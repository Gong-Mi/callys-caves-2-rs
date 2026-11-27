/* libyoyo.so 覆盖卡组 0161
 * 函数 0x1dca8c..0x1dfb88，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1dca8c · VARI_Load(unsigned char*, unsigned int, unsigned char*) · size=572 · insn=143 */
/* @0x1dca8c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1dca90 mov r3, #0 */
/* @0x1dca94 ldr r7, [pc, #0x1f4] */
/* @0x1dca98 mov r11, r0 */
/* @0x1dca9c ldr r12, [pc, #0x1f0] */
/* @0x1dcaa0 mov r6, r1 */
/* @0x1dcaa4 add r7, pc, r7 */
/* @0x1dcaa8 ldr r8, [pc, #0x1e8] */
/* @0x1dcaac ldr r4, [pc, #0x1e8] */
/* @0x1dcab0 mov r10, r2 */
/* @0x1dcab4 ldr r5, [r7, r12] */
/* @0x1dcab8 ldr r12, [pc, #0x1e0] */
/* @0x1dcabc str r3, [r5] */
/* @0x1dcac0 ldr r8, [r7, r8] */
/* @0x1dcac4 str r3, [r8] */
/* @0x1dcac8 ldr r4, [r7, r4] */
/* @0x1dcacc str r3, [r4] */
/* @0x1dcad0 ldr r3, [r7, r12] */
/* @0x1dcad4 ldrb r3, [r3] */
/* @0x1dcad8 cmp r3, #0 */
/* @0x1dcadc beq 0x1dcc80 <_Z9VARI_LoadPhjS_+0x1f4> */
/* @0x1dcae0 ldm r0, {r0, r1} */
/* @0x1dcae4 sub r6, r6, #12 */
/* @0x1dcae8 ldr r3, [r11, #0x8] */
/* @0x1dcaec add r11, r11, #12 */
/* @0x1dcaf0 cmp r1, #0 */
/* @0x1dcaf4 str r0, [r4] */
/* @0x1dcaf8 moveq r1, #2 */
/* @0x1dcafc mov r2, r3 */
/* @0x1dcb00 str r1, [r8] */
/* @0x1dcb04 str r3, [r5] */
/* @0x1dcb08 bl 0xd1d80 <_Z18Code_Variable_Initiii> */
/* @0x1dcb0c ldr r3, [pc, #0x190] */
/* @0x1dcb10 ldr r2, [r4] */
/* @0x1dcb14 ldr r1, [pc, #0x18c] */
/* @0x1dcb18 ldr r3, [r7, r3] */
/* @0x1dcb1c add r1, pc, r1 */
/* @0x1dcb20 ldr r4, [r3] */
/* @0x1dcb24 ldr r3, [r4] */
/* @0x1dcb28 mov r0, r4 */
/* @0x1dcb2c ldr r3, [r3, #0xc] */
/* @0x1dcb30 blx r3 */
/* @0x1dcb34 ldr r3, [r4] */
/* @0x1dcb38 ldr r1, [pc, #0x16c] */
/* @0x1dcb3c mov r0, r4 */
/* @0x1dcb40 ldr r2, [r8] */
/* @0x1dcb44 add r1, pc, r1 */
/* @0x1dcb48 ldr r3, [r3, #0xc] */
/* @0x1dcb4c blx r3 */
/* @0x1dcb50 ldr r3, [r4] */
/* @0x1dcb54 ldr r1, [pc, #0x154] */
/* @0x1dcb58 mov r0, r4 */
/* @0x1dcb5c ldr r2, [r5] */
/* @0x1dcb60 add r1, pc, r1 */
/* @0x1dcb64 ldr r3, [r3, #0xc] */
/* @0x1dcb68 blx r3 */
/* @0x1dcb6c ldr r0, [pc, #0x140] */
/* @0x1dcb70 movw r2, #0x9680 */
/* @0x1dcb74 mvn r1, #0 */
/* @0x1dcb78 add r0, pc, r0 */
/* @0x1dcb7c movt r2, #0x98 */
/* @0x1dcb80 bl 0xd2f20 <_Z22Code_Variable_Find_SetPKcii> */
/* @0x1dcb84 cmp r6, #0 */
/* @0x1dcb88 beq 0x1dcc28 <_Z9VARI_LoadPhjS_+0x19c> */
/* @0x1dcb8c ldr r8, [pc, #0x124] */
/* @0x1dcb90 ldr r9, [pc, #0x124] */
/* @0x1dcb94 add r8, pc, r8 */
/* @0x1dcb98 add r9, pc, r9 */
/* @0x1dcb9c ldr r0, [r11] */
/* @0x1dcba0 cmp r0, #0 */
/* @0x1dcba4 moveq r5, r0 */
/* @0x1dcba8 ldrne r3, [pc, #0x110] */
/* @0x1dcbac ldrne r3, [r7, r3] */
/* @0x1dcbb0 ldrne r5, [r3] */
/* @0x1dcbb4 addne r5, r5, r0 */
/* @0x1dcbb8 ldmib r11, {r1, r4} */
/* @0x1dcbbc cmn r4, #6 */
/* @0x1dcbc0 beq 0x1dcc30 <_Z9VARI_LoadPhjS_+0x1a4> */
/* @0x1dcbc4 mov r2, r4 */
/* @0x1dcbc8 mov r0, r5 */
/* @0x1dcbcc bl 0xd2f20 <_Z22Code_Variable_Find_SetPKcii> */
/* @0x1dcbd0 subs r4, r0, #0 */
/* @0x1dcbd4 blt 0x1dcc58 <_Z9VARI_LoadPhjS_+0x1cc> */
/* @0x1dcbd8 ldr r1, [r11, #0xc] */
/* @0x1dcbdc sub r6, r6, #20 */
/* @0x1dcbe0 ldr r3, [r11, #0x10] */
/* @0x1dcbe4 add r11, r11, #20 */
/* @0x1dcbe8 cmp r1, #0 */
/* @0x1dcbec bicgt r0, r4, #-268435456 */
/* @0x1dcbf0 movgt r12, #0 */
/* @0x1dcbf4 ble 0x1dcc20 <_Z9VARI_LoadPhjS_+0x194> */
/* @0x1dcbf8 add r4, r3, #4 */
/* @0x1dcbfc add r12, r12, #1 */
/* @0x1dcc00 cmp r12, r1 */
/* @0x1dcc04 ldr r5, [r10, r4] */
/* @0x1dcc08 and r2, r5, #-268435456 */
/* @0x1dcc0c sbfx r5, r5, #0x0, #0x1c */
/* @0x1dcc10 orr r2, r2, r0 */
/* @0x1dcc14 add r3, r3, r5 */
/* @0x1dcc18 str r2, [r10, r4] */
/* @0x1dcc1c bne 0x1dcbf8 <_Z9VARI_LoadPhjS_+0x16c> */
/* @0x1dcc20 cmp r6, #0 */
/* @0x1dcc24 bne 0x1dcb9c <_Z9VARI_LoadPhjS_+0x110> */
/* @0x1dcc28 mov r0, #1 */
/* @0x1dcc2c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1dcc30 mov r1, r8 */
/* @0x1dcc34 mov r0, r5 */
/* @0x1dcc38 bl 0xb6574 <strcmp@plt> */
/* @0x1dcc3c movw r3, #0x9680 */
/* @0x1dcc40 movt r3, #0x98 */
/* @0x1dcc44 cmp r0, #0 */
/* @0x1dcc48 moveq r4, r3 */
/* @0x1dcc4c mvnne r1, #5 */
/* @0x1dcc50 mvneq r1, #0 */
/* @0x1dcc54 b 0x1dcbc4 <_Z9VARI_LoadPhjS_+0x138> */
/* @0x1dcc58 mov r1, r5 */
/* @0x1dcc5c mov r0, r9 */
/* @0x1dcc60 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x1dcc64 ldr r3, [pc, #0x58] */
/* @0x1dcc68 ldr r3, [r7, r3] */
/* @0x1dcc6c ldrb r3, [r3] */
/* @0x1dcc70 cmp r3, #0 */
/* @0x1dcc74 beq 0x1dcc88 <_Z9VARI_LoadPhjS_+0x1fc> */
/* @0x1dcc78 bl 0x10c320 <_Z14YYGML_game_endv> */
/* @0x1dcc7c b 0x1dcbd8 <_Z9VARI_LoadPhjS_+0x14c> */
/* @0x1dcc80 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1dcc84 b 0x1dc960 <_Z13OLD_VARI_LoadPhjS_> */
/* @0x1dcc88 mov r0, #1 */
/* @0x1dcc8c bl 0xb6688 <exit@plt> */
/* @0x1dcc90 eoreq r5, r1, r12, lsr #3 */
/* @0x1dcc94 .word 0xffffc104 */
/* @0x1dcc98 .word 0xffffc0c4 */
/* @0x1dcc9c .word 0xffffc0b8 */
/* @0x1dcca0 .word 0xffffbf04 */
/* @0x1dcca4 .word 0xffffdecc */
/* @0x1dcca8 andseq r4, r7, r4, lsr #23 */
/* @0x1dccac mulseq r7, r8, r11 */
/* @0x1dccb0 mulseq r7, r8, r11 */
/* @0x1dccb4 mulseq r7, r8, r11 */
/* @0x1dccb8 andseq r4, r7, r12, ror r11 */
/* @0x1dccbc ldrsheq r4, [r7], -r12 */
/* @0x1dccc0 .word 0xffffbcf4 */
/* @0x1dccc4 .word 0xffffbfe0 */

/* ── FUNC 0x1dccc8 · OLD_FUNC_Load(unsigned char*, unsigned int, unsigned char*) · size=296 · insn=74 */
/* @0x1dccc8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1dcccc sub sp, sp, #1024 */
/* @0x1dccd0 ldr r8, [pc, #0x108] */
/* @0x1dccd4 sub sp, sp, #12 */
/* @0x1dccd8 ldr r9, [pc, #0x104] */
/* @0x1dccdc subs r10, r1, #0 */
/* @0x1dcce0 ldr r8, [pc, r8] */
/* @0x1dcce4 add r7, sp, #4 */
/* @0x1dcce8 add r9, pc, r9 */
/* @0x1dccec mov r5, r0 */
/* @0x1dccf0 ldr r3, [r8] */
/* @0x1dccf4 mov r4, r2 */
/* @0x1dccf8 str r3, [sp, #0x404] */
/* @0x1dccfc beq 0x1dcd78 <_Z13OLD_FUNC_LoadPhjS_+0xb0> */
/* @0x1dcd00 ldr r0, [r5] */
/* @0x1dcd04 cmp r0, #0 */
/* @0x1dcd08 moveq r11, r0 */
/* @0x1dcd0c ldrne r3, [pc, #0xd4] */
/* @0x1dcd10 ldrne r3, [pc, r3] */
/* @0x1dcd14 ldrne r11, [r3] */
/* @0x1dcd18 addne r11, r11, r0 */
/* @0x1dcd1c mov r0, r11 */
/* @0x1dcd20 mov r1, sp */
/* @0x1dcd24 bl 0xce158 <_Z18Code_Function_FindPKcPi> */
/* @0x1dcd28 ldr r3, [sp] */
/* @0x1dcd2c cmp r3, #0 */
/* @0x1dcd30 blt 0x1dcd98 <_Z13OLD_FUNC_LoadPhjS_+0xd0> */
/* @0x1dcd34 ldr r0, [r5, #0x4] */
/* @0x1dcd38 sub r10, r10, #12 */
/* @0x1dcd3c ldr r3, [r5, #0x8] */
/* @0x1dcd40 add r5, r5, #12 */
/* @0x1dcd44 cmp r0, #0 */
/* @0x1dcd48 ldrgt r11, [sp] */
/* @0x1dcd4c movgt r12, #0 */
/* @0x1dcd50 ble 0x1dcd70 <_Z13OLD_FUNC_LoadPhjS_+0xa8> */
/* @0x1dcd54 add r2, r3, #4 */
/* @0x1dcd58 add r12, r12, #1 */
/* @0x1dcd5c cmp r12, r0 */
/* @0x1dcd60 ldr r1, [r4, r2] */
/* @0x1dcd64 str r11, [r4, r2] */
/* @0x1dcd68 add r3, r3, r1 */
/* @0x1dcd6c bne 0x1dcd54 <_Z13OLD_FUNC_LoadPhjS_+0x8c> */
/* @0x1dcd70 cmp r10, #0 */
/* @0x1dcd74 bne 0x1dcd00 <_Z13OLD_FUNC_LoadPhjS_+0x38> */
/* @0x1dcd78 ldr r2, [sp, #0x404] */
/* @0x1dcd7c mov r0, #1 */
/* @0x1dcd80 ldr r3, [r8] */
/* @0x1dcd84 cmp r2, r3 */
/* @0x1dcd88 bne 0x1dcdd4 <_Z13OLD_FUNC_LoadPhjS_+0x10c> */
/* @0x1dcd8c add sp, sp, #1024 */
/* @0x1dcd90 add sp, sp, #12 */
/* @0x1dcd94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1dcd98 mov r3, r11 */
/* @0x1dcd9c mov r1, #1024 */
/* @0x1dcda0 mov r2, r9 */
/* @0x1dcda4 mov r0, r7 */
/* @0x1dcda8 bl 0xb65c8 <snprintf@plt> */
/* @0x1dcdac mov r0, r7 */
/* @0x1dcdb0 mov r1, #1 */
/* @0x1dcdb4 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1dcdb8 ldr r3, [pc, #0x2c] */
/* @0x1dcdbc ldr r3, [pc, r3] */
/* @0x1dcdc0 ldrb r3, [r3] */
/* @0x1dcdc4 cmp r3, #0 */
/* @0x1dcdc8 beq 0x1dcdd8 <_Z13OLD_FUNC_LoadPhjS_+0x110> */
/* @0x1dcdcc bl 0x10c320 <_Z14YYGML_game_endv> */
/* @0x1dcdd0 b 0x1dcd34 <_Z13OLD_FUNC_LoadPhjS_+0x6c> */
/* @0x1dcdd4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1dcdd8 mov r0, #1 */
/* @0x1dcddc bl 0xb6688 <exit@plt> */
/* @0x1dcde0 eoreq r0, r1, r0, ror r12 */
/* @0x1dcde4 andseq r4, r7, r4, lsr r10 */
/* @0x1dcde8 eoreq r0, r1, r4, lsr r12 */
/* @0x1dcdec eoreq r0, r1, r4, ror lr */

/* ── FUNC 0x1dcdf0 · FUNC_Load(unsigned char*, unsigned int, unsigned char*) · size=372 · insn=93 */
/* @0x1dcdf0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1dcdf4 sub sp, sp, #1040 */
/* @0x1dcdf8 ldr r8, [pc, #0x14c] */
/* @0x1dcdfc sub sp, sp, #4 */
/* @0x1dce00 ldr r12, [pc, #0x148] */
/* @0x1dce04 mov r5, r0 */
/* @0x1dce08 add r8, pc, r8 */
/* @0x1dce0c ldr r3, [pc, #0x140] */
/* @0x1dce10 mov r4, r2 */
/* @0x1dce14 ldr r12, [r8, r12] */
/* @0x1dce18 str r12, [sp] */
/* @0x1dce1c ldr r12, [r12] */
/* @0x1dce20 str r12, [sp, #0x40c] */
/* @0x1dce24 ldr r3, [r8, r3] */
/* @0x1dce28 ldrb r3, [r3] */
/* @0x1dce2c cmp r3, #0 */
/* @0x1dce30 beq 0x1dcf38 <_Z9FUNC_LoadPhjS_+0x148> */
/* @0x1dce34 ldr r6, [r5], #4 */
/* @0x1dce38 cmp r6, #0 */
/* @0x1dce3c ble 0x1dced0 <_Z9FUNC_LoadPhjS_+0xe0> */
/* @0x1dce40 ldr r1, [pc, #0x110] */
/* @0x1dce44 add r7, sp, #8 */
/* @0x1dce48 add r9, sp, #12 */
/* @0x1dce4c mov r11, #0 */
/* @0x1dce50 add r1, pc, r1 */
/* @0x1dce54 str r1, [sp, #0x4] */
/* @0x1dce58 ldr r0, [r5] */
/* @0x1dce5c cmp r0, #0 */
/* @0x1dce60 moveq r10, r0 */
/* @0x1dce64 ldrne r3, [pc, #0xf0] */
/* @0x1dce68 ldrne r3, [r8, r3] */
/* @0x1dce6c ldrne r3, [r3] */
/* @0x1dce70 addne r10, r3, r0 */
/* @0x1dce74 mov r0, r10 */
/* @0x1dce78 mov r1, r7 */
/* @0x1dce7c bl 0xce158 <_Z18Code_Function_FindPKcPi> */
/* @0x1dce80 ldr r2, [sp, #0x8] */
/* @0x1dce84 cmp r2, #0 */
/* @0x1dce88 blt 0x1dcefc <_Z9FUNC_LoadPhjS_+0x10c> */
/* @0x1dce8c ldr r12, [r5, #0x4] */
/* @0x1dce90 add r5, r5, #12 */
/* @0x1dce94 ldr r3, [r5, #-0x4] */
/* @0x1dce98 cmp r12, #0 */
/* @0x1dce9c ldrgt lr, [sp, #0x8] */
/* @0x1dcea0 movgt r2, #0 */
/* @0x1dcea4 ble 0x1dcec4 <_Z9FUNC_LoadPhjS_+0xd4> */
/* @0x1dcea8 add r1, r3, #4 */
/* @0x1dceac add r2, r2, #1 */
/* @0x1dceb0 cmp r2, r12 */
/* @0x1dceb4 ldr r0, [r4, r1] */
/* @0x1dceb8 str lr, [r4, r1] */
/* @0x1dcebc add r3, r3, r0 */
/* @0x1dcec0 bne 0x1dcea8 <_Z9FUNC_LoadPhjS_+0xb8> */
/* @0x1dcec4 add r11, r11, #1 */
/* @0x1dcec8 cmp r11, r6 */
/* @0x1dcecc bne 0x1dce58 <_Z9FUNC_LoadPhjS_+0x68> */
/* @0x1dced0 mov r0, r5 */
/* @0x1dced4 bl 0xd24d4 <_Z30Code_Variable_Read_Local_NamesPh> */
/* @0x1dced8 mov r0, #1 */
/* @0x1dcedc ldr r1, [sp] */
/* @0x1dcee0 ldr r2, [sp, #0x40c] */
/* @0x1dcee4 ldr r3, [r1] */
/* @0x1dcee8 cmp r2, r3 */
/* @0x1dceec bne 0x1dcf48 <_Z9FUNC_LoadPhjS_+0x158> */
/* @0x1dcef0 add sp, sp, #1040 */
/* @0x1dcef4 add sp, sp, #4 */
/* @0x1dcef8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1dcefc mov r3, r10 */
/* @0x1dcf00 mov r1, #1024 */
/* @0x1dcf04 ldr r2, [sp, #0x4] */
/* @0x1dcf08 mov r0, r9 */
/* @0x1dcf0c bl 0xb65c8 <snprintf@plt> */
/* @0x1dcf10 mov r0, r9 */
/* @0x1dcf14 mov r1, #1 */
/* @0x1dcf18 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1dcf1c ldr r3, [pc, #0x3c] */
/* @0x1dcf20 ldr r3, [r8, r3] */
/* @0x1dcf24 ldrb r3, [r3] */
/* @0x1dcf28 cmp r3, #0 */
/* @0x1dcf2c beq 0x1dcf40 <_Z9FUNC_LoadPhjS_+0x150> */
/* @0x1dcf30 bl 0x10c320 <_Z14YYGML_game_endv> */
/* @0x1dcf34 b 0x1dce8c <_Z9FUNC_LoadPhjS_+0x9c> */
/* @0x1dcf38 bl 0x1dccc8 <_Z13OLD_FUNC_LoadPhjS_> */
/* @0x1dcf3c b 0x1dcedc <_Z9FUNC_LoadPhjS_+0xec> */
/* @0x1dcf40 mov r0, #1 */
/* @0x1dcf44 bl 0xb6688 <exit@plt> */
/* @0x1dcf48 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1dcf4c eoreq r4, r1, r8, asr #28 */
/* @0x1dcf50 .word 0xffffbd00 */
/* @0x1dcf54 .word 0xffffbf04 */
/* @0x1dcf58 andseq r4, r7, r12, asr #17 */
/* @0x1dcf5c .word 0xffffbcf4 */
/* @0x1dcf60 .word 0xffffbfe0 */

/* ── FUNC 0x1dcf64 · GLOB_Load(unsigned char*, unsigned int, unsigned char*) · size=48 · insn=12 */
/* @0x1dcf64 mov r1, r0 */
/* @0x1dcf68 ldr r2, [pc, #0x1c] */
/* @0x1dcf6c ldr r3, [pc, #0x1c] */
/* @0x1dcf70 mov r0, #1 */
/* @0x1dcf74 ldr r12, [r1], #4 */
/* @0x1dcf78 ldr r2, [pc, r2] */
/* @0x1dcf7c ldr r3, [pc, r3] */
/* @0x1dcf80 str r1, [r2] */
/* @0x1dcf84 str r12, [r3] */
/* @0x1dcf88 bx lr */
/* @0x1dcf8c eoreq r3, r1, r12, lsr #26 */
/* @0x1dcf90 eoreq r3, r1, r12, lsr #26 */

