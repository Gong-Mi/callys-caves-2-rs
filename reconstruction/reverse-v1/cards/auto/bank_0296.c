/* libyoyo.so 覆盖卡组 0296
 * 函数 0x31a73c..0x31b134，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x31a73c · __gnu_unwind_execute · size=892 · insn=223 */
/* @0x31a73c push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x31a740 add r8, sp, #12 */
/* @0x31a744 mov r5, r0 */
/* @0x31a748 mov r6, r1 */
/* @0x31a74c mov r7, #0 */
/* @0x31a750 mov r9, #4080 */
/* @0x31a754 mov r0, r6 */
/* @0x31a758 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a75c cmp r0, #176 */
/* @0x31a760 mov r4, r0 */
/* @0x31a764 bne 0x31a7a8 <__gnu_unwind_execute+0x6c> */
/* @0x31a768 cmp r7, #0 */
/* @0x31a76c bne 0x31aaac <__gnu_unwind_execute+0x370> */
/* @0x31a770 add r4, sp, #12 */
/* @0x31a774 mov r1, r7 */
/* @0x31a778 mov r3, r7 */
/* @0x31a77c str r4, [sp] */
/* @0x31a780 mov r0, r5 */
/* @0x31a784 mov r2, #14 */
/* @0x31a788 bl 0x319be4 <_Unwind_VRS_Get> */
/* @0x31a78c str r4, [sp] */
/* @0x31a790 mov r0, r5 */
/* @0x31a794 mov r1, r7 */
/* @0x31a798 mov r2, #15 */
/* @0x31a79c mov r3, r7 */
/* @0x31a7a0 bl 0x319c68 <_Unwind_VRS_Set> */
/* @0x31a7a4 b 0x31aaac <__gnu_unwind_execute+0x370> */
/* @0x31a7a8 bic r1, r0, #127 */
/* @0x31a7ac ands r1, r1, #255 */
/* @0x31a7b0 bne 0x31a7ec <__gnu_unwind_execute+0xb0> */
/* @0x31a7b4 lsl r10, r0, #2 */
/* @0x31a7b8 mov r3, r1 */
/* @0x31a7bc str r8, [sp] */
/* @0x31a7c0 mov r0, r5 */
/* @0x31a7c4 mov r2, #13 */
/* @0x31a7c8 uxtb r10, r10 */
/* @0x31a7cc bl 0x319be4 <_Unwind_VRS_Get> */
/* @0x31a7d0 ldr r3, [sp, #0xc] */
/* @0x31a7d4 add r10, r10, #4 */
/* @0x31a7d8 tst r4, #64 */
/* @0x31a7dc rsbne r10, r10, r3 */
/* @0x31a7e0 addeq r10, r3, r10 */
/* @0x31a7e4 str r10, [sp, #0xc] */
/* @0x31a7e8 b 0x31a870 <__gnu_unwind_execute+0x134> */
/* @0x31a7ec and r3, r0, #240 */
/* @0x31a7f0 cmp r3, #128 */
/* @0x31a7f4 bne 0x31a844 <__gnu_unwind_execute+0x108> */
/* @0x31a7f8 lsl r4, r0, #8 */
/* @0x31a7fc mov r0, r6 */
/* @0x31a800 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a804 orr r0, r0, r4 */
/* @0x31a808 cmp r0, #32768 */
/* @0x31a80c bne 0x31a818 <__gnu_unwind_execute+0xdc> */
/* @0x31a810 mov r0, #9 */
/* @0x31a814 b 0x31aab0 <__gnu_unwind_execute+0x374> */
/* @0x31a818 lsl r4, r0, #4 */
/* @0x31a81c mov r1, #0 */
/* @0x31a820 mov r0, r5 */
/* @0x31a824 mov r3, r1 */
/* @0x31a828 uxth r2, r4 */
/* @0x31a82c bl 0x31a1bc <_Unwind_VRS_Pop> */
/* @0x31a830 cmp r0, #0 */
/* @0x31a834 bne 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a838 tst r4, #32768 */
/* @0x31a83c movne r7, #1 */
/* @0x31a840 b 0x31a754 <__gnu_unwind_execute+0x18> */
/* @0x31a844 cmp r3, #144 */
/* @0x31a848 bne 0x31a88c <__gnu_unwind_execute+0x150> */
/* @0x31a84c and r3, r0, #13 */
/* @0x31a850 cmp r3, #13 */
/* @0x31a854 beq 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a858 mov r1, #0 */
/* @0x31a85c str r8, [sp] */
/* @0x31a860 mov r0, r5 */
/* @0x31a864 and r2, r4, #15 */
/* @0x31a868 mov r3, r1 */
/* @0x31a86c bl 0x319be4 <_Unwind_VRS_Get> */
/* @0x31a870 mov r0, r5 */
/* @0x31a874 mov r1, #0 */
/* @0x31a878 str r8, [sp] */
/* @0x31a87c mov r2, #13 */
/* @0x31a880 mov r3, r1 */
/* @0x31a884 bl 0x319c68 <_Unwind_VRS_Set> */
/* @0x31a888 b 0x31a754 <__gnu_unwind_execute+0x18> */
/* @0x31a88c cmp r3, #160 */
/* @0x31a890 bne 0x31a8b8 <__gnu_unwind_execute+0x17c> */
/* @0x31a894 mvn r2, r0 */
/* @0x31a898 and r2, r2, #7 */
/* @0x31a89c asr r2, r9, r2 */
/* @0x31a8a0 tst r0, #8 */
/* @0x31a8a4 and r2, r2, #4080 */
/* @0x31a8a8 mov r0, r5 */
/* @0x31a8ac orrne r2, r2, #16384 */
/* @0x31a8b0 mov r1, #0 */
/* @0x31a8b4 b 0x31a8e4 <__gnu_unwind_execute+0x1a8> */
/* @0x31a8b8 cmp r3, #176 */
/* @0x31a8bc bne 0x31a9a4 <__gnu_unwind_execute+0x268> */
/* @0x31a8c0 cmp r0, #177 */
/* @0x31a8c4 bne 0x31a8ec <__gnu_unwind_execute+0x1b0> */
/* @0x31a8c8 mov r0, r6 */
/* @0x31a8cc bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a8d0 subs r2, r0, #0 */
/* @0x31a8d4 beq 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a8d8 ands r1, r2, #240 */
/* @0x31a8dc bne 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a8e0 mov r0, r5 */
/* @0x31a8e4 mov r3, r1 */
/* @0x31a8e8 b 0x31aa9c <__gnu_unwind_execute+0x360> */
/* @0x31a8ec cmp r0, #178 */
/* @0x31a8f0 bne 0x31a958 <__gnu_unwind_execute+0x21c> */
/* @0x31a8f4 mov r1, #0 */
/* @0x31a8f8 mov r2, #13 */
/* @0x31a8fc mov r3, r1 */
/* @0x31a900 str r8, [sp] */
/* @0x31a904 mov r0, r5 */
/* @0x31a908 mov r4, #2 */
/* @0x31a90c bl 0x319be4 <_Unwind_VRS_Get> */
/* @0x31a910 mov r0, r6 */
/* @0x31a914 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a918 ands r1, r0, #128 */
/* @0x31a91c ldr r3, [sp, #0xc] */
/* @0x31a920 and r0, r0, #127 */
/* @0x31a924 beq 0x31a940 <__gnu_unwind_execute+0x204> */
/* @0x31a928 add r0, r3, r0, lsl r4 */
/* @0x31a92c str r0, [sp, #0xc] */
/* @0x31a930 mov r0, r6 */
/* @0x31a934 add r4, r4, #7 */
/* @0x31a938 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a93c b 0x31a918 <__gnu_unwind_execute+0x1dc> */
/* @0x31a940 add r3, r3, #516 */
/* @0x31a944 str r8, [sp] */
/* @0x31a948 add r0, r3, r0, lsl r4 */
/* @0x31a94c str r0, [sp, #0xc] */
/* @0x31a950 mov r0, r5 */
/* @0x31a954 b 0x31a87c <__gnu_unwind_execute+0x140> */
/* @0x31a958 cmp r0, #179 */
/* @0x31a95c bne 0x31a980 <__gnu_unwind_execute+0x244> */
/* @0x31a960 mov r0, r6 */
/* @0x31a964 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a968 mov r1, #1 */
/* @0x31a96c and r3, r0, #15 */
/* @0x31a970 and r2, r0, #240 */
/* @0x31a974 add r3, r3, #1 */
/* @0x31a978 mov r0, r5 */
/* @0x31a97c b 0x31a9d0 <__gnu_unwind_execute+0x294> */
/* @0x31a980 and r3, r0, #252 */
/* @0x31a984 cmp r3, #180 */
/* @0x31a988 beq 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a98c and r4, r0, #7 */
/* @0x31a990 mov r1, #1 */
/* @0x31a994 add r2, r4, #1 */
/* @0x31a998 mov r0, r5 */
/* @0x31a99c orr r2, r2, #524288 */
/* @0x31a9a0 b 0x31a8e4 <__gnu_unwind_execute+0x1a8> */
/* @0x31a9a4 cmp r3, #192 */
/* @0x31a9a8 bne 0x31aa78 <__gnu_unwind_execute+0x33c> */
/* @0x31a9ac cmp r0, #198 */
/* @0x31a9b0 bne 0x31a9d8 <__gnu_unwind_execute+0x29c> */
/* @0x31a9b4 mov r0, r6 */
/* @0x31a9b8 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a9bc mov r1, #3 */
/* @0x31a9c0 and r3, r0, #15 */
/* @0x31a9c4 and r2, r0, #240 */
/* @0x31a9c8 add r3, r3, #1 */
/* @0x31a9cc mov r0, r5 */
/* @0x31a9d0 orr r2, r3, r2, lsl #12 */
/* @0x31a9d4 b 0x31a8e4 <__gnu_unwind_execute+0x1a8> */
/* @0x31a9d8 cmp r0, #199 */
/* @0x31a9dc bne 0x31aa04 <__gnu_unwind_execute+0x2c8> */
/* @0x31a9e0 mov r0, r6 */
/* @0x31a9e4 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31a9e8 subs r2, r0, #0 */
/* @0x31a9ec beq 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a9f0 ands r3, r2, #240 */
/* @0x31a9f4 bne 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31a9f8 mov r0, r5 */
/* @0x31a9fc mov r1, #4 */
/* @0x31aa00 b 0x31aa9c <__gnu_unwind_execute+0x360> */
/* @0x31aa04 and r3, r0, #248 */
/* @0x31aa08 cmp r3, #192 */
/* @0x31aa0c bne 0x31aa28 <__gnu_unwind_execute+0x2ec> */
/* @0x31aa10 and r4, r0, #15 */
/* @0x31aa14 mov r1, #3 */
/* @0x31aa18 add r2, r4, #1 */
/* @0x31aa1c mov r0, r5 */
/* @0x31aa20 orr r2, r2, #655360 */
/* @0x31aa24 b 0x31a8e4 <__gnu_unwind_execute+0x1a8> */
/* @0x31aa28 cmp r0, #200 */
/* @0x31aa2c bne 0x31aa4c <__gnu_unwind_execute+0x310> */
/* @0x31aa30 mov r0, r6 */
/* @0x31aa34 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31aa38 and r2, r0, #240 */
/* @0x31aa3c and r0, r0, #15 */
/* @0x31aa40 add r2, r2, #16 */
/* @0x31aa44 add r3, r0, #1 */
/* @0x31aa48 b 0x31aa68 <__gnu_unwind_execute+0x32c> */
/* @0x31aa4c cmp r0, #201 */
/* @0x31aa50 bne 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31aa54 mov r0, r6 */
/* @0x31aa58 bl 0x31a6b0 <___Unwind_Backtrace+0x24> */
/* @0x31aa5c and r3, r0, #15 */
/* @0x31aa60 and r2, r0, #240 */
/* @0x31aa64 add r3, r3, #1 */
/* @0x31aa68 mov r0, r5 */
/* @0x31aa6c mov r1, #1 */
/* @0x31aa70 orr r2, r3, r2, lsl #12 */
/* @0x31aa74 b 0x31aa98 <__gnu_unwind_execute+0x35c> */
/* @0x31aa78 and r3, r0, #248 */
/* @0x31aa7c cmp r3, #208 */
/* @0x31aa80 bne 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31aa84 and r4, r0, #7 */
/* @0x31aa88 mov r1, #1 */
/* @0x31aa8c add r2, r4, #1 */
/* @0x31aa90 mov r0, r5 */
/* @0x31aa94 orr r2, r2, #524288 */
/* @0x31aa98 mov r3, #5 */
/* @0x31aa9c bl 0x31a1bc <_Unwind_VRS_Pop> */
/* @0x31aaa0 cmp r0, #0 */
/* @0x31aaa4 bne 0x31a810 <__gnu_unwind_execute+0xd4> */
/* @0x31aaa8 b 0x31a754 <__gnu_unwind_execute+0x18> */
/* @0x31aaac mov r0, #0 */
/* @0x31aab0 add sp, sp, #16 */
/* @0x31aab4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x31aab8 · __gnu_unwind_frame · size=64 · insn=16 */
/* @0x31aab8 push {r0, r1, r2, r3, r4, lr} */
/* @0x31aabc ldr r3, [r0, #0x4c] */
/* @0x31aac0 mov r0, r1 */
/* @0x31aac4 add r1, sp, #4 */
/* @0x31aac8 ldr r2, [r3, #0x4] */
/* @0x31aacc lsl r2, r2, #8 */
/* @0x31aad0 str r2, [sp, #0x4] */
/* @0x31aad4 add r2, r3, #8 */
/* @0x31aad8 str r2, [sp, #0x8] */
/* @0x31aadc mov r2, #3 */
/* @0x31aae0 strb r2, [sp, #0xc] */
/* @0x31aae4 ldrb r3, [r3, #0x7] */
/* @0x31aae8 strb r3, [sp, #0xd] */
/* @0x31aaec bl 0x31a73c <__gnu_unwind_execute> */
/* @0x31aaf0 add sp, sp, #20 */
/* @0x31aaf4 ldr pc, [sp], #4 */

