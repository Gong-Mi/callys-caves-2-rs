/* libyoyo.so 覆盖卡组 0122
 * 函数 0x1865bc..0x188a9c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1865bc · LoadShader(unsigned int, char const*, char**) · size=420 · insn=105 */
/* @0x1865bc push {r4, r5, r6, r7, r8, lr} */
/* @0x1865c0 sub sp, sp, #16 */
/* @0x1865c4 ldr r4, [pc, #0x168] */
/* @0x1865c8 mov r6, r2 */
/* @0x1865cc ldr r3, [pc, #0x164] */
/* @0x1865d0 add r4, pc, r4 */
/* @0x1865d4 str r1, [sp, #0x4] */
/* @0x1865d8 ldr r3, [r4, r3] */
/* @0x1865dc ldr r3, [r3] */
/* @0x1865e0 blx r3 */
/* @0x1865e4 subs r5, r0, #0 */
/* @0x1865e8 beq 0x186718 <_Z10LoadShaderjPKcPPc+0x15c> */
/* @0x1865ec ldr r12, [pc, #0x148] */
/* @0x1865f0 mov r1, #1 */
/* @0x1865f4 add r2, sp, #4 */
/* @0x1865f8 mov r3, #0 */
/* @0x1865fc ldr r12, [r4, r12] */
/* @0x186600 ldr r12, [r12] */
/* @0x186604 blx r12 */
/* @0x186608 ldr r3, [pc, #0x130] */
/* @0x18660c mov r0, r5 */
/* @0x186610 ldr r3, [r4, r3] */
/* @0x186614 ldr r3, [r3] */
/* @0x186618 blx r3 */
/* @0x18661c ldr r3, [pc, #0x120] */
/* @0x186620 mov r0, r5 */
/* @0x186624 movw r1, #0x8b81 */
/* @0x186628 add r2, sp, #8 */
/* @0x18662c ldr r7, [r4, r3] */
/* @0x186630 ldr r3, [r7] */
/* @0x186634 blx r3 */
/* @0x186638 ldr r3, [sp, #0x8] */
/* @0x18663c cmp r3, #0 */
/* @0x186640 movne r0, r5 */
/* @0x186644 beq 0x186650 <_Z10LoadShaderjPKcPPc+0x94> */
/* @0x186648 add sp, sp, #16 */
/* @0x18664c pop {r4, r5, r6, r7, r8, pc} */
/* @0x186650 add r2, sp, #16 */
/* @0x186654 ldr r12, [r7] */
/* @0x186658 mov r0, r5 */
/* @0x18665c movw r1, #0x8b84 */
/* @0x186660 str r3, [r2, #-0x4]! */
/* @0x186664 blx r12 */
/* @0x186668 ldr r0, [sp, #0xc] */
/* @0x18666c cmp r0, #1 */
/* @0x186670 movle r0, #1024 */
/* @0x186674 strle r0, [sp, #0xc] */
/* @0x186678 bl 0xb6544 <malloc@plt> */
/* @0x18667c ldr r12, [pc, #0xc4] */
/* @0x186680 ldr r1, [sp, #0xc] */
/* @0x186684 mov r2, #0 */
/* @0x186688 ldr r12, [r4, r12] */
/* @0x18668c ldr r12, [r12] */
/* @0x186690 mov r7, r0 */
/* @0x186694 mov r3, r0 */
/* @0x186698 mov r0, r5 */
/* @0x18669c blx r12 */
/* @0x1866a0 ldr r3, [pc, #0xa4] */
/* @0x1866a4 ldr r1, [pc, #0xa4] */
/* @0x1866a8 mov r2, r7 */
/* @0x1866ac ldr r3, [r4, r3] */
/* @0x1866b0 add r1, pc, r1 */
/* @0x1866b4 ldr r8, [r3] */
/* @0x1866b8 ldr r3, [r8] */
/* @0x1866bc mov r0, r8 */
/* @0x1866c0 ldr r3, [r3, #0xc] */
/* @0x1866c4 blx r3 */
/* @0x1866c8 ldr r3, [r8] */
/* @0x1866cc ldr r1, [pc, #0x80] */
/* @0x1866d0 mov r0, r8 */
/* @0x1866d4 ldr r2, [sp, #0x4] */
/* @0x1866d8 ldr r3, [r3, #0xc] */
/* @0x1866dc add r1, pc, r1 */
/* @0x1866e0 blx r3 */
/* @0x1866e4 mov r1, r7 */
/* @0x1866e8 mov r0, r6 */
/* @0x1866ec bl 0x186544 <_Z16SetupErrorStringPPcS_> */
/* @0x1866f0 mov r0, r7 */
/* @0x1866f4 bl 0xb655c <free@plt> */
/* @0x1866f8 ldr r3, [pc, #0x58] */
/* @0x1866fc mov r0, r5 */
/* @0x186700 ldr r3, [r4, r3] */
/* @0x186704 ldr r3, [r3] */
/* @0x186708 blx r3 */
/* @0x18670c mov r0, #0 */
/* @0x186710 add sp, sp, #16 */
/* @0x186714 pop {r4, r5, r6, r7, r8, pc} */
/* @0x186718 ldr r1, [pc, #0x3c] */
/* @0x18671c mov r0, r6 */
/* @0x186720 add r1, pc, r1 */
/* @0x186724 bl 0x186544 <_Z16SetupErrorStringPPcS_> */
/* @0x186728 mov r0, r5 */
/* @0x18672c add sp, sp, #16 */
/* @0x186730 pop {r4, r5, r6, r7, r8, pc} */
/* @0x186734 eoreq r11, r6, r0, lsl #13 */
/* @0x186738 .word 0xffffbb94 */
/* @0x18673c .word 0xffffbb98 */
/* @0x186740 .word 0xffffbb9c */
/* @0x186744 .word 0xffffbba0 */
/* @0x186748 .word 0xffffbba4 */
/* @0x18674c .word 0xffffbac4 */
/* @0x186750 andseq r5, r12, r0, ror r5 */
/* @0x186754 andseq r5, r12, r0, ror #10 */
/* @0x186758 .word 0xffffbb7c */
/* @0x18675c ldrsbeq r5, [r12], -r12 */

/* ── FUNC 0x186760 · GetColumnsFromType(unsigned int) · size=168 · insn=42 */
/* @0x186760 movw r3, #0x8b55 */
/* @0x186764 cmp r0, r3 */
/* @0x186768 beq 0x186790 <_Z18GetColumnsFromTypej+0x30> */
/* @0x18676c bls 0x186798 <_Z18GetColumnsFromTypej+0x38> */
/* @0x186770 movw r3, #0x8b59 */
/* @0x186774 cmp r0, r3 */
/* @0x186778 beq 0x186790 <_Z18GetColumnsFromTypej+0x30> */
/* @0x18677c bls 0x1867e0 <_Z18GetColumnsFromTypej+0x80> */
/* @0x186780 movw r3, #0x8b5b */
/* @0x186784 cmp r0, r3 */
/* @0x186788 beq 0x1867b8 <_Z18GetColumnsFromTypej+0x58> */
/* @0x18678c blo 0x1867d8 <_Z18GetColumnsFromTypej+0x78> */
/* @0x186790 mov r0, #4 */
/* @0x186794 bx lr */
/* @0x186798 movw r3, #0x8b51 */
/* @0x18679c cmp r0, r3 */
/* @0x1867a0 beq 0x1867b8 <_Z18GetColumnsFromTypej+0x58> */
/* @0x1867a4 bls 0x1867c0 <_Z18GetColumnsFromTypej+0x60> */
/* @0x1867a8 movw r3, #0x8b53 */
/* @0x1867ac cmp r0, r3 */
/* @0x1867b0 beq 0x1867d8 <_Z18GetColumnsFromTypej+0x78> */
/* @0x1867b4 bls 0x186790 <_Z18GetColumnsFromTypej+0x30> */
/* @0x1867b8 mov r0, #3 */
/* @0x1867bc bx lr */
/* @0x1867c0 movw r3, #0x1406 */
/* @0x1867c4 cmp r0, r3 */
/* @0x1867c8 beq 0x1867f0 <_Z18GetColumnsFromTypej+0x90> */
/* @0x1867cc movw r3, #0x8b50 */
/* @0x1867d0 cmp r0, r3 */
/* @0x1867d4 bne 0x1867f8 <_Z18GetColumnsFromTypej+0x98> */
/* @0x1867d8 mov r0, #2 */
/* @0x1867dc bx lr */
/* @0x1867e0 movw r3, #0x8b57 */
/* @0x1867e4 cmp r0, r3 */
/* @0x1867e8 beq 0x1867d8 <_Z18GetColumnsFromTypej+0x78> */
/* @0x1867ec bhi 0x1867b8 <_Z18GetColumnsFromTypej+0x58> */
/* @0x1867f0 mov r0, #1 */
/* @0x1867f4 bx lr */
/* @0x1867f8 movw r3, #0x1404 */
/* @0x1867fc cmp r0, r3 */
/* @0x186800 bne 0x186790 <_Z18GetColumnsFromTypej+0x30> */
/* @0x186804 b 0x1867f0 <_Z18GetColumnsFromTypej+0x90> */

/* ── FUNC 0x186808 · GetRowsFromType(unsigned int) · size=44 · insn=11 */
/* @0x186808 sub r0, r0, #35584 */
/* @0x18680c sub r0, r0, #90 */
/* @0x186810 cmp r0, #2 */
/* @0x186814 bhi 0x186828 <_Z15GetRowsFromTypej+0x20> */
/* @0x186818 ldr r3, [pc, #0x10] */
/* @0x18681c add r3, pc, r3 */
/* @0x186820 ldr r0, [r3, r0, lsl #2] */
/* @0x186824 bx lr */
/* @0x186828 mov r0, #1 */
/* @0x18682c bx lr */
/* @0x186830 andseq r7, sp, r0, asr #8 */

