/* libyoyo.so 覆盖卡组 0232
 * 函数 0x27ebf0..0x280a88，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x27ebf0 · json_object_get_double · size=164 · insn=39 */
/* @0x27ebf0 cmp r0, #0 */
/* @0x27ebf4 str lr, [sp, #-0x4]! */
/* @0x27ebf8 sub sp, sp, #12 */
/* @0x27ebfc beq 0x27ec40 <json_object_get_double+0x50> */
/* @0x27ec00 ldr r3, [r0] */
/* @0x27ec04 sub r3, r3, #1 */
/* @0x27ec08 cmp r3, #5 */
/* @0x27ec0c addls pc, pc, r3, lsl #2 */
/* @0x27ec10 b 0x27ec40 <json_object_get_double+0x50> */
/* @0x27ec14 b 0x27ec2c <json_object_get_double+0x3c> */
/* @0x27ec18 b 0x27ec74 <json_object_get_double+0x84> */
/* @0x27ec1c b 0x27ec2c <json_object_get_double+0x3c> */
/* @0x27ec20 b 0x27ec40 <json_object_get_double+0x50> */
/* @0x27ec24 b 0x27ec40 <json_object_get_double+0x50> */
/* @0x27ec28 b 0x27ec50 <json_object_get_double+0x60> */
/* @0x27ec2c vldr s14, [r0, #24] */
/* @0x27ec30 vcvt.f64.s32 d7, s14 */
/* @0x27ec34 vmov r0, r1, d7 */
/* @0x27ec38 add sp, sp, #12 */
/* @0x27ec3c ldr pc, [sp], #4 */
/* @0x27ec40 vldr d7, [pc, #64] */
/* @0x27ec44 vmov r0, r1, d7 */
/* @0x27ec48 add sp, sp, #12 */
/* @0x27ec4c ldr pc, [sp], #4 */
/* @0x27ec50 ldr r1, [pc, #0x38] */
/* @0x27ec54 mov r2, sp */
/* @0x27ec58 ldr r0, [r0, #0x18] */
/* @0x27ec5c add r1, pc, r1 */
/* @0x27ec60 bl 0xb68f8 <sscanf@plt> */
/* @0x27ec64 cmp r0, #1 */
/* @0x27ec68 bne 0x27ec40 <json_object_get_double+0x50> */
/* @0x27ec6c vldr d7, [sp] */
/* @0x27ec70 b 0x27ec34 <json_object_get_double+0x44> */
/* @0x27ec74 vldr d7, [r0, #24] */
/* @0x27ec78 vmov r0, r1, d7 */
/* @0x27ec7c add sp, sp, #12 */
/* @0x27ec80 ldr pc, [sp], #4 */
/* @0x27ec84 nop */
/* @0x27ec90 strheq r1, [r12], -r8 */

/* ── FUNC 0x27ec94 · anon_27ec94 · size=0 · insn=1 */
/* @0x27ec94 nop */

/* ── FUNC 0x27ec98 · json_object_new_null · size=40 · insn=10 */
/* @0x27ec98 push {r3, lr} */
/* @0x27ec9c mov r0, #0 */
/* @0x27eca0 bl 0x27e724 <mc_info+0x35c> */
/* @0x27eca4 cmp r0, #0 */
/* @0x27eca8 popeq {r3, pc} */
/* @0x27ecac ldr r3, [pc, #0x8] */
/* @0x27ecb0 add r3, pc, r3 */
/* @0x27ecb4 str r3, [r0, #0x8] */
/* @0x27ecb8 pop {r3, pc} */
/* @0x27ecbc .word 0xfffff780 */

/* ── FUNC 0x27ecc0 · json_object_new_string · size=72 · insn=18 */
/* @0x27ecc0 push {r3, r4, r5, lr} */
/* @0x27ecc4 mov r5, r0 */
/* @0x27ecc8 mov r0, #6 */
/* @0x27eccc bl 0x27e724 <mc_info+0x35c> */
/* @0x27ecd0 subs r4, r0, #0 */
/* @0x27ecd4 beq 0x27ecf8 <json_object_new_string+0x38> */
/* @0x27ecd8 ldr r2, [pc, #0x20] */
/* @0x27ecdc mov r0, r5 */
/* @0x27ece0 ldr r3, [pc, #0x1c] */
/* @0x27ece4 add r2, pc, r2 */
/* @0x27ece8 add r3, pc, r3 */
/* @0x27ecec stmib r4, {r2, r3} */
/* @0x27ecf0 bl 0xb6640 <strdup@plt> */
/* @0x27ecf4 str r0, [r4, #0x18] */
/* @0x27ecf8 mov r0, r4 */
/* @0x27ecfc pop {r3, r4, r5, pc} */
/* @0x27ed00 .word 0xfffffa14 */
/* @0x27ed04 .word 0xfffff98c */

/* ── FUNC 0x27ed08 · json_object_new_string_len · size=80 · insn=20 */
/* @0x27ed08 push {r4, r5, r6, lr} */
/* @0x27ed0c mov r5, r0 */
/* @0x27ed10 mov r0, #6 */
/* @0x27ed14 mov r6, r1 */
/* @0x27ed18 bl 0x27e724 <mc_info+0x35c> */
/* @0x27ed1c subs r4, r0, #0 */
/* @0x27ed20 beq 0x27ed48 <json_object_new_string_len+0x40> */
/* @0x27ed24 ldr r2, [pc, #0x24] */
/* @0x27ed28 mov r0, r5 */
/* @0x27ed2c ldr r3, [pc, #0x20] */
/* @0x27ed30 mov r1, r6 */
/* @0x27ed34 add r2, pc, r2 */
/* @0x27ed38 add r3, pc, r3 */
/* @0x27ed3c stmib r4, {r2, r3} */
/* @0x27ed40 bl 0xb6d0c <strndup@plt> */
/* @0x27ed44 str r0, [r4, #0x18] */
/* @0x27ed48 mov r0, r4 */
/* @0x27ed4c pop {r4, r5, r6, pc} */
/* @0x27ed50 .word 0xfffff9c4 */
/* @0x27ed54 .word 0xfffff93c */

/* ── FUNC 0x27ed58 · json_object_get_string · size=40 · insn=10 */
/* @0x27ed58 subs r3, r0, #0 */
/* @0x27ed5c beq 0x27ed78 <json_object_get_string+0x20> */
/* @0x27ed60 ldr r2, [r3] */
/* @0x27ed64 cmp r2, #6 */
/* @0x27ed68 bne 0x27ed74 <json_object_get_string+0x1c> */
/* @0x27ed6c ldr r0, [r3, #0x18] */
/* @0x27ed70 bx lr */
/* @0x27ed74 b 0x27e830 <json_object_to_json_string> */
/* @0x27ed78 mov r0, r3 */
/* @0x27ed7c bx lr */

/* ── FUNC 0x27ed80 · json_object_new_array · size=76 · insn=19 */
/* @0x27ed80 push {r4, lr} */
/* @0x27ed84 mov r0, #5 */
/* @0x27ed88 bl 0x27e724 <mc_info+0x35c> */
/* @0x27ed8c subs r4, r0, #0 */
/* @0x27ed90 beq 0x27edb8 <json_object_new_array+0x38> */
/* @0x27ed94 ldr r2, [pc, #0x24] */
/* @0x27ed98 ldr r3, [pc, #0x24] */
/* @0x27ed9c ldr r0, [pc, #0x24] */
/* @0x27eda0 add r2, pc, r2 */
/* @0x27eda4 add r3, pc, r3 */
/* @0x27eda8 stmib r4, {r2, r3} */
/* @0x27edac add r0, pc, r0 */
/* @0x27edb0 bl 0x27e14c <array_list_new> */
/* @0x27edb4 str r0, [r4, #0x18] */
/* @0x27edb8 mov r0, r4 */
/* @0x27edbc pop {r4, pc} */
/* @0x27edc0 .word 0xfffff9b8 */
/* @0x27edc4 andeq r0, r0, r12, asr r0 */
/* @0x27edc8 .word 0xfffffa5c */

/* ── FUNC 0x27edcc · json_object_get_array · size=28 · insn=7 */
/* @0x27edcc cmp r0, #0 */
/* @0x27edd0 bxeq lr */
/* @0x27edd4 ldr r3, [r0] */
/* @0x27edd8 cmp r3, #5 */
/* @0x27eddc ldreq r0, [r0, #0x18] */
/* @0x27ede0 movne r0, #0 */
/* @0x27ede4 bx lr */

/* ── FUNC 0x27ede8 · json_object_array_length · size=8 · insn=2 */
/* @0x27ede8 ldr r0, [r0, #0x18] */
/* @0x27edec b 0x27e2e0 <array_list_length> */

/* ── FUNC 0x27edf0 · json_object_array_add · size=8 · insn=2 */
/* @0x27edf0 ldr r0, [r0, #0x18] */
/* @0x27edf4 b 0x27e2d4 <array_list_add> */

/* ── FUNC 0x27edf8 · json_object_array_put_idx · size=8 · insn=2 */
/* @0x27edf8 ldr r0, [r0, #0x18] */
/* @0x27edfc b 0x27e218 <array_list_put_idx> */

/* ── FUNC 0x27ee00 · json_object_array_get_idx · size=8 · insn=2 */
/* @0x27ee00 ldr r0, [r0, #0x18] */
/* @0x27ee04 b 0x27e200 <array_list_get_idx> */

/* ── FUNC 0x27ee08 · anon_27ee08 · size=240 · insn=61 */
/* @0x27ee08 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x27ee0c mov r5, r1 */
/* @0x27ee10 ldr r1, [pc, #0x98] */
/* @0x27ee14 mov r6, r0 */
/* @0x27ee18 ldr r7, [pc, #0x94] */
/* @0x27ee1c mov r0, r5 */
/* @0x27ee20 ldr r8, [pc, #0x90] */
/* @0x27ee24 add r1, pc, r1 */
/* @0x27ee28 ldr r9, [pc, #0x8c] */
/* @0x27ee2c bl 0x280dbc <sprintbuf> */
/* @0x27ee30 mov r4, #0 */
/* @0x27ee34 add r7, pc, r7 */
/* @0x27ee38 add r8, pc, r8 */
/* @0x27ee3c add r9, pc, r9 */
/* @0x27ee40 b 0x27ee50 <json_object_array_get_idx+0x50> */
/* @0x27ee44 ldr r3, [r3, #0x8] */
/* @0x27ee48 blx r3 */
/* @0x27ee4c add r4, r4, #1 */
/* @0x27ee50 mov r0, r6 */
/* @0x27ee54 bl 0x27ede8 <json_object_array_length> */
/* @0x27ee58 mov r1, r7 */
/* @0x27ee5c cmp r4, r0 */
/* @0x27ee60 mov r0, r5 */
/* @0x27ee64 bge 0x27eea0 <json_object_array_get_idx+0xa0> */
/* @0x27ee68 cmp r4, #0 */
/* @0x27ee6c movne r1, r8 */
/* @0x27ee70 movne r0, r5 */
/* @0x27ee74 bl 0x280dbc <sprintbuf> */
/* @0x27ee78 mov r1, r4 */
/* @0x27ee7c mov r0, r6 */
/* @0x27ee80 bl 0x27ee00 <json_object_array_get_idx> */
/* @0x27ee84 mov r1, r5 */
/* @0x27ee88 subs r3, r0, #0 */
/* @0x27ee8c bne 0x27ee44 <json_object_array_get_idx+0x44> */
/* @0x27ee90 mov r0, r5 */
/* @0x27ee94 mov r1, r9 */
/* @0x27ee98 bl 0x280dbc <sprintbuf> */
/* @0x27ee9c b 0x27ee4c <json_object_array_get_idx+0x4c> */
/* @0x27eea0 ldr r1, [pc, #0x18] */
/* @0x27eea4 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x27eea8 add r1, pc, r1 */
/* @0x27eeac b 0x280dbc <sprintbuf> */
/* @0x27eeb0 muleq sp, r0, r4 */
/* @0x27eeb4 andeq r8, sp, r8, lsl #9 */
/* @0x27eeb8 andeq r8, sp, r0, lsl #9 */
/* @0x27eebc andeq r3, r11, r8, ror #8 */
/* @0x27eec0 andeq r8, sp, r8, lsl r4 */
/* @0x27eec4 add r1, r1, r1, lsl #2 */
/* @0x27eec8 push {r3, r4, r5, lr} */
/* @0x27eecc add r4, r0, r1, lsl #2 */
/* @0x27eed0 mov r3, #1 */
/* @0x27eed4 mov r5, #0 */
/* @0x27eed8 str r3, [r4, #0x28] */
/* @0x27eedc ldr r0, [r4, #0x30] */
/* @0x27eee0 str r5, [r4, #0x24] */
/* @0x27eee4 bl 0x27e7c8 <json_object_put> */
/* @0x27eee8 str r5, [r4, #0x30] */
/* @0x27eeec ldr r0, [r4, #0x34] */
/* @0x27eef0 bl 0xb655c <free@plt> */
/* @0x27eef4 str r5, [r4, #0x34] */
/* @0x27eef8 pop {r3, r4, r5, pc} */

/* ── FUNC 0x27eefc · utf8_get_charW · size=132 · insn=33 */
/* @0x27eefc mov r3, r0 */
/* @0x27ef00 ldrb r0, [r0] */
/* @0x27ef04 tst r0, #128 */
/* @0x27ef08 bxeq lr */
/* @0x27ef0c tst r0, #32 */
/* @0x27ef10 beq 0x27ef4c <utf8_get_charW+0x50> */
/* @0x27ef14 tst r0, #16 */
/* @0x27ef18 ldrb r1, [r3, #0x1] */
/* @0x27ef1c beq 0x27ef60 <utf8_get_charW+0x64> */
/* @0x27ef20 ldrb r2, [r3, #0x2] */
/* @0x27ef24 and r1, r1, #63 */
/* @0x27ef28 and r0, r0, #7 */
/* @0x27ef2c ldrb r3, [r3, #0x3] */
/* @0x27ef30 and r2, r2, #63 */
/* @0x27ef34 lsl r1, r1, #12 */
/* @0x27ef38 add r0, r1, r0, lsl #18 */
/* @0x27ef3c and r3, r3, #63 */
/* @0x27ef40 add r0, r0, r2, lsl #6 */
/* @0x27ef44 add r0, r0, r3 */
/* @0x27ef48 bx lr */
/* @0x27ef4c ldrb r3, [r3, #0x1] */
/* @0x27ef50 and r0, r0, #31 */
/* @0x27ef54 and r3, r3, #63 */
/* @0x27ef58 add r0, r3, r0, lsl #6 */
/* @0x27ef5c bx lr */
/* @0x27ef60 lsl r2, r0, #12 */
/* @0x27ef64 ldrb r3, [r3, #0x2] */
/* @0x27ef68 and r1, r1, #63 */
/* @0x27ef6c uxth r2, r2 */
/* @0x27ef70 and r3, r3, #63 */
/* @0x27ef74 add r0, r2, r1, lsl #6 */
/* @0x27ef78 add r0, r0, r3 */
/* @0x27ef7c bx lr */

