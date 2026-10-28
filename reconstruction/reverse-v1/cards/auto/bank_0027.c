/* libyoyo.so 覆盖卡组 0027
 * 函数 0xfb588..0xfc864，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xfb588 · F_DsMapSecureLoadBuffer(RValue&, CInstance*, CInstance*, int, RValue*) · size=340 · insn=85 */
/* @0xfb588 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfb58c mov r4, #0 */
/* @0xfb590 ldr r2, [sp, #0x20] */
/* @0xfb594 mov r1, r4 */
/* @0xfb598 str r4, [r0, #0xc] */
/* @0xfb59c mov r6, r0 */
/* @0xfb5a0 str r4, [r0] */
/* @0xfb5a4 mov r3, r4 */
/* @0xfb5a8 movt r3, #0xbff0 */
/* @0xfb5ac str r3, [r0, #0x4] */
/* @0xfb5b0 mov r0, r2 */
/* @0xfb5b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfb5b8 bl 0xc6720 <_Z10GetIBufferi> */
/* @0xfb5bc subs r5, r0, #0 */
/* @0xfb5c0 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfb5c4 ldr r8, [pc, #0x10c] */
/* @0xfb5c8 movw r2, #0x784 */
/* @0xfb5cc mov r3, #1 */
/* @0xfb5d0 mov r0, #81 */
/* @0xfb5d4 add r8, pc, r8 */
/* @0xfb5d8 ldr r9, [r5, #0x10] */
/* @0xfb5dc mov r1, r8 */
/* @0xfb5e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfb5e4 mov r2, #1 */
/* @0xfb5e8 mov r3, #80 */
/* @0xfb5ec mov r7, r0 */
/* @0xfb5f0 mov r0, r5 */
/* @0xfb5f4 mov r1, r7 */
/* @0xfb5f8 bl 0xcdc9c <_ZN7IBuffer4ReadEPKvjj> */
/* @0xfb5fc strb r4, [r7, #0x50] */
/* @0xfb600 mov r0, r7 */
/* @0xfb604 bl 0xfb34c <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0xfb608 cmp r0, r4 */
/* @0xfb60c bne 0xfb61c <_Z23F_DsMapSecureLoadBufferR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0xfb610 mov r0, r7 */
/* @0xfb614 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfb618 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb61c mov r1, r8 */
/* @0xfb620 sub r0, r9, #78 */
/* @0xfb624 movw r2, #0x78d */
/* @0xfb628 mov r3, #1 */
/* @0xfb62c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfb630 sub r10, r9, #79 */
/* @0xfb634 mov r2, #1 */
/* @0xfb638 mov r3, r10 */
/* @0xfb63c mov r9, r0 */
/* @0xfb640 mov r0, r5 */
/* @0xfb644 mov r1, r9 */
/* @0xfb648 bl 0xcdc9c <_ZN7IBuffer4ReadEPKvjj> */
/* @0xfb64c add r3, r10, r10, lsl #1 */
/* @0xfb650 cmp r3, r4 */
/* @0xfb654 add r2, r3, #3 */
/* @0xfb658 strb r4, [r9, r10] */
/* @0xfb65c mov r1, r8 */
/* @0xfb660 movge r4, r3 */
/* @0xfb664 movlt r4, r2 */
/* @0xfb668 asr r4, r4, #2 */
/* @0xfb66c movw r2, #0x792 */
/* @0xfb670 add r4, r4, #4 */
/* @0xfb674 mov r3, #1 */
/* @0xfb678 mov r0, r4 */
/* @0xfb67c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfb680 mov r1, r4 */
/* @0xfb684 mov r3, #1 */
/* @0xfb688 mov r8, r0 */
/* @0xfb68c mov r0, r9 */
/* @0xfb690 mov r2, r8 */
/* @0xfb694 bl 0x1d1ff0 <_Z13base64_decodePKcjPcb> */
/* @0xfb698 mvn r1, #0 */
/* @0xfb69c mov r0, r8 */
/* @0xfb6a0 bl 0x13d5ac <_Z11JSONToDSMapPci> */
/* @0xfb6a4 vmov s15, r0 */
/* @0xfb6a8 mov r0, r8 */
/* @0xfb6ac vcvt.f64.s32 d7, s15 */
/* @0xfb6b0 vmov r4, r5, d7 */
/* @0xfb6b4 vmov r2, s14 */
/* @0xfb6b8 mov r3, r5 */
/* @0xfb6bc stm r6, {r2, r3} */
/* @0xfb6c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb6c4 mov r0, r9 */
/* @0xfb6c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb6cc mov r0, r7 */
/* @0xfb6d0 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfb6d4 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb6d8 eoreq r12, r3, r8, asr #11 */

/* ── FUNC 0xfb6dc · F_DsPriorityCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0xfb6dc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xfb6e0 mov r7, r0 */
/* @0xfb6e4 ldr r3, [pc, #0xe8] */
/* @0xfb6e8 ldr r2, [pc, #0xe8] */
/* @0xfb6ec add r3, pc, r3 */
/* @0xfb6f0 ldr r9, [r3, r2] */
/* @0xfb6f4 ldr r2, [pc, #0xe0] */
/* @0xfb6f8 ldr r5, [r9] */
/* @0xfb6fc ldr r8, [r3, r2] */
/* @0xfb700 cmp r5, #0 */
/* @0xfb704 ble 0xfb73c <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfb708 ldr r3, [r8, #0x4] */
/* @0xfb70c ldr r6, [r3] */
/* @0xfb710 cmp r6, #0 */
/* @0xfb714 beq 0xfb7cc <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0xfb718 mov r4, #0 */
/* @0xfb71c b 0xfb72c <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0xfb720 ldr r2, [r3, #0x4]! */
/* @0xfb724 cmp r2, #0 */
/* @0xfb728 beq 0xfb75c <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfb72c add r4, r4, #1 */
/* @0xfb730 cmp r4, r5 */
/* @0xfb734 lsl r6, r4, #2 */
/* @0xfb738 bne 0xfb720 <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0xfb73c ldr r3, [r8] */
/* @0xfb740 cmp r5, r3 */
/* @0xfb744 movlt r3, r5 */
/* @0xfb748 bge 0xfb790 <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfb74c lsl r6, r5, #2 */
/* @0xfb750 mov r4, r5 */
/* @0xfb754 add r3, r3, #1 */
/* @0xfb758 str r3, [r9] */
/* @0xfb75c mov r0, #24 */
/* @0xfb760 bl 0x27c524 <_Znwj> */
/* @0xfb764 mov r5, r0 */
/* @0xfb768 bl 0x209864 <_ZN12CDS_PriorityC2Ev> */
/* @0xfb76c vmov s15, r4 */
/* @0xfb770 ldr r0, [r8, #0x4] */
/* @0xfb774 mov r1, #0 */
/* @0xfb778 vcvt.f64.s32 d7, s15 */
/* @0xfb77c str r5, [r0, r6] */
/* @0xfb780 str r1, [r7, #0xc] */
/* @0xfb784 vmov r2, r3, d7 */
/* @0xfb788 stm r7, {r2, r3} */
/* @0xfb78c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xfb790 add r1, r5, #16 */
/* @0xfb794 ldr r2, [pc, #0x44] */
/* @0xfb798 movw r3, #0x7cc */
/* @0xfb79c add r0, r8, #4 */
/* @0xfb7a0 add r2, pc, r2 */
/* @0xfb7a4 lsl r1, r1, #2 */
/* @0xfb7a8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xfb7ac ldr r3, [r9] */
/* @0xfb7b0 lsl r6, r5, #2 */
/* @0xfb7b4 mov r4, r5 */
/* @0xfb7b8 add r2, r3, #16 */
/* @0xfb7bc add r3, r3, #1 */
/* @0xfb7c0 str r2, [r8] */
/* @0xfb7c4 str r3, [r9] */
/* @0xfb7c8 b 0xfb75c <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfb7cc mov r4, r6 */
/* @0xfb7d0 b 0xfb75c <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfb7d4 eoreq r6, pc, r4, ror #10 */
/* @0xfb7d8 .word 0xffffc224 */
/* @0xfb7dc .word 0xffffc228 */
/* @0xfb7e0 .word 0x0023c3fc */

/* ── FUNC 0xfb7e4 · F_DsStackDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0xfb7e4 push {r3, r4, r5, lr} */
/* @0xfb7e8 mov r1, #0 */
/* @0xfb7ec ldr r0, [sp, #0x10] */
/* @0xfb7f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfb7f4 subs r4, r0, #0 */
/* @0xfb7f8 blt 0xfb844 <_Z16F_DsStackDestroyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfb7fc ldr r3, [pc, #0x54] */
/* @0xfb800 ldr r3, [pc, r3] */
/* @0xfb804 ldr r3, [r3] */
/* @0xfb808 cmp r4, r3 */
/* @0xfb80c bge 0xfb844 <_Z16F_DsStackDestroyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfb810 ldr r5, [pc, #0x44] */
/* @0xfb814 ldr r5, [pc, r5] */
/* @0xfb818 ldr r3, [r5, #0x4] */
/* @0xfb81c ldr r0, [r3, r4, lsl #2] */
/* @0xfb820 cmp r0, #0 */
/* @0xfb824 beq 0xfb844 <_Z16F_DsStackDestroyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfb828 ldr r3, [r0] */
/* @0xfb82c ldr r3, [r3, #0x4] */
/* @0xfb830 blx r3 */
/* @0xfb834 ldr r3, [r5, #0x4] */
/* @0xfb838 mov r2, #0 */
/* @0xfb83c str r2, [r3, r4, lsl #2] */
/* @0xfb840 pop {r3, r4, r5, pc} */
/* @0xfb844 ldr r0, [pc, #0x14] */
/* @0xfb848 mov r1, #0 */
/* @0xfb84c pop {r3, r4, r5, lr} */
/* @0xfb850 add r0, pc, r0 */
/* @0xfb854 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfb858 eoreq r2, pc, r12, ror r6 */
/* @0xfb85c eoreq r2, pc, r12, ror #12 */
/* @0xfb860 eoreq r12, r3, r12, lsr #7 */

