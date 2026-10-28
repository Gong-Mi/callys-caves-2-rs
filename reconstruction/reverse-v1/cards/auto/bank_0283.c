/* libyoyo.so 覆盖卡组 0283
 * 函数 0x2de9bc..0x2e10b8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2de9bc · b2DynamicTree::AllocateNode() · size=240 · insn=60 */
/* @0x2de9bc push {r4, r5, r6, lr} */
/* @0x2de9c0 mov r4, r0 */
/* @0x2de9c4 ldr r5, [r0, #0x10] */
/* @0x2de9c8 cmn r5, #1 */
/* @0x2de9cc beq 0x2dea14 <_ZN13b2DynamicTree12AllocateNodeEv+0x58> */
/* @0x2de9d0 ldr r12, [r4, #0x4] */
/* @0x2de9d4 mov r0, r5 */
/* @0x2de9d8 ldr r2, [r4, #0x8] */
/* @0x2de9dc add r3, r0, r0, lsl #3 */
/* @0x2de9e0 add r5, r2, #1 */
/* @0x2de9e4 mov r1, #0 */
/* @0x2de9e8 mvn r2, #0 */
/* @0x2de9ec add r3, r12, r3, lsl #2 */
/* @0x2de9f0 ldr r12, [r3, #0x14] */
/* @0x2de9f4 str r12, [r4, #0x10] */
/* @0x2de9f8 str r2, [r3, #0x14] */
/* @0x2de9fc str r2, [r3, #0x18] */
/* @0x2dea00 str r2, [r3, #0x1c] */
/* @0x2dea04 str r1, [r3, #0x20] */
/* @0x2dea08 str r1, [r3, #0x10] */
/* @0x2dea0c str r5, [r4, #0x8] */
/* @0x2dea10 pop {r4, r5, r6, pc} */
/* @0x2dea14 ldr r2, [r0, #0xc] */
/* @0x2dea18 ldr r6, [r0, #0x4] */
/* @0x2dea1c lsl r3, r2, #1 */
/* @0x2dea20 str r3, [r0, #0xc] */
/* @0x2dea24 add r0, r3, r2, lsl #4 */
/* @0x2dea28 lsl r0, r0, #2 */
/* @0x2dea2c bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2dea30 ldr r3, [r4, #0x8] */
/* @0x2dea34 mov r1, r6 */
/* @0x2dea38 add r2, r3, r3, lsl #3 */
/* @0x2dea3c lsl r2, r2, #2 */
/* @0x2dea40 str r0, [r4, #0x4] */
/* @0x2dea44 bl 0xb65bc <memcpy@plt> */
/* @0x2dea48 mov r0, r6 */
/* @0x2dea4c bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2dea50 ldr r6, [r4, #0xc] */
/* @0x2dea54 ldr r0, [r4, #0x8] */
/* @0x2dea58 sub r1, r6, #1 */
/* @0x2dea5c ldr r12, [r4, #0x4] */
/* @0x2dea60 cmp r0, r1 */
/* @0x2dea64 addlt r3, r0, r0, lsl #3 */
/* @0x2dea68 movlt r2, r0 */
/* @0x2dea6c addlt r3, r12, r3, lsl #2 */
/* @0x2dea70 bge 0x2dea8c <_ZN13b2DynamicTree12AllocateNodeEv+0xd0> */
/* @0x2dea74 add r2, r2, #1 */
/* @0x2dea78 str r5, [r3, #0x20] */
/* @0x2dea7c cmp r2, r1 */
/* @0x2dea80 str r2, [r3, #0x14] */
/* @0x2dea84 add r3, r3, #36 */
/* @0x2dea88 bne 0x2dea74 <_ZN13b2DynamicTree12AllocateNodeEv+0xb8> */
/* @0x2dea8c add r6, r6, r6, lsl #3 */
/* @0x2dea90 mvn r3, #0 */
/* @0x2dea94 mov r2, r0 */
/* @0x2dea98 add r6, r12, r6, lsl #2 */
/* @0x2dea9c sub r6, r6, #36 */
/* @0x2deaa0 str r3, [r6, #0x14] */
/* @0x2deaa4 str r3, [r6, #0x20] */
/* @0x2deaa8 b 0x2de9dc <_ZN13b2DynamicTree12AllocateNodeEv+0x20> */

/* ── FUNC 0x2deaac · b2DynamicTree::FreeNode(int) · size=56 · insn=14 */
/* @0x2deaac str r4, [sp, #-0x4]! */
/* @0x2deab0 add r4, r1, r1, lsl #3 */
/* @0x2deab4 ldr r3, [r0, #0x4] */
/* @0x2deab8 mvn r12, #0 */
/* @0x2deabc ldr r2, [r0, #0x10] */
/* @0x2deac0 add r3, r3, r4, lsl #2 */
/* @0x2deac4 str r2, [r3, #0x14] */
/* @0x2deac8 ldr r2, [r0, #0x8] */
/* @0x2deacc ldr r4, [sp], #4 */
/* @0x2dead0 str r12, [r3, #0x20] */
/* @0x2dead4 add r3, r2, r12 */
/* @0x2dead8 str r1, [r0, #0x10] */
/* @0x2deadc str r3, [r0, #0x8] */
/* @0x2deae0 bx lr */

/* ── FUNC 0x2deae4 · b2DynamicTree::Balance(int) · size=1260 · insn=315 */
/* @0x2deae4 ldr r12, [r0, #0x4] */
/* @0x2deae8 add r3, r1, r1, lsl #3 */
/* @0x2deaec push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2deaf0 add r3, r12, r3, lsl #2 */
/* @0x2deaf4 ldr r5, [r3, #0x18] */
/* @0x2deaf8 cmn r5, #1 */
/* @0x2deafc beq 0x2dec88 <_ZN13b2DynamicTree7BalanceEi+0x1a4> */
/* @0x2deb00 ldr r2, [r3, #0x20] */
/* @0x2deb04 cmp r2, #1 */
/* @0x2deb08 ble 0x2dec88 <_ZN13b2DynamicTree7BalanceEi+0x1a4> */
/* @0x2deb0c ldr r8, [r3, #0x1c] */
/* @0x2deb10 add r4, r5, r5, lsl #3 */
/* @0x2deb14 add r4, r12, r4, lsl #2 */
/* @0x2deb18 add r2, r8, r8, lsl #3 */
/* @0x2deb1c ldr r9, [r4, #0x20] */
/* @0x2deb20 add r2, r12, r2, lsl #2 */
/* @0x2deb24 ldr r7, [r2, #0x20] */
/* @0x2deb28 rsb r6, r9, r7 */
/* @0x2deb2c cmp r6, #1 */
/* @0x2deb30 ble 0x2ded88 <_ZN13b2DynamicTree7BalanceEi+0x2a4> */
/* @0x2deb34 ldr r6, [r3, #0x14] */
/* @0x2deb38 ldr r5, [r2, #0x18] */
/* @0x2deb3c ldr r10, [r2, #0x1c] */
/* @0x2deb40 str r6, [r2, #0x14] */
/* @0x2deb44 str r1, [r2, #0x18] */
/* @0x2deb48 add r7, r5, r5, lsl #3 */
/* @0x2deb4c str r8, [r3, #0x14] */
/* @0x2deb50 add r6, r10, r10, lsl #3 */
/* @0x2deb54 ldr r11, [r2, #0x14] */
/* @0x2deb58 add r7, r12, r7, lsl #2 */
/* @0x2deb5c add r6, r12, r6, lsl #2 */
/* @0x2deb60 cmn r11, #1 */
/* @0x2deb64 streq r8, [r0] */
/* @0x2deb68 beq 0x2deb84 <_ZN13b2DynamicTree7BalanceEi+0xa0> */
/* @0x2deb6c add r11, r11, r11, lsl #3 */
/* @0x2deb70 add r12, r12, r11, lsl #2 */
/* @0x2deb74 ldr r0, [r12, #0x18] */
/* @0x2deb78 cmp r0, r1 */
/* @0x2deb7c streq r8, [r12, #0x18] */
/* @0x2deb80 strne r8, [r12, #0x1c] */
/* @0x2deb84 ldr r12, [r7, #0x20] */
/* @0x2deb88 ldr r11, [r6, #0x20] */
/* @0x2deb8c cmp r12, r11 */
/* @0x2deb90 ble 0x2dec94 <_ZN13b2DynamicTree7BalanceEi+0x1b0> */
/* @0x2deb94 vldr s14, [r6] */
/* @0x2deb98 str r5, [r2, #0x1c] */
/* @0x2deb9c str r10, [r3, #0x1c] */
/* @0x2deba0 vldr s15, [r6, #4] */
/* @0x2deba4 str r1, [r6, #0x14] */
/* @0x2deba8 vldr s12, [r4] */
/* @0x2debac vcmpe.f32 s12, s14 */
/* @0x2debb0 vldr s13, [r4, #4] */
/* @0x2debb4 mov r0, r8 */
/* @0x2debb8 vmrs APSR_nzcv, fpscr */
/* @0x2debbc vcmpe.f32 s13, s15 */
/* @0x2debc0 vmovmi.f32 s14, s12 */
/* @0x2debc4 vmrs APSR_nzcv, fpscr */
/* @0x2debc8 vstr s14, [r3] */
/* @0x2debcc vmovmi.f32 s15, s13 */
/* @0x2debd0 vstr s15, [r3, #4] */
/* @0x2debd4 vldr s10, [r4, #8] */
/* @0x2debd8 vldr s11, [r6, #8] */
/* @0x2debdc vldr s12, [r4, #12] */
/* @0x2debe0 vldr s13, [r6, #12] */
/* @0x2debe4 vcmpe.f32 s10, s11 */
/* @0x2debe8 vmrs APSR_nzcv, fpscr */
/* @0x2debec vcmpe.f32 s12, s13 */
/* @0x2debf0 vmovgt.f32 s11, s10 */
/* @0x2debf4 vmrs APSR_nzcv, fpscr */
/* @0x2debf8 vstr s11, [r3, #8] */
/* @0x2debfc vmovgt.f32 s13, s12 */
/* @0x2dec00 vstr s13, [r3, #12] */
/* @0x2dec04 vldr s12, [r7] */
/* @0x2dec08 vldr s13, [r7, #4] */
/* @0x2dec0c vcmpe.f32 s14, s12 */
/* @0x2dec10 vmrs APSR_nzcv, fpscr */
/* @0x2dec14 vcmpe.f32 s15, s13 */
/* @0x2dec18 vmovpl.f32 s14, s12 */
/* @0x2dec1c vmrs APSR_nzcv, fpscr */
/* @0x2dec20 vstr s14, [r2] */
/* @0x2dec24 vmovpl.f32 s15, s13 */
/* @0x2dec28 vstr s15, [r2, #4] */
/* @0x2dec2c vldr s13, [r7, #8] */
/* @0x2dec30 vldr s12, [r3, #8] */
/* @0x2dec34 vldr s15, [r7, #12] */
/* @0x2dec38 vldr s14, [r3, #12] */
/* @0x2dec3c vcmpe.f32 s12, s13 */
/* @0x2dec40 vmrs APSR_nzcv, fpscr */
/* @0x2dec44 vcmpe.f32 s14, s15 */
/* @0x2dec48 vmovgt.f32 s13, s12 */
/* @0x2dec4c vmrs APSR_nzcv, fpscr */
/* @0x2dec50 vstr s13, [r2, #8] */
/* @0x2dec54 vmovgt.f32 s15, s14 */
/* @0x2dec58 cmp r9, r11 */
/* @0x2dec5c movlt r9, r11 */
/* @0x2dec60 add r9, r9, #1 */
/* @0x2dec64 vstr s15, [r2, #12] */
/* @0x2dec68 str r9, [r3, #0x20] */
/* @0x2dec6c ldr r3, [r7, #0x20] */
/* @0x2dec70 cmp r9, r3 */
/* @0x2dec74 movlt r9, r3 */
/* @0x2dec78 add r9, r9, #1 */
/* @0x2dec7c str r9, [r2, #0x20] */
/* @0x2dec80 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2dec84 bx lr */
/* @0x2dec88 mov r0, r1 */
/* @0x2dec8c pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2dec90 bx lr */
/* @0x2dec94 vldr s14, [r7] */
/* @0x2dec98 str r10, [r2, #0x1c] */
/* @0x2dec9c str r5, [r3, #0x1c] */
/* @0x2deca0 vldr s15, [r7, #4] */
/* @0x2deca4 str r1, [r7, #0x14] */
/* @0x2deca8 vldr s12, [r4] */
/* @0x2decac vcmpe.f32 s12, s14 */
/* @0x2decb0 vldr s13, [r4, #4] */
/* @0x2decb4 mov r0, r8 */
/* @0x2decb8 vmrs APSR_nzcv, fpscr */
/* @0x2decbc vcmpe.f32 s13, s15 */
/* @0x2decc0 vmovmi.f32 s14, s12 */
/* @0x2decc4 vmrs APSR_nzcv, fpscr */
/* @0x2decc8 vstr s14, [r3] */
/* @0x2deccc vmovmi.f32 s15, s13 */
/* @0x2decd0 vstr s15, [r3, #4] */
/* @0x2decd4 vldr s10, [r4, #8] */
/* @0x2decd8 vldr s11, [r7, #8] */
/* @0x2decdc vldr s12, [r4, #12] */
/* @0x2dece0 vldr s13, [r7, #12] */
/* @0x2dece4 vcmpe.f32 s10, s11 */
/* @0x2dece8 vmrs APSR_nzcv, fpscr */
/* @0x2decec vcmpe.f32 s12, s13 */
/* @0x2decf0 vmovgt.f32 s11, s10 */
/* @0x2decf4 vmrs APSR_nzcv, fpscr */
/* @0x2decf8 vstr s11, [r3, #8] */
/* @0x2decfc vmovgt.f32 s13, s12 */
/* @0x2ded00 vstr s13, [r3, #12] */
/* @0x2ded04 vldr s12, [r6] */
/* @0x2ded08 vldr s13, [r6, #4] */
/* @0x2ded0c vcmpe.f32 s14, s12 */
/* @0x2ded10 vmrs APSR_nzcv, fpscr */
/* @0x2ded14 vcmpe.f32 s15, s13 */
/* @0x2ded18 vmovpl.f32 s14, s12 */
/* @0x2ded1c vmrs APSR_nzcv, fpscr */
/* @0x2ded20 vstr s14, [r2] */
/* @0x2ded24 vmovpl.f32 s15, s13 */
/* @0x2ded28 vstr s15, [r2, #4] */
/* @0x2ded2c vldr s13, [r6, #8] */
/* @0x2ded30 vldr s12, [r3, #8] */
/* @0x2ded34 vldr s15, [r6, #12] */
/* @0x2ded38 vldr s14, [r3, #12] */
/* @0x2ded3c vcmpe.f32 s12, s13 */
/* @0x2ded40 vmrs APSR_nzcv, fpscr */
/* @0x2ded44 vcmpe.f32 s14, s15 */
/* @0x2ded48 vmovgt.f32 s13, s12 */
/* @0x2ded4c vmrs APSR_nzcv, fpscr */
/* @0x2ded50 vstr s13, [r2, #8] */
/* @0x2ded54 vmovgt.f32 s15, s14 */
/* @0x2ded58 cmp r12, r9 */
/* @0x2ded5c movlt r12, r9 */
/* @0x2ded60 add r12, r12, #1 */
/* @0x2ded64 vstr s15, [r2, #12] */
/* @0x2ded68 str r12, [r3, #0x20] */
/* @0x2ded6c ldr r3, [r6, #0x20] */
/* @0x2ded70 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2ded74 cmp r12, r3 */
/* @0x2ded78 movlt r12, r3 */
/* @0x2ded7c add r12, r12, #1 */
/* @0x2ded80 str r12, [r2, #0x20] */
/* @0x2ded84 bx lr */
/* @0x2ded88 cmn r6, #1 */
/* @0x2ded8c bge 0x2dec88 <_ZN13b2DynamicTree7BalanceEi+0x1a4> */
/* @0x2ded90 ldr r6, [r3, #0x14] */
/* @0x2ded94 ldr r9, [r4, #0x18] */
/* @0x2ded98 ldr r10, [r4, #0x1c] */
/* @0x2ded9c str r6, [r4, #0x14] */
/* @0x2deda0 str r1, [r4, #0x18] */
/* @0x2deda4 add r8, r9, r9, lsl #3 */
/* @0x2deda8 str r5, [r3, #0x14] */
/* @0x2dedac add r6, r10, r10, lsl #3 */
/* @0x2dedb0 ldr r11, [r4, #0x14] */
/* @0x2dedb4 add r8, r12, r8, lsl #2 */
/* @0x2dedb8 add r6, r12, r6, lsl #2 */
/* @0x2dedbc cmn r11, #1 */
/* @0x2dedc0 streq r5, [r0] */
/* @0x2dedc4 beq 0x2dede0 <_ZN13b2DynamicTree7BalanceEi+0x2fc> */
/* @0x2dedc8 add r11, r11, r11, lsl #3 */
/* @0x2dedcc add r12, r12, r11, lsl #2 */
/* @0x2dedd0 ldr r0, [r12, #0x18] */
/* @0x2dedd4 cmp r0, r1 */
/* @0x2dedd8 streq r5, [r12, #0x18] */
/* @0x2deddc strne r5, [r12, #0x1c] */
/* @0x2dede0 ldr r12, [r8, #0x20] */
/* @0x2dede4 ldr r11, [r6, #0x20] */
/* @0x2dede8 cmp r12, r11 */
/* @0x2dedec ble 0x2deee0 <_ZN13b2DynamicTree7BalanceEi+0x3fc> */
/* @0x2dedf0 vldr s14, [r6] */
/* @0x2dedf4 str r9, [r4, #0x1c] */
/* @0x2dedf8 str r10, [r3, #0x18] */
/* @0x2dedfc vldr s15, [r6, #4] */
/* @0x2dee00 str r1, [r6, #0x14] */
/* @0x2dee04 vldr s12, [r2] */
/* @0x2dee08 vcmpe.f32 s12, s14 */
/* @0x2dee0c vldr s13, [r2, #4] */
/* @0x2dee10 mov r0, r5 */
/* @0x2dee14 vmrs APSR_nzcv, fpscr */
/* @0x2dee18 vcmpe.f32 s13, s15 */
/* @0x2dee1c vmovmi.f32 s14, s12 */
/* @0x2dee20 vmrs APSR_nzcv, fpscr */
/* @0x2dee24 vstr s14, [r3] */
/* @0x2dee28 vmovmi.f32 s15, s13 */
/* @0x2dee2c vstr s15, [r3, #4] */
/* @0x2dee30 vldr s10, [r2, #8] */
/* @0x2dee34 vldr s11, [r6, #8] */
/* @0x2dee38 vldr s12, [r2, #12] */
/* @0x2dee3c vldr s13, [r6, #12] */
/* @0x2dee40 vcmpe.f32 s10, s11 */
/* @0x2dee44 vmrs APSR_nzcv, fpscr */
/* @0x2dee48 vcmpe.f32 s12, s13 */
/* @0x2dee4c vmovgt.f32 s11, s10 */
/* @0x2dee50 vmrs APSR_nzcv, fpscr */
/* @0x2dee54 vstr s11, [r3, #8] */
/* @0x2dee58 vmovgt.f32 s13, s12 */
/* @0x2dee5c vstr s13, [r3, #12] */
/* @0x2dee60 vldr s12, [r8] */
/* @0x2dee64 vldr s13, [r8, #4] */
/* @0x2dee68 vcmpe.f32 s14, s12 */
/* @0x2dee6c vmrs APSR_nzcv, fpscr */
/* @0x2dee70 vcmpe.f32 s15, s13 */
/* @0x2dee74 vmovpl.f32 s14, s12 */
/* @0x2dee78 vmrs APSR_nzcv, fpscr */
/* @0x2dee7c vstr s14, [r4] */
/* @0x2dee80 vmovpl.f32 s15, s13 */
/* @0x2dee84 vstr s15, [r4, #4] */
/* @0x2dee88 vldr s12, [r3, #8] */
/* @0x2dee8c vldr s13, [r8, #8] */
/* @0x2dee90 vldr s14, [r3, #12] */
/* @0x2dee94 vldr s15, [r8, #12] */
/* @0x2dee98 vcmpe.f32 s12, s13 */
/* @0x2dee9c vmrs APSR_nzcv, fpscr */
/* @0x2deea0 vcmpe.f32 s14, s15 */
/* @0x2deea4 vmovgt.f32 s13, s12 */
/* @0x2deea8 vmrs APSR_nzcv, fpscr */
/* @0x2deeac vstr s13, [r4, #8] */
/* @0x2deeb0 vmovgt.f32 s15, s14 */
/* @0x2deeb4 cmp r7, r11 */
/* @0x2deeb8 movlt r7, r11 */
/* @0x2deebc add r7, r7, #1 */
/* @0x2deec0 vstr s15, [r4, #12] */
/* @0x2deec4 str r7, [r3, #0x20] */
/* @0x2deec8 ldr r3, [r8, #0x20] */
/* @0x2deecc cmp r7, r3 */
/* @0x2deed0 movlt r7, r3 */
/* @0x2deed4 add r7, r7, #1 */
/* @0x2deed8 str r7, [r4, #0x20] */
/* @0x2deedc b 0x2dec8c <_ZN13b2DynamicTree7BalanceEi+0x1a8> */
/* @0x2deee0 vldr s14, [r8] */
/* @0x2deee4 str r10, [r4, #0x1c] */
/* @0x2deee8 str r9, [r3, #0x18] */
/* @0x2deeec vldr s15, [r8, #4] */
/* @0x2deef0 str r1, [r8, #0x14] */
/* @0x2deef4 vldr s12, [r2] */
/* @0x2deef8 vcmpe.f32 s12, s14 */
/* @0x2deefc vldr s13, [r2, #4] */
/* @0x2def00 mov r0, r5 */
/* @0x2def04 vmrs APSR_nzcv, fpscr */
/* @0x2def08 vcmpe.f32 s13, s15 */
/* @0x2def0c vmovmi.f32 s14, s12 */
/* @0x2def10 vmrs APSR_nzcv, fpscr */
/* @0x2def14 vstr s14, [r3] */
/* @0x2def18 vmovmi.f32 s15, s13 */
/* @0x2def1c vstr s15, [r3, #4] */
/* @0x2def20 vldr s10, [r2, #8] */
/* @0x2def24 vldr s11, [r8, #8] */
/* @0x2def28 vldr s12, [r2, #12] */
/* @0x2def2c vldr s13, [r8, #12] */
/* @0x2def30 vcmpe.f32 s10, s11 */
/* @0x2def34 vmrs APSR_nzcv, fpscr */
/* @0x2def38 vcmpe.f32 s12, s13 */
/* @0x2def3c vmovgt.f32 s11, s10 */
/* @0x2def40 vmrs APSR_nzcv, fpscr */
/* @0x2def44 vstr s11, [r3, #8] */
/* @0x2def48 vmovgt.f32 s13, s12 */
/* @0x2def4c vstr s13, [r3, #12] */
/* @0x2def50 vldr s12, [r6] */
/* @0x2def54 vldr s13, [r6, #4] */
/* @0x2def58 vcmpe.f32 s14, s12 */
/* @0x2def5c vmrs APSR_nzcv, fpscr */
/* @0x2def60 vcmpe.f32 s15, s13 */
/* @0x2def64 vmovpl.f32 s14, s12 */
/* @0x2def68 vmrs APSR_nzcv, fpscr */
/* @0x2def6c vstr s14, [r4] */
/* @0x2def70 vmovpl.f32 s15, s13 */
/* @0x2def74 vstr s15, [r4, #4] */
/* @0x2def78 vldr s12, [r3, #8] */
/* @0x2def7c vldr s13, [r6, #8] */
/* @0x2def80 vldr s14, [r3, #12] */
/* @0x2def84 vldr s15, [r6, #12] */
/* @0x2def88 vcmpe.f32 s12, s13 */
/* @0x2def8c vmrs APSR_nzcv, fpscr */
/* @0x2def90 vcmpe.f32 s14, s15 */
/* @0x2def94 vmovgt.f32 s13, s12 */
/* @0x2def98 vmrs APSR_nzcv, fpscr */
/* @0x2def9c vstr s13, [r4, #8] */
/* @0x2defa0 vmovgt.f32 s15, s14 */
/* @0x2defa4 cmp r12, r7 */
/* @0x2defa8 movlt r12, r7 */
/* @0x2defac add r12, r12, #1 */
/* @0x2defb0 vstr s15, [r4, #12] */
/* @0x2defb4 str r12, [r3, #0x20] */
/* @0x2defb8 ldr r3, [r6, #0x20] */
/* @0x2defbc cmp r12, r3 */
/* @0x2defc0 movlt r12, r3 */
/* @0x2defc4 add r12, r12, #1 */
/* @0x2defc8 str r12, [r4, #0x20] */
/* @0x2defcc b 0x2dec8c <_ZN13b2DynamicTree7BalanceEi+0x1a8> */

