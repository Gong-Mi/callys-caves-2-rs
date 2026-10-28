/* cally 逆向卡：DoPushImmediate（原版 libyoyo.so，armv7）
 * @func 0xd3244 0xd3254  size 16  4 条指令
 * 级别: 正文
 * 符号: _Z15DoPushImmediatejPhPKhP6VMExec
 *   → uchar* DoPushImmediate(uint32_t imm, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（4 条指令全解）：
 *   把 16 位立即数**符号扩展**后压到 GML 值栈：`sxth r0,r0` 后 `str r0,[r1,#-4]!`（前减 4 再存），
 *   返回新栈顶 r1。base 与 exec 未使用。
 * 推论：r1（第 2 实参）是**值栈顶指针**而不是字节码指针；处理器返回新的栈顶。
 */
/* @0xd3244 sxth r0, r0 */
/* @0xd3248 str r0, [r1, #-0x4]! */
/* @0xd324c mov r0, r1 */
/* @0xd3250 bx lr */
