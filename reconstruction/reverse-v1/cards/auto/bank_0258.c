/* libyoyo.so 覆盖卡组 0258
 * 函数 0x2aec6a..0x2af812，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2aec6a · png_set_pHYs · size=24 · insn=11 */
/* @0x2aec6a cbz r0, 0x2aec80 <png_set_pHYs+0x16> */
/* @0x2aec6c cbz r1, 0x2aec80 <png_set_pHYs+0x16> */
/* @0x2aec6e str r3, [r1, #0x74] */
/* @0x2aec70 ldr r3, [sp] */
/* @0x2aec72 str r2, [r1, #0x70] */
/* @0x2aec74 strb.w r3, [r1, #0x78] */
/* @0x2aec76 stmvs r11, {r3, r4, r5, r6, r12, sp} */
/* @0x2aec78 ldr r3, [r1, #0x8] */
/* @0x2aec7a orr r3, r3, #0x80 */
/* @0x2aec7e str r3, [r1, #0x8] */
/* @0x2aec80 bx lr */

/* ── FUNC 0x2aec82 · anon_2aec82 · size=0 · insn=1 */
/* @0x2aec82 ldrblt r0, [r8, #0x0]! */

/* ── FUNC 0x2aec84 · png_set_PLTE · size=152 · insn=65 */
/* @0x2aec84 push {r3, r4, r5, r6, r7, lr} */
/* @0x2aec86 mov r4, r1 */
/* @0x2aec88 mov r7, r2 */
/* @0x2aec8a mov r6, r3 */
/* @0x2aec8c mov r5, r0 */
/* @0x2aec8e cmp r0, #0x0 */
/* @0x2aec90 beq 0x2aed12 <png_set_PLTE+0x8e> */
/* @0x2aec92 cmp r1, #0x0 */
/* @0x2aec94 beq 0x2aed12 <png_set_PLTE+0x8e> */
/* @0x2aec96 ldrb r3, [r1, #0x19] */
/* @0x2aec98 cmp r3, #0x3 */
/* @0x2aec9a ittet eq */
/* @0x2aec9c ldrbeq r2, [r1, #0x18] */
/* @0x2aec9e moveq r0, #0x1 */
/* @0x2aeca0 movne.w r0, #0x100 */
/* @0x2aeca4 lsleq r0, r2 */
/* @0x2aeca6 cmp r6, #0x0 */
/* @0x2aeca8 blt 0x2aecae <png_set_PLTE+0x2a> */
/* @0x2aecaa cmp r6, r0 */
/* @0x2aecac ble 0x2aecca <png_set_PLTE+0x46> */
/* @0x2aecae cmp r3, #0x3 */
/* @0x2aecb0 mov r0, r5 */
/* @0x2aecb2 bne 0x2aecbe <png_set_PLTE+0x3a> */
/* @0x2aecb4 ldr r1, [pc, #0x5c] */
/* @0x2aecb6 add r1, pc */
/* @0x2aecb8 bl 0x2a642c <png_error> */
/* @0x2aecbc b 0x2aecca <png_set_PLTE+0x46> */
/* @0x2aecbe ldr r1, [pc, #0x58] */
/* @0x2aecc0 pop.w {r3, r4, r5, r6, r7, lr} */
/* @0x2aecc4 add r1, pc */
/* @0x2aecc6 b.w 0x2a6474 <png_warning> */
/* @0x2aecc8 movwhs r11, #0xbd5 */
/* @0x2aecca movs r3, #0x0 */
/* @0x2aeccc mov.w r2, #0x1000 */
/* @0x2aecd0 mov r0, r5 */
/* @0x2aecd2 mov r1, r4 */
/* @0x2aecd4 bl 0x2a5bc0 <png_free_data> */
/* @0x2aecd8 mov.w r1, #0x300 */
/* @0x2aecdc mov r0, r5 */
/* @0x2aecde bl 0x2a6cd8 <png_calloc> */
/* @0x2aece0 andhs pc, r3, #1004 */
/* @0x2aece2 movs r2, #0x3 */
/* @0x2aece4 muls r2, r6, r2 */
/* @0x2aece6 mov r1, r7 */
/* @0x2aece8 uxth r6, r6 */
/* @0x2aecea str.w r0, [r5, #0x1d8] */
/* @0x2aecec .word 0xf60701d8 */
/* @0x2aecee blx 0xb65bc <memcpy@plt> */
/* @0x2aecf0 .word 0xf8d5ec66 */
/* @0x2aecf2 ldr.w r3, [r5, #0x1d8] */
/* @0x2aecf4 ldrdvs r3, r4, [r3, -r8]! */
/* @0x2aecf6 str r3, [r4, #0x10] */
/* @0x2aecf8 strh.w r6, [r5, #0x1dc] */
/* @0x2aecfc ldr.w r3, [r4, #0xb8] */
/* @0x2aed00 strh r6, [r4, #0x14] */
/* @0x2aed02 orr r3, r3, #0x1000 */
/* @0x2aed04 .word 0xf8c45380 */
/* @0x2aed06 str.w r3, [r4, #0xb8] */
/* @0x2aed08 stmvs r3!, {r3, r4, r5, r7, r12, sp} */
/* @0x2aed0a ldr r3, [r4, #0x8] */
/* @0x2aed0c orr r3, r3, #0x8 */
/* @0x2aed10 str r3, [r4, #0x8] */
/* @0x2aed12 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2aed14 cdp p0, #0xf, c0, c3, c13, #0x0 */
/* @0x2aed18 cdp p0, #0xe, c0, c5, c13, #0x0 */

/* ── FUNC 0x2aed1c · png_set_sBIT · size=24 · insn=11 */
/* @0x2aed1c cbz r0, 0x2aed32 <png_set_sBIT+0x16> */
/* @0x2aed1e cbz r1, 0x2aed32 <png_set_sBIT+0x16> */
/* @0x2aed20 ldr r3, [r2] */
/* @0x2aed22 str r3, [r1, #0x44] */
/* @0x2aed24 ldrb r3, [r2, #0x4] */
/* @0x2aed26 strb.w r3, [r1, #0x48] */
/* @0x2aed28 stmvs r11, {r3, r6, r12, sp} */
/* @0x2aed2a ldr r3, [r1, #0x8] */
/* @0x2aed2c orr r3, r3, #0x2 */
/* @0x2aed30 str r3, [r1, #0x8] */
/* @0x2aed32 bx lr */

/* ── FUNC 0x2aed34 · png_set_sRGB · size=18 · insn=9 */
/* @0x2aed34 cbz r0, 0x2aed44 <png_set_sRGB+0x10> */
/* @0x2aed36 cbz r1, 0x2aed44 <png_set_sRGB+0x10> */
/* @0x2aed38 ldr r3, [r1, #0x8] */
/* @0x2aed3a strb.w r2, [r1, #0x2c] */
/* @0x2aed3c vst4.8 {d18, d19, d20, d21}, [r3:128], r12 */
/* @0x2aed3e orr r3, r3, #0x800 */
/* @0x2aed40 addvs r6, r11, r0, lsl #6 */
/* @0x2aed42 str r3, [r1, #0x8] */
/* @0x2aed44 bx lr */

/* ── FUNC 0x2aed48 · png_set_sRGB_gAMA_and_cHRM · size=256 · insn=117 */
/* @0x2aed48 push {r4, r5, lr} */
/* @0x2aed4a mov r4, r1 */
/* @0x2aed4c sub sp, #0x3c */
/* @0x2aed4e mov r5, r0 */
/* @0x2aed50 cmp r0, #0x0 */
/* @0x2aed52 beq 0x2aedfa <png_set_sRGB_gAMA_and_cHRM+0xb2> */
/* @0x2aed54 cmp r1, #0x0 */
/* @0x2aed56 beq 0x2aedfa <png_set_sRGB_gAMA_and_cHRM+0xb2> */
/* @0x2aed58 bl 0x2aed34 <png_set_sRGB> */
/* @0x2aed5c adr r3, #160 <png_set_sRGB_gAMA_and_cHRM+0x40> */
/* @0x2aed5e ldrd r2, r3, [r3] */
/* @0x2aed60 strtmi r2, [r8], -r0, lsl #6 */
/* @0x2aed62 mov r0, r5 */
/* @0x2aed64 mov r1, r4 */
/* @0x2aed66 bl 0x2ae8f8 <png_set_gAMA> */
/* @0x2aed68 strtmi pc, [r8], -r7, asr #27 */
/* @0x2aed6a mov r0, r5 */
/* @0x2aed6c mov r1, r4 */
/* @0x2aed6e movw r2, #0xb18f */
/* @0x2aed70 .word 0xf7ff128f */
/* @0x2aed72 bl 0x2ae988 <png_set_gAMA_fixed> */
/* @0x2aed74 .word 0xf44ffe09 */
/* @0x2aed76 mov.w r0, #0xfa00 */
/* @0x2aed78 vqadd.s8 q10, q4, q13 */
/* @0x2aed7a movw r1, #0x80e8 */
/* @0x2aed7c .word 0xf24701e8 */
/* @0x2aed7e movw r2, #0x7530 */
/* @0x2aed80 .word 0xf64e5230 */
/* @0x2aed82 movw r3, #0xea60 */
/* @0x2aed84 stm sp, {r5, r6, r8, r9, sp} */
/* @0x2aed86 stm.w sp, {r0, r1, r2, r3} */
/* @0x2aed88 .word 0xf643000f */
/* @0x2aed8a movw r3, #0x3a98 */
/* @0x2aed8c qadd8mi r2, r8, r8 */
/* @0x2aed8e mov r0, r5 */
/* @0x2aed90 str r3, [sp, #0x10] */
/* @0x2aed92 mov r1, r4 */
/* @0x2aed94 movw r3, #0x1770 */
/* @0x2aed98 movw r2, #0x7a26 */
/* @0x2aed9c str r3, [sp, #0x14] */
/* @0x2aed9e movw r3, #0x8084 */
/* @0x2aeda0 .word 0xf7ff0384 */
/* @0x2aeda2 bl 0x2ae7e0 <png_set_cHRM_fixed> */
/* @0x2aeda4 tstge r8, #1856 */
/* @0x2aeda6 adr r3, #96 <png_set_sRGB_gAMA_and_cHRM+0x7a> */
/* @0x2aeda8 ldrd r2, r3, [r3] */
/* @0x2aedac mov r0, r5 */
/* @0x2aedae mov r1, r4 */
/* @0x2aedb0 strd r2, r3, [sp] */
/* @0x2aedb4 adr r3, #88 <png_set_sRGB_gAMA_and_cHRM+0x86> */
/* @0x2aedb6 ldrd r2, r3, [r3] */
/* @0x2aedb8 stmib sp, {r8, r9, sp} ^ */
/* @0x2aedba strd r2, r3, [sp, #8] */
/* @0x2aedbc tstge r6, #134217728 */
/* @0x2aedbe adr r3, #88 <png_set_sRGB_gAMA_and_cHRM+0x90> */
/* @0x2aedc0 ldrd r2, r3, [r3] */
/* @0x2aedc4 strd r2, r3, [sp, #16] */
/* @0x2aedc8 adr r3, #84 <png_set_sRGB_gAMA_and_cHRM+0x99> */
/* @0x2aedca ldrd r2, r3, [r3] */
/* @0x2aedcc stmib sp, {r8, r9, sp} ^ */
/* @0x2aedce strd r2, r3, [sp, #24] */
/* @0x2aedd0 tstge r5, #402653184 */
/* @0x2aedd2 adr r3, #84 <png_set_sRGB_gAMA_and_cHRM+0xa3> */
/* @0x2aedd4 ldrd r2, r3, [r3] */
/* @0x2aedd8 strd r2, r3, [sp, #32] */
/* @0x2aeddc adr r3, #80 <png_set_sRGB_gAMA_and_cHRM+0xac> */
/* @0x2aedde ldrd r2, r3, [r3] */
/* @0x2aede0 stmib sp, {r8, r9, sp} ^ */
/* @0x2aede2 strd r2, r3, [sp, #40] */
/* @0x2aede4 tstge r4, #671088640 */
/* @0x2aede6 adr r3, #80 <png_set_sRGB_gAMA_and_cHRM+0xb6> */
/* @0x2aede8 ldrd r2, r3, [r3] */
/* @0x2aedec strd r2, r3, [sp, #48] */
/* @0x2aedf0 adr r3, #76 <png_set_sRGB_gAMA_and_cHRM+0xbf> */
/* @0x2aedf2 ldrd r2, r3, [r3] */
/* @0x2aedf4 .word 0xf7ff2300 */
/* @0x2aedf6 bl 0x2ae6d8 <png_set_cHRM> */
/* @0x2aedf8 andlt pc, pc, pc, ror #24 */
/* @0x2aedfa add sp, #0x3c */
/* @0x2aedfc pop {r4, r5, pc} */
/* @0x2aedfe nop */
/* @0x2aee00 movs r0, r0 */
/* @0x2aee02 b 0x2aee06 <png_set_sRGB_gAMA_and_cHRM+0xbe> */
/* @0x2aee04 asrs r0, r3, #0x1d */
/* @0x2aee06 subs r7, #0xdd */
/* @0x2aee08 movs r0, r0 */
/* @0x2aee0a movs r0, r0 */
/* @0x2aee0c lsrs r6, r2, #0x19 */
/* @0x2aee0e subs r7, #0xd5 */
/* @0x2aee10 movs r0, r0 */
/* @0x2aee12 ands r0, r0 */
/* @0x2aee14 ldrb r1, [r4, #0xb] */
/* @0x2aee16 subs r7, #0xe4 */
/* @0x2aee18 movs r0, r0 */
/* @0x2aee1a str r0, [r0] */
/* @0x2aee1c subs r0, r7, #0x2 */
/* @0x2aee1e subs r7, #0xd5 */
/* @0x2aee20 movs r0, r0 */
/* @0x2aee22 ands r0, r0 */
/* @0x2aee24 adds r3, #0x33 */
/* @0x2aee26 subs r7, #0xd3 */
/* @0x2aee28 movs r0, r0 */
/* @0x2aee2a ands r0, r0 */
/* @0x2aee2c adds r3, #0x33 */
/* @0x2aee2e subs r7, #0xe3 */
/* @0x2aee30 movs r0, r0 */
/* @0x2aee32 ands r0, r0 */
/* @0x2aee34 adds r3, #0x33 */
/* @0x2aee36 subs r7, #0xc3 */
/* @0x2aee38 movs r0, r0 */
/* @0x2aee3a b 0x2aee3e <png_set_sRGB_gAMA_and_cHRM+0xf6> */
/* @0x2aee3c .word 0xb851 */
/* @0x2aee3e subs r7, #0xae */
/* @0x2aee40 movs r0, r0 */
/* @0x2aee42 b 0x2aee46 <png_set_sRGB_gAMA_and_cHRM+0xfe> */
/* @0x2aee44 lsls r6, r0, #0xd */
/* @0x2aee46 subs r7, #0xd4 */

