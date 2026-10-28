/* cally 逆向卡：DoRet（原版 libyoyo.so，armv7）
 * @func 0xe3fe8 0xe42d8  size 752  188 条指令
 * 级别: 正文（188/188 逐条落锚；控制流、帧恢复、值搬运全解，字段符号名 open）
 * 符号: _Z5DoRetjPhPKhP6VMExec → uchar* DoRet(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   ++(*<GOT+0xffffc0d0>)                                  ; e4004-e4018（与 PerformReturn e42f4-e4300 同一槽）
 *   if (exec->[0x4c] == 0) goto 0xe4020                    ; e4004/e400c/e401c bne 0xe4058
 *   —— 深度 0：只复位取指，sp 原样返回（与 DoExit 0xe44e4-e4514 指令级同构）——
 *   exec->[0x44] = exec->[0x50]; exec->[0x48] = tbl[(p<0?p+3:p)>>2]; return sp   ; e4020-e404c
 *   —— 深度 != 0 ——
 *   sub = (arg >> 16) & 0xFF                               ; e4058 ubfx r0,r0,#0x10,#0x8
 *   if (sub > 15) → 0xe4248（size = 0，同 7..14）            ; e405c cmp #15 / e4060 addls pc,pc,r0,lsl #2
 *   16 项表（表基 0xe4068）唯一决定 memcpy 长度 size：
 *     sub 0→8(e4218) 1→4(e40a8) 2→4 3→8(e4218) 4→4 5→16(e4220) 6→4
 *     7..14 →0(e4248) 15→16 且先压一个 undefined(e4228)
 *   --exec->[0x4c]                                         ; e40b0/e40b4
 *   if (*<GOT+0xffffbf18>) CProfiler::Pop()                 ; e40b8-e40c4 → e42a0
 *   frame = exec->[0x28]; buf = frame->[0x18]               ; e40c8/e40cc
 *   if (!buf) return frame + 60                             ; e40d0-e40d8（r8 = frame+0x3c）
 *   帧 → exec 回写（本函数内逐条可查，见卡内注释）：        ; e40dc-e4140
 *     frame+0x00→exec+0x44  +0x04→exec+0x30  +0x10→exec+0x14  +0x14→exec+0x18
 *     +0x18→exec+0x2c       +0x1c→exec+0x38  +0x20→exec+0x3c  +0x24→exec+0x34
 *     +0x2c→exec+0x0c       +0x30→exec+0x10  +0x38→加到 exec+0x08
 *     +0x0c→参与 exec+0x28：>=0 时 exec+0x28 = exec+0x08 + exec+0x40 - frame+0x0c，否则 0
 *   if (exec->[0x0c] == 0) { YYObjectBase::Free(exec->[0x10]); }  ; e4140/e42b0-e42b4
 *   buf+0x10→exec+0x24  buf+0x04→exec+0x50  buf+0x14→exec+0x58  buf+0x18→exec+0x5c(指针表)
 *   exec->[0x48] = ptrtab[exec->[0x44] >>arithmetic 2]      ; e4170-e419c
 *   operator delete(frame->[0x28])                          ; e418c/e41a0
 *   —— 临时值栈清理与返回值搬运 ——
 *   n = *G1 (G1=*<GOT+0xffffc0bc>); base = *G2 (G2=*<GOT+0xffffc0c0>)   ; e41a4-e41c8
 *   for (i = 0; i < n; i++) { if ((tag-1)&~0xFF000000&~3 == 0) FREE_RValue__Pre(slot);
 *                             *slot = {0,0,0,5}; slot++ }              ; e41d0-e4214
 *   dst = frame + 0x2c + n*16  (= frame + 0x3c + (n-1)*16)              ; e4258-e4264
 *   *G1 = frame->[0x08]; *G2 = exec->[0x08] + frame->[0x38]             ; e4268-e428c
 *   memcpy(dst, sp, size); return dst                                   ; e4290/e4294
 *
 * 结论（新增五条硬事实）：
 *   1. DoRet 的返回值**不留在值栈上**：它被搬进帧内 frame+0x2c+n*16 这个槽（恰好是「局部槽
 *      下方一格」），并用该地址作为新 sp 返回 —— 即返回值槽与局部区共用同一套 16 字节槽，
 *      由全局计数 n 定位。这解释了 DoExit 为什么要自己再压一个零 RValue。
 *   2. 两个全局（GOT 0xffffc0bc / 0xffffc0c0）分别是「临时 RValue 计数」与「临时 RValue 基址」；
 *      返回时前者由 frame+0x08 恢复、后者由 exec+0x08 + frame+0x38 恢复 —— 说明它们就是
 *      VM 的值栈游标，帧里保存的是进入时的快照。
 *   3. 子种类只决定 memcpy 字节数（0/4/8/16），不改控制流：4=int、8=double、16=整 RValue、
 *      0=不覆盖（复用现槽）。16 个 opcode 变体因此归一成一个 size 参数。
 *   4. 帧弹出段（e40dc-e4140）与 PerformReturn e4334-e43a4 的**字段映射逐项一致**（寄存器分配
 *      不同、指令顺序微调），可以判定 DoRet 是「PerformReturn 内联 + 带值返回」的合并版本。
 *   5. 释放判据在四处一致：`(tag-1) & ~0xFF000000 & ~3 == 0` ⇔ **tag ∈ {1,2,3,4}**
 *      （DoRet e41f8-e4204 / PerformReturn e444c-e4458 / DoPop e6800-e6814）。
 * open：各帧字段的符号名（self / other / args / 字节码指针 / 局部基址 / VMBuffer）；
 *       G1、G2 两个全局的符号名；sub ∈ 7..14 时 size=0 的业务含义（「不覆盖返回值槽」）；
 *       exec+0x40 与 exec+0x08 的语义（前者与 frame+0x0c 相减，疑似局部区字节数）。
 */

