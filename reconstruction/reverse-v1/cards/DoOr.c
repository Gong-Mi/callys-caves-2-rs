/* cally 逆向卡：DoOr（原版 libyoyo.so，armv7）
 * @func 0xdf804 0xe00d8  size 2260  565 条指令（含尾部 literal 池）
 * 级别: 正文（入口/两级 kind 分派/86 路消费表/69 路算术表/12 条算术核/bool 组合已证；
 *        pair 4 的读写槽位异常未证）
 * 符号: _Z4DoOrjPhPKhP6VMExec → uchar* DoOr(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   mode  = (arg >> 8) & 0xF          ; @0xdf804（tst r0,#3840 → bne 0xdf850）
 *   kindA = (arg >> 16) & 0xF         ; @0xdf824（and r2,r4,#15；r4 = uxtb(arg>>16)）
 *   kindB = (arg >> 20) & 0xF         ; @0xdf8f8（asr r2,r5,#4）
 *   pair  = kindA | (kindB << 4)      ; @0xdf93c（cmp r4,#85 的 86 路表索引）
 *
 * 寄存器角色：r9 = base、r11 = exec、r10 = opB 槽（= base+sizeA）、r6 = 新 sp、
 *             r8 = 结果槽、r7 = 待释放槽。
 * 操作数布局与 DoShr/DoMul/DoMod 同构：opA（kindA，位[19:16]）在 base+0，
 * opB（kindB，位[23:20]）在 base+sizeA。
 *
 * 结论（新增五条硬事实）：
 *   1. **`|` 在 real 上不是位运算，而是「转 int64 再 or」**：pair 0 走
 *      __fixdfdi(opA) / __fixdfdi(opB) → 64 位 orr → __floatdidf → 写回 double（@0xdfd24）。
 *      同理 real 与 int 的混搭 pair 2/3/32/48 都是「一侧 __fixdfdi、另一侧符号扩展，
 *      orr 后按需 __floatdidf」。即 GML 的 `|` 语义 = ToInt64(lhs) | ToInt64(rhs)。
 *   2. **int 结果按宽度定 tag**：pair 34（int32|int32）写 4 字节、tag 7（@0xdfdf8）；
 *      pair 35/50/51（任一侧 int64）写 8 字节、tag 10；pair 68（bool|bool）写 4 字节、tag **13**
 *      （@0xdfcd0）。real 结果 tag 0。
 *   3. **bool（kind 4）只在 DoOr 里被支持**：pair 64（real,bool）用
 *      `subs/rsbs/adcs` 把 bool 归一成 0/1 后与 int64(opA) orr（@0xdfd78）；
 *      pair 68（bool,bool）先判 opB，opB==0 时再用 `adds r3,#0 / movne r3,#1` 判 opA
 *      （@0xdfcd0 / @0xdff04）—— 逻辑上是「A||B 归一成 0/1」。
 *      **异常**：pair 4（bool,real）的核（@0xdfe20）读的是 opB 槽 [r10] 而非 opA 槽 [r9]，
 *      与 pair 64/68 的对称性不符，按指令如实记录，语义待证。
 *   4. **kindA 表**（@0xdf82c）：{0,3} → 8 字节槽（opB 槽 = base+8）、{1,2,4} → 4 字节槽
 *      （base+4）、{5} → 间接、{6} → 字符串报错；kindB 表（@0xdf900）同构，{6} 亦报错。
 *      **kind 1 在本算子里与 2/4 同槽但没有任何 pair 合法**（落到 VMError）。
 *   5. **mode≠0 的常量路径把两侧都转 int32 再 or**（@0xdf8d0 / @0xdfe60 两次
 *      F_JS_ToInt32 → vcvt.s32.f64 两次 → orr → 结果按 double 存、tag 0）。这与变量路径的
 *      64 位 orr 不同：**常量路径会截断成 32 位**。
 * open：pair 4 的槽位异常；kind 1 的真实类型（4 字节槽、无合法 pair）；
 *       常量路径为什么用 ToInt32 而变量路径用 ToInt64（是否对应 `|` 与 `||` 的两种 opcode）。
 *
 * ── 本批补证：按位或（逐条锚在下方）──
 *   位运算统一走 JS 语义：F_JS_ToInt32 取整 → __fixdfdi 把 double 转 int64（×5）→ 逻辑/位移 → __floatdidf ×3 回 double
 *   VMError ×13 / JSThrowReferenceError ×2：非数值操作数与非法位型走错误路径
 *   open 1 位宽与掩码位置
 *   open 2 与 DoAnd 是否共用同一段转换代码（三张卡的调用清单完全相同，说明极可能共用模板）
 * ── alu_path_scan 复核（2026-10-29）：逻辑指令就地确认 —— orr×18（内联），配合 ToInt32/fixdfdi/floatdidf 的转换面
 *   仍 open：位宽（32 还是 64）与掩码位置
 */