/* ── FUNC 0x2aee48 · png_set_iCCP · size=176 · insn=76 */
/* @0x2aee48 push.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2aee4c mov r4, r1 */
/* @0x2aee4e mov r7, r2 */
/* @0x2aee50 mov r11, r3 */
/* @0x2aee52 ldr.w r9, [sp, #0x28] */
/* @0x2aee54 strmi r9, [r5], -r8, lsr #32 */
/* @0x2aee56 mov r5, r0 */
/* @0x2aee58 ldr r6, [sp, #0x2c] */
/* @0x2aee5a cmp r0, #0x0 */
/* @0x2aee5c beq 0x2aeeec <png_set_iCCP+0xa4> */
/* @0x2aee5e cmp r1, #0x0 */
/* @0x2aee60 beq 0x2aeeec <png_set_iCCP+0xa4> */
/* @0x2aee62 cmp r2, #0x0 */
/* @0x2aee64 beq 0x2aeeec <png_set_iCCP+0xa4> */
/* @0x2aee66 cmp.w r9, #0x0 */
/* @0x2aee68 eorsle r0, pc, r0, lsl #30 */
/* @0x2aee6a beq 0x2aeeec <png_set_iCCP+0xa4> */
/* @0x2aee6c mov r0, r2 */
/* @0x2aee6e blx 0xb6538 <strlen@plt> */
/* @0x2aee70 .word 0xf100eb64 */
/* @0x2aee72 add.w r10, r0, #0x1 */
/* @0x2aee74 strtmi r0, [r8], -r1, lsl #20 */
/* @0x2aee76 mov r0, r5 */
/* @0x2aee78 mov r1, r10 */
/* @0x2aee7a bl 0x2a6d16 <png_malloc_warn> */
/* @0x2aee7c strmi pc, [r0], r12, asr #30 */
/* @0x2aee7e mov r8, r0 */
/* @0x2aee80 cbnz r0, 0x2aee8a <png_set_iCCP+0x42> */
/* @0x2aee82 ldr r1, [pc, #0x6c] */
/* @0x2aee84 mov r0, r5 */
/* @0x2aee86 add r1, pc */
/* @0x2aee88 b 0x2aeeac <png_set_iCCP+0x64> */
/* @0x2aee8a mov r1, r7 */
/* @0x2aee8c mov r2, r10 */
/* @0x2aee8e blx 0xb65bc <memcpy@plt> */
/* @0x2aee90 qadd8mi lr, r8, r6 */
/* @0x2aee92 mov r0, r5 */
/* @0x2aee94 mov r1, r6 */
/* @0x2aee96 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2aee98 .word 0x4607ff3e */
/* @0x2aee9a mov r7, r0 */
/* @0x2aee9c cbnz r0, 0x2aeeb4 <png_set_iCCP+0x6c> */
/* @0x2aee9e mov r0, r5 */
/* @0x2aeea0 mov r1, r8 */
/* @0x2aeea2 bl 0x2a6cfc <png_free> */
/* @0x2aeea4 ldmdbmi r3, {r0, r1, r3, r5, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2aeea6 ldr r1, [pc, #0x4c] */
/* @0x2aeea8 mov r0, r5 */
/* @0x2aeeaa add r1, pc */
/* @0x2aeeac pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2aeeb0 b.w 0x2a6474 <png_warning> */
/* @0x2aeeb4 mov r1, r9 */
/* @0x2aeeb6 mov r2, r6 */
/* @0x2aeeb8 blx 0xb65bc <memcpy@plt> */
/* @0x2aeebc movs r3, #0x0 */
/* @0x2aeebe mov r0, r5 */
/* @0x2aeec0 mov r1, r4 */
/* @0x2aeec2 movs r2, #0x10 */
/* @0x2aeec4 bl 0x2a5bc0 <png_free_data> */
/* @0x2aeec8 ldr.w r3, [r4, #0xb8] */
/* @0x2aeecc str.w r6, [r4, #0xcc] */
/* @0x2aeed0 orr r3, r3, #0x10 */
/* @0x2aeed4 str.w r3, [r4, #0xb8] */
/* @0x2aeed8 ldr r3, [r4, #0x8] */
/* @0x2aeeda str.w r8, [r4, #0xc4] */
/* @0x2aeedc .word 0xf44380c4 */
/* @0x2aeede orr r3, r3, #0x1000 */
/* @0x2aeee0 .word 0xf8c45380 */
/* @0x2aeee2 str.w r7, [r4, #0xc8] */
/* @0x2aeee4 .word 0xf88470c8 */
/* @0x2aeee6 strb.w r11, [r4, #0xd0] */
/* @0x2aeee8 .word 0x60a3b0d0 */
/* @0x2aeeea str r3, [r4, #0x8] */
/* @0x2aeeec pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aeef0 ldc p0, c0, [r10, #-52]! */
/* @0x2aeef4 stcl p0, c0, [r0, #-52] */