/* ── FUNC 0x31aaf8 · _Unwind_GetRegionStart · size=16 · insn=4 */
/* @0x31aaf8 push {r3, lr} */
/* @0x31aafc bl 0x31a738 <___Unwind_Backtrace+0xac> */
/* @0x31ab00 ldr r0, [r0, #0x48] */
/* @0x31ab04 pop {r3, pc} */

/* ── FUNC 0x31ab08 · _Unwind_GetLanguageSpecificData · size=28 · insn=7 */
/* @0x31ab08 push {r3, lr} */
/* @0x31ab0c bl 0x31a738 <___Unwind_Backtrace+0xac> */
/* @0x31ab10 ldr r3, [r0, #0x4c] */
/* @0x31ab14 ldrb r2, [r3, #0x7] */
/* @0x31ab18 add r0, r3, r2, lsl #2 */
/* @0x31ab1c add r0, r0, #8 */
/* @0x31ab20 pop {r3, pc} */

/* ── FUNC 0x31ab24 · _Unwind_GetDataRelBase · size=8 · insn=2 */
/* @0x31ab24 push {r3, lr} */
/* @0x31ab28 bl 0xb6c88 <abort@plt> */

/* ── FUNC 0x31ab2c · _Unwind_GetTextRelBase · size=8 · insn=2 */
/* @0x31ab2c push {r3, lr} */
/* @0x31ab30 bl 0xb6c88 <abort@plt> */

