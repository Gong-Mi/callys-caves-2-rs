/* cally 逆向卡：DoPopLocalVariable（原版 libyoyo.so，armv7）
 * @func 0xe1f5c 0xe2014  size 184  46 条指令
 * 级别: 正文（46 条逐条解码；控制流 + 数据流 + 输出全部钉住）
 * 符号: _Z18DoPopLocalVariablejPhPKhP6VMExec → uchar* DoPopLocalVariable(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   raw  = *(uint32_t*)base                       ; e1f64 —— 操作数来自码流，不是值栈
 *   bit31 = 0 → 先弹 4 B 到 r7（实例 id）；bit31 = 1 → r7 = 0x80000000（INT_MIN = "self" 哨兵）
 *                                                ; e1f6c / e1f70 / e1f74
 *   bit29 (0x20000000) = 0 → 再弹 4 B             ; e1f78 / e1f7c —— 与 DoPop 的 e68b4..e68c4 同一套实例-id 解码
 *   idx  = (raw & 0x0FFFFFFF) - 99328 - 672       ; e1fe0 / e1fe4 / e1fec —— 变量 id 基址 100000（第四次独立复现）
 *   self = exec->[0x10]                           ; e1f68
 *   self != 0 → PushContextStack(self)            ; e1f80 / e1f8c；与之配对的 PopContextStack 在 e1f9c/e2004
 *   self->[0x24] == 0 → 跳过写回、直接收尾        ; e1f90 / e1f98 —— 与 DoPop 的 local 分支 e6b58/e6b60 同一处门
 *   dst = self->[4] + idx*16                      ; e1fdc / e1ff4 —— 局部 RValue 表、步长 16（同 DoPushLocal）
 *   self->[4] == 0 → dst = self->InternalGetYYVar(idx)   ; e1ff0 / e2008 —— 动态变量回落
 *   SET_RValue(dst, src=值槽, r7)                 ; e1ff8..e2000 —— r7 = 实例 id 或 INT_MIN
 *   (tag-1) & 0x00FFFFFC == 0（tag ∈ 1..4）→ FREE_RValue__Pre(值槽)  ; e1fa0..e1fbc
 *   结果：同一槽改写 {+0=0, +8=0, +12=5}，返回该槽地址   ; e1fc4..e1fd8 —— 表达式结果 = tag 5（无载荷），不是赋值后的值
 *
 * 结论：
 *   1. 这是「局部变量赋值的 pop 形态」：值栈顶放 [实例 id?][右值 RValue]，本函数吃掉实例 id，把右值写进
 *      self->[4] 的第 idx 槽，再把右值槽改写成 tag 5 的空结果（sp 净下移 0：16 B 出去、16 B 回来）。
 *   2. 与 DoPop 的 do_set 局部分支（0xe6b40 起）逐指令同构，差别只有两点：这里不处理 0x40000000/0x10000000 两个
 *      高位标志，idx 直接由 base 操作数减 100000；且这里不读 base[+4]。
 *   3. 局部表在 self+4、变量 id 基址 100000、槽宽 16 —— 与 DoPushLocal/DoPushGlobal/DoSet 四点互证。
 * open：self->[0x24] 的字段语义（DoPop 同址同判定，两处都只把它当"有表"的闸）；
 *       tag 5 槽只写 +0/+8/+12、不写 +4 —— 与 SET_RValue 的 tag 跳表（0xd0bc4 起）里 tag 5 不拷载荷一致，
 *       但"tag 5 无载荷"这一条仍需一条独立函数（如 boxType 的 cls 9 分支 0xd77ec）来闭合。
 */


/* ── 段 1 · 序言 / 操作数解码（0xe1f5c..0xe1f7c） ── */
/* @0xe1f5c push {r3, r4, r5, r6, r7, lr} */
/* @0xe1f60 mov r4, r1 */
/* @0xe1f64 ldr r6, [r2] */
/* @0xe1f68 ldr r5, [r3, #0x10] */
/* @0xe1f6c cmp r6, #0 */
/* @0xe1f70 ldrge r7, [r4], #4 */
/* @0xe1f74 movlt r7, #-2147483648 */
/* @0xe1f78 tst r6, #536870912 */
/* @0xe1f7c addeq r4, r4, #4 */

/* ── 段 2 · 上下文栈 + self->[0x24] 闸（0xe1f80..0xe1f9c） ── */
/* @0xe1f80 cmp r5, #0 */
/* @0xe1f84 beq 0xe1fa0 <_Z18DoPopLocalVariablejPhPKhP6VMExec+0x44> */
/* @0xe1f88 mov r0, r5 */
/* @0xe1f8c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe1f90 ldr r3, [r5, #0x24] */
/* @0xe1f94 cmp r3, #0 */
/* @0xe1f98 bne 0xe1fdc <_Z18DoPopLocalVariablejPhPKhP6VMExec+0x80> */
/* @0xe1f9c bl 0xd3a34 <_Z15PopContextStackv> */

/* ── 段 3 · 值槽收尾：条件 FREE + 写 tag 5 结果（0xe1fa0..0xe1fd8） ── */
/* @0xe1fa0 ldr r3, [r4, #0xc] */
/* @0xe1fa4 sub r3, r3, #1 */
/* @0xe1fa8 bic r3, r3, #-16777216 */
/* @0xe1fac bic r3, r3, #3 */
/* @0xe1fb0 cmp r3, #0 */
/* @0xe1fb4 bne 0xe1fc0 <_Z18DoPopLocalVariablejPhPKhP6VMExec+0x64> */
/* @0xe1fb8 mov r0, r4 */
/* @0xe1fbc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe1fc0 mov r0, r4 */
/* @0xe1fc4 mov r3, #0 */
/* @0xe1fc8 mov r2, #5 */
/* @0xe1fcc str r3, [r4, #0x8] */
/* @0xe1fd0 str r2, [r4, #0xc] */
/* @0xe1fd4 str r3, [r0], #16 */
/* @0xe1fd8 pop {r3, r4, r5, r6, r7, pc} */

/* ── 段 4 · 写回局部槽：self->[4] 或 InternalGetYYVar（0xe1fdc..0xe2010） ── */
/* @0xe1fdc ldr r3, [r5, #0x4] */
/* @0xe1fe0 bic r6, r6, #-268435456 */
/* @0xe1fe4 sub r6, r6, #99328 */
/* @0xe1fe8 cmp r3, #0 */
/* @0xe1fec sub r1, r6, #672 */
/* @0xe1ff0 beq 0xe2008 <_Z18DoPopLocalVariablejPhPKhP6VMExec+0xac> */
/* @0xe1ff4 add r0, r3, r1, lsl #4 */
/* @0xe1ff8 mov r2, r7 */
/* @0xe1ffc mov r1, r4 */
/* @0xe2000 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0xe2004 b 0xe1f9c <_Z18DoPopLocalVariablejPhPKhP6VMExec+0x40> */
/* @0xe2008 mov r0, r5 */
/* @0xe200c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe2010 b 0xe1ff8 <_Z18DoPopLocalVariablejPhPKhP6VMExec+0x9c> */