/* ── FUNC 0x27ef80 · utf8_char_sizeW · size=48 · insn=12 */
/* @0x27ef80 cmp r0, #127 */
/* @0x27ef84 ble 0x27efa8 <utf8_char_sizeW+0x28> */
/* @0x27ef88 cmp r0, #2048 */
/* @0x27ef8c bge 0x27ef98 <utf8_char_sizeW+0x18> */
/* @0x27ef90 mov r0, #2 */
/* @0x27ef94 bx lr */
/* @0x27ef98 cmp r0, #65536 */
/* @0x27ef9c movlt r0, #3 */
/* @0x27efa0 movge r0, #4 */
/* @0x27efa4 bx lr */
/* @0x27efa8 mov r0, #1 */
/* @0x27efac bx lr */

/* ── FUNC 0x27efb0 · json_tokener_reset · size=64 · insn=16 */
/* @0x27efb0 push {r3, r4, r5, lr} */
/* @0x27efb4 subs r5, r0, #0 */
/* @0x27efb8 popeq {r3, r4, r5, pc} */
/* @0x27efbc ldr r4, [r5, #0x8] */
/* @0x27efc0 cmp r4, #0 */
/* @0x27efc4 blt 0x27efe0 <json_tokener_reset+0x30> */
/* @0x27efc8 mov r1, r4 */
/* @0x27efcc mov r0, r5 */
/* @0x27efd0 sub r4, r4, #1 */
/* @0x27efd4 bl 0x27eec4 <json_object_array_get_idx+0xc4> */
/* @0x27efd8 cmn r4, #1 */
/* @0x27efdc bne 0x27efc8 <json_tokener_reset+0x18> */
/* @0x27efe0 mov r3, #0 */
/* @0x27efe4 str r3, [r5, #0x8] */
/* @0x27efe8 str r3, [r5, #0x18] */
/* @0x27efec pop {r3, r4, r5, pc} */

/* ── FUNC 0x27eff0 · json_tokener_new · size=48 · insn=12 */
/* @0x27eff0 push {r4, lr} */
/* @0x27eff4 mov r0, #1 */
/* @0x27eff8 mov r1, #676 */
/* @0x27effc bl 0xb6c34 <calloc@plt> */
/* @0x27f000 subs r4, r0, #0 */
/* @0x27f004 beq 0x27f018 <json_tokener_new+0x28> */
/* @0x27f008 bl 0x280cc8 <printbuf_new> */
/* @0x27f00c str r0, [r4, #0x4] */
/* @0x27f010 mov r0, r4 */
/* @0x27f014 bl 0x27efb0 <json_tokener_reset> */
/* @0x27f018 mov r0, r4 */
/* @0x27f01c pop {r4, pc} */

/* ── FUNC 0x27f020 · json_tokener_free · size=40 · insn=10 */
/* @0x27f020 push {r4, lr} */
/* @0x27f024 mov r4, r0 */
/* @0x27f028 bl 0x27efb0 <json_tokener_reset> */
/* @0x27f02c cmp r4, #0 */
/* @0x27f030 beq 0x27f03c <json_tokener_free+0x1c> */
/* @0x27f034 ldr r0, [r4, #0x4] */
/* @0x27f038 bl 0x280eb0 <printbuf_free> */
/* @0x27f03c mov r0, r4 */
/* @0x27f040 pop {r4, lr} */
/* @0x27f044 b 0xb655c <free@plt> */

