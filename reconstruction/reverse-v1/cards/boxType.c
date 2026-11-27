/* cally 逆向卡：boxType（原版 libyoyo.so，armv7）
 * @func 0xd7784 0xd7908  size 388  97 条指令
 * 级别: 正文（97/97 逐条锚定；10 路分派表、8 个类型体（k=7/8/越界共用 1 个 default）的读写宽度、
 *       消费字节数与 tag 常量全部解码）
 * 符号: _Z7boxTypeR6RValue8eVM_TypePh → uchar* boxType(RValue& dst, eVM_Type type, uchar* src)
 *
 * ── 一句话 ───────────────────────────────────────────────────────
 *   把「已解码的操作数 + 4 位类型码」装箱成 16 字节 RValue。第 3 参 src 是**操作数指针**，
 *   函数按类型宽度读它并把指针前移，再返回**前移后的指针** ⇒ 返回值 = 数据指针 + 消费字节数。
 *   dst（首参 r0→r6）全程只写不读；没有 NULL 检查、没有 canary、没有引用计数、没有错误抛点。
 *
 * ── 分派形状（2 条指令 + 1 条 default + 10 项表）─────────────────────
 *   cmp r1,#9 / addls pc,pc,r1,lsl #2（0xd7790 / 0xd7794）
 *   表基 = 0xd779c = addls 的地址 + 8（ARM 读 PC 的硬规则），10 项，k → 0xd779c + 4k。
 *   0xd7798 是**表外 default**：r1 > 9 时 addls 不执行、直接落这条 b 0xd77e0。
 *   与 DoPushLocal 的 15 路表同构（default 紧贴 addls，表体从 addls+8 起）。
 *
 * ── 类型码 → 体 → 消费字节（宽度由每条叶子自己的读写指令证明，不是猜的）─────
 *   k   体入口     读宽   写 dst              tag            消费
 *   0   0xd780c     8 B    [0]/[4]            0  real        8   ldrd 原样搬，不转换
 *   1   0xd7830     4 B    [0]/[4]            0  real        4   vldmia s15 + vcvt.f64.f32
 *   2   0xd785c     4 B    [0]/[4]            0  real        4   vcvt.f64.s32（有符号）
 *   3   0xd77c4     8 B    [0]/[4]            0  real        8   bl __floatdidf（int64→double）
 *   4   0xd788c     4 B    [0]/[4]           13  bool        4   vcvt.f64.s32，**不做 0/1 归一化**
 *   5   0xd78bc    16 B    [0]/[4]/[8]/[0xc]  原样         16   整个 RValue 逐字拷贝，不 ++ 计数
 *   6   0xd78ec     4 B    [0] 指针            1  string      4   只写 [0] 与 tag；[4]/[8] 不动；不 ++
 *   7   0xd77e0     -      -                   -             0   no-op（dst 一位都不动）
 *   8   0xd77e0     -      -                   -             0   no-op
 *   9   0xd77ec     0      [0]=[4]=0           5  undefined   0
 *   >9  0xd77e0     -      -                   -             0   no-op
 *   ⇒ 只有 k=5 会写 dst+8；k=9 只清 [0]/[4]，[8] 保留调用方旧值。
 *   ⇒ 未知类型不是错误：静默 no-op，返回值仍是原 src（消费 0）。这与 DoConv「不支持的组合一律
 *     VMError」是相反的两种风格 —— boxType 的「错」交给调用方按 tag 判，它自己从不抛。
 *
 * ── 与 DoConv 类型码对账（顺带纠正 DoConv 卡 open 2）──────────────────
 *   DoConv 的 flags 路把 src 半字节 arg&15 直接当 eVM_Type 传（0xeb6b0 / 0xeb708），
 *   dst 半字节 arg>>4 也照样传（0xe2078 同理）。两边 0..6 逐项对上：
 *     0 = 8 字节 double、1 = float32、2 = int32、3 = int64、4 = bool(4 字节)、
 *     5 = 16 字节动态 RValue、6 = 字符串指针
 *   ⇒ DoConv 卡 open 2 记的「0=float32 1=int32 2=int64 3=bool 4=16B RValue 5=string 8=undefined」
 *     整体错位一格；而且 8 不是 undefined —— **9 才是 undefined(tag 5)，7/8 是空档**。
 *   ⇒ 「flags 路传 arg&15 存在 off-by-one」的疑点不成立：半字节就是 eVM_Type，无偏移。
 *   独立旁证：本卡写入的 tag 常量（k=0/1/2/3 的 0、k=4 的 13、k=6 的 1、k=9 的 5）
 *   与 DoConv 三个 dst=5 叶子写出的 real=0 / string=1 / bool=13 逐字相同。
 *
 * ── 调用侧形状（38 个 bl，19 对左右操作数）───────────────────────
 *   抽查的每个调用点都是先 `and r1,r1,#15`（左右各一个半字节）或 `lsr r1,rX,#4` 再 bl；
 *   全库扫「bl 前三指令里 mov r1,#imm」为 0 命中 ⇒ 类型码只能来自字节码操作数，
 *   eVM_Type 的**编号**只能由本体反推（枚举名本身没有符号可读）。
 *   r0 = dst、r1 = type、r2 = src；sp 只减 8，仅 k=3 用它暂存 src（bl __floatdidf 会打掉 r2）。
 *
 * open:
 *   1. k=5/k=6 都不增引用计数，谁负责 retain 未取证（DoConv/DoSet 侧没查）。
 *   2. k=7/k=8 是「预留」还是「曾经有语义」无法从本函数区分：两者都是 no-op 且不写 dst。
 *   3. k=6 只写 [0]+tag，若 dst 之前装着 string，[8] 会留着旧值；是否有害未证。
 *   4. eVM_Type 的 C 枚举字面（VM_REAL/VM_INT32…）无符号可读，本卡的编号是行为反推。
 */