/* ── FUNC 0x1dcf94 · Header_Load(unsigned char*, unsigned int, unsigned char*) · size=1240 · insn=310 */
/* @0x1dcf94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1dcf98 sub sp, sp, #52 */
/* @0x1dcf9c ldr r6, [pc, #0x47c] */
/* @0x1dcfa0 mov r7, r0 */
/* @0x1dcfa4 ldr r2, [pc, #0x478] */
/* @0x1dcfa8 add r6, pc, r6 */
/* @0x1dcfac ldr r3, [pc, #0x474] */
/* @0x1dcfb0 ldrb r4, [r0, #0x1] */
/* @0x1dcfb4 ldr r9, [r6, r2] */
/* @0x1dcfb8 ldr r1, [pc, #0x46c] */
/* @0x1dcfbc ldr r2, [r0, #0x14] */
/* @0x1dcfc0 str r0, [r9] */
/* @0x1dcfc4 ldr r8, [r6, r3] */
/* @0x1dcfc8 ldr r3, [pc, #0x460] */
/* @0x1dcfcc ldr lr, [r0, #0x18] */
/* @0x1dcfd0 str r4, [r8] */
/* @0x1dcfd4 ldr r1, [r6, r1] */
/* @0x1dcfd8 ldr r12, [r0, #0x1c] */
/* @0x1dcfdc str r1, [sp, #0x8] */
/* @0x1dcfe0 ldr r5, [sp, #0x8] */
/* @0x1dcfe4 ldr r1, [r0, #0x20] */
/* @0x1dcfe8 str r2, [r5] */
/* @0x1dcfec ldr r2, [r0, #0x24] */
/* @0x1dcff0 ldr r3, [r6, r3] */
/* @0x1dcff4 ldr r0, [r0, #0xc] */
/* @0x1dcff8 str lr, [r3] */
/* @0x1dcffc str r12, [r3, #0x4] */
/* @0x1dd000 str r1, [r3, #0x8] */
/* @0x1dd004 str r2, [r3, #0xc] */
/* @0x1dd008 bl 0x1b5e18 <_Z14Room_Set_maxidi> */
/* @0x1dd00c ldr r0, [r7, #0x10] */
/* @0x1dd010 bl 0x1b5e40 <_Z18Room_Set_maxtileidi> */
/* @0x1dd014 cmp r4, #7 */
/* @0x1dd018 ble 0x1dd064 <_Z11Header_LoadPhjS_+0xd0> */
/* @0x1dd01c ldr r3, [pc, #0x410] */
/* @0x1dd020 ldr r0, [r7, #0x3c] */
/* @0x1dd024 ldr r2, [pc, #0x40c] */
/* @0x1dd028 ldr r1, [r6, r3] */
/* @0x1dd02c ldr r12, [r7, #0x40] */
/* @0x1dd030 ldr r3, [pc, #0x404] */
/* @0x1dd034 str r0, [r1] */
/* @0x1dd038 ldr r0, [r6, r2] */
/* @0x1dd03c ldr r1, [pc, #0x3fc] */
/* @0x1dd040 ldr r2, [r7, #0x44] */
/* @0x1dd044 str r12, [r0] */
/* @0x1dd048 ldr r3, [r6, r3] */
/* @0x1dd04c str r2, [r3] */
/* @0x1dd050 ldr r1, [r6, r1] */
/* @0x1dd054 ldrb r1, [r1] */
/* @0x1dd058 cmp r1, #0 */
/* @0x1dd05c bicne r2, r2, #1 */
/* @0x1dd060 strne r2, [r3] */
/* @0x1dd064 ldr r4, [r9] */
/* @0x1dd068 ldr r2, [pc, #0x3d4] */
/* @0x1dd06c ldr r11, [pc, #0x3d4] */
/* @0x1dd070 mov r3, r4 */
/* @0x1dd074 ldr r10, [r4, #0x48] */
/* @0x1dd078 ldr r0, [r3, #0x4c]! */
/* @0x1dd07c ldr r12, [r6, r2] */
/* @0x1dd080 ldr lr, [pc, #0x3c4] */
/* @0x1dd084 ldr r1, [r3, #0x4] */
/* @0x1dd088 ldr r2, [r3, #0x8] */
/* @0x1dd08c ldr r3, [r3, #0xc] */
/* @0x1dd090 ldrd r4, r5, [r4, #92] */
/* @0x1dd094 stm r12!, {r0, r1, r2, r3} */
/* @0x1dd098 mov r0, r7 */
/* @0x1dd09c ldr r3, [r6, r11] */
/* @0x1dd0a0 ldr r1, [r8] */
/* @0x1dd0a4 str r10, [r3] */
/* @0x1dd0a8 ldr r7, [r6, lr] */
/* @0x1dd0ac strd r4, r5, [r7] */
/* @0x1dd0b0 bl 0x1b5ba0 <_Z14Room_LoadOrderP8YYHeaderi> */
/* @0x1dd0b4 ldr r2, [pc, #0x394] */
/* @0x1dd0b8 mov r1, #1 */
/* @0x1dd0bc ldr r3, [pc, #0x390] */
/* @0x1dd0c0 ldr r2, [r6, r2] */
/* @0x1dd0c4 strb r1, [r2] */
/* @0x1dd0c8 ldr r3, [r6, r3] */
/* @0x1dd0cc ldrb r3, [r3] */
/* @0x1dd0d0 cmp r3, #0 */
/* @0x1dd0d4 bne 0x1dd418 <_Z11Header_LoadPhjS_+0x484> */
/* @0x1dd0d8 ldr r12, [r8] */
/* @0x1dd0dc cmp r12, #13 */
/* @0x1dd0e0 ble 0x1dd3f8 <_Z11Header_LoadPhjS_+0x464> */
/* @0x1dd0e4 ldr r3, [pc, #0x36c] */
/* @0x1dd0e8 ldr r3, [r6, r3] */
/* @0x1dd0ec ldrb r3, [r3] */
/* @0x1dd0f0 cmp r3, #0 */
/* @0x1dd0f4 beq 0x1dd3f8 <_Z11Header_LoadPhjS_+0x464> */
/* @0x1dd0f8 ldrd r10, r11, [r7] */
/* @0x1dd0fc movw r8, #0x2493 */
/* @0x1dd100 movt r8, #0x9249 */
/* @0x1dd104 ldr r3, [r9] */
/* @0x1dd108 strd r10, r11, [sp, #32] */
/* @0x1dd10c add lr, r3, #132 */
/* @0x1dd110 ldr r11, [sp, #0x8] */
/* @0x1dd114 ldrh r2, [sp, #32] */
/* @0x1dd118 ldr r1, [r3, #0x3c] */
/* @0x1dd11c ldr r5, [r11] */
/* @0x1dd120 smull r11, r8, r8, r2 */
/* @0x1dd124 ldr r0, [r3, #0x40] */
/* @0x1dd128 rsb r7, r1, r5 */
/* @0x1dd12c ldr r4, [r3, #0x80] */
/* @0x1dd130 add r8, r8, r2 */
/* @0x1dd134 ldr r2, [r3, #0x44] */
/* @0x1dd138 str r5, [sp, #0xc] */
/* @0x1dd13c add r0, r2, r0 */
/* @0x1dd140 add r9, r7, r8, asr #2 */
/* @0x1dd144 add r9, r4, r9 */
/* @0x1dd148 add r1, r1, r2 */
/* @0x1dd14c asr r3, r0, #31 */
/* @0x1dd150 cmp r9, #0 */
/* @0x1dd154 rsblt r9, r9, #0 */
/* @0x1dd158 lsl r4, r4, #2 */
/* @0x1dd15c and r9, r9, #3 */
/* @0x1dd160 str r0, [sp, #0x14] */
/* @0x1dd164 add r8, r4, lr */
/* @0x1dd168 mov r7, #0 */
/* @0x1dd16c lsl r11, r3, #16 */
/* @0x1dd170 str r7, [sp, #0x28] */
/* @0x1dd174 lsl r3, r1, #16 */
/* @0x1dd178 str r7, [sp, #0x10] */
/* @0x1dd17c orr r11, r11, r0, lsr #16 */
/* @0x1dd180 str r3, [sp, #0x2c] */
/* @0x1dd184 add r10, r8, r9, lsl #3 */
/* @0x1dd188 ldrd r2, r3, [sp, #16] */
/* @0x1dd18c lsl r0, r0, #16 */
/* @0x1dd190 str r10, [sp, #0x18] */
/* @0x1dd194 str r11, [sp, #0x4] */
/* @0x1dd198 ldrd r10, r11, [sp, #40] */
/* @0x1dd19c str r7, [sp, #0x8] */
/* @0x1dd1a0 orr r11, r11, r3 */
/* @0x1dd1a4 ldr r3, [sp, #0x18] */
/* @0x1dd1a8 orr r10, r10, r2 */
/* @0x1dd1ac str r0, [sp] */
/* @0x1dd1b0 orr r10, r10, r1 */
/* @0x1dd1b4 orr r11, r11, r1, asr #31 */
/* @0x1dd1b8 ldrd r2, r3, [r3, #8] */
/* @0x1dd1bc ldrd r0, r1, [sp, #8] */
/* @0x1dd1c0 strd r2, r3, [sp, #40] */
/* @0x1dd1c4 orr r0, r0, r5 */
/* @0x1dd1c8 ldrd r2, r3, [sp] */
/* @0x1dd1cc orr r1, r1, r5, asr #31 */
/* @0x1dd1d0 eor r0, r0, r12 */
/* @0x1dd1d4 eor r1, r1, r12, asr #31 */
/* @0x1dd1d8 orr r2, r2, r10 */
/* @0x1dd1dc orr r3, r3, r11 */
/* @0x1dd1e0 eor r5, r1, r3 */
/* @0x1dd1e4 ldrd r10, r11, [r4, lr] */
/* @0x1dd1e8 eor r4, r0, r2 */
/* @0x1dd1ec ldrd r2, r3, [sp, #40] */
/* @0x1dd1f0 mov r0, #0 */
/* @0x1dd1f4 mov r1, #0 */
/* @0x1dd1f8 eor r5, r5, r3 */
/* @0x1dd1fc strd r0, r1, [sp, #16] */
/* @0x1dd200 ldrd r0, r1, [sp, #32] */
/* @0x1dd204 eor r4, r4, r2 */
/* @0x1dd208 mvn r5, r5 */
/* @0x1dd20c eor r5, r5, r11 */
/* @0x1dd210 mvn r4, r4 */
/* @0x1dd214 eor r4, r4, r10 */
/* @0x1dd218 mvn r0, r0 */
/* @0x1dd21c mvn r1, r1 */
/* @0x1dd220 strd r0, r1, [sp, #32] */
/* @0x1dd224 lsl r1, r5, #16 */
/* @0x1dd228 str r1, [sp, #0x14] */
/* @0x1dd22c lsl r3, r4, #16 */
/* @0x1dd230 ldr r2, [sp, #0x14] */
/* @0x1dd234 lsl r1, r5, #8 */
/* @0x1dd238 mov r10, #0 */
/* @0x1dd23c mov r11, #16711680 */
/* @0x1dd240 orr r2, r2, r4, lsr #16 */
/* @0x1dd244 str r2, [sp, #0x14] */
/* @0x1dd248 str r3, [sp, #0x10] */
/* @0x1dd24c orr r1, r1, r4, lsr #24 */
/* @0x1dd250 ldrd r2, r3, [sp, #16] */
/* @0x1dd254 lsl r0, r4, #8 */
/* @0x1dd258 lsl r7, r5, #24 */
/* @0x1dd25c and r10, r10, r2 */
/* @0x1dd260 and r11, r11, r3 */
/* @0x1dd264 strd r10, r11, [sp] */
/* @0x1dd268 mov r10, #0 */
/* @0x1dd26c ldrd r2, r3, [sp] */
/* @0x1dd270 and r0, r0, r10 */
/* @0x1dd274 mov r11, #-16777216 */
/* @0x1dd278 and r1, r1, r11 */
/* @0x1dd27c orr r2, r2, r0 */
/* @0x1dd280 orr r3, r3, r1 */
/* @0x1dd284 strd r2, r3, [sp] */
/* @0x1dd288 lsl r3, r4, #24 */
/* @0x1dd28c str r3, [sp, #0x18] */
/* @0x1dd290 orr r12, r7, r4, lsr #8 */
/* @0x1dd294 ldrd r2, r3, [sp] */
/* @0x1dd298 lsr r10, r5, #24 */
/* @0x1dd29c str r12, [sp, #0x1c] */
/* @0x1dd2a0 mov r11, #0 */
/* @0x1dd2a4 orr r2, r2, r10 */
/* @0x1dd2a8 orr r3, r3, r11 */
/* @0x1dd2ac strd r2, r3, [sp] */
/* @0x1dd2b0 mov r10, #0 */
/* @0x1dd2b4 ldrd r2, r3, [sp, #24] */
/* @0x1dd2b8 mov r11, #65280 */
/* @0x1dd2bc mov r0, #0 */
/* @0x1dd2c0 ldr r12, [pc, #0x194] */
/* @0x1dd2c4 and r10, r10, r2 */
/* @0x1dd2c8 and r11, r11, r3 */
/* @0x1dd2cc mov r2, #0 */
/* @0x1dd2d0 mov r3, #0 */
/* @0x1dd2d4 strd r2, r3, [sp, #24] */
/* @0x1dd2d8 mov r1, #0 */
/* @0x1dd2dc ldrd r2, r3, [sp] */
/* @0x1dd2e0 orr r10, r10, r2 */
/* @0x1dd2e4 orr r11, r11, r3 */
/* @0x1dd2e8 mov r2, #0 */
/* @0x1dd2ec lsr r3, r4, #8 */
/* @0x1dd2f0 and r2, r2, r0 */
/* @0x1dd2f4 str r3, [sp, #0x18] */
/* @0x1dd2f8 mov r3, #255 */
/* @0x1dd2fc and r3, r3, r4 */
/* @0x1dd300 orr r2, r2, r10 */
/* @0x1dd304 orr r3, r3, r11 */
/* @0x1dd308 ldr r7, [sp, #0x18] */
/* @0x1dd30c mov r0, #-16777216 */
/* @0x1dd310 ldrd r10, r11, [sp, #16] */
/* @0x1dd314 orr r7, r7, r5, lsl #24 */
/* @0x1dd318 str r7, [sp, #0x18] */
/* @0x1dd31c and r1, r1, r11 */
/* @0x1dd320 and r0, r0, r10 */
/* @0x1dd324 asr r11, r5, #8 */
/* @0x1dd328 str r11, [sp, #0x1c] */
/* @0x1dd32c orr r10, r2, r0 */
/* @0x1dd330 orr r11, r3, r1 */
/* @0x1dd334 ldr lr, [r6, r12] */
/* @0x1dd338 mov r0, #16711680 */
/* @0x1dd33c ldrd r2, r3, [sp, #24] */
/* @0x1dd340 mov r1, #0 */
/* @0x1dd344 strd r10, r11, [sp, #16] */
/* @0x1dd348 mov r10, r5 */
/* @0x1dd34c asr r11, r5, #31 */
/* @0x1dd350 ldrd r4, r5, [sp, #16] */
/* @0x1dd354 and r0, r0, r2 */
/* @0x1dd358 and r1, r1, r3 */
/* @0x1dd35c orr r0, r0, r4 */
/* @0x1dd360 orr r1, r1, r5 */
/* @0x1dd364 mov r2, #65280 */
/* @0x1dd368 mov r3, #0 */
/* @0x1dd36c and r2, r2, r10 */
/* @0x1dd370 and r3, r3, r11 */
/* @0x1dd374 orr r2, r2, r0 */
/* @0x1dd378 orr r3, r3, r1 */
/* @0x1dd37c ldrd r10, r11, [sp, #32] */
/* @0x1dd380 mov r12, #0 */
/* @0x1dd384 ldrd r0, r1, [sp, #40] */
/* @0x1dd388 mov r4, r8 */
/* @0x1dd38c strd r2, r3, [lr] */
/* @0x1dd390 cmp r12, r9 */
/* @0x1dd394 add r12, r12, #1 */
/* @0x1dd398 beq 0x1dd3ac <_Z11Header_LoadPhjS_+0x418> */
/* @0x1dd39c ldrd r2, r3, [r4, #8] */
/* @0x1dd3a0 cmp r3, r1 */
/* @0x1dd3a4 cmpeq r2, r0 */
/* @0x1dd3a8 strdeq r10, r11, [lr] */
/* @0x1dd3ac cmp r12, #4 */
/* @0x1dd3b0 add r4, r4, #8 */
/* @0x1dd3b4 bne 0x1dd390 <_Z11Header_LoadPhjS_+0x3fc> */
/* @0x1dd3b8 vldr s14, [r8, #40] */
/* @0x1dd3bc vcvt.f64.f32 d7, s14 */
/* @0x1dd3c0 ldr r1, [pc, #0x98] */
/* @0x1dd3c4 add r8, r8, #40 */
/* @0x1dd3c8 ldr r3, [pc, #0x94] */
/* @0x1dd3cc ldr r2, [pc, #0x94] */
/* @0x1dd3d0 ldr r1, [r6, r1] */
/* @0x1dd3d4 str r8, [r1] */
/* @0x1dd3d8 ldr r2, [r6, r2] */
/* @0x1dd3dc vstr d7, [r2] */
/* @0x1dd3e0 ldr r0, [r6, r3] */
/* @0x1dd3e4 vmov r2, r3, d7 */
/* @0x1dd3e8 bl 0x214800 <_ZN13CTimingSource12SetFrameRateEd> */
/* @0x1dd3ec mov r0, #1 */
/* @0x1dd3f0 add sp, sp, #52 */
/* @0x1dd3f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1dd3f8 ldr r1, [pc, #0x5c] */
/* @0x1dd3fc mov r2, #0 */
/* @0x1dd400 mov r3, #0 */
/* @0x1dd404 mov r0, #1 */
/* @0x1dd408 ldr r1, [r6, r1] */
/* @0x1dd40c strd r2, r3, [r1] */
/* @0x1dd410 add sp, sp, #52 */
/* @0x1dd414 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1dd418 bl 0x246fa8 <_Z21INITIALIZE_JavaScriptv> */
/* @0x1dd41c b 0x1dd0d8 <_Z11Header_LoadPhjS_+0x144> */
/* @0x1dd420 eoreq r4, r1, r8, lsr #25 */
/* @0x1dd424 .word 0xffffe79c */
/* @0x1dd428 .word 0xffffea88 */
/* @0x1dd42c .word 0xffffeec4 */
/* @0x1dd430 .word 0xffffeed4 */
/* @0x1dd434 .word 0xfffff05c */
/* @0x1dd438 .word 0xfffff060 */
/* @0x1dd43c .word 0xfffff064 */
/* @0x1dd440 .word 0xffffeb04 */
/* @0x1dd444 .word 0xffffef14 */
/* @0x1dd448 .word 0xfffff068 */
/* @0x1dd44c .word 0xffffef0c */
/* @0x1dd450 .word 0xfffff06c */
/* @0x1dd454 .word 0xffffbf68 */
/* @0x1dd458 .word 0xffffbcd4 */
/* @0x1dd45c .word 0xffffef08 */
/* @0x1dd460 .word 0xffffef04 */
/* @0x1dd464 .word 0xffffbcdc */
/* @0x1dd468 .word 0xffffebc4 */