/* ── FUNC 0x27f048 · json_tokener_parse_ex · size=5908 · insn=1477 */
/* @0x27f048 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x27f04c sub sp, sp, #60 */
/* @0x27f050 mov r3, #0 */
/* @0x27f054 mov r4, r0 */
/* @0x27f058 str r3, [r4, #0x14] */
/* @0x27f05c mov r0, r3 */
/* @0x27f060 str r3, [r4, #0x18] */
/* @0x27f064 mov r6, r2 */
/* @0x27f068 str r3, [sp, #0x4] */
/* @0x27f06c mov r3, #1 */
/* @0x27f070 str r3, [sp, #0x24] */
/* @0x27f074 mov r5, r1 */
/* @0x27f078 ldr r3, [pc, #0xfec] */
/* @0x27f07c ldr r2, [pc, #0xfec] */
/* @0x27f080 add r3, pc, r3 */
/* @0x27f084 str r3, [sp, #0x10] */
/* @0x27f088 ldr r3, [pc, #0xfe4] */
/* @0x27f08c add r2, pc, r2 */
/* @0x27f090 str r2, [sp, #0x8] */
/* @0x27f094 add r3, pc, r3 */
/* @0x27f098 str r3, [sp, #0xc] */
/* @0x27f09c ldr r3, [pc, #0xfd4] */
/* @0x27f0a0 add r3, pc, r3 */
/* @0x27f0a4 str r3, [sp, #0x18] */
/* @0x27f0a8 ldr r3, [pc, #0xfcc] */
/* @0x27f0ac add r3, pc, r3 */
/* @0x27f0b0 str r3, [sp, #0x14] */
/* @0x27f0b4 ldr r3, [pc, #0xfc4] */
/* @0x27f0b8 add r3, pc, r3 */
/* @0x27f0bc str r3, [sp, #0x1c] */
/* @0x27f0c0 cmp r6, r0 */
/* @0x27f0c4 bne 0x27f1e0 <json_tokener_parse_ex+0x198> */
/* @0x27f0c8 ldr r3, [r4, #0x8] */
/* @0x27f0cc cmp r3, #0 */
/* @0x27f0d0 bne 0x27f0ec <json_tokener_parse_ex+0xa4> */
/* @0x27f0d4 ldr r3, [r4, #0x24] */
/* @0x27f0d8 cmp r3, #0 */
/* @0x27f0dc bne 0x27f0ec <json_tokener_parse_ex+0xa4> */
/* @0x27f0e0 ldr r2, [r4, #0x28] */
/* @0x27f0e4 cmp r2, #2 */
/* @0x27f0e8 beq 0x27f0f0 <json_tokener_parse_ex+0xa8> */
/* @0x27f0ec mov r3, #1 */
/* @0x27f0f0 str r3, [r4, #0x18] */
/* @0x27f0f4 ldr r8, [sp, #0x24] */
/* @0x27f0f8 cmp r8, #0 */
/* @0x27f0fc beq 0x27f1a8 <json_tokener_parse_ex+0x160> */
/* @0x27f100 ldr r3, [r4, #0x18] */
/* @0x27f104 cmp r3, #0 */
/* @0x27f108 movne r0, #0 */
/* @0x27f10c bne 0x27f124 <json_tokener_parse_ex+0xdc> */
/* @0x27f110 ldr r3, [r4, #0x8] */
/* @0x27f114 add r3, r3, r3, lsl #2 */
/* @0x27f118 add r4, r4, r3, lsl #2 */
/* @0x27f11c ldr r0, [r4, #0x30] */
/* @0x27f120 bl 0x27e7b4 <json_object_get> */
/* @0x27f124 add sp, sp, #60 */
/* @0x27f128 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x27f12c ldr r8, [sp, #0x24] */
/* @0x27f130 cmp r8, #98 */
/* @0x27f134 beq 0x2804a4 <json_tokener_parse_ex+0x145c> */
/* @0x27f138 ble 0x27fe88 <json_tokener_parse_ex+0xe40> */
/* @0x27f13c cmp r8, #114 */
/* @0x27f140 beq 0x2804d8 <json_tokener_parse_ex+0x1490> */
/* @0x27f144 ble 0x280448 <json_tokener_parse_ex+0x1400> */
/* @0x27f148 cmp r8, #116 */
/* @0x27f14c beq 0x2804fc <json_tokener_parse_ex+0x14b4> */
/* @0x27f150 cmp r8, #117 */
/* @0x27f154 bne 0x27faec <json_tokener_parse_ex+0xaa4> */
/* @0x27f158 add r3, r1, r3 */
/* @0x27f15c mov r2, #0 */
/* @0x27f160 mov r0, #10 */
/* @0x27f164 str r2, [r4, #0x1c] */
/* @0x27f168 add r3, r4, r3, lsl #2 */
/* @0x27f16c str r2, [r4, #0x10] */
/* @0x27f170 str r0, [r3, #0x24] */
/* @0x27f174 mov r0, r5 */
/* @0x27f178 bl 0x27eefc <utf8_get_charW> */
/* @0x27f17c bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f180 ldr r7, [r4, #0x14] */
/* @0x27f184 add r5, r5, r0 */
/* @0x27f188 mov r0, r5 */
/* @0x27f18c bl 0x27eefc <utf8_get_charW> */
/* @0x27f190 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f194 ldr r3, [sp, #0x24] */
/* @0x27f198 cmp r3, #0 */
/* @0x27f19c add r0, r7, r0 */
/* @0x27f1a0 str r0, [r4, #0x14] */
/* @0x27f1a4 bne 0x27f0c0 <json_tokener_parse_ex+0x78> */
/* @0x27f1a8 ldr r3, [r4, #0x8] */
/* @0x27f1ac add r3, r3, r3, lsl #2 */
/* @0x27f1b0 add r3, r4, r3, lsl #2 */
/* @0x27f1b4 ldr r2, [r3, #0x24] */
/* @0x27f1b8 cmp r2, #2 */
/* @0x27f1bc beq 0x27f100 <json_tokener_parse_ex+0xb8> */
/* @0x27f1c0 ldr r3, [r3, #0x28] */
/* @0x27f1c4 cmp r3, #2 */
/* @0x27f1c8 beq 0x27f100 <json_tokener_parse_ex+0xb8> */
/* @0x27f1cc mov r3, #3 */
/* @0x27f1d0 mov r0, #0 */
/* @0x27f1d4 str r3, [r4, #0x18] */
/* @0x27f1d8 add sp, sp, #60 */
/* @0x27f1dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x27f1e0 mov r0, r5 */
/* @0x27f1e4 mov r9, #0 */
/* @0x27f1e8 bl 0x27eefc <utf8_get_charW> */
/* @0x27f1ec ldr r3, [r4, #0x8] */
/* @0x27f1f0 lsl r1, r3, #2 */
/* @0x27f1f4 add r2, r1, r3 */
/* @0x27f1f8 add r2, r4, r2, lsl #2 */
/* @0x27f1fc ldr r2, [r2, #0x24] */
/* @0x27f200 str r0, [sp, #0x24] */
/* @0x27f204 cmp r2, #21 */
/* @0x27f208 addls pc, pc, r2, lsl #2 */
/* @0x27f20c b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x27f210 b 0x27f298 <json_tokener_parse_ex+0x250> */
/* @0x27f214 b 0x27f33c <json_tokener_parse_ex+0x2f4> */
/* @0x27f218 b 0x27f5e4 <json_tokener_parse_ex+0x59c> */
/* @0x27f21c b 0x27f4b8 <json_tokener_parse_ex+0x470> */
/* @0x27f220 b 0x27f580 <json_tokener_parse_ex+0x538> */
/* @0x27f224 b 0x27f62c <json_tokener_parse_ex+0x5e4> */
/* @0x27f228 b 0x27f6e4 <json_tokener_parse_ex+0x69c> */
/* @0x27f22c b 0x27f754 <json_tokener_parse_ex+0x70c> */
/* @0x27f230 b 0x27f7b4 <json_tokener_parse_ex+0x76c> */
/* @0x27f234 b 0x27f12c <json_tokener_parse_ex+0xe4> */
/* @0x27f238 b 0x27fa44 <json_tokener_parse_ex+0x9fc> */
/* @0x27f23c b 0x27faf8 <json_tokener_parse_ex+0xab0> */
/* @0x27f240 b 0x27fba4 <json_tokener_parse_ex+0xb5c> */
/* @0x27f244 b 0x27f838 <json_tokener_parse_ex+0x7f0> */
/* @0x27f248 b 0x27f888 <json_tokener_parse_ex+0x840> */
/* @0x27f24c b 0x27f8c0 <json_tokener_parse_ex+0x878> */
/* @0x27f250 b 0x27f8f0 <json_tokener_parse_ex+0x8a8> */
/* @0x27f254 b 0x27f92c <json_tokener_parse_ex+0x8e4> */
/* @0x27f258 b 0x27f9b0 <json_tokener_parse_ex+0x968> */
/* @0x27f25c b 0x27f9d8 <json_tokener_parse_ex+0x990> */
/* @0x27f260 b 0x27f9f0 <json_tokener_parse_ex+0x9a8> */
/* @0x27f264 b 0x27f268 <json_tokener_parse_ex+0x220> */
/* @0x27f268 ldr r8, [sp, #0x24] */
/* @0x27f26c cmp r8, #125 */
/* @0x27f270 beq 0x27fd3c <json_tokener_parse_ex+0xcf4> */
/* @0x27f274 cmp r8, #44 */
/* @0x27f278 bne 0x280664 <json_tokener_parse_ex+0x161c> */
/* @0x27f27c add r3, r1, r3 */
/* @0x27f280 mov r0, #16 */
/* @0x27f284 mov r2, #0 */
/* @0x27f288 add r3, r4, r3, lsl #2 */
/* @0x27f28c str r0, [r3, #0x28] */
/* @0x27f290 str r2, [r3, #0x24] */
/* @0x27f294 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x27f298 ldr r0, [sp, #0x24] */
/* @0x27f29c cmp r0, #127 */
/* @0x27f2a0 bgt 0x27f328 <json_tokener_parse_ex+0x2e0> */
/* @0x27f2a4 cmn r0, #1 */
/* @0x27f2a8 beq 0x27f328 <json_tokener_parse_ex+0x2e0> */
/* @0x27f2ac ldr r8, [pc, #0xdd0] */
/* @0x27f2b0 ldr r8, [pc, r8] */
/* @0x27f2b4 ldr r3, [r8] */
/* @0x27f2b8 uxtab r3, r3, r0 */
/* @0x27f2bc ldrb r3, [r3, #0x1] */
/* @0x27f2c0 tst r3, #8 */
/* @0x27f2c4 beq 0x2806e8 <json_tokener_parse_ex+0x16a0> */
/* @0x27f2c8 mov r0, r5 */
/* @0x27f2cc bl 0x27eefc <utf8_get_charW> */
/* @0x27f2d0 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f2d4 ldr r7, [r4, #0x14] */
/* @0x27f2d8 add r5, r5, r0 */
/* @0x27f2dc mov r0, r5 */
/* @0x27f2e0 bl 0x27eefc <utf8_get_charW> */
/* @0x27f2e4 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f2e8 ldr r3, [sp, #0x24] */
/* @0x27f2ec cmp r3, #0 */
/* @0x27f2f0 add r3, r7, r0 */
/* @0x27f2f4 mov r0, r5 */
/* @0x27f2f8 str r3, [r4, #0x14] */
/* @0x27f2fc beq 0x27f1a8 <json_tokener_parse_ex+0x160> */
/* @0x27f300 cmp r6, r3 */
/* @0x27f304 beq 0x27fe58 <json_tokener_parse_ex+0xe10> */
/* @0x27f308 bl 0x27eefc <utf8_get_charW> */
/* @0x27f30c cmp r0, #127 */
/* @0x27f310 str r0, [sp, #0x24] */
/* @0x27f314 bgt 0x27f320 <json_tokener_parse_ex+0x2d8> */
/* @0x27f318 cmn r0, #1 */
/* @0x27f31c bne 0x27f2b4 <json_tokener_parse_ex+0x26c> */
/* @0x27f320 ldr r3, [r4, #0x8] */
/* @0x27f324 lsl r1, r3, #2 */
/* @0x27f328 add r0, r1, r3 */
/* @0x27f32c add r0, r4, r0, lsl #2 */
/* @0x27f330 ldr r2, [r0, #0x28] */
/* @0x27f334 str r2, [r0, #0x24] */
/* @0x27f338 b 0x27f204 <json_tokener_parse_ex+0x1bc> */
/* @0x27f33c ldr r8, [sp, #0x24] */
/* @0x27f340 sub r2, r8, #34 */
/* @0x27f344 cmp r2, #89 */
/* @0x27f348 addls pc, pc, r2, lsl #2 */
/* @0x27f34c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f350 b 0x280168 <json_tokener_parse_ex+0x1120> */
/* @0x27f354 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f358 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f35c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f360 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f364 b 0x280168 <json_tokener_parse_ex+0x1120> */
/* @0x27f368 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f36c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f370 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f374 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f378 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f37c b 0x280134 <json_tokener_parse_ex+0x10ec> */
/* @0x27f380 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f384 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f388 b 0x280134 <json_tokener_parse_ex+0x10ec> */
/* @0x27f38c b 0x280134 <json_tokener_parse_ex+0x10ec> */
/* @0x27f390 b 0x280134 <json_tokener_parse_ex+0x10ec> */
/* @0x27f394 b 0x280134 <json_tokener_parse_ex+0x10ec> */
/* @0x27f398 b 0x280134 <json_tokener_parse_ex+0x10ec> */
/* @0x27f39c b 0x280134 <json_tokener_parse_ex+0x10ec> */
/* @0x27f3a0 b 0x280134 <json_tokener_parse_ex+0x10ec> */
/* @0x27f3a4 b 0x280134 <json_tokener_parse_ex+0x10ec> */
/* @0x27f3a8 b 0x280134 <json_tokener_parse_ex+0x10ec> */
/* @0x27f3ac b 0x280134 <json_tokener_parse_ex+0x10ec> */
/* @0x27f3b0 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3b4 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3b8 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3bc b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3c0 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3c4 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3c8 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3cc b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3d0 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3d4 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3d8 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3dc b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3e0 b 0x280128 <json_tokener_parse_ex+0x10e0> */
/* @0x27f3e4 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3e8 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3ec b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3f0 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3f4 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3f8 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f3fc b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f400 b 0x2800f4 <json_tokener_parse_ex+0x10ac> */
/* @0x27f404 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f408 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f40c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f410 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f414 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f418 b 0x280128 <json_tokener_parse_ex+0x10e0> */
/* @0x27f41c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f420 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f424 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f428 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f42c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f430 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f434 b 0x2801b0 <json_tokener_parse_ex+0x1168> */
/* @0x27f438 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f43c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f440 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f444 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f448 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f44c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f450 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f454 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f458 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f45c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f460 b 0x280128 <json_tokener_parse_ex+0x10e0> */
/* @0x27f464 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f468 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f46c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f470 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f474 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f478 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f47c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f480 b 0x2800f4 <json_tokener_parse_ex+0x10ac> */
/* @0x27f484 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f488 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f48c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f490 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f494 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f498 b 0x280128 <json_tokener_parse_ex+0x10e0> */
/* @0x27f49c b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f4a0 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f4a4 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f4a8 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f4ac b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f4b0 b 0x280204 <json_tokener_parse_ex+0x11bc> */
/* @0x27f4b4 b 0x28018c <json_tokener_parse_ex+0x1144> */
/* @0x27f4b8 ldr r3, [r4, #0x4] */
/* @0x27f4bc ldr r0, [sp, #0x24] */
/* @0x27f4c0 ldmib r3, {r3, r7} */
/* @0x27f4c4 rsb r7, r3, r7 */
/* @0x27f4c8 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f4cc cmp r7, r0 */
/* @0x27f4d0 ble 0x27fd58 <json_tokener_parse_ex+0xd10> */
/* @0x27f4d4 ldr r3, [r4, #0x4] */
/* @0x27f4d8 add r7, sp, #56 */
/* @0x27f4dc ldr r0, [r7, #-0x14]! */
/* @0x27f4e0 ldm r3, {r3, r8} */
/* @0x27f4e4 add r8, r8, r3 */
/* @0x27f4e8 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f4ec mov r1, r7 */
/* @0x27f4f0 mov r2, r0 */
/* @0x27f4f4 mov r0, r8 */
/* @0x27f4f8 bl 0xb65bc <memcpy@plt> */
/* @0x27f4fc ldr r7, [r4, #0x4] */
/* @0x27f500 ldr r0, [sp, #0x24] */
/* @0x27f504 ldr r8, [r7, #0x4] */
/* @0x27f508 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f50c ldr r3, [r4, #0x4] */
/* @0x27f510 ldr r2, [r3] */
/* @0x27f514 add r0, r8, r0 */
/* @0x27f518 str r0, [r7, #0x4] */
/* @0x27f51c ldr r3, [r3, #0x4] */
/* @0x27f520 strb r9, [r2, r3] */
/* @0x27f524 ldr r8, [r4, #0x10] */
/* @0x27f528 ldr r3, [r4, #0x4] */
/* @0x27f52c add r7, r8, #1 */
/* @0x27f530 ldr r0, [sp, #0xc] */
/* @0x27f534 cmp r7, #3 */
/* @0x27f538 ldr r1, [r3] */
/* @0x27f53c movle r2, r7 */
/* @0x27f540 movgt r2, #4 */
/* @0x27f544 bl 0xb6d18 <strncasecmp@plt> */
/* @0x27f548 cmp r0, #0 */
/* @0x27f54c bne 0x280600 <json_tokener_parse_ex+0x15b8> */
/* @0x27f550 cmp r8, #4 */
/* @0x27f554 bne 0x2805a0 <json_tokener_parse_ex+0x1558> */
/* @0x27f558 ldr r3, [r4, #0x8] */
/* @0x27f55c mov r7, #2 */
/* @0x27f560 mov r2, r0 */
/* @0x27f564 lsl r1, r3, r7 */
/* @0x27f568 add r12, r1, r3 */
/* @0x27f56c add r12, r4, r12, lsl #2 */
/* @0x27f570 str r0, [r12, #0x30] */
/* @0x27f574 str r0, [r12, #0x24] */
/* @0x27f578 str r7, [r12, #0x28] */
/* @0x27f57c b 0x27f204 <json_tokener_parse_ex+0x1bc> */
/* @0x27f580 ldr r8, [sp, #0x24] */
/* @0x27f584 cmp r8, #42 */
/* @0x27f588 beq 0x27ffa4 <json_tokener_parse_ex+0xf5c> */
/* @0x27f58c cmp r8, #47 */
/* @0x27f590 bne 0x280688 <json_tokener_parse_ex+0x1640> */
/* @0x27f594 add r3, r1, r3 */
/* @0x27f598 mov r2, #6 */
/* @0x27f59c add r3, r4, r3, lsl #2 */
/* @0x27f5a0 str r2, [r3, #0x24] */
/* @0x27f5a4 ldr r0, [r4, #0x4] */
/* @0x27f5a8 ldr r3, [r0, #0x4] */
/* @0x27f5ac ldr r2, [r0, #0x8] */
/* @0x27f5b0 rsb r2, r3, r2 */
/* @0x27f5b4 cmp r2, #1 */
/* @0x27f5b8 ble 0x27ffd8 <json_tokener_parse_ex+0xf90> */
/* @0x27f5bc ldr r2, [r0] */
/* @0x27f5c0 mov r0, #0 */
/* @0x27f5c4 ldrb r1, [sp, #0x24] */
/* @0x27f5c8 strb r1, [r2, r3] */
/* @0x27f5cc ldr r3, [r4, #0x4] */
/* @0x27f5d0 ldm r3, {r1, r2} */
/* @0x27f5d4 add r2, r2, #1 */
/* @0x27f5d8 str r2, [r3, #0x4] */
/* @0x27f5dc strb r0, [r1, r2] */
/* @0x27f5e0 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x27f5e4 cmp r3, #0 */
/* @0x27f5e8 beq 0x27f0f4 <json_tokener_parse_ex+0xac> */
/* @0x27f5ec add r3, r1, r3 */
/* @0x27f5f0 add r3, r4, r3, lsl #2 */
/* @0x27f5f4 ldr r0, [r3, #0x30] */
/* @0x27f5f8 bl 0x27e7b4 <json_object_get> */
/* @0x27f5fc ldr r1, [r4, #0x8] */
/* @0x27f600 str r0, [sp, #0x4] */
/* @0x27f604 mov r0, r4 */
/* @0x27f608 bl 0x27eec4 <json_object_array_get_idx+0xc4> */
/* @0x27f60c ldr r3, [r4, #0x8] */
/* @0x27f610 sub r3, r3, #1 */
/* @0x27f614 str r3, [r4, #0x8] */
/* @0x27f618 lsl r1, r3, #2 */
/* @0x27f61c add r2, r1, r3 */
/* @0x27f620 add r2, r4, r2, lsl #2 */
/* @0x27f624 ldr r2, [r2, #0x24] */
/* @0x27f628 b 0x27f204 <json_tokener_parse_ex+0x1bc> */
/* @0x27f62c ldr r3, [sp, #0x24] */
/* @0x27f630 mov r7, r5 */
/* @0x27f634 cmp r3, #42 */
/* @0x27f638 bne 0x27f658 <json_tokener_parse_ex+0x610> */
/* @0x27f63c b 0x27ff5c <json_tokener_parse_ex+0xf14> */
/* @0x27f640 cmp r6, r3 */
/* @0x27f644 beq 0x27fd0c <json_tokener_parse_ex+0xcc4> */
/* @0x27f648 bl 0x27eefc <utf8_get_charW> */
/* @0x27f64c cmp r0, #42 */
/* @0x27f650 str r0, [sp, #0x24] */
/* @0x27f654 beq 0x27ff5c <json_tokener_parse_ex+0xf14> */
/* @0x27f658 mov r0, r7 */
/* @0x27f65c bl 0x27eefc <utf8_get_charW> */
/* @0x27f660 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f664 ldr r8, [r4, #0x14] */
/* @0x27f668 add r7, r7, r0 */
/* @0x27f66c mov r0, r7 */
/* @0x27f670 bl 0x27eefc <utf8_get_charW> */
/* @0x27f674 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f678 ldr r3, [sp, #0x24] */
/* @0x27f67c cmp r3, #0 */
/* @0x27f680 add r3, r8, r0 */
/* @0x27f684 mov r0, r7 */
/* @0x27f688 str r3, [r4, #0x14] */
/* @0x27f68c bne 0x27f640 <json_tokener_parse_ex+0x5f8> */
/* @0x27f690 ldr r0, [r4, #0x4] */
/* @0x27f694 rsb r7, r5, r7 */
/* @0x27f698 ldr r3, [r0, #0x4] */
/* @0x27f69c ldr r2, [r0, #0x8] */
/* @0x27f6a0 rsb r2, r3, r2 */
/* @0x27f6a4 cmp r2, r7 */
/* @0x27f6a8 ble 0x27fcf8 <json_tokener_parse_ex+0xcb0> */
/* @0x27f6ac ldr r0, [r0] */
/* @0x27f6b0 mov r2, r7 */
/* @0x27f6b4 mov r1, r5 */
/* @0x27f6b8 add r0, r0, r3 */
/* @0x27f6bc bl 0xb65bc <memcpy@plt> */
/* @0x27f6c0 ldr r3, [r4, #0x4] */
/* @0x27f6c4 mov r1, #0 */
/* @0x27f6c8 ldr r0, [r3, #0x4] */
/* @0x27f6cc ldr r2, [r3] */
/* @0x27f6d0 add r7, r7, r0 */
/* @0x27f6d4 str r7, [r3, #0x4] */
/* @0x27f6d8 strb r1, [r2, r7] */
/* @0x27f6dc ldr r8, [sp, #0x24] */
/* @0x27f6e0 b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x27f6e4 ldr r3, [sp, #0x24] */
/* @0x27f6e8 mov r9, r5 */
/* @0x27f6ec cmp r3, #10 */
/* @0x27f6f0 moveq r8, #0 */
/* @0x27f6f4 beq 0x27fefc <json_tokener_parse_ex+0xeb4> */
/* @0x27f6f8 mov r7, r5 */
/* @0x27f6fc b 0x27f718 <json_tokener_parse_ex+0x6d0> */
/* @0x27f700 cmp r6, r3 */
/* @0x27f704 beq 0x27fd0c <json_tokener_parse_ex+0xcc4> */
/* @0x27f708 bl 0x27eefc <utf8_get_charW> */
/* @0x27f70c cmp r0, #10 */
/* @0x27f710 str r0, [sp, #0x24] */
/* @0x27f714 beq 0x27fef4 <json_tokener_parse_ex+0xeac> */
/* @0x27f718 mov r0, r7 */
/* @0x27f71c bl 0x27eefc <utf8_get_charW> */
/* @0x27f720 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f724 ldr r8, [r4, #0x14] */
/* @0x27f728 add r7, r7, r0 */
/* @0x27f72c mov r0, r7 */
/* @0x27f730 bl 0x27eefc <utf8_get_charW> */
/* @0x27f734 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f738 ldr r3, [sp, #0x24] */
/* @0x27f73c cmp r3, #0 */
/* @0x27f740 add r3, r8, r0 */
/* @0x27f744 mov r0, r7 */
/* @0x27f748 str r3, [r4, #0x14] */
/* @0x27f74c bne 0x27f700 <json_tokener_parse_ex+0x6b8> */
/* @0x27f750 b 0x27f690 <json_tokener_parse_ex+0x648> */
/* @0x27f754 ldr r0, [r4, #0x4] */
/* @0x27f758 ldr r3, [r0, #0x4] */
/* @0x27f75c ldr r2, [r0, #0x8] */
/* @0x27f760 rsb r2, r3, r2 */
/* @0x27f764 cmp r2, #1 */
/* @0x27f768 ble 0x27ffc8 <json_tokener_parse_ex+0xf80> */
/* @0x27f76c ldr r2, [r0] */
/* @0x27f770 mov r0, #0 */
/* @0x27f774 ldrb r1, [sp, #0x24] */
/* @0x27f778 strb r1, [r2, r3] */
/* @0x27f77c ldr r3, [r4, #0x4] */
/* @0x27f780 ldm r3, {r1, r2} */
/* @0x27f784 add r2, r2, #1 */
/* @0x27f788 str r2, [r3, #0x4] */
/* @0x27f78c strb r0, [r1, r2] */
/* @0x27f790 ldr r3, [sp, #0x24] */
/* @0x27f794 cmp r3, #47 */
/* @0x27f798 ldr r3, [r4, #0x8] */
/* @0x27f79c moveq r2, #0 */
/* @0x27f7a0 movne r2, #5 */
/* @0x27f7a4 add r3, r3, r3, lsl #2 */
/* @0x27f7a8 add r3, r4, r3, lsl #2 */
/* @0x27f7ac str r2, [r3, #0x24] */
/* @0x27f7b0 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x27f7b4 ldr r3, [sp, #0x24] */
/* @0x27f7b8 mov r9, r5 */
/* @0x27f7bc ldrb r2, [r4, #0x20] */
/* @0x27f7c0 cmp r2, r3 */
/* @0x27f7c4 beq 0x2805b8 <json_tokener_parse_ex+0x1570> */
/* @0x27f7c8 cmp r3, #92 */
/* @0x27f7cc movne r7, r5 */
/* @0x27f7d0 bne 0x27f7fc <json_tokener_parse_ex+0x7b4> */
/* @0x27f7d4 b 0x2805c0 <json_tokener_parse_ex+0x1578> */
/* @0x27f7d8 cmp r6, r3 */
/* @0x27f7dc beq 0x27fd0c <json_tokener_parse_ex+0xcc4> */
/* @0x27f7e0 bl 0x27eefc <utf8_get_charW> */
/* @0x27f7e4 ldrb r3, [r4, #0x20] */
/* @0x27f7e8 cmp r3, r0 */
/* @0x27f7ec str r0, [sp, #0x24] */
/* @0x27f7f0 beq 0x280210 <json_tokener_parse_ex+0x11c8> */
/* @0x27f7f4 cmp r0, #92 */
/* @0x27f7f8 beq 0x280314 <json_tokener_parse_ex+0x12cc> */
/* @0x27f7fc mov r0, r7 */
/* @0x27f800 bl 0x27eefc <utf8_get_charW> */
/* @0x27f804 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f808 ldr r8, [r4, #0x14] */
/* @0x27f80c add r7, r7, r0 */
/* @0x27f810 mov r0, r7 */
/* @0x27f814 bl 0x27eefc <utf8_get_charW> */
/* @0x27f818 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f81c ldr r3, [sp, #0x24] */
/* @0x27f820 cmp r3, #0 */
/* @0x27f824 add r3, r8, r0 */
/* @0x27f828 mov r0, r7 */
/* @0x27f82c str r3, [r4, #0x14] */
/* @0x27f830 bne 0x27f7d8 <json_tokener_parse_ex+0x790> */
/* @0x27f834 b 0x27f690 <json_tokener_parse_ex+0x648> */
/* @0x27f838 ldr r8, [sp, #0x24] */
/* @0x27f83c cmp r8, #93 */
/* @0x27f840 beq 0x27fd3c <json_tokener_parse_ex+0xcf4> */
/* @0x27f844 cmp r3, #30 */
/* @0x27f848 bgt 0x2805f4 <json_tokener_parse_ex+0x15ac> */
/* @0x27f84c add r2, r1, r3 */
/* @0x27f850 add r3, r3, #1 */
/* @0x27f854 mov r12, #14 */
/* @0x27f858 add r2, r4, r2, lsl #2 */
/* @0x27f85c mov r1, r3 */
/* @0x27f860 mov r0, r4 */
/* @0x27f864 str r12, [r2, #0x24] */
/* @0x27f868 str r3, [r4, #0x8] */
/* @0x27f86c bl 0x27eec4 <json_object_array_get_idx+0xc4> */
/* @0x27f870 ldr r3, [r4, #0x8] */
/* @0x27f874 lsl r1, r3, #2 */
/* @0x27f878 add r2, r1, r3 */
/* @0x27f87c add r2, r4, r2, lsl #2 */
/* @0x27f880 ldr r2, [r2, #0x24] */
/* @0x27f884 b 0x27f204 <json_tokener_parse_ex+0x1bc> */
/* @0x27f888 add r3, r1, r3 */
/* @0x27f88c ldr r1, [sp, #0x4] */
/* @0x27f890 add r3, r4, r3, lsl #2 */
/* @0x27f894 ldr r0, [r3, #0x30] */
/* @0x27f898 bl 0x27edf0 <json_object_array_add> */
/* @0x27f89c ldr r3, [r4, #0x8] */
/* @0x27f8a0 mov r12, #15 */
/* @0x27f8a4 mov r2, #0 */
/* @0x27f8a8 lsl r1, r3, #2 */
/* @0x27f8ac add r0, r1, r3 */
/* @0x27f8b0 add r0, r4, r0, lsl #2 */
/* @0x27f8b4 str r9, [r0, #0x24] */
/* @0x27f8b8 str r12, [r0, #0x28] */
/* @0x27f8bc b 0x27f204 <json_tokener_parse_ex+0x1bc> */
/* @0x27f8c0 ldr r8, [sp, #0x24] */
/* @0x27f8c4 cmp r8, #93 */
/* @0x27f8c8 beq 0x27fd3c <json_tokener_parse_ex+0xcf4> */
/* @0x27f8cc cmp r8, #44 */
/* @0x27f8d0 bne 0x2806a0 <json_tokener_parse_ex+0x1658> */
/* @0x27f8d4 add r3, r1, r3 */
/* @0x27f8d8 mov r0, #13 */
/* @0x27f8dc mov r2, #0 */
/* @0x27f8e0 add r3, r4, r3, lsl #2 */
/* @0x27f8e4 str r0, [r3, #0x28] */
/* @0x27f8e8 str r2, [r3, #0x24] */
/* @0x27f8ec b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x27f8f0 ldr r8, [sp, #0x24] */
/* @0x27f8f4 cmp r8, #125 */
/* @0x27f8f8 beq 0x27fd3c <json_tokener_parse_ex+0xcf4> */
/* @0x27f8fc cmp r8, #34 */
/* @0x27f900 cmpne r8, #39 */
/* @0x27f904 bne 0x280694 <json_tokener_parse_ex+0x164c> */
/* @0x27f908 strb r8, [r4, #0x20] */
/* @0x27f90c ldr r0, [r4, #0x4] */
/* @0x27f910 bl 0x280e9c <printbuf_reset> */
/* @0x27f914 ldr r3, [r4, #0x8] */
/* @0x27f918 mov r2, #17 */
/* @0x27f91c add r3, r3, r3, lsl #2 */
/* @0x27f920 add r3, r4, r3, lsl #2 */
/* @0x27f924 str r2, [r3, #0x24] */
/* @0x27f928 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x27f92c ldr r3, [sp, #0x24] */
/* @0x27f930 mov r9, r5 */
/* @0x27f934 ldrb r2, [r4, #0x20] */
/* @0x27f938 cmp r2, r3 */
/* @0x27f93c beq 0x2805d0 <json_tokener_parse_ex+0x1588> */
/* @0x27f940 cmp r3, #92 */
/* @0x27f944 movne r7, r5 */
/* @0x27f948 bne 0x27f974 <json_tokener_parse_ex+0x92c> */
/* @0x27f94c b 0x2805c8 <json_tokener_parse_ex+0x1580> */
/* @0x27f950 cmp r6, r3 */
/* @0x27f954 beq 0x27fd0c <json_tokener_parse_ex+0xcc4> */
/* @0x27f958 bl 0x27eefc <utf8_get_charW> */
/* @0x27f95c ldrb r3, [r4, #0x20] */
/* @0x27f960 cmp r3, r0 */
/* @0x27f964 str r0, [sp, #0x24] */
/* @0x27f968 beq 0x280298 <json_tokener_parse_ex+0x1250> */
/* @0x27f96c cmp r0, #92 */
/* @0x27f970 beq 0x280384 <json_tokener_parse_ex+0x133c> */
/* @0x27f974 mov r0, r7 */
/* @0x27f978 bl 0x27eefc <utf8_get_charW> */
/* @0x27f97c bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f980 ldr r8, [r4, #0x14] */
/* @0x27f984 add r7, r7, r0 */
/* @0x27f988 mov r0, r7 */
/* @0x27f98c bl 0x27eefc <utf8_get_charW> */
/* @0x27f990 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27f994 ldr r3, [sp, #0x24] */
/* @0x27f998 cmp r3, #0 */
/* @0x27f99c add r3, r8, r0 */
/* @0x27f9a0 mov r0, r7 */
/* @0x27f9a4 str r3, [r4, #0x14] */
/* @0x27f9a8 bne 0x27f950 <json_tokener_parse_ex+0x908> */
/* @0x27f9ac b 0x27f690 <json_tokener_parse_ex+0x648> */
/* @0x27f9b0 ldr r8, [sp, #0x24] */
/* @0x27f9b4 cmp r8, #58 */
/* @0x27f9b8 bne 0x2805e8 <json_tokener_parse_ex+0x15a0> */
/* @0x27f9bc add r3, r1, r3 */
/* @0x27f9c0 mov r0, #19 */
/* @0x27f9c4 mov r2, #0 */
/* @0x27f9c8 add r3, r4, r3, lsl #2 */
/* @0x27f9cc str r0, [r3, #0x28] */
/* @0x27f9d0 str r2, [r3, #0x24] */
/* @0x27f9d4 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x27f9d8 cmp r3, #30 */
/* @0x27f9dc bgt 0x2805d8 <json_tokener_parse_ex+0x1590> */
/* @0x27f9e0 add r2, r1, r3 */
/* @0x27f9e4 mov r12, #20 */
/* @0x27f9e8 add r3, r3, #1 */
/* @0x27f9ec b 0x27f858 <json_tokener_parse_ex+0x810> */
/* @0x27f9f0 add r3, r1, r3 */
/* @0x27f9f4 ldr r2, [sp, #0x4] */
/* @0x27f9f8 add r3, r4, r3, lsl #2 */
/* @0x27f9fc ldr r1, [r3, #0x34] */
/* @0x27fa00 ldr r0, [r3, #0x30] */
/* @0x27fa04 bl 0x27ea00 <json_object_object_add> */
/* @0x27fa08 ldr r3, [r4, #0x8] */
/* @0x27fa0c add r3, r3, r3, lsl #2 */
/* @0x27fa10 add r3, r4, r3, lsl #2 */
/* @0x27fa14 ldr r0, [r3, #0x34] */
/* @0x27fa18 bl 0xb655c <free@plt> */
/* @0x27fa1c ldr r3, [r4, #0x8] */
/* @0x27fa20 mov r12, #21 */
/* @0x27fa24 mov r2, #0 */
/* @0x27fa28 lsl r1, r3, #2 */
/* @0x27fa2c add r0, r1, r3 */
/* @0x27fa30 add r0, r4, r0, lsl #2 */
/* @0x27fa34 str r9, [r0, #0x34] */
/* @0x27fa38 str r9, [r0, #0x24] */
/* @0x27fa3c str r12, [r0, #0x28] */
/* @0x27fa40 b 0x27f204 <json_tokener_parse_ex+0x1bc> */
/* @0x27fa44 ldr r7, [pc, #0x63c] */
/* @0x27fa48 ldr r8, [sp, #0x24] */
/* @0x27fa4c ldr r7, [pc, r7] */
/* @0x27fa50 b 0x27fad0 <json_tokener_parse_ex+0xa88> */
/* @0x27fa54 ldr r3, [r4, #0x10] */
/* @0x27fa58 cmp r8, #57 */
/* @0x27fa5c ldr r1, [r4, #0x1c] */
/* @0x27fa60 suble r2, r8, #48 */
/* @0x27fa64 rsb r12, r3, #3 */
/* @0x27fa68 add r3, r3, #1 */
/* @0x27fa6c cmp r3, #4 */
/* @0x27fa70 str r3, [r4, #0x10] */
/* @0x27fa74 lsl r3, r12, #2 */
/* @0x27fa78 mov r0, r5 */
/* @0x27fa7c add r2, r1, r2, lsl r3 */
/* @0x27fa80 str r2, [r4, #0x1c] */
/* @0x27fa84 beq 0x27ffe8 <json_tokener_parse_ex+0xfa0> */
/* @0x27fa88 bl 0x27eefc <utf8_get_charW> */
/* @0x27fa8c bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27fa90 ldr r8, [r4, #0x14] */
/* @0x27fa94 add r5, r5, r0 */
/* @0x27fa98 mov r0, r5 */
/* @0x27fa9c bl 0x27eefc <utf8_get_charW> */
/* @0x27faa0 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27faa4 ldr r3, [sp, #0x24] */
/* @0x27faa8 cmp r3, #0 */
/* @0x27faac add r3, r8, r0 */
/* @0x27fab0 mov r0, r5 */
/* @0x27fab4 str r3, [r4, #0x14] */
/* @0x27fab8 beq 0x27f1a8 <json_tokener_parse_ex+0x160> */
/* @0x27fabc cmp r6, r3 */
/* @0x27fac0 beq 0x27fe58 <json_tokener_parse_ex+0xe10> */
/* @0x27fac4 bl 0x27eefc <utf8_get_charW> */
/* @0x27fac8 mov r8, r0 */
/* @0x27facc str r0, [sp, #0x24] */
/* @0x27fad0 ldr r0, [r7] */
/* @0x27fad4 mov r1, r8 */
/* @0x27fad8 bl 0xb6634 <strchr@plt> */
/* @0x27fadc and r2, r8, #7 */
/* @0x27fae0 add r2, r2, #9 */
/* @0x27fae4 cmp r0, #0 */
/* @0x27fae8 bne 0x27fa54 <json_tokener_parse_ex+0xa0c> */
/* @0x27faec mov r3, #12 */
/* @0x27faf0 str r3, [r4, #0x18] */
/* @0x27faf4 b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x27faf8 ldr r0, [r4, #0x4] */
/* @0x27fafc ldr r3, [r0, #0x4] */
/* @0x27fb00 ldr r2, [r0, #0x8] */
/* @0x27fb04 rsb r2, r3, r2 */
/* @0x27fb08 cmp r2, #1 */
/* @0x27fb0c ble 0x27ffb8 <json_tokener_parse_ex+0xf70> */
/* @0x27fb10 ldr r2, [r0] */
/* @0x27fb14 ldrb r1, [sp, #0x24] */
/* @0x27fb18 strb r1, [r2, r3] */
/* @0x27fb1c ldr r3, [r4, #0x4] */
/* @0x27fb20 ldm r3, {r1, r2} */
/* @0x27fb24 add r2, r2, #1 */
/* @0x27fb28 str r2, [r3, #0x4] */
/* @0x27fb2c strb r9, [r1, r2] */
/* @0x27fb30 ldr r3, [r4, #0x4] */
/* @0x27fb34 ldr r8, [r4, #0x10] */
/* @0x27fb38 ldr r0, [sp, #0x8] */
/* @0x27fb3c ldr r10, [r3] */
/* @0x27fb40 add r7, r8, #1 */
/* @0x27fb44 cmp r7, #3 */
/* @0x27fb48 mov r1, r10 */
/* @0x27fb4c movle r2, r7 */
/* @0x27fb50 movgt r2, #4 */
/* @0x27fb54 bl 0xb6d18 <strncasecmp@plt> */
/* @0x27fb58 subs r11, r0, #0 */
/* @0x27fb5c bne 0x27fd7c <json_tokener_parse_ex+0xd34> */
/* @0x27fb60 cmp r8, #4 */
/* @0x27fb64 bne 0x2805a0 <json_tokener_parse_ex+0x1558> */
/* @0x27fb68 mov r0, #1 */
/* @0x27fb6c ldr r7, [r4, #0x8] */
/* @0x27fb70 bl 0x27ea48 <json_object_new_boolean> */
/* @0x27fb74 ldr r3, [r4, #0x8] */
/* @0x27fb78 mov r8, #2 */
/* @0x27fb7c mov r2, r11 */
/* @0x27fb80 add r7, r7, r7, lsl #2 */
/* @0x27fb84 lsl r1, r3, r8 */
/* @0x27fb88 add r12, r1, r3 */
/* @0x27fb8c add r7, r4, r7, lsl #2 */
/* @0x27fb90 add r12, r4, r12, lsl #2 */
/* @0x27fb94 str r0, [r7, #0x30] */
/* @0x27fb98 str r11, [r12, #0x24] */
/* @0x27fb9c str r8, [r12, #0x28] */
/* @0x27fba0 b 0x27f204 <json_tokener_parse_ex+0x1bc> */
/* @0x27fba4 ldr r11, [sp, #0x24] */
/* @0x27fba8 cmp r11, #0 */
/* @0x27fbac beq 0x27fc94 <json_tokener_parse_ex+0xc4c> */
/* @0x27fbb0 ldr r10, [pc, #0x4d4] */
/* @0x27fbb4 mov r7, r5 */
/* @0x27fbb8 mov r8, #0 */
/* @0x27fbbc ldr r10, [pc, r10] */
/* @0x27fbc0 b 0x27fc28 <json_tokener_parse_ex+0xbe0> */
/* @0x27fbc4 cmp r11, #46 */
/* @0x27fbc8 cmpne r11, #101 */
/* @0x27fbcc add r8, r8, #1 */
/* @0x27fbd0 moveq r2, #1 */
/* @0x27fbd4 streq r2, [r4, #0xc] */
/* @0x27fbd8 bl 0x27eefc <utf8_get_charW> */
/* @0x27fbdc bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27fbe0 ldr r11, [r4, #0x14] */
/* @0x27fbe4 add r7, r7, r0 */
/* @0x27fbe8 mov r0, r7 */
/* @0x27fbec bl 0x27eefc <utf8_get_charW> */
/* @0x27fbf0 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27fbf4 ldr r3, [sp, #0x24] */
/* @0x27fbf8 cmp r3, #0 */
/* @0x27fbfc add r3, r11, r0 */
/* @0x27fc00 mov r0, r7 */
/* @0x27fc04 str r3, [r4, #0x14] */
/* @0x27fc08 beq 0x27fe08 <json_tokener_parse_ex+0xdc0> */
/* @0x27fc0c cmp r6, r3 */
/* @0x27fc10 beq 0x27fddc <json_tokener_parse_ex+0xd94> */
/* @0x27fc14 bl 0x27eefc <utf8_get_charW> */
/* @0x27fc18 cmp r0, #0 */
/* @0x27fc1c mov r11, r0 */
/* @0x27fc20 str r0, [sp, #0x24] */
/* @0x27fc24 beq 0x27fc4c <json_tokener_parse_ex+0xc04> */
/* @0x27fc28 ldr r0, [r10] */
/* @0x27fc2c mov r1, r11 */
/* @0x27fc30 bl 0xb6634 <strchr@plt> */
/* @0x27fc34 cmp r0, #0 */
/* @0x27fc38 mov r0, r7 */
/* @0x27fc3c bne 0x27fbc4 <json_tokener_parse_ex+0xb7c> */
/* @0x27fc40 cmp r8, #0 */
/* @0x27fc44 moveq r5, r7 */
/* @0x27fc48 beq 0x27fc94 <json_tokener_parse_ex+0xc4c> */
/* @0x27fc4c ldr r0, [r4, #0x4] */
/* @0x27fc50 ldr r3, [r0, #0x4] */
/* @0x27fc54 ldr r2, [r0, #0x8] */
/* @0x27fc58 rsb r2, r3, r2 */
/* @0x27fc5c cmp r2, r8 */
/* @0x27fc60 ble 0x28009c <json_tokener_parse_ex+0x1054> */
/* @0x27fc64 ldr r0, [r0] */
/* @0x27fc68 mov r1, r5 */
/* @0x27fc6c mov r2, r8 */
/* @0x27fc70 mov r5, r7 */
/* @0x27fc74 add r0, r0, r3 */
/* @0x27fc78 bl 0xb65bc <memcpy@plt> */
/* @0x27fc7c ldr r3, [r4, #0x4] */
/* @0x27fc80 ldr r1, [r3, #0x4] */
/* @0x27fc84 ldr r2, [r3] */
/* @0x27fc88 add r8, r8, r1 */
/* @0x27fc8c str r8, [r3, #0x4] */
/* @0x27fc90 strb r9, [r2, r8] */
/* @0x27fc94 ldr r3, [r4, #0xc] */
/* @0x27fc98 cmp r3, #0 */
/* @0x27fc9c beq 0x2803e0 <json_tokener_parse_ex+0x1398> */
/* @0x27fca0 ldr r3, [r4, #0x4] */
/* @0x27fca4 add r2, sp, #48 */
/* @0x27fca8 ldr r1, [sp, #0x14] */
/* @0x27fcac ldr r0, [r3] */
/* @0x27fcb0 bl 0xb68f8 <sscanf@plt> */
/* @0x27fcb4 cmp r0, #1 */
/* @0x27fcb8 bne 0x280408 <json_tokener_parse_ex+0x13c0> */
/* @0x27fcbc ldrd r0, r1, [sp, #48] */
/* @0x27fcc0 ldr r7, [r4, #0x8] */
/* @0x27fcc4 bl 0x27ebb8 <json_object_new_double> */
/* @0x27fcc8 add r7, r7, r7, lsl #2 */
/* @0x27fccc add r7, r4, r7, lsl #2 */
/* @0x27fcd0 str r0, [r7, #0x30] */
/* @0x27fcd4 ldr r3, [r4, #0x8] */
/* @0x27fcd8 mov r12, #2 */
/* @0x27fcdc mov r2, #0 */
/* @0x27fce0 lsl r1, r3, r12 */
/* @0x27fce4 add r0, r1, r3 */
/* @0x27fce8 add r0, r4, r0, lsl #2 */
/* @0x27fcec str r9, [r0, #0x24] */
/* @0x27fcf0 str r12, [r0, #0x28] */
/* @0x27fcf4 b 0x27f204 <json_tokener_parse_ex+0x1bc> */
/* @0x27fcf8 mov r1, r5 */
/* @0x27fcfc mov r2, r7 */
/* @0x27fd00 bl 0x280d20 <printbuf_memappend> */
/* @0x27fd04 ldr r8, [sp, #0x24] */
/* @0x27fd08 b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x27fd0c ldr r3, [r4, #0x8] */
/* @0x27fd10 cmp r3, #0 */
/* @0x27fd14 bne 0x27fd30 <json_tokener_parse_ex+0xce8> */
/* @0x27fd18 ldr r3, [r4, #0x24] */
/* @0x27fd1c cmp r3, #0 */
/* @0x27fd20 bne 0x27fd30 <json_tokener_parse_ex+0xce8> */
/* @0x27fd24 ldr r2, [r4, #0x28] */
/* @0x27fd28 cmp r2, #2 */
/* @0x27fd2c beq 0x27fd34 <json_tokener_parse_ex+0xcec> */
/* @0x27fd30 mov r3, #1 */
/* @0x27fd34 str r3, [r4, #0x18] */
/* @0x27fd38 b 0x27f690 <json_tokener_parse_ex+0x648> */
/* @0x27fd3c add r3, r1, r3 */
/* @0x27fd40 mov r0, #2 */
/* @0x27fd44 mov r2, #0 */
/* @0x27fd48 add r3, r4, r3, lsl #2 */
/* @0x27fd4c str r0, [r3, #0x28] */
/* @0x27fd50 str r2, [r3, #0x24] */
/* @0x27fd54 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x27fd58 add r7, sp, #56 */
/* @0x27fd5c ldr r8, [r4, #0x4] */
/* @0x27fd60 ldr r0, [r7, #-0x14]! */
/* @0x27fd64 bl 0x27ef80 <utf8_char_sizeW> */
/* @0x27fd68 mov r1, r7 */
/* @0x27fd6c mov r2, r0 */
/* @0x27fd70 mov r0, r8 */
/* @0x27fd74 bl 0x280d20 <printbuf_memappend> */
/* @0x27fd78 b 0x27f524 <json_tokener_parse_ex+0x4dc> */
/* @0x27fd7c cmp r7, #4 */
/* @0x27fd80 mov r1, r10 */
/* @0x27fd84 ldr r0, [sp, #0x10] */
/* @0x27fd88 movle r2, r7 */
/* @0x27fd8c movgt r2, #5 */
/* @0x27fd90 bl 0xb6d18 <strncasecmp@plt> */
/* @0x27fd94 subs r10, r0, #0 */
/* @0x27fd98 bne 0x2806c4 <json_tokener_parse_ex+0x167c> */
/* @0x27fd9c cmp r8, #5 */
/* @0x27fda0 bne 0x2805a0 <json_tokener_parse_ex+0x1558> */
/* @0x27fda4 ldr r7, [r4, #0x8] */
/* @0x27fda8 bl 0x27ea48 <json_object_new_boolean> */
/* @0x27fdac ldr r3, [r4, #0x8] */
/* @0x27fdb0 mov r8, #2 */
/* @0x27fdb4 mov r2, r10 */
/* @0x27fdb8 add r7, r7, r7, lsl #2 */
/* @0x27fdbc lsl r1, r3, r8 */
/* @0x27fdc0 add r12, r1, r3 */
/* @0x27fdc4 add r7, r4, r7, lsl #2 */
/* @0x27fdc8 add r12, r4, r12, lsl #2 */
/* @0x27fdcc str r0, [r7, #0x30] */
/* @0x27fdd0 str r10, [r12, #0x24] */
/* @0x27fdd4 str r8, [r12, #0x28] */
/* @0x27fdd8 b 0x27f204 <json_tokener_parse_ex+0x1bc> */
/* @0x27fddc ldr r3, [r4, #0x8] */
/* @0x27fde0 cmp r3, #0 */
/* @0x27fde4 bne 0x27fe00 <json_tokener_parse_ex+0xdb8> */
/* @0x27fde8 ldr r3, [r4, #0x24] */
/* @0x27fdec cmp r3, #0 */
/* @0x27fdf0 bne 0x27fe00 <json_tokener_parse_ex+0xdb8> */
/* @0x27fdf4 ldr r2, [r4, #0x28] */
/* @0x27fdf8 cmp r2, #2 */
/* @0x27fdfc beq 0x27fe04 <json_tokener_parse_ex+0xdbc> */
/* @0x27fe00 mov r3, #1 */
/* @0x27fe04 str r3, [r4, #0x18] */
/* @0x27fe08 ldr r0, [r4, #0x4] */
/* @0x27fe0c ldr r3, [r0, #0x4] */
/* @0x27fe10 ldr r2, [r0, #0x8] */
/* @0x27fe14 rsb r2, r3, r2 */
/* @0x27fe18 cmp r2, r8 */
/* @0x27fe1c ble 0x280058 <json_tokener_parse_ex+0x1010> */
/* @0x27fe20 ldr r0, [r0] */
/* @0x27fe24 mov r2, r8 */
/* @0x27fe28 mov r1, r5 */
/* @0x27fe2c add r0, r0, r3 */
/* @0x27fe30 bl 0xb65bc <memcpy@plt> */
/* @0x27fe34 ldr r3, [r4, #0x4] */
/* @0x27fe38 mov r1, #0 */
/* @0x27fe3c ldr r0, [r3, #0x4] */
/* @0x27fe40 ldr r2, [r3] */
/* @0x27fe44 add r8, r8, r0 */
/* @0x27fe48 str r8, [r3, #0x4] */
/* @0x27fe4c strb r1, [r2, r8] */
/* @0x27fe50 ldr r8, [sp, #0x24] */
/* @0x27fe54 b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x27fe58 ldr r3, [r4, #0x8] */
/* @0x27fe5c cmp r3, #0 */
/* @0x27fe60 bne 0x27fe7c <json_tokener_parse_ex+0xe34> */
/* @0x27fe64 ldr r3, [r4, #0x24] */
/* @0x27fe68 cmp r3, #0 */
/* @0x27fe6c bne 0x27fe7c <json_tokener_parse_ex+0xe34> */
/* @0x27fe70 ldr r2, [r4, #0x28] */
/* @0x27fe74 cmp r2, #2 */
/* @0x27fe78 beq 0x27fe80 <json_tokener_parse_ex+0xe38> */
/* @0x27fe7c mov r3, #1 */
/* @0x27fe80 str r3, [r4, #0x18] */
/* @0x27fe84 b 0x27f100 <json_tokener_parse_ex+0xb8> */
/* @0x27fe88 cmp r8, #47 */
/* @0x27fe8c beq 0x27fea0 <json_tokener_parse_ex+0xe58> */
/* @0x27fe90 cmp r8, #92 */
/* @0x27fe94 beq 0x27fea0 <json_tokener_parse_ex+0xe58> */
/* @0x27fe98 cmp r8, #34 */
/* @0x27fe9c bne 0x27faec <json_tokener_parse_ex+0xaa4> */
/* @0x27fea0 ldr r0, [r4, #0x4] */
/* @0x27fea4 ldr r3, [r0, #0x4] */
/* @0x27fea8 ldr r2, [r0, #0x8] */
/* @0x27feac rsb r2, r3, r2 */
/* @0x27feb0 cmp r2, #1 */
/* @0x27feb4 ble 0x2804c8 <json_tokener_parse_ex+0x1480> */
/* @0x27feb8 ldr r2, [r0] */
/* @0x27febc mov r0, #0 */
/* @0x27fec0 ldrb r1, [sp, #0x24] */
/* @0x27fec4 strb r1, [r2, r3] */
/* @0x27fec8 ldr r3, [r4, #0x4] */
/* @0x27fecc ldm r3, {r1, r2} */
/* @0x27fed0 add r2, r2, #1 */
/* @0x27fed4 str r2, [r3, #0x4] */
/* @0x27fed8 strb r0, [r1, r2] */
/* @0x27fedc ldr r3, [r4, #0x8] */
/* @0x27fee0 add r3, r3, r3, lsl #2 */
/* @0x27fee4 add r3, r4, r3, lsl #2 */
/* @0x27fee8 ldr r2, [r3, #0x28] */
/* @0x27feec str r2, [r3, #0x24] */
/* @0x27fef0 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x27fef4 rsb r8, r5, r7 */
/* @0x27fef8 mov r5, r7 */
/* @0x27fefc ldr r0, [r4, #0x4] */
/* @0x27ff00 ldr r3, [r0, #0x4] */
/* @0x27ff04 ldr r2, [r0, #0x8] */
/* @0x27ff08 rsb r2, r3, r2 */
/* @0x27ff0c cmp r8, r2 */
/* @0x27ff10 bge 0x2800e4 <json_tokener_parse_ex+0x109c> */
/* @0x27ff14 ldr r0, [r0] */
/* @0x27ff18 mov r2, r8 */
/* @0x27ff1c mov r1, r9 */
/* @0x27ff20 add r0, r0, r3 */
/* @0x27ff24 bl 0xb65bc <memcpy@plt> */
/* @0x27ff28 ldr r3, [r4, #0x4] */
/* @0x27ff2c mov r1, #0 */
/* @0x27ff30 ldr r0, [r3, #0x4] */
/* @0x27ff34 ldr r2, [r3] */
/* @0x27ff38 add r8, r8, r0 */
/* @0x27ff3c str r8, [r3, #0x4] */
/* @0x27ff40 strb r1, [r2, r8] */
/* @0x27ff44 ldr r3, [r4, #0x8] */
/* @0x27ff48 mov r2, #0 */
/* @0x27ff4c add r3, r3, r3, lsl #2 */
/* @0x27ff50 add r3, r4, r3, lsl #2 */
/* @0x27ff54 str r2, [r3, #0x24] */
/* @0x27ff58 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x27ff5c ldr r0, [r4, #0x4] */
/* @0x27ff60 add r8, r7, #1 */
/* @0x27ff64 rsb r8, r5, r8 */
/* @0x27ff68 ldr r3, [r0, #0x4] */
/* @0x27ff6c ldr r2, [r0, #0x8] */
/* @0x27ff70 rsb r2, r3, r2 */
/* @0x27ff74 cmp r2, r8 */
/* @0x27ff78 bgt 0x2800b0 <json_tokener_parse_ex+0x1068> */
/* @0x27ff7c mov r1, r5 */
/* @0x27ff80 mov r2, r8 */
/* @0x27ff84 bl 0x280d20 <printbuf_memappend> */
/* @0x27ff88 ldr r3, [r4, #0x8] */
/* @0x27ff8c mov r2, #7 */
/* @0x27ff90 mov r5, r7 */
/* @0x27ff94 add r3, r3, r3, lsl #2 */
/* @0x27ff98 add r3, r4, r3, lsl #2 */
/* @0x27ff9c str r2, [r3, #0x24] */
/* @0x27ffa0 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x27ffa4 add r3, r1, r3 */
/* @0x27ffa8 mov r2, #5 */
/* @0x27ffac add r3, r4, r3, lsl #2 */
/* @0x27ffb0 str r2, [r3, #0x24] */
/* @0x27ffb4 b 0x27f5a4 <json_tokener_parse_ex+0x55c> */
/* @0x27ffb8 add r1, sp, #36 */
/* @0x27ffbc mov r2, #1 */
/* @0x27ffc0 bl 0x280d20 <printbuf_memappend> */
/* @0x27ffc4 b 0x27fb30 <json_tokener_parse_ex+0xae8> */
/* @0x27ffc8 add r1, sp, #36 */
/* @0x27ffcc mov r2, #1 */
/* @0x27ffd0 bl 0x280d20 <printbuf_memappend> */
/* @0x27ffd4 b 0x27f790 <json_tokener_parse_ex+0x748> */
/* @0x27ffd8 add r1, sp, #36 */
/* @0x27ffdc mov r2, #1 */
/* @0x27ffe0 bl 0x280d20 <printbuf_memappend> */
/* @0x27ffe4 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x27ffe8 cmp r2, #127 */
/* @0x27ffec bls 0x2801d4 <json_tokener_parse_ex+0x118c> */
/* @0x27fff0 cmp r2, #2048 */
/* @0x27fff4 bhs 0x280520 <json_tokener_parse_ex+0x14d8> */
/* @0x27fff8 lsr r1, r2, #6 */
/* @0x27fffc and r3, r2, #63 */
/* @0x280000 ldr r0, [r4, #0x4] */
/* @0x280004 mvn r1, r1, lsl #26 */
/* @0x280008 mvn r3, r3, lsl #25 */
/* @0x28000c mvn r3, r3, lsr #25 */
/* @0x280010 mvn r1, r1, lsr #26 */
/* @0x280014 strb r3, [sp, #0x31] */
/* @0x280018 strb r1, [sp, #0x30] */
/* @0x28001c ldr r3, [r0, #0x4] */
/* @0x280020 ldr r2, [r0, #0x8] */
/* @0x280024 rsb r2, r3, r2 */
/* @0x280028 cmp r2, #2 */
/* @0x28002c ble 0x2805a8 <json_tokener_parse_ex+0x1560> */
/* @0x280030 ldr r2, [r0] */
/* @0x280034 mov r0, #0 */
/* @0x280038 ldrh r1, [sp, #48] */
/* @0x28003c strh r1, [r2, r3] */
/* @0x280040 ldr r3, [r4, #0x4] */
/* @0x280044 ldm r3, {r1, r2} */
/* @0x280048 add r2, r2, #2 */
/* @0x28004c str r2, [r3, #0x4] */
/* @0x280050 strb r0, [r1, r2] */
/* @0x280054 b 0x27fedc <json_tokener_parse_ex+0xe94> */
/* @0x280058 mov r2, r8 */
/* @0x28005c mov r1, r5 */
/* @0x280060 bl 0x280d20 <printbuf_memappend> */
/* @0x280064 ldr r8, [sp, #0x24] */
/* @0x280068 b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x28006c andeq r5, r11, r8, lsr #19 */
/* @0x280070 muleq r11, r4, r9 */
/* @0x280074 andeq r3, r11, r0, lsl r2 */
/* @0x280078 andeq r3, r11, r8, asr r4 */
/* @0x28007c andeq r1, r12, r8, ror #2 */
/* @0x280080 andeq r8, sp, r12, lsl r2 */
/* @0x280084 ldrsbeq lr, [r6], -r0 */
/* @0x280088 andseq r1, r7, r12, lsr lr */
/* @0x28008c ldrsbeq r1, [r7], -r0 */
/* @0x280090 andeq r2, r11, r0, lsr #12 */
/* @0x280094 andeq r6, sp, r4, lsr #24 */
/* @0x280098 andeq r6, sp, r0, lsl #24 */
/* @0x28009c mov r1, r5 */
/* @0x2800a0 mov r2, r8 */
/* @0x2800a4 mov r5, r7 */
/* @0x2800a8 bl 0x280d20 <printbuf_memappend> */
/* @0x2800ac b 0x27fc94 <json_tokener_parse_ex+0xc4c> */
/* @0x2800b0 ldr r0, [r0] */
/* @0x2800b4 mov r2, r8 */
/* @0x2800b8 mov r1, r5 */
/* @0x2800bc add r0, r0, r3 */
/* @0x2800c0 bl 0xb65bc <memcpy@plt> */
/* @0x2800c4 ldr r3, [r4, #0x4] */
/* @0x2800c8 mov r1, #0 */
/* @0x2800cc ldr r0, [r3, #0x4] */
/* @0x2800d0 ldr r2, [r3] */
/* @0x2800d4 add r8, r8, r0 */
/* @0x2800d8 str r8, [r3, #0x4] */
/* @0x2800dc strb r1, [r2, r8] */
/* @0x2800e0 b 0x27ff88 <json_tokener_parse_ex+0xf40> */
/* @0x2800e4 mov r1, r9 */
/* @0x2800e8 mov r2, r8 */
/* @0x2800ec bl 0x280d20 <printbuf_memappend> */
/* @0x2800f0 b 0x27ff44 <json_tokener_parse_ex+0xefc> */
/* @0x2800f4 add r3, r1, r3 */
/* @0x2800f8 mov r2, #3 */
/* @0x2800fc add r3, r4, r3, lsl #2 */
/* @0x280100 ldr r0, [r4, #0x4] */
/* @0x280104 str r2, [r3, #0x24] */
/* @0x280108 bl 0x280e9c <printbuf_reset> */
/* @0x28010c ldr r3, [r4, #0x8] */
/* @0x280110 str r9, [r4, #0x10] */
/* @0x280114 lsl r1, r3, #2 */
/* @0x280118 add r2, r1, r3 */
/* @0x28011c add r2, r4, r2, lsl #2 */
/* @0x280120 ldr r2, [r2, #0x24] */
/* @0x280124 b 0x27f204 <json_tokener_parse_ex+0x1bc> */
/* @0x280128 add r3, r1, r3 */
/* @0x28012c mov r2, #11 */
/* @0x280130 b 0x2800fc <json_tokener_parse_ex+0x10b4> */
/* @0x280134 add r3, r1, r3 */
/* @0x280138 mov r2, #12 */
/* @0x28013c ldr r0, [r4, #0x4] */
/* @0x280140 add r3, r4, r3, lsl #2 */
/* @0x280144 str r2, [r3, #0x24] */
/* @0x280148 bl 0x280e9c <printbuf_reset> */
/* @0x28014c ldr r3, [r4, #0x8] */
/* @0x280150 str r9, [r4, #0xc] */
/* @0x280154 lsl r1, r3, #2 */
/* @0x280158 add r2, r1, r3 */
/* @0x28015c add r2, r4, r2, lsl #2 */
/* @0x280160 ldr r2, [r2, #0x24] */
/* @0x280164 b 0x27f204 <json_tokener_parse_ex+0x1bc> */
/* @0x280168 add r3, r1, r3 */
/* @0x28016c mov r2, #8 */
/* @0x280170 ldr r0, [r4, #0x4] */
/* @0x280174 add r3, r4, r3, lsl #2 */
/* @0x280178 str r2, [r3, #0x24] */
/* @0x28017c bl 0x280e9c <printbuf_reset> */
/* @0x280180 ldr r3, [sp, #0x24] */
/* @0x280184 strb r3, [r4, #0x20] */
/* @0x280188 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x28018c add r3, r1, r3 */
/* @0x280190 mov r0, #0 */
/* @0x280194 mov r2, #16 */
/* @0x280198 add r7, r4, r3, lsl #2 */
/* @0x28019c str r0, [r7, #0x24] */
/* @0x2801a0 str r2, [r7, #0x28] */
/* @0x2801a4 bl 0x27e89c <json_object_new_object> */
/* @0x2801a8 str r0, [r7, #0x30] */
/* @0x2801ac b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x2801b0 add r3, r1, r3 */
/* @0x2801b4 mov r0, #0 */
/* @0x2801b8 mov r2, #13 */
/* @0x2801bc add r7, r4, r3, lsl #2 */
/* @0x2801c0 str r0, [r7, #0x24] */
/* @0x2801c4 str r2, [r7, #0x28] */
/* @0x2801c8 bl 0x27ed80 <json_object_new_array> */
/* @0x2801cc str r0, [r7, #0x30] */
/* @0x2801d0 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x2801d4 ldr r0, [r4, #0x4] */
/* @0x2801d8 uxtb r2, r2 */
/* @0x2801dc strb r2, [sp, #0x30] */
/* @0x2801e0 ldr r3, [r0, #0x4] */
/* @0x2801e4 ldr r1, [r0, #0x8] */
/* @0x2801e8 rsb r1, r3, r1 */
/* @0x2801ec cmp r1, #1 */
/* @0x2801f0 ble 0x280654 <json_tokener_parse_ex+0x160c> */
/* @0x2801f4 ldr r1, [r0] */
/* @0x2801f8 mov r0, #0 */
/* @0x2801fc strb r2, [r1, r3] */
/* @0x280200 b 0x27fec8 <json_tokener_parse_ex+0xe80> */
/* @0x280204 mov r3, #4 */
/* @0x280208 str r3, [r4, #0x18] */
/* @0x28020c b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x280210 rsb r8, r5, r7 */
/* @0x280214 mov r5, r7 */
/* @0x280218 ldr r0, [r4, #0x4] */
/* @0x28021c ldr r3, [r0, #0x4] */
/* @0x280220 ldr r2, [r0, #0x8] */
/* @0x280224 rsb r2, r3, r2 */
/* @0x280228 cmp r2, r8 */
/* @0x28022c ble 0x280428 <json_tokener_parse_ex+0x13e0> */
/* @0x280230 ldr r0, [r0] */
/* @0x280234 mov r2, r8 */
/* @0x280238 mov r1, r9 */
/* @0x28023c add r0, r0, r3 */
/* @0x280240 bl 0xb65bc <memcpy@plt> */
/* @0x280244 ldr r3, [r4, #0x4] */
/* @0x280248 mov r1, #0 */
/* @0x28024c ldr r0, [r3, #0x4] */
/* @0x280250 ldr r2, [r3] */
/* @0x280254 add r8, r8, r0 */
/* @0x280258 str r8, [r3, #0x4] */
/* @0x28025c strb r1, [r2, r8] */
/* @0x280260 ldmib r4, {r3, r7} */
/* @0x280264 add r7, r7, r7, lsl #2 */
/* @0x280268 ldr r0, [r3] */
/* @0x28026c bl 0x27ecc0 <json_object_new_string> */
/* @0x280270 ldr r3, [r4, #0x8] */
/* @0x280274 add r12, r4, r7, lsl #2 */
/* @0x280278 mov r1, #2 */
/* @0x28027c mov r2, #0 */
/* @0x280280 add r3, r3, r3, lsl #2 */
/* @0x280284 add r3, r4, r3, lsl #2 */
/* @0x280288 str r0, [r12, #0x30] */
/* @0x28028c str r1, [r3, #0x28] */
/* @0x280290 str r2, [r3, #0x24] */
/* @0x280294 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x280298 rsb r8, r5, r7 */
/* @0x28029c mov r5, r7 */
/* @0x2802a0 ldr r0, [r4, #0x4] */
/* @0x2802a4 ldr r3, [r0, #0x4] */
/* @0x2802a8 ldr r2, [r0, #0x8] */
/* @0x2802ac rsb r2, r3, r2 */
/* @0x2802b0 cmp r2, r8 */
/* @0x2802b4 ble 0x280418 <json_tokener_parse_ex+0x13d0> */
/* @0x2802b8 ldr r0, [r0] */
/* @0x2802bc mov r2, r8 */
/* @0x2802c0 mov r1, r9 */
/* @0x2802c4 add r0, r0, r3 */
/* @0x2802c8 bl 0xb65bc <memcpy@plt> */
/* @0x2802cc ldr r3, [r4, #0x4] */
/* @0x2802d0 mov r1, #0 */
/* @0x2802d4 ldr r0, [r3, #0x4] */
/* @0x2802d8 ldr r2, [r3] */
/* @0x2802dc add r8, r8, r0 */
/* @0x2802e0 str r8, [r3, #0x4] */
/* @0x2802e4 strb r1, [r2, r8] */
/* @0x2802e8 ldmib r4, {r3, r7} */
/* @0x2802ec add r7, r7, r7, lsl #2 */
/* @0x2802f0 ldr r0, [r3] */
/* @0x2802f4 bl 0xb6640 <strdup@plt> */
/* @0x2802f8 add r3, r4, r7, lsl #2 */
/* @0x2802fc mov r1, #18 */
/* @0x280300 mov r2, #0 */
/* @0x280304 str r1, [r3, #0x28] */
/* @0x280308 str r2, [r3, #0x24] */
/* @0x28030c str r0, [r3, #0x34] */
/* @0x280310 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x280314 rsb r8, r5, r7 */
/* @0x280318 mov r5, r7 */
/* @0x28031c ldr r0, [r4, #0x4] */
/* @0x280320 ldr r3, [r0, #0x4] */
/* @0x280324 ldr r2, [r0, #0x8] */
/* @0x280328 rsb r2, r3, r2 */
/* @0x28032c cmp r2, r8 */
/* @0x280330 ble 0x280438 <json_tokener_parse_ex+0x13f0> */
/* @0x280334 ldr r0, [r0] */
/* @0x280338 mov r2, r8 */
/* @0x28033c mov r1, r9 */
/* @0x280340 add r0, r0, r3 */
/* @0x280344 bl 0xb65bc <memcpy@plt> */
/* @0x280348 ldr r3, [r4, #0x4] */
/* @0x28034c mov r1, #0 */
/* @0x280350 ldr r0, [r3, #0x4] */
/* @0x280354 ldr r2, [r3] */
/* @0x280358 add r8, r8, r0 */
/* @0x28035c str r8, [r3, #0x4] */
/* @0x280360 strb r1, [r2, r8] */
/* @0x280364 ldr r3, [r4, #0x8] */
/* @0x280368 mov r1, #8 */
/* @0x28036c add r3, r3, r3, lsl #2 */
/* @0x280370 mov r2, #9 */
/* @0x280374 add r3, r4, r3, lsl #2 */
/* @0x280378 str r1, [r3, #0x28] */
/* @0x28037c str r2, [r3, #0x24] */
/* @0x280380 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x280384 rsb r8, r5, r7 */
/* @0x280388 mov r5, r7 */
/* @0x28038c ldr r0, [r4, #0x4] */
/* @0x280390 ldr r3, [r0, #0x4] */
/* @0x280394 ldr r2, [r0, #0x8] */
/* @0x280398 rsb r2, r3, r2 */
/* @0x28039c cmp r2, r8 */
/* @0x2803a0 ble 0x280494 <json_tokener_parse_ex+0x144c> */
/* @0x2803a4 ldr r0, [r0] */
/* @0x2803a8 mov r2, r8 */
/* @0x2803ac mov r1, r9 */
/* @0x2803b0 add r0, r0, r3 */
/* @0x2803b4 bl 0xb65bc <memcpy@plt> */
/* @0x2803b8 ldr r3, [r4, #0x4] */
/* @0x2803bc mov r1, #0 */
/* @0x2803c0 ldr r0, [r3, #0x4] */
/* @0x2803c4 ldr r2, [r3] */
/* @0x2803c8 add r8, r8, r0 */
/* @0x2803cc str r8, [r3, #0x4] */
/* @0x2803d0 strb r1, [r2, r8] */
/* @0x2803d4 ldr r3, [r4, #0x8] */
/* @0x2803d8 mov r1, #17 */
/* @0x2803dc b 0x28036c <json_tokener_parse_ex+0x1324> */
/* @0x2803e0 ldr r3, [r4, #0x4] */
/* @0x2803e4 add r2, sp, #40 */
/* @0x2803e8 ldr r1, [sp, #0x18] */
/* @0x2803ec ldr r0, [r3] */
/* @0x2803f0 bl 0xb68f8 <sscanf@plt> */
/* @0x2803f4 cmp r0, #1 */
/* @0x2803f8 beq 0x280610 <json_tokener_parse_ex+0x15c8> */
/* @0x2803fc ldr r3, [r4, #0xc] */
/* @0x280400 cmp r3, #0 */
/* @0x280404 bne 0x27fca0 <json_tokener_parse_ex+0xc58> */
/* @0x280408 mov r3, #7 */
/* @0x28040c ldr r8, [sp, #0x24] */
/* @0x280410 str r3, [r4, #0x18] */
/* @0x280414 b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x280418 mov r1, r9 */
/* @0x28041c mov r2, r8 */
/* @0x280420 bl 0x280d20 <printbuf_memappend> */
/* @0x280424 b 0x2802e8 <json_tokener_parse_ex+0x12a0> */
/* @0x280428 mov r1, r9 */
/* @0x28042c mov r2, r8 */
/* @0x280430 bl 0x280d20 <printbuf_memappend> */
/* @0x280434 b 0x280260 <json_tokener_parse_ex+0x1218> */
/* @0x280438 mov r1, r9 */
/* @0x28043c mov r2, r8 */
/* @0x280440 bl 0x280d20 <printbuf_memappend> */
/* @0x280444 b 0x280364 <json_tokener_parse_ex+0x131c> */
/* @0x280448 cmp r8, #110 */
/* @0x28044c bne 0x27faec <json_tokener_parse_ex+0xaa4> */
/* @0x280450 ldr r0, [r4, #0x4] */
/* @0x280454 ldr r3, [r0, #0x4] */
/* @0x280458 ldr r2, [r0, #0x8] */
/* @0x28045c rsb r2, r3, r2 */
/* @0x280460 cmp r2, #1 */
/* @0x280464 ble 0x280670 <json_tokener_parse_ex+0x1628> */
/* @0x280468 ldr r2, [r0] */
/* @0x28046c mov r1, #10 */
/* @0x280470 strb r1, [r2, r3] */
/* @0x280474 mov r0, #0 */
/* @0x280478 ldr r3, [r4, #0x4] */
/* @0x28047c ldm r3, {r1, r2} */
/* @0x280480 add r2, r2, #1 */
/* @0x280484 str r2, [r3, #0x4] */
/* @0x280488 strb r0, [r1, r2] */
/* @0x28048c ldr r3, [r4, #0x8] */
/* @0x280490 b 0x27fee0 <json_tokener_parse_ex+0xe98> */
/* @0x280494 mov r1, r9 */
/* @0x280498 mov r2, r8 */
/* @0x28049c bl 0x280d20 <printbuf_memappend> */
/* @0x2804a0 b 0x2803d4 <json_tokener_parse_ex+0x138c> */
/* @0x2804a4 ldr r0, [r4, #0x4] */
/* @0x2804a8 ldr r3, [r0, #0x4] */
/* @0x2804ac ldr r2, [r0, #0x8] */
/* @0x2804b0 rsb r2, r3, r2 */
/* @0x2804b4 cmp r2, #1 */
/* @0x2804b8 ble 0x280630 <json_tokener_parse_ex+0x15e8> */
/* @0x2804bc ldr r2, [r0] */
/* @0x2804c0 mov r1, #8 */
/* @0x2804c4 b 0x280470 <json_tokener_parse_ex+0x1428> */
/* @0x2804c8 add r1, sp, #36 */
/* @0x2804cc mov r2, #1 */
/* @0x2804d0 bl 0x280d20 <printbuf_memappend> */
/* @0x2804d4 b 0x27fedc <json_tokener_parse_ex+0xe94> */
/* @0x2804d8 ldr r0, [r4, #0x4] */
/* @0x2804dc ldr r3, [r0, #0x4] */
/* @0x2804e0 ldr r2, [r0, #0x8] */
/* @0x2804e4 rsb r2, r3, r2 */
/* @0x2804e8 cmp r2, #1 */
/* @0x2804ec ble 0x2806ac <json_tokener_parse_ex+0x1664> */
/* @0x2804f0 ldr r2, [r0] */
/* @0x2804f4 mov r1, #13 */
/* @0x2804f8 b 0x280470 <json_tokener_parse_ex+0x1428> */
/* @0x2804fc ldr r0, [r4, #0x4] */
/* @0x280500 ldr r3, [r0, #0x4] */
/* @0x280504 ldr r2, [r0, #0x8] */
/* @0x280508 rsb r2, r3, r2 */
/* @0x28050c cmp r2, #1 */
/* @0x280510 ble 0x2806d4 <json_tokener_parse_ex+0x168c> */
/* @0x280514 ldr r2, [r0] */
/* @0x280518 mov r1, #9 */
/* @0x28051c b 0x280470 <json_tokener_parse_ex+0x1428> */
/* @0x280520 lsr r12, r2, #12 */
/* @0x280524 ubfx r1, r2, #0x6, #0x6 */
/* @0x280528 and r3, r2, #63 */
/* @0x28052c ldr r0, [r4, #0x4] */
/* @0x280530 mvn r12, r12, lsl #27 */
/* @0x280534 mvn r1, r1, lsl #25 */
/* @0x280538 mvn r3, r3, lsl #25 */
/* @0x28053c mvn r12, r12, lsr #27 */
/* @0x280540 mvn r3, r3, lsr #25 */
/* @0x280544 strb r12, [sp, #0x30] */
/* @0x280548 strb r3, [sp, #0x32] */
/* @0x28054c mvn r1, r1, lsr #25 */
/* @0x280550 strb r1, [sp, #0x31] */
/* @0x280554 ldr r3, [r0, #0x4] */
/* @0x280558 ldr r2, [r0, #0x8] */
/* @0x28055c rsb r2, r3, r2 */
/* @0x280560 cmp r2, #3 */
/* @0x280564 ble 0x280644 <json_tokener_parse_ex+0x15fc> */
/* @0x280568 add r2, sp, #56 */
/* @0x28056c ldr r1, [r0] */
/* @0x280570 mov r0, #0 */
/* @0x280574 ldrh lr, [r2, #-8]! */
/* @0x280578 add r12, r1, r3 */
/* @0x28057c ldrb r2, [r2, #0x2] */
/* @0x280580 strh lr, [r1, r3] */
/* @0x280584 strb r2, [r12, #0x2] */
/* @0x280588 ldr r3, [r4, #0x4] */
/* @0x28058c ldm r3, {r1, r2} */
/* @0x280590 add r2, r2, #3 */
/* @0x280594 str r2, [r3, #0x4] */
/* @0x280598 strb r0, [r1, r2] */
/* @0x28059c b 0x27fedc <json_tokener_parse_ex+0xe94> */
/* @0x2805a0 str r7, [r4, #0x10] */
/* @0x2805a4 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x2805a8 add r1, sp, #48 */
/* @0x2805ac mov r2, #2 */
/* @0x2805b0 bl 0x280d20 <printbuf_memappend> */
/* @0x2805b4 b 0x27fedc <json_tokener_parse_ex+0xe94> */
/* @0x2805b8 mov r8, #0 */
/* @0x2805bc b 0x280218 <json_tokener_parse_ex+0x11d0> */
/* @0x2805c0 mov r8, #0 */
/* @0x2805c4 b 0x28031c <json_tokener_parse_ex+0x12d4> */
/* @0x2805c8 mov r8, #0 */
/* @0x2805cc b 0x28038c <json_tokener_parse_ex+0x1344> */
/* @0x2805d0 mov r8, #0 */
/* @0x2805d4 b 0x2802a0 <json_tokener_parse_ex+0x1258> */
/* @0x2805d8 mov r3, #2 */
/* @0x2805dc ldr r8, [sp, #0x24] */
/* @0x2805e0 str r3, [r4, #0x18] */
/* @0x2805e4 b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x2805e8 mov r3, #10 */
/* @0x2805ec str r3, [r4, #0x18] */
/* @0x2805f0 b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x2805f4 mov r3, #2 */
/* @0x2805f8 str r3, [r4, #0x18] */
/* @0x2805fc b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x280600 mov r3, #5 */
/* @0x280604 ldr r8, [sp, #0x24] */
/* @0x280608 str r3, [r4, #0x18] */
/* @0x28060c b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x280610 ldrd r0, r1, [sp, #40] */
/* @0x280614 bl 0x319164 <__floatdidf> */
/* @0x280618 ldr r7, [r4, #0x8] */
/* @0x28061c bl 0x27ebb8 <json_object_new_double> */
/* @0x280620 add r7, r7, r7, lsl #2 */
/* @0x280624 add r3, r4, r7, lsl #2 */
/* @0x280628 str r0, [r3, #0x30] */
/* @0x28062c b 0x27fcd4 <json_tokener_parse_ex+0xc8c> */
/* @0x280630 ldr r1, [sp, #0x1c] */
/* @0x280634 mov r2, #1 */
/* @0x280638 bl 0x280d20 <printbuf_memappend> */
/* @0x28063c ldr r3, [r4, #0x8] */
/* @0x280640 b 0x27fee0 <json_tokener_parse_ex+0xe98> */
/* @0x280644 add r1, sp, #48 */
/* @0x280648 mov r2, #3 */
/* @0x28064c bl 0x280d20 <printbuf_memappend> */
/* @0x280650 b 0x27fedc <json_tokener_parse_ex+0xe94> */
/* @0x280654 add r1, sp, #48 */
/* @0x280658 mov r2, #1 */
/* @0x28065c bl 0x280d20 <printbuf_memappend> */
/* @0x280660 b 0x27fedc <json_tokener_parse_ex+0xe94> */
/* @0x280664 mov r3, #11 */
/* @0x280668 str r3, [r4, #0x18] */
/* @0x28066c b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x280670 ldr r1, [pc, #-0x5e8] */
/* @0x280674 mov r2, #1 */
/* @0x280678 add r1, pc, r1 */
/* @0x28067c bl 0x280d20 <printbuf_memappend> */
/* @0x280680 ldr r3, [r4, #0x8] */
/* @0x280684 b 0x27fee0 <json_tokener_parse_ex+0xe98> */
/* @0x280688 mov r3, #13 */
/* @0x28068c str r3, [r4, #0x18] */
/* @0x280690 b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x280694 mov r3, #9 */
/* @0x280698 str r3, [r4, #0x18] */
/* @0x28069c b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x2806a0 mov r3, #8 */
/* @0x2806a4 str r3, [r4, #0x18] */
/* @0x2806a8 b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x2806ac ldr r1, [pc, #-0x620] */
/* @0x2806b0 mov r2, #1 */
/* @0x2806b4 add r1, pc, r1 */
/* @0x2806b8 bl 0x280d20 <printbuf_memappend> */
/* @0x2806bc ldr r3, [r4, #0x8] */
/* @0x2806c0 b 0x27fee0 <json_tokener_parse_ex+0xe98> */
/* @0x2806c4 mov r3, #6 */
/* @0x2806c8 ldr r8, [sp, #0x24] */
/* @0x2806cc str r3, [r4, #0x18] */
/* @0x2806d0 b 0x27f0f8 <json_tokener_parse_ex+0xb0> */
/* @0x2806d4 ldr r1, [pc, #-0x644] */
/* @0x2806d8 mov r2, #1 */
/* @0x2806dc add r1, pc, r1 */
/* @0x2806e0 bl 0x280d20 <printbuf_memappend> */
/* @0x2806e4 b 0x27fedc <json_tokener_parse_ex+0xe94> */
/* @0x2806e8 cmp r0, #47 */
/* @0x2806ec bne 0x27f320 <json_tokener_parse_ex+0x2d8> */
/* @0x2806f0 ldr r0, [r4, #0x4] */
/* @0x2806f4 bl 0x280e9c <printbuf_reset> */
/* @0x2806f8 ldr r0, [r4, #0x4] */
/* @0x2806fc ldr r3, [r0, #0x4] */
/* @0x280700 ldr r2, [r0, #0x8] */
/* @0x280704 rsb r2, r3, r2 */
/* @0x280708 cmp r2, #1 */
/* @0x28070c ble 0x28074c <json_tokener_parse_ex+0x1704> */
/* @0x280710 ldr r2, [r0] */
/* @0x280714 mov r0, #0 */
/* @0x280718 ldrb r1, [sp, #0x24] */
/* @0x28071c strb r1, [r2, r3] */
/* @0x280720 ldr r3, [r4, #0x4] */
/* @0x280724 ldm r3, {r1, r2} */
/* @0x280728 add r2, r2, #1 */
/* @0x28072c str r2, [r3, #0x4] */
/* @0x280730 strb r0, [r1, r2] */
/* @0x280734 ldr r3, [r4, #0x8] */
/* @0x280738 mov r2, #4 */
/* @0x28073c add r3, r3, r3, lsl #2 */
/* @0x280740 add r3, r4, r3, lsl #2 */
/* @0x280744 str r2, [r3, #0x24] */
/* @0x280748 b 0x27f174 <json_tokener_parse_ex+0x12c> */
/* @0x28074c add r1, sp, #36 */
/* @0x280750 mov r2, #1 */
/* @0x280754 bl 0x280d20 <printbuf_memappend> */
/* @0x280758 b 0x280734 <json_tokener_parse_ex+0x16ec> */

