/* libyoyo.so 覆盖卡组 0017
 * 函数 0xe65e4..0xecb34，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xe65e4 · DoPop(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=6088 · insn=1522 */
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

/* ── FUNC 0xe7dac · YYCreateString(RValue*, _RefThing<char const*>*) · size=548 · insn=137 */
/* @0xe7dac ldr r2, [r0, #0xc] */
/* @0xe7db0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe7db4 sub r3, r2, #1 */
/* @0xe7db8 bic r3, r3, #-16777216 */
/* @0xe7dbc sub sp, sp, #12 */
/* @0xe7dc0 bics r4, r3, #3 */
/* @0xe7dc4 mov r5, r0 */
/* @0xe7dc8 mov r7, r1 */
/* @0xe7dcc beq 0xe7e04 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x58> */
/* @0xe7dd0 mov r3, #0 */
/* @0xe7dd4 mov r2, #1 */
/* @0xe7dd8 str r3, [r5, #0x8] */
/* @0xe7ddc mov r0, #12 */
/* @0xe7de0 str r3, [r5] */
/* @0xe7de4 str r2, [r5, #0xc] */
/* @0xe7de8 bl 0x27c524 <_Znwj> */
/* @0xe7dec mov r3, r0 */
/* @0xe7df0 ldm r7, {r0, r1, r2} */
/* @0xe7df4 stm r3, {r0, r1, r2} */
/* @0xe7df8 str r3, [r5] */
/* @0xe7dfc add sp, sp, #12 */
/* @0xe7e00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe7e04 bic r2, r2, #-16777216 */
/* @0xe7e08 cmp r2, #2 */
/* @0xe7e0c beq 0xe7e7c <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0xd0> */
/* @0xe7e10 cmp r2, #3 */
/* @0xe7e14 beq 0xe7e54 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0xa8> */
/* @0xe7e18 cmp r2, #1 */
/* @0xe7e1c bne 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24> */
/* @0xe7e20 ldr r4, [r0] */
/* @0xe7e24 cmp r4, #0 */
/* @0xe7e28 beq 0xe7e48 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x9c> */
/* @0xe7e2c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe7e30 ldr r6, [r4, #0x4] */
/* @0xe7e34 sub r6, r6, #1 */
/* @0xe7e38 str r6, [r4, #0x4] */
/* @0xe7e3c cmp r6, #0 */
/* @0xe7e40 beq 0xe7eb4 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x108> */
/* @0xe7e44 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe7e48 mov r3, #0 */
/* @0xe7e4c str r3, [r5] */
/* @0xe7e50 b 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24> */
/* @0xe7e54 ldr r3, [r0, #0x8] */
/* @0xe7e58 tst r3, #8 */
/* @0xe7e5c beq 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24> */
/* @0xe7e60 ldr r0, [r0] */
/* @0xe7e64 cmp r0, #0 */
/* @0xe7e68 beq 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24> */
/* @0xe7e6c ldr r3, [r0] */
/* @0xe7e70 ldr r3, [r3, #0x4] */
/* @0xe7e74 blx r3 */
/* @0xe7e78 b 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24> */
/* @0xe7e7c ldr r9, [r0] */
/* @0xe7e80 cmp r9, #0 */
/* @0xe7e84 beq 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24> */
/* @0xe7e88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe7e8c ldr r3, [r9] */
/* @0xe7e90 ldr r2, [r9, #0x8] */
/* @0xe7e94 sub r3, r3, #1 */
/* @0xe7e98 str r3, [r9] */
/* @0xe7e9c cmp r5, r2 */
/* @0xe7ea0 streq r4, [r9, #0x8] */
/* @0xe7ea4 cmp r3, #0 */
/* @0xe7ea8 ble 0xe7eec <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x140> */
/* @0xe7eac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe7eb0 b 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24> */
/* @0xe7eb4 ldr r0, [r4] */
/* @0xe7eb8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe7ebc str r6, [r4] */
/* @0xe7ec0 str r6, [r4, #0x8] */
/* @0xe7ec4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe7ec8 ldr r6, [r4, #0x4] */
/* @0xe7ecc sub r6, r6, #1 */
/* @0xe7ed0 str r6, [r4, #0x4] */
/* @0xe7ed4 cmp r6, #0 */
/* @0xe7ed8 beq 0xe7fac <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x200> */
/* @0xe7edc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe7ee0 mov r0, r4 */
/* @0xe7ee4 bl 0x27d1d0 <_ZdlPv> */
/* @0xe7ee8 b 0xe7e44 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x98> */
/* @0xe7eec ldr r3, [r9, #0x10] */
/* @0xe7ef0 cmp r3, #0 */
/* @0xe7ef4 movgt r8, #0 */
/* @0xe7ef8 movgt r10, #5 */
/* @0xe7efc movgt r6, r8 */
/* @0xe7f00 ble 0xe7f84 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x1d8> */
/* @0xe7f04 ldr r3, [r9, #0x4] */
/* @0xe7f08 add r2, r3, r8, lsl #3 */
/* @0xe7f0c str r2, [sp, #0x4] */
/* @0xe7f10 ldr r11, [r3, r8, lsl #3] */
/* @0xe7f14 ldr r4, [r2, #0x4] */
/* @0xe7f18 add r11, r4, r11, lsl #4 */
/* @0xe7f1c cmp r4, r11 */
/* @0xe7f20 blo 0xe7f3c <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x190> */
/* @0xe7f24 b 0xe7fa4 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x1f8> */
/* @0xe7f28 str r6, [r4, #0x8] */
/* @0xe7f2c str r10, [r4, #0xc] */
/* @0xe7f30 str r6, [r4], #16 */
/* @0xe7f34 cmp r11, r4 */
/* @0xe7f38 bls 0xe7f60 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x1b4> */
/* @0xe7f3c ldr r3, [r4, #0xc] */
/* @0xe7f40 sub r3, r3, #1 */
/* @0xe7f44 bic r3, r3, #-16777216 */
/* @0xe7f48 bic r3, r3, #3 */
/* @0xe7f4c cmp r3, #0 */
/* @0xe7f50 bne 0xe7f28 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x17c> */
/* @0xe7f54 mov r0, r4 */
/* @0xe7f58 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe7f5c b 0xe7f28 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x17c> */
/* @0xe7f60 ldr r3, [sp, #0x4] */
/* @0xe7f64 ldr r0, [r3, #0x4] */
/* @0xe7f68 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xe7f6c ldr r3, [r9, #0x10] */
/* @0xe7f70 add r8, r8, #1 */
/* @0xe7f74 ldr r2, [sp, #0x4] */
/* @0xe7f78 cmp r8, r3 */
/* @0xe7f7c str r6, [r2, #0x4] */
/* @0xe7f80 blt 0xe7f04 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x158> */
/* @0xe7f84 ldr r0, [r9, #0x4] */
/* @0xe7f88 mov r4, #0 */
/* @0xe7f8c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xe7f90 str r4, [r9, #0x4] */
/* @0xe7f94 mov r0, r9 */
/* @0xe7f98 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xe7f9c str r4, [r5] */
/* @0xe7fa0 b 0xe7eac <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x100> */
/* @0xe7fa4 mov r0, r4 */
/* @0xe7fa8 b 0xe7f68 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x1bc> */
/* @0xe7fac ldr r0, [r4] */
/* @0xe7fb0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe7fb4 mov r0, r4 */
/* @0xe7fb8 str r6, [r4] */
/* @0xe7fbc str r6, [r4, #0x8] */
/* @0xe7fc0 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xe7fc4 mov r0, r4 */
/* @0xe7fc8 bl 0x27d1d0 <_ZdlPv> */
/* @0xe7fcc b 0xe7edc <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x130> */

/* ── FUNC 0xe7fd0 · VM::Exec(CCode*, YYObjectBase*, YYObjectBase*, RValue*, YYObjectBase*, int, RValue*, int, YYObjectBase*) · size=1464 · insn=366 */
/* @0xe7fd0 ldr r12, [pc, #0x580] */
/* @0xe7fd4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe7fd8 add r12, pc, r12 */
/* @0xe7fdc mov r9, r3 */
/* @0xe7fe0 ldr r4, [pc, #0x574] */
/* @0xe7fe4 ldrb r3, [r12, #0x14] */
/* @0xe7fe8 sub sp, sp, #124 */
/* @0xe7fec add r4, pc, r4 */
/* @0xe7ff0 mov r6, r0 */
/* @0xe7ff4 cmp r3, #0 */
/* @0xe7ff8 mov r11, r1 */
/* @0xe7ffc mov r10, r2 */
/* @0xe8000 beq 0xe8210 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x240> */
/* @0xe8004 ldr r3, [pc, #0x554] */
/* @0xe8008 ldr r5, [r4, r3] */
/* @0xe800c ldr r3, [pc, #0x550] */
/* @0xe8010 ldr r2, [pc, #0x550] */
/* @0xe8014 ldr r0, [r6, #0x58] */
/* @0xe8018 ldr r3, [r4, r3] */
/* @0xe801c ldr r2, [r4, r2] */
/* @0xe8020 ldr r8, [r6, #0x5c] */
/* @0xe8024 ldrb r3, [r3] */
/* @0xe8028 ldr r2, [r2] */
/* @0xe802c cmp r3, #0 */
/* @0xe8030 ldr r7, [r6, #0x50] */
/* @0xe8034 ldr r3, [r6, #0x54] */
/* @0xe8038 str r2, [sp, #0x10] */
/* @0xe803c str r0, [sp, #0xc] */
/* @0xe8040 bne 0xe82a8 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2d8> */
/* @0xe8044 ldr lr, [r5, #0x8] */
/* @0xe8048 mov r2, #16384 */
/* @0xe804c str r11, [sp, #0x2c] */
/* @0xe8050 cmp lr, #0 */
/* @0xe8054 str r10, [sp, #0x30] */
/* @0xe8058 str r2, [sp, #0x58] */
/* @0xe805c beq 0xe832c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x35c> */
/* @0xe8060 ldr r10, [r5, #0x10] */
/* @0xe8064 movw r12, #0x3ff0 */
/* @0xe8068 ldr r0, [lr] */
/* @0xe806c ldr r1, [sp, #0xa4] */
/* @0xe8070 add r12, lr, r12 */
/* @0xe8074 str r0, [r5, #0x8] */
/* @0xe8078 sub r10, r10, #1 */
/* @0xe807c ldr r0, [r7, #0x4] */
/* @0xe8080 lsl r2, r1, #4 */
/* @0xe8084 ldr r11, [r7, #0x10] */
/* @0xe8088 rsb r12, r2, r12 */
/* @0xe808c str r3, [sp, #0x50] */
/* @0xe8090 ldr r3, [sp, #0xc] */
/* @0xe8094 str lr, [sp, #0x20] */
/* @0xe8098 ldr lr, [r5, #0xc] */
/* @0xe809c ldr r1, [sp, #0xa8] */
/* @0xe80a0 str r0, [sp, #0x68] */
/* @0xe80a4 mov r0, r12 */
/* @0xe80a8 str r10, [r5, #0x10] */
/* @0xe80ac add lr, lr, #1 */
/* @0xe80b0 str r11, [sp, #0x3c] */
/* @0xe80b4 add r11, sp, #24 */
/* @0xe80b8 str lr, [r5, #0xc] */
/* @0xe80bc str r7, [sp, #0x44] */
/* @0xe80c0 str r3, [sp, #0x54] */
/* @0xe80c4 str r8, [sp, #0x4c] */
/* @0xe80c8 bl 0xb65bc <memcpy@plt> */
/* @0xe80cc ldr r5, [pc, #0x498] */
/* @0xe80d0 mov r1, #0 */
/* @0xe80d4 ldr lr, [pc, #0x494] */
/* @0xe80d8 mov r2, #60 */
/* @0xe80dc ldr r10, [sp, #0xa4] */
/* @0xe80e0 ldr r7, [r4, r5] */
/* @0xe80e4 ldr r5, [r4, lr] */
/* @0xe80e8 str r10, [sp, #0x38] */
/* @0xe80ec ldr r10, [r7] */
/* @0xe80f0 ldr r8, [r5] */
/* @0xe80f4 sub r3, r0, #60 */
/* @0xe80f8 mov r12, r0 */
/* @0xe80fc str r3, [sp, #0x40] */
/* @0xe8100 mov r0, r3 */
/* @0xe8104 ldr r3, [sp, #0xa4] */
/* @0xe8108 str r12, [sp, #0x34] */
/* @0xe810c str r12, [r5] */
/* @0xe8110 str r3, [r7] */
/* @0xe8114 bl 0xb65b0 <memset@plt> */
/* @0xe8118 ldr r1, [r6, #0x6c] */
/* @0xe811c mov r2, #0 */
/* @0xe8120 ldr r0, [sp, #0x40] */
/* @0xe8124 mvn r12, #0 */
/* @0xe8128 ldr r3, [pc, #0x444] */
/* @0xe812c str r12, [r0, #0xc] */
/* @0xe8130 str r1, [sp, #0x5c] */
/* @0xe8134 mov r1, #0 */
/* @0xe8138 str r2, [sp, #0x64] */
/* @0xe813c ldr r6, [r4, r3] */
/* @0xe8140 ldr r3, [r6] */
/* @0xe8144 cmp r3, r2 */
/* @0xe8148 ldr r2, [sp, #0x44] */
/* @0xe814c strne r11, [r3] */
/* @0xe8150 str r3, [sp, #0x1c] */
/* @0xe8154 mov r0, r2 */
/* @0xe8158 str r11, [r6] */
/* @0xe815c str r1, [sp, #0x18] */
/* @0xe8160 str r2, [sp] */
/* @0xe8164 bl 0xec750 <_ZN8VMBuffer13convertBufferEv> */
/* @0xe8168 ldr r3, [sp, #0x44] */
/* @0xe816c ldr r2, [sp] */
/* @0xe8170 ldr lr, [sp, #0xa0] */
/* @0xe8174 ldr r3, [r3, #0x18] */
/* @0xe8178 ldr r2, [r2, #0x14] */
/* @0xe817c cmp lr, #0 */
/* @0xe8180 str r3, [sp, #0x74] */
/* @0xe8184 str r2, [sp, #0x70] */
/* @0xe8188 beq 0xe83cc <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x3fc> */
/* @0xe818c mov r3, #1 */
/* @0xe8190 str lr, [sp, #0x28] */
/* @0xe8194 str r3, [sp, #0x24] */
/* @0xe8198 ldr r3, [pc, #0x3d8] */
/* @0xe819c ldr r3, [r4, r3] */
/* @0xe81a0 ldrb r3, [r3] */
/* @0xe81a4 cmp r3, #0 */
/* @0xe81a8 bne 0xe8230 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x260> */
/* @0xe81ac ldr r3, [pc, #0x3c8] */
/* @0xe81b0 mov r0, r11 */
/* @0xe81b4 mov r1, r9 */
/* @0xe81b8 ldr r3, [r4, r3] */
/* @0xe81bc ldr r3, [r3] */
/* @0xe81c0 cmp r3, #0 */
/* @0xe81c4 beq 0xe8324 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x354> */
/* @0xe81c8 mov r2, #0 */
/* @0xe81cc bl 0xe47c8 <_ZN2VM9ExecDebugER6VMExecP6RValueb> */
/* @0xe81d0 ldr r3, [sp, #0x1c] */
/* @0xe81d4 cmp r3, #0 */
/* @0xe81d8 movne r2, #0 */
/* @0xe81dc strne r2, [r3] */
/* @0xe81e0 ldr r2, [sp, #0x24] */
/* @0xe81e4 str r3, [r6] */
/* @0xe81e8 cmp r2, #0 */
/* @0xe81ec str r10, [r7] */
/* @0xe81f0 str r8, [r5] */
/* @0xe81f4 bne 0xe8208 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x238> */
/* @0xe81f8 ldr r0, [sp, #0x28] */
/* @0xe81fc cmp r0, #0 */
/* @0xe8200 beq 0xe8208 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x238> */
/* @0xe8204 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xe8208 add sp, sp, #124 */
/* @0xe820c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe8210 ldr r1, [pc, #0x348] */
/* @0xe8214 mov r2, #1 */
/* @0xe8218 ldr r5, [r4, r1] */
/* @0xe821c strb r2, [r12, #0x14] */
/* @0xe8220 str r3, [r5, #0x4] */
/* @0xe8224 str r3, [r5, #0x8] */
/* @0xe8228 str r3, [r5, #0xc] */
/* @0xe822c b 0xe800c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x3c> */
/* @0xe8230 ldr r0, [sp, #0x28] */
/* @0xe8234 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe8238 ldr r0, [sp, #0x28] */
/* @0xe823c ldr r1, [r0, #0x4] */
/* @0xe8240 cmp r1, #0 */
/* @0xe8244 beq 0xe8454 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x484> */
/* @0xe8248 ldr r2, [r1, #0xc] */
/* @0xe824c bic r3, r2, #-16777216 */
/* @0xe8250 cmp r3, #1 */
/* @0xe8254 beq 0xe82d8 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x308> */
/* @0xe8258 cmp r3, #2 */
/* @0xe825c bne 0xe8274 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2a4> */
/* @0xe8260 sub r3, r2, #1 */
/* @0xe8264 bic r3, r3, #-16777216 */
/* @0xe8268 bic r3, r3, #3 */
/* @0xe826c cmp r3, #0 */
/* @0xe8270 beq 0xe8440 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x470> */
/* @0xe8274 ldr lr, [sp, #0xb0] */
/* @0xe8278 mov r2, #6 */
/* @0xe827c mov r3, #5 */
/* @0xe8280 str r2, [r1, #0xc] */
/* @0xe8284 cmp lr, #0 */
/* @0xe8288 str r3, [r1, #0x8] */
/* @0xe828c str lr, [r1] */
/* @0xe8290 beq 0xe82a0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2d0> */
/* @0xe8294 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe8298 ldr r1, [sp, #0xb0] */
/* @0xe829c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe82a0 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xe82a4 b 0xe81ac <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x1dc> */
/* @0xe82a8 ldr r0, [pc, #0x2d0] */
/* @0xe82ac mov r2, r8 */
/* @0xe82b0 ldr r1, [pc, #0x2cc] */
/* @0xe82b4 ldr r0, [r4, r0] */
/* @0xe82b8 add r1, pc, r1 */
/* @0xe82bc ldr r0, [r0] */
/* @0xe82c0 ldr r12, [r0] */
/* @0xe82c4 ldr r12, [r12, #0xc] */
/* @0xe82c8 str r3, [sp, #0x4] */
/* @0xe82cc blx r12 */
/* @0xe82d0 ldr r3, [sp, #0x4] */
/* @0xe82d4 b 0xe8044 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x74> */
/* @0xe82d8 ldr r3, [r1] */
/* @0xe82dc cmp r3, #0 */
/* @0xe82e0 beq 0xe8318 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x348> */
/* @0xe82e4 str r1, [sp, #0x8] */
/* @0xe82e8 str r3, [sp, #0x4] */
/* @0xe82ec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe82f0 ldr r3, [sp, #0x4] */
/* @0xe82f4 ldr r1, [sp, #0x8] */
/* @0xe82f8 ldr r2, [r3, #0x4] */
/* @0xe82fc sub r2, r2, #1 */
/* @0xe8300 str r2, [r3, #0x4] */
/* @0xe8304 cmp r2, #0 */
/* @0xe8308 beq 0xe83e4 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x414> */
/* @0xe830c str r1, [sp, #0x8] */
/* @0xe8310 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe8314 ldr r1, [sp, #0x8] */
/* @0xe8318 mov r3, #0 */
/* @0xe831c str r3, [r1] */
/* @0xe8320 b 0xe8274 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2a4> */
/* @0xe8324 bl 0xe4540 <_ZN2VM11ExecReleaseER6VMExecP6RValue> */
/* @0xe8328 b 0xe81d0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x200> */
/* @0xe832c movw r0, #0x8008 */
/* @0xe8330 movt r0, #0x10 */
/* @0xe8334 str r3, [sp, #0x4] */
/* @0xe8338 bl 0x27c524 <_Znwj> */
/* @0xe833c mov r1, #120 */
/* @0xe8340 mov r2, #1081344 */
/* @0xe8344 mov r10, r0 */
/* @0xe8348 add r0, r0, #8 */
/* @0xe834c bl 0xb65b0 <memset@plt> */
/* @0xe8350 ldr r1, [r5, #0x8] */
/* @0xe8354 ldr r0, [r5, #0x4] */
/* @0xe8358 add lr, r10, #32768 */
/* @0xe835c add lr, lr, #8 */
/* @0xe8360 ldr r11, [r5, #0x10] */
/* @0xe8364 str r1, [sp, #0x14] */
/* @0xe8368 bic lr, lr, #32512 */
/* @0xe836c str r0, [r10] */
/* @0xe8370 bic lr, lr, #255 */
/* @0xe8374 str r10, [r5, #0x4] */
/* @0xe8378 add r12, r11, #1 */
/* @0xe837c ldr r10, [sp, #0x14] */
/* @0xe8380 add r2, lr, #32768 */
/* @0xe8384 add r1, lr, #1015808 */
/* @0xe8388 mov r0, lr */
/* @0xe838c ldr r3, [sp, #0x4] */
/* @0xe8390 str r10, [lr] */
/* @0xe8394 str lr, [r5, #0x8] */
/* @0xe8398 str r12, [r5, #0x10] */
/* @0xe839c b 0xe83a4 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x3d4> */
/* @0xe83a0 mov r0, r12 */
/* @0xe83a4 str r0, [r2] */
/* @0xe83a8 mov r12, r2 */
/* @0xe83ac add r2, r2, #32768 */
/* @0xe83b0 cmp r2, r1 */
/* @0xe83b4 bne 0xe83a0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x3d0> */
/* @0xe83b8 ldr r2, [sp, #0x58] */
/* @0xe83bc add r10, r11, #31 */
/* @0xe83c0 add lr, lr, #983040 */
/* @0xe83c4 sub r12, r2, #16 */
/* @0xe83c8 b 0xe806c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x9c> */
/* @0xe83cc ldr r0, [sp, #0x10] */
/* @0xe83d0 bl 0xd41e4 <_Z20YYAllocLocalStackNewi> */
/* @0xe83d4 ldr r3, [sp, #0xa0] */
/* @0xe83d8 str r3, [sp, #0x24] */
/* @0xe83dc str r0, [sp, #0x28] */
/* @0xe83e0 b 0xe8198 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x1c8> */
/* @0xe83e4 ldr r0, [r3] */
/* @0xe83e8 stm sp, {r2, r3} */
/* @0xe83ec bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe83f0 ldm sp, {r2, r3} */
/* @0xe83f4 str r2, [r3] */
/* @0xe83f8 str r2, [r3, #0x8] */
/* @0xe83fc str r3, [sp, #0x4] */
/* @0xe8400 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe8404 ldr r3, [sp, #0x4] */
/* @0xe8408 ldr r1, [sp, #0x8] */
/* @0xe840c ldr r2, [r3, #0x4] */
/* @0xe8410 sub r2, r2, #1 */
/* @0xe8414 str r2, [r3, #0x4] */
/* @0xe8418 cmp r2, #0 */
/* @0xe841c beq 0xe8460 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x490> */
/* @0xe8420 str r1, [sp, #0x8] */
/* @0xe8424 str r3, [sp, #0x4] */
/* @0xe8428 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe842c ldr r3, [sp, #0x4] */
/* @0xe8430 mov r0, r3 */
/* @0xe8434 bl 0x27d1d0 <_ZdlPv> */
/* @0xe8438 ldr r1, [sp, #0x8] */
/* @0xe843c b 0xe830c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x33c> */
/* @0xe8440 mov r0, r1 */
/* @0xe8444 str r1, [sp, #0x8] */
/* @0xe8448 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe844c ldr r1, [sp, #0x8] */
/* @0xe8450 b 0xe8274 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x2a4> */
/* @0xe8454 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe8458 mov r1, r0 */
/* @0xe845c b 0xe8248 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x278> */
/* @0xe8460 ldr r0, [r3] */
/* @0xe8464 stm sp, {r2, r3} */
/* @0xe8468 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe846c ldm sp, {r2, r3} */
/* @0xe8470 str r2, [r3] */
/* @0xe8474 str r2, [r3, #0x8] */
/* @0xe8478 str r3, [sp, #0x4] */
/* @0xe847c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe8480 ldr r3, [sp, #0x4] */
/* @0xe8484 ldr r1, [sp, #0x8] */
/* @0xe8488 ldr r2, [r3, #0x4] */
/* @0xe848c sub r2, r2, #1 */
/* @0xe8490 str r2, [r3, #0x4] */
/* @0xe8494 cmp r2, #0 */
/* @0xe8498 beq 0xe84c0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x4f0> */
/* @0xe849c str r1, [sp, #0x8] */
/* @0xe84a0 str r3, [sp, #0x4] */
/* @0xe84a4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe84a8 ldr r3, [sp, #0x4] */
/* @0xe84ac mov r0, r3 */
/* @0xe84b0 bl 0x27d1d0 <_ZdlPv> */
/* @0xe84b4 ldr r3, [sp, #0x4] */
/* @0xe84b8 ldr r1, [sp, #0x8] */
/* @0xe84bc b 0xe8420 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x450> */
/* @0xe84c0 ldr r0, [r3] */
/* @0xe84c4 stm sp, {r2, r3} */
/* @0xe84c8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe84cc ldm sp, {r2, r3} */
/* @0xe84d0 str r2, [r3] */
/* @0xe84d4 str r2, [r3, #0x8] */
/* @0xe84d8 str r3, [sp, #0x4] */
/* @0xe84dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe84e0 ldr r3, [sp, #0x4] */
/* @0xe84e4 ldr r1, [sp, #0x8] */
/* @0xe84e8 ldr r2, [r3, #0x4] */
/* @0xe84ec sub r2, r2, #1 */
/* @0xe84f0 str r2, [r3, #0x4] */
/* @0xe84f4 cmp r2, #0 */
/* @0xe84f8 bne 0xe8534 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x564> */
/* @0xe84fc ldr r0, [r3] */
/* @0xe8500 stm sp, {r2, r3} */
/* @0xe8504 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe8508 ldm sp, {r2, r3} */
/* @0xe850c str r2, [r3] */
/* @0xe8510 mov r0, r3 */
/* @0xe8514 str r2, [r3, #0x8] */
/* @0xe8518 str r3, [sp, #0x4] */
/* @0xe851c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xe8520 ldr r3, [sp, #0x4] */
/* @0xe8524 mov r0, r3 */
/* @0xe8528 bl 0x27d1d0 <_ZdlPv> */
/* @0xe852c ldr r3, [sp, #0x4] */
/* @0xe8530 ldr r1, [sp, #0x8] */
/* @0xe8534 str r1, [sp, #0x8] */
/* @0xe8538 str r3, [sp, #0x4] */
/* @0xe853c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe8540 ldr r3, [sp, #0x4] */
/* @0xe8544 mov r0, r3 */
/* @0xe8548 bl 0x27d1d0 <_ZdlPv> */
/* @0xe854c ldr r3, [sp, #0x4] */
/* @0xe8550 ldr r1, [sp, #0x8] */
/* @0xe8554 b 0xe849c <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_+0x4cc> */
/* @0xe8558 ldrsbteq r2, [r9], -r12 */
/* @0xe855c eorseq r9, r0, r4, ror #24 */
/* @0xe8560 .word 0xffffc0e4 */
/* @0xe8564 .word 0xffffc100 */
/* @0xe8568 .word 0xffffc104 */
/* @0xe856c .word 0xffffc0bc */
/* @0xe8570 .word 0xffffc0c0 */
/* @0xe8574 .word 0xffffbf58 */
/* @0xe8578 .word 0xffffbf68 */
/* @0xe857c .word 0xffffc0a4 */
/* @0xe8580 .word 0xffffbac4 */
/* @0xe8584 eoreq r12, r4, r0, asr r5 */

/* ── FUNC 0xe8588 · DoCallScript(CScript*, int, unsigned char*, VMExec*, YYObjectBase*, YYObjectBase*) · size=1400 · insn=350 */
/* @0xe8588 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe858c subs r8, r0, #0 */
/* @0xe8590 ldr r7, [pc, #0x538] */
/* @0xe8594 sub sp, sp, #12 */
/* @0xe8598 mov r11, r1 */
/* @0xe859c mov r5, r2 */
/* @0xe85a0 mov r4, r3 */
/* @0xe85a4 add r7, pc, r7 */
/* @0xe85a8 beq 0xe89c0 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x438> */
/* @0xe85ac mov r0, r8 */
/* @0xe85b0 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0xe85b4 ldr r3, [r0, #0x50] */
/* @0xe85b8 cmp r3, #0 */
/* @0xe85bc beq 0xe8978 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x3f0> */
/* @0xe85c0 ldr r3, [pc, #0x50c] */
/* @0xe85c4 ldr r3, [r7, r3] */
/* @0xe85c8 ldrb r3, [r3] */
/* @0xe85cc cmp r3, #0 */
/* @0xe85d0 bne 0xe88fc <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x374> */
/* @0xe85d4 ldr r3, [pc, #0x4fc] */
/* @0xe85d8 ldr r6, [r4, #0x8] */
/* @0xe85dc ldr r9, [r7, r3] */
/* @0xe85e0 add r3, r6, #1024 */
/* @0xe85e4 cmp r5, r3 */
/* @0xe85e8 ldr r12, [r9] */
/* @0xe85ec str r5, [r9] */
/* @0xe85f0 blo 0xe882c <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x2a4> */
/* @0xe85f4 ldr r3, [r4, #0x28] */
/* @0xe85f8 ldr lr, [r4, #0x14] */
/* @0xe85fc cmp r3, #0 */
/* @0xe8600 ldr r0, [r4, #0x18] */
/* @0xe8604 sub r9, r5, #60 */
/* @0xe8608 ldr r1, [r4, #0x44] */
/* @0xe860c ldr r2, [r4, #0x2c] */
/* @0xe8610 ldr r10, [r4, #0x3c] */
/* @0xe8614 str lr, [r5, #-0x2c] */
/* @0xe8618 ldr lr, [r4, #0x38] */
/* @0xe861c str r0, [r5, #-0x28] */
/* @0xe8620 ldr r0, [r4, #0x34] */
/* @0xe8624 str r1, [r5, #-0x3c] */
/* @0xe8628 ldr r1, [r4, #0x30] */
/* @0xe862c str lr, [r5, #-0x20] */
/* @0xe8630 mvneq lr, #0 */
/* @0xe8634 ldrne lr, [r4, #0x40] */
/* @0xe8638 str r2, [r5, #-0x24] */
/* @0xe863c addne lr, r6, lr */
/* @0xe8640 ldr r2, [r4, #0xc] */
/* @0xe8644 rsbne lr, r3, lr */
/* @0xe8648 str r1, [r5, #-0x38] */
/* @0xe864c ldr r3, [pc, #0x488] */
/* @0xe8650 rsb r6, r6, r12 */
/* @0xe8654 ldr r1, [r4, #0x10] */
/* @0xe8658 str r10, [r5, #-0x1c] */
/* @0xe865c mov r10, #0 */
/* @0xe8660 str r0, [r5, #-0x18] */
/* @0xe8664 mov r0, r8 */
/* @0xe8668 str lr, [r5, #-0x30] */
/* @0xe866c str r1, [r5, #-0xc] */
/* @0xe8670 str r2, [r5, #-0x10] */
/* @0xe8674 str r10, [r5, #-0x14] */
/* @0xe8678 ldr r3, [r7, r3] */
/* @0xe867c ldr r2, [r3] */
/* @0xe8680 str r6, [r5, #-0x4] */
/* @0xe8684 str r2, [r5, #-0x34] */
/* @0xe8688 str r3, [sp, #0x4] */
/* @0xe868c bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0xe8690 ldr r6, [r0, #0x50] */
/* @0xe8694 mov r5, r0 */
/* @0xe8698 ldr r12, [r0, #0x6c] */
/* @0xe869c ldr lr, [r0, #0x54] */
/* @0xe86a0 ldr r1, [r6, #0x10] */
/* @0xe86a4 mov r0, r6 */
/* @0xe86a8 ldr r2, [r6, #0x4] */
/* @0xe86ac str r12, [r4, #0x44] */
/* @0xe86b0 ldr r12, [r5, #0x58] */
/* @0xe86b4 str r1, [r4, #0x24] */
/* @0xe86b8 ldr r1, [r5, #0x5c] */
/* @0xe86bc str r2, [r4, #0x50] */
/* @0xe86c0 str lr, [r4, #0x38] */
/* @0xe86c4 str r12, [r4, #0x3c] */
/* @0xe86c8 str r1, [r4, #0x34] */
/* @0xe86cc str r6, [r4, #0x2c] */
/* @0xe86d0 str r10, [r4, #0x30] */
/* @0xe86d4 str r9, [r4, #0x28] */
/* @0xe86d8 bl 0xec750 <_ZN8VMBuffer13convertBufferEv> */
/* @0xe86dc ldr r2, [r4, #0x44] */
/* @0xe86e0 ldr r1, [r4, #0x2c] */
/* @0xe86e4 mov r0, r8 */
/* @0xe86e8 cmp r2, r10 */
/* @0xe86ec add lr, r2, #3 */
/* @0xe86f0 ldr r12, [r6, #0x14] */
/* @0xe86f4 ldr r1, [r1, #0x18] */
/* @0xe86f8 movlt r2, lr */
/* @0xe86fc asr r2, r2, #2 */
/* @0xe8700 ldr r3, [sp, #0x4] */
/* @0xe8704 str r12, [r4, #0x58] */
/* @0xe8708 ldr r2, [r1, r2, lsl #2] */
/* @0xe870c str r1, [r4, #0x5c] */
/* @0xe8710 str r11, [r3] */
/* @0xe8714 str r2, [r4, #0x48] */
/* @0xe8718 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0xe871c ldr r3, [r0, #0x78] */
/* @0xe8720 tst r3, #4 */
/* @0xe8724 beq 0xe87f4 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x26c> */
/* @0xe8728 ldr r3, [pc, #0x3b0] */
/* @0xe872c mov r2, #1 */
/* @0xe8730 str r10, [r4, #0x10] */
/* @0xe8734 str r2, [r4, #0xc] */
/* @0xe8738 ldr r3, [r7, r3] */
/* @0xe873c ldrb r3, [r3] */
/* @0xe8740 cmp r3, r10 */
/* @0xe8744 beq 0xe87c8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x240> */
/* @0xe8748 ldr r3, [sp, #0x30] */
/* @0xe874c cmp r3, #0 */
/* @0xe8750 movne r0, r10 */
/* @0xe8754 beq 0xe87c8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x240> */
/* @0xe8758 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe875c ldr r0, [r4, #0x10] */
/* @0xe8760 ldr r6, [r0, #0x4] */
/* @0xe8764 cmp r6, #0 */
/* @0xe8768 beq 0xe8a30 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x4a8> */
/* @0xe876c ldr r2, [r6, #0xc] */
/* @0xe8770 bic r3, r2, #-16777216 */
/* @0xe8774 cmp r3, #1 */
/* @0xe8778 beq 0xe8944 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x3bc> */
/* @0xe877c cmp r3, #2 */
/* @0xe8780 bne 0xe8798 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x210> */
/* @0xe8784 sub r3, r2, #1 */
/* @0xe8788 bic r3, r3, #-16777216 */
/* @0xe878c bic r3, r3, #3 */
/* @0xe8790 cmp r3, #0 */
/* @0xe8794 beq 0xe8a0c <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x484> */
/* @0xe8798 ldr r1, [sp, #0x34] */
/* @0xe879c mov r2, #6 */
/* @0xe87a0 mov r3, #5 */
/* @0xe87a4 str r2, [r6, #0xc] */
/* @0xe87a8 cmp r1, #0 */
/* @0xe87ac str r3, [r6, #0x8] */
/* @0xe87b0 str r1, [r6] */
/* @0xe87b4 beq 0xe87c4 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x23c> */
/* @0xe87b8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe87bc ldr r1, [sp, #0x34] */
/* @0xe87c0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe87c4 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xe87c8 ldr r3, [pc, #0x314] */
/* @0xe87cc ldr r2, [r4, #0x4c] */
/* @0xe87d0 add r2, r2, #1 */
/* @0xe87d4 str r2, [r4, #0x4c] */
/* @0xe87d8 ldr r3, [r7, r3] */
/* @0xe87dc ldrb r3, [r3] */
/* @0xe87e0 cmp r3, #0 */
/* @0xe87e4 bne 0xe8924 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x39c> */
/* @0xe87e8 mov r0, r9 */
/* @0xe87ec add sp, sp, #12 */
/* @0xe87f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe87f4 ldr r1, [sp, #0x30] */
/* @0xe87f8 cmp r1, #0 */
/* @0xe87fc beq 0xe8a18 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x490> */
/* @0xe8800 ldr r3, [pc, #0x2d8] */
/* @0xe8804 mov r2, #1 */
/* @0xe8808 ldr r1, [sp, #0x30] */
/* @0xe880c str r2, [r4, #0xc] */
/* @0xe8810 str r1, [r4, #0x10] */
/* @0xe8814 ldr r3, [r7, r3] */
/* @0xe8818 ldrb r3, [r3] */
/* @0xe881c cmp r3, #0 */
/* @0xe8820 beq 0xe87c8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x240> */
/* @0xe8824 ldr r0, [sp, #0x30] */
/* @0xe8828 b 0xe8758 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x1d0> */
/* @0xe882c ldr r0, [r4, #0x40] */
/* @0xe8830 mov r3, #1 */
/* @0xe8834 ldr r1, [pc, #0x2ac] */
/* @0xe8838 movw r2, #0x837 */
/* @0xe883c add r0, r0, #16384 */
/* @0xe8840 str r12, [sp, #0x4] */
/* @0xe8844 add r1, pc, r1 */
/* @0xe8848 rsb r5, r6, r5 */
/* @0xe884c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xe8850 mov r1, r6 */
/* @0xe8854 ldr r2, [r4, #0x40] */
/* @0xe8858 add r5, r5, #16384 */
/* @0xe885c str r0, [r4, #0x8] */
/* @0xe8860 add r0, r0, #16384 */
/* @0xe8864 bl 0xb65bc <memcpy@plt> */
/* @0xe8868 ldr r3, [r4, #0x28] */
/* @0xe886c ldr r0, [r9] */
/* @0xe8870 ldr r1, [pc, #0x274] */
/* @0xe8874 rsb r3, r6, r3 */
/* @0xe8878 ldr r2, [r4, #0x8] */
/* @0xe887c add r3, r3, #16384 */
/* @0xe8880 ldr lr, [r4, #0x40] */
/* @0xe8884 rsb r0, r6, r0 */
/* @0xe8888 add r3, r2, r3 */
/* @0xe888c add r0, r2, r0 */
/* @0xe8890 str r3, [r4, #0x28] */
/* @0xe8894 add lr, lr, #16384 */
/* @0xe8898 str r0, [r9] */
/* @0xe889c add r5, r2, r5 */
/* @0xe88a0 str lr, [r4, #0x40] */
/* @0xe88a4 ldr r9, [r7, r1] */
/* @0xe88a8 ldr r12, [sp, #0x4] */
/* @0xe88ac ldr r1, [r9, #0x4] */
/* @0xe88b0 cmp r1, #0 */
/* @0xe88b4 beq 0xe88e0 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x358> */
/* @0xe88b8 add lr, r1, #8 */
/* @0xe88bc add r0, r1, #1048576 */
/* @0xe88c0 cmp r6, lr */
/* @0xe88c4 add r0, r0, #8 */
/* @0xe88c8 blo 0xe88d4 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x34c> */
/* @0xe88cc cmp r0, r6 */
/* @0xe88d0 bhi 0xe8994 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x40c> */
/* @0xe88d4 ldr r1, [r1] */
/* @0xe88d8 cmp r1, #0 */
/* @0xe88dc bne 0xe88b8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x330> */
/* @0xe88e0 mov r0, r6 */
/* @0xe88e4 str r12, [sp, #0x4] */
/* @0xe88e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xe88ec ldr r3, [r4, #0x28] */
/* @0xe88f0 ldr r6, [r4, #0x8] */
/* @0xe88f4 ldr r12, [sp, #0x4] */
/* @0xe88f8 b 0xe85f8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x70> */
/* @0xe88fc ldr r3, [pc, #0x1ec] */
/* @0xe8900 ldr r1, [pc, #0x1ec] */
/* @0xe8904 ldr r2, [r8, #0x14] */
/* @0xe8908 ldr r3, [r7, r3] */
/* @0xe890c add r1, pc, r1 */
/* @0xe8910 ldr r0, [r3] */
/* @0xe8914 ldr r3, [r0] */
/* @0xe8918 ldr r3, [r3, #0xc] */
/* @0xe891c blx r3 */
/* @0xe8920 b 0xe85d4 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x4c> */
/* @0xe8924 ldr r3, [pc, #0x1cc] */
/* @0xe8928 mov r1, #1 */
/* @0xe892c ldr r2, [r5, #0x60] */
/* @0xe8930 ldr r0, [r7, r3] */
/* @0xe8934 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0xe8938 mov r0, r9 */
/* @0xe893c add sp, sp, #12 */
/* @0xe8940 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe8944 ldr r8, [r6] */
/* @0xe8948 cmp r8, #0 */
/* @0xe894c beq 0xe896c <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x3e4> */
/* @0xe8950 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe8954 ldr r10, [r8, #0x4] */
/* @0xe8958 sub r10, r10, #1 */
/* @0xe895c str r10, [r8, #0x4] */
/* @0xe8960 cmp r10, #0 */
/* @0xe8964 beq 0xe89d4 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x44c> */
/* @0xe8968 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe896c mov r3, #0 */
/* @0xe8970 str r3, [r6] */
/* @0xe8974 b 0xe8798 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x210> */
/* @0xe8978 sub r9, r5, #16 */
/* @0xe897c str r3, [r5, #-0x4] */
/* @0xe8980 str r3, [r5, #-0x10] */
/* @0xe8984 mov r0, r9 */
/* @0xe8988 str r3, [r5, #-0xc] */
/* @0xe898c add sp, sp, #12 */
/* @0xe8990 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe8994 ldr lr, [r9, #0x8] */
/* @0xe8998 ldr r0, [r9, #0x10] */
/* @0xe899c ldr r1, [r9, #0xc] */
/* @0xe89a0 add r0, r0, #1 */
/* @0xe89a4 str lr, [r6] */
/* @0xe89a8 sub r1, r1, #1 */
/* @0xe89ac str r6, [r9, #0x8] */
/* @0xe89b0 str r0, [r9, #0x10] */
/* @0xe89b4 mov r6, r2 */
/* @0xe89b8 str r1, [r9, #0xc] */
/* @0xe89bc b 0xe85f8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x70> */
/* @0xe89c0 ldr r1, [pc, #0x134] */
/* @0xe89c4 mov r0, r3 */
/* @0xe89c8 add r1, pc, r1 */
/* @0xe89cc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe89d0 b 0xe85ac <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x24> */
/* @0xe89d4 ldr r0, [r8] */
/* @0xe89d8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe89dc str r10, [r8] */
/* @0xe89e0 str r10, [r8, #0x8] */
/* @0xe89e4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe89e8 ldr r10, [r8, #0x4] */
/* @0xe89ec sub r10, r10, #1 */
/* @0xe89f0 str r10, [r8, #0x4] */
/* @0xe89f4 cmp r10, #0 */
/* @0xe89f8 beq 0xe8a40 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x4b8> */
/* @0xe89fc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe8a00 mov r0, r8 */
/* @0xe8a04 bl 0x27d1d0 <_ZdlPv> */
/* @0xe8a08 b 0xe8968 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x3e0> */
/* @0xe8a0c mov r0, r6 */
/* @0xe8a10 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe8a14 b 0xe8798 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x210> */
/* @0xe8a18 ldr r0, [r5, #0x70] */
/* @0xe8a1c bl 0xd41e4 <_Z20YYAllocLocalStackNewi> */
/* @0xe8a20 ldr r3, [sp, #0x30] */
/* @0xe8a24 str r3, [r4, #0xc] */
/* @0xe8a28 str r0, [r4, #0x10] */
/* @0xe8a2c b 0xe87c8 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x240> */
/* @0xe8a30 mov r1, r6 */
/* @0xe8a34 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe8a38 mov r6, r0 */
/* @0xe8a3c b 0xe876c <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x1e4> */
/* @0xe8a40 ldr r0, [r8] */
/* @0xe8a44 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe8a48 str r10, [r8] */
/* @0xe8a4c str r10, [r8, #0x8] */
/* @0xe8a50 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe8a54 ldr r10, [r8, #0x4] */
/* @0xe8a58 sub r10, r10, #1 */
/* @0xe8a5c str r10, [r8, #0x4] */
/* @0xe8a60 cmp r10, #0 */
/* @0xe8a64 beq 0xe8a78 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x4f0> */
/* @0xe8a68 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe8a6c mov r0, r8 */
/* @0xe8a70 bl 0x27d1d0 <_ZdlPv> */
/* @0xe8a74 b 0xe89fc <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x474> */
/* @0xe8a78 ldr r0, [r8] */
/* @0xe8a7c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe8a80 str r10, [r8] */
/* @0xe8a84 str r10, [r8, #0x8] */
/* @0xe8a88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe8a8c ldr r10, [r8, #0x4] */
/* @0xe8a90 sub r10, r10, #1 */
/* @0xe8a94 str r10, [r8, #0x4] */
/* @0xe8a98 cmp r10, #0 */
/* @0xe8a9c bne 0xe8ac0 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x538> */
/* @0xe8aa0 ldr r0, [r8] */
/* @0xe8aa4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe8aa8 mov r0, r8 */
/* @0xe8aac str r10, [r8] */
/* @0xe8ab0 str r10, [r8, #0x8] */
/* @0xe8ab4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xe8ab8 mov r0, r8 */
/* @0xe8abc bl 0x27d1d0 <_ZdlPv> */
/* @0xe8ac0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe8ac4 mov r0, r8 */
/* @0xe8ac8 bl 0x27d1d0 <_ZdlPv> */
/* @0xe8acc b 0xe8a68 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_+0x4e0> */
/* @0xe8ad0 eorseq r9, r0, r12, lsr #13 */
/* @0xe8ad4 .word 0xffffc100 */
/* @0xe8ad8 .word 0xffffc0c0 */
/* @0xe8adc .word 0xffffc0bc */
/* @0xe8ae0 .word 0xffffbf68 */
/* @0xe8ae4 .word 0xffffbf18 */
/* @0xe8ae8 eoreq r9, r4, r8, lsr pc */
/* @0xe8aec .word 0xffffc0e4 */
/* @0xe8af0 .word 0xffffbac4 */
/* @0xe8af4 eoreq r11, r4, r12, lsr #30 */
/* @0xe8af8 .word 0xffffbf1c */
/* @0xe8afc eoreq r11, r4, r0, asr lr */