/* ── FUNC 0xfb864 · F_DsQueueDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0xfb864 push {r3, r4, r5, lr} */
/* @0xfb868 mov r1, #0 */
/* @0xfb86c ldr r0, [sp, #0x10] */
/* @0xfb870 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfb874 subs r4, r0, #0 */
/* @0xfb878 blt 0xfb8c4 <_Z16F_DsQueueDestroyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfb87c ldr r3, [pc, #0x54] */
/* @0xfb880 ldr r3, [pc, r3] */
/* @0xfb884 ldr r3, [r3] */
/* @0xfb888 cmp r4, r3 */
/* @0xfb88c bge 0xfb8c4 <_Z16F_DsQueueDestroyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfb890 ldr r5, [pc, #0x44] */
/* @0xfb894 ldr r5, [pc, r5] */
/* @0xfb898 ldr r3, [r5, #0x4] */
/* @0xfb89c ldr r0, [r3, r4, lsl #2] */
/* @0xfb8a0 cmp r0, #0 */
/* @0xfb8a4 beq 0xfb8c4 <_Z16F_DsQueueDestroyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfb8a8 ldr r3, [r0] */
/* @0xfb8ac ldr r3, [r3, #0x4] */
/* @0xfb8b0 blx r3 */
/* @0xfb8b4 ldr r3, [r5, #0x4] */
/* @0xfb8b8 mov r2, #0 */
/* @0xfb8bc str r2, [r3, r4, lsl #2] */
/* @0xfb8c0 pop {r3, r4, r5, pc} */
/* @0xfb8c4 ldr r0, [pc, #0x14] */
/* @0xfb8c8 mov r1, #0 */
/* @0xfb8cc pop {r3, r4, r5, lr} */
/* @0xfb8d0 add r0, pc, r0 */
/* @0xfb8d4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfb8d8 eoreq r2, pc, r12, ror #11 */
/* @0xfb8dc .word 0x002f25dc */
/* @0xfb8e0 eoreq r12, r3, r12, lsr #6 */

/* ── FUNC 0xfb8e4 · F_DsListDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0xfb8e4 push {r3, r4, r5, lr} */
/* @0xfb8e8 mov r1, #0 */
/* @0xfb8ec ldr r0, [sp, #0x10] */
/* @0xfb8f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfb8f4 subs r4, r0, #0 */
/* @0xfb8f8 blt 0xfb944 <_Z15F_DsListDestroyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfb8fc ldr r3, [pc, #0x54] */
/* @0xfb900 ldr r3, [pc, r3] */
/* @0xfb904 ldr r3, [r3] */
/* @0xfb908 cmp r4, r3 */
/* @0xfb90c bge 0xfb944 <_Z15F_DsListDestroyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfb910 ldr r5, [pc, #0x44] */
/* @0xfb914 ldr r5, [pc, r5] */
/* @0xfb918 ldr r3, [r5, #0x4] */
/* @0xfb91c ldr r0, [r3, r4, lsl #2] */
/* @0xfb920 cmp r0, #0 */
/* @0xfb924 popeq {r3, r4, r5, pc} */
/* @0xfb928 ldr r3, [r0] */
/* @0xfb92c ldr r3, [r3, #0x4] */
/* @0xfb930 blx r3 */
/* @0xfb934 ldr r3, [r5, #0x4] */
/* @0xfb938 mov r2, #0 */
/* @0xfb93c str r2, [r3, r4, lsl #2] */
/* @0xfb940 pop {r3, r4, r5, pc} */
/* @0xfb944 ldr r0, [pc, #0x14] */
/* @0xfb948 mov r1, #0 */
/* @0xfb94c pop {r3, r4, r5, lr} */
/* @0xfb950 add r0, pc, r0 */
/* @0xfb954 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfb958 eoreq r2, pc, r12, ror r3 */
/* @0xfb95c eoreq r2, pc, r12, ror #6 */
/* @0xfb960 eoreq r12, r3, r12, lsr #5 */

/* ── FUNC 0xfb964 · F_DsPriorityDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0xfb964 push {r3, r4, r5, lr} */
/* @0xfb968 mov r1, #0 */
/* @0xfb96c ldr r0, [sp, #0x10] */
/* @0xfb970 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfb974 subs r4, r0, #0 */
/* @0xfb978 blt 0xfb9c4 <_Z19F_DsPriorityDestroyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfb97c ldr r3, [pc, #0x54] */
/* @0xfb980 ldr r3, [pc, r3] */
/* @0xfb984 ldr r3, [r3] */
/* @0xfb988 cmp r4, r3 */
/* @0xfb98c bge 0xfb9c4 <_Z19F_DsPriorityDestroyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfb990 ldr r5, [pc, #0x44] */
/* @0xfb994 ldr r5, [pc, r5] */
/* @0xfb998 ldr r3, [r5, #0x4] */
/* @0xfb99c ldr r0, [r3, r4, lsl #2] */
/* @0xfb9a0 cmp r0, #0 */
/* @0xfb9a4 beq 0xfb9c4 <_Z19F_DsPriorityDestroyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfb9a8 ldr r3, [r0] */
/* @0xfb9ac ldr r3, [r3, #0x4] */
/* @0xfb9b0 blx r3 */
/* @0xfb9b4 ldr r3, [r5, #0x4] */
/* @0xfb9b8 mov r2, #0 */
/* @0xfb9bc str r2, [r3, r4, lsl #2] */
/* @0xfb9c0 pop {r3, r4, r5, pc} */
/* @0xfb9c4 ldr r0, [pc, #0x14] */
/* @0xfb9c8 mov r1, #0 */
/* @0xfb9cc pop {r3, r4, r5, lr} */
/* @0xfb9d0 add r0, pc, r0 */
/* @0xfb9d4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfb9d8 .word 0x002f24f4 */
/* @0xfb9dc eoreq r2, pc, r4, ror #9 */
/* @0xfb9e0 eoreq r12, r3, r12, lsr #4 */

/* ── FUNC 0xfb9e4 · F_DsStackClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0xfb9e4 push {r3, lr} */
/* @0xfb9e8 mov r1, #0 */
/* @0xfb9ec ldr r0, [sp, #0x8] */
/* @0xfb9f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfb9f4 cmp r0, #0 */
/* @0xfb9f8 blt 0xfba30 <_Z14F_DsStackClearR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfb9fc ldr r3, [pc, #0x40] */
/* @0xfba00 ldr r3, [pc, r3] */
/* @0xfba04 ldr r3, [r3] */
/* @0xfba08 cmp r0, r3 */
/* @0xfba0c bge 0xfba30 <_Z14F_DsStackClearR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfba10 ldr r3, [pc, #0x30] */
/* @0xfba14 ldr r3, [pc, r3] */
/* @0xfba18 ldr r3, [r3, #0x4] */
/* @0xfba1c ldr r0, [r3, r0, lsl #2] */
/* @0xfba20 cmp r0, #0 */
/* @0xfba24 beq 0xfba30 <_Z14F_DsStackClearR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfba28 pop {r3, lr} */
/* @0xfba2c b 0x20f270 <_ZN9CDS_Stack5ClearEv> */
/* @0xfba30 ldr r0, [pc, #0x14] */
/* @0xfba34 mov r1, #0 */
/* @0xfba38 pop {r3, lr} */
/* @0xfba3c add r0, pc, r0 */
/* @0xfba40 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfba44 eoreq r2, pc, r12, ror r4 */
/* @0xfba48 eoreq r2, pc, r12, ror #8 */
/* @0xfba4c eoreq r12, r3, r0, asr #3 */