/* ── FUNC 0x2defd0 · b2DynamicTree::InsertLeaf(int) · size=1180 · insn=295 */
/* @0x2defd0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2defd4 vpush {d8, d9} */
/* @0x2defd8 mov r6, r0 */
/* @0x2defdc ldr r4, [r0] */
/* @0x2defe0 mov r8, r1 */
/* @0x2defe4 ldr r3, [r0, #0x18] */
/* @0x2defe8 cmn r4, #1 */
/* @0x2defec add r3, r3, #1 */
/* @0x2deff0 str r3, [r0, #0x18] */
/* @0x2deff4 beq 0x2df450 <_ZN13b2DynamicTree10InsertLeafEi+0x480> */
/* @0x2deff8 lsl r7, r4, #3 */
/* @0x2deffc ldr r5, [r0, #0x4] */
/* @0x2df000 add r2, r7, r4 */
/* @0x2df004 add r9, r1, r1, lsl #3 */
/* @0x2df008 add r2, r5, r2, lsl #2 */
/* @0x2df00c lsl r9, r9, #2 */
/* @0x2df010 add r3, r5, r9 */
/* @0x2df014 vldr s16, [r3] */
/* @0x2df018 ldr r12, [r2, #0x18] */
/* @0x2df01c vldr s19, [r3, #4] */
/* @0x2df020 vldr s18, [r3, #8] */
/* @0x2df024 vldr s17, [r3, #12] */
/* @0x2df028 b 0x2df160 <_ZN13b2DynamicTree10InsertLeafEi+0x190> */
/* @0x2df02c vcmpe.f32 s16, s13 */
/* @0x2df030 vldr s12, [r2, #4] */
/* @0x2df034 vldr s10, [r2, #8] */
/* @0x2df038 vldr s11, [r2, #12] */
/* @0x2df03c vmrs APSR_nzcv, fpscr */
/* @0x2df040 vcmpe.f32 s12, s19 */
/* @0x2df044 vmovpl.f32 s8, s13 */
/* @0x2df048 vmovmi.f32 s8, s16 */
/* @0x2df04c vmrs APSR_nzcv, fpscr */
/* @0x2df050 vcmpe.f32 s10, s18 */
/* @0x2df054 vmovle.f32 s7, s12 */
/* @0x2df058 vmovgt.f32 s7, s19 */
/* @0x2df05c vmrs APSR_nzcv, fpscr */
/* @0x2df060 vcmpe.f32 s11, s17 */
/* @0x2df064 vmovpl.f32 s6, s10 */
/* @0x2df068 vmovmi.f32 s6, s18 */
/* @0x2df06c vmrs APSR_nzcv, fpscr */
/* @0x2df070 vmovpl.f32 s9, s11 */
/* @0x2df074 vmovmi.f32 s9, s17 */
/* @0x2df078 vsub.f32 s13, s10, s13 */
/* @0x2df07c vsub.f32 s8, s6, s8 */
/* @0x2df080 vsub.f32 s12, s11, s12 */
/* @0x2df084 vsub.f32 s9, s9, s7 */
/* @0x2df088 vadd.f32 s13, s13, s12 */
/* @0x2df08c vadd.f32 s9, s8, s9 */
/* @0x2df090 vadd.f32 s13, s13, s13 */
/* @0x2df094 vadd.f32 s9, s9, s9 */
/* @0x2df098 vsub.f32 s13, s9, s13 */
/* @0x2df09c vadd.f32 s13, s13, s14 */
/* @0x2df0a0 add r2, lr, lr, lsl #3 */
/* @0x2df0a4 add r2, r5, r2, lsl #2 */
/* @0x2df0a8 ldr r1, [r2, #0x18] */
/* @0x2df0ac cmn r1, #1 */
/* @0x2df0b0 beq 0x2df260 <_ZN13b2DynamicTree10InsertLeafEi+0x290> */
/* @0x2df0b4 vldr s10, [r2] */
/* @0x2df0b8 vcmpe.f32 s16, s10 */
/* @0x2df0bc vldr s12, [r2, #4] */
/* @0x2df0c0 vldr s9, [r2, #8] */
/* @0x2df0c4 vldr s11, [r2, #12] */
/* @0x2df0c8 vmrs APSR_nzcv, fpscr */
/* @0x2df0cc vcmpe.f32 s12, s19 */
/* @0x2df0d0 vmovpl.f32 s7, s10 */
/* @0x2df0d4 vmovmi.f32 s7, s16 */
/* @0x2df0d8 vmrs APSR_nzcv, fpscr */
/* @0x2df0dc vcmpe.f32 s9, s18 */
/* @0x2df0e0 vmovle.f32 s6, s12 */
/* @0x2df0e4 vmovgt.f32 s6, s19 */
/* @0x2df0e8 vmrs APSR_nzcv, fpscr */
/* @0x2df0ec vcmpe.f32 s11, s17 */
/* @0x2df0f0 vmovpl.f32 s5, s9 */
/* @0x2df0f4 vmovmi.f32 s5, s18 */
/* @0x2df0f8 vmrs APSR_nzcv, fpscr */
/* @0x2df0fc vmovpl.f32 s8, s11 */
/* @0x2df100 vmovmi.f32 s8, s17 */
/* @0x2df104 vsub.f32 s10, s9, s10 */
/* @0x2df108 vsub.f32 s7, s5, s7 */
/* @0x2df10c vsub.f32 s12, s11, s12 */
/* @0x2df110 vsub.f32 s8, s8, s6 */
/* @0x2df114 vadd.f32 s12, s10, s12 */
/* @0x2df118 vadd.f32 s8, s7, s8 */
/* @0x2df11c vadd.f32 s12, s12, s12 */
/* @0x2df120 vadd.f32 s8, s8, s8 */
/* @0x2df124 vsub.f32 s12, s8, s12 */
/* @0x2df128 vadd.f32 s14, s12, s14 */
/* @0x2df12c vcmpe.f32 s13, s15 */
/* @0x2df130 vmrs APSR_nzcv, fpscr */
/* @0x2df134 ble 0x2df144 <_ZN13b2DynamicTree10InsertLeafEi+0x174> */
/* @0x2df138 vcmpe.f32 s14, s15 */
/* @0x2df13c vmrs APSR_nzcv, fpscr */
/* @0x2df140 bgt 0x2df2b8 <_ZN13b2DynamicTree10InsertLeafEi+0x2e8> */
/* @0x2df144 vcmpe.f32 s13, s14 */
/* @0x2df148 vmrs APSR_nzcv, fpscr */
/* @0x2df14c movmi lr, r12 */
/* @0x2df150 movmi r1, r0 */
/* @0x2df154 lsl r7, lr, #3 */
/* @0x2df158 mov r4, lr */
/* @0x2df15c mov r12, r1 */
/* @0x2df160 add r7, r7, r4 */
/* @0x2df164 cmn r12, #1 */
/* @0x2df168 lsl r7, r7, #2 */
/* @0x2df16c add r3, r5, r7 */
/* @0x2df170 beq 0x2df2b8 <_ZN13b2DynamicTree10InsertLeafEi+0x2e8> */
/* @0x2df174 vldr s12, [r3] */
/* @0x2df178 vcmpe.f32 s16, s12 */
/* @0x2df17c vldr s14, [r3, #4] */
/* @0x2df180 vldr s11, [r3, #8] */
/* @0x2df184 vldr s13, [r3, #12] */
/* @0x2df188 add r2, r12, r12, lsl #3 */
/* @0x2df18c ldr lr, [r3, #0x1c] */
/* @0x2df190 vmrs APSR_nzcv, fpscr */
/* @0x2df194 vcmpe.f32 s14, s19 */
/* @0x2df198 add r2, r5, r2, lsl #2 */
/* @0x2df19c ldr r0, [r2, #0x18] */
/* @0x2df1a0 vmovle.f32 s10, s16 */
/* @0x2df1a4 vmovgt.f32 s10, s12 */
/* @0x2df1a8 vmrs APSR_nzcv, fpscr */
/* @0x2df1ac vcmpe.f32 s11, s18 */
/* @0x2df1b0 vmovpl.f32 s9, s19 */
/* @0x2df1b4 vmovmi.f32 s9, s14 */
/* @0x2df1b8 vmrs APSR_nzcv, fpscr */
/* @0x2df1bc vcmpe.f32 s13, s17 */
/* @0x2df1c0 vmovle.f32 s8, s18 */
/* @0x2df1c4 vmovgt.f32 s8, s11 */
/* @0x2df1c8 vmrs APSR_nzcv, fpscr */
/* @0x2df1cc vmovle.f32 s15, s17 */
/* @0x2df1d0 vmovgt.f32 s15, s13 */
/* @0x2df1d4 cmn r0, #1 */
/* @0x2df1d8 vsub.f32 s14, s13, s14 */
/* @0x2df1dc vldr s13, [r2] */
/* @0x2df1e0 vsub.f32 s12, s11, s12 */
/* @0x2df1e4 vsub.f32 s10, s8, s10 */
/* @0x2df1e8 vsub.f32 s15, s15, s9 */
/* @0x2df1ec vadd.f32 s14, s12, s14 */
/* @0x2df1f0 vadd.f32 s15, s10, s15 */
/* @0x2df1f4 vadd.f32 s14, s14, s14 */
/* @0x2df1f8 vadd.f32 s15, s15, s15 */
/* @0x2df1fc vsub.f32 s14, s15, s14 */
/* @0x2df200 vadd.f32 s15, s15, s15 */
/* @0x2df204 vadd.f32 s14, s14, s14 */
/* @0x2df208 bne 0x2df02c <_ZN13b2DynamicTree10InsertLeafEi+0x5c> */
/* @0x2df20c vldr s10, [r2, #4] */
/* @0x2df210 vldr s11, [r2, #8] */
/* @0x2df214 vldr s12, [r2, #12] */
/* @0x2df218 vcmpe.f32 s16, s13 */
/* @0x2df21c vmrs APSR_nzcv, fpscr */
/* @0x2df220 vcmpe.f32 s10, s19 */
/* @0x2df224 vmovmi.f32 s13, s16 */
/* @0x2df228 vmrs APSR_nzcv, fpscr */
/* @0x2df22c vcmpe.f32 s11, s18 */
/* @0x2df230 vmovgt.f32 s10, s19 */
/* @0x2df234 vmrs APSR_nzcv, fpscr */
/* @0x2df238 vcmpe.f32 s12, s17 */
/* @0x2df23c vmovmi.f32 s11, s18 */
/* @0x2df240 vmrs APSR_nzcv, fpscr */
/* @0x2df244 vmovmi.f32 s12, s17 */
/* @0x2df248 vsub.f32 s13, s11, s13 */
/* @0x2df24c vsub.f32 s12, s12, s10 */
/* @0x2df250 vadd.f32 s13, s13, s12 */
/* @0x2df254 vadd.f32 s13, s13, s13 */
/* @0x2df258 vadd.f32 s13, s14, s13 */
/* @0x2df25c b 0x2df0a0 <_ZN13b2DynamicTree10InsertLeafEi+0xd0> */
/* @0x2df260 vldr s12, [r2] */
/* @0x2df264 vcmpe.f32 s16, s12 */
/* @0x2df268 vldr s9, [r2, #4] */
/* @0x2df26c vldr s10, [r2, #8] */
/* @0x2df270 vldr s11, [r2, #12] */
/* @0x2df274 vmrs APSR_nzcv, fpscr */
/* @0x2df278 vcmpe.f32 s9, s19 */
/* @0x2df27c vmovmi.f32 s12, s16 */
/* @0x2df280 vmrs APSR_nzcv, fpscr */
/* @0x2df284 vcmpe.f32 s10, s18 */
/* @0x2df288 vmovgt.f32 s9, s19 */
/* @0x2df28c vmrs APSR_nzcv, fpscr */
/* @0x2df290 vcmpe.f32 s11, s17 */
/* @0x2df294 vmovmi.f32 s10, s18 */
/* @0x2df298 vmrs APSR_nzcv, fpscr */
/* @0x2df29c vmovmi.f32 s11, s17 */
/* @0x2df2a0 vsub.f32 s12, s10, s12 */
/* @0x2df2a4 vsub.f32 s11, s11, s9 */
/* @0x2df2a8 vadd.f32 s12, s12, s11 */
/* @0x2df2ac vadd.f32 s12, s12, s12 */
/* @0x2df2b0 vadd.f32 s14, s14, s12 */
/* @0x2df2b4 b 0x2df12c <_ZN13b2DynamicTree10InsertLeafEi+0x15c> */
/* @0x2df2b8 mov r0, r6 */
/* @0x2df2bc ldr r5, [r3, #0x14] */
/* @0x2df2c0 bl 0x2de9bc <_ZN13b2DynamicTree12AllocateNodeEv> */
/* @0x2df2c4 ldr r2, [r6, #0x4] */
/* @0x2df2c8 mov r12, #0 */
/* @0x2df2cc add r7, r2, r7 */
/* @0x2df2d0 add r3, r0, r0, lsl #3 */
/* @0x2df2d4 mov r1, r0 */
/* @0x2df2d8 ldr r0, [r7, #0x20] */
/* @0x2df2dc add r3, r2, r3, lsl #2 */
/* @0x2df2e0 add r0, r0, #1 */
/* @0x2df2e4 str r5, [r3, #0x14] */
/* @0x2df2e8 vldr s14, [r7] */
/* @0x2df2ec vcmpe.f32 s16, s14 */
/* @0x2df2f0 vldr s15, [r7, #4] */
/* @0x2df2f4 str r12, [r3, #0x10] */
/* @0x2df2f8 vmrs APSR_nzcv, fpscr */
/* @0x2df2fc vcmpe.f32 s15, s19 */
/* @0x2df300 vmovpl.f32 s16, s14 */
/* @0x2df304 vmrs APSR_nzcv, fpscr */
/* @0x2df308 vstr s16, [r3] */
/* @0x2df30c vmovle.f32 s19, s15 */
/* @0x2df310 vstr s19, [r3, #4] */
/* @0x2df314 vldr s14, [r7, #8] */
/* @0x2df318 vldr s15, [r7, #12] */
/* @0x2df31c str r0, [r3, #0x20] */
/* @0x2df320 vcmpe.f32 s14, s18 */
/* @0x2df324 vmrs APSR_nzcv, fpscr */
/* @0x2df328 vcmpe.f32 s15, s17 */
/* @0x2df32c vmovpl.f32 s18, s14 */
/* @0x2df330 vmrs APSR_nzcv, fpscr */
/* @0x2df334 vstr s18, [r3, #8] */
/* @0x2df338 vmovpl.f32 s17, s15 */
/* @0x2df33c cmn r5, #1 */
/* @0x2df340 vstr s17, [r3, #12] */
/* @0x2df344 beq 0x2df434 <_ZN13b2DynamicTree10InsertLeafEi+0x464> */
/* @0x2df348 add r5, r5, r5, lsl #3 */
/* @0x2df34c add r5, r2, r5, lsl #2 */
/* @0x2df350 add r2, r2, r9 */
/* @0x2df354 ldr r0, [r5, #0x18] */
/* @0x2df358 cmp r4, r0 */
/* @0x2df35c streq r1, [r5, #0x18] */
/* @0x2df360 strne r1, [r5, #0x1c] */
/* @0x2df364 str r4, [r3, #0x18] */
/* @0x2df368 str r8, [r3, #0x1c] */
/* @0x2df36c str r1, [r7, #0x14] */
/* @0x2df370 str r1, [r2, #0x14] */
/* @0x2df374 cmn r1, #1 */
/* @0x2df378 beq 0x2df42c <_ZN13b2DynamicTree10InsertLeafEi+0x45c> */
/* @0x2df37c mov r0, r6 */
/* @0x2df380 bl 0x2deae4 <_ZN13b2DynamicTree7BalanceEi> */
/* @0x2df384 ldr r4, [r6, #0x4] */
/* @0x2df388 add r0, r0, r0, lsl #3 */
/* @0x2df38c add r3, r4, r0, lsl #2 */
/* @0x2df390 ldr r12, [r3, #0x18] */
/* @0x2df394 ldr r2, [r3, #0x1c] */
/* @0x2df398 ldr r1, [r3, #0x14] */
/* @0x2df39c add r12, r12, r12, lsl #3 */
/* @0x2df3a0 add r2, r2, r2, lsl #3 */
/* @0x2df3a4 add r12, r4, r12, lsl #2 */
/* @0x2df3a8 vldr s12, [r12] */
/* @0x2df3ac add r2, r4, r2, lsl #2 */
/* @0x2df3b0 vldr s13, [r2] */
/* @0x2df3b4 vcmpe.f32 s12, s13 */
/* @0x2df3b8 ldr r0, [r12, #0x20] */
/* @0x2df3bc ldr r4, [r2, #0x20] */
/* @0x2df3c0 vldr s14, [r12, #4] */
/* @0x2df3c4 vldr s15, [r2, #4] */
/* @0x2df3c8 cmp r0, r4 */
/* @0x2df3cc movlt r0, r4 */
/* @0x2df3d0 vmrs APSR_nzcv, fpscr */
/* @0x2df3d4 vcmpe.f32 s14, s15 */
/* @0x2df3d8 add r0, r0, #1 */
/* @0x2df3dc str r0, [r3, #0x20] */
/* @0x2df3e0 vmovmi.f32 s13, s12 */
/* @0x2df3e4 vmrs APSR_nzcv, fpscr */
/* @0x2df3e8 vstr s13, [r3] */
/* @0x2df3ec vmovmi.f32 s15, s14 */
/* @0x2df3f0 vstr s15, [r3, #4] */
/* @0x2df3f4 vldr s12, [r12, #8] */
/* @0x2df3f8 vldr s13, [r2, #8] */
/* @0x2df3fc vldr s14, [r12, #12] */
/* @0x2df400 vldr s15, [r2, #12] */
/* @0x2df404 vcmpe.f32 s12, s13 */
/* @0x2df408 vmrs APSR_nzcv, fpscr */
/* @0x2df40c vcmpe.f32 s14, s15 */
/* @0x2df410 vmovgt.f32 s13, s12 */
/* @0x2df414 vmrs APSR_nzcv, fpscr */
/* @0x2df418 vstr s13, [r3, #8] */
/* @0x2df41c vmovgt.f32 s15, s14 */
/* @0x2df420 cmn r1, #1 */
/* @0x2df424 vstr s15, [r3, #12] */
/* @0x2df428 bne 0x2df37c <_ZN13b2DynamicTree10InsertLeafEi+0x3ac> */
/* @0x2df42c vpop {d8, d9} */
/* @0x2df430 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2df434 add r2, r2, r9 */
/* @0x2df438 str r4, [r3, #0x18] */
/* @0x2df43c str r8, [r3, #0x1c] */
/* @0x2df440 str r1, [r7, #0x14] */
/* @0x2df444 str r1, [r2, #0x14] */
/* @0x2df448 str r1, [r6] */
/* @0x2df44c b 0x2df374 <_ZN13b2DynamicTree10InsertLeafEi+0x3a4> */
/* @0x2df450 ldr r3, [r0, #0x4] */
/* @0x2df454 add r2, r1, r1, lsl #3 */
/* @0x2df458 str r1, [r6] */
/* @0x2df45c add r3, r3, r2, lsl #2 */
/* @0x2df460 str r4, [r3, #0x14] */
/* @0x2df464 vpop {d8, d9} */
/* @0x2df468 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2df46c · b2DynamicTree::CreateProxy(b2AABB const&, void*) · size=124 · insn=31 */
/* @0x2df46c push {r3, r4, r5, r6, r7, lr} */
/* @0x2df470 mov r4, r1 */
/* @0x2df474 mov r7, r2 */
/* @0x2df478 mov r6, r0 */
/* @0x2df47c bl 0x2de9bc <_ZN13b2DynamicTree12AllocateNodeEv> */
/* @0x2df480 vldr s14, [r4, #4] */
/* @0x2df484 vldr s13, [r4] */
/* @0x2df488 vldr s15, [pc, #84] */
/* @0x2df48c vsub.f32 s13, s13, s15 */
/* @0x2df490 ldr r3, [r6, #0x4] */
/* @0x2df494 mov r2, #0 */
/* @0x2df498 vsub.f32 s14, s14, s15 */
/* @0x2df49c mov r5, r0 */
/* @0x2df4a0 mov r0, r6 */
/* @0x2df4a4 add r12, r5, r5, lsl #3 */
/* @0x2df4a8 mov r1, r5 */
/* @0x2df4ac add r3, r3, r12, lsl #2 */
/* @0x2df4b0 vstr s13, [r3] */
/* @0x2df4b4 vstr s14, [r3, #4] */
/* @0x2df4b8 vldr s14, [r4, #12] */
/* @0x2df4bc vldr s13, [r4, #8] */
/* @0x2df4c0 vadd.f32 s14, s14, s15 */
/* @0x2df4c4 str r7, [r3, #0x10] */
/* @0x2df4c8 str r2, [r3, #0x20] */
/* @0x2df4cc vadd.f32 s15, s13, s15 */
/* @0x2df4d0 vstr s14, [r3, #12] */
/* @0x2df4d4 vstr s15, [r3, #8] */
/* @0x2df4d8 bl 0x2defd0 <_ZN13b2DynamicTree10InsertLeafEi> */
/* @0x2df4dc mov r0, r5 */
/* @0x2df4e0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2df4e4 stcllo p12, c12, [r12, #820] */