/* ── FUNC 0xe8b00 · DoCallGML(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=72 · insn=18 */
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

/* ── FUNC 0xe8b48 · DoCall(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=3144 · insn=786 */
/* @0xe8b48 ubfx r12, r0, #0x10, #0x4 */
/* @0xe8b4c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe8b50 cmp r12, #2 */
/* @0xe8b54 ldr r5, [pc, #0xbe8] */
/* @0xe8b58 sub sp, sp, #76 */
/* @0xe8b5c mov r4, r1 */
/* @0xe8b60 mov r9, r3 */
/* @0xe8b64 add r5, pc, r5 */
/* @0xe8b68 beq 0xe8be0 <_Z6DoCalljPhPKhP6VMExec+0x98> */
/* @0xe8b6c cmp r12, #5 */
/* @0xe8b70 beq 0xe8b94 <_Z6DoCalljPhPKhP6VMExec+0x4c> */
/* @0xe8b74 ldr r1, [pc, #0xbcc] */
/* @0xe8b78 mov r0, r3 */
/* @0xe8b7c add r1, pc, r1 */
/* @0xe8b80 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe8b84 mov r11, r4 */
/* @0xe8b88 mov r0, r11 */
/* @0xe8b8c add sp, sp, #76 */
/* @0xe8b90 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe8b94 ldr r3, [r1, #0xc] */
/* @0xe8b98 add r11, r1, #16 */
/* @0xe8b9c bic r3, r3, #-16777216 */
/* @0xe8ba0 cmp r3, #6 */
/* @0xe8ba4 beq 0xe8e08 <_Z6DoCalljPhPKhP6VMExec+0x2c0> */
/* @0xe8ba8 mvn r2, #-16777216 */
/* @0xe8bac cmp r3, r2 */
/* @0xe8bb0 beq 0xe8ff4 <_Z6DoCalljPhPKhP6VMExec+0x4ac> */
/* @0xe8bb4 ldr r3, [pc, #0xb90] */
/* @0xe8bb8 ldr r3, [r5, r3] */
/* @0xe8bbc ldrb r3, [r3] */
/* @0xe8bc0 cmp r3, #0 */
/* @0xe8bc4 bne 0xe8b88 <_Z6DoCalljPhPKhP6VMExec+0x40> */
/* @0xe8bc8 ldr r0, [pc, #0xb80] */
/* @0xe8bcc add r0, pc, r0 */
/* @0xe8bd0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe8bd4 mov r0, r11 */
/* @0xe8bd8 add sp, sp, #76 */
/* @0xe8bdc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe8be0 ldr r2, [r2] */
/* @0xe8be4 movw r3, #0x869f */
/* @0xe8be8 movt r3, #0x1 */
/* @0xe8bec uxth r6, r0 */
/* @0xe8bf0 cmp r2, r3 */
/* @0xe8bf4 ble 0xe8d0c <_Z6DoCalljPhPKhP6VMExec+0x1c4> */
/* @0xe8bf8 movw r3, #0xa120 */
/* @0xe8bfc movt r3, #0x7 */
/* @0xe8c00 cmp r2, r3 */
/* @0xe8c04 bgt 0xe8c50 <_Z6DoCalljPhPKhP6VMExec+0x108> */
/* @0xe8c08 movw r3, #0xa11f */
/* @0xe8c0c movt r3, #0x7 */
/* @0xe8c10 cmp r2, r3 */
/* @0xe8c14 beq 0xe9024 <_Z6DoCalljPhPKhP6VMExec+0x4dc> */
/* @0xe8c18 sub r0, r2, #99328 */
/* @0xe8c1c sub r0, r0, #672 */
/* @0xe8c20 bl 0x1e069c <_Z11Script_Datai> */
/* @0xe8c24 mov r12, #0 */
/* @0xe8c28 mov r1, r6 */
/* @0xe8c2c mov r2, r4 */
/* @0xe8c30 mov r3, r9 */
/* @0xe8c34 str r12, [sp] */
/* @0xe8c38 str r12, [sp, #0x4] */
/* @0xe8c3c bl 0xe8588 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_> */
/* @0xe8c40 mov r11, r0 */
/* @0xe8c44 mov r0, r11 */
/* @0xe8c48 add sp, sp, #76 */
/* @0xe8c4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe8c50 add r7, sp, #72 */
/* @0xe8c54 sub r0, r2, #499712 */
/* @0xe8c58 mov r8, #0 */
/* @0xe8c5c sub r0, r0, #288 */
/* @0xe8c60 str r8, [sp, #0x44] */
/* @0xe8c64 mov r1, r6 */
/* @0xe8c68 str r8, [sp, #0x40] */
/* @0xe8c6c mov r2, r4 */
/* @0xe8c70 str r8, [sp, #0x3c] */
/* @0xe8c74 str r8, [r7, #-0x10]! */
/* @0xe8c78 mov r3, r7 */
/* @0xe8c7c bl 0xf6344 <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_> */
/* @0xe8c80 ldr r3, [pc, #0xacc] */
/* @0xe8c84 cmp r6, r8 */
/* @0xe8c88 ldr r3, [r5, r3] */
/* @0xe8c8c str r9, [r3] */
/* @0xe8c90 beq 0xe8ce4 <_Z6DoCalljPhPKhP6VMExec+0x19c> */
/* @0xe8c94 mov r5, r4 */
/* @0xe8c98 mov r9, r8 */
/* @0xe8c9c mov r10, #5 */
/* @0xe8ca0 b 0xe8cb8 <_Z6DoCalljPhPKhP6VMExec+0x170> */
/* @0xe8ca4 cmp r8, r6 */
/* @0xe8ca8 str r9, [r5, #0x8] */
/* @0xe8cac str r10, [r5, #0xc] */
/* @0xe8cb0 str r9, [r5], #16 */
/* @0xe8cb4 beq 0xe8ce0 <_Z6DoCalljPhPKhP6VMExec+0x198> */
/* @0xe8cb8 ldr r3, [r5, #0xc] */
/* @0xe8cbc add r8, r8, #1 */
/* @0xe8cc0 sub r3, r3, #1 */
/* @0xe8cc4 bic r3, r3, #-16777216 */
/* @0xe8cc8 bic r3, r3, #3 */
/* @0xe8ccc cmp r3, #0 */
/* @0xe8cd0 bne 0xe8ca4 <_Z6DoCalljPhPKhP6VMExec+0x15c> */
/* @0xe8cd4 mov r0, r5 */
/* @0xe8cd8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe8cdc b 0xe8ca4 <_Z6DoCalljPhPKhP6VMExec+0x15c> */
/* @0xe8ce0 add r4, r4, r8, lsl #4 */
/* @0xe8ce4 ldm r7!, {r0, r1, r2, r3} */
/* @0xe8ce8 sub r12, r4, #16 */
/* @0xe8cec mov r11, r12 */
/* @0xe8cf0 str r0, [r4, #-0x10] */
/* @0xe8cf4 str r1, [r4, #-0xc] */
/* @0xe8cf8 mov r0, r11 */
/* @0xe8cfc str r2, [r4, #-0x8] */
/* @0xe8d00 str r3, [r4, #-0x4] */
/* @0xe8d04 add sp, sp, #76 */
/* @0xe8d08 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe8d0c ldr r3, [pc, #0xa44] */
/* @0xe8d10 mov r1, #0 */
/* @0xe8d14 ldr r0, [pc, #0xa40] */
/* @0xe8d18 add r10, r2, r2, lsl #2 */
/* @0xe8d1c ldr r3, [r5, r3] */
/* @0xe8d20 str r1, [sp, #0x38] */
/* @0xe8d24 str r1, [sp, #0x3c] */
/* @0xe8d28 str r1, [sp, #0x40] */
/* @0xe8d2c str r1, [sp, #0x44] */
/* @0xe8d30 ldr r0, [r5, r0] */
/* @0xe8d34 str r0, [sp, #0xc] */
/* @0xe8d38 ldr r12, [sp, #0xc] */
/* @0xe8d3c ldr r0, [r3] */
/* @0xe8d40 ldrb r3, [r12] */
/* @0xe8d44 add r10, r0, r10, lsl #4 */
/* @0xe8d48 cmp r3, r1 */
/* @0xe8d4c bne 0xe9014 <_Z6DoCalljPhPKhP6VMExec+0x4cc> */
/* @0xe8d50 ldr r12, [pc, #0xa08] */
/* @0xe8d54 add r7, sp, #56 */
/* @0xe8d58 ldr r2, [r9, #0x18] */
/* @0xe8d5c mov r3, r6 */
/* @0xe8d60 ldr r1, [r9, #0x14] */
/* @0xe8d64 mov r0, r7 */
/* @0xe8d68 ldr r8, [r5, r12] */
/* @0xe8d6c str r4, [sp] */
/* @0xe8d70 ldr r12, [r10, #0x40] */
/* @0xe8d74 ldr r11, [r8] */
/* @0xe8d78 str r10, [r8] */
/* @0xe8d7c blx r12 */
/* @0xe8d80 ldr r12, [sp, #0xc] */
/* @0xe8d84 ldr r3, [pc, #0x9c8] */
/* @0xe8d88 str r11, [r8] */
/* @0xe8d8c ldrb r2, [r12] */
/* @0xe8d90 ldr r3, [r5, r3] */
/* @0xe8d94 cmp r2, #0 */
/* @0xe8d98 str r9, [r3] */
/* @0xe8d9c bne 0xe9004 <_Z6DoCalljPhPKhP6VMExec+0x4bc> */
/* @0xe8da0 ldr r3, [pc, #0x9bc] */
/* @0xe8da4 ldr r3, [r5, r3] */
/* @0xe8da8 ldrb r8, [r3] */
/* @0xe8dac cmp r8, #0 */
/* @0xe8db0 bne 0xe8b84 <_Z6DoCalljPhPKhP6VMExec+0x3c> */
/* @0xe8db4 cmp r6, #0 */
/* @0xe8db8 movne r5, r4 */
/* @0xe8dbc movne r9, r8 */
/* @0xe8dc0 movne r10, #5 */
/* @0xe8dc4 bne 0xe8de0 <_Z6DoCalljPhPKhP6VMExec+0x298> */
/* @0xe8dc8 b 0xe8ce4 <_Z6DoCalljPhPKhP6VMExec+0x19c> */
/* @0xe8dcc cmp r8, r6 */
/* @0xe8dd0 str r9, [r5, #0x8] */
/* @0xe8dd4 str r10, [r5, #0xc] */
/* @0xe8dd8 str r9, [r5], #16 */
/* @0xe8ddc beq 0xe8ce0 <_Z6DoCalljPhPKhP6VMExec+0x198> */
/* @0xe8de0 ldr r3, [r5, #0xc] */
/* @0xe8de4 add r8, r8, #1 */
/* @0xe8de8 sub r3, r3, #1 */
/* @0xe8dec bic r3, r3, #-16777216 */
/* @0xe8df0 bic r3, r3, #3 */
/* @0xe8df4 cmp r3, #0 */
/* @0xe8df8 bne 0xe8dcc <_Z6DoCalljPhPKhP6VMExec+0x284> */
/* @0xe8dfc mov r0, r5 */
/* @0xe8e00 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe8e04 b 0xe8dcc <_Z6DoCalljPhPKhP6VMExec+0x284> */
/* @0xe8e08 ldr r8, [r1] */
/* @0xe8e0c ldr r3, [r8, #0x48] */
/* @0xe8e10 cmp r3, #3 */
/* @0xe8e14 bne 0xe8bb4 <_Z6DoCalljPhPKhP6VMExec+0x6c> */
/* @0xe8e18 ldr r7, [r8, #0x64] */
/* @0xe8e1c uxth r6, r0 */
/* @0xe8e20 cmp r7, #0 */
/* @0xe8e24 beq 0xe9074 <_Z6DoCalljPhPKhP6VMExec+0x52c> */
/* @0xe8e28 mov r0, r7 */
/* @0xe8e2c mov r10, #0 */
/* @0xe8e30 add r12, r1, #32 */
/* @0xe8e34 str r10, [sp, #0x28] */
/* @0xe8e38 str r12, [sp, #0xc] */
/* @0xe8e3c str r10, [sp, #0x2c] */
/* @0xe8e40 str r10, [sp, #0x30] */
/* @0xe8e44 str r10, [sp, #0x34] */
/* @0xe8e48 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0xe8e4c ldr r3, [r0, #0x78] */
/* @0xe8e50 tst r3, #4 */
/* @0xe8e54 beq 0xe91a8 <_Z6DoCalljPhPKhP6VMExec+0x660> */
/* @0xe8e58 ldr r3, [r8, #0x88] */
/* @0xe8e5c cmp r3, #6 */
/* @0xe8e60 beq 0xe9200 <_Z6DoCalljPhPKhP6VMExec+0x6b8> */
/* @0xe8e64 ldr r3, [r4, #0x1c] */
/* @0xe8e68 bic r3, r3, #-16777216 */
/* @0xe8e6c cmp r3, #3 */
/* @0xe8e70 beq 0xe9044 <_Z6DoCalljPhPKhP6VMExec+0x4fc> */
/* @0xe8e74 cmp r3, #6 */
/* @0xe8e78 beq 0xe9044 <_Z6DoCalljPhPKhP6VMExec+0x4fc> */
/* @0xe8e7c mov r1, r11 */
/* @0xe8e80 add r0, sp, #40 */
/* @0xe8e84 bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0xe8e88 cmp r0, #1 */
/* @0xe8e8c beq 0xe9634 <_Z6DoCalljPhPKhP6VMExec+0xaec> */
/* @0xe8e90 ldr r4, [sp, #0x28] */
/* @0xe8e94 str r4, [sp, #0x14] */
/* @0xe8e98 ldr r3, [pc, #0x8c8] */
/* @0xe8e9c ldr r4, [r5, r3] */
/* @0xe8ea0 ldr r0, [r4] */
/* @0xe8ea4 cmn r0, #1 */
/* @0xe8ea8 movne r1, r0 */
/* @0xe8eac beq 0xe93fc <_Z6DoCalljPhPKhP6VMExec+0x8b4> */
/* @0xe8eb0 ldr r3, [r8, #0x4] */
/* @0xe8eb4 cmp r3, #0 */
/* @0xe8eb8 beq 0xe9464 <_Z6DoCalljPhPKhP6VMExec+0x91c> */
/* @0xe8ebc add r0, r3, r1, lsl #4 */
/* @0xe8ec0 vmov s12, r6 */
/* @0xe8ec4 ldm r0, {r2, r3} */
/* @0xe8ec8 vcvt.f64.s32 d7, s12 */
/* @0xe8ecc vmov d6, r2, r3 */
/* @0xe8ed0 vcmpe.f64 d6, d7 */
/* @0xe8ed4 vmrs APSR_nzcv, fpscr */
/* @0xe8ed8 ble 0xe8f40 <_Z6DoCalljPhPKhP6VMExec+0x3f8> */
/* @0xe8edc vcvt.s32.f64 s13, d6 */
/* @0xe8ee0 vmov r4, s13 */
/* @0xe8ee4 cmp r6, r4 */
/* @0xe8ee8 bge 0xe8f40 <_Z6DoCalljPhPKhP6VMExec+0x3f8> */
/* @0xe8eec ldr r1, [sp, #0xc] */
/* @0xe8ef0 rsb r3, r6, r4 */
/* @0xe8ef4 lsl r6, r6, #4 */
/* @0xe8ef8 sub r12, r1, r3, lsl #4 */
/* @0xe8efc mov r2, r6 */
/* @0xe8f00 mov r0, r12 */
/* @0xe8f04 bl 0xb6694 <memmove@plt> */
/* @0xe8f08 mov r1, #0 */
/* @0xe8f0c mov r2, #5 */
/* @0xe8f10 mov r12, r0 */
/* @0xe8f14 add r3, r0, r6 */
/* @0xe8f18 add r0, r0, r4, lsl #4 */
/* @0xe8f1c str r1, [r3] */
/* @0xe8f20 add r3, r3, #16 */
/* @0xe8f24 str r1, [r3, #-0xc] */
/* @0xe8f28 str r1, [r3, #-0x8] */
/* @0xe8f2c str r2, [r3, #-0x4] */
/* @0xe8f30 cmp r3, r0 */
/* @0xe8f34 bne 0xe8f1c <_Z6DoCalljPhPKhP6VMExec+0x3d4> */
/* @0xe8f38 mov r6, r4 */
/* @0xe8f3c str r12, [sp, #0xc] */
/* @0xe8f40 mov r0, r7 */
/* @0xe8f44 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0xe8f48 ldr r3, [r0, #0x78] */
/* @0xe8f4c ands r3, r3, #1 */
/* @0xe8f50 beq 0xe9050 <_Z6DoCalljPhPKhP6VMExec+0x508> */
/* @0xe8f54 mov r12, #0 */
/* @0xe8f58 mov r1, r8 */
/* @0xe8f5c add r0, sp, #56 */
/* @0xe8f60 str r12, [sp] */
/* @0xe8f64 mov r2, r6 */
/* @0xe8f68 ldr r3, [sp, #0xc] */
/* @0xe8f6c str r12, [sp, #0x40] */
/* @0xe8f70 mov r4, #0 */
/* @0xe8f74 mvn r12, #-16777216 */
/* @0xe8f78 mov r5, #0 */
/* @0xe8f7c str r12, [sp, #0x44] */
/* @0xe8f80 strd r4, r5, [sp, #56] */
/* @0xe8f84 bl 0x248b58 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b> */
/* @0xe8f88 ldr r12, [sp, #0x38] */
/* @0xe8f8c mov r1, r6 */
/* @0xe8f90 str r10, [sp] */
/* @0xe8f94 mov r0, r7 */
/* @0xe8f98 ldr r2, [sp, #0xc] */
/* @0xe8f9c mov r3, r9 */
/* @0xe8fa0 str r12, [sp, #0x4] */
/* @0xe8fa4 bl 0xe8588 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_> */
/* @0xe8fa8 mov r11, r0 */
/* @0xe8fac cmp r10, #0 */
/* @0xe8fb0 beq 0xe8fc8 <_Z6DoCalljPhPKhP6VMExec+0x480> */
/* @0xe8fb4 mov r0, r7 */
/* @0xe8fb8 bl 0x1dfba8 <_ZN7CScript7GetCodeEv> */
/* @0xe8fbc ldr r3, [r0, #0x78] */
/* @0xe8fc0 ands r3, r3, #2 */
/* @0xe8fc4 streq r3, [r9, #0xc] */
/* @0xe8fc8 ldr r3, [sp, #0x34] */
/* @0xe8fcc ldr r4, [sp, #0x14] */
/* @0xe8fd0 sub r3, r3, #1 */
/* @0xe8fd4 bic r3, r3, #-16777216 */
/* @0xe8fd8 bic r3, r3, #3 */
/* @0xe8fdc str r4, [r9, #0x14] */
/* @0xe8fe0 cmp r3, #0 */
/* @0xe8fe4 bne 0xe8b88 <_Z6DoCalljPhPKhP6VMExec+0x40> */
/* @0xe8fe8 add r0, sp, #40 */
/* @0xe8fec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe8ff0 b 0xe8b88 <_Z6DoCalljPhPKhP6VMExec+0x40> */
/* @0xe8ff4 ldr r0, [pc, #0x770] */
/* @0xe8ff8 add r0, pc, r0 */
/* @0xe8ffc bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe9000 b 0xe8b88 <_Z6DoCalljPhPKhP6VMExec+0x40> */
/* @0xe9004 ldr r3, [pc, #0x764] */
/* @0xe9008 ldr r0, [r5, r3] */
/* @0xe900c bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0xe9010 b 0xe8da0 <_Z6DoCalljPhPKhP6VMExec+0x258> */
/* @0xe9014 ldr r3, [pc, #0x754] */
/* @0xe9018 ldr r0, [r5, r3] */
/* @0xe901c bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0xe9020 b 0xe8d50 <_Z6DoCalljPhPKhP6VMExec+0x208> */
/* @0xe9024 mov r0, r1 */
/* @0xe9028 mov r1, #0 */
/* @0xe902c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xe9030 add r4, r4, #16 */
/* @0xe9034 sub r6, r6, #1 */
/* @0xe9038 add r0, r0, #99328 */
/* @0xe903c add r2, r0, #672 */
/* @0xe9040 b 0xe8c18 <_Z6DoCalljPhPKhP6VMExec+0xd0> */
/* @0xe9044 ldr r4, [r4, #0x10] */
/* @0xe9048 str r4, [sp, #0x14] */
/* @0xe904c b 0xe8e98 <_Z6DoCalljPhPKhP6VMExec+0x350> */
/* @0xe9050 str r3, [sp, #0x4] */
/* @0xe9054 mov r1, r6 */
/* @0xe9058 str r10, [sp] */
/* @0xe905c mov r0, r7 */
/* @0xe9060 ldr r2, [sp, #0xc] */
/* @0xe9064 mov r3, r9 */
/* @0xe9068 bl 0xe8588 <_Z12DoCallScriptP7CScriptiPhP6VMExecP12YYObjectBaseS5_> */
/* @0xe906c mov r11, r0 */
/* @0xe9070 b 0xe8fac <_Z6DoCalljPhPKhP6VMExec+0x464> */
/* @0xe9074 ldr r10, [r8, #0x68] */
/* @0xe9078 cmp r10, #0 */
/* @0xe907c beq 0xe9698 <_Z6DoCalljPhPKhP6VMExec+0xb50> */
/* @0xe9080 str r12, [sp, #0x34] */
/* @0xe9084 mvn r1, #-16777216 */
/* @0xe9088 str r7, [sp, #0x38] */
/* @0xe908c mov r2, #0 */
/* @0xe9090 str r7, [sp, #0x3c] */
/* @0xe9094 mov r3, #0 */
/* @0xe9098 str r7, [sp, #0x40] */
/* @0xe909c add r12, r4, #32 */
/* @0xe90a0 str r1, [sp, #0x44] */
/* @0xe90a4 ldr r1, [r8, #0x88] */
/* @0xe90a8 str r12, [sp, #0xc] */
/* @0xe90ac cmp r1, #6 */
/* @0xe90b0 str r7, [sp, #0x30] */
/* @0xe90b4 strd r2, r3, [sp, #40] */
/* @0xe90b8 beq 0xe947c <_Z6DoCalljPhPKhP6VMExec+0x934> */
/* @0xe90bc ldr r3, [r4, #0x1c] */
/* @0xe90c0 bic r3, r3, #-16777216 */
/* @0xe90c4 cmp r3, #3 */
/* @0xe90c8 beq 0xe91f0 <_Z6DoCalljPhPKhP6VMExec+0x6a8> */
/* @0xe90cc cmp r3, #6 */
/* @0xe90d0 beq 0xe91f0 <_Z6DoCalljPhPKhP6VMExec+0x6a8> */
/* @0xe90d4 mov r1, r11 */
/* @0xe90d8 add r0, sp, #56 */
/* @0xe90dc bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0xe90e0 cmp r0, #1 */
/* @0xe90e4 beq 0xe96a8 <_Z6DoCalljPhPKhP6VMExec+0xb60> */
/* @0xe90e8 ldr r7, [sp, #0x38] */
/* @0xe90ec mov r0, #0 */
/* @0xe90f0 add r8, sp, #40 */
/* @0xe90f4 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe90f8 ldr r4, [sp, #0xc] */
/* @0xe90fc ldr r2, [r9, #0x18] */
/* @0xe9100 mov r3, r6 */
/* @0xe9104 mov r1, r7 */
/* @0xe9108 mov r0, r8 */
/* @0xe910c str r4, [sp] */
/* @0xe9110 blx r10 */
/* @0xe9114 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xe9118 ldr r3, [sp, #0x44] */
/* @0xe911c sub r3, r3, #1 */
/* @0xe9120 bic r3, r3, #-16777216 */
/* @0xe9124 bic r3, r3, #3 */
/* @0xe9128 cmp r3, #0 */
/* @0xe912c beq 0xe9418 <_Z6DoCalljPhPKhP6VMExec+0x8d0> */
/* @0xe9130 ldr r2, [pc, #0x62c] */
/* @0xe9134 mov r3, #0 */
/* @0xe9138 mov r10, #5 */
/* @0xe913c str r3, [sp, #0x40] */
/* @0xe9140 str r3, [sp, #0x38] */
/* @0xe9144 str r10, [sp, #0x44] */
/* @0xe9148 ldr r3, [r5, r2] */
/* @0xe914c ldrb r5, [r3] */
/* @0xe9150 cmp r5, #0 */
/* @0xe9154 bne 0xe91f8 <_Z6DoCalljPhPKhP6VMExec+0x6b0> */
/* @0xe9158 cmp r6, #0 */
/* @0xe915c movne r7, r5 */
/* @0xe9160 ldrne r4, [sp, #0xc] */
/* @0xe9164 bne 0xe9180 <_Z6DoCalljPhPKhP6VMExec+0x638> */
/* @0xe9168 b 0xe91dc <_Z6DoCalljPhPKhP6VMExec+0x694> */
/* @0xe916c cmp r5, r6 */
/* @0xe9170 str r7, [r4, #0x8] */
/* @0xe9174 str r10, [r4, #0xc] */
/* @0xe9178 str r7, [r4], #16 */
/* @0xe917c beq 0xe91d0 <_Z6DoCalljPhPKhP6VMExec+0x688> */
/* @0xe9180 ldr r3, [r4, #0xc] */
/* @0xe9184 add r5, r5, #1 */
/* @0xe9188 sub r3, r3, #1 */
/* @0xe918c bic r3, r3, #-16777216 */
/* @0xe9190 bic r3, r3, #3 */
/* @0xe9194 cmp r3, #0 */
/* @0xe9198 bne 0xe916c <_Z6DoCalljPhPKhP6VMExec+0x624> */
/* @0xe919c mov r0, r4 */
/* @0xe91a0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe91a4 b 0xe916c <_Z6DoCalljPhPKhP6VMExec+0x624> */
/* @0xe91a8 ldr r3, [pc, #0x5c4] */
/* @0xe91ac ldr r3, [r5, r3] */
/* @0xe91b0 ldr r0, [r3] */
/* @0xe91b4 bl 0xd41e4 <_Z20YYAllocLocalStackNewi> */
/* @0xe91b8 ldr r3, [r8, #0x78] */
/* @0xe91bc cmp r3, #6 */
/* @0xe91c0 ldreq r3, [r8, #0x6c] */
/* @0xe91c4 mov r10, r0 */
/* @0xe91c8 streq r3, [r0, #0xc] */
/* @0xe91cc b 0xe8e58 <_Z6DoCalljPhPKhP6VMExec+0x310> */
/* @0xe91d0 ldr r12, [sp, #0xc] */
/* @0xe91d4 add r12, r12, r5, lsl #4 */
/* @0xe91d8 str r12, [sp, #0xc] */
/* @0xe91dc ldr r4, [sp, #0xc] */
/* @0xe91e0 mov r9, r8 */
/* @0xe91e4 ldm r9!, {r0, r1, r2, r3} */
/* @0xe91e8 sub r12, r4, #16 */
/* @0xe91ec b 0xe8cec <_Z6DoCalljPhPKhP6VMExec+0x1a4> */
/* @0xe91f0 ldr r7, [r4, #0x10] */
/* @0xe91f4 b 0xe90ec <_Z6DoCalljPhPKhP6VMExec+0x5a4> */
/* @0xe91f8 ldr r11, [sp, #0xc] */
/* @0xe91fc b 0xe8b88 <_Z6DoCalljPhPKhP6VMExec+0x40> */
/* @0xe9200 ldr r4, [r8, #0x7c] */
/* @0xe9204 mov r0, r8 */
/* @0xe9208 ldr r1, [pc, #0x568] */
/* @0xe920c add r1, pc, r1 */
/* @0xe9210 str r4, [sp, #0x14] */
/* @0xe9214 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0xe9218 cmp r0, #0 */
/* @0xe921c beq 0xe8e98 <_Z6DoCalljPhPKhP6VMExec+0x350> */
/* @0xe9220 ldr r3, [r0, #0xc] */
/* @0xe9224 cmp r3, #6 */
/* @0xe9228 bne 0xe8e98 <_Z6DoCalljPhPKhP6VMExec+0x350> */
/* @0xe922c ldr r0, [r0] */
/* @0xe9230 ldr r3, [r0, #0x4] */
/* @0xe9234 cmp r3, #0 */
/* @0xe9238 addne r0, r3, #16 */
/* @0xe923c beq 0xe9700 <_Z6DoCalljPhPKhP6VMExec+0xbb8> */
/* @0xe9240 ldr r2, [r0] */
/* @0xe9244 ldr r3, [r2, #0x24] */
/* @0xe9248 ldr r2, [r2, #0x4] */
/* @0xe924c sub r11, r3, #-268435455 */
/* @0xe9250 subs r3, r3, #1 */
/* @0xe9254 add r11, r2, r11, lsl #4 */
/* @0xe9258 bmi 0xe8e98 <_Z6DoCalljPhPKhP6VMExec+0x350> */
/* @0xe925c sub r11, r11, #16 */
/* @0xe9260 ldr r4, [sp, #0xc] */
/* @0xe9264 str r8, [sp, #0x18] */
/* @0xe9268 mov r8, r3 */
/* @0xe926c str r7, [sp, #0x1c] */
/* @0xe9270 mov r7, r11 */
/* @0xe9274 str r10, [sp, #0x10] */
/* @0xe9278 str r9, [sp, #0x20] */
/* @0xe927c str r5, [sp, #0x24] */
/* @0xe9280 ldr r0, [r4, #-0x4] */
/* @0xe9284 sub r9, r4, #16 */
/* @0xe9288 add r10, r7, #16 */
/* @0xe928c bic r1, r0, #-16777216 */
/* @0xe9290 mov r5, r9 */
/* @0xe9294 cmp r1, #1 */
/* @0xe9298 beq 0xe93d0 <_Z6DoCalljPhPKhP6VMExec+0x888> */
/* @0xe929c cmp r1, #2 */
/* @0xe92a0 bne 0xe92c4 <_Z6DoCalljPhPKhP6VMExec+0x77c> */
/* @0xe92a4 sub r1, r0, #1 */
/* @0xe92a8 bic r1, r1, #-16777216 */
/* @0xe92ac bic r1, r1, #3 */
/* @0xe92b0 cmp r1, #0 */
/* @0xe92b4 beq 0xe9470 <_Z6DoCalljPhPKhP6VMExec+0x928> */
/* @0xe92b8 mov r0, #0 */
/* @0xe92bc mov r12, #5 */
/* @0xe92c0 stmdb r4, {r0, r12} */
/* @0xe92c4 mov r1, #0 */
/* @0xe92c8 str r1, [r4, #-0x10] */
/* @0xe92cc ldr r1, [r7, #0x1c] */
/* @0xe92d0 str r1, [r4, #-0x4] */
/* @0xe92d4 ldr r1, [r7, #0x18] */
/* @0xe92d8 str r1, [r4, #-0x8] */
/* @0xe92dc ldr r1, [r7, #0x1c] */
/* @0xe92e0 bic r1, r1, #-16777216 */
/* @0xe92e4 cmp r1, #14 */
/* @0xe92e8 addls pc, pc, r1, lsl #2 */
/* @0xe92ec b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe92f0 b 0xe9364 <_Z6DoCalljPhPKhP6VMExec+0x81c> */
/* @0xe92f4 b 0xe93c0 <_Z6DoCalljPhPKhP6VMExec+0x878> */
/* @0xe92f8 b 0xe9394 <_Z6DoCalljPhPKhP6VMExec+0x84c> */
/* @0xe92fc b 0xe932c <_Z6DoCalljPhPKhP6VMExec+0x7e4> */
/* @0xe9300 b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9304 b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9308 b 0xe9370 <_Z6DoCalljPhPKhP6VMExec+0x828> */
/* @0xe930c b 0xe932c <_Z6DoCalljPhPKhP6VMExec+0x7e4> */
/* @0xe9310 b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9314 b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9318 b 0xe9364 <_Z6DoCalljPhPKhP6VMExec+0x81c> */
/* @0xe931c b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9320 b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9324 b 0xe9364 <_Z6DoCalljPhPKhP6VMExec+0x81c> */
/* @0xe9328 b 0xe932c <_Z6DoCalljPhPKhP6VMExec+0x7e4> */
/* @0xe932c ldr r1, [r7, #0x10] */
/* @0xe9330 str r1, [r4, #-0x10] */
/* @0xe9334 subs r8, r8, #1 */
/* @0xe9338 add r6, r6, #1 */
/* @0xe933c sub r7, r7, #16 */
/* @0xe9340 mov r4, r9 */
/* @0xe9344 bpl 0xe9280 <_Z6DoCalljPhPKhP6VMExec+0x738> */
/* @0xe9348 str r5, [sp, #0xc] */
/* @0xe934c ldr r10, [sp, #0x10] */
/* @0xe9350 ldr r8, [sp, #0x18] */
/* @0xe9354 ldr r7, [sp, #0x1c] */
/* @0xe9358 ldr r9, [sp, #0x20] */
/* @0xe935c ldr r5, [sp, #0x24] */
/* @0xe9360 b 0xe8e98 <_Z6DoCalljPhPKhP6VMExec+0x350> */
/* @0xe9364 ldm r10, {r0, r1} */
/* @0xe9368 stm r9, {r0, r1} */
/* @0xe936c b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9370 ldr r1, [r7, #0x10] */
/* @0xe9374 str r1, [r4, #-0x10] */
/* @0xe9378 ldr r1, [r7, #0x10] */
/* @0xe937c cmp r1, #0 */
/* @0xe9380 beq 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9384 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe9388 ldr r1, [r7, #0x10] */
/* @0xe938c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe9390 b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe9394 ldr r1, [r7, #0x10] */
/* @0xe9398 cmp r1, #0 */
/* @0xe939c str r1, [r4, #-0x10] */
/* @0xe93a0 beq 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe93a4 ldr r12, [r1, #0x8] */
/* @0xe93a8 ldr r0, [r1] */
/* @0xe93ac cmp r12, #0 */
/* @0xe93b0 streq r9, [r1, #0x8] */
/* @0xe93b4 add r0, r0, #1 */
/* @0xe93b8 str r0, [r1] */
/* @0xe93bc b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe93c0 ldr r0, [r7, #0x10] */
/* @0xe93c4 bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */
/* @0xe93c8 str r0, [r4, #-0x10] */
/* @0xe93cc b 0xe9334 <_Z6DoCalljPhPKhP6VMExec+0x7ec> */
/* @0xe93d0 ldr r11, [r4, #-0x10] */
/* @0xe93d4 cmp r11, #0 */
/* @0xe93d8 beq 0xe92c4 <_Z6DoCalljPhPKhP6VMExec+0x77c> */
/* @0xe93dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe93e0 ldr r12, [r11, #0x4] */
/* @0xe93e4 sub r12, r12, #1 */
/* @0xe93e8 str r12, [r11, #0x4] */
/* @0xe93ec cmp r12, #0 */
/* @0xe93f0 beq 0xe9424 <_Z6DoCalljPhPKhP6VMExec+0x8dc> */
/* @0xe93f4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe93f8 b 0xe92c4 <_Z6DoCalljPhPKhP6VMExec+0x77c> */
/* @0xe93fc ldr r1, [pc, #0x378] */
/* @0xe9400 mov r0, r8 */
/* @0xe9404 add r1, pc, r1 */
/* @0xe9408 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0xe940c mov r1, r0 */
/* @0xe9410 str r0, [r4] */
/* @0xe9414 b 0xe8eb0 <_Z6DoCalljPhPKhP6VMExec+0x368> */
/* @0xe9418 add r0, sp, #56 */
/* @0xe941c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe9420 b 0xe9130 <_Z6DoCalljPhPKhP6VMExec+0x5e8> */
/* @0xe9424 ldr r0, [r11] */
/* @0xe9428 str r12, [sp, #0x8] */
/* @0xe942c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9430 ldr r12, [sp, #0x8] */
/* @0xe9434 str r12, [r11] */
/* @0xe9438 str r12, [r11, #0x8] */
/* @0xe943c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe9440 ldr r12, [r11, #0x4] */
/* @0xe9444 sub r12, r12, #1 */
/* @0xe9448 str r12, [r11, #0x4] */
/* @0xe944c cmp r12, #0 */
/* @0xe9450 beq 0xe9658 <_Z6DoCalljPhPKhP6VMExec+0xb10> */
/* @0xe9454 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe9458 mov r0, r11 */
/* @0xe945c bl 0x27d1d0 <_ZdlPv> */
/* @0xe9460 b 0xe93f4 <_Z6DoCalljPhPKhP6VMExec+0x8ac> */
/* @0xe9464 mov r0, r8 */
/* @0xe9468 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe946c b 0xe8ec0 <_Z6DoCalljPhPKhP6VMExec+0x378> */
/* @0xe9470 mov r0, r9 */
/* @0xe9474 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe9478 b 0xe92b8 <_Z6DoCalljPhPKhP6VMExec+0x770> */
/* @0xe947c ldr r1, [pc, #0x2fc] */
/* @0xe9480 mov r0, r8 */
/* @0xe9484 ldr r7, [r8, #0x7c] */
/* @0xe9488 add r1, pc, r1 */
/* @0xe948c bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0xe9490 cmp r0, #0 */
/* @0xe9494 beq 0xe90ec <_Z6DoCalljPhPKhP6VMExec+0x5a4> */
/* @0xe9498 ldr r3, [r0, #0xc] */
/* @0xe949c cmp r3, #6 */
/* @0xe94a0 bne 0xe90ec <_Z6DoCalljPhPKhP6VMExec+0x5a4> */
/* @0xe94a4 ldr r0, [r0] */
/* @0xe94a8 ldr r3, [r0, #0x4] */
/* @0xe94ac cmp r3, #0 */
/* @0xe94b0 addne r0, r3, #16 */
/* @0xe94b4 beq 0xe970c <_Z6DoCalljPhPKhP6VMExec+0xbc4> */
/* @0xe94b8 ldr r3, [r0] */
/* @0xe94bc ldr r2, [r3, #0x24] */
/* @0xe94c0 ldr r3, [r3, #0x4] */
/* @0xe94c4 sub r11, r2, #-268435455 */
/* @0xe94c8 subs r8, r2, #1 */
/* @0xe94cc add r11, r3, r11, lsl #4 */
/* @0xe94d0 bmi 0xe90ec <_Z6DoCalljPhPKhP6VMExec+0x5a4> */
/* @0xe94d4 ldr r4, [sp, #0xc] */
/* @0xe94d8 sub r11, r11, #16 */
/* @0xe94dc str r7, [sp, #0x10] */
/* @0xe94e0 mov r7, r8 */
/* @0xe94e4 str r5, [sp, #0x14] */
/* @0xe94e8 ldr r0, [r4, #-0x4] */
/* @0xe94ec sub r5, r4, #16 */
/* @0xe94f0 add r8, r11, #16 */
/* @0xe94f4 str r5, [sp, #0xc] */
/* @0xe94f8 bic r2, r0, #-16777216 */
/* @0xe94fc cmp r2, #1 */
/* @0xe9500 beq 0xe9628 <_Z6DoCalljPhPKhP6VMExec+0xae0> */
/* @0xe9504 cmp r2, #2 */
/* @0xe9508 bne 0xe952c <_Z6DoCalljPhPKhP6VMExec+0x9e4> */
/* @0xe950c sub r2, r0, #1 */
/* @0xe9510 bic r2, r2, #-16777216 */
/* @0xe9514 bic r2, r2, #3 */
/* @0xe9518 cmp r2, #0 */
/* @0xe951c beq 0xe964c <_Z6DoCalljPhPKhP6VMExec+0xb04> */
/* @0xe9520 mov r0, #0 */
/* @0xe9524 mov r1, #5 */
/* @0xe9528 stmdb r4, {r0, r1} */
/* @0xe952c mov r2, #0 */
/* @0xe9530 str r2, [r4, #-0x10] */
/* @0xe9534 ldr r2, [r11, #0x1c] */
/* @0xe9538 str r2, [r4, #-0x4] */
/* @0xe953c ldr r2, [r11, #0x18] */
/* @0xe9540 str r2, [r4, #-0x8] */
/* @0xe9544 ldr r2, [r11, #0x1c] */
/* @0xe9548 bic r2, r2, #-16777216 */
/* @0xe954c cmp r2, #14 */
/* @0xe9550 addls pc, pc, r2, lsl #2 */
/* @0xe9554 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe9558 b 0xe95bc <_Z6DoCalljPhPKhP6VMExec+0xa74> */
/* @0xe955c b 0xe9618 <_Z6DoCalljPhPKhP6VMExec+0xad0> */
/* @0xe9560 b 0xe95ec <_Z6DoCalljPhPKhP6VMExec+0xaa4> */
/* @0xe9564 b 0xe9594 <_Z6DoCalljPhPKhP6VMExec+0xa4c> */
/* @0xe9568 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe956c b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe9570 b 0xe95c8 <_Z6DoCalljPhPKhP6VMExec+0xa80> */
/* @0xe9574 b 0xe9594 <_Z6DoCalljPhPKhP6VMExec+0xa4c> */
/* @0xe9578 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe957c b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe9580 b 0xe95bc <_Z6DoCalljPhPKhP6VMExec+0xa74> */
/* @0xe9584 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe9588 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe958c b 0xe95bc <_Z6DoCalljPhPKhP6VMExec+0xa74> */
/* @0xe9590 b 0xe9594 <_Z6DoCalljPhPKhP6VMExec+0xa4c> */
/* @0xe9594 ldr r2, [r11, #0x10] */
/* @0xe9598 str r2, [r4, #-0x10] */
/* @0xe959c subs r7, r7, #1 */
/* @0xe95a0 add r6, r6, #1 */
/* @0xe95a4 sub r11, r11, #16 */
/* @0xe95a8 mov r4, r5 */
/* @0xe95ac bpl 0xe94e8 <_Z6DoCalljPhPKhP6VMExec+0x9a0> */
/* @0xe95b0 ldr r7, [sp, #0x10] */
/* @0xe95b4 ldr r5, [sp, #0x14] */
/* @0xe95b8 b 0xe90ec <_Z6DoCalljPhPKhP6VMExec+0x5a4> */
/* @0xe95bc ldm r8, {r0, r2} */
/* @0xe95c0 stm r5, {r0, r2} */
/* @0xe95c4 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe95c8 ldr r2, [r11, #0x10] */
/* @0xe95cc str r2, [r4, #-0x10] */
/* @0xe95d0 ldr r2, [r11, #0x10] */
/* @0xe95d4 cmp r2, #0 */
/* @0xe95d8 beq 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe95dc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe95e0 ldr r1, [r11, #0x10] */
/* @0xe95e4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe95e8 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe95ec ldr r2, [r11, #0x10] */
/* @0xe95f0 cmp r2, #0 */
/* @0xe95f4 str r2, [r4, #-0x10] */
/* @0xe95f8 beq 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe95fc ldr r0, [r2, #0x8] */
/* @0xe9600 ldr r1, [r2] */
/* @0xe9604 cmp r0, #0 */
/* @0xe9608 streq r5, [r2, #0x8] */
/* @0xe960c add r1, r1, #1 */
/* @0xe9610 str r1, [r2] */
/* @0xe9614 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe9618 ldr r0, [r11, #0x10] */
/* @0xe961c bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */
/* @0xe9620 str r0, [r4, #-0x10] */
/* @0xe9624 b 0xe959c <_Z6DoCalljPhPKhP6VMExec+0xa54> */
/* @0xe9628 ldr r0, [r4, #-0x10] */
/* @0xe962c bl 0xdc42c <_ZN9_RefThingIPKcE6removeEPS2_> */
/* @0xe9630 b 0xe952c <_Z6DoCalljPhPKhP6VMExec+0x9e4> */
/* @0xe9634 ldr r1, [pc, #0x148] */
/* @0xe9638 mov r0, r9 */
/* @0xe963c ldr r2, [r4, #0x1c] */
/* @0xe9640 add r1, pc, r1 */
/* @0xe9644 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe9648 b 0xe8e90 <_Z6DoCalljPhPKhP6VMExec+0x348> */
/* @0xe964c mov r0, r5 */
/* @0xe9650 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe9654 b 0xe9520 <_Z6DoCalljPhPKhP6VMExec+0x9d8> */
/* @0xe9658 ldr r0, [r11] */
/* @0xe965c str r12, [sp, #0x8] */
/* @0xe9660 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9664 ldr r12, [sp, #0x8] */
/* @0xe9668 str r12, [r11] */
/* @0xe966c str r12, [r11, #0x8] */
/* @0xe9670 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe9674 ldr r12, [r11, #0x4] */
/* @0xe9678 sub r12, r12, #1 */
/* @0xe967c str r12, [r11, #0x4] */
/* @0xe9680 cmp r12, #0 */
/* @0xe9684 beq 0xe96c0 <_Z6DoCalljPhPKhP6VMExec+0xb78> */
/* @0xe9688 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe968c mov r0, r11 */
/* @0xe9690 bl 0x27d1d0 <_ZdlPv> */
/* @0xe9694 b 0xe9454 <_Z6DoCalljPhPKhP6VMExec+0x90c> */
/* @0xe9698 ldr r0, [pc, #0xe8] */
/* @0xe969c add r0, pc, r0 */
/* @0xe96a0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe96a4 b 0xe8b88 <_Z6DoCalljPhPKhP6VMExec+0x40> */
/* @0xe96a8 ldr r1, [pc, #0xdc] */
/* @0xe96ac mov r0, r9 */
/* @0xe96b0 ldr r2, [r4, #0x1c] */
/* @0xe96b4 add r1, pc, r1 */
/* @0xe96b8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe96bc b 0xe90e8 <_Z6DoCalljPhPKhP6VMExec+0x5a0> */
/* @0xe96c0 ldr r0, [r11] */
/* @0xe96c4 str r12, [sp, #0x8] */
/* @0xe96c8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe96cc ldr r12, [sp, #0x8] */
/* @0xe96d0 str r12, [r11] */
/* @0xe96d4 str r12, [r11, #0x8] */
/* @0xe96d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe96dc ldr r12, [r11, #0x4] */
/* @0xe96e0 sub r12, r12, #1 */
/* @0xe96e4 str r12, [r11, #0x4] */
/* @0xe96e8 cmp r12, #0 */
/* @0xe96ec beq 0xe9718 <_Z6DoCalljPhPKhP6VMExec+0xbd0> */
/* @0xe96f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe96f4 mov r0, r11 */
/* @0xe96f8 bl 0x27d1d0 <_ZdlPv> */
/* @0xe96fc b 0xe9688 <_Z6DoCalljPhPKhP6VMExec+0xb40> */
/* @0xe9700 mov r1, #1 */
/* @0xe9704 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe9708 b 0xe9240 <_Z6DoCalljPhPKhP6VMExec+0x6f8> */
/* @0xe970c mov r1, #1 */
/* @0xe9710 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xe9714 b 0xe94b8 <_Z6DoCalljPhPKhP6VMExec+0x970> */
/* @0xe9718 ldr r0, [r11] */
/* @0xe971c str r12, [sp, #0x8] */
/* @0xe9720 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9724 ldr r12, [sp, #0x8] */
/* @0xe9728 mov r0, r11 */
/* @0xe972c str r12, [r11] */
/* @0xe9730 str r12, [r11, #0x8] */
/* @0xe9734 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xe9738 mov r0, r11 */
/* @0xe973c bl 0x27d1d0 <_ZdlPv> */
/* @0xe9740 b 0xe96f0 <_Z6DoCalljPhPKhP6VMExec+0xba8> */
/* @0xe9744 eorseq r9, r0, r12, ror #1 */
/* @0xe9748 eoreq r11, r4, r8, asr sp */
/* @0xe974c .word 0xffffc0fc */
/* @0xe9750 .word 0x0024bcf0 */
/* @0xe9754 .word 0xffffbf58 */
/* @0xe9758 .word 0xffffbec8 */
/* @0xe975c .word 0xffffbf18 */
/* @0xe9760 .word 0xffffbee0 */
/* @0xe9764 .word 0xffffc0cc */
/* @0xe9768 .word 0xffffc05c */
/* @0xe976c eoreq r11, r4, r12, lsr #17 */
/* @0xe9770 .word 0xffffbf1c */
/* @0xe9774 .word 0xffffc104 */
/* @0xe9778 eoreq r11, r4, r0, asr #12 */
/* @0xe977c eoreq r7, r4, r8, ror #8 */
/* @0xe9780 eoreq r11, r4, r4, asr #7 */
/* @0xe9784 eoreq r11, r4, r12, lsl r2 */
/* @0xe9788 .word 0x0024b1f0 */
/* @0xe978c eoreq r11, r4, r8, lsr #3 */