/* ── FUNC 0xfba50 · F_DsStackCopy(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0xfba50 push {r3, r4, r5, r6, r7, lr} */
/* @0xfba54 mov r1, #0 */
/* @0xfba58 ldr r7, [sp, #0x18] */
/* @0xfba5c mov r0, r7 */
/* @0xfba60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfba64 subs r5, r0, #0 */
/* @0xfba68 blt 0xfbad4 <_Z13F_DsStackCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfba6c ldr r4, [pc, #0x74] */
/* @0xfba70 ldr r4, [pc, r4] */
/* @0xfba74 ldr r3, [r4] */
/* @0xfba78 cmp r5, r3 */
/* @0xfba7c bge 0xfbad4 <_Z13F_DsStackCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfba80 ldr r6, [pc, #0x64] */
/* @0xfba84 ldr r6, [pc, r6] */
/* @0xfba88 ldr r3, [r6, #0x4] */
/* @0xfba8c ldr r3, [r3, r5, lsl #2] */
/* @0xfba90 cmp r3, #0 */
/* @0xfba94 beq 0xfbad4 <_Z13F_DsStackCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfba98 mov r0, r7 */
/* @0xfba9c mov r1, #1 */
/* @0xfbaa0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfbaa4 cmp r0, #0 */
/* @0xfbaa8 blt 0xfbad4 <_Z13F_DsStackCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfbaac ldr r3, [r4] */
/* @0xfbab0 cmp r0, r3 */
/* @0xfbab4 bge 0xfbad4 <_Z13F_DsStackCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfbab8 ldr r3, [r6, #0x4] */
/* @0xfbabc ldr r1, [r3, r0, lsl #2] */
/* @0xfbac0 cmp r1, #0 */
/* @0xfbac4 beq 0xfbad4 <_Z13F_DsStackCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfbac8 ldr r0, [r3, r5, lsl #2] */
/* @0xfbacc pop {r3, r4, r5, r6, r7, lr} */
/* @0xfbad0 b 0x20f514 <_ZN9CDS_Stack6AssignEPS_> */
/* @0xfbad4 ldr r0, [pc, #0x14] */
/* @0xfbad8 mov r1, #0 */
/* @0xfbadc pop {r3, r4, r5, r6, r7, lr} */
/* @0xfbae0 add r0, pc, r0 */
/* @0xfbae4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfbae8 eoreq r2, pc, r12, lsl #8 */
/* @0xfbaec .word 0x002f23fc */
/* @0xfbaf0 eoreq r12, r3, r12, lsl r1 */

/* ── FUNC 0xfbaf4 · F_DsStackSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0xfbaf4 push {r4, lr} */
/* @0xfbaf8 mov r1, #0 */
/* @0xfbafc mov r4, r0 */
/* @0xfbb00 ldr r0, [sp, #0x8] */
/* @0xfbb04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfbb08 cmp r0, #0 */
/* @0xfbb0c blt 0xfbb64 <_Z13F_DsStackSizeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfbb10 ldr r3, [pc, #0x60] */
/* @0xfbb14 ldr r3, [pc, r3] */
/* @0xfbb18 ldr r3, [r3] */
/* @0xfbb1c cmp r0, r3 */
/* @0xfbb20 bge 0xfbb64 <_Z13F_DsStackSizeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfbb24 ldr r3, [pc, #0x50] */
/* @0xfbb28 ldr r3, [pc, r3] */
/* @0xfbb2c ldr r3, [r3, #0x4] */
/* @0xfbb30 ldr r0, [r3, r0, lsl #2] */
/* @0xfbb34 cmp r0, #0 */
/* @0xfbb38 beq 0xfbb64 <_Z13F_DsStackSizeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfbb3c mov r3, #0 */
/* @0xfbb40 str r3, [r4, #0xc] */
/* @0xfbb44 bl 0x2052ac <_ZN9CDS_Stack4SizeEv> */
/* @0xfbb48 vmov s15, r0 */
/* @0xfbb4c vcvt.f64.s32 d7, s15 */
/* @0xfbb50 vmov r0, r1, d7 */
/* @0xfbb54 vmov r2, s14 */
/* @0xfbb58 mov r3, r1 */
/* @0xfbb5c stm r4, {r2, r3} */
/* @0xfbb60 pop {r4, pc} */
/* @0xfbb64 ldr r0, [pc, #0x14] */
/* @0xfbb68 mov r1, #0 */
/* @0xfbb6c pop {r4, lr} */
/* @0xfbb70 add r0, pc, r0 */
/* @0xfbb74 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfbb78 eoreq r2, pc, r8, ror #6 */
/* @0xfbb7c eoreq r2, pc, r8, asr r3 */
/* @0xfbb80 eoreq r12, r3, r12, lsl #1 */

/* ── FUNC 0xfbb84 · F_DsStackEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0xfbb84 push {r3, r4, r5, lr} */
/* @0xfbb88 mov r1, #0 */
/* @0xfbb8c mov r4, r0 */
/* @0xfbb90 ldr r0, [sp, #0x10] */
/* @0xfbb94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfbb98 cmp r0, #0 */
/* @0xfbb9c blt 0xfbbf8 <_Z14F_DsStackEmptyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfbba0 ldr r3, [pc, #0x64] */
/* @0xfbba4 ldr r3, [pc, r3] */
/* @0xfbba8 ldr r3, [r3] */
/* @0xfbbac cmp r0, r3 */
/* @0xfbbb0 bge 0xfbbf8 <_Z14F_DsStackEmptyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfbbb4 ldr r3, [pc, #0x54] */
/* @0xfbbb8 ldr r3, [pc, r3] */
/* @0xfbbbc ldr r3, [r3, #0x4] */
/* @0xfbbc0 ldr r0, [r3, r0, lsl #2] */
/* @0xfbbc4 cmp r0, #0 */
/* @0xfbbc8 beq 0xfbbf8 <_Z14F_DsStackEmptyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfbbcc mov r5, #0 */
/* @0xfbbd0 str r5, [r4, #0xc] */
/* @0xfbbd4 bl 0x202d40 <_ZN9CDS_Stack5EmptyEv> */
/* @0xfbbd8 cmp r0, #0 */
/* @0xfbbdc moveq r5, r0 */
/* @0xfbbe0 movne r3, r5 */
/* @0xfbbe4 moveq r3, r5 */
/* @0xfbbe8 movtne r3, #0x3ff0 */
/* @0xfbbec str r5, [r4] */
/* @0xfbbf0 str r3, [r4, #0x4] */
/* @0xfbbf4 pop {r3, r4, r5, pc} */
/* @0xfbbf8 ldr r0, [pc, #0x14] */
/* @0xfbbfc mov r1, #0 */
/* @0xfbc00 pop {r3, r4, r5, lr} */
/* @0xfbc04 add r0, pc, r0 */
/* @0xfbc08 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfbc0c .word 0x002f22d8 */
/* @0xfbc10 eoreq r2, pc, r8, asr #5 */
/* @0xfbc14 .word 0x0023bff8 */

/* ── FUNC 0xfbc18 · F_DsStackPush(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0xfbc18 push {r4, r5, r6, r7, r8, lr} */
/* @0xfbc1c mov r1, #0 */
/* @0xfbc20 ldr r5, [sp, #0x18] */
/* @0xfbc24 mov r6, r3 */
/* @0xfbc28 mov r0, r5 */
/* @0xfbc2c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfbc30 cmp r6, #1 */
/* @0xfbc34 movgt r3, #0 */
/* @0xfbc38 movle r3, #1 */
/* @0xfbc3c orrs r3, r3, r0, lsr #31 */
/* @0xfbc40 bne 0xfbca0 <_Z13F_DsStackPushR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xfbc44 ldr r3, [pc, #0x68] */
/* @0xfbc48 ldr r3, [pc, r3] */
/* @0xfbc4c ldr r3, [r3] */
/* @0xfbc50 cmp r0, r3 */
/* @0xfbc54 bge 0xfbca0 <_Z13F_DsStackPushR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xfbc58 ldr r7, [pc, #0x58] */
/* @0xfbc5c lsl r8, r0, #2 */
/* @0xfbc60 ldr r7, [pc, r7] */
/* @0xfbc64 ldr r3, [r7, #0x4] */
/* @0xfbc68 ldr r0, [r3, r0, lsl #2] */
/* @0xfbc6c cmp r0, #0 */
/* @0xfbc70 addne r5, r5, #16 */
/* @0xfbc74 movne r4, #1 */
/* @0xfbc78 beq 0xfbca0 <_Z13F_DsStackPushR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xfbc7c mov r1, r5 */
/* @0xfbc80 add r4, r4, #1 */
/* @0xfbc84 bl 0x20566c <_ZN9CDS_Stack4PushEP6RValue> */
/* @0xfbc88 cmp r6, r4 */
/* @0xfbc8c add r5, r5, #16 */
/* @0xfbc90 pople {r4, r5, r6, r7, r8, pc} */
/* @0xfbc94 ldr r2, [r7, #0x4] */
/* @0xfbc98 ldr r0, [r2, r8] */
/* @0xfbc9c b 0xfbc7c <_Z13F_DsStackPushR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xfbca0 ldr r0, [pc, #0x14] */
/* @0xfbca4 mov r1, #0 */
/* @0xfbca8 pop {r4, r5, r6, r7, r8, lr} */
/* @0xfbcac add r0, pc, r0 */
/* @0xfbcb0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfbcb4 eoreq r2, pc, r4, lsr r2 */
/* @0xfbcb8 eoreq r2, pc, r0, lsr #4 */
/* @0xfbcbc eoreq r11, r3, r0, asr pc */