/* ── FUNC 0x1dd46c · GetResolution(unsigned char*, int) · size=1468 · insn=367 */
/* @0x1dd46c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1dd470 mov r10, r1 */
/* @0x1dd474 ldr r4, [pc, #0x514] */
/* @0x1dd478 sub sp, sp, #52 */
/* @0x1dd47c ldr r3, [pc, #0x510] */
/* @0x1dd480 mov r6, r0 */
/* @0x1dd484 add r4, pc, r4 */
/* @0x1dd488 ldr r1, [pc, #0x508] */
/* @0x1dd48c ldr r0, [r0, #0x4] */
/* @0x1dd490 sub r12, r10, #8 */
/* @0x1dd494 ldr r3, [r4, r3] */
/* @0x1dd498 add r2, r6, r10 */
/* @0x1dd49c cmp r12, r0 */
/* @0x1dd4a0 str r6, [r3] */
/* @0x1dd4a4 str r3, [sp] */
/* @0x1dd4a8 ldr r3, [r4, r1] */
/* @0x1dd4ac str r2, [r3] */
/* @0x1dd4b0 beq 0x1dd4bc <_Z13GetResolutionPhi+0x50> */
/* @0x1dd4b4 add sp, sp, #52 */
/* @0x1dd4b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1dd4bc cmp r10, #8 */
/* @0x1dd4c0 bls 0x1dd4b4 <_Z13GetResolutionPhi+0x48> */
/* @0x1dd4c4 movw r11, #0x4f43 */
/* @0x1dd4c8 movw r3, #0x4156 */
/* @0x1dd4cc movt r11, #0x4544 */
/* @0x1dd4d0 movt r3, #0x4952 */
/* @0x1dd4d4 mov r8, #8 */
/* @0x1dd4d8 str r3, [sp, #0xc] */
/* @0x1dd4dc str r11, [sp, #0x4] */
/* @0x1dd4e0 movw r3, #0x4547 */
/* @0x1dd4e4 movt r3, #0x4c4e */
/* @0x1dd4e8 str r3, [sp, #0x10] */
/* @0x1dd4ec movw r3, #0x5453 */
/* @0x1dd4f0 movt r3, #0x4752 */
/* @0x1dd4f4 str r3, [sp, #0x14] */
/* @0x1dd4f8 movw r3, #0x4547 */
/* @0x1dd4fc movt r3, #0x374e */
/* @0x1dd500 str r3, [sp, #0x18] */
/* @0x1dd504 movw r3, #0x4547 */
/* @0x1dd508 movt r3, #0x384e */
/* @0x1dd50c str r3, [sp, #0x1c] */
/* @0x1dd510 b 0x1dd588 <_Z13GetResolutionPhi+0x11c> */
/* @0x1dd514 ldr r3, [sp, #0xc] */
/* @0x1dd518 cmp r2, r3 */
/* @0x1dd51c beq 0x1dd8ac <_Z13GetResolutionPhi+0x440> */
/* @0x1dd520 ldr r3, [sp, #0x10] */
/* @0x1dd524 cmp r2, r3 */
/* @0x1dd528 beq 0x1dd5c8 <_Z13GetResolutionPhi+0x15c> */
/* @0x1dd52c ldr r3, [sp, #0x14] */
/* @0x1dd530 cmp r2, r3 */
/* @0x1dd534 bne 0x1dd57c <_Z13GetResolutionPhi+0x110> */
/* @0x1dd538 ldr r3, [pc, #0x45c] */
/* @0x1dd53c add r8, r8, #12 */
/* @0x1dd540 ldr r1, [pc, #0x458] */
/* @0x1dd544 add r8, r6, r8 */
/* @0x1dd548 ldr r3, [r4, r3] */
/* @0x1dd54c add r1, pc, r1 */
/* @0x1dd550 ldr r0, [r3] */
/* @0x1dd554 ldr r3, [r0] */
/* @0x1dd558 ldr r3, [r3, #0xc] */
/* @0x1dd55c blx r3 */
/* @0x1dd560 ldr r1, [pc, #0x43c] */
/* @0x1dd564 ldr r2, [pc, #0x43c] */
/* @0x1dd568 ldr r3, [r6, r7] */
/* @0x1dd56c ldr r1, [r4, r1] */
/* @0x1dd570 str r8, [r1] */
/* @0x1dd574 ldr r2, [r4, r2] */
/* @0x1dd578 str r3, [r2] */
/* @0x1dd57c add r8, r5, r7 */
/* @0x1dd580 cmp r10, r8 */
/* @0x1dd584 bls 0x1dd4b4 <_Z13GetResolutionPhi+0x48> */
/* @0x1dd588 mov r3, r6 */
/* @0x1dd58c add r7, r8, #8 */
/* @0x1dd590 ldr r2, [r3, r8]! */
/* @0x1dd594 ldr r5, [r3, #0x4] */
/* @0x1dd598 cmp r5, #0 */
/* @0x1dd59c beq 0x1dd57c <_Z13GetResolutionPhi+0x110> */
/* @0x1dd5a0 ldr r3, [sp, #0x4] */
/* @0x1dd5a4 cmp r2, r3 */
/* @0x1dd5a8 beq 0x1dd868 <_Z13GetResolutionPhi+0x3fc> */
/* @0x1dd5ac bhi 0x1dd514 <_Z13GetResolutionPhi+0xa8> */
/* @0x1dd5b0 ldr r3, [sp, #0x18] */
/* @0x1dd5b4 cmp r2, r3 */
/* @0x1dd5b8 beq 0x1dd5c8 <_Z13GetResolutionPhi+0x15c> */
/* @0x1dd5bc ldr r3, [sp, #0x1c] */
/* @0x1dd5c0 cmp r2, r3 */
/* @0x1dd5c4 bne 0x1dd57c <_Z13GetResolutionPhi+0x110> */
/* @0x1dd5c8 ldr r3, [pc, #0x3cc] */
/* @0x1dd5cc add r8, r6, r7 */
/* @0x1dd5d0 ldr r1, [pc, #0x3d4] */
/* @0x1dd5d4 ldr r3, [r4, r3] */
/* @0x1dd5d8 add r1, pc, r1 */
/* @0x1dd5dc ldr r3, [r3] */
/* @0x1dd5e0 str r3, [sp, #0x8] */
/* @0x1dd5e4 ldr r3, [r3] */
/* @0x1dd5e8 ldr r0, [sp, #0x8] */
/* @0x1dd5ec ldr r3, [r3, #0xc] */
/* @0x1dd5f0 blx r3 */
/* @0x1dd5f4 ldr r2, [pc, #0x3b4] */
/* @0x1dd5f8 ldr r1, [pc, #0x3b4] */
/* @0x1dd5fc ldr r3, [r6, r7] */
/* @0x1dd600 ldr r0, [r4, r2] */
/* @0x1dd604 ldr r2, [pc, #0x3ac] */
/* @0x1dd608 ubfx r9, r3, #0x8, #0x8 */
/* @0x1dd60c uxtb r3, r3 */
/* @0x1dd610 str r8, [r0] */
/* @0x1dd614 ldr r0, [r8, #0x8] */
/* @0x1dd618 ldr r1, [r4, r1] */
/* @0x1dd61c cmp r0, #0 */
/* @0x1dd620 str r3, [r1] */
/* @0x1dd624 ldrne lr, [sp] */
/* @0x1dd628 ldr r2, [r4, r2] */
/* @0x1dd62c str r3, [r2] */
/* @0x1dd630 ldrne r3, [lr] */
/* @0x1dd634 addne r0, r3, r0 */
/* @0x1dd638 bl 0xb6640 <strdup@plt> */
/* @0x1dd63c ldr r3, [r8, #0x28] */
/* @0x1dd640 ldr r2, [pc, #0x374] */
/* @0x1dd644 cmp r3, #0 */
/* @0x1dd648 ldr r2, [r4, r2] */
/* @0x1dd64c ldrne r1, [sp] */
/* @0x1dd650 str r0, [r2] */
/* @0x1dd654 moveq r0, r3 */
/* @0x1dd658 ldrne r0, [r1] */
/* @0x1dd65c addne r0, r0, r3 */
/* @0x1dd660 bl 0xb6640 <strdup@plt> */
/* @0x1dd664 ldr r2, [pc, #0x354] */
/* @0x1dd668 ldr r3, [pc, #0x354] */
/* @0x1dd66c ldr r11, [r8, #0x44] */
/* @0x1dd670 ldr r2, [r4, r2] */
/* @0x1dd674 ldr r12, [r8, #0x14] */
/* @0x1dd678 and r1, r11, #1536 */
/* @0x1dd67c cmp r1, #1536 */
/* @0x1dd680 str r0, [r2] */
/* @0x1dd684 ldr r3, [r4, r3] */
/* @0x1dd688 str r12, [r3] */
/* @0x1dd68c beq 0x1dd934 <_Z13GetResolutionPhi+0x4c8> */
/* @0x1dd690 tst r11, #512 */
/* @0x1dd694 bne 0x1dd900 <_Z13GetResolutionPhi+0x494> */
/* @0x1dd698 tst r11, #1024 */
/* @0x1dd69c beq 0x1dd948 <_Z13GetResolutionPhi+0x4dc> */
/* @0x1dd6a0 ldr r3, [pc, #0x320] */
/* @0x1dd6a4 mov r2, #2 */
/* @0x1dd6a8 ldr r3, [r4, r3] */
/* @0x1dd6ac str r2, [r3] */
/* @0x1dd6b0 tst r11, #4096 */
/* @0x1dd6b4 ldrne r3, [pc, #0x310] */
/* @0x1dd6b8 movne r2, #1 */
/* @0x1dd6bc ldrne r3, [r4, r3] */
/* @0x1dd6c0 strbne r2, [r3] */
/* @0x1dd6c4 ldr r3, [pc, #0x304] */
/* @0x1dd6c8 ldr r3, [r4, r3] */
/* @0x1dd6cc ldrb r3, [r3] */
/* @0x1dd6d0 cmp r3, #0 */
/* @0x1dd6d4 ldrne r3, [pc, #0x2f0] */
/* @0x1dd6d8 movne r2, #1 */
/* @0x1dd6dc ldrne r3, [r4, r3] */
/* @0x1dd6e0 strbne r2, [r3] */
/* @0x1dd6e4 cmp r9, #9 */
/* @0x1dd6e8 ble 0x1dd914 <_Z13GetResolutionPhi+0x4a8> */
/* @0x1dd6ec ldr r3, [pc, #0x2d4] */
/* @0x1dd6f0 ldr r3, [r4, r3] */
/* @0x1dd6f4 ldr r3, [r3] */
/* @0x1dd6f8 sub r3, r3, #2 */
/* @0x1dd6fc cmp r3, #1 */
/* @0x1dd700 bls 0x1dd960 <_Z13GetResolutionPhi+0x4f4> */
/* @0x1dd704 cmp r9, #10 */
/* @0x1dd708 beq 0x1dd914 <_Z13GetResolutionPhi+0x4a8> */
/* @0x1dd70c ldr r3, [pc, #0x2c0] */
/* @0x1dd710 mov r2, #0 */
/* @0x1dd714 ldr r1, [r8, #0x6c] */
/* @0x1dd718 cmp r9, #11 */
/* @0x1dd71c str r1, [sp, #0x24] */
/* @0x1dd720 ldr r1, [r8, #0x68] */
/* @0x1dd724 ldr r0, [r4, r3] */
/* @0x1dd728 str r2, [sp, #0x20] */
/* @0x1dd72c ldrd r2, r3, [sp, #32] */
/* @0x1dd730 orr r2, r2, r1 */
/* @0x1dd734 orr r3, r3, r1, asr #31 */
/* @0x1dd738 strd r2, r3, [r0] */
/* @0x1dd73c beq 0x1dd914 <_Z13GetResolutionPhi+0x4a8> */
/* @0x1dd740 ldr r3, [pc, #0x290] */
/* @0x1dd744 mov r2, #0 */
/* @0x1dd748 ldr lr, [r8, #0x74] */
/* @0x1dd74c cmp r9, #12 */
/* @0x1dd750 ldr r1, [r8, #0x70] */
/* @0x1dd754 str lr, [sp, #0x2c] */
/* @0x1dd758 ldr r0, [r4, r3] */
/* @0x1dd75c str r2, [sp, #0x28] */
/* @0x1dd760 ldrd r2, r3, [sp, #40] */
/* @0x1dd764 orr r2, r2, r1 */
/* @0x1dd768 orr r3, r3, r1, asr #31 */
/* @0x1dd76c strd r2, r3, [r0] */
/* @0x1dd770 beq 0x1dd798 <_Z13GetResolutionPhi+0x32c> */
/* @0x1dd774 ldr r3, [pc, #0x260] */
/* @0x1dd778 cmp r9, #13 */
/* @0x1dd77c ldr r2, [r8, #0x78] */
/* @0x1dd780 ldr r3, [r4, r3] */
/* @0x1dd784 str r2, [r3] */
/* @0x1dd788 ldrne r3, [pc, #0x250] */
/* @0x1dd78c ldrne r2, [r8, #0x7c] */
/* @0x1dd790 ldrne r3, [r4, r3] */
/* @0x1dd794 strne r2, [r3] */
/* @0x1dd798 ldr r3, [pc, #0x244] */
/* @0x1dd79c ubfx r1, r11, #0xf, #0x1 */
/* @0x1dd7a0 ldr r2, [r8, #0x3c] */
/* @0x1dd7a4 ldr r0, [pc, #0x23c] */
/* @0x1dd7a8 ldr r12, [r4, r3] */
/* @0x1dd7ac ldr r3, [r8, #0x40] */
/* @0x1dd7b0 str r2, [r12] */
/* @0x1dd7b4 ldr r12, [pc, #0x230] */
/* @0x1dd7b8 ldr lr, [r4, r0] */
/* @0x1dd7bc ldr r0, [pc, #0x22c] */
/* @0x1dd7c0 str r3, [lr] */
/* @0x1dd7c4 ldr lr, [r4, r12] */
/* @0x1dd7c8 ldr r12, [pc, #0x224] */
/* @0x1dd7cc str r11, [lr] */
/* @0x1dd7d0 ldr r0, [r4, r0] */
/* @0x1dd7d4 str r2, [r0] */
/* @0x1dd7d8 ldr r2, [pc, #0x218] */
/* @0x1dd7dc ldr r0, [r4, r12] */
/* @0x1dd7e0 str r3, [r0] */
/* @0x1dd7e4 ldr r3, [pc, #0x210] */
/* @0x1dd7e8 ldr r2, [r4, r2] */
/* @0x1dd7ec strb r1, [r2] */
/* @0x1dd7f0 ldr r3, [r4, r3] */
/* @0x1dd7f4 ldrb r3, [r3] */
/* @0x1dd7f8 cmp r3, #0 */
/* @0x1dd7fc bicne r11, r11, #1 */
/* @0x1dd800 strne r11, [lr] */
/* @0x1dd804 ldr r1, [pc, #0x1f4] */
/* @0x1dd808 cmp r9, #14 */
/* @0x1dd80c ldr r0, [sp, #0x8] */
/* @0x1dd810 mov r3, #800 */
/* @0x1dd814 ldr r2, [pc, #0x1e8] */
/* @0x1dd818 movle r9, #0 */
/* @0x1dd81c ldr r12, [r4, r1] */
/* @0x1dd820 movgt r9, #1 */
/* @0x1dd824 ldr r1, [r0] */
/* @0x1dd828 strb r9, [r12] */
/* @0x1dd82c ldr r12, [r4, r2] */
/* @0x1dd830 ldr r2, [r1, #0xc] */
/* @0x1dd834 ldr r1, [pc, #0x1cc] */
/* @0x1dd838 str r3, [r12] */
/* @0x1dd83c add r1, pc, r1 */
/* @0x1dd840 blx r2 */
/* @0x1dd844 ldr r3, [pc, #0x1c0] */
/* @0x1dd848 ldr r2, [r8, #0x2c] */
/* @0x1dd84c ldr r3, [r4, r3] */
/* @0x1dd850 cmp r2, #1 */
/* @0x1dd854 movle r2, #0 */
/* @0x1dd858 movgt r2, #1 */
/* @0x1dd85c strb r2, [r3] */
/* @0x1dd860 bl 0x2a297c <_Z16InitGMLFunctionsv> */
/* @0x1dd864 b 0x1dd57c <_Z13GetResolutionPhi+0x110> */
/* @0x1dd868 ldr r3, [pc, #0x12c] */
/* @0x1dd86c ldr r1, [pc, #0x19c] */
/* @0x1dd870 ldr r3, [r4, r3] */
/* @0x1dd874 add r1, pc, r1 */
/* @0x1dd878 ldr r0, [r3] */
/* @0x1dd87c ldr r3, [r0] */
/* @0x1dd880 ldr r3, [r3, #0xc] */
/* @0x1dd884 blx r3 */
/* @0x1dd888 ldr r3, [pc, #0x184] */
/* @0x1dd88c add r0, r6, r7 */
/* @0x1dd890 mov r1, r5 */
/* @0x1dd894 mov r2, r6 */
/* @0x1dd898 mov r12, #1 */
/* @0x1dd89c ldr r3, [r4, r3] */
/* @0x1dd8a0 strb r12, [r3] */
/* @0x1dd8a4 bl 0x1dc800 <_Z9Code_LoadPhjS_> */
/* @0x1dd8a8 b 0x1dd57c <_Z13GetResolutionPhi+0x110> */
/* @0x1dd8ac ldr r3, [pc, #0xe8] */
/* @0x1dd8b0 add r8, r6, r7 */
/* @0x1dd8b4 ldr r1, [pc, #0x15c] */
/* @0x1dd8b8 ldr r3, [r4, r3] */
/* @0x1dd8bc add r1, pc, r1 */
/* @0x1dd8c0 ldr r0, [r3] */
/* @0x1dd8c4 ldr r3, [r0] */
/* @0x1dd8c8 ldr r3, [r3, #0xc] */
/* @0x1dd8cc blx r3 */
/* @0x1dd8d0 mov r1, r5 */
/* @0x1dd8d4 mov r2, r6 */
/* @0x1dd8d8 mov r0, r8 */
/* @0x1dd8dc bl 0x1dca8c <_Z9VARI_LoadPhjS_> */
/* @0x1dd8e0 ldr r1, [pc, #0x134] */
/* @0x1dd8e4 ldr r3, [pc, #0x134] */
/* @0x1dd8e8 lsr r2, r5, #2 */
/* @0x1dd8ec ldr r1, [r4, r1] */
/* @0x1dd8f0 str r8, [r1] */
/* @0x1dd8f4 ldr r3, [r4, r3] */
/* @0x1dd8f8 str r2, [r3] */
/* @0x1dd8fc b 0x1dd57c <_Z13GetResolutionPhi+0x110> */
/* @0x1dd900 ldr r3, [pc, #0xc0] */
/* @0x1dd904 mov r2, #1 */
/* @0x1dd908 ldr r3, [r4, r3] */
/* @0x1dd90c str r2, [r3] */
/* @0x1dd910 b 0x1dd6b0 <_Z13GetResolutionPhi+0x244> */
/* @0x1dd914 ldr r1, [pc, #0xbc] */
/* @0x1dd918 cmp r9, #7 */
/* @0x1dd91c mvn r2, #0 */
/* @0x1dd920 mvn r3, #0 */
/* @0x1dd924 ldr r1, [r4, r1] */
/* @0x1dd928 strd r2, r3, [r1] */
/* @0x1dd92c ble 0x1dd804 <_Z13GetResolutionPhi+0x398> */
/* @0x1dd930 b 0x1dd798 <_Z13GetResolutionPhi+0x32c> */
/* @0x1dd934 ldr r3, [pc, #0x8c] */
/* @0x1dd938 mov r2, #4 */
/* @0x1dd93c ldr r3, [r4, r3] */
/* @0x1dd940 str r2, [r3] */
/* @0x1dd944 b 0x1dd6b0 <_Z13GetResolutionPhi+0x244> */
/* @0x1dd948 tst r11, #2048 */
/* @0x1dd94c ldrne r3, [pc, #0x74] */
/* @0x1dd950 movne r2, #3 */
/* @0x1dd954 ldrne r3, [r4, r3] */
/* @0x1dd958 strne r2, [r3] */
/* @0x1dd95c b 0x1dd6b0 <_Z13GetResolutionPhi+0x244> */
/* @0x1dd960 ldr r3, [r8, #0x64] */
/* @0x1dd964 cmp r3, #0 */
/* @0x1dd968 beq 0x1dd704 <_Z13GetResolutionPhi+0x298> */
/* @0x1dd96c ldr lr, [sp] */
/* @0x1dd970 ldr r2, [lr] */
/* @0x1dd974 adds r0, r2, r3 */
/* @0x1dd978 beq 0x1dd704 <_Z13GetResolutionPhi+0x298> */
/* @0x1dd97c bl 0xb6640 <strdup@plt> */
/* @0x1dd980 ldr r3, [pc, #0x9c] */
/* @0x1dd984 ldr r3, [r4, r3] */
/* @0x1dd988 str r0, [r3] */
/* @0x1dd98c b 0x1dd704 <_Z13GetResolutionPhi+0x298> */
/* @0x1dd990 eoreq r4, r1, r12, asr #15 */
/* @0x1dd994 .word 0xffffbcf4 */
/* @0x1dd998 .word 0xffffebb8 */
/* @0x1dd99c .word 0xffffdecc */
/* @0x1dd9a0 andseq r4, r7, r8, asr #4 */
/* @0x1dd9a4 .word 0xffffc114 */
/* @0x1dd9a8 .word 0xfffff070 */
/* @0x1dd9ac andseq r4, r7, r0, ror r1 */
/* @0x1dd9b0 .word 0xffffe79c */
/* @0x1dd9b4 .word 0xfffff074 */
/* @0x1dd9b8 .word 0xffffc7d0 */
/* @0x1dd9bc .word 0xffffdf0c */
/* @0x1dd9c0 .word 0xffffef18 */
/* @0x1dd9c4 .word 0xffffeec4 */
/* @0x1dd9c8 .word 0xffffe6d0 */
/* @0x1dd9cc .word 0xffffc180 */
/* @0x1dd9d0 .word 0xffffbfe0 */
/* @0x1dd9d4 .word 0xfffff078 */
/* @0x1dd9d8 .word 0xfffff07c */
/* @0x1dd9dc .word 0xfffff080 */
/* @0x1dd9e0 .word 0xfffff084 */
/* @0x1dd9e4 .word 0xfffff05c */
/* @0x1dd9e8 .word 0xfffff060 */
/* @0x1dd9ec .word 0xfffff064 */
/* @0x1dd9f0 .word 0xffffdf38 */
/* @0x1dd9f4 .word 0xffffdf40 */
/* @0x1dd9f8 .word 0xffffbf68 */
/* @0x1dd9fc .word 0xffffeb04 */
/* @0x1dda00 .word 0xffffbf04 */
/* @0x1dda04 .word 0xffffd14c */
/* @0x1dda08 andseq r3, r7, r4, lsr #30 */
/* @0x1dda0c .word 0xffffbcd4 */
/* @0x1dda10 andseq r3, r7, r0, lsl #30 */
/* @0x1dda14 .word 0xffffbf10 */
/* @0x1dda18 andseq r3, r7, r8, asr #29 */
/* @0x1dda1c .word 0xfffff088 */
/* @0x1dda20 .word 0xfffff08c */
/* @0x1dda24 .word 0xffffce44 */

/* ── FUNC 0x1dda28 · Texture_Load(unsigned char*, unsigned int, unsigned char*) · size=580 · insn=145 */
/* @0x1dda28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1dda2c mov r5, r0 */
/* @0x1dda30 ldr r8, [r0] */
/* @0x1dda34 sub sp, sp, #12 */
/* @0x1dda38 mov r11, r1 */
/* @0x1dda3c ldr r7, [pc, #0x208] */
/* @0x1dda40 cmp r8, #532676608 */
/* @0x1dda44 lslls r0, r8, #2 */
/* @0x1dda48 add r7, pc, r7 */
/* @0x1dda4c mvnhi r0, #0 */
/* @0x1dda50 bl 0x27d14c <_Znaj> */
/* @0x1dda54 ldr r3, [pc, #0x1f4] */
/* @0x1dda58 cmp r8, #0 */
/* @0x1dda5c ldr r9, [r7, r3] */
/* @0x1dda60 str r0, [r9] */
/* @0x1dda64 ble 0x1ddba8 <_Z12Texture_LoadPhjS_+0x180> */
/* @0x1dda68 ldr r3, [pc, #0x1e4] */
/* @0x1dda6c mov r12, r0 */
/* @0x1dda70 mov r4, #0 */
/* @0x1dda74 mov r6, #1 */
/* @0x1dda78 ldr r3, [r7, r3] */
/* @0x1dda7c str r3, [sp, #0x4] */
/* @0x1dda80 b 0x1ddb3c <_Z12Texture_LoadPhjS_+0x114> */
/* @0x1dda84 ldr r2, [r5, #0x4] */
/* @0x1dda88 cmp r2, #0 */
/* @0x1dda8c ldrne r3, [pc, #0x1c4] */
/* @0x1dda90 ldrne r3, [r7, r3] */
/* @0x1dda94 ldrne r3, [r3] */
/* @0x1dda98 addne r2, r3, r2 */
/* @0x1dda9c ldr r0, [r2, #0x8] */
/* @0x1ddaa0 add r12, r12, r4 */
/* @0x1ddaa4 ldr r3, [r2] */
/* @0x1ddaa8 cmp r0, #0 */
/* @0x1ddaac ldr r10, [r2, #0x4] */
/* @0x1ddab0 and r3, r3, #1 */
/* @0x1ddab4 ldrne r2, [pc, #0x19c] */
/* @0x1ddab8 ldrne r2, [r7, r2] */
/* @0x1ddabc ldrne r2, [r2] */
/* @0x1ddac0 addne r0, r2, r0 */
/* @0x1ddac4 mov r1, r11 */
/* @0x1ddac8 mov r2, #0 */
/* @0x1ddacc str r12, [sp] */
/* @0x1ddad0 bl 0x173cdc <_Z17GR_Texture_CreatePhjbb> */
/* @0x1ddad4 ldr r12, [sp] */
/* @0x1ddad8 cmp r10, #0 */
/* @0x1ddadc str r0, [r12] */
/* @0x1ddae0 beq 0x1ddba0 <_Z12Texture_LoadPhjS_+0x178> */
/* @0x1ddae4 ldr r3, [pc, #0x170] */
/* @0x1ddae8 ldr r2, [r9] */
/* @0x1ddaec ldr r3, [r7, r3] */
/* @0x1ddaf0 ldr r2, [r2, r4] */
/* @0x1ddaf4 ldr r3, [r3, #0x4] */
/* @0x1ddaf8 ldr r3, [r3, r2, lsl #2] */
/* @0x1ddafc cmp r3, #0 */
/* @0x1ddb00 beq 0x1ddba0 <_Z12Texture_LoadPhjS_+0x178> */
/* @0x1ddb04 ldr r2, [r3] */
/* @0x1ddb08 cmp r2, #0 */
/* @0x1ddb0c beq 0x1ddba0 <_Z12Texture_LoadPhjS_+0x178> */
/* @0x1ddb10 ldr r1, [r2, #0x10] */
/* @0x1ddb14 mov r3, r6 */
/* @0x1ddb18 str r10, [r2, #0xc] */
/* @0x1ddb1c orr r1, r1, #16 */
/* @0x1ddb20 str r1, [r2, #0x10] */
/* @0x1ddb24 cmp r8, r3 */
/* @0x1ddb28 add r6, r6, #1 */
/* @0x1ddb2c add r4, r4, #4 */
/* @0x1ddb30 add r5, r5, #4 */
/* @0x1ddb34 ble 0x1ddba8 <_Z12Texture_LoadPhjS_+0x180> */
/* @0x1ddb38 ldr r12, [r9] */
/* @0x1ddb3c ldr r2, [sp, #0x4] */
/* @0x1ddb40 ldrb r3, [r2] */
/* @0x1ddb44 cmp r3, #0 */
/* @0x1ddb48 bne 0x1dda84 <_Z12Texture_LoadPhjS_+0x5c> */
/* @0x1ddb4c ldr r3, [r5, #0x4] */
/* @0x1ddb50 cmp r3, #0 */
/* @0x1ddb54 ldrne r2, [pc, #0xfc] */
/* @0x1ddb58 ldrne r2, [r7, r2] */
/* @0x1ddb5c ldrne r2, [r2] */
/* @0x1ddb60 addne r3, r2, r3 */
/* @0x1ddb64 ldr r0, [r3, #0x4] */
/* @0x1ddb68 add r10, r12, r4 */
/* @0x1ddb6c ldr r3, [r3] */
/* @0x1ddb70 cmp r0, #0 */
/* @0x1ddb74 and r3, r3, #1 */
/* @0x1ddb78 ldrne r2, [pc, #0xd8] */
/* @0x1ddb7c ldrne r2, [r7, r2] */
/* @0x1ddb80 ldrne r2, [r2] */
/* @0x1ddb84 addne r0, r2, r0 */
/* @0x1ddb88 mov r1, r11 */
/* @0x1ddb8c mov r2, #0 */
/* @0x1ddb90 bl 0x173cdc <_Z17GR_Texture_CreatePhjbb> */
/* @0x1ddb94 mov r3, r6 */
/* @0x1ddb98 str r0, [r10] */
/* @0x1ddb9c b 0x1ddb24 <_Z12Texture_LoadPhjS_+0xfc> */
/* @0x1ddba0 mov r3, r6 */
/* @0x1ddba4 b 0x1ddb24 <_Z12Texture_LoadPhjS_+0xfc> */
/* @0x1ddba8 ldr r3, [pc, #0xb0] */
/* @0x1ddbac mov r4, #0 */
/* @0x1ddbb0 ldr r6, [pc, #0xac] */
/* @0x1ddbb4 ldr r5, [r7, r3] */
/* @0x1ddbb8 add r6, pc, r6 */
/* @0x1ddbbc ldr r3, [r5] */
/* @0x1ddbc0 ldr r10, [r3] */
/* @0x1ddbc4 cmp r10, #0 */
/* @0x1ddbc8 bne 0x1ddbe8 <_Z12Texture_LoadPhjS_+0x1c0> */
/* @0x1ddbcc b 0x1ddc40 <_Z12Texture_LoadPhjS_+0x218> */
/* @0x1ddbd0 ldr r1, [r9] */
/* @0x1ddbd4 cmp r4, r10 */
/* @0x1ddbd8 ldr r3, [r1, r3, lsl #2] */
/* @0x1ddbdc strh r3, [r2, #20] */
/* @0x1ddbe0 beq 0x1ddc40 <_Z12Texture_LoadPhjS_+0x218> */
/* @0x1ddbe4 ldr r3, [r5] */
/* @0x1ddbe8 add r4, r4, #1 */
/* @0x1ddbec ldr r1, [pc, #0x64] */
/* @0x1ddbf0 ldr r0, [pc, #0x70] */
/* @0x1ddbf4 ldr r3, [r3, r4, lsl #2] */
/* @0x1ddbf8 cmp r3, #0 */
/* @0x1ddbfc mov r2, r3 */
/* @0x1ddc00 ldrne r2, [r7, r1] */
/* @0x1ddc04 mov r1, r6 */
/* @0x1ddc08 ldrne r2, [r2] */
/* @0x1ddc0c addne r2, r2, r3 */
/* @0x1ddc10 ldrsh r3, [r2, #20] */
/* @0x1ddc14 cmp r3, #0 */
/* @0x1ddc18 blt 0x1ddc24 <_Z12Texture_LoadPhjS_+0x1fc> */
/* @0x1ddc1c cmp r8, r3 */
/* @0x1ddc20 bgt 0x1ddbd0 <_Z12Texture_LoadPhjS_+0x1a8> */
/* @0x1ddc24 ldr r3, [r7, r0] */
/* @0x1ddc28 ldr r0, [r3] */
/* @0x1ddc2c ldr r3, [r0] */
/* @0x1ddc30 ldr r3, [r3, #0xc] */
/* @0x1ddc34 blx r3 */
/* @0x1ddc38 cmp r4, r10 */
/* @0x1ddc3c bne 0x1ddbe4 <_Z12Texture_LoadPhjS_+0x1bc> */
/* @0x1ddc40 mov r0, #1 */
/* @0x1ddc44 add sp, sp, #12 */
/* @0x1ddc48 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ddc4c eoreq r4, r1, r8, lsl #4 */
/* @0x1ddc50 .word 0xfffff090 */
/* @0x1ddc54 .word 0xffffbcd4 */
/* @0x1ddc58 .word 0xffffbcf4 */
/* @0x1ddc5c .word 0xffffbccc */
/* @0x1ddc60 .word 0xfffff094 */
/* @0x1ddc64 andseq r3, r7, r8, ror #23 */
/* @0x1ddc68 .word 0xffffbac4 */

/* ── FUNC 0x1ddc6c · YYPATCH(void*, void*) · size=20 · insn=5 */
/* @0x1ddc6c ldr r3, [r0] */
/* @0x1ddc70 cmp r3, #0 */
/* @0x1ddc74 addne r3, r1, r3 */
/* @0x1ddc78 str r3, [r0] */
/* @0x1ddc7c bx lr */

