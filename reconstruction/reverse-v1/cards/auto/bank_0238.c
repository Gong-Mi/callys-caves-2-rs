/* libyoyo.so 覆盖卡组 0238
 * 函数 0x286758..0x2894cc，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x286758 · spIkConstraintData_dispose · size=36 · insn=9 */
/* @0x286758 push {r4, lr} */
/* @0x28675c mov r4, r0 */
/* @0x286760 ldr r0, [r0] */
/* @0x286764 bl 0x285c80 <_free> */
/* @0x286768 ldr r0, [r4, #0x8] */
/* @0x28676c bl 0x285c80 <_free> */
/* @0x286770 mov r0, r4 */
/* @0x286774 pop {r4, lr} */
/* @0x286778 b 0x285c80 <_free> */

/* ── FUNC 0x28677c · anon_28677c · size=2872 · insn=719 */
/* @0x28677c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x286780 mov r4, r2 */
/* @0x286784 ldrb r3, [r2] */
/* @0x286788 sub sp, sp, #20 */
/* @0x28678c mov r8, r0 */
/* @0x286790 mov r9, r1 */
/* @0x286794 cmp r3, #34 */
/* @0x286798 add r5, r2, #1 */
/* @0x28679c bne 0x2869ec <spIkConstraintData_dispose+0x294> */
/* @0x2867a0 mov r1, r5 */
/* @0x2867a4 mov r0, #0 */
/* @0x2867a8 ldrb r3, [r1] */
/* @0x2867ac cmp r3, #0 */
/* @0x2867b0 cmpne r3, #34 */
/* @0x2867b4 beq 0x2867dc <spIkConstraintData_dispose+0x84> */
/* @0x2867b8 cmp r3, #92 */
/* @0x2867bc add r0, r0, #1 */
/* @0x2867c0 addne r1, r1, #1 */
/* @0x2867c4 bne 0x2867a8 <spIkConstraintData_dispose+0x50> */
/* @0x2867c8 add r1, r1, #2 */
/* @0x2867cc ldrb r3, [r1] */
/* @0x2867d0 cmp r3, #0 */
/* @0x2867d4 cmpne r3, #34 */
/* @0x2867d8 bne 0x2867b8 <spIkConstraintData_dispose+0x60> */
/* @0x2867dc ldr r1, [pc, #0x314] */
/* @0x2867e0 add r0, r0, #1 */
/* @0x2867e4 mov r2, #141 */
/* @0x2867e8 add r1, pc, r1 */
/* @0x2867ec bl 0x285c10 <_malloc> */
/* @0x2867f0 subs r7, r0, #0 */
/* @0x2867f4 beq 0x286ac4 <spIkConstraintData_dispose+0x36c> */
/* @0x2867f8 ldr r10, [pc, #0x2fc] */
/* @0x2867fc add r3, sp, #8 */
/* @0x286800 ldr r12, [pc, #0x2f8] */
/* @0x286804 mov r6, r7 */
/* @0x286808 ldrb r4, [r4, #0x1] */
/* @0x28680c add r10, pc, r10 */
/* @0x286810 add r12, pc, r12 */
/* @0x286814 movw r11, #0x3ff */
/* @0x286818 cmp r4, #0 */
/* @0x28681c cmpne r4, #34 */
/* @0x286820 moveq r2, #0 */
/* @0x286824 movne r2, #1 */
/* @0x286828 beq 0x2868b0 <spIkConstraintData_dispose+0x158> */
/* @0x28682c cmp r4, #92 */
/* @0x286830 beq 0x286848 <spIkConstraintData_dispose+0xf0> */
/* @0x286834 strb r4, [r6] */
/* @0x286838 add r5, r5, #1 */
/* @0x28683c ldrb r4, [r5] */
/* @0x286840 add r6, r6, #1 */
/* @0x286844 b 0x286818 <spIkConstraintData_dispose+0xc0> */
/* @0x286848 ldrb r0, [r5, #0x1] */
/* @0x28684c add r2, r5, #1 */
/* @0x286850 sub r1, r0, #98 */
/* @0x286854 cmp r1, #19 */
/* @0x286858 addls pc, pc, r1, lsl #2 */
/* @0x28685c b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286860 b 0x2869c8 <spIkConstraintData_dispose+0x270> */
/* @0x286864 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286868 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x28686c b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286870 b 0x2869b4 <spIkConstraintData_dispose+0x25c> */
/* @0x286874 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286878 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x28687c b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286880 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286884 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286888 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x28688c b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286890 b 0x2869a0 <spIkConstraintData_dispose+0x248> */
/* @0x286894 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x286898 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x28689c b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x2868a0 b 0x28698c <spIkConstraintData_dispose+0x234> */
/* @0x2868a4 b 0x2869dc <spIkConstraintData_dispose+0x284> */
/* @0x2868a8 b 0x286974 <spIkConstraintData_dispose+0x21c> */
/* @0x2868ac b 0x2868d8 <spIkConstraintData_dispose+0x180> */
/* @0x2868b0 strb r2, [r6] */
/* @0x2868b4 ldrb r3, [r5] */
/* @0x2868b8 str r7, [r9] */
/* @0x2868bc cmp r3, #34 */
/* @0x2868c0 mov r3, #4 */
/* @0x2868c4 addeq r5, r5, #1 */
/* @0x2868c8 str r3, [r8] */
/* @0x2868cc mov r0, r5 */
/* @0x2868d0 add sp, sp, #20 */
/* @0x2868d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2868d8 mov r2, r3 */
/* @0x2868dc mov r1, r10 */
/* @0x2868e0 add r0, r5, #2 */
/* @0x2868e4 str r3, [sp, #0x4] */
/* @0x2868e8 str r12, [sp] */
/* @0x2868ec bl 0xb68f8 <sscanf@plt> */
/* @0x2868f0 ldr r1, [sp, #0x8] */
/* @0x2868f4 add r2, r5, #5 */
/* @0x2868f8 ldr r3, [sp, #0x4] */
/* @0x2868fc sub r0, r1, #56320 */
/* @0x286900 ldr r12, [sp] */
/* @0x286904 cmp r1, #0 */
/* @0x286908 cmpne r0, r11 */
/* @0x28690c bls 0x286a04 <spIkConstraintData_dispose+0x2ac> */
/* @0x286910 sub r0, r1, #55296 */
/* @0x286914 cmp r0, #1024 */
/* @0x286918 bhs 0x286a0c <spIkConstraintData_dispose+0x2b4> */
/* @0x28691c ldrb r1, [r5, #0x6] */
/* @0x286920 cmp r1, #92 */
/* @0x286924 movne r4, r1 */
/* @0x286928 bne 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x28692c ldrb r1, [r5, #0x7] */
/* @0x286930 cmp r1, #117 */
/* @0x286934 bne 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x286938 mov r1, r10 */
/* @0x28693c add r2, sp, #12 */
/* @0x286940 add r0, r5, #8 */
/* @0x286944 str r3, [sp, #0x4] */
/* @0x286948 str r12, [sp] */
/* @0x28694c bl 0xb68f8 <sscanf@plt> */
/* @0x286950 ldr r1, [sp, #0xc] */
/* @0x286954 add r2, r5, #11 */
/* @0x286958 ldr r3, [sp, #0x4] */
/* @0x28695c sub r0, r1, #56320 */
/* @0x286960 ldr r12, [sp] */
/* @0x286964 cmp r0, #1024 */
/* @0x286968 blo 0x286a24 <spIkConstraintData_dispose+0x2cc> */
/* @0x28696c ldrb r4, [r5, #0xc] */
/* @0x286970 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x286974 mov r1, #9 */
/* @0x286978 strb r1, [r6] */
/* @0x28697c ldrb r4, [r5, #0x2] */
/* @0x286980 add r6, r6, #1 */
/* @0x286984 add r5, r2, #1 */
/* @0x286988 b 0x286818 <spIkConstraintData_dispose+0xc0> */
/* @0x28698c mov r1, #13 */
/* @0x286990 add r6, r6, #1 */
/* @0x286994 strb r1, [r6, #-0x1] */
/* @0x286998 ldrb r4, [r5, #0x2] */
/* @0x28699c b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x2869a0 mov r1, #10 */
/* @0x2869a4 add r6, r6, #1 */
/* @0x2869a8 strb r1, [r6, #-0x1] */
/* @0x2869ac ldrb r4, [r5, #0x2] */
/* @0x2869b0 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x2869b4 mov r1, #12 */
/* @0x2869b8 add r6, r6, #1 */
/* @0x2869bc strb r1, [r6, #-0x1] */
/* @0x2869c0 ldrb r4, [r5, #0x2] */
/* @0x2869c4 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x2869c8 mov r1, #8 */
/* @0x2869cc add r6, r6, #1 */
/* @0x2869d0 strb r1, [r6, #-0x1] */
/* @0x2869d4 ldrb r4, [r5, #0x2] */
/* @0x2869d8 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x2869dc strb r0, [r6] */
/* @0x2869e0 add r6, r6, #1 */
/* @0x2869e4 ldrb r4, [r5, #0x2] */
/* @0x2869e8 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x2869ec ldr r3, [pc, #0x110] */
/* @0x2869f0 mov r0, #0 */
/* @0x2869f4 add r3, pc, r3 */
/* @0x2869f8 str r2, [r3] */
/* @0x2869fc add sp, sp, #20 */
/* @0x286a00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x286a04 ldrb r4, [r5, #0x6] */
/* @0x286a08 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x286a0c cmp r1, #127 */
/* @0x286a10 bhi 0x286a3c <spIkConstraintData_dispose+0x2e4> */
/* @0x286a14 mov r0, #1 */
/* @0x286a18 add r4, r6, r0 */
/* @0x286a1c mov r5, r0 */
/* @0x286a20 b 0x286a98 <spIkConstraintData_dispose+0x340> */
/* @0x286a24 ldr r0, [sp, #0x8] */
/* @0x286a28 ubfx r1, r1, #0x0, #0xa */
/* @0x286a2c ubfx r0, r0, #0x0, #0xa */
/* @0x286a30 orr r1, r1, r0, lsl #10 */
/* @0x286a34 add r1, r1, #65536 */
/* @0x286a38 str r1, [sp, #0x8] */
/* @0x286a3c cmp r1, #2048 */
/* @0x286a40 blo 0x286ab4 <spIkConstraintData_dispose+0x35c> */
/* @0x286a44 cmp r1, #65536 */
/* @0x286a48 bhs 0x286acc <spIkConstraintData_dispose+0x374> */
/* @0x286a4c mov r0, #3 */
/* @0x286a50 add r4, r6, r0 */
/* @0x286a54 mov r5, r0 */
/* @0x286a58 and r1, r1, #63 */
/* @0x286a5c sub r6, r4, #1 */
/* @0x286a60 mvn r1, r1, lsl #25 */
/* @0x286a64 mvn r1, r1, lsr #25 */
/* @0x286a68 strb r1, [r4, #-0x1] */
/* @0x286a6c ldr r1, [sp, #0x8] */
/* @0x286a70 lsr r1, r1, #6 */
/* @0x286a74 str r1, [sp, #0x8] */
/* @0x286a78 and r1, r1, #63 */
/* @0x286a7c sub r4, r6, #1 */
/* @0x286a80 mvn r1, r1, lsl #25 */
/* @0x286a84 mvn r1, r1, lsr #25 */
/* @0x286a88 strb r1, [r6, #-0x1] */
/* @0x286a8c ldr r1, [sp, #0x8] */
/* @0x286a90 lsr r1, r1, #6 */
/* @0x286a94 str r1, [sp, #0x8] */
/* @0x286a98 ldrb r5, [r12, r5] */
/* @0x286a9c sub r6, r4, #1 */
/* @0x286aa0 add r6, r6, r0 */
/* @0x286aa4 orr r1, r1, r5 */
/* @0x286aa8 strb r1, [r4, #-0x1] */
/* @0x286aac ldrb r4, [r2, #0x1] */
/* @0x286ab0 b 0x286984 <spIkConstraintData_dispose+0x22c> */
/* @0x286ab4 mov r0, #2 */
/* @0x286ab8 add r6, r6, r0 */
/* @0x286abc mov r5, r0 */
/* @0x286ac0 b 0x286a78 <spIkConstraintData_dispose+0x320> */
/* @0x286ac4 mov r0, r7 */
/* @0x286ac8 b 0x2868d0 <spIkConstraintData_dispose+0x178> */
/* @0x286acc and r1, r1, #63 */
/* @0x286ad0 mov r0, #4 */
/* @0x286ad4 add r4, r6, #3 */
/* @0x286ad8 mov r5, r0 */
/* @0x286adc mvn r1, r1, lsl #25 */
/* @0x286ae0 mvn r1, r1, lsr #25 */
/* @0x286ae4 strb r1, [r6, #0x3] */
/* @0x286ae8 ldr r1, [sp, #0x8] */
/* @0x286aec lsr r1, r1, #6 */
/* @0x286af0 str r1, [sp, #0x8] */
/* @0x286af4 b 0x286a58 <spIkConstraintData_dispose+0x300> */
/* @0x286af8 ldrdeq r1, r2, [sp], -r0 */
/* @0x286afc andeq r1, sp, r0, ror #1 */
/* @0x286b00 andseq r5, r0, r12, lsr #15 */
/* @0x286b04 subeq r0, sp, r12, asr #3 */
/* @0x286b08 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x286b0c mov r6, r1 */
/* @0x286b10 ldrb r3, [r1] */
/* @0x286b14 sub sp, sp, #12 */
/* @0x286b18 mov r5, r0 */
/* @0x286b1c sub r3, r3, #34 */
/* @0x286b20 cmp r3, #89 */
/* @0x286b24 addls pc, pc, r3, lsl #2 */
/* @0x286b28 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b2c b 0x286f58 <spIkConstraintData_dispose+0x800> */
/* @0x286b30 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b34 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b38 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b3c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b40 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b44 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b48 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b4c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b50 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b54 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b58 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b5c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b60 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b64 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b68 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b6c b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b70 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b74 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b78 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b7c b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b80 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b84 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b88 b 0x286f70 <spIkConstraintData_dispose+0x818> */
/* @0x286b8c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b90 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b94 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b98 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286b9c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286ba0 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286ba4 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286ba8 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bac b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bb0 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bb4 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bb8 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bbc b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bc0 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bc4 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bc8 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bcc b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bd0 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bd4 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bd8 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bdc b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286be0 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286be4 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286be8 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bec b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bf0 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bf4 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bf8 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286bfc b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c00 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c04 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c08 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c0c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c10 b 0x286fb0 <spIkConstraintData_dispose+0x858> */
/* @0x286c14 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c18 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c1c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c20 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c24 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c28 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c2c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c30 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c34 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c38 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c3c b 0x287154 <spIkConstraintData_dispose+0x9fc> */
/* @0x286c40 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c44 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c48 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c4c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c50 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c54 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c58 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c5c b 0x287180 <spIkConstraintData_dispose+0xa28> */
/* @0x286c60 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c64 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c68 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c6c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c70 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c74 b 0x2871b0 <spIkConstraintData_dispose+0xa58> */
/* @0x286c78 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c7c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c80 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c84 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c88 b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c8c b 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x286c90 b 0x286c94 <spIkConstraintData_dispose+0x53c> */
/* @0x286c94 adds r4, r1, #1 */
/* @0x286c98 mov r3, #6 */
/* @0x286c9c str r3, [r0, #0x8] */
/* @0x286ca0 ldrb r3, [r1, #0x1] */
/* @0x286ca4 beq 0x286cd0 <spIkConstraintData_dispose+0x578> */
/* @0x286ca8 sub r2, r3, #1 */
/* @0x286cac cmp r2, #31 */
/* @0x286cb0 bhi 0x286cd0 <spIkConstraintData_dispose+0x578> */
/* @0x286cb4 add r6, r1, #2 */
/* @0x286cb8 mov r4, r6 */
/* @0x286cbc add r6, r6, #1 */
/* @0x286cc0 ldrb r3, [r4] */
/* @0x286cc4 sub r2, r3, #1 */
/* @0x286cc8 cmp r2, #31 */
/* @0x286ccc bls 0x286cb8 <spIkConstraintData_dispose+0x560> */
/* @0x286cd0 cmp r3, #125 */
/* @0x286cd4 beq 0x287208 <spIkConstraintData_dispose+0xab0> */
/* @0x286cd8 ldr r2, [pc, #0x5a4] */
/* @0x286cdc mov r0, #1 */
/* @0x286ce0 mov r1, #32 */
/* @0x286ce4 mov r3, #77 */
/* @0x286ce8 add r2, pc, r2 */
/* @0x286cec bl 0x285c4c <_calloc> */
/* @0x286cf0 cmp r0, #0 */
/* @0x286cf4 mov r9, r0 */
/* @0x286cf8 str r0, [r5, #0x4] */
/* @0x286cfc beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x286d00 ldrb r3, [r4] */
/* @0x286d04 sub r3, r3, #1 */
/* @0x286d08 cmp r3, #31 */
/* @0x286d0c bhi 0x286d2c <spIkConstraintData_dispose+0x5d4> */
/* @0x286d10 add r3, r4, #1 */
/* @0x286d14 mov r4, r3 */
/* @0x286d18 add r3, r3, #1 */
/* @0x286d1c ldrb r2, [r4] */
/* @0x286d20 sub r2, r2, #1 */
/* @0x286d24 cmp r2, #31 */
/* @0x286d28 bls 0x286d14 <spIkConstraintData_dispose+0x5bc> */
/* @0x286d2c mov r2, r4 */
/* @0x286d30 add r0, r9, #8 */
/* @0x286d34 add r1, r9, #16 */
/* @0x286d38 bl 0x28677c <spIkConstraintData_dispose+0x24> */
/* @0x286d3c subs r2, r0, #0 */
/* @0x286d40 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x286d44 ldrb r3, [r2] */
/* @0x286d48 sub r3, r3, #1 */
/* @0x286d4c cmp r3, #31 */
/* @0x286d50 bhi 0x286d70 <spIkConstraintData_dispose+0x618> */
/* @0x286d54 add r3, r2, #1 */
/* @0x286d58 mov r2, r3 */
/* @0x286d5c add r3, r3, #1 */
/* @0x286d60 ldrb r1, [r2] */
/* @0x286d64 sub r1, r1, #1 */
/* @0x286d68 cmp r1, #31 */
/* @0x286d6c bls 0x286d58 <spIkConstraintData_dispose+0x600> */
/* @0x286d70 ldr r3, [r9, #0x10] */
/* @0x286d74 mov r0, #0 */
/* @0x286d78 str r0, [r9, #0x10] */
/* @0x286d7c str r3, [r9, #0x1c] */
/* @0x286d80 ldrb r3, [r2] */
/* @0x286d84 cmp r3, #58 */
/* @0x286d88 bne 0x287230 <spIkConstraintData_dispose+0xad8> */
/* @0x286d8c adds r1, r2, #1 */
/* @0x286d90 beq 0x286dc0 <spIkConstraintData_dispose+0x668> */
/* @0x286d94 ldrb r3, [r2, #0x1] */
/* @0x286d98 sub r3, r3, #1 */
/* @0x286d9c cmp r3, #31 */
/* @0x286da0 bhi 0x286dc0 <spIkConstraintData_dispose+0x668> */
/* @0x286da4 add r2, r2, #2 */
/* @0x286da8 mov r1, r2 */
/* @0x286dac add r2, r2, #1 */
/* @0x286db0 ldrb r3, [r1] */
/* @0x286db4 sub r3, r3, #1 */
/* @0x286db8 cmp r3, #31 */
/* @0x286dbc bls 0x286da8 <spIkConstraintData_dispose+0x650> */
/* @0x286dc0 mov r0, r9 */
/* @0x286dc4 bl 0x286b08 <spIkConstraintData_dispose+0x3b0> */
/* @0x286dc8 subs r4, r0, #0 */
/* @0x286dcc beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x286dd0 ldrb r3, [r4] */
/* @0x286dd4 sub r3, r3, #1 */
/* @0x286dd8 cmp r3, #31 */
/* @0x286ddc bhi 0x286dfc <spIkConstraintData_dispose+0x6a4> */
/* @0x286de0 add r3, r4, #1 */
/* @0x286de4 mov r4, r3 */
/* @0x286de8 add r3, r3, #1 */
/* @0x286dec ldrb r2, [r4] */
/* @0x286df0 sub r2, r2, #1 */
/* @0x286df4 cmp r2, #31 */
/* @0x286df8 bls 0x286de4 <spIkConstraintData_dispose+0x68c> */
/* @0x286dfc mov r3, #1 */
/* @0x286e00 str r3, [r5, #0xc] */
/* @0x286e04 ldrb r3, [r4] */
/* @0x286e08 mov r7, #0 */
/* @0x286e0c ldr r6, [pc, #0x474] */
/* @0x286e10 cmp r3, #44 */
/* @0x286e14 add r6, pc, r6 */
/* @0x286e18 bne 0x287240 <spIkConstraintData_dispose+0xae8> */
/* @0x286e1c mov r0, #1 */
/* @0x286e20 mov r1, #32 */
/* @0x286e24 mov r2, r6 */
/* @0x286e28 mov r3, #77 */
/* @0x286e2c bl 0x285c4c <_calloc> */
/* @0x286e30 subs r8, r0, #0 */
/* @0x286e34 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x286e38 adds r2, r4, #1 */
/* @0x286e3c str r8, [r9] */
/* @0x286e40 beq 0x286e70 <spIkConstraintData_dispose+0x718> */
/* @0x286e44 ldrb r3, [r4, #0x1] */
/* @0x286e48 sub r3, r3, #1 */
/* @0x286e4c cmp r3, #31 */
/* @0x286e50 bhi 0x286e70 <spIkConstraintData_dispose+0x718> */
/* @0x286e54 add r4, r4, #2 */
/* @0x286e58 mov r2, r4 */
/* @0x286e5c add r4, r4, #1 */
/* @0x286e60 ldrb r3, [r2] */
/* @0x286e64 sub r3, r3, #1 */
/* @0x286e68 cmp r3, #31 */
/* @0x286e6c bls 0x286e58 <spIkConstraintData_dispose+0x700> */
/* @0x286e70 add r0, r8, #8 */
/* @0x286e74 add r1, r8, #16 */
/* @0x286e78 bl 0x28677c <spIkConstraintData_dispose+0x24> */
/* @0x286e7c subs r12, r0, #0 */
/* @0x286e80 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x286e84 ldrb r3, [r12] */
/* @0x286e88 sub r3, r3, #1 */
/* @0x286e8c cmp r3, #31 */
/* @0x286e90 bhi 0x286eb0 <spIkConstraintData_dispose+0x758> */
/* @0x286e94 add r3, r12, #1 */
/* @0x286e98 mov r12, r3 */
/* @0x286e9c add r3, r3, #1 */
/* @0x286ea0 ldrb r2, [r12] */
/* @0x286ea4 sub r2, r2, #1 */
/* @0x286ea8 cmp r2, #31 */
/* @0x286eac bls 0x286e98 <spIkConstraintData_dispose+0x740> */
/* @0x286eb0 ldr r3, [r8, #0x10] */
/* @0x286eb4 str r7, [r8, #0x10] */
/* @0x286eb8 str r3, [r8, #0x1c] */
/* @0x286ebc ldrb r3, [r12] */
/* @0x286ec0 cmp r3, #58 */
/* @0x286ec4 bne 0x28725c <spIkConstraintData_dispose+0xb04> */
/* @0x286ec8 adds r1, r12, #1 */
/* @0x286ecc beq 0x286efc <spIkConstraintData_dispose+0x7a4> */
/* @0x286ed0 ldrb r3, [r12, #0x1] */
/* @0x286ed4 sub r3, r3, #1 */
/* @0x286ed8 cmp r3, #31 */
/* @0x286edc bhi 0x286efc <spIkConstraintData_dispose+0x7a4> */
/* @0x286ee0 add r12, r12, #2 */
/* @0x286ee4 mov r1, r12 */
/* @0x286ee8 add r12, r12, #1 */
/* @0x286eec ldrb r3, [r1] */
/* @0x286ef0 sub r3, r3, #1 */
/* @0x286ef4 cmp r3, #31 */
/* @0x286ef8 bls 0x286ee4 <spIkConstraintData_dispose+0x78c> */
/* @0x286efc mov r0, r8 */
/* @0x286f00 bl 0x286b08 <spIkConstraintData_dispose+0x3b0> */
/* @0x286f04 subs r4, r0, #0 */
/* @0x286f08 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x286f0c ldrb r3, [r4] */
/* @0x286f10 sub r3, r3, #1 */
/* @0x286f14 cmp r3, #31 */
/* @0x286f18 bhi 0x286f38 <spIkConstraintData_dispose+0x7e0> */
/* @0x286f1c add r3, r4, #1 */
/* @0x286f20 mov r4, r3 */
/* @0x286f24 add r3, r3, #1 */
/* @0x286f28 ldrb r2, [r4] */
/* @0x286f2c sub r2, r2, #1 */
/* @0x286f30 cmp r2, #31 */
/* @0x286f34 bls 0x286f20 <spIkConstraintData_dispose+0x7c8> */
/* @0x286f38 ldr r3, [r5, #0xc] */
/* @0x286f3c add r3, r3, #1 */
/* @0x286f40 str r3, [r5, #0xc] */
/* @0x286f44 ldrb r3, [r4] */
/* @0x286f48 cmp r3, #44 */
/* @0x286f4c bne 0x287240 <spIkConstraintData_dispose+0xae8> */
/* @0x286f50 mov r9, r8 */
/* @0x286f54 b 0x286e1c <spIkConstraintData_dispose+0x6c4> */
/* @0x286f58 mov r2, r1 */
/* @0x286f5c add r0, r0, #8 */
/* @0x286f60 add r1, r5, #16 */
/* @0x286f64 bl 0x28677c <spIkConstraintData_dispose+0x24> */
/* @0x286f68 add sp, sp, #12 */
/* @0x286f6c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x286f70 mov r0, r1 */
/* @0x286f74 add r1, sp, #4 */
/* @0x286f78 bl 0xb6658 <strtod@plt> */
/* @0x286f7c ldr r4, [sp, #0x4] */
/* @0x286f80 cmp r6, r4 */
/* @0x286f84 vmov d6, r0, r1 */
/* @0x286f88 vcvt.f32.f64 s15, d6 */
/* @0x286f8c beq 0x287270 <spIkConstraintData_dispose+0xb18> */
/* @0x286f90 vstr s15, [r5, #24] */
/* @0x286f94 mov r0, r4 */
/* @0x286f98 mov r3, #3 */
/* @0x286f9c str r3, [r5, #0x8] */
/* @0x286fa0 vcvt.s32.f32 s15, s15 */
/* @0x286fa4 vstr s15, [r5, #20] */
/* @0x286fa8 add sp, sp, #12 */
/* @0x286fac pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x286fb0 adds r4, r1, #1 */
/* @0x286fb4 mov r3, #5 */
/* @0x286fb8 str r3, [r0, #0x8] */
/* @0x286fbc ldrb r3, [r1, #0x1] */
/* @0x286fc0 beq 0x286fec <spIkConstraintData_dispose+0x894> */
/* @0x286fc4 sub r2, r3, #1 */
/* @0x286fc8 cmp r2, #31 */
/* @0x286fcc bhi 0x286fec <spIkConstraintData_dispose+0x894> */
/* @0x286fd0 add r6, r1, #2 */
/* @0x286fd4 mov r4, r6 */
/* @0x286fd8 add r6, r6, #1 */
/* @0x286fdc ldrb r3, [r4] */
/* @0x286fe0 sub r2, r3, #1 */
/* @0x286fe4 cmp r2, #31 */
/* @0x286fe8 bls 0x286fd4 <spIkConstraintData_dispose+0x87c> */
/* @0x286fec cmp r3, #93 */
/* @0x286ff0 beq 0x287208 <spIkConstraintData_dispose+0xab0> */
/* @0x286ff4 ldr r2, [pc, #0x290] */
/* @0x286ff8 mov r0, #1 */
/* @0x286ffc mov r1, #32 */
/* @0x287000 mov r3, #77 */
/* @0x287004 add r2, pc, r2 */
/* @0x287008 bl 0x285c4c <_calloc> */
/* @0x28700c cmp r0, #0 */
/* @0x287010 mov r8, r0 */
/* @0x287014 str r0, [r5, #0x4] */
/* @0x287018 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x28701c ldrb r3, [r4] */
/* @0x287020 sub r3, r3, #1 */
/* @0x287024 cmp r3, #31 */
/* @0x287028 bhi 0x287048 <spIkConstraintData_dispose+0x8f0> */
/* @0x28702c add r3, r4, #1 */
/* @0x287030 mov r4, r3 */
/* @0x287034 add r3, r3, #1 */
/* @0x287038 ldrb r2, [r4] */
/* @0x28703c sub r2, r2, #1 */
/* @0x287040 cmp r2, #31 */
/* @0x287044 bls 0x287030 <spIkConstraintData_dispose+0x8d8> */
/* @0x287048 mov r1, r4 */
/* @0x28704c mov r0, r8 */
/* @0x287050 bl 0x286b08 <spIkConstraintData_dispose+0x3b0> */
/* @0x287054 subs r4, r0, #0 */
/* @0x287058 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x28705c ldrb r3, [r4] */
/* @0x287060 sub r3, r3, #1 */
/* @0x287064 cmp r3, #31 */
/* @0x287068 bhi 0x287088 <spIkConstraintData_dispose+0x930> */
/* @0x28706c add r3, r4, #1 */
/* @0x287070 mov r4, r3 */
/* @0x287074 add r3, r3, #1 */
/* @0x287078 ldrb r2, [r4] */
/* @0x28707c sub r2, r2, #1 */
/* @0x287080 cmp r2, #31 */
/* @0x287084 bls 0x287070 <spIkConstraintData_dispose+0x918> */
/* @0x287088 mov r3, #1 */
/* @0x28708c str r3, [r5, #0xc] */
/* @0x287090 ldrb r3, [r4] */
/* @0x287094 ldr r6, [pc, #0x1f4] */
/* @0x287098 cmp r3, #44 */
/* @0x28709c add r6, pc, r6 */
/* @0x2870a0 bne 0x287214 <spIkConstraintData_dispose+0xabc> */
/* @0x2870a4 mov r0, #1 */
/* @0x2870a8 mov r1, #32 */
/* @0x2870ac mov r2, r6 */
/* @0x2870b0 mov r3, #77 */
/* @0x2870b4 bl 0x285c4c <_calloc> */
/* @0x2870b8 subs r7, r0, #0 */
/* @0x2870bc beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x2870c0 adds r1, r4, #1 */
/* @0x2870c4 str r7, [r8] */
/* @0x2870c8 beq 0x2870f8 <spIkConstraintData_dispose+0x9a0> */
/* @0x2870cc ldrb r3, [r4, #0x1] */
/* @0x2870d0 sub r3, r3, #1 */
/* @0x2870d4 cmp r3, #31 */
/* @0x2870d8 bhi 0x2870f8 <spIkConstraintData_dispose+0x9a0> */
/* @0x2870dc add r4, r4, #2 */
/* @0x2870e0 mov r1, r4 */
/* @0x2870e4 add r4, r4, #1 */
/* @0x2870e8 ldrb r3, [r1] */
/* @0x2870ec sub r3, r3, #1 */
/* @0x2870f0 cmp r3, #31 */
/* @0x2870f4 bls 0x2870e0 <spIkConstraintData_dispose+0x988> */
/* @0x2870f8 mov r0, r7 */
/* @0x2870fc bl 0x286b08 <spIkConstraintData_dispose+0x3b0> */
/* @0x287100 subs r4, r0, #0 */
/* @0x287104 beq 0x2871fc <spIkConstraintData_dispose+0xaa4> */
/* @0x287108 ldrb r3, [r4] */
/* @0x28710c sub r3, r3, #1 */
/* @0x287110 cmp r3, #31 */
/* @0x287114 bhi 0x287134 <spIkConstraintData_dispose+0x9dc> */
/* @0x287118 add r3, r4, #1 */
/* @0x28711c mov r4, r3 */
/* @0x287120 add r3, r3, #1 */
/* @0x287124 ldrb r1, [r4] */
/* @0x287128 sub r1, r1, #1 */
/* @0x28712c cmp r1, #31 */
/* @0x287130 bls 0x28711c <spIkConstraintData_dispose+0x9c4> */
/* @0x287134 ldr r3, [r5, #0xc] */
/* @0x287138 add r3, r3, #1 */
/* @0x28713c str r3, [r5, #0xc] */
/* @0x287140 ldrb r3, [r4] */
/* @0x287144 cmp r3, #44 */
/* @0x287148 bne 0x287214 <spIkConstraintData_dispose+0xabc> */
/* @0x28714c mov r8, r7 */
/* @0x287150 b 0x2870a4 <spIkConstraintData_dispose+0x94c> */
/* @0x287154 add r0, r1, #1 */
/* @0x287158 ldr r1, [pc, #0x134] */
/* @0x28715c mov r2, #4 */
/* @0x287160 add r1, pc, r1 */
/* @0x287164 bl 0xb65e0 <strncmp@plt> */
/* @0x287168 cmp r0, #0 */
/* @0x28716c bne 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x287170 str r0, [r5, #0x8] */
/* @0x287174 add r0, r6, #5 */
/* @0x287178 add sp, sp, #12 */
/* @0x28717c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x287180 add r0, r1, #1 */
/* @0x287184 ldr r1, [pc, #0x10c] */
/* @0x287188 mov r2, #3 */
/* @0x28718c add r1, pc, r1 */
/* @0x287190 bl 0xb65e0 <strncmp@plt> */
/* @0x287194 cmp r0, #0 */
/* @0x287198 bne 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x28719c add r0, r6, #4 */
/* @0x2871a0 mov r3, #2 */
/* @0x2871a4 str r3, [r5, #0x8] */
/* @0x2871a8 add sp, sp, #12 */
/* @0x2871ac pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2871b0 add r0, r1, #1 */
/* @0x2871b4 ldr r1, [pc, #0xe0] */
/* @0x2871b8 mov r2, #3 */
/* @0x2871bc add r1, pc, r1 */
/* @0x2871c0 bl 0xb65e0 <strncmp@plt> */
/* @0x2871c4 cmp r0, #0 */
/* @0x2871c8 bne 0x2871e4 <spIkConstraintData_dispose+0xa8c> */
/* @0x2871cc mov r3, #1 */
/* @0x2871d0 add r0, r6, #4 */
/* @0x2871d4 str r3, [r5, #0x8] */
/* @0x2871d8 str r3, [r5, #0x14] */
/* @0x2871dc add sp, sp, #12 */
/* @0x2871e0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2871e4 ldr r3, [pc, #0xb4] */
/* @0x2871e8 mov r0, #0 */
/* @0x2871ec add r3, pc, r3 */
/* @0x2871f0 str r6, [r3] */
/* @0x2871f4 add sp, sp, #12 */
/* @0x2871f8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2871fc mov r0, #0 */
/* @0x287200 add sp, sp, #12 */
/* @0x287204 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x287208 add r0, r4, #1 */
/* @0x28720c add sp, sp, #12 */
/* @0x287210 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x287214 cmp r3, #93 */
/* @0x287218 beq 0x287208 <spIkConstraintData_dispose+0xab0> */
/* @0x28721c ldr r3, [pc, #0x80] */
/* @0x287220 mov r0, #0 */
/* @0x287224 add r3, pc, r3 */
/* @0x287228 str r4, [r3] */
/* @0x28722c b 0x286f68 <spIkConstraintData_dispose+0x810> */
/* @0x287230 ldr r3, [pc, #0x70] */
/* @0x287234 add r3, pc, r3 */
/* @0x287238 str r2, [r3] */
/* @0x28723c b 0x286f68 <spIkConstraintData_dispose+0x810> */
/* @0x287240 cmp r3, #125 */
/* @0x287244 beq 0x287208 <spIkConstraintData_dispose+0xab0> */
/* @0x287248 ldr r3, [pc, #0x5c] */
/* @0x28724c mov r0, #0 */
/* @0x287250 add r3, pc, r3 */
/* @0x287254 str r4, [r3] */
/* @0x287258 b 0x286f68 <spIkConstraintData_dispose+0x810> */
/* @0x28725c ldr r3, [pc, #0x4c] */
/* @0x287260 mov r0, #0 */
/* @0x287264 add r3, pc, r3 */
/* @0x287268 str r12, [r3] */
/* @0x28726c b 0x286f68 <spIkConstraintData_dispose+0x810> */
/* @0x287270 ldr r3, [pc, #0x3c] */
/* @0x287274 mov r0, #0 */
/* @0x287278 add r3, pc, r3 */
/* @0x28727c str r6, [r3] */
/* @0x287280 b 0x286f68 <spIkConstraintData_dispose+0x810> */
/* @0x287284 ldrdeq r0, r1, [sp], -r0 */
/* @0x287288 andeq r0, sp, r4, lsr #21 */
/* @0x28728c strheq r0, [sp], -r4 */
/* @0x287290 andeq r0, sp, r12, lsl r8 */
/* @0x287294 muleq sp, r4, r7 */
/* @0x287298 andeq r0, sp, r4, ror #14 */
/* @0x28729c andeq r0, sp, r0, asr #14 */
/* @0x2872a0 .word 0x004cf9d4 */
/* @0x2872a4 umaaleq pc, r12, r12, r9 */
/* @0x2872a8 subeq pc, r12, r12, lsl #19 */
/* @0x2872ac subeq pc, r12, r0, ror r9 */
/* @0x2872b0 subeq pc, r12, r12, asr r9 */
/* @0x2872b4 subeq pc, r12, r8, asr #18 */

