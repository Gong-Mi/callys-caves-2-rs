/* cally 逆向卡：DoCallLibrary（原版 libyoyo.so，armv7）
 * @func 0xe3e58 0xe3fe8  size 400  100 条指令（含尾部 7 个 literal 字）
 * 级别: 正文（100 条逐条解码；调用协议、结果落点、剖析/异常三个旁路全局全部定名）
 * 符号: _Z13DoCallLibraryjPhPKhP6VMExec → uchar* DoCallLibrary(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   nargs = arg & 0xFFFF（uxth）                          ; e3e7c —— 只读低 16 位，高位未用
 *   idx   = *(uint32_t*)base                              ; e3e98
 *   table = *(void***)匿名静态槽（.bss 0x47a14c，无符号名）  ; e3e80 / e3ea8
 *   desc  = table + idx*0x50                              ; e3ea4 add r11,r2,r2,lsl#2（×5）→ e3eb0 lsl #4（×16）
 *   fn    = desc->[0x40]                                  ; e3eec / e3ef0 blx r11
 *   结果缓冲 = sp+0x10，16 B 先清零（tag 0 = Real 0）      ; e3e84..e3e90 —— 被调方不写就等于"返回 0"
 *   g_pFunction（4 B 指针，.data 0x47f288）调用前 = desc、返回后还原   ; e3ec8/e3ecc/e3ed0 / e3f00
 *   g_pCurrentExec（4 B 指针，0x47f298）= exec（调用之后发布）          ; e3efc..e3f10
 *   g_bProfile（1 B，0x757e7c）为真 → CProfiler::Push(g_Profiler,0) / Pop()  ; e3e80+e3eac+e3eb8 / e3fa8..e3fb8 / e3fbc
 *   g_Profiler 是 128 B 的 CProfiler 对象（0x757e80）                     ; e3fa8 / e3fbc
 *   g_fDoExceptionUnwind（1 B 标志，0x756470）为真 → 不释放实参、不压结果、返回 sp 原值 ; e3f18..e3f2c
 *   调用协议：fn(&result, exec->[0x14], exec->[0x18], nargs, args)        ; e3ed8/e3ee0/e3edc/e3ee4/e3ee8/e3ef0
 *   调用被 PushContextStack(0) / PopContextStack() 包住                    ; e3ed4 / e3ef4
 *   正常路径：逐个释放实参（(tag-1)&0x00FFFFFC==0 才 FREE_RValue__Pre），sp += nargs*16，
 *             把结果 16 B 压到 sp-16 并返回该地址                          ; e3f30..e3f98
 *   返回前把 exec 写进 g_pCurrentExec —— 库函数/异常/剖析都能拿到 VMExec   ; e3f10
 *
 * 结论：
 *   1. 库函数是"表驱动"：一条 opcode 只带 32 位表索引，函数指针在 desc+0x40，描述符步长固定 80 B。
 *   2. 调用协议 5 参 (RValue* ret, self, other, int nargs, uchar* args)：self/other 直接取自 exec+0x14/+0x18，
 *      所以库函数天然看得见 with 环境 —— 这正是 env 表作为第三张表存在的接口面。
 *   3. 三个旁路全局各司其职：g_pFunction（当前描述符，被调方回溯用）、g_pCurrentExec（当前 exec）、
 *      g_fDoExceptionUnwind（异常标志，一置位就放弃回收实参，把栈留给 unwind）。
 * open：匿名表（0x47a14c）的初始化点；descriptor 其余字段（+0..+0x4c）语义；nargs 上限只有 uxth（≤65535）、无越界检查。
 */

/* ── 段 1 · 序言 / PIC 基址 / 表索引（0xe3e58..0xe3eb8） ── */
/* @0xe3e58 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe3e5c mov r6, r1 */
/* @0xe3e60 ldr r4, [pc, #0x164] */
/* @0xe3e64 sub sp, sp, #36 */
/* @0xe3e68 ldr lr, [pc, #0x160] */
/* @0xe3e6c mov r12, #0 */
/* @0xe3e70 ldr r1, [pc, #0x15c] */
/* @0xe3e74 add r4, pc, r4 */
/* @0xe3e78 mov r5, r3 */
/* @0xe3e7c uxth r8, r0 */
/* @0xe3e80 ldr r3, [r4, lr] */
/* @0xe3e84 str r12, [sp, #0x10] */
/* @0xe3e88 str r12, [sp, #0x14] */
/* @0xe3e8c str r12, [sp, #0x18] */
/* @0xe3e90 str r12, [sp, #0x1c] */
/* @0xe3e94 ldr r1, [r4, r1] */
/* @0xe3e98 ldr r2, [r2] */
/* @0xe3e9c str r1, [sp, #0xc] */
/* @0xe3ea0 ldr r0, [sp, #0xc] */
/* @0xe3ea4 add r11, r2, r2, lsl #2 */
/* @0xe3ea8 ldr r1, [r3] */
/* @0xe3eac ldrb r3, [r0] */
/* @0xe3eb0 add r11, r1, r11, lsl #4 */
/* @0xe3eb4 cmp r3, r12 */
/* @0xe3eb8 bne 0xe3fa8 <_Z13DoCallLibraryjPhPKhP6VMExec+0x150> */

