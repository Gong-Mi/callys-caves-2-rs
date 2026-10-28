/* libyoyo.so 覆盖卡组 0154
 * 函数 0x1cb774..0x1cdf6c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1cb774 · anon_1cb774 · size=4 · insn=1 */
/* @0x1cb774 andeq r0, r0, r0 */

/* ── FUNC 0x1cb778 · INITIALIZE_Run_Global() · size=732 · insn=183 */
/* @0x1cb778 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1cb77c sub sp, sp, #20 */
/* @0x1cb780 ldr r4, [pc, #0x248] */
/* @0x1cb784 mov r5, #0 */
/* @0x1cb788 ldr r1, [pc, #0x244] */
/* @0x1cb78c mov r0, #12 */
/* @0x1cb790 add r4, pc, r4 */
/* @0x1cb794 ldr r2, [pc, #0x23c] */
/* @0x1cb798 ldr r3, [pc, #0x23c] */
/* @0x1cb79c mov r8, #8 */
/* @0x1cb7a0 ldr r1, [r4, r1] */
/* @0x1cb7a4 mov r6, #1 */
/* @0x1cb7a8 ldr r10, [pc, #0x230] */
/* @0x1cb7ac movw r11, #0xdead */
/* @0x1cb7b0 ldr r9, [pc, #0x22c] */
/* @0x1cb7b4 movt r11, #0xfeee */
/* @0x1cb7b8 str r1, [sp, #0x4] */
/* @0x1cb7bc str r5, [r1] */
/* @0x1cb7c0 ldr r2, [r4, r2] */
/* @0x1cb7c4 str r2, [sp, #0x8] */
/* @0x1cb7c8 str r5, [r2] */
/* @0x1cb7cc ldr r3, [r4, r3] */
/* @0x1cb7d0 str r3, [sp, #0xc] */
/* @0x1cb7d4 str r5, [r3] */
/* @0x1cb7d8 bl 0x27c524 <_Znwj> */
/* @0x1cb7dc mov r7, r0 */
/* @0x1cb7e0 ldr r0, [pc, #0x200] */
/* @0x1cb7e4 str r8, [r7, #0x8] */
/* @0x1cb7e8 add r0, pc, r0 */
/* @0x1cb7ec bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1cb7f0 ldr r1, [sp, #0x4] */
/* @0x1cb7f4 stm r7, {r0, r6} */
/* @0x1cb7f8 mov r0, #12 */
/* @0x1cb7fc str r7, [r1] */
/* @0x1cb800 bl 0x27c524 <_Znwj> */
/* @0x1cb804 mov r3, #7 */
/* @0x1cb808 mov r7, r0 */
/* @0x1cb80c ldr r0, [pc, #0x1d8] */
/* @0x1cb810 str r3, [r7, #0x8] */
/* @0x1cb814 add r0, pc, r0 */
/* @0x1cb818 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1cb81c ldr r2, [sp, #0x8] */
/* @0x1cb820 stm r7, {r0, r6} */
/* @0x1cb824 mov r0, #12 */
/* @0x1cb828 str r7, [r2] */
/* @0x1cb82c bl 0x27c524 <_Znwj> */
/* @0x1cb830 mov r7, r0 */
/* @0x1cb834 ldr r0, [pc, #0x1b4] */
/* @0x1cb838 str r8, [r7, #0x8] */
/* @0x1cb83c add r0, pc, r0 */
/* @0x1cb840 ldr r8, [pc, #0x1ac] */
/* @0x1cb844 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1cb848 str r6, [r7, #0x4] */
/* @0x1cb84c ldr r12, [pc, #0x1a4] */
/* @0x1cb850 mvn r3, #0 */
/* @0x1cb854 ldr r1, [pc, #0x1a0] */
/* @0x1cb858 vldr d7, [pc, #360] */
/* @0x1cb85c ldr r2, [pc, #0x19c] */
/* @0x1cb860 str r0, [r7] */
/* @0x1cb864 ldr r0, [sp, #0xc] */
/* @0x1cb868 str r7, [r0] */
/* @0x1cb86c ldr r0, [r4, r10] */
/* @0x1cb870 ldr r10, [pc, #0x18c] */
/* @0x1cb874 ldr r7, [pc, #0x18c] */
/* @0x1cb878 strb r5, [r0] */
/* @0x1cb87c ldr r0, [r4, r9] */
/* @0x1cb880 ldr r9, [sp, #0x8] */
/* @0x1cb884 strb r5, [r0] */
/* @0x1cb888 ldr r0, [r4, r8] */
/* @0x1cb88c ldr r8, [pc, #0x178] */
/* @0x1cb890 strb r5, [r0] */
/* @0x1cb894 ldr r0, [r4, r12] */
/* @0x1cb898 ldr r12, [pc, #0x170] */
/* @0x1cb89c str r5, [r0] */
/* @0x1cb8a0 ldr r1, [r4, r1] */
/* @0x1cb8a4 str r5, [r1] */
/* @0x1cb8a8 ldr r2, [r4, r2] */
/* @0x1cb8ac ldr r1, [sp, #0x4] */
/* @0x1cb8b0 strb r6, [r2] */
/* @0x1cb8b4 ldr r2, [pc, #0x158] */
/* @0x1cb8b8 ldr r2, [r4, r2] */
/* @0x1cb8bc str r5, [r1] */
/* @0x1cb8c0 ldr r1, [pc, #0x150] */
/* @0x1cb8c4 strb r5, [r2] */
/* @0x1cb8c8 ldr r2, [pc, #0x14c] */
/* @0x1cb8cc ldr r2, [r4, r2] */
/* @0x1cb8d0 str r3, [r2] */
/* @0x1cb8d4 ldr r2, [pc, #0x144] */
/* @0x1cb8d8 ldr r2, [r4, r2] */
/* @0x1cb8dc str r5, [r9] */
/* @0x1cb8e0 strb r5, [r2] */
/* @0x1cb8e4 ldr r2, [pc, #0x138] */
/* @0x1cb8e8 ldr r2, [r4, r2] */
/* @0x1cb8ec vstr d7, [r2] */
/* @0x1cb8f0 ldr r2, [pc, #0x130] */
/* @0x1cb8f4 ldr r0, [r4, r2] */
/* @0x1cb8f8 ldr r2, [pc, #0x12c] */
/* @0x1cb8fc strb r5, [r0] */
/* @0x1cb900 ldr r0, [pc, #0x128] */
/* @0x1cb904 ldr r0, [r4, r0] */
/* @0x1cb908 str r12, [sp, #0x8] */
/* @0x1cb90c ldr r12, [pc, #0x120] */
/* @0x1cb910 str r5, [r0] */
/* @0x1cb914 ldr r0, [pc, #0x11c] */
/* @0x1cb918 ldr r0, [r4, r0] */
/* @0x1cb91c strb r5, [r0] */
/* @0x1cb920 ldr r0, [pc, #0x114] */
/* @0x1cb924 ldr r0, [r4, r0] */
/* @0x1cb928 str r3, [r0] */
/* @0x1cb92c ldr r0, [pc, #0x10c] */
/* @0x1cb930 ldr r0, [r4, r0] */
/* @0x1cb934 str r5, [r0] */
/* @0x1cb938 ldr r0, [pc, #0x104] */
/* @0x1cb93c ldr r0, [r4, r0] */
/* @0x1cb940 str r0, [sp, #0x4] */
/* @0x1cb944 ldr r9, [sp, #0x4] */
/* @0x1cb948 ldr r0, [pc, #0xf8] */
/* @0x1cb94c strb r6, [r9] */
/* @0x1cb950 ldr r1, [r4, r1] */
/* @0x1cb954 str r1, [sp, #0x4] */
/* @0x1cb958 ldr r9, [sp, #0x4] */
/* @0x1cb95c ldr r1, [pc, #0xe8] */
/* @0x1cb960 str r5, [r9] */
/* @0x1cb964 ldr r2, [r4, r2] */
/* @0x1cb968 str r2, [sp, #0x4] */
/* @0x1cb96c ldr r9, [sp, #0x4] */
/* @0x1cb970 ldr r2, [pc, #0xd8] */
/* @0x1cb974 str r11, [r9] */
/* @0x1cb978 ldr r9, [sp, #0x8] */
/* @0x1cb97c ldr r10, [r4, r10] */
/* @0x1cb980 str r3, [r10] */
/* @0x1cb984 ldr r9, [r4, r9] */
/* @0x1cb988 str r3, [r9] */
/* @0x1cb98c ldr r8, [r4, r8] */
/* @0x1cb990 strb r6, [r8] */
/* @0x1cb994 ldr r6, [r4, r7] */
/* @0x1cb998 str r3, [r6] */
/* @0x1cb99c ldr r12, [r4, r12] */
/* @0x1cb9a0 str r3, [r12] */
/* @0x1cb9a4 ldr r0, [r4, r0] */
/* @0x1cb9a8 strb r5, [r0] */
/* @0x1cb9ac ldr r1, [r4, r1] */
/* @0x1cb9b0 str r5, [r1] */
/* @0x1cb9b4 ldr r2, [r4, r2] */
/* @0x1cb9b8 str r3, [r2] */
/* @0x1cb9bc add sp, sp, #20 */
/* @0x1cb9c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1cb9c4 nop */
/* @0x1cb9c8 andeq r0, r0, r0 */
/* @0x1cb9cc subsmi r0, r9, r0 */
/* @0x1cb9d0 eoreq r6, r2, r0, asr #9 */
/* @0x1cb9d4 .word 0xffffd9a0 */
/* @0x1cb9d8 .word 0xffffd9a8 */
/* @0x1cb9dc .word 0xffffd9b0 */
/* @0x1cb9e0 .word 0xffffeebc */
/* @0x1cb9e4 .word 0xffffdfa0 */
/* @0x1cb9e8 andseq r5, r8, r12, asr #11 */
/* @0x1cb9ec andseq r5, r8, r12, lsr #11 */
/* @0x1cb9f0 andseq r5, r8, r12, lsl #11 */
/* @0x1cb9f4 .word 0xffffeec0 */
/* @0x1cb9f8 .word 0xffffc458 */
/* @0x1cb9fc .word 0xffffce34 */
/* @0x1cba00 .word 0xffffd99c */
/* @0x1cba04 .word 0xffffdf38 */
/* @0x1cba08 .word 0xffffc990 */
/* @0x1cba0c .word 0xffffdf34 */
/* @0x1cba10 .word 0xffffdf40 */
/* @0x1cba14 .word 0xffffd998 */
/* @0x1cba18 .word 0xffffeec4 */
/* @0x1cba1c .word 0xffffd780 */
/* @0x1cba20 .word 0xffffd9a4 */
/* @0x1cba24 .word 0xffffd788 */
/* @0x1cba28 .word 0xffffd9ac */
/* @0x1cba2c .word 0xffffc988 */
/* @0x1cba30 .word 0xffffc980 */
/* @0x1cba34 .word 0xffffc994 */
/* @0x1cba38 .word 0xffffd658 */
/* @0x1cba3c .word 0xffffd798 */
/* @0x1cba40 .word 0xffffebf0 */
/* @0x1cba44 .word 0xffffc974 */
/* @0x1cba48 .word 0xffffc98c */
/* @0x1cba4c .word 0xffffebec */
/* @0x1cba50 .word 0xffffeec8 */

/* ── FUNC 0x1cba54 · anon_1cba54 · size=4 · insn=1 */
/* @0x1cba54 nop */

/* ── FUNC 0x1cba58 · Run_Room_Set(CRoom*) · size=20 · insn=5 */
/* @0x1cba58 ldr r3, [pc, #0x8] */
/* @0x1cba5c ldr r3, [pc, r3] */
/* @0x1cba60 str r0, [r3] */
/* @0x1cba64 bx lr */
/* @0x1cba68 eoreq r1, r2, r12, asr #29 */

/* ── FUNC 0x1cba6c · FINALIZE_Run_Global() · size=420 · insn=105 */
/* @0x1cba6c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1cba70 mov r5, #0 */
/* @0x1cba74 ldr r4, [pc, #0x148] */
/* @0x1cba78 mov r8, #1 */
/* @0x1cba7c ldr r3, [pc, #0x144] */
/* @0x1cba80 add r4, pc, r4 */
/* @0x1cba84 ldr r11, [pc, #0x140] */
/* @0x1cba88 ldr r10, [pc, #0x140] */
/* @0x1cba8c ldr r6, [r4, r3] */
/* @0x1cba90 ldr r9, [pc, #0x13c] */
/* @0x1cba94 ldr r7, [pc, #0x13c] */
/* @0x1cba98 ldr r0, [r6] */
/* @0x1cba9c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1cbaa0 ldr r3, [pc, #0x134] */
/* @0x1cbaa4 str r5, [r6] */
/* @0x1cbaa8 ldr r6, [r4, r3] */
/* @0x1cbaac ldr r0, [r6] */
/* @0x1cbab0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1cbab4 ldr r3, [pc, #0x124] */
/* @0x1cbab8 str r5, [r6] */
/* @0x1cbabc ldr r6, [r4, r3] */
/* @0x1cbac0 ldr r0, [r6] */
/* @0x1cbac4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1cbac8 ldr r3, [pc, #0x114] */
/* @0x1cbacc str r5, [r6] */
/* @0x1cbad0 ldr r6, [r4, r3] */
/* @0x1cbad4 ldr r0, [r6] */
/* @0x1cbad8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1cbadc ldr r3, [pc, #0x104] */
/* @0x1cbae0 str r5, [r6] */
/* @0x1cbae4 ldr r6, [r4, r3] */
/* @0x1cbae8 ldr r0, [r6] */
/* @0x1cbaec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1cbaf0 ldr r3, [pc, #0xf4] */
/* @0x1cbaf4 str r5, [r6] */
/* @0x1cbaf8 ldr r6, [r4, r3] */
/* @0x1cbafc ldr r0, [r6] */
/* @0x1cbb00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1cbb04 ldr r2, [pc, #0xe4] */
/* @0x1cbb08 str r5, [r6] */
/* @0x1cbb0c movw r1, #0xdead */
/* @0x1cbb10 ldr r3, [pc, #0xdc] */
/* @0x1cbb14 movt r1, #0xfeee */
/* @0x1cbb18 ldr r0, [r4, r2] */
/* @0x1cbb1c mvn r2, #0 */
/* @0x1cbb20 ldr r12, [pc, #0xd0] */
/* @0x1cbb24 ldr r6, [pc, #0xd0] */
/* @0x1cbb28 str r5, [r0] */
/* @0x1cbb2c ldr r0, [r4, r3] */
/* @0x1cbb30 mov r3, r0 */
/* @0x1cbb34 str r5, [r3], #4 */
/* @0x1cbb38 add r3, r3, #4 */
/* @0x1cbb3c str r5, [r0, #0x4] */
/* @0x1cbb40 str r5, [r3], #4 */
/* @0x1cbb44 str r5, [r3] */
/* @0x1cbb48 ldr r3, [r4, r12] */
/* @0x1cbb4c ldr r12, [pc, #0xac] */
/* @0x1cbb50 ldr r0, [pc, #0xac] */
/* @0x1cbb54 str r1, [r3] */
/* @0x1cbb58 ldr r3, [r4, r11] */
/* @0x1cbb5c ldr r1, [pc, #0xa4] */
/* @0x1cbb60 str r2, [r3] */
/* @0x1cbb64 ldr r10, [r4, r10] */
/* @0x1cbb68 ldr r3, [pc, #0x9c] */
/* @0x1cbb6c str r2, [r10] */
/* @0x1cbb70 ldr r9, [r4, r9] */
/* @0x1cbb74 strb r8, [r9] */
/* @0x1cbb78 ldr r7, [r4, r7] */
/* @0x1cbb7c str r2, [r7] */
/* @0x1cbb80 ldr r6, [r4, r6] */
/* @0x1cbb84 str r2, [r6] */
/* @0x1cbb88 ldr r12, [r4, r12] */
/* @0x1cbb8c strb r5, [r12] */
/* @0x1cbb90 ldr r0, [r4, r0] */
/* @0x1cbb94 str r5, [r0] */
/* @0x1cbb98 ldr r1, [r4, r1] */
/* @0x1cbb9c str r2, [r1] */
/* @0x1cbba0 ldr r4, [r4, r3] */
/* @0x1cbba4 ldr r0, [r4] */
/* @0x1cbba8 cmp r0, r5 */
/* @0x1cbbac beq 0x1cbbb4 <_Z19FINALIZE_Run_Globalv+0x148> */
/* @0x1cbbb0 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0x1cbbb4 mov r3, #0 */
/* @0x1cbbb8 str r3, [r4] */
/* @0x1cbbbc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1cbbc0 b 0x191794 <_ZN12YYObjectBase7FreeAllEv> */
/* @0x1cbbc4 .word 0x002261d0 */
/* @0x1cbbc8 .word 0xffffd9a0 */
/* @0x1cbbcc .word 0xffffdf38 */
/* @0x1cbbd0 .word 0xffffdf40 */
/* @0x1cbbd4 .word 0xffffdf34 */
/* @0x1cbbd8 .word 0xffffc990 */
/* @0x1cbbdc .word 0xffffd9a8 */
/* @0x1cbbe0 .word 0xffffd9b0 */
/* @0x1cbbe4 .word 0xffffeecc */
/* @0x1cbbe8 .word 0xffffeed0 */
/* @0x1cbbec .word 0xffffea08 */
/* @0x1cbbf0 .word 0xffffeec4 */
/* @0x1cbbf4 .word 0xffffeed4 */
/* @0x1cbbf8 .word 0xffffc988 */
/* @0x1cbbfc .word 0xffffc994 */
/* @0x1cbc00 .word 0xffffc98c */
/* @0x1cbc04 .word 0xffffebec */
/* @0x1cbc08 .word 0xffffeec8 */
/* @0x1cbc0c .word 0xffffbf64 */