/* ── FUNC 0x2872b8 · Json_getError · size=16 · insn=4 */
/* @0x2872b8 ldr r3, [pc, #0x4] */
/* @0x2872bc ldr r0, [pc, r3] */
/* @0x2872c0 bx lr */
/* @0x2872c4 subeq pc, r12, r4, lsl #18 */

/* ── FUNC 0x2872c8 · Json_dispose · size=88 · insn=22 */
/* @0x2872c8 push {r3, r4, r5, lr} */
/* @0x2872cc subs r4, r0, #0 */
/* @0x2872d0 popeq {r3, r4, r5, pc} */
/* @0x2872d4 ldr r0, [r4, #0x4] */
/* @0x2872d8 ldr r5, [r4] */
/* @0x2872dc cmp r0, #0 */
/* @0x2872e0 beq 0x2872e8 <Json_dispose+0x20> */
/* @0x2872e4 bl 0x2872c8 <Json_dispose> */
/* @0x2872e8 ldr r0, [r4, #0x10] */
/* @0x2872ec cmp r0, #0 */
/* @0x2872f0 beq 0x2872f8 <Json_dispose+0x30> */
/* @0x2872f4 bl 0x285c80 <_free> */
/* @0x2872f8 ldr r0, [r4, #0x1c] */
/* @0x2872fc cmp r0, #0 */
/* @0x287300 beq 0x287308 <Json_dispose+0x40> */
/* @0x287304 bl 0x285c80 <_free> */
/* @0x287308 mov r0, r4 */
/* @0x28730c mov r4, r5 */
/* @0x287310 bl 0x285c80 <_free> */
/* @0x287314 cmp r5, #0 */
/* @0x287318 bne 0x2872d4 <Json_dispose+0xc> */
/* @0x28731c pop {r3, r4, r5, pc} */

/* ── FUNC 0x287320 · Json_create · size=164 · insn=41 */
/* @0x287320 push {r3, r4, r5, lr} */
/* @0x287324 subs r4, r0, #0 */
/* @0x287328 ldr r3, [pc, #0x8c] */
/* @0x28732c mov r2, #0 */
/* @0x287330 add r3, pc, r3 */
/* @0x287334 str r2, [r3] */
/* @0x287338 beq 0x2873a4 <Json_create+0x84> */
/* @0x28733c ldr r2, [pc, #0x7c] */
/* @0x287340 mov r0, #1 */
/* @0x287344 mov r1, #32 */
/* @0x287348 mov r3, #77 */
/* @0x28734c add r2, pc, r2 */
/* @0x287350 bl 0x285c4c <_calloc> */
/* @0x287354 subs r5, r0, #0 */
/* @0x287358 beq 0x2873a4 <Json_create+0x84> */
/* @0x28735c ldrb r3, [r4] */
/* @0x287360 sub r3, r3, #1 */
/* @0x287364 cmp r3, #31 */
/* @0x287368 bhi 0x287388 <Json_create+0x68> */
/* @0x28736c add r3, r4, #1 */
/* @0x287370 mov r4, r3 */
/* @0x287374 add r3, r3, #1 */
/* @0x287378 ldrb r2, [r4] */
/* @0x28737c sub r2, r2, #1 */
/* @0x287380 cmp r2, #31 */
/* @0x287384 bls 0x287370 <Json_create+0x50> */
/* @0x287388 mov r1, r4 */
/* @0x28738c mov r0, r5 */
/* @0x287390 bl 0x286b08 <spIkConstraintData_dispose+0x3b0> */
/* @0x287394 subs r3, r0, #0 */
/* @0x287398 beq 0x2873ac <Json_create+0x8c> */
/* @0x28739c mov r0, r5 */
/* @0x2873a0 pop {r3, r4, r5, pc} */
/* @0x2873a4 mov r5, #0 */
/* @0x2873a8 b 0x28739c <Json_create+0x7c> */
/* @0x2873ac mov r0, r5 */
/* @0x2873b0 mov r5, r3 */
/* @0x2873b4 bl 0x2872c8 <Json_dispose> */
/* @0x2873b8 b 0x28739c <Json_create+0x7c> */
/* @0x2873bc umaaleq pc, r12, r0, r8 */
/* @0x2873c0 andeq r0, sp, r12, ror #10 */

/* ── FUNC 0x2873c4 · Json_getItem · size=100 · insn=25 */
/* @0x2873c4 push {r4, r5, r6, lr} */
/* @0x2873c8 mov r5, r1 */
/* @0x2873cc ldr r4, [r0, #0x4] */
/* @0x2873d0 cmp r4, #0 */
/* @0x2873d4 beq 0x287420 <Json_getItem+0x5c> */
/* @0x2873d8 adds r6, r1, #0 */
/* @0x2873dc movne r6, #1 */
/* @0x2873e0 b 0x2873f8 <Json_getItem+0x34> */
/* @0x2873e4 cmp r0, r5 */
/* @0x2873e8 beq 0x287420 <Json_getItem+0x5c> */
/* @0x2873ec ldr r4, [r4] */
/* @0x2873f0 cmp r4, #0 */
/* @0x2873f4 beq 0x287420 <Json_getItem+0x5c> */
/* @0x2873f8 ldr r0, [r4, #0x1c] */
/* @0x2873fc cmp r0, #0 */
/* @0x287400 moveq r3, #0 */
/* @0x287404 andne r3, r6, #1 */
/* @0x287408 cmp r3, #0 */
/* @0x28740c beq 0x2873e4 <Json_getItem+0x20> */
/* @0x287410 mov r1, r5 */
/* @0x287414 bl 0xb66d0 <strcasecmp@plt> */
/* @0x287418 cmp r0, #0 */
/* @0x28741c bne 0x2873ec <Json_getItem+0x28> */
/* @0x287420 mov r0, r4 */
/* @0x287424 pop {r4, r5, r6, pc} */

/* ── FUNC 0x287428 · Json_getString · size=28 · insn=7 */
/* @0x287428 push {r4, lr} */
/* @0x28742c mov r4, r2 */
/* @0x287430 bl 0x2873c4 <Json_getItem> */
/* @0x287434 cmp r0, #0 */
/* @0x287438 ldrne r0, [r0, #0x10] */
/* @0x28743c moveq r0, r4 */
/* @0x287440 pop {r4, pc} */

/* ── FUNC 0x287444 · Json_getFloat · size=28 · insn=7 */
/* @0x287444 push {r4, lr} */
/* @0x287448 mov r4, r2 */
/* @0x28744c bl 0x2873c4 <Json_getItem> */
/* @0x287450 cmp r0, #0 */
/* @0x287454 ldrne r0, [r0, #0x18] */
/* @0x287458 moveq r0, r4 */
/* @0x28745c pop {r4, pc} */

/* ── FUNC 0x287460 · Json_getInt · size=28 · insn=7 */
/* @0x287460 push {r4, lr} */
/* @0x287464 mov r4, r2 */
/* @0x287468 bl 0x2873c4 <Json_getItem> */
/* @0x28746c cmp r0, #0 */
/* @0x287470 ldrne r0, [r0, #0x14] */
/* @0x287474 moveq r0, r4 */
/* @0x287478 pop {r4, pc} */