/* ── FUNC 0x2aeef8 · png_set_text_2 · size=488 · insn=224 */
/* @0x2aeef8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2aeefc sub sp, #0x1c */
/* @0x2aeefe mov r4, r1 */
/* @0x2aef00 mov r9, r2 */
/* @0x2aef02 str r3, [sp, #0xc] */
/* @0x2aef04 str r0, [sp, #0x10] */
/* @0x2aef06 cbnz r0, 0x2aef0c <png_set_text_2+0x14> */
/* @0x2aef08 movs r0, #0x0 */
/* @0x2aef0a b 0x2af0d4 <png_set_text_2+0x1dc> */
/* @0x2aef0c cmp r1, #0x0 */
/* @0x2aef0e beq 0x2aef08 <png_set_text_2+0x10> */
/* @0x2aef10 ldr r3, [sp, #0xc] */
/* @0x2aef12 cmp r3, #0x0 */
/* @0x2aef14 beq 0x2aef08 <png_set_text_2+0x10> */
/* @0x2aef16 ldr r5, [r1, #0x30] */
/* @0x2aef18 mov r1, r3 */
/* @0x2aef1a ldr r7, [r4, #0x34] */
/* @0x2aef1c add r1, r5 */
/* @0x2aef1e cmp r1, r7 */
/* @0x2aef20 ble 0x2aef52 <png_set_text_2+0x5a> */
/* @0x2aef22 ldr r6, [r4, #0x38] */
/* @0x2aef24 mov.w r8, #0x1c */
/* @0x2aef28 cbz r6, 0x2aef60 <png_set_text_2+0x68> */
/* @0x2aef2a adds r1, #0x8 */
/* @0x2aef2c str r1, [r4, #0x34] */
/* @0x2aef2e mul r1, r8, r1 */
/* @0x2aef30 .word 0xf7f7f101 */
/* @0x2aef32 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2aef34 movvs pc, #240, #28 */
/* @0x2aef36 str r0, [r4, #0x38] */
/* @0x2aef38 cbnz r0, 0x2aef40 <png_set_text_2+0x48> */
/* @0x2aef3a str r7, [r4, #0x34] */
/* @0x2aef3c str r6, [r4, #0x38] */
/* @0x2aef3e b 0x2af0d2 <png_set_text_2+0x1da> */
/* @0x2aef40 mov r1, r6 */
/* @0x2aef42 mul r2, r8, r7 */
/* @0x2aef44 .word 0xf607f207 */
/* @0x2aef46 blx 0xb65bc <memcpy@plt> */
/* @0x2aef48 stmdals r4, {r1, r3, r4, r5, r8, r9, r11, sp, lr, pc} */
/* @0x2aef4a ldr r0, [sp, #0x10] */
/* @0x2aef4c mov r1, r6 */
/* @0x2aef4e bl 0x2a6cfc <png_free> */
/* @0x2aef50 movwhs pc, #0xed5 */
/* @0x2aef52 movs r3, #0x0 */
/* @0x2aef54 str r3, [sp, #0x4] */
/* @0x2aef56 ldr r3, [pc, #0x184] */
/* @0x2aef58 mov r5, r9 */
/* @0x2aef5a add r3, pc */
/* @0x2aef5c str r3, [sp, #0x14] */
/* @0x2aef5e b 0x2aef9c <png_set_text_2+0xa4> */
/* @0x2aef60 ldr r3, [sp, #0xc] */
/* @0x2aef62 str r6, [r4, #0x30] */
/* @0x2aef64 add.w r1, r3, #0x8 */
/* @0x2aef68 str r1, [r4, #0x34] */
/* @0x2aef6a mul r1, r8, r1 */
/* @0x2aef6c .word 0xf7f7f101 */
/* @0x2aef6e bl 0x2a6d16 <png_malloc_warn> */
/* @0x2aef70 movvs pc, #3360 */
/* @0x2aef72 str r0, [r4, #0x38] */
/* @0x2aef74 cbnz r0, 0x2aef7c <png_set_text_2+0x84> */
/* @0x2aef76 str r5, [r4, #0x30] */
/* @0x2aef78 str r7, [r4, #0x34] */
/* @0x2aef7a b 0x2af0d2 <png_set_text_2+0x1da> */
/* @0x2aef7c ldr.w r3, [r4, #0xb8] */
/* @0x2aef80 orr r3, r3, #0x4000 */
/* @0x2aef84 str.w r3, [r4, #0xb8] */
/* @0x2aef88 b 0x2aef52 <png_set_text_2+0x5a> */
/* @0x2aef8a ldr r3, [r4, #0x38] */
/* @0x2aef8c ldr r0, [r5, #0x4] */
/* @0x2aef8e ldr r6, [r4, #0x30] */
/* @0x2aef90 str r3, [sp] */
/* @0x2aef92 cbnz r0, 0x2aefa6 <png_set_text_2+0xae> */
/* @0x2aef94 ldr r3, [sp, #0x4] */
/* @0x2aef96 adds r5, #0x1c */
/* @0x2aef98 adds r3, #0x1 */
/* @0x2aef9a str r3, [sp, #0x4] */
/* @0x2aef9c ldr r2, [sp, #0x4] */
/* @0x2aef9e ldr r3, [sp, #0xc] */
/* @0x2aefa0 cmp r2, r3 */
/* @0x2aefa2 blt 0x2aef8a <png_set_text_2+0x92> */
/* @0x2aefa4 b 0x2aef08 <png_set_text_2+0x10> */
/* @0x2aefa6 ldr r2, [r5] */
/* @0x2aefa8 adds r3, r2, #0x1 */
/* @0x2aefaa cmp r3, #0x3 */
/* @0x2aefac str r2, [sp, #0x8] */
/* @0x2aefae bls 0x2aefba <png_set_text_2+0xc2> */
/* @0x2aefb0 ldr r0, [sp, #0x10] */
/* @0x2aefb2 ldr r1, [sp, #0x14] */
/* @0x2aefb4 bl 0x2a6474 <png_warning> */
/* @0x2aefb8 b 0x2aef94 <png_set_text_2+0x9c> */
/* @0x2aefba blx 0xb6538 <strlen@plt> */
/* @0x2aefbc blls 0x369abc <_ZTS13C_UTF16String+0xb68> */
/* @0x2aefbe ldr r3, [sp, #0x8] */
/* @0x2aefc0 cmp r3, #0x0 */
/* @0x2aefc2 mov r9, r0 */
/* @0x2aefc4 ble 0x2aefda <png_set_text_2+0xe2> */
/* @0x2aefc6 ldr r0, [r5, #0x14] */
/* @0x2aefc8 cbz r0, 0x2aefce <png_set_text_2+0xd6> */
/* @0x2aefca blx 0xb6538 <strlen@plt> */
/* @0x2aefcc selmi lr, r0, r6 */
/* @0x2aefce mov r8, r0 */
/* @0x2aefd0 ldr r0, [r5, #0x18] */
/* @0x2aefd2 cbz r0, 0x2aefe0 <png_set_text_2+0xe8> */
/* @0x2aefd4 blx 0xb6538 <strlen@plt> */
/* @0x2aefd8 b 0x2aefe0 <png_set_text_2+0xe8> */
/* @0x2aefda movs r7, #0x0 */
/* @0x2aefdc mov r8, r7 */
/* @0x2aefde b 0x2aefe2 <png_set_text_2+0xea> */
/* @0x2aefe0 mov r7, r0 */
/* @0x2aefe2 movs r3, #0x1c */
/* @0x2aefe4 ldr r0, [r5, #0x8] */
/* @0x2aefe6 mul r11, r3, r6 */
/* @0x2aefe8 vmlals.f64 d15, d0, d6 */
/* @0x2aefea ldr r6, [sp] */
/* @0x2aefec add r6, r11 */
/* @0x2aefee cbz r0, 0x2aeff4 <png_set_text_2+0xfc> */
/* @0x2aeff0 ldrb r2, [r0] */
/* @0x2aeff2 cbnz r2, 0x2af00c <png_set_text_2+0x114> */
/* @0x2aeff4 ldr r2, [sp, #0x8] */
/* @0x2aeff6 mov.w r10, #0x0 */
/* @0x2aeff8 blls 0x2b1800 <png_write_gAMA+0x40> */
/* @0x2aeffa ldr r3, [sp] */
/* @0x2aeffc cmp r2, #0x0 */
/* @0x2aeffe ite gt */
/* @0x2af000 movgt r2, #0x1 */
/* @0x2af002 movle.w r2, #0xffffffff */
/* @0x2af004 .word 0xf84332ff */
/* @0x2af006 str.w r2, [r3, r11] */
/* @0x2af008 and r2, r6, r11 */
/* @0x2af00a b 0x2af01a <png_set_text_2+0x122> */
/* @0x2af00c blx 0xb6538 <strlen@plt> */
/* @0x2af010 ldr r2, [sp, #0x8] */
/* @0x2af012 ldr r3, [sp] */
/* @0x2af014 str.w r2, [r3, r11] */
/* @0x2af018 mov r10, r0 */
/* @0x2af01a add.w r1, r9, #0x4 */
/* @0x2af01c stmdals r4, {r2, r8} */
/* @0x2af01e ldr r0, [sp, #0x10] */
/* @0x2af020 add r1, r8 */
/* @0x2af022 add r1, r7 */
/* @0x2af024 add r1, r10 */
/* @0x2af026 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2af028 rsbsvs pc, r0, r6, ror lr */
/* @0x2af02a str r0, [r6, #0x4] */
/* @0x2af02c cmp r0, #0x0 */
/* @0x2af02e beq 0x2af0d2 <png_set_text_2+0x1da> */
/* @0x2af030 mov r2, r9 */
/* @0x2af032 ldr r1, [r5, #0x4] */
/* @0x2af034 blx 0xb65bc <memcpy@plt> */
/* @0x2af038 ldr r2, [r6, #0x4] */
/* @0x2af03a mov.w r3, #0x0 */
/* @0x2af03c .word 0xf8020300 */
/* @0x2af03e strb.w r3, [r2, r9] */
/* @0x2af040 .word 0xf1093009 */
/* @0x2af042 add.w r9, r9, #0x1 */
/* @0x2af044 stmdavs r10!, {r0, r8, r11} */
/* @0x2af046 ldr r2, [r5] */
/* @0x2af048 ldr r0, [r6, #0x4] */
/* @0x2af04a cmp r2, #0x0 */
/* @0x2af04c ble 0x2af08a <png_set_text_2+0x192> */
/* @0x2af04e mov r2, r8 */
/* @0x2af050 add r0, r9 */
/* @0x2af052 str r0, [r6, #0x14] */
/* @0x2af054 ldr r1, [r5, #0x14] */
/* @0x2af056 blx 0xb65bc <memcpy@plt> */
/* @0x2af058 ldmdbvs r2!, {r1, r4, r5, r7, r9, r11, sp, lr, pc} ^ */
/* @0x2af05a ldr r2, [r6, #0x14] */
/* @0x2af05c mov.w r3, #0x0 */
/* @0x2af060 strb.w r3, [r2, r8] */
/* @0x2af064 add.w r8, r8, #0x1 */
/* @0x2af068 ldr r2, [r6, #0x14] */
/* @0x2af06a add.w r0, r2, r8 */
/* @0x2af06c ldrtmi r0, [r10], -r8 */
/* @0x2af06e mov r2, r7 */
/* @0x2af070 str r0, [r6, #0x18] */
/* @0x2af072 ldr r1, [r5, #0x18] */
/* @0x2af074 blx 0xb65bc <memcpy@plt> */
/* @0x2af078 ldr r2, [r6, #0x18] */
/* @0x2af07a mov.w r3, #0x0 */
/* @0x2af07c ldrbpl r0, [r3, #0x300] */
/* @0x2af07e strb r3, [r2, r7] */
/* @0x2af080 adds r7, #0x1 */
/* @0x2af082 ldr r2, [r6, #0x18] */
/* @0x2af084 add r2, r7 */
/* @0x2af086 str r2, [r6, #0x8] */
/* @0x2af088 b 0x2af094 <png_set_text_2+0x19c> */
/* @0x2af08a movs r2, #0x0 */
/* @0x2af08c add r0, r9 */
/* @0x2af08e str r2, [r6, #0x14] */
/* @0x2af090 str r2, [r6, #0x18] */
/* @0x2af092 str r0, [r6, #0x8] */
/* @0x2af094 cmp.w r10, #0x0 */
/* @0x2af098 beq 0x2af0a4 <png_set_text_2+0x1ac> */
/* @0x2af09a ldr r0, [r6, #0x8] */
/* @0x2af09c mov r2, r10 */
/* @0x2af09e ldr r1, [r5, #0x8] */
/* @0x2af0a0 blx 0xb65bc <memcpy@plt> */
/* @0x2af0a4 ldr r2, [r6, #0x8] */
/* @0x2af0a6 mov.w r3, #0x0 */
/* @0x2af0a8 .word 0xf8020300 */
/* @0x2af0aa strb.w r3, [r2, r10] */
/* @0x2af0ac blls 0x2bb0dc <jinit_1pass_quantizer+0x3ac> */
/* @0x2af0ae ldr r3, [sp] */
/* @0x2af0b0 ldr.w r2, [r3, r11] */
/* @0x2af0b4 cmp r2, #0x0 */
/* @0x2af0b6 ble 0x2af0c2 <png_set_text_2+0x1ca> */
/* @0x2af0b8 movs r2, #0x0 */
/* @0x2af0ba str.w r10, [r6, #0x10] */
/* @0x2af0bc rscsvs r10, r2, r0, lsl r0 */
/* @0x2af0be str r2, [r6, #0xc] */
/* @0x2af0c0 b 0x2af0ca <png_set_text_2+0x1d2> */
/* @0x2af0c2 movs r3, #0x0 */
/* @0x2af0c4 str.w r10, [r6, #0xc] */
/* @0x2af0c8 str r3, [r6, #0x10] */
/* @0x2af0ca ldr r3, [r4, #0x30] */
/* @0x2af0cc adds r3, #0x1 */
/* @0x2af0ce str r3, [r4, #0x30] */
/* @0x2af0d0 b 0x2aef94 <png_set_text_2+0x9c> */
/* @0x2af0d2 movs r0, #0x1 */
/* @0x2af0d4 add sp, #0x1c */
/* @0x2af0d6 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2af0d8 svclt #0x8ff0 */
/* @0x2af0da nop */
/* @0x2af0dc ldc p0, c0, [r12], #52 */