/* ── FUNC 0xe9790 · YYGML_CallExtensionFunction(CInstance*, CInstance*, YYRValue&, int, int, YYRValue**) · size=1096 · insn=274 */
/* @0xe9790 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe9794 add r11, sp, #32 */
/* @0xe9798 ldr r0, [pc, #0x42c] */
/* @0xe979c sub sp, sp, #28 */
/* @0xe97a0 mov r7, r3 */
/* @0xe97a4 ldr r0, [pc, r0] */
/* @0xe97a8 lsl r3, r3, #4 */
/* @0xe97ac str r2, [r11, #-0x38] */
/* @0xe97b0 add r2, r3, #8 */
/* @0xe97b4 sub sp, sp, r2 */
/* @0xe97b8 mov r2, r3 */
/* @0xe97bc ldr r3, [r0] */
/* @0xe97c0 mov r1, #0 */
/* @0xe97c4 str r0, [r11, #-0x34] */
/* @0xe97c8 mov r0, sp */
/* @0xe97cc str sp, [r11, #-0x30] */
/* @0xe97d0 ldr r4, [r11, #0x8] */
/* @0xe97d4 str r3, [r11, #-0x28] */
/* @0xe97d8 bl 0xb65b0 <memset@plt> */
/* @0xe97dc cmp r7, #0 */
/* @0xe97e0 ble 0xe98bc <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x12c> */
/* @0xe97e4 ldr r2, [r11, #-0x30] */
/* @0xe97e8 sub r8, r4, #4 */
/* @0xe97ec mov r10, #0 */
/* @0xe97f0 add r9, r2, #12 */
/* @0xe97f4 mov r6, r2 */
/* @0xe97f8 ldr r2, [r6, #0xc] */
/* @0xe97fc ldr r4, [r8, #0x4]! */
/* @0xe9800 bic r3, r2, #-16777216 */
/* @0xe9804 cmp r3, #1 */
/* @0xe9808 beq 0xe99c4 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x234> */
/* @0xe980c cmp r3, #2 */
/* @0xe9810 bne 0xe9838 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0xa8> */
/* @0xe9814 sub r2, r2, #1 */
/* @0xe9818 bic r2, r2, #-16777216 */
/* @0xe981c bic r2, r2, #3 */
/* @0xe9820 cmp r2, #0 */
/* @0xe9824 beq 0xe9a58 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x2c8> */
/* @0xe9828 mov r0, #0 */
/* @0xe982c mov r1, #5 */
/* @0xe9830 str r0, [r6, #0x8] */
/* @0xe9834 str r1, [r6, #0xc] */
/* @0xe9838 mov r2, #0 */
/* @0xe983c str r2, [r9, #-0xc] */
/* @0xe9840 ldr r3, [r4, #0xc] */
/* @0xe9844 str r3, [r6, #0xc] */
/* @0xe9848 ldr r3, [r4, #0x8] */
/* @0xe984c str r3, [r6, #0x8] */
/* @0xe9850 ldr r3, [r4, #0xc] */
/* @0xe9854 bic r3, r3, #-16777216 */
/* @0xe9858 cmp r3, #14 */
/* @0xe985c addls pc, pc, r3, lsl #2 */
/* @0xe9860 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe9864 b 0xe9984 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x1f4> */
/* @0xe9868 b 0xe996c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x1dc> */
/* @0xe986c b 0xe9940 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x1b0> */
/* @0xe9870 b 0xe98a0 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x110> */
/* @0xe9874 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe9878 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe987c b 0xe99a0 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x210> */
/* @0xe9880 b 0xe98a0 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x110> */
/* @0xe9884 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe9888 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe988c b 0xe9990 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x200> */
/* @0xe9890 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe9894 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe9898 b 0xe9984 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x1f4> */
/* @0xe989c b 0xe98a0 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x110> */
/* @0xe98a0 ldr r3, [r4] */
/* @0xe98a4 str r3, [r9, #-0xc] */
/* @0xe98a8 add r10, r10, #1 */
/* @0xe98ac add r9, r9, #16 */
/* @0xe98b0 cmp r10, r7 */
/* @0xe98b4 add r6, r6, #16 */
/* @0xe98b8 bne 0xe97f8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x68> */
/* @0xe98bc ldr r3, [pc, #0x30c] */
/* @0xe98c0 ldr r1, [r11, #0x4] */
/* @0xe98c4 ldr r3, [pc, r3] */
/* @0xe98c8 sub r0, r1, #499712 */
/* @0xe98cc ldr r3, [r3] */
/* @0xe98d0 sub r0, r0, #288 */
/* @0xe98d4 ldr r3, [r3, r0, lsl #2] */
/* @0xe98d8 cmp r3, #0 */
/* @0xe98dc beq 0xe9aa4 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x314> */
/* @0xe98e0 cmp r3, #2 */
/* @0xe98e4 beq 0xe9b08 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x378> */
/* @0xe98e8 cmp r7, #0 */
/* @0xe98ec ble 0xe9a38 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x2a8> */
/* @0xe98f0 mov r4, #0 */
/* @0xe98f4 ldr r9, [r11, #-0x30] */
/* @0xe98f8 mov r5, r4 */
/* @0xe98fc mov r6, #5 */
/* @0xe9900 b 0xe991c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x18c> */
/* @0xe9904 add r4, r4, #1 */
/* @0xe9908 str r5, [r9, #0x8] */
/* @0xe990c cmp r4, r7 */
/* @0xe9910 str r6, [r9, #0xc] */
/* @0xe9914 str r5, [r9], #16 */
/* @0xe9918 beq 0xe9a38 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x2a8> */
/* @0xe991c ldr r3, [r9, #0xc] */
/* @0xe9920 sub r3, r3, #1 */
/* @0xe9924 bic r3, r3, #-16777216 */
/* @0xe9928 bic r3, r3, #3 */
/* @0xe992c cmp r3, #0 */
/* @0xe9930 bne 0xe9904 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x174> */
/* @0xe9934 mov r0, r9 */
/* @0xe9938 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe993c b 0xe9904 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x174> */
/* @0xe9940 ldr r3, [r4] */
/* @0xe9944 cmp r3, #0 */
/* @0xe9948 str r3, [r9, #-0xc] */
/* @0xe994c beq 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe9950 ldr r1, [r3, #0x8] */
/* @0xe9954 ldr r2, [r3] */
/* @0xe9958 cmp r1, #0 */
/* @0xe995c streq r6, [r3, #0x8] */
/* @0xe9960 add r2, r2, #1 */
/* @0xe9964 str r2, [r3] */
/* @0xe9968 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe996c ldr r3, [r4] */
/* @0xe9970 cmp r3, #0 */
/* @0xe9974 ldrne r2, [r3, #0x4] */
/* @0xe9978 addne r2, r2, #1 */
/* @0xe997c strne r2, [r3, #0x4] */
/* @0xe9980 b 0xe98a4 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x114> */
/* @0xe9984 ldm r4, {r2, r3} */
/* @0xe9988 strd r2, r3, [r9, #-12] */
/* @0xe998c b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe9990 ldm r4, {r2, r3} */
/* @0xe9994 str r2, [r9, #-0xc] */
/* @0xe9998 str r3, [r9, #-0x8] */
/* @0xe999c b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe99a0 ldr r3, [r4] */
/* @0xe99a4 str r3, [r9, #-0xc] */
/* @0xe99a8 ldr r3, [r4] */
/* @0xe99ac cmp r3, #0 */
/* @0xe99b0 beq 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe99b4 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe99b8 ldr r1, [r4] */
/* @0xe99bc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe99c0 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118> */
/* @0xe99c4 ldr r5, [r9, #-0xc] */
/* @0xe99c8 cmp r5, #0 */
/* @0xe99cc beq 0xe99ec <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x25c> */
/* @0xe99d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe99d4 ldr r3, [r5, #0x4] */
/* @0xe99d8 sub r3, r3, #1 */
/* @0xe99dc str r3, [r5, #0x4] */
/* @0xe99e0 cmp r3, #0 */
/* @0xe99e4 beq 0xe99f8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x268> */
/* @0xe99e8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe99ec mov r3, #0 */
/* @0xe99f0 str r3, [r9, #-0xc] */
/* @0xe99f4 b 0xe9838 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0xa8> */
/* @0xe99f8 ldr r0, [r5] */
/* @0xe99fc str r3, [r11, #-0x3c] */
/* @0xe9a00 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9a04 ldr r3, [r11, #-0x3c] */
/* @0xe9a08 str r3, [r5] */
/* @0xe9a0c str r3, [r5, #0x8] */
/* @0xe9a10 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe9a14 ldr r3, [r5, #0x4] */
/* @0xe9a18 sub r3, r3, #1 */
/* @0xe9a1c str r3, [r5, #0x4] */
/* @0xe9a20 cmp r3, #0 */
/* @0xe9a24 beq 0xe9a64 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x2d4> */
/* @0xe9a28 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe9a2c mov r0, r5 */
/* @0xe9a30 bl 0x27d1d0 <_ZdlPv> */
/* @0xe9a34 b 0xe99e8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x258> */
/* @0xe9a38 ldr r1, [r11, #-0x34] */
/* @0xe9a3c ldr r2, [r11, #-0x28] */
/* @0xe9a40 ldr r0, [r11, #-0x38] */
/* @0xe9a44 ldr r3, [r1] */
/* @0xe9a48 cmp r2, r3 */
/* @0xe9a4c bne 0xe9bc8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x438> */
/* @0xe9a50 sub sp, r11, #32 */
/* @0xe9a54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xe9a58 mov r0, r6 */
/* @0xe9a5c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe9a60 b 0xe9828 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x98> */
/* @0xe9a64 ldr r0, [r5] */
/* @0xe9a68 str r3, [r11, #-0x3c] */
/* @0xe9a6c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9a70 ldr r3, [r11, #-0x3c] */
/* @0xe9a74 str r3, [r5] */
/* @0xe9a78 str r3, [r5, #0x8] */
/* @0xe9a7c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe9a80 ldr r3, [r5, #0x4] */
/* @0xe9a84 sub r3, r3, #1 */
/* @0xe9a88 str r3, [r5, #0x4] */
/* @0xe9a8c cmp r3, #0 */
/* @0xe9a90 beq 0xe9ac8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x338> */
/* @0xe9a94 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe9a98 mov r0, r5 */
/* @0xe9a9c bl 0x27d1d0 <_ZdlPv> */
/* @0xe9aa0 b 0xe9a28 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x298> */
/* @0xe9aa4 ldr r12, [pc, #0x128] */
/* @0xe9aa8 mov r1, r7 */
/* @0xe9aac ldr r2, [r11, #-0x30] */
/* @0xe9ab0 ldr r12, [pc, r12] */
/* @0xe9ab4 ldr r3, [r11, #-0x38] */
/* @0xe9ab8 ldr r12, [r12] */
/* @0xe9abc ldr r0, [r12, r0, lsl #2] */
/* @0xe9ac0 bl 0x212b10 <_Z8DLL_CalliiP6RValueS0_> */
/* @0xe9ac4 b 0xe98e8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x158> */
/* @0xe9ac8 ldr r0, [r5] */
/* @0xe9acc str r3, [r11, #-0x3c] */
/* @0xe9ad0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9ad4 ldr r3, [r11, #-0x3c] */
/* @0xe9ad8 str r3, [r5] */
/* @0xe9adc str r3, [r5, #0x8] */
/* @0xe9ae0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe9ae4 ldr r3, [r5, #0x4] */
/* @0xe9ae8 sub r3, r3, #1 */
/* @0xe9aec str r3, [r5, #0x4] */
/* @0xe9af0 cmp r3, #0 */
/* @0xe9af4 beq 0xe9b1c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x38c> */
/* @0xe9af8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe9afc mov r0, r5 */
/* @0xe9b00 bl 0x27d1d0 <_ZdlPv> */
/* @0xe9b04 b 0xe9a94 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x304> */
/* @0xe9b08 mov r1, r7 */
/* @0xe9b0c ldr r2, [r11, #-0x30] */
/* @0xe9b10 ldr r3, [r11, #-0x38] */
/* @0xe9b14 bl 0x214a18 <_Z8Ext_CalliiP6RValueS0_> */
/* @0xe9b18 b 0xe98e8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x158> */
/* @0xe9b1c ldr r0, [r5] */
/* @0xe9b20 str r3, [r11, #-0x3c] */
/* @0xe9b24 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9b28 ldr r3, [r11, #-0x3c] */
/* @0xe9b2c str r3, [r5] */
/* @0xe9b30 str r3, [r5, #0x8] */
/* @0xe9b34 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe9b38 ldr r3, [r5, #0x4] */
/* @0xe9b3c sub r3, r3, #1 */
/* @0xe9b40 str r3, [r5, #0x4] */
/* @0xe9b44 cmp r3, #0 */
/* @0xe9b48 beq 0xe9b5c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x3cc> */
/* @0xe9b4c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe9b50 mov r0, r5 */
/* @0xe9b54 bl 0x27d1d0 <_ZdlPv> */
/* @0xe9b58 b 0xe9af8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x368> */
/* @0xe9b5c ldr r0, [r5] */
/* @0xe9b60 str r3, [r11, #-0x3c] */
/* @0xe9b64 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9b68 ldr r3, [r11, #-0x3c] */
/* @0xe9b6c str r3, [r5] */
/* @0xe9b70 str r3, [r5, #0x8] */
/* @0xe9b74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe9b78 ldr r3, [r5, #0x4] */
/* @0xe9b7c sub r3, r3, #1 */
/* @0xe9b80 str r3, [r5, #0x4] */
/* @0xe9b84 cmp r3, #0 */
/* @0xe9b88 beq 0xe9b9c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x40c> */
/* @0xe9b8c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe9b90 mov r0, r5 */
/* @0xe9b94 bl 0x27d1d0 <_ZdlPv> */
/* @0xe9b98 b 0xe9b4c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x3bc> */
/* @0xe9b9c ldr r0, [r5] */
/* @0xe9ba0 str r3, [r11, #-0x3c] */
/* @0xe9ba4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9ba8 ldr r3, [r11, #-0x3c] */
/* @0xe9bac mov r0, r5 */
/* @0xe9bb0 str r3, [r5] */
/* @0xe9bb4 str r3, [r5, #0x8] */
/* @0xe9bb8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xe9bbc mov r0, r5 */
/* @0xe9bc0 bl 0x27d1d0 <_ZdlPv> */
/* @0xe9bc4 b 0xe9b8c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x3fc> */
/* @0xe9bc8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xe9bcc eorseq r4, r0, r12, lsr #3 */
/* @0xe9bd0 mlaseq r0, r4, r4, r4 */
/* @0xe9bd4 eorseq r4, r0, r12, lsr #5 */