/* ── FUNC 0x28747c · _spMeshAttachment_dispose · size=96 · insn=24 */
/* @0x28747c push {r4, lr} */
/* @0x287480 mov r4, r0 */
/* @0x287484 ldr r0, [r0, #0x54] */
/* @0x287488 bl 0x285c80 <_free> */
/* @0x28748c ldr r0, [r4, #0x5c] */
/* @0x287490 bl 0x285c80 <_free> */
/* @0x287494 ldr r3, [r4, #0x7c] */
/* @0x287498 mov r0, r4 */
/* @0x28749c cmp r3, #0 */
/* @0x2874a0 beq 0x2874b4 <_spMeshAttachment_dispose+0x38> */
/* @0x2874a4 bl 0x284c84 <_spAttachment_deinit> */
/* @0x2874a8 mov r0, r4 */
/* @0x2874ac pop {r4, lr} */
/* @0x2874b0 b 0x285c80 <_free> */
/* @0x2874b4 bl 0x28f62c <_spVertexAttachment_deinit> */
/* @0x2874b8 ldr r0, [r4, #0x58] */
/* @0x2874bc bl 0x285c80 <_free> */
/* @0x2874c0 ldr r0, [r4, #0x64] */
/* @0x2874c4 bl 0x285c80 <_free> */
/* @0x2874c8 ldr r0, [r4, #0x88] */
/* @0x2874cc bl 0x285c80 <_free> */
/* @0x2874d0 mov r0, r4 */
/* @0x2874d4 pop {r4, lr} */
/* @0x2874d8 b 0x285c80 <_free> */

/* ── FUNC 0x2874dc · spMeshAttachment_create · size=92 · insn=23 */
/* @0x2874dc ldr r2, [pc, #0x4c] */
/* @0x2874e0 mov r1, #148 */
/* @0x2874e4 push {r3, r4, r5, lr} */
/* @0x2874e8 add r2, pc, r2 */
/* @0x2874ec mov r5, r0 */
/* @0x2874f0 mov r3, #50 */
/* @0x2874f4 mov r0, #1 */
/* @0x2874f8 bl 0x285c4c <_calloc> */
/* @0x2874fc ldr r3, [pc, #0x30] */
/* @0x287500 mov r12, #1065353216 */
/* @0x287504 mov r1, r5 */
/* @0x287508 mov r2, #2 */
/* @0x28750c ldr r3, [pc, r3] */
/* @0x287510 mov r4, r0 */
/* @0x287514 str r12, [r0, #0x68] */
/* @0x287518 str r12, [r0, #0x6c] */
/* @0x28751c str r12, [r0, #0x70] */
/* @0x287520 str r12, [r0, #0x74] */
/* @0x287524 bl 0x284c18 <_spAttachment_init> */
/* @0x287528 mov r0, r4 */
/* @0x28752c pop {r3, r4, r5, pc} */
/* @0x287530 andeq r0, sp, r8, lsl r4 */
/* @0x287534 ldrsheq r10, [r6], -r4 */

/* ── FUNC 0x287538 · spMeshAttachment_updateUVs · size=280 · insn=70 */
/* @0x287538 push {r3, r4, r5, lr} */
/* @0x28753c vldr s15, [r0, #64] */
/* @0x287540 mov r4, r0 */
/* @0x287544 vpush {d8} */
/* @0x287548 ldr r5, [r0, #0x20] */
/* @0x28754c vldr s17, [r0, #72] */
/* @0x287550 ldr r0, [r0, #0x5c] */
/* @0x287554 vldr s16, [r4, #76] */
/* @0x287558 vsub.f32 s17, s17, s15 */
/* @0x28755c vldr s15, [r4, #68] */
/* @0x287560 vsub.f32 s16, s16, s15 */
/* @0x287564 bl 0x285c80 <_free> */
/* @0x287568 ldr r1, [pc, #0xdc] */
/* @0x28756c lsl r0, r5, #2 */
/* @0x287570 mov r2, #64 */
/* @0x287574 add r1, pc, r1 */
/* @0x287578 bl 0x285c10 <_malloc> */
/* @0x28757c ldr r3, [r4, #0x50] */
/* @0x287580 cmp r3, #0 */
/* @0x287584 str r0, [r4, #0x5c] */
/* @0x287588 bne 0x2875ec <spMeshAttachment_updateUVs+0xb4> */
/* @0x28758c cmp r5, #0 */
/* @0x287590 ble 0x2875e4 <spMeshAttachment_updateUVs+0xac> */
/* @0x287594 sub r2, r5, #1 */
/* @0x287598 ldr r3, [r4, #0x58] */
/* @0x28759c add r0, r0, #4 */
/* @0x2875a0 lsr r2, r2, #1 */
/* @0x2875a4 add r1, r3, #12 */
/* @0x2875a8 add r3, r3, #4 */
/* @0x2875ac add r2, r1, r2, lsl #3 */
/* @0x2875b0 vldr s14, [r3, #-4] */
/* @0x2875b4 vldr s15, [r4, #64] */
/* @0x2875b8 vmla.f32 s15, s17, s14 */
/* @0x2875bc mov r1, r3 */
/* @0x2875c0 add r3, r3, #8 */
/* @0x2875c4 cmp r3, r2 */
/* @0x2875c8 vstr s15, [r0, #-4] */
/* @0x2875cc vldr s14, [r1] */
/* @0x2875d0 vldr s15, [r4, #68] */
/* @0x2875d4 vmla.f32 s15, s16, s14 */
/* @0x2875d8 vmov r1, s15 */
/* @0x2875dc str r1, [r0], #8 */
/* @0x2875e0 bne 0x2875b0 <spMeshAttachment_updateUVs+0x78> */
/* @0x2875e4 vpop {d8} */
/* @0x2875e8 pop {r3, r4, r5, pc} */
/* @0x2875ec cmp r5, #0 */
/* @0x2875f0 ble 0x2875e4 <spMeshAttachment_updateUVs+0xac> */
/* @0x2875f4 sub r2, r5, #1 */
/* @0x2875f8 ldr r3, [r4, #0x58] */
/* @0x2875fc add r0, r0, #4 */
/* @0x287600 lsr r2, r2, #1 */
/* @0x287604 add r1, r3, #12 */
/* @0x287608 add r3, r3, #4 */
/* @0x28760c add r2, r1, r2, lsl #3 */
/* @0x287610 vldr s14, [r3] */
/* @0x287614 vldr s15, [r4, #64] */
/* @0x287618 vmla.f32 s15, s17, s14 */
/* @0x28761c add r3, r3, #8 */
/* @0x287620 vstr s15, [r0, #-4] */
/* @0x287624 vldr s15, [r4, #68] */
/* @0x287628 vadd.f32 s15, s16, s15 */
/* @0x28762c vldr s14, [r3, #-12] */
/* @0x287630 cmp r3, r2 */
/* @0x287634 vmls.f32 s15, s16, s14 */
/* @0x287638 vmov r1, s15 */
/* @0x28763c str r1, [r0], #8 */
/* @0x287640 bne 0x287610 <spMeshAttachment_updateUVs+0xd8> */
/* @0x287644 vpop {d8} */
/* @0x287648 pop {r3, r4, r5, pc} */
/* @0x28764c andeq r0, sp, r12, lsl #7 */

/* ── FUNC 0x287650 · spMeshAttachment_computeWorldVertices · size=4 · insn=1 */
/* @0x287650 b 0x28fa08 <spVertexAttachment_computeWorldVertices> */

/* ── FUNC 0x287654 · spMeshAttachment_setParentMesh · size=128 · insn=32 */
/* @0x287654 cmp r1, #0 */
/* @0x287658 str r1, [r0, #0x7c] */
/* @0x28765c push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x287660 beq 0x2876cc <spMeshAttachment_setParentMesh+0x78> */
/* @0x287664 ldr r11, [r1, #0x20] */
/* @0x287668 vldr s14, [r1, #140] */
/* @0x28766c ldr r10, [r1, #0x14] */
/* @0x287670 vldr s15, [r1, #144] */
/* @0x287674 ldr r9, [r1, #0x10] */
/* @0x287678 ldr r8, [r1, #0x1c] */
/* @0x28767c ldr r7, [r1, #0x18] */
/* @0x287680 ldr r6, [r1, #0x58] */
/* @0x287684 ldr r5, [r1, #0x64] */
/* @0x287688 ldr r4, [r1, #0x60] */
/* @0x28768c ldr r12, [r1, #0x78] */
/* @0x287690 ldr r2, [r1, #0x88] */
/* @0x287694 ldr r3, [r1, #0x84] */
/* @0x287698 vstr s14, [r0, #140] */
/* @0x28769c str r11, [r0, #0x20] */
/* @0x2876a0 vstr s15, [r0, #144] */
/* @0x2876a4 str r10, [r0, #0x14] */
/* @0x2876a8 str r9, [r0, #0x10] */
/* @0x2876ac str r8, [r0, #0x1c] */
/* @0x2876b0 str r7, [r0, #0x18] */
/* @0x2876b4 str r6, [r0, #0x58] */
/* @0x2876b8 str r5, [r0, #0x64] */
/* @0x2876bc str r4, [r0, #0x60] */
/* @0x2876c0 str r12, [r0, #0x78] */
/* @0x2876c4 str r2, [r0, #0x88] */
/* @0x2876c8 str r3, [r0, #0x84] */
/* @0x2876cc pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2876d0 bx lr */

/* ── FUNC 0x2876d4 · _spPathAttachment_dispose · size=32 · insn=8 */
/* @0x2876d4 push {r4, lr} */
/* @0x2876d8 mov r4, r0 */
/* @0x2876dc bl 0x28f62c <_spVertexAttachment_deinit> */
/* @0x2876e0 ldr r0, [r4, #0x28] */
/* @0x2876e4 bl 0x285c80 <_free> */
/* @0x2876e8 mov r0, r4 */
/* @0x2876ec pop {r4, lr} */
/* @0x2876f0 b 0x285c80 <_free> */

/* ── FUNC 0x2876f4 · spPathAttachment_create · size=72 · insn=18 */
/* @0x2876f4 ldr r2, [pc, #0x38] */
/* @0x2876f8 mov r1, #52 */
/* @0x2876fc push {r3, r4, r5, lr} */
/* @0x287700 add r2, pc, r2 */
/* @0x287704 mov r5, r0 */
/* @0x287708 mov r3, #45 */
/* @0x28770c mov r0, #1 */
/* @0x287710 bl 0x285c4c <_calloc> */
/* @0x287714 ldr r3, [pc, #0x1c] */
/* @0x287718 mov r1, r5 */
/* @0x28771c mov r2, #4 */
/* @0x287720 ldr r3, [pc, r3] */
/* @0x287724 mov r4, r0 */
/* @0x287728 bl 0x284c18 <_spAttachment_init> */
/* @0x28772c mov r0, r4 */
/* @0x287730 pop {r3, r4, r5, pc} */
/* @0x287734 andeq r0, sp, r12, lsr r2 */
/* @0x287738 andseq r10, r6, r4, ror #3 */

/* ── FUNC 0x28773c · spPathAttachment_computeWorldVertices · size=4 · insn=1 */
/* @0x28773c b 0x28fa08 <spVertexAttachment_computeWorldVertices> */

/* ── FUNC 0x287740 · spPathAttachment_computeWorldVertices1 · size=28 · insn=7 */
/* @0x287740 str r4, [sp, #-0x4]! */
/* @0x287744 mov r4, r1 */
/* @0x287748 mov r1, r2 */
/* @0x28774c mov r2, r3 */
/* @0x287750 mov r3, r4 */
/* @0x287754 ldr r4, [sp], #4 */
/* @0x287758 b 0x28f64c <spVertexAttachment_computeWorldVertices1> */

/* ── FUNC 0x28775c · anon_28775c · size=524 · insn=132 */
/* @0x28775c vcmp.f32 s0, #0 */
/* @0x287760 push {r4, lr} */
/* @0x287764 vmrs APSR_nzcv, fpscr */
/* @0x287768 beq 0x287818 <spPathAttachment_computeWorldVertices1+0xd8> */
/* @0x28776c vmov.f32 s12, #1.000000e+00 */
/* @0x287770 vsub.f32 s12, s12, s0 */
/* @0x287774 vmul.f32 s9, s0, s12 */
/* @0x287778 vmov.f32 s13, #3.000000e+00 */
/* @0x28777c vmul.f32 s10, s12, s12 */
/* @0x287780 vmul.f32 s13, s9, s13 */
/* @0x287784 vmul.f32 s11, s0, s0 */
/* @0x287788 vmul.f32 s14, s12, s13 */
/* @0x28778c vmul.f32 s13, s0, s13 */
/* @0x287790 vmul.f32 s12, s12, s10 */
/* @0x287794 vmul.f32 s0, s0, s11 */
/* @0x287798 cmp r2, #0 */
/* @0x28779c add r4, r0, r1, lsl #2 */
/* @0x2877a0 vmul.f32 s15, s3, s14 */
/* @0x2877a4 vmul.f32 s14, s4, s14 */
/* @0x2877a8 vmla.f32 s15, s1, s12 */
/* @0x2877ac vmla.f32 s14, s2, s12 */
/* @0x2877b0 vmla.f32 s15, s5, s13 */
/* @0x2877b4 vmla.f32 s14, s6, s13 */
/* @0x2877b8 vmla.f32 s15, s7, s0 */
/* @0x2877bc vmla.f32 s14, s8, s0 */
/* @0x2877c0 vstr s15, [r4] */
/* @0x2877c4 vstr s14, [r4, #4] */
/* @0x2877c8 popeq {r4, pc} */
/* @0x2877cc vmul.f32 s4, s4, s9 */
/* @0x2877d0 vmul.f32 s3, s3, s9 */
/* @0x2877d4 vadd.f32 s4, s4, s4 */
/* @0x2877d8 vadd.f32 s3, s3, s3 */
/* @0x2877dc vmla.f32 s4, s2, s10 */
/* @0x2877e0 vmla.f32 s3, s1, s10 */
/* @0x2877e4 vmla.f32 s4, s6, s11 */
/* @0x2877e8 vmla.f32 s3, s5, s11 */
/* @0x2877ec vsub.f32 s14, s14, s4 */
/* @0x2877f0 vsub.f32 s15, s15, s3 */
/* @0x2877f4 vcvt.f64.f32 d6, s14 */
/* @0x2877f8 vmov r0, r1, d6 */
/* @0x2877fc vcvt.f64.f32 d6, s15 */
/* @0x287800 vmov r2, r3, d6 */
/* @0x287804 bl 0xb6c70 <atan2@plt> */
/* @0x287808 vmov d6, r0, r1 */
/* @0x28780c vcvt.f32.f64 s15, d6 */
/* @0x287810 vstr s15, [r4, #8] */
/* @0x287814 pop {r4, pc} */
/* @0x287818 vldr s13, [pc, #24] */
/* @0x28781c vldr s14, [pc, #24] */
/* @0x287820 vldr s9, [pc, #24] */
/* @0x287824 vldr s12, [pc, #24] */
/* @0x287828 vldr s10, [pc, #24] */
/* @0x28782c vldr s0, [pc, #24] */
/* @0x287830 vldr s11, [pc, #24] */
/* @0x287834 b 0x287798 <spPathAttachment_computeWorldVertices1+0x58> */
/* @0x287838 movwlo sp, #0x60c */
/* @0x28783c ldmiblo sp, {r0, r1, r6, r8, lr} */
/* @0x287840 ldmlo r1, {r3, r4, r5, r7, r8, r12, sp, pc} ^ */
/* @0x287844 svclo #0x7fec56 */
/* @0x287848 svclo #0x7ff2e4 */
/* @0x28784c blhs 0xfe5b6b80 <b2_toiTime+0xfffffffffde5d6dc> */
/* @0x287850 eorlo r12, r11, #30208 */
/* @0x287854 add r1, r1, #2 */
/* @0x287858 push {r4, lr} */
/* @0x28785c vpush {d8, d9, d10} */
/* @0x287860 add r0, r0, r1, lsl #2 */
/* @0x287864 vldr s21, [r0] */
/* @0x287868 vldr s14, [r0, #-8] */
/* @0x28786c vsub.f32 s14, s21, s14 */
/* @0x287870 vldr s18, [r0, #4] */
/* @0x287874 vldr s15, [r0, #-4] */
/* @0x287878 lsl r4, r3, #2 */
/* @0x28787c add r4, r2, r4 */
/* @0x287880 vsub.f32 s15, s18, s15 */
/* @0x287884 vcvt.f64.f32 d6, s14 */
/* @0x287888 vmov r2, r3, d6 */
/* @0x28788c vcvt.f64.f32 d6, s15 */
/* @0x287890 vmov r0, r1, d6 */
/* @0x287894 vmov.f32 s19, s0 */
/* @0x287898 bl 0xb6c70 <atan2@plt> */
/* @0x28789c vmov d7, r0, r1 */
/* @0x2878a0 vcvt.f32.f64 s20, d7 */
/* @0x2878a4 vcvt.f64.f32 d8, s20 */
/* @0x2878a8 vmov r0, r1, d8 */
/* @0x2878ac bl 0xb67e4 <cos@plt> */
/* @0x2878b0 vmov d6, r0, r1 */
/* @0x2878b4 vcvt.f32.f64 s15, d6 */
/* @0x2878b8 vmov r0, r1, d8 */
/* @0x2878bc vmla.f32 s21, s15, s19 */
/* @0x2878c0 vstr s21, [r4] */
/* @0x2878c4 bl 0xb67d8 <sin@plt> */
/* @0x2878c8 vstr s20, [r4, #8] */
/* @0x2878cc vmov d6, r0, r1 */
/* @0x2878d0 vcvt.f32.f64 s15, d6 */
/* @0x2878d4 vmla.f32 s18, s15, s19 */
/* @0x2878d8 vstr s18, [r4, #4] */
/* @0x2878dc vpop {d8, d9, d10} */
/* @0x2878e0 pop {r4, pc} */
/* @0x2878e4 push {r4, lr} */
/* @0x2878e8 vldr s15, [r0, #8] */
/* @0x2878ec vpush {d8, d9, d10} */
/* @0x2878f0 vldr s21, [r0] */
/* @0x2878f4 vsub.f32 s15, s15, s21 */
/* @0x2878f8 vldr s18, [r0, #4] */
/* @0x2878fc vldr s14, [r0, #12] */
/* @0x287900 lsl r4, r2, #2 */
/* @0x287904 add r4, r1, r4 */
/* @0x287908 vsub.f32 s14, s14, s18 */
/* @0x28790c vcvt.f64.f32 d6, s15 */
/* @0x287910 vmov r2, r3, d6 */
/* @0x287914 vcvt.f64.f32 d6, s14 */
/* @0x287918 vmov r0, r1, d6 */
/* @0x28791c vmov.f32 s19, s0 */
/* @0x287920 bl 0xb6c70 <atan2@plt> */
/* @0x287924 vmov d7, r0, r1 */
/* @0x287928 vcvt.f32.f64 s20, d7 */
/* @0x28792c vcvt.f64.f32 d8, s20 */
/* @0x287930 vmov r0, r1, d8 */
/* @0x287934 bl 0xb67e4 <cos@plt> */
/* @0x287938 vmov d6, r0, r1 */
/* @0x28793c vcvt.f32.f64 s15, d6 */
/* @0x287940 vmov r0, r1, d8 */
/* @0x287944 vmla.f32 s21, s15, s19 */
/* @0x287948 vstr s21, [r4] */
/* @0x28794c bl 0xb67d8 <sin@plt> */
/* @0x287950 vstr s20, [r4, #8] */
/* @0x287954 vmov d6, r0, r1 */
/* @0x287958 vcvt.f32.f64 s15, d6 */
/* @0x28795c vmla.f32 s18, s19, s15 */
/* @0x287960 vstr s18, [r4, #4] */
/* @0x287964 vpop {d8, d9, d10} */
/* @0x287968 pop {r4, pc} */

/* ── FUNC 0x28796c · spPathConstraint_create · size=260 · insn=65 */
/* @0x28796c push {r4, r5, r6, r7, r8, lr} */
/* @0x287970 mov r3, #42 */
/* @0x287974 ldr r5, [pc, #0xf0] */
/* @0x287978 mov r8, r0 */
/* @0x28797c mov r7, r1 */
/* @0x287980 mov r0, #1 */
/* @0x287984 add r5, pc, r5 */
/* @0x287988 mov r1, #112 */
/* @0x28798c mov r2, r5 */
/* @0x287990 bl 0x285c4c <_calloc> */
/* @0x287994 mov r1, r5 */
/* @0x287998 mov r2, #45 */
/* @0x28799c mov r4, r0 */
/* @0x2879a0 ldr r0, [r8, #0x4] */
/* @0x2879a4 str r8, [r4] */
/* @0x2879a8 str r0, [r4, #0x4] */
/* @0x2879ac lsl r0, r0, #2 */
/* @0x2879b0 bl 0x285c10 <_malloc> */
/* @0x2879b4 ldr r3, [r4, #0x4] */
/* @0x2879b8 cmp r3, #0 */
/* @0x2879bc str r0, [r4, #0x8] */
/* @0x2879c0 ble 0x287a00 <spPathConstraint_create+0x94> */
/* @0x2879c4 mov r6, r0 */
/* @0x2879c8 mov r5, #0 */
/* @0x2879cc b 0x2879d4 <spPathConstraint_create+0x68> */
/* @0x2879d0 ldr r6, [r4, #0x8] */
/* @0x2879d4 ldr r3, [r4] */
/* @0x2879d8 mov r0, r7 */
/* @0x2879dc ldr r3, [r3, #0x8] */
/* @0x2879e0 ldr r3, [r3, r5, lsl #2] */
/* @0x2879e4 ldr r1, [r3, #0x4] */
/* @0x2879e8 bl 0x28a0c8 <spSkeleton_findBone> */
/* @0x2879ec ldr r3, [r4, #0x4] */
/* @0x2879f0 str r0, [r6, r5, lsl #2] */
/* @0x2879f4 add r5, r5, #1 */
/* @0x2879f8 cmp r3, r5 */
/* @0x2879fc bgt 0x2879d0 <spPathConstraint_create+0x64> */
/* @0x287a00 ldr r3, [r4] */
/* @0x287a04 mov r0, r7 */
/* @0x287a08 ldr r3, [r3, #0xc] */
/* @0x287a0c ldr r1, [r3, #0x4] */
/* @0x287a10 bl 0x28a18c <spSkeleton_findSlot> */
/* @0x287a14 ldr r2, [r8, #0x20] */
/* @0x287a18 ldr r3, [r8, #0x24] */
/* @0x287a1c str r2, [r4, #0x10] */
/* @0x287a20 str r3, [r4, #0x14] */
/* @0x287a24 ldr r2, [r8, #0x28] */
/* @0x287a28 ldr r3, [r8, #0x2c] */
/* @0x287a2c str r2, [r4, #0x18] */
/* @0x287a30 str r3, [r4, #0x1c] */
/* @0x287a34 mov r3, #0 */
/* @0x287a38 str r3, [r4, #0x20] */
/* @0x287a3c str r3, [r4, #0x24] */
/* @0x287a40 str r3, [r4, #0x28] */
/* @0x287a44 str r3, [r4, #0x2c] */
/* @0x287a48 str r3, [r4, #0x30] */
/* @0x287a4c str r3, [r4, #0x34] */
/* @0x287a50 str r3, [r4, #0x38] */
/* @0x287a54 str r3, [r4, #0x3c] */
/* @0x287a58 str r3, [r4, #0x40] */
/* @0x287a5c str r3, [r4, #0x44] */
/* @0x287a60 str r0, [r4, #0xc] */
/* @0x287a64 mov r0, r4 */
/* @0x287a68 pop {r4, r5, r6, r7, r8, pc} */
/* @0x287a6c .word 0x000cfff4 */