/* ── FUNC 0x2af0e0 · png_set_text · size=32 · insn=13 */
/* @0x2af0e0 push {r4, lr} */
/* @0x2af0e2 mov r4, r0 */
/* @0x2af0e4 bl 0x2aeef8 <png_set_text_2> */
/* @0x2af0e8 cbz r0, 0x2af0f8 <png_set_text+0x18> */
/* @0x2af0ea ldr r1, [pc, #0x10] */
/* @0x2af0ec mov r0, r4 */
/* @0x2af0ee pop.w {r4, lr} */
/* @0x2af0f0 ldrbtmi r4, [r9], #-16 */
/* @0x2af0f2 add r1, pc */
/* @0x2af0f4 b.w 0x2a642c <png_error> */
/* @0x2af0f8 pop {r4, pc} */
/* @0x2af0fa nop */
/* @0x2af0fc adc.w r0, r10, sp */

/* ── FUNC 0x2af100 · png_set_tIME · size=76 · insn=35 */
/* @0x2af100 cbz r0, 0x2af146 <png_set_tIME+0x46> */
/* @0x2af102 cbz r1, 0x2af146 <png_set_tIME+0x46> */
/* @0x2af104 ldr.w r3, [r0, #0x12c] */
/* @0x2af108 lsls r3, r3, #0x16 */
/* @0x2af10a bmi 0x2af146 <png_set_tIME+0x46> */
/* @0x2af10c ldrb r3, [r2, #0x2] */
/* @0x2af10e subs r3, #0x1 */
/* @0x2af110 cmp r3, #0xb */
/* @0x2af112 bhi 0x2af12e <png_set_tIME+0x2e> */
/* @0x2af114 ldrb r3, [r2, #0x3] */
/* @0x2af116 subs r3, #0x1 */
/* @0x2af118 cmp r3, #0x1e */
/* @0x2af11a bhi 0x2af12e <png_set_tIME+0x2e> */
/* @0x2af11c ldrb r3, [r2, #0x4] */
/* @0x2af11e cmp r3, #0x17 */
/* @0x2af120 bhi 0x2af12e <png_set_tIME+0x2e> */
/* @0x2af122 ldrb r3, [r2, #0x5] */
/* @0x2af124 cmp r3, #0x3b */
/* @0x2af126 bhi 0x2af12e <png_set_tIME+0x2e> */
/* @0x2af128 ldrb r3, [r2, #0x6] */
/* @0x2af12a cmp r3, #0x3c */
/* @0x2af12c bls 0x2af136 <png_set_tIME+0x36> */
/* @0x2af12e ldr r1, [pc, #0x18] */
/* @0x2af130 add r1, pc */
/* @0x2af132 b.w 0x2a6474 <png_warning> */
/* @0x2af134 ldmdavs r3, {r0, r1, r2, r3, r4, r7, r8, r11, r12, sp, pc} */
/* @0x2af136 ldr r3, [r2] */
/* @0x2af138 str r3, [r1, #0x3c] */
/* @0x2af13a ldr r3, [r2, #0x4] */
/* @0x2af13c str r3, [r1, #0x40] */
/* @0x2af13e ldr r3, [r1, #0x8] */
/* @0x2af140 orr r3, r3, #0x200 */
/* @0x2af144 str r3, [r1, #0x8] */
/* @0x2af146 bx lr */
/* @0x2af148 .word 0xeb2e 000d */

/* ── FUNC 0x2af14c · png_set_tRNS · size=192 · insn=87 */
/* @0x2af14c push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2af150 mov r4, r1 */
/* @0x2af152 mov r8, r2 */
/* @0x2af154 mov r5, r3 */
/* @0x2af156 ldr r6, [sp, #0x18] */
/* @0x2af158 mov r7, r0 */
/* @0x2af15a cmp r0, #0x0 */
/* @0x2af15c beq 0x2af1fe <png_set_tRNS+0xb2> */
/* @0x2af15e cmp r1, #0x0 */
/* @0x2af160 beq 0x2af1fe <png_set_tRNS+0xb2> */
/* @0x2af162 cmp.w r3, #0x100 */
/* @0x2af164 stmdble r5, {r7, r8, r9, r10, r11, r12, sp, lr} */
/* @0x2af166 bls 0x2af174 <png_set_tRNS+0x28> */
/* @0x2af168 ldr r1, [pc, #0x98] */
/* @0x2af16a pop.w {r4, r5, r6, r7, r8, lr} */
/* @0x2af16c ldrbtmi r4, [r9], #-496 */
/* @0x2af16e add r1, pc */
/* @0x2af170 b.w 0x2a6474 <png_warning> */
/* @0x2af174 cbz r2, 0x2af1a0 <png_set_tRNS+0x54> */
/* @0x2af176 movs r3, #0x0 */
/* @0x2af178 mov.w r2, #0x2000 */
/* @0x2af17c bl 0x2a5bc0 <png_free_data> */
/* @0x2af180 mov r0, r7 */
/* @0x2af182 mov.w r1, #0x100 */
/* @0x2af184 .word 0xf7f77180 */
/* @0x2af186 bl 0x2a6ca0 <png_malloc> */
/* @0x2af188 cdpne p13, #0x6, c15, c11, c11, #0x4 */
/* @0x2af18a subs r3, r5, #0x1 */
/* @0x2af18c cmp r3, #0xff */
/* @0x2af18e str r0, [r4, #0x4c] */
/* @0x2af190 str.w r0, [r7, #0x24c] */
/* @0x2af194 bhi 0x2af1a0 <png_set_tRNS+0x54> */
/* @0x2af196 ldr r0, [r4, #0x4c] */
/* @0x2af198 mov r1, r8 */
/* @0x2af19a mov r2, r5 */
/* @0x2af19c blx 0xb65bc <memcpy@plt> */
/* @0x2af1a0 cbz r6, 0x2af1e6 <png_set_tRNS+0x9a> */
/* @0x2af1a2 ldrb r3, [r4, #0x18] */
/* @0x2af1a4 movs r2, #0x1 */
/* @0x2af1a6 lsl.w r3, r2, r3 */
/* @0x2af1a8 cdpvc p3, #0x6, c15, c2, c3, #0x0 */
/* @0x2af1aa ldrb r2, [r4, #0x19] */
/* @0x2af1ac cbnz r2, 0x2af1b2 <png_set_tRNS+0x66> */
/* @0x2af1ae ldrh r2, [r6, #0x8] */
/* @0x2af1b0 b 0x2af1c4 <png_set_tRNS+0x78> */
/* @0x2af1b2 cmp r2, #0x2 */
/* @0x2af1b4 bne 0x2af1d2 <png_set_tRNS+0x86> */
/* @0x2af1b6 ldrh r2, [r6, #0x2] */
/* @0x2af1b8 cmp r2, r3 */
/* @0x2af1ba bgt 0x2af1c8 <png_set_tRNS+0x7c> */
/* @0x2af1bc ldrh r2, [r6, #0x4] */
/* @0x2af1be cmp r2, r3 */
/* @0x2af1c0 bgt 0x2af1c8 <png_set_tRNS+0x7c> */
/* @0x2af1c2 ldrh r2, [r6, #0x6] */
/* @0x2af1c4 cmp r2, r3 */
/* @0x2af1c6 ble 0x2af1d2 <png_set_tRNS+0x86> */
/* @0x2af1c8 ldr r1, [pc, #0x3c] */
/* @0x2af1ca mov r0, r7 */
/* @0x2af1cc add r1, pc */
/* @0x2af1ce bl 0x2a6474 <png_warning> */
/* @0x2af1d0 ldmdavs r3!, {r0, r4, r6, r8, r11, r12, sp, lr, pc} */
/* @0x2af1d2 ldr r3, [r6] */
/* @0x2af1d4 cmp r5, #0x0 */
/* @0x2af1d6 it eq */
/* @0x2af1d8 moveq r5, #0x1 */
/* @0x2af1da str r3, [r4, #0x50] */
/* @0x2af1dc ldr r3, [r6, #0x4] */
/* @0x2af1de str r3, [r4, #0x54] */
/* @0x2af1e0 ldrh r3, [r6, #0x8] */
/* @0x2af1e2 strh.w r3, [r4, #0x58] */
/* @0x2af1e4 rschi r3, r5, #88 */
/* @0x2af1e6 strh r5, [r4, #0x16] */
/* @0x2af1e8 cbz r5, 0x2af1fe <png_set_tRNS+0xb2> */
/* @0x2af1ea ldr r3, [r4, #0x8] */
/* @0x2af1ec orr r3, r3, #0x10 */
/* @0x2af1f0 str r3, [r4, #0x8] */
/* @0x2af1f2 ldr.w r3, [r4, #0xb8] */
/* @0x2af1f4 vst4.32 {d19, d20, d21, d22}, [r3:256], r8 */
/* @0x2af1f6 orr r3, r3, #0x2000 */
/* @0x2af1f8 .word 0xf8c45300 */
/* @0x2af1fa str.w r3, [r4, #0xb8] */
/* @0x2af1fc pop {r3, r4, r5, r7, r12, sp} */
/* @0x2af1fe pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2af200 svclt #0x81f0 */
/* @0x2af202 nop */
/* @0x2af204 add.w r0, r12, sp */
/* @0x2af208 pkhbt r0, pc, sp */