/* ── FUNC 0x31ab34 · __aeabi_dmul · size=620 · insn=155 */
/* @0x31ab34 push {r4, r5, r6, lr} */
/* @0x31ab38 mov r12, #255 */
/* @0x31ab3c orr r12, r12, #1792 */
/* @0x31ab40 ands r4, r12, r1, lsr #20 */
/* @0x31ab44 andsne r5, r12, r3, lsr #20 */
/* @0x31ab48 teqne r4, r12 */
/* @0x31ab4c teqne r5, r12 */
/* @0x31ab50 bleq 0x31ad14 <__muldf3+0x1e0> */
/* @0x31ab54 add r4, r4, r5 */
/* @0x31ab58 eor r6, r1, r3 */
/* @0x31ab5c bic r1, r1, r12, lsl #21 */
/* @0x31ab60 bic r3, r3, r12, lsl #21 */
/* @0x31ab64 orrs r5, r0, r1, lsl #12 */
/* @0x31ab68 orrsne r5, r2, r3, lsl #12 */
/* @0x31ab6c orr r1, r1, #1048576 */
/* @0x31ab70 orr r3, r3, #1048576 */
/* @0x31ab74 beq 0x31abec <__muldf3+0xb8> */
/* @0x31ab78 umull r12, lr, r0, r2 */
/* @0x31ab7c mov r5, #0 */
/* @0x31ab80 umlal lr, r5, r1, r2 */
/* @0x31ab84 and r2, r6, #-2147483648 */
/* @0x31ab88 umlal lr, r5, r0, r3 */
/* @0x31ab8c mov r6, #0 */
/* @0x31ab90 umlal r5, r6, r1, r3 */
/* @0x31ab94 teq r12, #0 */
/* @0x31ab98 orrne lr, lr, #1 */
/* @0x31ab9c sub r4, r4, #255 */
/* @0x31aba0 cmp r6, #512 */
/* @0x31aba4 sbc r4, r4, #768 */
/* @0x31aba8 bhs 0x31abb8 <__muldf3+0x84> */
/* @0x31abac lsls lr, lr, #1 */
/* @0x31abb0 adcs r5, r5, r5 */
/* @0x31abb4 adc r6, r6, r6 */
/* @0x31abb8 orr r1, r2, r6, lsl #11 */
/* @0x31abbc orr r1, r1, r5, lsr #21 */
/* @0x31abc0 lsl r0, r5, #11 */
/* @0x31abc4 orr r0, r0, lr, lsr #21 */
/* @0x31abc8 lsl lr, lr, #11 */
/* @0x31abcc subs r12, r4, #253 */
/* @0x31abd0 cmphi r12, #1792 */
/* @0x31abd4 bhi 0x31ac18 <__muldf3+0xe4> */
/* @0x31abd8 cmp lr, #-2147483648 */
/* @0x31abdc lsrseq lr, r0, #1 */
/* @0x31abe0 adcs r0, r0, #0 */
/* @0x31abe4 adc r1, r1, r4, lsl #20 */
/* @0x31abe8 pop {r4, r5, r6, pc} */
/* @0x31abec and r6, r6, #-2147483648 */
/* @0x31abf0 orr r1, r6, r1 */
/* @0x31abf4 orr r0, r0, r2 */
/* @0x31abf8 eor r1, r1, r3 */
/* @0x31abfc subs r4, r4, r12, lsr #1 */
/* @0x31ac00 rsbsgt r5, r4, r12 */
/* @0x31ac04 orrgt r1, r1, r4, lsl #20 */
/* @0x31ac08 popgt {r4, r5, r6, pc} */
/* @0x31ac0c orr r1, r1, #1048576 */
/* @0x31ac10 mov lr, #0 */
/* @0x31ac14 subs r4, r4, #1 */
/* @0x31ac18 bgt 0x31ad80 <__muldf3+0x24c> */
/* @0x31ac1c cmn r4, #54 */
/* @0x31ac20 movle r0, #0 */
/* @0x31ac24 andle r1, r1, #-2147483648 */
/* @0x31ac28 pople {r4, r5, r6, pc} */
/* @0x31ac2c rsb r4, r4, #0 */
/* @0x31ac30 subs r4, r4, #32 */
/* @0x31ac34 bge 0x31ac9c <__muldf3+0x168> */
/* @0x31ac38 adds r4, r4, #12 */
/* @0x31ac3c bgt 0x31ac70 <__muldf3+0x13c> */
/* @0x31ac40 add r4, r4, #20 */
/* @0x31ac44 rsb r5, r4, #32 */
/* @0x31ac48 lsl r3, r0, r5 */
/* @0x31ac4c lsr r0, r0, r4 */
/* @0x31ac50 orr r0, r0, r1, lsl r5 */
/* @0x31ac54 and r2, r1, #-2147483648 */
/* @0x31ac58 bic r1, r1, #-2147483648 */
/* @0x31ac5c adds r0, r0, r3, lsr #31 */
/* @0x31ac60 adc r1, r2, r1, lsr r4 */
/* @0x31ac64 orrs lr, lr, r3, lsl #1 */
/* @0x31ac68 biceq r0, r0, r3, lsr #31 */
/* @0x31ac6c pop {r4, r5, r6, pc} */
/* @0x31ac70 rsb r4, r4, #12 */
/* @0x31ac74 rsb r5, r4, #32 */
/* @0x31ac78 lsl r3, r0, r4 */
/* @0x31ac7c lsr r0, r0, r5 */
/* @0x31ac80 orr r0, r0, r1, lsl r4 */
/* @0x31ac84 and r1, r1, #-2147483648 */
/* @0x31ac88 adds r0, r0, r3, lsr #31 */
/* @0x31ac8c adc r1, r1, #0 */
/* @0x31ac90 orrs lr, lr, r3, lsl #1 */
/* @0x31ac94 biceq r0, r0, r3, lsr #31 */
/* @0x31ac98 pop {r4, r5, r6, pc} */
/* @0x31ac9c rsb r5, r4, #32 */
/* @0x31aca0 orr lr, lr, r0, lsl r5 */
/* @0x31aca4 lsr r3, r0, r4 */
/* @0x31aca8 orr r3, r3, r1, lsl r5 */
/* @0x31acac lsr r0, r1, r4 */
/* @0x31acb0 and r1, r1, #-2147483648 */
/* @0x31acb4 bic r0, r0, r1, lsr r4 */
/* @0x31acb8 add r0, r0, r3, lsr #31 */
/* @0x31acbc orrs lr, lr, r3, lsl #1 */
/* @0x31acc0 biceq r0, r0, r3, lsr #31 */
/* @0x31acc4 pop {r4, r5, r6, pc} */
/* @0x31acc8 teq r4, #0 */
/* @0x31accc bne 0x31acf4 <__muldf3+0x1c0> */
/* @0x31acd0 and r6, r1, #-2147483648 */
/* @0x31acd4 lsls r0, r0, #1 */
/* @0x31acd8 adc r1, r1, r1 */
/* @0x31acdc tst r1, #1048576 */
/* @0x31ace0 subeq r4, r4, #1 */
/* @0x31ace4 beq 0x31acd4 <__muldf3+0x1a0> */
/* @0x31ace8 orr r1, r1, r6 */
/* @0x31acec teq r5, #0 */
/* @0x31acf0 bxne lr */
/* @0x31acf4 and r6, r3, #-2147483648 */
/* @0x31acf8 lsls r2, r2, #1 */
/* @0x31acfc adc r3, r3, r3 */
/* @0x31ad00 tst r3, #1048576 */
/* @0x31ad04 subeq r5, r5, #1 */
/* @0x31ad08 beq 0x31acf8 <__muldf3+0x1c4> */
/* @0x31ad0c orr r3, r3, r6 */
/* @0x31ad10 bx lr */
/* @0x31ad14 teq r4, r12 */
/* @0x31ad18 and r5, r12, r3, lsr #20 */
/* @0x31ad1c teqne r5, r12 */
/* @0x31ad20 beq 0x31ad40 <__muldf3+0x20c> */
/* @0x31ad24 orrs r6, r0, r1, lsl #1 */
/* @0x31ad28 orrsne r6, r2, r3, lsl #1 */
/* @0x31ad2c bne 0x31acc8 <__muldf3+0x194> */
/* @0x31ad30 eor r1, r1, r3 */
/* @0x31ad34 and r1, r1, #-2147483648 */
/* @0x31ad38 mov r0, #0 */
/* @0x31ad3c pop {r4, r5, r6, pc} */
/* @0x31ad40 orrs r6, r0, r1, lsl #1 */
/* @0x31ad44 moveq r0, r2 */
/* @0x31ad48 moveq r1, r3 */
/* @0x31ad4c orrsne r6, r2, r3, lsl #1 */
/* @0x31ad50 beq 0x31ad94 <__muldf3+0x260> */
/* @0x31ad54 teq r4, r12 */
/* @0x31ad58 bne 0x31ad64 <__muldf3+0x230> */
/* @0x31ad5c orrs r6, r0, r1, lsl #12 */
/* @0x31ad60 bne 0x31ad94 <__muldf3+0x260> */
/* @0x31ad64 teq r5, r12 */
/* @0x31ad68 bne 0x31ad7c <__muldf3+0x248> */
/* @0x31ad6c orrs r6, r2, r3, lsl #12 */
/* @0x31ad70 movne r0, r2 */
/* @0x31ad74 movne r1, r3 */
/* @0x31ad78 bne 0x31ad94 <__muldf3+0x260> */
/* @0x31ad7c eor r1, r1, r3 */
/* @0x31ad80 and r1, r1, #-2147483648 */
/* @0x31ad84 orr r1, r1, #2130706432 */
/* @0x31ad88 orr r1, r1, #15728640 */
/* @0x31ad8c mov r0, #0 */
/* @0x31ad90 pop {r4, r5, r6, pc} */
/* @0x31ad94 orr r1, r1, #2130706432 */
/* @0x31ad98 orr r1, r1, #16252928 */
/* @0x31ad9c pop {r4, r5, r6, pc} */