/* ── FUNC 0x1cbc10 · anon_1cbc10 · size=476 · insn=119 */
/* @0x1cbc10 ldr r2, [r0] */
/* @0x1cbc14 ldr r3, [r1, #0x8] */
/* @0x1cbc18 cmp r2, r3 */
/* @0x1cbc1c bgt 0x1cbc58 <_Z19FINALIZE_Run_Globalv+0x1ec> */
/* @0x1cbc20 ldr r2, [r1] */
/* @0x1cbc24 ldr r3, [r0, #0x8] */
/* @0x1cbc28 cmp r2, r3 */
/* @0x1cbc2c bgt 0x1cbc58 <_Z19FINALIZE_Run_Globalv+0x1ec> */
/* @0x1cbc30 ldr r2, [r0, #0x4] */
/* @0x1cbc34 ldr r3, [r1, #0xc] */
/* @0x1cbc38 cmp r2, r3 */
/* @0x1cbc3c bgt 0x1cbc58 <_Z19FINALIZE_Run_Globalv+0x1ec> */
/* @0x1cbc40 ldr r3, [r0, #0xc] */
/* @0x1cbc44 ldr r2, [r1, #0x4] */
/* @0x1cbc48 cmp r2, r3 */
/* @0x1cbc4c movgt r0, #0 */
/* @0x1cbc50 movle r0, #1 */
/* @0x1cbc54 bx lr */
/* @0x1cbc58 mov r0, #0 */
/* @0x1cbc5c bx lr */
/* @0x1cbc60 add r3, r1, #8 */
/* @0x1cbc64 mov r12, r1 */
/* @0x1cbc68 push {r4, r5, r6, r7, r8, r9, r10} */
/* @0x1cbc6c mov r9, r0 */
/* @0x1cbc70 ldr r8, [r1] */
/* @0x1cbc74 ldm r3, {r0, r1, r2, r3} */
/* @0x1cbc78 cmp r8, #1 */
/* @0x1cbc7c stm r9, {r0, r1, r2, r3} */
/* @0x1cbc80 ble 0x1cbce8 <_Z19FINALIZE_Run_Globalv+0x27c> */
/* @0x1cbc84 add r12, r12, #32 */
/* @0x1cbc88 mov r5, r0 */
/* @0x1cbc8c mov r4, #1 */
/* @0x1cbc90 ldmib r12, {r0, r7} */
/* @0x1cbc94 add r4, r4, #1 */
/* @0x1cbc98 ldr r10, [r12] */
/* @0x1cbc9c add r12, r12, #24 */
/* @0x1cbca0 ldr r6, [r12, #-0xc] */
/* @0x1cbca4 cmp r7, r2 */
/* @0x1cbca8 movlt r7, r2 */
/* @0x1cbcac cmp r10, r5 */
/* @0x1cbcb0 movge r10, r5 */
/* @0x1cbcb4 cmp r0, r1 */
/* @0x1cbcb8 movge r0, r1 */
/* @0x1cbcbc cmp r6, r3 */
/* @0x1cbcc0 movlt r6, r3 */
/* @0x1cbcc4 cmp r4, r8 */
/* @0x1cbcc8 mov r5, r10 */
/* @0x1cbccc mov r1, r0 */
/* @0x1cbcd0 mov r2, r7 */
/* @0x1cbcd4 mov r3, r6 */
/* @0x1cbcd8 bne 0x1cbc90 <_Z19FINALIZE_Run_Globalv+0x224> */
/* @0x1cbcdc str r10, [r9] */
/* @0x1cbce0 stmib r9, {r0, r7} */
/* @0x1cbce4 str r6, [r9, #0xc] */
/* @0x1cbce8 mov r0, r9 */
/* @0x1cbcec pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0x1cbcf0 bx lr */
/* @0x1cbcf4 add r12, r2, r1, lsl #2 */
/* @0x1cbcf8 push {r4, r5, r6, r7} */
/* @0x1cbcfc str r1, [r2, r0, lsl #2] */
/* @0x1cbd00 add r0, r0, r0, lsl #1 */
/* @0x1cbd04 ldr r3, [r12, #0x24] */
/* @0x1cbd08 cmp r3, #0 */
/* @0x1cbd0c beq 0x1cbdb4 <_Z19FINALIZE_Run_Globalv+0x348> */
/* @0x1cbd10 add r1, r2, r1, lsl #4 */
/* @0x1cbd14 add r2, r2, r0, lsl #3 */
/* @0x1cbd18 add r4, r2, #84 */
/* @0x1cbd1c add r2, r2, #80 */
/* @0x1cbd20 ldr r0, [r4, #0x8] */
/* @0x1cbd24 ldr r2, [r2, #0x4] */
/* @0x1cbd28 ldr r6, [r1, #0x34] */
/* @0x1cbd2c ldr r5, [r1, #0x2c] */
/* @0x1cbd30 ldr r7, [r4, #0x4] */
/* @0x1cbd34 cmp r0, r6 */
/* @0x1cbd38 movlt r0, r6 */
/* @0x1cbd3c cmp r5, r2 */
/* @0x1cbd40 movge r5, r2 */
/* @0x1cbd44 ldr r6, [r1, #0x38] */
/* @0x1cbd48 ldr r2, [r4, #0xc] */
/* @0x1cbd4c vmov s11, r0 */
/* @0x1cbd50 ldr r4, [r1, #0x30] */
/* @0x1cbd54 vmov s14, r5 */
/* @0x1cbd58 cmp r2, r6 */
/* @0x1cbd5c movlt r2, r6 */
/* @0x1cbd60 str r5, [r1, #0x2c] */
/* @0x1cbd64 cmp r4, r7 */
/* @0x1cbd68 movge r4, r7 */
/* @0x1cbd6c str r0, [r1, #0x34] */
/* @0x1cbd70 vmov s12, r2 */
/* @0x1cbd74 str r4, [r1, #0x30] */
/* @0x1cbd78 vmov s13, r4 */
/* @0x1cbd7c str r2, [r1, #0x38] */
/* @0x1cbd80 vcvt.f32.s32 s11, s11 */
/* @0x1cbd84 ldr r3, [r12, #0x24] */
/* @0x1cbd88 pop {r4, r5, r6, r7} */
/* @0x1cbd8c add r3, r3, #1 */
/* @0x1cbd90 str r3, [r12, #0x24] */
/* @0x1cbd94 vcvt.f32.s32 s14, s14 */
/* @0x1cbd98 vcvt.f32.s32 s12, s12 */
/* @0x1cbd9c vcvt.f32.s32 s13, s13 */
/* @0x1cbda0 vsub.f32 s14, s11, s14 */
/* @0x1cbda4 vsub.f32 s15, s12, s13 */
/* @0x1cbda8 vmul.f32 s15, s14, s15 */
/* @0x1cbdac vstr s15, [r12, #76] */
/* @0x1cbdb0 bx lr */
/* @0x1cbdb4 add r0, r2, r0, lsl #3 */
/* @0x1cbdb8 lsl r1, r1, #4 */
/* @0x1cbdbc add r0, r0, #84 */
/* @0x1cbdc0 add r6, r1, #40 */
/* @0x1cbdc4 add r1, r2, r1 */
/* @0x1cbdc8 add r6, r2, r6 */
/* @0x1cbdcc add r4, r1, #44 */
/* @0x1cbdd0 ldm r0, {r0, r1, r2, r3} */
/* @0x1cbdd4 stm r4, {r0, r1, r2, r3} */
/* @0x1cbdd8 vldr s14, [r6, #4] */
/* @0x1cbddc vldr s11, [r6, #12] */
/* @0x1cbde0 vldr s12, [r6, #16] */
/* @0x1cbde4 vldr s13, [r6, #8] */
/* @0x1cbde8 b 0x1cbd80 <_Z19FINALIZE_Run_Globalv+0x314> */

/* ── FUNC 0x1cbdec · RTree<CInstance*, int, float, 6, 2>::~RTree() · size=108 · insn=27 */
/* @0x1cbdec push {r4, r5, r6, lr} */
/* @0x1cbdf0 mov r6, r0 */
/* @0x1cbdf4 ldr r5, [r0, #0x4] */
/* @0x1cbdf8 ldr r3, [pc, #0x54] */
/* @0x1cbdfc cmp r5, #0 */
/* @0x1cbe00 ldr r3, [pc, r3] */
/* @0x1cbe04 add r3, r3, #8 */
/* @0x1cbe08 str r3, [r0] */
/* @0x1cbe0c beq 0x1cbe4c <_ZN5RTreeIP9CInstanceifLi6ELi2EED2Ev+0x60> */
/* @0x1cbe10 ldr r3, [r5, #0x8] */
/* @0x1cbe14 cmp r3, #0 */
/* @0x1cbe18 movgt r4, #0 */
/* @0x1cbe1c ble 0x1cbe3c <_ZN5RTreeIP9CInstanceifLi6ELi2EED2Ev+0x50> */
/* @0x1cbe20 ldr r3, [r5, #0x4] */
/* @0x1cbe24 ldr r0, [r3, r4, lsl #2] */
/* @0x1cbe28 add r4, r4, #1 */
/* @0x1cbe2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1cbe30 ldr r3, [r5, #0x8] */
/* @0x1cbe34 cmp r4, r3 */
/* @0x1cbe38 blt 0x1cbe20 <_ZN5RTreeIP9CInstanceifLi6ELi2EED2Ev+0x34> */
/* @0x1cbe3c ldr r0, [r5, #0x4] */
/* @0x1cbe40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1cbe44 mov r0, r5 */
/* @0x1cbe48 bl 0x27d1d0 <_ZdlPv> */
/* @0x1cbe4c mov r0, r6 */
/* @0x1cbe50 pop {r4, r5, r6, pc} */
/* @0x1cbe54 eoreq r4, r2, r12, lsr #26 */

/* ── FUNC 0x1cbdec · RTree<CInstance*, int, float, 6, 2>::~RTree() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1cbe58 · RTree<CInstance*, int, float, 6, 2>::~RTree() · size=28 · insn=7 */
/* @0x1cbe58 push {r4, lr} */
/* @0x1cbe5c mov r4, r0 */
/* @0x1cbe60 bl 0x1cbdec <_ZN5RTreeIP9CInstanceifLi6ELi2EED2Ev> */
/* @0x1cbe64 mov r0, r4 */
/* @0x1cbe68 bl 0x27d1d0 <_ZdlPv> */
/* @0x1cbe6c mov r0, r4 */
/* @0x1cbe70 pop {r4, pc} */

/* ── FUNC 0x1cbe74 · push_back(SCollision) · size=164 · insn=41 */
/* @0x1cbe74 push {r4, r5, r6, lr} */
/* @0x1cbe78 sub sp, sp, #16 */
/* @0x1cbe7c ldr r4, [pc, #0x88] */
/* @0x1cbe80 add r5, sp, #8 */
/* @0x1cbe84 add r4, pc, r4 */
/* @0x1cbe88 stm r5, {r0, r1} */
/* @0x1cbe8c ldm r4, {r2, r3} */
/* @0x1cbe90 cmp r2, r3 */
/* @0x1cbe94 bge 0x1cbec8 <_Z9push_back10SCollision+0x54> */
/* @0x1cbe98 ldr r12, [r4, #0x8] */
/* @0x1cbe9c mov r3, r5 */
/* @0x1cbea0 ldr r4, [pc, #0x68] */
/* @0x1cbea4 ldm r3!, {r0, r1} */
/* @0x1cbea8 add r3, r12, r2, lsl #3 */
/* @0x1cbeac add r4, pc, r4 */
/* @0x1cbeb0 add r5, r2, #1 */
/* @0x1cbeb4 str r0, [r12, r2, lsl #3] */
/* @0x1cbeb8 str r5, [r4] */
/* @0x1cbebc str r1, [r3, #0x4] */
/* @0x1cbec0 add sp, sp, #16 */
/* @0x1cbec4 pop {r4, r5, r6, pc} */
/* @0x1cbec8 cmp r3, #32 */
/* @0x1cbecc movge r12, r3 */
/* @0x1cbed0 movlt r12, #32 */
/* @0x1cbed4 ldr r2, [pc, #0x38] */
/* @0x1cbed8 ldr r0, [r4, #0x8] */
/* @0x1cbedc mov r3, #0 */
/* @0x1cbee0 add r2, pc, r2 */
/* @0x1cbee4 lsl r1, r12, #4 */
/* @0x1cbee8 str r3, [sp] */
/* @0x1cbeec mov r3, #74 */
/* @0x1cbef0 lsl r6, r12, #1 */
/* @0x1cbef4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1cbef8 ldr r2, [r4] */
/* @0x1cbefc str r6, [r4, #0x4] */
/* @0x1cbf00 str r0, [r4, #0x8] */
/* @0x1cbf04 mov r12, r0 */
/* @0x1cbf08 b 0x1cbe9c <_Z9push_back10SCollision+0x28> */
/* @0x1cbf0c eorseq r6, r7, r12, lsl #22 */
/* @0x1cbf10 eorseq r6, r7, r4, ror #21 */
/* @0x1cbf14 andseq r5, r6, r0, asr r1 */

/* ── FUNC 0x1cbf18 · collisionResult(CInstance*, void*) · size=168 · insn=42 */
/* @0x1cbf18 ldr r3, [pc, #0x98] */
/* @0x1cbf1c cmp r0, r1 */
/* @0x1cbf20 push {r4, r5, lr} */
/* @0x1cbf24 ldr r3, [pc, r3] */
/* @0x1cbf28 sub sp, sp, #12 */
/* @0x1cbf2c mov r4, r0 */
/* @0x1cbf30 ldr r2, [r3] */
/* @0x1cbf34 mov r5, r1 */
/* @0x1cbf38 add r2, r2, #1 */
/* @0x1cbf3c str r2, [r3] */
/* @0x1cbf40 beq 0x1cbf8c <_Z15collisionResultP9CInstancePv+0x74> */
/* @0x1cbf44 ldr r3, [r0, #0x80] */
/* @0x1cbf48 mov r1, #4 */
/* @0x1cbf4c ldr r0, [r5, #0x80] */
/* @0x1cbf50 ldr r2, [r3, #0x18] */
/* @0x1cbf54 bl 0x19daf4 <_ZN9CObjectGM17GetEventRecursiveEii> */
/* @0x1cbf58 cmp r0, #0 */
/* @0x1cbf5c beq 0x1cbf98 <_Z15collisionResultP9CInstancePv+0x80> */
/* @0x1cbf60 ldr r3, [pc, #0x54] */
/* @0x1cbf64 ldr r2, [r4, #0x188] */
/* @0x1cbf68 add r3, pc, r3 */
/* @0x1cbf6c ldr r3, [r3, #0xc] */
/* @0x1cbf70 cmp r2, r3 */
/* @0x1cbf74 beq 0x1cbf8c <_Z15collisionResultP9CInstancePv+0x74> */
/* @0x1cbf78 add r3, sp, #8 */
/* @0x1cbf7c str r5, [sp] */
/* @0x1cbf80 str r4, [sp, #0x4] */
/* @0x1cbf84 ldmdb r3, {r0, r1} */
/* @0x1cbf88 bl 0x1cbe74 <_Z9push_back10SCollision> */
/* @0x1cbf8c mov r0, #1 */
/* @0x1cbf90 add sp, sp, #12 */
/* @0x1cbf94 pop {r4, r5, pc} */
/* @0x1cbf98 ldr r3, [r5, #0x80] */
/* @0x1cbf9c mov r1, #4 */
/* @0x1cbfa0 ldr r0, [r4, #0x80] */
/* @0x1cbfa4 ldr r2, [r3, #0x18] */
/* @0x1cbfa8 bl 0x19daf4 <_ZN9CObjectGM17GetEventRecursiveEii> */
/* @0x1cbfac cmp r0, #0 */
/* @0x1cbfb0 bne 0x1cbf60 <_Z15collisionResultP9CInstancePv+0x48> */
/* @0x1cbfb4 b 0x1cbf8c <_Z15collisionResultP9CInstancePv+0x74> */
/* @0x1cbfb8 eoreq r4, r2, r12, lsl #24 */
/* @0x1cbfbc eorseq r6, r7, r8, lsr #20 */

/* ── FUNC 0x1cbfc0 · CollisionMarkTest(CInstance*) · size=116 · insn=29 */
/* @0x1cbfc0 ldr r3, [pc, #0x64] */
/* @0x1cbfc4 ldr r3, [pc, r3] */
/* @0x1cbfc8 ldrb r3, [r3] */
/* @0x1cbfcc cmp r3, #0 */
/* @0x1cbfd0 bxeq lr */
/* @0x1cbfd4 ldr r3, [pc, #0x54] */
/* @0x1cbfd8 add r2, r0, #396 */
/* @0x1cbfdc ldr r1, [r0, #0x194] */
/* @0x1cbfe0 ldr r3, [pc, r3] */
/* @0x1cbfe4 cmp r1, r3 */
/* @0x1cbfe8 ldreq r12, [r0, #0x190] */
/* @0x1cbfec ldreq r1, [r0, #0x18c] */
/* @0x1cbff0 streq r12, [r1, #0x4] */
/* @0x1cbff4 ldreq r12, [r0, #0x190] */
/* @0x1cbff8 streq r1, [r12] */
/* @0x1cbffc mov r12, #0 */
/* @0x1cc000 ldr r1, [r3] */
/* @0x1cc004 str r2, [r0, #0x18c] */
/* @0x1cc008 cmp r2, r1 */
/* @0x1cc00c str r2, [r0, #0x190] */
/* @0x1cc010 str r12, [r0, #0x194] */
/* @0x1cc014 strne r1, [r0, #0x18c] */
/* @0x1cc018 strne r3, [r0, #0x190] */
/* @0x1cc01c strne r2, [r3] */
/* @0x1cc020 strne r2, [r1, #0x4] */
/* @0x1cc024 strne r3, [r0, #0x194] */
/* @0x1cc028 bx lr */
/* @0x1cc02c .word 0x002246bc */
/* @0x1cc030 eoreq r4, r2, r4, asr r11 */

/* ── FUNC 0x1cc034 · processCollision(SCollision*) · size=412 · insn=103 */
/* @0x1cc034 push {r3, r4, r5, lr} */
/* @0x1cc038 mov r2, #1 */
/* @0x1cc03c ldm r0, {r4, r5} */
/* @0x1cc040 mov r0, r4 */
/* @0x1cc044 mov r1, r5 */
/* @0x1cc048 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1cc04c cmp r0, #0 */
/* @0x1cc050 popeq {r3, r4, r5, pc} */
/* @0x1cc054 ldrb r3, [r4, #0x69] */
/* @0x1cc058 cmp r3, #0 */
/* @0x1cc05c popne {r3, r4, r5, pc} */
/* @0x1cc060 ldrb r3, [r5, #0x69] */
/* @0x1cc064 cmp r3, #0 */
/* @0x1cc068 popne {r3, r4, r5, pc} */
/* @0x1cc06c ldr r3, [pc, #0x158] */
/* @0x1cc070 mov r0, r5 */
/* @0x1cc074 ldr r3, [pc, r3] */
/* @0x1cc078 ldr r2, [r3] */
/* @0x1cc07c add r2, r2, #1 */
/* @0x1cc080 str r2, [r3] */
/* @0x1cc084 bl 0x1cbfc0 <_Z17CollisionMarkTestP9CInstance> */
/* @0x1cc088 ldrb r3, [r4, #0x66] */
/* @0x1cc08c cmp r3, #0 */
/* @0x1cc090 bne 0x1cc0a0 <_Z16processCollisionP10SCollision+0x6c> */
/* @0x1cc094 ldrb r3, [r5, #0x66] */
/* @0x1cc098 cmp r3, #0 */
/* @0x1cc09c beq 0x1cc0d8 <_Z16processCollisionP10SCollision+0xa4> */
/* @0x1cc0a0 ldr r2, [r4, #0xc8] */
/* @0x1cc0a4 mov r0, r4 */
/* @0x1cc0a8 ldr r1, [r4, #0xc4] */
/* @0x1cc0ac bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cc0b0 mov r0, r4 */
/* @0x1cc0b4 ldr r1, [r4, #0x130] */
/* @0x1cc0b8 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf> */
/* @0x1cc0bc mov r0, r5 */
/* @0x1cc0c0 ldr r1, [r5, #0xc4] */
/* @0x1cc0c4 ldr r2, [r5, #0xc8] */
/* @0x1cc0c8 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cc0cc mov r0, r5 */
/* @0x1cc0d0 ldr r1, [r5, #0x130] */
/* @0x1cc0d4 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf> */
/* @0x1cc0d8 mov r0, r4 */
/* @0x1cc0dc mov r1, r5 */
/* @0x1cc0e0 mov r2, #4 */
/* @0x1cc0e4 ldr r3, [r5, #0x7c] */
/* @0x1cc0e8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1cc0ec ldr r3, [r4, #0x7c] */
/* @0x1cc0f0 mov r0, r5 */
/* @0x1cc0f4 mov r1, r4 */
/* @0x1cc0f8 mov r2, #4 */
/* @0x1cc0fc bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1cc100 ldrb r3, [r4, #0x66] */
/* @0x1cc104 cmp r3, #0 */
/* @0x1cc108 bne 0x1cc118 <_Z16processCollisionP10SCollision+0xe4> */
/* @0x1cc10c ldrb r3, [r5, #0x66] */
/* @0x1cc110 cmp r3, #0 */
/* @0x1cc114 popeq {r3, r4, r5, pc} */
/* @0x1cc118 mov r0, r4 */
/* @0x1cc11c bl 0x19411c <_ZN9CInstance10Adapt_PathEv> */
/* @0x1cc120 mov r0, r5 */
/* @0x1cc124 bl 0x19411c <_ZN9CInstance10Adapt_PathEv> */
/* @0x1cc128 vldr s13, [r4, #180] */
/* @0x1cc12c vldr s15, [r4, #224] */
/* @0x1cc130 vadd.f32 s15, s13, s15 */
/* @0x1cc134 vldr s14, [r4, #184] */
/* @0x1cc138 mov r0, r4 */
/* @0x1cc13c vmov r1, s15 */
/* @0x1cc140 vldr s15, [r4, #228] */
/* @0x1cc144 vadd.f32 s15, s14, s15 */
/* @0x1cc148 vmov r2, s15 */
/* @0x1cc14c bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cc150 vldr s12, [r5, #180] */
/* @0x1cc154 vldr s14, [r5, #184] */
/* @0x1cc158 vldr s13, [r5, #224] */
/* @0x1cc15c vldr s15, [r5, #228] */
/* @0x1cc160 vadd.f32 s13, s12, s13 */
/* @0x1cc164 mov r0, r5 */
/* @0x1cc168 vadd.f32 s15, s14, s15 */
/* @0x1cc16c vmov r1, s13 */
/* @0x1cc170 vmov r2, s15 */
/* @0x1cc174 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cc178 mov r0, r4 */
/* @0x1cc17c mov r1, r5 */
/* @0x1cc180 mov r2, #1 */
/* @0x1cc184 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1cc188 cmp r0, #0 */
/* @0x1cc18c popeq {r3, r4, r5, pc} */
/* @0x1cc190 ldr r2, [r4, #0xc8] */
/* @0x1cc194 mov r0, r4 */
/* @0x1cc198 ldr r1, [r4, #0xc4] */
/* @0x1cc19c bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cc1a0 mov r0, r4 */
/* @0x1cc1a4 ldr r1, [r4, #0x130] */
/* @0x1cc1a8 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf> */
/* @0x1cc1ac mov r0, r5 */
/* @0x1cc1b0 ldr r1, [r5, #0xc4] */
/* @0x1cc1b4 ldr r2, [r5, #0xc8] */
/* @0x1cc1b8 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cc1bc mov r0, r5 */
/* @0x1cc1c0 ldr r1, [r5, #0x130] */
/* @0x1cc1c4 pop {r3, r4, r5, lr} */
/* @0x1cc1c8 b 0x1935c4 <_ZN9CInstance15SetPathPositionEf> */
/* @0x1cc1cc eoreq r4, r2, r4, asr #21 */