/* ── FUNC 0x1ddc80 · PatchArray(unsigned char*, unsigned char*) · size=84 · insn=21 */
/* @0x1ddc80 push {r3, r4, r5, r6, r7, lr} */
/* @0x1ddc84 mov r7, r1 */
/* @0x1ddc88 ldr r6, [r0] */
/* @0x1ddc8c cmp r6, #0 */
/* @0x1ddc90 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1ddc94 add r5, r0, #4 */
/* @0x1ddc98 mov r4, #0 */
/* @0x1ddc9c b 0x1ddca8 <_Z10PatchArrayPhS_+0x28> */
/* @0x1ddca0 cmp r4, r6 */
/* @0x1ddca4 beq 0x1ddcd0 <_Z10PatchArrayPhS_+0x50> */
/* @0x1ddca8 ldr r3, [r5] */
/* @0x1ddcac mov r0, r5 */
/* @0x1ddcb0 add r4, r4, #1 */
/* @0x1ddcb4 add r5, r5, #4 */
/* @0x1ddcb8 cmp r3, #0 */
/* @0x1ddcbc beq 0x1ddca0 <_Z10PatchArrayPhS_+0x20> */
/* @0x1ddcc0 mov r1, r7 */
/* @0x1ddcc4 bl 0x1ddc6c <_Z7YYPATCHPvS_> */
/* @0x1ddcc8 cmp r4, r6 */
/* @0x1ddccc bne 0x1ddca8 <_Z10PatchArrayPhS_+0x28> */
/* @0x1ddcd0 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x1ddcd4 · YYPATCH2(void*, void*) · size=16 · insn=4 */
/* @0x1ddcd4 ldr r0, [r0] */
/* @0x1ddcd8 cmp r0, #0 */
/* @0x1ddcdc addne r0, r0, r1 */
/* @0x1ddce0 bx lr */

/* ── FUNC 0x1ddce4 · LoadGameData(void*, unsigned int) · size=2668 · insn=667 */
/* @0x1ddce4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ddce8 sub sp, sp, #68 */
/* @0x1ddcec ldr r7, [pc, #0xa08] */
/* @0x1ddcf0 ldr r3, [pc, #0xa08] */
/* @0x1ddcf4 add r7, pc, r7 */
/* @0x1ddcf8 str r0, [sp, #0xc] */
/* @0x1ddcfc str r1, [sp, #0x18] */
/* @0x1ddd00 ldr r3, [r7, r3] */
/* @0x1ddd04 ldr r1, [pc, #0x9f8] */
/* @0x1ddd08 ldr r3, [r3] */
/* @0x1ddd0c add r1, pc, r1 */
/* @0x1ddd10 str r3, [sp, #0x14] */
/* @0x1ddd14 ldr r3, [r3] */
/* @0x1ddd18 ldr r0, [sp, #0x14] */
/* @0x1ddd1c ldr r3, [r3, #0xc] */
/* @0x1ddd20 blx r3 */
/* @0x1ddd24 bl 0x21f2e4 <_Z10Sound_Initv> */
/* @0x1ddd28 bl 0x1eebbc <_Z11Sprite_Initv> */
/* @0x1ddd2c bl 0xc329c <_Z15Background_Initv> */
/* @0x1ddd30 bl 0x1a7ca8 <_Z9Path_Initv> */
/* @0x1ddd34 bl 0x1dff7c <_Z11Script_Initv> */
/* @0x1ddd38 bl 0xf9fb4 <_Z9Font_Initv> */
/* @0x1ddd3c bl 0x1f25b4 <_Z13TimeLine_Initv> */
/* @0x1ddd40 bl 0x19e908 <_Z11Object_Initv> */
/* @0x1ddd44 bl 0x1b4bc4 <_Z9Room_Initv> */
/* @0x1ddd48 bl 0x19f2d0 <_Z11Option_Initv> */
/* @0x1ddd4c ldr r3, [pc, #0x9b4] */
/* @0x1ddd50 ldr r3, [r7, r3] */
/* @0x1ddd54 ldrb r3, [r3] */
/* @0x1ddd58 cmp r3, #0 */
/* @0x1ddd5c bne 0x1de0b4 <_Z12LoadGameDataPvj+0x3d0> */
/* @0x1ddd60 ldr r3, [pc, #0x9a4] */
/* @0x1ddd64 ldr r3, [r7, r3] */
/* @0x1ddd68 str r3, [sp, #0x10] */
/* @0x1ddd6c ldr r3, [r3] */
/* @0x1ddd70 cmp r3, #0 */
/* @0x1ddd74 beq 0x1de488 <_Z12LoadGameDataPvj+0x7a4> */
/* @0x1ddd78 ldr r2, [pc, #0x990] */
/* @0x1ddd7c ldr r3, [pc, #0x990] */
/* @0x1ddd80 ldr r2, [r7, r2] */
/* @0x1ddd84 str r2, [sp, #0x8] */
/* @0x1ddd88 ldr r9, [r7, r3] */
/* @0x1ddd8c ldr r3, [r2] */
/* @0x1ddd90 cmp r3, #0 */
/* @0x1ddd94 ldr r0, [r9] */
/* @0x1ddd98 beq 0x1de4c0 <_Z12LoadGameDataPvj+0x7dc> */
/* @0x1ddd9c ldr r3, [r3, #0xc] */
/* @0x1ddda0 cmp r3, #0 */
/* @0x1ddda4 ble 0x1de2f8 <_Z12LoadGameDataPvj+0x614> */
/* @0x1ddda8 ldr r2, [pc, #0x968] */
/* @0x1dddac mov r1, r3 */
/* @0x1dddb0 ldr r8, [r7, r2] */
/* @0x1dddb4 str r3, [r8] */
/* @0x1dddb8 mov r2, #0 */
/* @0x1dddbc bl 0xd1d80 <_Z18Code_Variable_Initiii> */
/* @0x1dddc0 ldr r12, [sp, #0x8] */
/* @0x1dddc4 ldr r2, [r8] */
/* @0x1dddc8 ldr r3, [r12] */
/* @0x1dddcc cmp r2, #0 */
/* @0x1dddd0 ldr r5, [r3, #0x14] */
/* @0x1dddd4 ble 0x1dde10 <_Z12LoadGameDataPvj+0x12c> */
/* @0x1dddd8 sub r5, r5, #4 */
/* @0x1ddddc mov r4, #0 */
/* @0x1ddde0 ldr r3, [r5, #0x4]! */
/* @0x1ddde4 mov r2, r4 */
/* @0x1ddde8 mvn r1, #0 */
/* @0x1dddec add r4, r4, #1 */
/* @0x1dddf0 ldr r0, [r3] */
/* @0x1dddf4 bl 0xd2f20 <_Z22Code_Variable_Find_SetPKcii> */
/* @0x1dddf8 ldr r3, [r8] */
/* @0x1dddfc cmp r3, r4 */
/* @0x1dde00 bgt 0x1ddde0 <_Z12LoadGameDataPvj+0xfc> */
/* @0x1dde04 ldr r12, [sp, #0x8] */
/* @0x1dde08 ldr r3, [r12] */
/* @0x1dde0c ldr r5, [r3, #0x14] */
/* @0x1dde10 ldr r3, [r9] */
/* @0x1dde14 cmp r3, #0 */
/* @0x1dde18 ble 0x1ddecc <_Z12LoadGameDataPvj+0x1e8> */
/* @0x1dde1c ldr r3, [pc, #0x8f8] */
/* @0x1dde20 sub r6, r5, #4 */
/* @0x1dde24 ldr r12, [pc, #0x8f4] */
/* @0x1dde28 mov r5, #0 */
/* @0x1dde2c add r12, pc, r12 */
/* @0x1dde30 str r12, [sp, #0x1c] */
/* @0x1dde34 ldr r4, [r7, r3] */
/* @0x1dde38 ldr r3, [r6, #0x4]! */
/* @0x1dde3c ldr r0, [r3] */
/* @0x1dde40 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1dde44 ldm r4, {r11, lr} */
/* @0x1dde48 cmp lr, #0 */
/* @0x1dde4c mov r10, r0 */
/* @0x1dde50 ldrle r0, [r4, #0xc] */
/* @0x1dde54 ble 0x1de060 <_Z12LoadGameDataPvj+0x37c> */
/* @0x1dde58 cmp r11, #0 */
/* @0x1dde5c ldrle r1, [r4, #0xc] */
/* @0x1dde60 ble 0x1ddeac <_Z12LoadGameDataPvj+0x1c8> */
/* @0x1dde64 ldr r0, [r4, #0xc] */
/* @0x1dde68 ldr r3, [r0] */
/* @0x1dde6c cmp r3, #0 */
/* @0x1dde70 addne r2, r0, #4 */
/* @0x1dde74 movne r3, #0 */
/* @0x1dde78 bne 0x1dde8c <_Z12LoadGameDataPvj+0x1a8> */
/* @0x1dde7c b 0x1de6f4 <_Z12LoadGameDataPvj+0xa10> */
/* @0x1dde80 ldr r12, [r1] */
/* @0x1dde84 cmp r12, #0 */
/* @0x1dde88 beq 0x1ddeac <_Z12LoadGameDataPvj+0x1c8> */
/* @0x1dde8c add r3, r3, #1 */
/* @0x1dde90 mov r1, r2 */
/* @0x1dde94 cmp r3, lr */
/* @0x1dde98 add r2, r2, #4 */
/* @0x1dde9c beq 0x1de060 <_Z12LoadGameDataPvj+0x37c> */
/* @0x1ddea0 cmp r3, r11 */
/* @0x1ddea4 bne 0x1dde80 <_Z12LoadGameDataPvj+0x19c> */
/* @0x1ddea8 add r1, r0, r3, lsl #2 */
/* @0x1ddeac str r10, [r1] */
/* @0x1ddeb0 ldr r3, [r9] */
/* @0x1ddeb4 add r5, r5, #1 */
/* @0x1ddeb8 cmp r3, r5 */
/* @0x1ddebc bgt 0x1dde38 <_Z12LoadGameDataPvj+0x154> */
/* @0x1ddec0 ldr r12, [sp, #0x8] */
/* @0x1ddec4 ldr r3, [r12] */
/* @0x1ddec8 ldr r5, [r3, #0x14] */
/* @0x1ddecc cmp r5, #0 */
/* @0x1dded0 beq 0x1ddf1c <_Z12LoadGameDataPvj+0x238> */
/* @0x1dded4 ldr r4, [r5] */
/* @0x1dded8 cmp r4, #0 */
/* @0x1ddedc beq 0x1ddf1c <_Z12LoadGameDataPvj+0x238> */
/* @0x1ddee0 add r5, r5, #4 */
/* @0x1ddee4 b 0x1ddefc <_Z12LoadGameDataPvj+0x218> */
/* @0x1ddee8 cmp r5, #0 */
/* @0x1ddeec beq 0x1ddf1c <_Z12LoadGameDataPvj+0x238> */
/* @0x1ddef0 ldr r4, [r5], #4 */
/* @0x1ddef4 cmp r4, #0 */
/* @0x1ddef8 beq 0x1ddf1c <_Z12LoadGameDataPvj+0x238> */
/* @0x1ddefc ldr r3, [r4, #0x4] */
/* @0x1ddf00 cmn r3, #1 */
/* @0x1ddf04 bne 0x1ddee8 <_Z12LoadGameDataPvj+0x204> */
/* @0x1ddf08 ldr r0, [r4] */
/* @0x1ddf0c bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc> */
/* @0x1ddf10 cmp r5, #0 */
/* @0x1ddf14 str r0, [r4, #0x4] */
/* @0x1ddf18 bne 0x1ddef0 <_Z12LoadGameDataPvj+0x20c> */
/* @0x1ddf1c ldr r0, [r9] */
/* @0x1ddf20 ldr r3, [pc, #0x7fc] */
/* @0x1ddf24 mov r5, #0 */
/* @0x1ddf28 ldr lr, [r8] */
/* @0x1ddf2c mov r12, #1 */
/* @0x1ddf30 mov r2, r5 */
/* @0x1ddf34 mvn r1, #-16777216 */
/* @0x1ddf38 ldr r3, [r7, r3] */
/* @0x1ddf3c cmp r0, lr */
/* @0x1ddf40 movlt r0, lr */
/* @0x1ddf44 mov r4, #3 */
/* @0x1ddf48 mov lr, #2 */
/* @0x1ddf4c str r12, [r3, #0x68] */
/* @0x1ddf50 str lr, [r3, #0xc0] */
/* @0x1ddf54 str r5, [r3, #0x10] */
/* @0x1ddf58 str r4, [r3, #0x118] */
/* @0x1ddf5c bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0x1ddf60 ldr r12, [sp, #0x10] */
/* @0x1ddf64 ldr r1, [pc, #0x7bc] */
/* @0x1ddf68 ldr r2, [pc, #0x7bc] */
/* @0x1ddf6c str r0, [r12] */
/* @0x1ddf70 mov r3, r0 */
/* @0x1ddf74 str r4, [r0, #0x38] */
/* @0x1ddf78 ldr r1, [r7, r1] */
/* @0x1ddf7c str r5, [r0, #0xc] */
/* @0x1ddf80 str r0, [r1] */
/* @0x1ddf84 ldr r2, [r7, r2] */
/* @0x1ddf88 ldr r2, [r2] */
/* @0x1ddf8c cmp r2, r5 */
/* @0x1ddf90 beq 0x1ddfa8 <_Z12LoadGameDataPvj+0x2c4> */
/* @0x1ddf94 add r4, sp, #64 */
/* @0x1ddf98 mov r0, r5 */
/* @0x1ddf9c str r3, [r4, #-0x10]! */
/* @0x1ddfa0 mov r1, r4 */
/* @0x1ddfa4 blx r2 */
/* @0x1ddfa8 ldr r12, [sp, #0xc] */
/* @0x1ddfac cmp r12, #0 */
/* @0x1ddfb0 beq 0x1de4cc <_Z12LoadGameDataPvj+0x7e8> */
/* @0x1ddfb4 ldr r3, [r12, #0x4] */
/* @0x1ddfb8 ldr r12, [sp, #0x18] */
/* @0x1ddfbc sub r2, r12, #8 */
/* @0x1ddfc0 cmp r2, r3 */
/* @0x1ddfc4 beq 0x1de0d0 <_Z12LoadGameDataPvj+0x3ec> */
/* @0x1ddfc8 mov r10, #1 */
/* @0x1ddfcc ldr r3, [pc, #0x75c] */
/* @0x1ddfd0 ldr r3, [r7, r3] */
/* @0x1ddfd4 ldrb r3, [r3] */
/* @0x1ddfd8 cmp r3, #0 */
/* @0x1ddfdc bne 0x1de0c8 <_Z12LoadGameDataPvj+0x3e4> */
/* @0x1ddfe0 ldr r12, [sp, #0x8] */
/* @0x1ddfe4 ldr r3, [r12] */
/* @0x1ddfe8 cmp r3, #0 */
/* @0x1ddfec beq 0x1de054 <_Z12LoadGameDataPvj+0x370> */
/* @0x1ddff0 ldr r5, [r3, #0x14] */
/* @0x1ddff4 ldr r4, [r5] */
/* @0x1ddff8 cmp r4, #0 */
/* @0x1ddffc beq 0x1de020 <_Z12LoadGameDataPvj+0x33c> */
/* @0x1de000 ldr r0, [r4] */
/* @0x1de004 bl 0xd1d60 <_Z18Code_Variable_FindPKc> */
/* @0x1de008 str r0, [r4, #0x4] */
/* @0x1de00c ldr r4, [r5, #0x4]! */
/* @0x1de010 cmp r4, #0 */
/* @0x1de014 bne 0x1de000 <_Z12LoadGameDataPvj+0x31c> */
/* @0x1de018 ldr r12, [sp, #0x8] */
/* @0x1de01c ldr r3, [r12] */
/* @0x1de020 ldr r6, [r3, #0x18] */
/* @0x1de024 ldr r5, [r6] */
/* @0x1de028 cmp r5, #0 */
/* @0x1de02c beq 0x1de054 <_Z12LoadGameDataPvj+0x370> */
/* @0x1de030 add r4, sp, #48 */
/* @0x1de034 ldr r0, [r5] */
/* @0x1de038 mov r1, r4 */
/* @0x1de03c bl 0xce158 <_Z18Code_Function_FindPKcPi> */
/* @0x1de040 ldr r3, [sp, #0x30] */
/* @0x1de044 str r3, [r5, #0x4] */
/* @0x1de048 ldr r5, [r6, #0x4]! */
/* @0x1de04c cmp r5, #0 */
/* @0x1de050 bne 0x1de034 <_Z12LoadGameDataPvj+0x350> */
/* @0x1de054 mov r0, r10 */
/* @0x1de058 add sp, sp, #68 */
/* @0x1de05c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1de060 cmp lr, r11 */
/* @0x1de064 beq 0x1de07c <_Z12LoadGameDataPvj+0x398> */
/* @0x1de068 add r0, r0, lr, lsl #2 */
/* @0x1de06c add lr, lr, #1 */
/* @0x1de070 str r10, [r0] */
/* @0x1de074 str lr, [r4, #0x4] */
/* @0x1de078 b 0x1ddeb0 <_Z12LoadGameDataPvj+0x1cc> */
/* @0x1de07c ldr r11, [r4, #0x8] */
/* @0x1de080 add r11, lr, r11 */
/* @0x1de084 cmp r11, lr */
/* @0x1de088 beq 0x1de068 <_Z12LoadGameDataPvj+0x384> */
/* @0x1de08c cmp r11, #0 */
/* @0x1de090 bne 0x1de458 <_Z12LoadGameDataPvj+0x774> */
/* @0x1de094 cmp r0, #0 */
/* @0x1de098 beq 0x1de414 <_Z12LoadGameDataPvj+0x730> */
/* @0x1de09c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1de0a0 mov lr, #1 */
/* @0x1de0a4 mov r0, r11 */
/* @0x1de0a8 str r11, [r4, #0xc] */
/* @0x1de0ac str r11, [r4] */
/* @0x1de0b0 b 0x1de070 <_Z12LoadGameDataPvj+0x38c> */
/* @0x1de0b4 ldr r3, [pc, #0x678] */
/* @0x1de0b8 ldr r0, [r7, r3] */
/* @0x1de0bc bl 0x16dd34 <_ZN14CCameraManager5CleanEv> */
/* @0x1de0c0 bl 0x1afef0 <_Z19CreateDefaultCamerav> */
/* @0x1de0c4 b 0x1ddd60 <_Z12LoadGameDataPvj+0x7c> */
/* @0x1de0c8 bl 0x23f93c <_Z16JS_ResourceSetupv> */
/* @0x1de0cc b 0x1ddfe0 <_Z12LoadGameDataPvj+0x2fc> */
/* @0x1de0d0 cmp r12, #8 */
/* @0x1de0d4 mov r3, #0 */
/* @0x1de0d8 strb r3, [sp, #0x34] */
/* @0x1de0dc bls 0x1ddfc8 <_Z12LoadGameDataPvj+0x2e4> */
/* @0x1de0e0 mov r8, #8 */
/* @0x1de0e4 mov r10, #1 */
/* @0x1de0e8 movw r11, #0x4853 */
/* @0x1de0ec str r10, [sp, #0x2c] */
/* @0x1de0f0 movt r11, #0x5244 */
/* @0x1de0f4 ldr r10, [sp, #0xc] */
/* @0x1de0f8 str r11, [sp, #0x10] */
/* @0x1de0fc movw r9, #0x4f52 */
/* @0x1de100 str r7, [sp, #0xc] */
/* @0x1de104 mov r7, r8 */
/* @0x1de108 ldr r11, [sp, #0x14] */
/* @0x1de10c movw r12, #0x424f */
/* @0x1de110 ldr r8, [sp, #0x18] */
/* @0x1de114 add r12, r12, #260 */
/* @0x1de118 movt r9, #0x4d4f */
/* @0x1de11c add r4, sp, #48 */
/* @0x1de120 sub r12, r12, #260 */
/* @0x1de124 movt r12, #0x544a */
/* @0x1de128 str r12, [sp, #0x1c] */
/* @0x1de12c movw r12, #0x4353 */
/* @0x1de130 movt r12, #0x5450 */
/* @0x1de134 str r12, [sp, #0x20] */
/* @0x1de138 movw r12, #0x5053 */
/* @0x1de13c movt r12, #0x5452 */
/* @0x1de140 str r12, [sp, #0x24] */
/* @0x1de144 movw r12, #0x4f46 */
/* @0x1de148 movt r12, #0x544e */
/* @0x1de14c str r12, [sp, #0x28] */
/* @0x1de150 mov r3, r10 */
/* @0x1de154 ldr r12, [r11] */
/* @0x1de158 ldr r6, [r3, r7]! */
/* @0x1de15c mov r0, r11 */
/* @0x1de160 ldr r1, [pc, #0x5d0] */
/* @0x1de164 mov r2, r4 */
/* @0x1de168 ldr r12, [r12, #0xc] */
/* @0x1de16c add r7, r7, #8 */
/* @0x1de170 ldr r5, [r3, #0x4] */
/* @0x1de174 add r1, pc, r1 */
/* @0x1de178 str r6, [sp, #0x30] */
/* @0x1de17c mov r3, r5 */
/* @0x1de180 blx r12 */
/* @0x1de184 mov r0, r4 */
/* @0x1de188 bl 0x27b948 <_Z17memLogPushContextPKc> */
/* @0x1de18c cmp r5, #0 */
/* @0x1de190 beq 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de194 cmp r6, r9 */
/* @0x1de198 beq 0x1de62c <_Z12LoadGameDataPvj+0x948> */
/* @0x1de19c bhi 0x1de248 <_Z12LoadGameDataPvj+0x564> */
/* @0x1de1a0 movw r3, #0x5054 */
/* @0x1de1a4 movt r3, #0x4741 */
/* @0x1de1a8 cmp r6, r3 */
/* @0x1de1ac beq 0x1de654 <_Z12LoadGameDataPvj+0x970> */
/* @0x1de1b0 bhi 0x1de308 <_Z12LoadGameDataPvj+0x624> */
/* @0x1de1b4 movw r3, #0x5546 */
/* @0x1de1b8 movt r3, #0x434e */
/* @0x1de1bc cmp r6, r3 */
/* @0x1de1c0 beq 0x1de640 <_Z12LoadGameDataPvj+0x95c> */
/* @0x1de1c4 bls 0x1de360 <_Z12LoadGameDataPvj+0x67c> */
/* @0x1de1c8 movw r3, #0x4f53 */
/* @0x1de1cc movt r3, #0x444e */
/* @0x1de1d0 cmp r6, r3 */
/* @0x1de1d4 beq 0x1de568 <_Z12LoadGameDataPvj+0x884> */
/* @0x1de1d8 movw r3, #0x4f43 */
/* @0x1de1dc movt r3, #0x4544 */
/* @0x1de1e0 cmp r6, r3 */
/* @0x1de1e4 beq 0x1de554 <_Z12LoadGameDataPvj+0x870> */
/* @0x1de1e8 movw r3, #0x4742 */
/* @0x1de1ec movt r3, #0x444e */
/* @0x1de1f0 cmp r6, r3 */
/* @0x1de1f4 beq 0x1de444 <_Z12LoadGameDataPvj+0x760> */
/* @0x1de1f8 mov r12, #0 */
/* @0x1de1fc ldr r0, [pc, #0x538] */
/* @0x1de200 str r12, [sp, #0x2c] */
/* @0x1de204 mov r3, r6 */
/* @0x1de208 ldr r12, [sp, #0xc] */
/* @0x1de20c mov r2, r4 */
/* @0x1de210 ldr r1, [pc, #0x528] */
/* @0x1de214 ldr r0, [r12, r0] */
/* @0x1de218 add r1, pc, r1 */
/* @0x1de21c ldr r0, [r0] */
/* @0x1de220 ldr r12, [r0] */
/* @0x1de224 ldr r12, [r12, #0xc] */
/* @0x1de228 blx r12 */
/* @0x1de22c add r7, r5, r7 */
/* @0x1de230 bl 0x27b94c <_Z16memLogPopContextv> */
/* @0x1de234 cmp r8, r7 */
/* @0x1de238 bhi 0x1de150 <_Z12LoadGameDataPvj+0x46c> */
/* @0x1de23c ldr r10, [sp, #0x2c] */
/* @0x1de240 ldr r7, [sp, #0xc] */
/* @0x1de244 b 0x1ddfcc <_Z12LoadGameDataPvj+0x2e8> */
/* @0x1de248 ldr r12, [sp, #0x10] */
/* @0x1de24c cmp r6, r12 */
/* @0x1de250 beq 0x1de52c <_Z12LoadGameDataPvj+0x848> */
/* @0x1de254 bhi 0x1de2b0 <_Z12LoadGameDataPvj+0x5cc> */
/* @0x1de258 movw r3, #0x5541 */
/* @0x1de25c movt r3, #0x4f44 */
/* @0x1de260 cmp r6, r3 */
/* @0x1de264 beq 0x1de500 <_Z12LoadGameDataPvj+0x81c> */
/* @0x1de268 bhi 0x1de3d8 <_Z12LoadGameDataPvj+0x6f4> */
/* @0x1de26c movw r3, #0x504f */
/* @0x1de270 movt r3, #0x4e54 */
/* @0x1de274 cmp r6, r3 */
/* @0x1de278 beq 0x1de604 <_Z12LoadGameDataPvj+0x920> */
/* @0x1de27c movw r3, #0x5845 */
/* @0x1de280 movt r3, #0x4e54 */
/* @0x1de284 cmp r6, r3 */
/* @0x1de288 beq 0x1de5f0 <_Z12LoadGameDataPvj+0x90c> */
/* @0x1de28c movw r3, #0x4d54 */
/* @0x1de290 movt r3, #0x4e4c */
/* @0x1de294 cmp r6, r3 */
/* @0x1de298 bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> */
/* @0x1de29c add r0, r10, r7 */
/* @0x1de2a0 mov r1, r5 */
/* @0x1de2a4 mov r2, r10 */
/* @0x1de2a8 bl 0x1f2770 <_Z13TimeLine_LoadPhjS_> */
/* @0x1de2ac b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de2b0 ldr r12, [sp, #0x1c] */
/* @0x1de2b4 cmp r6, r12 */
/* @0x1de2b8 beq 0x1de540 <_Z12LoadGameDataPvj+0x85c> */
/* @0x1de2bc bls 0x1de394 <_Z12LoadGameDataPvj+0x6b0> */
/* @0x1de2c0 ldr r12, [sp, #0x20] */
/* @0x1de2c4 cmp r6, r12 */
/* @0x1de2c8 beq 0x1de4ec <_Z12LoadGameDataPvj+0x808> */
/* @0x1de2cc ldr r12, [sp, #0x24] */
/* @0x1de2d0 cmp r6, r12 */
/* @0x1de2d4 beq 0x1de4d8 <_Z12LoadGameDataPvj+0x7f4> */
/* @0x1de2d8 ldr r12, [sp, #0x28] */
/* @0x1de2dc cmp r6, r12 */
/* @0x1de2e0 bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> */
/* @0x1de2e4 add r0, r10, r7 */
/* @0x1de2e8 mov r1, r5 */
/* @0x1de2ec mov r2, r10 */
/* @0x1de2f0 bl 0xfa0d4 <_Z9Font_LoadPhjS_> */
/* @0x1de2f4 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de2f8 ldr r3, [pc, #0x418] */
/* @0x1de2fc ldr r8, [r7, r3] */
/* @0x1de300 ldr r1, [r8] */
/* @0x1de304 b 0x1dddb8 <_Z12LoadGameDataPvj+0xd4> */
/* @0x1de308 movw r3, #0x4d45 */
/* @0x1de30c movt r3, #0x4942 */
/* @0x1de310 cmp r6, r3 */
/* @0x1de314 beq 0x1de42c <_Z12LoadGameDataPvj+0x748> */
/* @0x1de318 bhi 0x1de5a8 <_Z12LoadGameDataPvj+0x8c4> */
/* @0x1de31c movw r3, #0x5453 */
/* @0x1de320 movt r3, #0x4752 */
/* @0x1de324 cmp r6, r3 */
/* @0x1de328 beq 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de32c movw r3, #0x4150 */
/* @0x1de330 movt r3, #0x4854 */
/* @0x1de334 cmp r6, r3 */
/* @0x1de338 beq 0x1de594 <_Z12LoadGameDataPvj+0x8b0> */
/* @0x1de33c movw r3, #0x414c */
/* @0x1de340 movt r3, #0x474e */
/* @0x1de344 cmp r6, r3 */
/* @0x1de348 bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> */
/* @0x1de34c add r0, r10, r7 */
/* @0x1de350 mov r1, r5 */
/* @0x1de354 mov r2, r10 */
/* @0x1de358 bl 0x27a4c8 <_ZN8CLangMan13Language_LoadEPhjS0_> */
/* @0x1de35c b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de360 movw r3, #0x4547 */
/* @0x1de364 movt r3, #0x384e */
/* @0x1de368 cmp r6, r3 */
/* @0x1de36c beq 0x1de618 <_Z12LoadGameDataPvj+0x934> */
/* @0x1de370 movw r3, #0x4c47 */
/* @0x1de374 movt r3, #0x424f */
/* @0x1de378 cmp r6, r3 */
/* @0x1de37c bne 0x1de690 <_Z12LoadGameDataPvj+0x9ac> */
/* @0x1de380 add r0, r10, r7 */
/* @0x1de384 mov r1, r5 */
/* @0x1de388 mov r2, r10 */
/* @0x1de38c bl 0x1dcf64 <_Z9GLOB_LoadPhjS_> */
/* @0x1de390 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de394 movw r3, #0x5350 */
/* @0x1de398 movt r3, #0x5350 */
/* @0x1de39c cmp r6, r3 */
/* @0x1de3a0 beq 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de3a4 movw r3, #0x5453 */
/* @0x1de3a8 movt r3, #0x5441 */
/* @0x1de3ac cmp r6, r3 */
/* @0x1de3b0 beq 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de3b4 movw r3, #0x5854 */
/* @0x1de3b8 movt r3, #0x5254 */
/* @0x1de3bc cmp r6, r3 */
/* @0x1de3c0 bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> */
/* @0x1de3c4 add r0, r10, r7 */
/* @0x1de3c8 mov r1, r5 */
/* @0x1de3cc mov r2, r10 */
/* @0x1de3d0 bl 0x1dda28 <_Z12Texture_LoadPhjS_> */
/* @0x1de3d4 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de3d8 movw r3, #0x4741 */
/* @0x1de3dc movt r3, #0x5052 */
/* @0x1de3e0 cmp r6, r3 */
/* @0x1de3e4 bne 0x1de6bc <_Z12LoadGameDataPvj+0x9d8> */
/* @0x1de3e8 ldr r3, [pc, #0x354] */
/* @0x1de3ec ldr r12, [sp, #0xc] */
/* @0x1de3f0 ldr r3, [r12, r3] */
/* @0x1de3f4 ldrb r3, [r3] */
/* @0x1de3f8 cmp r3, #0 */
/* @0x1de3fc beq 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de400 add r0, r10, r7 */
/* @0x1de404 mov r1, r5 */
/* @0x1de408 mov r2, r10 */
/* @0x1de40c bl 0x218c94 <_Z15AudioGroup_LoadPhjS_> */
/* @0x1de410 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de414 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1de418 mov r1, #0 */
/* @0x1de41c mov lr, #1 */
/* @0x1de420 str r1, [r4, #0xc] */
/* @0x1de424 mov r0, r1 */
/* @0x1de428 b 0x1de0ac <_Z12LoadGameDataPvj+0x3c8> */
/* @0x1de42c mov r1, r5 */
/* @0x1de430 mov r2, r10 */
/* @0x1de434 add r0, r10, r7 */
/* @0x1de438 bl 0x176830 <_Z19EmbeddedImages_LoadPhjS_> */
/* @0x1de43c bl 0x1a58d8 <_Z24Part_SetupEmbeddedImagesv> */
/* @0x1de440 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de444 add r0, r10, r7 */
/* @0x1de448 mov r1, r5 */
/* @0x1de44c mov r2, r10 */
/* @0x1de450 bl 0xc3350 <_Z15Background_LoadPhjS_> */
/* @0x1de454 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de458 lsls r1, r11, #2 */
/* @0x1de45c beq 0x1de414 <_Z12LoadGameDataPvj+0x730> */
/* @0x1de460 mov r2, #0 */
/* @0x1de464 movw r3, #0x11b */
/* @0x1de468 str r2, [sp] */
/* @0x1de46c ldr r2, [sp, #0x1c] */
/* @0x1de470 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1de474 ldr r3, [r4, #0x4] */
/* @0x1de478 add lr, r3, #1 */
/* @0x1de47c str r0, [r4, #0xc] */
/* @0x1de480 add r0, r0, r3, lsl #2 */
/* @0x1de484 b 0x1de0ac <_Z12LoadGameDataPvj+0x3c8> */
/* @0x1de488 ldr r3, [pc, #0x280] */
/* @0x1de48c ldr r3, [r7, r3] */
/* @0x1de490 str r3, [sp, #0x8] */
/* @0x1de494 ldr r3, [r3] */
/* @0x1de498 cmp r3, #0 */
/* @0x1de49c beq 0x1de6a4 <_Z12LoadGameDataPvj+0x9c0> */
/* @0x1de4a0 ldr r2, [r3, #0x8] */
/* @0x1de4a4 cmp r2, #0 */
/* @0x1de4a8 ble 0x1de680 <_Z12LoadGameDataPvj+0x99c> */
/* @0x1de4ac ldr r1, [pc, #0x260] */
/* @0x1de4b0 mov r0, r2 */
/* @0x1de4b4 ldr r9, [r7, r1] */
/* @0x1de4b8 str r2, [r9] */
/* @0x1de4bc b 0x1ddd9c <_Z12LoadGameDataPvj+0xb8> */
/* @0x1de4c0 ldr r3, [pc, #0x250] */
/* @0x1de4c4 ldr r8, [r7, r3] */
/* @0x1de4c8 b 0x1ddf20 <_Z12LoadGameDataPvj+0x23c> */
/* @0x1de4cc ldr r0, [sp, #0xc] */
/* @0x1de4d0 add sp, sp, #68 */
/* @0x1de4d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1de4d8 add r0, r10, r7 */
/* @0x1de4dc mov r1, r5 */
/* @0x1de4e0 mov r2, r10 */
/* @0x1de4e4 bl 0x1effbc <_Z11Sprite_LoadPhiS_> */
/* @0x1de4e8 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de4ec add r0, r10, r7 */
/* @0x1de4f0 mov r1, r5 */
/* @0x1de4f4 mov r2, r10 */
/* @0x1de4f8 bl 0x1e01e4 <_Z11Script_LoadPhjS_> */
/* @0x1de4fc b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de500 ldr r3, [pc, #0x23c] */
/* @0x1de504 add r0, r10, r7 */
/* @0x1de508 ldr r12, [sp, #0xc] */
/* @0x1de50c mov r1, r5 */
/* @0x1de510 mov r2, r10 */
/* @0x1de514 ldr r3, [r12, r3] */
/* @0x1de518 ldrb r3, [r3] */
/* @0x1de51c cmp r3, #0 */
/* @0x1de520 bne 0x1de674 <_Z12LoadGameDataPvj+0x990> */
/* @0x1de524 bl 0x21f9d4 <_Z10Sound_WAVsPhjS_> */
/* @0x1de528 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de52c add r0, r10, r7 */
/* @0x1de530 mov r1, r5 */
/* @0x1de534 mov r2, r10 */
/* @0x1de538 bl 0x1e1cd8 <_Z11Shader_LoadPhjS_> */
/* @0x1de53c b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de540 add r0, r10, r7 */
/* @0x1de544 mov r1, r5 */
/* @0x1de548 mov r2, r10 */
/* @0x1de54c bl 0x19ea7c <_Z11Object_LoadPhjS_> */
/* @0x1de550 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de554 add r0, r10, r7 */
/* @0x1de558 mov r1, r5 */
/* @0x1de55c mov r2, r10 */
/* @0x1de560 bl 0x1dc8c4 <_Z10Code_PatchPhjS_> */
/* @0x1de564 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de568 ldr r3, [pc, #0x1d4] */
/* @0x1de56c add r0, r10, r7 */
/* @0x1de570 ldr r12, [sp, #0xc] */
/* @0x1de574 mov r1, r5 */
/* @0x1de578 mov r2, r10 */
/* @0x1de57c ldr r3, [r12, r3] */
/* @0x1de580 ldrb r3, [r3] */
/* @0x1de584 cmp r3, #0 */
/* @0x1de588 bne 0x1de66c <_Z12LoadGameDataPvj+0x988> */
/* @0x1de58c bl 0x21f630 <_Z10Sound_LoadPhjS_> */
/* @0x1de590 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de594 add r0, r10, r7 */
/* @0x1de598 mov r1, r5 */
/* @0x1de59c mov r2, r10 */
/* @0x1de5a0 bl 0x1a7e74 <_Z9Path_LoadPhjS_> */
/* @0x1de5a4 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de5a8 movw r3, #0x4144 */
/* @0x1de5ac movt r3, #0x4c46 */
/* @0x1de5b0 cmp r6, r3 */
/* @0x1de5b4 beq 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de5b8 movw r3, #0x4547 */
/* @0x1de5bc movt r3, #0x4c4e */
/* @0x1de5c0 cmp r6, r3 */
/* @0x1de5c4 bne 0x1de6e0 <_Z12LoadGameDataPvj+0x9fc> */
/* @0x1de5c8 ldr r2, [sp, #0xc] */
/* @0x1de5cc add r0, r10, r7 */
/* @0x1de5d0 ldr r3, [pc, #0x170] */
/* @0x1de5d4 mov r1, r5 */
/* @0x1de5d8 mov r12, #700 */
/* @0x1de5dc ldr r3, [r2, r3] */
/* @0x1de5e0 mov r2, r10 */
/* @0x1de5e4 str r12, [r3] */
/* @0x1de5e8 bl 0x1dcf94 <_Z11Header_LoadPhjS_> */
/* @0x1de5ec b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de5f0 add r0, r10, r7 */
/* @0x1de5f4 mov r1, r5 */
/* @0x1de5f8 mov r2, r10 */
/* @0x1de5fc bl 0xf5eb8 <_Z14Extension_LoadPhjS_> */
/* @0x1de600 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de604 add r0, r10, r7 */
/* @0x1de608 mov r1, r5 */
/* @0x1de60c mov r2, r10 */
/* @0x1de610 bl 0x19f534 <_Z11Option_LoadPhjS_> */
/* @0x1de614 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de618 add r0, r10, r7 */
/* @0x1de61c mov r1, r5 */
/* @0x1de620 mov r2, r10 */
/* @0x1de624 bl 0x1dcf94 <_Z11Header_LoadPhjS_> */
/* @0x1de628 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de62c add r0, r10, r7 */
/* @0x1de630 mov r1, r5 */
/* @0x1de634 mov r2, r10 */
/* @0x1de638 bl 0x1b4cd8 <_Z9Room_LoadPhjS_> */
/* @0x1de63c b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de640 add r0, r10, r7 */
/* @0x1de644 mov r1, r5 */
/* @0x1de648 mov r2, r10 */
/* @0x1de64c bl 0x1dcdf0 <_Z9FUNC_LoadPhjS_> */
/* @0x1de650 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de654 ldr r3, [pc, #0xf0] */
/* @0x1de658 add r2, r10, r7 */
/* @0x1de65c ldr r12, [sp, #0xc] */
/* @0x1de660 ldr r3, [r12, r3] */
/* @0x1de664 str r2, [r3] */
/* @0x1de668 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de66c bl 0x219048 <_Z10Audio_LoadPhjS_> */
/* @0x1de670 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de674 mov r3, #0 */
/* @0x1de678 bl 0x219680 <_Z10Audio_WAVsPhjS_i> */
/* @0x1de67c b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de680 ldr r2, [pc, #0x8c] */
/* @0x1de684 ldr r9, [r7, r2] */
/* @0x1de688 ldr r0, [r9] */
/* @0x1de68c b 0x1ddd9c <_Z12LoadGameDataPvj+0xb8> */
/* @0x1de690 movw r3, #0x4547 */
/* @0x1de694 movt r3, #0x374e */
/* @0x1de698 cmp r6, r3 */
/* @0x1de69c bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> */
/* @0x1de6a0 b 0x1de5c8 <_Z12LoadGameDataPvj+0x8e4> */
/* @0x1de6a4 ldr r3, [pc, #0x68] */
/* @0x1de6a8 ldr r2, [pc, #0x68] */
/* @0x1de6ac ldr r3, [r7, r3] */
/* @0x1de6b0 ldr r8, [r7, r2] */
/* @0x1de6b4 ldr r0, [r3] */
/* @0x1de6b8 b 0x1ddf20 <_Z12LoadGameDataPvj+0x23c> */
/* @0x1de6bc movw r3, #0x4152 */
/* @0x1de6c0 movt r3, #0x5053 */
/* @0x1de6c4 cmp r6, r3 */
/* @0x1de6c8 beq 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de6cc movw r3, #0x4548 */
/* @0x1de6d0 movt r3, #0x504c */
/* @0x1de6d4 cmp r6, r3 */
/* @0x1de6d8 bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> */
/* @0x1de6dc b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de6e0 movw r3, #0x4156 */
/* @0x1de6e4 movt r3, #0x4952 */
/* @0x1de6e8 cmp r6, r3 */
/* @0x1de6ec bne 0x1de1f8 <_Z12LoadGameDataPvj+0x514> */
/* @0x1de6f0 b 0x1de22c <_Z12LoadGameDataPvj+0x548> */
/* @0x1de6f4 mov r1, r0 */
/* @0x1de6f8 b 0x1ddeac <_Z12LoadGameDataPvj+0x1c8> */
/* @0x1de6fc eoreq r3, r1, r12, asr pc */
/* @0x1de700 .word 0xffffdecc */
/* @0x1de704 andseq r3, r7, r0, lsr #21 */
/* @0x1de708 .word 0xffffbcd4 */
/* @0x1de70c .word 0xffffbf64 */
/* @0x1de710 .word 0xffffbef0 */
/* @0x1de714 .word 0xffffc0b8 */
/* @0x1de718 .word 0xffffc0c4 */
/* @0x1de71c .word 0xffffbf4c */
/* @0x1de720 andseq pc, r6, r4, asr #9 */
/* @0x1de724 .word 0xffffc010 */
/* @0x1de728 .word 0xffffc058 */
/* @0x1de72c .word 0xffffc5f8 */
/* @0x1de730 .word 0xffffbf68 */
/* @0x1de734 .word 0xffffc024 */
/* @0x1de738 andseq r3, r7, r0, asr r6 */
/* @0x1de73c .word 0xffffbac4 */
/* @0x1de740 andseq r3, r7, r4, asr #11 */
/* @0x1de744 .word 0xffffd0e0 */
/* @0x1de748 .word 0xffffd14c */
/* @0x1de74c .word 0xfffff094 */

