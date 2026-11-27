/* cally 逆向卡：anon_26f1e8（原版 libyoyo.so，armv7）
 * @func 0x26f1e8 0x26ffac  size 3524  881 条（881×4 = 3524，窗口内全是指令、无字面量池）
 * 级别: 骨架（7 参协议、返回值码族、3 个被调、162 项操作码跳表、计数/上限双闸门、回溯节点压栈
 *             已逐条钉；但窗口本身不是闭合函数 —— 见「口径与边界」，窗口外 9465 条未定性）
 * 符号: **无符号名**。.dynsym 里没有本地址的条目；语义由调用点与指令推断，本卡不替它取名。
 *       最靠近的两个具名邻居都是 pcre_* 家族的导出件：pcre_dfa_exec（0x26e568，st_size 3200，
 *       其末字节 +1 恰好是本函数起点）、pcre_exec（0x279390，st_size 4408，紧接本函数体之后）。
 *       同层可复核的具名件：_pcre_is_newline 0x25f9fc（452 B）、_pcre_OP_lengths 0x38ba04（162 B）、
 *       _pcre_default_tables 0x38baa8（1088 B）、memcmp@plt 0xb6c40。
 * 身份: libyoyo.so sha256 = 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *       .text = 0x0b6fd0..0x31bb7c（asm/census.json：627423 条指令，attributed 627423，缺口 0）
 *
 * ── 一句话 ─────────────────────────────────────────────────────────────
 *   递归回溯式匹配核：一对游标（r0 = 主语串当前位置 eptr，r1 = 编译模式字节码当前字 ecode）
 *   在 162 项操作码跳表上分派前进。每次进入先把第 5 参结构里的调用计数自增、与两条上限比较
 *   （超限分别返回 -8 / -21）；需要回溯时把 {上一节点, 当前 eptr} 压成栈上 8 字节节点，把节点
 *   地址顶成第 6 参后自递归，第 7 参 = 深度 + 1。
 *
 * ── 口径与边界（不读这条会把它当 3524 B 的完整函数）────────────────────
 *   1. 本卡窗口 = 0x26f1e8..0x26ffac（3524 B / 881 条）。asm/functions.tsv 记同起点函数的体是
 *      size 41384 → 0x27938c、10346 条；asm/anon_splits.tsv 把它切成
 *      26f1e8(3524, bl,prologue) + 26ffac(37860, bl)。窗口只是该函数的前 8.5%。
 *   2. 切点 0x26ffac 处的指令是 `beq 0x2740d4`（条件分支），不是函数入口 ⇒ 这次切割不是函数
 *      边界，是索引器按 "bl" 证据切出来的段边界。本卡只对窗口内 881 条负责。
 *   3. 窗口内共 198 条分支跳出窗口，落在 102 个不同目标上，全部 < 0x27938c（即同一函数体内）；
 *      窗口内只有 2 条出口（0x26f5a4 / 0x26f6b4，都是 add sp,#316 + pop {r4-r11,pc}）。
 *   4. ⇒ 窗口内的「语义」只能按「入口 + 已读块 + 被调 + 返回码」表述；窗口中途的状态机不闭合，
 *      凡依赖窗口外块的行为一律记 open。
 *
 * ── 实参契约（AAPCS，7 个形参 = 4 寄存器 + 3 栈）────────────────────────
 *   帧 = push {r4-r11,lr}(36 B) + sub sp,#316(0x13C) = 0x160，所以入口栈参数落在
 *   [sp+0x160] / [sp+0x164] / [sp+0x168]；[sp+0x16c] 全窗口无任何读取 ⇒ 正好 7 参。
 *
 *   ① r0 = eptr：主语串当前游标（指针，只前进）
 *      0x26f1f8 mov r10,r0 是唯一的形参落位。全窗口 10 处 `mov r0,r10` 全部是把 eptr 当第 1
 *      实参：8 处喂自递归（0x26f634/0x26f7f8/0x26fa3c/0x26fbf0/0x26fdc0/0x26fe4c/0x26fed0/
 *      0x26ff5c）、1 处喂 _pcre_is_newline（0x26f750）、1 处喂 memcmp（0x26f914）。
 *      前进证据：memcmp 命中后 0x26f904 `add r10,r10,r8`（r8 = 比较长度）；0x26fb94
 *      `add r10,r10,#1`。上界证据：与 [r6+0x78]（串尾）做无符号比较（0x26f6f8、0x26f734、
 *      0x26f8f0、0x26fb30 等）。差值证据：0x26f594 `rsb r0,r10,r0`。
 *
 *   ② r1 = ecode：编译模式字节码当前字（指针，逐个操作码步进）
 *      0x26f1ec `subs r4,r1,#0` 落位到 r4/r11。操作码取值 49 处 `ldrb rX,[r11]`；分支/长度
 *      字段按大端 16 位读：0x26f5dc `ldrb r2,[r11,#1]` + 0x26f5e0 `ldrb r3,[r11,#2]` +
 *      0x26f5e4 `orr r3,r3,r2,lsl #8`，随后 0x26f5e8 `add r11,r11,r3` 跳过该操作码
 *      （同类 8 处：0x26f5e8/0x26f6d4/0x26f84c/0x26f920/0x26fa90/0x26fb98/0x26fbdc/0x26fd74）。
 *      按操作码查长度表：0x26f5cc `ldr r7,[r12,r3]`，其中 r12 = GOT 锚 0x3F1C58（0x26f1f4 →
 *      0x26f1fc 物化）、r3 = 0xFFFFFB8C = -1140 ⇒ 槽 0x3F17E4；该槽是 R_ARM_RELATIVE，
 *      文件内 addend = 0x38BA04 = _pcre_OP_lengths（llvm-readelf -s 可复核），于是
 *      0x26f640 `ldrb r1,[r7,r1]` + 0x26f650 `add r1,r11,r1` = 按操作码长度推进 ecode。
 *
 *   ③ r2 = 跨递归不变量（类型未定）
 *      唯一写点 0x26f200 `str r2,[sp,#0x1c]`（无条件写；0x26f20c 的 `beq` 用的是更早的 Z 标，见 ⑤-a）；
 *      8 处自递归全部 `ldr r2,[sp,#0x1c]` 原样回传（0x26f658/0x26f80c/0x26fc08/0x26fe74/
 *      0x26fee4/0x26ff68），另 2 处装进别的寄存器（0x26f9e8 → r4、0x26fd84 → r7）。
 *      窗口内对它没有任何算术或解引用 ⇒ 只证「跨层不变」。
 *
 *   ④ r3 = 跨递归不变量（同上）
 *      唯一写点 0x26f25c `str r3,[sp,#0x18]`；8 处读（0x26f65c/0x26f818/0x26fc0c/0x26f9e4→r5/
 *      0x26fd88→r8/0x26fe5c→r11/0x26fecc→r11/0x26ff50→r11）。
 *
 *   ⑤ [sp+0x160] = 上下文结构指针（本函数唯一写内存的对象）
 *      0x26f208 `ldr r6,[sp,#0x160]`。字段表见下一节。
 *      ⑤-a 特例：r1 == 0 时先走 0x26f1ec `subs r4,r1,#0` 设的 Z 标（0x26f1f0..0x26f208 这些
 *      指令都不写标），0x26f20c `beq 0x26f584` 跳到早退块 —— 那块只读第 7 参，完全不碰 r6。
 *
 *   ⑥ [sp+0x164] = 回溯位置链头（8 字节节点地址，可被本函数改写）
 *      0x26f564 `ldr r12,[sp,#0x164]`（旧链头）→ 0x26f568 `add r5,sp,#108`（= sp+0x6C，新节点
 *      地址）→ 0x26f570 `str r5,[sp,#0x164]`（顶上）→ 0x26f574 `str r10,[sp,#0x70]`（节点 +4 =
 *      当前 eptr）、0x26f578 `str r12,[sp,#0x6c]`（节点 +0 = 旧链头）⇒ 节点 = {+0 prev,
 *      +4 saved_eptr}，共 8 B，且节点地址就是 sp+0x6C。
 *
 *   ⑦ [sp+0x168] = 递归深度（每层 +1）
 *      0x26f63c `ldr lr,[sp,#0x168]` → 0x26f648 `add lr,lr,#1` → 0x26f654 `str lr,[sp,#8]`；
 *      同一模式见 0x26f7fc/0x26fa38/0x26fbec/0x26fdbc/0x26fec8/0x26ff58。入口 0x26f284 拿它
 *      与 [r6+8] 比较（0x26f288 cmp、0x26f28c bls → 0x274198 返回 -21）。
 *
 * ── 上下文结构（第 5 参 r6）在本窗口读到的字段（偏移 / 证据 / 用途）────────
 *   +0x00 int  调用计数：0x26f260 ldr 旧值 → 0x26f26c add #1 → 0x26f274 str **无条件先写**，
 *              写完才用旧值比较（0x26f270 cmp 旧值,[+0x04]；0x26f27c bhs → 0x274148 = -8）
 *   +0x04 int  计数上限
 *   +0x08 int  深度上限：0x26f280 ldr → 0x26f288 cmp 与第 7 参 → 0x26f28c bls → 0x274198 = -21
 *   +0x18 int  换行类型：0x26f73c ldr → 当 _pcre_is_newline 的第 2 实参
 *   +0x1C      0x26f754 `add r3,r6,#28` ⇒ &[+0x1C]，当 _pcre_is_newline 的第 4 实参（输出槽）
 *   +0x28 int  第二组计数：0x26ff0c ldr → 0x26ff14 add #1 → 0x26ff18 str → 0x26ff1c cmp [+0x2C]
 *   +0x2C int  第二组上限
 *   +0x4C int  UTF-8 标志：0x26f268 ldr → 0x26f278 存 [sp+0x28] → 当 _pcre_is_newline 第 5 实参
 *   +0x64 int  「部分匹配」标志：0x26f71c mov r1,#1 → 0x26f720 str；条件 [+0x88]!=0 且
 *              eptr > [+0x84]，且 [+0x88] > 1 时 0x26f728 返回 -12
 *   +0x78      串尾指针：5 处装载（0x26f6f4/0x26f730/0x26f8e8/0x26fb2c/…），随即与 eptr 比较
 *   +0x7C int* 成功位置：0x26feb4 `streq r4,[r6,#0x7c]` —— 只在子调用 r0==0（成功）时把当前
 *              ecode（r4 = r11）写进去，随后同一块把返回改成 -992 上抛（见「返回值」）
 *   +0x84      与 eptr 比较的下界（0x26f70c ldr → 0x26f710 cmp）
 *   +0x88      三态开关：0/1/其它（0x26f700 ldr → 0x26f704/0x26f718 比较）
 *   +0x8C/+0xA4/+0xB0  窗口内各 1 次装载/写入（0x26fa9c / 0x26fd08 / 0x26fe48），用途未定
 *   +0x90 ptr  0x26f664 装进 r9，递归前置 0x26f5fc `str r9,[r6,#0x90]` 回存
 *   +0x98 int  小整数：==2 才压回溯节点（0x26f290 ldr → 0x26f294 cmp #2 → 0x26f298 beq 0x26f564）；
 *              可写 2（0x26f604 `strne r8,#2`、0x26f7f0 `strhi r8,#2`）或 0（0x26f57c）
 *   +0xAC ptr  0x26f660 装进 r4，递归前置 0x26f5ec `str r4,[r6,#0xac]` 回存；0x26feac 条件写
 *   另读：+0x0C +0x10 +0x14（0x26f964..0x26f97c）、+0x38（0x26fb78 字符表基址）、+0x44 +0x48
 *        +0x58 +0x6C +0x70 +0x74 +0x80（0x26f6b8..0x26fa8c）
 *
 * ── 返回值（int，r0）──────────────────────────────────────────────────
 *   窗口内出口只有两个（0x26f5a4 / 0x26f6b4），但两条返回码来自窗口外的块；按全函数扫
 *   `mvn r0,#N` 与 `movw+movt` 得到这组常数：
 *     -8   (0x274148 mvn r0,#7)   计数 >= 上限，窗口入口 0x26f27c bhs 直达
 *     -21  (0x274198 mvn r0,#20)  深度 >= 深度上限，0x26f28c bls 直达
 *     -12  (0x26f728、0x272678)   窗口内就有：0x26f728 `mvn r0,#11`
 *     -5   (0x271a18)             操作码 > 161 的跳表越界出口
 *     -6   (0x278ccc) / -14 (0x272a74 等 6 处) / -26 (0x271658)
 *   ⇒ {-5,-6,-8,-12,-14,-21,-26} 正好是 PCRE1 错误表里 UNKNOWN_OPCODE / NOMEMORY / MATCHLIMIT /
 *      PARTIAL / INTERNAL / RECURSIONLIMIT / RECURSELOOP 那一组（只作定位证据，不据此命名函数）。
 *   另有 -992（0x26f6a8、0x26feb8）与 -995（0x271438）不在该表里：
 *     -992 是**成功上抛哨兵**，不是错误 —— 0x26feb0 `cmp r0,#0` → 0x26feb4 只在子结果 == 0
 *     （成功）时才写 [+0x7C]=ecode，紧接着 0x26feb8/0x26febc 把 r0 改成 0xFFFFFC20 再返回；
 *     上一层 0x26f66c `cmn r0,#992` 专门识别它并按同一套「记位置 + 再上抛」处理。
 *   非匹配路径的推进量：0x26f584 分支 r0 = -|(&第 7 参槽) - eptr|
 *     （0x26f590 `add r0,sp,#360` → 0x26f594 `rsb r0,r10,r0` → 0x26f59c `rsbgt r0,r0,#0`）。
 *
 * ── 它调了谁（窗口内 10 条 bl、3 个不同目标；无 blx、无函数指针物化）──────────
 *   自身 0x26f1e8      ×8   0x26f668 0x26f824 0x26fa78 0x26fc10 0x26fde0 0x26fe8c
 *                            0x26fef4 0x26ff78 —— 8 处都是 eptr 原样、ecode 换成新位置、
 *                            第 3/4 参原样、第 6 参透传、第 7 参 +1
 *   _pcre_is_newline   ×1   0x26f75c（0x25f9fc，452 B）5 实参：r0=eptr、r1=[r6+0x18]、
 *                            r2=[r6+0x78]、r3=&[r6+0x1C]、[sp]=[r6+0x4C]（形状与
 *                            (ptr, type, endptr, int*, utf8) 的 5 参一致，但不据此命名）
 *   memcmp@plt         ×1   0x26f924：r0=eptr、r1=模式内字面量串、r2=r8 长度；
 *                            返回 0 后 0x26f904 前进 r8，非 0 转 0x26f930 的回溯判定
 *
 * ── 谁调它（asm/instructions.jsonl 全量扫 bl 立即数，59 条命中）──────────────
 *   自身递归 57 条：全部在 0x26f1e8..0x27938c 体内（窗口内 8 条，窗口外 49 条）
 *   pcre_exec 0x279390 ×2：0x2794ac、0x279c74
 *   ⇒ **对外只有 2 个调用点**；「59 处引用」里 96.6% 是自递归，不能当热度用。
 *   0x279c74（正常匹配入口形态）：r0=r7、r1=[sp+0xf0]、r2=r7、r3=2、
 *        [sp]=r2、[sp+4]=r10、[sp+8]=r10
 *   0x2794ac（退化形态）：r0=sp+0x80、r1=r2=r3=0、[sp]=[sp+4]=0、[sp+8]=1
 *        → 落进 r1==0 的早退块 0x26f584（不碰第 5 参），按上面的公式返回 -0x78 量级的负值
 *
 * ── 操作码分派（窗口内最硬的一条结构）──────────────────────────────────
 *   0x26f2b0 mov r9,r5 → 0x26f2b4 cmp r5,#161 → 0x26f2b8 `addls pc,pc,r5,lsl #2`
 *   ⇒ 表基 = 0x26f2b8 + 8 = 0x26f2c0，162 项（操作码 0..161）× 4 B = 0x288，末项止于 0x26f548；
 *     这 162 个槽全是 `b` 指令、指向 81 个不同 handler（有合并）。
 *   越界（操作码 > 161）时 `addls` 不执行，落到 0x26f2bc `b 0x271a18` → 返回 -5。
 *
 * ── open ─────────────────────────────────────────────────────────────
 *   1. 窗口只是前 881/10346 条（8.5%）；0x26ffac 不是函数边界，完整函数体未出卡。
 *   2. 窗口内 102 个出窗分支目标对应的块全部未定性 ⇒ 中途状态机不闭合。
 *   3. 第 3 / 第 4 形参的类型未定：只证「跨递归不变、未被解引用、未参与算术」。
 *   4. 六次 PIC 物化全部得到同一个 0x38BB50（= _pcre_default_tables + 0xA8，落在 lcc 恒等表
 *      中间：该地址首字节 0xA8、且 0x38baa8 处才是 00 01 02… 的恒等表）。六个槽
 *      sp+0x34/0x38/0x3C/0x40/0x44/0x48 写入后窗口内无任何读取；用途未定。
 *   5. -995（0x271438）的来源未定。
 *   6. pcre_exec 0x2794ac 那个全零退化调用的用途未定（返回 -0x78 量级负值，语义不明）。
 *   7. +0x28/+0x2C 那组第二「计数/上限」对应哪一种上限未定。
 *   8. +0x8C / +0xA4 / +0xB0 三个字段各只有 1 次访问，用途未定。
 *
 * ── 逐条锚点（881 条，与 asm/index-anon_26f1e8.tsv 逐字一致）──────────────
 */
