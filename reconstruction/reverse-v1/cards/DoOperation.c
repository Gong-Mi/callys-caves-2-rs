/* cally 逆向卡：DoOperation（原版 libyoyo.so，armv7）
 * @func 0x207a0c 0x207d18  size 784  196 条（0x207d14..0x207d18 是 literal pool，objdump 译成 andseq）
 * 级别: 正文（op 1/2/3 三条语义、15 路 tag 拷贝表、字符串拼接、double 加/乘的存储体、canary 收尾逐条落地；
 *            残留 open 都在函数之外：tag 2/3 的宿主类型名、YYGetReal 的非 0 tag 转换细节、调用者如何消费返回值）
 * 符号: _Z11DoOperationiP6RValueS0_ → void DoOperation(int op, RValue* dst  [r1], RValue* src  [r2])
 * 位置: 不是 VM 指令处理器，而是 CDS_Grid（ds_grid_*）的单元语义。四个批量算子 Cell/Region/Disk/Grid_Operation
 *       把 (op, 目标槽, 源 RValue) 转给本函数：Cell_Operation(0x207d1c) 用 `b` 尾调，
 *       Region(0x207db4)/Disk(0x207e8c)/Grid(0x207fe8) 在循环里 `bl`。全库对 0x207a0c 的引用共 7 处（1 条 b + 6 条 bl），全部落在 0x207d1c..0x20862c。
 *
 * ── 帧与出口 ─────────────────────────────────────────────────────────
 *   push {r4,r5,r6,r7,r8,lr} + vpush {d8} + sub sp,sp,#1040（0x207a0c..0x207a1c）
 *   r5 = dst（r1），r6 = src（r2）；1024 字节缓冲在 sp+0xc，栈保护字取自 GOT 0x3ed958（__stack_chk_guard），
 *   存 sp+0x40c、退出前比对，不等 → __stack_chk_fail@plt（0x207d10）。即「char buf[1024] + canary」的编译器布局。
 *   出口（0x207af4..0x207b0c）只做 canary 比对与恢复，**不复位 r0**；符号是 void。
 *
 * ── op 分派：只认 1/2/3 ────────────────────────────────────────────
 *   cmp #2 → 0x207b68（add）；cmp #3 → 0x207b10（multiply）；cmp #1 → 0x207a48（set/copy）；
 *   其余（0、4、负数……）直落 0x207af4 空返回（0x207a14..0x207a44）。
 *   op 的取值有调用侧证据，不是从实现猜的：
 *     F_DsGridSetRegion/Disk/GridRegion 分别把 #1 塞进 Region/Disk/Grid_Operation 的第 2 实参（0xfd4dc/0xfd764/0xfda30）；
 *     F_DsGridAdd* 塞 #2（0xfd5b4/0xfd83c/0xfdb58）；F_DsGridMultiply* 塞 #3（0xfd68c/0xfd914/0xfdc80）；
 *     F_DsGridAdd/F_DsGridMultiply 直接给 Cell_Operation 传 #2/#3（0xfd350/0xfd404）。
 *
 * ── op==1：set（把 src 赋给 dst）────────────────────────────────────
 *   kind = dst->tag & 0x00FFFFFF（bic #0xFF000000，0x207a4c）。
 *   kind==1（字符串）：先释放 dst 的旧串 —— 0x207bbc..0x207d00 是 FREE_RValue__Pre 的 kind1 分支内联副本：
 *     LOCK_RVALUE_MUTEX → --[ptr+4] → 归零则 YYFree(ptr->[0])、ptr->[0]=ptr->[8]=0，再走 _RefThing<char const*>::dec()
 *     与 operator delete 的第二级递减（0x207cac..0x207d00）。与 FREE_RValue__Pre(0xc0a7c) 的 kind1 头（0xc0ac0..0xc0ad8）
 *     同构：同一 [ptr+4] 计数、同一 YYFree([ptr]) 载荷。
 *   kind==2：0x207a60..0x207a70 的判定 (tag-1)&0x00FFFFFF&~3 == 0 在本分支恒真
 *     （kind==2 ⇒ tag&0xFFFFFF==2 ⇒ (tag-1)&0xFFFFFF==1 ⇒ &~3==0），所以 kind==2 必调 FREE_RValue__Pre(dst)；
 *     0x207a74 那条「不释放直接置位」的分支在 kind==2 前提下不可达（汇合点仍被 0x207d0c 走到）。
 *     随后 dst->[8]=0、dst->tag=5，再落进下面的拷贝体把 dst 整体改成 src 的值。
 *
 * ── 拷贝体：15 路 tag 表（op1 主体，也是 op2 两侧只要有一侧是字符串时的回退）──
 *   前缀（0x207a84..0x207a9c）：dst->[0]=0、dst->tag=src->tag（原字，含高 8 位）、dst->[8]=src->[8]；
 *   **dst->[4] 不写** —— 与 cards/DoDup.c 记录的 16B 拷贝体逐字一致（两张卡互为交叉证据）。
 *   跳表基址 0x207ab0（addls pc,pc,r3,lsl #2 的 pc=0x207aa8+8）；紧跟 addls 的 0x207aac 那条 b 0x207af4 全库无引用
 *   （表外死代码），按 0x207aac 起表会把 15 路整体错位一格 —— 本卡已按 objdump 逐条核对过。kind 0..14：
 *     0/10/13 → 0x207bb0  ldm/stm 拷 [0],[4]（8 B 载荷：double / int64）
 *     1       → 0x207c68  dst[0]=src[0]，[ptr+4]++（字符串计数在 +4）
 *     2       → 0x207c80  dst[0]=src[0]，[ptr+0]++，若 [ptr+8]==0 则回指 dst（_RefThing 形状）
 *     3/7/14  → 0x207aec  只拷 [0]（裸指针）
 *     6       → 0x207c44  dst[0]=src[0]；非 0 时 GetContextStackTop() + DeterminePotentialRoot(top,ptr)
 *     4/5/8/9/11/12 → 0x207af4 直接返回（只留 tag 与 [8]）
 *   kind 6 的「登记 GC root」在本二进制里等于空转：DeterminePotentialRoot(0x191710) 全身只有一条 `bx lr`（4 B）。
 *
 * ── op==2：add ────────────────────────────────────────────────────
 *   a) 两侧 tag 都 == 1 → 字符串拼接（0x207bf0..0x207c3c）：
 *        memset(buf,0,1024) → snprintf(buf,1024,"%s%s"(0x334bdc), *(char**)dst->[0], *(char**)src->[0])
 *        → YYCreateString(dst,buf)。**没有**先释放 dst 旧串（整段只有 memset/snprintf/YYCreateString 三个调用）。
 *   b) dst==1、src!=1 或 dst!=1、src==1 → 落 0x207a4c（先按 dst 的 kind 释放/清位，再把 src 整体拷进 dst）。
 *      即「add 只要有一侧是字符串，就退化成赋值」。
 *   c) 两侧都不是 1 → 数值（0x207b80..0x207b64）：d8=YYGetReal(dst,0)、d7=YYGetReal(src,0)，
 *       然后共用 0x207b54 的存储体：dst->tag=0、d7=d8+d7、把 d7 的 {lo,hi} 写 [0],[4]。
 *      整段只有两条 bl（都是 YYGetReal），**没有任何释放**：dst 若是 kind1/2/3，旧载荷在这里被直接覆盖。
 *
 * ── op==3：multiply ───────────────────────────────────────────────
 *   dst->tag==1 或 src->tag==1 → 直接返回，dst 原样不动（0x207b10..0x207b24，注意这里比的是原字 tag，不是 kind）。
 *   否则 d = YYGetReal(dst,0) * YYGetReal(src,0)，tag=0，写 {lo,hi}（0x207b54 的存储体，与 op2 共用）。
 *   同样不释放 dst 旧载荷。
 *
 * ── 已证的硬事实（可直接引用）─────────────────────────────────────
 *   1. 三个 op 的语义 = set / add / multiply，由调用侧常量 1/2/3 与 ds_grid_* 的符号名双重钉住。
 *   2. RValue 布局：+0..+7 载荷（double 的 lo/hi）、+8 附加字（kind 2 的回指槽）、+0xc tag；
 *      kind = tag & 0x00FFFFFF，tag 0..14 共 15 路，与 DoDup 的表逐项相同。
 *   3. 字符串 tag==1：+0 = _RefThing<char const*>（计数在 +4，载荷 char* 在 +0），拼接用 %s%s 直接读 *(char**)。
 *   4. kind 6 的 GC 登记是空实现（DeterminePotentialRoot = bx lr），本卡以后不许再把 kind6 当「真的入 root 集」。
 *   5. op2/op3 的数值路径不释放 dst 旧载荷；op2 的纯串拼接也不释放 dst 旧串 —— 是原版行为，不是本卡漏写。
 *
 * ── open ─────────────────────────────────────────────────────────
 *   · tag 2 / tag 3 的宿主类型名（本卡只能证计数位置：kind1 在 +4、kind2 在 +0 且 +8 回指；DoDup 卡记作 YYString / _RefThing）；
 *   · op2 纯串拼接时 dst 旧串是否由 YYCreateString 内部接管（0x207bf0 路径本身不释放）；
 *   · 数值路径不释放 dst 是否真是原版缺陷，还是调用侧保证 dst 必为空（ds_grid_set/add/multiply 的槽初始值）；
 *   · YYGetReal(0xceb24) 的非 0 tag 转换：15 路表（addls 于 0xceb40）、kind10 走 __floatdidf，字符串支路细节未展开；
 *   · Cell_Operation 以 `b` 尾调本函数，返回给 GML 的 r0 是本函数残留值（void 函数，谁消费不明）。
 */
