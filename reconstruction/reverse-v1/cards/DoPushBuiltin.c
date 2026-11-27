/* cally 逆向卡：DoPushBuiltin（原版 libyoyo.so，armv7）
 * @func 0xd4d74 0xd4dfc  size 136  34 条指令（末 3 条为 literal 词）
 * 级别: 正文（内置函数表的上界来源 open）
 * 符号: _Z13DoPushBuiltinjPhPKhP6VMExec
 *
 * 已证（指令级）：
 *   idx = *(uint32_t*)base & 0x0FFFFFFF        ; d4d84 ldr r4,[r2] / d4d94 bic #-268435456
 *   res = sp - 16                              ; d4d80 sub r5,r1,#16
 *   for (i=4;i<=16;i+=4) *(uint32*)(sp-i) = 0  ; d4d8c..d4d9c 清零 16 字节
 *   n   = *(uint32_t*)<global>                 ; d4d7c/d4d88/d4da0 GOT 三跳取表长度
 *   if (idx >= n) { VMError(exec, "<msg>"); return res; }        ; d4da4 blt / d4db8 bl VMError
 *   fn  = *(void**)(((char*)<global_table>) + idx*16 + 4)        ; d4ddc add r4,r3,r4,lsl #4 / d4de0 ldr r3,[r4,#4]
 *   fn(0x80000000, res, res);  return res                        ; d4dd0/d4dd4/d4de4 blx r3
 *
 * 结论（新增两条硬事实）：
 *   1. **RValue 在栈上是 16 字节**——这里显式清零四个字（sp-4 .. sp-16）。
 *   2. 内置函数表项是 16 字节步长，函数指针在表项 +4；索引先与 0x0FFFFFFF 掩码，
 *      说明 opcode 参数的高 4 位另作标志。
 * open：表长的全局符号名；VMError 的消息串；blx 的第 1 个实参 0x80000000 的语义；
 *       表项 +0 与 +8..+15 的字段。
 */
/* @0xd4d74 push {r3, r4, r5, lr} */
/* @0xd4d78 mov r0, #0 */
/* @0xd4d7c ldr lr, [pc, #0x6c] */
/* @0xd4d80 sub r5, r1, #16 */
/* @0xd4d84 ldr r4, [r2] */
/* @0xd4d88 ldr lr, [pc, lr] */
/* @0xd4d8c str r0, [r1, #-0x4] */
/* @0xd4d90 str r0, [r1, #-0x8] */
/* @0xd4d94 bic r4, r4, #-268435456 */
/* @0xd4d98 str r0, [r1, #-0xc] */
/* @0xd4d9c str r0, [r1, #-0x10] */
/* @0xd4da0 ldr lr, [lr] */
/* @0xd4da4 cmp r4, lr */
/* @0xd4da8 blt 0xd4dcc <_Z13DoPushBuiltinjPhPKhP6VMExec+0x58> */
/* @0xd4dac ldr r1, [pc, #0x40] */
/* @0xd4db0 mov r0, r3 */
/* @0xd4db4 mov r2, r4 */
/* @0xd4db8 mov r3, lr */
/* @0xd4dbc add r1, pc, r1 */
/* @0xd4dc0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4dc4 mov r0, r5 */
/* @0xd4dc8 pop {r3, r4, r5, pc} */
/* @0xd4dcc ldr r3, [pc, #0x24] */
/* @0xd4dd0 mov r1, #-2147483648 */
/* @0xd4dd4 mov r2, r5 */
/* @0xd4dd8 ldr r3, [pc, r3] */
/* @0xd4ddc add r4, r3, r4, lsl #4 */
/* @0xd4de0 ldr r3, [r4, #0x4] */
/* @0xd4de4 blx r3 */
/* @0xd4de8 mov r0, r5 */
/* @0xd4dec pop {r3, r4, r5, pc} */
/* @0xd4df0 eorseq r8, r1, r12, lsr #29 */
/* @0xd4df4 eoreq sp, r5, r8, asr r12 */
/* @0xd4df8 eorseq r8, r1, r0, ror #28 */