/* ── FUNC 0x1cc1d0 · CollisionMarkDirty(CInstance*) · size=116 · insn=29 */
/* @0x1cc1d0 ldr r3, [pc, #0x64] */
/* @0x1cc1d4 ldr r3, [pc, r3] */
/* @0x1cc1d8 ldrb r3, [r3] */
/* @0x1cc1dc cmp r3, #0 */
/* @0x1cc1e0 bxeq lr */
/* @0x1cc1e4 ldr r3, [pc, #0x54] */
/* @0x1cc1e8 add r2, r0, #408 */
/* @0x1cc1ec ldr r1, [r0, #0x1a0] */
/* @0x1cc1f0 ldr r3, [pc, r3] */
/* @0x1cc1f4 cmp r1, r3 */
/* @0x1cc1f8 ldreq r12, [r0, #0x19c] */
/* @0x1cc1fc ldreq r1, [r0, #0x198] */
/* @0x1cc200 streq r12, [r1, #0x4] */
/* @0x1cc204 ldreq r12, [r0, #0x19c] */
/* @0x1cc208 streq r1, [r12] */
/* @0x1cc20c mov r12, #0 */
/* @0x1cc210 ldr r1, [r3] */
/* @0x1cc214 str r2, [r0, #0x198] */
/* @0x1cc218 cmp r2, r1 */
/* @0x1cc21c str r2, [r0, #0x19c] */
/* @0x1cc220 str r12, [r0, #0x1a0] */
/* @0x1cc224 strne r1, [r0, #0x198] */
/* @0x1cc228 strne r3, [r0, #0x19c] */
/* @0x1cc22c strne r2, [r3] */
/* @0x1cc230 strne r2, [r1, #0x4] */
/* @0x1cc234 strne r3, [r0, #0x1a0] */
/* @0x1cc238 b 0x1cbfc0 <_Z17CollisionMarkTestP9CInstance> */
/* @0x1cc23c eoreq r4, r2, r12, lsr #9 */
/* @0x1cc240 eoreq r4, r2, r12, asr #18 */

/* ── FUNC 0x1cc244 · CollisionIsRemoved(CInstance*) · size=8 · insn=2 */
/* @0x1cc244 mov r0, #0 */
/* @0x1cc248 bx lr */

/* ── FUNC 0x1cc24c · UpdateTree() · size=212 · insn=53 */
/* @0x1cc24c push {r3, r4, r5, r6, r7, lr} */
/* @0x1cc250 ldr r6, [pc, #0xc4] */
/* @0x1cc254 ldr r6, [pc, r6] */
/* @0x1cc258 ldr r5, [r6] */
/* @0x1cc25c cmp r5, r6 */
/* @0x1cc260 beq 0x1cc2f0 <_Z10UpdateTreev+0xa4> */
/* @0x1cc264 mov r7, #0 */
/* @0x1cc268 ldr r4, [r6, #0x8] */
/* @0x1cc26c subs r4, r5, r4 */
/* @0x1cc270 beq 0x1cc298 <_Z10UpdateTreev+0x4c> */
/* @0x1cc274 ldrb r3, [r4, #0x68] */
/* @0x1cc278 cmp r3, #0 */
/* @0x1cc27c bne 0x1cc298 <_Z10UpdateTreev+0x4c> */
/* @0x1cc280 ldrb r3, [r4, #0x69] */
/* @0x1cc284 cmp r3, #0 */
/* @0x1cc288 bne 0x1cc298 <_Z10UpdateTreev+0x4c> */
/* @0x1cc28c mov r0, r4 */
/* @0x1cc290 mov r1, #1 */
/* @0x1cc294 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cc298 ldr r2, [r4, #0x1a0] */
/* @0x1cc29c add r3, r4, #408 */
/* @0x1cc2a0 ldr r5, [r5] */
/* @0x1cc2a4 cmp r2, r6 */
/* @0x1cc2a8 ldreq r1, [r4, #0x19c] */
/* @0x1cc2ac ldreq r2, [r4, #0x198] */
/* @0x1cc2b0 streq r1, [r2, #0x4] */
/* @0x1cc2b4 ldreq r1, [r4, #0x19c] */
/* @0x1cc2b8 streq r2, [r1] */
/* @0x1cc2bc cmp r5, r6 */
/* @0x1cc2c0 str r3, [r4, #0x198] */
/* @0x1cc2c4 str r3, [r4, #0x19c] */
/* @0x1cc2c8 str r7, [r4, #0x1a0] */
/* @0x1cc2cc bne 0x1cc268 <_Z10UpdateTreev+0x1c> */
/* @0x1cc2d0 ldr r3, [r6] */
/* @0x1cc2d4 cmp r3, #0 */
/* @0x1cc2d8 beq 0x1cc2f0 <_Z10UpdateTreev+0xa4> */
/* @0x1cc2dc cmp r3, r6 */
/* @0x1cc2e0 strne r3, [r3] */
/* @0x1cc2e4 strne r3, [r3, #0x4] */
/* @0x1cc2e8 movne r2, #0 */
/* @0x1cc2ec strne r2, [r3, #0x8] */
/* @0x1cc2f0 ldr r3, [r6, #0x4] */
/* @0x1cc2f4 cmp r3, #0 */
/* @0x1cc2f8 beq 0x1cc310 <_Z10UpdateTreev+0xc4> */
/* @0x1cc2fc cmp r3, r6 */
/* @0x1cc300 strne r3, [r3] */
/* @0x1cc304 strne r3, [r3, #0x4] */
/* @0x1cc308 movne r2, #0 */
/* @0x1cc30c strne r2, [r3, #0x8] */
/* @0x1cc310 str r6, [r6] */
/* @0x1cc314 str r6, [r6, #0x4] */
/* @0x1cc318 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1cc31c eoreq r4, r2, r8, ror #17 */

/* ── FUNC 0x1cc320 · RTree<CInstance*, int, float, 6, 2>::RTree(int) · size=372 · insn=93 */
/* @0x1cc320 ldr r3, [pc, #0x164] */
/* @0x1cc324 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1cc328 ldr r3, [pc, r3] */
/* @0x1cc32c mov r5, r0 */
/* @0x1cc330 sub sp, sp, #12 */
/* @0x1cc334 add r3, r3, #8 */
/* @0x1cc338 mov r0, #20 */
/* @0x1cc33c str r3, [r5] */
/* @0x1cc340 mov r8, r1 */
/* @0x1cc344 bl 0x27c524 <_Znwj> */
/* @0x1cc348 ldr r7, [pc, #0x140] */
/* @0x1cc34c mov r6, #0 */
/* @0x1cc350 mov r1, #4 */
/* @0x1cc354 add r7, pc, r7 */
/* @0x1cc358 mov r3, #74 */
/* @0x1cc35c mov r10, #152 */
/* @0x1cc360 mov r2, r7 */
/* @0x1cc364 mov r4, r0 */
/* @0x1cc368 str r8, [r0] */
/* @0x1cc36c str r6, [r0, #0x4] */
/* @0x1cc370 mov r8, #1 */
/* @0x1cc374 str r6, [r0, #0xc] */
/* @0x1cc378 mov r0, r6 */
/* @0x1cc37c str r6, [r4, #0x10] */
/* @0x1cc380 str r8, [r4, #0x8] */
/* @0x1cc384 str r6, [sp] */
/* @0x1cc388 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1cc38c mov r1, r7 */
/* @0x1cc390 mov r3, r8 */
/* @0x1cc394 mov r2, #70 */
/* @0x1cc398 ldr r11, [r4, #0x8] */
/* @0x1cc39c sub r11, r11, #-1073741823 */
/* @0x1cc3a0 mov r9, r0 */
/* @0x1cc3a4 ldr r0, [r4] */
/* @0x1cc3a8 str r9, [r4, #0x4] */
/* @0x1cc3ac mul r0, r10, r0 */
/* @0x1cc3b0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1cc3b4 str r0, [r9, r11, lsl #2] */
/* @0x1cc3b8 ldr r12, [r4, #0x10] */
/* @0x1cc3bc str r4, [r5, #0x4] */
/* @0x1cc3c0 cmp r12, r6 */
/* @0x1cc3c4 str r6, [r5, #0xc] */
/* @0x1cc3c8 beq 0x1cc3fc <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei+0xdc> */
/* @0x1cc3cc ldr r3, [r12] */
/* @0x1cc3d0 str r3, [r4, #0x10] */
/* @0x1cc3d4 mov r3, #0 */
/* @0x1cc3d8 mov r0, r5 */
/* @0x1cc3dc str r3, [r12] */
/* @0x1cc3e0 movw r2, #0xfdc */
/* @0x1cc3e4 str r12, [r5, #0x10] */
/* @0x1cc3e8 movt r2, #0x4049 */
/* @0x1cc3ec str r3, [r12, #0x4] */
/* @0x1cc3f0 str r2, [r5, #0x14] */
/* @0x1cc3f4 add sp, sp, #12 */
/* @0x1cc3f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1cc3fc ldr r3, [r4, #0xc] */
/* @0x1cc400 ldr r2, [r4] */
/* @0x1cc404 cmp r3, r2 */
/* @0x1cc408 bge 0x1cc430 <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei+0x110> */
/* @0x1cc40c ldr r0, [r4, #0x8] */
/* @0x1cc410 mov r12, #152 */
/* @0x1cc414 ldr r2, [r4, #0x4] */
/* @0x1cc418 add r1, r3, #1 */
/* @0x1cc41c sub r0, r0, #-1073741823 */
/* @0x1cc420 ldr r2, [r2, r0, lsl #2] */
/* @0x1cc424 str r1, [r4, #0xc] */
/* @0x1cc428 mla r12, r12, r3, r2 */
/* @0x1cc42c b 0x1cc3d4 <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei+0xb4> */
/* @0x1cc430 ldr r1, [r4, #0x8] */
/* @0x1cc434 mov r2, r7 */
/* @0x1cc438 str r12, [r4, #0xc] */
/* @0x1cc43c mov r3, #74 */
/* @0x1cc440 add r1, r1, #1 */
/* @0x1cc444 ldr r0, [r4, #0x4] */
/* @0x1cc448 str r1, [r4, #0x8] */
/* @0x1cc44c lsl r1, r1, #2 */
/* @0x1cc450 str r12, [sp] */
/* @0x1cc454 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1cc458 mov r1, r7 */
/* @0x1cc45c mov r3, r8 */
/* @0x1cc460 mov r2, #70 */
/* @0x1cc464 ldr r7, [r4, #0x8] */
/* @0x1cc468 sub r7, r7, #-1073741823 */
/* @0x1cc46c mov r6, r0 */
/* @0x1cc470 ldr r0, [r4] */
/* @0x1cc474 str r6, [r4, #0x4] */
/* @0x1cc478 mul r0, r10, r0 */
/* @0x1cc47c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1cc480 ldr r3, [r4, #0xc] */
/* @0x1cc484 str r0, [r6, r7, lsl #2] */
/* @0x1cc488 b 0x1cc40c <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei+0xec> */
/* @0x1cc48c eoreq r4, r2, r4, lsl #16 */
/* @0x1cc490 ldrsbeq r4, [r6], -r12 */

/* ── FUNC 0x1cc320 · RTree<CInstance*, int, float, 6, 2>::RTree(int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1cc494 · CollisionInsert(CInstance*) · size=108 · insn=27 */
/* @0x1cc494 ldr r3, [pc, #0x5c] */
/* @0x1cc498 push {r4, r5, r6, lr} */
/* @0x1cc49c ldr r3, [pc, r3] */
/* @0x1cc4a0 mov r5, r0 */
/* @0x1cc4a4 ldrb r3, [r3] */
/* @0x1cc4a8 cmp r3, #0 */
/* @0x1cc4ac popeq {r4, r5, r6, pc} */
/* @0x1cc4b0 ldr r4, [pc, #0x44] */
/* @0x1cc4b4 ldr r4, [pc, r4] */
/* @0x1cc4b8 ldr r3, [r4] */
/* @0x1cc4bc cmp r3, #0 */
/* @0x1cc4c0 beq 0x1cc4dc <_Z15CollisionInsertP9CInstance+0x48> */
/* @0x1cc4c4 mov r0, r5 */
/* @0x1cc4c8 mov r1, #1 */
/* @0x1cc4cc bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cc4d0 mov r0, r5 */
/* @0x1cc4d4 pop {r4, r5, r6, lr} */
/* @0x1cc4d8 b 0x1cbfc0 <_Z17CollisionMarkTestP9CInstance> */
/* @0x1cc4dc mov r0, #24 */
/* @0x1cc4e0 bl 0x27c524 <_Znwj> */
/* @0x1cc4e4 mov r1, #1024 */
/* @0x1cc4e8 mov r6, r0 */
/* @0x1cc4ec bl 0x1cc320 <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei> */
/* @0x1cc4f0 str r6, [r4] */
/* @0x1cc4f4 b 0x1cc4c4 <_Z15CollisionInsertP9CInstance+0x30> */
/* @0x1cc4f8 eoreq r4, r2, r4, ror #3 */
/* @0x1cc4fc mlaeq r2, r0, sp, r1 */