/* 序言：r5 = exec、r8 = sp、r4 = GOT 基址；随后取全局计数并 ++ */
/* @0xe3fe8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe3fec mov r5, r3 */  —— r5 = exec
/* @0xe3ff0 ldr r4, [pc, #0x2c8] */
/* @0xe3ff4 mov r8, r1 */  —— r8 = sp
/* @0xe3ff8 ldr r3, [pc, #0x2c4] */
/* @0xe3ffc sub sp, sp, #12 */
/* @0xe4000 add r4, pc, r4 */
/* @0xe4004 ldr r2, [r5, #0x4c] */  —— r2 = 帧深度
/* @0xe4008 ldr r3, [r4, r3] */
/* @0xe400c cmp r2, #0 */
/* @0xe4010 ldr r1, [r3] */  —— ++全局返回计数
/* @0xe4014 add r1, r1, #1 */
/* @0xe4018 str r1, [r3] */
/* @0xe401c bne 0xe4058 <_Z5DoRetjPhPKhP6VMExec+0x70> */  —— 深度 != 0 → 走真正的返回

/* 深度 0 出口：取指复位（exec+0x44/+0x48），sp 原样返回 */
/* @0xe4020 ldr r2, [r5, #0x5c] */
/* @0xe4024 ldr r3, [r5, #0x50] */
/* @0xe4028 cmp r2, #0 */
/* @0xe402c str r3, [r5, #0x44] */  —— exec->[0x44] = exec->[0x50]
/* @0xe4030 beq 0xe4048 <_Z5DoRetjPhPKhP6VMExec+0x60> */
/* @0xe4034 add r1, r3, #3 */
/* @0xe4038 cmp r3, #0 */
/* @0xe403c movlt r3, r1 */
/* @0xe4040 asr r3, r3, #2 */
/* @0xe4044 ldr r2, [r2, r3, lsl #2] */
/* @0xe4048 str r2, [r5, #0x48] */  —— exec->[0x48] = tbl[code>>2]
/* @0xe404c mov r0, r8 */
/* @0xe4050 add sp, sp, #12 */
/* @0xe4054 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* 子种类 sub = (arg>>16)&0xFF；16 项跳转表，表基 = 0xe4068（addls 在 0xe4060） */
/* @0xe4058 ubfx r0, r0, #0x10, #0x8 */  —— sub = 高 8 位（bit16..23）
/* @0xe405c cmp r0, #15 */
/* @0xe4060 addls pc, pc, r0, lsl #2 */

/* 默认（sub>15）：size = 0，即不拷返回值 */
/* @0xe4064 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */

/* 表项：sub 0 → 0xe4218（size 8，double） */
/* @0xe4068 b 0xe4218 <_Z5DoRetjPhPKhP6VMExec+0x230> */

/* sub 1 → 0xe40a8（size 4，int） */
/* @0xe406c b 0xe40a8 <_Z5DoRetjPhPKhP6VMExec+0xc0> */
/* @0xe4070 b 0xe40a8 <_Z5DoRetjPhPKhP6VMExec+0xc0> */

/* sub 3 → 0xe4218（size 8） */
/* @0xe4074 b 0xe4218 <_Z5DoRetjPhPKhP6VMExec+0x230> */
/* @0xe4078 b 0xe40a8 <_Z5DoRetjPhPKhP6VMExec+0xc0> */

/* sub 5 → 0xe4220（size 16，整 RValue） */
/* @0xe407c b 0xe4220 <_Z5DoRetjPhPKhP6VMExec+0x238> */
/* @0xe4080 b 0xe40a8 <_Z5DoRetjPhPKhP6VMExec+0xc0> */

/* sub 7..14 → 0xe4248（size 0） */
/* @0xe4084 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe4088 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe408c b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe4090 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe4094 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe4098 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe409c b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */
/* @0xe40a0 b 0xe4248 <_Z5DoRetjPhPKhP6VMExec+0x260> */

/* sub 15 → 0xe4228（先压 tag 5 = undefined，再 size 16） */
/* @0xe40a4 b 0xe4228 <_Z5DoRetjPhPKhP6VMExec+0x240> */
/* @0xe40a8 mov r11, #4 */

/* 公共段：帧深度自减；调试字节置位时先 CProfiler::Pop() */
/* @0xe40ac ldr r3, [pc, #0x214] */
/* @0xe40b0 sub r2, r2, #1 */  —— depth--
/* @0xe40b4 str r2, [r5, #0x4c] */
/* @0xe40b8 ldr r3, [r4, r3] */
/* @0xe40bc ldrb r3, [r3] */
/* @0xe40c0 cmp r3, #0 */
/* @0xe40c4 bne 0xe42a0 <_Z5DoRetjPhPKhP6VMExec+0x2b8> */

/* frame = exec->[0x28]；frame+0x18 = VMBuffer*，为 0 时直接返回 frame+0x3c */
/* @0xe40c8 ldr r10, [r5, #0x28] */  —— r10 = frame
/* @0xe40cc ldr r6, [r10, #0x18] */  —— r6 = frame->[0x18]（VMBuffer*）
/* @0xe40d0 cmp r6, #0 */
/* @0xe40d4 addeq r8, r10, #60 */  —— 无 buffer：返回 frame+0x3c（局部区基址）
/* @0xe40d8 beq 0xe404c <_Z5DoRetjPhPKhP6VMExec+0x64> */

/* 帧 → exec 回写段（与 PerformReturn e4334-e43a4 字段映射一致） */
/* @0xe40dc ldr r3, [r10, #0xc] */  —— frame+0x0c 起逐字段回写 exec
/* @0xe40e0 ldr r0, [r10, #0x24] */
/* @0xe40e4 ldr r1, [r10, #0x4] */
/* @0xe40e8 cmp r3, #0 */
/* @0xe40ec ldr r2, [r10, #0x10] */
/* @0xe40f0 ldr r9, [r10, #0x14] */
/* @0xe40f4 movlt r3, #0 */
/* @0xe40f8 ldr r7, [r10] */
/* @0xe40fc ldr lr, [r10, #0x1c] */
/* @0xe4100 ldr r12, [r10, #0x20] */
/* @0xe4104 str r0, [r5, #0x34] */
/* @0xe4108 ldrge r0, [r5, #0x40] */  —— exec+0x40 - frame+0x0c
/* @0xe410c str r1, [r5, #0x30] */
/* @0xe4110 ldrge r1, [r5, #0x8] */
/* @0xe4114 rsbge r3, r3, r0 */
/* @0xe4118 str r2, [r5, #0x14] */
/* @0xe411c addge r3, r1, r3 */
/* @0xe4120 ldr r1, [r5, #0xc] */
/* @0xe4124 str r9, [r5, #0x18] */
/* @0xe4128 cmp r1, #0 */
/* @0xe412c str r7, [r5, #0x44] */
/* @0xe4130 str r6, [r5, #0x2c] */
/* @0xe4134 str lr, [r5, #0x38] */
/* @0xe4138 str r12, [r5, #0x3c] */
/* @0xe413c str r3, [r5, #0x28] */  —— exec->[0x28] = 父帧指针
/* @0xe4140 beq 0xe42b0 <_Z5DoRetjPhPKhP6VMExec+0x2c8> */