/* ── FUNC 0x28075c · json_tokener_parse · size=60 · insn=15 */
/* @0x28075c push {r3, r4, r5, lr} */
/* @0x280760 mov r5, r0 */
/* @0x280764 bl 0x27eff0 <json_tokener_new> */
/* @0x280768 mov r1, r5 */
/* @0x28076c mvn r2, #0 */
/* @0x280770 mov r4, r0 */
/* @0x280774 bl 0x27f048 <json_tokener_parse_ex> */
/* @0x280778 ldr r3, [r4, #0x18] */
/* @0x28077c cmp r3, #0 */
/* @0x280780 mov r5, r0 */
/* @0x280784 rsbne r5, r3, #0 */
/* @0x280788 mov r0, r4 */
/* @0x28078c bl 0x27f020 <json_tokener_free> */
/* @0x280790 mov r0, r5 */
/* @0x280794 pop {r3, r4, r5, pc} */

/* ── FUNC 0x280798 · lh_ptr_hash · size=20 · insn=5 */
/* @0x280798 mov r3, #1 */
/* @0x28079c movt r3, #0x9e37 */
/* @0x2807a0 mul r0, r3, r0 */
/* @0x2807a4 lsr r0, r0, #4 */
/* @0x2807a8 bx lr */

/* ── FUNC 0x2807ac · lh_ptr_equal · size=16 · insn=4 */
/* @0x2807ac subs r3, r1, r0 */
/* @0x2807b0 rsbs r0, r3, #0 */
/* @0x2807b4 adcs r0, r0, r3 */
/* @0x2807b8 bx lr */