/* ── FUNC 0x1cc500 · HandleCollision() · size=1684 · insn=421 */
/* @0x1cc500 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1cc504 sub sp, sp, #60 */
/* @0x1cc508 ldr r6, [pc, #0x640] */
/* @0x1cc50c ldr r3, [pc, #0x640] */
/* @0x1cc510 add r6, pc, r6 */
/* @0x1cc514 str r6, [sp, #0x8] */
/* @0x1cc518 ldr r3, [r6, r3] */
/* @0x1cc51c str r3, [sp, #0x14] */
/* @0x1cc520 ldrb r3, [r3] */
/* @0x1cc524 cmp r3, #0 */
/* @0x1cc528 bne 0x1ccac4 <_Z15HandleCollisionv+0x5c4> */
/* @0x1cc52c ldr r12, [sp, #0x8] */
/* @0x1cc530 ldr r2, [pc, #0x620] */
/* @0x1cc534 ldr r3, [pc, #0x620] */
/* @0x1cc538 ldr r2, [r12, r2] */
/* @0x1cc53c ldr r3, [r12, r3] */
/* @0x1cc540 ldrb r10, [r2] */
/* @0x1cc544 ldr r9, [r3, #0x4] */
/* @0x1cc548 cmp r10, #0 */
/* @0x1cc54c bne 0x1cc7e4 <_Z15HandleCollisionv+0x2e4> */
/* @0x1cc550 ldr r3, [pc, #0x608] */
/* @0x1cc554 ldr r3, [r12, r3] */
/* @0x1cc558 str r3, [sp, #0xc] */
/* @0x1cc55c ldr r3, [r3] */
/* @0x1cc560 cmp r3, #0 */
/* @0x1cc564 ble 0x1cc7bc <_Z15HandleCollisionv+0x2bc> */
/* @0x1cc568 ldrb r3, [r9, #0x10] */
/* @0x1cc56c cmp r3, #0 */
/* @0x1cc570 beq 0x1cc7a4 <_Z15HandleCollisionv+0x2a4> */
/* @0x1cc574 ldr r3, [r9, #0x8] */
/* @0x1cc578 ldr r11, [r3, #0xc4] */
/* @0x1cc57c cmp r11, #0 */
/* @0x1cc580 beq 0x1cc7a4 <_Z15HandleCollisionv+0x2a4> */
/* @0x1cc584 ldr r3, [r11, #0x8] */
/* @0x1cc588 cmp r3, #0 */
/* @0x1cc58c beq 0x1cc7a4 <_Z15HandleCollisionv+0x2a4> */
/* @0x1cc590 ldr r3, [pc, #0x5cc] */
/* @0x1cc594 ldr r12, [r9, #0xc] */
/* @0x1cc598 ldr r6, [sp, #0x8] */
/* @0x1cc59c str r12, [sp, #0x10] */
/* @0x1cc5a0 ldr r1, [r6, r3] */
/* @0x1cc5a4 ldrd r4, r5, [r1] */
/* @0x1cc5a8 adds r2, r4, #1 */
/* @0x1cc5ac adc r3, r5, #0 */
/* @0x1cc5b0 strd r2, r3, [r1] */
/* @0x1cc5b4 ldr r8, [r11, #0x8] */
/* @0x1cc5b8 ldr r11, [r11] */
/* @0x1cc5bc ldrb r3, [r8, #0x68] */
/* @0x1cc5c0 cmp r3, #0 */
/* @0x1cc5c4 bne 0x1cc790 <_Z15HandleCollisionv+0x290> */
/* @0x1cc5c8 ldrb r3, [r8, #0x69] */
/* @0x1cc5cc cmp r3, #0 */
/* @0x1cc5d0 bne 0x1cc790 <_Z15HandleCollisionv+0x290> */
/* @0x1cc5d4 ldrd r2, r3, [r8, #112] */
/* @0x1cc5d8 cmp r4, r2 */
/* @0x1cc5dc sbcs r12, r5, r3 */
/* @0x1cc5e0 blt 0x1cc790 <_Z15HandleCollisionv+0x290> */
/* @0x1cc5e4 ldr r12, [sp, #0x10] */
/* @0x1cc5e8 ldr r6, [r12, #0xc4] */
/* @0x1cc5ec cmp r6, #0 */
/* @0x1cc5f0 beq 0x1cc790 <_Z15HandleCollisionv+0x290> */
/* @0x1cc5f4 ldr r3, [r6, #0x8] */
/* @0x1cc5f8 cmp r3, #0 */
/* @0x1cc5fc beq 0x1cc790 <_Z15HandleCollisionv+0x290> */
/* @0x1cc600 ldr r7, [r6, #0x8] */
/* @0x1cc604 ldr r6, [r6] */
/* @0x1cc608 ldrb r3, [r7, #0x68] */
/* @0x1cc60c cmp r3, #0 */
/* @0x1cc610 bne 0x1cc5ec <_Z15HandleCollisionv+0xec> */
/* @0x1cc614 ldrb r3, [r7, #0x69] */
/* @0x1cc618 cmp r3, #0 */
/* @0x1cc61c bne 0x1cc5ec <_Z15HandleCollisionv+0xec> */
/* @0x1cc620 ldrd r2, r3, [r7, #112] */
/* @0x1cc624 cmp r4, r2 */
/* @0x1cc628 sbcs r1, r5, r3 */
/* @0x1cc62c blt 0x1cc5ec <_Z15HandleCollisionv+0xec> */
/* @0x1cc630 mov r0, r8 */
/* @0x1cc634 mov r1, r7 */
/* @0x1cc638 mov r2, #1 */
/* @0x1cc63c bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1cc640 cmp r0, #0 */
/* @0x1cc644 beq 0x1cc5ec <_Z15HandleCollisionv+0xec> */
/* @0x1cc648 ldrb r3, [r8, #0x66] */
/* @0x1cc64c cmp r3, #0 */
/* @0x1cc650 bne 0x1cc660 <_Z15HandleCollisionv+0x160> */
/* @0x1cc654 ldrb r3, [r7, #0x66] */
/* @0x1cc658 cmp r3, #0 */
/* @0x1cc65c beq 0x1cc698 <_Z15HandleCollisionv+0x198> */
/* @0x1cc660 ldr r2, [r8, #0xc8] */
/* @0x1cc664 mov r0, r8 */
/* @0x1cc668 ldr r1, [r8, #0xc4] */
/* @0x1cc66c bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cc670 mov r0, r8 */
/* @0x1cc674 ldr r1, [r8, #0x130] */
/* @0x1cc678 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf> */
/* @0x1cc67c mov r0, r7 */
/* @0x1cc680 ldr r1, [r7, #0xc4] */
/* @0x1cc684 ldr r2, [r7, #0xc8] */
/* @0x1cc688 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cc68c mov r0, r7 */
/* @0x1cc690 ldr r1, [r7, #0x130] */
/* @0x1cc694 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf> */
/* @0x1cc698 mov r0, r8 */
/* @0x1cc69c mov r1, r7 */
/* @0x1cc6a0 mov r2, #4 */
/* @0x1cc6a4 ldr r3, [r7, #0x7c] */
/* @0x1cc6a8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1cc6ac ldr r3, [r8, #0x7c] */
/* @0x1cc6b0 mov r0, r7 */
/* @0x1cc6b4 mov r1, r8 */
/* @0x1cc6b8 mov r2, #4 */
/* @0x1cc6bc bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1cc6c0 ldrb r3, [r8, #0x66] */
/* @0x1cc6c4 cmp r3, #0 */
/* @0x1cc6c8 bne 0x1cc6d8 <_Z15HandleCollisionv+0x1d8> */
/* @0x1cc6cc ldrb r3, [r7, #0x66] */
/* @0x1cc6d0 cmp r3, #0 */
/* @0x1cc6d4 beq 0x1cc5ec <_Z15HandleCollisionv+0xec> */
/* @0x1cc6d8 mov r0, r8 */
/* @0x1cc6dc bl 0x19411c <_ZN9CInstance10Adapt_PathEv> */
/* @0x1cc6e0 mov r0, r7 */
/* @0x1cc6e4 bl 0x19411c <_ZN9CInstance10Adapt_PathEv> */
/* @0x1cc6e8 vldr s13, [r8, #180] */
/* @0x1cc6ec vldr s15, [r8, #224] */
/* @0x1cc6f0 vadd.f32 s15, s13, s15 */
/* @0x1cc6f4 vldr s14, [r8, #184] */
/* @0x1cc6f8 mov r0, r8 */
/* @0x1cc6fc vmov r1, s15 */
/* @0x1cc700 vldr s15, [r8, #228] */
/* @0x1cc704 vadd.f32 s15, s14, s15 */
/* @0x1cc708 vmov r2, s15 */
/* @0x1cc70c bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cc710 vldr s12, [r7, #180] */
/* @0x1cc714 vldr s14, [r7, #184] */
/* @0x1cc718 vldr s13, [r7, #224] */
/* @0x1cc71c vldr s15, [r7, #228] */
/* @0x1cc720 vadd.f32 s13, s12, s13 */
/* @0x1cc724 mov r0, r7 */
/* @0x1cc728 vadd.f32 s15, s14, s15 */
/* @0x1cc72c vmov r1, s13 */
/* @0x1cc730 vmov r2, s15 */
/* @0x1cc734 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cc738 mov r0, r8 */
/* @0x1cc73c mov r1, r7 */
/* @0x1cc740 mov r2, #1 */
/* @0x1cc744 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1cc748 cmp r0, #0 */
/* @0x1cc74c beq 0x1cc5ec <_Z15HandleCollisionv+0xec> */
/* @0x1cc750 ldr r2, [r8, #0xc8] */
/* @0x1cc754 mov r0, r8 */
/* @0x1cc758 ldr r1, [r8, #0xc4] */
/* @0x1cc75c bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cc760 mov r0, r8 */
/* @0x1cc764 ldr r1, [r8, #0x130] */
/* @0x1cc768 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf> */
/* @0x1cc76c mov r0, r7 */
/* @0x1cc770 ldr r1, [r7, #0xc4] */
/* @0x1cc774 ldr r2, [r7, #0xc8] */
/* @0x1cc778 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cc77c mov r0, r7 */
/* @0x1cc780 ldr r1, [r7, #0x130] */
/* @0x1cc784 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf> */
/* @0x1cc788 cmp r6, #0 */
/* @0x1cc78c bne 0x1cc5f4 <_Z15HandleCollisionv+0xf4> */
/* @0x1cc790 cmp r11, #0 */
/* @0x1cc794 beq 0x1cc7a4 <_Z15HandleCollisionv+0x2a4> */
/* @0x1cc798 ldr r3, [r11, #0x8] */
/* @0x1cc79c cmp r3, #0 */
/* @0x1cc7a0 bne 0x1cc5b4 <_Z15HandleCollisionv+0xb4> */
/* @0x1cc7a4 ldr r6, [sp, #0xc] */
/* @0x1cc7a8 add r10, r10, #1 */
/* @0x1cc7ac add r9, r9, #20 */
/* @0x1cc7b0 ldr r3, [r6] */
/* @0x1cc7b4 cmp r3, r10 */
/* @0x1cc7b8 bgt 0x1cc568 <_Z15HandleCollisionv+0x68> */
/* @0x1cc7bc ldr r12, [sp, #0x14] */
/* @0x1cc7c0 ldrb r3, [r12] */
/* @0x1cc7c4 cmp r3, #0 */
/* @0x1cc7c8 beq 0x1cc7dc <_Z15HandleCollisionv+0x2dc> */
/* @0x1cc7cc ldr r3, [pc, #0x394] */
/* @0x1cc7d0 ldr r6, [sp, #0x8] */
/* @0x1cc7d4 ldr r0, [r6, r3] */
/* @0x1cc7d8 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1cc7dc add sp, sp, #60 */
/* @0x1cc7e0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1cc7e4 ldr r9, [pc, #0x380] */
/* @0x1cc7e8 mov r8, #0 */
/* @0x1cc7ec ldr r3, [pc, #0x37c] */
/* @0x1cc7f0 add r7, sp, #28 */
/* @0x1cc7f4 ldr r6, [sp, #0x8] */
/* @0x1cc7f8 add r9, pc, r9 */
/* @0x1cc7fc mov r2, #396 */
/* @0x1cc800 str r7, [sp, #0x1c] */
/* @0x1cc804 str r2, [sp, #0x24] */
/* @0x1cc808 str r8, [r9] */
/* @0x1cc80c str r7, [sp, #0x20] */
/* @0x1cc810 ldr r11, [r6, r3] */
/* @0x1cc814 ldr r4, [r11] */
/* @0x1cc818 cmp r4, r8 */
/* @0x1cc81c beq 0x1ccb0c <_Z15HandleCollisionv+0x60c> */
/* @0x1cc820 bl 0x1cc24c <_Z10UpdateTreev> */
/* @0x1cc824 ldr r3, [pc, #0x348] */
/* @0x1cc828 ldr r12, [sp, #0x8] */
/* @0x1cc82c ldr r5, [r12, r3] */
/* @0x1cc830 ldr r6, [r5] */
/* @0x1cc834 cmp r6, r5 */
/* @0x1cc838 beq 0x1ccb20 <_Z15HandleCollisionv+0x620> */
/* @0x1cc83c ldr r9, [pc, #0x334] */
/* @0x1cc840 add r12, sp, #40 */
/* @0x1cc844 str r12, [sp, #0xc] */
/* @0x1cc848 add r12, sp, #24 */
/* @0x1cc84c add r9, pc, r9 */
/* @0x1cc850 str r12, [sp, #0x10] */
/* @0x1cc854 b 0x1cc950 <_Z15HandleCollisionv+0x450> */
/* @0x1cc858 ldrb r1, [r4, #0x69] */
/* @0x1cc85c cmp r1, #0 */
/* @0x1cc860 bne 0x1cc968 <_Z15HandleCollisionv+0x468> */
/* @0x1cc864 ldr r0, [r4, #0xe8] */
/* @0x1cc868 add r3, sp, #24 */
/* @0x1cc86c ldr lr, [r4, #0xf0] */
/* @0x1cc870 add r2, sp, #40 */
/* @0x1cc874 ldr r12, [r4, #0xec] */
/* @0x1cc878 str r1, [sp, #0x18] */
/* @0x1cc87c cmp lr, r0 */
/* @0x1cc880 strle lr, [sp, #0x28] */
/* @0x1cc884 strgt r0, [sp, #0x28] */
/* @0x1cc888 ldr r1, [r4, #0xf4] */
/* @0x1cc88c cmp lr, r0 */
/* @0x1cc890 strge lr, [sp, #0x30] */
/* @0x1cc894 strlt r0, [sp, #0x30] */
/* @0x1cc898 ldr r10, [pc, #0x2dc] */
/* @0x1cc89c ldr lr, [sp, #0x8] */
/* @0x1cc8a0 ldr r0, [r11] */
/* @0x1cc8a4 cmp r1, r12 */
/* @0x1cc8a8 strle r1, [sp, #0x2c] */
/* @0x1cc8ac strgt r12, [sp, #0x2c] */
/* @0x1cc8b0 cmp r1, r12 */
/* @0x1cc8b4 strge r1, [sp, #0x34] */
/* @0x1cc8b8 strlt r12, [sp, #0x34] */
/* @0x1cc8bc ldr r12, [lr, r10] */
/* @0x1cc8c0 add r10, r4, #396 */
/* @0x1cc8c4 ldr r1, [r0, #0x10] */
/* @0x1cc8c8 str r4, [sp, #0x4] */
/* @0x1cc8cc str r12, [sp] */
/* @0x1cc8d0 bl 0x10d558 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_> */
/* @0x1cc8d4 ldr r3, [r4, #0x194] */
/* @0x1cc8d8 ldr r6, [r6] */
/* @0x1cc8dc cmp r3, r5 */
/* @0x1cc8e0 beq 0x1ccadc <_Z15HandleCollisionv+0x5dc> */
/* @0x1cc8e4 ldrb r3, [r4, #0xb0] */
/* @0x1cc8e8 str r10, [r4, #0x18c] */
/* @0x1cc8ec cmp r3, #0 */
/* @0x1cc8f0 str r10, [r4, #0x190] */
/* @0x1cc8f4 str r8, [r4, #0x194] */
/* @0x1cc8f8 beq 0x1cc940 <_Z15HandleCollisionv+0x440> */
/* @0x1cc8fc ldr r0, [r4, #0xac] */
/* @0x1cc900 cmp r0, #0 */
/* @0x1cc904 ldrlt r0, [r4, #0x8c] */
/* @0x1cc908 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1cc90c cmp r0, #0 */
/* @0x1cc910 beq 0x1cc940 <_Z15HandleCollisionv+0x440> */
/* @0x1cc914 ldr r3, [r0, #0x18] */
/* @0x1cc918 cmp r3, #1 */
/* @0x1cc91c ble 0x1cc940 <_Z15HandleCollisionv+0x440> */
/* @0x1cc920 ldr r3, [sp, #0x1c] */
/* @0x1cc924 cmp r10, r3 */
/* @0x1cc928 beq 0x1cc940 <_Z15HandleCollisionv+0x440> */
/* @0x1cc92c str r3, [r4, #0x18c] */
/* @0x1cc930 str r7, [r4, #0x190] */
/* @0x1cc934 str r10, [sp, #0x1c] */
/* @0x1cc938 str r10, [r3, #0x4] */
/* @0x1cc93c str r7, [r4, #0x194] */
/* @0x1cc940 ldr r3, [r9, #0xc] */
/* @0x1cc944 cmp r6, r5 */
/* @0x1cc948 str r3, [r4, #0x188] */
/* @0x1cc94c beq 0x1cc990 <_Z15HandleCollisionv+0x490> */
/* @0x1cc950 ldr r4, [r5, #0x8] */
/* @0x1cc954 subs r4, r6, r4 */
/* @0x1cc958 beq 0x1cc968 <_Z15HandleCollisionv+0x468> */
/* @0x1cc95c ldrb r3, [r4, #0x68] */
/* @0x1cc960 cmp r3, #0 */
/* @0x1cc964 beq 0x1cc858 <_Z15HandleCollisionv+0x358> */
/* @0x1cc968 ldr r3, [r4, #0x194] */
/* @0x1cc96c ldr r6, [r6] */
/* @0x1cc970 cmp r3, r5 */
/* @0x1cc974 beq 0x1ccaf4 <_Z15HandleCollisionv+0x5f4> */
/* @0x1cc978 cmp r6, r5 */
/* @0x1cc97c add r3, r4, #396 */
/* @0x1cc980 str r8, [r4, #0x194] */
/* @0x1cc984 str r3, [r4, #0x18c] */
/* @0x1cc988 str r3, [r4, #0x190] */
/* @0x1cc98c bne 0x1cc950 <_Z15HandleCollisionv+0x450> */
/* @0x1cc990 ldr r2, [pc, #0x1e8] */
/* @0x1cc994 ldr r1, [sp, #0x1c] */
/* @0x1cc998 add r2, pc, r2 */
/* @0x1cc99c ldr r3, [r5] */
/* @0x1cc9a0 ldr r4, [r2] */
/* @0x1cc9a4 ldr r0, [pc, #0x1d8] */
/* @0x1cc9a8 mov r2, #0 */
/* @0x1cc9ac ldr r6, [pc, #0x1d4] */
/* @0x1cc9b0 cmp r3, r2 */
/* @0x1cc9b4 add r0, pc, r0 */
/* @0x1cc9b8 ldr r12, [pc, #0x1cc] */
/* @0x1cc9bc ldr r8, [r0, #0xc] */
/* @0x1cc9c0 add r8, r8, #1 */
/* @0x1cc9c4 str r8, [r0, #0xc] */
/* @0x1cc9c8 mov r0, r6 */
/* @0x1cc9cc ldr r6, [sp, #0x8] */
/* @0x1cc9d0 ldr r0, [r6, r0] */
/* @0x1cc9d4 str r2, [r0] */
/* @0x1cc9d8 ldr r0, [r6, r12] */
/* @0x1cc9dc str r2, [r0] */
/* @0x1cc9e0 beq 0x1cc9f4 <_Z15HandleCollisionv+0x4f4> */
/* @0x1cc9e4 cmp r3, r5 */
/* @0x1cc9e8 strne r3, [r3] */
/* @0x1cc9ec strne r3, [r3, #0x4] */
/* @0x1cc9f0 strne r2, [r3, #0x8] */
/* @0x1cc9f4 ldr r3, [r5, #0x4] */
/* @0x1cc9f8 cmp r3, #0 */
/* @0x1cc9fc beq 0x1cca14 <_Z15HandleCollisionv+0x514> */
/* @0x1cca00 cmp r3, r5 */
/* @0x1cca04 strne r3, [r3] */
/* @0x1cca08 strne r3, [r3, #0x4] */
/* @0x1cca0c movne r2, #0 */
/* @0x1cca10 strne r2, [r3, #0x8] */
/* @0x1cca14 cmp r1, r7 */
/* @0x1cca18 str r5, [r5] */
/* @0x1cca1c str r5, [r5, #0x4] */
/* @0x1cca20 beq 0x1cca94 <_Z15HandleCollisionv+0x594> */
/* @0x1cca24 ldr r6, [sp, #0x24] */
/* @0x1cca28 mov r12, r5 */
/* @0x1cca2c mov r0, r5 */
/* @0x1cca30 mov r8, #0 */
/* @0x1cca34 rsb r6, r6, #0 */
/* @0x1cca38 add r3, r1, r6 */
/* @0x1cca3c ldr r1, [r1] */
/* @0x1cca40 add r2, r3, #396 */
/* @0x1cca44 ldr r9, [r3, #0x194] */
/* @0x1cca48 cmp r9, r7 */
/* @0x1cca4c ldreq r10, [r3, #0x190] */
/* @0x1cca50 ldreq r9, [r3, #0x18c] */
/* @0x1cca54 streq r10, [r9, #0x4] */
/* @0x1cca58 ldreq r10, [r3, #0x190] */
/* @0x1cca5c streq r9, [r10] */
/* @0x1cca60 cmp r0, r2 */
/* @0x1cca64 str r2, [r3, #0x18c] */
/* @0x1cca68 str r2, [r3, #0x190] */
/* @0x1cca6c movne r12, r2 */
/* @0x1cca70 strne r0, [r3, #0x18c] */
/* @0x1cca74 str r8, [r3, #0x194] */
/* @0x1cca78 strne r5, [r3, #0x190] */
/* @0x1cca7c strne r2, [r0, #0x4] */
/* @0x1cca80 mov r0, r12 */
/* @0x1cca84 strne r5, [r3, #0x194] */
/* @0x1cca88 cmp r1, r7 */
/* @0x1cca8c bne 0x1cca38 <_Z15HandleCollisionv+0x538> */
/* @0x1cca90 str r12, [r5] */
/* @0x1cca94 ldr r6, [pc, #0xf4] */
/* @0x1cca98 cmp r4, #0 */
/* @0x1cca9c mov r5, #0 */
/* @0x1ccaa0 add r6, pc, r6 */
/* @0x1ccaa4 ble 0x1cc7bc <_Z15HandleCollisionv+0x2bc> */
/* @0x1ccaa8 ldr r0, [r6, #0x8] */
/* @0x1ccaac add r0, r0, r5, lsl #3 */
/* @0x1ccab0 add r5, r5, #1 */
/* @0x1ccab4 bl 0x1cc034 <_Z16processCollisionP10SCollision> */
/* @0x1ccab8 cmp r5, r4 */
/* @0x1ccabc bne 0x1ccaa8 <_Z15HandleCollisionv+0x5a8> */
/* @0x1ccac0 b 0x1cc7bc <_Z15HandleCollisionv+0x2bc> */
/* @0x1ccac4 ldr r3, [pc, #0x9c] */
/* @0x1ccac8 mov r1, #6 */
/* @0x1ccacc mov r2, #0 */
/* @0x1ccad0 ldr r0, [r6, r3] */
/* @0x1ccad4 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1ccad8 b 0x1cc52c <_Z15HandleCollisionv+0x2c> */
/* @0x1ccadc ldr r2, [r4, #0x190] */
/* @0x1ccae0 ldr r3, [r4, #0x18c] */
/* @0x1ccae4 str r2, [r3, #0x4] */
/* @0x1ccae8 ldr r2, [r4, #0x190] */
/* @0x1ccaec str r3, [r2] */
/* @0x1ccaf0 b 0x1cc8e4 <_Z15HandleCollisionv+0x3e4> */
/* @0x1ccaf4 ldr r2, [r4, #0x190] */
/* @0x1ccaf8 ldr r3, [r4, #0x18c] */
/* @0x1ccafc str r2, [r3, #0x4] */
/* @0x1ccb00 ldr r2, [r4, #0x190] */
/* @0x1ccb04 str r3, [r2] */
/* @0x1ccb08 b 0x1cc978 <_Z15HandleCollisionv+0x478> */
/* @0x1ccb0c ldr r3, [pc, #0x60] */
/* @0x1ccb10 mov r1, r7 */
/* @0x1ccb14 ldr r5, [r6, r3] */
/* @0x1ccb18 ldr r3, [r5] */
/* @0x1ccb1c b 0x1cc9a4 <_Z15HandleCollisionv+0x4a4> */
/* @0x1ccb20 ldr r2, [pc, #0x60] */
/* @0x1ccb24 ldr r1, [r9, #0xc] */
/* @0x1ccb28 ldr r3, [pc, #0x5c] */
/* @0x1ccb2c add r1, r1, #1 */
/* @0x1ccb30 str r1, [r9, #0xc] */
/* @0x1ccb34 ldr r2, [r12, r2] */
/* @0x1ccb38 ldr r1, [sp, #0x1c] */
/* @0x1ccb3c ldr r4, [r9] */
/* @0x1ccb40 str r8, [r2] */
/* @0x1ccb44 ldr r3, [r12, r3] */
/* @0x1ccb48 str r8, [r3] */
/* @0x1ccb4c b 0x1cc9f4 <_Z15HandleCollisionv+0x4f4> */
/* @0x1ccb50 eoreq r5, r2, r0, asr #14 */
/* @0x1ccb54 .word 0xffffbf18 */
/* @0x1ccb58 .word 0xffffea30 */
/* @0x1ccb5c .word 0xffffea90 */
/* @0x1ccb60 .word 0xffffea8c */
/* @0x1ccb64 .word 0xffffdeb4 */
/* @0x1ccb68 .word 0xffffbf1c */
/* @0x1ccb6c mlaseq r7, r8, r1, r6 */
/* @0x1ccb70 .word 0xffffc5f4 */
/* @0x1ccb74 .word 0xffffeee4 */
/* @0x1ccb78 eorseq r6, r7, r4, asr #2 */
/* @0x1ccb7c .word 0xffffeef0 */
/* @0x1ccb80 ldrshteq r5, [r7], -r8 */
/* @0x1ccb84 ldrsbteq r5, [r7], -r12 */
/* @0x1ccb88 .word 0xffffeee0 */
/* @0x1ccb8c .word 0xffffeee8 */
/* @0x1ccb90 ldrshteq r5, [r7], -r0 */