/* ── FUNC 0x1de750 · DebugScript_Load(unsigned char*, unsigned int, unsigned char*) · size=28 · insn=7 */
/* @0x1de750 ldr r3, [pc, #0x10] */
/* @0x1de754 add r2, r0, #4 */
/* @0x1de758 mov r0, #1 */
/* @0x1de75c ldr r3, [pc, r3] */
/* @0x1de760 str r2, [r3] */
/* @0x1de764 bx lr */
/* @0x1de768 .word 0x0020f3f0 */

/* ── FUNC 0x1de76c · DebugInfo_Load(unsigned char*, unsigned int, unsigned char*) · size=28 · insn=7 */
/* @0x1de76c ldr r3, [pc, #0x10] */
/* @0x1de770 add r2, r0, #4 */
/* @0x1de774 mov r0, #1 */
/* @0x1de778 ldr r3, [pc, r3] */
/* @0x1de77c str r2, [r3] */
/* @0x1de780 bx lr */
/* @0x1de784 eoreq pc, r0, r0, ror #7 */

/* ── FUNC 0x1de788 · DebugInstNames_Load(unsigned char*, unsigned int, unsigned char*) · size=40 · insn=10 */
/* @0x1de788 ldr r2, [pc, #0x18] */
/* @0x1de78c ldr r3, [pc, #0x18] */
/* @0x1de790 ldr r1, [r0], #4 */
/* @0x1de794 ldr r2, [pc, r2] */
/* @0x1de798 ldr r3, [pc, r3] */
/* @0x1de79c str r0, [r2] */
/* @0x1de7a0 str r1, [r3] */
/* @0x1de7a4 bx lr */
/* @0x1de7a8 eoreq r2, r1, r4, asr r5 */
/* @0x1de7ac eoreq r2, r1, r4, asr r5 */

/* ── FUNC 0x1de7b0 · LoadDebugInfo(void*, unsigned int) · size=312 · insn=78 */
/* @0x1de7b0 ldr r3, [pc, #0x124] */
/* @0x1de7b4 ldr r2, [r0, #0x4] */
/* @0x1de7b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1de7bc mov r9, r1 */
/* @0x1de7c0 sub r1, r1, #8 */
/* @0x1de7c4 ldr r3, [pc, r3] */
/* @0x1de7c8 cmp r1, r2 */
/* @0x1de7cc sub sp, sp, #28 */
/* @0x1de7d0 mov r6, r0 */
/* @0x1de7d4 str r0, [r3] */
/* @0x1de7d8 beq 0x1de7e8 <_Z13LoadDebugInfoPvj+0x38> */
/* @0x1de7dc mov r0, #1 */
/* @0x1de7e0 add sp, sp, #28 */
/* @0x1de7e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1de7e8 cmp r9, #8 */
/* @0x1de7ec mov r3, #0 */
/* @0x1de7f0 strb r3, [sp, #0x14] */
/* @0x1de7f4 bls 0x1de7dc <_Z13LoadDebugInfoPvj+0x2c> */
/* @0x1de7f8 ldr r3, [pc, #0xe0] */
/* @0x1de7fc movw r2, #0x4353 */
/* @0x1de800 ldr r11, [pc, #0xdc] */
/* @0x1de804 movt r2, #0x5450 */
/* @0x1de808 ldr r3, [pc, r3] */
/* @0x1de80c str r2, [sp, #0x4] */
/* @0x1de810 add r11, pc, r11 */
/* @0x1de814 movw r2, #0x4e49 */
/* @0x1de818 ldr r8, [r3] */
/* @0x1de81c movt r2, #0x5453 */
/* @0x1de820 movw r3, #0x4244 */
/* @0x1de824 str r2, [sp, #0x8] */
/* @0x1de828 movt r3, #0x4947 */
/* @0x1de82c add r10, sp, #16 */
/* @0x1de830 str r3, [sp, #0xc] */
/* @0x1de834 mov r7, #8 */
/* @0x1de838 b 0x1de870 <_Z13LoadDebugInfoPvj+0xc0> */
/* @0x1de83c ldr r3, [sp, #0x8] */
/* @0x1de840 cmp r5, r3 */
/* @0x1de844 beq 0x1de8c8 <_Z13LoadDebugInfoPvj+0x118> */
/* @0x1de848 ldr r2, [sp, #0xc] */
/* @0x1de84c cmp r5, r2 */
/* @0x1de850 bne 0x1de864 <_Z13LoadDebugInfoPvj+0xb4> */
/* @0x1de854 add r0, r6, r7 */
/* @0x1de858 mov r1, r4 */
/* @0x1de85c mov r2, r6 */
/* @0x1de860 bl 0x1de76c <_Z14DebugInfo_LoadPhjS_> */
/* @0x1de864 add r7, r4, r7 */
/* @0x1de868 cmp r9, r7 */
/* @0x1de86c bls 0x1de7dc <_Z13LoadDebugInfoPvj+0x2c> */
/* @0x1de870 mov r3, r6 */
/* @0x1de874 ldr r12, [r8] */
/* @0x1de878 ldr r5, [r3, r7]! */
/* @0x1de87c mov r0, r8 */
/* @0x1de880 mov r1, r11 */
/* @0x1de884 mov r2, r10 */
/* @0x1de888 ldr r12, [r12, #0xc] */
/* @0x1de88c add r7, r7, #8 */
/* @0x1de890 ldr r4, [r3, #0x4] */
/* @0x1de894 str r5, [sp, #0x10] */
/* @0x1de898 mov r3, r4 */
/* @0x1de89c blx r12 */
/* @0x1de8a0 cmp r4, #0 */
/* @0x1de8a4 beq 0x1de864 <_Z13LoadDebugInfoPvj+0xb4> */
/* @0x1de8a8 ldr r2, [sp, #0x4] */
/* @0x1de8ac cmp r5, r2 */
/* @0x1de8b0 bne 0x1de83c <_Z13LoadDebugInfoPvj+0x8c> */
/* @0x1de8b4 add r0, r6, r7 */
/* @0x1de8b8 mov r1, r4 */
/* @0x1de8bc mov r2, r6 */
/* @0x1de8c0 bl 0x1de750 <_Z16DebugScript_LoadPhjS_> */
/* @0x1de8c4 b 0x1de864 <_Z13LoadDebugInfoPvj+0xb4> */
/* @0x1de8c8 add r0, r6, r7 */
/* @0x1de8cc mov r1, r4 */
/* @0x1de8d0 mov r2, r6 */
/* @0x1de8d4 bl 0x1de788 <_Z19DebugInstNames_LoadPhjS_> */
/* @0x1de8d8 b 0x1de864 <_Z13LoadDebugInfoPvj+0xb4> */
/* @0x1de8dc eoreq pc, r0, r12, lsl #7 */
/* @0x1de8e0 eoreq r1, r1, r4, lsl r3 */
/* @0x1de8e4 ldrheq r2, [r7], -r4 */

