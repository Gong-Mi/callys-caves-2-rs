/* cally 逆向卡：DoXor（原版 libyoyo.so，armv7）
 * @func 0xe00d8 0xe096c  size 2196  549 条指令（含 literal 词）
 * 级别: 骨架（arg 位域 / 双格式码分派 / 10 条内核（含 bool）/ 全部错误分支已证；返回值口径未定，不升正文）
 * 符号: _Z5DoXorjPhPKhP6VMExec → uchar* DoXor(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   慢路径开关与 DoSub 不同：**bits[11:8] 任一非零**就走 box 路径：@0xe00d8 tst r0, #3840 —— tst 掩码 0xF00；@0xe00f0 bne 0xe0124 <_Z5DoXorjPhPKhP6VMExec+0x4c> —— bne 0xe0124
 *   byte=(arg>>16)&0xFF=(Afmt<<4)|Bfmt（高 nibble=A）：@0xe00e0 lsr r5, r0, #16 —— arg>>16；@0xe00f4 uxtb r4, r5 —— uxtb；@0xe00f8 and r2, r4, #15 —— 取低 nibble（B）
 *   表1 按 B 的格式码定 A 的地址：@0xe0100 addls pc, pc, r2, lsl #2 —— 7 项表；@0xe01c4 add r10, r1, #8 —— B 8 字节 → A=arg2+8；@0xe0514 add r10, r1, #4 —— B 4 字节 → A=arg2+4
 *   表2 按 A 的格式码算 r6=A+4 / A+8：@0xe01cc asr r2, r5, #4 —— asr #4；@0xe01d4 addls pc, pc, r2, lsl #2 —— 第二级表；@0xe050c add r6, r10, #8 —— r6=A+8
 *   B 从 [arg2] 读、A 从 arg2+4/arg2+8 读：@0xe0648 ldrd r0, r1, [r9] —— ldrd r0,r1,[r9]（r9=arg2）取 B
 *   表3 按整字节（0..85）→ dest，等价于 dest=A+size(A)−max(size(A),size(B))：@0xe020c cmp r4, #85 —— 上界 85；@0xe0210 addls pc, pc, r4, lsl #2 —— 86 项表
 *   表4 按同一字节（0..68）→ 10 条内核（比 DoSub 多一条 bool×bool）：@0xe037c cmp r5, #68 —— 上界 68；@0xe0380 addls pc, pc, r5, lsl #2 —— 69 项表
 *   结果 tag：0=double、7=int32、10=int64、13=bool，只在 r7≠0 时写 [r7+0xc]：@0xe05c8 str r12, [r7, #0xc] —— 条件写
 *   bool×bool 走逻辑异或并写 tag 13：@0xe0668 ldr r3, [r10] —— 入口；@0xe0680 eorne r3, r3, #1 —— eorne 才是异或；@0xe066c mov r12, #13 —— tag=13
 *   实数参与时不保留小数：__fixdfdi 截断成 int64，异或后 __floatdidf 回 double：@0xe063c bl 0x3194a0 <__fixdfdi> —— A 截断；@0xe0658 bl 0x319164 <__floatdidf> —— 回 double
 *   int64×int64 双字 eor（tag 10）：@0xe05b0 eor r2, r2, r0 —— 低字；@0xe05b4 eor r3, r3, r1 —— 高字；@0xe05a8 mov r12, #10 —— tag=10
 *   int32×int32 单字 eor（tag 7）：@0xe06c4 eor r3, r2, r3 —— eor；@0xe06bc mov r12, #7 —— tag=7
 *   慢路径 = boxType×2 + F_JS_ToInt32×2 + 32 位 eor + 回 double：@0xe01a4 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> —— 第一次 ToInt32；@0xe0704 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> —— 第二次；@0xe074c eor r2, r2, r3 —— 32 位 eor
 *
 * 结论（新增 4 条硬事实）：
 *   1. 位运算符的 arg 与 DoSub 同构（两段格式码 + bits[11:8] 慢路径开关），但**开关判定不同**：DoSub/DoDiv 要求
 *      bits[11:8]==1，DoXor/DoAnd/DoShl 是"任一位置 1"。同一 VM 里两套模板并存。
 *   2. 实数参与异或时不按浮点位做，而是 __fixdfdi 截断成 int64 再异或（向零取整），最后 __floatdidf 回 double：
 *      即 (int64)a ^ (int64)b 再转回实数，结果 tag 仍是 0（double）。
 *   3. 这是六个里唯一把 bool 单独建模的一个：只有 (4,4) 组合写 tag 13 的逻辑异或，其余带 4 的组合
 *      （(4,0)/(4,2)/(4,3)/(0,4)…）全部落进 VMError；DoAnd 只允许 bool 与 real 混算。
 *   4. 每档内核自带 tag 常量（0/7/10/13），错误分支只写 tag 不写值，然后统一返回 r6。
 * open：
 *   · 表3 的条目数随函数变化（DoSub 到 101，DoDiv/DoXor/DoAnd/DoShl/DoRem 都到 85），说明 dest 表只覆盖"编译器会发射的组合"，
 *     未列出的组合没有 dest；本卡已用 dest=A+size(A)−max(size) 复算通过全部已列出项。
 *   · 格式码 5 路径里 0xe07b0 把 16 加到 r6（DoSub 是加到 r10），两条模板对 A 的落点写法不同，未统一解释。
 *   · 返回值是"新 sp"还是"新 ip"未定；尾部 0xe0928..0xe0968 是 literal pool（objdump 译成 eoreq/mla），逐字保留。
 */