/* ── FUNC 0x1ccb94 · RTree<CInstance*, int, float, 6, 2>::RemoveRectRec(RTree<CInstance*, int, float, 6, 2>::Rect*, CInstance* const&, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::ListNode**) · size=460 · insn=115 */
/* @0x1ccb94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ccb98 mov r8, r3 */
/* @0x1ccb9c ldr r3, [r3, #0x4] */
/* @0x1ccba0 sub sp, sp, #28 */
/* @0x1ccba4 mov r11, r0 */
/* @0x1ccba8 mov r7, r1 */
/* @0x1ccbac cmp r3, #0 */
/* @0x1ccbb0 mov r9, r2 */
/* @0x1ccbb4 ldr r10, [sp, #0x40] */
/* @0x1ccbb8 ble 0x1ccc3c <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0xa8> */
/* @0x1ccbbc ldr r6, [r8] */
/* @0x1ccbc0 cmp r6, #0 */
/* @0x1ccbc4 ble 0x1ccc2c <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x98> */
/* @0x1ccbc8 add r4, r8, #8 */
/* @0x1ccbcc mov r5, #0 */
/* @0x1ccbd0 b 0x1ccbe4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x50> */
/* @0x1ccbd4 add r5, r5, #1 */
/* @0x1ccbd8 add r4, r4, #24 */
/* @0x1ccbdc cmp r6, r5 */
/* @0x1ccbe0 ble 0x1ccc2c <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x98> */
/* @0x1ccbe4 mov r0, r7 */
/* @0x1ccbe8 mov r1, r4 */
/* @0x1ccbec bl 0x1cbc10 <_Z19FINALIZE_Run_Globalv+0x1a4> */
/* @0x1ccbf0 cmp r0, #0 */
/* @0x1ccbf4 beq 0x1ccbd4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x40> */
/* @0x1ccbf8 ldr r3, [r4, #0x10] */
/* @0x1ccbfc mov r0, r11 */
/* @0x1ccc00 str r10, [sp] */
/* @0x1ccc04 mov r1, r7 */
/* @0x1ccc08 mov r2, r9 */
/* @0x1ccc0c bl 0x1ccb94 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE> */
/* @0x1ccc10 subs r6, r0, #0 */
/* @0x1ccc14 beq 0x1ccc84 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0xf0> */
/* @0x1ccc18 ldr r6, [r8] */
/* @0x1ccc1c add r5, r5, #1 */
/* @0x1ccc20 add r4, r4, #24 */
/* @0x1ccc24 cmp r6, r5 */
/* @0x1ccc28 bgt 0x1ccbe4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x50> */
/* @0x1ccc2c mov r6, #1 */
/* @0x1ccc30 mov r0, r6 */
/* @0x1ccc34 add sp, sp, #28 */
/* @0x1ccc38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ccc3c ldr r0, [r8] */
/* @0x1ccc40 cmp r0, #0 */
/* @0x1ccc44 ble 0x1ccc2c <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x98> */
/* @0x1ccc48 ldr r12, [r2] */
/* @0x1ccc4c ldr r3, [r8, #0x1c] */
/* @0x1ccc50 cmp r3, r12 */
/* @0x1ccc54 movne r1, r8 */
/* @0x1ccc58 movne r2, #0 */
/* @0x1ccc5c bne 0x1ccc70 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0xdc> */
/* @0x1ccc60 b 0x1ccccc <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x138> */
/* @0x1ccc64 ldr r3, [r1, #0x1c] */
/* @0x1ccc68 cmp r3, r12 */
/* @0x1ccc6c beq 0x1cccd0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x13c> */
/* @0x1ccc70 add r2, r2, #1 */
/* @0x1ccc74 add r1, r1, #24 */
/* @0x1ccc78 cmp r2, r0 */
/* @0x1ccc7c bne 0x1ccc64 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0xd0> */
/* @0x1ccc80 b 0x1ccc2c <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x98> */
/* @0x1ccc84 add r3, r5, #1 */
/* @0x1ccc88 add r3, r3, r3, lsl #1 */
/* @0x1ccc8c ldr r4, [r8, r3, lsl #3] */
/* @0x1ccc90 ldr r3, [r4] */
/* @0x1ccc94 cmp r3, #1 */
/* @0x1ccc98 ble 0x1ccd10 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x17c> */
/* @0x1ccc9c mov r1, r4 */
/* @0x1ccca0 add r4, sp, #8 */
/* @0x1ccca4 add r5, r5, r5, lsl #1 */
/* @0x1ccca8 mov r0, r4 */
/* @0x1cccac bl 0x1cbc60 <_Z19FINALIZE_Run_Globalv+0x1f4> */
/* @0x1cccb0 ldm r4, {r0, r1, r2, r3} */
/* @0x1cccb4 add r5, r8, r5, lsl #3 */
/* @0x1cccb8 add r5, r5, #8 */
/* @0x1cccbc stm r5, {r0, r1, r2, r3} */
/* @0x1cccc0 mov r0, r6 */
/* @0x1cccc4 add sp, sp, #28 */
/* @0x1cccc8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ccccc mov r2, #0 */
/* @0x1cccd0 sub r5, r0, #1 */
/* @0x1cccd4 add r2, r2, r2, lsl #1 */
/* @0x1cccd8 mov r6, #0 */
/* @0x1cccdc add r4, r5, r5, lsl #1 */
/* @0x1ccce0 add r12, r8, r2, lsl #3 */
/* @0x1ccce4 add r12, r12, #8 */
/* @0x1ccce8 add r4, r8, r4, lsl #3 */
/* @0x1cccec add r4, r4, #8 */
/* @0x1cccf0 ldm r4!, {r0, r1, r2, r3} */
/* @0x1cccf4 stm r12!, {r0, r1, r2, r3} */
/* @0x1cccf8 ldm r4, {r0, r1} */
/* @0x1cccfc stm r12, {r0, r1} */
/* @0x1ccd00 mov r0, r6 */
/* @0x1ccd04 str r5, [r8] */
/* @0x1ccd08 add sp, sp, #28 */
/* @0x1ccd0c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ccd10 mov r0, #8 */
/* @0x1ccd14 add r5, r5, r5, lsl #1 */
/* @0x1ccd18 bl 0x27c524 <_Znwj> */
/* @0x1ccd1c ldr r7, [r8] */
/* @0x1ccd20 add r12, r8, r5, lsl #3 */
/* @0x1ccd24 sub r7, r7, #1 */
/* @0x1ccd28 add r12, r12, #8 */
/* @0x1ccd2c str r4, [r0, #0x4] */
/* @0x1ccd30 add r4, r7, r7, lsl #1 */
/* @0x1ccd34 ldr r3, [r10] */
/* @0x1ccd38 add r4, r8, r4, lsl #3 */
/* @0x1ccd3c add r4, r4, #8 */
/* @0x1ccd40 str r3, [r0] */
/* @0x1ccd44 str r0, [r10] */
/* @0x1ccd48 ldm r4!, {r0, r1, r2, r3} */
/* @0x1ccd4c stm r12!, {r0, r1, r2, r3} */
/* @0x1ccd50 ldm r4, {r0, r1} */
/* @0x1ccd54 stm r12, {r0, r1} */
/* @0x1ccd58 str r7, [r8] */
/* @0x1ccd5c b 0x1ccc30 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE+0x9c> */

/* ── FUNC 0x1ccd60 · RTree<CInstance*, int, float, 6, 2>::SplitNode(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Branch const*, RTree<CInstance*, int, float, 6, 2>::Node**) · size=1788 · insn=447 */
/* @0x1ccd60 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ccd64 sub sp, sp, #372 */
/* @0x1ccd68 add r11, sp, #92 */
/* @0x1ccd6c add r7, sp, #236 */
/* @0x1ccd70 mov r6, r2 */
/* @0x1ccd74 mov r5, r1 */
/* @0x1ccd78 mov r4, r11 */
/* @0x1ccd7c str r1, [sp, #0x24] */
/* @0x1ccd80 str r0, [sp, #0x2c] */
/* @0x1ccd84 str r3, [sp, #0x30] */
/* @0x1ccd88 add lr, r5, #8 */
/* @0x1ccd8c add r12, r4, #84 */
/* @0x1ccd90 add r4, r4, #24 */
/* @0x1ccd94 add r5, r5, #24 */
/* @0x1ccd98 ldm lr!, {r0, r1, r2, r3} */
/* @0x1ccd9c cmp r4, r7 */
/* @0x1ccda0 stm r12!, {r0, r1, r2, r3} */
/* @0x1ccda4 ldm lr, {r0, r1} */
/* @0x1ccda8 stm r12, {r0, r1} */
/* @0x1ccdac bne 0x1ccd88 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x28> */
/* @0x1ccdb0 ldm r6!, {r0, r1, r2, r3} */
/* @0x1ccdb4 add r5, sp, #320 */
/* @0x1ccdb8 add r4, sp, #176 */
/* @0x1ccdbc str r4, [sp, #0x20] */
/* @0x1ccdc0 add lr, sp, #200 */
/* @0x1ccdc4 add r4, r11, #252 */
/* @0x1ccdc8 mov r12, #7 */
/* @0x1ccdcc str r12, [sp, #0x158] */
/* @0x1ccdd0 stm r5!, {r0, r1, r2, r3} */
/* @0x1ccdd4 mov r12, lr */
/* @0x1ccdd8 ldm r6, {r0, r1} */
/* @0x1ccddc stm r5, {r0, r1} */
/* @0x1ccde0 ldr r5, [sp, #0x20] */
/* @0x1ccde4 ldm r5, {r0, r1, r2, r3} */
/* @0x1ccde8 add r5, sp, #348 */
/* @0x1ccdec stm r5, {r0, r1, r2, r3} */
/* @0x1ccdf0 mov r8, r0 */
/* @0x1ccdf4 ldr r7, [sp, #0x164] */
/* @0x1ccdf8 ldr r6, [sp, #0x160] */
/* @0x1ccdfc ldr r5, [sp, #0x168] */
/* @0x1cce00 ldr r1, [r12] */
/* @0x1cce04 add r12, r12, #24 */
/* @0x1cce08 ldr r0, [r12, #-0x10] */
/* @0x1cce0c ldr r3, [r12, #-0x14] */
/* @0x1cce10 cmp r1, r8 */
/* @0x1cce14 movge r1, r8 */
/* @0x1cce18 ldr r2, [r12, #-0xc] */
/* @0x1cce1c cmp r0, r7 */
/* @0x1cce20 movlt r0, r7 */
/* @0x1cce24 cmp r3, r6 */
/* @0x1cce28 movge r3, r6 */
/* @0x1cce2c mov r8, r1 */
/* @0x1cce30 cmp r2, r5 */
/* @0x1cce34 movlt r2, r5 */
/* @0x1cce38 cmp r12, r4 */
/* @0x1cce3c mov r6, r3 */
/* @0x1cce40 mov r7, r0 */
/* @0x1cce44 mov r5, r2 */
/* @0x1cce48 str r1, [sp, #0x15c] */
/* @0x1cce4c str r3, [sp, #0x160] */
/* @0x1cce50 str r0, [sp, #0x164] */
/* @0x1cce54 str r2, [sp, #0x168] */
/* @0x1cce58 bne 0x1cce00 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0xa0> */
/* @0x1cce5c vmov s4, r0 */
/* @0x1cce60 add r4, sp, #88 */
/* @0x1cce64 vmov s8, r2 */
/* @0x1cce68 str r4, [sp, #0x28] */
/* @0x1cce6c vcvt.f32.s32 s12, s4 */
/* @0x1cce70 add r4, r11, #24 */
/* @0x1cce74 vmov s4, r1 */
/* @0x1cce78 add r0, sp, #88 */
/* @0x1cce7c vmov s10, r3 */
/* @0x1cce80 mvn r12, #0 */
/* @0x1cce84 mov r5, #0 */
/* @0x1cce88 mov r1, #2 */
/* @0x1cce8c str r5, [sp, #0x84] */
/* @0x1cce90 str r5, [sp, #0x80] */
/* @0x1cce94 mov r5, #0 */
/* @0x1cce98 str r1, [sp, #0x7c] */
/* @0x1cce9c vcvt.f32.s32 s14, s4 */
/* @0x1ccea0 str r5, [sp, #0xac] */
/* @0x1ccea4 str r5, [sp, #0xa8] */
/* @0x1ccea8 mov r5, #7 */
/* @0x1cceac str r5, [sp, #0x78] */
/* @0x1cceb0 vcvt.f32.s32 s13, s8 */
/* @0x1cceb4 vcvt.f32.s32 s15, s10 */
/* @0x1cceb8 vsub.f32 s14, s12, s14 */
/* @0x1ccebc vsub.f32 s15, s13, s15 */
/* @0x1ccec0 vmul.f32 s14, s14, s15 */
/* @0x1ccec4 vstr s14, [sp, #364] */
/* @0x1ccec8 str r12, [r0, #0x4]! */
/* @0x1ccecc cmp r0, r4 */
/* @0x1cced0 bne 0x1ccec8 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x168> */
/* @0x1cced4 add r2, sp, #64 */
/* @0x1cced8 add r1, r11, #168 */
/* @0x1ccedc mov r3, r11 */
/* @0x1ccee0 vldr s15, [r3, #92] */
/* @0x1ccee4 vldr s13, [r3, #84] */
/* @0x1ccee8 vldr s11, [r3, #96] */
/* @0x1cceec vldr s12, [r3, #88] */
/* @0x1ccef0 vcvt.f32.s32 s10, s15 */
/* @0x1ccef4 add r3, r3, #24 */
/* @0x1ccef8 cmp r3, r1 */
/* @0x1ccefc vcvt.f32.s32 s13, s13 */
/* @0x1ccf00 vcvt.f32.s32 s11, s11 */
/* @0x1ccf04 vcvt.f32.s32 s12, s12 */
/* @0x1ccf08 vsub.f32 s13, s10, s13 */
/* @0x1ccf0c vsub.f32 s15, s11, s12 */
/* @0x1ccf10 vmul.f32 s15, s13, s15 */
/* @0x1ccf14 vstmia r2!, {s15} */
/* @0x1ccf18 bne 0x1ccee0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x180> */
/* @0x1ccf1c vmov.f32 s15, #-1.000000e+00 */
/* @0x1ccf20 mvn r5, #0 */
/* @0x1ccf24 add r4, sp, #176 */
/* @0x1ccf28 add r0, sp, #68 */
/* @0x1ccf2c mov r12, #1 */
/* @0x1ccf30 str r0, [sp, #0x14] */
/* @0x1ccf34 mov r6, #0 */
/* @0x1ccf38 mov r0, r5 */
/* @0x1ccf3c str lr, [sp, #0x18] */
/* @0x1ccf40 str r11, [sp, #0x34] */
/* @0x1ccf44 vsub.f32 s14, s15, s14 */
/* @0x1ccf48 ldr r2, [sp, #0x18] */
/* @0x1ccf4c add r1, r6, #1 */
/* @0x1ccf50 str r1, [sp, #0x1c] */
/* @0x1ccf54 ldr r10, [r4, #0x8] */
/* @0x1ccf58 ldr r11, [r2, #-0x18] */
/* @0x1ccf5c ldr r1, [sp, #0x14] */
/* @0x1ccf60 vldr s9, [r1, #-4] */
/* @0x1ccf64 ldr r9, [r4, #0x4] */
/* @0x1ccf68 ldr r2, [sp, #0x1c] */
/* @0x1ccf6c ldr r8, [r4, #0xc] */
/* @0x1ccf70 ldr r3, [sp, #0x18] */
/* @0x1ccf74 str r4, [sp, #0xc] */
/* @0x1ccf78 b 0x1ccfb0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x250> */
/* @0x1ccf7c vcmp.f32 s15, s14 */
/* @0x1ccf80 add r3, r3, #24 */
/* @0x1ccf84 vmrs APSR_nzcv, fpscr */
/* @0x1ccf88 movne lr, #0 */
/* @0x1ccf8c andeq lr, r12, #1 */
/* @0x1ccf90 cmp lr, #0 */
/* @0x1ccf94 movne r5, r2 */
/* @0x1ccf98 add r2, r2, #1 */
/* @0x1ccf9c vmovne.f32 s14, s15 */
/* @0x1ccfa0 movne r0, r6 */
/* @0x1ccfa4 movne r12, #0 */
/* @0x1ccfa8 cmp r2, #6 */
/* @0x1ccfac bgt 0x1cd048 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x2e8> */
/* @0x1ccfb0 ldr r4, [r3, #0x8] */
/* @0x1ccfb4 vmov.f32 s8, s9 */
/* @0x1ccfb8 ldr lr, [r3] */
/* @0x1ccfbc vldmia r1!, {s15} */
/* @0x1ccfc0 cmp r4, r10 */
/* @0x1ccfc4 movge r7, r4 */
/* @0x1ccfc8 movlt r7, r10 */
/* @0x1ccfcc ldr r4, [r3, #0xc] */
/* @0x1ccfd0 cmp lr, r11 */
/* @0x1ccfd4 movge lr, r11 */
/* @0x1ccfd8 cmp r4, r8 */
/* @0x1ccfdc movlt r4, r8 */
/* @0x1ccfe0 vmov s4, r7 */
/* @0x1ccfe4 vmov s11, r4 */
/* @0x1ccfe8 ldr r4, [r3, #0x4] */
/* @0x1ccfec vcvt.f32.s32 s10, s4 */
/* @0x1ccff0 cmp r4, r9 */
/* @0x1ccff4 movge r4, r9 */
/* @0x1ccff8 vmov s4, lr */
/* @0x1ccffc vmov s13, r4 */
/* @0x1cd000 vcvt.f32.s32 s12, s4 */
/* @0x1cd004 vcvt.f32.s32 s11, s11 */
/* @0x1cd008 vcvt.f32.s32 s13, s13 */
/* @0x1cd00c vsub.f32 s12, s10, s12 */
/* @0x1cd010 vsub.f32 s13, s11, s13 */
/* @0x1cd014 vnmls.f32 s8, s12, s13 */
/* @0x1cd018 vsub.f32 s15, s8, s15 */
/* @0x1cd01c vcmpe.f32 s15, s14 */
/* @0x1cd020 vmrs APSR_nzcv, fpscr */
/* @0x1cd024 ble 0x1ccf7c <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x21c> */
/* @0x1cd028 mov r5, r2 */
/* @0x1cd02c add r2, r2, #1 */
/* @0x1cd030 cmp r2, #6 */
/* @0x1cd034 vmov.f32 s14, s15 */
/* @0x1cd038 mov r0, r6 */
/* @0x1cd03c mov r12, #0 */
/* @0x1cd040 add r3, r3, #24 */
/* @0x1cd044 ble 0x1ccfb0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x250> */
/* @0x1cd048 ldr r1, [sp, #0x1c] */
/* @0x1cd04c ldr r2, [sp, #0x18] */
/* @0x1cd050 ldr r3, [sp, #0x14] */
/* @0x1cd054 cmp r1, #6 */
/* @0x1cd058 ldr r4, [sp, #0xc] */
/* @0x1cd05c add r2, r2, #24 */
/* @0x1cd060 add r3, r3, #4 */
/* @0x1cd064 str r2, [sp, #0x18] */
/* @0x1cd068 add r4, r4, #24 */
/* @0x1cd06c str r3, [sp, #0x14] */
/* @0x1cd070 movne r6, r1 */
/* @0x1cd074 bne 0x1ccf48 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x1e8> */
/* @0x1cd078 ldr r11, [sp, #0x34] */
/* @0x1cd07c mov r1, #0 */
/* @0x1cd080 mov r2, r11 */
/* @0x1cd084 bl 0x1cbcf4 <_Z19FINALIZE_Run_Globalv+0x288> */
/* @0x1cd088 mov r1, #1 */
/* @0x1cd08c mov r2, r11 */
/* @0x1cd090 mov r0, r5 */
/* @0x1cd094 bl 0x1cbcf4 <_Z19FINALIZE_Run_Globalv+0x288> */
/* @0x1cd098 ldr r3, [sp, #0x80] */
/* @0x1cd09c ldr r1, [sp, #0x84] */
/* @0x1cd0a0 ldr r7, [sp, #0x78] */
/* @0x1cd0a4 add r2, r3, r1 */
/* @0x1cd0a8 cmp r2, r7 */
/* @0x1cd0ac bge 0x1cd308 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x5a8> */
/* @0x1cd0b0 ldr r2, [sp, #0x7c] */
/* @0x1cd0b4 rsb r2, r2, r7 */
/* @0x1cd0b8 cmp r3, r2 */
/* @0x1cd0bc bge 0x1cd2b0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x550> */
/* @0x1cd0c0 cmp r1, r2 */
/* @0x1cd0c4 bge 0x1cd2b0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x550> */
/* @0x1cd0c8 ldr r8, [sp, #0x38] */
/* @0x1cd0cc ldr r6, [sp, #0x3c] */
/* @0x1cd0d0 cmp r7, #0 */
/* @0x1cd0d4 ble 0x1cd270 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x510> */
/* @0x1cd0d8 ldr r1, [sp, #0x98] */
/* @0x1cd0dc add r0, sp, #176 */
/* @0x1cd0e0 ldr r5, [sp, #0x90] */
/* @0x1cd0e4 vmov.f32 s14, #-1.000000e+00 */
/* @0x1cd0e8 ldr r12, [sp, #0x8c] */
/* @0x1cd0ec mov r3, #0 */
/* @0x1cd0f0 ldr lr, [sp, #0x94] */
/* @0x1cd0f4 vldr s5, [sp, #168] */
/* @0x1cd0f8 ldr r2, [sp, #0x9c] */
/* @0x1cd0fc vldr s6, [sp, #172] */
/* @0x1cd100 str r1, [sp, #0x18] */
/* @0x1cd104 ldr r10, [sp, #0x88] */
/* @0x1cd108 str r5, [sp, #0xc] */
/* @0x1cd10c str r12, [sp, #0x10] */
/* @0x1cd110 str lr, [sp, #0x14] */
/* @0x1cd114 ldr r9, [sp, #0xa0] */
/* @0x1cd118 str r2, [sp, #0x1c] */
/* @0x1cd11c ldr r1, [sp, #0xa4] */
/* @0x1cd120 b 0x1cd134 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x3d4> */
/* @0x1cd124 add r3, r3, #1 */
/* @0x1cd128 add r0, r0, #24 */
/* @0x1cd12c cmp r3, r7 */
/* @0x1cd130 beq 0x1cd270 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x510> */
/* @0x1cd134 ldr r2, [r11, r3, lsl #2] */
/* @0x1cd138 cmn r2, #1 */
/* @0x1cd13c bne 0x1cd124 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x3c4> */
/* @0x1cd140 ldmib r0, {r12, lr} */
/* @0x1cd144 mov r5, #0 */
/* @0x1cd148 ldr r4, [r0] */
/* @0x1cd14c ldr r2, [sp, #0x18] */
/* @0x1cd150 cmp r2, r4 */
/* @0x1cd154 movge r2, r4 */
/* @0x1cd158 cmp r4, r10 */
/* @0x1cd15c movge r4, r10 */
/* @0x1cd160 str r4, [sp, #0x34] */
/* @0x1cd164 cmp lr, r9 */
/* @0x1cd168 movge r4, lr */
/* @0x1cd16c movlt r4, r9 */
/* @0x1cd170 vmov s7, r2 */
/* @0x1cd174 ldr r2, [r0, #0xc] */
/* @0x1cd178 vmov s11, r4 */
/* @0x1cd17c ldr r4, [sp, #0xc] */
/* @0x1cd180 vldr s10, [sp, #52] */
/* @0x1cd184 vcvt.f32.s32 s7, s7 */
/* @0x1cd188 cmp lr, r4 */
/* @0x1cd18c movlt lr, r4 */
/* @0x1cd190 ldr r4, [sp, #0x1c] */
/* @0x1cd194 cmp r4, r12 */
/* @0x1cd198 movge r4, r12 */
/* @0x1cd19c vmov s4, lr */
/* @0x1cd1a0 vmov s8, r4 */
/* @0x1cd1a4 ldr r4, [sp, #0x10] */
/* @0x1cd1a8 cmp r12, r4 */
/* @0x1cd1ac movge r12, r4 */
/* @0x1cd1b0 cmp r2, r1 */
/* @0x1cd1b4 movge r4, r2 */
/* @0x1cd1b8 movlt r4, r1 */
/* @0x1cd1bc vcvt.f32.s32 s9, s4 */
/* @0x1cd1c0 vmov s13, r4 */
/* @0x1cd1c4 ldr r4, [sp, #0x14] */
/* @0x1cd1c8 vmov s4, r12 */
/* @0x1cd1cc cmp r2, r4 */
/* @0x1cd1d0 movlt r2, r4 */
/* @0x1cd1d4 vmov s15, r2 */
/* @0x1cd1d8 vcvt.f32.s32 s8, s8 */
/* @0x1cd1dc vcvt.f32.s32 s12, s10 */
/* @0x1cd1e0 vcvt.f32.s32 s11, s11 */
/* @0x1cd1e4 vcvt.f32.s32 s10, s15 */
/* @0x1cd1e8 vcvt.f32.s32 s13, s13 */
/* @0x1cd1ec vcvt.f32.s32 s15, s4 */
/* @0x1cd1f0 vsub.f32 s13, s13, s8 */
/* @0x1cd1f4 vsub.f32 s15, s10, s15 */
/* @0x1cd1f8 vsub.f32 s11, s11, s7 */
/* @0x1cd1fc vsub.f32 s12, s9, s12 */
/* @0x1cd200 vmov.f32 s8, s6 */
/* @0x1cd204 vmov.f32 s10, s5 */
/* @0x1cd208 vnmls.f32 s8, s11, s13 */
/* @0x1cd20c vnmls.f32 s10, s12, s15 */
/* @0x1cd210 vsub.f32 s15, s8, s10 */
/* @0x1cd214 vcmpe.f32 s15, #0 */
/* @0x1cd218 vmrs APSR_nzcv, fpscr */
/* @0x1cd21c vneglt.f32 s15, s15 */
/* @0x1cd220 movlt r5, #1 */
/* @0x1cd224 vcmpe.f32 s15, s14 */
/* @0x1cd228 vmrs APSR_nzcv, fpscr */
/* @0x1cd22c bgt 0x1cd3ac <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x64c> */
/* @0x1cd230 vcmp.f32 s15, s14 */
/* @0x1cd234 add r2, r5, #8 */
/* @0x1cd238 add r4, sp, #368 */
/* @0x1cd23c add r12, r4, r6, lsl #2 */
/* @0x1cd240 add r2, r4, r2, lsl #2 */
/* @0x1cd244 vmrs APSR_nzcv, fpscr */
/* @0x1cd248 bne 0x1cd124 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x3c4> */
/* @0x1cd24c ldr r2, [r2, #-0x110] */
/* @0x1cd250 add r0, r0, #24 */
/* @0x1cd254 ldr r12, [r12, #-0xf0] */
/* @0x1cd258 cmp r2, r12 */
/* @0x1cd25c movlt r8, r3 */
/* @0x1cd260 add r3, r3, #1 */
/* @0x1cd264 movlt r6, r5 */
/* @0x1cd268 cmp r3, r7 */
/* @0x1cd26c bne 0x1cd134 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x3d4> */
/* @0x1cd270 mov r1, r6 */
/* @0x1cd274 mov r2, r11 */
/* @0x1cd278 mov r0, r8 */
/* @0x1cd27c bl 0x1cbcf4 <_Z19FINALIZE_Run_Globalv+0x288> */
/* @0x1cd280 ldr r3, [sp, #0x80] */
/* @0x1cd284 ldr r1, [sp, #0x84] */
/* @0x1cd288 ldr r7, [sp, #0x78] */
/* @0x1cd28c add r2, r3, r1 */
/* @0x1cd290 cmp r7, r2 */
/* @0x1cd294 ble 0x1cd308 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x5a8> */
/* @0x1cd298 ldr r2, [sp, #0x7c] */
/* @0x1cd29c rsb r2, r2, r7 */
/* @0x1cd2a0 cmp r3, r2 */
/* @0x1cd2a4 bge 0x1cd2b0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x550> */
/* @0x1cd2a8 cmp r1, r2 */
/* @0x1cd2ac blt 0x1cd0d0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x370> */
/* @0x1cd2b0 cmp r3, r2 */
/* @0x1cd2b4 movlt r6, #0 */
/* @0x1cd2b8 movge r6, #1 */
/* @0x1cd2bc cmp r7, #0 */
/* @0x1cd2c0 ble 0x1cd308 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x5a8> */
/* @0x1cd2c4 add r5, sp, #88 */
/* @0x1cd2c8 mov r4, #0 */
/* @0x1cd2cc b 0x1cd2dc <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x57c> */
/* @0x1cd2d0 add r4, r4, #1 */
/* @0x1cd2d4 cmp r4, r7 */
/* @0x1cd2d8 bge 0x1cd308 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x5a8> */
/* @0x1cd2dc ldr r3, [r5, #0x4]! */
/* @0x1cd2e0 cmn r3, #1 */
/* @0x1cd2e4 bne 0x1cd2d0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x570> */
/* @0x1cd2e8 mov r0, r4 */
/* @0x1cd2ec mov r1, r6 */
/* @0x1cd2f0 mov r2, r11 */
/* @0x1cd2f4 add r4, r4, #1 */
/* @0x1cd2f8 bl 0x1cbcf4 <_Z19FINALIZE_Run_Globalv+0x288> */
/* @0x1cd2fc ldr r7, [sp, #0x78] */
/* @0x1cd300 cmp r4, r7 */
/* @0x1cd304 blt 0x1cd2dc <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x57c> */
/* @0x1cd308 ldr r5, [sp, #0x2c] */
/* @0x1cd30c ldr r4, [r5, #0x4] */
/* @0x1cd310 ldr r7, [r4, #0x10] */
/* @0x1cd314 cmp r7, #0 */
/* @0x1cd318 beq 0x1cd3bc <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x65c> */
/* @0x1cd31c ldr r3, [r7] */
/* @0x1cd320 str r3, [r4, #0x10] */
/* @0x1cd324 ldr r5, [sp, #0x24] */
/* @0x1cd328 mov r4, #0 */
/* @0x1cd32c mvn r3, #0 */
/* @0x1cd330 str r4, [r7] */
/* @0x1cd334 str r3, [r7, #0x4] */
/* @0x1cd338 ldr r2, [sp, #0x78] */
/* @0x1cd33c ldr r3, [r5, #0x4] */
/* @0x1cd340 ldr r12, [sp, #0x30] */
/* @0x1cd344 cmp r2, r4 */
/* @0x1cd348 str r7, [r12] */
/* @0x1cd34c str r3, [r7, #0x4] */
/* @0x1cd350 str r4, [r5] */
/* @0x1cd354 ble 0x1cd3a4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x644> */
/* @0x1cd358 ldr r8, [sp, #0x2c] */
/* @0x1cd35c add r5, sp, #176 */
/* @0x1cd360 ldr r9, [sp, #0x24] */
/* @0x1cd364 add r6, sp, #88 */
/* @0x1cd368 ldr r2, [r6, #0x4]! */
/* @0x1cd36c add lr, sp, #368 */
/* @0x1cd370 str r9, [sp, #0x40] */
/* @0x1cd374 mov r1, r5 */
/* @0x1cd378 str r7, [sp, #0x44] */
/* @0x1cd37c mov r3, #0 */
/* @0x1cd380 add r2, lr, r2, lsl #2 */
/* @0x1cd384 mov r0, r8 */
/* @0x1cd388 add r4, r4, #1 */
/* @0x1cd38c add r5, r5, #24 */
/* @0x1cd390 ldr r2, [r2, #-0x130] */
/* @0x1cd394 bl 0x1cd45c <_ZN5RTreeIP9CInstanceifLi6ELi2EE9AddBranchEPKNS2_6BranchEPNS2_4NodeEPS7_> */
/* @0x1cd398 ldr r3, [sp, #0x78] */
/* @0x1cd39c cmp r4, r3 */
/* @0x1cd3a0 blt 0x1cd368 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x608> */
/* @0x1cd3a4 add sp, sp, #372 */
/* @0x1cd3a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1cd3ac vmov.f32 s14, s15 */
/* @0x1cd3b0 mov r6, r5 */
/* @0x1cd3b4 mov r8, r3 */
/* @0x1cd3b8 b 0x1cd124 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x3c4> */
/* @0x1cd3bc ldr r3, [r4, #0xc] */
/* @0x1cd3c0 ldr r2, [r4] */
/* @0x1cd3c4 cmp r3, r2 */
/* @0x1cd3c8 bge 0x1cd3f0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x690> */
/* @0x1cd3cc ldr r0, [r4, #0x8] */
/* @0x1cd3d0 mov r7, #152 */
/* @0x1cd3d4 ldr r2, [r4, #0x4] */
/* @0x1cd3d8 add r1, r3, #1 */
/* @0x1cd3dc sub r0, r0, #-1073741823 */
/* @0x1cd3e0 ldr r2, [r2, r0, lsl #2] */
/* @0x1cd3e4 str r1, [r4, #0xc] */
/* @0x1cd3e8 mla r7, r7, r3, r2 */
/* @0x1cd3ec b 0x1cd324 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x5c4> */
/* @0x1cd3f0 ldr r1, [r4, #0x8] */
/* @0x1cd3f4 mov r3, #74 */
/* @0x1cd3f8 ldr r6, [pc, #0x58] */
/* @0x1cd3fc add r1, r1, #1 */
/* @0x1cd400 ldr r0, [r4, #0x4] */
/* @0x1cd404 add r6, pc, r6 */
/* @0x1cd408 str r1, [r4, #0x8] */
/* @0x1cd40c str r7, [r4, #0xc] */
/* @0x1cd410 lsl r1, r1, #2 */
/* @0x1cd414 mov r2, r6 */
/* @0x1cd418 str r7, [sp] */
/* @0x1cd41c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1cd420 ldr r3, [r4] */
/* @0x1cd424 ldr r12, [r4, #0x8] */
/* @0x1cd428 mov r1, r6 */
/* @0x1cd42c mov r2, #70 */
/* @0x1cd430 sub r6, r12, #-1073741823 */
/* @0x1cd434 mov r5, r0 */
/* @0x1cd438 mov r0, #152 */
/* @0x1cd43c mul r0, r0, r3 */
/* @0x1cd440 str r5, [r4, #0x4] */
/* @0x1cd444 mov r3, #1 */
/* @0x1cd448 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1cd44c ldr r3, [r4, #0xc] */
/* @0x1cd450 str r0, [r5, r6, lsl #2] */
/* @0x1cd454 b 0x1cd3cc <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x66c> */
/* @0x1cd458 andseq r3, r6, r12, lsr #24 */

