/* cally 逆向卡：DoShr（原版 libyoyo.so，armv7）
 * @func 0xe1568 0xe1f5c  size 2548  637 条指令（含尾部 literal 池）
 * 级别: 骨架（入口/两级 kind 分派/86 路消费表/52 路算术表/9 条算术核已证；
 *        kind 1 与 kind 4 的语义未证）
 * 符号: _Z5DoShrjPhPKhP6VMExec → uchar* DoShr(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   mode  = (arg >> 8) & 0xF          ; @0xe1568（tst r0,#3840 → bne 0xe15b4）
 *   kindA = (arg >> 16) & 0xF         ; @0xe1588（and r1,r4,#15；r4 = uxtb(arg>>16)）
 *   kindB = (arg >> 20) & 0xF         ; @0xe1688（asr r1,r2,#4；r2 = kindA|kindB<<4）
 *   pair  = kindA | (kindB << 4)      ; @0xe16dc（cmp r4,#85 的 86 路表索引）
 *   bit15 = arg & 0x8000              ; @0xe1608（ands r7,r7,#32768）
 *
 * 操作数布局（本卡的关键结构事实）：
 *   opA（kindA，位[19:16]）在 base+0，是**右操作数**（移位量 / 除数 / 重复串）；
 *   opB（kindB，位[23:20]）在 base+sizeA，是**左操作数**（被移位 / 被除的值）。
 *   依据：kindA∈{0,3}（8 字节）→ opB 槽 = base+8，kindA∈{1,2,4}（4 字节）→ base+4
 *   （@0xe19b8 / @0xe19c4）；而 9 条算术核一律把 base+0 当计数、base+sizeA 当值
 *   （@0xe1a18：ldrd[r6]=B 做 __fixdfdi，ldr[r11]=A 当 count；@0xe9c4 处 fmod(B,A) 同构）。
 *
 * 结论（新增五条硬事实）：
 *   1. **操作数类型是「指令字里的两个 4 bit kind」**，不是运行期 tag。kind∈{0,3} → 8 字节槽、
 *      kind∈{1,2,4} → 4 字节槽、kind=5 → 间接（该槽是一枚 16 字节 RValue，装变量引用，
 *      故 opB 槽被推到 base+16）、kind=6 → 字符串（本算子直接 VMError）、kind>6 → 兜底把
 *      opB 槽退回 base+0。kindA 的字节数决定 opB 起点，这就是"两套槽位"表的由来。
 *   2. **间接操作数按 RValue tag 反推 kind**（tag 在 +12；14 路表，cmp #13）：
 *      tag 0/13 → kind 0（real）、tag 7 → kind 2、tag 10 → kind 3、tag 1 → 字符串（本算子直接
 *      VMError，DoMul 则重写成 kind 6 走重复路径）；
 *      tag 2 → "illegal array use"、tag 3 → "illegal pointer use"、tag 5 → "undefined value"、
 *      tag 4/6/8/9/11/12 → "Malformed variable"。据此 RValue tag 语义为：
 *      0/13=real、1=string、2=array、3=pointer、5=undefined、7=int32、10=int64。
 *   3. **86 路消费表定「结果写哪 / sp 回退多少 / 释放哪个 RValue」**（@0xe16dc）：
 *      pair∈{0,2,3,32,35,48,50,51} → 回退 8 字节、结果写新 sp；
 *      pair=34 → 回退 4 字节（int>>int 的 32 位结果）；pair∈{5,37,80,82,85} → 回退 16 字节
 *      并 FREE 一个 RValue（间接路径）；其余（含非法 kind）→ r10=0，随后由算术表报错。
 *   4. **52 路算术表（@0xe1868 cmp #51）只有 9 个合法 pair**（pair = kA|kB<<4，kA 是 opA
 *      即计数侧、kB 是 opB 即被移位侧），real 参与时一律经 __fixdfdi / __floatundidf 中转：
 *        pair 0   kA=0 kB=0  real >> real        @0xe1bd0
 *        pair 2   kA=2 kB=0  real >> int32       @0xe1a18
 *        pair 3   kA=3 kB=0  real >> int32       @0xe1a18（计数只取低 32 位）
 *        pair 32  kA=0 kB=2  int32 >> real       @0xe1c80
 *        pair 34  kA=2 kB=2  int32 >> int32      @0xe1c68（asr，32 位，结果 tag 7）
 *        pair 35  kA=3 kB=2  int32 >> int32      @0xe1c30（符号扩展成 64 位，tag 10）
 *        pair 48  kA=0 kB=3  int64 >> real       @0xe1c04
 *        pair 50  kA=2 kB=3  int64 >> int32      @0xe1b5c
 *        pair 51  kA=3 kB=3  int64 >> int32      @0xe1b98
 *      默认项 VMError("DoShr :: Execution Error")；pair>85 越界落到 pair 34 的块（default 落点）。
 *   5. **mode≠0 走「常量装箱」路径**（@0xe15b4）：boxType(frame+0x18,kindA,base) →
 *      boxType(frame+8,kindB,上次返回值) 造出两枚 RValue；若 tag 低 24 位 == 0x00FFFFFF
 *      （未解析变量引用）→ JSThrowReferenceError("could not find variable before/after '>>'")；
 *      否则 F_JS_ToInt32（bit15=0）或 F_JS_ToUint32（bit15=1）取整后移位。
 * open：kind 1 / kind 4 的语义（4 字节槽，但与任何 pair 组合都不合法）；
 *       bit15 到底选 ">>" 还是 ">>>"（掩码 0x7FFFFFFF/0xFFFFFFFF 与 ToInt32/Uint32 都随它切换）；
 *       为什么 mode 的 15 个取值全部合并到同一条常量路径（无 1/2 区分，与 DoNot 不同）。
 */