/* ---- 入口：mode=(arg>>8)&0xF；mode≠0 → 常量装箱路径 ---- */
/* @0x00df804 tst r0, #3840 */
/* @0x00df808 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x00df80c lsr r5, r0, #16 */
/* @0x00df810 sub sp, sp, #68 */
/* @0x00df814 mov r9, r1 */
/* @0x00df818 mov r11, r3 */
/* @0x00df81c bne 0xdf850 <_Z4DoOrjPhPKhP6VMExec+0x4c> */
/* ---- kindA 表：{0,3}→8 字节槽，{1,2,4}→4 字节槽，{5}→间接，{6}→字符串报错 ---- */
/* @0x00df820 uxtb r4, r5 */
/* @0x00df824 and r2, r4, #15 */
/* @0x00df828 cmp r2, #6 */
/* @0x00df82c addls pc, pc, r2, lsl #2 */
/* @0x00df830 b 0xe0080 <_Z4DoOrjPhPKhP6VMExec+0x87c> */
/* @0x00df834 b 0xdf8f0 <_Z4DoOrjPhPKhP6VMExec+0xec> */
/* @0x00df838 b 0xdfc40 <_Z4DoOrjPhPKhP6VMExec+0x43c> */
/* @0x00df83c b 0xdfc40 <_Z4DoOrjPhPKhP6VMExec+0x43c> */
/* @0x00df840 b 0xdf8f0 <_Z4DoOrjPhPKhP6VMExec+0xec> */
/* @0x00df844 b 0xdfc40 <_Z4DoOrjPhPKhP6VMExec+0x43c> */
/* @0x00df848 b 0xdfc4c <_Z4DoOrjPhPKhP6VMExec+0x448> */
/* @0x00df84c b 0xdfc94 <_Z4DoOrjPhPKhP6VMExec+0x490> */
/* ---- 常量路径：boxType(帧+0x10,kindA,base) / boxType(sp,kindB,前次返回) ---- */
/* @0x00df850 add r4, sp, #16 */
/* @0x00df854 uxtb r5, r5 */
/* @0x00df858 mov r2, r1 */
/* @0x00df85c and r1, r5, #15 */
/* @0x00df860 mov r0, r4 */
/* @0x00df864 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0x00df868 lsr r1, r5, #4 */
/* @0x00df86c mov r2, r0 */
/* @0x00df870 mov r0, sp */
/* @0x00df874 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* 校验两枚 RValue 的 +12 字低 24 位是否全 1（0x00FFFFFF = 未解析引用标记） ---- */
/* @0x00df878 ldr r3, [sp, #0xc] */
/* @0x00df87c mvn r12, #-16777216 */
/* @0x00df880 and r3, r3, r12 */
/* @0x00df884 cmp r3, r12 */
/* @0x00df888 mov r6, r0 */
/* @0x00df88c beq 0xe0038 <_Z4DoOrjPhPKhP6VMExec+0x834> */
/* @0x00df890 ldr r3, [sp, #0x1c] */
/* @0x00df894 bic r3, r3, #-16777216 */
/* @0x00df898 cmp r3, r12 */
/* @0x00df89c beq 0xdfcbc <_Z4DoOrjPhPKhP6VMExec+0x4b8> */
/* F_JS_ToInt32(帧+0x20, sp) 与 F_JS_ToInt32(帧+0x30, 帧+0x10) ---- */
/* @0x00df8a0 add r5, sp, #32 */
/* @0x00df8a4 mov r1, sp */
/* @0x00df8a8 mov r2, #0 */
/* @0x00df8ac mov r3, #0 */
/* @0x00df8b0 mov r0, r5 */
/* @0x00df8b4 str r12, [sp, #0x2c] */
/* @0x00df8b8 str r12, [sp, #0x3c] */
/* @0x00df8bc mov r12, #0 */
/* @0x00df8c0 strd r2, r3, [sp, #32] */
/* @0x00df8c4 strd r2, r3, [sp, #48] */
/* @0x00df8c8 str r12, [sp, #0x28] */
/* @0x00df8cc str r12, [sp, #0x38] */
/* @0x00df8d0 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0x00df8d4 cmp r0, #1 */
/* @0x00df8d8 beq 0xe004c <_Z4DoOrjPhPKhP6VMExec+0x848> */
/* @0x00df8dc cmp r0, #0 */
/* @0x00df8e0 beq 0xdfe54 <_Z4DoOrjPhPKhP6VMExec+0x650> */
/* @0x00df8e4 mov r0, r6 */
/* @0x00df8e8 add sp, sp, #68 */
/* @0x00df8ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* kindA∈{0,3}：opB 槽 = base+8 */
/* @0x00df8f0 add r10, r1, #8 */
/* @0x00df8f4 mov r5, r4 */
/* ---- kindB 表：{0,3}→新 sp=opB+8，{1,2,4}→opB+4，{5}→间接，{6}→报错 ---- */
/* @0x00df8f8 asr r2, r5, #4 */
/* @0x00df8fc cmp r2, #6 */
/* @0x00df900 addls pc, pc, r2, lsl #2 */
/* @0x00df904 b 0xe008c <_Z4DoOrjPhPKhP6VMExec+0x888> */
/* @0x00df908 b 0xdfc38 <_Z4DoOrjPhPKhP6VMExec+0x434> */
/* @0x00df90c b 0xdfc30 <_Z4DoOrjPhPKhP6VMExec+0x42c> */
/* @0x00df910 b 0xdfc30 <_Z4DoOrjPhPKhP6VMExec+0x42c> */
/* @0x00df914 b 0xdfc38 <_Z4DoOrjPhPKhP6VMExec+0x434> */
/* @0x00df918 b 0xdfc30 <_Z4DoOrjPhPKhP6VMExec+0x42c> */
/* @0x00df91c b 0xdfbe8 <_Z4DoOrjPhPKhP6VMExec+0x3e4> */
/* @0x00df920 b 0xdf924 <_Z4DoOrjPhPKhP6VMExec+0x120> */
/* kindB=6：VMError("DoOr :2: ... Cannot operate on string type") */
/* @0x00df924 ldr r1, [pc, #0x768] */
/* @0x00df928 mov r0, r11 */
/* @0x00df92c mov r6, r10 */
/* @0x00df930 add r1, pc, r1 */
/* @0x00df934 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00df938 cmp r4, #85 */
/* ---- 86 路消费表（cmp #85）：新 sp r6 / 结果槽 r8 / 释放槽 r7 ---- */
/* @0x00df93c addls pc, pc, r4, lsl #2 */
/* @0x00df940 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df944 b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0x00df948 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df94c b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0x00df950 b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0x00df954 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df958 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0x00df95c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df960 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df964 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df968 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df96c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df970 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df974 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df978 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df97c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df980 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df984 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df988 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df98c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df990 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df994 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df998 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df99c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9a0 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9a4 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9a8 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9ac b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9b0 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9b4 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9b8 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9bc b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9c0 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9c4 b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0x00df9c8 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9cc b 0xdfa9c <_Z4DoOrjPhPKhP6VMExec+0x298> */
/* @0x00df9d0 b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0x00df9d4 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9d8 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0x00df9dc b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9e0 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9e4 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9e8 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9ec b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9f0 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9f4 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9f8 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00df9fc b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa00 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa04 b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0x00dfa08 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa0c b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0x00dfa10 b 0xdfbd8 <_Z4DoOrjPhPKhP6VMExec+0x3d4> */
/* @0x00dfa14 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa18 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0x00dfa1c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa20 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa24 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa28 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa2c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa30 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa34 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa38 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa3c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa40 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa44 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa48 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa4c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa50 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa54 b 0xdfa9c <_Z4DoOrjPhPKhP6VMExec+0x298> */
/* @0x00dfa58 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0x00dfa5c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa60 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa64 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa68 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa6c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa70 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa74 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa78 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa7c b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa80 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa84 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0x00dfa88 b 0xdfcb0 <_Z4DoOrjPhPKhP6VMExec+0x4ac> */
/* @0x00dfa8c b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0x00dfa90 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0x00dfa94 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* @0x00dfa98 b 0xdfbc8 <_Z4DoOrjPhPKhP6VMExec+0x3c4> */
/* pair=34 或 68：结果 4 字节，回退 4 ---- */
/* @0x00dfa9c sub r6, r6, #4 */
/* @0x00dfaa0 mov r7, #0 */
/* @0x00dfaa4 mov r8, r6 */
/* ---- 69 路算术表（cmp #68）；越界落到 0xdfbc4 ---- */
/* @0x00dfaa8 cmp r5, #68 */
/* @0x00dfaac addls pc, pc, r5, lsl #2 */
/* @0x00dfab0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfab4 b 0xdfd24 <_Z4DoOrjPhPKhP6VMExec+0x520> */
/* @0x00dfab8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfabc b 0xdfd54 <_Z4DoOrjPhPKhP6VMExec+0x550> */
/* @0x00dfac0 b 0xdfcec <_Z4DoOrjPhPKhP6VMExec+0x4e8> */
/* @0x00dfac4 b 0xdfe20 <_Z4DoOrjPhPKhP6VMExec+0x61c> */
/* @0x00dfac8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfacc b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfad0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfad4 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfad8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfadc b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfae0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfae4 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfae8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfaec b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfaf0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfaf4 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfaf8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfafc b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb00 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb04 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb08 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb0c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb10 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb14 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb18 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb1c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb20 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb24 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb28 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb2c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb30 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb34 b 0xdfe10 <_Z4DoOrjPhPKhP6VMExec+0x60c> */
/* @0x00dfb38 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb3c b 0xdfdf8 <_Z4DoOrjPhPKhP6VMExec+0x5f4> */
/* @0x00dfb40 b 0xdfddc <_Z4DoOrjPhPKhP6VMExec+0x5d8> */
/* @0x00dfb44 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb48 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb4c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb50 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb54 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb58 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb5c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb60 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb64 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb68 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb6c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb70 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb74 b 0xdfdcc <_Z4DoOrjPhPKhP6VMExec+0x5c8> */
/* @0x00dfb78 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb7c b 0xdfdb0 <_Z4DoOrjPhPKhP6VMExec+0x5ac> */
/* @0x00dfb80 b 0xdfd94 <_Z4DoOrjPhPKhP6VMExec+0x590> */
/* @0x00dfb84 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb88 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb8c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb90 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb94 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb98 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfb9c b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfba0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfba4 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfba8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfbac b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfbb0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfbb4 b 0xdfd78 <_Z4DoOrjPhPKhP6VMExec+0x574> */
/* @0x00dfbb8 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfbbc b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfbc0 b 0xdfe3c <_Z4DoOrjPhPKhP6VMExec+0x638> */
/* @0x00dfbc4 b 0xdfcd0 <_Z4DoOrjPhPKhP6VMExec+0x4cc> */
/* 间接 pair：回退 16 并释放一个 RValue ---- */
/* @0x00dfbc8 sub r7, r6, #16 */
/* @0x00dfbcc mov r8, r7 */
/* @0x00dfbd0 mov r6, r7 */
/* @0x00dfbd4 b 0xdfaa8 <_Z4DoOrjPhPKhP6VMExec+0x2a4> */
/* 8 字节结果：回退 8 ---- */
/* @0x00dfbd8 sub r6, r6, #8 */
/* @0x00dfbdc mov r7, #0 */
/* @0x00dfbe0 mov r8, r6 */
/* @0x00dfbe4 b 0xdfaa8 <_Z4DoOrjPhPKhP6VMExec+0x2a4> */
/* kindB=5：按 [opB+0xc] 的 tag 反推 kindB（改写高半字节） */
/* @0x00dfbe8 ldr r3, [r10, #0xc] */
/* @0x00dfbec cmp r3, #13 */
/* @0x00dfbf0 addls pc, pc, r3, lsl #2 */
/* @0x00dfbf4 b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0x00dfbf8 b 0xdff80 <_Z4DoOrjPhPKhP6VMExec+0x77c> */
/* @0x00dfbfc b 0xdff6c <_Z4DoOrjPhPKhP6VMExec+0x768> */
/* @0x00dfc00 b 0xdff58 <_Z4DoOrjPhPKhP6VMExec+0x754> */
/* @0x00dfc04 b 0xdff44 <_Z4DoOrjPhPKhP6VMExec+0x740> */
/* @0x00dfc08 b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0x00dfc0c b 0xdff30 <_Z4DoOrjPhPKhP6VMExec+0x72c> */
/* @0x00dfc10 b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0x00dfc14 b 0xdff24 <_Z4DoOrjPhPKhP6VMExec+0x720> */
/* @0x00dfc18 b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0x00dfc1c b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0x00dfc20 b 0xdff14 <_Z4DoOrjPhPKhP6VMExec+0x710> */
/* @0x00dfc24 b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0x00dfc28 b 0xe000c <_Z4DoOrjPhPKhP6VMExec+0x808> */
/* @0x00dfc2c b 0xdff80 <_Z4DoOrjPhPKhP6VMExec+0x77c> */
/* kindB∈{1,2,4}：新 sp = opB+4 */
/* @0x00dfc30 add r6, r10, #4 */
/* @0x00dfc34 b 0xdf938 <_Z4DoOrjPhPKhP6VMExec+0x134> */
/* kindB∈{0,3}：新 sp = opB+8 */
/* @0x00dfc38 add r6, r10, #8 */
/* @0x00dfc3c b 0xdf938 <_Z4DoOrjPhPKhP6VMExec+0x134> */
/* kindA∈{1,2,4}：opB 槽 = base+4 */
/* @0x00dfc40 add r10, r1, #4 */
/* @0x00dfc44 mov r5, r4 */
/* @0x00dfc48 b 0xdf8f8 <_Z4DoOrjPhPKhP6VMExec+0xf4> */
/* kindA=5：按 [base+0xc] 的 tag 反推 kindA（改写低半字节） */
/* @0x00dfc4c ldr r3, [r1, #0xc] */
/* @0x00dfc50 cmp r3, #13 */
/* @0x00dfc54 addls pc, pc, r3, lsl #2 */
/* @0x00dfc58 b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0x00dfc5c b 0xe0004 <_Z4DoOrjPhPKhP6VMExec+0x800> */
/* @0x00dfc60 b 0xdffec <_Z4DoOrjPhPKhP6VMExec+0x7e8> */
/* @0x00dfc64 b 0xdffd4 <_Z4DoOrjPhPKhP6VMExec+0x7d0> */
/* @0x00dfc68 b 0xdffbc <_Z4DoOrjPhPKhP6VMExec+0x7b8> */
/* @0x00dfc6c b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0x00dfc70 b 0xdffa4 <_Z4DoOrjPhPKhP6VMExec+0x7a0> */
/* @0x00dfc74 b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0x00dfc78 b 0xdff98 <_Z4DoOrjPhPKhP6VMExec+0x794> */
/* @0x00dfc7c b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0x00dfc80 b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0x00dfc84 b 0xdff88 <_Z4DoOrjPhPKhP6VMExec+0x784> */
/* @0x00dfc88 b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0x00dfc8c b 0xe0020 <_Z4DoOrjPhPKhP6VMExec+0x81c> */
/* @0x00dfc90 b 0xe0004 <_Z4DoOrjPhPKhP6VMExec+0x800> */
/* kindA=6：VMError("DoOr :: ... Cannot operate on string type") */
/* @0x00dfc94 ldr r1, [pc, #0x3fc] */
/* @0x00dfc98 mov r0, r3 */
/* @0x00dfc9c mov r5, r4 */
/* @0x00dfca0 mov r10, r9 */
/* @0x00dfca4 add r1, pc, r1 */
/* @0x00dfca8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dfcac b 0xdf8f8 <_Z4DoOrjPhPKhP6VMExec+0xf4> */
/* 非法 pair：结果槽/释放槽清零 ---- */
/* @0x00dfcb0 mov r8, #0 */
/* @0x00dfcb4 mov r7, r8 */
/* @0x00dfcb8 b 0xdfaa8 <_Z4DoOrjPhPKhP6VMExec+0x2a4> */
/* opB 未解析引用 → JSThrowReferenceError("could not find variable after '|'") */
/* @0x00dfcbc ldr r0, [pc, #0x3d8] */
/* @0x00dfcc0 add r0, pc, r0 */
/* @0x00dfcc4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0x00dfcc8 mov r0, r6 */
/* @0x00dfccc b 0xdf8e8 <_Z4DoOrjPhPKhP6VMExec+0xe4> */
/* pair 68 (bool,bool)：先判 opB ---- */
/* @0x00dfcd0 ldr r3, [r10] */
/* @0x00dfcd4 cmp r3, #0 */
/* @0x00dfcd8 movne r3, #1 */
/* @0x00dfcdc beq 0xdff04 <_Z4DoOrjPhPKhP6VMExec+0x700> */
/* @0x00dfce0 str r3, [r8] */
/* @0x00dfce4 mov r12, #13 */
/* @0x00dfce8 b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* pair 3 (kA=3 int64 / kB=0 real)：__fixdfdi(opB) 后与 opA 的 int64 orr → double ---- */
/* @0x00dfcec ldrd r0, r1, [r10] */
/* @0x00dfcf0 bl 0x3194a0 <__fixdfdi> */
/* @0x00dfcf4 ldrd r2, r3, [r9] */
/* @0x00dfcf8 orr r0, r0, r2 */
/* @0x00dfcfc orr r1, r1, r3 */
/* @0x00dfd00 bl 0x319164 <__floatdidf> */
/* @0x00dfd04 mov r12, #0 */
/* @0x00dfd08 strd r0, r1, [r8] */
/* 收尾：写结果 tag（r12=0/7/10/13）→ 返回新 sp r6 ---- */
/* @0x00dfd0c cmp r7, #0 */
/* @0x00dfd10 beq 0xdf8e4 <_Z4DoOrjPhPKhP6VMExec+0xe0> */
/* @0x00dfd14 mov r0, r6 */
/* @0x00dfd18 str r12, [r7, #0xc] */
/* @0x00dfd1c add sp, sp, #68 */
/* @0x00dfd20 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* pair 0 (real,real)：两侧 __fixdfdi → 64 位 orr → __floatdidf ---- */
/* @0x00dfd24 ldrd r0, r1, [r10] */
/* @0x00dfd28 bl 0x3194a0 <__fixdfdi> */
/* @0x00dfd2c mov r4, r0 */
/* @0x00dfd30 mov r5, r1 */
/* @0x00dfd34 ldrd r0, r1, [r9] */
/* @0x00dfd38 bl 0x3194a0 <__fixdfdi> */
/* @0x00dfd3c orr r0, r0, r4 */
/* @0x00dfd40 orr r1, r1, r5 */
/* @0x00dfd44 bl 0x319164 <__floatdidf> */
/* @0x00dfd48 mov r12, #0 */
/* @0x00dfd4c strd r0, r1, [r8] */
/* @0x00dfd50 b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* pair 2 (kA=2 int32 / kB=0 real)：opB double→int64，opA int32 符号扩展后 orr ---- */
/* @0x00dfd54 ldrd r0, r1, [r10] */
/* @0x00dfd58 bl 0x3194a0 <__fixdfdi> */
/* @0x00dfd5c ldr r3, [r9] */
/* @0x00dfd60 orr r0, r0, r3 */
/* @0x00dfd64 orr r1, r1, r3, asr #31 */
/* @0x00dfd68 bl 0x319164 <__floatdidf> */
/* @0x00dfd6c mov r12, #0 */
/* @0x00dfd70 strd r0, r1, [r8] */
/* @0x00dfd74 b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* pair 64 (real,bool)：bool 归一 0/1（subs/rsbs/adcs）后与 int64(opA) orr ---- */
/* @0x00dfd78 ldr r4, [r10] */
/* @0x00dfd7c mov r5, #0 */
/* @0x00dfd80 ldrd r0, r1, [r9] */
/* @0x00dfd84 subs r2, r4, #1 */
/* @0x00dfd88 rsbs r4, r2, #0 */
/* @0x00dfd8c adcs r4, r4, r2 */
/* @0x00dfd90 b 0xdfd38 <_Z4DoOrjPhPKhP6VMExec+0x534> */
/* pair 51 (int64,int64)：直接 64 位 orr，tag 10 ---- */
/* @0x00dfd94 ldrd r0, r1, [r10] */
/* @0x00dfd98 mov r12, #10 */
/* @0x00dfd9c ldrd r2, r3, [r9] */
/* @0x00dfda0 orr r2, r2, r0 */
/* @0x00dfda4 orr r3, r3, r1 */
/* @0x00dfda8 strd r2, r3, [r8] */
/* @0x00dfdac b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* pair 50 (int64,int32)：opA int32 符号扩展后 64 位 orr，tag 10 ---- */
/* @0x00dfdb0 ldr r1, [r9] */
/* @0x00dfdb4 mov r12, #10 */
/* @0x00dfdb8 ldrd r2, r3, [r10] */
/* @0x00dfdbc orr r2, r2, r1 */
/* @0x00dfdc0 orr r3, r3, r1, asr #31 */
/* @0x00dfdc4 strd r2, r3, [r8] */
/* @0x00dfdc8 b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* pair 48 (int64,real)：__fixdfdi(opB) 后 64 位 orr ---- */
/* @0x00dfdcc ldrd r0, r1, [r9] */
/* @0x00dfdd0 bl 0x3194a0 <__fixdfdi> */
/* @0x00dfdd4 ldrd r2, r3, [r10] */
/* @0x00dfdd8 b 0xdfcf8 <_Z4DoOrjPhPKhP6VMExec+0x4f4> */
/* pair 35 (int32,int64)：64 位 orr，tag 10 ---- */
/* @0x00dfddc ldr r1, [r10] */
/* @0x00dfde0 mov r12, #10 */
/* @0x00dfde4 ldrd r2, r3, [r9] */
/* @0x00dfde8 orr r2, r2, r1 */
/* @0x00dfdec orr r3, r3, r1, asr #31 */
/* @0x00dfdf0 strd r2, r3, [r8] */
/* @0x00dfdf4 b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* pair 34 (int32,int32)：orr → 4 字节结果，tag 7 ---- */
/* @0x00dfdf8 ldr r2, [r10] */
/* @0x00dfdfc mov r12, #7 */
/* @0x00dfe00 ldr r3, [r9] */
/* @0x00dfe04 orr r3, r2, r3 */
/* @0x00dfe08 str r3, [r8] */
/* @0x00dfe0c b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* pair 32 (int32,real)：__fixdfdi(opB) 后与 opA 符号扩展 orr ---- */
/* @0x00dfe10 ldr r4, [r10] */
/* @0x00dfe14 ldrd r0, r1, [r9] */
/* @0x00dfe18 asr r5, r4, #31 */
/* @0x00dfe1c b 0xdfd38 <_Z4DoOrjPhPKhP6VMExec+0x534> */
/* pair 4 (kA=4 bool / kB=0 real)：此处读的是 opB 槽 [r10]（与 pair 64 不对称，语义待证） ---- */
/* @0x00dfe20 ldr r4, [r10] */
/* @0x00dfe24 mov r5, #0 */
/* @0x00dfe28 ldrd r0, r1, [r10] */
/* @0x00dfe2c subs r3, r4, #1 */
/* @0x00dfe30 rsbs r4, r3, #0 */
/* @0x00dfe34 adcs r4, r4, r3 */
/* @0x00dfe38 b 0xdfd38 <_Z4DoOrjPhPKhP6VMExec+0x534> */
/* 算术表默认项：VMError("DoOr :: Execution Error") ---- */
/* @0x00dfe3c ldr r1, [pc, #0x25c] */
/* @0x00dfe40 mov r0, r11 */
/* @0x00dfe44 add r1, pc, r1 */
/* @0x00dfe48 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dfe4c mov r12, #0 */
/* @0x00dfe50 b 0xdfd0c <_Z4DoOrjPhPKhP6VMExec+0x508> */
/* @0x00dfe54 add r7, sp, #48 */
/* @0x00dfe58 mov r1, r4 */
/* @0x00dfe5c mov r0, r7 */
/* F_JS_ToInt32(帧+0x30, 帧+0x10)：opB 也转 int32 ---- */
/* @0x00dfe60 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0x00dfe64 cmp r0, #1 */
/* @0x00dfe68 beq 0xe006c <_Z4DoOrjPhPKhP6VMExec+0x868> */
/* @0x00dfe6c cmp r0, #0 */
/* @0x00dfe70 bne 0xdf8e4 <_Z4DoOrjPhPKhP6VMExec+0xe0> */
/* @0x00dfe74 str r0, [r6, #-0x4] */
/* @0x00dfe78 sub r4, r6, #16 */
/* 常量路径核心：vcvt.s32.f64 ×2 → orr → vcvt.f64.s32 回 double ---- */
/* @0x00dfe7c vldr d7, [sp, #32] */
/* @0x00dfe80 vldr d6, [sp, #48] */
/* @0x00dfe84 vcvt.s32.f64 s14, d7 */
/* @0x00dfe88 ldr r3, [sp, #0x2c] */
/* @0x00dfe8c sub r3, r3, #1 */
/* @0x00dfe90 bic r3, r3, #-16777216 */
/* @0x00dfe94 bic r3, r3, #3 */
/* @0x00dfe98 cmp r3, #0 */
/* @0x00dfe9c vcvt.s32.f64 s11, d6 */
/* @0x00dfea0 vmov r3, s14 */
/* @0x00dfea4 vmov r2, s11 */
/* @0x00dfea8 orr r2, r2, r3 */
/* @0x00dfeac vmov s15, r2 */
/* @0x00dfeb0 vcvt.f64.s32 d7, s15 */
/* @0x00dfeb4 vmov r2, r3, d7 */
/* @0x00dfeb8 vstr s14, [r6, #-16] */
/* @0x00dfebc str r3, [r6, #-0xc] */
/* @0x00dfec0 beq 0xe0060 <_Z4DoOrjPhPKhP6VMExec+0x85c> */
/* @0x00dfec4 ldr r1, [sp, #0x3c] */
/* @0x00dfec8 mov r3, #0 */
/* @0x00dfecc str r3, [sp, #0x28] */
/* @0x00dfed0 mov r2, #5 */
/* @0x00dfed4 sub r1, r1, #1 */
/* @0x00dfed8 str r3, [sp, #0x20] */
/* @0x00dfedc bic r3, r1, #-16777216 */
/* @0x00dfee0 str r2, [sp, #0x2c] */
/* @0x00dfee4 bic r3, r3, #3 */
/* @0x00dfee8 cmp r3, #0 */
/* @0x00dfeec movne r0, r4 */
/* @0x00dfef0 bne 0xdf8e8 <_Z4DoOrjPhPKhP6VMExec+0xe4> */
/* @0x00dfef4 mov r0, r7 */
/* @0x00dfef8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x00dfefc mov r0, r4 */
/* @0x00dff00 b 0xdf8e8 <_Z4DoOrjPhPKhP6VMExec+0xe4> */
/* pair 68：opB==0 时改用 adds/movne 判 opA ---- */
/* @0x00dff04 ldr r3, [r9] */
/* @0x00dff08 adds r3, r3, #0 */
/* @0x00dff0c movne r3, #1 */
/* @0x00dff10 b 0xdfce0 <_Z4DoOrjPhPKhP6VMExec+0x4dc> */
/* 间接 kindB：tag 10 → kindB=3（0x30） */
/* @0x00dff14 and r5, r5, #15 */
/* @0x00dff18 orr r5, r5, #48 */
/* @0x00dff1c add r6, r10, #16 */
/* @0x00dff20 b 0xdf938 <_Z4DoOrjPhPKhP6VMExec+0x134> */
/* 间接 kindB：tag 7 → kindB=2（0x20） */
/* @0x00dff24 and r5, r5, #15 */
/* @0x00dff28 orr r5, r5, #32 */
/* @0x00dff2c b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* 间接 kindB：tag 5 → "undefined value" */
/* @0x00dff30 ldr r1, [pc, #0x16c] */
/* @0x00dff34 mov r0, r11 */
/* @0x00dff38 add r1, pc, r1 */
/* @0x00dff3c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dff40 b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* 间接 kindB：tag 3 → "illegal pointer use" */
/* @0x00dff44 ldr r1, [pc, #0x15c] */
/* @0x00dff48 mov r0, r11 */
/* @0x00dff4c add r1, pc, r1 */
/* @0x00dff50 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dff54 b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* 间接 kindB：tag 2 → "illegal array use" */
/* @0x00dff58 ldr r1, [pc, #0x14c] */
/* @0x00dff5c mov r0, r11 */
/* @0x00dff60 add r1, pc, r1 */
/* @0x00dff64 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dff68 b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* 间接 kindB：tag 1 → 字符串报错 */
/* @0x00dff6c ldr r1, [pc, #0x13c] */
/* @0x00dff70 mov r0, r11 */
/* @0x00dff74 add r1, pc, r1 */
/* @0x00dff78 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dff7c b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* 间接 kindB：tag 0/13 → kindB=0（real） */
/* @0x00dff80 and r5, r5, #15 */
/* @0x00dff84 b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* 间接 kindA：tag 10 → kindA=3，opB 槽回 base+16 ---- */
/* @0x00dff88 and r5, r5, #240 */
/* @0x00dff8c orr r5, r5, #3 */
/* @0x00dff90 add r10, r9, #16 */
/* @0x00dff94 b 0xdf8f8 <_Z4DoOrjPhPKhP6VMExec+0xf4> */
/* 间接 kindA：tag 7 → kindA=2 ---- */
/* @0x00dff98 and r5, r5, #240 */
/* @0x00dff9c orr r5, r5, #2 */
/* @0x00dffa0 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* 间接 kindA：tag 5 → "undefined value" */
/* @0x00dffa4 ldr r1, [pc, #0x108] */
/* @0x00dffa8 mov r0, r11 */
/* @0x00dffac mov r5, r4 */
/* @0x00dffb0 add r1, pc, r1 */
/* @0x00dffb4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dffb8 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* 间接 kindA：tag 3 → "illegal pointer use" */
/* @0x00dffbc ldr r1, [pc, #0xf4] */
/* @0x00dffc0 mov r0, r11 */
/* @0x00dffc4 mov r5, r4 */
/* @0x00dffc8 add r1, pc, r1 */
/* @0x00dffcc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dffd0 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* 间接 kindA：tag 2 → "illegal array use" */
/* @0x00dffd4 ldr r1, [pc, #0xe0] */
/* @0x00dffd8 mov r0, r11 */
/* @0x00dffdc mov r5, r4 */
/* @0x00dffe0 add r1, pc, r1 */
/* @0x00dffe4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dffe8 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* 间接 kindA：tag 1 → 字符串报错 */
/* @0x00dffec ldr r1, [pc, #0xcc] */
/* @0x00dfff0 mov r0, r11 */
/* @0x00dfff4 mov r5, r4 */
/* @0x00dfff8 add r1, pc, r1 */
/* @0x00dfffc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e0000 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* 间接 kindA：tag 0/13 → kindA=0 ---- */
/* @0x00e0004 and r5, r4, #240 */
/* @0x00e0008 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* 间接 kindB："Malformed variable" */
/* @0x00e000c ldr r1, [pc, #0xb0] */
/* @0x00e0010 mov r0, r11 */
/* @0x00e0014 add r1, pc, r1 */
/* @0x00e0018 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e001c b 0xdff1c <_Z4DoOrjPhPKhP6VMExec+0x718> */
/* 间接 kindA："Malformed variable" */
/* @0x00e0020 ldr r1, [pc, #0xa0] */
/* @0x00e0024 mov r0, r11 */
/* @0x00e0028 mov r5, r4 */
/* @0x00e002c add r1, pc, r1 */
/* @0x00e0030 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e0034 b 0xdff90 <_Z4DoOrjPhPKhP6VMExec+0x78c> */
/* opA 未解析引用 → JSThrowReferenceError("could not find variable before '|'") */
/* @0x00e0038 ldr r0, [pc, #0x8c] */
/* @0x00e003c add r0, pc, r0 */
/* @0x00e0040 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0x00e0044 mov r0, r6 */
/* @0x00e0048 b 0xdf8e8 <_Z4DoOrjPhPKhP6VMExec+0xe4> */
/* ToInt32 失败 → JSThrowTypeError("DoOr - could not convert lhs expr to a number") */
/* @0x00e004c ldr r0, [pc, #0x7c] */
/* @0x00e0050 add r0, pc, r0 */
/* @0x00e0054 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x00e0058 mov r0, r6 */
/* @0x00e005c b 0xdf8e8 <_Z4DoOrjPhPKhP6VMExec+0xe4> */
/* @0x00e0060 mov r0, r5 */
/* @0x00e0064 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x00e0068 b 0xdfec4 <_Z4DoOrjPhPKhP6VMExec+0x6c0> */
/* 右侧失败 → "DoOr - could not convert rhs expr to a number" */
/* @0x00e006c ldr r0, [pc, #0x60] */
/* @0x00e0070 add r0, pc, r0 */
/* @0x00e0074 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x00e0078 mov r0, r6 */
/* @0x00e007c b 0xdf8e8 <_Z4DoOrjPhPKhP6VMExec+0xe4> */
/* @0x00e0080 mov r5, r4 */
/* @0x00e0084 mov r10, r1 */
/* @0x00e0088 b 0xdf8f8 <_Z4DoOrjPhPKhP6VMExec+0xf4> */
/* @0x00e008c mov r6, r10 */
/* @0x00e0090 b 0xdf938 <_Z4DoOrjPhPKhP6VMExec+0x134> */
/* @0x00e0094 eoreq r4, r5, r12, lsr r1 */
/* @0x00e0098 .word 0x00253cdc */
/* @0x00e009c eoreq r3, r5, r12, lsr r12 */
/* @0x00e00a0 .word 0x00253cd8 */
/* @0x00e00a4 mlaeq r5, r0, r11, r3 */
/* @0x00e00a8 eoreq r3, r5, r12, asr r11 */
/* @0x00e00ac eoreq r3, r5, r4, lsl #23 */
/* @0x00e00b0 .word 0x00253af8 */
/* @0x00e00b4 eoreq r3, r5, r12, lsr #20 */
/* @0x00e00b8 .word 0x002539f4 */
/* @0x00e00bc eoreq r3, r5, r4, asr r10 */
/* @0x00e00c0 eoreq r3, r5, r0, lsl #20 */
/* @0x00e00c4 eoreq r3, r5, r12, ror #21 */
/* @0x00e00c8 eoreq r3, r5, r4, lsr #20 */
/* @0x00e00cc mlaeq r5, r12, r8, r3 */
/* @0x00e00d0 .word 0x002538d0 */
/* @0x00e00d4 eoreq r3, r5, r0, ror #17 */