/* ── FUNC 0x2df4e8 · b2DynamicTree::RemoveLeaf(int) · size=344 · insn=86 */
/* @0x2df4e8 ldr r3, [r0] */
/* @0x2df4ec push {r4, r5, r6, lr} */
/* @0x2df4f0 cmp r3, r1 */
/* @0x2df4f4 mov r6, r0 */
/* @0x2df4f8 mvneq r3, #0 */
/* @0x2df4fc streq r3, [r0] */
/* @0x2df500 popeq {r4, r5, r6, pc} */
/* @0x2df504 ldr r2, [r0, #0x4] */
/* @0x2df508 add r3, r1, r1, lsl #3 */
/* @0x2df50c add r3, r2, r3, lsl #2 */
/* @0x2df510 ldr r12, [r3, #0x14] */
/* @0x2df514 add r0, r12, r12, lsl #3 */
/* @0x2df518 add r0, r2, r0, lsl #2 */
/* @0x2df51c ldr r3, [r0, #0x18] */
/* @0x2df520 ldr r5, [r0, #0x14] */
/* @0x2df524 cmp r3, r1 */
/* @0x2df528 ldreq r3, [r0, #0x1c] */
/* @0x2df52c cmn r5, #1 */
/* @0x2df530 beq 0x2df620 <_ZN13b2DynamicTree10RemoveLeafEi+0x138> */
/* @0x2df534 add r1, r5, r5, lsl #3 */
/* @0x2df538 add r1, r2, r1, lsl #2 */
/* @0x2df53c ldr r0, [r1, #0x18] */
/* @0x2df540 cmp r0, r12 */
/* @0x2df544 streq r3, [r1, #0x18] */
/* @0x2df548 strne r3, [r1, #0x1c] */
/* @0x2df54c add r3, r3, r3, lsl #3 */
/* @0x2df550 mov r1, r12 */
/* @0x2df554 mov r0, r6 */
/* @0x2df558 add r2, r2, r3, lsl #2 */
/* @0x2df55c str r5, [r2, #0x14] */
/* @0x2df560 bl 0x2deaac <_ZN13b2DynamicTree8FreeNodeEi> */
/* @0x2df564 mov r1, r5 */
/* @0x2df568 mov r0, r6 */
/* @0x2df56c bl 0x2deae4 <_ZN13b2DynamicTree7BalanceEi> */
/* @0x2df570 ldr r4, [r6, #0x4] */
/* @0x2df574 add r0, r0, r0, lsl #3 */
/* @0x2df578 add r3, r4, r0, lsl #2 */
/* @0x2df57c ldr r12, [r3, #0x18] */
/* @0x2df580 ldr r2, [r3, #0x1c] */
/* @0x2df584 ldr r5, [r3, #0x14] */
/* @0x2df588 add r12, r12, r12, lsl #3 */
/* @0x2df58c add r2, r2, r2, lsl #3 */
/* @0x2df590 add r12, r4, r12, lsl #2 */
/* @0x2df594 vldr s12, [r12] */
/* @0x2df598 add r2, r4, r2, lsl #2 */
/* @0x2df59c vldr s13, [r2] */
/* @0x2df5a0 vcmpe.f32 s12, s13 */
/* @0x2df5a4 vldr s14, [r12, #4] */
/* @0x2df5a8 vldr s15, [r2, #4] */
/* @0x2df5ac ldr r1, [r12, #0x20] */
/* @0x2df5b0 ldr r0, [r2, #0x20] */
/* @0x2df5b4 vmrs APSR_nzcv, fpscr */
/* @0x2df5b8 vcmpe.f32 s14, s15 */
/* @0x2df5bc vmovmi.f32 s13, s12 */
/* @0x2df5c0 vmrs APSR_nzcv, fpscr */
/* @0x2df5c4 vstr s13, [r3] */
/* @0x2df5c8 vmovmi.f32 s15, s14 */
/* @0x2df5cc vstr s15, [r3, #4] */
/* @0x2df5d0 vldr s13, [r2, #8] */
/* @0x2df5d4 vldr s12, [r12, #8] */
/* @0x2df5d8 vldr s15, [r2, #12] */
/* @0x2df5dc vldr s14, [r12, #12] */
/* @0x2df5e0 vcmpe.f32 s12, s13 */
/* @0x2df5e4 vmrs APSR_nzcv, fpscr */
/* @0x2df5e8 vcmpe.f32 s14, s15 */
/* @0x2df5ec vmovgt.f32 s13, s12 */
/* @0x2df5f0 vmrs APSR_nzcv, fpscr */
/* @0x2df5f4 vstr s13, [r3, #8] */
/* @0x2df5f8 vmovgt.f32 s15, s14 */
/* @0x2df5fc cmp r0, r1 */
/* @0x2df600 movge r2, r0 */
/* @0x2df604 movlt r2, r1 */
/* @0x2df608 cmn r5, #1 */
/* @0x2df60c add r2, r2, #1 */
/* @0x2df610 vstr s15, [r3, #12] */
/* @0x2df614 str r2, [r3, #0x20] */
/* @0x2df618 bne 0x2df564 <_ZN13b2DynamicTree10RemoveLeafEi+0x7c> */
/* @0x2df61c pop {r4, r5, r6, pc} */
/* @0x2df620 add r4, r3, r3, lsl #3 */
/* @0x2df624 str r3, [r6] */
/* @0x2df628 mov r0, r6 */
/* @0x2df62c mov r1, r12 */
/* @0x2df630 add r2, r2, r4, lsl #2 */
/* @0x2df634 str r5, [r2, #0x14] */
/* @0x2df638 pop {r4, r5, r6, lr} */
/* @0x2df63c b 0x2deaac <_ZN13b2DynamicTree8FreeNodeEi> */

/* ── FUNC 0x2df640 · b2DynamicTree::DestroyProxy(int) · size=32 · insn=8 */
/* @0x2df640 push {r3, r4, r5, lr} */
/* @0x2df644 mov r5, r0 */
/* @0x2df648 mov r4, r1 */
/* @0x2df64c bl 0x2df4e8 <_ZN13b2DynamicTree10RemoveLeafEi> */
/* @0x2df650 mov r0, r5 */
/* @0x2df654 mov r1, r4 */
/* @0x2df658 pop {r3, r4, r5, lr} */
/* @0x2df65c b 0x2deaac <_ZN13b2DynamicTree8FreeNodeEi> */

/* ── FUNC 0x2df660 · b2DynamicTree::MoveProxy(int, b2AABB const&, b2Vec2 const&) · size=280 · insn=70 */
/* @0x2df660 push {r4, r5, r6, r7, r8, lr} */
/* @0x2df664 vldr s15, [r2] */
/* @0x2df668 add r8, r1, r1, lsl #3 */
/* @0x2df66c mov r5, r1 */
/* @0x2df670 ldr r1, [r0, #0x4] */
/* @0x2df674 lsl r8, r8, #2 */
/* @0x2df678 mov r4, r2 */
/* @0x2df67c add r2, r1, r8 */
/* @0x2df680 vldr s14, [r2] */
/* @0x2df684 vcmpe.f32 s14, s15 */
/* @0x2df688 mov r6, r0 */
/* @0x2df68c mov r7, r3 */
/* @0x2df690 vmrs APSR_nzcv, fpscr */
/* @0x2df694 bhi 0x2df6ac <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2+0x4c> */
/* @0x2df698 vldr s14, [r2, #4] */
/* @0x2df69c vldr s15, [r4, #4] */
/* @0x2df6a0 vcmpe.f32 s14, s15 */
/* @0x2df6a4 vmrs APSR_nzcv, fpscr */
/* @0x2df6a8 bls 0x2df73c <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2+0xdc> */
/* @0x2df6ac mov r0, r6 */
/* @0x2df6b0 mov r1, r5 */
/* @0x2df6b4 bl 0x2df4e8 <_ZN13b2DynamicTree10RemoveLeafEi> */
/* @0x2df6b8 vldr s15, [r7] */
/* @0x2df6bc vadd.f32 s14, s15, s15 */
/* @0x2df6c0 vldr s12, [r4] */
/* @0x2df6c4 vldr s15, [pc, #168] */
/* @0x2df6c8 vldr s13, [r4, #8] */
/* @0x2df6cc vldr s10, [r4, #4] */
/* @0x2df6d0 vldr s9, [r4, #12] */
/* @0x2df6d4 vldr s11, [r7, #4] */
/* @0x2df6d8 vsub.f32 s12, s12, s15 */
/* @0x2df6dc vadd.f32 s15, s13, s15 */
/* @0x2df6e0 vcmpe.f32 s14, #0 */
/* @0x2df6e4 vmrs APSR_nzcv, fpscr */
/* @0x2df6e8 vaddpl.f32 s15, s15, s14 */
/* @0x2df6ec bmi 0x2df76c <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2+0x10c> */
/* @0x2df6f0 vldr s14, [pc, #124] */
/* @0x2df6f4 ldr r3, [r6, #0x4] */
/* @0x2df6f8 mov r0, r6 */
/* @0x2df6fc mov r1, r5 */
/* @0x2df700 add r8, r3, r8 */
/* @0x2df704 vstr s12, [r8] */
/* @0x2df708 vstr s15, [r8, #8] */
/* @0x2df70c vadd.f32 s11, s11, s11 */
/* @0x2df710 vsub.f32 s10, s10, s14 */
/* @0x2df714 vadd.f32 s14, s9, s14 */
/* @0x2df718 vcmpe.f32 s11, #0 */
/* @0x2df71c vmrs APSR_nzcv, fpscr */
/* @0x2df720 vaddmi.f32 s10, s10, s11 */
/* @0x2df724 vaddpl.f32 s14, s14, s11 */
/* @0x2df728 vstr s10, [r8, #4] */
/* @0x2df72c vstr s14, [r8, #12] */
/* @0x2df730 bl 0x2defd0 <_ZN13b2DynamicTree10InsertLeafEi> */
/* @0x2df734 mov r0, #1 */
/* @0x2df738 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2df73c vldr s14, [r4, #8] */
/* @0x2df740 vldr s15, [r2, #8] */
/* @0x2df744 vcmpe.f32 s14, s15 */
/* @0x2df748 vmrs APSR_nzcv, fpscr */
/* @0x2df74c bhi 0x2df6ac <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2+0x4c> */
/* @0x2df750 vldr s14, [r4, #12] */
/* @0x2df754 vldr s15, [r2, #12] */
/* @0x2df758 vcmpe.f32 s14, s15 */
/* @0x2df75c vmrs APSR_nzcv, fpscr */
/* @0x2df760 bhi 0x2df6ac <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2+0x4c> */
/* @0x2df764 mov r0, #0 */
/* @0x2df768 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2df76c vadd.f32 s12, s12, s14 */
/* @0x2df770 b 0x2df6f0 <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2+0x90> */
/* @0x2df774 stcllo p12, c12, [r12, #820] */

/* ── FUNC 0x2df778 · b2DynamicTree::GetHeight() const · size=32 · insn=8 */
/* @0x2df778 ldr r3, [r0] */
/* @0x2df77c cmn r3, #1 */
/* @0x2df780 addne r3, r3, r3, lsl #3 */
/* @0x2df784 ldrne r2, [r0, #0x4] */
/* @0x2df788 addne r3, r2, r3, lsl #2 */
/* @0x2df78c ldrne r0, [r3, #0x20] */
/* @0x2df790 moveq r0, #0 */
/* @0x2df794 bx lr */

/* ── FUNC 0x2df798 · b2DynamicTree::GetAreaRatio() const · size=180 · insn=45 */
/* @0x2df798 ldr r2, [r0] */
/* @0x2df79c cmn r2, #1 */
/* @0x2df7a0 beq 0x2df834 <_ZNK13b2DynamicTree12GetAreaRatioEv+0x9c> */
/* @0x2df7a4 add r2, r2, r2, lsl #3 */
/* @0x2df7a8 ldr r3, [r0, #0x4] */
/* @0x2df7ac ldr r1, [r0, #0xc] */
/* @0x2df7b0 add r2, r3, r2, lsl #2 */
/* @0x2df7b4 vldr s15, [r2] */
/* @0x2df7b8 vldr s14, [r2, #8] */
/* @0x2df7bc vldr s13, [r2, #12] */
/* @0x2df7c0 vsub.f32 s14, s14, s15 */
/* @0x2df7c4 vldr s15, [r2, #4] */
/* @0x2df7c8 cmp r1, #0 */
/* @0x2df7cc vsub.f32 s15, s13, s15 */
/* @0x2df7d0 vadd.f32 s14, s14, s15 */
/* @0x2df7d4 vadd.f32 s11, s14, s14 */
/* @0x2df7d8 ble 0x2df840 <_ZNK13b2DynamicTree12GetAreaRatioEv+0xa8> */
/* @0x2df7dc add r1, r1, r1, lsl #3 */
/* @0x2df7e0 add r3, r3, #32 */
/* @0x2df7e4 vldr s14, [pc, #92] */
/* @0x2df7e8 add r1, r3, r1, lsl #2 */
/* @0x2df7ec ldr r2, [r3] */
/* @0x2df7f0 cmp r2, #0 */
/* @0x2df7f4 blt 0x2df81c <_ZNK13b2DynamicTree12GetAreaRatioEv+0x84> */
/* @0x2df7f8 vldr s15, [r3, #-32] */
/* @0x2df7fc vldr s13, [r3, #-24] */
/* @0x2df800 vldr s12, [r3, #-20] */
/* @0x2df804 vsub.f32 s13, s13, s15 */
/* @0x2df808 vldr s15, [r3, #-28] */
/* @0x2df80c vsub.f32 s15, s12, s15 */
/* @0x2df810 vadd.f32 s15, s13, s15 */
/* @0x2df814 vadd.f32 s15, s15, s15 */
/* @0x2df818 vadd.f32 s14, s14, s15 */
/* @0x2df81c add r3, r3, #36 */
/* @0x2df820 cmp r3, r1 */
/* @0x2df824 bne 0x2df7ec <_ZNK13b2DynamicTree12GetAreaRatioEv+0x54> */
/* @0x2df828 vdiv.f32 s14, s14, s11 */
/* @0x2df82c vmov r0, s14 */
/* @0x2df830 bx lr */
/* @0x2df834 vldr s14, [pc, #12] */
/* @0x2df838 vmov r0, s14 */
/* @0x2df83c bx lr */
/* @0x2df840 vldr s14, [pc] */
/* @0x2df844 b 0x2df828 <_ZNK13b2DynamicTree12GetAreaRatioEv+0x90> */
/* @0x2df848 andeq r0, r0, r0 */