/* ---- 入口：mode=(arg>>8)&0xF；mode≠0 → 常量装箱路径 ---- */
/* @0x00e1568 tst r0, #3840 */
/* @0x00e156c lsr r2, r0, #16 */
/* @0x00e1570 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x00e1574 mov r7, r0 */
/* @0x00e1578 sub sp, sp, #76 */
/* @0x00e157c mov r11, r1 */
/* @0x00e1580 bne 0xe15b4 <_Z5DoShrjPhPKhP6VMExec+0x4c> */
/* @0x00e1584 uxtb r4, r2 */
/* @0x00e1588 and r1, r4, #15 */
/* @0x00e158c cmp r1, #6 */
/* @0x00e1590 addls pc, pc, r1, lsl #2 */
/* @0x00e1594 b 0xe1f04 <_Z5DoShrjPhPKhP6VMExec+0x99c> */
/* @0x00e1598 b 0xe19b8 <_Z5DoShrjPhPKhP6VMExec+0x450> */
/* @0x00e159c b 0xe19c4 <_Z5DoShrjPhPKhP6VMExec+0x45c> */
/* @0x00e15a0 b 0xe19c4 <_Z5DoShrjPhPKhP6VMExec+0x45c> */
/* @0x00e15a4 b 0xe19b8 <_Z5DoShrjPhPKhP6VMExec+0x450> */
/* @0x00e15a8 b 0xe19c4 <_Z5DoShrjPhPKhP6VMExec+0x45c> */
/* @0x00e15ac b 0xe19d0 <_Z5DoShrjPhPKhP6VMExec+0x468> */
/* @0x00e15b0 b 0xe1668 <_Z5DoShrjPhPKhP6VMExec+0x100> */
/* ---- 常量路径：boxType(帧+0x18,kindA,base) / boxType(帧+8,kindB,前次返回) ---- */
/* @0x00e15b4 add r5, sp, #24 */
/* @0x00e15b8 uxtb r4, r2 */
/* @0x00e15bc mov r2, r1 */
/* @0x00e15c0 and r1, r4, #15 */
/* @0x00e15c4 mov r0, r5 */
/* @0x00e15c8 add r9, sp, #8 */
/* @0x00e15cc bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0x00e15d0 lsr r1, r4, #4 */
/* @0x00e15d4 mov r2, r0 */
/* @0x00e15d8 mov r0, r9 */
/* @0x00e15dc bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* 校验两枚 RValue 的 +12 字低 24 位是否全 1（0x00FFFFFF = 未解析变量引用标记） */
/* @0x00e15e0 ldr r3, [sp, #0x14] */
/* @0x00e15e4 mvn r12, #-16777216 */
/* @0x00e15e8 and r3, r3, r12 */
/* @0x00e15ec cmp r3, r12 */
/* @0x00e15f0 mov r4, r0 */
/* @0x00e15f4 beq 0xe1e1c <_Z5DoShrjPhPKhP6VMExec+0x8b4> */
/* @0x00e15f8 ldr r3, [sp, #0x24] */
/* @0x00e15fc bic r3, r3, #-16777216 */
/* @0x00e1600 cmp r3, r12 */
/* @0x00e1604 beq 0xe1e30 <_Z5DoShrjPhPKhP6VMExec+0x8c8> */
/* bit15 决定符号性：bne → F_JS_ToUint32 分支（0xe1a68） */
/* @0x00e1608 ands r7, r7, #32768 */
/* @0x00e160c mov lr, #0 */
/* @0x00e1610 add r6, sp, #40 */
/* @0x00e1614 mov r1, r9 */
/* @0x00e1618 sub r8, r0, #16 */
/* @0x00e161c str lr, [r0, #-0x4] */
/* @0x00e1620 bne 0xe1a68 <_Z5DoShrjPhPKhP6VMExec+0x500> */
/* bit15=0：F_JS_ToInt32(frame+0x28, frame+8) */
/* @0x00e1624 mov r0, r6 */
/* @0x00e1628 mov r2, #0 */
/* @0x00e162c mov r3, #0 */
/* @0x00e1630 str r7, [sp, #0x30] */
/* @0x00e1634 str r12, [sp, #0x34] */
/* @0x00e1638 str r7, [sp, #0x40] */
/* @0x00e163c str r12, [sp, #0x44] */
/* @0x00e1640 strd r2, r3, [sp, #40] */
/* @0x00e1644 strd r2, r3, [sp, #56] */
/* @0x00e1648 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0x00e164c cmp r0, #1 */
/* @0x00e1650 beq 0xe1ecc <_Z5DoShrjPhPKhP6VMExec+0x964> */
/* @0x00e1654 cmp r0, #0 */
/* @0x00e1658 beq 0xe1e44 <_Z5DoShrjPhPKhP6VMExec+0x8dc> */
/* @0x00e165c mov r0, r8 */
/* @0x00e1660 add sp, sp, #76 */
/* @0x00e1664 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* kindA==6（opA 是字符串）→ VMError("DoShr :1: ... Cannot operate on string type") */
/* @0x00e1668 ldr r1, [pc, #0x8a0] */
/* @0x00e166c mov r0, r3 */
/* @0x00e1670 str r3, [sp] */
/* @0x00e1674 mov r6, r11 */
/* @0x00e1678 add r1, pc, r1 */
/* @0x00e167c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e1680 ldr r3, [sp] */
/* ---- 第二级：kindB=(pair>>4)&0xF ---- */
/* @0x00e1684 mov r2, r4 */
/* @0x00e1688 asr r1, r2, #4 */
/* @0x00e168c cmp r1, #6 */
/* @0x00e1690 addls pc, pc, r1, lsl #2 */
/* @0x00e1694 b 0xe1efc <_Z5DoShrjPhPKhP6VMExec+0x994> */
/* @0x00e1698 b 0xe19b0 <_Z5DoShrjPhPKhP6VMExec+0x448> */
/* @0x00e169c b 0xe19a8 <_Z5DoShrjPhPKhP6VMExec+0x440> */
/* @0x00e16a0 b 0xe19a8 <_Z5DoShrjPhPKhP6VMExec+0x440> */
/* @0x00e16a4 b 0xe19b0 <_Z5DoShrjPhPKhP6VMExec+0x448> */
/* @0x00e16a8 b 0xe19a8 <_Z5DoShrjPhPKhP6VMExec+0x440> */
/* @0x00e16ac b 0xe1960 <_Z5DoShrjPhPKhP6VMExec+0x3f8> */
/* @0x00e16b0 b 0xe16b4 <_Z5DoShrjPhPKhP6VMExec+0x14c> */
/* kindB==6（opB 是字符串）→ VMError("DoShr :2: ... Cannot operate on string type") */
/* @0x00e16b4 ldr r1, [pc, #0x858] */
/* @0x00e16b8 mov r0, r3 */
/* @0x00e16bc str r2, [sp, #0x4] */
/* @0x00e16c0 mov r8, r6 */
/* @0x00e16c4 add r1, pc, r1 */
/* @0x00e16c8 str r3, [sp] */
/* @0x00e16cc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e16d0 ldr r2, [sp, #0x4] */
/* @0x00e16d4 ldr r3, [sp] */
/* ---- 86 路消费表（pair=kindA|kindB<<4）：新 sp(r8)、释放槽(r9)、结果槽(r10) ---- */
/* @0x00e16d8 cmp r4, #85 */
/* @0x00e16dc addls pc, pc, r4, lsl #2 */
/* @0x00e16e0 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e16e4 b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0x00e16e8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e16ec b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0x00e16f0 b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0x00e16f4 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e16f8 b 0xe1940 <_Z5DoShrjPhPKhP6VMExec+0x3d8> */
/* @0x00e16fc b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1700 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1704 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1708 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e170c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1710 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1714 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1718 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e171c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1720 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1724 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1728 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e172c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1730 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1734 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1738 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e173c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1740 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1744 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1748 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e174c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1750 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1754 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1758 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e175c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1760 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1764 b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0x00e1768 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e176c b 0xe183c <_Z5DoShrjPhPKhP6VMExec+0x2d4> */
/* @0x00e1770 b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0x00e1774 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1778 b 0xe1940 <_Z5DoShrjPhPKhP6VMExec+0x3d8> */
/* @0x00e177c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1780 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1784 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1788 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e178c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1790 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1794 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1798 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e179c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17a0 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17a4 b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0x00e17a8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17ac b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0x00e17b0 b 0xe1950 <_Z5DoShrjPhPKhP6VMExec+0x3e8> */
/* @0x00e17b4 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17b8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17bc b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17c0 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17c4 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17c8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17cc b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17d0 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17d4 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17d8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17dc b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17e0 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17e4 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17e8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17ec b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17f0 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17f4 b 0xe183c <_Z5DoShrjPhPKhP6VMExec+0x2d4> */
/* @0x00e17f8 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e17fc b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1800 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1804 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1808 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e180c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1810 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1814 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1818 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e181c b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1820 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1824 b 0xe1940 <_Z5DoShrjPhPKhP6VMExec+0x3d8> */
/* @0x00e1828 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e182c b 0xe1940 <_Z5DoShrjPhPKhP6VMExec+0x3d8> */
/* @0x00e1830 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1834 b 0xe1b50 <_Z5DoShrjPhPKhP6VMExec+0x5e8> */
/* @0x00e1838 b 0xe1940 <_Z5DoShrjPhPKhP6VMExec+0x3d8> */
/* pair=34（int32>>int32）：结果 4 字节，回退 4 ---- */
/* @0x00e183c sub r8, r8, #4 */
/* @0x00e1840 mov r9, #0 */
/* @0x00e1844 mov r10, r8 */
/* bit15 → r7=0x7FFFFFFF(1)/0xFFFFFFFF(0)，r4=r5=0xFFFFFFFF（64 位掩码） */
/* @0x00e1848 tst r7, #32768 */
/* @0x00e184c mvnne r7, #-2147483648 */
/* @0x00e1850 mvnne r4, #0 */
/* @0x00e1854 mvnne r5, #-2147483648 */
/* @0x00e1858 mvneq r4, #0 */
/* @0x00e185c mvneq r5, #0 */
/* @0x00e1860 mvneq r7, #0 */
/* ---- 52 路算术表（cmp #51）：9 个 pair 合法，其余 → 0xe1ca4 ---- */
/* @0x00e1864 cmp r2, #51 */
/* @0x00e1868 addls pc, pc, r2, lsl #2 */
/* @0x00e186c b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1870 b 0xe1bd0 <_Z5DoShrjPhPKhP6VMExec+0x668> */
/* @0x00e1874 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1878 b 0xe1a18 <_Z5DoShrjPhPKhP6VMExec+0x4b0> */
/* @0x00e187c b 0xe1a18 <_Z5DoShrjPhPKhP6VMExec+0x4b0> */
/* @0x00e1880 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1884 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1888 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e188c b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1890 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1894 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1898 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e189c b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18a0 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18a4 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18a8 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18ac b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18b0 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18b4 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18b8 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18bc b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18c0 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18c4 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18c8 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18cc b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18d0 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18d4 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18d8 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18dc b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18e0 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18e4 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18e8 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18ec b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18f0 b 0xe1c80 <_Z5DoShrjPhPKhP6VMExec+0x718> */
/* @0x00e18f4 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e18f8 b 0xe1c68 <_Z5DoShrjPhPKhP6VMExec+0x700> */
/* @0x00e18fc b 0xe1c30 <_Z5DoShrjPhPKhP6VMExec+0x6c8> */
/* @0x00e1900 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1904 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1908 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e190c b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1910 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1914 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1918 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e191c b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1920 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1924 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1928 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e192c b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1930 b 0xe1c04 <_Z5DoShrjPhPKhP6VMExec+0x69c> */
/* @0x00e1934 b 0xe1ca4 <_Z5DoShrjPhPKhP6VMExec+0x73c> */
/* @0x00e1938 b 0xe1b5c <_Z5DoShrjPhPKhP6VMExec+0x5f4> */
/* @0x00e193c b 0xe1b98 <_Z5DoShrjPhPKhP6VMExec+0x630> */
/* 间接 pair：回退 16 并释放栈上的 RValue（r9=要 FREE 的槽） */
/* @0x00e1940 sub r9, r8, #16 */
/* @0x00e1944 mov r10, r9 */
/* @0x00e1948 mov r8, r9 */
/* @0x00e194c b 0xe1848 <_Z5DoShrjPhPKhP6VMExec+0x2e0> */
/* 8 字节结果：回退 8，结果写在 r10=新 sp ---- */
/* @0x00e1950 sub r8, r8, #8 */
/* @0x00e1954 mov r9, #0 */
/* @0x00e1958 mov r10, r8 */
/* @0x00e195c b 0xe1848 <_Z5DoShrjPhPKhP6VMExec+0x2e0> */
/* kindB=5：按 [opB+0xc] 的 tag 反推 kindB（改写高半字节） */
/* @0x00e1960 ldr r1, [r6, #0xc] */
/* @0x00e1964 cmp r1, #13 */
/* @0x00e1968 addls pc, pc, r1, lsl #2 */
/* @0x00e196c b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0x00e1970 b 0xe1d0c <_Z5DoShrjPhPKhP6VMExec+0x7a4> */
/* @0x00e1974 b 0xe1cfc <_Z5DoShrjPhPKhP6VMExec+0x794> */
/* @0x00e1978 b 0xe1cd8 <_Z5DoShrjPhPKhP6VMExec+0x770> */
/* @0x00e197c b 0xe1d24 <_Z5DoShrjPhPKhP6VMExec+0x7bc> */
/* @0x00e1980 b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0x00e1984 b 0xe1d14 <_Z5DoShrjPhPKhP6VMExec+0x7ac> */
/* @0x00e1988 b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0x00e198c b 0xe1ccc <_Z5DoShrjPhPKhP6VMExec+0x764> */
/* @0x00e1990 b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0x00e1994 b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0x00e1998 b 0xe1cbc <_Z5DoShrjPhPKhP6VMExec+0x754> */
/* @0x00e199c b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0x00e19a0 b 0xe1dd8 <_Z5DoShrjPhPKhP6VMExec+0x870> */
/* @0x00e19a4 b 0xe1d0c <_Z5DoShrjPhPKhP6VMExec+0x7a4> */
/* opB 槽 = opA+4（kindA∈{1,2,4}，opA 占 4 字节）→ r8 初值 */
/* @0x00e19a8 add r8, r6, #4 */
/* @0x00e19ac b 0xe16d8 <_Z5DoShrjPhPKhP6VMExec+0x170> */
/* opB 槽 = opA+8（kindA∈{0,3}，opA 占 8 字节）→ r8 初值 */
/* @0x00e19b0 add r8, r6, #8 */
/* @0x00e19b4 b 0xe16d8 <_Z5DoShrjPhPKhP6VMExec+0x170> */
/* kindA∈{0,3}：opB 槽 = base+8 */
/* @0x00e19b8 add r6, r11, #8 */
/* @0x00e19bc mov r2, r4 */
/* @0x00e19c0 b 0xe1688 <_Z5DoShrjPhPKhP6VMExec+0x120> */
/* kindA∈{1,2,4}：opB 槽 = base+4 */
/* @0x00e19c4 add r6, r11, #4 */
/* @0x00e19c8 mov r2, r4 */
/* @0x00e19cc b 0xe1688 <_Z5DoShrjPhPKhP6VMExec+0x120> */
/* kindA=5：按 [base+0xc] 的 tag 反推 kindA（改写低半字节），opB 槽改 base+16 */
/* @0x00e19d0 ldr r1, [r11, #0xc] */
/* @0x00e19d4 cmp r1, #13 */
/* @0x00e19d8 addls pc, pc, r1, lsl #2 */
/* @0x00e19dc b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0x00e19e0 b 0xe1dd0 <_Z5DoShrjPhPKhP6VMExec+0x868> */
/* @0x00e19e4 b 0xe1db0 <_Z5DoShrjPhPKhP6VMExec+0x848> */
/* @0x00e19e8 b 0xe1d90 <_Z5DoShrjPhPKhP6VMExec+0x828> */
/* @0x00e19ec b 0xe1d70 <_Z5DoShrjPhPKhP6VMExec+0x808> */
/* @0x00e19f0 b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0x00e19f4 b 0xe1d50 <_Z5DoShrjPhPKhP6VMExec+0x7e8> */
/* @0x00e19f8 b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0x00e19fc b 0xe1d44 <_Z5DoShrjPhPKhP6VMExec+0x7dc> */
/* @0x00e1a00 b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0x00e1a04 b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0x00e1a08 b 0xe1d34 <_Z5DoShrjPhPKhP6VMExec+0x7cc> */
/* @0x00e1a0c b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0x00e1a10 b 0xe1dfc <_Z5DoShrjPhPKhP6VMExec+0x894> */
/* @0x00e1a14 b 0xe1dd0 <_Z5DoShrjPhPKhP6VMExec+0x868> */
/* pair 2/3 (real,int32|int64)：ldrd[opB]→__fixdfdi 作被移位数；ldr[base]=A 作 count；64 位移位 → __floatundidf */
/* @0x00e1a18 ldrd r0, r1, [r6] */
/* @0x00e1a1c bl 0x3194a0 <__fixdfdi> */
/* @0x00e1a20 ldr r12, [r11] */
/* @0x00e1a24 subs r6, r12, #32 */
/* @0x00e1a28 rsb lr, r12, #32 */
/* @0x00e1a2c lsr r2, r0, r12 */
/* @0x00e1a30 orr r2, r2, r1, lsl lr */
/* @0x00e1a34 orrpl r2, r2, r1, asr r6 */
/* @0x00e1a38 asr r3, r1, r12 */
/* @0x00e1a3c and r0, r4, r2 */
/* @0x00e1a40 and r1, r5, r3 */
/* @0x00e1a44 bl 0x319150 <__floatundidf> */
/* @0x00e1a48 mov r12, #0 */
/* @0x00e1a4c strd r0, r1, [r10] */
/* @0x00e1a50 cmp r9, #0 */
/* @0x00e1a54 beq 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0x00e1a58 mov r0, r8 */
/* @0x00e1a5c str r12, [r9, #0xc] */
/* @0x00e1a60 add sp, sp, #76 */
/* @0x00e1a64 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* bit15=1：改走 F_JS_ToUint32 取 count（无符号语义） */
/* @0x00e1a68 mov r0, r6 */
/* @0x00e1a6c mov r2, #0 */
/* @0x00e1a70 mov r3, #0 */
/* @0x00e1a74 str lr, [sp, #0x30] */
/* @0x00e1a78 str r12, [sp, #0x34] */
/* @0x00e1a7c str lr, [sp, #0x40] */
/* @0x00e1a80 str r12, [sp, #0x44] */
/* @0x00e1a84 strd r2, r3, [sp, #40] */
/* @0x00e1a88 strd r2, r3, [sp, #56] */
/* F_JS_ToUint32(frame+0x28, frame+8) */
/* @0x00e1a8c bl 0x24d4f4 <_Z13F_JS_ToUint32R6RValueS0_> */
/* @0x00e1a90 cmp r0, #1 */
/* @0x00e1a94 beq 0xe1ebc <_Z5DoShrjPhPKhP6VMExec+0x954> */
/* @0x00e1a98 cmp r0, #0 */
/* @0x00e1a9c bne 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* F_JS_ToUint32(frame+0x38, frame+0x18) */
/* @0x00e1aa0 add r7, sp, #56 */
/* @0x00e1aa4 mov r1, r5 */
/* @0x00e1aa8 mov r0, r7 */
/* @0x00e1aac bl 0x24d4f4 <_Z13F_JS_ToUint32R6RValueS0_> */
/* @0x00e1ab0 cmp r0, #1 */
/* @0x00e1ab4 beq 0xe1eec <_Z5DoShrjPhPKhP6VMExec+0x984> */
/* @0x00e1ab8 cmp r0, #0 */
/* @0x00e1abc bne 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* vcvt.u32.f64 取 count；lsr + bic 掩码；vcvt.f64.u32 回 double */
/* @0x00e1ac0 vldr d6, [sp, #56] */
/* @0x00e1ac4 vcvt.u32.f64 s11, d6 */
/* @0x00e1ac8 vldr d7, [sp, #40] */
/* @0x00e1acc ldr r2, [sp, #0x34] */
/* @0x00e1ad0 mvn r1, #0 */
/* @0x00e1ad4 add r2, r2, r1 */
/* @0x00e1ad8 bic r2, r2, #-16777216 */
/* @0x00e1adc bic r2, r2, #3 */
/* @0x00e1ae0 cmp r2, #0 */
/* @0x00e1ae4 vcvt.u32.f64 s14, d7 */
/* @0x00e1ae8 vmov r3, s11 */
/* @0x00e1aec vmov r0, s14 */
/* @0x00e1af0 and r3, r3, #31 */
/* @0x00e1af4 rsb r2, r3, #32 */
/* @0x00e1af8 lsr r3, r0, r3 */
/* @0x00e1afc bic r2, r3, r1, lsl r2 */
/* @0x00e1b00 vmov s15, r2 */
/* @0x00e1b04 vcvt.f64.u32 d7, s15 */
/* @0x00e1b08 vmov r2, r3, d7 */
/* @0x00e1b0c vstr s14, [r4, #-16] */
/* @0x00e1b10 str r3, [r4, #-0xc] */
/* @0x00e1b14 beq 0xe1eb0 <_Z5DoShrjPhPKhP6VMExec+0x948> */
/* @0x00e1b18 ldr r1, [sp, #0x44] */
/* @0x00e1b1c mov r3, #0 */
/* @0x00e1b20 str r3, [sp, #0x30] */
/* @0x00e1b24 mov r2, #5 */
/* @0x00e1b28 sub r1, r1, #1 */
/* @0x00e1b2c str r3, [sp, #0x28] */
/* @0x00e1b30 bic r3, r1, #-16777216 */
/* @0x00e1b34 str r2, [sp, #0x34] */
/* @0x00e1b38 bic r3, r3, #3 */
/* @0x00e1b3c cmp r3, #0 */
/* @0x00e1b40 bne 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0x00e1b44 mov r0, r7 */
/* @0x00e1b48 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x00e1b4c b 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0x00e1b50 mov r10, #0 */
/* @0x00e1b54 mov r9, r10 */
/* @0x00e1b58 b 0xe1848 <_Z5DoShrjPhPKhP6VMExec+0x2e0> */
/* pair 50 (int64,int32)：64 位 lsr/orr 拼接，掩码后 tag 10 */
/* @0x00e1b5c ldr r12, [r11] */
/* @0x00e1b60 mov r1, #0 */
/* @0x00e1b64 ldr r11, [r6] */
/* @0x00e1b68 ldr r4, [r6, #0x4] */
/* @0x00e1b6c rsb r5, r12, #32 */
/* @0x00e1b70 subs r6, r12, #32 */
/* @0x00e1b74 lsr r2, r11, r12 */
/* @0x00e1b78 orr r2, r2, r4, lsl r5 */
/* @0x00e1b7c asr r3, r4, r12 */
/* @0x00e1b80 orrpl r2, r2, r4, asr r6 */
/* @0x00e1b84 and r3, r3, r1 */
/* @0x00e1b88 and r2, r2, r7 */
/* @0x00e1b8c mov r12, #10 */
/* @0x00e1b90 strd r2, r3, [r10] */
/* @0x00e1b94 b 0xe1a50 <_Z5DoShrjPhPKhP6VMExec+0x4e8> */
/* pair 51 (int64,int64)：同 pair 50，寄存器角色互换 */
/* @0x00e1b98 ldr r7, [r6] */
/* @0x00e1b9c ldr r1, [r11] */
/* @0x00e1ba0 ldr r0, [r6, #0x4] */
/* @0x00e1ba4 rsb r12, r1, #32 */
/* @0x00e1ba8 lsr r2, r7, r1 */
/* @0x00e1bac subs r6, r1, #32 */
/* @0x00e1bb0 orr r2, r2, r0, lsl r12 */
/* @0x00e1bb4 asr r3, r0, r1 */
/* @0x00e1bb8 orrpl r2, r2, r0, asr r6 */
/* @0x00e1bbc and r5, r5, r3 */
/* @0x00e1bc0 and r4, r4, r2 */
/* @0x00e1bc4 mov r12, #10 */
/* @0x00e1bc8 strd r4, r5, [r10] */
/* @0x00e1bcc b 0xe1a50 <_Z5DoShrjPhPKhP6VMExec+0x4e8> */
/* pair 0 (real,real)：两侧 __fixdfdi → 64 位移位 → __floatundidf → strd */
/* @0x00e1bd0 ldrd r0, r1, [r6] */
/* @0x00e1bd4 bl 0x3194a0 <__fixdfdi> */
/* @0x00e1bd8 mov r6, r1 */
/* @0x00e1bdc mov r7, r0 */
/* @0x00e1be0 ldrd r0, r1, [r11] */
/* @0x00e1be4 bl 0x3194a0 <__fixdfdi> */
/* @0x00e1be8 lsr r2, r7, r0 */
/* @0x00e1bec rsb r1, r0, #32 */
/* @0x00e1bf0 subs r12, r0, #32 */
/* @0x00e1bf4 orr r2, r2, r6, lsl r1 */
/* @0x00e1bf8 orrpl r2, r2, r6, asr r12 */
/* @0x00e1bfc asr r3, r6, r0 */
/* @0x00e1c00 b 0xe1a3c <_Z5DoShrjPhPKhP6VMExec+0x4d4> */
/* pair 48 (int64,real)：count=(int)__fixdfdi(A) */
/* @0x00e1c04 ldrd r0, r1, [r11] */
/* @0x00e1c08 bl 0x3194a0 <__fixdfdi> */
/* @0x00e1c0c ldr lr, [r6] */
/* @0x00e1c10 ldr r1, [r6, #0x4] */
/* @0x00e1c14 rsb r12, r0, #32 */
/* @0x00e1c18 lsr r2, lr, r0 */
/* @0x00e1c1c subs r6, r0, #32 */
/* @0x00e1c20 orr r2, r2, r1, lsl r12 */
/* @0x00e1c24 orrpl r2, r2, r1, asr r6 */
/* @0x00e1c28 asr r3, r1, r0 */
/* @0x00e1c2c b 0xe1a3c <_Z5DoShrjPhPKhP6VMExec+0x4d4> */
/* pair 35 (int32,int64)：符号位填充的 64 位移位，结果 tag 10 */
/* @0x00e1c30 ldr r0, [r6] */
/* @0x00e1c34 ldr r1, [r11] */
/* @0x00e1c38 asr r3, r0, #31 */
/* @0x00e1c3c lsr r6, r0, r1 */
/* @0x00e1c40 rsb r0, r1, #32 */
/* @0x00e1c44 subs r12, r1, #32 */
/* @0x00e1c48 orr r6, r6, r3, lsl r0 */
/* @0x00e1c4c asr r7, r3, r1 */
/* @0x00e1c50 orrpl r6, r6, r3, asr r12 */
/* @0x00e1c54 and r5, r5, r7 */
/* @0x00e1c58 and r4, r4, r6 */
/* @0x00e1c5c mov r12, #10 */
/* @0x00e1c60 strd r4, r5, [r10] */
/* @0x00e1c64 b 0xe1a50 <_Z5DoShrjPhPKhP6VMExec+0x4e8> */
/* pair 34 (int32,int32)：and r7,r7,opB asr count → 32 位结果，tag 7 */
/* @0x00e1c68 ldr r0, [r6] */
/* @0x00e1c6c mov r12, #7 */
/* @0x00e1c70 ldr r3, [r11] */
/* @0x00e1c74 and r7, r7, r0, asr r3 */
/* @0x00e1c78 str r7, [r10] */
/* @0x00e1c7c b 0xe1a50 <_Z5DoShrjPhPKhP6VMExec+0x4e8> */
/* pair 32 (int32,real)：count=(int)__fixdfdi(A)；结果 vcvt.f64.u32 */
/* @0x00e1c80 ldrd r0, r1, [r11] */
/* @0x00e1c84 bl 0x3194a0 <__fixdfdi> */
/* @0x00e1c88 ldr r3, [r6] */
/* @0x00e1c8c mov r12, #0 */
/* @0x00e1c90 and r0, r7, r3, asr r0 */
/* @0x00e1c94 vmov s11, r0 */
/* @0x00e1c98 vcvt.f64.u32 d7, s11 */
/* @0x00e1c9c vstr d7, [r10] */
/* @0x00e1ca0 b 0xe1a50 <_Z5DoShrjPhPKhP6VMExec+0x4e8> */
/* 算术表默认项：VMError("DoShr :: Execution Error") */
/* @0x00e1ca4 ldr r1, [pc, #0x26c] */
/* @0x00e1ca8 mov r0, r3 */
/* @0x00e1cac add r1, pc, r1 */
/* @0x00e1cb0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* 写结果 tag（r12=0 real / 7 int32 / 10 int64）后返回 r8 */
/* @0x00e1cb4 mov r12, #0 */
/* @0x00e1cb8 b 0xe1a50 <_Z5DoShrjPhPKhP6VMExec+0x4e8> */
/* 间接 kindB：tag 10 → kindB=3（0x30） */
/* @0x00e1cbc and r2, r2, #15 */
/* @0x00e1cc0 orr r2, r2, #48 */
/* @0x00e1cc4 add r8, r6, #16 */
/* @0x00e1cc8 b 0xe16d8 <_Z5DoShrjPhPKhP6VMExec+0x170> */
/* 间接 kindB：tag 7 → kindB=2（0x20） */
/* @0x00e1ccc and r2, r2, #15 */
/* @0x00e1cd0 orr r2, r2, #32 */
/* @0x00e1cd4 b 0xe1cc4 <_Z5DoShrjPhPKhP6VMExec+0x75c> */
/* @0x00e1cd8 ldr r1, [pc, #0x23c] */
/* @0x00e1cdc mov r0, r3 */
/* @0x00e1ce0 add r1, pc, r1 */
/* @0x00e1ce4 str r2, [sp, #0x4] */
/* @0x00e1ce8 str r3, [sp] */
/* @0x00e1cec bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e1cf0 ldr r2, [sp, #0x4] */
/* @0x00e1cf4 ldr r3, [sp] */
/* @0x00e1cf8 b 0xe1cc4 <_Z5DoShrjPhPKhP6VMExec+0x75c> */
/* @0x00e1cfc ldr r1, [pc, #0x21c] */
/* @0x00e1d00 mov r0, r3 */
/* @0x00e1d04 add r1, pc, r1 */
/* @0x00e1d08 b 0xe1ce4 <_Z5DoShrjPhPKhP6VMExec+0x77c> */
/* @0x00e1d0c and r2, r2, #15 */
/* @0x00e1d10 b 0xe1cc4 <_Z5DoShrjPhPKhP6VMExec+0x75c> */
/* @0x00e1d14 ldr r1, [pc, #0x208] */
/* @0x00e1d18 mov r0, r3 */
/* @0x00e1d1c add r1, pc, r1 */
/* @0x00e1d20 b 0xe1ce4 <_Z5DoShrjPhPKhP6VMExec+0x77c> */
/* @0x00e1d24 ldr r1, [pc, #0x1fc] */
/* @0x00e1d28 mov r0, r3 */
/* @0x00e1d2c add r1, pc, r1 */
/* @0x00e1d30 b 0xe1ce4 <_Z5DoShrjPhPKhP6VMExec+0x77c> */
/* 间接 kindA：tag 10 → kindA=3，opB 槽回 base+16 */
/* @0x00e1d34 and r2, r2, #240 */
/* @0x00e1d38 orr r2, r2, #3 */
/* @0x00e1d3c add r6, r11, #16 */
/* @0x00e1d40 b 0xe1688 <_Z5DoShrjPhPKhP6VMExec+0x120> */
/* 间接 kindA：tag 7 → kindA=2 */
/* @0x00e1d44 and r2, r2, #240 */
/* @0x00e1d48 orr r2, r2, #2 */
/* @0x00e1d4c b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* @0x00e1d50 ldr r1, [pc, #0x1d4] */
/* @0x00e1d54 mov r0, r3 */
/* @0x00e1d58 str r3, [sp] */
/* @0x00e1d5c add r1, pc, r1 */
/* @0x00e1d60 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e1d64 mov r2, r4 */
/* @0x00e1d68 ldr r3, [sp] */
/* @0x00e1d6c b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* @0x00e1d70 ldr r1, [pc, #0x1b8] */
/* @0x00e1d74 mov r0, r3 */
/* @0x00e1d78 str r3, [sp] */
/* @0x00e1d7c add r1, pc, r1 */
/* @0x00e1d80 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e1d84 mov r2, r4 */
/* @0x00e1d88 ldr r3, [sp] */
/* @0x00e1d8c b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* @0x00e1d90 ldr r1, [pc, #0x19c] */
/* @0x00e1d94 mov r0, r3 */
/* @0x00e1d98 str r3, [sp] */
/* @0x00e1d9c add r1, pc, r1 */
/* @0x00e1da0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e1da4 mov r2, r4 */
/* @0x00e1da8 ldr r3, [sp] */
/* @0x00e1dac b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* @0x00e1db0 ldr r1, [pc, #0x180] */
/* @0x00e1db4 mov r0, r3 */
/* @0x00e1db8 str r3, [sp] */
/* @0x00e1dbc add r1, pc, r1 */
/* @0x00e1dc0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e1dc4 mov r2, r4 */
/* @0x00e1dc8 ldr r3, [sp] */
/* @0x00e1dcc b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* 间接 kindA：tag 0/13 → kindA=0（real） */
/* @0x00e1dd0 and r2, r4, #240 */
/* @0x00e1dd4 b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* 间接 kindB：Malformed variable（tag 4/6/8/9/11/12 共用） */
/* @0x00e1dd8 ldr r1, [pc, #0x15c] */
/* @0x00e1ddc mov r0, r3 */
/* @0x00e1de0 str r2, [sp, #0x4] */
/* @0x00e1de4 add r1, pc, r1 */
/* @0x00e1de8 str r3, [sp] */
/* @0x00e1dec bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e1df0 ldr r3, [sp] */
/* @0x00e1df4 ldr r2, [sp, #0x4] */
/* @0x00e1df8 b 0xe1cc4 <_Z5DoShrjPhPKhP6VMExec+0x75c> */
/* 间接 kindA：Malformed variable（tag 4/6/8/9/11/12 共用） */
/* @0x00e1dfc ldr r1, [pc, #0x13c] */
/* @0x00e1e00 mov r0, r3 */
/* @0x00e1e04 str r3, [sp] */
/* @0x00e1e08 add r1, pc, r1 */
/* @0x00e1e0c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e1e10 mov r2, r4 */
/* @0x00e1e14 ldr r3, [sp] */
/* @0x00e1e18 b 0xe1d3c <_Z5DoShrjPhPKhP6VMExec+0x7d4> */
/* opA 是未解析引用 → JSThrowReferenceError("could not find variable before '>>'") */
/* @0x00e1e1c ldr r0, [pc, #0x120] */
/* @0x00e1e20 add r0, pc, r0 */
/* @0x00e1e24 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0x00e1e28 mov r0, r4 */
/* @0x00e1e2c b 0xe1a60 <_Z5DoShrjPhPKhP6VMExec+0x4f8> */
/* opB 是未解析引用 → JSThrowReferenceError("could not find variable after '>>'") */
/* @0x00e1e30 ldr r0, [pc, #0x110] */
/* @0x00e1e34 add r0, pc, r0 */
/* @0x00e1e38 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0x00e1e3c mov r0, r4 */
/* @0x00e1e40 b 0xe1a60 <_Z5DoShrjPhPKhP6VMExec+0x4f8> */
/* @0x00e1e44 add r7, sp, #56 */
/* @0x00e1e48 mov r1, r5 */
/* @0x00e1e4c mov r0, r7 */
/* @0x00e1e50 bl 0x24d4f4 <_Z13F_JS_ToUint32R6RValueS0_> */
/* @0x00e1e54 cmp r0, #1 */
/* @0x00e1e58 beq 0xe1edc <_Z5DoShrjPhPKhP6VMExec+0x974> */
/* @0x00e1e5c cmp r0, #0 */
/* @0x00e1e60 bne 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0x00e1e64 vldr d6, [sp, #56] */
/* @0x00e1e68 vcvt.u32.f64 s11, d6 */
/* @0x00e1e6c vldr d7, [sp, #40] */
/* @0x00e1e70 ldr r2, [sp, #0x34] */
/* @0x00e1e74 sub r2, r2, #1 */
/* @0x00e1e78 bic r2, r2, #-16777216 */
/* @0x00e1e7c bic r2, r2, #3 */
/* @0x00e1e80 cmp r2, #0 */
/* @0x00e1e84 vcvt.s32.f64 s14, d7 */
/* @0x00e1e88 vmov r3, s11 */
/* @0x00e1e8c vmov r0, s14 */
/* @0x00e1e90 and r3, r3, #31 */
/* @0x00e1e94 asr r3, r0, r3 */
/* @0x00e1e98 vmov s15, r3 */
/* @0x00e1e9c vcvt.f64.s32 d7, s15 */
/* @0x00e1ea0 vmov r2, r3, d7 */
/* @0x00e1ea4 vstr s14, [r4, #-16] */
/* @0x00e1ea8 str r3, [r4, #-0xc] */
/* @0x00e1eac bne 0xe1b18 <_Z5DoShrjPhPKhP6VMExec+0x5b0> */
/* @0x00e1eb0 mov r0, r6 */
/* @0x00e1eb4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x00e1eb8 b 0xe1b18 <_Z5DoShrjPhPKhP6VMExec+0x5b0> */
/* ToUint32 失败 → JSThrowTypeError（文本沿用 DoOr 模板 + #1/#2 后缀） */
/* @0x00e1ebc ldr r0, [pc, #0x88] */
/* @0x00e1ec0 add r0, pc, r0 */
/* @0x00e1ec4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x00e1ec8 b 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* ToInt32 失败 → JSThrowTypeError */
/* @0x00e1ecc ldr r0, [pc, #0x7c] */
/* @0x00e1ed0 add r0, pc, r0 */
/* @0x00e1ed4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x00e1ed8 b 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* ToUint32 失败（opB）→ JSThrowTypeError */
/* @0x00e1edc ldr r0, [pc, #0x70] */
/* @0x00e1ee0 add r0, pc, r0 */
/* @0x00e1ee4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x00e1ee8 b 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* ToInt32 失败（opB）→ JSThrowTypeError */
/* @0x00e1eec ldr r0, [pc, #0x64] */
/* @0x00e1ef0 add r0, pc, r0 */
/* @0x00e1ef4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x00e1ef8 b 0xe165c <_Z5DoShrjPhPKhP6VMExec+0xf4> */
/* @0x00e1efc mov r8, r6 */
/* @0x00e1f00 b 0xe16d8 <_Z5DoShrjPhPKhP6VMExec+0x170> */
/* kindA>6：退回 opB 槽 = base+0 */
/* @0x00e1f04 mov r2, r4 */
/* @0x00e1f08 mov r6, r11 */
/* @0x00e1f0c b 0xe1688 <_Z5DoShrjPhPKhP6VMExec+0x120> */
/* @0x00e1f10 eoreq r2, r5, r8, lsr r11 */
/* @0x00e1f14 eoreq r2, r5, r0, lsr #23 */
/* @0x00e1f18 eoreq r2, r5, r12, ror #12 */
/* @0x00e1f1c .word 0x002525fc */
/* @0x00e1f20 eoreq r2, r5, r0, ror #10 */
/* @0x00e1f24 eoreq r2, r5, r4, lsr #11 */
/* @0x00e1f28 eoreq r2, r5, r4, ror r5 */
/* @0x00e1f2c .word 0x002524b0 */
/* @0x00e1f30 eoreq r2, r5, r0, ror r4 */
/* @0x00e1f34 eoreq r2, r5, r12, lsl #9 */
/* @0x00e1f38 .word 0x002523f4 */
/* @0x00e1f3c eoreq r2, r5, r4, lsl r5 */
/* @0x00e1f40 eoreq r2, r5, r12, lsr r4 */
/* @0x00e1f44 eoreq r2, r5, r8, ror r2 */
/* @0x00e1f48 eoreq r2, r5, r8, lsl #5 */
/* @0x00e1f4c eoreq r2, r5, r0, lsr #4 */
/* @0x00e1f50 eoreq r2, r5, r8, ror r2 */
/* @0x00e1f54 mlaeq r5, r12, r2, r2 */
/* @0x00e1f58 eoreq r2, r5, r4, lsr #4 */