/* ── FUNC 0x2af20c · png_set_sPLT · size=308 · insn=133 */
/* @0x2af20c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2af210 mov r4, r1 */
/* @0x2af212 sub sp, #0x14 */
/* @0x2af214 mov r8, r2 */
/* @0x2af216 mov r9, r3 */
/* @0x2af218 mov r5, r0 */
/* @0x2af21a cmp r0, #0x0 */
/* @0x2af21c beq.w 0x2af32c <png_set_sPLT+0x120> */
/* @0x2af220 cmp r1, #0x0 */
/* @0x2af222 beq.w 0x2af32c <png_set_sPLT+0x120> */
/* @0x2af224 .word 0xf8d18083 */
/* @0x2af226 ldr.w r1, [r1, #0xd8] */
/* @0x2af228 ldrmi r1, [r9], #-216 */
/* @0x2af22a add r1, r3 */
/* @0x2af22c lsls r1, r1, #0x4 */
/* @0x2af22e bl 0x2a6d16 <png_malloc_warn> */
/* @0x2af230 .word 0x4606fd72 */
/* @0x2af232 mov r6, r0 */
/* @0x2af234 cbnz r0, 0x2af246 <png_set_sPLT+0x3a> */
/* @0x2af236 ldr r1, [pc, #0xfc] */
/* @0x2af238 mov r0, r5 */
/* @0x2af23a add r1, pc */
/* @0x2af23c add sp, #0x14 */
/* @0x2af23e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2af240 .word 0xf7f74ff0 */
/* @0x2af242 b.w 0x2a6474 <png_warning> */
/* @0x2af244 .word 0xf8d4b917 */
/* @0x2af246 ldr.w r2, [r4, #0xd8] */
/* @0x2af248 .word 0x46c320d8 */
/* @0x2af24a mov r11, r8 */
/* @0x2af24c ldr.w r1, [r4, #0xd4] */
/* @0x2af250 movs r7, #0x0 */
/* @0x2af252 lsls r2, r2, #0x4 */
/* @0x2af254 blx 0xb65bc <memcpy@plt> */
/* @0x2af258 mov r0, r5 */
/* @0x2af25a ldr.w r1, [r4, #0xd4] */
/* @0x2af25c .word 0xf7f710d4 */
/* @0x2af25e bl 0x2a6cfc <png_free> */
/* @0x2af260 blmi 0x102e79c <b2_toiTime+0x8d52f8> */
/* @0x2af262 ldr r3, [pc, #0xd4] */
/* @0x2af264 str.w r7, [r4, #0xd4] */
/* @0x2af268 add r3, pc */
/* @0x2af26a str r3, [sp, #0x8] */
/* @0x2af26c ldr r3, [pc, #0xcc] */
/* @0x2af26e add r3, pc */
/* @0x2af270 str r3, [sp, #0xc] */
/* @0x2af272 cmp r7, r9 */
/* @0x2af274 ldr.w r2, [r4, #0xd8] */
/* @0x2af278 bge 0x2af30e <png_set_sPLT+0x102> */
/* @0x2af27a ldr.w r0, [r11] */
/* @0x2af27c bl 0x46f284 <g_RomDisk+0x77a64> */
/* @0x2af27e add.w r8, r7, r2 */
/* @0x2af280 .word 0xf6070802 */
/* @0x2af282 blx 0xb6538 <strlen@plt> */
/* @0x2af284 b 0x16a97f4 <b2_toiTime+0xf50350> */
/* @0x2af286 lsl.w r8, r8, #0x4 */
/* @0x2af288 bl 0x4352b0 <g_RomDisk+0x3da90> */
/* @0x2af28a add.w r10, r6, r8 */
/* @0x2af28c .word 0x1c420a08 */
/* @0x2af28e adds r2, r0, #0x1 */
/* @0x2af290 mov r0, r5 */
/* @0x2af292 str r2, [sp, #0x4] */
/* @0x2af294 mov r1, r2 */
/* @0x2af296 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2af298 .word 0xf846fd3e */
/* @0x2af29a str.w r0, [r6, r8] */
/* @0x2af29c bls 0x2ef2c4 <FT_Done_Memory+0x5650> */
/* @0x2af29e ldr r2, [sp, #0x4] */
/* @0x2af2a0 cbnz r0, 0x2af2ac <png_set_sPLT+0xa0> */
/* @0x2af2a2 mov r0, r5 */
/* @0x2af2a4 ldr r1, [sp, #0xc] */
/* @0x2af2a6 bl 0x2a6474 <png_warning> */
/* @0x2af2a8 eor pc, r12, r5, ror #17 */
/* @0x2af2aa b 0x2af306 <png_set_sPLT+0xfa> */
/* @0x2af2ac ldr.w r1, [r11] */
/* @0x2af2b0 blx 0xb65bc <memcpy@plt> */
/* @0x2af2b4 ldr.w r1, [r11, #0xc] */
/* @0x2af2b8 movs r3, #0xa */
/* @0x2af2ba mov r0, r5 */
/* @0x2af2bc muls r1, r3, r1 */
/* @0x2af2be bl 0x2a6d16 <png_malloc_warn> */
/* @0x2af2c0 strmi pc, [r2], -r10, lsr #26 */
/* @0x2af2c2 mov r2, r0 */
/* @0x2af2c4 str.w r0, [r10, #0x8] */
/* @0x2af2c8 cbnz r0, 0x2af2e6 <png_set_sPLT+0xda> */
/* @0x2af2ca mov r0, r5 */
/* @0x2af2cc ldr r1, [sp, #0x8] */
/* @0x2af2ce str r2, [sp, #0x4] */
/* @0x2af2d0 bl 0x2a6474 <png_warning> */
/* @0x2af2d4 mov r0, r5 */
/* @0x2af2d6 ldr.w r1, [r6, r8] */
/* @0x2af2d8 .word 0xf7f71008 */
/* @0x2af2da bl 0x2a6cfc <png_free> */
/* @0x2af2dc bls 0x32e720 */
/* @0x2af2de ldr r2, [sp, #0x4] */
/* @0x2af2e0 str.w r2, [r6, r8] */
/* @0x2af2e4 b 0x2af306 <png_set_sPLT+0xfa> */
/* @0x2af2e6 ldr.w r2, [r11, #0xc] */
/* @0x2af2e8 movwhs r2, #0xa00c */
/* @0x2af2ea movs r3, #0xa */
/* @0x2af2ec ldr.w r1, [r11, #0x8] */
/* @0x2af2f0 muls r2, r3, r2 */
/* @0x2af2f2 blx 0xb65bc <memcpy@plt> */
/* @0x2af2f4 .word 0xf8dbe964 */
/* @0x2af2f6 ldr.w r2, [r11, #0xc] */
/* @0x2af2f8 .word 0xf8ca200c */
/* @0x2af2fa str.w r2, [r10, #0xc] */
/* @0x2af2fc .word 0xf89b200c */
/* @0x2af2fe ldrb.w r2, [r11, #0x4] */
/* @0x2af300 .word 0xf88a2004 */
/* @0x2af302 strb.w r2, [r10, #0x4] */
/* @0x2af304 strlo r2, [r1, -r4] */
/* @0x2af306 adds r7, #0x1 */
/* @0x2af308 add.w r11, r11, #0x10 */
/* @0x2af30c b 0x2af272 <png_set_sPLT+0x66> */
/* @0x2af30e ldr r3, [r4, #0x8] */
/* @0x2af310 add r2, r9 */
/* @0x2af312 str.w r6, [r4, #0xd4] */
/* @0x2af314 .word 0xf44360d4 */
/* @0x2af316 orr r3, r3, #0x2000 */
/* @0x2af318 adcvs r5, r3, r0, lsl #6 */
/* @0x2af31a str r3, [r4, #0x8] */
/* @0x2af31c ldr.w r3, [r4, #0xb8] */
/* @0x2af320 str.w r2, [r4, #0xd8] */
/* @0x2af324 orr r3, r3, #0x20 */
/* @0x2af328 str.w r3, [r4, #0xb8] */
/* @0x2af32c add sp, #0x14 */
/* @0x2af32e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2af330 svclt #0x8ff0 */
/* @0x2af332 nop */
/* @0x2af334 eors.w r0, r3, sp */
/* @0x2af338 eor.w r0, r1, sp */
/* @0x2af33c orns r0, r11, sp */

/* ── FUNC 0x2af340 · png_set_unknown_chunks · size=244 · insn=106 */
/* @0x2af340 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2af344 mov r4, r1 */
/* @0x2af346 mov r5, r2 */
/* @0x2af348 mov r7, r3 */
/* @0x2af34a mov r6, r0 */
/* @0x2af34c cmp r0, #0x0 */
/* @0x2af34e beq 0x2af426 <png_set_unknown_chunks+0xe6> */
/* @0x2af350 cmp r1, #0x0 */
/* @0x2af352 beq 0x2af426 <png_set_unknown_chunks+0xe6> */
/* @0x2af354 cmp r3, #0x0 */
/* @0x2af356 beq 0x2af426 <png_set_unknown_chunks+0xe6> */
/* @0x2af358 ldr.w r1, [r1, #0xc0] */
/* @0x2af35c mov.w r9, #0x14 */
/* @0x2af360 add r1, r3 */
/* @0x2af362 mul r1, r9, r1 */
/* @0x2af364 .word 0xf7f7f101 */
/* @0x2af366 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2af368 pkhtbmi pc, r0, r6, asr #25 */
/* @0x2af36a mov r8, r0 */
/* @0x2af36c cbnz r0, 0x2af37e <png_set_unknown_chunks+0x3e> */
/* @0x2af36e ldr r1, [pc, #0xbc] */
/* @0x2af370 mov r0, r6 */
/* @0x2af372 add r1, pc */
/* @0x2af374 add sp, #0xc */
/* @0x2af376 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2af378 .word 0xf7f74ff0 */
/* @0x2af37a b.w 0x2a6474 <png_warning> */
/* @0x2af37c .word 0xf8d4b87b */
/* @0x2af37e ldr.w r2, [r4, #0xc0] */
/* @0x2af380 .word 0xf8d420c0 */
/* @0x2af382 ldr.w r1, [r4, #0xbc] */
/* @0x2af384 .word 0xf8df10bc */
/* @0x2af386 ldr.w r11, [pc, #0xa8] */
/* @0x2af388 blx 0x51b632 <SrcVerts+0x78676> */
/* @0x2af38a mul r2, r9, r2 */
/* @0x2af38c .word 0xf607f202 */
/* @0x2af38e blx 0xb65bc <memcpy@plt> */
/* @0x2af390 shadd16mi lr, r0, r6 */
/* @0x2af392 mov r0, r6 */
/* @0x2af394 ldr.w r1, [r4, #0xbc] */
/* @0x2af398 add r11, pc */
/* @0x2af39a bl 0x2a6cfc <png_free> */
/* @0x2af39c movwhs pc, #0xcaf */
/* @0x2af39e movs r3, #0x0 */
/* @0x2af3a0 mov r10, r3 */
/* @0x2af3a2 str.w r3, [r4, #0xbc] */
/* @0x2af3a4 ldrmi r3, [r10, #0xbc]! */
/* @0x2af3a6 cmp r10, r7 */
/* @0x2af3a8 ldr.w r3, [r4, #0xc0] */
/* @0x2af3ac bge 0x2af410 <png_set_unknown_chunks+0xd0> */
/* @0x2af3ae add r3, r10 */
/* @0x2af3b0 movs r1, #0x14 */
/* @0x2af3b2 mul r2, r1, r3 */
/* @0x2af3b4 stmdavs r9!, {r0, r1, r9, r12, sp, lr, pc} */
/* @0x2af3b6 ldr r1, [r5] */
/* @0x2af3b8 mov.w r3, #0x0 */
/* @0x2af3bc add.w r9, r8, r2 */
/* @0x2af3c0 str.w r1, [r8, r2] */
/* @0x2af3c4 strb.w r3, [r9, #0x4] */
/* @0x2af3c8 ldr r2, [r5, #0xc] */
/* @0x2af3ca str.w r2, [r9, #0xc] */
/* @0x2af3cc .word 0xf8d6200c */
/* @0x2af3ce ldr.w r2, [r6, #0x12c] */
/* @0x2af3d0 .word 0xf889212c */
/* @0x2af3d2 strb.w r2, [r9, #0x10] */
/* @0x2af3d4 stmvs r9!, {r4, sp} ^ */
/* @0x2af3d6 ldr r1, [r5, #0xc] */
/* @0x2af3d8 cbnz r1, 0x2af3e0 <png_set_unknown_chunks+0xa0> */
/* @0x2af3da str.w r1, [r9, #0x8] */
/* @0x2af3dc ands r1, r3, r8 */
/* @0x2af3de b 0x2af408 <png_set_unknown_chunks+0xc8> */
/* @0x2af3e0 mov r0, r6 */
/* @0x2af3e2 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2af3e4 .word 0x4602fc98 */
/* @0x2af3e6 mov r2, r0 */
/* @0x2af3e8 str.w r0, [r9, #0x8] */
/* @0x2af3ec cbnz r0, 0x2af400 <png_set_unknown_chunks+0xc0> */
/* @0x2af3ee mov r0, r6 */
/* @0x2af3f0 mov r1, r11 */
/* @0x2af3f2 str r2, [sp, #0x4] */
/* @0x2af3f4 bl 0x2a6474 <png_warning> */
/* @0x2af3f8 ldr r2, [sp, #0x4] */
/* @0x2af3fa str.w r2, [r9, #0xc] */
/* @0x2af3fc and r2, r3, r12 */
/* @0x2af3fe b 0x2af408 <png_set_unknown_chunks+0xc8> */
/* @0x2af400 ldr r1, [r5, #0x8] */
/* @0x2af402 ldr r2, [r5, #0xc] */
/* @0x2af404 blx 0xb65bc <memcpy@plt> */
/* @0x2af408 add.w r10, r10, #0x1 */
/* @0x2af40c adds r5, #0x14 */
/* @0x2af40e b 0x2af3a6 <png_set_unknown_chunks+0x66> */
/* @0x2af410 add r7, r3 */
/* @0x2af412 ldr.w r3, [r4, #0xb8] */
/* @0x2af414 .word 0xf8c430b8 */
/* @0x2af416 str.w r8, [r4, #0xbc] */
/* @0x2af418 vst4.32 {d24, d25, d26, d27}, [r3:256], r12 */
/* @0x2af41a orr r3, r3, #0x200 */
/* @0x2af41c .word 0xf8c47300 */
/* @0x2af41e str.w r7, [r4, #0xc0] */
/* @0x2af420 .word 0xf8c470c0 */
/* @0x2af422 str.w r3, [r4, #0xb8] */
/* @0x2af424 strhlt r3, [r3], -r8 */
/* @0x2af426 add sp, #0xc */
/* @0x2af428 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2af42c .word 0xe9a1 000d */
/* @0x2af430 ldrd r0, r0, [r11, #-52]! */