/* ── FUNC 0x31ab34 · __muldf3 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31ada0 · __aeabi_ddiv · size=516 · insn=129 */
/* @0x31ada0 push {r4, r5, r6, lr} */
/* @0x31ada4 mov r12, #255 */
/* @0x31ada8 orr r12, r12, #1792 */
/* @0x31adac ands r4, r12, r1, lsr #20 */
/* @0x31adb0 andsne r5, r12, r3, lsr #20 */
/* @0x31adb4 teqne r4, r12 */
/* @0x31adb8 teqne r5, r12 */
/* @0x31adbc bleq 0x31af34 <__divdf3+0x194> */
/* @0x31adc0 sub r4, r4, r5 */
/* @0x31adc4 eor lr, r1, r3 */
/* @0x31adc8 orrs r5, r2, r3, lsl #12 */
/* @0x31adcc lsl r1, r1, #12 */
/* @0x31add0 beq 0x31af04 <__divdf3+0x164> */
/* @0x31add4 lsl r3, r3, #12 */
/* @0x31add8 mov r5, #268435456 */
/* @0x31addc orr r3, r5, r3, lsr #4 */
/* @0x31ade0 orr r3, r3, r2, lsr #24 */
/* @0x31ade4 lsl r2, r2, #8 */
/* @0x31ade8 orr r5, r5, r1, lsr #4 */
/* @0x31adec orr r5, r5, r0, lsr #24 */
/* @0x31adf0 lsl r6, r0, #8 */
/* @0x31adf4 and r1, lr, #-2147483648 */
/* @0x31adf8 cmp r5, r3 */
/* @0x31adfc cmpeq r6, r2 */
/* @0x31ae00 adc r4, r4, #253 */
/* @0x31ae04 add r4, r4, #768 */
/* @0x31ae08 bhs 0x31ae14 <__divdf3+0x74> */
/* @0x31ae0c lsrs r3, r3, #1 */
/* @0x31ae10 rrx r2, r2 */
/* @0x31ae14 subs r6, r6, r2 */
/* @0x31ae18 sbc r5, r5, r3 */
/* @0x31ae1c lsrs r3, r3, #1 */
/* @0x31ae20 rrx r2, r2 */
/* @0x31ae24 mov r0, #1048576 */
/* @0x31ae28 mov r12, #524288 */
/* @0x31ae2c subs lr, r6, r2 */
/* @0x31ae30 sbcs lr, r5, r3 */
/* @0x31ae34 subhs r6, r6, r2 */
/* @0x31ae38 movhs r5, lr */
/* @0x31ae3c orrhs r0, r0, r12 */
/* @0x31ae40 lsrs r3, r3, #1 */
/* @0x31ae44 rrx r2, r2 */
/* @0x31ae48 subs lr, r6, r2 */
/* @0x31ae4c sbcs lr, r5, r3 */
/* @0x31ae50 subhs r6, r6, r2 */
/* @0x31ae54 movhs r5, lr */
/* @0x31ae58 orrhs r0, r0, r12, lsr #1 */
/* @0x31ae5c lsrs r3, r3, #1 */
/* @0x31ae60 rrx r2, r2 */
/* @0x31ae64 subs lr, r6, r2 */
/* @0x31ae68 sbcs lr, r5, r3 */
/* @0x31ae6c subhs r6, r6, r2 */
/* @0x31ae70 movhs r5, lr */
/* @0x31ae74 orrhs r0, r0, r12, lsr #2 */
/* @0x31ae78 lsrs r3, r3, #1 */
/* @0x31ae7c rrx r2, r2 */
/* @0x31ae80 subs lr, r6, r2 */
/* @0x31ae84 sbcs lr, r5, r3 */
/* @0x31ae88 subhs r6, r6, r2 */
/* @0x31ae8c movhs r5, lr */
/* @0x31ae90 orrhs r0, r0, r12, lsr #3 */
/* @0x31ae94 orrs lr, r5, r6 */
/* @0x31ae98 beq 0x31aed4 <__divdf3+0x134> */
/* @0x31ae9c lsl r5, r5, #4 */
/* @0x31aea0 orr r5, r5, r6, lsr #28 */
/* @0x31aea4 lsl r6, r6, #4 */
/* @0x31aea8 lsl r3, r3, #3 */
/* @0x31aeac orr r3, r3, r2, lsr #29 */
/* @0x31aeb0 lsl r2, r2, #3 */
/* @0x31aeb4 lsrs r12, r12, #4 */
/* @0x31aeb8 bne 0x31ae2c <__divdf3+0x8c> */
/* @0x31aebc tst r1, #1048576 */
/* @0x31aec0 bne 0x31aee0 <__divdf3+0x140> */
/* @0x31aec4 orr r1, r1, r0 */
/* @0x31aec8 mov r0, #0 */
/* @0x31aecc mov r12, #-2147483648 */
/* @0x31aed0 b 0x31ae2c <__divdf3+0x8c> */
/* @0x31aed4 tst r1, #1048576 */
/* @0x31aed8 orreq r1, r1, r0 */
/* @0x31aedc moveq r0, #0 */
/* @0x31aee0 subs r12, r4, #253 */
/* @0x31aee4 cmphi r12, #1792 */
/* @0x31aee8 bhi 0x31ac18 <__muldf3+0xe4> */
/* @0x31aeec subs r12, r5, r3 */
/* @0x31aef0 subseq r12, r6, r2 */
/* @0x31aef4 lsrseq r12, r0, #1 */
/* @0x31aef8 adcs r0, r0, #0 */
/* @0x31aefc adc r1, r1, r4, lsl #20 */
/* @0x31af00 pop {r4, r5, r6, pc} */
/* @0x31af04 and lr, lr, #-2147483648 */
/* @0x31af08 orr r1, lr, r1, lsr #12 */
/* @0x31af0c adds r4, r4, r12, lsr #1 */
/* @0x31af10 rsbsgt r5, r4, r12 */
/* @0x31af14 orrgt r1, r1, r4, lsl #20 */
/* @0x31af18 popgt {r4, r5, r6, pc} */
/* @0x31af1c orr r1, r1, #1048576 */
/* @0x31af20 mov lr, #0 */
/* @0x31af24 subs r4, r4, #1 */
/* @0x31af28 b 0x31ac18 <__muldf3+0xe4> */
/* @0x31af2c orr lr, r5, r6 */
/* @0x31af30 b 0x31ac18 <__muldf3+0xe4> */
/* @0x31af34 and r5, r12, r3, lsr #20 */
/* @0x31af38 teq r4, r12 */
/* @0x31af3c teqeq r5, r12 */
/* @0x31af40 beq 0x31ad94 <__muldf3+0x260> */
/* @0x31af44 teq r4, r12 */
/* @0x31af48 bne 0x31af68 <__divdf3+0x1c8> */
/* @0x31af4c orrs r4, r0, r1, lsl #12 */
/* @0x31af50 bne 0x31ad94 <__muldf3+0x260> */
/* @0x31af54 teq r5, r12 */
/* @0x31af58 bne 0x31ad7c <__muldf3+0x248> */
/* @0x31af5c mov r0, r2 */
/* @0x31af60 mov r1, r3 */
/* @0x31af64 b 0x31ad94 <__muldf3+0x260> */
/* @0x31af68 teq r5, r12 */
/* @0x31af6c bne 0x31af84 <__divdf3+0x1e4> */
/* @0x31af70 orrs r5, r2, r3, lsl #12 */
/* @0x31af74 beq 0x31ad30 <__muldf3+0x1fc> */
/* @0x31af78 mov r0, r2 */
/* @0x31af7c mov r1, r3 */
/* @0x31af80 b 0x31ad94 <__muldf3+0x260> */
/* @0x31af84 orrs r6, r0, r1, lsl #1 */
/* @0x31af88 orrsne r6, r2, r3, lsl #1 */
/* @0x31af8c bne 0x31acc8 <__muldf3+0x194> */
/* @0x31af90 orrs r4, r0, r1, lsl #1 */
/* @0x31af94 bne 0x31ad7c <__muldf3+0x248> */
/* @0x31af98 orrs r5, r2, r3, lsl #1 */
/* @0x31af9c bne 0x31ad30 <__muldf3+0x1fc> */
/* @0x31afa0 b 0x31ad94 <__muldf3+0x260> */