/* ── FUNC 0x1de8e8 · Facebook_Setup(IniFile*) · size=148 · insn=37 */
/* @0x1de8e8 ldr r1, [pc, #0x74] */
/* @0x1de8ec ldr r2, [pc, #0x74] */
/* @0x1de8f0 push {r4, lr} */
/* @0x1de8f4 add r1, pc, r1 */
/* @0x1de8f8 add r2, pc, r2 */
/* @0x1de8fc bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x1de900 subs r4, r0, #0 */
/* @0x1de904 popeq {r4, pc} */
/* @0x1de908 ldr r3, [pc, #0x5c] */
/* @0x1de90c ldr r1, [pc, #0x5c] */
/* @0x1de910 ldr r3, [pc, r3] */
/* @0x1de914 ldr r2, [r4, #0x8] */
/* @0x1de918 add r1, pc, r1 */
/* @0x1de91c ldr r0, [r3] */
/* @0x1de920 ldr r3, [r0] */
/* @0x1de924 ldr r3, [r3, #0xc] */
/* @0x1de928 blx r3 */
/* @0x1de92c ldr r0, [r4, #0x8] */
/* @0x1de930 bl 0xb6538 <strlen@plt> */
/* @0x1de934 ldr r1, [pc, #0x38] */
/* @0x1de938 mov r3, #1 */
/* @0x1de93c movw r2, #0x72c */
/* @0x1de940 add r1, pc, r1 */
/* @0x1de944 add r0, r0, r3 */
/* @0x1de948 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1de94c ldr r3, [pc, #0x24] */
/* @0x1de950 ldr r1, [r4, #0x8] */
/* @0x1de954 ldr r3, [pc, r3] */
/* @0x1de958 pop {r4, lr} */
/* @0x1de95c str r0, [r3] */
/* @0x1de960 b 0xb65a4 <strcpy@plt> */
/* @0x1de964 andseq r2, r7, r0, lsl #30 */
/* @0x1de968 andseq r2, r7, r4, lsl #30 */
/* @0x1de96c eoreq lr, r0, r4, lsl #28 */
/* @0x1de970 ldrsheq r2, [r7], -r0 */
/* @0x1de974 andseq r2, r7, r4, ror #29 */
/* @0x1de978 eoreq r1, r1, r4, asr r5 */

/* ── FUNC 0x1de97c · Misc_Setup(IniFile*) · size=4 · insn=1 */
/* @0x1de97c bx lr */

/* ── FUNC 0x1de980 · Purchases_Setup(IniFile*) · size=4 · insn=1 */
/* @0x1de980 bx lr */

/* ── FUNC 0x1de984 · Platform_Setup(IniFile*) · size=1208 · insn=302 */
/* @0x1de984 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1de988 mov r4, r0 */
/* @0x1de98c bl 0x1dfb88 <_Z15Platform_SetupMP7IniFile> */
/* @0x1de990 mov r0, r4 */
/* @0x1de994 ldr r5, [pc, #0x414] */
/* @0x1de998 bl 0x1de8e8 <_Z14Facebook_SetupP7IniFile> */
/* @0x1de99c mov r0, r4 */
/* @0x1de9a0 bl 0x1de980 <_Z15Purchases_SetupP7IniFile> */
/* @0x1de9a4 mov r0, r4 */
/* @0x1de9a8 add r5, pc, r5 */
/* @0x1de9ac bl 0x1de97c <_Z10Misc_SetupP7IniFile> */
/* @0x1de9b0 ldr r2, [pc, #0x3fc] */
/* @0x1de9b4 mov r0, r4 */
/* @0x1de9b8 mov r1, r5 */
/* @0x1de9bc add r2, pc, r2 */
/* @0x1de9c0 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x1de9c4 ldr r2, [pc, #0x3ec] */
/* @0x1de9c8 mov r1, r5 */
/* @0x1de9cc add r2, pc, r2 */
/* @0x1de9d0 mov r9, r0 */
/* @0x1de9d4 mov r0, r4 */
/* @0x1de9d8 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x1de9dc ldr r2, [pc, #0x3d8] */
/* @0x1de9e0 mov r1, r5 */
/* @0x1de9e4 add r2, pc, r2 */
/* @0x1de9e8 mov r8, r0 */
/* @0x1de9ec mov r0, r4 */
/* @0x1de9f0 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x1de9f4 ldr r2, [pc, #0x3c4] */
/* @0x1de9f8 mov r1, r5 */
/* @0x1de9fc ldr r5, [pc, #0x3c0] */
/* @0x1dea00 add r2, pc, r2 */
/* @0x1dea04 add r5, pc, r5 */
/* @0x1dea08 mov r7, r0 */
/* @0x1dea0c mov r0, r4 */
/* @0x1dea10 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x1dea14 cmp r9, #0 */
/* @0x1dea18 mov r6, r0 */
/* @0x1dea1c beq 0x1dea70 <_Z14Platform_SetupP7IniFile+0xec> */
/* @0x1dea20 ldr r9, [r9, #0x8] */
/* @0x1dea24 ldr r1, [pc, #0x39c] */
/* @0x1dea28 mov r0, r9 */
/* @0x1dea2c add r1, pc, r1 */
/* @0x1dea30 bl 0xb6574 <strcmp@plt> */
/* @0x1dea34 cmp r0, #0 */
/* @0x1dea38 beq 0x1ded1c <_Z14Platform_SetupP7IniFile+0x398> */
/* @0x1dea3c ldr r1, [pc, #0x388] */
/* @0x1dea40 mov r0, r9 */
/* @0x1dea44 add r1, pc, r1 */
/* @0x1dea48 bl 0xb6574 <strcmp@plt> */
/* @0x1dea4c cmp r0, #0 */
/* @0x1dea50 beq 0x1ded90 <_Z14Platform_SetupP7IniFile+0x40c> */
/* @0x1dea54 mov r0, r9 */
/* @0x1dea58 bl 0xb66b8 <atoi@plt> */
/* @0x1dea5c ldr r3, [pc, #0x36c] */
/* @0x1dea60 ldr r3, [r5, r3] */
/* @0x1dea64 adds r0, r0, #0 */
/* @0x1dea68 movne r0, #1 */
/* @0x1dea6c str r0, [r3] */
/* @0x1dea70 cmp r8, #0 */
/* @0x1dea74 beq 0x1deac8 <_Z14Platform_SetupP7IniFile+0x144> */
/* @0x1dea78 ldr r8, [r8, #0x8] */
/* @0x1dea7c ldr r1, [pc, #0x350] */
/* @0x1dea80 mov r0, r8 */
/* @0x1dea84 add r1, pc, r1 */
/* @0x1dea88 bl 0xb6574 <strcmp@plt> */
/* @0x1dea8c cmp r0, #0 */
/* @0x1dea90 beq 0x1ded30 <_Z14Platform_SetupP7IniFile+0x3ac> */
/* @0x1dea94 ldr r1, [pc, #0x33c] */
/* @0x1dea98 mov r0, r8 */
/* @0x1dea9c add r1, pc, r1 */
/* @0x1deaa0 bl 0xb6574 <strcmp@plt> */
/* @0x1deaa4 cmp r0, #0 */
/* @0x1deaa8 beq 0x1deda0 <_Z14Platform_SetupP7IniFile+0x41c> */
/* @0x1deaac mov r0, r8 */
/* @0x1deab0 bl 0xb66b8 <atoi@plt> */
/* @0x1deab4 ldr r3, [pc, #0x320] */
/* @0x1deab8 ldr r3, [r5, r3] */
/* @0x1deabc adds r0, r0, #0 */
/* @0x1deac0 movne r0, #1 */
/* @0x1deac4 str r0, [r3] */
/* @0x1deac8 cmp r7, #0 */
/* @0x1deacc beq 0x1deb20 <_Z14Platform_SetupP7IniFile+0x19c> */
/* @0x1dead0 ldr r7, [r7, #0x8] */
/* @0x1dead4 ldr r1, [pc, #0x304] */
/* @0x1dead8 mov r0, r7 */
/* @0x1deadc add r1, pc, r1 */
/* @0x1deae0 bl 0xb6574 <strcmp@plt> */
/* @0x1deae4 cmp r0, #0 */
/* @0x1deae8 beq 0x1ded08 <_Z14Platform_SetupP7IniFile+0x384> */
/* @0x1deaec ldr r1, [pc, #0x2f0] */
/* @0x1deaf0 mov r0, r7 */
/* @0x1deaf4 add r1, pc, r1 */
/* @0x1deaf8 bl 0xb6574 <strcmp@plt> */
/* @0x1deafc cmp r0, #0 */
/* @0x1deb00 beq 0x1ded80 <_Z14Platform_SetupP7IniFile+0x3fc> */
/* @0x1deb04 mov r0, r7 */
/* @0x1deb08 bl 0xb66b8 <atoi@plt> */
/* @0x1deb0c ldr r3, [pc, #0x2d4] */
/* @0x1deb10 ldr r3, [r5, r3] */
/* @0x1deb14 adds r0, r0, #0 */
/* @0x1deb18 movne r0, #1 */
/* @0x1deb1c str r0, [r3] */
/* @0x1deb20 cmp r6, #0 */
/* @0x1deb24 beq 0x1deb78 <_Z14Platform_SetupP7IniFile+0x1f4> */
/* @0x1deb28 ldr r6, [r6, #0x8] */
/* @0x1deb2c ldr r1, [pc, #0x2b8] */
/* @0x1deb30 mov r0, r6 */
/* @0x1deb34 add r1, pc, r1 */
/* @0x1deb38 bl 0xb6574 <strcmp@plt> */
/* @0x1deb3c cmp r0, #0 */
/* @0x1deb40 beq 0x1decf4 <_Z14Platform_SetupP7IniFile+0x370> */
/* @0x1deb44 ldr r1, [pc, #0x2a4] */
/* @0x1deb48 mov r0, r6 */
/* @0x1deb4c add r1, pc, r1 */
/* @0x1deb50 bl 0xb6574 <strcmp@plt> */
/* @0x1deb54 cmp r0, #0 */
/* @0x1deb58 beq 0x1ded70 <_Z14Platform_SetupP7IniFile+0x3ec> */
/* @0x1deb5c mov r0, r6 */
/* @0x1deb60 bl 0xb66b8 <atoi@plt> */
/* @0x1deb64 ldr r3, [pc, #0x288] */
/* @0x1deb68 ldr r3, [r5, r3] */
/* @0x1deb6c adds r0, r0, #0 */
/* @0x1deb70 movne r0, #1 */
/* @0x1deb74 str r0, [r3] */
/* @0x1deb78 ldr r1, [pc, #0x278] */
/* @0x1deb7c mov r0, r4 */
/* @0x1deb80 ldr r2, [pc, #0x274] */
/* @0x1deb84 add r1, pc, r1 */
/* @0x1deb88 add r2, pc, r2 */
/* @0x1deb8c bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x1deb90 cmp r0, #0 */
/* @0x1deb94 beq 0x1debbc <_Z14Platform_SetupP7IniFile+0x238> */
/* @0x1deb98 ldr r0, [r0, #0x8] */
/* @0x1deb9c bl 0xb66b8 <atoi@plt> */
/* @0x1deba0 ldr r3, [pc, #0x258] */
/* @0x1deba4 ldr r3, [r5, r3] */
/* @0x1deba8 adds r0, r0, #0 */
/* @0x1debac movne r0, #1 */
/* @0x1debb0 cmp r0, #0 */
/* @0x1debb4 strb r0, [r3] */
/* @0x1debb8 bne 0x1ded44 <_Z14Platform_SetupP7IniFile+0x3c0> */
/* @0x1debbc ldr r1, [pc, #0x240] */
/* @0x1debc0 mov r0, r4 */
/* @0x1debc4 ldr r2, [pc, #0x23c] */
/* @0x1debc8 add r1, pc, r1 */
/* @0x1debcc add r2, pc, r2 */
/* @0x1debd0 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x1debd4 cmp r0, #0 */
/* @0x1debd8 beq 0x1debf8 <_Z14Platform_SetupP7IniFile+0x274> */
/* @0x1debdc ldr r0, [r0, #0x8] */
/* @0x1debe0 bl 0xb66b8 <atoi@plt> */
/* @0x1debe4 ldr r3, [pc, #0x220] */
/* @0x1debe8 ldr r3, [r5, r3] */
/* @0x1debec adds r0, r0, #0 */
/* @0x1debf0 movne r0, #1 */
/* @0x1debf4 strb r0, [r3] */
/* @0x1debf8 ldr r1, [pc, #0x210] */
/* @0x1debfc mov r0, r4 */
/* @0x1dec00 ldr r2, [pc, #0x20c] */
/* @0x1dec04 add r1, pc, r1 */
/* @0x1dec08 add r2, pc, r2 */
/* @0x1dec0c bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x1dec10 cmp r0, #0 */
/* @0x1dec14 beq 0x1dec34 <_Z14Platform_SetupP7IniFile+0x2b0> */
/* @0x1dec18 ldr r0, [r0, #0x8] */
/* @0x1dec1c bl 0xb66b8 <atoi@plt> */
/* @0x1dec20 ldr r3, [pc, #0x1f0] */
/* @0x1dec24 ldr r3, [r5, r3] */
/* @0x1dec28 adds r0, r0, #0 */
/* @0x1dec2c movne r0, #1 */
/* @0x1dec30 strb r0, [r3] */
/* @0x1dec34 ldr r1, [pc, #0x1e0] */
/* @0x1dec38 mov r0, r4 */
/* @0x1dec3c ldr r2, [pc, #0x1dc] */
/* @0x1dec40 add r1, pc, r1 */
/* @0x1dec44 add r2, pc, r2 */
/* @0x1dec48 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x1dec4c subs r4, r0, #0 */
/* @0x1dec50 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1dec54 ldr r0, [r4, #0x8] */
/* @0x1dec58 bl 0xb6538 <strlen@plt> */
/* @0x1dec5c ldr r1, [pc, #0x1c0] */
/* @0x1dec60 movw r2, #0x7ee */
/* @0x1dec64 mov r3, #1 */
/* @0x1dec68 add r1, pc, r1 */
/* @0x1dec6c add r0, r0, r3 */
/* @0x1dec70 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1dec74 ldr r3, [pc, #0x1ac] */
/* @0x1dec78 ldr r1, [r4, #0x8] */
/* @0x1dec7c ldr r4, [r5, r3] */
/* @0x1dec80 str r0, [r4] */
/* @0x1dec84 bl 0xb65a4 <strcpy@plt> */
/* @0x1dec88 ldr r6, [r4] */
/* @0x1dec8c mov r1, #58 */
/* @0x1dec90 mov r0, r6 */
/* @0x1dec94 bl 0xb6868 <strrchr@plt> */
/* @0x1dec98 cmp r0, #0 */
/* @0x1dec9c beq 0x1ded5c <_Z14Platform_SetupP7IniFile+0x3d8> */
/* @0x1deca0 mov r3, #0 */
/* @0x1deca4 strb r3, [r0], #1 */
/* @0x1deca8 bl 0xb66b8 <atoi@plt> */
/* @0x1decac ldr lr, [pc, #0x178] */
/* @0x1decb0 ldr r1, [pc, #0x160] */
/* @0x1decb4 mov r12, #1 */
/* @0x1decb8 ldr r2, [r4] */
/* @0x1decbc ldr lr, [r5, lr] */
/* @0x1decc0 str r0, [lr] */
/* @0x1decc4 mov r3, r0 */
/* @0x1decc8 ldr r1, [r5, r1] */
/* @0x1deccc strb r12, [r1] */
/* @0x1decd0 ldr r0, [pc, #0x158] */
/* @0x1decd4 ldr r1, [pc, #0x158] */
/* @0x1decd8 ldr r0, [r5, r0] */
/* @0x1decdc add r1, pc, r1 */
/* @0x1dece0 ldr r0, [r0] */
/* @0x1dece4 ldr r12, [r0] */
/* @0x1dece8 ldr r12, [r12, #0xc] */
/* @0x1decec blx r12 */
/* @0x1decf0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1decf4 ldr r3, [pc, #0xf8] */
/* @0x1decf8 mov r2, #1 */
/* @0x1decfc ldr r3, [r5, r3] */
/* @0x1ded00 str r2, [r3] */
/* @0x1ded04 b 0x1deb78 <_Z14Platform_SetupP7IniFile+0x1f4> */
/* @0x1ded08 ldr r3, [pc, #0xd8] */
/* @0x1ded0c mov r2, #1 */
/* @0x1ded10 ldr r3, [r5, r3] */
/* @0x1ded14 str r2, [r3] */
/* @0x1ded18 b 0x1deb20 <_Z14Platform_SetupP7IniFile+0x19c> */
/* @0x1ded1c ldr r3, [pc, #0xac] */
/* @0x1ded20 mov r2, #1 */
/* @0x1ded24 ldr r3, [r5, r3] */
/* @0x1ded28 str r2, [r3] */
/* @0x1ded2c b 0x1dea70 <_Z14Platform_SetupP7IniFile+0xec> */
/* @0x1ded30 ldr r3, [pc, #0xa4] */
/* @0x1ded34 mov r2, #1 */
/* @0x1ded38 ldr r3, [r5, r3] */
/* @0x1ded3c str r2, [r3] */
/* @0x1ded40 b 0x1deac8 <_Z14Platform_SetupP7IniFile+0x144> */
/* @0x1ded44 ldr r3, [pc, #0xec] */
/* @0x1ded48 mov r2, #2 */
/* @0x1ded4c ldr r3, [r5, r3] */
/* @0x1ded50 str r2, [r3] */
/* @0x1ded54 bl 0x237b88 <_ZN13CPhysicsWorld12SetDebugModeEv> */
/* @0x1ded58 b 0x1debbc <_Z14Platform_SetupP7IniFile+0x238> */
/* @0x1ded5c ldr r3, [pc, #0xc8] */
/* @0x1ded60 mov r2, r6 */
/* @0x1ded64 ldr r3, [r5, r3] */
/* @0x1ded68 ldr r3, [r3] */
/* @0x1ded6c b 0x1decd0 <_Z14Platform_SetupP7IniFile+0x34c> */
/* @0x1ded70 ldr r3, [pc, #0x7c] */
/* @0x1ded74 ldr r3, [r5, r3] */
/* @0x1ded78 str r0, [r3] */
/* @0x1ded7c b 0x1deb78 <_Z14Platform_SetupP7IniFile+0x1f4> */
/* @0x1ded80 ldr r3, [pc, #0x60] */
/* @0x1ded84 ldr r3, [r5, r3] */
/* @0x1ded88 str r0, [r3] */
/* @0x1ded8c b 0x1deb20 <_Z14Platform_SetupP7IniFile+0x19c> */
/* @0x1ded90 ldr r3, [pc, #0x38] */
/* @0x1ded94 ldr r3, [r5, r3] */
/* @0x1ded98 str r0, [r3] */
/* @0x1ded9c b 0x1dea70 <_Z14Platform_SetupP7IniFile+0xec> */
/* @0x1deda0 ldr r3, [pc, #0x34] */
/* @0x1deda4 ldr r3, [r5, r3] */
/* @0x1deda8 str r0, [r3] */
/* @0x1dedac b 0x1deac8 <_Z14Platform_SetupP7IniFile+0x144> */
/* @0x1dedb0 andseq r2, r7, r12, asr #28 */
/* @0x1dedb4 andseq r2, r7, r0, lsr #29 */
/* @0x1dedb8 andseq r2, r7, r0, lsr #29 */
/* @0x1dedbc andseq r2, r7, r0, lsr #29 */
/* @0x1dedc0 mulseq r7, r4, lr */
/* @0x1dedc4 eoreq r3, r1, r12, asr #4 */
/* @0x1dedc8 andseq r2, r7, r0, lsl #29 */
/* @0x1dedcc andseq r2, r7, r0, ror lr */
/* @0x1dedd0 .word 0xffffdf64 */
/* @0x1dedd4 andseq r2, r7, r8, lsr #28 */
/* @0x1dedd8 andseq r2, r7, r8, lsl lr */
/* @0x1deddc .word 0xffffdf6c */
/* @0x1dede0 ldrsbeq r2, [r7], -r0 */
/* @0x1dede4 andseq r2, r7, r0, asr #27 */
/* @0x1dede8 .word 0xffffdf68 */
/* @0x1dedec andseq r2, r7, r8, ror sp */
/* @0x1dedf0 andseq r2, r7, r8, ror #26 */
/* @0x1dedf4 .word 0xffffdf70 */
/* @0x1dedf8 andseq r2, r7, r0, ror r12 */
/* @0x1dedfc andseq r2, r7, r4, lsr sp */
/* @0x1dee00 .word 0xffffef34 */
/* @0x1dee04 andseq r2, r7, r12, lsr #24 */
/* @0x1dee08 ldrsheq r2, [r7], -r8 */
/* @0x1dee0c .word 0xffffc100 */
/* @0x1dee10 ldrsheq r2, [r7], -r0 */
/* @0x1dee14 andseq r2, r7, r4, asr #25 */
/* @0x1dee18 .word 0xfffff0a0 */
/* @0x1dee1c ldrheq r2, [r7], -r4 */
/* @0x1dee20 mulseq r7, r4, r12 */
/* @0x1dee24 ldrheq r2, [r7], -r12 */
/* @0x1dee28 .word 0xfffff0a4 */
/* @0x1dee2c .word 0xfffff0a8 */
/* @0x1dee30 .word 0xffffbac4 */
/* @0x1dee34 andseq r2, r7, r4, lsl #24 */
/* @0x1dee38 .word 0xffffc7dc */

/* ── FUNC 0x1dee3c · RunnerGetWADSize() · size=8 · insn=2 */
/* @0x1dee3c mov r0, #0 */
/* @0x1dee40 bx lr */

/* ── FUNC 0x1dee44 · OverwriteGameINIKey(IniFile*, IniFile*, char const*, char const*) · size=64 · insn=16 */
/* @0x1dee44 push {r4, r5, r6, lr} */
/* @0x1dee48 mov r4, r2 */
/* @0x1dee4c mov r6, r0 */
/* @0x1dee50 mov r2, r3 */
/* @0x1dee54 mov r0, r1 */
/* @0x1dee58 mov r1, r4 */
/* @0x1dee5c mov r5, r3 */
/* @0x1dee60 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x1dee64 subs r3, r0, #0 */
/* @0x1dee68 popeq {r4, r5, r6, pc} */
/* @0x1dee6c mov r0, r6 */
/* @0x1dee70 mov r1, r4 */
/* @0x1dee74 mov r2, r5 */
/* @0x1dee78 ldr r3, [r3, #0x8] */
/* @0x1dee7c pop {r4, r5, r6, lr} */
/* @0x1dee80 b 0x235edc <_ZN7IniFile6SetKeyEPKcS1_S1_> */

/* ── FUNC 0x1dee84 · OverwriteGameINI(IniFile*, IniFile*) · size=132 · insn=33 */
/* @0x1dee84 push {r4, r5, r6, lr} */
/* @0x1dee88 mov r6, r0 */
/* @0x1dee8c ldr r4, [pc, #0x60] */
/* @0x1dee90 mov r5, r1 */
/* @0x1dee94 ldr r3, [pc, #0x5c] */
/* @0x1dee98 add r4, pc, r4 */
/* @0x1dee9c add r3, pc, r3 */
/* @0x1deea0 mov r2, r4 */
/* @0x1deea4 bl 0x1dee44 <_Z19OverwriteGameINIKeyP7IniFileS0_PKcS2_> */
/* @0x1deea8 ldr r3, [pc, #0x4c] */
/* @0x1deeac mov r0, r6 */
/* @0x1deeb0 mov r1, r5 */
/* @0x1deeb4 mov r2, r4 */
/* @0x1deeb8 add r3, pc, r3 */
/* @0x1deebc bl 0x1dee44 <_Z19OverwriteGameINIKeyP7IniFileS0_PKcS2_> */
/* @0x1deec0 ldr r3, [pc, #0x38] */
/* @0x1deec4 mov r0, r6 */
/* @0x1deec8 mov r1, r5 */
/* @0x1deecc mov r2, r4 */
/* @0x1deed0 add r3, pc, r3 */
/* @0x1deed4 bl 0x1dee44 <_Z19OverwriteGameINIKeyP7IniFileS0_PKcS2_> */
/* @0x1deed8 ldr r3, [pc, #0x24] */
/* @0x1deedc mov r0, r6 */
/* @0x1deee0 mov r1, r5 */
/* @0x1deee4 mov r2, r4 */
/* @0x1deee8 add r3, pc, r3 */
/* @0x1deeec pop {r4, r5, r6, lr} */
/* @0x1deef0 b 0x1dee44 <_Z19OverwriteGameINIKeyP7IniFileS0_PKcS2_> */
/* @0x1deef4 andseq r2, r7, r12, asr r9 */
/* @0x1deef8 andseq r2, r7, r0, asr #19 */
/* @0x1deefc ldrheq r2, [r7], -r4 */
/* @0x1def00 ldrheq r2, [r7], -r4 */
/* @0x1def04 andseq r2, r7, r12, lsr #19 */