/* ── FUNC 0x1cd45c · RTree<CInstance*, int, float, 6, 2>::AddBranch(RTree<CInstance*, int, float, 6, 2>::Branch const*, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Node**) · size=96 · insn=24 */
/* @0x1cd45c push {r3, r4, r5, r6, r7, lr} */
/* @0x1cd460 mov r6, r2 */
/* @0x1cd464 ldr r5, [r6] */
/* @0x1cd468 mov r2, r1 */
/* @0x1cd46c cmp r5, #5 */
/* @0x1cd470 bgt 0x1cd4a8 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9AddBranchEPKNS2_6BranchEPNS2_4NodeEPS7_+0x4c> */
/* @0x1cd474 mov r4, r1 */
/* @0x1cd478 add r12, r5, r5, lsl #1 */
/* @0x1cd47c ldm r4!, {r0, r1, r2, r3} */
/* @0x1cd480 add r12, r6, r12, lsl #3 */
/* @0x1cd484 add r12, r12, #8 */
/* @0x1cd488 mov r7, #0 */
/* @0x1cd48c add r5, r5, #1 */
/* @0x1cd490 stm r12!, {r0, r1, r2, r3} */
/* @0x1cd494 ldm r4, {r0, r1} */
/* @0x1cd498 stm r12, {r0, r1} */
/* @0x1cd49c mov r0, r7 */
/* @0x1cd4a0 str r5, [r6] */
/* @0x1cd4a4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1cd4a8 mov r1, r6 */
/* @0x1cd4ac mov r7, #1 */
/* @0x1cd4b0 bl 0x1ccd60 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_> */
/* @0x1cd4b4 mov r0, r7 */
/* @0x1cd4b8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x1cd4bc · RTree<CInstance*, int, float, 6, 2>::InsertRectRec(RTree<CInstance*, int, float, 6, 2>::Branch const&, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Node**, int) · size=580 · insn=145 */
/* @0x1cd4bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1cd4c0 sub sp, sp, #76 */
/* @0x1cd4c4 ldr r12, [r2, #0x4] */
/* @0x1cd4c8 mov r5, r2 */
/* @0x1cd4cc ldr r4, [sp, #0x70] */
/* @0x1cd4d0 mov r6, r1 */
/* @0x1cd4d4 str r0, [sp, #0x10] */
/* @0x1cd4d8 cmp r12, r4 */
/* @0x1cd4dc str r3, [sp, #0x14] */
/* @0x1cd4e0 bgt 0x1cd4f4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x38> */
/* @0x1cd4e4 movne r0, #0 */
/* @0x1cd4e8 beq 0x1cd6a0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x1e4> */
/* @0x1cd4ec add sp, sp, #76 */
/* @0x1cd4f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1cd4f4 ldr r11, [r2] */
/* @0x1cd4f8 cmp r11, #0 */
/* @0x1cd4fc ble 0x1cd610 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x154> */
/* @0x1cd500 vmov.f32 s7, #-1.000000e+00 */
/* @0x1cd504 ldr r1, [r1] */
/* @0x1cd508 ldr r2, [r6, #0x8] */
/* @0x1cd50c mov r12, r5 */
/* @0x1cd510 ldr r3, [r6, #0x4] */
/* @0x1cd514 mov r0, #1 */
/* @0x1cd518 ldr r4, [r6, #0xc] */
/* @0x1cd51c mov lr, #0 */
/* @0x1cd520 str r5, [sp, #0xc] */
/* @0x1cd524 ldr r10, [r12, #0x10] */
/* @0x1cd528 ldr r5, [r12, #0x8] */
/* @0x1cd52c ldr r8, [r12, #0x14] */
/* @0x1cd530 ldr r9, [r12, #0xc] */
/* @0x1cd534 vmov s10, r10 */
/* @0x1cd538 vmov s11, r5 */
/* @0x1cd53c cmp r5, r1 */
/* @0x1cd540 vcvt.f32.s32 s12, s10 */
/* @0x1cd544 vmov s15, r8 */
/* @0x1cd548 vmov s10, r9 */
/* @0x1cd54c vcvt.f32.s32 s13, s11 */
/* @0x1cd550 vcvt.f32.s32 s14, s15 */
/* @0x1cd554 vcvt.f32.s32 s15, s10 */
/* @0x1cd558 vmovge s10, r1 */
/* @0x1cd55c vsub.f32 s6, s12, s13 */
/* @0x1cd560 vcvtge.f32.s32 s13, s10 */
/* @0x1cd564 cmp r10, r2 */
/* @0x1cd568 vmovle s10, r2 */
/* @0x1cd56c vsub.f32 s11, s14, s15 */
/* @0x1cd570 vcvtle.f32.s32 s12, s10 */
/* @0x1cd574 cmp r9, r3 */
/* @0x1cd578 vmovge s10, r3 */
/* @0x1cd57c vcvtge.f32.s32 s15, s10 */
/* @0x1cd580 cmp r8, r4 */
/* @0x1cd584 vmovle s10, r4 */
/* @0x1cd588 vcvtle.f32.s32 s14, s10 */
/* @0x1cd58c vmul.f32 s11, s6, s11 */
/* @0x1cd590 vsub.f32 s15, s14, s15 */
/* @0x1cd594 vsub.f32 s13, s12, s13 */
/* @0x1cd598 vmov.f32 s14, s11 */
/* @0x1cd59c vnmls.f32 s14, s13, s15 */
/* @0x1cd5a0 vcmpe.f32 s14, s7 */
/* @0x1cd5a4 vmov.f32 s15, s14 */
/* @0x1cd5a8 vmrs APSR_nzcv, fpscr */
/* @0x1cd5ac bmi 0x1cd5d0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x114> */
/* @0x1cd5b0 cmp r0, #0 */
/* @0x1cd5b4 bne 0x1cd5d0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x114> */
/* @0x1cd5b8 vcmp.f32 s14, s7 */
/* @0x1cd5bc vmrs APSR_nzcv, fpscr */
/* @0x1cd5c0 bne 0x1cd5f4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x138> */
/* @0x1cd5c4 vcmpe.f32 s11, s5 */
/* @0x1cd5c8 vmrs APSR_nzcv, fpscr */
/* @0x1cd5cc bpl 0x1cd5f4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x138> */
/* @0x1cd5d0 mov r7, lr */
/* @0x1cd5d4 add lr, lr, #1 */
/* @0x1cd5d8 cmp lr, r11 */
/* @0x1cd5dc add r12, r12, #24 */
/* @0x1cd5e0 beq 0x1cd60c <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x150> */
/* @0x1cd5e4 vmov.f32 s5, s11 */
/* @0x1cd5e8 mov r0, #0 */
/* @0x1cd5ec vmov.f32 s7, s15 */
/* @0x1cd5f0 b 0x1cd524 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x68> */
/* @0x1cd5f4 add lr, lr, #1 */
/* @0x1cd5f8 vmov.f32 s11, s5 */
/* @0x1cd5fc cmp lr, r11 */
/* @0x1cd600 add r12, r12, #24 */
/* @0x1cd604 vmov.f32 s15, s7 */
/* @0x1cd608 bne 0x1cd5e4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x128> */
/* @0x1cd60c ldr r5, [sp, #0xc] */
/* @0x1cd610 ldr r4, [sp, #0x70] */
/* @0x1cd614 add r7, r7, r7, lsl #1 */
/* @0x1cd618 ldr r0, [sp, #0x10] */
/* @0x1cd61c mov r1, r6 */
/* @0x1cd620 lsl r7, r7, #3 */
/* @0x1cd624 add r3, sp, #44 */
/* @0x1cd628 str r4, [sp] */
/* @0x1cd62c add r4, r5, r7 */
/* @0x1cd630 ldr r2, [r4, #0x18] */
/* @0x1cd634 bl 0x1cd4bc <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i> */
/* @0x1cd638 cmp r0, #0 */
/* @0x1cd63c bne 0x1cd6ac <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x1f0> */
/* @0x1cd640 add r2, r7, #8 */
/* @0x1cd644 ldr r4, [r6, #0x8] */
/* @0x1cd648 add r3, r5, r2 */
/* @0x1cd64c ldr r8, [r6, #0x4] */
/* @0x1cd650 ldr r1, [r6, #0xc] */
/* @0x1cd654 ldr r10, [r5, r2] */
/* @0x1cd658 ldr r6, [r6] */
/* @0x1cd65c ldr r7, [r3, #0x8] */
/* @0x1cd660 ldr r9, [r3, #0x4] */
/* @0x1cd664 ldr r12, [r3, #0xc] */
/* @0x1cd668 cmp r10, r6 */
/* @0x1cd66c strle r10, [r5, r2] */
/* @0x1cd670 strgt r6, [r5, r2] */
/* @0x1cd674 cmp r9, r8 */
/* @0x1cd678 strle r9, [r3, #0x4] */
/* @0x1cd67c strgt r8, [r3, #0x4] */
/* @0x1cd680 cmp r7, r4 */
/* @0x1cd684 strge r7, [r3, #0x8] */
/* @0x1cd688 strlt r4, [r3, #0x8] */
/* @0x1cd68c cmp r12, r1 */
/* @0x1cd690 strge r12, [r3, #0xc] */
/* @0x1cd694 strlt r1, [r3, #0xc] */
/* @0x1cd698 add sp, sp, #76 */
/* @0x1cd69c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1cd6a0 bl 0x1cd45c <_ZN5RTreeIP9CInstanceifLi6ELi2EE9AddBranchEPKNS2_6BranchEPNS2_4NodeEPS7_> */
/* @0x1cd6a4 add sp, sp, #76 */
/* @0x1cd6a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1cd6ac ldr r1, [r4, #0x18] */
/* @0x1cd6b0 add r6, r4, #8 */
/* @0x1cd6b4 add r4, sp, #24 */
/* @0x1cd6b8 mov r0, r4 */
/* @0x1cd6bc bl 0x1cbc60 <_Z19FINALIZE_Run_Globalv+0x1f4> */
/* @0x1cd6c0 ldm r4, {r0, r1, r2, r3} */
/* @0x1cd6c4 ldr r12, [sp, #0x2c] */
/* @0x1cd6c8 stm r6, {r0, r1, r2, r3} */
/* @0x1cd6cc mov r0, r4 */
/* @0x1cd6d0 mov r1, r12 */
/* @0x1cd6d4 str r12, [sp, #0x40] */
/* @0x1cd6d8 bl 0x1cbc60 <_Z19FINALIZE_Run_Globalv+0x1f4> */
/* @0x1cd6dc ldm r4, {r0, r1, r2, r3} */
/* @0x1cd6e0 add r12, sp, #48 */
/* @0x1cd6e4 stm r12, {r0, r1, r2, r3} */
/* @0x1cd6e8 mov r1, r12 */
/* @0x1cd6ec ldr r0, [sp, #0x10] */
/* @0x1cd6f0 mov r2, r5 */
/* @0x1cd6f4 ldr r3, [sp, #0x14] */
/* @0x1cd6f8 bl 0x1cd45c <_ZN5RTreeIP9CInstanceifLi6ELi2EE9AddBranchEPKNS2_6BranchEPNS2_4NodeEPS7_> */
/* @0x1cd6fc b 0x1cd4ec <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x30> */

