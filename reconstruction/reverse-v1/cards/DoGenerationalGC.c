/* cally 逆向卡：DoGenerationalGC（原版 libyoyo.so，armv7）
 * @func 0xd6850 0xd6aac  size 604  151 条（0xd6a80..0xd6aa8 是 literal pool：1 个 GOT 增量 + 10 个负偏移字）
 * 级别: 正文（控制流、全部存储副作用、两个整型门限与四个浮点常量、代数迁移规则逐条落地；
 *            记录字段的「语义名」只到「MarkAndSweepGen 写入的统计量」这一档，具体含义列入 open）
 * 符号: _Z16DoGenerationalGCv → void DoGenerationalGC()
 * 位置: 全库没有任何 bl/b 指向 0xd6850，但 .dynsym 里是 GLOBAL FUNC（导出 604 B）→ 由外部（JNI/宿主）按符号调用，
 *       不是 C++ 内部静态函数。同族的 MarkAndSweepGen(0xd5ba8, 718 条) 与本函数共用同一开关字节与同一记录数组。
 *
 * ── 全局状态（全部经 GOT 取值，GOT 基址 r6 = 0x3f1c58，与 MarkAndSweepGen 完全相同）────
 *   0x3edbc0 → 0x47f295   u8   GC 开关（0=整函数什么都不做）
 *   0x3edc9c → 0x47a1f8   int  当前代 g_gen（0..3）
 *   0x3edca0 → 0x47a1f4   int  调用计数 g_gcCalls（本函数返回前 +1）
 *   0x3edc68 → 0x536da8        记录数组基址（MarkAndSweepGen 也用它）
 *   记录步长 88 B（0x58），rec = 0x536da8 + 88*gen；rec3 = 0x536da8+0x108
 *   0x3edcb8 → 0x3f206c   int   200   （B 的下限）
 *   0x3edcbc → 0x3f2068   float 4.0f  （自适应比值上限）
 *   0x3edcc0 → 0x3f2060   float 1.1f  （自适应系数的乘数）
 *   0x3edcc4 → 0x3f2064   float 0.5f  （自适应比值下限）
 *   0x3edcc8 → 0x3f205c   float 2.0f  （增长率/耗时比阈值）
 *   0x3edccc → 0x3f2058   int   30    （三十门槛）
 *
 * ── §1 开关（0xd6850..0xd6878）────────────────────────────────────
 *   读 0x47f295 的字节，为 0 就 vpop/pop 直接返回 —— 连 MarkAndSweepGen 都不调。
 *
 * ── §2 先扫「当前代」（0xd687c..0xd689c）──────────────────────────
 *   MarkAndSweepGen(g_gen, g_gcCalls, true)：第 1 实参取 0x47a1f8，第 2 实参取 0x47a1f4，
 *   第 3 实参恒 #1（0xd6880 mov r2,#1）。顺序是「先扫，再决定迁移」，不是先迁移。
 *
 * ── §3 记录与两道早退（0xd68a0..0xd68d0）──────────────────────────
 *   A = rec[0x20]；A==0 → gen=0。
 *   B = rec[0x24]；B <= 200 → gen=0。
 *   两条都跳 0xd69a4（只做 g_gen=0，然后走收尾）。
 *
 * ── §4 增长率与自适应系数（0xd68d4..0xd6964）──────────────────────
 *   (float)B/(float)A > 2.0f                         → promote=1（0xd69c0）
 *   否则若 B>0 且 rec[0x2c] > 0：
 *     r = (float)rec[0x28] / (float)B
 *     r >= 4.0f            → rec[0x2c] *= 1.1f，不晋升（0xd6a60）
 *     r <  4.0f            → r /= rec[0x2c]；rec[0x2c] *= 1.1f；r < 0.5f 时 promote=1（0xd6938..0xd6964）
 *   两条支路都把 rec[0x2c] 乘 1.1：它是「每次 GC 就放大一次」的自适应系数，唯一差别是是否用「除掉系数后的比值」去撞 0.5 下限。
 *
 * ── §5 gen==1 专用：64 位耗时比（0xd69c8..0xd6a18）────────────────
 *   比较 rec[0x40]（第 1 代）与 rec0[0x40]（第 0 代，rec0 = 0x536da8）的 int64：
 *     rec0[0x40] < 1              → promote=0
 *     否则 promote = ((float)((double)rec[0x40] / (double)rec0[0x40]) > 2.0f)
 *   这两个 64 位量由 MarkAndSweepGen 用 Timing_Time() 差值写入（0xd6570 bl、0xd6580 strd）；把它们解释成「该代上次 GC 的耗时 ticks」
 *   是从写入口反推的，字段名本身没有证据（见 open 第 1 条）。
 *
 * ── §6 三十门槛的晋升补偿（0xd6a1c..0xd6a5c，只对 gen<=1 可达）──────
 *   if rec[0x34] > 30：
 *     gen >= rec[0x38]        → promote=1（0xd6a78，直接跳迁移体）
 *     rec[0x34] < rec[0x30]   → promote=1（同一目标）
 *     否则 promote = min(rec[0x38] - gen + 1, 2)（0xd6a4c..0xd6a58，上限 2）
 *   gen>=2 到不了这段：0xd6978 的 `ble 0xd6a1c` 只在 gen<=1 时成立。
 *
 * ── §7 迁移与收尾（0xd697c..0xd69bc）──────────────────────────────
 *   promote <= 0 → g_gen = 0
 *   newgen = gen + promote；newgen <= 3 → 写回 g_gen
 *   newgen >  3 → g_gen = 0 且 rec3[0x20] = rec3[0x24]（0x128/0x12c 就是 rec3 的 +0x20/+0x24）
 *   最后 g_gcCalls++（0xd69b0..0xd69b8）：**所有过了开关闸的路径都执行**（0xd69a4 的归零路径也落到 0xd69ac），
 *   只有开关关闭时 0xd6874 的早退不计数。
 *
 * ── 已证的硬事实（可直接引用）─────────────────────────────────────
 *   1. 语义 = 「先对本代做一次 MarkAndSweepGen(gen, calls, true)，再按统计量决定下一代」；代数上界 3，
 *      MarkAndSweepGen 自己也硬性要求 gen<=3（0xd5be0 cmp r0,#3 / bls），两边一致。
 *   2. 所有失败/无数据/不晋升的路径都写 g_gen = 0（回到第 0 代），没有「保持不变」这一支。
 *   3. gen!=1 时 0xd696c 的 movne 会把 §4/§5 算出的 promote 清零（gen 0/2/3 都走这条），唯一能跳过清零的是
 *      B/A > 2.0 那条（0xd68f4 bgt → 0xd69c0 mov r3,#1 → 0xd6974）。后果：§5 的 64 位耗时比只在 gen==1 生效；
 *      第 2/3 代只能靠 B/A > 2.0 晋升 1 级；第 0 代要么走 B/A > 2.0，要么走三十门槛（两条都不经清零）。
 *   4. 四条把 promote 置正的入口：0xd68f4（B/A>2.0）、0xd6964（自适应比值<0.5）、0xd6a18（gen1 耗时比>2.0）、
 *      0xd6a3c/0xd6a48（三十门槛补偿，直接进迁移体）；其中前三条都只给 1，只有 0xd6a4c 的 min(rec[0x38]-gen+1,2) 能给 2。
 *   5. 策略常量全在 .data 0x3f2058..0x3f206c（200 / 30 / 2.0f / 1.1f / 0.5f / 4.0f），各改一个字节就能做变异实验。
 *   6. 0x47a1f4（本函数自增的计数）被当作 MarkAndSweepGen 的第 2 实参，那边写进 rec[0x1c] 并参与 0xd64bc..0xd64e4 的比较
 *      —— 也就是说「调用次数」被 GC 当作某种年龄/上限在用（具体含义 open）。
 *
 * ── open ─────────────────────────────────────────────────────────
 *   · rec 字段语义：+0x20 与 +0x24 由 MarkAndSweepGen 0xd6538/0xd6560 写（同一次 GC 的统计），本卡只当「基数/本次计数」用；
 *     +0x28 由 0xd60ac 写；+0x2c 由 0xd654c 写（一个比值）；+0x30/+0x34/+0x38 在 0xd6534..0xd6564 之间互相搬运 —— 都未定名；
 *   · 分代策略为什么这样分层：第 0 代有「B/A>2.0」与「三十门槛」两条晋升路，第 1 代另加 64 位耗时比，
 *     第 2/3 代只剩 B/A>2.0 —— 只有恒量与分支证据，没有设计文档；
 *   · 0x47f295 开关字节的置位点（本卡未取证谁把它设成 1）；
 *   · 「r>=4.0 只放大系数、不晋升」是防抖还是另有用途，只有恒量与比较，没有设计文档；
 *   · MarkAndSweepGen(0xd5ba8) 内部对 rec 的完整语义（718 条，未出卡）。
 */