/* ── FUNC 0x1def08 · RunnerLoadGame() · size=1684 · insn=421 */
/* @0x1def08 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1def0c sub sp, sp, #1040 */
/* @0x1def10 ldr r10, [pc, #0x5f4] */
/* @0x1def14 sub sp, sp, #12 */
/* @0x1def18 ldr r1, [pc, #0x5f0] */
/* @0x1def1c add r10, pc, r10 */
/* @0x1def20 ldr r2, [pc, #0x5ec] */
/* @0x1def24 ldr r3, [pc, #0x5ec] */
/* @0x1def28 ldr r1, [r10, r1] */
/* @0x1def2c str r1, [sp, #0x4] */
/* @0x1def30 ldr r12, [sp, #0x4] */
/* @0x1def34 ldr r1, [pc, #0x5e0] */
/* @0x1def38 ldr r0, [r12] */
/* @0x1def3c add r1, pc, r1 */
/* @0x1def40 str r0, [sp, #0x414] */
/* @0x1def44 ldr r2, [r10, r2] */
/* @0x1def48 ldr r4, [r2] */
/* @0x1def4c str r2, [sp, #0x8] */
/* @0x1def50 ldr r7, [r10, r3] */
/* @0x1def54 ldr r3, [r4] */
/* @0x1def58 mov r0, r4 */
/* @0x1def5c ldr r2, [r7] */
/* @0x1def60 ldr r3, [r3, #0xc] */
/* @0x1def64 blx r3 */
/* @0x1def68 ldr r3, [pc, #0x5b0] */
/* @0x1def6c ldr r3, [r10, r3] */
/* @0x1def70 str r3, [sp] */
/* @0x1def74 ldr r3, [r3] */
/* @0x1def78 cmp r3, #0 */
/* @0x1def7c beq 0x1df260 <_Z14RunnerLoadGamev+0x358> */
/* @0x1def80 ldr r3, [r3] */
/* @0x1def84 cmp r3, #0 */
/* @0x1def88 beq 0x1df260 <_Z14RunnerLoadGamev+0x358> */
/* @0x1def8c ldr r0, [pc, #0x590] */
/* @0x1def90 mov r12, #1 */
/* @0x1def94 str r12, [sp, #0xc] */
/* @0x1def98 add r0, pc, r0 */
/* @0x1def9c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1defa0 ldr r3, [pc, #0x580] */
/* @0x1defa4 ldr r9, [r10, r3] */
/* @0x1defa8 mov r5, r0 */
/* @0x1defac str r0, [r7] */
/* @0x1defb0 str r0, [r9] */
/* @0x1defb4 bl 0x1fd150 <_Z19SetWorkingDirectoryv> */
/* @0x1defb8 mov r0, r5 */
/* @0x1defbc bl 0xb6538 <strlen@plt> */
/* @0x1defc0 ldr r1, [pc, #0x564] */
/* @0x1defc4 movw r2, #0x8e3 */
/* @0x1defc8 mov r3, #1 */
/* @0x1defcc add r1, pc, r1 */
/* @0x1defd0 add r8, r0, #12 */
/* @0x1defd4 mov r0, r8 */
/* @0x1defd8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1defdc mov r1, r5 */
/* @0x1defe0 mov r6, r0 */
/* @0x1defe4 bl 0xb65a4 <strcpy@plt> */
/* @0x1defe8 mov r0, r6 */
/* @0x1defec mov r1, #47 */
/* @0x1deff0 bl 0xb6868 <strrchr@plt> */
/* @0x1deff4 subs r11, r0, #0 */
/* @0x1deff8 beq 0x1df3d4 <_Z14RunnerLoadGamev+0x4cc> */
/* @0x1deffc ldr lr, [r4] */
/* @0x1df000 mov r0, r4 */
/* @0x1df004 ldr r1, [pc, #0x524] */
/* @0x1df008 ldr r2, [r9] */
/* @0x1df00c add r1, pc, r1 */
/* @0x1df010 ldr r9, [lr, #0xc] */
/* @0x1df014 blx r9 */
/* @0x1df018 ldr lr, [pc, #0x514] */
/* @0x1df01c add lr, pc, lr */
/* @0x1df020 ldm lr!, {r0, r1, r2} */
/* @0x1df024 ldrb lr, [lr] */
/* @0x1df028 str r0, [r11] */
/* @0x1df02c mov r0, r4 */
/* @0x1df030 str r1, [r11, #0x4] */
/* @0x1df034 strb lr, [r11, #0xc] */
/* @0x1df038 str r2, [r11, #0x8] */
/* @0x1df03c mov r2, r6 */
/* @0x1df040 ldr r3, [r4] */
/* @0x1df044 ldr r1, [pc, #0x4ec] */
/* @0x1df048 ldr r3, [r3, #0xc] */
/* @0x1df04c add r1, pc, r1 */
/* @0x1df050 blx r3 */
/* @0x1df054 mov r0, r6 */
/* @0x1df058 bl 0x214e48 <_Z10FileExistsPKc> */
/* @0x1df05c cmp r0, #0 */
/* @0x1df060 bne 0x1df1d4 <_Z14RunnerLoadGamev+0x2cc> */
/* @0x1df064 ldr lr, [pc, #0x4d0] */
/* @0x1df068 movw r2, #0x917 */
/* @0x1df06c ldr r1, [pc, #0x4cc] */
/* @0x1df070 mov r3, #1 */
/* @0x1df074 mov r0, r8 */
/* @0x1df078 ldr lr, [r10, lr] */
/* @0x1df07c add r1, pc, r1 */
/* @0x1df080 str r6, [lr] */
/* @0x1df084 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1df088 mov r1, r5 */
/* @0x1df08c mov r6, r0 */
/* @0x1df090 bl 0xb65a4 <strcpy@plt> */
/* @0x1df094 mov r0, r6 */
/* @0x1df098 mov r1, #46 */
/* @0x1df09c bl 0xb6868 <strrchr@plt> */
/* @0x1df0a0 subs r2, r0, #0 */
/* @0x1df0a4 beq 0x1df0d4 <_Z14RunnerLoadGamev+0x1cc> */
/* @0x1df0a8 ldr r3, [pc, #0x494] */
/* @0x1df0ac add r3, pc, r3 */
/* @0x1df0b0 ldm r3!, {r0, r1} */
/* @0x1df0b4 ldrb r3, [r3] */
/* @0x1df0b8 str r0, [r2] */
/* @0x1df0bc mov r0, r6 */
/* @0x1df0c0 str r1, [r2, #0x4] */
/* @0x1df0c4 strb r3, [r2, #0x8] */
/* @0x1df0c8 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1df0cc cmp r0, #0 */
/* @0x1df0d0 bne 0x1df198 <_Z14RunnerLoadGamev+0x290> */
/* @0x1df0d4 ldr r2, [pc, #0x46c] */
/* @0x1df0d8 mov r3, #0 */
/* @0x1df0dc ldr lr, [pc, #0x468] */
/* @0x1df0e0 mov r0, r4 */
/* @0x1df0e4 ldr r1, [pc, #0x464] */
/* @0x1df0e8 ldr r8, [r10, r2] */
/* @0x1df0ec mov r2, r5 */
/* @0x1df0f0 add r1, pc, r1 */
/* @0x1df0f4 str r6, [r8] */
/* @0x1df0f8 ldr r6, [r10, lr] */
/* @0x1df0fc ldr lr, [r4] */
/* @0x1df100 str r3, [r6] */
/* @0x1df104 ldr r3, [lr, #0xc] */
/* @0x1df108 blx r3 */
/* @0x1df10c ldr r12, [sp] */
/* @0x1df110 ldr r3, [r12] */
/* @0x1df114 cmp r3, #0 */
/* @0x1df118 beq 0x1df30c <_Z14RunnerLoadGamev+0x404> */
/* @0x1df11c ldr r2, [r3] */
/* @0x1df120 cmp r2, #0 */
/* @0x1df124 beq 0x1df30c <_Z14RunnerLoadGamev+0x404> */
/* @0x1df128 ldr r0, [r3, #0x4] */
/* @0x1df12c mov r3, r2 */
/* @0x1df130 ldr r1, [pc, #0x41c] */
/* @0x1df134 str r0, [r6] */
/* @0x1df138 ldr r8, [r10, r1] */
/* @0x1df13c str r2, [r8] */
/* @0x1df140 ldr r2, [r3] */
/* @0x1df144 movw r1, #0x524d */
/* @0x1df148 movw r3, #0x4f46 */
/* @0x1df14c movt r1, #0x464f */
/* @0x1df150 movt r3, #0x4d52 */
/* @0x1df154 cmp r2, r3 */
/* @0x1df158 cmpne r2, r1 */
/* @0x1df15c beq 0x1df2e0 <_Z14RunnerLoadGamev+0x3d8> */
/* @0x1df160 ldr r3, [pc, #0x3f0] */
/* @0x1df164 ldr r4, [r10, r3] */
/* @0x1df168 ldr r3, [r4] */
/* @0x1df16c cmp r3, #0 */
/* @0x1df170 beq 0x1df40c <_Z14RunnerLoadGamev+0x504> */
/* @0x1df174 ldr r12, [sp, #0x4] */
/* @0x1df178 mov r0, #0 */
/* @0x1df17c ldr r2, [sp, #0x414] */
/* @0x1df180 ldr r3, [r12] */
/* @0x1df184 cmp r2, r3 */
/* @0x1df188 bne 0x1df500 <_Z14RunnerLoadGamev+0x5f8> */
/* @0x1df18c add sp, sp, #1040 */
/* @0x1df190 add sp, sp, #12 */
/* @0x1df194 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1df198 add r1, sp, #16 */
/* @0x1df19c mov r0, r6 */
/* @0x1df1a0 mov r3, #0 */
/* @0x1df1a4 str r3, [sp, #0x10] */
/* @0x1df1a8 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x1df1ac ldr r1, [pc, #0x3a8] */
/* @0x1df1b0 ldr r2, [pc, #0x3a8] */
/* @0x1df1b4 ldr r3, [sp, #0x10] */
/* @0x1df1b8 ldr lr, [r10, r1] */
/* @0x1df1bc mov r1, r3 */
/* @0x1df1c0 str r0, [lr] */
/* @0x1df1c4 ldr r2, [r10, r2] */
/* @0x1df1c8 str r3, [r2] */
/* @0x1df1cc bl 0x1de7b0 <_Z13LoadDebugInfoPvj> */
/* @0x1df1d0 b 0x1df0d4 <_Z14RunnerLoadGamev+0x1cc> */
/* @0x1df1d4 ldr r3, [r4] */
/* @0x1df1d8 mov r2, r6 */
/* @0x1df1dc ldr r1, [pc, #0x380] */
/* @0x1df1e0 mov r0, r4 */
/* @0x1df1e4 add r1, pc, r1 */
/* @0x1df1e8 ldr r3, [r3, #0xc] */
/* @0x1df1ec blx r3 */
/* @0x1df1f0 mov r0, #28 */
/* @0x1df1f4 bl 0x27c524 <_Znwj> */
/* @0x1df1f8 mov r2, #1 */
/* @0x1df1fc mov r1, r6 */
/* @0x1df200 mov r11, r0 */
/* @0x1df204 bl 0x2362b8 <_ZN7IniFileC2EPcb> */
/* @0x1df208 ldr r2, [pc, #0x358] */
/* @0x1df20c cmp r11, #0 */
/* @0x1df210 ldr r9, [r10, r2] */
/* @0x1df214 beq 0x1df238 <_Z14RunnerLoadGamev+0x330> */
/* @0x1df218 ldr r0, [r9] */
/* @0x1df21c cmp r0, #0 */
/* @0x1df220 beq 0x1df238 <_Z14RunnerLoadGamev+0x330> */
/* @0x1df224 ldr r2, [pc, #0x340] */
/* @0x1df228 ldr r2, [r10, r2] */
/* @0x1df22c ldrb r2, [r2] */
/* @0x1df230 cmp r2, #0 */
/* @0x1df234 bne 0x1df4c8 <_Z14RunnerLoadGamev+0x5c0> */
/* @0x1df238 mov r0, r11 */
/* @0x1df23c str r11, [r9] */
/* @0x1df240 bl 0x18cd20 <_Z8IO_SetupP7IniFile> */
/* @0x1df244 ldr r0, [r9] */
/* @0x1df248 bl 0x18f6bc <_ZN8LoadSave5SetUpEP7IniFile> */
/* @0x1df24c ldr r0, [r9] */
/* @0x1df250 bl 0x221374 <_Z11Sound_SetupP7IniFile> */
/* @0x1df254 ldr r0, [r9] */
/* @0x1df258 bl 0x1de984 <_Z14Platform_SetupP7IniFile> */
/* @0x1df25c b 0x1df064 <_Z14RunnerLoadGamev+0x15c> */
/* @0x1df260 ldr r3, [r7] */
/* @0x1df264 cmp r3, #0 */
/* @0x1df268 beq 0x1df278 <_Z14RunnerLoadGamev+0x370> */
/* @0x1df26c ldrb r3, [r3] */
/* @0x1df270 cmp r3, #0 */
/* @0x1df274 bne 0x1df41c <_Z14RunnerLoadGamev+0x514> */
/* @0x1df278 ldr r3, [pc, #0x2f0] */
/* @0x1df27c ldr r3, [r10, r3] */
/* @0x1df280 ldrb r3, [r3] */
/* @0x1df284 cmp r3, #0 */
/* @0x1df288 beq 0x1df49c <_Z14RunnerLoadGamev+0x594> */
/* @0x1df28c ldr r3, [pc, #0x2d8] */
/* @0x1df290 ldr r3, [r10, r3] */
/* @0x1df294 ldrb r3, [r3] */
/* @0x1df298 cmp r3, #0 */
/* @0x1df29c beq 0x1df504 <_Z14RunnerLoadGamev+0x5fc> */
/* @0x1df2a0 bl 0x10c320 <_Z14YYGML_game_endv> */
/* @0x1df2a4 ldr r3, [pc, #0x27c] */
/* @0x1df2a8 mov r12, #1 */
/* @0x1df2ac str r12, [sp, #0xc] */
/* @0x1df2b0 mov r5, #0 */
/* @0x1df2b4 ldr r9, [r10, r3] */
/* @0x1df2b8 ldr r3, [r4] */
/* @0x1df2bc mov r0, r4 */
/* @0x1df2c0 ldr r1, [pc, #0x2ac] */
/* @0x1df2c4 mov r2, r5 */
/* @0x1df2c8 add r1, pc, r1 */
/* @0x1df2cc ldr r3, [r3, #0xc] */
/* @0x1df2d0 blx r3 */
/* @0x1df2d4 str r5, [r9] */
/* @0x1df2d8 str r5, [r7] */
/* @0x1df2dc b 0x1defb4 <_Z14RunnerLoadGamev+0xac> */
/* @0x1df2e0 ldr r12, [sp, #0x8] */
/* @0x1df2e4 ldr r1, [pc, #0x28c] */
/* @0x1df2e8 ldr r0, [r12] */
/* @0x1df2ec add r1, pc, r1 */
/* @0x1df2f0 ldr r3, [r0] */
/* @0x1df2f4 ldr r3, [r3, #0xc] */
/* @0x1df2f8 blx r3 */
/* @0x1df2fc ldr r0, [r8] */
/* @0x1df300 ldr r1, [r6] */
/* @0x1df304 bl 0x1dfb7c <_Z10DecryptWadPci> */
/* @0x1df308 b 0x1df160 <_Z14RunnerLoadGamev+0x258> */
/* @0x1df30c ldr r0, [pc, #0x268] */
/* @0x1df310 add r0, pc, r0 */
/* @0x1df314 bl 0x27b948 <_Z17memLogPushContextPKc> */
/* @0x1df318 ldr r12, [sp, #0xc] */
/* @0x1df31c mov r0, r5 */
/* @0x1df320 mov r1, r6 */
/* @0x1df324 cmp r12, #0 */
/* @0x1df328 bne 0x1df3cc <_Z14RunnerLoadGamev+0x4c4> */
/* @0x1df32c bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0x1df330 ldr r3, [pc, #0x21c] */
/* @0x1df334 ldr r8, [r10, r3] */
/* @0x1df338 str r0, [r8] */
/* @0x1df33c bl 0x27b94c <_Z16memLogPopContextv> */
/* @0x1df340 ldr r3, [r8] */
/* @0x1df344 cmp r3, #0 */
/* @0x1df348 beq 0x1df4d8 <_Z14RunnerLoadGamev+0x5d0> */
/* @0x1df34c ldr lr, [r4] */
/* @0x1df350 mov r0, r4 */
/* @0x1df354 ldr r1, [pc, #0x224] */
/* @0x1df358 mov r2, r5 */
/* @0x1df35c ldr r3, [r6] */
/* @0x1df360 add r1, pc, r1 */
/* @0x1df364 ldr r4, [lr, #0xc] */
/* @0x1df368 blx r4 */
/* @0x1df36c ldr r2, [pc, #0x210] */
/* @0x1df370 ldr r3, [r8] */
/* @0x1df374 ldr r1, [r6] */
/* @0x1df378 ldr r2, [r10, r2] */
/* @0x1df37c cmp r3, #0 */
/* @0x1df380 add r1, r1, #128 */
/* @0x1df384 str r1, [r2] */
/* @0x1df388 bne 0x1df140 <_Z14RunnerLoadGamev+0x238> */
/* @0x1df38c add r4, sp, #20 */
/* @0x1df390 ldr r2, [pc, #0x1f0] */
/* @0x1df394 ldr r3, [r7] */
/* @0x1df398 mov r1, #1024 */
/* @0x1df39c add r2, pc, r2 */
/* @0x1df3a0 mov r0, r4 */
/* @0x1df3a4 bl 0xb65c8 <snprintf@plt> */
/* @0x1df3a8 mov r0, r4 */
/* @0x1df3ac bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x1df3b0 ldr r3, [pc, #0x1b4] */
/* @0x1df3b4 ldr r3, [r10, r3] */
/* @0x1df3b8 ldrb r3, [r3] */
/* @0x1df3bc cmp r3, #0 */
/* @0x1df3c0 beq 0x1df504 <_Z14RunnerLoadGamev+0x5fc> */
/* @0x1df3c4 bl 0x10c320 <_Z14YYGML_game_endv> */
/* @0x1df3c8 b 0x1df160 <_Z14RunnerLoadGamev+0x258> */
/* @0x1df3cc bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x1df3d0 b 0x1df330 <_Z14RunnerLoadGamev+0x428> */
/* @0x1df3d4 mov r1, #92 */
/* @0x1df3d8 mov r0, r6 */
/* @0x1df3dc bl 0xb6868 <strrchr@plt> */
/* @0x1df3e0 ldr lr, [r4] */
/* @0x1df3e4 ldr r1, [pc, #0x1a0] */
/* @0x1df3e8 ldr r2, [r9] */
/* @0x1df3ec add r1, pc, r1 */
/* @0x1df3f0 ldr r9, [lr, #0xc] */
/* @0x1df3f4 mov r11, r0 */
/* @0x1df3f8 mov r0, r4 */
/* @0x1df3fc blx r9 */
/* @0x1df400 cmp r11, #0 */
/* @0x1df404 beq 0x1df064 <_Z14RunnerLoadGamev+0x15c> */
/* @0x1df408 b 0x1df018 <_Z14RunnerLoadGamev+0x110> */
/* @0x1df40c ldr r0, [r7] */
/* @0x1df410 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1df414 str r0, [r4] */
/* @0x1df418 b 0x1df174 <_Z14RunnerLoadGamev+0x26c> */
/* @0x1df41c bl 0x28fd5c <_Z14GetFilePrePendv> */
/* @0x1df420 mov r5, r0 */
/* @0x1df424 ldr r0, [r7] */
/* @0x1df428 bl 0xb6538 <strlen@plt> */
/* @0x1df42c mov r6, r0 */
/* @0x1df430 mov r0, r5 */
/* @0x1df434 bl 0xb6538 <strlen@plt> */
/* @0x1df438 mov r3, #1 */
/* @0x1df43c ldr r1, [pc, #0x14c] */
/* @0x1df440 movw r2, #0x8ab */
/* @0x1df444 add r1, pc, r1 */
/* @0x1df448 add r0, r6, r0 */
/* @0x1df44c add r6, r0, r3 */
/* @0x1df450 mov r0, r6 */
/* @0x1df454 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1df458 ldr r2, [pc, #0xc8] */
/* @0x1df45c ldr r3, [r7] */
/* @0x1df460 ldr r9, [r10, r2] */
/* @0x1df464 str r3, [r9] */
/* @0x1df468 mov r5, r0 */
/* @0x1df46c bl 0x1fd150 <_Z19SetWorkingDirectoryv> */
/* @0x1df470 ldr r0, [r7] */
/* @0x1df474 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1df478 mov r1, r6 */
/* @0x1df47c ldr r2, [r7] */
/* @0x1df480 subs r11, r0, #0 */
/* @0x1df484 mov r0, r5 */
/* @0x1df488 beq 0x1df4bc <_Z14RunnerLoadGamev+0x5b4> */
/* @0x1df48c mov r12, #1 */
/* @0x1df490 str r12, [sp, #0xc] */
/* @0x1df494 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x1df498 b 0x1df2b8 <_Z14RunnerLoadGamev+0x3b0> */
/* @0x1df49c bl 0x1dfb80 <_Z13YYGetFileNamev> */
/* @0x1df4a0 subs r5, r0, #0 */
/* @0x1df4a4 beq 0x1df28c <_Z14RunnerLoadGamev+0x384> */
/* @0x1df4a8 ldr r3, [pc, #0x78] */
/* @0x1df4ac mov r12, #1 */
/* @0x1df4b0 str r12, [sp, #0xc] */
/* @0x1df4b4 ldr r9, [r10, r3] */
/* @0x1df4b8 b 0x1df2b8 <_Z14RunnerLoadGamev+0x3b0> */
/* @0x1df4bc str r11, [sp, #0xc] */
/* @0x1df4c0 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1df4c4 b 0x1df2b8 <_Z14RunnerLoadGamev+0x3b0> */
/* @0x1df4c8 mov r1, r11 */
/* @0x1df4cc bl 0x1dee84 <_Z16OverwriteGameINIP7IniFileS0_> */
/* @0x1df4d0 ldr r0, [r9] */
/* @0x1df4d4 b 0x1df240 <_Z14RunnerLoadGamev+0x338> */
/* @0x1df4d8 ldr r3, [pc, #0xb4] */
/* @0x1df4dc mov r2, r5 */
/* @0x1df4e0 ldr r1, [pc, #0xb0] */
/* @0x1df4e4 ldr r3, [r10, r3] */
/* @0x1df4e8 add r1, pc, r1 */
/* @0x1df4ec ldr r0, [r3] */
/* @0x1df4f0 ldr r3, [r0] */
/* @0x1df4f4 ldr r3, [r3, #0xc] */
/* @0x1df4f8 blx r3 */
/* @0x1df4fc b 0x1df36c <_Z14RunnerLoadGamev+0x464> */
/* @0x1df500 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1df504 mov r0, #1 */
/* @0x1df508 bl 0xb6688 <exit@plt> */
/* @0x1df50c eoreq r2, r1, r4, lsr sp */
/* @0x1df510 .word 0xffffbd00 */
/* @0x1df514 .word 0xffffdecc */
/* @0x1df518 .word 0xffffeed0 */
/* @0x1df51c ldrheq r2, [r7], -r8 */
/* @0x1df520 .word 0xffffbef0 */
/* @0x1df524 andseq r2, r7, r8, lsl #19 */
/* @0x1df528 .word 0xfffff0ac */
/* @0x1df52c andseq r2, r7, r8, asr r8 */
/* @0x1df530 andseq r2, r7, r8, lsr #18 */
/* @0x1df534 andseq r2, r7, r12, lsr r9 */
/* @0x1df538 andseq r2, r7, r12, lsl r9 */
/* @0x1df53c .word 0xfffff0b0 */
/* @0x1df540 andseq r2, r7, r8, lsr #15 */
/* @0x1df544 andseq r2, r7, r0, lsl #18 */
/* @0x1df548 .word 0xfffff0b4 */
/* @0x1df54c .word 0xfffff0b8 */
/* @0x1df550 andseq r2, r7, r8, asr #17 */
/* @0x1df554 .word 0xfffff0bc */
/* @0x1df558 .word 0xffffdf5c */
/* @0x1df55c .word 0xfffff0c0 */
/* @0x1df560 .word 0xfffff0c4 */
/* @0x1df564 andseq r2, r7, r8, lsr #15 */
/* @0x1df568 .word 0xfffff0c8 */
/* @0x1df56c .word 0xffffbfe0 */
/* @0x1df570 .word 0xfffff0cc */
/* @0x1df574 andseq r2, r7, r0, asr #12 */
/* @0x1df578 andseq r2, r7, r8, lsl r7 */
/* @0x1df57c ldrheq r2, [r7], -r12 */
/* @0x1df580 andseq r2, r7, r8, ror r6 */
/* @0x1df584 .word 0xffffe78c */
/* @0x1df588 andseq r2, r7, r8, ror r6 */
/* @0x1df58c andseq r2, r7, r8, asr #10 */
/* @0x1df590 andseq r2, r7, r0, ror #7 */
/* @0x1df594 .word 0xffffbcf0 */
/* @0x1df598 andseq r2, r7, r4, lsl #10 */