/* ── FUNC 0x186834 · InitialiseUniforms(GLSLShader*) · size=1656 · insn=414 */
/* @0x186834 ldr r12, [pc, #0x648] */
/* @0x186838 ldr r3, [pc, #0x648] */
/* @0x18683c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x186840 add r12, pc, r12 */
/* @0x186844 sub sp, sp, #228 */
/* @0x186848 subs r4, r0, #0 */
/* @0x18684c str r12, [sp, #0x24] */
/* @0x186850 ldr r3, [r12, r3] */
/* @0x186854 str r3, [sp, #0x38] */
/* @0x186858 ldr r3, [r3] */
/* @0x18685c str r3, [sp, #0xdc] */
/* @0x186860 beq 0x1869a4 <_Z18InitialiseUniformsP10GLSLShader+0x170> */
/* @0x186864 ldr r3, [pc, #0x620] */
/* @0x186868 ldr r0, [r4, #0x8] */
/* @0x18686c ldr r3, [r12, r3] */
/* @0x186870 str r3, [sp, #0x44] */
/* @0x186874 ldr r3, [r3] */
/* @0x186878 blx r3 */
/* @0x18687c ldr r12, [sp, #0x24] */
/* @0x186880 ldr r3, [pc, #0x608] */
/* @0x186884 movw r1, #0x8b86 */
/* @0x186888 ldr r0, [r4, #0x8] */
/* @0x18688c add r2, sp, #76 */
/* @0x186890 ldr r3, [r12, r3] */
/* @0x186894 ldr r3, [r3] */
/* @0x186898 blx r3 */
/* @0x18689c ldr r3, [sp, #0x4c] */
/* @0x1868a0 cmp r3, #0 */
/* @0x1868a4 ble 0x186e54 <_Z18InitialiseUniformsP10GLSLShader+0x620> */
/* @0x1868a8 mov r12, #0 */
/* @0x1868ac str r12, [sp, #0x28] */
/* @0x1868b0 ldr r12, [pc, #0x5dc] */
/* @0x1868b4 mov r8, #0 */
/* @0x1868b8 ldr r3, [pc, #0x5d8] */
/* @0x1868bc mvn r9, #0 */
/* @0x1868c0 add r12, pc, r12 */
/* @0x1868c4 str r12, [sp, #0x18] */
/* @0x1868c8 mvn r12, #0 */
/* @0x1868cc str r12, [sp, #0x30] */
/* @0x1868d0 add r12, sp, #84 */
/* @0x1868d4 str r12, [sp, #0x1c] */
/* @0x1868d8 ldr r12, [sp, #0x24] */
/* @0x1868dc add r11, sp, #88 */
/* @0x1868e0 add r5, sp, #92 */
/* @0x1868e4 mov r6, r8 */
/* @0x1868e8 movw r10, #0x8b5e */
/* @0x1868ec ldr r7, [r12, r3] */
/* @0x1868f0 str r11, [sp, #0x20] */
/* @0x1868f4 mov r11, r9 */
/* @0x1868f8 str r8, [sp, #0x2c] */
/* @0x1868fc b 0x18693c <_Z18InitialiseUniformsP10GLSLShader+0x108> */
/* @0x186900 movw r0, #0x8b60 */
/* @0x186904 cmp r3, r0 */
/* @0x186908 ldrne r12, [sp, #0x28] */
/* @0x18690c addne r12, r12, #1 */
/* @0x186910 strne r12, [sp, #0x28] */
/* @0x186914 mov r0, r5 */
/* @0x186918 ldr r1, [sp, #0x18] */
/* @0x18691c bl 0xb6574 <strcmp@plt> */
/* @0x186920 ldr r3, [sp, #0x4c] */
/* @0x186924 cmp r0, #0 */
/* @0x186928 moveq r11, r6 */
/* @0x18692c add r6, r6, #1 */
/* @0x186930 moveq r8, #1 */
/* @0x186934 cmp r3, r6 */
/* @0x186938 ble 0x1869c0 <_Z18InitialiseUniformsP10GLSLShader+0x18c> */
/* @0x18693c ldr r12, [sp, #0x1c] */
/* @0x186940 mov r3, #0 */
/* @0x186944 ldr r0, [r4, #0x8] */
/* @0x186948 mov r1, r6 */
/* @0x18694c str r5, [sp, #0x8] */
/* @0x186950 mov r2, #128 */
/* @0x186954 str r12, [sp] */
/* @0x186958 ldr r12, [sp, #0x20] */
/* @0x18695c str r9, [sp, #0x54] */
/* @0x186960 str r9, [sp, #0x58] */
/* @0x186964 str r12, [sp, #0x4] */
/* @0x186968 ldr r12, [r7] */
/* @0x18696c blx r12 */
/* @0x186970 ldr r3, [sp, #0x58] */
/* @0x186974 cmp r3, r10 */
/* @0x186978 bne 0x186900 <_Z18InitialiseUniformsP10GLSLShader+0xcc> */
/* @0x18697c ldr r12, [sp, #0x2c] */
/* @0x186980 add r12, r12, #1 */
/* @0x186984 str r12, [sp, #0x2c] */
/* @0x186988 b 0x186914 <_Z18InitialiseUniformsP10GLSLShader+0xe0> */
/* @0x18698c ldr r12, [sp, #0x28] */
/* @0x186990 mov r0, #0 */
/* @0x186994 str r12, [r4, #0x7c] */
/* @0x186998 ldr r12, [sp, #0x44] */
/* @0x18699c ldr r3, [r12] */
/* @0x1869a0 blx r3 */
/* @0x1869a4 ldr r12, [sp, #0x38] */
/* @0x1869a8 ldr r2, [sp, #0xdc] */
/* @0x1869ac ldr r3, [r12] */
/* @0x1869b0 cmp r2, r3 */
/* @0x1869b4 bne 0x186e80 <_Z18InitialiseUniformsP10GLSLShader+0x64c> */
/* @0x1869b8 add sp, sp, #228 */
/* @0x1869bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1869c0 ldr r5, [sp, #0x2c] */
/* @0x1869c4 ldr r12, [sp, #0x28] */
/* @0x1869c8 sub r6, r5, #1 */
/* @0x1869cc str r11, [sp, #0x30] */
/* @0x1869d0 str r12, [sp, #0x34] */
/* @0x1869d4 sub r12, r12, #1 */
/* @0x1869d8 str r12, [sp, #0x40] */
/* @0x1869dc ldr r0, [r4, #0x14] */
/* @0x1869e0 cmp r0, #0 */
/* @0x1869e4 beq 0x186a20 <_Z18InitialiseUniformsP10GLSLShader+0x1ec> */
/* @0x1869e8 ldr r7, [r0, #-0x4] */
/* @0x1869ec add r7, r7, r7, lsl #1 */
/* @0x1869f0 add r7, r0, r7, lsl #2 */
/* @0x1869f4 cmp r0, r7 */
/* @0x1869f8 beq 0x186a10 <_Z18InitialiseUniformsP10GLSLShader+0x1dc> */
/* @0x1869fc ldr r0, [r7, #-0xc]! */
/* @0x186a00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x186a04 ldr r0, [r4, #0x14] */
/* @0x186a08 cmp r0, r7 */
/* @0x186a0c bne 0x1869fc <_Z18InitialiseUniformsP10GLSLShader+0x1c8> */
/* @0x186a10 sub r0, r0, #8 */
/* @0x186a14 bl 0x27d1d4 <_ZdaPv> */
/* @0x186a18 mov r3, #0 */
/* @0x186a1c str r3, [r4, #0x14] */
/* @0x186a20 cmp r5, #178257920 */
/* @0x186a24 addls r0, r5, r5, lsl #1 */
/* @0x186a28 mvnhi r0, #0 */
/* @0x186a2c lslls r0, r0, #2 */
/* @0x186a30 addls r0, r0, #8 */
/* @0x186a34 bl 0x27d14c <_Znaj> */
/* @0x186a38 cmn r6, #1 */
/* @0x186a3c mov r3, #12 */
/* @0x186a40 str r5, [r0, #0x4] */
/* @0x186a44 str r3, [r0] */
/* @0x186a48 beq 0x186a7c <_Z18InitialiseUniformsP10GLSLShader+0x248> */
/* @0x186a4c mov r2, #0 */
/* @0x186a50 add r6, r6, #1 */
/* @0x186a54 add r3, r0, #20 */
/* @0x186a58 mov r1, r2 */
/* @0x186a5c mvn r12, #0 */
/* @0x186a60 add r2, r2, #1 */
/* @0x186a64 str r1, [r3, #-0xc] */
/* @0x186a68 cmp r2, r6 */
/* @0x186a6c str r12, [r3, #-0x8] */
/* @0x186a70 str r1, [r3, #-0x4] */
/* @0x186a74 add r3, r3, #12 */
/* @0x186a78 bne 0x186a60 <_Z18InitialiseUniformsP10GLSLShader+0x22c> */
/* @0x186a7c ldr r3, [sp, #0x4c] */
/* @0x186a80 add r0, r0, #8 */
/* @0x186a84 str r0, [r4, #0x14] */
/* @0x186a88 cmp r3, #0 */
/* @0x186a8c ble 0x186bf0 <_Z18InitialiseUniformsP10GLSLShader+0x3bc> */
/* @0x186a90 ldr r12, [pc, #0x404] */
/* @0x186a94 mov r6, #0 */
/* @0x186a98 ldr r3, [pc, #0x3f8] */
/* @0x186a9c add r11, sp, #88 */
/* @0x186aa0 add r12, pc, r12 */
/* @0x186aa4 str r12, [sp, #0x3c] */
/* @0x186aa8 add r12, sp, #84 */
/* @0x186aac str r12, [sp, #0x1c] */
/* @0x186ab0 ldr r12, [sp, #0x24] */
/* @0x186ab4 add r5, sp, #92 */
/* @0x186ab8 mvn r9, #0 */
/* @0x186abc mov r10, r8 */
/* @0x186ac0 ldr r7, [r12, r3] */
/* @0x186ac4 add r12, sp, #80 */
/* @0x186ac8 str r12, [sp, #0x18] */
/* @0x186acc b 0x186ae0 <_Z18InitialiseUniformsP10GLSLShader+0x2ac> */
/* @0x186ad0 ldr r3, [sp, #0x4c] */
/* @0x186ad4 add r6, r6, #1 */
/* @0x186ad8 cmp r3, r6 */
/* @0x186adc ble 0x186bf0 <_Z18InitialiseUniformsP10GLSLShader+0x3bc> */
/* @0x186ae0 mov r12, #0 */
/* @0x186ae4 str r12, [sp, #0x58] */
/* @0x186ae8 ldr r12, [sp, #0x18] */
/* @0x186aec mov r3, r11 */
/* @0x186af0 ldr r0, [r4, #0x8] */
/* @0x186af4 mov r1, r6 */
/* @0x186af8 str r5, [sp, #0x8] */
/* @0x186afc mov r2, #128 */
/* @0x186b00 str r12, [sp] */
/* @0x186b04 ldr r12, [sp, #0x1c] */
/* @0x186b08 str r9, [sp, #0x50] */
/* @0x186b0c str r9, [sp, #0x54] */
/* @0x186b10 str r12, [sp, #0x4] */
/* @0x186b14 ldr r12, [r7] */
/* @0x186b18 blx r12 */
/* @0x186b1c ldr r3, [sp, #0x54] */
/* @0x186b20 movw r0, #0x8b5e */
/* @0x186b24 cmp r3, r0 */
/* @0x186b28 bne 0x186ad0 <_Z18InitialiseUniformsP10GLSLShader+0x29c> */
/* @0x186b2c ldr r12, [sp, #0x30] */
/* @0x186b30 mov r2, #70 */
/* @0x186b34 ldr r0, [sp, #0x58] */
/* @0x186b38 mov r3, #1 */
/* @0x186b3c cmp r6, r12 */
/* @0x186b40 ldr r12, [r4, #0x14] */
/* @0x186b44 addne r8, r10, r10, lsl #1 */
/* @0x186b48 ldr r1, [sp, #0x3c] */
/* @0x186b4c add r0, r0, r3 */
/* @0x186b50 moveq r8, #0 */
/* @0x186b54 lslne r8, r8, #2 */
/* @0x186b58 strne r10, [sp, #0x20] */
/* @0x186b5c streq r8, [sp, #0x20] */
/* @0x186b60 addne r10, r10, #1 */
/* @0x186b64 str r12, [sp, #0x14] */
/* @0x186b68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x186b6c ldr r3, [r4, #0x14] */
/* @0x186b70 mov r1, r5 */
/* @0x186b74 ldr r12, [sp, #0x14] */
/* @0x186b78 add r6, r6, #1 */
/* @0x186b7c str r0, [r12, r8] */
/* @0x186b80 ldr r0, [r3, r8] */
/* @0x186b84 bl 0xb65a4 <strcpy@plt> */
/* @0x186b88 ldr r3, [r4, #0x14] */
/* @0x186b8c ldr r12, [sp, #0x20] */
/* @0x186b90 mov r1, r5 */
/* @0x186b94 add r3, r3, r8 */
/* @0x186b98 ldr r0, [r4, #0x8] */
/* @0x186b9c ldr r2, [pc, #0x2fc] */
/* @0x186ba0 str r12, [r3, #0x8] */
/* @0x186ba4 ldr r12, [sp, #0x24] */
/* @0x186ba8 ldr r2, [r12, r2] */
/* @0x186bac ldr r2, [r2] */
/* @0x186bb0 str r3, [sp, #0x14] */
/* @0x186bb4 blx r2 */
/* @0x186bb8 ldr r12, [r4, #0x14] */
/* @0x186bbc ldr r3, [sp, #0x14] */
/* @0x186bc0 ldr r2, [pc, #0x2dc] */
/* @0x186bc4 add r8, r12, r8 */
/* @0x186bc8 ldr r12, [sp, #0x24] */
/* @0x186bcc ldr r1, [sp, #0x20] */
/* @0x186bd0 str r0, [r3, #0x4] */
/* @0x186bd4 ldr r3, [r12, r2] */
/* @0x186bd8 ldr r0, [r8, #0x4] */
/* @0x186bdc ldr r3, [r3] */
/* @0x186be0 blx r3 */
/* @0x186be4 ldr r3, [sp, #0x4c] */
/* @0x186be8 cmp r3, r6 */
/* @0x186bec bgt 0x186ae0 <_Z18InitialiseUniformsP10GLSLShader+0x2ac> */
/* @0x186bf0 ldr r0, [r4, #0x78] */
/* @0x186bf4 ldr r12, [sp, #0x2c] */
/* @0x186bf8 cmp r0, #0 */
/* @0x186bfc str r12, [r4, #0x18] */
/* @0x186c00 beq 0x186c3c <_Z18InitialiseUniformsP10GLSLShader+0x408> */
/* @0x186c04 ldr r5, [r0, #-0x4] */
/* @0x186c08 rsb r5, r5, r5, lsl #3 */
/* @0x186c0c add r5, r0, r5, lsl #2 */
/* @0x186c10 cmp r0, r5 */
/* @0x186c14 beq 0x186c2c <_Z18InitialiseUniformsP10GLSLShader+0x3f8> */
/* @0x186c18 ldr r0, [r5, #-0x1c]! */
/* @0x186c1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x186c20 ldr r0, [r4, #0x78] */
/* @0x186c24 cmp r0, r5 */
/* @0x186c28 bne 0x186c18 <_Z18InitialiseUniformsP10GLSLShader+0x3e4> */
/* @0x186c2c sub r0, r0, #8 */
/* @0x186c30 bl 0x27d1d4 <_ZdaPv> */
/* @0x186c34 mov r3, #0 */
/* @0x186c38 str r3, [r4, #0x78] */
/* @0x186c3c ldr r12, [sp, #0x34] */
/* @0x186c40 cmp r12, #76546048 */
/* @0x186c44 rsbls r0, r12, r12, lsl #3 */
/* @0x186c48 mvnhi r0, #0 */
/* @0x186c4c lslls r0, r0, #2 */
/* @0x186c50 addls r0, r0, #8 */
/* @0x186c54 bl 0x27d14c <_Znaj> */
/* @0x186c58 ldr r12, [sp, #0x40] */
/* @0x186c5c mov r3, #28 */
/* @0x186c60 cmn r12, #1 */
/* @0x186c64 ldr r12, [sp, #0x34] */
/* @0x186c68 str r3, [r0] */
/* @0x186c6c str r12, [r0, #0x4] */
/* @0x186c70 beq 0x186cc4 <_Z18InitialiseUniformsP10GLSLShader+0x490> */
/* @0x186c74 ldr r12, [sp, #0x40] */
/* @0x186c78 mov r2, #0 */
/* @0x186c7c add r3, r0, #36 */
/* @0x186c80 mov r6, r2 */
/* @0x186c84 add r7, r12, #1 */
/* @0x186c88 mvn r5, #0 */
/* @0x186c8c movw lr, #0x8b52 */
/* @0x186c90 mov r12, #4 */
/* @0x186c94 mov r1, #1 */
/* @0x186c98 add r2, r2, #1 */
/* @0x186c9c str r6, [r3, #-0x1c] */
/* @0x186ca0 cmp r2, r7 */
/* @0x186ca4 str r5, [r3, #-0x18] */
/* @0x186ca8 str lr, [r3, #-0x14] */
/* @0x186cac add r3, r3, #28 */
/* @0x186cb0 str r12, [r3, #-0x2c] */
/* @0x186cb4 str r1, [r3, #-0x28] */
/* @0x186cb8 str r12, [r3, #-0x24] */
/* @0x186cbc str r1, [r3, #-0x20] */
/* @0x186cc0 bne 0x186c98 <_Z18InitialiseUniformsP10GLSLShader+0x464> */
/* @0x186cc4 ldr r3, [sp, #0x4c] */
/* @0x186cc8 add r0, r0, #8 */
/* @0x186ccc str r0, [r4, #0x78] */
/* @0x186cd0 cmp r3, #0 */
/* @0x186cd4 ble 0x18698c <_Z18InitialiseUniformsP10GLSLShader+0x158> */
/* @0x186cd8 ldr r12, [pc, #0x1c8] */
/* @0x186cdc mov r9, #0 */
/* @0x186ce0 ldr r3, [pc, #0x1b0] */
/* @0x186ce4 add r11, sp, #88 */
/* @0x186ce8 add r12, pc, r12 */
/* @0x186cec str r12, [sp, #0x20] */
/* @0x186cf0 add r12, sp, #84 */
/* @0x186cf4 str r12, [sp, #0x1c] */
/* @0x186cf8 ldr r12, [sp, #0x24] */
/* @0x186cfc add r5, sp, #92 */
/* @0x186d00 mov r6, r9 */
/* @0x186d04 ldr r10, [sp, #0x1c] */
/* @0x186d08 ldr r7, [r12, r3] */
/* @0x186d0c add r12, sp, #80 */
/* @0x186d10 str r12, [sp, #0x18] */
/* @0x186d14 b 0x186d28 <_Z18InitialiseUniformsP10GLSLShader+0x4f4> */
/* @0x186d18 ldr r3, [sp, #0x4c] */
/* @0x186d1c add r6, r6, #1 */
/* @0x186d20 cmp r3, r6 */
/* @0x186d24 ble 0x18698c <_Z18InitialiseUniformsP10GLSLShader+0x158> */
/* @0x186d28 mov r12, #0 */
/* @0x186d2c str r12, [sp, #0x58] */
/* @0x186d30 ldr r12, [sp, #0x18] */
/* @0x186d34 mvn r2, #0 */
/* @0x186d38 ldr r0, [r4, #0x8] */
/* @0x186d3c movw r3, #0x8b52 */
/* @0x186d40 str r2, [sp, #0x50] */
/* @0x186d44 mov r1, r6 */
/* @0x186d48 mov r2, #128 */
/* @0x186d4c str r3, [sp, #0x54] */
/* @0x186d50 str r12, [sp] */
/* @0x186d54 mov r3, r11 */
/* @0x186d58 str r10, [sp, #0x4] */
/* @0x186d5c str r5, [sp, #0x8] */
/* @0x186d60 ldr r12, [r7] */
/* @0x186d64 blx r12 */
/* @0x186d68 ldr r3, [sp, #0x54] */
/* @0x186d6c movw r2, #0x8b60 */
/* @0x186d70 movw r0, #0x8b5e */
/* @0x186d74 cmp r3, r0 */
/* @0x186d78 cmpne r3, r2 */
/* @0x186d7c beq 0x186d18 <_Z18InitialiseUniformsP10GLSLShader+0x4e4> */
/* @0x186d80 ldr r12, [r4, #0x78] */
/* @0x186d84 mov r3, #1 */
/* @0x186d88 ldr r0, [sp, #0x58] */
/* @0x186d8c mov r2, #70 */
/* @0x186d90 ldr r1, [sp, #0x20] */
/* @0x186d94 add r0, r0, r3 */
/* @0x186d98 str r12, [sp, #0x14] */
/* @0x186d9c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x186da0 ldr r2, [r4, #0x78] */
/* @0x186da4 ldr r12, [sp, #0x14] */
/* @0x186da8 rsb r3, r9, r9, lsl #3 */
/* @0x186dac mov r1, r5 */
/* @0x186db0 add r9, r9, #1 */
/* @0x186db4 lsl r8, r3, #2 */
/* @0x186db8 str r0, [r12, r3, lsl #2] */
/* @0x186dbc ldr r0, [r2, r3, lsl #2] */
/* @0x186dc0 bl 0xb65a4 <strcpy@plt> */
/* @0x186dc4 ldr r12, [sp, #0x24] */
/* @0x186dc8 ldr r3, [pc, #0xd0] */
/* @0x186dcc mov r1, r5 */
/* @0x186dd0 ldr r2, [r4, #0x78] */
/* @0x186dd4 ldr r0, [r4, #0x8] */
/* @0x186dd8 ldr r3, [r12, r3] */
/* @0x186ddc add r2, r2, r8 */
/* @0x186de0 ldr r3, [r3] */
/* @0x186de4 str r2, [sp, #0x14] */
/* @0x186de8 blx r3 */
/* @0x186dec ldr r2, [sp, #0x14] */
/* @0x186df0 ldr r3, [r4, #0x78] */
/* @0x186df4 add r3, r3, r8 */
/* @0x186df8 str r0, [r2, #0x4] */
/* @0x186dfc ldr r0, [sp, #0x54] */
/* @0x186e00 str r0, [r3, #0x8] */
/* @0x186e04 str r3, [sp, #0x14] */
/* @0x186e08 bl 0x186760 <_Z18GetColumnsFromTypej> */
/* @0x186e0c ldr r3, [sp, #0x14] */
/* @0x186e10 ldr r2, [r4, #0x78] */
/* @0x186e14 add r2, r2, r8 */
/* @0x186e18 str r0, [r3, #0xc] */
/* @0x186e1c ldr r0, [sp, #0x54] */
/* @0x186e20 str r2, [sp, #0x14] */
/* @0x186e24 bl 0x186808 <_Z15GetRowsFromTypej> */
/* @0x186e28 ldr r3, [r4, #0x78] */
/* @0x186e2c ldr r2, [sp, #0x14] */
/* @0x186e30 add r8, r3, r8 */
/* @0x186e34 ldr r3, [r8, #0xc] */
/* @0x186e38 str r0, [r2, #0x10] */
/* @0x186e3c ldr r2, [r8, #0x10] */
/* @0x186e40 mul r3, r2, r3 */
/* @0x186e44 str r3, [r8, #0x14] */
/* @0x186e48 ldr r3, [sp, #0x50] */
/* @0x186e4c str r3, [r8, #0x18] */
/* @0x186e50 b 0x186d18 <_Z18InitialiseUniformsP10GLSLShader+0x4e4> */
/* @0x186e54 mvn r12, #0 */
/* @0x186e58 str r12, [sp, #0x40] */
/* @0x186e5c mov r12, #0 */
/* @0x186e60 mvn r6, #0 */
/* @0x186e64 str r12, [sp, #0x34] */
/* @0x186e68 mov r5, r12 */
/* @0x186e6c str r6, [sp, #0x30] */
/* @0x186e70 mov r8, r12 */
/* @0x186e74 str r12, [sp, #0x28] */
/* @0x186e78 str r12, [sp, #0x2c] */
/* @0x186e7c b 0x1869dc <_Z18InitialiseUniformsP10GLSLShader+0x1a8> */
/* @0x186e80 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x186e84 eoreq r11, r6, r0, lsl r4 */
/* @0x186e88 .word 0xffffbd00 */
/* @0x186e8c .word 0xffffbb80 */
/* @0x186e90 .word 0xffffbbb4 */
/* @0x186e94 andseq r5, r12, r4, lsl #7 */
/* @0x186e98 .word 0xffffbbf8 */
/* @0x186e9c mulseq r10, r0, r5 */
/* @0x186ea0 .word 0xffffbbc0 */
/* @0x186ea4 .word 0xffffbb84 */
/* @0x186ea8 andseq r10, r10, r8, asr #6 */

