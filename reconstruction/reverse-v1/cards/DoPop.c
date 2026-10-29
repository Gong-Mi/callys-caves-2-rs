/* cally 逆向卡：DoPop（原版 libyoyo.so，armv7）
 * @func 0xe65e4 0xe7dcc  size 6120  1530 条指令（含 literal 词）
 * 级别: 骨架（opcode 位域与三条主路径已证；15 类型 × refcount 细节未展开）
 * 符号: _Z5DoPopjPhPKhP6VMExec → uchar* DoPop(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   kind   = (arg >> 16) & 0xF        ; e6608 ubfx r6,r5,#0x10,#0x4   —— 位 19..16
 *   flag30 = arg & 0x40000000         ; e666c ands r9,r5,#1073741824 —— 位 30
 *   count  = (int16_t)arg             ; e66a8 sxth r9,r5              —— 位 15..0（有符号）
 *   if (flag30) vb = *(uint32*)base; else vb = ~0;                    ; e6678/e667c
 *   switch (kind) { 2 → 0xe6978; 5 → 同上主路径; 15 → 0xe6834; 其它 → VMError }  ; e6614-e6640
 *   主路径先写 RValue 模板：+12 处 0x00FFFFFF tag、其余三字清零             ; e6684-e6698
 *   函数栈帧 2208 字节 —— 说明存在按类型展开的大 switch                    ; e65f0
 *   count == -9 有专门分支（`cmn r9,#9`）                                  ; e66b8
 *
 * 结论（新增两条硬事实）：
 *   1. **opcode 参数是位域**：[15:0] 有符号 count，[19:16] pop 种类（2/5/15 合法，其余 VMError），
 *      位 30 表示「附带变量基址」——即 DoPushBuiltin 里被 & 0x0FFFFFFF 掩掉的正是这些高位。
 *   2. kind 2 与 kind 5 走不同起始点（0xe6978 vs 主路径），差别在是否保留/释放被弹出的值。
 * open：15 个类型分支各自的 refcount 处理、count == -9 的语义（可能是「弹出到帧基」）、
 *       flag30 的实参 base 解释方式。
 */