/* ── FUNC 0x31ada0 · __divdf3 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31afa4 · __gedf2 · size=152 · insn=2 */
/* @0x31afa4 mvn r12, #0 */
/* @0x31afa8 b 0x31afb8 <__nedf2+0x4> */

/* ── FUNC 0x31afa4 · __gtdf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31afac · __ledf2 · size=144 · insn=2 */
/* @0x31afac mov r12, #1 */
/* @0x31afb0 b 0x31afb8 <__nedf2+0x4> */

/* ── FUNC 0x31afac · __ltdf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31afb4 · __cmpdf2 · size=136 · insn=34 */
/* @0x31afb4 mov r12, #1 */
/* @0x31afb8 str r12, [sp, #-0x4]! */
/* @0x31afbc lsl r12, r1, #1 */
/* @0x31afc0 mvns r12, r12, asr #21 */
/* @0x31afc4 lsl r12, r3, #1 */
/* @0x31afc8 mvnsne r12, r12, asr #21 */
/* @0x31afcc beq 0x31b00c <__nedf2+0x58> */
/* @0x31afd0 add sp, sp, #4 */
/* @0x31afd4 orrs r12, r0, r1, lsl #1 */
/* @0x31afd8 orrseq r12, r2, r3, lsl #1 */
/* @0x31afdc teqne r1, r3 */
/* @0x31afe0 teqeq r0, r2 */
/* @0x31afe4 moveq r0, #0 */
/* @0x31afe8 bxeq lr */
/* @0x31afec cmn r0, #0 */
/* @0x31aff0 teq r1, r3 */
/* @0x31aff4 cmppl r1, r3 */
/* @0x31aff8 cmpeq r0, r2 */
/* @0x31affc asrhs r0, r3, #31 */
/* @0x31b000 mvnlo r0, r3, asr #31 */
/* @0x31b004 orr r0, r0, #1 */
/* @0x31b008 bx lr */
/* @0x31b00c lsl r12, r1, #1 */
/* @0x31b010 mvns r12, r12, asr #21 */
/* @0x31b014 bne 0x31b020 <__nedf2+0x6c> */
/* @0x31b018 orrs r12, r0, r1, lsl #12 */
/* @0x31b01c bne 0x31b034 <__nedf2+0x80> */
/* @0x31b020 lsl r12, r3, #1 */
/* @0x31b024 mvns r12, r12, asr #21 */
/* @0x31b028 bne 0x31afd0 <__nedf2+0x1c> */
/* @0x31b02c orrs r12, r2, r3, lsl #12 */
/* @0x31b030 beq 0x31afd0 <__nedf2+0x1c> */
/* @0x31b034 ldr r0, [sp], #4 */
/* @0x31b038 bx lr */