/* ── FUNC 0x1cd700 · RTree<CInstance*, int, float, 6, 2>::InsertRect(RTree<CInstance*, int, float, 6, 2>::Branch const&, RTree<CInstance*, int, float, 6, 2>::Node**, int) · size=380 · insn=95 */
/* @0x1cd700 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1cd704 sub sp, sp, #60 */
/* @0x1cd708 mov r7, r2 */
/* @0x1cd70c mov r8, r0 */
/* @0x1cd710 str r3, [sp] */
/* @0x1cd714 add r3, sp, #28 */
/* @0x1cd718 ldr r2, [r2] */
/* @0x1cd71c bl 0x1cd4bc <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i> */
/* @0x1cd720 cmp r0, #0 */
/* @0x1cd724 bne 0x1cd730 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi+0x30> */
/* @0x1cd728 add sp, sp, #60 */
/* @0x1cd72c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1cd730 ldr r4, [r8, #0x4] */
/* @0x1cd734 ldr r6, [r4, #0x10] */
/* @0x1cd738 cmp r6, #0 */
/* @0x1cd73c beq 0x1cd7dc <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi+0xdc> */
/* @0x1cd740 ldr r3, [r6] */
/* @0x1cd744 str r3, [r4, #0x10] */
/* @0x1cd748 ldr r1, [r7] */
/* @0x1cd74c add r4, sp, #8 */
/* @0x1cd750 mov r9, #0 */
/* @0x1cd754 mvn r3, #0 */
/* @0x1cd758 str r9, [r6] */
/* @0x1cd75c mov r0, r4 */
/* @0x1cd760 str r3, [r6, #0x4] */
/* @0x1cd764 add r5, sp, #32 */
/* @0x1cd768 ldr r3, [r1, #0x4] */
/* @0x1cd76c add r3, r3, #1 */
/* @0x1cd770 str r3, [r6, #0x4] */
/* @0x1cd774 bl 0x1cbc60 <_Z19FINALIZE_Run_Globalv+0x1f4> */
/* @0x1cd778 ldm r4, {r0, r1, r2, r3} */
/* @0x1cd77c ldr r12, [r7] */
/* @0x1cd780 stm r5, {r0, r1, r2, r3} */
/* @0x1cd784 mov r3, r9 */
/* @0x1cd788 mov r2, r6 */
/* @0x1cd78c mov r1, r5 */
/* @0x1cd790 mov r0, r8 */
/* @0x1cd794 str r12, [sp, #0x30] */
/* @0x1cd798 bl 0x1cd45c <_ZN5RTreeIP9CInstanceifLi6ELi2EE9AddBranchEPKNS2_6BranchEPNS2_4NodeEPS7_> */
/* @0x1cd79c mov r0, r4 */
/* @0x1cd7a0 ldr r1, [sp, #0x1c] */
/* @0x1cd7a4 bl 0x1cbc60 <_Z19FINALIZE_Run_Globalv+0x1f4> */
/* @0x1cd7a8 ldm r4, {r0, r1, r2, r3} */
/* @0x1cd7ac ldr r12, [sp, #0x1c] */
/* @0x1cd7b0 stm r5, {r0, r1, r2, r3} */
/* @0x1cd7b4 mov r1, r5 */
/* @0x1cd7b8 mov r3, r9 */
/* @0x1cd7bc mov r0, r8 */
/* @0x1cd7c0 mov r2, r6 */
/* @0x1cd7c4 str r12, [sp, #0x30] */
/* @0x1cd7c8 bl 0x1cd45c <_ZN5RTreeIP9CInstanceifLi6ELi2EE9AddBranchEPKNS2_6BranchEPNS2_4NodeEPS7_> */
/* @0x1cd7cc mov r0, #1 */
/* @0x1cd7d0 str r6, [r7] */
/* @0x1cd7d4 add sp, sp, #60 */
/* @0x1cd7d8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1cd7dc ldr r3, [r4, #0xc] */
/* @0x1cd7e0 ldr r2, [r4] */
/* @0x1cd7e4 cmp r3, r2 */
/* @0x1cd7e8 bge 0x1cd810 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi+0x110> */
/* @0x1cd7ec ldr r0, [r4, #0x8] */
/* @0x1cd7f0 mov r6, #152 */
/* @0x1cd7f4 ldr r2, [r4, #0x4] */
/* @0x1cd7f8 add r1, r3, #1 */
/* @0x1cd7fc sub r0, r0, #-1073741823 */
/* @0x1cd800 ldr r2, [r2, r0, lsl #2] */
/* @0x1cd804 str r1, [r4, #0xc] */
/* @0x1cd808 mla r6, r6, r3, r2 */
/* @0x1cd80c b 0x1cd748 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi+0x48> */
/* @0x1cd810 ldr r1, [r4, #0x8] */
/* @0x1cd814 mov r3, #74 */
/* @0x1cd818 ldr r2, [pc, #0x58] */
/* @0x1cd81c add r1, r1, #1 */
/* @0x1cd820 str r6, [r4, #0xc] */
/* @0x1cd824 add r2, pc, r2 */
/* @0x1cd828 str r1, [r4, #0x8] */
/* @0x1cd82c ldr r0, [r4, #0x4] */
/* @0x1cd830 lsl r1, r1, #2 */
/* @0x1cd834 str r6, [sp] */
/* @0x1cd838 mov r6, r2 */
/* @0x1cd83c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1cd840 ldr r3, [r4] */
/* @0x1cd844 ldr r12, [r4, #0x8] */
/* @0x1cd848 mov r1, r6 */
/* @0x1cd84c mov r2, #70 */
/* @0x1cd850 sub r6, r12, #-1073741823 */
/* @0x1cd854 mov r5, r0 */
/* @0x1cd858 mov r0, #152 */
/* @0x1cd85c mul r0, r0, r3 */
/* @0x1cd860 str r5, [r4, #0x4] */
/* @0x1cd864 mov r3, #1 */
/* @0x1cd868 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1cd86c ldr r3, [r4, #0xc] */
/* @0x1cd870 str r0, [r5, r6, lsl #2] */
/* @0x1cd874 b 0x1cd7ec <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi+0xec> */
/* @0x1cd878 andseq r3, r6, r12, lsl #16 */

/* ── FUNC 0x1cd87c · RTree<CInstance*, int, float, 6, 2>::RemoveRect(RTree<CInstance*, int, float, 6, 2>::Rect*, CInstance* const&, RTree<CInstance*, int, float, 6, 2>::Node**) · size=252 · insn=63 */
/* @0x1cd87c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1cd880 sub sp, sp, #20 */
/* @0x1cd884 add r12, sp, #16 */
/* @0x1cd888 mov lr, #0 */
/* @0x1cd88c mov r8, r3 */
/* @0x1cd890 ldr r3, [r3] */
/* @0x1cd894 str lr, [r12, #-0x4]! */
/* @0x1cd898 mov r7, r0 */
/* @0x1cd89c str r12, [sp] */
/* @0x1cd8a0 bl 0x1ccb94 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE> */
/* @0x1cd8a4 subs r9, r0, #0 */
/* @0x1cd8a8 bne 0x1cd93c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0xc0> */
/* @0x1cd8ac ldr r3, [sp, #0xc] */
/* @0x1cd8b0 cmp r3, #0 */
/* @0x1cd8b4 beq 0x1cd92c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0xb0> */
/* @0x1cd8b8 ldr r6, [r3, #0x4] */
/* @0x1cd8bc ldr r2, [r6] */
/* @0x1cd8c0 cmp r2, #0 */
/* @0x1cd8c4 addgt r5, r6, #8 */
/* @0x1cd8c8 movgt r4, #0 */
/* @0x1cd8cc ble 0x1cd8fc <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0x80> */
/* @0x1cd8d0 mov r1, r5 */
/* @0x1cd8d4 mov r0, r7 */
/* @0x1cd8d8 mov r2, r8 */
/* @0x1cd8dc ldr r3, [r6, #0x4] */
/* @0x1cd8e0 bl 0x1cd700 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi> */
/* @0x1cd8e4 ldr r1, [r6] */
/* @0x1cd8e8 add r4, r4, #1 */
/* @0x1cd8ec add r5, r5, #24 */
/* @0x1cd8f0 cmp r1, r4 */
/* @0x1cd8f4 bgt 0x1cd8d0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0x54> */
/* @0x1cd8f8 ldr r3, [sp, #0xc] */
/* @0x1cd8fc ldr r2, [r7, #0x4] */
/* @0x1cd900 mov r0, r3 */
/* @0x1cd904 ldr r12, [r3] */
/* @0x1cd908 ldr r3, [r3, #0x4] */
/* @0x1cd90c ldr r1, [r2, #0x10] */
/* @0x1cd910 str r12, [sp, #0xc] */
/* @0x1cd914 str r3, [r2, #0x10] */
/* @0x1cd918 str r1, [r3] */
/* @0x1cd91c bl 0x27d1d0 <_ZdlPv> */
/* @0x1cd920 ldr r3, [sp, #0xc] */
/* @0x1cd924 cmp r3, #0 */
/* @0x1cd928 bne 0x1cd8b8 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0x3c> */
/* @0x1cd92c ldr r3, [r8] */
/* @0x1cd930 ldr r2, [r3] */
/* @0x1cd934 cmp r2, #1 */
/* @0x1cd938 beq 0x1cd948 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0xcc> */
/* @0x1cd93c mov r0, r9 */
/* @0x1cd940 add sp, sp, #20 */
/* @0x1cd944 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1cd948 ldr r2, [r3, #0x4] */
/* @0x1cd94c cmp r2, #0 */
/* @0x1cd950 ble 0x1cd93c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0xc0> */
/* @0x1cd954 ldr r2, [r7, #0x4] */
/* @0x1cd958 ldr r1, [r3, #0x18] */
/* @0x1cd95c ldr r0, [r2, #0x10] */
/* @0x1cd960 str r3, [r2, #0x10] */
/* @0x1cd964 str r0, [r3] */
/* @0x1cd968 mov r0, r9 */
/* @0x1cd96c str r1, [r8] */
/* @0x1cd970 add sp, sp, #20 */
/* @0x1cd974 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x1cd978 · RTree<CInstance*, int, float, 6, 2>::Remove(int const*, int const*, CInstance* const&, bool) · size=120 · insn=30 */
/* @0x1cd978 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1cd97c add r5, r0, #16 */
/* @0x1cd980 sub sp, sp, #36 */
/* @0x1cd984 ldr r9, [r1] */
/* @0x1cd988 ldr r8, [r1, #0x4] */
/* @0x1cd98c mov r6, r3 */
/* @0x1cd990 ldr lr, [r2] */
/* @0x1cd994 mov r3, r5 */
/* @0x1cd998 ldr r12, [r2, #0x4] */
/* @0x1cd99c mov r1, sp */
/* @0x1cd9a0 mov r2, r6 */
/* @0x1cd9a4 ldrb r7, [sp, #0x40] */
/* @0x1cd9a8 mov r4, r0 */
/* @0x1cd9ac str r9, [sp] */
/* @0x1cd9b0 stmib sp, {r8, lr} */
/* @0x1cd9b4 str r12, [sp, #0xc] */
/* @0x1cd9b8 bl 0x1cd87c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE> */
/* @0x1cd9bc tst r0, r7 */
/* @0x1cd9c0 beq 0x1cd9e8 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6RemoveEPKiS4_RKS1_b+0x70> */
/* @0x1cd9c4 add r7, sp, #16 */
/* @0x1cd9c8 ldr r1, [r4, #0x10] */
/* @0x1cd9cc mov r0, r7 */
/* @0x1cd9d0 bl 0x1cbc60 <_Z19FINALIZE_Run_Globalv+0x1f4> */
/* @0x1cd9d4 mov r0, r4 */
/* @0x1cd9d8 mov r1, r7 */
/* @0x1cd9dc mov r2, r6 */
/* @0x1cd9e0 mov r3, r5 */
/* @0x1cd9e4 bl 0x1cd87c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE> */
/* @0x1cd9e8 add sp, sp, #36 */
/* @0x1cd9ec pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x1cd9f0 · CollisionRemove(CInstance*) · size=300 · insn=75 */
/* @0x1cd9f0 push {r4, r5, r6, r7, lr} */
/* @0x1cd9f4 sub sp, sp, #36 */
/* @0x1cd9f8 ldr r4, [pc, #0x108] */
/* @0x1cd9fc ldr r3, [pc, #0x108] */
/* @0x1cda00 add r4, pc, r4 */
/* @0x1cda04 str r0, [sp, #0xc] */
/* @0x1cda08 ldr r3, [r4, r3] */
/* @0x1cda0c ldrb r3, [r3] */
/* @0x1cda10 cmp r3, #0 */
/* @0x1cda14 beq 0x1cdb00 <_Z15CollisionRemoveP9CInstance+0x110> */
/* @0x1cda18 ldr r3, [pc, #0xf0] */
/* @0x1cda1c ldr r3, [r4, r3] */
/* @0x1cda20 ldr r2, [r3] */
/* @0x1cda24 cmp r2, #0 */
/* @0x1cda28 beq 0x1cda8c <_Z15CollisionRemoveP9CInstance+0x9c> */
/* @0x1cda2c mov r3, r0 */
/* @0x1cda30 ldr r5, [r0, #0xe8] */
/* @0x1cda34 ldr r6, [r3, #0xf0] */
/* @0x1cda38 mov r7, #1 */
/* @0x1cda3c ldr r12, [r3, #0xec] */
/* @0x1cda40 mov r0, r2 */
/* @0x1cda44 ldr lr, [r3, #0xf4] */
/* @0x1cda48 add r1, sp, #16 */
/* @0x1cda4c add r2, sp, #24 */
/* @0x1cda50 add r3, sp, #12 */
/* @0x1cda54 str r7, [sp] */
/* @0x1cda58 cmp r6, r5 */
/* @0x1cda5c strle r6, [sp, #0x10] */
/* @0x1cda60 strgt r5, [sp, #0x10] */
/* @0x1cda64 cmp r6, r5 */
/* @0x1cda68 strge r6, [sp, #0x18] */
/* @0x1cda6c strlt r5, [sp, #0x18] */
/* @0x1cda70 cmp lr, r12 */
/* @0x1cda74 strle lr, [sp, #0x14] */
/* @0x1cda78 strgt r12, [sp, #0x14] */
/* @0x1cda7c cmp lr, r12 */
/* @0x1cda80 strge lr, [sp, #0x1c] */
/* @0x1cda84 strlt r12, [sp, #0x1c] */
/* @0x1cda88 bl 0x1cd978 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6RemoveEPKiS4_RKS1_b> */
/* @0x1cda8c ldr r3, [sp, #0xc] */
/* @0x1cda90 ldr r2, [pc, #0x7c] */
/* @0x1cda94 ldr r12, [pc, #0x7c] */
/* @0x1cda98 add r1, r3, #408 */
/* @0x1cda9c ldr r0, [r3, #0x1a0] */
/* @0x1cdaa0 ldr r2, [r4, r2] */
/* @0x1cdaa4 cmp r0, r2 */
/* @0x1cdaa8 ldreq r0, [r3, #0x19c] */
/* @0x1cdaac ldreq r2, [r3, #0x198] */
/* @0x1cdab0 streq r0, [r2, #0x4] */
/* @0x1cdab4 ldreq r0, [r3, #0x19c] */
/* @0x1cdab8 streq r2, [r0] */
/* @0x1cdabc mov r0, #0 */
/* @0x1cdac0 str r1, [r3, #0x198] */
/* @0x1cdac4 add r2, r3, #396 */
/* @0x1cdac8 str r0, [r3, #0x1a0] */
/* @0x1cdacc str r1, [r3, #0x19c] */
/* @0x1cdad0 ldr r0, [r3, #0x194] */
/* @0x1cdad4 ldr r1, [r4, r12] */
/* @0x1cdad8 cmp r0, r1 */
/* @0x1cdadc ldreq r1, [r3, #0x18c] */
/* @0x1cdae0 ldreq r0, [r3, #0x190] */
/* @0x1cdae4 streq r0, [r1, #0x4] */
/* @0x1cdae8 ldreq r0, [r3, #0x190] */
/* @0x1cdaec streq r1, [r0] */
/* @0x1cdaf0 mov r1, #0 */
/* @0x1cdaf4 str r2, [r3, #0x18c] */
/* @0x1cdaf8 str r2, [r3, #0x190] */
/* @0x1cdafc str r1, [r3, #0x194] */
/* @0x1cdb00 add sp, sp, #36 */
/* @0x1cdb04 pop {r4, r5, r6, r7, pc} */
/* @0x1cdb08 eoreq r4, r2, r0, asr r2 */
/* @0x1cdb0c .word 0xffffea30 */
/* @0x1cdb10 .word 0xffffc5f4 */
/* @0x1cdb14 .word 0xffffeeec */
/* @0x1cdb18 .word 0xffffeee4 */

/* ── FUNC 0x1cdb1c · RebuildTree() · size=256 · insn=64 */
/* @0x1cdb1c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1cdb20 mov r0, #24 */
/* @0x1cdb24 sub sp, sp, #28 */
/* @0x1cdb28 ldr r5, [pc, #0xe4] */
/* @0x1cdb2c bl 0x27c524 <_Znwj> */
/* @0x1cdb30 mov r1, #1024 */
/* @0x1cdb34 mov r4, r0 */
/* @0x1cdb38 bl 0x1cc320 <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei> */
/* @0x1cdb3c ldr r3, [pc, #0xd4] */
/* @0x1cdb40 ldr r5, [pc, r5] */
/* @0x1cdb44 ldr r3, [pc, r3] */
/* @0x1cdb48 str r4, [r5] */
/* @0x1cdb4c ldr r3, [r3] */
/* @0x1cdb50 ldr r2, [r3, #0x80] */
/* @0x1cdb54 cmp r2, #0 */
/* @0x1cdb58 beq 0x1cdbfc <_Z11RebuildTreev+0xe0> */
/* @0x1cdb5c ldrb r3, [r2, #0x68] */
/* @0x1cdb60 ldr r4, [r2, #0x178] */
/* @0x1cdb64 cmp r3, #0 */
/* @0x1cdb68 bne 0x1cdbf0 <_Z11RebuildTreev+0xd4> */
/* @0x1cdb6c ldrb r3, [r2, #0x69] */
/* @0x1cdb70 cmp r3, #0 */
/* @0x1cdb74 bne 0x1cdbf0 <_Z11RebuildTreev+0xd4> */
/* @0x1cdb78 ldr r3, [r2, #0x80] */
/* @0x1cdb7c ldr r3, [r3] */
/* @0x1cdb80 tst r3, #16 */
/* @0x1cdb84 beq 0x1cdbf0 <_Z11RebuildTreev+0xd4> */
/* @0x1cdb88 ldrb r12, [r2, #0x64] */
/* @0x1cdb8c mov r1, sp */
/* @0x1cdb90 cmp r12, #0 */
/* @0x1cdb94 mov r3, r12 */
/* @0x1cdb98 bne 0x1cdc04 <_Z11RebuildTreev+0xe8> */
/* @0x1cdb9c ldr r8, [r2, #0xe8] */
/* @0x1cdba0 ldr r9, [r2, #0xf0] */
/* @0x1cdba4 ldr lr, [r2, #0xec] */
/* @0x1cdba8 ldr r7, [r2, #0xf4] */
/* @0x1cdbac ldr r0, [r5] */
/* @0x1cdbb0 str r2, [sp, #0x14] */
/* @0x1cdbb4 add r2, r0, #16 */
/* @0x1cdbb8 str r12, [sp, #0x10] */
/* @0x1cdbbc cmp r9, r8 */
/* @0x1cdbc0 strle r9, [sp] */
/* @0x1cdbc4 strgt r8, [sp] */
/* @0x1cdbc8 cmp r9, r8 */
/* @0x1cdbcc strge r9, [sp, #0x8] */
/* @0x1cdbd0 strlt r8, [sp, #0x8] */
/* @0x1cdbd4 cmp r7, lr */
/* @0x1cdbd8 strle r7, [sp, #0x4] */
/* @0x1cdbdc strgt lr, [sp, #0x4] */
/* @0x1cdbe0 cmp r7, lr */
/* @0x1cdbe4 strge r7, [sp, #0xc] */
/* @0x1cdbe8 strlt lr, [sp, #0xc] */
/* @0x1cdbec bl 0x1cd700 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi> */
/* @0x1cdbf0 cmp r4, #0 */
/* @0x1cdbf4 mov r2, r4 */
/* @0x1cdbf8 bne 0x1cdb5c <_Z11RebuildTreev+0x40> */
/* @0x1cdbfc add sp, sp, #28 */
/* @0x1cdc00 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1cdc04 mov r1, #1 */
/* @0x1cdc08 mov r0, r2 */
/* @0x1cdc0c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cdc10 b 0x1cdbf0 <_Z11RebuildTreev+0xd4> */
/* @0x1cdc14 eoreq r0, r2, r4, lsl #14 */
/* @0x1cdc18 eoreq pc, r1, r4, ror #27 */