/* @0xe65e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe65e8 add r11, sp, #32 */
/* @0xe65ec ldr r7, [pc, #0xfe0] */
/* @0xe65f0 sub sp, sp, #2208 */
/* @0xe65f4 mov r5, r0 */
/* @0xe65f8 sub sp, sp, #4 */
/* @0xe65fc ldr r0, [pc, #0xfd4] */
/* @0xe6600 add r7, pc, r7 */
/* @0xe6604 str r3, [r11, #-0x884] */
/* @0xe6608 ubfx r6, r5, #0x10, #0x4 */
/* @0xe660c mov r4, r1 */
/* @0xe6610 ldr r0, [r7, r0] */
/* @0xe6614 cmp r6, #5 */
/* @0xe6618 ldr r3, [r0] */
/* @0xe661c str r0, [r11, #-0x880] */
/* @0xe6620 str r3, [r11, #-0x28] */
/* @0xe6624 beq 0xe666c <_Z5DoPopjPhPKhP6VMExec+0x88> */
/* @0xe6628 cmp r6, #15 */
/* @0xe662c beq 0xe6834 <_Z5DoPopjPhPKhP6VMExec+0x250> */
/* @0xe6630 cmp r6, #2 */
/* @0xe6634 beq 0xe666c <_Z5DoPopjPhPKhP6VMExec+0x88> */
/* @0xe6638 ldr r1, [pc, #0xf9c] */
/* @0xe663c ldr r0, [r11, #-0x884] */
/* @0xe6640 add r1, pc, r1 */
/* @0xe6644 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe6648 mov r5, r4 */
/* @0xe664c ldr r12, [r11, #-0x880] */
/* @0xe6650 mov r0, r5 */
/* @0xe6654 ldr r2, [r11, #-0x28] */
/* @0xe6658 ldr r3, [r12] */
/* @0xe665c cmp r2, r3 */
/* @0xe6660 bne 0xe7a08 <_Z5DoPopjPhPKhP6VMExec+0x1424> */
/* @0xe6664 sub sp, r11, #32 */
/* @0xe6668 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe666c ands r9, r5, #1073741824 */
/* @0xe6670 mov r3, #0 */
/* @0xe6674 str r3, [r11, #-0x878] */
/* @0xe6678 ldrne r10, [r2] */
/* @0xe667c mvneq r10, #0 */
/* @0xe6680 cmp r6, #2 */
/* @0xe6684 mvn r2, #-16777216 */
/* @0xe6688 subne r8, r11, #2160 */
/* @0xe668c str r3, [r11, #-0x874] */
/* @0xe6690 subne r8, r8, #4 */
/* @0xe6694 str r3, [r11, #-0x870] */
/* @0xe6698 str r2, [r11, #-0x86c] */
/* @0xe669c subne r8, r8, #4 */
/* @0xe66a0 beq 0xe6978 <_Z5DoPopjPhPKhP6VMExec+0x394> */
/* @0xe66a4 cmp r9, #0 */
/* @0xe66a8 sxth r9, r5 */
/* @0xe66ac moveq r12, #-2147483648 */
/* @0xe66b0 streq r12, [r11, #-0x88c] */
/* @0xe66b4 bne 0xe68a4 <_Z5DoPopjPhPKhP6VMExec+0x2c0> */
/* @0xe66b8 cmn r9, #9 */
/* @0xe66bc mov r3, #0 */
/* @0xe66c0 mvn r2, #-16777216 */
/* @0xe66c4 str r3, [r11, #-0x868] */
/* @0xe66c8 str r3, [r11, #-0x864] */
/* @0xe66cc str r3, [r11, #-0x860] */
/* @0xe66d0 str r3, [r11, #-0x858] */
/* @0xe66d4 str r3, [r11, #-0x854] */
/* @0xe66d8 str r3, [r11, #-0x850] */
/* @0xe66dc str r2, [r11, #-0x85c] */
/* @0xe66e0 str r2, [r11, #-0x84c] */
/* @0xe66e4 beq 0xe711c <_Z5DoPopjPhPKhP6VMExec+0xb38> */
/* @0xe66e8 cmn r9, #10 */
/* @0xe66ec beq 0xe7144 <_Z5DoPopjPhPKhP6VMExec+0xb60> */
/* @0xe66f0 cmp r6, #5 */
/* @0xe66f4 beq 0xe69a4 <_Z5DoPopjPhPKhP6VMExec+0x3c0> */
/* @0xe66f8 ldr r3, [pc, #0xee0] */
/* @0xe66fc ldr r3, [r7, r3] */
/* @0xe6700 ldrb r3, [r3] */
/* @0xe6704 cmp r8, #0 */
/* @0xe6708 moveq r3, #0 */
/* @0xe670c andne r3, r3, #1 */
/* @0xe6710 cmp r3, #0 */
/* @0xe6714 beq 0xe68e0 <_Z5DoPopjPhPKhP6VMExec+0x2fc> */
/* @0xe6718 ldr r2, [r8, #0xc] */
/* @0xe671c mvn r3, #-16777216 */
/* @0xe6720 and r2, r2, r3 */
/* @0xe6724 cmp r2, r3 */
/* @0xe6728 movne r12, #0 */
/* @0xe672c strne r12, [r11, #-0x890] */
/* @0xe6730 beq 0xe70cc <_Z5DoPopjPhPKhP6VMExec+0xae8> */
/* @0xe6734 ldr r2, [pc, #0xea8] */
/* @0xe6738 cmp r9, #0 */
/* @0xe673c mov r3, #0 */
/* @0xe6740 ldr r2, [r7, r2] */
/* @0xe6744 str r2, [r11, #-0x888] */
/* @0xe6748 strb r3, [r2] */
/* @0xe674c blt 0xe6934 <_Z5DoPopjPhPKhP6VMExec+0x350> */
/* @0xe6750 mov r0, r9 */
/* @0xe6754 mov r1, r10 */
/* @0xe6758 ldr r2, [r11, #-0x88c] */
/* @0xe675c mov r3, r8 */
/* @0xe6760 bl 0x1f4348 <_Z17Variable_SetValueiiiP6RValue> */
/* @0xe6764 cmp r0, #0 */
/* @0xe6768 beq 0xe677c <_Z5DoPopjPhPKhP6VMExec+0x198> */
/* @0xe676c ldr r12, [r11, #-0x888] */
/* @0xe6770 ldrb r3, [r12] */
/* @0xe6774 cmp r3, #0 */
/* @0xe6778 beq 0xe6800 <_Z5DoPopjPhPKhP6VMExec+0x21c> */
/* @0xe677c ldr r12, [r11, #-0x884] */
/* @0xe6780 mov r1, r9 */
/* @0xe6784 mov r2, r10 */
/* @0xe6788 ldr r0, [r12, #0x34] */
/* @0xe678c bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xe6790 ldr r12, [r11, #-0x888] */
/* @0xe6794 ldrb r3, [r12] */
/* @0xe6798 cmp r3, #0 */
/* @0xe679c mov r1, r0 */
/* @0xe67a0 beq 0xe69dc <_Z5DoPopjPhPKhP6VMExec+0x3f8> */
/* @0xe67a4 ldr r12, [pc, #0xe3c] */
/* @0xe67a8 ldr r2, [pc, #0xe3c] */
/* @0xe67ac ldr r3, [pc, #0xe3c] */
/* @0xe67b0 ldr lr, [r7, r12] */
/* @0xe67b4 ldr r2, [r7, r2] */
/* @0xe67b8 ldr r12, [pc, #0xe34] */
/* @0xe67bc ldr lr, [lr] */
/* @0xe67c0 ldr r3, [r7, r3] */
/* @0xe67c4 ldr r2, [r2] */
/* @0xe67c8 str lr, [sp] */
/* @0xe67cc ldr r12, [r7, r12] */
/* @0xe67d0 ldr r3, [r3] */
/* @0xe67d4 str r9, [sp, #0x8] */
/* @0xe67d8 ldr r12, [r12] */
/* @0xe67dc str r1, [sp, #0xc] */
/* @0xe67e0 ldr r1, [pc, #0xe10] */
/* @0xe67e4 str r12, [sp, #0x4] */
/* @0xe67e8 ldr r12, [r11, #-0x88c] */
/* @0xe67ec add r1, pc, r1 */
/* @0xe67f0 ldr r0, [r11, #-0x884] */
/* @0xe67f4 str r10, [sp, #0x10] */
/* @0xe67f8 str r12, [sp, #0x14] */
/* @0xe67fc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe6800 ldr r3, [r8, #0xc] */
/* @0xe6804 sub r3, r3, #1 */
/* @0xe6808 bic r3, r3, #-16777216 */
/* @0xe680c bic r3, r3, #3 */
/* @0xe6810 cmp r3, #0 */
/* @0xe6814 beq 0xe69f4 <_Z5DoPopjPhPKhP6VMExec+0x410> */
/* @0xe6818 mov r3, #0 */
/* @0xe681c mov r2, #5 */
/* @0xe6820 mov r5, r4 */
/* @0xe6824 str r3, [r8, #0x8] */
/* @0xe6828 str r3, [r8] */
/* @0xe682c str r2, [r8, #0xc] */
/* @0xe6830 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe6834 ubfx r0, r5, #0x14, #0x4 */
/* @0xe6838 lsl r8, r5, #24 */
/* @0xe683c bl 0xd7760 <_Z16ParamSizeOnStacki> */
/* @0xe6840 mov r1, r4 */
/* @0xe6844 asr r8, r8, #22 */
/* @0xe6848 sbfx r5, r5, #0x6, #0xa */
/* @0xe684c add r8, r8, #3 */
/* @0xe6850 bic r5, r5, #3 */
/* @0xe6854 add r5, r4, r5 */
/* @0xe6858 add r3, r0, #14 */
/* @0xe685c mov r6, r0 */
/* @0xe6860 bic r3, r3, #7 */
/* @0xe6864 mov r2, r0 */
/* @0xe6868 sub sp, sp, r3 */
/* @0xe686c add r7, sp, #24 */
/* @0xe6870 mov r0, r7 */
/* @0xe6874 bl 0xb65bc <memcpy@plt> */
/* @0xe6878 bic r2, r8, #3 */
/* @0xe687c add r8, r4, r2 */
/* @0xe6880 rsb r0, r6, r2 */
/* @0xe6884 add r0, r4, r0 */
/* @0xe6888 mov r1, r8 */
/* @0xe688c bl 0xb6694 <memmove@plt> */
/* @0xe6890 mov r0, r8 */
/* @0xe6894 mov r1, r7 */
/* @0xe6898 mov r2, r6 */
/* @0xe689c bl 0xb65bc <memcpy@plt> */
/* @0xe68a0 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe68a4 tst r10, #268435456 */
/* @0xe68a8 ldrne r3, [r8, #0x8] */
/* @0xe68ac bicne r3, r3, #2 */
/* @0xe68b0 strne r3, [r8, #0x8] */
/* @0xe68b4 cmp r10, #0 */
/* @0xe68b8 ldrge r12, [r4], #4 */
/* @0xe68bc movlt r12, #-2147483648 */
/* @0xe68c0 tst r10, #536870912 */
/* @0xe68c4 ldreq r9, [r4], #4 */
/* @0xe68c8 tst r10, #1073741824 */
/* @0xe68cc addne r3, r9, #99328 */
/* @0xe68d0 str r12, [r11, #-0x88c] */
/* @0xe68d4 addne r9, r3, #672 */
/* @0xe68d8 bic r10, r10, #-268435456 */
/* @0xe68dc b 0xe66b8 <_Z5DoPopjPhPKhP6VMExec+0xd4> */
/* @0xe68e0 str r3, [r11, #-0x890] */
/* @0xe68e4 b 0xe6734 <_Z5DoPopjPhPKhP6VMExec+0x150> */
/* @0xe68e8 add r3, r9, #10 */
/* @0xe68ec cmp r3, #1 */
/* @0xe68f0 movhi r3, #1 */
/* @0xe68f4 movhi r8, #0 */
/* @0xe68f8 strhi r3, [r11, #-0x890] */
/* @0xe68fc bhi 0xe6734 <_Z5DoPopjPhPKhP6VMExec+0x150> */
/* @0xe6900 ldr r2, [r11, #-0x85c] */
/* @0xe6904 mvn r3, #-16777216 */
/* @0xe6908 and r2, r2, r3 */
/* @0xe690c cmp r2, r3 */
/* @0xe6910 beq 0xe79f4 <_Z5DoPopjPhPKhP6VMExec+0x1410> */
/* @0xe6914 ldr r2, [pc, #0xcc8] */
/* @0xe6918 mov r12, #1 */
/* @0xe691c str r12, [r11, #-0x890] */
/* @0xe6920 mov r3, #0 */
/* @0xe6924 mov r8, r3 */
/* @0xe6928 ldr r2, [r7, r2] */
/* @0xe692c str r2, [r11, #-0x888] */
/* @0xe6930 strb r3, [r2] */
/* @0xe6934 add r3, r9, #13 */
/* @0xe6938 cmp r3, #12 */
/* @0xe693c addls pc, pc, r3, lsl #2 */
/* @0xe6940 b 0xe7070 <_Z5DoPopjPhPKhP6VMExec+0xa8c> */
/* @0xe6944 b 0xe6f10 <_Z5DoPopjPhPKhP6VMExec+0x92c> */
/* @0xe6948 b 0xe6e7c <_Z5DoPopjPhPKhP6VMExec+0x898> */
/* @0xe694c b 0xe6e40 <_Z5DoPopjPhPKhP6VMExec+0x85c> */
/* @0xe6950 b 0xe6da8 <_Z5DoPopjPhPKhP6VMExec+0x7c4> */
/* @0xe6954 b 0xe6bc0 <_Z5DoPopjPhPKhP6VMExec+0x5dc> */
/* @0xe6958 b 0xe6a00 <_Z5DoPopjPhPKhP6VMExec+0x41c> */
/* @0xe695c b 0xe6b40 <_Z5DoPopjPhPKhP6VMExec+0x55c> */
/* @0xe6960 b 0xe6a00 <_Z5DoPopjPhPKhP6VMExec+0x41c> */
/* @0xe6964 b 0xe6a10 <_Z5DoPopjPhPKhP6VMExec+0x42c> */
/* @0xe6968 b 0xe7070 <_Z5DoPopjPhPKhP6VMExec+0xa8c> */
/* @0xe696c b 0xe7070 <_Z5DoPopjPhPKhP6VMExec+0xa8c> */
/* @0xe6970 b 0xe6b24 <_Z5DoPopjPhPKhP6VMExec+0x540> */
/* @0xe6974 b 0xe6b08 <_Z5DoPopjPhPKhP6VMExec+0x524> */
/* @0xe6978 ubfx r3, r5, #0x14, #0x4 */
/* @0xe697c cmp r3, #6 */
/* @0xe6980 addls pc, pc, r3, lsl #2 */
/* @0xe6984 b 0xe7050 <_Z5DoPopjPhPKhP6VMExec+0xa6c> */
/* @0xe6988 b 0xe6ae0 <_Z5DoPopjPhPKhP6VMExec+0x4fc> */
/* @0xe698c b 0xe7050 <_Z5DoPopjPhPKhP6VMExec+0xa6c> */
/* @0xe6990 b 0xe6ab4 <_Z5DoPopjPhPKhP6VMExec+0x4d0> */
/* @0xe6994 b 0xe6a90 <_Z5DoPopjPhPKhP6VMExec+0x4ac> */
/* @0xe6998 b 0xe6a58 <_Z5DoPopjPhPKhP6VMExec+0x474> */
/* @0xe699c b 0xe6a4c <_Z5DoPopjPhPKhP6VMExec+0x468> */
/* @0xe69a0 b 0xe6a2c <_Z5DoPopjPhPKhP6VMExec+0x448> */
/* @0xe69a4 ubfx r5, r5, #0x14, #0x4 */
/* @0xe69a8 cmp r5, #9 */
/* @0xe69ac addls pc, pc, r5, lsl #2 */
/* @0xe69b0 b 0xe70a8 <_Z5DoPopjPhPKhP6VMExec+0xac4> */
/* @0xe69b4 b 0xe7018 <_Z5DoPopjPhPKhP6VMExec+0xa34> */
/* @0xe69b8 b 0xe70a8 <_Z5DoPopjPhPKhP6VMExec+0xac4> */
/* @0xe69bc b 0xe6ff4 <_Z5DoPopjPhPKhP6VMExec+0xa10> */
/* @0xe69c0 b 0xe7038 <_Z5DoPopjPhPKhP6VMExec+0xa54> */
/* @0xe69c4 b 0xe6f38 <_Z5DoPopjPhPKhP6VMExec+0x954> */
/* @0xe69c8 b 0xe7044 <_Z5DoPopjPhPKhP6VMExec+0xa60> */
/* @0xe69cc b 0xe6fe0 <_Z5DoPopjPhPKhP6VMExec+0x9fc> */
/* @0xe69d0 b 0xe70a8 <_Z5DoPopjPhPKhP6VMExec+0xac4> */
/* @0xe69d4 b 0xe68e8 <_Z5DoPopjPhPKhP6VMExec+0x304> */
/* @0xe69d8 b 0xe6f68 <_Z5DoPopjPhPKhP6VMExec+0x984> */
/* @0xe69dc mov r2, r1 */
/* @0xe69e0 ldr r1, [pc, #0xc14] */
/* @0xe69e4 ldr r0, [r11, #-0x884] */
/* @0xe69e8 add r1, pc, r1 */
/* @0xe69ec bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe69f0 b 0xe6800 <_Z5DoPopjPhPKhP6VMExec+0x21c> */
/* @0xe69f4 mov r0, r8 */
/* @0xe69f8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe69fc b 0xe6818 <_Z5DoPopjPhPKhP6VMExec+0x234> */
/* @0xe6a00 mov r0, r10 */
/* @0xe6a04 bl 0x1f3484 <_Z24Variable_Global_Declaredi> */
/* @0xe6a08 cmp r0, #0 */
/* @0xe6a0c beq 0xe6b08 <_Z5DoPopjPhPKhP6VMExec+0x524> */
/* @0xe6a10 mov r0, r10 */
/* @0xe6a14 ldr r1, [r11, #-0x88c] */
/* @0xe6a18 mov r2, r8 */
/* @0xe6a1c bl 0x1f38f8 <_Z22Variable_Global_SetVariiP6RValue> */
/* @0xe6a20 ldr r12, [r11, #-0x888] */
/* @0xe6a24 ldrb r3, [r12] */
/* @0xe6a28 b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe6a2c ldr r3, [r4], #4 */
/* @0xe6a30 sub r8, r11, #2160 */
/* @0xe6a34 sub r8, r8, #4 */
/* @0xe6a38 mov r2, #1 */
/* @0xe6a3c sub r8, r8, #4 */
/* @0xe6a40 str r2, [r11, #-0x86c] */
/* @0xe6a44 str r3, [r11, #-0x878] */
/* @0xe6a48 b 0xe66a4 <_Z5DoPopjPhPKhP6VMExec+0xc0> */
/* @0xe6a4c mov r8, r4 */
/* @0xe6a50 add r4, r4, #16 */
/* @0xe6a54 b 0xe66a4 <_Z5DoPopjPhPKhP6VMExec+0xc0> */
/* @0xe6a58 ldr r3, [r4] */
/* @0xe6a5c sub r8, r11, #36 */
/* @0xe6a60 mov r2, #13 */
/* @0xe6a64 str r2, [r11, #-0x86c] */
/* @0xe6a68 cmp r3, #0 */
/* @0xe6a6c add r4, r4, #4 */
/* @0xe6a70 movne r2, #0 */
/* @0xe6a74 moveq r2, r3 */
/* @0xe6a78 movne r3, r2 */
/* @0xe6a7c movtne r2, #0x3ff0 */
/* @0xe6a80 str r3, [r11, #-0x878] */
/* @0xe6a84 str r2, [r8, #-0x850]! */
/* @0xe6a88 sub r8, r8, #4 */
/* @0xe6a8c b 0xe66a4 <_Z5DoPopjPhPKhP6VMExec+0xc0> */
/* @0xe6a90 ldrd r0, r1, [r4], #8 */
/* @0xe6a94 mov r3, #0 */
/* @0xe6a98 str r3, [r11, #-0x86c] */
/* @0xe6a9c bl 0x319164 <__floatdidf> */
/* @0xe6aa0 sub r8, r11, #36 */
/* @0xe6aa4 str r0, [r11, #-0x878] */
/* @0xe6aa8 str r1, [r8, #-0x850]! */
/* @0xe6aac sub r8, r8, #4 */
/* @0xe6ab0 b 0xe66a4 <_Z5DoPopjPhPKhP6VMExec+0xc0> */
/* @0xe6ab4 ldr r2, [r4], #4 */
/* @0xe6ab8 mov r3, #0 */
/* @0xe6abc str r3, [r11, #-0x86c] */
/* @0xe6ac0 sub r8, r11, #36 */
/* @0xe6ac4 vmov s15, r2 */
/* @0xe6ac8 vcvt.f64.s32 d7, s15 */
/* @0xe6acc vmov r2, r3, d7 */
/* @0xe6ad0 str r3, [r8, #-0x850]! */
/* @0xe6ad4 sub r8, r8, #4 */
/* @0xe6ad8 str r2, [r11, #-0x878] */
/* @0xe6adc b 0xe66a4 <_Z5DoPopjPhPKhP6VMExec+0xc0> */
/* @0xe6ae0 ldr r2, [r4, #0x4] */
/* @0xe6ae4 sub r8, r11, #36 */
/* @0xe6ae8 ldr r3, [r4] */
/* @0xe6aec mov r1, #0 */
/* @0xe6af0 add r4, r4, #8 */
/* @0xe6af4 str r1, [r11, #-0x86c] */
/* @0xe6af8 str r2, [r8, #-0x850]! */
/* @0xe6afc sub r8, r8, #4 */
/* @0xe6b00 str r3, [r11, #-0x878] */
/* @0xe6b04 b 0xe66a4 <_Z5DoPopjPhPKhP6VMExec+0xc0> */
/* @0xe6b08 ldr r12, [r11, #-0x884] */
/* @0xe6b0c mov r1, r10 */
/* @0xe6b10 ldr r2, [r11, #-0x88c] */
/* @0xe6b14 mov r3, r8 */
/* @0xe6b18 ldr r0, [r12, #0x14] */
/* @0xe6b1c bl 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0xe6b20 b 0xe6764 <_Z5DoPopjPhPKhP6VMExec+0x180> */
/* @0xe6b24 ldr r12, [r11, #-0x884] */
/* @0xe6b28 mov r1, r10 */
/* @0xe6b2c ldr r2, [r11, #-0x88c] */
/* @0xe6b30 mov r3, r8 */
/* @0xe6b34 ldr r0, [r12, #0x18] */
/* @0xe6b38 bl 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0xe6b3c b 0xe6764 <_Z5DoPopjPhPKhP6VMExec+0x180> */
/* @0xe6b40 ldr r12, [r11, #-0x884] */
/* @0xe6b44 ldr r6, [r12, #0x10] */
/* @0xe6b48 cmp r6, #0 */
/* @0xe6b4c beq 0xe7514 <_Z5DoPopjPhPKhP6VMExec+0xf30> */
/* @0xe6b50 mov r0, r6 */
/* @0xe6b54 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe6b58 ldr r3, [r6, #0x24] */
/* @0xe6b5c cmp r3, #0 */
/* @0xe6b60 beq 0xe72e4 <_Z5DoPopjPhPKhP6VMExec+0xd00> */
/* @0xe6b64 ldr r3, [r11, #-0x890] */
/* @0xe6b68 sub r1, r10, #99328 */
/* @0xe6b6c sub r1, r1, #672 */
/* @0xe6b70 cmp r3, #0 */
/* @0xe6b74 ldr r3, [r6, #0x4] */
/* @0xe6b78 beq 0xe72cc <_Z5DoPopjPhPKhP6VMExec+0xce8> */
/* @0xe6b7c cmp r3, #0 */
/* @0xe6b80 mov r2, #13 */
/* @0xe6b84 sub r5, r4, #16 */
/* @0xe6b88 str r2, [r4, #-0x4] */
/* @0xe6b8c beq 0xe7c9c <_Z5DoPopjPhPKhP6VMExec+0x16b8> */
/* @0xe6b90 add r0, r3, r1, lsl #4 */
/* @0xe6b94 ldr r3, [r0, #0xc] */
/* @0xe6b98 bic r3, r3, #-16777216 */
/* @0xe6b9c cmp r3, #5 */
/* @0xe6ba0 moveq r3, #0 */
/* @0xe6ba4 movne r2, #0 */
/* @0xe6ba8 moveq r2, r3 */
/* @0xe6bac movteq r3, #0x3ff0 */
/* @0xe6bb0 movne r3, r2 */
/* @0xe6bb4 str r2, [r4, #-0x10] */
/* @0xe6bb8 str r3, [r4, #-0xc] */
/* @0xe6bbc b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe6bc0 ldr r3, [r11, #-0x85c] */
/* @0xe6bc4 bic r3, r3, #-16777216 */
/* @0xe6bc8 cmp r3, #3 */
/* @0xe6bcc beq 0xe74bc <_Z5DoPopjPhPKhP6VMExec+0xed8> */
/* @0xe6bd0 cmp r3, #6 */
/* @0xe6bd4 bne 0xe7484 <_Z5DoPopjPhPKhP6VMExec+0xea0> */
/* @0xe6bd8 ldr r12, [r11, #-0x868] */
/* @0xe6bdc str r12, [r11, #-0x89c] */
/* @0xe6be0 ldr r3, [r11, #-0x89c] */
/* @0xe6be4 cmp r3, #0 */
/* @0xe6be8 beq 0xe7498 <_Z5DoPopjPhPKhP6VMExec+0xeb4> */
/* @0xe6bec mov r0, r3 */
/* @0xe6bf0 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe6bf4 ldr r12, [r11, #-0x89c] */
/* @0xe6bf8 sub r3, r10, #99328 */
/* @0xe6bfc sub r3, r3, #672 */
/* @0xe6c00 str r3, [r11, #-0x898] */
/* @0xe6c04 ldr r12, [r12, #0x60] */
/* @0xe6c08 cmp r12, #0 */
/* @0xe6c0c str r12, [r11, #-0x894] */
/* @0xe6c10 beq 0xe6cb8 <_Z5DoPopjPhPKhP6VMExec+0x6d4> */
/* @0xe6c14 mov r0, r3 */
/* @0xe6c18 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0xe6c1c ldr r2, [r11, #-0x894] */
/* @0xe6c20 ldr r1, [r2, #0x8] */
/* @0xe6c24 ldr r6, [r2, #0x10] */
/* @0xe6c28 bic r5, r0, #-2147483648 */
/* @0xe6c2c and r3, r5, r1 */
/* @0xe6c30 lsl r12, r3, #1 */
/* @0xe6c34 add r2, r12, r3 */
/* @0xe6c38 add r2, r6, r2, lsl #2 */
/* @0xe6c3c ldr r2, [r2, #0x8] */
/* @0xe6c40 cmp r2, #0 */
/* @0xe6c44 beq 0xe6cb8 <_Z5DoPopjPhPKhP6VMExec+0x6d4> */
/* @0xe6c48 cmp r5, r2 */
/* @0xe6c4c beq 0xe75b8 <_Z5DoPopjPhPKhP6VMExec+0xfd4> */
/* @0xe6c50 ldr r12, [r11, #-0x894] */
/* @0xe6c54 and r2, r1, r2 */
/* @0xe6c58 ldr lr, [r12] */
/* @0xe6c5c add r0, r3, lr */
/* @0xe6c60 rsb r2, r2, r0 */
/* @0xe6c64 tst r2, r1 */
/* @0xe6c68 bmi 0xe6cb8 <_Z5DoPopjPhPKhP6VMExec+0x6d4> */
/* @0xe6c6c mov r0, #0 */
/* @0xe6c70 b 0xe6c94 <_Z5DoPopjPhPKhP6VMExec+0x6b0> */
/* @0xe6c74 cmp r5, r2 */
/* @0xe6c78 beq 0xe75b0 <_Z5DoPopjPhPKhP6VMExec+0xfcc> */
/* @0xe6c7c and r2, r1, r2 */
/* @0xe6c80 add r12, r3, lr */
/* @0xe6c84 rsb r2, r2, r12 */
/* @0xe6c88 and r2, r2, r1 */
/* @0xe6c8c cmp r2, r0 */
/* @0xe6c90 blt 0xe6cb8 <_Z5DoPopjPhPKhP6VMExec+0x6d4> */
/* @0xe6c94 add r3, r3, #1 */
/* @0xe6c98 add r0, r0, #1 */
/* @0xe6c9c and r3, r1, r3 */
/* @0xe6ca0 lsl r12, r3, #1 */
/* @0xe6ca4 add r2, r12, r3 */
/* @0xe6ca8 add r2, r6, r2, lsl #2 */
/* @0xe6cac ldr r2, [r2, #0x8] */
/* @0xe6cb0 cmp r2, #0 */
/* @0xe6cb4 bne 0xe6c74 <_Z5DoPopjPhPKhP6VMExec+0x690> */
/* @0xe6cb8 mov r2, #0 */
/* @0xe6cbc str r2, [r11, #-0x894] */
/* @0xe6cc0 ldr r6, [r11, #-0x89c] */
/* @0xe6cc4 str r10, [r11, #-0x8a0] */
/* @0xe6cc8 cmp r2, #0 */
/* @0xe6ccc beq 0xe6ce4 <_Z5DoPopjPhPKhP6VMExec+0x700> */
/* @0xe6cd0 ldr r3, [r2] */
/* @0xe6cd4 mvn r0, #-16777216 */
/* @0xe6cd8 ldr r3, [r3, #0xc] */
/* @0xe6cdc cmp r3, r0 */
/* @0xe6ce0 bne 0xe71f4 <_Z5DoPopjPhPKhP6VMExec+0xc10> */
/* @0xe6ce4 cmp r6, #0 */
/* @0xe6ce8 beq 0xe71f4 <_Z5DoPopjPhPKhP6VMExec+0xc10> */
/* @0xe6cec ldr r6, [r6, #0x18] */
/* @0xe6cf0 cmp r6, #0 */
/* @0xe6cf4 beq 0xe6cc8 <_Z5DoPopjPhPKhP6VMExec+0x6e4> */
/* @0xe6cf8 ldr r10, [r6, #0x60] */
/* @0xe6cfc cmp r10, #0 */
/* @0xe6d00 beq 0xe6da0 <_Z5DoPopjPhPKhP6VMExec+0x7bc> */
/* @0xe6d04 ldr r0, [r11, #-0x898] */
/* @0xe6d08 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0xe6d0c ldr r1, [r10, #0x8] */
/* @0xe6d10 ldr r5, [r10, #0x10] */
/* @0xe6d14 bic r0, r0, #-2147483648 */
/* @0xe6d18 and r3, r0, r1 */
/* @0xe6d1c lsl lr, r3, #1 */
/* @0xe6d20 add r2, lr, r3 */
/* @0xe6d24 add r2, r5, r2, lsl #2 */
/* @0xe6d28 ldr r2, [r2, #0x8] */
/* @0xe6d2c cmp r2, #0 */
/* @0xe6d30 beq 0xe6da0 <_Z5DoPopjPhPKhP6VMExec+0x7bc> */
/* @0xe6d34 cmp r0, r2 */
/* @0xe6d38 beq 0xe71ac <_Z5DoPopjPhPKhP6VMExec+0xbc8> */
/* @0xe6d3c ldr r10, [r10] */
/* @0xe6d40 and r2, r1, r2 */
/* @0xe6d44 add r12, r3, r10 */
/* @0xe6d48 rsb r2, r2, r12 */
/* @0xe6d4c tst r2, r1 */
/* @0xe6d50 bmi 0xe6da0 <_Z5DoPopjPhPKhP6VMExec+0x7bc> */
/* @0xe6d54 mov r12, #0 */
/* @0xe6d58 b 0xe6d7c <_Z5DoPopjPhPKhP6VMExec+0x798> */
/* @0xe6d5c cmp r0, r2 */
/* @0xe6d60 beq 0xe71a4 <_Z5DoPopjPhPKhP6VMExec+0xbc0> */
/* @0xe6d64 and r2, r1, r2 */
/* @0xe6d68 add lr, r3, r10 */
/* @0xe6d6c rsb r2, r2, lr */
/* @0xe6d70 and r2, r2, r1 */
/* @0xe6d74 cmp r2, r12 */
/* @0xe6d78 blt 0xe6da0 <_Z5DoPopjPhPKhP6VMExec+0x7bc> */
/* @0xe6d7c add r3, r3, #1 */
/* @0xe6d80 add r12, r12, #1 */
/* @0xe6d84 and r3, r1, r3 */
/* @0xe6d88 lsl lr, r3, #1 */
/* @0xe6d8c add r2, lr, r3 */
/* @0xe6d90 add r2, r5, r2, lsl #2 */
/* @0xe6d94 ldr r2, [r2, #0x8] */
/* @0xe6d98 cmp r2, #0 */
/* @0xe6d9c bne 0xe6d5c <_Z5DoPopjPhPKhP6VMExec+0x778> */
/* @0xe6da0 mov r2, #0 */
/* @0xe6da4 b 0xe6ce4 <_Z5DoPopjPhPKhP6VMExec+0x700> */
/* @0xe6da8 ldr r2, [r11, #-0x85c] */
/* @0xe6dac bic r3, r2, #-16777216 */
/* @0xe6db0 cmp r3, #2 */
/* @0xe6db4 beq 0xe7538 <_Z5DoPopjPhPKhP6VMExec+0xf54> */
/* @0xe6db8 cmp r3, #6 */
/* @0xe6dbc beq 0xe78d0 <_Z5DoPopjPhPKhP6VMExec+0x12ec> */
/* @0xe6dc0 ldr r3, [pc, #0x838] */
/* @0xe6dc4 ldr r3, [r7, r3] */
/* @0xe6dc8 ldrb r6, [r3] */
/* @0xe6dcc cmp r6, #0 */
/* @0xe6dd0 bne 0xe6800 <_Z5DoPopjPhPKhP6VMExec+0x21c> */
/* @0xe6dd4 ldr r12, [r11, #-0x884] */
/* @0xe6dd8 mov r2, r10 */
/* @0xe6ddc mvn r1, #9 */
/* @0xe6de0 mov r5, r4 */
/* @0xe6de4 ldr r0, [r12, #0x34] */
/* @0xe6de8 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xe6dec mov r1, r10 */
/* @0xe6df0 mov r4, r0 */
/* @0xe6df4 mvn r0, #9 */
/* @0xe6df8 bl 0x1f3f8c <_Z22Variable_GetObjectNameii> */
/* @0xe6dfc str r4, [sp] */
/* @0xe6e00 sub r4, r11, #2080 */
/* @0xe6e04 ldr r12, [r11, #-0x88c] */
/* @0xe6e08 sub r4, r4, #4 */
/* @0xe6e0c ldr r2, [pc, #0x7f0] */
/* @0xe6e10 sub r4, r4, #4 */
/* @0xe6e14 str r10, [sp, #0x4] */
/* @0xe6e18 mov r1, #2048 */
/* @0xe6e1c str r12, [sp, #0x8] */
/* @0xe6e20 add r2, pc, r2 */
/* @0xe6e24 mov r3, r0 */
/* @0xe6e28 mov r0, r4 */
/* @0xe6e2c bl 0xb65c8 <snprintf@plt> */
/* @0xe6e30 mov r0, r4 */
/* @0xe6e34 strb r6, [r11, #-0x29] */
/* @0xe6e38 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe6e3c b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe6e40 ldr r12, [r11, #-0x890] */
/* @0xe6e44 mov r0, r10 */
/* @0xe6e48 ldr r1, [r11, #-0x88c] */
/* @0xe6e4c cmp r12, #0 */
/* @0xe6e50 beq 0xe7470 <_Z5DoPopjPhPKhP6VMExec+0xe8c> */
/* @0xe6e54 bl 0x1f34bc <_Z24Variable_Scope_DeleteVarii> */
/* @0xe6e58 sub r5, r4, #16 */
/* @0xe6e5c mov r3, #13 */
/* @0xe6e60 str r3, [r4, #-0x4] */
/* @0xe6e64 vmov s15, r0 */
/* @0xe6e68 vcvt.f64.u32 d7, s15 */
/* @0xe6e6c vmov r0, r1, d7 */
/* @0xe6e70 vmov r2, s14 */
/* @0xe6e74 mov r3, r1 */
/* @0xe6e78 b 0xe6bb4 <_Z5DoPopjPhPKhP6VMExec+0x5d0> */
/* @0xe6e7c ldr r12, [r11, #-0x884] */
/* @0xe6e80 ldr r5, [r12, #0x10] */
/* @0xe6e84 cmp r5, #0 */
/* @0xe6e88 beq 0xe7858 <_Z5DoPopjPhPKhP6VMExec+0x1274> */
/* @0xe6e8c sub r6, r10, #99328 */
/* @0xe6e90 mvn r3, #-16777216 */
/* @0xe6e94 sub r6, r6, #672 */
/* @0xe6e98 lsl r12, r6, #4 */
/* @0xe6e9c ldr r2, [r5, #0x24] */
/* @0xe6ea0 cmp r2, #0 */
/* @0xe6ea4 beq 0xe70bc <_Z5DoPopjPhPKhP6VMExec+0xad8> */
/* @0xe6ea8 cmp r2, r6 */
/* @0xe6eac bls 0xe70bc <_Z5DoPopjPhPKhP6VMExec+0xad8> */
/* @0xe6eb0 ldr r2, [r5, #0x4] */
/* @0xe6eb4 cmp r2, #0 */
/* @0xe6eb8 beq 0xe77f0 <_Z5DoPopjPhPKhP6VMExec+0x120c> */
/* @0xe6ebc add r0, r2, r12 */
/* @0xe6ec0 ldr r2, [r0, #0xc] */
/* @0xe6ec4 bic r2, r2, #-16777216 */
/* @0xe6ec8 cmp r2, r3 */
/* @0xe6ecc beq 0xe70bc <_Z5DoPopjPhPKhP6VMExec+0xad8> */
/* @0xe6ed0 ldr r3, [r11, #-0x890] */
/* @0xe6ed4 cmp r3, #0 */
/* @0xe6ed8 bne 0xe7820 <_Z5DoPopjPhPKhP6VMExec+0x123c> */
/* @0xe6edc mov r0, r5 */
/* @0xe6ee0 str r12, [r11, #-0x8a8] */
/* @0xe6ee4 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe6ee8 ldr r0, [r5, #0x4] */
/* @0xe6eec ldr r12, [r11, #-0x8a8] */
/* @0xe6ef0 cmp r0, #0 */
/* @0xe6ef4 beq 0xe7810 <_Z5DoPopjPhPKhP6VMExec+0x122c> */
/* @0xe6ef8 add r0, r0, r12 */
/* @0xe6efc mov r1, r8 */
/* @0xe6f00 ldr r2, [r11, #-0x88c] */
/* @0xe6f04 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0xe6f08 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xe6f0c b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe6f10 ldr r3, [r11, #-0x890] */
/* @0xe6f14 cmp r3, #0 */
/* @0xe6f18 beq 0xe72f4 <_Z5DoPopjPhPKhP6VMExec+0xd10> */
/* @0xe6f1c mov r3, #0 */
/* @0xe6f20 mov r2, #13 */
/* @0xe6f24 sub r5, r4, #16 */
/* @0xe6f28 str r2, [r4, #-0x4] */
/* @0xe6f2c str r3, [r4, #-0x10] */
/* @0xe6f30 str r3, [r4, #-0xc] */
/* @0xe6f34 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe6f38 ldr r2, [r4] */
/* @0xe6f3c mov r3, #13 */
/* @0xe6f40 str r3, [r11, #-0x86c] */
/* @0xe6f44 add r4, r4, #4 */
/* @0xe6f48 cmp r2, #0 */
/* @0xe6f4c movne r3, #0 */
/* @0xe6f50 moveq r3, r2 */
/* @0xe6f54 movne r2, r3 */
/* @0xe6f58 movtne r3, #0x3ff0 */
/* @0xe6f5c str r2, [r11, #-0x878] */
/* @0xe6f60 str r3, [r11, #-0x874] */
/* @0xe6f64 b 0xe66f8 <_Z5DoPopjPhPKhP6VMExec+0x114> */
/* @0xe6f68 cmn r9, #12 */
/* @0xe6f6c bne 0xe66f8 <_Z5DoPopjPhPKhP6VMExec+0x114> */
/* @0xe6f70 movw r3, #0x86a0 */
/* @0xe6f74 movt r3, #0x1 */
/* @0xe6f78 cmp r10, r3 */
/* @0xe6f7c mov r2, #5 */
/* @0xe6f80 mov r3, #0 */
/* @0xe6f84 str r2, [r11, #-0x82c] */
/* @0xe6f88 str r3, [r11, #-0x838] */
/* @0xe6f8c str r3, [r11, #-0x834] */
/* @0xe6f90 beq 0xe6648 <_Z5DoPopjPhPKhP6VMExec+0x64> */
/* @0xe6f94 ldr r12, [r11, #-0x884] */
/* @0xe6f98 ldr r5, [r12, #0x10] */
/* @0xe6f9c mov r0, r5 */
/* @0xe6fa0 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe6fa4 ldr r3, [r5, #0x24] */
/* @0xe6fa8 cmp r3, #0 */
/* @0xe6fac beq 0xe6fd8 <_Z5DoPopjPhPKhP6VMExec+0x9f4> */
/* @0xe6fb0 ldr r0, [r5, #0x4] */
/* @0xe6fb4 sub r1, r10, #99328 */
/* @0xe6fb8 sub r1, r1, #672 */
/* @0xe6fbc cmp r0, #0 */
/* @0xe6fc0 beq 0xe7d90 <_Z5DoPopjPhPKhP6VMExec+0x17ac> */
/* @0xe6fc4 add r0, r0, r1, lsl #4 */
/* @0xe6fc8 sub r1, r11, #2096 */
/* @0xe6fcc ldr r2, [r11, #-0x88c] */
/* @0xe6fd0 sub r1, r1, #8 */
/* @0xe6fd4 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0xe6fd8 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xe6fdc b 0xe6648 <_Z5DoPopjPhPKhP6VMExec+0x64> */
/* @0xe6fe0 ldr r3, [r4], #4 */
/* @0xe6fe4 mov r2, #1 */
/* @0xe6fe8 str r2, [r11, #-0x86c] */
/* @0xe6fec str r3, [r11, #-0x878] */
/* @0xe6ff0 b 0xe66f8 <_Z5DoPopjPhPKhP6VMExec+0x114> */
/* @0xe6ff4 ldr r2, [r4], #4 */
/* @0xe6ff8 mov r3, #0 */
/* @0xe6ffc str r3, [r11, #-0x86c] */
/* @0xe7000 vmov s15, r2 */
/* @0xe7004 vcvt.f64.s32 d7, s15 */
/* @0xe7008 vmov r2, r3, d7 */
/* @0xe700c str r2, [r11, #-0x878] */
/* @0xe7010 str r3, [r11, #-0x874] */
/* @0xe7014 b 0xe66f8 <_Z5DoPopjPhPKhP6VMExec+0x114> */
/* @0xe7018 ldr r2, [r4] */
/* @0xe701c mov r1, #0 */
/* @0xe7020 ldr r3, [r4, #0x4] */
/* @0xe7024 add r4, r4, #8 */
/* @0xe7028 str r1, [r11, #-0x86c] */
/* @0xe702c str r2, [r11, #-0x878] */
/* @0xe7030 str r3, [r11, #-0x874] */
/* @0xe7034 b 0xe66f8 <_Z5DoPopjPhPKhP6VMExec+0x114> */
/* @0xe7038 ldr r2, [r4] */
/* @0xe703c mov r1, #10 */
/* @0xe7040 b 0xe7020 <_Z5DoPopjPhPKhP6VMExec+0xa3c> */
/* @0xe7044 mov r8, r4 */
/* @0xe7048 add r4, r4, #16 */
/* @0xe704c b 0xe66f8 <_Z5DoPopjPhPKhP6VMExec+0x114> */
/* @0xe7050 ldr r1, [pc, #0x5b0] */
/* @0xe7054 sub r8, r11, #2160 */
/* @0xe7058 ldr r0, [r11, #-0x884] */
/* @0xe705c sub r8, r8, #4 */
/* @0xe7060 add r1, pc, r1 */
/* @0xe7064 sub r8, r8, #4 */
/* @0xe7068 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe706c b 0xe66a4 <_Z5DoPopjPhPKhP6VMExec+0xc0> */
/* @0xe7070 ldr r12, [r11, #-0x884] */
/* @0xe7074 mov r1, r9 */
/* @0xe7078 mov r2, r10 */
/* @0xe707c ldr r0, [r12, #0x34] */
/* @0xe7080 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xe7084 ldr r1, [pc, #0x580] */
/* @0xe7088 mov r2, r9 */
/* @0xe708c add r1, pc, r1 */
/* @0xe7090 mov r3, r0 */
/* @0xe7094 ldr r0, [r11, #-0x884] */
/* @0xe7098 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe709c ldr r12, [r11, #-0x888] */
/* @0xe70a0 ldrb r3, [r12] */
/* @0xe70a4 b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe70a8 ldr r1, [pc, #0x560] */
/* @0xe70ac ldr r0, [r11, #-0x884] */
/* @0xe70b0 add r1, pc, r1 */
/* @0xe70b4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe70b8 b 0xe66f8 <_Z5DoPopjPhPKhP6VMExec+0x114> */
/* @0xe70bc ldr r5, [r5, #0xc] */
/* @0xe70c0 cmp r5, #0 */
/* @0xe70c4 bne 0xe6e9c <_Z5DoPopjPhPKhP6VMExec+0x8b8> */
/* @0xe70c8 b 0xe677c <_Z5DoPopjPhPKhP6VMExec+0x198> */
/* @0xe70cc ldr r12, [r11, #-0x884] */
/* @0xe70d0 mov r1, r9 */
/* @0xe70d4 mov r2, r10 */
/* @0xe70d8 mov r5, r4 */
/* @0xe70dc sub r4, r11, #2080 */
/* @0xe70e0 ldr r0, [r12, #0x34] */
/* @0xe70e4 sub r4, r4, #4 */
/* @0xe70e8 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xe70ec sub r4, r4, #4 */
/* @0xe70f0 ldr r2, [pc, #0x51c] */
/* @0xe70f4 mov r1, #2048 */
/* @0xe70f8 add r2, pc, r2 */
/* @0xe70fc mov r3, r0 */
/* @0xe7100 mov r0, r4 */
/* @0xe7104 bl 0xb65c8 <snprintf@plt> */
/* @0xe7108 mov r0, r4 */
/* @0xe710c mov r3, #0 */
/* @0xe7110 strb r3, [r11, #-0x29] */
/* @0xe7114 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe7118 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe711c sub r12, r11, #2144 */
/* @0xe7120 ldr r0, [r4] */
/* @0xe7124 ldr r1, [r4, #0x4] */
/* @0xe7128 sub r12, r12, #4 */
/* @0xe712c ldr r2, [r4, #0x8] */
/* @0xe7130 sub r12, r12, #4 */
/* @0xe7134 ldr r3, [r4, #0xc] */
/* @0xe7138 add r4, r4, #16 */
/* @0xe713c stm r12!, {r0, r1, r2, r3} */
/* @0xe7140 b 0xe66f0 <_Z5DoPopjPhPKhP6VMExec+0x10c> */
/* @0xe7144 sub r3, r11, #2144 */
/* @0xe7148 sub r12, r11, #2128 */
/* @0xe714c sub r3, r3, #4 */
/* @0xe7150 sub r12, r12, #4 */
/* @0xe7154 sub r3, r3, #4 */
/* @0xe7158 str r3, [r11, #-0x888] */
/* @0xe715c ldr r0, [r4] */
/* @0xe7160 sub r12, r12, #4 */
/* @0xe7164 ldr r1, [r4, #0x4] */
/* @0xe7168 ldr r2, [r4, #0x8] */
/* @0xe716c ldr r3, [r4, #0xc] */
/* @0xe7170 str r12, [r11, #-0x894] */
/* @0xe7174 ldr r12, [r11, #-0x888] */
/* @0xe7178 str r4, [r11, #-0x890] */
/* @0xe717c add r4, r4, #32 */
/* @0xe7180 stm r12!, {r0, r1, r2, r3} */
/* @0xe7184 ldr r12, [r11, #-0x890] */
/* @0xe7188 ldr r0, [r12, #0x10]! */
/* @0xe718c ldr r1, [r12, #0x4] */
/* @0xe7190 ldr r2, [r12, #0x8] */
/* @0xe7194 ldr r3, [r12, #0xc] */
/* @0xe7198 ldr r12, [r11, #-0x894] */
/* @0xe719c stm r12!, {r0, r1, r2, r3} */
/* @0xe71a0 b 0xe66f0 <_Z5DoPopjPhPKhP6VMExec+0x10c> */
/* @0xe71a4 cmn r3, #1 */
/* @0xe71a8 beq 0xe6da0 <_Z5DoPopjPhPKhP6VMExec+0x7bc> */
/* @0xe71ac add r3, lr, r3 */
/* @0xe71b0 add r5, r5, r3, lsl #2 */
/* @0xe71b4 adds r2, r5, #4 */
/* @0xe71b8 beq 0xe6ce4 <_Z5DoPopjPhPKhP6VMExec+0x700> */
/* @0xe71bc ldr r3, [r5, #0x4] */
/* @0xe71c0 cmp r3, #0 */
/* @0xe71c4 beq 0xe6cc8 <_Z5DoPopjPhPKhP6VMExec+0x6e4> */
/* @0xe71c8 ldr r1, [r3, #0xc] */
/* @0xe71cc bic r1, r1, #-16777216 */
/* @0xe71d0 cmp r1, #6 */
/* @0xe71d4 bne 0xe6cc8 <_Z5DoPopjPhPKhP6VMExec+0x6e4> */
/* @0xe71d8 ldr r1, [r3] */
/* @0xe71dc ldr r12, [r11, #-0x894] */
/* @0xe71e0 ldr r1, [r1, #0x48] */
/* @0xe71e4 cmp r1, #2 */
/* @0xe71e8 moveq r12, r3 */
/* @0xe71ec str r12, [r11, #-0x894] */
/* @0xe71f0 b 0xe6cc8 <_Z5DoPopjPhPKhP6VMExec+0x6e4> */
/* @0xe71f4 ldr r3, [r11, #-0x894] */
/* @0xe71f8 ldr r10, [r11, #-0x8a0] */
/* @0xe71fc cmp r3, #0 */
/* @0xe7200 beq 0xe7bc8 <_Z5DoPopjPhPKhP6VMExec+0x15e4> */
/* @0xe7204 ldr r12, [r11, #-0x894] */
/* @0xe7208 ldr r3, [r12, #0xc] */
/* @0xe720c bic r3, r3, #-16777216 */
/* @0xe7210 cmp r3, #6 */
/* @0xe7214 beq 0xe787c <_Z5DoPopjPhPKhP6VMExec+0x1298> */
/* @0xe7218 ldr r0, [pc, #0x3f8] */
/* @0xe721c mvn r1, #8 */
/* @0xe7220 mov r2, r10 */
/* @0xe7224 add r0, pc, r0 */
/* @0xe7228 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xe722c ldr r3, [r11, #-0x890] */
/* @0xe7230 ldr r12, [r11, #-0x894] */
/* @0xe7234 cmp r3, #0 */
/* @0xe7238 ldr r5, [r12, #0x8] */
/* @0xe723c ldr r3, [r12, #0xc] */
/* @0xe7240 bne 0xe74dc <_Z5DoPopjPhPKhP6VMExec+0xef8> */
/* @0xe7244 mvn r6, #-16777216 */
/* @0xe7248 subs r2, r3, r6 */
/* @0xe724c rsbs r6, r2, #0 */
/* @0xe7250 adcs r6, r6, r2 */
/* @0xe7254 mov r1, r0 */
/* @0xe7258 ldr r0, [r11, #-0x89c] */
/* @0xe725c bl 0x241cac <_Z9JS_CanPutP12YYObjectBasePKc> */
/* @0xe7260 cmp r0, #0 */
/* @0xe7264 beq 0xe728c <_Z5DoPopjPhPKhP6VMExec+0xca8> */
/* @0xe7268 cmp r6, #0 */
/* @0xe726c beq 0xe7a0c <_Z5DoPopjPhPKhP6VMExec+0x1428> */
/* @0xe7270 ldr r0, [r11, #-0x89c] */
/* @0xe7274 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0xe7278 cmp r0, #0 */
/* @0xe727c bne 0xe7a14 <_Z5DoPopjPhPKhP6VMExec+0x1430> */
/* @0xe7280 ldr r12, [r11, #-0x894] */
/* @0xe7284 mov r3, #5 */
/* @0xe7288 str r3, [r12, #0xc] */
/* @0xe728c ldr r3, [r8, #0xc] */
/* @0xe7290 sub r3, r3, #1 */
/* @0xe7294 bic r3, r3, #-16777216 */
/* @0xe7298 bic r3, r3, #3 */
/* @0xe729c cmp r3, #0 */
/* @0xe72a0 bne 0xe72ac <_Z5DoPopjPhPKhP6VMExec+0xcc8> */
/* @0xe72a4 mov r0, r8 */
/* @0xe72a8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe72ac mov r5, r4 */
/* @0xe72b0 mov r3, #0 */
/* @0xe72b4 mov r2, #5 */
/* @0xe72b8 str r3, [r8, #0x8] */
/* @0xe72bc str r3, [r8] */
/* @0xe72c0 str r2, [r8, #0xc] */
/* @0xe72c4 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xe72c8 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe72cc cmp r3, #0 */
/* @0xe72d0 beq 0xe7ca8 <_Z5DoPopjPhPKhP6VMExec+0x16c4> */
/* @0xe72d4 add r0, r3, r1, lsl #4 */
/* @0xe72d8 mov r1, r8 */
/* @0xe72dc ldr r2, [r11, #-0x88c] */
/* @0xe72e0 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0xe72e4 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xe72e8 ldr r12, [r11, #-0x888] */
/* @0xe72ec ldrb r3, [r12] */
/* @0xe72f0 b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe72f4 ubfx r3, r10, #0x8, #0x8 */
/* @0xe72f8 uxtb r6, r10 */
/* @0xe72fc cmp r3, #0 */
/* @0xe7300 bne 0xe7640 <_Z5DoPopjPhPKhP6VMExec+0x105c> */
/* @0xe7304 ldr r3, [pc, #0x310] */
/* @0xe7308 ldr r3, [r7, r3] */
/* @0xe730c ldr r5, [r3] */
/* @0xe7310 add r1, r5, r6, lsl #4 */
/* @0xe7314 ldr r3, [r1, #0xc] */
/* @0xe7318 bic r2, r3, #-16777216 */
/* @0xe731c cmp r2, #1 */
/* @0xe7320 beq 0xe79dc <_Z5DoPopjPhPKhP6VMExec+0x13f8> */
/* @0xe7324 cmp r2, #2 */
/* @0xe7328 bne 0xe7360 <_Z5DoPopjPhPKhP6VMExec+0xd7c> */
/* @0xe732c sub r3, r3, #1 */
/* @0xe7330 bic r3, r3, #-16777216 */
/* @0xe7334 bic r3, r3, #3 */
/* @0xe7338 cmp r3, #0 */
/* @0xe733c bne 0xe7350 <_Z5DoPopjPhPKhP6VMExec+0xd6c> */
/* @0xe7340 mov r0, r1 */
/* @0xe7344 str r1, [r11, #-0x8a4] */
/* @0xe7348 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe734c ldr r1, [r11, #-0x8a4] */
/* @0xe7350 mov r3, #0 */
/* @0xe7354 str r3, [r1, #0x8] */
/* @0xe7358 mov r3, #5 */
/* @0xe735c str r3, [r1, #0xc] */
/* @0xe7360 ldr r3, [r8, #0xc] */
/* @0xe7364 mov r2, #0 */
/* @0xe7368 str r2, [r5, r6, lsl #4] */
/* @0xe736c ldr r2, [r8, #0x8] */
/* @0xe7370 str r3, [r1, #0xc] */
/* @0xe7374 ldr r3, [r8, #0xc] */
/* @0xe7378 str r2, [r1, #0x8] */
/* @0xe737c bic r3, r3, #-16777216 */
/* @0xe7380 cmp r3, #14 */
/* @0xe7384 addls pc, pc, r3, lsl #2 */
/* @0xe7388 b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe738c b 0xe73dc <_Z5DoPopjPhPKhP6VMExec+0xdf8> */
/* @0xe7390 b 0xe7458 <_Z5DoPopjPhPKhP6VMExec+0xe74> */
/* @0xe7394 b 0xe7420 <_Z5DoPopjPhPKhP6VMExec+0xe3c> */
/* @0xe7398 b 0xe73c8 <_Z5DoPopjPhPKhP6VMExec+0xde4> */
/* @0xe739c b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe73a0 b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe73a4 b 0xe73f4 <_Z5DoPopjPhPKhP6VMExec+0xe10> */
/* @0xe73a8 b 0xe73c8 <_Z5DoPopjPhPKhP6VMExec+0xde4> */
/* @0xe73ac b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe73b0 b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe73b4 b 0xe73dc <_Z5DoPopjPhPKhP6VMExec+0xdf8> */
/* @0xe73b8 b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe73bc b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe73c0 b 0xe73dc <_Z5DoPopjPhPKhP6VMExec+0xdf8> */
/* @0xe73c4 b 0xe73c8 <_Z5DoPopjPhPKhP6VMExec+0xde4> */
/* @0xe73c8 ldr r3, [r8] */
/* @0xe73cc str r3, [r5, r6, lsl #4] */
/* @0xe73d0 ldr r12, [r11, #-0x888] */
/* @0xe73d4 ldrb r3, [r12] */
/* @0xe73d8 b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe73dc ldm r8, {r2, r3} */
/* @0xe73e0 str r2, [r5, r6, lsl #4] */
/* @0xe73e4 str r3, [r1, #0x4] */
/* @0xe73e8 ldr r12, [r11, #-0x888] */
/* @0xe73ec ldrb r3, [r12] */
/* @0xe73f0 b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe73f4 ldr r3, [r8] */
/* @0xe73f8 str r3, [r5, r6, lsl #4] */
/* @0xe73fc ldr r3, [r8] */
/* @0xe7400 cmp r3, #0 */
/* @0xe7404 beq 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe7408 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe740c ldr r1, [r8] */
/* @0xe7410 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe7414 ldr r12, [r11, #-0x888] */
/* @0xe7418 ldrb r3, [r12] */
/* @0xe741c b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe7420 ldr r3, [r8] */
/* @0xe7424 cmp r3, #0 */
/* @0xe7428 str r3, [r5, r6, lsl #4] */
/* @0xe742c beq 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe7430 ldr r0, [r3, #0x8] */
/* @0xe7434 ldr r2, [r3] */
/* @0xe7438 cmp r0, #0 */
/* @0xe743c streq r1, [r3, #0x8] */
/* @0xe7440 add r2, r2, #1 */
/* @0xe7444 str r2, [r3] */
/* @0xe7448 ldreq r12, [r11, #-0x888] */
/* @0xe744c ldrbeq r3, [r12] */
/* @0xe7450 bne 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe7454 b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe7458 ldr r0, [r8] */
/* @0xe745c bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */
/* @0xe7460 ldr r12, [r11, #-0x888] */
/* @0xe7464 str r0, [r5, r6, lsl #4] */
/* @0xe7468 ldrb r3, [r12] */
/* @0xe746c b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe7470 mov r2, r8 */
/* @0xe7474 bl 0x1f35e0 <_Z21Variable_Scope_SetVariiP6RValue> */
/* @0xe7478 ldr r12, [r11, #-0x888] */
/* @0xe747c ldrb r3, [r12] */
/* @0xe7480 b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe7484 ldr r3, [pc, #0x174] */
/* @0xe7488 ldr r3, [r7, r3] */
/* @0xe748c ldrb r6, [r3] */
/* @0xe7490 cmp r6, #0 */
/* @0xe7494 beq 0xe7954 <_Z5DoPopjPhPKhP6VMExec+0x1370> */
/* @0xe7498 ldr r3, [r11, #-0x890] */
/* @0xe749c cmp r3, #0 */
/* @0xe74a0 beq 0xe6800 <_Z5DoPopjPhPKhP6VMExec+0x21c> */
/* @0xe74a4 mov r3, #0 */
/* @0xe74a8 sub r5, r4, #16 */
/* @0xe74ac str r3, [r4, #-0x4] */
/* @0xe74b0 str r3, [r4, #-0x10] */
/* @0xe74b4 str r3, [r4, #-0xc] */
/* @0xe74b8 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe74bc ldr r3, [r11, #-0x868] */
/* @0xe74c0 str r3, [r11, #-0x89c] */
/* @0xe74c4 b 0xe6be0 <_Z5DoPopjPhPKhP6VMExec+0x5fc> */
/* @0xe74c8 ldr r0, [pc, #0x150] */
/* @0xe74cc mvn r1, #8 */
/* @0xe74d0 mov r2, r10 */
/* @0xe74d4 add r0, pc, r0 */
/* @0xe74d8 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xe74dc ldr r0, [pc, #0x140] */
/* @0xe74e0 mov r2, r10 */
/* @0xe74e4 mvn r1, #8 */
/* @0xe74e8 sub r5, r4, #16 */
/* @0xe74ec add r0, pc, r0 */
/* @0xe74f0 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xe74f4 ldr r3, [r11, #-0x89c] */
/* @0xe74f8 mov r1, r5 */
/* @0xe74fc ldr r12, [r3, #0x50] */
/* @0xe7500 mov r2, r0 */
/* @0xe7504 mov r0, r3 */
/* @0xe7508 mov r3, #0 */
/* @0xe750c blx r12 */
/* @0xe7510 b 0xe72c4 <_Z5DoPopjPhPKhP6VMExec+0xce0> */
/* @0xe7514 ldr r3, [r11, #-0x890] */
/* @0xe7518 cmp r3, #0 */
/* @0xe751c beq 0xe6800 <_Z5DoPopjPhPKhP6VMExec+0x21c> */
/* @0xe7520 mov r3, #13 */
/* @0xe7524 str r6, [r4, #-0x10] */
/* @0xe7528 str r6, [r4, #-0xc] */
/* @0xe752c sub r5, r4, #16 */
/* @0xe7530 str r3, [r4, #-0x4] */
/* @0xe7534 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe7538 sub r5, r11, #2144 */
/* @0xe753c sub r2, r2, #1 */
/* @0xe7540 sub r5, r5, #4 */
/* @0xe7544 bic r12, r2, #-16777216 */
/* @0xe7548 sub r5, r5, #4 */
/* @0xe754c bic r12, r12, #3 */
/* @0xe7550 cmp r12, #0 */
/* @0xe7554 sub r12, r11, #2096 */
/* @0xe7558 ldm r5, {r0, r1, r2, r3} */
/* @0xe755c sub r12, r12, #4 */
/* @0xe7560 sub r12, r12, #4 */
/* @0xe7564 stm r12, {r0, r1, r2, r3} */
/* @0xe7568 beq 0xe79d0 <_Z5DoPopjPhPKhP6VMExec+0x13ec> */
/* @0xe756c ldr r12, [r11, #-0x858] */
/* @0xe7570 mov r0, r5 */
/* @0xe7574 ldr r2, [r11, #-0x854] */
/* @0xe7578 mov r1, r8 */
/* @0xe757c mov r3, #0 */
/* @0xe7580 str r3, [r11, #-0x830] */
/* @0xe7584 vmov s14, r12 */
/* @0xe7588 str r3, [r11, #-0x838] */
/* @0xe758c vmov s15, r2 */
/* @0xe7590 mov r12, #5 */
/* @0xe7594 str r12, [r11, #-0x82c] */
/* @0xe7598 vcvt.s32.f64 s13, d7 */
/* @0xe759c vmov r2, s13 */
/* @0xe75a0 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0xe75a4 ldr r12, [r11, #-0x888] */
/* @0xe75a8 ldrb r3, [r12] */
/* @0xe75ac b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe75b0 cmn r3, #1 */
/* @0xe75b4 beq 0xe6cb8 <_Z5DoPopjPhPKhP6VMExec+0x6d4> */
/* @0xe75b8 add r3, r12, r3 */
/* @0xe75bc add r3, r6, r3, lsl #2 */
/* @0xe75c0 adds r2, r3, #4 */
/* @0xe75c4 streq r2, [r11, #-0x894] */
/* @0xe75c8 ldrne r3, [r3, #0x4] */
/* @0xe75cc strne r3, [r11, #-0x894] */
/* @0xe75d0 b 0xe6cc0 <_Z5DoPopjPhPKhP6VMExec+0x6dc> */
/* @0xe75d4 eorseq r11, r0, r0, asr r6 */
/* @0xe75d8 .word 0xffffbd00 */
/* @0xe75dc eoreq lr, r4, r8, ror r1 */
/* @0xe75e0 .word 0xffffbf68 */
/* @0xe75e4 .word 0xffffbf24 */
/* @0xe75e8 .word 0xffffbf30 */
/* @0xe75ec .word 0xffffbf28 */
/* @0xe75f0 .word 0xffffbf2c */
/* @0xe75f4 .word 0xffffbf34 */
/* @0xe75f8 eoreq sp, r4, r0, lsr pc */
/* @0xe75fc eoreq sp, r4, r8, lsl #27 */
/* @0xe7600 .word 0xffffc0fc */
/* @0xe7604 eoreq sp, r4, r0, asr r8 */
/* @0xe7608 eoreq sp, r4, r0, ror #10 */
/* @0xe760c eoreq sp, r4, r12, asr #12 */
/* @0xe7610 eoreq sp, r4, r0, lsl r5 */
/* @0xe7614 eoreq sp, r4, r0, ror #9 */
/* @0xe7618 eoreq r7, r4, r2, lsl r9 */
/* @0xe761c .word 0xffffc0c0 */
/* @0xe7620 eoreq r7, r4, r2, ror #12 */
/* @0xe7624 eoreq r7, r4, r10, asr #12 */
/* @0xe7628 eoreq r7, r4, lr, lsl #5 */
/* @0xe762c eoreq r12, r4, r12, ror #24 */
/* @0xe7630 eoreq r12, r4, r12, ror #27 */
/* @0xe7634 eoreq r6, r4, r2, ror #30 */
/* @0xe7638 eoreq r12, r4, r12, lsl #20 */
/* @0xe763c eoreq r12, r4, r12, lsl #18 */
/* @0xe7640 ldr r12, [r11, #-0x884] */
/* @0xe7644 ldr r5, [r12, #0x10] */
/* @0xe7648 cmp r5, #0 */
/* @0xe764c beq 0xe7c84 <_Z5DoPopjPhPKhP6VMExec+0x16a0> */
/* @0xe7650 mov r2, r3 */
/* @0xe7654 subs r2, r2, #1 */
/* @0xe7658 ldr r5, [r5, #0xc] */
/* @0xe765c moveq r1, #0 */
/* @0xe7660 movne r1, #1 */
/* @0xe7664 cmp r5, #0 */
/* @0xe7668 moveq r1, #0 */
/* @0xe766c andne r1, r1, #1 */
/* @0xe7670 cmp r1, #0 */
/* @0xe7674 bne 0xe7654 <_Z5DoPopjPhPKhP6VMExec+0x1070> */
/* @0xe7678 cmp r5, #0 */
/* @0xe767c beq 0xe7c84 <_Z5DoPopjPhPKhP6VMExec+0x16a0> */
/* @0xe7680 ldr r1, [r5, #0x4] */
/* @0xe7684 cmp r1, #0 */
/* @0xe7688 beq 0xe7c74 <_Z5DoPopjPhPKhP6VMExec+0x1690> */
/* @0xe768c ldr r0, [r1] */
/* @0xe7690 ldr r3, [r0, #0x4] */
/* @0xe7694 cmp r3, #0 */
/* @0xe7698 beq 0xe7cdc <_Z5DoPopjPhPKhP6VMExec+0x16f8> */
/* @0xe769c add r0, r3, #16 */
/* @0xe76a0 ldr r0, [r0] */
/* @0xe76a4 ldr r3, [r0, #0x4] */
/* @0xe76a8 cmp r3, #0 */
/* @0xe76ac beq 0xe7ccc <_Z5DoPopjPhPKhP6VMExec+0x16e8> */
/* @0xe76b0 add r6, r3, r6, lsl #4 */
/* @0xe76b4 ldr r3, [r6, #0xc] */
/* @0xe76b8 bic r2, r3, #-16777216 */
/* @0xe76bc cmp r2, #1 */
/* @0xe76c0 beq 0xe79c0 <_Z5DoPopjPhPKhP6VMExec+0x13dc> */
/* @0xe76c4 cmp r2, #2 */
/* @0xe76c8 bne 0xe76f8 <_Z5DoPopjPhPKhP6VMExec+0x1114> */
/* @0xe76cc sub r3, r3, #1 */
/* @0xe76d0 bic r3, r3, #-16777216 */
/* @0xe76d4 bic r3, r3, #3 */
/* @0xe76d8 cmp r3, #0 */
/* @0xe76dc bne 0xe76e8 <_Z5DoPopjPhPKhP6VMExec+0x1104> */
/* @0xe76e0 mov r0, r6 */
/* @0xe76e4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe76e8 mov r2, #0 */
/* @0xe76ec mov r3, #5 */
/* @0xe76f0 str r2, [r6, #0x8] */
/* @0xe76f4 str r3, [r6, #0xc] */
/* @0xe76f8 ldr r3, [r8, #0xc] */
/* @0xe76fc mov r1, #0 */
/* @0xe7700 ldr r2, [r8, #0x8] */
/* @0xe7704 str r1, [r6] */
/* @0xe7708 str r3, [r6, #0xc] */
/* @0xe770c ldr r3, [r8, #0xc] */
/* @0xe7710 str r2, [r6, #0x8] */
/* @0xe7714 bic r3, r3, #-16777216 */
/* @0xe7718 cmp r3, #14 */
/* @0xe771c addls pc, pc, r3, lsl #2 */
/* @0xe7720 b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe7724 b 0xe7774 <_Z5DoPopjPhPKhP6VMExec+0x1190> */
/* @0xe7728 b 0xe77d8 <_Z5DoPopjPhPKhP6VMExec+0x11f4> */
/* @0xe772c b 0xe77a0 <_Z5DoPopjPhPKhP6VMExec+0x11bc> */
/* @0xe7730 b 0xe7760 <_Z5DoPopjPhPKhP6VMExec+0x117c> */
/* @0xe7734 b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe7738 b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe773c b 0xe7788 <_Z5DoPopjPhPKhP6VMExec+0x11a4> */
/* @0xe7740 b 0xe7760 <_Z5DoPopjPhPKhP6VMExec+0x117c> */
/* @0xe7744 b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe7748 b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe774c b 0xe7774 <_Z5DoPopjPhPKhP6VMExec+0x1190> */
/* @0xe7750 b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe7754 b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe7758 b 0xe7774 <_Z5DoPopjPhPKhP6VMExec+0x1190> */
/* @0xe775c b 0xe7760 <_Z5DoPopjPhPKhP6VMExec+0x117c> */
/* @0xe7760 ldr r3, [r8] */
/* @0xe7764 str r3, [r6] */
/* @0xe7768 ldr r12, [r11, #-0x888] */
/* @0xe776c ldrb r3, [r12] */
/* @0xe7770 b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe7774 ldm r8, {r2, r3} */
/* @0xe7778 stm r6, {r2, r3} */
/* @0xe777c ldr r12, [r11, #-0x888] */
/* @0xe7780 ldrb r3, [r12] */
/* @0xe7784 b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe7788 ldr r3, [r8] */
/* @0xe778c str r3, [r6] */
/* @0xe7790 ldr r3, [r8] */
/* @0xe7794 cmp r3, #0 */
/* @0xe7798 bne 0xe7408 <_Z5DoPopjPhPKhP6VMExec+0xe24> */
/* @0xe779c b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe77a0 ldr r3, [r8] */
/* @0xe77a4 cmp r3, #0 */
/* @0xe77a8 str r3, [r6] */
/* @0xe77ac beq 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe77b0 ldr r1, [r3, #0x8] */
/* @0xe77b4 ldr r2, [r3] */
/* @0xe77b8 cmp r1, #0 */
/* @0xe77bc streq r6, [r3, #0x8] */
/* @0xe77c0 add r2, r2, #1 */
/* @0xe77c4 str r2, [r3] */
/* @0xe77c8 ldreq r12, [r11, #-0x888] */
/* @0xe77cc ldrbeq r3, [r12] */
/* @0xe77d0 bne 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe77d4 b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe77d8 ldr r0, [r8] */
/* @0xe77dc bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */
/* @0xe77e0 ldr r12, [r11, #-0x888] */
/* @0xe77e4 str r0, [r6] */
/* @0xe77e8 ldrb r3, [r12] */
/* @0xe77ec b 0xe6774 <_Z5DoPopjPhPKhP6VMExec+0x190> */
/* @0xe77f0 mov r0, r5 */
/* @0xe77f4 mov r1, r6 */
/* @0xe77f8 str r3, [r11, #-0x8a4] */
/* @0xe77fc str r12, [r11, #-0x8a8] */
/* @0xe7800 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe7804 ldr r12, [r11, #-0x8a8] */
/* @0xe7808 ldr r3, [r11, #-0x8a4] */
/* @0xe780c b 0xe6ec0 <_Z5DoPopjPhPKhP6VMExec+0x8dc> */
/* @0xe7810 mov r0, r5 */
/* @0xe7814 mov r1, r6 */
/* @0xe7818 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe781c b 0xe6efc <_Z5DoPopjPhPKhP6VMExec+0x918> */
/* @0xe7820 ldr r0, [r5, #0x4] */
/* @0xe7824 mov r3, #13 */
/* @0xe7828 sub r7, r4, #16 */
/* @0xe782c str r3, [r4, #-0x4] */
/* @0xe7830 cmp r0, #0 */
/* @0xe7834 beq 0xe7d0c <_Z5DoPopjPhPKhP6VMExec+0x1728> */
/* @0xe7838 add r0, r0, r12 */
/* @0xe783c ldr r3, [r0, #0x8] */
/* @0xe7840 ands r3, r3, #2 */
/* @0xe7844 bne 0xe7b70 <_Z5DoPopjPhPKhP6VMExec+0x158c> */
/* @0xe7848 str r3, [r4, #-0x10] */
/* @0xe784c mov r5, r7 */
/* @0xe7850 str r3, [r4, #-0xc] */
/* @0xe7854 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe7858 ldr r3, [r11, #-0x890] */
/* @0xe785c cmp r3, #0 */
/* @0xe7860 beq 0xe6800 <_Z5DoPopjPhPKhP6VMExec+0x21c> */
/* @0xe7864 str r5, [r4, #-0x10] */
/* @0xe7868 mov r3, #13 */
/* @0xe786c str r5, [r4, #-0xc] */
/* @0xe7870 sub r5, r4, #16 */
/* @0xe7874 str r3, [r4, #-0x4] */
/* @0xe7878 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe787c ldr r12, [r11, #-0x890] */
/* @0xe7880 cmp r12, #0 */
/* @0xe7884 bne 0xe74c8 <_Z5DoPopjPhPKhP6VMExec+0xee4> */
/* @0xe7888 ldr r0, [r11, #-0x894] */
/* @0xe788c ldr r12, [r0] */
/* @0xe7890 ldr r2, [r12, #0x48] */
/* @0xe7894 cmp r2, #2 */
/* @0xe7898 beq 0xe7ce8 <_Z5DoPopjPhPKhP6VMExec+0x1704> */
/* @0xe789c ldr r0, [pc, #-0x27c] */
/* @0xe78a0 mvn r1, #8 */
/* @0xe78a4 mov r2, r10 */
/* @0xe78a8 add r0, pc, r0 */
/* @0xe78ac bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xe78b0 ldr r12, [r11, #-0x894] */
/* @0xe78b4 mvn r3, #-16777216 */
/* @0xe78b8 ldr r6, [r12, #0xc] */
/* @0xe78bc ldr r5, [r12, #0x8] */
/* @0xe78c0 subs r3, r6, r3 */
/* @0xe78c4 rsbs r6, r3, #0 */
/* @0xe78c8 adcs r6, r6, r3 */
/* @0xe78cc b 0xe7254 <_Z5DoPopjPhPKhP6VMExec+0xc70> */
/* @0xe78d0 sub r5, r11, #2112 */
/* @0xe78d4 sub r1, r11, #2128 */
/* @0xe78d8 sub r5, r5, #4 */
/* @0xe78dc sub r1, r1, #4 */
/* @0xe78e0 sub r5, r5, #4 */
/* @0xe78e4 sub r1, r1, #4 */
/* @0xe78e8 mov r0, r5 */
/* @0xe78ec bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0xe78f0 cmp r0, #1 */
/* @0xe78f4 mov r3, r0 */
/* @0xe78f8 beq 0xe7d24 <_Z5DoPopjPhPKhP6VMExec+0x1740> */
/* @0xe78fc cmp r0, #0 */
/* @0xe7900 bne 0xe6648 <_Z5DoPopjPhPKhP6VMExec+0x64> */
/* @0xe7904 ldr r12, [r11, #-0x890] */
/* @0xe7908 cmp r12, #0 */
/* @0xe790c beq 0xe7bf0 <_Z5DoPopjPhPKhP6VMExec+0x160c> */
/* @0xe7910 ldr r0, [r11, #-0x868] */
/* @0xe7914 sub r4, r4, #16 */
/* @0xe7918 ldr r2, [r11, #-0x848] */
/* @0xe791c mov r1, r4 */
/* @0xe7920 ldr r12, [r0, #0x50] */
/* @0xe7924 ldr r2, [r2] */
/* @0xe7928 blx r12 */
/* @0xe792c ldr r3, [r11, #-0x83c] */
/* @0xe7930 sub r3, r3, #1 */
/* @0xe7934 bic r3, r3, #-16777216 */
/* @0xe7938 bic r3, r3, #3 */
/* @0xe793c cmp r3, #0 */
/* @0xe7940 bne 0xe6648 <_Z5DoPopjPhPKhP6VMExec+0x64> */
/* @0xe7944 mov r0, r5 */
/* @0xe7948 mov r5, r4 */
/* @0xe794c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe7950 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe7954 ldr r12, [r11, #-0x884] */
/* @0xe7958 mov r2, r10 */
/* @0xe795c mvn r1, #8 */
/* @0xe7960 mov r5, r4 */
/* @0xe7964 ldr r0, [r12, #0x34] */
/* @0xe7968 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xe796c mov r1, r10 */
/* @0xe7970 mov r4, r0 */
/* @0xe7974 mvn r0, #8 */
/* @0xe7978 bl 0x1f3f8c <_Z22Variable_GetObjectNameii> */
/* @0xe797c str r4, [sp] */
/* @0xe7980 sub r4, r11, #2080 */
/* @0xe7984 ldr r12, [r11, #-0x88c] */
/* @0xe7988 sub r4, r4, #4 */
/* @0xe798c ldr r2, [pc, #-0x368] */
/* @0xe7990 sub r4, r4, #4 */
/* @0xe7994 str r10, [sp, #0x4] */
/* @0xe7998 mov r1, #2048 */
/* @0xe799c str r12, [sp, #0x8] */
/* @0xe79a0 add r2, pc, r2 */
/* @0xe79a4 mov r3, r0 */
/* @0xe79a8 mov r0, r4 */
/* @0xe79ac bl 0xb65c8 <snprintf@plt> */
/* @0xe79b0 mov r0, r4 */
/* @0xe79b4 strb r6, [r11, #-0x29] */
/* @0xe79b8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe79bc b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe79c0 ldr r0, [r6] */
/* @0xe79c4 bl 0xdc42c <_ZN9_RefThingIPKcE6removeEPS2_> */
/* @0xe79c8 str r0, [r6] */
/* @0xe79cc b 0xe76f8 <_Z5DoPopjPhPKhP6VMExec+0x1114> */
/* @0xe79d0 mov r0, r12 */
/* @0xe79d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe79d8 b 0xe756c <_Z5DoPopjPhPKhP6VMExec+0xf88> */
/* @0xe79dc ldr r0, [r5, r6, lsl #4] */
/* @0xe79e0 str r1, [r11, #-0x8a4] */
/* @0xe79e4 bl 0xdc42c <_ZN9_RefThingIPKcE6removeEPS2_> */
/* @0xe79e8 str r0, [r5, r6, lsl #4] */
/* @0xe79ec ldr r1, [r11, #-0x8a4] */
/* @0xe79f0 b 0xe7360 <_Z5DoPopjPhPKhP6VMExec+0xd7c> */
/* @0xe79f4 ldr r0, [pc, #-0x3cc] */
/* @0xe79f8 mov r5, r4 */
/* @0xe79fc add r0, pc, r0 */
/* @0xe7a00 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe7a04 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe7a08 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xe7a0c tst r5, #4 */
/* @0xe7a10 beq 0xe728c <_Z5DoPopjPhPKhP6VMExec+0xca8> */
/* @0xe7a14 ldr r3, [r11, #-0x894] */
/* @0xe7a18 ldr r2, [r3, #0xc] */
/* @0xe7a1c bic r3, r2, #-16777216 */
/* @0xe7a20 cmp r3, #1 */
/* @0xe7a24 beq 0xe7cb4 <_Z5DoPopjPhPKhP6VMExec+0x16d0> */
/* @0xe7a28 cmp r3, #2 */
/* @0xe7a2c bne 0xe7a60 <_Z5DoPopjPhPKhP6VMExec+0x147c> */
/* @0xe7a30 sub r3, r2, #1 */
/* @0xe7a34 bic r3, r3, #-16777216 */
/* @0xe7a38 bic r3, r3, #3 */
/* @0xe7a3c cmp r3, #0 */
/* @0xe7a40 bne 0xe7a4c <_Z5DoPopjPhPKhP6VMExec+0x1468> */
/* @0xe7a44 ldr r0, [r11, #-0x894] */
/* @0xe7a48 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe7a4c ldr r12, [r11, #-0x894] */
/* @0xe7a50 mov r2, #0 */
/* @0xe7a54 mov r3, #5 */
/* @0xe7a58 str r2, [r12, #0x8] */
/* @0xe7a5c str r3, [r12, #0xc] */
/* @0xe7a60 ldr r3, [r8, #0xc] */
/* @0xe7a64 mov r1, #0 */
/* @0xe7a68 ldr r12, [r11, #-0x894] */
/* @0xe7a6c ldr r2, [r8, #0x8] */
/* @0xe7a70 str r3, [r12, #0xc] */
/* @0xe7a74 ldr r3, [r8, #0xc] */
/* @0xe7a78 str r1, [r12] */
/* @0xe7a7c bic r3, r3, #-16777216 */
/* @0xe7a80 str r2, [r12, #0x8] */
/* @0xe7a84 cmp r3, #14 */
/* @0xe7a88 addls pc, pc, r3, lsl #2 */
/* @0xe7a8c b 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7a90 b 0xe7af4 <_Z5DoPopjPhPKhP6VMExec+0x1510> */
/* @0xe7a94 b 0xe7b5c <_Z5DoPopjPhPKhP6VMExec+0x1578> */
/* @0xe7a98 b 0xe7b2c <_Z5DoPopjPhPKhP6VMExec+0x1548> */
/* @0xe7a9c b 0xe7acc <_Z5DoPopjPhPKhP6VMExec+0x14e8> */
/* @0xe7aa0 b 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7aa4 b 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7aa8 b 0xe7b04 <_Z5DoPopjPhPKhP6VMExec+0x1520> */
/* @0xe7aac b 0xe7acc <_Z5DoPopjPhPKhP6VMExec+0x14e8> */
/* @0xe7ab0 b 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7ab4 b 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7ab8 b 0xe7af4 <_Z5DoPopjPhPKhP6VMExec+0x1510> */
/* @0xe7abc b 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7ac0 b 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7ac4 b 0xe7af4 <_Z5DoPopjPhPKhP6VMExec+0x1510> */
/* @0xe7ac8 b 0xe7acc <_Z5DoPopjPhPKhP6VMExec+0x14e8> */
/* @0xe7acc ldr r3, [r8] */
/* @0xe7ad0 ldr r12, [r11, #-0x894] */
/* @0xe7ad4 str r3, [r12] */
/* @0xe7ad8 cmp r6, #0 */
/* @0xe7adc ldreq r3, [r11, #-0x894] */
/* @0xe7ae0 movne r3, #7 */
/* @0xe7ae4 ldrne r12, [r11, #-0x894] */
/* @0xe7ae8 streq r5, [r3, #0x8] */
/* @0xe7aec strne r3, [r12, #0x8] */
/* @0xe7af0 b 0xe72e4 <_Z5DoPopjPhPKhP6VMExec+0xd00> */
/* @0xe7af4 ldm r8, {r2, r3} */
/* @0xe7af8 ldr r12, [r11, #-0x894] */
/* @0xe7afc stm r12, {r2, r3} */
/* @0xe7b00 b 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7b04 ldr r3, [r8] */
/* @0xe7b08 ldr r12, [r11, #-0x894] */
/* @0xe7b0c str r3, [r12] */
/* @0xe7b10 ldr r3, [r8] */
/* @0xe7b14 cmp r3, #0 */
/* @0xe7b18 beq 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7b1c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe7b20 ldr r1, [r8] */
/* @0xe7b24 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe7b28 b 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7b2c ldr r3, [r8] */
/* @0xe7b30 ldr r12, [r11, #-0x894] */
/* @0xe7b34 cmp r3, #0 */
/* @0xe7b38 str r3, [r12] */
/* @0xe7b3c beq 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7b40 ldr r1, [r3, #0x8] */
/* @0xe7b44 ldr r2, [r3] */
/* @0xe7b48 cmp r1, #0 */
/* @0xe7b4c streq r12, [r3, #0x8] */
/* @0xe7b50 add r2, r2, #1 */
/* @0xe7b54 str r2, [r3] */
/* @0xe7b58 b 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7b5c ldr r0, [r8] */
/* @0xe7b60 bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */
/* @0xe7b64 ldr r3, [r11, #-0x894] */
/* @0xe7b68 str r0, [r3] */
/* @0xe7b6c b 0xe7ad8 <_Z5DoPopjPhPKhP6VMExec+0x14f4> */
/* @0xe7b70 mov r3, #0 */
/* @0xe7b74 mov r0, r5 */
/* @0xe7b78 mov r2, r3 */
/* @0xe7b7c movt r3, #0x3ff0 */
/* @0xe7b80 str r2, [r4, #-0x10] */
/* @0xe7b84 str r3, [r4, #-0xc] */
/* @0xe7b88 mov r3, #5 */
/* @0xe7b8c str r12, [r11, #-0x8a8] */
/* @0xe7b90 str r3, [r11, #-0x82c] */
/* @0xe7b94 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe7b98 ldr r0, [r5, #0x4] */
/* @0xe7b9c ldr r12, [r11, #-0x8a8] */
/* @0xe7ba0 cmp r0, #0 */
/* @0xe7ba4 beq 0xe7d9c <_Z5DoPopjPhPKhP6VMExec+0x17b8> */
/* @0xe7ba8 add r0, r0, r12 */
/* @0xe7bac sub r1, r11, #2096 */
/* @0xe7bb0 ldr r2, [r11, #-0x88c] */
/* @0xe7bb4 sub r1, r1, #8 */
/* @0xe7bb8 mov r5, r7 */
/* @0xe7bbc bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0xe7bc0 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xe7bc4 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe7bc8 ldr r0, [pc, #-0x59c] */
/* @0xe7bcc mvn r1, #8 */
/* @0xe7bd0 mov r2, r10 */
/* @0xe7bd4 add r0, pc, r0 */
/* @0xe7bd8 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xe7bdc mov r1, r0 */
/* @0xe7be0 ldr r0, [r11, #-0x89c] */
/* @0xe7be4 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc> */
/* @0xe7be8 str r0, [r11, #-0x894] */
/* @0xe7bec b 0xe7218 <_Z5DoPopjPhPKhP6VMExec+0xc34> */
/* @0xe7bf0 ldr r3, [r11, #-0x848] */
/* @0xe7bf4 ldr r0, [r11, #-0x868] */
/* @0xe7bf8 ldr r1, [r3] */
/* @0xe7bfc bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0xe7c00 cmn r0, #1 */
/* @0xe7c04 mov r1, r0 */
/* @0xe7c08 beq 0xe7c38 <_Z5DoPopjPhPKhP6VMExec+0x1654> */
/* @0xe7c0c ldr r0, [r11, #-0x868] */
/* @0xe7c10 ldr r3, [r0, #0x4] */
/* @0xe7c14 cmp r3, #0 */
/* @0xe7c18 beq 0xe7d88 <_Z5DoPopjPhPKhP6VMExec+0x17a4> */
/* @0xe7c1c add r0, r3, r1, lsl #4 */
/* @0xe7c20 cmp r0, #0 */
/* @0xe7c24 beq 0xe7c38 <_Z5DoPopjPhPKhP6VMExec+0x1654> */
/* @0xe7c28 ldr r3, [r0, #0xc] */
/* @0xe7c2c bic r3, r3, #-16777216 */
/* @0xe7c30 cmp r3, #6 */
/* @0xe7c34 beq 0xe7d38 <_Z5DoPopjPhPKhP6VMExec+0x1754> */
/* @0xe7c38 ldr r2, [r11, #-0x848] */
/* @0xe7c3c mov r3, #0 */
/* @0xe7c40 mov r1, r8 */
/* @0xe7c44 ldr r0, [r11, #-0x868] */
/* @0xe7c48 ldr r2, [r2] */
/* @0xe7c4c bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0xe7c50 ldr r3, [r11, #-0x83c] */
/* @0xe7c54 sub r3, r3, #1 */
/* @0xe7c58 bic r3, r3, #-16777216 */
/* @0xe7c5c bic r3, r3, #3 */
/* @0xe7c60 cmp r3, #0 */
/* @0xe7c64 bne 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe7c68 mov r0, r5 */
/* @0xe7c6c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe7c70 b 0xe676c <_Z5DoPopjPhPKhP6VMExec+0x188> */
/* @0xe7c74 mov r0, r5 */
/* @0xe7c78 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe7c7c mov r1, r0 */
/* @0xe7c80 b 0xe768c <_Z5DoPopjPhPKhP6VMExec+0x10a8> */
/* @0xe7c84 ldr r1, [pc, #-0x654] */
/* @0xe7c88 mov r2, r6 */
/* @0xe7c8c ldr r0, [r11, #-0x884] */
/* @0xe7c90 add r1, pc, r1 */
/* @0xe7c94 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe7c98 b 0xe7680 <_Z5DoPopjPhPKhP6VMExec+0x109c> */
/* @0xe7c9c mov r0, r6 */
/* @0xe7ca0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe7ca4 b 0xe6b94 <_Z5DoPopjPhPKhP6VMExec+0x5b0> */
/* @0xe7ca8 mov r0, r6 */
/* @0xe7cac bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe7cb0 b 0xe72d8 <_Z5DoPopjPhPKhP6VMExec+0xcf4> */
/* @0xe7cb4 ldr r12, [r11, #-0x894] */
/* @0xe7cb8 ldr r0, [r12] */
/* @0xe7cbc bl 0xdc42c <_ZN9_RefThingIPKcE6removeEPS2_> */
/* @0xe7cc0 ldr r3, [r11, #-0x894] */
/* @0xe7cc4 str r0, [r3] */
/* @0xe7cc8 b 0xe7a60 <_Z5DoPopjPhPKhP6VMExec+0x147c> */
/* @0xe7ccc mov r1, r6 */
/* @0xe7cd0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe7cd4 mov r6, r0 */
/* @0xe7cd8 b 0xe76b4 <_Z5DoPopjPhPKhP6VMExec+0x10d0> */
/* @0xe7cdc mov r1, #1 */
/* @0xe7ce0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe7ce4 b 0xe76a0 <_Z5DoPopjPhPKhP6VMExec+0x10bc> */
/* @0xe7ce8 sub r2, r11, #2096 */
/* @0xe7cec ldr r0, [r11, #-0x89c] */
/* @0xe7cf0 mov r1, r8 */
/* @0xe7cf4 sub r2, r2, #8 */
/* @0xe7cf8 str r3, [r11, #-0x82c] */
/* @0xe7cfc mov r5, r4 */
/* @0xe7d00 str r12, [r11, #-0x838] */
/* @0xe7d04 bl 0x24931c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_> */
/* @0xe7d08 b 0xe72c4 <_Z5DoPopjPhPKhP6VMExec+0xce0> */
/* @0xe7d0c mov r0, r5 */
/* @0xe7d10 mov r1, r6 */
/* @0xe7d14 str r12, [r11, #-0x8a8] */
/* @0xe7d18 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe7d1c ldr r12, [r11, #-0x8a8] */
/* @0xe7d20 b 0xe783c <_Z5DoPopjPhPKhP6VMExec+0x1258> */
/* @0xe7d24 ldr r0, [pc, #-0x6f0] */
/* @0xe7d28 mov r5, r4 */
/* @0xe7d2c add r0, pc, r0 */
/* @0xe7d30 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe7d34 b 0xe664c <_Z5DoPopjPhPKhP6VMExec+0x68> */
/* @0xe7d38 ldr r12, [r0] */
/* @0xe7d3c ldr r2, [r12, #0x48] */
/* @0xe7d40 cmp r2, #2 */
/* @0xe7d44 bne 0xe7c38 <_Z5DoPopjPhPKhP6VMExec+0x1654> */
/* @0xe7d48 sub r2, r11, #2096 */
/* @0xe7d4c mov r1, r8 */
/* @0xe7d50 ldr r0, [r11, #-0x868] */
/* @0xe7d54 sub r2, r2, #8 */
/* @0xe7d58 str r3, [r11, #-0x82c] */
/* @0xe7d5c str r12, [r11, #-0x838] */
/* @0xe7d60 bl 0x24931c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_> */
/* @0xe7d64 ldr r3, [r11, #-0x83c] */
/* @0xe7d68 sub r3, r3, #1 */
/* @0xe7d6c bic r3, r3, #-16777216 */
/* @0xe7d70 bic r3, r3, #3 */
/* @0xe7d74 cmp r3, #0 */
/* @0xe7d78 bne 0xe6648 <_Z5DoPopjPhPKhP6VMExec+0x64> */
/* @0xe7d7c mov r0, r5 */
/* @0xe7d80 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe7d84 b 0xe6648 <_Z5DoPopjPhPKhP6VMExec+0x64> */
/* @0xe7d88 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe7d8c b 0xe7c20 <_Z5DoPopjPhPKhP6VMExec+0x163c> */
/* @0xe7d90 mov r0, r5 */
/* @0xe7d94 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe7d98 b 0xe6fc8 <_Z5DoPopjPhPKhP6VMExec+0x9e4> */
/* @0xe7d9c mov r0, r5 */
/* @0xe7da0 mov r1, r6 */
/* @0xe7da4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe7da8 b 0xe7bac <_Z5DoPopjPhPKhP6VMExec+0x15c8> */
/* @0xe7dac ldr r2, [r0, #0xc] */
/* @0xe7db0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe7db4 sub r3, r2, #1 */
/* @0xe7db8 bic r3, r3, #-16777216 */
/* @0xe7dbc sub sp, sp, #12 */
/* @0xe7dc0 bics r4, r3, #3 */
/* @0xe7dc4 mov r5, r0 */
/* @0xe7dc8 mov r7, r1 */
