/* cally 逆向卡：DoSet（原版 libyoyo.so，armv7）
 * @func 0xe2014 0xe3d30  size 7452  1863 条指令（其中 1691 条可达指令 + 20 张跳转表 + 14 字 literal pool）
 * 级别: 骨架（分派树 / 操作数装箱协议 / 栈效果 / K=1..6 六种比较 / K=14,15 严格相等极性 已证；
 *       K=7..11 与 17 个具体类型组合的重载未逐个钉死，见 open）
 * 符号: _Z5DoSetjPhPKhP6VMExec → uchar* DoSet(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   K = (arg >> 8) & 0xF                                  e2018 ubfx r9,r0,#0x8,#0x4
 *   T = (arg >> 16) & 0xFF                                e2038 lsr r12,r0,#16 / e2054 uxtb r4,r12
 *   位 15..0 与位 30 在本函数内全程未被读（全函数无 sxth、无 ands/tst #0x40000000）
 *     T 低半字节 = 栈顶操作数(右)类型，T>>4 = 次栈顶操作数(左)类型   e205c and r1,r4,#15 / e206c lsr r1,r4,#4
 *   实参 base(r2) 自 e2058 起被覆盖成 boxType 的第 3 实参，此后从不被读   e2058 mov r2, r1
 *   exec(r3) 只在 e2030 存入 r8，供错误路径当第 1 实参用   e2030 mov r8,r3 / e28a4 mov r0,r8
 *   分派 1: 7<=K<=10 → 泛型装箱路径                         e2034/e2040 bhi
 *           K∈{8,9} → e2050；K∈{7,10} → e21d4             e2044/e2048/e204c
 *   分派 2（K∉[7,10]）: K-12∈{0,1}→e23bc；K-14∈{0,1}→e2570；K==11→e2684；否则 K∈[0,6]  e215c-e2178
 *   分派 3: 按 T&0xF 的 8 路表                              e21ac cmp r3,#6 / e21b0 addls pc,pc,r3,lsl #2
 *   分派 4: 按 T>>4 的 8 路表                               e2224 asr r3,r11,#4 / e2228 addls
 *   分派 5: 按 T 全字节 17 个组合 + 默认                     e2268-e229c 的 cmp/beq 链，实测落点：
 *           0x00→e24a8 0x02→e27dc 0x04→e3274 0x20→e2718 0x22→e37b4 0x23→e264c 0x24→e37b4
 *           0x30→e3524 0x32→e2758 0x33→e3908 0x40→e2500 0x42→e37b4 0x44→e37b4 0x46→e2798
 *           0x64→e3650 0x66→e31c0 0xFF→e22a0；其余 → e33c0（未支持组合）
 *   两个操作数都用 boxType(RValue&,eVM_Type,uchar*) 装箱，返回值 = 消耗后的 sp   e2068/e2078/e21ec/e21fc/
 *           e23d4/e23e4/e2588/e2598/e2698/e26ac
 *   操作数尺寸（boxType @0xd7784 的类型码，本次一并反汇编核对）:
 *           0=8B double 1=4B f32 2=4B i32 3=8B i64 4=4B i32(tag13) 5=16B RValue 6=4B 指针(tag1)
 *           7/8=0B 9=null 常量 0B（写 tag5）
 *   栈效果: 右操作数在 sp，左操作数紧随其后；r4 = sp + size(右)（e23a4 #4 / e23ac #8），
 *           r7 = r4 + size(左)（e2338 #4 / e23b4 #8），结果 4 字节写 [r7-4]，返回 sp = r7-4
 *           e226c sub r8,r7,#4 → e28f0 str r0,[r7,#-0x4] → e247c/e2940 mov r0,r8
 *   数值比较的核：先算 d7 = 左 - 右，再与 GOT 全局常量比较
 *           0x00 组合: e24ac/e24b0 vldr d6,[r4] / d7,[r10] → e24b4 vsub.f64 d7,d6,d7
 *           常量: e2948 ldr r3,[pc,#0x6d0] → 字面量 e3020 = 0xffffc0c8；r6(GOT 锚)=0x3f1c58
 *                 → GOT 槽 0x3edd20 → 指针 0x3f20a0 → 8 字节 0x3EE4F8B588E368F1 = 1e-05
 *   K=1..6 六种比较（e24bc 的 addls，有效项自 e24c4 起；数值核用 ±1e-05）：
 *           1 = 左<右   e2e40（diff < -1e-5 → movmi #1）
 *           2 = 左<=右  e2e20（diff <= +1e-5 → movls #1）
 *           3 = 左==右  e2dec（|diff| <= 1e-5：先 blt -1e-5 → 0，再 <= +1e-5 → 1）
 *           4 = 左!=右  e2db8（|diff| > 1e-5：先 < -1e-5 → 1，再 > +1e-5 → 1）
 *           5 = 左>=右  e2d94（diff >= -1e-5 → movge #1）
 *           6 = 左>右   e29f4（diff > +1e-5 → movgt #1）
 *   字符串路径（T=0x66，两个指针）用 strcmp(左,右) 独立复现同一 K 顺序：
 *           e31c0-e31fc strcmp；K=1→e326c lsr #31（<0）、K=2→e325c（<=0）、K=3→e3250（==0）、
 *           K=4→e3244（!=0）、K=5→e3238（mvn+lsr31，>=0）、K=6→e3228（>0）
 *   K=14/15: e25cc abstractStrictEqualityComparison(左,右)，e25d0 cmp r9,#14 / e25d8 eorne r0,r0,#1
 *           → 14 不取反（===），15 取反（!==）；结果 e25e0 str r0,[r4,#-0x4]
 *   K=12/13: e2424 abstractEqualityComparison(&res,右,左)，之后按浮点结果落 0/1（e2430-e2450）
 *   K=11:    e3a80 F_JS_ToString(左)、e3ab0 JS_GetProperty，结果 = (返回 tag != 0x00FFFFFF)
 *            e3ab4-e3ac8 → 属性存在性判定；右操作数 tag!=6 时 e26e4 JSThrowTypeError
 *   未解析引用 tag==0x00FFFFFF → JSThrowReferenceError（8 个调用点）: bl 在 e24e4 / e254c /
 *           e281c / e2830 / e2894 / e3a68 / e3b64 / e3bdc，对应判定在 e2094 / e20a4 / e23fc /
 *           e25b0 / e26c0 / e26d0 / e25c0 / e3b88 一带
 *   临时 RValue 释放判据 (tag-1)&0x00FFFFFC==0 即 tag∈{1,2,3,4}，才调 FREE_RValue__Pre（9 个调用）:
 *           e211c→e2564、e2148→e2558、e25f4→e3b50、e2904→e31b4、e3adc→e3d08、e3b34→e3b40、
 *           e3b0c→e3d14、e2624→e262c、e2938 一带
 *   未支持的类型组合 e33c0：只有 K=4(!=) 得 1（e33f0），其余得 0（e33e8）
 *
 * 结论（结构性事实）：
 *   1. **DoSet 不是「把栈顶写进变量槽」的赋值处理器**——目标描述需更正。全函数没有一处
 *      100000/99328 基址算术、没有 lsl #4 的 16 字节槽步长、没有 Code_Variable_Find_Name /
 *      Variable_SetValue 调用，也从不读 base 或 exec 的字段；34 条 str 全部落在值栈
 *      （[r8-4]/[r7-4]/[r4-4]/[r10-0x20]!/[r4-0x10]!）或本函数栈帧内。它是**比较算子**：
 *      arg[11:8] 选算子（<,<=,==,!=,>=,> 与四条 JS 语义慢路径），arg[23:16] 给两个操作数的静态
 *      类型，结果是一个 4 字节整数（绝大多数路径 0/1，字符串 == 路径会留 1-strcmp 的非零值）。
 *   2. 该 so 的值栈是**按静态类型紧凑编码**的（同一 opcode 的两个类型半字节决定每个操作数占
 *      4/8/16 字节），boxType 负责把紧凑编码装箱成 16 字节 RValue（tag 在 +12）。
 *   3. 实数比较带 **1e-05 容差**（全局 double，经 GOT 两跳取），所以 == 是 |左-右| <= 1e-5、
 *      != 是 |左-右| > 1e-5 —— 不是位相等。
 *   4. 处理器表（.data VA 0x3f2108 起）里 DoSet 紧接 DoShr、前于 DoBranch，与 DoAdd/DoSub…
 *      同一族，属"二元算子"槽位。
 *   5. 结构上 20 张跳转表（2 张 8 路类型表、2 张 15 路 RValue-tag 表、16 张 7 路 K-1 六算子表）
 *      + 14 字 literal pool；1863 个解码词里 1691 个是可达指令。
 *
 * open：
 *   · K=7..10（JS 抽象关系比较慢路径）：helper 实参是 (右,左)，与快路径 (左-右) 方向相反，
 *     只证到 K∈{7,8} 取 (cmp!=0)、K∈{9,10} 取 (cmp==1)，尚未定到单个算子名。
 *   · K=12/13 的极性：e2430 的 cmp r9,#12 之后紧跟 vcmp（覆盖标志），死代码化，未能证明哪个是 ==。
 *   · K=11 的算子名（按 JS_GetProperty + F_JS_ToString 判为属性存在性 / in），GML 侧无对应语法确认。
 *   · 17 个类型组合里只有 0x00（double,double，核 e2d94..e2e5c）与 0x66（指针,指针，核 e3228..e326c）
 *     逐核核对了六个算子的符号条件；其余 15 个组合只钉到"差值怎么算 + 六路表落点"，六个核内的
 *     movXX 条件未逐条核对（它们与 0x00/0x66 的核同构，但未证）。
 *   · 15 路 RValue-tag 表（e2364/e22fc）里 tag 0..13 各分支的语义（哪些 tag 可直接比较、
 *     哪些要 JS_ToString/ToString 转换）未逐个展开。
 *   · e26f0-e2888 的"类型字节归一化"改写规则（|2/|3/|6/|48/|96/|240、and #0xF0 清低半字节）
 *     只证到它把实际 tag 折算成紧凑编码后回跳 e2224/e2268，未证每条规则的动机。
 *   · 常量 1e-05 是否可被游戏运行时改写（它在 .data，GOT 间接引用）未验证。
 */

