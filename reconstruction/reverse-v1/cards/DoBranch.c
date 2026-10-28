/* cally 逆向卡：DoBranch（原版 libyoyo.so，armv7）
 * @func 0xd3254 0xd328c  size 56  14 条指令
 * 级别: 正文
 * 符号: _Z8DoBranchjPhPKhP6VMExec → uchar* DoBranch(uint32_t off, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   p  = exec->[0x44]                  ; 当前字节码指针
 *   p += (int32_t)(off << 9) >> 7      ; == off*4 的算术右移等价形式（相对跳转，单位 4 字节）
 *   exec->[0x44] = p - 4 + off*4       ; 先减 4 再加重定位量
 *   idx = (p<0 ? p+3 : p) >> 2         ; 负地址的安全取整
 *   exec->[0x48] = ((void**)exec->[0x5c])[idx]   ; 取处理器表项作为新 pc
 *   返回 sp（未弹栈）
 * 结论：VM 是**线程化解释器**：exec[0x44] = 字节码地址，exec[0x5c] = 处理器指针表，
 *       exec[0x48] = 当前表项（下次 blx 的目标）。
 */
/* @0xd3254 ldr r2, [r3, #0x44] */
/* @0xd3258 lsl r12, r0, #9 */
/* @0xd325c mov r0, r1 */
/* @0xd3260 ldr r1, [r3, #0x5c] */
/* @0xd3264 sub r2, r2, #4 */
/* @0xd3268 add r2, r2, r12, asr #7 */
/* @0xd326c str r2, [r3, #0x44] */
/* @0xd3270 add r12, r2, #3 */
/* @0xd3274 cmp r2, #0 */
/* @0xd3278 movlt r2, r12 */
/* @0xd327c asr r2, r2, #2 */
/* @0xd3280 ldr r2, [r1, r2, lsl #2] */
/* @0xd3284 str r2, [r3, #0x48] */
/* @0xd3288 bx lr */