/* ── §1 开关：0x47f295 为 0 就直接返回（连 MarkAndSweepGen 都不调）────────────── */
/* @0xd6850 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 帧：10 字 + d8 */
/* @0xd6854 vpush {d8} —— 保存 d8 */
/* @0xd6858 ldr r6, [pc, #0x220] —— GOT 增量 0x31b3f0 */
/* @0xd685c ldr r3, [pc, #0x220] —— 开关槽 -0x4098 */
/*     GOT 基址 r6 = 0x3f1c58（与 MarkAndSweepGen 同一个），下列全局全走 r6+负偏移          */
/* @0xd6860 add r6, pc, r6 —— r6 = 0x3f1c58 */
/* @0xd6864 ldr r3, [r6, r3] —— r3 = *(0x3edbc0) = 0x47f295 */
/* @0xd6868 ldrb r3, [r3] —— GC 开关字节 */
/* @0xd686c cmp r3, #0 —— 为 0 ? */
/* @0xd6870 bne 0xd687c <_Z16DoGenerationalGCv+0x2c> —— 非 0 → 继续 */
/* @0xd6874 vpop {d8} —— 关闭：vpop */
/* @0xd6878 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 关闭：返回 */
/* ── §2 先扫当前代：MarkAndSweepGen(g_gen, g_gcCalls, true) ──────────────────── */
/* @0xd687c ldr r3, [pc, #0x204] —— 计数槽 -0x3fb8 → 0x47a1f4 */
/* @0xd6880 mov r2, #1 —— 第 3 实参 = true */
/* @0xd6884 ldr r1, [pc, #0x200] —— 代号槽 -0x3fbc → 0x47a1f8 */
/* @0xd6888 mov r11, #88 —— 记录步长 88 */
/* @0xd688c ldr r8, [r6, r3] —— r8 = &g_gcCalls */
/* @0xd6890 ldr r7, [r6, r1] —— r7 = &g_gen */
/* @0xd6894 ldr r1, [r8] —— 第 2 实参 = 计数当前值 */
/* @0xd6898 ldr r0, [r7] —— 第 1 实参 = 当前代 */
/* @0xd689c bl 0xd5ba8 <_Z15MarkAndSweepGeniib> —— MarkAndSweepGen(gen,calls,true) */
/* ── §3 rec = 0x536da8 + 88*gen；A=rec[0x20]、B=rec[0x24]，两道早退都落到 gen=0 ───── */
/* @0xd68a0 ldr r3, [pc, #0x1e8] —— 数组槽 -0x3ff0 → 0x536da8 */
/* @0xd68a4 ldr r9, [r7] —— r9 = gen */
/* @0xd68a8 ldr r10, [r6, r3] —— r10 = 记录数组基址 */
/* @0xd68ac mla r11, r11, r9, r10 —— r11 = base + 88*gen */
/* @0xd68b0 ldr r3, [r11, #0x20] —— A = rec[0x20] */
/* @0xd68b4 cmp r3, #0 —— A == 0 ? */
/* @0xd68b8 beq 0xd69a4 <_Z16DoGenerationalGCv+0x154> —— A==0 → gen=0 */
/* @0xd68bc ldr r1, [pc, #0x1d0] —— 门限槽 -0x3fa0 → 0x3f206c */
/* @0xd68c0 ldr r2, [r11, #0x24] —— B = rec[0x24] */
/* @0xd68c4 ldr r1, [r6, r1] —— r1 = &200 */
/* @0xd68c8 ldr r1, [r1] —— 200 */
/* @0xd68cc cmp r2, r1 —— B 与 200 */
/* @0xd68d0 ble 0xd69a4 <_Z16DoGenerationalGCv+0x154> —— B<=200 → gen=0 */
/* ── §4 增长率 B/A 与满 2.0f 的比较；否则进自适应系数 rec[0x2c] 那一套 ───────── */
/* @0xd68d4 vmov s14, r3 —— A（位模式） */
/* @0xd68d8 vmov s12, r2 —— B（位模式） */
/* @0xd68dc vcvt.f32.s32 s13, s14 —— s13 = (float)A */
/* @0xd68e0 vcvt.f32.s32 s15, s12 —— s15 = (float)B */
/* @0xd68e4 vdiv.f32 s13, s15, s13 —— s13 = B/A */
/* @0xd68e8 vmov.f32 s14, #2.000000e+00 —— 2.0f */
/* @0xd68ec vcmpe.f32 s13, s14 —— B/A 与 2.0f */
/* @0xd68f0 vmrs APSR_nzcv, fpscr —— 取 flags */
/* @0xd68f4 bgt 0xd69c0 <_Z16DoGenerationalGCv+0x170> —— B/A>2.0 → promote=1 */
/* @0xd68f8 cmp r2, #0 —— B <= 0 ? */
/* @0xd68fc ble 0xd6968 <_Z16DoGenerationalGCv+0x118> —— B<=0 → 0xd6968 */
/* @0xd6900 vldr s14, [r11, #44] —— f = rec[0x2c] */
/* @0xd6904 vcmpe.f32 s14, #0 —— f <= 0 ? */
/* @0xd6908 ldr r3, [r11, #0x28] —— rec[0x28] */
/* @0xd690c vmrs APSR_nzcv, fpscr —— 取 flags */
/* @0xd6910 ble 0xd6968 <_Z16DoGenerationalGCv+0x118> —— f<=0 → 0xd6968 */
/* @0xd6914 vmov s13, r3 —— rec[0x28] 位模式 */
/* @0xd6918 ldr r3, [pc, #0x178] —— 4.0f 槽 -0x3f9c */
/* @0xd691c vcvt.f32.s32 s12, s13 —— s12 = (float)rec[0x28] */
/* @0xd6920 ldr r3, [r6, r3] —— r3 = &4.0f */
/* @0xd6924 vldr s13, [r3] —— 4.0f */
/* @0xd6928 vdiv.f32 s15, s12, s15 —— r = rec[0x28]/B */
/* @0xd692c vcmpe.f32 s15, s13 —— r 与 4.0f */
/* @0xd6930 vmrs APSR_nzcv, fpscr —— 取 flags */
/* @0xd6934 bpl 0xd6a60 <_Z16DoGenerationalGCv+0x210> —— r>=4.0 → 0xd6a60 */
/* @0xd6938 vdiv.f32 s15, s15, s14 —— r = r / f */
/* @0xd693c ldr r2, [pc, #0x158] —— 1.1f 槽 -0x3f98 */
/* @0xd6940 ldr r3, [pc, #0x158] —— 0.5f 槽 -0x3f94 */
/* @0xd6944 ldr r2, [r6, r2] —— r2 = &1.1f */
/* @0xd6948 vldr s12, [r2] —— 1.1f */
/* @0xd694c ldr r3, [r6, r3] —— r3 = &0.5f */
/* @0xd6950 vldr s13, [r3] —— 0.5f */
/* @0xd6954 vmul.f32 s14, s14, s12 —— f' = f*1.1 */
/* @0xd6958 vcmpe.f32 s15, s13 —— r 与 0.5f */
/* @0xd695c vstr s14, [r11, #44] —— rec[0x2c] = f*1.1 */
/* @0xd6960 vmrs APSR_nzcv, fpscr —— 取 flags */
/* @0xd6964 bmi 0xd69c0 <_Z16DoGenerationalGCv+0x170> —— r<0.5 → promote=1 */
/* ── §4b 分支汇合：gen!=1 先把 promote 清零；gen==1 转 64 位耗时比（§5）─────────── */
/* @0xd6968 cmp r9, #1 —— gen == 1 ? */
/* @0xd696c movne r3, #0 —— gen!=1 → promote=0（清零） */
/* @0xd6970 beq 0xd69c8 <_Z16DoGenerationalGCv+0x178> —— gen==1 → 0xd69c8 */
/* @0xd6974 cmp r9, #1 —— gen <= 1 ? */
/* @0xd6978 ble 0xd6a1c <_Z16DoGenerationalGCv+0x1cc> —— gen<=1 → 0xd6a1c */
/* ── §7 迁移：promote<=0 回第 0 代；否则 newgen=gen+promote，>3 则清 0 并重定 rec3 基数 ─ */
/* @0xd697c cmp r3, #0 —— promote <= 0 ? */
/* @0xd6980 ble 0xd69a4 <_Z16DoGenerationalGCv+0x154> —— → gen=0 */
/* @0xd6984 add r9, r3, r9 —— newgen = gen + promote */
/* @0xd6988 cmp r9, #3 —— newgen <= 3 ? */
/* @0xd698c strle r9, [r7] —— 写回 g_gen */
/* @0xd6990 ldrgt r3, [r10, #0x12c] —— 溢出：rec3[0x24] */
/* @0xd6994 movgt r2, #0 —— 0 */
/* @0xd6998 strgt r2, [r7] —— g_gen = 0 */
/* @0xd699c strgt r3, [r10, #0x128] —— rec3[0x20] = rec3[0x24] */
/* @0xd69a0 b 0xd69ac <_Z16DoGenerationalGCv+0x15c> —— → 收尾 */
/*     归零路径：g_gen = 0                                                      */
/* @0xd69a4 mov r3, #0 —— 0 */
/* @0xd69a8 str r3, [r7] —— g_gen = 0 */
/* ── §8 收尾：vpop/pop + g_gcCalls++（只有开关关闭的早退不走这里）───────────────── */
/* @0xd69ac vpop {d8} —— vpop d8（归零路径 0xd69a4 也落到这里） */
/* @0xd69b0 ldr r3, [r8] —— g_gcCalls */
/* @0xd69b4 add r3, r3, #1 —— +1 */
/* @0xd69b8 str r3, [r8] —— 写回 */
/* @0xd69bc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 返回 */
/*     promote=1 的短路径（B/A>2.0 与自适应比值<0.5 都跳到这里）                    */
/* @0xd69c0 mov r3, #1 —— promote = 1 */
/* @0xd69c4 b 0xd6974 <_Z16DoGenerationalGCv+0x124> —— → 0xd6974 */
/* ── §5 gen==1：rec[0x40] / rec0[0x40] 的 64 位耗时比 > 2.0f ────────────────── */
/* @0xd69c8 ldrd r4, r5, [r10, #64] —— rec0[0x40..0x48) 的 64 位值 */
/* @0xd69cc cmp r4, #1 —— 64 位与 1 比较 */
/* @0xd69d0 sbcs r3, r5, #0 —— 借位 */
/* @0xd69d4 movlt r3, #0 —— <1 → promote=0 */
/* @0xd69d8 blt 0xd6a1c <_Z16DoGenerationalGCv+0x1cc> —— → 0xd6a1c */
/* @0xd69dc ldrd r0, r1, [r11, #64] —— rec[0x40..0x48) */
/* @0xd69e0 bl 0x319164 <__floatdidf> —— int64 → double */
/* @0xd69e4 vmov d8, r0, r1 —— d8 = rec 耗时 */
/* @0xd69e8 mov r0, r4 —— r0 = rec0 低字 */
/* @0xd69ec mov r1, r5 —— r1 = rec0 高字 */
/* @0xd69f0 bl 0x319164 <__floatdidf> —— int64 → double */
/* @0xd69f4 ldr r3, [pc, #0xa8] —— 2.0f 槽 -0x3f90 */
/* @0xd69f8 ldr r3, [r6, r3] —— r3 = &2.0f */
/* @0xd69fc vldr s15, [r3] —— 2.0f */
/* @0xd6a00 vmov d6, r0, r1 —— d6 = rec0 耗时 */
/* @0xd6a04 vdiv.f64 d8, d8, d6 —— d8 = rec/rec0 */
/* @0xd6a08 vcvt.f32.f64 s16, d8 —— → float */
/* @0xd6a0c vcmpe.f32 s16, s15 —— 与 2.0f */
/* @0xd6a10 vmrs APSR_nzcv, fpscr —— 取 flags */
/* @0xd6a14 movle r3, #0 —— <= */
/* @0xd6a18 movgt r3, #1 —— > → promote=1 */
/* ── §6 三十门槛（rec[0x34] > 30）的晋升补偿，只对 gen<=1 可达 ─────────────────── */
/* @0xd6a1c ldr r1, [pc, #0x84] —— 30 槽 -0x3f8c */
/* @0xd6a20 ldr r2, [r11, #0x34] —— rec[0x34] */
/* @0xd6a24 ldr r1, [r6, r1] —— r1 = &30 */
/* @0xd6a28 ldr r1, [r1] —— 30 */
/* @0xd6a2c cmp r2, r1 —— 与 30 比较 */
/* @0xd6a30 ble 0xd697c <_Z16DoGenerationalGCv+0x12c> —— <=30 → 用 promote */
/* @0xd6a34 ldr r3, [r11, #0x38] —— rec[0x38] */
/* @0xd6a38 cmp r9, r3 —— gen 与 rec[0x38] */
/* @0xd6a3c bge 0xd6a78 <_Z16DoGenerationalGCv+0x228> —— gen>=rec[0x38] → promote=1 */
/* @0xd6a40 ldr r1, [r11, #0x30] —— rec[0x30] */
/* @0xd6a44 cmp r2, r1 —— rec[0x34] 与 rec[0x30] */
/* @0xd6a48 blt 0xd6a78 <_Z16DoGenerationalGCv+0x228> —— < → promote=1 */
/* @0xd6a4c rsb r3, r9, r3 —— rec[0x38]-gen */
/* @0xd6a50 add r3, r3, #1 —— +1 */
/* @0xd6a54 cmp r3, #2 —— 与 2 比较 */
/* @0xd6a58 movge r3, #2 —— 上限 2 */
/* @0xd6a5c b 0xd697c <_Z16DoGenerationalGCv+0x12c> —— → 0xd697c */
/*     r >= 4.0f：只把 rec[0x2c] 乘 1.1，不晋升                                    */
/* @0xd6a60 ldr r3, [pc, #0x34] —— 1.1f 槽 -0x3f98 */
/* @0xd6a64 ldr r3, [r6, r3] —— r3 = &1.1f */
/* @0xd6a68 vldr s15, [r3] —— 1.1f */
/* @0xd6a6c vmul.f32 s14, s14, s15 —— f*1.1 */
/* @0xd6a70 vstr s14, [r11, #44] —— rec[0x2c] = f*1.1 */
/* @0xd6a74 b 0xd6968 <_Z16DoGenerationalGCv+0x118> —— → 0xd6968 */
/*     三十门槛命中：promote=1 并直接跳迁移体（跳过 promote<=0 判定）                 */
/* @0xd6a78 mov r3, #1 —— promote = 1 */
/* @0xd6a7c b 0xd6984 <_Z16DoGenerationalGCv+0x134> —— → 迁移体（跳过 promote<=0） */
/* ── §9 literal pool：0xd6a80 是 GOT 增量（objdump 译成 ldrshteq），其余是负偏移字 ─── */
/* @0xd6a80 ldrshteq r11, [r1], -r0 —— literal 0x31b3f0：GOT 增量（非指令） */
/* @0xd6a84 .word 0xffffbf68 —— literal -0x4098：开关槽偏移 */
/* @0xd6a88 .word 0xffffc048 —— literal -0x3fb8：计数槽偏移 */
/* @0xd6a8c .word 0xffffc044 —— literal -0x3fbc：代号槽偏移 */
/* @0xd6a90 .word 0xffffc010 —— literal -0x3ff0：数组槽偏移 */
/* @0xd6a94 .word 0xffffc060 —— literal -0x3fa0：200 槽偏移 */
/* @0xd6a98 .word 0xffffc064 —— literal -0x3f9c：4.0f 槽偏移 */
/* @0xd6a9c .word 0xffffc068 —— literal -0x3f98：1.1f 槽偏移（两条路共用） */
/* @0xd6aa0 .word 0xffffc06c —— literal -0x3f94：0.5f 槽偏移 */
/* @0xd6aa4 .word 0xffffc070 —— literal -0x3f90：2.0f 槽偏移 */
/* @0xd6aa8 .word 0xffffc074 —— literal -0x3f8c：30 槽偏移 */