/* ── FUNC 0x186eac · InitialisePreParsedAttribs(GLSLShader*, int, char**) · size=1468 · insn=367 */
/* @0x186eac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x186eb0 subs r5, r0, #0 */
/* @0x186eb4 sub sp, sp, #92 */
/* @0x186eb8 mov r9, r1 */
/* @0x186ebc mov r6, r2 */
/* @0x186ec0 beq 0x187050 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x1a4> */
/* @0x186ec4 cmp r2, #0 */
/* @0x186ec8 cmpne r1, #0 */
/* @0x186ecc beq 0x187050 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x1a4> */
/* @0x186ed0 ldr r0, [r5, #0x2c] */
/* @0x186ed4 cmp r0, #0 */
/* @0x186ed8 beq 0x186ee0 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x34> */
/* @0x186edc bl 0x27d1d4 <_ZdaPv> */
/* @0x186ee0 cmp r9, #532676608 */
/* @0x186ee4 bhi 0x187058 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x1ac> */
/* @0x186ee8 lsl r4, r9, #2 */
/* @0x186eec mov r0, r4 */
/* @0x186ef0 bl 0x27d14c <_Znaj> */
/* @0x186ef4 str r9, [r5, #0x30] */
/* @0x186ef8 str r0, [r5, #0x2c] */
/* @0x186efc mov r0, r4 */
/* @0x186f00 bl 0x27d14c <_Znaj> */
/* @0x186f04 str r0, [r5, #0x34] */
/* @0x186f08 mov r0, r4 */
/* @0x186f0c bl 0x27d14c <_Znaj> */
/* @0x186f10 mov r1, #0 */
/* @0x186f14 mov r2, #60 */
/* @0x186f18 str r0, [r5, #0x38] */
/* @0x186f1c add r0, sp, #28 */
/* @0x186f20 bl 0xb65b0 <memset@plt> */
/* @0x186f24 ldr r2, [pc, #0x49c] */
/* @0x186f28 mov r4, #0 */
/* @0x186f2c ldr r3, [pc, #0x498] */
/* @0x186f30 add r2, pc, r2 */
/* @0x186f34 ldr r10, [pc, #0x494] */
/* @0x186f38 add r3, pc, r3 */
/* @0x186f3c str r2, [sp] */
/* @0x186f40 str r3, [sp, #0x4] */
/* @0x186f44 ldr r10, [pc, r10] */
/* @0x186f48 ldr r2, [pc, #0x484] */
/* @0x186f4c ldr r3, [pc, #0x484] */
/* @0x186f50 add r2, pc, r2 */
/* @0x186f54 str r2, [sp, #0x8] */
/* @0x186f58 add r3, pc, r3 */
/* @0x186f5c ldr r2, [pc, #0x478] */
/* @0x186f60 str r3, [sp, #0xc] */
/* @0x186f64 ldr r3, [pc, #0x474] */
/* @0x186f68 add r2, pc, r2 */
/* @0x186f6c str r2, [sp, #0x10] */
/* @0x186f70 add r3, pc, r3 */
/* @0x186f74 str r3, [sp, #0x14] */
/* @0x186f78 ldr r3, [r10] */
/* @0x186f7c lsl r8, r4, #2 */
/* @0x186f80 ldr r1, [r6] */
/* @0x186f84 ldr r0, [r5, #0x8] */
/* @0x186f88 ldr r11, [r5, #0x2c] */
/* @0x186f8c blx r3 */
/* @0x186f90 ldr r7, [r6], #4 */
/* @0x186f94 ldr r1, [pc, #0x448] */
/* @0x186f98 add r1, pc, r1 */
/* @0x186f9c str r0, [r11, r4, lsl #2] */
/* @0x186fa0 mov r0, r7 */
/* @0x186fa4 bl 0xb6574 <strcmp@plt> */
/* @0x186fa8 cmp r0, #0 */
/* @0x186fac moveq r3, #1 */
/* @0x186fb0 moveq r1, r3 */
/* @0x186fb4 beq 0x187020 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x174> */
/* @0x186fb8 ldr r1, [pc, #0x428] */
/* @0x186fbc mov r0, r7 */
/* @0x186fc0 add r1, pc, r1 */
/* @0x186fc4 bl 0xb6574 <strcmp@plt> */
/* @0x186fc8 cmp r0, #0 */
/* @0x186fcc beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x186fd0 ldr r1, [pc, #0x414] */
/* @0x186fd4 mov r0, r7 */
/* @0x186fd8 add r1, pc, r1 */
/* @0x186fdc bl 0xb6574 <strcmp@plt> */
/* @0x186fe0 cmp r0, #0 */
/* @0x186fe4 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x186fe8 ldr r1, [pc, #0x400] */
/* @0x186fec mov r0, r7 */
/* @0x186ff0 add r1, pc, r1 */
/* @0x186ff4 bl 0xb6574 <strcmp@plt> */
/* @0x186ff8 cmp r0, #0 */
/* @0x186ffc beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187000 ldr r1, [pc, #0x3ec] */
/* @0x187004 mov r0, r7 */
/* @0x187008 add r1, pc, r1 */
/* @0x18700c bl 0xb6574 <strcmp@plt> */
/* @0x187010 cmp r0, #0 */
/* @0x187014 bne 0x18709c <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x1f0> */
/* @0x187018 mov r3, #2 */
/* @0x18701c mov r1, r3 */
/* @0x187020 add r2, sp, #88 */
/* @0x187024 ldr r7, [r5, #0x34] */
/* @0x187028 add r3, r2, r3, lsl #2 */
/* @0x18702c ldr r0, [r5, #0x38] */
/* @0x187030 add r4, r4, #1 */
/* @0x187034 ldr r2, [r3, #-0x3c] */
/* @0x187038 cmp r4, r9 */
/* @0x18703c str r1, [r7, r8] */
/* @0x187040 add r12, r2, #1 */
/* @0x187044 str r12, [r3, #-0x3c] */
/* @0x187048 str r2, [r0, r8] */
/* @0x18704c bne 0x186f78 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0xcc> */
/* @0x187050 add sp, sp, #92 */
/* @0x187054 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x187058 mvn r0, #0 */
/* @0x18705c bl 0x27d14c <_Znaj> */
/* @0x187060 str r9, [r5, #0x30] */
/* @0x187064 str r0, [r5, #0x2c] */
/* @0x187068 mvn r0, #0 */
/* @0x18706c bl 0x27d14c <_Znaj> */
/* @0x187070 str r0, [r5, #0x34] */
/* @0x187074 mvn r0, #0 */
/* @0x187078 bl 0x27d14c <_Znaj> */
/* @0x18707c mov r1, #0 */
/* @0x187080 mov r2, #60 */
/* @0x187084 str r0, [r5, #0x38] */
/* @0x187088 add r0, sp, #28 */
/* @0x18708c bl 0xb65b0 <memset@plt> */
/* @0x187090 cmp r9, #0 */
/* @0x187094 bgt 0x186f24 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x78> */
/* @0x187098 b 0x187050 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x1a4> */
/* @0x18709c ldr r1, [pc, #0x354] */
/* @0x1870a0 mov r0, r7 */
/* @0x1870a4 add r1, pc, r1 */
/* @0x1870a8 bl 0xb6574 <strcmp@plt> */
/* @0x1870ac cmp r0, #0 */
/* @0x1870b0 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x1870b4 ldr r1, [pc, #0x340] */
/* @0x1870b8 mov r0, r7 */
/* @0x1870bc add r1, pc, r1 */
/* @0x1870c0 bl 0xb6574 <strcmp@plt> */
/* @0x1870c4 cmp r0, #0 */
/* @0x1870c8 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x1870cc ldr r1, [pc, #0x32c] */
/* @0x1870d0 mov r0, r7 */
/* @0x1870d4 add r1, pc, r1 */
/* @0x1870d8 bl 0xb6574 <strcmp@plt> */
/* @0x1870dc cmp r0, #0 */
/* @0x1870e0 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x1870e4 ldr r1, [pc, #0x318] */
/* @0x1870e8 mov r0, r7 */
/* @0x1870ec add r1, pc, r1 */
/* @0x1870f0 bl 0xb6574 <strcmp@plt> */
/* @0x1870f4 cmp r0, #0 */
/* @0x1870f8 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x1870fc ldr r1, [pc, #0x304] */
/* @0x187100 mov r0, r7 */
/* @0x187104 add r1, pc, r1 */
/* @0x187108 bl 0xb6574 <strcmp@plt> */
/* @0x18710c cmp r0, #0 */
/* @0x187110 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187114 ldr r1, [pc, #0x2f0] */
/* @0x187118 mov r0, r7 */
/* @0x18711c add r1, pc, r1 */
/* @0x187120 bl 0xb6574 <strcmp@plt> */
/* @0x187124 cmp r0, #0 */
/* @0x187128 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x18712c ldr r1, [pc, #0x2dc] */
/* @0x187130 mov r0, r7 */
/* @0x187134 add r1, pc, r1 */
/* @0x187138 bl 0xb6574 <strcmp@plt> */
/* @0x18713c cmp r0, #0 */
/* @0x187140 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187144 ldr r1, [pc, #0x2c8] */
/* @0x187148 mov r0, r7 */
/* @0x18714c add r1, pc, r1 */
/* @0x187150 bl 0xb6574 <strcmp@plt> */
/* @0x187154 cmp r0, #0 */
/* @0x187158 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x18715c mov r0, r7 */
/* @0x187160 ldr r1, [sp] */
/* @0x187164 bl 0xb6574 <strcmp@plt> */
/* @0x187168 cmp r0, #0 */
/* @0x18716c beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187170 mov r0, r7 */
/* @0x187174 ldr r1, [sp, #0x4] */
/* @0x187178 bl 0xb6574 <strcmp@plt> */
/* @0x18717c cmp r0, #0 */
/* @0x187180 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187184 mov r0, r7 */
/* @0x187188 ldr r1, [sp, #0x8] */
/* @0x18718c bl 0xb6574 <strcmp@plt> */
/* @0x187190 cmp r0, #0 */
/* @0x187194 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187198 mov r0, r7 */
/* @0x18719c ldr r1, [sp, #0xc] */
/* @0x1871a0 bl 0xb6574 <strcmp@plt> */
/* @0x1871a4 cmp r0, #0 */
/* @0x1871a8 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x1871ac mov r0, r7 */
/* @0x1871b0 ldr r1, [sp, #0x10] */
/* @0x1871b4 bl 0xb6574 <strcmp@plt> */
/* @0x1871b8 cmp r0, #0 */
/* @0x1871bc beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x1871c0 mov r0, r7 */
/* @0x1871c4 ldr r1, [sp, #0x14] */
/* @0x1871c8 bl 0xb6574 <strcmp@plt> */
/* @0x1871cc cmp r0, #0 */
/* @0x1871d0 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x1871d4 ldr r1, [pc, #0x23c] */
/* @0x1871d8 mov r0, r7 */
/* @0x1871dc add r1, pc, r1 */
/* @0x1871e0 bl 0xb6574 <strcmp@plt> */
/* @0x1871e4 cmp r0, #0 */
/* @0x1871e8 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x1871ec ldr r1, [pc, #0x228] */
/* @0x1871f0 mov r0, r7 */
/* @0x1871f4 add r1, pc, r1 */
/* @0x1871f8 bl 0xb6574 <strcmp@plt> */
/* @0x1871fc cmp r0, #0 */
/* @0x187200 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187204 ldr r1, [pc, #0x214] */
/* @0x187208 mov r0, r7 */
/* @0x18720c add r1, pc, r1 */
/* @0x187210 bl 0xb6574 <strcmp@plt> */
/* @0x187214 cmp r0, #0 */
/* @0x187218 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x18721c ldr r1, [pc, #0x200] */
/* @0x187220 mov r0, r7 */
/* @0x187224 add r1, pc, r1 */
/* @0x187228 bl 0xb6574 <strcmp@plt> */
/* @0x18722c cmp r0, #0 */
/* @0x187230 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187234 ldr r1, [pc, #0x1ec] */
/* @0x187238 mov r0, r7 */
/* @0x18723c add r1, pc, r1 */
/* @0x187240 bl 0xb6574 <strcmp@plt> */
/* @0x187244 cmp r0, #0 */
/* @0x187248 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x18724c ldr r1, [pc, #0x1d8] */
/* @0x187250 mov r0, r7 */
/* @0x187254 add r1, pc, r1 */
/* @0x187258 bl 0xb6574 <strcmp@plt> */
/* @0x18725c cmp r0, #0 */
/* @0x187260 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187264 ldr r1, [pc, #0x1c4] */
/* @0x187268 mov r0, r7 */
/* @0x18726c add r1, pc, r1 */
/* @0x187270 bl 0xb6574 <strcmp@plt> */
/* @0x187274 cmp r0, #0 */
/* @0x187278 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x18727c ldr r1, [pc, #0x1b0] */
/* @0x187280 mov r0, r7 */
/* @0x187284 add r1, pc, r1 */
/* @0x187288 bl 0xb6574 <strcmp@plt> */
/* @0x18728c cmp r0, #0 */
/* @0x187290 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187294 ldr r1, [pc, #0x19c] */
/* @0x187298 mov r0, r7 */
/* @0x18729c add r1, pc, r1 */
/* @0x1872a0 bl 0xb6574 <strcmp@plt> */
/* @0x1872a4 cmp r0, #0 */
/* @0x1872a8 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x1872ac ldr r1, [pc, #0x188] */
/* @0x1872b0 mov r0, r7 */
/* @0x1872b4 add r1, pc, r1 */
/* @0x1872b8 bl 0xb6574 <strcmp@plt> */
/* @0x1872bc cmp r0, #0 */
/* @0x1872c0 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x1872c4 ldr r1, [pc, #0x174] */
/* @0x1872c8 mov r0, r7 */
/* @0x1872cc add r1, pc, r1 */
/* @0x1872d0 bl 0xb6574 <strcmp@plt> */
/* @0x1872d4 cmp r0, #0 */
/* @0x1872d8 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x1872dc ldr r1, [pc, #0x160] */
/* @0x1872e0 mov r0, r7 */
/* @0x1872e4 add r1, pc, r1 */
/* @0x1872e8 bl 0xb6574 <strcmp@plt> */
/* @0x1872ec cmp r0, #0 */
/* @0x1872f0 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x1872f4 ldr r1, [pc, #0x14c] */
/* @0x1872f8 mov r0, r7 */
/* @0x1872fc add r1, pc, r1 */
/* @0x187300 bl 0xb6574 <strcmp@plt> */
/* @0x187304 cmp r0, #0 */
/* @0x187308 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x18730c ldr r1, [pc, #0x138] */
/* @0x187310 mov r0, r7 */
/* @0x187314 add r1, pc, r1 */
/* @0x187318 bl 0xb6574 <strcmp@plt> */
/* @0x18731c cmp r0, #0 */
/* @0x187320 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187324 ldr r1, [pc, #0x124] */
/* @0x187328 mov r0, r7 */
/* @0x18732c add r1, pc, r1 */
/* @0x187330 bl 0xb6574 <strcmp@plt> */
/* @0x187334 cmp r0, #0 */
/* @0x187338 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x18733c ldr r1, [pc, #0x110] */
/* @0x187340 mov r0, r7 */
/* @0x187344 add r1, pc, r1 */
/* @0x187348 bl 0xb6574 <strcmp@plt> */
/* @0x18734c cmp r0, #0 */
/* @0x187350 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187354 ldr r1, [pc, #0xfc] */
/* @0x187358 mov r0, r7 */
/* @0x18735c add r1, pc, r1 */
/* @0x187360 bl 0xb6574 <strcmp@plt> */
/* @0x187364 cmp r0, #0 */
/* @0x187368 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x18736c ldr r1, [pc, #0xe8] */
/* @0x187370 mov r0, r7 */
/* @0x187374 add r1, pc, r1 */
/* @0x187378 bl 0xb6574 <strcmp@plt> */
/* @0x18737c cmp r0, #0 */
/* @0x187380 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c> */
/* @0x187384 ldr r1, [pc, #0xd4] */
/* @0x187388 mov r0, r7 */
/* @0x18738c add r1, pc, r1 */
/* @0x187390 bl 0xb6574 <strcmp@plt> */
/* @0x187394 cmp r0, #0 */
/* @0x187398 beq 0x1873bc <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x510> */
/* @0x18739c ldr r1, [pc, #0xc0] */
/* @0x1873a0 mov r0, r7 */
/* @0x1873a4 add r1, pc, r1 */
/* @0x1873a8 bl 0xb6574 <strcmp@plt> */
/* @0x1873ac cmp r0, #0 */
/* @0x1873b0 moveq r3, #3 */
/* @0x1873b4 moveq r1, r3 */
/* @0x1873b8 beq 0x187020 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x174> */
/* @0x1873bc mov r3, #4 */
/* @0x1873c0 mov r1, r3 */
/* @0x1873c4 b 0x187020 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x174> */
/* @0x1873c8 andseq r4, r12, r0, asr #27 */
/* @0x1873cc andseq r4, r12, r4, asr #27 */
/* @0x1873d0 eoreq r6, r6, r8, asr #17 */
/* @0x1873d4 ldrheq r4, [r12], -r8 */
/* @0x1873d8 ldrheq r4, [r12], -r12 */
/* @0x1873dc ldrheq r4, [r12], -r8 */
/* @0x1873e0 ldrheq r4, [r12], -r12 */
/* @0x1873e4 ldrheq r4, [r12], -r12 */
/* @0x1873e8 andseq r4, r12, r0, lsr #25 */
/* @0x1873ec mulseq r12, r4, r12 */
/* @0x1873f0 andseq r4, r12, r8, lsl #25 */
/* @0x1873f4 andseq r4, r12, r12, ror r12 */
/* @0x1873f8 andseq r4, r12, r12, ror #23 */
/* @0x1873fc andseq r4, r12, r0, ror #23 */
/* @0x187400 ldrsbeq r4, [r12], -r4 */
/* @0x187404 andseq r4, r12, r8, asr #23 */
/* @0x187408 ldrheq r4, [r12], -r12 */
/* @0x18740c ldrheq r4, [r12], -r0 */
/* @0x187410 andseq r4, r12, r4, lsr #23 */
/* @0x187414 mulseq r12, r8, r11 */
/* @0x187418 andseq r4, r12, r12, asr r11 */
/* @0x18741c andseq r4, r12, r0, asr r11 */
/* @0x187420 andseq r4, r12, r4, asr #22 */
/* @0x187424 andseq r4, r12, r8, lsr r11 */
/* @0x187428 andseq r4, r12, r12, lsr #22 */
/* @0x18742c andseq r4, r12, r0, lsr #22 */
/* @0x187430 andseq r4, r12, r4, lsl r11 */
/* @0x187434 andseq r4, r12, r8, lsl #22 */
/* @0x187438 ldrsheq r4, [r12], -r12 */
/* @0x18743c ldrsheq r4, [r12], -r0 */
/* @0x187440 andseq r4, r12, r4, ror #21 */
/* @0x187444 ldrsbeq r4, [r12], -r8 */
/* @0x187448 andseq r4, r12, r12, asr #21 */
/* @0x18744c andseq r4, r12, r0, asr #21 */
/* @0x187450 ldrheq r4, [r12], -r4 */
/* @0x187454 andseq r4, r12, r8, lsr #21 */
/* @0x187458 mulseq r12, r12, r10 */
/* @0x18745c mulseq r12, r0, r10 */
/* @0x187460 andseq r4, r12, r4, lsl #21 */
/* @0x187464 andseq r4, r12, r12, ror r10 */

