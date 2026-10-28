/* cally 逆向卡：anon_268fb4（原版 libyoyo.so，armv7）
 * @func 0x268fb4 0x26e564   size 21940   5485 条
 *       其中 4976 条真实指令 + 3 张内联跳转表 498 项 + 2 处字面量池 11 字（见「字节账」）
 * 级别: 骨架（锚点全覆盖 = 5485；结构 / 入口契约 / 出口族 / 派发口 / 三张表 已钉；
 *       各 case 体只给"这里在干什么"级别的话，逐条语义未钉；open 8 条）
 * 符号: functions.tsv 记作 anon_268fb4（stripped 目标，.dynsym 无独立符号名）。
 *       llvm-objdump 把整段标成 <pcre_compile+0x2c>：0x268f88 那 44 B（11 条）才是 pcre_compile
 *       符号本体，本区间紧接其后；被调件是 PCRE 8.x 的 _pcre_is_newline / _pcre_was_newline /
 *       _pcre_xclass（下划线前缀 = pcre1 世代命名，不是 pcre2_*）⇒ 本区间属于 PCRE 编译侧核心。
 *
 * ══ 结论一：这是**一个**函数，不是多函数粘连 ══════════════════════════════════
 *   1. 全 21940 B 里 push 带 lr 只有 1 条（0x268fb4 首条：push {r4..r11, lr}）。
 *      没有任何第二条序言 ⇒ 不存在"漏检的内嵌函数入口"。
 *   2. pop 只有 2 条（0x2691e8 / 0x2695ac），都是 pop {r4..r11, pc}，且各自前面紧跟同一对拆帧
 *      （0x2691e0/0x2691e4 与 0x2695a4/0x2695a8 的 add sp,#8192 + add sp,#28）
 *      ⇒ 整段只有 2 个返回点，共用两个尾块。
 *   3. 从 0x268fb4 做 CFG 可达性（条件跳双出、b 单出、bl 递归继续、addls pc 按表长展开）：
 *      4976 条真实指令**全部可达**，剩余 509 条 = 3 张表的 498 个 b 表项 + 11 个字面量池字。
 *      ⇒ 一个入口、一套栈帧、两个出口、无孤岛代码块：**单函数**。
 *      因此**不建议按函数切分**；本卡只在「段落」层面给自然断点（见上「分段表」），供后续分主题攻坚。
 *
 * ══ 结论二：控制流全是直连，没有间接尾跳 ═════════════════════════════════════
 *   bx = 0；mov pc = 0；ldr pc = 0；tbb/tbh = 0。
 *   （0x26c40c 的 ldrsbeq pc, [r1], -r4 是字面量池数据字，不是指令；见字节账。）
 *   3 条 addls pc, pc, rN, lsl #2，每条都严格对应紧邻的 cmp rN,#imm ⇒ 表长 = imm+1：
 *       0x269574  cmp r2,#8    9 项   r2 = 码点-14      表 0x26957c..0x26959c
 *       0x2695bc  cmp r2,#476  477 项  r2 = r9-1        表 0x2695c4..0x269d34
 *       0x26bb30  cmp r3,#11   12 项   r3 = r3-98       表 0x26bb38..0x26bb64
 *   表项就是紧跟在 addls 后面的 b 指令（in-line），是本区间 745 条 b 的主要来源。
 *   bl = 19，blx r3 = 2；b = 745；beq = 227；bne = 140；bge = 102。
 *
 * ══ 字节账（5485 = 4976 + 498 + 11）══════════════════════════════════════════
 *   4976  真实指令
 *    498  3 张跳转表的 b 表项（9 + 477 + 12）
 *     11  字面量池：0x26a264..0x26a27c（7 字，紧跟 0x26a260 的 b）
 *                  0x26c404..0x26c410（4 字，紧跟 0x26c400 的 b）
 *   objdump 把池数据译成了 andseq ×9 / ldrsbeq ×1 / mulseq ×1 —— 这三个助记符在全区间只出现这 11 次，
 *   且地址与上面两段完全重合，可反向自校验（README 规矩 3：卡里保留 objdump 写法，注释里标非指令）。
 *
 * ══ 栈帧 ═══════════════════════════════════════════════════════════════════
 *   0x268fb4 push {r4,r5,r6,r7,r8,r9,r10,r11,lr}   9 寄存器 = 36 B
 *   0x268fb8 sub sp, sp, #8192
 *   0x268fbc sub sp, sp, #28                      ⇒ 局部 8220 B；帧合计 8256 B（÷16 = 516，对齐）
 *   帧顶用 add rN, sp, #8192 反复重算（24 处），帧内偏移有两种写法：
 *       [sp, #0..0xd4]（49 个不同偏移，最大 0xd4）与 [sp+8192, #-0xf6c..]（负偏移，等价 sp+0x1094 一类）
 *   例：0x26c424 add r9, sp, #204 / 0x26c434 add r9, sp, #4160 + add #56 ⇒ 一个 0x1078 起的上下文块。
 *   帧外只读不写：entry_sp+8 / +12 / +16（见入口契约）。
 *
 * ══ 入口契约（S1，0x268fb4..0x26902b）════════════════════════════════════════
 *   r0  → [sp,#0x28]，全程当**结构体指针**用：读 [+0] [+4] [+8] [+0x10] [+0x1c]，
 *         并把 [+0x1c] 的 bit11（0x26900c ubfx r6,r6,#0xb,#1）存 [sp,#0x48]
 *   r1  → r8（输入串指针），0x269004 ldrb r1,[r1] 取首字节
 *   r2  → [sp,#0x5c]；r3 → [sp,#0x8c]
 *   帧外三个字（= 本函数的第 7/8/9 个实参）：
 *         [r5=sp+8192, #0x4c] = entry_sp+12 → sub #2 后按 0x2AAAAAAB 乘倒数除 3（0x268fec/0x269010）
 *                                            ⇒ 按 **12 B/项** 换算条目数，结果进 r11（0x26907c）
 *         [r9=sp+8192, #0x48] = entry_sp+8  → +8 后存 [sp,#0x58]（12 B 记录表基址 = 基址+8）
 *         [r9=sp+8192, #0x50] = entry_sp+16 → +1 后存 [sp,#0x6c]
 *   ⇒ 本函数至少吃 9 个实参；第 5/6 个（entry_sp+0/+4）在 S1 未见直接读取。
 *
 * ══ 出口族（只有 2 个返回点，返回值是一个负状态码）════════════════════════════
 *   E1 0x2691dc mvn r0,#18（= -19）→ 0x2691e0/0x2691e4 拆帧 → 0x2691e8 pop
 *      入边 110 条：bge 100 / ble 9 / b 1；其中 98 条紧跟 cmp（cmp r8,rN / cmp r11,rN）
 *      ⇒ 这个出口是**扫描越界 / 计数耗尽**的统一句柄（"走到头了"）。
 *   E2 0x2695a0 mvn r0,#15（= -16）→ 0x2695a4/0x2695a8 拆帧 → 0x2695ac pop
 *      入边 315 条，**全部是无条件 b**，绝大多数就是 477 项表里的兜底表项
 *      ⇒ 这个出口是**未覆盖 / 默认分支**的兜底。
 *   另有 13 条 b/条件跳**跳过 mvn r0,#18 直奔 0x2691e0**（拆帧但保留自己的 r0）：
 *      0x26b6bc mvn r0,#25 (-26)      0x26e2d8 mvn r0,#19 (-20)
 *      0x26e314 mvn r0,#16 (-17)      0x26e134 mvnne r0,#11 / 0x26e15c mvnhi r0,#11 (-12，条件写)
 *      0x26d404 ldr r0,[sp,#0x70]      ← 唯一一处"从槽里取返回值"
 *      其余 7 条沿用子调用的 r0：0x26be2c/0x26c8d4 cmn r0,#16（= -16 透传）、
 *                              0x26c7a0/0x26d38c cmn r0,#1（= -1 透传）、
 *                              0x26b600/0x26d234 cmp r0,#0 + blt、0x26bfdc bne
 *   ⇒ 可观察返回值集合 = {-1, -12, -16, -17, -19, -20, -26} ∪ {[sp+0x70]}；
 *     -16 既是本函数的兜底码，也被当成**子调用的返回码**用 cmn 精确识别后原样上抛。
 *     （成功值到底是不是 [sp+0x70] / 0 未钉 —— open 2。）
 *
 * ══ 派发骨架 ═══════════════════════════════════════════════════════════════
 *   主循环头 0x269480（cmp r8,r5；228 条入边 = 132 b + 96 条件跳），回边 0x269484 bgt → 0x269424；
 *   循环体是一次 12 B 记录表线性查找：r10 = 表基（[sp,#0x58]），r5 = 游标，
 *   0x269428 ldr r7,[r10, r6, lsl #2]（r6 = 3*r5 ⇒ 12 B/项）取项首字做键，
 *   再与 r7 比 (0x269460) 并比第二字 (0x269470)，命中存 r11 = r5 后继续。
 *   取字符：0x2694d8/0x2694dc/0x2694e0 → r9 = [sp,#0x3c][r7]（当前字节），r4 = 该项指针；
 *   然后两张 GOT 基址表（0x2694e8/0x2694f0/0x2694f8 与 0x269508/0x26950c/0x269510）把字节映射成
 *   标志位 [sp,#0x44] 与偏移 r3（ctypes / escapes 形态），再 0x269528 ldrb r0,[r4,r3] 取续字节。
 *   UTF-8 四档都在本区间（手写、非库调用）：
 *       单字节 0x26952c cmp r0,#191（≤0xBF）→ r3=1
 *       2 字节 0x269544..0x26955c  cp = ((b&0x1F)<<6) | (b1&0x3F)  → [sp,#0x2c]
 *       3 字节 0x269f00..0x269f28  cp = ((b&0x0F)<<12) | ...       → [sp,#0x2c]
 *       4 字节 0x269e14 tst #16 / tst #8 → 0x26c314
 *   派发：0x269560 cmp r9,#84 ; ble 0x2695b4（ASCII ≤ 'T' 直接查 477 项表）；
 *         > 'T' 时先按码点 14..22 走 9 项表（S8），命中则把 r9 += 300/320/340/360/380
 *         变成**伪 token** 再回 477 项表（0x269ee0/0x269ee8/0x269ef0/0x269ef8/0x2695b0）。
 *   ⇒ 477 项表 = 按「当前字节 1..255 + 伪 token」的 switch；315 个表项直接落 E2(-16)。
 *
 * ══ 间接调用（2 处，同一个协议）════════════════════════════════════════════════
 *   0x26b5f4 / 0x26d228 blx r3，r3 来自 0x26b538..0x26b544 的 GOT→全局→首字 三级取值，
 *   取到 0 就跳过（0x26b548 beq）：这是一个**运行期可空的全局函数指针钩子**。
 *   调用前把 5 个字填进 sp+0x1078 起的上下文块（字段 +0x1C/+0x20/+0x24/+0x2C/+0x30，
 *   写法 [r9=sp+8192, #-0xf6c/-0xf68/-0xf64/-0xf5c/-0xf58]），r0 = &块（add r0,sp,#4160; add #56）。
 *   返回后：r0 < 0 → 直奔 E1 拆帧上抛（0x26b600 blt）；r0 != 0 → r5++ 回主循环（0x26b604 bne）；
 *   r0 == 0 → 不推进直接继续（0x26b60c）。
 *
 * ══ 调用面 ═══════════════════════════════════════════════════════════════════
 *   bl 19 条 + blx r3 2 条：
 *     memcpy@plt 0xb65bc   ×1  0x269ed8
 *     memmove@plt 0xb6694  ×1  0x26db80
 *     _pcre_is_newline     ×10 0x26cac4 0x26d5bc 0x26d698 0x26d77c 0x26dab8
 *                              0x26ddd4 0x26e194 0x26e2c0 0x26e4a0 0x26e4e0
 *     _pcre_was_newline    ×1  0x26d8f0
 *     _pcre_xclass         ×1  0x26d284（\p{...} 扩展类编译）
 *     自递归 bl 0x268fb4   ×5  0x26bcd4 0x26be20 0x26bfb0 0x26c480 0x26c8c8
 *   ⇒ 5 处自递归 + 1 处区间外调用 = 上下文说的「6 处 bl」（外部那 1 处推定是 0x268f88 的
 *     44 B 薄包装里的 bl，本工作区无 .so，无法直接看那 11 条 —— open 1）。
 *
 * ══ 分段表（段落，不是函数；按派发口 / 回边 / 表自然断开）══════════════════════
 *   S1  0x268fb4   30 条   入口：帧 8256 B + 实参展开（r0 结构体、r1 串、3 个帧外实参）
 *   S2  0x26902c   30 条   首字节前缀探测（0x85/0x8A→+3、0x86/0x8B→+5，再要求该位 == '|'）
 *   S3  0x2690a4  199 条   前缀/字节扫描内环（回边 0x2690a4、0x26919c；E1 的 bge 群在这段）
 *   S4  0x2693c0   25 条   3 字节 UTF-8 解码 + 12 B 表索引换算（0x2AAAAAAB 除 3）
 *   S5  0x269424   25 条   12 B 记录表线性查找内环（键 = 项[0]、项[1] 两字）
 *   S6  0x269488   19 条   查找收敛：命中 → r11，未命中 → 0x26d3a4
 *   S7  0x2694d4   35 条   取字节 + ctypes/escapes 两表 + UTF-8 1/2/3/4 档
 *   S8  0x269560   21 条   9 项小派发（码点 14..22 → 伪 token +300/+320/+340/+360/+380）
 *   S9  0x2695b4  481 条   477 项总派发表（4 条派发代码 + 477 条表项数据）
 *   S10 0x269d38 1918 条   case 体群 A
 *   S11 0x26bb30   13 条   12 项小派发表（1 条派发 + 12 条表项数据，值 98..109）
 *   S12 0x26bb64 2689 条   case 体群 B（含 5 处自递归、_pcre_xclass、memmove、两处字面量池）
 *
 * ══ open ════════════════════════════════════════════════════════════════════
 *   1. 区间外调用点未枚举：本工作区没有 libyoyo.so，asm/ 里也没有 instructions.jsonl(.xz)，
 *      只有本函数的 index TSV。上下文给的「6 处」按 5 自递归 + 1 外部推定成立，
 *      外部那 1 处（推测在 0x268f88 的 44 B 包装体内）未直接看到。
 *   2. 返回值语义未钉：只知集合与触发条件（见出口族），不知调用方如何解释 -19/-16/-12/-17/-20/-26，
 *      也不知成功值到底是 [sp+0x70] 还是 0；「返回值是 int 状态码」是从"两处出口都写死负常数 +
 *      7 处把子调用负码原样上抛"推出来的，不是从调用点读出来的。
 *   3. 0x268fb4 读 3 个帧外实参（第 7/8/9 个）⇒ 真实签名 ≥ 9 参；第 5/6 个实参在 S1 未被直接读取，
 *      是没用还是被别的路径取了，未钉。
 *   4. 全局函数指针钩子（0x26b538 三级取值 + 5 字上下文块）指向谁、协议是什么，未钉。
 *   5. S2 的前缀探测（0x85/0x86/0x8A/0x8B + 后续字节 '|'）对应哪种语法构件，未钉。
 *   6. 477 项表的索引语义只钉到「r9 = 当前字节 或 字节+300..380 的伪 token」；
 *      伪 token 300/320/340/360/380 这 5 个档位各自的含义未钉。
 *   7. 各 case 体（S10/S12 共 4607 条）只做了结构性标注，没有逐条语义；本卡级别因此封顶在骨架。
 *   8. 12 B 记录表（r10/[sp,#0x58]，键 = 项[0..1]）装的是什么（子模式名/编号表？）未钉。
 *
 * 校验：scripts/check_card_anchors.py --card cards/anon_268fb4.c --index asm/index-anon_268fb4.tsv
 *       → RESULT EXACT（5485/5485，无 missing / extra / mismatch）
 */


/* ──── S1 入口：帧 8256 B + 实参展开（30 条） ──── */
/* @0x268fb4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 唯一序言；全区间仅此一条 push 带 lr */
/* @0x268fb8 sub sp, sp, #8192 —— 局部 8192 B */
/* @0x268fbc sub sp, sp, #28 —— 再 28 B ⇒ 帧合计 8256 B（16 对齐） */
/* @0x268fc0 movw r12, #0xaaab */
/* @0x268fc4 add r5, sp, #8192 */
/* @0x268fc8 movt r12, #0x2aaa */
/* @0x268fcc add r9, sp, #8192 */
/* @0x268fd0 str r3, [sp, #0x8c] */
/* @0x268fd4 ldr r4, [r5, #0x4c] —— 帧外实参 #8（entry_sp+12）：后面按 /3 换 12 B 项数 */
/* @0x268fd8 mov r8, r1 */
/* @0x268fdc str r0, [sp, #0x28] */
/* @0x268fe0 sub r4, r4, #2 */
/* @0x268fe4 ldr r9, [r9, #0x48] —— 帧外实参 #7（entry_sp+8）：+8 后当 12 B 记录表基址 */
/* @0x268fe8 ldr r7, [sp, #0x28] */
/* @0x268fec smull r6, r5, r12, r4 */
/* @0x268ff0 str r2, [sp, #0x5c] */
/* @0x268ff4 add r9, r9, #8 */
/* @0x268ff8 str r9, [sp, #0x58] */
/* @0x268ffc add r9, sp, #8192 */
/* @0x269000 ldr r6, [r7, #0x1c] */
/* @0x269004 ldrb r1, [r1] */
/* @0x269008 ldr r7, [r9, #0x50] —— 帧外实参 #9（entry_sp+16）：+1 后存槽 */
/* @0x26900c ubfx r6, r6, #0xb, #0x1 —— 取 r0->[+0x1c] 的 bit11 存 [sp,#0x48] */
/* @0x269010 sub r4, r5, r4, asr #31 */
/* @0x269014 str r6, [sp, #0x48] */
/* @0x269018 add r7, r7, #1 */
/* @0x26901c ldr r5, [sp, #0x28] */
/* @0x269020 add r4, r4, r4, lsl #1 */
/* @0x269024 ldr r6, [sp, #0x28] */
/* @0x269028 str r7, [sp, #0x6c] */
/* ──── S2 首字节前缀探测（30 条） ──── */
/* @0x26902c cmp r1, #133 —— 首字节 r1 与其后两字节：0x85/0x8A 与 0x86/0x8B 四选一 */
/* @0x269030 cmpne r1, #138 */
/* @0x269034 lsl r3, r4, #1 */
/* @0x269038 ldr r7, [sp, #0x28] */
/* @0x26903c ldr r9, [sp, #0x28] */
/* @0x269040 movne r0, #0 */
/* @0x269044 moveq r0, #1 */
/* @0x269048 smull r2, r12, r12, r3 */
/* @0x26904c ldr r5, [r5, #0x4] */
/* @0x269050 ldr r6, [r6, #0x8] */
/* @0x269054 ldr r7, [r7] */
/* @0x269058 ldr r9, [r9, #0x10] */
/* @0x26905c ldr r4, [sp, #0x58] */
/* @0x269060 sub r12, r12, r3, asr #31 */
/* @0x269064 str r5, [sp, #0x54] */
/* @0x269068 str r6, [sp, #0x68] */
/* @0x26906c add r3, r12, r12, lsl #1 */
/* @0x269070 str r7, [sp, #0x3c] */
/* @0x269074 str r9, [sp, #0x74] */
/* @0x269078 str r12, [sp, #0x30] */
/* @0x26907c add r11, r4, r3, lsl #2 */
/* @0x269080 beq 0x26915c <pcre_compile+0x1d4> */
/* @0x269084 cmp r1, #134 */
/* @0x269088 beq 0x26915c <pcre_compile+0x1d4> */
/* @0x26908c cmp r1, #139 */
/* @0x269090 movne r3, #3 */
/* @0x269094 moveq r3, #5 */
/* @0x269098 ldrb r3, [r8, r3] */
/* @0x26909c cmp r3, #124 —— 要求前缀后那一位是 '|'(0x7c) */
/* @0x2690a0 bne 0x26916c <pcre_compile+0x1e4> */
/* ──── S3 前缀/字节扫描内环，回边 0x2690a4 与 0x26919c（199 条） ──── */
/* @0x2690a4 mov r2, r8 */
/* @0x2690a8 mov r3, #0 */
/* @0x2690ac ldrb r0, [r2, #0x1] */
/* @0x2690b0 ldrb r1, [r2, #0x2] */
/* @0x2690b4 ldrb r12, [r2, #0x4] */
/* @0x2690b8 orr r1, r1, r0, lsl #8 */
/* @0x2690bc ldrb r0, [r2, #0x5] */
/* @0x2690c0 ldrb r1, [r2, r1]! */
/* @0x2690c4 orr r0, r0, r12, lsl #8 */
/* @0x2690c8 cmp r3, r0 */
/* @0x2690cc movlt r3, r0 */
/* @0x2690d0 cmp r1, #119 */
/* @0x2690d4 beq 0x2690ac <pcre_compile+0x124> */
/* @0x2690d8 ldr r5, [sp, #0x48] */
/* @0x2690dc mov r12, r3 */
/* @0x2690e0 cmp r5, #0 */
/* @0x2690e4 beq 0x269204 <pcre_compile+0x27c> */
/* @0x2690e8 cmp r3, #0 */
/* @0x2690ec beq 0x269224 <pcre_compile+0x29c> */
/* @0x2690f0 ldr r6, [sp, #0x54] */
/* @0x2690f4 mov r3, #0 */
/* @0x2690f8 ldr r7, [sp, #0x5c] */
/* @0x2690fc cmp r6, r7 */
/* @0x269100 bhs 0x269224 <pcre_compile+0x29c> */
/* @0x269104 mov r4, r6 */
/* @0x269108 mov r2, r7 */
/* @0x26910c sub r1, r2, #1 */
/* @0x269110 cmp r4, r1 */
/* @0x269114 bhs 0x269150 <pcre_compile+0x1c8> */
/* @0x269118 ldrb r0, [r2, #-0x1] */
/* @0x26911c and r0, r0, #192 */
/* @0x269120 cmp r0, #128 */
/* @0x269124 bne 0x26e4b8 <pcre_compile+0x5530> */
/* @0x269128 sub r2, r2, #2 */
/* @0x26912c b 0x269140 <pcre_compile+0x1b8> */
/* @0x269130 ldrb r0, [r1] */
/* @0x269134 and r0, r0, #192 */
/* @0x269138 cmp r0, #128 */
/* @0x26913c bne 0x26e4b8 <pcre_compile+0x5530> */
/* @0x269140 cmp r2, r4 */
/* @0x269144 mov r1, r2 */
/* @0x269148 sub r2, r2, #1 */
/* @0x26914c bne 0x269130 <pcre_compile+0x1a8> */
/* @0x269150 add r3, r3, #1 */
/* @0x269154 str r1, [sp, #0x5c] */
/* @0x269158 b 0x269224 <pcre_compile+0x29c> */
/* @0x26915c mov r3, #5 */
/* @0x269160 ldrb r3, [r8, r3] */
/* @0x269164 cmp r3, #124 */
/* @0x269168 beq 0x2690a4 <pcre_compile+0x11c> */
/* @0x26916c ldr r6, [sp, #0x6c] */
/* @0x269170 cmp r6, #1 */
/* @0x269174 beq 0x269e88 <pcre_compile+0xf00> */
/* @0x269178 cmp r0, #0 */
/* @0x26917c beq 0x2691ec <pcre_compile+0x264> */
/* @0x269180 mov r2, #5 */
/* @0x269184 mov r10, #0 */
/* @0x269188 add r3, r11, #12 */
/* @0x26918c mov r12, r10 */
/* @0x269190 ldr r0, [sp, #0x3c] */
/* @0x269194 ldr r4, [sp, #0x30] */
/* @0x269198 b 0x2691c0 <pcre_compile+0x238> */
/* @0x26919c str r1, [r3, #-0xc] */
/* @0x2691a0 add r3, r3, #12 */
/* @0x2691a4 str r12, [r3, #-0x14] */
/* @0x2691a8 ldrb r5, [r8, #0x1] */
/* @0x2691ac ldrb r1, [r8, #0x2] */
/* @0x2691b0 orr r1, r1, r5, lsl #8 */
/* @0x2691b4 ldrb r1, [r8, r1]! */
/* @0x2691b8 cmp r1, #119 */
/* @0x2691bc bne 0x2692a8 <pcre_compile+0x320> */
/* @0x2691c0 rsb r1, r0, r8 */
/* @0x2691c4 add r10, r10, #1 */
/* @0x2691c8 add r1, r1, r2 */
/* @0x2691cc sub r2, r10, #1 */
/* @0x2691d0 cmp r4, r2 */
/* @0x2691d4 mov r2, #3 */
/* @0x2691d8 bgt 0x26919c <pcre_compile+0x214> */
/* @0x2691dc mvn r0, #18 —— 出口 E1：r0 = -19（110 条入边，bge 100/ble 9/b 1） */
/* @0x2691e0 add sp, sp, #8192 —— E1 拆帧（不碰 r0）——13 条跳过 mvn 的路径也落这里 */
/* @0x2691e4 add sp, sp, #28 */
/* @0x2691e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 返回点 1/2 */
/* @0x2691ec cmp r1, #134 */
/* @0x2691f0 beq 0x269180 <pcre_compile+0x1f8> */
/* @0x2691f4 cmp r1, #139 */
/* @0x2691f8 movne r2, #3 */
/* @0x2691fc moveq r2, #5 */
/* @0x269200 b 0x269184 <pcre_compile+0x1fc> */
/* @0x269204 ldr r9, [sp, #0x5c] */
/* @0x269208 ldr r12, [sp, #0x54] */
/* @0x26920c rsb r2, r3, r9 */
/* @0x269210 cmp r12, r2 */
/* @0x269214 strls r2, [sp, #0x5c] */
/* @0x269218 rsbhi r3, r12, r9 */
/* @0x26921c rsbhi r9, r3, r9 */
/* @0x269220 strhi r9, [sp, #0x5c] */
/* @0x269224 ldr r4, [sp, #0x28] */
/* @0x269228 mov r10, #0 */
/* @0x26922c ldr r5, [sp, #0x5c] */
/* @0x269230 ldr r6, [sp, #0x30] */
/* @0x269234 ldr r2, [r4, #0xc] */
/* @0x269238 cmp r5, r2 */
/* @0x26923c strlo r5, [r4, #0xc] */
/* @0x269240 ldr r4, [sp, #0x3c] */
/* @0x269244 mov r2, r11 */
/* @0x269248 mov r5, r10 */
/* @0x26924c ldrb r0, [r8, #0x4] */
/* @0x269250 rsb r12, r4, r8 */
/* @0x269254 ldrb r1, [r8, #0x5] */
/* @0x269258 add r12, r12, #6 */
/* @0x26925c rsb r12, r12, #0 */
/* @0x269260 add r7, r10, #1 */
/* @0x269264 orr r1, r1, r0, lsl #8 */
/* @0x269268 cmp r3, r1 */
/* @0x26926c rsb r1, r1, r3 */
/* @0x269270 blt 0x269290 <pcre_compile+0x308> */
/* @0x269274 cmp r10, r6 */
/* @0x269278 mov r10, r7 */
/* @0x26927c bge 0x2691dc <pcre_compile+0x254> */
/* @0x269280 str r12, [r2] */
/* @0x269284 add r2, r2, #12 */
/* @0x269288 str r5, [r2, #-0x8] */
/* @0x26928c str r1, [r2, #-0x4] */
/* @0x269290 ldrb r0, [r8, #0x1] */
/* @0x269294 ldrb r1, [r8, #0x2] */
/* @0x269298 orr r1, r1, r0, lsl #8 */
/* @0x26929c ldrb r1, [r8, r1]! */
/* @0x2692a0 cmp r1, #119 */
/* @0x2692a4 beq 0x26924c <pcre_compile+0x2c4> */
/* @0x2692a8 lsl r4, r10, #1 */
/* @0x2692ac add r5, sp, #8192 */
/* @0x2692b0 ldr r6, [pc, #0xfac] */
/* @0x2692b4 ldr r7, [pc, #0xfac] */
/* @0x2692b8 mov r3, #0 */
/* @0x2692bc ldr r5, [r5, #0x44] */
/* @0x2692c0 add r6, pc, r6 */
/* @0x2692c4 str r6, [sp, #0x50] */
/* @0x2692c8 add r7, pc, r7 */
/* @0x2692cc bic r5, r5, #1 */
/* @0x2692d0 str r5, [sp, #0x84] */
/* @0x2692d4 cmp r5, #1 */
/* @0x2692d8 ldr r5, [pc, #0xf8c] */
/* @0x2692dc ldr r6, [sp, #0x74] */
/* @0x2692e0 add r5, pc, r5 */
/* @0x2692e4 str r5, [sp, #0xa4] */
/* @0x2692e8 ldr r5, [sp, #0x5c] */
/* @0x2692ec movle r9, #0 */
/* @0x2692f0 movgt r9, #1 */
/* @0x2692f4 str r7, [sp, #0x9c] */
/* @0x2692f8 str r9, [sp, #0x98] */
/* @0x2692fc add r6, r6, #832 */
/* @0x269300 ldr r12, [pc, #0xf68] */
/* @0x269304 ldr r7, [pc, #0xf68] */
/* @0x269308 ldr r9, [sp, #0x74] */
/* @0x26930c add r12, pc, r12 */
/* @0x269310 str r6, [sp, #0x78] */
/* @0x269314 mvn r6, #0 */
/* @0x269318 str r6, [sp, #0x70] */
/* @0x26931c mov r6, r10 */
/* @0x269320 mov r10, r11 */
/* @0x269324 str r12, [sp, #0xa0] */
/* @0x269328 add r7, pc, r7 */
/* @0x26932c add r9, r9, #256 */
/* @0x269330 add r12, sp, #204 */
/* @0x269334 str r7, [sp, #0xa8] */
/* @0x269338 str r9, [sp, #0x88] */
/* @0x26933c str r12, [sp, #0x94] */
/* @0x269340 str r3, [sp, #0x44] */
/* @0x269344 str r5, [sp, #0x38] */
/* @0x269348 str r8, [sp, #0xac] */
/* @0x26934c add r12, sp, #8192 */
/* @0x269350 ldr r7, [sp, #0x38] */
/* @0x269354 ldr r9, [sp, #0x68] */
/* @0x269358 add r2, r4, r6 */
/* @0x26935c ldr r12, [r12, #0x48] */
/* @0x269360 eor r3, r3, #1 */
/* @0x269364 cmp r7, r9 */
/* @0x269368 add r2, r10, r2, lsl #2 */
/* @0x26936c str r2, [sp, #0x24] */
/* @0x269370 str r6, [r12, #0x4] */
/* @0x269374 str r3, [r12] */
/* @0x269378 bhs 0x269e00 <pcre_compile+0xe78> */
/* @0x26937c ldrb r4, [r7] */
/* @0x269380 ldr r3, [sp, #0x48] */
/* @0x269384 cmp r4, #191 */
/* @0x269388 movls r3, #0 */
/* @0x26938c andhi r3, r3, #1 */
/* @0x269390 str r4, [sp, #0x34] */
/* @0x269394 cmp r3, #0 */
/* @0x269398 moveq r5, #1 */
/* @0x26939c streq r5, [sp, #0x40] */
/* @0x2693a0 beq 0x2693e8 <pcre_compile+0x460> */
/* @0x2693a4 tst r4, #32 */
/* @0x2693a8 beq 0x269f30 <pcre_compile+0xfa8> */
/* @0x2693ac ldr r7, [sp, #0x34] */
/* @0x2693b0 tst r7, #16 */
/* @0x2693b4 bne 0x26c69c <pcre_compile+0x3714> */
/* @0x2693b8 ldr r9, [sp, #0x38] */
/* @0x2693bc lsl r1, r7, #12 */
/* ──── S4 3 字节 UTF-8 解码 + 12 B 表索引换算（25 条） ──── */
/* @0x2693c0 mov r12, #3 */
/* @0x2693c4 str r12, [sp, #0x40] */
/* @0x2693c8 uxth r1, r1 */
/* @0x2693cc ldrb r3, [r9, #0x2] */
/* @0x2693d0 ldrb r2, [r9, #0x1] */
/* @0x2693d4 and r3, r3, #63 */
/* @0x2693d8 and r2, r2, #63 */
/* @0x2693dc orr r3, r1, r3 */
/* @0x2693e0 orr r2, r3, r2, lsl #6 */
/* @0x2693e4 str r2, [sp, #0x34] */
/* @0x2693e8 cmp r6, #0 */
/* @0x2693ec ble 0x26d398 <pcre_compile+0x4410> */
/* @0x2693f0 mov r9, #0 */
/* @0x2693f4 ldr r7, [sp, #0x34] */
/* @0x2693f8 mov r5, r9 */
/* @0x2693fc str r9, [sp, #0x4c] */
/* @0x269400 str r9, [sp, #0x80] */
/* @0x269404 mov r8, r6 */
/* @0x269408 str r9, [sp, #0x64] */
/* @0x26940c lsr r3, r7, #3 */
/* @0x269410 ldr r9, [sp, #0x58] */
/* @0x269414 mov r11, r5 */
/* @0x269418 add r3, r3, #1 */
/* @0x26941c str r3, [sp, #0x90] */
/* @0x269420 mov r12, r9 */
/* ──── S5 12 B 记录表线性查找内环，回边 0x269424（25 条） ──── */
/* @0x269424 add r6, r5, r5, lsl #1 */
/* @0x269428 ldr r7, [r10, r6, lsl #2] */
/* @0x26942c add r6, r10, r6, lsl #2 */
/* @0x269430 cmp r7, #0 */
/* @0x269434 blt 0x269d8c <pcre_compile+0xe04> */
/* @0x269438 cmp r5, #0 */
/* @0x26943c ble 0x2694d0 <pcre_compile+0x548> */
/* @0x269440 mov r3, #0 */
/* @0x269444 mov r2, r3 */
/* @0x269448 b 0x269458 <pcre_compile+0x4d0> */
/* @0x26944c cmp r2, r5 */
/* @0x269450 add r3, r3, #12 */
/* @0x269454 beq 0x2694d0 <pcre_compile+0x548> */
/* @0x269458 ldr r1, [r10, r3] */
/* @0x26945c add r2, r2, #1 */
/* @0x269460 cmp r1, r7 */
/* @0x269464 bne 0x26944c <pcre_compile+0x4c4> */
/* @0x269468 add r0, r10, r3 */
/* @0x26946c ldr r1, [r6, #0x4] */
/* @0x269470 ldr r0, [r0, #0x4] */
/* @0x269474 cmp r0, r1 */
/* @0x269478 bne 0x26944c <pcre_compile+0x4c4> */
/* @0x26947c add r5, r5, #1 */
/* @0x269480 cmp r8, r5 —— 主循环头：228 条入边（132 b + 96 条件跳） */
/* @0x269484 bgt 0x269424 <pcre_compile+0x49c> —— 回边 → 0x269424 */
/* ──── S6 查找收敛：命中 → r11，未命中 → 0x26d3a4（19 条） ──── */
/* @0x269488 cmp r11, #0 */
/* @0x26948c mov r12, r11 */
/* @0x269490 beq 0x26d3a4 <pcre_compile+0x441c> */
/* @0x269494 add r9, sp, #8192 */
/* @0x269498 ldr r3, [sp, #0x58] */
/* @0x26949c ldr r7, [sp, #0x64] */
/* @0x2694a0 mov r6, r12 */
/* @0x2694a4 ldr r9, [r9, #0x48] */
/* @0x2694a8 ldr r4, [sp, #0x38] */
/* @0x2694ac ldr r5, [sp, #0x40] */
/* @0x2694b0 str r10, [sp, #0x58] */
/* @0x2694b4 mov r10, r3 */
/* @0x2694b8 add r4, r4, r5 */
/* @0x2694bc str r7, [sp, #0x44] */
/* @0x2694c0 str r4, [sp, #0x38] */
/* @0x2694c4 lsl r4, r12, #1 */
/* @0x2694c8 ldr r3, [r9] */
/* @0x2694cc b 0x26934c <pcre_compile+0x3c4> */
/* @0x2694d0 ldr r9, [sp, #0x40] */
/* ──── S7 取字节 + ctypes/escapes 两表 + UTF-8 1/2/3/4 档（35 条） ──── */
/* @0x2694d4 cmp r9, #0 */
/* @0x2694d8 ldr r9, [sp, #0x3c] */
/* @0x2694dc add r4, r9, r7 */
/* @0x2694e0 ldrb r9, [r9, r7] */
/* @0x2694e4 bne 0x269508 <pcre_compile+0x580> */
/* @0x2694e8 ldr r3, [pc, #0xd88] —— GOT 基址 + 当前字节 → ctypes 表 */
/* @0x2694ec ldr r0, [sp, #0x44] */
/* @0x2694f0 add r3, pc, r3 */
/* @0x2694f4 add r3, r3, r9 */
/* @0x2694f8 ldrb r3, [r3, #-0xd8c] */
/* @0x2694fc cmp r3, #0 */
/* @0x269500 movne r0, #1 */
/* @0x269504 str r0, [sp, #0x44] */
/* @0x269508 ldr r1, [sp, #0x50] */
/* @0x26950c add r3, r1, r9 */
/* @0x269510 ldrb r3, [r3, #-0xce8] —— 第二张表（escapes 形态）给出续字节偏移 */
/* @0x269514 cmp r3, #0 */
/* @0x269518 beq 0x269dd8 <pcre_compile+0xe50> */
/* @0x26951c ldr r2, [sp, #0x48] */
/* @0x269520 cmp r2, #0 */
/* @0x269524 beq 0x269de4 <pcre_compile+0xe5c> */
/* @0x269528 ldrb r0, [r4, r3] —— ≤0xBF 单字节档；否则进 2/3/4 字节解码 */
/* @0x26952c cmp r0, #191 */
/* @0x269530 str r0, [sp, #0x2c] */
/* @0x269534 movls r3, #1 */
/* @0x269538 bls 0x269560 <pcre_compile+0x5d8> */
/* @0x26953c tst r0, #32 */
/* @0x269540 bne 0x269e14 <pcre_compile+0xe8c> */
/* @0x269544 add r2, r4, r3 —— 2 字节 UTF-8：cp = ((b&0x1F)<<6)|(b1&0x3F) */
/* @0x269548 and r1, r0, #31 */
/* @0x26954c mov r3, #2 */
/* @0x269550 ldrb r0, [r2, #0x1] */
/* @0x269554 and r0, r0, #63 */
/* @0x269558 orr r1, r0, r1, lsl #6 */
/* @0x26955c str r1, [sp, #0x2c] */
/* ──── S8 9 项小派发：码点 14..22 → 伪 token +300/+320/+340/+360/+380（21 条） ──── */
/* @0x269560 cmp r9, #84 —— ASCII ≤ 'T' 直接查 477 项表；否则先做码点 14..22 特判 */
/* @0x269564 ble 0x2695b4 <pcre_compile+0x62c> */
/* @0x269568 ldr r1, [sp, #0x2c] */
/* @0x26956c sub r2, r1, #14 */
/* @0x269570 cmp r2, #8 */
/* @0x269574 addls pc, pc, r2, lsl #2 —— 跳转表 1：9 项（索引 = 码点-14） */
/* @0x269578 b 0x2695b4 <pcre_compile+0x62c> —— 表项（数据）：默认落 E2 */
/* @0x26957c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269580 b 0x269ef8 <pcre_compile+0xf70> */
/* @0x269584 b 0x269ef8 <pcre_compile+0xf70> */
/* @0x269588 b 0x269ef0 <pcre_compile+0xf68> */
/* @0x26958c b 0x2695b0 <pcre_compile+0x628> */
/* @0x269590 b 0x2695b0 <pcre_compile+0x628> */
/* @0x269594 b 0x269ee8 <pcre_compile+0xf60> */
/* @0x269598 b 0x269ee8 <pcre_compile+0xf60> */
/* @0x26959c b 0x269ee0 <pcre_compile+0xf58> —— 表 1 末项 */
/* @0x2695a0 mvn r0, #15 —— 出口 E2：r0 = -16（315 条无条件 b 入边，多为 477 项表兜底） */
/* @0x2695a4 add sp, sp, #8192 */
/* @0x2695a8 add sp, sp, #28 */
/* @0x2695ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 返回点 2/2 */
/* @0x2695b0 add r9, r9, #360 */
/* ──── S9 477 项总派发表：4 条派发代码 + 477 条表项数据（481 条） ──── */
/* @0x2695b4 sub r2, r9, #1 —— 总派发：r2 = r9-1，范围 0..476 */
/* @0x2695b8 cmp r2, #476 */
/* @0x2695bc addls pc, pc, r2, lsl #2 —— 跳转表 2：477 项（表项 0x2695c4..0x269d34 全是 b，属数据） */
/* @0x2695c0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2695c4 b 0x26ac20 <pcre_compile+0x1c98> —— 表 2 首项（数据） */
/* @0x2695c8 b 0x26abcc <pcre_compile+0x1c44> */
/* @0x2695cc b 0x2695a0 <pcre_compile+0x618> */
/* @0x2695d0 b 0x26ab48 <pcre_compile+0x1bc0> */
/* @0x2695d4 b 0x26ab48 <pcre_compile+0x1bc0> */
/* @0x2695d8 b 0x26aafc <pcre_compile+0x1b74> */
/* @0x2695dc b 0x26aa74 <pcre_compile+0x1aec> */
/* @0x2695e0 b 0x26aafc <pcre_compile+0x1b74> */
/* @0x2695e4 b 0x26aa74 <pcre_compile+0x1aec> */
/* @0x2695e8 b 0x26aafc <pcre_compile+0x1b74> */
/* @0x2695ec b 0x26aa74 <pcre_compile+0x1aec> */
/* @0x2695f0 b 0x26a9ac <pcre_compile+0x1a24> */
/* @0x2695f4 b 0x26a96c <pcre_compile+0x19e4> */
/* @0x2695f8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2695fc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269600 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269604 b 0x26a914 <pcre_compile+0x198c> */
/* @0x269608 b 0x26a83c <pcre_compile+0x18b4> */
/* @0x26960c b 0x26a7bc <pcre_compile+0x1834> */
/* @0x269610 b 0x26a8b0 <pcre_compile+0x1928> */
/* @0x269614 b 0x26a758 <pcre_compile+0x17d0> */
/* @0x269618 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26961c b 0x26a704 <pcre_compile+0x177c> */
/* @0x269620 b 0x26a6ac <pcre_compile+0x1724> */
/* @0x269624 b 0x26a5d0 <pcre_compile+0x1648> */
/* @0x269628 b 0x26a4f8 <pcre_compile+0x1570> */
/* @0x26962c b 0x26aff8 <pcre_compile+0x2070> */
/* @0x269630 b 0x26af24 <pcre_compile+0x1f9c> */
/* @0x269634 b 0x26aec4 <pcre_compile+0x1f3c> */
/* @0x269638 b 0x26ae40 <pcre_compile+0x1eb8> */
/* @0x26963c b 0x26adf0 <pcre_compile+0x1e68> */
/* @0x269640 b 0x26ad70 <pcre_compile+0x1de8> */
/* @0x269644 b 0x26ad68 <pcre_compile+0x1de0> */
/* @0x269648 b 0x26ad68 <pcre_compile+0x1de0> */
/* @0x26964c b 0x26ac6c <pcre_compile+0x1ce4> */
/* @0x269650 b 0x26ac6c <pcre_compile+0x1ce4> */
/* @0x269654 b 0x26a170 <pcre_compile+0x11e8> */
/* @0x269658 b 0x26a170 <pcre_compile+0x11e8> */
/* @0x26965c b 0x26a09c <pcre_compile+0x1114> */
/* @0x269660 b 0x26a09c <pcre_compile+0x1114> */
/* @0x269664 b 0x269f50 <pcre_compile+0xfc8> */
/* @0x269668 b 0x26ad68 <pcre_compile+0x1de0> */
/* @0x26966c b 0x26ac6c <pcre_compile+0x1ce4> */
/* @0x269670 b 0x26a170 <pcre_compile+0x11e8> */
/* @0x269674 b 0x26a09c <pcre_compile+0x1114> */
/* @0x269678 b 0x269ff0 <pcre_compile+0x1068> */
/* @0x26967c b 0x269ff0 <pcre_compile+0x1068> */
/* @0x269680 b 0x26b05c <pcre_compile+0x20d4> */
/* @0x269684 b 0x26b05c <pcre_compile+0x20d4> */
/* @0x269688 b 0x26b050 <pcre_compile+0x20c8> */
/* @0x26968c b 0x26b050 <pcre_compile+0x20c8> */
/* @0x269690 b 0x26b068 <pcre_compile+0x20e0> */
/* @0x269694 b 0x26b068 <pcre_compile+0x20e0> */
/* @0x269698 b 0x26a218 <pcre_compile+0x1290> */
/* @0x26969c b 0x269ff0 <pcre_compile+0x1068> */
/* @0x2696a0 b 0x26b05c <pcre_compile+0x20d4> */
/* @0x2696a4 b 0x26b050 <pcre_compile+0x20c8> */
/* @0x2696a8 b 0x26b068 <pcre_compile+0x20e0> */
/* @0x2696ac b 0x26ad68 <pcre_compile+0x1de0> */
/* @0x2696b0 b 0x26ad68 <pcre_compile+0x1de0> */
/* @0x2696b4 b 0x26ac6c <pcre_compile+0x1ce4> */
/* @0x2696b8 b 0x26ac6c <pcre_compile+0x1ce4> */
/* @0x2696bc b 0x26a170 <pcre_compile+0x11e8> */
/* @0x2696c0 b 0x26a170 <pcre_compile+0x11e8> */
/* @0x2696c4 b 0x26a09c <pcre_compile+0x1114> */
/* @0x2696c8 b 0x26a09c <pcre_compile+0x1114> */
/* @0x2696cc b 0x269f50 <pcre_compile+0xfc8> */
/* @0x2696d0 b 0x26ad68 <pcre_compile+0x1de0> */
/* @0x2696d4 b 0x26ac6c <pcre_compile+0x1ce4> */
/* @0x2696d8 b 0x26a170 <pcre_compile+0x11e8> */
/* @0x2696dc b 0x26a09c <pcre_compile+0x1114> */
/* @0x2696e0 b 0x269ff0 <pcre_compile+0x1068> */
/* @0x2696e4 b 0x269ff0 <pcre_compile+0x1068> */
/* @0x2696e8 b 0x26b05c <pcre_compile+0x20d4> */
/* @0x2696ec b 0x26b05c <pcre_compile+0x20d4> */
/* @0x2696f0 b 0x26b050 <pcre_compile+0x20c8> */
/* @0x2696f4 b 0x26b050 <pcre_compile+0x20c8> */
/* @0x2696f8 b 0x26b068 <pcre_compile+0x20e0> */
/* @0x2696fc b 0x26b068 <pcre_compile+0x20e0> */
/* @0x269700 b 0x26a218 <pcre_compile+0x1290> */
/* @0x269704 b 0x269ff0 <pcre_compile+0x1068> */
/* @0x269708 b 0x26b05c <pcre_compile+0x20d4> */
/* @0x26970c b 0x26b050 <pcre_compile+0x20c8> */
/* @0x269710 b 0x26b068 <pcre_compile+0x20e0> */
/* @0x269714 b 0x26b9d8 <pcre_compile+0x2a50> */
/* @0x269718 b 0x26b9d8 <pcre_compile+0x2a50> */
/* @0x26971c b 0x26b8c8 <pcre_compile+0x2940> */
/* @0x269720 b 0x26b8c8 <pcre_compile+0x2940> */
/* @0x269724 b 0x26b7c8 <pcre_compile+0x2840> */
/* @0x269728 b 0x26b7c8 <pcre_compile+0x2840> */
/* @0x26972c b 0x26b6c0 <pcre_compile+0x2738> */
/* @0x269730 b 0x26b6c0 <pcre_compile+0x2738> */
/* @0x269734 b 0x26bb68 <pcre_compile+0x2be0> */
/* @0x269738 b 0x26b9d8 <pcre_compile+0x2a50> */
/* @0x26973c b 0x26b8c8 <pcre_compile+0x2940> */
/* @0x269740 b 0x26b7c8 <pcre_compile+0x2840> */
/* @0x269744 b 0x26b6c0 <pcre_compile+0x2738> */
/* @0x269748 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26974c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269750 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269754 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269758 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26975c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269760 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269764 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269768 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26976c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269770 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269774 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269778 b 0x26bad8 <pcre_compile+0x2b50> */
/* @0x26977c b 0x26bad8 <pcre_compile+0x2b50> */
/* @0x269780 b 0x26bad8 <pcre_compile+0x2b50> */
/* @0x269784 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269788 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26978c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269790 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269794 b 0x26b644 <pcre_compile+0x26bc> */
/* @0x269798 b 0x26b538 <pcre_compile+0x25b0> */
/* @0x26979c b 0x269d38 <pcre_compile+0xdb0> */
/* @0x2697a0 b 0x26c05c <pcre_compile+0x30d4> */
/* @0x2697a4 b 0x26c05c <pcre_compile+0x30d4> */
/* @0x2697a8 b 0x26c05c <pcre_compile+0x30d4> */
/* @0x2697ac b 0x26c05c <pcre_compile+0x30d4> */
/* @0x2697b0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2697b4 b 0x26bda8 <pcre_compile+0x2e20> */
/* @0x2697b8 b 0x26bda8 <pcre_compile+0x2e20> */
/* @0x2697bc b 0x26bda8 <pcre_compile+0x2e20> */
/* @0x2697c0 b 0x26bda8 <pcre_compile+0x2e20> */
/* @0x2697c4 b 0x26bc90 <pcre_compile+0x2d08> */
/* @0x2697c8 b 0x26bc90 <pcre_compile+0x2d08> */
/* @0x2697cc b 0x26bc30 <pcre_compile+0x2ca8> */
/* @0x2697d0 b 0x26bee4 <pcre_compile+0x2f5c> */
/* @0x2697d4 b 0x26be8c <pcre_compile+0x2f04> */
/* @0x2697d8 b 0x26bee4 <pcre_compile+0x2f5c> */
/* @0x2697dc b 0x26b110 <pcre_compile+0x2188> */
/* @0x2697e0 b 0x26bc30 <pcre_compile+0x2ca8> */
/* @0x2697e4 b 0x26bee4 <pcre_compile+0x2f5c> */
/* @0x2697e8 b 0x26be8c <pcre_compile+0x2f04> */
/* @0x2697ec b 0x26bee4 <pcre_compile+0x2f5c> */
/* @0x2697f0 b 0x26b110 <pcre_compile+0x2188> */
/* @0x2697f4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2697f8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2697fc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269800 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269804 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269808 b 0x26b078 <pcre_compile+0x20f0> */
/* @0x26980c b 0x26b078 <pcre_compile+0x20f0> */
/* @0x269810 b 0x26bee4 <pcre_compile+0x2f5c> */
/* @0x269814 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269818 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26981c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269820 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269824 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269828 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26982c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269830 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269834 b 0x26b524 <pcre_compile+0x259c> */
/* @0x269838 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26983c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269840 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269844 b 0x26b4ac <pcre_compile+0x2524> */
/* @0x269848 b 0x26b4a4 <pcre_compile+0x251c> */
/* @0x26984c b 0x26b4a4 <pcre_compile+0x251c> */
/* @0x269850 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269854 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269858 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26985c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269860 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269864 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269868 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26986c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269870 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269874 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269878 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26987c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269880 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269884 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269888 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26988c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269890 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269894 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269898 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26989c b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698a0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698a4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698a8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698ac b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698b0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698b4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698b8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698bc b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698c0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698c4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698c8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698cc b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698d0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698d4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698d8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698dc b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698e0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698e4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698e8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698ec b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698f0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698f4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698f8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2698fc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269900 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269904 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269908 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26990c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269910 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269914 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269918 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26991c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269920 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269924 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269928 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26992c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269930 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269934 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269938 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26993c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269940 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269944 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269948 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26994c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269950 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269954 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269958 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26995c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269960 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269964 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269968 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26996c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269970 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269974 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269978 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26997c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269980 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269984 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269988 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26998c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269990 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269994 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269998 b 0x2695a0 <pcre_compile+0x618> */
/* @0x26999c b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699a0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699a4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699a8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699ac b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699b0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699b4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699b8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699bc b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699c0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699c4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699c8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699cc b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699d0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699d4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699d8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699dc b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699e0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699e4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699e8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699ec b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699f0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699f4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699f8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x2699fc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a00 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a04 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a08 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a0c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a10 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a14 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a18 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a1c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a20 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a24 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a28 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a2c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a30 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a34 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a38 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a3c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a40 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a44 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a48 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a4c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a50 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a54 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a58 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a5c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a60 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a64 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a68 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a6c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a70 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a74 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a78 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a7c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a80 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a84 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a88 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a8c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a90 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a94 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a98 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269a9c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269aa0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269aa4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269aa8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269aac b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ab0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ab4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ab8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269abc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ac0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ac4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ac8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269acc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ad0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ad4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ad8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269adc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ae0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ae4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ae8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269aec b 0x2695a0 <pcre_compile+0x618> */
/* @0x269af0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269af4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269af8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269afc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b00 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b04 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b08 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b0c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b10 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b14 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b18 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b1c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b20 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b24 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b28 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b2c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b30 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b34 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b38 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b3c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b40 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b44 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b48 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b4c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b50 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b54 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b58 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b5c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b60 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b64 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b68 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b6c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b70 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b74 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b78 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b7c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b80 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b84 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b88 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b8c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b90 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b94 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b98 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269b9c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ba0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ba4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ba8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bac b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bb0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bb4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bb8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bbc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bc0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bc4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bc8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bcc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bd0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bd4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bd8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bdc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269be0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269be4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269be8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bec b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bf0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bf4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bf8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269bfc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c00 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c04 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c08 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c0c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c10 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c14 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c18 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c1c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c20 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c24 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c28 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c2c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c30 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c34 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c38 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c3c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c40 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c44 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c48 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c4c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c50 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c54 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c58 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c5c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c60 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c64 b 0x26b49c <pcre_compile+0x2514> */
/* @0x269c68 b 0x26b49c <pcre_compile+0x2514> */
/* @0x269c6c b 0x26b3d0 <pcre_compile+0x2448> */
/* @0x269c70 b 0x26b3d0 <pcre_compile+0x2448> */
/* @0x269c74 b 0x26b318 <pcre_compile+0x2390> */
/* @0x269c78 b 0x26b318 <pcre_compile+0x2390> */
/* @0x269c7c b 0x26b244 <pcre_compile+0x22bc> */
/* @0x269c80 b 0x26b244 <pcre_compile+0x22bc> */
/* @0x269c84 b 0x26b244 <pcre_compile+0x22bc> */
/* @0x269c88 b 0x26b49c <pcre_compile+0x2514> */
/* @0x269c8c b 0x26b3d0 <pcre_compile+0x2448> */
/* @0x269c90 b 0x26b318 <pcre_compile+0x2390> */
/* @0x269c94 b 0x26b244 <pcre_compile+0x22bc> */
/* @0x269c98 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269c9c b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ca0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ca4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269ca8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269cac b 0x2695a0 <pcre_compile+0x618> */
/* @0x269cb0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269cb4 b 0x26b1a0 <pcre_compile+0x2218> */
/* @0x269cb8 b 0x26b1a0 <pcre_compile+0x2218> */
/* @0x269cbc b 0x26c0d8 <pcre_compile+0x3150> */
/* @0x269cc0 b 0x26c0d8 <pcre_compile+0x3150> */
/* @0x269cc4 b 0x26c0d0 <pcre_compile+0x3148> */
/* @0x269cc8 b 0x26c0d0 <pcre_compile+0x3148> */
/* @0x269ccc b 0x26c1e8 <pcre_compile+0x3260> */
/* @0x269cd0 b 0x26c1e8 <pcre_compile+0x3260> */
/* @0x269cd4 b 0x26c1e8 <pcre_compile+0x3260> */
/* @0x269cd8 b 0x26b1a0 <pcre_compile+0x2218> */
/* @0x269cdc b 0x26c0d8 <pcre_compile+0x3150> */
/* @0x269ce0 b 0x26c0d0 <pcre_compile+0x3148> */
/* @0x269ce4 b 0x26c1e8 <pcre_compile+0x3260> */
/* @0x269ce8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269cec b 0x2695a0 <pcre_compile+0x618> */
/* @0x269cf0 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269cf4 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269cf8 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269cfc b 0x2695a0 <pcre_compile+0x618> */
/* @0x269d00 b 0x2695a0 <pcre_compile+0x618> */
/* @0x269d04 b 0x26be84 <pcre_compile+0x2efc> */
/* @0x269d08 b 0x26be84 <pcre_compile+0x2efc> */
/* @0x269d0c b 0x26a404 <pcre_compile+0x147c> */
/* @0x269d10 b 0x26a404 <pcre_compile+0x147c> */
/* @0x269d14 b 0x26a378 <pcre_compile+0x13f0> */
/* @0x269d18 b 0x26a378 <pcre_compile+0x13f0> */
/* @0x269d1c b 0x26a280 <pcre_compile+0x12f8> */
/* @0x269d20 b 0x26a280 <pcre_compile+0x12f8> */
/* @0x269d24 b 0x26a280 <pcre_compile+0x12f8> */
/* @0x269d28 b 0x26be84 <pcre_compile+0x2efc> */
/* @0x269d2c b 0x26a404 <pcre_compile+0x147c> */
/* @0x269d30 b 0x26a378 <pcre_compile+0x13f0> */
/* @0x269d34 b 0x26a280 <pcre_compile+0x12f8> —— 表 2 末项（数据） */
/* ──── S10 case 体群 A（1918 条） ──── */
/* @0x269d38 ldrb r2, [r4, #0x1] —— 477 项表之后：case 体群 A 起点 */
/* @0x269d3c ldrb r3, [r4, #0x2] */
/* @0x269d40 orr r3, r3, r2, lsl #8 */
/* @0x269d44 ldrb r3, [r4, r3]! */
/* @0x269d48 cmp r3, #119 */
/* @0x269d4c beq 0x269d38 <pcre_compile+0xdb0> */
/* @0x269d50 ldr r9, [sp, #0x30] */
/* @0x269d54 add r3, r8, #1 */
/* @0x269d58 cmp r8, r9 */
/* @0x269d5c bge 0x2691dc <pcre_compile+0x254> */
/* @0x269d60 ldr r7, [sp, #0x24] */
/* @0x269d64 mov r8, r3 */
/* @0x269d68 ldr r6, [sp, #0x3c] */
/* @0x269d6c mov r3, #0 */
/* @0x269d70 add r7, r7, #12 */
/* @0x269d74 add r5, r5, #1 */
/* @0x269d78 str r3, [r7, #-0x8] */
/* @0x269d7c rsb r4, r6, r4 */
/* @0x269d80 str r4, [r7, #-0xc] */
/* @0x269d84 str r7, [sp, #0x24] */
/* @0x269d88 b 0x269480 <pcre_compile+0x4f8> */
/* @0x269d8c ldr r3, [r6, #0x8] */
/* @0x269d90 cmp r3, #0 */
/* @0x269d94 ble 0x269df4 <pcre_compile+0xe6c> */
/* @0x269d98 ldr r4, [sp, #0x30] */
/* @0x269d9c add r2, r11, #1 */
/* @0x269da0 cmp r11, r4 */
/* @0x269da4 bge 0x2691dc <pcre_compile+0x254> */
/* @0x269da8 ldr r1, [r6, #0x4] */
/* @0x269dac sub r3, r3, #1 */
/* @0x269db0 ldr r6, [sp, #0x44] */
/* @0x269db4 add r5, r5, #1 */
/* @0x269db8 str r7, [r12] */
/* @0x269dbc mov r11, r2 */
/* @0x269dc0 cmp r6, #0 */
/* @0x269dc4 stmib r12, {r1, r3} */
/* @0x269dc8 add r12, r12, #12 */
/* @0x269dcc movne r7, #1 */
/* @0x269dd0 strne r7, [sp, #0x64] */
/* @0x269dd4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x269dd8 mvn r2, #0 */
/* @0x269ddc str r2, [sp, #0x2c] */
/* @0x269de0 b 0x2695b4 <pcre_compile+0x62c> */
/* @0x269de4 ldrb r3, [r4, r3] */
/* @0x269de8 str r3, [sp, #0x2c] */
/* @0x269dec mov r3, #1 */
/* @0x269df0 b 0x269560 <pcre_compile+0x5d8> */
/* @0x269df4 rsb r7, r7, #0 */
/* @0x269df8 str r7, [r6] */
/* @0x269dfc b 0x269438 <pcre_compile+0x4b0> */
/* @0x269e00 mvn r12, #0 */
/* @0x269e04 mov r4, #0 */
/* @0x269e08 str r12, [sp, #0x34] */
/* @0x269e0c str r4, [sp, #0x40] */
/* @0x269e10 b 0x2693e8 <pcre_compile+0x460> */
/* @0x269e14 ldr r1, [sp, #0x2c] —— 4 字节 UTF-8 分流（tst #16 已是 3 字节） */
/* @0x269e18 tst r1, #16 */
/* @0x269e1c beq 0x269f00 <pcre_compile+0xf78> */
/* @0x269e20 ldr r2, [sp, #0x2c] */
/* @0x269e24 tst r2, #8 */
/* @0x269e28 bne 0x26c314 <pcre_compile+0x338c> */
/* @0x269e2c add r2, r4, r3 */
/* @0x269e30 ldr r3, [sp, #0x2c] */
/* @0x269e34 ldrb r0, [r2, #0x3] */
/* @0x269e38 and r3, r3, #7 */
/* @0x269e3c str r3, [sp, #0x60] */
/* @0x269e40 mov r3, #4 */
/* @0x269e44 str r0, [sp, #0x2c] */
/* @0x269e48 ldrb r0, [r2, #0x1] */
/* @0x269e4c ldrb r2, [r2, #0x2] */
/* @0x269e50 and r0, r0, #63 */
/* @0x269e54 str r0, [sp, #0xb0] */
/* @0x269e58 ldr r0, [sp, #0x60] */
/* @0x269e5c str r2, [sp, #0x7c] */
/* @0x269e60 ldr r2, [sp, #0x2c] */
/* @0x269e64 and r1, r2, #63 */
/* @0x269e68 orr r1, r1, r0, lsl #18 */
/* @0x269e6c ldr r0, [sp, #0x7c] */
/* @0x269e70 and r2, r0, #63 */
/* @0x269e74 ldr r0, [sp, #0xb0] */
/* @0x269e78 orr r1, r1, r0, lsl #12 */
/* @0x269e7c orr r2, r1, r2, lsl #6 */
/* @0x269e80 str r2, [sp, #0x2c] */
/* @0x269e84 b 0x269560 <pcre_compile+0x5d8> */
/* @0x269e88 ldr r7, [sp, #0x28] */
/* @0x269e8c ldr r3, [r7, #0x18] */
/* @0x269e90 tst r3, #131072 */
/* @0x269e94 beq 0x269178 <pcre_compile+0x1f0> */
/* @0x269e98 ldrb r2, [r8, #0x1] */
/* @0x269e9c ldrb r3, [r8, #0x2] */
/* @0x269ea0 orr r3, r3, r2, lsl #8 */
/* @0x269ea4 ldrb r3, [r8, r3]! */
/* @0x269ea8 cmp r3, #119 */
/* @0x269eac beq 0x269e98 <pcre_compile+0xf10> */
/* @0x269eb0 add r9, sp, #8192 */
/* @0x269eb4 ldr r9, [r9, #0x48] */
/* @0x269eb8 ldm r9, {r3, r10} */
/* @0x269ebc cmp r3, #0 */
/* @0x269ec0 lsl r4, r10, #1 */
/* @0x269ec4 bne 0x2692ac <pcre_compile+0x324> */
/* @0x269ec8 add r2, r4, r10 */
/* @0x269ecc mov r0, r11 */
/* @0x269ed0 ldr r1, [sp, #0x58] */
/* @0x269ed4 lsl r2, r2, #2 */
/* @0x269ed8 bl 0xb65bc <memcpy@plt> —— memcpy@plt */
/* @0x269edc b 0x2692ac <pcre_compile+0x324> */
/* @0x269ee0 add r9, r9, #320 —— 伪 token：r9 += 320 后回总表 */
/* @0x269ee4 b 0x2695b4 <pcre_compile+0x62c> */
/* @0x269ee8 add r9, r9, #380 —— 伪 token：r9 += 380 */
/* @0x269eec b 0x2695b4 <pcre_compile+0x62c> */
/* @0x269ef0 add r9, r9, #340 —— 伪 token：r9 += 340 */
/* @0x269ef4 b 0x2695b4 <pcre_compile+0x62c> */
/* @0x269ef8 add r9, r9, #300 —— 伪 token：r9 += 300 */
/* @0x269efc b 0x2695b4 <pcre_compile+0x62c> */
/* @0x269f00 add r2, r4, r3 —— 3 字节 UTF-8：cp = ((b&0x0F)<<12)|... */
/* @0x269f04 lsl r1, r1, #12 */
/* @0x269f08 mov r3, #3 */
/* @0x269f0c ldrb r0, [r2, #0x2] */
/* @0x269f10 uxth r1, r1 */
/* @0x269f14 ldrb r2, [r2, #0x1] */
/* @0x269f18 and r0, r0, #63 */
/* @0x269f1c and r2, r2, #63 */
/* @0x269f20 orr r1, r0, r1 */
/* @0x269f24 orr r2, r1, r2, lsl #6 */
/* @0x269f28 str r2, [sp, #0x2c] */
/* @0x269f2c b 0x269560 <pcre_compile+0x5d8> */
/* @0x269f30 ldrb r3, [r7, #0x1] */
/* @0x269f34 and r2, r4, #31 */
/* @0x269f38 mov r5, #2 */
/* @0x269f3c str r5, [sp, #0x40] */
/* @0x269f40 and r3, r3, #63 */
/* @0x269f44 orr r3, r3, r2, lsl #6 */
/* @0x269f48 str r3, [sp, #0x34] */
/* @0x269f4c b 0x2693e8 <pcre_compile+0x460> */
/* @0x269f50 ldr r1, [sp, #0x40] */
/* @0x269f54 ldr r6, [r6, #0x4] */
/* @0x269f58 cmp r1, #0 */
/* @0x269f5c addeq r5, r5, #1 */
/* @0x269f60 str r6, [sp, #0x7c] */
/* @0x269f64 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x269f68 mvn r1, #0 */
/* @0x269f6c str r1, [sp, #0x60] */
/* @0x269f70 ldr r6, [sp, #0x34] */
/* @0x269f74 ldr r0, [sp, #0x60] */
/* @0x269f78 ldr r1, [sp, #0x2c] */
/* @0x269f7c cmp r6, r1 */
/* @0x269f80 cmpne r6, r0 */
/* @0x269f84 movne r6, #0 */
/* @0x269f88 moveq r6, #1 */
/* @0x269f8c cmp r9, #58 */
/* @0x269f90 eorgt r6, r6, #1 */
/* @0x269f94 cmp r6, #0 */
/* @0x269f98 addeq r5, r5, #1 */
/* @0x269f9c beq 0x269480 <pcre_compile+0x4f8> */
/* @0x269fa0 ldrb r0, [r4, #0x1] */
/* @0x269fa4 ldr r6, [sp, #0x7c] */
/* @0x269fa8 ldrb r1, [r4, #0x2] */
/* @0x269fac add r2, r6, #1 */
/* @0x269fb0 orr r1, r1, r0, lsl #8 */
/* @0x269fb4 cmp r2, r1 */
/* @0x269fb8 blt 0x26ca04 <pcre_compile+0x3a7c> */
/* @0x269fbc ldr r9, [sp, #0x30] */
/* @0x269fc0 add r2, r11, #1 */
/* @0x269fc4 cmp r11, r9 */
/* @0x269fc8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x269fcc add r3, r7, r3 */
/* @0x269fd0 add r5, r5, #1 */
/* @0x269fd4 add r3, r3, #3 */
/* @0x269fd8 mov r11, r2 */
/* @0x269fdc str r3, [r12] */
/* @0x269fe0 mov r3, #0 */
/* @0x269fe4 add r12, r12, #12 */
/* @0x269fe8 str r3, [r12, #-0x8] */
/* @0x269fec b 0x269480 <pcre_compile+0x4f8> */
/* @0x269ff0 sub r9, r9, #13 */
/* @0x269ff4 mov r1, #1 */
/* @0x269ff8 ldr r4, [sp, #0x30] */
/* @0x269ffc add r2, r8, #1 */
/* @0x26a000 cmp r8, r4 */
/* @0x26a004 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a008 ldr r6, [sp, #0x40] */
/* @0x26a00c add r3, r7, r3 */
/* @0x26a010 ldr r4, [sp, #0x24] */
/* @0x26a014 add r3, r3, #1 */
/* @0x26a018 cmp r6, #0 */
/* @0x26a01c addeq r5, r5, #1 */
/* @0x26a020 str r3, [r4] */
/* @0x26a024 moveq r8, r2 */
/* @0x26a028 mov r3, #0 */
/* @0x26a02c str r3, [r4, #0x4] */
/* @0x26a030 add r3, r4, #12 */
/* @0x26a034 streq r3, [sp, #0x24] */
/* @0x26a038 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a03c cmp r1, #0 */
/* @0x26a040 beq 0x26a060 <pcre_compile+0x10d8> */
/* @0x26a044 ldr r1, [sp, #0x48] */
/* @0x26a048 ldr r6, [sp, #0x2c] */
/* @0x26a04c cmp r6, #127 */
/* @0x26a050 movls r1, #0 */
/* @0x26a054 andhi r1, r1, #1 */
/* @0x26a058 cmp r1, #0 */
/* @0x26a05c beq 0x26ca38 <pcre_compile+0x3ab0> */
/* @0x26a060 mvn r1, #0 */
/* @0x26a064 ldr r6, [sp, #0x34] */
/* @0x26a068 ldr r4, [sp, #0x2c] */
/* @0x26a06c cmp r6, r4 */
/* @0x26a070 cmpne r6, r1 */
/* @0x26a074 movne r1, #0 */
/* @0x26a078 moveq r1, #1 */
/* @0x26a07c cmp r9, #58 */
/* @0x26a080 eorgt r1, r1, #1 */
/* @0x26a084 cmp r1, #0 */
/* @0x26a088 bne 0x26c5a8 <pcre_compile+0x3620> */
/* @0x26a08c add r5, r5, #1 */
/* @0x26a090 mov r8, r2 */
/* @0x26a094 str r3, [sp, #0x24] */
/* @0x26a098 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a09c mov r1, #0 */
/* @0x26a0a0 str r1, [sp, #0x7c] */
/* @0x26a0a4 ldr r2, [sp, #0x30] */
/* @0x26a0a8 add r0, r8, #1 */
/* @0x26a0ac str r0, [sp, #0xb4] */
/* @0x26a0b0 cmp r8, r2 */
/* @0x26a0b4 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a0b8 ldr r0, [sp, #0x24] */
/* @0x26a0bc add r3, r7, r3 */
/* @0x26a0c0 ldr r1, [sp, #0x40] */
/* @0x26a0c4 add r3, r3, #3 */
/* @0x26a0c8 mov r2, #0 */
/* @0x26a0cc str r3, [sp, #0x60] */
/* @0x26a0d0 cmp r1, #0 */
/* @0x26a0d4 mov r1, r0 */
/* @0x26a0d8 str r3, [r0] */
/* @0x26a0dc add r0, r0, #12 */
/* @0x26a0e0 str r2, [r1, #0x4] */
/* @0x26a0e4 ldr r6, [r6, #0x4] */
/* @0x26a0e8 str r6, [sp, #0xb0] */
/* @0x26a0ec beq 0x26c6fc <pcre_compile+0x3774> */
/* @0x26a0f0 ldr r2, [sp, #0x7c] */
/* @0x26a0f4 cmp r2, #0 */
/* @0x26a0f8 mvneq r2, #0 */
/* @0x26a0fc streq r2, [sp, #0x7c] */
/* @0x26a100 beq 0x26a130 <pcre_compile+0x11a8> */
/* @0x26a104 ldr r6, [sp, #0x2c] */
/* @0x26a108 ldr r3, [sp, #0x48] */
/* @0x26a10c cmp r6, #127 */
/* @0x26a110 movls r3, #0 */
/* @0x26a114 andhi r3, r3, #1 */
/* @0x26a118 cmp r3, #0 */
/* @0x26a11c ldreq r1, [sp, #0x88] */
/* @0x26a120 mvnne r3, #0 */
/* @0x26a124 strne r3, [sp, #0x7c] */
/* @0x26a128 ldrbeq r1, [r1, r6] */
/* @0x26a12c streq r1, [sp, #0x7c] */
/* @0x26a130 ldr r6, [sp, #0x34] */
/* @0x26a134 ldr r1, [sp, #0x7c] */
/* @0x26a138 ldr r2, [sp, #0x2c] */
/* @0x26a13c cmp r6, r2 */
/* @0x26a140 cmpne r6, r1 */
/* @0x26a144 movne r6, #0 */
/* @0x26a148 moveq r6, #1 */
/* @0x26a14c mov r3, r6 */
/* @0x26a150 cmp r9, #58 */
/* @0x26a154 eorgt r3, r3, #1 */
/* @0x26a158 cmp r3, #0 */
/* @0x26a15c bne 0x26c5f8 <pcre_compile+0x3670> */
/* @0x26a160 add r5, r5, #1 */
/* @0x26a164 ldr r8, [sp, #0xb4] */
/* @0x26a168 str r0, [sp, #0x24] */
/* @0x26a16c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a170 mov r1, #0 */
/* @0x26a174 ldr r6, [sp, #0x30] */
/* @0x26a178 add r2, r8, #1 */
/* @0x26a17c cmp r8, r6 */
/* @0x26a180 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a184 ldr r4, [sp, #0x40] */
/* @0x26a188 add r3, r7, r3 */
/* @0x26a18c ldr r6, [sp, #0x24] */
/* @0x26a190 mov r0, #0 */
/* @0x26a194 cmp r4, #0 */
/* @0x26a198 add r4, r3, #1 */
/* @0x26a19c addeq r5, r5, #1 */
/* @0x26a1a0 add r3, r6, #12 */
/* @0x26a1a4 str r4, [r6] */
/* @0x26a1a8 moveq r8, r2 */
/* @0x26a1ac str r0, [r6, #0x4] */
/* @0x26a1b0 streq r3, [sp, #0x24] */
/* @0x26a1b4 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a1b8 cmp r1, #0 */
/* @0x26a1bc beq 0x26a1dc <pcre_compile+0x1254> */
/* @0x26a1c0 ldr r1, [sp, #0x48] */
/* @0x26a1c4 ldr r7, [sp, #0x2c] */
/* @0x26a1c8 cmp r7, #127 */
/* @0x26a1cc movls r1, #0 */
/* @0x26a1d0 andhi r1, r1, #1 */
/* @0x26a1d4 cmp r1, #0 */
/* @0x26a1d8 beq 0x26ca2c <pcre_compile+0x3aa4> */
/* @0x26a1dc mvn r1, #0 */
/* @0x26a1e0 ldr r7, [sp, #0x34] */
/* @0x26a1e4 ldr r6, [sp, #0x2c] */
/* @0x26a1e8 cmp r7, r6 */
/* @0x26a1ec cmpne r7, r1 */
/* @0x26a1f0 movne r1, #0 */
/* @0x26a1f4 moveq r1, #1 */
/* @0x26a1f8 cmp r9, #58 */
/* @0x26a1fc eorgt r1, r1, #1 */
/* @0x26a200 cmp r1, #0 */
/* @0x26a204 bne 0x26c558 <pcre_compile+0x35d0> */
/* @0x26a208 add r5, r5, #1 */
/* @0x26a20c mov r8, r2 */
/* @0x26a210 str r3, [sp, #0x24] */
/* @0x26a214 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a218 ldr r0, [sp, #0x40] */
/* @0x26a21c sub r9, r9, #13 */
/* @0x26a220 ldr r6, [r6, #0x4] */
/* @0x26a224 cmp r0, #0 */
/* @0x26a228 addeq r5, r5, #1 */
/* @0x26a22c str r6, [sp, #0x7c] */
/* @0x26a230 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a234 ldr r2, [sp, #0x48] */
/* @0x26a238 ldr r6, [sp, #0x2c] */
/* @0x26a23c cmp r6, #127 */
/* @0x26a240 movls r2, #0 */
/* @0x26a244 andhi r2, r2, #1 */
/* @0x26a248 cmp r2, #0 */
/* @0x26a24c mvnne r2, #0 */
/* @0x26a250 strne r2, [sp, #0x60] */
/* @0x26a254 ldreq r0, [sp, #0x88] */
/* @0x26a258 ldrbeq r0, [r0, r6] */
/* @0x26a25c streq r0, [sp, #0x60] */
/* @0x26a260 b 0x269f70 <pcre_compile+0xfe8> —— b 之后跟 7 字字面量池 */
/* @0x26a264 andseq r2, r2, r8, lsl #17 —— 非指令：字面量池（andseq 是池数据） */
/* @0x26a268 andseq r2, r2, r0, lsl #17 */
/* @0x26a26c andseq r2, r2, r8, ror #16 */
/* @0x26a270 andseq r2, r2, r12, lsr r8 */
/* @0x26a274 andseq r2, r2, r0, lsr #16 */
/* @0x26a278 andseq r2, r2, r8, asr r6 */
/* @0x26a27c andseq r1, r2, r4, lsr #1 —— 非指令：池末字 */
/* @0x26a280 movw r3, #0x1d9 */
/* @0x26a284 cmp r9, r3 */
/* @0x26a288 beq 0x26a2bc <pcre_compile+0x1334> */
/* @0x26a28c ldr r0, [sp, #0x30] */
/* @0x26a290 add r3, r8, #1 */
/* @0x26a294 cmp r8, r0 */
/* @0x26a298 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a29c ldr r1, [sp, #0x24] */
/* @0x26a2a0 mov r8, r3 */
/* @0x26a2a4 add r2, r7, #4 */
/* @0x26a2a8 add r1, r1, #12 */
/* @0x26a2ac str r2, [r1, #-0xc] */
/* @0x26a2b0 mov r2, #0 */
/* @0x26a2b4 str r2, [r1, #-0x8] */
/* @0x26a2b8 str r1, [sp, #0x24] */
/* @0x26a2bc ldr r2, [sp, #0x40] */
/* @0x26a2c0 ldr r3, [r6, #0x4] */
/* @0x26a2c4 cmp r2, #0 */
/* @0x26a2c8 addeq r5, r5, #1 */
/* @0x26a2cc beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a2d0 ldr r6, [sp, #0x34] */
/* @0x26a2d4 cmp r6, #133 */
/* @0x26a2d8 beq 0x26cc30 <pcre_compile+0x3ca8> */
/* @0x26a2dc bhi 0x26cc1c <pcre_compile+0x3c94> */
/* @0x26a2e0 sub r2, r6, #10 */
/* @0x26a2e4 cmp r2, #3 */
/* @0x26a2e8 bls 0x26cc30 <pcre_compile+0x3ca8> */
/* @0x26a2ec mov r2, #0 */
/* @0x26a2f0 ldr r6, [sp, #0x2c] */
/* @0x26a2f4 subs r6, r6, #21 */
/* @0x26a2f8 rsbs r1, r6, #0 */
/* @0x26a2fc adcs r1, r1, r6 */
/* @0x26a300 cmp r1, r2 */
/* @0x26a304 addne r5, r5, #1 */
/* @0x26a308 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26a30c movw r2, #0x1dd */
/* @0x26a310 cmp r9, r2 */
/* @0x26a314 ldrb r1, [r4, #0x1] */
/* @0x26a318 add r3, r3, #1 */
/* @0x26a31c ldreq r9, [sp, #0x24] */
/* @0x26a320 subeq r8, r8, #1 */
/* @0x26a324 ldrb r2, [r4, #0x2] */
/* @0x26a328 subeq r9, r9, #12 */
/* @0x26a32c orr r2, r2, r1, lsl #8 */
/* @0x26a330 streq r9, [sp, #0x24] */
/* @0x26a334 cmp r3, r2 */
/* @0x26a338 blt 0x26d978 <pcre_compile+0x49f0> */
/* @0x26a33c ldr r4, [sp, #0x30] */
/* @0x26a340 add r2, r11, #1 */
/* @0x26a344 cmp r11, r4 */
/* @0x26a348 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a34c movw r3, #0xfffc */
/* @0x26a350 movt r3, #0xffff */
/* @0x26a354 mov r11, r2 */
/* @0x26a358 rsb r3, r7, r3 */
/* @0x26a35c mov r2, #0 */
/* @0x26a360 str r3, [r12] */
/* @0x26a364 str r2, [r12, #0x4] */
/* @0x26a368 add r5, r5, #1 */
/* @0x26a36c str r2, [r12, #0x8] */
/* @0x26a370 add r12, r12, #12 */
/* @0x26a374 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a378 mov r0, #2 */
/* @0x26a37c ldr r4, [sp, #0x30] */
/* @0x26a380 add r2, r8, #1 */
/* @0x26a384 cmp r8, r4 */
/* @0x26a388 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a38c ldr r6, [sp, #0x40] */
/* @0x26a390 add r3, r7, #2 */
/* @0x26a394 ldr r4, [sp, #0x24] */
/* @0x26a398 cmp r6, #0 */
/* @0x26a39c addeq r5, r5, #1 */
/* @0x26a3a0 str r3, [r4] */
/* @0x26a3a4 moveq r8, r2 */
/* @0x26a3a8 mov r3, #0 */
/* @0x26a3ac str r3, [r4, #0x4] */
/* @0x26a3b0 add r3, r4, #12 */
/* @0x26a3b4 streq r3, [sp, #0x24] */
/* @0x26a3b8 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a3bc ldr r6, [sp, #0x34] */
/* @0x26a3c0 cmp r6, #133 */
/* @0x26a3c4 beq 0x26c30c <pcre_compile+0x3384> */
/* @0x26a3c8 bhi 0x26c2f8 <pcre_compile+0x3370> */
/* @0x26a3cc sub r1, r6, #10 */
/* @0x26a3d0 cmp r1, #3 */
/* @0x26a3d4 bls 0x26c30c <pcre_compile+0x3384> */
/* @0x26a3d8 mov r1, #0 */
/* @0x26a3dc ldr r6, [sp, #0x2c] */
/* @0x26a3e0 subs r6, r6, #21 */
/* @0x26a3e4 rsbs r4, r6, #0 */
/* @0x26a3e8 adcs r4, r4, r6 */
/* @0x26a3ec cmp r4, r1 */
/* @0x26a3f0 beq 0x26cf74 <pcre_compile+0x3fec> */
/* @0x26a3f4 add r5, r5, #1 */
/* @0x26a3f8 mov r8, r2 */
/* @0x26a3fc str r3, [sp, #0x24] */
/* @0x26a400 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a404 ldr r3, [r6, #0x4] */
/* @0x26a408 cmp r3, #0 */
/* @0x26a40c ble 0x26a440 <pcre_compile+0x14b8> */
/* @0x26a410 ldr r6, [sp, #0x30] */
/* @0x26a414 add r2, r8, #1 */
/* @0x26a418 cmp r8, r6 */
/* @0x26a41c bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a420 ldr r4, [sp, #0x24] */
/* @0x26a424 mov r8, r2 */
/* @0x26a428 add r1, r7, #2 */
/* @0x26a42c add r4, r4, #12 */
/* @0x26a430 str r1, [r4, #-0xc] */
/* @0x26a434 mov r1, #0 */
/* @0x26a438 str r1, [r4, #-0x8] */
/* @0x26a43c str r4, [sp, #0x24] */
/* @0x26a440 ldr r6, [sp, #0x40] */
/* @0x26a444 cmp r6, #0 */
/* @0x26a448 addeq r5, r5, #1 */
/* @0x26a44c beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a450 ldr r4, [sp, #0x34] */
/* @0x26a454 cmp r4, #133 */
/* @0x26a458 beq 0x26cc14 <pcre_compile+0x3c8c> */
/* @0x26a45c bls 0x26cc08 <pcre_compile+0x3c80> */
/* @0x26a460 ldr r6, [sp, #0x34] */
/* @0x26a464 sub r2, r6, #8192 */
/* @0x26a468 sub r2, r2, #40 */
/* @0x26a46c cmp r2, #1 */
/* @0x26a470 bls 0x26cc14 <pcre_compile+0x3c8c> */
/* @0x26a474 mov r2, #0 */
/* @0x26a478 ldr r4, [sp, #0x2c] */
/* @0x26a47c subs r0, r4, #21 */
/* @0x26a480 rsbs r1, r0, #0 */
/* @0x26a484 adcs r1, r1, r0 */
/* @0x26a488 cmp r1, r2 */
/* @0x26a48c addne r5, r5, #1 */
/* @0x26a490 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26a494 movw r2, #0x1db */
/* @0x26a498 subs r2, r9, r2 */
/* @0x26a49c rsbs r9, r2, #0 */
/* @0x26a4a0 adcs r9, r9, r2 */
/* @0x26a4a4 cmp r3, #0 */
/* @0x26a4a8 add r2, r11, #1 */
/* @0x26a4ac add r3, r3, #1 */
/* @0x26a4b0 movle r9, #0 */
/* @0x26a4b4 cmp r9, #0 */
/* @0x26a4b8 ldr r9, [sp, #0x30] */
/* @0x26a4bc subne r8, r8, #1 */
/* @0x26a4c0 ldrne r6, [sp, #0x24] */
/* @0x26a4c4 subne r6, r6, #12 */
/* @0x26a4c8 strne r6, [sp, #0x24] */
/* @0x26a4cc cmp r11, r9 */
/* @0x26a4d0 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a4d4 str r3, [r12, #0x4] */
/* @0x26a4d8 rsb r7, r7, #0 */
/* @0x26a4dc mov r3, #0 */
/* @0x26a4e0 str r7, [r12] */
/* @0x26a4e4 str r3, [r12, #0x8] */
/* @0x26a4e8 add r5, r5, #1 */
/* @0x26a4ec mov r11, r2 */
/* @0x26a4f0 add r12, r12, #12 */
/* @0x26a4f4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a4f8 ldr r4, [sp, #0x28] */
/* @0x26a4fc ldr r3, [r4, #0x18] */
/* @0x26a500 tst r3, #256 */
/* @0x26a504 bne 0x26cfd4 <pcre_compile+0x404c> */
/* @0x26a508 ldr r6, [sp, #0x40] */
/* @0x26a50c cmp r6, #0 */
/* @0x26a510 beq 0x26cbc8 <pcre_compile+0x3c40> */
/* @0x26a514 ldr r6, [sp, #0x28] */
/* @0x26a518 ldr r3, [r6, #0x1c] */
/* @0x26a51c tst r3, #32 */
/* @0x26a520 bne 0x26dd1c <pcre_compile+0x4d94> */
/* @0x26a524 ldr r1, [r6, #0x20] */
/* @0x26a528 cmp r1, #0 */
/* @0x26a52c beq 0x26e22c <pcre_compile+0x52a4> */
/* @0x26a530 ldr r2, [r6, #0x8] */
/* @0x26a534 ldr r9, [sp, #0x38] */
/* @0x26a538 cmp r9, r2 */
/* @0x26a53c blo 0x26e2ac <pcre_compile+0x5324> */
/* @0x26a540 ldr r9, [sp, #0x38] */
/* @0x26a544 add r3, r9, #1 */
/* @0x26a548 cmp r2, r3 */
/* @0x26a54c addhi r5, r5, #1 */
/* @0x26a550 bhi 0x269480 <pcre_compile+0x4f8> */
/* @0x26a554 ldr r4, [sp, #0x28] */
/* @0x26a558 mov r3, #32768 */
/* @0x26a55c movt r3, #0x800 */
/* @0x26a560 ldr r1, [r4, #0x18] */
/* @0x26a564 and r3, r1, r3 */
/* @0x26a568 cmp r3, #0 */
/* @0x26a56c addeq r5, r5, #1 */
/* @0x26a570 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a574 ldr r6, [sp, #0x28] */
/* @0x26a578 ldr r2, [r6, #0x20] */
/* @0x26a57c cmp r2, #0 */
/* @0x26a580 addne r5, r5, #1 */
/* @0x26a584 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26a588 ldr r9, [sp, #0x28] */
/* @0x26a58c ldr r3, [r9, #0x24] */
/* @0x26a590 cmp r3, #2 */
/* @0x26a594 addne r5, r5, #1 */
/* @0x26a598 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26a59c ldr r4, [sp, #0x28] */
/* @0x26a5a0 ldr r6, [sp, #0x34] */
/* @0x26a5a4 ldrb r3, [r4, #0x28] */
/* @0x26a5a8 cmp r3, r6 */
/* @0x26a5ac addne r5, r5, #1 */
/* @0x26a5b0 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26a5b4 tst r1, #134217728 */
/* @0x26a5b8 bne 0x26e274 <pcre_compile+0x52ec> */
/* @0x26a5bc mov r7, #1 */
/* @0x26a5c0 str r7, [sp, #0x44] */
/* @0x26a5c4 add r5, r5, r7 */
/* @0x26a5c8 str r7, [sp, #0x4c] */
/* @0x26a5cc b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a5d0 ldr r9, [sp, #0x28] */
/* @0x26a5d4 ldr r3, [r9, #0x18] */
/* @0x26a5d8 tst r3, #256 */
/* @0x26a5dc addne r5, r5, #1 */
/* @0x26a5e0 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26a5e4 ldr r4, [sp, #0x40] */
/* @0x26a5e8 cmp r4, #0 */
/* @0x26a5ec beq 0x26cb88 <pcre_compile+0x3c00> */
/* @0x26a5f0 ldr r9, [sp, #0x28] */
/* @0x26a5f4 ldr r3, [r9, #0x1c] */
/* @0x26a5f8 tst r3, #32 */
/* @0x26a5fc bne 0x26d9c8 <pcre_compile+0x4a40> */
/* @0x26a600 ldr r1, [r9, #0x20] */
/* @0x26a604 cmp r1, #0 */
/* @0x26a608 beq 0x26df08 <pcre_compile+0x4f80> */
/* @0x26a60c ldr r2, [r9, #0x8] */
/* @0x26a610 ldr r4, [sp, #0x38] */
/* @0x26a614 cmp r4, r2 */
/* @0x26a618 blo 0x26e48c <pcre_compile+0x5504> */
/* @0x26a61c ldr r6, [sp, #0x38] */
/* @0x26a620 add r3, r6, #1 */
/* @0x26a624 cmp r2, r3 */
/* @0x26a628 addhi r5, r5, #1 */
/* @0x26a62c bhi 0x269480 <pcre_compile+0x4f8> */
/* @0x26a630 ldr r9, [sp, #0x28] */
/* @0x26a634 mov r3, #32768 */
/* @0x26a638 movt r3, #0x800 */
/* @0x26a63c ldr r1, [r9, #0x18] */
/* @0x26a640 and r3, r1, r3 */
/* @0x26a644 cmp r3, #0 */
/* @0x26a648 addeq r5, r5, #1 */
/* @0x26a64c beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a650 ldr r4, [sp, #0x28] */
/* @0x26a654 ldr r2, [r4, #0x20] */
/* @0x26a658 cmp r2, #0 */
/* @0x26a65c addne r5, r5, #1 */
/* @0x26a660 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26a664 ldr r6, [sp, #0x28] */
/* @0x26a668 ldr r3, [r6, #0x24] */
/* @0x26a66c cmp r3, #2 */
/* @0x26a670 addne r5, r5, #1 */
/* @0x26a674 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26a678 ldr r9, [sp, #0x28] */
/* @0x26a67c ldr r4, [sp, #0x34] */
/* @0x26a680 ldrb r3, [r9, #0x28] */
/* @0x26a684 cmp r3, r4 */
/* @0x26a688 addne r5, r5, #1 */
/* @0x26a68c bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26a690 tst r1, #134217728 */
/* @0x26a694 bne 0x26e454 <pcre_compile+0x54cc> */
/* @0x26a698 mov r6, #1 */
/* @0x26a69c str r6, [sp, #0x44] */
/* @0x26a6a0 add r5, r5, r6 */
/* @0x26a6a4 str r6, [sp, #0x4c] */
/* @0x26a6a8 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a6ac ldr r4, [sp, #0x38] */
/* @0x26a6b0 ldr r6, [sp, #0x68] */
/* @0x26a6b4 cmp r4, r6 */
/* @0x26a6b8 addlo r5, r5, #1 */
/* @0x26a6bc blo 0x269480 <pcre_compile+0x4f8> */
/* @0x26a6c0 ldr r9, [sp, #0x28] */
/* @0x26a6c4 ldr r3, [r9, #0x18] */
/* @0x26a6c8 ands r3, r3, #134217728 */
/* @0x26a6cc bne 0x26cb64 <pcre_compile+0x3bdc> */
/* @0x26a6d0 ldr r6, [sp, #0x30] */
/* @0x26a6d4 add r2, r8, #1 */
/* @0x26a6d8 cmp r8, r6 */
/* @0x26a6dc bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a6e0 ldr r9, [sp, #0x24] */
/* @0x26a6e4 add r7, r7, #1 */
/* @0x26a6e8 add r5, r5, #1 */
/* @0x26a6ec mov r8, r2 */
/* @0x26a6f0 add r9, r9, #12 */
/* @0x26a6f4 str r3, [r9, #-0x8] */
/* @0x26a6f8 str r7, [r9, #-0xc] */
/* @0x26a6fc str r9, [sp, #0x24] */
/* @0x26a700 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a704 ldr r6, [sp, #0x40] */
/* @0x26a708 ldr r9, [sp, #0x28] */
/* @0x26a70c cmp r6, #0 */
/* @0x26a710 bne 0x26d040 <pcre_compile+0x40b8> */
/* @0x26a714 ldr r3, [r9, #0x18] */
/* @0x26a718 tst r3, #134217728 */
/* @0x26a71c bne 0x26cb54 <pcre_compile+0x3bcc> */
/* @0x26a720 ldr r4, [sp, #0x30] */
/* @0x26a724 add r3, r8, #1 */
/* @0x26a728 cmp r8, r4 */
/* @0x26a72c bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a730 ldr r6, [sp, #0x24] */
/* @0x26a734 add r7, r7, #1 */
/* @0x26a738 mov r8, r3 */
/* @0x26a73c add r5, r5, #1 */
/* @0x26a740 mov r3, #0 */
/* @0x26a744 add r6, r6, #12 */
/* @0x26a748 str r7, [r6, #-0xc] */
/* @0x26a74c str r3, [r6, #-0x8] */
/* @0x26a750 str r6, [sp, #0x24] */
/* @0x26a754 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a758 ldr r4, [sp, #0x40] */
/* @0x26a75c cmp r4, #0 */
/* @0x26a760 addeq r5, r5, #1 */
/* @0x26a764 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a768 ldr r6, [sp, #0x34] */
/* @0x26a76c cmp r6, #133 */
/* @0x26a770 beq 0x26a78c <pcre_compile+0x1804> */
/* @0x26a774 bls 0x26cb40 <pcre_compile+0x3bb8> */
/* @0x26a778 ldr r9, [sp, #0x34] */
/* @0x26a77c sub r3, r9, #8192 */
/* @0x26a780 sub r3, r3, #40 */
/* @0x26a784 cmp r3, #1 */
/* @0x26a788 bhi 0x26cb4c <pcre_compile+0x3bc4> */
/* @0x26a78c ldr r4, [sp, #0x30] */
/* @0x26a790 add r3, r11, #1 */
/* @0x26a794 cmp r11, r4 */
/* @0x26a798 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a79c add r7, r7, #1 */
/* @0x26a7a0 mov r11, r3 */
/* @0x26a7a4 str r7, [r12] */
/* @0x26a7a8 mov r3, #0 */
/* @0x26a7ac add r5, r5, #1 */
/* @0x26a7b0 str r3, [r12, #0x4] */
/* @0x26a7b4 add r12, r12, #12 */
/* @0x26a7b8 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a7bc ldr r6, [sp, #0x40] */
/* @0x26a7c0 cmp r6, #0 */
/* @0x26a7c4 addeq r5, r5, #1 */
/* @0x26a7c8 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a7cc ldr r9, [sp, #0x34] */
/* @0x26a7d0 movw r3, #0x180e */
/* @0x26a7d4 cmp r9, r3 */
/* @0x26a7d8 beq 0x26a80c <pcre_compile+0x1884> */
/* @0x26a7dc bls 0x26c978 <pcre_compile+0x39f0> */
/* @0x26a7e0 ldr r6, [sp, #0x34] */
/* @0x26a7e4 movw r3, #0x202f */
/* @0x26a7e8 cmp r6, r3 */
/* @0x26a7ec beq 0x26a80c <pcre_compile+0x1884> */
/* @0x26a7f0 bls 0x26d9b8 <pcre_compile+0x4a30> */
/* @0x26a7f4 ldr r9, [sp, #0x34] */
/* @0x26a7f8 movw r3, #0x205f */
/* @0x26a7fc cmp r9, r3 */
/* @0x26a800 beq 0x26a80c <pcre_compile+0x1884> */
/* @0x26a804 cmp r9, #12288 */
/* @0x26a808 bne 0x26c998 <pcre_compile+0x3a10> */
/* @0x26a80c ldr r4, [sp, #0x30] */
/* @0x26a810 add r3, r11, #1 */
/* @0x26a814 cmp r11, r4 */
/* @0x26a818 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a81c add r7, r7, #1 */
/* @0x26a820 mov r11, r3 */
/* @0x26a824 str r7, [r12] */
/* @0x26a828 mov r3, #0 */
/* @0x26a82c add r5, r5, #1 */
/* @0x26a830 str r3, [r12, #0x4] */
/* @0x26a834 add r12, r12, #12 */
/* @0x26a838 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a83c ldr r6, [sp, #0x40] */
/* @0x26a840 cmp r6, #0 */
/* @0x26a844 addeq r5, r5, #1 */
/* @0x26a848 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a84c ldr r9, [sp, #0x34] */
/* @0x26a850 movw r3, #0x180e */
/* @0x26a854 cmp r9, r3 */
/* @0x26a858 beq 0x26c970 <pcre_compile+0x39e8> */
/* @0x26a85c bhi 0x26c944 <pcre_compile+0x39bc> */
/* @0x26a860 cmp r9, #32 */
/* @0x26a864 beq 0x26c970 <pcre_compile+0x39e8> */
/* @0x26a868 bls 0x26de48 <pcre_compile+0x4ec0> */
/* @0x26a86c ldr r4, [sp, #0x34] */
/* @0x26a870 cmp r4, #160 */
/* @0x26a874 beq 0x26c970 <pcre_compile+0x39e8> */
/* @0x26a878 cmp r4, #5760 */
/* @0x26a87c beq 0x26c970 <pcre_compile+0x39e8> */
/* @0x26a880 ldr r4, [sp, #0x30] */
/* @0x26a884 add r3, r11, #1 */
/* @0x26a888 cmp r11, r4 */
/* @0x26a88c bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a890 add r7, r7, #1 */
/* @0x26a894 mov r11, r3 */
/* @0x26a898 str r7, [r12] */
/* @0x26a89c mov r3, #0 */
/* @0x26a8a0 add r5, r5, #1 */
/* @0x26a8a4 str r3, [r12, #0x4] */
/* @0x26a8a8 add r12, r12, #12 */
/* @0x26a8ac b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a8b0 ldr r9, [sp, #0x40] */
/* @0x26a8b4 cmp r9, #0 */
/* @0x26a8b8 addeq r5, r5, #1 */
/* @0x26a8bc beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a8c0 ldr r4, [sp, #0x34] */
/* @0x26a8c4 cmp r4, #133 */
/* @0x26a8c8 beq 0x26cd88 <pcre_compile+0x3e00> */
/* @0x26a8cc bls 0x26cd7c <pcre_compile+0x3df4> */
/* @0x26a8d0 ldr r6, [sp, #0x34] */
/* @0x26a8d4 sub r3, r6, #8192 */
/* @0x26a8d8 sub r3, r3, #40 */
/* @0x26a8dc cmp r3, #1 */
/* @0x26a8e0 bls 0x26cd88 <pcre_compile+0x3e00> */
/* @0x26a8e4 ldr r9, [sp, #0x30] */
/* @0x26a8e8 add r3, r11, #1 */
/* @0x26a8ec cmp r11, r9 */
/* @0x26a8f0 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a8f4 add r7, r7, #1 */
/* @0x26a8f8 mov r11, r3 */
/* @0x26a8fc str r7, [r12] */
/* @0x26a900 mov r3, #0 */
/* @0x26a904 add r5, r5, #1 */
/* @0x26a908 str r3, [r12, #0x4] */
/* @0x26a90c add r12, r12, #12 */
/* @0x26a910 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a914 ldr r9, [sp, #0x40] */
/* @0x26a918 cmp r9, #0 */
/* @0x26a91c addeq r5, r5, #1 */
/* @0x26a920 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a924 ldr r4, [sp, #0x34] */
/* @0x26a928 cmp r4, #13 */
/* @0x26a92c beq 0x26d904 <pcre_compile+0x497c> */
/* @0x26a930 bhi 0x26ccd0 <pcre_compile+0x3d48> */
/* @0x26a934 cmp r4, #10 */
/* @0x26a938 bne 0x26d95c <pcre_compile+0x49d4> */
/* @0x26a93c ldr r4, [sp, #0x30] */
/* @0x26a940 add r3, r11, #1 */
/* @0x26a944 cmp r11, r4 */
/* @0x26a948 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a94c add r7, r7, #1 */
/* @0x26a950 mov r11, r3 */
/* @0x26a954 str r7, [r12] */
/* @0x26a958 mov r3, #0 */
/* @0x26a95c add r5, r5, #1 */
/* @0x26a960 str r3, [r12, #0x4] */
/* @0x26a964 add r12, r12, #12 */
/* @0x26a968 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a96c ldr r9, [sp, #0x40] */
/* @0x26a970 cmp r9, #0 */
/* @0x26a974 addeq r5, r5, #1 */
/* @0x26a978 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a97c ldr r4, [sp, #0x30] */
/* @0x26a980 add r3, r11, #1 */
/* @0x26a984 cmp r11, r4 */
/* @0x26a988 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26a98c add r7, r7, #1 */
/* @0x26a990 mov r11, r3 */
/* @0x26a994 str r7, [r12] */
/* @0x26a998 mov r3, #0 */
/* @0x26a99c add r5, r5, #1 */
/* @0x26a9a0 str r3, [r12, #0x4] */
/* @0x26a9a4 add r12, r12, #12 */
/* @0x26a9a8 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26a9ac ldr r4, [sp, #0x40] */
/* @0x26a9b0 cmp r4, #0 */
/* @0x26a9b4 addeq r5, r5, #1 */
/* @0x26a9b8 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26a9bc ldr r6, [sp, #0x28] */
/* @0x26a9c0 ldr r1, [r6, #0x20] */
/* @0x26a9c4 cmp r1, #0 */
/* @0x26a9c8 bne 0x26ca9c <pcre_compile+0x3b14> */
/* @0x26a9cc ldr r6, [sp, #0x28] */
/* @0x26a9d0 ldr r9, [sp, #0x38] */
/* @0x26a9d4 ldr r3, [r6, #0x24] */
/* @0x26a9d8 ldr r2, [r6, #0x8] */
/* @0x26a9dc rsb r2, r3, r2 */
/* @0x26a9e0 cmp r9, r2 */
/* @0x26a9e4 bhi 0x26a9f8 <pcre_compile+0x1a70> */
/* @0x26a9e8 ldrb r0, [r9] */
/* @0x26a9ec ldrb r2, [r6, #0x28] */
/* @0x26a9f0 cmp r0, r2 */
/* @0x26a9f4 beq 0x26e0f4 <pcre_compile+0x516c> */
/* @0x26a9f8 mov r3, #1 */
/* @0x26a9fc cmp r3, #0 */
/* @0x26aa00 addeq r5, r5, #1 */
/* @0x26aa04 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26aa08 ldr r4, [sp, #0x28] */
/* @0x26aa0c ldr r6, [sp, #0x38] */
/* @0x26aa10 ldr r2, [r4, #0x8] */
/* @0x26aa14 add r3, r6, #1 */
/* @0x26aa18 cmp r2, r3 */
/* @0x26aa1c bhi 0x26aa44 <pcre_compile+0x1abc> */
/* @0x26aa20 ldr r3, [r4, #0x18] */
/* @0x26aa24 tst r3, #134217728 */
/* @0x26aa28 beq 0x26aa44 <pcre_compile+0x1abc> */
/* @0x26aa2c ldr r3, [r4, #0x20] */
/* @0x26aa30 cmp r3, #0 */
/* @0x26aa34 bne 0x26aa44 <pcre_compile+0x1abc> */
/* @0x26aa38 ldr r3, [r4, #0x24] */
/* @0x26aa3c cmp r3, #2 */
/* @0x26aa40 beq 0x26e0d0 <pcre_compile+0x5148> */
/* @0x26aa44 ldr r6, [sp, #0x30] */
/* @0x26aa48 add r3, r11, #1 */
/* @0x26aa4c cmp r11, r6 */
/* @0x26aa50 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26aa54 add r7, r7, #1 */
/* @0x26aa58 mov r11, r3 */
/* @0x26aa5c str r7, [r12] */
/* @0x26aa60 mov r3, #0 */
/* @0x26aa64 add r5, r5, #1 */
/* @0x26aa68 str r3, [r12, #0x4] */
/* @0x26aa6c add r12, r12, #12 */
/* @0x26aa70 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26aa74 ldr r6, [sp, #0x40] */
/* @0x26aa78 ldr r4, [sp, #0x34] */
/* @0x26aa7c cmp r6, #0 */
/* @0x26aa80 movle r3, #0 */
/* @0x26aa84 movgt r3, #1 */
/* @0x26aa88 cmp r4, #255 */
/* @0x26aa8c movhi r3, #0 */
/* @0x26aa90 cmp r3, #0 */
/* @0x26aa94 addeq r5, r5, #1 */
/* @0x26aa98 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26aa9c ldr r2, [pc, #-0x828] */
/* @0x26aaa0 ldr r4, [sp, #0x78] */
/* @0x26aaa4 add r2, pc, r2 */
/* @0x26aaa8 ldr r6, [sp, #0x34] */
/* @0x26aaac add r9, r2, r9 */
/* @0x26aab0 ldrb r3, [r4, r6] */
/* @0x26aab4 ldrb r1, [r9, #-0xc44] */
/* @0x26aab8 ldrb r2, [r9, #-0xc34] */
/* @0x26aabc and r3, r1, r3 */
/* @0x26aac0 cmp r2, r3 */
/* @0x26aac4 addeq r5, r5, #1 */
/* @0x26aac8 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26aacc ldr r6, [sp, #0x30] */
/* @0x26aad0 add r3, r11, #1 */
/* @0x26aad4 cmp r11, r6 */
/* @0x26aad8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26aadc add r7, r7, #1 */
/* @0x26aae0 mov r11, r3 */
/* @0x26aae4 str r7, [r12] */
/* @0x26aae8 mov r3, #0 */
/* @0x26aaec add r5, r5, #1 */
/* @0x26aaf0 str r3, [r12, #0x4] */
/* @0x26aaf4 add r12, r12, #12 */
/* @0x26aaf8 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26aafc ldr r4, [sp, #0x40] */
/* @0x26ab00 cmp r4, #0 */
/* @0x26ab04 addeq r5, r5, #1 */
/* @0x26ab08 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26ab0c ldr r6, [sp, #0x34] */
/* @0x26ab10 cmp r6, #255 */
/* @0x26ab14 bls 0x26ca6c <pcre_compile+0x3ae4> */
/* @0x26ab18 ldr r6, [sp, #0x30] */
/* @0x26ab1c add r3, r11, #1 */
/* @0x26ab20 cmp r11, r6 */
/* @0x26ab24 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26ab28 add r7, r7, #1 */
/* @0x26ab2c mov r11, r3 */
/* @0x26ab30 str r7, [r12] */
/* @0x26ab34 mov r3, #0 */
/* @0x26ab38 add r5, r5, #1 */
/* @0x26ab3c str r3, [r12, #0x4] */
/* @0x26ab40 add r12, r12, #12 */
/* @0x26ab44 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26ab48 ldr r4, [sp, #0x38] */
/* @0x26ab4c ldr r6, [sp, #0x54] */
/* @0x26ab50 cmp r4, r6 */
/* @0x26ab54 bls 0x26c38c <pcre_compile+0x3404> */
/* @0x26ab58 ldr r4, [sp, #0x28] */
/* @0x26ab5c ldr r6, [sp, #0x38] */
/* @0x26ab60 ldr r2, [r4, #0xc] */
/* @0x26ab64 sub r3, r6, #1 */
/* @0x26ab68 cmp r3, r2 */
/* @0x26ab6c strlo r3, [r4, #0xc] */
/* @0x26ab70 ldr r4, [sp, #0x48] */
/* @0x26ab74 cmp r4, #0 */
/* @0x26ab78 bne 0x26cd90 <pcre_compile+0x3e08> */
/* @0x26ab7c ldr r6, [sp, #0x38] */
/* @0x26ab80 ldrb r0, [r6, #-0x1] */
/* @0x26ab84 ldr r2, [sp, #0x48] */
/* @0x26ab88 cmp r0, #191 */
/* @0x26ab8c movls r2, #0 */
/* @0x26ab90 andhi r2, r2, #1 */
/* @0x26ab94 cmp r2, #0 */
/* @0x26ab98 beq 0x26abbc <pcre_compile+0x1c34> */
/* @0x26ab9c tst r0, #32 */
/* @0x26aba0 bne 0x26dc24 <pcre_compile+0x4c9c> */
/* @0x26aba4 ldrb r3, [r3, #0x1] */
/* @0x26aba8 and r0, r0, #31 */
/* @0x26abac and r3, r3, #63 */
/* @0x26abb0 orr r0, r3, r0, lsl #6 */
/* @0x26abb4 cmp r0, #255 */
/* @0x26abb8 bhi 0x26c38c <pcre_compile+0x3404> */
/* @0x26abbc ldr r6, [sp, #0x78] */
/* @0x26abc0 ldrb r3, [r6, r0] */
/* @0x26abc4 ubfx r3, r3, #0x4, #0x1 */
/* @0x26abc8 b 0x26c390 <pcre_compile+0x3408> */
/* @0x26abcc ldr r6, [sp, #0x54] */
/* @0x26abd0 ldr r9, [sp, #0x8c] */
/* @0x26abd4 ldr r4, [sp, #0x38] */
/* @0x26abd8 add r3, r6, r9 */
/* @0x26abdc cmp r3, r4 */
/* @0x26abe0 addne r5, r5, #1 */
/* @0x26abe4 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26abe8 ldr r6, [sp, #0x30] */
/* @0x26abec add r3, r8, #1 */
/* @0x26abf0 cmp r8, r6 */
/* @0x26abf4 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26abf8 ldr r9, [sp, #0x24] */
/* @0x26abfc add r7, r7, #1 */
/* @0x26ac00 mov r8, r3 */
/* @0x26ac04 add r5, r5, #1 */
/* @0x26ac08 mov r3, #0 */
/* @0x26ac0c add r9, r9, #12 */
/* @0x26ac10 str r7, [r9, #-0xc] */
/* @0x26ac14 str r3, [r9, #-0x8] */
/* @0x26ac18 str r9, [sp, #0x24] */
/* @0x26ac1c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26ac20 ldr r4, [sp, #0x38] */
/* @0x26ac24 ldr r6, [sp, #0x54] */
/* @0x26ac28 cmp r4, r6 */
/* @0x26ac2c addne r5, r5, #1 */
/* @0x26ac30 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26ac34 ldr r9, [sp, #0x30] */
/* @0x26ac38 add r3, r8, #1 */
/* @0x26ac3c cmp r8, r9 */
/* @0x26ac40 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26ac44 ldr r4, [sp, #0x24] */
/* @0x26ac48 add r7, r7, #1 */
/* @0x26ac4c mov r8, r3 */
/* @0x26ac50 add r5, r5, #1 */
/* @0x26ac54 mov r3, #0 */
/* @0x26ac58 add r4, r4, #12 */
/* @0x26ac5c str r7, [r4, #-0xc] */
/* @0x26ac60 str r3, [r4, #-0x8] */
/* @0x26ac64 str r4, [sp, #0x24] */
/* @0x26ac68 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26ac6c mov r4, #0 */
/* @0x26ac70 ldr r1, [r6, #0x4] */
/* @0x26ac74 cmp r1, #0 */
/* @0x26ac78 ble 0x26c7ac <pcre_compile+0x3824> */
/* @0x26ac7c ldr r6, [sp, #0x30] */
/* @0x26ac80 add r2, r8, #1 */
/* @0x26ac84 cmp r8, r6 */
/* @0x26ac88 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26ac8c ldr r6, [sp, #0x24] */
/* @0x26ac90 add r3, r7, r3 */
/* @0x26ac94 mov r0, #0 */
/* @0x26ac98 add r3, r3, #1 */
/* @0x26ac9c add r6, r6, #12 */
/* @0x26aca0 str r0, [r6, #-0x8] */
/* @0x26aca4 str r3, [r6, #-0xc] */
/* @0x26aca8 str r6, [sp, #0x24] */
/* @0x26acac ldr r6, [sp, #0x40] */
/* @0x26acb0 cmp r6, #0 */
/* @0x26acb4 addeq r5, r5, #1 */
/* @0x26acb8 moveq r8, r2 */
/* @0x26acbc beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26acc0 cmp r4, #0 */
/* @0x26acc4 beq 0x26ace4 <pcre_compile+0x1d5c> */
/* @0x26acc8 ldr r3, [sp, #0x48] */
/* @0x26accc ldr r4, [sp, #0x2c] */
/* @0x26acd0 cmp r4, #127 */
/* @0x26acd4 movls r3, #0 */
/* @0x26acd8 andhi r3, r3, #1 */
/* @0x26acdc cmp r3, #0 */
/* @0x26ace0 beq 0x26ca60 <pcre_compile+0x3ad8> */
/* @0x26ace4 mvn r3, #0 */
/* @0x26ace8 ldr r4, [sp, #0x34] */
/* @0x26acec ldr r6, [sp, #0x2c] */
/* @0x26acf0 cmp r4, r6 */
/* @0x26acf4 cmpne r4, r3 */
/* @0x26acf8 movne r3, #0 */
/* @0x26acfc moveq r3, #1 */
/* @0x26ad00 cmp r9, #58 */
/* @0x26ad04 eorgt r3, r3, #1 */
/* @0x26ad08 cmp r3, #0 */
/* @0x26ad0c addeq r5, r5, #1 */
/* @0x26ad10 moveq r8, r2 */
/* @0x26ad14 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26ad18 cmp r1, #0 */
/* @0x26ad1c ble 0x26ad38 <pcre_compile+0x1db0> */
/* @0x26ad20 cmp r9, #43 */
/* @0x26ad24 cmpne r9, #69 */
/* @0x26ad28 subeq r2, r2, #1 */
/* @0x26ad2c ldreq r9, [sp, #0x24] */
/* @0x26ad30 subeq r9, r9, #12 */
/* @0x26ad34 streq r9, [sp, #0x24] */
/* @0x26ad38 ldr r4, [sp, #0x30] */
/* @0x26ad3c add r1, r1, #1 */
/* @0x26ad40 add r3, r11, #1 */
/* @0x26ad44 cmp r11, r4 */
/* @0x26ad48 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26ad4c str r7, [r12] */
/* @0x26ad50 add r5, r5, #1 */
/* @0x26ad54 str r1, [r12, #0x4] */
/* @0x26ad58 mov r11, r3 */
/* @0x26ad5c add r12, r12, #12 */
/* @0x26ad60 mov r8, r2 */
/* @0x26ad64 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26ad68 mov r1, #0 */
/* @0x26ad6c b 0x269ff8 <pcre_compile+0x1070> */
/* @0x26ad70 ldr r9, [sp, #0x40] */
/* @0x26ad74 cmp r9, #0 */
/* @0x26ad78 addeq r5, r5, #1 */
/* @0x26ad7c beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26ad80 ldr r4, [sp, #0x2c] */
/* @0x26ad84 ldr r2, [sp, #0x48] */
/* @0x26ad88 ldr r9, [sp, #0x34] */
/* @0x26ad8c cmp r4, #127 */
/* @0x26ad90 movls r2, #0 */
/* @0x26ad94 andhi r2, r2, #1 */
/* @0x26ad98 cmp r2, #0 */
/* @0x26ad9c ldreq r6, [sp, #0x88] */
/* @0x26ada0 ldrne r2, [sp, #0x2c] */
/* @0x26ada4 ldrbeq r2, [r6, r4] */
/* @0x26ada8 ldr r4, [sp, #0x2c] */
/* @0x26adac cmp r9, r2 */
/* @0x26adb0 cmpne r9, r4 */
/* @0x26adb4 addeq r5, r5, #1 */
/* @0x26adb8 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26adbc ldr r6, [sp, #0x30] */
/* @0x26adc0 add r2, r11, #1 */
/* @0x26adc4 cmp r11, r6 */
/* @0x26adc8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26adcc add r3, r7, r3 */
/* @0x26add0 add r5, r5, #1 */
/* @0x26add4 add r3, r3, #1 */
/* @0x26add8 mov r11, r2 */
/* @0x26addc str r3, [r12] */
/* @0x26ade0 mov r3, #0 */
/* @0x26ade4 add r12, r12, #12 */
/* @0x26ade8 str r3, [r12, #-0x8] */
/* @0x26adec b 0x269480 <pcre_compile+0x4f8> */
/* @0x26adf0 ldr r6, [sp, #0x34] */
/* @0x26adf4 ldr r9, [sp, #0x2c] */
/* @0x26adf8 ldr r4, [sp, #0x40] */
/* @0x26adfc cmp r6, r9 */
/* @0x26ae00 cmpne r4, #0 */
/* @0x26ae04 addle r5, r5, #1 */
/* @0x26ae08 ble 0x269480 <pcre_compile+0x4f8> */
/* @0x26ae0c ldr r6, [sp, #0x30] */
/* @0x26ae10 add r2, r11, #1 */
/* @0x26ae14 cmp r11, r6 */
/* @0x26ae18 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26ae1c add r3, r7, r3 */
/* @0x26ae20 add r5, r5, #1 */
/* @0x26ae24 add r3, r3, #1 */
/* @0x26ae28 mov r11, r2 */
/* @0x26ae2c str r3, [r12] */
/* @0x26ae30 mov r3, #0 */
/* @0x26ae34 add r12, r12, #12 */
/* @0x26ae38 str r3, [r12, #-0x8] */
/* @0x26ae3c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26ae40 ldr r4, [sp, #0x40] */
/* @0x26ae44 cmp r4, #0 */
/* @0x26ae48 addeq r5, r5, #1 */
/* @0x26ae4c beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26ae50 ldr r6, [sp, #0x48] */
/* @0x26ae54 cmp r6, #0 */
/* @0x26ae58 beq 0x26cd2c <pcre_compile+0x3da4> */
/* @0x26ae5c ldr r9, [sp, #0x34] */
/* @0x26ae60 ldr r4, [sp, #0x2c] */
/* @0x26ae64 cmp r9, r4 */
/* @0x26ae68 beq 0x26e4f4 <pcre_compile+0x556c> */
/* @0x26ae6c ldr r9, [sp, #0x34] */
/* @0x26ae70 ldr r6, [sp, #0x2c] */
/* @0x26ae74 cmp r9, #127 */
/* @0x26ae78 ldrls r4, [sp, #0x88] */
/* @0x26ae7c mvnhi r2, #0 */
/* @0x26ae80 ldrbls r2, [r4, r9] */
/* @0x26ae84 cmp r6, r2 */
/* @0x26ae88 addne r5, r5, #1 */
/* @0x26ae8c bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26ae90 ldr r9, [sp, #0x30] */
/* @0x26ae94 add r2, r11, #1 */
/* @0x26ae98 cmp r11, r9 */
/* @0x26ae9c bge 0x2691dc <pcre_compile+0x254> */
/* @0x26aea0 add r3, r7, r3 */
/* @0x26aea4 add r5, r5, #1 */
/* @0x26aea8 add r3, r3, #1 */
/* @0x26aeac mov r11, r2 */
/* @0x26aeb0 str r3, [r12] */
/* @0x26aeb4 mov r3, #0 */
/* @0x26aeb8 add r12, r12, #12 */
/* @0x26aebc str r3, [r12, #-0x8] */
/* @0x26aec0 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26aec4 ldr r9, [sp, #0x34] */
/* @0x26aec8 ldr r4, [sp, #0x2c] */
/* @0x26aecc ldr r6, [sp, #0x40] */
/* @0x26aed0 subs r9, r9, r4 */
/* @0x26aed4 rsbs r2, r9, #0 */
/* @0x26aed8 adcs r2, r2, r9 */
/* @0x26aedc cmp r6, #0 */
/* @0x26aee0 movle r2, #0 */
/* @0x26aee4 cmp r2, #0 */
/* @0x26aee8 addeq r5, r5, #1 */
/* @0x26aeec beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26aef0 ldr r9, [sp, #0x30] */
/* @0x26aef4 add r2, r11, #1 */
/* @0x26aef8 cmp r11, r9 */
/* @0x26aefc bge 0x2691dc <pcre_compile+0x254> */
/* @0x26af00 add r3, r7, r3 */
/* @0x26af04 add r5, r5, #1 */
/* @0x26af08 add r3, r3, #1 */
/* @0x26af0c mov r11, r2 */
/* @0x26af10 str r3, [r12] */
/* @0x26af14 mov r3, #0 */
/* @0x26af18 add r12, r12, #12 */
/* @0x26af1c str r3, [r12, #-0x8] */
/* @0x26af20 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26af24 ldr r9, [sp, #0x38] */
/* @0x26af28 ldr r4, [sp, #0x54] */
/* @0x26af2c cmp r9, r4 */
/* @0x26af30 beq 0x26dc10 <pcre_compile+0x4c88> */
/* @0x26af34 ldr r4, [sp, #0x38] */
/* @0x26af38 ldr r6, [sp, #0x68] */
/* @0x26af3c cmp r4, r6 */
/* @0x26af40 addeq r5, r5, #1 */
/* @0x26af44 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26af48 ldr r9, [sp, #0x28] */
/* @0x26af4c ldr r1, [r9, #0x20] */
/* @0x26af50 cmp r1, #0 */
/* @0x26af54 bne 0x26c92c <pcre_compile+0x39a4> */
/* @0x26af58 ldr r9, [sp, #0x28] */
/* @0x26af5c ldr r4, [sp, #0x38] */
/* @0x26af60 ldr r3, [r9, #0x24] */
/* @0x26af64 ldr r2, [r9, #0x4] */
/* @0x26af68 add r2, r2, r3 */
/* @0x26af6c cmp r4, r2 */
/* @0x26af70 addlo r5, r5, #1 */
/* @0x26af74 blo 0x269480 <pcre_compile+0x4f8> */
/* @0x26af78 ldr r6, [sp, #0x38] */
/* @0x26af7c ldr r9, [sp, #0x28] */
/* @0x26af80 rsb r1, r3, r6 */
/* @0x26af84 ldrb r2, [r9, #0x28] */
/* @0x26af88 ldrb r1, [r1] */
/* @0x26af8c cmp r1, r2 */
/* @0x26af90 addne r5, r5, #1 */
/* @0x26af94 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26af98 cmp r3, #1 */
/* @0x26af9c beq 0x26afc0 <pcre_compile+0x2038> */
/* @0x26afa0 ldr r4, [sp, #0x28] */
/* @0x26afa4 rsb r3, r3, #1 */
/* @0x26afa8 ldr r6, [sp, #0x38] */
/* @0x26afac ldrb r2, [r4, #0x29] */
/* @0x26afb0 ldrb r3, [r6, r3] */
/* @0x26afb4 cmp r3, r2 */
/* @0x26afb8 addne r5, r5, #1 */
/* @0x26afbc bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26afc0 ldr r9, [sp, #0x30] */
/* @0x26afc4 add r3, r8, #1 */
/* @0x26afc8 cmp r8, r9 */
/* @0x26afcc bge 0x2691dc <pcre_compile+0x254> */
/* @0x26afd0 ldr r9, [sp, #0x24] */
/* @0x26afd4 add r7, r7, #1 */
/* @0x26afd8 mov r8, r3 */
/* @0x26afdc add r5, r5, #1 */
/* @0x26afe0 mov r3, #0 */
/* @0x26afe4 add r9, r9, #12 */
/* @0x26afe8 str r7, [r9, #-0xc] */
/* @0x26afec str r3, [r9, #-0x8] */
/* @0x26aff0 str r9, [sp, #0x24] */
/* @0x26aff4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26aff8 ldr r4, [sp, #0x38] */
/* @0x26affc ldr r6, [sp, #0x54] */
/* @0x26b000 cmp r4, r6 */
/* @0x26b004 addne r5, r5, #1 */
/* @0x26b008 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26b00c ldr r9, [sp, #0x28] */
/* @0x26b010 ldr r3, [r9, #0x18] */
/* @0x26b014 ands r3, r3, #128 */
/* @0x26b018 addne r5, r5, #1 */
/* @0x26b01c bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26b020 ldr r4, [sp, #0x30] */
/* @0x26b024 cmp r8, r4 */
/* @0x26b028 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b02c ldr r6, [sp, #0x24] */
/* @0x26b030 add r7, r7, #1 */
/* @0x26b034 add r8, r8, #1 */
/* @0x26b038 add r5, r5, #1 */
/* @0x26b03c add r6, r6, #12 */
/* @0x26b040 str r3, [r6, #-0x8] */
/* @0x26b044 str r7, [r6, #-0xc] */
/* @0x26b048 str r6, [sp, #0x24] */
/* @0x26b04c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b050 sub r9, r9, #13 */
/* @0x26b054 mov r1, #1 */
/* @0x26b058 b 0x26a174 <pcre_compile+0x11ec> */
/* @0x26b05c sub r9, r9, #13 */
/* @0x26b060 mov r4, #1 */
/* @0x26b064 b 0x26ac70 <pcre_compile+0x1ce8> */
/* @0x26b068 mov r0, #1 */
/* @0x26b06c sub r9, r9, #13 */
/* @0x26b070 str r0, [sp, #0x7c] */
/* @0x26b074 b 0x26a0a4 <pcre_compile+0x111c> */
/* @0x26b078 ldr r9, [sp, #0x30] */
/* @0x26b07c add r1, r8, #1 */
/* @0x26b080 cmp r8, r9 */
/* @0x26b084 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b088 ldr r6, [sp, #0x24] */
/* @0x26b08c mov r3, #0 */
/* @0x26b090 add r7, r7, #1 */
/* @0x26b094 str r3, [r6, #0x4] */
/* @0x26b098 str r7, [r6] */
/* @0x26b09c ldrb r2, [r4, #0x2] */
/* @0x26b0a0 ldrb r3, [r4, #0x3] */
/* @0x26b0a4 orr r2, r3, r2, lsl #8 */
/* @0x26b0a8 add r2, r2, #1 */
/* @0x26b0ac add r3, r4, r2 */
/* @0x26b0b0 ldrb r2, [r4, r2] */
/* @0x26b0b4 cmp r2, #119 */
/* @0x26b0b8 bne 0x26b0d4 <pcre_compile+0x214c> */
/* @0x26b0bc ldrb r0, [r3, #0x1] */
/* @0x26b0c0 ldrb r2, [r3, #0x2] */
/* @0x26b0c4 orr r2, r2, r0, lsl #8 */
/* @0x26b0c8 ldrb r2, [r3, r2]! */
/* @0x26b0cc cmp r2, #119 */
/* @0x26b0d0 beq 0x26b0bc <pcre_compile+0x2134> */
/* @0x26b0d4 ldr r7, [sp, #0x30] */
/* @0x26b0d8 add r8, r8, #2 */
/* @0x26b0dc cmp r7, r1 */
/* @0x26b0e0 ble 0x2691dc <pcre_compile+0x254> */
/* @0x26b0e4 ldr r4, [sp, #0x24] */
/* @0x26b0e8 add r5, r5, #1 */
/* @0x26b0ec ldr r9, [sp, #0x3c] */
/* @0x26b0f0 add r4, r4, #24 */
/* @0x26b0f4 rsb r3, r9, r3 */
/* @0x26b0f8 add r3, r3, #3 */
/* @0x26b0fc str r3, [r4, #-0xc] */
/* @0x26b100 mov r3, #0 */
/* @0x26b104 str r3, [r4, #-0x8] */
/* @0x26b108 str r4, [sp, #0x24] */
/* @0x26b10c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b110 ldrb r9, [r4, #0x3] */
/* @0x26b114 ldrb r1, [r4, #0x1] */
/* @0x26b118 ldrb r2, [r4, #0x2] */
/* @0x26b11c cmp r9, #118 */
/* @0x26b120 str r1, [sp, #0x2c] */
/* @0x26b124 str r2, [sp, #0x60] */
/* @0x26b128 beq 0x26d170 <pcre_compile+0x41e8> */
/* @0x26b12c sub r3, r9, #141 */
/* @0x26b130 cmp r9, #144 */
/* @0x26b134 cmpne r3, #1 */
/* @0x26b138 movhi r3, #0 */
/* @0x26b13c movls r3, #1 */
/* @0x26b140 bls 0x26e310 <pcre_compile+0x5388> */
/* @0x26b144 ldr r1, [sp, #0x2c] */
/* @0x26b148 cmp r9, #145 */
/* @0x26b14c cmpne r9, #157 */
/* @0x26b150 ldr r6, [sp, #0x60] */
/* @0x26b154 movne r2, #0 */
/* @0x26b158 moveq r2, #1 */
/* @0x26b15c orr r6, r6, r1, lsl #8 */
/* @0x26b160 str r6, [sp, #0x60] */
/* @0x26b164 bne 0x26c84c <pcre_compile+0x38c4> */
/* @0x26b168 ldr r4, [sp, #0x30] */
/* @0x26b16c cmp r8, r4 */
/* @0x26b170 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b174 ldr r9, [sp, #0x24] */
/* @0x26b178 add r8, r8, #1 */
/* @0x26b17c ldr r6, [sp, #0x60] */
/* @0x26b180 add r9, r9, #12 */
/* @0x26b184 add r7, r7, r6 */
/* @0x26b188 str r3, [r9, #-0x8] */
/* @0x26b18c add r3, r7, #3 */
/* @0x26b190 str r3, [r9, #-0xc] */
/* @0x26b194 str r9, [sp, #0x24] */
/* @0x26b198 add r5, r5, #1 */
/* @0x26b19c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b1a0 mov r0, #0 */
/* @0x26b1a4 ldr r6, [sp, #0x30] */
/* @0x26b1a8 add r2, r8, #1 */
/* @0x26b1ac cmp r8, r6 */
/* @0x26b1b0 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b1b4 ldr r4, [sp, #0x40] */
/* @0x26b1b8 add r3, r7, #2 */
/* @0x26b1bc ldr r6, [sp, #0x24] */
/* @0x26b1c0 cmp r4, #0 */
/* @0x26b1c4 addeq r5, r5, #1 */
/* @0x26b1c8 str r3, [r6] */
/* @0x26b1cc moveq r8, r2 */
/* @0x26b1d0 mov r3, #0 */
/* @0x26b1d4 str r3, [r6, #0x4] */
/* @0x26b1d8 add r3, r6, #12 */
/* @0x26b1dc streq r3, [sp, #0x24] */
/* @0x26b1e0 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26b1e4 ldr r4, [sp, #0x34] */
/* @0x26b1e8 movw r1, #0x180e */
/* @0x26b1ec cmp r4, r1 */
/* @0x26b1f0 beq 0x26b218 <pcre_compile+0x2290> */
/* @0x26b1f4 bhi 0x26c66c <pcre_compile+0x36e4> */
/* @0x26b1f8 cmp r4, #32 */
/* @0x26b1fc beq 0x26b218 <pcre_compile+0x2290> */
/* @0x26b200 bls 0x26cc88 <pcre_compile+0x3d00> */
/* @0x26b204 ldr r6, [sp, #0x34] */
/* @0x26b208 cmp r6, #160 */
/* @0x26b20c beq 0x26b218 <pcre_compile+0x2290> */
/* @0x26b210 cmp r6, #5760 */
/* @0x26b214 bne 0x26cb80 <pcre_compile+0x3bf8> */
/* @0x26b218 mov r1, #1 */
/* @0x26b21c ldr r6, [sp, #0x2c] */
/* @0x26b220 subs r6, r6, #19 */
/* @0x26b224 rsbs r4, r6, #0 */
/* @0x26b228 adcs r4, r4, r6 */
/* @0x26b22c cmp r4, r1 */
/* @0x26b230 beq 0x26d0b4 <pcre_compile+0x412c> */
/* @0x26b234 add r5, r5, #1 */
/* @0x26b238 mov r8, r2 */
/* @0x26b23c str r3, [sp, #0x24] */
/* @0x26b240 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b244 movw r3, #0x1b1 */
/* @0x26b248 cmp r9, r3 */
/* @0x26b24c beq 0x26d4d4 <pcre_compile+0x454c> */
/* @0x26b250 ldr r0, [sp, #0x30] */
/* @0x26b254 add r3, r8, #1 */
/* @0x26b258 cmp r8, r0 */
/* @0x26b25c bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b260 ldr r1, [sp, #0x24] */
/* @0x26b264 add r2, r7, #4 */
/* @0x26b268 add r1, r1, #12 */
/* @0x26b26c str r2, [r1, #-0xc] */
/* @0x26b270 mov r2, #0 */
/* @0x26b274 str r2, [r1, #-0x8] */
/* @0x26b278 str r1, [sp, #0x24] */
/* @0x26b27c ldr r2, [sp, #0x40] */
/* @0x26b280 cmp r2, #0 */
/* @0x26b284 ldr r2, [r6, #0x4] */
/* @0x26b288 addeq r5, r5, #1 */
/* @0x26b28c moveq r8, r3 */
/* @0x26b290 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26b294 ldr r6, [sp, #0x34] */
/* @0x26b298 cmp r6, #13 */
/* @0x26b29c beq 0x26d51c <pcre_compile+0x4594> */
/* @0x26b2a0 bhi 0x26cc48 <pcre_compile+0x3cc0> */
/* @0x26b2a4 cmp r6, #10 */
/* @0x26b2a8 bne 0x26d50c <pcre_compile+0x4584> */
/* @0x26b2ac mov r6, #0 */
/* @0x26b2b0 movw r1, #0x1b5 */
/* @0x26b2b4 cmp r9, r1 */
/* @0x26b2b8 ldrb r0, [r4, #0x1] */
/* @0x26b2bc add r2, r2, #1 */
/* @0x26b2c0 ldreq r9, [sp, #0x24] */
/* @0x26b2c4 subeq r3, r3, #1 */
/* @0x26b2c8 ldrb r1, [r4, #0x2] */
/* @0x26b2cc subeq r9, r9, #12 */
/* @0x26b2d0 orr r1, r1, r0, lsl #8 */
/* @0x26b2d4 streq r9, [sp, #0x24] */
/* @0x26b2d8 cmp r2, r1 */
/* @0x26b2dc blt 0x26d4dc <pcre_compile+0x4554> */
/* @0x26b2e0 ldr r4, [sp, #0x30] */
/* @0x26b2e4 cmp r11, r4 */
/* @0x26b2e8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b2ec movw r2, #0xfffc */
/* @0x26b2f0 movt r2, #0xffff */
/* @0x26b2f4 str r6, [r12, #0x8] */
/* @0x26b2f8 mov r8, r3 */
/* @0x26b2fc rsb r2, r7, r2 */
/* @0x26b300 mov r3, #0 */
/* @0x26b304 add r11, r11, #1 */
/* @0x26b308 stm r12, {r2, r3} */
/* @0x26b30c add r5, r5, #1 */
/* @0x26b310 add r12, r12, #12 */
/* @0x26b314 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b318 mov r4, #2 */
/* @0x26b31c ldr r6, [sp, #0x30] */
/* @0x26b320 add r1, r8, #1 */
/* @0x26b324 cmp r8, r6 */
/* @0x26b328 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b32c ldr r6, [sp, #0x40] */
/* @0x26b330 add r2, r7, #2 */
/* @0x26b334 mov r3, #0 */
/* @0x26b338 cmp r6, #0 */
/* @0x26b33c ldr r6, [sp, #0x24] */
/* @0x26b340 addeq r5, r5, #1 */
/* @0x26b344 moveq r8, r1 */
/* @0x26b348 stm r6, {r2, r3} */
/* @0x26b34c add r2, r6, #12 */
/* @0x26b350 streq r2, [sp, #0x24] */
/* @0x26b354 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26b358 ldr r6, [sp, #0x34] */
/* @0x26b35c cmp r6, #13 */
/* @0x26b360 beq 0x26d144 <pcre_compile+0x41bc> */
/* @0x26b364 bhi 0x26d114 <pcre_compile+0x418c> */
/* @0x26b368 cmp r6, #10 */
/* @0x26b36c bne 0x26cd08 <pcre_compile+0x3d80> */
/* @0x26b370 movw r0, #0x1b2 */
/* @0x26b374 cmp r9, r0 */
/* @0x26b378 cmpne r9, #436 */
/* @0x26b37c ldr r6, [sp, #0x30] */
/* @0x26b380 add r0, r11, #1 */
/* @0x26b384 movne r9, #0 */
/* @0x26b388 moveq r9, #1 */
/* @0x26b38c cmp r9, #0 */
/* @0x26b390 ldr r9, [sp, #0x24] */
/* @0x26b394 moveq r8, r1 */
/* @0x26b398 moveq r9, r2 */
/* @0x26b39c cmp r11, r6 */
/* @0x26b3a0 str r9, [sp, #0x24] */
/* @0x26b3a4 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b3a8 add r2, r7, r4 */
/* @0x26b3ac str r3, [r12, #0x8] */
/* @0x26b3b0 add r5, r5, #1 */
/* @0x26b3b4 rsb r3, r2, #0 */
/* @0x26b3b8 mov r11, r0 */
/* @0x26b3bc str r3, [r12] */
/* @0x26b3c0 mov r3, #0 */
/* @0x26b3c4 add r12, r12, #12 */
/* @0x26b3c8 str r3, [r12, #-0x8] */
/* @0x26b3cc b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b3d0 ldr r1, [r6, #0x4] */
/* @0x26b3d4 cmp r1, #0 */
/* @0x26b3d8 ble 0x26d2a4 <pcre_compile+0x431c> */
/* @0x26b3dc ldr r4, [sp, #0x30] */
/* @0x26b3e0 add r0, r8, #1 */
/* @0x26b3e4 cmp r8, r4 */
/* @0x26b3e8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b3ec ldr r6, [sp, #0x24] */
/* @0x26b3f0 add r3, r7, #2 */
/* @0x26b3f4 add r6, r6, #12 */
/* @0x26b3f8 str r3, [r6, #-0xc] */
/* @0x26b3fc mov r3, #0 */
/* @0x26b400 str r3, [r6, #-0x8] */
/* @0x26b404 str r6, [sp, #0x24] */
/* @0x26b408 ldr r4, [sp, #0x40] */
/* @0x26b40c cmp r4, #0 */
/* @0x26b410 addeq r5, r5, #1 */
/* @0x26b414 moveq r8, r0 */
/* @0x26b418 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26b41c ldr r6, [sp, #0x34] */
/* @0x26b420 cmp r6, #13 */
/* @0x26b424 beq 0x26dea8 <pcre_compile+0x4f20> */
/* @0x26b428 bhi 0x26cc94 <pcre_compile+0x3d0c> */
/* @0x26b42c cmp r6, #10 */
/* @0x26b430 bne 0x26de54 <pcre_compile+0x4ecc> */
/* @0x26b434 mov r3, #0 */
/* @0x26b438 movw r2, #0x1b3 */
/* @0x26b43c subs r4, r9, r2 */
/* @0x26b440 rsbs r9, r4, #0 */
/* @0x26b444 add r2, r11, #1 */
/* @0x26b448 adcs r9, r9, r4 */
/* @0x26b44c cmp r1, #0 */
/* @0x26b450 ldr r4, [sp, #0x30] */
/* @0x26b454 add r1, r1, #1 */
/* @0x26b458 movle r9, #0 */
/* @0x26b45c cmp r9, #0 */
/* @0x26b460 subne r0, r0, #1 */
/* @0x26b464 ldrne r9, [sp, #0x24] */
/* @0x26b468 subne r9, r9, #12 */
/* @0x26b46c strne r9, [sp, #0x24] */
/* @0x26b470 cmp r11, r4 */
/* @0x26b474 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b478 rsb r7, r7, #0 */
/* @0x26b47c str r1, [r12, #0x4] */
/* @0x26b480 str r7, [r12] */
/* @0x26b484 add r5, r5, #1 */
/* @0x26b488 str r3, [r12, #0x8] */
/* @0x26b48c mov r11, r2 */
/* @0x26b490 add r12, r12, #12 */
/* @0x26b494 mov r8, r0 */
/* @0x26b498 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b49c mov r4, #0 */
/* @0x26b4a0 b 0x26b31c <pcre_compile+0x2394> */
/* @0x26b4a4 add r5, r5, #1 */
/* @0x26b4a8 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b4ac ldrb r2, [r4, #0x2] */
/* @0x26b4b0 ldrb r3, [r4, #0x3] */
/* @0x26b4b4 orr r2, r3, r2, lsl #8 */
/* @0x26b4b8 add r2, r2, #1 */
/* @0x26b4bc add r3, r4, r2 */
/* @0x26b4c0 ldrb r2, [r4, r2] */
/* @0x26b4c4 cmp r2, #119 */
/* @0x26b4c8 bne 0x26b4e4 <pcre_compile+0x255c> */
/* @0x26b4cc ldrb r1, [r3, #0x1] */
/* @0x26b4d0 ldrb r2, [r3, #0x2] */
/* @0x26b4d4 orr r2, r2, r1, lsl #8 */
/* @0x26b4d8 ldrb r2, [r3, r2]! */
/* @0x26b4dc cmp r2, #119 */
/* @0x26b4e0 beq 0x26b4cc <pcre_compile+0x2544> */
/* @0x26b4e4 ldr r6, [sp, #0x30] */
/* @0x26b4e8 add r2, r8, #1 */
/* @0x26b4ec cmp r8, r6 */
/* @0x26b4f0 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b4f4 ldr r9, [sp, #0x24] */
/* @0x26b4f8 add r5, r5, #1 */
/* @0x26b4fc ldr r7, [sp, #0x3c] */
/* @0x26b500 mov r8, r2 */
/* @0x26b504 add r9, r9, #12 */
/* @0x26b508 rsb r3, r7, r3 */
/* @0x26b50c add r3, r3, #3 */
/* @0x26b510 str r3, [r9, #-0xc] */
/* @0x26b514 mov r3, #0 */
/* @0x26b518 str r3, [r9, #-0x8] */
/* @0x26b51c str r9, [sp, #0x24] */
/* @0x26b520 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b524 ldr r9, [sp, #0x80] */
/* @0x26b528 add r5, r5, #1 */
/* @0x26b52c add r9, r9, #1 */
/* @0x26b530 str r9, [sp, #0x80] */
/* @0x26b534 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b538 ldr r3, [pc, #0xec4] —— 全局函数指针钩子：GOT → 全局 → 首字 */
/* @0x26b53c ldr r3, [pc, r3] */
/* @0x26b540 ldr r3, [r3] */
/* @0x26b544 cmp r3, #0 —— 钩子为空则跳过整个调用（0x26b548 beq） */
/* @0x26b548 beq 0x26b60c <pcre_compile+0x2684> */
/* @0x26b54c add r6, sp, #8192 */
/* @0x26b550 mov r2, #1 */
/* @0x26b554 ldr r9, [sp, #0x68] */
/* @0x26b558 str r2, [r6, #-0xf88] */
/* @0x26b55c ldr r6, [sp, #0x54] */
/* @0x26b560 ldrb r0, [r4, #0x1] */
/* @0x26b564 rsb r1, r6, r9 */
/* @0x26b568 add r9, sp, #8192 */
/* @0x26b56c ldr lr, [r9, #0x40] */
/* @0x26b570 str lr, [r9, #-0xf80] */
/* @0x26b574 ldr r9, [sp, #0x5c] */
/* @0x26b578 rsb lr, r6, r9 */
/* @0x26b57c add r9, sp, #8192 */
/* @0x26b580 str r6, [r9, #-0xf7c] */
/* @0x26b584 str r0, [r9, #-0xf84] */
/* @0x26b588 ldr r9, [sp, #0x38] */
/* @0x26b58c rsb r0, r6, r9 */
/* @0x26b590 add r6, sp, #8192 */
/* @0x26b594 add r9, sp, #8192 */
/* @0x26b598 str r1, [r6, #-0xf78] */
/* @0x26b59c mvn r1, #0 */
/* @0x26b5a0 str lr, [r6, #-0xf74] */
/* @0x26b5a4 mov lr, #0 */
/* @0x26b5a8 str r0, [r6, #-0xf70] */
/* @0x26b5ac ldrb r6, [r4, #0x2] */
/* @0x26b5b0 ldrb r0, [r4, #0x3] */
/* @0x26b5b4 orr r0, r0, r6, lsl #8 */
/* @0x26b5b8 str r0, [r9, #-0xf60] */
/* @0x26b5bc ldr r9, [sp, #0x28] */
/* @0x26b5c0 ldrb r6, [r4, #0x4] */
/* @0x26b5c4 ldrb r0, [r4, #0x5] */
/* @0x26b5c8 ldr r4, [r9, #0x2c] */
/* @0x26b5cc add r9, sp, #8192 */
/* @0x26b5d0 str r2, [r9, #-0xf6c] */
/* @0x26b5d4 orr r2, r0, r6, lsl #8 */
/* @0x26b5d8 add r0, sp, #4160 */
/* @0x26b5dc str r1, [r9, #-0xf68] */
/* @0x26b5e0 str r2, [r9, #-0xf5c] */
/* @0x26b5e4 add r0, r0, #56 */
/* @0x26b5e8 str r4, [r9, #-0xf64] */
/* @0x26b5ec str lr, [r9, #-0xf58] */
/* @0x26b5f0 str r12, [sp, #0x1c] */
/* @0x26b5f4 blx r3 —— blx r3 钩子调用 #1（r0 = sp+0x1078 上下文块） */
/* @0x26b5f8 ldr r12, [sp, #0x1c] */
/* @0x26b5fc cmp r0, #0 */
/* @0x26b600 blt 0x2691e0 <pcre_compile+0x258> */
/* @0x26b604 addne r5, r5, #1 */
/* @0x26b608 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26b60c ldr r4, [sp, #0x30] */
/* @0x26b610 add r3, r8, #1 */
/* @0x26b614 cmp r8, r4 */
/* @0x26b618 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b61c ldr r4, [sp, #0x24] */
/* @0x26b620 add r7, r7, #6 */
/* @0x26b624 mov r2, #0 */
/* @0x26b628 add r5, r5, #1 */
/* @0x26b62c add r4, r4, #12 */
/* @0x26b630 mov r8, r3 */
/* @0x26b634 str r7, [r4, #-0xc] */
/* @0x26b638 str r2, [r4, #-0x8] */
/* @0x26b63c str r4, [sp, #0x24] */
/* @0x26b640 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b644 ldrb r2, [r4, #0x2] */
/* @0x26b648 ldrb r1, [r4, #0x1] */
/* @0x26b64c ldr r4, [sp, #0x28] */
/* @0x26b650 ldr r6, [sp, #0x3c] */
/* @0x26b654 orr r1, r2, r1, lsl #8 */
/* @0x26b658 ldr r9, [sp, #0x28] */
/* @0x26b65c ldr r3, [r4] */
/* @0x26b660 add r1, r6, r1 */
/* @0x26b664 cmp r3, r1 */
/* @0x26b668 ldr r9, [r9, #0x30] */
/* @0x26b66c ldrbne r2, [r1, #0x3] */
/* @0x26b670 moveq r3, #0 */
/* @0x26b674 ldrbne r3, [r1, #0x4] */
/* @0x26b678 str r9, [sp, #0x60] */
/* @0x26b67c orrne r3, r3, r2, lsl #8 */
/* @0x26b680 cmp r9, #0 */
/* @0x26b684 beq 0x26c418 <pcre_compile+0x3490> */
/* @0x26b688 mov r2, r9 */
/* @0x26b68c ldr r4, [sp, #0x38] */
/* @0x26b690 b 0x26b6a0 <pcre_compile+0x2718> */
/* @0x26b694 ldr r2, [r2] */
/* @0x26b698 cmp r2, #0 */
/* @0x26b69c beq 0x26c414 <pcre_compile+0x348c> */
/* @0x26b6a0 ldr r0, [r2, #0x4] */
/* @0x26b6a4 cmp r3, r0 */
/* @0x26b6a8 bne 0x26b694 <pcre_compile+0x270c> */
/* @0x26b6ac ldr r0, [r2, #0x8] */
/* @0x26b6b0 cmp r0, r4 */
/* @0x26b6b4 bne 0x26b694 <pcre_compile+0x270c> */
/* @0x26b6b8 mvn r0, #25 */
/* @0x26b6bc b 0x2691e0 <pcre_compile+0x258> */
/* @0x26b6c0 ldr r0, [sp, #0x30] */
/* @0x26b6c4 add r1, r8, #1 */
/* @0x26b6c8 str r1, [sp, #0x60] */
/* @0x26b6cc cmp r8, r0 */
/* @0x26b6d0 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b6d4 ldr r2, [sp, #0x40] */
/* @0x26b6d8 add r0, r7, #4 */
/* @0x26b6dc ldr r1, [sp, #0x24] */
/* @0x26b6e0 mov r3, #0 */
/* @0x26b6e4 cmp r2, #0 */
/* @0x26b6e8 str r0, [sp, #0xb0] */
/* @0x26b6ec add r2, r1, #12 */
/* @0x26b6f0 str r2, [sp, #0x7c] */
/* @0x26b6f4 stm r1, {r0, r3} */
/* @0x26b6f8 ldr r6, [r6, #0x4] */
/* @0x26b6fc beq 0x26d2ac <pcre_compile+0x4324> */
/* @0x26b700 ldr r3, [sp, #0x2c] */
/* @0x26b704 cmp r3, #12 */
/* @0x26b708 beq 0x26da14 <pcre_compile+0x4a8c> */
/* @0x26b70c ldr r0, [sp, #0x2c] */
/* @0x26b710 ldr r1, [sp, #0x34] */
/* @0x26b714 cmp r0, #7 */
/* @0x26b718 cmpne r1, #255 */
/* @0x26b71c bhi 0x26cb0c <pcre_compile+0x3b84> */
/* @0x26b720 ldr r0, [sp, #0x34] */
/* @0x26b724 cmp r0, #255 */
/* @0x26b728 bhi 0x26d5e0 <pcre_compile+0x4658> */
/* @0x26b72c ldr r0, [sp, #0x2c] */
/* @0x26b730 cmp r0, #12 */
/* @0x26b734 beq 0x26d584 <pcre_compile+0x45fc> */
/* @0x26b738 ldr r0, [sp, #0x9c] */
/* @0x26b73c ldr r1, [sp, #0x2c] */
/* @0x26b740 add r2, r0, r1 */
/* @0x26b744 ldr r1, [sp, #0x78] */
/* @0x26b748 ldr r0, [sp, #0x34] */
/* @0x26b74c ldrb r3, [r1, r0] */
/* @0x26b750 ldrb r1, [r2, #-0xc44] */
/* @0x26b754 ldrb r2, [r2, #-0xc34] */
/* @0x26b758 and r3, r1, r3 */
/* @0x26b75c cmp r2, r3 */
/* @0x26b760 beq 0x26d570 <pcre_compile+0x45e8> */
/* @0x26b764 cmp r9, #97 */
/* @0x26b768 ldr r9, [sp, #0x60] */
/* @0x26b76c ldrb r2, [r4, #0x1] */
/* @0x26b770 add r6, r6, #1 */
/* @0x26b774 ldrb r3, [r4, #0x2] */
/* @0x26b778 movne r8, r9 */
/* @0x26b77c ldr r4, [sp, #0x24] */
/* @0x26b780 ldr r9, [sp, #0x7c] */
/* @0x26b784 orr r3, r3, r2, lsl #8 */
/* @0x26b788 movne r4, r9 */
/* @0x26b78c cmp r6, r3 */
/* @0x26b790 str r4, [sp, #0x24] */
/* @0x26b794 blt 0x26d548 <pcre_compile+0x45c0> */
/* @0x26b798 ldr r6, [sp, #0x30] */
/* @0x26b79c add r3, r11, #1 */
/* @0x26b7a0 cmp r11, r6 */
/* @0x26b7a4 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b7a8 ldr r7, [sp, #0xb0] */
/* @0x26b7ac mov r11, r3 */
/* @0x26b7b0 add r5, r5, #1 */
/* @0x26b7b4 mov r3, #0 */
/* @0x26b7b8 add r12, r12, #12 */
/* @0x26b7bc str r3, [r12, #-0x8] */
/* @0x26b7c0 str r7, [r12, #-0xc] */
/* @0x26b7c4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b7c8 ldr r4, [sp, #0x30] */
/* @0x26b7cc cmp r8, r4 */
/* @0x26b7d0 add r4, r8, #1 */
/* @0x26b7d4 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b7d8 ldr r6, [sp, #0x40] */
/* @0x26b7dc add r7, r7, #2 */
/* @0x26b7e0 mov r3, #0 */
/* @0x26b7e4 cmp r6, #0 */
/* @0x26b7e8 ldr r6, [sp, #0x24] */
/* @0x26b7ec addeq r5, r5, #1 */
/* @0x26b7f0 moveq r8, r4 */
/* @0x26b7f4 str r7, [r6] */
/* @0x26b7f8 mov r0, r6 */
/* @0x26b7fc str r3, [r6, #0x4] */
/* @0x26b800 add r6, r6, #12 */
/* @0x26b804 streq r6, [sp, #0x24] */
/* @0x26b808 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26b80c ldr r1, [sp, #0x2c] */
/* @0x26b810 cmp r1, #12 */
/* @0x26b814 beq 0x26d6b0 <pcre_compile+0x4728> */
/* @0x26b818 ldr r0, [sp, #0x2c] */
/* @0x26b81c ldr r1, [sp, #0x34] */
/* @0x26b820 cmp r0, #7 */
/* @0x26b824 cmpne r1, #255 */
/* @0x26b828 bhi 0x26caf0 <pcre_compile+0x3b68> */
/* @0x26b82c ldr r0, [sp, #0x34] */
/* @0x26b830 cmp r0, #255 */
/* @0x26b834 strhi r6, [sp, #0x24] */
/* @0x26b838 addhi r5, r5, #1 */
/* @0x26b83c movhi r8, r4 */
/* @0x26b840 bhi 0x269480 <pcre_compile+0x4f8> */
/* @0x26b844 ldr r1, [sp, #0x2c] */
/* @0x26b848 cmp r1, #12 */
/* @0x26b84c beq 0x26da80 <pcre_compile+0x4af8> */
/* @0x26b850 ldr r1, [sp, #0xa8] */
/* @0x26b854 ldr r3, [sp, #0x2c] */
/* @0x26b858 ldr r0, [sp, #0x34] */
/* @0x26b85c add r2, r1, r3 */
/* @0x26b860 ldr r1, [sp, #0x78] */
/* @0x26b864 ldrb r3, [r1, r0] */
/* @0x26b868 ldrb r1, [r2, #-0xc44] */
/* @0x26b86c ldrb r2, [r2, #-0xc34] */
/* @0x26b870 and r3, r1, r3 */
/* @0x26b874 cmp r2, r3 */
/* @0x26b878 streq r6, [sp, #0x24] */
/* @0x26b87c addeq r5, r5, #1 */
/* @0x26b880 moveq r8, r4 */
/* @0x26b884 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26b888 cmp r9, #96 */
/* @0x26b88c add r3, r11, #1 */
/* @0x26b890 movne r8, r4 */
/* @0x26b894 ldr r4, [sp, #0x24] */
/* @0x26b898 movne r4, r6 */
/* @0x26b89c ldr r6, [sp, #0x30] */
/* @0x26b8a0 str r4, [sp, #0x24] */
/* @0x26b8a4 cmp r11, r6 */
/* @0x26b8a8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b8ac str r7, [r12] */
/* @0x26b8b0 mov r11, r3 */
/* @0x26b8b4 add r5, r5, #1 */
/* @0x26b8b8 mov r3, #0 */
/* @0x26b8bc add r12, r12, #12 */
/* @0x26b8c0 str r3, [r12, #-0x8] */
/* @0x26b8c4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b8c8 ldr r4, [r6, #0x4] */
/* @0x26b8cc cmp r4, #0 */
/* @0x26b8d0 ble 0x26b904 <pcre_compile+0x297c> */
/* @0x26b8d4 ldr r6, [sp, #0x30] */
/* @0x26b8d8 add r3, r8, #1 */
/* @0x26b8dc cmp r8, r6 */
/* @0x26b8e0 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b8e4 ldr r6, [sp, #0x24] */
/* @0x26b8e8 mov r8, r3 */
/* @0x26b8ec add r2, r7, #2 */
/* @0x26b8f0 add r6, r6, #12 */
/* @0x26b8f4 str r2, [r6, #-0xc] */
/* @0x26b8f8 mov r2, #0 */
/* @0x26b8fc str r2, [r6, #-0x8] */
/* @0x26b900 str r6, [sp, #0x24] */
/* @0x26b904 ldr r6, [sp, #0x40] */
/* @0x26b908 cmp r6, #0 */
/* @0x26b90c addeq r5, r5, #1 */
/* @0x26b910 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26b914 ldr r6, [sp, #0x2c] */
/* @0x26b918 cmp r6, #12 */
/* @0x26b91c beq 0x26d840 <pcre_compile+0x48b8> */
/* @0x26b920 ldr r6, [sp, #0x2c] */
/* @0x26b924 ldr r0, [sp, #0x34] */
/* @0x26b928 cmp r6, #7 */
/* @0x26b92c cmpne r0, #255 */
/* @0x26b930 bhi 0x26cadc <pcre_compile+0x3b54> */
/* @0x26b934 ldr r6, [sp, #0x34] */
/* @0x26b938 cmp r6, #255 */
/* @0x26b93c addhi r5, r5, #1 */
/* @0x26b940 bhi 0x269480 <pcre_compile+0x4f8> */
/* @0x26b944 ldr r6, [sp, #0x2c] */
/* @0x26b948 cmp r6, #12 */
/* @0x26b94c beq 0x26d660 <pcre_compile+0x46d8> */
/* @0x26b950 ldr r6, [sp, #0x34] */
/* @0x26b954 ldr r0, [sp, #0x78] */
/* @0x26b958 ldr r2, [pc, #0xaa8] */
/* @0x26b95c ldrb r3, [r0, r6] */
/* @0x26b960 add r2, pc, r2 */
/* @0x26b964 ldr r6, [sp, #0x2c] */
/* @0x26b968 add r2, r2, r6 */
/* @0x26b96c ldrb r1, [r2, #-0xc44] */
/* @0x26b970 ldrb r2, [r2, #-0xc34] */
/* @0x26b974 and r3, r1, r3 */
/* @0x26b978 cmp r2, r3 */
/* @0x26b97c addeq r5, r5, #1 */
/* @0x26b980 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26b984 subs r3, r9, #95 */
/* @0x26b988 rsbs r9, r3, #0 */
/* @0x26b98c adcs r9, r9, r3 */
/* @0x26b990 cmp r4, #0 */
/* @0x26b994 movle r9, #0 */
/* @0x26b998 cmp r9, #0 */
/* @0x26b99c ldrne r9, [sp, #0x24] */
/* @0x26b9a0 subne r8, r8, #1 */
/* @0x26b9a4 subne r9, r9, #12 */
/* @0x26b9a8 strne r9, [sp, #0x24] */
/* @0x26b9ac ldr r6, [sp, #0x30] */
/* @0x26b9b0 add r4, r4, #1 */
/* @0x26b9b4 add r3, r11, #1 */
/* @0x26b9b8 cmp r11, r6 */
/* @0x26b9bc bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b9c0 str r7, [r12] */
/* @0x26b9c4 add r5, r5, #1 */
/* @0x26b9c8 str r4, [r12, #0x4] */
/* @0x26b9cc mov r11, r3 */
/* @0x26b9d0 add r12, r12, #12 */
/* @0x26b9d4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26b9d8 ldr r4, [sp, #0x30] */
/* @0x26b9dc cmp r8, r4 */
/* @0x26b9e0 add r4, r8, #1 */
/* @0x26b9e4 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26b9e8 ldr r6, [sp, #0x40] */
/* @0x26b9ec add r3, r7, #2 */
/* @0x26b9f0 cmp r6, #0 */
/* @0x26b9f4 ldr r6, [sp, #0x24] */
/* @0x26b9f8 addeq r5, r5, #1 */
/* @0x26b9fc moveq r8, r4 */
/* @0x26ba00 str r3, [r6] */
/* @0x26ba04 mov r0, r6 */
/* @0x26ba08 mov r3, #0 */
/* @0x26ba0c add r6, r6, #12 */
/* @0x26ba10 str r3, [r6, #-0x8] */
/* @0x26ba14 streq r6, [sp, #0x24] */
/* @0x26ba18 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26ba1c ldr r1, [sp, #0x2c] */
/* @0x26ba20 cmp r1, #12 */
/* @0x26ba24 beq 0x26d5f4 <pcre_compile+0x466c> */
/* @0x26ba28 ldr r0, [sp, #0x2c] */
/* @0x26ba2c ldr r1, [sp, #0x34] */
/* @0x26ba30 cmp r0, #7 */
/* @0x26ba34 cmpne r1, #255 */
/* @0x26ba38 bhi 0x26ca44 <pcre_compile+0x3abc> */
/* @0x26ba3c ldr r0, [sp, #0x34] */
/* @0x26ba40 cmp r0, #255 */
/* @0x26ba44 strhi r6, [sp, #0x24] */
/* @0x26ba48 addhi r5, r5, #1 */
/* @0x26ba4c movhi r8, r4 */
/* @0x26ba50 bhi 0x269480 <pcre_compile+0x4f8> */
/* @0x26ba54 ldr r1, [sp, #0x2c] */
/* @0x26ba58 cmp r1, #12 */
/* @0x26ba5c beq 0x26dd9c <pcre_compile+0x4e14> */
/* @0x26ba60 ldr r1, [sp, #0xa4] */
/* @0x26ba64 ldr r3, [sp, #0x2c] */
/* @0x26ba68 ldr r0, [sp, #0x34] */
/* @0x26ba6c add r2, r1, r3 */
/* @0x26ba70 ldr r1, [sp, #0x78] */
/* @0x26ba74 ldrb r3, [r1, r0] */
/* @0x26ba78 ldrb r1, [r2, #-0xc44] */
/* @0x26ba7c ldrb r2, [r2, #-0xc34] */
/* @0x26ba80 and r3, r1, r3 */
/* @0x26ba84 cmp r2, r3 */
/* @0x26ba88 streq r6, [sp, #0x24] */
/* @0x26ba8c addeq r5, r5, #1 */
/* @0x26ba90 moveq r8, r4 */
/* @0x26ba94 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26ba98 cmp r9, #94 */
/* @0x26ba9c add r3, r11, #1 */
/* @0x26baa0 movne r8, r4 */
/* @0x26baa4 ldr r4, [sp, #0x24] */
/* @0x26baa8 movne r4, r6 */
/* @0x26baac ldr r6, [sp, #0x30] */
/* @0x26bab0 str r4, [sp, #0x24] */
/* @0x26bab4 cmp r11, r6 */
/* @0x26bab8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26babc str r7, [r12] */
/* @0x26bac0 mov r11, r3 */
/* @0x26bac4 add r5, r5, #1 */
/* @0x26bac8 mov r3, #0 */
/* @0x26bacc add r12, r12, #12 */
/* @0x26bad0 str r3, [r12, #-0x8] */
/* @0x26bad4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26bad8 cmp r9, #112 */
/* @0x26badc beq 0x26d254 <pcre_compile+0x42cc> */
/* @0x26bae0 ldr r0, [sp, #0x40] */
/* @0x26bae4 add r3, r4, #33 */
/* @0x26bae8 str r3, [sp, #0x2c] */
/* @0x26baec cmp r0, #0 */
/* @0x26baf0 beq 0x26d24c <pcre_compile+0x42c4> */
/* @0x26baf4 ldr r0, [sp, #0x34] */
/* @0x26baf8 cmp r0, #255 */
/* @0x26bafc bhi 0x26cc38 <pcre_compile+0x3cb0> */
/* @0x26bb00 ldr r9, [sp, #0x90] */
/* @0x26bb04 ldrb r0, [r4, r9] */
/* @0x26bb08 ldr r4, [sp, #0x34] */
/* @0x26bb0c and r3, r4, #7 */
/* @0x26bb10 asr r0, r0, r3 */
/* @0x26bb14 and r0, r0, #1 */
/* @0x26bb18 ldr r4, [sp, #0x2c] */
/* @0x26bb1c ldr r9, [sp, #0x3c] */
/* @0x26bb20 ldrb r3, [r4] */
/* @0x26bb24 rsb r1, r9, r4 */
/* @0x26bb28 sub r3, r3, #98 —— sub r3,#98 后范围 0..11 */
/* @0x26bb2c cmp r3, #11 */
/* ──── S11 12 项小派发表：值 98..109（13 条） ──── */
/* @0x26bb30 addls pc, pc, r3, lsl #2 —— 跳转表 3：12 项（表项 0x26bb38..0x26bb64 是数据） */
/* @0x26bb34 b 0x26ded0 <pcre_compile+0x4f48> */
/* @0x26bb38 b 0x26cf38 <pcre_compile+0x3fb0> —— 表 3 首项（数据） */
/* @0x26bb3c b 0x26cf38 <pcre_compile+0x3fb0> */
/* @0x26bb40 b 0x26ceb8 <pcre_compile+0x3f30> */
/* @0x26bb44 b 0x26ceb8 <pcre_compile+0x3f30> */
/* @0x26bb48 b 0x26ce7c <pcre_compile+0x3ef4> */
/* @0x26bb4c b 0x26ce7c <pcre_compile+0x3ef4> */
/* @0x26bb50 b 0x26cdc4 <pcre_compile+0x3e3c> */
/* @0x26bb54 b 0x26cdc4 <pcre_compile+0x3e3c> */
/* @0x26bb58 b 0x26cf38 <pcre_compile+0x3fb0> */
/* @0x26bb5c b 0x26ceb8 <pcre_compile+0x3f30> */
/* @0x26bb60 b 0x26ce7c <pcre_compile+0x3ef4> */
/* ──── S12 case 体群 B：5 处自递归 / _pcre_xclass / memmove / 两处字面量池（2689 条） ──── */
/* @0x26bb64 b 0x26cdc4 <pcre_compile+0x3e3c> —— 表 3 之后：case 体群 B 起点 */
/* @0x26bb68 ldr r9, [sp, #0x40] */
/* @0x26bb6c ldr r6, [r6, #0x4] */
/* @0x26bb70 cmp r9, #0 */
/* @0x26bb74 addeq r5, r5, #1 */
/* @0x26bb78 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26bb7c ldr r9, [sp, #0x2c] */
/* @0x26bb80 cmp r9, #12 */
/* @0x26bb84 beq 0x26dd38 <pcre_compile+0x4db0> */
/* @0x26bb88 ldr r9, [sp, #0x2c] */
/* @0x26bb8c ldr r0, [sp, #0x34] */
/* @0x26bb90 cmp r9, #7 */
/* @0x26bb94 cmpne r0, #255 */
/* @0x26bb98 bhi 0x26cb2c <pcre_compile+0x3ba4> */
/* @0x26bb9c ldr r9, [sp, #0x34] */
/* @0x26bba0 cmp r9, #255 */
/* @0x26bba4 addhi r5, r5, #1 */
/* @0x26bba8 bhi 0x269480 <pcre_compile+0x4f8> */
/* @0x26bbac ldr r9, [sp, #0x2c] */
/* @0x26bbb0 cmp r9, #12 */
/* @0x26bbb4 beq 0x26d744 <pcre_compile+0x47bc> */
/* @0x26bbb8 ldr r9, [sp, #0xa0] */
/* @0x26bbbc ldr r0, [sp, #0x2c] */
/* @0x26bbc0 add r2, r9, r0 */
/* @0x26bbc4 ldr r0, [sp, #0x78] */
/* @0x26bbc8 ldr r9, [sp, #0x34] */
/* @0x26bbcc ldrb r1, [r2, #-0xc44] */
/* @0x26bbd0 ldrb r2, [r2, #-0xc34] */
/* @0x26bbd4 ldrb r3, [r0, r9] */
/* @0x26bbd8 and r3, r1, r3 */
/* @0x26bbdc cmp r2, r3 */
/* @0x26bbe0 addeq r5, r5, #1 */
/* @0x26bbe4 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26bbe8 ldrb r2, [r4, #0x1] */
/* @0x26bbec add r6, r6, #1 */
/* @0x26bbf0 ldrb r3, [r4, #0x2] */
/* @0x26bbf4 orr r3, r3, r2, lsl #8 */
/* @0x26bbf8 cmp r6, r3 */
/* @0x26bbfc blt 0x26d71c <pcre_compile+0x4794> */
/* @0x26bc00 ldr r4, [sp, #0x30] */
/* @0x26bc04 add r3, r11, #1 */
/* @0x26bc08 cmp r11, r4 */
/* @0x26bc0c bge 0x2691dc <pcre_compile+0x254> */
/* @0x26bc10 add r7, r7, #4 */
/* @0x26bc14 mov r11, r3 */
/* @0x26bc18 str r7, [r12] */
/* @0x26bc1c mov r3, #0 */
/* @0x26bc20 add r5, r5, #1 */
/* @0x26bc24 str r3, [r12, #0x4] */
/* @0x26bc28 add r12, r12, #12 */
/* @0x26bc2c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26bc30 ldr r9, [sp, #0x24] */
/* @0x26bc34 mov r2, #0 */
/* @0x26bc38 add r3, r9, #12 */
/* @0x26bc3c ldr r6, [sp, #0x3c] */
/* @0x26bc40 add r8, r8, #1 */
/* @0x26bc44 ldr r7, [sp, #0x30] */
/* @0x26bc48 mov r1, r3 */
/* @0x26bc4c rsb r0, r6, r4 */
/* @0x26bc50 sub r6, r8, #1 */
/* @0x26bc54 cmp r7, r6 */
/* @0x26bc58 add r0, r0, #3 */
/* @0x26bc5c add r3, r3, #12 */
/* @0x26bc60 ble 0x2691dc <pcre_compile+0x254> */
/* @0x26bc64 str r0, [r1, #-0xc] */
/* @0x26bc68 str r2, [r1, #-0x8] */
/* @0x26bc6c ldrb r6, [r4, #0x1] */
/* @0x26bc70 ldrb r0, [r4, #0x2] */
/* @0x26bc74 orr r0, r0, r6, lsl #8 */
/* @0x26bc78 ldrb r0, [r4, r0]! */
/* @0x26bc7c cmp r0, #119 */
/* @0x26bc80 beq 0x26bc3c <pcre_compile+0x2cb4> */
/* @0x26bc84 str r1, [sp, #0x24] */
/* @0x26bc88 add r5, r5, #1 */
/* @0x26bc8c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26bc90 ldr r7, [sp, #0x6c] */
/* @0x26bc94 add r9, sp, #4160 */
/* @0x26bc98 ldr r2, [sp, #0x38] */
/* @0x26bc9c mov r3, #2 */
/* @0x26bca0 add r6, sp, #216 */
/* @0x26bca4 str r3, [sp, #0x4] */
/* @0x26bca8 str r7, [sp, #0x10] */
/* @0x26bcac mov r3, #1000 */
/* @0x26bcb0 ldr r7, [sp, #0x54] */
/* @0x26bcb4 add r9, r9, #56 */
/* @0x26bcb8 str r3, [sp, #0xc] */
/* @0x26bcbc mov r1, r4 */
/* @0x26bcc0 str r6, [sp] */
/* @0x26bcc4 rsb r3, r7, r2 */
/* @0x26bcc8 str r9, [sp, #0x8] */
/* @0x26bccc ldr r0, [sp, #0x28] */
/* @0x26bcd0 str r12, [sp, #0x1c] */
/* @0x26bcd4 bl 0x268fb4 <pcre_compile+0x2c> —— 自递归 1/5 */
/* @0x26bcd8 ldr r12, [sp, #0x1c] */
/* @0x26bcdc cmp r0, #0 */
/* @0x26bce0 blt 0x26d388 <pcre_compile+0x4400> */
/* @0x26bce4 add r0, sp, #8192 */
/* @0x26bce8 movw r3, #0xe0c0 */
/* @0x26bcec add r0, r0, #24 */
/* @0x26bcf0 movt r3, #0xffff */
/* @0x26bcf4 ldr r9, [r6, #0x4] */
/* @0x26bcf8 ldr r7, [r0, r3] */
/* @0x26bcfc rsb r3, r7, r9 */
/* @0x26bd00 ldrb r1, [r4, #0x1] */
/* @0x26bd04 ldrb r2, [r4, #0x2] */
/* @0x26bd08 orr r2, r2, r1, lsl #8 */
/* @0x26bd0c ldrb r1, [r4, r2]! */
/* @0x26bd10 cmp r1, #119 */
/* @0x26bd14 beq 0x26bd00 <pcre_compile+0x2d78> */
/* @0x26bd18 sub r1, r1, #121 */
/* @0x26bd1c ldr r6, [sp, #0x3c] */
/* @0x26bd20 cmp r1, #1 */
/* @0x26bd24 rsb r2, r6, r4 */
/* @0x26bd28 ldrbls r0, [r4, #0x1] */
/* @0x26bd2c mvnhi r4, #0 */
/* @0x26bd30 ldrbls r1, [r4, #0x2] */
/* @0x26bd34 add r6, r2, #3 */
/* @0x26bd38 orrls r1, r1, r0, lsl #8 */
/* @0x26bd3c rsbls r4, r1, r2 */
/* @0x26bd40 cmp r3, #0 */
/* @0x26bd44 beq 0x26c9c8 <pcre_compile+0x3a40> */
/* @0x26bd48 add r5, r5, #1 */
/* @0x26bd4c cmp r8, r5 */
/* @0x26bd50 bgt 0x26d43c <pcre_compile+0x44b4> */
/* @0x26bd54 cmp r11, #0 */
/* @0x26bd58 bne 0x26d43c <pcre_compile+0x44b4> */
/* @0x26bd5c ldr r7, [sp, #0x30] */
/* @0x26bd60 ldr r9, [sp, #0x38] */
/* @0x26bd64 cmp r7, #0 */
/* @0x26bd68 add r9, r9, r3 */
/* @0x26bd6c str r9, [sp, #0x38] */
/* @0x26bd70 ble 0x2691dc <pcre_compile+0x254> */
/* @0x26bd74 cmp r4, #0 */
/* @0x26bd78 stm r12, {r6, r11} */
/* @0x26bd7c add r12, r12, #12 */
/* @0x26bd80 blt 0x26e064 <pcre_compile+0x50dc> */
/* @0x26bd84 mov r5, r11 */
/* @0x26bd88 str r11, [r10, #0x4] */
/* @0x26bd8c mov r11, #1 */
/* @0x26bd90 str r4, [r10] */
/* @0x26bd94 str r5, [sp, #0x40] */
/* @0x26bd98 add r4, r10, #12 */
/* @0x26bd9c mov r8, r11 */
/* @0x26bda0 str r4, [sp, #0x24] */
/* @0x26bda4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26bda8 ldrb r2, [r4, #0x1] */
/* @0x26bdac ldrb r3, [r4, #0x2] */
/* @0x26bdb0 orr r3, r3, r2, lsl #8 */
/* @0x26bdb4 add r7, r4, r3 */
/* @0x26bdb8 ldrb r3, [r4, r3] */
/* @0x26bdbc cmp r3, #119 */
/* @0x26bdc0 bne 0x26bddc <pcre_compile+0x2e54> */
/* @0x26bdc4 ldrb r2, [r7, #0x1] */
/* @0x26bdc8 ldrb r3, [r7, #0x2] */
/* @0x26bdcc orr r3, r3, r2, lsl #8 */
/* @0x26bdd0 ldrb r3, [r7, r3]! */
/* @0x26bdd4 cmp r3, #119 */
/* @0x26bdd8 beq 0x26bdc4 <pcre_compile+0x2e3c> */
/* @0x26bddc ldr r6, [sp, #0x6c] */
/* @0x26bde0 mov r1, r4 */
/* @0x26bde4 ldr r2, [sp, #0x38] */
/* @0x26bde8 add lr, sp, #4160 */
/* @0x26bdec ldr r4, [sp, #0x54] */
/* @0x26bdf0 mov r3, #2 */
/* @0x26bdf4 str r6, [sp, #0x10] */
/* @0x26bdf8 add lr, lr, #56 */
/* @0x26bdfc str r3, [sp, #0x4] */
/* @0x26be00 add r6, sp, #216 */
/* @0x26be04 mov r3, #1000 */
/* @0x26be08 str r6, [sp] */
/* @0x26be0c str r3, [sp, #0xc] */
/* @0x26be10 rsb r3, r4, r2 */
/* @0x26be14 str lr, [sp, #0x8] */
/* @0x26be18 ldr r0, [sp, #0x28] */
/* @0x26be1c str r12, [sp, #0x1c] */
/* @0x26be20 bl 0x268fb4 <pcre_compile+0x2c> —— 自递归 2/5 */
/* @0x26be24 ldr r12, [sp, #0x1c] */
/* @0x26be28 cmn r0, #16 */
/* @0x26be2c beq 0x2691e0 <pcre_compile+0x258> */
/* @0x26be30 bic r3, r9, #2 */
/* @0x26be34 subs r1, r3, #125 */
/* @0x26be38 rsbs r3, r1, #0 */
/* @0x26be3c adcs r3, r3, r1 */
/* @0x26be40 cmp r3, r0, lsr #31 */
/* @0x26be44 beq 0x26be7c <pcre_compile+0x2ef4> */
/* @0x26be48 ldr r6, [sp, #0x30] */
/* @0x26be4c cmp r8, r6 */
/* @0x26be50 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26be54 ldr r9, [sp, #0x24] */
/* @0x26be58 add r3, r7, #3 */
/* @0x26be5c add r8, r8, #1 */
/* @0x26be60 ldr r7, [sp, #0x3c] */
/* @0x26be64 add r9, r9, #12 */
/* @0x26be68 rsb r3, r7, r3 */
/* @0x26be6c str r3, [r9, #-0xc] */
/* @0x26be70 mov r3, #0 */
/* @0x26be74 str r3, [r9, #-0x8] */
/* @0x26be78 str r9, [sp, #0x24] */
/* @0x26be7c add r5, r5, #1 */
/* @0x26be80 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26be84 mov r0, #0 */
/* @0x26be88 b 0x26a37c <pcre_compile+0x13f4> */
/* @0x26be8c ldr r9, [sp, #0x30] */
/* @0x26be90 add r2, r8, #1 */
/* @0x26be94 cmp r8, r9 */
/* @0x26be98 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26be9c ldr r6, [sp, #0x3c] */
/* @0x26bea0 mov r3, #0 */
/* @0x26bea4 ldr r7, [sp, #0x24] */
/* @0x26bea8 rsb r1, r6, r4 */
/* @0x26beac add r1, r1, #5 */
/* @0x26beb0 add r6, r7, #12 */
/* @0x26beb4 stm r7, {r1, r3} */
/* @0x26beb8 ldrb r0, [r4, #0x1] */
/* @0x26bebc ldrb r1, [r4, #0x2] */
/* @0x26bec0 orr r0, r1, r0, lsl #8 */
/* @0x26bec4 ldrb r1, [r4, r0] */
/* @0x26bec8 add r4, r4, r0 */
/* @0x26becc cmp r1, #119 */
/* @0x26bed0 beq 0x26d330 <pcre_compile+0x43a8> */
/* @0x26bed4 add r5, r5, #1 */
/* @0x26bed8 mov r8, r2 */
/* @0x26bedc str r6, [sp, #0x24] */
/* @0x26bee0 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26bee4 cmp r9, #148 */
/* @0x26bee8 ldr lr, [sp, #0x38] */
/* @0x26beec addeq r4, r4, #1 */
/* @0x26bef0 movw r9, #0xe0c0 */
/* @0x26bef4 moveq r6, #1 */
/* @0x26bef8 streq r6, [sp, #0x7c] */
/* @0x26befc ldr r6, [sp, #0x54] */
/* @0x26bf00 movne r7, #0 */
/* @0x26bf04 movt r9, #0xffff */
/* @0x26bf08 strne r7, [sp, #0x7c] */
/* @0x26bf0c rsb lr, r6, lr */
/* @0x26bf10 add r7, sp, #4160 */
/* @0x26bf14 add r7, r7, #56 */
/* @0x26bf18 mov r0, #0 */
/* @0x26bf1c str r7, [sp, #0x2c] */
/* @0x26bf20 add r6, sp, #216 */
/* @0x26bf24 str r10, [sp, #0xb0] */
/* @0x26bf28 str r8, [sp, #0xb8] */
/* @0x26bf2c mov r8, r9 */
/* @0x26bf30 str r11, [sp, #0xbc] */
/* @0x26bf34 mov r9, lr */
/* @0x26bf38 str r5, [sp, #0xc0] */
/* @0x26bf3c mov r5, r4 */
/* @0x26bf40 str lr, [sp, #0xc4] */
/* @0x26bf44 mov r4, r0 */
/* @0x26bf48 ldr r7, [sp, #0x38] */
/* @0x26bf4c str r0, [sp, #0x60] */
/* @0x26bf50 str r12, [sp, #0xb4] */
/* @0x26bf54 ldr r10, [sp, #0x28] */
/* @0x26bf58 ldr r11, [sp, #0x2c] */
/* @0x26bf5c b 0x26bf80 <pcre_compile+0x2ff8> */
/* @0x26bf60 add r0, sp, #8192 */
/* @0x26bf64 ldr r2, [r6, #0x4] */
/* @0x26bf68 add r0, r0, #24 */
/* @0x26bf6c ldr r3, [r0, r8] */
/* @0x26bf70 subs r3, r2, r3 */
/* @0x26bf74 beq 0x26d094 <pcre_compile+0x410c> */
/* @0x26bf78 add r7, r7, r3 */
/* @0x26bf7c add r4, r4, #1 */
/* @0x26bf80 ldr r12, [sp, #0x6c] */
/* @0x26bf84 mov r1, #2 */
/* @0x26bf88 mov r3, #1000 */
/* @0x26bf8c str r1, [sp, #0x4] */
/* @0x26bf90 str r3, [sp, #0xc] */
/* @0x26bf94 mov r0, r10 */
/* @0x26bf98 str r6, [sp] */
/* @0x26bf9c mov r1, r5 */
/* @0x26bfa0 str r11, [sp, #0x8] */
/* @0x26bfa4 mov r2, r7 */
/* @0x26bfa8 mov r3, r9 */
/* @0x26bfac str r12, [sp, #0x10] */
/* @0x26bfb0 bl 0x268fb4 <pcre_compile+0x2c> —— 自递归 3/5 */
/* @0x26bfb4 cmp r0, #0 */
/* @0x26bfb8 bge 0x26bf60 <pcre_compile+0x2fd8> */
/* @0x26bfbc cmn r0, #1 */
/* @0x26bfc0 str r4, [sp, #0x60] */
/* @0x26bfc4 ldr r10, [sp, #0xb0] */
/* @0x26bfc8 mov r4, r5 */
/* @0x26bfcc ldr r12, [sp, #0xb4] */
/* @0x26bfd0 ldr r8, [sp, #0xb8] */
/* @0x26bfd4 ldr r11, [sp, #0xbc] */
/* @0x26bfd8 ldr r5, [sp, #0xc0] */
/* @0x26bfdc bne 0x2691e0 <pcre_compile+0x258> */
/* @0x26bfe0 ldr r9, [sp, #0x7c] */
/* @0x26bfe4 ldr r1, [sp, #0x60] */
/* @0x26bfe8 cmp r1, #0 */
/* @0x26bfec orrgt r9, r9, #1 */
/* @0x26bff0 cmp r9, #0 */
/* @0x26bff4 addeq r5, r5, #1 */
/* @0x26bff8 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26bffc ldrb r2, [r4, #0x1] */
/* @0x26c000 ldrb r3, [r4, #0x2] */
/* @0x26c004 orr r3, r3, r2, lsl #8 */
/* @0x26c008 ldrb r3, [r4, r3]! */
/* @0x26c00c cmp r3, #119 */
/* @0x26c010 beq 0x26bffc <pcre_compile+0x3074> */
/* @0x26c014 add r5, r5, #1 */
/* @0x26c018 ldr r6, [sp, #0x3c] */
/* @0x26c01c cmp r8, r5 */
/* @0x26c020 rsb r4, r6, r4 */
/* @0x26c024 add r4, r4, #3 */
/* @0x26c028 bgt 0x26d2c4 <pcre_compile+0x433c> */
/* @0x26c02c cmp r11, #0 */
/* @0x26c030 bne 0x26d2c4 <pcre_compile+0x433c> */
/* @0x26c034 ldr r5, [sp, #0x30] */
/* @0x26c038 mov r9, r12 */
/* @0x26c03c cmp r5, #0 */
/* @0x26c040 ble 0x2691dc <pcre_compile+0x254> */
/* @0x26c044 str r11, [r9, #0x4] */
/* @0x26c048 mov r12, #1 */
/* @0x26c04c str r11, [sp, #0x40] */
/* @0x26c050 str r4, [r9] */
/* @0x26c054 str r7, [sp, #0x38] */
/* @0x26c058 b 0x269494 <pcre_compile+0x50c> */
/* @0x26c05c ldr r6, [sp, #0xac] */
/* @0x26c060 cmp r4, r6 */
/* @0x26c064 beq 0x26dad8 <pcre_compile+0x4b50> */
/* @0x26c068 ldr r6, [sp, #0x30] */
/* @0x26c06c add r2, r8, #1 */
/* @0x26c070 cmp r8, r6 */
/* @0x26c074 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26c078 cmp r9, #120 */
/* @0x26c07c ldr r9, [sp, #0x24] */
/* @0x26c080 add r3, r7, #3 */
/* @0x26c084 str r3, [r9] */
/* @0x26c088 mov r3, #0 */
/* @0x26c08c str r3, [r9, #0x4] */
/* @0x26c090 beq 0x26d290 <pcre_compile+0x4308> */
/* @0x26c094 ldr r6, [sp, #0x30] */
/* @0x26c098 add r8, r8, #2 */
/* @0x26c09c cmp r6, r2 */
/* @0x26c0a0 ble 0x2691dc <pcre_compile+0x254> */
/* @0x26c0a4 ldr r9, [sp, #0x24] */
/* @0x26c0a8 add r5, r5, #1 */
/* @0x26c0ac ldrb r1, [r4, #0x1] */
/* @0x26c0b0 ldrb r2, [r4, #0x2] */
/* @0x26c0b4 add r9, r9, #24 */
/* @0x26c0b8 str r3, [r9, #-0x8] */
/* @0x26c0bc orr r3, r2, r1, lsl #8 */
/* @0x26c0c0 rsb r7, r3, r7 */
/* @0x26c0c4 str r7, [r9, #-0xc] */
/* @0x26c0c8 str r9, [sp, #0x24] */
/* @0x26c0cc b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c0d0 mov r0, #2 */
/* @0x26c0d4 b 0x26b1a4 <pcre_compile+0x221c> */
/* @0x26c0d8 ldr r3, [r6, #0x4] */
/* @0x26c0dc cmp r3, #0 */
/* @0x26c0e0 ble 0x26c114 <pcre_compile+0x318c> */
/* @0x26c0e4 ldr r4, [sp, #0x30] */
/* @0x26c0e8 add r2, r8, #1 */
/* @0x26c0ec cmp r8, r4 */
/* @0x26c0f0 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26c0f4 ldr r6, [sp, #0x24] */
/* @0x26c0f8 mov r8, r2 */
/* @0x26c0fc add r1, r7, #2 */
/* @0x26c100 add r6, r6, #12 */
/* @0x26c104 str r1, [r6, #-0xc] */
/* @0x26c108 mov r1, #0 */
/* @0x26c10c str r1, [r6, #-0x8] */
/* @0x26c110 str r6, [sp, #0x24] */
/* @0x26c114 ldr r4, [sp, #0x40] */
/* @0x26c118 cmp r4, #0 */
/* @0x26c11c addeq r5, r5, #1 */
/* @0x26c120 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26c124 ldr r6, [sp, #0x34] */
/* @0x26c128 movw r2, #0x180e */
/* @0x26c12c cmp r6, r2 */
/* @0x26c130 beq 0x26c844 <pcre_compile+0x38bc> */
/* @0x26c134 bls 0x26c824 <pcre_compile+0x389c> */
/* @0x26c138 ldr r6, [sp, #0x34] */
/* @0x26c13c movw r2, #0x202f */
/* @0x26c140 cmp r6, r2 */
/* @0x26c144 beq 0x26c844 <pcre_compile+0x38bc> */
/* @0x26c148 bls 0x26d810 <pcre_compile+0x4888> */
/* @0x26c14c ldr r4, [sp, #0x34] */
/* @0x26c150 movw r2, #0x205f */
/* @0x26c154 cmp r4, r2 */
/* @0x26c158 beq 0x26c844 <pcre_compile+0x38bc> */
/* @0x26c15c cmp r4, #12288 */
/* @0x26c160 beq 0x26c844 <pcre_compile+0x38bc> */
/* @0x26c164 mov r2, #0 */
/* @0x26c168 ldr r6, [sp, #0x2c] */
/* @0x26c16c subs r6, r6, #19 */
/* @0x26c170 rsbs r1, r6, #0 */
/* @0x26c174 adcs r1, r1, r6 */
/* @0x26c178 cmp r1, r2 */
/* @0x26c17c addne r5, r5, #1 */
/* @0x26c180 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26c184 movw r2, #0x1c7 */
/* @0x26c188 subs r4, r9, r2 */
/* @0x26c18c rsbs r9, r4, #0 */
/* @0x26c190 add r2, r11, #1 */
/* @0x26c194 adcs r9, r9, r4 */
/* @0x26c198 cmp r3, #0 */
/* @0x26c19c ldr r4, [sp, #0x30] */
/* @0x26c1a0 add r3, r3, #1 */
/* @0x26c1a4 movle r9, #0 */
/* @0x26c1a8 cmp r9, #0 */
/* @0x26c1ac subne r8, r8, #1 */
/* @0x26c1b0 ldrne r9, [sp, #0x24] */
/* @0x26c1b4 subne r9, r9, #12 */
/* @0x26c1b8 strne r9, [sp, #0x24] */
/* @0x26c1bc cmp r11, r4 */
/* @0x26c1c0 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26c1c4 str r3, [r12, #0x4] */
/* @0x26c1c8 rsb r7, r7, #0 */
/* @0x26c1cc mov r3, #0 */
/* @0x26c1d0 str r7, [r12] */
/* @0x26c1d4 str r3, [r12, #0x8] */
/* @0x26c1d8 add r5, r5, #1 */
/* @0x26c1dc mov r11, r2 */
/* @0x26c1e0 add r12, r12, #12 */
/* @0x26c1e4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c1e8 movw r3, #0x1c5 */
/* @0x26c1ec cmp r9, r3 */
/* @0x26c1f0 beq 0x26c224 <pcre_compile+0x329c> */
/* @0x26c1f4 ldr r0, [sp, #0x30] */
/* @0x26c1f8 add r3, r8, #1 */
/* @0x26c1fc cmp r8, r0 */
/* @0x26c200 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26c204 ldr r1, [sp, #0x24] */
/* @0x26c208 mov r8, r3 */
/* @0x26c20c add r2, r7, #4 */
/* @0x26c210 add r1, r1, #12 */
/* @0x26c214 str r2, [r1, #-0xc] */
/* @0x26c218 mov r2, #0 */
/* @0x26c21c str r2, [r1, #-0x8] */
/* @0x26c220 str r1, [sp, #0x24] */
/* @0x26c224 ldr r2, [sp, #0x40] */
/* @0x26c228 ldr r3, [r6, #0x4] */
/* @0x26c22c cmp r2, #0 */
/* @0x26c230 addeq r5, r5, #1 */
/* @0x26c234 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26c238 ldr r6, [sp, #0x34] */
/* @0x26c23c movw r2, #0x180e */
/* @0x26c240 cmp r6, r2 */
/* @0x26c244 beq 0x26c81c <pcre_compile+0x3894> */
/* @0x26c248 bhi 0x26c7f0 <pcre_compile+0x3868> */
/* @0x26c24c cmp r6, #32 */
/* @0x26c250 beq 0x26c81c <pcre_compile+0x3894> */
/* @0x26c254 bls 0x26dc04 <pcre_compile+0x4c7c> */
/* @0x26c258 ldr r6, [sp, #0x34] */
/* @0x26c25c cmp r6, #160 */
/* @0x26c260 beq 0x26c81c <pcre_compile+0x3894> */
/* @0x26c264 cmp r6, #5760 */
/* @0x26c268 beq 0x26c81c <pcre_compile+0x3894> */
/* @0x26c26c mov r2, #0 */
/* @0x26c270 ldr r6, [sp, #0x2c] */
/* @0x26c274 subs r0, r6, #19 */
/* @0x26c278 rsbs r1, r0, #0 */
/* @0x26c27c adcs r1, r1, r0 */
/* @0x26c280 cmp r1, r2 */
/* @0x26c284 addne r5, r5, #1 */
/* @0x26c288 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26c28c movw r2, #0x1c9 */
/* @0x26c290 cmp r9, r2 */
/* @0x26c294 ldrb r1, [r4, #0x1] */
/* @0x26c298 add r3, r3, #1 */
/* @0x26c29c ldreq r9, [sp, #0x24] */
/* @0x26c2a0 subeq r8, r8, #1 */
/* @0x26c2a4 ldrb r2, [r4, #0x2] */
/* @0x26c2a8 subeq r9, r9, #12 */
/* @0x26c2ac orr r2, r2, r1, lsl #8 */
/* @0x26c2b0 streq r9, [sp, #0x24] */
/* @0x26c2b4 cmp r3, r2 */
/* @0x26c2b8 blt 0x26dbd0 <pcre_compile+0x4c48> */
/* @0x26c2bc ldr r4, [sp, #0x30] */
/* @0x26c2c0 add r2, r11, #1 */
/* @0x26c2c4 cmp r11, r4 */
/* @0x26c2c8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26c2cc movw r3, #0xfffc */
/* @0x26c2d0 movt r3, #0xffff */
/* @0x26c2d4 mov r11, r2 */
/* @0x26c2d8 rsb r3, r7, r3 */
/* @0x26c2dc mov r2, #0 */
/* @0x26c2e0 str r3, [r12] */
/* @0x26c2e4 str r2, [r12, #0x4] */
/* @0x26c2e8 add r5, r5, #1 */
/* @0x26c2ec str r2, [r12, #0x8] */
/* @0x26c2f0 add r12, r12, #12 */
/* @0x26c2f4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c2f8 ldr r4, [sp, #0x34] */
/* @0x26c2fc sub r1, r4, #8192 */
/* @0x26c300 sub r1, r1, #40 */
/* @0x26c304 cmp r1, #1 */
/* @0x26c308 bhi 0x26a3d8 <pcre_compile+0x1450> */
/* @0x26c30c mov r1, #1 */
/* @0x26c310 b 0x26a3dc <pcre_compile+0x1454> */
/* @0x26c314 ldr r1, [sp, #0x2c] */
/* @0x26c318 add r2, r4, r3 */
/* @0x26c31c tst r1, #4 */
/* @0x26c320 bne 0x26c70c <pcre_compile+0x3784> */
/* @0x26c324 ldrb r0, [r2, #0x4] */
/* @0x26c328 and r3, r1, #3 */
/* @0x26c32c ldrb r1, [r2, #0x1] */
/* @0x26c330 and r0, r0, #63 */
/* @0x26c334 str r0, [sp, #0x2c] */
/* @0x26c338 ldrb r0, [r2, #0x2] */
/* @0x26c33c and r1, r1, #63 */
/* @0x26c340 ldrb r2, [r2, #0x3] */
/* @0x26c344 str r3, [sp, #0x60] */
/* @0x26c348 and r0, r0, #63 */
/* @0x26c34c str r1, [sp, #0x7c] */
/* @0x26c350 mov r3, #5 */
/* @0x26c354 str r2, [sp, #0xb0] */
/* @0x26c358 ldr r2, [sp, #0x60] */
/* @0x26c35c ldr r1, [sp, #0x2c] */
/* @0x26c360 str r0, [sp, #0x60] */
/* @0x26c364 ldr r0, [sp, #0x7c] */
/* @0x26c368 orr r1, r1, r2, lsl #24 */
/* @0x26c36c orr r1, r1, r0, lsl #18 */
/* @0x26c370 ldr r0, [sp, #0xb0] */
/* @0x26c374 and r2, r0, #63 */
/* @0x26c378 ldr r0, [sp, #0x60] */
/* @0x26c37c orr r1, r1, r0, lsl #12 */
/* @0x26c380 orr r2, r1, r2, lsl #6 */
/* @0x26c384 str r2, [sp, #0x2c] */
/* @0x26c388 b 0x269560 <pcre_compile+0x5d8> */
/* @0x26c38c mov r3, #0 */
/* @0x26c390 ldr r4, [sp, #0x40] */
/* @0x26c394 cmp r4, #0 */
/* @0x26c398 beq 0x26d2bc <pcre_compile+0x4334> */
/* @0x26c39c ldr r6, [sp, #0x34] */
/* @0x26c3a0 cmp r6, #255 */
/* @0x26c3a4 movhi r2, #0 */
/* @0x26c3a8 bls 0x26c9f4 <pcre_compile+0x3a6c> */
/* @0x26c3ac eor r3, r2, r3 */
/* @0x26c3b0 and r3, r3, #1 */
/* @0x26c3b4 cmp r9, #4 */
/* @0x26c3b8 movne r9, r3 */
/* @0x26c3bc eoreq r9, r3, #1 */
/* @0x26c3c0 cmp r9, #0 */
/* @0x26c3c4 addeq r5, r5, #1 */
/* @0x26c3c8 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26c3cc ldr r6, [sp, #0x30] */
/* @0x26c3d0 add r3, r8, #1 */
/* @0x26c3d4 cmp r8, r6 */
/* @0x26c3d8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26c3dc ldr r9, [sp, #0x24] */
/* @0x26c3e0 add r7, r7, #1 */
/* @0x26c3e4 mov r8, r3 */
/* @0x26c3e8 add r5, r5, #1 */
/* @0x26c3ec mov r3, #0 */
/* @0x26c3f0 add r9, r9, #12 */
/* @0x26c3f4 str r7, [r9, #-0xc] */
/* @0x26c3f8 str r3, [r9, #-0x8] */
/* @0x26c3fc str r9, [sp, #0x24] */
/* @0x26c400 b 0x269480 <pcre_compile+0x4f8> —— b 之后跟 4 字字面量池 */
/* @0x26c404 andseq r6, r8, r8, asr #5 —— 非指令：字面量池（andseq 是池数据） */
/* @0x26c408 andseq r0, r2, r8, ror #3 */
/* @0x26c40c ldrsbeq pc, [r1], -r4 —— 非指令：池数据（被译成 ldrsbeq pc,...） */
/* @0x26c410 mulseq r8, r0, r6 —— 非指令：池数据（mulseq） */
/* @0x26c414 str r9, [sp, #0x60] */
/* @0x26c418 ldr r6, [sp, #0x28] */
/* @0x26c41c mov r2, #1000 */
/* @0x26c420 ldr lr, [sp, #0x54] */
/* @0x26c424 add r9, sp, #204 */
/* @0x26c428 str r3, [sp, #0xd0] */
/* @0x26c42c movw r4, #0xe0b4 */
/* @0x26c430 str r9, [r6, #0x30] */
/* @0x26c434 add r9, sp, #4160 */
/* @0x26c438 str r2, [sp, #0x4] */
/* @0x26c43c add r9, r9, #56 */
/* @0x26c440 str r2, [sp, #0xc] */
/* @0x26c444 movt r4, #0xffff */
/* @0x26c448 ldr r2, [sp, #0x38] */
/* @0x26c44c ldr r6, [sp, #0x6c] */
/* @0x26c450 str r9, [sp, #0x8] */
/* @0x26c454 rsb r3, lr, r2 */
/* @0x26c458 ldr r9, [sp, #0x60] */
/* @0x26c45c add lr, sp, #8192 */
/* @0x26c460 add lr, lr, #24 */
/* @0x26c464 str r6, [sp, #0x10] */
/* @0x26c468 ldr r0, [sp, #0x28] */
/* @0x26c46c add r6, sp, #216 */
/* @0x26c470 str r6, [sp] */
/* @0x26c474 str r9, [lr, r4] */
/* @0x26c478 str r2, [sp, #0xd4] */
/* @0x26c47c str r12, [sp, #0x1c] */
/* @0x26c480 bl 0x268fb4 <pcre_compile+0x2c> —— 自递归 4/5 */
/* @0x26c484 add r1, sp, #8192 */
/* @0x26c488 ldr r12, [sp, #0x1c] */
/* @0x26c48c add r1, r1, #24 */
/* @0x26c490 ldr r3, [r1, r4] */
/* @0x26c494 ldr r4, [sp, #0x28] */
/* @0x26c498 str r3, [r4, #0x30] */
/* @0x26c49c cmp r0, #0 */
/* @0x26c4a0 beq 0x26e2d4 <pcre_compile+0x534c> */
/* @0x26c4a4 ble 0x26c79c <pcre_compile+0x3814> */
/* @0x26c4a8 sub r0, r0, #1 */
/* @0x26c4ac movw r9, #0xfffd */
/* @0x26c4b0 movt r9, #0xffff */
/* @0x26c4b4 add r1, r7, #3 */
/* @0x26c4b8 lsl r4, r0, #1 */
/* @0x26c4bc rsb r9, r7, r9 */
/* @0x26c4c0 add r3, r4, #1 */
/* @0x26c4c4 mov r7, r11 */
/* @0x26c4c8 str r1, [sp, #0x2c] */
/* @0x26c4cc add r6, r6, r3, lsl #2 */
/* @0x26c4d0 ldr r2, [sp, #0x48] */
/* @0x26c4d4 ldr r1, [r6] */
/* @0x26c4d8 ldr r3, [r6, #-0x4] */
/* @0x26c4dc cmp r2, #0 */
/* @0x26c4e0 rsb r0, r3, r1 */
/* @0x26c4e4 beq 0x26c514 <pcre_compile+0x358c> */
/* @0x26c4e8 ldr r2, [sp, #0x54] */
/* @0x26c4ec add r3, r2, r3 */
/* @0x26c4f0 add r1, r2, r1 */
/* @0x26c4f4 cmp r3, r1 */
/* @0x26c4f8 bhs 0x26c514 <pcre_compile+0x358c> */
/* @0x26c4fc ldrb r2, [r3], #1 */
/* @0x26c500 and r2, r2, #192 */
/* @0x26c504 cmp r2, #128 */
/* @0x26c508 subeq r0, r0, #1 */
/* @0x26c50c cmp r3, r1 */
/* @0x26c510 bne 0x26c4fc <pcre_compile+0x3574> */
/* @0x26c514 cmp r0, #0 */
/* @0x26c518 ble 0x26d064 <pcre_compile+0x40dc> */
/* @0x26c51c ldr r3, [sp, #0x30] */
/* @0x26c520 add r11, r11, #1 */
/* @0x26c524 cmp r3, r7 */
/* @0x26c528 ble 0x2691dc <pcre_compile+0x254> */
/* @0x26c52c sub r0, r0, #1 */
/* @0x26c530 str r9, [r12] */
/* @0x26c534 str r0, [r12, #0x8] */
/* @0x26c538 mov r7, #0 */
/* @0x26c53c add r12, r12, #12 */
/* @0x26c540 str r7, [r12, #-0x8] */
/* @0x26c544 subs r4, r4, #2 */
/* @0x26c548 sub r6, r6, #8 */
/* @0x26c54c bmi 0x26c7a4 <pcre_compile+0x381c> */
/* @0x26c550 mov r7, r11 */
/* @0x26c554 b 0x26c4d0 <pcre_compile+0x3548> */
/* @0x26c558 cmp r9, #44 */
/* @0x26c55c cmpne r9, #70 */
/* @0x26c560 ldr r7, [sp, #0x24] */
/* @0x26c564 add r1, r11, #1 */
/* @0x26c568 movne r9, #0 */
/* @0x26c56c moveq r9, #1 */
/* @0x26c570 cmp r9, #0 */
/* @0x26c574 ldr r9, [sp, #0x30] */
/* @0x26c578 moveq r7, r3 */
/* @0x26c57c moveq r8, r2 */
/* @0x26c580 cmp r11, r9 */
/* @0x26c584 str r7, [sp, #0x24] */
/* @0x26c588 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26c58c str r4, [r12] */
/* @0x26c590 mov r3, #0 */
/* @0x26c594 add r5, r5, #1 */
/* @0x26c598 str r3, [r12, #0x4] */
/* @0x26c59c mov r11, r1 */
/* @0x26c5a0 add r12, r12, #12 */
/* @0x26c5a4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c5a8 cmp r9, #42 */
/* @0x26c5ac cmpne r9, #68 */
/* @0x26c5b0 ldr r6, [sp, #0x24] */
/* @0x26c5b4 add r1, r11, #1 */
/* @0x26c5b8 movne r9, #0 */
/* @0x26c5bc moveq r9, #1 */
/* @0x26c5c0 cmp r9, #0 */
/* @0x26c5c4 ldr r9, [sp, #0x30] */
/* @0x26c5c8 moveq r6, r3 */
/* @0x26c5cc moveq r8, r2 */
/* @0x26c5d0 cmp r11, r9 */
/* @0x26c5d4 str r6, [sp, #0x24] */
/* @0x26c5d8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26c5dc str r7, [r12] */
/* @0x26c5e0 mov r3, #0 */
/* @0x26c5e4 add r5, r5, #1 */
/* @0x26c5e8 str r3, [r12, #0x4] */
/* @0x26c5ec mov r11, r1 */
/* @0x26c5f0 add r12, r12, #12 */
/* @0x26c5f4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c5f8 ldrb r6, [r4, #0x1] */
/* @0x26c5fc cmp r9, #45 */
/* @0x26c600 cmpne r9, #71 */
/* @0x26c604 ldrb r1, [r4, #0x2] */
/* @0x26c608 movne r9, #0 */
/* @0x26c60c moveq r9, #1 */
/* @0x26c610 ldr r4, [sp, #0xb0] */
/* @0x26c614 cmp r9, #0 */
/* @0x26c618 orr r1, r1, r6, lsl #8 */
/* @0x26c61c ldr r9, [sp, #0x24] */
/* @0x26c620 add r3, r4, #1 */
/* @0x26c624 ldr r6, [sp, #0xb4] */
/* @0x26c628 moveq r9, r0 */
/* @0x26c62c str r9, [sp, #0x24] */
/* @0x26c630 moveq r8, r6 */
/* @0x26c634 cmp r3, r1 */
/* @0x26c638 blt 0x26c9a0 <pcre_compile+0x3a18> */
/* @0x26c63c ldr r4, [sp, #0x30] */
/* @0x26c640 add r3, r11, #1 */
/* @0x26c644 cmp r11, r4 */
/* @0x26c648 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26c64c ldr r6, [sp, #0x60] */
/* @0x26c650 mov r11, r3 */
/* @0x26c654 add r5, r5, #1 */
/* @0x26c658 mov r3, #0 */
/* @0x26c65c add r12, r12, #12 */
/* @0x26c660 str r3, [r12, #-0x8] */
/* @0x26c664 str r6, [r12, #-0xc] */
/* @0x26c668 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c66c ldr r4, [sp, #0x34] */
/* @0x26c670 movw r1, #0x202f */
/* @0x26c674 cmp r4, r1 */
/* @0x26c678 beq 0x26b218 <pcre_compile+0x2290> */
/* @0x26c67c bls 0x26cb74 <pcre_compile+0x3bec> */
/* @0x26c680 ldr r6, [sp, #0x34] */
/* @0x26c684 movw r1, #0x205f */
/* @0x26c688 cmp r6, r1 */
/* @0x26c68c beq 0x26b218 <pcre_compile+0x2290> */
/* @0x26c690 cmp r6, #12288 */
/* @0x26c694 bne 0x26cb80 <pcre_compile+0x3bf8> */
/* @0x26c698 b 0x26b218 <pcre_compile+0x2290> */
/* @0x26c69c ldr r4, [sp, #0x34] */
/* @0x26c6a0 tst r4, #8 */
/* @0x26c6a4 beq 0x26c7b4 <pcre_compile+0x382c> */
/* @0x26c6a8 ldr r9, [sp, #0x34] */
/* @0x26c6ac tst r9, #4 */
/* @0x26c6b0 bne 0x26dc60 <pcre_compile+0x4cd8> */
/* @0x26c6b4 ldr r12, [sp, #0x38] */
/* @0x26c6b8 and r2, r9, #3 */
/* @0x26c6bc mov r4, #5 */
/* @0x26c6c0 str r4, [sp, #0x40] */
/* @0x26c6c4 ldrb r3, [r12, #0x4] */
/* @0x26c6c8 ldrb r0, [r12, #0x1] */
/* @0x26c6cc and r3, r3, #63 */
/* @0x26c6d0 ldrb r1, [r12, #0x2] */
/* @0x26c6d4 orr r3, r3, r2, lsl #24 */
/* @0x26c6d8 and r0, r0, #63 */
/* @0x26c6dc ldrb r2, [r12, #0x3] */
/* @0x26c6e0 and r1, r1, #63 */
/* @0x26c6e4 orr r3, r3, r0, lsl #18 */
/* @0x26c6e8 and r2, r2, #63 */
/* @0x26c6ec orr r3, r3, r1, lsl #12 */
/* @0x26c6f0 orr r2, r3, r2, lsl #6 */
/* @0x26c6f4 str r2, [sp, #0x34] */
/* @0x26c6f8 b 0x2693e8 <pcre_compile+0x460> */
/* @0x26c6fc add r5, r5, #1 */
/* @0x26c700 ldr r8, [sp, #0xb4] */
/* @0x26c704 str r0, [sp, #0x24] */
/* @0x26c708 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c70c ldr r1, [sp, #0x2c] */
/* @0x26c710 mov r3, #6 */
/* @0x26c714 ldrb r0, [r2, #0x5] */
/* @0x26c718 and r1, r1, #1 */
/* @0x26c71c str r1, [sp, #0x2c] */
/* @0x26c720 ldrb r1, [r2, #0x1] */
/* @0x26c724 and r0, r0, #63 */
/* @0x26c728 str r1, [sp, #0x60] */
/* @0x26c72c ldrb r1, [r2, #0x2] */
/* @0x26c730 str r1, [sp, #0x7c] */
/* @0x26c734 ldr r1, [sp, #0x60] */
/* @0x26c738 and r1, r1, #63 */
/* @0x26c73c str r1, [sp, #0x60] */
/* @0x26c740 ldr r1, [sp, #0x2c] */
/* @0x26c744 orr r0, r0, r1, lsl #30 */
/* @0x26c748 str r0, [sp, #0x2c] */
/* @0x26c74c ldr r0, [sp, #0x7c] */
/* @0x26c750 ldr r1, [sp, #0x2c] */
/* @0x26c754 and r0, r0, #63 */
/* @0x26c758 str r0, [sp, #0x7c] */
/* @0x26c75c ldrb r0, [r2, #0x3] */
/* @0x26c760 ldrb r2, [r2, #0x4] */
/* @0x26c764 and r0, r0, #63 */
/* @0x26c768 str r2, [sp, #0xb0] */
/* @0x26c76c ldr r2, [sp, #0x60] */
/* @0x26c770 str r0, [sp, #0x60] */
/* @0x26c774 ldr r0, [sp, #0x7c] */
/* @0x26c778 orr r1, r1, r2, lsl #24 */
/* @0x26c77c orr r1, r1, r0, lsl #18 */
/* @0x26c780 ldr r0, [sp, #0xb0] */
/* @0x26c784 and r2, r0, #63 */
/* @0x26c788 ldr r0, [sp, #0x60] */
/* @0x26c78c orr r1, r1, r0, lsl #12 */
/* @0x26c790 orr r2, r1, r2, lsl r3 */
/* @0x26c794 str r2, [sp, #0x2c] */
/* @0x26c798 b 0x269560 <pcre_compile+0x5d8> */
/* @0x26c79c cmn r0, #1 */
/* @0x26c7a0 bne 0x2691e0 <pcre_compile+0x258> */
/* @0x26c7a4 add r5, r5, #1 */
/* @0x26c7a8 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c7ac mov r2, r8 */
/* @0x26c7b0 b 0x26acac <pcre_compile+0x1d24> */
/* @0x26c7b4 ldr r5, [sp, #0x38] */
/* @0x26c7b8 and r0, r4, #7 */
/* @0x26c7bc mov r7, #4 */
/* @0x26c7c0 str r7, [sp, #0x40] */
/* @0x26c7c4 ldrb r3, [r5, #0x3] */
/* @0x26c7c8 ldrb r1, [r5, #0x1] */
/* @0x26c7cc ldrb r2, [r5, #0x2] */
/* @0x26c7d0 and r3, r3, #63 */
/* @0x26c7d4 and r1, r1, #63 */
/* @0x26c7d8 orr r3, r3, r0, lsl #18 */
/* @0x26c7dc and r2, r2, #63 */
/* @0x26c7e0 orr r3, r3, r1, lsl #12 */
/* @0x26c7e4 orr r2, r3, r2, lsl #6 */
/* @0x26c7e8 str r2, [sp, #0x34] */
/* @0x26c7ec b 0x2693e8 <pcre_compile+0x460> */
/* @0x26c7f0 ldr r6, [sp, #0x34] */
/* @0x26c7f4 movw r2, #0x202f */
/* @0x26c7f8 cmp r6, r2 */
/* @0x26c7fc beq 0x26c81c <pcre_compile+0x3894> */
/* @0x26c800 bls 0x26dc50 <pcre_compile+0x4cc8> */
/* @0x26c804 ldr r6, [sp, #0x34] */
/* @0x26c808 movw r2, #0x205f */
/* @0x26c80c cmp r6, r2 */
/* @0x26c810 beq 0x26c81c <pcre_compile+0x3894> */
/* @0x26c814 cmp r6, #12288 */
/* @0x26c818 bne 0x26c26c <pcre_compile+0x32e4> */
/* @0x26c81c mov r2, #1 */
/* @0x26c820 b 0x26c270 <pcre_compile+0x32e8> */
/* @0x26c824 cmp r6, #32 */
/* @0x26c828 beq 0x26c844 <pcre_compile+0x38bc> */
/* @0x26c82c bls 0x26d820 <pcre_compile+0x4898> */
/* @0x26c830 ldr r4, [sp, #0x34] */
/* @0x26c834 cmp r4, #160 */
/* @0x26c838 beq 0x26c844 <pcre_compile+0x38bc> */
/* @0x26c83c cmp r4, #5760 */
/* @0x26c840 bne 0x26c164 <pcre_compile+0x31dc> */
/* @0x26c844 mov r2, #1 */
/* @0x26c848 b 0x26c168 <pcre_compile+0x31e0> */
/* @0x26c84c cmp r9, #143 */
/* @0x26c850 beq 0x26dcb8 <pcre_compile+0x4d30> */
/* @0x26c854 ldrb r2, [r4, #0x4] */
/* @0x26c858 add r1, r4, #3 */
/* @0x26c85c ldrb r3, [r4, #0x5] */
/* @0x26c860 orr r3, r3, r2, lsl #8 */
/* @0x26c864 add r4, r1, r3 */
/* @0x26c868 ldrb r3, [r1, r3] */
/* @0x26c86c cmp r3, #119 */
/* @0x26c870 bne 0x26c88c <pcre_compile+0x3904> */
/* @0x26c874 ldrb r2, [r4, #0x1] */
/* @0x26c878 ldrb r3, [r4, #0x2] */
/* @0x26c87c orr r3, r3, r2, lsl #8 */
/* @0x26c880 ldrb r3, [r4, r3]! */
/* @0x26c884 cmp r3, #119 */
/* @0x26c888 beq 0x26c874 <pcre_compile+0x38ec> */
/* @0x26c88c ldr r6, [sp, #0x6c] */
/* @0x26c890 add lr, sp, #4160 */
/* @0x26c894 add lr, lr, #56 */
/* @0x26c898 ldr r2, [sp, #0x38] */
/* @0x26c89c str lr, [sp, #0x8] */
/* @0x26c8a0 mov r3, #1000 */
/* @0x26c8a4 ldr lr, [sp, #0x54] */
/* @0x26c8a8 str r6, [sp, #0x10] */
/* @0x26c8ac add r6, sp, #216 */
/* @0x26c8b0 str r3, [sp, #0x4] */
/* @0x26c8b4 str r3, [sp, #0xc] */
/* @0x26c8b8 rsb r3, lr, r2 */
/* @0x26c8bc str r6, [sp] */
/* @0x26c8c0 ldr r0, [sp, #0x28] */
/* @0x26c8c4 str r12, [sp, #0x1c] */
/* @0x26c8c8 bl 0x268fb4 <pcre_compile+0x2c> —— 自递归 5/5 */
/* @0x26c8cc ldr r12, [sp, #0x1c] */
/* @0x26c8d0 cmn r0, #16 */
/* @0x26c8d4 beq 0x2691e0 <pcre_compile+0x258> */
/* @0x26c8d8 and r3, r9, #253 */
/* @0x26c8dc subs r2, r3, #125 */
/* @0x26c8e0 rsbs r3, r2, #0 */
/* @0x26c8e4 adcs r3, r3, r2 */
/* @0x26c8e8 eors r3, r3, r0, lsr #31 */
/* @0x26c8ec beq 0x26d8a4 <pcre_compile+0x491c> */
/* @0x26c8f0 ldr r6, [sp, #0x30] */
/* @0x26c8f4 add r2, r8, #1 */
/* @0x26c8f8 cmp r8, r6 */
/* @0x26c8fc bge 0x2691dc <pcre_compile+0x254> */
/* @0x26c900 ldr r9, [sp, #0x24] */
/* @0x26c904 add r3, r4, #3 */
/* @0x26c908 ldr r7, [sp, #0x3c] */
/* @0x26c90c mov r8, r2 */
/* @0x26c910 add r9, r9, #12 */
/* @0x26c914 rsb r3, r7, r3 */
/* @0x26c918 str r3, [r9, #-0xc] */
/* @0x26c91c mov r3, #0 */
/* @0x26c920 str r3, [r9, #-0x8] */
/* @0x26c924 str r9, [sp, #0x24] */
/* @0x26c928 b 0x26b198 <pcre_compile+0x2210> */
/* @0x26c92c ldr r2, [r9, #0x4] */
/* @0x26c930 ldr r4, [sp, #0x38] */
/* @0x26c934 cmp r4, r2 */
/* @0x26c938 bhi 0x26d8dc <pcre_compile+0x4954> */
/* @0x26c93c add r5, r5, #1 */
/* @0x26c940 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c944 ldr r6, [sp, #0x34] */
/* @0x26c948 movw r3, #0x202f */
/* @0x26c94c cmp r6, r3 */
/* @0x26c950 beq 0x26c970 <pcre_compile+0x39e8> */
/* @0x26c954 bls 0x26de38 <pcre_compile+0x4eb0> */
/* @0x26c958 ldr r9, [sp, #0x34] */
/* @0x26c95c movw r3, #0x205f */
/* @0x26c960 cmp r9, r3 */
/* @0x26c964 beq 0x26c970 <pcre_compile+0x39e8> */
/* @0x26c968 cmp r9, #12288 */
/* @0x26c96c bne 0x26a880 <pcre_compile+0x18f8> */
/* @0x26c970 add r5, r5, #1 */
/* @0x26c974 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c978 cmp r9, #32 */
/* @0x26c97c beq 0x26a80c <pcre_compile+0x1884> */
/* @0x26c980 bls 0x26d9ac <pcre_compile+0x4a24> */
/* @0x26c984 ldr r4, [sp, #0x34] */
/* @0x26c988 cmp r4, #160 */
/* @0x26c98c beq 0x26a80c <pcre_compile+0x1884> */
/* @0x26c990 cmp r4, #5760 */
/* @0x26c994 beq 0x26a80c <pcre_compile+0x1884> */
/* @0x26c998 add r5, r5, #1 */
/* @0x26c99c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c9a0 ldr r9, [sp, #0x30] */
/* @0x26c9a4 add r2, r11, #1 */
/* @0x26c9a8 cmp r11, r9 */
/* @0x26c9ac bge 0x2691dc <pcre_compile+0x254> */
/* @0x26c9b0 str r7, [r12] */
/* @0x26c9b4 add r5, r5, #1 */
/* @0x26c9b8 str r3, [r12, #0x4] */
/* @0x26c9bc mov r11, r2 */
/* @0x26c9c0 add r12, r12, #12 */
/* @0x26c9c4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c9c8 ldr r7, [sp, #0x30] */
/* @0x26c9cc cmp r8, r7 */
/* @0x26c9d0 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26c9d4 ldr r9, [sp, #0x24] */
/* @0x26c9d8 add r8, r8, #1 */
/* @0x26c9dc add r5, r5, #1 */
/* @0x26c9e0 add r9, r9, #12 */
/* @0x26c9e4 str r6, [r9, #-0xc] */
/* @0x26c9e8 str r3, [r9, #-0x8] */
/* @0x26c9ec str r9, [sp, #0x24] */
/* @0x26c9f0 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26c9f4 ldr r4, [sp, #0x78] */
/* @0x26c9f8 ldrb r2, [r4, r6] */
/* @0x26c9fc ubfx r2, r2, #0x4, #0x1 */
/* @0x26ca00 b 0x26c3ac <pcre_compile+0x3424> */
/* @0x26ca04 ldr r4, [sp, #0x30] */
/* @0x26ca08 add r3, r11, #1 */
/* @0x26ca0c cmp r11, r4 */
/* @0x26ca10 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26ca14 str r7, [r12] */
/* @0x26ca18 add r5, r5, #1 */
/* @0x26ca1c str r2, [r12, #0x4] */
/* @0x26ca20 mov r11, r3 */
/* @0x26ca24 add r12, r12, #12 */
/* @0x26ca28 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26ca2c ldr r6, [sp, #0x88] */
/* @0x26ca30 ldrb r1, [r6, r7] */
/* @0x26ca34 b 0x26a1e0 <pcre_compile+0x1258> */
/* @0x26ca38 ldr r4, [sp, #0x88] */
/* @0x26ca3c ldrb r1, [r4, r6] */
/* @0x26ca40 b 0x26a064 <pcre_compile+0x10dc> */
/* @0x26ca44 bic r3, r0, #2 */
/* @0x26ca48 cmp r3, #9 */
/* @0x26ca4c bne 0x26ba98 <pcre_compile+0x2b10> */
/* @0x26ca50 add r5, r5, #1 */
/* @0x26ca54 mov r8, r4 */
/* @0x26ca58 str r6, [sp, #0x24] */
/* @0x26ca5c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26ca60 ldr r6, [sp, #0x88] */
/* @0x26ca64 ldrb r3, [r6, r4] */
/* @0x26ca68 b 0x26ace8 <pcre_compile+0x1d60> */
/* @0x26ca6c ldr r2, [pc, #-0x668] */
/* @0x26ca70 ldr r4, [sp, #0x78] */
/* @0x26ca74 add r2, pc, r2 */
/* @0x26ca78 add r9, r2, r9 */
/* @0x26ca7c ldrb r3, [r4, r6] */
/* @0x26ca80 ldrb r1, [r9, #-0xc44] */
/* @0x26ca84 ldrb r2, [r9, #-0xc34] */
/* @0x26ca88 and r3, r1, r3 */
/* @0x26ca8c cmp r2, r3 */
/* @0x26ca90 addeq r5, r5, #1 */
/* @0x26ca94 bne 0x26ab18 <pcre_compile+0x1b90> */
/* @0x26ca98 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26ca9c ldr r2, [r6, #0x8] */
/* @0x26caa0 ldr r9, [sp, #0x38] */
/* @0x26caa4 cmp r9, r2 */
/* @0x26caa8 movhs r0, #1 */
/* @0x26caac bhs 0x26cad4 <pcre_compile+0x3b4c> */
/* @0x26cab0 ldr r4, [sp, #0x48] */
/* @0x26cab4 mov r0, r9 */
/* @0x26cab8 add r3, r6, #36 */
/* @0x26cabc str r12, [sp, #0x1c] */
/* @0x26cac0 str r4, [sp] */
/* @0x26cac4 bl 0x25f9fc <_pcre_is_newline> */
/* @0x26cac8 ldr r12, [sp, #0x1c] */
/* @0x26cacc rsbs r0, r0, #1 */
/* @0x26cad0 movlo r0, #0 */
/* @0x26cad4 mov r3, r0 */
/* @0x26cad8 b 0x26a9fc <pcre_compile+0x1a74> */
/* @0x26cadc bic r3, r6, #2 */
/* @0x26cae0 cmp r3, #9 */
/* @0x26cae4 addeq r5, r5, #1 */
/* @0x26cae8 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26caec b 0x26b984 <pcre_compile+0x29fc> */
/* @0x26caf0 bic r3, r0, #2 */
/* @0x26caf4 cmp r3, #9 */
/* @0x26caf8 bne 0x26b888 <pcre_compile+0x2900> */
/* @0x26cafc add r5, r5, #1 */
/* @0x26cb00 mov r8, r4 */
/* @0x26cb04 str r6, [sp, #0x24] */
/* @0x26cb08 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cb0c bic r3, r0, #2 */
/* @0x26cb10 cmp r3, #9 */
/* @0x26cb14 bne 0x26b764 <pcre_compile+0x27dc> */
/* @0x26cb18 ldr r4, [sp, #0x7c] */
/* @0x26cb1c add r5, r5, #1 */
/* @0x26cb20 ldr r8, [sp, #0x60] */
/* @0x26cb24 str r4, [sp, #0x24] */
/* @0x26cb28 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cb2c bic r3, r9, #2 */
/* @0x26cb30 cmp r3, #9 */
/* @0x26cb34 addeq r5, r5, #1 */
/* @0x26cb38 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26cb3c b 0x26bbe8 <pcre_compile+0x2c60> */
/* @0x26cb40 sub r3, r6, #10 */
/* @0x26cb44 cmp r3, #3 */
/* @0x26cb48 bls 0x26a78c <pcre_compile+0x1804> */
/* @0x26cb4c add r5, r5, #1 */
/* @0x26cb50 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cb54 mov r6, #1 */
/* @0x26cb58 add r5, r5, #1 */
/* @0x26cb5c str r6, [sp, #0x44] */
/* @0x26cb60 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cb64 mov r4, #1 */
/* @0x26cb68 add r5, r5, #1 */
/* @0x26cb6c str r4, [sp, #0x44] */
/* @0x26cb70 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cb74 sub r1, r4, #8192 */
/* @0x26cb78 cmp r1, #10 */
/* @0x26cb7c bls 0x26b218 <pcre_compile+0x2290> */
/* @0x26cb80 mov r1, #0 */
/* @0x26cb84 b 0x26b21c <pcre_compile+0x2294> */
/* @0x26cb88 tst r3, #134217728 */
/* @0x26cb8c bne 0x26dd0c <pcre_compile+0x4d84> */
/* @0x26cb90 ldr r6, [sp, #0x30] */
/* @0x26cb94 add r3, r8, #1 */
/* @0x26cb98 cmp r8, r6 */
/* @0x26cb9c bge 0x2691dc <pcre_compile+0x254> */
/* @0x26cba0 ldr r9, [sp, #0x24] */
/* @0x26cba4 add r7, r7, #1 */
/* @0x26cba8 mov r8, r3 */
/* @0x26cbac add r5, r5, #1 */
/* @0x26cbb0 mov r3, #0 */
/* @0x26cbb4 add r9, r9, #12 */
/* @0x26cbb8 str r7, [r9, #-0xc] */
/* @0x26cbbc str r3, [r9, #-0x8] */
/* @0x26cbc0 str r9, [sp, #0x24] */
/* @0x26cbc4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cbc8 tst r3, #134217728 */
/* @0x26cbcc bne 0x26d968 <pcre_compile+0x49e0> */
/* @0x26cbd0 ldr r9, [sp, #0x30] */
/* @0x26cbd4 add r3, r8, #1 */
/* @0x26cbd8 cmp r8, r9 */
/* @0x26cbdc bge 0x2691dc <pcre_compile+0x254> */
/* @0x26cbe0 ldr r4, [sp, #0x24] */
/* @0x26cbe4 add r7, r7, #1 */
/* @0x26cbe8 mov r8, r3 */
/* @0x26cbec add r5, r5, #1 */
/* @0x26cbf0 mov r3, #0 */
/* @0x26cbf4 add r4, r4, #12 */
/* @0x26cbf8 str r7, [r4, #-0xc] */
/* @0x26cbfc str r3, [r4, #-0x8] */
/* @0x26cc00 str r4, [sp, #0x24] */
/* @0x26cc04 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cc08 sub r2, r4, #10 */
/* @0x26cc0c cmp r2, #3 */
/* @0x26cc10 bhi 0x26a474 <pcre_compile+0x14ec> */
/* @0x26cc14 mov r2, #1 */
/* @0x26cc18 b 0x26a478 <pcre_compile+0x14f0> */
/* @0x26cc1c ldr r6, [sp, #0x34] */
/* @0x26cc20 sub r2, r6, #8192 */
/* @0x26cc24 sub r2, r2, #40 */
/* @0x26cc28 cmp r2, #1 */
/* @0x26cc2c bhi 0x26a2ec <pcre_compile+0x1364> */
/* @0x26cc30 mov r2, #1 */
/* @0x26cc34 b 0x26a2f0 <pcre_compile+0x1368> */
/* @0x26cc38 subs r4, r9, #111 */
/* @0x26cc3c rsbs r0, r4, #0 */
/* @0x26cc40 adcs r0, r0, r4 */
/* @0x26cc44 b 0x26bb18 <pcre_compile+0x2b90> */
/* @0x26cc48 ldr r6, [sp, #0x34] */
/* @0x26cc4c cmp r6, #133 */
/* @0x26cc50 beq 0x26cc68 <pcre_compile+0x3ce0> */
/* @0x26cc54 blo 0x26d510 <pcre_compile+0x4588> */
/* @0x26cc58 sub r1, r6, #8192 */
/* @0x26cc5c sub r1, r1, #40 */
/* @0x26cc60 cmp r1, #1 */
/* @0x26cc64 bhi 0x26d510 <pcre_compile+0x4588> */
/* @0x26cc68 ldr r6, [sp, #0x28] */
/* @0x26cc6c ldr r1, [r6, #0x18] */
/* @0x26cc70 ands r1, r1, #8388608 */
/* @0x26cc74 addne r5, r5, #1 */
/* @0x26cc78 movne r8, r3 */
/* @0x26cc7c bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26cc80 mov r6, r1 */
/* @0x26cc84 b 0x26b2b0 <pcre_compile+0x2328> */
/* @0x26cc88 cmp r4, #9 */
/* @0x26cc8c bne 0x26cb80 <pcre_compile+0x3bf8> */
/* @0x26cc90 b 0x26b218 <pcre_compile+0x2290> */
/* @0x26cc94 ldr r4, [sp, #0x34] */
/* @0x26cc98 cmp r4, #133 */
/* @0x26cc9c beq 0x26ccb4 <pcre_compile+0x3d2c> */
/* @0x26cca0 blo 0x26de58 <pcre_compile+0x4ed0> */
/* @0x26cca4 sub r3, r4, #8192 */
/* @0x26cca8 sub r3, r3, #40 */
/* @0x26ccac cmp r3, #1 */
/* @0x26ccb0 bhi 0x26de58 <pcre_compile+0x4ed0> */
/* @0x26ccb4 ldr r6, [sp, #0x28] */
/* @0x26ccb8 ldr r3, [r6, #0x18] */
/* @0x26ccbc ands r3, r3, #8388608 */
/* @0x26ccc0 addne r5, r5, #1 */
/* @0x26ccc4 movne r8, r0 */
/* @0x26ccc8 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26cccc b 0x26b438 <pcre_compile+0x24b0> */
/* @0x26ccd0 ldr r6, [sp, #0x34] */
/* @0x26ccd4 cmp r6, #133 */
/* @0x26ccd8 beq 0x26ccf0 <pcre_compile+0x3d68> */
/* @0x26ccdc blo 0x26d960 <pcre_compile+0x49d8> */
/* @0x26cce0 sub r3, r6, #8192 */
/* @0x26cce4 sub r3, r3, #40 */
/* @0x26cce8 cmp r3, #1 */
/* @0x26ccec bhi 0x26d960 <pcre_compile+0x49d8> */
/* @0x26ccf0 ldr r9, [sp, #0x28] */
/* @0x26ccf4 ldr r3, [r9, #0x18] */
/* @0x26ccf8 tst r3, #8388608 */
/* @0x26ccfc addne r5, r5, #1 */
/* @0x26cd00 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26cd04 b 0x26a93c <pcre_compile+0x19b4> */
/* @0x26cd08 blo 0x26d134 <pcre_compile+0x41ac> */
/* @0x26cd0c ldr r6, [sp, #0x28] */
/* @0x26cd10 ldr r3, [r6, #0x18] */
/* @0x26cd14 ands r3, r3, #8388608 */
/* @0x26cd18 beq 0x26b370 <pcre_compile+0x23e8> */
/* @0x26cd1c add r5, r5, #1 */
/* @0x26cd20 mov r8, r1 */
/* @0x26cd24 str r2, [sp, #0x24] */
/* @0x26cd28 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cd2c ldr r6, [sp, #0x74] */
/* @0x26cd30 ldr r4, [sp, #0x2c] */
/* @0x26cd34 ldr r9, [sp, #0x34] */
/* @0x26cd38 ldrb r3, [r6, r4] */
/* @0x26cd3c ldrb r2, [r6, r9] */
/* @0x26cd40 cmp r2, r3 */
/* @0x26cd44 addne r5, r5, #1 */
/* @0x26cd48 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26cd4c ldr r4, [sp, #0x30] */
/* @0x26cd50 add r3, r11, #1 */
/* @0x26cd54 cmp r11, r4 */
/* @0x26cd58 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26cd5c ldr r6, [sp, #0x48] */
/* @0x26cd60 add r7, r7, #2 */
/* @0x26cd64 add r5, r5, #1 */
/* @0x26cd68 str r7, [r12] */
/* @0x26cd6c mov r11, r3 */
/* @0x26cd70 add r12, r12, #12 */
/* @0x26cd74 str r6, [r12, #-0x8] */
/* @0x26cd78 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cd7c sub r3, r4, #10 */
/* @0x26cd80 cmp r3, #3 */
/* @0x26cd84 bhi 0x26a8e4 <pcre_compile+0x195c> */
/* @0x26cd88 add r5, r5, #1 */
/* @0x26cd8c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cd90 ldr r4, [sp, #0x38] */
/* @0x26cd94 ldrb r0, [r4, #-0x1] */
/* @0x26cd98 and r2, r0, #192 */
/* @0x26cd9c cmp r2, #128 */
/* @0x26cda0 bne 0x26ab84 <pcre_compile+0x1bfc> */
/* @0x26cda4 sub r2, r4, #2 */
/* @0x26cda8 mov r3, r2 */
/* @0x26cdac sub r2, r2, #1 */
/* @0x26cdb0 ldrb r0, [r3] */
/* @0x26cdb4 and r1, r0, #192 */
/* @0x26cdb8 cmp r1, #128 */
/* @0x26cdbc beq 0x26cda8 <pcre_compile+0x3e20> */
/* @0x26cdc0 b 0x26ab84 <pcre_compile+0x1bfc> */
/* @0x26cdc4 ldr r9, [sp, #0x2c] */
/* @0x26cdc8 ldr r4, [r6, #0x4] */
/* @0x26cdcc ldrb r2, [r9, #0x1] */
/* @0x26cdd0 ldrb r3, [r9, #0x2] */
/* @0x26cdd4 orr r3, r3, r2, lsl #8 */
/* @0x26cdd8 cmp r4, r3 */
/* @0x26cddc blt 0x26ce10 <pcre_compile+0x3e88> */
/* @0x26cde0 ldr r6, [sp, #0x30] */
/* @0x26cde4 add r3, r8, #1 */
/* @0x26cde8 cmp r8, r6 */
/* @0x26cdec bge 0x2691dc <pcre_compile+0x254> */
/* @0x26cdf0 ldr r9, [sp, #0x24] */
/* @0x26cdf4 mov r8, r3 */
/* @0x26cdf8 add r2, r1, #5 */
/* @0x26cdfc add r9, r9, #12 */
/* @0x26ce00 str r2, [r9, #-0xc] */
/* @0x26ce04 mov r2, #0 */
/* @0x26ce08 str r2, [r9, #-0x8] */
/* @0x26ce0c str r9, [sp, #0x24] */
/* @0x26ce10 cmp r0, #0 */
/* @0x26ce14 addeq r5, r5, #1 */
/* @0x26ce18 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26ce1c ldr r6, [sp, #0x2c] */
/* @0x26ce20 ldrb r3, [r6] */
/* @0x26ce24 ldrb r2, [r6, #0x3] */
/* @0x26ce28 cmp r3, #109 */
/* @0x26ce2c ldrb r3, [r6, #0x4] */
/* @0x26ce30 orr r3, r3, r2, lsl #8 */
/* @0x26ce34 beq 0x26e040 <pcre_compile+0x50b8> */
/* @0x26ce38 add r2, r4, #1 */
/* @0x26ce3c cmp r3, r2 */
/* @0x26ce40 bgt 0x26e018 <pcre_compile+0x5090> */
/* @0x26ce44 cmp r3, #0 */
/* @0x26ce48 beq 0x26e018 <pcre_compile+0x5090> */
/* @0x26ce4c ldr r4, [sp, #0x30] */
/* @0x26ce50 add r3, r11, #1 */
/* @0x26ce54 cmp r11, r4 */
/* @0x26ce58 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26ce5c add r1, r1, #5 */
/* @0x26ce60 mov r11, r3 */
/* @0x26ce64 str r1, [r12] */
/* @0x26ce68 mov r3, #0 */
/* @0x26ce6c add r5, r5, #1 */
/* @0x26ce70 str r3, [r12, #0x4] */
/* @0x26ce74 add r12, r12, #12 */
/* @0x26ce78 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26ce7c ldr r7, [sp, #0x30] */
/* @0x26ce80 add r6, r8, #1 */
/* @0x26ce84 cmp r8, r7 */
/* @0x26ce88 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26ce8c ldr r9, [sp, #0x24] */
/* @0x26ce90 cmp r0, #0 */
/* @0x26ce94 add r1, r1, #1 */
/* @0x26ce98 mov r4, #0 */
/* @0x26ce9c add r3, r9, #12 */
/* @0x26cea0 stm r9, {r1, r4} */
/* @0x26cea4 bne 0x26ddf4 <pcre_compile+0x4e6c> */
/* @0x26cea8 add r5, r5, #1 */
/* @0x26ceac mov r8, r6 */
/* @0x26ceb0 str r3, [sp, #0x24] */
/* @0x26ceb4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26ceb8 ldr r4, [r6, #0x4] */
/* @0x26cebc cmp r4, #0 */
/* @0x26cec0 ble 0x26dfa0 <pcre_compile+0x5018> */
/* @0x26cec4 ldr r6, [sp, #0x30] */
/* @0x26cec8 add r3, r8, #1 */
/* @0x26cecc cmp r8, r6 */
/* @0x26ced0 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26ced4 ldr r9, [sp, #0x24] */
/* @0x26ced8 cmp r0, #0 */
/* @0x26cedc mov r2, #0 */
/* @0x26cee0 add r1, r1, #1 */
/* @0x26cee4 stm r9, {r1, r2} */
/* @0x26cee8 add r2, r9, #12 */
/* @0x26ceec beq 0x26dd28 <pcre_compile+0x4da0> */
/* @0x26cef0 ldr r6, [sp, #0x2c] */
/* @0x26cef4 ldr r9, [sp, #0x24] */
/* @0x26cef8 ldrb r1, [r6] */
/* @0x26cefc cmp r1, #107 */
/* @0x26cf00 movne r8, r3 */
/* @0x26cf04 movne r9, r2 */
/* @0x26cf08 str r9, [sp, #0x24] */
/* @0x26cf0c ldr r6, [sp, #0x30] */
/* @0x26cf10 add r2, r4, #1 */
/* @0x26cf14 add r3, r11, #1 */
/* @0x26cf18 cmp r11, r6 */
/* @0x26cf1c bge 0x2691dc <pcre_compile+0x254> */
/* @0x26cf20 str r7, [r12] */
/* @0x26cf24 add r5, r5, #1 */
/* @0x26cf28 str r2, [r12, #0x4] */
/* @0x26cf2c mov r11, r3 */
/* @0x26cf30 add r12, r12, #12 */
/* @0x26cf34 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cf38 ldr r4, [sp, #0x30] */
/* @0x26cf3c add r3, r8, #1 */
/* @0x26cf40 cmp r8, r4 */
/* @0x26cf44 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26cf48 ldr r6, [sp, #0x24] */
/* @0x26cf4c cmp r0, #0 */
/* @0x26cf50 add r1, r1, #1 */
/* @0x26cf54 mov r4, #0 */
/* @0x26cf58 add r2, r6, #12 */
/* @0x26cf5c stm r6, {r1, r4} */
/* @0x26cf60 bne 0x26de64 <pcre_compile+0x4edc> */
/* @0x26cf64 add r5, r5, #1 */
/* @0x26cf68 mov r8, r3 */
/* @0x26cf6c str r2, [sp, #0x24] */
/* @0x26cf70 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cf74 movw r1, #0x1da */
/* @0x26cf78 cmp r9, r1 */
/* @0x26cf7c cmpne r9, #476 */
/* @0x26cf80 ldr r4, [sp, #0x30] */
/* @0x26cf84 add r1, r11, #1 */
/* @0x26cf88 movne r9, #0 */
/* @0x26cf8c moveq r9, #1 */
/* @0x26cf90 cmp r9, #0 */
/* @0x26cf94 ldr r9, [sp, #0x24] */
/* @0x26cf98 moveq r8, r2 */
/* @0x26cf9c moveq r9, r3 */
/* @0x26cfa0 cmp r11, r4 */
/* @0x26cfa4 str r9, [sp, #0x24] */
/* @0x26cfa8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26cfac add r3, r7, r0 */
/* @0x26cfb0 add r5, r5, #1 */
/* @0x26cfb4 rsb r3, r3, #0 */
/* @0x26cfb8 mov r11, r1 */
/* @0x26cfbc str r3, [r12] */
/* @0x26cfc0 mov r3, #0 */
/* @0x26cfc4 add r12, r12, #12 */
/* @0x26cfc8 str r3, [r12, #-0x8] */
/* @0x26cfcc str r3, [r12, #-0x4] */
/* @0x26cfd0 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26cfd4 ldr r4, [sp, #0x28] */
/* @0x26cfd8 ldr r1, [r4, #0x20] */
/* @0x26cfdc cmp r1, #0 */
/* @0x26cfe0 beq 0x26d408 <pcre_compile+0x4480> */
/* @0x26cfe4 ldr r2, [r4, #0x8] */
/* @0x26cfe8 ldr r6, [sp, #0x38] */
/* @0x26cfec cmp r6, r2 */
/* @0x26cff0 movhs r0, #0 */
/* @0x26cff4 blo 0x26e4cc <pcre_compile+0x5544> */
/* @0x26cff8 mov r3, r0 */
/* @0x26cffc cmp r3, #0 */
/* @0x26d000 addeq r5, r5, #1 */
/* @0x26d004 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26d008 ldr r9, [sp, #0x30] */
/* @0x26d00c add r3, r8, #1 */
/* @0x26d010 cmp r8, r9 */
/* @0x26d014 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26d018 ldr r4, [sp, #0x24] */
/* @0x26d01c add r7, r7, #1 */
/* @0x26d020 mov r8, r3 */
/* @0x26d024 add r5, r5, #1 */
/* @0x26d028 mov r3, #0 */
/* @0x26d02c add r4, r4, #12 */
/* @0x26d030 str r7, [r4, #-0xc] */
/* @0x26d034 str r3, [r4, #-0x8] */
/* @0x26d038 str r4, [sp, #0x24] */
/* @0x26d03c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d040 ldr r1, [r9, #0x20] */
/* @0x26d044 cmp r1, #0 */
/* @0x26d048 beq 0x26d794 <pcre_compile+0x480c> */
/* @0x26d04c ldr r2, [r9, #0x8] */
/* @0x26d050 ldr r4, [sp, #0x38] */
/* @0x26d054 cmp r4, r2 */
/* @0x26d058 blo 0x26e180 <pcre_compile+0x51f8> */
/* @0x26d05c add r5, r5, #1 */
/* @0x26d060 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d064 ldr r7, [sp, #0x30] */
/* @0x26d068 cmp r7, r8 */
/* @0x26d06c ble 0x2691dc <pcre_compile+0x254> */
/* @0x26d070 ldr r7, [sp, #0x24] */
/* @0x26d074 add r8, r8, #1 */
/* @0x26d078 ldr r0, [sp, #0x2c] */
/* @0x26d07c add r7, r7, #12 */
/* @0x26d080 str r0, [r7, #-0xc] */
/* @0x26d084 mov r0, #0 */
/* @0x26d088 str r0, [r7, #-0x8] */
/* @0x26d08c str r7, [sp, #0x24] */
/* @0x26d090 b 0x26c544 <pcre_compile+0x35bc> */
/* @0x26d094 str r4, [sp, #0x60] */
/* @0x26d098 mov r4, r5 */
/* @0x26d09c ldr r10, [sp, #0xb0] */
/* @0x26d0a0 ldr r12, [sp, #0xb4] */
/* @0x26d0a4 ldr r8, [sp, #0xb8] */
/* @0x26d0a8 ldr r11, [sp, #0xbc] */
/* @0x26d0ac ldr r5, [sp, #0xc0] */
/* @0x26d0b0 b 0x26bfe0 <pcre_compile+0x3058> */
/* @0x26d0b4 movw r1, #0x1c6 */
/* @0x26d0b8 cmp r9, r1 */
/* @0x26d0bc cmpne r9, #456 */
/* @0x26d0c0 ldr r4, [sp, #0x30] */
/* @0x26d0c4 add r1, r11, #1 */
/* @0x26d0c8 movne r9, #0 */
/* @0x26d0cc moveq r9, #1 */
/* @0x26d0d0 cmp r9, #0 */
/* @0x26d0d4 ldr r9, [sp, #0x24] */
/* @0x26d0d8 moveq r8, r2 */
/* @0x26d0dc moveq r9, r3 */
/* @0x26d0e0 cmp r11, r4 */
/* @0x26d0e4 str r9, [sp, #0x24] */
/* @0x26d0e8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26d0ec add r3, r7, r0 */
/* @0x26d0f0 add r5, r5, #1 */
/* @0x26d0f4 rsb r3, r3, #0 */
/* @0x26d0f8 mov r11, r1 */
/* @0x26d0fc str r3, [r12] */
/* @0x26d100 mov r3, #0 */
/* @0x26d104 add r12, r12, #12 */
/* @0x26d108 str r3, [r12, #-0x8] */
/* @0x26d10c str r3, [r12, #-0x4] */
/* @0x26d110 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d114 ldr r6, [sp, #0x34] */
/* @0x26d118 cmp r6, #133 */
/* @0x26d11c beq 0x26cd0c <pcre_compile+0x3d84> */
/* @0x26d120 blo 0x26d134 <pcre_compile+0x41ac> */
/* @0x26d124 sub r3, r6, #8192 */
/* @0x26d128 sub r3, r3, #40 */
/* @0x26d12c cmp r3, #1 */
/* @0x26d130 bls 0x26cd0c <pcre_compile+0x3d84> */
/* @0x26d134 add r5, r5, #1 */
/* @0x26d138 mov r8, r1 */
/* @0x26d13c str r2, [sp, #0x24] */
/* @0x26d140 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d144 ldr r6, [sp, #0x38] */
/* @0x26d148 add r0, r6, #1 */
/* @0x26d14c ldr r6, [sp, #0x68] */
/* @0x26d150 cmp r6, r0 */
/* @0x26d154 bls 0x26b370 <pcre_compile+0x23e8> */
/* @0x26d158 ldr r6, [sp, #0x38] */
/* @0x26d15c ldrb r3, [r6, #0x1] */
/* @0x26d160 subs r0, r3, #10 */
/* @0x26d164 rsbs r3, r0, #0 */
/* @0x26d168 adcs r3, r3, r0 */
/* @0x26d16c b 0x26b370 <pcre_compile+0x23e8> */
/* @0x26d170 ldr r3, [pc, #-0xd68] */
/* @0x26d174 ldr r3, [pc, r3] */
/* @0x26d178 ldr r3, [r3] */
/* @0x26d17c cmp r3, #0 */
/* @0x26d180 beq 0x26d240 <pcre_compile+0x42b8> */
/* @0x26d184 add r6, sp, #8192 */
/* @0x26d188 mov r2, #1 */
/* @0x26d18c ldr r9, [sp, #0x68] */
/* @0x26d190 str r2, [r6, #-0xf88] */
/* @0x26d194 ldr r6, [sp, #0x54] */
/* @0x26d198 ldrb r0, [r4, #0x4] */
/* @0x26d19c rsb r1, r6, r9 */
/* @0x26d1a0 add r9, sp, #8192 */
/* @0x26d1a4 ldr lr, [r9, #0x40] */
/* @0x26d1a8 str lr, [r9, #-0xf80] */
/* @0x26d1ac ldr r9, [sp, #0x5c] */
/* @0x26d1b0 rsb lr, r6, r9 */
/* @0x26d1b4 add r9, sp, #8192 */
/* @0x26d1b8 str r6, [r9, #-0xf7c] */
/* @0x26d1bc str r0, [r9, #-0xf84] */
/* @0x26d1c0 ldr r9, [sp, #0x38] */
/* @0x26d1c4 rsb r0, r6, r9 */
/* @0x26d1c8 add r6, sp, #8192 */
/* @0x26d1cc str r1, [r6, #-0xf78] */
/* @0x26d1d0 mvn r1, #0 */
/* @0x26d1d4 str lr, [r6, #-0xf74] */
/* @0x26d1d8 mov lr, #0 */
/* @0x26d1dc str r0, [r6, #-0xf70] */
/* @0x26d1e0 ldrb r9, [r4, #0x5] */
/* @0x26d1e4 ldrb r0, [r4, #0x6] */
/* @0x26d1e8 orr r0, r0, r9, lsl #8 */
/* @0x26d1ec str r0, [r6, #-0xf60] */
/* @0x26d1f0 ldrb r9, [r4, #0x7] */
/* @0x26d1f4 ldrb r0, [r4, #0x8] */
/* @0x26d1f8 str r2, [r6, #-0xf6c] */
/* @0x26d1fc ldr r2, [sp, #0x28] */
/* @0x26d200 ldr r6, [r2, #0x2c] */
/* @0x26d204 orr r2, r0, r9, lsl #8 */
/* @0x26d208 add r9, sp, #8192 */
/* @0x26d20c add r0, sp, #4160 */
/* @0x26d210 add r0, r0, #56 */
/* @0x26d214 str r1, [r9, #-0xf68] */
/* @0x26d218 str r2, [r9, #-0xf5c] */
/* @0x26d21c str r6, [r9, #-0xf64] */
/* @0x26d220 str lr, [r9, #-0xf58] */
/* @0x26d224 str r12, [sp, #0x1c] */
/* @0x26d228 blx r3 —— blx r3 钩子调用 #2（同一 5 字上下文协议） */
/* @0x26d22c ldr r12, [sp, #0x1c] */
/* @0x26d230 cmp r0, #0 */
/* @0x26d234 blt 0x2691e0 <pcre_compile+0x258> */
/* @0x26d238 addne r5, r5, #1 */
/* @0x26d23c bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26d240 ldrb r9, [r4, #0x9] */
/* @0x26d244 add r4, r4, #6 */
/* @0x26d248 b 0x26b12c <pcre_compile+0x21a4> */
/* @0x26d24c ldr r0, [sp, #0x40] */
/* @0x26d250 b 0x26bb18 <pcre_compile+0x2b90> */
/* @0x26d254 ldrb r2, [r4, #0x1] */
/* @0x26d258 ldr r9, [sp, #0x40] */
/* @0x26d25c ldrb r3, [r4, #0x2] */
/* @0x26d260 cmp r9, #0 */
/* @0x26d264 orr r3, r3, r2, lsl #8 */
/* @0x26d268 add r3, r4, r3 */
/* @0x26d26c str r3, [sp, #0x2c] */
/* @0x26d270 beq 0x26d24c <pcre_compile+0x42c4> */
/* @0x26d274 add r1, r4, #3 */
/* @0x26d278 ldr r0, [sp, #0x34] */
/* @0x26d27c ldr r2, [sp, #0x48] */
/* @0x26d280 str r12, [sp, #0x1c] */
/* @0x26d284 bl 0x266cac <_pcre_xclass> —— _pcre_xclass：\p{...} 扩展类 */
/* @0x26d288 ldr r12, [sp, #0x1c] */
/* @0x26d28c b 0x26bb18 <pcre_compile+0x2b90> */
/* @0x26d290 add r9, r9, #12 */
/* @0x26d294 add r5, r5, #1 */
/* @0x26d298 str r9, [sp, #0x24] */
/* @0x26d29c mov r8, r2 */
/* @0x26d2a0 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d2a4 mov r0, r8 */
/* @0x26d2a8 b 0x26b408 <pcre_compile+0x2480> */
/* @0x26d2ac add r5, r5, #1 */
/* @0x26d2b0 ldr r8, [sp, #0x60] */
/* @0x26d2b4 str r2, [sp, #0x24] */
/* @0x26d2b8 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d2bc ldr r2, [sp, #0x40] */
/* @0x26d2c0 b 0x26c3ac <pcre_compile+0x3424> */
/* @0x26d2c4 ldr r6, [sp, #0x48] */
/* @0x26d2c8 ldr r9, [sp, #0x38] */
/* @0x26d2cc cmp r6, #0 */
/* @0x26d2d0 rsb r3, r9, r7 */
/* @0x26d2d4 beq 0x26d2fc <pcre_compile+0x4374> */
/* @0x26d2d8 cmp r9, r7 */
/* @0x26d2dc bhs 0x26d2fc <pcre_compile+0x4374> */
/* @0x26d2e0 mov r2, r9 */
/* @0x26d2e4 ldrb r1, [r2], #1 */
/* @0x26d2e8 and r1, r1, #192 */
/* @0x26d2ec cmp r1, #128 */
/* @0x26d2f0 subeq r3, r3, #1 */
/* @0x26d2f4 cmp r2, r7 */
/* @0x26d2f8 bne 0x26d2e4 <pcre_compile+0x435c> */
/* @0x26d2fc ldr r6, [sp, #0x30] */
/* @0x26d300 add r2, r11, #1 */
/* @0x26d304 cmp r11, r6 */
/* @0x26d308 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26d30c sub r3, r3, #1 */
/* @0x26d310 rsb r4, r4, #0 */
/* @0x26d314 str r3, [r12, #0x8] */
/* @0x26d318 mov r11, r2 */
/* @0x26d31c str r4, [r12] */
/* @0x26d320 mov r3, #0 */
/* @0x26d324 add r12, r12, #12 */
/* @0x26d328 str r3, [r12, #-0x8] */
/* @0x26d32c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d330 ldr r9, [sp, #0x30] */
/* @0x26d334 add r8, r8, #2 */
/* @0x26d338 cmp r9, r2 */
/* @0x26d33c ble 0x2691dc <pcre_compile+0x254> */
/* @0x26d340 ldr r6, [sp, #0x24] */
/* @0x26d344 mov r0, r3 */
/* @0x26d348 add r2, r6, #24 */
/* @0x26d34c add r6, r9, #1 */
/* @0x26d350 ldr r7, [sp, #0x3c] */
/* @0x26d354 str r0, [r2, #-0x8] */
/* @0x26d358 rsb r3, r7, r4 */
/* @0x26d35c str r2, [sp, #0x24] */
/* @0x26d360 add r3, r3, #3 */
/* @0x26d364 str r3, [r2, #-0xc] */
/* @0x26d368 ldrb r1, [r4, #0x1] */
/* @0x26d36c ldrb r3, [r4, #0x2] */
/* @0x26d370 orr r3, r3, r1, lsl #8 */
/* @0x26d374 ldrb r3, [r4, r3]! */
/* @0x26d378 cmp r3, #119 */
/* @0x26d37c beq 0x26d82c <pcre_compile+0x48a4> */
/* @0x26d380 add r5, r5, #1 */
/* @0x26d384 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d388 cmn r0, #1 */
/* @0x26d38c bne 0x2691e0 <pcre_compile+0x258> */
/* @0x26d390 add r5, r5, #1 */
/* @0x26d394 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d398 mov r5, #0 */
/* @0x26d39c str r5, [sp, #0x4c] */
/* @0x26d3a0 str r5, [sp, #0x80] */
/* @0x26d3a4 ldr r6, [sp, #0x44] */
/* @0x26d3a8 ldr r7, [sp, #0x6c] */
/* @0x26d3ac adds r3, r6, #0 */
/* @0x26d3b0 movne r3, #1 */
/* @0x26d3b4 cmp r7, #1 */
/* @0x26d3b8 movne r3, #0 */
/* @0x26d3bc cmp r3, #0 */
/* @0x26d3c0 beq 0x26d400 <pcre_compile+0x4478> */
/* @0x26d3c4 add r9, sp, #8192 */
/* @0x26d3c8 ldr r12, [sp, #0x80] */
/* @0x26d3cc ldr r9, [r9, #0x48] */
/* @0x26d3d0 ldr r3, [r9, #0x4] */
/* @0x26d3d4 cmp r3, r12 */
/* @0x26d3d8 beq 0x26d400 <pcre_compile+0x4478> */
/* @0x26d3dc ldr r4, [sp, #0x28] */
/* @0x26d3e0 ldr r3, [r4, #0x18] */
/* @0x26d3e4 tst r3, #134217728 */
/* @0x26d3e8 bne 0x26e128 <pcre_compile+0x51a0> */
/* @0x26d3ec tst r3, #32768 */
/* @0x26d3f0 beq 0x26d400 <pcre_compile+0x4478> */
/* @0x26d3f4 ldr r5, [sp, #0x70] */
/* @0x26d3f8 cmn r5, #1 */
/* @0x26d3fc beq 0x26e128 <pcre_compile+0x51a0> */
/* @0x26d400 ldr r0, [sp, #0x70] */
/* @0x26d404 b 0x2691e0 <pcre_compile+0x258> */
/* @0x26d408 ldr r4, [sp, #0x28] */
/* @0x26d40c ldr r6, [sp, #0x38] */
/* @0x26d410 ldr r3, [r4, #0x24] */
/* @0x26d414 ldr r2, [r4, #0x8] */
/* @0x26d418 rsb r2, r3, r2 */
/* @0x26d41c cmp r6, r2 */
/* @0x26d420 bhi 0x26d434 <pcre_compile+0x44ac> */
/* @0x26d424 ldrb r0, [r6] */
/* @0x26d428 ldrb r2, [r4, #0x28] */
/* @0x26d42c cmp r0, r2 */
/* @0x26d430 beq 0x26e160 <pcre_compile+0x51d8> */
/* @0x26d434 mov r3, r1 */
/* @0x26d438 b 0x26cffc <pcre_compile+0x4074> */
/* @0x26d43c ldr r0, [sp, #0x48] */
/* @0x26d440 cmp r0, #0 */
/* @0x26d444 beq 0x26d474 <pcre_compile+0x44ec> */
/* @0x26d448 ldr r1, [sp, #0x54] */
/* @0x26d44c add r2, r1, r7 */
/* @0x26d450 add r1, r1, r9 */
/* @0x26d454 cmp r2, r1 */
/* @0x26d458 bhs 0x26d474 <pcre_compile+0x44ec> */
/* @0x26d45c ldrb r0, [r2], #1 */
/* @0x26d460 and r0, r0, #192 */
/* @0x26d464 cmp r0, #128 */
/* @0x26d468 subeq r3, r3, #1 */
/* @0x26d46c cmp r2, r1 */
/* @0x26d470 bne 0x26d45c <pcre_compile+0x44d4> */
/* @0x26d474 ldr r7, [sp, #0x30] */
/* @0x26d478 add r2, r11, #1 */
/* @0x26d47c cmp r11, r7 */
/* @0x26d480 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26d484 cmp r4, #0 */
/* @0x26d488 rsb r1, r6, #0 */
/* @0x26d48c sub r3, r3, #1 */
/* @0x26d490 str r1, [r12] */
/* @0x26d494 str r3, [r12, #0x8] */
/* @0x26d498 mov r1, #0 */
/* @0x26d49c movlt r11, r2 */
/* @0x26d4a0 str r1, [r12, #0x4] */
/* @0x26d4a4 addlt r12, r12, #12 */
/* @0x26d4a8 blt 0x269480 <pcre_compile+0x4f8> */
/* @0x26d4ac ldr r9, [sp, #0x30] */
/* @0x26d4b0 add r11, r11, #2 */
/* @0x26d4b4 cmp r9, r2 */
/* @0x26d4b8 ble 0x2691dc <pcre_compile+0x254> */
/* @0x26d4bc rsb r2, r4, #0 */
/* @0x26d4c0 str r1, [r12, #0x10] */
/* @0x26d4c4 str r2, [r12, #0xc] */
/* @0x26d4c8 add r12, r12, #24 */
/* @0x26d4cc str r3, [r12, #-0x4] */
/* @0x26d4d0 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d4d4 mov r3, r8 */
/* @0x26d4d8 b 0x26b27c <pcre_compile+0x22f4> */
/* @0x26d4dc ldr r9, [sp, #0x30] */
/* @0x26d4e0 cmp r11, r9 */
/* @0x26d4e4 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26d4e8 rsb r7, r7, #0 */
/* @0x26d4ec str r2, [r12, #0x4] */
/* @0x26d4f0 str r7, [r12] */
/* @0x26d4f4 add r11, r11, #1 */
/* @0x26d4f8 str r6, [r12, #0x8] */
/* @0x26d4fc add r5, r5, #1 */
/* @0x26d500 add r12, r12, #12 */
/* @0x26d504 mov r8, r3 */
/* @0x26d508 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d50c bhs 0x26cc68 <pcre_compile+0x3ce0> */
/* @0x26d510 add r5, r5, #1 */
/* @0x26d514 mov r8, r3 */
/* @0x26d518 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d51c ldr r6, [sp, #0x38] */
/* @0x26d520 add r1, r6, #1 */
/* @0x26d524 ldr r6, [sp, #0x68] */
/* @0x26d528 cmp r6, r1 */
/* @0x26d52c bls 0x26b2ac <pcre_compile+0x2324> */
/* @0x26d530 ldr r6, [sp, #0x38] */
/* @0x26d534 ldrb r1, [r6, #0x1] */
/* @0x26d538 subs r8, r1, #10 */
/* @0x26d53c rsbs r6, r8, #0 */
/* @0x26d540 adcs r6, r6, r8 */
/* @0x26d544 b 0x26b2b0 <pcre_compile+0x2328> */
/* @0x26d548 ldr r9, [sp, #0x30] */
/* @0x26d54c add r3, r11, #1 */
/* @0x26d550 cmp r11, r9 */
/* @0x26d554 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26d558 str r7, [r12] */
/* @0x26d55c add r5, r5, #1 */
/* @0x26d560 str r6, [r12, #0x4] */
/* @0x26d564 mov r11, r3 */
/* @0x26d568 add r12, r12, #12 */
/* @0x26d56c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d570 ldr r4, [sp, #0x7c] */
/* @0x26d574 add r5, r5, #1 */
/* @0x26d578 ldr r8, [sp, #0x60] */
/* @0x26d57c str r4, [sp, #0x24] */
/* @0x26d580 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d584 ldr r2, [sp, #0x28] */
/* @0x26d588 ldr r1, [r2, #0x20] */
/* @0x26d58c cmp r1, #0 */
/* @0x26d590 beq 0x26e070 <pcre_compile+0x50e8> */
/* @0x26d594 ldr r2, [r2, #0x8] */
/* @0x26d598 ldr r3, [sp, #0x38] */
/* @0x26d59c cmp r3, r2 */
/* @0x26d5a0 bhs 0x26b738 <pcre_compile+0x27b0> */
/* @0x26d5a4 ldr lr, [sp, #0x48] */
/* @0x26d5a8 mov r0, r3 */
/* @0x26d5ac str r12, [sp, #0x1c] */
/* @0x26d5b0 str lr, [sp] */
/* @0x26d5b4 ldr lr, [sp, #0x28] */
/* @0x26d5b8 add r3, lr, #36 */
/* @0x26d5bc bl 0x25f9fc <_pcre_is_newline> */
/* @0x26d5c0 ldr r12, [sp, #0x1c] */
/* @0x26d5c4 cmp r0, #0 */
/* @0x26d5c8 beq 0x26b738 <pcre_compile+0x27b0> */
/* @0x26d5cc ldr r4, [sp, #0x7c] */
/* @0x26d5d0 add r5, r5, #1 */
/* @0x26d5d4 ldr r8, [sp, #0x60] */
/* @0x26d5d8 str r4, [sp, #0x24] */
/* @0x26d5dc b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d5e0 ldr r4, [sp, #0x7c] */
/* @0x26d5e4 add r5, r5, #1 */
/* @0x26d5e8 ldr r8, [sp, #0x60] */
/* @0x26d5ec str r4, [sp, #0x24] */
/* @0x26d5f0 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d5f4 ldr r3, [sp, #0x28] */
/* @0x26d5f8 ldr r0, [sp, #0x38] */
/* @0x26d5fc ldr r2, [r3, #0x8] */
/* @0x26d600 add r3, r0, #1 */
/* @0x26d604 cmp r2, r3 */
/* @0x26d608 bhi 0x26ba28 <pcre_compile+0x2aa0> */
/* @0x26d60c ldr r1, [sp, #0x28] */
/* @0x26d610 ldr r3, [r1, #0x18] */
/* @0x26d614 tst r3, #134217728 */
/* @0x26d618 beq 0x26ba28 <pcre_compile+0x2aa0> */
/* @0x26d61c ldr r3, [r1, #0x20] */
/* @0x26d620 cmp r3, #0 */
/* @0x26d624 bne 0x26ba28 <pcre_compile+0x2aa0> */
/* @0x26d628 ldr r3, [r1, #0x24] */
/* @0x26d62c cmp r3, #2 */
/* @0x26d630 bne 0x26ba28 <pcre_compile+0x2aa0> */
/* @0x26d634 ldrb r3, [r1, #0x28] */
/* @0x26d638 ldr r2, [sp, #0x34] */
/* @0x26d63c cmp r3, r2 */
/* @0x26d640 bne 0x26ba28 <pcre_compile+0x2aa0> */
/* @0x26d644 mov r7, #1 */
/* @0x26d648 mov r8, r4 */
/* @0x26d64c str r7, [sp, #0x44] */
/* @0x26d650 add r5, r5, r7 */
/* @0x26d654 str r6, [sp, #0x24] */
/* @0x26d658 str r7, [sp, #0x4c] */
/* @0x26d65c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d660 ldr r6, [sp, #0x28] */
/* @0x26d664 ldr r1, [r6, #0x20] */
/* @0x26d668 cmp r1, #0 */
/* @0x26d66c beq 0x26e390 <pcre_compile+0x5408> */
/* @0x26d670 ldr r2, [r6, #0x8] */
/* @0x26d674 ldr r6, [sp, #0x38] */
/* @0x26d678 cmp r6, r2 */
/* @0x26d67c bhs 0x26b950 <pcre_compile+0x29c8> */
/* @0x26d680 ldr r6, [sp, #0x48] */
/* @0x26d684 ldr r0, [sp, #0x38] */
/* @0x26d688 str r12, [sp, #0x1c] */
/* @0x26d68c str r6, [sp] */
/* @0x26d690 ldr r6, [sp, #0x28] */
/* @0x26d694 add r3, r6, #36 */
/* @0x26d698 bl 0x25f9fc <_pcre_is_newline> */
/* @0x26d69c ldr r12, [sp, #0x1c] */
/* @0x26d6a0 cmp r0, #0 */
/* @0x26d6a4 addne r5, r5, #1 */
/* @0x26d6a8 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26d6ac b 0x26b950 <pcre_compile+0x29c8> */
/* @0x26d6b0 ldr r3, [sp, #0x28] */
/* @0x26d6b4 ldr r0, [sp, #0x38] */
/* @0x26d6b8 ldr r2, [r3, #0x8] */
/* @0x26d6bc add r3, r0, #1 */
/* @0x26d6c0 cmp r2, r3 */
/* @0x26d6c4 bhi 0x26b818 <pcre_compile+0x2890> */
/* @0x26d6c8 ldr r1, [sp, #0x28] */
/* @0x26d6cc ldr r3, [r1, #0x18] */
/* @0x26d6d0 tst r3, #134217728 */
/* @0x26d6d4 beq 0x26b818 <pcre_compile+0x2890> */
/* @0x26d6d8 ldr r3, [r1, #0x20] */
/* @0x26d6dc cmp r3, #0 */
/* @0x26d6e0 bne 0x26b818 <pcre_compile+0x2890> */
/* @0x26d6e4 ldr r3, [r1, #0x24] */
/* @0x26d6e8 cmp r3, #2 */
/* @0x26d6ec bne 0x26b818 <pcre_compile+0x2890> */
/* @0x26d6f0 ldrb r3, [r1, #0x28] */
/* @0x26d6f4 ldr r2, [sp, #0x34] */
/* @0x26d6f8 cmp r3, r2 */
/* @0x26d6fc bne 0x26b818 <pcre_compile+0x2890> */
/* @0x26d700 mov r7, #1 */
/* @0x26d704 mov r8, r4 */
/* @0x26d708 str r7, [sp, #0x44] */
/* @0x26d70c add r5, r5, r7 */
/* @0x26d710 str r6, [sp, #0x24] */
/* @0x26d714 str r7, [sp, #0x4c] */
/* @0x26d718 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d71c ldr r9, [sp, #0x30] */
/* @0x26d720 add r3, r11, #1 */
/* @0x26d724 cmp r11, r9 */
/* @0x26d728 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26d72c str r7, [r12] */
/* @0x26d730 add r5, r5, #1 */
/* @0x26d734 str r6, [r12, #0x4] */
/* @0x26d738 mov r11, r3 */
/* @0x26d73c add r12, r12, #12 */
/* @0x26d740 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d744 ldr r9, [sp, #0x28] */
/* @0x26d748 ldr r1, [r9, #0x20] */
/* @0x26d74c cmp r1, #0 */
/* @0x26d750 beq 0x26e1ac <pcre_compile+0x5224> */
/* @0x26d754 ldr r2, [r9, #0x8] */
/* @0x26d758 ldr r9, [sp, #0x38] */
/* @0x26d75c cmp r9, r2 */
/* @0x26d760 bhs 0x26bbb8 <pcre_compile+0x2c30> */
/* @0x26d764 ldr r9, [sp, #0x48] */
/* @0x26d768 ldr r0, [sp, #0x38] */
/* @0x26d76c str r12, [sp, #0x1c] */
/* @0x26d770 str r9, [sp] */
/* @0x26d774 ldr r9, [sp, #0x28] */
/* @0x26d778 add r3, r9, #36 */
/* @0x26d77c bl 0x25f9fc <_pcre_is_newline> */
/* @0x26d780 ldr r12, [sp, #0x1c] */
/* @0x26d784 cmp r0, #0 */
/* @0x26d788 addne r5, r5, #1 */
/* @0x26d78c bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26d790 b 0x26bbb8 <pcre_compile+0x2c30> */
/* @0x26d794 ldr r6, [sp, #0x28] */
/* @0x26d798 ldr r9, [sp, #0x38] */
/* @0x26d79c ldr r3, [r6, #0x24] */
/* @0x26d7a0 ldr r2, [r6, #0x8] */
/* @0x26d7a4 rsb r2, r3, r2 */
/* @0x26d7a8 cmp r9, r2 */
/* @0x26d7ac addhi r5, r5, #1 */
/* @0x26d7b0 bhi 0x269480 <pcre_compile+0x4f8> */
/* @0x26d7b4 ldr r4, [sp, #0x38] */
/* @0x26d7b8 ldr r6, [sp, #0x28] */
/* @0x26d7bc ldrb r1, [r4] */
/* @0x26d7c0 ldrb r2, [r6, #0x28] */
/* @0x26d7c4 cmp r1, r2 */
/* @0x26d7c8 addne r5, r5, #1 */
/* @0x26d7cc bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26d7d0 cmp r3, #1 */
/* @0x26d7d4 beq 0x26d7f4 <pcre_compile+0x486c> */
/* @0x26d7d8 ldr r9, [sp, #0x38] */
/* @0x26d7dc ldr r4, [sp, #0x28] */
/* @0x26d7e0 ldrb r1, [r9, #0x1] */
/* @0x26d7e4 ldrb r2, [r4, #0x29] */
/* @0x26d7e8 cmp r1, r2 */
/* @0x26d7ec addne r5, r5, #1 */
/* @0x26d7f0 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26d7f4 ldr r9, [sp, #0x68] */
/* @0x26d7f8 ldr r4, [sp, #0x38] */
/* @0x26d7fc rsb r3, r3, r9 */
/* @0x26d800 cmp r4, r3 */
/* @0x26d804 addne r5, r5, #1 */
/* @0x26d808 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26d80c b 0x26a720 <pcre_compile+0x1798> */
/* @0x26d810 sub r2, r6, #8192 */
/* @0x26d814 cmp r2, #10 */
/* @0x26d818 bhi 0x26c164 <pcre_compile+0x31dc> */
/* @0x26d81c b 0x26c844 <pcre_compile+0x38bc> */
/* @0x26d820 cmp r6, #9 */
/* @0x26d824 bne 0x26c164 <pcre_compile+0x31dc> */
/* @0x26d828 b 0x26c844 <pcre_compile+0x38bc> */
/* @0x26d82c add r8, r8, #1 */
/* @0x26d830 add r2, r2, #12 */
/* @0x26d834 cmp r8, r6 */
/* @0x26d838 bne 0x26d350 <pcre_compile+0x43c8> */
/* @0x26d83c b 0x2691dc <pcre_compile+0x254> */
/* @0x26d840 ldr r6, [sp, #0x28] */
/* @0x26d844 ldr r2, [r6, #0x8] */
/* @0x26d848 ldr r6, [sp, #0x38] */
/* @0x26d84c add r3, r6, #1 */
/* @0x26d850 cmp r2, r3 */
/* @0x26d854 bhi 0x26b920 <pcre_compile+0x2998> */
/* @0x26d858 ldr r6, [sp, #0x28] */
/* @0x26d85c ldr r3, [r6, #0x18] */
/* @0x26d860 tst r3, #134217728 */
/* @0x26d864 beq 0x26b920 <pcre_compile+0x2998> */
/* @0x26d868 ldr r3, [r6, #0x20] */
/* @0x26d86c cmp r3, #0 */
/* @0x26d870 bne 0x26b920 <pcre_compile+0x2998> */
/* @0x26d874 ldr r3, [r6, #0x24] */
/* @0x26d878 cmp r3, #2 */
/* @0x26d87c bne 0x26b920 <pcre_compile+0x2998> */
/* @0x26d880 ldrb r3, [r6, #0x28] */
/* @0x26d884 ldr r6, [sp, #0x34] */
/* @0x26d888 cmp r3, r6 */
/* @0x26d88c bne 0x26b920 <pcre_compile+0x2998> */
/* @0x26d890 mov r7, #1 */
/* @0x26d894 str r7, [sp, #0x44] */
/* @0x26d898 add r5, r5, r7 */
/* @0x26d89c str r7, [sp, #0x4c] */
/* @0x26d8a0 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d8a4 ldr r4, [sp, #0x30] */
/* @0x26d8a8 add r2, r8, #1 */
/* @0x26d8ac cmp r8, r4 */
/* @0x26d8b0 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26d8b4 ldr r9, [sp, #0x24] */
/* @0x26d8b8 mov r8, r2 */
/* @0x26d8bc ldr r6, [sp, #0x60] */
/* @0x26d8c0 add r9, r9, #12 */
/* @0x26d8c4 add r7, r7, r6 */
/* @0x26d8c8 str r3, [r9, #-0x8] */
/* @0x26d8cc add r3, r7, #3 */
/* @0x26d8d0 str r3, [r9, #-0xc] */
/* @0x26d8d4 str r9, [sp, #0x24] */
/* @0x26d8d8 b 0x26b198 <pcre_compile+0x2210> */
/* @0x26d8dc ldr r6, [sp, #0x48] */
/* @0x26d8e0 mov r0, r4 */
/* @0x26d8e4 add r3, r9, #36 */
/* @0x26d8e8 str r12, [sp, #0x1c] */
/* @0x26d8ec str r6, [sp] */
/* @0x26d8f0 bl 0x25fbc0 <_pcre_was_newline> */
/* @0x26d8f4 ldr r12, [sp, #0x1c] */
/* @0x26d8f8 cmp r0, #0 */
/* @0x26d8fc bne 0x26afc0 <pcre_compile+0x2038> */
/* @0x26d900 b 0x26c93c <pcre_compile+0x39b4> */
/* @0x26d904 ldr r6, [sp, #0x38] */
/* @0x26d908 ldr r9, [sp, #0x68] */
/* @0x26d90c add r3, r6, #1 */
/* @0x26d910 cmp r9, r3 */
/* @0x26d914 bhi 0x26d9d4 <pcre_compile+0x4a4c> */
/* @0x26d918 ldr r4, [sp, #0x30] */
/* @0x26d91c add r3, r11, #1 */
/* @0x26d920 cmp r11, r4 */
/* @0x26d924 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26d928 ldr r6, [sp, #0x28] */
/* @0x26d92c add r7, r7, #1 */
/* @0x26d930 mov r2, #0 */
/* @0x26d934 add r5, r5, #1 */
/* @0x26d938 mov r11, r3 */
/* @0x26d93c add r12, r12, #12 */
/* @0x26d940 ldr r1, [r6, #0x18] */
/* @0x26d944 str r7, [r12, #-0xc] */
/* @0x26d948 tst r1, #134217728 */
/* @0x26d94c str r2, [r12, #-0x8] */
/* @0x26d950 movne r7, #1 */
/* @0x26d954 strne r7, [sp, #0x64] */
/* @0x26d958 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d95c bhs 0x26ccf0 <pcre_compile+0x3d68> */
/* @0x26d960 add r5, r5, #1 */
/* @0x26d964 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d968 mov r4, #1 */
/* @0x26d96c add r5, r5, #1 */
/* @0x26d970 str r4, [sp, #0x44] */
/* @0x26d974 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d978 ldr r6, [sp, #0x30] */
/* @0x26d97c add r2, r11, #1 */
/* @0x26d980 cmp r11, r6 */
/* @0x26d984 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26d988 str r3, [r12, #0x4] */
/* @0x26d98c rsb r7, r7, #0 */
/* @0x26d990 mov r3, #0 */
/* @0x26d994 str r7, [r12] */
/* @0x26d998 str r3, [r12, #0x8] */
/* @0x26d99c add r5, r5, #1 */
/* @0x26d9a0 mov r11, r2 */
/* @0x26d9a4 add r12, r12, #12 */
/* @0x26d9a8 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26d9ac cmp r9, #9 */
/* @0x26d9b0 bne 0x26c998 <pcre_compile+0x3a10> */
/* @0x26d9b4 b 0x26a80c <pcre_compile+0x1884> */
/* @0x26d9b8 sub r3, r6, #8192 */
/* @0x26d9bc cmp r3, #10 */
/* @0x26d9c0 bhi 0x26c998 <pcre_compile+0x3a10> */
/* @0x26d9c4 b 0x26a80c <pcre_compile+0x1884> */
/* @0x26d9c8 ldr r4, [sp, #0x28] */
/* @0x26d9cc ldr r2, [r4, #0x8] */
/* @0x26d9d0 b 0x26a61c <pcre_compile+0x1694> */
/* @0x26d9d4 ldr r9, [sp, #0x38] */
/* @0x26d9d8 ldrb r3, [r9, #0x1] */
/* @0x26d9dc cmp r3, #10 */
/* @0x26d9e0 beq 0x26df6c <pcre_compile+0x4fe4> */
/* @0x26d9e4 ldr r6, [sp, #0x30] */
/* @0x26d9e8 add r3, r11, #1 */
/* @0x26d9ec cmp r11, r6 */
/* @0x26d9f0 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26d9f4 add r7, r7, #1 */
/* @0x26d9f8 mov r11, r3 */
/* @0x26d9fc str r7, [r12] */
/* @0x26da00 mov r3, #0 */
/* @0x26da04 add r5, r5, #1 */
/* @0x26da08 str r3, [r12, #0x4] */
/* @0x26da0c add r12, r12, #12 */
/* @0x26da10 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26da14 ldr r0, [sp, #0x28] */
/* @0x26da18 ldr r1, [sp, #0x38] */
/* @0x26da1c ldr r2, [r0, #0x8] */
/* @0x26da20 add r3, r1, #1 */
/* @0x26da24 cmp r2, r3 */
/* @0x26da28 bhi 0x26b70c <pcre_compile+0x2784> */
/* @0x26da2c ldr r3, [r0, #0x18] */
/* @0x26da30 tst r3, #134217728 */
/* @0x26da34 beq 0x26b70c <pcre_compile+0x2784> */
/* @0x26da38 ldr r3, [r0, #0x20] */
/* @0x26da3c cmp r3, #0 */
/* @0x26da40 bne 0x26b70c <pcre_compile+0x2784> */
/* @0x26da44 ldr r3, [r0, #0x24] */
/* @0x26da48 cmp r3, #2 */
/* @0x26da4c bne 0x26b70c <pcre_compile+0x2784> */
/* @0x26da50 ldrb r3, [r0, #0x28] */
/* @0x26da54 ldr r2, [sp, #0x34] */
/* @0x26da58 cmp r3, r2 */
/* @0x26da5c bne 0x26b70c <pcre_compile+0x2784> */
/* @0x26da60 ldr r6, [sp, #0x7c] */
/* @0x26da64 mov r4, #1 */
/* @0x26da68 ldr r8, [sp, #0x60] */
/* @0x26da6c add r5, r5, r4 */
/* @0x26da70 str r4, [sp, #0x44] */
/* @0x26da74 str r6, [sp, #0x24] */
/* @0x26da78 str r4, [sp, #0x4c] */
/* @0x26da7c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26da80 ldr r2, [sp, #0x28] */
/* @0x26da84 ldr r1, [r2, #0x20] */
/* @0x26da88 cmp r1, #0 */
/* @0x26da8c beq 0x26e3ec <pcre_compile+0x5464> */
/* @0x26da90 ldr r2, [r2, #0x8] */
/* @0x26da94 ldr r3, [sp, #0x38] */
/* @0x26da98 cmp r3, r2 */
/* @0x26da9c bhs 0x26b850 <pcre_compile+0x28c8> */
/* @0x26daa0 ldr lr, [sp, #0x48] */
/* @0x26daa4 mov r0, r3 */
/* @0x26daa8 str r12, [sp, #0x1c] */
/* @0x26daac str lr, [sp] */
/* @0x26dab0 ldr lr, [sp, #0x28] */
/* @0x26dab4 add r3, lr, #36 */
/* @0x26dab8 bl 0x25f9fc <_pcre_is_newline> */
/* @0x26dabc ldr r12, [sp, #0x1c] */
/* @0x26dac0 cmp r0, #0 */
/* @0x26dac4 beq 0x26b850 <pcre_compile+0x28c8> */
/* @0x26dac8 add r5, r5, #1 */
/* @0x26dacc mov r8, r4 */
/* @0x26dad0 str r6, [sp, #0x24] */
/* @0x26dad4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26dad8 ldr r4, [sp, #0x5c] */
/* @0x26dadc ldr r6, [sp, #0x38] */
/* @0x26dae0 cmp r4, r6 */
/* @0x26dae4 blo 0x26db24 <pcre_compile+0x4b9c> */
/* @0x26dae8 ldr r7, [sp, #0x28] */
/* @0x26daec ldr r3, [r7, #0x18] */
/* @0x26daf0 tst r3, #1024 */
/* @0x26daf4 addne r5, r5, #1 */
/* @0x26daf8 bne 0x269480 <pcre_compile+0x4f8> */
/* @0x26dafc tst r3, #268435456 */
/* @0x26db00 beq 0x26db24 <pcre_compile+0x4b9c> */
/* @0x26db04 ldr r9, [sp, #0x28] */
/* @0x26db08 ldr r4, [sp, #0x54] */
/* @0x26db0c ldr r6, [sp, #0x5c] */
/* @0x26db10 ldr r3, [r9, #0x14] */
/* @0x26db14 add r3, r4, r3 */
/* @0x26db18 cmp r6, r3 */
/* @0x26db1c addls r5, r5, #1 */
/* @0x26db20 bls 0x269480 <pcre_compile+0x4f8> */
/* @0x26db24 ldr r7, [sp, #0x70] */
/* @0x26db28 cmn r7, #1 */
/* @0x26db2c beq 0x26e208 <pcre_compile+0x5280> */
/* @0x26db30 ldr r4, [sp, #0x70] */
/* @0x26db34 cmp r4, #0 */
/* @0x26db38 beq 0x26db50 <pcre_compile+0x4bc8> */
/* @0x26db3c add r4, r4, #1 */
/* @0x26db40 ldr r6, [sp, #0x84] */
/* @0x26db44 str r4, [sp, #0x70] */
/* @0x26db48 cmp r6, r4, lsl #1 */
/* @0x26db4c bge 0x26e21c <pcre_compile+0x5294> */
/* @0x26db50 ldr r4, [sp, #0x84] */
/* @0x26db54 mov r6, #0 */
/* @0x26db58 str r6, [sp, #0x70] */
/* @0x26db5c sub r2, r4, #2 */
/* @0x26db60 cmp r2, #0 */
/* @0x26db64 ble 0x26db88 <pcre_compile+0x4c00> */
/* @0x26db68 add r7, sp, #8192 */
/* @0x26db6c lsl r2, r2, #2 */
/* @0x26db70 ldr r7, [r7, #0x40] */
/* @0x26db74 str r12, [sp, #0x1c] */
/* @0x26db78 add r0, r7, #8 */
/* @0x26db7c mov r1, r7 */
/* @0x26db80 bl 0xb6694 <memmove@plt> —— memmove@plt */
/* @0x26db84 ldr r12, [sp, #0x1c] */
/* @0x26db88 ldr r4, [sp, #0x98] */
/* @0x26db8c cmp r4, #0 */
/* @0x26db90 beq 0x26dbb8 <pcre_compile+0x4c30> */
/* @0x26db94 add r9, sp, #8192 */
/* @0x26db98 ldr r7, [sp, #0x54] */
/* @0x26db9c ldr r6, [sp, #0x5c] */
/* @0x26dba0 ldr r9, [r9, #0x40] */
/* @0x26dba4 ldr r4, [sp, #0x38] */
/* @0x26dba8 rsb r3, r7, r6 */
/* @0x26dbac str r3, [r9] */
/* @0x26dbb0 rsb r3, r7, r4 */
/* @0x26dbb4 str r3, [r9, #0x4] */
/* @0x26dbb8 ldr r7, [sp, #0x28] */
/* @0x26dbbc ldr r3, [r7, #0x18] */
/* @0x26dbc0 tst r3, #65536 */
/* @0x26dbc4 bne 0x26d400 <pcre_compile+0x4478> */
/* @0x26dbc8 add r5, r5, #1 */
/* @0x26dbcc b 0x269480 <pcre_compile+0x4f8> */
/* @0x26dbd0 ldr r6, [sp, #0x30] */
/* @0x26dbd4 add r2, r11, #1 */
/* @0x26dbd8 cmp r11, r6 */
/* @0x26dbdc bge 0x2691dc <pcre_compile+0x254> */
/* @0x26dbe0 str r3, [r12, #0x4] */
/* @0x26dbe4 rsb r7, r7, #0 */
/* @0x26dbe8 mov r3, #0 */
/* @0x26dbec str r7, [r12] */
/* @0x26dbf0 str r3, [r12, #0x8] */
/* @0x26dbf4 add r5, r5, #1 */
/* @0x26dbf8 mov r11, r2 */
/* @0x26dbfc add r12, r12, #12 */
/* @0x26dc00 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26dc04 cmp r6, #9 */
/* @0x26dc08 bne 0x26c26c <pcre_compile+0x32e4> */
/* @0x26dc0c b 0x26c81c <pcre_compile+0x3894> */
/* @0x26dc10 ldr r6, [sp, #0x28] */
/* @0x26dc14 ldr r3, [r6, #0x18] */
/* @0x26dc18 tst r3, #128 */
/* @0x26dc1c bne 0x26af34 <pcre_compile+0x1fac> */
/* @0x26dc20 b 0x26afc0 <pcre_compile+0x2038> */
/* @0x26dc24 tst r0, #16 */
/* @0x26dc28 bne 0x26e2dc <pcre_compile+0x5354> */
/* @0x26dc2c lsl r0, r0, #12 */
/* @0x26dc30 ldrb r2, [r3, #0x2] */
/* @0x26dc34 ldrb r1, [r3, #0x1] */
/* @0x26dc38 and r2, r2, #63 */
/* @0x26dc3c uxth r3, r0 */
/* @0x26dc40 and r0, r1, #63 */
/* @0x26dc44 orr r3, r2, r3 */
/* @0x26dc48 orr r0, r3, r0, lsl #6 */
/* @0x26dc4c b 0x26abb4 <pcre_compile+0x1c2c> */
/* @0x26dc50 sub r2, r6, #8192 */
/* @0x26dc54 cmp r2, #10 */
/* @0x26dc58 bhi 0x26c26c <pcre_compile+0x32e4> */
/* @0x26dc5c b 0x26c81c <pcre_compile+0x3894> */
/* @0x26dc60 ldr r5, [sp, #0x38] */
/* @0x26dc64 mov r9, #6 */
/* @0x26dc68 ldr r7, [sp, #0x34] */
/* @0x26dc6c str r9, [sp, #0x40] */
/* @0x26dc70 ldrb r3, [r5, #0x5] */
/* @0x26dc74 and r1, r7, #1 */
/* @0x26dc78 ldrb r2, [r5, #0x1] */
/* @0x26dc7c and r3, r3, #63 */
/* @0x26dc80 ldrb r0, [r5, #0x2] */
/* @0x26dc84 and r2, r2, #63 */
/* @0x26dc88 orr r3, r3, r1, lsl #30 */
/* @0x26dc8c ldrb r1, [r5, #0x3] */
/* @0x26dc90 and r0, r0, #63 */
/* @0x26dc94 orr r3, r3, r2, lsl #24 */
/* @0x26dc98 ldrb r2, [r5, #0x4] */
/* @0x26dc9c and r1, r1, #63 */
/* @0x26dca0 orr r3, r3, r0, lsl #18 */
/* @0x26dca4 and r2, r2, #63 */
/* @0x26dca8 orr r3, r3, r1, lsl #12 */
/* @0x26dcac orr r2, r3, r2, lsl r9 */
/* @0x26dcb0 str r2, [sp, #0x34] */
/* @0x26dcb4 b 0x2693e8 <pcre_compile+0x460> */
/* @0x26dcb8 ldrb r0, [r4, #0x4] */
/* @0x26dcbc movw r3, #0xffff */
/* @0x26dcc0 ldrb r1, [r4, #0x5] */
/* @0x26dcc4 orr r1, r1, r0, lsl #8 */
/* @0x26dcc8 cmp r1, r3 */
/* @0x26dccc bne 0x26e310 <pcre_compile+0x5388> */
/* @0x26dcd0 ldr r4, [sp, #0x28] */
/* @0x26dcd4 ldr r3, [r4, #0x30] */
/* @0x26dcd8 cmp r3, #0 */
/* @0x26dcdc beq 0x26e318 <pcre_compile+0x5390> */
/* @0x26dce0 ldr r6, [sp, #0x30] */
/* @0x26dce4 cmp r8, r6 */
/* @0x26dce8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26dcec ldr r9, [sp, #0x24] */
/* @0x26dcf0 add r7, r7, #6 */
/* @0x26dcf4 add r8, r8, #1 */
/* @0x26dcf8 add r9, r9, #12 */
/* @0x26dcfc str r2, [r9, #-0x8] */
/* @0x26dd00 str r7, [r9, #-0xc] */
/* @0x26dd04 str r9, [sp, #0x24] */
/* @0x26dd08 b 0x26b198 <pcre_compile+0x2210> */
/* @0x26dd0c mov r7, #1 */
/* @0x26dd10 add r5, r5, #1 */
/* @0x26dd14 str r7, [sp, #0x44] */
/* @0x26dd18 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26dd1c ldr r6, [sp, #0x28] */
/* @0x26dd20 ldr r2, [r6, #0x8] */
/* @0x26dd24 b 0x26a540 <pcre_compile+0x15b8> */
/* @0x26dd28 add r5, r5, #1 */
/* @0x26dd2c mov r8, r3 */
/* @0x26dd30 str r2, [sp, #0x24] */
/* @0x26dd34 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26dd38 ldr r9, [sp, #0x28] */
/* @0x26dd3c ldr r2, [r9, #0x8] */
/* @0x26dd40 ldr r9, [sp, #0x38] */
/* @0x26dd44 add r3, r9, #1 */
/* @0x26dd48 cmp r2, r3 */
/* @0x26dd4c bhi 0x26bb88 <pcre_compile+0x2c00> */
/* @0x26dd50 ldr r9, [sp, #0x28] */
/* @0x26dd54 ldr r3, [r9, #0x18] */
/* @0x26dd58 tst r3, #134217728 */
/* @0x26dd5c beq 0x26bb88 <pcre_compile+0x2c00> */
/* @0x26dd60 ldr r3, [r9, #0x20] */
/* @0x26dd64 cmp r3, #0 */
/* @0x26dd68 bne 0x26bb88 <pcre_compile+0x2c00> */
/* @0x26dd6c ldr r3, [r9, #0x24] */
/* @0x26dd70 cmp r3, #2 */
/* @0x26dd74 bne 0x26bb88 <pcre_compile+0x2c00> */
/* @0x26dd78 ldrb r3, [r9, #0x28] */
/* @0x26dd7c ldr r9, [sp, #0x34] */
/* @0x26dd80 cmp r3, r9 */
/* @0x26dd84 bne 0x26bb88 <pcre_compile+0x2c00> */
/* @0x26dd88 mov r4, #1 */
/* @0x26dd8c str r4, [sp, #0x44] */
/* @0x26dd90 add r5, r5, r4 */
/* @0x26dd94 str r4, [sp, #0x4c] */
/* @0x26dd98 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26dd9c ldr r2, [sp, #0x28] */
/* @0x26dda0 ldr r1, [r2, #0x20] */
/* @0x26dda4 cmp r1, #0 */
/* @0x26dda8 beq 0x26dfb0 <pcre_compile+0x5028> */
/* @0x26ddac ldr r2, [r2, #0x8] */
/* @0x26ddb0 ldr r3, [sp, #0x38] */
/* @0x26ddb4 cmp r3, r2 */
/* @0x26ddb8 bhs 0x26ba60 <pcre_compile+0x2ad8> */
/* @0x26ddbc ldr lr, [sp, #0x48] */
/* @0x26ddc0 mov r0, r3 */
/* @0x26ddc4 str r12, [sp, #0x1c] */
/* @0x26ddc8 str lr, [sp] */
/* @0x26ddcc ldr lr, [sp, #0x28] */
/* @0x26ddd0 add r3, lr, #36 */
/* @0x26ddd4 bl 0x25f9fc <_pcre_is_newline> */
/* @0x26ddd8 ldr r12, [sp, #0x1c] */
/* @0x26dddc cmp r0, #0 */
/* @0x26dde0 beq 0x26ba60 <pcre_compile+0x2ad8> */
/* @0x26dde4 add r5, r5, #1 */
/* @0x26dde8 mov r8, r4 */
/* @0x26ddec str r6, [sp, #0x24] */
/* @0x26ddf0 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26ddf4 ldr r7, [sp, #0x2c] */
/* @0x26ddf8 add r2, r11, #1 */
/* @0x26ddfc ldr r9, [sp, #0x24] */
/* @0x26de00 ldrb r0, [r7] */
/* @0x26de04 cmp r0, #108 */
/* @0x26de08 movne r8, r6 */
/* @0x26de0c ldr r6, [sp, #0x30] */
/* @0x26de10 movne r9, r3 */
/* @0x26de14 str r9, [sp, #0x24] */
/* @0x26de18 cmp r11, r6 */
/* @0x26de1c bge 0x2691dc <pcre_compile+0x254> */
/* @0x26de20 str r1, [r12] */
/* @0x26de24 add r5, r5, #1 */
/* @0x26de28 str r4, [r12, #0x4] */
/* @0x26de2c mov r11, r2 */
/* @0x26de30 add r12, r12, #12 */
/* @0x26de34 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26de38 sub r3, r6, #8192 */
/* @0x26de3c cmp r3, #10 */
/* @0x26de40 bhi 0x26a880 <pcre_compile+0x18f8> */
/* @0x26de44 b 0x26c970 <pcre_compile+0x39e8> */
/* @0x26de48 cmp r9, #9 */
/* @0x26de4c bne 0x26a880 <pcre_compile+0x18f8> */
/* @0x26de50 b 0x26c970 <pcre_compile+0x39e8> */
/* @0x26de54 bhs 0x26ccb4 <pcre_compile+0x3d2c> */
/* @0x26de58 add r5, r5, #1 */
/* @0x26de5c mov r8, r0 */
/* @0x26de60 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26de64 ldr r9, [sp, #0x2c] */
/* @0x26de68 add r1, r11, #1 */
/* @0x26de6c ldr r6, [sp, #0x24] */
/* @0x26de70 ldrb r0, [r9] */
/* @0x26de74 ldr r9, [sp, #0x30] */
/* @0x26de78 cmp r0, #106 */
/* @0x26de7c movne r6, r2 */
/* @0x26de80 movne r8, r3 */
/* @0x26de84 cmp r11, r9 */
/* @0x26de88 str r6, [sp, #0x24] */
/* @0x26de8c bge 0x2691dc <pcre_compile+0x254> */
/* @0x26de90 str r7, [r12] */
/* @0x26de94 add r5, r5, #1 */
/* @0x26de98 str r4, [r12, #0x4] */
/* @0x26de9c mov r11, r1 */
/* @0x26dea0 add r12, r12, #12 */
/* @0x26dea4 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26dea8 ldr r4, [sp, #0x38] */
/* @0x26deac ldr r6, [sp, #0x68] */
/* @0x26deb0 add r3, r4, #1 */
/* @0x26deb4 cmp r6, r3 */
/* @0x26deb8 bls 0x26b434 <pcre_compile+0x24ac> */
/* @0x26debc ldrb r3, [r4, #0x1] */
/* @0x26dec0 subs r6, r3, #10 */
/* @0x26dec4 rsbs r3, r6, #0 */
/* @0x26dec8 adcs r3, r3, r6 */
/* @0x26decc b 0x26b438 <pcre_compile+0x24b0> */
/* @0x26ded0 cmp r0, #0 */
/* @0x26ded4 addeq r5, r5, #1 */
/* @0x26ded8 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26dedc ldr r7, [sp, #0x30] */
/* @0x26dee0 add r3, r11, #1 */
/* @0x26dee4 cmp r11, r7 */
/* @0x26dee8 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26deec str r1, [r12] */
/* @0x26def0 mov r11, r3 */
/* @0x26def4 add r5, r5, #1 */
/* @0x26def8 mov r3, #0 */
/* @0x26defc add r12, r12, #12 */
/* @0x26df00 str r3, [r12, #-0x8] */
/* @0x26df04 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26df08 ldr r9, [sp, #0x28] */
/* @0x26df0c ldr r4, [sp, #0x38] */
/* @0x26df10 ldr r2, [r9, #0x8] */
/* @0x26df14 ldr r3, [r9, #0x24] */
/* @0x26df18 rsb r1, r3, r2 */
/* @0x26df1c cmp r4, r1 */
/* @0x26df20 bhi 0x26a61c <pcre_compile+0x1694> */
/* @0x26df24 ldrb r0, [r4] */
/* @0x26df28 ldrb r1, [r9, #0x28] */
/* @0x26df2c cmp r0, r1 */
/* @0x26df30 bne 0x26a61c <pcre_compile+0x1694> */
/* @0x26df34 cmp r3, #1 */
/* @0x26df38 beq 0x26df4c <pcre_compile+0x4fc4> */
/* @0x26df3c ldrb r0, [r4, #0x1] */
/* @0x26df40 ldrb r1, [r9, #0x29] */
/* @0x26df44 cmp r0, r1 */
/* @0x26df48 bne 0x26a61c <pcre_compile+0x1694> */
/* @0x26df4c ldr r4, [sp, #0x68] */
/* @0x26df50 ldr r6, [sp, #0x38] */
/* @0x26df54 rsb r3, r3, r4 */
/* @0x26df58 cmp r6, r3 */
/* @0x26df5c beq 0x26cb90 <pcre_compile+0x3c08> */
/* @0x26df60 ldr r6, [sp, #0x28] */
/* @0x26df64 ldr r2, [r6, #0x8] */
/* @0x26df68 b 0x26a61c <pcre_compile+0x1694> */
/* @0x26df6c ldr r4, [sp, #0x30] */
/* @0x26df70 add r3, r11, #1 */
/* @0x26df74 cmp r11, r4 */
/* @0x26df78 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26df7c mvn r7, r7 */
/* @0x26df80 mov r11, r3 */
/* @0x26df84 str r7, [r12] */
/* @0x26df88 mov r3, #0 */
/* @0x26df8c mov r6, #1 */
/* @0x26df90 add r5, r5, #1 */
/* @0x26df94 stmib r12, {r3, r6} */
/* @0x26df98 add r12, r12, #12 */
/* @0x26df9c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26dfa0 cmp r0, #0 */
/* @0x26dfa4 addeq r5, r5, #1 */
/* @0x26dfa8 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26dfac b 0x26cf0c <pcre_compile+0x3f84> */
/* @0x26dfb0 ldr r0, [sp, #0x28] */
/* @0x26dfb4 ldr r1, [sp, #0x38] */
/* @0x26dfb8 ldr r3, [r0, #0x24] */
/* @0x26dfbc ldr r2, [r0, #0x8] */
/* @0x26dfc0 rsb r2, r3, r2 */
/* @0x26dfc4 cmp r1, r2 */
/* @0x26dfc8 bhi 0x26ba60 <pcre_compile+0x2ad8> */
/* @0x26dfcc ldrb r1, [r1] */
/* @0x26dfd0 ldrb r2, [r0, #0x28] */
/* @0x26dfd4 cmp r1, r2 */
/* @0x26dfd8 bne 0x26ba60 <pcre_compile+0x2ad8> */
/* @0x26dfdc cmp r3, #1 */
/* @0x26dfe0 streq r6, [sp, #0x24] */
/* @0x26dfe4 addeq r5, r5, #1 */
/* @0x26dfe8 moveq r8, r4 */
/* @0x26dfec beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26dff0 ldr r3, [sp, #0x38] */
/* @0x26dff4 ldr r0, [sp, #0x28] */
/* @0x26dff8 ldrb r2, [r3, #0x1] */
/* @0x26dffc ldrb r3, [r0, #0x29] */
/* @0x26e000 cmp r2, r3 */
/* @0x26e004 streq r6, [sp, #0x24] */
/* @0x26e008 addeq r5, r5, #1 */
/* @0x26e00c moveq r8, r4 */
/* @0x26e010 bne 0x26ba60 <pcre_compile+0x2ad8> */
/* @0x26e014 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26e018 ldr r6, [sp, #0x30] */
/* @0x26e01c add r3, r11, #1 */
/* @0x26e020 cmp r11, r6 */
/* @0x26e024 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26e028 str r7, [r12] */
/* @0x26e02c add r5, r5, #1 */
/* @0x26e030 str r2, [r12, #0x4] */
/* @0x26e034 mov r11, r3 */
/* @0x26e038 add r12, r12, #12 */
/* @0x26e03c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26e040 ldrb r2, [r6, #0x1] */
/* @0x26e044 ldrb r0, [r6, #0x2] */
/* @0x26e048 orr r2, r0, r2, lsl #8 */
/* @0x26e04c cmp r4, r2 */
/* @0x26e050 subge r8, r8, #1 */
/* @0x26e054 ldrge r9, [sp, #0x24] */
/* @0x26e058 subge r9, r9, #12 */
/* @0x26e05c strge r9, [sp, #0x24] */
/* @0x26e060 b 0x26ce38 <pcre_compile+0x3eb0> */
/* @0x26e064 str r11, [sp, #0x40] */
/* @0x26e068 mov r11, #1 */
/* @0x26e06c b 0x269480 <pcre_compile+0x4f8> */
/* @0x26e070 ldr r0, [sp, #0x28] */
/* @0x26e074 ldr r1, [sp, #0x38] */
/* @0x26e078 ldr r3, [r0, #0x24] */
/* @0x26e07c ldr r2, [r0, #0x8] */
/* @0x26e080 rsb r2, r3, r2 */
/* @0x26e084 cmp r1, r2 */
/* @0x26e088 bhi 0x26b738 <pcre_compile+0x27b0> */
/* @0x26e08c ldrb r1, [r1] */
/* @0x26e090 ldrb r2, [r0, #0x28] */
/* @0x26e094 cmp r1, r2 */
/* @0x26e098 bne 0x26b738 <pcre_compile+0x27b0> */
/* @0x26e09c cmp r3, #1 */
/* @0x26e0a0 beq 0x26e114 <pcre_compile+0x518c> */
/* @0x26e0a4 ldr r0, [sp, #0x38] */
/* @0x26e0a8 ldr r1, [sp, #0x28] */
/* @0x26e0ac ldrb r2, [r0, #0x1] */
/* @0x26e0b0 ldrb r3, [r1, #0x29] */
/* @0x26e0b4 cmp r2, r3 */
/* @0x26e0b8 bne 0x26b738 <pcre_compile+0x27b0> */
/* @0x26e0bc ldr r4, [sp, #0x7c] */
/* @0x26e0c0 add r5, r5, #1 */
/* @0x26e0c4 ldr r8, [sp, #0x60] */
/* @0x26e0c8 str r4, [sp, #0x24] */
/* @0x26e0cc b 0x269480 <pcre_compile+0x4f8> */
/* @0x26e0d0 ldrb r3, [r4, #0x28] */
/* @0x26e0d4 ldr r9, [sp, #0x34] */
/* @0x26e0d8 cmp r3, r9 */
/* @0x26e0dc bne 0x26aa44 <pcre_compile+0x1abc> */
/* @0x26e0e0 mov r4, #1 */
/* @0x26e0e4 str r4, [sp, #0x44] */
/* @0x26e0e8 add r5, r5, r4 */
/* @0x26e0ec str r4, [sp, #0x4c] */
/* @0x26e0f0 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26e0f4 cmp r3, #1 */
/* @0x26e0f8 moveq r3, r1 */
/* @0x26e0fc beq 0x26a9fc <pcre_compile+0x1a74> */
/* @0x26e100 ldrb r2, [r9, #0x1] */
/* @0x26e104 ldrb r3, [r6, #0x29] */
/* @0x26e108 subs r3, r2, r3 */
/* @0x26e10c movne r3, #1 */
/* @0x26e110 b 0x26a9fc <pcre_compile+0x1a74> */
/* @0x26e114 ldr r4, [sp, #0x7c] */
/* @0x26e118 add r5, r5, #1 */
/* @0x26e11c ldr r8, [sp, #0x60] */
/* @0x26e120 str r4, [sp, #0x24] */
/* @0x26e124 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26e128 ldr r6, [sp, #0x4c] */
/* @0x26e12c cmp r6, #0 */
/* @0x26e130 mvnne r0, #11 */
/* @0x26e134 bne 0x2691e0 <pcre_compile+0x258> */
/* @0x26e138 ldr r7, [sp, #0x38] */
/* @0x26e13c ldr r9, [sp, #0x68] */
/* @0x26e140 cmp r7, r9 */
/* @0x26e144 blo 0x26d400 <pcre_compile+0x4478> */
/* @0x26e148 ldr r12, [sp, #0x28] */
/* @0x26e14c ldr r0, [sp, #0x70] */
/* @0x26e150 ldr r3, [r12, #0xc] */
/* @0x26e154 cmp r7, r3 */
/* @0x26e158 mvnhi r0, #11 */
/* @0x26e15c b 0x2691e0 <pcre_compile+0x258> */
/* @0x26e160 cmp r3, #1 */
/* @0x26e164 beq 0x26cffc <pcre_compile+0x4074> */
/* @0x26e168 ldrb r3, [r4, #0x29] */
/* @0x26e16c ldrb r2, [r6, #0x1] */
/* @0x26e170 subs r2, r2, r3 */
/* @0x26e174 rsbs r3, r2, #0 */
/* @0x26e178 adcs r3, r3, r2 */
/* @0x26e17c b 0x26cffc <pcre_compile+0x4074> */
/* @0x26e180 ldr r6, [sp, #0x48] */
/* @0x26e184 mov r0, r4 */
/* @0x26e188 add r3, r9, #36 */
/* @0x26e18c str r12, [sp, #0x1c] */
/* @0x26e190 str r6, [sp] */
/* @0x26e194 bl 0x25f9fc <_pcre_is_newline> */
/* @0x26e198 ldr r12, [sp, #0x1c] */
/* @0x26e19c cmp r0, #0 */
/* @0x26e1a0 beq 0x26d05c <pcre_compile+0x40d4> */
/* @0x26e1a4 ldr r3, [r9, #0x24] */
/* @0x26e1a8 b 0x26d7f4 <pcre_compile+0x486c> */
/* @0x26e1ac ldr r9, [sp, #0x28] */
/* @0x26e1b0 ldr r3, [r9, #0x24] */
/* @0x26e1b4 ldr r2, [r9, #0x8] */
/* @0x26e1b8 ldr r9, [sp, #0x38] */
/* @0x26e1bc rsb r2, r3, r2 */
/* @0x26e1c0 cmp r9, r2 */
/* @0x26e1c4 bhi 0x26bbb8 <pcre_compile+0x2c30> */
/* @0x26e1c8 ldrb r1, [r9] */
/* @0x26e1cc ldr r9, [sp, #0x28] */
/* @0x26e1d0 ldrb r2, [r9, #0x28] */
/* @0x26e1d4 cmp r1, r2 */
/* @0x26e1d8 bne 0x26bbb8 <pcre_compile+0x2c30> */
/* @0x26e1dc cmp r3, #1 */
/* @0x26e1e0 addeq r5, r5, #1 */
/* @0x26e1e4 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26e1e8 ldr r9, [sp, #0x38] */
/* @0x26e1ec ldrb r2, [r9, #0x1] */
/* @0x26e1f0 ldr r9, [sp, #0x28] */
/* @0x26e1f4 ldrb r3, [r9, #0x29] */
/* @0x26e1f8 cmp r2, r3 */
/* @0x26e1fc addeq r5, r5, #1 */
/* @0x26e200 bne 0x26bbb8 <pcre_compile+0x2c30> */
/* @0x26e204 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26e208 ldr r9, [sp, #0x98] */
/* @0x26e20c cmp r9, #0 */
/* @0x26e210 beq 0x26db50 <pcre_compile+0x4bc8> */
/* @0x26e214 mov r7, #1 */
/* @0x26e218 str r7, [sp, #0x70] */
/* @0x26e21c ldr r9, [sp, #0x70] */
/* @0x26e220 sub r2, r9, #1 */
/* @0x26e224 lsl r2, r2, #1 */
/* @0x26e228 b 0x26db60 <pcre_compile+0x4bd8> */
/* @0x26e22c ldr r6, [sp, #0x28] */
/* @0x26e230 ldr r9, [sp, #0x38] */
/* @0x26e234 ldr r2, [r6, #0x8] */
/* @0x26e238 ldr r3, [r6, #0x24] */
/* @0x26e23c rsb r1, r3, r2 */
/* @0x26e240 cmp r9, r1 */
/* @0x26e244 bhi 0x26a540 <pcre_compile+0x15b8> */
/* @0x26e248 ldrb r0, [r9] */
/* @0x26e24c ldrb r1, [r6, #0x28] */
/* @0x26e250 cmp r0, r1 */
/* @0x26e254 bne 0x26a540 <pcre_compile+0x15b8> */
/* @0x26e258 cmp r3, #1 */
/* @0x26e25c beq 0x26cbd0 <pcre_compile+0x3c48> */
/* @0x26e260 ldrb r1, [r9, #0x1] */
/* @0x26e264 ldrb r3, [r6, #0x29] */
/* @0x26e268 cmp r1, r3 */
/* @0x26e26c bne 0x26a540 <pcre_compile+0x15b8> */
/* @0x26e270 b 0x26cbd0 <pcre_compile+0x3c48> */
/* @0x26e274 ldr r9, [sp, #0x30] */
/* @0x26e278 add r1, r11, #1 */
/* @0x26e27c cmp r11, r9 */
/* @0x26e280 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26e284 mov r3, #1 */
/* @0x26e288 mvn r7, r7 */
/* @0x26e28c str r2, [r12, #0x4] */
/* @0x26e290 add r5, r5, r3 */
/* @0x26e294 str r7, [r12] */
/* @0x26e298 mov r11, r1 */
/* @0x26e29c str r3, [r12, #0x8] */
/* @0x26e2a0 add r12, r12, #12 */
/* @0x26e2a4 str r3, [sp, #0x64] */
/* @0x26e2a8 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26e2ac ldr r4, [sp, #0x48] */
/* @0x26e2b0 mov r0, r9 */
/* @0x26e2b4 add r3, r6, #36 */
/* @0x26e2b8 str r12, [sp, #0x1c] */
/* @0x26e2bc str r4, [sp] */
/* @0x26e2c0 bl 0x25f9fc <_pcre_is_newline> */
/* @0x26e2c4 ldr r12, [sp, #0x1c] */
/* @0x26e2c8 cmp r0, #0 */
/* @0x26e2cc bne 0x26cbd0 <pcre_compile+0x3c48> */
/* @0x26e2d0 b 0x26dd20 <pcre_compile+0x4d98> */
/* @0x26e2d4 mvn r0, #19 */
/* @0x26e2d8 b 0x2691e0 <pcre_compile+0x258> */
/* @0x26e2dc tst r0, #8 */
/* @0x26e2e0 bne 0x26e350 <pcre_compile+0x53c8> */
/* @0x26e2e4 ldrb r2, [r3, #0x3] */
/* @0x26e2e8 and r0, r0, #7 */
/* @0x26e2ec ldrb r1, [r3, #0x1] */
/* @0x26e2f0 ldrb r4, [r3, #0x2] */
/* @0x26e2f4 and r2, r2, #63 */
/* @0x26e2f8 and r1, r1, #63 */
/* @0x26e2fc orr r3, r2, r0, lsl #18 */
/* @0x26e300 and r2, r4, #63 */
/* @0x26e304 orr r3, r3, r1, lsl #12 */
/* @0x26e308 orr r0, r3, r2, lsl #6 */
/* @0x26e30c b 0x26abb4 <pcre_compile+0x1c2c> */
/* @0x26e310 mvn r0, #16 */
/* @0x26e314 b 0x2691e0 <pcre_compile+0x258> */
/* @0x26e318 ldr r4, [sp, #0x30] */
/* @0x26e31c add r2, r8, #1 */
/* @0x26e320 cmp r8, r4 */
/* @0x26e324 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26e328 ldr r9, [sp, #0x24] */
/* @0x26e32c mov r8, r2 */
/* @0x26e330 ldr r6, [sp, #0x60] */
/* @0x26e334 add r9, r9, #12 */
/* @0x26e338 add r7, r7, r6 */
/* @0x26e33c str r3, [r9, #-0x8] */
/* @0x26e340 add r3, r7, #3 */
/* @0x26e344 str r3, [r9, #-0xc] */
/* @0x26e348 str r9, [sp, #0x24] */
/* @0x26e34c b 0x26b198 <pcre_compile+0x2210> */
/* @0x26e350 tst r0, #4 */
/* @0x26e354 bne 0x26e534 <pcre_compile+0x55ac> */
/* @0x26e358 ldrb r1, [r3, #0x4] */
/* @0x26e35c and r4, r0, #3 */
/* @0x26e360 ldrb r2, [r3, #0x1] */
/* @0x26e364 and r0, r1, #63 */
/* @0x26e368 ldrb r1, [r3, #0x2] */
/* @0x26e36c ldrb r3, [r3, #0x3] */
/* @0x26e370 and r2, r2, #63 */
/* @0x26e374 orr r0, r0, r4, lsl #24 */
/* @0x26e378 and r1, r1, #63 */
/* @0x26e37c orr r2, r0, r2, lsl #18 */
/* @0x26e380 and r3, r3, #63 */
/* @0x26e384 orr r2, r2, r1, lsl #12 */
/* @0x26e388 orr r0, r2, r3, lsl #6 */
/* @0x26e38c b 0x26abb4 <pcre_compile+0x1c2c> */
/* @0x26e390 ldr r6, [sp, #0x28] */
/* @0x26e394 ldr r3, [r6, #0x24] */
/* @0x26e398 ldr r2, [r6, #0x8] */
/* @0x26e39c ldr r6, [sp, #0x38] */
/* @0x26e3a0 rsb r2, r3, r2 */
/* @0x26e3a4 cmp r6, r2 */
/* @0x26e3a8 bhi 0x26b950 <pcre_compile+0x29c8> */
/* @0x26e3ac ldrb r1, [r6] */
/* @0x26e3b0 ldr r6, [sp, #0x28] */
/* @0x26e3b4 ldrb r2, [r6, #0x28] */
/* @0x26e3b8 cmp r1, r2 */
/* @0x26e3bc bne 0x26b950 <pcre_compile+0x29c8> */
/* @0x26e3c0 cmp r3, #1 */
/* @0x26e3c4 addeq r5, r5, #1 */
/* @0x26e3c8 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26e3cc ldr r6, [sp, #0x38] */
/* @0x26e3d0 ldrb r2, [r6, #0x1] */
/* @0x26e3d4 ldr r6, [sp, #0x28] */
/* @0x26e3d8 ldrb r3, [r6, #0x29] */
/* @0x26e3dc cmp r2, r3 */
/* @0x26e3e0 addeq r5, r5, #1 */
/* @0x26e3e4 bne 0x26b950 <pcre_compile+0x29c8> */
/* @0x26e3e8 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26e3ec ldr r0, [sp, #0x28] */
/* @0x26e3f0 ldr r1, [sp, #0x38] */
/* @0x26e3f4 ldr r3, [r0, #0x24] */
/* @0x26e3f8 ldr r2, [r0, #0x8] */
/* @0x26e3fc rsb r2, r3, r2 */
/* @0x26e400 cmp r1, r2 */
/* @0x26e404 bhi 0x26b850 <pcre_compile+0x28c8> */
/* @0x26e408 ldrb r1, [r1] */
/* @0x26e40c ldrb r2, [r0, #0x28] */
/* @0x26e410 cmp r1, r2 */
/* @0x26e414 bne 0x26b850 <pcre_compile+0x28c8> */
/* @0x26e418 cmp r3, #1 */
/* @0x26e41c streq r6, [sp, #0x24] */
/* @0x26e420 addeq r5, r5, #1 */
/* @0x26e424 moveq r8, r4 */
/* @0x26e428 beq 0x269480 <pcre_compile+0x4f8> */
/* @0x26e42c ldr r3, [sp, #0x38] */
/* @0x26e430 ldr r0, [sp, #0x28] */
/* @0x26e434 ldrb r2, [r3, #0x1] */
/* @0x26e438 ldrb r3, [r0, #0x29] */
/* @0x26e43c cmp r2, r3 */
/* @0x26e440 streq r6, [sp, #0x24] */
/* @0x26e444 addeq r5, r5, #1 */
/* @0x26e448 moveq r8, r4 */
/* @0x26e44c bne 0x26b850 <pcre_compile+0x28c8> */
/* @0x26e450 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26e454 ldr r9, [sp, #0x30] */
/* @0x26e458 add r1, r11, #1 */
/* @0x26e45c cmp r11, r9 */
/* @0x26e460 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26e464 mov r3, #1 */
/* @0x26e468 mvn r7, r7 */
/* @0x26e46c str r2, [r12, #0x4] */
/* @0x26e470 add r5, r5, r3 */
/* @0x26e474 str r7, [r12] */
/* @0x26e478 mov r11, r1 */
/* @0x26e47c str r3, [r12, #0x8] */
/* @0x26e480 add r12, r12, #12 */
/* @0x26e484 str r3, [sp, #0x64] */
/* @0x26e488 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26e48c ldr r6, [sp, #0x48] */
/* @0x26e490 mov r0, r4 */
/* @0x26e494 add r3, r9, #36 */
/* @0x26e498 str r12, [sp, #0x1c] */
/* @0x26e49c str r6, [sp] */
/* @0x26e4a0 bl 0x25f9fc <_pcre_is_newline> */
/* @0x26e4a4 ldr r12, [sp, #0x1c] */
/* @0x26e4a8 cmp r0, #0 */
/* @0x26e4ac beq 0x26e528 <pcre_compile+0x55a0> */
/* @0x26e4b0 ldr r3, [r9, #0x24] */
/* @0x26e4b4 b 0x26df4c <pcre_compile+0x4fc4> */
/* @0x26e4b8 add r3, r3, #1 */
/* @0x26e4bc cmp r3, r12 */
/* @0x26e4c0 beq 0x26e560 <pcre_compile+0x55d8> */
/* @0x26e4c4 mov r2, r1 */
/* @0x26e4c8 b 0x26910c <pcre_compile+0x184> */
/* @0x26e4cc ldr r9, [sp, #0x48] */
/* @0x26e4d0 mov r0, r6 */
/* @0x26e4d4 add r3, r4, #36 */
/* @0x26e4d8 str r12, [sp, #0x1c] */
/* @0x26e4dc str r9, [sp] */
/* @0x26e4e0 bl 0x25f9fc <_pcre_is_newline> */
/* @0x26e4e4 ldr r12, [sp, #0x1c] */
/* @0x26e4e8 adds r0, r0, #0 */
/* @0x26e4ec movne r0, #1 */
/* @0x26e4f0 b 0x26cff8 <pcre_compile+0x4070> */
/* @0x26e4f4 ldr r6, [sp, #0x30] */
/* @0x26e4f8 add r2, r11, #1 */
/* @0x26e4fc cmp r11, r6 */
/* @0x26e500 bge 0x2691dc <pcre_compile+0x254> */
/* @0x26e504 add r3, r7, r3 */
/* @0x26e508 add r5, r5, #1 */
/* @0x26e50c add r3, r3, #1 */
/* @0x26e510 mov r11, r2 */
/* @0x26e514 str r3, [r12] */
/* @0x26e518 mov r3, #0 */
/* @0x26e51c add r12, r12, #12 */
/* @0x26e520 str r3, [r12, #-0x8] */
/* @0x26e524 b 0x269480 <pcre_compile+0x4f8> */
/* @0x26e528 ldr r9, [sp, #0x28] */
/* @0x26e52c ldr r2, [r9, #0x8] */
/* @0x26e530 b 0x26a61c <pcre_compile+0x1694> */
/* @0x26e534 ldrb r1, [r3, #0x5] */
/* @0x26e538 and r0, r0, #1 */
/* @0x26e53c ldrb r4, [r3, #0x1] */
/* @0x26e540 ldrb r2, [r3, #0x2] */
/* @0x26e544 and r1, r1, #63 */
/* @0x26e548 orr r0, r1, r0, lsl #30 */
/* @0x26e54c and r4, r4, #63 */
/* @0x26e550 ldrb r1, [r3, #0x3] */
/* @0x26e554 and r2, r2, #63 */
/* @0x26e558 ldrb r3, [r3, #0x4] */
/* @0x26e55c b 0x26e374 <pcre_compile+0x53ec> */
/* @0x26e560 str r1, [sp, #0x5c] */
/* @0x26e564 b 0x269224 <pcre_compile+0x29c> */
