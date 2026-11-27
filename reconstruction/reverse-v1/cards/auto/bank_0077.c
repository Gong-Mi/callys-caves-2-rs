/* libyoyo.so 覆盖卡组 0077
 * 函数 0x143668..0x14430c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x143668 · F_ActionExecuteScript(RValue&, CInstance*, CInstance*, int, RValue*) · size=736 · insn=184 */
/* @0x143668 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14366c sub sp, sp, #116 */
/* @0x143670 add r8, sp, #32 */
/* @0x143674 add r6, sp, #44 */
/* @0x143678 str r0, [sp, #0xc] */
/* @0x14367c add r7, sp, #112 */
/* @0x143680 str r1, [sp, #0x10] */
/* @0x143684 mov r0, r8 */
/* @0x143688 str r2, [sp, #0x14] */
/* @0x14368c mov r1, #0 */
/* @0x143690 mov r2, #80 */
/* @0x143694 mov r4, r8 */
/* @0x143698 bl 0xb65b0 <memset@plt> */
/* @0x14369c ldr r3, [sp, #0x98] */
/* @0x1436a0 mov r10, #0 */
/* @0x1436a4 add r11, r3, #12 */
/* @0x1436a8 mov r5, r3 */
/* @0x1436ac ldr r2, [r4, #0xc] */
/* @0x1436b0 bic r3, r2, #-16777216 */
/* @0x1436b4 cmp r3, #1 */
/* @0x1436b8 beq 0x143864 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x1436bc cmp r3, #2 */
/* @0x1436c0 bne 0x1436e4 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x1436c4 sub r2, r2, #1 */
/* @0x1436c8 bic r2, r2, #-16777216 */
/* @0x1436cc bic r2, r2, #3 */
/* @0x1436d0 cmp r2, #0 */
/* @0x1436d4 beq 0x1438e0 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x278> */
/* @0x1436d8 mov r2, #5 */
/* @0x1436dc str r10, [r4, #0x8] */
/* @0x1436e0 str r2, [r4, #0xc] */
/* @0x1436e4 str r10, [r6, #-0xc] */
/* @0x1436e8 ldr r2, [r5, #0xc] */
/* @0x1436ec bic r3, r2, #-16777216 */
/* @0x1436f0 str r2, [r4, #0xc] */
/* @0x1436f4 ldr r2, [r5, #0x8] */
/* @0x1436f8 str r2, [r4, #0x8] */
/* @0x1436fc cmp r3, #14 */
/* @0x143700 addls pc, pc, r3, lsl #2 */
/* @0x143704 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x143708 b 0x1437f0 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x14370c b 0x14384c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x143710 b 0x143820 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x143714 b 0x143744 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x143718 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x14371c b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x143720 b 0x1437fc <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x143724 b 0x143744 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x143728 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x14372c b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x143730 b 0x1437f0 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x143734 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x143738 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x14373c b 0x1437f0 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x143740 b 0x143744 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x143744 ldr r3, [r11, #-0xc] */
/* @0x143748 str r3, [r6, #-0xc] */
/* @0x14374c add r4, r4, #16 */
/* @0x143750 add r6, r6, #16 */
/* @0x143754 cmp r4, r7 */
/* @0x143758 add r11, r11, #16 */
/* @0x14375c add r5, r5, #16 */
/* @0x143760 bne 0x1436ac <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x143764 mov r5, #0 */
/* @0x143768 ldr r0, [sp, #0x98] */
/* @0x14376c mov r1, r5 */
/* @0x143770 mov r4, #5 */
/* @0x143774 str r8, [sp, #0x1c] */
/* @0x143778 str r4, [sp, #0x18] */
/* @0x14377c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x143780 ldr r2, [sp, #0xc] */
/* @0x143784 mov r3, r4 */
/* @0x143788 add r12, sp, #24 */
/* @0x14378c ldr r1, [sp, #0x10] */
/* @0x143790 str r12, [sp, #0x4] */
/* @0x143794 str r2, [sp] */
/* @0x143798 ldr r2, [sp, #0x14] */
/* @0x14379c bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue> */
/* @0x1437a0 ldr r3, [pc, #0x198] */
/* @0x1437a4 ldr r3, [pc, r3] */
/* @0x1437a8 ldrb r3, [r3] */
/* @0x1437ac cmp r3, r5 */
/* @0x1437b0 bne 0x1438ec <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x1437b4 mov r4, #0 */
/* @0x1437b8 mov r5, #5 */
/* @0x1437bc ldr r3, [r8, #0xc] */
/* @0x1437c0 sub r3, r3, #1 */
/* @0x1437c4 bic r3, r3, #-16777216 */
/* @0x1437c8 bic r3, r3, #3 */
/* @0x1437cc cmp r3, #0 */
/* @0x1437d0 beq 0x143894 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x1437d4 str r4, [r8, #0x8] */
/* @0x1437d8 str r5, [r8, #0xc] */
/* @0x1437dc str r4, [r8], #16 */
/* @0x1437e0 cmp r8, r7 */
/* @0x1437e4 bne 0x1437bc <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x1437e8 add sp, sp, #116 */
/* @0x1437ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1437f0 ldm r5, {r2, r3} */
/* @0x1437f4 stm r4, {r2, r3} */
/* @0x1437f8 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x1437fc ldr r3, [r11, #-0xc] */
/* @0x143800 str r3, [r6, #-0xc] */
/* @0x143804 ldr r3, [r11, #-0xc] */
/* @0x143808 cmp r3, #0 */
/* @0x14380c beq 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x143810 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x143814 ldr r1, [r11, #-0xc] */
/* @0x143818 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x14381c b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x143820 ldr r3, [r11, #-0xc] */
/* @0x143824 cmp r3, #0 */
/* @0x143828 str r3, [r6, #-0xc] */
/* @0x14382c beq 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x143830 ldr r1, [r3, #0x8] */
/* @0x143834 ldr r2, [r3] */
/* @0x143838 cmp r1, #0 */
/* @0x14383c streq r4, [r3, #0x8] */
/* @0x143840 add r2, r2, #1 */
/* @0x143844 str r2, [r3] */
/* @0x143848 b 0x14374c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x14384c ldr r3, [r11, #-0xc] */
/* @0x143850 cmp r3, #0 */
/* @0x143854 ldrne r2, [r3, #0x4] */
/* @0x143858 addne r2, r2, #1 */
/* @0x14385c strne r2, [r3, #0x4] */
/* @0x143860 b 0x143748 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x143864 ldr r9, [r6, #-0xc] */
/* @0x143868 cmp r9, #0 */
/* @0x14386c beq 0x14388c <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x143870 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x143874 ldr r3, [r9, #0x4] */
/* @0x143878 sub r3, r3, #1 */
/* @0x14387c str r3, [r9, #0x4] */
/* @0x143880 cmp r3, #0 */
/* @0x143884 beq 0x1438a0 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x238> */
/* @0x143888 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x14388c str r10, [r6, #-0xc] */
/* @0x143890 b 0x1436e4 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x143894 mov r0, r8 */
/* @0x143898 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x14389c b 0x1437d4 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x1438a0 ldr r0, [r9] */
/* @0x1438a4 str r3, [sp, #0x8] */
/* @0x1438a8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1438ac ldr r3, [sp, #0x8] */
/* @0x1438b0 str r3, [r9] */
/* @0x1438b4 str r3, [r9, #0x8] */
/* @0x1438b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1438bc ldr r3, [r9, #0x4] */
/* @0x1438c0 sub r3, r3, #1 */
/* @0x1438c4 str r3, [r9, #0x4] */
/* @0x1438c8 cmp r3, #0 */
/* @0x1438cc beq 0x143908 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x2a0> */
/* @0x1438d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1438d4 mov r0, r9 */
/* @0x1438d8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1438dc b 0x143888 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x1438e0 mov r0, r4 */
/* @0x1438e4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1438e8 b 0x1436d8 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1438ec ldr r3, [pc, #0x50] */
/* @0x1438f0 mov r1, r5 */
/* @0x1438f4 ldr r3, [pc, r3] */
/* @0x1438f8 ldr r3, [r3] */
/* @0x1438fc ldr r0, [r3] */
/* @0x143900 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x143904 b 0x1437b4 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x143908 ldr r0, [r9] */
/* @0x14390c str r3, [sp, #0x8] */
/* @0x143910 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x143914 ldr r3, [sp, #0x8] */
/* @0x143918 mov r0, r9 */
/* @0x14391c str r3, [r9] */
/* @0x143920 str r3, [r9, #0x8] */
/* @0x143924 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x143928 mov r0, r9 */
/* @0x14392c bl 0x27d1d0 <_ZdlPv> */
/* @0x143930 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x143934 mov r0, r9 */
/* @0x143938 bl 0x27d1d0 <_ZdlPv> */
/* @0x14393c b 0x143888 <_Z21F_ActionExecuteScriptR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x143940 eoreq r10, r10, r0, asr #7 */
/* @0x143944 eoreq r10, r10, r12, ror r2 */