/* ── FUNC 0xfbcc0 · F_DsStackWrite(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0xfbcc0 push {r4, lr} */
/* @0xfbcc4 sub sp, sp, #8 */
/* @0xfbcc8 mov r4, r0 */
/* @0xfbccc mov r1, #0 */
/* @0xfbcd0 ldr r0, [sp, #0x10] */
/* @0xfbcd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfbcd8 subs r2, r0, #0 */
/* @0xfbcdc blt 0xfbd3c <_Z14F_DsStackWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfbce0 ldr r3, [pc, #0x6c] */
/* @0xfbce4 ldr r3, [pc, r3] */
/* @0xfbce8 ldr r3, [r3] */
/* @0xfbcec cmp r2, r3 */
/* @0xfbcf0 bge 0xfbd3c <_Z14F_DsStackWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfbcf4 ldr r3, [pc, #0x5c] */
/* @0xfbcf8 ldr r3, [pc, r3] */
/* @0xfbcfc ldr r3, [r3, #0x4] */
/* @0xfbd00 ldr r1, [r3, r2, lsl #2] */
/* @0xfbd04 cmp r1, #0 */
/* @0xfbd08 beq 0xfbd3c <_Z14F_DsStackWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfbd0c add r1, sp, #8 */
/* @0xfbd10 mov r0, #0 */
/* @0xfbd14 str r0, [r1, #-0x4]! */
/* @0xfbd18 ldr r0, [r3, r2, lsl #2] */
/* @0xfbd1c bl 0x202c70 <_ZN9CDS_Stack13WriteToStringERPKc> */
/* @0xfbd20 mov r0, r4 */
/* @0xfbd24 ldr r1, [sp, #0x4] */
/* @0xfbd28 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xfbd2c ldr r0, [sp, #0x4] */
/* @0xfbd30 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xfbd34 add sp, sp, #8 */
/* @0xfbd38 pop {r4, pc} */
/* @0xfbd3c ldr r0, [pc, #0x18] */
/* @0xfbd40 mov r1, #0 */
/* @0xfbd44 add r0, pc, r0 */
/* @0xfbd48 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfbd4c add sp, sp, #8 */
/* @0xfbd50 pop {r4, pc} */
/* @0xfbd54 mlaeq pc, r8, r1, r2 */
/* @0xfbd58 eoreq r2, pc, r8, lsl #3 */
/* @0xfbd5c .word 0x0023beb8 */

/* ── FUNC 0xfbd60 · F_DsStackRead(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0xfbd60 push {r3, r4, r5, r6, r7, lr} */
/* @0xfbd64 mov r1, #0 */
/* @0xfbd68 ldr r5, [sp, #0x18] */
/* @0xfbd6c mov r6, r3 */
/* @0xfbd70 mov r0, r5 */
/* @0xfbd74 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfbd78 mov r1, #1 */
/* @0xfbd7c mov r4, r0 */
/* @0xfbd80 mov r0, r5 */
/* @0xfbd84 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xfbd88 cmp r6, #3 */
/* @0xfbd8c movne r2, #0 */
/* @0xfbd90 mov r7, r0 */
/* @0xfbd94 beq 0xfbdec <_Z13F_DsStackReadR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0xfbd98 cmp r4, #0 */
/* @0xfbd9c blt 0xfbdd8 <_Z13F_DsStackReadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfbda0 ldr r3, [pc, #0x60] */
/* @0xfbda4 ldr r3, [pc, r3] */
/* @0xfbda8 ldr r3, [r3] */
/* @0xfbdac cmp r4, r3 */
/* @0xfbdb0 bge 0xfbdd8 <_Z13F_DsStackReadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfbdb4 ldr r3, [pc, #0x50] */
/* @0xfbdb8 ldr r3, [pc, r3] */
/* @0xfbdbc ldr r3, [r3, #0x4] */
/* @0xfbdc0 ldr r0, [r3, r4, lsl #2] */
/* @0xfbdc4 cmp r0, #0 */
/* @0xfbdc8 beq 0xfbdd8 <_Z13F_DsStackReadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfbdcc mov r1, r7 */
/* @0xfbdd0 pop {r3, r4, r5, r6, r7, lr} */
/* @0xfbdd4 b 0x20f860 <_ZN9CDS_Stack14ReadFromStringEPKcb> */
/* @0xfbdd8 ldr r0, [pc, #0x30] */
/* @0xfbddc mov r1, #0 */
/* @0xfbde0 pop {r3, r4, r5, r6, r7, lr} */
/* @0xfbde4 add r0, pc, r0 */
/* @0xfbde8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfbdec mov r0, r5 */
/* @0xfbdf0 mov r1, #2 */
/* @0xfbdf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfbdf8 cmp r0, #0 */
/* @0xfbdfc movle r2, #0 */
/* @0xfbe00 movgt r2, #1 */
/* @0xfbe04 b 0xfbd98 <_Z13F_DsStackReadR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0xfbe08 .word 0x002f20d8 */
/* @0xfbe0c eoreq r2, pc, r8, asr #1 */
/* @0xfbe10 eoreq r11, r3, r8, lsl lr */

/* ── FUNC 0xfbe14 · F_DsQueueClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0xfbe14 push {r3, lr} */
/* @0xfbe18 mov r1, #0 */
/* @0xfbe1c ldr r0, [sp, #0x8] */
/* @0xfbe20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfbe24 cmp r0, #0 */
/* @0xfbe28 blt 0xfbe60 <_Z14F_DsQueueClearR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfbe2c ldr r3, [pc, #0x40] */
/* @0xfbe30 ldr r3, [pc, r3] */
/* @0xfbe34 ldr r3, [r3] */
/* @0xfbe38 cmp r0, r3 */
/* @0xfbe3c bge 0xfbe60 <_Z14F_DsQueueClearR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfbe40 ldr r3, [pc, #0x30] */
/* @0xfbe44 ldr r3, [pc, r3] */
/* @0xfbe48 ldr r3, [r3, #0x4] */
/* @0xfbe4c ldr r0, [r3, r0, lsl #2] */
/* @0xfbe50 cmp r0, #0 */
/* @0xfbe54 beq 0xfbe60 <_Z14F_DsQueueClearR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfbe58 pop {r3, lr} */
/* @0xfbe5c b 0x20eacc <_ZN9CDS_Queue5ClearEv> */
/* @0xfbe60 ldr r0, [pc, #0x14] */
/* @0xfbe64 mov r1, #0 */
/* @0xfbe68 pop {r3, lr} */
/* @0xfbe6c add r0, pc, r0 */
/* @0xfbe70 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfbe74 eoreq r2, pc, r12, lsr r0 */
/* @0xfbe78 eoreq r2, pc, r12, lsr #32 */
/* @0xfbe7c mlaeq r3, r0, sp, r11 */

/* ── FUNC 0xfbe80 · F_DsQueueCopy(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0xfbe80 push {r3, r4, r5, r6, r7, lr} */
/* @0xfbe84 mov r1, #0 */
/* @0xfbe88 ldr r7, [sp, #0x18] */
/* @0xfbe8c mov r0, r7 */
/* @0xfbe90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfbe94 subs r5, r0, #0 */
/* @0xfbe98 blt 0xfbf04 <_Z13F_DsQueueCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfbe9c ldr r4, [pc, #0x74] */
/* @0xfbea0 ldr r4, [pc, r4] */
/* @0xfbea4 ldr r3, [r4] */
/* @0xfbea8 cmp r5, r3 */
/* @0xfbeac bge 0xfbf04 <_Z13F_DsQueueCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfbeb0 ldr r6, [pc, #0x64] */
/* @0xfbeb4 ldr r6, [pc, r6] */
/* @0xfbeb8 ldr r3, [r6, #0x4] */
/* @0xfbebc ldr r3, [r3, r5, lsl #2] */
/* @0xfbec0 cmp r3, #0 */
/* @0xfbec4 beq 0xfbf04 <_Z13F_DsQueueCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfbec8 mov r0, r7 */
/* @0xfbecc mov r1, #1 */
/* @0xfbed0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfbed4 cmp r0, #0 */
/* @0xfbed8 blt 0xfbf04 <_Z13F_DsQueueCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfbedc ldr r3, [r4] */
/* @0xfbee0 cmp r0, r3 */
/* @0xfbee4 bge 0xfbf04 <_Z13F_DsQueueCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfbee8 ldr r3, [r6, #0x4] */
/* @0xfbeec ldr r1, [r3, r0, lsl #2] */
/* @0xfbef0 cmp r1, #0 */
/* @0xfbef4 beq 0xfbf04 <_Z13F_DsQueueCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfbef8 ldr r0, [r3, r5, lsl #2] */
/* @0xfbefc pop {r3, r4, r5, r6, r7, lr} */
/* @0xfbf00 b 0x20edac <_ZN9CDS_Queue6AssignEPS_> */
/* @0xfbf04 ldr r0, [pc, #0x14] */
/* @0xfbf08 mov r1, #0 */
/* @0xfbf0c pop {r3, r4, r5, r6, r7, lr} */
/* @0xfbf10 add r0, pc, r0 */
/* @0xfbf14 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfbf18 eoreq r1, pc, r12, asr #31 */
/* @0xfbf1c .word 0x002f1fbc */
/* @0xfbf20 eoreq r11, r3, r12, ror #25 */