/* ── FUNC 0x2807bc · lh_char_hash · size=64 · insn=16 */
/* @0x2807bc ldrb r3, [r0] */
/* @0x2807c0 cmp r3, #0 */
/* @0x2807c4 beq 0x2807f4 <lh_char_hash+0x38> */
/* @0x2807c8 mov r2, r0 */
/* @0x2807cc mov r0, #0 */
/* @0x2807d0 add r1, r0, r0, lsl #7 */
/* @0x2807d4 mov r0, #1 */
/* @0x2807d8 add r1, r1, r3 */
/* @0x2807dc ldrb r3, [r2, #0x1]! */
/* @0x2807e0 movt r0, #0x9e37 */
/* @0x2807e4 cmp r3, #0 */
/* @0x2807e8 add r0, r1, r0 */
/* @0x2807ec bne 0x2807d0 <lh_char_hash+0x14> */
/* @0x2807f0 bx lr */
/* @0x2807f4 mov r0, r3 */
/* @0x2807f8 bx lr */

/* ── FUNC 0x2807fc · lh_char_equal · size=20 · insn=5 */
/* @0x2807fc push {r3, lr} */
/* @0x280800 bl 0xb6574 <strcmp@plt> */
/* @0x280804 rsbs r0, r0, #1 */
/* @0x280808 movlo r0, #0 */
/* @0x28080c pop {r3, pc} */