/* ── FUNC 0x143948 · F_D3DMatrixStackClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x143948 ldr r0, [pc, #0x5c] */
/* @0x14394c mov r2, #0 */
/* @0x143950 ldr r3, [pc, #0x58] */
/* @0x143954 mov r1, #1065353216 */
/* @0x143958 ldr r0, [pc, r0] */
/* @0x14395c mov r12, #0 */
/* @0x143960 ldr r3, [pc, r3] */
/* @0x143964 str r12, [r0] */
/* @0x143968 str r2, [r3, #0x38] */
/* @0x14396c str r2, [r3, #0x34] */
/* @0x143970 str r2, [r3, #0x30] */
/* @0x143974 str r2, [r3, #0x2c] */
/* @0x143978 str r2, [r3, #0x24] */
/* @0x14397c str r2, [r3, #0x20] */
/* @0x143980 str r2, [r3, #0x1c] */
/* @0x143984 str r2, [r3, #0x18] */
/* @0x143988 str r2, [r3, #0x10] */
/* @0x14398c str r2, [r3, #0xc] */
/* @0x143990 str r2, [r3, #0x8] */
/* @0x143994 str r2, [r3, #0x4] */
/* @0x143998 str r1, [r3, #0x3c] */
/* @0x14399c str r1, [r3, #0x28] */
/* @0x1439a0 str r1, [r3, #0x14] */
/* @0x1439a4 str r1, [r3] */
/* @0x1439a8 bx lr */
/* @0x1439ac eoreq r11, r10, r12, lsr #25 */
/* @0x1439b0 eoreq r11, r10, r8, lsr #25 */