/* ── FUNC 0xfbf24 · F_DsQueueSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0xfbf24 push {r4, lr} */
/* @0xfbf28 mov r1, #0 */
/* @0xfbf2c mov r4, r0 */
/* @0xfbf30 ldr r0, [sp, #0x8] */
/* @0xfbf34 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfbf38 cmp r0, #0 */
/* @0xfbf3c blt 0xfbf94 <_Z13F_DsQueueSizeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfbf40 ldr r3, [pc, #0x60] */
/* @0xfbf44 ldr r3, [pc, r3] */
/* @0xfbf48 ldr r3, [r3] */
/* @0xfbf4c cmp r0, r3 */
/* @0xfbf50 bge 0xfbf94 <_Z13F_DsQueueSizeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfbf54 ldr r3, [pc, #0x50] */
/* @0xfbf58 ldr r3, [pc, r3] */
/* @0xfbf5c ldr r3, [r3, #0x4] */
/* @0xfbf60 ldr r0, [r3, r0, lsl #2] */
/* @0xfbf64 cmp r0, #0 */
/* @0xfbf68 beq 0xfbf94 <_Z13F_DsQueueSizeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfbf6c mov r3, #0 */
/* @0xfbf70 str r3, [r4, #0xc] */
/* @0xfbf74 bl 0x2052b4 <_ZN9CDS_Queue4SizeEv> */
/* @0xfbf78 vmov s15, r0 */
/* @0xfbf7c vcvt.f64.s32 d7, s15 */
/* @0xfbf80 vmov r0, r1, d7 */
/* @0xfbf84 vmov r2, s14 */
/* @0xfbf88 mov r3, r1 */
/* @0xfbf8c stm r4, {r2, r3} */
/* @0xfbf90 pop {r4, pc} */
/* @0xfbf94 ldr r0, [pc, #0x14] */
/* @0xfbf98 mov r1, #0 */
/* @0xfbf9c pop {r4, lr} */
/* @0xfbfa0 add r0, pc, r0 */
/* @0xfbfa4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfbfa8 eoreq r1, pc, r8, lsr #30 */
/* @0xfbfac eoreq r1, pc, r8, lsl pc */
/* @0xfbfb0 eoreq r11, r3, r12, asr r12 */

/* ── FUNC 0xfbfb4 · F_DsQueueEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0xfbfb4 push {r3, r4, r5, lr} */
/* @0xfbfb8 mov r1, #0 */
/* @0xfbfbc mov r4, r0 */
/* @0xfbfc0 ldr r0, [sp, #0x10] */
/* @0xfbfc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfbfc8 cmp r0, #0 */
/* @0xfbfcc blt 0xfc028 <_Z14F_DsQueueEmptyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfbfd0 ldr r3, [pc, #0x64] */
/* @0xfbfd4 ldr r3, [pc, r3] */
/* @0xfbfd8 ldr r3, [r3] */
/* @0xfbfdc cmp r0, r3 */
/* @0xfbfe0 bge 0xfc028 <_Z14F_DsQueueEmptyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfbfe4 ldr r3, [pc, #0x54] */
/* @0xfbfe8 ldr r3, [pc, r3] */
/* @0xfbfec ldr r3, [r3, #0x4] */
/* @0xfbff0 ldr r0, [r3, r0, lsl #2] */
/* @0xfbff4 cmp r0, #0 */
/* @0xfbff8 beq 0xfc028 <_Z14F_DsQueueEmptyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfbffc mov r5, #0 */
/* @0xfc000 str r5, [r4, #0xc] */
/* @0xfc004 bl 0x202fe0 <_ZN9CDS_Queue5EmptyEv> */
/* @0xfc008 cmp r0, #0 */
/* @0xfc00c moveq r5, r0 */
/* @0xfc010 movne r3, r5 */
/* @0xfc014 moveq r3, r5 */
/* @0xfc018 movtne r3, #0x3ff0 */
/* @0xfc01c str r5, [r4] */
/* @0xfc020 str r3, [r4, #0x4] */
/* @0xfc024 pop {r3, r4, r5, pc} */
/* @0xfc028 ldr r0, [pc, #0x14] */
/* @0xfc02c mov r1, #0 */
/* @0xfc030 pop {r3, r4, r5, lr} */
/* @0xfc034 add r0, pc, r0 */
/* @0xfc038 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc03c mlaeq pc, r8, lr, r1 */
/* @0xfc040 eoreq r1, pc, r8, lsl #29 */
/* @0xfc044 eoreq r11, r3, r8, asr #23 */

/* ── FUNC 0xfc048 · F_DsQueueEnqueue(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0xfc048 push {r4, r5, r6, r7, r8, lr} */
/* @0xfc04c mov r1, #0 */
/* @0xfc050 ldr r5, [sp, #0x18] */
/* @0xfc054 mov r7, r3 */
/* @0xfc058 mov r0, r5 */
/* @0xfc05c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc060 cmp r0, #0 */
/* @0xfc064 blt 0xfc0cc <_Z16F_DsQueueEnqueueR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfc068 ldr r3, [pc, #0x70] */
/* @0xfc06c ldr r3, [pc, r3] */
/* @0xfc070 ldr r3, [r3] */
/* @0xfc074 cmp r0, r3 */
/* @0xfc078 bge 0xfc0cc <_Z16F_DsQueueEnqueueR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfc07c ldr r6, [pc, #0x60] */
/* @0xfc080 lsl r8, r0, #2 */
/* @0xfc084 ldr r6, [pc, r6] */
/* @0xfc088 ldr r3, [r6, #0x4] */
/* @0xfc08c ldr r0, [r3, r0, lsl #2] */
/* @0xfc090 cmp r0, #0 */
/* @0xfc094 beq 0xfc0cc <_Z16F_DsQueueEnqueueR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfc098 cmp r7, #1 */
/* @0xfc09c pople {r4, r5, r6, r7, r8, pc} */
/* @0xfc0a0 add r5, r5, #16 */
/* @0xfc0a4 mov r4, #1 */
/* @0xfc0a8 mov r1, r5 */
/* @0xfc0ac add r4, r4, #1 */
/* @0xfc0b0 bl 0x20588c <_ZN9CDS_Queue7EnqueueEP6RValue> */
/* @0xfc0b4 cmp r4, r7 */
/* @0xfc0b8 add r5, r5, #16 */
/* @0xfc0bc popeq {r4, r5, r6, r7, r8, pc} */
/* @0xfc0c0 ldr r2, [r6, #0x4] */
/* @0xfc0c4 ldr r0, [r2, r8] */
/* @0xfc0c8 b 0xfc0a8 <_Z16F_DsQueueEnqueueR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfc0cc ldr r0, [pc, #0x14] */
/* @0xfc0d0 mov r1, #0 */
/* @0xfc0d4 pop {r4, r5, r6, r7, r8, lr} */
/* @0xfc0d8 add r0, pc, r0 */
/* @0xfc0dc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc0e0 eoreq r1, pc, r0, lsl #28 */
/* @0xfc0e4 eoreq r1, pc, r12, ror #27 */
/* @0xfc0e8 eoreq r11, r3, r4, lsr #22 */

/* ── FUNC 0xfc0ec · F_DsQueueWrite(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0xfc0ec push {r4, lr} */
/* @0xfc0f0 sub sp, sp, #8 */
/* @0xfc0f4 mov r4, r0 */
/* @0xfc0f8 mov r1, #0 */
/* @0xfc0fc ldr r0, [sp, #0x10] */
/* @0xfc100 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc104 subs r2, r0, #0 */
/* @0xfc108 blt 0xfc168 <_Z14F_DsQueueWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfc10c ldr r3, [pc, #0x6c] */
/* @0xfc110 ldr r3, [pc, r3] */
/* @0xfc114 ldr r3, [r3] */
/* @0xfc118 cmp r2, r3 */
/* @0xfc11c bge 0xfc168 <_Z14F_DsQueueWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfc120 ldr r3, [pc, #0x5c] */
/* @0xfc124 ldr r3, [pc, r3] */
/* @0xfc128 ldr r3, [r3, #0x4] */
/* @0xfc12c ldr r1, [r3, r2, lsl #2] */
/* @0xfc130 cmp r1, #0 */
/* @0xfc134 beq 0xfc168 <_Z14F_DsQueueWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfc138 add r1, sp, #8 */
/* @0xfc13c mov r0, #0 */
/* @0xfc140 str r0, [r1, #-0x4]! */
/* @0xfc144 ldr r0, [r3, r2, lsl #2] */
/* @0xfc148 bl 0x202e30 <_ZN9CDS_Queue13WriteToStringERPKc> */
/* @0xfc14c mov r0, r4 */
/* @0xfc150 ldr r1, [sp, #0x4] */
/* @0xfc154 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xfc158 ldr r0, [sp, #0x4] */
/* @0xfc15c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xfc160 add sp, sp, #8 */
/* @0xfc164 pop {r4, pc} */
/* @0xfc168 ldr r0, [pc, #0x18] */
/* @0xfc16c mov r1, #0 */
/* @0xfc170 add r0, pc, r0 */
/* @0xfc174 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc178 add sp, sp, #8 */
/* @0xfc17c pop {r4, pc} */
/* @0xfc180 eoreq r1, pc, r12, asr sp */
/* @0xfc184 eoreq r1, pc, r12, asr #26 */
/* @0xfc188 eoreq r11, r3, r12, lsl #21 */