/* ── FUNC 0x2af434 · png_set_unknown_chunk_location · size=30 · insn=13 */
/* @0x2af434 cbz r0, 0x2af450 <png_set_unknown_chunk_location+0x1c> */
/* @0x2af436 cbz r1, 0x2af450 <png_set_unknown_chunk_location+0x1c> */
/* @0x2af438 cmp r2, #0x0 */
/* @0x2af43a blt 0x2af450 <png_set_unknown_chunk_location+0x1c> */
/* @0x2af43c ldr.w r0, [r1, #0xc0] */
/* @0x2af440 cmp r2, r0 */
/* @0x2af442 bge 0x2af450 <png_set_unknown_chunk_location+0x1c> */
/* @0x2af444 ldr.w r1, [r1, #0xbc] */
/* @0x2af448 movs r0, #0x14 */
/* @0x2af44a mla r2, r0, r2, r1 */
/* @0x2af44c ldrvc r1, [r3], #-514 */
/* @0x2af44e strb r3, [r2, #0x10] */
/* @0x2af450 bx lr */

/* ── FUNC 0x2af452 · png_permit_mng_features · size=14 · insn=7 */
/* @0x2af452 cbz r0, 0x2af45e <png_permit_mng_features+0xc> */
/* @0x2af454 and r1, r1, #0x5 */
/* @0x2af456 .word 0xf8c00105 */
/* @0x2af458 str.w r1, [r0, #0x2dc] */
/* @0x2af45a .word 0x460812dc */
/* @0x2af45c mov r0, r1 */
/* @0x2af45e bx lr */

/* ── FUNC 0x2af460 · png_set_keep_unknown_chunks · size=192 · insn=75 */
/* @0x2af460 push.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2af464 mov r6, r1 */
/* @0x2af466 mov r11, r2 */
/* @0x2af468 mov r5, r3 */
/* @0x2af46a mov r4, r0 */
/* @0x2af46c cmp r0, #0x0 */
/* @0x2af46e beq 0x2af51c <png_set_keep_unknown_chunks+0xbc> */
/* @0x2af470 cbnz r3, 0x2af4a4 <png_set_keep_unknown_chunks+0x44> */
/* @0x2af472 subs r3, r1, #0x2 */
/* @0x2af474 cmp r3, #0x1 */
/* @0x2af476 ldr.w r3, [r0, #0x130] */
/* @0x2af478 stmdale r7, {r4, r5, r8, r12, sp} */
/* @0x2af47a bhi 0x2af48c <png_set_keep_unknown_chunks+0x2c> */
/* @0x2af47c cmp r1, #0x3 */
/* @0x2af47e it eq */
/* @0x2af480 orreq r3, r3, #0x18000 */
/* @0x2af484 beq 0x2af49c <png_set_keep_unknown_chunks+0x3c> */
/* @0x2af486 orr r3, r3, #0x8000 */
/* @0x2af488 and r4, r1, r0, lsl #6 */
/* @0x2af48a b 0x2af490 <png_set_keep_unknown_chunks+0x30> */
/* @0x2af48c bic r3, r3, #0x8000 */
/* @0x2af490 str.w r3, [r4, #0x130] */
/* @0x2af494 ldr.w r3, [r4, #0x130] */
/* @0x2af498 bic r3, r3, #0x10000 */
/* @0x2af49c str.w r3, [r4, #0x130] */
/* @0x2af4a0 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2af4a4 cbz r2, 0x2af51c <png_set_keep_unknown_chunks+0xbc> */
/* @0x2af4a6 ldr.w r8, [r0, #0x2cc] */
/* @0x2af4a8 .word 0xf04f82cc */
/* @0x2af4aa mov.w r9, #0x5 */
/* @0x2af4ac bl 0x3718c8 <_ZTS13C_UTF16String+0x8974> */
/* @0x2af4ae add.w r10, r3, r8 */
/* @0x2af4b0 blx 0x4f1cda <SrcVerts+0x4ed1e> */
/* @0x2af4b2 mul r1, r9, r10 */
/* @0x2af4b4 .word 0xf7f7f10a */
/* @0x2af4b6 bl 0x2a6ca0 <png_malloc> */
/* @0x2af4b8 .word 0xf8d4fbf3 */
/* @0x2af4ba ldr.w r1, [r4, #0x2d0] */
/* @0x2af4bc .word 0x460712d0 */
/* @0x2af4be mov r7, r0 */
/* @0x2af4c0 cbz r1, 0x2af4da <png_set_keep_unknown_chunks+0x7a> */
/* @0x2af4c2 mul r2, r9, r8 */
/* @0x2af4c4 .word 0xf607f208 */
/* @0x2af4c6 blx 0xb65bc <memcpy@plt> */
/* @0x2af4c8 qsub16mi lr, r0, r10 */
/* @0x2af4ca mov r0, r4 */
/* @0x2af4cc ldr.w r1, [r4, #0x2d0] */
/* @0x2af4d0 bl 0x2a6cfc <png_free> */
/* @0x2af4d4 movs r3, #0x0 */
/* @0x2af4d6 str.w r3, [r4, #0x2d0] */
/* @0x2af4d8 .word 0xf04f32d0 */
/* @0x2af4da mov.w r9, #0x5 */
/* @0x2af4dc ldrbmi r0, [r9], -r5, lsl #18 */
/* @0x2af4de mov r1, r11 */
/* @0x2af4e0 mul r8, r9, r8 */
/* @0x2af4e4 mul r2, r9, r5 */
/* @0x2af4e8 add.w r0, r7, r8 */
/* @0x2af4ec add.w r8, r8, #0x4 */
/* @0x2af4f0 add r8, r7 */
/* @0x2af4f2 blx 0xb65bc <memcpy@plt> */
/* @0x2af4f4 movwhs lr, #0x864 */
/* @0x2af4f6 movs r3, #0x0 */
/* @0x2af4f8 cmp r3, r5 */
/* @0x2af4fa bge 0x2af508 <png_set_keep_unknown_chunks+0xa8> */
/* @0x2af4fc mul r2, r9, r3 */
/* @0x2af500 adds r3, #0x1 */
/* @0x2af502 strb.w r6, [r8, r2] */
/* @0x2af504 ldrb r6, [r7, r2]! */
/* @0x2af506 b 0x2af4f8 <png_set_keep_unknown_chunks+0x98> */
/* @0x2af508 ldr.w r3, [r4, #0x2c0] */
/* @0x2af50c str.w r10, [r4, #0x2cc] */
/* @0x2af510 orr r3, r3, #0x400 */
/* @0x2af514 str.w r7, [r4, #0x2d0] */
/* @0x2af518 str.w r3, [r4, #0x2c0] */
/* @0x2af51c pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2af520 · png_set_read_user_chunk_fn · size=12 · insn=6 */
/* @0x2af520 cbz r0, 0x2af52a <png_set_read_user_chunk_fn+0xa> */
/* @0x2af522 str.w r2, [r0, #0x2c8] */
/* @0x2af524 .word 0xf8c022c8 */
/* @0x2af526 str.w r1, [r0, #0x2c4] */
/* @0x2af528 ldrbmi r1, [r0, -r4, asr #5]! */
/* @0x2af52a bx lr */

/* ── FUNC 0x2af52c · png_set_rows · size=44 · insn=19 */
/* @0x2af52c push {r3, r4, r5, lr} */
/* @0x2af52e mov r4, r1 */
/* @0x2af530 mov r5, r2 */
/* @0x2af532 cbz r0, 0x2af556 <png_set_rows+0x2a> */
/* @0x2af534 cbz r1, 0x2af556 <png_set_rows+0x2a> */
/* @0x2af536 ldr.w r3, [r1, #0xf8] */
/* @0x2af538 strdlt r3, r4, [r11, -r8]! */
/* @0x2af53a cbz r3, 0x2af548 <png_set_rows+0x1c> */
/* @0x2af53c cmp r3, r2 */
/* @0x2af53e beq 0x2af548 <png_set_rows+0x1c> */
/* @0x2af540 movs r2, #0x40 */
/* @0x2af542 movs r3, #0x0 */
/* @0x2af544 bl 0x2a5bc0 <png_free_data> */
/* @0x2af548 str.w r5, [r4, #0xf8] */
/* @0x2af54c cbz r5, 0x2af556 <png_set_rows+0x2a> */
/* @0x2af54e ldr r3, [r4, #0x8] */
/* @0x2af550 orr r3, r3, #0x8000 */
/* @0x2af554 str r3, [r4, #0x8] */
/* @0x2af556 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2af558 · png_set_compression_buffer_size · size=46 · insn=15 */
/* @0x2af558 push {r3, r4, r5, lr} */
/* @0x2af55a mov r5, r1 */
/* @0x2af55c mov r4, r0 */
/* @0x2af55e cbz r0, 0x2af584 <png_set_compression_buffer_size+0x2c> */
/* @0x2af560 ldr.w r1, [r0, #0x170] */
/* @0x2af564 bl 0x2a6cfc <png_free> */
/* @0x2af568 str.w r5, [r4, #0x174] */
/* @0x2af56c mov r0, r4 */
/* @0x2af56e mov r1, r5 */
/* @0x2af570 bl 0x2a6ca0 <png_malloc> */
/* @0x2af574 ldr.w r3, [r4, #0x174] */
/* @0x2af578 str.w r3, [r4, #0x148] */
/* @0x2af57c str.w r0, [r4, #0x170] */
/* @0x2af580 str.w r0, [r4, #0x144] */
/* @0x2af584 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2af586 · png_set_invalid · size=14 · insn=7 */
/* @0x2af586 cbz r0, 0x2af592 <png_set_invalid+0xc> */
/* @0x2af588 cbz r1, 0x2af592 <png_set_invalid+0xc> */
/* @0x2af58a ldr r3, [r1, #0x8] */
/* @0x2af58c bic.w r3, r3, r2 */
/* @0x2af58e addvs r0, r11, r2, lsl #6 */
/* @0x2af590 str r3, [r1, #0x8] */
/* @0x2af592 bx lr */