/* ── FUNC 0x2df84c · b2DynamicTree::ComputeHeight(int) const · size=76 · insn=19 */
/* @0x2df84c add r1, r1, r1, lsl #3 */
/* @0x2df850 ldr r3, [r0, #0x4] */
/* @0x2df854 push {r4, r5, r6, lr} */
/* @0x2df858 add r4, r3, r1, lsl #2 */
/* @0x2df85c mov r5, r0 */
/* @0x2df860 ldr r1, [r4, #0x18] */
/* @0x2df864 cmn r1, #1 */
/* @0x2df868 beq 0x2df890 <_ZNK13b2DynamicTree13ComputeHeightEi+0x44> */
/* @0x2df86c bl 0x2df84c <_ZNK13b2DynamicTree13ComputeHeightEi> */
/* @0x2df870 ldr r1, [r4, #0x1c] */
/* @0x2df874 mov r6, r0 */
/* @0x2df878 mov r0, r5 */
/* @0x2df87c bl 0x2df84c <_ZNK13b2DynamicTree13ComputeHeightEi> */
/* @0x2df880 cmp r0, r6 */
/* @0x2df884 movlt r0, r6 */
/* @0x2df888 add r0, r0, #1 */
/* @0x2df88c pop {r4, r5, r6, pc} */
/* @0x2df890 mov r0, #0 */
/* @0x2df894 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2df898 · b2DynamicTree::ComputeHeight() const · size=8 · insn=2 */
/* @0x2df898 ldr r1, [r0] */
/* @0x2df89c b 0x2df84c <_ZNK13b2DynamicTree13ComputeHeightEi> */

/* ── FUNC 0x2df8a0 · b2DynamicTree::ValidateStructure(int) const · size=96 · insn=24 */
/* @0x2df8a0 cmn r1, #1 */
/* @0x2df8a4 push {r3, r4, r5, lr} */
/* @0x2df8a8 mov r5, r0 */
/* @0x2df8ac popeq {r3, r4, r5, pc} */
/* @0x2df8b0 add r1, r1, r1, lsl #3 */
/* @0x2df8b4 ldr r3, [r0, #0x4] */
/* @0x2df8b8 add r3, r3, r1, lsl #2 */
/* @0x2df8bc ldr r1, [r3, #0x18] */
/* @0x2df8c0 ldr r4, [r3, #0x1c] */
/* @0x2df8c4 cmn r1, #1 */
/* @0x2df8c8 bne 0x2df8e8 <_ZNK13b2DynamicTree17ValidateStructureEi+0x48> */
/* @0x2df8cc pop {r3, r4, r5, pc} */
/* @0x2df8d0 ldr r2, [r5, #0x4] */
/* @0x2df8d4 add r3, r2, r3, lsl #2 */
/* @0x2df8d8 ldr r1, [r3, #0x18] */
/* @0x2df8dc ldr r4, [r3, #0x1c] */
/* @0x2df8e0 cmn r1, #1 */
/* @0x2df8e4 popeq {r3, r4, r5, pc} */
/* @0x2df8e8 mov r0, r5 */
/* @0x2df8ec bl 0x2df8a0 <_ZNK13b2DynamicTree17ValidateStructureEi> */
/* @0x2df8f0 cmn r4, #1 */
/* @0x2df8f4 add r3, r4, r4, lsl #3 */
/* @0x2df8f8 bne 0x2df8d0 <_ZNK13b2DynamicTree17ValidateStructureEi+0x30> */
/* @0x2df8fc pop {r3, r4, r5, pc} */

/* ── FUNC 0x2df900 · b2DynamicTree::ValidateMetrics(int) const · size=96 · insn=24 */
/* @0x2df900 cmn r1, #1 */
/* @0x2df904 push {r3, r4, r5, lr} */
/* @0x2df908 mov r5, r0 */
/* @0x2df90c popeq {r3, r4, r5, pc} */
/* @0x2df910 add r1, r1, r1, lsl #3 */
/* @0x2df914 ldr r3, [r0, #0x4] */
/* @0x2df918 add r3, r3, r1, lsl #2 */
/* @0x2df91c ldr r1, [r3, #0x18] */
/* @0x2df920 ldr r4, [r3, #0x1c] */
/* @0x2df924 cmn r1, #1 */
/* @0x2df928 bne 0x2df948 <_ZNK13b2DynamicTree15ValidateMetricsEi+0x48> */
/* @0x2df92c pop {r3, r4, r5, pc} */
/* @0x2df930 ldr r2, [r5, #0x4] */
/* @0x2df934 add r3, r2, r3, lsl #2 */
/* @0x2df938 ldr r1, [r3, #0x18] */
/* @0x2df93c ldr r4, [r3, #0x1c] */
/* @0x2df940 cmn r1, #1 */
/* @0x2df944 popeq {r3, r4, r5, pc} */
/* @0x2df948 mov r0, r5 */
/* @0x2df94c bl 0x2df900 <_ZNK13b2DynamicTree15ValidateMetricsEi> */
/* @0x2df950 cmn r4, #1 */
/* @0x2df954 add r3, r4, r4, lsl #3 */
/* @0x2df958 bne 0x2df930 <_ZNK13b2DynamicTree15ValidateMetricsEi+0x30> */
/* @0x2df95c pop {r3, r4, r5, pc} */

/* ── FUNC 0x2df960 · b2DynamicTree::Validate() const · size=32 · insn=8 */
/* @0x2df960 push {r4, lr} */
/* @0x2df964 mov r4, r0 */
/* @0x2df968 ldr r1, [r0] */
/* @0x2df96c bl 0x2df8a0 <_ZNK13b2DynamicTree17ValidateStructureEi> */
/* @0x2df970 mov r0, r4 */
/* @0x2df974 ldr r1, [r4] */
/* @0x2df978 pop {r4, lr} */
/* @0x2df97c b 0x2df900 <_ZNK13b2DynamicTree15ValidateMetricsEi> */

/* ── FUNC 0x2df980 · b2DynamicTree::GetMaxBalance() const · size=128 · insn=32 */
/* @0x2df980 str r4, [sp, #-0x4]! */
/* @0x2df984 ldr r4, [r0, #0xc] */
/* @0x2df988 cmp r4, #0 */
/* @0x2df98c ble 0x2df9f8 <_ZNK13b2DynamicTree13GetMaxBalanceEv+0x78> */
/* @0x2df990 ldr r12, [r0, #0x4] */
/* @0x2df994 add r4, r4, r4, lsl #3 */
/* @0x2df998 mov r0, #0 */
/* @0x2df99c add r4, r12, r4, lsl #2 */
/* @0x2df9a0 mov r3, r12 */
/* @0x2df9a4 ldr r2, [r3, #0x20] */
/* @0x2df9a8 cmp r2, #1 */
/* @0x2df9ac ble 0x2df9e4 <_ZNK13b2DynamicTree13GetMaxBalanceEv+0x64> */
/* @0x2df9b0 ldr r1, [r3, #0x1c] */
/* @0x2df9b4 ldr r2, [r3, #0x18] */
/* @0x2df9b8 add r1, r1, r1, lsl #3 */
/* @0x2df9bc add r2, r2, r2, lsl #3 */
/* @0x2df9c0 add r1, r12, r1, lsl #2 */
/* @0x2df9c4 add r2, r12, r2, lsl #2 */
/* @0x2df9c8 ldr r1, [r1, #0x20] */
/* @0x2df9cc ldr r2, [r2, #0x20] */
/* @0x2df9d0 rsb r2, r2, r1 */
/* @0x2df9d4 cmp r2, #0 */
/* @0x2df9d8 rsblt r2, r2, #0 */
/* @0x2df9dc cmp r0, r2 */
/* @0x2df9e0 movlt r0, r2 */
/* @0x2df9e4 add r3, r3, #36 */
/* @0x2df9e8 cmp r3, r4 */
/* @0x2df9ec bne 0x2df9a4 <_ZNK13b2DynamicTree13GetMaxBalanceEv+0x24> */
/* @0x2df9f0 ldr r4, [sp], #4 */
/* @0x2df9f4 bx lr */
/* @0x2df9f8 mov r0, #0 */
/* @0x2df9fc b 0x2df9f0 <_ZNK13b2DynamicTree13GetMaxBalanceEv+0x70> */

/* ── FUNC 0x2dfa00 · b2DynamicTree::RebuildBottomUp() · size=644 · insn=161 */
/* @0x2dfa00 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2dfa04 mov r9, r0 */
/* @0x2dfa08 ldr r0, [r0, #0x8] */
/* @0x2dfa0c sub sp, sp, #20 */
/* @0x2dfa10 lsl r0, r0, #2 */
/* @0x2dfa14 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2dfa18 ldr r2, [r9, #0xc] */
/* @0x2dfa1c cmp r2, #0 */
/* @0x2dfa20 movgt r6, #0 */
/* @0x2dfa24 movgt r5, r6 */
/* @0x2dfa28 movgt r4, r6 */
/* @0x2dfa2c mov r10, r0 */
/* @0x2dfa30 bgt 0x2dfa58 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x58> */
/* @0x2dfa34 b 0x2dfc60 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x260> */
/* @0x2dfa38 str r2, [r3, #0x14] */
/* @0x2dfa3c str r5, [r10, r4, lsl #2] */
/* @0x2dfa40 add r4, r4, #1 */
/* @0x2dfa44 ldr r2, [r9, #0xc] */
/* @0x2dfa48 add r5, r5, #1 */
/* @0x2dfa4c add r6, r6, #36 */
/* @0x2dfa50 cmp r2, r5 */
/* @0x2dfa54 ble 0x2dfa98 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x98> */
/* @0x2dfa58 ldr r3, [r9, #0x4] */
/* @0x2dfa5c add r3, r3, r6 */
/* @0x2dfa60 ldr r1, [r3, #0x20] */
/* @0x2dfa64 cmp r1, #0 */
/* @0x2dfa68 blt 0x2dfa48 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x48> */
/* @0x2dfa6c ldr r2, [r3, #0x18] */
/* @0x2dfa70 mov r1, r5 */
/* @0x2dfa74 mov r0, r9 */
/* @0x2dfa78 cmn r2, #1 */
/* @0x2dfa7c beq 0x2dfa38 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x38> */
/* @0x2dfa80 bl 0x2deaac <_ZN13b2DynamicTree8FreeNodeEi> */
/* @0x2dfa84 ldr r2, [r9, #0xc] */
/* @0x2dfa88 add r5, r5, #1 */
/* @0x2dfa8c add r6, r6, #36 */
/* @0x2dfa90 cmp r2, r5 */
/* @0x2dfa94 bgt 0x2dfa58 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x58> */
/* @0x2dfa98 cmp r4, #1 */
/* @0x2dfa9c ble 0x2dfc60 <_ZN13b2DynamicTree15RebuildBottomUpEv+0x260> */
/* @0x2dfaa0 ldr r3, [r9, #0x4] */
/* @0x2dfaa4 add r12, r10, r4, lsl #2 */
/* @0x2dfaa8 mov r1, r9 */
/* @0x2dfaac sub r2, r10, #4 */
/* @0x2dfab0 str r2, [sp, #0xc] */
/* @0x2dfab4 ldr r9, [sp, #0xc] */
/* @0x2dfab8 mvn r5, #0 */
/* @0x2dfabc mov r6, r5 */
/* @0x2dfac0 mov r7, #0 */
/* @0x2dfac4 vldr s7, [pc, #436] */
/* @0x2dfac8 ldr r2, [r9, #0x4]! */
/* @0x2dfacc add r8, r7, #1 */
/* @0x2dfad0 cmp r8, r4 */
/* @0x2dfad4 add r2, r2, r2, lsl #3 */
/* @0x2dfad8 add r2, r3, r2, lsl #2 */
/* @0x2dfadc vldr s10, [r2] */
/* @0x2dfae0 vldr s11, [r2, #4] */
/* @0x2dfae4 vldr s8, [r2, #8] */
/* @0x2dfae8 vldr s9, [r2, #12] */
/* @0x2dfaec bge 0x2dfb7c <_ZN13b2DynamicTree15RebuildBottomUpEv+0x17c> */
/* @0x2dfaf0 mov lr, r9 */
/* @0x2dfaf4 mov r0, r8 */
/* @0x2dfaf8 ldr r2, [lr, #0x4]! */
/* @0x2dfafc add r2, r2, r2, lsl #3 */
/* @0x2dfb00 add r2, r3, r2, lsl #2 */
/* @0x2dfb04 vldr s15, [r2] */
/* @0x2dfb08 vcmpe.f32 s10, s15 */
/* @0x2dfb0c vldr s12, [r2, #4] */
/* @0x2dfb10 vldr s13, [r2, #8] */
/* @0x2dfb14 vldr s14, [r2, #12] */
/* @0x2dfb18 vmrs APSR_nzcv, fpscr */
/* @0x2dfb1c vcmpe.f32 s11, s12 */
/* @0x2dfb20 vmovmi.f32 s15, s10 */
/* @0x2dfb24 vmrs APSR_nzcv, fpscr */
/* @0x2dfb28 vcmpe.f32 s13, s8 */
/* @0x2dfb2c vmovmi.f32 s12, s11 */
/* @0x2dfb30 vmrs APSR_nzcv, fpscr */
/* @0x2dfb34 vcmpe.f32 s14, s9 */
/* @0x2dfb38 vmovmi.f32 s13, s8 */
/* @0x2dfb3c vmrs APSR_nzcv, fpscr */
/* @0x2dfb40 vmovmi.f32 s14, s9 */
/* @0x2dfb44 vsub.f32 s15, s13, s15 */
/* @0x2dfb48 vsub.f32 s14, s14, s12 */
/* @0x2dfb4c vadd.f32 s15, s15, s14 */
/* @0x2dfb50 vadd.f32 s15, s15, s15 */
/* @0x2dfb54 vcmpe.f32 s7, s15 */
/* @0x2dfb58 vmrs APSR_nzcv, fpscr */
/* @0x2dfb5c movgt r5, r0 */
/* @0x2dfb60 add r0, r0, #1 */
/* @0x2dfb64 vmovgt.f32 s7, s15 */
/* @0x2dfb68 movgt r6, r7 */
/* @0x2dfb6c cmp r0, r4 */
/* @0x2dfb70 bne 0x2dfaf8 <_ZN13b2DynamicTree15RebuildBottomUpEv+0xf8> */
/* @0x2dfb74 mov r7, r8 */
/* @0x2dfb78 b 0x2dfac8 <_ZN13b2DynamicTree15RebuildBottomUpEv+0xc8> */
/* @0x2dfb7c ldr r9, [r10, r6, lsl #2] */
/* @0x2dfb80 mov r0, r1 */
/* @0x2dfb84 ldr r11, [r10, r5, lsl #2] */
/* @0x2dfb88 sub r4, r4, #1 */
/* @0x2dfb8c stmib sp, {r1, r12} */
/* @0x2dfb90 add r8, r9, r9, lsl #3 */
/* @0x2dfb94 add r7, r11, r11, lsl #3 */
/* @0x2dfb98 add r8, r3, r8, lsl #2 */
/* @0x2dfb9c add r7, r3, r7, lsl #2 */
/* @0x2dfba0 bl 0x2de9bc <_ZN13b2DynamicTree12AllocateNodeEv> */
/* @0x2dfba4 vldr s12, [r8] */
/* @0x2dfba8 vldr s13, [r7] */
/* @0x2dfbac vcmpe.f32 s12, s13 */
/* @0x2dfbb0 ldr r3, [r8, #0x20] */
/* @0x2dfbb4 ldr lr, [r7, #0x20] */
/* @0x2dfbb8 vldr s14, [r8, #4] */
/* @0x2dfbbc ldr r1, [sp, #0x4] */
/* @0x2dfbc0 vldr s15, [r7, #4] */
/* @0x2dfbc4 cmp lr, r3 */
/* @0x2dfbc8 movlt lr, r3 */
/* @0x2dfbcc vmrs APSR_nzcv, fpscr */
/* @0x2dfbd0 vcmpe.f32 s14, s15 */
/* @0x2dfbd4 ldr r3, [r1, #0x4] */
/* @0x2dfbd8 add lr, lr, #1 */
/* @0x2dfbdc vmovmi.f32 s13, s12 */
/* @0x2dfbe0 vmrs APSR_nzcv, fpscr */
/* @0x2dfbe4 vmovmi.f32 s15, s14 */
/* @0x2dfbe8 add r2, r0, r0, lsl #3 */
/* @0x2dfbec add r2, r3, r2, lsl #2 */
/* @0x2dfbf0 vstr s13, [r2] */
/* @0x2dfbf4 vstr s15, [r2, #4] */
/* @0x2dfbf8 vldr s12, [r8, #8] */
/* @0x2dfbfc vldr s13, [r7, #8] */
/* @0x2dfc00 vcmpe.f32 s12, s13 */
/* @0x2dfc04 vldr s14, [r8, #12] */
/* @0x2dfc08 vldr s15, [r7, #12] */
/* @0x2dfc0c str lr, [r2, #0x20] */
/* @0x2dfc10 mvn lr, #0 */
/* @0x2dfc14 str r9, [r2, #0x18] */
/* @0x2dfc18 vmrs APSR_nzcv, fpscr */
/* @0x2dfc1c vcmpe.f32 s14, s15 */
/* @0x2dfc20 str lr, [r2, #0x14] */
/* @0x2dfc24 str r11, [r2, #0x1c] */
/* @0x2dfc28 vmovgt.f32 s13, s12 */
/* @0x2dfc2c vmrs APSR_nzcv, fpscr */
/* @0x2dfc30 vstr s13, [r2, #8] */
/* @0x2dfc34 vmovgt.f32 s15, s14 */
/* @0x2dfc38 vstr s15, [r2, #12] */
/* @0x2dfc3c str r0, [r8, #0x14] */
/* @0x2dfc40 cmp r4, #1 */
/* @0x2dfc44 str r0, [r7, #0x14] */
/* @0x2dfc48 ldr r12, [sp, #0x8] */
/* @0x2dfc4c ldr r2, [r12, #-0x4]! */
/* @0x2dfc50 str r2, [r10, r5, lsl #2] */
/* @0x2dfc54 str r0, [r10, r6, lsl #2] */
/* @0x2dfc58 bne 0x2dfab4 <_ZN13b2DynamicTree15RebuildBottomUpEv+0xb4> */
/* @0x2dfc5c mov r9, r1 */
/* @0x2dfc60 ldr r3, [r10] */
/* @0x2dfc64 mov r0, r10 */
/* @0x2dfc68 str r3, [r9] */
/* @0x2dfc6c bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2dfc70 mov r0, r9 */
/* @0x2dfc74 add sp, sp, #20 */
/* @0x2dfc78 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2dfc7c b 0x2df960 <_ZNK13b2DynamicTree8ValidateEv> */
/* @0x2dfc80 svcvc #0x7fffff */

/* ── FUNC 0x2dfc84 · b2DynamicTree::ShiftOrigin(b2Vec2 const&) · size=112 · insn=28 */
/* @0x2dfc84 ldr r2, [r0, #0xc] */
/* @0x2dfc88 cmp r2, #0 */
/* @0x2dfc8c bxle lr */
/* @0x2dfc90 ldr r3, [r0, #0x4] */
/* @0x2dfc94 add r0, r2, r2, lsl #3 */
/* @0x2dfc98 add r2, r3, #8 */
/* @0x2dfc9c add r0, r3, r0, lsl #2 */
/* @0x2dfca0 vldr s14, [r3] */
/* @0x2dfca4 vldr s15, [r1] */
/* @0x2dfca8 vsub.f32 s15, s14, s15 */
/* @0x2dfcac vldr s14, [r3, #4] */
/* @0x2dfcb0 add r3, r3, #36 */
/* @0x2dfcb4 add r2, r2, #36 */
/* @0x2dfcb8 vstr s15, [r3, #-36] */
/* @0x2dfcbc vldr s15, [r1, #4] */
/* @0x2dfcc0 vsub.f32 s15, s14, s15 */
/* @0x2dfcc4 vstr s15, [r3, #-32] */
/* @0x2dfcc8 vldr s14, [r2, #-36] */
/* @0x2dfccc vldr s15, [r1] */
/* @0x2dfcd0 vsub.f32 s15, s14, s15 */
/* @0x2dfcd4 vldr s14, [r2, #-32] */
/* @0x2dfcd8 cmp r3, r0 */
/* @0x2dfcdc vstr s15, [r2, #-36] */
/* @0x2dfce0 vldr s15, [r1, #4] */
/* @0x2dfce4 vsub.f32 s15, s14, s15 */
/* @0x2dfce8 vstr s15, [r2, #-32] */
/* @0x2dfcec bne 0x2dfca0 <_ZN13b2DynamicTree11ShiftOriginERK6b2Vec2+0x1c> */
/* @0x2dfcf0 bx lr */