/* ── FUNC 0x280810 · lh_abort · size=36 · insn=9 */
/* @0x280810 push {r0, r1, r2, r3} */
/* @0x280814 str lr, [sp, #-0x4]! */
/* @0x280818 sub sp, sp, #12 */
/* @0x28081c add r1, sp, #20 */
/* @0x280820 ldr r0, [sp, #0x10] */
/* @0x280824 str r1, [sp, #0x4] */
/* @0x280828 bl 0xb6cf4 <vprintf@plt> */
/* @0x28082c mov r0, #1 */
/* @0x280830 bl 0xb6688 <exit@plt> */

/* ── FUNC 0x280834 · lh_table_new · size=184 · insn=46 */
/* @0x280834 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x280838 mov r5, r0 */
/* @0x28083c mov r9, r1 */
/* @0x280840 mov r0, #1 */
/* @0x280844 mov r1, #56 */
/* @0x280848 mov r8, r2 */
/* @0x28084c mov r7, r3 */
/* @0x280850 ldr r6, [sp, #0x20] */
/* @0x280854 bl 0xb6c34 <calloc@plt> */
/* @0x280858 subs r4, r0, #0 */
/* @0x28085c beq 0x2808c4 <lh_table_new+0x90> */
/* @0x280860 mov r3, #0 */
/* @0x280864 str r5, [r4] */
/* @0x280868 str r9, [r4, #0x1c] */
/* @0x28086c mov r0, r5 */
/* @0x280870 str r3, [r4, #0x4] */
/* @0x280874 mov r1, #16 */
/* @0x280878 bl 0xb6c34 <calloc@plt> */
/* @0x28087c cmp r0, #0 */
/* @0x280880 str r0, [r4, #0x28] */
/* @0x280884 beq 0x2808d4 <lh_table_new+0xa0> */
/* @0x280888 cmp r5, #0 */
/* @0x28088c str r8, [r4, #0x2c] */
/* @0x280890 str r7, [r4, #0x30] */
/* @0x280894 str r6, [r4, #0x34] */
/* @0x280898 ble 0x2808bc <lh_table_new+0x88> */
/* @0x28089c ldr r12, [r4, #0x28] */
/* @0x2808a0 lsl r1, r5, #4 */
/* @0x2808a4 mov r3, #0 */
/* @0x2808a8 mvn r2, #0 */
/* @0x2808ac str r2, [r12, r3] */
/* @0x2808b0 add r3, r3, #16 */
/* @0x2808b4 cmp r3, r1 */
/* @0x2808b8 bne 0x2808ac <lh_table_new+0x78> */
/* @0x2808bc mov r0, r4 */
/* @0x2808c0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2808c4 ldr r0, [pc, #0x18] */
/* @0x2808c8 add r0, pc, r0 */
/* @0x2808cc bl 0x280810 <lh_abort> */
/* @0x2808d0 b 0x280860 <lh_table_new+0x2c> */
/* @0x2808d4 ldr r0, [pc, #0xc] */
/* @0x2808d8 add r0, pc, r0 */
/* @0x2808dc bl 0x280810 <lh_abort> */
/* @0x2808e0 b 0x280888 <lh_table_new+0x54> */
/* @0x2808e4 andeq r6, sp, r8, ror #22 */
/* @0x2808e8 andeq r6, sp, r8, asr r11 */