/* ── FUNC 0x287a70 · spPathConstraint_dispose · size=100 · insn=25 */
/* @0x287a70 push {r4, lr} */
/* @0x287a74 mov r4, r0 */
/* @0x287a78 ldr r0, [r0, #0x8] */
/* @0x287a7c bl 0x285c80 <_free> */
/* @0x287a80 ldr r0, [r4, #0x24] */
/* @0x287a84 bl 0x285c80 <_free> */
/* @0x287a88 ldr r0, [r4, #0x2c] */
/* @0x287a8c cmp r0, #0 */
/* @0x287a90 beq 0x287a98 <spPathConstraint_dispose+0x28> */
/* @0x287a94 bl 0x285c80 <_free> */
/* @0x287a98 ldr r0, [r4, #0x34] */
/* @0x287a9c cmp r0, #0 */
/* @0x287aa0 beq 0x287aa8 <spPathConstraint_dispose+0x38> */
/* @0x287aa4 bl 0x285c80 <_free> */
/* @0x287aa8 ldr r0, [r4, #0x3c] */
/* @0x287aac cmp r0, #0 */
/* @0x287ab0 beq 0x287ab8 <spPathConstraint_dispose+0x48> */
/* @0x287ab4 bl 0x285c80 <_free> */
/* @0x287ab8 ldr r0, [r4, #0x44] */
/* @0x287abc cmp r0, #0 */
/* @0x287ac0 beq 0x287ac8 <spPathConstraint_dispose+0x58> */
/* @0x287ac4 bl 0x285c80 <_free> */
/* @0x287ac8 mov r0, r4 */
/* @0x287acc pop {r4, lr} */
/* @0x287ad0 b 0x285c80 <_free> */