/* ── FUNC 0xe9bd8 · VM::PokeDSGrid(int, int, int, RValue&) · size=688 · insn=172 */
/* @0xe9bd8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xe9bdc sub sp, sp, #8 */
/* @0xe9be0 mov r4, r0 */
/* @0xe9be4 add r0, sp, #4 */
/* @0xe9be8 mov r5, r1 */
/* @0xe9bec mov r6, r2 */
/* @0xe9bf0 mov r7, r3 */
/* @0xe9bf4 bl 0x10026c <_Z11GetTheGridsRi> */
/* @0xe9bf8 cmp r4, #0 */
/* @0xe9bfc blt 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154> */
/* @0xe9c00 ldr r1, [sp, #0x4] */
/* @0xe9c04 cmp r4, r1 */
/* @0xe9c08 bge 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154> */
/* @0xe9c0c ldr r4, [r0, r4, lsl #2] */
/* @0xe9c10 cmp r4, #0 */
/* @0xe9c14 beq 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154> */
/* @0xe9c18 cmp r5, #0 */
/* @0xe9c1c blt 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154> */
/* @0xe9c20 ldr r3, [r4, #0x4] */
/* @0xe9c24 cmp r5, r3 */
/* @0xe9c28 bge 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154> */
/* @0xe9c2c cmp r6, #0 */
/* @0xe9c30 blt 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154> */
/* @0xe9c34 ldr r2, [r4, #0x8] */
/* @0xe9c38 cmp r6, r2 */
/* @0xe9c3c bge 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154> */
/* @0xe9c40 mla r10, r6, r3, r5 */
/* @0xe9c44 ldr r9, [r4] */
/* @0xe9c48 add r8, r9, r10, lsl #4 */
/* @0xe9c4c ldr r3, [r8, #0xc] */
/* @0xe9c50 sub r3, r3, #1 */
/* @0xe9c54 bic r3, r3, #-16777216 */
/* @0xe9c58 bic r3, r3, #3 */
/* @0xe9c5c cmp r3, #0 */
/* @0xe9c60 beq 0xe9d7c <_ZN2VM10PokeDSGridEiiiR6RValue+0x1a4> */
/* @0xe9c64 mov r3, #0 */
/* @0xe9c68 mov r2, #5 */
/* @0xe9c6c str r3, [r8, #0x8] */
/* @0xe9c70 str r2, [r8, #0xc] */
/* @0xe9c74 str r3, [r9, r10, lsl #4] */
/* @0xe9c78 ldr r3, [r4, #0x4] */
/* @0xe9c7c ldr r8, [r4] */
/* @0xe9c80 mla r5, r3, r6, r5 */
/* @0xe9c84 add r4, r8, r5, lsl #4 */
/* @0xe9c88 ldr r2, [r4, #0xc] */
/* @0xe9c8c bic r3, r2, #-16777216 */
/* @0xe9c90 cmp r3, #1 */
/* @0xe9c94 beq 0xe9d48 <_ZN2VM10PokeDSGridEiiiR6RValue+0x170> */
/* @0xe9c98 cmp r3, #2 */
/* @0xe9c9c bne 0xe9cc4 <_ZN2VM10PokeDSGridEiiiR6RValue+0xec> */
/* @0xe9ca0 sub r3, r2, #1 */
/* @0xe9ca4 bic r3, r3, #-16777216 */
/* @0xe9ca8 bic r3, r3, #3 */
/* @0xe9cac cmp r3, #0 */
/* @0xe9cb0 beq 0xe9e58 <_ZN2VM10PokeDSGridEiiiR6RValue+0x280> */
/* @0xe9cb4 mov r2, #0 */
/* @0xe9cb8 mov r3, #5 */
/* @0xe9cbc str r2, [r4, #0x8] */
/* @0xe9cc0 str r3, [r4, #0xc] */
/* @0xe9cc4 ldr r3, [r7, #0xc] */
/* @0xe9cc8 mov r1, #0 */
/* @0xe9ccc ldr r2, [r7, #0x8] */
/* @0xe9cd0 str r1, [r8, r5, lsl #4] */
/* @0xe9cd4 str r3, [r4, #0xc] */
/* @0xe9cd8 ldr r3, [r7, #0xc] */
/* @0xe9cdc str r2, [r4, #0x8] */
/* @0xe9ce0 bic r3, r3, #-16777216 */
/* @0xe9ce4 cmp r3, #14 */
/* @0xe9ce8 addls pc, pc, r3, lsl #2 */
/* @0xe9cec b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220> */
/* @0xe9cf0 b 0xe9d88 <_ZN2VM10PokeDSGridEiiiR6RValue+0x1b0> */
/* @0xe9cf4 b 0xe9e00 <_ZN2VM10PokeDSGridEiiiR6RValue+0x228> */
/* @0xe9cf8 b 0xe9dc8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x1f0> */
/* @0xe9cfc b 0xe9d38 <_ZN2VM10PokeDSGridEiiiR6RValue+0x160> */
/* @0xe9d00 b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220> */
/* @0xe9d04 b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220> */
/* @0xe9d08 b 0xe9da0 <_ZN2VM10PokeDSGridEiiiR6RValue+0x1c8> */
/* @0xe9d0c b 0xe9d38 <_ZN2VM10PokeDSGridEiiiR6RValue+0x160> */
/* @0xe9d10 b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220> */
/* @0xe9d14 b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220> */
/* @0xe9d18 b 0xe9d88 <_ZN2VM10PokeDSGridEiiiR6RValue+0x1b0> */
/* @0xe9d1c b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220> */
/* @0xe9d20 b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220> */
/* @0xe9d24 b 0xe9d88 <_ZN2VM10PokeDSGridEiiiR6RValue+0x1b0> */
/* @0xe9d28 b 0xe9d38 <_ZN2VM10PokeDSGridEiiiR6RValue+0x160> */
/* @0xe9d2c mov r0, #0 */
/* @0xe9d30 add sp, sp, #8 */
/* @0xe9d34 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xe9d38 ldr r3, [r7] */
/* @0xe9d3c mov r0, #1 */
/* @0xe9d40 str r3, [r8, r5, lsl #4] */
/* @0xe9d44 b 0xe9d30 <_ZN2VM10PokeDSGridEiiiR6RValue+0x158> */
/* @0xe9d48 ldr r6, [r8, r5, lsl #4] */
/* @0xe9d4c cmp r6, #0 */
/* @0xe9d50 beq 0xe9d70 <_ZN2VM10PokeDSGridEiiiR6RValue+0x198> */
/* @0xe9d54 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe9d58 ldr r9, [r6, #0x4] */
/* @0xe9d5c sub r9, r9, #1 */
/* @0xe9d60 str r9, [r6, #0x4] */
/* @0xe9d64 cmp r9, #0 */
/* @0xe9d68 beq 0xe9e20 <_ZN2VM10PokeDSGridEiiiR6RValue+0x248> */
/* @0xe9d6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe9d70 mov r3, #0 */
/* @0xe9d74 str r3, [r8, r5, lsl #4] */
/* @0xe9d78 b 0xe9cc4 <_ZN2VM10PokeDSGridEiiiR6RValue+0xec> */
/* @0xe9d7c mov r0, r8 */
/* @0xe9d80 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe9d84 b 0xe9c64 <_ZN2VM10PokeDSGridEiiiR6RValue+0x8c> */
/* @0xe9d88 ldr r2, [r7] */
/* @0xe9d8c mov r0, #1 */
/* @0xe9d90 ldr r3, [r7, #0x4] */
/* @0xe9d94 str r2, [r8, r5, lsl #4] */
/* @0xe9d98 str r3, [r4, #0x4] */
/* @0xe9d9c b 0xe9d30 <_ZN2VM10PokeDSGridEiiiR6RValue+0x158> */
/* @0xe9da0 ldr r3, [r7] */
/* @0xe9da4 str r3, [r8, r5, lsl #4] */
/* @0xe9da8 ldr r3, [r7] */
/* @0xe9dac cmp r3, #0 */
/* @0xe9db0 beq 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220> */
/* @0xe9db4 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xe9db8 ldr r1, [r7] */
/* @0xe9dbc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xe9dc0 mov r0, #1 */
/* @0xe9dc4 b 0xe9d30 <_ZN2VM10PokeDSGridEiiiR6RValue+0x158> */
/* @0xe9dc8 ldr r3, [r7] */
/* @0xe9dcc cmp r3, #0 */
/* @0xe9dd0 str r3, [r8, r5, lsl #4] */
/* @0xe9dd4 beq 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220> */
/* @0xe9dd8 ldr r1, [r3, #0x8] */
/* @0xe9ddc ldr r2, [r3] */
/* @0xe9de0 cmp r1, #0 */
/* @0xe9de4 streq r4, [r3, #0x8] */
/* @0xe9de8 add r2, r2, #1 */
/* @0xe9dec str r2, [r3] */
/* @0xe9df0 moveq r0, #1 */
/* @0xe9df4 beq 0xe9d30 <_ZN2VM10PokeDSGridEiiiR6RValue+0x158> */
/* @0xe9df8 mov r0, #1 */
/* @0xe9dfc b 0xe9d30 <_ZN2VM10PokeDSGridEiiiR6RValue+0x158> */
/* @0xe9e00 ldr r3, [r7] */
/* @0xe9e04 mov r0, #1 */
/* @0xe9e08 cmp r3, #0 */
/* @0xe9e0c ldrne r2, [r3, #0x4] */
/* @0xe9e10 addne r2, r2, #1 */
/* @0xe9e14 strne r2, [r3, #0x4] */
/* @0xe9e18 str r3, [r8, r5, lsl #4] */
/* @0xe9e1c b 0xe9d30 <_ZN2VM10PokeDSGridEiiiR6RValue+0x158> */
/* @0xe9e20 ldr r0, [r6] */
/* @0xe9e24 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9e28 str r9, [r6] */
/* @0xe9e2c str r9, [r6, #0x8] */
/* @0xe9e30 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xe9e34 ldr r9, [r6, #0x4] */
/* @0xe9e38 sub r9, r9, #1 */
/* @0xe9e3c str r9, [r6, #0x4] */
/* @0xe9e40 cmp r9, #0 */
/* @0xe9e44 beq 0xe9e64 <_ZN2VM10PokeDSGridEiiiR6RValue+0x28c> */
/* @0xe9e48 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xe9e4c mov r0, r6 */
/* @0xe9e50 bl 0x27d1d0 <_ZdlPv> */
/* @0xe9e54 b 0xe9d6c <_ZN2VM10PokeDSGridEiiiR6RValue+0x194> */
/* @0xe9e58 mov r0, r4 */
/* @0xe9e5c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe9e60 b 0xe9cb4 <_ZN2VM10PokeDSGridEiiiR6RValue+0xdc> */
/* @0xe9e64 ldr r0, [r6] */
/* @0xe9e68 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xe9e6c mov r0, r6 */
/* @0xe9e70 str r9, [r6] */
/* @0xe9e74 str r9, [r6, #0x8] */
/* @0xe9e78 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xe9e7c mov r0, r6 */
/* @0xe9e80 bl 0x27d1d0 <_ZdlPv> */
/* @0xe9e84 b 0xe9e48 <_ZN2VM10PokeDSGridEiiiR6RValue+0x270> */