/* ── FUNC 0x2808ec · lh_kchar_table_new · size=48 · insn=12 */
/* @0x2808ec str lr, [sp, #-0x4]! */
/* @0x2808f0 sub sp, sp, #12 */
/* @0x2808f4 ldr r3, [pc, #0x18] */
/* @0x2808f8 ldr r12, [pc, #0x18] */
/* @0x2808fc ldr r3, [pc, r3] */
/* @0x280900 ldr r12, [pc, r12] */
/* @0x280904 str r12, [sp] */
/* @0x280908 bl 0x280834 <lh_table_new> */
/* @0x28090c add sp, sp, #12 */
/* @0x280910 ldr pc, [sp], #4 */
/* @0x280914 mulseq r7, r4, pc */
/* @0x280918 mulseq r7, r4, pc */

/* ── FUNC 0x28091c · lh_kptr_table_new · size=48 · insn=12 */
/* @0x28091c str lr, [sp, #-0x4]! */
/* @0x280920 sub sp, sp, #12 */
/* @0x280924 ldr r3, [pc, #0x18] */
/* @0x280928 ldr r12, [pc, #0x18] */
/* @0x28092c ldr r3, [pc, r3] */
/* @0x280930 ldr r12, [pc, r12] */
/* @0x280934 str r12, [sp] */
/* @0x280938 bl 0x280834 <lh_table_new> */
/* @0x28093c add sp, sp, #12 */
/* @0x280940 ldr pc, [sp], #4 */
/* @0x280944 andseq r0, r7, r12, ror #30 */
/* @0x280948 andseq r0, r7, r12, ror #30 */