/* ── FUNC 0x287ad4 · spPathConstraint_computeWorldPositions · size=3252 · insn=813 */
/* @0x287ad4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x287ad8 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x287adc sub sp, sp, #52 */
/* @0x287ae0 add r4, r2, r2, lsl #1 */
/* @0x287ae4 mov r6, r0 */
/* @0x287ae8 str r2, [sp, #0xc] */
/* @0x287aec add r4, r4, #2 */
/* @0x287af0 ldr r2, [r0, #0x28] */
/* @0x287af4 mov r9, r1 */
/* @0x287af8 ldr r0, [r0, #0xc] */
/* @0x287afc vldr s16, [r6, #16] */
/* @0x287b00 cmp r2, r4 */
/* @0x287b04 str r3, [sp, #0x28] */
/* @0x287b08 ldr r11, [r6, #0x24] */
/* @0x287b0c str r0, [sp, #0x10] */
/* @0x287b10 beq 0x2885c8 <spPathConstraint_computeWorldPositions+0xaf4> */
/* @0x287b14 ldr r0, [r6, #0x2c] */
/* @0x287b18 cmp r0, #0 */
/* @0x287b1c beq 0x287b24 <spPathConstraint_computeWorldPositions+0x50> */
/* @0x287b20 bl 0x285c80 <_free> */
/* @0x287b24 ldr r1, [pc, #0x2b4] */
/* @0x287b28 lsl r0, r4, #2 */
/* @0x287b2c mov r2, #219 */
/* @0x287b30 add r1, pc, r1 */
/* @0x287b34 bl 0x285c10 <_malloc> */
/* @0x287b38 str r4, [r6, #0x28] */
/* @0x287b3c str r0, [sp, #0x1c] */
/* @0x287b40 str r0, [r6, #0x2c] */
/* @0x287b44 ldr r2, [r9, #0x20] */
/* @0x287b48 movw r4, #0xaaab */
/* @0x287b4c movt r4, #0x2aaa */
/* @0x287b50 ldr r3, [r9, #0x30] */
/* @0x287b54 ldr r0, [r9, #0x2c] */
/* @0x287b58 str r2, [sp, #0x14] */
/* @0x287b5c cmp r3, #0 */
/* @0x287b60 smull r2, r4, r4, r2 */
/* @0x287b64 ldr r1, [sp, #0x14] */
/* @0x287b68 str r0, [sp, #0x24] */
/* @0x287b6c sub r4, r4, r1, asr #31 */
/* @0x287b70 bne 0x287dfc <spPathConstraint_computeWorldPositions+0x328> */
/* @0x287b74 cmp r0, #0 */
/* @0x287b78 ldr r2, [sp, #0x98] */
/* @0x287b7c ldr r10, [r9, #0x28] */
/* @0x287b80 moveq r3, #2 */
/* @0x287b84 movne r3, #1 */
/* @0x287b88 rsb r3, r3, r4 */
/* @0x287b8c cmp r2, #0 */
/* @0x287b90 str r3, [sp, #0x20] */
/* @0x287b94 add r3, r10, r3, lsl #2 */
/* @0x287b98 vldr s18, [r3] */
/* @0x287b9c ldr r3, [sp, #0x9c] */
/* @0x287ba0 vmulne.f32 s16, s16, s18 */
/* @0x287ba4 cmp r3, #0 */
/* @0x287ba8 beq 0x287bd4 <spPathConstraint_computeWorldPositions+0x100> */
/* @0x287bac ldr r0, [sp, #0xc] */
/* @0x287bb0 cmp r0, #0 */
/* @0x287bb4 ble 0x287bd4 <spPathConstraint_computeWorldPositions+0x100> */
/* @0x287bb8 add r2, r11, r0, lsl #2 */
/* @0x287bbc mov r3, r11 */
/* @0x287bc0 vldr s15, [r3] */
/* @0x287bc4 vmul.f32 s15, s15, s18 */
/* @0x287bc8 vstmia r3!, {s15} */
/* @0x287bcc cmp r3, r2 */
/* @0x287bd0 bne 0x287bc0 <spPathConstraint_computeWorldPositions+0xec> */
/* @0x287bd4 ldr r3, [r6, #0x30] */
/* @0x287bd8 cmp r3, #8 */
/* @0x287bdc beq 0x2885d4 <spPathConstraint_computeWorldPositions+0xb00> */
/* @0x287be0 ldr r0, [r6, #0x34] */
/* @0x287be4 cmp r0, #0 */
/* @0x287be8 beq 0x287bf0 <spPathConstraint_computeWorldPositions+0x11c> */
/* @0x287bec bl 0x285c80 <_free> */
/* @0x287bf0 ldr r1, [pc, #0x1ec] */
/* @0x287bf4 mov r0, #32 */
/* @0x287bf8 mov r2, #237 */
/* @0x287bfc add r1, pc, r1 */
/* @0x287c00 bl 0x285c10 <_malloc> */
/* @0x287c04 mov r3, #8 */
/* @0x287c08 str r3, [r6, #0x30] */
/* @0x287c0c mov r4, r0 */
/* @0x287c10 str r0, [r6, #0x34] */
/* @0x287c14 ldr r1, [sp, #0xc] */
/* @0x287c18 cmp r1, #0 */
/* @0x287c1c ble 0x28848c <spPathConstraint_computeWorldPositions+0x9b8> */
/* @0x287c20 ldr r2, [sp, #0x14] */
/* @0x287c24 mov r6, #0 */
/* @0x287c28 mov r7, r11 */
/* @0x287c2c mov r5, r6 */
/* @0x287c30 sub r2, r2, #6 */
/* @0x287c34 mvn r8, #0 */
/* @0x287c38 str r2, [sp, #0x2c] */
/* @0x287c3c ldr r11, [sp, #0x24] */
/* @0x287c40 str r9, [sp, #0x18] */
/* @0x287c44 b 0x287d94 <spPathConstraint_computeWorldPositions+0x2c0> */
/* @0x287c48 vcmpe.f32 s16, #0 */
/* @0x287c4c vmrs APSR_nzcv, fpscr */
/* @0x287c50 bmi 0x288588 <spPathConstraint_computeWorldPositions+0xab4> */
/* @0x287c54 vcmpe.f32 s18, s16 */
/* @0x287c58 vmrs APSR_nzcv, fpscr */
/* @0x287c5c bmi 0x288518 <spPathConstraint_computeWorldPositions+0xa44> */
/* @0x287c60 vmov.f32 s0, s16 */
/* @0x287c64 lsl r2, r6, #2 */
/* @0x287c68 mov r3, r6 */
/* @0x287c6c add r2, r10, r2 */
/* @0x287c70 vldr s15, [r2] */
/* @0x287c74 vcmpe.f32 s0, s15 */
/* @0x287c78 vmrs APSR_nzcv, fpscr */
/* @0x287c7c ble 0x288508 <spPathConstraint_computeWorldPositions+0xa34> */
/* @0x287c80 add r3, r6, #1 */
/* @0x287c84 add r2, r10, r3, lsl #2 */
/* @0x287c88 vldmia r2!, {s15} */
/* @0x287c8c vcmpe.f32 s0, s15 */
/* @0x287c90 mov r6, r3 */
/* @0x287c94 mov r1, r3 */
/* @0x287c98 add r3, r3, #1 */
/* @0x287c9c vmrs APSR_nzcv, fpscr */
/* @0x287ca0 bgt 0x287c88 <spPathConstraint_computeWorldPositions+0x1b4> */
/* @0x287ca4 add r1, r10, r1, lsl #2 */
/* @0x287ca8 vldr s14, [r1, #-4] */
/* @0x287cac vsub.f32 s0, s0, s14 */
/* @0x287cb0 vsub.f32 s15, s15, s14 */
/* @0x287cb4 cmp r6, r8 */
/* @0x287cb8 vdiv.f32 s19, s0, s15 */
/* @0x287cbc beq 0x287d28 <spPathConstraint_computeWorldPositions+0x254> */
/* @0x287cc0 ldr r0, [sp, #0x20] */
/* @0x287cc4 subs r2, r6, r0 */
/* @0x287cc8 rsbs r3, r2, #0 */
/* @0x287ccc adcs r3, r3, r2 */
/* @0x287cd0 cmp r11, #0 */
/* @0x287cd4 moveq r3, #0 */
/* @0x287cd8 cmp r3, #0 */
/* @0x287cdc beq 0x28855c <spPathConstraint_computeWorldPositions+0xa88> */
/* @0x287ce0 ldr r3, [sp, #0x14] */
/* @0x287ce4 mov r1, #0 */
/* @0x287ce8 ldr r0, [sp, #0x18] */
/* @0x287cec mov r8, r6 */
/* @0x287cf0 sub r2, r3, #4 */
/* @0x287cf4 str r1, [sp, #0x4] */
/* @0x287cf8 mov r3, #4 */
/* @0x287cfc ldr r1, [sp, #0x10] */
/* @0x287d00 str r4, [sp] */
/* @0x287d04 bl 0x287740 <spPathAttachment_computeWorldVertices1> */
/* @0x287d08 mov r0, #4 */
/* @0x287d0c str r4, [sp] */
/* @0x287d10 mov r2, #0 */
/* @0x287d14 str r0, [sp, #0x4] */
/* @0x287d18 mov r3, #4 */
/* @0x287d1c ldr r0, [sp, #0x18] */
/* @0x287d20 ldr r1, [sp, #0x10] */
/* @0x287d24 bl 0x287740 <spPathAttachment_computeWorldVertices1> */
/* @0x287d28 ldr r1, [sp, #0x28] */
/* @0x287d2c vldr s1, [r4] */
/* @0x287d30 vldr s2, [r4, #4] */
/* @0x287d34 vldr s3, [r4, #8] */
/* @0x287d38 cmp r1, #0 */
/* @0x287d3c vldr s4, [r4, #12] */
/* @0x287d40 vldr s5, [r4, #16] */
/* @0x287d44 vldr s6, [r4, #20] */
/* @0x287d48 vldr s7, [r4, #24] */
/* @0x287d4c vldr s8, [r4, #28] */
/* @0x287d50 movne r2, #1 */
/* @0x287d54 bne 0x287d74 <spPathConstraint_computeWorldPositions+0x2a0> */
/* @0x287d58 vcmp.f32 s17, #0 */
/* @0x287d5c vmrs APSR_nzcv, fpscr */
/* @0x287d60 movne r2, #0 */
/* @0x287d64 moveq r2, #1 */
/* @0x287d68 cmp r5, #0 */
/* @0x287d6c movle r2, #0 */
/* @0x287d70 andgt r2, r2, #1 */
/* @0x287d74 vmov.f32 s0, s19 */
/* @0x287d78 mov r1, r9 */
/* @0x287d7c ldr r0, [sp, #0x1c] */
/* @0x287d80 bl 0x28775c <spPathAttachment_computeWorldVertices1+0x1c> */
/* @0x287d84 ldr r2, [sp, #0xc] */
/* @0x287d88 add r5, r5, #1 */
/* @0x287d8c cmp r5, r2 */
/* @0x287d90 beq 0x28848c <spPathConstraint_computeWorldPositions+0x9b8> */
/* @0x287d94 cmp r11, #0 */
/* @0x287d98 vldmia r7!, {s17} */
/* @0x287d9c add r9, r5, r5, lsl #1 */
/* @0x287da0 vadd.f32 s16, s16, s17 */
/* @0x287da4 beq 0x287c48 <spPathConstraint_computeWorldPositions+0x174> */
/* @0x287da8 vcvt.f64.f32 d6, s16 */
/* @0x287dac vcvt.f64.f32 d7, s18 */
/* @0x287db0 vmov r0, r1, d6 */
/* @0x287db4 vmov r2, r3, d7 */
/* @0x287db8 bl 0xb66ac <fmod@plt> */
/* @0x287dbc mov r3, #0 */
/* @0x287dc0 mov r2, r3 */
/* @0x287dc4 mov r6, r3 */
/* @0x287dc8 vmov d6, r0, r1 */
/* @0x287dcc vcvt.f32.f64 s0, d6 */
/* @0x287dd0 vcmpe.f32 s0, #0 */
/* @0x287dd4 vmrs APSR_nzcv, fpscr */
/* @0x287dd8 vaddmi.f32 s0, s0, s18 */
/* @0x287ddc b 0x287c6c <spPathConstraint_computeWorldPositions+0x198> */
/* @0x287de0 andeq pc, r12, r8, asr #28 */
/* @0x287de4 andeq pc, r12, r12, ror sp */
/* @0x287de8 andeq pc, r12, r0, asr #22 */
/* @0x287dec muleq r12, r8, r10 */
/* @0x287df0 andeq pc, r12, r12, lsr #9 */
/* @0x287df4 stcllo p0, c0, [r0] */
/* @0x287df8 andeq r0, r0, r0 */
/* @0x287dfc ldr r3, [sp, #0x24] */
/* @0x287e00 cmp r3, #0 */
/* @0x287e04 ldr r3, [r6, #0x30] */
/* @0x287e08 beq 0x28849c <spPathConstraint_computeWorldPositions+0x9c8> */
/* @0x287e0c ldr r0, [sp, #0x14] */
/* @0x287e10 add r10, r0, #2 */
/* @0x287e14 cmp r3, r10 */
/* @0x287e18 beq 0x2885dc <spPathConstraint_computeWorldPositions+0xb08> */
/* @0x287e1c ldr r0, [r6, #0x34] */
/* @0x287e20 cmp r0, #0 */
/* @0x287e24 beq 0x287e2c <spPathConstraint_computeWorldPositions+0x358> */
/* @0x287e28 bl 0x285c80 <_free> */
/* @0x287e2c ldr r1, [pc, #-0x4c] */
/* @0x287e30 lsl r0, r10, #2 */
/* @0x287e34 movw r2, #0x129 */
/* @0x287e38 add r1, pc, r1 */
/* @0x287e3c bl 0x285c10 <_malloc> */
/* @0x287e40 str r10, [r6, #0x30] */
/* @0x287e44 str r0, [sp, #0x18] */
/* @0x287e48 str r0, [r6, #0x34] */
/* @0x287e4c ldr r2, [sp, #0x14] */
/* @0x287e50 mov r5, #0 */
/* @0x287e54 ldr r3, [sp, #0x18] */
/* @0x287e58 mov r0, r9 */
/* @0x287e5c sub r7, r2, #2 */
/* @0x287e60 ldr r1, [sp, #0x10] */
/* @0x287e64 mov r2, #2 */
/* @0x287e68 str r5, [sp, #0x4] */
/* @0x287e6c str r3, [sp] */
/* @0x287e70 mov r3, r7 */
/* @0x287e74 bl 0x287740 <spPathAttachment_computeWorldVertices1> */
/* @0x287e78 ldr r0, [sp, #0x18] */
/* @0x287e7c mov r2, r5 */
/* @0x287e80 ldr r1, [sp, #0x10] */
/* @0x287e84 mov r3, #2 */
/* @0x287e88 str r7, [sp, #0x4] */
/* @0x287e8c str r0, [sp] */
/* @0x287e90 mov r0, r9 */
/* @0x287e94 bl 0x287740 <spPathAttachment_computeWorldVertices1> */
/* @0x287e98 ldr r1, [sp, #0x18] */
/* @0x287e9c sub r3, r10, #-1073741822 */
/* @0x287ea0 ldr r2, [r1] */
/* @0x287ea4 add r3, r1, r3, lsl #2 */
/* @0x287ea8 str r2, [r3] */
/* @0x287eac ldr r2, [r1, #0x4] */
/* @0x287eb0 str r2, [r3, #0x4] */
/* @0x287eb4 ldr r3, [r6, #0x38] */
/* @0x287eb8 cmp r3, r4 */
/* @0x287ebc ldreq r12, [r6, #0x3c] */
/* @0x287ec0 beq 0x287ef4 <spPathConstraint_computeWorldPositions+0x420> */
/* @0x287ec4 ldr r0, [r6, #0x3c] */
/* @0x287ec8 cmp r0, #0 */
/* @0x287ecc beq 0x287ed4 <spPathConstraint_computeWorldPositions+0x400> */
/* @0x287ed0 bl 0x285c80 <_free> */
/* @0x287ed4 ldr r1, [pc, #-0xf0] */
/* @0x287ed8 lsl r0, r4, #2 */
/* @0x287edc mov r2, #320 */
/* @0x287ee0 add r1, pc, r1 */
/* @0x287ee4 bl 0x285c10 <_malloc> */
/* @0x287ee8 str r4, [r6, #0x38] */
/* @0x287eec mov r12, r0 */
/* @0x287ef0 str r0, [r6, #0x3c] */
/* @0x287ef4 cmp r4, #0 */
/* @0x287ef8 ldr r1, [sp, #0x18] */
/* @0x287efc vldr s15, [r1] */
/* @0x287f00 vldr s13, [r1, #4] */
/* @0x287f04 ble 0x288698 <spPathConstraint_computeWorldPositions+0xbc4> */
/* @0x287f08 vmov.f32 s31, #1.875000e-01 */
/* @0x287f0c add r5, r1, #28 */
/* @0x287f10 mov r8, r12 */
/* @0x287f14 mov r7, #0 */
/* @0x287f18 vldr s27, [pc, #-296] */
/* @0x287f1c vldr s30, [pc, #-304] */
/* @0x287f20 vldr s18, [r5, #-16] */
/* @0x287f24 vldr s17, [r5, #-20] */
/* @0x287f28 vldr s26, [r5, #-8] */
/* @0x287f2c mov r2, #0 */
/* @0x287f30 movt r2, #0x4040 */
/* @0x287f34 vldr s25, [r5, #-12] */
/* @0x287f38 mov r1, #1061158912 */
/* @0x287f3c vldr s22, [r5] */
/* @0x287f40 vmov s12, r2 */
/* @0x287f44 vldr s21, [r5, #-4] */
/* @0x287f48 add r7, r7, #1 */
/* @0x287f4c add r5, r5, #24 */
/* @0x287f50 vadd.f32 s28, s18, s18 */
/* @0x287f54 vsub.f32 s28, s13, s28 */
/* @0x287f58 vadd.f32 s29, s17, s17 */
/* @0x287f5c vsub.f32 s14, s18, s26 */
/* @0x287f60 vmov.f32 s23, s13 */
/* @0x287f64 vadd.f32 s28, s28, s26 */
/* @0x287f68 vsub.f32 s29, s15, s29 */
/* @0x287f6c vnmls.f32 s23, s14, s12 */
/* @0x287f70 vsub.f32 s14, s17, s25 */
/* @0x287f74 vmul.f32 s28, s28, s31 */
/* @0x287f78 vmov.f32 s24, s15 */
/* @0x287f7c vadd.f32 s29, s29, s25 */
/* @0x287f80 vnmls.f32 s24, s14, s12 */
/* @0x287f84 vmov s12, r1 */
/* @0x287f88 movw r1, #0xaaab */
/* @0x287f8c movt r1, #0x3e2a */
/* @0x287f90 vsub.f32 s13, s18, s13 */
/* @0x287f94 vmov.f32 s20, s28 */
/* @0x287f98 vmul.f32 s29, s29, s31 */
/* @0x287f9c vadd.f32 s23, s23, s22 */
/* @0x287fa0 vmla.f32 s20, s13, s12 */
/* @0x287fa4 vsub.f32 s15, s17, s15 */
/* @0x287fa8 vmov.f32 s19, s29 */
/* @0x287fac vmul.f32 s23, s23, s30 */
/* @0x287fb0 vadd.f32 s24, s24, s21 */
/* @0x287fb4 vmla.f32 s19, s15, s12 */
/* @0x287fb8 vmov s12, r1 */
/* @0x287fbc vmul.f32 s24, s24, s30 */
/* @0x287fc0 vmla.f32 s20, s23, s12 */
/* @0x287fc4 vmla.f32 s19, s24, s12 */
/* @0x287fc8 vmul.f32 s14, s20, s20 */
/* @0x287fcc vmla.f32 s14, s19, s19 */
/* @0x287fd0 vcvt.f64.f32 d7, s14 */
/* @0x287fd4 vsqrt.f64 d6, d7 */
/* @0x287fd8 vadd.f32 s28, s28, s28 */
/* @0x287fdc vadd.f32 s29, s29, s29 */
/* @0x287fe0 vcmp.f64 d6, d6 */
/* @0x287fe4 vadd.f32 s28, s28, s23 */
/* @0x287fe8 vmrs APSR_nzcv, fpscr */
/* @0x287fec vadd.f32 s29, s29, s24 */
/* @0x287ff0 bne 0x28876c <spPathConstraint_computeWorldPositions+0xc98> */
/* @0x287ff4 vadd.f32 s20, s20, s28 */
/* @0x287ff8 vmul.f32 s10, s20, s20 */
/* @0x287ffc vadd.f32 s19, s19, s29 */
/* @0x288000 vmla.f32 s10, s19, s19 */
/* @0x288004 vcvt.f64.f32 d5, s10 */
/* @0x288008 vsqrt.f64 d7, d5 */
/* @0x28800c vcvt.f32.f64 s12, d6 */
/* @0x288010 vcmp.f64 d7, d7 */
/* @0x288014 vadd.f32 s27, s12, s27 */
/* @0x288018 vmrs APSR_nzcv, fpscr */
/* @0x28801c vadd.f32 s29, s29, s24 */
/* @0x288020 vadd.f32 s28, s28, s23 */
/* @0x288024 bne 0x288754 <spPathConstraint_computeWorldPositions+0xc80> */
/* @0x288028 vadd.f32 s20, s20, s28 */
/* @0x28802c vmul.f32 s10, s20, s20 */
/* @0x288030 vadd.f32 s19, s19, s29 */
/* @0x288034 vmla.f32 s10, s19, s19 */
/* @0x288038 vcvt.f64.f32 d5, s10 */
/* @0x28803c vsqrt.f64 d6, d5 */
/* @0x288040 vcvt.f32.f64 s14, d7 */
/* @0x288044 vcmp.f64 d6, d6 */
/* @0x288048 vadd.f32 s27, s14, s27 */
/* @0x28804c vmrs APSR_nzcv, fpscr */
/* @0x288050 bne 0x28873c <spPathConstraint_computeWorldPositions+0xc68> */
/* @0x288054 vadd.f32 s28, s28, s23 */
/* @0x288058 vadd.f32 s28, s28, s20 */
/* @0x28805c vadd.f32 s29, s29, s24 */
/* @0x288060 vmul.f32 s28, s28, s28 */
/* @0x288064 vadd.f32 s19, s29, s19 */
/* @0x288068 vmla.f32 s28, s19, s19 */
/* @0x28806c vcvt.f64.f32 d14, s28 */
/* @0x288070 vsqrt.f64 d7, d14 */
/* @0x288074 vcvt.f32.f64 s12, d6 */
/* @0x288078 vcmp.f64 d7, d7 */
/* @0x28807c vadd.f32 s27, s12, s27 */
/* @0x288080 vmrs APSR_nzcv, fpscr */
/* @0x288084 bne 0x288724 <spPathConstraint_computeWorldPositions+0xc50> */
/* @0x288088 cmp r7, r4 */
/* @0x28808c vcvt.f32.f64 s14, d7 */
/* @0x288090 vadd.f32 s27, s14, s27 */
/* @0x288094 vmov.f32 s13, s22 */
/* @0x288098 vstmia r8!, {s27} */
/* @0x28809c vmov.f32 s15, s21 */
/* @0x2880a0 bne 0x287f20 <spPathConstraint_computeWorldPositions+0x44c> */
/* @0x2880a4 vstr s22, [sp, #16] */
/* @0x2880a8 vstr s21, [sp, #20] */
/* @0x2880ac ldr r0, [sp, #0x98] */
/* @0x2880b0 ldr r1, [sp, #0x9c] */
/* @0x2880b4 cmp r0, #0 */
/* @0x2880b8 vmulne.f32 s16, s16, s27 */
/* @0x2880bc cmp r1, #0 */
/* @0x2880c0 beq 0x288684 <spPathConstraint_computeWorldPositions+0xbb0> */
/* @0x2880c4 ldr r2, [sp, #0xc] */
/* @0x2880c8 cmp r2, #0 */
/* @0x2880cc ble 0x28848c <spPathConstraint_computeWorldPositions+0x9b8> */
/* @0x2880d0 add r2, r11, r2, lsl #2 */
/* @0x2880d4 mov r3, r11 */
/* @0x2880d8 vldr s15, [r3] */
/* @0x2880dc vmul.f32 s15, s15, s27 */
/* @0x2880e0 vstmia r3!, {s15} */
/* @0x2880e4 cmp r3, r2 */
/* @0x2880e8 bne 0x2880d8 <spPathConstraint_computeWorldPositions+0x604> */
/* @0x2880ec add r9, r6, #72 */
/* @0x2880f0 mov r8, #0 */
/* @0x2880f4 sub r10, r10, #4 */
/* @0x2880f8 mov r7, r11 */
/* @0x2880fc str r10, [sp, #0x2c] */
/* @0x288100 mov r5, r8 */
/* @0x288104 mov r4, r8 */
/* @0x288108 mvn r10, #0 */
/* @0x28810c mov r11, r12 */
/* @0x288110 vldr s23, [pc, #-800] */
/* @0x288114 ldr r0, [sp, #0x24] */
/* @0x288118 vldmia r7!, {s31} */
/* @0x28811c add r12, r4, r4, lsl #1 */
/* @0x288120 vadd.f32 s16, s16, s31 */
/* @0x288124 cmp r0, #0 */
/* @0x288128 bne 0x288610 <spPathConstraint_computeWorldPositions+0xb3c> */
/* @0x28812c vcmpe.f32 s16, #0 */
/* @0x288130 vmrs APSR_nzcv, fpscr */
/* @0x288134 bmi 0x28866c <spPathConstraint_computeWorldPositions+0xb98> */
/* @0x288138 vcmpe.f32 s16, s27 */
/* @0x28813c vmrs APSR_nzcv, fpscr */
/* @0x288140 bgt 0x288650 <spPathConstraint_computeWorldPositions+0xb7c> */
/* @0x288144 vmov.f32 s14, s16 */
/* @0x288148 lsl r3, r5, #2 */
/* @0x28814c mov r1, r5 */
/* @0x288150 add r3, r11, r3 */
/* @0x288154 vldr s15, [r3] */
/* @0x288158 vcmpe.f32 s14, s15 */
/* @0x28815c vmrs APSR_nzcv, fpscr */
/* @0x288160 ble 0x2885f4 <spPathConstraint_computeWorldPositions+0xb20> */
/* @0x288164 add r3, r5, #1 */
/* @0x288168 add r2, r11, r3, lsl #2 */
/* @0x28816c vldmia r2!, {s15} */
/* @0x288170 vcmpe.f32 s15, s14 */
/* @0x288174 mov r5, r3 */
/* @0x288178 mov r1, r3 */
/* @0x28817c add r3, r3, #1 */
/* @0x288180 vmrs APSR_nzcv, fpscr */
/* @0x288184 bmi 0x28816c <spPathConstraint_computeWorldPositions+0x698> */
/* @0x288188 add r1, r11, r1, lsl #2 */
/* @0x28818c vldr s13, [r1, #-4] */
/* @0x288190 vsub.f32 s14, s14, s13 */
/* @0x288194 vsub.f32 s15, s15, s13 */
/* @0x288198 cmp r5, r10 */
/* @0x28819c lsleq r3, r8, #2 */
/* @0x2881a0 moveq r1, r8 */
/* @0x2881a4 vdiv.f32 s15, s14, s15 */
/* @0x2881a8 vstr s15, [sp, #32] */
/* @0x2881ac beq 0x2883b0 <spPathConstraint_computeWorldPositions+0x8dc> */
/* @0x2881b0 add r2, r5, r5, lsl #1 */
/* @0x2881b4 ldr r0, [sp, #0x18] */
/* @0x2881b8 vmov.f32 s15, #3.000000e+00 */
/* @0x2881bc add r3, r0, r2, lsl #3 */
/* @0x2881c0 vldr s18, [r3, #12] */
/* @0x2881c4 vldr s22, [r3, #4] */
/* @0x2881c8 vldr s17, [r3, #8] */
/* @0x2881cc vldr s26, [r3, #20] */
/* @0x2881d0 movw r0, #0xc28f */
/* @0x2881d4 movt r0, #0x3cf5 */
/* @0x2881d8 vldr s21, [r3] */
/* @0x2881dc vldr s12, [r3, #28] */
/* @0x2881e0 vstr s12, [sp, #16] */
/* @0x2881e4 vmov s12, r0 */
/* @0x2881e8 vldr s25, [r3, #16] */
/* @0x2881ec vldr s13, [r3, #24] */
/* @0x2881f0 vstr s13, [sp, #20] */
/* @0x2881f4 movw r0, #0x999a */
/* @0x2881f8 movt r0, #0x3e99 */
/* @0x2881fc mov r2, r3 */
/* @0x288200 vadd.f32 s28, s18, s18 */
/* @0x288204 vsub.f32 s28, s22, s28 */
/* @0x288208 vsub.f32 s14, s18, s26 */
/* @0x28820c vadd.f32 s24, s17, s17 */
/* @0x288210 vadd.f32 s28, s28, s26 */
/* @0x288214 vmov.f32 s30, s22 */
/* @0x288218 vsub.f32 s24, s21, s24 */
/* @0x28821c vnmls.f32 s30, s14, s15 */
/* @0x288220 vmul.f32 s28, s28, s12 */
/* @0x288224 vmov s12, r0 */
/* @0x288228 movw r0, #0xc28f */
/* @0x28822c movt r0, #0x3cf5 */
/* @0x288230 vsub.f32 s13, s17, s25 */
/* @0x288234 vsub.f32 s14, s18, s22 */
/* @0x288238 vmov.f32 s29, s21 */
/* @0x28823c vadd.f32 s24, s24, s25 */
/* @0x288240 vnmls.f32 s29, s13, s15 */
/* @0x288244 vldr s13, [sp, #16] */
/* @0x288248 vmov.f32 s20, s28 */
/* @0x28824c vmla.f32 s20, s14, s12 */
/* @0x288250 vmov s12, r0 */
/* @0x288254 movw r0, #0x9ba6 */
/* @0x288258 movt r0, #0x3bc4 */
/* @0x28825c vmul.f32 s24, s24, s12 */
/* @0x288260 vmov s12, r0 */
/* @0x288264 movw r0, #0x999a */
/* @0x288268 movt r0, #0x3e99 */
/* @0x28826c vadd.f32 s30, s30, s13 */
/* @0x288270 vldr s13, [sp, #20] */
/* @0x288274 vsub.f32 s15, s17, s21 */
/* @0x288278 vmul.f32 s30, s30, s12 */
/* @0x28827c vmov s12, r0 */
/* @0x288280 movw r0, #0xaaab */
/* @0x288284 movt r0, #0x3e2a */
/* @0x288288 vmov.f32 s19, s24 */
/* @0x28828c vadd.f32 s29, s29, s13 */
/* @0x288290 vmla.f32 s19, s15, s12 */
/* @0x288294 vmov s12, r0 */
/* @0x288298 movw r0, #0x9ba6 */
/* @0x28829c movt r0, #0x3bc4 */
/* @0x2882a0 vmla.f32 s20, s30, s12 */
/* @0x2882a4 vmov s12, r0 */
/* @0x2882a8 movw r0, #0xaaab */
/* @0x2882ac movt r0, #0x3e2a */
/* @0x2882b0 vmul.f32 s29, s29, s12 */
/* @0x2882b4 vmov s12, r0 */
/* @0x2882b8 vmla.f32 s19, s29, s12 */
/* @0x2882bc vmul.f32 s12, s20, s20 */
/* @0x2882c0 vmla.f32 s12, s19, s19 */
/* @0x2882c4 vcvt.f64.f32 d6, s12 */
/* @0x2882c8 vsqrt.f64 d7, d6 */
/* @0x2882cc vadd.f32 s28, s28, s28 */
/* @0x2882d0 vadd.f32 s24, s24, s24 */
/* @0x2882d4 vcmp.f64 d7, d7 */
/* @0x2882d8 vadd.f32 s28, s28, s30 */
/* @0x2882dc vmrs APSR_nzcv, fpscr */
/* @0x2882e0 vadd.f32 s24, s24, s29 */
/* @0x2882e4 bne 0x2886dc <spPathConstraint_computeWorldPositions+0xc08> */
/* @0x2882e8 add r10, r9, #4 */
/* @0x2882ec mov r8, #1 */
/* @0x2882f0 vcvt.f32.f64 s23, d7 */
/* @0x2882f4 vstr s23, [r6, #72] */
/* @0x2882f8 vadd.f32 s20, s20, s28 */
/* @0x2882fc add r8, r8, #1 */
/* @0x288300 vmul.f32 s12, s20, s20 */
/* @0x288304 vadd.f32 s19, s19, s24 */
/* @0x288308 vmla.f32 s12, s19, s19 */
/* @0x28830c vcvt.f64.f32 d6, s12 */
/* @0x288310 vsqrt.f64 d7, d6 */
/* @0x288314 vcmp.f64 d7, d7 */
/* @0x288318 vadd.f32 s24, s24, s29 */
/* @0x28831c vmrs APSR_nzcv, fpscr */
/* @0x288320 vadd.f32 s28, s28, s30 */
/* @0x288324 bne 0x2886c4 <spPathConstraint_computeWorldPositions+0xbf0> */
/* @0x288328 cmp r8, #8 */
/* @0x28832c vcvt.f32.f64 s14, d7 */
/* @0x288330 vadd.f32 s23, s23, s14 */
/* @0x288334 vstmia r10!, {s23} */
/* @0x288338 bne 0x2882f8 <spPathConstraint_computeWorldPositions+0x824> */
/* @0x28833c vadd.f32 s20, s20, s28 */
/* @0x288340 vmul.f32 s14, s20, s20 */
/* @0x288344 vadd.f32 s19, s19, s24 */
/* @0x288348 vmla.f32 s14, s19, s19 */
/* @0x28834c vcvt.f64.f32 d7, s14 */
/* @0x288350 vsqrt.f64 d6, d7 */
/* @0x288354 vcmp.f64 d6, d6 */
/* @0x288358 vmrs APSR_nzcv, fpscr */
/* @0x28835c bne 0x28870c <spPathConstraint_computeWorldPositions+0xc38> */
/* @0x288360 vadd.f32 s10, s30, s28 */
/* @0x288364 vadd.f32 s10, s10, s20 */
/* @0x288368 vadd.f32 s24, s29, s24 */
/* @0x28836c vmul.f32 s10, s10, s10 */
/* @0x288370 vadd.f32 s19, s24, s19 */
/* @0x288374 vmla.f32 s10, s19, s19 */
/* @0x288378 vcvt.f64.f32 d5, s10 */
/* @0x28837c vsqrt.f64 d7, d5 */
/* @0x288380 vcvt.f32.f64 s12, d6 */
/* @0x288384 vadd.f32 s23, s23, s12 */
/* @0x288388 vcmp.f64 d7, d7 */
/* @0x28838c vstr s23, [r6, #104] */
/* @0x288390 vmrs APSR_nzcv, fpscr */
/* @0x288394 bne 0x2886f4 <spPathConstraint_computeWorldPositions+0xc20> */
/* @0x288398 vcvt.f32.f64 s14, d7 */
/* @0x28839c mov r3, #0 */
/* @0x2883a0 mov r1, r3 */
/* @0x2883a4 mov r8, r3 */
/* @0x2883a8 vadd.f32 s23, s14, s23 */
/* @0x2883ac vstr s23, [r6, #108] */
/* @0x2883b0 vldr s13, [sp, #32] */
/* @0x2883b4 vmul.f32 s14, s13, s23 */
/* @0x2883b8 add r3, r9, r3 */
/* @0x2883bc vldr s15, [r3] */
/* @0x2883c0 vcmpe.f32 s14, s15 */
/* @0x2883c4 vmrs APSR_nzcv, fpscr */
/* @0x2883c8 ble 0x288600 <spPathConstraint_computeWorldPositions+0xb2c> */
/* @0x2883cc add r3, r8, #1 */
/* @0x2883d0 add r2, r9, r3, lsl #2 */
/* @0x2883d4 vldmia r2!, {s15} */
/* @0x2883d8 vcmpe.f32 s14, s15 */
/* @0x2883dc mov r8, r3 */
/* @0x2883e0 mov r1, r3 */
/* @0x2883e4 add r3, r3, #1 */
/* @0x2883e8 vmrs APSR_nzcv, fpscr */
/* @0x2883ec bgt 0x2883d4 <spPathConstraint_computeWorldPositions+0x900> */
/* @0x2883f0 add r1, r9, r1, lsl #2 */
/* @0x2883f4 vldr s13, [r1, #-4] */
/* @0x2883f8 vsub.f32 s14, s14, s13 */
/* @0x2883fc vsub.f32 s15, s15, s13 */
/* @0x288400 vdiv.f32 s15, s14, s15 */
/* @0x288404 vmov s14, r8 */
/* @0x288408 vcvt.f32.s32 s0, s14 */
/* @0x28840c vadd.f32 s0, s0, s15 */
/* @0x288410 ldr r0, [sp, #0x28] */
/* @0x288414 movw r1, #0xcccd */
/* @0x288418 movt r1, #0x3dcc */
/* @0x28841c cmp r0, #0 */
/* @0x288420 vmov s12, r1 */
/* @0x288424 movne r2, #1 */
/* @0x288428 vmul.f32 s0, s0, s12 */
/* @0x28842c bne 0x28844c <spPathConstraint_computeWorldPositions+0x978> */
/* @0x288430 vcmp.f32 s31, #0 */
/* @0x288434 vmrs APSR_nzcv, fpscr */
/* @0x288438 movne r2, #0 */
/* @0x28843c moveq r2, #1 */
/* @0x288440 cmp r4, #0 */
/* @0x288444 movle r2, #0 */
/* @0x288448 andgt r2, r2, #1 */
/* @0x28844c mov r1, r12 */
/* @0x288450 vmov.f32 s1, s21 */
/* @0x288454 ldr r0, [sp, #0x1c] */
/* @0x288458 vldr s7, [sp, #20] */
/* @0x28845c vldr s8, [sp, #16] */
/* @0x288460 mov r10, r5 */
/* @0x288464 vmov.f32 s2, s22 */
/* @0x288468 vmov.f32 s3, s17 */
/* @0x28846c vmov.f32 s4, s18 */
/* @0x288470 vmov.f32 s5, s25 */
/* @0x288474 vmov.f32 s6, s26 */
/* @0x288478 bl 0x28775c <spPathAttachment_computeWorldVertices1+0x1c> */
/* @0x28847c ldr r0, [sp, #0xc] */
/* @0x288480 add r4, r4, #1 */
/* @0x288484 cmp r0, r4 */
/* @0x288488 bgt 0x288114 <spPathConstraint_computeWorldPositions+0x640> */
/* @0x28848c ldr r0, [sp, #0x1c] */
/* @0x288490 add sp, sp, #52 */
/* @0x288494 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x288498 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x28849c ldr r2, [sp, #0x14] */
/* @0x2884a0 sub r4, r4, #1 */
/* @0x2884a4 sub r10, r2, #4 */
/* @0x2884a8 cmp r3, r10 */
/* @0x2884ac beq 0x2885e8 <spPathConstraint_computeWorldPositions+0xb14> */
/* @0x2884b0 ldr r0, [r6, #0x34] */
/* @0x2884b4 cmp r0, #0 */
/* @0x2884b8 beq 0x2884c0 <spPathConstraint_computeWorldPositions+0x9ec> */
/* @0x2884bc bl 0x285c80 <_free> */
/* @0x2884c0 ldr r1, [pc, #-0x6d8] */
/* @0x2884c4 lsl r0, r10, #2 */
/* @0x2884c8 movw r2, #0x136 */
/* @0x2884cc add r1, pc, r1 */
/* @0x2884d0 bl 0x285c10 <_malloc> */
/* @0x2884d4 str r10, [r6, #0x30] */
/* @0x2884d8 str r0, [sp, #0x18] */
/* @0x2884dc str r0, [r6, #0x34] */
/* @0x2884e0 ldr r0, [sp, #0x18] */
/* @0x2884e4 mov r3, #0 */
/* @0x2884e8 ldr r1, [sp, #0x10] */
/* @0x2884ec mov r2, #2 */
/* @0x2884f0 str r3, [sp, #0x4] */
/* @0x2884f4 mov r3, r10 */
/* @0x2884f8 str r0, [sp] */
/* @0x2884fc mov r0, r9 */
/* @0x288500 bl 0x287740 <spPathAttachment_computeWorldVertices1> */
/* @0x288504 b 0x287eb4 <spPathConstraint_computeWorldPositions+0x3e0> */
/* @0x288508 cmp r6, #0 */
/* @0x28850c beq 0x287cb4 <spPathConstraint_computeWorldPositions+0x1e0> */
/* @0x288510 mov r1, r3 */
/* @0x288514 b 0x287ca4 <spPathConstraint_computeWorldPositions+0x1d0> */
/* @0x288518 cmn r8, #3 */
/* @0x28851c beq 0x28853c <spPathConstraint_computeWorldPositions+0xa68> */
/* @0x288520 str r4, [sp] */
/* @0x288524 mov r3, #4 */
/* @0x288528 ldr r0, [sp, #0x18] */
/* @0x28852c str r11, [sp, #0x4] */
/* @0x288530 ldr r1, [sp, #0x10] */
/* @0x288534 ldr r2, [sp, #0x2c] */
/* @0x288538 bl 0x287740 <spPathAttachment_computeWorldVertices1> */
/* @0x28853c mov r3, r9 */
/* @0x288540 vsub.f32 s0, s16, s18 */
/* @0x288544 mov r0, r4 */
/* @0x288548 mov r1, #0 */
/* @0x28854c ldr r2, [sp, #0x1c] */
/* @0x288550 mvn r8, #2 */
/* @0x288554 bl 0x287854 <spPathAttachment_computeWorldVertices1+0x114> */
/* @0x288558 b 0x287d84 <spPathConstraint_computeWorldPositions+0x2b0> */
/* @0x28855c add r2, r6, r6, lsl #1 */
/* @0x288560 str r3, [sp, #0x4] */
/* @0x288564 str r4, [sp] */
/* @0x288568 mov r3, #8 */
/* @0x28856c lsl r2, r2, #1 */
/* @0x288570 ldr r0, [sp, #0x18] */
/* @0x288574 ldr r1, [sp, #0x10] */
/* @0x288578 add r2, r2, #2 */
/* @0x28857c bl 0x287740 <spPathAttachment_computeWorldVertices1> */
/* @0x288580 mov r8, r6 */
/* @0x288584 b 0x287d28 <spPathConstraint_computeWorldPositions+0x254> */
/* @0x288588 cmn r8, #2 */
/* @0x28858c beq 0x2885ac <spPathConstraint_computeWorldPositions+0xad8> */
/* @0x288590 str r4, [sp] */
/* @0x288594 mov r2, #2 */
/* @0x288598 ldr r0, [sp, #0x18] */
/* @0x28859c mov r3, #4 */
/* @0x2885a0 str r11, [sp, #0x4] */
/* @0x2885a4 ldr r1, [sp, #0x10] */
/* @0x2885a8 bl 0x287740 <spPathAttachment_computeWorldVertices1> */
/* @0x2885ac mov r2, r9 */
/* @0x2885b0 vmov.f32 s0, s16 */
/* @0x2885b4 mov r0, r4 */
/* @0x2885b8 ldr r1, [sp, #0x1c] */
/* @0x2885bc bl 0x2878e4 <spPathAttachment_computeWorldVertices1+0x1a4> */
/* @0x2885c0 mvn r8, #1 */
/* @0x2885c4 b 0x287d84 <spPathConstraint_computeWorldPositions+0x2b0> */
/* @0x2885c8 ldr r1, [r6, #0x2c] */
/* @0x2885cc str r1, [sp, #0x1c] */
/* @0x2885d0 b 0x287b44 <spPathConstraint_computeWorldPositions+0x70> */
/* @0x2885d4 ldr r4, [r6, #0x34] */
/* @0x2885d8 b 0x287c14 <spPathConstraint_computeWorldPositions+0x140> */
/* @0x2885dc ldr r1, [r6, #0x34] */
/* @0x2885e0 str r1, [sp, #0x18] */
/* @0x2885e4 b 0x287e4c <spPathConstraint_computeWorldPositions+0x378> */
/* @0x2885e8 ldr r3, [r6, #0x34] */
/* @0x2885ec str r3, [sp, #0x18] */
/* @0x2885f0 b 0x2884e0 <spPathConstraint_computeWorldPositions+0xa0c> */
/* @0x2885f4 cmp r5, #0 */
/* @0x2885f8 beq 0x288198 <spPathConstraint_computeWorldPositions+0x6c4> */
/* @0x2885fc b 0x288188 <spPathConstraint_computeWorldPositions+0x6b4> */
/* @0x288600 cmp r8, #0 */
/* @0x288604 bne 0x2883f0 <spPathConstraint_computeWorldPositions+0x91c> */
/* @0x288608 vdiv.f32 s0, s14, s15 */
/* @0x28860c b 0x288410 <spPathConstraint_computeWorldPositions+0x93c> */
/* @0x288610 vcvt.f64.f32 d6, s16 */
/* @0x288614 str r12, [sp, #0x8] */
/* @0x288618 vcvt.f64.f32 d7, s27 */
/* @0x28861c vmov r0, r1, d6 */
/* @0x288620 vmov r2, r3, d7 */
/* @0x288624 bl 0xb66ac <fmod@plt> */
/* @0x288628 mov r3, #0 */
/* @0x28862c ldr r12, [sp, #0x8] */
/* @0x288630 mov r5, r3 */
/* @0x288634 vmov d6, r0, r1 */
/* @0x288638 mov r1, r3 */
/* @0x28863c vcvt.f32.f64 s14, d6 */
/* @0x288640 vcmpe.f32 s14, #0 */
/* @0x288644 vmrs APSR_nzcv, fpscr */
/* @0x288648 vaddmi.f32 s14, s14, s27 */
/* @0x28864c b 0x288150 <spPathConstraint_computeWorldPositions+0x67c> */
/* @0x288650 mov r3, r12 */
/* @0x288654 vsub.f32 s0, s16, s27 */
/* @0x288658 ldr r0, [sp, #0x18] */
/* @0x28865c ldr r1, [sp, #0x2c] */
/* @0x288660 ldr r2, [sp, #0x1c] */
/* @0x288664 bl 0x287854 <spPathAttachment_computeWorldVertices1+0x114> */
/* @0x288668 b 0x28847c <spPathConstraint_computeWorldPositions+0x9a8> */
/* @0x28866c mov r2, r12 */
/* @0x288670 vmov.f32 s0, s16 */
/* @0x288674 ldr r0, [sp, #0x18] */
/* @0x288678 ldr r1, [sp, #0x1c] */
/* @0x28867c bl 0x2878e4 <spPathAttachment_computeWorldVertices1+0x1a4> */
/* @0x288680 b 0x28847c <spPathConstraint_computeWorldPositions+0x9a8> */
/* @0x288684 ldr r3, [sp, #0xc] */
/* @0x288688 add r9, r6, #72 */
/* @0x28868c cmp r3, #0 */
/* @0x288690 bgt 0x2880f0 <spPathConstraint_computeWorldPositions+0x61c> */
/* @0x288694 b 0x28848c <spPathConstraint_computeWorldPositions+0x9b8> */
/* @0x288698 vldr s12, [pc, #228] */
/* @0x28869c vmov.f32 s22, s13 */
/* @0x2886a0 vstr s12, [sp, #16] */
/* @0x2886a4 vstr s12, [sp, #20] */
/* @0x2886a8 vmov.f32 s21, s15 */
/* @0x2886ac vmov.f32 s26, s12 */
/* @0x2886b0 vmov.f32 s25, s12 */
/* @0x2886b4 vmov.f32 s18, s12 */
/* @0x2886b8 vmov.f32 s17, s12 */
/* @0x2886bc vmov.f32 s27, s12 */
/* @0x2886c0 b 0x2880ac <spPathConstraint_computeWorldPositions+0x5d8> */
/* @0x2886c4 vmov r0, r1, d6 */
/* @0x2886c8 str r12, [sp, #0x8] */
/* @0x2886cc bl 0xb66f4 <sqrt@plt> */
/* @0x2886d0 ldr r12, [sp, #0x8] */
/* @0x2886d4 vmov d7, r0, r1 */
/* @0x2886d8 b 0x288328 <spPathConstraint_computeWorldPositions+0x854> */
/* @0x2886dc vmov r0, r1, d6 */
/* @0x2886e0 str r12, [sp, #0x8] */
/* @0x2886e4 bl 0xb66f4 <sqrt@plt> */
/* @0x2886e8 ldr r12, [sp, #0x8] */
/* @0x2886ec vmov d7, r0, r1 */
/* @0x2886f0 b 0x2882e8 <spPathConstraint_computeWorldPositions+0x814> */
/* @0x2886f4 vmov r0, r1, d5 */
/* @0x2886f8 str r12, [sp, #0x8] */
/* @0x2886fc bl 0xb66f4 <sqrt@plt> */
/* @0x288700 ldr r12, [sp, #0x8] */
/* @0x288704 vmov d7, r0, r1 */
/* @0x288708 b 0x288398 <spPathConstraint_computeWorldPositions+0x8c4> */
/* @0x28870c vmov r0, r1, d7 */
/* @0x288710 str r12, [sp, #0x8] */
/* @0x288714 bl 0xb66f4 <sqrt@plt> */
/* @0x288718 ldr r12, [sp, #0x8] */
/* @0x28871c vmov d6, r0, r1 */
/* @0x288720 b 0x288360 <spPathConstraint_computeWorldPositions+0x88c> */
/* @0x288724 vmov r0, r1, d14 */
/* @0x288728 str r12, [sp, #0x8] */
/* @0x28872c bl 0xb66f4 <sqrt@plt> */
/* @0x288730 ldr r12, [sp, #0x8] */
/* @0x288734 vmov d7, r0, r1 */
/* @0x288738 b 0x288088 <spPathConstraint_computeWorldPositions+0x5b4> */
/* @0x28873c vmov r0, r1, d5 */
/* @0x288740 str r12, [sp, #0x8] */
/* @0x288744 bl 0xb66f4 <sqrt@plt> */
/* @0x288748 ldr r12, [sp, #0x8] */
/* @0x28874c vmov d6, r0, r1 */
/* @0x288750 b 0x288054 <spPathConstraint_computeWorldPositions+0x580> */
/* @0x288754 vmov r0, r1, d5 */
/* @0x288758 str r12, [sp, #0x8] */
/* @0x28875c bl 0xb66f4 <sqrt@plt> */
/* @0x288760 ldr r12, [sp, #0x8] */
/* @0x288764 vmov d7, r0, r1 */
/* @0x288768 b 0x288028 <spPathConstraint_computeWorldPositions+0x554> */
/* @0x28876c vmov r0, r1, d7 */
/* @0x288770 str r12, [sp, #0x8] */
/* @0x288774 bl 0xb66f4 <sqrt@plt> */
/* @0x288778 ldr r12, [sp, #0x8] */
/* @0x28877c vmov d6, r0, r1 */
/* @0x288780 b 0x287ff4 <spPathConstraint_computeWorldPositions+0x520> */
/* @0x288784 andeq r0, r0, r0 */