/* VMBuffer 收尾：convertBuffer、把 +0x14/+0x18 写进 exec+0x58/+0x5c，再 delete frame+0x28 */
/* @0xe4144 ldr r1, [r6, #0x10] */  —— buf+0x10 → exec+0x24
/* @0xe4148 mov r0, r6 */
/* @0xe414c ldr r3, [r6, #0x4] */  —— buf+0x04 → exec+0x50
/* @0xe4150 ldr lr, [r10, #0x30] */
/* @0xe4154 ldr r12, [r10, #0x2c] */
/* @0xe4158 str r1, [r5, #0x24] */
/* @0xe415c str lr, [r5, #0x10] */
/* @0xe4160 str r12, [r5, #0xc] */
/* @0xe4164 str r3, [r5, #0x50] */
/* @0xe4168 bl 0xec750 <_ZN8VMBuffer13convertBufferEv> */  —— VMBuffer::convertBuffer()
/* @0xe416c ldr r3, [r5, #0x44] */
/* @0xe4170 ldr r1, [r5, #0x2c] */
/* @0xe4174 cmp r3, #0 */
/* @0xe4178 add r0, r3, #3 */
/* @0xe417c ldr r12, [r6, #0x14] */  —— buf+0x14 → exec+0x58
/* @0xe4180 ldr r1, [r1, #0x18] */
/* @0xe4184 movlt r3, r0 */
/* @0xe4188 asr r3, r3, #2 */
/* @0xe418c ldr r0, [r10, #0x28] */
/* @0xe4190 str r12, [r5, #0x58] */
/* @0xe4194 ldr r3, [r1, r3, lsl #2] */
/* @0xe4198 str r1, [r5, #0x5c] */  —— exec->[0x5c] = 指针表
/* @0xe419c str r3, [r5, #0x48] */  —— exec->[0x48] = ptrtab[code>>2]
/* @0xe41a0 bl 0x27d1d0 <_ZdlPv> */  —— delete frame->[0x28]

/* 取两个全局游标：G1 = 临时 RValue 计数、G2 = 临时 RValue 基址 */
/* @0xe41a4 ldr r1, [pc, #0x120] */
/* @0xe41a8 ldr r3, [pc, #0x120] */
/* @0xe41ac ldr r1, [r4, r1] */
/* @0xe41b0 str r1, [sp] */
/* @0xe41b4 ldr r3, [r4, r3] */
/* @0xe41b8 str r3, [sp, #0x4] */
/* @0xe41bc ldr r3, [r1] */
/* @0xe41c0 ldr r2, [sp, #0x4] */
/* @0xe41c4 subs r6, r3, #1 */  —— i = n-1（n = 临时 RValue 个数）
/* @0xe41c8 ldr r4, [r2] */
/* @0xe41cc bmi 0xe4258 <_Z5DoRetjPhPKhP6VMExec+0x270> */

/* 清理循环：tag∈{1,2,3,4} 的槽先 FREE_RValue__Pre，然后把槽改写成 {0,0,0,5} */
/* @0xe41d0 mov r7, #0 */
/* @0xe41d4 mov r9, #5 */
/* @0xe41d8 b 0xe41f0 <_Z5DoRetjPhPKhP6VMExec+0x208> */
/* @0xe41dc cmn r6, #1 */
/* @0xe41e0 str r7, [r4, #0x8] */
/* @0xe41e4 str r9, [r4, #0xc] */
/* @0xe41e8 str r7, [r4], #16 */
/* @0xe41ec beq 0xe4250 <_Z5DoRetjPhPKhP6VMExec+0x268> */
/* @0xe41f0 ldr r3, [r4, #0xc] */
/* @0xe41f4 sub r6, r6, #1 */
/* @0xe41f8 sub r3, r3, #1 */  —— （tag-1）& ~0xFF000000 & ~3
/* @0xe41fc bic r3, r3, #-16777216 */
/* @0xe4200 bic r3, r3, #3 */
/* @0xe4204 cmp r3, #0 */
/* @0xe4208 bne 0xe41dc <_Z5DoRetjPhPKhP6VMExec+0x1f4> */
/* @0xe420c mov r0, r4 */
/* @0xe4210 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */  —— FREE_RValue__Pre(slot)
/* @0xe4214 b 0xe41dc <_Z5DoRetjPhPKhP6VMExec+0x1f4> */