/* ── FUNC 0x187468 · Shader_Build(GLSLShader*, char**, bool*, int, char**) · size=1136 · insn=284 */
/* @0x187468 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18746c subs r4, r0, #0 */
/* @0x187470 ldr r7, [pc, #0x3e8] */
/* @0x187474 sub sp, sp, #12 */
/* @0x187478 mov r8, r1 */
/* @0x18747c mov r6, r2 */
/* @0x187480 mov r9, r3 */
/* @0x187484 add r7, pc, r7 */
/* @0x187488 beq 0x187600 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x198> */
/* @0x18748c movw r0, #0x8b31 */
/* @0x187490 ldr r1, [r4, #0xc] */
/* @0x187494 mov r2, r8 */
/* @0x187498 bl 0x1865bc <_Z10LoadShaderjPKcPPc> */
/* @0x18749c cmp r0, #0 */
/* @0x1874a0 str r0, [r4] */
/* @0x1874a4 bne 0x1874c4 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x5c> */
/* @0x1874a8 cmp r6, #0 */
/* @0x1874ac beq 0x187600 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x198> */
/* @0x1874b0 mov r5, r0 */
/* @0x1874b4 strb r0, [r6] */
/* @0x1874b8 mov r0, r5 */
/* @0x1874bc add sp, sp, #12 */
/* @0x1874c0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1874c4 movw r0, #0x8b30 */
/* @0x1874c8 ldr r1, [r4, #0x10] */
/* @0x1874cc mov r2, r8 */
/* @0x1874d0 bl 0x1865bc <_Z10LoadShaderjPKcPPc> */
/* @0x1874d4 cmp r0, #0 */
/* @0x1874d8 str r0, [r4, #0x4] */
/* @0x1874dc beq 0x187610 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x1a8> */
/* @0x1874e0 ldr r3, [pc, #0x37c] */
/* @0x1874e4 ldr r3, [r7, r3] */
/* @0x1874e8 ldr r3, [r3] */
/* @0x1874ec blx r3 */
/* @0x1874f0 cmp r0, #0 */
/* @0x1874f4 mov r5, r0 */
/* @0x1874f8 str r0, [r4, #0x8] */
/* @0x1874fc beq 0x187630 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x1c8> */
/* @0x187500 ldr r3, [pc, #0x360] */
/* @0x187504 ldr r1, [r4] */
/* @0x187508 ldr r5, [r7, r3] */
/* @0x18750c ldr r3, [r5] */
/* @0x187510 blx r3 */
/* @0x187514 ldr r3, [r5] */
/* @0x187518 ldr r1, [r4, #0x4] */
/* @0x18751c ldr r0, [r4, #0x8] */
/* @0x187520 blx r3 */
/* @0x187524 ldr r3, [pc, #0x340] */
/* @0x187528 ldr r0, [r4, #0x8] */
/* @0x18752c ldr r3, [r7, r3] */
/* @0x187530 ldr r3, [r3] */
/* @0x187534 blx r3 */
/* @0x187538 ldr r3, [pc, #0x330] */
/* @0x18753c add r2, sp, #8 */
/* @0x187540 mov r1, #0 */
/* @0x187544 ldr r0, [r4, #0x8] */
/* @0x187548 str r1, [r2, #-0x8]! */
/* @0x18754c movw r1, #0x8b82 */
/* @0x187550 ldr r5, [r7, r3] */
/* @0x187554 mov r2, sp */
/* @0x187558 ldr r3, [r5] */
/* @0x18755c blx r3 */
/* @0x187560 ldr r3, [sp] */
/* @0x187564 cmp r3, #0 */
/* @0x187568 bne 0x187650 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x1e8> */
/* @0x18756c add r2, sp, #8 */
/* @0x187570 ldr r12, [r5] */
/* @0x187574 movw r1, #0x8b84 */
/* @0x187578 ldr r0, [r4, #0x8] */
/* @0x18757c str r3, [r2, #-0x4]! */
/* @0x187580 blx r12 */
/* @0x187584 ldr r0, [sp, #0x4] */
/* @0x187588 cmp r0, #1 */
/* @0x18758c movle r0, #1024 */
/* @0x187590 strle r0, [sp, #0x4] */
/* @0x187594 bl 0xb6544 <malloc@plt> */
/* @0x187598 ldr r12, [pc, #0x2d4] */
/* @0x18759c mov r2, #0 */
/* @0x1875a0 ldr r1, [sp, #0x4] */
/* @0x1875a4 ldr r12, [r7, r12] */
/* @0x1875a8 ldr r12, [r12] */
/* @0x1875ac mov r5, r0 */
/* @0x1875b0 mov r3, r0 */
/* @0x1875b4 ldr r0, [r4, #0x8] */
/* @0x1875b8 blx r12 */
/* @0x1875bc ldr r3, [pc, #0x2b4] */
/* @0x1875c0 ldr r1, [pc, #0x2b4] */
/* @0x1875c4 mov r2, r5 */
/* @0x1875c8 ldr r3, [r7, r3] */
/* @0x1875cc add r1, pc, r1 */
/* @0x1875d0 ldr r0, [r3] */
/* @0x1875d4 ldr r3, [r0] */
/* @0x1875d8 ldr r3, [r3, #0xc] */
/* @0x1875dc blx r3 */
/* @0x1875e0 mov r0, r8 */
/* @0x1875e4 mov r1, r5 */
/* @0x1875e8 bl 0x186544 <_Z16SetupErrorStringPPcS_> */
/* @0x1875ec mov r0, r5 */
/* @0x1875f0 bl 0xb655c <free@plt> */
/* @0x1875f4 cmp r6, #0 */
/* @0x1875f8 movne r3, #0 */
/* @0x1875fc strbne r3, [r6] */
/* @0x187600 mov r5, #0 */
/* @0x187604 mov r0, r5 */
/* @0x187608 add sp, sp, #12 */
/* @0x18760c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x187610 cmp r6, #0 */
/* @0x187614 beq 0x187600 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x198> */
/* @0x187618 mov r5, r0 */
/* @0x18761c mov r3, #1 */
/* @0x187620 mov r0, r5 */
/* @0x187624 strb r3, [r6] */
/* @0x187628 add sp, sp, #12 */
/* @0x18762c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x187630 ldr r1, [pc, #0x248] */
/* @0x187634 mov r0, r8 */
/* @0x187638 add r1, pc, r1 */
/* @0x18763c bl 0x186544 <_Z16SetupErrorStringPPcS_> */
/* @0x187640 cmp r6, #0 */
/* @0x187644 strbne r5, [r6] */
/* @0x187648 bne 0x1874b8 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x50> */
/* @0x18764c b 0x187600 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x198> */
/* @0x187650 ldr r3, [pc, #0x22c] */
/* @0x187654 ldr r1, [pc, #0x22c] */
/* @0x187658 ldr r0, [r4, #0x8] */
/* @0x18765c ldr r5, [r7, r3] */
/* @0x187660 add r1, pc, r1 */
/* @0x187664 ldr r3, [r5] */
/* @0x187668 blx r3 */
/* @0x18766c ldr r1, [pc, #0x218] */
/* @0x187670 ldr r3, [r5] */
/* @0x187674 add r1, pc, r1 */
/* @0x187678 str r0, [r4, #0x1c] */
/* @0x18767c ldr r0, [r4, #0x8] */
/* @0x187680 blx r3 */
/* @0x187684 ldr r1, [pc, #0x204] */
/* @0x187688 ldr r3, [r5] */
/* @0x18768c add r1, pc, r1 */
/* @0x187690 str r0, [r4, #0x20] */
/* @0x187694 ldr r0, [r4, #0x8] */
/* @0x187698 blx r3 */
/* @0x18769c ldr r1, [pc, #0x1f0] */
/* @0x1876a0 ldr r3, [r5] */
/* @0x1876a4 add r1, pc, r1 */
/* @0x1876a8 str r0, [r4, #0x24] */
/* @0x1876ac ldr r0, [r4, #0x8] */
/* @0x1876b0 blx r3 */
/* @0x1876b4 ldr r3, [pc, #0x1dc] */
/* @0x1876b8 ldr r1, [pc, #0x1dc] */
/* @0x1876bc add r1, pc, r1 */
/* @0x1876c0 str r0, [r4, #0x28] */
/* @0x1876c4 ldr r5, [r7, r3] */
/* @0x1876c8 ldr r0, [r4, #0x8] */
/* @0x1876cc ldr r3, [r5] */
/* @0x1876d0 blx r3 */
/* @0x1876d4 ldr r1, [pc, #0x1c4] */
/* @0x1876d8 ldr r3, [r5] */
/* @0x1876dc add r1, pc, r1 */
/* @0x1876e0 str r0, [r4, #0x3c] */
/* @0x1876e4 ldr r0, [r4, #0x8] */
/* @0x1876e8 blx r3 */
/* @0x1876ec ldr r1, [pc, #0x1b0] */
/* @0x1876f0 ldr r3, [r5] */
/* @0x1876f4 add r1, pc, r1 */
/* @0x1876f8 str r0, [r4, #0x40] */
/* @0x1876fc ldr r0, [r4, #0x8] */
/* @0x187700 blx r3 */
/* @0x187704 ldr r1, [pc, #0x19c] */
/* @0x187708 ldr r3, [r5] */
/* @0x18770c add r1, pc, r1 */
/* @0x187710 str r0, [r4, #0x44] */
/* @0x187714 ldr r0, [r4, #0x8] */
/* @0x187718 blx r3 */
/* @0x18771c ldr r1, [pc, #0x188] */
/* @0x187720 ldr r3, [r5] */
/* @0x187724 add r1, pc, r1 */
/* @0x187728 str r0, [r4, #0x48] */
/* @0x18772c ldr r0, [r4, #0x8] */
/* @0x187730 blx r3 */
/* @0x187734 ldr r1, [pc, #0x174] */
/* @0x187738 ldr r3, [r5] */
/* @0x18773c add r1, pc, r1 */
/* @0x187740 str r0, [r4, #0x4c] */
/* @0x187744 ldr r0, [r4, #0x8] */
/* @0x187748 blx r3 */
/* @0x18774c ldr r1, [pc, #0x160] */
/* @0x187750 ldr r3, [r5] */
/* @0x187754 add r1, pc, r1 */
/* @0x187758 str r0, [r4, #0x50] */
/* @0x18775c ldr r0, [r4, #0x8] */
/* @0x187760 blx r3 */
/* @0x187764 ldr r1, [pc, #0x14c] */
/* @0x187768 ldr r3, [r5] */
/* @0x18776c add r1, pc, r1 */
/* @0x187770 str r0, [r4, #0x54] */
/* @0x187774 ldr r0, [r4, #0x8] */
/* @0x187778 blx r3 */
/* @0x18777c ldr r1, [pc, #0x138] */
/* @0x187780 ldr r3, [r5] */
/* @0x187784 add r1, pc, r1 */
/* @0x187788 str r0, [r4, #0x58] */
/* @0x18778c ldr r0, [r4, #0x8] */
/* @0x187790 blx r3 */
/* @0x187794 ldr r1, [pc, #0x124] */
/* @0x187798 ldr r3, [r5] */
/* @0x18779c add r1, pc, r1 */
/* @0x1877a0 str r0, [r4, #0x5c] */
/* @0x1877a4 ldr r0, [r4, #0x8] */
/* @0x1877a8 blx r3 */
/* @0x1877ac ldr r1, [pc, #0x110] */
/* @0x1877b0 ldr r3, [r5] */
/* @0x1877b4 add r1, pc, r1 */
/* @0x1877b8 str r0, [r4, #0x60] */
/* @0x1877bc ldr r0, [r4, #0x8] */
/* @0x1877c0 blx r3 */
/* @0x1877c4 ldr r1, [pc, #0xfc] */
/* @0x1877c8 ldr r3, [r5] */
/* @0x1877cc add r1, pc, r1 */
/* @0x1877d0 str r0, [r4, #0x64] */
/* @0x1877d4 ldr r0, [r4, #0x8] */
/* @0x1877d8 blx r3 */
/* @0x1877dc ldr r1, [pc, #0xe8] */
/* @0x1877e0 ldr r3, [r5] */
/* @0x1877e4 add r1, pc, r1 */
/* @0x1877e8 str r0, [r4, #0x68] */
/* @0x1877ec ldr r0, [r4, #0x8] */
/* @0x1877f0 blx r3 */
/* @0x1877f4 ldr r1, [pc, #0xd4] */
/* @0x1877f8 ldr r3, [r5] */
/* @0x1877fc add r1, pc, r1 */
/* @0x187800 str r0, [r4, #0x6c] */
/* @0x187804 ldr r0, [r4, #0x8] */
/* @0x187808 blx r3 */
/* @0x18780c ldr r1, [pc, #0xc0] */
/* @0x187810 ldr r3, [r5] */
/* @0x187814 add r1, pc, r1 */
/* @0x187818 str r0, [r4, #0x70] */
/* @0x18781c ldr r0, [r4, #0x8] */
/* @0x187820 blx r3 */
/* @0x187824 str r0, [r4, #0x74] */
/* @0x187828 mov r0, r4 */
/* @0x18782c bl 0x186834 <_Z18InitialiseUniformsP10GLSLShader> */
/* @0x187830 ldr r3, [sp, #0x28] */
/* @0x187834 cmp r3, #0 */
/* @0x187838 cmpne r9, #0 */
/* @0x18783c movle r5, #0 */
/* @0x187840 movgt r5, #1 */
/* @0x187844 movle r5, #1 */
/* @0x187848 ble 0x1874b8 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x50> */
/* @0x18784c mov r0, r4 */
/* @0x187850 mov r1, r9 */
/* @0x187854 mov r2, r3 */
/* @0x187858 bl 0x186eac <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc> */
/* @0x18785c b 0x1874b8 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x50> */
/* @0x187860 eoreq r10, r6, r12, asr #15 */
/* @0x187864 .word 0xffffbba8 */
/* @0x187868 .word 0xffffbbac */
/* @0x18786c .word 0xffffbbb0 */
/* @0x187870 .word 0xffffbbb4 */
/* @0x187874 .word 0xffffbbb8 */
/* @0x187878 .word 0xffffbac4 */
/* @0x18787c andseq r4, r12, r0, asr #19 */
/* @0x187880 ldrsheq r4, [r12], -r4 */
/* @0x187884 .word 0xffffbbbc */
/* @0x187888 ldrsheq r4, [r12], -r4 */
/* @0x18788c andseq r4, r12, r12, lsr #15 */
/* @0x187890 andseq r4, r12, r4, lsl #15 */
/* @0x187894 ldrheq r4, [r12], -r12 */
/* @0x187898 .word 0xffffbbc0 */
/* @0x18789c mulseq r12, r4, r7 */
/* @0x1878a0 andseq r4, r12, r8, ror #10 */
/* @0x1878a4 andseq r4, r12, r8, ror #14 */
/* @0x1878a8 andseq r4, r12, r4, ror #14 */
/* @0x1878ac andseq r4, r12, r0, ror #14 */
/* @0x1878b0 andseq r4, r12, r4, asr r7 */
/* @0x1878b4 andseq r4, r12, r12, asr #14 */
/* @0x1878b8 andseq r4, r12, r8, asr #14 */
/* @0x1878bc andseq r4, r12, r0, asr #14 */
/* @0x1878c0 andseq r4, r12, r12, lsr r7 */
/* @0x1878c4 andseq r4, r12, r8, lsr r7 */
/* @0x1878c8 andseq r4, r12, r8, lsr r7 */
/* @0x1878cc andseq r4, r12, r12, lsr r7 */
/* @0x1878d0 andseq r4, r12, r8, asr #14 */
/* @0x1878d4 andseq r4, r12, r4, asr r7 */