/* ── FUNC 0x28094c · lh_table_free · size=72 · insn=18 */
/* @0x28094c push {r3, r4, r5, lr} */
/* @0x280950 mov r5, r0 */
/* @0x280954 ldr r4, [r0, #0x20] */
/* @0x280958 cmp r4, #0 */
/* @0x28095c beq 0x280980 <lh_table_free+0x34> */
/* @0x280960 ldr r3, [r5, #0x2c] */
/* @0x280964 mov r0, r4 */
/* @0x280968 cmp r3, #0 */
/* @0x28096c beq 0x280974 <lh_table_free+0x28> */
/* @0x280970 blx r3 */
/* @0x280974 ldr r4, [r4, #0x8] */
/* @0x280978 cmp r4, #0 */
/* @0x28097c bne 0x280960 <lh_table_free+0x14> */
/* @0x280980 ldr r0, [r5, #0x28] */
/* @0x280984 bl 0xb655c <free@plt> */
/* @0x280988 mov r0, r5 */
/* @0x28098c pop {r3, r4, r5, lr} */
/* @0x280990 b 0xb655c <free@plt> */

/* ── FUNC 0x280994 · anon_280994 · size=0 · insn=1 */
/* @0x280994 andeq r0, r0, r0 */

/* ── FUNC 0x280998 · lh_table_insert · size=240 · insn=60 */
/* @0x280998 ldr r3, [r0] */
/* @0x28099c vldr d7, [pc, #220] */
/* @0x2809a0 push {r4, r5, r6, r7, r8, lr} */
/* @0x2809a4 mov r6, r2 */
/* @0x2809a8 vmov s11, r3 */
/* @0x2809ac ldr r2, [r0, #0x14] */
/* @0x2809b0 mov r4, r0 */
/* @0x2809b4 mov r7, r1 */
/* @0x2809b8 vcvt.f64.s32 d6, s11 */
/* @0x2809bc vldr s11, [r0, #4] */
/* @0x2809c0 add r2, r2, #1 */
/* @0x2809c4 str r2, [r0, #0x14] */
/* @0x2809c8 vmul.f64 d7, d6, d7 */
/* @0x2809cc vcvt.f64.s32 d6, s11 */
/* @0x2809d0 vcmpe.f64 d6, d7 */
/* @0x2809d4 vmrs APSR_nzcv, fpscr */
/* @0x2809d8 bgt 0x280a74 <lh_table_insert+0xdc> */
/* @0x2809dc ldr r3, [r4, #0x30] */
/* @0x2809e0 mov r0, r7 */
/* @0x2809e4 blx r3 */
/* @0x2809e8 ldr r8, [r4] */
/* @0x2809ec mov r1, r8 */
/* @0x2809f0 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x2809f4 ldr r12, [r4, #0x28] */
/* @0x2809f8 b 0x280a10 <lh_table_insert+0x78> */
/* @0x2809fc cmp r8, r1 */
/* @0x280a00 ldr r5, [r4, #0x8] */
/* @0x280a04 moveq r1, #0 */
/* @0x280a08 add r5, r5, #1 */
/* @0x280a0c str r5, [r4, #0x8] */
/* @0x280a10 ldr r5, [r12, r1, lsl #4] */
/* @0x280a14 add r2, r12, r1, lsl #4 */
/* @0x280a18 add r1, r1, #1 */
/* @0x280a1c add r5, r5, #2 */
/* @0x280a20 cmp r5, #1 */
/* @0x280a24 bhi 0x2809fc <lh_table_insert+0x64> */
/* @0x280a28 ldr r3, [r4, #0x20] */
/* @0x280a2c mov r0, #0 */
/* @0x280a30 ldr r1, [r4, #0x4] */
/* @0x280a34 cmp r3, #0 */
/* @0x280a38 str r7, [r2] */
/* @0x280a3c str r6, [r2, #0x4] */
/* @0x280a40 add r1, r1, #1 */
/* @0x280a44 ldrne r3, [r4, #0x24] */
/* @0x280a48 str r1, [r4, #0x4] */
/* @0x280a4c movne r1, #0 */
/* @0x280a50 streq r2, [r4, #0x24] */
/* @0x280a54 strne r2, [r3, #0x8] */
/* @0x280a58 streq r2, [r4, #0x20] */
/* @0x280a5c strne r3, [r2, #0xc] */
/* @0x280a60 strne r1, [r2, #0x8] */
/* @0x280a64 streq r3, [r2, #0xc] */
/* @0x280a68 streq r3, [r2, #0x8] */
/* @0x280a6c strne r2, [r4, #0x24] */
/* @0x280a70 pop {r4, r5, r6, r7, r8, pc} */
/* @0x280a74 lsl r1, r3, #1 */
/* @0x280a78 bl 0x280a88 <lh_table_resize> */
/* @0x280a7c b 0x2809dc <lh_table_insert+0x44> */
/* @0x280a80 mvnpl r8, pc, lsl r5 */
/* @0x280a84 svclo #0xe51eb8 */

/* ── FUNC 0x280a88 · lh_table_resize · size=148 · insn=37 */
/* @0x280a88 push {r4, r5, r6, r7, lr} */
/* @0x280a8c mov r6, r0 */
/* @0x280a90 ldr r12, [r6, #0x34] */
/* @0x280a94 sub sp, sp, #12 */
/* @0x280a98 mov r7, r1 */
/* @0x280a9c ldr r3, [r6, #0x30] */
/* @0x280aa0 ldr r1, [r0, #0x1c] */
/* @0x280aa4 mov r2, #0 */
/* @0x280aa8 mov r0, r7 */
/* @0x280aac str r12, [sp] */
/* @0x280ab0 bl 0x280834 <lh_table_new> */
/* @0x280ab4 ldr r4, [r6, #0x20] */
/* @0x280ab8 cmp r4, #0 */
/* @0x280abc mov r5, r0 */
/* @0x280ac0 beq 0x280adc <lh_table_resize+0x54> */
/* @0x280ac4 ldm r4, {r1, r2} */
/* @0x280ac8 mov r0, r5 */
/* @0x280acc bl 0x280998 <lh_table_insert> */
/* @0x280ad0 ldr r4, [r4, #0x8] */
/* @0x280ad4 cmp r4, #0 */
/* @0x280ad8 bne 0x280ac4 <lh_table_resize+0x3c> */
/* @0x280adc ldr r0, [r6, #0x28] */
/* @0x280ae0 bl 0xb655c <free@plt> */
/* @0x280ae4 ldr r12, [r5, #0x28] */
/* @0x280ae8 ldr r1, [r5, #0x20] */
/* @0x280aec mov r0, r5 */
/* @0x280af0 ldr r3, [r5, #0x24] */
/* @0x280af4 ldr r2, [r6, #0xc] */
/* @0x280af8 str r12, [r6, #0x28] */
/* @0x280afc add r2, r2, #1 */
/* @0x280b00 str r7, [r6] */
/* @0x280b04 str r1, [r6, #0x20] */
/* @0x280b08 str r2, [r6, #0xc] */
/* @0x280b0c str r3, [r6, #0x24] */
/* @0x280b10 add sp, sp, #12 */
/* @0x280b14 pop {r4, r5, r6, r7, lr} */
/* @0x280b18 b 0xb655c <free@plt> */