/* size = 8 入口 */
/* @0xe4218 mov r11, #8 */
/* @0xe421c b 0xe40ac <_Z5DoRetjPhPKhP6VMExec+0xc4> */

/* size = 16 入口 */
/* @0xe4220 mov r11, #16 */
/* @0xe4224 b 0xe40ac <_Z5DoRetjPhPKhP6VMExec+0xc4> */

/* size = 16 且返回值 = undefined（tag 5） */
/* @0xe4228 mov r3, #0 */
/* @0xe422c mov r1, #5 */
/* @0xe4230 str r3, [r8, #-0x10] */
/* @0xe4234 mov r11, #16 */
/* @0xe4238 str r3, [r8, #-0xc] */
/* @0xe423c sub r8, r8, #16 */
/* @0xe4240 str r1, [r8, #0xc] */
/* @0xe4244 b 0xe40ac <_Z5DoRetjPhPKhP6VMExec+0xc4> */

/* size = 0 入口：不做 memcpy，返回值槽保持原样 */
/* @0xe4248 mov r11, #0 */
/* @0xe424c b 0xe40ac <_Z5DoRetjPhPKhP6VMExec+0xc4> */
/* @0xe4250 ldr r4, [sp] */
/* @0xe4254 ldr r3, [r4] */

/* 返回值槽 dst = frame + 0x2c + n*16；同时恢复两个全局游标 */
/* @0xe4258 ldr r4, [r5, #0x8] */  —— r4 = exec->[0x08]（值栈基址）
/* @0xe425c add r3, r10, r3, lsl #4 */  —— dst = frame + n*16 + 0x2c
/* @0xe4260 ldr r12, [r10, #0x38] */
/* @0xe4264 add r3, r3, #44 */
/* @0xe4268 ldr lr, [r10, #0x8] */
/* @0xe426c mov r1, r8 */
/* @0xe4270 add r12, r4, r12 */
/* @0xe4274 ldr r4, [sp] */
/* @0xe4278 mov r2, r11 */
/* @0xe427c mov r0, r3 */
/* @0xe4280 mov r8, r3 */
/* @0xe4284 str lr, [r4] */  —— *G1 = frame->[0x08]（恢复计数）
/* @0xe4288 ldr r4, [sp, #0x4] */
/* @0xe428c str r12, [r4] */  —— *G2 = exec->[0x08] + frame->[0x38]
/* @0xe4290 bl 0xb65bc <memcpy@plt> */  —— memcpy(dst, sp, size)
/* @0xe4294 mov r0, r8 */
/* @0xe4298 add sp, sp, #12 */
/* @0xe429c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* 调试字节置位路径：CProfiler::Pop() 后继续 */
/* @0xe42a0 ldr r3, [pc, #0x2c] */
/* @0xe42a4 ldr r0, [r4, r3] */
/* @0xe42a8 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0xe42ac b 0xe40c8 <_Z5DoRetjPhPKhP6VMExec+0xe0> */

/* exec+0x0c == 0：先 YYObjectBase::Free(exec->[0x10])，再用 exec->[0x2c] 当 buf */
/* @0xe42b0 ldr r0, [r5, #0x10] */
/* @0xe42b4 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xe42b8 ldr r6, [r5, #0x2c] */
/* @0xe42bc b 0xe4144 <_Z5DoRetjPhPKhP6VMExec+0x15c> */

/* 字面量池（objdump 按指令解码的第一字其实也是池数据） */
/* @0xe42c0 eorseq sp, r0, r0, asr r12 */
/* @0xe42c4 .word 0xffffc0d0 */
/* @0xe42c8 .word 0xffffbf18 */
/* @0xe42cc .word 0xffffc0bc */
/* @0xe42d0 .word 0xffffc0c0 */
/* @0xe42d4 .word 0xffffbf1c */
