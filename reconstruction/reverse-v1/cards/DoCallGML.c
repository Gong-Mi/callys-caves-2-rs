/* cally 逆向卡：DoCallGML（原版 libyoyo.so，armv7）
 * @func 0xe8b00 0xe8b48  size 72  18 条指令
 * 级别: 正文（尾部 -> DoCallScript 的参数语义部分 open）
 * 符号: _Z9DoCallGMLjPhPKhP6VMExec
 *
 * 已证（指令级）：
 *   id   = *(uint32_t*)base;                    ; e8b00  ldr r2,[r2]
 *   idx  = id - 99328 - 672;                    ; e8b10/e8b1c == id - 100000
 *   scr  = Script_Data(idx);                    ; e8b20  -> CScript*
 *   argv = (uint16_t)off;                       ; e8b28  uxth r1,r6 —— 低 16 位 = 实参个数
 *   DoCallScript(scr, argv, sp, exec, NULL, NULL);   ; e8b3c，两个栈槽先清 0
 *   return <DoCallScript 的返回值>
 * 结论：GML 脚本 id 以 100000 为基址（100000+idx ↔ Script_Data(idx)），
 *       调用时实参个数取 opcode 参数的低 16 位。base 在这里是**指向脚本 id 的指针**。
 * open：DoCallScript 的返回值语义、两个 NULL 实参的含义。
 */
/* @0xe8b00 ldr r2, [r2] */
/* @0xe8b04 push {r4, r5, r6, lr} */
/* @0xe8b08 mov r6, r0 */
/* @0xe8b0c sub sp, sp, #8 */
/* @0xe8b10 sub r0, r2, #99328 */
/* @0xe8b14 mov r5, r1 */
/* @0xe8b18 mov r4, r3 */
/* @0xe8b1c sub r0, r0, #672 */
/* @0xe8b20 bl 0x1e069c <_Z11Script_Datai> */
/* @0xe8b24 mov r12, #0 */
/* @0xe8b28 uxth r1, r6 */
/* @0xe8b2c mov r2, r5 */
/* @0xe8b30 mov r3, r4 */
/* @0xe8b34 str r12, [sp] */
/* @0xe8b38 str r12, [sp, #0x4] */
/* @0xe8b3c bl 0xe8588 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_> */
/* @0xe8b40 add sp, sp, #8 */
/* @0xe8b44 pop {r4, r5, r6, pc} */