/* ── FUNC 0x31afb4 · __eqdf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31afb4 · __nedf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b03c · __aeabi_cdrcmple · size=48 · insn=7 */
/* @0x31b03c mov r12, r0 */
/* @0x31b040 mov r0, r2 */
/* @0x31b044 mov r2, r12 */
/* @0x31b048 mov r12, r1 */
/* @0x31b04c mov r1, r3 */
/* @0x31b050 mov r3, r12 */
/* @0x31b054 b 0x31b058 <__aeabi_cdcmple> */

/* ── FUNC 0x31b058 · __aeabi_cdcmpeq · size=20 · insn=5 */
/* @0x31b058 push {r0, lr} */
/* @0x31b05c bl 0x31afb4 <__nedf2> */
/* @0x31b060 cmp r0, #0 */
/* @0x31b064 cmnmi r0, #0 */
/* @0x31b068 pop {r0, pc} */

/* ── FUNC 0x31b058 · __aeabi_cdcmple · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b06c · __aeabi_dcmpeq · size=20 · insn=5 */
/* @0x31b06c str lr, [sp, #-0x8]! */
/* @0x31b070 bl 0x31b058 <__aeabi_cdcmple> */
/* @0x31b074 moveq r0, #1 */
/* @0x31b078 movne r0, #0 */
/* @0x31b07c ldr pc, [sp], #8 */