/* ── FUNC 0xe9e88 · DoPush(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=5488 · insn=1372 */
/* @0xe9e88 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe9e8c mov r7, r3 */
/* @0xe9e90 ldr r5, [pc, #0xff4] */
/* @0xe9e94 sub sp, sp, #2192 */
/* @0xe9e98 ldr r12, [pc, #0xff0] */
/* @0xe9e9c sub sp, sp, #4 */
/* @0xe9ea0 add r5, pc, r5 */
/* @0xe9ea4 mov r8, r0 */
/* @0xe9ea8 mov r0, #0 */
/* @0xe9eac mov r4, r1 */
/* @0xe9eb0 ldr r6, [r5, r12] */
/* @0xe9eb4 mov r9, r2 */
/* @0xe9eb8 ldr r3, [r6] */
/* @0xe9ebc str r3, [sp, #0x88c] */
/* @0xe9ec0 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xe9ec4 ubfx r3, r8, #0x10, #0x4 */
/* @0xe9ec8 cmp r3, #15 */
/* @0xe9ecc addls pc, pc, r3, lsl #2 */
/* @0xe9ed0 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9ed4 b 0xea1f0 <_Z6DoPushjPhPKhP6VMExec+0x368> */
/* @0xe9ed8 b 0xea1f0 <_Z6DoPushjPhPKhP6VMExec+0x368> */
/* @0xe9edc b 0xea04c <_Z6DoPushjPhPKhP6VMExec+0x1c4> */
/* @0xe9ee0 b 0xea1f0 <_Z6DoPushjPhPKhP6VMExec+0x368> */
/* @0xe9ee4 b 0xea04c <_Z6DoPushjPhPKhP6VMExec+0x1c4> */
/* @0xe9ee8 b 0xea06c <_Z6DoPushjPhPKhP6VMExec+0x1e4> */
/* @0xe9eec b 0xea130 <_Z6DoPushjPhPKhP6VMExec+0x2a8> */
/* @0xe9ef0 b 0xea19c <_Z6DoPushjPhPKhP6VMExec+0x314> */
/* @0xe9ef4 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9ef8 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9efc b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9f00 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9f04 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9f08 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9f0c b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9f10 b 0xea05c <_Z6DoPushjPhPKhP6VMExec+0x1d4> */
/* @0xe9f14 add r3, sp, #60 */
/* @0xe9f18 str r3, [sp, #0x2c] */
/* @0xe9f1c ldr r0, [r4] */
/* @0xe9f20 mov r10, r4 */
/* @0xe9f24 ldr r1, [r4, #0x4] */
/* @0xe9f28 add r11, sp, #76 */
/* @0xe9f2c ldr r2, [r4, #0x8] */
/* @0xe9f30 mov r9, #0 */
/* @0xe9f34 ldr r3, [r4, #0xc] */
/* @0xe9f38 ldr r12, [sp, #0x2c] */
/* @0xe9f3c stm r12!, {r0, r1, r2, r3} */
/* @0xe9f40 mov r12, r11 */
/* @0xe9f44 ldr r0, [r10, #0x10]! */
/* @0xe9f48 ldr lr, [sp, #0x48] */
/* @0xe9f4c ldr r1, [r10, #0x4] */
/* @0xe9f50 bic lr, lr, #-16777216 */
/* @0xe9f54 ldr r2, [r10, #0x8] */
/* @0xe9f58 cmp lr, #2 */
/* @0xe9f5c ldr r3, [r10, #0xc] */
/* @0xe9f60 stm r12!, {r0, r1, r2, r3} */
/* @0xe9f64 mvn r3, #-16777216 */
/* @0xe9f68 ldr r2, [pc, #0xf24] */
/* @0xe9f6c str r9, [r4, #0x10] */
/* @0xe9f70 str r9, [r4, #0x14] */
/* @0xe9f74 str r9, [r4, #0x18] */
/* @0xe9f78 str r3, [r4, #0x1c] */
/* @0xe9f7c ldr r2, [r5, r2] */
/* @0xe9f80 str r9, [sp, #0x5c] */
/* @0xe9f84 str r9, [sp, #0x60] */
/* @0xe9f88 str r2, [sp, #0x20] */
/* @0xe9f8c strb r9, [r2] */
/* @0xe9f90 str r9, [sp, #0x64] */
/* @0xe9f94 str r3, [sp, #0x68] */
/* @0xe9f98 beq 0xeb148 <_Z6DoPushjPhPKhP6VMExec+0x12c0> */
/* @0xe9f9c cmp lr, #5 */
/* @0xe9fa0 beq 0xeb0bc <_Z6DoPushjPhPKhP6VMExec+0x1234> */
/* @0xe9fa4 ble 0xeafc4 <_Z6DoPushjPhPKhP6VMExec+0x113c> */
/* @0xe9fa8 cmp lr, #6 */
/* @0xe9fac beq 0xead74 <_Z6DoPushjPhPKhP6VMExec+0xeec> */
/* @0xe9fb0 cmp lr, r3 */
/* @0xe9fb4 bne 0xeafcc <_Z6DoPushjPhPKhP6VMExec+0x1144> */
/* @0xe9fb8 ldr r2, [sp, #0x1c] */
/* @0xe9fbc mov r1, r8 */
/* @0xe9fc0 ldr r0, [r7, #0x34] */
/* @0xe9fc4 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xe9fc8 ldr r1, [sp, #0x1c] */
/* @0xe9fcc mov r5, r0 */
/* @0xe9fd0 mov r0, r8 */
/* @0xe9fd4 bl 0x1f3f8c <_Z22Variable_GetObjectNameii> */
/* @0xe9fd8 ldr r2, [sp, #0x24] */
/* @0xe9fdc ldr r1, [sp, #0x1c] */
/* @0xe9fe0 str r5, [sp] */
/* @0xe9fe4 add r5, sp, #140 */
/* @0xe9fe8 str r2, [sp, #0x8] */
/* @0xe9fec ldr r2, [pc, #0xea4] */
/* @0xe9ff0 str r1, [sp, #0x4] */
/* @0xe9ff4 mov r1, #2048 */
/* @0xe9ff8 add r2, pc, r2 */
/* @0xe9ffc mov r3, r0 */
/* @0xea000 mov r0, r5 */
/* @0xea004 bl 0xb65c8 <snprintf@plt> */
/* @0xea008 mov r0, r5 */
/* @0xea00c strb r9, [sp, #0x88b] */
/* @0xea010 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xea014 mov r3, #5 */
/* @0xea018 str r9, [r4, #0x10] */
/* @0xea01c str r9, [r4, #0x14] */
/* @0xea020 str r3, [r4, #0x1c] */
/* @0xea024 mov r4, r10 */
/* @0xea028 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xea02c ldr r2, [sp, #0x88c] */
/* @0xea030 ldr r3, [r6] */
/* @0xea034 mov r0, r4 */
/* @0xea038 cmp r2, r3 */
/* @0xea03c bne 0xeb214 <_Z6DoPushjPhPKhP6VMExec+0x138c> */
/* @0xea040 add sp, sp, #2192 */
/* @0xea044 add sp, sp, #4 */
/* @0xea048 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xea04c ldr r3, [r9] */
/* @0xea050 sub r4, r4, #4 */
/* @0xea054 str r3, [r4] */
/* @0xea058 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea05c sxth r8, r8 */
/* @0xea060 sub r4, r4, #4 */
/* @0xea064 str r8, [r4] */
/* @0xea068 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea06c tst r8, #1073741824 */
/* @0xea070 sxth r8, r8 */
/* @0xea074 beq 0xea208 <_Z6DoPushjPhPKhP6VMExec+0x380> */
/* @0xea078 ldr r3, [r9] */
/* @0xea07c cmp r3, #0 */
/* @0xea080 ldrge r1, [r4], #4 */
/* @0xea084 movlt r2, #-2147483648 */
/* @0xea088 strlt r2, [sp, #0x24] */
/* @0xea08c strge r1, [sp, #0x24] */
/* @0xea090 tst r3, #536870912 */
/* @0xea094 ldreq r8, [r4], #4 */
/* @0xea098 tst r3, #1073741824 */
/* @0xea09c addne r8, r8, #99328 */
/* @0xea0a0 bic r3, r3, #-268435456 */
/* @0xea0a4 addne r8, r8, #672 */
/* @0xea0a8 str r3, [sp, #0x1c] */
/* @0xea0ac cmn r8, #9 */
/* @0xea0b0 beq 0xea7c0 <_Z6DoPushjPhPKhP6VMExec+0x938> */
/* @0xea0b4 cmn r8, #10 */
/* @0xea0b8 beq 0xe9f14 <_Z6DoPushjPhPKhP6VMExec+0x8c> */
/* @0xea0bc ldr r1, [pc, #0xdd0] */
/* @0xea0c0 mov r3, #0 */
/* @0xea0c4 mvn r0, #-16777216 */
/* @0xea0c8 str r3, [r4, #-0x10] */
/* @0xea0cc str r3, [r4, #-0xc] */
/* @0xea0d0 add r2, r8, #14 */
/* @0xea0d4 str r3, [r4, #-0x8] */
/* @0xea0d8 sub r10, r4, #16 */
/* @0xea0dc str r0, [r4, #-0x4] */
/* @0xea0e0 ldr r1, [r5, r1] */
/* @0xea0e4 str r1, [sp, #0x20] */
/* @0xea0e8 strb r3, [r1] */
/* @0xea0ec cmp r2, #13 */
/* @0xea0f0 addls pc, pc, r2, lsl #2 */
/* @0xea0f4 b 0xea628 <_Z6DoPushjPhPKhP6VMExec+0x7a0> */
/* @0xea0f8 b 0xea620 <_Z6DoPushjPhPKhP6VMExec+0x798> */
/* @0xea0fc b 0xea510 <_Z6DoPushjPhPKhP6VMExec+0x688> */
/* @0xea100 b 0xea3bc <_Z6DoPushjPhPKhP6VMExec+0x534> */
/* @0xea104 b 0xea39c <_Z6DoPushjPhPKhP6VMExec+0x514> */
/* @0xea108 b 0xea628 <_Z6DoPushjPhPKhP6VMExec+0x7a0> */
/* @0xea10c b 0xea628 <_Z6DoPushjPhPKhP6VMExec+0x7a0> */
/* @0xea110 b 0xea340 <_Z6DoPushjPhPKhP6VMExec+0x4b8> */
/* @0xea114 b 0xea2f0 <_Z6DoPushjPhPKhP6VMExec+0x468> */
/* @0xea118 b 0xea21c <_Z6DoPushjPhPKhP6VMExec+0x394> */
/* @0xea11c b 0xea22c <_Z6DoPushjPhPKhP6VMExec+0x3a4> */
/* @0xea120 b 0xea598 <_Z6DoPushjPhPKhP6VMExec+0x710> */
/* @0xea124 b 0xea628 <_Z6DoPushjPhPKhP6VMExec+0x7a0> */
/* @0xea128 b 0xea618 <_Z6DoPushjPhPKhP6VMExec+0x790> */
/* @0xea12c b 0xea2cc <_Z6DoPushjPhPKhP6VMExec+0x444> */
/* @0xea130 ldr r3, [pc, #0xd64] */
/* @0xea134 sub r8, r4, #4 */
/* @0xea138 ldr r2, [r9] */
/* @0xea13c ldr r3, [r5, r3] */
/* @0xea140 ldr r3, [r3] */
/* @0xea144 ldr r3, [r3, r2, lsl #2] */
/* @0xea148 cmp r3, #0 */
/* @0xea14c beq 0xea200 <_Z6DoPushjPhPKhP6VMExec+0x378> */
/* @0xea150 ldr r2, [pc, #0xd48] */
/* @0xea154 ldr r2, [r5, r2] */
/* @0xea158 ldr r7, [r2] */
/* @0xea15c add r3, r7, r3 */
/* @0xea160 adds r7, r3, #4 */
/* @0xea164 beq 0xea1e4 <_Z6DoPushjPhPKhP6VMExec+0x35c> */
/* @0xea168 mov r0, #12 */
/* @0xea16c bl 0x27c524 <_Znwj> */
/* @0xea170 mov r5, r0 */
/* @0xea174 mov r0, r7 */
/* @0xea178 bl 0xb6538 <strlen@plt> */
/* @0xea17c str r0, [r5, #0x8] */
/* @0xea180 mov r0, r7 */
/* @0xea184 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xea188 mov r3, #1 */
/* @0xea18c stm r5, {r0, r3} */
/* @0xea190 str r5, [r4, #-0x4] */
/* @0xea194 mov r4, r8 */
/* @0xea198 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea19c ldr r3, [pc, #0xd00] */
/* @0xea1a0 sub r8, r4, #4 */
/* @0xea1a4 ldr r2, [r9] */
/* @0xea1a8 ldr r3, [r5, r3] */
/* @0xea1ac ldr r3, [r3] */
/* @0xea1b0 ldr r5, [r3, r2, lsl #2] */
/* @0xea1b4 cmp r5, #0 */
/* @0xea1b8 beq 0xea7b4 <_Z6DoPushjPhPKhP6VMExec+0x92c> */
/* @0xea1bc mov r0, #12 */
/* @0xea1c0 bl 0x27c524 <_Znwj> */
/* @0xea1c4 mov r7, r0 */
/* @0xea1c8 mov r0, r5 */
/* @0xea1cc bl 0xb6538 <strlen@plt> */
/* @0xea1d0 str r0, [r7, #0x8] */
/* @0xea1d4 mov r0, r5 */
/* @0xea1d8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xea1dc mov r3, #1 */
/* @0xea1e0 stm r7, {r0, r3} */
/* @0xea1e4 str r7, [r4, #-0x4] */
/* @0xea1e8 mov r4, r8 */
/* @0xea1ec b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea1f0 ldrd r2, r3, [r9] */
/* @0xea1f4 sub r4, r4, #8 */
/* @0xea1f8 strd r2, r3, [r4] */
/* @0xea1fc b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea200 mov r7, #4 */
/* @0xea204 b 0xea168 <_Z6DoPushjPhPKhP6VMExec+0x2e0> */
/* @0xea208 mov r3, #-2147483648 */
/* @0xea20c mvn r1, #0 */
/* @0xea210 str r3, [sp, #0x24] */
/* @0xea214 str r1, [sp, #0x1c] */
/* @0xea218 b 0xea0ac <_Z6DoPushjPhPKhP6VMExec+0x224> */
/* @0xea21c ldr r0, [sp, #0x1c] */
/* @0xea220 bl 0x1f3484 <_Z24Variable_Global_Declaredi> */
/* @0xea224 cmp r0, #0 */
/* @0xea228 beq 0xea2cc <_Z6DoPushjPhPKhP6VMExec+0x444> */
/* @0xea22c ldr r0, [sp, #0x1c] */
/* @0xea230 mov r2, r10 */
/* @0xea234 ldr r1, [sp, #0x24] */
/* @0xea238 bl 0x1f3984 <_Z22Variable_Global_GetVariiP6RValue> */
/* @0xea23c ldr r3, [r4, #-0x4] */
/* @0xea240 mov r4, r10 */
/* @0xea244 mov r11, r0 */
/* @0xea248 mvn r2, #-16777216 */
/* @0xea24c cmp r3, r2 */
/* @0xea250 beq 0xea5ac <_Z6DoPushjPhPKhP6VMExec+0x724> */
/* @0xea254 cmp r11, #0 */
/* @0xea258 bne 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea25c mov r1, r8 */
/* @0xea260 ldr r2, [sp, #0x1c] */
/* @0xea264 ldr r0, [r7, #0x34] */
/* @0xea268 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xea26c ldr r3, [pc, #0xc34] */
/* @0xea270 ldr r2, [r5, r3] */
/* @0xea274 ldrb r2, [r2] */
/* @0xea278 cmp r2, #0 */
/* @0xea27c mov r1, r0 */
/* @0xea280 bne 0xea8cc <_Z6DoPushjPhPKhP6VMExec+0xa44> */
/* @0xea284 ldr r2, [sp, #0x20] */
/* @0xea288 ldrb r3, [r2] */
/* @0xea28c cmp r3, #0 */
/* @0xea290 bne 0xea930 <_Z6DoPushjPhPKhP6VMExec+0xaa8> */
/* @0xea294 cmn r8, #1 */
/* @0xea298 mov r0, r7 */
/* @0xea29c ldreq r3, [r7, #0x14] */
/* @0xea2a0 movne r2, r8 */
/* @0xea2a4 ldreq r2, [r3, #0x78] */
/* @0xea2a8 ldr r3, [sp, #0x1c] */
/* @0xea2ac str r3, [sp] */
/* @0xea2b0 ldr r3, [sp, #0x24] */
/* @0xea2b4 str r3, [sp, #0x4] */
/* @0xea2b8 mov r3, r1 */
/* @0xea2bc ldr r1, [pc, #0xbe8] */
/* @0xea2c0 add r1, pc, r1 */
/* @0xea2c4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xea2c8 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea2cc ldr r0, [r7, #0x14] */
/* @0xea2d0 mov r3, r10 */
/* @0xea2d4 ldr r1, [sp, #0x1c] */
/* @0xea2d8 ldr r2, [sp, #0x24] */
/* @0xea2dc bl 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0xea2e0 ldr r3, [r4, #-0x4] */
/* @0xea2e4 mov r4, r10 */
/* @0xea2e8 mov r11, r0 */
/* @0xea2ec b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea2f0 ldr r0, [r7, #0x10] */
/* @0xea2f4 cmp r0, #0 */
/* @0xea2f8 beq 0xeb11c <_Z6DoPushjPhPKhP6VMExec+0x1294> */
/* @0xea2fc ldr r11, [r0, #0x24] */
/* @0xea300 cmp r11, #0 */
/* @0xea304 beq 0xea5a8 <_Z6DoPushjPhPKhP6VMExec+0x720> */
/* @0xea308 ldr r3, [r0, #0x4] */
/* @0xea30c ldr r2, [sp, #0x1c] */
/* @0xea310 cmp r3, #0 */
/* @0xea314 sub r1, r2, #99328 */
/* @0xea318 sub r1, r1, #672 */
/* @0xea31c beq 0xeb2dc <_Z6DoPushjPhPKhP6VMExec+0x1454> */
/* @0xea320 add r1, r3, r1, lsl #4 */
/* @0xea324 mov r0, r10 */
/* @0xea328 ldr r2, [sp, #0x24] */
/* @0xea32c bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0xea330 ldr r3, [r4, #-0x4] */
/* @0xea334 mov r4, r10 */
/* @0xea338 mov r11, r0 */
/* @0xea33c b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea340 ldr r2, [sp, #0x1c] */
/* @0xea344 movw r3, #0x869f */
/* @0xea348 movt r3, #0x1 */
/* @0xea34c cmp r2, r3 */
/* @0xea350 ble 0xea954 <_Z6DoPushjPhPKhP6VMExec+0xacc> */
/* @0xea354 ldr r0, [r7, #0x10] */
/* @0xea358 cmp r0, #0 */
/* @0xea35c beq 0xea954 <_Z6DoPushjPhPKhP6VMExec+0xacc> */
/* @0xea360 ldr r3, [r0, #0x4] */
/* @0xea364 sub r1, r2, #99328 */
/* @0xea368 sub r1, r1, #672 */
/* @0xea36c cmp r3, #0 */
/* @0xea370 beq 0xeb2e8 <_Z6DoPushjPhPKhP6VMExec+0x1460> */
/* @0xea374 add r1, r3, r1, lsl #4 */
/* @0xea378 mov r0, r10 */
/* @0xea37c ldr r2, [sp, #0x24] */
/* @0xea380 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0xea384 cmp r0, #0 */
/* @0xea388 beq 0xea954 <_Z6DoPushjPhPKhP6VMExec+0xacc> */
/* @0xea38c ldr r3, [r4, #-0x4] */
/* @0xea390 mov r11, #1 */
/* @0xea394 mov r4, r10 */
/* @0xea398 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea39c ldr r0, [sp, #0x1c] */
/* @0xea3a0 mov r2, r10 */
/* @0xea3a4 ldr r1, [sp, #0x24] */
/* @0xea3a8 bl 0x1f3798 <_Z21Variable_Scope_GetVariiP6RValue> */
/* @0xea3ac ldr r3, [r4, #-0x4] */
/* @0xea3b0 mov r4, r10 */
/* @0xea3b4 mov r11, r0 */
/* @0xea3b8 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea3bc ldr r9, [r7, #0x10] */
/* @0xea3c0 mvn r3, #-16777216 */
/* @0xea3c4 str r3, [sp, #0x88] */
/* @0xea3c8 cmp r9, #0 */
/* @0xea3cc moveq r11, r9 */
/* @0xea3d0 beq 0xea470 <_Z6DoPushjPhPKhP6VMExec+0x5e8> */
/* @0xea3d4 ldr r1, [sp, #0x1c] */
/* @0xea3d8 mov r11, #0 */
/* @0xea3dc mov r0, r11 */
/* @0xea3e0 mov r11, r6 */
/* @0xea3e4 sub r12, r1, #99328 */
/* @0xea3e8 mov r6, r5 */
/* @0xea3ec sub r12, r12, #672 */
/* @0xea3f0 mov r5, r4 */
/* @0xea3f4 add r2, sp, #124 */
/* @0xea3f8 str r2, [sp, #0x28] */
/* @0xea3fc mov r4, r12 */
/* @0xea400 lsl r2, r12, #4 */
/* @0xea404 str r2, [sp, #0x2c] */
/* @0xea408 ldr r2, [r9, #0x24] */
/* @0xea40c cmp r2, #0 */
/* @0xea410 beq 0xea444 <_Z6DoPushjPhPKhP6VMExec+0x5bc> */
/* @0xea414 cmp r2, r4 */
/* @0xea418 bls 0xea444 <_Z6DoPushjPhPKhP6VMExec+0x5bc> */
/* @0xea41c ldr r1, [r9, #0x4] */
/* @0xea420 cmp r1, #0 */
/* @0xea424 beq 0xeb0a0 <_Z6DoPushjPhPKhP6VMExec+0x1218> */
/* @0xea428 ldr r2, [sp, #0x2c] */
/* @0xea42c add r1, r1, r2 */
/* @0xea430 ldr r0, [sp, #0x28] */
/* @0xea434 ldr r2, [sp, #0x24] */
/* @0xea438 str r3, [sp, #0x18] */
/* @0xea43c bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0xea440 ldr r3, [sp, #0x18] */
/* @0xea444 ldr r9, [r9, #0xc] */
/* @0xea448 cmp r9, #0 */
/* @0xea44c beq 0xea460 <_Z6DoPushjPhPKhP6VMExec+0x5d8> */
/* @0xea450 ldr r2, [sp, #0x88] */
/* @0xea454 bic r2, r2, #-16777216 */
/* @0xea458 cmp r2, r3 */
/* @0xea45c beq 0xea408 <_Z6DoPushjPhPKhP6VMExec+0x580> */
/* @0xea460 mov r4, r5 */
/* @0xea464 mov r5, r6 */
/* @0xea468 mov r6, r11 */
/* @0xea46c mov r11, r0 */
/* @0xea470 ldr r2, [r4, #-0x4] */
/* @0xea474 bic r3, r2, #-16777216 */
/* @0xea478 cmp r3, #1 */
/* @0xea47c beq 0xead40 <_Z6DoPushjPhPKhP6VMExec+0xeb8> */
/* @0xea480 cmp r3, #2 */
/* @0xea484 bne 0xea4a8 <_Z6DoPushjPhPKhP6VMExec+0x620> */
/* @0xea488 sub r3, r2, #1 */
/* @0xea48c bic r3, r3, #-16777216 */
/* @0xea490 bic r3, r3, #3 */
/* @0xea494 cmp r3, #0 */
/* @0xea498 beq 0xeb1c8 <_Z6DoPushjPhPKhP6VMExec+0x1340> */
/* @0xea49c mov r2, #0 */
/* @0xea4a0 mov r3, #5 */
/* @0xea4a4 stmdb r4, {r2, r3} */
/* @0xea4a8 ldr r3, [sp, #0x88] */
/* @0xea4ac mov r1, #0 */
/* @0xea4b0 ldr r2, [sp, #0x84] */
/* @0xea4b4 str r1, [r4, #-0x10] */
/* @0xea4b8 str r3, [r4, #-0x4] */
/* @0xea4bc ldr r3, [sp, #0x88] */
/* @0xea4c0 str r2, [r4, #-0x8] */
/* @0xea4c4 bic r3, r3, #-16777216 */
/* @0xea4c8 cmp r3, #14 */
/* @0xea4cc addls pc, pc, r3, lsl #2 */
/* @0xea4d0 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea4d4 b 0xea684 <_Z6DoPushjPhPKhP6VMExec+0x7fc> */
/* @0xea4d8 b 0xea718 <_Z6DoPushjPhPKhP6VMExec+0x890> */
/* @0xea4dc b 0xea6ec <_Z6DoPushjPhPKhP6VMExec+0x864> */
/* @0xea4e0 b 0xea678 <_Z6DoPushjPhPKhP6VMExec+0x7f0> */
/* @0xea4e4 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea4e8 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea4ec b 0xea6c8 <_Z6DoPushjPhPKhP6VMExec+0x840> */
/* @0xea4f0 b 0xea678 <_Z6DoPushjPhPKhP6VMExec+0x7f0> */
/* @0xea4f4 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea4f8 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea4fc b 0xea684 <_Z6DoPushjPhPKhP6VMExec+0x7fc> */
/* @0xea500 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea504 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea508 b 0xea684 <_Z6DoPushjPhPKhP6VMExec+0x7fc> */
/* @0xea50c b 0xea678 <_Z6DoPushjPhPKhP6VMExec+0x7f0> */
/* @0xea510 ldr r1, [sp, #0x1c] */
/* @0xea514 ubfx r3, r1, #0x8, #0x8 */
/* @0xea518 cmp r3, #0 */
/* @0xea51c uxtb r9, r1 */
/* @0xea520 bne 0xeab50 <_Z6DoPushjPhPKhP6VMExec+0xcc8> */
/* @0xea524 ldr r2, [pc, #0x984] */
/* @0xea528 ldr r2, [r5, r2] */
/* @0xea52c ldr r11, [r2] */
/* @0xea530 str r3, [r4, #-0x10] */
/* @0xea534 add r2, r11, r9, lsl #4 */
/* @0xea538 ldr r3, [r2, #0xc] */
/* @0xea53c ldr r0, [r2, #0x8] */
/* @0xea540 str r3, [r4, #-0x4] */
/* @0xea544 ldr r1, [r2, #0xc] */
/* @0xea548 str r0, [r4, #-0x8] */
/* @0xea54c bic r1, r1, #-16777216 */
/* @0xea550 cmp r1, #14 */
/* @0xea554 addls pc, pc, r1, lsl #2 */
/* @0xea558 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea55c b 0xea6ac <_Z6DoPushjPhPKhP6VMExec+0x824> */
/* @0xea560 b 0xea728 <_Z6DoPushjPhPKhP6VMExec+0x8a0> */
/* @0xea564 b 0xea744 <_Z6DoPushjPhPKhP6VMExec+0x8bc> */
/* @0xea568 b 0xea698 <_Z6DoPushjPhPKhP6VMExec+0x810> */
/* @0xea56c b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea570 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea574 b 0xea784 <_Z6DoPushjPhPKhP6VMExec+0x8fc> */
/* @0xea578 b 0xea698 <_Z6DoPushjPhPKhP6VMExec+0x810> */
/* @0xea57c b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea580 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea584 b 0xea6ac <_Z6DoPushjPhPKhP6VMExec+0x824> */
/* @0xea588 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea58c b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea590 b 0xea6ac <_Z6DoPushjPhPKhP6VMExec+0x824> */
/* @0xea594 b 0xea698 <_Z6DoPushjPhPKhP6VMExec+0x810> */
/* @0xea598 ldr r1, [sp, #0x20] */
/* @0xea59c mov r11, #0 */
/* @0xea5a0 mov r3, #1 */
/* @0xea5a4 strb r3, [r1] */
/* @0xea5a8 mov r4, r10 */
/* @0xea5ac mov r1, r8 */
/* @0xea5b0 ldr r2, [sp, #0x1c] */
/* @0xea5b4 ldr r0, [r7, #0x34] */
/* @0xea5b8 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xea5bc ldr r3, [r7, #0x14] */
/* @0xea5c0 cmn r8, #1 */
/* @0xea5c4 ldr r1, [sp, #0x1c] */
/* @0xea5c8 mov r9, r0 */
/* @0xea5cc ldreq r0, [r3, #0x78] */
/* @0xea5d0 movne r0, r8 */
/* @0xea5d4 bl 0x1f3f8c <_Z22Variable_GetObjectNameii> */
/* @0xea5d8 ldr r3, [pc, #0x8d4] */
/* @0xea5dc ldr r3, [r5, r3] */
/* @0xea5e0 ldrb r3, [r3] */
/* @0xea5e4 cmp r3, #0 */
/* @0xea5e8 bne 0xea254 <_Z6DoPushjPhPKhP6VMExec+0x3cc> */
/* @0xea5ec ldr r1, [sp, #0x24] */
/* @0xea5f0 mov r2, r0 */
/* @0xea5f4 ldr r3, [sp, #0x1c] */
/* @0xea5f8 mov r0, r7 */
/* @0xea5fc str r1, [sp, #0x4] */
/* @0xea600 ldr r1, [pc, #0x8b0] */
/* @0xea604 str r3, [sp] */
/* @0xea608 mov r3, r9 */
/* @0xea60c add r1, pc, r1 */
/* @0xea610 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xea614 b 0xea254 <_Z6DoPushjPhPKhP6VMExec+0x3cc> */
/* @0xea618 ldr r0, [r7, #0x18] */
/* @0xea61c b 0xea2d0 <_Z6DoPushjPhPKhP6VMExec+0x448> */
/* @0xea620 mov r11, #1 */
/* @0xea624 b 0xea5a8 <_Z6DoPushjPhPKhP6VMExec+0x720> */
/* @0xea628 mov r3, r10 */
/* @0xea62c mov r0, r8 */
/* @0xea630 ldr r1, [sp, #0x1c] */
/* @0xea634 ldr r2, [sp, #0x24] */
/* @0xea638 bl 0x1f3ce0 <_Z17Variable_GetValueiiiP6RValue> */
/* @0xea63c ldr r3, [pc, #0x864] */
/* @0xea640 ldr r3, [r5, r3] */
/* @0xea644 ldrb r3, [r3] */
/* @0xea648 cmp r3, #0 */
/* @0xea64c mov r11, r0 */
/* @0xea650 bne 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea654 cmp r0, #0 */
/* @0xea658 bne 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea65c ldr r2, [sp, #0x20] */
/* @0xea660 ldrb r3, [r2] */
/* @0xea664 cmp r3, #0 */
/* @0xea668 bne 0xeb218 <_Z6DoPushjPhPKhP6VMExec+0x1390> */
/* @0xea66c ldr r3, [r4, #-0x4] */
/* @0xea670 mov r4, r10 */
/* @0xea674 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea678 ldr r3, [sp, #0x7c] */
/* @0xea67c str r3, [r4, #-0x10] */
/* @0xea680 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea684 ldr r2, [sp, #0x7c] */
/* @0xea688 ldr r3, [sp, #0x80] */
/* @0xea68c str r2, [r4, #-0x10] */
/* @0xea690 str r3, [r4, #-0xc] */
/* @0xea694 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea698 ldr r2, [r11, r9, lsl #4] */
/* @0xea69c mov r11, #1 */
/* @0xea6a0 str r2, [r4, #-0x10] */
/* @0xea6a4 mov r4, r10 */
/* @0xea6a8 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea6ac ldr r1, [r11, r9, lsl #4] */
/* @0xea6b0 mov r11, #1 */
/* @0xea6b4 ldr r2, [r2, #0x4] */
/* @0xea6b8 str r1, [r4, #-0x10] */
/* @0xea6bc str r2, [r4, #-0xc] */
/* @0xea6c0 mov r4, r10 */
/* @0xea6c4 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea6c8 ldr r3, [sp, #0x7c] */
/* @0xea6cc str r3, [r4, #-0x10] */
/* @0xea6d0 ldr r3, [sp, #0x7c] */
/* @0xea6d4 cmp r3, #0 */
/* @0xea6d8 beq 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea6dc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xea6e0 ldr r1, [sp, #0x7c] */
/* @0xea6e4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xea6e8 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea6ec ldr r3, [sp, #0x7c] */
/* @0xea6f0 cmp r3, #0 */
/* @0xea6f4 str r3, [r4, #-0x10] */
/* @0xea6f8 beq 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea6fc ldr r1, [r3, #0x8] */
/* @0xea700 ldr r2, [r3] */
/* @0xea704 cmp r1, #0 */
/* @0xea708 streq r10, [r3, #0x8] */
/* @0xea70c add r2, r2, #1 */
/* @0xea710 str r2, [r3] */
/* @0xea714 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea718 ldr r0, [sp, #0x7c] */
/* @0xea71c bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */
/* @0xea720 str r0, [r4, #-0x10] */
/* @0xea724 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea728 ldr r0, [r11, r9, lsl #4] */
/* @0xea72c bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */
/* @0xea730 mov r11, #1 */
/* @0xea734 ldr r3, [r4, #-0x4] */
/* @0xea738 str r0, [r4, #-0x10] */
/* @0xea73c mov r4, r10 */
/* @0xea740 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea744 ldr r2, [r11, r9, lsl #4] */
/* @0xea748 cmp r2, #0 */
/* @0xea74c str r2, [r4, #-0x10] */
/* @0xea750 beq 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea754 ldr r0, [r2, #0x8] */
/* @0xea758 ldr r1, [r2] */
/* @0xea75c cmp r0, #0 */
/* @0xea760 streq r10, [r2, #0x8] */
/* @0xea764 add r1, r1, #1 */
/* @0xea768 str r1, [r2] */
/* @0xea76c moveq r4, r10 */
/* @0xea770 moveq r11, #1 */
/* @0xea774 beq 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea778 mov r4, r10 */
/* @0xea77c mov r11, #1 */
/* @0xea780 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea784 ldr r2, [r11, r9, lsl #4] */
/* @0xea788 str r2, [r4, #-0x10] */
/* @0xea78c ldr r2, [r11, r9, lsl #4] */
/* @0xea790 cmp r2, #0 */
/* @0xea794 beq 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea798 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xea79c ldr r1, [r11, r9, lsl #4] */
/* @0xea7a0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xea7a4 mov r11, #1 */
/* @0xea7a8 ldr r3, [r4, #-0x4] */
/* @0xea7ac mov r4, r10 */
/* @0xea7b0 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea7b4 str r5, [r4, #-0x4] */
/* @0xea7b8 mov r4, r8 */
/* @0xea7bc b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea7c0 add r3, sp, #60 */
/* @0xea7c4 str r3, [sp, #0x2c] */
/* @0xea7c8 ldr r0, [r4] */
/* @0xea7cc mvn r12, #-16777216 */
/* @0xea7d0 ldr r2, [r4, #0x8] */
/* @0xea7d4 ldr r3, [r4, #0xc] */
/* @0xea7d8 ldr r1, [r4, #0x4] */
/* @0xea7dc ldr r9, [sp, #0x2c] */
/* @0xea7e0 ldr lr, [pc, #0x6ac] */
/* @0xea7e4 stm r9!, {r0, r1, r2, r3} */
/* @0xea7e8 add r2, r4, #16 */
/* @0xea7ec str r12, [r4, #0xc] */
/* @0xea7f0 mov r3, #0 */
/* @0xea7f4 str r2, [sp, #0x28] */
/* @0xea7f8 ldr r2, [sp, #0x48] */
/* @0xea7fc str r3, [r4] */
/* @0xea800 str r3, [r4, #0x4] */
/* @0xea804 and r2, r2, r12 */
/* @0xea808 str r3, [r4, #0x8] */
/* @0xea80c cmp r2, #5 */
/* @0xea810 ldr lr, [r5, lr] */
/* @0xea814 str r3, [sp, #0x6c] */
/* @0xea818 str r3, [sp, #0x70] */
/* @0xea81c str lr, [sp, #0x20] */
/* @0xea820 strb r3, [lr] */
/* @0xea824 str r3, [sp, #0x74] */
/* @0xea828 str r12, [sp, #0x78] */
/* @0xea82c beq 0xeb02c <_Z6DoPushjPhPKhP6VMExec+0x11a4> */
/* @0xea830 ble 0xea970 <_Z6DoPushjPhPKhP6VMExec+0xae8> */
/* @0xea834 cmp r2, #6 */
/* @0xea838 beq 0xea978 <_Z6DoPushjPhPKhP6VMExec+0xaf0> */
/* @0xea83c cmp r2, r12 */
/* @0xea840 bne 0xeb00c <_Z6DoPushjPhPKhP6VMExec+0x1184> */
/* @0xea844 ldr r2, [pc, #0x690] */
/* @0xea848 ldr r2, [r5, r2] */
/* @0xea84c ldrb r9, [r2] */
/* @0xea850 cmp r9, #0 */
/* @0xea854 strne r3, [r4] */
/* @0xea858 strne r3, [r4, #0x4] */
/* @0xea85c movne r2, #5 */
/* @0xea860 beq 0xeb23c <_Z6DoPushjPhPKhP6VMExec+0x13b4> */
/* @0xea864 str r2, [r4, #0xc] */
/* @0xea868 ldr r3, [sp, #0x78] */
/* @0xea86c sub r3, r3, #1 */
/* @0xea870 bic r3, r3, #-16777216 */
/* @0xea874 bic r3, r3, #3 */
/* @0xea878 cmp r3, #0 */
/* @0xea87c beq 0xeb000 <_Z6DoPushjPhPKhP6VMExec+0x1178> */
/* @0xea880 ldr r1, [sp, #0x48] */
/* @0xea884 mov r3, #0 */
/* @0xea888 str r3, [sp, #0x74] */
/* @0xea88c mov r2, #5 */
/* @0xea890 sub r1, r1, #1 */
/* @0xea894 str r3, [sp, #0x6c] */
/* @0xea898 bic r3, r1, #-16777216 */
/* @0xea89c str r2, [sp, #0x78] */
/* @0xea8a0 bic r3, r3, #3 */
/* @0xea8a4 cmp r3, #0 */
/* @0xea8a8 beq 0xeaff4 <_Z6DoPushjPhPKhP6VMExec+0x116c> */
/* @0xea8ac mov r3, #5 */
/* @0xea8b0 mov r2, #0 */
/* @0xea8b4 str r3, [sp, #0x48] */
/* @0xea8b8 mov r11, #1 */
/* @0xea8bc ldr r3, [r4, #0xc] */
/* @0xea8c0 str r2, [sp, #0x44] */
/* @0xea8c4 str r2, [sp, #0x3c] */
/* @0xea8c8 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea8cc ldr r12, [pc, #0x5e8] */
/* @0xea8d0 mov r0, r7 */
/* @0xea8d4 ldr r2, [pc, #0x5e4] */
/* @0xea8d8 ldr r3, [pc, #0x5e4] */
/* @0xea8dc ldr lr, [r5, r12] */
/* @0xea8e0 ldr r2, [r5, r2] */
/* @0xea8e4 ldr r12, [pc, #0x5dc] */
/* @0xea8e8 ldr lr, [lr] */
/* @0xea8ec ldr r3, [r5, r3] */
/* @0xea8f0 ldr r2, [r2] */
/* @0xea8f4 str lr, [sp] */
/* @0xea8f8 ldr r12, [r5, r12] */
/* @0xea8fc ldr r3, [r3] */
/* @0xea900 str r8, [sp, #0x8] */
/* @0xea904 ldr r12, [r12] */
/* @0xea908 str r1, [sp, #0xc] */
/* @0xea90c ldr r1, [sp, #0x1c] */
/* @0xea910 str r12, [sp, #0x4] */
/* @0xea914 str r1, [sp, #0x10] */
/* @0xea918 ldr r1, [sp, #0x24] */
/* @0xea91c str r1, [sp, #0x14] */
/* @0xea920 ldr r1, [pc, #0x5a4] */
/* @0xea924 add r1, pc, r1 */
/* @0xea928 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xea92c b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea930 mov r0, r8 */
/* @0xea934 bl 0x19ed54 <_Z11Object_Namei> */
/* @0xea938 ldr r1, [pc, #0x590] */
/* @0xea93c mov r2, r8 */
/* @0xea940 add r1, pc, r1 */
/* @0xea944 mov r3, r0 */
/* @0xea948 mov r0, r7 */
/* @0xea94c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xea950 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea954 ldr r0, [r7, #0x14] */
/* @0xea958 cmp r0, #0 */
/* @0xea95c bne 0xea2d0 <_Z6DoPushjPhPKhP6VMExec+0x448> */
/* @0xea960 ldr r3, [r4, #-0x4] */
/* @0xea964 mov r11, r0 */
/* @0xea968 mov r4, r10 */
/* @0xea96c b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea970 cmp r2, #3 */
/* @0xea974 bne 0xeb00c <_Z6DoPushjPhPKhP6VMExec+0x1184> */
/* @0xea978 ldr r3, [sp, #0x3c] */
/* @0xea97c str r3, [sp, #0x34] */
/* @0xea980 ldr r3, [sp, #0x34] */
/* @0xea984 ldr r1, [sp, #0x1c] */
/* @0xea988 cmp r3, #0 */
/* @0xea98c sub r3, r1, #99328 */
/* @0xea990 sub r3, r3, #672 */
/* @0xea994 str r3, [sp, #0x30] */
/* @0xea998 beq 0xeb3c0 <_Z6DoPushjPhPKhP6VMExec+0x1538> */
/* @0xea99c ldr r3, [sp, #0x34] */
/* @0xea9a0 ldr r9, [r3, #0x60] */
/* @0xea9a4 cmp r9, #0 */
/* @0xea9a8 beq 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xea9ac ldr r0, [sp, #0x30] */
/* @0xea9b0 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0xea9b4 ldr r1, [r9, #0x8] */
/* @0xea9b8 ldr r11, [r9, #0x10] */
/* @0xea9bc bic r10, r0, #-2147483648 */
/* @0xea9c0 and r3, r10, r1 */
/* @0xea9c4 lsl r12, r3, #1 */
/* @0xea9c8 add r2, r12, r3 */
/* @0xea9cc add r2, r11, r2, lsl #2 */
/* @0xea9d0 ldr r2, [r2, #0x8] */
/* @0xea9d4 cmp r2, #0 */
/* @0xea9d8 beq 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xea9dc cmp r10, r2 */
/* @0xea9e0 beq 0xead1c <_Z6DoPushjPhPKhP6VMExec+0xe94> */
/* @0xea9e4 ldr lr, [r9] */
/* @0xea9e8 and r2, r1, r2 */
/* @0xea9ec add r0, lr, r3 */
/* @0xea9f0 rsb r2, r2, r0 */
/* @0xea9f4 tst r2, r1 */
/* @0xea9f8 movpl r0, #0 */
/* @0xea9fc bpl 0xeaa24 <_Z6DoPushjPhPKhP6VMExec+0xb9c> */
/* @0xeaa00 b 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xeaa04 cmp r10, r2 */
/* @0xeaa08 beq 0xead14 <_Z6DoPushjPhPKhP6VMExec+0xe8c> */
/* @0xeaa0c and r2, r1, r2 */
/* @0xeaa10 add r12, lr, r3 */
/* @0xeaa14 rsb r2, r2, r12 */
/* @0xeaa18 and r2, r2, r1 */
/* @0xeaa1c cmp r2, r0 */
/* @0xeaa20 blt 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xeaa24 add r3, r3, #1 */
/* @0xeaa28 add r0, r0, #1 */
/* @0xeaa2c and r3, r1, r3 */
/* @0xeaa30 lsl r12, r3, #1 */
/* @0xeaa34 add r2, r12, r3 */
/* @0xeaa38 add r2, r11, r2, lsl #2 */
/* @0xeaa3c ldr r2, [r2, #0x8] */
/* @0xeaa40 cmp r2, #0 */
/* @0xeaa44 bne 0xeaa04 <_Z6DoPushjPhPKhP6VMExec+0xb7c> */
/* @0xeaa48 ldr r2, [r4, #0xc] */
/* @0xeaa4c ldr r9, [sp, #0x34] */
/* @0xeaa50 mvn r1, #-16777216 */
/* @0xeaa54 cmp r2, r1 */
/* @0xeaa58 bne 0xeacd8 <_Z6DoPushjPhPKhP6VMExec+0xe50> */
/* @0xeaa5c cmp r9, #0 */
/* @0xeaa60 beq 0xead08 <_Z6DoPushjPhPKhP6VMExec+0xe80> */
/* @0xeaa64 ldr r9, [r9, #0x18] */
/* @0xeaa68 cmp r9, #0 */
/* @0xeaa6c beq 0xeaa50 <_Z6DoPushjPhPKhP6VMExec+0xbc8> */
/* @0xeaa70 ldr r11, [r9, #0x60] */
/* @0xeaa74 cmp r11, #0 */
/* @0xeaa78 beq 0xeaa50 <_Z6DoPushjPhPKhP6VMExec+0xbc8> */
/* @0xeaa7c ldr r0, [sp, #0x30] */
/* @0xeaa80 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0xeaa84 ldr r1, [r11, #0x8] */
/* @0xeaa88 ldr r10, [r11, #0x10] */
/* @0xeaa8c bic r0, r0, #-2147483648 */
/* @0xeaa90 and r3, r0, r1 */
/* @0xeaa94 lsl lr, r3, #1 */
/* @0xeaa98 add r2, lr, r3 */
/* @0xeaa9c add r2, r10, r2, lsl #2 */
/* @0xeaaa0 ldr r2, [r2, #0x8] */
/* @0xeaaa4 cmp r2, #0 */
/* @0xeaaa8 beq 0xeab18 <_Z6DoPushjPhPKhP6VMExec+0xc90> */
/* @0xeaaac cmp r0, r2 */
/* @0xeaab0 beq 0xeab2c <_Z6DoPushjPhPKhP6VMExec+0xca4> */
/* @0xeaab4 ldr r11, [r11] */
/* @0xeaab8 and r2, r1, r2 */
/* @0xeaabc add r12, r3, r11 */
/* @0xeaac0 rsb r2, r2, r12 */
/* @0xeaac4 tst r2, r1 */
/* @0xeaac8 movpl r12, #0 */
/* @0xeaacc bpl 0xeaaf4 <_Z6DoPushjPhPKhP6VMExec+0xc6c> */
/* @0xeaad0 b 0xeab18 <_Z6DoPushjPhPKhP6VMExec+0xc90> */
/* @0xeaad4 cmp r0, r2 */
/* @0xeaad8 beq 0xeab24 <_Z6DoPushjPhPKhP6VMExec+0xc9c> */
/* @0xeaadc and r2, r1, r2 */
/* @0xeaae0 add lr, r3, r11 */
/* @0xeaae4 rsb r2, r2, lr */
/* @0xeaae8 and r2, r2, r1 */
/* @0xeaaec cmp r2, r12 */
/* @0xeaaf0 blt 0xeab18 <_Z6DoPushjPhPKhP6VMExec+0xc90> */
/* @0xeaaf4 add r3, r3, #1 */
/* @0xeaaf8 add r12, r12, #1 */
/* @0xeaafc and r3, r1, r3 */
/* @0xeab00 lsl lr, r3, #1 */
/* @0xeab04 add r2, lr, r3 */
/* @0xeab08 add r2, r10, r2, lsl #2 */
/* @0xeab0c ldr r2, [r2, #0x8] */
/* @0xeab10 cmp r2, #0 */
/* @0xeab14 bne 0xeaad4 <_Z6DoPushjPhPKhP6VMExec+0xc4c> */
/* @0xeab18 ldr r3, [sp, #0x28] */
/* @0xeab1c ldr r2, [r3, #-0x4] */
/* @0xeab20 b 0xeaa50 <_Z6DoPushjPhPKhP6VMExec+0xbc8> */
/* @0xeab24 cmn r3, #1 */
/* @0xeab28 beq 0xeab18 <_Z6DoPushjPhPKhP6VMExec+0xc90> */
/* @0xeab2c add r3, lr, r3 */
/* @0xeab30 add r10, r10, r3, lsl #2 */
/* @0xeab34 cmn r10, #4 */
/* @0xeab38 beq 0xeab18 <_Z6DoPushjPhPKhP6VMExec+0xc90> */
/* @0xeab3c ldr r1, [r10, #0x4] */
/* @0xeab40 mov r0, r4 */
/* @0xeab44 ldr r2, [sp, #0x24] */
/* @0xeab48 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0xeab4c b 0xeab18 <_Z6DoPushjPhPKhP6VMExec+0xc90> */
/* @0xeab50 ldr r0, [r7, #0x10] */
/* @0xeab54 cmp r0, #0 */
/* @0xeab58 beq 0xeab80 <_Z6DoPushjPhPKhP6VMExec+0xcf8> */
/* @0xeab5c subs r3, r3, #1 */
/* @0xeab60 ldr r0, [r0, #0xc] */
/* @0xeab64 moveq r2, #0 */
/* @0xeab68 movne r2, #1 */
/* @0xeab6c cmp r0, #0 */
/* @0xeab70 moveq r2, #0 */
/* @0xeab74 andne r2, r2, #1 */
/* @0xeab78 cmp r2, #0 */
/* @0xeab7c bne 0xeab5c <_Z6DoPushjPhPKhP6VMExec+0xcd4> */
/* @0xeab80 ldr r1, [r0, #0x4] */
/* @0xeab84 cmp r1, #0 */
/* @0xeab88 beq 0xeb2a8 <_Z6DoPushjPhPKhP6VMExec+0x1420> */
/* @0xeab8c ldr r0, [r1] */
/* @0xeab90 cmp r0, #0 */
/* @0xeab94 beq 0xea960 <_Z6DoPushjPhPKhP6VMExec+0xad8> */
/* @0xeab98 ldr r3, [r0, #0x4] */
/* @0xeab9c cmp r3, #0 */
/* @0xeaba0 beq 0xeb364 <_Z6DoPushjPhPKhP6VMExec+0x14dc> */
/* @0xeaba4 add r0, r3, #16 */
/* @0xeaba8 ldr r0, [r0] */
/* @0xeabac ldr r3, [r0, #0x4] */
/* @0xeabb0 cmp r3, #0 */
/* @0xeabb4 beq 0xeb354 <_Z6DoPushjPhPKhP6VMExec+0x14cc> */
/* @0xeabb8 add r9, r3, r9, lsl #4 */
/* @0xeabbc ldr r2, [r4, #-0x4] */
/* @0xeabc0 bic r3, r2, #-16777216 */
/* @0xeabc4 cmp r3, #1 */
/* @0xeabc8 beq 0xeb19c <_Z6DoPushjPhPKhP6VMExec+0x1314> */
/* @0xeabcc cmp r3, #2 */
/* @0xeabd0 bne 0xeabf4 <_Z6DoPushjPhPKhP6VMExec+0xd6c> */
/* @0xeabd4 sub r3, r2, #1 */
/* @0xeabd8 bic r3, r3, #-16777216 */
/* @0xeabdc bic r3, r3, #3 */
/* @0xeabe0 cmp r3, #0 */
/* @0xeabe4 beq 0xeb2c4 <_Z6DoPushjPhPKhP6VMExec+0x143c> */
/* @0xeabe8 mov r2, #0 */
/* @0xeabec mov r3, #5 */
/* @0xeabf0 stmdb r4, {r2, r3} */
/* @0xeabf4 ldr r3, [r9, #0xc] */
/* @0xeabf8 mov r2, #0 */
/* @0xeabfc ldr r1, [r9, #0x8] */
/* @0xeac00 str r2, [r4, #-0x10] */
/* @0xeac04 str r3, [r4, #-0x4] */
/* @0xeac08 ldr r2, [r9, #0xc] */
/* @0xeac0c str r1, [r4, #-0x8] */
/* @0xeac10 bic r2, r2, #-16777216 */
/* @0xeac14 cmp r2, #14 */
/* @0xeac18 addls pc, pc, r2, lsl #2 */
/* @0xeac1c b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac20 b 0xeac70 <_Z6DoPushjPhPKhP6VMExec+0xde8> */
/* @0xeac24 b 0xeacd0 <_Z6DoPushjPhPKhP6VMExec+0xe48> */
/* @0xeac28 b 0xeacbc <_Z6DoPushjPhPKhP6VMExec+0xe34> */
/* @0xeac2c b 0xeac5c <_Z6DoPushjPhPKhP6VMExec+0xdd4> */
/* @0xeac30 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac34 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac38 b 0xeac8c <_Z6DoPushjPhPKhP6VMExec+0xe04> */
/* @0xeac3c b 0xeac5c <_Z6DoPushjPhPKhP6VMExec+0xdd4> */
/* @0xeac40 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac44 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac48 b 0xeac70 <_Z6DoPushjPhPKhP6VMExec+0xde8> */
/* @0xeac4c b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac50 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac54 b 0xeac70 <_Z6DoPushjPhPKhP6VMExec+0xde8> */
/* @0xeac58 b 0xeac5c <_Z6DoPushjPhPKhP6VMExec+0xdd4> */
/* @0xeac5c ldr r2, [r9] */
/* @0xeac60 mov r11, #1 */
/* @0xeac64 str r2, [r4, #-0x10] */
/* @0xeac68 mov r4, r10 */
/* @0xeac6c b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xeac70 ldr r1, [r9] */
/* @0xeac74 mov r11, #1 */
/* @0xeac78 ldr r2, [r9, #0x4] */
/* @0xeac7c str r1, [r4, #-0x10] */
/* @0xeac80 str r2, [r4, #-0xc] */
/* @0xeac84 mov r4, r10 */
/* @0xeac88 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xeac8c ldr r2, [r9] */
/* @0xeac90 str r2, [r4, #-0x10] */
/* @0xeac94 ldr r2, [r9] */
/* @0xeac98 cmp r2, #0 */
/* @0xeac9c beq 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeaca0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xeaca4 ldr r1, [r9] */
/* @0xeaca8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xeacac mov r11, #1 */
/* @0xeacb0 ldr r3, [r4, #-0x4] */
/* @0xeacb4 mov r4, r10 */
/* @0xeacb8 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xeacbc ldr r2, [r9] */
/* @0xeacc0 cmp r2, #0 */
/* @0xeacc4 str r2, [r4, #-0x10] */
/* @0xeacc8 bne 0xea754 <_Z6DoPushjPhPKhP6VMExec+0x8cc> */
/* @0xeaccc b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeacd0 ldr r0, [r9] */
/* @0xeacd4 b 0xea72c <_Z6DoPushjPhPKhP6VMExec+0x8a4> */
/* @0xeacd8 and r12, r2, r1 */
/* @0xeacdc cmp r12, #6 */
/* @0xeace0 bne 0xeacfc <_Z6DoPushjPhPKhP6VMExec+0xe74> */
/* @0xeace4 ldr r3, [r4] */
/* @0xeace8 cmp r3, #0 */
/* @0xeacec beq 0xeacfc <_Z6DoPushjPhPKhP6VMExec+0xe74> */
/* @0xeacf0 ldr r1, [r3, #0x48] */
/* @0xeacf4 cmp r1, #2 */
/* @0xeacf8 beq 0xeb334 <_Z6DoPushjPhPKhP6VMExec+0x14ac> */
/* @0xeacfc mvn r3, #-16777216 */
/* @0xead00 cmp r2, r3 */
/* @0xead04 bne 0xea868 <_Z6DoPushjPhPKhP6VMExec+0x9e0> */
/* @0xead08 mov r3, #5 */
/* @0xead0c str r3, [r4, #0xc] */
/* @0xead10 b 0xea868 <_Z6DoPushjPhPKhP6VMExec+0x9e0> */
/* @0xead14 cmn r3, #1 */
/* @0xead18 beq 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xead1c add r3, r12, r3 */
/* @0xead20 add r11, r11, r3, lsl #2 */
/* @0xead24 cmn r11, #4 */
/* @0xead28 beq 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xead2c ldr r1, [r11, #0x4] */
/* @0xead30 mov r0, r4 */
/* @0xead34 ldr r2, [sp, #0x24] */
/* @0xead38 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0xead3c b 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xead40 ldr r9, [r4, #-0x10] */
/* @0xead44 cmp r9, #0 */
/* @0xead48 beq 0xead68 <_Z6DoPushjPhPKhP6VMExec+0xee0> */
/* @0xead4c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xead50 ldr r3, [r9, #0x4] */
/* @0xead54 sub r3, r3, #1 */
/* @0xead58 str r3, [r9, #0x4] */
/* @0xead5c cmp r3, #0 */
/* @0xead60 beq 0xeb1d4 <_Z6DoPushjPhPKhP6VMExec+0x134c> */
/* @0xead64 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xead68 mov r3, #0 */
/* @0xead6c str r3, [r4, #-0x10] */
/* @0xead70 b 0xea4a8 <_Z6DoPushjPhPKhP6VMExec+0x620> */
/* @0xead74 ldr r9, [sp, #0x3c] */
/* @0xead78 ldr r0, [r9, #0x40] */
/* @0xead7c cmp r0, #0 */
/* @0xead80 beq 0xead98 <_Z6DoPushjPhPKhP6VMExec+0xf10> */
/* @0xead84 ldr r1, [pc, #0x148] */
/* @0xead88 add r1, pc, r1 */
/* @0xead8c bl 0xb6574 <strcmp@plt> */
/* @0xead90 cmp r0, #0 */
/* @0xead94 beq 0xeb130 <_Z6DoPushjPhPKhP6VMExec+0x12a8> */
/* @0xead98 mov r1, r11 */
/* @0xead9c add r11, sp, #108 */
/* @0xeada0 mov r3, #5 */
/* @0xeada4 str r3, [sp, #0x78] */
/* @0xeada8 mov r0, r11 */
/* @0xeadac str r3, [sp, #0x18] */
/* @0xeadb0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0xeadb4 ldr r2, [sp, #0x6c] */
/* @0xeadb8 ldr r3, [sp, #0x18] */
/* @0xeadbc mvn r12, #-16777216 */
/* @0xeadc0 mov r0, r9 */
/* @0xeadc4 add r1, sp, #124 */
/* @0xeadc8 str r3, [r4, #0x1c] */
/* @0xeadcc mov r3, #0 */
/* @0xeadd0 str r12, [sp, #0x88] */
/* @0xeadd4 str r3, [sp, #0x7c] */
/* @0xeadd8 str r3, [sp, #0x80] */
/* @0xeaddc str r3, [sp, #0x84] */
/* @0xeade0 ldr r2, [r2] */
/* @0xeade4 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0xeade8 ldr r2, [r4, #0x1c] */
/* @0xeadec bic r3, r2, #-16777216 */
/* @0xeadf0 cmp r3, #1 */
/* @0xeadf4 beq 0xeb1ac <_Z6DoPushjPhPKhP6VMExec+0x1324> */
/* @0xeadf8 cmp r3, #2 */
/* @0xeadfc bne 0xeae24 <_Z6DoPushjPhPKhP6VMExec+0xf9c> */
/* @0xeae00 sub r3, r2, #1 */
/* @0xeae04 bic r3, r3, #-16777216 */
/* @0xeae08 bic r3, r3, #3 */
/* @0xeae0c cmp r3, #0 */
/* @0xeae10 beq 0xeb2d0 <_Z6DoPushjPhPKhP6VMExec+0x1448> */
/* @0xeae14 mov r2, #0 */
/* @0xeae18 mov r3, #5 */
/* @0xeae1c str r2, [r4, #0x18] */
/* @0xeae20 str r3, [r4, #0x1c] */
/* @0xeae24 ldr r3, [sp, #0x88] */
/* @0xeae28 mov r1, #0 */
/* @0xeae2c ldr r2, [sp, #0x84] */
/* @0xeae30 str r1, [r4, #0x10] */
/* @0xeae34 str r3, [r4, #0x1c] */
/* @0xeae38 ldr r3, [sp, #0x88] */
/* @0xeae3c str r2, [r4, #0x18] */
/* @0xeae40 bic r3, r3, #-16777216 */
/* @0xeae44 cmp r3, #14 */
/* @0xeae48 addls pc, pc, r3, lsl #2 */
/* @0xeae4c b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae50 b 0xeaf50 <_Z6DoPushjPhPKhP6VMExec+0x10c8> */
/* @0xeae54 b 0xeafb4 <_Z6DoPushjPhPKhP6VMExec+0x112c> */
/* @0xeae58 b 0xeaf88 <_Z6DoPushjPhPKhP6VMExec+0x1100> */
/* @0xeae5c b 0xeaef4 <_Z6DoPushjPhPKhP6VMExec+0x106c> */
/* @0xeae60 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae64 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae68 b 0xeaf64 <_Z6DoPushjPhPKhP6VMExec+0x10dc> */
/* @0xeae6c b 0xeaef4 <_Z6DoPushjPhPKhP6VMExec+0x106c> */
/* @0xeae70 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae74 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae78 b 0xeaf50 <_Z6DoPushjPhPKhP6VMExec+0x10c8> */
/* @0xeae7c b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae80 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae84 b 0xeaf50 <_Z6DoPushjPhPKhP6VMExec+0x10c8> */
/* @0xeae88 b 0xeaef4 <_Z6DoPushjPhPKhP6VMExec+0x106c> */
/* @0xeae8c ldrhteq r7, [r0], -r0 */
/* @0xeae90 .word 0xffffbd00 */
/* @0xeae94 .word 0xffffc110 */
/* @0xeae98 eoreq r10, r4, r4, lsl r6 */
/* @0xeae9c .word 0xffffc114 */
/* @0xeaea0 .word 0xffffbcf4 */
/* @0xeaea4 .word 0xffffc118 */
/* @0xeaea8 .word 0xffffbf24 */
/* @0xeaeac eoreq r10, r4, r8, lsr #14 */
/* @0xeaeb0 .word 0xffffc0c0 */
/* @0xeaeb4 .word 0xffffbf68 */
/* @0xeaeb8 eoreq r10, r4, r0, asr r3 */
/* @0xeaebc .word 0xffffbf30 */
/* @0xeaec0 .word 0xffffbf28 */
/* @0xeaec4 .word 0xffffbf2c */
/* @0xeaec8 .word 0xffffbf34 */
/* @0xeaecc eoreq r10, r4, r12, rrx */
/* @0xeaed0 eoreq r9, r4, r0, ror #31 */
/* @0xeaed4 mlaeq r4, r0, r11, r9 */
/* @0xeaed8 eoreq r9, r4, r4, lsl r9 */
/* @0xeaedc .word 0xffffc0fc */
/* @0xeaee0 eoreq r9, r4, r12, lsl #11 */
/* @0xeaee4 eoreq r9, r4, r0, lsl r5 */
/* @0xeaee8 .word 0x002496f8 */
/* @0xeaeec mlaeq r4, r0, r3, r9 */
/* @0xeaef0 eoreq r9, r4, r8, lsl #11 */
/* @0xeaef4 ldr r3, [sp, #0x7c] */
/* @0xeaef8 str r3, [r4, #0x10] */
/* @0xeaefc ldr r3, [sp, #0x78] */
/* @0xeaf00 sub r3, r3, #1 */
/* @0xeaf04 bic r3, r3, #-16777216 */
/* @0xeaf08 bic r3, r3, #3 */
/* @0xeaf0c cmp r3, #0 */
/* @0xeaf10 beq 0xeb1bc <_Z6DoPushjPhPKhP6VMExec+0x1334> */
/* @0xeaf14 mov r11, #1 */
/* @0xeaf18 ldr r2, [r4, #0x1c] */
/* @0xeaf1c mvn r3, #-16777216 */
/* @0xeaf20 cmp r2, r3 */
/* @0xeaf24 moveq r3, #5 */
/* @0xeaf28 streq r3, [r4, #0x1c] */
/* @0xeaf2c ldr r3, [sp, #0x68] */
/* @0xeaf30 sub r3, r3, #1 */
/* @0xeaf34 bic r3, r3, #-16777216 */
/* @0xeaf38 bic r3, r3, #3 */
/* @0xeaf3c cmp r3, #0 */
/* @0xeaf40 beq 0xeb124 <_Z6DoPushjPhPKhP6VMExec+0x129c> */
/* @0xeaf44 ldr r3, [r4, #0x1c] */
/* @0xeaf48 mov r4, r10 */
/* @0xeaf4c b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xeaf50 ldr r2, [sp, #0x7c] */
/* @0xeaf54 ldr r3, [sp, #0x80] */
/* @0xeaf58 str r2, [r4, #0x10] */
/* @0xeaf5c str r3, [r4, #0x14] */
/* @0xeaf60 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeaf64 ldr r3, [sp, #0x7c] */
/* @0xeaf68 str r3, [r4, #0x10] */
/* @0xeaf6c ldr r3, [sp, #0x7c] */
/* @0xeaf70 cmp r3, #0 */
/* @0xeaf74 beq 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeaf78 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xeaf7c ldr r1, [sp, #0x7c] */
/* @0xeaf80 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xeaf84 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeaf88 ldr r3, [sp, #0x7c] */
/* @0xeaf8c cmp r3, #0 */
/* @0xeaf90 str r3, [r4, #0x10] */
/* @0xeaf94 beq 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeaf98 ldr r1, [r3, #0x8] */
/* @0xeaf9c ldr r2, [r3] */
/* @0xeafa0 cmp r1, #0 */
/* @0xeafa4 streq r10, [r3, #0x8] */
/* @0xeafa8 add r2, r2, #1 */
/* @0xeafac str r2, [r3] */
/* @0xeafb0 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeafb4 ldr r0, [sp, #0x7c] */
/* @0xeafb8 bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */
/* @0xeafbc str r0, [r4, #0x10] */
/* @0xeafc0 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeafc4 cmp lr, #3 */
/* @0xeafc8 beq 0xead74 <_Z6DoPushjPhPKhP6VMExec+0xeec> */
/* @0xeafcc ldr r1, [sp, #0x2c] */
/* @0xeafd0 add r0, sp, #92 */
/* @0xeafd4 bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0xeafd8 cmp r0, #1 */
/* @0xeafdc ldrne r9, [sp, #0x5c] */
/* @0xeafe0 bne 0xead78 <_Z6DoPushjPhPKhP6VMExec+0xef0> */
/* @0xeafe4 ldr r0, [pc, #-0x114] */
/* @0xeafe8 add r0, pc, r0 */
/* @0xeafec bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xeaff0 b 0xea024 <_Z6DoPushjPhPKhP6VMExec+0x19c> */
/* @0xeaff4 ldr r0, [sp, #0x2c] */
/* @0xeaff8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeaffc b 0xea8ac <_Z6DoPushjPhPKhP6VMExec+0xa24> */
/* @0xeb000 add r0, sp, #108 */
/* @0xeb004 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb008 b 0xea880 <_Z6DoPushjPhPKhP6VMExec+0x9f8> */
/* @0xeb00c ldr r1, [sp, #0x2c] */
/* @0xeb010 add r0, sp, #108 */
/* @0xeb014 bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0xeb018 cmp r0, #1 */
/* @0xeb01c beq 0xeb370 <_Z6DoPushjPhPKhP6VMExec+0x14e8> */
/* @0xeb020 ldr r3, [sp, #0x6c] */
/* @0xeb024 str r3, [sp, #0x34] */
/* @0xeb028 b 0xea980 <_Z6DoPushjPhPKhP6VMExec+0xaf8> */
/* @0xeb02c ldr r3, [pc, #-0x158] */
/* @0xeb030 ldr r3, [r5, r3] */
/* @0xeb034 ldrb r9, [r3] */
/* @0xeb038 cmp r9, #0 */
/* @0xeb03c bne 0xea864 <_Z6DoPushjPhPKhP6VMExec+0x9dc> */
/* @0xeb040 ldr r2, [sp, #0x1c] */
/* @0xeb044 mov r1, r8 */
/* @0xeb048 ldr r0, [r7, #0x34] */
/* @0xeb04c bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xeb050 ldr r1, [sp, #0x1c] */
/* @0xeb054 mov r5, r0 */
/* @0xeb058 mov r0, r8 */
/* @0xeb05c bl 0x1f3f8c <_Z22Variable_GetObjectNameii> */
/* @0xeb060 ldr r2, [sp, #0x24] */
/* @0xeb064 ldr r1, [sp, #0x1c] */
/* @0xeb068 str r5, [sp] */
/* @0xeb06c add r5, sp, #140 */
/* @0xeb070 str r2, [sp, #0x8] */
/* @0xeb074 ldr r2, [pc, #-0x19c] */
/* @0xeb078 str r1, [sp, #0x4] */
/* @0xeb07c mov r1, #2048 */
/* @0xeb080 add r2, pc, r2 */
/* @0xeb084 mov r3, r0 */
/* @0xeb088 mov r0, r5 */
/* @0xeb08c bl 0xb65c8 <snprintf@plt> */
/* @0xeb090 mov r0, r5 */
/* @0xeb094 strb r9, [sp, #0x88b] */
/* @0xeb098 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xeb09c b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xeb0a0 mov r1, r4 */
/* @0xeb0a4 mov r0, r9 */
/* @0xeb0a8 str r3, [sp, #0x18] */
/* @0xeb0ac bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xeb0b0 ldr r3, [sp, #0x18] */
/* @0xeb0b4 mov r1, r0 */
/* @0xeb0b8 b 0xea430 <_Z6DoPushjPhPKhP6VMExec+0x5a8> */
/* @0xeb0bc ldr r2, [sp, #0x1c] */
/* @0xeb0c0 mov r1, r8 */
/* @0xeb0c4 ldr r0, [r7, #0x34] */
/* @0xeb0c8 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xeb0cc ldr r1, [sp, #0x1c] */
/* @0xeb0d0 mov r4, r0 */
/* @0xeb0d4 mov r0, r8 */
/* @0xeb0d8 bl 0x1f3f8c <_Z22Variable_GetObjectNameii> */
/* @0xeb0dc ldr r2, [sp, #0x24] */
/* @0xeb0e0 ldr r1, [sp, #0x1c] */
/* @0xeb0e4 str r4, [sp] */
/* @0xeb0e8 add r4, sp, #140 */
/* @0xeb0ec str r2, [sp, #0x8] */
/* @0xeb0f0 ldr r2, [pc, #-0x214] */
/* @0xeb0f4 str r1, [sp, #0x4] */
/* @0xeb0f8 mov r1, #2048 */
/* @0xeb0fc add r2, pc, r2 */
/* @0xeb100 mov r3, r0 */
/* @0xeb104 mov r0, r4 */
/* @0xeb108 bl 0xb65c8 <snprintf@plt> */
/* @0xeb10c mov r0, r4 */
/* @0xeb110 strb r9, [sp, #0x88b] */
/* @0xeb114 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xeb118 b 0xea024 <_Z6DoPushjPhPKhP6VMExec+0x19c> */
/* @0xeb11c mov r11, r0 */
/* @0xeb120 b 0xea5a8 <_Z6DoPushjPhPKhP6VMExec+0x720> */
/* @0xeb124 add r0, sp, #92 */
/* @0xeb128 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb12c b 0xeaf44 <_Z6DoPushjPhPKhP6VMExec+0x10bc> */
/* @0xeb130 mov r1, r11 */
/* @0xeb134 ldr r0, [sp, #0x2c] */
/* @0xeb138 mov r2, r10 */
/* @0xeb13c bl 0x249cdc <_Z10JSArrayGetP6RValueS0_S0_> */
/* @0xeb140 mov r11, r0 */
/* @0xeb144 b 0xeaf18 <_Z6DoPushjPhPKhP6VMExec+0x1090> */
/* @0xeb148 ldr r2, [sp, #0x4c] */
/* @0xeb14c mov r0, r10 */
/* @0xeb150 ldr r3, [sp, #0x50] */
/* @0xeb154 ldr r1, [sp, #0x2c] */
/* @0xeb158 vmov d7, r2, r3 */
/* @0xeb15c vcvt.s32.f64 s15, d7 */
/* @0xeb160 vmov r2, s15 */
/* @0xeb164 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0xeb168 ldr r3, [sp, #0x48] */
/* @0xeb16c sub r3, r3, #1 */
/* @0xeb170 bic r3, r3, #-16777216 */
/* @0xeb174 bic r3, r3, #3 */
/* @0xeb178 cmp r3, #0 */
/* @0xeb17c beq 0xeb29c <_Z6DoPushjPhPKhP6VMExec+0x1414> */
/* @0xeb180 mov r3, #0 */
/* @0xeb184 mov r2, #5 */
/* @0xeb188 str r3, [sp, #0x44] */
/* @0xeb18c mov r11, #1 */
/* @0xeb190 str r3, [sp, #0x3c] */
/* @0xeb194 str r2, [sp, #0x48] */
/* @0xeb198 b 0xeaf44 <_Z6DoPushjPhPKhP6VMExec+0x10bc> */
/* @0xeb19c ldr r0, [r4, #-0x10] */
/* @0xeb1a0 bl 0xdc42c <_ZN9_RefThingIPKcE6removeEPS2_> */
/* @0xeb1a4 str r0, [r4, #-0x10] */
/* @0xeb1a8 b 0xeabf4 <_Z6DoPushjPhPKhP6VMExec+0xd6c> */
/* @0xeb1ac ldr r0, [r4, #0x10] */
/* @0xeb1b0 bl 0xdc42c <_ZN9_RefThingIPKcE6removeEPS2_> */
/* @0xeb1b4 str r0, [r4, #0x10] */
/* @0xeb1b8 b 0xeae24 <_Z6DoPushjPhPKhP6VMExec+0xf9c> */
/* @0xeb1bc mov r0, r11 */
/* @0xeb1c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb1c4 b 0xeaf14 <_Z6DoPushjPhPKhP6VMExec+0x108c> */
/* @0xeb1c8 mov r0, r10 */
/* @0xeb1cc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb1d0 b 0xea49c <_Z6DoPushjPhPKhP6VMExec+0x614> */
/* @0xeb1d4 ldr r0, [r9] */
/* @0xeb1d8 str r3, [sp, #0x18] */
/* @0xeb1dc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xeb1e0 ldr r3, [sp, #0x18] */
/* @0xeb1e4 str r3, [r9] */
/* @0xeb1e8 str r3, [r9, #0x8] */
/* @0xeb1ec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xeb1f0 ldr r3, [r9, #0x4] */
/* @0xeb1f4 sub r3, r3, #1 */
/* @0xeb1f8 str r3, [r9, #0x4] */
/* @0xeb1fc cmp r3, #0 */
/* @0xeb200 beq 0xeb2f4 <_Z6DoPushjPhPKhP6VMExec+0x146c> */
/* @0xeb204 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xeb208 mov r0, r9 */
/* @0xeb20c bl 0x27d1d0 <_ZdlPv> */
/* @0xeb210 b 0xead64 <_Z6DoPushjPhPKhP6VMExec+0xedc> */
/* @0xeb214 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xeb218 mov r0, r8 */
/* @0xeb21c bl 0x19ed54 <_Z11Object_Namei> */
/* @0xeb220 ldr r1, [pc, #-0x340] */
/* @0xeb224 mov r2, r8 */
/* @0xeb228 add r1, pc, r1 */
/* @0xeb22c mov r3, r0 */
/* @0xeb230 mov r0, r7 */
/* @0xeb234 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xeb238 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xeb23c ldr r2, [sp, #0x1c] */
/* @0xeb240 mov r1, r8 */
/* @0xeb244 ldr r0, [r7, #0x34] */
/* @0xeb248 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xeb24c ldr r1, [sp, #0x1c] */
/* @0xeb250 mov r5, r0 */
/* @0xeb254 mov r0, r8 */
/* @0xeb258 bl 0x1f3f8c <_Z22Variable_GetObjectNameii> */
/* @0xeb25c ldr r2, [sp, #0x24] */
/* @0xeb260 ldr r1, [sp, #0x1c] */
/* @0xeb264 str r5, [sp] */
/* @0xeb268 add r5, sp, #140 */
/* @0xeb26c str r2, [sp, #0x8] */
/* @0xeb270 ldr r2, [pc, #-0x38c] */
/* @0xeb274 str r1, [sp, #0x4] */
/* @0xeb278 mov r1, #2048 */
/* @0xeb27c add r2, pc, r2 */
/* @0xeb280 mov r3, r0 */
/* @0xeb284 mov r0, r5 */
/* @0xeb288 bl 0xb65c8 <snprintf@plt> */
/* @0xeb28c mov r0, r5 */
/* @0xeb290 strb r9, [sp, #0x88b] */
/* @0xeb294 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xeb298 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xeb29c ldr r0, [sp, #0x2c] */
/* @0xeb2a0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb2a4 b 0xeb180 <_Z6DoPushjPhPKhP6VMExec+0x12f8> */
/* @0xeb2a8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xeb2ac subs r1, r0, #0 */
/* @0xeb2b0 bne 0xeab8c <_Z6DoPushjPhPKhP6VMExec+0xd04> */
/* @0xeb2b4 ldr r3, [r4, #-0x4] */
/* @0xeb2b8 mov r11, r1 */
/* @0xeb2bc mov r4, r10 */
/* @0xeb2c0 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xeb2c4 mov r0, r10 */
/* @0xeb2c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb2cc b 0xeabe8 <_Z6DoPushjPhPKhP6VMExec+0xd60> */
/* @0xeb2d0 mov r0, r10 */
/* @0xeb2d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb2d8 b 0xeae14 <_Z6DoPushjPhPKhP6VMExec+0xf8c> */
/* @0xeb2dc bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xeb2e0 mov r1, r0 */
/* @0xeb2e4 b 0xea324 <_Z6DoPushjPhPKhP6VMExec+0x49c> */
/* @0xeb2e8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xeb2ec mov r1, r0 */
/* @0xeb2f0 b 0xea378 <_Z6DoPushjPhPKhP6VMExec+0x4f0> */
/* @0xeb2f4 ldr r0, [r9] */
/* @0xeb2f8 str r3, [sp, #0x18] */
/* @0xeb2fc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xeb300 ldr r3, [sp, #0x18] */
/* @0xeb304 str r3, [r9] */
/* @0xeb308 str r3, [r9, #0x8] */
/* @0xeb30c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xeb310 ldr r3, [r9, #0x4] */
/* @0xeb314 sub r3, r3, #1 */
/* @0xeb318 str r3, [r9, #0x4] */
/* @0xeb31c cmp r3, #0 */
/* @0xeb320 beq 0xeb380 <_Z6DoPushjPhPKhP6VMExec+0x14f8> */
/* @0xeb324 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xeb328 mov r0, r9 */
/* @0xeb32c bl 0x27d1d0 <_ZdlPv> */
/* @0xeb330 b 0xeb204 <_Z6DoPushjPhPKhP6VMExec+0x137c> */
/* @0xeb334 add r2, sp, #124 */
/* @0xeb338 ldr r0, [sp, #0x34] */
/* @0xeb33c mov r1, r4 */
/* @0xeb340 str r12, [sp, #0x88] */
/* @0xeb344 str r3, [sp, #0x7c] */
/* @0xeb348 bl 0x248fec <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_> */
/* @0xeb34c ldr r2, [r4, #0xc] */
/* @0xeb350 b 0xeacfc <_Z6DoPushjPhPKhP6VMExec+0xe74> */
/* @0xeb354 mov r1, r9 */
/* @0xeb358 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xeb35c mov r9, r0 */
/* @0xeb360 b 0xeabbc <_Z6DoPushjPhPKhP6VMExec+0xd34> */
/* @0xeb364 mov r1, #1 */
/* @0xeb368 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xeb36c b 0xeaba8 <_Z6DoPushjPhPKhP6VMExec+0xd20> */
/* @0xeb370 ldr r0, [pc, #-0x488] */
/* @0xeb374 add r0, pc, r0 */
/* @0xeb378 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xeb37c b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xeb380 ldr r0, [r9] */
/* @0xeb384 str r3, [sp, #0x18] */
/* @0xeb388 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xeb38c ldr r3, [sp, #0x18] */
/* @0xeb390 str r3, [r9] */
/* @0xeb394 str r3, [r9, #0x8] */
/* @0xeb398 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xeb39c ldr r3, [r9, #0x4] */
/* @0xeb3a0 sub r3, r3, #1 */
/* @0xeb3a4 str r3, [r9, #0x4] */
/* @0xeb3a8 cmp r3, #0 */
/* @0xeb3ac beq 0xeb3cc <_Z6DoPushjPhPKhP6VMExec+0x1544> */
/* @0xeb3b0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xeb3b4 mov r0, r9 */
/* @0xeb3b8 bl 0x27d1d0 <_ZdlPv> */
/* @0xeb3bc b 0xeb324 <_Z6DoPushjPhPKhP6VMExec+0x149c> */
/* @0xeb3c0 ldr r2, [r4, #0xc] */
/* @0xeb3c4 bic r12, r2, #-16777216 */
/* @0xeb3c8 b 0xeacdc <_Z6DoPushjPhPKhP6VMExec+0xe54> */
/* @0xeb3cc ldr r0, [r9] */
/* @0xeb3d0 str r3, [sp, #0x18] */
/* @0xeb3d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xeb3d8 ldr r3, [sp, #0x18] */
/* @0xeb3dc mov r0, r9 */
/* @0xeb3e0 str r3, [r9] */
/* @0xeb3e4 str r3, [r9, #0x8] */
/* @0xeb3e8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xeb3ec mov r0, r9 */
/* @0xeb3f0 bl 0x27d1d0 <_ZdlPv> */
/* @0xeb3f4 b 0xeb3b0 <_Z6DoPushjPhPKhP6VMExec+0x1528> */