/* ── FUNC 0xfc18c · F_DsQueueRead(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0xfc18c push {r3, r4, r5, r6, r7, lr} */
/* @0xfc190 mov r1, #0 */
/* @0xfc194 ldr r5, [sp, #0x18] */
/* @0xfc198 mov r6, r3 */
/* @0xfc19c mov r0, r5 */
/* @0xfc1a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc1a4 mov r1, #1 */
/* @0xfc1a8 mov r4, r0 */
/* @0xfc1ac mov r0, r5 */
/* @0xfc1b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xfc1b4 cmp r6, #3 */
/* @0xfc1b8 movne r2, #0 */
/* @0xfc1bc mov r7, r0 */
/* @0xfc1c0 beq 0xfc218 <_Z13F_DsQueueReadR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0xfc1c4 cmp r4, #0 */
/* @0xfc1c8 blt 0xfc204 <_Z13F_DsQueueReadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfc1cc ldr r3, [pc, #0x60] */
/* @0xfc1d0 ldr r3, [pc, r3] */
/* @0xfc1d4 ldr r3, [r3] */
/* @0xfc1d8 cmp r4, r3 */
/* @0xfc1dc bge 0xfc204 <_Z13F_DsQueueReadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfc1e0 ldr r3, [pc, #0x50] */
/* @0xfc1e4 ldr r3, [pc, r3] */
/* @0xfc1e8 ldr r3, [r3, #0x4] */
/* @0xfc1ec ldr r0, [r3, r4, lsl #2] */
/* @0xfc1f0 cmp r0, #0 */
/* @0xfc1f4 beq 0xfc204 <_Z13F_DsQueueReadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfc1f8 mov r1, r7 */
/* @0xfc1fc pop {r3, r4, r5, r6, r7, lr} */
/* @0xfc200 b 0x20f104 <_ZN9CDS_Queue14ReadFromStringEPKcb> */
/* @0xfc204 ldr r0, [pc, #0x30] */
/* @0xfc208 mov r1, #0 */
/* @0xfc20c pop {r3, r4, r5, r6, r7, lr} */
/* @0xfc210 add r0, pc, r0 */
/* @0xfc214 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc218 mov r0, r5 */
/* @0xfc21c mov r1, #2 */
/* @0xfc220 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc224 cmp r0, #0 */
/* @0xfc228 movle r2, #0 */
/* @0xfc22c movgt r2, #1 */
/* @0xfc230 b 0xfc1c4 <_Z13F_DsQueueReadR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0xfc234 mlaeq pc, r12, r12, r1 */
/* @0xfc238 eoreq r1, pc, r12, lsl #25 */
/* @0xfc23c eoreq r11, r3, r12, ror #19 */

/* ── FUNC 0xfc240 · F_DsListClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0xfc240 push {r3, lr} */
/* @0xfc244 mov r1, #0 */
/* @0xfc248 ldr r0, [sp, #0x8] */
/* @0xfc24c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc250 cmp r0, #0 */
/* @0xfc254 blt 0xfc28c <_Z13F_DsListClearR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfc258 ldr r3, [pc, #0x40] */
/* @0xfc25c ldr r3, [pc, r3] */
/* @0xfc260 ldr r3, [r3] */
/* @0xfc264 cmp r0, r3 */
/* @0xfc268 bge 0xfc28c <_Z13F_DsListClearR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfc26c ldr r3, [pc, #0x30] */
/* @0xfc270 ldr r3, [pc, r3] */
/* @0xfc274 ldr r3, [r3, #0x4] */
/* @0xfc278 ldr r0, [r3, r0, lsl #2] */
/* @0xfc27c cmp r0, #0 */
/* @0xfc280 beq 0xfc28c <_Z13F_DsListClearR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfc284 pop {r3, lr} */
/* @0xfc288 b 0x20e478 <_ZN8CDS_List5ClearEv> */
/* @0xfc28c ldr r0, [pc, #0x14] */
/* @0xfc290 mov r1, #0 */
/* @0xfc294 pop {r3, lr} */
/* @0xfc298 add r0, pc, r0 */
/* @0xfc29c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc2a0 eoreq r1, pc, r0, lsr #20 */
/* @0xfc2a4 eoreq r1, pc, r0, lsl r10 */
/* @0xfc2a8 eoreq r11, r3, r4, ror #18 */

/* ── FUNC 0xfc2ac · F_DsListCopy(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0xfc2ac push {r3, r4, r5, r6, r7, lr} */
/* @0xfc2b0 mov r1, #0 */
/* @0xfc2b4 ldr r7, [sp, #0x18] */
/* @0xfc2b8 mov r0, r7 */
/* @0xfc2bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc2c0 subs r5, r0, #0 */
/* @0xfc2c4 blt 0xfc330 <_Z12F_DsListCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfc2c8 ldr r4, [pc, #0x74] */
/* @0xfc2cc ldr r4, [pc, r4] */
/* @0xfc2d0 ldr r3, [r4] */
/* @0xfc2d4 cmp r5, r3 */
/* @0xfc2d8 bge 0xfc330 <_Z12F_DsListCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfc2dc ldr r6, [pc, #0x64] */
/* @0xfc2e0 ldr r6, [pc, r6] */
/* @0xfc2e4 ldr r3, [r6, #0x4] */
/* @0xfc2e8 ldr r3, [r3, r5, lsl #2] */
/* @0xfc2ec cmp r3, #0 */
/* @0xfc2f0 beq 0xfc330 <_Z12F_DsListCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfc2f4 mov r0, r7 */
/* @0xfc2f8 mov r1, #1 */
/* @0xfc2fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc300 cmp r0, #0 */
/* @0xfc304 blt 0xfc330 <_Z12F_DsListCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfc308 ldr r3, [r4] */
/* @0xfc30c cmp r0, r3 */
/* @0xfc310 bge 0xfc330 <_Z12F_DsListCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfc314 ldr r3, [r6, #0x4] */
/* @0xfc318 ldr r1, [r3, r0, lsl #2] */
/* @0xfc31c cmp r1, #0 */
/* @0xfc320 beq 0xfc330 <_Z12F_DsListCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfc324 ldr r0, [r3, r5, lsl #2] */
/* @0xfc328 pop {r3, r4, r5, r6, r7, lr} */
/* @0xfc32c b 0x20e61c <_ZN8CDS_List6AssignEPS_> */
/* @0xfc330 ldr r0, [pc, #0x14] */
/* @0xfc334 mov r1, #0 */
/* @0xfc338 pop {r3, r4, r5, r6, r7, lr} */
/* @0xfc33c add r0, pc, r0 */
/* @0xfc340 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc344 .word 0x002f19b0 */
/* @0xfc348 eoreq r1, pc, r0, lsr #19 */
/* @0xfc34c eoreq r11, r3, r0, asr #17 */

/* ── FUNC 0xfc350 · F_DsListSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0xfc350 push {r4, lr} */
/* @0xfc354 mov r1, #0 */
/* @0xfc358 mov r4, r0 */
/* @0xfc35c ldr r0, [sp, #0x8] */
/* @0xfc360 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc364 cmp r0, #0 */
/* @0xfc368 blt 0xfc3c0 <_Z12F_DsListSizeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfc36c ldr r3, [pc, #0x60] */
/* @0xfc370 ldr r3, [pc, r3] */
/* @0xfc374 ldr r3, [r3] */
/* @0xfc378 cmp r0, r3 */
/* @0xfc37c bge 0xfc3c0 <_Z12F_DsListSizeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfc380 ldr r3, [pc, #0x50] */
/* @0xfc384 ldr r3, [pc, r3] */
/* @0xfc388 ldr r3, [r3, #0x4] */
/* @0xfc38c ldr r0, [r3, r0, lsl #2] */
/* @0xfc390 cmp r0, #0 */
/* @0xfc394 beq 0xfc3c0 <_Z12F_DsListSizeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfc398 mov r3, #0 */
/* @0xfc39c str r3, [r4, #0xc] */
/* @0xfc3a0 bl 0x2052b8 <_ZN8CDS_List4SizeEv> */
/* @0xfc3a4 vmov s15, r0 */
/* @0xfc3a8 vcvt.f64.s32 d7, s15 */
/* @0xfc3ac vmov r0, r1, d7 */
/* @0xfc3b0 vmov r2, s14 */
/* @0xfc3b4 mov r3, r1 */
/* @0xfc3b8 stm r4, {r2, r3} */
/* @0xfc3bc pop {r4, pc} */
/* @0xfc3c0 ldr r0, [pc, #0x14] */
/* @0xfc3c4 mov r1, #0 */
/* @0xfc3c8 pop {r4, lr} */
/* @0xfc3cc add r0, pc, r0 */
/* @0xfc3d0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc3d4 eoreq r1, pc, r12, lsl #18 */
/* @0xfc3d8 .word 0x002f18fc */
/* @0xfc3dc eoreq r11, r3, r0, lsr r8 */