/* ── FUNC 0x1878d8 · Shader_Setup(char*, char*, char**, bool*, int, char**) · size=676 · insn=169 */
/* @0x1878d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1878dc cmp r1, #0 */
/* @0x1878e0 cmpne r0, #0 */
/* @0x1878e4 ldr r8, [pc, #0x280] */
/* @0x1878e8 mov r7, r0 */
/* @0x1878ec sub sp, sp, #12 */
/* @0x1878f0 mov r6, r1 */
/* @0x1878f4 add r8, pc, r8 */
/* @0x1878f8 movne r5, #0 */
/* @0x1878fc moveq r5, #1 */
/* @0x187900 mov r10, r2 */
/* @0x187904 mov r9, r3 */
/* @0x187908 moveq r0, #0 */
/* @0x18790c beq 0x187b64 <_Z12Shader_SetupPcS_PS_PbiS0_+0x28c> */
/* @0x187910 mov r0, #128 */
/* @0x187914 ldr r11, [pc, #0x254] */
/* @0x187918 bl 0x27c524 <_Znwj> */
/* @0x18791c mvn r12, #0 */
/* @0x187920 add r11, pc, r11 */
/* @0x187924 mov r4, r0 */
/* @0x187928 str r5, [r0] */
/* @0x18792c str r5, [r0, #0x4] */
/* @0x187930 mov r0, r7 */
/* @0x187934 str r12, [r4, #0x1c] */
/* @0x187938 str r12, [r4, #0x20] */
/* @0x18793c str r12, [r4, #0x24] */
/* @0x187940 str r12, [r4, #0x28] */
/* @0x187944 str r12, [r4, #0x40] */
/* @0x187948 str r5, [r4, #0x8] */
/* @0x18794c str r5, [r4, #0xc] */
/* @0x187950 str r5, [r4, #0x10] */
/* @0x187954 str r5, [r4, #0x14] */
/* @0x187958 str r5, [r4, #0x18] */
/* @0x18795c str r5, [r4, #0x2c] */
/* @0x187960 str r5, [r4, #0x30] */
/* @0x187964 str r5, [r4, #0x34] */
/* @0x187968 str r5, [r4, #0x38] */
/* @0x18796c str r5, [r4, #0x78] */
/* @0x187970 str r5, [r4, #0x7c] */
/* @0x187974 mov r5, r11 */
/* @0x187978 bl 0xb6538 <strlen@plt> */
/* @0x18797c mov r3, #1 */
/* @0x187980 mov r1, r11 */
/* @0x187984 mov r2, #70 */
/* @0x187988 add r0, r0, r3 */
/* @0x18798c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x187990 mov r11, r0 */
/* @0x187994 mov r0, r7 */
/* @0x187998 str r11, [r4, #0xc] */
/* @0x18799c bl 0xb6538 <strlen@plt> */
/* @0x1879a0 mov r1, r7 */
/* @0x1879a4 add r2, r0, #1 */
/* @0x1879a8 mov r0, r11 */
/* @0x1879ac bl 0xb65bc <memcpy@plt> */
/* @0x1879b0 mov r0, r6 */
/* @0x1879b4 bl 0xb6538 <strlen@plt> */
/* @0x1879b8 mov r3, #1 */
/* @0x1879bc mov r1, r5 */
/* @0x1879c0 mov r2, #70 */
/* @0x1879c4 add r0, r0, r3 */
/* @0x1879c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1879cc mov r5, r0 */
/* @0x1879d0 mov r0, r6 */
/* @0x1879d4 str r5, [r4, #0x10] */
/* @0x1879d8 bl 0xb6538 <strlen@plt> */
/* @0x1879dc mov r1, r6 */
/* @0x1879e0 add r2, r0, #1 */
/* @0x1879e4 mov r0, r5 */
/* @0x1879e8 bl 0xb65bc <memcpy@plt> */
/* @0x1879ec ldr r3, [sp, #0x34] */
/* @0x1879f0 mov r1, r10 */
/* @0x1879f4 mov r2, r9 */
/* @0x1879f8 mov r0, r4 */
/* @0x1879fc str r3, [sp] */
/* @0x187a00 ldr r3, [sp, #0x30] */
/* @0x187a04 bl 0x187468 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_> */
/* @0x187a08 cmp r0, #0 */
/* @0x187a0c movne r0, r4 */
/* @0x187a10 bne 0x187b64 <_Z12Shader_SetupPcS_PS_PbiS0_+0x28c> */
/* @0x187a14 ldr r0, [r4, #0x8] */
/* @0x187a18 cmn r0, #1 */
/* @0x187a1c beq 0x187a30 <_Z12Shader_SetupPcS_PS_PbiS0_+0x158> */
/* @0x187a20 ldr r3, [pc, #0x14c] */
/* @0x187a24 ldr r3, [r8, r3] */
/* @0x187a28 ldr r3, [r3] */
/* @0x187a2c blx r3 */
/* @0x187a30 ldr r0, [r4] */
/* @0x187a34 cmn r0, #1 */
/* @0x187a38 beq 0x187a4c <_Z12Shader_SetupPcS_PS_PbiS0_+0x174> */
/* @0x187a3c ldr r3, [pc, #0x134] */
/* @0x187a40 ldr r3, [r8, r3] */
/* @0x187a44 ldr r3, [r3] */
/* @0x187a48 blx r3 */
/* @0x187a4c ldr r0, [r4, #0x4] */
/* @0x187a50 cmn r0, #1 */
/* @0x187a54 beq 0x187a68 <_Z12Shader_SetupPcS_PS_PbiS0_+0x190> */
/* @0x187a58 ldr r3, [pc, #0x118] */
/* @0x187a5c ldr r3, [r8, r3] */
/* @0x187a60 ldr r3, [r3] */
/* @0x187a64 blx r3 */
/* @0x187a68 ldr r0, [r4, #0xc] */
/* @0x187a6c cmp r0, #0 */
/* @0x187a70 beq 0x187a78 <_Z12Shader_SetupPcS_PS_PbiS0_+0x1a0> */
/* @0x187a74 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x187a78 ldr r0, [r4, #0x10] */
/* @0x187a7c cmp r0, #0 */
/* @0x187a80 beq 0x187a88 <_Z12Shader_SetupPcS_PS_PbiS0_+0x1b0> */
/* @0x187a84 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x187a88 ldr r0, [r4, #0x14] */
/* @0x187a8c cmp r0, #0 */
/* @0x187a90 beq 0x187acc <_Z12Shader_SetupPcS_PS_PbiS0_+0x1f4> */
/* @0x187a94 ldr r5, [r0, #-0x4] */
/* @0x187a98 add r5, r5, r5, lsl #1 */
/* @0x187a9c add r5, r0, r5, lsl #2 */
/* @0x187aa0 cmp r0, r5 */
/* @0x187aa4 beq 0x187abc <_Z12Shader_SetupPcS_PS_PbiS0_+0x1e4> */
/* @0x187aa8 ldr r0, [r5, #-0xc]! */
/* @0x187aac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x187ab0 ldr r0, [r4, #0x14] */
/* @0x187ab4 cmp r0, r5 */
/* @0x187ab8 bne 0x187aa8 <_Z12Shader_SetupPcS_PS_PbiS0_+0x1d0> */
/* @0x187abc sub r0, r0, #8 */
/* @0x187ac0 bl 0x27d1d4 <_ZdaPv> */
/* @0x187ac4 mov r3, #0 */
/* @0x187ac8 str r3, [r4, #0x14] */
/* @0x187acc ldr r0, [r4, #0x2c] */
/* @0x187ad0 cmp r0, #0 */
/* @0x187ad4 beq 0x187ae4 <_Z12Shader_SetupPcS_PS_PbiS0_+0x20c> */
/* @0x187ad8 bl 0x27d1d4 <_ZdaPv> */
/* @0x187adc mov r3, #0 */
/* @0x187ae0 str r3, [r4, #0x2c] */
/* @0x187ae4 ldr r0, [r4, #0x34] */
/* @0x187ae8 cmp r0, #0 */
/* @0x187aec beq 0x187afc <_Z12Shader_SetupPcS_PS_PbiS0_+0x224> */
/* @0x187af0 bl 0x27d1d4 <_ZdaPv> */
/* @0x187af4 mov r3, #0 */
/* @0x187af8 str r3, [r4, #0x34] */
/* @0x187afc ldr r0, [r4, #0x38] */
/* @0x187b00 cmp r0, #0 */
/* @0x187b04 beq 0x187b14 <_Z12Shader_SetupPcS_PS_PbiS0_+0x23c> */
/* @0x187b08 bl 0x27d1d4 <_ZdaPv> */
/* @0x187b0c mov r3, #0 */
/* @0x187b10 str r3, [r4, #0x38] */
/* @0x187b14 ldr r0, [r4, #0x78] */
/* @0x187b18 cmp r0, #0 */
/* @0x187b1c beq 0x187b58 <_Z12Shader_SetupPcS_PS_PbiS0_+0x280> */
/* @0x187b20 ldr r5, [r0, #-0x4] */
/* @0x187b24 rsb r5, r5, r5, lsl #3 */
/* @0x187b28 add r5, r0, r5, lsl #2 */
/* @0x187b2c cmp r0, r5 */
/* @0x187b30 beq 0x187b48 <_Z12Shader_SetupPcS_PS_PbiS0_+0x270> */
/* @0x187b34 ldr r0, [r5, #-0x1c]! */
/* @0x187b38 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x187b3c ldr r0, [r4, #0x78] */
/* @0x187b40 cmp r0, r5 */
/* @0x187b44 bne 0x187b34 <_Z12Shader_SetupPcS_PS_PbiS0_+0x25c> */
/* @0x187b48 sub r0, r0, #8 */
/* @0x187b4c bl 0x27d1d4 <_ZdaPv> */
/* @0x187b50 mov r3, #0 */
/* @0x187b54 str r3, [r4, #0x78] */
/* @0x187b58 mov r0, r4 */
/* @0x187b5c bl 0x27d1d0 <_ZdlPv> */
/* @0x187b60 mov r0, #0 */
/* @0x187b64 add sp, sp, #12 */
/* @0x187b68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x187b6c eoreq r10, r6, r12, asr r3 */
/* @0x187b70 andseq r9, r10, r0, lsl r7 */
/* @0x187b74 .word 0xffffbb78 */
/* @0x187b78 .word 0xffffbb7c */

/* ── FUNC 0x187b7c · Shader_Add(char*, char*, char**, bool*, int, char**) · size=124 · insn=31 */
/* @0x187b7c push {r4, r5, lr} */
/* @0x187b80 sub sp, sp, #12 */
/* @0x187b84 ldr lr, [sp, #0x18] */
/* @0x187b88 ldr r12, [sp, #0x1c] */
/* @0x187b8c str lr, [sp] */
/* @0x187b90 str r12, [sp, #0x4] */
/* @0x187b94 bl 0x1878d8 <_Z12Shader_SetupPcS_PS_PbiS0_> */
/* @0x187b98 subs r5, r0, #0 */
/* @0x187b9c beq 0x187be8 <_Z10Shader_AddPcS_PS_PbiS0_+0x6c> */
/* @0x187ba0 ldr r4, [pc, #0x48] */
/* @0x187ba4 movw r3, #0x2a9 */
/* @0x187ba8 ldr r2, [pc, #0x44] */
/* @0x187bac ldr r4, [pc, r4] */
/* @0x187bb0 add r2, pc, r2 */
/* @0x187bb4 ldr r1, [r4] */
/* @0x187bb8 mov r0, r4 */
/* @0x187bbc add r1, r1, #1 */
/* @0x187bc0 str r1, [r0], #4 */
/* @0x187bc4 lsl r1, r1, #2 */
/* @0x187bc8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x187bcc ldr r3, [r4] */
/* @0x187bd0 ldr r2, [r4, #0x4] */
/* @0x187bd4 sub r1, r3, #-1073741823 */
/* @0x187bd8 sub r0, r3, #1 */
/* @0x187bdc str r5, [r2, r1, lsl #2] */
/* @0x187be0 add sp, sp, #12 */
/* @0x187be4 pop {r4, r5, pc} */
/* @0x187be8 mvn r0, #0 */
/* @0x187bec b 0x187be0 <_Z10Shader_AddPcS_PS_PbiS0_+0x64> */
/* @0x187bf0 eoreq r8, r6, r12, lsl #20 */
/* @0x187bf4 ldrsheq r4, [r12], -r8 */

/* ── FUNC 0x187bf8 · LoadFile(char*, int&) · size=76 · insn=19 */
/* @0x187bf8 push {r3, r4, r5, lr} */
/* @0x187bfc mov r3, #0 */
/* @0x187c00 str r3, [r1] */
/* @0x187c04 mov r5, r0 */
/* @0x187c08 mov r4, r1 */
/* @0x187c0c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x187c10 cmp r0, #0 */
/* @0x187c14 mov r0, r5 */
/* @0x187c18 bne 0x187c38 <_Z8LoadFilePcRi+0x40> */
/* @0x187c1c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x187c20 cmp r0, #0 */
/* @0x187c24 popeq {r3, r4, r5, pc} */
/* @0x187c28 mov r0, r5 */
/* @0x187c2c mov r1, r4 */
/* @0x187c30 pop {r3, r4, r5, lr} */
/* @0x187c34 b 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x187c38 mov r1, r4 */
/* @0x187c3c pop {r3, r4, r5, lr} */
/* @0x187c40 b 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */

/* ── FUNC 0x187c44 · Shader_Load(char*, char*) · size=556 · insn=139 */
/* @0x187c44 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x187c48 cmp r1, #0 */
/* @0x187c4c cmpne r0, #0 */
/* @0x187c50 ldr r10, [pc, #0x1fc] */
/* @0x187c54 sub sp, sp, #28 */
/* @0x187c58 mov r8, r1 */
/* @0x187c5c movne r4, #0 */
/* @0x187c60 moveq r4, #1 */
/* @0x187c64 add r10, pc, r10 */
/* @0x187c68 beq 0x187e48 <_Z11Shader_LoadPcS_+0x204> */
/* @0x187c6c add r1, sp, #16 */
/* @0x187c70 bl 0x187bf8 <_Z8LoadFilePcRi> */
/* @0x187c74 subs r9, r0, #0 */
/* @0x187c78 beq 0x187e48 <_Z11Shader_LoadPcS_+0x204> */
/* @0x187c7c ldr r3, [pc, #0x1d4] */
/* @0x187c80 ldr r2, [pc, #0x1d4] */
/* @0x187c84 ldr r11, [pc, #0x1d4] */
/* @0x187c88 add r2, pc, r2 */
/* @0x187c8c str r2, [sp, #0xc] */
/* @0x187c90 ldr r6, [r10, r3] */
/* @0x187c94 add r11, pc, r11 */
/* @0x187c98 mov r0, r6 */
/* @0x187c9c bl 0xb6538 <strlen@plt> */
/* @0x187ca0 ldr r3, [pc, #0x1bc] */
/* @0x187ca4 ldr r5, [r10, r3] */
/* @0x187ca8 mov r7, r0 */
/* @0x187cac mov r0, r5 */
/* @0x187cb0 bl 0xb6538 <strlen@plt> */
/* @0x187cb4 ldr lr, [sp, #0x10] */
/* @0x187cb8 mov r1, r11 */
/* @0x187cbc mov r2, #70 */
/* @0x187cc0 add lr, lr, #1 */
/* @0x187cc4 mov r3, #1 */
/* @0x187cc8 add r7, lr, r7 */
/* @0x187ccc add r0, r7, r0 */
/* @0x187cd0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x187cd4 mov r2, r6 */
/* @0x187cd8 ldr r1, [sp, #0xc] */
/* @0x187cdc mov r3, r5 */
/* @0x187ce0 mov r7, r0 */
/* @0x187ce4 bl 0xb6550 <sprintf@plt> */
/* @0x187ce8 mov r0, r6 */
/* @0x187cec bl 0xb6538 <strlen@plt> */
/* @0x187cf0 mov r3, r0 */
/* @0x187cf4 mov r0, r5 */
/* @0x187cf8 str r3, [sp, #0x8] */
/* @0x187cfc bl 0xb6538 <strlen@plt> */
/* @0x187d00 ldr r3, [sp, #0x8] */
/* @0x187d04 mov r1, r9 */
/* @0x187d08 ldr r2, [sp, #0x10] */
/* @0x187d0c add r0, r0, r3 */
/* @0x187d10 add r0, r7, r0 */
/* @0x187d14 bl 0xb65bc <memcpy@plt> */
/* @0x187d18 mov r0, r6 */
/* @0x187d1c bl 0xb6538 <strlen@plt> */
/* @0x187d20 mov r6, r0 */
/* @0x187d24 mov r0, r5 */
/* @0x187d28 bl 0xb6538 <strlen@plt> */
/* @0x187d2c add r6, r7, r6 */
/* @0x187d30 ldr r3, [sp, #0x10] */
/* @0x187d34 add r6, r6, r0 */
/* @0x187d38 mov r0, r9 */
/* @0x187d3c strb r4, [r6, r3] */
/* @0x187d40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x187d44 mov r0, r8 */
/* @0x187d48 add r1, sp, #20 */
/* @0x187d4c bl 0x187bf8 <_Z8LoadFilePcRi> */
/* @0x187d50 subs r8, r0, #0 */
/* @0x187d54 beq 0x187e40 <_Z11Shader_LoadPcS_+0x1fc> */
/* @0x187d58 ldr r3, [pc, #0x108] */
/* @0x187d5c ldr r6, [r10, r3] */
/* @0x187d60 mov r0, r6 */
/* @0x187d64 bl 0xb6538 <strlen@plt> */
/* @0x187d68 ldr r3, [pc, #0xfc] */
/* @0x187d6c ldr r9, [r10, r3] */
/* @0x187d70 mov r5, r0 */
/* @0x187d74 mov r0, r9 */
/* @0x187d78 bl 0xb6538 <strlen@plt> */
/* @0x187d7c ldr r12, [sp, #0x14] */
/* @0x187d80 mov r1, r11 */
/* @0x187d84 mov r2, #70 */
/* @0x187d88 add r12, r12, #1 */
/* @0x187d8c mov r3, #1 */
/* @0x187d90 add r5, r12, r5 */
/* @0x187d94 add r0, r5, r0 */
/* @0x187d98 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x187d9c mov r3, r9 */
/* @0x187da0 ldr r1, [sp, #0xc] */
/* @0x187da4 mov r2, r6 */
/* @0x187da8 mov r5, r0 */
/* @0x187dac bl 0xb6550 <sprintf@plt> */
/* @0x187db0 mov r0, r6 */
/* @0x187db4 bl 0xb6538 <strlen@plt> */
/* @0x187db8 mov r10, r0 */
/* @0x187dbc mov r0, r9 */
/* @0x187dc0 bl 0xb6538 <strlen@plt> */
/* @0x187dc4 mov r1, r8 */
/* @0x187dc8 ldr r2, [sp, #0x14] */
/* @0x187dcc add r0, r0, r10 */
/* @0x187dd0 add r0, r5, r0 */
/* @0x187dd4 bl 0xb65bc <memcpy@plt> */
/* @0x187dd8 mov r0, r6 */
/* @0x187ddc bl 0xb6538 <strlen@plt> */
/* @0x187de0 mov r6, r0 */
/* @0x187de4 mov r0, r9 */
/* @0x187de8 bl 0xb6538 <strlen@plt> */
/* @0x187dec add r6, r5, r6 */
/* @0x187df0 ldr r3, [sp, #0x14] */
/* @0x187df4 add r6, r6, r0 */
/* @0x187df8 mov r0, r8 */
/* @0x187dfc strb r4, [r6, r3] */
/* @0x187e00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x187e04 mov r2, r4 */
/* @0x187e08 mov r3, r4 */
/* @0x187e0c mov r1, r5 */
/* @0x187e10 str r4, [sp] */
/* @0x187e14 mov r0, r7 */
/* @0x187e18 str r4, [sp, #0x4] */
/* @0x187e1c bl 0x187b7c <_Z10Shader_AddPcS_PS_PbiS0_> */
/* @0x187e20 mov r4, r0 */
/* @0x187e24 mov r0, r7 */
/* @0x187e28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x187e2c mov r0, r5 */
/* @0x187e30 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x187e34 mov r0, r4 */
/* @0x187e38 add sp, sp, #28 */
/* @0x187e3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x187e40 mov r0, r7 */
/* @0x187e44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x187e48 mvn r0, #0 */
/* @0x187e4c add sp, sp, #28 */
/* @0x187e50 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x187e54 eoreq r9, r6, r12, ror #31 */
/* @0x187e58 .word 0xffffe910 */
/* @0x187e5c andseq r12, r10, r12, asr #30 */
/* @0x187e60 mulseq r10, r12, r3 */
/* @0x187e64 .word 0xffffe914 */
/* @0x187e68 .word 0xffffe918 */
/* @0x187e6c .word 0xffffe91c */