/* ── FUNC 0xeb3f8 · DoConv(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=3340 · insn=832 */
/* @0xeb3f8 push {r4, r5, r6, r7, r8, lr} */
/* @0xeb3fc lsr r12, r0, #16 */
/* @0xeb400 ldr r6, [pc, #0xc04] */
/* @0xeb404 ubfx r0, r0, #0x8, #0x8 */
/* @0xeb408 sub sp, sp, #120 */
/* @0xeb40c uxtb r4, r12 */
/* @0xeb410 ldr r6, [pc, r6] */
/* @0xeb414 tst r0, #15 */
/* @0xeb418 mov r5, r1 */
/* @0xeb41c mov r8, r4 */
/* @0xeb420 ldr r2, [r6] */
/* @0xeb424 str r2, [sp, #0x74] */
/* @0xeb428 beq 0xeb43c <_Z6DoConvjPhPKhP6VMExec+0x44> */
/* @0xeb42c tst r0, #1 */
/* @0xeb430 bne 0xeb6a0 <_Z6DoConvjPhPKhP6VMExec+0x2a8> */
/* @0xeb434 tst r0, #2 */
/* @0xeb438 bne 0xeb6f8 <_Z6DoConvjPhPKhP6VMExec+0x300> */
/* @0xeb43c and r2, r4, #15 */
/* @0xeb440 cmp r2, #6 */
/* @0xeb444 addls pc, pc, r2, lsl #2 */
/* @0xeb448 b 0xec0fc <_Z6DoConvjPhPKhP6VMExec+0xd04> */
/* @0xeb44c b 0xeb644 <_Z6DoConvjPhPKhP6VMExec+0x24c> */
/* @0xeb450 b 0xeb468 <_Z6DoConvjPhPKhP6VMExec+0x70> */
/* @0xeb454 b 0xeb468 <_Z6DoConvjPhPKhP6VMExec+0x70> */
/* @0xeb458 b 0xeb644 <_Z6DoConvjPhPKhP6VMExec+0x24c> */
/* @0xeb45c b 0xeb468 <_Z6DoConvjPhPKhP6VMExec+0x70> */
/* @0xeb460 b 0xeb64c <_Z6DoConvjPhPKhP6VMExec+0x254> */
/* @0xeb464 b 0xeb468 <_Z6DoConvjPhPKhP6VMExec+0x70> */
/* @0xeb468 add r7, r5, #4 */
/* @0xeb46c asr r4, r4, #4 */
/* @0xeb470 cmp r4, #6 */
/* @0xeb474 addls pc, pc, r4, lsl #2 */
/* @0xeb478 b 0xeb49c <_Z6DoConvjPhPKhP6VMExec+0xa4> */
/* @0xeb47c b 0xeb690 <_Z6DoConvjPhPKhP6VMExec+0x298> */
/* @0xeb480 b 0xeb498 <_Z6DoConvjPhPKhP6VMExec+0xa0> */
/* @0xeb484 b 0xeb498 <_Z6DoConvjPhPKhP6VMExec+0xa0> */
/* @0xeb488 b 0xeb690 <_Z6DoConvjPhPKhP6VMExec+0x298> */
/* @0xeb48c b 0xeb498 <_Z6DoConvjPhPKhP6VMExec+0xa0> */
/* @0xeb490 b 0xeb698 <_Z6DoConvjPhPKhP6VMExec+0x2a0> */
/* @0xeb494 b 0xeb498 <_Z6DoConvjPhPKhP6VMExec+0xa0> */
/* @0xeb498 sub r7, r7, #4 */
/* @0xeb49c cmp r8, #102 */
/* @0xeb4a0 addls pc, pc, r8, lsl #2 */
/* @0xeb4a4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4a8 b 0xebd18 <_Z6DoConvjPhPKhP6VMExec+0x920> */
/* @0xeb4ac b 0xebd28 <_Z6DoConvjPhPKhP6VMExec+0x930> */
/* @0xeb4b0 b 0xebdc8 <_Z6DoConvjPhPKhP6VMExec+0x9d0> */
/* @0xeb4b4 b 0xebddc <_Z6DoConvjPhPKhP6VMExec+0x9e4> */
/* @0xeb4b8 b 0xebc98 <_Z6DoConvjPhPKhP6VMExec+0x8a0> */
/* @0xeb4bc b 0xebcb8 <_Z6DoConvjPhPKhP6VMExec+0x8c0> */
/* @0xeb4c0 b 0xebce4 <_Z6DoConvjPhPKhP6VMExec+0x8ec> */
/* @0xeb4c4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4c8 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4cc b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4d0 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4d4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4d8 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4dc b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4e0 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4e4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb4e8 b 0xebd04 <_Z6DoConvjPhPKhP6VMExec+0x90c> */
/* @0xeb4ec b 0xeb794 <_Z6DoConvjPhPKhP6VMExec+0x39c> */
/* @0xeb4f0 b 0xebdb4 <_Z6DoConvjPhPKhP6VMExec+0x9bc> */
/* @0xeb4f4 b 0xebc18 <_Z6DoConvjPhPKhP6VMExec+0x820> */
/* @0xeb4f8 b 0xebc2c <_Z6DoConvjPhPKhP6VMExec+0x834> */
/* @0xeb4fc b 0xebc6c <_Z6DoConvjPhPKhP6VMExec+0x874> */
/* @0xeb500 b 0xebe18 <_Z6DoConvjPhPKhP6VMExec+0xa20> */
/* @0xeb504 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb508 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb50c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb510 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb514 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb518 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb51c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb520 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb524 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb528 b 0xebdf0 <_Z6DoConvjPhPKhP6VMExec+0x9f8> */
/* @0xeb52c b 0xebe04 <_Z6DoConvjPhPKhP6VMExec+0xa0c> */
/* @0xeb530 b 0xeb794 <_Z6DoConvjPhPKhP6VMExec+0x39c> */
/* @0xeb534 b 0xeb794 <_Z6DoConvjPhPKhP6VMExec+0x39c> */
/* @0xeb538 b 0xeb7a4 <_Z6DoConvjPhPKhP6VMExec+0x3ac> */
/* @0xeb53c b 0xebb60 <_Z6DoConvjPhPKhP6VMExec+0x768> */
/* @0xeb540 b 0xebb70 <_Z6DoConvjPhPKhP6VMExec+0x778> */
/* @0xeb544 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb548 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb54c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb550 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb554 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb558 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb55c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb560 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb564 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb568 b 0xebb88 <_Z6DoConvjPhPKhP6VMExec+0x790> */
/* @0xeb56c b 0xebc04 <_Z6DoConvjPhPKhP6VMExec+0x80c> */
/* @0xeb570 b 0xebbd0 <_Z6DoConvjPhPKhP6VMExec+0x7d8> */
/* @0xeb574 b 0xebd18 <_Z6DoConvjPhPKhP6VMExec+0x920> */
/* @0xeb578 b 0xebbe4 <_Z6DoConvjPhPKhP6VMExec+0x7ec> */
/* @0xeb57c b 0xebb9c <_Z6DoConvjPhPKhP6VMExec+0x7a4> */
/* @0xeb580 b 0xebc4c <_Z6DoConvjPhPKhP6VMExec+0x854> */
/* @0xeb584 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb588 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb58c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb590 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb594 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb598 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb59c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5a0 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5a4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5a8 b 0xeb7e8 <_Z6DoConvjPhPKhP6VMExec+0x3f0> */
/* @0xeb5ac b 0xeb9b0 <_Z6DoConvjPhPKhP6VMExec+0x5b8> */
/* @0xeb5b0 b 0xeb80c <_Z6DoConvjPhPKhP6VMExec+0x414> */
/* @0xeb5b4 b 0xeb828 <_Z6DoConvjPhPKhP6VMExec+0x430> */
/* @0xeb5b8 b 0xeb7a4 <_Z6DoConvjPhPKhP6VMExec+0x3ac> */
/* @0xeb5bc b 0xeb8e0 <_Z6DoConvjPhPKhP6VMExec+0x4e8> */
/* @0xeb5c0 b 0xeb948 <_Z6DoConvjPhPKhP6VMExec+0x550> */
/* @0xeb5c4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5c8 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5cc b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5d0 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5d4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5d8 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5dc b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5e0 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5e4 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb5e8 b 0xeb994 <_Z6DoConvjPhPKhP6VMExec+0x59c> */
/* @0xeb5ec b 0xeb9d4 <_Z6DoConvjPhPKhP6VMExec+0x5dc> */
/* @0xeb5f0 b 0xeb9f4 <_Z6DoConvjPhPKhP6VMExec+0x5fc> */
/* @0xeb5f4 b 0xeba18 <_Z6DoConvjPhPKhP6VMExec+0x620> */
/* @0xeb5f8 b 0xeba24 <_Z6DoConvjPhPKhP6VMExec+0x62c> */
/* @0xeb5fc b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb600 b 0xeba54 <_Z6DoConvjPhPKhP6VMExec+0x65c> */
/* @0xeb604 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb608 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb60c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb610 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb614 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb618 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb61c b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb620 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb624 b 0xebe50 <_Z6DoConvjPhPKhP6VMExec+0xa58> */
/* @0xeb628 b 0xeba6c <_Z6DoConvjPhPKhP6VMExec+0x674> */
/* @0xeb62c b 0xebaf0 <_Z6DoConvjPhPKhP6VMExec+0x6f8> */
/* @0xeb630 b 0xebb2c <_Z6DoConvjPhPKhP6VMExec+0x734> */
/* @0xeb634 b 0xebd40 <_Z6DoConvjPhPKhP6VMExec+0x948> */
/* @0xeb638 b 0xeb848 <_Z6DoConvjPhPKhP6VMExec+0x450> */
/* @0xeb63c b 0xebd8c <_Z6DoConvjPhPKhP6VMExec+0x994> */
/* @0xeb640 b 0xeb794 <_Z6DoConvjPhPKhP6VMExec+0x39c> */
/* @0xeb644 add r7, r5, #8 */
/* @0xeb648 b 0xeb46c <_Z6DoConvjPhPKhP6VMExec+0x74> */
/* @0xeb64c ldr r2, [r5, #0xc] */
/* @0xeb650 cmp r2, #5 */
/* @0xeb654 beq 0xebef0 <_Z6DoConvjPhPKhP6VMExec+0xaf8> */
/* @0xeb658 ble 0xeb75c <_Z6DoConvjPhPKhP6VMExec+0x364> */
/* @0xeb65c cmp r2, #12 */
/* @0xeb660 beq 0xebef0 <_Z6DoConvjPhPKhP6VMExec+0xaf8> */
/* @0xeb664 bgt 0xeb7bc <_Z6DoConvjPhPKhP6VMExec+0x3c4> */
/* @0xeb668 cmp r2, #7 */
/* @0xeb66c andeq r12, r12, #240 */
/* @0xeb670 orreq r8, r12, #2 */
/* @0xeb674 beq 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xeb678 cmp r2, #10 */
/* @0xeb67c andeq r12, r12, #240 */
/* @0xeb680 orreq r8, r12, #3 */
/* @0xeb684 bne 0xebefc <_Z6DoConvjPhPKhP6VMExec+0xb04> */
/* @0xeb688 add r7, r5, #16 */
/* @0xeb68c b 0xeb46c <_Z6DoConvjPhPKhP6VMExec+0x74> */
/* @0xeb690 sub r7, r7, #8 */
/* @0xeb694 b 0xeb49c <_Z6DoConvjPhPKhP6VMExec+0xa4> */
/* @0xeb698 sub r7, r7, #16 */
/* @0xeb69c b 0xeb49c <_Z6DoConvjPhPKhP6VMExec+0xa4> */
/* @0xeb6a0 add r7, sp, #36 */
/* @0xeb6a4 and r1, r4, #15 */
/* @0xeb6a8 mov r2, r5 */
/* @0xeb6ac mov r0, r7 */
/* @0xeb6b0 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xeb6b4 ldr r2, [sp, #0x30] */
/* @0xeb6b8 mvn r3, #-16777216 */
/* @0xeb6bc and r2, r2, r3 */
/* @0xeb6c0 cmp r2, r3 */
/* @0xeb6c4 mov r4, r0 */
/* @0xeb6c8 beq 0xebe68 <_Z6DoConvjPhPKhP6VMExec+0xa70> */
/* @0xeb6cc mov r0, r7 */
/* @0xeb6d0 bl 0x2404bc <_Z12JS_ToBooleanR6RValue> */
/* @0xeb6d4 sub r12, r4, #4 */
/* @0xeb6d8 str r0, [r4, #-0x4] */
/* @0xeb6dc ldr r2, [sp, #0x74] */
/* @0xeb6e0 mov r0, r12 */
/* @0xeb6e4 ldr r3, [r6] */
/* @0xeb6e8 cmp r2, r3 */
/* @0xeb6ec bne 0xec0f8 <_Z6DoConvjPhPKhP6VMExec+0xd00> */
/* @0xeb6f0 add sp, sp, #120 */
/* @0xeb6f4 pop {r4, r5, r6, r7, r8, pc} */
/* @0xeb6f8 add r7, sp, #20 */
/* @0xeb6fc and r1, r4, #15 */
/* @0xeb700 mov r2, r5 */
/* @0xeb704 mov r0, r7 */
/* @0xeb708 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xeb70c ldr r2, [sp, #0x20] */
/* @0xeb710 mvn r3, #-16777216 */
/* @0xeb714 and r2, r2, r3 */
/* @0xeb718 cmp r2, r3 */
/* @0xeb71c mov r4, r0 */
/* @0xeb720 beq 0xebe7c <_Z6DoConvjPhPKhP6VMExec+0xa84> */
/* @0xeb724 mov r1, r7 */
/* @0xeb728 add r0, sp, #36 */
/* @0xeb72c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xeb730 cmp r0, #1 */
/* @0xeb734 beq 0xebf18 <_Z6DoConvjPhPKhP6VMExec+0xb20> */
/* @0xeb738 cmp r0, #0 */
/* @0xeb73c streq r0, [r4, #-0x4] */
/* @0xeb740 subeq r12, r4, #16 */
/* @0xeb744 ldreq r2, [sp, #0x24] */
/* @0xeb748 movne r12, r4 */
/* @0xeb74c ldreq r3, [sp, #0x28] */
/* @0xeb750 streq r2, [r4, #-0x10] */
/* @0xeb754 streq r3, [r4, #-0xc] */
/* @0xeb758 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb75c cmp r2, #1 */
/* @0xeb760 beq 0xebee4 <_Z6DoConvjPhPKhP6VMExec+0xaec> */
/* @0xeb764 ble 0xebe40 <_Z6DoConvjPhPKhP6VMExec+0xa48> */
/* @0xeb768 cmp r2, #2 */
/* @0xeb76c beq 0xebec8 <_Z6DoConvjPhPKhP6VMExec+0xad0> */
/* @0xeb770 cmp r2, #3 */
/* @0xeb774 bne 0xebefc <_Z6DoConvjPhPKhP6VMExec+0xb04> */
/* @0xeb778 ldr r1, [pc, #0x890] */
/* @0xeb77c mov r0, r3 */
/* @0xeb780 str r3, [sp, #0xc] */
/* @0xeb784 add r1, pc, r1 */
/* @0xeb788 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xeb78c ldr r3, [sp, #0xc] */
/* @0xeb790 b 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xeb794 ldr r3, [r5] */
/* @0xeb798 mov r12, r7 */
/* @0xeb79c str r3, [r7] */
/* @0xeb7a0 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb7a4 ldr r3, [r5] */
/* @0xeb7a8 mov r12, r7 */
/* @0xeb7ac adds r3, r3, #0 */
/* @0xeb7b0 movne r3, #1 */
/* @0xeb7b4 str r3, [r7] */
/* @0xeb7b8 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb7bc cmp r2, #13 */
/* @0xeb7c0 beq 0xebe48 <_Z6DoConvjPhPKhP6VMExec+0xa50> */
/* @0xeb7c4 mvn r1, #-16777216 */
/* @0xeb7c8 cmp r2, r1 */
/* @0xeb7cc bne 0xebefc <_Z6DoConvjPhPKhP6VMExec+0xb04> */
/* @0xeb7d0 ldr r1, [pc, #0x83c] */
/* @0xeb7d4 mov r0, r3 */
/* @0xeb7d8 add r1, pc, r1 */
/* @0xeb7dc bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xeb7e0 mov r12, r5 */
/* @0xeb7e4 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb7e8 vmov.f64 d7, #5.000000e-01 */
/* @0xeb7ec vldr d6, [r5] */
/* @0xeb7f0 mov r12, r7 */
/* @0xeb7f4 vcmpe.f64 d6, d7 */
/* @0xeb7f8 vmrs APSR_nzcv, fpscr */
/* @0xeb7fc movle r3, #0 */
/* @0xeb800 movgt r3, #1 */
/* @0xeb804 str r3, [r7] */
/* @0xeb808 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb80c ldr r3, [r5] */
/* @0xeb810 mov r12, r7 */
/* @0xeb814 cmp r3, #0 */
/* @0xeb818 movle r3, #0 */
/* @0xeb81c movgt r3, #1 */
/* @0xeb820 str r3, [r7] */
/* @0xeb824 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb828 ldrd r2, r3, [r5] */
/* @0xeb82c mov r12, r7 */
/* @0xeb830 cmp r2, #1 */
/* @0xeb834 sbcs r1, r3, #0 */
/* @0xeb838 movlt r3, #0 */
/* @0xeb83c movge r3, #1 */
/* @0xeb840 str r3, [r7] */
/* @0xeb844 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb848 ldr r3, [r5] */
/* @0xeb84c cmp r3, #0 */
/* @0xeb850 beq 0xebf2c <_Z6DoConvjPhPKhP6VMExec+0xb34> */
/* @0xeb854 ldr r3, [pc, #0x7bc] */
/* @0xeb858 add r3, pc, r3 */
/* @0xeb85c add r5, sp, #52 */
/* @0xeb860 ldr r2, [pc, #0x7b4] */
/* @0xeb864 mov r1, #64 */
/* @0xeb868 add r2, pc, r2 */
/* @0xeb86c mov r0, r5 */
/* @0xeb870 bl 0xb65c8 <snprintf@plt> */
/* @0xeb874 mov r0, r5 */
/* @0xeb878 bl 0xb6538 <strlen@plt> */
/* @0xeb87c ldr r1, [pc, #0x79c] */
/* @0xeb880 movw r2, #0xf7e */
/* @0xeb884 add r1, pc, r1 */
/* @0xeb888 mov r3, #1 */
/* @0xeb88c add r0, r0, r3 */
/* @0xeb890 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xeb894 mov r1, r5 */
/* @0xeb898 mov r4, r0 */
/* @0xeb89c bl 0xb65a4 <strcpy@plt> */
/* @0xeb8a0 mov r0, #12 */
/* @0xeb8a4 bl 0x27c524 <_Znwj> */
/* @0xeb8a8 mov r5, r0 */
/* @0xeb8ac subs r0, r4, #0 */
/* @0xeb8b0 beq 0xeb8b8 <_Z6DoConvjPhPKhP6VMExec+0x4c0> */
/* @0xeb8b4 bl 0xb6538 <strlen@plt> */
/* @0xeb8b8 str r0, [r5, #0x8] */
/* @0xeb8bc mov r0, r4 */
/* @0xeb8c0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xeb8c4 mov r3, #1 */
/* @0xeb8c8 stm r5, {r0, r3} */
/* @0xeb8cc mov r0, r4 */
/* @0xeb8d0 str r5, [r7] */
/* @0xeb8d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xeb8d8 mov r12, r7 */
/* @0xeb8dc b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb8e0 ldr r3, [r5, #0xc] */
/* @0xeb8e4 cmp r3, #1 */
/* @0xeb8e8 bne 0xebf5c <_Z6DoConvjPhPKhP6VMExec+0xb64> */
/* @0xeb8ec ldr r3, [r5] */
/* @0xeb8f0 ldr r1, [pc, #0x72c] */
/* @0xeb8f4 cmp r3, #0 */
/* @0xeb8f8 add r1, pc, r1 */
/* @0xeb8fc ldrne r0, [r3] */
/* @0xeb900 moveq r0, r3 */
/* @0xeb904 bl 0xb6574 <strcmp@plt> */
/* @0xeb908 rsbs r0, r0, #1 */
/* @0xeb90c movlo r0, #0 */
/* @0xeb910 str r0, [r7] */
/* @0xeb914 ldr r3, [r5, #0xc] */
/* @0xeb918 sub r3, r3, #1 */
/* @0xeb91c bic r3, r3, #-16777216 */
/* @0xeb920 bic r3, r3, #3 */
/* @0xeb924 cmp r3, #0 */
/* @0xeb928 beq 0xebbc4 <_Z6DoConvjPhPKhP6VMExec+0x7cc> */
/* @0xeb92c mov r3, #0 */
/* @0xeb930 mov r2, #5 */
/* @0xeb934 mov r12, r7 */
/* @0xeb938 str r3, [r5, #0x8] */
/* @0xeb93c str r3, [r5] */
/* @0xeb940 str r2, [r5, #0xc] */
/* @0xeb944 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb948 ldr r4, [r5] */
/* @0xeb94c cmp r4, #0 */
/* @0xeb950 beq 0xec088 <_Z6DoConvjPhPKhP6VMExec+0xc90> */
/* @0xeb954 ldr r1, [pc, #0x6cc] */
/* @0xeb958 ldr r0, [r4] */
/* @0xeb95c add r1, pc, r1 */
/* @0xeb960 bl 0xb6574 <strcmp@plt> */
/* @0xeb964 rsbs r0, r0, #1 */
/* @0xeb968 movlo r0, #0 */
/* @0xeb96c str r0, [r7] */
/* @0xeb970 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xeb974 ldr r5, [r4, #0x4] */
/* @0xeb978 sub r5, r5, #1 */
/* @0xeb97c str r5, [r4, #0x4] */
/* @0xeb980 cmp r5, #0 */
/* @0xeb984 beq 0xebe90 <_Z6DoConvjPhPKhP6VMExec+0xa98> */
/* @0xeb988 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xeb98c mov r12, r7 */
/* @0xeb990 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb994 ldr r2, [r5] */
/* @0xeb998 mov r1, #0 */
/* @0xeb99c ldr r3, [r5, #0x4] */
/* @0xeb9a0 mov r12, r7 */
/* @0xeb9a4 str r1, [r7, #0xc] */
/* @0xeb9a8 stm r7, {r2, r3} */
/* @0xeb9ac b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb9b0 vmov.f32 s15, #5.000000e-01 */
/* @0xeb9b4 vldr s14, [r5] */
/* @0xeb9b8 mov r12, r7 */
/* @0xeb9bc vcmpe.f32 s14, s15 */
/* @0xeb9c0 vmrs APSR_nzcv, fpscr */
/* @0xeb9c4 movle r3, #0 */
/* @0xeb9c8 movgt r3, #1 */
/* @0xeb9cc str r3, [r7] */
/* @0xeb9d0 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb9d4 vldr s15, [r5] */
/* @0xeb9d8 vcvt.f64.f32 d6, s15 */
/* @0xeb9dc mov r1, #0 */
/* @0xeb9e0 mov r12, r7 */
/* @0xeb9e4 str r1, [r7, #0xc] */
/* @0xeb9e8 vmov r2, r3, d6 */
/* @0xeb9ec stm r7, {r2, r3} */
/* @0xeb9f0 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeb9f4 ldr r2, [r5] */
/* @0xeb9f8 mov r3, #0 */
/* @0xeb9fc str r3, [r7, #0xc] */
/* @0xeba00 mov r12, r7 */
/* @0xeba04 vmov s13, r2 */
/* @0xeba08 vcvt.f64.s32 d6, s13 */
/* @0xeba0c vmov r2, r3, d6 */
/* @0xeba10 stm r7, {r2, r3} */
/* @0xeba14 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeba18 ldr r2, [r5] */
/* @0xeba1c mov r1, #10 */
/* @0xeba20 b 0xeb99c <_Z6DoConvjPhPKhP6VMExec+0x5a4> */
/* @0xeba24 ldr r3, [r5] */
/* @0xeba28 mov r12, r7 */
/* @0xeba2c cmp r3, #0 */
/* @0xeba30 movne r2, #0 */
/* @0xeba34 moveq r2, r3 */
/* @0xeba38 movne r3, r2 */
/* @0xeba3c movtne r2, #0x3ff0 */
/* @0xeba40 str r3, [r7] */
/* @0xeba44 mov r3, #13 */
/* @0xeba48 str r2, [r7, #0x4] */
/* @0xeba4c str r3, [r7, #0xc] */
/* @0xeba50 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeba54 ldr r3, [r5] */
/* @0xeba58 mov r2, #1 */
/* @0xeba5c mov r12, r7 */
/* @0xeba60 str r2, [r7, #0xc] */
/* @0xeba64 str r3, [r7] */
/* @0xeba68 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xeba6c ldrd r2, r3, [r5] */
/* @0xeba70 add r4, sp, #52 */
/* @0xeba74 mov r1, #64 */
/* @0xeba78 mov r0, r4 */
/* @0xeba7c strd r2, r3, [sp] */
/* @0xeba80 ldr r2, [pc, #0x5a4] */
/* @0xeba84 add r2, pc, r2 */
/* @0xeba88 bl 0xb65c8 <snprintf@plt> */
/* @0xeba8c mov r0, r4 */
/* @0xeba90 bl 0xb6538 <strlen@plt> */
/* @0xeba94 ldr r1, [pc, #0x594] */
/* @0xeba98 movw r2, #0xf0d */
/* @0xeba9c add r1, pc, r1 */
/* @0xebaa0 mov r3, #1 */
/* @0xebaa4 add r0, r0, r3 */
/* @0xebaa8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xebaac mov r1, r4 */
/* @0xebab0 mov r5, r0 */
/* @0xebab4 bl 0xb65a4 <strcpy@plt> */
/* @0xebab8 mov r0, #12 */
/* @0xebabc bl 0x27c524 <_Znwj> */
/* @0xebac0 mov r4, r0 */
/* @0xebac4 subs r0, r5, #0 */
/* @0xebac8 beq 0xebad0 <_Z6DoConvjPhPKhP6VMExec+0x6d8> */
/* @0xebacc bl 0xb6538 <strlen@plt> */
/* @0xebad0 str r0, [r4, #0x8] */
/* @0xebad4 mov r0, r5 */
/* @0xebad8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xebadc mov r3, #1 */
/* @0xebae0 mov r12, r7 */
/* @0xebae4 stm r4, {r0, r3} */
/* @0xebae8 str r4, [r7] */
/* @0xebaec b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebaf0 vldr s14, [r5] */
/* @0xebaf4 vcvt.f64.f32 d7, s14 */
/* @0xebaf8 add r5, sp, #52 */
/* @0xebafc ldr r2, [pc, #0x530] */
/* @0xebb00 mov r1, #64 */
/* @0xebb04 add r2, pc, r2 */
/* @0xebb08 mov r0, r5 */
/* @0xebb0c vstr d7, [sp] */
/* @0xebb10 bl 0xb65c8 <snprintf@plt> */
/* @0xebb14 mov r0, r5 */
/* @0xebb18 bl 0xb6538 <strlen@plt> */
/* @0xebb1c ldr r1, [pc, #0x514] */
/* @0xebb20 movw r2, #0xf43 */
/* @0xebb24 add r1, pc, r1 */
/* @0xebb28 b 0xeb888 <_Z6DoConvjPhPKhP6VMExec+0x490> */
/* @0xebb2c add r4, sp, #52 */
/* @0xebb30 ldr r2, [pc, #0x504] */
/* @0xebb34 mov r1, #64 */
/* @0xebb38 ldr r3, [r5] */
/* @0xebb3c add r2, pc, r2 */
/* @0xebb40 mov r0, r4 */
/* @0xebb44 bl 0xb65c8 <snprintf@plt> */
/* @0xebb48 mov r0, r4 */
/* @0xebb4c bl 0xb6538 <strlen@plt> */
/* @0xebb50 ldr r1, [pc, #0x4e8] */
/* @0xebb54 movw r2, #0xf28 */
/* @0xebb58 add r1, pc, r1 */
/* @0xebb5c b 0xebaa0 <_Z6DoConvjPhPKhP6VMExec+0x6a8> */
/* @0xebb60 mov r0, r5 */
/* @0xebb64 mov r1, #0 */
/* @0xebb68 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xebb6c b 0xeb910 <_Z6DoConvjPhPKhP6VMExec+0x518> */
/* @0xebb70 ldr r4, [r5] */
/* @0xebb74 cmp r4, #0 */
/* @0xebb78 beq 0xec0c4 <_Z6DoConvjPhPKhP6VMExec+0xccc> */
/* @0xebb7c ldr r0, [r4] */
/* @0xebb80 bl 0xb66b8 <atoi@plt> */
/* @0xebb84 b 0xeb96c <_Z6DoConvjPhPKhP6VMExec+0x574> */
/* @0xebb88 ldrd r0, r1, [r5] */
/* @0xebb8c bl 0x3194a0 <__fixdfdi> */
/* @0xebb90 mov r12, r7 */
/* @0xebb94 strd r0, r1, [r7] */
/* @0xebb98 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebb9c mov r0, r5 */
/* @0xebba0 mov r1, #0 */
/* @0xebba4 bl 0xcea30 <_Z10YYGetInt64PK6RValuei> */
/* @0xebba8 ldr r3, [r5, #0xc] */
/* @0xebbac sub r3, r3, #1 */
/* @0xebbb0 bic r3, r3, #-16777216 */
/* @0xebbb4 bic r3, r3, #3 */
/* @0xebbb8 cmp r3, #0 */
/* @0xebbbc strd r0, r1, [r7] */
/* @0xebbc0 bne 0xeb92c <_Z6DoConvjPhPKhP6VMExec+0x534> */
/* @0xebbc4 mov r0, r5 */
/* @0xebbc8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xebbcc b 0xeb92c <_Z6DoConvjPhPKhP6VMExec+0x534> */
/* @0xebbd0 ldr r2, [r5] */
/* @0xebbd4 mov r12, r7 */
/* @0xebbd8 asr r3, r2, #31 */
/* @0xebbdc strd r2, r3, [r7] */
/* @0xebbe0 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebbe4 ldr r3, [r5] */
/* @0xebbe8 mov r2, #0 */
/* @0xebbec mov r12, r7 */
/* @0xebbf0 str r2, [r7, #0x4] */
/* @0xebbf4 subs r3, r3, r2 */
/* @0xebbf8 movne r3, #1 */
/* @0xebbfc str r3, [r7] */
/* @0xebc00 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebc04 ldr r0, [r5] */
/* @0xebc08 bl 0x319468 <__fixsfdi> */
/* @0xebc0c mov r12, r7 */
/* @0xebc10 strd r0, r1, [r7] */
/* @0xebc14 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebc18 ldrd r0, r1, [r5] */
/* @0xebc1c bl 0x319398 <__floatdisf> */
/* @0xebc20 mov r12, r7 */
/* @0xebc24 str r0, [r7] */
/* @0xebc28 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebc2c vmov.f32 s15, #1.000000e+00 */
/* @0xebc30 ldr r3, [r5] */
/* @0xebc34 vldr s14, [pc, #972] */
/* @0xebc38 mov r12, r7 */
/* @0xebc3c cmp r3, #0 */
/* @0xebc40 vmoveq.f32 s15, s14 */
/* @0xebc44 vstr s15, [r7] */
/* @0xebc48 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebc4c ldr r4, [r5] */
/* @0xebc50 cmp r4, #0 */
/* @0xebc54 beq 0xec070 <_Z6DoConvjPhPKhP6VMExec+0xc78> */
/* @0xebc58 ldr r0, [r4] */
/* @0xebc5c bl 0xb66c4 <atol@plt> */
/* @0xebc60 asr r1, r0, #31 */
/* @0xebc64 strd r0, r1, [r7] */
/* @0xebc68 b 0xeb970 <_Z6DoConvjPhPKhP6VMExec+0x578> */
/* @0xebc6c mov r0, r5 */
/* @0xebc70 mov r1, #0 */
/* @0xebc74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0xebc78 ldr r3, [r5, #0xc] */
/* @0xebc7c sub r3, r3, #1 */
/* @0xebc80 bic r3, r3, #-16777216 */
/* @0xebc84 bic r3, r3, #3 */
/* @0xebc88 cmp r3, #0 */
/* @0xebc8c str r0, [r7] */
/* @0xebc90 bne 0xeb92c <_Z6DoConvjPhPKhP6VMExec+0x534> */
/* @0xebc94 b 0xebbc4 <_Z6DoConvjPhPKhP6VMExec+0x7cc> */
/* @0xebc98 vmov.f64 d7, #1.000000e+00 */
/* @0xebc9c ldr r3, [r5] */
/* @0xebca0 vldr d6, [pc, #856] */
/* @0xebca4 mov r12, r7 */
/* @0xebca8 cmp r3, #0 */
/* @0xebcac vmoveq.f64 d7, d6 */
/* @0xebcb0 vstr d7, [r7] */
/* @0xebcb4 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebcb8 mov r0, r5 */
/* @0xebcbc mov r1, #0 */
/* @0xebcc0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xebcc4 ldr r3, [r5, #0xc] */
/* @0xebcc8 sub r3, r3, #1 */
/* @0xebccc bic r3, r3, #-16777216 */
/* @0xebcd0 bic r3, r3, #3 */
/* @0xebcd4 cmp r3, #0 */
/* @0xebcd8 strd r0, r1, [r7] */
/* @0xebcdc bne 0xeb92c <_Z6DoConvjPhPKhP6VMExec+0x534> */
/* @0xebce0 b 0xebbc4 <_Z6DoConvjPhPKhP6VMExec+0x7cc> */
/* @0xebce4 ldr r4, [r5] */
/* @0xebce8 cmp r4, #0 */
/* @0xebcec beq 0xec0ac <_Z6DoConvjPhPKhP6VMExec+0xcb4> */
/* @0xebcf0 ldr r0, [r4] */
/* @0xebcf4 mov r1, #0 */
/* @0xebcf8 bl 0xb6658 <strtod@plt> */
/* @0xebcfc strd r0, r1, [r7] */
/* @0xebd00 b 0xeb970 <_Z6DoConvjPhPKhP6VMExec+0x578> */
/* @0xebd04 vldr d7, [r5] */
/* @0xebd08 vcvt.f32.f64 s14, d7 */
/* @0xebd0c mov r12, r7 */
/* @0xebd10 vstr s14, [r7] */
/* @0xebd14 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebd18 ldrd r2, r3, [r5] */
/* @0xebd1c mov r12, r7 */
/* @0xebd20 strd r2, r3, [r7] */
/* @0xebd24 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebd28 vldr s14, [r5] */
/* @0xebd2c vcvt.s32.f32 s14, s14 */
/* @0xebd30 mov r12, r7 */
/* @0xebd34 vcvt.f64.s32 d7, s14 */
/* @0xebd38 vstr d7, [r7] */
/* @0xebd3c b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebd40 ldrd r4, r5, [r5] */
/* @0xebd44 add r8, sp, #52 */
/* @0xebd48 ldr r2, [pc, #0x2f4] */
/* @0xebd4c mov r1, #64 */
/* @0xebd50 mov r0, r8 */
/* @0xebd54 add r2, pc, r2 */
/* @0xebd58 strd r4, r5, [sp] */
/* @0xebd5c bl 0xb65c8 <snprintf@plt> */
/* @0xebd60 mov r0, r8 */
/* @0xebd64 bl 0xb6538 <strlen@plt> */
/* @0xebd68 ldr r1, [pc, #0x2d8] */
/* @0xebd6c mov r3, #1 */
/* @0xebd70 movw r2, #0xf5f */
/* @0xebd74 add r1, pc, r1 */
/* @0xebd78 add r0, r0, r3 */
/* @0xebd7c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xebd80 mov r1, r8 */
/* @0xebd84 mov r4, r0 */
/* @0xebd88 b 0xeb89c <_Z6DoConvjPhPKhP6VMExec+0x4a4> */
/* @0xebd8c ldr r3, [r5, #0xc] */
/* @0xebd90 cmp r3, #1 */
/* @0xebd94 bne 0xebf74 <_Z6DoConvjPhPKhP6VMExec+0xb7c> */
/* @0xebd98 ldr r3, [r5] */
/* @0xebd9c mov r12, r7 */
/* @0xebda0 ldr r2, [r3, #0x4] */
/* @0xebda4 str r3, [r7] */
/* @0xebda8 add r2, r2, #1 */
/* @0xebdac str r2, [r3, #0x4] */
/* @0xebdb0 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebdb4 vldr s15, [r5] */
/* @0xebdb8 vcvt.f32.s32 s15, s15 */
/* @0xebdbc mov r12, r7 */
/* @0xebdc0 vstr s15, [r7] */
/* @0xebdc4 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebdc8 vldr s14, [r5] */
/* @0xebdcc vcvt.f64.s32 d7, s14 */
/* @0xebdd0 mov r12, r7 */
/* @0xebdd4 vstr d7, [r7] */
/* @0xebdd8 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebddc ldrd r0, r1, [r5] */
/* @0xebde0 bl 0x319164 <__floatdidf> */
/* @0xebde4 mov r12, r7 */
/* @0xebde8 strd r0, r1, [r7] */
/* @0xebdec b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebdf0 vldr d7, [r5] */
/* @0xebdf4 vcvt.s32.f64 s14, d7 */
/* @0xebdf8 mov r12, r7 */
/* @0xebdfc vstr s14, [r7] */
/* @0xebe00 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebe04 vldr s15, [r5] */
/* @0xebe08 vcvt.s32.f32 s15, s15 */
/* @0xebe0c mov r12, r7 */
/* @0xebe10 vstr s15, [r7] */
/* @0xebe14 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebe18 ldr r4, [r5] */
/* @0xebe1c cmp r4, #0 */
/* @0xebe20 beq 0xec0d8 <_Z6DoConvjPhPKhP6VMExec+0xce0> */
/* @0xebe24 ldr r0, [r4] */
/* @0xebe28 mov r1, #0 */
/* @0xebe2c bl 0xb6658 <strtod@plt> */
/* @0xebe30 vmov d6, r0, r1 */
/* @0xebe34 vcvt.f32.f64 s15, d6 */
/* @0xebe38 vstr s15, [r7] */
/* @0xebe3c b 0xeb970 <_Z6DoConvjPhPKhP6VMExec+0x578> */
/* @0xebe40 cmp r2, #0 */
/* @0xebe44 bne 0xebefc <_Z6DoConvjPhPKhP6VMExec+0xb04> */
/* @0xebe48 and r8, r4, #240 */
/* @0xebe4c b 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xebe50 ldr r1, [pc, #0x1f4] */
/* @0xebe54 mov r0, r3 */
/* @0xebe58 add r1, pc, r1 */
/* @0xebe5c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xebe60 mov r12, r7 */
/* @0xebe64 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebe68 ldr r0, [pc, #0x1e0] */
/* @0xebe6c add r0, pc, r0 */
/* @0xebe70 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xebe74 mov r12, r4 */
/* @0xebe78 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebe7c ldr r0, [pc, #0x1d0] */
/* @0xebe80 add r0, pc, r0 */
/* @0xebe84 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xebe88 mov r12, r4 */
/* @0xebe8c b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebe90 ldr r0, [r4] */
/* @0xebe94 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xebe98 str r5, [r4] */
/* @0xebe9c str r5, [r4, #0x8] */
/* @0xebea0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xebea4 ldr r5, [r4, #0x4] */
/* @0xebea8 sub r5, r5, #1 */
/* @0xebeac str r5, [r4, #0x4] */
/* @0xebeb0 cmp r5, #0 */
/* @0xebeb4 beq 0xebf38 <_Z6DoConvjPhPKhP6VMExec+0xb40> */
/* @0xebeb8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xebebc mov r0, r4 */
/* @0xebec0 bl 0x27d1d0 <_ZdlPv> */
/* @0xebec4 b 0xeb988 <_Z6DoConvjPhPKhP6VMExec+0x590> */
/* @0xebec8 ldr r1, [pc, #0x188] */
/* @0xebecc mov r0, r3 */
/* @0xebed0 str r3, [sp, #0xc] */
/* @0xebed4 add r1, pc, r1 */
/* @0xebed8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xebedc ldr r3, [sp, #0xc] */
/* @0xebee0 b 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xebee4 and r12, r12, #240 */
/* @0xebee8 orr r8, r12, #6 */
/* @0xebeec b 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xebef0 and r12, r12, #240 */
/* @0xebef4 orr r8, r12, #4 */
/* @0xebef8 b 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xebefc ldr r1, [pc, #0x158] */
/* @0xebf00 mov r0, r3 */
/* @0xebf04 str r3, [sp, #0xc] */
/* @0xebf08 add r1, pc, r1 */
/* @0xebf0c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xebf10 ldr r3, [sp, #0xc] */
/* @0xebf14 b 0xeb688 <_Z6DoConvjPhPKhP6VMExec+0x290> */
/* @0xebf18 ldr r0, [pc, #0x140] */
/* @0xebf1c add r0, pc, r0 */
/* @0xebf20 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xebf24 mov r12, r4 */
/* @0xebf28 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebf2c ldr r3, [pc, #0x130] */
/* @0xebf30 add r3, pc, r3 */
/* @0xebf34 b 0xeb85c <_Z6DoConvjPhPKhP6VMExec+0x464> */
/* @0xebf38 ldr r0, [r4] */
/* @0xebf3c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xebf40 mov r0, r4 */
/* @0xebf44 str r5, [r4] */
/* @0xebf48 str r5, [r4, #0x8] */
/* @0xebf4c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xebf50 mov r0, r4 */
/* @0xebf54 bl 0x27d1d0 <_ZdlPv> */
/* @0xebf58 b 0xebeb8 <_Z6DoConvjPhPKhP6VMExec+0xac0> */
/* @0xebf5c mov r0, r5 */
/* @0xebf60 mov r1, #0 */
/* @0xebf64 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0xebf68 mov r12, r7 */
/* @0xebf6c str r0, [r7] */
/* @0xebf70 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xebf74 ldr r1, [pc, #0xec] */
/* @0xebf78 mov r12, #16 */
/* @0xebf7c mov r0, r12 */
/* @0xebf80 movw r2, #0xfef */
/* @0xebf84 add r1, pc, r1 */
/* @0xebf88 mov r3, #1 */
/* @0xebf8c str r12, [sp, #0x10] */
/* @0xebf90 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xebf94 mov r3, r5 */
/* @0xebf98 mov r1, #0 */
/* @0xebf9c mov r2, r0 */
/* @0xebfa0 add r0, sp, #120 */
/* @0xebfa4 str r2, [sp, #0x14] */
/* @0xebfa8 str r2, [r0, #-0x54]! */
/* @0xebfac strb r1, [r2] */
/* @0xebfb0 add r1, sp, #20 */
/* @0xebfb4 add r2, sp, #16 */
/* @0xebfb8 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0xebfbc mov r0, #12 */
/* @0xebfc0 bl 0x27c524 <_Znwj> */
/* @0xebfc4 ldr r5, [sp, #0x14] */
/* @0xebfc8 mov r4, r0 */
/* @0xebfcc subs r0, r5, #0 */
/* @0xebfd0 beq 0xebfd8 <_Z6DoConvjPhPKhP6VMExec+0xbe0> */
/* @0xebfd4 bl 0xb6538 <strlen@plt> */
/* @0xebfd8 str r0, [r4, #0x8] */
/* @0xebfdc mov r0, r5 */
/* @0xebfe0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xebfe4 mov r3, #1 */
/* @0xebfe8 stm r4, {r0, r3} */
/* @0xebfec ldr r0, [sp, #0x14] */
/* @0xebff0 str r4, [r7] */
/* @0xebff4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xebff8 mov r12, r7 */
/* @0xebffc b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xec00c eorseq r2, r0, r0, asr #10 */
/* @0xec010 .word 0x002492fc */
/* @0xec014 eoreq r9, r4, r8, ror #5 */
/* @0xec018 eoreq r9, r4, r8, asr #3 */
/* @0xec01c eoreq r9, r4, r0, lsr #5 */
/* @0xec020 .word 0x00246ef8 */
/* @0xec024 eoreq r9, r4, r8, lsr #2 */
/* @0xec028 eoreq r9, r4, r4, asr #1 */
/* @0xec02c eoreq r9, r4, r0, lsl #1 */
/* @0xec030 eoreq r6, r4, r0, ror #25 */
/* @0xec034 eoreq r9, r4, r0 */
/* @0xec038 eoreq r6, r4, r8, asr r12 */
/* @0xec03c .word 0x002469d0 */
/* @0xec040 eoreq r6, r4, r4, lsr #24 */
/* @0xec044 eoreq r6, r4, r4, lsr #15 */
/* @0xec048 eoreq r6, r4, r8, lsl #20 */
/* @0xec04c .word 0x00248cb4 */
/* @0xec050 eoreq r8, r4, r4, asr #23 */
/* @0xec054 .word 0x00248bb0 */
/* @0xec058 eoreq r8, r4, r12, asr #23 */
/* @0xec05c .word 0x00248bdc */
/* @0xec060 eoreq r8, r4, r8, lsr r11 */
/* @0xec064 .word 0x00248af8 */
/* @0xec068 .word 0x002467f8 */
/* @0xec06c mlaeq r4, r0, r9, r8 */
/* @0xec070 mov r0, r4 */
/* @0xec074 bl 0xb66c4 <atol@plt> */
/* @0xec078 mov r12, r7 */
/* @0xec07c asr r1, r0, #31 */
/* @0xec080 strd r0, r1, [r7] */
/* @0xec084 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xec088 ldr r1, [pc, #-0x24] */
/* @0xec08c mov r0, r4 */
/* @0xec090 add r1, pc, r1 */
/* @0xec094 bl 0xb6574 <strcmp@plt> */
/* @0xec098 mov r12, r7 */
/* @0xec09c rsbs r0, r0, #1 */
/* @0xec0a0 movlo r0, #0 */
/* @0xec0a4 str r0, [r7] */
/* @0xec0a8 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xec0ac mov r0, r4 */
/* @0xec0b0 mov r1, r4 */
/* @0xec0b4 bl 0xb6658 <strtod@plt> */
/* @0xec0b8 mov r12, r7 */
/* @0xec0bc strd r0, r1, [r7] */
/* @0xec0c0 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xec0c4 mov r0, r4 */
/* @0xec0c8 bl 0xb66b8 <atoi@plt> */
/* @0xec0cc mov r12, r7 */
/* @0xec0d0 str r0, [r7] */
/* @0xec0d4 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xec0d8 mov r0, r4 */
/* @0xec0dc mov r1, r4 */
/* @0xec0e0 bl 0xb6658 <strtod@plt> */
/* @0xec0e4 mov r12, r7 */
/* @0xec0e8 vmov d6, r0, r1 */
/* @0xec0ec vcvt.f32.f64 s15, d6 */
/* @0xec0f0 vstr s15, [r7] */
/* @0xec0f4 b 0xeb6dc <_Z6DoConvjPhPKhP6VMExec+0x2e4> */
/* @0xec0f8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xec0fc mov r7, r5 */
/* @0xec100 b 0xeb46c <_Z6DoConvjPhPKhP6VMExec+0x74> */