/* ── §1 帧与 op 分派：1=set / 2=add / 3=multiply，其余空返回 ─────────────────── */
/* @0x207a0c push {r4, r5, r6, r7, r8, lr} —— 帧：push 6 字（r4..r8,lr） */
/* @0x207a10 vpush {d8} —— 保存 d8（数值路径用 d7/d8） */
/* @0x207a14 cmp r0, #2 —— op == 2 ? */
/* @0x207a18 ldr r4, [pc, #0x2f4] —— GOT 增量 0x1e5f28 */
/* @0x207a1c sub sp, sp, #1040 —— 帧 1040 B = buf 1024 + canary + 余量 */
/* @0x207a20 mov r5, r1 —— r5 = dst */
/* @0x207a24 mov r6, r2 —— r6 = src */
/* @0x207a28 ldr r4, [pc, r4] —— r4 = &__stack_chk_guard（0x3ed958，GLOB_DAT） */
/* @0x207a2c ldr r3, [r4] —— 取 canary 值 */
/* @0x207a30 str r3, [sp, #0x40c] —— 存 sp+0x40c（紧贴 buf 尾） */
/* @0x207a34 beq 0x207b68 <_Z11DoOperationiP6RValueS0_+0x15c> —— op==2 → 0x207b68 */
/* @0x207a38 cmp r0, #3 —— op == 3 ? */
/* @0x207a3c beq 0x207b10 <_Z11DoOperationiP6RValueS0_+0x104> —— op==3 → 0x207b10 */
/* @0x207a40 cmp r0, #1 —— op == 1 ? */
/* @0x207a44 bne 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— 其余（0/4/负数…）→ 空返回 */
/* ── §2 op==1 的 kind 前置：kind1 先释旧串；kind2 先 FREE_RValue__Pre ────────── */
/* @0x207a48 ldr r3, [r1, #0xc] —— dst 的 tag */
/* @0x207a4c bic r2, r3, #-16777216 —— kind = tag & 0x00FFFFFF */
/* @0x207a50 cmp r2, #1 —— kind == 1 ? */
/* @0x207a54 beq 0x207bbc <_Z11DoOperationiP6RValueS0_+0x1b0> —— 字符串 → 先释放 dst 旧串 */
/* @0x207a58 cmp r2, #2 —— kind == 2 ? */
/* @0x207a5c bne 0x207a84 <_Z11DoOperationiP6RValueS0_+0x78> —— 非 2 → 直接进拷贝体 */
/* @0x207a60 sub r3, r3, #1 —— tag-1 */
/* @0x207a64 bic r3, r3, #-16777216 —— 清高 8 位 */
/* @0x207a68 bic r3, r3, #3 —— 再 &~3 */
/* @0x207a6c cmp r3, #0 —— kind==2 时这里恒 0（见卡头 §1） */
/* @0x207a70 beq 0x207d04 <_Z11DoOperationiP6RValueS0_+0x2f8> —— 恒真 → FREE 支路（0x207d04） */
/* @0x207a74 mov r2, #0 —— 汇合点：dst[8]=0 */
/* @0x207a78 mov r3, #5 —— dst tag=5（随后被拷贝体改成 src tag） */
/* @0x207a7c str r2, [r5, #0x8] —— dst[8]=0 */
/* @0x207a80 str r3, [r5, #0xc] —— dst tag=5 */
/* ── §3 拷贝体：前缀 + 15 路跳表（表基址 0x207ab0，kind 0..14）────────────────── */
/* @0x207a84 ldr r3, [r6, #0xc] —— src tag */
/* @0x207a88 mov r1, #0 —— 0 */
/* @0x207a8c ldr r2, [r6, #0x8] —— src[8] */
/* @0x207a90 str r1, [r5] —— dst[0]=0（dst[4] 全程不写） */
/* @0x207a94 str r3, [r5, #0xc] —— dst tag = src tag（原字，含高 8 位） */
/* @0x207a98 ldr r3, [r6, #0xc] —— 再读 src tag */
/* @0x207a9c str r2, [r5, #0x8] —— dst[8] = src[8] */
/* @0x207aa0 bic r3, r3, #-16777216 —— kind */
/* @0x207aa4 cmp r3, #14 —— kind <= 14 ? */
/* @0x207aa8 addls pc, pc, r3, lsl #2 —— addls pc → 表基址 = 本指令 +8 = 0x207ab0 */
/*     跳表本体从 0x207ab0 起、按 kind 顺序一行一条（0x207aac 那条 b 不在表内）     */
/* @0x207aac b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— 表前一条 b（无引用；kind0 的槽是 0x207ab0） */
/* @0x207ab0 b 0x207bb0 <_Z11DoOperationiP6RValueS0_+0x1a4> —— kind0 → 0x207bb0（拷 8 B） */
/* @0x207ab4 b 0x207c68 <_Z11DoOperationiP6RValueS0_+0x25c> —— kind1 → 0x207c68（串计数在 +4） */
/* @0x207ab8 b 0x207c80 <_Z11DoOperationiP6RValueS0_+0x274> —— kind2 → 0x207c80（计数在 +0，+8 回指） */
/* @0x207abc b 0x207aec <_Z11DoOperationiP6RValueS0_+0xe0> —— kind3 → 0x207aec（只拷 [0]） */
/* @0x207ac0 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— kind4 → 返回 */
/* @0x207ac4 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— kind5 → 返回 */
/* @0x207ac8 b 0x207c44 <_Z11DoOperationiP6RValueS0_+0x238> —— kind6 → 0x207c44（GC root） */
/* @0x207acc b 0x207aec <_Z11DoOperationiP6RValueS0_+0xe0> —— kind7 → 0x207aec */
/* @0x207ad0 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— kind8 → 返回 */
/* @0x207ad4 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— kind9 → 返回 */
/* @0x207ad8 b 0x207bb0 <_Z11DoOperationiP6RValueS0_+0x1a4> —— kind10 → 0x207bb0 */
/* @0x207adc b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— kind11 → 返回 */
/* @0x207ae0 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— kind12 → 返回 */
/* @0x207ae4 b 0x207bb0 <_Z11DoOperationiP6RValueS0_+0x1a4> —— kind13 → 0x207bb0 */
/* @0x207ae8 b 0x207aec <_Z11DoOperationiP6RValueS0_+0xe0> —— kind14 → 0x207aec */
/* @0x207aec ldr r3, [r6] —— 只拷 [0] */
/* @0x207af0 str r3, [r5] —— dst[0]=src[0]（kind 1/3/7/14 汇合于此） */
/* ── §4 统一出口：canary 比对 → 恢复 → pop（不复位 r0）──────────────────────── */
/* @0x207af4 ldr r2, [sp, #0x40c] —— 出口：canary */
/* @0x207af8 ldr r3, [r4] —— 当前 canary */
/* @0x207afc cmp r2, r3 —— 比对 */
/* @0x207b00 bne 0x207d10 <_Z11DoOperationiP6RValueS0_+0x304> —— 不等 → __stack_chk_fail */
/* @0x207b04 add sp, sp, #1040 —— 恢复帧 */
/* @0x207b08 vpop {d8} —— vpop d8 */
/* @0x207b0c pop {r4, r5, r6, r7, r8, pc} —— pop（r0 未设置） */
/* ── §5 op==3 multiply：任一侧是字符串就原样返回，否则 double 相乘 ────────────── */
/* @0x207b10 ldr r3, [r1, #0xc] —— op3：dst tag */
/* @0x207b14 cmp r3, #1 —— dst tag == 1 ? */
/* @0x207b18 beq 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— 串 → 原样返回 */
/* @0x207b1c ldr r3, [r2, #0xc] —— src tag */
/* @0x207b20 cmp r3, #1 —— src tag == 1 ? */
/* @0x207b24 beq 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— 串 → 原样返回 */
/* @0x207b28 mov r0, r1 —— r0 = dst */
/* @0x207b2c mov r1, #0 —— idx = 0 */
/* @0x207b30 bl 0xceb24 <_Z9YYGetRealPK6RValuei> —— bl YYGetReal */
/* @0x207b34 vmov d8, r0, r1 —— d8 = dst */
/* @0x207b38 mov r0, r6 —— r0 = src */
/* @0x207b3c mov r1, #0 —— idx = 0 */
/* @0x207b40 bl 0xceb24 <_Z9YYGetRealPK6RValuei> —— bl YYGetReal */
/* @0x207b44 mov r3, #0 —— 0 */
/* @0x207b48 str r3, [r5, #0xc] —— dst tag = 0（real） */
/* @0x207b4c vmov d7, r0, r1 —— d7 = src */
/* @0x207b50 vmul.f64 d7, d8, d7 —— d7 = d8 * d7 */
/* @0x207b54 vmov r0, r1, d7 —— 存储体：lo 半字 */
/* @0x207b58 vmov r2, s14 —— lo（s14） */
/* @0x207b5c mov r3, r1 —— hi */
/* @0x207b60 stm r5, {r2, r3} —— dst[0]=lo, dst[4]=hi */
/* @0x207b64 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— → 出口 */
/* ── §6 op==2 add：串+串=拼接；否则若有一侧是串就退化成赋值；都不是串则 double 相加 ─ */
/* @0x207b68 ldr r3, [r1, #0xc] —— op2：dst tag */
/* @0x207b6c ldr r2, [r2, #0xc] —— src tag */
/* @0x207b70 cmp r3, #1 —— dst tag == 1 ? */
/* @0x207b74 beq 0x207bf0 <_Z11DoOperationiP6RValueS0_+0x1e4> —— → 0x207bf0（两侧都测） */
/* @0x207b78 cmp r2, #1 —— src tag == 1 ? */
/* @0x207b7c beq 0x207a4c <_Z11DoOperationiP6RValueS0_+0x40> —— → 0x207a4c（退化成赋值） */
/* @0x207b80 mov r0, r1 —— r0 = dst */
/* @0x207b84 mov r1, #0 —— idx = 0 */
/* @0x207b88 bl 0xceb24 <_Z9YYGetRealPK6RValuei> —— bl YYGetReal */
/* @0x207b8c vmov d8, r0, r1 —— d8 = dst */
/* @0x207b90 mov r0, r6 —— r0 = src */
/* @0x207b94 mov r1, #0 —— idx = 0 */
/* @0x207b98 bl 0xceb24 <_Z9YYGetRealPK6RValuei> —— bl YYGetReal */
/* @0x207b9c mov r3, #0 —— 0 */
/* @0x207ba0 str r3, [r5, #0xc] —— dst tag = 0 */
/* @0x207ba4 vmov d7, r0, r1 —— d7 = src */
/* @0x207ba8 vadd.f64 d7, d8, d7 —— d7 = d8 + d7 */
/* @0x207bac b 0x207b54 <_Z11DoOperationiP6RValueS0_+0x148> —— → 存储体 */
/* @0x207bb0 ldm r6, {r2, r3} —— 拷 [0],[4]（8 B 载荷：double / int64） */
/* @0x207bb4 stm r5, {r2, r3} —— [0],[4] 一起写 */
/* @0x207bb8 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— → 出口 */
/*     kind==1 的旧串释放（FREE_RValue__Pre 的 kind1 分支内联副本，两级递减）        */
/* @0x207bbc ldr r7, [r5] —— kind1：dst[0]（_RefThing） */
/* @0x207bc0 cmp r7, #0 —— 空则跳过 */
/* @0x207bc4 beq 0x207be4 <_Z11DoOperationiP6RValueS0_+0x1d8> —— LOCK_RVALUE_MUTEX */
/* @0x207bc8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> —— 计数 */
/* @0x207bcc ldr r8, [r7, #0x4] —— -1 */
/* @0x207bd0 sub r8, r8, #1 —— 写回 */
/* @0x207bd4 str r8, [r7, #0x4] —— 归零? */
/* @0x207bd8 cmp r8, #0 —— cmp */
/* @0x207bdc beq 0x207cac <_Z11DoOperationiP6RValueS0_+0x2a0> —— 归零 → 深释放 */
/* @0x207be0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> —— UNLOCK */
/* @0x207be4 mov r3, #0 —— 0 */
/* @0x207be8 str r3, [r5] —— dst[0]=0 */
/* @0x207bec b 0x207a84 <_Z11DoOperationiP6RValueS0_+0x78> —— → 拷贝体 */
/*     串拼接：snprintf(buf,1024,"%s%s", dst 载荷, src 载荷) → YYCreateString      */
/* @0x207bf0 cmp r2, #1 —— src tag == 1 ?（dst 已确为 1） */
/* @0x207bf4 bne 0x207a4c <_Z11DoOperationiP6RValueS0_+0x40> —— 否则退化成赋值 */
/* @0x207bf8 add r7, sp, #12 —— buf = sp+0xc */
/* @0x207bfc mov r1, #0 —— 0 */
/* @0x207c00 mov r2, #1024 —— 1024 */
/* @0x207c04 mov r0, r7 —— r0 = buf */
/* @0x207c08 bl 0xb65b0 <memset@plt> —— memset(buf,0,1024) */
/* @0x207c0c ldr r12, [r6] —— src->[0] */
/* @0x207c10 ldr r3, [r5] —— dst->[0] */
/* @0x207c14 mov r0, r7 —— r0 = buf */
/* @0x207c18 ldr r2, [pc, #0xf8] —— r2 = 0x334bdc（%s%s） */
/* @0x207c1c mov r1, #1024 —— size = 1024 */
/* @0x207c20 ldr r12, [r12] —— src 载荷 = *(char**) */
/* @0x207c24 ldr r3, [r3] —— dst 载荷 = *(char**) */
/* @0x207c28 add r2, pc, r2 —— r2 = fmt */
/* @0x207c2c str r12, [sp] —— 第 5 实参 = src 载荷 */
/* @0x207c30 bl 0xb65c8 <snprintf@plt> —— snprintf */
/* @0x207c34 mov r0, r5 —— r0 = dst */
/* @0x207c38 mov r1, r7 —— r1 = buf */
/* @0x207c3c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> —— YYCreateString(dst,buf) */
/* @0x207c40 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— → 出口 */
/*     跳表目标：kind6（对象）→ GC root 登记                                      */
/* @0x207c44 ldr r3, [r6] —— kind6：src[0]（对象指针） */
/* @0x207c48 str r3, [r5] —— dst[0]=对象 */
/* @0x207c4c ldr r3, [r6] —— 再读 */
/* @0x207c50 cmp r3, #0 —— 非 0? */
/* @0x207c54 beq 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— 0 → 出口 */
/* @0x207c58 bl 0xd3a54 <_Z18GetContextStackTopv> —— GetContextStackTop() */
/* @0x207c5c ldr r1, [r6] —— r1 = 对象 */
/* @0x207c60 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> —— DeterminePotentialRoot = bx lr（空实现） */
/* @0x207c64 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— → 出口 */
/*     跳表目标：kind1（字符串）计数 +4；kind2（_RefThing）计数 +0 且 +8 回指        */
/* @0x207c68 ldr r3, [r6] —— kind1：src[0] */
/* @0x207c6c cmp r3, #0 —— 空? */
/* @0x207c70 ldrne r2, [r3, #0x4] —— 计数 [+4] */
/* @0x207c74 addne r2, r2, #1 —— +1 */
/* @0x207c78 strne r2, [r3, #0x4] —— 写回 [+4] */
/* @0x207c7c b 0x207af0 <_Z11DoOperationiP6RValueS0_+0xe4> —— → dst[0]=src[0] */
/* @0x207c80 ldr r3, [r6] —— kind2：src[0] */
/* @0x207c84 cmp r3, #0 —— cmp 0 */
/* @0x207c88 str r3, [r5] —— dst[0]=src[0] */
/* @0x207c8c beq 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— 0 → 出口 */
/* @0x207c90 ldr r1, [r3, #0x8] —— 回指槽 [+8] */
/* @0x207c94 ldr r2, [r3] —— 计数 [+0] */
/* @0x207c98 cmp r1, #0 —— 空? */
/* @0x207c9c streq r5, [r3, #0x8] —— 空则回指 dst */
/* @0x207ca0 add r2, r2, #1 —— +1 */
/* @0x207ca4 str r2, [r3] —— 写回 */
/* @0x207ca8 b 0x207af4 <_Z11DoOperationiP6RValueS0_+0xe8> —— → 出口 */
/*     一级计数归零后的深释放：YYFree 载荷 → 二级计数 → _RefThing::dec → delete      */
/* @0x207cac ldr r0, [r7] —— 深释放：ptr[0]（char* 载荷） */
/* @0x207cb0 bl 0xcef90 <_Z6YYFreePKv> —— YYFree(载荷) */
/* @0x207cb4 str r8, [r7] —— ptr[0]=0 */
/* @0x207cb8 str r8, [r7, #0x8] —— ptr[8]=0 */
/* @0x207cbc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> —— 再 LOCK */
/* @0x207cc0 ldr r8, [r7, #0x4] —— 二级计数 */
/* @0x207cc4 sub r8, r8, #1 —— -1 */
/* @0x207cc8 str r8, [r7, #0x4] —— 写回 */
/* @0x207ccc cmp r8, #0 —— 归零? */
/* @0x207cd0 bne 0x207cf4 <_Z11DoOperationiP6RValueS0_+0x2e8> —— 非 0 → 0x207cf4 */
/* @0x207cd4 ldr r0, [r7] —— ptr[0] */
/* @0x207cd8 bl 0xcef90 <_Z6YYFreePKv> —— YYFree（此时已为 0） */
/* @0x207cdc mov r0, r7 —— r0 = ptr */
/* @0x207ce0 str r8, [r7] —— ptr[0]=0 */
/* @0x207ce4 str r8, [r7, #0x8] —— ptr[8]=0 */
/* @0x207ce8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> —— _RefThing<char const*>::dec() */
/* @0x207cec mov r0, r7 —— r0 = ptr */
/* @0x207cf0 bl 0x27d1d0 <_ZdlPv> —— operator delete(ptr) */
/* @0x207cf4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> —— UNLOCK */
/* @0x207cf8 mov r0, r7 —— r0 = ptr */
/* @0x207cfc bl 0x27d1d0 <_ZdlPv> —— operator delete(ptr) */
/* @0x207d00 b 0x207be0 <_Z11DoOperationiP6RValueS0_+0x1d4> —— → 0x207be0（再 UNLOCK 后回拷贝体） */
/*     kind==2 的释放钩子（调用 FREE_RValue__Pre 后汇合到 0x207a74）               */
/* @0x207d04 mov r0, r5 —— r0 = dst */
/* @0x207d08 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> —— FREE_RValue__Pre(dst) */
/* @0x207d0c b 0x207a74 <_Z11DoOperationiP6RValueS0_+0x68> —— → 0x207a74 */
/* ── §7 尾部：canary 失败桩 + literal pool（两个数据字，objdump 译成 andseq，非指令）── */
/* @0x207d10 bl 0xb65d4 <__stack_chk_fail@plt> —— __stack_chk_fail */
/* @0x207d14 andseq r5, lr, r8, lsr #30 —— literal 0x1e5f28：GOT 增量（非指令） */
/* @0x207d18 andseq r12, r2, r12, lsr #31 —— literal 0x12cfac：%s%s 的 pc 增量（非指令） */