/* ── FUNC 0x31b080 · __aeabi_dcmplt · size=20 · insn=5 */
/* @0x31b080 str lr, [sp, #-0x8]! */
/* @0x31b084 bl 0x31b058 <__aeabi_cdcmple> */
/* @0x31b088 movlo r0, #1 */
/* @0x31b08c movhs r0, #0 */
/* @0x31b090 ldr pc, [sp], #8 */

/* ── FUNC 0x31b094 · __aeabi_dcmple · size=20 · insn=5 */
/* @0x31b094 str lr, [sp, #-0x8]! */
/* @0x31b098 bl 0x31b058 <__aeabi_cdcmple> */
/* @0x31b09c movls r0, #1 */
/* @0x31b0a0 movhi r0, #0 */
/* @0x31b0a4 ldr pc, [sp], #8 */

/* ── FUNC 0x31b0a8 · __aeabi_dcmpge · size=20 · insn=5 */
/* @0x31b0a8 str lr, [sp, #-0x8]! */
/* @0x31b0ac bl 0x31b03c <__aeabi_cdrcmple> */
/* @0x31b0b0 movls r0, #1 */
/* @0x31b0b4 movhi r0, #0 */
/* @0x31b0b8 ldr pc, [sp], #8 */

/* ── FUNC 0x31b0bc · __aeabi_dcmpgt · size=20 · insn=5 */
/* @0x31b0bc str lr, [sp, #-0x8]! */
/* @0x31b0c0 bl 0x31b03c <__aeabi_cdrcmple> */
/* @0x31b0c4 movlo r0, #1 */
/* @0x31b0c8 movhs r0, #0 */
/* @0x31b0cc ldr pc, [sp], #8 */