/* ── FUNC 0xec104 · anon_ec104 · size=0 · insn=1 */
/* @0xec104 nop */

/* ── FUNC 0xec108 · ParamSize(int) · size=60 · insn=15 */
/* @0xec108 and r0, r0, #15 */
/* @0xec10c cmp r0, #6 */
/* @0xec110 bhi 0xec13c <_Z9ParamSizei+0x34> */
/* @0xec114 mov r3, #1 */
/* @0xec118 lsl r0, r3, r0 */
/* @0xec11c tst r0, #118 */
/* @0xec120 beq 0xec12c <_Z9ParamSizei+0x24> */
/* @0xec124 mov r0, #4 */
/* @0xec128 bx lr */
/* @0xec12c tst r0, #9 */
/* @0xec130 moveq r0, #0 */
/* @0xec134 movne r0, #8 */
/* @0xec138 bx lr */
/* @0xec13c mov r0, #0 */
/* @0xec140 bx lr */

/* ── FUNC 0xec144 · VM::DebugInfo(VMBuffer*, int) · size=100 · insn=25 */
/* @0xec144 cmp r0, #0 */
/* @0xec148 str r4, [sp, #-0x4]! */
/* @0xec14c beq 0xec190 <_ZN2VM9DebugInfoEP8VMBufferi+0x4c> */
/* @0xec150 ldr r4, [r0, #0x4] */
/* @0xec154 ldr r2, [r0, #0x10] */
/* @0xec158 lsrs r4, r4, #3 */
/* @0xec15c beq 0xec198 <_ZN2VM9DebugInfoEP8VMBufferi+0x54> */
/* @0xec160 ldr r3, [r2] */
/* @0xec164 cmp r1, r3 */
/* @0xec168 blt 0xec1a0 <_ZN2VM9DebugInfoEP8VMBufferi+0x5c> */
/* @0xec16c mov r3, #0 */
/* @0xec170 b 0xec180 <_ZN2VM9DebugInfoEP8VMBufferi+0x3c> */
/* @0xec174 ldr r12, [r2, #0x8]! */
/* @0xec178 cmp r12, r1 */
/* @0xec17c bgt 0xec190 <_ZN2VM9DebugInfoEP8VMBufferi+0x4c> */
/* @0xec180 add r3, r3, #1 */
/* @0xec184 mov r0, r2 */
/* @0xec188 cmp r4, r3 */
/* @0xec18c bne 0xec174 <_ZN2VM9DebugInfoEP8VMBufferi+0x30> */
/* @0xec190 ldr r4, [sp], #4 */
/* @0xec194 bx lr */
/* @0xec198 mov r0, r4 */
/* @0xec19c b 0xec190 <_ZN2VM9DebugInfoEP8VMBufferi+0x4c> */
/* @0xec1a0 mov r0, #0 */
/* @0xec1a4 b 0xec190 <_ZN2VM9DebugInfoEP8VMBufferi+0x4c> */

/* ── FUNC 0xec1a8 · VM::DebugLine(VMDebugInfo*, char const*) · size=272 · insn=68 */
/* @0xec1a8 push {r4, r5, r6, r7, lr} */
/* @0xec1ac subs r4, r0, #0 */
/* @0xec1b0 sub sp, sp, #12 */
/* @0xec1b4 mov r7, r1 */
/* @0xec1b8 beq 0xec274 <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0xcc> */
/* @0xec1bc mov r0, r1 */
/* @0xec1c0 bl 0x110648 <utf8_strlen> */
/* @0xec1c4 ldr r6, [r4, #0x4] */
/* @0xec1c8 str r7, [sp] */
/* @0xec1cc cmp r0, r6 */
/* @0xec1d0 sublt r6, r0, #1 */
/* @0xec1d4 cmp r6, #0 */
/* @0xec1d8 ble 0xec284 <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0xdc> */
/* @0xec1dc mov r4, #0 */
/* @0xec1e0 mov r0, sp */
/* @0xec1e4 add r4, r4, #1 */
/* @0xec1e8 bl 0x10fb38 <utf8_extract_char> */
/* @0xec1ec cmp r0, #10 */
/* @0xec1f0 ldreq r7, [sp] */
/* @0xec1f4 cmp r4, r6 */
/* @0xec1f8 bne 0xec1e0 <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0x38> */
/* @0xec1fc ldr r3, [pc, #0x9c] */
/* @0xec200 str r7, [sp] */
/* @0xec204 add r3, pc, r3 */
/* @0xec208 str r3, [sp, #0x4] */
/* @0xec20c ldrb r3, [r7] */
/* @0xec210 cmp r3, #10 */
/* @0xec214 beq 0xec294 <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0xec> */
/* @0xec218 ldr r4, [pc, #0x84] */
/* @0xec21c add r6, sp, #4 */
/* @0xec220 add r4, pc, r4 */
/* @0xec224 add r4, r4, #255 */
/* @0xec228 b 0xec23c <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0x94> */
/* @0xec22c ldr r2, [sp] */
/* @0xec230 ldrb r2, [r2] */
/* @0xec234 cmp r2, #10 */
/* @0xec238 beq 0xec25c <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0xb4> */
/* @0xec23c mov r0, sp */
/* @0xec240 bl 0x10fb38 <utf8_extract_char> */
/* @0xec244 mov r1, r0 */
/* @0xec248 mov r0, r6 */
/* @0xec24c bl 0x10fe28 <utf8_add_char> */
/* @0xec250 ldr r3, [sp, #0x4] */
/* @0xec254 cmp r3, r4 */
/* @0xec258 blo 0xec22c <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0x84> */
/* @0xec25c ldr r0, [pc, #0x44] */
/* @0xec260 mov r2, #0 */
/* @0xec264 strb r2, [r3] */
/* @0xec268 add r0, pc, r0 */
/* @0xec26c add sp, sp, #12 */
/* @0xec270 pop {r4, r5, r6, r7, pc} */
/* @0xec274 ldr r0, [pc, #0x30] */
/* @0xec278 add r0, pc, r0 */
/* @0xec27c add sp, sp, #12 */
/* @0xec280 pop {r4, r5, r6, r7, pc} */
/* @0xec284 ldr r3, [pc, #0x24] */
/* @0xec288 add r3, pc, r3 */
/* @0xec28c str r3, [sp, #0x4] */
/* @0xec290 b 0xec20c <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0x64> */
/* @0xec294 ldr r3, [pc, #0x18] */
/* @0xec298 add r3, pc, r3 */
/* @0xec29c b 0xec25c <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0xb4> */
/* @0xec2a0 mlaseq r9, r4, r0, r3 */
/* @0xec2a4 eorseq r3, r9, r8, ror r0 */
/* @0xec2a8 eorseq r3, r9, r0, lsr r0 */
/* @0xec2ac .word 0x002488b8 */
/* @0xec2b0 eorseq r3, r9, r0, lsl r0 */
/* @0xec2b4 eorseq r3, r9, r0 */

/* ── FUNC 0xec2b8 · VM::DebugLineNumber(VMDebugInfo*, char const*, char**) · size=452 · insn=113 */
/* @0xec2b8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xec2bc subs r4, r0, #0 */
/* @0xec2c0 sub sp, sp, #8 */
/* @0xec2c4 mov r5, r1 */
/* @0xec2c8 mov r9, r2 */
/* @0xec2cc beq 0xec46c <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x1b4> */
/* @0xec2d0 mov r0, r1 */
/* @0xec2d4 bl 0xb6538 <strlen@plt> */
/* @0xec2d8 ldr r10, [r4, #0x4] */
/* @0xec2dc cmp r0, r10 */
/* @0xec2e0 sublt r10, r0, #1 */
/* @0xec2e4 cmp r10, #0 */
/* @0xec2e8 blt 0xec46c <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x1b4> */
/* @0xec2ec add r10, r5, r10 */
/* @0xec2f0 cmp r5, r10 */
/* @0xec2f4 beq 0xec45c <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x1a4> */
/* @0xec2f8 ldr r8, [pc, #0x174] */
/* @0xec2fc add r6, sp, #4 */
/* @0xec300 mov r7, #0 */
/* @0xec304 add r8, pc, r8 */
/* @0xec308 mov r0, r6 */
/* @0xec30c str r10, [sp, #0x4] */
/* @0xec310 bl 0x10fb38 <utf8_extract_char> */
/* @0xec314 cmp r0, #10 */
/* @0xec318 beq 0xec374 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xbc> */
/* @0xec31c ldrb r3, [r10, #-0x1] */
/* @0xec320 sub r2, r10, #1 */
/* @0xec324 tst r3, #128 */
/* @0xec328 beq 0xec3a0 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xe8> */
/* @0xec32c and r3, r3, #192 */
/* @0xec330 cmp r3, #192 */
/* @0xec334 beq 0xec3a0 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xe8> */
/* @0xec338 sub r3, r10, #2 */
/* @0xec33c b 0xec348 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x90> */
/* @0xec340 cmp r4, #192 */
/* @0xec344 beq 0xec35c <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xa4> */
/* @0xec348 mov r10, r3 */
/* @0xec34c ldrb r12, [r3], #-1 */
/* @0xec350 tst r12, #128 */
/* @0xec354 and r4, r12, #192 */
/* @0xec358 bne 0xec340 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x88> */
/* @0xec35c cmp r5, r10 */
/* @0xec360 bne 0xec308 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x50> */
/* @0xec364 add r7, r7, #1 */
/* @0xec368 mov r0, r7 */
/* @0xec36c add sp, sp, #8 */
/* @0xec370 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xec374 add r0, r10, #1 */
/* @0xec378 mov r1, r8 */
/* @0xec37c mov r2, #6 */
/* @0xec380 bl 0xb65e0 <strncmp@plt> */
/* @0xec384 cmp r0, #0 */
/* @0xec388 beq 0xec3b0 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xf8> */
/* @0xec38c ldrb r3, [r10, #-0x1] */
/* @0xec390 add r7, r7, #1 */
/* @0xec394 sub r2, r10, #1 */
/* @0xec398 tst r3, #128 */
/* @0xec39c bne 0xec32c <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x74> */
/* @0xec3a0 mov r10, r2 */
/* @0xec3a4 cmp r5, r10 */
/* @0xec3a8 bne 0xec308 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x50> */
/* @0xec3ac b 0xec364 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xac> */
/* @0xec3b0 ldr r3, [pc, #0xc0] */
/* @0xec3b4 add r5, r10, #7 */
/* @0xec3b8 ldrb r2, [r10, #0x7] */
/* @0xec3bc ldr r3, [pc, r3] */
/* @0xec3c0 ldr r12, [r3] */
/* @0xec3c4 add r3, r12, r2 */
/* @0xec3c8 ldrb r3, [r3, #0x1] */
/* @0xec3cc tst r3, #8 */
/* @0xec3d0 bne 0xec464 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x1ac> */
/* @0xec3d4 add r10, r10, #8 */
/* @0xec3d8 mov r4, r10 */
/* @0xec3dc add r10, r10, #1 */
/* @0xec3e0 ldrb r3, [r4] */
/* @0xec3e4 add r3, r12, r3 */
/* @0xec3e8 ldrb r3, [r3, #0x1] */
/* @0xec3ec tst r3, #8 */
/* @0xec3f0 beq 0xec3d8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x120> */
/* @0xec3f4 add r3, r4, #1 */
/* @0xec3f8 mov r0, r3 */
/* @0xec3fc add r3, r3, #1 */
/* @0xec400 ldrb r2, [r0] */
/* @0xec404 add r2, r12, r2 */
/* @0xec408 ldrb r2, [r2, #0x1] */
/* @0xec40c and r2, r2, #8 */
/* @0xec410 ands r6, r2, #255 */
/* @0xec414 bne 0xec3f8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x140> */
/* @0xec418 bl 0xb66b8 <atoi@plt> */
/* @0xec41c cmp r9, #0 */
/* @0xec420 add r0, r0, r7 */
/* @0xec424 sub r7, r0, #1 */
/* @0xec428 beq 0xec368 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xb0> */
/* @0xec42c rsb r4, r5, r4 */
/* @0xec430 add r0, r4, #1 */
/* @0xec434 bl 0xb6544 <malloc@plt> */
/* @0xec438 mov r1, r5 */
/* @0xec43c mov r2, r4 */
/* @0xec440 str r0, [r9] */
/* @0xec444 bl 0xb65bc <memcpy@plt> */
/* @0xec448 ldr r3, [r9] */
/* @0xec44c mov r0, r7 */
/* @0xec450 strb r6, [r3, r4] */
/* @0xec454 add sp, sp, #8 */
/* @0xec458 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xec45c mov r7, #1 */
/* @0xec460 b 0xec368 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xb0> */
/* @0xec464 mov r4, r5 */
/* @0xec468 b 0xec3f4 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0x13c> */
/* @0xec46c mvn r7, #0 */
/* @0xec470 b 0xec368 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc+0xb0> */
/* @0xec474 eoreq r8, r4, r4, asr #16 */
/* @0xec478 eorseq r1, r0, r4, asr #11 */