/* ── FUNC 0xfc3e0 · F_DsListEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0xfc3e0 push {r3, r4, r5, lr} */
/* @0xfc3e4 mov r1, #0 */
/* @0xfc3e8 mov r4, r0 */
/* @0xfc3ec ldr r0, [sp, #0x10] */
/* @0xfc3f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc3f4 cmp r0, #0 */
/* @0xfc3f8 blt 0xfc454 <_Z13F_DsListEmptyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfc3fc ldr r3, [pc, #0x64] */
/* @0xfc400 ldr r3, [pc, r3] */
/* @0xfc404 ldr r3, [r3] */
/* @0xfc408 cmp r0, r3 */
/* @0xfc40c bge 0xfc454 <_Z13F_DsListEmptyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfc410 ldr r3, [pc, #0x54] */
/* @0xfc414 ldr r3, [pc, r3] */
/* @0xfc418 ldr r3, [r3, #0x4] */
/* @0xfc41c ldr r0, [r3, r0, lsl #2] */
/* @0xfc420 cmp r0, #0 */
/* @0xfc424 beq 0xfc454 <_Z13F_DsListEmptyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfc428 mov r5, #0 */
/* @0xfc42c str r5, [r4, #0xc] */
/* @0xfc430 bl 0x20317c <_ZN8CDS_List5EmptyEv> */
/* @0xfc434 cmp r0, #0 */
/* @0xfc438 moveq r5, r0 */
/* @0xfc43c movne r3, r5 */
/* @0xfc440 moveq r3, r5 */
/* @0xfc444 movtne r3, #0x3ff0 */
/* @0xfc448 str r5, [r4] */
/* @0xfc44c str r3, [r4, #0x4] */
/* @0xfc450 pop {r3, r4, r5, pc} */
/* @0xfc454 ldr r0, [pc, #0x14] */
/* @0xfc458 mov r1, #0 */
/* @0xfc45c pop {r3, r4, r5, lr} */
/* @0xfc460 add r0, pc, r0 */
/* @0xfc464 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc468 eoreq r1, pc, r12, ror r8 */
/* @0xfc46c eoreq r1, pc, r12, ror #16 */
/* @0xfc470 mlaeq r3, r12, r7, r11 */

/* ── FUNC 0xfc474 · F_DsListAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0xfc474 push {r4, r5, r6, r7, r8, lr} */
/* @0xfc478 mov r1, #0 */
/* @0xfc47c ldr r5, [sp, #0x18] */
/* @0xfc480 mov r6, r3 */
/* @0xfc484 mov r0, r5 */
/* @0xfc488 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc48c cmp r6, #1 */
/* @0xfc490 movgt r3, #0 */
/* @0xfc494 movle r3, #1 */
/* @0xfc498 orrs r3, r3, r0, lsr #31 */
/* @0xfc49c bne 0xfc4fc <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xfc4a0 ldr r3, [pc, #0x68] */
/* @0xfc4a4 ldr r3, [pc, r3] */
/* @0xfc4a8 ldr r3, [r3] */
/* @0xfc4ac cmp r0, r3 */
/* @0xfc4b0 bge 0xfc4fc <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xfc4b4 ldr r7, [pc, #0x58] */
/* @0xfc4b8 lsl r8, r0, #2 */
/* @0xfc4bc ldr r7, [pc, r7] */
/* @0xfc4c0 ldr r3, [r7, #0x4] */
/* @0xfc4c4 ldr r0, [r3, r0, lsl #2] */
/* @0xfc4c8 cmp r0, #0 */
/* @0xfc4cc addne r5, r5, #16 */
/* @0xfc4d0 movne r4, #1 */
/* @0xfc4d4 beq 0xfc4fc <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xfc4d8 mov r1, r5 */
/* @0xfc4dc add r4, r4, #1 */
/* @0xfc4e0 bl 0x205d18 <_ZN8CDS_List3AddEP6RValue> */
/* @0xfc4e4 cmp r6, r4 */
/* @0xfc4e8 add r5, r5, #16 */
/* @0xfc4ec pople {r4, r5, r6, r7, r8, pc} */
/* @0xfc4f0 ldr r2, [r7, #0x4] */
/* @0xfc4f4 ldr r0, [r2, r8] */
/* @0xfc4f8 b 0xfc4d8 <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xfc4fc ldr r0, [pc, #0x14] */
/* @0xfc500 mov r1, #0 */
/* @0xfc504 pop {r4, r5, r6, r7, r8, lr} */
/* @0xfc508 add r0, pc, r0 */
/* @0xfc50c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc510 .word 0x002f17d8 */
/* @0xfc514 eoreq r1, pc, r4, asr #15 */
/* @0xfc518 .word 0x0023b6f4 */

/* ── FUNC 0xfc51c · F_DsListInsert(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0xfc51c push {r3, r4, r5, lr} */
/* @0xfc520 mov r1, #0 */
/* @0xfc524 ldr r4, [sp, #0x10] */
/* @0xfc528 mov r0, r4 */
/* @0xfc52c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc530 cmp r0, #0 */
/* @0xfc534 blt 0xfc584 <_Z14F_DsListInsertR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0xfc538 ldr r3, [pc, #0x58] */
/* @0xfc53c ldr r3, [pc, r3] */
/* @0xfc540 ldr r3, [r3] */
/* @0xfc544 cmp r0, r3 */
/* @0xfc548 bge 0xfc584 <_Z14F_DsListInsertR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0xfc54c ldr r3, [pc, #0x48] */
/* @0xfc550 ldr r3, [pc, r3] */
/* @0xfc554 ldr r3, [r3, #0x4] */
/* @0xfc558 ldr r5, [r3, r0, lsl #2] */
/* @0xfc55c cmp r5, #0 */
/* @0xfc560 beq 0xfc584 <_Z14F_DsListInsertR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0xfc564 mov r0, r4 */
/* @0xfc568 mov r1, #1 */
/* @0xfc56c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc570 add r2, r4, #32 */
/* @0xfc574 mov r1, r0 */
/* @0xfc578 mov r0, r5 */
/* @0xfc57c pop {r3, r4, r5, lr} */
/* @0xfc580 b 0x205f40 <_ZN8CDS_List6InsertEiP6RValue> */
/* @0xfc584 ldr r0, [pc, #0x14] */
/* @0xfc588 mov r1, #0 */
/* @0xfc58c pop {r3, r4, r5, lr} */
/* @0xfc590 add r0, pc, r0 */
/* @0xfc594 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc598 eoreq r1, pc, r0, asr #14 */
/* @0xfc59c eoreq r1, pc, r0, lsr r7 */
/* @0xfc5a0 eoreq r11, r3, r12, ror #12 */

/* ── FUNC 0xfc5a4 · F_DsListSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0xfc5a4 push {r4, r5, r6, lr} */
/* @0xfc5a8 mov r1, #0 */
/* @0xfc5ac ldr r4, [sp, #0x10] */
/* @0xfc5b0 mov r0, r4 */
/* @0xfc5b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc5b8 cmp r0, #0 */
/* @0xfc5bc blt 0xfc610 <_Z11F_DsListSetR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xfc5c0 ldr r3, [pc, #0x5c] */
/* @0xfc5c4 ldr r3, [pc, r3] */
/* @0xfc5c8 ldr r3, [r3] */
/* @0xfc5cc cmp r0, r3 */
/* @0xfc5d0 bge 0xfc610 <_Z11F_DsListSetR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xfc5d4 ldr r3, [pc, #0x4c] */
/* @0xfc5d8 ldr r3, [pc, r3] */
/* @0xfc5dc ldr r3, [r3, #0x4] */
/* @0xfc5e0 ldr r5, [r3, r0, lsl #2] */
/* @0xfc5e4 cmp r5, #0 */
/* @0xfc5e8 beq 0xfc610 <_Z11F_DsListSetR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xfc5ec mov r0, r4 */
/* @0xfc5f0 mov r1, #1 */
/* @0xfc5f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc5f8 add r2, r4, #32 */
/* @0xfc5fc mov r3, #0 */
/* @0xfc600 mov r1, r0 */
/* @0xfc604 mov r0, r5 */
/* @0xfc608 pop {r4, r5, r6, lr} */
/* @0xfc60c b 0x2060c0 <_ZN8CDS_List3SetEiP6RValueS1_> */
/* @0xfc610 ldr r0, [pc, #0x14] */
/* @0xfc614 mov r1, #0 */
/* @0xfc618 pop {r4, r5, r6, lr} */
/* @0xfc61c add r0, pc, r0 */
/* @0xfc620 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc624 .word 0x002f16b8 */
/* @0xfc628 eoreq r1, pc, r8, lsr #13 */
/* @0xfc62c eoreq r11, r3, r0, ror #11 */

/* ── FUNC 0xfc630 · F_DsListSetPost(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0xfc630 push {r4, r5, r6, lr} */
/* @0xfc634 mov r1, #0 */
/* @0xfc638 ldr r4, [sp, #0x10] */
/* @0xfc63c mov r6, r0 */
/* @0xfc640 mov r0, r4 */
/* @0xfc644 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc648 cmp r0, #0 */
/* @0xfc64c blt 0xfc6a0 <_Z15F_DsListSetPostR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfc650 ldr r1, [pc, #0x5c] */
/* @0xfc654 ldr r1, [pc, r1] */
/* @0xfc658 ldr r1, [r1] */
/* @0xfc65c cmp r0, r1 */
/* @0xfc660 bge 0xfc6a0 <_Z15F_DsListSetPostR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfc664 ldr r1, [pc, #0x4c] */
/* @0xfc668 ldr r1, [pc, r1] */
/* @0xfc66c ldr r3, [r1, #0x4] */
/* @0xfc670 ldr r5, [r3, r0, lsl #2] */
/* @0xfc674 cmp r5, #0 */
/* @0xfc678 beq 0xfc6a0 <_Z15F_DsListSetPostR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfc67c mov r0, r4 */
/* @0xfc680 mov r1, #1 */
/* @0xfc684 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc688 add r2, r4, #32 */
/* @0xfc68c mov r3, r6 */
/* @0xfc690 mov r1, r0 */
/* @0xfc694 mov r0, r5 */
/* @0xfc698 pop {r4, r5, r6, lr} */
/* @0xfc69c b 0x2060c0 <_ZN8CDS_List3SetEiP6RValueS1_> */
/* @0xfc6a0 ldr r0, [pc, #0x14] */
/* @0xfc6a4 mov r1, #0 */
/* @0xfc6a8 pop {r4, r5, r6, lr} */
/* @0xfc6ac add r0, pc, r0 */
/* @0xfc6b0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc6b4 eoreq r1, pc, r8, lsr #12 */
/* @0xfc6b8 eoreq r1, pc, r8, lsl r6 */
/* @0xfc6bc eoreq r11, r3, r0, asr r5 */

