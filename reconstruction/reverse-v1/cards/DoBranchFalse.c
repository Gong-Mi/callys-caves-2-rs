/* cally 逆向卡：DoBranchFalse（原版 libyoyo.so，armv7）
 * @func 0xd32d0 0xd3314  size 68  17 条指令
 * 级别: 正文
 * 符号: _Z13DoBranchFalsejPhPKhP6VMExec
 *
 * 已证（指令级）：
 *   if (*(int32_t*)sp != 0) return sp + 4;      ; 条件为真：不跳
 *   否则执行与 DoBranch 相同的重定位（exec[0x44] += off*4，exec[0x48] = exec[0x5c][idx]）
 *   return sp + 4
 * 结论：DoBranchTrue/False 互为镜像，唯一差别是 `beq` 与 `bne`，其余 16 条指令逐字相同。
 */
/* @0xd32d0 ldr r12, [r1] */
/* @0xd32d4 cmp r12, #0 */
/* @0xd32d8 bne 0xd330c <_Z13DoBranchFalsejPhPKhP6VMExec+0x3c> */
/* @0xd32dc ldr r2, [r3, #0x44] */
/* @0xd32e0 lsl r0, r0, #9 */
/* @0xd32e4 ldr r12, [r3, #0x5c] */
/* @0xd32e8 sub r2, r2, #4 */
/* @0xd32ec add r2, r2, r0, asr #7 */
/* @0xd32f0 str r2, [r3, #0x44] */
/* @0xd32f4 add r0, r2, #3 */
/* @0xd32f8 cmp r2, #0 */
/* @0xd32fc movlt r2, r0 */
/* @0xd3300 asr r2, r2, #2 */
/* @0xd3304 ldr r2, [r12, r2, lsl #2] */
/* @0xd3308 str r2, [r3, #0x48] */
/* @0xd330c add r0, r1, #4 */
/* @0xd3310 bx lr */