/* ── FUNC 0x2af594 · png_set_user_limits · size=12 · insn=6 */
/* @0x2af594 cbz r0, 0x2af59e <png_set_user_limits+0xa> */
/* @0x2af596 str.w r1, [r0, #0x308] */
/* @0x2af598 .word 0xf8c01308 */
/* @0x2af59a str.w r2, [r0, #0x30c] */
/* @0x2af59c ldrbmi r2, [r0, -r12, lsl #6]! */
/* @0x2af59e bx lr */

/* ── FUNC 0x2af5a0 · png_set_chunk_cache_max · size=8 · insn=4 */
/* @0x2af5a0 cbz r0, 0x2af5a6 <png_set_chunk_cache_max+0x6> */
/* @0x2af5a2 str.w r1, [r0, #0x310] */
/* @0x2af5a4 .word 0x47701310 */
/* @0x2af5a6 bx lr */

/* ── FUNC 0x2af5a8 · png_set_chunk_malloc_max · size=8 · insn=4 */
/* @0x2af5a8 cbz r0, 0x2af5ae <png_set_chunk_malloc_max+0x6> */
/* @0x2af5aa str.w r1, [r0, #0x1a0] */
/* @0x2af5ac ldrbmi r1, [r0, -r0, lsr #3]! */
/* @0x2af5ae bx lr */

/* ── FUNC 0x2af5b0 · png_check_keyword · size=392 · insn=185 */
/* @0x2af5b0 ldr r3, [pc, #0x160] */
/* @0x2af5b2 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2af5b4 ldrbtmi r4, [r11], #-4080 */
/* @0x2af5b6 add r3, pc */
/* @0x2af5b8 ldr r3, [r3] */
/* @0x2af5ba mov r6, r2 */
/* @0x2af5bc sub sp, #0x3c */
/* @0x2af5be ldr r2, [r3] */
/* @0x2af5c0 movs r7, #0x0 */
/* @0x2af5c2 mov r5, r0 */
/* @0x2af5c4 str r7, [r6] */
/* @0x2af5c6 mov r9, r1 */
/* @0x2af5c8 str r3, [sp, #0x4] */
/* @0x2af5ca str r2, [sp, #0x34] */
/* @0x2af5cc cbz r1, 0x2af5d8 <png_check_keyword+0x28> */
/* @0x2af5ce mov r0, r1 */
/* @0x2af5d0 blx 0xb6538 <strlen@plt> */
/* @0x2af5d4 mov r4, r0 */
/* @0x2af5d6 cbnz r0, 0x2af5e6 <png_check_keyword+0x36> */
/* @0x2af5d8 ldr r1, [pc, #0x13c] */
/* @0x2af5da mov r0, r5 */
/* @0x2af5dc add r1, pc */
/* @0x2af5de bl 0x2a6474 <png_warning> */
/* @0x2af5e0 andhs pc, r0, r9, asr #30 */
/* @0x2af5e2 movs r0, #0x0 */
/* @0x2af5e4 b 0x2af700 <png_check_keyword+0x150> */
/* @0x2af5e6 mov r0, r5 */
/* @0x2af5e8 adds r1, r4, #0x2 */
/* @0x2af5ea bl 0x2a6d16 <png_malloc_warn> */
/* @0x2af5ec pkhbtmi pc, r0, r4, lsl #23 */
/* @0x2af5ee mov r8, r0 */
/* @0x2af5f0 str r0, [r6] */
/* @0x2af5f2 cbz r0, 0x2af604 <png_check_keyword+0x54> */
/* @0x2af5f4 ldr.w r11, [pc, #0x124] */
/* @0x2af5f8 add.w r10, sp, #0xc */
/* @0x2af5fc mov.w r12, #0x20 */
/* @0x2af600 add r11, pc */
/* @0x2af602 b 0x2af630 <png_check_keyword+0x80> */
/* @0x2af604 ldr r1, [pc, #0x118] */
/* @0x2af606 mov r0, r5 */
/* @0x2af608 add r1, pc */
/* @0x2af60a b 0x2af5de <png_check_keyword+0x2e> */
/* @0x2af60c cmp r3, #0x1f */
/* @0x2af60e bhi 0x2af63e <png_check_keyword+0x8e> */
/* @0x2af610 movs r1, #0x28 */
/* @0x2af612 mov r2, r11 */
/* @0x2af614 mov r0, r10 */
/* @0x2af616 str.w r12, [sp] */
/* @0x2af618 .word 0xf606c000 */
/* @0x2af61a blx 0xb65c8 <snprintf@plt> */
/* @0x2af61c .word 0x4628efd6 */
/* @0x2af61e mov r0, r5 */
/* @0x2af620 mov r1, r10 */
/* @0x2af622 bl 0x2a6474 <png_warning> */
/* @0x2af624 .word 0xf8ddff27 */
/* @0x2af626 ldr.w r12, [sp] */
/* @0x2af628 .word 0xf808c000 */
/* @0x2af62a strb.w r12, [r8, r7] */
/* @0x2af62c strlo r12, [r1, -r7] */
/* @0x2af62e adds r7, #0x1 */
/* @0x2af630 ldrb.w r3, [r9, r7] */
/* @0x2af634 add.w r2, r8, r7 */
/* @0x2af638 cmp r3, #0x0 */
/* @0x2af63a bne 0x2af60c <png_check_keyword+0x5c> */
/* @0x2af63c b 0x2af64c <png_check_keyword+0x9c> */
/* @0x2af63e sub.w r2, r3, #0x7f */
/* @0x2af640 bhs 0xaf0044 <b2_toiTime+0x396ba0> */
/* @0x2af642 cmp r2, #0x21 */
/* @0x2af644 bls 0x2af610 <png_check_keyword+0x60> */
/* @0x2af646 strb.w r3, [r8, r7] */
/* @0x2af648 ldrb r3, [r0, r7]! */
/* @0x2af64a b 0x2af62e <png_check_keyword+0x7e> */
/* @0x2af64c strb r3, [r2] */
/* @0x2af64e subs r1, r4, #0x1 */
/* @0x2af650 ldr r0, [r6] */
/* @0x2af652 adds r7, r0, r1 */
/* @0x2af654 ldrb r2, [r0, r1] */
/* @0x2af656 cmp r2, #0x20 */
/* @0x2af658 bne 0x2af676 <png_check_keyword+0xc6> */
/* @0x2af65a ldr r1, [pc, #0xc8] */
/* @0x2af65c mov r0, r5 */
/* @0x2af65e str r3, [sp] */
/* @0x2af660 add r1, pc */
/* @0x2af662 bl 0x2a6474 <png_warning> */
/* @0x2af664 blls 0x2ef288 <FT_Done_Memory+0x5614> */
/* @0x2af666 ldr r3, [sp] */
/* @0x2af668 subs r2, r7, r4 */
/* @0x2af66a ldrb r1, [r2, r4] */
/* @0x2af66c cmp r1, #0x20 */
/* @0x2af66e bne 0x2af676 <png_check_keyword+0xc6> */
/* @0x2af670 strb r3, [r2, r4] */
/* @0x2af672 subs r4, #0x1 */
/* @0x2af674 bne 0x2af66a <png_check_keyword+0xba> */
/* @0x2af676 ldr r7, [r6] */
/* @0x2af678 ldrb r3, [r7] */
/* @0x2af67a cmp r3, #0x20 */
/* @0x2af67c bne 0x2af698 <png_check_keyword+0xe8> */
/* @0x2af67e ldr r1, [pc, #0xa8] */
/* @0x2af680 mov r0, r5 */
/* @0x2af682 add r1, pc */
/* @0x2af684 bl 0x2a6474 <png_warning> */
/* @0x2af688 adds r1, r7, r4 */
/* @0x2af68a mov r3, r7 */
/* @0x2af68c mov r7, r3 */
/* @0x2af68e subs r4, r1, r3 */
/* @0x2af690 ldrb r2, [r7] */
/* @0x2af692 adds r3, #0x1 */
/* @0x2af694 cmp r2, #0x20 */
/* @0x2af696 beq 0x2af68c <png_check_keyword+0xdc> */
/* @0x2af698 ldr r3, [r6] */
/* @0x2af69a subs r7, #0x1 */
/* @0x2af69c movs r1, #0x0 */
/* @0x2af69e movs r0, #0x0 */
/* @0x2af6a0 ldrb r2, [r7, #1]! */
/* @0x2af6a4 cbz r2, 0x2af6c0 <png_check_keyword+0x110> */
/* @0x2af6a6 cmp r2, #0x20 */
/* @0x2af6a8 bne 0x2af6ba <png_check_keyword+0x10a> */
/* @0x2af6aa cbnz r0, 0x2af6b4 <png_check_keyword+0x104> */
/* @0x2af6ac strb r2, [r3] */
/* @0x2af6ae adds r3, #0x1 */
/* @0x2af6b0 movs r0, #0x1 */
/* @0x2af6b2 b 0x2af6a0 <png_check_keyword+0xf0> */
/* @0x2af6b4 subs r4, #0x1 */
/* @0x2af6b6 movs r1, #0x1 */
/* @0x2af6b8 b 0x2af6b0 <png_check_keyword+0x100> */
/* @0x2af6ba strb r2, [r3] */
/* @0x2af6bc adds r3, #0x1 */
/* @0x2af6be b 0x2af69e <png_check_keyword+0xee> */
/* @0x2af6c0 strb r2, [r3] */
/* @0x2af6c2 cbz r1, 0x2af6ce <png_check_keyword+0x11e> */
/* @0x2af6c4 ldr r1, [pc, #0x64] */
/* @0x2af6c6 mov r0, r5 */
/* @0x2af6c8 add r1, pc */
/* @0x2af6ca bl 0x2a6474 <png_warning> */
/* @0x2af6cc stmdblt r12, {r0, r1, r4, r6, r7, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2af6ce cbnz r4, 0x2af6e4 <png_check_keyword+0x134> */
/* @0x2af6d0 mov r0, r5 */
/* @0x2af6d2 ldr r1, [r6] */
/* @0x2af6d4 bl 0x2a6cfc <png_free> */
/* @0x2af6d8 ldr r1, [pc, #0x54] */
/* @0x2af6da mov r0, r5 */
/* @0x2af6dc add r1, pc */
/* @0x2af6de bl 0x2a6474 <png_warning> */
/* @0x2af6e0 and pc, r12, r9, asr #29 */
/* @0x2af6e2 b 0x2af6fe <png_check_keyword+0x14e> */
/* @0x2af6e4 cmp r4, #0x4f */
/* @0x2af6e6 bls 0x2af6fe <png_check_keyword+0x14e> */
/* @0x2af6e8 ldr r1, [pc, #0x48] */
/* @0x2af6ea mov r0, r5 */
/* @0x2af6ec add r1, pc */
/* @0x2af6ee bl 0x2a6474 <png_warning> */
/* @0x2af6f0 ldmdavs r3!, {r0, r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2af6f2 ldr r3, [r6] */
/* @0x2af6f4 movs r2, #0x0 */
/* @0x2af6f6 movs r0, #0x4f */
/* @0x2af6f8 strb.w r2, [r3, #0x4f] */
/* @0x2af6fc b 0x2af700 <png_check_keyword+0x150> */
/* @0x2af6fe mov r0, r4 */
/* @0x2af700 ldr r1, [sp, #0x4] */
/* @0x2af702 ldr r2, [sp, #0x34] */
/* @0x2af704 ldr r3, [r1] */
/* @0x2af706 cmp r2, r3 */
/* @0x2af708 beq 0x2af70e <png_check_keyword+0x15e> */
/* @0x2af70a blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2af70c andlt lr, pc, r4, ror #30 */
/* @0x2af70e add sp, #0x3c */
/* @0x2af710 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2af714 b 0x2afe54 <png_write_info+0x40> */
/* @0x2af716 movs r3, r2 */
/* @0x2af718 b 0x2af5e4 <png_check_keyword+0x34> */
/* @0x2af71a movs r5, r1 */
/* @0x2af71c b 0x2af614 <png_check_keyword+0x64> */
/* @0x2af71e movs r5, r1 */
/* @0x2af720 b 0x2af5bc <png_check_keyword+0xc> */
/* @0x2af722 movs r5, r1 */
/* @0x2af724 b 0x2af59e <png_set_user_limits+0xa> */
/* @0x2af726 movs r5, r1 */
/* @0x2af728 b 0x2af5a8 <png_set_chunk_malloc_max> */
/* @0x2af72a movs r5, r1 */
/* @0x2af72c b 0x2af568 <png_set_compression_buffer_size+0x10> */
/* @0x2af72e movs r5, r1 */
/* @0x2af730 b 0x2af59a <png_set_user_limits+0x6> */
/* @0x2af732 movs r5, r1 */
/* @0x2af734 b 0x2af5a6 <png_set_chunk_cache_max+0x6> */
/* @0x2af736 movs r5, r1 */