/* ── FUNC 0x1439b4 · F_D3DMatrixStackPop(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1439b4 ldr r12, [pc, #0x28] */
/* @0x1439b8 push {r4, r5} */
/* @0x1439bc ldr r12, [pc, r12] */
/* @0x1439c0 ldr r4, [r12] */
/* @0x1439c4 sub r4, r4, #1 */
/* @0x1439c8 str r4, [r12] */
/* @0x1439cc cmp r4, #0 */
/* @0x1439d0 blt 0x1439dc <_Z19F_D3DMatrixStackPopR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x1439d4 pop {r4, r5} */
/* @0x1439d8 bx lr */
/* @0x1439dc pop {r4, r5} */
/* @0x1439e0 b 0x143948 <_Z21F_D3DMatrixStackClearR6RValueP9CInstanceS2_iPS_> */
/* @0x1439e4 eoreq r11, r10, r8, asr #24 */

/* ── FUNC 0x1439e8 · F_D3DMatrixStackIsEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1439e8 ldr r3, [pc, #0x24] */
/* @0x1439ec mov r2, #0 */
/* @0x1439f0 str r2, [r0, #0xc] */
/* @0x1439f4 ldr r3, [pc, r3] */
/* @0x1439f8 ldr r3, [r3] */
/* @0x1439fc cmp r3, r2 */
/* @0x143a00 streq r3, [r0] */
/* @0x143a04 moveq r3, r2 */
/* @0x143a08 movteq r3, #0x3ff0 */
/* @0x143a0c streq r3, [r0, #0x4] */
/* @0x143a10 bx lr */
/* @0x143a14 eoreq r11, r10, r0, lsl r12 */

/* ── FUNC 0x143a18 · F_D3DLightGetAmbient(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x143a18 ldr r3, [pc, #0x20] */
/* @0x143a1c mov r2, #0 */
/* @0x143a20 str r2, [r0, #0xc] */
/* @0x143a24 ldr r3, [pc, r3] */
/* @0x143a28 ldr r2, [r3] */
/* @0x143a2c vmov s15, r2 */
/* @0x143a30 vcvt.f64.u32 d7, s15 */
/* @0x143a34 vmov r2, r3, d7 */
/* @0x143a38 stm r0, {r2, r3} */
/* @0x143a3c bx lr */
/* @0x143a40 eoreq r11, r10, r8, ror #23 */

/* ── FUNC 0x143a44 · F_D3DGetLighting(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x143a44 ldr r3, [pc, #0x28] */
/* @0x143a48 mov r2, #0 */
/* @0x143a4c str r2, [r0, #0xc] */
/* @0x143a50 ldr r3, [pc, r3] */
/* @0x143a54 ldrb r3, [r3] */
/* @0x143a58 cmp r3, r2 */
/* @0x143a5c movne r3, r2 */
/* @0x143a60 moveq r2, r3 */
/* @0x143a64 movtne r2, #0x3ff0 */
/* @0x143a68 str r3, [r0] */
/* @0x143a6c str r2, [r0, #0x4] */
/* @0x143a70 bx lr */
/* @0x143a74 eoreq r11, r10, r0, asr #23 */

/* ── FUNC 0x143a78 · F_YoYo_EnableAlphaBlend(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x143a78 push {r3, lr} */
/* @0x143a7c mov r1, #0 */
/* @0x143a80 ldr r0, [sp, #0x8] */
/* @0x143a84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x143a88 ldr r3, [pc, #0x10] */
/* @0x143a8c mov r1, #12 */
/* @0x143a90 mov r2, r0 */
/* @0x143a94 ldr r0, [pc, r3] */
/* @0x143a98 pop {r3, lr} */
/* @0x143a9c b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x143aa0 eoreq r10, r10, r4, ror #4 */

/* ── FUNC 0x143aa4 · F_YoYo_DrawFlush(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x143aa4 mov r3, #0 */
/* @0x143aa8 str r3, [r0, #0xc] */
/* @0x143aac str r3, [r0] */
/* @0x143ab0 str r3, [r0, #0x4] */
/* @0x143ab4 b 0x1852ec <_ZN8Graphics5FlushEv> */

/* ── FUNC 0x143ab8 · F_D3DStart(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x143ab8 push {r4, lr} */
/* @0x143abc mov r4, r0 */
/* @0x143ac0 mov r3, #0 */
/* @0x143ac4 mov r0, #1 */
/* @0x143ac8 str r3, [r4, #0xc] */
/* @0x143acc bl 0x163170 <_Z14GR_3D_Set_Modeb> */
/* @0x143ad0 vmov s15, r0 */
/* @0x143ad4 vcvt.f64.u32 d7, s15 */
/* @0x143ad8 vmov r0, r1, d7 */
/* @0x143adc vmov r2, s14 */
/* @0x143ae0 mov r3, r1 */
/* @0x143ae4 stm r4, {r2, r3} */
/* @0x143ae8 pop {r4, pc} */

/* ── FUNC 0x143aec · F_D3DEnd(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x143aec mov r3, #0 */
/* @0x143af0 push {r4, lr} */
/* @0x143af4 mov r4, r0 */
/* @0x143af8 str r3, [r4, #0xc] */
/* @0x143afc mov r0, r3 */
/* @0x143b00 bl 0x163170 <_Z14GR_3D_Set_Modeb> */
/* @0x143b04 vmov s15, r0 */
/* @0x143b08 vcvt.f64.u32 d7, s15 */
/* @0x143b0c vmov r0, r1, d7 */
/* @0x143b10 vmov r2, s14 */
/* @0x143b14 mov r3, r1 */
/* @0x143b18 stm r4, {r2, r3} */
/* @0x143b1c pop {r4, pc} */