/* ── 段 2 · 发布 g_pFunction + 调用（0xe3ebc..e3ef4） ── */
/* @0xe3ebc ldr r3, [pc, #0x114] */
/* @0xe3ec0 mov r0, #0 */
/* @0xe3ec4 add r7, sp, #16 */
/* @0xe3ec8 ldr r9, [r4, r3] */
/* @0xe3ecc ldr r10, [r9] */
/* @0xe3ed0 str r11, [r9] */
/* @0xe3ed4 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe3ed8 ldr r1, [r5, #0x14] */
/* @0xe3edc mov r3, r8 */
/* @0xe3ee0 ldr r2, [r5, #0x18] */
/* @0xe3ee4 mov r0, r7 */
/* @0xe3ee8 str r6, [sp] */
/* @0xe3eec ldr r11, [r11, #0x40] */
/* @0xe3ef0 blx r11 */
/* @0xe3ef4 bl 0xd3a34 <_Z15PopContextStackv> */

/* ── 段 3 · 还原 + 发布 g_pCurrentExec + 异常闸（0xe3ef8..e3f2c） ── */
/* @0xe3ef8 ldr r1, [sp, #0xc] */
/* @0xe3efc ldr r3, [pc, #0xd8] */
/* @0xe3f00 str r10, [r9] */
/* @0xe3f04 ldrb r2, [r1] */
/* @0xe3f08 ldr r3, [r4, r3] */
/* @0xe3f0c cmp r2, #0 */
/* @0xe3f10 str r5, [r3] */
/* @0xe3f14 bne 0xe3fbc <_Z13DoCallLibraryjPhPKhP6VMExec+0x164> */
/* @0xe3f18 ldr r3, [pc, #0xc0] */
/* @0xe3f1c ldr r3, [r4, r3] */
/* @0xe3f20 ldrb r5, [r3] */
/* @0xe3f24 cmp r5, #0 */
/* @0xe3f28 movne r4, r6 */
/* @0xe3f2c bne 0xe3f9c <_Z13DoCallLibraryjPhPKhP6VMExec+0x144> */

/* ── 段 4 · 释放实参并压结果（0xe3f30..e3f9c） ── */
/* @0xe3f30 cmp r8, #0 */
/* @0xe3f34 beq 0xe3f80 <_Z13DoCallLibraryjPhPKhP6VMExec+0x128> */
/* @0xe3f38 mov r4, r6 */
/* @0xe3f3c b 0xe3f4c <_Z13DoCallLibraryjPhPKhP6VMExec+0xf4> */
/* @0xe3f40 cmp r5, r8 */
/* @0xe3f44 add r4, r4, #16 */
/* @0xe3f48 beq 0xe3f7c <_Z13DoCallLibraryjPhPKhP6VMExec+0x124> */
/* @0xe3f4c ldr r2, [r4, #0xc] */
/* @0xe3f50 add r5, r5, #1 */
/* @0xe3f54 sub r2, r2, #1 */
/* @0xe3f58 bic r2, r2, #-16777216 */
/* @0xe3f5c bic r2, r2, #3 */
/* @0xe3f60 cmp r2, #0 */
/* @0xe3f64 bne 0xe3f40 <_Z13DoCallLibraryjPhPKhP6VMExec+0xe8> */
/* @0xe3f68 mov r0, r4 */
/* @0xe3f6c add r4, r4, #16 */
/* @0xe3f70 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe3f74 cmp r5, r8 */
/* @0xe3f78 bne 0xe3f4c <_Z13DoCallLibraryjPhPKhP6VMExec+0xf4> */
/* @0xe3f7c add r6, r6, r5, lsl #4 */
/* @0xe3f80 ldm r7!, {r0, r1, r2, r3} */
/* @0xe3f84 sub r12, r6, #16 */
/* @0xe3f88 mov r4, r12 */
/* @0xe3f8c str r0, [r6, #-0x10] */
/* @0xe3f90 str r1, [r6, #-0xc] */
/* @0xe3f94 str r2, [r6, #-0x8] */
/* @0xe3f98 str r3, [r6, #-0x4] */
/* @0xe3f9c mov r0, r4 */
/* @0xe3fa0 add sp, sp, #36 */
/* @0xe3fa4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 段 5 · 剖析分支 + literal pool（0xe3fa8..e3fe4） ── */
/* @0xe3fa8 ldr r3, [pc, #0x34] */
/* @0xe3fac mov r1, r12 */
/* @0xe3fb0 ldr r0, [r4, r3] */
/* @0xe3fb4 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0xe3fb8 b 0xe3ebc <_Z13DoCallLibraryjPhPKhP6VMExec+0x64> */
/* @0xe3fbc ldr r3, [pc, #0x20] */
/* @0xe3fc0 ldr r0, [r4, r3] */
/* @0xe3fc4 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0xe3fc8 b 0xe3f18 <_Z13DoCallLibraryjPhPKhP6VMExec+0xc0> */
/* @0xe3fcc ldrsbteq sp, [r0], -r12 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xe3fd0 .word 0xffffbec8 */
/* @0xe3fd4 .word 0xffffbf18 */
/* @0xe3fd8 .word 0xffffbee0 */
/* @0xe3fdc .word 0xffffbf58 */
/* @0xe3fe0 .word 0xffffc0cc */
/* @0xe3fe4 .word 0xffffbf1c */