/* ── FUNC 0x288788 · spPathConstraint_apply · size=1876 · insn=469 */
/* @0x288788 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x28878c vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x288790 vldr s22, [r0, #28] */
/* @0x288794 vcmpe.f32 s22, #0 */
/* @0x288798 ldr r5, [r0] */
/* @0x28879c vldr s25, [r0, #24] */
/* @0x2887a0 ldr r2, [r0, #0xc] */
/* @0x2887a4 sub sp, sp, #52 */
/* @0x2887a8 ldr r8, [r0, #0x4] */
/* @0x2887ac mov r4, r0 */
/* @0x2887b0 vmrs APSR_nzcv, fpscr */
/* @0x2887b4 vcmpe.f32 s25, #0 */
/* @0x2887b8 ldr r9, [r5, #0x18] */
/* @0x2887bc movle r3, #0 */
/* @0x2887c0 movgt r3, #1 */
/* @0x2887c4 ldr r6, [r2, #0x18] */
/* @0x2887c8 ldr r2, [r0, #0x8] */
/* @0x2887cc vmrs APSR_nzcv, fpscr */
/* @0x2887d0 movle r10, #0 */
/* @0x2887d4 movgt r10, #1 */
/* @0x2887d8 rsbs r1, r9, #1 */
/* @0x2887dc ldr r12, [r5, #0x14] */
/* @0x2887e0 str r2, [sp, #0x20] */
/* @0x2887e4 movlo r1, #0 */
/* @0x2887e8 cmp r1, #0 */
/* @0x2887ec addeq r7, r8, #1 */
/* @0x2887f0 str r1, [sp, #0x14] */
/* @0x2887f4 movne r7, r8 */
/* @0x2887f8 orrs r3, r10, r3 */
/* @0x2887fc beq 0x288814 <spPathConstraint_apply+0x8c> */
/* @0x288800 cmp r6, #0 */
/* @0x288804 beq 0x288814 <spPathConstraint_apply+0x8c> */
/* @0x288808 ldr r3, [r6, #0x4] */
/* @0x28880c cmp r3, #4 */
/* @0x288810 beq 0x288820 <spPathConstraint_apply+0x98> */
/* @0x288814 add sp, sp, #52 */
/* @0x288818 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x28881c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x288820 ldr r3, [r0, #0x20] */
/* @0x288824 cmp r7, r3 */
/* @0x288828 beq 0x288b38 <spPathConstraint_apply+0x3b0> */
/* @0x28882c ldr r0, [r0, #0x24] */
/* @0x288830 cmp r0, #0 */
/* @0x288834 beq 0x288844 <spPathConstraint_apply+0xbc> */
/* @0x288838 str r12, [sp, #0x8] */
/* @0x28883c bl 0x285c80 <_free> */
/* @0x288840 ldr r12, [sp, #0x8] */
/* @0x288844 ldr r1, [pc, #0x41c] */
/* @0x288848 lsl r0, r7, #2 */
/* @0x28884c mov r2, #100 */
/* @0x288850 str r12, [sp, #0x8] */
/* @0x288854 add r1, pc, r1 */
/* @0x288858 bl 0x285c10 <_malloc> */
/* @0x28885c ldr r12, [sp, #0x8] */
/* @0x288860 str r7, [r4, #0x20] */
/* @0x288864 str r0, [sp, #0x28] */
/* @0x288868 str r0, [r4, #0x24] */
/* @0x28886c subs lr, r9, #2 */
/* @0x288870 vldr s17, [pc, #1004] */
/* @0x288874 rsbs r9, lr, #0 */
/* @0x288878 ldr r2, [sp, #0x28] */
/* @0x28887c adcs r9, r9, lr */
/* @0x288880 str r9, [sp, #0x18] */
/* @0x288884 ldr r1, [sp, #0x18] */
/* @0x288888 rsbs r9, r12, #1 */
/* @0x28888c vstr s17, [r2] */
/* @0x288890 vldr s16, [r4, #20] */
/* @0x288894 movlo r9, #0 */
/* @0x288898 orrs r1, r1, r9 */
/* @0x28889c bne 0x288bdc <spPathConstraint_apply+0x454> */
/* @0x2888a0 cmp r7, #1 */
/* @0x2888a4 ble 0x2888c0 <spPathConstraint_apply+0x138> */
/* @0x2888a8 ldr r2, [sp, #0x28] */
/* @0x2888ac add r3, r2, #4 */
/* @0x2888b0 add r2, r2, r7, lsl #2 */
/* @0x2888b4 vstmia r3!, {s16} */
/* @0x2888b8 cmp r3, r2 */
/* @0x2888bc bne 0x2888b4 <spPathConstraint_apply+0x12c> */
/* @0x2888c0 mov r3, #0 */
/* @0x2888c4 str r3, [sp, #0x2c] */
/* @0x2888c8 ldr r3, [r5, #0x10] */
/* @0x2888cc subs r2, r12, #2 */
/* @0x2888d0 rsbs r12, r2, #0 */
/* @0x2888d4 mov r1, r6 */
/* @0x2888d8 adcs r12, r12, r2 */
/* @0x2888dc subs r0, r3, #1 */
/* @0x2888e0 rsbs r3, r0, #0 */
/* @0x2888e4 str r12, [sp, #0x4] */
/* @0x2888e8 adcs r3, r3, r0 */
/* @0x2888ec mov r2, r7 */
/* @0x2888f0 str r3, [sp] */
/* @0x2888f4 mov r0, r4 */
/* @0x2888f8 ldr r3, [sp, #0x14] */
/* @0x2888fc bl 0x287ad4 <spPathConstraint_computeWorldPositions> */
/* @0x288900 ldr r3, [r4] */
/* @0x288904 vldr s10, [r3, #28] */
/* @0x288908 ldr r3, [r4, #0xc] */
/* @0x28890c vcmp.f32 s10, #0 */
/* @0x288910 ldr r1, [sp, #0x18] */
/* @0x288914 vstr s10, [sp, #28] */
/* @0x288918 ldr r3, [r3, #0x4] */
/* @0x28891c vmrs APSR_nzcv, fpscr */
/* @0x288920 movne r1, #0 */
/* @0x288924 andeq r1, r1, #1 */
/* @0x288928 cmp r8, #0 */
/* @0x28892c ldr r3, [r3, #0x4] */
/* @0x288930 str r1, [sp, #0x24] */
/* @0x288934 vldr s28, [r3, #88] */
/* @0x288938 vldr s29, [r3, #92] */
/* @0x28893c vldr s17, [r0] */
/* @0x288940 vldr s30, [r0, #4] */
/* @0x288944 ble 0x288814 <spPathConstraint_apply+0x8c> */
/* @0x288948 ldr r3, [sp, #0x28] */
/* @0x28894c mov r11, #0 */
/* @0x288950 ldr r2, [sp, #0x20] */
/* @0x288954 add r5, r0, #20 */
/* @0x288958 add r7, r3, #4 */
/* @0x28895c mov r3, r11 */
/* @0x288960 sub r9, r2, #4 */
/* @0x288964 mov r11, r8 */
/* @0x288968 ldr r6, [sp, #0x2c] */
/* @0x28896c mov r8, r3 */
/* @0x288970 b 0x288aa4 <spPathConstraint_apply+0x31c> */
/* @0x288974 vldr s16, [r5, #-12] */
/* @0x288978 vcvt.f64.f32 d5, s24 */
/* @0x28897c vcvt.f64.f32 d6, s23 */
/* @0x288980 vmov r0, r1, d5 */
/* @0x288984 vmov r2, r3, d6 */
/* @0x288988 bl 0xb6c70 <atan2@plt> */
/* @0x28898c ldr r2, [sp, #0x24] */
/* @0x288990 cmp r2, #0 */
/* @0x288994 vmov d5, r0, r1 */
/* @0x288998 movw r1, #0xfa35 */
/* @0x28899c movt r1, #0x3c8e */
/* @0x2889a0 vcvt.f32.f64 s15, d5 */
/* @0x2889a4 vldr s10, [sp, #28] */
/* @0x2889a8 vmov s11, r1 */
/* @0x2889ac vmls.f32 s15, s10, s11 */
/* @0x2889b0 vsub.f32 s16, s16, s15 */
/* @0x2889b4 beq 0x288a04 <spPathConstraint_apply+0x27c> */
/* @0x2889b8 vcvt.f64.f32 d9, s16 */
/* @0x2889bc vmov r0, r1, d9 */
/* @0x2889c0 bl 0xb67e4 <cos@plt> */
/* @0x2889c4 vmov d6, r0, r1 */
/* @0x2889c8 vmov r0, r1, d9 */
/* @0x2889cc vcvt.f32.f64 s31, d6 */
/* @0x2889d0 bl 0xb67d8 <sin@plt> */
/* @0x2889d4 ldr r3, [r4] */
/* @0x2889d8 vldr s13, [r3, #12] */
/* @0x2889dc vmul.f32 s14, s31, s24 */
/* @0x2889e0 vmov d5, r0, r1 */
/* @0x2889e4 vcvt.f32.f64 s12, d5 */
/* @0x2889e8 vmul.f32 s15, s12, s24 */
/* @0x2889ec vmla.f32 s14, s12, s23 */
/* @0x2889f0 vnmls.f32 s15, s31, s23 */
/* @0x2889f4 vnmls.f32 s30, s14, s13 */
/* @0x2889f8 vnmls.f32 s17, s15, s13 */
/* @0x2889fc vmla.f32 s21, s30, s25 */
/* @0x288a00 vmla.f32 s20, s17, s25 */
/* @0x288a04 movw r1, #0xfdb */
/* @0x288a08 movt r1, #0x4049 */
/* @0x288a0c vmov s10, r1 */
/* @0x288a10 movw r1, #0xfdb */
/* @0x288a14 vcmpe.f32 s16, s10 */
/* @0x288a18 vmrs APSR_nzcv, fpscr */
/* @0x288a1c ble 0x288b44 <spPathConstraint_apply+0x3bc> */
/* @0x288a20 movt r1, #0x40c9 */
/* @0x288a24 vmov s10, r1 */
/* @0x288a28 vsub.f32 s16, s16, s10 */
/* @0x288a2c vmul.f32 s16, s16, s25 */
/* @0x288a30 vcvt.f64.f32 d8, s16 */
/* @0x288a34 vmov r0, r1, d8 */
/* @0x288a38 bl 0xb67e4 <cos@plt> */
/* @0x288a3c vmov d6, r0, r1 */
/* @0x288a40 vmov r0, r1, d8 */
/* @0x288a44 vcvt.f32.f64 s18, d6 */
/* @0x288a48 bl 0xb67d8 <sin@plt> */
/* @0x288a4c vmul.f32 s13, s18, s24 */
/* @0x288a50 vmul.f32 s14, s18, s27 */
/* @0x288a54 vmov d5, r0, r1 */
/* @0x288a58 vcvt.f32.f64 s15, d5 */
/* @0x288a5c vmul.f32 s24, s15, s24 */
/* @0x288a60 vmul.f32 s27, s15, s27 */
/* @0x288a64 vmla.f32 s13, s15, s23 */
/* @0x288a68 vnmls.f32 s24, s18, s23 */
/* @0x288a6c vstr s13, [r4, #64] */
/* @0x288a70 vnmls.f32 s27, s18, s26 */
/* @0x288a74 vstr s24, [r4, #52] */
/* @0x288a78 vmla.f32 s14, s15, s26 */
/* @0x288a7c vstr s27, [r4, #56] */
/* @0x288a80 vstr s14, [r4, #68] */
/* @0x288a84 add r8, r8, #1 */
/* @0x288a88 add r5, r5, #12 */
/* @0x288a8c cmp r8, r11 */
/* @0x288a90 add r7, r7, #4 */
/* @0x288a94 add r6, r6, #4 */
/* @0x288a98 beq 0x288814 <spPathConstraint_apply+0x8c> */
/* @0x288a9c vmov.f32 s30, s21 */
/* @0x288aa0 vmov.f32 s17, s20 */
/* @0x288aa4 ldr r4, [r9, #0x4]! */
/* @0x288aa8 vldr s14, [r4, #60] */
/* @0x288aac vldr s15, [r4, #72] */
/* @0x288ab0 ldr r1, [sp, #0x18] */
/* @0x288ab4 vsub.f32 s12, s17, s28 */
/* @0x288ab8 cmp r1, #0 */
/* @0x288abc vsub.f32 s13, s30, s29 */
/* @0x288ac0 vsub.f32 s12, s12, s14 */
/* @0x288ac4 vsub.f32 s13, s13, s15 */
/* @0x288ac8 vmla.f32 s14, s12, s22 */
/* @0x288acc vmla.f32 s15, s13, s22 */
/* @0x288ad0 vstr s14, [r4, #60] */
/* @0x288ad4 vstr s15, [r4, #72] */
/* @0x288ad8 vldr s20, [r5, #-8] */
/* @0x288adc vldr s21, [r5, #-4] */
/* @0x288ae0 vsub.f32 s17, s20, s17 */
/* @0x288ae4 vsub.f32 s30, s21, s30 */
/* @0x288ae8 beq 0x288afc <spPathConstraint_apply+0x374> */
/* @0x288aec vldr s16, [r6] */
/* @0x288af0 vcmp.f32 s16, #0 */
/* @0x288af4 vmrs APSR_nzcv, fpscr */
/* @0x288af8 bne 0x288b68 <spPathConstraint_apply+0x3e0> */
/* @0x288afc cmp r10, #0 */
/* @0x288b00 beq 0x288a84 <spPathConstraint_apply+0x2fc> */
/* @0x288b04 ldr r2, [sp, #0x14] */
/* @0x288b08 vldr s23, [r4, #52] */
/* @0x288b0c vldr s26, [r4, #56] */
/* @0x288b10 vldr s24, [r4, #64] */
/* @0x288b14 cmp r2, #0 */
/* @0x288b18 vldr s27, [r4, #68] */
/* @0x288b1c bne 0x288974 <spPathConstraint_apply+0x1ec> */
/* @0x288b20 vldr s15, [r7] */
/* @0x288b24 vcmp.f32 s15, #0 */
/* @0x288b28 vmrs APSR_nzcv, fpscr */
/* @0x288b2c bne 0x288bbc <spPathConstraint_apply+0x434> */
/* @0x288b30 vldr s16, [r5] */
/* @0x288b34 b 0x288978 <spPathConstraint_apply+0x1f0> */
/* @0x288b38 ldr r3, [r0, #0x24] */
/* @0x288b3c str r3, [sp, #0x28] */
/* @0x288b40 b 0x28886c <spPathConstraint_apply+0xe4> */
/* @0x288b44 movt r1, #0xc049 */
/* @0x288b48 vmov s10, r1 */
/* @0x288b4c vcmpe.f32 s16, s10 */
/* @0x288b50 vmrs APSR_nzcv, fpscr */
/* @0x288b54 movwmi r1, #0xfdb */
/* @0x288b58 movtmi r1, #0x40c9 */
/* @0x288b5c vmovmi s10, r1 */
/* @0x288b60 vaddmi.f32 s16, s16, s10 */
/* @0x288b64 b 0x288a2c <spPathConstraint_apply+0x2a4> */
/* @0x288b68 vmul.f32 s12, s30, s30 */
/* @0x288b6c vmla.f32 s12, s17, s17 */
/* @0x288b70 vcvt.f64.f32 d6, s12 */
/* @0x288b74 vsqrt.f64 d7, d6 */
/* @0x288b78 vcmp.f64 d7, d7 */
/* @0x288b7c vmrs APSR_nzcv, fpscr */
/* @0x288b80 bne 0x288e30 <spPathConstraint_apply+0x6a8> */
/* @0x288b84 vcvt.f32.f64 s14, d7 */
/* @0x288b88 mov r2, #1065353216 */
/* @0x288b8c vmov s10, r2 */
/* @0x288b90 vldr s12, [r4, #52] */
/* @0x288b94 vmov s15, r2 */
/* @0x288b98 vldr s13, [r4, #64] */
/* @0x288b9c vdiv.f32 s16, s14, s16 */
/* @0x288ba0 vsub.f32 s16, s16, s10 */
/* @0x288ba4 vmla.f32 s15, s16, s25 */
/* @0x288ba8 vmul.f32 s14, s12, s15 */
/* @0x288bac vmul.f32 s15, s13, s15 */
/* @0x288bb0 vstr s14, [r4, #52] */
/* @0x288bb4 vstr s15, [r4, #64] */
/* @0x288bb8 b 0x288afc <spPathConstraint_apply+0x374> */
/* @0x288bbc vcvt.f64.f32 d5, s30 */
/* @0x288bc0 vcvt.f64.f32 d6, s17 */
/* @0x288bc4 vmov r0, r1, d5 */
/* @0x288bc8 vmov r2, r3, d6 */
/* @0x288bcc bl 0xb6c70 <atan2@plt> */
/* @0x288bd0 vmov d7, r0, r1 */
/* @0x288bd4 vcvt.f32.f64 s16, d7 */
/* @0x288bd8 b 0x288978 <spPathConstraint_apply+0x1f0> */
/* @0x288bdc ldr r1, [sp, #0x18] */
/* @0x288be0 cmp r1, #0 */
/* @0x288be4 bne 0x288c74 <spPathConstraint_apply+0x4ec> */
/* @0x288be8 cmp r7, #1 */
/* @0x288bec ldrle r1, [sp, #0x18] */
/* @0x288bf0 strle r1, [sp, #0x2c] */
/* @0x288bf4 ble 0x2888c8 <spPathConstraint_apply+0x140> */
/* @0x288bf8 ldr r2, [sp, #0x28] */
/* @0x288bfc cmp r9, #0 */
/* @0x288c00 ldr r1, [sp, #0x20] */
/* @0x288c04 add r11, r2, #4 */
/* @0x288c08 ldr r9, [sp, #0x18] */
/* @0x288c0c sub r3, r1, #4 */
/* @0x288c10 sub r2, r7, #1 */
/* @0x288c14 bne 0x288d54 <spPathConstraint_apply+0x5cc> */
/* @0x288c18 ldr r1, [r3, #0x4]! */
/* @0x288c1c vldr s14, [r1, #52] */
/* @0x288c20 vldr s12, [r1, #64] */
/* @0x288c24 add r9, r9, #1 */
/* @0x288c28 ldr r1, [r1] */
/* @0x288c2c vldr s15, [r1, #12] */
/* @0x288c30 vmul.f32 s12, s15, s12 */
/* @0x288c34 vmul.f32 s15, s15, s14 */
/* @0x288c38 vmul.f32 s12, s12, s12 */
/* @0x288c3c vmla.f32 s12, s15, s15 */
/* @0x288c40 vcvt.f64.f32 d6, s12 */
/* @0x288c44 vsqrt.f64 d7, d6 */
/* @0x288c48 vcmp.f64 d7, d7 */
/* @0x288c4c vmrs APSR_nzcv, fpscr */
/* @0x288c50 bne 0x288e68 <spPathConstraint_apply+0x6e0> */
/* @0x288c54 cmp r9, r2 */
/* @0x288c58 vstmia r11!, {s16} */
/* @0x288c5c bne 0x288c18 <spPathConstraint_apply+0x490> */
/* @0x288c60 b 0x2888c0 <spPathConstraint_apply+0x138> */
/* @0x288c64 andeq r0, r0, r0 */
/* @0x288c68 andeq pc, r12, r4, lsr #2 */
/* @0x288c6c ldrdeq lr, pc, [r12], -r0 */
/* @0x288c70 andeq r0, r0, r0 */
/* @0x288c74 ldr r3, [r4, #0x40] */
/* @0x288c78 cmp r3, r8 */
/* @0x288c7c beq 0x288d48 <spPathConstraint_apply+0x5c0> */
/* @0x288c80 ldr r0, [r4, #0x44] */
/* @0x288c84 cmp r0, #0 */
/* @0x288c88 beq 0x288c98 <spPathConstraint_apply+0x510> */
/* @0x288c8c str r12, [sp, #0x8] */
/* @0x288c90 bl 0x285c80 <_free> */
/* @0x288c94 ldr r12, [sp, #0x8] */
/* @0x288c98 ldr r1, [pc, #-0x34] */
/* @0x288c9c lsl r0, r8, #2 */
/* @0x288ca0 mov r2, #111 */
/* @0x288ca4 str r12, [sp, #0x8] */
/* @0x288ca8 add r1, pc, r1 */
/* @0x288cac bl 0x285c10 <_malloc> */
/* @0x288cb0 ldr r12, [sp, #0x8] */
/* @0x288cb4 str r8, [r4, #0x40] */
/* @0x288cb8 str r0, [sp, #0x2c] */
/* @0x288cbc str r0, [r4, #0x44] */
/* @0x288cc0 cmp r7, #1 */
/* @0x288cc4 ble 0x2888c8 <spPathConstraint_apply+0x140> */
/* @0x288cc8 ldr r3, [sp, #0x20] */
/* @0x288ccc cmp r9, #0 */
/* @0x288cd0 ldr r1, [sp, #0x28] */
/* @0x288cd4 sub r2, r3, #4 */
/* @0x288cd8 ldr r11, [sp, #0x2c] */
/* @0x288cdc add r3, r1, #4 */
/* @0x288ce0 sub r1, r7, #1 */
/* @0x288ce4 bne 0x288dbc <spPathConstraint_apply+0x634> */
/* @0x288ce8 str r12, [sp, #0x1c] */
/* @0x288cec mov r12, r1 */
/* @0x288cf0 ldr r1, [r2, #0x4]! */
/* @0x288cf4 vldr s14, [r1, #52] */
/* @0x288cf8 vldr s12, [r1, #64] */
/* @0x288cfc add r9, r9, #1 */
/* @0x288d00 ldr r1, [r1] */
/* @0x288d04 vldr s15, [r1, #12] */
/* @0x288d08 vmul.f32 s12, s15, s12 */
/* @0x288d0c vmul.f32 s15, s15, s14 */
/* @0x288d10 vmul.f32 s12, s12, s12 */
/* @0x288d14 vmla.f32 s12, s15, s15 */
/* @0x288d18 vcvt.f64.f32 d6, s12 */
/* @0x288d1c vsqrt.f64 d7, d6 */
/* @0x288d20 vcmp.f64 d7, d7 */
/* @0x288d24 vmrs APSR_nzcv, fpscr */
/* @0x288d28 bne 0x288e8c <spPathConstraint_apply+0x704> */
/* @0x288d2c vcvt.f32.f64 s14, d7 */
/* @0x288d30 cmp r9, r12 */
/* @0x288d34 vstmia r11!, {s14} */
/* @0x288d38 vstmia r3!, {s16} */
/* @0x288d3c bne 0x288cf0 <spPathConstraint_apply+0x568> */
/* @0x288d40 ldr r12, [sp, #0x1c] */
/* @0x288d44 b 0x2888c8 <spPathConstraint_apply+0x140> */
/* @0x288d48 ldr r2, [r4, #0x44] */
/* @0x288d4c str r2, [sp, #0x2c] */
/* @0x288d50 b 0x288cc0 <spPathConstraint_apply+0x538> */
/* @0x288d54 ldr r1, [r3, #0x4]! */
/* @0x288d58 vldr s14, [r1, #52] */
/* @0x288d5c vldr s12, [r1, #64] */
/* @0x288d60 add r9, r9, #1 */
/* @0x288d64 ldr r1, [r1] */
/* @0x288d68 vldr s15, [r1, #12] */
/* @0x288d6c vmul.f32 s12, s15, s12 */
/* @0x288d70 vmul.f32 s15, s15, s14 */
/* @0x288d74 vmul.f32 s12, s12, s12 */
/* @0x288d78 vmla.f32 s12, s15, s15 */
/* @0x288d7c vcvt.f64.f32 d6, s12 */
/* @0x288d80 vsqrt.f64 d7, d6 */
/* @0x288d84 vcmp.f64 d7, d7 */
/* @0x288d88 vmrs APSR_nzcv, fpscr */
/* @0x288d8c bne 0x288e40 <spPathConstraint_apply+0x6b8> */
/* @0x288d90 vcvt.f32.f64 s14, d7 */
/* @0x288d94 vadd.f32 s14, s14, s16 */
/* @0x288d98 vcmpe.f32 s14, #0 */
/* @0x288d9c vmrs APSR_nzcv, fpscr */
/* @0x288da0 vmovmi.f32 s14, s17 */
/* @0x288da4 cmp r9, r2 */
/* @0x288da8 vstmia r11!, {s14} */
/* @0x288dac bne 0x288d54 <spPathConstraint_apply+0x5cc> */
/* @0x288db0 mov r1, #0 */
/* @0x288db4 str r1, [sp, #0x2c] */
/* @0x288db8 b 0x2888c8 <spPathConstraint_apply+0x140> */
/* @0x288dbc str r12, [sp, #0x1c] */
/* @0x288dc0 mov r9, #0 */
/* @0x288dc4 mov r12, r1 */
/* @0x288dc8 vldr s17, [pc, #-352] */
/* @0x288dcc ldr r1, [r2, #0x4]! */
/* @0x288dd0 vldr s14, [r1, #52] */
/* @0x288dd4 vldr s12, [r1, #64] */
/* @0x288dd8 add r9, r9, #1 */
/* @0x288ddc ldr r1, [r1] */
/* @0x288de0 vldr s15, [r1, #12] */
/* @0x288de4 vmul.f32 s12, s15, s12 */
/* @0x288de8 vmul.f32 s15, s15, s14 */
/* @0x288dec vmul.f32 s12, s12, s12 */
/* @0x288df0 vmla.f32 s12, s15, s15 */
/* @0x288df4 vcvt.f64.f32 d6, s12 */
/* @0x288df8 vsqrt.f64 d7, d6 */
/* @0x288dfc vcmp.f64 d7, d7 */
/* @0x288e00 vmrs APSR_nzcv, fpscr */
/* @0x288e04 bne 0x288eb4 <spPathConstraint_apply+0x72c> */
/* @0x288e08 vcvt.f32.f64 s14, d7 */
/* @0x288e0c vadd.f32 s15, s14, s16 */
/* @0x288e10 vstmia r11!, {s14} */
/* @0x288e14 vcmpe.f32 s15, #0 */
/* @0x288e18 vmrs APSR_nzcv, fpscr */
/* @0x288e1c vmovmi.f32 s15, s17 */
/* @0x288e20 cmp r9, r12 */
/* @0x288e24 vstmia r3!, {s15} */
/* @0x288e28 bne 0x288dcc <spPathConstraint_apply+0x644> */
/* @0x288e2c b 0x288d40 <spPathConstraint_apply+0x5b8> */
/* @0x288e30 vmov r0, r1, d6 */
/* @0x288e34 bl 0xb66f4 <sqrt@plt> */
/* @0x288e38 vmov d7, r0, r1 */
/* @0x288e3c b 0x288b84 <spPathConstraint_apply+0x3fc> */
/* @0x288e40 vmov r0, r1, d6 */
/* @0x288e44 str r2, [sp, #0x10] */
/* @0x288e48 str r3, [sp, #0xc] */
/* @0x288e4c str r12, [sp, #0x8] */
/* @0x288e50 bl 0xb66f4 <sqrt@plt> */
/* @0x288e54 ldr r12, [sp, #0x8] */
/* @0x288e58 ldr r3, [sp, #0xc] */
/* @0x288e5c ldr r2, [sp, #0x10] */
/* @0x288e60 vmov d7, r0, r1 */
/* @0x288e64 b 0x288d90 <spPathConstraint_apply+0x608> */
/* @0x288e68 vmov r0, r1, d6 */
/* @0x288e6c str r2, [sp, #0x10] */
/* @0x288e70 str r3, [sp, #0xc] */
/* @0x288e74 str r12, [sp, #0x8] */
/* @0x288e78 bl 0xb66f4 <sqrt@plt> */
/* @0x288e7c ldr r12, [sp, #0x8] */
/* @0x288e80 ldr r3, [sp, #0xc] */
/* @0x288e84 ldr r2, [sp, #0x10] */
/* @0x288e88 b 0x288c54 <spPathConstraint_apply+0x4cc> */
/* @0x288e8c vmov r0, r1, d6 */
/* @0x288e90 str r2, [sp, #0x10] */
/* @0x288e94 str r3, [sp, #0xc] */
/* @0x288e98 str r12, [sp, #0x8] */
/* @0x288e9c bl 0xb66f4 <sqrt@plt> */
/* @0x288ea0 ldr r12, [sp, #0x8] */
/* @0x288ea4 ldr r3, [sp, #0xc] */
/* @0x288ea8 ldr r2, [sp, #0x10] */
/* @0x288eac vmov d7, r0, r1 */
/* @0x288eb0 b 0x288d2c <spPathConstraint_apply+0x5a4> */
/* @0x288eb4 vmov r0, r1, d6 */
/* @0x288eb8 str r2, [sp, #0x10] */
/* @0x288ebc str r3, [sp, #0xc] */
/* @0x288ec0 str r12, [sp, #0x8] */
/* @0x288ec4 bl 0xb66f4 <sqrt@plt> */
/* @0x288ec8 ldr r12, [sp, #0x8] */
/* @0x288ecc ldr r3, [sp, #0xc] */
/* @0x288ed0 ldr r2, [sp, #0x10] */
/* @0x288ed4 vmov d7, r0, r1 */
/* @0x288ed8 b 0x288e08 <spPathConstraint_apply+0x680> */