/* ── FUNC 0x2dfcf4 · b2SeparationFunction::Initialize(b2SimplexCache const*, b2DistanceProxy const*, b2Sweep const&, b2DistanceProxy const*, b2Sweep const&, float) · size=1236 · insn=309 */
/* @0x2dfcf4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2dfcf8 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x2dfcfc mov r6, r3 */
/* @0x2dfd00 vldr s16, [sp, #88] */
/* @0x2dfd04 mov r4, r0 */
/* @0x2dfd08 mov r7, r1 */
/* @0x2dfd0c mov r8, r2 */
/* @0x2dfd10 ldr r9, [sp, #0x50] */
/* @0x2dfd14 ldm r6!, {r0, r1, r2, r3} */
/* @0x2dfd18 add r5, r4, #8 */
/* @0x2dfd1c ldrh r10, [r7, #4] */
/* @0x2dfd20 vmov.f32 s17, #1.000000e+00 */
/* @0x2dfd24 str r8, [r4] */
/* @0x2dfd28 add r12, r4, #44 */
/* @0x2dfd2c str r9, [r4, #0x4] */
/* @0x2dfd30 stm r5!, {r0, r1, r2, r3} */
/* @0x2dfd34 ldm r6!, {r0, r1, r2, r3} */
/* @0x2dfd38 ldr lr, [sp, #0x54] */
/* @0x2dfd3c stm r5!, {r0, r1, r2, r3} */
/* @0x2dfd40 vsub.f32 s17, s17, s16 */
/* @0x2dfd44 ldr r3, [r6] */
/* @0x2dfd48 str r3, [r5] */
/* @0x2dfd4c ldm lr!, {r0, r1, r2, r3} */
/* @0x2dfd50 stm r12!, {r0, r1, r2, r3} */
/* @0x2dfd54 ldm lr!, {r0, r1, r2, r3} */
/* @0x2dfd58 stm r12!, {r0, r1, r2, r3} */
/* @0x2dfd5c vldr s18, [r4, #36] */
/* @0x2dfd60 vmul.f32 s18, s16, s18 */
/* @0x2dfd64 vldr s15, [r4, #32] */
/* @0x2dfd68 ldr r3, [lr] */
/* @0x2dfd6c str r3, [r12] */
/* @0x2dfd70 vmla.f32 s18, s17, s15 */
/* @0x2dfd74 vmov r0, s18 */
/* @0x2dfd78 bl 0xb6580 <sinf@plt> */
/* @0x2dfd7c vmov s19, r0 */
/* @0x2dfd80 vmov r0, s18 */
/* @0x2dfd84 bl 0xb658c <cosf@plt> */
/* @0x2dfd88 vldr s20, [r4, #72] */
/* @0x2dfd8c vmul.f32 s20, s16, s20 */
/* @0x2dfd90 vldr s15, [r4, #12] */
/* @0x2dfd94 vldr s12, [r4, #24] */
/* @0x2dfd98 vldr s14, [r4, #28] */
/* @0x2dfd9c vldr s8, [r4, #68] */
/* @0x2dfda0 vldr s11, [r4, #8] */
/* @0x2dfda4 vldr s9, [r4, #16] */
/* @0x2dfda8 vldr s10, [r4, #20] */
/* @0x2dfdac vmul.f32 s12, s16, s12 */
/* @0x2dfdb0 vmul.f32 s13, s15, s19 */
/* @0x2dfdb4 vmov s18, r0 */
/* @0x2dfdb8 vmul.f32 s14, s16, s14 */
/* @0x2dfdbc vmul.f32 s15, s15, s18 */
/* @0x2dfdc0 vmla.f32 s20, s17, s8 */
/* @0x2dfdc4 vmla.f32 s12, s17, s9 */
/* @0x2dfdc8 vmov r0, s20 */
/* @0x2dfdcc vmla.f32 s14, s17, s10 */
/* @0x2dfdd0 vnmls.f32 s13, s11, s18 */
/* @0x2dfdd4 vmla.f32 s15, s11, s19 */
/* @0x2dfdd8 vsub.f32 s22, s12, s13 */
/* @0x2dfddc vsub.f32 s23, s14, s15 */
/* @0x2dfde0 bl 0xb6580 <sinf@plt> */
/* @0x2dfde4 vmov s21, r0 */
/* @0x2dfde8 vmov r0, s20 */
/* @0x2dfdec bl 0xb658c <cosf@plt> */
/* @0x2dfdf0 vldr s12, [r4, #48] */
/* @0x2dfdf4 vldr s13, [r4, #60] */
/* @0x2dfdf8 vldr s8, [r4, #64] */
/* @0x2dfdfc vmul.f32 s13, s16, s13 */
/* @0x2dfe00 vldr s11, [r4, #44] */
/* @0x2dfe04 vldr s9, [r4, #52] */
/* @0x2dfe08 vldr s10, [r4, #56] */
/* @0x2dfe0c cmp r10, #1 */
/* @0x2dfe10 vmul.f32 s14, s12, s21 */
/* @0x2dfe14 vmul.f32 s16, s16, s8 */
/* @0x2dfe18 vmov s20, r0 */
/* @0x2dfe1c vmul.f32 s15, s12, s20 */
/* @0x2dfe20 vmla.f32 s16, s17, s10 */
/* @0x2dfe24 vmla.f32 s13, s17, s9 */
/* @0x2dfe28 vnmls.f32 s14, s11, s20 */
/* @0x2dfe2c vmla.f32 s15, s11, s21 */
/* @0x2dfe30 vsub.f32 s17, s13, s14 */
/* @0x2dfe34 vsub.f32 s16, s16, s15 */
/* @0x2dfe38 beq 0x2e00d4 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x3e0> */
/* @0x2dfe3c ldrb r2, [r7, #0x6] */
/* @0x2dfe40 ldrb r3, [r7, #0x7] */
/* @0x2dfe44 cmp r2, r3 */
/* @0x2dfe48 beq 0x2dff90 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x29c> */
/* @0x2dfe4c mov r3, #1 */
/* @0x2dfe50 str r3, [r4, #0x50] */
/* @0x2dfe54 ldrb r2, [r7, #0x6] */
/* @0x2dfe58 ldrb r1, [r7, #0x7] */
/* @0x2dfe5c ldr r3, [r8, #0x10] */
/* @0x2dfe60 add r2, r3, r2, lsl #3 */
/* @0x2dfe64 add r3, r3, r1, lsl #3 */
/* @0x2dfe68 vldr s26, [r2] */
/* @0x2dfe6c vldr s27, [r3] */
/* @0x2dfe70 vsub.f32 s14, s27, s26 */
/* @0x2dfe74 vldr s24, [r2, #4] */
/* @0x2dfe78 vldr s25, [r3, #4] */
/* @0x2dfe7c vneg.f32 s14, s14 */
/* @0x2dfe80 vmul.f32 s12, s14, s14 */
/* @0x2dfe84 vstr s14, [r4, #96] */
/* @0x2dfe88 vsub.f32 s14, s25, s24 */
/* @0x2dfe8c vmla.f32 s12, s14, s14 */
/* @0x2dfe90 vstr s14, [r4, #92] */
/* @0x2dfe94 vsqrt.f32 s11, s12 */
/* @0x2dfe98 vcmp.f32 s11, s11 */
/* @0x2dfe9c vmrs APSR_nzcv, fpscr */
/* @0x2dfea0 bne 0x2e0194 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x4a0> */
/* @0x2dfea4 vldr s15, [pc, #792] */
/* @0x2dfea8 vcmpe.f32 s11, s15 */
/* @0x2dfeac vmrs APSR_nzcv, fpscr */
/* @0x2dfeb0 bmi 0x2dff84 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x290> */
/* @0x2dfeb4 vmov.f32 s14, #1.000000e+00 */
/* @0x2dfeb8 vldr s6, [r4, #92] */
/* @0x2dfebc vldr s15, [r4, #96] */
/* @0x2dfec0 vdiv.f32 s11, s14, s11 */
/* @0x2dfec4 vmul.f32 s6, s11, s6 */
/* @0x2dfec8 vmul.f32 s11, s11, s15 */
/* @0x2dfecc vstr s6, [r4, #92] */
/* @0x2dfed0 vmov.f32 s7, s11 */
/* @0x2dfed4 vstr s11, [r4, #96] */
/* @0x2dfed8 ldr r3, [r4, #0x4] */
/* @0x2dfedc vmov.f32 s14, #5.000000e-01 */
/* @0x2dfee0 ldr r3, [r3, #0x10] */
/* @0x2dfee4 vadd.f32 s15, s27, s26 */
/* @0x2dfee8 vadd.f32 s12, s25, s24 */
/* @0x2dfeec vmul.f32 s15, s15, s14 */
/* @0x2dfef0 vmul.f32 s12, s12, s14 */
/* @0x2dfef4 vstr s15, [r4, #84] */
/* @0x2dfef8 vstr s12, [r4, #88] */
/* @0x2dfefc ldrb r2, [r7, #0x9] */
/* @0x2dff00 vmul.f32 s9, s12, s18 */
/* @0x2dff04 add r3, r3, r2, lsl #3 */
/* @0x2dff08 vldr s10, [r3, #4] */
/* @0x2dff0c vldr s5, [r3] */
/* @0x2dff10 vmul.f32 s8, s10, s20 */
/* @0x2dff14 vmla.f32 s9, s15, s19 */
/* @0x2dff18 vmul.f32 s12, s12, s19 */
/* @0x2dff1c vmul.f32 s10, s10, s21 */
/* @0x2dff20 vmla.f32 s8, s5, s21 */
/* @0x2dff24 vmul.f32 s11, s7, s18 */
/* @0x2dff28 vnmls.f32 s12, s15, s18 */
/* @0x2dff2c vnmls.f32 s10, s5, s20 */
/* @0x2dff30 vmla.f32 s11, s19, s6 */
/* @0x2dff34 vmul.f32 s19, s7, s19 */
/* @0x2dff38 vadd.f32 s15, s8, s16 */
/* @0x2dff3c vadd.f32 s23, s9, s23 */
/* @0x2dff40 vsub.f32 s15, s15, s23 */
/* @0x2dff44 vnmls.f32 s19, s18, s6 */
/* @0x2dff48 vadd.f32 s10, s10, s17 */
/* @0x2dff4c vadd.f32 s12, s12, s22 */
/* @0x2dff50 vmul.f32 s15, s11, s15 */
/* @0x2dff54 vsub.f32 s12, s10, s12 */
/* @0x2dff58 vmla.f32 s15, s19, s12 */
/* @0x2dff5c vcmpe.f32 s15, #0 */
/* @0x2dff60 vmrs APSR_nzcv, fpscr */
/* @0x2dff64 vnegmi.f32 s15, s15 */
/* @0x2dff68 vmov r0, s15 */
/* @0x2dff6c vnegmi.f32 s6, s6 */
/* @0x2dff70 vnegmi.f32 s7, s7 */
/* @0x2dff74 vstrmi s6, [r4, #92] */
/* @0x2dff78 vstrmi s7, [r4, #96] */
/* @0x2dff7c vpop {d8, d9, d10, d11, d12, d13} */
/* @0x2dff80 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2dff84 vldr s6, [r4, #92] */
/* @0x2dff88 vldr s7, [r4, #96] */
/* @0x2dff8c b 0x2dfed8 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x1e4> */
/* @0x2dff90 mov r3, #2 */
/* @0x2dff94 str r3, [r4, #0x50] */
/* @0x2dff98 ldrb r2, [r7, #0x9] */
/* @0x2dff9c ldrb r1, [r7, #0xa] */
/* @0x2dffa0 ldr r3, [r9, #0x10] */
/* @0x2dffa4 add r2, r3, r2, lsl #3 */
/* @0x2dffa8 add r3, r3, r1, lsl #3 */
/* @0x2dffac vldr s26, [r2] */
/* @0x2dffb0 vldr s27, [r3] */
/* @0x2dffb4 vsub.f32 s15, s27, s26 */
/* @0x2dffb8 vldr s24, [r2, #4] */
/* @0x2dffbc vldr s25, [r3, #4] */
/* @0x2dffc0 vneg.f32 s15, s15 */
/* @0x2dffc4 vmul.f32 s14, s15, s15 */
/* @0x2dffc8 vstr s15, [r4, #96] */
/* @0x2dffcc vsub.f32 s15, s25, s24 */
/* @0x2dffd0 vmla.f32 s14, s15, s15 */
/* @0x2dffd4 vstr s15, [r4, #92] */
/* @0x2dffd8 vsqrt.f32 s15, s14 */
/* @0x2dffdc vcmp.f32 s15, s15 */
/* @0x2dffe0 vmrs APSR_nzcv, fpscr */
/* @0x2dffe4 bne 0x2e01a4 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x4b0> */
/* @0x2dffe8 vldr s14, [pc, #468] */
/* @0x2dffec vcmpe.f32 s15, s14 */
/* @0x2dfff0 vmrs APSR_nzcv, fpscr */
/* @0x2dfff4 bmi 0x2e00c8 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x3d4> */
/* @0x2dfff8 vmov.f32 s13, #1.000000e+00 */
/* @0x2dfffc vldr s7, [r4, #92] */
/* @0x2e0000 vldr s14, [r4, #96] */
/* @0x2e0004 vdiv.f32 s15, s13, s15 */
/* @0x2e0008 vmul.f32 s7, s15, s7 */
/* @0x2e000c vmul.f32 s15, s15, s14 */
/* @0x2e0010 vstr s7, [r4, #92] */
/* @0x2e0014 vmov.f32 s9, s15 */
/* @0x2e0018 vstr s15, [r4, #96] */
/* @0x2e001c ldr r3, [r8, #0x10] */
/* @0x2e0020 vmov.f32 s15, #5.000000e-01 */
/* @0x2e0024 vadd.f32 s14, s27, s26 */
/* @0x2e0028 vadd.f32 s10, s25, s24 */
/* @0x2e002c vmul.f32 s14, s14, s15 */
/* @0x2e0030 vmul.f32 s10, s10, s15 */
/* @0x2e0034 vstr s14, [r4, #84] */
/* @0x2e0038 vstr s10, [r4, #88] */
/* @0x2e003c ldrb r2, [r7, #0x6] */
/* @0x2e0040 vmul.f32 s12, s10, s20 */
/* @0x2e0044 add r3, r3, r2, lsl #3 */
/* @0x2e0048 vldr s13, [r3, #4] */
/* @0x2e004c vldr s8, [r3] */
/* @0x2e0050 vmul.f32 s15, s13, s18 */
/* @0x2e0054 vmla.f32 s12, s14, s21 */
/* @0x2e0058 vmul.f32 s10, s10, s21 */
/* @0x2e005c vmul.f32 s13, s13, s19 */
/* @0x2e0060 vmla.f32 s15, s8, s19 */
/* @0x2e0064 vmul.f32 s11, s9, s20 */
/* @0x2e0068 vnmls.f32 s13, s8, s18 */
/* @0x2e006c vnmls.f32 s10, s14, s20 */
/* @0x2e0070 vmla.f32 s11, s7, s21 */
/* @0x2e0074 vmul.f32 s21, s9, s21 */
/* @0x2e0078 vadd.f32 s15, s15, s23 */
/* @0x2e007c vadd.f32 s16, s12, s16 */
/* @0x2e0080 vsub.f32 s16, s15, s16 */
/* @0x2e0084 vnmls.f32 s21, s7, s20 */
/* @0x2e0088 vadd.f32 s13, s13, s22 */
/* @0x2e008c vadd.f32 s10, s10, s17 */
/* @0x2e0090 vmul.f32 s16, s11, s16 */
/* @0x2e0094 vsub.f32 s13, s13, s10 */
/* @0x2e0098 vmla.f32 s16, s21, s13 */
/* @0x2e009c vcmpe.f32 s16, #0 */
/* @0x2e00a0 vmrs APSR_nzcv, fpscr */
/* @0x2e00a4 vmovpl r0, s16 */
/* @0x2e00a8 bpl 0x2dff7c <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x288> */
/* @0x2e00ac vneg.f32 s7, s7 */
/* @0x2e00b0 vneg.f32 s9, s9 */
/* @0x2e00b4 vstr s7, [r4, #92] */
/* @0x2e00b8 vneg.f32 s16, s16 */
/* @0x2e00bc vstr s9, [r4, #96] */
/* @0x2e00c0 vmov r0, s16 */
/* @0x2e00c4 b 0x2dff7c <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x288> */
/* @0x2e00c8 vldr s7, [r4, #92] */
/* @0x2e00cc vldr s9, [r4, #96] */
/* @0x2e00d0 b 0x2e001c <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x328> */
/* @0x2e00d4 mov r3, #0 */
/* @0x2e00d8 str r3, [r4, #0x50] */
/* @0x2e00dc ldrb r0, [r7, #0x6] */
/* @0x2e00e0 ldrb r1, [r7, #0x9] */
/* @0x2e00e4 ldr r2, [r8, #0x10] */
/* @0x2e00e8 ldr r3, [r9, #0x10] */
/* @0x2e00ec add r2, r2, r0, lsl #3 */
/* @0x2e00f0 vldr s13, [r2, #4] */
/* @0x2e00f4 add r3, r3, r1, lsl #3 */
/* @0x2e00f8 vmul.f32 s15, s13, s18 */
/* @0x2e00fc vldr s11, [r3, #4] */
/* @0x2e0100 vldr s10, [r2] */
/* @0x2e0104 vldr s14, [r3] */
/* @0x2e0108 vmul.f32 s12, s11, s20 */
/* @0x2e010c vmla.f32 s15, s10, s19 */
/* @0x2e0110 vmul.f32 s13, s13, s19 */
/* @0x2e0114 vmul.f32 s11, s11, s21 */
/* @0x2e0118 vmla.f32 s12, s14, s21 */
/* @0x2e011c vnmls.f32 s13, s10, s18 */
/* @0x2e0120 vnmls.f32 s11, s14, s20 */
/* @0x2e0124 vadd.f32 s23, s15, s23 */
/* @0x2e0128 vadd.f32 s16, s12, s16 */
/* @0x2e012c vsub.f32 s16, s16, s23 */
/* @0x2e0130 vadd.f32 s22, s13, s22 */
/* @0x2e0134 vstr s16, [r4, #96] */
/* @0x2e0138 vadd.f32 s17, s11, s17 */
/* @0x2e013c vmul.f32 s16, s16, s16 */
/* @0x2e0140 vsub.f32 s17, s17, s22 */
/* @0x2e0144 vmla.f32 s16, s17, s17 */
/* @0x2e0148 vstr s17, [r4, #92] */
/* @0x2e014c vsqrt.f32 s15, s16 */
/* @0x2e0150 vcmp.f32 s15, s15 */
/* @0x2e0154 vmrs APSR_nzcv, fpscr */
/* @0x2e0158 bne 0x2e01b4 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x4c0> */
/* @0x2e015c vldr s14, [pc, #96] */
/* @0x2e0160 vcmpe.f32 s15, s14 */
/* @0x2e0164 vmrs APSR_nzcv, fpscr */
/* @0x2e0168 vmovpl.f32 s12, #1.000000e+00 */
/* @0x2e016c vmovpl r0, s15 */
/* @0x2e0170 vldrpl s14, [r4, #92] */
/* @0x2e0174 vldrpl s13, [r4, #96] */
/* @0x2e0178 movmi r0, #0 */
/* @0x2e017c vdivpl.f32 s15, s12, s15 */
/* @0x2e0180 vmulpl.f32 s14, s14, s15 */
/* @0x2e0184 vmulpl.f32 s15, s13, s15 */
/* @0x2e0188 vstrpl s14, [r4, #92] */
/* @0x2e018c vstrpl s15, [r4, #96] */
/* @0x2e0190 b 0x2dff7c <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x288> */
/* @0x2e0194 vmov r0, s12 */
/* @0x2e0198 bl 0xb6700 <sqrtf@plt> */
/* @0x2e019c vmov s11, r0 */
/* @0x2e01a0 b 0x2dfea4 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x1b0> */
/* @0x2e01a4 vmov r0, s14 */
/* @0x2e01a8 bl 0xb6700 <sqrtf@plt> */
/* @0x2e01ac vmov s15, r0 */
/* @0x2e01b0 b 0x2dffe8 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x2f4> */
/* @0x2e01b4 vmov r0, s16 */
/* @0x2e01b8 bl 0xb6700 <sqrtf@plt> */
/* @0x2e01bc vmov s15, r0 */
/* @0x2e01c0 b 0x2e015c <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x468> */
/* @0x2e01c4 strlo r0, [r0], #-0 */