/* ── FUNC 0x187e70 · Shader_Get(int) · size=52 · insn=13 */
/* @0x187e70 cmp r0, #0 */
/* @0x187e74 blt 0x187e98 <_Z10Shader_Geti+0x28> */
/* @0x187e78 ldr r3, [pc, #0x20] */
/* @0x187e7c ldr r3, [pc, r3] */
/* @0x187e80 ldr r2, [r3] */
/* @0x187e84 cmp r0, r2 */
/* @0x187e88 bge 0x187e98 <_Z10Shader_Geti+0x28> */
/* @0x187e8c ldr r3, [r3, #0x4] */
/* @0x187e90 ldr r0, [r3, r0, lsl #2] */
/* @0x187e94 bx lr */
/* @0x187e98 mov r0, #0 */
/* @0x187e9c bx lr */
/* @0x187ea0 eoreq r8, r6, r12, lsr r7 */

/* ── FUNC 0x187ea4 · Shader_Reload(int) · size=48 · insn=12 */
/* @0x187ea4 str lr, [sp, #-0x4]! */
/* @0x187ea8 sub sp, sp, #12 */
/* @0x187eac bl 0x187e70 <_Z10Shader_Geti> */
/* @0x187eb0 cmp r0, #0 */
/* @0x187eb4 beq 0x187ecc <_Z13Shader_Reloadi+0x28> */
/* @0x187eb8 mov r1, #0 */
/* @0x187ebc str r1, [sp] */
/* @0x187ec0 mov r2, r1 */
/* @0x187ec4 mov r3, r1 */
/* @0x187ec8 bl 0x187468 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_> */
/* @0x187ecc add sp, sp, #12 */
/* @0x187ed0 ldr pc, [sp], #4 */

/* ── FUNC 0x187ed4 · Shader_Flush_All() · size=212 · insn=53 */
/* @0x187ed4 push {r4, r5, r6, r7, r8, lr} */
/* @0x187ed8 mov r0, #0 */
/* @0x187edc ldr r8, [pc, #0xb0] */
/* @0x187ee0 ldr r3, [pc, #0xb0] */
/* @0x187ee4 add r8, pc, r8 */
/* @0x187ee8 ldr r3, [r8, r3] */
/* @0x187eec ldr r3, [r3] */
/* @0x187ef0 blx r3 */
/* @0x187ef4 ldr r3, [pc, #0xa0] */
/* @0x187ef8 ldr r6, [r8, r3] */
/* @0x187efc ldr r3, [r6] */
/* @0x187f00 cmp r3, #0 */
/* @0x187f04 pople {r4, r5, r6, r7, r8, pc} */
/* @0x187f08 mov r5, #0 */
/* @0x187f0c mvn r7, #0 */
/* @0x187f10 ldr r3, [r6, #0x4] */
/* @0x187f14 ldr r4, [r3, r5, lsl #2] */
/* @0x187f18 add r5, r5, #1 */
/* @0x187f1c cmp r4, #0 */
/* @0x187f20 beq 0x187f84 <_Z16Shader_Flush_Allv+0xb0> */
/* @0x187f24 ldr r0, [r4, #0x8] */
/* @0x187f28 ldr r3, [pc, #0x70] */
/* @0x187f2c cmn r0, #1 */
/* @0x187f30 beq 0x187f44 <_Z16Shader_Flush_Allv+0x70> */
/* @0x187f34 ldr r3, [r8, r3] */
/* @0x187f38 ldr r3, [r3] */
/* @0x187f3c blx r3 */
/* @0x187f40 str r7, [r4, #0x8] */
/* @0x187f44 ldr r0, [r4] */
/* @0x187f48 ldr r3, [pc, #0x54] */
/* @0x187f4c cmn r0, #1 */
/* @0x187f50 beq 0x187f64 <_Z16Shader_Flush_Allv+0x90> */
/* @0x187f54 ldr r3, [r8, r3] */
/* @0x187f58 ldr r3, [r3] */
/* @0x187f5c blx r3 */
/* @0x187f60 str r7, [r4] */
/* @0x187f64 ldr r0, [r4, #0x4] */
/* @0x187f68 ldr r3, [pc, #0x34] */
/* @0x187f6c cmn r0, #1 */
/* @0x187f70 beq 0x187f84 <_Z16Shader_Flush_Allv+0xb0> */
/* @0x187f74 ldr r3, [r8, r3] */
/* @0x187f78 ldr r3, [r3] */
/* @0x187f7c blx r3 */
/* @0x187f80 str r7, [r4, #0x4] */
/* @0x187f84 ldr r3, [r6] */
/* @0x187f88 cmp r3, r5 */
/* @0x187f8c bgt 0x187f10 <_Z16Shader_Flush_Allv+0x3c> */
/* @0x187f90 pop {r4, r5, r6, r7, r8, pc} */
/* @0x187f94 eoreq r9, r6, r12, ror #26 */
/* @0x187f98 .word 0xffffbb80 */
/* @0x187f9c .word 0xffffe968 */
/* @0x187fa0 .word 0xffffbb78 */
/* @0x187fa4 .word 0xffffbb7c */

/* ── FUNC 0x187fa8 · FreeShaderManagerResources() · size=4 · insn=1 */
/* @0x187fa8 b 0x187ed4 <_Z16Shader_Flush_Allv> */

/* ── FUNC 0x187fac · Shader_Reload_All() · size=176 · insn=44 */
/* @0x187fac push {r3, r4, r5, lr} */
/* @0x187fb0 ldr r5, [pc, #0x98] */
/* @0x187fb4 ldr r5, [pc, r5] */
/* @0x187fb8 ldr r3, [r5] */
/* @0x187fbc cmp r3, #0 */
/* @0x187fc0 movgt r4, #0 */
/* @0x187fc4 bgt 0x187fdc <_Z17Shader_Reload_Allv+0x30> */
/* @0x187fc8 b 0x188010 <_Z17Shader_Reload_Allv+0x64> */
/* @0x187fcc ldr r3, [r5] */
/* @0x187fd0 add r4, r4, #1 */
/* @0x187fd4 cmp r3, r4 */
/* @0x187fd8 ble 0x188010 <_Z17Shader_Reload_Allv+0x64> */
/* @0x187fdc ldr r3, [r5, #0x4] */
/* @0x187fe0 ldr r3, [r3, r4, lsl #2] */
/* @0x187fe4 cmp r3, #0 */
/* @0x187fe8 beq 0x187fcc <_Z17Shader_Reload_Allv+0x20> */
/* @0x187fec ldr r3, [r3, #0x8] */
/* @0x187ff0 cmn r3, #1 */
/* @0x187ff4 bne 0x187fcc <_Z17Shader_Reload_Allv+0x20> */
/* @0x187ff8 mov r0, r4 */
/* @0x187ffc add r4, r4, #1 */
/* @0x188000 bl 0x187ea4 <_Z13Shader_Reloadi> */
/* @0x188004 ldr r3, [r5] */
/* @0x188008 cmp r3, r4 */
/* @0x18800c bgt 0x187fdc <_Z17Shader_Reload_Allv+0x30> */
/* @0x188010 ldr r4, [pc, #0x3c] */
/* @0x188014 ldr r4, [pc, r4] */
/* @0x188018 ldr r0, [r4] */
/* @0x18801c cmn r0, #1 */
/* @0x188020 popeq {r3, r4, r5, pc} */
/* @0x188024 bl 0x187e70 <_Z10Shader_Geti> */
/* @0x188028 cmp r0, #0 */
/* @0x18802c mvneq r3, #0 */
/* @0x188030 streq r3, [r4] */
/* @0x188034 popeq {r3, r4, r5, pc} */
/* @0x188038 ldr r3, [pc, #0x18] */
/* @0x18803c ldr r0, [r0, #0x8] */
/* @0x188040 ldr r3, [pc, r3] */
/* @0x188044 ldr r3, [r3] */
/* @0x188048 blx r3 */
/* @0x18804c pop {r3, r4, r5, pc} */
/* @0x188050 eoreq r8, r6, r4, lsl #12 */
/* @0x188054 eoreq r8, r6, r12, ror r5 */
/* @0x188058 mlaeq r6, r0, r7, r5 */

/* ── FUNC 0x18805c · Shader_Commit() · size=144 · insn=36 */
/* @0x18805c push {r4, r5, r6, lr} */
/* @0x188060 ldr r4, [pc, #0x70] */
/* @0x188064 ldr r3, [pc, #0x70] */
/* @0x188068 add r4, pc, r4 */
/* @0x18806c ldr r5, [r4, r3] */
/* @0x188070 ldrb r3, [r5] */
/* @0x188074 cmp r3, #0 */
/* @0x188078 popeq {r4, r5, r6, pc} */
/* @0x18807c ldr r3, [pc, #0x5c] */
/* @0x188080 ldr r6, [r4, r3] */
/* @0x188084 ldr r0, [r6] */
/* @0x188088 bl 0x187e70 <_Z10Shader_Geti> */
/* @0x18808c cmp r0, #0 */
/* @0x188090 beq 0x1880c4 <_Z13Shader_Commitv+0x68> */
/* @0x188094 ldr r2, [pc, #0x48] */
/* @0x188098 ldr r1, [r6] */
/* @0x18809c ldr r3, [pc, #0x44] */
/* @0x1880a0 ldr r2, [r4, r2] */
/* @0x1880a4 ldr r0, [r0, #0x8] */
/* @0x1880a8 str r1, [r2] */
/* @0x1880ac ldr r3, [r4, r3] */
/* @0x1880b0 ldr r3, [r3] */
/* @0x1880b4 blx r3 */
/* @0x1880b8 mov r3, #0 */
/* @0x1880bc strb r3, [r5] */
/* @0x1880c0 pop {r4, r5, r6, pc} */
/* @0x1880c4 ldr r3, [pc, #0x18] */
/* @0x1880c8 mvn r2, #0 */
/* @0x1880cc ldr r3, [r4, r3] */
/* @0x1880d0 str r2, [r3] */
/* @0x1880d4 b 0x1880b8 <_Z13Shader_Commitv+0x5c> */
/* @0x1880d8 eoreq r9, r6, r8, ror #23 */
/* @0x1880dc .word 0xffffe964 */
/* @0x1880e0 .word 0xffffe96c */
/* @0x1880e4 .word 0xffffe940 */
/* @0x1880e8 .word 0xffffbb80 */

/* ── FUNC 0x1880ec · Shader_SetM(int) · size=88 · insn=22 */
/* @0x1880ec ldr r3, [pc, #0x40] */
/* @0x1880f0 ldr r2, [pc, #0x40] */
/* @0x1880f4 add r3, pc, r3 */
/* @0x1880f8 ldr r2, [r3, r2] */
/* @0x1880fc ldr r1, [r2] */
/* @0x188100 cmp r1, r0 */
/* @0x188104 bxeq lr */
/* @0x188108 ldr r1, [pc, #0x2c] */
/* @0x18810c ldr r12, [pc, #0x2c] */
/* @0x188110 ldr r1, [r3, r1] */
/* @0x188114 ldr r3, [r3, r12] */
/* @0x188118 str r0, [r2] */
/* @0x18811c ldr r1, [r1] */
/* @0x188120 cmp r1, r0 */
/* @0x188124 moveq r1, #0 */
/* @0x188128 movne r1, #1 */
/* @0x18812c strb r1, [r3] */
/* @0x188130 bx lr */
/* @0x188134 eoreq r9, r6, r12, asr r11 */
/* @0x188138 .word 0xffffe96c */
/* @0x18813c .word 0xffffe940 */
/* @0x188140 .word 0xffffe964 */

/* ── FUNC 0x188144 · InitShaderManagerResources() · size=32 · insn=8 */
/* @0x188144 push {r3, lr} */
/* @0x188148 bl 0x187fac <_Z17Shader_Reload_Allv> */
/* @0x18814c ldr r3, [pc, #0xc] */
/* @0x188150 ldr r3, [pc, r3] */
/* @0x188154 ldr r0, [r3] */
/* @0x188158 pop {r3, lr} */
/* @0x18815c b 0x1880ec <_Z11Shader_SetMi> */
/* @0x188160 eoreq r8, r6, r0, asr #8 */

/* ── FUNC 0x188164 · Shader_Set_Uniform_F(int, int, int, float*) · size=156 · insn=39 */
/* @0x188164 push {r4, r5, r6, r7, r8, lr} */
/* @0x188168 cmn r0, #1 */
/* @0x18816c ldr r4, [pc, #0x78] */
/* @0x188170 mov r5, r0 */
/* @0x188174 mov r7, r1 */
/* @0x188178 mov r8, r2 */
/* @0x18817c mov r6, r3 */
/* @0x188180 add r4, pc, r4 */
/* @0x188184 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x188188 cmp r3, #0 */
/* @0x18818c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x188190 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x188194 sub r3, r7, #1 */
/* @0x188198 cmp r3, #3 */
/* @0x18819c addls pc, pc, r3, lsl #2 */
/* @0x1881a0 b 0x1881d0 <_Z20Shader_Set_Uniform_FiiiPf+0x6c> */
/* @0x1881a4 b 0x1881d4 <_Z20Shader_Set_Uniform_FiiiPf+0x70> */
/* @0x1881a8 b 0x1881dc <_Z20Shader_Set_Uniform_FiiiPf+0x78> */
/* @0x1881ac b 0x1881e4 <_Z20Shader_Set_Uniform_FiiiPf+0x80> */
/* @0x1881b0 b 0x1881b4 <_Z20Shader_Set_Uniform_FiiiPf+0x50> */
/* @0x1881b4 ldr r3, [pc, #0x34] */
/* @0x1881b8 ldr r3, [r4, r3] */
/* @0x1881bc mov r0, r5 */
/* @0x1881c0 mov r1, r8 */
/* @0x1881c4 mov r2, r6 */
/* @0x1881c8 ldr r3, [r3] */
/* @0x1881cc blx r3 */
/* @0x1881d0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1881d4 ldr r3, [pc, #0x18] */
/* @0x1881d8 b 0x1881b8 <_Z20Shader_Set_Uniform_FiiiPf+0x54> */
/* @0x1881dc ldr r3, [pc, #0x14] */
/* @0x1881e0 b 0x1881b8 <_Z20Shader_Set_Uniform_FiiiPf+0x54> */
/* @0x1881e4 ldr r3, [pc, #0x10] */
/* @0x1881e8 b 0x1881b8 <_Z20Shader_Set_Uniform_FiiiPf+0x54> */
/* @0x1881ec .word 0x00269ad0 */
/* @0x1881f0 .word 0xffffbbd0 */
/* @0x1881f4 .word 0xffffbbc4 */
/* @0x1881f8 .word 0xffffbbc8 */
/* @0x1881fc .word 0xffffbbcc */

/* ── FUNC 0x188200 · Shader_Set_Uniform_I(int, int, int, int*) · size=156 · insn=39 */
/* @0x188200 push {r4, r5, r6, r7, r8, lr} */
/* @0x188204 cmn r0, #1 */
/* @0x188208 ldr r4, [pc, #0x78] */
/* @0x18820c mov r5, r0 */
/* @0x188210 mov r7, r1 */
/* @0x188214 mov r8, r2 */
/* @0x188218 mov r6, r3 */
/* @0x18821c add r4, pc, r4 */
/* @0x188220 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x188224 cmp r3, #0 */
/* @0x188228 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x18822c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x188230 sub r3, r7, #1 */
/* @0x188234 cmp r3, #3 */
/* @0x188238 addls pc, pc, r3, lsl #2 */
/* @0x18823c b 0x18826c <_Z20Shader_Set_Uniform_IiiiPi+0x6c> */
/* @0x188240 b 0x188270 <_Z20Shader_Set_Uniform_IiiiPi+0x70> */
/* @0x188244 b 0x188278 <_Z20Shader_Set_Uniform_IiiiPi+0x78> */
/* @0x188248 b 0x188280 <_Z20Shader_Set_Uniform_IiiiPi+0x80> */
/* @0x18824c b 0x188250 <_Z20Shader_Set_Uniform_IiiiPi+0x50> */
/* @0x188250 ldr r3, [pc, #0x34] */
/* @0x188254 ldr r3, [r4, r3] */
/* @0x188258 mov r0, r5 */
/* @0x18825c mov r1, r8 */
/* @0x188260 mov r2, r6 */
/* @0x188264 ldr r3, [r3] */
/* @0x188268 blx r3 */
/* @0x18826c pop {r4, r5, r6, r7, r8, pc} */
/* @0x188270 ldr r3, [pc, #0x18] */
/* @0x188274 b 0x188254 <_Z20Shader_Set_Uniform_IiiiPi+0x54> */
/* @0x188278 ldr r3, [pc, #0x14] */
/* @0x18827c b 0x188254 <_Z20Shader_Set_Uniform_IiiiPi+0x54> */
/* @0x188280 ldr r3, [pc, #0x10] */
/* @0x188284 b 0x188254 <_Z20Shader_Set_Uniform_IiiiPi+0x54> */
/* @0x188288 eoreq r9, r6, r4, lsr r10 */
/* @0x18828c .word 0xffffbbe0 */
/* @0x188290 .word 0xffffbbd4 */
/* @0x188294 .word 0xffffbbd8 */
/* @0x188298 .word 0xffffbbdc */