/* ── FUNC 0xec47c · CHashMap<unsigned char*, void**, 3>::~CHashMap() · size=40 · insn=10 */
/* @0xec47c push {r4, lr} */
/* @0xec480 mov r4, r0 */
/* @0xec484 ldr r0, [r0, #0x10] */
/* @0xec488 cmp r0, #0 */
/* @0xec48c beq 0xec49c <_ZN8CHashMapIPhPPvLi3EED2Ev+0x20> */
/* @0xec490 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xec494 mov r3, #0 */
/* @0xec498 str r3, [r4, #0x10] */
/* @0xec49c mov r0, r4 */
/* @0xec4a0 pop {r4, pc} */

/* ── FUNC 0xec47c · CHashMap<unsigned char*, void**, 3>::~CHashMap() · alias of the symbol above · insn=0 */

/* ── FUNC 0xec4a4 · VMWriteBuffer::~VMWriteBuffer() · size=132 · insn=33 */
/* @0xec4a4 push {r4, lr} */
/* @0xec4a8 mov r4, r0 */
/* @0xec4ac ldr r0, [r0, #0x14] */
/* @0xec4b0 ldr r3, [pc, #0x6c] */
/* @0xec4b4 cmp r0, #0 */
/* @0xec4b8 ldr r3, [pc, r3] */
/* @0xec4bc add r3, r3, #8 */
/* @0xec4c0 str r3, [r4] */
/* @0xec4c4 beq 0xec4d4 <_ZN13VMWriteBufferD2Ev+0x30> */
/* @0xec4c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xec4cc mov r3, #0 */
/* @0xec4d0 str r3, [r4, #0x14] */
/* @0xec4d4 ldr r0, [r4, #0x18] */
/* @0xec4d8 cmp r0, #0 */
/* @0xec4dc beq 0xec4ec <_ZN13VMWriteBufferD2Ev+0x48> */
/* @0xec4e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xec4e4 mov r3, #0 */
/* @0xec4e8 str r3, [r4, #0x18] */
/* @0xec4ec ldr r0, [r4, #0x10] */
/* @0xec4f0 cmp r0, #0 */
/* @0xec4f4 beq 0xec51c <_ZN13VMWriteBufferD2Ev+0x78> */
/* @0xec4f8 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0xec4fc cmp r0, #0 */
/* @0xec500 bne 0xec51c <_ZN13VMWriteBufferD2Ev+0x78> */
/* @0xec504 ldr r0, [r4, #0x10] */
/* @0xec508 cmp r0, #0 */
/* @0xec50c beq 0xec514 <_ZN13VMWriteBufferD2Ev+0x70> */
/* @0xec510 bl 0x27d1d4 <_ZdaPv> */
/* @0xec514 mov r3, #0 */
/* @0xec518 str r3, [r4, #0x10] */
/* @0xec51c mov r0, r4 */
/* @0xec520 pop {r4, pc} */
/* @0xec524 eorseq r1, r0, r4, ror r6 */

/* ── FUNC 0xec4a4 · VMWriteBuffer::~VMWriteBuffer() · alias of the symbol above · insn=0 */

/* ── FUNC 0xec528 · VMWriteBuffer::~VMWriteBuffer() · size=140 · insn=35 */
/* @0xec528 push {r4, lr} */
/* @0xec52c mov r4, r0 */
/* @0xec530 ldr r0, [r0, #0x14] */
/* @0xec534 ldr r3, [pc, #0x74] */
/* @0xec538 cmp r0, #0 */
/* @0xec53c ldr r3, [pc, r3] */
/* @0xec540 add r3, r3, #8 */
/* @0xec544 str r3, [r4] */
/* @0xec548 beq 0xec558 <_ZN13VMWriteBufferD0Ev+0x30> */
/* @0xec54c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xec550 mov r3, #0 */
/* @0xec554 str r3, [r4, #0x14] */
/* @0xec558 ldr r0, [r4, #0x18] */
/* @0xec55c cmp r0, #0 */
/* @0xec560 beq 0xec570 <_ZN13VMWriteBufferD0Ev+0x48> */
/* @0xec564 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xec568 mov r3, #0 */
/* @0xec56c str r3, [r4, #0x18] */
/* @0xec570 ldr r0, [r4, #0x10] */
/* @0xec574 cmp r0, #0 */
/* @0xec578 beq 0xec5a0 <_ZN13VMWriteBufferD0Ev+0x78> */
/* @0xec57c bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0xec580 cmp r0, #0 */
/* @0xec584 bne 0xec5a0 <_ZN13VMWriteBufferD0Ev+0x78> */
/* @0xec588 ldr r0, [r4, #0x10] */
/* @0xec58c cmp r0, #0 */
/* @0xec590 beq 0xec598 <_ZN13VMWriteBufferD0Ev+0x70> */
/* @0xec594 bl 0x27d1d4 <_ZdaPv> */
/* @0xec598 mov r3, #0 */
/* @0xec59c str r3, [r4, #0x10] */
/* @0xec5a0 mov r0, r4 */
/* @0xec5a4 bl 0x27d1d0 <_ZdlPv> */
/* @0xec5a8 mov r0, r4 */
/* @0xec5ac pop {r4, pc} */
/* @0xec5b0 ldrshteq r1, [r0], -r0 */

/* ── FUNC 0xec5b4 · VMWriteBuffer::VMWriteBuffer(int) · size=80 · insn=20 */
/* @0xec5b4 push {r3, r4, r5, lr} */
/* @0xec5b8 mov r4, r0 */
/* @0xec5bc ldr r3, [pc, #0x3c] */
/* @0xec5c0 mov r2, #0 */
/* @0xec5c4 str r2, [r0, #0x10] */
/* @0xec5c8 mov r5, r1 */
/* @0xec5cc ldr r3, [pc, r3] */
/* @0xec5d0 str r2, [r0, #0x14] */
/* @0xec5d4 add r3, r3, #8 */
/* @0xec5d8 str r3, [r0] */
/* @0xec5dc mov r0, r1 */
/* @0xec5e0 str r2, [r4, #0x18] */
/* @0xec5e4 bl 0x27d14c <_Znaj> */
/* @0xec5e8 str r5, [r4, #0x4] */
/* @0xec5ec mov r3, r0 */
/* @0xec5f0 mov r0, r4 */
/* @0xec5f4 str r3, [r4, #0x10] */
/* @0xec5f8 str r3, [r4, #0x1c] */
/* @0xec5fc pop {r3, r4, r5, pc} */
/* @0xec600 eorseq r1, r0, r4, lsr #15 */

/* ── FUNC 0xec5b4 · VMWriteBuffer::VMWriteBuffer(int) · alias of the symbol above · insn=0 */

/* ── FUNC 0xec604 · VMWriteBuffer::Reserve(int) · size=112 · insn=28 */
/* @0xec604 push {r4, r5, r6, lr} */
/* @0xec608 mov r4, r0 */
/* @0xec60c ldr r2, [r4, #0x1c] */
/* @0xec610 mov r6, r1 */
/* @0xec614 ldr r0, [r0, #0x10] */
/* @0xec618 ldr r3, [r4, #0x4] */
/* @0xec61c rsb r1, r2, r0 */
/* @0xec620 add r1, r3, r1 */
/* @0xec624 cmp r6, r1 */
/* @0xec628 pople {r4, r5, r6, pc} */
/* @0xec62c rsb r5, r0, r2 */
/* @0xec630 lsl r0, r3, #1 */
/* @0xec634 bl 0x27d14c <_Znaj> */
/* @0xec638 ldr r1, [r4, #0x10] */
/* @0xec63c mov r2, r5 */
/* @0xec640 bl 0xb65bc <memcpy@plt> */
/* @0xec644 ldr r3, [r4, #0x4] */
/* @0xec648 lsl r3, r3, #1 */
/* @0xec64c str r3, [r4, #0x4] */
/* @0xec650 add r2, r0, r5 */
/* @0xec654 mov r12, r0 */
/* @0xec658 rsb r1, r2, r0 */
/* @0xec65c str r2, [r4, #0x1c] */
/* @0xec660 add r1, r3, r1 */
/* @0xec664 str r12, [r4, #0x10] */
/* @0xec668 cmp r6, r1 */
/* @0xec66c bgt 0xec62c <_ZN13VMWriteBuffer7ReserveEi+0x28> */
/* @0xec670 pop {r4, r5, r6, pc} */

/* ── FUNC 0xec674 · VMWriteBuffer::Add(int, ...) · size=104 · insn=26 */
/* @0xec674 push {r1, r2, r3} */
/* @0xec678 push {r4, r5, lr} */
/* @0xec67c sub sp, sp, #8 */
/* @0xec680 mov r5, r0 */
/* @0xec684 ldr r4, [sp, #0x14] */
/* @0xec688 lsl r1, r4, #2 */
/* @0xec68c bl 0xec604 <_ZN13VMWriteBuffer7ReserveEi> */
/* @0xec690 cmp r4, #0 */
/* @0xec694 add r3, sp, #24 */
/* @0xec698 str r3, [sp, #0x4] */
/* @0xec69c ble 0xec6cc <_ZN13VMWriteBuffer3AddEiz+0x58> */
/* @0xec6a0 ldr r0, [r5, #0x1c] */
/* @0xec6a4 add r1, sp, #20 */
/* @0xec6a8 mov r3, #0 */
/* @0xec6ac mov r2, r0 */
/* @0xec6b0 add r3, r3, #1 */
/* @0xec6b4 ldr r12, [r1, #0x4]! */
/* @0xec6b8 cmp r3, r4 */
/* @0xec6bc str r12, [r2], #4 */
/* @0xec6c0 bne 0xec6b0 <_ZN13VMWriteBuffer3AddEiz+0x3c> */
/* @0xec6c4 add r3, r0, r3, lsl #2 */
/* @0xec6c8 str r3, [r5, #0x1c] */
/* @0xec6cc add sp, sp, #8 */
/* @0xec6d0 pop {r4, r5, lr} */
/* @0xec6d4 add sp, sp, #12 */
/* @0xec6d8 bx lr */

/* ── FUNC 0xec6dc · VMWriteBuffer::AddVal(double) · size=32 · insn=8 */
/* @0xec6dc str lr, [sp, #-0x4]! */
/* @0xec6e0 sub sp, sp, #12 */
/* @0xec6e4 mov r1, #2 */
/* @0xec6e8 strd r2, r3, [sp] */
/* @0xec6ec ldm sp, {r2, r3} */
/* @0xec6f0 bl 0xec674 <_ZN13VMWriteBuffer3AddEiz> */
/* @0xec6f4 add sp, sp, #12 */
/* @0xec6f8 ldr pc, [sp], #4 */

/* ── FUNC 0xec6fc · VMWriteBuffer::AddVal(float) · size=20 · insn=5 */
/* @0xec6fc vmov s13, r1 */
/* @0xec700 mov r1, #1 */
/* @0xec704 vcvt.f64.f32 d7, s13 */
/* @0xec708 vmov r2, r3, d7 */
/* @0xec70c b 0xec674 <_ZN13VMWriteBuffer3AddEiz> */

/* ── FUNC 0xec710 · VMWriteBuffer::AddVal(int) · size=12 · insn=3 */
/* @0xec710 mov r2, r1 */
/* @0xec714 mov r1, #1 */
/* @0xec718 b 0xec674 <_ZN13VMWriteBuffer3AddEiz> */

/* ── FUNC 0xec71c · VMWriteBuffer::AddVal(long long) · size=32 · insn=8 */
/* @0xec71c str lr, [sp, #-0x4]! */
/* @0xec720 sub sp, sp, #12 */
/* @0xec724 mov r1, #2 */
/* @0xec728 strd r2, r3, [sp] */
/* @0xec72c ldr r3, [sp, #0x4] */
/* @0xec730 bl 0xec674 <_ZN13VMWriteBuffer3AddEiz> */
/* @0xec734 add sp, sp, #12 */
/* @0xec738 ldr pc, [sp], #4 */

/* ── FUNC 0xec73c · VMWriteBuffer::AddVal(bool) · size=12 · insn=3 */
/* @0xec73c mov r2, r1 */
/* @0xec740 mov r1, #1 */
/* @0xec744 b 0xec674 <_ZN13VMWriteBuffer3AddEiz> */

/* ── FUNC 0xec748 · unsigned int CHashMapCalculateHash<unsigned char*>(unsigned char*) · size=8 · insn=2 */
/* @0xec748 add r0, r0, #1 */
/* @0xec74c bx lr */

/* ── FUNC 0xec750 · VMBuffer::convertBuffer() · size=996 · insn=249 */
/* @0xec750 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xec754 mov r4, r0 */
/* @0xec758 ldr r7, [r0, #0x14] */
/* @0xec75c sub sp, sp, #20 */
/* @0xec760 ldr r5, [pc, #0x3a4] */
/* @0xec764 cmp r7, #0 */
/* @0xec768 add r5, pc, r5 */
/* @0xec76c beq 0xec778 <_ZN8VMBuffer13convertBufferEv+0x28> */
/* @0xec770 add sp, sp, #20 */
/* @0xec774 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xec778 ldr r0, [r0, #0x10] */
/* @0xec77c bl 0xec748 <_Z21CHashMapCalculateHashIPhEjT_> */
/* @0xec780 ldr r2, [pc, #0x388] */
/* @0xec784 add r2, pc, r2 */
/* @0xec788 ldr r1, [r2, #0x8] */
/* @0xec78c ldr r9, [r2, #0x10] */
/* @0xec790 bic r0, r0, #-2147483648 */
/* @0xec794 and r3, r0, r1 */
/* @0xec798 lsl r6, r3, #1 */
/* @0xec79c add r12, r6, r3 */
/* @0xec7a0 add r12, r9, r12, lsl #2 */
/* @0xec7a4 ldr r12, [r12, #0x8] */
/* @0xec7a8 cmp r12, #0 */
/* @0xec7ac beq 0xec81c <_ZN8VMBuffer13convertBufferEv+0xcc> */
/* @0xec7b0 cmp r0, r12 */
/* @0xec7b4 beq 0xec9b4 <_ZN8VMBuffer13convertBufferEv+0x264> */
/* @0xec7b8 ldr r10, [r2] */
/* @0xec7bc and r12, r1, r12 */
/* @0xec7c0 add r2, r3, r10 */
/* @0xec7c4 rsb r12, r12, r2 */
/* @0xec7c8 tst r12, r1 */
/* @0xec7cc bmi 0xec81c <_ZN8VMBuffer13convertBufferEv+0xcc> */
/* @0xec7d0 mov r12, r7 */
/* @0xec7d4 b 0xec7e8 <_ZN8VMBuffer13convertBufferEv+0x98> */
/* @0xec7d8 cmp r0, r2 */
/* @0xec7dc beq 0xec9ac <_ZN8VMBuffer13convertBufferEv+0x25c> */
/* @0xec7e0 cmp r7, r12 */
/* @0xec7e4 blt 0xec81c <_ZN8VMBuffer13convertBufferEv+0xcc> */
/* @0xec7e8 add r3, r3, #1 */
/* @0xec7ec add r12, r12, #1 */
/* @0xec7f0 and r3, r3, r1 */
/* @0xec7f4 add r8, r3, r10 */
/* @0xec7f8 lsl r6, r3, #1 */
/* @0xec7fc add r2, r6, r3 */
/* @0xec800 add r2, r9, r2, lsl #2 */
/* @0xec804 ldr r2, [r2, #0x8] */
/* @0xec808 and r7, r1, r2 */
/* @0xec80c cmp r2, #0 */
/* @0xec810 rsb r7, r7, r8 */
/* @0xec814 and r7, r7, r1 */
/* @0xec818 bne 0xec7d8 <_ZN8VMBuffer13convertBufferEv+0x88> */
/* @0xec81c ldr r7, [r4, #0x4] */
/* @0xec820 cmp r7, #0 */
/* @0xec824 ble 0xecac0 <_ZN8VMBuffer13convertBufferEv+0x370> */
/* @0xec828 mov r0, #0 */
/* @0xec82c ldr r6, [r4, #0x10] */
/* @0xec830 mov r3, r0 */
/* @0xec834 b 0xec83c <_ZN8VMBuffer13convertBufferEv+0xec> */
/* @0xec838 mov r0, r2 */
/* @0xec83c ldr r2, [r6, r3] */
/* @0xec840 mov r1, #4 */
/* @0xec844 ldr lr, [pc, #0x2c8] */
/* @0xec848 tst r2, #1073741824 */
/* @0xec84c ubfx r12, r2, #0x10, #0x4 */
/* @0xec850 ldrne r2, [r5, lr] */
/* @0xec854 ldrne r1, [r2, r12, lsl #2] */
/* @0xec858 add r2, r0, #1 */
/* @0xec85c addne r1, r1, #4 */
/* @0xec860 add r3, r3, r1 */
/* @0xec864 cmp r7, r3 */
/* @0xec868 bgt 0xec838 <_ZN8VMBuffer13convertBufferEv+0xe8> */
/* @0xec86c ldr r6, [pc, #0x2a4] */
/* @0xec870 add r0, r0, #2 */
/* @0xec874 mov r2, #126 */
/* @0xec878 mov r3, #1 */
/* @0xec87c add r6, pc, r6 */
/* @0xec880 lsl r0, r0, #2 */
/* @0xec884 movw r8, #0x869f */
/* @0xec888 movt r8, #0x1 */
/* @0xec88c mov r1, r6 */
/* @0xec890 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xec894 cmp r7, #0 */
/* @0xec898 add r12, r7, #3 */
/* @0xec89c mov r1, r6 */
/* @0xec8a0 movge r12, r7 */
/* @0xec8a4 bic r12, r12, #3 */
/* @0xec8a8 mov r2, #127 */
/* @0xec8ac mov r3, #1 */
/* @0xec8b0 str r0, [r4, #0x14] */
/* @0xec8b4 add r0, r12, #4 */
/* @0xec8b8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xec8bc mov r12, #0 */
/* @0xec8c0 mov r1, #6784 */
/* @0xec8c4 movw r2, #0xa11f */
/* @0xec8c8 movt r1, #0x6 */
/* @0xec8cc movt r2, #0x7 */
/* @0xec8d0 mov r6, r12 */
/* @0xec8d4 mov r3, r12 */
/* @0xec8d8 str r1, [sp, #0x4] */
/* @0xec8dc str r2, [sp, #0x8] */
/* @0xec8e0 str r8, [sp, #0xc] */
/* @0xec8e4 str r0, [r4, #0x18] */
/* @0xec8e8 b 0xec928 <_ZN8VMBuffer13convertBufferEv+0x1d8> */
/* @0xec8ec cmp r1, #25 */
/* @0xec8f0 beq 0xeca08 <_ZN8VMBuffer13convertBufferEv+0x2b8> */
/* @0xec8f4 cmp r1, #5 */
/* @0xec8f8 beq 0xec9d0 <_ZN8VMBuffer13convertBufferEv+0x280> */
/* @0xec8fc ldr r0, [pc, #0x218] */
/* @0xec900 ldr r2, [r4, #0x14] */
/* @0xec904 ldr r0, [r5, r0] */
/* @0xec908 ldr r1, [r0, r1, lsl #2] */
/* @0xec90c str r1, [r2, r12] */
/* @0xec910 add r3, r3, r9 */
/* @0xec914 add r6, r6, #1 */
/* @0xec918 cmp r7, r3 */
/* @0xec91c add r12, r12, #4 */
/* @0xec920 ble 0xec770 <_ZN8VMBuffer13convertBufferEv+0x20> */
/* @0xec924 ldr r0, [r4, #0x18] */
/* @0xec928 ldr r2, [r4, #0x10] */
/* @0xec92c add r10, r2, r3 */
/* @0xec930 ldr r2, [r2, r3] */
/* @0xec934 ands r11, r2, #1073741824 */
/* @0xec938 moveq r9, #4 */
/* @0xec93c beq 0xec954 <_ZN8VMBuffer13convertBufferEv+0x204> */
/* @0xec940 ldr r1, [pc, #0x1cc] */
/* @0xec944 ubfx r8, r2, #0x10, #0x4 */
/* @0xec948 ldr r1, [r5, r1] */
/* @0xec94c ldr r9, [r1, r8, lsl #2] */
/* @0xec950 add r9, r9, #4 */
/* @0xec954 cmp r3, #0 */
/* @0xec958 add r8, r3, #3 */
/* @0xec95c ubfx r1, r2, #0x18, #0x5 */
/* @0xec960 movge r8, r3 */
/* @0xec964 cmp r1, #7 */
/* @0xec968 asr r8, r8, #2 */
/* @0xec96c str r6, [r0, r8, lsl #2] */
/* @0xec970 bne 0xec8ec <_ZN8VMBuffer13convertBufferEv+0x19c> */
/* @0xec974 tst r2, #3840 */
/* @0xec978 ubfx r2, r2, #0x10, #0x8 */
/* @0xec97c movne r1, #0 */
/* @0xec980 moveq r1, #1 */
/* @0xec984 cmp r2, #82 */
/* @0xec988 movne r2, #0 */
/* @0xec98c andeq r2, r1, #1 */
/* @0xec990 cmp r2, #0 */
/* @0xec994 beq 0xeca54 <_ZN8VMBuffer13convertBufferEv+0x304> */
/* @0xec998 ldr r1, [pc, #0x180] */
/* @0xec99c ldr r2, [r4, #0x14] */
/* @0xec9a0 ldr r1, [r5, r1] */
/* @0xec9a4 str r1, [r2, r12] */
/* @0xec9a8 b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0> */
/* @0xec9ac cmn r3, #1 */
/* @0xec9b0 beq 0xec81c <_ZN8VMBuffer13convertBufferEv+0xcc> */
/* @0xec9b4 add r3, r6, r3 */
/* @0xec9b8 add r9, r9, r3, lsl #2 */
/* @0xec9bc cmn r9, #4 */
/* @0xec9c0 beq 0xec81c <_ZN8VMBuffer13convertBufferEv+0xcc> */
/* @0xec9c4 ldr r3, [r9, #0x4] */
/* @0xec9c8 str r3, [r4, #0x14] */
/* @0xec9cc b 0xec770 <_ZN8VMBuffer13convertBufferEv+0x20> */
/* @0xec9d0 ubfx r0, r2, #0x10, #0x4 */
/* @0xec9d4 ubfx r1, r2, #0x14, #0x4 */
/* @0xec9d8 cmp r0, #5 */
/* @0xec9dc cmpeq r1, #5 */
/* @0xec9e0 bne 0xec9f0 <_ZN8VMBuffer13convertBufferEv+0x2a0> */
/* @0xec9e4 sxth r2, r2 */
/* @0xec9e8 cmn r2, #7 */
/* @0xec9ec beq 0xeca6c <_ZN8VMBuffer13convertBufferEv+0x31c> */
/* @0xec9f0 ldr r1, [pc, #0x124] */
/* @0xec9f4 ldr r2, [r4, #0x14] */
/* @0xec9f8 ldr r1, [r5, r1] */
/* @0xec9fc ldr r1, [r1, #0x14] */
/* @0xeca00 str r1, [r2, r12] */
/* @0xeca04 b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0> */
/* @0xeca08 ubfx r2, r2, #0x10, #0x4 */
/* @0xeca0c cmp r2, #2 */
/* @0xeca10 bne 0xec8fc <_ZN8VMBuffer13convertBufferEv+0x1ac> */
/* @0xeca14 ldr r2, [r10, #0x4] */
/* @0xeca18 ldmib sp, {r0, r8} */
/* @0xeca1c sub r1, r2, #99328 */
/* @0xeca20 sub r1, r1, #672 */
/* @0xeca24 cmp r1, r0 */
/* @0xeca28 movhi r1, #0 */
/* @0xeca2c movls r1, #1 */
/* @0xeca30 cmp r2, r8 */
/* @0xeca34 moveq r1, #0 */
/* @0xeca38 cmp r1, #0 */
/* @0xeca3c beq 0xeca88 <_ZN8VMBuffer13convertBufferEv+0x338> */
/* @0xeca40 ldr r1, [pc, #0xdc] */
/* @0xeca44 ldr r2, [r4, #0x14] */
/* @0xeca48 ldr r1, [r5, r1] */
/* @0xeca4c str r1, [r2, r12] */
/* @0xeca50 b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0> */
/* @0xeca54 ldr r1, [pc, #0xc0] */
/* @0xeca58 ldr r2, [r4, #0x14] */
/* @0xeca5c ldr r1, [r5, r1] */
/* @0xeca60 ldr r1, [r1, #0x1c] */
/* @0xeca64 str r1, [r2, r12] */
/* @0xeca68 b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0> */
/* @0xeca6c cmp r11, #0 */
/* @0xeca70 beq 0xec9f0 <_ZN8VMBuffer13convertBufferEv+0x2a0> */
/* @0xeca74 ldr r1, [pc, #0xac] */
/* @0xeca78 ldr r2, [r4, #0x14] */
/* @0xeca7c ldr r1, [r5, r1] */
/* @0xeca80 str r1, [r2, r12] */
/* @0xeca84 b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0> */
/* @0xeca88 ldr r0, [sp, #0xc] */
/* @0xeca8c cmp r2, r0 */
/* @0xeca90 bgt 0xecaa8 <_ZN8VMBuffer13convertBufferEv+0x358> */
/* @0xeca94 ldr r1, [pc, #0x90] */
/* @0xeca98 ldr r2, [r4, #0x14] */
/* @0xeca9c ldr r1, [r5, r1] */
/* @0xecaa0 str r1, [r2, r12] */
/* @0xecaa4 b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0> */
/* @0xecaa8 ldr r1, [pc, #0x6c] */
/* @0xecaac ldr r2, [r4, #0x14] */
/* @0xecab0 ldr r1, [r5, r1] */
/* @0xecab4 ldr r1, [r1, #0x64] */
/* @0xecab8 str r1, [r2, r12] */
/* @0xecabc b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0> */
/* @0xecac0 ldr r5, [pc, #0x68] */
/* @0xecac4 mov r2, #126 */
/* @0xecac8 mov r3, #1 */
/* @0xecacc mov r0, #4 */
/* @0xecad0 add r5, pc, r5 */
/* @0xecad4 mov r1, r5 */
/* @0xecad8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xecadc add r3, r7, #3 */
/* @0xecae0 cmp r7, #0 */
/* @0xecae4 mov r1, r5 */
/* @0xecae8 mov r2, #127 */
/* @0xecaec movlt r7, r3 */
/* @0xecaf0 bic r12, r7, #3 */
/* @0xecaf4 mov r3, #1 */
/* @0xecaf8 str r0, [r4, #0x14] */
/* @0xecafc add r0, r12, #4 */
/* @0xecb00 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xecb04 str r0, [r4, #0x18] */
/* @0xecb08 b 0xec770 <_ZN8VMBuffer13convertBufferEv+0x20> */
/* @0xecb0c eorseq r5, r0, r8, ror #9 */
/* @0xecb10 eorseq r2, r9, r4, lsl r12 */
/* @0xecb14 .word 0xffffc09c */
/* @0xecb18 .word 0x002482d4 */
/* @0xecb1c .word 0xffffc0a0 */
/* @0xecb20 .word 0xffffc124 */
/* @0xecb24 .word 0xffffc128 */
/* @0xecb28 .word 0xffffc12c */
/* @0xecb2c .word 0xffffc130 */
/* @0xecb30 eoreq r8, r4, r0, lsl #1 */

/* ── FUNC 0xecb34 · ShowForm(char const*, bool) · size=584 · insn=146 */
/* @0xecb34 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xecb38 add r11, sp, #32 */
/* @0xecb3c ldr r2, [pc, #0x214] */
/* @0xecb40 sub sp, sp, #44 */
/* @0xecb44 ldr r3, [pc, #0x210] */
/* @0xecb48 ldr r2, [pc, r2] */
/* @0xecb4c str r1, [r11, #-0x3c] */
/* @0xecb50 add r3, pc, r3 */
/* @0xecb54 str r3, [r11, #-0x38] */
/* @0xecb58 ldr r3, [r2] */
/* @0xecb5c mov r5, r0 */
/* @0xecb60 str r2, [r11, #-0x30] */
/* @0xecb64 mov r4, #0 */
/* @0xecb68 ldr r1, [pc, #0x1f0] */
/* @0xecb6c ldr r2, [pc, #0x1f0] */
/* @0xecb70 add r1, pc, r1 */
/* @0xecb74 str r3, [r11, #-0x28] */
/* @0xecb78 str r1, [r11, #-0x40] */
/* @0xecb7c add r2, pc, r2 */
/* @0xecb80 str r2, [r11, #-0x34] */
/* @0xecb84 bl 0x17df38 <_Z14ExitFullScreenv> */
/* @0xecb88 mov r0, r5 */
/* @0xecb8c bl 0xb6538 <strlen@plt> */
/* @0xecb90 mov r1, r4 */
/* @0xecb94 add r0, r0, #128 */
/* @0xecb98 lsl r6, r0, #1 */
/* @0xecb9c add r3, r6, #14 */
/* @0xecba0 bic r3, r3, #7 */
/* @0xecba4 mov r2, r6 */
/* @0xecba8 sub sp, sp, r3 */
/* @0xecbac add r9, sp, #8 */
/* @0xecbb0 sub sp, sp, r3 */
/* @0xecbb4 add r8, sp, #8 */
/* @0xecbb8 sub sp, sp, r3 */
/* @0xecbbc mov r0, r9 */
/* @0xecbc0 add r7, sp, #8 */
/* @0xecbc4 bl 0xb65b0 <memset@plt> */
/* @0xecbc8 mov r2, r6 */
/* @0xecbcc mov r1, r4 */
/* @0xecbd0 mov r0, r8 */
/* @0xecbd4 bl 0xb65b0 <memset@plt> */
/* @0xecbd8 ldr r2, [pc, #0x188] */
/* @0xecbdc ldr r3, [pc, #0x188] */
/* @0xecbe0 mov r0, r9 */
/* @0xecbe4 mov r1, r6 */
/* @0xecbe8 add r2, pc, r2 */
/* @0xecbec add r3, pc, r3 */
/* @0xecbf0 bl 0xb65c8 <snprintf@plt> */
/* @0xecbf4 b 0xecc2c <_Z8ShowFormPKcb+0xf8> */
/* @0xecbf8 cmp r3, #9 */
/* @0xecbfc mov r1, r8 */
/* @0xecc00 mov r2, r6 */
/* @0xecc04 beq 0xecc9c <_Z8ShowFormPKcb+0x168> */
/* @0xecc08 bl 0xb6568 <strncpy@plt> */
/* @0xecc0c ldrb r12, [r10] */
/* @0xecc10 mov r0, r8 */
/* @0xecc14 mov r1, r6 */
/* @0xecc18 ldr r2, [r11, #-0x38] */
/* @0xecc1c mov r3, r7 */
/* @0xecc20 str r12, [sp] */
/* @0xecc24 bl 0xb65c8 <snprintf@plt> */
/* @0xecc28 add r4, r4, #1 */
/* @0xecc2c mov r0, r5 */
/* @0xecc30 bl 0xb6538 <strlen@plt> */
/* @0xecc34 cmp r4, r0 */
/* @0xecc38 bge 0xeccb8 <_Z8ShowFormPKcb+0x184> */
/* @0xecc3c ldrb r3, [r5, r4] */
/* @0xecc40 add r10, r5, r4 */
/* @0xecc44 mov r0, r7 */
/* @0xecc48 cmp r3, #13 */
/* @0xecc4c cmpne r3, #10 */
/* @0xecc50 bne 0xecbf8 <_Z8ShowFormPKcb+0xc4> */
/* @0xecc54 mov r1, r9 */
/* @0xecc58 mov r2, r6 */
/* @0xecc5c bl 0xb6568 <strncpy@plt> */
/* @0xecc60 mov r3, r7 */
/* @0xecc64 mov r1, r6 */
/* @0xecc68 ldr r2, [r11, #-0x34] */
/* @0xecc6c str r8, [sp] */
/* @0xecc70 mov r0, r9 */
/* @0xecc74 bl 0xb65c8 <snprintf@plt> */
/* @0xecc78 mov r0, r8 */
/* @0xecc7c mov r1, #0 */
/* @0xecc80 mov r2, r6 */
/* @0xecc84 bl 0xb65b0 <memset@plt> */
/* @0xecc88 ldrb r3, [r10, #0x1] */
/* @0xecc8c cmp r3, #13 */
/* @0xecc90 cmpne r3, #10 */
/* @0xecc94 addeq r4, r4, #1 */
/* @0xecc98 b 0xecc28 <_Z8ShowFormPKcb+0xf4> */
/* @0xecc9c bl 0xb6568 <strncpy@plt> */
/* @0xecca0 mov r0, r8 */
/* @0xecca4 mov r1, r6 */
/* @0xecca8 ldr r2, [r11, #-0x40] */
/* @0xeccac mov r3, r7 */
/* @0xeccb0 bl 0xb65c8 <snprintf@plt> */
/* @0xeccb4 b 0xecc28 <_Z8ShowFormPKcb+0xf4> */
/* @0xeccb8 mov r1, r9 */
/* @0xeccbc mov r2, r6 */
/* @0xeccc0 mov r0, r7 */
/* @0xeccc4 ldr r4, [pc, #0xa4] */
/* @0xeccc8 bl 0xb6568 <strncpy@plt> */
/* @0xecccc ldr r2, [pc, #0xa0] */
/* @0xeccd0 mov r1, r6 */
/* @0xeccd4 mov r3, r7 */
/* @0xeccd8 add r2, pc, r2 */
/* @0xeccdc str r8, [sp] */
/* @0xecce0 mov r0, r9 */
/* @0xecce4 bl 0xb65c8 <snprintf@plt> */
/* @0xecce8 ldr r4, [pc, r4] */
/* @0xeccec ldr r1, [r11, #-0x3c] */
/* @0xeccf0 ldr r3, [r4] */
/* @0xeccf4 strb r1, [r3, #0x4] */
/* @0xeccf8 str r9, [r3] */
/* @0xeccfc bl 0x29cb74 <_Z19DebuggerIsConnectedv> */
/* @0xecd00 cmp r0, #0 */
/* @0xecd04 bne 0xecd38 <_Z8ShowFormPKcb+0x204> */
/* @0xecd08 ldr r0, [r4] */
/* @0xecd0c bl 0xf1c94 <_ZN10Code_Error4ShowEv> */
/* @0xecd10 subs r3, r0, #1 */
/* @0xecd14 rsbs r0, r3, #0 */
/* @0xecd18 adcs r0, r0, r3 */
/* @0xecd1c ldr r1, [r11, #-0x30] */
/* @0xecd20 ldr r2, [r11, #-0x28] */
/* @0xecd24 ldr r3, [r1] */
/* @0xecd28 cmp r2, r3 */
/* @0xecd2c bne 0xecd54 <_Z8ShowFormPKcb+0x220> */
/* @0xecd30 sub sp, r11, #32 */
/* @0xecd34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xecd38 ldr r4, [pc, #0x38] */
/* @0xecd3c ldr r4, [pc, r4] */
/* @0xecd40 str r9, [r4] */
/* @0xecd44 bl 0x29d634 <_Z19DebuggerMessageLoopv> */
/* @0xecd48 mov r0, #0 */
/* @0xecd4c str r0, [r4] */
/* @0xecd50 b 0xecd1c <_Z8ShowFormPKcb+0x1e8> */
/* @0xecd54 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xecd58 eorseq r0, r0, r8, lsl #28 */
/* @0xecd5c eoreq r8, r4, r12, ror r0 */
/* @0xecd60 eoreq r8, r4, r0, asr r0 */
/* @0xecd64 eoreq r8, r4, r12, lsr r0 */
/* @0xecd68 mlaeq r4, r12, pc, r7 */
/* @0xecd6c eoreq r7, r4, r0, lsr #31 */
/* @0xecd70 eorseq r1, r0, r0, lsr #1 */
/* @0xecd74 .word 0x00247efc */
/* @0xecd78 eorseq r1, r0, r0, asr r0 */