/* ── FUNC 0x143b20 · F_D3DSetPerspective(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x143b20 push {r3, lr} */
/* @0x143b24 mov r1, #0 */
/* @0x143b28 ldr r0, [sp, #0x8] */
/* @0x143b2c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x143b30 pop {r3, lr} */
/* @0x143b34 b 0x1682f0 <_Z22GR_D3D_Set_Perspectiveb> */

/* ── FUNC 0x143b38 · F_D3DSetHidden(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x143b38 push {r3, lr} */
/* @0x143b3c mov r1, #0 */
/* @0x143b40 ldr r0, [sp, #0x8] */
/* @0x143b44 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x143b48 pop {r3, lr} */
/* @0x143b4c b 0x16841c <_Z10SetZBufferb> */

/* ── FUNC 0x143b50 · F_D3DSetDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x143b50 push {r3, lr} */
/* @0x143b54 mov r1, #0 */
/* @0x143b58 ldr r0, [sp, #0x8] */
/* @0x143b5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143b60 pop {r3, lr} */
/* @0x143b64 b 0x1631dc <_Z15GR_3D_Set_Depthf> */

/* ── FUNC 0x143b68 · F_D3DSetLighting(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x143b68 push {r3, lr} */
/* @0x143b6c mov r1, #0 */
/* @0x143b70 ldr r0, [sp, #0x8] */
/* @0x143b74 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x143b78 ldr r3, [pc, #0xc] */
/* @0x143b7c ldr r3, [pc, r3] */
/* @0x143b80 strb r0, [r3] */
/* @0x143b84 pop {r3, lr} */
/* @0x143b88 b 0x168484 <_Z19GR_D3D_Set_Lightingb> */
/* @0x143b8c mlaeq r10, r4, r10, r11 */

/* ── FUNC 0x143b90 · F_D3DSetShading(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x143b90 push {r3, lr} */
/* @0x143b94 mov r1, #0 */
/* @0x143b98 ldr r0, [sp, #0x8] */
/* @0x143b9c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x143ba0 pop {r3, lr} */
/* @0x143ba4 b 0x16849c <_Z18GR_D3D_Set_Shadingb> */

/* ── FUNC 0x143ba8 · F_D3DSetFog(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x143ba8 push {r4, r5, r6, r7, r8, lr} */
/* @0x143bac mov r1, #0 */
/* @0x143bb0 ldr r4, [sp, #0x18] */
/* @0x143bb4 mov r0, r4 */
/* @0x143bb8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x143bbc mov r1, #1 */
/* @0x143bc0 mov r5, r0 */
/* @0x143bc4 mov r0, r4 */
/* @0x143bc8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x143bcc bl 0xb66e8 <lrint@plt> */
/* @0x143bd0 mov r1, #2 */
/* @0x143bd4 mov r7, r0 */
/* @0x143bd8 mov r0, r4 */
/* @0x143bdc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x143be0 mov r1, #3 */
/* @0x143be4 mov r6, r0 */
/* @0x143be8 mov r0, r4 */
/* @0x143bec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x143bf0 mov r1, r7 */
/* @0x143bf4 sxth r2, r6 */
/* @0x143bf8 sxth r3, r0 */
/* @0x143bfc mov r0, r5 */
/* @0x143c00 pop {r4, r5, r6, r7, r8, lr} */
/* @0x143c04 b 0x168520 <_Z14GR_D3D_Set_Fogbjss> */

/* ── FUNC 0x143c08 · F_D3DSetCulling(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x143c08 push {r3, lr} */
/* @0x143c0c mov r1, #0 */
/* @0x143c10 ldr r0, [sp, #0x8] */
/* @0x143c14 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x143c18 pop {r3, lr} */
/* @0x143c1c b 0x1683e8 <_Z18GR_D3D_Set_Cullingb> */

/* ── FUNC 0x143c20 · F_D3DSetZWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x143c20 push {r3, lr} */
/* @0x143c24 mov r1, #0 */
/* @0x143c28 ldr r0, [sp, #0x8] */
/* @0x143c2c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x143c30 pop {r3, lr} */
/* @0x143c34 b 0x16864c <_Z25GR_D3D_Set_Z_Write_Enableb> */

/* ── FUNC 0x143c38 · F_D3DPrimitiveBegin(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x143c38 push {r3, lr} */
/* @0x143c3c mov r1, #0 */
/* @0x143c40 ldr r0, [sp, #0x8] */
/* @0x143c44 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x143c48 mvn r1, #0 */
/* @0x143c4c pop {r3, lr} */
/* @0x143c50 b 0x1769dc <_Z21GR_3D_Primitive_Beginii> */

/* ── FUNC 0x143c54 · F_D3DPrimitiveBeginTexture(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x143c54 push {r3, r4, r5, lr} */
/* @0x143c58 mov r1, #0 */
/* @0x143c5c ldr r4, [sp, #0x10] */
/* @0x143c60 mov r0, r4 */
/* @0x143c64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x143c68 mov r1, #1 */
/* @0x143c6c mov r5, r0 */
/* @0x143c70 mov r0, r4 */
/* @0x143c74 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x143c78 mov r1, r0 */
/* @0x143c7c mov r0, r5 */
/* @0x143c80 pop {r3, r4, r5, lr} */
/* @0x143c84 b 0x1769dc <_Z21GR_3D_Primitive_Beginii> */