/* ── 入口 / 帧 / 形参落位 ────────────────────────────────────── */
/* @0x26f1e8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x26f1ec subs r4, r1, #0 */
/* @0x26f1f0 sub sp, sp, #316 */
/* @0x26f1f4 ldr r5, [pc, #0xff0] */
/* @0x26f1f8 mov r10, r0 */
/* @0x26f1fc add r5, pc, r5 */
/* @0x26f200 str r2, [sp, #0x1c] */
/* @0x26f204 str r5, [sp, #0x20] */
/* @0x26f208 ldr r6, [sp, #0x160] */
/* @0x26f20c beq 0x26f584 <pcre_dfa_exec+0x101c> */
/* ── 六次 PIC 物化：全部 = 0x38BB50（_pcre_default_tables + 0xA8）── */
/* @0x26f210 ldr r7, [pc, #0xfd8] */
/* @0x26f214 mov r11, r4 */
/* @0x26f218 ldr r12, [pc, #0xfd4] */
/* @0x26f21c ldr r5, [pc, #0xfd4] */
/* @0x26f220 add r7, pc, r7 */
/* @0x26f224 add r12, pc, r12 */
/* @0x26f228 str r7, [sp, #0x34] */
/* @0x26f22c add r5, pc, r5 */
/* @0x26f230 str r12, [sp, #0x38] */
/* @0x26f234 str r5, [sp, #0x3c] */
/* @0x26f238 ldr r7, [pc, #0xfbc] */
/* @0x26f23c ldr r12, [pc, #0xfbc] */
/* @0x26f240 ldr r5, [pc, #0xfbc] */
/* @0x26f244 add r7, pc, r7 */
/* @0x26f248 add r12, pc, r12 */
/* @0x26f24c str r7, [sp, #0x44] */
/* @0x26f250 add r5, pc, r5 */
/* @0x26f254 str r12, [sp, #0x48] */
/* @0x26f258 str r5, [sp, #0x40] */
/* ── 第 5 参结构：调用计数自增 + 两条上限（-8 / -21）────────────── */
/* @0x26f25c str r3, [sp, #0x18] */
/* @0x26f260 ldr r3, [r6] */
/* @0x26f264 ldr r2, [r6, #0x4] */
/* @0x26f268 ldr r7, [r6, #0x4c] */
/* @0x26f26c add r1, r3, #1 */
/* @0x26f270 cmp r3, r2 */
/* @0x26f274 str r1, [r6] */
/* @0x26f278 str r7, [sp, #0x28] */
/* @0x26f27c bhs 0x274148 <pcre_dfa_exec+0x5be0> */
/* @0x26f280 ldr r2, [r6, #0x8] */
/* @0x26f284 ldr r3, [sp, #0x168] */
/* @0x26f288 cmp r2, r3 */
/* @0x26f28c bls 0x274198 <pcre_dfa_exec+0x5c30> */
/* ── 回溯节点闸门：[+0x98] == 2 才压栈 ──────────────────────── */
/* @0x26f290 ldr r3, [r6, #0x98] */
/* @0x26f294 cmp r3, #2 */
/* @0x26f298 beq 0x26f564 <pcre_dfa_exec+0xffc> */
/* ── 每轮取操作码 ──────────────────────────────────────────── */
/* @0x26f29c ldr r7, [sp, #0x28] */
/* @0x26f2a0 ldrb r5, [r11] */
/* @0x26f2a4 adds r7, r7, #0 */
/* @0x26f2a8 movne r7, #1 */
/* @0x26f2ac str r7, [sp, #0x24] */
/* ── 操作码分派：162 项跳表（0..161，基址 = 本条 +8 = 0x26f2c0）── */
/* @0x26f2b0 mov r9, r5 */
/* @0x26f2b4 cmp r5, #161 */
/* @0x26f2b8 addls pc, pc, r5, lsl #2 */
/* ── 越界 default：opcode > 161 → 0x271a18（返回 -5）──────────── */
/* @0x26f2bc b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* ── 跳表 162 项（表体，逐项是 b）───────────────────────────── */
/* @0x26f2c0 b 0x270014 <pcre_dfa_exec+0x1aac> */
/* @0x26f2c4 b 0x26f6c4 <pcre_dfa_exec+0x115c> */
/* @0x26f2c8 b 0x26fff4 <pcre_dfa_exec+0x1a8c> */
/* @0x26f2cc b 0x2708e0 <pcre_dfa_exec+0x2378> */
/* @0x26f2d0 b 0x2707f8 <pcre_dfa_exec+0x2290> */
/* @0x26f2d4 b 0x2707f8 <pcre_dfa_exec+0x2290> */
/* @0x26f2d8 b 0x270cd0 <pcre_dfa_exec+0x2768> */
/* @0x26f2dc b 0x270794 <pcre_dfa_exec+0x222c> */
/* @0x26f2e0 b 0x270c6c <pcre_dfa_exec+0x2704> */
/* @0x26f2e4 b 0x270ba4 <pcre_dfa_exec+0x263c> */
/* @0x26f2e8 b 0x270c08 <pcre_dfa_exec+0x26a0> */
/* @0x26f2ec b 0x2706c0 <pcre_dfa_exec+0x2158> */
/* @0x26f2f0 b 0x270b08 <pcre_dfa_exec+0x25a0> */
/* @0x26f2f4 b 0x270aa4 <pcre_dfa_exec+0x253c> */
/* @0x26f2f8 b 0x270b88 <pcre_dfa_exec+0x2620> */
/* @0x26f2fc b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f300 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f304 b 0x270724 <pcre_dfa_exec+0x21bc> */
/* @0x26f308 b 0x270a30 <pcre_dfa_exec+0x24c8> */
/* @0x26f30c b 0x2708f0 <pcre_dfa_exec+0x2388> */
/* @0x26f310 b 0x270388 <pcre_dfa_exec+0x1e20> */
/* @0x26f314 b 0x270320 <pcre_dfa_exec+0x1db8> */
/* @0x26f318 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f31c b 0x26f730 <pcre_dfa_exec+0x11c8> */
/* @0x26f320 b 0x26f6f4 <pcre_dfa_exec+0x118c> */
/* @0x26f324 b 0x26f6dc <pcre_dfa_exec+0x1174> */
/* @0x26f328 b 0x27179c <pcre_dfa_exec+0x3234> */
/* @0x26f32c b 0x26f6b8 <pcre_dfa_exec+0x1150> */
/* @0x26f330 b 0x2704cc <pcre_dfa_exec+0x1f64> */
/* @0x26f334 b 0x270444 <pcre_dfa_exec+0x1edc> */
/* @0x26f338 b 0x26fb2c <pcre_dfa_exec+0x15c4> */
/* @0x26f33c b 0x271700 <pcre_dfa_exec+0x3198> */
/* @0x26f340 b 0x271700 <pcre_dfa_exec+0x3198> */
/* @0x26f344 b 0x2703fc <pcre_dfa_exec+0x1e94> */
/* @0x26f348 b 0x2703fc <pcre_dfa_exec+0x1e94> */
/* @0x26f34c b 0x2703fc <pcre_dfa_exec+0x1e94> */
/* @0x26f350 b 0x2703fc <pcre_dfa_exec+0x1e94> */
/* @0x26f354 b 0x2703fc <pcre_dfa_exec+0x1e94> */
/* @0x26f358 b 0x2703fc <pcre_dfa_exec+0x1e94> */
/* @0x26f35c b 0x2703f0 <pcre_dfa_exec+0x1e88> */
/* @0x26f360 b 0x2703f0 <pcre_dfa_exec+0x1e88> */
/* @0x26f364 b 0x270698 <pcre_dfa_exec+0x2130> */
/* @0x26f368 b 0x270678 <pcre_dfa_exec+0x2110> */
/* @0x26f36c b 0x270658 <pcre_dfa_exec+0x20f0> */
/* @0x26f370 b 0x27063c <pcre_dfa_exec+0x20d4> */
/* @0x26f374 b 0x26f864 <pcre_dfa_exec+0x12fc> */
/* @0x26f378 b 0x2703fc <pcre_dfa_exec+0x1e94> */
/* @0x26f37c b 0x2703fc <pcre_dfa_exec+0x1e94> */
/* @0x26f380 b 0x2703fc <pcre_dfa_exec+0x1e94> */
/* @0x26f384 b 0x2703fc <pcre_dfa_exec+0x1e94> */
/* @0x26f388 b 0x2703fc <pcre_dfa_exec+0x1e94> */
/* @0x26f38c b 0x2703fc <pcre_dfa_exec+0x1e94> */
/* @0x26f390 b 0x2703f0 <pcre_dfa_exec+0x1e88> */
/* @0x26f394 b 0x2703f0 <pcre_dfa_exec+0x1e88> */
/* @0x26f398 b 0x270698 <pcre_dfa_exec+0x2130> */
/* @0x26f39c b 0x270678 <pcre_dfa_exec+0x2110> */
/* @0x26f3a0 b 0x270658 <pcre_dfa_exec+0x20f0> */
/* @0x26f3a4 b 0x27063c <pcre_dfa_exec+0x20d4> */
/* @0x26f3a8 b 0x26f864 <pcre_dfa_exec+0x12fc> */
/* @0x26f3ac b 0x271050 <pcre_dfa_exec+0x2ae8> */
/* @0x26f3b0 b 0x271050 <pcre_dfa_exec+0x2ae8> */
/* @0x26f3b4 b 0x271050 <pcre_dfa_exec+0x2ae8> */
/* @0x26f3b8 b 0x271050 <pcre_dfa_exec+0x2ae8> */
/* @0x26f3bc b 0x271050 <pcre_dfa_exec+0x2ae8> */
/* @0x26f3c0 b 0x271050 <pcre_dfa_exec+0x2ae8> */
/* @0x26f3c4 b 0x271020 <pcre_dfa_exec+0x2ab8> */
/* @0x26f3c8 b 0x271020 <pcre_dfa_exec+0x2ab8> */
/* @0x26f3cc b 0x270ffc <pcre_dfa_exec+0x2a94> */
/* @0x26f3d0 b 0x270fe0 <pcre_dfa_exec+0x2a78> */
/* @0x26f3d4 b 0x270fc4 <pcre_dfa_exec+0x2a5c> */
/* @0x26f3d8 b 0x270fac <pcre_dfa_exec+0x2a44> */
/* @0x26f3dc b 0x270dd0 <pcre_dfa_exec+0x2868> */
/* @0x26f3e0 b 0x271050 <pcre_dfa_exec+0x2ae8> */
/* @0x26f3e4 b 0x271050 <pcre_dfa_exec+0x2ae8> */
/* @0x26f3e8 b 0x271050 <pcre_dfa_exec+0x2ae8> */
/* @0x26f3ec b 0x271050 <pcre_dfa_exec+0x2ae8> */
/* @0x26f3f0 b 0x271050 <pcre_dfa_exec+0x2ae8> */
/* @0x26f3f4 b 0x271050 <pcre_dfa_exec+0x2ae8> */
/* @0x26f3f8 b 0x271020 <pcre_dfa_exec+0x2ab8> */
/* @0x26f3fc b 0x271020 <pcre_dfa_exec+0x2ab8> */
/* @0x26f400 b 0x270ffc <pcre_dfa_exec+0x2a94> */
/* @0x26f404 b 0x270fe0 <pcre_dfa_exec+0x2a78> */
/* @0x26f408 b 0x270fc4 <pcre_dfa_exec+0x2a5c> */
/* @0x26f40c b 0x270fac <pcre_dfa_exec+0x2a44> */
/* @0x26f410 b 0x270dd0 <pcre_dfa_exec+0x2868> */
/* @0x26f414 b 0x270d34 <pcre_dfa_exec+0x27cc> */
/* @0x26f418 b 0x270d34 <pcre_dfa_exec+0x27cc> */
/* @0x26f41c b 0x270d34 <pcre_dfa_exec+0x27cc> */
/* @0x26f420 b 0x270d34 <pcre_dfa_exec+0x27cc> */
/* @0x26f424 b 0x270d34 <pcre_dfa_exec+0x27cc> */
/* @0x26f428 b 0x270d34 <pcre_dfa_exec+0x27cc> */
/* @0x26f42c b 0x27116c <pcre_dfa_exec+0x2c04> */
/* @0x26f430 b 0x27116c <pcre_dfa_exec+0x2c04> */
/* @0x26f434 b 0x27114c <pcre_dfa_exec+0x2be4> */
/* @0x26f438 b 0x2710b8 <pcre_dfa_exec+0x2b50> */
/* @0x26f43c b 0x271098 <pcre_dfa_exec+0x2b30> */
/* @0x26f440 b 0x2711bc <pcre_dfa_exec+0x2c54> */
/* @0x26f444 b 0x271198 <pcre_dfa_exec+0x2c30> */
/* @0x26f448 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f44c b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f450 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f454 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f458 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f45c b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f460 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f464 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f468 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f46c b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f470 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f474 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f478 b 0x2711d4 <pcre_dfa_exec+0x2c6c> */
/* @0x26f47c b 0x2711d4 <pcre_dfa_exec+0x2c6c> */
/* @0x26f480 b 0x270140 <pcre_dfa_exec+0x1bd8> */
/* @0x26f484 b 0x2702a0 <pcre_dfa_exec+0x1d38> */
/* @0x26f488 b 0x2702a0 <pcre_dfa_exec+0x1d38> */
/* @0x26f48c b 0x271660 <pcre_dfa_exec+0x30f8> */
/* @0x26f490 b 0x271660 <pcre_dfa_exec+0x30f8> */
/* @0x26f494 b 0x2715f8 <pcre_dfa_exec+0x3090> */
/* @0x26f498 b 0x271470 <pcre_dfa_exec+0x2f08> */
/* @0x26f49c b 0x26f548 <pcre_dfa_exec+0xfe0> */
/* @0x26f4a0 b 0x26fc90 <pcre_dfa_exec+0x1728> */
/* @0x26f4a4 b 0x26fc90 <pcre_dfa_exec+0x1728> */
/* @0x26f4a8 b 0x26fc90 <pcre_dfa_exec+0x1728> */
/* @0x26f4ac b 0x26fc90 <pcre_dfa_exec+0x1728> */
/* @0x26f4b0 b 0x26ff90 <pcre_dfa_exec+0x1a28> */
/* @0x26f4b4 b 0x26fba0 <pcre_dfa_exec+0x1638> */
/* @0x26f4b8 b 0x27096c <pcre_dfa_exec+0x2404> */
/* @0x26f4bc b 0x26fba0 <pcre_dfa_exec+0x1638> */
/* @0x26f4c0 b 0x27096c <pcre_dfa_exec+0x2404> */
/* @0x26f4c4 b 0x26f5a8 <pcre_dfa_exec+0x1040> */
/* @0x26f4c8 b 0x26fd7c <pcre_dfa_exec+0x1814> */
/* @0x26f4cc b 0x26f5a8 <pcre_dfa_exec+0x1040> */
/* @0x26f4d0 b 0x26f7a8 <pcre_dfa_exec+0x1240> */
/* @0x26f4d4 b 0x27050c <pcre_dfa_exec+0x1fa4> */
/* @0x26f4d8 b 0x26f954 <pcre_dfa_exec+0x13ec> */
/* @0x26f4dc b 0x26fabc <pcre_dfa_exec+0x1554> */
/* @0x26f4e0 b 0x26f5a8 <pcre_dfa_exec+0x1040> */
/* @0x26f4e4 b 0x26f7a8 <pcre_dfa_exec+0x1240> */
/* @0x26f4e8 b 0x27050c <pcre_dfa_exec+0x1fa4> */
/* @0x26f4ec b 0x26f954 <pcre_dfa_exec+0x13ec> */
/* @0x26f4f0 b 0x26fabc <pcre_dfa_exec+0x1554> */
/* @0x26f4f4 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f4f8 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f4fc b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f500 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f504 b 0x271a18 <pcre_dfa_exec+0x34b0> */
/* @0x26f508 b 0x2713a0 <pcre_dfa_exec+0x2e38> */
/* @0x26f50c b 0x271834 <pcre_dfa_exec+0x32cc> */
/* @0x26f510 b 0x271444 <pcre_dfa_exec+0x2edc> */
/* @0x26f514 b 0x271538 <pcre_dfa_exec+0x2fd0> */
/* @0x26f518 b 0x2713fc <pcre_dfa_exec+0x2e94> */
/* @0x26f51c b 0x271894 <pcre_dfa_exec+0x332c> */
/* @0x26f520 b 0x26ff48 <pcre_dfa_exec+0x19e0> */
/* @0x26f524 b 0x26ff0c <pcre_dfa_exec+0x19a4> */
/* @0x26f528 b 0x26fec4 <pcre_dfa_exec+0x195c> */
/* @0x26f52c b 0x26fe30 <pcre_dfa_exec+0x18c8> */
/* @0x26f530 b 0x270070 <pcre_dfa_exec+0x1b08> */
/* @0x26f534 b 0x270068 <pcre_dfa_exec+0x1b00> */
/* @0x26f538 b 0x270014 <pcre_dfa_exec+0x1aac> */
/* @0x26f53c b 0x270014 <pcre_dfa_exec+0x1aac> */
/* @0x26f540 b 0x2700b8 <pcre_dfa_exec+0x1b50> */
/* @0x26f544 b 0x26fc68 <pcre_dfa_exec+0x1700> */
/* ── 表尾之后的第一个真实块（ALT 链跳过）────────────────────── */
/* @0x26f548 ldrb r2, [r11, #0x1] */
/* @0x26f54c ldrb r3, [r11, #0x2] */
/* @0x26f550 orr r3, r3, r2, lsl #8 */
/* @0x26f554 ldrb r5, [r11, r3]! */
/* @0x26f558 cmp r5, #119 */
/* @0x26f55c beq 0x26f548 <pcre_dfa_exec+0xfe0> */
/* @0x26f560 b 0x26f2b0 <pcre_dfa_exec+0xd48> */
/* ── 压回溯节点 {+0 prev, +4 saved_eptr} @ sp+0x6C ──────────── */
/* @0x26f564 ldr r12, [sp, #0x164] */
/* @0x26f568 add r5, sp, #108 */
/* @0x26f56c mov r3, #0 */
/* @0x26f570 str r5, [sp, #0x164] */
/* @0x26f574 str r10, [sp, #0x70] */
/* @0x26f578 str r12, [sp, #0x6c] */
/* @0x26f57c str r3, [r6, #0x98] */
/* @0x26f580 b 0x26f29c <pcre_dfa_exec+0xd34> */
/* ── r1 == 0 早退（不碰第 5 参）────────────────────────────── */
/* @0x26f584 ldr r3, [sp, #0x168] */
/* @0x26f588 cmp r3, #0 */
/* @0x26f58c beq 0x273304 <pcre_dfa_exec+0x4d9c> */
/* @0x26f590 add r0, sp, #360 */
/* @0x26f594 rsb r0, r10, r0 */
/* @0x26f598 cmp r0, #0 */
/* @0x26f59c rsbgt r0, r0, #0 */
/* ── 出口 1：add sp,#316 + pop ─────────────────────────────── */
/* @0x26f5a0 add sp, sp, #316 */
/* @0x26f5a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 取 _pcre_OP_lengths（GOT 0x3F17E4 → 0x38BA04）─────────── */
/* @0x26f5a8 subs r9, r5, #129 */
/* @0x26f5ac ldr r3, [pc, #0xc54] */
/* @0x26f5b0 ldr r12, [sp, #0x20] */
/* @0x26f5b4 rsbs r2, r9, #0 */
/* @0x26f5b8 adcs r2, r2, r9 */
/* @0x26f5bc mov r8, #2 */
/* @0x26f5c0 cmp r5, #135 */
/* @0x26f5c4 movls r5, r2 */
/* @0x26f5c8 orrhi r5, r2, #1 */
/* @0x26f5cc ldr r7, [r12, r3] */
/* @0x26f5d0 b 0x26f600 <pcre_dfa_exec+0x1098> */
/* @0x26f5d4 cmp r0, #0 */
/* @0x26f5d8 bne 0x279284 <pcre_dfa_exec+0xad1c> */
/* @0x26f5dc ldrb r2, [r11, #0x1] */
/* @0x26f5e0 ldrb r3, [r11, #0x2] */
/* @0x26f5e4 orr r3, r3, r2, lsl #8 */
/* @0x26f5e8 add r11, r11, r3 */
/* @0x26f5ec str r4, [r6, #0xac] */
/* @0x26f5f0 ldrb r3, [r11] */
/* @0x26f5f4 cmp r3, #119 */
/* @0x26f5f8 bne 0x270008 <pcre_dfa_exec+0x1aa0> */
/* @0x26f5fc str r9, [r6, #0x90] */
/* @0x26f600 cmp r5, #0 */
/* @0x26f604 strne r8, [r6, #0x98] */
/* @0x26f608 bne 0x26f630 <pcre_dfa_exec+0x10c8> */
/* @0x26f60c ldr r3, [r6, #0x6c] */
/* @0x26f610 cmp r3, #0 */
/* @0x26f614 bne 0x26f630 <pcre_dfa_exec+0x10c8> */
/* @0x26f618 ldrb r2, [r11, #0x1] */
/* @0x26f61c ldrb r3, [r11, #0x2] */
/* @0x26f620 orr r3, r3, r2, lsl #8 */
/* @0x26f624 ldrb r3, [r11, r3] */
/* @0x26f628 cmp r3, #119 */
/* @0x26f62c bne 0x275688 <pcre_dfa_exec+0x7120> */
/* ── 首例自递归（字面量串逐字节）───────────────────────────── */
/* @0x26f630 ldrb r1, [r11] */
/* @0x26f634 mov r0, r10 */
/* @0x26f638 ldr r12, [sp, #0x164] */
/* @0x26f63c ldr lr, [sp, #0x168] */
/* @0x26f640 ldrb r1, [r7, r1] */
/* @0x26f644 str r6, [sp] */
/* @0x26f648 add lr, lr, #1 */
/* @0x26f64c str r12, [sp, #0x4] */
/* @0x26f650 add r1, r11, r1 */
/* @0x26f654 str lr, [sp, #0x8] */
/* @0x26f658 ldr r2, [sp, #0x1c] */
/* @0x26f65c ldr r3, [sp, #0x18] */
/* @0x26f660 ldr r4, [r6, #0xac] */
/* @0x26f664 ldr r9, [r6, #0x90] */
/* @0x26f668 bl 0x26f1e8 <pcre_dfa_exec+0xc80> */
/* ── -992 成功哨兵：识别并上抛 ─────────────────────────────── */
/* @0x26f66c cmn r0, #992 */
/* @0x26f670 bne 0x26f5d4 <pcre_dfa_exec+0x106c> */
/* @0x26f674 ldrb r1, [r11, #0x1] */
/* @0x26f678 ldrb r3, [r11, #0x2] */
/* @0x26f67c ldr r2, [r6, #0x7c] */
/* @0x26f680 orr r3, r3, r1, lsl #8 */
/* @0x26f684 add r3, r11, r3 */
/* @0x26f688 cmp r3, r2 */
/* @0x26f68c bls 0x26f6a8 <pcre_dfa_exec+0x1140> */
/* @0x26f690 ldrb r2, [r11] */
/* @0x26f694 cmp r2, #119 */
/* @0x26f698 beq 0x2732c4 <pcre_dfa_exec+0x4d5c> */
/* @0x26f69c ldrb r2, [r3] */
/* @0x26f6a0 cmp r2, #119 */
/* @0x26f6a4 beq 0x2732c4 <pcre_dfa_exec+0x4d5c> */
/* ── 出口 2：返回 -992 ────────────────────────────────────── */
/* @0x26f6a8 movw r0, #0xfc20 */
/* @0x26f6ac movt r0, #0xffff */
/* @0x26f6b0 add sp, sp, #316 */
/* @0x26f6b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x26f6b8 ldr r3, [r6, #0x44] */
/* @0x26f6bc cmp r3, #0 */
/* @0x26f6c0 bne 0x270008 <pcre_dfa_exec+0x1aa0> */
/* @0x26f6c4 ldr r3, [r6, #0x74] */
/* @0x26f6c8 cmp r3, r10 */
/* @0x26f6cc bne 0x270008 <pcre_dfa_exec+0x1aa0> */
/* @0x26f6d0 ldrb r5, [r11, #0x1] */
/* @0x26f6d4 add r11, r11, #1 */
/* @0x26f6d8 b 0x26f2b0 <pcre_dfa_exec+0xd48> */
/* ── 以下至 0x26f8e8 为逐个操作码的判定块（未逐块定性）──────── */
/* @0x26f6dc ldr r3, [r6, #0x48] */
/* @0x26f6e0 cmp r3, #0 */
/* @0x26f6e4 bne 0x270008 <pcre_dfa_exec+0x1aa0> */
/* @0x26f6e8 ldr r3, [r6, #0x58] */
/* @0x26f6ec cmp r3, #0 */
/* @0x26f6f0 beq 0x26f730 <pcre_dfa_exec+0x11c8> */
/* @0x26f6f4 ldr r9, [r6, #0x78] */
/* @0x26f6f8 cmp r10, r9 */
/* @0x26f6fc blo 0x270008 <pcre_dfa_exec+0x1aa0> */
/* @0x26f700 ldr r2, [r6, #0x88] */
/* @0x26f704 cmp r2, #0 */
/* @0x26f708 beq 0x26f6d0 <pcre_dfa_exec+0x1168> */
/* @0x26f70c ldr r3, [r6, #0x84] */
/* @0x26f710 cmp r10, r3 */
/* @0x26f714 bls 0x26f6d0 <pcre_dfa_exec+0x1168> */
/* @0x26f718 cmp r2, #1 */
/* @0x26f71c mov r1, #1 */
/* @0x26f720 str r1, [r6, #0x64] */
/* @0x26f724 ble 0x26f6d0 <pcre_dfa_exec+0x1168> */
/* ── 窗口内返回 -12（0x26f728 mvn r0,#11）─────────────────── */
/* @0x26f728 mvn r0, #11 */
/* @0x26f72c b 0x26f5a0 <pcre_dfa_exec+0x1038> */
/* ── _pcre_is_newline 调用点（5 实参）─────────────────────── */
/* @0x26f730 ldr r9, [r6, #0x78] */
/* @0x26f734 cmp r10, r9 */
/* @0x26f738 bhs 0x26f77c <pcre_dfa_exec+0x1214> */
/* @0x26f73c ldr r1, [r6, #0x18] */
/* @0x26f740 cmp r1, #0 */
/* @0x26f744 beq 0x274ae4 <pcre_dfa_exec+0x657c> */
/* @0x26f748 ldr r5, [sp, #0x28] */
/* @0x26f74c mov r2, r9 */
/* @0x26f750 mov r0, r10 */
/* @0x26f754 add r3, r6, #28 */
/* @0x26f758 str r5, [sp] */
/* @0x26f75c bl 0x25f9fc <_pcre_is_newline> */
/* @0x26f760 cmp r0, #0 */
/* @0x26f764 beq 0x2717dc <pcre_dfa_exec+0x3274> */
/* @0x26f768 ldr r9, [r6, #0x78] */
/* @0x26f76c ldr r3, [r6, #0x1c] */
/* @0x26f770 rsb r3, r3, r9 */
/* @0x26f774 cmp r10, r3 */
/* @0x26f778 bne 0x2717dc <pcre_dfa_exec+0x3274> */
/* @0x26f77c ldr r2, [r6, #0x88] */
/* @0x26f780 cmp r2, #0 */
/* @0x26f784 beq 0x26f6d0 <pcre_dfa_exec+0x1168> */
/* @0x26f788 ldr r3, [r6, #0x84] */
/* @0x26f78c cmp r10, r3 */
/* @0x26f790 bls 0x26f6d0 <pcre_dfa_exec+0x1168> */
/* @0x26f794 cmp r2, #1 */
/* @0x26f798 mov r7, #1 */
/* @0x26f79c str r7, [r6, #0x64] */
/* @0x26f7a0 ble 0x26f6d0 <pcre_dfa_exec+0x1168> */
/* @0x26f7a4 b 0x26f728 <pcre_dfa_exec+0x11c0> */
/* ── （未逐块定性）────────────────────────────────────────── */
/* @0x26f7a8 mov r5, #0 */
/* @0x26f7ac str r5, [sp, #0x4c] */
/* @0x26f7b0 ldr r3, [pc, #0xa50] */
/* @0x26f7b4 mov r12, #0 */
/* @0x26f7b8 str r12, [sp, #0x2c] */
/* @0x26f7bc movw r5, #0xfc1a */
/* @0x26f7c0 ldr r12, [sp, #0x20] */
/* @0x26f7c4 movt r5, #0xffff */
/* @0x26f7c8 ldr r7, [r6, #0x90] */
/* @0x26f7cc mov r8, #2 */
/* @0x26f7d0 ldr r2, [r6, #0x70] */
/* @0x26f7d4 ldr r4, [r12, r3] */
/* @0x26f7d8 mov r3, r5 */
/* @0x26f7dc rsb r2, r2, r11 */
/* @0x26f7e0 str r2, [sp, #0x30] */
/* @0x26f7e4 mov r5, r4 */
/* @0x26f7e8 mov r4, r3 */
/* @0x26f7ec cmp r9, #135 */
/* @0x26f7f0 strhi r8, [r6, #0x98] */
/* @0x26f7f4 ldrb r1, [r11] */
/* @0x26f7f8 mov r0, r10 */
/* @0x26f7fc ldr r12, [sp, #0x164] */
/* @0x26f800 ldr lr, [sp, #0x168] */
/* @0x26f804 ldrb r1, [r5, r1] */
/* @0x26f808 add lr, lr, #1 */
/* @0x26f80c ldr r2, [sp, #0x1c] */
/* @0x26f810 str r6, [sp] */
/* @0x26f814 add r1, r11, r1 */
/* @0x26f818 ldr r3, [sp, #0x18] */
/* @0x26f81c str r12, [sp, #0x4] */
/* @0x26f820 str lr, [sp, #0x8] */
/* @0x26f824 bl 0x26f1e8 <pcre_dfa_exec+0xc80> */
/* @0x26f828 cmp r0, r4 */
/* @0x26f82c beq 0x272a84 <pcre_dfa_exec+0x451c> */
/* @0x26f830 cmn r0, #992 */
/* @0x26f834 beq 0x272abc <pcre_dfa_exec+0x4554> */
/* @0x26f838 cmp r0, #0 */
/* @0x26f83c bne 0x26f5a0 <pcre_dfa_exec+0x1038> */
/* @0x26f840 ldrb r2, [r11, #0x1] */
/* @0x26f844 ldrb r3, [r11, #0x2] */
/* @0x26f848 orr r3, r3, r2, lsl #8 */
/* @0x26f84c add r11, r11, r3 */
/* @0x26f850 ldrb r3, [r11] */
/* @0x26f854 cmp r3, #119 */
/* @0x26f858 bne 0x274380 <pcre_dfa_exec+0x5e18> */
/* @0x26f85c str r7, [r6, #0x90] */
/* @0x26f860 b 0x26f7ec <pcre_dfa_exec+0x1284> */
/* @0x26f864 mov r3, #1 */
/* @0x26f868 str r3, [sp, #0x30] */
/* @0x26f86c ldrb r2, [r11, #0x1] */
/* @0x26f870 cmp r5, #40 */
/* @0x26f874 cmpne r5, #53 */
/* @0x26f878 ldrb r3, [r11, #0x2] */
/* @0x26f87c add r4, r11, #3 */
/* @0x26f880 movne r7, #0 */
/* @0x26f884 moveq r7, #1 */
/* @0x26f888 str r7, [sp, #0x4c] */
/* @0x26f88c mov r7, #0 */
/* @0x26f890 orr r3, r3, r2, lsl #8 */
/* @0x26f894 str r3, [sp, #0x2c] */
/* @0x26f898 ldr r12, [sp, #0x24] */
/* @0x26f89c cmp r12, #0 */
/* @0x26f8a0 ldrb r12, [r4] */
/* @0x26f8a4 beq 0x272af8 <pcre_dfa_exec+0x4590> */
/* @0x26f8a8 cmp r12, #191 */
/* @0x26f8ac bls 0x272af8 <pcre_dfa_exec+0x4590> */
/* @0x26f8b0 tst r12, #32 */
/* @0x26f8b4 moveq r8, #2 */
/* @0x26f8b8 beq 0x26f8e0 <pcre_dfa_exec+0x1378> */
/* @0x26f8bc tst r12, #16 */
/* @0x26f8c0 moveq r8, #3 */
/* @0x26f8c4 beq 0x26f8e0 <pcre_dfa_exec+0x1378> */
/* @0x26f8c8 tst r12, #8 */
/* @0x26f8cc moveq r8, #4 */
/* @0x26f8d0 beq 0x26f8e0 <pcre_dfa_exec+0x1378> */
/* @0x26f8d4 tst r12, #4 */
/* @0x26f8d8 moveq r8, #5 */
/* @0x26f8dc movne r8, #6 */
/* @0x26f8e0 cmp r7, #0 */
/* @0x26f8e4 beq 0x273e2c <pcre_dfa_exec+0x58c4> */
/* ── memcmp 调用点：模式内字面量串比对 ────────────────────── */
/* @0x26f8e8 ldr r9, [r6, #0x78] */
/* @0x26f8ec rsb r5, r8, r9 */
/* @0x26f8f0 cmp r10, r5 */
/* @0x26f8f4 bhi 0x26f930 <pcre_dfa_exec+0x13c8> */
/* @0x26f8f8 mov r11, #1 */
/* @0x26f8fc b 0x26f914 <pcre_dfa_exec+0x13ac> */
/* @0x26f900 cmp r7, r11 */
/* @0x26f904 add r10, r10, r8 */
/* @0x26f908 blt 0x273e2c <pcre_dfa_exec+0x58c4> */
/* @0x26f90c cmp r10, r5 */
/* @0x26f910 bhi 0x26f930 <pcre_dfa_exec+0x13c8> */
/* @0x26f914 mov r0, r10 */
/* @0x26f918 mov r1, r4 */
/* @0x26f91c mov r2, r8 */
/* @0x26f920 add r11, r11, #1 */
/* @0x26f924 bl 0xb6c40 <memcmp@plt> */
/* @0x26f928 cmp r0, #0 */
/* @0x26f92c beq 0x26f900 <pcre_dfa_exec+0x1398> */
/* @0x26f930 ldr r3, [r6, #0x88] */
/* @0x26f934 cmp r3, #0 */
/* @0x26f938 beq 0x270008 <pcre_dfa_exec+0x1aa0> */
/* @0x26f93c cmp r10, r9 */
/* @0x26f940 blo 0x270008 <pcre_dfa_exec+0x1aa0> */
/* @0x26f944 ldr r2, [r6, #0x84] */
/* @0x26f948 cmp r2, r10 */
/* @0x26f94c blo 0x271820 <pcre_dfa_exec+0x32b8> */
/* @0x26f950 b 0x270008 <pcre_dfa_exec+0x1aa0> */
/* ── （未逐块定性）────────────────────────────────────────── */
/* @0x26f954 mov r5, #0 */
/* @0x26f958 str r5, [sp, #0x4c] */
/* @0x26f95c ldrb r5, [r11, #0x3] */
/* @0x26f960 ldrb r2, [r11, #0x4] */
/* @0x26f964 ldr r3, [r6, #0x14] */
/* @0x26f968 orr r5, r2, r5, lsl #8 */
/* @0x26f96c cmp r3, r5, lsl #1 */
/* @0x26f970 ble 0x26f7b0 <pcre_dfa_exec+0x1248> */
/* @0x26f974 ldr r2, [r6, #0x10] */
/* @0x26f978 lsl r1, r5, #3 */
/* @0x26f97c ldr r3, [r6, #0xc] */
/* @0x26f980 add r1, r1, #4 */
/* @0x26f984 rsb r2, r5, r2 */
/* @0x26f988 str r1, [sp, #0x58] */
/* @0x26f98c ldr r1, [pc, #0x874] */
/* @0x26f990 movw r7, #0xfc1a */
/* @0x26f994 ldr r12, [r3, r2, lsl #2] */
/* @0x26f998 movt r7, #0xffff */
/* @0x26f99c ldr r0, [r6, #0x70] */
/* @0x26f9a0 ldr r8, [r6, #0x90] */
/* @0x26f9a4 str r12, [sp, #0x64] */
/* @0x26f9a8 rsb r0, r0, r11 */
/* @0x26f9ac ldr r12, [sp, #0x58] */
/* @0x26f9b0 str r0, [sp, #0x54] */
/* @0x26f9b4 ldr r12, [r3, r12] */
/* @0x26f9b8 str r12, [sp, #0x60] */
/* @0x26f9bc ldr r12, [r3, r5, lsl #3] */
/* @0x26f9c0 str r12, [sp, #0x5c] */
/* @0x26f9c4 mov r12, #0 */
/* @0x26f9c8 str r12, [sp, #0x50] */
/* @0x26f9cc ldr r12, [sp, #0x20] */
/* @0x26f9d0 ldr r4, [r12, r1] */
/* @0x26f9d4 str r8, [sp, #0x2c] */
/* @0x26f9d8 mov r8, r7 */
/* @0x26f9dc str r5, [sp, #0x30] */
/* @0x26f9e0 mov r7, r4 */
/* @0x26f9e4 ldr r5, [sp, #0x18] */
/* @0x26f9e8 ldr r4, [sp, #0x1c] */
/* @0x26f9ec b 0x26fa30 <pcre_dfa_exec+0x14c8> */
/* ── -992 识别（第二处 cmn r0,#992）──────────────────────── */
/* @0x26f9f0 cmn r0, #992 */
/* @0x26f9f4 beq 0x2732cc <pcre_dfa_exec+0x4d64> */
/* @0x26f9f8 cmp r0, #0 */
/* @0x26f9fc bne 0x26f5a0 <pcre_dfa_exec+0x1038> */
/* @0x26fa00 ldr r12, [sp, #0x2c] */
/* @0x26fa04 str r12, [r6, #0x90] */
/* @0x26fa08 ldrb r2, [r11, #0x1] */
/* @0x26fa0c ldrb r3, [r11, #0x2] */
/* @0x26fa10 orr r3, r3, r2, lsl #8 */
/* @0x26fa14 ldrb r3, [r11, r3]! */
/* @0x26fa18 cmp r3, #119 */
/* @0x26fa1c bne 0x275858 <pcre_dfa_exec+0x72f0> */
/* @0x26fa20 ldr r2, [r6, #0x10] */
/* @0x26fa24 ldr r12, [sp, #0x30] */
/* @0x26fa28 ldr r3, [r6, #0xc] */
/* @0x26fa2c rsb r2, r12, r2 */
/* @0x26fa30 ldr r1, [r6, #0x74] */
/* @0x26fa34 cmp r9, #135 */
/* @0x26fa38 ldr r12, [sp, #0x164] */
/* @0x26fa3c mov r0, r10 */
/* @0x26fa40 movhi lr, #2 */
/* @0x26fa44 rsb r1, r1, r10 */
/* @0x26fa48 str r1, [r3, r2, lsl #2] */
/* @0x26fa4c mov r2, r4 */
/* @0x26fa50 strhi lr, [r6, #0x98] */
/* @0x26fa54 mov r3, r5 */
/* @0x26fa58 ldrb r1, [r11] */
/* @0x26fa5c ldr lr, [sp, #0x168] */
/* @0x26fa60 str r6, [sp] */
/* @0x26fa64 ldrb r1, [r7, r1] */
/* @0x26fa68 add lr, lr, #1 */
/* @0x26fa6c str r12, [sp, #0x4] */
/* @0x26fa70 add r1, r11, r1 */
/* @0x26fa74 str lr, [sp, #0x8] */
/* @0x26fa78 bl 0x26f1e8 <pcre_dfa_exec+0xc80> */
/* @0x26fa7c cmp r0, r8 */
/* @0x26fa80 bne 0x26f9f0 <pcre_dfa_exec+0x1488> */
/* @0x26fa84 ldr r12, [sp, #0x54] */
/* @0x26fa88 ldr r11, [r6, #0x70] */
/* @0x26fa8c ldr r3, [r6, #0x80] */
/* @0x26fa90 add r11, r11, r12 */
/* @0x26fa94 ldr r12, [r6, #0x90] */
/* @0x26fa98 cmp r3, r10 */
/* @0x26fa9c ldr r5, [r6, #0x8c] */
/* @0x26faa0 ldr r4, [r6, #0x7c] */
/* @0x26faa4 str r12, [sp, #0x2c] */
/* @0x26faa8 beq 0x274c84 <pcre_dfa_exec+0x671c> */
/* @0x26faac mov r12, #1 */
/* @0x26fab0 mov r10, r3 */
/* @0x26fab4 str r12, [sp, #0x50] */
/* @0x26fab8 b 0x26fa20 <pcre_dfa_exec+0x14b8> */
/* @0x26fabc ldrb r8, [r11, #0x3] */
/* @0x26fac0 ldrb r7, [r11, #0x1] */
/* @0x26fac4 cmp r8, #118 */
/* @0x26fac8 ldrb r3, [r11, #0x2] */
/* @0x26facc addne r4, r11, #3 */
/* @0x26fad0 orr r7, r3, r7, lsl #8 */
/* @0x26fad4 beq 0x2750a8 <pcre_dfa_exec+0x6b40> */
/* @0x26fad8 sub r3, r8, #141 */
/* @0x26fadc cmp r3, #16 */
/* @0x26fae0 addls pc, pc, r3, lsl #2 */
/* @0x26fae4 b 0x271a20 <pcre_dfa_exec+0x34b8> */
/* @0x26fae8 b 0x27229c <pcre_dfa_exec+0x3d34> */
/* @0x26faec b 0x27222c <pcre_dfa_exec+0x3cc4> */
/* @0x26faf0 b 0x2721a0 <pcre_dfa_exec+0x3c38> */
/* @0x26faf4 b 0x272114 <pcre_dfa_exec+0x3bac> */
/* @0x26faf8 b 0x271a68 <pcre_dfa_exec+0x3500> */
/* @0x26fafc b 0x271a20 <pcre_dfa_exec+0x34b8> */
/* @0x26fb00 b 0x271a20 <pcre_dfa_exec+0x34b8> */
/* @0x26fb04 b 0x271a20 <pcre_dfa_exec+0x34b8> */
/* @0x26fb08 b 0x271a20 <pcre_dfa_exec+0x34b8> */
/* @0x26fb0c b 0x271a20 <pcre_dfa_exec+0x34b8> */
/* @0x26fb10 b 0x271a20 <pcre_dfa_exec+0x34b8> */
/* @0x26fb14 b 0x271a20 <pcre_dfa_exec+0x34b8> */
/* @0x26fb18 b 0x271a20 <pcre_dfa_exec+0x34b8> */
/* @0x26fb1c b 0x271a20 <pcre_dfa_exec+0x34b8> */
/* @0x26fb20 b 0x271a20 <pcre_dfa_exec+0x34b8> */
/* @0x26fb24 b 0x271a20 <pcre_dfa_exec+0x34b8> */
/* @0x26fb28 b 0x271a68 <pcre_dfa_exec+0x3500> */
/* ── （未逐块定性）────────────────────────────────────────── */
/* @0x26fb2c ldr r9, [r6, #0x78] */
/* @0x26fb30 cmp r10, r9 */
/* @0x26fb34 bhs 0x272d58 <pcre_dfa_exec+0x47f0> */
/* @0x26fb38 ldr r7, [sp, #0x24] */
/* @0x26fb3c cmp r7, #0 */
/* @0x26fb40 beq 0x274600 <pcre_dfa_exec+0x6098> */
/* @0x26fb44 ldrb r3, [r11, #0x1] */
/* @0x26fb48 cmp r3, #191 */
/* @0x26fb4c movls r1, #1 */
/* @0x26fb50 bls 0x26fb70 <pcre_dfa_exec+0x1608> */
/* @0x26fb54 tst r3, #32 */
/* @0x26fb58 bne 0x275fe0 <pcre_dfa_exec+0x7a78> */
/* @0x26fb5c ldrb r2, [r11, #0x2] */
/* @0x26fb60 and r3, r3, #31 */
/* @0x26fb64 mov r1, #2 */
/* @0x26fb68 and r2, r2, #63 */
/* @0x26fb6c orr r3, r2, r3, lsl #6 */
/* @0x26fb70 cmp r3, #127 */
/* @0x26fb74 bhi 0x275388 <pcre_dfa_exec+0x6e20> */
/* @0x26fb78 ldr r2, [r6, #0x38] */
/* @0x26fb7c ldrb r0, [r10] */
/* @0x26fb80 ldrb r1, [r2, r3] */
/* @0x26fb84 ldrb r3, [r2, r0] */
/* @0x26fb88 cmp r1, r3 */
/* @0x26fb8c bne 0x270008 <pcre_dfa_exec+0x1aa0> */
/* @0x26fb90 ldrb r5, [r11, #0x2] */
/* @0x26fb94 add r10, r10, #1 */
/* @0x26fb98 add r11, r11, #2 */
/* @0x26fb9c b 0x26f2b0 <pcre_dfa_exec+0xd48> */
/* ── （未逐块定性）────────────────────────────────────────── */
/* @0x26fba0 ldr r8, [r6, #0x98] */
/* @0x26fba4 movw r4, #0xfc19 */
/* @0x26fba8 ldr r7, [r6, #0xac] */
/* @0x26fbac mov r5, #0 */
/* @0x26fbb0 cmp r8, #1 */
/* @0x26fbb4 movt r4, #0xffff */
/* @0x26fbb8 moveq r3, #0 */
/* @0x26fbbc movne r8, #0 */
/* @0x26fbc0 streq r3, [r6, #0x98] */
/* @0x26fbc4 b 0x26fbec <pcre_dfa_exec+0x1684> */
/* @0x26fbc8 cmp r0, #0 */
/* @0x26fbcc bne 0x26f5a0 <pcre_dfa_exec+0x1038> */
/* @0x26fbd0 ldrb r2, [r11, #0x1] */
/* @0x26fbd4 ldrb r3, [r11, #0x2] */
/* @0x26fbd8 orr r3, r3, r2, lsl #8 */
/* @0x26fbdc add r11, r11, r3 */
/* @0x26fbe0 ldrb r3, [r11] */
/* @0x26fbe4 cmp r3, #119 */
/* @0x26fbe8 bne 0x274218 <pcre_dfa_exec+0x5cb0> */
/* @0x26fbec ldr r3, [sp, #0x168] */
/* @0x26fbf0 mov r0, r10 */
/* @0x26fbf4 str r6, [sp] */
/* @0x26fbf8 add r1, r11, #3 */
/* @0x26fbfc add r3, r3, #1 */
/* @0x26fc00 str r5, [sp, #0x4] */
/* @0x26fc04 str r3, [sp, #0x8] */
/* @0x26fc08 ldr r2, [sp, #0x1c] */
/* @0x26fc0c ldr r3, [sp, #0x18] */
/* @0x26fc10 bl 0x26f1e8 <pcre_dfa_exec+0xc80> */
/* @0x26fc14 cmp r0, #1 */
/* @0x26fc18 cmpne r0, r4 */
/* @0x26fc1c beq 0x27420c <pcre_dfa_exec+0x5ca4> */
/* @0x26fc20 cmn r0, #992 */
/* @0x26fc24 str r7, [r6, #0xac] */
/* @0x26fc28 bne 0x26fbc8 <pcre_dfa_exec+0x1660> */
/* @0x26fc2c ldrb r1, [r11, #0x1] */
/* @0x26fc30 ldrb r3, [r11, #0x2] */
/* @0x26fc34 ldr r2, [r6, #0x7c] */
/* @0x26fc38 orr r3, r3, r1, lsl #8 */
/* @0x26fc3c add r3, r11, r3 */
/* @0x26fc40 cmp r3, r2 */
/* @0x26fc44 bls 0x26f6a8 <pcre_dfa_exec+0x1140> */
/* @0x26fc48 ldrb r2, [r11] */
/* @0x26fc4c cmp r2, #119 */
/* @0x26fc50 beq 0x274848 <pcre_dfa_exec+0x62e0> */
/* @0x26fc54 ldrb r2, [r3] */
/* @0x26fc58 cmp r2, #119 */
/* @0x26fc5c bne 0x26f6a8 <pcre_dfa_exec+0x1140> */
/* @0x26fc60 mov r11, r3 */
/* @0x26fc64 b 0x26fbec <pcre_dfa_exec+0x1684> */
/* @0x26fc68 add r3, r11, #1 */
/* @0x26fc6c ldrb r1, [r3, #0x1] */
/* @0x26fc70 ldrb r2, [r3, #0x2] */
/* @0x26fc74 orr r2, r2, r1, lsl #8 */
/* @0x26fc78 ldrb r2, [r3, r2]! */
/* @0x26fc7c cmp r2, #119 */
/* @0x26fc80 beq 0x26fc6c <pcre_dfa_exec+0x1704> */
/* @0x26fc84 add r11, r3, #3 */
/* @0x26fc88 ldrb r5, [r3, #0x3] */
/* @0x26fc8c b 0x26f2b0 <pcre_dfa_exec+0xd48> */
/* @0x26fc90 ldrb r2, [r11, #0x1] */
/* @0x26fc94 ldrb r3, [r11, #0x2] */
/* @0x26fc98 orr r3, r3, r2, lsl #8 */
/* @0x26fc9c rsb r3, r3, #0 */
/* @0x26fca0 add r8, r11, r3 */
/* @0x26fca4 ldrb r3, [r11, r3] */
/* @0x26fca8 cmp r3, #135 */
/* @0x26fcac movls r2, #0 */
/* @0x26fcb0 movhi r2, #1 */
/* @0x26fcb4 cmp r3, #129 */
/* @0x26fcb8 orreq r2, r2, #1 */
/* @0x26fcbc cmp r2, #0 */
/* @0x26fcc0 ldrne r7, [sp, #0x164] */
/* @0x26fcc4 moveq r4, r2 */
/* @0x26fcc8 sub r2, r3, #125 */
/* @0x26fccc ldrne r12, [r7] */
/* @0x26fcd0 ldrne r4, [r7, #0x4] */
/* @0x26fcd4 strne r12, [sp, #0x164] */
/* @0x26fcd8 cmp r3, #130 */
/* @0x26fcdc cmpne r2, #3 */
/* @0x26fce0 bls 0x2780a8 <pcre_dfa_exec+0x9b40> */
/* @0x26fce4 add r2, r3, #123 */
/* @0x26fce8 add r3, r3, #118 */
/* @0x26fcec uxtb r2, r2 */
/* @0x26fcf0 uxtb r3, r3 */
/* @0x26fcf4 cmp r3, #1 */
/* @0x26fcf8 cmphi r2, #1 */
/* @0x26fcfc bhi 0x26fd4c <pcre_dfa_exec+0x17e4> */
/* @0x26fd00 ldrb r1, [r8, #0x3] */
/* @0x26fd04 ldrb r2, [r8, #0x4] */
/* @0x26fd08 ldr r3, [r6, #0xa4] */
/* @0x26fd0c orr r2, r2, r1, lsl #8 */
/* @0x26fd10 cmp r3, #0 */
/* @0x26fd14 lsl r1, r2, #1 */
/* @0x26fd18 beq 0x26fd28 <pcre_dfa_exec+0x17c0> */
/* @0x26fd1c ldr r3, [r3, #0x4] */
/* @0x26fd20 cmp r3, r2 */
/* @0x26fd24 beq 0x2780c4 <pcre_dfa_exec+0x9b5c> */
/* ── （未逐块定性）────────────────────────────────────────── */
/* @0x26fd28 ldr r0, [r6, #0x14] */
/* @0x26fd2c ldrh r3, [r6, #146] */
/* @0x26fd30 cmp r1, r0 */
/* @0x26fd34 orr r3, r2, r3, lsl #16 */
/* @0x26fd38 str r3, [r6, #0x90] */
/* @0x26fd3c blt 0x274cd8 <pcre_dfa_exec+0x6770> */
/* @0x26fd40 orr r3, r3, #65536 */
/* @0x26fd44 str r3, [r6, #0x90] */
/* @0x26fd48 ldrb r5, [r11] */
/* @0x26fd4c cmp r5, #123 */
/* @0x26fd50 beq 0x27802c <pcre_dfa_exec+0x9ac4> */
/* @0x26fd54 cmp r5, #120 */
/* @0x26fd58 beq 0x26fd64 <pcre_dfa_exec+0x17fc> */
/* @0x26fd5c cmp r10, r4 */
/* @0x26fd60 bne 0x27804c <pcre_dfa_exec+0x9ae4> */
/* @0x26fd64 ldrb r3, [r8] */
/* @0x26fd68 cmp r3, #129 */
/* @0x26fd6c beq 0x27849c <pcre_dfa_exec+0x9f34> */
/* @0x26fd70 ldrb r5, [r11, #0x3] */
/* @0x26fd74 add r11, r11, #3 */
/* @0x26fd78 b 0x26f2b0 <pcre_dfa_exec+0xd48> */
/* ── （未逐块定性）────────────────────────────────────────── */
/* @0x26fd7c ldr r4, [r6, #0xac] */
/* @0x26fd80 mov r5, r11 */
/* @0x26fd84 ldr r7, [sp, #0x1c] */
/* @0x26fd88 ldr r8, [sp, #0x18] */
/* @0x26fd8c ldr r9, [sp, #0x164] */
/* @0x26fd90 b 0x26fdbc <pcre_dfa_exec+0x1854> */
/* @0x26fd94 cmp r0, #0 */
/* @0x26fd98 bne 0x26f5a0 <pcre_dfa_exec+0x1038> */
/* @0x26fd9c ldrb r2, [r5, #0x1] */
/* @0x26fda0 ldrb r3, [r5, #0x2] */
/* @0x26fda4 orr r3, r3, r2, lsl #8 */
/* @0x26fda8 add r5, r5, r3 */
/* @0x26fdac str r4, [r6, #0xac] */
/* @0x26fdb0 ldrb r3, [r5] */
/* @0x26fdb4 cmp r3, #119 */
/* @0x26fdb8 bne 0x274264 <pcre_dfa_exec+0x5cfc> */
/* @0x26fdbc ldr r3, [sp, #0x168] */
/* @0x26fdc0 mov r0, r10 */
/* @0x26fdc4 str r6, [sp] */
/* @0x26fdc8 add r1, r5, #3 */
/* @0x26fdcc add r3, r3, #1 */
/* @0x26fdd0 str r9, [sp, #0x4] */
/* @0x26fdd4 str r3, [sp, #0x8] */
/* @0x26fdd8 mov r2, r7 */
/* @0x26fddc mov r3, r8 */
/* @0x26fde0 bl 0x26f1e8 <pcre_dfa_exec+0xc80> */
/* @0x26fde4 cmp r0, #1 */
/* @0x26fde8 beq 0x274258 <pcre_dfa_exec+0x5cf0> */
/* @0x26fdec cmn r0, #992 */
/* @0x26fdf0 bne 0x26fd94 <pcre_dfa_exec+0x182c> */
/* @0x26fdf4 ldrb r1, [r5, #0x1] */
/* @0x26fdf8 ldrb r3, [r5, #0x2] */
/* @0x26fdfc ldr r2, [r6, #0x7c] */
/* @0x26fe00 orr r3, r3, r1, lsl #8 */
/* @0x26fe04 add r3, r5, r3 */
/* @0x26fe08 cmp r3, r2 */
/* @0x26fe0c bls 0x26f6a8 <pcre_dfa_exec+0x1140> */
/* @0x26fe10 ldrb r2, [r5] */
/* @0x26fe14 cmp r2, #119 */
/* @0x26fe18 beq 0x26fe28 <pcre_dfa_exec+0x18c0> */
/* @0x26fe1c ldrb r2, [r3] */
/* @0x26fe20 cmp r2, #119 */
/* @0x26fe24 bne 0x26f6a8 <pcre_dfa_exec+0x1140> */
/* @0x26fe28 mov r5, r3 */
/* @0x26fe2c b 0x26fdac <pcre_dfa_exec+0x1844> */
/* ── 成功分支：写 [+0x7C] = ecode 后返回 -992 ──────────────── */
/* @0x26fe30 ldr r12, [sp, #0x20] */
/* @0x26fe34 mov r4, r11 */
/* @0x26fe38 ldr r3, [pc, #0x3c8] */
/* @0x26fe3c mov r2, #0 */
/* @0x26fe40 add r5, r4, #2 */
/* @0x26fe44 str r2, [r6, #0xac] */
/* @0x26fe48 str r5, [r6, #0xb0] */
/* @0x26fe4c mov r0, r10 */
/* @0x26fe50 ldr r7, [r12, r3] */
/* @0x26fe54 ldrb lr, [r4] */
/* @0x26fe58 ldrb r1, [r4, #0x1] */
/* @0x26fe5c ldr r11, [sp, #0x18] */
/* @0x26fe60 ldrb lr, [r7, lr] */
/* @0x26fe64 ldr r7, [sp, #0x164] */
/* @0x26fe68 ldr r12, [sp, #0x168] */
/* @0x26fe6c add r1, lr, r1 */
/* @0x26fe70 mov r3, r11 */
/* @0x26fe74 ldr r2, [sp, #0x1c] */
/* @0x26fe78 add r12, r12, #1 */
/* @0x26fe7c str r6, [sp] */
/* @0x26fe80 str r7, [sp, #0x4] */
/* @0x26fe84 add r1, r4, r1 */
/* @0x26fe88 str r12, [sp, #0x8] */
/* @0x26fe8c bl 0x26f1e8 <pcre_dfa_exec+0xc80> */
/* @0x26fe90 movw r3, #0xfc19 */
/* @0x26fe94 movt r3, #0xffff */
/* @0x26fe98 cmp r0, #1 */
/* @0x26fe9c cmpne r0, r3 */
/* @0x26fea0 bne 0x26feb0 <pcre_dfa_exec+0x1948> */
/* @0x26fea4 ldr r3, [r6, #0xac] */
/* @0x26fea8 cmp r3, #0 */
/* @0x26feac streq r5, [r6, #0xac] */
/* @0x26feb0 cmp r0, #0 */
/* @0x26feb4 streq r4, [r6, #0x7c] */
/* @0x26feb8 movweq r0, #0xfc20 */
/* @0x26febc movteq r0, #0xffff */
/* @0x26fec0 b 0x26f5a0 <pcre_dfa_exec+0x1038> */
/* @0x26fec4 mov r4, r11 */
/* @0x26fec8 ldr r7, [sp, #0x164] */
/* @0x26fecc ldr r11, [sp, #0x18] */
/* @0x26fed0 mov r0, r10 */
/* @0x26fed4 ldr r12, [sp, #0x168] */
/* @0x26fed8 add r1, r4, #1 */
/* @0x26fedc str r6, [sp] */
/* @0x26fee0 add r12, r12, #1 */
/* @0x26fee4 ldr r2, [sp, #0x1c] */
/* @0x26fee8 str r7, [sp, #0x4] */
/* @0x26feec mov r3, r11 */
/* @0x26fef0 str r12, [sp, #0x8] */
/* @0x26fef4 bl 0x26f1e8 <pcre_dfa_exec+0xc80> */
/* @0x26fef8 cmp r0, #0 */
/* @0x26fefc streq r4, [r6, #0x7c] */
/* @0x26ff00 movweq r0, #0xfc20 */
/* @0x26ff04 movteq r0, #0xffff */
/* @0x26ff08 b 0x26f5a0 <pcre_dfa_exec+0x1038> */
/* ── 第二组 计数/上限（+0x28 / +0x2C）─────────────────────── */
/* @0x26ff0c ldr r3, [r6, #0x28] */
/* @0x26ff10 ldr r2, [r6, #0x2c] */
/* @0x26ff14 add r3, r3, #1 */
/* @0x26ff18 str r3, [r6, #0x28] */
/* @0x26ff1c cmp r3, r2 */
/* @0x26ff20 bhi 0x278438 <pcre_dfa_exec+0x9ed0> */
/* @0x26ff24 ldr r1, [pc, #0x2dc] */
/* @0x26ff28 ldr r7, [sp, #0x20] */
/* @0x26ff2c ldrb r2, [r11] */
/* @0x26ff30 ldrb r3, [r11, #0x1] */
/* @0x26ff34 ldr r4, [r7, r1] */
/* @0x26ff38 ldrb r2, [r4, r2] */
/* @0x26ff3c add r3, r2, r3 */
/* @0x26ff40 ldrb r5, [r11, r3]! */
/* @0x26ff44 b 0x26f2b0 <pcre_dfa_exec+0xd48> */
/* @0x26ff48 mov r4, r11 */
/* @0x26ff4c ldr r5, [sp, #0x164] */
/* @0x26ff50 ldr r11, [sp, #0x18] */
/* @0x26ff54 add r1, r4, #1 */
/* @0x26ff58 ldr r12, [sp, #0x168] */
/* @0x26ff5c mov r0, r10 */
/* @0x26ff60 str r6, [sp] */
/* @0x26ff64 add r12, r12, #1 */
/* @0x26ff68 ldr r2, [sp, #0x1c] */
/* @0x26ff6c str r5, [sp, #0x4] */
/* @0x26ff70 mov r3, r11 */
/* @0x26ff74 str r12, [sp, #0x8] */
/* @0x26ff78 bl 0x26f1e8 <pcre_dfa_exec+0xc80> */
/* @0x26ff7c cmp r0, #0 */
/* @0x26ff80 streq r10, [r6, #0x7c] */
/* @0x26ff84 movweq r0, #0xfc1e */
/* @0x26ff88 movteq r0, #0xffff */
/* @0x26ff8c b 0x26f5a0 <pcre_dfa_exec+0x1038> */
/* ── 窗口尾：0x26ffac 之后是本函数的第二段（37860 B）────────── */
/* @0x26ff90 ldr r5, [sp, #0x24] */
/* @0x26ff94 ldrb r1, [r11, #0x1] */
/* @0x26ff98 cmp r5, #0 */
/* @0x26ff9c beq 0x2740bc <pcre_dfa_exec+0x5b54> */
/* @0x26ffa0 ldrb r3, [r11, #0x2] */
/* @0x26ffa4 orr r1, r3, r1, lsl #8 */
/* @0x26ffa8 cmp r1, #0 */