/* ── FUNC 0x1df59c · RunnerLoadWad() · size=84 · insn=21 */
/* @0x1df59c push {r3, lr} */
/* @0x1df5a0 ldr r3, [pc, #0x38] */
/* @0x1df5a4 ldr r1, [pc, #0x38] */
/* @0x1df5a8 ldr r3, [pc, r3] */
/* @0x1df5ac add r1, pc, r1 */
/* @0x1df5b0 ldr r0, [r3] */
/* @0x1df5b4 ldr r3, [r0] */
/* @0x1df5b8 ldr r3, [r3, #0xc] */
/* @0x1df5bc blx r3 */
/* @0x1df5c0 ldr r2, [pc, #0x20] */
/* @0x1df5c4 ldr r3, [pc, #0x20] */
/* @0x1df5c8 ldr r2, [pc, r2] */
/* @0x1df5cc ldr r3, [pc, r3] */
/* @0x1df5d0 ldr r0, [r2] */
/* @0x1df5d4 ldr r1, [r3] */
/* @0x1df5d8 pop {r3, lr} */
/* @0x1df5dc b 0x1ddce4 <_Z12LoadGameDataPvj> */
/* @0x1df5e0 eoreq r0, r1, r4, ror r5 */
/* @0x1df5e4 andseq r2, r7, r4, lsl #9 */
/* @0x1df5e8 eoreq r1, r1, r4, asr #14 */
/* @0x1df5ec eoreq r1, r1, r12, lsr r7 */

/* ── FUNC 0x1df5f0 · InitGraphics() · size=292 · insn=73 */
/* @0x1df5f0 push {r3, r4, r5, lr} */
/* @0x1df5f4 ldr r4, [pc, #0xec] */
/* @0x1df5f8 ldr r3, [pc, #0xec] */
/* @0x1df5fc add r4, pc, r4 */
/* @0x1df600 ldr r3, [r4, r3] */
/* @0x1df604 ldrb r3, [r3] */
/* @0x1df608 cmp r3, #0 */
/* @0x1df60c bne 0x1df6d0 <_Z12InitGraphicsv+0xe0> */
/* @0x1df610 ldr r3, [pc, #0xd8] */
/* @0x1df614 ldr r1, [pc, #0xd8] */
/* @0x1df618 ldr r3, [r4, r3] */
/* @0x1df61c add r1, pc, r1 */
/* @0x1df620 ldr r5, [r3] */
/* @0x1df624 ldr r3, [r5] */
/* @0x1df628 mov r0, r5 */
/* @0x1df62c ldr r3, [r3, #0xc] */
/* @0x1df630 blx r3 */
/* @0x1df634 ldr r0, [pc, #0xbc] */
/* @0x1df638 ldr r1, [pc, #0xbc] */
/* @0x1df63c ldr r2, [pc, #0xbc] */
/* @0x1df640 ldr r3, [pc, #0xbc] */
/* @0x1df644 ldr r0, [r4, r0] */
/* @0x1df648 ldr r1, [r4, r1] */
/* @0x1df64c ldr r2, [r4, r2] */
/* @0x1df650 ldr r3, [r4, r3] */
/* @0x1df654 ldr r0, [r0] */
/* @0x1df658 ldr r1, [r1] */
/* @0x1df65c ldr r2, [r2] */
/* @0x1df660 ldr r3, [r3] */
/* @0x1df664 bl 0x16973c <_Z11GR_D3D_InitPviii> */
/* @0x1df668 subs r4, r0, #0 */
/* @0x1df66c beq 0x1df6c8 <_Z12InitGraphicsv+0xd8> */
/* @0x1df670 ldr r3, [r5] */
/* @0x1df674 mov r0, r5 */
/* @0x1df678 ldr r1, [pc, #0x88] */
/* @0x1df67c ldr r3, [r3, #0xc] */
/* @0x1df680 add r1, pc, r1 */
/* @0x1df684 blx r3 */
/* @0x1df688 bl 0xc3578 <_Z23Background_InitTexturesv> */
/* @0x1df68c ldr r3, [r5] */
/* @0x1df690 ldr r1, [pc, #0x74] */
/* @0x1df694 mov r0, r5 */
/* @0x1df698 add r1, pc, r1 */
/* @0x1df69c ldr r3, [r3, #0xc] */
/* @0x1df6a0 blx r3 */
/* @0x1df6a4 bl 0x1eedd0 <_Z19Sprite_InitTexturesv> */
/* @0x1df6a8 ldr r3, [r5] */
/* @0x1df6ac ldr r1, [pc, #0x5c] */
/* @0x1df6b0 mov r0, r5 */
/* @0x1df6b4 add r1, pc, r1 */
/* @0x1df6b8 ldr r3, [r3, #0xc] */
/* @0x1df6bc blx r3 */
/* @0x1df6c0 bl 0xfac40 <_Z17Font_InitTexturesv> */
/* @0x1df6c4 bl 0x17dd44 <_ZN8Graphics7EndInitEv> */
/* @0x1df6c8 mov r0, r4 */
/* @0x1df6cc pop {r3, r4, r5, pc} */
/* @0x1df6d0 mvn r0, #0 */
/* @0x1df6d4 mov r1, r0 */
/* @0x1df6d8 mov r2, r0 */
/* @0x1df6dc mov r3, r0 */
/* @0x1df6e0 bl 0x17db64 <_Z10DisplaySetiiii> */
/* @0x1df6e4 b 0x1df610 <_Z12InitGraphicsv+0x20> */
/* @0x1df6e8 eoreq r2, r1, r4, asr r6 */
/* @0x1df6ec .word 0xffffeab4 */
/* @0x1df6f0 .word 0xffffdecc */
/* @0x1df6f4 andseq r2, r7, r4, lsr #8 */
/* @0x1df6f8 .word 0xffffeba4 */
/* @0x1df6fc .word 0xfffff05c */
/* @0x1df700 .word 0xfffff060 */
/* @0x1df704 .word 0xfffff064 */
/* @0x1df708 ldrsbeq r2, [r7], -r0 */
/* @0x1df70c ldrsbeq r2, [r7], -r4 */
/* @0x1df710 ldrsbeq r2, [r7], -r0 */

/* ── FUNC 0x1df714 · PrepareGame() · size=504 · insn=126 */
/* @0x1df714 push {r3, r4, r5, lr} */
/* @0x1df718 ldr r3, [pc, #0x1ac] */
/* @0x1df71c ldr r1, [pc, #0x1ac] */
/* @0x1df720 ldr r3, [pc, r3] */
/* @0x1df724 add r1, pc, r1 */
/* @0x1df728 ldr r4, [r3] */
/* @0x1df72c ldr r3, [r4] */
/* @0x1df730 mov r0, r4 */
/* @0x1df734 ldr r3, [r3, #0xc] */
/* @0x1df738 blx r3 */
/* @0x1df73c bl 0xf5834 <_Z17Extension_Preparev> */
/* @0x1df740 subs r5, r0, #0 */
/* @0x1df744 beq 0x1df870 <_Z11PrepareGamev+0x15c> */
/* @0x1df748 ldr r3, [r4] */
/* @0x1df74c mov r0, r4 */
/* @0x1df750 ldr r1, [pc, #0x17c] */
/* @0x1df754 ldr r3, [r3, #0xc] */
/* @0x1df758 add r1, pc, r1 */
/* @0x1df75c blx r3 */
/* @0x1df760 bl 0xf1b44 <_Z21Code_Constant_Preparev> */
/* @0x1df764 subs r5, r0, #0 */
/* @0x1df768 beq 0x1df85c <_Z11PrepareGamev+0x148> */
/* @0x1df76c ldr r3, [r4] */
/* @0x1df770 mov r0, r4 */
/* @0x1df774 ldr r1, [pc, #0x15c] */
/* @0x1df778 ldr r3, [r3, #0xc] */
/* @0x1df77c add r1, pc, r1 */
/* @0x1df780 blx r3 */
/* @0x1df784 bl 0x1e0af0 <_Z14Script_Preparev> */
/* @0x1df788 subs r5, r0, #0 */
/* @0x1df78c beq 0x1df894 <_Z11PrepareGamev+0x180> */
/* @0x1df790 ldr r3, [r4] */
/* @0x1df794 mov r0, r4 */
/* @0x1df798 ldr r1, [pc, #0x13c] */
/* @0x1df79c ldr r3, [r3, #0xc] */
/* @0x1df7a0 add r1, pc, r1 */
/* @0x1df7a4 blx r3 */
/* @0x1df7a8 bl 0x1f2c80 <_Z16TimeLine_Preparev> */
/* @0x1df7ac subs r5, r0, #0 */
/* @0x1df7b0 beq 0x1df884 <_Z11PrepareGamev+0x170> */
/* @0x1df7b4 ldr r3, [r4] */
/* @0x1df7b8 mov r0, r4 */
/* @0x1df7bc ldr r1, [pc, #0x11c] */
/* @0x1df7c0 ldr r3, [r3, #0xc] */
/* @0x1df7c4 add r1, pc, r1 */
/* @0x1df7c8 blx r3 */
/* @0x1df7cc bl 0x19ebb4 <_Z14Object_Preparev> */
/* @0x1df7d0 cmp r0, #0 */
/* @0x1df7d4 beq 0x1df8a8 <_Z11PrepareGamev+0x194> */
/* @0x1df7d8 ldr r3, [r4] */
/* @0x1df7dc mov r0, r4 */
/* @0x1df7e0 ldr r1, [pc, #0xfc] */
/* @0x1df7e4 ldr r3, [r3, #0xc] */
/* @0x1df7e8 add r1, pc, r1 */
/* @0x1df7ec blx r3 */
/* @0x1df7f0 bl 0x1b4cd0 <_Z12Room_Preparev> */
/* @0x1df7f4 cmp r0, #0 */
/* @0x1df7f8 beq 0x1df8a8 <_Z11PrepareGamev+0x194> */
/* @0x1df7fc ldr r3, [r4] */
/* @0x1df800 mov r0, r4 */
/* @0x1df804 ldr r1, [pc, #0xdc] */
/* @0x1df808 ldr r3, [r3, #0xc] */
/* @0x1df80c add r1, pc, r1 */
/* @0x1df810 blx r3 */
/* @0x1df814 bl 0x21e940 <_Z8SND_Initv> */
/* @0x1df818 bl 0x21fb80 <_Z13Sound_Preparev> */
/* @0x1df81c subs r5, r0, #0 */
/* @0x1df820 beq 0x1df8bc <_Z11PrepareGamev+0x1a8> */
/* @0x1df824 bl 0x2194e0 <_Z13Audio_Preparev> */
/* @0x1df828 ldr r3, [r4] */
/* @0x1df82c ldr r1, [pc, #0xb8] */
/* @0x1df830 mov r0, r4 */
/* @0x1df834 add r1, pc, r1 */
/* @0x1df838 ldr r3, [r3, #0xc] */
/* @0x1df83c blx r3 */
/* @0x1df840 ldr r3, [r4] */
/* @0x1df844 ldr r1, [pc, #0xa4] */
/* @0x1df848 mov r0, r4 */
/* @0x1df84c add r1, pc, r1 */
/* @0x1df850 ldr r3, [r3, #0xc] */
/* @0x1df854 blx r3 */
/* @0x1df858 b 0x1df868 <_Z11PrepareGamev+0x154> */
/* @0x1df85c ldr r0, [pc, #0x90] */
/* @0x1df860 add r0, pc, r0 */
/* @0x1df864 bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x1df868 mov r0, r5 */
/* @0x1df86c pop {r3, r4, r5, pc} */
/* @0x1df870 ldr r0, [pc, #0x80] */
/* @0x1df874 add r0, pc, r0 */
/* @0x1df878 bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x1df87c mov r0, r5 */
/* @0x1df880 pop {r3, r4, r5, pc} */
/* @0x1df884 ldr r0, [pc, #0x70] */
/* @0x1df888 add r0, pc, r0 */
/* @0x1df88c bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x1df890 b 0x1df868 <_Z11PrepareGamev+0x154> */
/* @0x1df894 ldr r0, [pc, #0x64] */
/* @0x1df898 add r0, pc, r0 */
/* @0x1df89c bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x1df8a0 mov r0, r5 */
/* @0x1df8a4 pop {r3, r4, r5, pc} */
/* @0x1df8a8 ldr r0, [pc, #0x54] */
/* @0x1df8ac mov r5, #0 */
/* @0x1df8b0 add r0, pc, r0 */
/* @0x1df8b4 bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x1df8b8 b 0x1df868 <_Z11PrepareGamev+0x154> */
/* @0x1df8bc ldr r0, [pc, #0x44] */
/* @0x1df8c0 add r0, pc, r0 */
/* @0x1df8c4 bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x1df8c8 b 0x1df868 <_Z11PrepareGamev+0x154> */
/* @0x1df8cc .word 0x002103fc */
/* @0x1df8d0 andseq r2, r7, r8, ror r3 */
/* @0x1df8d4 andseq r2, r7, r4, lsl #7 */
/* @0x1df8d8 mulseq r7, r12, r3 */
/* @0x1df8dc andseq r2, r7, r12, lsr #7 */
/* @0x1df8e0 ldrsbeq r2, [r7], -r4 */
/* @0x1df8e4 ldrsheq r2, [r7], -r4 */
/* @0x1df8e8 andseq r2, r7, r4, ror #7 */
/* @0x1df8ec ldrsheq r2, [r7], -r0 */
/* @0x1df8f0 andseq r2, r7, r12, ror #7 */
/* @0x1df8f4 mulseq r7, r8, r2 */
/* @0x1df8f8 andseq r2, r7, r0, asr #4 */
/* @0x1df8fc ldrsbeq r2, [r7], -r12 */
/* @0x1df900 mulseq r7, r4, r2 */
/* @0x1df904 ldrsheq r2, [r7], -r12 */
/* @0x1df908 andseq r2, r7, r4, asr #6 */

/* ── FUNC 0x1df90c · FINALIZE_Runner_Form() · size=200 · insn=50 */
/* @0x1df90c push {r3, r4, r5, lr} */
/* @0x1df910 bl 0x1a7be8 <_Z9Path_Quitv> */
/* @0x1df914 ldr r4, [pc, #0x98] */
/* @0x1df918 bl 0x1f241c <_Z13TimeLine_Quitv> */
/* @0x1df91c ldr r3, [pc, #0x94] */
/* @0x1df920 add r4, pc, r4 */
/* @0x1df924 ldr r5, [r4, r3] */
/* @0x1df928 ldr r0, [r5] */
/* @0x1df92c cmp r0, #0 */
/* @0x1df930 beq 0x1df940 <_Z20FINALIZE_Runner_Formv+0x34> */
/* @0x1df934 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1df938 mov r3, #0 */
/* @0x1df93c str r3, [r5] */
/* @0x1df940 ldr r3, [pc, #0x74] */
/* @0x1df944 ldr r5, [r4, r3] */
/* @0x1df948 ldr r0, [r5] */
/* @0x1df94c cmp r0, #0 */
/* @0x1df950 beq 0x1df960 <_Z20FINALIZE_Runner_Formv+0x54> */
/* @0x1df954 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1df958 mov r3, #0 */
/* @0x1df95c str r3, [r5] */
/* @0x1df960 ldr r3, [pc, #0x58] */
/* @0x1df964 ldr r5, [r4, r3] */
/* @0x1df968 ldr r0, [r5] */
/* @0x1df96c cmp r0, #0 */
/* @0x1df970 beq 0x1df978 <_Z20FINALIZE_Runner_Formv+0x6c> */
/* @0x1df974 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1df978 ldr r2, [pc, #0x44] */
/* @0x1df97c mov r3, #0 */
/* @0x1df980 ldr r0, [pc, #0x40] */
/* @0x1df984 str r3, [r5] */
/* @0x1df988 ldr r12, [r4, r2] */
/* @0x1df98c ldr r1, [pc, #0x38] */
/* @0x1df990 ldr r2, [pc, #0x38] */
/* @0x1df994 str r3, [r12] */
/* @0x1df998 ldr r0, [r4, r0] */
/* @0x1df99c str r3, [r0] */
/* @0x1df9a0 ldr r1, [r4, r1] */
/* @0x1df9a4 str r3, [r1] */
/* @0x1df9a8 ldr r2, [r4, r2] */
/* @0x1df9ac str r3, [r2] */
/* @0x1df9b0 pop {r3, r4, r5, pc} */
/* @0x1df9b4 eoreq r2, r1, r0, lsr r3 */
/* @0x1df9b8 .word 0xfffff0bc */
/* @0x1df9bc .word 0xffffbef0 */
/* @0x1df9c0 .word 0xfffff0c0 */
/* @0x1df9c4 .word 0xffffbf08 */
/* @0x1df9c8 .word 0xfffff098 */
/* @0x1df9cc .word 0xfffff09c */
/* @0x1df9d0 .word 0xffffbefc */

/* ── FUNC 0x1df9d4 · CheckFileCRC(char const*) · size=352 · insn=88 */
/* @0x1df9d4 push {r4, r5, r6, r7, lr} */
/* @0x1df9d8 mov r7, r0 */
/* @0x1df9dc ldr r6, [pc, #0x144] */
/* @0x1df9e0 sub sp, sp, #12 */
/* @0x1df9e4 bl 0x27de00 <_Z11InitFastCRCv> */
/* @0x1df9e8 mov r0, r7 */
/* @0x1df9ec add r6, pc, r6 */
/* @0x1df9f0 mov r1, r6 */
/* @0x1df9f4 bl 0xb6844 <fopen@plt> */
/* @0x1df9f8 subs r5, r0, #0 */
/* @0x1df9fc beq 0x1dfa4c <_Z12CheckFileCRCPKc+0x78> */
/* @0x1dfa00 mov r2, #2 */
/* @0x1dfa04 mov r1, #0 */
/* @0x1dfa08 bl 0xb68d4 <fseek@plt> */
/* @0x1dfa0c mov r0, r5 */
/* @0x1dfa10 mov r1, sp */
/* @0x1dfa14 bl 0xb6958 <fgetpos@plt> */
/* @0x1dfa18 mov r0, r5 */
/* @0x1dfa1c mvn r1, #3 */
/* @0x1dfa20 mov r2, #2 */
/* @0x1dfa24 bl 0xb68d4 <fseek@plt> */
/* @0x1dfa28 mov r3, r5 */
/* @0x1dfa2c add r0, sp, #4 */
/* @0x1dfa30 mov r1, #1 */
/* @0x1dfa34 mov r2, #4 */
/* @0x1dfa38 bl 0xb68c8 <fread@plt> */
/* @0x1dfa3c ldr r0, [sp] */
/* @0x1dfa40 cmp r0, #0 */
/* @0x1dfa44 moveq r5, r0 */
/* @0x1dfa48 bne 0x1dfa58 <_Z12CheckFileCRCPKc+0x84> */
/* @0x1dfa4c mov r0, r5 */
/* @0x1dfa50 add sp, sp, #12 */
/* @0x1dfa54 pop {r4, r5, r6, r7, pc} */
/* @0x1dfa58 mov r0, r5 */
/* @0x1dfa5c mvn r4, #0 */
/* @0x1dfa60 bl 0xb6850 <fclose@plt> */
/* @0x1dfa64 mov r1, r6 */
/* @0x1dfa68 mov r0, r7 */
/* @0x1dfa6c bl 0xb6844 <fopen@plt> */
/* @0x1dfa70 ldr r1, [pc, #0xb4] */
/* @0x1dfa74 mov r2, #78 */
/* @0x1dfa78 mov r3, #1 */
/* @0x1dfa7c add r1, pc, r1 */
/* @0x1dfa80 mov r6, r0 */
/* @0x1dfa84 mov r0, #32768 */
/* @0x1dfa88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1dfa8c ldr r7, [sp] */
/* @0x1dfa90 subs r7, r7, #4 */
/* @0x1dfa94 mov r5, r0 */
/* @0x1dfa98 beq 0x1dfafc <_Z12CheckFileCRCPKc+0x128> */
/* @0x1dfa9c cmp r7, #32768 */
/* @0x1dfaa0 movlo r2, r7 */
/* @0x1dfaa4 movhs r2, #32768 */
/* @0x1dfaa8 mov r0, r5 */
/* @0x1dfaac mov r1, #1 */
/* @0x1dfab0 mov r3, r6 */
/* @0x1dfab4 bl 0xb68c8 <fread@plt> */
/* @0x1dfab8 cmp r0, #0 */
/* @0x1dfabc beq 0x1dfaf4 <_Z12CheckFileCRCPKc+0x120> */
/* @0x1dfac0 ldr r3, [pc, #0x68] */
/* @0x1dfac4 mov r1, #0 */
/* @0x1dfac8 mov r2, r1 */
/* @0x1dfacc ldr r3, [pc, r3] */
/* @0x1dfad0 ldrb r12, [r5, r1] */
/* @0x1dfad4 add r2, r2, #1 */
/* @0x1dfad8 cmp r2, r0 */
/* @0x1dfadc eor r12, r4, r12 */
/* @0x1dfae0 mov r1, r2 */
/* @0x1dfae4 uxtb r12, r12 */
/* @0x1dfae8 ldr r12, [r3, r12, lsl #2] */
/* @0x1dfaec eor r4, r12, r4, lsr #8 */
/* @0x1dfaf0 bne 0x1dfad0 <_Z12CheckFileCRCPKc+0xfc> */
/* @0x1dfaf4 subs r7, r7, r0 */
/* @0x1dfaf8 bne 0x1dfa9c <_Z12CheckFileCRCPKc+0xc8> */
/* @0x1dfafc mov r0, r5 */
/* @0x1dfb00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1dfb04 ldr r5, [sp, #0x4] */
/* @0x1dfb08 mov r0, r6 */
/* @0x1dfb0c subs r3, r4, r5 */
/* @0x1dfb10 rsbs r5, r3, #0 */
/* @0x1dfb14 adcs r5, r5, r3 */
/* @0x1dfb18 bl 0xb6850 <fclose@plt> */
/* @0x1dfb1c mov r0, r5 */
/* @0x1dfb20 add sp, sp, #12 */
/* @0x1dfb24 pop {r4, r5, r6, r7, pc} */
/* @0x1dfb28 andseq r8, r5, r12, lsl #4 */
/* @0x1dfb2c ldrsheq r2, [r7], -r4 */
/* @0x1dfb30 eoreq r1, r1, r4, asr r2 */

/* ── FUNC 0x1dfb34 · LocalRandom(unsigned int&, unsigned int&) · size=72 · insn=18 */
/* @0x1dfb34 ldr r3, [r0] */
/* @0x1dfb38 movw r2, #0x9069 */
/* @0x1dfb3c str r4, [sp, #-0x4]! */
/* @0x1dfb40 movw r12, #0x4650 */
/* @0x1dfb44 uxth r4, r3 */
/* @0x1dfb48 lsr r3, r3, #16 */
/* @0x1dfb4c mla r2, r2, r4, r3 */
/* @0x1dfb50 ldr r4, [sp], #4 */
/* @0x1dfb54 str r2, [r0] */
/* @0x1dfb58 ldr r2, [r1] */
/* @0x1dfb5c uxth r3, r2 */
/* @0x1dfb60 lsr r2, r2, #16 */
/* @0x1dfb64 mla r3, r12, r3, r2 */
/* @0x1dfb68 str r3, [r1] */
/* @0x1dfb6c ldr r0, [r0] */
/* @0x1dfb70 lsl r0, r0, #16 */
/* @0x1dfb74 uxtah r0, r0, r3 */
/* @0x1dfb78 bx lr */

/* ── FUNC 0x1dfb7c · DecryptWad(char*, int) · size=4 · insn=1 */
/* @0x1dfb7c bx lr */

/* ── FUNC 0x1dfb80 · YYGetFileName() · size=8 · insn=2 */
/* @0x1dfb80 mov r0, #0 */
/* @0x1dfb84 bx lr */

/* ── FUNC 0x1dfb88 · Platform_SetupM(IniFile*) · size=4 · insn=1 */
/* @0x1dfb88 bx lr */