/* ── FUNC 0x143c88 · F_D3DPrimitiveEnd(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x143c88 b 0x176ad0 <_Z19GR_3D_Primitive_Endv> */

/* ── FUNC 0x143c8c · F_D3DVertex(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x143c8c push {r4, r5, r6, lr} */
/* @0x143c90 mov r1, #0 */
/* @0x143c94 ldr r4, [sp, #0x10] */
/* @0x143c98 mov r0, r4 */
/* @0x143c9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143ca0 mov r1, #1 */
/* @0x143ca4 mov r6, r0 */
/* @0x143ca8 mov r0, r4 */
/* @0x143cac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143cb0 mov r1, #2 */
/* @0x143cb4 mov r5, r0 */
/* @0x143cb8 mov r0, r4 */
/* @0x143cbc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143cc0 mov r1, r5 */
/* @0x143cc4 mov r2, r0 */
/* @0x143cc8 mov r0, r6 */
/* @0x143ccc pop {r4, r5, r6, lr} */
/* @0x143cd0 b 0x176e2c <_Z12GR_3D_Vertexfff> */

/* ── FUNC 0x143cd4 · F_D3DVertexColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x143cd4 push {r4, r5, r6, r7, r8, lr} */
/* @0x143cd8 mov r1, #0 */
/* @0x143cdc ldr r4, [sp, #0x18] */
/* @0x143ce0 mov r0, r4 */
/* @0x143ce4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143ce8 mov r1, #1 */
/* @0x143cec mov r5, r0 */
/* @0x143cf0 mov r0, r4 */
/* @0x143cf4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143cf8 mov r1, #2 */
/* @0x143cfc mov r8, r0 */
/* @0x143d00 mov r0, r4 */
/* @0x143d04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143d08 mov r1, #3 */
/* @0x143d0c mov r7, r0 */
/* @0x143d10 mov r0, r4 */
/* @0x143d14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x143d18 mov r1, #4 */
/* @0x143d1c mov r6, r0 */
/* @0x143d20 mov r0, r4 */
/* @0x143d24 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143d28 mov r1, r8 */
/* @0x143d2c mov r2, r7 */
/* @0x143d30 mov r3, r6 */
/* @0x143d34 str r0, [sp, #0x18] */
/* @0x143d38 mov r0, r5 */
/* @0x143d3c pop {r4, r5, r6, r7, r8, lr} */
/* @0x143d40 b 0x176ed4 <_Z18GR_3D_Vertex_Colorfffjf> */

/* ── FUNC 0x143d44 · F_D3DVertexTexture(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x143d44 push {r4, r5, r6, r7, r8, lr} */
/* @0x143d48 mov r1, #0 */
/* @0x143d4c ldr r4, [sp, #0x18] */
/* @0x143d50 mov r0, r4 */
/* @0x143d54 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143d58 mov r1, #1 */
/* @0x143d5c mov r5, r0 */
/* @0x143d60 mov r0, r4 */
/* @0x143d64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143d68 mov r1, #2 */
/* @0x143d6c mov r8, r0 */
/* @0x143d70 mov r0, r4 */
/* @0x143d74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143d78 mov r1, #3 */
/* @0x143d7c mov r7, r0 */
/* @0x143d80 mov r0, r4 */
/* @0x143d84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143d88 mov r1, #4 */
/* @0x143d8c mov r6, r0 */
/* @0x143d90 mov r0, r4 */
/* @0x143d94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143d98 mov r1, r8 */
/* @0x143d9c mov r2, r7 */
/* @0x143da0 mov r3, r6 */
/* @0x143da4 str r0, [sp, #0x18] */
/* @0x143da8 mov r0, r5 */
/* @0x143dac pop {r4, r5, r6, r7, r8, lr} */
/* @0x143db0 b 0x176f7c <_Z20GR_3D_Vertex_Texturefffff> */