/* ── FUNC 0x1cdc1c · CollisionUpdate(CInstance*, tagYYRECT&) · size=340 · insn=85 */
/* @0x1cdc1c ldr r3, [pc, #0x144] */
/* @0x1cdc20 push {r4, r5, r6, r7, lr} */
/* @0x1cdc24 ldr r3, [pc, r3] */
/* @0x1cdc28 sub sp, sp, #60 */
/* @0x1cdc2c mov r4, r1 */
/* @0x1cdc30 ldrb r3, [r3] */
/* @0x1cdc34 str r0, [sp, #0xc] */
/* @0x1cdc38 cmp r3, #0 */
/* @0x1cdc3c beq 0x1cdc4c <_Z15CollisionUpdateP9CInstanceR9tagYYRECT+0x30> */
/* @0x1cdc40 ldrb r3, [r0, #0x68] */
/* @0x1cdc44 cmp r3, #0 */
/* @0x1cdc48 beq 0x1cdc54 <_Z15CollisionUpdateP9CInstanceR9tagYYRECT+0x38> */
/* @0x1cdc4c add sp, sp, #60 */
/* @0x1cdc50 pop {r4, r5, r6, r7, pc} */
/* @0x1cdc54 ldrb r3, [r0, #0x69] */
/* @0x1cdc58 cmp r3, #0 */
/* @0x1cdc5c bne 0x1cdc4c <_Z15CollisionUpdateP9CInstanceR9tagYYRECT+0x30> */
/* @0x1cdc60 ldr r3, [r0, #0x80] */
/* @0x1cdc64 ldr r3, [r3] */
/* @0x1cdc68 tst r3, #16 */
/* @0x1cdc6c beq 0x1cdc4c <_Z15CollisionUpdateP9CInstanceR9tagYYRECT+0x30> */
/* @0x1cdc70 ldr r5, [pc, #0xf4] */
/* @0x1cdc74 ldr r5, [pc, r5] */
/* @0x1cdc78 ldr r0, [r5] */
/* @0x1cdc7c cmp r0, #0 */
/* @0x1cdc80 beq 0x1cdd48 <_Z15CollisionUpdateP9CInstanceR9tagYYRECT+0x12c> */
/* @0x1cdc84 ldr r6, [r4] */
/* @0x1cdc88 add r1, sp, #16 */
/* @0x1cdc8c ldr r7, [r4, #0x8] */
/* @0x1cdc90 add r2, sp, #24 */
/* @0x1cdc94 ldr r12, [r4, #0x4] */
/* @0x1cdc98 mov r3, #1 */
/* @0x1cdc9c ldr lr, [r4, #0xc] */
/* @0x1cdca0 str r3, [sp] */
/* @0x1cdca4 add r3, sp, #12 */
/* @0x1cdca8 cmp r7, r6 */
/* @0x1cdcac strle r7, [sp, #0x10] */
/* @0x1cdcb0 strgt r6, [sp, #0x10] */
/* @0x1cdcb4 cmp lr, r12 */
/* @0x1cdcb8 strle lr, [sp, #0x14] */
/* @0x1cdcbc strgt r12, [sp, #0x14] */
/* @0x1cdcc0 cmp lr, r12 */
/* @0x1cdcc4 strge lr, [sp, #0x1c] */
/* @0x1cdcc8 strlt r12, [sp, #0x1c] */
/* @0x1cdccc cmp r7, r6 */
/* @0x1cdcd0 strge r7, [sp, #0x18] */
/* @0x1cdcd4 strlt r6, [sp, #0x18] */
/* @0x1cdcd8 bl 0x1cd978 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6RemoveEPKiS4_RKS1_b> */
/* @0x1cdcdc ldr r12, [sp, #0xc] */
/* @0x1cdce0 mov r2, #0 */
/* @0x1cdce4 ldr r0, [r5] */
/* @0x1cdce8 mov r3, r2 */
/* @0x1cdcec str r2, [sp, #0x30] */
/* @0x1cdcf0 add r1, sp, #32 */
/* @0x1cdcf4 ldr r5, [r12, #0xe8] */
/* @0x1cdcf8 add r2, r0, #16 */
/* @0x1cdcfc ldr r6, [r12, #0xf0] */
/* @0x1cdd00 ldr lr, [r12, #0xec] */
/* @0x1cdd04 ldr r4, [r12, #0xf4] */
/* @0x1cdd08 str r12, [sp, #0x34] */
/* @0x1cdd0c cmp r6, r5 */
/* @0x1cdd10 strle r6, [sp, #0x20] */
/* @0x1cdd14 strgt r5, [sp, #0x20] */
/* @0x1cdd18 cmp r6, r5 */
/* @0x1cdd1c strge r6, [sp, #0x28] */
/* @0x1cdd20 strlt r5, [sp, #0x28] */
/* @0x1cdd24 cmp r4, lr */
/* @0x1cdd28 strle r4, [sp, #0x24] */
/* @0x1cdd2c strgt lr, [sp, #0x24] */
/* @0x1cdd30 cmp r4, lr */
/* @0x1cdd34 strge r4, [sp, #0x2c] */
/* @0x1cdd38 strlt lr, [sp, #0x2c] */
/* @0x1cdd3c bl 0x1cd700 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi> */
/* @0x1cdd40 add sp, sp, #60 */
/* @0x1cdd44 pop {r4, r5, r6, r7, pc} */
/* @0x1cdd48 mov r0, #24 */
/* @0x1cdd4c bl 0x27c524 <_Znwj> */
/* @0x1cdd50 mov r1, #1024 */
/* @0x1cdd54 mov r6, r0 */
/* @0x1cdd58 bl 0x1cc320 <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei> */
/* @0x1cdd5c str r6, [r5] */
/* @0x1cdd60 mov r0, r6 */
/* @0x1cdd64 b 0x1cdc84 <_Z15CollisionUpdateP9CInstanceR9tagYYRECT+0x68> */
/* @0x1cdd68 eoreq r2, r2, r12, asr r10 */
/* @0x1cdd6c .word 0x002205d0 */

/* ── FUNC 0x1cdd70 · HandleAlarm() · size=508 · insn=127 */
/* @0x1cdd70 ldr r12, [pc, #0x1d8] */
/* @0x1cdd74 ldr r3, [pc, #0x1d8] */
/* @0x1cdd78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1cdd7c add r12, pc, r12 */
/* @0x1cdd80 sub sp, sp, #20 */
/* @0x1cdd84 str r12, [sp, #0x8] */
/* @0x1cdd88 ldr r3, [r12, r3] */
/* @0x1cdd8c str r3, [sp, #0xc] */
/* @0x1cdd90 ldrb r3, [r3] */
/* @0x1cdd94 cmp r3, #0 */
/* @0x1cdd98 bne 0x1cdf38 <_Z11HandleAlarmv+0x1c8> */
/* @0x1cdd9c ldr r3, [pc, #0x1b4] */
/* @0x1cdda0 mov r6, #0 */
/* @0x1cdda4 ldr r12, [sp, #0x8] */
/* @0x1cdda8 ldr r0, [pc, #0x1ac] */
/* @0x1cddac ldr r1, [r12, r3] */
/* @0x1cddb0 ldrd r4, r5, [r1] */
/* @0x1cddb4 adds r2, r4, #1 */
/* @0x1cddb8 adc r3, r5, #0 */
/* @0x1cddbc strd r2, r3, [r1] */
/* @0x1cddc0 ldr r9, [r12, r0] */
/* @0x1cddc4 add r9, r9, #2048 */
/* @0x1cddc8 ldr r3, [r9], #4 */
/* @0x1cddcc cmp r3, #0 */
/* @0x1cddd0 ble 0x1cdefc <_Z11HandleAlarmv+0x18c> */
/* @0x1cddd4 ldr r12, [sp, #0x8] */
/* @0x1cddd8 mov r7, #0 */
/* @0x1cdddc ldr r2, [pc, #0x17c] */
/* @0x1cdde0 ldr r3, [pc, #0x17c] */
/* @0x1cdde4 ldr r8, [r12, r2] */
/* @0x1cdde8 ldr r3, [r12, r3] */
/* @0x1cddec add r8, r8, r6, lsl #3 */
/* @0x1cddf0 add r8, r8, #4096 */
/* @0x1cddf4 add r8, r8, #4 */
/* @0x1cddf8 str r3, [sp, #0x4] */
/* @0x1cddfc ldr r12, [sp, #0x4] */
/* @0x1cde00 ldr r1, [r8] */
/* @0x1cde04 ldr r3, [r12] */
/* @0x1cde08 ldr r1, [r1, r7, lsl #2] */
/* @0x1cde0c ldr r2, [r3, #0x4] */
/* @0x1cde10 ldr r3, [r3] */
/* @0x1cde14 and r2, r1, r2 */
/* @0x1cde18 ldr r3, [r3, r2, lsl #3] */
/* @0x1cde1c cmp r3, #0 */
/* @0x1cde20 bne 0x1cde34 <_Z11HandleAlarmv+0xc4> */
/* @0x1cde24 b 0x1cde44 <_Z11HandleAlarmv+0xd4> */
/* @0x1cde28 ldr r3, [r3, #0x4] */
/* @0x1cde2c cmp r3, #0 */
/* @0x1cde30 beq 0x1cde44 <_Z11HandleAlarmv+0xd4> */
/* @0x1cde34 ldr r2, [r3, #0x8] */
/* @0x1cde38 cmp r1, r2 */
/* @0x1cde3c bne 0x1cde28 <_Z11HandleAlarmv+0xb8> */
/* @0x1cde40 ldr r3, [r3, #0xc] */
/* @0x1cde44 ldr r10, [r3, #0xc4] */
/* @0x1cde48 cmp r10, #0 */
/* @0x1cde4c beq 0x1cdeec <_Z11HandleAlarmv+0x17c> */
/* @0x1cde50 ldr r3, [r10, #0x8] */
/* @0x1cde54 cmp r3, #0 */
/* @0x1cde58 beq 0x1cdeec <_Z11HandleAlarmv+0x17c> */
/* @0x1cde5c ldr r11, [r10, #0x8] */
/* @0x1cde60 ldr r10, [r10] */
/* @0x1cde64 ldrb r3, [r11, #0x68] */
/* @0x1cde68 cmp r3, #0 */
/* @0x1cde6c bne 0x1cde48 <_Z11HandleAlarmv+0xd8> */
/* @0x1cde70 ldrb r3, [r11, #0x69] */
/* @0x1cde74 cmp r3, #0 */
/* @0x1cde78 bne 0x1cde48 <_Z11HandleAlarmv+0xd8> */
/* @0x1cde7c ldrd r2, r3, [r11, #112] */
/* @0x1cde80 cmp r4, r2 */
/* @0x1cde84 sbcs r1, r5, r3 */
/* @0x1cde88 blt 0x1cde48 <_Z11HandleAlarmv+0xd8> */
/* @0x1cde8c mov r0, r11 */
/* @0x1cde90 mov r1, r6 */
/* @0x1cde94 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0x1cde98 cmp r0, #0 */
/* @0x1cde9c blt 0x1cdebc <_Z11HandleAlarmv+0x14c> */
/* @0x1cdea0 mov r1, r6 */
/* @0x1cdea4 mov r0, r11 */
/* @0x1cdea8 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0x1cdeac mov r1, r6 */
/* @0x1cdeb0 sub r2, r0, #1 */
/* @0x1cdeb4 mov r0, r11 */
/* @0x1cdeb8 bl 0x193148 <_ZN9CInstance8SetTimerEii> */
/* @0x1cdebc mov r0, r11 */
/* @0x1cdec0 mov r1, r6 */
/* @0x1cdec4 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0x1cdec8 cmp r0, #0 */
/* @0x1cdecc bne 0x1cde48 <_Z11HandleAlarmv+0xd8> */
/* @0x1cded0 mov r0, r11 */
/* @0x1cded4 mov r2, #2 */
/* @0x1cded8 mov r1, r11 */
/* @0x1cdedc mov r3, r6 */
/* @0x1cdee0 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1cdee4 cmp r10, #0 */
/* @0x1cdee8 bne 0x1cde50 <_Z11HandleAlarmv+0xe0> */
/* @0x1cdeec ldr r3, [r9, #-0x4] */
/* @0x1cdef0 add r7, r7, #1 */
/* @0x1cdef4 cmp r3, r7 */
/* @0x1cdef8 bgt 0x1cddfc <_Z11HandleAlarmv+0x8c> */
/* @0x1cdefc add r6, r6, #1 */
/* @0x1cdf00 cmp r6, #12 */
/* @0x1cdf04 bne 0x1cddc8 <_Z11HandleAlarmv+0x58> */
/* @0x1cdf08 ldr r12, [sp, #0xc] */
/* @0x1cdf0c ldrb r3, [r12] */
/* @0x1cdf10 cmp r3, #0 */
/* @0x1cdf14 bne 0x1cdf20 <_Z11HandleAlarmv+0x1b0> */
/* @0x1cdf18 add sp, sp, #20 */
/* @0x1cdf1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1cdf20 ldr r3, [pc, #0x40] */
/* @0x1cdf24 ldr r12, [sp, #0x8] */
/* @0x1cdf28 ldr r0, [r12, r3] */
/* @0x1cdf2c add sp, sp, #20 */
/* @0x1cdf30 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1cdf34 b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1cdf38 ldr r3, [pc, #0x28] */
/* @0x1cdf3c mov r1, #6 */
/* @0x1cdf40 mov r2, #8 */
/* @0x1cdf44 ldr r0, [r12, r3] */
/* @0x1cdf48 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1cdf4c b 0x1cdd9c <_Z11HandleAlarmv+0x2c> */
/* @0x1cdf50 .word 0x00223ed4 */
/* @0x1cdf54 .word 0xffffbf18 */
/* @0x1cdf58 .word 0xffffdeb4 */
/* @0x1cdf5c .word 0xffffdeb8 */
/* @0x1cdf60 .word 0xffffdebc */
/* @0x1cdf64 .word 0xffffbfec */
/* @0x1cdf68 .word 0xffffbf1c */

/* ── FUNC 0x1cdf6c · HandleStep(int) · size=456 · insn=114 */
/* @0x1cdf6c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1cdf70 sub sp, sp, #28 */
/* @0x1cdf74 ldr r8, [pc, #0x19c] */
/* @0x1cdf78 mov r11, r0 */
/* @0x1cdf7c ldr r3, [pc, #0x198] */
/* @0x1cdf80 add r8, pc, r8 */
/* @0x1cdf84 str r8, [sp, #0x10] */
/* @0x1cdf88 ldr r3, [r8, r3] */
/* @0x1cdf8c str r3, [sp, #0x14] */
/* @0x1cdf90 ldrb r3, [r3] */
/* @0x1cdf94 cmp r3, #0 */
/* @0x1cdf98 bne 0x1ce100 <_Z10HandleStepi+0x194> */
/* @0x1cdf9c ldr r3, [pc, #0x17c] */
/* @0x1cdfa0 add r0, r11, #768 */
/* @0x1cdfa4 ldr r9, [sp, #0x10] */
/* @0x1cdfa8 ldr r4, [pc, #0x174] */
/* @0x1cdfac ldr r1, [r9, r3] */
/* @0x1cdfb0 ldrd r8, r9, [r1] */
/* @0x1cdfb4 adds r2, r8, #1 */
/* @0x1cdfb8 adc r3, r9, #0 */
/* @0x1cdfbc strd r8, r9, [sp, #8] */
/* @0x1cdfc0 ldr r9, [sp, #0x10] */
/* @0x1cdfc4 strd r2, r3, [r1] */
/* @0x1cdfc8 ldr r3, [r9, r4] */
/* @0x1cdfcc ldr r8, [r3, r0, lsl #2] */
/* @0x1cdfd0 cmp r8, #0 */
/* @0x1cdfd4 ble 0x1ce0d0 <_Z10HandleStepi+0x164> */
/* @0x1cdfd8 ldr r12, [sp, #0x10] */
/* @0x1cdfdc mov r7, #0 */
/* @0x1cdfe0 ldr r2, [pc, #0x140] */
/* @0x1cdfe4 ldr r3, [pc, #0x140] */
/* @0x1cdfe8 ldr r9, [r12, r2] */
/* @0x1cdfec ldr r10, [r12, r3] */
/* @0x1cdff0 add r9, r9, r0, lsl #3 */
/* @0x1cdff4 ldr r3, [r10] */
/* @0x1cdff8 ldr r1, [r9, #0x4] */
/* @0x1cdffc ldr r2, [r3, #0x4] */
/* @0x1ce000 ldr r1, [r1, r7, lsl #2] */
/* @0x1ce004 ldr r3, [r3] */
/* @0x1ce008 and r2, r1, r2 */
/* @0x1ce00c ldr r3, [r3, r2, lsl #3] */
/* @0x1ce010 cmp r3, #0 */
/* @0x1ce014 bne 0x1ce028 <_Z10HandleStepi+0xbc> */
/* @0x1ce018 b 0x1ce0c4 <_Z10HandleStepi+0x158> */
/* @0x1ce01c ldr r3, [r3, #0x4] */
/* @0x1ce020 cmp r3, #0 */
/* @0x1ce024 beq 0x1ce0c4 <_Z10HandleStepi+0x158> */
/* @0x1ce028 ldr r2, [r3, #0x8] */
/* @0x1ce02c cmp r1, r2 */
/* @0x1ce030 bne 0x1ce01c <_Z10HandleStepi+0xb0> */
/* @0x1ce034 ldr r3, [r3, #0xc] */
/* @0x1ce038 cmp r3, #0 */
/* @0x1ce03c beq 0x1ce0c4 <_Z10HandleStepi+0x158> */
/* @0x1ce040 ldr r6, [r3, #0xc4] */
/* @0x1ce044 cmp r6, #0 */
/* @0x1ce048 beq 0x1ce0c4 <_Z10HandleStepi+0x158> */
/* @0x1ce04c ldr r3, [r6, #0x8] */
/* @0x1ce050 cmp r3, #0 */
/* @0x1ce054 beq 0x1ce0c4 <_Z10HandleStepi+0x158> */
/* @0x1ce058 str r8, [sp, #0x4] */
/* @0x1ce05c str r9, [sp] */
/* @0x1ce060 b 0x1ce070 <_Z10HandleStepi+0x104> */
/* @0x1ce064 ldr r3, [r6, #0x8] */
/* @0x1ce068 cmp r3, #0 */
/* @0x1ce06c beq 0x1ce0bc <_Z10HandleStepi+0x150> */
/* @0x1ce070 ldr r0, [r6, #0x8] */
/* @0x1ce074 ldr r6, [r6] */
/* @0x1ce078 ldrb r3, [r0, #0x68] */
/* @0x1ce07c cmp r3, #0 */
/* @0x1ce080 bne 0x1ce0b4 <_Z10HandleStepi+0x148> */
/* @0x1ce084 ldrb r3, [r0, #0x69] */
/* @0x1ce088 cmp r3, #0 */
/* @0x1ce08c bne 0x1ce0b4 <_Z10HandleStepi+0x148> */
/* @0x1ce090 ldrd r4, r5, [r0, #112] */
/* @0x1ce094 mov r1, r0 */
/* @0x1ce098 ldrd r8, r9, [sp, #8] */
/* @0x1ce09c mov r2, #3 */
/* @0x1ce0a0 mov r3, r11 */
/* @0x1ce0a4 cmp r8, r4 */
/* @0x1ce0a8 sbcs r9, r9, r5 */
/* @0x1ce0ac blt 0x1ce0b4 <_Z10HandleStepi+0x148> */
/* @0x1ce0b0 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1ce0b4 cmp r6, #0 */
/* @0x1ce0b8 bne 0x1ce064 <_Z10HandleStepi+0xf8> */
/* @0x1ce0bc ldr r8, [sp, #0x4] */
/* @0x1ce0c0 ldr r9, [sp] */
/* @0x1ce0c4 add r7, r7, #1 */
/* @0x1ce0c8 cmp r7, r8 */
/* @0x1ce0cc bne 0x1cdff4 <_Z10HandleStepi+0x88> */
/* @0x1ce0d0 ldr r12, [sp, #0x14] */
/* @0x1ce0d4 ldrb r3, [r12] */
/* @0x1ce0d8 cmp r3, #0 */
/* @0x1ce0dc bne 0x1ce0e8 <_Z10HandleStepi+0x17c> */
/* @0x1ce0e0 add sp, sp, #28 */
/* @0x1ce0e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ce0e8 ldr r3, [pc, #0x40] */
/* @0x1ce0ec ldr r12, [sp, #0x10] */
/* @0x1ce0f0 ldr r0, [r12, r3] */
/* @0x1ce0f4 add sp, sp, #28 */
/* @0x1ce0f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ce0fc b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1ce100 ldr r3, [pc, #0x28] */
/* @0x1ce104 mov r1, #6 */
/* @0x1ce108 mov r2, #4 */
/* @0x1ce10c ldr r0, [r8, r3] */
/* @0x1ce110 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1ce114 b 0x1cdf9c <_Z10HandleStepi+0x30> */
/* @0x1ce118 .word 0x00223cd0 */
/* @0x1ce11c .word 0xffffbf18 */
/* @0x1ce120 .word 0xffffdeb4 */
/* @0x1ce124 .word 0xffffdeb8 */
/* @0x1ce128 .word 0xffffdebc */
/* @0x1ce12c .word 0xffffbfec */
/* @0x1ce130 .word 0xffffbf1c */