/* ── FUNC 0x288edc · spPathConstraintData_create · size=88 · insn=22 */
/* @0x288edc push {r4, r5, r6, lr} */
/* @0x288ee0 mov r3, #36 */
/* @0x288ee4 ldr r6, [pc, #0x44] */
/* @0x288ee8 mov r5, r0 */
/* @0x288eec mov r1, #48 */
/* @0x288ef0 mov r0, #1 */
/* @0x288ef4 add r6, pc, r6 */
/* @0x288ef8 mov r2, r6 */
/* @0x288efc bl 0x285c4c <_calloc> */
/* @0x288f00 mov r4, r0 */
/* @0x288f04 mov r0, r5 */
/* @0x288f08 bl 0xb6538 <strlen@plt> */
/* @0x288f0c mov r1, r6 */
/* @0x288f10 mov r2, #37 */
/* @0x288f14 add r0, r0, #1 */
/* @0x288f18 bl 0x285c10 <_malloc> */
/* @0x288f1c mov r1, r5 */
/* @0x288f20 str r0, [r4] */
/* @0x288f24 bl 0xb65a4 <strcpy@plt> */
/* @0x288f28 mov r0, r4 */
/* @0x288f2c pop {r4, r5, r6, pc} */
/* @0x288f30 andeq lr, r12, r0, asr #21 */

/* ── FUNC 0x288f34 · spPathConstraintData_dispose · size=36 · insn=9 */
/* @0x288f34 push {r4, lr} */
/* @0x288f38 mov r4, r0 */
/* @0x288f3c ldr r0, [r0] */
/* @0x288f40 bl 0x285c80 <_free> */
/* @0x288f44 ldr r0, [r4, #0x8] */
/* @0x288f48 bl 0x285c80 <_free> */
/* @0x288f4c mov r0, r4 */
/* @0x288f50 pop {r4, lr} */
/* @0x288f54 b 0x285c80 <_free> */

/* ── FUNC 0x288f58 · _spRegionAttachment_dispose · size=32 · insn=8 */
/* @0x288f58 push {r4, lr} */
/* @0x288f5c mov r4, r0 */
/* @0x288f60 bl 0x284c84 <_spAttachment_deinit> */
/* @0x288f64 ldr r0, [r4, #0x10] */
/* @0x288f68 bl 0x285c80 <_free> */
/* @0x288f6c mov r0, r4 */
/* @0x288f70 pop {r4, lr} */
/* @0x288f74 b 0x285c80 <_free> */

/* ── FUNC 0x288f78 · spRegionAttachment_create · size=100 · insn=25 */
/* @0x288f78 ldr r2, [pc, #0x54] */
/* @0x288f7c mov r1, #156 */
/* @0x288f80 push {r3, r4, r5, lr} */
/* @0x288f84 add r2, pc, r2 */
/* @0x288f88 mov r5, r0 */
/* @0x288f8c mov r3, #43 */
/* @0x288f90 mov r0, #1 */
/* @0x288f94 bl 0x285c4c <_calloc> */
/* @0x288f98 ldr r3, [pc, #0x38] */
/* @0x288f9c mov r12, #1065353216 */
/* @0x288fa0 mov r1, r5 */
/* @0x288fa4 mov r2, #0 */
/* @0x288fa8 ldr r3, [pc, r3] */
/* @0x288fac mov r4, r0 */
/* @0x288fb0 str r12, [r0, #0x1c] */
/* @0x288fb4 str r12, [r0, #0x20] */
/* @0x288fb8 str r12, [r0, #0x30] */
/* @0x288fbc str r12, [r0, #0x34] */
/* @0x288fc0 str r12, [r0, #0x38] */
/* @0x288fc4 str r12, [r0, #0x3c] */
/* @0x288fc8 bl 0x284c18 <_spAttachment_init> */
/* @0x288fcc mov r0, r4 */
/* @0x288fd0 pop {r3, r4, r5, pc} */
/* @0x288fd4 andeq lr, r12, r0, ror r10 */
/* @0x288fd8 andseq r8, r6, r0, ror #18 */

/* ── FUNC 0x288fdc · spRegionAttachment_setUVs · size=100 · insn=25 */
/* @0x288fdc str r4, [sp, #-0x4]! */
/* @0x288fe0 ldr r4, [sp, #0x8] */
/* @0x288fe4 ldr r12, [sp, #0x4] */
/* @0x288fe8 cmp r4, #0 */
/* @0x288fec bne 0x289018 <spRegionAttachment_setUVs+0x3c> */
/* @0x288ff0 str r1, [r0, #0x7c] */
/* @0x288ff4 str r12, [r0, #0x80] */
/* @0x288ff8 str r1, [r0, #0x84] */
/* @0x288ffc str r2, [r0, #0x88] */
/* @0x289000 str r3, [r0, #0x8c] */
/* @0x289004 str r2, [r0, #0x90] */
/* @0x289008 str r3, [r0, #0x94] */
/* @0x28900c str r12, [r0, #0x98] */
/* @0x289010 ldr r4, [sp], #4 */
/* @0x289014 bx lr */
/* @0x289018 str r1, [r0, #0x84] */
/* @0x28901c str r12, [r0, #0x88] */
/* @0x289020 str r1, [r0, #0x8c] */
/* @0x289024 str r2, [r0, #0x90] */
/* @0x289028 str r3, [r0, #0x94] */
/* @0x28902c str r2, [r0, #0x98] */
/* @0x289030 str r3, [r0, #0x7c] */
/* @0x289034 str r12, [r0, #0x80] */
/* @0x289038 ldr r4, [sp], #4 */
/* @0x28903c bx lr */