/* ── FUNC 0x143db4 · F_D3DVertexTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x143db4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x143db8 sub sp, sp, #16 */
/* @0x143dbc mov r1, #0 */
/* @0x143dc0 ldr r4, [sp, #0x30] */
/* @0x143dc4 mov r0, r4 */
/* @0x143dc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143dcc mov r1, #1 */
/* @0x143dd0 mov r5, r0 */
/* @0x143dd4 mov r0, r4 */
/* @0x143dd8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143ddc mov r1, #2 */
/* @0x143de0 mov r8, r0 */
/* @0x143de4 mov r0, r4 */
/* @0x143de8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143dec mov r1, #3 */
/* @0x143df0 mov r7, r0 */
/* @0x143df4 mov r0, r4 */
/* @0x143df8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143dfc mov r1, #4 */
/* @0x143e00 mov r6, r0 */
/* @0x143e04 mov r0, r4 */
/* @0x143e08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143e0c mov r1, #5 */
/* @0x143e10 mov r10, r0 */
/* @0x143e14 mov r0, r4 */
/* @0x143e18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x143e1c mov r1, #6 */
/* @0x143e20 mov r9, r0 */
/* @0x143e24 mov r0, r4 */
/* @0x143e28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143e2c str r10, [sp] */
/* @0x143e30 str r9, [sp, #0x4] */
/* @0x143e34 mov r1, r8 */
/* @0x143e38 mov r2, r7 */
/* @0x143e3c mov r3, r6 */
/* @0x143e40 str r0, [sp, #0x8] */
/* @0x143e44 mov r0, r5 */
/* @0x143e48 bl 0x1770c8 <_Z26GR_3D_Vertex_Texture_Colorfffffjf> */
/* @0x143e4c add sp, sp, #16 */
/* @0x143e50 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x143e54 · F_D3DVertexNormal(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x143e54 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x143e58 sub sp, sp, #12 */
/* @0x143e5c mov r1, #0 */
/* @0x143e60 ldr r4, [sp, #0x28] */
/* @0x143e64 mov r0, r4 */
/* @0x143e68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143e6c mov r1, #1 */
/* @0x143e70 mov r5, r0 */
/* @0x143e74 mov r0, r4 */
/* @0x143e78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143e7c mov r1, #2 */
/* @0x143e80 mov r8, r0 */
/* @0x143e84 mov r0, r4 */
/* @0x143e88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143e8c mov r1, #3 */
/* @0x143e90 mov r7, r0 */
/* @0x143e94 mov r0, r4 */
/* @0x143e98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143e9c mov r1, #4 */
/* @0x143ea0 mov r6, r0 */
/* @0x143ea4 mov r0, r4 */
/* @0x143ea8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143eac mov r1, #5 */
/* @0x143eb0 mov r9, r0 */
/* @0x143eb4 mov r0, r4 */
/* @0x143eb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143ebc str r9, [sp] */
/* @0x143ec0 mov r1, r8 */
/* @0x143ec4 mov r2, r7 */
/* @0x143ec8 mov r3, r6 */
/* @0x143ecc str r0, [sp, #0x4] */
/* @0x143ed0 mov r0, r5 */
/* @0x143ed4 bl 0x177214 <_Z14GR_3D_Vertex_Nffffff> */
/* @0x143ed8 add sp, sp, #12 */
/* @0x143edc pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x143ee0 · F_D3DVertexNormalColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x143ee0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x143ee4 sub sp, sp, #20 */
/* @0x143ee8 mov r1, #0 */
/* @0x143eec ldr r4, [sp, #0x38] */
/* @0x143ef0 mov r0, r4 */
/* @0x143ef4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143ef8 mov r1, #1 */
/* @0x143efc mov r5, r0 */
/* @0x143f00 mov r0, r4 */
/* @0x143f04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143f08 mov r1, #2 */
/* @0x143f0c mov r8, r0 */
/* @0x143f10 mov r0, r4 */
/* @0x143f14 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143f18 mov r1, #3 */
/* @0x143f1c mov r7, r0 */
/* @0x143f20 mov r0, r4 */
/* @0x143f24 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143f28 mov r1, #4 */
/* @0x143f2c mov r6, r0 */
/* @0x143f30 mov r0, r4 */
/* @0x143f34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143f38 mov r1, #5 */
/* @0x143f3c mov r11, r0 */
/* @0x143f40 mov r0, r4 */
/* @0x143f44 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143f48 mov r1, #6 */
/* @0x143f4c mov r10, r0 */
/* @0x143f50 mov r0, r4 */
/* @0x143f54 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x143f58 mov r1, #7 */
/* @0x143f5c mov r9, r0 */
/* @0x143f60 mov r0, r4 */
/* @0x143f64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143f68 str r11, [sp] */
/* @0x143f6c str r10, [sp, #0x4] */
/* @0x143f70 mov r1, r8 */
/* @0x143f74 str r9, [sp, #0x8] */
/* @0x143f78 mov r2, r7 */
/* @0x143f7c mov r3, r6 */
/* @0x143f80 str r0, [sp, #0xc] */
/* @0x143f84 mov r0, r5 */
/* @0x143f88 bl 0x1772d0 <_Z20GR_3D_Vertex_N_Colorffffffjf> */
/* @0x143f8c add sp, sp, #20 */
/* @0x143f90 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x143f94 · F_D3DVertexNormalTexture(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x143f94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x143f98 sub sp, sp, #20 */
/* @0x143f9c mov r1, #0 */
/* @0x143fa0 ldr r4, [sp, #0x38] */
/* @0x143fa4 mov r0, r4 */
/* @0x143fa8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143fac mov r1, #1 */
/* @0x143fb0 mov r5, r0 */
/* @0x143fb4 mov r0, r4 */
/* @0x143fb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143fbc mov r1, #2 */
/* @0x143fc0 mov r8, r0 */
/* @0x143fc4 mov r0, r4 */
/* @0x143fc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143fcc mov r1, #3 */
/* @0x143fd0 mov r7, r0 */
/* @0x143fd4 mov r0, r4 */
/* @0x143fd8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143fdc mov r1, #4 */
/* @0x143fe0 mov r6, r0 */
/* @0x143fe4 mov r0, r4 */
/* @0x143fe8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143fec mov r1, #5 */
/* @0x143ff0 mov r11, r0 */
/* @0x143ff4 mov r0, r4 */
/* @0x143ff8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x143ffc mov r1, #6 */
/* @0x144000 mov r10, r0 */
/* @0x144004 mov r0, r4 */
/* @0x144008 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14400c mov r1, #7 */
/* @0x144010 mov r9, r0 */
/* @0x144014 mov r0, r4 */
/* @0x144018 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14401c str r11, [sp] */
/* @0x144020 str r10, [sp, #0x4] */
/* @0x144024 mov r1, r8 */
/* @0x144028 str r9, [sp, #0x8] */
/* @0x14402c mov r2, r7 */
/* @0x144030 mov r3, r6 */
/* @0x144034 str r0, [sp, #0xc] */
/* @0x144038 mov r0, r5 */
/* @0x14403c bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff> */
/* @0x144040 add sp, sp, #20 */
/* @0x144044 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x144048 · F_D3DVertexNormalTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=236 · insn=59 */
/* @0x144048 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x14404c sub sp, sp, #36 */
/* @0x144050 mov r1, #0 */
/* @0x144054 ldr r4, [sp, #0x48] */
/* @0x144058 mov r0, r4 */
/* @0x14405c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144060 mov r1, #1 */
/* @0x144064 mov r5, r0 */
/* @0x144068 mov r0, r4 */
/* @0x14406c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144070 mov r1, #2 */
/* @0x144074 mov r8, r0 */
/* @0x144078 mov r0, r4 */
/* @0x14407c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144080 mov r1, #3 */
/* @0x144084 mov r7, r0 */
/* @0x144088 mov r0, r4 */
/* @0x14408c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144090 mov r1, #4 */
/* @0x144094 mov r6, r0 */
/* @0x144098 mov r0, r4 */
/* @0x14409c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1440a0 mov r1, #5 */
/* @0x1440a4 mov r2, r0 */
/* @0x1440a8 mov r0, r4 */
/* @0x1440ac str r2, [sp, #0x18] */
/* @0x1440b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1440b4 mov r1, #6 */
/* @0x1440b8 mov r3, r0 */
/* @0x1440bc mov r0, r4 */
/* @0x1440c0 str r3, [sp, #0x1c] */
/* @0x1440c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1440c8 mov r1, #7 */
/* @0x1440cc mov r11, r0 */
/* @0x1440d0 mov r0, r4 */
/* @0x1440d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1440d8 mov r1, #8 */
/* @0x1440dc mov r10, r0 */
/* @0x1440e0 mov r0, r4 */
/* @0x1440e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1440e8 mov r1, #9 */
/* @0x1440ec mov r9, r0 */
/* @0x1440f0 mov r0, r4 */
/* @0x1440f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1440f8 ldr r2, [sp, #0x18] */
/* @0x1440fc ldr r3, [sp, #0x1c] */
/* @0x144100 mov r1, r8 */
/* @0x144104 str r11, [sp, #0x8] */
/* @0x144108 str r2, [sp] */
/* @0x14410c mov r2, r7 */
/* @0x144110 str r3, [sp, #0x4] */
/* @0x144114 mov r3, r6 */
/* @0x144118 str r10, [sp, #0xc] */
/* @0x14411c str r9, [sp, #0x10] */
/* @0x144120 str r0, [sp, #0x14] */
/* @0x144124 mov r0, r5 */
/* @0x144128 bl 0x1774e4 <_Z28GR_3D_Vertex_N_Texture_Colorffffffffjf> */
/* @0x14412c add sp, sp, #36 */
/* @0x144130 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x144134 · F_D3DDrawBlock(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x144134 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x144138 sub sp, sp, #36 */
/* @0x14413c mov r1, #0 */
/* @0x144140 ldr r4, [sp, #0x48] */
/* @0x144144 mov r0, r4 */
/* @0x144148 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14414c mov r1, #1 */
/* @0x144150 mov r5, r0 */
/* @0x144154 mov r0, r4 */
/* @0x144158 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14415c mov r1, #2 */
/* @0x144160 mov r8, r0 */
/* @0x144164 mov r0, r4 */
/* @0x144168 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14416c mov r1, #3 */
/* @0x144170 mov r7, r0 */
/* @0x144174 mov r0, r4 */
/* @0x144178 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14417c mov r1, #4 */
/* @0x144180 mov r6, r0 */
/* @0x144184 mov r0, r4 */
/* @0x144188 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14418c mov r1, #5 */
/* @0x144190 mov r3, r0 */
/* @0x144194 mov r0, r4 */
/* @0x144198 str r3, [sp, #0x1c] */
/* @0x14419c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1441a0 mov r1, #6 */
/* @0x1441a4 mov r11, r0 */
/* @0x1441a8 mov r0, r4 */
/* @0x1441ac bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x1441b0 mov r1, #7 */
/* @0x1441b4 mov r10, r0 */
/* @0x1441b8 mov r0, r4 */
/* @0x1441bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1441c0 mov r1, #8 */
/* @0x1441c4 mov r9, r0 */
/* @0x1441c8 mov r0, r4 */
/* @0x1441cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1441d0 ldr r3, [sp, #0x1c] */
/* @0x1441d4 str r11, [sp, #0x4] */
/* @0x1441d8 mov r1, r8 */
/* @0x1441dc str r10, [sp, #0x8] */
/* @0x1441e0 mov r2, r7 */
/* @0x1441e4 str r3, [sp] */
/* @0x1441e8 mov r3, r6 */
/* @0x1441ec str r9, [sp, #0xc] */
/* @0x1441f0 str r0, [sp, #0x10] */
/* @0x1441f4 mov r0, r5 */
/* @0x1441f8 bl 0x17763c <_Z16GR_3D_Draw_Blockffffffiff> */
/* @0x1441fc add sp, sp, #36 */
/* @0x144200 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x144204 · F_D3DDrawCylinder(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0x144204 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x144208 sub sp, sp, #52 */
/* @0x14420c mov r1, #0 */
/* @0x144210 ldr r4, [sp, #0x58] */
/* @0x144214 mov r0, r4 */
/* @0x144218 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14421c mov r1, #1 */
/* @0x144220 mov r5, r0 */
/* @0x144224 mov r0, r4 */
/* @0x144228 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14422c mov r1, #2 */
/* @0x144230 mov r8, r0 */
/* @0x144234 mov r0, r4 */
/* @0x144238 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14423c mov r1, #3 */
/* @0x144240 mov r7, r0 */
/* @0x144244 mov r0, r4 */
/* @0x144248 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14424c mov r1, #4 */
/* @0x144250 mov r6, r0 */
/* @0x144254 mov r0, r4 */
/* @0x144258 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14425c mov r1, #5 */
/* @0x144260 mov r12, r0 */
/* @0x144264 mov r0, r4 */
/* @0x144268 str r12, [sp, #0x24] */
/* @0x14426c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144270 mov r1, #6 */
/* @0x144274 mov r2, r0 */
/* @0x144278 mov r0, r4 */
/* @0x14427c str r2, [sp, #0x28] */
/* @0x144280 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x144284 mov r1, #7 */
/* @0x144288 mov r3, r0 */
/* @0x14428c mov r0, r4 */
/* @0x144290 str r3, [sp, #0x2c] */
/* @0x144294 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144298 mov r1, #8 */
/* @0x14429c mov r11, r0 */
/* @0x1442a0 mov r0, r4 */
/* @0x1442a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1442a8 mov r1, #9 */
/* @0x1442ac mov r10, r0 */
/* @0x1442b0 mov r0, r4 */
/* @0x1442b4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1442b8 mov r1, #10 */
/* @0x1442bc mov r9, r0 */
/* @0x1442c0 mov r0, r4 */
/* @0x1442c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1442c8 ldr r2, [sp, #0x28] */
/* @0x1442cc ldr r3, [sp, #0x2c] */
/* @0x1442d0 mov r1, r8 */
/* @0x1442d4 ldr r12, [sp, #0x24] */
/* @0x1442d8 str r2, [sp, #0x4] */
/* @0x1442dc mov r2, r7 */
/* @0x1442e0 str r3, [sp, #0x8] */
/* @0x1442e4 mov r3, r6 */
/* @0x1442e8 str r12, [sp] */
/* @0x1442ec str r11, [sp, #0xc] */
/* @0x1442f0 str r10, [sp, #0x10] */
/* @0x1442f4 str r9, [sp, #0x14] */
/* @0x1442f8 str r0, [sp, #0x18] */
/* @0x1442fc mov r0, r5 */
/* @0x144300 bl 0x178d44 <_Z19GR_3D_Draw_Cylinderffffffiffbi> */
/* @0x144304 add sp, sp, #52 */
/* @0x144308 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x14430c · F_D3DDrawCone(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0x14430c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x144310 sub sp, sp, #52 */
/* @0x144314 mov r1, #0 */
/* @0x144318 ldr r4, [sp, #0x58] */
/* @0x14431c mov r0, r4 */
/* @0x144320 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144324 mov r1, #1 */
/* @0x144328 mov r5, r0 */
/* @0x14432c mov r0, r4 */
/* @0x144330 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144334 mov r1, #2 */
/* @0x144338 mov r8, r0 */
/* @0x14433c mov r0, r4 */
/* @0x144340 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144344 mov r1, #3 */
/* @0x144348 mov r7, r0 */
/* @0x14434c mov r0, r4 */
/* @0x144350 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144354 mov r1, #4 */
/* @0x144358 mov r6, r0 */
/* @0x14435c mov r0, r4 */
/* @0x144360 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144364 mov r1, #5 */
/* @0x144368 mov r12, r0 */
/* @0x14436c mov r0, r4 */
/* @0x144370 str r12, [sp, #0x24] */
/* @0x144374 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x144378 mov r1, #6 */
/* @0x14437c mov r2, r0 */
/* @0x144380 mov r0, r4 */
/* @0x144384 str r2, [sp, #0x28] */
/* @0x144388 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei> */
/* @0x14438c mov r1, #7 */
/* @0x144390 mov r3, r0 */
/* @0x144394 mov r0, r4 */
/* @0x144398 str r3, [sp, #0x2c] */
/* @0x14439c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1443a0 mov r1, #8 */
/* @0x1443a4 mov r11, r0 */
/* @0x1443a8 mov r0, r4 */
/* @0x1443ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1443b0 mov r1, #9 */
/* @0x1443b4 mov r10, r0 */
/* @0x1443b8 mov r0, r4 */
/* @0x1443bc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1443c0 mov r1, #10 */
/* @0x1443c4 mov r9, r0 */
/* @0x1443c8 mov r0, r4 */
/* @0x1443cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1443d0 ldr r2, [sp, #0x28] */
/* @0x1443d4 ldr r3, [sp, #0x2c] */
/* @0x1443d8 mov r1, r8 */
/* @0x1443dc ldr r12, [sp, #0x24] */
/* @0x1443e0 str r2, [sp, #0x4] */
/* @0x1443e4 mov r2, r7 */
/* @0x1443e8 str r3, [sp, #0x8] */
/* @0x1443ec mov r3, r6 */
/* @0x1443f0 str r12, [sp] */
/* @0x1443f4 str r11, [sp, #0xc] */
/* @0x1443f8 str r10, [sp, #0x10] */
/* @0x1443fc str r9, [sp, #0x14] */
/* @0x144400 str r0, [sp, #0x18] */
/* @0x144404 mov r0, r5 */
/* @0x144408 bl 0x179094 <_Z15GR_3D_Draw_Coneffffffiffbi> */
/* @0x14440c add sp, sp, #52 */
/* @0x144410 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