/* ── 入口：dst=r6、type=r1、src=r2；无 canary，帧只 8 字节（仅 k=3 借来暂存 src） */
/* @0xd7784 push {r4, r5, r6, lr} */
/* dst 固定进 r6：全函数只通过 r6 写目的 RValue */
/* @0xd7788 mov r6, r0 */
/* @0xd778c sub sp, sp, #8 */
/* 类型码上界 9；r1 > 9 时 addls 不执行 → 落 0xd7798 default */
/* @0xd7790 cmp r1, #9 */
/* 跳表基址 = 本条 + 8 = 0xd779c；k=0..9 → 0xd779c + 4k（ARM 读 PC 的硬规则） */
/* @0xd7794 addls pc, pc, r1, lsl #2 */
/* default（越界）：不写 dst，只把 src 原样返回 */
/* @0xd7798 b 0xd77e0 <_Z7boxTypeR6RValue8eVM_TypePh+0x5c> */
/* 表[0] → real 8 字节原样 */
/* @0xd779c b 0xd780c <_Z7boxTypeR6RValue8eVM_TypePh+0x88> */
/* 表[1] → float32 */
/* @0xd77a0 b 0xd7830 <_Z7boxTypeR6RValue8eVM_TypePh+0xac> */
/* 表[2] → int32 */
/* @0xd77a4 b 0xd785c <_Z7boxTypeR6RValue8eVM_TypePh+0xd8> */
/* 表[3] → int64（体在 0xd77c4，紧贴表尾） */
/* @0xd77a8 b 0xd77c4 <_Z7boxTypeR6RValue8eVM_TypePh+0x40> */
/* 表[4] → bool */
/* @0xd77ac b 0xd788c <_Z7boxTypeR6RValue8eVM_TypePh+0x108> */
/* 表[5] → 16 字节 RValue */
/* @0xd77b0 b 0xd78bc <_Z7boxTypeR6RValue8eVM_TypePh+0x138> */
/* 表[6] → 字符串指针 */
/* @0xd77b4 b 0xd78ec <_Z7boxTypeR6RValue8eVM_TypePh+0x168> */
/* 表[7] → no-op */
/* @0xd77b8 b 0xd77e0 <_Z7boxTypeR6RValue8eVM_TypePh+0x5c> */
/* 表[8] → no-op */
/* @0xd77bc b 0xd77e0 <_Z7boxTypeR6RValue8eVM_TypePh+0x5c> */
/* 表[9] → undefined */
/* @0xd77c0 b 0xd77ec <_Z7boxTypeR6RValue8eVM_TypePh+0x68> */
/* ── k=3 int64：ldrd 带写回，一次读走 8 字节并前移 src */
/* @0xd77c4 ldrd r0, r1, [r2], #8 */
/* @0xd77c8 mov r3, #0 */
/* @0xd77cc str r3, [r6, #0xc] */
/* bl 会打掉 r2，先暂存前移后的 src */
/* @0xd77d0 str r2, [sp, #0x4] */
/* __floatdidf：int64→double（有符号 64 位整型路径，不是 vcvt） */
/* @0xd77d4 bl 0x319164 <__floatdidf> */
/* @0xd77d8 stm r6, {r0, r1} */
/* 取回前移后的 src，落共同出口 */
/* @0xd77dc ldr r2, [sp, #0x4] */
/* ── 共同出口：r0 = src（= 数据指针 + 消费字节数） */
/* @0xd77e0 mov r0, r2 */
/* @0xd77e4 add sp, sp, #8 */
/* @0xd77e8 pop {r4, r5, r6, pc} */
/* ── k=9 undefined：只清 [0]/[4]，tag 写 5，[8] 不动，消费 0 */
/* @0xd77ec mov r3, #0 */
/* @0xd77f0 mov r1, #5 */
/* @0xd77f4 str r3, [r0] */
/* @0xd77f8 str r1, [r0, #0xc] */
/* @0xd77fc str r3, [r0, #0x4] */
/* @0xd7800 mov r0, r2 */
/* @0xd7804 add sp, sp, #8 */
/* @0xd7808 pop {r4, r5, r6, pc} */
/* ── k=0 real：8 字节原样搬（不转换），tag 0 */
/* @0xd780c ldr r1, [r2] */
/* @0xd7810 add r2, r2, #8 */
/* @0xd7814 ldr r3, [r2, #-0x4] */
/* @0xd7818 mov r0, #0 */
/* @0xd781c str r0, [r6, #0xc] */
/* @0xd7820 mov r0, r2 */
/* @0xd7824 stm r6, {r1, r3} */
/* @0xd7828 add sp, sp, #8 */
/* @0xd782c pop {r4, r5, r6, pc} */
/* ── k=1 float32：vldmia 4 字节带写回 → vcvt.f64.f32 → 8 字节，tag 0 */
/* @0xd7830 vldmia r2!, {s15} */
/* @0xd7834 vcvt.f64.f32 d6, s15 */
/* @0xd7838 mov r3, #0 */
/* @0xd783c str r3, [r0, #0xc] */
/* @0xd7840 vmov r4, r5, d6 */
/* @0xd7844 vmov r1, s12 */
/* @0xd7848 mov r3, r5 */
/* @0xd784c stm r0, {r1, r3} */
/* @0xd7850 mov r0, r2 */
/* @0xd7854 add sp, sp, #8 */
/* @0xd7858 pop {r4, r5, r6, pc} */
/* ── k=2 int32：vcvt.f64.s32（有符号），tag 0 */
/* @0xd785c mov r3, #0 */
/* @0xd7860 str r3, [r0, #0xc] */
/* @0xd7864 ldr r4, [r2], #4 */
/* @0xd7868 vmov s13, r4 */
/* @0xd786c vcvt.f64.s32 d6, s13 */
/* @0xd7870 vmov r4, r5, d6 */
/* @0xd7874 vmov r1, s12 */
/* @0xd7878 mov r3, r5 */
/* @0xd787c stm r0, {r1, r3} */
/* @0xd7880 mov r0, r2 */
/* @0xd7884 add sp, sp, #8 */
/* @0xd7888 pop {r4, r5, r6, pc} */
/* ── k=4 bool：tag 13 先写，再 vcvt.f64.s32；无 0/1 归一化（调用方自己保证 0/1） */
/* @0xd788c mov r3, #13 */
/* @0xd7890 str r3, [r0, #0xc] */
/* @0xd7894 ldr r4, [r2], #4 */
/* @0xd7898 vmov s15, r4 */
/* @0xd789c vcvt.f64.s32 d7, s15 */
/* @0xd78a0 vmov r4, r5, d7 */
/* @0xd78a4 vmov r1, s14 */
/* @0xd78a8 mov r3, r5 */
/* @0xd78ac stm r0, {r1, r3} */
/* @0xd78b0 mov r0, r2 */
/* @0xd78b4 add sp, sp, #8 */
/* @0xd78b8 pop {r4, r5, r6, pc} */
/* ── k=5 动态 RValue：16 字节逐字拷贝（含 tag 原字），消费 16 */
/* @0xd78bc ldr r12, [r2] */
/* 一次前移 16，随后用负偏移取回四个字 */
/* @0xd78c0 add r2, r2, #16 */
/* @0xd78c4 ldr r0, [r2, #-0xc] */
/* @0xd78c8 ldr r1, [r2, #-0x8] */
/* @0xd78cc ldr r3, [r2, #-0x4] */
/* @0xd78d0 str r0, [r6, #0x4] */
/* @0xd78d4 mov r0, r2 */
/* @0xd78d8 str r12, [r6] */
/* @0xd78dc str r1, [r6, #0x8] */
/* tag 原样写出（保留高 8 位，不清） */
/* @0xd78e0 str r3, [r6, #0xc] */
/* @0xd78e4 add sp, sp, #8 */
/* @0xd78e8 pop {r4, r5, r6, pc} */
/* ── k=6 字符串：读 4 字节指针，tag 1，只写 [0]；[4]/[8] 与引用计数都不碰 */
/* @0xd78ec ldr r3, [r2], #4 */
/* @0xd78f0 mov r1, #1 */
/* @0xd78f4 str r1, [r0, #0xc] */
/* @0xd78f8 str r3, [r0] */
/* @0xd78fc mov r0, r2 */
/* @0xd7900 add sp, sp, #8 */
/* @0xd7904 pop {r4, r5, r6, pc} */