/* ── FUNC 0x2af738 · png_set_bgr · size=16 · insn=8 */
/* @0x2af738 cbz r0, 0x2af746 <png_set_bgr+0xe> */
/* @0x2af73a ldr.w r3, [r0, #0x134] */
/* @0x2af73c .word 0xf0433134 */
/* @0x2af73e orr r3, r3, #0x1 */
/* @0x2af740 .word 0xf8c00301 */
/* @0x2af742 str.w r3, [r0, #0x134] */
/* @0x2af744 .word 0x47703134 */
/* @0x2af746 bx lr */

/* ── FUNC 0x2af748 · png_set_swap · size=24 · insn=12 */
/* @0x2af748 cbz r0, 0x2af75e <png_set_swap+0x16> */
/* @0x2af74a ldrb.w r3, [r0, #0x1eb] */
/* @0x2af74c blhs 0x6bbf00 <g_SWFlinevertbuff+0x68e38> */
/* @0x2af74e cmp r3, #0x10 */
/* @0x2af750 bne 0x2af75e <png_set_swap+0x16> */
/* @0x2af752 ldr.w r3, [r0, #0x134] */
/* @0x2af754 .word 0xf0433134 */
/* @0x2af756 orr r3, r3, #0x10 */
/* @0x2af758 .word 0xf8c00310 */
/* @0x2af75a str.w r3, [r0, #0x134] */
/* @0x2af75c .word 0x47703134 */
/* @0x2af75e bx lr */

/* ── FUNC 0x2af760 · png_set_packing · size=30 · insn=14 */
/* @0x2af760 cbz r0, 0x2af77c <png_set_packing+0x1c> */
/* @0x2af762 ldrb.w r3, [r0, #0x1eb] */
/* @0x2af764 blhs 0x47bf18 <targetStr+0xcd8> */
/* @0x2af766 cmp r3, #0x7 */
/* @0x2af768 bhi 0x2af77c <png_set_packing+0x1c> */
/* @0x2af76a ldr.w r3, [r0, #0x134] */
/* @0x2af76c .word 0xf0433134 */
/* @0x2af76e orr r3, r3, #0x4 */
/* @0x2af770 .word 0xf8c00304 */
/* @0x2af772 str.w r3, [r0, #0x134] */
/* @0x2af774 movwhs r3, #0x8134 */
/* @0x2af776 movs r3, #0x8 */
/* @0x2af778 strb.w r3, [r0, #0x1ec] */
/* @0x2af77c bx lr */

/* ── FUNC 0x2af77e · png_set_packswap · size=24 · insn=12 */
/* @0x2af77e cbz r0, 0x2af794 <png_set_packswap+0x16> */
/* @0x2af780 ldrb.w r3, [r0, #0x1eb] */
/* @0x2af782 blhs 0x47bf36 <targetStr+0xcf6> */
/* @0x2af784 cmp r3, #0x7 */
/* @0x2af786 bhi 0x2af794 <png_set_packswap+0x16> */
/* @0x2af788 ldr.w r3, [r0, #0x134] */
/* @0x2af78a vst4.8 {d19, d21, d23, d25}, [r3:256], r4 */
/* @0x2af78c orr r3, r3, #0x10000 */
/* @0x2af78e .word 0xf8c03380 */
/* @0x2af790 str.w r3, [r0, #0x134] */
/* @0x2af792 .word 0x47703134 */
/* @0x2af794 bx lr */

/* ── FUNC 0x2af796 · png_set_shift · size=28 · insn=13 */
/* @0x2af796 cbz r0, 0x2af7b0 <png_set_shift+0x1a> */
/* @0x2af798 ldr.w r3, [r0, #0x134] */
/* @0x2af79a .word 0xf0433134 */
/* @0x2af79c orr r3, r3, #0x8 */
/* @0x2af79e .word 0xf8c00308 */
/* @0x2af7a0 str.w r3, [r0, #0x134] */
/* @0x2af7a2 stmdavs r11, {r2, r4, r5, r8, r12, sp} */
/* @0x2af7a4 ldr r3, [r1] */
/* @0x2af7a6 str.w r3, [r0, #0x245] */
/* @0x2af7aa ldrb r3, [r1, #0x4] */
/* @0x2af7ac strb.w r3, [r0, #0x249] */
/* @0x2af7ae ldrbmi r3, [r0, -r9, asr #4]! */
/* @0x2af7b0 bx lr */

/* ── FUNC 0x2af7b2 · png_set_interlace_handling · size=28 · insn=11 */
/* @0x2af7b2 cbz r0, 0x2af7ca <png_set_interlace_handling+0x18> */
/* @0x2af7b4 ldrb.w r3, [r0, #0x1e7] */
/* @0x2af7b6 teqlt r11, r7, ror #3 */
/* @0x2af7b8 cbz r3, 0x2af7ca <png_set_interlace_handling+0x18> */
/* @0x2af7ba ldr.w r3, [r0, #0x134] */
/* @0x2af7be orr r3, r3, #0x2 */
/* @0x2af7c2 str.w r3, [r0, #0x134] */
/* @0x2af7c6 movs r0, #0x7 */
/* @0x2af7c8 bx lr */
/* @0x2af7ca movs r0, #0x1 */
/* @0x2af7cc bx lr */

/* ── FUNC 0x2af7ce · png_set_filler · size=68 · insn=29 */
/* @0x2af7ce cbz r0, 0x2af810 <png_set_filler+0x42> */
/* @0x2af7d0 ldr.w r3, [r0, #0x134] */
/* @0x2af7d2 bhs 0x2fbcaa <ps_hints_apply+0xa8aa> */
/* @0x2af7d4 cmp r2, #0x1 */
/* @0x2af7d6 strh.w r1, [r0, #0x1f2] */
/* @0x2af7da orr r3, r3, #0x8000 */
/* @0x2af7de str.w r3, [r0, #0x134] */
/* @0x2af7e2 ldr.w r3, [r0, #0x130] */
/* @0x2af7e6 ite eq */
/* @0x2af7e8 orreq r3, r3, #0x80 */
/* @0x2af7ea .word 0xf0230380 */
/* @0x2af7ec bicne r3, r3, #0x80 */
/* @0x2af7ee .word 0xf8c00380 */
/* @0x2af7f0 str.w r3, [r0, #0x130] */
/* @0x2af7f2 .word 0xf8903130 */
/* @0x2af7f4 ldrb.w r3, [r0, #0x1ea] */
/* @0x2af7f6 blhs 0x33bfa6 */
/* @0x2af7f8 cmp r3, #0x2 */
/* @0x2af7fa bne 0x2af800 <png_set_filler+0x32> */
/* @0x2af7fc movs r3, #0x4 */
/* @0x2af7fe b 0x2af80c <png_set_filler+0x3e> */
/* @0x2af800 cbnz r3, 0x2af810 <png_set_filler+0x42> */
/* @0x2af802 ldrb.w r3, [r0, #0x1eb] */
/* @0x2af806 cmp r3, #0x7 */
/* @0x2af808 bls 0x2af810 <png_set_filler+0x42> */
/* @0x2af80a movs r3, #0x2 */
/* @0x2af80c strb.w r3, [r0, #0x1ef] */
/* @0x2af80e ldrbmi r3, [r0, -pc, ror #3]! */
/* @0x2af810 bx lr */

/* ── FUNC 0x2af812 · png_set_add_alpha · size=24 · insn=12 */
/* @0x2af812 push {r4, lr} */
/* @0x2af814 mov r4, r0 */
/* @0x2af816 cbz r0, 0x2af828 <png_set_add_alpha+0x16> */
/* @0x2af818 bl 0x2af7ce <png_set_filler> */
/* @0x2af81a .word 0xf8d4ffd9 */
/* @0x2af81c ldr.w r3, [r4, #0x134] */
/* @0x2af81e .word 0xf0433134 */
/* @0x2af820 orr r3, r3, #0x1000000 */
/* @0x2af822 .word 0xf8c47380 */
/* @0x2af824 str.w r3, [r4, #0x134] */
/* @0x2af826 ldclt p1, c3, [r0, #-208] */
/* @0x2af828 pop {r4, pc} */