/* ── 序言：r10 = sp（值栈顶，实参 2）、r8 = exec（实参 4）、r6 = GOT 锚（e203c 后 = 0x3f1c58） */
/* ── 栈帧 68 字节：sp+0x00/sp+0x10/sp+0x20 三个 16 字节临时 RValue，sp+0x30 是结果用的临时 RValue */
/* @0xe2014 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* ── K = (arg>>8)&0xF —— 比较算子号；1..6 = <,<=,==,!=,>=,>（见 e24bc 与 e3208 两张六路表） */
/* @0xe2018 ubfx r9, r0, #0x8, #0x4 */
/* @0xe201c sub r11, r9, #7 */
/* ── GOT 锚：字面量 e2ffc = 0x30fc14 → r6 = 0x3f1c58 */
/* @0xe2020 ldr r6, [pc, #0xfd4] */
/* @0xe2024 sub sp, sp, #68 */
/* @0xe2028 mov r10, r1 */
/* @0xe202c uxtb r11, r11 */
/* ── r8 = exec：只供后面 VMError / JSThrow 当第 1 实参；e226c 起 r8 改存新 sp */
/* @0xe2030 mov r8, r3 */
/* ── 分派 1：r11 = (K-7) & 0xFF；r11 > 3（K∉[7,10]）→ e215c */
/* @0xe2034 cmp r11, #3 */
/* ── T = arg>>16；e2054 uxtb → 0..255 = (左类型<<4) | 右类型 */
/* @0xe2038 lsr r12, r0, #16 */
/* @0xe203c add r6, pc, r6 */
/* @0xe2040 bhi 0xe215c <_Z5DoSetjPhPKhP6VMExec+0x148> */
/* ── K∈{8,9} → e2050（带类型极性）；K∈{7,10} → e21d4 */
/* @0xe2044 sub r9, r9, #8 */
/* @0xe2048 cmp r9, #1 */
/* @0xe204c bhi 0xe21d4 <_Z5DoSetjPhPKhP6VMExec+0x1c0> */
/* ── 右操作数装箱：boxType(&tmp@sp+0x10, T&0xF, sp) */
/* @0xe2050 add r6, sp, #16 */
/* @0xe2054 uxtb r4, r12 */
/* @0xe2058 mov r2, r1 */
/* @0xe205c and r1, r4, #15 */
/* @0xe2060 mov r0, r6 */
/* ── 左操作数装箱：dst = sp+0x20 */
/* @0xe2064 add r7, sp, #32 */
/* ── bl boxType(RValue& dst, eVM_Type t, uchar* sp) → 返回消耗后的 sp（本函数共 10 个调用点） */
/* @0xe2068 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe206c lsr r1, r4, #4 */
/* @0xe2070 mov r2, r0 */
/* @0xe2074 mov r0, r7 */
/* @0xe2078 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe207c mov r3, #0 */
/* @0xe2080 mov r8, r0 */
/* ── 未解析引用检查：tag & 0x00FFFFFF == 0x00FFFFFF → 抛 ReferenceError（e2544） */
/* @0xe2084 ldr r2, [sp, #0x1c] */
/* @0xe2088 mvn r12, #-16777216 */
/* @0xe208c and r2, r2, r12 */
/* @0xe2090 cmp r2, r12 */
/* @0xe2094 beq 0xe2544 <_Z5DoSetjPhPKhP6VMExec+0x530> */
/* @0xe2098 ldr r2, [sp, #0x2c] */
/* @0xe209c bic r2, r2, #-16777216 */
/* @0xe20a0 cmp r2, r12 */
/* @0xe20a4 beq 0xe24dc <_Z5DoSetjPhPKhP6VMExec+0x4c8> */
/* ── abstractRelationalComparison(&res@sp+0x30, 右, 左, false) —— 注意实参顺序是 (右,左) */
/* @0xe20a8 add r0, sp, #48 */
/* @0xe20ac mov r1, r6 */
/* @0xe20b0 mov r2, r7 */
/* @0xe20b4 str r12, [sp, #0x3c] */
/* @0xe20b8 mov r4, #0 */
/* @0xe20bc mov r12, #0 */
/* @0xe20c0 mov r5, #0 */
/* @0xe20c4 str r12, [sp, #0x38] */
/* @0xe20c8 strd r4, r5, [sp, #48] */
/* @0xe20cc bl 0x25a518 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b> */
/* ── 返回非 0（已抛异常）→ e247c 直接出栈返回 */
/* @0xe20d0 cmp r0, #0 */
/* @0xe20d4 bne 0xe247c <_Z5DoSetjPhPKhP6VMExec+0x468> */
/* ── K-7∈{0,1}（K=7,8）→ e2458：结果 = (cmp != 0)；K-7∈{2,3}（K=9,10）走 e20e8-e2100：结果 = (cmp == 1) */
/* @0xe20d8 cmp r11, #1 */
/* @0xe20dc ldr r3, [sp, #0x3c] */
/* @0xe20e0 sub r4, r8, #4 */
/* @0xe20e4 bls 0xe2458 <_Z5DoSetjPhPKhP6VMExec+0x444> */
/* @0xe20e8 cmp r3, #5 */
/* @0xe20ec beq 0xe2104 <_Z5DoSetjPhPKhP6VMExec+0xf0> */
/* @0xe20f0 vmov.f64 d6, #1.000000e+00 */
/* @0xe20f4 vldr d7, [sp, #48] */
/* @0xe20f8 vcmp.f64 d7, d6 */
/* @0xe20fc vmrs APSR_nzcv, fpscr */
/* @0xe2100 bne 0xe2470 <_Z5DoSetjPhPKhP6VMExec+0x45c> */
/* ── 写 4 字节结果 0；e20e0 已算出 r4 = r8-4 = 新栈顶，出口 r0 = r4（e2150） */
/* @0xe2104 mov r3, #0 */
/* @0xe2108 str r3, [r8, #-0x4] */
/* ── 清理：临时 RValue 的 tag 若 ∈{1,2,3,4}（判据 (tag-1)&0x00FFFFFC==0）才调 FREE_RValue__Pre */
/* @0xe210c ldr r3, [sp, #0x1c] */
/* @0xe2110 sub r3, r3, #1 */
/* @0xe2114 bic r3, r3, #-16777216 */
/* @0xe2118 bic r3, r3, #3 */
/* @0xe211c cmp r3, #0 */
/* @0xe2120 beq 0xe2564 <_Z5DoSetjPhPKhP6VMExec+0x550> */
/* @0xe2124 ldr r1, [sp, #0x2c] */
/* @0xe2128 mov r3, #0 */
/* @0xe212c str r3, [sp, #0x18] */
/* @0xe2130 mov r2, #5 */
/* @0xe2134 sub r1, r1, #1 */
/* @0xe2138 str r3, [sp, #0x10] */
/* @0xe213c bic r3, r1, #-16777216 */
/* @0xe2140 str r2, [sp, #0x1c] */
/* @0xe2144 bic r3, r3, #3 */
/* @0xe2148 cmp r3, #0 */
/* @0xe214c beq 0xe2558 <_Z5DoSetjPhPKhP6VMExec+0x544> */
/* ── 公共出口：r0 = r4（结果指针），sp += 68，pop {r4..r11, pc} */
/* @0xe2150 mov r0, r4 */
/* @0xe2154 add sp, sp, #68 */
/* @0xe2158 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 分派 2：K-12∈{0,1} → e23bc（抽象相等）；K-14∈{0,1} → e2570（严格相等）；K==11 → e2684 */
/* @0xe215c sub r3, r9, #12 */
/* @0xe2160 cmp r3, #1 */
/* @0xe2164 bls 0xe23bc <_Z5DoSetjPhPKhP6VMExec+0x3a8> */
/* @0xe2168 sub r3, r9, #14 */
/* @0xe216c cmp r3, #1 */
/* @0xe2170 bls 0xe2570 <_Z5DoSetjPhPKhP6VMExec+0x55c> */
/* @0xe2174 cmp r9, #11 */
/* @0xe2178 beq 0xe2684 <_Z5DoSetjPhPKhP6VMExec+0x670> */
/* ── K∈[0,6]：先把两个临时 RValue 置成 {0,0,0,0x00FFFFFF} 占位，再进类型分派 */
/* @0xe217c uxtb r11, r12 */
/* @0xe2180 mov r4, #0 */
/* @0xe2184 and r3, r11, #15 */
/* @0xe2188 mov r5, #0 */
/* @0xe218c mov r1, #0 */
/* @0xe2190 mvn r2, #-16777216 */
/* @0xe2194 strd r4, r5, [sp, #32] */
/* @0xe2198 strd r4, r5, [sp, #48] */
/* @0xe219c str r1, [sp, #0x28] */
/* @0xe21a0 str r1, [sp, #0x38] */
/* @0xe21a4 str r2, [sp, #0x2c] */
/* @0xe21a8 str r2, [sp, #0x3c] */
/* ── 分派 3：按 T&0xF（栈顶/右操作数类型）8 路表 → e21b8..0xe21d0 */
/* @0xe21ac cmp r3, #6 */
/* @0xe21b0 addls pc, pc, r3, lsl #2 */
/* @0xe21b4 b 0xe3d28 <_Z5DoSetjPhPKhP6VMExec+0x1d14> */
/* ── 表项 = e23ac（右类型0，8B） e23a4（1，4B） e23a4（2，4B） e23ac（3，8B） e23a4（4，4B） */
/* @0xe21b8 b 0xe23ac <_Z5DoSetjPhPKhP6VMExec+0x398> */
/* @0xe21bc b 0xe23a4 <_Z5DoSetjPhPKhP6VMExec+0x390> */
/* @0xe21c0 b 0xe23a4 <_Z5DoSetjPhPKhP6VMExec+0x390> */
/* @0xe21c4 b 0xe23ac <_Z5DoSetjPhPKhP6VMExec+0x398> */
/* @0xe21c8 b 0xe23a4 <_Z5DoSetjPhPKhP6VMExec+0x390> */
/* ── 表项 = e2340（5，16B RValue） / e220c（6，指针）；>6 → e21b4 → e3d28（按 0 字节算） */
/* @0xe21cc b 0xe2340 <_Z5DoSetjPhPKhP6VMExec+0x32c> */
/* @0xe21d0 b 0xe220c <_Z5DoSetjPhPKhP6VMExec+0x1f8> */
/* ── K∈{7,10} 泛型路径：boxType ×2，然后进 e2084 的占位/未解析检查 */
/* @0xe21d4 add r7, sp, #32 */
/* @0xe21d8 uxtb r4, r12 */
/* @0xe21dc mov r2, r1 */
/* @0xe21e0 and r1, r4, #15 */
/* @0xe21e4 mov r0, r7 */
/* @0xe21e8 add r6, sp, #16 */
/* @0xe21ec bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe21f0 lsr r1, r4, #4 */
/* @0xe21f4 mov r2, r0 */
/* @0xe21f8 mov r0, r6 */
/* @0xe21fc bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe2200 mov r3, #1 */
/* @0xe2204 mov r8, r0 */
/* @0xe2208 b 0xe2084 <_Z5DoSetjPhPKhP6VMExec+0x70> */
/* ── 右操作数 = 指针（4B）：搬进 sp+0x20 并置 tag=1，再统一进 e2224 */
/* @0xe220c mov r4, r10 */
/* @0xe2210 add r10, sp, #64 */
/* @0xe2214 ldr r3, [r4], #4 */
/* @0xe2218 mov r2, #1 */
/* @0xe221c str r2, [sp, #0x2c] */
/* @0xe2220 str r3, [r10, #-0x20]! */
/* ── 分派 4：按 T>>4（左操作数类型）8 路表；r7 = 左操作数起点 */
/* @0xe2224 asr r3, r11, #4 */
/* @0xe2228 cmp r3, #6 */
/* @0xe222c addls pc, pc, r3, lsl #2 */
/* @0xe2230 b 0xe3d20 <_Z5DoSetjPhPKhP6VMExec+0x1d0c> */
/* ── 表项 = e23b4（左类型0，+8B） e2338（1，+4B） e2338（2） e23b4（3，+8B） e2338（4） e22d4（5，16B） e2250（6） */
/* @0xe2234 b 0xe23b4 <_Z5DoSetjPhPKhP6VMExec+0x3a0> */
/* @0xe2238 b 0xe2338 <_Z5DoSetjPhPKhP6VMExec+0x324> */
/* @0xe223c b 0xe2338 <_Z5DoSetjPhPKhP6VMExec+0x324> */
/* @0xe2240 b 0xe23b4 <_Z5DoSetjPhPKhP6VMExec+0x3a0> */
/* @0xe2244 b 0xe2338 <_Z5DoSetjPhPKhP6VMExec+0x324> */
/* @0xe2248 b 0xe22d4 <_Z5DoSetjPhPKhP6VMExec+0x2c0> */
/* @0xe224c b 0xe2250 <_Z5DoSetjPhPKhP6VMExec+0x23c> */
/* @0xe2250 mov r7, r4 */
/* @0xe2254 add r4, sp, #64 */
/* @0xe2258 ldr r3, [r7], #4 */
/* @0xe225c mov r2, #1 */
/* @0xe2260 str r2, [sp, #0x3c] */
/* @0xe2264 str r3, [r4, #-0x10]! */
/* ── 分派 5：按 T 全字节的 17 个组合（见下）；e226c 先算 r8 = r7-4 = 新 sp（结果 4 字节） */
/* @0xe2268 cmp r11, #48 */
/* @0xe226c sub r8, r7, #4 */
/* ── 0x30 → e3524；<48 走 e2488 链（0x00/0x02/0x04/0x20/0x22/0x23/0x24）；0x44 → e37b4 */
/* @0xe2270 beq 0xe3524 <_Z5DoSetjPhPKhP6VMExec+0x1510> */
/* @0xe2274 bls 0xe2488 <_Z5DoSetjPhPKhP6VMExec+0x474> */
/* @0xe2278 cmp r11, #68 */
/* @0xe227c beq 0xe37b4 <_Z5DoSetjPhPKhP6VMExec+0x17a0> */
/* @0xe2280 bls 0xe24f4 <_Z5DoSetjPhPKhP6VMExec+0x4e0> */
/* @0xe2284 cmp r11, #100 */
/* @0xe2288 beq 0xe3650 <_Z5DoSetjPhPKhP6VMExec+0x163c> */
/* @0xe228c bls 0xe2798 <_Z5DoSetjPhPKhP6VMExec+0x784> */
/* @0xe2290 cmp r11, #102 */
/* @0xe2294 beq 0xe31c0 <_Z5DoSetjPhPKhP6VMExec+0x11ac> */
/* ── 0x64 → e3650；0x66 → e31c0；0xFF → e22a0；其余 → e33c0（未支持组合） */
/* @0xe2298 cmp r11, #255 */
/* @0xe229c bne 0xe33c0 <_Z5DoSetjPhPKhP6VMExec+0x13ac> */
/* @0xe22a0 ldr r2, [r4] */
/* @0xe22a4 sub r9, r9, #1 */
/* @0xe22a8 ldr r3, [r10] */
/* @0xe22ac rsb r3, r3, r2 */
/* @0xe22b0 cmp r9, #5 */
/* @0xe22b4 addls pc, pc, r9, lsl #2 */
/* @0xe22b8 b 0xe3bf4 <_Z5DoSetjPhPKhP6VMExec+0x1be0> */
/* @0xe22bc b 0xe3098 <_Z5DoSetjPhPKhP6VMExec+0x1084> */
/* @0xe22c0 b 0xe3070 <_Z5DoSetjPhPKhP6VMExec+0x105c> */
/* @0xe22c4 b 0xe3034 <_Z5DoSetjPhPKhP6VMExec+0x1020> */
/* @0xe22c8 b 0xe2fc0 <_Z5DoSetjPhPKhP6VMExec+0xfac> */
/* @0xe22cc b 0xe2f94 <_Z5DoSetjPhPKhP6VMExec+0xf80> */
/* @0xe22d0 b 0xe2f6c <_Z5DoSetjPhPKhP6VMExec+0xf58> */
/* @0xe22d4 ldr r3, [r4, #0xc] */
/* @0xe22d8 add r5, sp, #48 */
/* @0xe22dc ldr r0, [r4] */
/* @0xe22e0 ldr r1, [r4, #0x4] */
/* @0xe22e4 mov r12, r5 */
/* @0xe22e8 ldr r2, [r4, #0x8] */
/* @0xe22ec stm r12!, {r0, r1, r2, r3} */
/* @0xe22f0 ldr r3, [sp, #0x3c] */
/* @0xe22f4 cmp r3, #13 */
/* @0xe22f8 addls pc, pc, r3, lsl #2 */
/* @0xe22fc b 0xe28b8 <_Z5DoSetjPhPKhP6VMExec+0x8a4> */
/* @0xe2300 b 0xe2884 <_Z5DoSetjPhPKhP6VMExec+0x870> */
/* @0xe2304 b 0xe2878 <_Z5DoSetjPhPKhP6VMExec+0x864> */
/* @0xe2308 b 0xe2704 <_Z5DoSetjPhPKhP6VMExec+0x6f0> */
/* @0xe230c b 0xe2704 <_Z5DoSetjPhPKhP6VMExec+0x6f0> */
/* @0xe2310 b 0xe28b8 <_Z5DoSetjPhPKhP6VMExec+0x8a4> */
/* @0xe2314 b 0xe285c <_Z5DoSetjPhPKhP6VMExec+0x848> */
/* @0xe2318 b 0xe2704 <_Z5DoSetjPhPKhP6VMExec+0x6f0> */
/* @0xe231c b 0xe2704 <_Z5DoSetjPhPKhP6VMExec+0x6f0> */
/* @0xe2320 b 0xe28b8 <_Z5DoSetjPhPKhP6VMExec+0x8a4> */
/* @0xe2324 b 0xe28b8 <_Z5DoSetjPhPKhP6VMExec+0x8a4> */
/* @0xe2328 b 0xe286c <_Z5DoSetjPhPKhP6VMExec+0x858> */
/* @0xe232c b 0xe28b8 <_Z5DoSetjPhPKhP6VMExec+0x8a4> */
/* @0xe2330 b 0xe28b8 <_Z5DoSetjPhPKhP6VMExec+0x8a4> */
/* @0xe2334 b 0xe2884 <_Z5DoSetjPhPKhP6VMExec+0x870> */
/* @0xe2338 add r7, r4, #4 */
/* @0xe233c b 0xe2268 <_Z5DoSetjPhPKhP6VMExec+0x254> */
/* ── 右操作数 = 16B RValue：整块搬到 sp+0x20，再按搬来的 tag 走 15 路表 e2364 */
/* @0xe2340 ldr r3, [r10, #0xc] */
/* @0xe2344 add r7, sp, #32 */
/* @0xe2348 ldr r0, [r10] */
/* @0xe234c ldr r1, [r10, #0x4] */
/* @0xe2350 mov r4, r7 */
/* @0xe2354 ldr r2, [r10, #0x8] */
/* @0xe2358 stm r4!, {r0, r1, r2, r3} */
/* @0xe235c ldr r3, [sp, #0x2c] */
/* @0xe2360 cmp r3, #13 */
/* @0xe2364 addls pc, pc, r3, lsl #2 */
/* ── tag 表项 = e28a0(0) e2864(1) e2850(2) e26f0(3) e26f0(4) e28a0(5) e283c(6) e26f0(7) e26f0(8) … */
/* @0xe2368 b 0xe28a0 <_Z5DoSetjPhPKhP6VMExec+0x88c> */
/* @0xe236c b 0xe2864 <_Z5DoSetjPhPKhP6VMExec+0x850> */
/* @0xe2370 b 0xe2850 <_Z5DoSetjPhPKhP6VMExec+0x83c> */
/* @0xe2374 b 0xe26f0 <_Z5DoSetjPhPKhP6VMExec+0x6dc> */
/* @0xe2378 b 0xe26f0 <_Z5DoSetjPhPKhP6VMExec+0x6dc> */
/* @0xe237c b 0xe28a0 <_Z5DoSetjPhPKhP6VMExec+0x88c> */
/* @0xe2380 b 0xe283c <_Z5DoSetjPhPKhP6VMExec+0x828> */
/* @0xe2384 b 0xe26f0 <_Z5DoSetjPhPKhP6VMExec+0x6dc> */
/* @0xe2388 b 0xe26f0 <_Z5DoSetjPhPKhP6VMExec+0x6dc> */
/* @0xe238c b 0xe28a0 <_Z5DoSetjPhPKhP6VMExec+0x88c> */
/* @0xe2390 b 0xe28a0 <_Z5DoSetjPhPKhP6VMExec+0x88c> */
/* @0xe2394 b 0xe2844 <_Z5DoSetjPhPKhP6VMExec+0x830> */
/* @0xe2398 b 0xe28a0 <_Z5DoSetjPhPKhP6VMExec+0x88c> */
/* @0xe239c b 0xe28a0 <_Z5DoSetjPhPKhP6VMExec+0x88c> */
/* @0xe23a0 b 0xe2864 <_Z5DoSetjPhPKhP6VMExec+0x850> */
/* @0xe23a4 add r4, r10, #4 */
/* @0xe23a8 b 0xe2224 <_Z5DoSetjPhPKhP6VMExec+0x210> */
/* @0xe23ac add r4, r10, #8 */
/* @0xe23b0 b 0xe2224 <_Z5DoSetjPhPKhP6VMExec+0x210> */
/* @0xe23b4 add r7, r4, #8 */
/* @0xe23b8 b 0xe2268 <_Z5DoSetjPhPKhP6VMExec+0x254> */
/* @0xe23bc add r7, sp, #32 */
/* @0xe23c0 uxtb r4, r12 */
/* @0xe23c4 mov r2, r1 */
/* @0xe23c8 and r1, r4, #15 */
/* @0xe23cc mov r0, r7 */
/* @0xe23d0 add r6, sp, #16 */
/* @0xe23d4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe23d8 lsr r1, r4, #4 */
/* @0xe23dc mov r2, r0 */
/* @0xe23e0 mov r0, r6 */
/* @0xe23e4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe23e8 ldr r2, [sp, #0x1c] */
/* @0xe23ec mvn r3, #-16777216 */
/* @0xe23f0 and r2, r2, r3 */
/* @0xe23f4 cmp r2, r3 */
/* @0xe23f8 mov r8, r0 */
/* @0xe23fc beq 0xe3b5c <_Z5DoSetjPhPKhP6VMExec+0x1b48> */
/* @0xe2400 ldr r2, [sp, #0x2c] */
/* @0xe2404 bic r2, r2, #-16777216 */
/* @0xe2408 cmp r2, r3 */
/* @0xe240c beq 0xe2814 <_Z5DoSetjPhPKhP6VMExec+0x800> */
/* @0xe2410 add r0, sp, #48 */
/* @0xe2414 mov r1, r6 */
/* @0xe2418 mov r2, r7 */
/* @0xe241c mov r3, #5 */
/* @0xe2420 str r3, [sp, #0x3c] */
/* @0xe2424 bl 0x25a814 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_> */
/* @0xe2428 cmp r0, #0 */
/* @0xe242c bne 0xe247c <_Z5DoSetjPhPKhP6VMExec+0x468> */
/* @0xe2430 cmp r9, #12 */
/* @0xe2434 vldr d7, [sp, #48] */
/* @0xe2438 sub r4, r8, #4 */
/* @0xe243c vcmp.f64 d7, #0 */
/* @0xe2440 beq 0xe3bc0 <_Z5DoSetjPhPKhP6VMExec+0x1bac> */
/* @0xe2444 vmrs APSR_nzcv, fpscr */
/* @0xe2448 movne r3, #0 */
/* @0xe244c moveq r3, #1 */
/* @0xe2450 str r3, [r8, #-0x4] */
/* @0xe2454 b 0xe210c <_Z5DoSetjPhPKhP6VMExec+0xf8> */
/* @0xe2458 cmp r3, #5 */
/* @0xe245c beq 0xe2104 <_Z5DoSetjPhPKhP6VMExec+0xf0> */
/* @0xe2460 vldr d7, [sp, #48] */
/* @0xe2464 vcmp.f64 d7, #0 */
/* @0xe2468 vmrs APSR_nzcv, fpscr */
/* @0xe246c beq 0xe2104 <_Z5DoSetjPhPKhP6VMExec+0xf0> */
/* @0xe2470 mov r3, #1 */
/* @0xe2474 str r3, [r8, #-0x4] */
/* @0xe2478 b 0xe210c <_Z5DoSetjPhPKhP6VMExec+0xf8> */
/* @0xe247c mov r0, r8 */
/* @0xe2480 add sp, sp, #68 */
/* @0xe2484 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe2488 cmp r11, #4 */
/* @0xe248c beq 0xe3274 <_Z5DoSetjPhPKhP6VMExec+0x1260> */
/* @0xe2490 bhi 0xe2638 <_Z5DoSetjPhPKhP6VMExec+0x624> */
/* @0xe2494 cmp r11, #2 */
/* @0xe2498 beq 0xe27dc <_Z5DoSetjPhPKhP6VMExec+0x7c8> */
/* @0xe249c bhi 0xe33f8 <_Z5DoSetjPhPKhP6VMExec+0x13e4> */
/* @0xe24a0 cmp r11, #0 */
/* @0xe24a4 bne 0xe33c0 <_Z5DoSetjPhPKhP6VMExec+0x13ac> */
/* ── 组合 0x00（double,double）：d7 = 左 - 右（e24b0/e24b4），再按 K-1 六路表 e24bc */
/* @0xe24a8 sub r9, r9, #1 */
/* @0xe24ac vldr d6, [r4] */
/* @0xe24b0 vldr d7, [r10] */
/* @0xe24b4 vsub.f64 d7, d6, d7 */
/* @0xe24b8 cmp r9, #5 */
/* @0xe24bc addls pc, pc, r9, lsl #2 */
/* @0xe24c0 b 0xe3c74 <_Z5DoSetjPhPKhP6VMExec+0x1c60> */
/* ── 六路表 K=1..6 → e2e40 e2e20 e2dec e2db8 e2d94 e29f4；默认 e3c74（把 [r7-4] 布尔化） */
/* @0xe24c4 b 0xe2e40 <_Z5DoSetjPhPKhP6VMExec+0xe2c> */
/* @0xe24c8 b 0xe2e20 <_Z5DoSetjPhPKhP6VMExec+0xe0c> */
/* @0xe24cc b 0xe2dec <_Z5DoSetjPhPKhP6VMExec+0xdd8> */
/* @0xe24d0 b 0xe2db8 <_Z5DoSetjPhPKhP6VMExec+0xda4> */
/* @0xe24d4 b 0xe2d94 <_Z5DoSetjPhPKhP6VMExec+0xd80> */
/* @0xe24d8 b 0xe29f4 <_Z5DoSetjPhPKhP6VMExec+0x9e0> */
/* ── 右操作数 tag = 0x00FFFFFF → JSThrowReferenceError */
/* @0xe24dc ldr r0, [pc, #0xb1c] */
/* @0xe24e0 add r0, pc, r0 */
/* @0xe24e4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe24e8 mov r0, r8 */
/* @0xe24ec add sp, sp, #68 */
/* @0xe24f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe24f4 cmp r11, #51 */
/* @0xe24f8 beq 0xe3908 <_Z5DoSetjPhPKhP6VMExec+0x18f4> */
/* @0xe24fc bls 0xe2758 <_Z5DoSetjPhPKhP6VMExec+0x744> */
/* ── 组合 0x40（右 f32 / 左 double）：d7 = 左 - 右（e2508-e2518） */
/* @0xe2500 cmp r11, #64 */
/* @0xe2504 bne 0xe33b8 <_Z5DoSetjPhPKhP6VMExec+0x13a4> */
/* @0xe2508 vldr s14, [r4] */
/* @0xe250c vcvt.f64.s32 d7, s14 */
/* @0xe2510 vldr d6, [r10] */
/* @0xe2514 sub r9, r9, #1 */
/* @0xe2518 vsub.f64 d7, d7, d6 */
/* @0xe251c vcvt.s32.f64 s12, d7 */
/* @0xe2520 cmp r9, #5 */
/* @0xe2524 addls pc, pc, r9, lsl #2 */
/* @0xe2528 b 0xe3c84 <_Z5DoSetjPhPKhP6VMExec+0x1c70> */
/* @0xe252c b 0xe2f44 <_Z5DoSetjPhPKhP6VMExec+0xf30> */
/* @0xe2530 b 0xe2f20 <_Z5DoSetjPhPKhP6VMExec+0xf0c> */
/* @0xe2534 b 0xe2ee8 <_Z5DoSetjPhPKhP6VMExec+0xed4> */
/* @0xe2538 b 0xe2eb0 <_Z5DoSetjPhPKhP6VMExec+0xe9c> */
/* @0xe253c b 0xe2e88 <_Z5DoSetjPhPKhP6VMExec+0xe74> */
/* @0xe2540 b 0xe2e64 <_Z5DoSetjPhPKhP6VMExec+0xe50> */
/* ── 左操作数 tag = 0x00FFFFFF → JSThrowReferenceError */
/* @0xe2544 ldr r0, [pc, #0xab8] */
/* @0xe2548 add r0, pc, r0 */
/* @0xe254c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe2550 mov r0, r8 */
/* @0xe2554 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* ── tag∈{1,2,3,4} 才释放（左临时 RValue） */
/* @0xe2558 mov r0, r7 */
/* @0xe255c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe2560 b 0xe2150 <_Z5DoSetjPhPKhP6VMExec+0x13c> */
/* ── tag∈{1,2,3,4} 才释放（右临时 RValue） */
/* @0xe2564 mov r0, r6 */
/* @0xe2568 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe256c b 0xe2124 <_Z5DoSetjPhPKhP6VMExec+0x110> */
/* ── K∈{14,15}：boxType(右→sp+0x30)、boxType(左→sp+0x20) */
/* @0xe2570 add r5, sp, #48 */
/* @0xe2574 uxtb r4, r12 */
/* @0xe2578 mov r2, r1 */
/* @0xe257c and r1, r4, #15 */
/* @0xe2580 mov r0, r5 */
/* @0xe2584 add r7, sp, #32 */
/* @0xe2588 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe258c lsr r1, r4, #4 */
/* @0xe2590 mov r2, r0 */
/* @0xe2594 mov r0, r7 */
/* @0xe2598 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe259c ldr r2, [sp, #0x2c] */
/* @0xe25a0 mvn r3, #-16777216 */
/* @0xe25a4 and r2, r2, r3 */
/* @0xe25a8 cmp r2, r3 */
/* @0xe25ac mov r4, r0 */
/* @0xe25b0 beq 0xe2828 <_Z5DoSetjPhPKhP6VMExec+0x814> */
/* @0xe25b4 ldr r2, [sp, #0x3c] */
/* @0xe25b8 bic r2, r2, #-16777216 */
/* @0xe25bc cmp r2, r3 */
/* @0xe25c0 beq 0xe3a60 <_Z5DoSetjPhPKhP6VMExec+0x1a4c> */
/* @0xe25c4 mov r0, r7 */
/* @0xe25c8 mov r1, r5 */
/* ── abstractStrictEqualityComparison(左, 右) → int */
/* @0xe25cc bl 0x240a08 <_Z42JS_Global_abstractStrictEqualityComparisonR6RValueS0_> */
/* ── K==14 不取反（===）；K==15 eorne r0,r0,#1（!==） */
/* @0xe25d0 cmp r9, #14 */
/* @0xe25d4 sub r8, r4, #4 */
/* @0xe25d8 eorne r0, r0, #1 */
/* @0xe25dc uxtbne r0, r0 */
/* ── 结果落 [r4-4]；e25d4 sub r8,r4,#4 → 返回 r8 */
/* @0xe25e0 str r0, [r4, #-0x4] */
/* @0xe25e4 ldr r3, [sp, #0x2c] */
/* @0xe25e8 sub r3, r3, #1 */
/* @0xe25ec bic r3, r3, #-16777216 */
/* @0xe25f0 bic r3, r3, #3 */
/* @0xe25f4 cmp r3, #0 */
/* @0xe25f8 beq 0xe3b50 <_Z5DoSetjPhPKhP6VMExec+0x1b3c> */
/* @0xe25fc ldr r1, [sp, #0x3c] */
/* @0xe2600 mov r3, #0 */
/* @0xe2604 str r3, [sp, #0x28] */
/* @0xe2608 mov r2, #5 */
/* @0xe260c sub r1, r1, #1 */
/* @0xe2610 str r3, [sp, #0x20] */
/* @0xe2614 bic r3, r1, #-16777216 */
/* @0xe2618 str r2, [sp, #0x2c] */
/* @0xe261c bic r3, r3, #3 */
/* @0xe2620 cmp r3, #0 */
/* @0xe2624 bne 0xe247c <_Z5DoSetjPhPKhP6VMExec+0x468> */
/* @0xe2628 mov r0, r5 */
/* @0xe262c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe2630 mov r0, r8 */
/* @0xe2634 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* ── 0x20/0x21 → e2718；0x22 → e37b4；0x23 → e264c */
/* @0xe2638 cmp r11, #34 */
/* @0xe263c beq 0xe37b4 <_Z5DoSetjPhPKhP6VMExec+0x17a0> */
/* @0xe2640 bls 0xe2718 <_Z5DoSetjPhPKhP6VMExec+0x704> */
/* @0xe2644 cmp r11, #35 */
/* @0xe2648 bne 0xe37ac <_Z5DoSetjPhPKhP6VMExec+0x1798> */
/* ── 组合 0x23（右 int32 / 左 int64）：64 位差 rsbs + sbc */
/* @0xe264c ldr r12, [r4] */
/* @0xe2650 sub r9, r9, #1 */
/* @0xe2654 ldrd r2, r3, [r10] */
/* @0xe2658 rsbs r0, r2, r12 */
/* @0xe265c rsc r1, r3, r12, asr #31 */
/* @0xe2660 cmp r9, #5 */
/* @0xe2664 addls pc, pc, r9, lsl #2 */
/* @0xe2668 b 0xe3c14 <_Z5DoSetjPhPKhP6VMExec+0x1c00> */
/* @0xe266c b 0xe2c1c <_Z5DoSetjPhPKhP6VMExec+0xc08> */
/* @0xe2670 b 0xe2bf4 <_Z5DoSetjPhPKhP6VMExec+0xbe0> */
/* @0xe2674 b 0xe2bb8 <_Z5DoSetjPhPKhP6VMExec+0xba4> */
/* @0xe2678 b 0xe2b7c <_Z5DoSetjPhPKhP6VMExec+0xb68> */
/* @0xe267c b 0xe2c70 <_Z5DoSetjPhPKhP6VMExec+0xc5c> */
/* @0xe2680 b 0xe2c48 <_Z5DoSetjPhPKhP6VMExec+0xc34> */
/* ── K=11：boxType(右→sp+0x10)、boxType(左→sp+0)；即「左 in 右」的属性存在性测试 */
/* @0xe2684 add r6, sp, #16 */
/* @0xe2688 uxtb r4, r12 */
/* @0xe268c mov r2, r1 */
/* @0xe2690 and r1, r4, #15 */
/* @0xe2694 mov r0, r6 */
/* @0xe2698 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe269c lsr r1, r4, #4 */
/* @0xe26a0 mvn r4, #-16777216 */
/* @0xe26a4 mov r2, r0 */
/* @0xe26a8 mov r0, sp */
/* @0xe26ac bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* ── 左操作数 tag = 0x00FFFFFF → ReferenceError（e288c） */
/* @0xe26b0 ldr r3, [sp, #0xc] */
/* @0xe26b4 and r3, r3, r4 */
/* @0xe26b8 cmp r3, r4 */
/* @0xe26bc mov r8, r0 */
/* @0xe26c0 beq 0xe288c <_Z5DoSetjPhPKhP6VMExec+0x878> */
/* ── 右操作数 tag == 0x00FFFFFF → e3bd4；tag != 6（非对象）→ JSThrowTypeError（e26e4） */
/* @0xe26c4 ldr r3, [sp, #0x1c] */
/* @0xe26c8 bic r3, r3, #-16777216 */
/* @0xe26cc cmp r3, r4 */
/* @0xe26d0 beq 0xe3bd4 <_Z5DoSetjPhPKhP6VMExec+0x1bc0> */
/* @0xe26d4 cmp r3, #6 */
/* @0xe26d8 beq 0xe3a74 <_Z5DoSetjPhPKhP6VMExec+0x1a60> */
/* @0xe26dc ldr r0, [pc, #0x924] */
/* @0xe26e0 add r0, pc, r0 */
/* @0xe26e4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe26e8 mov r0, r8 */
/* @0xe26ec b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* ── 类型字节归一化：把 RValue 实际 tag 折成紧凑编码（orr #2 / #3 / #6 / #48 / #96 / #240） */
/* @0xe26f0 and r12, r12, #240 */
/* @0xe26f4 orr r11, r12, #2 */
/* @0xe26f8 add r4, r10, #16 */
/* @0xe26fc mov r10, r7 */
/* @0xe2700 b 0xe2224 <_Z5DoSetjPhPKhP6VMExec+0x210> */
/* @0xe2704 and r11, r11, #15 */
/* @0xe2708 orr r11, r11, #32 */
/* @0xe270c add r7, r4, #16 */
/* @0xe2710 mov r4, r5 */
/* @0xe2714 b 0xe2268 <_Z5DoSetjPhPKhP6VMExec+0x254> */
/* ── 组合 0x20（右 f32 / 左 double）：d7 = 左 - 右，K-1 六路表 e2738 */
/* @0xe2718 cmp r11, #32 */
/* @0xe271c bne 0xe33c0 <_Z5DoSetjPhPKhP6VMExec+0x13ac> */
/* @0xe2720 vldr s12, [r4] */
/* @0xe2724 vcvt.f64.s32 d6, s12 */
/* @0xe2728 sub r9, r9, #1 */
/* @0xe272c vldr d7, [r10] */
/* @0xe2730 vsub.f64 d7, d6, d7 */
/* @0xe2734 cmp r9, #5 */
/* @0xe2738 addls pc, pc, r9, lsl #2 */
/* @0xe273c b 0xe3ca4 <_Z5DoSetjPhPKhP6VMExec+0x1c90> */
/* @0xe2740 b 0xe29d0 <_Z5DoSetjPhPKhP6VMExec+0x9bc> */
/* @0xe2744 b 0xe29b0 <_Z5DoSetjPhPKhP6VMExec+0x99c> */
/* @0xe2748 b 0xe297c <_Z5DoSetjPhPKhP6VMExec+0x968> */
/* @0xe274c b 0xe2948 <_Z5DoSetjPhPKhP6VMExec+0x934> */
/* @0xe2750 b 0xe28d0 <_Z5DoSetjPhPKhP6VMExec+0x8bc> */
/* @0xe2754 b 0xe2b5c <_Z5DoSetjPhPKhP6VMExec+0xb48> */
/* ── 组合 0x32（右 int32 / 左 int32）：32 位差 subs + sbc */
/* @0xe2758 cmp r11, #50 */
/* @0xe275c bne 0xe33c0 <_Z5DoSetjPhPKhP6VMExec+0x13ac> */
/* @0xe2760 ldr r12, [r10] */
/* @0xe2764 sub r9, r9, #1 */
/* @0xe2768 ldrd r2, r3, [r4] */
/* @0xe276c subs r0, r2, r12 */
/* @0xe2770 sbc r1, r3, r12, asr #31 */
/* @0xe2774 cmp r9, #5 */
/* @0xe2778 addls pc, pc, r9, lsl #2 */
/* @0xe277c b 0xe3ce4 <_Z5DoSetjPhPKhP6VMExec+0x1cd0> */
/* @0xe2780 b 0xe2d68 <_Z5DoSetjPhPKhP6VMExec+0xd54> */
/* @0xe2784 b 0xe2d40 <_Z5DoSetjPhPKhP6VMExec+0xd2c> */
/* @0xe2788 b 0xe2d04 <_Z5DoSetjPhPKhP6VMExec+0xcf0> */
/* @0xe278c b 0xe2cc8 <_Z5DoSetjPhPKhP6VMExec+0xcb4> */
/* @0xe2790 b 0xe2c9c <_Z5DoSetjPhPKhP6VMExec+0xc88> */
/* @0xe2794 b 0xe2a14 <_Z5DoSetjPhPKhP6VMExec+0xa00> */
/* ── 组合 0x46（右 指针 / 左 指针）：空指针特判后作差 */
/* @0xe2798 cmp r11, #70 */
/* @0xe279c bne 0xe33c0 <_Z5DoSetjPhPKhP6VMExec+0x13ac> */
/* @0xe27a0 ldr r3, [r10] */
/* @0xe27a4 sub r9, r9, #1 */
/* @0xe27a8 ldr r2, [r4] */
/* @0xe27ac cmp r3, #0 */
/* @0xe27b0 moveq r3, r2 */
/* @0xe27b4 subne r3, r2, #1 */
/* @0xe27b8 cmp r9, #5 */
/* @0xe27bc addls pc, pc, r9, lsl #2 */
/* @0xe27c0 b 0xe3c44 <_Z5DoSetjPhPKhP6VMExec+0x1c30> */
/* @0xe27c4 b 0xe2b30 <_Z5DoSetjPhPKhP6VMExec+0xb1c> */
/* @0xe27c8 b 0xe2b08 <_Z5DoSetjPhPKhP6VMExec+0xaf4> */
/* @0xe27cc b 0xe2acc <_Z5DoSetjPhPKhP6VMExec+0xab8> */
/* @0xe27d0 b 0xe2a90 <_Z5DoSetjPhPKhP6VMExec+0xa7c> */
/* @0xe27d4 b 0xe2a64 <_Z5DoSetjPhPKhP6VMExec+0xa50> */
/* @0xe27d8 b 0xe2a3c <_Z5DoSetjPhPKhP6VMExec+0xa28> */
/* ── 组合 0x02（右 f32 / 左 double）：d7 = 左 - 右 */
/* @0xe27dc vldr s14, [r10] */
/* @0xe27e0 vcvt.f64.s32 d7, s14 */
/* @0xe27e4 sub r9, r9, #1 */
/* @0xe27e8 vldr d6, [r4] */
/* @0xe27ec vsub.f64 d7, d6, d7 */
/* @0xe27f0 cmp r9, #5 */
/* @0xe27f4 addls pc, pc, r9, lsl #2 */
/* @0xe27f8 b 0xe3c94 <_Z5DoSetjPhPKhP6VMExec+0x1c80> */
/* @0xe27fc b 0xe3190 <_Z5DoSetjPhPKhP6VMExec+0x117c> */
/* @0xe2800 b 0xe3170 <_Z5DoSetjPhPKhP6VMExec+0x115c> */
/* @0xe2804 b 0xe313c <_Z5DoSetjPhPKhP6VMExec+0x1128> */
/* @0xe2808 b 0xe3108 <_Z5DoSetjPhPKhP6VMExec+0x10f4> */
/* @0xe280c b 0xe30e4 <_Z5DoSetjPhPKhP6VMExec+0x10d0> */
/* @0xe2810 b 0xe30c4 <_Z5DoSetjPhPKhP6VMExec+0x10b0> */
/* ── 右操作数未解析 → ReferenceError（同 e254c） */
/* @0xe2814 ldr r0, [pc, #0x7f0] */
/* @0xe2818 add r0, pc, r0 */
/* @0xe281c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe2820 mov r0, r8 */
/* @0xe2824 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe2828 ldr r0, [pc, #0x7e0] */
/* @0xe282c add r0, pc, r0 */
/* @0xe2830 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe2834 mov r0, r4 */
/* @0xe2838 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe283c orr r11, r11, #15 */
/* @0xe2840 b 0xe26f8 <_Z5DoSetjPhPKhP6VMExec+0x6e4> */
/* @0xe2844 and r12, r12, #240 */
/* @0xe2848 orr r11, r12, #3 */
/* @0xe284c b 0xe26f8 <_Z5DoSetjPhPKhP6VMExec+0x6e4> */
/* @0xe2850 and r12, r12, #240 */
/* @0xe2854 orr r11, r12, #6 */
/* @0xe2858 b 0xe26f8 <_Z5DoSetjPhPKhP6VMExec+0x6e4> */
/* @0xe285c orr r11, r11, #240 */
/* @0xe2860 b 0xe270c <_Z5DoSetjPhPKhP6VMExec+0x6f8> */
/* @0xe2864 and r11, r11, #240 */
/* @0xe2868 b 0xe26f8 <_Z5DoSetjPhPKhP6VMExec+0x6e4> */
/* @0xe286c and r11, r11, #15 */
/* @0xe2870 orr r11, r11, #48 */
/* @0xe2874 b 0xe270c <_Z5DoSetjPhPKhP6VMExec+0x6f8> */
/* @0xe2878 and r11, r11, #15 */
/* @0xe287c orr r11, r11, #96 */
/* @0xe2880 b 0xe270c <_Z5DoSetjPhPKhP6VMExec+0x6f8> */
/* @0xe2884 and r11, r11, #15 */
/* @0xe2888 b 0xe270c <_Z5DoSetjPhPKhP6VMExec+0x6f8> */
/* @0xe288c ldr r0, [pc, #0x780] */
/* @0xe2890 add r0, pc, r0 */
/* @0xe2894 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe2898 mov r0, r8 */
/* @0xe289c b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* ── RValue tag 表里的 VMError 分支（右侧） */
/* @0xe28a0 ldr r1, [pc, #0x770] */
/* @0xe28a4 mov r0, r8 */
/* @0xe28a8 mov r7, r10 */
/* @0xe28ac add r1, pc, r1 */
/* @0xe28b0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe28b4 b 0xe26f8 <_Z5DoSetjPhPKhP6VMExec+0x6e4> */
/* ── RValue tag 表里的 VMError 分支（左侧） */
/* @0xe28b8 ldr r1, [pc, #0x75c] */
/* @0xe28bc mov r0, r8 */
/* @0xe28c0 mov r5, r4 */
/* @0xe28c4 add r1, pc, r1 */
/* @0xe28c8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe28cc b 0xe270c <_Z5DoSetjPhPKhP6VMExec+0x6f8> */
/* @0xe28d0 ldr r3, [pc, #0x748] */
/* @0xe28d4 ldr r3, [r6, r3] */
/* @0xe28d8 vldr d6, [r3] */
/* @0xe28dc vneg.f64 d6, d6 */
/* @0xe28e0 vcmpe.f64 d7, d6 */
/* @0xe28e4 vmrs APSR_nzcv, fpscr */
/* @0xe28e8 movlt r0, #0 */
/* @0xe28ec movge r0, #1 */
/* ── 结果统一落地：str r0,[r7-4]；随后按 tag∈{1,2,3,4} 释放两个临时 RValue 并返回 r8 */
/* @0xe28f0 str r0, [r7, #-0x4] */
/* @0xe28f4 ldr r3, [sp, #0x2c] */
/* @0xe28f8 sub r3, r3, #1 */
/* @0xe28fc bic r3, r3, #-16777216 */
/* @0xe2900 bic r3, r3, #3 */
/* @0xe2904 cmp r3, #0 */
/* @0xe2908 beq 0xe31b4 <_Z5DoSetjPhPKhP6VMExec+0x11a0> */
/* @0xe290c ldr r1, [sp, #0x3c] */
/* @0xe2910 mov r3, #0 */
/* @0xe2914 str r3, [sp, #0x28] */
/* @0xe2918 mov r2, #5 */
/* @0xe291c sub r1, r1, #1 */
/* @0xe2920 str r3, [sp, #0x20] */
/* @0xe2924 bic r3, r1, #-16777216 */
/* @0xe2928 str r2, [sp, #0x2c] */
/* @0xe292c bic r3, r3, #3 */
/* @0xe2930 cmp r3, #0 */
/* @0xe2934 bne 0xe247c <_Z5DoSetjPhPKhP6VMExec+0x468> */
/* @0xe2938 add r0, sp, #48 */
/* @0xe293c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe2940 mov r0, r8 */
/* @0xe2944 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* ── 比较核第一段：GOT 取常量 double（1e-05，见 e3020）后与 d7(=左-右) 比较 */
/* @0xe2948 ldr r3, [pc, #0x6d0] */
/* @0xe294c ldr r3, [r6, r3] */
/* @0xe2950 vldr d6, [r3] */
/* @0xe2954 vneg.f64 d5, d6 */
/* @0xe2958 vcmpe.f64 d7, d5 */
/* @0xe295c vmrs APSR_nzcv, fpscr */
/* ── movmi #1 ⇒ diff < -1e-05 */
/* @0xe2960 movmi r0, #1 */
/* @0xe2964 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2968 vcmpe.f64 d7, d6 */
/* @0xe296c vmrs APSR_nzcv, fpscr */
/* @0xe2970 movle r0, #0 */
/* @0xe2974 movgt r0, #1 */
/* @0xe2978 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe297c ldr r3, [pc, #0x69c] */
/* @0xe2980 ldr r3, [r6, r3] */
/* @0xe2984 vldr d6, [r3] */
/* @0xe2988 vneg.f64 d5, d6 */
/* @0xe298c vcmpe.f64 d7, d5 */
/* @0xe2990 vmrs APSR_nzcv, fpscr */
/* @0xe2994 movlt r0, #0 */
/* @0xe2998 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe299c vcmpe.f64 d7, d6 */
/* @0xe29a0 vmrs APSR_nzcv, fpscr */
/* @0xe29a4 movhi r0, #0 */
/* @0xe29a8 movls r0, #1 */
/* @0xe29ac b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── K=2（<=）：diff <= +1e-05 ⇒ movls #1 */
/* @0xe29b0 ldr r3, [pc, #0x668] */
/* @0xe29b4 ldr r3, [r6, r3] */
/* @0xe29b8 vldr d6, [r3] */
/* @0xe29bc vcmpe.f64 d7, d6 */
/* @0xe29c0 vmrs APSR_nzcv, fpscr */
/* @0xe29c4 movhi r0, #0 */
/* @0xe29c8 movls r0, #1 */
/* @0xe29cc b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── K=4（!=）第一段：diff < -1e-05 ⇒ 1 */
/* @0xe29d0 ldr r3, [pc, #0x648] */
/* @0xe29d4 ldr r3, [r6, r3] */
/* @0xe29d8 vldr d6, [r3] */
/* @0xe29dc vneg.f64 d6, d6 */
/* @0xe29e0 vcmpe.f64 d7, d6 */
/* @0xe29e4 vmrs APSR_nzcv, fpscr */
/* @0xe29e8 movpl r0, #0 */
/* @0xe29ec movmi r0, #1 */
/* @0xe29f0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── K=6（>）：diff > +1e-05 ⇒ movgt #1 */
/* @0xe29f4 ldr r3, [pc, #0x624] */
/* @0xe29f8 ldr r3, [r6, r3] */
/* @0xe29fc vldr d6, [r3] */
/* @0xe2a00 vcmpe.f64 d7, d6 */
/* @0xe2a04 vmrs APSR_nzcv, fpscr */
/* @0xe2a08 movle r0, #0 */
/* @0xe2a0c movgt r0, #1 */
/* @0xe2a10 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2a14 bl 0x319164 <__floatdidf> */
/* @0xe2a18 ldr r3, [pc, #0x600] */
/* @0xe2a1c ldr r3, [r6, r3] */
/* @0xe2a20 vldr d7, [r3] */
/* @0xe2a24 vmov d6, r0, r1 */
/* @0xe2a28 vcmpe.f64 d6, d7 */
/* @0xe2a2c vmrs APSR_nzcv, fpscr */
/* @0xe2a30 movle r0, #0 */
/* @0xe2a34 movgt r0, #1 */
/* @0xe2a38 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2a3c vmov s15, r3 */
/* @0xe2a40 ldr r3, [pc, #0x5d8] */
/* @0xe2a44 vcvt.f64.s32 d6, s15 */
/* @0xe2a48 ldr r3, [r6, r3] */
/* @0xe2a4c vldr d7, [r3] */
/* @0xe2a50 vcmpe.f64 d6, d7 */
/* @0xe2a54 vmrs APSR_nzcv, fpscr */
/* @0xe2a58 movle r0, #0 */
/* @0xe2a5c movgt r0, #1 */
/* @0xe2a60 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2a64 vmov s15, r3 */
/* @0xe2a68 ldr r2, [pc, #0x5b0] */
/* @0xe2a6c vcvt.f64.s32 d6, s15 */
/* @0xe2a70 ldr r3, [r6, r2] */
/* @0xe2a74 vldr d7, [r3] */
/* @0xe2a78 vneg.f64 d7, d7 */
/* @0xe2a7c vcmpe.f64 d6, d7 */
/* @0xe2a80 vmrs APSR_nzcv, fpscr */
/* @0xe2a84 movlt r0, #0 */
/* @0xe2a88 movge r0, #1 */
/* @0xe2a8c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2a90 vmov s15, r3 */
/* @0xe2a94 ldr r2, [pc, #0x584] */
/* @0xe2a98 vcvt.f64.s32 d6, s15 */
/* @0xe2a9c ldr r3, [r6, r2] */
/* @0xe2aa0 vldr d7, [r3] */
/* @0xe2aa4 vneg.f64 d5, d7 */
/* @0xe2aa8 vcmpe.f64 d6, d5 */
/* @0xe2aac vmrs APSR_nzcv, fpscr */
/* @0xe2ab0 movmi r0, #1 */
/* @0xe2ab4 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2ab8 vcmpe.f64 d6, d7 */
/* @0xe2abc vmrs APSR_nzcv, fpscr */
/* @0xe2ac0 movle r0, #0 */
/* @0xe2ac4 movgt r0, #1 */
/* @0xe2ac8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2acc vmov s15, r3 */
/* @0xe2ad0 ldr r2, [pc, #0x548] */
/* @0xe2ad4 vcvt.f64.s32 d6, s15 */
/* @0xe2ad8 ldr r3, [r6, r2] */
/* @0xe2adc vldr d7, [r3] */
/* @0xe2ae0 vneg.f64 d5, d7 */
/* @0xe2ae4 vcmpe.f64 d6, d5 */
/* @0xe2ae8 vmrs APSR_nzcv, fpscr */
/* @0xe2aec movlt r0, #0 */
/* @0xe2af0 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2af4 vcmpe.f64 d6, d7 */
/* @0xe2af8 vmrs APSR_nzcv, fpscr */
/* @0xe2afc movhi r0, #0 */
/* @0xe2b00 movls r0, #1 */
/* @0xe2b04 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2b08 vmov s15, r3 */
/* @0xe2b0c ldr r3, [pc, #0x50c] */
/* @0xe2b10 vcvt.f64.s32 d6, s15 */
/* @0xe2b14 ldr r3, [r6, r3] */
/* @0xe2b18 vldr d7, [r3] */
/* @0xe2b1c vcmpe.f64 d6, d7 */
/* @0xe2b20 vmrs APSR_nzcv, fpscr */
/* @0xe2b24 movhi r0, #0 */
/* @0xe2b28 movls r0, #1 */
/* @0xe2b2c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2b30 vmov s15, r3 */
/* @0xe2b34 ldr r2, [pc, #0x4e4] */
/* @0xe2b38 vcvt.f64.s32 d6, s15 */
/* @0xe2b3c ldr r3, [r6, r2] */
/* @0xe2b40 vldr d7, [r3] */
/* @0xe2b44 vneg.f64 d7, d7 */
/* @0xe2b48 vcmpe.f64 d6, d7 */
/* @0xe2b4c vmrs APSR_nzcv, fpscr */
/* @0xe2b50 movpl r0, #0 */
/* @0xe2b54 movmi r0, #1 */
/* @0xe2b58 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2b5c ldr r3, [pc, #0x4bc] */
/* @0xe2b60 ldr r3, [r6, r3] */
/* @0xe2b64 vldr d6, [r3] */
/* @0xe2b68 vcmpe.f64 d7, d6 */
/* @0xe2b6c vmrs APSR_nzcv, fpscr */
/* @0xe2b70 movle r0, #0 */
/* @0xe2b74 movgt r0, #1 */
/* @0xe2b78 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2b7c bl 0x319164 <__floatdidf> */
/* @0xe2b80 ldr r3, [pc, #0x498] */
/* @0xe2b84 ldr r3, [r6, r3] */
/* @0xe2b88 vldr d7, [r3] */
/* @0xe2b8c vneg.f64 d5, d7 */
/* @0xe2b90 vmov d6, r0, r1 */
/* @0xe2b94 vcmpe.f64 d6, d5 */
/* @0xe2b98 vmrs APSR_nzcv, fpscr */
/* @0xe2b9c movmi r0, #1 */
/* @0xe2ba0 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2ba4 vcmpe.f64 d6, d7 */
/* @0xe2ba8 vmrs APSR_nzcv, fpscr */
/* @0xe2bac movle r0, #0 */
/* @0xe2bb0 movgt r0, #1 */
/* @0xe2bb4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2bb8 bl 0x319164 <__floatdidf> */
/* @0xe2bbc ldr r3, [pc, #0x45c] */
/* @0xe2bc0 ldr r3, [r6, r3] */
/* @0xe2bc4 vldr d7, [r3] */
/* @0xe2bc8 vneg.f64 d5, d7 */
/* @0xe2bcc vmov d6, r0, r1 */
/* @0xe2bd0 vcmpe.f64 d6, d5 */
/* @0xe2bd4 vmrs APSR_nzcv, fpscr */
/* @0xe2bd8 movlt r0, #0 */
/* @0xe2bdc blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2be0 vcmpe.f64 d6, d7 */
/* @0xe2be4 vmrs APSR_nzcv, fpscr */
/* @0xe2be8 movhi r0, #0 */
/* @0xe2bec movls r0, #1 */
/* @0xe2bf0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2bf4 bl 0x319164 <__floatdidf> */
/* @0xe2bf8 ldr r3, [pc, #0x420] */
/* @0xe2bfc ldr r3, [r6, r3] */
/* @0xe2c00 vldr d7, [r3] */
/* @0xe2c04 vmov d6, r0, r1 */
/* @0xe2c08 vcmpe.f64 d6, d7 */
/* @0xe2c0c vmrs APSR_nzcv, fpscr */
/* @0xe2c10 movhi r0, #0 */
/* @0xe2c14 movls r0, #1 */
/* @0xe2c18 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2c1c bl 0x319164 <__floatdidf> */
/* @0xe2c20 ldr r3, [pc, #0x3f8] */
/* @0xe2c24 ldr r3, [r6, r3] */
/* @0xe2c28 vldr d7, [r3] */
/* @0xe2c2c vneg.f64 d7, d7 */
/* @0xe2c30 vmov d6, r0, r1 */
/* @0xe2c34 vcmpe.f64 d6, d7 */
/* @0xe2c38 vmrs APSR_nzcv, fpscr */
/* @0xe2c3c movpl r0, #0 */
/* @0xe2c40 movmi r0, #1 */
/* @0xe2c44 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2c48 bl 0x319164 <__floatdidf> */
/* @0xe2c4c ldr r3, [pc, #0x3cc] */
/* @0xe2c50 ldr r3, [r6, r3] */
/* @0xe2c54 vldr d7, [r3] */
/* @0xe2c58 vmov d6, r0, r1 */
/* @0xe2c5c vcmpe.f64 d6, d7 */
/* @0xe2c60 vmrs APSR_nzcv, fpscr */
/* @0xe2c64 movle r0, #0 */
/* @0xe2c68 movgt r0, #1 */
/* @0xe2c6c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2c70 bl 0x319164 <__floatdidf> */
/* @0xe2c74 ldr r3, [pc, #0x3a4] */
/* @0xe2c78 ldr r3, [r6, r3] */
/* @0xe2c7c vldr d7, [r3] */
/* @0xe2c80 vneg.f64 d7, d7 */
/* @0xe2c84 vmov d6, r0, r1 */
/* @0xe2c88 vcmpe.f64 d6, d7 */
/* @0xe2c8c vmrs APSR_nzcv, fpscr */
/* @0xe2c90 movlt r0, #0 */
/* @0xe2c94 movge r0, #1 */
/* @0xe2c98 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2c9c bl 0x319164 <__floatdidf> */
/* @0xe2ca0 ldr r3, [pc, #0x378] */
/* @0xe2ca4 ldr r3, [r6, r3] */
/* @0xe2ca8 vldr d7, [r3] */
/* @0xe2cac vneg.f64 d7, d7 */
/* @0xe2cb0 vmov d6, r0, r1 */
/* @0xe2cb4 vcmpe.f64 d6, d7 */
/* @0xe2cb8 vmrs APSR_nzcv, fpscr */
/* @0xe2cbc movlt r0, #0 */
/* @0xe2cc0 movge r0, #1 */
/* @0xe2cc4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2cc8 bl 0x319164 <__floatdidf> */
/* @0xe2ccc ldr r3, [pc, #0x34c] */
/* @0xe2cd0 ldr r3, [r6, r3] */
/* @0xe2cd4 vldr d7, [r3] */
/* @0xe2cd8 vneg.f64 d5, d7 */
/* @0xe2cdc vmov d6, r0, r1 */
/* @0xe2ce0 vcmpe.f64 d6, d5 */
/* @0xe2ce4 vmrs APSR_nzcv, fpscr */
/* @0xe2ce8 movmi r0, #1 */
/* @0xe2cec bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2cf0 vcmpe.f64 d6, d7 */
/* @0xe2cf4 vmrs APSR_nzcv, fpscr */
/* @0xe2cf8 movle r0, #0 */
/* @0xe2cfc movgt r0, #1 */
/* @0xe2d00 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2d04 bl 0x319164 <__floatdidf> */
/* @0xe2d08 ldr r3, [pc, #0x310] */
/* @0xe2d0c ldr r3, [r6, r3] */
/* @0xe2d10 vldr d7, [r3] */
/* @0xe2d14 vneg.f64 d5, d7 */
/* @0xe2d18 vmov d6, r0, r1 */
/* @0xe2d1c vcmpe.f64 d6, d5 */
/* @0xe2d20 vmrs APSR_nzcv, fpscr */
/* @0xe2d24 movlt r0, #0 */
/* @0xe2d28 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2d2c vcmpe.f64 d6, d7 */
/* @0xe2d30 vmrs APSR_nzcv, fpscr */
/* @0xe2d34 movhi r0, #0 */
/* @0xe2d38 movls r0, #1 */
/* @0xe2d3c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2d40 bl 0x319164 <__floatdidf> */
/* @0xe2d44 ldr r3, [pc, #0x2d4] */
/* @0xe2d48 ldr r3, [r6, r3] */
/* @0xe2d4c vldr d7, [r3] */
/* @0xe2d50 vmov d6, r0, r1 */
/* @0xe2d54 vcmpe.f64 d6, d7 */
/* @0xe2d58 vmrs APSR_nzcv, fpscr */
/* @0xe2d5c movhi r0, #0 */
/* @0xe2d60 movls r0, #1 */
/* @0xe2d64 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2d68 bl 0x319164 <__floatdidf> */
/* @0xe2d6c ldr r3, [pc, #0x2ac] */
/* @0xe2d70 ldr r3, [r6, r3] */
/* @0xe2d74 vldr d7, [r3] */
/* @0xe2d78 vneg.f64 d7, d7 */
/* @0xe2d7c vmov d6, r0, r1 */
/* @0xe2d80 vcmpe.f64 d6, d7 */
/* @0xe2d84 vmrs APSR_nzcv, fpscr */
/* @0xe2d88 movpl r0, #0 */
/* @0xe2d8c movmi r0, #1 */
/* @0xe2d90 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── K=5（>=）：diff >= -1e-05 ⇒ movge #1 */
/* @0xe2d94 ldr r3, [pc, #0x284] */
/* @0xe2d98 ldr r3, [r6, r3] */
/* @0xe2d9c vldr d6, [r3] */
/* @0xe2da0 vneg.f64 d6, d6 */
/* @0xe2da4 vcmpe.f64 d7, d6 */
/* @0xe2da8 vmrs APSR_nzcv, fpscr */
/* @0xe2dac movlt r0, #0 */
/* @0xe2db0 movge r0, #1 */
/* @0xe2db4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── K=4（!=）：先 diff < -1e-05 ⇒ 1，否则 diff > +1e-05 ⇒ 1（|diff| > 1e-05） */
/* @0xe2db8 ldr r3, [pc, #0x260] */
/* @0xe2dbc ldr r3, [r6, r3] */
/* @0xe2dc0 vldr d6, [r3] */
/* @0xe2dc4 vneg.f64 d5, d6 */
/* @0xe2dc8 vcmpe.f64 d7, d5 */
/* @0xe2dcc vmrs APSR_nzcv, fpscr */
/* @0xe2dd0 movmi r0, #1 */
/* @0xe2dd4 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2dd8 vcmpe.f64 d7, d6 */
/* @0xe2ddc vmrs APSR_nzcv, fpscr */
/* @0xe2de0 movle r0, #0 */
/* @0xe2de4 movgt r0, #1 */
/* @0xe2de8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── K=3（==）：先 diff < -1e-05 ⇒ 0，否则 diff <= +1e-05 ⇒ 1（|diff| <= 1e-05） */
/* @0xe2dec ldr r3, [pc, #0x22c] */
/* @0xe2df0 ldr r3, [r6, r3] */
/* @0xe2df4 vldr d6, [r3] */
/* @0xe2df8 vneg.f64 d5, d6 */
/* @0xe2dfc vcmpe.f64 d7, d5 */
/* @0xe2e00 vmrs APSR_nzcv, fpscr */
/* @0xe2e04 movlt r0, #0 */
/* @0xe2e08 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2e0c vcmpe.f64 d7, d6 */
/* @0xe2e10 vmrs APSR_nzcv, fpscr */
/* @0xe2e14 movhi r0, #0 */
/* @0xe2e18 movls r0, #1 */
/* @0xe2e1c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── K=2（<=）：diff <= +1e-05 ⇒ 1 */
/* @0xe2e20 ldr r3, [pc, #0x1f8] */
/* @0xe2e24 ldr r3, [r6, r3] */
/* @0xe2e28 vldr d6, [r3] */
/* @0xe2e2c vcmpe.f64 d7, d6 */
/* @0xe2e30 vmrs APSR_nzcv, fpscr */
/* @0xe2e34 movhi r0, #0 */
/* @0xe2e38 movls r0, #1 */
/* @0xe2e3c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── K=1（<）：diff < -1e-05 ⇒ movmi #1 */
/* @0xe2e40 ldr r3, [pc, #0x1d8] */
/* @0xe2e44 ldr r3, [r6, r3] */
/* @0xe2e48 vldr d6, [r3] */
/* @0xe2e4c vneg.f64 d6, d6 */
/* @0xe2e50 vcmpe.f64 d7, d6 */
/* @0xe2e54 vmrs APSR_nzcv, fpscr */
/* @0xe2e58 movpl r0, #0 */
/* @0xe2e5c movmi r0, #1 */
/* @0xe2e60 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2e64 vcvt.f64.s32 d6, s12 */
/* @0xe2e68 ldr r3, [pc, #0x1b0] */
/* @0xe2e6c ldr r3, [r6, r3] */
/* @0xe2e70 vldr d7, [r3] */
/* @0xe2e74 vcmpe.f64 d6, d7 */
/* @0xe2e78 vmrs APSR_nzcv, fpscr */
/* @0xe2e7c movle r0, #0 */
/* @0xe2e80 movgt r0, #1 */
/* @0xe2e84 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2e88 ldr r3, [pc, #0x190] */
/* @0xe2e8c vcvt.f64.s32 d6, s12 */
/* @0xe2e90 ldr r3, [r6, r3] */
/* @0xe2e94 vldr d7, [r3] */
/* @0xe2e98 vneg.f64 d7, d7 */
/* @0xe2e9c vcmpe.f64 d6, d7 */
/* @0xe2ea0 vmrs APSR_nzcv, fpscr */
/* @0xe2ea4 movlt r0, #0 */
/* @0xe2ea8 movge r0, #1 */
/* @0xe2eac b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2eb0 ldr r3, [pc, #0x168] */
/* @0xe2eb4 vcvt.f64.s32 d6, s12 */
/* @0xe2eb8 ldr r3, [r6, r3] */
/* @0xe2ebc vldr d7, [r3] */
/* @0xe2ec0 vneg.f64 d5, d7 */
/* @0xe2ec4 vcmpe.f64 d6, d5 */
/* @0xe2ec8 vmrs APSR_nzcv, fpscr */
/* @0xe2ecc movmi r0, #1 */
/* @0xe2ed0 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2ed4 vcmpe.f64 d6, d7 */
/* @0xe2ed8 vmrs APSR_nzcv, fpscr */
/* @0xe2edc movle r0, #0 */
/* @0xe2ee0 movgt r0, #1 */
/* @0xe2ee4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2ee8 ldr r3, [pc, #0x130] */
/* @0xe2eec vcvt.f64.s32 d6, s12 */
/* @0xe2ef0 ldr r3, [r6, r3] */
/* @0xe2ef4 vldr d7, [r3] */
/* @0xe2ef8 vneg.f64 d5, d7 */
/* @0xe2efc vcmpe.f64 d6, d5 */
/* @0xe2f00 vmrs APSR_nzcv, fpscr */
/* @0xe2f04 movlt r0, #0 */
/* @0xe2f08 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2f0c vcmpe.f64 d6, d7 */
/* @0xe2f10 vmrs APSR_nzcv, fpscr */
/* @0xe2f14 movhi r0, #0 */
/* @0xe2f18 movls r0, #1 */
/* @0xe2f1c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2f20 vcvt.f64.s32 d6, s12 */
/* @0xe2f24 ldr r3, [pc, #0xf4] */
/* @0xe2f28 ldr r3, [r6, r3] */
/* @0xe2f2c vldr d7, [r3] */
/* @0xe2f30 vcmpe.f64 d6, d7 */
/* @0xe2f34 vmrs APSR_nzcv, fpscr */
/* @0xe2f38 movhi r0, #0 */
/* @0xe2f3c movls r0, #1 */
/* @0xe2f40 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2f44 ldr r3, [pc, #0xd4] */
/* @0xe2f48 vcvt.f64.s32 d6, s12 */
/* @0xe2f4c ldr r3, [r6, r3] */
/* @0xe2f50 vldr d7, [r3] */
/* @0xe2f54 vneg.f64 d7, d7 */
/* @0xe2f58 vcmpe.f64 d6, d7 */
/* @0xe2f5c vmrs APSR_nzcv, fpscr */
/* @0xe2f60 movpl r0, #0 */
/* @0xe2f64 movmi r0, #1 */
/* @0xe2f68 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2f6c vmov s15, r3 */
/* @0xe2f70 ldr r3, [pc, #0xa8] */
/* @0xe2f74 vcvt.f64.s32 d6, s15 */
/* @0xe2f78 ldr r3, [r6, r3] */
/* @0xe2f7c vldr d7, [r3] */
/* @0xe2f80 vcmpe.f64 d6, d7 */
/* @0xe2f84 vmrs APSR_nzcv, fpscr */
/* @0xe2f88 movle r0, #0 */
/* @0xe2f8c movgt r0, #1 */
/* @0xe2f90 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2f94 vmov s15, r3 */
/* @0xe2f98 ldr r2, [pc, #0x80] */
/* @0xe2f9c vcvt.f64.s32 d6, s15 */
/* @0xe2fa0 ldr r3, [r6, r2] */
/* @0xe2fa4 vldr d7, [r3] */
/* @0xe2fa8 vneg.f64 d7, d7 */
/* @0xe2fac vcmpe.f64 d6, d7 */
/* @0xe2fb0 vmrs APSR_nzcv, fpscr */
/* @0xe2fb4 movlt r0, #0 */
/* @0xe2fb8 movge r0, #1 */
/* @0xe2fbc b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2fc0 vmov s15, r3 */
/* @0xe2fc4 ldr r2, [pc, #0x54] */
/* @0xe2fc8 vcvt.f64.s32 d6, s15 */
/* @0xe2fcc ldr r3, [r6, r2] */
/* @0xe2fd0 vldr d7, [r3] */
/* @0xe2fd4 vneg.f64 d5, d7 */
/* @0xe2fd8 vcmpe.f64 d6, d5 */
/* @0xe2fdc vmrs APSR_nzcv, fpscr */
/* @0xe2fe0 movmi r0, #1 */
/* @0xe2fe4 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe2fe8 vcmpe.f64 d6, d7 */
/* @0xe2fec vmrs APSR_nzcv, fpscr */
/* @0xe2ff0 movle r0, #0 */
/* @0xe2ff4 movgt r0, #1 */
/* @0xe2ff8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── 0xe2ffc..0xe3030 = literal pool（14 字，非指令）：GOT 锚 0x30fc14、9 个字符串偏移、 */
/*    以及 0xffffc0c8 → GOT 槽 0x3edd20 → .data 0x3f20a0 = double 1e-05 */
/* @0xe2ffc eorseq pc, r0, r4, lsl r12 */
/* @0xe3000 eoreq r1, r5, r4, asr lr */
/* @0xe3004 eoreq r1, r5, r12, ror #27 */
/* @0xe3008 eoreq r1, r5, r8, ror sp */
/* @0xe300c eoreq r1, r5, r4, ror r11 */
/* @0xe3010 eoreq r1, r5, r12, lsl #23 */
/* @0xe3014 eoreq r1, r5, r0, lsl #23 */
/* @0xe3018 eoreq r1, r5, r12, lsl r12 */
/* @0xe301c eoreq r1, r5, r4, lsr #24 */
/* @0xe3020 .word 0xffffc0c8 */
/* @0xe3024 eoreq r0, r5, r0, lsl #19 */
/* @0xe3028 eoreq r0, r5, r0, lsl #16 */
/* @0xe302c eoreq r0, r5, r12, asr r8 */
/* @0xe3030 mlaeq r5, r4, r7, r0 */
/* @0xe3034 vmov s15, r3 */
/* @0xe3038 ldr r2, [pc, #-0x20] */
/* @0xe303c vcvt.f64.s32 d6, s15 */
/* @0xe3040 ldr r3, [r6, r2] */
/* @0xe3044 vldr d7, [r3] */
/* @0xe3048 vneg.f64 d5, d7 */
/* @0xe304c vcmpe.f64 d6, d5 */
/* @0xe3050 vmrs APSR_nzcv, fpscr */
/* @0xe3054 movlt r0, #0 */
/* @0xe3058 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe305c vcmpe.f64 d6, d7 */
/* @0xe3060 vmrs APSR_nzcv, fpscr */
/* @0xe3064 movhi r0, #0 */
/* @0xe3068 movls r0, #1 */
/* @0xe306c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3070 vmov s15, r3 */
/* @0xe3074 ldr r3, [pc, #-0x5c] */
/* @0xe3078 vcvt.f64.s32 d6, s15 */
/* @0xe307c ldr r3, [r6, r3] */
/* @0xe3080 vldr d7, [r3] */
/* @0xe3084 vcmpe.f64 d6, d7 */
/* @0xe3088 vmrs APSR_nzcv, fpscr */
/* @0xe308c movhi r0, #0 */
/* @0xe3090 movls r0, #1 */
/* @0xe3094 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3098 vmov s15, r3 */
/* @0xe309c ldr r2, [pc, #-0x84] */
/* @0xe30a0 vcvt.f64.s32 d6, s15 */
/* @0xe30a4 ldr r3, [r6, r2] */
/* @0xe30a8 vldr d7, [r3] */
/* @0xe30ac vneg.f64 d7, d7 */
/* @0xe30b0 vcmpe.f64 d6, d7 */
/* @0xe30b4 vmrs APSR_nzcv, fpscr */
/* @0xe30b8 movpl r0, #0 */
/* @0xe30bc movmi r0, #1 */
/* @0xe30c0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe30c4 ldr r3, [pc, #-0xac] */
/* @0xe30c8 ldr r3, [r6, r3] */
/* @0xe30cc vldr d6, [r3] */
/* @0xe30d0 vcmpe.f64 d7, d6 */
/* @0xe30d4 vmrs APSR_nzcv, fpscr */
/* @0xe30d8 movle r0, #0 */
/* @0xe30dc movgt r0, #1 */
/* @0xe30e0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe30e4 ldr r3, [pc, #-0xcc] */
/* @0xe30e8 ldr r3, [r6, r3] */
/* @0xe30ec vldr d6, [r3] */
/* @0xe30f0 vneg.f64 d6, d6 */
/* @0xe30f4 vcmpe.f64 d7, d6 */
/* @0xe30f8 vmrs APSR_nzcv, fpscr */
/* @0xe30fc movlt r0, #0 */
/* @0xe3100 movge r0, #1 */
/* @0xe3104 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3108 ldr r3, [pc, #-0xf0] */
/* @0xe310c ldr r3, [r6, r3] */
/* @0xe3110 vldr d6, [r3] */
/* @0xe3114 vneg.f64 d5, d6 */
/* @0xe3118 vcmpe.f64 d7, d5 */
/* @0xe311c vmrs APSR_nzcv, fpscr */
/* @0xe3120 movmi r0, #1 */
/* @0xe3124 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3128 vcmpe.f64 d7, d6 */
/* @0xe312c vmrs APSR_nzcv, fpscr */
/* @0xe3130 movle r0, #0 */
/* @0xe3134 movgt r0, #1 */
/* @0xe3138 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe313c ldr r3, [pc, #-0x124] */
/* @0xe3140 ldr r3, [r6, r3] */
/* @0xe3144 vldr d6, [r3] */
/* @0xe3148 vneg.f64 d5, d6 */
/* @0xe314c vcmpe.f64 d7, d5 */
/* @0xe3150 vmrs APSR_nzcv, fpscr */
/* @0xe3154 movlt r0, #0 */
/* @0xe3158 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe315c vcmpe.f64 d7, d6 */
/* @0xe3160 vmrs APSR_nzcv, fpscr */
/* @0xe3164 movhi r0, #0 */
/* @0xe3168 movls r0, #1 */
/* @0xe316c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3170 ldr r3, [pc, #-0x158] */
/* @0xe3174 ldr r3, [r6, r3] */
/* @0xe3178 vldr d6, [r3] */
/* @0xe317c vcmpe.f64 d7, d6 */
/* @0xe3180 vmrs APSR_nzcv, fpscr */
/* @0xe3184 movhi r0, #0 */
/* @0xe3188 movls r0, #1 */
/* @0xe318c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3190 ldr r3, [pc, #-0x178] */
/* @0xe3194 ldr r3, [r6, r3] */
/* @0xe3198 vldr d6, [r3] */
/* @0xe319c vneg.f64 d6, d6 */
/* @0xe31a0 vcmpe.f64 d7, d6 */
/* @0xe31a4 vmrs APSR_nzcv, fpscr */
/* @0xe31a8 movpl r0, #0 */
/* @0xe31ac movmi r0, #1 */
/* @0xe31b0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe31b4 add r0, sp, #32 */
/* @0xe31b8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe31bc b 0xe290c <_Z5DoSetjPhPKhP6VMExec+0x8f8> */
/* ── 组合 0x66（右 指针 / 左 指针）：strcmp(左, 右)，K-1 六路表 e3208 */
/* @0xe31c0 ldr r2, [r10] */
/* @0xe31c4 ldr r3, [r4] */
/* @0xe31c8 cmp r2, #0 */
/* @0xe31cc moveq r1, r2 */
/* @0xe31d0 beq 0xe31e0 <_Z5DoSetjPhPKhP6VMExec+0x11cc> */
/* @0xe31d4 ldr r1, [r2] */
/* @0xe31d8 adds r2, r1, #0 */
/* @0xe31dc movne r2, #1 */
/* @0xe31e0 cmp r3, #0 */
/* @0xe31e4 beq 0xe3be8 <_Z5DoSetjPhPKhP6VMExec+0x1bd4> */
/* @0xe31e8 ldr r0, [r3] */
/* @0xe31ec adds r3, r0, #0 */
/* @0xe31f0 movne r3, #1 */
/* @0xe31f4 tst r2, r3 */
/* @0xe31f8 beq 0xe3b70 <_Z5DoSetjPhPKhP6VMExec+0x1b5c> */
/* @0xe31fc bl 0xb6574 <strcmp@plt> */
/* @0xe3200 sub r9, r9, #1 */
/* @0xe3204 cmp r9, #5 */
/* @0xe3208 addls pc, pc, r9, lsl #2 */
/* @0xe320c b 0xe3c24 <_Z5DoSetjPhPKhP6VMExec+0x1c10> */
/* @0xe3210 b 0xe326c <_Z5DoSetjPhPKhP6VMExec+0x1258> */
/* @0xe3214 b 0xe325c <_Z5DoSetjPhPKhP6VMExec+0x1248> */
/* @0xe3218 b 0xe3250 <_Z5DoSetjPhPKhP6VMExec+0x123c> */
/* @0xe321c b 0xe3244 <_Z5DoSetjPhPKhP6VMExec+0x1230> */
/* @0xe3220 b 0xe3238 <_Z5DoSetjPhPKhP6VMExec+0x1224> */
/* @0xe3224 b 0xe3228 <_Z5DoSetjPhPKhP6VMExec+0x1214> */
/* ── 字符串 K=6（>）：cmp/movgt ⇒ 1 */
/* @0xe3228 cmp r0, #0 */
/* @0xe322c movle r0, #0 */
/* @0xe3230 movgt r0, #1 */
/* @0xe3234 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── 字符串 K=5（>=）：mvn + lsr #31 ⇒ 1 */
/* @0xe3238 mvn r0, r0 */
/* @0xe323c lsr r0, r0, #31 */
/* @0xe3240 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── 字符串 K=4（!=）：adds/movne ⇒ 1 */
/* @0xe3244 adds r0, r0, #0 */
/* @0xe3248 movne r0, #1 */
/* @0xe324c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── 字符串 K=3（==）：rsbs r0,r0,#1；movlo #0（strcmp<0 时留下 1-strcmp，非归一化） */
/* @0xe3250 rsbs r0, r0, #1 */
/* @0xe3254 movlo r0, #0 */
/* @0xe3258 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── 字符串 K=2（<=）：cmp/movle ⇒ 1 */
/* @0xe325c cmp r0, #0 */
/* @0xe3260 movgt r0, #0 */
/* @0xe3264 movle r0, #1 */
/* @0xe3268 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* ── 字符串 K=1（<）：lsr #31 ⇒ 1 */
/* @0xe326c lsr r0, r0, #31 */
/* @0xe3270 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3274 vldr s14, [r10] */
/* @0xe3278 vcvt.f64.s32 d7, s14 */
/* @0xe327c vldr d6, [r4] */
/* @0xe3280 sub r9, r9, #1 */
/* @0xe3284 vsub.f64 d7, d6, d7 */
/* @0xe3288 vcvt.s32.f64 s12, d7 */
/* @0xe328c cmp r9, #5 */
/* @0xe3290 addls pc, pc, r9, lsl #2 */
/* @0xe3294 b 0xe3cd4 <_Z5DoSetjPhPKhP6VMExec+0x1cc0> */
/* @0xe3298 b 0xe3390 <_Z5DoSetjPhPKhP6VMExec+0x137c> */
/* @0xe329c b 0xe336c <_Z5DoSetjPhPKhP6VMExec+0x1358> */
/* @0xe32a0 b 0xe3334 <_Z5DoSetjPhPKhP6VMExec+0x1320> */
/* @0xe32a4 b 0xe32fc <_Z5DoSetjPhPKhP6VMExec+0x12e8> */
/* @0xe32a8 b 0xe32d4 <_Z5DoSetjPhPKhP6VMExec+0x12c0> */
/* @0xe32ac b 0xe32b0 <_Z5DoSetjPhPKhP6VMExec+0x129c> */
/* @0xe32b0 vcvt.f64.s32 d6, s12 */
/* @0xe32b4 ldr r3, [pc, #-0x29c] */
/* @0xe32b8 ldr r3, [r6, r3] */
/* @0xe32bc vldr d7, [r3] */
/* @0xe32c0 vcmpe.f64 d6, d7 */
/* @0xe32c4 vmrs APSR_nzcv, fpscr */
/* @0xe32c8 movle r0, #0 */
/* @0xe32cc movgt r0, #1 */
/* @0xe32d0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe32d4 ldr r3, [pc, #-0x2bc] */
/* @0xe32d8 vcvt.f64.s32 d6, s12 */
/* @0xe32dc ldr r3, [r6, r3] */
/* @0xe32e0 vldr d7, [r3] */
/* @0xe32e4 vneg.f64 d7, d7 */
/* @0xe32e8 vcmpe.f64 d6, d7 */
/* @0xe32ec vmrs APSR_nzcv, fpscr */
/* @0xe32f0 movlt r0, #0 */
/* @0xe32f4 movge r0, #1 */
/* @0xe32f8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe32fc ldr r3, [pc, #-0x2e4] */
/* @0xe3300 vcvt.f64.s32 d6, s12 */
/* @0xe3304 ldr r3, [r6, r3] */
/* @0xe3308 vldr d7, [r3] */
/* @0xe330c vneg.f64 d5, d7 */
/* @0xe3310 vcmpe.f64 d6, d5 */
/* @0xe3314 vmrs APSR_nzcv, fpscr */
/* @0xe3318 movmi r0, #1 */
/* @0xe331c bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3320 vcmpe.f64 d6, d7 */
/* @0xe3324 vmrs APSR_nzcv, fpscr */
/* @0xe3328 movle r0, #0 */
/* @0xe332c movgt r0, #1 */
/* @0xe3330 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3334 ldr r3, [pc, #-0x31c] */
/* @0xe3338 vcvt.f64.s32 d6, s12 */
/* @0xe333c ldr r3, [r6, r3] */
/* @0xe3340 vldr d7, [r3] */
/* @0xe3344 vneg.f64 d5, d7 */
/* @0xe3348 vcmpe.f64 d6, d5 */
/* @0xe334c vmrs APSR_nzcv, fpscr */
/* @0xe3350 movlt r0, #0 */
/* @0xe3354 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3358 vcmpe.f64 d6, d7 */
/* @0xe335c vmrs APSR_nzcv, fpscr */
/* @0xe3360 movhi r0, #0 */
/* @0xe3364 movls r0, #1 */
/* @0xe3368 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe336c vcvt.f64.s32 d6, s12 */
/* @0xe3370 ldr r3, [pc, #-0x358] */
/* @0xe3374 ldr r3, [r6, r3] */
/* @0xe3378 vldr d7, [r3] */
/* @0xe337c vcmpe.f64 d6, d7 */
/* @0xe3380 vmrs APSR_nzcv, fpscr */
/* @0xe3384 movhi r0, #0 */
/* @0xe3388 movls r0, #1 */
/* @0xe338c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3390 ldr r3, [pc, #-0x378] */
/* @0xe3394 vcvt.f64.s32 d6, s12 */
/* @0xe3398 ldr r3, [r6, r3] */
/* @0xe339c vldr d7, [r3] */
/* @0xe33a0 vneg.f64 d7, d7 */
/* @0xe33a4 vcmpe.f64 d6, d7 */
/* @0xe33a8 vmrs APSR_nzcv, fpscr */
/* @0xe33ac movpl r0, #0 */
/* @0xe33b0 movmi r0, #1 */
/* @0xe33b4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe33b8 cmp r11, #66 */
/* @0xe33bc beq 0xe37b4 <_Z5DoSetjPhPKhP6VMExec+0x17a0> */
/* ── 未支持的类型组合：只有 K=4（!=）返回 1（e33f0），其余返回 0（e33e8） */
/* @0xe33c0 sub r9, r9, #1 */
/* @0xe33c4 cmp r9, #5 */
/* @0xe33c8 addls pc, pc, r9, lsl #2 */
/* @0xe33cc b 0xe3cc4 <_Z5DoSetjPhPKhP6VMExec+0x1cb0> */
/* @0xe33d0 b 0xe33e8 <_Z5DoSetjPhPKhP6VMExec+0x13d4> */
/* @0xe33d4 b 0xe33e8 <_Z5DoSetjPhPKhP6VMExec+0x13d4> */
/* @0xe33d8 b 0xe33e8 <_Z5DoSetjPhPKhP6VMExec+0x13d4> */
/* @0xe33dc b 0xe33f0 <_Z5DoSetjPhPKhP6VMExec+0x13dc> */
/* @0xe33e0 b 0xe33e8 <_Z5DoSetjPhPKhP6VMExec+0x13d4> */
/* @0xe33e4 b 0xe33e8 <_Z5DoSetjPhPKhP6VMExec+0x13d4> */
/* @0xe33e8 mov r0, #0 */
/* @0xe33ec b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe33f0 mov r0, #1 */
/* @0xe33f4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe33f8 ldrd r0, r1, [r10] */
/* @0xe33fc sub r9, r9, #1 */
/* @0xe3400 bl 0x319164 <__floatdidf> */
/* @0xe3404 vldr d7, [r4] */
/* @0xe3408 vmov d6, r0, r1 */
/* @0xe340c vsub.f64 d7, d7, d6 */
/* @0xe3410 cmp r9, #5 */
/* @0xe3414 addls pc, pc, r9, lsl #2 */
/* @0xe3418 b 0xe3cb4 <_Z5DoSetjPhPKhP6VMExec+0x1ca0> */
/* @0xe341c b 0xe3500 <_Z5DoSetjPhPKhP6VMExec+0x14ec> */
/* @0xe3420 b 0xe34e0 <_Z5DoSetjPhPKhP6VMExec+0x14cc> */
/* @0xe3424 b 0xe34ac <_Z5DoSetjPhPKhP6VMExec+0x1498> */
/* @0xe3428 b 0xe3478 <_Z5DoSetjPhPKhP6VMExec+0x1464> */
/* @0xe342c b 0xe3454 <_Z5DoSetjPhPKhP6VMExec+0x1440> */
/* @0xe3430 b 0xe3434 <_Z5DoSetjPhPKhP6VMExec+0x1420> */
/* @0xe3434 ldr r3, [pc, #-0x41c] */
/* @0xe3438 ldr r3, [r6, r3] */
/* @0xe343c vldr d6, [r3] */
/* @0xe3440 vcmpe.f64 d7, d6 */
/* @0xe3444 vmrs APSR_nzcv, fpscr */
/* @0xe3448 movle r0, #0 */
/* @0xe344c movgt r0, #1 */
/* @0xe3450 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3454 ldr r3, [pc, #-0x43c] */
/* @0xe3458 ldr r3, [r6, r3] */
/* @0xe345c vldr d6, [r3] */
/* @0xe3460 vneg.f64 d6, d6 */
/* @0xe3464 vcmpe.f64 d7, d6 */
/* @0xe3468 vmrs APSR_nzcv, fpscr */
/* @0xe346c movlt r0, #0 */
/* @0xe3470 movge r0, #1 */
/* @0xe3474 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3478 ldr r3, [pc, #-0x460] */
/* @0xe347c ldr r3, [r6, r3] */
/* @0xe3480 vldr d6, [r3] */
/* @0xe3484 vneg.f64 d5, d6 */
/* @0xe3488 vcmpe.f64 d7, d5 */
/* @0xe348c vmrs APSR_nzcv, fpscr */
/* @0xe3490 movmi r0, #1 */
/* @0xe3494 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3498 vcmpe.f64 d7, d6 */
/* @0xe349c vmrs APSR_nzcv, fpscr */
/* @0xe34a0 movle r0, #0 */
/* @0xe34a4 movgt r0, #1 */
/* @0xe34a8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe34ac ldr r3, [pc, #-0x494] */
/* @0xe34b0 ldr r3, [r6, r3] */
/* @0xe34b4 vldr d6, [r3] */
/* @0xe34b8 vneg.f64 d5, d6 */
/* @0xe34bc vcmpe.f64 d7, d5 */
/* @0xe34c0 vmrs APSR_nzcv, fpscr */
/* @0xe34c4 movlt r0, #0 */
/* @0xe34c8 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe34cc vcmpe.f64 d7, d6 */
/* @0xe34d0 vmrs APSR_nzcv, fpscr */
/* @0xe34d4 movhi r0, #0 */
/* @0xe34d8 movls r0, #1 */
/* @0xe34dc b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe34e0 ldr r3, [pc, #-0x4c8] */
/* @0xe34e4 ldr r3, [r6, r3] */
/* @0xe34e8 vldr d6, [r3] */
/* @0xe34ec vcmpe.f64 d7, d6 */
/* @0xe34f0 vmrs APSR_nzcv, fpscr */
/* @0xe34f4 movhi r0, #0 */
/* @0xe34f8 movls r0, #1 */
/* @0xe34fc b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3500 ldr r3, [pc, #-0x4e8] */
/* @0xe3504 ldr r3, [r6, r3] */
/* @0xe3508 vldr d6, [r3] */
/* @0xe350c vneg.f64 d6, d6 */
/* @0xe3510 vcmpe.f64 d7, d6 */
/* @0xe3514 vmrs APSR_nzcv, fpscr */
/* @0xe3518 movpl r0, #0 */
/* @0xe351c movmi r0, #1 */
/* @0xe3520 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3524 ldrd r0, r1, [r4] */
/* @0xe3528 sub r9, r9, #1 */
/* @0xe352c bl 0x319164 <__floatdidf> */
/* @0xe3530 vldr d7, [r10] */
/* @0xe3534 vmov d6, r0, r1 */
/* @0xe3538 vsub.f64 d7, d6, d7 */
/* @0xe353c cmp r9, #5 */
/* @0xe3540 addls pc, pc, r9, lsl #2 */
/* @0xe3544 b 0xe3c04 <_Z5DoSetjPhPKhP6VMExec+0x1bf0> */
/* @0xe3548 b 0xe362c <_Z5DoSetjPhPKhP6VMExec+0x1618> */
/* @0xe354c b 0xe360c <_Z5DoSetjPhPKhP6VMExec+0x15f8> */
/* @0xe3550 b 0xe35d8 <_Z5DoSetjPhPKhP6VMExec+0x15c4> */
/* @0xe3554 b 0xe35a4 <_Z5DoSetjPhPKhP6VMExec+0x1590> */
/* @0xe3558 b 0xe3580 <_Z5DoSetjPhPKhP6VMExec+0x156c> */
/* @0xe355c b 0xe3560 <_Z5DoSetjPhPKhP6VMExec+0x154c> */
/* @0xe3560 ldr r3, [pc, #-0x548] */
/* @0xe3564 ldr r3, [r6, r3] */
/* @0xe3568 vldr d6, [r3] */
/* @0xe356c vcmpe.f64 d7, d6 */
/* @0xe3570 vmrs APSR_nzcv, fpscr */
/* @0xe3574 movle r0, #0 */
/* @0xe3578 movgt r0, #1 */
/* @0xe357c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3580 ldr r3, [pc, #-0x568] */
/* @0xe3584 ldr r3, [r6, r3] */
/* @0xe3588 vldr d6, [r3] */
/* @0xe358c vneg.f64 d6, d6 */
/* @0xe3590 vcmpe.f64 d7, d6 */
/* @0xe3594 vmrs APSR_nzcv, fpscr */
/* @0xe3598 movlt r0, #0 */
/* @0xe359c movge r0, #1 */
/* @0xe35a0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe35a4 ldr r3, [pc, #-0x58c] */
/* @0xe35a8 ldr r3, [r6, r3] */
/* @0xe35ac vldr d6, [r3] */
/* @0xe35b0 vneg.f64 d5, d6 */
/* @0xe35b4 vcmpe.f64 d7, d5 */
/* @0xe35b8 vmrs APSR_nzcv, fpscr */
/* @0xe35bc movmi r0, #1 */
/* @0xe35c0 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe35c4 vcmpe.f64 d7, d6 */
/* @0xe35c8 vmrs APSR_nzcv, fpscr */
/* @0xe35cc movle r0, #0 */
/* @0xe35d0 movgt r0, #1 */
/* @0xe35d4 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe35d8 ldr r3, [pc, #-0x5c0] */
/* @0xe35dc ldr r3, [r6, r3] */
/* @0xe35e0 vldr d6, [r3] */
/* @0xe35e4 vneg.f64 d5, d6 */
/* @0xe35e8 vcmpe.f64 d7, d5 */
/* @0xe35ec vmrs APSR_nzcv, fpscr */
/* @0xe35f0 movlt r0, #0 */
/* @0xe35f4 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe35f8 vcmpe.f64 d7, d6 */
/* @0xe35fc vmrs APSR_nzcv, fpscr */
/* @0xe3600 movhi r0, #0 */
/* @0xe3604 movls r0, #1 */
/* @0xe3608 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe360c ldr r3, [pc, #-0x5f4] */
/* @0xe3610 ldr r3, [r6, r3] */
/* @0xe3614 vldr d6, [r3] */
/* @0xe3618 vcmpe.f64 d7, d6 */
/* @0xe361c vmrs APSR_nzcv, fpscr */
/* @0xe3620 movhi r0, #0 */
/* @0xe3624 movls r0, #1 */
/* @0xe3628 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe362c ldr r3, [pc, #-0x614] */
/* @0xe3630 ldr r3, [r6, r3] */
/* @0xe3634 vldr d6, [r3] */
/* @0xe3638 vneg.f64 d6, d6 */
/* @0xe363c vcmpe.f64 d7, d6 */
/* @0xe3640 vmrs APSR_nzcv, fpscr */
/* @0xe3644 movpl r0, #0 */
/* @0xe3648 movmi r0, #1 */
/* @0xe364c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3650 ldr r2, [r4] */
/* @0xe3654 sub r9, r9, #1 */
/* @0xe3658 ldr r3, [r10] */
/* @0xe365c cmp r2, #0 */
/* @0xe3660 rsbeq r3, r3, #0 */
/* @0xe3664 rsbne r3, r3, #1 */
/* @0xe3668 cmp r9, #5 */
/* @0xe366c addls pc, pc, r9, lsl #2 */
/* @0xe3670 b 0xe3c64 <_Z5DoSetjPhPKhP6VMExec+0x1c50> */
/* @0xe3674 b 0xe3780 <_Z5DoSetjPhPKhP6VMExec+0x176c> */
/* @0xe3678 b 0xe3758 <_Z5DoSetjPhPKhP6VMExec+0x1744> */
/* @0xe367c b 0xe371c <_Z5DoSetjPhPKhP6VMExec+0x1708> */
/* @0xe3680 b 0xe36e0 <_Z5DoSetjPhPKhP6VMExec+0x16cc> */
/* @0xe3684 b 0xe36b4 <_Z5DoSetjPhPKhP6VMExec+0x16a0> */
/* @0xe3688 b 0xe368c <_Z5DoSetjPhPKhP6VMExec+0x1678> */
/* @0xe368c vmov s15, r3 */
/* @0xe3690 ldr r3, [pc, #-0x678] */
/* @0xe3694 vcvt.f64.s32 d6, s15 */
/* @0xe3698 ldr r3, [r6, r3] */
/* @0xe369c vldr d7, [r3] */
/* @0xe36a0 vcmpe.f64 d6, d7 */
/* @0xe36a4 vmrs APSR_nzcv, fpscr */
/* @0xe36a8 movle r0, #0 */
/* @0xe36ac movgt r0, #1 */
/* @0xe36b0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe36b4 vmov s15, r3 */
/* @0xe36b8 ldr r2, [pc, #-0x6a0] */
/* @0xe36bc vcvt.f64.s32 d6, s15 */
/* @0xe36c0 ldr r3, [r6, r2] */
/* @0xe36c4 vldr d7, [r3] */
/* @0xe36c8 vneg.f64 d7, d7 */
/* @0xe36cc vcmpe.f64 d6, d7 */
/* @0xe36d0 vmrs APSR_nzcv, fpscr */
/* @0xe36d4 movlt r0, #0 */
/* @0xe36d8 movge r0, #1 */
/* @0xe36dc b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe36e0 vmov s15, r3 */
/* @0xe36e4 ldr r2, [pc, #-0x6cc] */
/* @0xe36e8 vcvt.f64.s32 d6, s15 */
/* @0xe36ec ldr r3, [r6, r2] */
/* @0xe36f0 vldr d7, [r3] */
/* @0xe36f4 vneg.f64 d5, d7 */
/* @0xe36f8 vcmpe.f64 d6, d5 */
/* @0xe36fc vmrs APSR_nzcv, fpscr */
/* @0xe3700 movmi r0, #1 */
/* @0xe3704 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3708 vcmpe.f64 d6, d7 */
/* @0xe370c vmrs APSR_nzcv, fpscr */
/* @0xe3710 movle r0, #0 */
/* @0xe3714 movgt r0, #1 */
/* @0xe3718 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe371c vmov s15, r3 */
/* @0xe3720 ldr r2, [pc, #-0x708] */
/* @0xe3724 vcvt.f64.s32 d6, s15 */
/* @0xe3728 ldr r3, [r6, r2] */
/* @0xe372c vldr d7, [r3] */
/* @0xe3730 vneg.f64 d5, d7 */
/* @0xe3734 vcmpe.f64 d6, d5 */
/* @0xe3738 vmrs APSR_nzcv, fpscr */
/* @0xe373c movlt r0, #0 */
/* @0xe3740 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3744 vcmpe.f64 d6, d7 */
/* @0xe3748 vmrs APSR_nzcv, fpscr */
/* @0xe374c movhi r0, #0 */
/* @0xe3750 movls r0, #1 */
/* @0xe3754 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3758 vmov s15, r3 */
/* @0xe375c ldr r3, [pc, #-0x744] */
/* @0xe3760 vcvt.f64.s32 d6, s15 */
/* @0xe3764 ldr r3, [r6, r3] */
/* @0xe3768 vldr d7, [r3] */
/* @0xe376c vcmpe.f64 d6, d7 */
/* @0xe3770 vmrs APSR_nzcv, fpscr */
/* @0xe3774 movhi r0, #0 */
/* @0xe3778 movls r0, #1 */
/* @0xe377c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3780 vmov s15, r3 */
/* @0xe3784 ldr r2, [pc, #-0x76c] */
/* @0xe3788 vcvt.f64.s32 d6, s15 */
/* @0xe378c ldr r3, [r6, r2] */
/* @0xe3790 vldr d7, [r3] */
/* @0xe3794 vneg.f64 d7, d7 */
/* @0xe3798 vcmpe.f64 d6, d7 */
/* @0xe379c vmrs APSR_nzcv, fpscr */
/* @0xe37a0 movpl r0, #0 */
/* @0xe37a4 movmi r0, #1 */
/* @0xe37a8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe37ac cmp r11, #36 */
/* @0xe37b0 bne 0xe33c0 <_Z5DoSetjPhPKhP6VMExec+0x13ac> */
/* @0xe37b4 ldr r2, [r4] */
/* @0xe37b8 sub r9, r9, #1 */
/* @0xe37bc ldr r3, [r10] */
/* @0xe37c0 rsb r3, r3, r2 */
/* @0xe37c4 cmp r9, #5 */
/* @0xe37c8 addls pc, pc, r9, lsl #2 */
/* @0xe37cc b 0xe3c54 <_Z5DoSetjPhPKhP6VMExec+0x1c40> */
/* @0xe37d0 b 0xe38dc <_Z5DoSetjPhPKhP6VMExec+0x18c8> */
/* @0xe37d4 b 0xe38b4 <_Z5DoSetjPhPKhP6VMExec+0x18a0> */
/* @0xe37d8 b 0xe3878 <_Z5DoSetjPhPKhP6VMExec+0x1864> */
/* @0xe37dc b 0xe383c <_Z5DoSetjPhPKhP6VMExec+0x1828> */
/* @0xe37e0 b 0xe3810 <_Z5DoSetjPhPKhP6VMExec+0x17fc> */
/* @0xe37e4 b 0xe37e8 <_Z5DoSetjPhPKhP6VMExec+0x17d4> */
/* @0xe37e8 vmov s15, r3 */
/* @0xe37ec ldr r3, [pc, #-0x7d4] */
/* @0xe37f0 vcvt.f64.s32 d6, s15 */
/* @0xe37f4 ldr r3, [r6, r3] */
/* @0xe37f8 vldr d7, [r3] */
/* @0xe37fc vcmpe.f64 d6, d7 */
/* @0xe3800 vmrs APSR_nzcv, fpscr */
/* @0xe3804 movle r0, #0 */
/* @0xe3808 movgt r0, #1 */
/* @0xe380c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3810 vmov s15, r3 */
/* @0xe3814 ldr r2, [pc, #-0x7fc] */
/* @0xe3818 vcvt.f64.s32 d6, s15 */
/* @0xe381c ldr r3, [r6, r2] */
/* @0xe3820 vldr d7, [r3] */
/* @0xe3824 vneg.f64 d7, d7 */
/* @0xe3828 vcmpe.f64 d6, d7 */
/* @0xe382c vmrs APSR_nzcv, fpscr */
/* @0xe3830 movlt r0, #0 */
/* @0xe3834 movge r0, #1 */
/* @0xe3838 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe383c vmov s15, r3 */
/* @0xe3840 ldr r2, [pc, #-0x828] */
/* @0xe3844 vcvt.f64.s32 d6, s15 */
/* @0xe3848 ldr r3, [r6, r2] */
/* @0xe384c vldr d7, [r3] */
/* @0xe3850 vneg.f64 d5, d7 */
/* @0xe3854 vcmpe.f64 d6, d5 */
/* @0xe3858 vmrs APSR_nzcv, fpscr */
/* @0xe385c movmi r0, #1 */
/* @0xe3860 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3864 vcmpe.f64 d6, d7 */
/* @0xe3868 vmrs APSR_nzcv, fpscr */
/* @0xe386c movle r0, #0 */
/* @0xe3870 movgt r0, #1 */
/* @0xe3874 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3878 vmov s15, r3 */
/* @0xe387c ldr r2, [pc, #-0x864] */
/* @0xe3880 vcvt.f64.s32 d6, s15 */
/* @0xe3884 ldr r3, [r6, r2] */
/* @0xe3888 vldr d7, [r3] */
/* @0xe388c vneg.f64 d5, d7 */
/* @0xe3890 vcmpe.f64 d6, d5 */
/* @0xe3894 vmrs APSR_nzcv, fpscr */
/* @0xe3898 movlt r0, #0 */
/* @0xe389c blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe38a0 vcmpe.f64 d6, d7 */
/* @0xe38a4 vmrs APSR_nzcv, fpscr */
/* @0xe38a8 movhi r0, #0 */
/* @0xe38ac movls r0, #1 */
/* @0xe38b0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe38b4 vmov s15, r3 */
/* @0xe38b8 ldr r3, [pc, #-0x8a0] */
/* @0xe38bc vcvt.f64.s32 d6, s15 */
/* @0xe38c0 ldr r3, [r6, r3] */
/* @0xe38c4 vldr d7, [r3] */
/* @0xe38c8 vcmpe.f64 d6, d7 */
/* @0xe38cc vmrs APSR_nzcv, fpscr */
/* @0xe38d0 movhi r0, #0 */
/* @0xe38d4 movls r0, #1 */
/* @0xe38d8 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe38dc vmov s15, r3 */
/* @0xe38e0 ldr r2, [pc, #-0x8c8] */
/* @0xe38e4 vcvt.f64.s32 d6, s15 */
/* @0xe38e8 ldr r3, [r6, r2] */
/* @0xe38ec vldr d7, [r3] */
/* @0xe38f0 vneg.f64 d7, d7 */
/* @0xe38f4 vcmpe.f64 d6, d7 */
/* @0xe38f8 vmrs APSR_nzcv, fpscr */
/* @0xe38fc movpl r0, #0 */
/* @0xe3900 movmi r0, #1 */
/* @0xe3904 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3908 ldrd r0, r1, [r4] */
/* @0xe390c sub r9, r9, #1 */
/* @0xe3910 ldrd r2, r3, [r10] */
/* @0xe3914 subs r0, r0, r2 */
/* @0xe3918 sbc r1, r1, r3 */
/* @0xe391c cmp r9, #5 */
/* @0xe3920 addls pc, pc, r9, lsl #2 */
/* @0xe3924 b 0xe3c34 <_Z5DoSetjPhPKhP6VMExec+0x1c20> */
/* @0xe3928 b 0xe3a34 <_Z5DoSetjPhPKhP6VMExec+0x1a20> */
/* @0xe392c b 0xe3a0c <_Z5DoSetjPhPKhP6VMExec+0x19f8> */
/* @0xe3930 b 0xe39d0 <_Z5DoSetjPhPKhP6VMExec+0x19bc> */
/* @0xe3934 b 0xe3994 <_Z5DoSetjPhPKhP6VMExec+0x1980> */
/* @0xe3938 b 0xe3968 <_Z5DoSetjPhPKhP6VMExec+0x1954> */
/* @0xe393c b 0xe3940 <_Z5DoSetjPhPKhP6VMExec+0x192c> */
/* @0xe3940 bl 0x319164 <__floatdidf> */
/* @0xe3944 ldr r3, [pc, #-0x92c] */
/* @0xe3948 ldr r3, [r6, r3] */
/* @0xe394c vldr d7, [r3] */
/* @0xe3950 vmov d6, r0, r1 */
/* @0xe3954 vcmpe.f64 d6, d7 */
/* @0xe3958 vmrs APSR_nzcv, fpscr */
/* @0xe395c movle r0, #0 */
/* @0xe3960 movgt r0, #1 */
/* @0xe3964 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3968 bl 0x319164 <__floatdidf> */
/* @0xe396c ldr r3, [pc, #-0x954] */
/* @0xe3970 ldr r3, [r6, r3] */
/* @0xe3974 vldr d7, [r3] */
/* @0xe3978 vneg.f64 d7, d7 */
/* @0xe397c vmov d6, r0, r1 */
/* @0xe3980 vcmpe.f64 d6, d7 */
/* @0xe3984 vmrs APSR_nzcv, fpscr */
/* @0xe3988 movlt r0, #0 */
/* @0xe398c movge r0, #1 */
/* @0xe3990 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3994 bl 0x319164 <__floatdidf> */
/* @0xe3998 ldr r3, [pc, #-0x980] */
/* @0xe399c ldr r3, [r6, r3] */
/* @0xe39a0 vldr d7, [r3] */
/* @0xe39a4 vneg.f64 d5, d7 */
/* @0xe39a8 vmov d6, r0, r1 */
/* @0xe39ac vcmpe.f64 d6, d5 */
/* @0xe39b0 vmrs APSR_nzcv, fpscr */
/* @0xe39b4 movmi r0, #1 */
/* @0xe39b8 bmi 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe39bc vcmpe.f64 d6, d7 */
/* @0xe39c0 vmrs APSR_nzcv, fpscr */
/* @0xe39c4 movle r0, #0 */
/* @0xe39c8 movgt r0, #1 */
/* @0xe39cc b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe39d0 bl 0x319164 <__floatdidf> */
/* @0xe39d4 ldr r3, [pc, #-0x9bc] */
/* @0xe39d8 ldr r3, [r6, r3] */
/* @0xe39dc vldr d7, [r3] */
/* @0xe39e0 vneg.f64 d5, d7 */
/* @0xe39e4 vmov d6, r0, r1 */
/* @0xe39e8 vcmpe.f64 d6, d5 */
/* @0xe39ec vmrs APSR_nzcv, fpscr */
/* @0xe39f0 movlt r0, #0 */
/* @0xe39f4 blt 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe39f8 vcmpe.f64 d6, d7 */
/* @0xe39fc vmrs APSR_nzcv, fpscr */
/* @0xe3a00 movhi r0, #0 */
/* @0xe3a04 movls r0, #1 */
/* @0xe3a08 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3a0c bl 0x319164 <__floatdidf> */
/* @0xe3a10 ldr r3, [pc, #-0x9f8] */
/* @0xe3a14 ldr r3, [r6, r3] */
/* @0xe3a18 vldr d7, [r3] */
/* @0xe3a1c vmov d6, r0, r1 */
/* @0xe3a20 vcmpe.f64 d6, d7 */
/* @0xe3a24 vmrs APSR_nzcv, fpscr */
/* @0xe3a28 movhi r0, #0 */
/* @0xe3a2c movls r0, #1 */
/* @0xe3a30 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3a34 bl 0x319164 <__floatdidf> */
/* @0xe3a38 ldr r3, [pc, #-0xa20] */
/* @0xe3a3c ldr r3, [r6, r3] */
/* @0xe3a40 vldr d7, [r3] */
/* @0xe3a44 vneg.f64 d7, d7 */
/* @0xe3a48 vmov d6, r0, r1 */
/* @0xe3a4c vcmpe.f64 d6, d7 */
/* @0xe3a50 vmrs APSR_nzcv, fpscr */
/* @0xe3a54 movpl r0, #0 */
/* @0xe3a58 movmi r0, #1 */
/* @0xe3a5c b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3a60 ldr r0, [pc, #-0xa44] */
/* @0xe3a64 add r0, pc, r0 */
/* @0xe3a68 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe3a6c mov r0, r4 */
/* @0xe3a70 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* ── K=11 正体：F_JS_ToString(左) 转串，再 JS_GetProperty 查属性 */
/* @0xe3a74 add r7, sp, #32 */
/* @0xe3a78 mov r1, sp */
/* @0xe3a7c mov r0, r7 */
/* @0xe3a80 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0xe3a84 cmp r0, #1 */
/* @0xe3a88 beq 0xe3cf4 <_Z5DoSetjPhPKhP6VMExec+0x1ce0> */
/* @0xe3a8c cmp r0, #0 */
/* @0xe3a90 bne 0xe247c <_Z5DoSetjPhPKhP6VMExec+0x468> */
/* @0xe3a94 ldr r3, [sp, #0x20] */
/* @0xe3a98 mov r2, #5 */
/* @0xe3a9c ldr r0, [sp, #0x10] */
/* @0xe3aa0 add r1, sp, #48 */
/* @0xe3aa4 str r2, [sp, #0x3c] */
/* @0xe3aa8 sub r9, r8, #4 */
/* @0xe3aac ldr r2, [r3] */
/* @0xe3ab0 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* ── 结果 = (返回 RValue 的 tag != 0x00FFFFFF) → 0/1 */
/* @0xe3ab4 ldr r3, [sp, #0x3c] */
/* @0xe3ab8 bic r3, r3, #-16777216 */
/* @0xe3abc cmp r3, r4 */
/* @0xe3ac0 moveq r3, #0 */
/* @0xe3ac4 movne r3, #1 */
/* @0xe3ac8 str r3, [r8, #-0x4] */
/* @0xe3acc ldr r3, [sp, #0x2c] */
/* @0xe3ad0 sub r3, r3, #1 */
/* @0xe3ad4 bic r3, r3, #-16777216 */
/* @0xe3ad8 bic r3, r3, #3 */
/* @0xe3adc cmp r3, #0 */
/* @0xe3ae0 beq 0xe3d08 <_Z5DoSetjPhPKhP6VMExec+0x1cf4> */
/* @0xe3ae4 ldr r1, [sp, #0xc] */
/* @0xe3ae8 mov r3, #0 */
/* @0xe3aec str r3, [sp, #0x28] */
/* @0xe3af0 mov r2, #5 */
/* @0xe3af4 sub r1, r1, #1 */
/* @0xe3af8 str r3, [sp, #0x20] */
/* @0xe3afc bic r3, r1, #-16777216 */
/* @0xe3b00 str r2, [sp, #0x2c] */
/* @0xe3b04 bic r3, r3, #3 */
/* @0xe3b08 cmp r3, #0 */
/* @0xe3b0c beq 0xe3d14 <_Z5DoSetjPhPKhP6VMExec+0x1d00> */
/* @0xe3b10 ldr r1, [sp, #0x1c] */
/* @0xe3b14 mov r3, #0 */
/* @0xe3b18 str r3, [sp, #0x8] */
/* @0xe3b1c mov r2, #5 */
/* @0xe3b20 sub r1, r1, #1 */
/* @0xe3b24 str r3, [sp] */
/* @0xe3b28 bic r3, r1, #-16777216 */
/* @0xe3b2c str r2, [sp, #0xc] */
/* @0xe3b30 bic r3, r3, #3 */
/* @0xe3b34 cmp r3, #0 */
/* @0xe3b38 movne r0, r9 */
/* @0xe3b3c bne 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe3b40 mov r0, r6 */
/* @0xe3b44 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe3b48 mov r0, r9 */
/* @0xe3b4c b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe3b50 mov r0, r7 */
/* @0xe3b54 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe3b58 b 0xe25fc <_Z5DoSetjPhPKhP6VMExec+0x5e8> */
/* @0xe3b5c ldr r0, [pc, #-0xb3c] */
/* @0xe3b60 add r0, pc, r0 */
/* @0xe3b64 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe3b68 mov r0, r8 */
/* @0xe3b6c b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe3b70 rsbs r12, r0, #1 */
/* @0xe3b74 movlo r12, #0 */
/* @0xe3b78 tst r12, r2 */
/* @0xe3b7c beq 0xe3b90 <_Z5DoSetjPhPKhP6VMExec+0x1b7c> */
/* @0xe3b80 ldrb r2, [r1] */
/* @0xe3b84 cmp r2, #0 */
/* @0xe3b88 moveq r0, r2 */
/* @0xe3b8c beq 0xe3200 <_Z5DoSetjPhPKhP6VMExec+0x11ec> */
/* @0xe3b90 cmp r1, #0 */
/* @0xe3b94 movne r3, #0 */
/* @0xe3b98 andeq r3, r3, #1 */
/* @0xe3b9c cmp r3, #0 */
/* @0xe3ba0 beq 0xe3bb4 <_Z5DoSetjPhPKhP6VMExec+0x1ba0> */
/* @0xe3ba4 ldrb r3, [r0] */
/* @0xe3ba8 cmp r3, #0 */
/* @0xe3bac moveq r0, r3 */
/* @0xe3bb0 beq 0xe3200 <_Z5DoSetjPhPKhP6VMExec+0x11ec> */
/* @0xe3bb4 subs r0, r1, r0 */
/* @0xe3bb8 movne r0, #1 */
/* @0xe3bbc b 0xe3200 <_Z5DoSetjPhPKhP6VMExec+0x11ec> */
/* ── 各六路表的公共默认入口：把 [r7-4] 里已算好的差/整数布尔化后落 [r7-4] */
/* @0xe3bc0 vmrs APSR_nzcv, fpscr */
/* @0xe3bc4 moveq r3, #0 */
/* @0xe3bc8 movne r3, #1 */
/* @0xe3bcc str r3, [r8, #-0x4] */
/* @0xe3bd0 b 0xe210c <_Z5DoSetjPhPKhP6VMExec+0xf8> */
/* @0xe3bd4 ldr r0, [pc, #-0xbb0] */
/* @0xe3bd8 add r0, pc, r0 */
/* @0xe3bdc bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe3be0 mov r0, r8 */
/* @0xe3be4 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe3be8 mov r12, #1 */
/* @0xe3bec mov r0, r3 */
/* @0xe3bf0 b 0xe3b78 <_Z5DoSetjPhPKhP6VMExec+0x1b64> */
/* ── 0xe3bf4..0xe3cf0 = 16 个同构默认桩：ldr r0,[r7-4] / adds / movne #1 / b e28f0 */
/* @0xe3bf4 ldr r0, [r7, #-0x4] */
/* @0xe3bf8 adds r0, r0, #0 */
/* @0xe3bfc movne r0, #1 */
/* @0xe3c00 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c04 ldr r0, [r7, #-0x4] */
/* @0xe3c08 adds r0, r0, #0 */
/* @0xe3c0c movne r0, #1 */
/* @0xe3c10 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c14 ldr r0, [r7, #-0x4] */
/* @0xe3c18 adds r0, r0, #0 */
/* @0xe3c1c movne r0, #1 */
/* @0xe3c20 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c24 ldr r0, [r7, #-0x4] */
/* @0xe3c28 adds r0, r0, #0 */
/* @0xe3c2c movne r0, #1 */
/* @0xe3c30 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c34 ldr r0, [r7, #-0x4] */
/* @0xe3c38 adds r0, r0, #0 */
/* @0xe3c3c movne r0, #1 */
/* @0xe3c40 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c44 ldr r0, [r7, #-0x4] */
/* @0xe3c48 adds r0, r0, #0 */
/* @0xe3c4c movne r0, #1 */
/* @0xe3c50 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c54 ldr r0, [r7, #-0x4] */
/* @0xe3c58 adds r0, r0, #0 */
/* @0xe3c5c movne r0, #1 */
/* @0xe3c60 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c64 ldr r0, [r7, #-0x4] */
/* @0xe3c68 adds r0, r0, #0 */
/* @0xe3c6c movne r0, #1 */
/* @0xe3c70 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c74 ldr r0, [r7, #-0x4] */
/* @0xe3c78 adds r0, r0, #0 */
/* @0xe3c7c movne r0, #1 */
/* @0xe3c80 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c84 ldr r0, [r7, #-0x4] */
/* @0xe3c88 adds r0, r0, #0 */
/* @0xe3c8c movne r0, #1 */
/* @0xe3c90 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3c94 ldr r0, [r7, #-0x4] */
/* @0xe3c98 adds r0, r0, #0 */
/* @0xe3c9c movne r0, #1 */
/* @0xe3ca0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3ca4 ldr r0, [r7, #-0x4] */
/* @0xe3ca8 adds r0, r0, #0 */
/* @0xe3cac movne r0, #1 */
/* @0xe3cb0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3cb4 ldr r0, [r7, #-0x4] */
/* @0xe3cb8 adds r0, r0, #0 */
/* @0xe3cbc movne r0, #1 */
/* @0xe3cc0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3cc4 ldr r0, [r7, #-0x4] */
/* @0xe3cc8 adds r0, r0, #0 */
/* @0xe3ccc movne r0, #1 */
/* @0xe3cd0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3cd4 ldr r0, [r7, #-0x4] */
/* @0xe3cd8 adds r0, r0, #0 */
/* @0xe3cdc movne r0, #1 */
/* @0xe3ce0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3ce4 ldr r0, [r7, #-0x4] */
/* @0xe3ce8 adds r0, r0, #0 */
/* @0xe3cec movne r0, #1 */
/* @0xe3cf0 b 0xe28f0 <_Z5DoSetjPhPKhP6VMExec+0x8dc> */
/* @0xe3cf4 ldr r0, [pc, #-0xccc] */
/* @0xe3cf8 add r0, pc, r0 */
/* @0xe3cfc bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe3d00 mov r0, r8 */
/* @0xe3d04 b 0xe2154 <_Z5DoSetjPhPKhP6VMExec+0x140> */
/* @0xe3d08 mov r0, r7 */
/* @0xe3d0c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe3d10 b 0xe3ae4 <_Z5DoSetjPhPKhP6VMExec+0x1ad0> */
/* @0xe3d14 mov r0, sp */
/* @0xe3d18 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe3d1c b 0xe3b10 <_Z5DoSetjPhPKhP6VMExec+0x1afc> */
/* ── 类型表默认：r7 = r4（左操作数按 0 字节算） */
/* @0xe3d20 mov r7, r4 */
/* @0xe3d24 b 0xe2268 <_Z5DoSetjPhPKhP6VMExec+0x254> */
/* ── 类型表默认：r4 = r10（右操作数按 0 字节算） */
/* @0xe3d28 mov r4, r10 */
/* @0xe3d2c b 0xe2224 <_Z5DoSetjPhPKhP6VMExec+0x210> */
