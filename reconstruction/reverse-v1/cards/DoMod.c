/* cally 逆向卡：DoMod（原版 libyoyo.so，armv7）
 * @func 0xde5e8 0xdef6c  size 2436  609 条指令（含尾部 literal 池）
 * 级别: 正文（入口/两级 kind 分派/86 路消费表/52 路算术表/9 条算术核/除零与 NaN 语义已证；
 *        kind 1、kind 4 的语义未证）
 * 符号: _Z5DoModjPhPKhP6VMExec → uchar* DoMod(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   mode  = (arg >> 8) & 0xF          ; @0xde5e8（ubfx r2,r0,#8,#4；cmp r2,#1 → beq 0xdeb68）
 *   kindA = (arg >> 16) & 0xF         ; @0xde610（and r3,r4,#15；r4 = uxtb(arg>>16)）
 *   kindB = (arg >> 20) & 0xF         ; @0xde654（asr r3,r5,#4）
 *   pair  = kindA | (kindB << 4)      ; @0xde698（cmp r4,#85 的 86 路表索引）
 *
 * 寄存器角色：r11 = base、r10 = exec、r9 = opB 槽（= base+sizeA）、r6 = 新 sp、
 *             r8 = 结果槽、r7 = 待释放槽；帧 = push 9 寄存器 + vpush {d8} + sub sp,#68。
 * 操作数布局与 DoShr/DoMul 同构：opA（kindA，位[19:16]）在 base+0 = **除数**，
 * opB（kindB，位[23:20]）在 base+sizeA = **被除数**（@0xdec38 处 fmod(opB, opA)）。
 *
 * 结论（新增五条硬事实）：
 *   1. **浮点除零阈值是 1e-10**：常量池 0xded88 = 0x3DDB7CDFD9D7BDBB（= 1e-10），
 *      @0xde9c4 用 vabs + vcmpe 判 |opA| < 1e-10 → VMError("DoMod :: Divide by zero")；
 *      @0xdea38 / @0xdead4 用 bmi 走同一条报错。整数侧则用 `cmp #0` / `orrs` 判零
 *      （@0xdeaa8 / @0xdea74 / @0xdeb08 / @0xdeb2c），报错走 @0xdec20（另一处同串）。
 *   2. **整数取模直接调 AEABI**：pair 34 用 __aeabi_idivmod（余数在 r1，结果 tag 7），
 *      pair 35/50/51 用 __aeabi_ldivmod（余数在 r2/r3，结果 tag 10）——
 *      即 int32%int32 得 32 位、只要有一侧 int64 就得 64 位。
 *   3. **kindA 表**（@0xde618）：kindA∈{0,3} → opA 占 8 字节、opB 槽 = base+8；
 *      kindA∈{1,2,4} → 4 字节、opB 槽 = base+4；kindA=5 → 间接；**kindA≥6 → 字符串报错**
 *      （"DoMod :: Execution Engine - Cannot operate on string type"，表外 7..15 也落到同一条）。
 *      kindB 表（@0xde65c）同构：{0,3} → 新 sp = opB+8，{1,2,4} → opB+4，5 → 间接，6 → 同串报错。
 *   4. **间接操作数按 tag 反推 kind**（14 路表，tag 在 +12）：tag 0/13 → real、tag 7 → int32、
 *      tag 10 → int64、tag 1 → string（报错）；tag 2 → "illegal array use"、
 *      tag 3 → "illegal pointer use"、tag 5 → "undefined value"、其余 → "Malformed variable"。
 *   5. **常量路径（mode==1）自己实现 fmod 的 IEEE 边角**（@0xdec8c 起）：vcmp d7,d7 捕 NaN、
 *      yyisinf 判 ∞、清符号位判 ±0，命中则把结果置为 0x7FFFFFFFFFFFFFFF 的 NaN 位型
 *      （@0xdef38：mvn r2,#0 / mvn r3,#-2147483648）；正常则 fmod(opB,opA) 后原样存 double。
 *      这与 mode 0 的 "除零 → VMError" 策略不同：**常量路径给 NaN，变量路径报错**。
 * open：kind 1 / kind 4 的语义（4 字节槽但与任何 pair 都不合法）；pair 52..85 落到 @0xde8e0
 *       后会跳回 @0xde804 重新分派（正常路径下含 5 的 pair 都会被改写，故不可达）；
 *       为什么 mode 只区分 1（2..15 与 0 同路）。
 *
 * ── 本批补证：取模（GML `mod` / `%`）（逐条锚在下方）──
 *   0xde5e8 起：fmod@plt ×6（实数路径，走 libm 的 fmod，不是截断取整）
 *   __aeabi_ldivmod ×3（整型路径：int64 除法取余，余数符号随被除数）
 *   __floatdidf ×2（int64 → double 回装箱）
 *   VMError ×15 —— 本函数错误面最大的一个，格式串未解（open）
 *   open 1 实数路径用 fmod 而整型路径用 ldivmod：两条路的「负数取模」语义不同，Rust 实现要分别对
 *   open 2 15 处 VMError 的触发条件与文案
 */