/* ── FUNC 0x18829c · Shader_Set_Uniform_Matrix(int, int, int, float*) · size=184 · insn=46 */
/* @0x18829c cmn r0, #1 */
/* @0x1882a0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1882a4 mov r4, r0 */
/* @0x1882a8 mov r5, r1 */
/* @0x1882ac mov r7, r2 */
/* @0x1882b0 mov r6, r3 */
/* @0x1882b4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1882b8 cmp r3, #0 */
/* @0x1882bc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1882c0 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1882c4 cmp r5, #3 */
/* @0x1882c8 beq 0x188300 <_Z25Shader_Set_Uniform_MatrixiiiPf+0x64> */
/* @0x1882cc cmp r5, #4 */
/* @0x1882d0 beq 0x188324 <_Z25Shader_Set_Uniform_MatrixiiiPf+0x88> */
/* @0x1882d4 cmp r5, #2 */
/* @0x1882d8 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1882dc ldr r12, [pc, #0x64] */
/* @0x1882e0 mov r0, r4 */
/* @0x1882e4 mov r1, r7 */
/* @0x1882e8 mov r3, r6 */
/* @0x1882ec ldr r12, [pc, r12] */
/* @0x1882f0 mov r2, #0 */
/* @0x1882f4 ldr r12, [r12] */
/* @0x1882f8 blx r12 */
/* @0x1882fc pop {r3, r4, r5, r6, r7, pc} */
/* @0x188300 ldr r12, [pc, #0x44] */
/* @0x188304 mov r0, r4 */
/* @0x188308 mov r1, r7 */
/* @0x18830c mov r3, r6 */
/* @0x188310 ldr r12, [pc, r12] */
/* @0x188314 mov r2, #0 */
/* @0x188318 ldr r12, [r12] */
/* @0x18831c blx r12 */
/* @0x188320 pop {r3, r4, r5, r6, r7, pc} */
/* @0x188324 ldr r12, [pc, #0x24] */
/* @0x188328 mov r0, r4 */
/* @0x18832c mov r1, r7 */
/* @0x188330 mov r3, r6 */
/* @0x188334 ldr r12, [pc, r12] */
/* @0x188338 mov r2, #0 */
/* @0x18833c ldr r12, [r12] */
/* @0x188340 blx r12 */
/* @0x188344 pop {r3, r4, r5, r6, r7, pc} */
/* @0x188348 eoreq r5, r6, r8, asr #10 */
/* @0x18834c eoreq r5, r6, r8, lsr #10 */
/* @0x188350 eoreq r5, r6, r8, lsl #10 */

/* ── FUNC 0x188354 · Shader_Set_Texture(int, void*) · size=72 · insn=18 */
/* @0x188354 cmp r0, #7 */
/* @0x188358 push {r3, r4, r5, lr} */
/* @0x18835c mov r4, r0 */
/* @0x188360 mov r5, r1 */
/* @0x188364 pophi {r3, r4, r5, pc} */
/* @0x188368 cmp r1, #0 */
/* @0x18836c popeq {r3, r4, r5, pc} */
/* @0x188370 ldr r3, [pc, #0x20] */
/* @0x188374 ldr r3, [pc, r3] */
/* @0x188378 ldr r3, [r3, r0, lsl #2] */
/* @0x18837c cmp r3, r1 */
/* @0x188380 popeq {r3, r4, r5, pc} */
/* @0x188384 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x188388 mov r0, r4 */
/* @0x18838c mov r1, r5 */
/* @0x188390 pop {r3, r4, r5, lr} */
/* @0x188394 b 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x188398 eoreq r8, r6, r4, asr #3 */

/* ── FUNC 0x18839c · F_Dummy_Shader_Func(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x18839c mov r2, #0 */
/* @0x1883a0 mov r3, r2 */
/* @0x1883a4 movt r2, #0xbff0 */
/* @0x1883a8 str r3, [r0, #0xc] */
/* @0x1883ac str r2, [r0, #0x4] */
/* @0x1883b0 str r3, [r0] */
/* @0x1883b4 bx lr */

/* ── FUNC 0x1883b8 · Shader_Get_Uniform_Handle(Shader*, char const*) · size=176 · insn=44 */
/* @0x1883b8 push {r3, r4, r5, lr} */
/* @0x1883bc mov r5, r1 */
/* @0x1883c0 ldr r3, [pc, #0x98] */
/* @0x1883c4 ldr r3, [pc, r3] */
/* @0x1883c8 ldr r3, [r3] */
/* @0x1883cc cmp r3, #1 */
/* @0x1883d0 bne 0x188448 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x90> */
/* @0x1883d4 ldr r0, [r0, #0x64] */
/* @0x1883d8 bl 0x187e70 <_Z10Shader_Geti> */
/* @0x1883dc subs r4, r0, #0 */
/* @0x1883e0 beq 0x188448 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x90> */
/* @0x1883e4 ldr r3, [r4, #0x78] */
/* @0x1883e8 cmp r3, #0 */
/* @0x1883ec beq 0x188448 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x90> */
/* @0x1883f0 ldr r3, [pc, #0x6c] */
/* @0x1883f4 mov r1, r5 */
/* @0x1883f8 ldr r0, [r4, #0x8] */
/* @0x1883fc ldr r3, [pc, r3] */
/* @0x188400 ldr r3, [r3] */
/* @0x188404 blx r3 */
/* @0x188408 ldr r12, [r4, #0x7c] */
/* @0x18840c cmp r12, #0 */
/* @0x188410 ble 0x188448 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x90> */
/* @0x188414 ldr r2, [r4, #0x78] */
/* @0x188418 ldr r3, [r2, #0x4] */
/* @0x18841c cmp r3, r0 */
/* @0x188420 beq 0x188458 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0xa0> */
/* @0x188424 mov r3, #0 */
/* @0x188428 b 0x188438 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x80> */
/* @0x18842c ldr r1, [r2, #0x4] */
/* @0x188430 cmp r1, r0 */
/* @0x188434 beq 0x188450 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x98> */
/* @0x188438 add r3, r3, #1 */
/* @0x18843c add r2, r2, #28 */
/* @0x188440 cmp r3, r12 */
/* @0x188444 bne 0x18842c <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x74> */
/* @0x188448 mvn r0, #0 */
/* @0x18844c pop {r3, r4, r5, pc} */
/* @0x188450 mov r0, r3 */
/* @0x188454 pop {r3, r4, r5, pc} */
/* @0x188458 mov r0, #0 */
/* @0x18845c pop {r3, r4, r5, pc} */
/* @0x188460 eoreq r8, r6, r4, asr #32 */
/* @0x188464 eoreq r5, r6, r4, lsl r4 */

/* ── FUNC 0x188468 · Shader_Get_Sampler_Index(Shader*, char const*) · size=140 · insn=35 */
/* @0x188468 push {r3, r4, r5, r6, r7, lr} */
/* @0x18846c mov r7, r1 */
/* @0x188470 ldr r3, [pc, #0x78] */
/* @0x188474 ldr r3, [pc, r3] */
/* @0x188478 ldr r3, [r3] */
/* @0x18847c cmp r3, #1 */
/* @0x188480 bne 0x1884e8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x80> */
/* @0x188484 cmp r0, #0 */
/* @0x188488 beq 0x1884e8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x80> */
/* @0x18848c ldr r0, [r0, #0x64] */
/* @0x188490 bl 0x187e70 <_Z10Shader_Geti> */
/* @0x188494 cmp r0, #0 */
/* @0x188498 beq 0x1884e8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x80> */
/* @0x18849c ldr r4, [r0, #0x14] */
/* @0x1884a0 cmp r4, #0 */
/* @0x1884a4 beq 0x1884e8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x80> */
/* @0x1884a8 ldr r6, [r0, #0x18] */
/* @0x1884ac cmp r6, #0 */
/* @0x1884b0 ble 0x1884e8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x80> */
/* @0x1884b4 mov r5, #0 */
/* @0x1884b8 b 0x1884c8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x60> */
/* @0x1884bc cmp r5, r6 */
/* @0x1884c0 add r4, r4, #12 */
/* @0x1884c4 beq 0x1884e8 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x80> */
/* @0x1884c8 ldr r0, [r4] */
/* @0x1884cc mov r1, r7 */
/* @0x1884d0 bl 0xb6574 <strcmp@plt> */
/* @0x1884d4 add r5, r5, #1 */
/* @0x1884d8 cmp r0, #0 */
/* @0x1884dc bne 0x1884bc <_Z24Shader_Get_Sampler_IndexP6ShaderPKc+0x54> */
/* @0x1884e0 ldr r0, [r4, #0x8] */
/* @0x1884e4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1884e8 mvn r0, #0 */
/* @0x1884ec pop {r3, r4, r5, r6, r7, pc} */
/* @0x1884f0 mlaeq r6, r4, pc, r7 */

/* ── FUNC 0x1884f4 · Shader_Load(Shader*) · size=348 · insn=87 */
/* @0x1884f4 ldr r3, [pc, #0x12c] */
/* @0x1884f8 push {r4, r5, lr} */
/* @0x1884fc ldr r3, [pc, r3] */
/* @0x188500 sub sp, sp, #12 */
/* @0x188504 mov r4, r0 */
/* @0x188508 ldr r5, [r3] */
/* @0x18850c cmp r5, #1 */
/* @0x188510 beq 0x188558 <_Z11Shader_LoadP6Shader+0x64> */
/* @0x188514 cmp r5, #0 */
/* @0x188518 beq 0x18852c <_Z11Shader_LoadP6Shader+0x38> */
/* @0x18851c mov r5, #0 */
/* @0x188520 mov r0, r5 */
/* @0x188524 add sp, sp, #12 */
/* @0x188528 pop {r4, r5, pc} */
/* @0x18852c ldr r3, [pc, #0xf8] */
/* @0x188530 ldr r1, [pc, #0xf8] */
/* @0x188534 ldr r3, [pc, r3] */
/* @0x188538 add r1, pc, r1 */
/* @0x18853c ldr r0, [r3] */
/* @0x188540 ldr r3, [r0] */
/* @0x188544 ldr r3, [r3, #0xc] */
/* @0x188548 blx r3 */
/* @0x18854c mov r0, r5 */
/* @0x188550 add sp, sp, #12 */
/* @0x188554 pop {r4, r5, pc} */
/* @0x188558 cmp r0, #0 */
/* @0x18855c beq 0x18851c <_Z11Shader_LoadP6Shader+0x28> */
/* @0x188560 ldr lr, [r4, #0x5c] */
/* @0x188564 add r2, r4, #84 */
/* @0x188568 ldr r12, [r4, #0x60] */
/* @0x18856c add r3, r4, #88 */
/* @0x188570 ldr r0, [r0, #0xc] */
/* @0x188574 ldr r1, [r4, #0x10] */
/* @0x188578 str lr, [sp] */
/* @0x18857c str r12, [sp, #0x4] */
/* @0x188580 bl 0x187b7c <_Z10Shader_AddPcS_PS_PbiS0_> */
/* @0x188584 cmn r0, #1 */
/* @0x188588 str r0, [r4, #0x64] */
/* @0x18858c beq 0x18851c <_Z11Shader_LoadP6Shader+0x28> */
/* @0x188590 ldr r1, [pc, #0x9c] */
/* @0x188594 mov r0, r4 */
/* @0x188598 add r1, pc, r1 */
/* @0x18859c bl 0x188468 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc> */
/* @0x1885a0 ldr r1, [pc, #0x90] */
/* @0x1885a4 add r1, pc, r1 */
/* @0x1885a8 str r0, [r4, #0x68] */
/* @0x1885ac mov r0, r4 */
/* @0x1885b0 bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc> */
/* @0x1885b4 ldr r1, [pc, #0x80] */
/* @0x1885b8 add r1, pc, r1 */
/* @0x1885bc str r0, [r4, #0x6c] */
/* @0x1885c0 mov r0, r4 */
/* @0x1885c4 bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc> */
/* @0x1885c8 ldr r1, [pc, #0x70] */
/* @0x1885cc add r1, pc, r1 */
/* @0x1885d0 str r0, [r4, #0x70] */
/* @0x1885d4 mov r0, r4 */
/* @0x1885d8 bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc> */
/* @0x1885dc ldr r1, [pc, #0x60] */
/* @0x1885e0 add r1, pc, r1 */
/* @0x1885e4 str r0, [r4, #0x74] */
/* @0x1885e8 mov r0, r4 */
/* @0x1885ec bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc> */
/* @0x1885f0 ldr r1, [pc, #0x50] */
/* @0x1885f4 add r1, pc, r1 */
/* @0x1885f8 str r0, [r4, #0x78] */
/* @0x1885fc mov r0, r4 */
/* @0x188600 bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc> */
/* @0x188604 ldr r1, [pc, #0x40] */
/* @0x188608 add r1, pc, r1 */
/* @0x18860c str r0, [r4, #0x7c] */
/* @0x188610 mov r0, r4 */
/* @0x188614 bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc> */
/* @0x188618 str r0, [r4, #0x80] */
/* @0x18861c mov r0, r5 */
/* @0x188620 add sp, sp, #12 */
/* @0x188624 pop {r4, r5, pc} */
/* @0x188628 eoreq r7, r6, r12, lsl #30 */
/* @0x18862c eoreq r5, r6, r0, ror #3 */
/* @0x188630 andseq r3, r12, r12, lsl #22 */
/* @0x188634 andseq r3, r12, r12, lsr #13 */
/* @0x188638 andseq r3, r12, r12, lsr #17 */
/* @0x18863c andseq r3, r12, r12, lsr r10 */
/* @0x188640 andseq r3, r12, r12, lsr r10 */
/* @0x188644 andseq r3, r12, r12, lsr r10 */
/* @0x188648 andseq r3, r12, r12, lsr r10 */
/* @0x18864c andseq r3, r12, r4, asr r8 */

/* ── FUNC 0x188650 · SetShader(Shader*) · size=48 · insn=12 */
/* @0x188650 ldr r3, [pc, #0x24] */
/* @0x188654 ldr r3, [pc, r3] */
/* @0x188658 ldr r3, [r3] */
/* @0x18865c cmp r3, #1 */
/* @0x188660 bxne lr */
/* @0x188664 cmp r0, #0 */
/* @0x188668 beq 0x188674 <_Z9SetShaderP6Shader+0x24> */
/* @0x18866c ldr r0, [r0, #0x64] */
/* @0x188670 b 0x1880ec <_Z11Shader_SetMi> */
/* @0x188674 mvn r0, #0 */
/* @0x188678 b 0x1880ec <_Z11Shader_SetMi> */
/* @0x18867c .word 0x00267db4 */

/* ── FUNC 0x188680 · Shader_Set_Uniform_I(int, int, double, double, double, double) · size=276 · insn=69 */
/* @0x188680 ldr r12, [pc, #0x104] */
/* @0x188684 push {r4, lr} */
/* @0x188688 vpush {d8} */
/* @0x18868c ldr r12, [pc, r12] */
/* @0x188690 vmov d8, r2, r3 */
/* @0x188694 sub sp, sp, #24 */
/* @0x188698 ldr r3, [r12] */
/* @0x18869c mov r4, r0 */
/* @0x1886a0 cmp r3, #1 */
/* @0x1886a4 beq 0x1886b8 <_Z20Shader_Set_Uniform_Iiidddd+0x38> */
/* @0x1886a8 mov r0, #0 */
/* @0x1886ac add sp, sp, #24 */
/* @0x1886b0 vpop {d8} */
/* @0x1886b4 pop {r4, pc} */
/* @0x1886b8 cmp r0, #0 */
/* @0x1886bc blt 0x1886a8 <_Z20Shader_Set_Uniform_Iiidddd+0x28> */
/* @0x1886c0 ldr r3, [pc, #0xc8] */
/* @0x1886c4 ldr r3, [pc, r3] */
/* @0x1886c8 ldr r3, [r3] */
/* @0x1886cc cmp r3, #0 */
/* @0x1886d0 beq 0x1886a8 <_Z20Shader_Set_Uniform_Iiidddd+0x28> */
/* @0x1886d4 ldr r0, [r3, #0x64] */
/* @0x1886d8 str r1, [sp, #0x4] */
/* @0x1886dc bl 0x187e70 <_Z10Shader_Geti> */
/* @0x1886e0 ldr r1, [sp, #0x4] */
/* @0x1886e4 cmp r0, #0 */
/* @0x1886e8 beq 0x1886a8 <_Z20Shader_Set_Uniform_Iiidddd+0x28> */
/* @0x1886ec ldr r3, [r0, #0x7c] */
/* @0x1886f0 cmp r4, r3 */
/* @0x1886f4 bge 0x1886a8 <_Z20Shader_Set_Uniform_Iiidddd+0x28> */
/* @0x1886f8 ldr r3, [r0, #0x78] */
/* @0x1886fc rsb r4, r4, r4, lsl #3 */
/* @0x188700 adds r4, r3, r4, lsl #2 */
/* @0x188704 beq 0x1886a8 <_Z20Shader_Set_Uniform_Iiidddd+0x28> */
/* @0x188708 vcvt.s32.f64 s16, d8 */
/* @0x18870c ldr r2, [r4, #0xc] */
/* @0x188710 mov r3, #0 */
/* @0x188714 str r3, [sp, #0x14] */
/* @0x188718 cmp r1, r2 */
/* @0x18871c movge r1, r2 */
/* @0x188720 str r3, [sp, #0x10] */
/* @0x188724 cmp r1, #1 */
/* @0x188728 strle r3, [sp, #0xc] */
/* @0x18872c vstr s16, [sp, #8] */
/* @0x188730 ble 0x18876c <_Z20Shader_Set_Uniform_Iiidddd+0xec> */
/* @0x188734 vldr d7, [sp, #40] */
/* @0x188738 vcvt.s32.f64 s15, d7 */
/* @0x18873c cmp r1, #2 */
/* @0x188740 vstr s15, [sp, #12] */
/* @0x188744 beq 0x18876c <_Z20Shader_Set_Uniform_Iiidddd+0xec> */
/* @0x188748 vldr d7, [sp, #48] */
/* @0x18874c vcvt.s32.f64 s15, d7 */
/* @0x188750 cmp r1, #3 */
/* @0x188754 vmov r3, s15 */
/* @0x188758 vstr s15, [sp, #16] */
/* @0x18875c vldrne d7, [sp, #56] */
/* @0x188760 vcvtne.s32.f64 s15, d7 */
/* @0x188764 vmovne r3, s15 */
/* @0x188768 strne r3, [sp, #0x14] */
/* @0x18876c ldr r0, [r4, #0x4] */
/* @0x188770 mov r2, #1 */
/* @0x188774 add r3, sp, #8 */
/* @0x188778 bl 0x188200 <_Z20Shader_Set_Uniform_IiiiPi> */
/* @0x18877c mov r0, #1 */
/* @0x188780 add sp, sp, #24 */
/* @0x188784 vpop {d8} */
/* @0x188788 pop {r4, pc} */
/* @0x18878c eoreq r7, r6, r12, ror sp */
/* @0x188790 .word 0x00267db4 */