/* ── FUNC 0x2e01c8 · b2SeparationFunction::FindMinSeparation(int*, int*, float) const · size=1228 · insn=307 */
/* @0x2e01c8 push {r3, r4, r5, r6, r7, lr} */
/* @0x2e01cc vpush {d8, d9, d10, d11} */
/* @0x2e01d0 vmov.f32 s17, #1.000000e+00 */
/* @0x2e01d4 vldr s18, [r0, #36] */
/* @0x2e01d8 vmov s16, r3 */
/* @0x2e01dc vldr s15, [r0, #32] */
/* @0x2e01e0 mov r4, r0 */
/* @0x2e01e4 mov r5, r1 */
/* @0x2e01e8 mov r6, r2 */
/* @0x2e01ec vmul.f32 s18, s16, s18 */
/* @0x2e01f0 vsub.f32 s17, s17, s16 */
/* @0x2e01f4 vmla.f32 s18, s17, s15 */
/* @0x2e01f8 vmov r0, s18 */
/* @0x2e01fc bl 0xb6580 <sinf@plt> */
/* @0x2e0200 vmov s19, r0 */
/* @0x2e0204 vmov r0, s18 */
/* @0x2e0208 bl 0xb658c <cosf@plt> */
/* @0x2e020c vldr s23, [r4, #72] */
/* @0x2e0210 vmul.f32 s23, s16, s23 */
/* @0x2e0214 vldr s15, [r4, #12] */
/* @0x2e0218 vldr s21, [r4, #24] */
/* @0x2e021c vldr s22, [r4, #28] */
/* @0x2e0220 vldr s10, [r4, #68] */
/* @0x2e0224 vldr s13, [r4, #8] */
/* @0x2e0228 vldr s11, [r4, #16] */
/* @0x2e022c vldr s12, [r4, #20] */
/* @0x2e0230 vmul.f32 s21, s16, s21 */
/* @0x2e0234 vmul.f32 s14, s15, s19 */
/* @0x2e0238 vmov s18, r0 */
/* @0x2e023c vmul.f32 s22, s16, s22 */
/* @0x2e0240 vmul.f32 s15, s15, s18 */
/* @0x2e0244 vmla.f32 s23, s17, s10 */
/* @0x2e0248 vnmls.f32 s14, s13, s18 */
/* @0x2e024c vmov r0, s23 */
/* @0x2e0250 vmla.f32 s15, s13, s19 */
/* @0x2e0254 vmla.f32 s21, s17, s11 */
/* @0x2e0258 vmla.f32 s22, s17, s12 */
/* @0x2e025c vsub.f32 s21, s21, s14 */
/* @0x2e0260 vsub.f32 s22, s22, s15 */
/* @0x2e0264 bl 0xb6580 <sinf@plt> */
/* @0x2e0268 vmov s20, r0 */
/* @0x2e026c vmov r0, s23 */
/* @0x2e0270 bl 0xb658c <cosf@plt> */
/* @0x2e0274 vldr s15, [r4, #48] */
/* @0x2e0278 vldr s12, [r4, #60] */
/* @0x2e027c vmul.f32 s13, s15, s20 */
/* @0x2e0280 vldr s8, [r4, #64] */
/* @0x2e0284 vldr s11, [r4, #44] */
/* @0x2e0288 vldr s9, [r4, #52] */
/* @0x2e028c vldr s10, [r4, #56] */
/* @0x2e0290 vmul.f32 s12, s16, s12 */
/* @0x2e0294 vmul.f32 s16, s16, s8 */
/* @0x2e0298 vmov s14, r0 */
/* @0x2e029c ldr r0, [r4, #0x50] */
/* @0x2e02a0 cmp r0, #1 */
/* @0x2e02a4 vmul.f32 s15, s15, s14 */
/* @0x2e02a8 vmla.f32 s12, s17, s9 */
/* @0x2e02ac vnmls.f32 s13, s11, s14 */
/* @0x2e02b0 vmla.f32 s15, s11, s20 */
/* @0x2e02b4 vmla.f32 s16, s17, s10 */
/* @0x2e02b8 vsub.f32 s7, s12, s13 */
/* @0x2e02bc vsub.f32 s16, s16, s15 */
/* @0x2e02c0 beq 0x2e0560 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x398> */
/* @0x2e02c4 cmp r0, #2 */
/* @0x2e02c8 beq 0x2e045c <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x294> */
/* @0x2e02cc cmp r0, #0 */
/* @0x2e02d0 beq 0x2e02f0 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x128> */
/* @0x2e02d4 vldr s22, [pc, #948] */
/* @0x2e02d8 vmov r0, s22 */
/* @0x2e02dc vpop {d8, d9, d10, d11} */
/* @0x2e02e0 mvn r3, #0 */
/* @0x2e02e4 str r3, [r5] */
/* @0x2e02e8 str r3, [r6] */
/* @0x2e02ec pop {r3, r4, r5, r6, r7, pc} */
/* @0x2e02f0 vldr s5, [r4, #96] */
/* @0x2e02f4 vmul.f32 s8, s5, s18 */
/* @0x2e02f8 vldr s6, [r4, #92] */
/* @0x2e02fc ldr r7, [r4] */
/* @0x2e0300 ldr r3, [r7, #0x10] */
/* @0x2e0304 vldr s12, [r3, #4] */
/* @0x2e0308 ldr r2, [r7, #0x14] */
/* @0x2e030c vldr s13, [r3] */
/* @0x2e0310 cmp r2, #1 */
/* @0x2e0314 vmls.f32 s8, s19, s6 */
/* @0x2e0318 vmul.f32 s9, s5, s19 */
/* @0x2e031c vmla.f32 s9, s6, s18 */
/* @0x2e0320 vneg.f32 s10, s5 */
/* @0x2e0324 vmul.f32 s12, s8, s12 */
/* @0x2e0328 vmul.f32 s11, s10, s20 */
/* @0x2e032c vmul.f32 s10, s10, s14 */
/* @0x2e0330 vneg.f32 s15, s6 */
/* @0x2e0334 vmla.f32 s12, s9, s13 */
/* @0x2e0338 vmla.f32 s11, s15, s14 */
/* @0x2e033c vmls.f32 s10, s20, s15 */
/* @0x2e0340 ble 0x2e0664 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x49c> */
/* @0x2e0344 add r3, r3, #8 */
/* @0x2e0348 mov r1, r0 */
/* @0x2e034c mov r0, #1 */
/* @0x2e0350 vldr s15, [r3, #4] */
/* @0x2e0354 vldr s13, [r3] */
/* @0x2e0358 add r3, r3, #8 */
/* @0x2e035c vmul.f32 s15, s8, s15 */
/* @0x2e0360 vmla.f32 s15, s9, s13 */
/* @0x2e0364 vcmpe.f32 s12, s15 */
/* @0x2e0368 vmrs APSR_nzcv, fpscr */
/* @0x2e036c movmi r1, r0 */
/* @0x2e0370 add r0, r0, #1 */
/* @0x2e0374 vmovmi.f32 s12, s15 */
/* @0x2e0378 cmp r0, r2 */
/* @0x2e037c bne 0x2e0350 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x188> */
/* @0x2e0380 ldr r4, [r4, #0x4] */
/* @0x2e0384 str r1, [r5] */
/* @0x2e0388 ldr r3, [r4, #0x10] */
/* @0x2e038c vldr s12, [r3, #4] */
/* @0x2e0390 vmul.f32 s12, s10, s12 */
/* @0x2e0394 ldr r12, [r4, #0x14] */
/* @0x2e0398 vldr s15, [r3] */
/* @0x2e039c cmp r12, #1 */
/* @0x2e03a0 vmla.f32 s12, s11, s15 */
/* @0x2e03a4 ble 0x2e066c <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x4a4> */
/* @0x2e03a8 add r3, r3, #8 */
/* @0x2e03ac mov r2, #0 */
/* @0x2e03b0 mov r0, #1 */
/* @0x2e03b4 vldr s15, [r3, #4] */
/* @0x2e03b8 vldr s13, [r3] */
/* @0x2e03bc add r3, r3, #8 */
/* @0x2e03c0 vmul.f32 s15, s10, s15 */
/* @0x2e03c4 vmla.f32 s15, s11, s13 */
/* @0x2e03c8 vcmpe.f32 s15, s12 */
/* @0x2e03cc vmrs APSR_nzcv, fpscr */
/* @0x2e03d0 movgt r2, r0 */
/* @0x2e03d4 add r0, r0, #1 */
/* @0x2e03d8 vmovgt.f32 s12, s15 */
/* @0x2e03dc cmp r0, r12 */
/* @0x2e03e0 bne 0x2e03b4 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x1ec> */
/* @0x2e03e4 lsl r3, r2, #3 */
/* @0x2e03e8 str r2, [r6] */
/* @0x2e03ec ldr r0, [r5] */
/* @0x2e03f0 ldr r2, [r7, #0x10] */
/* @0x2e03f4 ldr r1, [r4, #0x10] */
/* @0x2e03f8 add r2, r2, r0, lsl #3 */
/* @0x2e03fc vldr s12, [r2, #4] */
/* @0x2e0400 add r3, r1, r3 */
/* @0x2e0404 vmul.f32 s11, s12, s18 */
/* @0x2e0408 vldr s13, [r3, #4] */
/* @0x2e040c vldr s9, [r2] */
/* @0x2e0410 vldr s10, [r3] */
/* @0x2e0414 vmul.f32 s15, s13, s14 */
/* @0x2e0418 vmul.f32 s12, s12, s19 */
/* @0x2e041c vmla.f32 s11, s9, s19 */
/* @0x2e0420 vmul.f32 s13, s13, s20 */
/* @0x2e0424 vmla.f32 s15, s10, s20 */
/* @0x2e0428 vnmls.f32 s12, s9, s18 */
/* @0x2e042c vnmls.f32 s13, s10, s14 */
/* @0x2e0430 vadd.f32 s16, s15, s16 */
/* @0x2e0434 vadd.f32 s22, s11, s22 */
/* @0x2e0438 vsub.f32 s22, s16, s22 */
/* @0x2e043c vadd.f32 s21, s12, s21 */
/* @0x2e0440 vadd.f32 s13, s13, s7 */
/* @0x2e0444 vmul.f32 s22, s5, s22 */
/* @0x2e0448 vsub.f32 s13, s13, s21 */
/* @0x2e044c vmla.f32 s22, s6, s13 */
/* @0x2e0450 vmov r0, s22 */
/* @0x2e0454 vpop {d8, d9, d10, d11} */
/* @0x2e0458 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2e045c vldr s9, [r4, #96] */
/* @0x2e0460 vmul.f32 s8, s9, s14 */
/* @0x2e0464 vldr s12, [r4, #92] */
/* @0x2e0468 vldr s15, [r4, #88] */
/* @0x2e046c vldr s6, [r4, #84] */
/* @0x2e0470 ldr r12, [r4] */
/* @0x2e0474 mvn r3, #0 */
/* @0x2e0478 str r3, [r6] */
/* @0x2e047c ldr r3, [r12, #0x10] */
/* @0x2e0480 vldr s13, [r3, #4] */
/* @0x2e0484 ldr r0, [r12, #0x14] */
/* @0x2e0488 vldr s4, [r3] */
/* @0x2e048c cmp r0, #1 */
/* @0x2e0490 vmla.f32 s8, s12, s20 */
/* @0x2e0494 vmul.f32 s9, s9, s20 */
/* @0x2e0498 vnmls.f32 s9, s12, s14 */
/* @0x2e049c vneg.f32 s11, s8 */
/* @0x2e04a0 vmul.f32 s10, s11, s18 */
/* @0x2e04a4 vneg.f32 s5, s9 */
/* @0x2e04a8 vmul.f32 s12, s15, s20 */
/* @0x2e04ac vmul.f32 s11, s11, s19 */
/* @0x2e04b0 vmls.f32 s10, s19, s5 */
/* @0x2e04b4 vmul.f32 s15, s15, s14 */
/* @0x2e04b8 vmla.f32 s11, s5, s18 */
/* @0x2e04bc vnmls.f32 s12, s6, s14 */
/* @0x2e04c0 vmla.f32 s15, s6, s20 */
/* @0x2e04c4 vmul.f32 s13, s10, s13 */
/* @0x2e04c8 vadd.f32 s12, s12, s7 */
/* @0x2e04cc vmla.f32 s13, s11, s4 */
/* @0x2e04d0 vadd.f32 s16, s15, s16 */
/* @0x2e04d4 ble 0x2e0678 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x4b0> */
/* @0x2e04d8 add r3, r3, #8 */
/* @0x2e04dc mov r1, #0 */
/* @0x2e04e0 mov r2, #1 */
/* @0x2e04e4 vldr s15, [r3, #4] */
/* @0x2e04e8 vldr s14, [r3] */
/* @0x2e04ec add r3, r3, #8 */
/* @0x2e04f0 vmul.f32 s15, s10, s15 */
/* @0x2e04f4 vmla.f32 s15, s11, s14 */
/* @0x2e04f8 vcmpe.f32 s13, s15 */
/* @0x2e04fc vmrs APSR_nzcv, fpscr */
/* @0x2e0500 movmi r1, r2 */
/* @0x2e0504 add r2, r2, #1 */
/* @0x2e0508 vmovmi.f32 s13, s15 */
/* @0x2e050c cmp r2, r0 */
/* @0x2e0510 bne 0x2e04e4 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x31c> */
/* @0x2e0514 lsl r3, r1, #3 */
/* @0x2e0518 str r1, [r5] */
/* @0x2e051c ldr r2, [r12, #0x10] */
/* @0x2e0520 add r3, r2, r3 */
/* @0x2e0524 vldr s14, [r3, #4] */
/* @0x2e0528 vmul.f32 s11, s14, s18 */
/* @0x2e052c vldr s10, [r3] */
/* @0x2e0530 vmul.f32 s14, s14, s19 */
/* @0x2e0534 vmla.f32 s11, s10, s19 */
/* @0x2e0538 vnmls.f32 s14, s10, s18 */
/* @0x2e053c vadd.f32 s22, s11, s22 */
/* @0x2e0540 vsub.f32 s22, s22, s16 */
/* @0x2e0544 vadd.f32 s21, s14, s21 */
/* @0x2e0548 vmul.f32 s22, s8, s22 */
/* @0x2e054c vsub.f32 s12, s21, s12 */
/* @0x2e0550 vmla.f32 s22, s9, s12 */
/* @0x2e0554 vmov r0, s22 */
/* @0x2e0558 vpop {d8, d9, d10, d11} */
/* @0x2e055c pop {r3, r4, r5, r6, r7, pc} */
/* @0x2e0560 vldr s9, [r4, #96] */
/* @0x2e0564 vmul.f32 s8, s9, s18 */
/* @0x2e0568 vldr s13, [r4, #92] */
/* @0x2e056c vldr s15, [r4, #88] */
/* @0x2e0570 vldr s6, [r4, #84] */
/* @0x2e0574 ldr r4, [r4, #0x4] */
/* @0x2e0578 mvn r3, #0 */
/* @0x2e057c str r3, [r5] */
/* @0x2e0580 ldr r3, [r4, #0x10] */
/* @0x2e0584 vldr s12, [r3, #4] */
/* @0x2e0588 ldr r12, [r4, #0x14] */
/* @0x2e058c vldr s4, [r3] */
/* @0x2e0590 cmp r12, #1 */
/* @0x2e0594 vmla.f32 s8, s13, s19 */
/* @0x2e0598 vmul.f32 s9, s9, s19 */
/* @0x2e059c vnmls.f32 s9, s13, s18 */
/* @0x2e05a0 vneg.f32 s11, s8 */
/* @0x2e05a4 vmul.f32 s10, s11, s14 */
/* @0x2e05a8 vneg.f32 s5, s9 */
/* @0x2e05ac vmul.f32 s13, s15, s19 */
/* @0x2e05b0 vmul.f32 s11, s11, s20 */
/* @0x2e05b4 vmls.f32 s10, s20, s5 */
/* @0x2e05b8 vmul.f32 s15, s15, s18 */
/* @0x2e05bc vmla.f32 s11, s5, s14 */
/* @0x2e05c0 vnmls.f32 s13, s6, s18 */
/* @0x2e05c4 vmla.f32 s15, s6, s19 */
/* @0x2e05c8 vmul.f32 s12, s10, s12 */
/* @0x2e05cc vadd.f32 s21, s13, s21 */
/* @0x2e05d0 vmla.f32 s12, s11, s4 */
/* @0x2e05d4 vadd.f32 s22, s15, s22 */
/* @0x2e05d8 ble 0x2e0684 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x4bc> */
/* @0x2e05dc add r3, r3, #8 */
/* @0x2e05e0 mov r1, r0 */
/* @0x2e05e4 mov r2, #0 */
/* @0x2e05e8 vldr s15, [r3, #4] */
/* @0x2e05ec vldr s13, [r3] */
/* @0x2e05f0 add r3, r3, #8 */
/* @0x2e05f4 vmul.f32 s15, s10, s15 */
/* @0x2e05f8 vmla.f32 s15, s11, s13 */
/* @0x2e05fc vcmpe.f32 s12, s15 */
/* @0x2e0600 vmrs APSR_nzcv, fpscr */
/* @0x2e0604 movmi r2, r1 */
/* @0x2e0608 add r1, r1, #1 */
/* @0x2e060c vmovmi.f32 s12, s15 */
/* @0x2e0610 cmp r1, r12 */
/* @0x2e0614 bne 0x2e05e8 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x420> */
/* @0x2e0618 lsl r3, r2, #3 */
/* @0x2e061c str r2, [r6] */
/* @0x2e0620 ldr r2, [r4, #0x10] */
/* @0x2e0624 add r3, r2, r3 */
/* @0x2e0628 vldr s11, [r3, #4] */
/* @0x2e062c vmul.f32 s15, s11, s14 */
/* @0x2e0630 vldr s12, [r3] */
/* @0x2e0634 vmul.f32 s13, s11, s20 */
/* @0x2e0638 vmla.f32 s15, s12, s20 */
/* @0x2e063c vnmls.f32 s13, s12, s14 */
/* @0x2e0640 vadd.f32 s16, s15, s16 */
/* @0x2e0644 vsub.f32 s22, s16, s22 */
/* @0x2e0648 vadd.f32 s13, s13, s7 */
/* @0x2e064c vmul.f32 s22, s8, s22 */
/* @0x2e0650 vsub.f32 s13, s13, s21 */
/* @0x2e0654 vmla.f32 s22, s9, s13 */
/* @0x2e0658 vmov r0, s22 */
/* @0x2e065c vpop {d8, d9, d10, d11} */
/* @0x2e0660 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2e0664 mov r1, r0 */
/* @0x2e0668 b 0x2e0380 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x1b8> */
/* @0x2e066c mov r3, #0 */
/* @0x2e0670 mov r2, r3 */
/* @0x2e0674 b 0x2e03e8 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x220> */
/* @0x2e0678 mov r3, #0 */
/* @0x2e067c mov r1, r3 */
/* @0x2e0680 b 0x2e0518 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x350> */
/* @0x2e0684 mov r3, #0 */
/* @0x2e0688 mov r2, r3 */
/* @0x2e068c b 0x2e061c <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x454> */
/* @0x2e0690 andeq r0, r0, r0 */

