/* cally 逆向卡：DoBranchTrue（原版 libyoyo.so，armv7）
 * @func 0xd328c 0xd32d0  size 68  17 条指令
 * 级别: 正文
 * 符号: _Z12DoBranchTruejPhPKhP6VMExec
 *
 * 已证（指令级）：
 *   if (*(int32_t*)sp == 0) return sp + 4;      ; 条件为假：不跳，弹 1 个值
 *   ……否则与 DoBranch 完全相同：exec[0x44] += off*4 后按 (p<0?p+3:p)>>2 取 exec[0x5c][idx] 写入 exec[0x48]
 *   return sp + 4
 * 结论：条件取自**值栈顶**（sp[0]），与 DoBranch 共用重定位代码；两处尾部都是 `add r0,r1,#4`。
 */
/* @0xd328c ldr r12, [r1] */
/* @0xd3290 cmp r12, #0 */
/* @0xd3294 beq 0xd32c8 <_Z12DoBranchTruejPhPKhP6VMExec+0x3c> */
/* @0xd3298 ldr r2, [r3, #0x44] */
/* @0xd329c lsl r0, r0, #9 */
/* @0xd32a0 ldr r12, [r3, #0x5c] */
/* @0xd32a4 sub r2, r2, #4 */
/* @0xd32a8 add r2, r2, r0, asr #7 */
/* @0xd32ac str r2, [r3, #0x44] */
/* @0xd32b0 add r0, r2, #3 */
/* @0xd32b4 cmp r2, #0 */
/* @0xd32b8 movlt r2, r0 */
/* @0xd32bc asr r2, r2, #2 */
/* @0xd32c0 ldr r2, [r12, r2, lsl #2] */
/* @0xd32c4 str r2, [r3, #0x48] */
/* @0xd32c8 add r0, r1, #4 */
/* @0xd32cc bx lr */
