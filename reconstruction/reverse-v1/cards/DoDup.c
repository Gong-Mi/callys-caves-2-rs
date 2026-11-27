/* cally 逆向卡：DoDup（原版 libyoyo.so，armv7）
 * @func 0xd5560 0xd5838  size 728  182 条指令（含尾部 literal 词）
 * 级别: 正文（正常 dup 的 8 B / 4 B / 16 B / string 四条拷贝体、16 B RValue 的 15 路 tag 拷贝、swap 模式全部落地；
 *           残留 open 都在函数之外：调用者如何消费 sp 下移后的副本）
 * 符号: _Z5DoDupjPhPKhP6VMExec → uchar* DoDup(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   r7 = sp；r6 = GOT（[pc] 两跳）；canary 存 [r11-0x28]；r3 = arg>>16            d5568/d5578/d5580
 *   (arg & 0xFF00) != 0 → 只接受 type==5：T1 d5594 → 5 走 d5620（swap），其余（含 0..4、6）走
 *       d55b8 YYError "Argument type %d currently unhandled by DoDup swap mode"（.rodata 0x332aa8）
 *   (arg & 0xFF00) == 0 → 正常 dup：n = (arg&0x7FFF)+1，起始偏移 r5 = 0
 *       d55e0..d55f4；此处 bit15 必为 0（bit15 属于刚测过的 0xFF00），故 r5 恒 0、n 恒为 count+1
 *   T2 d55fc 按 type=(arg>>16)&0xFF（0..6）选元素宽度：
 *       0,3 → 8 B（d56c8 lsl#3）；1,2,4,6 → 4 B（d56e0 lsl#2）；5 → 16 B RValue（d56f8）；>6 → d5600 直接返回
 *   dup 本体：memcpy(sp - n*size, sp, n*size)，并把 r7 改写成目的地址（d56d0/d56e8/d56fc 的 rsb/sub）→
 *       返回 sp - n*size（d55c4 mov r0,r7）——栈向下长，副本成为新栈顶
 *   type 6（string）：逐元素 strlen+1 → MemoryManager::Alloc(len+1, "…/Files/Code/VM_Exec.cpp", 0x2075, 1)
 *       → strcpy（d568c..d56c4），源指针 [r5,#4]! 步进、目的 [r10],#4 步进；新串是独立副本，不动源串引用计数
 *   swap 模式（type==5 且 arg&0xFF00!=0，d5620）：n=(arg&0xF0)/16 槽、m=(arg&0x0F) 槽，
 *       memcpy(临时, sp, 16n) → memmove(sp+16n, sp, 16m) → memcpy(sp+16m, 临时, 16n)（d5620..d5664），返回 sp
 *       → 把栈顶 n 个 RValue 与随后的 m 个槽对调（"swap mode" 字面义）
 *   16 B 拷贝体（d5714..d579c，do-while，i=0..n-1）：先把 dst+0 清 0、dst+12=src+12（tag 原字）、dst+8=src+8，
 *       再按 tag&0x00FFFFFF（0..14）分派：
 *         0,10,13 → 拷 +0/+4（8 B 载荷）d57a4；1 → 指针在 +0，++[+4]（YYString 计数在 +4）d5810；
 *         2 → 指针在 +0，++[+0] 且 +8 空则回指（_RefThing）d57e4；6 → 拷指针后 GetContextStackTop+DeterminePotentialRoot（GC）d57b8；
 *         3,7,14 → 只拷 +0（裸指针）d5784；4,5,8,9,11,12,>14 → 不做额外动作（d578c）
 *
 * 结论（新增三条硬事实）：
 *   1. DoDup 一个处理器兼两种 opcode：正常 dup（arg&0xFF00==0）与 "swap mode"（arg&0xFF00!=0，只许 type5），
 *      后者的 n/m 就是 bits7:4 与 bits3:0（以 16 B 槽为单位）。
 *   2. 正常 dup 的元素个数是 (arg&0x7FFF)+1，宽度由 type 字节（0..6）决定 —— 与 DoAdd 的存储类 nibble、
 *      DoPopNull 的返回增量是同一张宽度表（0/3=8、1/2/4/6=4、5=16、6=4 带引用计数）。
 *   3. RValue 拷贝按 tag 分引用计数语义：tag1 计数在对象 +4（YYString）、tag2 计数在对象 +0 且 +8 是回指（_RefThing）、
 *      tag6 要登记 GC root，其余只做字节拷贝 —— 与 DoPushGlobal 的 15 路 tag 表、DoAdd 的 tag 释放判定互相印证。
 *
 * 尾部 d582c..d5834 是 literal pool（objdump 译成 ldrsbteq/eoreq），非指令；按 objdump 原样保留。
 *
 * open：
 *   · 调用者如何消费"sp 已下移"的副本（dup 完 sp 变低，副本在 [sp_new, sp_old)）；
 *   · swap 模式是否就是 array/varargs 展开，bits7:4 最多 15 槽、bits3:0 最多 15 槽是否够用；
 *   · type 1 与 4 的元素类型名（只按 4 B 宽度处理，无引用计数动作）；
 *   · MemoryManager::Alloc 的第三/四实参（0x2075, 1）含义；
 *   · tag>14（如 0x00FFFFFF 占位）在拷贝体里只落 d578c：dst+0 保持 0 而 dst+12 保留原 tag，调用侧是否再查占位。
 */