/* ── FUNC 0x2e0694 · b2SeparationFunction::Evaluate(int, int, float) const · size=668 · insn=167 */
/* @0x2e0694 push {r4, r5, r6, lr} */
/* @0x2e0698 vpush {d8, d9, d10, d11} */
/* @0x2e069c vmov.f32 s17, #1.000000e+00 */
/* @0x2e06a0 vldr s18, [r0, #36] */
/* @0x2e06a4 vmov s16, r3 */
/* @0x2e06a8 vldr s15, [r0, #32] */
/* @0x2e06ac mov r4, r0 */
/* @0x2e06b0 mov r5, r1 */
/* @0x2e06b4 mov r6, r2 */
/* @0x2e06b8 vmul.f32 s18, s16, s18 */
/* @0x2e06bc vsub.f32 s17, s17, s16 */
/* @0x2e06c0 vmla.f32 s18, s17, s15 */
/* @0x2e06c4 vmov r0, s18 */
/* @0x2e06c8 bl 0xb6580 <sinf@plt> */
/* @0x2e06cc vmov s20, r0 */
/* @0x2e06d0 vmov r0, s18 */
/* @0x2e06d4 bl 0xb658c <cosf@plt> */
/* @0x2e06d8 vldr s21, [r4, #72] */
/* @0x2e06dc vmul.f32 s21, s16, s21 */
/* @0x2e06e0 vldr s15, [r4, #12] */
/* @0x2e06e4 vldr s12, [r4, #24] */
/* @0x2e06e8 vldr s14, [r4, #28] */
/* @0x2e06ec vldr s8, [r4, #68] */
/* @0x2e06f0 vldr s11, [r4, #8] */
/* @0x2e06f4 vldr s9, [r4, #16] */
/* @0x2e06f8 vldr s10, [r4, #20] */
/* @0x2e06fc vmul.f32 s12, s16, s12 */
/* @0x2e0700 vmul.f32 s13, s15, s20 */
/* @0x2e0704 vmov s19, r0 */
/* @0x2e0708 vmul.f32 s14, s16, s14 */
/* @0x2e070c vmul.f32 s15, s15, s19 */
/* @0x2e0710 vmla.f32 s21, s17, s8 */
/* @0x2e0714 vmla.f32 s12, s17, s9 */
/* @0x2e0718 vmov r0, s21 */
/* @0x2e071c vnmls.f32 s13, s11, s19 */
/* @0x2e0720 vmla.f32 s15, s11, s20 */
/* @0x2e0724 vmla.f32 s14, s17, s10 */
/* @0x2e0728 vsub.f32 s22, s12, s13 */
/* @0x2e072c vsub.f32 s23, s14, s15 */
/* @0x2e0730 bl 0xb6580 <sinf@plt> */
/* @0x2e0734 vmov s18, r0 */
/* @0x2e0738 vmov r0, s21 */
/* @0x2e073c bl 0xb658c <cosf@plt> */
/* @0x2e0740 vldr s10, [r4, #48] */
/* @0x2e0744 vldr s12, [r4, #60] */
/* @0x2e0748 vldr s7, [r4, #64] */
/* @0x2e074c vmul.f32 s12, s16, s12 */
/* @0x2e0750 vldr s11, [r4, #44] */
/* @0x2e0754 vldr s8, [r4, #52] */
/* @0x2e0758 vldr s9, [r4, #56] */
/* @0x2e075c ldr r3, [r4, #0x50] */
/* @0x2e0760 cmp r3, #1 */
/* @0x2e0764 vmul.f32 s13, s10, s18 */
/* @0x2e0768 vmul.f32 s16, s16, s7 */
/* @0x2e076c vmov s15, r0 */
/* @0x2e0770 vmul.f32 s14, s10, s15 */
/* @0x2e0774 vmla.f32 s12, s17, s8 */
/* @0x2e0778 vnmls.f32 s13, s11, s15 */
/* @0x2e077c vmla.f32 s14, s11, s18 */
/* @0x2e0780 vmla.f32 s16, s17, s9 */
/* @0x2e0784 vsub.f32 s13, s12, s13 */
/* @0x2e0788 vsub.f32 s16, s16, s14 */
/* @0x2e078c beq 0x2e08ac <_ZNK20b2SeparationFunction8EvaluateEiif+0x218> */
/* @0x2e0790 cmp r3, #2 */
/* @0x2e0794 beq 0x2e082c <_ZNK20b2SeparationFunction8EvaluateEiif+0x198> */
/* @0x2e0798 cmp r3, #0 */
/* @0x2e079c beq 0x2e07b0 <_ZNK20b2SeparationFunction8EvaluateEiif+0x11c> */
/* @0x2e07a0 vpop {d8, d9, d10, d11} */
/* @0x2e07a4 vldr s15, [pc, #384] */
/* @0x2e07a8 vmov r0, s15 */
/* @0x2e07ac pop {r4, r5, r6, pc} */
/* @0x2e07b0 ldr r2, [r4] */
/* @0x2e07b4 vldr s6, [r4, #96] */
/* @0x2e07b8 ldr r3, [r4, #0x4] */
/* @0x2e07bc vldr s7, [r4, #92] */
/* @0x2e07c0 ldr r2, [r2, #0x10] */
/* @0x2e07c4 ldr r3, [r3, #0x10] */
/* @0x2e07c8 add r5, r2, r5, lsl #3 */
/* @0x2e07cc vldr s12, [r5, #4] */
/* @0x2e07d0 add r6, r3, r6, lsl #3 */
/* @0x2e07d4 vmul.f32 s14, s12, s19 */
/* @0x2e07d8 vldr s11, [r6, #4] */
/* @0x2e07dc vldr s8, [r5] */
/* @0x2e07e0 vldr s9, [r6] */
/* @0x2e07e4 vmul.f32 s10, s11, s15 */
/* @0x2e07e8 vmul.f32 s12, s12, s20 */
/* @0x2e07ec vmla.f32 s14, s8, s20 */
/* @0x2e07f0 vmul.f32 s11, s11, s18 */
/* @0x2e07f4 vmla.f32 s10, s9, s18 */
/* @0x2e07f8 vnmls.f32 s12, s8, s19 */
/* @0x2e07fc vnmls.f32 s11, s9, s15 */
/* @0x2e0800 vadd.f32 s23, s14, s23 */
/* @0x2e0804 vadd.f32 s16, s10, s16 */
/* @0x2e0808 vsub.f32 s15, s16, s23 */
/* @0x2e080c vadd.f32 s22, s12, s22 */
/* @0x2e0810 vadd.f32 s13, s11, s13 */
/* @0x2e0814 vmul.f32 s15, s15, s6 */
/* @0x2e0818 vsub.f32 s13, s13, s22 */
/* @0x2e081c vpop {d8, d9, d10, d11} */
/* @0x2e0820 vmla.f32 s15, s13, s7 */
/* @0x2e0824 vmov r0, s15 */
/* @0x2e0828 pop {r4, r5, r6, pc} */
/* @0x2e082c ldr r3, [r4] */
/* @0x2e0830 vldr s9, [r4, #88] */
/* @0x2e0834 vmul.f32 s8, s9, s15 */
/* @0x2e0838 vldr s6, [r4, #84] */
/* @0x2e083c vldr s11, [r4, #96] */
/* @0x2e0840 vldr s7, [r4, #92] */
/* @0x2e0844 ldr r3, [r3, #0x10] */
/* @0x2e0848 add r5, r3, r5, lsl #3 */
/* @0x2e084c vldr s12, [r5, #4] */
/* @0x2e0850 vldr s5, [r5] */
/* @0x2e0854 vmul.f32 s14, s12, s19 */
/* @0x2e0858 vmul.f32 s9, s9, s18 */
/* @0x2e085c vmul.f32 s12, s12, s20 */
/* @0x2e0860 vmla.f32 s14, s5, s20 */
/* @0x2e0864 vmla.f32 s8, s6, s18 */
/* @0x2e0868 vmul.f32 s10, s11, s15 */
/* @0x2e086c vnmls.f32 s12, s5, s19 */
/* @0x2e0870 vnmls.f32 s9, s6, s15 */
/* @0x2e0874 vmul.f32 s11, s11, s18 */
/* @0x2e0878 vmla.f32 s10, s7, s18 */
/* @0x2e087c vadd.f32 s14, s14, s23 */
/* @0x2e0880 vadd.f32 s16, s8, s16 */
/* @0x2e0884 vsub.f32 s14, s14, s16 */
/* @0x2e0888 vnmls.f32 s11, s7, s15 */
/* @0x2e088c vadd.f32 s12, s12, s22 */
/* @0x2e0890 vpop {d8, d9, d10, d11} */
/* @0x2e0894 vadd.f32 s13, s9, s13 */
/* @0x2e0898 vmul.f32 s15, s10, s14 */
/* @0x2e089c vsub.f32 s13, s12, s13 */
/* @0x2e08a0 vmla.f32 s15, s11, s13 */
/* @0x2e08a4 vmov r0, s15 */
/* @0x2e08a8 pop {r4, r5, r6, pc} */
/* @0x2e08ac ldr r3, [r4, #0x4] */
/* @0x2e08b0 vldr s9, [r4, #88] */
/* @0x2e08b4 vmul.f32 s8, s9, s19 */
/* @0x2e08b8 vldr s6, [r4, #84] */
/* @0x2e08bc vldr s11, [r4, #96] */
/* @0x2e08c0 vldr s7, [r4, #92] */
/* @0x2e08c4 ldr r3, [r3, #0x10] */
/* @0x2e08c8 add r6, r3, r6, lsl #3 */
/* @0x2e08cc vldr s12, [r6, #4] */
/* @0x2e08d0 vldr s5, [r6] */
/* @0x2e08d4 vmul.f32 s14, s12, s15 */
/* @0x2e08d8 vmul.f32 s9, s9, s20 */
/* @0x2e08dc vmul.f32 s12, s12, s18 */
/* @0x2e08e0 vmla.f32 s14, s5, s18 */
/* @0x2e08e4 vmla.f32 s8, s6, s20 */
/* @0x2e08e8 vmul.f32 s10, s11, s19 */
/* @0x2e08ec vnmls.f32 s12, s5, s15 */
/* @0x2e08f0 vnmls.f32 s9, s6, s19 */
/* @0x2e08f4 vmul.f32 s11, s11, s20 */
/* @0x2e08f8 vmla.f32 s10, s7, s20 */
/* @0x2e08fc vadd.f32 s16, s14, s16 */
/* @0x2e0900 vadd.f32 s23, s8, s23 */
/* @0x2e0904 vsub.f32 s15, s16, s23 */
/* @0x2e0908 vnmls.f32 s11, s7, s19 */
/* @0x2e090c vadd.f32 s22, s9, s22 */
/* @0x2e0910 vadd.f32 s13, s12, s13 */
/* @0x2e0914 vmul.f32 s15, s10, s15 */
/* @0x2e0918 vsub.f32 s13, s13, s22 */
/* @0x2e091c vpop {d8, d9, d10, d11} */
/* @0x2e0920 vmla.f32 s15, s11, s13 */
/* @0x2e0924 vmov r0, s15 */
/* @0x2e0928 pop {r4, r5, r6, pc} */
/* @0x2e092c andeq r0, r0, r0 */

