/* cally 逆向卡：DoConvIntToVariable（原版 libyoyo.so，armv7）
 * @func 0xd773c 0xd7760  size 36  9 条指令
 * 级别: 正文（转换方向已证；RValue 12 字节布局待证）
 * 符号: _Z19DoConvIntToVariablejPhPKhP6VMExec
 *
 * 已证（指令级）：
 *   vldr s15,[sp]            ; 取栈顶 int32
 *   vcvt.f64.s32 d7,s15      ; 转成 double
 *   vmov r2,r3,d7            ; 取 double 的两个字
 *   vstr s14,[sp,#-12]       ; 写 12 字节对象的前 4 字节（s14 未在本函数内定义！）
 *   str  r3,[sp,#-8]         ; 写高位字
 *   str  #0,[sp]             ; 先写 0，再把返回值设为 sp-12
 *   返回 sp-12
 * 结论：把栈顶整数就地转成 12 字节的实数 RValue，栈上**不加高**（原地替换但地址下移 12）。
 * open：s14 的来源（跨函数/ABI 残值？）、12 字节里 tag 字段的位置、返回后旧位置是否被清理。
 *
 * ── 本批补证：极小转换器（逐条锚在下方）──
 *   无任何 bl：纯内联的类型/整数转换段
 *   open 1 转换前后的 tag 变化（需逐条读 9 条指令）
 */
/* @0xd773c vldr s15, [r1] */
/* @0xd7740 vcvt.f64.s32 d7, s15 */
/* @0xd7744 mov r0, r1 */
/* @0xd7748 mov r12, #0 */
/* @0xd774c vmov r2, r3, d7 */
/* @0xd7750 vstr s14, [r1, #-12] */
/* @0xd7754 str r3, [r1, #-0x8] */
/* @0xd7758 str r12, [r0], #-12 */
/* @0xd775c bx lr */