/* @0xd5560 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd5564 add r11, sp, #32 */
/* @0xd5568 ldr r6, [pc, #0x2bc] */
/* @0xd556c sub sp, sp, #20 */
/* @0xd5570 tst r0, #65280 */
/* @0xd5574 ldr r6, [pc, r6] */
/* @0xd5578 mov r7, r1 */
/* @0xd557c lsr r3, r0, #16 */
/* @0xd5580 ldr r2, [r6] */
/* @0xd5584 str r2, [r11, #-0x28] */
/* @0xd5588 beq 0xd55e0 <_Z5DoDupjPhPKhP6VMExec+0x80> */
/* @0xd558c uxtb r1, r3 */
/* @0xd5590 cmp r1, #6 */
/* @0xd5594 addls pc, pc, r1, lsl #2 */
/* @0xd5598 b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd559c b 0xd55b8 <_Z5DoDupjPhPKhP6VMExec+0x58> */
/* @0xd55a0 b 0xd55b8 <_Z5DoDupjPhPKhP6VMExec+0x58> */
/* @0xd55a4 b 0xd55b8 <_Z5DoDupjPhPKhP6VMExec+0x58> */
/* @0xd55a8 b 0xd55b8 <_Z5DoDupjPhPKhP6VMExec+0x58> */
/* @0xd55ac b 0xd55b8 <_Z5DoDupjPhPKhP6VMExec+0x58> */
/* @0xd55b0 b 0xd5620 <_Z5DoDupjPhPKhP6VMExec+0xc0> */
/* @0xd55b4 b 0xd55b8 <_Z5DoDupjPhPKhP6VMExec+0x58> */
/* @0xd55b8 ldr r0, [pc, #0x270] */
/* @0xd55bc add r0, pc, r0 */
/* @0xd55c0 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xd55c4 ldr r2, [r11, #-0x28] */
/* @0xd55c8 mov r0, r7 */
/* @0xd55cc ldr r3, [r6] */
/* @0xd55d0 cmp r2, r3 */
/* @0xd55d4 bne 0xd5828 <_Z5DoDupjPhPKhP6VMExec+0x2c8> */
/* @0xd55d8 sub sp, r11, #32 */
/* @0xd55dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd55e0 ands r2, r0, #32768 */
/* @0xd55e4 ubfx r5, r0, #0x0, #0xf */
/* @0xd55e8 uxtb r3, r3 */
/* @0xd55ec addeq r9, r5, #1 */
/* @0xd55f0 movne r9, #1 */
/* @0xd55f4 moveq r5, r2 */
/* @0xd55f8 cmp r3, #6 */
/* @0xd55fc addls pc, pc, r3, lsl #2 */
/* @0xd5600 b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd5604 b 0xd56c8 <_Z5DoDupjPhPKhP6VMExec+0x168> */
/* @0xd5608 b 0xd56e0 <_Z5DoDupjPhPKhP6VMExec+0x180> */
/* @0xd560c b 0xd56e0 <_Z5DoDupjPhPKhP6VMExec+0x180> */
/* @0xd5610 b 0xd56c8 <_Z5DoDupjPhPKhP6VMExec+0x168> */
/* @0xd5614 b 0xd56e0 <_Z5DoDupjPhPKhP6VMExec+0x180> */
/* @0xd5618 b 0xd56f8 <_Z5DoDupjPhPKhP6VMExec+0x198> */
/* @0xd561c b 0xd566c <_Z5DoDupjPhPKhP6VMExec+0x10c> */
/* @0xd5620 and r4, r0, #240 */
/* @0xd5624 and r5, r0, #15 */
/* @0xd5628 add r3, r4, #14 */
/* @0xd562c mov r1, r7 */
/* @0xd5630 and r3, r3, #504 */
/* @0xd5634 lsl r5, r5, #4 */
/* @0xd5638 sub sp, sp, r3 */
/* @0xd563c mov r2, r4 */
/* @0xd5640 mov r0, sp */
/* @0xd5644 bl 0xb65bc <memcpy@plt> */
/* @0xd5648 mov r2, r5 */
/* @0xd564c add r1, r7, r4 */
/* @0xd5650 mov r0, r7 */
/* @0xd5654 bl 0xb6694 <memmove@plt> */
/* @0xd5658 mov r1, sp */
/* @0xd565c add r0, r7, r5 */
/* @0xd5660 mov r2, r4 */
/* @0xd5664 bl 0xb65bc <memcpy@plt> */
/* @0xd5668 b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd566c add r12, r1, r5, lsl #2 */
/* @0xd5670 sub r7, r1, r9, lsl #2 */
/* @0xd5674 ldr r3, [pc, #0x1b8] */
/* @0xd5678 sub r5, r12, #4 */
/* @0xd567c mov r4, #0 */
/* @0xd5680 mov r10, r7 */
/* @0xd5684 add r3, pc, r3 */
/* @0xd5688 str r3, [r11, #-0x30] */
/* @0xd568c ldr r8, [r5, #0x4]! */
/* @0xd5690 add r4, r4, #1 */
/* @0xd5694 mov r0, r8 */
/* @0xd5698 bl 0xb6538 <strlen@plt> */
/* @0xd569c mov r3, #1 */
/* @0xd56a0 ldr r1, [r11, #-0x30] */
/* @0xd56a4 movw r2, #0x2075 */
/* @0xd56a8 add r0, r0, r3 */
/* @0xd56ac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd56b0 mov r1, r8 */
/* @0xd56b4 bl 0xb65a4 <strcpy@plt> */
/* @0xd56b8 cmp r9, r4 */
/* @0xd56bc str r0, [r10], #4 */
/* @0xd56c0 bgt 0xd568c <_Z5DoDupjPhPKhP6VMExec+0x12c> */
/* @0xd56c4 b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd56c8 lsl r2, r9, #3 */
/* @0xd56cc add r1, r1, r5, lsl #3 */
/* @0xd56d0 rsb r7, r2, r7 */
/* @0xd56d4 mov r0, r7 */
/* @0xd56d8 bl 0xb65bc <memcpy@plt> */
/* @0xd56dc b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd56e0 lsl r2, r9, #2 */
/* @0xd56e4 add r1, r1, r5, lsl #2 */
/* @0xd56e8 rsb r7, r2, r7 */
/* @0xd56ec mov r0, r7 */
/* @0xd56f0 bl 0xb65bc <memcpy@plt> */
/* @0xd56f4 b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd56f8 add r5, r1, r5, lsl #4 */
/* @0xd56fc sub r7, r1, r9, lsl #4 */
/* @0xd5700 mov r8, #0 */
/* @0xd5704 add r5, r5, #16 */
/* @0xd5708 add r4, r7, #16 */
/* @0xd570c mov r2, #5 */
/* @0xd5710 mov r10, r8 */
/* @0xd5714 str r2, [r4, #-0x4] */
/* @0xd5718 sub r0, r5, #16 */
/* @0xd571c str r10, [r4, #-0x10] */
/* @0xd5720 sub r1, r4, #16 */
/* @0xd5724 ldr r3, [r5, #-0x4] */
/* @0xd5728 str r3, [r4, #-0x4] */
/* @0xd572c ldr r3, [r5, #-0x8] */
/* @0xd5730 str r3, [r4, #-0x8] */
/* @0xd5734 ldr r3, [r5, #-0x4] */
/* @0xd5738 bic r3, r3, #-16777216 */
/* @0xd573c cmp r3, #14 */
/* @0xd5740 addls pc, pc, r3, lsl #2 */
/* @0xd5744 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd5748 b 0xd57a4 <_Z5DoDupjPhPKhP6VMExec+0x244> */
/* @0xd574c b 0xd5810 <_Z5DoDupjPhPKhP6VMExec+0x2b0> */
/* @0xd5750 b 0xd57e4 <_Z5DoDupjPhPKhP6VMExec+0x284> */
/* @0xd5754 b 0xd5784 <_Z5DoDupjPhPKhP6VMExec+0x224> */
/* @0xd5758 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd575c b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd5760 b 0xd57b8 <_Z5DoDupjPhPKhP6VMExec+0x258> */
/* @0xd5764 b 0xd5784 <_Z5DoDupjPhPKhP6VMExec+0x224> */
/* @0xd5768 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd576c b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd5770 b 0xd57a4 <_Z5DoDupjPhPKhP6VMExec+0x244> */
/* @0xd5774 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd5778 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd577c b 0xd57a4 <_Z5DoDupjPhPKhP6VMExec+0x244> */
/* @0xd5780 b 0xd5784 <_Z5DoDupjPhPKhP6VMExec+0x224> */
/* @0xd5784 ldr r3, [r5, #-0x10] */
/* @0xd5788 str r3, [r4, #-0x10] */
/* @0xd578c add r8, r8, #1 */
/* @0xd5790 add r4, r4, #16 */
/* @0xd5794 cmp r9, r8 */
/* @0xd5798 add r5, r5, #16 */
/* @0xd579c bgt 0xd5714 <_Z5DoDupjPhPKhP6VMExec+0x1b4> */
/* @0xd57a0 b 0xd55c4 <_Z5DoDupjPhPKhP6VMExec+0x64> */
/* @0xd57a4 ldr r3, [r0, #0x4] */
/* @0xd57a8 ldr r0, [r5, #-0x10] */
/* @0xd57ac str r0, [r4, #-0x10] */
/* @0xd57b0 str r3, [r1, #0x4] */
/* @0xd57b4 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd57b8 ldr r3, [r5, #-0x10] */
/* @0xd57bc str r3, [r4, #-0x10] */
/* @0xd57c0 ldr r3, [r5, #-0x10] */
/* @0xd57c4 cmp r3, #0 */
/* @0xd57c8 beq 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd57cc str r2, [r11, #-0x34] */
/* @0xd57d0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xd57d4 ldr r1, [r5, #-0x10] */
/* @0xd57d8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xd57dc ldr r2, [r11, #-0x34] */
/* @0xd57e0 b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd57e4 ldr r3, [r5, #-0x10] */
/* @0xd57e8 cmp r3, #0 */
/* @0xd57ec str r3, [r4, #-0x10] */
/* @0xd57f0 beq 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd57f4 ldr r12, [r3, #0x8] */
/* @0xd57f8 ldr r0, [r3] */
/* @0xd57fc cmp r12, #0 */
/* @0xd5800 streq r1, [r3, #0x8] */
/* @0xd5804 add r0, r0, #1 */
/* @0xd5808 str r0, [r3] */
/* @0xd580c b 0xd578c <_Z5DoDupjPhPKhP6VMExec+0x22c> */
/* @0xd5810 ldr r3, [r5, #-0x10] */
/* @0xd5814 cmp r3, #0 */
/* @0xd5818 ldrne r1, [r3, #0x4] */
/* @0xd581c addne r1, r1, #1 */
/* @0xd5820 strne r1, [r3, #0x4] */
/* @0xd5824 b 0xd5788 <_Z5DoDupjPhPKhP6VMExec+0x228> */
/* @0xd5828 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xd582c ldrsbteq r8, [r1], -r12 */
/* @0xd5830 eoreq sp, r5, r4, ror #9 */
/* @0xd5834 .word 0x0025d0f8 */