/* ── FUNC 0x2e0930 · b2TimeOfImpact(b2TOIOutput*, b2TOIInput const*) · size=1492 · insn=373 */
/* @0x2e0930 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e0934 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2e0938 sub sp, sp, #396 */
/* @0x2e093c vldr s16, [pc, #920] */
/* @0x2e0940 add r4, sp, #84 */
/* @0x2e0944 add r6, sp, #128 */
/* @0x2e0948 str r0, [sp, #0x30] */
/* @0x2e094c mov r7, #0 */
/* @0x2e0950 mov r0, r4 */
/* @0x2e0954 str r4, [sp, #0x44] */
/* @0x2e0958 str r1, [sp, #0x24] */
/* @0x2e095c add r4, sp, #128 */
/* @0x2e0960 str r6, [sp, #0x34] */
/* @0x2e0964 bl 0x2e10b8 <_ZN7b2TimerC2Ev> */
/* @0x2e0968 ldr r6, [sp, #0x24] */
/* @0x2e096c vmov.f32 s26, #1.000000e+00 */
/* @0x2e0970 ldr r12, [sp, #0x24] */
/* @0x2e0974 vldr s21, [pc, #868] */
/* @0x2e0978 ldr r11, [pc, #0x370] */
/* @0x2e097c vldr s24, [pc, #864] */
/* @0x2e0980 ldr r6, [r6, #0x80] */
/* @0x2e0984 add r5, r12, #56 */
/* @0x2e0988 ldr r12, [pc, #0x364] */
/* @0x2e098c add r11, pc, r11 */
/* @0x2e0990 ldm r5!, {r0, r1, r2, r3} */
/* @0x2e0994 vldr s22, [pc, #844] */
/* @0x2e0998 str r6, [sp, #0x28] */
/* @0x2e099c ldr r6, [sp, #0x24] */
/* @0x2e09a0 ldr r8, [r11, r12] */
/* @0x2e09a4 add r12, sp, #164 */
/* @0x2e09a8 add lr, r6, #92 */
/* @0x2e09ac str r12, [sp, #0x38] */
/* @0x2e09b0 ldr r6, [sp, #0x28] */
/* @0x2e09b4 ldr r12, [sp, #0x30] */
/* @0x2e09b8 stm r4!, {r0, r1, r2, r3} */
/* @0x2e09bc str r6, [r12, #0x4] */
/* @0x2e09c0 add r6, sp, #200 */
/* @0x2e09c4 str r6, [sp, #0x2c] */
/* @0x2e09c8 add r12, sp, #164 */
/* @0x2e09cc ldr r6, [r8] */
/* @0x2e09d0 ldm r5!, {r0, r1, r2, r3} */
/* @0x2e09d4 add r6, r6, #1 */
/* @0x2e09d8 str r6, [r8] */
/* @0x2e09dc ldr r6, [sp, #0x24] */
/* @0x2e09e0 add r6, r6, #28 */
/* @0x2e09e4 str r6, [sp, #0x3c] */
/* @0x2e09e8 ldr r6, [sp, #0x30] */
/* @0x2e09ec stm r4!, {r0, r1, r2, r3} */
/* @0x2e09f0 ldr r5, [r5] */
/* @0x2e09f4 ldm lr!, {r0, r1, r2, r3} */
/* @0x2e09f8 str r7, [r6] */
/* @0x2e09fc vldr s19, [sp, #152] */
/* @0x2e0a00 vdiv.f32 s11, s19, s16 */
/* @0x2e0a04 str r5, [r4] */
/* @0x2e0a08 add r6, sp, #104 */
/* @0x2e0a0c add r4, sp, #92 */
/* @0x2e0a10 stm r12!, {r0, r1, r2, r3} */
/* @0x2e0a14 add r5, sp, #200 */
/* @0x2e0a18 ldm lr!, {r0, r1, r2, r3} */
/* @0x2e0a1c str r6, [sp, #0x40] */
/* @0x2e0a20 add r6, sp, #76 */
/* @0x2e0a24 str r4, [sp, #0x20] */
/* @0x2e0a28 add r4, sp, #292 */
/* @0x2e0a2c stm r12!, {r0, r1, r2, r3} */
/* @0x2e0a30 ldr r3, [lr] */
/* @0x2e0a34 str r3, [r12] */
/* @0x2e0a38 vmov r0, s11 */
/* @0x2e0a3c bl 0xb6910 <floorf@plt> */
/* @0x2e0a40 vldr s17, [sp, #188] */
/* @0x2e0a44 vdiv.f32 s14, s17, s16 */
/* @0x2e0a48 vldr s18, [sp, #156] */
/* @0x2e0a4c str r6, [sp, #0x18] */
/* @0x2e0a50 str r7, [sp, #0x1c] */
/* @0x2e0a54 vmov s11, r0 */
/* @0x2e0a58 vmul.f32 s15, s11, s16 */
/* @0x2e0a5c vmov r0, s14 */
/* @0x2e0a60 vsub.f32 s19, s19, s15 */
/* @0x2e0a64 vsub.f32 s18, s18, s15 */
/* @0x2e0a68 vstr s19, [sp, #152] */
/* @0x2e0a6c vstr s18, [sp, #156] */
/* @0x2e0a70 bl 0xb6910 <floorf@plt> */
/* @0x2e0a74 ldr r6, [sp, #0x24] */
/* @0x2e0a78 vldr s11, [r6, #24] */
/* @0x2e0a7c vldr s13, [r6, #52] */
/* @0x2e0a80 vadd.f32 s13, s11, s13 */
/* @0x2e0a84 add lr, sp, #392 */
/* @0x2e0a88 movw r3, #0xfed8 */
/* @0x2e0a8c movt r3, #0xffff */
/* @0x2e0a90 mov r12, r6 */
/* @0x2e0a94 vldr s15, [pc, #592] */
/* @0x2e0a98 vldr s14, [sp, #192] */
/* @0x2e0a9c strh r7, [lr, r3] */
/* @0x2e0aa0 ldr lr, [sp, #0x3c] */
/* @0x2e0aa4 vsub.f32 s15, s13, s15 */
/* @0x2e0aa8 vcmpe.f32 s15, s21 */
/* @0x2e0aac vmov.f32 s12, s19 */
/* @0x2e0ab0 vmrs APSR_nzcv, fpscr */
/* @0x2e0ab4 vmovpl.f32 s21, s15 */
/* @0x2e0ab8 vmov s11, r0 */
/* @0x2e0abc ldm r12!, {r0, r1, r2, r3} */
/* @0x2e0ac0 vmul.f32 s16, s11, s16 */
/* @0x2e0ac4 stm r5!, {r0, r1, r2, r3} */
/* @0x2e0ac8 ldm r12, {r0, r1, r2} */
/* @0x2e0acc add r12, sp, #228 */
/* @0x2e0ad0 stm r5, {r0, r1, r2} */
/* @0x2e0ad4 vsub.f32 s13, s17, s16 */
/* @0x2e0ad8 ldm lr!, {r0, r1, r2, r3} */
/* @0x2e0adc vsub.f32 s14, s14, s16 */
/* @0x2e0ae0 vstr s13, [sp, #188] */
/* @0x2e0ae4 stm r12!, {r0, r1, r2, r3} */
/* @0x2e0ae8 ldm lr, {r0, r1, r2} */
/* @0x2e0aec strb r7, [sp, #0x120] */
/* @0x2e0af0 stm r12, {r0, r1, r2} */
/* @0x2e0af4 vmov.f32 s17, s14 */
/* @0x2e0af8 vstr s14, [sp, #192] */
/* @0x2e0afc vldr s23, [sp, #144] */
/* @0x2e0b00 vldr s20, [sp, #148] */
/* @0x2e0b04 vldr s14, [sp, #136] */
/* @0x2e0b08 vldr s15, [sp, #140] */
/* @0x2e0b0c vmul.f32 s18, s24, s18 */
/* @0x2e0b10 vsub.f32 s16, s26, s24 */
/* @0x2e0b14 vmla.f32 s18, s16, s12 */
/* @0x2e0b18 vmul.f32 s17, s24, s17 */
/* @0x2e0b1c vmov r0, s18 */
/* @0x2e0b20 vmul.f32 s23, s24, s23 */
/* @0x2e0b24 vmul.f32 s20, s24, s20 */
/* @0x2e0b28 vmla.f32 s17, s16, s13 */
/* @0x2e0b2c vmla.f32 s23, s16, s14 */
/* @0x2e0b30 vmla.f32 s20, s16, s15 */
/* @0x2e0b34 bl 0xb6580 <sinf@plt> */
/* @0x2e0b38 vmov s25, r0 */
/* @0x2e0b3c vmov r0, s18 */
/* @0x2e0b40 bl 0xb658c <cosf@plt> */
/* @0x2e0b44 vldr s19, [sp, #180] */
/* @0x2e0b48 vldr s18, [sp, #184] */
/* @0x2e0b4c vmul.f32 s19, s24, s19 */
/* @0x2e0b50 vldr s14, [sp, #172] */
/* @0x2e0b54 vldr s15, [sp, #176] */
/* @0x2e0b58 vldr s29, [sp, #132] */
/* @0x2e0b5c vldr s28, [sp, #128] */
/* @0x2e0b60 vmul.f32 s18, s24, s18 */
/* @0x2e0b64 vmla.f32 s19, s16, s14 */
/* @0x2e0b68 vmov s27, r0 */
/* @0x2e0b6c vmov r0, s17 */
/* @0x2e0b70 vmla.f32 s18, s16, s15 */
/* @0x2e0b74 bl 0xb6580 <sinf@plt> */
/* @0x2e0b78 vmov s16, r0 */
/* @0x2e0b7c vmov r0, s17 */
/* @0x2e0b80 bl 0xb658c <cosf@plt> */
/* @0x2e0b84 vldr s15, [sp, #168] */
/* @0x2e0b88 vmul.f32 s12, s29, s25 */
/* @0x2e0b8c vldr s10, [sp, #164] */
/* @0x2e0b90 add r1, sp, #92 */
/* @0x2e0b94 add r2, sp, #200 */
/* @0x2e0b98 vstr s25, [sp, #264] */
/* @0x2e0b9c vstr s27, [sp, #268] */
/* @0x2e0ba0 vstr s16, [sp, #280] */
/* @0x2e0ba4 vmul.f32 s14, s15, s16 */
/* @0x2e0ba8 vmul.f32 s13, s29, s27 */
/* @0x2e0bac vmov s11, r0 */
/* @0x2e0bb0 add r0, sp, #104 */
/* @0x2e0bb4 vstr s11, [sp, #284] */
/* @0x2e0bb8 vmul.f32 s15, s15, s11 */
/* @0x2e0bbc vnmls.f32 s14, s10, s11 */
/* @0x2e0bc0 vmla.f32 s15, s10, s16 */
/* @0x2e0bc4 vnmls.f32 s12, s28, s27 */
/* @0x2e0bc8 vmla.f32 s13, s28, s25 */
/* @0x2e0bcc vsub.f32 s15, s18, s15 */
/* @0x2e0bd0 vsub.f32 s12, s23, s12 */
/* @0x2e0bd4 vstr s15, [sp, #276] */
/* @0x2e0bd8 vsub.f32 s13, s20, s13 */
/* @0x2e0bdc vstr s12, [sp, #256] */
/* @0x2e0be0 vsub.f32 s14, s19, s14 */
/* @0x2e0be4 vstr s13, [sp, #260] */
/* @0x2e0be8 vstr s14, [sp, #272] */
/* @0x2e0bec bl 0x2c3fa0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput> */
/* @0x2e0bf0 vldr s15, [sp, #120] */
/* @0x2e0bf4 vcmpe.f32 s15, #0 */
/* @0x2e0bf8 mov r3, #0 */
/* @0x2e0bfc vmrs APSR_nzcv, fpscr */
/* @0x2e0c00 bls 0x2e0ef0 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x5c0> */
/* @0x2e0c04 vadd.f32 s25, s21, s22 */
/* @0x2e0c08 vcmpe.f32 s15, s25 */
/* @0x2e0c0c vmrs APSR_nzcv, fpscr */
/* @0x2e0c10 bmi 0x2e0edc <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x5ac> */
/* @0x2e0c14 vmov.f32 s23, #5.000000e-01 */
/* @0x2e0c18 ldr r12, [sp, #0x3c] */
/* @0x2e0c1c add lr, sp, #164 */
/* @0x2e0c20 vstr s24, [sp, #8] */
/* @0x2e0c24 str lr, [sp, #0x4] */
/* @0x2e0c28 mov r0, r4 */
/* @0x2e0c2c str r12, [sp] */
/* @0x2e0c30 add r1, sp, #92 */
/* @0x2e0c34 ldr r2, [sp, #0x24] */
/* @0x2e0c38 add r3, sp, #128 */
/* @0x2e0c3c bl 0x2dfcf4 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f> */
/* @0x2e0c40 ldr r10, [sp, #0x28] */
/* @0x2e0c44 add r6, sp, #80 */
/* @0x2e0c48 mov r12, #8 */
/* @0x2e0c4c str r6, [sp, #0x14] */
/* @0x2e0c50 str r12, [sp, #0x10] */
/* @0x2e0c54 mov r0, r4 */
/* @0x2e0c58 add r1, sp, #76 */
/* @0x2e0c5c add r2, sp, #80 */
/* @0x2e0c60 mov r3, r10 */
/* @0x2e0c64 bl 0x2e01c8 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f> */
/* @0x2e0c68 vmov s20, r0 */
/* @0x2e0c6c vcmpe.f32 s25, s20 */
/* @0x2e0c70 vmrs APSR_nzcv, fpscr */
/* @0x2e0c74 bmi 0x2e0e00 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x4d0> */
/* @0x2e0c78 vsub.f32 s16, s21, s22 */
/* @0x2e0c7c vcmpe.f32 s20, s16 */
/* @0x2e0c80 vmrs APSR_nzcv, fpscr */
/* @0x2e0c84 bgt 0x2e0e98 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x568> */
/* @0x2e0c88 ldr r5, [sp, #0x4c] */
/* @0x2e0c8c mov r0, r4 */
/* @0x2e0c90 ldr r6, [sp, #0x50] */
/* @0x2e0c94 vmov r3, s24 */
/* @0x2e0c98 mov r1, r5 */
/* @0x2e0c9c mov r2, r6 */
/* @0x2e0ca0 bl 0x2e0694 <_ZNK20b2SeparationFunction8EvaluateEiif> */
/* @0x2e0ca4 vmov s18, r0 */
/* @0x2e0ca8 vcmpe.f32 s16, s18 */
/* @0x2e0cac vmrs APSR_nzcv, fpscr */
/* @0x2e0cb0 bgt 0x2e0eb4 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x584> */
/* @0x2e0cb4 vcmpe.f32 s25, s18 */
/* @0x2e0cb8 vmrs APSR_nzcv, fpscr */
/* @0x2e0cbc bge 0x2e0ea0 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x570> */
/* @0x2e0cc0 ldr r3, [pc, #0x30] */
/* @0x2e0cc4 vmov s19, r10 */
/* @0x2e0cc8 vmov.f32 s17, s24 */
/* @0x2e0ccc mov r9, #0 */
/* @0x2e0cd0 ldr r7, [r11, r3] */
/* @0x2e0cd4 ldr r8, [r7] */
/* @0x2e0cd8 b 0x2e0d30 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x400> */
/* @0x2e0cdc ldrdmi r0, r1, [r9], #251 */
/* @0x2e0ce0 bllo 0xfebd6910 <b2_toiTime+0xfffffffffe47d46c> */
/* @0x2e0ce4 andeq r0, r0, r0 */
/* @0x2e0ce8 blo 0xfebd6918 <b2_toiTime+0xfffffffffe47d474> */
/* @0x2e0cec ldcllo p2, c12, [r5], #-572 */
/* @0x2e0cf0 andseq r1, r1, r4, asr #5 */
/* @0x2e0cf4 .word 0xffffff34 */
/* @0x2e0cf8 .word 0xffffff38 */
/* @0x2e0cfc .word 0xffffff3c */
/* @0x2e0d00 .word 0xffffff40 */
/* @0x2e0d04 .word 0xffffff44 */
/* @0x2e0d08 .word 0xffffff48 */
/* @0x2e0d0c .word 0xffffff4c */
/* @0x2e0d10 vcmpe.f32 s15, s21 */
/* @0x2e0d14 vmrs APSR_nzcv, fpscr */
/* @0x2e0d18 vmovle.f32 s20, s15 */
/* @0x2e0d1c vmovgt.f32 s18, s15 */
/* @0x2e0d20 vmovle.f32 s19, s16 */
/* @0x2e0d24 vmovgt.f32 s17, s16 */
/* @0x2e0d28 cmp r9, #50 */
/* @0x2e0d2c beq 0x2e0d9c <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x46c> */
/* @0x2e0d30 tst r9, #1 */
/* @0x2e0d34 add r9, r9, #1 */
/* @0x2e0d38 add r3, r9, r8 */
/* @0x2e0d3c mov r0, r4 */
/* @0x2e0d40 vsubne.f32 s16, s21, s18 */
/* @0x2e0d44 str r3, [r7] */
/* @0x2e0d48 mov r1, r5 */
/* @0x2e0d4c mov r2, r6 */
/* @0x2e0d50 vsubne.f32 s15, s19, s17 */
/* @0x2e0d54 vmulne.f32 s16, s16, s15 */
/* @0x2e0d58 vsubne.f32 s15, s20, s18 */
/* @0x2e0d5c vdivne.f32 s16, s16, s15 */
/* @0x2e0d60 vaddeq.f32 s16, s17, s19 */
/* @0x2e0d64 vmuleq.f32 s16, s16, s23 */
/* @0x2e0d68 vaddne.f32 s16, s16, s17 */
/* @0x2e0d6c vmov r3, s16 */
/* @0x2e0d70 bl 0x2e0694 <_ZNK20b2SeparationFunction8EvaluateEiif> */
/* @0x2e0d74 vmov s15, r0 */
/* @0x2e0d78 vsub.f32 s14, s15, s21 */
/* @0x2e0d7c vcmpe.f32 s14, #0 */
/* @0x2e0d80 vmov.f32 s13, s14 */
/* @0x2e0d84 vmrs APSR_nzcv, fpscr */
/* @0x2e0d88 vnegle.f32 s13, s14 */
/* @0x2e0d8c vcmpe.f32 s13, s22 */
/* @0x2e0d90 vmrs APSR_nzcv, fpscr */
/* @0x2e0d94 bpl 0x2e0d10 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x3e0> */
/* @0x2e0d98 vmov r10, s16 */
/* @0x2e0d9c ldr r3, [pc, #-0xa8] */
/* @0x2e0da0 ldr r6, [sp, #0x10] */
/* @0x2e0da4 ldr r3, [r11, r3] */
/* @0x2e0da8 ldr r2, [r3] */
/* @0x2e0dac cmp r9, r2 */
/* @0x2e0db0 strge r9, [r3] */
/* @0x2e0db4 strlt r2, [r3] */
/* @0x2e0db8 subs r6, r6, #1 */
/* @0x2e0dbc str r6, [sp, #0x10] */
/* @0x2e0dc0 bne 0x2e0c54 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x324> */
/* @0x2e0dc4 ldr r12, [sp, #0x1c] */
/* @0x2e0dc8 ldr r3, [pc, #-0xd0] */
/* @0x2e0dcc add r12, r12, #1 */
/* @0x2e0dd0 str r12, [sp, #0x1c] */
/* @0x2e0dd4 cmp r12, #20 */
/* @0x2e0dd8 ldr r3, [r11, r3] */
/* @0x2e0ddc ldr r2, [r3] */
/* @0x2e0de0 add r2, r2, #1 */
/* @0x2e0de4 str r2, [r3] */
/* @0x2e0de8 beq 0x2e0ec8 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x598> */
/* @0x2e0dec vldr s12, [sp, #152] */
/* @0x2e0df0 vldr s18, [sp, #156] */
/* @0x2e0df4 vldr s13, [sp, #188] */
/* @0x2e0df8 vldr s17, [sp, #192] */
/* @0x2e0dfc b 0x2e0afc <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x1cc> */
/* @0x2e0e00 ldr r6, [sp, #0x30] */
/* @0x2e0e04 mov r3, #4 */
/* @0x2e0e08 ldr r4, [sp, #0x28] */
/* @0x2e0e0c str r3, [r6] */
/* @0x2e0e10 str r4, [r6, #0x4] */
/* @0x2e0e14 ldr r6, [sp, #0x1c] */
/* @0x2e0e18 ldr r3, [pc, #-0x120] */
/* @0x2e0e1c add r6, r6, #1 */
/* @0x2e0e20 str r6, [sp, #0x1c] */
/* @0x2e0e24 ldr r3, [r11, r3] */
/* @0x2e0e28 ldr r2, [r3] */
/* @0x2e0e2c add r2, r2, #1 */
/* @0x2e0e30 str r2, [r3] */
/* @0x2e0e34 ldr r3, [pc, #-0x138] */
/* @0x2e0e38 add r0, sp, #84 */
/* @0x2e0e3c ldr r4, [sp, #0x1c] */
/* @0x2e0e40 ldr r3, [r11, r3] */
/* @0x2e0e44 ldr r2, [r3] */
/* @0x2e0e48 cmp r4, r2 */
/* @0x2e0e4c strge r4, [r3] */
/* @0x2e0e50 strlt r2, [r3] */
/* @0x2e0e54 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv> */
/* @0x2e0e58 ldr r3, [pc, #-0x158] */
/* @0x2e0e5c ldr r2, [pc, #-0x158] */
/* @0x2e0e60 ldr r3, [r11, r3] */
/* @0x2e0e64 vldr s14, [r3] */
/* @0x2e0e68 vmov s15, r0 */
/* @0x2e0e6c vcmpe.f32 s15, s14 */
/* @0x2e0e70 vmrs APSR_nzcv, fpscr */
/* @0x2e0e74 vmovpl.f32 s14, s15 */
/* @0x2e0e78 vstr s14, [r3] */
/* @0x2e0e7c ldr r3, [r11, r2] */
/* @0x2e0e80 vldr s14, [r3] */
/* @0x2e0e84 vadd.f32 s15, s14, s15 */
/* @0x2e0e88 vstr s15, [r3] */
/* @0x2e0e8c add sp, sp, #396 */
/* @0x2e0e90 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2e0e94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e0e98 vmov s24, r10 */
/* @0x2e0e9c b 0x2e0dc4 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x494> */
/* @0x2e0ea0 ldr r4, [sp, #0x30] */
/* @0x2e0ea4 mov r3, #3 */
/* @0x2e0ea8 vstr s24, [r4, #4] */
/* @0x2e0eac str r3, [r4] */
/* @0x2e0eb0 b 0x2e0e14 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x4e4> */
/* @0x2e0eb4 ldr r12, [sp, #0x30] */
/* @0x2e0eb8 mov r3, #1 */
/* @0x2e0ebc vstr s24, [r12, #4] */
/* @0x2e0ec0 str r3, [r12] */
/* @0x2e0ec4 b 0x2e0e14 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x4e4> */
/* @0x2e0ec8 ldr r12, [sp, #0x30] */
/* @0x2e0ecc mov r3, #1 */
/* @0x2e0ed0 vstr s24, [r12, #4] */
/* @0x2e0ed4 str r3, [r12] */
/* @0x2e0ed8 b 0x2e0e34 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x504> */
/* @0x2e0edc ldr r6, [sp, #0x30] */
/* @0x2e0ee0 mov r3, #3 */
/* @0x2e0ee4 vstr s24, [r6, #4] */
/* @0x2e0ee8 str r3, [r6] */
/* @0x2e0eec b 0x2e0e34 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x504> */
/* @0x2e0ef0 ldr r4, [sp, #0x30] */
/* @0x2e0ef4 str r3, [r4, #0x4] */
/* @0x2e0ef8 mov r3, #2 */
/* @0x2e0efc str r3, [r4] */
/* @0x2e0f00 b 0x2e0e34 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x504> */

/* ── FUNC 0x2e0f04 · b2StackAllocator::b2StackAllocator() · size=60 · insn=15 */
/* @0x2e0f04 push {r4, r5} */
/* @0x2e0f08 movw r4, #0x9004 */
/* @0x2e0f0c movw r12, #0x9008 */
/* @0x2e0f10 movt r4, #0x1 */
/* @0x2e0f14 movt r12, #0x1 */
/* @0x2e0f18 movw r1, #0x918c */
/* @0x2e0f1c movt r1, #0x1 */
/* @0x2e0f20 mov r5, #102400 */
/* @0x2e0f24 mov r2, #0 */
/* @0x2e0f28 str r2, [r0, r5] */
/* @0x2e0f2c str r2, [r0, r4] */
/* @0x2e0f30 str r2, [r0, r12] */
/* @0x2e0f34 pop {r4, r5} */
/* @0x2e0f38 str r2, [r0, r1] */
/* @0x2e0f3c bx lr */

/* ── FUNC 0x2e0f04 · b2StackAllocator::b2StackAllocator() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e0f40 · b2StackAllocator::~b2StackAllocator() · size=4 · insn=1 */
/* @0x2e0f40 bx lr */

/* ── FUNC 0x2e0f40 · b2StackAllocator::~b2StackAllocator() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2e0f44 · b2StackAllocator::Allocate(int) · size=184 · insn=46 */
/* @0x2e0f44 push {r3, r4, r5, r6, r7, lr} */
/* @0x2e0f48 movw r3, #0x918c */
/* @0x2e0f4c movt r3, #0x1 */
/* @0x2e0f50 mov r2, #102400 */
/* @0x2e0f54 mov r4, r0 */
/* @0x2e0f58 mov r6, r1 */
/* @0x2e0f5c ldr r5, [r0, r3] */
/* @0x2e0f60 ldr r0, [r0, r2] */
/* @0x2e0f64 add r5, r5, r5, lsl #1 */
/* @0x2e0f68 add r3, r0, r1 */
/* @0x2e0f6c cmp r3, r2 */
/* @0x2e0f70 add r5, r4, r5, lsl #2 */
/* @0x2e0f74 add r5, r5, r2 */
/* @0x2e0f78 add r5, r5, #8 */
/* @0x2e0f7c add r7, r5, #4 */
/* @0x2e0f80 str r1, [r7, #0x4] */
/* @0x2e0f84 bgt 0x2e0fe0 <_ZN16b2StackAllocator8AllocateEi+0x9c> */
/* @0x2e0f88 add r0, r4, r0 */
/* @0x2e0f8c mov r1, #0 */
/* @0x2e0f90 str r0, [r5, #0x4] */
/* @0x2e0f94 strb r1, [r7, #0x8] */
/* @0x2e0f98 str r3, [r4, r2] */
/* @0x2e0f9c movw r2, #0x9008 */
/* @0x2e0fa0 movt r2, #0x1 */
/* @0x2e0fa4 movw r1, #0x9004 */
/* @0x2e0fa8 movw r3, #0x918c */
/* @0x2e0fac movt r1, #0x1 */
/* @0x2e0fb0 movt r3, #0x1 */
/* @0x2e0fb4 ldr r12, [r4, r2] */
/* @0x2e0fb8 ldr r7, [r4, r1] */
/* @0x2e0fbc ldr r5, [r4, r3] */
/* @0x2e0fc0 add r6, r6, r7 */
/* @0x2e0fc4 str r6, [r4, r1] */
/* @0x2e0fc8 add r1, r5, #1 */
/* @0x2e0fcc cmp r6, r12 */
/* @0x2e0fd0 strge r6, [r4, r2] */
/* @0x2e0fd4 strlt r12, [r4, r2] */
/* @0x2e0fd8 str r1, [r4, r3] */
/* @0x2e0fdc pop {r3, r4, r5, r6, r7, pc} */
/* @0x2e0fe0 mov r0, r1 */
/* @0x2e0fe4 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2e0fe8 mov r3, r0 */
/* @0x2e0fec str r3, [r5, #0x4] */
/* @0x2e0ff0 mov r3, #1 */
/* @0x2e0ff4 strb r3, [r7, #0x8] */
/* @0x2e0ff8 b 0x2e0f9c <_ZN16b2StackAllocator8AllocateEi+0x58> */

/* ── FUNC 0x2e0ffc · b2StackAllocator::Free(void*) · size=132 · insn=33 */
/* @0x2e0ffc push {r4, r5, r6, lr} */
/* @0x2e1000 movw r6, #0x918c */
/* @0x2e1004 movt r6, #0x1 */
/* @0x2e1008 mov r4, r0 */
/* @0x2e100c ldr r3, [r0, r6] */
/* @0x2e1010 add r5, r3, r3, lsl #1 */
/* @0x2e1014 add r5, r0, r5, lsl #2 */
/* @0x2e1018 add r5, r5, #102400 */
/* @0x2e101c add r5, r5, #8 */
/* @0x2e1020 ldrb r2, [r5], #4 */
/* @0x2e1024 cmp r2, #0 */
/* @0x2e1028 bne 0x2e106c <_ZN16b2StackAllocator4FreeEPv+0x70> */
/* @0x2e102c mov r2, #102400 */
/* @0x2e1030 ldr r1, [r5, #-0x8] */
/* @0x2e1034 ldr r12, [r0, r2] */
/* @0x2e1038 mov r0, r3 */
/* @0x2e103c rsb r3, r1, r12 */
/* @0x2e1040 str r3, [r4, r2] */
/* @0x2e1044 movw r3, #0x9004 */
/* @0x2e1048 movt r3, #0x1 */
/* @0x2e104c movw r2, #0x918c */
/* @0x2e1050 movt r2, #0x1 */
/* @0x2e1054 ldr r12, [r4, r3] */
/* @0x2e1058 sub r0, r0, #1 */
/* @0x2e105c rsb r1, r1, r12 */
/* @0x2e1060 str r1, [r4, r3] */
/* @0x2e1064 str r0, [r4, r2] */
/* @0x2e1068 pop {r4, r5, r6, pc} */
/* @0x2e106c mov r0, r1 */
/* @0x2e1070 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2e1074 ldr r0, [r4, r6] */
/* @0x2e1078 ldr r1, [r5, #-0x8] */
/* @0x2e107c b 0x2e1044 <_ZN16b2StackAllocator4FreeEPv+0x48> */

/* ── FUNC 0x2e1080 · b2StackAllocator::GetMaxAllocation() const · size=16 · insn=4 */
/* @0x2e1080 movw r3, #0x9008 */
/* @0x2e1084 movt r3, #0x1 */
/* @0x2e1088 ldr r0, [r0, r3] */
/* @0x2e108c bx lr */

/* ── FUNC 0x2e1090 · b2Timer::Reset() · size=40 · insn=10 */
/* @0x2e1090 push {r4, lr} */
/* @0x2e1094 sub sp, sp, #8 */
/* @0x2e1098 mov r4, r0 */
/* @0x2e109c mov r1, #0 */
/* @0x2e10a0 mov r0, sp */
/* @0x2e10a4 bl 0xb6f70 <gettimeofday@plt> */
/* @0x2e10a8 ldm sp, {r2, r3} */
/* @0x2e10ac stm r4, {r2, r3} */
/* @0x2e10b0 add sp, sp, #8 */
/* @0x2e10b4 pop {r4, pc} */

/* ── FUNC 0x2e10b8 · b2Timer::b2Timer() · size=20 · insn=5 */
/* @0x2e10b8 push {r4, lr} */
/* @0x2e10bc mov r4, r0 */
/* @0x2e10c0 bl 0x2e1090 <_ZN7b2Timer5ResetEv> */
/* @0x2e10c4 mov r0, r4 */
/* @0x2e10c8 pop {r4, pc} */

/* ── FUNC 0x2e10b8 · b2Timer::b2Timer() · alias of the symbol above · insn=0 */