/* ── FUNC 0x188794 · Shader_Set_Uniform_IA(int, int, int*) · size=348 · insn=87 */
/* @0x188794 push {r4, r5, r6, r7, r8, r9, r11, lr} */
/* @0x188798 add r11, sp, #28 */
/* @0x18879c ldr r12, [pc, #0x140] */
/* @0x1887a0 sub sp, sp, #8 */
/* @0x1887a4 ldr r4, [pc, #0x13c] */
/* @0x1887a8 ldr r12, [pc, r12] */
/* @0x1887ac mov r6, r0 */
/* @0x1887b0 ldr r4, [pc, r4] */
/* @0x1887b4 mov r7, r1 */
/* @0x1887b8 ldr r5, [r12] */
/* @0x1887bc mov r8, r2 */
/* @0x1887c0 ldr r12, [r4] */
/* @0x1887c4 cmp r5, #1 */
/* @0x1887c8 str r12, [r11, #-0x20] */
/* @0x1887cc beq 0x1887ec <_Z21Shader_Set_Uniform_IAiiPi+0x58> */
/* @0x1887d0 mov r0, #0 */
/* @0x1887d4 ldr r2, [r11, #-0x20] */
/* @0x1887d8 ldr r3, [r4] */
/* @0x1887dc cmp r2, r3 */
/* @0x1887e0 bne 0x1888e0 <_Z21Shader_Set_Uniform_IAiiPi+0x14c> */
/* @0x1887e4 sub sp, r11, #28 */
/* @0x1887e8 pop {r4, r5, r6, r7, r8, r9, r11, pc} */
/* @0x1887ec cmp r0, #0 */
/* @0x1887f0 blt 0x1887d0 <_Z21Shader_Set_Uniform_IAiiPi+0x3c> */
/* @0x1887f4 ldr r12, [pc, #0xf0] */
/* @0x1887f8 ldr r12, [pc, r12] */
/* @0x1887fc ldr r3, [r12] */
/* @0x188800 cmp r3, #0 */
/* @0x188804 beq 0x1887d0 <_Z21Shader_Set_Uniform_IAiiPi+0x3c> */
/* @0x188808 ldr r0, [r3, #0x64] */
/* @0x18880c bl 0x187e70 <_Z10Shader_Geti> */
/* @0x188810 cmp r0, #0 */
/* @0x188814 beq 0x1887d0 <_Z21Shader_Set_Uniform_IAiiPi+0x3c> */
/* @0x188818 ldr r3, [r0, #0x7c] */
/* @0x18881c cmp r6, r3 */
/* @0x188820 bge 0x1887d0 <_Z21Shader_Set_Uniform_IAiiPi+0x3c> */
/* @0x188824 ldr r3, [r0, #0x78] */
/* @0x188828 rsb r6, r6, r6, lsl #3 */
/* @0x18882c adds r6, r3, r6, lsl #2 */
/* @0x188830 beq 0x1887d0 <_Z21Shader_Set_Uniform_IAiiPi+0x3c> */
/* @0x188834 ldr r9, [r6, #0x10] */
/* @0x188838 cmp r9, #1 */
/* @0x18883c ble 0x1888b0 <_Z21Shader_Set_Uniform_IAiiPi+0x11c> */
/* @0x188840 ldr r1, [r6, #0x14] */
/* @0x188844 cmp r1, #0 */
/* @0x188848 beq 0x1888a8 <_Z21Shader_Set_Uniform_IAiiPi+0x114> */
/* @0x18884c mov r0, r7 */
/* @0x188850 bl 0x318d10 <__divsi3> */
/* @0x188854 subs r2, r0, #0 */
/* @0x188858 moveq r0, r5 */
/* @0x18885c beq 0x1887d4 <_Z21Shader_Set_Uniform_IAiiPi+0x40> */
/* @0x188860 lsl lr, r2, #2 */
/* @0x188864 subgt r8, r8, #4 */
/* @0x188868 add r3, lr, #14 */
/* @0x18886c bic r3, r3, #7 */
/* @0x188870 sub sp, sp, r3 */
/* @0x188874 mov r3, sp */
/* @0x188878 movgt r12, sp */
/* @0x18887c addgt lr, lr, r3 */
/* @0x188880 ble 0x18889c <_Z21Shader_Set_Uniform_IAiiPi+0x108> */
/* @0x188884 ldr r1, [r8, #0x4]! */
/* @0x188888 vmov s15, r1 */
/* @0x18888c vcvt.f32.s32 s15, s15 */
/* @0x188890 vstmia r12!, {s15} */
/* @0x188894 cmp r12, lr */
/* @0x188898 bne 0x188884 <_Z21Shader_Set_Uniform_IAiiPi+0xf0> */
/* @0x18889c ldr r0, [r6, #0x4] */
/* @0x1888a0 mov r1, r9 */
/* @0x1888a4 bl 0x18829c <_Z25Shader_Set_Uniform_MatrixiiiPf> */
/* @0x1888a8 mov r0, #1 */
/* @0x1888ac b 0x1887d4 <_Z21Shader_Set_Uniform_IAiiPi+0x40> */
/* @0x1888b0 ldr r9, [r6, #0xc] */
/* @0x1888b4 mov r0, r7 */
/* @0x1888b8 ldr r6, [r6, #0x4] */
/* @0x1888bc mov r1, r9 */
/* @0x1888c0 bl 0x318d10 <__divsi3> */
/* @0x1888c4 mov r1, r9 */
/* @0x1888c8 mov r3, r8 */
/* @0x1888cc mov r2, r0 */
/* @0x1888d0 mov r0, r6 */
/* @0x1888d4 bl 0x188200 <_Z20Shader_Set_Uniform_IiiiPi> */
/* @0x1888d8 mov r0, r5 */
/* @0x1888dc b 0x1887d4 <_Z21Shader_Set_Uniform_IAiiPi+0x40> */
/* @0x1888e0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1888e4 eoreq r7, r6, r0, ror #24 */
/* @0x1888e8 eoreq r5, r6, r0, lsr #3 */
/* @0x1888ec eoreq r7, r6, r0, lsl #25 */

/* ── FUNC 0x1888f0 · Shader_Set_Uniform_F(int, int, double, double, double, double) · size=268 · insn=67 */
/* @0x1888f0 ldr r12, [pc, #0xfc] */
/* @0x1888f4 push {r4, lr} */
/* @0x1888f8 vpush {d8} */
/* @0x1888fc ldr r12, [pc, r12] */
/* @0x188900 vmov d8, r2, r3 */
/* @0x188904 sub sp, sp, #24 */
/* @0x188908 ldr r3, [r12] */
/* @0x18890c mov r4, r0 */
/* @0x188910 cmp r3, #1 */
/* @0x188914 beq 0x188928 <_Z20Shader_Set_Uniform_Fiidddd+0x38> */
/* @0x188918 mov r0, #0 */
/* @0x18891c add sp, sp, #24 */
/* @0x188920 vpop {d8} */
/* @0x188924 pop {r4, pc} */
/* @0x188928 cmp r0, #0 */
/* @0x18892c blt 0x188918 <_Z20Shader_Set_Uniform_Fiidddd+0x28> */
/* @0x188930 ldr r3, [pc, #0xc0] */
/* @0x188934 ldr r3, [pc, r3] */
/* @0x188938 ldr r3, [r3] */
/* @0x18893c cmp r3, #0 */
/* @0x188940 beq 0x188918 <_Z20Shader_Set_Uniform_Fiidddd+0x28> */
/* @0x188944 ldr r0, [r3, #0x64] */
/* @0x188948 str r1, [sp, #0x4] */
/* @0x18894c bl 0x187e70 <_Z10Shader_Geti> */
/* @0x188950 ldr r1, [sp, #0x4] */
/* @0x188954 cmp r0, #0 */
/* @0x188958 beq 0x188918 <_Z20Shader_Set_Uniform_Fiidddd+0x28> */
/* @0x18895c ldr r3, [r0, #0x7c] */
/* @0x188960 cmp r4, r3 */
/* @0x188964 bge 0x188918 <_Z20Shader_Set_Uniform_Fiidddd+0x28> */
/* @0x188968 ldr r3, [r0, #0x78] */
/* @0x18896c rsb r4, r4, r4, lsl #3 */
/* @0x188970 adds r4, r3, r4, lsl #2 */
/* @0x188974 beq 0x188918 <_Z20Shader_Set_Uniform_Fiidddd+0x28> */
/* @0x188978 vcvt.f32.f64 s16, d8 */
/* @0x18897c ldr r2, [r4, #0xc] */
/* @0x188980 mov r3, #0 */
/* @0x188984 str r3, [sp, #0x14] */
/* @0x188988 cmp r1, r2 */
/* @0x18898c movge r1, r2 */
/* @0x188990 str r3, [sp, #0x10] */
/* @0x188994 cmp r1, #1 */
/* @0x188998 strle r3, [sp, #0xc] */
/* @0x18899c vstr s16, [sp, #8] */
/* @0x1889a0 ble 0x1889d4 <_Z20Shader_Set_Uniform_Fiidddd+0xe4> */
/* @0x1889a4 vldr d6, [sp, #40] */
/* @0x1889a8 vcvt.f32.f64 s15, d6 */
/* @0x1889ac cmp r1, #2 */
/* @0x1889b0 vstr s15, [sp, #12] */
/* @0x1889b4 beq 0x1889d4 <_Z20Shader_Set_Uniform_Fiidddd+0xe4> */
/* @0x1889b8 vldr d6, [sp, #48] */
/* @0x1889bc vcvt.f32.f64 s15, d6 */
/* @0x1889c0 cmp r1, #3 */
/* @0x1889c4 vldrne d6, [sp, #56] */
/* @0x1889c8 vstr s15, [sp, #16] */
/* @0x1889cc vcvtne.f32.f64 s15, d6 */
/* @0x1889d0 vstrne s15, [sp, #20] */
/* @0x1889d4 ldr r0, [r4, #0x4] */
/* @0x1889d8 mov r2, #1 */
/* @0x1889dc add r3, sp, #8 */
/* @0x1889e0 bl 0x188164 <_Z20Shader_Set_Uniform_FiiiPf> */
/* @0x1889e4 mov r0, #1 */
/* @0x1889e8 add sp, sp, #24 */
/* @0x1889ec vpop {d8} */
/* @0x1889f0 pop {r4, pc} */
/* @0x1889f4 eoreq r7, r6, r12, lsl #22 */
/* @0x1889f8 eoreq r7, r6, r4, asr #22 */

/* ── FUNC 0x1889fc · Shader_Set_Uniform_Matrix_N(int, int, float*) · size=160 · insn=40 */
/* @0x1889fc ldr r12, [pc, #0x90] */
/* @0x188a00 push {r3, r4, r5, r6, r7, lr} */
/* @0x188a04 ldr r12, [pc, r12] */
/* @0x188a08 mov r5, r0 */
/* @0x188a0c mov r7, r1 */
/* @0x188a10 ldr r4, [r12] */
/* @0x188a14 mov r6, r2 */
/* @0x188a18 cmp r4, #1 */
/* @0x188a1c beq 0x188a28 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x2c> */
/* @0x188a20 mov r0, #0 */
/* @0x188a24 pop {r3, r4, r5, r6, r7, pc} */
/* @0x188a28 cmp r0, #0 */
/* @0x188a2c blt 0x188a20 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x24> */
/* @0x188a30 ldr r0, [pc, #0x60] */
/* @0x188a34 ldr r0, [pc, r0] */
/* @0x188a38 ldr r3, [r0] */
/* @0x188a3c cmp r3, #0 */
/* @0x188a40 beq 0x188a20 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x24> */
/* @0x188a44 ldr r0, [r3, #0x64] */
/* @0x188a48 bl 0x187e70 <_Z10Shader_Geti> */
/* @0x188a4c cmp r0, #0 */
/* @0x188a50 beq 0x188a20 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x24> */
/* @0x188a54 ldr r3, [r0, #0x7c] */
/* @0x188a58 cmp r5, r3 */
/* @0x188a5c bge 0x188a20 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x24> */
/* @0x188a60 ldr r3, [r0, #0x78] */
/* @0x188a64 rsb r5, r5, r5, lsl #3 */
/* @0x188a68 adds r5, r3, r5, lsl #2 */
/* @0x188a6c beq 0x188a20 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x24> */
/* @0x188a70 ldr r1, [r5, #0xc] */
/* @0x188a74 cmp r1, #4 */
/* @0x188a78 bne 0x188a20 <_Z27Shader_Set_Uniform_Matrix_NiiPf+0x24> */
/* @0x188a7c ldr r0, [r5, #0x4] */
/* @0x188a80 mov r2, r7 */
/* @0x188a84 mov r3, r6 */
/* @0x188a88 bl 0x18829c <_Z25Shader_Set_Uniform_MatrixiiiPf> */
/* @0x188a8c mov r0, r4 */
/* @0x188a90 pop {r3, r4, r5, r6, r7, pc} */
/* @0x188a94 eoreq r7, r6, r4, lsl #20 */
/* @0x188a98 eoreq r7, r6, r4, asr #20 */

/* ── FUNC 0x188a9c · Shader_Set_Uniform_FA(int, int, float*) · size=244 · insn=61 */
/* @0x188a9c ldr r12, [pc, #0xe4] */
/* @0x188aa0 push {r4, r5, r6, r7, r8, lr} */
/* @0x188aa4 ldr r12, [pc, r12] */
/* @0x188aa8 mov r5, r0 */
/* @0x188aac mov r6, r1 */
/* @0x188ab0 ldr r4, [r12] */
/* @0x188ab4 mov r7, r2 */
/* @0x188ab8 cmp r4, #1 */
/* @0x188abc beq 0x188ac8 <_Z21Shader_Set_Uniform_FAiiPf+0x2c> */
/* @0x188ac0 mov r0, #0 */
/* @0x188ac4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x188ac8 cmp r0, #0 */
/* @0x188acc blt 0x188ac0 <_Z21Shader_Set_Uniform_FAiiPf+0x24> */
/* @0x188ad0 ldr r12, [pc, #0xb4] */
/* @0x188ad4 ldr r12, [pc, r12] */
/* @0x188ad8 ldr r3, [r12] */
/* @0x188adc cmp r3, #0 */
/* @0x188ae0 beq 0x188ac0 <_Z21Shader_Set_Uniform_FAiiPf+0x24> */
/* @0x188ae4 ldr r0, [r3, #0x64] */
/* @0x188ae8 bl 0x187e70 <_Z10Shader_Geti> */
/* @0x188aec cmp r0, #0 */
/* @0x188af0 beq 0x188ac0 <_Z21Shader_Set_Uniform_FAiiPf+0x24> */
/* @0x188af4 ldr r3, [r0, #0x7c] */
/* @0x188af8 cmp r5, r3 */
/* @0x188afc bge 0x188ac0 <_Z21Shader_Set_Uniform_FAiiPf+0x24> */
/* @0x188b00 ldr r3, [r0, #0x78] */
/* @0x188b04 rsb r5, r5, r5, lsl #3 */
/* @0x188b08 adds r5, r3, r5, lsl #2 */
/* @0x188b0c beq 0x188ac0 <_Z21Shader_Set_Uniform_FAiiPf+0x24> */
/* @0x188b10 ldr r8, [r5, #0x10] */
/* @0x188b14 cmp r8, #1 */
/* @0x188b18 ble 0x188b58 <_Z21Shader_Set_Uniform_FAiiPf+0xbc> */
/* @0x188b1c ldr r1, [r5, #0x14] */
/* @0x188b20 cmp r1, #0 */
/* @0x188b24 beq 0x188b38 <_Z21Shader_Set_Uniform_FAiiPf+0x9c> */
/* @0x188b28 mov r0, r6 */
/* @0x188b2c bl 0x318d10 <__divsi3> */
/* @0x188b30 subs r2, r0, #0 */
/* @0x188b34 bne 0x188b40 <_Z21Shader_Set_Uniform_FAiiPf+0xa4> */
/* @0x188b38 mov r0, r4 */
/* @0x188b3c pop {r4, r5, r6, r7, r8, pc} */
/* @0x188b40 ldr r0, [r5, #0x4] */
/* @0x188b44 mov r1, r8 */
/* @0x188b48 mov r3, r7 */
/* @0x188b4c bl 0x18829c <_Z25Shader_Set_Uniform_MatrixiiiPf> */
/* @0x188b50 mov r0, r4 */
/* @0x188b54 pop {r4, r5, r6, r7, r8, pc} */
/* @0x188b58 ldr r8, [r5, #0xc] */
/* @0x188b5c mov r0, r6 */
/* @0x188b60 ldr r5, [r5, #0x4] */
/* @0x188b64 mov r1, r8 */
/* @0x188b68 bl 0x318d10 <__divsi3> */
/* @0x188b6c mov r1, r8 */
/* @0x188b70 mov r3, r7 */
/* @0x188b74 mov r2, r0 */
/* @0x188b78 mov r0, r5 */
/* @0x188b7c bl 0x188164 <_Z20Shader_Set_Uniform_FiiiPf> */
/* @0x188b80 mov r0, r4 */
/* @0x188b84 pop {r4, r5, r6, r7, r8, pc} */
/* @0x188b88 eoreq r7, r6, r4, ror #18 */
/* @0x188b8c eoreq r7, r6, r4, lsr #19 */
