/* cally 逆向卡：DoExit（原版 libyoyo.so，armv7）
 * @func 0xe44d4 0xe4540  size 108  27 条指令
 * 级别: 正文（27/27 逐条落锚，两条出口路径全解）
 * 符号: _Z6DoExitjPhPKhP6VMExec → uchar* DoExit(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   depth = exec->[0x4c]                                   ; e44d4 ldr r2, [r3, #0x4c]
 *   if (depth > 0) goto 0xe4518                            ; e44dc cmp #0 / e44e0 bgt
 *   —— depth <= 0：只重置取指状态，sp 原样返回 ——
 *   tbl = exec->[0x5c]                                     ; e44e4
 *   p   = exec->[0x50]                                     ; e44e8
 *   exec->[0x44] = p                                       ; e44f0
 *   if (tbl != 0) exec->[0x48] = tbl[(p < 0 ? p+3 : p) >> 2] ; e44f8-e4508（先 +3 再 asr #2 = 有符号除 4）
 *   return sp                                              ; e4510 mov r0,r1 / e4514 pop
 *   —— depth > 0：真正退出 ——
 *   sp2 = PerformReturn(exec->[0x28], exec)                ; e4518-e4520（r0 = 帧指针，r1 = exec）
 *   *(uint32*)(sp2-16) = 0; (sp2-12) = 0; (sp2-8) = 0; (sp2-4) = 0 ; e4524-e4534（r3=0 连写四字）
 *   return sp2 - 16                                        ; e4528 sub r1,r0,#16 / e4538 mov r0,r1
 *
 * 结论（新增三条硬事实）：
 *   1. exec+0x50 是「退出后恢复用的取指指针」，exec+0x44 是当前字节码指针，exec+0x5c 是
 *      **以 4 字节字为单位索引的指针表**；表项 = tbl[code/4]，负数除法靠「先 +3 再 asr #2」向 0 取整。
 *      这段重置与 DoRet 0xe4020-0xe4048 指令级同构（同偏移、同写法），可以判定二者共用同一取指状态协议。
 *   2. 帧深度 == 0（或为负）时 DoExit 既不清值栈也不回填帧值：只做上面三条赋值并原样返回 sp ——
 *      即「最外层退出」，把「取指复位」与「弹帧」两件事彻底拆开。
 *   3. 深度 > 0 时 DoExit = PerformReturn(帧, exec) 再在返回地址下方压一个 **16 字节全零 RValue**
 *      （tag 字 = 0）。按 DoPush 的 tag 表 case 0 走 8 字节载荷拷贝，这个零值即「数值 0」；
 *      而 DoRet 子类 15 压的是 tag 5（undefined）——两者不是同一个值，这是 exit 与 return 的实质差别。
 * open：exec+0x50 的写入点（PerformReturn 0xe43a4 从 frame+0x04 恢复的正是同一字段）；
 *       顶层退出后 VM 主循环如何收尾（本函数不处理 exec+0x4c 的负值，也不动 exec+0x28）。
 */

/* 序言：r3 = exec、r1 = sp、r0 = arg（本函数不使用 arg 与 base）；r2 = exec+0x4c 帧深度 */
/* @0xe44d4 ldr r2, [r3, #0x4c] */  —— r2 = 帧深度 exec->[0x4c]
/* @0xe44d8 push {r3, lr} */
/* @0xe44dc cmp r2, #0 */
/* @0xe44e0 bgt 0xe4518 <_Z6DoExitjPhPKhP6VMExec+0x44> */

/* 深度 <= 0 出口：只重置「字节码指针 / 表项」，不弹帧、不动 sp */
/* @0xe44e4 ldr r0, [r3, #0x5c] */  —— r0 = exec->[0x5c] 指针表
/* @0xe44e8 ldr r2, [r3, #0x50] */  —— r2 = exec->[0x50] 恢复用取指指针
/* @0xe44ec cmp r0, #0 */
/* @0xe44f0 str r2, [r3, #0x44] */  —— exec->[0x44] = p
/* @0xe44f4 beq 0xe450c <_Z6DoExitjPhPKhP6VMExec+0x38> */

/* 有符号除 4：p<0 时先 +3 再 asr #2，保证向 0 取整（与 DoRet 0xe4034-e4044 同构） */
/* @0xe44f8 add r12, r2, #3 */
/* @0xe44fc cmp r2, #0 */
/* @0xe4500 movlt r2, r12 */
/* @0xe4504 asr r2, r2, #2 */
/* @0xe4508 ldr r0, [r0, r2, lsl #2] */  —— exec->[0x48] = tbl[p>>2]
/* @0xe450c str r0, [r3, #0x48] */
/* @0xe4510 mov r0, r1 */
/* @0xe4514 pop {r3, pc} */

/* 深度 > 0 出口：PerformReturn(exec->[0x28], exec) 完成弹帧并返回新的值栈顶 */
/* @0xe4518 mov r1, r3 */
/* @0xe451c ldr r0, [r3, #0x28] */  —— r0 = exec->[0x28] 当前帧
/* @0xe4520 bl 0xe42d8 <_Z13PerformReturnPhP6VMExec> */  —— sp2 = PerformReturn(frame, exec)

/* 在返回地址下方写 4 个零字 = 一个全零 RValue（tag 字 0） */
/* @0xe4524 mov r3, #0 */
/* @0xe4528 sub r1, r0, #16 */  —— r1 = sp2 - 16（将成为返回的 sp）
/* @0xe452c str r3, [r0, #-0x4] */
/* @0xe4530 str r3, [r0, #-0x10] */
/* @0xe4534 str r3, [r0, #-0xc] */
/* @0xe4538 mov r0, r1 */
/* @0xe453c pop {r3, pc} */