/* @0xe00d8 tst r0, #3840   ——慢路径开关：tst bits[11:8]（任一非零即 box） */
/* @0xe00dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe00e0 lsr r5, r0, #16   ——r5=arg>>16 */
/* @0xe00e4 sub sp, sp, #68 */
/* @0xe00e8 mov r9, r1 */
/* @0xe00ec mov r11, r3 */
/* @0xe00f0 bne 0xe0124 <_Z5DoXorjPhPKhP6VMExec+0x4c>   ——→ 0xe0124 */
/* @0xe00f4 uxtb r4, r5   ——r4=类型字节 */
/* @0xe00f8 and r2, r4, #15   ——取 B 的 nibble */
/* @0xe00fc cmp r2, #6   ——表1 上界 6 */
/* @0xe0100 addls pc, pc, r2, lsl #2   ——表1：按 Bfmt → A 指针 */
/* @0xe0104 b 0xe0914 <_Z5DoXorjPhPKhP6VMExec+0x83c> */
/* @0xe0108 b 0xe01c4 <_Z5DoXorjPhPKhP6VMExec+0xec>   ——Bfmt 0/3 → A=arg2+8 */
/* @0xe010c b 0xe0514 <_Z5DoXorjPhPKhP6VMExec+0x43c> */
/* @0xe0110 b 0xe0514 <_Z5DoXorjPhPKhP6VMExec+0x43c> */
/* @0xe0114 b 0xe01c4 <_Z5DoXorjPhPKhP6VMExec+0xec> */
/* @0xe0118 b 0xe0514 <_Z5DoXorjPhPKhP6VMExec+0x43c> */
/* @0xe011c b 0xe0520 <_Z5DoXorjPhPKhP6VMExec+0x448> */
/* @0xe0120 b 0xe0568 <_Z5DoXorjPhPKhP6VMExec+0x490>   ——Bfmt=6（内联字符串常量）→ VMError */
/* @0xe0124 add r4, sp, #16   ——慢路径：box 成 sp+16 / sp 两个 RValue */
/* @0xe0128 uxtb r5, r5 */
/* @0xe012c mov r2, r1 */
/* @0xe0130 and r1, r5, #15 */
/* @0xe0134 mov r0, r4 */
/* @0xe0138 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh>   ——boxType(sp+16,Afmt,arg2) */
/* @0xe013c lsr r1, r5, #4 */
/* @0xe0140 mov r2, r0 */
/* @0xe0144 mov r0, sp */
/* @0xe0148 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe014c ldr r3, [sp, #0xc] */
/* @0xe0150 mvn r12, #-16777216 */
/* @0xe0154 and r3, r3, r12 */
/* @0xe0158 cmp r3, r12 */
/* @0xe015c mov r6, r0 */
/* @0xe0160 beq 0xe08cc <_Z5DoXorjPhPKhP6VMExec+0x7f4> */
/* @0xe0164 ldr r3, [sp, #0x1c] */
/* @0xe0168 bic r3, r3, #-16777216 */
/* @0xe016c cmp r3, r12 */
/* @0xe0170 beq 0xe0590 <_Z5DoXorjPhPKhP6VMExec+0x4b8> */
/* @0xe0174 add r5, sp, #32 */
/* @0xe0178 mov r1, sp */
/* @0xe017c mov r2, #0 */
/* @0xe0180 mov r3, #0 */
/* @0xe0184 mov r0, r5 */
/* @0xe0188 str r12, [sp, #0x2c] */
/* @0xe018c str r12, [sp, #0x3c] */
/* @0xe0190 mov r12, #0 */
/* @0xe0194 strd r2, r3, [sp, #32] */
/* @0xe0198 strd r2, r3, [sp, #48] */
/* @0xe019c str r12, [sp, #0x28] */
/* @0xe01a0 str r12, [sp, #0x38] */
/* @0xe01a4 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xe01a8 cmp r0, #1 */
/* @0xe01ac beq 0xe08e0 <_Z5DoXorjPhPKhP6VMExec+0x808> */
/* @0xe01b0 cmp r0, #0 */
/* @0xe01b4 beq 0xe06f8 <_Z5DoXorjPhPKhP6VMExec+0x620> */
/* @0xe01b8 mov r0, r6 */
/* @0xe01bc add sp, sp, #68 */
/* @0xe01c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe01c4 add r10, r1, #8 */
/* @0xe01c8 mov r5, r4 */
/* @0xe01cc asr r2, r5, #4   ——取 A 的 nibble */
/* @0xe01d0 cmp r2, #6 */
/* @0xe01d4 addls pc, pc, r2, lsl #2   ——表2：按 Afmt → r6 */
/* @0xe01d8 b 0xe0920 <_Z5DoXorjPhPKhP6VMExec+0x848> */
/* @0xe01dc b 0xe050c <_Z5DoXorjPhPKhP6VMExec+0x434> */
/* @0xe01e0 b 0xe0504 <_Z5DoXorjPhPKhP6VMExec+0x42c> */
/* @0xe01e4 b 0xe0504 <_Z5DoXorjPhPKhP6VMExec+0x42c> */
/* @0xe01e8 b 0xe050c <_Z5DoXorjPhPKhP6VMExec+0x434> */
/* @0xe01ec b 0xe0504 <_Z5DoXorjPhPKhP6VMExec+0x42c> */
/* @0xe01f0 b 0xe04bc <_Z5DoXorjPhPKhP6VMExec+0x3e4> */
/* @0xe01f4 b 0xe01f8 <_Z5DoXorjPhPKhP6VMExec+0x120> */
/* @0xe01f8 ldr r1, [pc, #0x728]   ——Afmt=6 → VMError */
/* @0xe01fc mov r0, r11 */
/* @0xe0200 mov r6, r10 */
/* @0xe0204 add r1, pc, r1 */
/* @0xe0208 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe020c cmp r4, #85   ——表3 上界 85 */
/* @0xe0210 addls pc, pc, r4, lsl #2   ——表3：按整字节 (Afmt<<4)|Bfmt → dest */
/* @0xe0214 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0218 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe021c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0220 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe0224 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe0228 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe022c b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe0230 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0234 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0238 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe023c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0240 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0244 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0248 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe024c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0250 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0254 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0258 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe025c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0260 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0264 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0268 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe026c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0270 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0274 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0278 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe027c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0280 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0284 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0288 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe028c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0290 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0294 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0298 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe029c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02a0 b 0xe0370 <_Z5DoXorjPhPKhP6VMExec+0x298> */
/* @0xe02a4 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe02a8 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02ac b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe02b0 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02b4 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02b8 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02bc b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02c0 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02c4 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02c8 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02cc b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02d0 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02d4 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02d8 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe02dc b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02e0 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe02e4 b 0xe04ac <_Z5DoXorjPhPKhP6VMExec+0x3d4> */
/* @0xe02e8 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02ec b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe02f0 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02f4 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02f8 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe02fc b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0300 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0304 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0308 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe030c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0310 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0314 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0318 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe031c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0320 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0324 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0328 b 0xe0370 <_Z5DoXorjPhPKhP6VMExec+0x298> */
/* @0xe032c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0330 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0334 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0338 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe033c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0340 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0344 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0348 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe034c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0350 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0354 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0358 b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe035c b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe0360 b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe0364 b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe0368 b 0xe0584 <_Z5DoXorjPhPKhP6VMExec+0x4ac> */
/* @0xe036c b 0xe049c <_Z5DoXorjPhPKhP6VMExec+0x3c4> */
/* @0xe0370 sub r6, r6, #4   ——dest=r6-4（bool/int32 短槽） */
/* @0xe0374 mov r7, #0 */
/* @0xe0378 mov r8, r6 */
/* @0xe037c cmp r5, #68   ——表4 上界 68 */
/* @0xe0380 addls pc, pc, r5, lsl #2   ——表4：类型对→内核 */
/* @0xe0384 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0388 b 0xe0638 <_Z5DoXorjPhPKhP6VMExec+0x560> */
/* @0xe038c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0390 b 0xe0614 <_Z5DoXorjPhPKhP6VMExec+0x53c> */
/* @0xe0394 b 0xe05f0 <_Z5DoXorjPhPKhP6VMExec+0x518> */
/* @0xe0398 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe039c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03a0 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03a4 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03a8 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03ac b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03b0 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03b4 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03b8 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03bc b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03c0 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03c4 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03c8 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03cc b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03d0 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03d4 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03d8 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03dc b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03e0 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03e4 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03e8 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03ec b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03f0 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03f4 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03f8 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe03fc b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0400 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0404 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0408 b 0xe06d0 <_Z5DoXorjPhPKhP6VMExec+0x5f8> */
/* @0xe040c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0410 b 0xe06b8 <_Z5DoXorjPhPKhP6VMExec+0x5e0> */
/* @0xe0414 b 0xe069c <_Z5DoXorjPhPKhP6VMExec+0x5c4> */
/* @0xe0418 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe041c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0420 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0424 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0428 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe042c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0430 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0434 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0438 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe043c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0440 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0444 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0448 b 0xe068c <_Z5DoXorjPhPKhP6VMExec+0x5b4> */
/* @0xe044c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0450 b 0xe05d4 <_Z5DoXorjPhPKhP6VMExec+0x4fc> */
/* @0xe0454 b 0xe05a4 <_Z5DoXorjPhPKhP6VMExec+0x4cc> */
/* @0xe0458 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe045c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0460 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0464 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0468 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe046c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0470 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0474 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0478 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe047c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0480 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0484 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0488 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe048c b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0490 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0494 b 0xe06e0 <_Z5DoXorjPhPKhP6VMExec+0x608> */
/* @0xe0498 b 0xe0668 <_Z5DoXorjPhPKhP6VMExec+0x590> */
/* @0xe049c sub r7, r6, #16   ——dest=r6-16（r7=r8=r6-16，写 tag） */
/* @0xe04a0 mov r8, r7 */
/* @0xe04a4 mov r6, r7 */
/* @0xe04a8 b 0xe037c <_Z5DoXorjPhPKhP6VMExec+0x2a4> */
/* @0xe04ac sub r6, r6, #8   ——dest=r6-8（r7=0） */
/* @0xe04b0 mov r7, #0 */
/* @0xe04b4 mov r8, r6 */
/* @0xe04b8 b 0xe037c <_Z5DoXorjPhPKhP6VMExec+0x2a4> */
/* @0xe04bc ldr r3, [r10, #0xc]   ——Afmt 5：读 [A+0xc] 的 tag */
/* @0xe04c0 cmp r3, #13 */
/* @0xe04c4 addls pc, pc, r3, lsl #2   ——Afmt=5：按 [A+0xc] 的 tag 分派 */
/* @0xe04c8 b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe04cc b 0xe07e0 <_Z5DoXorjPhPKhP6VMExec+0x708> */
/* @0xe04d0 b 0xe07cc <_Z5DoXorjPhPKhP6VMExec+0x6f4> */
/* @0xe04d4 b 0xe07b8 <_Z5DoXorjPhPKhP6VMExec+0x6e0> */
/* @0xe04d8 b 0xe07fc <_Z5DoXorjPhPKhP6VMExec+0x724> */
/* @0xe04dc b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe04e0 b 0xe07e8 <_Z5DoXorjPhPKhP6VMExec+0x710> */
/* @0xe04e4 b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe04e8 b 0xe0810 <_Z5DoXorjPhPKhP6VMExec+0x738> */
/* @0xe04ec b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe04f0 b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe04f4 b 0xe07a8 <_Z5DoXorjPhPKhP6VMExec+0x6d0> */
/* @0xe04f8 b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe04fc b 0xe08a0 <_Z5DoXorjPhPKhP6VMExec+0x7c8> */
/* @0xe0500 b 0xe07e0 <_Z5DoXorjPhPKhP6VMExec+0x708> */
/* @0xe0504 add r6, r10, #4   ——Afmt 1/2/4 → r6=A+4 */
/* @0xe0508 b 0xe020c <_Z5DoXorjPhPKhP6VMExec+0x134> */
/* @0xe050c add r6, r10, #8   ——Afmt 0/3 → r6=A+8 */
/* @0xe0510 b 0xe020c <_Z5DoXorjPhPKhP6VMExec+0x134> */
/* @0xe0514 add r10, r1, #4 */
/* @0xe0518 mov r5, r4   ——Bfmt 1/2/4 → A=arg2+4 */
/* @0xe051c b 0xe01cc <_Z5DoXorjPhPKhP6VMExec+0xf4> */
/* @0xe0520 ldr r3, [r1, #0xc]   ——Bfmt 5：读 [arg2+0xc] 的 tag */
/* @0xe0524 cmp r3, #13 */
/* @0xe0528 addls pc, pc, r3, lsl #2   ——Bfmt=5：按 [arg2+0xc] 的 tag 分派 */
/* @0xe052c b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe0530 b 0xe0850 <_Z5DoXorjPhPKhP6VMExec+0x778> */
/* @0xe0534 b 0xe0838 <_Z5DoXorjPhPKhP6VMExec+0x760> */
/* @0xe0538 b 0xe081c <_Z5DoXorjPhPKhP6VMExec+0x744> */
/* @0xe053c b 0xe0888 <_Z5DoXorjPhPKhP6VMExec+0x7b0> */
/* @0xe0540 b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe0544 b 0xe0870 <_Z5DoXorjPhPKhP6VMExec+0x798> */
/* @0xe0548 b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe054c b 0xe0864 <_Z5DoXorjPhPKhP6VMExec+0x78c> */
/* @0xe0550 b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe0554 b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe0558 b 0xe0858 <_Z5DoXorjPhPKhP6VMExec+0x780> */
/* @0xe055c b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe0560 b 0xe08b4 <_Z5DoXorjPhPKhP6VMExec+0x7dc> */
/* @0xe0564 b 0xe0850 <_Z5DoXorjPhPKhP6VMExec+0x778> */
/* @0xe0568 ldr r1, [pc, #0x3bc]   ——VMError/JSThrow 文案：'DoXor :1: Execution Engine - Cannot operate on string type' */
/* @0xe056c mov r0, r3 */
/* @0xe0570 mov r5, r4 */
/* @0xe0574 mov r10, r9 */
/* @0xe0578 add r1, pc, r1 */
/* @0xe057c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0580 b 0xe01cc <_Z5DoXorjPhPKhP6VMExec+0xf4> */
/* @0xe0584 mov r8, #0   ——无 dest 出口（r8=r7=0） */
/* @0xe0588 mov r7, r8 */
/* @0xe058c b 0xe037c <_Z5DoXorjPhPKhP6VMExec+0x2a4> */
/* @0xe0590 ldr r0, [pc, #0x398]   ——JSThrowReferenceError('could not find variable after ^') */
/* @0xe0594 add r0, pc, r0 */
/* @0xe0598 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe059c mov r0, r6 */
/* @0xe05a0 b 0xe01bc <_Z5DoXorjPhPKhP6VMExec+0xe4> */
/* @0xe05a4 ldrd r0, r1, [r10]   ——内核 (int64,int64)：双字 eor，tag 10 */
/* @0xe05a8 mov r12, #10 */
/* @0xe05ac ldrd r2, r3, [r9] */
/* @0xe05b0 eor r2, r2, r0 */
/* @0xe05b4 eor r3, r3, r1 */
/* @0xe05b8 strd r2, r3, [r8] */
/* @0xe05bc cmp r7, #0   ——共享尾：r7≠0 才写 tag */
/* @0xe05c0 beq 0xe01b8 <_Z5DoXorjPhPKhP6VMExec+0xe0> */
/* @0xe05c4 mov r0, r6   ——返回 r6 */
/* @0xe05c8 str r12, [r7, #0xc]   ——tag 写回 [r7+0xc] */
/* @0xe05cc add sp, sp, #68 */
/* @0xe05d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe05d4 ldr r1, [r9]   ——内核 (int64,int32)：B 符号扩展后 eor，tag 10 */
/* @0xe05d8 mov r12, #10 */
/* @0xe05dc ldrd r2, r3, [r10] */
/* @0xe05e0 eor r2, r2, r1 */
/* @0xe05e4 eor r3, r3, r1, asr #31 */
/* @0xe05e8 strd r2, r3, [r8] */
/* @0xe05ec b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe05f0 ldrd r0, r1, [r10]   ——内核 (real,int64)：A 截断成 int64 再 eor，回 double，tag 0 */
/* @0xe05f4 bl 0x3194a0 <__fixdfdi> */
/* @0xe05f8 ldrd r2, r3, [r9] */
/* @0xe05fc eor r0, r0, r2 */
/* @0xe0600 eor r1, r1, r3 */
/* @0xe0604 bl 0x319164 <__floatdidf> */
/* @0xe0608 mov r12, #0 */
/* @0xe060c strd r0, r1, [r8] */
/* @0xe0610 b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe0614 ldrd r0, r1, [r10]   ——内核 (real,int32)：A 截断，B 符号扩展，回 double，tag 0 */
/* @0xe0618 bl 0x3194a0 <__fixdfdi> */
/* @0xe061c ldr r3, [r9] */
/* @0xe0620 eor r0, r0, r3 */
/* @0xe0624 eor r1, r1, r3, asr #31 */
/* @0xe0628 bl 0x319164 <__floatdidf> */
/* @0xe062c mov r12, #0 */
/* @0xe0630 strd r0, r1, [r8] */
/* @0xe0634 b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe0638 ldrd r0, r1, [r10]   ——内核 (real,real)：两个 __fixdfdi → eor → __floatdidf，tag 0 */
/* @0xe063c bl 0x3194a0 <__fixdfdi> */
/* @0xe0640 mov r4, r0 */
/* @0xe0644 mov r5, r1 */
/* @0xe0648 ldrd r0, r1, [r9] */
/* @0xe064c bl 0x3194a0 <__fixdfdi> */
/* @0xe0650 eor r0, r0, r4 */
/* @0xe0654 eor r1, r1, r5 */
/* @0xe0658 bl 0x319164 <__floatdidf> */
/* @0xe065c mov r12, #0 */
/* @0xe0660 strd r0, r1, [r8] */
/* @0xe0664 b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe0668 ldr r3, [r10]   ——内核 (bool,bool)：((A!=0)^(B!=0))，tag 13 */
/* @0xe066c mov r12, #13 */
/* @0xe0670 ldr r2, [r9] */
/* @0xe0674 adds r3, r3, #0 */
/* @0xe0678 movne r3, #1 */
/* @0xe067c cmp r2, #0 */
/* @0xe0680 eorne r3, r3, #1 */
/* @0xe0684 str r3, [r8] */
/* @0xe0688 b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe068c ldrd r0, r1, [r9]   ——内核 (int64,real)：B 截断后 eor，回 double，tag 0 */
/* @0xe0690 bl 0x3194a0 <__fixdfdi> */
/* @0xe0694 ldrd r2, r3, [r10] */
/* @0xe0698 b 0xe05fc <_Z5DoXorjPhPKhP6VMExec+0x524> */
/* @0xe069c ldr r1, [r10]   ——内核 (int32,int64)：A 符号扩展后 eor，tag 10 */
/* @0xe06a0 mov r12, #10 */
/* @0xe06a4 ldrd r2, r3, [r9] */
/* @0xe06a8 eor r2, r2, r1 */
/* @0xe06ac eor r3, r3, r1, asr #31 */
/* @0xe06b0 strd r2, r3, [r8] */
/* @0xe06b4 b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe06b8 ldr r2, [r10]   ——内核 (int32,int32)：eor，tag 7 */
/* @0xe06bc mov r12, #7 */
/* @0xe06c0 ldr r3, [r9] */
/* @0xe06c4 eor r3, r2, r3 */
/* @0xe06c8 str r3, [r8] */
/* @0xe06cc b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe06d0 ldr r4, [r10] */
/* @0xe06d4 ldrd r0, r1, [r9] */
/* @0xe06d8 asr r5, r4, #31 */
/* @0xe06dc b 0xe064c <_Z5DoXorjPhPKhP6VMExec+0x574> */
/* @0xe06e0 ldr r1, [pc, #0x24c]   ——非法类型组合（含字符串）→ VMError('DoXor :: Execution Error')，tag 0 */
/* @0xe06e4 mov r0, r11 */
/* @0xe06e8 add r1, pc, r1 */
/* @0xe06ec bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe06f0 mov r12, #0 */
/* @0xe06f4 b 0xe05bc <_Z5DoXorjPhPKhP6VMExec+0x4e4> */
/* @0xe06f8 add r7, sp, #48 */
/* @0xe06fc mov r1, r4 */
/* @0xe0700 mov r0, r7 */
/* @0xe0704 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xe0708 cmp r0, #1 */
/* @0xe070c beq 0xe0900 <_Z5DoXorjPhPKhP6VMExec+0x828> */
/* @0xe0710 cmp r0, #0 */
/* @0xe0714 bne 0xe01b8 <_Z5DoXorjPhPKhP6VMExec+0xe0> */
/* @0xe0718 str r0, [r6, #-0x4] */
/* @0xe071c sub r4, r6, #16 */
/* @0xe0720 vldr d7, [sp, #32] */
/* @0xe0724 vldr d6, [sp, #48] */
/* @0xe0728 vcvt.s32.f64 s14, d7 */
/* @0xe072c ldr r3, [sp, #0x2c] */
/* @0xe0730 sub r3, r3, #1 */
/* @0xe0734 bic r3, r3, #-16777216 */
/* @0xe0738 bic r3, r3, #3 */
/* @0xe073c cmp r3, #0 */
/* @0xe0740 vcvt.s32.f64 s11, d6 */
/* @0xe0744 vmov r3, s14 */
/* @0xe0748 vmov r2, s11 */
/* @0xe074c eor r2, r2, r3 */
/* @0xe0750 vmov s15, r2 */
/* @0xe0754 vcvt.f64.s32 d7, s15 */
/* @0xe0758 vmov r2, r3, d7 */
/* @0xe075c vstr s14, [r6, #-16]   ——慢路径结果：sp-16 写 double（tag 在 +0xc） */
/* @0xe0760 str r3, [r6, #-0xc] */
/* @0xe0764 beq 0xe08f4 <_Z5DoXorjPhPKhP6VMExec+0x81c> */
/* @0xe0768 ldr r1, [sp, #0x3c] */
/* @0xe076c mov r3, #0 */
/* @0xe0770 str r3, [sp, #0x28] */
/* @0xe0774 mov r2, #5 */
/* @0xe0778 sub r1, r1, #1 */
/* @0xe077c str r3, [sp, #0x20] */
/* @0xe0780 bic r3, r1, #-16777216 */
/* @0xe0784 str r2, [sp, #0x2c] */
/* @0xe0788 bic r3, r3, #3 */
/* @0xe078c cmp r3, #0 */
/* @0xe0790 movne r0, r4 */
/* @0xe0794 bne 0xe01bc <_Z5DoXorjPhPKhP6VMExec+0xe4> */
/* @0xe0798 mov r0, r7   ——释放临时 RValue */
/* @0xe079c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe07a0 mov r0, r4 */
/* @0xe07a4 b 0xe01bc <_Z5DoXorjPhPKhP6VMExec+0xe4> */
/* @0xe07a8 and r5, r5, #15   ——tag=10 → int64 */
/* @0xe07ac orr r5, r5, #48 */
/* @0xe07b0 add r6, r10, #16   ——5 路径：A=arg2+16 */
/* @0xe07b4 b 0xe020c <_Z5DoXorjPhPKhP6VMExec+0x134> */
/* @0xe07b8 ldr r1, [pc, #0x178]   ——VMError/JSThrow 文案：'DoXor :2: illegal array use' */
/* @0xe07bc mov r0, r11 */
/* @0xe07c0 add r1, pc, r1 */
/* @0xe07c4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe07c8 b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe07cc ldr r1, [pc, #0x168]   ——VMError/JSThrow 文案：'DoXor :2: Execution Engine - Cannot operate on string type' */
/* @0xe07d0 mov r0, r11 */
/* @0xe07d4 add r1, pc, r1 */
/* @0xe07d8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe07dc b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe07e0 and r5, r5, #15   ——tag 0/13 → 实数 */
/* @0xe07e4 b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe07e8 ldr r1, [pc, #0x150]   ——VMError/JSThrow 文案：'DoXor :2: undefined value' */
/* @0xe07ec mov r0, r11 */
/* @0xe07f0 add r1, pc, r1 */
/* @0xe07f4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe07f8 b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe07fc ldr r1, [pc, #0x140]   ——VMError/JSThrow 文案：'DoXor :2: illegal pointer use' */
/* @0xe0800 mov r0, r11 */
/* @0xe0804 add r1, pc, r1 */
/* @0xe0808 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe080c b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe0810 and r5, r5, #15   ——tag=7 → int32 */
/* @0xe0814 orr r5, r5, #32 */
/* @0xe0818 b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe081c ldr r1, [pc, #0x124]   ——VMError/JSThrow 文案：'DoXor :1: illegal array use' */
/* @0xe0820 mov r0, r11 */
/* @0xe0824 mov r5, r4 */
/* @0xe0828 add r1, pc, r1 */
/* @0xe082c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0830 add r10, r9, #16 */
/* @0xe0834 b 0xe01cc <_Z5DoXorjPhPKhP6VMExec+0xf4> */
/* @0xe0838 ldr r1, [pc, #0x10c]   ——VMError/JSThrow 文案：'DoXor :1: Execution Engine - Cannot operate on string type' */
/* @0xe083c mov r0, r11 */
/* @0xe0840 mov r5, r4 */
/* @0xe0844 add r1, pc, r1 */
/* @0xe0848 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe084c b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe0850 and r5, r4, #240 */
/* @0xe0854 b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe0858 and r5, r5, #240 */
/* @0xe085c orr r5, r5, #3 */
/* @0xe0860 b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe0864 and r5, r5, #240 */
/* @0xe0868 orr r5, r5, #2 */
/* @0xe086c b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe0870 ldr r1, [pc, #0xd8]   ——VMError/JSThrow 文案：'DoXor :1: undefined value' */
/* @0xe0874 mov r0, r11 */
/* @0xe0878 mov r5, r4 */
/* @0xe087c add r1, pc, r1 */
/* @0xe0880 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0884 b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe0888 ldr r1, [pc, #0xc4]   ——VMError/JSThrow 文案：'DoXor :1: illegal pointer use' */
/* @0xe088c mov r0, r11 */
/* @0xe0890 mov r5, r4 */
/* @0xe0894 add r1, pc, r1 */
/* @0xe0898 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe089c b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe08a0 ldr r1, [pc, #0xb0]   ——tag 4/6/8/9/11/12 → Malformed variable */
/* @0xe08a4 mov r0, r11 */
/* @0xe08a8 add r1, pc, r1 */
/* @0xe08ac bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe08b0 b 0xe07b0 <_Z5DoXorjPhPKhP6VMExec+0x6d8> */
/* @0xe08b4 ldr r1, [pc, #0xa0]   ——VMError/JSThrow 文案：'DoXor :1: Malformed variable' */
/* @0xe08b8 mov r0, r11 */
/* @0xe08bc mov r5, r4 */
/* @0xe08c0 add r1, pc, r1 */
/* @0xe08c4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe08c8 b 0xe0830 <_Z5DoXorjPhPKhP6VMExec+0x758> */
/* @0xe08cc ldr r0, [pc, #0x8c]   ——JSThrowReferenceError('could not find variable before ^') */
/* @0xe08d0 add r0, pc, r0 */
/* @0xe08d4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe08d8 mov r0, r6 */
/* @0xe08dc b 0xe01bc <_Z5DoXorjPhPKhP6VMExec+0xe4> */
/* @0xe08e0 ldr r0, [pc, #0x7c]   ——JSThrowTypeError('DoXor - could not convert lhs expr to a number') */
/* @0xe08e4 add r0, pc, r0 */
/* @0xe08e8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe08ec mov r0, r6 */
/* @0xe08f0 b 0xe01bc <_Z5DoXorjPhPKhP6VMExec+0xe4> */
/* @0xe08f4 mov r0, r5 */
/* @0xe08f8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe08fc b 0xe0768 <_Z5DoXorjPhPKhP6VMExec+0x690> */
/* @0xe0900 ldr r0, [pc, #0x60]   ——JSThrowTypeError('DoXor - could not convert rhs expr to a number') */
/* @0xe0904 add r0, pc, r0 */
/* @0xe0908 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe090c mov r0, r6 */
/* @0xe0910 b 0xe01bc <_Z5DoXorjPhPKhP6VMExec+0xe4> */
/* @0xe0914 mov r5, r4 */
/* @0xe0918 mov r10, r1 */
/* @0xe091c b 0xe01cc <_Z5DoXorjPhPKhP6VMExec+0xf4> */
/* @0xe0920 mov r6, r10 */
/* @0xe0924 b 0xe020c <_Z5DoXorjPhPKhP6VMExec+0x134> */
/* @0xe0928 eoreq r3, r5, r12, lsl #21   ——literal pool：+0x253a8c → 0x333c98 (非指令) 'DoXor :2: Execution Engine - Cannot operate on string type' */
/* @0xe092c eoreq r3, r5, r4, ror #12   ——literal pool：+0x253664 → 0x333be4 (非指令) 'DoXor :1: Execution Engine - Cannot operate on string type' */
/* @0xe0930 eoreq r3, r5, r4, asr #11   ——literal pool：+0x2535c4 → 0x333b60 (非指令) "could not find variable after '^'" */
/* @0xe0934 eoreq r3, r5, r12, asr r6   ——literal pool：+0x25365c → 0x333d4c (非指令) 'DoXor :: Execution Error' */
/* @0xe0938 eoreq r3, r5, r8, asr #10   ——literal pool：+0x253548 → 0x333d10 (非指令) 'DoXor :2: illegal array use' */
/* @0xe093c .word 0x002534bc   ——literal pool：+0x2534bc → 0x333c98 (非指令) 'DoXor :2: Execution Engine - Cannot operate on string type' */
/* @0xe0940 .word 0x002534fc   ——literal pool：+0x2534fc → 0x333cf4 (非指令) 'DoXor :2: undefined value' */
/* @0xe0944 eoreq r3, r5, r8, asr #9   ——literal pool：+0x2534c8 → 0x333cd4 (非指令) 'DoXor :2: illegal pointer use' */
/* @0xe0948 eoreq r3, r5, r12, lsr #8   ——literal pool：+0x25342c → 0x333c5c (非指令) 'DoXor :1: illegal array use' */
/* @0xe094c mlaeq r5, r8, r3, r3   ——literal pool：+0x253398 → 0x333be4 (非指令) 'DoXor :1: Execution Engine - Cannot operate on string type' */
/* @0xe0950 .word 0x002533bc   ——literal pool：+0x2533bc → 0x333c40 (非指令) 'DoXor :1: undefined value' */
/* @0xe0954 eoreq r3, r5, r4, lsl #7   ——literal pool：+0x253384 → 0x333c20 (非指令) 'DoXor :1: illegal pointer use' */
/* @0xe0958 eoreq r3, r5, r12, ror r4   ——literal pool：+0x25347c → 0x333d2c (非指令) 'DoXor :2: Malformed variable' */
/* @0xe095c .word 0x002533b0   ——literal pool：+0x2533b0 → 0x333c78 (非指令) 'DoXor :1: Malformed variable' */
/* @0xe0960 eoreq r3, r5, r4, ror #4   ——literal pool：+0x253264 → 0x333b3c (非指令) "could not find variable before '^'" */
/* @0xe0964 mlaeq r5, r8, r2, r3   ——literal pool：+0x253298 → 0x333b84 (非指令) 'DoXor - could not convert lhs expr to a number' */
/* @0xe0968 eoreq r3, r5, r8, lsr #5   ——literal pool：+0x2532a8 → 0x333bb4 (非指令) 'DoXor - could not convert rhs expr to a number' */