/* ── FUNC 0xfc6c0 · F_DsListReplace(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0xfc6c0 push {r3, r4, r5, lr} */
/* @0xfc6c4 mov r1, #0 */
/* @0xfc6c8 ldr r4, [sp, #0x10] */
/* @0xfc6cc mov r0, r4 */
/* @0xfc6d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc6d4 cmp r0, #0 */
/* @0xfc6d8 blt 0xfc728 <_Z15F_DsListReplaceR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0xfc6dc ldr r3, [pc, #0x58] */
/* @0xfc6e0 ldr r3, [pc, r3] */
/* @0xfc6e4 ldr r3, [r3] */
/* @0xfc6e8 cmp r0, r3 */
/* @0xfc6ec bge 0xfc728 <_Z15F_DsListReplaceR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0xfc6f0 ldr r3, [pc, #0x48] */
/* @0xfc6f4 ldr r3, [pc, r3] */
/* @0xfc6f8 ldr r3, [r3, #0x4] */
/* @0xfc6fc ldr r5, [r3, r0, lsl #2] */
/* @0xfc700 cmp r5, #0 */
/* @0xfc704 beq 0xfc728 <_Z15F_DsListReplaceR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0xfc708 mov r0, r4 */
/* @0xfc70c mov r1, #1 */
/* @0xfc710 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc714 add r2, r4, #32 */
/* @0xfc718 mov r1, r0 */
/* @0xfc71c mov r0, r5 */
/* @0xfc720 pop {r3, r4, r5, lr} */
/* @0xfc724 b 0x208964 <_ZN8CDS_List7ReplaceEiP6RValue> */
/* @0xfc728 ldr r0, [pc, #0x14] */
/* @0xfc72c mov r1, #0 */
/* @0xfc730 pop {r3, r4, r5, lr} */
/* @0xfc734 add r0, pc, r0 */
/* @0xfc738 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc73c mlaeq pc, r12, r5, r1 */
/* @0xfc740 eoreq r1, pc, r12, lsl #11 */
/* @0xfc744 eoreq r11, r3, r8, asr #9 */

/* ── FUNC 0xfc748 · F_DsListDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0xfc748 push {r3, r4, r5, lr} */
/* @0xfc74c mov r1, #0 */
/* @0xfc750 ldr r4, [sp, #0x10] */
/* @0xfc754 mov r0, r4 */
/* @0xfc758 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc75c cmp r0, #0 */
/* @0xfc760 blt 0xfc7ac <_Z14F_DsListDeleteR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xfc764 ldr r3, [pc, #0x54] */
/* @0xfc768 ldr r3, [pc, r3] */
/* @0xfc76c ldr r3, [r3] */
/* @0xfc770 cmp r0, r3 */
/* @0xfc774 bge 0xfc7ac <_Z14F_DsListDeleteR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xfc778 ldr r3, [pc, #0x44] */
/* @0xfc77c ldr r3, [pc, r3] */
/* @0xfc780 ldr r3, [r3, #0x4] */
/* @0xfc784 ldr r5, [r3, r0, lsl #2] */
/* @0xfc788 cmp r5, #0 */
/* @0xfc78c beq 0xfc7ac <_Z14F_DsListDeleteR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xfc790 mov r0, r4 */
/* @0xfc794 mov r1, #1 */
/* @0xfc798 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc79c mov r1, r0 */
/* @0xfc7a0 mov r0, r5 */
/* @0xfc7a4 pop {r3, r4, r5, lr} */
/* @0xfc7a8 b 0x208b94 <_ZN8CDS_List6DeleteEi> */
/* @0xfc7ac ldr r0, [pc, #0x14] */
/* @0xfc7b0 mov r1, #0 */
/* @0xfc7b4 pop {r3, r4, r5, lr} */
/* @0xfc7b8 add r0, pc, r0 */
/* @0xfc7bc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc7c0 eoreq r1, pc, r4, lsl r5 */
/* @0xfc7c4 eoreq r1, pc, r4, lsl #10 */
/* @0xfc7c8 eoreq r11, r3, r4, asr #8 */

/* ── FUNC 0xfc7cc · F_DsListFindIndex(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0xfc7cc push {r3, r4, r5, lr} */
/* @0xfc7d0 mov r1, #0 */
/* @0xfc7d4 ldr r4, [sp, #0x10] */
/* @0xfc7d8 mov r5, r0 */
/* @0xfc7dc mov r0, r4 */
/* @0xfc7e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc7e4 cmp r0, #0 */
/* @0xfc7e8 blt 0xfc844 <_Z17F_DsListFindIndexR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfc7ec ldr r3, [pc, #0x64] */
/* @0xfc7f0 ldr r3, [pc, r3] */
/* @0xfc7f4 ldr r3, [r3] */
/* @0xfc7f8 cmp r0, r3 */
/* @0xfc7fc bge 0xfc844 <_Z17F_DsListFindIndexR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfc800 ldr r3, [pc, #0x54] */
/* @0xfc804 ldr r3, [pc, r3] */
/* @0xfc808 ldr r3, [r3, #0x4] */
/* @0xfc80c ldr r0, [r3, r0, lsl #2] */
/* @0xfc810 cmp r0, #0 */
/* @0xfc814 beq 0xfc844 <_Z17F_DsListFindIndexR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfc818 mov r3, #0 */
/* @0xfc81c add r1, r4, #16 */
/* @0xfc820 str r3, [r5, #0xc] */
/* @0xfc824 bl 0x20318c <_ZN8CDS_List4FindEP6RValue> */
/* @0xfc828 vmov s15, r0 */
/* @0xfc82c vcvt.f64.s32 d7, s15 */
/* @0xfc830 vmov r0, r1, d7 */
/* @0xfc834 vmov r2, s14 */
/* @0xfc838 mov r3, r1 */
/* @0xfc83c stm r5, {r2, r3} */
/* @0xfc840 pop {r3, r4, r5, pc} */
/* @0xfc844 ldr r0, [pc, #0x14] */
/* @0xfc848 mov r1, #0 */
/* @0xfc84c pop {r3, r4, r5, lr} */
/* @0xfc850 add r0, pc, r0 */
/* @0xfc854 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc858 eoreq r1, pc, r12, lsl #9 */
/* @0xfc85c eoreq r1, pc, r12, ror r4 */
/* @0xfc860 eoreq r11, r3, r12, lsr #7 */

/* ── FUNC 0xfc864 · F_DsListSort(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0xfc864 push {r3, r4, r5, lr} */
/* @0xfc868 mov r1, #0 */
/* @0xfc86c ldr r4, [sp, #0x10] */
/* @0xfc870 mov r0, r4 */
/* @0xfc874 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc878 cmp r0, #0 */
/* @0xfc87c blt 0xfc8c8 <_Z12F_DsListSortR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xfc880 ldr r3, [pc, #0x54] */
/* @0xfc884 ldr r3, [pc, r3] */
/* @0xfc888 ldr r3, [r3] */
/* @0xfc88c cmp r0, r3 */
/* @0xfc890 bge 0xfc8c8 <_Z12F_DsListSortR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xfc894 ldr r3, [pc, #0x44] */
/* @0xfc898 ldr r3, [pc, r3] */
/* @0xfc89c ldr r3, [r3, #0x4] */
/* @0xfc8a0 ldr r5, [r3, r0, lsl #2] */
/* @0xfc8a4 cmp r5, #0 */
/* @0xfc8a8 beq 0xfc8c8 <_Z12F_DsListSortR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xfc8ac mov r0, r4 */
/* @0xfc8b0 mov r1, #1 */
/* @0xfc8b4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0xfc8b8 mov r1, r0 */
/* @0xfc8bc mov r0, r5 */
/* @0xfc8c0 pop {r3, r4, r5, lr} */
/* @0xfc8c4 b 0x20321c <_ZN8CDS_List4SortEb> */
/* @0xfc8c8 ldr r0, [pc, #0x14] */
/* @0xfc8cc mov r1, #0 */
/* @0xfc8d0 pop {r3, r4, r5, lr} */
/* @0xfc8d4 add r0, pc, r0 */
/* @0xfc8d8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc8dc .word 0x002f13f8 */
/* @0xfc8e0 eoreq r1, pc, r8, ror #7 */
/* @0xfc8e4 eoreq r11, r3, r8, lsr #6 */