/* ── FUNC 0x31b0d0 · __aeabi_d2uiz · size=84 · insn=21 */
/* @0x31b0d0 lsls r2, r1, #1 */
/* @0x31b0d4 bhs 0x31b104 <__fixunsdfsi+0x34> */
/* @0x31b0d8 adds r2, r2, #2097152 */
/* @0x31b0dc bhs 0x31b10c <__fixunsdfsi+0x3c> */
/* @0x31b0e0 bpl 0x31b104 <__fixunsdfsi+0x34> */
/* @0x31b0e4 mvn r3, #992 */
/* @0x31b0e8 subs r2, r3, r2, asr #21 */
/* @0x31b0ec bmi 0x31b114 <__fixunsdfsi+0x44> */
/* @0x31b0f0 lsl r3, r1, #11 */
/* @0x31b0f4 orr r3, r3, #-2147483648 */
/* @0x31b0f8 orr r3, r3, r0, lsr #21 */
/* @0x31b0fc lsr r0, r3, r2 */
/* @0x31b100 bx lr */
/* @0x31b104 mov r0, #0 */
/* @0x31b108 bx lr */
/* @0x31b10c orrs r0, r0, r1, lsl #12 */
/* @0x31b110 bne 0x31b11c <__fixunsdfsi+0x4c> */
/* @0x31b114 mvn r0, #0 */
/* @0x31b118 bx lr */
/* @0x31b11c mov r0, #0 */
/* @0x31b120 bx lr */

/* ── FUNC 0x31b0d0 · __fixunsdfsi · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b124 · __gesf2 · size=116 · insn=2 */
/* @0x31b124 mvn r12, #0 */
/* @0x31b128 b 0x31b138 <__nesf2+0x4> */

/* ── FUNC 0x31b124 · __gtsf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b12c · __lesf2 · size=108 · insn=2 */
/* @0x31b12c mov r12, #1 */
/* @0x31b130 b 0x31b138 <__nesf2+0x4> */

/* ── FUNC 0x31b12c · __ltsf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b134 · __cmpsf2 · size=100 · insn=25 */
/* @0x31b134 mov r12, #1 */
/* @0x31b138 str r12, [sp, #-0x4]! */
/* @0x31b13c lsl r2, r0, #1 */
/* @0x31b140 lsl r3, r1, #1 */
/* @0x31b144 mvns r12, r2, asr #24 */
/* @0x31b148 mvnsne r12, r3, asr #24 */
/* @0x31b14c beq 0x31b170 <__nesf2+0x3c> */
/* @0x31b150 add sp, sp, #4 */
/* @0x31b154 orrs r12, r2, r3, lsr #1 */
/* @0x31b158 teqne r0, r1 */
/* @0x31b15c subspl r0, r2, r3 */
/* @0x31b160 asrhi r0, r1, #31 */
/* @0x31b164 mvnlo r0, r1, asr #31 */
/* @0x31b168 orrne r0, r0, #1 */
/* @0x31b16c bx lr */
/* @0x31b170 mvns r12, r2, asr #24 */
/* @0x31b174 bne 0x31b180 <__nesf2+0x4c> */
/* @0x31b178 lsls r12, r0, #9 */
/* @0x31b17c bne 0x31b190 <__nesf2+0x5c> */
/* @0x31b180 mvns r12, r3, asr #24 */
/* @0x31b184 bne 0x31b150 <__nesf2+0x1c> */
/* @0x31b188 lsls r12, r1, #9 */
/* @0x31b18c beq 0x31b150 <__nesf2+0x1c> */
/* @0x31b190 ldr r0, [sp], #4 */
/* @0x31b194 bx lr */