/* ---- 入口：mode=(arg>>8)&0xF，只有 mode==1 走常量装箱 ---- */
/* @0x00de5e8 ubfx r2, r0, #0x8, #0x4 */
/* @0x00de5ec lsr r0, r0, #16 */
/* @0x00de5f0 cmp r2, #1 */
/* @0x00de5f4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x00de5f8 vpush {d8} */
/* @0x00de5fc mov r11, r1 */
/* @0x00de600 sub sp, sp, #68 */
/* @0x00de604 mov r10, r3 */
/* @0x00de608 uxtb r4, r0 */
/* @0x00de60c beq 0xdeb68 <_Z5DoModjPhPKhP6VMExec+0x580> */
/* ---- kindA 表：{0,3}→8 字节槽，{1,2,4}→4 字节槽，{5}→间接，{6}→字符串报错 ---- */
/* @0x00de610 and r3, r4, #15 */
/* @0x00de614 cmp r3, #6 */
/* @0x00de618 addls pc, pc, r3, lsl #2 */
/* @0x00de61c b 0xdef58 <_Z5DoModjPhPKhP6VMExec+0x970> */
/* @0x00de620 b 0xde958 <_Z5DoModjPhPKhP6VMExec+0x370> */
/* @0x00de624 b 0xde964 <_Z5DoModjPhPKhP6VMExec+0x37c> */
/* @0x00de628 b 0xde964 <_Z5DoModjPhPKhP6VMExec+0x37c> */
/* @0x00de62c b 0xde958 <_Z5DoModjPhPKhP6VMExec+0x370> */
/* @0x00de630 b 0xde964 <_Z5DoModjPhPKhP6VMExec+0x37c> */
/* @0x00de634 b 0xde970 <_Z5DoModjPhPKhP6VMExec+0x388> */
/* @0x00de638 b 0xde63c <_Z5DoModjPhPKhP6VMExec+0x54> */
/* kindA=6：VMError("DoMod :: Execution Engine - Cannot operate on string type") */
/* @0x00de63c ldr r1, [pc, #0x74c] */
/* @0x00de640 mov r0, r10 */
/* @0x00de644 mov r5, r4 */
/* @0x00de648 mov r9, r11 */
/* @0x00de64c add r1, pc, r1 */
/* @0x00de650 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* ---- kindB 表：{0,3}→新 sp=opB+8，{1,2,4}→opB+4，{5}→间接，{6}→同串报错 ---- */
/* @0x00de654 asr r3, r5, #4 */
/* @0x00de658 cmp r3, #6 */
/* @0x00de65c addls pc, pc, r3, lsl #2 */
/* @0x00de660 b 0xdef64 <_Z5DoModjPhPKhP6VMExec+0x97c> */
/* @0x00de664 b 0xde950 <_Z5DoModjPhPKhP6VMExec+0x368> */
/* @0x00de668 b 0xde948 <_Z5DoModjPhPKhP6VMExec+0x360> */
/* @0x00de66c b 0xde948 <_Z5DoModjPhPKhP6VMExec+0x360> */
/* @0x00de670 b 0xde950 <_Z5DoModjPhPKhP6VMExec+0x368> */
/* @0x00de674 b 0xde948 <_Z5DoModjPhPKhP6VMExec+0x360> */
/* @0x00de678 b 0xde900 <_Z5DoModjPhPKhP6VMExec+0x318> */
/* @0x00de67c b 0xde680 <_Z5DoModjPhPKhP6VMExec+0x98> */
/* kindB=6：字符串报错 */
/* @0x00de680 ldr r1, [pc, #0x70c] */
/* @0x00de684 mov r0, r10 */
/* @0x00de688 mov r6, r9 */
/* @0x00de68c add r1, pc, r1 */
/* @0x00de690 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* ---- 86 路消费表（cmp #85）：新 sp r6 / 结果槽 r8 / 释放槽 r7 ---- */
/* @0x00de694 cmp r4, #85 */
/* @0x00de698 addls pc, pc, r4, lsl #2 */
/* @0x00de69c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6a0 b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0x00de6a4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6a8 b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0x00de6ac b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0x00de6b0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6b4 b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0x00de6b8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6bc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6c0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6c4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6c8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6cc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6d0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6d4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6d8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6dc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6e0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6e4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6e8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6ec b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6f0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6f4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6f8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de6fc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de700 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de704 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de708 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de70c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de710 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de714 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de718 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de71c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de720 b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0x00de724 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de728 b 0xde7f8 <_Z5DoModjPhPKhP6VMExec+0x210> */
/* @0x00de72c b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0x00de730 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de734 b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0x00de738 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de73c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de740 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de744 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de748 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de74c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de750 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de754 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de758 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de75c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de760 b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0x00de764 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de768 b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0x00de76c b 0xde8f0 <_Z5DoModjPhPKhP6VMExec+0x308> */
/* @0x00de770 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de774 b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0x00de778 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de77c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de780 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de784 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de788 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de78c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de790 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de794 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de798 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de79c b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7a0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7a4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7a8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7ac b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7b0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7b4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7b8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7bc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7c0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7c4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7c8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7cc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7d0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7d4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7d8 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7dc b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7e0 b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0x00de7e4 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7e8 b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0x00de7ec b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* @0x00de7f0 b 0xde9b8 <_Z5DoModjPhPKhP6VMExec+0x3d0> */
/* @0x00de7f4 b 0xde8e0 <_Z5DoModjPhPKhP6VMExec+0x2f8> */
/* pair=34（int32%int32）：结果 4 字节，回退 4 */
/* @0x00de7f8 sub r6, r6, #4 */
/* @0x00de7fc mov r7, #0 */
/* @0x00de800 mov r8, r6 */
/* ---- 52 路算术表（cmp #51）；越界落到 0xde80c 的 VMError ---- */
/* @0x00de804 cmp r5, #51 */
/* @0x00de808 addls pc, pc, r5, lsl #2 */
/* @0x00de80c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de810 b 0xde9c4 <_Z5DoModjPhPKhP6VMExec+0x3dc> */
/* @0x00de814 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de818 b 0xdeaa8 <_Z5DoModjPhPKhP6VMExec+0x4c0> */
/* @0x00de81c b 0xdea74 <_Z5DoModjPhPKhP6VMExec+0x48c> */
/* @0x00de820 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de824 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de828 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de82c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de830 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de834 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de838 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de83c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de840 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de844 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de848 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de84c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de850 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de854 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de858 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de85c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de860 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de864 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de868 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de86c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de870 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de874 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de878 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de87c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de880 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de884 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de888 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de88c b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de890 b 0xdea38 <_Z5DoModjPhPKhP6VMExec+0x450> */
/* @0x00de894 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de898 b 0xdea20 <_Z5DoModjPhPKhP6VMExec+0x438> */
/* @0x00de89c b 0xdeb08 <_Z5DoModjPhPKhP6VMExec+0x520> */
/* @0x00de8a0 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8a4 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8a8 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8ac b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8b0 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8b4 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8b8 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8bc b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8c0 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8c4 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8c8 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8cc b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8d0 b 0xdead4 <_Z5DoModjPhPKhP6VMExec+0x4ec> */
/* @0x00de8d4 b 0xdeb50 <_Z5DoModjPhPKhP6VMExec+0x568> */
/* @0x00de8d8 b 0xdeb2c <_Z5DoModjPhPKhP6VMExec+0x544> */
/* @0x00de8dc b 0xde9f4 <_Z5DoModjPhPKhP6VMExec+0x40c> */
/* 间接 pair：回退 16 并释放一个 RValue */
/* @0x00de8e0 sub r7, r6, #16 */
/* @0x00de8e4 mov r8, r7 */
/* @0x00de8e8 mov r6, r7 */
/* @0x00de8ec b 0xde804 <_Z5DoModjPhPKhP6VMExec+0x21c> */
/* 8 字节结果：回退 8 */
/* @0x00de8f0 sub r6, r6, #8 */
/* @0x00de8f4 mov r7, #0 */
/* @0x00de8f8 mov r8, r6 */
/* @0x00de8fc b 0xde804 <_Z5DoModjPhPKhP6VMExec+0x21c> */
/* kindB=5：按 [opB+0xc] 的 tag 反推 kindB（改写高半字节） */
/* @0x00de900 ldr r3, [r9, #0xc] */
/* @0x00de904 cmp r3, #13 */
/* @0x00de908 addls pc, pc, r3, lsl #2 */
/* @0x00de90c b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0x00de910 b 0xdeebc <_Z5DoModjPhPKhP6VMExec+0x8d4> */
/* @0x00de914 b 0xdeea8 <_Z5DoModjPhPKhP6VMExec+0x8c0> */
/* @0x00de918 b 0xdee94 <_Z5DoModjPhPKhP6VMExec+0x8ac> */
/* @0x00de91c b 0xdee80 <_Z5DoModjPhPKhP6VMExec+0x898> */
/* @0x00de920 b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0x00de924 b 0xdee6c <_Z5DoModjPhPKhP6VMExec+0x884> */
/* @0x00de928 b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0x00de92c b 0xdee60 <_Z5DoModjPhPKhP6VMExec+0x878> */
/* @0x00de930 b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0x00de934 b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0x00de938 b 0xdee50 <_Z5DoModjPhPKhP6VMExec+0x868> */
/* @0x00de93c b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0x00de940 b 0xdeedc <_Z5DoModjPhPKhP6VMExec+0x8f4> */
/* @0x00de944 b 0xdeebc <_Z5DoModjPhPKhP6VMExec+0x8d4> */
/* kindB∈{1,2,4}：新 sp = opB+4 */
/* @0x00de948 add r6, r9, #4 */
/* @0x00de94c b 0xde694 <_Z5DoModjPhPKhP6VMExec+0xac> */
/* kindB∈{0,3}：新 sp = opB+8 */
/* @0x00de950 add r6, r9, #8 */
/* @0x00de954 b 0xde694 <_Z5DoModjPhPKhP6VMExec+0xac> */
/* kindA∈{0,3}：opB 槽 = base+8 */
/* @0x00de958 add r9, r1, #8 */
/* @0x00de95c mov r5, r4 */
/* @0x00de960 b 0xde654 <_Z5DoModjPhPKhP6VMExec+0x6c> */
/* kindA∈{1,2,4}：opB 槽 = base+4 */
/* @0x00de964 add r9, r1, #4 */
/* @0x00de968 mov r5, r4 */
/* @0x00de96c b 0xde654 <_Z5DoModjPhPKhP6VMExec+0x6c> */
/* kindA=5：按 [base+0xc] 的 tag 反推 kindA（改写低半字节） */
/* @0x00de970 ldr r3, [r1, #0xc] */
/* @0x00de974 cmp r3, #13 */
/* @0x00de978 addls pc, pc, r3, lsl #2 */
/* @0x00de97c b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0x00de980 b 0xdee3c <_Z5DoModjPhPKhP6VMExec+0x854> */
/* @0x00de984 b 0xdee24 <_Z5DoModjPhPKhP6VMExec+0x83c> */
/* @0x00de988 b 0xdee0c <_Z5DoModjPhPKhP6VMExec+0x824> */
/* @0x00de98c b 0xdedf4 <_Z5DoModjPhPKhP6VMExec+0x80c> */
/* @0x00de990 b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0x00de994 b 0xdeddc <_Z5DoModjPhPKhP6VMExec+0x7f4> */
/* @0x00de998 b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0x00de99c b 0xded78 <_Z5DoModjPhPKhP6VMExec+0x790> */
/* @0x00de9a0 b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0x00de9a4 b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0x00de9a8 b 0xdee44 <_Z5DoModjPhPKhP6VMExec+0x85c> */
/* @0x00de9ac b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0x00de9b0 b 0xdeec4 <_Z5DoModjPhPKhP6VMExec+0x8dc> */
/* @0x00de9b4 b 0xdee3c <_Z5DoModjPhPKhP6VMExec+0x854> */
/* 非法 pair：结果槽/释放槽清零 */
/* @0x00de9b8 mov r8, #0 */
/* @0x00de9bc mov r7, r8 */
/* @0x00de9c0 b 0xde804 <_Z5DoModjPhPKhP6VMExec+0x21c> */
/* pair 0 (real,real)：|opA| < 1e-10 → 除零；否则 fmod(opB,opA) @0xdec38 */
/* @0x00de9c4 vldr d7, [r11] */
/* @0x00de9c8 vabs.f64 d5, d7 */
/* @0x00de9cc vldr d6, [pc, #948] */
/* @0x00de9d0 vcmpe.f64 d5, d6 */
/* @0x00de9d4 vmrs APSR_nzcv, fpscr */
/* @0x00de9d8 bpl 0xdec38 <_Z5DoModjPhPKhP6VMExec+0x650> */
/* VMError("DoMod :: Divide by zero") ---- */
/* @0x00de9dc ldr r1, [pc, #0x3b4] */
/* @0x00de9e0 mov r0, r10 */
/* @0x00de9e4 add r1, pc, r1 */
/* @0x00de9e8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00de9ec mov r12, #0 */
/* @0x00de9f0 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* pair 51 (int64,int64)：__aeabi_ldivmod → 余数 r2/r3，tag 10 */
/* @0x00de9f4 ldrd r0, r1, [r9] */
/* @0x00de9f8 ldrd r2, r3, [r11] */
/* @0x00de9fc bl 0x319414 <__aeabi_ldivmod> */
/* @0x00dea00 mov r12, #10 */
/* @0x00dea04 strd r2, r3, [r8] */
/* 收尾：写结果 tag（r12=0/7/10）→ 返回新 sp r6 */
/* @0x00dea08 cmp r7, #0 */
/* @0x00dea0c strne r12, [r7, #0xc] */
/* @0x00dea10 mov r0, r6 */
/* @0x00dea14 add sp, sp, #68 */
/* @0x00dea18 vpop {d8} */
/* @0x00dea1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* pair 34 (int32,int32)：__aeabi_idivmod → 余数 r1，tag 7 */
/* @0x00dea20 ldr r0, [r9] */
/* @0x00dea24 ldr r1, [r11] */
/* @0x00dea28 bl 0x318dec <__aeabi_idivmod> */
/* @0x00dea2c mov r12, #7 */
/* @0x00dea30 str r1, [r8] */
/* @0x00dea34 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* pair 32 (int32,real)：|opA| < 1e-10 → 除零；fmod(__floatdidf? opB 为 int32) */
/* @0x00dea38 vldr d7, [r11] */
/* @0x00dea3c vabs.f64 d5, d7 */
/* @0x00dea40 vldr d6, [pc, #832] */
/* @0x00dea44 vcmpe.f64 d5, d6 */
/* @0x00dea48 vmrs APSR_nzcv, fpscr */
/* @0x00dea4c bmi 0xde9dc <_Z5DoModjPhPKhP6VMExec+0x3f4> */
/* @0x00dea50 ldr r0, [r9] */
/* @0x00dea54 vmov r2, r3, d7 */
/* @0x00dea58 vmov s15, r0 */
/* @0x00dea5c vcvt.f64.s32 d7, s15 */
/* @0x00dea60 vmov r0, r1, d7 */
/* @0x00dea64 bl 0xb66ac <fmod@plt> */
/* @0x00dea68 mov r12, #0 */
/* @0x00dea6c strd r0, r1, [r8] */
/* @0x00dea70 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* pair 3 (real,int64)：opA(int64)==0 → 除零；__floatdidf + fmod */
/* @0x00dea74 ldrd r0, r1, [r11] */
/* @0x00dea78 orrs r3, r0, r1 */
/* @0x00dea7c beq 0xde9dc <_Z5DoModjPhPKhP6VMExec+0x3f4> */
/* @0x00dea80 bl 0x319164 <__floatdidf> */
/* @0x00dea84 ldrd r4, r5, [r9] */
/* @0x00dea88 mov r2, r0 */
/* @0x00dea8c mov r3, r1 */
/* @0x00dea90 mov r0, r4 */
/* @0x00dea94 mov r1, r5 */
/* @0x00dea98 bl 0xb66ac <fmod@plt> */
/* @0x00dea9c mov r12, #0 */
/* @0x00deaa0 strd r0, r1, [r8] */
/* @0x00deaa4 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* pair 2 (real,int32)：opA == 0 → 除零；vcvt.f64.s32 + fmod */
/* @0x00deaa8 ldr r2, [r11] */
/* @0x00deaac cmp r2, #0 */
/* @0x00deab0 beq 0xde9dc <_Z5DoModjPhPKhP6VMExec+0x3f4> */
/* @0x00deab4 vmov s15, r2 */
/* @0x00deab8 ldrd r0, r1, [r9] */
/* @0x00deabc vcvt.f64.s32 d7, s15 */
/* @0x00deac0 vmov r2, r3, d7 */
/* @0x00deac4 bl 0xb66ac <fmod@plt> */
/* @0x00deac8 mov r12, #0 */
/* @0x00deacc strd r0, r1, [r8] */
/* @0x00dead0 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* pair 48 (int64,real)：|opA| < 1e-10 → 除零；__floatdidf(opB) + fmod */
/* @0x00dead4 vldr d8, [r11] */
/* @0x00dead8 vabs.f64 d6, d8 */
/* @0x00deadc vldr d7, [pc, #676] */
/* @0x00deae0 vcmpe.f64 d6, d7 */
/* @0x00deae4 vmrs APSR_nzcv, fpscr */
/* @0x00deae8 bmi 0xde9dc <_Z5DoModjPhPKhP6VMExec+0x3f4> */
/* @0x00deaec ldrd r0, r1, [r9] */
/* @0x00deaf0 bl 0x319164 <__floatdidf> */
/* @0x00deaf4 vmov r2, r3, d8 */
/* @0x00deaf8 bl 0xb66ac <fmod@plt> */
/* @0x00deafc mov r12, #0 */
/* @0x00deb00 strd r0, r1, [r8] */
/* @0x00deb04 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* pair 35 (int32,int64)：opA(int64)==0 → 除零（走 0xdec20）；ldivmod → tag 10 */
/* @0x00deb08 ldrd r2, r3, [r11] */
/* @0x00deb0c orrs r1, r2, r3 */
/* @0x00deb10 beq 0xdec20 <_Z5DoModjPhPKhP6VMExec+0x638> */
/* @0x00deb14 ldr r0, [r9] */
/* @0x00deb18 asr r1, r0, #31 */
/* @0x00deb1c bl 0x319414 <__aeabi_ldivmod> */
/* @0x00deb20 mov r12, #10 */
/* @0x00deb24 strd r2, r3, [r8] */
/* @0x00deb28 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* pair 50 (int64,int32)：opA(int32)==0 → 除零；ldivmod → tag 10 */
/* @0x00deb2c ldr r2, [r11] */
/* @0x00deb30 cmp r2, #0 */
/* @0x00deb34 beq 0xdec20 <_Z5DoModjPhPKhP6VMExec+0x638> */
/* @0x00deb38 ldrd r0, r1, [r9] */
/* @0x00deb3c asr r3, r2, #31 */
/* @0x00deb40 bl 0x319414 <__aeabi_ldivmod> */
/* @0x00deb44 mov r12, #10 */
/* @0x00deb48 strd r2, r3, [r8] */
/* @0x00deb4c b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* 算术表默认项：VMError("DoMod :: Execution Error") ---- */
/* @0x00deb50 ldr r1, [pc, #0x244] */
/* @0x00deb54 mov r0, r10 */
/* @0x00deb58 add r1, pc, r1 */
/* @0x00deb5c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00deb60 mov r12, #0 */
/* @0x00deb64 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* ---- 常量路径：boxType(帧+0x10,kindA,base) / boxType(sp,kindB,前次返回) ---- */
/* @0x00deb68 add r7, sp, #16 */
/* @0x00deb6c mov r2, r1 */
/* @0x00deb70 and r1, r4, #15 */
/* @0x00deb74 mov r0, r7 */
/* @0x00deb78 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0x00deb7c lsr r1, r4, #4 */
/* @0x00deb80 mov r2, r0 */
/* @0x00deb84 mov r0, sp */
/* @0x00deb88 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* 校验两枚 RValue 的 +12 字低 24 位是否全 1（0x00FFFFFF = 未解析引用标记） ---- */
/* @0x00deb8c ldr r3, [sp, #0xc] */
/* @0x00deb90 mvn r12, #-16777216 */
/* @0x00deb94 and r3, r3, r12 */
/* @0x00deb98 cmp r3, r12 */
/* @0x00deb9c mov r6, r0 */
/* @0x00deba0 beq 0xdef04 <_Z5DoModjPhPKhP6VMExec+0x91c> */
/* @0x00deba4 ldr r3, [sp, #0x1c] */
/* @0x00deba8 bic r3, r3, #-16777216 */
/* @0x00debac cmp r3, r12 */
/* @0x00debb0 beq 0xdeef0 <_Z5DoModjPhPKhP6VMExec+0x908> */
/* F_JS_ToNumber(帧+0x20, sp) 与 F_JS_ToNumber(帧+0x30, 帧+0x10) ---- */
/* @0x00debb4 add r4, sp, #32 */
/* @0x00debb8 mov r1, sp */
/* @0x00debbc mov r2, #0 */
/* @0x00debc0 mov r3, #0 */
/* @0x00debc4 mov r0, r4 */
/* @0x00debc8 str r12, [sp, #0x2c] */
/* @0x00debcc str r12, [sp, #0x3c] */
/* @0x00debd0 mov r12, #0 */
/* @0x00debd4 strd r2, r3, [sp, #32] */
/* @0x00debd8 strd r2, r3, [sp, #48] */
/* @0x00debdc str r12, [sp, #0x28] */
/* @0x00debe0 str r12, [sp, #0x38] */
/* @0x00debe4 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x00debe8 cmp r0, #1 */
/* @0x00debec beq 0xdef18 <_Z5DoModjPhPKhP6VMExec+0x930> */
/* @0x00debf0 cmp r0, #0 */
/* @0x00debf4 beq 0xdec50 <_Z5DoModjPhPKhP6VMExec+0x668> */
/* @0x00debf8 ldr r3, [sp, #0x2c] */
/* @0x00debfc sub r3, r3, #1 */
/* @0x00dec00 bic r3, r3, #-16777216 */
/* @0x00dec04 bic r3, r3, #3 */
/* @0x00dec08 cmp r3, #0 */
/* @0x00dec0c bne 0xdea10 <_Z5DoModjPhPKhP6VMExec+0x428> */
/* @0x00dec10 mov r0, r4 */
/* @0x00dec14 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x00dec18 mov r0, r6 */
/* @0x00dec1c b 0xdea14 <_Z5DoModjPhPKhP6VMExec+0x42c> */
/* 整数除零：VMError("DoMod :: Divide by zero")（第二处，随后 r12=10） */
/* @0x00dec20 ldr r1, [pc, #0x178] */
/* @0x00dec24 mov r0, r10 */
/* @0x00dec28 add r1, pc, r1 */
/* @0x00dec2c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dec30 mov r12, #10 */
/* @0x00dec34 b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* fmod(opB, opA) 的公共尾部：strd 结果（double，tag 0） */
/* @0x00dec38 ldrd r0, r1, [r9] */
/* @0x00dec3c vmov r2, r3, d7 */
/* @0x00dec40 bl 0xb66ac <fmod@plt> */
/* @0x00dec44 mov r12, #0 */
/* @0x00dec48 strd r0, r1, [r8] */
/* @0x00dec4c b 0xdea08 <_Z5DoModjPhPKhP6VMExec+0x420> */
/* @0x00dec50 add r5, sp, #48 */
/* @0x00dec54 mov r1, r7 */
/* @0x00dec58 mov r0, r5 */
/* @0x00dec5c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x00dec60 cmp r0, #1 */
/* @0x00dec64 beq 0xdef28 <_Z5DoModjPhPKhP6VMExec+0x940> */
/* @0x00dec68 cmp r0, #0 */
/* @0x00dec6c bne 0xdebf8 <_Z5DoModjPhPKhP6VMExec+0x610> */
/* @0x00dec70 str r0, [r6, #-0x4] */
/* @0x00dec74 sub r7, r6, #16 */
/* @0x00dec78 ldrd r0, r1, [sp, #32] */
/* @0x00dec7c ldrd r2, r3, [sp, #48] */
/* @0x00dec80 bl 0xb66ac <fmod@plt> */
/* @0x00dec84 str r0, [r6, #-0x10] */
/* @0x00dec88 str r1, [r6, #-0xc] */
/* ---- 常量路径的 IEEE 后处理：NaN / ±0 / ∞ ---- */
/* @0x00dec8c vldr d7, [sp, #48] */
/* @0x00dec90 vcmp.f64 d7, d7 */
/* @0x00dec94 vmrs APSR_nzcv, fpscr */
/* @0x00dec98 bvs 0xdef38 <_Z5DoModjPhPKhP6VMExec+0x950> */
/* @0x00dec9c vldr d7, [sp, #32] */
/* @0x00deca0 vcmp.f64 d7, d7 */
/* @0x00deca4 vmrs APSR_nzcv, fpscr */
/* @0x00deca8 bvs 0xdef38 <_Z5DoModjPhPKhP6VMExec+0x950> */
/* @0x00decac mov r0, r4 */
/* @0x00decb0 bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x00decb4 cmp r0, #0 */
/* @0x00decb8 bne 0xdef38 <_Z5DoModjPhPKhP6VMExec+0x950> */
/* @0x00decbc ldrd r2, r3, [sp, #48] */
/* @0x00decc0 mvn r8, #0 */
/* @0x00decc4 mvn r9, #-2147483648 */
/* @0x00decc8 and r2, r2, r8 */
/* @0x00deccc and r3, r3, r9 */
/* @0x00decd0 orrs r1, r2, r3 */
/* @0x00decd4 beq 0xdef38 <_Z5DoModjPhPKhP6VMExec+0x950> */
/* @0x00decd8 mov r0, r5 */
/* @0x00decdc bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x00dece0 cmp r0, #0 */
/* @0x00dece4 bne 0xded10 <_Z5DoModjPhPKhP6VMExec+0x728> */
/* @0x00dece8 ldrd r2, r3, [sp, #32] */
/* @0x00decec and r2, r2, r8 */
/* @0x00decf0 and r3, r3, r9 */
/* @0x00decf4 orrs r1, r2, r3 */
/* @0x00decf8 bne 0xded20 <_Z5DoModjPhPKhP6VMExec+0x738> */
/* @0x00decfc ldrd r2, r3, [sp, #48] */
/* @0x00ded00 and r2, r2, r8 */
/* @0x00ded04 and r3, r3, r9 */
/* @0x00ded08 orrs r1, r2, r3 */
/* @0x00ded0c beq 0xded20 <_Z5DoModjPhPKhP6VMExec+0x738> */
/* 结果回填为 opA 的位型（∞ 或 0 的传播） */
/* @0x00ded10 ldr r2, [sp, #0x20] */
/* @0x00ded14 ldr r3, [sp, #0x24] */
/* @0x00ded18 str r2, [r6, #-0x10] */
/* @0x00ded1c str r3, [r6, #-0xc] */
/* @0x00ded20 ldr r3, [sp, #0x2c] */
/* @0x00ded24 sub r3, r3, #1 */
/* @0x00ded28 bic r3, r3, #-16777216 */
/* @0x00ded2c bic r3, r3, #3 */
/* @0x00ded30 cmp r3, #0 */
/* @0x00ded34 beq 0xdef4c <_Z5DoModjPhPKhP6VMExec+0x964> */
/* @0x00ded38 ldr r1, [sp, #0x3c] */
/* @0x00ded3c mov r3, #0 */
/* @0x00ded40 str r3, [sp, #0x28] */
/* @0x00ded44 mov r2, #5 */
/* @0x00ded48 sub r1, r1, #1 */
/* @0x00ded4c str r3, [sp, #0x20] */
/* @0x00ded50 bic r3, r1, #-16777216 */
/* @0x00ded54 str r2, [sp, #0x2c] */
/* @0x00ded58 bic r3, r3, #3 */
/* @0x00ded5c cmp r3, #0 */
/* @0x00ded60 movne r0, r7 */
/* @0x00ded64 bne 0xdea14 <_Z5DoModjPhPKhP6VMExec+0x42c> */
/* @0x00ded68 mov r0, r5 */
/* @0x00ded6c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x00ded70 mov r0, r7 */
/* @0x00ded74 b 0xdea14 <_Z5DoModjPhPKhP6VMExec+0x42c> */
/* 间接 kindA：tag 7 → kindA=2，opB 槽回 base+16（0xded80 起） */
/* @0x00ded78 and r0, r0, #240 */
/* @0x00ded7c orr r5, r0, #2 */
/* @0x00ded80 add r9, r11, #16 */
/* @0x00ded84 b 0xde654 <_Z5DoModjPhPKhP6VMExec+0x6c> */
/* @0x00ded88 ldmible r7, {r0, r1, r3, r4, r5, r7, r8, r10, r11, r12, sp, pc} ^ */
/* @0x00ded8c ldcllo p12, c7, [r11, #892] */
/* @0x00ded90 eoreq r4, r5, r8, lsl #29 */
/* @0x00ded94 eoreq r4, r5, r8, asr #28 */
/* @0x00ded98 eoreq r4, r5, r8, asr r12 */
/* @0x00ded9c .word 0x00254afc */
/* @0x00deda0 eoreq r4, r5, r4, lsl r10 */
/* @0x00deda4 eoreq r4, r5, r8, asr #14 */
/* @0x00deda8 eoreq r4, r5, r0, lsl r7 */
/* @0x00dedac eoreq r4, r5, r0, ror r7 */
/* @0x00dedb0 eoreq r4, r5, r12, lsl r7 */
/* @0x00dedb4 eoreq r4, r5, r0, ror r7 */
/* @0x00dedb8 eoreq r4, r5, r12, lsr r7 */
/* @0x00dedbc eoreq r4, r5, r4, ror #14 */
/* @0x00dedc0 eoreq r4, r5, r4, lsr #12 */
/* @0x00dedc4 .word 0x002546d4 */
/* @0x00dedc8 eoreq r4, r5, r8, lsr r7 */
/* @0x00dedcc eoreq r4, r5, r12, lsr r5 */
/* @0x00dedd0 eoreq r4, r5, r8, lsr #10 */
/* @0x00dedd4 eoreq r4, r5, r8, lsr r5 */
/* @0x00dedd8 eoreq r4, r5, r8, ror #10 */
/* 间接 kindA：tag 5 → "undefined value" */
/* @0x00deddc ldr r1, [pc, #-0x40] */
/* @0x00dede0 mov r0, r10 */
/* @0x00dede4 mov r5, r4 */
/* @0x00dede8 add r1, pc, r1 */
/* @0x00dedec bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dedf0 b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* 间接 kindA：tag 3 → "illegal pointer use" */
/* @0x00dedf4 ldr r1, [pc, #-0x54] */
/* @0x00dedf8 mov r0, r10 */
/* @0x00dedfc mov r5, r4 */
/* @0x00dee00 add r1, pc, r1 */
/* @0x00dee04 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dee08 b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* 间接 kindA：tag 2 → "illegal array use" */
/* @0x00dee0c ldr r1, [pc, #-0x68] */
/* @0x00dee10 mov r0, r10 */
/* @0x00dee14 mov r5, r4 */
/* @0x00dee18 add r1, pc, r1 */
/* @0x00dee1c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dee20 b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* 间接 kindA：tag 1 → 字符串报错 */
/* @0x00dee24 ldr r1, [pc, #-0x7c] */
/* @0x00dee28 mov r0, r10 */
/* @0x00dee2c mov r5, r4 */
/* @0x00dee30 add r1, pc, r1 */
/* @0x00dee34 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dee38 b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* 间接 kindA：tag 0/13 → kindA=0（real） */
/* @0x00dee3c and r5, r4, #240 */
/* @0x00dee40 b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* 间接 kindA：tag 10 → kindA=3 */
/* @0x00dee44 and r0, r0, #240 */
/* @0x00dee48 orr r5, r0, #3 */
/* @0x00dee4c b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* 间接 kindB：tag 10 → kindB=3（0x30） */
/* @0x00dee50 and r5, r5, #15 */
/* @0x00dee54 orr r5, r5, #48 */
/* @0x00dee58 add r6, r9, #16 */
/* @0x00dee5c b 0xde694 <_Z5DoModjPhPKhP6VMExec+0xac> */
/* 间接 kindB：tag 7 → kindB=2（0x20） */
/* @0x00dee60 and r5, r5, #15 */
/* @0x00dee64 orr r5, r5, #32 */
/* @0x00dee68 b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* 间接 kindB：tag 5 → "undefined value" */
/* @0x00dee6c ldr r1, [pc, #-0xc0] */
/* @0x00dee70 mov r0, r10 */
/* @0x00dee74 add r1, pc, r1 */
/* @0x00dee78 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dee7c b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* 间接 kindB：tag 3 → "illegal pointer use" */
/* @0x00dee80 ldr r1, [pc, #-0xd0] */
/* @0x00dee84 mov r0, r10 */
/* @0x00dee88 add r1, pc, r1 */
/* @0x00dee8c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00dee90 b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* 间接 kindB：tag 2 → "illegal array use" */
/* @0x00dee94 ldr r1, [pc, #-0xe0] */
/* @0x00dee98 mov r0, r10 */
/* @0x00dee9c add r1, pc, r1 */
/* @0x00deea0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00deea4 b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* 间接 kindB：tag 1 → 字符串报错 */
/* @0x00deea8 ldr r1, [pc, #-0xf0] */
/* @0x00deeac mov r0, r10 */
/* @0x00deeb0 add r1, pc, r1 */
/* @0x00deeb4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00deeb8 b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* 间接 kindB：tag 0/13 → kindB=0 */
/* @0x00deebc and r5, r5, #15 */
/* @0x00deec0 b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* 间接 kindA："Malformed variable" */
/* @0x00deec4 ldr r1, [pc, #-0x108] */
/* @0x00deec8 mov r0, r10 */
/* @0x00deecc mov r5, r4 */
/* @0x00deed0 add r1, pc, r1 */
/* @0x00deed4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00deed8 b 0xded80 <_Z5DoModjPhPKhP6VMExec+0x798> */
/* 间接 kindB："Malformed variable" */
/* @0x00deedc ldr r1, [pc, #-0x11c] */
/* @0x00deee0 mov r0, r10 */
/* @0x00deee4 add r1, pc, r1 */
/* @0x00deee8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00deeec b 0xdee58 <_Z5DoModjPhPKhP6VMExec+0x870> */
/* opA 未解析引用 → JSThrowReferenceError("could not find lhs variable on mod") */
/* @0x00deef0 ldr r0, [pc, #-0x12c] */
/* @0x00deef4 add r0, pc, r0 */
/* @0x00deef8 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0x00deefc mov r0, r6 */
/* @0x00def00 b 0xdea14 <_Z5DoModjPhPKhP6VMExec+0x42c> */
/* opB 未解析引用 → 同一句（源码只有 lhs 文案） */
/* @0x00def04 ldr r0, [pc, #-0x13c] */
/* @0x00def08 add r0, pc, r0 */
/* @0x00def0c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0x00def10 mov r0, r6 */
/* @0x00def14 b 0xdea14 <_Z5DoModjPhPKhP6VMExec+0x42c> */
/* ToNumber 失败 → JSThrowTypeError("Could not convert left-hand-side of '%' operator to a number") */
/* @0x00def18 ldr r0, [pc, #-0x14c] */
/* @0x00def1c add r0, pc, r0 */
/* @0x00def20 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x00def24 b 0xdebf8 <_Z5DoModjPhPKhP6VMExec+0x610> */
/* 右侧失败 → right-hand-side 同名报错 */
/* @0x00def28 ldr r0, [pc, #-0x158] */
/* @0x00def2c add r0, pc, r0 */
/* @0x00def30 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x00def34 b 0xdebf8 <_Z5DoModjPhPKhP6VMExec+0x610> */
/* 命中 NaN/±0/∞：结果置 0x7FFFFFFFFFFFFFFF（NaN 位型） */
/* @0x00def38 mvn r2, #0 */
/* @0x00def3c mvn r3, #-2147483648 */
/* @0x00def40 str r2, [r6, #-0x10] */
/* @0x00def44 str r3, [r6, #-0xc] */
/* @0x00def48 b 0xded20 <_Z5DoModjPhPKhP6VMExec+0x738> */
/* @0x00def4c mov r0, r4 */
/* @0x00def50 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x00def54 b 0xded38 <_Z5DoModjPhPKhP6VMExec+0x750> */
/* @0x00def58 mov r5, r4 */
/* @0x00def5c mov r9, r1 */
/* @0x00def60 b 0xde654 <_Z5DoModjPhPKhP6VMExec+0x6c> */
/* @0x00def64 mov r6, r9 */
/* @0x00def68 b 0xde694 <_Z5DoModjPhPKhP6VMExec+0xac> */