/* ── FUNC 0x289040 · spRegionAttachment_updateOffset · size=308 · insn=77 */
/* @0x289040 vldr s7, [r0, #84] */
/* @0x289044 vldr s11, [r0, #88] */
/* @0x289048 vcvt.f32.s32 s14, s7 */
/* @0x28904c vldr s10, [r0, #44] */
/* @0x289050 vldr s9, [r0, #40] */
/* @0x289054 vldr s12, [r0, #28] */
/* @0x289058 vldr s13, [r0, #32] */
/* @0x28905c vldr s7, [r0, #68] */
/* @0x289060 push {r4, lr} */
/* @0x289064 vpush {d8, d9, d10, d11} */
/* @0x289068 vldr s8, [pc, #256] */
/* @0x28906c vldr s16, [r0, #36] */
/* @0x289070 mov r4, r0 */
/* @0x289074 vcvt.f32.s32 s15, s11 */
/* @0x289078 vdiv.f32 s14, s9, s14 */
/* @0x28907c vdiv.f32 s15, s10, s15 */
/* @0x289080 vmul.f32 s14, s14, s12 */
/* @0x289084 vmul.f32 s15, s15, s13 */
/* @0x289088 vmov.f32 s11, #5.000000e-01 */
/* @0x28908c vcvt.f32.s32 s19, s7 */
/* @0x289090 vldr s7, [r0, #72] */
/* @0x289094 vcvt.f32.s32 s18, s7 */
/* @0x289098 vmul.f32 s19, s19, s14 */
/* @0x28909c vnmul.f32 s9, s9, s11 */
/* @0x2890a0 vmul.f32 s18, s18, s15 */
/* @0x2890a4 vnmul.f32 s11, s10, s11 */
/* @0x2890a8 vmla.f32 s19, s12, s9 */
/* @0x2890ac vldr s9, [r4, #80] */
/* @0x2890b0 vmla.f32 s18, s13, s11 */
/* @0x2890b4 vmul.f32 s16, s16, s8 */
/* @0x2890b8 vldr s8, [r0, #76] */
/* @0x2890bc vcvt.f64.f32 d8, s16 */
/* @0x2890c0 vcvt.f32.s32 s12, s8 */
/* @0x2890c4 vmov r0, r1, d8 */
/* @0x2890c8 vcvt.f32.s32 s13, s9 */
/* @0x2890cc vmov.f32 s22, s19 */
/* @0x2890d0 vmov.f32 s21, s18 */
/* @0x2890d4 vmla.f32 s22, s12, s14 */
/* @0x2890d8 vmla.f32 s21, s13, s15 */
/* @0x2890dc bl 0xb67e4 <cos@plt> */
/* @0x2890e0 vmov d7, r0, r1 */
/* @0x2890e4 vmov r0, r1, d8 */
/* @0x2890e8 vcvt.f32.f64 s20, d7 */
/* @0x2890ec bl 0xb67d8 <sin@plt> */
/* @0x2890f0 vldr s12, [r4, #20] */
/* @0x2890f4 vldr s13, [r4, #24] */
/* @0x2890f8 vmov.f32 s11, s12 */
/* @0x2890fc vmla.f32 s12, s22, s20 */
/* @0x289100 vmla.f32 s11, s19, s20 */
/* @0x289104 vmov d4, r0, r1 */
/* @0x289108 vcvt.f32.f64 s15, d4 */
/* @0x28910c vmov.f32 s14, s13 */
/* @0x289110 vmul.f32 s22, s22, s15 */
/* @0x289114 vmla.f32 s14, s18, s20 */
/* @0x289118 vmul.f32 s19, s19, s15 */
/* @0x28911c vmul.f32 s18, s18, s15 */
/* @0x289120 vmul.f32 s15, s21, s15 */
/* @0x289124 vmla.f32 s13, s21, s20 */
/* @0x289128 vsub.f32 s10, s11, s18 */
/* @0x28912c vsub.f32 s11, s11, s15 */
/* @0x289130 vstr s10, [r4, #92] */
/* @0x289134 vsub.f32 s15, s12, s15 */
/* @0x289138 vstr s11, [r4, #100] */
/* @0x28913c vsub.f32 s18, s12, s18 */
/* @0x289140 vstr s15, [r4, #108] */
/* @0x289144 vadd.f32 s15, s14, s19 */
/* @0x289148 vstr s18, [r4, #116] */
/* @0x28914c vadd.f32 s19, s13, s19 */
/* @0x289150 vstr s15, [r4, #96] */
/* @0x289154 vadd.f32 s13, s13, s22 */
/* @0x289158 vstr s19, [r4, #104] */
/* @0x28915c vadd.f32 s22, s14, s22 */
/* @0x289160 vstr s13, [r4, #112] */
/* @0x289164 vstr s22, [r4, #120] */
/* @0x289168 vpop {d8, d9, d10, d11} */
/* @0x28916c pop {r4, pc} */
/* @0x289170 vstmialo lr, {s30, s31} */

/* ── FUNC 0x289174 · spRegionAttachment_computeWorldVertices · size=288 · insn=72 */
/* @0x289174 vldr s15, [r1, #56] */
/* @0x289178 vldr s13, [r0, #96] */
/* @0x28917c vmul.f32 s13, s13, s15 */
/* @0x289180 vldr s10, [r1, #52] */
/* @0x289184 vldr s9, [r0, #92] */
/* @0x289188 ldr r3, [r1, #0x4] */
/* @0x28918c vldr s14, [r1, #60] */
/* @0x289190 vldr s11, [r3, #88] */
/* @0x289194 vldr s12, [r3, #92] */
/* @0x289198 vldr s15, [r1, #72] */
/* @0x28919c vmla.f32 s13, s9, s10 */
/* @0x2891a0 vadd.f32 s14, s11, s14 */
/* @0x2891a4 vadd.f32 s13, s13, s14 */
/* @0x2891a8 vstr s13, [r2] */
/* @0x2891ac vldr s11, [r0, #96] */
/* @0x2891b0 vldr s13, [r1, #68] */
/* @0x2891b4 vmul.f32 s13, s11, s13 */
/* @0x2891b8 vldr s10, [r0, #92] */
/* @0x2891bc vldr s11, [r1, #64] */
/* @0x2891c0 vmla.f32 s13, s10, s11 */
/* @0x2891c4 vadd.f32 s15, s12, s15 */
/* @0x2891c8 vadd.f32 s13, s13, s15 */
/* @0x2891cc vstr s13, [r2, #4] */
/* @0x2891d0 vldr s12, [r0, #104] */
/* @0x2891d4 vldr s13, [r1, #56] */
/* @0x2891d8 vmul.f32 s13, s12, s13 */
/* @0x2891dc vldr s11, [r0, #100] */
/* @0x2891e0 vldr s12, [r1, #52] */
/* @0x2891e4 vmla.f32 s13, s11, s12 */
/* @0x2891e8 vadd.f32 s13, s13, s14 */
/* @0x2891ec vstr s13, [r2, #8] */
/* @0x2891f0 vldr s12, [r0, #104] */
/* @0x2891f4 vldr s13, [r1, #68] */
/* @0x2891f8 vmul.f32 s13, s12, s13 */
/* @0x2891fc vldr s11, [r0, #100] */
/* @0x289200 vldr s12, [r1, #64] */
/* @0x289204 vmla.f32 s13, s11, s12 */
/* @0x289208 vadd.f32 s13, s13, s15 */
/* @0x28920c vstr s13, [r2, #12] */
/* @0x289210 vldr s12, [r0, #112] */
/* @0x289214 vldr s13, [r1, #56] */
/* @0x289218 vmul.f32 s13, s12, s13 */
/* @0x28921c vldr s11, [r0, #108] */
/* @0x289220 vldr s12, [r1, #52] */
/* @0x289224 vmla.f32 s13, s11, s12 */
/* @0x289228 vadd.f32 s13, s13, s14 */
/* @0x28922c vstr s13, [r2, #16] */
/* @0x289230 vldr s12, [r0, #112] */
/* @0x289234 vldr s13, [r1, #68] */
/* @0x289238 vmul.f32 s13, s12, s13 */
/* @0x28923c vldr s11, [r0, #108] */
/* @0x289240 vldr s12, [r1, #64] */
/* @0x289244 vmla.f32 s13, s11, s12 */
/* @0x289248 vadd.f32 s13, s13, s15 */
/* @0x28924c vstr s13, [r2, #20] */
/* @0x289250 vldr s12, [r0, #120] */
/* @0x289254 vldr s13, [r1, #56] */
/* @0x289258 vmul.f32 s13, s12, s13 */
/* @0x28925c vldr s11, [r0, #116] */
/* @0x289260 vldr s12, [r1, #52] */
/* @0x289264 vmla.f32 s13, s11, s12 */
/* @0x289268 vadd.f32 s14, s13, s14 */
/* @0x28926c vstr s14, [r2, #24] */
/* @0x289270 vldr s13, [r0, #120] */
/* @0x289274 vldr s14, [r1, #68] */
/* @0x289278 vmul.f32 s14, s13, s14 */
/* @0x28927c vldr s12, [r0, #116] */
/* @0x289280 vldr s13, [r1, #64] */
/* @0x289284 vmla.f32 s14, s12, s13 */
/* @0x289288 vadd.f32 s15, s14, s15 */
/* @0x28928c vstr s15, [r2, #28] */
/* @0x289290 bx lr */

/* ── FUNC 0x289294 · anon_289294 · size=564 · insn=142 */
/* @0x289294 push {r4, r5, r6, r7, r8, lr} */
/* @0x289298 subs r7, r1, #0 */
/* @0x28929c pople {r4, r5, r6, r7, r8, pc} */
/* @0x2892a0 mov r5, #0 */
/* @0x2892a4 sub r6, r0, #4 */
/* @0x2892a8 mov r8, r5 */
/* @0x2892ac b 0x2892bc <spRegionAttachment_computeWorldVertices+0x148> */
/* @0x2892b0 cmp r5, r7 */
/* @0x2892b4 str r8, [r4, #0x54] */
/* @0x2892b8 beq 0x2892e8 <spRegionAttachment_computeWorldVertices+0x174> */
/* @0x2892bc ldr r4, [r6, #0x4]! */
/* @0x2892c0 add r5, r5, #1 */
/* @0x2892c4 ldr r3, [r4, #0x54] */
/* @0x2892c8 cmp r3, #0 */
/* @0x2892cc beq 0x2892b0 <spRegionAttachment_computeWorldVertices+0x13c> */
/* @0x2892d0 ldr r0, [r4, #0x10] */
/* @0x2892d4 ldr r1, [r4, #0xc] */
/* @0x2892d8 bl 0x289294 <spRegionAttachment_computeWorldVertices+0x120> */
/* @0x2892dc cmp r5, r7 */
/* @0x2892e0 str r8, [r4, #0x54] */
/* @0x2892e4 bne 0x2892bc <spRegionAttachment_computeWorldVertices+0x148> */
/* @0x2892e8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2892ec push {r4, r5, lr} */
/* @0x2892f0 mov r5, r1 */
/* @0x2892f4 ldr r3, [r0, #0x60] */
/* @0x2892f8 sub sp, sp, #12 */
/* @0x2892fc ldr r1, [r0, #0x64] */
/* @0x289300 mov r4, r0 */
/* @0x289304 cmp r3, r1 */
/* @0x289308 beq 0x28932c <spRegionAttachment_computeWorldVertices+0x1b8> */
/* @0x28930c ldr r12, [r0, #0x68] */
/* @0x289310 add r1, r12, r3, lsl #3 */
/* @0x289314 str r5, [r12, r3, lsl #3] */
/* @0x289318 add r3, r3, #1 */
/* @0x28931c str r2, [r1, #0x4] */
/* @0x289320 str r3, [r4, #0x60] */
/* @0x289324 add sp, sp, #12 */
/* @0x289328 pop {r4, r5, pc} */
/* @0x28932c lsl r0, r3, #1 */
/* @0x289330 lsl r1, r3, #4 */
/* @0x289334 str r0, [r4, #0x64] */
/* @0x289338 ldr r0, [r4, #0x68] */
/* @0x28933c str r2, [sp, #0x4] */
/* @0x289340 bl 0xb6c28 <realloc@plt> */
/* @0x289344 ldr r3, [r4, #0x60] */
/* @0x289348 ldr r2, [sp, #0x4] */
/* @0x28934c mov r12, r0 */
/* @0x289350 str r0, [r4, #0x68] */
/* @0x289354 b 0x289310 <spRegionAttachment_computeWorldVertices+0x19c> */
/* @0x289358 push {r3, r4, r5, lr} */
/* @0x28935c mov r4, r1 */
/* @0x289360 ldr r1, [r1, #0x8] */
/* @0x289364 mov r5, r0 */
/* @0x289368 cmp r1, #0 */
/* @0x28936c beq 0x289380 <spRegionAttachment_computeWorldVertices+0x20c> */
/* @0x289370 ldr r3, [r1, #0x54] */
/* @0x289374 cmp r3, #0 */
/* @0x289378 bne 0x289380 <spRegionAttachment_computeWorldVertices+0x20c> */
/* @0x28937c bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4> */
/* @0x289380 mov r3, #1 */
/* @0x289384 mov r0, r5 */
/* @0x289388 mov r2, r4 */
/* @0x28938c str r3, [r4, #0x54] */
/* @0x289390 mov r1, #0 */
/* @0x289394 pop {r3, r4, r5, lr} */
/* @0x289398 b 0x2892ec <spRegionAttachment_computeWorldVertices+0x178> */
/* @0x28939c ldr r3, [r1, #0x4] */
/* @0x2893a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2893a4 cmp r3, #4 */
/* @0x2893a8 sub sp, sp, #12 */
/* @0x2893ac mov r7, r0 */
/* @0x2893b0 beq 0x2893bc <spRegionAttachment_computeWorldVertices+0x248> */
/* @0x2893b4 add sp, sp, #12 */
/* @0x2893b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2893bc ldr r8, [r1, #0x14] */
/* @0x2893c0 ldr r1, [r1, #0x10] */
/* @0x2893c4 cmp r8, #0 */
/* @0x2893c8 str r1, [sp, #0x4] */
/* @0x2893cc beq 0x289458 <spRegionAttachment_computeWorldVertices+0x2e4> */
/* @0x2893d0 ldr r3, [sp, #0x4] */
/* @0x2893d4 ldr r11, [r0, #0x8] */
/* @0x2893d8 cmp r3, #0 */
/* @0x2893dc ble 0x2893b4 <spRegionAttachment_computeWorldVertices+0x240> */
/* @0x2893e0 mov r9, #0 */
/* @0x2893e4 ldr r10, [r8, r9, lsl #2] */
/* @0x2893e8 add r6, r9, #1 */
/* @0x2893ec add r5, r8, r9, lsl #2 */
/* @0x2893f0 add r10, r6, r10 */
/* @0x2893f4 cmp r6, r10 */
/* @0x2893f8 bge 0x289450 <spRegionAttachment_computeWorldVertices+0x2dc> */
/* @0x2893fc mov r4, r6 */
/* @0x289400 b 0x28940c <spRegionAttachment_computeWorldVertices+0x298> */
/* @0x289404 cmp r4, r10 */
/* @0x289408 beq 0x289434 <spRegionAttachment_computeWorldVertices+0x2c0> */
/* @0x28940c ldr r3, [r5, #0x4]! */
/* @0x289410 add r4, r4, #1 */
/* @0x289414 ldr r1, [r11, r3, lsl #2] */
/* @0x289418 ldr r3, [r1, #0x54] */
/* @0x28941c cmp r3, #0 */
/* @0x289420 bne 0x289404 <spRegionAttachment_computeWorldVertices+0x290> */
/* @0x289424 mov r0, r7 */
/* @0x289428 bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4> */
/* @0x28942c cmp r4, r10 */
/* @0x289430 bne 0x28940c <spRegionAttachment_computeWorldVertices+0x298> */
/* @0x289434 rsb r2, r9, r6 */
/* @0x289438 sub r2, r2, #1 */
/* @0x28943c add r9, r2, r4 */
/* @0x289440 ldr r3, [sp, #0x4] */
/* @0x289444 cmp r3, r9 */
/* @0x289448 bgt 0x2893e4 <spRegionAttachment_computeWorldVertices+0x270> */
/* @0x28944c b 0x2893b4 <spRegionAttachment_computeWorldVertices+0x240> */
/* @0x289450 mov r9, r6 */
/* @0x289454 b 0x289440 <spRegionAttachment_computeWorldVertices+0x2cc> */
/* @0x289458 ldr r3, [r2, #0x54] */
/* @0x28945c cmp r3, #0 */
/* @0x289460 bne 0x2893b4 <spRegionAttachment_computeWorldVertices+0x240> */
/* @0x289464 mov r1, r2 */
/* @0x289468 add sp, sp, #12 */
/* @0x28946c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x289470 b 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4> */
/* @0x289474 push {r3, r4, r5, r6, r7, lr} */
/* @0x289478 mov r6, r0 */
/* @0x28947c ldr r4, [r1, #0x4] */
/* @0x289480 mov r5, r2 */
/* @0x289484 mov r7, r3 */
/* @0x289488 cmp r4, #0 */
/* @0x28948c bne 0x2894a0 <spRegionAttachment_computeWorldVertices+0x32c> */
/* @0x289490 pop {r3, r4, r5, r6, r7, pc} */
/* @0x289494 ldr r4, [r4, #0xc] */
/* @0x289498 cmp r4, #0 */
/* @0x28949c beq 0x2894c8 <spRegionAttachment_computeWorldVertices+0x354> */
/* @0x2894a0 ldr r1, [r4] */
/* @0x2894a4 cmp r1, r5 */
/* @0x2894a8 bne 0x289494 <spRegionAttachment_computeWorldVertices+0x320> */
/* @0x2894ac ldr r1, [r4, #0x8] */
/* @0x2894b0 mov r0, r6 */
/* @0x2894b4 mov r2, r7 */
/* @0x2894b8 bl 0x28939c <spRegionAttachment_computeWorldVertices+0x228> */
/* @0x2894bc ldr r4, [r4, #0xc] */
/* @0x2894c0 cmp r4, #0 */
/* @0x2894c4 bne 0x2894a0 <spRegionAttachment_computeWorldVertices+0x32c> */
/* @0x2894c8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2894cc · spSkeleton_dispose · size=304 · insn=76 */
/* @0x2894cc push {r3, r4, r5, lr} */
/* @0x2894d0 mov r4, r0 */
/* @0x2894d4 ldr r0, [r0, #0x68] */
/* @0x2894d8 bl 0x285c80 <_free> */
/* @0x2894dc ldr r3, [r4, #0x4] */
/* @0x2894e0 cmp r3, #0 */
/* @0x2894e4 movgt r5, #0 */
/* @0x2894e8 ble 0x289508 <spSkeleton_dispose+0x3c> */
/* @0x2894ec ldr r3, [r4, #0x8] */
/* @0x2894f0 ldr r0, [r3, r5, lsl #2] */
/* @0x2894f4 add r5, r5, #1 */
/* @0x2894f8 bl 0x284efc <spBone_dispose> */
/* @0x2894fc ldr r3, [r4, #0x4] */
/* @0x289500 cmp r3, r5 */
/* @0x289504 bgt 0x2894ec <spSkeleton_dispose+0x20> */
/* @0x289508 ldr r0, [r4, #0x8] */
/* @0x28950c bl 0x285c80 <_free> */
/* @0x289510 ldr r3, [r4, #0x10] */
/* @0x289514 cmp r3, #0 */
/* @0x289518 movgt r5, #0 */
/* @0x28951c ble 0x28953c <spSkeleton_dispose+0x70> */
/* @0x289520 ldr r3, [r4, #0x14] */
/* @0x289524 ldr r0, [r3, r5, lsl #2] */
/* @0x289528 add r5, r5, #1 */
/* @0x28952c bl 0x28ee00 <spSlot_dispose> */
/* @0x289530 ldr r3, [r4, #0x10] */
/* @0x289534 cmp r3, r5 */
/* @0x289538 bgt 0x289520 <spSkeleton_dispose+0x54> */
/* @0x28953c ldr r0, [r4, #0x14] */
/* @0x289540 bl 0x285c80 <_free> */
/* @0x289544 ldr r3, [r4, #0x1c] */
/* @0x289548 cmp r3, #0 */
/* @0x28954c movgt r5, #0 */
/* @0x289550 ble 0x289570 <spSkeleton_dispose+0xa4> */
/* @0x289554 ldr r3, [r4, #0x20] */
/* @0x289558 ldr r0, [r3, r5, lsl #2] */
/* @0x28955c add r5, r5, #1 */
/* @0x289560 bl 0x285e2c <spIkConstraint_dispose> */
/* @0x289564 ldr r3, [r4, #0x1c] */
/* @0x289568 cmp r3, r5 */
/* @0x28956c bgt 0x289554 <spSkeleton_dispose+0x88> */
/* @0x289570 ldr r0, [r4, #0x20] */
/* @0x289574 bl 0x285c80 <_free> */
/* @0x289578 ldr r0, [r4, #0x24] */
/* @0x28957c bl 0x285c80 <_free> */
/* @0x289580 ldr r3, [r4, #0x28] */
/* @0x289584 cmp r3, #0 */
/* @0x289588 movgt r5, #0 */
/* @0x28958c ble 0x2895ac <spSkeleton_dispose+0xe0> */
/* @0x289590 ldr r3, [r4, #0x2c] */
/* @0x289594 ldr r0, [r3, r5, lsl #2] */
/* @0x289598 add r5, r5, #1 */
/* @0x28959c bl 0x28f0f4 <spTransformConstraint_dispose> */
/* @0x2895a0 ldr r3, [r4, #0x28] */
/* @0x2895a4 cmp r3, r5 */
/* @0x2895a8 bgt 0x289590 <spSkeleton_dispose+0xc4> */
/* @0x2895ac ldr r0, [r4, #0x2c] */
/* @0x2895b0 bl 0x285c80 <_free> */
/* @0x2895b4 ldr r3, [r4, #0x30] */
/* @0x2895b8 cmp r3, #0 */
/* @0x2895bc movgt r5, #0 */
/* @0x2895c0 ble 0x2895e0 <spSkeleton_dispose+0x114> */
/* @0x2895c4 ldr r3, [r4, #0x34] */
/* @0x2895c8 ldr r0, [r3, r5, lsl #2] */
/* @0x2895cc add r5, r5, #1 */
/* @0x2895d0 bl 0x287a70 <spPathConstraint_dispose> */
/* @0x2895d4 ldr r3, [r4, #0x30] */
/* @0x2895d8 cmp r3, r5 */
/* @0x2895dc bgt 0x2895c4 <spSkeleton_dispose+0xf8> */
/* @0x2895e0 ldr r0, [r4, #0x34] */
/* @0x2895e4 bl 0x285c80 <_free> */
/* @0x2895e8 ldr r0, [r4, #0x18] */
/* @0x2895ec bl 0x285c80 <_free> */
/* @0x2895f0 mov r0, r4 */
/* @0x2895f4 pop {r3, r4, r5, lr} */
/* @0x2895f8 b 0x285c80 <_free> */
