/* libyoyo.so 覆盖卡组 0018
 * 函数 0xecd7c..0xf274c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xecd7c · Error_Show(char const*, bool) · size=500 · insn=125 */
/* @0xecd7c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xecd80 mov r6, r0 */
/* @0xecd84 ldr r4, [pc, #0x1b8] */
/* @0xecd88 mov r7, r1 */
/* @0xecd8c ldr r3, [pc, #0x1b4] */
/* @0xecd90 add r4, pc, r4 */
/* @0xecd94 ldr r8, [r4, r3] */
/* @0xecd98 ldrb r3, [r8] */
/* @0xecd9c cmp r3, #0 */
/* @0xecda0 popne {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xecda4 ldr r3, [pc, #0x1a0] */
/* @0xecda8 ldr r2, [pc, #0x1a0] */
/* @0xecdac ldr r3, [r4, r3] */
/* @0xecdb0 ldr r5, [r4, r2] */
/* @0xecdb4 ldrb r2, [r3] */
/* @0xecdb8 ldrb r3, [r5] */
/* @0xecdbc cmp r2, #0 */
/* @0xecdc0 movne r7, #1 */
/* @0xecdc4 cmp r3, #0 */
/* @0xecdc8 beq 0xece7c <_Z10Error_ShowPKcb+0x100> */
/* @0xecdcc bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0xecdd0 ldr r3, [pc, #0x17c] */
/* @0xecdd4 ldr r9, [r4, r3] */
/* @0xecdd8 ldr r5, [r9] */
/* @0xecddc cmp r5, #0 */
/* @0xecde0 beq 0xece00 <_Z10Error_ShowPKcb+0x84> */
/* @0xecde4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xecde8 ldr r10, [r5, #0x4] */
/* @0xecdec sub r10, r10, #1 */
/* @0xecdf0 str r10, [r5, #0x4] */
/* @0xecdf4 cmp r10, #0 */
/* @0xecdf8 beq 0xecedc <_Z10Error_ShowPKcb+0x160> */
/* @0xecdfc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xece00 mov r0, #12 */
/* @0xece04 bl 0x27c524 <_Znwj> */
/* @0xece08 mov r5, r0 */
/* @0xece0c subs r0, r6, #0 */
/* @0xece10 beq 0xece18 <_Z10Error_ShowPKcb+0x9c> */
/* @0xece14 bl 0xb6538 <strlen@plt> */
/* @0xece18 str r0, [r5, #0x8] */
/* @0xece1c mov r0, r6 */
/* @0xece20 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xece24 ldr r3, [pc, #0x12c] */
/* @0xece28 mov r2, #1 */
/* @0xece2c stm r5, {r0, r2} */
/* @0xece30 str r5, [r9] */
/* @0xece34 ldr r3, [r4, r3] */
/* @0xece38 ldrb r3, [r3] */
/* @0xece3c cmp r3, #0 */
/* @0xece40 beq 0xeceb4 <_Z10Error_ShowPKcb+0x138> */
/* @0xece44 ldr r2, [pc, #0x110] */
/* @0xece48 cmp r7, #0 */
/* @0xece4c mov r3, #1 */
/* @0xece50 ldr r2, [r4, r2] */
/* @0xece54 strb r3, [r2] */
/* @0xece58 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xece5c ldr r1, [pc, #0xfc] */
/* @0xece60 movw r2, #0xfe70 */
/* @0xece64 strb r3, [r8] */
/* @0xece68 movt r2, #0xffff */
/* @0xece6c ldr r3, [r4, r1] */
/* @0xece70 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xece74 str r2, [r3] */
/* @0xece78 b 0x28fe4c <_Z9Terminatev> */
/* @0xece7c bl 0x17df38 <_Z14ExitFullScreenv> */
/* @0xece80 ldrb r1, [r5] */
/* @0xece84 cmp r1, #0 */
/* @0xece88 bne 0xecdcc <_Z10Error_ShowPKcb+0x50> */
/* @0xece8c ldr r3, [pc, #0xd0] */
/* @0xece90 ldr r3, [r4, r3] */
/* @0xece94 ldrb r3, [r3] */
/* @0xece98 cmp r3, #0 */
/* @0xece9c beq 0xecdcc <_Z10Error_ShowPKcb+0x50> */
/* @0xecea0 cmp r7, #0 */
/* @0xecea4 mov r0, r6 */
/* @0xecea8 beq 0xecf34 <_Z10Error_ShowPKcb+0x1b8> */
/* @0xeceac bl 0xecb34 <_Z8ShowFormPKcb> */
/* @0xeceb0 b 0xecdcc <_Z10Error_ShowPKcb+0x50> */
/* @0xeceb4 ldr r3, [pc, #0xac] */
/* @0xeceb8 mov r2, r6 */
/* @0xecebc ldr r1, [pc, #0xa8] */
/* @0xecec0 ldr r3, [r4, r3] */
/* @0xecec4 add r1, pc, r1 */
/* @0xecec8 ldr r0, [r3] */
/* @0xececc ldr r3, [r0] */
/* @0xeced0 ldr r3, [r3, #0xc] */
/* @0xeced4 blx r3 */
/* @0xeced8 b 0xece44 <_Z10Error_ShowPKcb+0xc8> */
/* @0xecedc ldr r0, [r5] */
/* @0xecee0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xecee4 str r10, [r5] */
/* @0xecee8 str r10, [r5, #0x8] */
/* @0xeceec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xecef0 ldr r10, [r5, #0x4] */
/* @0xecef4 sub r10, r10, #1 */
/* @0xecef8 str r10, [r5, #0x4] */
/* @0xecefc cmp r10, #0 */
/* @0xecf00 bne 0xecf24 <_Z10Error_ShowPKcb+0x1a8> */
/* @0xecf04 ldr r0, [r5] */
/* @0xecf08 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xecf0c mov r0, r5 */
/* @0xecf10 str r10, [r5] */
/* @0xecf14 str r10, [r5, #0x8] */
/* @0xecf18 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xecf1c mov r0, r5 */
/* @0xecf20 bl 0x27d1d0 <_ZdlPv> */
/* @0xecf24 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xecf28 mov r0, r5 */
/* @0xecf2c bl 0x27d1d0 <_ZdlPv> */
/* @0xecf30 b 0xecdfc <_Z10Error_ShowPKcb+0x80> */
/* @0xecf34 mov r1, #1 */
/* @0xecf38 bl 0xecb34 <_Z8ShowFormPKcb> */
/* @0xecf3c mov r7, r0 */
/* @0xecf40 b 0xecdcc <_Z10Error_ShowPKcb+0x50> */
/* @0xecf44 eorseq r4, r0, r0, asr #29 */
/* @0xecf48 .word 0xffffc140 */
/* @0xecf4c .word 0xffffc144 */
/* @0xecf50 .word 0xffffc148 */
/* @0xecf54 .word 0xffffc14c */
/* @0xecf58 .word 0xffffbfdc */
/* @0xecf5c .word 0xffffc150 */
/* @0xecf60 .word 0xffffc154 */
/* @0xecf64 .word 0xffffc158 */
/* @0xecf68 .word 0xffffbcf0 */
/* @0xecf6c eoreq r7, r4, r8, lsl sp */

/* ── FUNC 0xecf70 · Error_Show_Action(char const*, bool) · size=2184 · insn=546 */
/* @0xecf70 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xecf74 sub sp, sp, #32768 */
/* @0xecf78 sub sp, sp, #124 */
/* @0xecf7c ldr r12, [pc, #0x7ec] */
/* @0xecf80 add r8, sp, #120 */
/* @0xecf84 ldr r3, [pc, #0x7e8] */
/* @0xecf88 add r12, pc, r12 */
/* @0xecf8c str r12, [sp, #0x20] */
/* @0xecf90 sub r12, r8, #4 */
/* @0xecf94 str r12, [sp, #0x38] */
/* @0xecf98 ldr r12, [sp, #0x20] */
/* @0xecf9c mov r2, #32768 */
/* @0xecfa0 str r0, [sp, #0x3c] */
/* @0xecfa4 add lr, sp, r2 */
/* @0xecfa8 str r1, [sp, #0x54] */
/* @0xecfac add r0, sp, #116 */
/* @0xecfb0 ldr r3, [r12, r3] */
/* @0xecfb4 mov r1, #0 */
/* @0xecfb8 str r3, [sp, #0x48] */
/* @0xecfbc ldr r3, [r3] */
/* @0xecfc0 str r3, [lr, #0x74] */
/* @0xecfc4 bl 0xb65b0 <memset@plt> */
/* @0xecfc8 ldr r12, [sp, #0x54] */
/* @0xecfcc cmp r12, #0 */
/* @0xecfd0 bne 0xed5c0 <_Z17Error_Show_ActionPKcb+0x650> */
/* @0xecfd4 ldr r12, [sp, #0x20] */
/* @0xecfd8 add lr, sp, #32768 */
/* @0xecfdc ldr r2, [pc, #0x794] */
/* @0xecfe0 movw r4, #0x7fe0 */
/* @0xecfe4 ldr r3, [pc, #0x790] */
/* @0xecfe8 movt r4, #0xffff */
/* @0xecfec add lr, lr, #120 */
/* @0xecff0 mov r1, #0 */
/* @0xecff4 ldr r2, [r12, r2] */
/* @0xecff8 str r1, [lr, r4] */
/* @0xecffc ldr r3, [r12, r3] */
/* @0xed000 ldr r2, [r2] */
/* @0xed004 ldr r3, [r3] */
/* @0xed008 cmp r2, r1 */
/* @0xed00c str r2, [sp, #0x34] */
/* @0xed010 add r3, r3, #1 */
/* @0xed014 str r3, [sp, #0x24] */
/* @0xed018 beq 0xed330 <_Z17Error_Show_ActionPKcb+0x3c0> */
/* @0xed01c ldr r0, [r2, #0x38] */
/* @0xed020 cmp r0, r1 */
/* @0xed024 beq 0xed668 <_Z17Error_Show_ActionPKcb+0x6f8> */
/* @0xed028 ldr r1, [r2, #0x44] */
/* @0xed02c sub r12, r8, #32 */
/* @0xed030 str r12, [sp, #0x28] */
/* @0xed034 bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi> */
/* @0xed038 ldr r12, [sp, #0x34] */
/* @0xed03c ldr r2, [sp, #0x28] */
/* @0xed040 ldr r1, [r12, #0x3c] */
/* @0xed044 str r0, [sp, #0x4c] */
/* @0xed048 bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc> */
/* @0xed04c add lr, sp, #32768 */
/* @0xed050 add lr, lr, #120 */
/* @0xed054 ldr r4, [lr, r4] */
/* @0xed058 cmp r4, #0 */
/* @0xed05c str r0, [sp, #0x50] */
/* @0xed060 beq 0xed080 <_Z17Error_Show_ActionPKcb+0x110> */
/* @0xed064 ldr r1, [pc, #0x714] */
/* @0xed068 mov r0, r4 */
/* @0xed06c mov r2, #10 */
/* @0xed070 add r1, pc, r1 */
/* @0xed074 bl 0xb65e0 <strncmp@plt> */
/* @0xed078 cmp r0, #0 */
/* @0xed07c beq 0xed55c <_Z17Error_Show_ActionPKcb+0x5ec> */
/* @0xed080 sub r8, r8, #28 */
/* @0xed084 add r12, sp, #104 */
/* @0xed088 str r12, [sp, #0x14] */
/* @0xed08c mov r4, #1 */
/* @0xed090 ldr r12, [pc, #0x6ec] */
/* @0xed094 mov r0, r8 */
/* @0xed098 ldr r5, [sp, #0x34] */
/* @0xed09c add r12, pc, r12 */
/* @0xed0a0 str r12, [sp, #0x30] */
/* @0xed0a4 bl 0xd4190 <_ZN17TErrStreamConsoleC2Ev> */
/* @0xed0a8 ldr r12, [pc, #0x6d8] */
/* @0xed0ac add r12, pc, r12 */
/* @0xed0b0 str r12, [sp, #0x40] */
/* @0xed0b4 ldr r12, [pc, #0x6d0] */
/* @0xed0b8 add r12, pc, r12 */
/* @0xed0bc str r12, [sp, #0x44] */
/* @0xed0c0 ldr r12, [pc, #0x6c8] */
/* @0xed0c4 add r12, pc, r12 */
/* @0xed0c8 str r12, [sp, #0x2c] */
/* @0xed0cc ldr r12, [pc, #0x6c0] */
/* @0xed0d0 add r12, pc, r12 */
/* @0xed0d4 str r12, [sp, #0x18] */
/* @0xed0d8 ldr r12, [pc, #0x6b8] */
/* @0xed0dc add r12, pc, r12 */
/* @0xed0e0 str r12, [sp, #0x1c] */
/* @0xed0e4 ldr r1, [r5, #0x44] */
/* @0xed0e8 ldr r0, [r5, #0x38] */
/* @0xed0ec bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi> */
/* @0xed0f0 ldr r1, [r5, #0x3c] */
/* @0xed0f4 ldr r2, [sp, #0x28] */
/* @0xed0f8 mov r6, r0 */
/* @0xed0fc bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc> */
/* @0xed100 cmp r4, #0 */
/* @0xed104 mov r7, r0 */
/* @0xed108 bne 0xed2f4 <_Z17Error_Show_ActionPKcb+0x384> */
/* @0xed10c add r0, sp, #32768 */
/* @0xed110 movw r2, #0x7fe0 */
/* @0xed114 add r0, r0, #120 */
/* @0xed118 movt r2, #0xffff */
/* @0xed11c ldr r1, [r5, #0x3c] */
/* @0xed120 ldr r2, [r0, r2] */
/* @0xed124 mov r0, r6 */
/* @0xed128 cmp r2, #0 */
/* @0xed12c ldreq r4, [r5, #0x34] */
/* @0xed130 movne r4, r2 */
/* @0xed134 bl 0xec1a8 <_ZN2VM9DebugLineEP11VMDebugInfoPKc> */
/* @0xed138 mov r3, r7 */
/* @0xed13c ldr r1, [sp, #0x30] */
/* @0xed140 mov r2, r4 */
/* @0xed144 str r0, [sp] */
/* @0xed148 mov r0, r8 */
/* @0xed14c bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz> */
/* @0xed150 add r1, sp, #32768 */
/* @0xed154 movw r3, #0x7fe0 */
/* @0xed158 add r1, r1, #120 */
/* @0xed15c movt r3, #0xffff */
/* @0xed160 ldr r0, [r1, r3] */
/* @0xed164 cmp r0, #0 */
/* @0xed168 beq 0xed170 <_Z17Error_Show_ActionPKcb+0x200> */
/* @0xed16c bl 0xb655c <free@plt> */
/* @0xed170 ldr r6, [r5, #0x4c] */
/* @0xed174 cmp r6, #0 */
/* @0xed178 ble 0xed2cc <_Z17Error_Show_ActionPKcb+0x35c> */
/* @0xed17c ldr r4, [r5, #0x28] */
/* @0xed180 movw r7, #0x7ff0 */
/* @0xed184 movt r7, #0xffff */
/* @0xed188 ldr r3, [r4, #0x18] */
/* @0xed18c cmp r3, #0 */
/* @0xed190 beq 0xed2cc <_Z17Error_Show_ActionPKcb+0x35c> */
/* @0xed194 ldr r0, [r4, #0x1c] */
/* @0xed198 cmp r0, #0 */
/* @0xed19c beq 0xed2e0 <_Z17Error_Show_ActionPKcb+0x370> */
/* @0xed1a0 ldr r1, [r4] */
/* @0xed1a4 bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi> */
/* @0xed1a8 add r2, sp, #32768 */
/* @0xed1ac add r2, r2, #120 */
/* @0xed1b0 mov r3, #0 */
/* @0xed1b4 str r3, [r2, r7] */
/* @0xed1b8 ldr r2, [sp, #0x14] */
/* @0xed1bc ldr r1, [r4, #0x20] */
/* @0xed1c0 mov r10, r0 */
/* @0xed1c4 bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc> */
/* @0xed1c8 add r12, sp, #32768 */
/* @0xed1cc ldr r1, [r4, #0x20] */
/* @0xed1d0 add r12, r12, #120 */
/* @0xed1d4 ldr r2, [r12, r7] */
/* @0xed1d8 cmp r2, #0 */
/* @0xed1dc ldreq r9, [r4, #0x24] */
/* @0xed1e0 movne r9, r2 */
/* @0xed1e4 mov r11, r0 */
/* @0xed1e8 mov r0, r10 */
/* @0xed1ec bl 0xec1a8 <_ZN2VM9DebugLineEP11VMDebugInfoPKc> */
/* @0xed1f0 mov r3, r11 */
/* @0xed1f4 mov r2, r9 */
/* @0xed1f8 ldr r1, [sp, #0x18] */
/* @0xed1fc str r0, [sp] */
/* @0xed200 mov r0, r8 */
/* @0xed204 bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz> */
/* @0xed208 add lr, sp, #32768 */
/* @0xed20c add lr, lr, #120 */
/* @0xed210 ldr r11, [lr, r7] */
/* @0xed214 cmp r11, #0 */
/* @0xed218 beq 0xed2b0 <_Z17Error_Show_ActionPKcb+0x340> */
/* @0xed21c mov r0, r11 */
/* @0xed220 ldr r1, [sp, #0x1c] */
/* @0xed224 mov r2, #10 */
/* @0xed228 bl 0xb65e0 <strncmp@plt> */
/* @0xed22c cmp r0, #0 */
/* @0xed230 bne 0xed2a8 <_Z17Error_Show_ActionPKcb+0x338> */
/* @0xed234 mov r0, r11 */
/* @0xed238 bl 0xb6538 <strlen@plt> */
/* @0xed23c ldr r12, [sp, #0x20] */
/* @0xed240 ldr r2, [pc, #0x554] */
/* @0xed244 ldr r2, [r12, r2] */
/* @0xed248 ldr r12, [r2] */
/* @0xed24c sub r0, r0, #1 */
/* @0xed250 add r2, r11, r0 */
/* @0xed254 ldrb r3, [r11, r0] */
/* @0xed258 add r3, r12, r3 */
/* @0xed25c ldrb r3, [r3, #0x1] */
/* @0xed260 tst r3, #4 */
/* @0xed264 beq 0xed288 <_Z17Error_Show_ActionPKcb+0x318> */
/* @0xed268 sub r3, r2, #1 */
/* @0xed26c mov r2, r3 */
/* @0xed270 sub r3, r3, #1 */
/* @0xed274 ldrb r1, [r2] */
/* @0xed278 add r1, r12, r1 */
/* @0xed27c ldrb r1, [r1, #0x1] */
/* @0xed280 tst r1, #4 */
/* @0xed284 bne 0xed26c <_Z17Error_Show_ActionPKcb+0x2fc> */
/* @0xed288 add r0, r2, #1 */
/* @0xed28c bl 0xb66b8 <atoi@plt> */
/* @0xed290 add lr, sp, #32768 */
/* @0xed294 add lr, lr, #120 */
/* @0xed298 ldr r11, [lr, r7] */
/* @0xed29c cmp r11, #0 */
/* @0xed2a0 str r0, [sp, #0x24] */
/* @0xed2a4 beq 0xed2b0 <_Z17Error_Show_ActionPKcb+0x340> */
/* @0xed2a8 mov r0, r11 */
/* @0xed2ac bl 0xb655c <free@plt> */
/* @0xed2b0 ldr r2, [r4, #0xc] */
/* @0xed2b4 subs r6, r6, #1 */
/* @0xed2b8 ldr r4, [r5, #0x40] */
/* @0xed2bc ldr r3, [r5, #0x8] */
/* @0xed2c0 rsb r4, r2, r4 */
/* @0xed2c4 add r4, r3, r4 */
/* @0xed2c8 bne 0xed188 <_Z17Error_Show_ActionPKcb+0x218> */
/* @0xed2cc ldr r5, [r5, #0x4] */
/* @0xed2d0 cmp r5, #0 */
/* @0xed2d4 beq 0xed350 <_Z17Error_Show_ActionPKcb+0x3e0> */
/* @0xed2d8 mov r4, #0 */
/* @0xed2dc b 0xed0e4 <_Z17Error_Show_ActionPKcb+0x174> */
/* @0xed2e0 mov r0, r8 */
/* @0xed2e4 ldr r1, [sp, #0x2c] */
/* @0xed2e8 ldr r2, [r4, #0x24] */
/* @0xed2ec bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz> */
/* @0xed2f0 b 0xed2b0 <_Z17Error_Show_ActionPKcb+0x340> */
/* @0xed2f4 mov r0, r8 */
/* @0xed2f8 ldr r1, [sp, #0x40] */
/* @0xed2fc bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz> */
/* @0xed300 add lr, sp, #32768 */
/* @0xed304 add lr, lr, #120 */
/* @0xed308 movw r3, #0x7fe0 */
/* @0xed30c movt r3, #0xffff */
/* @0xed310 mov r0, r8 */
/* @0xed314 ldr r1, [sp, #0x44] */
/* @0xed318 ldr r2, [lr, r3] */
/* @0xed31c mov r3, r7 */
/* @0xed320 cmp r2, #0 */
/* @0xed324 ldreq r2, [r5, #0x34] */
/* @0xed328 bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz> */
/* @0xed32c b 0xed150 <_Z17Error_Show_ActionPKcb+0x1e0> */
/* @0xed330 ldr r12, [sp, #0x34] */
/* @0xed334 sub r8, r8, #28 */
/* @0xed338 mov r0, r8 */
/* @0xed33c str r12, [sp, #0x4c] */
/* @0xed340 str r12, [sp, #0x50] */
/* @0xed344 add r12, sp, #104 */
/* @0xed348 str r12, [sp, #0x14] */
/* @0xed34c bl 0xd4190 <_ZN17TErrStreamConsoleC2Ev> */
/* @0xed350 ldr r3, [pc, #0x448] */
/* @0xed354 ldr r12, [sp, #0x20] */
/* @0xed358 ldr r3, [r12, r3] */
/* @0xed35c ldr r0, [r3] */
/* @0xed360 cmn r0, #1 */
/* @0xed364 beq 0xed5e0 <_Z17Error_Show_ActionPKcb+0x670> */
/* @0xed368 movw r3, #0x86a0 */
/* @0xed36c movt r3, #0x1 */
/* @0xed370 cmp r0, r3 */
/* @0xed374 beq 0xed67c <_Z17Error_Show_ActionPKcb+0x70c> */
/* @0xed378 ldr r12, [sp, #0x20] */
/* @0xed37c ldr r3, [pc, #0x420] */
/* @0xed380 ldr r3, [r12, r3] */
/* @0xed384 ldr r1, [r3] */
/* @0xed388 bl 0xf41fc <_Z14Get_Event_Nameii> */
/* @0xed38c ldr r12, [sp, #0x20] */
/* @0xed390 ldr r3, [pc, #0x410] */
/* @0xed394 ldr r3, [r12, r3] */
/* @0xed398 mov r4, r0 */
/* @0xed39c ldr r0, [r3] */
/* @0xed3a0 bl 0x19ed54 <_Z11Object_Namei> */
/* @0xed3a4 ldr r12, [sp, #0x3c] */
/* @0xed3a8 cmp r12, #0 */
/* @0xed3ac mov r3, r0 */
/* @0xed3b0 beq 0xed720 <_Z17Error_Show_ActionPKcb+0x7b0> */
/* @0xed3b4 ldr r12, [sp, #0x24] */
/* @0xed3b8 add r0, sp, #116 */
/* @0xed3bc ldr r2, [pc, #0x3e8] */
/* @0xed3c0 movw r1, #0x7fff */
/* @0xed3c4 str r3, [sp, #0x8] */
/* @0xed3c8 mov r3, r0 */
/* @0xed3cc str r12, [sp] */
/* @0xed3d0 add r2, pc, r2 */
/* @0xed3d4 ldr r12, [sp, #0x3c] */
/* @0xed3d8 str r4, [sp, #0x4] */
/* @0xed3dc str r12, [sp, #0xc] */
/* @0xed3e0 bl 0xb65c8 <snprintf@plt> */
/* @0xed3e4 ldr r0, [sp, #0x14] */
/* @0xed3e8 bl 0xd4190 <_ZN17TErrStreamConsoleC2Ev> */
/* @0xed3ec ldr r1, [pc, #0x3bc] */
/* @0xed3f0 ldr r0, [sp, #0x14] */
/* @0xed3f4 add r1, pc, r1 */
/* @0xed3f8 bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz> */
/* @0xed3fc ldr r1, [pc, #0x3b0] */
/* @0xed400 ldr r0, [sp, #0x14] */
/* @0xed404 add r2, sp, #116 */
/* @0xed408 add r1, pc, r1 */
/* @0xed40c bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz> */
/* @0xed410 ldr r12, [sp, #0x34] */
/* @0xed414 cmp r12, #0 */
/* @0xed418 beq 0xed474 <_Z17Error_Show_ActionPKcb+0x504> */
/* @0xed41c ldr r3, [r12, #0x38] */
/* @0xed420 cmp r3, #0 */
/* @0xed424 beq 0xed740 <_Z17Error_Show_ActionPKcb+0x7d0> */
/* @0xed428 add lr, sp, #32768 */
/* @0xed42c movw r3, #0x7fe0 */
/* @0xed430 add lr, lr, #120 */
/* @0xed434 movt r3, #0xffff */
/* @0xed438 ldr r0, [sp, #0x4c] */
/* @0xed43c ldr r2, [lr, r3] */
/* @0xed440 cmp r2, #0 */
/* @0xed444 ldreq r4, [r12, #0x34] */
/* @0xed448 movne r4, r2 */
/* @0xed44c ldr r12, [sp, #0x34] */
/* @0xed450 ldr r1, [r12, #0x3c] */
/* @0xed454 bl 0xec1a8 <_ZN2VM9DebugLineEP11VMDebugInfoPKc> */
/* @0xed458 ldr r1, [pc, #0x358] */
/* @0xed45c mov r2, r4 */
/* @0xed460 ldr r3, [sp, #0x50] */
/* @0xed464 add r1, pc, r1 */
/* @0xed468 str r0, [sp] */
/* @0xed46c ldr r0, [sp, #0x14] */
/* @0xed470 bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz> */
/* @0xed474 ldr r1, [pc, #0x340] */
/* @0xed478 ldr r0, [sp, #0x14] */
/* @0xed47c add r1, pc, r1 */
/* @0xed480 bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz> */
/* @0xed484 ldr r0, [sp, #0x14] */
/* @0xed488 ldr r1, [r8, #0x8] */
/* @0xed48c bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz> */
/* @0xed490 add lr, sp, #32768 */
/* @0xed494 movw r3, #0x7fe0 */
/* @0xed498 add lr, lr, #120 */
/* @0xed49c movt r3, #0xffff */
/* @0xed4a0 ldr r0, [lr, r3] */
/* @0xed4a4 cmp r0, #0 */
/* @0xed4a8 beq 0xed4b0 <_Z17Error_Show_ActionPKcb+0x540> */
/* @0xed4ac bl 0xb655c <free@plt> */
/* @0xed4b0 ldr r3, [pc, #0x308] */
/* @0xed4b4 ldr r12, [sp, #0x20] */
/* @0xed4b8 ldr r3, [r12, r3] */
/* @0xed4bc ldrb r3, [r3] */
/* @0xed4c0 cmp r3, #0 */
/* @0xed4c4 bne 0xed4d8 <_Z17Error_Show_ActionPKcb+0x568> */
/* @0xed4c8 ldr r12, [sp, #0x14] */
/* @0xed4cc ldr r1, [sp, #0x54] */
/* @0xed4d0 ldr r0, [r12, #0x8] */
/* @0xed4d4 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0xed4d8 ldr r12, [sp, #0x14] */
/* @0xed4dc add lr, sp, #32768 */
/* @0xed4e0 ldr r3, [pc, #0x2dc] */
/* @0xed4e4 add lr, lr, #120 */
/* @0xed4e8 movw r4, #0x7ff0 */
/* @0xed4ec movt r4, #0xffff */
/* @0xed4f0 ldr r0, [r12, #0x8] */
/* @0xed4f4 ldr r12, [sp, #0x20] */
/* @0xed4f8 ldr r5, [r12, r3] */
/* @0xed4fc add r5, r5, #8 */
/* @0xed500 str r5, [lr, r4] */
/* @0xed504 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xed508 ldr r12, [sp, #0x20] */
/* @0xed50c ldr r2, [pc, #0x2b4] */
/* @0xed510 add lr, sp, #32768 */
/* @0xed514 add lr, lr, #120 */
/* @0xed518 movw r3, #0x7fe4 */
/* @0xed51c movt r3, #0xffff */
/* @0xed520 ldr r0, [r8, #0x8] */
/* @0xed524 ldr r2, [r12, r2] */
/* @0xed528 str r5, [lr, r3] */
/* @0xed52c add r3, r2, #8 */
/* @0xed530 str r3, [lr, r4] */
/* @0xed534 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xed538 ldr r12, [sp, #0x48] */
/* @0xed53c add r0, sp, #32768 */
/* @0xed540 ldr r2, [r0, #0x74] */
/* @0xed544 ldr r3, [r12] */
/* @0xed548 cmp r2, r3 */
/* @0xed54c bne 0xed76c <_Z17Error_Show_ActionPKcb+0x7fc> */
/* @0xed550 add sp, sp, #32768 */
/* @0xed554 add sp, sp, #124 */
/* @0xed558 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xed55c mov r0, r4 */
/* @0xed560 bl 0xb6538 <strlen@plt> */
/* @0xed564 ldr r12, [sp, #0x20] */
/* @0xed568 ldr r3, [pc, #0x22c] */
/* @0xed56c ldr r3, [r12, r3] */
/* @0xed570 ldr r12, [r3] */
/* @0xed574 sub r0, r0, #1 */
/* @0xed578 add r2, r4, r0 */
/* @0xed57c ldrb r3, [r4, r0] */
/* @0xed580 add r3, r12, r3 */
/* @0xed584 ldrb r3, [r3, #0x1] */
/* @0xed588 tst r3, #4 */
/* @0xed58c beq 0xed5b0 <_Z17Error_Show_ActionPKcb+0x640> */
/* @0xed590 sub r3, r2, #1 */
/* @0xed594 mov r2, r3 */
/* @0xed598 sub r3, r3, #1 */
/* @0xed59c ldrb r1, [r2] */
/* @0xed5a0 add r1, r12, r1 */
/* @0xed5a4 ldrb r1, [r1, #0x1] */
/* @0xed5a8 tst r1, #4 */
/* @0xed5ac bne 0xed594 <_Z17Error_Show_ActionPKcb+0x624> */
/* @0xed5b0 add r0, r2, #1 */
/* @0xed5b4 bl 0xb66b8 <atoi@plt> */
/* @0xed5b8 str r0, [sp, #0x24] */
/* @0xed5bc b 0xed080 <_Z17Error_Show_ActionPKcb+0x110> */
/* @0xed5c0 ldr r3, [pc, #0x204] */
/* @0xed5c4 add r3, pc, r3 */
/* @0xed5c8 ldm r3, {r0, r1} */
/* @0xed5cc lsr r3, r1, #16 */
/* @0xed5d0 strb r3, [r8, #0x2] */
/* @0xed5d4 str r0, [r8, #-0x4] */
/* @0xed5d8 strh r1, [r8] */
/* @0xed5dc b 0xecfd4 <_Z17Error_Show_ActionPKcb+0x64> */
/* @0xed5e0 ldr r3, [pc, #0x1e8] */
/* @0xed5e4 ldr r3, [r12, r3] */
/* @0xed5e8 ldrb r3, [r3] */
/* @0xed5ec cmp r3, #0 */
/* @0xed5f0 beq 0xed6e4 <_Z17Error_Show_ActionPKcb+0x774> */
/* @0xed5f4 ldr lr, [pc, #0x1d8] */
/* @0xed5f8 add r12, sp, #116 */
/* @0xed5fc add lr, pc, lr */
/* @0xed600 ldm lr!, {r0, r1, r2, r3} */
/* @0xed604 stm r12!, {r0, r1, r2, r3} */
/* @0xed608 ldm lr!, {r0, r1, r2, r3} */
/* @0xed60c stm r12!, {r0, r1, r2, r3} */
/* @0xed610 ldm lr!, {r0, r1, r2, r3} */
/* @0xed614 stm r12!, {r0, r1, r2, r3} */
/* @0xed618 ldm lr, {r0, r1, r2} */
/* @0xed61c stm r12!, {r0, r1} */
/* @0xed620 strb r2, [r12] */
/* @0xed624 ldr r12, [sp, #0x3c] */
/* @0xed628 cmp r12, #0 */
/* @0xed62c beq 0xed730 <_Z17Error_Show_ActionPKcb+0x7c0> */
/* @0xed630 ldr r3, [pc, #0x1a0] */
/* @0xed634 add r0, sp, #116 */
/* @0xed638 ldr lr, [sp, #0x20] */
/* @0xed63c movw r1, #0x7fff */
/* @0xed640 ldr r2, [pc, #0x194] */
/* @0xed644 ldr r12, [lr, r3] */
/* @0xed648 add r2, pc, r2 */
/* @0xed64c ldr r3, [sp, #0x3c] */
/* @0xed650 str r3, [sp, #0x4] */
/* @0xed654 mov r3, r0 */
/* @0xed658 ldr r12, [r12] */
/* @0xed65c str r12, [sp] */
/* @0xed660 bl 0xb65c8 <snprintf@plt> */
/* @0xed664 b 0xed3e4 <_Z17Error_Show_ActionPKcb+0x474> */
/* @0xed668 add r12, sp, #88 */
/* @0xed66c str r0, [sp, #0x4c] */
/* @0xed670 str r12, [sp, #0x28] */
/* @0xed674 str r0, [sp, #0x50] */
/* @0xed678 b 0xed080 <_Z17Error_Show_ActionPKcb+0x110> */
/* @0xed67c ldr r12, [sp, #0x20] */
/* @0xed680 ldr r3, [pc, #0x120] */
/* @0xed684 ldr r3, [r12, r3] */
/* @0xed688 ldr r0, [r3] */
/* @0xed68c bl 0x1f2b58 <_Z13TimeLine_Namei> */
/* @0xed690 ldr r12, [sp, #0x3c] */
/* @0xed694 cmp r12, #0 */
/* @0xed698 mov r3, r0 */
/* @0xed69c beq 0xed75c <_Z17Error_Show_ActionPKcb+0x7ec> */
/* @0xed6a0 ldr r12, [sp, #0x24] */
/* @0xed6a4 add r0, sp, #116 */
/* @0xed6a8 ldr r2, [pc, #0xf4] */
/* @0xed6ac movw r1, #0x7fff */
/* @0xed6b0 str r12, [sp] */
/* @0xed6b4 ldr r12, [sp, #0x20] */
/* @0xed6b8 ldr r2, [r12, r2] */
/* @0xed6bc ldr r12, [sp, #0x3c] */
/* @0xed6c0 str r3, [sp, #0x8] */
/* @0xed6c4 mov r3, r0 */
/* @0xed6c8 str r12, [sp, #0xc] */
/* @0xed6cc ldr r12, [r2] */
/* @0xed6d0 ldr r2, [pc, #0x108] */
/* @0xed6d4 str r12, [sp, #0x4] */
/* @0xed6d8 add r2, pc, r2 */
/* @0xed6dc bl 0xb65c8 <snprintf@plt> */
/* @0xed6e0 b 0xed3e4 <_Z17Error_Show_ActionPKcb+0x474> */
/* @0xed6e4 ldr lr, [pc, #0xf8] */
/* @0xed6e8 add r12, sp, #116 */
/* @0xed6ec add lr, pc, lr */
/* @0xed6f0 ldm lr!, {r0, r1, r2, r3} */
/* @0xed6f4 stm r12!, {r0, r1, r2, r3} */
/* @0xed6f8 ldm lr!, {r0, r1, r2, r3} */
/* @0xed6fc stm r12!, {r0, r1, r2, r3} */
/* @0xed700 ldm lr!, {r0, r1, r2, r3} */
/* @0xed704 stm r12!, {r0, r1, r2, r3} */
/* @0xed708 ldm lr, {r0, r1} */
/* @0xed70c lsr r3, r1, #16 */
/* @0xed710 str r0, [r12], #4 */
/* @0xed714 strh r1, [r12], #2 */
/* @0xed718 strb r3, [r12] */
/* @0xed71c b 0xed624 <_Z17Error_Show_ActionPKcb+0x6b4> */
/* @0xed720 ldr r12, [pc, #0xc0] */
/* @0xed724 add r12, pc, r12 */
/* @0xed728 str r12, [sp, #0x3c] */
/* @0xed72c b 0xed3b4 <_Z17Error_Show_ActionPKcb+0x444> */
/* @0xed730 ldr r12, [pc, #0xb4] */
/* @0xed734 add r12, pc, r12 */
/* @0xed738 str r12, [sp, #0x3c] */
/* @0xed73c b 0xed630 <_Z17Error_Show_ActionPKcb+0x6c0> */
/* @0xed740 ldr r12, [sp, #0x34] */
/* @0xed744 ldr r1, [pc, #0xa4] */
/* @0xed748 ldr r0, [sp, #0x14] */
/* @0xed74c ldr r2, [r12, #0x34] */
/* @0xed750 add r1, pc, r1 */
/* @0xed754 bl 0xd3788 <_ZN17TErrStreamConsole6OutputEPKcz> */
/* @0xed758 b 0xed474 <_Z17Error_Show_ActionPKcb+0x504> */
/* @0xed75c ldr r12, [pc, #0x90] */
/* @0xed760 add r12, pc, r12 */
/* @0xed764 str r12, [sp, #0x3c] */
/* @0xed768 b 0xed6a0 <_Z17Error_Show_ActionPKcb+0x730> */
/* @0xed76c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xed770 eorseq r4, r0, r8, asr #25 */
/* @0xed774 .word 0xffffbd00 */
/* @0xed778 .word 0xffffbf58 */
/* @0xed77c .word 0xffffc15c */
/* @0xed780 eoreq r7, r4, r4, lsl #23 */
/* @0xed784 eoreq r7, r4, r4, ror #23 */
/* @0xed788 eoreq r7, r4, r4, asr r11 */
/* @0xed78c eoreq r7, r4, r8, lsr #23 */
/* @0xed790 eoreq r7, r4, r0, ror #23 */
/* @0xed794 .word 0x00247bb0 */
/* @0xed798 eoreq r7, r4, r8, lsl r11 */
/* @0xed79c .word 0xffffbd30 */
/* @0xed7a0 .word 0xffffc160 */
/* @0xed7a4 .word 0xffffc164 */
/* @0xed7a8 .word 0xffffc168 */
/* @0xed7ac mlaeq r4, r12, r9, r7 */
/* @0xed7b0 .word 0x002479b0 */
/* @0xed7b4 mlaeq r4, r12, r8, r7 */
/* @0xed7b8 eoreq r7, r4, r0, lsr #19 */
/* @0xed7bc eoreq r7, r4, r8, lsr #18 */
/* @0xed7c0 .word 0xffffc140 */
/* @0xed7c4 .word 0xffffbf78 */
/* @0xed7c8 .word 0xffffbd10 */
/* @0xed7cc eoreq r7, r4, r8, lsr #12 */
/* @0xed7d0 .word 0xffffc16c */
/* @0xed7d4 eoreq r7, r4, r4, ror #13 */
/* @0xed7d8 .word 0xffffc170 */
/* @0xed7dc .word 0x002476d4 */
/* @0xed7e0 eoreq r7, r4, r0, asr r6 */
/* @0xed7e4 .word 0x002475bc */
/* @0xed7e8 eoreq r1, r4, r2, lsl r4 */
/* @0xed7ec eoreq r1, r4, r2, lsl #8 */
/* @0xed7f0 eoreq r7, r4, r12, asr #13 */
/* @0xed7f4 .word 0x002413d6 */

/* ── FUNC 0xed7f8 · Code_Report_Error(CCode*, int, char const*) · size=1036 · insn=259 */
/* @0xed7f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xed7fc add r11, sp, #32 */
/* @0xed800 ldr r5, [pc, #0x3e8] */
/* @0xed804 sub sp, sp, #44 */
/* @0xed808 mov r4, r1 */
/* @0xed80c ldr r5, [pc, r5] */
/* @0xed810 str r0, [r11, #-0x34] */
/* @0xed814 str r2, [r11, #-0x38] */
/* @0xed818 ldr r3, [r5] */
/* @0xed81c str r3, [r11, #-0x28] */
/* @0xed820 bl 0x17df38 <_Z14ExitFullScreenv> */
/* @0xed824 ldr r3, [pc, #0x3c8] */
/* @0xed828 ldr r3, [pc, r3] */
/* @0xed82c ldrb r7, [r3] */
/* @0xed830 cmp r7, #0 */
/* @0xed834 beq 0xed850 <_Z17Code_Report_ErrorP5CCodeiPKc+0x58> */
/* @0xed838 ldr r2, [r11, #-0x28] */
/* @0xed83c ldr r3, [r5] */
/* @0xed840 cmp r2, r3 */
/* @0xed844 bne 0xedbd0 <_Z17Code_Report_ErrorP5CCodeiPKc+0x3d8> */
/* @0xed848 sub sp, r11, #32 */
/* @0xed84c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xed850 ldr r6, [pc, #0x3a0] */
/* @0xed854 mov r2, #1 */
/* @0xed858 strb r2, [r3] */
/* @0xed85c bic r4, r4, r4, asr #31 */
/* @0xed860 ldr r6, [pc, r6] */
/* @0xed864 ldr r0, [r6] */
/* @0xed868 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xed86c ldr r0, [r11, #-0x34] */
/* @0xed870 str r7, [r6] */
/* @0xed874 bl 0xcf470 <_ZN5CCode7GetTextEv> */
/* @0xed878 mov r9, r0 */
/* @0xed87c bl 0xb6538 <strlen@plt> */
/* @0xed880 mov r1, #0 */
/* @0xed884 cmp r4, r0 */
/* @0xed888 movge r4, r0 */
/* @0xed88c cmp r9, #0 */
/* @0xed890 addne r2, r0, #1 */
/* @0xed894 moveq r2, #32 */
/* @0xed898 add r0, r2, #14 */
/* @0xed89c bic r0, r0, #7 */
/* @0xed8a0 mov r7, r2 */
/* @0xed8a4 sub sp, sp, r0 */
/* @0xed8a8 add r3, sp, #16 */
/* @0xed8ac str r3, [r11, #-0x30] */
/* @0xed8b0 mov r0, r3 */
/* @0xed8b4 bl 0xb65b0 <memset@plt> */
/* @0xed8b8 cmp r4, #0 */
/* @0xed8bc ble 0xedbd4 <_Z17Code_Report_ErrorP5CCodeiPKc+0x3dc> */
/* @0xed8c0 add lr, r4, r9 */
/* @0xed8c4 mov r2, r9 */
/* @0xed8c8 mov r0, #0 */
/* @0xed8cc mov r10, #1 */
/* @0xed8d0 ldrb r1, [r2], #1 */
/* @0xed8d4 cmp r1, #10 */
/* @0xed8d8 addeq r10, r10, #1 */
/* @0xed8dc moveq r0, #0 */
/* @0xed8e0 beq 0xed8ec <_Z17Code_Report_ErrorP5CCodeiPKc+0xf4> */
/* @0xed8e4 cmp r1, #13 */
/* @0xed8e8 addne r0, r0, #1 */
/* @0xed8ec cmp r2, lr */
/* @0xed8f0 bne 0xed8d0 <_Z17Code_Report_ErrorP5CCodeiPKc+0xd8> */
/* @0xed8f4 ldrb r1, [r9] */
/* @0xed8f8 add r0, r0, #1 */
/* @0xed8fc str r0, [r11, #-0x3c] */
/* @0xed900 cmp r1, #0 */
/* @0xed904 beq 0xed974 <_Z17Code_Report_ErrorP5CCodeiPKc+0x17c> */
/* @0xed908 ldrb r1, [r2, #-0x1] */
/* @0xed90c cmp r1, #10 */
/* @0xed910 bne 0xed928 <_Z17Code_Report_ErrorP5CCodeiPKc+0x130> */
/* @0xed914 b 0xed930 <_Z17Code_Report_ErrorP5CCodeiPKc+0x138> */
/* @0xed918 sub r2, r2, #1 */
/* @0xed91c ldrb r1, [r2, #-0x1] */
/* @0xed920 cmp r1, #10 */
/* @0xed924 beq 0xed930 <_Z17Code_Report_ErrorP5CCodeiPKc+0x138> */
/* @0xed928 subs r4, r4, #1 */
/* @0xed92c bne 0xed918 <_Z17Code_Report_ErrorP5CCodeiPKc+0x120> */
/* @0xed930 mov r0, r9 */
/* @0xed934 mov r8, #0 */
/* @0xed938 bl 0xb6538 <strlen@plt> */
/* @0xed93c b 0xed96c <_Z17Code_Report_ErrorP5CCodeiPKc+0x174> */
/* @0xed940 ldrb r1, [r9, r4] */
/* @0xed944 cmp r1, #10 */
/* @0xed948 beq 0xed974 <_Z17Code_Report_ErrorP5CCodeiPKc+0x17c> */
/* @0xed94c cmp r8, r7 */
/* @0xed950 bge 0xed968 <_Z17Code_Report_ErrorP5CCodeiPKc+0x170> */
/* @0xed954 ldr r3, [r11, #-0x30] */
/* @0xed958 mov r0, r9 */
/* @0xed95c strb r1, [r3, r8] */
/* @0xed960 add r8, r8, #1 */
/* @0xed964 bl 0xb6538 <strlen@plt> */
/* @0xed968 add r4, r4, #1 */
/* @0xed96c cmp r4, r0 */
/* @0xed970 blt 0xed940 <_Z17Code_Report_ErrorP5CCodeiPKc+0x148> */
/* @0xed974 ldr r3, [r11, #-0x34] */
/* @0xed978 ldr r2, [r3, #0x8] */
/* @0xed97c cmp r2, #1 */
/* @0xed980 beq 0xeda84 <_Z17Code_Report_ErrorP5CCodeiPKc+0x28c> */
/* @0xed984 mov r0, r9 */
/* @0xed988 bl 0xb6538 <strlen@plt> */
/* @0xed98c mov r4, r0 */
/* @0xed990 ldr r0, [r11, #-0x38] */
/* @0xed994 bl 0xb6538 <strlen@plt> */
/* @0xed998 mov r1, #0 */
/* @0xed99c add r0, r4, r0 */
/* @0xed9a0 add r4, r0, #40 */
/* @0xed9a4 lsl r4, r4, #1 */
/* @0xed9a8 add r0, r4, #14 */
/* @0xed9ac bic r0, r0, #7 */
/* @0xed9b0 mov r2, r4 */
/* @0xed9b4 sub sp, sp, r0 */
/* @0xed9b8 add r7, sp, #16 */
/* @0xed9bc mov r0, r7 */
/* @0xed9c0 bl 0xb65b0 <memset@plt> */
/* @0xed9c4 ldr r3, [r11, #-0x3c] */
/* @0xed9c8 ldr r2, [pc, #0x22c] */
/* @0xed9cc mov r1, r4 */
/* @0xed9d0 mov r0, r7 */
/* @0xed9d4 str r3, [sp] */
/* @0xed9d8 add r2, pc, r2 */
/* @0xed9dc ldr r3, [r11, #-0x38] */
/* @0xed9e0 str r3, [sp, #0x4] */
/* @0xed9e4 mov r3, r9 */
/* @0xed9e8 bl 0xb65c8 <snprintf@plt> */
/* @0xed9ec ldr r4, [r6] */
/* @0xed9f0 cmp r4, #0 */
/* @0xed9f4 beq 0xeda1c <_Z17Code_Report_ErrorP5CCodeiPKc+0x224> */
/* @0xed9f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xed9fc ldr r8, [r4, #0x4] */
/* @0xeda00 sub r8, r8, #1 */
/* @0xeda04 str r8, [r4, #0x4] */
/* @0xeda08 cmp r8, #0 */
/* @0xeda0c beq 0xeda4c <_Z17Code_Report_ErrorP5CCodeiPKc+0x254> */
/* @0xeda10 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xeda14 mov r0, r4 */
/* @0xeda18 bl 0x27d1d0 <_ZdlPv> */
/* @0xeda1c mov r0, #12 */
/* @0xeda20 bl 0x27c524 <_Znwj> */
/* @0xeda24 mov r4, r0 */
/* @0xeda28 mov r0, r7 */
/* @0xeda2c bl 0xb6538 <strlen@plt> */
/* @0xeda30 str r0, [r4, #0x8] */
/* @0xeda34 mov r0, r7 */
/* @0xeda38 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xeda3c mov r3, #1 */
/* @0xeda40 stm r4, {r0, r3} */
/* @0xeda44 str r4, [r6] */
/* @0xeda48 b 0xed838 <_Z17Code_Report_ErrorP5CCodeiPKc+0x40> */
/* @0xeda4c ldr r0, [r4] */
/* @0xeda50 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xeda54 str r8, [r4] */
/* @0xeda58 str r8, [r4, #0x8] */
/* @0xeda5c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xeda60 ldr r8, [r4, #0x4] */
/* @0xeda64 sub r8, r8, #1 */
/* @0xeda68 str r8, [r4, #0x4] */
/* @0xeda6c cmp r8, #0 */
/* @0xeda70 beq 0xedbac <_Z17Code_Report_ErrorP5CCodeiPKc+0x3b4> */
/* @0xeda74 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xeda78 mov r0, r4 */
/* @0xeda7c bl 0x27d1d0 <_ZdlPv> */
/* @0xeda80 b 0xeda10 <_Z17Code_Report_ErrorP5CCodeiPKc+0x218> */
/* @0xeda84 ldr r0, [r11, #-0x30] */
/* @0xeda88 bl 0xb6538 <strlen@plt> */
/* @0xeda8c mov r4, r0 */
/* @0xeda90 ldr r0, [r11, #-0x38] */
/* @0xeda94 bl 0xb6538 <strlen@plt> */
/* @0xeda98 mov r1, #0 */
/* @0xeda9c add r0, r4, r0 */
/* @0xedaa0 add r7, r0, #51 */
/* @0xedaa4 lsl r7, r7, #1 */
/* @0xedaa8 add r3, r7, #14 */
/* @0xedaac bic r3, r3, #7 */
/* @0xedab0 mov r2, r7 */
/* @0xedab4 sub sp, sp, r3 */
/* @0xedab8 add r4, sp, #16 */
/* @0xedabc mov r0, r4 */
/* @0xedac0 bl 0xb65b0 <memset@plt> */
/* @0xedac4 ldr r3, [r11, #-0x30] */
/* @0xedac8 ldr r2, [pc, #0x130] */
/* @0xedacc mov r1, r7 */
/* @0xedad0 mov r0, r4 */
/* @0xedad4 str r3, [sp] */
/* @0xedad8 add r2, pc, r2 */
/* @0xedadc ldr r3, [r11, #-0x3c] */
/* @0xedae0 str r3, [sp, #0x4] */
/* @0xedae4 ldr r3, [r11, #-0x38] */
/* @0xedae8 str r3, [sp, #0x8] */
/* @0xedaec mov r3, r10 */
/* @0xedaf0 bl 0xb65c8 <snprintf@plt> */
/* @0xedaf4 ldr r7, [r6] */
/* @0xedaf8 cmp r7, #0 */
/* @0xedafc beq 0xedb24 <_Z17Code_Report_ErrorP5CCodeiPKc+0x32c> */
/* @0xedb00 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xedb04 ldr r8, [r7, #0x4] */
/* @0xedb08 sub r8, r8, #1 */
/* @0xedb0c str r8, [r7, #0x4] */
/* @0xedb10 cmp r8, #0 */
/* @0xedb14 beq 0xedb54 <_Z17Code_Report_ErrorP5CCodeiPKc+0x35c> */
/* @0xedb18 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xedb1c mov r0, r7 */
/* @0xedb20 bl 0x27d1d0 <_ZdlPv> */
/* @0xedb24 mov r0, #12 */
/* @0xedb28 bl 0x27c524 <_Znwj> */
/* @0xedb2c mov r7, r0 */
/* @0xedb30 mov r0, r4 */
/* @0xedb34 bl 0xb6538 <strlen@plt> */
/* @0xedb38 str r0, [r7, #0x8] */
/* @0xedb3c mov r0, r4 */
/* @0xedb40 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xedb44 mov r3, #1 */
/* @0xedb48 stm r7, {r0, r3} */
/* @0xedb4c str r7, [r6] */
/* @0xedb50 b 0xed838 <_Z17Code_Report_ErrorP5CCodeiPKc+0x40> */
/* @0xedb54 ldr r0, [r7] */
/* @0xedb58 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xedb5c str r8, [r7] */
/* @0xedb60 str r8, [r7, #0x8] */
/* @0xedb64 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xedb68 ldr r8, [r7, #0x4] */
/* @0xedb6c sub r8, r8, #1 */
/* @0xedb70 str r8, [r7, #0x4] */
/* @0xedb74 cmp r8, #0 */
/* @0xedb78 bne 0xedb9c <_Z17Code_Report_ErrorP5CCodeiPKc+0x3a4> */
/* @0xedb7c ldr r0, [r7] */
/* @0xedb80 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xedb84 mov r0, r7 */
/* @0xedb88 str r8, [r7] */
/* @0xedb8c str r8, [r7, #0x8] */
/* @0xedb90 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xedb94 mov r0, r7 */
/* @0xedb98 bl 0x27d1d0 <_ZdlPv> */
/* @0xedb9c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xedba0 mov r0, r7 */
/* @0xedba4 bl 0x27d1d0 <_ZdlPv> */
/* @0xedba8 b 0xedb18 <_Z17Code_Report_ErrorP5CCodeiPKc+0x320> */
/* @0xedbac ldr r0, [r4] */
/* @0xedbb0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xedbb4 mov r0, r4 */
/* @0xedbb8 str r8, [r4] */
/* @0xedbbc str r8, [r4, #0x8] */
/* @0xedbc0 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xedbc4 mov r0, r4 */
/* @0xedbc8 bl 0x27d1d0 <_ZdlPv> */
/* @0xedbcc b 0xeda74 <_Z17Code_Report_ErrorP5CCodeiPKc+0x27c> */
/* @0xedbd0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xedbd4 ldrb r2, [r9] */
/* @0xedbd8 mov r3, #1 */
/* @0xedbdc mov r10, r3 */
/* @0xedbe0 str r3, [r11, #-0x3c] */
/* @0xedbe4 cmp r2, #0 */
/* @0xedbe8 bne 0xed930 <_Z17Code_Report_ErrorP5CCodeiPKc+0x138> */
/* @0xedbec b 0xed974 <_Z17Code_Report_ErrorP5CCodeiPKc+0x17c> */
/* @0xedbf0 eorseq r0, r0, r4, asr #2 */
/* @0xedbf4 eorseq r0, r0, r12, lsr r3 */
/* @0xedbf8 eorseq r0, r0, r0, lsl r3 */
/* @0xedbfc eoreq r7, r4, r0, lsl #9 */
/* @0xedc00 eoreq r7, r4, r12, asr #6 */

/* ── FUNC 0xedc04 · CheckConstName(char const*) · size=136 · insn=34 */
/* @0xedc04 push {r4, lr} */
/* @0xedc08 mov r4, r0 */
/* @0xedc0c ldrb r3, [r0] */
/* @0xedc10 cmp r3, #0 */
/* @0xedc14 beq 0xedc6c <_Z14CheckConstNamePKc+0x68> */
/* @0xedc18 bic r2, r3, #32 */
/* @0xedc1c sub r2, r2, #65 */
/* @0xedc20 cmp r2, #25 */
/* @0xedc24 bhi 0xedc74 <_Z14CheckConstNamePKc+0x70> */
/* @0xedc28 mov r0, r4 */
/* @0xedc2c bl 0xb6538 <strlen@plt> */
/* @0xedc30 mov r1, r4 */
/* @0xedc34 mov r2, #1 */
/* @0xedc38 cmp r2, r0 */
/* @0xedc3c add r2, r2, #1 */
/* @0xedc40 bge 0xedc84 <_Z14CheckConstNamePKc+0x80> */
/* @0xedc44 ldrb r3, [r1, #0x1]! */
/* @0xedc48 bic r12, r3, #32 */
/* @0xedc4c sub r4, r3, #48 */
/* @0xedc50 sub r12, r12, #65 */
/* @0xedc54 cmp r12, #25 */
/* @0xedc58 bls 0xedc38 <_Z14CheckConstNamePKc+0x34> */
/* @0xedc5c cmp r4, #9 */
/* @0xedc60 bls 0xedc38 <_Z14CheckConstNamePKc+0x34> */
/* @0xedc64 cmp r3, #95 */
/* @0xedc68 beq 0xedc38 <_Z14CheckConstNamePKc+0x34> */
/* @0xedc6c mov r0, #0 */
/* @0xedc70 pop {r4, pc} */
/* @0xedc74 cmp r3, #95 */
/* @0xedc78 beq 0xedc28 <_Z14CheckConstNamePKc+0x24> */
/* @0xedc7c mov r0, #0 */
/* @0xedc80 pop {r4, pc} */
/* @0xedc84 mov r0, #1 */
/* @0xedc88 pop {r4, pc} */

/* ── FUNC 0xedc8c · Code_Constant_Find_IgnoreCase(char const*) · size=116 · insn=29 */
/* @0xedc8c ldr r3, [pc, #0x60] */
/* @0xedc90 push {r4, r5, r6, lr} */
/* @0xedc94 ldr r3, [pc, r3] */
/* @0xedc98 mov r6, r0 */
/* @0xedc9c ldr r3, [r3] */
/* @0xedca0 subs r4, r3, #1 */
/* @0xedca4 bmi 0xedcec <_Z29Code_Constant_Find_IgnoreCasePKc+0x60> */
/* @0xedca8 ldr r2, [pc, #0x48] */
/* @0xedcac ldr r2, [pc, r2] */
/* @0xedcb0 ldr r5, [r2] */
/* @0xedcb4 add r5, r5, r3, lsl #2 */
/* @0xedcb8 b 0xedcc4 <_Z29Code_Constant_Find_IgnoreCasePKc+0x38> */
/* @0xedcbc subs r4, r4, #1 */
/* @0xedcc0 blo 0xedcec <_Z29Code_Constant_Find_IgnoreCasePKc+0x60> */
/* @0xedcc4 ldr r0, [r5, #-0x4]! */
/* @0xedcc8 mov r1, r6 */
/* @0xedccc bl 0xb66d0 <strcasecmp@plt> */
/* @0xedcd0 cmp r0, #0 */
/* @0xedcd4 bne 0xedcbc <_Z29Code_Constant_Find_IgnoreCasePKc+0x30> */
/* @0xedcd8 ldr r3, [pc, #0x1c] */
/* @0xedcdc ldr r3, [pc, r3] */
/* @0xedce0 ldr r0, [r3] */
/* @0xedce4 add r0, r0, r4, lsl #4 */
/* @0xedce8 pop {r4, r5, r6, pc} */
/* @0xedcec mov r0, #0 */
/* @0xedcf0 pop {r4, r5, r6, pc} */
/* @0xedcf4 eorseq r0, r0, r0, lsr r1 */
/* @0xedcf8 eorseq r0, r0, r12, lsl r1 */
/* @0xedcfc ldrshteq r0, [r0], -r0 */

/* ── FUNC 0xedd00 · AddConstant(char const*, RValue*) · size=756 · insn=189 */
/* @0xedd00 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xedd04 mov r5, r1 */
/* @0xedd08 ldr r4, [pc, #0x2d4] */
/* @0xedd0c mov r3, #74 */
/* @0xedd10 ldr r7, [pc, #0x2d0] */
/* @0xedd14 mov r9, r0 */
/* @0xedd18 ldr r4, [pc, r4] */
/* @0xedd1c ldr r8, [pc, #0x2c8] */
/* @0xedd20 ldr r7, [pc, r7] */
/* @0xedd24 ldr r6, [pc, #0x2c4] */
/* @0xedd28 ldr r1, [r4] */
/* @0xedd2c add r8, pc, r8 */
/* @0xedd30 mov r0, r7 */
/* @0xedd34 add r1, r1, #1 */
/* @0xedd38 mov r2, r8 */
/* @0xedd3c lsl r1, r1, #2 */
/* @0xedd40 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xedd44 ldr r1, [r4] */
/* @0xedd48 ldr r6, [pc, r6] */
/* @0xedd4c mov r2, r8 */
/* @0xedd50 add r1, r1, #1 */
/* @0xedd54 mov r3, #75 */
/* @0xedd58 mov r0, r6 */
/* @0xedd5c lsl r1, r1, #4 */
/* @0xedd60 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xedd64 ldr r3, [r4] */
/* @0xedd68 ldr r7, [r7] */
/* @0xedd6c add r8, r3, #1073741824 */
/* @0xedd70 add r3, r3, #1 */
/* @0xedd74 str r3, [r4] */
/* @0xedd78 ldr r0, [r7, r8, lsl #2] */
/* @0xedd7c cmp r0, #0 */
/* @0xedd80 beq 0xedd88 <_Z11AddConstantPKcP6RValue+0x88> */
/* @0xedd84 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xedd88 mov r0, r9 */
/* @0xedd8c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xedd90 str r0, [r7, r8, lsl #2] */
/* @0xedd94 mov r0, #0 */
/* @0xedd98 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xedd9c ldr r7, [r4] */
/* @0xedda0 ldr r6, [r6] */
/* @0xedda4 sub r7, r7, #-268435455 */
/* @0xedda8 add r4, r6, r7, lsl #4 */
/* @0xeddac ldr r2, [r4, #0xc] */
/* @0xeddb0 bic r3, r2, #-16777216 */
/* @0xeddb4 cmp r3, #1 */
/* @0xeddb8 beq 0xede74 <_Z11AddConstantPKcP6RValue+0x174> */
/* @0xeddbc cmp r3, #2 */
/* @0xeddc0 bne 0xedde8 <_Z11AddConstantPKcP6RValue+0xe8> */
/* @0xeddc4 sub r2, r2, #1 */
/* @0xeddc8 bic r2, r2, #-16777216 */
/* @0xeddcc bic r2, r2, #3 */
/* @0xeddd0 cmp r2, #0 */
/* @0xeddd4 beq 0xedf48 <_Z11AddConstantPKcP6RValue+0x248> */
/* @0xeddd8 mov r2, #0 */
/* @0xedddc mov r3, #5 */
/* @0xedde0 str r2, [r4, #0x8] */
/* @0xedde4 str r3, [r4, #0xc] */
/* @0xedde8 ldr r3, [r5, #0xc] */
/* @0xeddec mov r1, #0 */
/* @0xeddf0 ldr r2, [r5, #0x8] */
/* @0xeddf4 str r1, [r6, r7, lsl #4] */
/* @0xeddf8 str r3, [r4, #0xc] */
/* @0xeddfc ldr r3, [r5, #0xc] */
/* @0xede00 str r2, [r4, #0x8] */
/* @0xede04 bic r3, r3, #-16777216 */
/* @0xede08 cmp r3, #14 */
/* @0xede0c addls pc, pc, r3, lsl #2 */
/* @0xede10 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158> */
/* @0xede14 b 0xede60 <_Z11AddConstantPKcP6RValue+0x160> */
/* @0xede18 b 0xedecc <_Z11AddConstantPKcP6RValue+0x1cc> */
/* @0xede1c b 0xedee4 <_Z11AddConstantPKcP6RValue+0x1e4> */
/* @0xede20 b 0xede50 <_Z11AddConstantPKcP6RValue+0x150> */
/* @0xede24 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158> */
/* @0xede28 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158> */
/* @0xede2c b 0xedea8 <_Z11AddConstantPKcP6RValue+0x1a8> */
/* @0xede30 b 0xede50 <_Z11AddConstantPKcP6RValue+0x150> */
/* @0xede34 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158> */
/* @0xede38 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158> */
/* @0xede3c b 0xede60 <_Z11AddConstantPKcP6RValue+0x160> */
/* @0xede40 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158> */
/* @0xede44 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158> */
/* @0xede48 b 0xede60 <_Z11AddConstantPKcP6RValue+0x160> */
/* @0xede4c b 0xede50 <_Z11AddConstantPKcP6RValue+0x150> */
/* @0xede50 ldr r3, [r5] */
/* @0xede54 str r3, [r6, r7, lsl #4] */
/* @0xede58 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xede5c b 0xd3a34 <_Z15PopContextStackv> */
/* @0xede60 ldm r5, {r2, r3} */
/* @0xede64 str r2, [r6, r7, lsl #4] */
/* @0xede68 str r3, [r4, #0x4] */
/* @0xede6c pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xede70 b 0xd3a34 <_Z15PopContextStackv> */
/* @0xede74 ldr r8, [r6, r7, lsl #4] */
/* @0xede78 cmp r8, #0 */
/* @0xede7c beq 0xede9c <_Z11AddConstantPKcP6RValue+0x19c> */
/* @0xede80 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xede84 ldr r9, [r8, #0x4] */
/* @0xede88 sub r9, r9, #1 */
/* @0xede8c str r9, [r8, #0x4] */
/* @0xede90 cmp r9, #0 */
/* @0xede94 beq 0xedf10 <_Z11AddConstantPKcP6RValue+0x210> */
/* @0xede98 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xede9c mov r3, #0 */
/* @0xedea0 str r3, [r6, r7, lsl #4] */
/* @0xedea4 b 0xedde8 <_Z11AddConstantPKcP6RValue+0xe8> */
/* @0xedea8 ldr r3, [r5] */
/* @0xedeac str r3, [r6, r7, lsl #4] */
/* @0xedeb0 ldr r3, [r5] */
/* @0xedeb4 cmp r3, #0 */
/* @0xedeb8 beq 0xede58 <_Z11AddConstantPKcP6RValue+0x158> */
/* @0xedebc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xedec0 ldr r1, [r5] */
/* @0xedec4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xedec8 b 0xede58 <_Z11AddConstantPKcP6RValue+0x158> */
/* @0xedecc ldr r3, [r5] */
/* @0xeded0 cmp r3, #0 */
/* @0xeded4 ldrne r2, [r3, #0x4] */
/* @0xeded8 addne r2, r2, #1 */
/* @0xededc strne r2, [r3, #0x4] */
/* @0xedee0 b 0xede54 <_Z11AddConstantPKcP6RValue+0x154> */
/* @0xedee4 ldr r3, [r5] */
/* @0xedee8 cmp r3, #0 */
/* @0xedeec str r3, [r6, r7, lsl #4] */
/* @0xedef0 beq 0xede58 <_Z11AddConstantPKcP6RValue+0x158> */
/* @0xedef4 ldr r1, [r3, #0x8] */
/* @0xedef8 ldr r2, [r3] */
/* @0xedefc cmp r1, #0 */
/* @0xedf00 streq r4, [r3, #0x8] */
/* @0xedf04 add r2, r2, #1 */
/* @0xedf08 str r2, [r3] */
/* @0xedf0c b 0xede58 <_Z11AddConstantPKcP6RValue+0x158> */
/* @0xedf10 ldr r0, [r8] */
/* @0xedf14 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xedf18 str r9, [r8] */
/* @0xedf1c str r9, [r8, #0x8] */
/* @0xedf20 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xedf24 ldr r9, [r8, #0x4] */
/* @0xedf28 sub r9, r9, #1 */
/* @0xedf2c str r9, [r8, #0x4] */
/* @0xedf30 cmp r9, #0 */
/* @0xedf34 beq 0xedf54 <_Z11AddConstantPKcP6RValue+0x254> */
/* @0xedf38 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xedf3c mov r0, r8 */
/* @0xedf40 bl 0x27d1d0 <_ZdlPv> */
/* @0xedf44 b 0xede98 <_Z11AddConstantPKcP6RValue+0x198> */
/* @0xedf48 mov r0, r4 */
/* @0xedf4c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xedf50 b 0xeddd8 <_Z11AddConstantPKcP6RValue+0xd8> */
/* @0xedf54 ldr r0, [r8] */
/* @0xedf58 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xedf5c str r9, [r8] */
/* @0xedf60 str r9, [r8, #0x8] */
/* @0xedf64 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xedf68 ldr r9, [r8, #0x4] */
/* @0xedf6c sub r9, r9, #1 */
/* @0xedf70 str r9, [r8, #0x4] */
/* @0xedf74 cmp r9, #0 */
/* @0xedf78 beq 0xedf8c <_Z11AddConstantPKcP6RValue+0x28c> */
/* @0xedf7c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xedf80 mov r0, r8 */
/* @0xedf84 bl 0x27d1d0 <_ZdlPv> */
/* @0xedf88 b 0xedf38 <_Z11AddConstantPKcP6RValue+0x238> */
/* @0xedf8c ldr r0, [r8] */
/* @0xedf90 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xedf94 str r9, [r8] */
/* @0xedf98 str r9, [r8, #0x8] */
/* @0xedf9c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xedfa0 ldr r9, [r8, #0x4] */
/* @0xedfa4 sub r9, r9, #1 */
/* @0xedfa8 str r9, [r8, #0x4] */
/* @0xedfac cmp r9, #0 */
/* @0xedfb0 bne 0xedfd4 <_Z11AddConstantPKcP6RValue+0x2d4> */
/* @0xedfb4 ldr r0, [r8] */
/* @0xedfb8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xedfbc mov r0, r8 */
/* @0xedfc0 str r9, [r8] */
/* @0xedfc4 str r9, [r8, #0x8] */
/* @0xedfc8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xedfcc mov r0, r8 */
/* @0xedfd0 bl 0x27d1d0 <_ZdlPv> */
/* @0xedfd4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xedfd8 mov r0, r8 */
/* @0xedfdc bl 0x27d1d0 <_ZdlPv> */
/* @0xedfe0 b 0xedf7c <_Z11AddConstantPKcP6RValue+0x27c> */
/* @0xedfe4 eorseq r0, r0, r12, lsr #1 */
/* @0xedfe8 eorseq r0, r0, r8, lsr #1 */
/* @0xedfec eoreq r7, r4, r8, asr r1 */
/* @0xedff0 eorseq r0, r0, r4, lsl #1 */

/* ── FUNC 0xedff4 · AddRealConstant(char const*, double) · size=40 · insn=10 */
/* @0xedff4 str lr, [sp, #-0x4]! */
/* @0xedff8 sub sp, sp, #20 */
/* @0xedffc add r1, sp, #16 */
/* @0xee000 mov r12, #0 */
/* @0xee004 str r12, [sp, #0xc] */
/* @0xee008 strd r2, r3, [r1, #-16]! */
/* @0xee00c mov r1, sp */
/* @0xee010 bl 0xedd00 <_Z11AddConstantPKcP6RValue> */
/* @0xee014 add sp, sp, #20 */
/* @0xee018 ldr pc, [sp], #4 */

/* ── FUNC 0xee01c · INITIALIZE_Code_Constant() · size=14124 · insn=3531 */
/* @0xee01c ldr r0, [pc, #0xff8] */
/* @0xee020 mov r2, #0 */
/* @0xee024 push {r4, lr} */
/* @0xee028 add r0, pc, r0 */
/* @0xee02c mov r3, #0 */
/* @0xee030 movt r3, #0xbff0 */
/* @0xee034 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee038 ldr r0, [pc, #0xfe0] */
/* @0xee03c mov r2, #0 */
/* @0xee040 mov r3, #-1073741824 */
/* @0xee044 add r0, pc, r0 */
/* @0xee048 ldr r4, [pc, #0xfd4] */
/* @0xee04c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee050 ldr r0, [pc, #0xfd0] */
/* @0xee054 mov r2, #0 */
/* @0xee058 mov r3, #0 */
/* @0xee05c add r0, pc, r0 */
/* @0xee060 movt r3, #0xc008 */
/* @0xee064 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee068 ldr r0, [pc, #0xfbc] */
/* @0xee06c mov r2, #0 */
/* @0xee070 mov r3, #0 */
/* @0xee074 add r0, pc, r0 */
/* @0xee078 movt r3, #0xc010 */
/* @0xee07c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee080 ldr r0, [pc, #0xfa8] */
/* @0xee084 mov r2, #0 */
/* @0xee088 mov r3, #0 */
/* @0xee08c add r0, pc, r0 */
/* @0xee090 movt r3, #0xc014 */
/* @0xee094 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee098 ldr r0, [pc, #0xf94] */
/* @0xee09c mov r2, #0 */
/* @0xee0a0 mov r3, #0 */
/* @0xee0a4 add r0, pc, r0 */
/* @0xee0a8 movt r3, #0xc01c */
/* @0xee0ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee0b0 ldr r0, [pc, #0xf80] */
/* @0xee0b4 mov r2, #0 */
/* @0xee0b8 mov r3, #0 */
/* @0xee0bc add r0, pc, r0 */
/* @0xee0c0 movt r3, #0x3ff0 */
/* @0xee0c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee0c8 ldr r0, [pc, #0xf6c] */
/* @0xee0cc mov r2, #0 */
/* @0xee0d0 mov r3, #0 */
/* @0xee0d4 add r0, pc, r0 */
/* @0xee0d8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee0dc ldr r0, [pc, #0xf5c] */
/* @0xee0e0 mov r2, #1610612736 */
/* @0xee0e4 movw r3, #0x21fb */
/* @0xee0e8 add r0, pc, r0 */
/* @0xee0ec movt r3, #0x4009 */
/* @0xee0f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee0f4 ldr r0, [pc, #0xf48] */
/* @0xee0f8 mov r2, #0 */
/* @0xee0fc mov r3, #0 */
/* @0xee100 add r0, pc, r0 */
/* @0xee104 movt r3, #0x3ff0 */
/* @0xee108 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee10c ldr r0, [pc, #0xf34] */
/* @0xee110 mov r2, #0 */
/* @0xee114 mov r3, #1073741824 */
/* @0xee118 add r0, pc, r0 */
/* @0xee11c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee120 ldr r0, [pc, #0xf24] */
/* @0xee124 mov r2, #0 */
/* @0xee128 mov r3, #0 */
/* @0xee12c add r0, pc, r0 */
/* @0xee130 movt r3, #0x4008 */
/* @0xee134 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee138 ldr r0, [pc, #0xf10] */
/* @0xee13c mov r2, #0 */
/* @0xee140 mov r3, #0 */
/* @0xee144 add r0, pc, r0 */
/* @0xee148 movt r3, #0x4010 */
/* @0xee14c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee150 ldr r0, [pc, #0xefc] */
/* @0xee154 mov r2, #0 */
/* @0xee158 mov r3, #0 */
/* @0xee15c add r0, pc, r0 */
/* @0xee160 movt r3, #0x4014 */
/* @0xee164 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee168 ldr r0, [pc, #0xee8] */
/* @0xee16c mov r2, #0 */
/* @0xee170 mov r3, #0 */
/* @0xee174 add r0, pc, r0 */
/* @0xee178 movt r3, #0x4018 */
/* @0xee17c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee180 ldr r0, [pc, #0xed4] */
/* @0xee184 mov r2, #0 */
/* @0xee188 movw r3, #0xffe0 */
/* @0xee18c add r0, pc, r0 */
/* @0xee190 movt r3, #0x416f */
/* @0xee194 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee198 ldr r0, [pc, #0xec0] */
/* @0xee19c mov r2, #0 */
/* @0xee1a0 mov r3, #0 */
/* @0xee1a4 add r0, pc, r0 */
/* @0xee1a8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee1ac ldr r0, [pc, #0xeb0] */
/* @0xee1b0 mov r2, #0 */
/* @0xee1b4 mov r3, #57344 */
/* @0xee1b8 add r0, pc, r0 */
/* @0xee1bc movt r3, #0x416f */
/* @0xee1c0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee1c4 ldr r0, [pc, #0xe9c] */
/* @0xee1c8 mov r2, #0 */
/* @0xee1cc movw r3, #0x1010 */
/* @0xee1d0 add r0, pc, r0 */
/* @0xee1d4 movt r3, #0x4150 */
/* @0xee1d8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee1dc ldr r0, [pc, #0xe88] */
/* @0xee1e0 mov r2, #-536870912 */
/* @0xee1e4 movw r3, #0xe01f */
/* @0xee1e8 add r0, pc, r0 */
/* @0xee1ec movt r3, #0x416f */
/* @0xee1f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee1f4 ldr r0, [pc, #0xe74] */
/* @0xee1f8 mov r2, #0 */
/* @0xee1fc movw r3, #0x1010 */
/* @0xee200 add r0, pc, r0 */
/* @0xee204 movt r3, #0x4160 */
/* @0xee208 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee20c ldr r0, [pc, #0xe60] */
/* @0xee210 mov r2, #0 */
/* @0xee214 mov r3, #0 */
/* @0xee218 add r0, pc, r0 */
/* @0xee21c movt r3, #0x40e0 */
/* @0xee220 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee224 ldr r0, [pc, #0xe4c] */
/* @0xee228 mov r2, #0 */
/* @0xee22c mov r3, #57344 */
/* @0xee230 add r0, pc, r0 */
/* @0xee234 movt r3, #0x40ef */
/* @0xee238 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee23c ldr r0, [pc, #0xe38] */
/* @0xee240 mov r2, #0 */
/* @0xee244 movw r3, #0x1818 */
/* @0xee248 add r0, pc, r0 */
/* @0xee24c movt r3, #0x4168 */
/* @0xee250 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee254 ldr r0, [pc, #0xe24] */
/* @0xee258 mov r2, #0 */
/* @0xee25c mov r3, #0 */
/* @0xee260 add r0, pc, r0 */
/* @0xee264 movt r3, #0x4060 */
/* @0xee268 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee26c ldr r0, [pc, #0xe10] */
/* @0xee270 mov r2, #0 */
/* @0xee274 mov r3, #0 */
/* @0xee278 add r0, pc, r0 */
/* @0xee27c movt r3, #0x4160 */
/* @0xee280 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee284 ldr r0, [pc, #0xdfc] */
/* @0xee288 mov r2, #0 */
/* @0xee28c mov r3, #4096 */
/* @0xee290 add r0, pc, r0 */
/* @0xee294 movt r3, #0x40e0 */
/* @0xee298 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee29c ldr r0, [pc, #0xde8] */
/* @0xee2a0 mov r2, #0 */
/* @0xee2a4 mov r3, #16 */
/* @0xee2a8 add r0, pc, r0 */
/* @0xee2ac movt r3, #0x4160 */
/* @0xee2b0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee2b4 ldr r0, [pc, #0xdd4] */
/* @0xee2b8 mov r2, #0 */
/* @0xee2bc mov r3, #57344 */
/* @0xee2c0 add r0, pc, r0 */
/* @0xee2c4 movt r3, #0x406f */
/* @0xee2c8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee2cc ldr r0, [pc, #0xdc0] */
/* @0xee2d0 mov r2, #0 */
/* @0xee2d4 movw r3, #0x1818 */
/* @0xee2d8 add r0, pc, r0 */
/* @0xee2dc movt r3, #0x4168 */
/* @0xee2e0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee2e4 ldr r0, [pc, #0xdac] */
/* @0xee2e8 mov r2, #0 */
/* @0xee2ec mov r3, #4096 */
/* @0xee2f0 add r0, pc, r0 */
/* @0xee2f4 movt r3, #0x4160 */
/* @0xee2f8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee2fc ldr r0, [pc, #0xd98] */
/* @0xee300 mov r2, #-536870912 */
/* @0xee304 movw r3, #0xffff */
/* @0xee308 add r0, pc, r0 */
/* @0xee30c movt r3, #0x416f */
/* @0xee310 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee314 ldr r0, [pc, #0xd84] */
/* @0xee318 mov r2, #0 */
/* @0xee31c movw r3, #0xffe0 */
/* @0xee320 add r0, pc, r0 */
/* @0xee324 movt r3, #0x40ef */
/* @0xee328 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee32c ldr r0, [pc, #0xd70] */
/* @0xee330 mov r2, #-1073741824 */
/* @0xee334 movw r3, #0x283f */
/* @0xee338 add r0, pc, r0 */
/* @0xee33c movt r3, #0x4150 */
/* @0xee340 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee344 ldr r0, [pc, #0xd5c] */
/* @0xee348 mov r2, #0 */
/* @0xee34c mov r3, #0 */
/* @0xee350 add r0, pc, r0 */
/* @0xee354 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee358 ldr r0, [pc, #0xd4c] */
/* @0xee35c mov r2, #0 */
/* @0xee360 mov r3, #0 */
/* @0xee364 add r0, pc, r0 */
/* @0xee368 movt r3, #0x3ff0 */
/* @0xee36c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee370 ldr r0, [pc, #0xd38] */
/* @0xee374 mov r2, #0 */
/* @0xee378 mov r3, #1073741824 */
/* @0xee37c add r0, pc, r0 */
/* @0xee380 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee384 ldr r0, [pc, #0xd28] */
/* @0xee388 mov r2, #0 */
/* @0xee38c mov r3, #0 */
/* @0xee390 add r0, pc, r0 */
/* @0xee394 movt r3, #0x4008 */
/* @0xee398 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee39c ldr r0, [pc, #0xd14] */
/* @0xee3a0 mov r2, #0 */
/* @0xee3a4 mov r3, #0 */
/* @0xee3a8 add r0, pc, r0 */
/* @0xee3ac movt r3, #0x3ff0 */
/* @0xee3b0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee3b4 ldr r0, [pc, #0xd00] */
/* @0xee3b8 mov r2, #0 */
/* @0xee3bc mov r3, #1073741824 */
/* @0xee3c0 add r0, pc, r0 */
/* @0xee3c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee3c8 ldr r0, [pc, #0xcf0] */
/* @0xee3cc mov r2, #0 */
/* @0xee3d0 mov r3, #0 */
/* @0xee3d4 add r0, pc, r0 */
/* @0xee3d8 movt r3, #0x4008 */
/* @0xee3dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee3e0 ldr r0, [pc, #0xcdc] */
/* @0xee3e4 mov r2, #0 */
/* @0xee3e8 mov r3, #0 */
/* @0xee3ec add r0, pc, r0 */
/* @0xee3f0 movt r3, #0x4008 */
/* @0xee3f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee3f8 ldr r0, [pc, #0xcc8] */
/* @0xee3fc mov r2, #0 */
/* @0xee400 mov r3, #0 */
/* @0xee404 add r0, pc, r0 */
/* @0xee408 movt r3, #0x4010 */
/* @0xee40c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee410 ldr r0, [pc, #0xcb4] */
/* @0xee414 mov r2, #0 */
/* @0xee418 mov r3, #0 */
/* @0xee41c add r0, pc, r0 */
/* @0xee420 movt r3, #0x4010 */
/* @0xee424 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee428 ldr r0, [pc, #0xca0] */
/* @0xee42c mov r2, #0 */
/* @0xee430 mov r3, #0 */
/* @0xee434 add r0, pc, r0 */
/* @0xee438 movt r3, #0x4014 */
/* @0xee43c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee440 ldr r0, [pc, #0xc8c] */
/* @0xee444 mov r2, #0 */
/* @0xee448 mov r3, #0 */
/* @0xee44c add r0, pc, r0 */
/* @0xee450 movt r3, #0x4018 */
/* @0xee454 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee458 ldr r0, [pc, #0xc78] */
/* @0xee45c mov r2, #0 */
/* @0xee460 mov r3, #0 */
/* @0xee464 add r0, pc, r0 */
/* @0xee468 movt r3, #0x401c */
/* @0xee46c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee470 ldr r0, [pc, #0xc64] */
/* @0xee474 mov r2, #0 */
/* @0xee478 mov r3, #0 */
/* @0xee47c add r0, pc, r0 */
/* @0xee480 movt r3, #0x4020 */
/* @0xee484 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee488 ldr r0, [pc, #0xc50] */
/* @0xee48c mov r2, #0 */
/* @0xee490 mov r3, #0 */
/* @0xee494 add r0, pc, r0 */
/* @0xee498 movt r3, #0x4022 */
/* @0xee49c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee4a0 ldr r0, [pc, #0xc3c] */
/* @0xee4a4 mov r2, #0 */
/* @0xee4a8 mov r3, #0 */
/* @0xee4ac add r0, pc, r0 */
/* @0xee4b0 movt r3, #0x4022 */
/* @0xee4b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee4b8 ldr r0, [pc, #0xc28] */
/* @0xee4bc mov r2, #0 */
/* @0xee4c0 mov r3, #0 */
/* @0xee4c4 add r0, pc, r0 */
/* @0xee4c8 movt r3, #0x4024 */
/* @0xee4cc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee4d0 ldr r0, [pc, #0xc14] */
/* @0xee4d4 mov r2, #0 */
/* @0xee4d8 mov r3, #0 */
/* @0xee4dc add r0, pc, r0 */
/* @0xee4e0 movt r3, #0x4026 */
/* @0xee4e4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee4e8 ldr r4, [pc, r4] */
/* @0xee4ec ldrb r3, [r4] */
/* @0xee4f0 cmp r3, #0 */
/* @0xee4f4 bne 0xf1428 <_Z24INITIALIZE_Code_Constantv+0x340c> */
/* @0xee4f8 ldr r0, [pc, #0xbf0] */
/* @0xee4fc mov r2, #0 */
/* @0xee500 mov r3, #0 */
/* @0xee504 add r0, pc, r0 */
/* @0xee508 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee50c ldr r0, [pc, #0xbe0] */
/* @0xee510 mov r2, #0 */
/* @0xee514 mov r3, #0 */
/* @0xee518 add r0, pc, r0 */
/* @0xee51c movt r3, #0x3ff0 */
/* @0xee520 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee524 ldr r0, [pc, #0xbcc] */
/* @0xee528 mov r2, #0 */
/* @0xee52c mov r3, #1073741824 */
/* @0xee530 add r0, pc, r0 */
/* @0xee534 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee538 ldr r0, [pc, #0xbbc] */
/* @0xee53c mov r2, #0 */
/* @0xee540 mov r3, #0 */
/* @0xee544 add r0, pc, r0 */
/* @0xee548 movt r3, #0x4008 */
/* @0xee54c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee550 ldr r0, [pc, #0xba8] */
/* @0xee554 mov r2, #0 */
/* @0xee558 mov r3, #0 */
/* @0xee55c add r0, pc, r0 */
/* @0xee560 movt r3, #0x4010 */
/* @0xee564 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee568 ldr r0, [pc, #0xb94] */
/* @0xee56c mov r2, #0 */
/* @0xee570 mov r3, #0 */
/* @0xee574 add r0, pc, r0 */
/* @0xee578 movt r3, #0x4014 */
/* @0xee57c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee580 ldr r0, [pc, #0xb80] */
/* @0xee584 mov r2, #0 */
/* @0xee588 mov r3, #0 */
/* @0xee58c add r0, pc, r0 */
/* @0xee590 movt r3, #0x4018 */
/* @0xee594 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee598 ldr r0, [pc, #0xb6c] */
/* @0xee59c mov r2, #0 */
/* @0xee5a0 mov r3, #0 */
/* @0xee5a4 add r0, pc, r0 */
/* @0xee5a8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee5ac ldr r0, [pc, #0xb5c] */
/* @0xee5b0 mov r2, #0 */
/* @0xee5b4 mov r3, #0 */
/* @0xee5b8 add r0, pc, r0 */
/* @0xee5bc movt r3, #0x3ff0 */
/* @0xee5c0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee5c4 ldr r0, [pc, #0xb48] */
/* @0xee5c8 mov r2, #0 */
/* @0xee5cc mov r3, #0 */
/* @0xee5d0 add r0, pc, r0 */
/* @0xee5d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee5d8 ldr r0, [pc, #0xb38] */
/* @0xee5dc mov r2, #0 */
/* @0xee5e0 mov r3, #0 */
/* @0xee5e4 add r0, pc, r0 */
/* @0xee5e8 movt r3, #0x3ff0 */
/* @0xee5ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee5f0 ldr r0, [pc, #0xb24] */
/* @0xee5f4 mov r2, #0 */
/* @0xee5f8 mov r3, #1073741824 */
/* @0xee5fc add r0, pc, r0 */
/* @0xee600 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee604 ldr r0, [pc, #0xb14] */
/* @0xee608 mov r2, #0 */
/* @0xee60c mov r3, #0 */
/* @0xee610 add r0, pc, r0 */
/* @0xee614 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee618 ldr r0, [pc, #0xb04] */
/* @0xee61c mov r2, #0 */
/* @0xee620 mov r3, #0 */
/* @0xee624 add r0, pc, r0 */
/* @0xee628 movt r3, #0x3ff0 */
/* @0xee62c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee630 ldr r0, [pc, #0xaf0] */
/* @0xee634 mov r2, #0 */
/* @0xee638 mov r3, #1073741824 */
/* @0xee63c add r0, pc, r0 */
/* @0xee640 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee644 ldr r0, [pc, #0xae0] */
/* @0xee648 mov r2, #0 */
/* @0xee64c mov r3, #0 */
/* @0xee650 add r0, pc, r0 */
/* @0xee654 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee658 ldr r0, [pc, #0xad0] */
/* @0xee65c mov r2, #0 */
/* @0xee660 mov r3, #0 */
/* @0xee664 add r0, pc, r0 */
/* @0xee668 movt r3, #0x3ff0 */
/* @0xee66c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee670 ldr r0, [pc, #0xabc] */
/* @0xee674 mov r2, #0 */
/* @0xee678 mov r3, #1073741824 */
/* @0xee67c add r0, pc, r0 */
/* @0xee680 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee684 ldr r0, [pc, #0xaac] */
/* @0xee688 mov r2, #0 */
/* @0xee68c mov r3, #0 */
/* @0xee690 add r0, pc, r0 */
/* @0xee694 movt r3, #0xbff0 */
/* @0xee698 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee69c ldr r0, [pc, #0xa98] */
/* @0xee6a0 mov r2, #0 */
/* @0xee6a4 mov r3, #0 */
/* @0xee6a8 add r0, pc, r0 */
/* @0xee6ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee6b0 ldr r0, [pc, #0xa88] */
/* @0xee6b4 mov r2, #0 */
/* @0xee6b8 mov r3, #0 */
/* @0xee6bc add r0, pc, r0 */
/* @0xee6c0 movt r3, #0x3ff0 */
/* @0xee6c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee6c8 ldr r0, [pc, #0xa74] */
/* @0xee6cc mov r2, #0 */
/* @0xee6d0 mov r3, #1073741824 */
/* @0xee6d4 add r0, pc, r0 */
/* @0xee6d8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee6dc ldr r0, [pc, #0xa64] */
/* @0xee6e0 mov r2, #0 */
/* @0xee6e4 mov r3, #0 */
/* @0xee6e8 add r0, pc, r0 */
/* @0xee6ec movt r3, #0x4008 */
/* @0xee6f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee6f4 ldr r0, [pc, #0xa50] */
/* @0xee6f8 mov r2, #0 */
/* @0xee6fc mov r3, #0 */
/* @0xee700 add r0, pc, r0 */
/* @0xee704 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee708 ldr r0, [pc, #0xa40] */
/* @0xee70c mov r2, #0 */
/* @0xee710 mov r3, #0 */
/* @0xee714 add r0, pc, r0 */
/* @0xee718 movt r3, #0x3ff0 */
/* @0xee71c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee720 ldr r0, [pc, #0xa2c] */
/* @0xee724 mov r2, #0 */
/* @0xee728 mov r3, #0 */
/* @0xee72c add r0, pc, r0 */
/* @0xee730 movt r3, #0x402a */
/* @0xee734 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee738 ldr r0, [pc, #0xa18] */
/* @0xee73c mov r2, #0 */
/* @0xee740 mov r3, #0 */
/* @0xee744 add r0, pc, r0 */
/* @0xee748 movt r3, #0x402a */
/* @0xee74c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee750 ldr r0, [pc, #0xa04] */
/* @0xee754 mov r2, #0 */
/* @0xee758 mov r3, #0 */
/* @0xee75c add r0, pc, r0 */
/* @0xee760 movt r3, #0x4030 */
/* @0xee764 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee768 ldr r0, [pc, #0x9f0] */
/* @0xee76c mov r2, #0 */
/* @0xee770 mov r3, #0 */
/* @0xee774 add r0, pc, r0 */
/* @0xee778 movt r3, #0x4031 */
/* @0xee77c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee780 ldr r0, [pc, #0x9dc] */
/* @0xee784 mov r2, #0 */
/* @0xee788 mov r3, #0 */
/* @0xee78c add r0, pc, r0 */
/* @0xee790 movt r3, #0x4032 */
/* @0xee794 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee798 ldr r0, [pc, #0x9c8] */
/* @0xee79c mov r2, #0 */
/* @0xee7a0 mov r3, #0 */
/* @0xee7a4 add r0, pc, r0 */
/* @0xee7a8 movt r3, #0x403b */
/* @0xee7ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee7b0 ldr r0, [pc, #0x9b4] */
/* @0xee7b4 mov r2, #0 */
/* @0xee7b8 mov r3, #0 */
/* @0xee7bc add r0, pc, r0 */
/* @0xee7c0 movt r3, #0x4040 */
/* @0xee7c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee7c8 ldr r0, [pc, #0x9a0] */
/* @0xee7cc mov r2, #0 */
/* @0xee7d0 mov r3, #0 */
/* @0xee7d4 add r0, pc, r0 */
/* @0xee7d8 movt r3, #0x4020 */
/* @0xee7dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee7e0 ldr r0, [pc, #0x98c] */
/* @0xee7e4 mov r2, #0 */
/* @0xee7e8 mov r3, #0 */
/* @0xee7ec add r0, pc, r0 */
/* @0xee7f0 movt r3, #0x4022 */
/* @0xee7f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee7f8 ldr r0, [pc, #0x978] */
/* @0xee7fc mov r2, #0 */
/* @0xee800 mov r3, #0 */
/* @0xee804 add r0, pc, r0 */
/* @0xee808 movt r3, #0x4033 */
/* @0xee80c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee810 ldr r0, [pc, #0x964] */
/* @0xee814 mov r2, #0 */
/* @0xee818 mov r3, #0 */
/* @0xee81c add r0, pc, r0 */
/* @0xee820 movt r3, #0x4046 */
/* @0xee824 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee828 ldr r0, [pc, #0x950] */
/* @0xee82c mov r2, #0 */
/* @0xee830 mov r3, #32768 */
/* @0xee834 add r0, pc, r0 */
/* @0xee838 movt r3, #0x4042 */
/* @0xee83c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee840 ldr r0, [pc, #0x93c] */
/* @0xee844 mov r2, #0 */
/* @0xee848 mov r3, #32768 */
/* @0xee84c add r0, pc, r0 */
/* @0xee850 movt r3, #0x4043 */
/* @0xee854 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee858 ldr r0, [pc, #0x928] */
/* @0xee85c mov r2, #0 */
/* @0xee860 mov r3, #0 */
/* @0xee864 add r0, pc, r0 */
/* @0xee868 movt r3, #0x4043 */
/* @0xee86c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee870 ldr r0, [pc, #0x914] */
/* @0xee874 mov r2, #0 */
/* @0xee878 mov r3, #0 */
/* @0xee87c add r0, pc, r0 */
/* @0xee880 movt r3, #0x4044 */
/* @0xee884 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee888 ldr r0, [pc, #0x900] */
/* @0xee88c mov r2, #0 */
/* @0xee890 mov r3, #0 */
/* @0xee894 add r0, pc, r0 */
/* @0xee898 movt r3, #0x4042 */
/* @0xee89c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee8a0 ldr r0, [pc, #0x8ec] */
/* @0xee8a4 mov r2, #0 */
/* @0xee8a8 mov r3, #32768 */
/* @0xee8ac add r0, pc, r0 */
/* @0xee8b0 movt r3, #0x4041 */
/* @0xee8b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee8b8 ldr r0, [pc, #0x8d8] */
/* @0xee8bc mov r2, #0 */
/* @0xee8c0 mov r3, #0 */
/* @0xee8c4 add r0, pc, r0 */
/* @0xee8c8 movt r3, #0x4047 */
/* @0xee8cc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee8d0 ldr r0, [pc, #0x8c4] */
/* @0xee8d4 mov r2, #0 */
/* @0xee8d8 mov r3, #32768 */
/* @0xee8dc add r0, pc, r0 */
/* @0xee8e0 movt r3, #0x4046 */
/* @0xee8e4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee8e8 ldr r0, [pc, #0x8b0] */
/* @0xee8ec mov r2, #0 */
/* @0xee8f0 mov r3, #32768 */
/* @0xee8f4 add r0, pc, r0 */
/* @0xee8f8 movt r3, #0x4040 */
/* @0xee8fc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee900 ldr r0, [pc, #0x89c] */
/* @0xee904 mov r2, #0 */
/* @0xee908 mov r3, #0 */
/* @0xee90c add r0, pc, r0 */
/* @0xee910 movt r3, #0x4041 */
/* @0xee914 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee918 ldr r0, [pc, #0x888] */
/* @0xee91c mov r2, #0 */
/* @0xee920 mov r3, #0 */
/* @0xee924 add r0, pc, r0 */
/* @0xee928 movt r3, #0x405c */
/* @0xee92c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee930 ldr r0, [pc, #0x874] */
/* @0xee934 mov r2, #0 */
/* @0xee938 mov r3, #16384 */
/* @0xee93c add r0, pc, r0 */
/* @0xee940 movt r3, #0x405c */
/* @0xee944 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee948 ldr r0, [pc, #0x860] */
/* @0xee94c mov r2, #0 */
/* @0xee950 mov r3, #32768 */
/* @0xee954 add r0, pc, r0 */
/* @0xee958 movt r3, #0x405c */
/* @0xee95c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee960 ldr r0, [pc, #0x84c] */
/* @0xee964 mov r2, #0 */
/* @0xee968 mov r3, #49152 */
/* @0xee96c add r0, pc, r0 */
/* @0xee970 movt r3, #0x405c */
/* @0xee974 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee978 ldr r0, [pc, #0x838] */
/* @0xee97c mov r2, #0 */
/* @0xee980 mov r3, #0 */
/* @0xee984 add r0, pc, r0 */
/* @0xee988 movt r3, #0x405d */
/* @0xee98c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee990 ldr r0, [pc, #0x824] */
/* @0xee994 mov r2, #0 */
/* @0xee998 mov r3, #16384 */
/* @0xee99c add r0, pc, r0 */
/* @0xee9a0 movt r3, #0x405d */
/* @0xee9a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee9a8 ldr r0, [pc, #0x810] */
/* @0xee9ac mov r2, #0 */
/* @0xee9b0 mov r3, #32768 */
/* @0xee9b4 add r0, pc, r0 */
/* @0xee9b8 movt r3, #0x405d */
/* @0xee9bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee9c0 ldr r0, [pc, #0x7fc] */
/* @0xee9c4 mov r2, #0 */
/* @0xee9c8 mov r3, #49152 */
/* @0xee9cc add r0, pc, r0 */
/* @0xee9d0 movt r3, #0x405d */
/* @0xee9d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee9d8 ldr r0, [pc, #0x7e8] */
/* @0xee9dc mov r2, #0 */
/* @0xee9e0 mov r3, #0 */
/* @0xee9e4 add r0, pc, r0 */
/* @0xee9e8 movt r3, #0x405e */
/* @0xee9ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xee9f0 ldr r0, [pc, #0x7d4] */
/* @0xee9f4 mov r2, #0 */
/* @0xee9f8 mov r3, #16384 */
/* @0xee9fc add r0, pc, r0 */
/* @0xeea00 movt r3, #0x405e */
/* @0xeea04 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea08 ldr r0, [pc, #0x7c0] */
/* @0xeea0c mov r2, #0 */
/* @0xeea10 mov r3, #0 */
/* @0xeea14 add r0, pc, r0 */
/* @0xeea18 movt r3, #0x4060 */
/* @0xeea1c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea20 ldr r0, [pc, #0x7ac] */
/* @0xeea24 mov r2, #0 */
/* @0xeea28 mov r3, #8192 */
/* @0xeea2c add r0, pc, r0 */
/* @0xeea30 movt r3, #0x4060 */
/* @0xeea34 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea38 ldr r0, [pc, #0x798] */
/* @0xeea3c mov r2, #0 */
/* @0xeea40 mov r3, #0 */
/* @0xeea44 add r0, pc, r0 */
/* @0xeea48 movt r3, #0x4058 */
/* @0xeea4c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea50 ldr r0, [pc, #0x784] */
/* @0xeea54 mov r2, #0 */
/* @0xeea58 mov r3, #16384 */
/* @0xeea5c add r0, pc, r0 */
/* @0xeea60 movt r3, #0x4058 */
/* @0xeea64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea68 ldr r0, [pc, #0x770] */
/* @0xeea6c mov r2, #0 */
/* @0xeea70 mov r3, #32768 */
/* @0xeea74 add r0, pc, r0 */
/* @0xeea78 movt r3, #0x4058 */
/* @0xeea7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea80 ldr r0, [pc, #0x75c] */
/* @0xeea84 mov r2, #0 */
/* @0xeea88 mov r3, #49152 */
/* @0xeea8c add r0, pc, r0 */
/* @0xeea90 movt r3, #0x4058 */
/* @0xeea94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeea98 ldr r0, [pc, #0x748] */
/* @0xeea9c mov r2, #0 */
/* @0xeeaa0 mov r3, #0 */
/* @0xeeaa4 add r0, pc, r0 */
/* @0xeeaa8 movt r3, #0x4059 */
/* @0xeeaac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeab0 ldr r0, [pc, #0x734] */
/* @0xeeab4 mov r2, #0 */
/* @0xeeab8 mov r3, #16384 */
/* @0xeeabc add r0, pc, r0 */
/* @0xeeac0 movt r3, #0x4059 */
/* @0xeeac4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeac8 ldr r0, [pc, #0x720] */
/* @0xeeacc mov r2, #0 */
/* @0xeead0 mov r3, #32768 */
/* @0xeead4 add r0, pc, r0 */
/* @0xeead8 movt r3, #0x4059 */
/* @0xeeadc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeae0 ldr r0, [pc, #0x70c] */
/* @0xeeae4 mov r2, #0 */
/* @0xeeae8 mov r3, #49152 */
/* @0xeeaec add r0, pc, r0 */
/* @0xeeaf0 movt r3, #0x4059 */
/* @0xeeaf4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeaf8 ldr r0, [pc, #0x6f8] */
/* @0xeeafc mov r2, #0 */
/* @0xeeb00 mov r3, #0 */
/* @0xeeb04 add r0, pc, r0 */
/* @0xeeb08 movt r3, #0x405a */
/* @0xeeb0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeb10 ldr r0, [pc, #0x6e4] */
/* @0xeeb14 mov r2, #0 */
/* @0xeeb18 mov r3, #16384 */
/* @0xeeb1c add r0, pc, r0 */
/* @0xeeb20 movt r3, #0x405a */
/* @0xeeb24 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeb28 ldr r0, [pc, #0x6d0] */
/* @0xeeb2c mov r2, #0 */
/* @0xeeb30 mov r3, #49152 */
/* @0xeeb34 add r0, pc, r0 */
/* @0xeeb38 movt r3, #0x405b */
/* @0xeeb3c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeb40 ldr r0, [pc, #0x6bc] */
/* @0xeeb44 mov r2, #0 */
/* @0xeeb48 mov r3, #32768 */
/* @0xeeb4c add r0, pc, r0 */
/* @0xeeb50 movt r3, #0x405a */
/* @0xeeb54 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeb58 ldr r0, [pc, #0x6a8] */
/* @0xeeb5c mov r2, #0 */
/* @0xeeb60 mov r3, #16384 */
/* @0xeeb64 add r0, pc, r0 */
/* @0xeeb68 movt r3, #0x405b */
/* @0xeeb6c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeb70 ldr r0, [pc, #0x694] */
/* @0xeeb74 mov r2, #0 */
/* @0xeeb78 mov r3, #49152 */
/* @0xeeb7c add r0, pc, r0 */
/* @0xeeb80 movt r3, #0x405a */
/* @0xeeb84 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeb88 ldr r0, [pc, #0x680] */
/* @0xeeb8c mov r2, #0 */
/* @0xeeb90 mov r3, #32768 */
/* @0xeeb94 add r0, pc, r0 */
/* @0xeeb98 movt r3, #0x405b */
/* @0xeeb9c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeba0 ldr r0, [pc, #0x66c] */
/* @0xeeba4 mov r2, #0 */
/* @0xeeba8 mov r3, #0 */
/* @0xeebac add r0, pc, r0 */
/* @0xeebb0 movt r3, #0x4064 */
/* @0xeebb4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeebb8 ldr r0, [pc, #0x658] */
/* @0xeebbc mov r2, #0 */
/* @0xeebc0 mov r3, #16384 */
/* @0xeebc4 add r0, pc, r0 */
/* @0xeebc8 movt r3, #0x4064 */
/* @0xeebcc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeebd0 ldr r0, [pc, #0x644] */
/* @0xeebd4 mov r2, #0 */
/* @0xeebd8 mov r3, #32768 */
/* @0xeebdc add r0, pc, r0 */
/* @0xeebe0 movt r3, #0x4064 */
/* @0xeebe4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeebe8 ldr r0, [pc, #0x630] */
/* @0xeebec mov r2, #0 */
/* @0xeebf0 mov r3, #8192 */
/* @0xeebf4 add r0, pc, r0 */
/* @0xeebf8 movt r3, #0x4064 */
/* @0xeebfc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec00 ldr r0, [pc, #0x61c] */
/* @0xeec04 mov r2, #0 */
/* @0xeec08 mov r3, #24576 */
/* @0xeec0c add r0, pc, r0 */
/* @0xeec10 movt r3, #0x4064 */
/* @0xeec14 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec18 ldr r0, [pc, #0x608] */
/* @0xeec1c mov r2, #0 */
/* @0xeec20 mov r3, #40960 */
/* @0xeec24 add r0, pc, r0 */
/* @0xeec28 movt r3, #0x4064 */
/* @0xeec2c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec30 ldr r0, [pc, #0x5f4] */
/* @0xeec34 mov r2, #0 */
/* @0xeec38 mov r3, #32 */
/* @0xeec3c add r0, pc, r0 */
/* @0xeec40 movt r3, #0x40e0 */
/* @0xeec44 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec48 ldr r0, [pc, #0x5e0] */
/* @0xeec4c mov r2, #0 */
/* @0xeec50 mov r3, #64 */
/* @0xeec54 add r0, pc, r0 */
/* @0xeec58 movt r3, #0x40e0 */
/* @0xeec5c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec60 ldr r0, [pc, #0x5cc] */
/* @0xeec64 mov r2, #0 */
/* @0xeec68 mov r3, #96 */
/* @0xeec6c add r0, pc, r0 */
/* @0xeec70 movt r3, #0x40e0 */
/* @0xeec74 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec78 ldr r0, [pc, #0x5b8] */
/* @0xeec7c mov r2, #0 */
/* @0xeec80 mov r3, #128 */
/* @0xeec84 add r0, pc, r0 */
/* @0xeec88 movt r3, #0x40e0 */
/* @0xeec8c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeec90 ldr r0, [pc, #0x5a4] */
/* @0xeec94 mov r2, #0 */
/* @0xeec98 mov r3, #160 */
/* @0xeec9c add r0, pc, r0 */
/* @0xeeca0 movt r3, #0x40e0 */
/* @0xeeca4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeca8 ldr r0, [pc, #0x590] */
/* @0xeecac mov r2, #0 */
/* @0xeecb0 mov r3, #192 */
/* @0xeecb4 add r0, pc, r0 */
/* @0xeecb8 movt r3, #0x40e0 */
/* @0xeecbc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeecc0 ldr r0, [pc, #0x57c] */
/* @0xeecc4 mov r2, #0 */
/* @0xeecc8 mov r3, #224 */
/* @0xeeccc add r0, pc, r0 */
/* @0xeecd0 movt r3, #0x40e0 */
/* @0xeecd4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeecd8 ldr r0, [pc, #0x568] */
/* @0xeecdc mov r2, #0 */
/* @0xeece0 mov r3, #256 */
/* @0xeece4 add r0, pc, r0 */
/* @0xeece8 movt r3, #0x40e0 */
/* @0xeecec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeecf0 ldr r0, [pc, #0x554] */
/* @0xeecf4 mov r2, #0 */
/* @0xeecf8 mov r3, #288 */
/* @0xeecfc add r0, pc, r0 */
/* @0xeed00 movt r3, #0x40e0 */
/* @0xeed04 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed08 ldr r0, [pc, #0x540] */
/* @0xeed0c mov r2, #0 */
/* @0xeed10 mov r3, #320 */
/* @0xeed14 add r0, pc, r0 */
/* @0xeed18 movt r3, #0x40e0 */
/* @0xeed1c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed20 ldr r0, [pc, #0x52c] */
/* @0xeed24 mov r2, #0 */
/* @0xeed28 mov r3, #352 */
/* @0xeed2c add r0, pc, r0 */
/* @0xeed30 movt r3, #0x40e0 */
/* @0xeed34 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed38 ldr r0, [pc, #0x518] */
/* @0xeed3c mov r2, #0 */
/* @0xeed40 mov r3, #384 */
/* @0xeed44 add r0, pc, r0 */
/* @0xeed48 movt r3, #0x40e0 */
/* @0xeed4c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed50 ldr r0, [pc, #0x504] */
/* @0xeed54 mov r2, #0 */
/* @0xeed58 mov r3, #416 */
/* @0xeed5c add r0, pc, r0 */
/* @0xeed60 movt r3, #0x40e0 */
/* @0xeed64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed68 ldr r0, [pc, #0x4f0] */
/* @0xeed6c mov r2, #0 */
/* @0xeed70 mov r3, #448 */
/* @0xeed74 add r0, pc, r0 */
/* @0xeed78 movt r3, #0x40e0 */
/* @0xeed7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed80 ldr r0, [pc, #0x4dc] */
/* @0xeed84 mov r2, #0 */
/* @0xeed88 mov r3, #480 */
/* @0xeed8c add r0, pc, r0 */
/* @0xeed90 movt r3, #0x40e0 */
/* @0xeed94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeed98 ldr r0, [pc, #0x4c8] */
/* @0xeed9c mov r2, #0 */
/* @0xeeda0 mov r3, #512 */
/* @0xeeda4 add r0, pc, r0 */
/* @0xeeda8 movt r3, #0x40e0 */
/* @0xeedac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeedb0 ldr r0, [pc, #0x4b4] */
/* @0xeedb4 mov r2, #0 */
/* @0xeedb8 mov r3, #544 */
/* @0xeedbc add r0, pc, r0 */
/* @0xeedc0 movt r3, #0x40e0 */
/* @0xeedc4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeedc8 ldr r0, [pc, #0x4a0] */
/* @0xeedcc mov r2, #0 */
/* @0xeedd0 mov r3, #576 */
/* @0xeedd4 add r0, pc, r0 */
/* @0xeedd8 movt r3, #0x40e0 */
/* @0xeeddc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeede0 ldr r0, [pc, #0x48c] */
/* @0xeede4 mov r2, #0 */
/* @0xeede8 mov r3, #608 */
/* @0xeedec add r0, pc, r0 */
/* @0xeedf0 movt r3, #0x40e0 */
/* @0xeedf4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeedf8 ldr r0, [pc, #0x478] */
/* @0xeedfc mov r2, #0 */
/* @0xeee00 mov r3, #640 */
/* @0xeee04 add r0, pc, r0 */
/* @0xeee08 movt r3, #0x40e0 */
/* @0xeee0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee10 ldr r0, [pc, #0x464] */
/* @0xeee14 mov r2, #0 */
/* @0xeee18 mov r3, #0 */
/* @0xeee1c add r0, pc, r0 */
/* @0xeee20 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee24 ldr r0, [pc, #0x454] */
/* @0xeee28 mov r2, #0 */
/* @0xeee2c mov r3, #0 */
/* @0xeee30 add r0, pc, r0 */
/* @0xeee34 movt r3, #0x3ff0 */
/* @0xeee38 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee3c ldr r0, [pc, #0x440] */
/* @0xeee40 mov r2, #0 */
/* @0xeee44 mov r3, #0 */
/* @0xeee48 add r0, pc, r0 */
/* @0xeee4c movt r3, #0x4028 */
/* @0xeee50 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee54 ldr r0, [pc, #0x42c] */
/* @0xeee58 mov r2, #0 */
/* @0xeee5c mov r3, #0 */
/* @0xeee60 add r0, pc, r0 */
/* @0xeee64 movt r3, #0x4008 */
/* @0xeee68 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee6c ldr r0, [pc, #0x418] */
/* @0xeee70 mov r2, #0 */
/* @0xeee74 mov r3, #1073741824 */
/* @0xeee78 add r0, pc, r0 */
/* @0xeee7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee80 ldr r0, [pc, #0x408] */
/* @0xeee84 mov r2, #0 */
/* @0xeee88 mov r3, #0 */
/* @0xeee8c add r0, pc, r0 */
/* @0xeee90 movt r3, #0x4014 */
/* @0xeee94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeee98 ldr r0, [pc, #0x3f4] */
/* @0xeee9c mov r2, #0 */
/* @0xeeea0 mov r3, #0 */
/* @0xeeea4 add r0, pc, r0 */
/* @0xeeea8 movt r3, #0x4018 */
/* @0xeeeac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeeb0 ldr r0, [pc, #0x3e0] */
/* @0xeeeb4 mov r2, #0 */
/* @0xeeeb8 mov r3, #0 */
/* @0xeeebc add r0, pc, r0 */
/* @0xeeec0 movt r3, #0x4010 */
/* @0xeeec4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeec8 ldr r0, [pc, #0x3cc] */
/* @0xeeecc mov r2, #0 */
/* @0xeeed0 mov r3, #0 */
/* @0xeeed4 add r0, pc, r0 */
/* @0xeeed8 movt r3, #0x401c */
/* @0xeeedc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeee0 ldr r0, [pc, #0x3b8] */
/* @0xeeee4 mov r2, #0 */
/* @0xeeee8 mov r3, #0 */
/* @0xeeeec add r0, pc, r0 */
/* @0xeeef0 movt r3, #0x4020 */
/* @0xeeef4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeeef8 ldr r0, [pc, #0x3a4] */
/* @0xeeefc mov r2, #0 */
/* @0xeef00 mov r3, #0 */
/* @0xeef04 add r0, pc, r0 */
/* @0xeef08 movt r3, #0x4022 */
/* @0xeef0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeef10 ldr r0, [pc, #0x390] */
/* @0xeef14 mov r2, #0 */
/* @0xeef18 mov r3, #0 */
/* @0xeef1c add r0, pc, r0 */
/* @0xeef20 movt r3, #0x4024 */
/* @0xeef24 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeef28 ldr r0, [pc, #0x37c] */
/* @0xeef2c mov r2, #0 */
/* @0xeef30 mov r3, #0 */
/* @0xeef34 add r0, pc, r0 */
/* @0xeef38 movt r3, #0x4026 */
/* @0xeef3c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeef40 ldrb r3, [r4] */
/* @0xeef44 cmp r3, #0 */
/* @0xeef48 bne 0xf13dc <_Z24INITIALIZE_Code_Constantv+0x33c0> */
/* @0xeef4c ldr r0, [pc, #0x35c] */
/* @0xeef50 mov r2, #0 */
/* @0xeef54 mov r3, #0 */
/* @0xeef58 add r0, pc, r0 */
/* @0xeef5c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeef60 ldr r0, [pc, #0x34c] */
/* @0xeef64 mov r2, #0 */
/* @0xeef68 mov r3, #0 */
/* @0xeef6c add r0, pc, r0 */
/* @0xeef70 movt r3, #0x3ff0 */
/* @0xeef74 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeef78 ldr r0, [pc, #0x338] */
/* @0xeef7c mov r2, #0 */
/* @0xeef80 mov r3, #1073741824 */
/* @0xeef84 add r0, pc, r0 */
/* @0xeef88 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeef8c ldr r0, [pc, #0x328] */
/* @0xeef90 mov r2, #0 */
/* @0xeef94 mov r3, #0 */
/* @0xeef98 add r0, pc, r0 */
/* @0xeef9c movt r3, #0x4008 */
/* @0xeefa0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeefa4 ldr r0, [pc, #0x314] */
/* @0xeefa8 mov r2, #0 */
/* @0xeefac mov r3, #0 */
/* @0xeefb0 add r0, pc, r0 */
/* @0xeefb4 movt r3, #0x4010 */
/* @0xeefb8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeefbc ldr r0, [pc, #0x300] */
/* @0xeefc0 mov r2, #0 */
/* @0xeefc4 mov r3, #0 */
/* @0xeefc8 add r0, pc, r0 */
/* @0xeefcc movt r3, #0x4014 */
/* @0xeefd0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeefd4 ldr r0, [pc, #0x2ec] */
/* @0xeefd8 mov r2, #0 */
/* @0xeefdc mov r3, #0 */
/* @0xeefe0 add r0, pc, r0 */
/* @0xeefe4 movt r3, #0x4018 */
/* @0xeefe8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeefec ldr r0, [pc, #0x2d8] */
/* @0xeeff0 mov r2, #0 */
/* @0xeeff4 mov r3, #0 */
/* @0xeeff8 add r0, pc, r0 */
/* @0xeeffc movt r3, #0x401c */
/* @0xef000 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef004 ldr r0, [pc, #0x2c4] */
/* @0xef008 mov r2, #0 */
/* @0xef00c mov r3, #0 */
/* @0xef010 add r0, pc, r0 */
/* @0xef014 movt r3, #0x4020 */
/* @0xef018 b 0xef58c <_Z24INITIALIZE_Code_Constantv+0x1570> */
/* @0xef01c mlaeq r4, r4, lr, r6 */
/* @0xef020 eoreq r6, r4, r0, lsl #29 */
/* @0xef024 eoreq pc, pc, r12, lsr r4 */
/* @0xef028 eoreq r6, r4, r0, ror lr */
/* @0xef02c eoreq r6, r4, r12, asr lr */
/* @0xef030 eoreq r6, r4, r12, asr #28 */
/* @0xef034 eoreq r6, r4, r12, lsr lr */
/* @0xef038 eoreq r6, r4, r4, ror #18 */
/* @0xef03c eoreq r6, r4, r4, asr r9 */
/* @0xef040 eoreq r6, r4, r0, lsl #28 */
/* @0xef044 eoreq r6, r4, r12, ror #27 */
/* @0xef048 eoreq r6, r4, r4, ror #27 */
/* @0xef04c .word 0x00246ddc */
/* @0xef050 .word 0x00246dd4 */
/* @0xef054 eoreq r6, r4, r12, asr #27 */
/* @0xef058 eoreq r6, r4, r8, asr #27 */
/* @0xef05c eoreq r6, r4, r0, asr #27 */
/* @0xef060 .word 0x00246db0 */
/* @0xef064 eoreq r6, r4, r4, lsr #27 */
/* @0xef068 mlaeq r4, r4, sp, r6 */
/* @0xef06c eoreq r6, r4, r8, lsl #27 */
/* @0xef070 eoreq r6, r4, r12, ror sp */
/* @0xef074 eoreq r6, r4, r12, ror #26 */
/* @0xef078 eoreq r6, r4, r12, asr sp */
/* @0xef07c eoreq r6, r4, r12, asr #26 */
/* @0xef080 eoreq r6, r4, r0, asr #26 */
/* @0xef084 eoreq r6, r4, r4, lsr sp */
/* @0xef088 eoreq r6, r4, r4, lsr #26 */
/* @0xef08c eoreq r6, r4, r4, lsl sp */
/* @0xef090 eoreq r6, r4, r8, lsl #26 */
/* @0xef094 .word 0x00246cf8 */
/* @0xef098 eoreq r6, r4, r12, ror #25 */
/* @0xef09c .word 0x00246cdc */
/* @0xef0a0 eoreq r6, r4, r12, asr #25 */
/* @0xef0a4 eoreq r6, r4, r0, asr #25 */
/* @0xef0a8 .word 0x00246cb4 */
/* @0xef0ac eoreq r6, r4, r12, lsr #25 */
/* @0xef0b0 mlaeq r4, r12, r12, r6 */
/* @0xef0b4 mlaeq r4, r0, r12, r6 */
/* @0xef0b8 eoreq r6, r4, r4, lsl #25 */
/* @0xef0bc eoreq r6, r4, r4, ror r12 */
/* @0xef0c0 eoreq r6, r4, r8, ror #24 */
/* @0xef0c4 eoreq r6, r4, r0, ror #24 */
/* @0xef0c8 eoreq r6, r4, r8, asr r12 */
/* @0xef0cc eoreq r6, r4, r4, asr r12 */
/* @0xef0d0 eoreq r6, r4, r0, asr r12 */
/* @0xef0d4 eoreq r6, r4, r8, asr #24 */
/* @0xef0d8 eoreq r6, r4, r4, asr #24 */
/* @0xef0dc eoreq r6, r4, r12, lsr r12 */
/* @0xef0e0 eoreq r6, r4, r8, lsr r12 */
/* @0xef0e4 eoreq r6, r4, r0, lsr r12 */
/* @0xef0e8 eoreq r6, r4, r8, lsr #24 */
/* @0xef0ec eoreq r6, r4, r4, lsr #24 */
/* @0xef0f0 eoreq r6, r4, r8, asr r12 */
/* @0xef0f4 eoreq r6, r4, r8, asr r12 */
/* @0xef0f8 eoreq r6, r4, r0, ror #24 */
/* @0xef0fc eoreq r6, r4, r4, ror r12 */
/* @0xef100 eoreq r6, r4, r12, ror r12 */
/* @0xef104 eoreq r6, r4, r12, lsl #25 */
/* @0xef108 mlaeq r4, r4, r12, r6 */
/* @0xef10c eoreq r6, r4, r4, lsr #25 */
/* @0xef110 eoreq r6, r4, r4, lsr #25 */
/* @0xef114 eoreq r6, r4, r0, lsr #25 */
/* @0xef118 mlaeq r4, r8, r12, r6 */
/* @0xef11c mlaeq r4, r0, r12, r6 */
/* @0xef120 eoreq r6, r4, r8, lsl #25 */
/* @0xef124 eoreq r6, r4, r12, ror r12 */
/* @0xef128 eoreq r6, r4, r0, ror r12 */
/* @0xef12c eoreq r6, r4, r8, ror #24 */
/* @0xef130 eoreq r6, r4, r12, asr r12 */
/* @0xef134 eoreq r6, r4, r0, asr r12 */
/* @0xef138 eoreq r6, r4, r8, asr #24 */
/* @0xef13c eoreq r6, r4, r8, lsr r12 */
/* @0xef140 eoreq r6, r4, r12, lsr #24 */
/* @0xef144 eoreq r6, r4, r12, lsl r12 */
/* @0xef148 eoreq r6, r4, r4, lsl r12 */
/* @0xef14c eoreq r6, r4, r8, lsl #24 */
/* @0xef150 eoreq r6, r4, r0, lsl #24 */
/* @0xef154 .word 0x00246bf4 */
/* @0xef158 eoreq r6, r4, r8, ror #23 */
/* @0xef15c .word 0x00246bdc */
/* @0xef160 .word 0x00246bd0 */
/* @0xef164 eoreq r6, r4, r4, asr #23 */
/* @0xef168 .word 0x00246bb4 */
/* @0xef16c eoreq r6, r4, r8, lsr #23 */
/* @0xef170 mlaeq r4, r12, r11, r6 */
/* @0xef174 mlaeq r4, r4, r11, r6 */
/* @0xef178 eoreq r6, r4, r4, lsl #23 */
/* @0xef17c eoreq r6, r4, r8, ror r11 */
/* @0xef180 eoreq r6, r4, r0, ror r11 */
/* @0xef184 eoreq r6, r4, r0, ror #22 */
/* @0xef188 eoreq r6, r4, r4, asr r11 */
/* @0xef18c eoreq r6, r4, r4, asr #22 */
/* @0xef190 eoreq r6, r4, r4, lsr r11 */
/* @0xef194 eoreq r6, r4, r4, lsr #22 */
/* @0xef198 eoreq r6, r4, r4, lsl r11 */
/* @0xef19c eoreq r6, r4, r8, lsl #22 */
/* @0xef1a0 .word 0x00246afc */
/* @0xef1a4 .word 0x00246af0 */
/* @0xef1a8 eoreq r6, r4, r4, ror #21 */
/* @0xef1ac .word 0x00246ad4 */
/* @0xef1b0 eoreq r6, r4, r4, asr #21 */
/* @0xef1b4 .word 0x00246ab4 */
/* @0xef1b8 eoreq r6, r4, r4, lsr #21 */
/* @0xef1bc mlaeq r4, r4, r10, r6 */
/* @0xef1c0 eoreq r6, r4, r4, lsl #21 */
/* @0xef1c4 eoreq r6, r4, r4, ror r10 */
/* @0xef1c8 eoreq r6, r4, r4, ror #20 */
/* @0xef1cc eoreq r6, r4, r4, asr r10 */
/* @0xef1d0 eoreq r6, r4, r4, asr #20 */
/* @0xef1d4 eoreq r6, r4, r4, lsr r10 */
/* @0xef1d8 eoreq r6, r4, r4, lsr #20 */
/* @0xef1dc eoreq r6, r4, r8, lsl r10 */
/* @0xef1e0 eoreq r6, r4, r12, lsl #20 */
/* @0xef1e4 eoreq r6, r4, r0, lsl #20 */
/* @0xef1e8 .word 0x002469f4 */
/* @0xef1ec eoreq r6, r4, r8, ror #19 */
/* @0xef1f0 .word 0x002469dc */
/* @0xef1f4 .word 0x002469d0 */
/* @0xef1f8 eoreq r6, r4, r4, asr #19 */
/* @0xef1fc .word 0x002469b8 */
/* @0xef200 eoreq r6, r4, r12, lsr #19 */
/* @0xef204 eoreq r6, r4, r0, lsr #19 */
/* @0xef208 mlaeq r4, r4, r9, r6 */
/* @0xef20c eoreq r6, r4, r8, lsl #19 */
/* @0xef210 eoreq r6, r4, r8, ror r9 */
/* @0xef214 eoreq r6, r4, r12, ror #18 */
/* @0xef218 eoreq r6, r4, r0, ror #18 */
/* @0xef21c eoreq r6, r4, r4, asr r9 */
/* @0xef220 eoreq r6, r4, r4, asr #18 */
/* @0xef224 eoreq r6, r4, r8, lsr r9 */
/* @0xef228 eoreq r6, r4, r12, lsr #18 */
/* @0xef22c eoreq r6, r4, r12, lsl r9 */
/* @0xef230 eoreq r6, r4, r0, lsl r9 */
/* @0xef234 eoreq r6, r4, r4, lsl #18 */
/* @0xef238 .word 0x002468f8 */
/* @0xef23c eoreq r6, r4, r12, ror #17 */
/* @0xef240 eoreq r6, r4, r4, ror #17 */
/* @0xef244 .word 0x002468dc */
/* @0xef248 .word 0x002468d4 */
/* @0xef24c eoreq r6, r4, r12, asr #17 */
/* @0xef250 eoreq r6, r4, r0, asr #17 */
/* @0xef254 .word 0x002468b4 */
/* @0xef258 eoreq r6, r4, r8, lsr #17 */
/* @0xef25c mlaeq r4, r12, r8, r6 */
/* @0xef260 eoreq r6, r4, r12, lsl #17 */
/* @0xef264 eoreq r6, r4, r12, ror r8 */
/* @0xef268 eoreq r6, r4, r12, ror #16 */
/* @0xef26c eoreq r6, r4, r12, asr r8 */
/* @0xef270 eoreq r6, r4, r0, asr r8 */
/* @0xef274 eoreq r6, r4, r4, asr #16 */
/* @0xef278 eoreq r6, r4, r8, lsr r8 */
/* @0xef27c eoreq r6, r4, r12, lsr #16 */
/* @0xef280 eoreq r6, r4, r4, lsr #16 */
/* @0xef284 eoreq r6, r4, r8, lsl r8 */
/* @0xef288 eoreq r6, r4, r12, lsl #16 */
/* @0xef28c .word 0x002467fc */
/* @0xef290 .word 0x002467f4 */
/* @0xef294 eoreq r6, r4, r8, ror #15 */
/* @0xef298 .word 0x002467dc */
/* @0xef29c .word 0x002467d4 */
/* @0xef2a0 eoreq r6, r4, r8, asr #15 */
/* @0xef2a4 .word 0x002467b8 */
/* @0xef2a8 eoreq r6, r4, r12, lsr #15 */
/* @0xef2ac eoreq r6, r4, r4, lsr #15 */
/* @0xef2b0 .word 0x002467b4 */
/* @0xef2b4 .word 0x002467b0 */
/* @0xef2b8 eoreq r6, r4, r8, lsr #15 */
/* @0xef2bc eoreq r6, r4, r8, lsr #15 */
/* @0xef2c0 eoreq r6, r4, r0, lsr #15 */
/* @0xef2c4 mlaeq r4, r8, r7, r6 */
/* @0xef2c8 mlaeq r4, r0, r7, r6 */
/* @0xef2cc eoreq r6, r4, r8, lsl #15 */
/* @0xef2d0 eoreq r6, r4, r0, lsl #15 */
/* @0xef2d4 eoreq r6, r4, r8, lsl #4 */
/* @0xef2d8 eoreq r6, r4, r4, lsl #4 */
/* @0xef2dc .word 0x002461fc */
/* @0xef2e0 .word 0x002461f4 */
/* @0xef2e4 eoreq r6, r4, r12, ror #3 */
/* @0xef2e8 eoreq r6, r4, r8, ror #3 */
/* @0xef2ec eoreq r6, r4, r4, ror #3 */
/* @0xef2f0 eoreq r6, r4, r0, ror #3 */
/* @0xef2f4 .word 0x002461d8 */
/* @0xef2f8 .word 0x002461d4 */
/* @0xef2fc .word 0x002461d4 */
/* @0xef300 .word 0x002461d4 */
/* @0xef304 .word 0x002461d4 */
/* @0xef308 .word 0x002461d4 */
/* @0xef30c .word 0x002461d4 */
/* @0xef310 .word 0x002461d4 */
/* @0xef314 .word 0x002461d4 */
/* @0xef318 .word 0x002461d4 */
/* @0xef31c .word 0x002461d0 */
/* @0xef320 eoreq r6, r4, r12, asr #3 */
/* @0xef324 eoreq r6, r4, r4, asr #3 */
/* @0xef328 eoreq r6, r4, r0, asr #3 */
/* @0xef32c eoreq r6, r4, r0, asr #3 */
/* @0xef330 eoreq r6, r4, r0, asr #3 */
/* @0xef334 eoreq r6, r4, r0, asr #3 */
/* @0xef338 eoreq r6, r4, r0, asr #3 */
/* @0xef33c eoreq r6, r4, r0, asr #3 */
/* @0xef340 eoreq r6, r4, r0, asr #3 */
/* @0xef344 eoreq r6, r4, r0, asr #3 */
/* @0xef348 eoreq r6, r4, r0, asr #3 */
/* @0xef34c eoreq r6, r4, r0, asr #3 */
/* @0xef350 eoreq r6, r4, r0, asr #3 */
/* @0xef354 eoreq r6, r4, r0, asr #3 */
/* @0xef358 eoreq r6, r4, r0, asr #3 */
/* @0xef35c eoreq r6, r4, r0, asr #3 */
/* @0xef360 eoreq r6, r4, r0, asr #3 */
/* @0xef364 eoreq r6, r4, r0, asr #3 */
/* @0xef368 eoreq r6, r4, r0, asr #3 */
/* @0xef36c eoreq r6, r4, r4, asr #3 */
/* @0xef370 eoreq r6, r4, r0, asr #3 */
/* @0xef374 .word 0x002461bc */
/* @0xef378 .word 0x002461b4 */
/* @0xef37c eoreq r6, r4, r8, lsr #3 */
/* @0xef380 eoreq r6, r4, r4, lsr #3 */
/* @0xef384 mlaeq r4, r8, r1, r6 */
/* @0xef388 mlaeq r4, r0, r1, r6 */
/* @0xef38c eoreq r6, r4, r4, lsl #3 */
/* @0xef390 eoreq r6, r4, r0, lsl #3 */
/* @0xef394 eoreq r6, r4, r12, ror r1 */
/* @0xef398 eoreq r6, r4, r4, ror r1 */
/* @0xef39c eoreq r6, r4, r0, ror r1 */
/* @0xef3a0 eoreq r6, r4, r4, ror #2 */
/* @0xef3a4 eoreq r6, r4, r8, asr r1 */
/* @0xef3a8 eoreq r6, r4, r12, asr #2 */
/* @0xef3ac eoreq r6, r4, r0, asr #2 */
/* @0xef3b0 eoreq r6, r4, r4, lsr r1 */
/* @0xef3b4 eoreq r6, r4, r8, lsr #2 */
/* @0xef3b8 eoreq r6, r4, r12, lsl r1 */
/* @0xef3bc eoreq r6, r4, r0, lsl r1 */
/* @0xef3c0 eoreq r6, r4, r4, lsl #2 */
/* @0xef3c4 .word 0x002460f8 */
/* @0xef3c8 eoreq r6, r4, r12, ror #1 */
/* @0xef3cc eoreq r6, r4, r0, ror #1 */
/* @0xef3d0 .word 0x002460d4 */
/* @0xef3d4 eoreq r6, r4, r8, asr #1 */
/* @0xef3d8 strhteq r6, [r4], -r12 */
/* @0xef3dc strhteq r6, [r4], -r0 */
/* @0xef3e0 eoreq r6, r4, r8, lsr #1 */
/* @0xef3e4 eoreq r6, r4, r4, lsr #1 */
/* @0xef3e8 mlaeq r4, r12, r0, r6 */
/* @0xef3ec eoreq r6, r4, r8, lsl r3 */
/* @0xef3f0 eoreq r6, r4, r0, lsl r3 */
/* @0xef3f4 eoreq r6, r4, r4, lsl #6 */
/* @0xef3f8 .word 0x002462f4 */
/* @0xef3fc eoreq r6, r4, r4, ror #5 */
/* @0xef400 .word 0x002462d8 */
/* @0xef404 .word 0x002462d0 */
/* @0xef408 eoreq r6, r4, r4, asr #5 */
/* @0xef40c .word 0x002462b8 */
/* @0xef410 .word 0x002462b8 */
/* @0xef414 .word 0x002462b0 */
/* @0xef418 eoreq r6, r4, r12, lsr #5 */
/* @0xef41c eoreq r6, r4, r8, lsr #5 */
/* @0xef420 eoreq r6, r4, r0, lsr #5 */
/* @0xef424 mlaeq r4, r4, r2, r6 */
/* @0xef428 eoreq lr, pc, r12, asr #32 */
/* @0xef42c eoreq r6, r4, r8, lsl #5 */
/* @0xef430 eoreq r6, r4, r0, lsl #5 */
/* @0xef434 eoreq r6, r4, r8, ror r2 */
/* @0xef438 eoreq r6, r4, r12, ror #4 */
/* @0xef43c eoreq r6, r4, r0, ror #4 */
/* @0xef440 eoreq r6, r4, r8, asr r2 */
/* @0xef444 eoreq r6, r4, r12, asr #4 */
/* @0xef448 eoreq r6, r4, r4, asr #4 */
/* @0xef44c eoreq r6, r4, r4, lsr r2 */
/* @0xef450 eoreq r6, r4, r12, lsr #4 */
/* @0xef454 eoreq r6, r4, r0, lsr #4 */
/* @0xef458 eoreq r6, r4, r0, lsl r2 */
/* @0xef45c eoreq r6, r4, r8, lsl #4 */
/* @0xef460 .word 0x002461fc */
/* @0xef464 .word 0x002461f4 */
/* @0xef468 eoreq r6, r4, r8, ror #3 */
/* @0xef46c .word 0x002461dc */
/* @0xef470 .word 0x002461d4 */
/* @0xef474 eoreq r6, r4, r4, asr #3 */
/* @0xef478 .word 0x002461b8 */
/* @0xef47c eoreq r6, r4, r12, lsr #3 */
/* @0xef480 eoreq r6, r4, r0, lsr #3 */
/* @0xef484 mlaeq r4, r8, r1, r6 */
/* @0xef488 eoreq r6, r4, r12, lsl #3 */
/* @0xef48c eoreq r6, r4, r12, ror r1 */
/* @0xef490 eoreq r6, r4, r0, ror r1 */
/* @0xef494 eoreq r6, r4, r0, ror #2 */
/* @0xef498 eoreq r6, r4, r8, asr r1 */
/* @0xef49c eoreq r6, r4, r12, asr #2 */
/* @0xef4a0 eoreq r6, r4, r8, asr #2 */
/* @0xef4a4 eoreq r6, r4, r0, asr #2 */
/* @0xef4a8 eoreq r6, r4, r12, lsr r1 */
/* @0xef4ac eoreq r6, r4, r4, lsr r1 */
/* @0xef4b0 eoreq r6, r4, r12, lsr #2 */
/* @0xef4b4 eoreq r6, r4, r4, lsr #2 */
/* @0xef4b8 eoreq r6, r4, r12, lsl r1 */
/* @0xef4bc eoreq r6, r4, r4, lsl r1 */
/* @0xef4c0 eoreq r6, r4, r12, lsl #2 */
/* @0xef4c4 eoreq r6, r4, r4, lsl #2 */
/* @0xef4c8 eoreq r6, r4, r0, lsl #2 */
/* @0xef4cc .word 0x002460f8 */
/* @0xef4d0 .word 0x002460f0 */
/* @0xef4d4 eoreq r6, r4, r8, ror #1 */
/* @0xef4d8 eoreq r6, r4, r4, ror #1 */
/* @0xef4dc eoreq r6, r4, r0, ror #1 */
/* @0xef4e0 eoreq r6, r4, r4, ror #1 */
/* @0xef4e4 eoreq r6, r4, r4, ror #1 */
/* @0xef4e8 eoreq r6, r4, r0, ror #1 */
/* @0xef4ec eoreq r6, r4, r0, ror #1 */
/* @0xef4f0 .word 0x002460d8 */
/* @0xef4f4 .word 0x002460d8 */
/* @0xef4f8 .word 0x002460d0 */
/* @0xef4fc .word 0x002460d0 */
/* @0xef500 .word 0x002460d0 */
/* @0xef504 .word 0x002460d0 */
/* @0xef508 eoreq r6, r4, r12, asr #1 */
/* @0xef50c eoreq r6, r4, r4, asr #1 */
/* @0xef510 eoreq r6, r4, r4, asr #1 */
/* @0xef514 eoreq r6, r4, r0, asr #1 */
/* @0xef518 strhteq r6, [r4], -r0 */
/* @0xef51c eoreq r6, r4, r8, lsr #1 */
/* @0xef520 mlaeq r4, r12, r0, r6 */
/* @0xef524 mlaeq r4, r0, r0, r6 */
/* @0xef528 eoreq r6, r4, r4, lsl #1 */
/* @0xef52c eoreq r6, r4, r4, ror r0 */
/* @0xef530 eoreq r6, r4, r8, rrx */
/* @0xef534 eoreq r6, r4, r12, asr r0 */
/* @0xef538 eoreq r6, r4, r0, asr r0 */
/* @0xef53c eoreq r6, r4, r0, asr #32 */
/* @0xef540 eoreq r6, r4, r0, lsr r0 */
/* @0xef544 eoreq r6, r4, r0, lsr r0 */
/* @0xef548 eoreq r6, r4, r12, lsr #32 */
/* @0xef54c eoreq r6, r4, r4, lsr r0 */
/* @0xef550 eoreq r6, r4, r8, lsr r0 */
/* @0xef554 eoreq r6, r4, r12, lsr #32 */
/* @0xef558 eoreq r6, r4, r4, lsr #32 */
/* @0xef55c eoreq r6, r4, r12, lsl r0 */
/* @0xef560 eoreq r6, r4, r4 */
/* @0xef564 .word 0x00245ff4 */
/* @0xef568 eoreq r5, r4, r8, ror #31 */
/* @0xef56c .word 0x00245fdc */
/* @0xef570 .word 0x00245fd0 */
/* @0xef574 eoreq r5, r4, r4, asr #31 */
/* @0xef578 .word 0x00245fb8 */
/* @0xef57c eoreq r5, r4, r12, lsr #31 */
/* @0xef580 eoreq r5, r4, r4, lsr #31 */
/* @0xef584 mlaeq r4, r4, pc, r5 */
/* @0xef588 eoreq r5, r4, r4, lsl #31 */
/* @0xef58c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef590 ldr r0, [pc, #-0x2c4] */
/* @0xef594 mov r2, #0 */
/* @0xef598 mov r3, #0 */
/* @0xef59c add r0, pc, r0 */
/* @0xef5a0 movt r3, #0x4022 */
/* @0xef5a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef5a8 ldr r0, [pc, #-0x2d8] */
/* @0xef5ac mov r2, #0 */
/* @0xef5b0 mov r3, #0 */
/* @0xef5b4 add r0, pc, r0 */
/* @0xef5b8 movt r3, #0x4024 */
/* @0xef5bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef5c0 ldr r0, [pc, #-0x2ec] */
/* @0xef5c4 mov r2, #0 */
/* @0xef5c8 mov r3, #0 */
/* @0xef5cc add r0, pc, r0 */
/* @0xef5d0 movt r3, #0x4026 */
/* @0xef5d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef5d8 ldr r0, [pc, #-0x300] */
/* @0xef5dc mov r2, #0 */
/* @0xef5e0 mov r3, #0 */
/* @0xef5e4 add r0, pc, r0 */
/* @0xef5e8 movt r3, #0x4028 */
/* @0xef5ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef5f0 ldr r0, [pc, #-0x314] */
/* @0xef5f4 mov r2, #0 */
/* @0xef5f8 mov r3, #0 */
/* @0xef5fc add r0, pc, r0 */
/* @0xef600 movt r3, #0x402a */
/* @0xef604 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef608 ldr r0, [pc, #-0x328] */
/* @0xef60c mov r2, #0 */
/* @0xef610 mov r3, #0 */
/* @0xef614 add r0, pc, r0 */
/* @0xef618 movt r3, #0x4030 */
/* @0xef61c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef620 ldr r0, [pc, #-0x33c] */
/* @0xef624 mov r2, #0 */
/* @0xef628 mov r3, #0 */
/* @0xef62c add r0, pc, r0 */
/* @0xef630 movt r3, #0x4031 */
/* @0xef634 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef638 ldr r0, [pc, #-0x350] */
/* @0xef63c mov r2, #0 */
/* @0xef640 mov r3, #0 */
/* @0xef644 add r0, pc, r0 */
/* @0xef648 movt r3, #0x4032 */
/* @0xef64c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef650 ldr r0, [pc, #-0x364] */
/* @0xef654 mov r2, #0 */
/* @0xef658 mov r3, #0 */
/* @0xef65c add r0, pc, r0 */
/* @0xef660 movt r3, #0x4033 */
/* @0xef664 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef668 ldr r0, [pc, #-0x378] */
/* @0xef66c mov r2, #0 */
/* @0xef670 mov r3, #0 */
/* @0xef674 add r0, pc, r0 */
/* @0xef678 movt r3, #0x4035 */
/* @0xef67c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef680 ldr r0, [pc, #-0x38c] */
/* @0xef684 mov r2, #0 */
/* @0xef688 mov r3, #0 */
/* @0xef68c add r0, pc, r0 */
/* @0xef690 movt r3, #0x4036 */
/* @0xef694 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef698 ldr r0, [pc, #-0x3a0] */
/* @0xef69c mov r2, #0 */
/* @0xef6a0 mov r3, #0 */
/* @0xef6a4 add r0, pc, r0 */
/* @0xef6a8 movt r3, #0x4037 */
/* @0xef6ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef6b0 ldr r0, [pc, #-0x3b4] */
/* @0xef6b4 mov r2, #0 */
/* @0xef6b8 mov r3, #0 */
/* @0xef6bc add r0, pc, r0 */
/* @0xef6c0 movt r3, #0x4038 */
/* @0xef6c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef6c8 ldr r0, [pc, #-0x3c8] */
/* @0xef6cc mov r2, #0 */
/* @0xef6d0 mov r3, #0 */
/* @0xef6d4 add r0, pc, r0 */
/* @0xef6d8 movt r3, #0x4039 */
/* @0xef6dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef6e0 ldr r0, [pc, #-0x3dc] */
/* @0xef6e4 mov r2, #0 */
/* @0xef6e8 mov r3, #0 */
/* @0xef6ec add r0, pc, r0 */
/* @0xef6f0 movt r3, #0x403a */
/* @0xef6f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef6f8 ldr r0, [pc, #-0x3f0] */
/* @0xef6fc mov r2, #0 */
/* @0xef700 mov r3, #0 */
/* @0xef704 add r0, pc, r0 */
/* @0xef708 movt r3, #0x403b */
/* @0xef70c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef710 ldr r0, [pc, #-0x404] */
/* @0xef714 mov r2, #0 */
/* @0xef718 mov r3, #0 */
/* @0xef71c add r0, pc, r0 */
/* @0xef720 movt r3, #0x403c */
/* @0xef724 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef728 ldr r0, [pc, #-0x418] */
/* @0xef72c mov r2, #0 */
/* @0xef730 mov r3, #0 */
/* @0xef734 add r0, pc, r0 */
/* @0xef738 movt r3, #0x403f */
/* @0xef73c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef740 ldr r0, [pc, #-0x42c] */
/* @0xef744 mov r2, #0 */
/* @0xef748 mov r3, #0 */
/* @0xef74c add r0, pc, r0 */
/* @0xef750 movt r3, #0x4040 */
/* @0xef754 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef758 ldr r0, [pc, #-0x440] */
/* @0xef75c mov r2, #0 */
/* @0xef760 mov r3, #32768 */
/* @0xef764 add r0, pc, r0 */
/* @0xef768 movt r3, #0x4040 */
/* @0xef76c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef770 ldr r0, [pc, #-0x454] */
/* @0xef774 mov r2, #0 */
/* @0xef778 mov r3, #0 */
/* @0xef77c add r0, pc, r0 */
/* @0xef780 movt r3, #0x4041 */
/* @0xef784 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef788 ldr r0, [pc, #-0x468] */
/* @0xef78c mov r2, #0 */
/* @0xef790 mov r3, #0 */
/* @0xef794 add r0, pc, r0 */
/* @0xef798 movt r3, #0x4042 */
/* @0xef79c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef7a0 ldr r0, [pc, #-0x47c] */
/* @0xef7a4 mov r2, #0 */
/* @0xef7a8 mov r3, #32768 */
/* @0xef7ac add r0, pc, r0 */
/* @0xef7b0 movt r3, #0x4042 */
/* @0xef7b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef7b8 ldr r0, [pc, #-0x490] */
/* @0xef7bc mov r2, #0 */
/* @0xef7c0 mov r3, #0 */
/* @0xef7c4 add r0, pc, r0 */
/* @0xef7c8 movt r3, #0x4043 */
/* @0xef7cc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef7d0 ldr r0, [pc, #-0x4a4] */
/* @0xef7d4 mov r2, #0 */
/* @0xef7d8 mov r3, #32768 */
/* @0xef7dc add r0, pc, r0 */
/* @0xef7e0 movt r3, #0x4043 */
/* @0xef7e4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef7e8 ldr r0, [pc, #-0x4b8] */
/* @0xef7ec mov r2, #0 */
/* @0xef7f0 mov r3, #0 */
/* @0xef7f4 add r0, pc, r0 */
/* @0xef7f8 movt r3, #0x4044 */
/* @0xef7fc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef800 ldr r0, [pc, #-0x4cc] */
/* @0xef804 mov r2, #0 */
/* @0xef808 mov r3, #32768 */
/* @0xef80c add r0, pc, r0 */
/* @0xef810 movt r3, #0x4044 */
/* @0xef814 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef818 ldr r0, [pc, #-0x4e0] */
/* @0xef81c mov r2, #0 */
/* @0xef820 mov r3, #0 */
/* @0xef824 add r0, pc, r0 */
/* @0xef828 movt r3, #0x4045 */
/* @0xef82c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef830 ldr r0, [pc, #-0x4f4] */
/* @0xef834 mov r2, #0 */
/* @0xef838 mov r3, #32768 */
/* @0xef83c add r0, pc, r0 */
/* @0xef840 movt r3, #0x4045 */
/* @0xef844 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef848 ldr r0, [pc, #-0x508] */
/* @0xef84c mov r2, #0 */
/* @0xef850 mov r3, #0 */
/* @0xef854 add r0, pc, r0 */
/* @0xef858 movt r3, #0x4049 */
/* @0xef85c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef860 ldr r0, [pc, #-0x51c] */
/* @0xef864 mov r2, #0 */
/* @0xef868 mov r3, #32768 */
/* @0xef86c add r0, pc, r0 */
/* @0xef870 movt r3, #0x4049 */
/* @0xef874 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef878 ldr r0, [pc, #-0x530] */
/* @0xef87c mov r2, #0 */
/* @0xef880 mov r3, #0 */
/* @0xef884 add r0, pc, r0 */
/* @0xef888 movt r3, #0x404a */
/* @0xef88c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef890 ldr r0, [pc, #-0x544] */
/* @0xef894 mov r2, #0 */
/* @0xef898 mov r3, #32768 */
/* @0xef89c add r0, pc, r0 */
/* @0xef8a0 movt r3, #0x404a */
/* @0xef8a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef8a8 ldr r0, [pc, #-0x558] */
/* @0xef8ac mov r2, #0 */
/* @0xef8b0 mov r3, #0 */
/* @0xef8b4 add r0, pc, r0 */
/* @0xef8b8 movt r3, #0x404b */
/* @0xef8bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef8c0 ldr r0, [pc, #-0x56c] */
/* @0xef8c4 mov r2, #0 */
/* @0xef8c8 mov r3, #32768 */
/* @0xef8cc add r0, pc, r0 */
/* @0xef8d0 movt r3, #0x404b */
/* @0xef8d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef8d8 ldr r0, [pc, #-0x580] */
/* @0xef8dc mov r2, #0 */
/* @0xef8e0 mov r3, #0 */
/* @0xef8e4 add r0, pc, r0 */
/* @0xef8e8 movt r3, #0x404c */
/* @0xef8ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef8f0 ldr r0, [pc, #-0x594] */
/* @0xef8f4 mov r2, #0 */
/* @0xef8f8 mov r3, #32768 */
/* @0xef8fc add r0, pc, r0 */
/* @0xef900 movt r3, #0x404c */
/* @0xef904 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef908 ldr r0, [pc, #-0x5a8] */
/* @0xef90c mov r2, #0 */
/* @0xef910 mov r3, #0 */
/* @0xef914 add r0, pc, r0 */
/* @0xef918 movt r3, #0x404d */
/* @0xef91c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef920 ldr r0, [pc, #-0x5bc] */
/* @0xef924 mov r2, #0 */
/* @0xef928 mov r3, #0 */
/* @0xef92c add r0, pc, r0 */
/* @0xef930 movt r3, #0x404e */
/* @0xef934 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef938 ldr r0, [pc, #-0x5d0] */
/* @0xef93c mov r2, #0 */
/* @0xef940 mov r3, #32768 */
/* @0xef944 add r0, pc, r0 */
/* @0xef948 movt r3, #0x404e */
/* @0xef94c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef950 ldr r0, [pc, #-0x5e4] */
/* @0xef954 mov r2, #0 */
/* @0xef958 mov r3, #0 */
/* @0xef95c add r0, pc, r0 */
/* @0xef960 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef964 ldr r0, [pc, #-0x5f4] */
/* @0xef968 mov r2, #0 */
/* @0xef96c mov r3, #0 */
/* @0xef970 add r0, pc, r0 */
/* @0xef974 movt r3, #0x3ff0 */
/* @0xef978 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef97c ldr r0, [pc, #-0x608] */
/* @0xef980 mov r2, #0 */
/* @0xef984 mov r3, #1073741824 */
/* @0xef988 add r0, pc, r0 */
/* @0xef98c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef990 ldr r0, [pc, #-0x618] */
/* @0xef994 mov r2, #0 */
/* @0xef998 mov r3, #0 */
/* @0xef99c add r0, pc, r0 */
/* @0xef9a0 movt r3, #0x4008 */
/* @0xef9a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef9a8 ldr r0, [pc, #-0x62c] */
/* @0xef9ac mov r2, #0 */
/* @0xef9b0 mov r3, #0 */
/* @0xef9b4 add r0, pc, r0 */
/* @0xef9b8 movt r3, #0x4010 */
/* @0xef9bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef9c0 ldr r0, [pc, #-0x640] */
/* @0xef9c4 mov r2, #0 */
/* @0xef9c8 mov r3, #0 */
/* @0xef9cc add r0, pc, r0 */
/* @0xef9d0 movt r3, #0x4014 */
/* @0xef9d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef9d8 ldr r0, [pc, #-0x654] */
/* @0xef9dc mov r2, #0 */
/* @0xef9e0 mov r3, #0 */
/* @0xef9e4 add r0, pc, r0 */
/* @0xef9e8 movt r3, #0x4018 */
/* @0xef9ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xef9f0 ldr r0, [pc, #-0x668] */
/* @0xef9f4 mov r2, #0 */
/* @0xef9f8 mov r3, #0 */
/* @0xef9fc add r0, pc, r0 */
/* @0xefa00 movt r3, #0x401c */
/* @0xefa04 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa08 ldr r0, [pc, #-0x67c] */
/* @0xefa0c mov r2, #0 */
/* @0xefa10 mov r3, #0 */
/* @0xefa14 add r0, pc, r0 */
/* @0xefa18 movt r3, #0x4020 */
/* @0xefa1c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa20 ldr r0, [pc, #-0x690] */
/* @0xefa24 mov r2, #0 */
/* @0xefa28 mov r3, #0 */
/* @0xefa2c add r0, pc, r0 */
/* @0xefa30 movt r3, #0x4022 */
/* @0xefa34 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa38 ldr r0, [pc, #-0x6a4] */
/* @0xefa3c mov r2, #0 */
/* @0xefa40 mov r3, #0 */
/* @0xefa44 add r0, pc, r0 */
/* @0xefa48 movt r3, #0x4024 */
/* @0xefa4c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa50 ldr r0, [pc, #-0x6b8] */
/* @0xefa54 mov r2, #0 */
/* @0xefa58 mov r3, #0 */
/* @0xefa5c add r0, pc, r0 */
/* @0xefa60 movt r3, #0x4026 */
/* @0xefa64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa68 ldr r0, [pc, #-0x6cc] */
/* @0xefa6c mov r2, #0 */
/* @0xefa70 mov r3, #0 */
/* @0xefa74 add r0, pc, r0 */
/* @0xefa78 movt r3, #0x4028 */
/* @0xefa7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa80 ldr r0, [pc, #-0x6e0] */
/* @0xefa84 mov r2, #0 */
/* @0xefa88 mov r3, #0 */
/* @0xefa8c add r0, pc, r0 */
/* @0xefa90 movt r3, #0x402a */
/* @0xefa94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefa98 ldr r0, [pc, #-0x6f4] */
/* @0xefa9c mov r2, #0 */
/* @0xefaa0 mov r3, #0 */
/* @0xefaa4 add r0, pc, r0 */
/* @0xefaa8 movt r3, #0x402c */
/* @0xefaac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefab0 ldr r0, [pc, #-0x708] */
/* @0xefab4 mov r2, #0 */
/* @0xefab8 mov r3, #0 */
/* @0xefabc add r0, pc, r0 */
/* @0xefac0 movt r3, #0x402e */
/* @0xefac4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefac8 ldr r0, [pc, #-0x71c] */
/* @0xefacc mov r2, #0 */
/* @0xefad0 mov r3, #0 */
/* @0xefad4 add r0, pc, r0 */
/* @0xefad8 movt r3, #0x4030 */
/* @0xefadc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefae0 ldr r0, [pc, #-0x730] */
/* @0xefae4 mov r2, #0 */
/* @0xefae8 mov r3, #0 */
/* @0xefaec add r0, pc, r0 */
/* @0xefaf0 movt r3, #0x4031 */
/* @0xefaf4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefaf8 ldr r0, [pc, #-0x744] */
/* @0xefafc mov r2, #0 */
/* @0xefb00 mov r3, #0 */
/* @0xefb04 add r0, pc, r0 */
/* @0xefb08 movt r3, #0x4032 */
/* @0xefb0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefb10 ldr r0, [pc, #-0x758] */
/* @0xefb14 mov r2, #0 */
/* @0xefb18 mov r3, #0 */
/* @0xefb1c add r0, pc, r0 */
/* @0xefb20 movt r3, #0x4033 */
/* @0xefb24 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefb28 ldr r0, [pc, #-0x76c] */
/* @0xefb2c mov r2, #0 */
/* @0xefb30 mov r3, #0 */
/* @0xefb34 add r0, pc, r0 */
/* @0xefb38 movt r3, #0x4034 */
/* @0xefb3c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefb40 ldr r0, [pc, #-0x780] */
/* @0xefb44 mov r2, #0 */
/* @0xefb48 mov r3, #0 */
/* @0xefb4c add r0, pc, r0 */
/* @0xefb50 movt r3, #0x4035 */
/* @0xefb54 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefb58 ldr r0, [pc, #-0x794] */
/* @0xefb5c mov r2, #0 */
/* @0xefb60 mov r3, #0 */
/* @0xefb64 add r0, pc, r0 */
/* @0xefb68 movt r3, #0x4036 */
/* @0xefb6c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefb70 ldr r0, [pc, #-0x7a8] */
/* @0xefb74 mov r2, #0 */
/* @0xefb78 mov r3, #0 */
/* @0xefb7c add r0, pc, r0 */
/* @0xefb80 movt r3, #0x4037 */
/* @0xefb84 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefb88 ldr r0, [pc, #-0x7bc] */
/* @0xefb8c mov r2, #0 */
/* @0xefb90 mov r3, #0 */
/* @0xefb94 add r0, pc, r0 */
/* @0xefb98 movt r3, #0x4038 */
/* @0xefb9c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefba0 ldr r0, [pc, #-0x7d0] */
/* @0xefba4 mov r2, #0 */
/* @0xefba8 mov r3, #0 */
/* @0xefbac add r0, pc, r0 */
/* @0xefbb0 movt r3, #0x4039 */
/* @0xefbb4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefbb8 ldr r0, [pc, #-0x7e4] */
/* @0xefbbc mov r2, #0 */
/* @0xefbc0 mov r3, #0 */
/* @0xefbc4 add r0, pc, r0 */
/* @0xefbc8 movt r3, #0x403e */
/* @0xefbcc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefbd0 ldr r0, [pc, #-0x7f8] */
/* @0xefbd4 mov r2, #0 */
/* @0xefbd8 mov r3, #0 */
/* @0xefbdc add r0, pc, r0 */
/* @0xefbe0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefbe4 ldr r0, [pc, #-0x808] */
/* @0xefbe8 mov r2, #0 */
/* @0xefbec mov r3, #0 */
/* @0xefbf0 add r0, pc, r0 */
/* @0xefbf4 movt r3, #0x3ff0 */
/* @0xefbf8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefbfc ldr r0, [pc, #-0x81c] */
/* @0xefc00 mov r3, #1073741824 */
/* @0xefc04 mov r2, #0 */
/* @0xefc08 add r0, pc, r0 */
/* @0xefc0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefc10 ldrb r3, [r4] */
/* @0xefc14 cmp r3, #0 */
/* @0xefc18 bne 0xf1170 <_Z24INITIALIZE_Code_Constantv+0x3154> */
/* @0xefc1c ldr r0, [pc, #-0x838] */
/* @0xefc20 mov r2, #0 */
/* @0xefc24 mov r3, #0 */
/* @0xefc28 movt r3, #0x404f */
/* @0xefc2c add r0, pc, r0 */
/* @0xefc30 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefc34 ldr r0, [pc, #-0x84c] */
/* @0xefc38 mov r2, #0 */
/* @0xefc3c mov r3, #32768 */
/* @0xefc40 add r0, pc, r0 */
/* @0xefc44 movt r3, #0x404f */
/* @0xefc48 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefc4c ldr r0, [pc, #-0x860] */
/* @0xefc50 mov r2, #0 */
/* @0xefc54 mov r3, #0 */
/* @0xefc58 add r0, pc, r0 */
/* @0xefc5c movt r3, #0x4050 */
/* @0xefc60 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefc64 ldr r0, [pc, #-0x874] */
/* @0xefc68 mov r2, #0 */
/* @0xefc6c mov r3, #32768 */
/* @0xefc70 add r0, pc, r0 */
/* @0xefc74 movt r3, #0x4050 */
/* @0xefc78 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefc7c ldr r0, [pc, #-0x888] */
/* @0xefc80 mov r2, #0 */
/* @0xefc84 mov r3, #49152 */
/* @0xefc88 add r0, pc, r0 */
/* @0xefc8c movt r3, #0x4050 */
/* @0xefc90 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefc94 ldr r0, [pc, #-0x89c] */
/* @0xefc98 mov r2, #0 */
/* @0xefc9c mov r3, #0 */
/* @0xefca0 add r0, pc, r0 */
/* @0xefca4 movt r3, #0x4051 */
/* @0xefca8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefcac ldr r0, [pc, #-0x8b0] */
/* @0xefcb0 mov r2, #0 */
/* @0xefcb4 mov r3, #16384 */
/* @0xefcb8 add r0, pc, r0 */
/* @0xefcbc movt r3, #0x4051 */
/* @0xefcc0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefcc4 ldr r0, [pc, #-0x8c4] */
/* @0xefcc8 mov r2, #0 */
/* @0xefccc mov r3, #32768 */
/* @0xefcd0 add r0, pc, r0 */
/* @0xefcd4 movt r3, #0x4051 */
/* @0xefcd8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefcdc ldr r0, [pc, #-0x8d8] */
/* @0xefce0 mov r2, #0 */
/* @0xefce4 mov r3, #49152 */
/* @0xefce8 add r0, pc, r0 */
/* @0xefcec movt r3, #0x4051 */
/* @0xefcf0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefcf4 ldr r0, [pc, #-0x8ec] */
/* @0xefcf8 mov r2, #0 */
/* @0xefcfc mov r3, #0 */
/* @0xefd00 add r0, pc, r0 */
/* @0xefd04 movt r3, #0x4052 */
/* @0xefd08 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefd0c ldr r0, [pc, #-0x900] */
/* @0xefd10 mov r2, #0 */
/* @0xefd14 mov r3, #16384 */
/* @0xefd18 add r0, pc, r0 */
/* @0xefd1c movt r3, #0x4052 */
/* @0xefd20 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefd24 ldr r0, [pc, #-0x914] */
/* @0xefd28 mov r2, #0 */
/* @0xefd2c mov r3, #32768 */
/* @0xefd30 add r0, pc, r0 */
/* @0xefd34 movt r3, #0x4052 */
/* @0xefd38 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefd3c ldr r0, [pc, #-0x928] */
/* @0xefd40 mov r2, #0 */
/* @0xefd44 mov r3, #49152 */
/* @0xefd48 add r0, pc, r0 */
/* @0xefd4c movt r3, #0x4052 */
/* @0xefd50 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefd54 ldr r0, [pc, #-0x93c] */
/* @0xefd58 mov r2, #0 */
/* @0xefd5c mov r3, #0 */
/* @0xefd60 add r0, pc, r0 */
/* @0xefd64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefd68 ldr r0, [pc, #-0x94c] */
/* @0xefd6c mov r2, #0 */
/* @0xefd70 mov r3, #0 */
/* @0xefd74 add r0, pc, r0 */
/* @0xefd78 movt r3, #0x3ff0 */
/* @0xefd7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefd80 ldr r3, [pc, #-0x960] */
/* @0xefd84 ldr r3, [pc, r3] */
/* @0xefd88 ldrb r3, [r3] */
/* @0xefd8c cmp r3, #0 */
/* @0xefd90 beq 0xf1140 <_Z24INITIALIZE_Code_Constantv+0x3124> */
/* @0xefd94 ldr r0, [pc, #-0x970] */
/* @0xefd98 mov r2, #0 */
/* @0xefd9c mov r3, #0 */
/* @0xefda0 movt r3, #0x3ff0 */
/* @0xefda4 add r0, pc, r0 */
/* @0xefda8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefdac ldr r0, [pc, #-0x984] */
/* @0xefdb0 mov r2, #0 */
/* @0xefdb4 mov r3, #1073741824 */
/* @0xefdb8 add r0, pc, r0 */
/* @0xefdbc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefdc0 ldr r0, [pc, #-0x994] */
/* @0xefdc4 mov r2, #0 */
/* @0xefdc8 mov r3, #0 */
/* @0xefdcc add r0, pc, r0 */
/* @0xefdd0 movt r3, #0x4010 */
/* @0xefdd4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefdd8 ldr r0, [pc, #-0x9a8] */
/* @0xefddc mov r2, #0 */
/* @0xefde0 mov r3, #0 */
/* @0xefde4 add r0, pc, r0 */
/* @0xefde8 movt r3, #0x4020 */
/* @0xefdec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefdf0 ldr r0, [pc, #-0x9bc] */
/* @0xefdf4 mov r2, #0 */
/* @0xefdf8 mov r3, #0 */
/* @0xefdfc add r0, pc, r0 */
/* @0xefe00 movt r3, #0x4030 */
/* @0xefe04 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe08 ldr r0, [pc, #-0x9d0] */
/* @0xefe0c mov r2, #0 */
/* @0xefe10 mov r3, #0 */
/* @0xefe14 add r0, pc, r0 */
/* @0xefe18 movt r3, #0x4040 */
/* @0xefe1c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe20 ldr r0, [pc, #-0x9e4] */
/* @0xefe24 mov r2, #0 */
/* @0xefe28 mov r3, #0 */
/* @0xefe2c add r0, pc, r0 */
/* @0xefe30 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe34 ldr r0, [pc, #-0x9f4] */
/* @0xefe38 mov r2, #0 */
/* @0xefe3c mov r3, #0 */
/* @0xefe40 add r0, pc, r0 */
/* @0xefe44 movt r3, #0xbff0 */
/* @0xefe48 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe4c ldr r0, [pc, #-0xa08] */
/* @0xefe50 mov r2, #0 */
/* @0xefe54 mov r3, #-1073741824 */
/* @0xefe58 add r0, pc, r0 */
/* @0xefe5c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe60 ldr r0, [pc, #-0xa18] */
/* @0xefe64 mov r2, #0 */
/* @0xefe68 mov r3, #0 */
/* @0xefe6c add r0, pc, r0 */
/* @0xefe70 movt r3, #0xc008 */
/* @0xefe74 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe78 ldr r0, [pc, #-0xa2c] */
/* @0xefe7c mov r2, #0 */
/* @0xefe80 mov r3, #0 */
/* @0xefe84 add r0, pc, r0 */
/* @0xefe88 movt r3, #0xc010 */
/* @0xefe8c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefe90 ldr r0, [pc, #-0xa40] */
/* @0xefe94 mov r2, #0 */
/* @0xefe98 mov r3, #0 */
/* @0xefe9c add r0, pc, r0 */
/* @0xefea0 movt r3, #0xc018 */
/* @0xefea4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefea8 ldr r0, [pc, #-0xa54] */
/* @0xefeac mov r2, #0 */
/* @0xefeb0 mov r3, #0 */
/* @0xefeb4 add r0, pc, r0 */
/* @0xefeb8 movt r3, #0xc01c */
/* @0xefebc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefec0 ldr r0, [pc, #-0xa68] */
/* @0xefec4 mov r2, #0 */
/* @0xefec8 mov r3, #0 */
/* @0xefecc add r0, pc, r0 */
/* @0xefed0 movt r3, #0xc020 */
/* @0xefed4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefed8 ldr r0, [pc, #-0xa7c] */
/* @0xefedc mov r2, #0 */
/* @0xefee0 mov r3, #0 */
/* @0xefee4 add r0, pc, r0 */
/* @0xefee8 movt r3, #0xc022 */
/* @0xefeec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefef0 ldr r0, [pc, #-0xa90] */
/* @0xefef4 mov r2, #0 */
/* @0xefef8 mov r3, #0 */
/* @0xefefc add r0, pc, r0 */
/* @0xeff00 movt r3, #0xc024 */
/* @0xeff04 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff08 ldr r0, [pc, #-0xaa4] */
/* @0xeff0c mov r2, #0 */
/* @0xeff10 mov r3, #0 */
/* @0xeff14 add r0, pc, r0 */
/* @0xeff18 movt r3, #0xc026 */
/* @0xeff1c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff20 ldr r0, [pc, #-0xab8] */
/* @0xeff24 mov r2, #0 */
/* @0xeff28 mov r3, #0 */
/* @0xeff2c add r0, pc, r0 */
/* @0xeff30 movt r3, #0xc028 */
/* @0xeff34 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff38 ldr r0, [pc, #-0xacc] */
/* @0xeff3c mov r2, #0 */
/* @0xeff40 mov r3, #0 */
/* @0xeff44 add r0, pc, r0 */
/* @0xeff48 movt r3, #0xc02a */
/* @0xeff4c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff50 ldr r0, [pc, #-0xae0] */
/* @0xeff54 mov r2, #0 */
/* @0xeff58 mov r3, #0 */
/* @0xeff5c add r0, pc, r0 */
/* @0xeff60 movt r3, #0xc02c */
/* @0xeff64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff68 ldr r0, [pc, #-0xaf4] */
/* @0xeff6c mov r2, #0 */
/* @0xeff70 mov r3, #0 */
/* @0xeff74 add r0, pc, r0 */
/* @0xeff78 movt r3, #0xc02e */
/* @0xeff7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff80 ldr r0, [pc, #-0xb08] */
/* @0xeff84 mov r2, #0 */
/* @0xeff88 mov r3, #0 */
/* @0xeff8c add r0, pc, r0 */
/* @0xeff90 movt r3, #0xc030 */
/* @0xeff94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeff98 ldr r0, [pc, #-0xb1c] */
/* @0xeff9c mov r2, #0 */
/* @0xeffa0 mov r3, #0 */
/* @0xeffa4 add r0, pc, r0 */
/* @0xeffa8 movt r3, #0xc031 */
/* @0xeffac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeffb0 ldr r0, [pc, #-0xb30] */
/* @0xeffb4 mov r2, #0 */
/* @0xeffb8 mov r3, #0 */
/* @0xeffbc add r0, pc, r0 */
/* @0xeffc0 movt r3, #0xc032 */
/* @0xeffc4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeffc8 ldr r0, [pc, #-0xb44] */
/* @0xeffcc mov r2, #0 */
/* @0xeffd0 mov r3, #0 */
/* @0xeffd4 add r0, pc, r0 */
/* @0xeffd8 movt r3, #0xc033 */
/* @0xeffdc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xeffe0 ldr r0, [pc, #-0xb58] */
/* @0xeffe4 mov r2, #0 */
/* @0xeffe8 mov r3, #0 */
/* @0xeffec add r0, pc, r0 */
/* @0xefff0 movt r3, #0xc034 */
/* @0xefff4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xefff8 ldr r0, [pc, #-0xb6c] */
/* @0xefffc mov r2, #0 */
/* @0xf0000 mov r3, #0 */
/* @0xf0004 add r0, pc, r0 */
/* @0xf0008 movt r3, #0xc035 */
/* @0xf000c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0010 ldr r0, [pc, #-0xb80] */
/* @0xf0014 mov r2, #0 */
/* @0xf0018 mov r3, #0 */
/* @0xf001c add r0, pc, r0 */
/* @0xf0020 movt r3, #0xc036 */
/* @0xf0024 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0028 ldr r0, [pc, #-0xb94] */
/* @0xf002c mov r2, #0 */
/* @0xf0030 mov r3, #0 */
/* @0xf0034 add r0, pc, r0 */
/* @0xf0038 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf003c ldr r0, [pc, #-0xba4] */
/* @0xf0040 mov r2, #0 */
/* @0xf0044 mov r3, #0 */
/* @0xf0048 add r0, pc, r0 */
/* @0xf004c movt r3, #0x3ff0 */
/* @0xf0050 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0054 ldr r0, [pc, #-0xbb8] */
/* @0xf0058 mov r2, #0 */
/* @0xf005c mov r3, #1073741824 */
/* @0xf0060 add r0, pc, r0 */
/* @0xf0064 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0068 ldr r0, [pc, #-0xbc8] */
/* @0xf006c mov r2, #0 */
/* @0xf0070 mov r3, #0 */
/* @0xf0074 add r0, pc, r0 */
/* @0xf0078 movt r3, #0x4008 */
/* @0xf007c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0080 ldr r0, [pc, #-0xbdc] */
/* @0xf0084 mov r2, #0 */
/* @0xf0088 mov r3, #0 */
/* @0xf008c add r0, pc, r0 */
/* @0xf0090 movt r3, #0x4010 */
/* @0xf0094 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0098 ldr r0, [pc, #-0xbf0] */
/* @0xf009c mov r2, #0 */
/* @0xf00a0 mov r3, #0 */
/* @0xf00a4 add r0, pc, r0 */
/* @0xf00a8 movt r3, #0x4014 */
/* @0xf00ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf00b0 ldr r0, [pc, #-0xc04] */
/* @0xf00b4 mov r2, #0 */
/* @0xf00b8 mov r3, #0 */
/* @0xf00bc add r0, pc, r0 */
/* @0xf00c0 movt r3, #0x4018 */
/* @0xf00c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf00c8 ldr r0, [pc, #-0xc18] */
/* @0xf00cc mov r2, #0 */
/* @0xf00d0 mov r3, #0 */
/* @0xf00d4 add r0, pc, r0 */
/* @0xf00d8 movt r3, #0x401c */
/* @0xf00dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf00e0 ldr r0, [pc, #-0xc2c] */
/* @0xf00e4 mov r2, #0 */
/* @0xf00e8 mov r3, #0 */
/* @0xf00ec add r0, pc, r0 */
/* @0xf00f0 movt r3, #0x4020 */
/* @0xf00f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf00f8 ldr r0, [pc, #-0xc40] */
/* @0xf00fc mov r2, #0 */
/* @0xf0100 mov r3, #0 */
/* @0xf0104 add r0, pc, r0 */
/* @0xf0108 movt r3, #0x4022 */
/* @0xf010c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0110 ldr r0, [pc, #-0xc54] */
/* @0xf0114 mov r2, #0 */
/* @0xf0118 mov r3, #0 */
/* @0xf011c add r0, pc, r0 */
/* @0xf0120 movt r3, #0x4024 */
/* @0xf0124 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0128 ldr r0, [pc, #-0xc68] */
/* @0xf012c mov r2, #0 */
/* @0xf0130 mov r3, #0 */
/* @0xf0134 add r0, pc, r0 */
/* @0xf0138 movt r3, #0x4026 */
/* @0xf013c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0140 ldr r0, [pc, #-0xc7c] */
/* @0xf0144 mov r2, #0 */
/* @0xf0148 mov r3, #0 */
/* @0xf014c add r0, pc, r0 */
/* @0xf0150 movt r3, #0x4028 */
/* @0xf0154 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0158 ldr r0, [pc, #-0xc90] */
/* @0xf015c mov r2, #0 */
/* @0xf0160 mov r3, #0 */
/* @0xf0164 add r0, pc, r0 */
/* @0xf0168 movt r3, #0x402a */
/* @0xf016c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0170 ldr r0, [pc, #-0xca4] */
/* @0xf0174 mov r2, #0 */
/* @0xf0178 mov r3, #0 */
/* @0xf017c add r0, pc, r0 */
/* @0xf0180 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0184 ldr r0, [pc, #-0xcb4] */
/* @0xf0188 mov r2, #0 */
/* @0xf018c mov r3, #0 */
/* @0xf0190 add r0, pc, r0 */
/* @0xf0194 movt r3, #0x3ff0 */
/* @0xf0198 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf019c ldr r0, [pc, #-0xcc8] */
/* @0xf01a0 mov r2, #0 */
/* @0xf01a4 mov r3, #1073741824 */
/* @0xf01a8 add r0, pc, r0 */
/* @0xf01ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf01b0 ldr r0, [pc, #-0xcd8] */
/* @0xf01b4 mov r2, #0 */
/* @0xf01b8 mov r3, #0 */
/* @0xf01bc add r0, pc, r0 */
/* @0xf01c0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf01c4 ldr r0, [pc, #-0xce8] */
/* @0xf01c8 mov r2, #0 */
/* @0xf01cc mov r3, #0 */
/* @0xf01d0 add r0, pc, r0 */
/* @0xf01d4 movt r3, #0x3ff0 */
/* @0xf01d8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf01dc ldr r0, [pc, #-0xcfc] */
/* @0xf01e0 mov r2, #0 */
/* @0xf01e4 mov r3, #1073741824 */
/* @0xf01e8 add r0, pc, r0 */
/* @0xf01ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf01f0 ldr r0, [pc, #-0xd0c] */
/* @0xf01f4 mov r2, #0 */
/* @0xf01f8 mov r3, #0 */
/* @0xf01fc add r0, pc, r0 */
/* @0xf0200 movt r3, #0x4008 */
/* @0xf0204 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0208 ldr r0, [pc, #-0xd20] */
/* @0xf020c mov r2, #0 */
/* @0xf0210 mov r3, #0 */
/* @0xf0214 add r0, pc, r0 */
/* @0xf0218 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf021c ldr r0, [pc, #-0xd30] */
/* @0xf0220 mov r2, #0 */
/* @0xf0224 mov r3, #0 */
/* @0xf0228 add r0, pc, r0 */
/* @0xf022c movt r3, #0x3ff0 */
/* @0xf0230 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0234 ldr r0, [pc, #-0xd44] */
/* @0xf0238 mov r2, #0 */
/* @0xf023c mov r3, #1073741824 */
/* @0xf0240 add r0, pc, r0 */
/* @0xf0244 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0248 ldr r0, [pc, #-0xd54] */
/* @0xf024c mov r2, #0 */
/* @0xf0250 mov r3, #0 */
/* @0xf0254 add r0, pc, r0 */
/* @0xf0258 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf025c ldr r0, [pc, #-0xd64] */
/* @0xf0260 mov r2, #0 */
/* @0xf0264 mov r3, #0 */
/* @0xf0268 add r0, pc, r0 */
/* @0xf026c movt r3, #0x3ff0 */
/* @0xf0270 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0274 ldr r0, [pc, #-0xd78] */
/* @0xf0278 mov r2, #0 */
/* @0xf027c mov r3, #0 */
/* @0xf0280 add r0, pc, r0 */
/* @0xf0284 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0288 ldr r0, [pc, #-0xd88] */
/* @0xf028c mov r2, #0 */
/* @0xf0290 mov r3, #0 */
/* @0xf0294 add r0, pc, r0 */
/* @0xf0298 movt r3, #0x3ff0 */
/* @0xf029c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf02a0 ldr r0, [pc, #-0xd9c] */
/* @0xf02a4 mov r2, #0 */
/* @0xf02a8 mov r3, #1073741824 */
/* @0xf02ac add r0, pc, r0 */
/* @0xf02b0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf02b4 ldr r0, [pc, #-0xdac] */
/* @0xf02b8 mov r2, #0 */
/* @0xf02bc mov r3, #0 */
/* @0xf02c0 add r0, pc, r0 */
/* @0xf02c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf02c8 ldr r0, [pc, #-0xdbc] */
/* @0xf02cc mov r2, #0 */
/* @0xf02d0 mov r3, #0 */
/* @0xf02d4 add r0, pc, r0 */
/* @0xf02d8 movt r3, #0x3ff0 */
/* @0xf02dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf02e0 ldr r0, [pc, #-0xdd0] */
/* @0xf02e4 mov r2, #0 */
/* @0xf02e8 mov r3, #1073741824 */
/* @0xf02ec add r0, pc, r0 */
/* @0xf02f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf02f4 ldr r0, [pc, #-0xde0] */
/* @0xf02f8 mov r2, #0 */
/* @0xf02fc mov r3, #0 */
/* @0xf0300 add r0, pc, r0 */
/* @0xf0304 movt r3, #0x4008 */
/* @0xf0308 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf030c ldr r0, [pc, #-0xdf4] */
/* @0xf0310 mov r2, #0 */
/* @0xf0314 mov r3, #0 */
/* @0xf0318 add r0, pc, r0 */
/* @0xf031c movt r3, #0x4010 */
/* @0xf0320 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0324 ldr r0, [pc, #-0xe08] */
/* @0xf0328 mov r2, #0 */
/* @0xf032c mov r3, #0 */
/* @0xf0330 add r0, pc, r0 */
/* @0xf0334 movt r3, #0x4014 */
/* @0xf0338 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf033c ldr r0, [pc, #-0xe1c] */
/* @0xf0340 mov r2, #0 */
/* @0xf0344 mov r3, #0 */
/* @0xf0348 add r0, pc, r0 */
/* @0xf034c movt r3, #0x4018 */
/* @0xf0350 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0354 ldr r0, [pc, #-0xe30] */
/* @0xf0358 mov r2, #0 */
/* @0xf035c mov r3, #0 */
/* @0xf0360 add r0, pc, r0 */
/* @0xf0364 movt r3, #0x401c */
/* @0xf0368 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf036c ldr r0, [pc, #-0xe44] */
/* @0xf0370 mov r2, #0 */
/* @0xf0374 mov r3, #0 */
/* @0xf0378 add r0, pc, r0 */
/* @0xf037c movt r3, #0x4020 */
/* @0xf0380 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0384 ldr r0, [pc, #-0xe58] */
/* @0xf0388 mov r2, #0 */
/* @0xf038c mov r3, #0 */
/* @0xf0390 add r0, pc, r0 */
/* @0xf0394 movt r3, #0x4022 */
/* @0xf0398 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf039c ldr r0, [pc, #-0xe6c] */
/* @0xf03a0 mov r2, #0 */
/* @0xf03a4 mov r3, #0 */
/* @0xf03a8 add r0, pc, r0 */
/* @0xf03ac movt r3, #0x4024 */
/* @0xf03b0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf03b4 ldr r0, [pc, #-0xe80] */
/* @0xf03b8 mov r2, #0 */
/* @0xf03bc mov r3, #0 */
/* @0xf03c0 add r0, pc, r0 */
/* @0xf03c4 movt r3, #0x4026 */
/* @0xf03c8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf03cc ldr r0, [pc, #-0xe94] */
/* @0xf03d0 mov r2, #0 */
/* @0xf03d4 mov r3, #0 */
/* @0xf03d8 add r0, pc, r0 */
/* @0xf03dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf03e0 ldr r0, [pc, #-0xea4] */
/* @0xf03e4 mov r2, #0 */
/* @0xf03e8 mov r3, #0 */
/* @0xf03ec add r0, pc, r0 */
/* @0xf03f0 movt r3, #0x3ff0 */
/* @0xf03f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf03f8 ldr r0, [pc, #-0xeb8] */
/* @0xf03fc mov r2, #0 */
/* @0xf0400 mov r3, #1073741824 */
/* @0xf0404 add r0, pc, r0 */
/* @0xf0408 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf040c ldr r0, [pc, #-0xec8] */
/* @0xf0410 mov r2, #0 */
/* @0xf0414 mov r3, #0 */
/* @0xf0418 add r0, pc, r0 */
/* @0xf041c movt r3, #0x4008 */
/* @0xf0420 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0424 ldr r0, [pc, #-0xedc] */
/* @0xf0428 mov r2, #0 */
/* @0xf042c mov r3, #0 */
/* @0xf0430 add r0, pc, r0 */
/* @0xf0434 movt r3, #0xbff0 */
/* @0xf0438 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf043c ldr r0, [pc, #-0xef0] */
/* @0xf0440 mov r2, #0 */
/* @0xf0444 mov r3, #0 */
/* @0xf0448 add r0, pc, r0 */
/* @0xf044c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0450 ldr r0, [pc, #-0xf00] */
/* @0xf0454 mov r2, #0 */
/* @0xf0458 mov r3, #0 */
/* @0xf045c add r0, pc, r0 */
/* @0xf0460 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0464 ldr r0, [pc, #-0xf10] */
/* @0xf0468 mov r2, #0 */
/* @0xf046c mov r3, #0 */
/* @0xf0470 add r0, pc, r0 */
/* @0xf0474 movt r3, #0x3ff0 */
/* @0xf0478 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf047c ldrb r3, [r4] */
/* @0xf0480 cmp r3, #0 */
/* @0xf0484 bne 0xf049c <_Z24INITIALIZE_Code_Constantv+0x2480> */
/* @0xf0488 ldr r0, [pc, #-0xf30] */
/* @0xf048c mov r2, #0 */
/* @0xf0490 mov r3, #1073741824 */
/* @0xf0494 add r0, pc, r0 */
/* @0xf0498 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf049c ldr r0, [pc, #-0xf40] */
/* @0xf04a0 mov r2, #0 */
/* @0xf04a4 mov r3, #0 */
/* @0xf04a8 movt r3, #0x4008 */
/* @0xf04ac add r0, pc, r0 */
/* @0xf04b0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf04b4 ldr r0, [pc, #-0xf54] */
/* @0xf04b8 mov r2, #0 */
/* @0xf04bc mov r3, #0 */
/* @0xf04c0 add r0, pc, r0 */
/* @0xf04c4 movt r3, #0x4010 */
/* @0xf04c8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf04cc ldr r0, [pc, #-0xf68] */
/* @0xf04d0 mov r2, #0 */
/* @0xf04d4 mov r3, #0 */
/* @0xf04d8 add r0, pc, r0 */
/* @0xf04dc movt r3, #0x4014 */
/* @0xf04e0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf04e4 ldr r0, [pc, #-0xf7c] */
/* @0xf04e8 mov r2, #0 */
/* @0xf04ec mov r3, #0 */
/* @0xf04f0 add r0, pc, r0 */
/* @0xf04f4 movt r3, #0x4018 */
/* @0xf04f8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf04fc ldr r0, [pc, #-0xf90] */
/* @0xf0500 mov r2, #0 */
/* @0xf0504 mov r3, #0 */
/* @0xf0508 add r0, pc, r0 */
/* @0xf050c movt r3, #0x401c */
/* @0xf0510 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0514 ldr r0, [pc, #-0xfa4] */
/* @0xf0518 mov r2, #0 */
/* @0xf051c mov r3, #0 */
/* @0xf0520 add r0, pc, r0 */
/* @0xf0524 movt r3, #0x4020 */
/* @0xf0528 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf052c ldr r0, [pc, #-0xfb8] */
/* @0xf0530 mov r2, #0 */
/* @0xf0534 mov r3, #0 */
/* @0xf0538 add r0, pc, r0 */
/* @0xf053c movt r3, #0x4022 */
/* @0xf0540 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0544 ldr r0, [pc, #-0xfcc] */
/* @0xf0548 mov r2, #0 */
/* @0xf054c mov r3, #0 */
/* @0xf0550 add r0, pc, r0 */
/* @0xf0554 movt r3, #0x4024 */
/* @0xf0558 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf055c ldr r0, [pc, #-0xfe0] */
/* @0xf0560 mov r2, #0 */
/* @0xf0564 mov r3, #0 */
/* @0xf0568 add r0, pc, r0 */
/* @0xf056c movt r3, #0x4026 */
/* @0xf0570 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0574 ldr r0, [pc, #-0xff4] */
/* @0xf0578 mov r2, #0 */
/* @0xf057c mov r3, #0 */
/* @0xf0580 add r0, pc, r0 */
/* @0xf0584 movt r3, #0x4028 */
/* @0xf0588 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf058c ldr r0, [pc, #0xf18] */
/* @0xf0590 mov r2, #0 */
/* @0xf0594 mov r3, #0 */
/* @0xf0598 add r0, pc, r0 */
/* @0xf059c movt r3, #0x402a */
/* @0xf05a0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf05a4 ldr r0, [pc, #0xf04] */
/* @0xf05a8 mov r2, #0 */
/* @0xf05ac mov r3, #0 */
/* @0xf05b0 add r0, pc, r0 */
/* @0xf05b4 movt r3, #0x402c */
/* @0xf05b8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf05bc ldr r0, [pc, #0xef0] */
/* @0xf05c0 mov r2, #0 */
/* @0xf05c4 mov r3, #0 */
/* @0xf05c8 add r0, pc, r0 */
/* @0xf05cc movt r3, #0x402e */
/* @0xf05d0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf05d4 ldr r0, [pc, #0xedc] */
/* @0xf05d8 mov r2, #0 */
/* @0xf05dc mov r3, #0 */
/* @0xf05e0 add r0, pc, r0 */
/* @0xf05e4 movt r3, #0x4030 */
/* @0xf05e8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf05ec ldr r0, [pc, #0xec8] */
/* @0xf05f0 mov r2, #0 */
/* @0xf05f4 mov r3, #0 */
/* @0xf05f8 add r0, pc, r0 */
/* @0xf05fc movt r3, #0x4031 */
/* @0xf0600 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0604 ldr r0, [pc, #0xeb4] */
/* @0xf0608 mov r2, #0 */
/* @0xf060c mov r3, #0 */
/* @0xf0610 add r0, pc, r0 */
/* @0xf0614 movt r3, #0x4032 */
/* @0xf0618 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf061c ldr r0, [pc, #0xea0] */
/* @0xf0620 mov r2, #0 */
/* @0xf0624 mov r3, #0 */
/* @0xf0628 add r0, pc, r0 */
/* @0xf062c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0630 ldr r0, [pc, #0xe90] */
/* @0xf0634 mov r2, #0 */
/* @0xf0638 mov r3, #0 */
/* @0xf063c add r0, pc, r0 */
/* @0xf0640 movt r3, #0x3ff0 */
/* @0xf0644 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0648 ldr r0, [pc, #0xe7c] */
/* @0xf064c mov r2, #0 */
/* @0xf0650 mov r3, #1073741824 */
/* @0xf0654 add r0, pc, r0 */
/* @0xf0658 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf065c ldr r0, [pc, #0xe6c] */
/* @0xf0660 mov r2, #0 */
/* @0xf0664 mov r3, #0 */
/* @0xf0668 add r0, pc, r0 */
/* @0xf066c movt r3, #0x4008 */
/* @0xf0670 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0674 ldr r0, [pc, #0xe58] */
/* @0xf0678 mov r2, #0 */
/* @0xf067c mov r3, #0 */
/* @0xf0680 add r0, pc, r0 */
/* @0xf0684 movt r3, #0x4010 */
/* @0xf0688 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf068c ldr r0, [pc, #0xe44] */
/* @0xf0690 mov r2, #0 */
/* @0xf0694 mov r3, #0 */
/* @0xf0698 add r0, pc, r0 */
/* @0xf069c movt r3, #0x4014 */
/* @0xf06a0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf06a4 ldr r0, [pc, #0xe30] */
/* @0xf06a8 mov r2, #0 */
/* @0xf06ac mov r3, #0 */
/* @0xf06b0 add r0, pc, r0 */
/* @0xf06b4 movt r3, #0x4018 */
/* @0xf06b8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf06bc ldr r0, [pc, #0xe1c] */
/* @0xf06c0 mov r2, #0 */
/* @0xf06c4 mov r3, #0 */
/* @0xf06c8 add r0, pc, r0 */
/* @0xf06cc movt r3, #0x4020 */
/* @0xf06d0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf06d4 ldr r0, [pc, #0xe08] */
/* @0xf06d8 mov r2, #0 */
/* @0xf06dc mov r3, #0 */
/* @0xf06e0 add r0, pc, r0 */
/* @0xf06e4 movt r3, #0x401c */
/* @0xf06e8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf06ec ldr r0, [pc, #0xdf4] */
/* @0xf06f0 mov r2, #0 */
/* @0xf06f4 mov r3, #0 */
/* @0xf06f8 add r0, pc, r0 */
/* @0xf06fc movt r3, #0x4022 */
/* @0xf0700 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0704 ldr r0, [pc, #0xde0] */
/* @0xf0708 mov r2, #0 */
/* @0xf070c mov r3, #0 */
/* @0xf0710 add r0, pc, r0 */
/* @0xf0714 movt r3, #0x4024 */
/* @0xf0718 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf071c ldr r0, [pc, #0xdcc] */
/* @0xf0720 mov r2, #0 */
/* @0xf0724 mov r3, #0 */
/* @0xf0728 add r0, pc, r0 */
/* @0xf072c movt r3, #0x4026 */
/* @0xf0730 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0734 ldr r0, [pc, #0xdb8] */
/* @0xf0738 mov r2, #0 */
/* @0xf073c mov r3, #0 */
/* @0xf0740 add r0, pc, r0 */
/* @0xf0744 movt r3, #0x4028 */
/* @0xf0748 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf074c ldr r0, [pc, #0xda4] */
/* @0xf0750 mov r2, #0 */
/* @0xf0754 mov r3, #0 */
/* @0xf0758 add r0, pc, r0 */
/* @0xf075c movt r3, #0x402a */
/* @0xf0760 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0764 ldr r0, [pc, #0xd90] */
/* @0xf0768 mov r2, #0 */
/* @0xf076c mov r3, #0 */
/* @0xf0770 add r0, pc, r0 */
/* @0xf0774 movt r3, #0x402c */
/* @0xf0778 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf077c ldr r0, [pc, #0xd7c] */
/* @0xf0780 mov r2, #0 */
/* @0xf0784 mov r3, #0 */
/* @0xf0788 add r0, pc, r0 */
/* @0xf078c movt r3, #0x402e */
/* @0xf0790 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0794 ldr r0, [pc, #0xd68] */
/* @0xf0798 mov r2, #0 */
/* @0xf079c mov r3, #0 */
/* @0xf07a0 add r0, pc, r0 */
/* @0xf07a4 movt r3, #0x4030 */
/* @0xf07a8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf07ac ldr r0, [pc, #0xd54] */
/* @0xf07b0 mov r2, #0 */
/* @0xf07b4 mov r3, #0 */
/* @0xf07b8 add r0, pc, r0 */
/* @0xf07bc movt r3, #0x4031 */
/* @0xf07c0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf07c4 ldr r0, [pc, #0xd40] */
/* @0xf07c8 mov r2, #0 */
/* @0xf07cc mov r3, #0 */
/* @0xf07d0 add r0, pc, r0 */
/* @0xf07d4 movt r3, #0x4032 */
/* @0xf07d8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf07dc ldr r0, [pc, #0xd2c] */
/* @0xf07e0 mov r2, #0 */
/* @0xf07e4 mov r3, #0 */
/* @0xf07e8 add r0, pc, r0 */
/* @0xf07ec movt r3, #0x3ff0 */
/* @0xf07f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf07f4 ldr r0, [pc, #0xd18] */
/* @0xf07f8 mov r2, #0 */
/* @0xf07fc mov r3, #1073741824 */
/* @0xf0800 add r0, pc, r0 */
/* @0xf0804 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0808 ldr r0, [pc, #0xd08] */
/* @0xf080c mov r2, #0 */
/* @0xf0810 mov r3, #0 */
/* @0xf0814 add r0, pc, r0 */
/* @0xf0818 movt r3, #0x4010 */
/* @0xf081c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0820 ldr r0, [pc, #0xcf4] */
/* @0xf0824 mov r2, #0 */
/* @0xf0828 mov r3, #0 */
/* @0xf082c add r0, pc, r0 */
/* @0xf0830 movt r3, #0x4020 */
/* @0xf0834 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0838 ldr r0, [pc, #0xce0] */
/* @0xf083c mov r2, #0 */
/* @0xf0840 mov r3, #0 */
/* @0xf0844 add r0, pc, r0 */
/* @0xf0848 movt r3, #0x4030 */
/* @0xf084c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0850 ldr r0, [pc, #0xccc] */
/* @0xf0854 mov r2, #0 */
/* @0xf0858 mov r3, #0 */
/* @0xf085c add r0, pc, r0 */
/* @0xf0860 movt r3, #0x4040 */
/* @0xf0864 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0868 ldr r0, [pc, #0xcb8] */
/* @0xf086c mov r2, #0 */
/* @0xf0870 mov r3, #0 */
/* @0xf0874 add r0, pc, r0 */
/* @0xf0878 movt r3, #0x4050 */
/* @0xf087c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0880 ldr r0, [pc, #0xca4] */
/* @0xf0884 mov r2, #0 */
/* @0xf0888 mov r3, #0 */
/* @0xf088c add r0, pc, r0 */
/* @0xf0890 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0894 ldr r0, [pc, #0xc94] */
/* @0xf0898 mov r2, #0 */
/* @0xf089c mov r3, #0 */
/* @0xf08a0 add r0, pc, r0 */
/* @0xf08a4 movt r3, #0x3ff0 */
/* @0xf08a8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf08ac ldr r0, [pc, #0xc80] */
/* @0xf08b0 mov r2, #0 */
/* @0xf08b4 mov r3, #1073741824 */
/* @0xf08b8 add r0, pc, r0 */
/* @0xf08bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf08c0 ldr r0, [pc, #0xc70] */
/* @0xf08c4 mov r2, #0 */
/* @0xf08c8 mov r3, #0 */
/* @0xf08cc add r0, pc, r0 */
/* @0xf08d0 movt r3, #0x4008 */
/* @0xf08d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf08d8 ldr r0, [pc, #0xc5c] */
/* @0xf08dc mov r2, #0 */
/* @0xf08e0 mov r3, #0 */
/* @0xf08e4 add r0, pc, r0 */
/* @0xf08e8 movt r3, #0x4010 */
/* @0xf08ec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf08f0 ldr r0, [pc, #0xc48] */
/* @0xf08f4 mov r2, #0 */
/* @0xf08f8 mov r3, #0 */
/* @0xf08fc add r0, pc, r0 */
/* @0xf0900 movt r3, #0x4014 */
/* @0xf0904 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0908 ldr r0, [pc, #0xc34] */
/* @0xf090c mov r2, #0 */
/* @0xf0910 mov r3, #0 */
/* @0xf0914 add r0, pc, r0 */
/* @0xf0918 movt r3, #0x4018 */
/* @0xf091c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0920 ldr r0, [pc, #0xc20] */
/* @0xf0924 mov r2, #0 */
/* @0xf0928 mov r3, #0 */
/* @0xf092c add r0, pc, r0 */
/* @0xf0930 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0934 ldr r0, [pc, #0xc10] */
/* @0xf0938 mov r2, #0 */
/* @0xf093c mov r3, #0 */
/* @0xf0940 add r0, pc, r0 */
/* @0xf0944 movt r3, #0x3ff0 */
/* @0xf0948 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf094c ldr r0, [pc, #0xbfc] */
/* @0xf0950 mov r2, #0 */
/* @0xf0954 mov r3, #0 */
/* @0xf0958 add r0, pc, r0 */
/* @0xf095c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0960 ldr r0, [pc, #0xbec] */
/* @0xf0964 mov r2, #0 */
/* @0xf0968 mov r3, #0 */
/* @0xf096c add r0, pc, r0 */
/* @0xf0970 movt r3, #0x3ff0 */
/* @0xf0974 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0978 ldr r0, [pc, #0xbd8] */
/* @0xf097c mov r2, #0 */
/* @0xf0980 mov r3, #1073741824 */
/* @0xf0984 add r0, pc, r0 */
/* @0xf0988 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf098c ldr r0, [pc, #0xbc8] */
/* @0xf0990 mov r2, #0 */
/* @0xf0994 mov r3, #0 */
/* @0xf0998 add r0, pc, r0 */
/* @0xf099c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf09a0 ldr r0, [pc, #0xbb8] */
/* @0xf09a4 mov r2, #0 */
/* @0xf09a8 mov r3, #0 */
/* @0xf09ac add r0, pc, r0 */
/* @0xf09b0 movt r3, #0x3ff0 */
/* @0xf09b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf09b8 ldr r0, [pc, #0xba4] */
/* @0xf09bc mov r2, #0 */
/* @0xf09c0 mov r3, #1073741824 */
/* @0xf09c4 add r0, pc, r0 */
/* @0xf09c8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf09cc ldr r0, [pc, #0xb94] */
/* @0xf09d0 mov r2, #0 */
/* @0xf09d4 mov r3, #0 */
/* @0xf09d8 add r0, pc, r0 */
/* @0xf09dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf09e0 ldr r0, [pc, #0xb84] */
/* @0xf09e4 mov r2, #0 */
/* @0xf09e8 mov r3, #0 */
/* @0xf09ec add r0, pc, r0 */
/* @0xf09f0 movt r3, #0x3ff0 */
/* @0xf09f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf09f8 ldr r0, [pc, #0xb70] */
/* @0xf09fc mov r2, #0 */
/* @0xf0a00 mov r3, #1073741824 */
/* @0xf0a04 add r0, pc, r0 */
/* @0xf0a08 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a0c ldr r0, [pc, #0xb60] */
/* @0xf0a10 mov r2, #0 */
/* @0xf0a14 mov r3, #0 */
/* @0xf0a18 add r0, pc, r0 */
/* @0xf0a1c movt r3, #0x4008 */
/* @0xf0a20 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a24 ldr r0, [pc, #0xb4c] */
/* @0xf0a28 mov r2, #0 */
/* @0xf0a2c mov r3, #0 */
/* @0xf0a30 add r0, pc, r0 */
/* @0xf0a34 movt r3, #0x4010 */
/* @0xf0a38 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a3c ldr r0, [pc, #0xb38] */
/* @0xf0a40 mov r2, #0 */
/* @0xf0a44 mov r3, #0 */
/* @0xf0a48 add r0, pc, r0 */
/* @0xf0a4c movt r3, #0x4014 */
/* @0xf0a50 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a54 ldr r0, [pc, #0xb24] */
/* @0xf0a58 mov r2, #0 */
/* @0xf0a5c mov r3, #0 */
/* @0xf0a60 add r0, pc, r0 */
/* @0xf0a64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a68 ldr r0, [pc, #0xb14] */
/* @0xf0a6c mov r2, #0 */
/* @0xf0a70 mov r3, #0 */
/* @0xf0a74 add r0, pc, r0 */
/* @0xf0a78 movt r3, #0x3ff0 */
/* @0xf0a7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a80 ldr r0, [pc, #0xb00] */
/* @0xf0a84 mov r2, #0 */
/* @0xf0a88 mov r3, #1073741824 */
/* @0xf0a8c add r0, pc, r0 */
/* @0xf0a90 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0a94 ldr r0, [pc, #0xaf0] */
/* @0xf0a98 mov r2, #0 */
/* @0xf0a9c mov r3, #0 */
/* @0xf0aa0 add r0, pc, r0 */
/* @0xf0aa4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0aa8 ldr r0, [pc, #0xae0] */
/* @0xf0aac mov r2, #0 */
/* @0xf0ab0 mov r3, #0 */
/* @0xf0ab4 add r0, pc, r0 */
/* @0xf0ab8 movt r3, #0x3ff0 */
/* @0xf0abc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ac0 ldr r0, [pc, #0xacc] */
/* @0xf0ac4 mov r2, #0 */
/* @0xf0ac8 mov r3, #1073741824 */
/* @0xf0acc add r0, pc, r0 */
/* @0xf0ad0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ad4 ldr r0, [pc, #0xabc] */
/* @0xf0ad8 mov r2, #0 */
/* @0xf0adc mov r3, #0 */
/* @0xf0ae0 add r0, pc, r0 */
/* @0xf0ae4 movt r3, #0x4008 */
/* @0xf0ae8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0aec ldr r0, [pc, #0xaa8] */
/* @0xf0af0 mov r2, #0 */
/* @0xf0af4 mov r3, #0 */
/* @0xf0af8 add r0, pc, r0 */
/* @0xf0afc movt r3, #0x3ff0 */
/* @0xf0b00 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b04 ldr r0, [pc, #0xa94] */
/* @0xf0b08 mov r2, #0 */
/* @0xf0b0c mov r3, #0 */
/* @0xf0b10 add r0, pc, r0 */
/* @0xf0b14 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b18 ldr r0, [pc, #0xa84] */
/* @0xf0b1c mov r2, #0 */
/* @0xf0b20 mov r3, #0 */
/* @0xf0b24 add r0, pc, r0 */
/* @0xf0b28 movt r3, #0x3ff0 */
/* @0xf0b2c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b30 ldr r0, [pc, #0xa70] */
/* @0xf0b34 mov r2, #0 */
/* @0xf0b38 mov r3, #0 */
/* @0xf0b3c add r0, pc, r0 */
/* @0xf0b40 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b44 ldr r0, [pc, #0xa60] */
/* @0xf0b48 mov r2, #0 */
/* @0xf0b4c mov r3, #0 */
/* @0xf0b50 add r0, pc, r0 */
/* @0xf0b54 movt r3, #0x3ff0 */
/* @0xf0b58 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b5c ldr r0, [pc, #0xa4c] */
/* @0xf0b60 mov r2, #0 */
/* @0xf0b64 mov r3, #1073741824 */
/* @0xf0b68 add r0, pc, r0 */
/* @0xf0b6c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b70 ldr r0, [pc, #0xa3c] */
/* @0xf0b74 mov r2, #0 */
/* @0xf0b78 mov r3, #0 */
/* @0xf0b7c add r0, pc, r0 */
/* @0xf0b80 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b84 ldr r0, [pc, #0xa2c] */
/* @0xf0b88 mov r2, #0 */
/* @0xf0b8c mov r3, #0 */
/* @0xf0b90 add r0, pc, r0 */
/* @0xf0b94 movt r3, #0x3ff0 */
/* @0xf0b98 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0b9c ldr r0, [pc, #0xa18] */
/* @0xf0ba0 mov r2, #0 */
/* @0xf0ba4 mov r3, #1073741824 */
/* @0xf0ba8 add r0, pc, r0 */
/* @0xf0bac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0bb0 ldr r0, [pc, #0xa08] */
/* @0xf0bb4 mov r2, #0 */
/* @0xf0bb8 mov r3, #0 */
/* @0xf0bbc add r0, pc, r0 */
/* @0xf0bc0 movt r3, #0x4008 */
/* @0xf0bc4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0bc8 ldr r0, [pc, #0x9f4] */
/* @0xf0bcc mov r2, #0 */
/* @0xf0bd0 mov r3, #0 */
/* @0xf0bd4 add r0, pc, r0 */
/* @0xf0bd8 movt r3, #0x4010 */
/* @0xf0bdc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0be0 ldr r0, [pc, #0x9e0] */
/* @0xf0be4 mov r2, #0 */
/* @0xf0be8 mov r3, #0 */
/* @0xf0bec add r0, pc, r0 */
/* @0xf0bf0 movt r3, #0x4014 */
/* @0xf0bf4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0bf8 ldr r0, [pc, #0x9cc] */
/* @0xf0bfc mov r2, #0 */
/* @0xf0c00 mov r3, #0 */
/* @0xf0c04 add r0, pc, r0 */
/* @0xf0c08 movt r3, #0x4018 */
/* @0xf0c0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c10 ldr r0, [pc, #0x9b8] */
/* @0xf0c14 mov r2, #0 */
/* @0xf0c18 mov r3, #0 */
/* @0xf0c1c add r0, pc, r0 */
/* @0xf0c20 movt r3, #0x401c */
/* @0xf0c24 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c28 ldr r0, [pc, #0x9a4] */
/* @0xf0c2c mov r2, #0 */
/* @0xf0c30 mov r3, #0 */
/* @0xf0c34 add r0, pc, r0 */
/* @0xf0c38 movt r3, #0x4020 */
/* @0xf0c3c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c40 ldr r0, [pc, #0x990] */
/* @0xf0c44 mov r2, #0 */
/* @0xf0c48 mov r3, #0 */
/* @0xf0c4c add r0, pc, r0 */
/* @0xf0c50 movt r3, #0x4022 */
/* @0xf0c54 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c58 ldr r0, [pc, #0x97c] */
/* @0xf0c5c mov r2, #0 */
/* @0xf0c60 mov r3, #0 */
/* @0xf0c64 add r0, pc, r0 */
/* @0xf0c68 movt r3, #0x4024 */
/* @0xf0c6c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c70 ldr r0, [pc, #0x968] */
/* @0xf0c74 mov r2, #0 */
/* @0xf0c78 mov r3, #0 */
/* @0xf0c7c add r0, pc, r0 */
/* @0xf0c80 movt r3, #0x4026 */
/* @0xf0c84 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c88 ldr r0, [pc, #0x954] */
/* @0xf0c8c mov r2, #0 */
/* @0xf0c90 mov r3, #0 */
/* @0xf0c94 add r0, pc, r0 */
/* @0xf0c98 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0c9c ldr r0, [pc, #0x944] */
/* @0xf0ca0 mov r2, #0 */
/* @0xf0ca4 mov r3, #0 */
/* @0xf0ca8 add r0, pc, r0 */
/* @0xf0cac movt r3, #0x3ff0 */
/* @0xf0cb0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0cb4 ldr r0, [pc, #0x930] */
/* @0xf0cb8 mov r2, #0 */
/* @0xf0cbc mov r3, #1073741824 */
/* @0xf0cc0 add r0, pc, r0 */
/* @0xf0cc4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0cc8 ldr r0, [pc, #0x920] */
/* @0xf0ccc mov r2, #0 */
/* @0xf0cd0 mov r3, #0 */
/* @0xf0cd4 add r0, pc, r0 */
/* @0xf0cd8 movt r3, #0x4008 */
/* @0xf0cdc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ce0 ldr r0, [pc, #0x90c] */
/* @0xf0ce4 mov r2, #0 */
/* @0xf0ce8 mov r3, #0 */
/* @0xf0cec add r0, pc, r0 */
/* @0xf0cf0 movt r3, #0x4010 */
/* @0xf0cf4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0cf8 ldr r0, [pc, #0x8f8] */
/* @0xf0cfc mov r2, #0 */
/* @0xf0d00 mov r3, #0 */
/* @0xf0d04 add r0, pc, r0 */
/* @0xf0d08 movt r3, #0x4014 */
/* @0xf0d0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d10 ldr r0, [pc, #0x8e4] */
/* @0xf0d14 mov r2, #0 */
/* @0xf0d18 mov r3, #0 */
/* @0xf0d1c add r0, pc, r0 */
/* @0xf0d20 movt r3, #0x4018 */
/* @0xf0d24 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d28 ldr r0, [pc, #0x8d0] */
/* @0xf0d2c mov r2, #0 */
/* @0xf0d30 mov r3, #0 */
/* @0xf0d34 add r0, pc, r0 */
/* @0xf0d38 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d3c ldr r0, [pc, #0x8c0] */
/* @0xf0d40 mov r2, #0 */
/* @0xf0d44 mov r3, #0 */
/* @0xf0d48 add r0, pc, r0 */
/* @0xf0d4c movt r3, #0x3ff0 */
/* @0xf0d50 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d54 ldr r0, [pc, #0x8ac] */
/* @0xf0d58 mov r2, #0 */
/* @0xf0d5c mov r3, #1073741824 */
/* @0xf0d60 add r0, pc, r0 */
/* @0xf0d64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d68 ldr r0, [pc, #0x89c] */
/* @0xf0d6c mov r2, #0 */
/* @0xf0d70 mov r3, #0 */
/* @0xf0d74 add r0, pc, r0 */
/* @0xf0d78 movt r3, #0x4008 */
/* @0xf0d7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d80 ldr r0, [pc, #0x888] */
/* @0xf0d84 mov r2, #0 */
/* @0xf0d88 mov r3, #0 */
/* @0xf0d8c add r0, pc, r0 */
/* @0xf0d90 movt r3, #0x4010 */
/* @0xf0d94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0d98 ldr r0, [pc, #0x874] */
/* @0xf0d9c mov r2, #0 */
/* @0xf0da0 mov r3, #0 */
/* @0xf0da4 add r0, pc, r0 */
/* @0xf0da8 movt r3, #0x4014 */
/* @0xf0dac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0db0 ldr r0, [pc, #0x860] */
/* @0xf0db4 mov r2, #0 */
/* @0xf0db8 mov r3, #0 */
/* @0xf0dbc add r0, pc, r0 */
/* @0xf0dc0 movt r3, #0x4018 */
/* @0xf0dc4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0dc8 ldr r0, [pc, #0x84c] */
/* @0xf0dcc mov r2, #0 */
/* @0xf0dd0 mov r3, #0 */
/* @0xf0dd4 add r0, pc, r0 */
/* @0xf0dd8 movt r3, #0x401c */
/* @0xf0ddc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0de0 ldr r0, [pc, #0x838] */
/* @0xf0de4 mov r2, #0 */
/* @0xf0de8 mov r3, #0 */
/* @0xf0dec add r0, pc, r0 */
/* @0xf0df0 movt r3, #0x4020 */
/* @0xf0df4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0df8 ldr r0, [pc, #0x824] */
/* @0xf0dfc mov r2, #0 */
/* @0xf0e00 mov r3, #0 */
/* @0xf0e04 add r0, pc, r0 */
/* @0xf0e08 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e0c ldr r0, [pc, #0x814] */
/* @0xf0e10 mov r2, #0 */
/* @0xf0e14 mov r3, #0 */
/* @0xf0e18 add r0, pc, r0 */
/* @0xf0e1c movt r3, #0x3ff0 */
/* @0xf0e20 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e24 ldr r0, [pc, #0x800] */
/* @0xf0e28 mov r2, #0 */
/* @0xf0e2c mov r3, #1073741824 */
/* @0xf0e30 add r0, pc, r0 */
/* @0xf0e34 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e38 ldr r0, [pc, #0x7f0] */
/* @0xf0e3c mov r2, #0 */
/* @0xf0e40 mov r3, #0 */
/* @0xf0e44 add r0, pc, r0 */
/* @0xf0e48 movt r3, #0x4008 */
/* @0xf0e4c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e50 ldr r0, [pc, #0x7dc] */
/* @0xf0e54 mov r2, #0 */
/* @0xf0e58 mov r3, #0 */
/* @0xf0e5c add r0, pc, r0 */
/* @0xf0e60 movt r3, #0x4010 */
/* @0xf0e64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e68 ldr r0, [pc, #0x7c8] */
/* @0xf0e6c mov r2, #0 */
/* @0xf0e70 mov r3, #0 */
/* @0xf0e74 add r0, pc, r0 */
/* @0xf0e78 movt r3, #0x4014 */
/* @0xf0e7c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e80 ldr r0, [pc, #0x7b4] */
/* @0xf0e84 mov r2, #0 */
/* @0xf0e88 mov r3, #0 */
/* @0xf0e8c add r0, pc, r0 */
/* @0xf0e90 movt r3, #0x4018 */
/* @0xf0e94 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0e98 ldr r0, [pc, #0x7a0] */
/* @0xf0e9c mov r2, #0 */
/* @0xf0ea0 mov r3, #0 */
/* @0xf0ea4 add r0, pc, r0 */
/* @0xf0ea8 movt r3, #0x401c */
/* @0xf0eac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0eb0 ldr r0, [pc, #0x78c] */
/* @0xf0eb4 mov r2, #0 */
/* @0xf0eb8 mov r3, #0 */
/* @0xf0ebc add r0, pc, r0 */
/* @0xf0ec0 movt r3, #0x4020 */
/* @0xf0ec4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ec8 ldr r0, [pc, #0x778] */
/* @0xf0ecc mov r2, #0 */
/* @0xf0ed0 mov r3, #0 */
/* @0xf0ed4 add r0, pc, r0 */
/* @0xf0ed8 movt r3, #0x4022 */
/* @0xf0edc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ee0 ldr r0, [pc, #0x764] */
/* @0xf0ee4 mov r2, #0 */
/* @0xf0ee8 mov r3, #0 */
/* @0xf0eec add r0, pc, r0 */
/* @0xf0ef0 movt r3, #0x4024 */
/* @0xf0ef4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ef8 ldr r0, [pc, #0x750] */
/* @0xf0efc mov r2, #0 */
/* @0xf0f00 mov r3, #0 */
/* @0xf0f04 add r0, pc, r0 */
/* @0xf0f08 movt r3, #0x4026 */
/* @0xf0f0c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f10 ldr r0, [pc, #0x73c] */
/* @0xf0f14 mov r2, #0 */
/* @0xf0f18 mov r3, #0 */
/* @0xf0f1c add r0, pc, r0 */
/* @0xf0f20 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f24 ldr r0, [pc, #0x72c] */
/* @0xf0f28 mov r2, #0 */
/* @0xf0f2c mov r3, #0 */
/* @0xf0f30 add r0, pc, r0 */
/* @0xf0f34 movt r3, #0x3ff0 */
/* @0xf0f38 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f3c ldr r0, [pc, #0x718] */
/* @0xf0f40 mov r2, #0 */
/* @0xf0f44 mov r3, #0 */
/* @0xf0f48 add r0, pc, r0 */
/* @0xf0f4c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f50 ldr r0, [pc, #0x708] */
/* @0xf0f54 mov r2, #0 */
/* @0xf0f58 mov r3, #0 */
/* @0xf0f5c add r0, pc, r0 */
/* @0xf0f60 movt r3, #0x3ff0 */
/* @0xf0f64 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f68 ldr r0, [pc, #0x6f4] */
/* @0xf0f6c mov r2, #0 */
/* @0xf0f70 mov r3, #1073741824 */
/* @0xf0f74 add r0, pc, r0 */
/* @0xf0f78 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f7c ldr r0, [pc, #0x6e4] */
/* @0xf0f80 mov r2, #0 */
/* @0xf0f84 mov r3, #0 */
/* @0xf0f88 add r0, pc, r0 */
/* @0xf0f8c movt r3, #0x4008 */
/* @0xf0f90 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0f94 ldr r0, [pc, #0x6d0] */
/* @0xf0f98 mov r2, #0 */
/* @0xf0f9c mov r3, #0 */
/* @0xf0fa0 add r0, pc, r0 */
/* @0xf0fa4 movt r3, #0x4010 */
/* @0xf0fa8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0fac ldr r0, [pc, #0x6bc] */
/* @0xf0fb0 mov r2, #0 */
/* @0xf0fb4 mov r3, #0 */
/* @0xf0fb8 add r0, pc, r0 */
/* @0xf0fbc movt r3, #0x4014 */
/* @0xf0fc0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0fc4 ldr r0, [pc, #0x6a8] */
/* @0xf0fc8 mov r2, #0 */
/* @0xf0fcc mov r3, #0 */
/* @0xf0fd0 add r0, pc, r0 */
/* @0xf0fd4 movt r3, #0x3ff0 */
/* @0xf0fd8 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0fdc ldr r0, [pc, #0x694] */
/* @0xf0fe0 mov r2, #0 */
/* @0xf0fe4 mov r3, #1073741824 */
/* @0xf0fe8 add r0, pc, r0 */
/* @0xf0fec bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf0ff0 ldr r0, [pc, #0x684] */
/* @0xf0ff4 mov r2, #0 */
/* @0xf0ff8 mov r3, #0 */
/* @0xf0ffc add r0, pc, r0 */
/* @0xf1000 movt r3, #0x4008 */
/* @0xf1004 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1008 ldr r0, [pc, #0x670] */
/* @0xf100c mov r2, #0 */
/* @0xf1010 mov r3, #0 */
/* @0xf1014 add r0, pc, r0 */
/* @0xf1018 movt r3, #0x4010 */
/* @0xf101c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1020 ldr r0, [pc, #0x65c] */
/* @0xf1024 mov r2, #0 */
/* @0xf1028 mov r3, #0 */
/* @0xf102c add r0, pc, r0 */
/* @0xf1030 movt r3, #0x4014 */
/* @0xf1034 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1038 ldr r0, [pc, #0x648] */
/* @0xf103c mov r2, #0 */
/* @0xf1040 mov r3, #0 */
/* @0xf1044 add r0, pc, r0 */
/* @0xf1048 movt r3, #0x4018 */
/* @0xf104c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1050 ldr r0, [pc, #0x634] */
/* @0xf1054 mov r2, #0 */
/* @0xf1058 mov r3, #0 */
/* @0xf105c add r0, pc, r0 */
/* @0xf1060 movt r3, #0x401c */
/* @0xf1064 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1068 ldr r0, [pc, #0x620] */
/* @0xf106c mov r2, #0 */
/* @0xf1070 mov r3, #0 */
/* @0xf1074 add r0, pc, r0 */
/* @0xf1078 movt r3, #0x4020 */
/* @0xf107c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1080 ldr r0, [pc, #0x60c] */
/* @0xf1084 mov r2, #0 */
/* @0xf1088 mov r3, #0 */
/* @0xf108c add r0, pc, r0 */
/* @0xf1090 movt r3, #0x4022 */
/* @0xf1094 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1098 ldr r0, [pc, #0x5f8] */
/* @0xf109c mov r2, #0 */
/* @0xf10a0 mov r3, #0 */
/* @0xf10a4 add r0, pc, r0 */
/* @0xf10a8 movt r3, #0x4024 */
/* @0xf10ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf10b0 ldr r0, [pc, #0x5e4] */
/* @0xf10b4 mov r2, #0 */
/* @0xf10b8 mov r3, #0 */
/* @0xf10bc add r0, pc, r0 */
/* @0xf10c0 movt r3, #0x4026 */
/* @0xf10c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf10c8 ldr r0, [pc, #0x5d0] */
/* @0xf10cc mov r2, #0 */
/* @0xf10d0 mov r3, #0 */
/* @0xf10d4 add r0, pc, r0 */
/* @0xf10d8 movt r3, #0x4028 */
/* @0xf10dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf10e0 ldr r0, [pc, #0x5bc] */
/* @0xf10e4 mov r2, #0 */
/* @0xf10e8 mov r3, #0 */
/* @0xf10ec add r0, pc, r0 */
/* @0xf10f0 movt r3, #0x402a */
/* @0xf10f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf10f8 ldr r0, [pc, #0x5a8] */
/* @0xf10fc mov r2, #0 */
/* @0xf1100 mov r3, #0 */
/* @0xf1104 add r0, pc, r0 */
/* @0xf1108 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf110c ldr r0, [pc, #0x598] */
/* @0xf1110 mov r2, #0 */
/* @0xf1114 mov r3, #0 */
/* @0xf1118 add r0, pc, r0 */
/* @0xf111c movt r3, #0x3ff0 */
/* @0xf1120 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1124 ldr r0, [pc, #0x584] */
/* @0xf1128 mov r2, #0 */
/* @0xf112c mov r3, #1073741824 */
/* @0xf1130 add r0, pc, r0 */
/* @0xf1134 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1138 pop {r4, lr} */
/* @0xf113c b 0x15d0f8 <_Z25InitYoYoFunctionConstantsv> */
/* @0xf1140 ldr r0, [pc, #0x56c] */
/* @0xf1144 mov r2, #0 */
/* @0xf1148 mov r3, #0 */
/* @0xf114c add r0, pc, r0 */
/* @0xf1150 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1154 ldr r0, [pc, #0x55c] */
/* @0xf1158 mov r2, #0 */
/* @0xf115c mov r3, #0 */
/* @0xf1160 add r0, pc, r0 */
/* @0xf1164 movt r3, #0x3ff0 */
/* @0xf1168 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf116c b 0xefd94 <_Z24INITIALIZE_Code_Constantv+0x1d78> */
/* @0xf1170 ldr r0, [pc, #0x544] */
/* @0xf1174 mov r2, #0 */
/* @0xf1178 mov r3, #0 */
/* @0xf117c add r0, pc, r0 */
/* @0xf1180 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1184 ldr r0, [pc, #0x534] */
/* @0xf1188 mov r2, #0 */
/* @0xf118c mov r3, #0 */
/* @0xf1190 add r0, pc, r0 */
/* @0xf1194 movt r3, #0x3ff0 */
/* @0xf1198 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf119c ldr r0, [pc, #0x520] */
/* @0xf11a0 mov r2, #0 */
/* @0xf11a4 mov r3, #1073741824 */
/* @0xf11a8 add r0, pc, r0 */
/* @0xf11ac bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf11b0 ldr r0, [pc, #0x510] */
/* @0xf11b4 mov r2, #0 */
/* @0xf11b8 mov r3, #0 */
/* @0xf11bc add r0, pc, r0 */
/* @0xf11c0 movt r3, #0x4008 */
/* @0xf11c4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf11c8 ldr r0, [pc, #0x4fc] */
/* @0xf11cc mov r2, #0 */
/* @0xf11d0 mov r3, #0 */
/* @0xf11d4 add r0, pc, r0 */
/* @0xf11d8 movt r3, #0x4010 */
/* @0xf11dc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf11e0 ldr r0, [pc, #0x4e8] */
/* @0xf11e4 mov r2, #0 */
/* @0xf11e8 mov r3, #0 */
/* @0xf11ec add r0, pc, r0 */
/* @0xf11f0 movt r3, #0x4014 */
/* @0xf11f4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf11f8 ldr r0, [pc, #0x4d4] */
/* @0xf11fc mov r2, #0 */
/* @0xf1200 mov r3, #0 */
/* @0xf1204 add r0, pc, r0 */
/* @0xf1208 movt r3, #0x4018 */
/* @0xf120c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1210 ldr r0, [pc, #0x4c0] */
/* @0xf1214 mov r2, #0 */
/* @0xf1218 mov r3, #0 */
/* @0xf121c add r0, pc, r0 */
/* @0xf1220 movt r3, #0x401c */
/* @0xf1224 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1228 ldr r0, [pc, #0x4ac] */
/* @0xf122c mov r2, #0 */
/* @0xf1230 mov r3, #0 */
/* @0xf1234 add r0, pc, r0 */
/* @0xf1238 movt r3, #0x4020 */
/* @0xf123c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1240 ldr r0, [pc, #0x498] */
/* @0xf1244 mov r2, #0 */
/* @0xf1248 mov r3, #0 */
/* @0xf124c add r0, pc, r0 */
/* @0xf1250 movt r3, #0x4022 */
/* @0xf1254 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1258 ldr r0, [pc, #0x484] */
/* @0xf125c mov r2, #0 */
/* @0xf1260 mov r3, #0 */
/* @0xf1264 add r0, pc, r0 */
/* @0xf1268 movt r3, #0x4024 */
/* @0xf126c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1270 ldr r0, [pc, #0x470] */
/* @0xf1274 mov r2, #0 */
/* @0xf1278 mov r3, #0 */
/* @0xf127c add r0, pc, r0 */
/* @0xf1280 movt r3, #0x4026 */
/* @0xf1284 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1288 ldr r0, [pc, #0x45c] */
/* @0xf128c mov r2, #0 */
/* @0xf1290 mov r3, #0 */
/* @0xf1294 add r0, pc, r0 */
/* @0xf1298 movt r3, #0x4028 */
/* @0xf129c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf12a0 ldr r0, [pc, #0x448] */
/* @0xf12a4 mov r2, #0 */
/* @0xf12a8 mov r3, #0 */
/* @0xf12ac add r0, pc, r0 */
/* @0xf12b0 movt r3, #0x4050 */
/* @0xf12b4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf12b8 ldr r0, [pc, #0x434] */
/* @0xf12bc mov r2, #0 */
/* @0xf12c0 mov r3, #16384 */
/* @0xf12c4 add r0, pc, r0 */
/* @0xf12c8 movt r3, #0x4050 */
/* @0xf12cc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf12d0 ldr r0, [pc, #0x420] */
/* @0xf12d4 mov r2, #0 */
/* @0xf12d8 mov r3, #32768 */
/* @0xf12dc add r0, pc, r0 */
/* @0xf12e0 movt r3, #0x4050 */
/* @0xf12e4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf12e8 ldr r0, [pc, #0x40c] */
/* @0xf12ec mov r2, #0 */
/* @0xf12f0 mov r3, #49152 */
/* @0xf12f4 add r0, pc, r0 */
/* @0xf12f8 movt r3, #0x4050 */
/* @0xf12fc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1300 ldr r0, [pc, #0x3f8] */
/* @0xf1304 mov r2, #0 */
/* @0xf1308 mov r3, #0 */
/* @0xf130c add r0, pc, r0 */
/* @0xf1310 movt r3, #0x4051 */
/* @0xf1314 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1318 ldr r0, [pc, #0x3e4] */
/* @0xf131c mov r2, #0 */
/* @0xf1320 mov r3, #16384 */
/* @0xf1324 add r0, pc, r0 */
/* @0xf1328 movt r3, #0x4051 */
/* @0xf132c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1330 ldr r0, [pc, #0x3d0] */
/* @0xf1334 mov r2, #0 */
/* @0xf1338 mov r3, #32768 */
/* @0xf133c add r0, pc, r0 */
/* @0xf1340 movt r3, #0x4051 */
/* @0xf1344 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1348 ldr r0, [pc, #0x3bc] */
/* @0xf134c mov r2, #0 */
/* @0xf1350 mov r3, #49152 */
/* @0xf1354 add r0, pc, r0 */
/* @0xf1358 movt r3, #0x4051 */
/* @0xf135c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1360 ldr r0, [pc, #0x3a8] */
/* @0xf1364 mov r2, #0 */
/* @0xf1368 mov r3, #0 */
/* @0xf136c add r0, pc, r0 */
/* @0xf1370 movt r3, #0x4052 */
/* @0xf1374 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1378 ldr r0, [pc, #0x394] */
/* @0xf137c mov r2, #0 */
/* @0xf1380 mov r3, #16384 */
/* @0xf1384 add r0, pc, r0 */
/* @0xf1388 movt r3, #0x4052 */
/* @0xf138c bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1390 ldr r0, [pc, #0x380] */
/* @0xf1394 mov r2, #0 */
/* @0xf1398 mov r3, #32768 */
/* @0xf139c add r0, pc, r0 */
/* @0xf13a0 movt r3, #0x4052 */
/* @0xf13a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf13a8 ldr r0, [pc, #0x36c] */
/* @0xf13ac mov r2, #0 */
/* @0xf13b0 mov r3, #49152 */
/* @0xf13b4 add r0, pc, r0 */
/* @0xf13b8 movt r3, #0x4052 */
/* @0xf13bc bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf13c0 ldr r0, [pc, #0x358] */
/* @0xf13c4 mov r2, #0 */
/* @0xf13c8 mov r3, #0 */
/* @0xf13cc add r0, pc, r0 */
/* @0xf13d0 movt r3, #0x4053 */
/* @0xf13d4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf13d8 b 0xefc1c <_Z24INITIALIZE_Code_Constantv+0x1c00> */
/* @0xf13dc ldr r0, [pc, #0x340] */
/* @0xf13e0 mov r2, #0 */
/* @0xf13e4 mov r3, #0 */
/* @0xf13e8 movt r3, #0x4028 */
/* @0xf13ec add r0, pc, r0 */
/* @0xf13f0 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf13f4 ldr r0, [pc, #0x32c] */
/* @0xf13f8 mov r2, #0 */
/* @0xf13fc mov r3, #0 */
/* @0xf1400 add r0, pc, r0 */
/* @0xf1404 movt r3, #0x402a */
/* @0xf1408 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf140c ldr r0, [pc, #0x318] */
/* @0xf1410 mov r2, #0 */
/* @0xf1414 mov r3, #0 */
/* @0xf1418 add r0, pc, r0 */
/* @0xf141c movt r3, #0x402c */
/* @0xf1420 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1424 b 0xeef4c <_Z24INITIALIZE_Code_Constantv+0xf30> */
/* @0xf1428 ldr r0, [pc, #0x300] */
/* @0xf142c mov r2, #0 */
/* @0xf1430 mov r3, #0 */
/* @0xf1434 add r0, pc, r0 */
/* @0xf1438 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf143c ldr r0, [pc, #0x2f0] */
/* @0xf1440 mov r2, #0 */
/* @0xf1444 mov r3, #0 */
/* @0xf1448 add r0, pc, r0 */
/* @0xf144c movt r3, #0x3ff0 */
/* @0xf1450 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1454 ldr r0, [pc, #0x2dc] */
/* @0xf1458 mov r2, #0 */
/* @0xf145c mov r3, #1073741824 */
/* @0xf1460 add r0, pc, r0 */
/* @0xf1464 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1468 ldr r0, [pc, #0x2cc] */
/* @0xf146c mov r2, #0 */
/* @0xf1470 mov r3, #0 */
/* @0xf1474 add r0, pc, r0 */
/* @0xf1478 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf147c ldr r0, [pc, #0x2bc] */
/* @0xf1480 mov r2, #0 */
/* @0xf1484 mov r3, #0 */
/* @0xf1488 add r0, pc, r0 */
/* @0xf148c movt r3, #0x3ff0 */
/* @0xf1490 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf1494 ldr r0, [pc, #0x2a8] */
/* @0xf1498 mov r2, #0 */
/* @0xf149c mov r3, #1073741824 */
/* @0xf14a0 add r0, pc, r0 */
/* @0xf14a4 bl 0xedff4 <_Z15AddRealConstantPKcd> */
/* @0xf14a8 b 0xee4f8 <_Z24INITIALIZE_Code_Constantv+0x4dc> */
/* @0xf14ac eoreq r5, r4, r8, ror pc */
/* @0xf14b0 eoreq r5, r4, r8, ror #30 */
/* @0xf14b4 eoreq r5, r4, r8, asr pc */
/* @0xf14b8 eoreq r5, r4, r12, asr #30 */
/* @0xf14bc eoreq r5, r4, r12, lsr pc */
/* @0xf14c0 eoreq r5, r4, r0, lsr pc */
/* @0xf14c4 eoreq r5, r4, r0, lsr #30 */
/* @0xf14c8 eoreq r5, r4, r4, lsr #30 */
/* @0xf14cc eoreq r5, r4, r4, lsr #30 */
/* @0xf14d0 eoreq r5, r4, r8, lsr #30 */
/* @0xf14d4 eoreq r5, r4, r8, lsr #30 */
/* @0xf14d8 eoreq r5, r4, r12, lsr #30 */
/* @0xf14dc eoreq r5, r4, r0, lsr pc */
/* @0xf14e0 eoreq r5, r4, r4, lsr pc */
/* @0xf14e4 eoreq r5, r4, r12, lsr #30 */
/* @0xf14e8 eoreq r5, r4, r12, lsr #30 */
/* @0xf14ec eoreq r5, r4, r12, lsr #30 */
/* @0xf14f0 eoreq r5, r4, r0, lsr pc */
/* @0xf14f4 eoreq r5, r4, r0, lsr pc */
/* @0xf14f8 eoreq r5, r4, r8, lsr #30 */
/* @0xf14fc eoreq r5, r4, r8, lsr #30 */
/* @0xf1500 eoreq r5, r4, r12, lsr #30 */
/* @0xf1504 eoreq r5, r4, r8, lsr #30 */
/* @0xf1508 eoreq r5, r4, r4, lsr #30 */
/* @0xf150c eoreq r5, r4, r4, lsr #30 */
/* @0xf1510 eoreq r5, r4, r0, lsr #30 */
/* @0xf1514 eoreq r5, r4, r0, lsr #30 */
/* @0xf1518 eoreq r5, r4, r4, lsr #30 */
/* @0xf151c eoreq r5, r4, r4, lsr #30 */
/* @0xf1520 eoreq r5, r4, r4, lsr #30 */
/* @0xf1524 eoreq r5, r4, r4, lsr #30 */
/* @0xf1528 eoreq r5, r4, r12, lsr #30 */
/* @0xf152c .word 0x002448d0 */
/* @0xf1530 .word 0x002448d0 */
/* @0xf1534 .word 0x002448d8 */
/* @0xf1538 eoreq r4, r4, r12, ror #17 */
/* @0xf153c .word 0x002448f4 */
/* @0xf1540 eoreq r4, r4, r4, lsl #18 */
/* @0xf1544 eoreq r4, r4, r12, lsl #18 */
/* @0xf1548 eoreq r4, r4, r12, lsl r9 */
/* @0xf154c eoreq r4, r4, r12, lsl r9 */
/* @0xf1550 eoreq r4, r4, r8, lsl r9 */
/* @0xf1554 eoreq r4, r4, r0, lsl r9 */
/* @0xf1558 eoreq r4, r4, r8, lsl #18 */
/* @0xf155c eoreq r5, r4, r12, lsr #28 */
/* @0xf1560 eoreq r5, r4, r4, lsr #28 */
/* @0xf1564 eoreq r5, r4, r0, lsr #28 */
/* @0xf1568 eoreq r5, r4, r12, lsl lr */
/* @0xf156c eoreq r5, r4, r4, lsl lr */
/* @0xf1570 eoreq r5, r4, r12, lsl #28 */
/* @0xf1574 eoreq r5, r4, r4, lsl #28 */
/* @0xf1578 .word 0x00245df8 */
/* @0xf157c .word 0x00245df0 */
/* @0xf1580 eoreq r5, r4, r8, ror #27 */
/* @0xf1584 eoreq r5, r4, r4, ror #27 */
/* @0xf1588 eoreq r5, r4, r0, ror #27 */
/* @0xf158c eoreq r5, r4, r0, ror #27 */
/* @0xf1590 .word 0x00245ddc */
/* @0xf1594 .word 0x00245dd4 */
/* @0xf1598 .word 0x00245dd4 */
/* @0xf159c eoreq r5, r4, r12, asr #27 */
/* @0xf15a0 eoreq r5, r4, r8, asr #27 */
/* @0xf15a4 eoreq r5, r4, r12, asr #27 */
/* @0xf15a8 eoreq r5, r4, r12, asr #27 */
/* @0xf15ac .word 0x00245dd0 */
/* @0xf15b0 .word 0x00245dd4 */
/* @0xf15b4 .word 0x00245dd8 */
/* @0xf15b8 .word 0x00245ddc */
/* @0xf15bc eoreq r5, r4, r8, ror #27 */
/* @0xf15c0 eoreq r5, r4, r4, lsl #28 */
/* @0xf15c4 eoreq r5, r4, r4, lsl #28 */
/* @0xf15c8 eoreq r5, r4, r0, lsr #28 */
/* @0xf15cc eoreq r5, r4, r12, lsr lr */
/* @0xf15d0 eoreq r5, r4, r8, asr #28 */
/* @0xf15d4 eoreq r5, r4, r8, ror #28 */
/* @0xf15d8 eoreq r5, r4, r8, ror #28 */
/* @0xf15dc eoreq r5, r4, r0, ror lr */
/* @0xf15e0 eoreq r5, r4, r4, ror lr */
/* @0xf15e4 eoreq r5, r4, r12, ror lr */
/* @0xf15e8 eoreq r5, r4, r8, lsl #29 */
/* @0xf15ec mlaeq r4, r0, lr, r5 */
/* @0xf15f0 mlaeq r4, r4, lr, r5 */
/* @0xf15f4 mlaeq r4, r12, lr, r5 */
/* @0xf15f8 eoreq r5, r4, r8, lsr #29 */
/* @0xf15fc eoreq r5, r4, r12, lsr #29 */
/* @0xf1600 .word 0x00245eb0 */
/* @0xf1604 .word 0x00245eb0 */
/* @0xf1608 eoreq r5, r4, r12, lsr #29 */
/* @0xf160c eoreq r5, r4, r12, lsr #29 */
/* @0xf1610 eoreq r5, r4, r8, lsr #29 */
/* @0xf1614 eoreq r5, r4, r8, lsr #29 */
/* @0xf1618 eoreq r5, r4, r4, lsr #29 */
/* @0xf161c eoreq r5, r4, r0, lsr #29 */
/* @0xf1620 eoreq r5, r4, r0, lsr #29 */
/* @0xf1624 mlaeq r4, r12, lr, r5 */
/* @0xf1628 mlaeq r4, r8, lr, r5 */
/* @0xf162c mlaeq r4, r4, lr, r5 */
/* @0xf1630 mlaeq r4, r12, lr, r5 */
/* @0xf1634 mlaeq r4, r12, lr, r5 */
/* @0xf1638 mlaeq r4, r8, lr, r5 */
/* @0xf163c mlaeq r4, r4, lr, r5 */
/* @0xf1640 mlaeq r4, r4, lr, r5 */
/* @0xf1644 mlaeq r4, r0, lr, r5 */
/* @0xf1648 eoreq r5, r4, r12, lsl #29 */
/* @0xf164c mlaeq r4, r0, lr, r5 */
/* @0xf1650 mlaeq r4, r0, lr, r5 */
/* @0xf1654 mlaeq r4, r8, lr, r5 */
/* @0xf1658 mlaeq r4, r4, lr, r5 */
/* @0xf165c eoreq r5, r4, r12, lsl #29 */
/* @0xf1660 eoreq r5, r4, r8, lsl #29 */
/* @0xf1664 eoreq r5, r4, r12, ror lr */
/* @0xf1668 eoreq r5, r4, r4, ror lr */
/* @0xf166c eoreq r5, r4, r8, ror #28 */
/* @0xf1670 eoreq r5, r4, r0, ror #28 */
/* @0xf1674 eoreq r5, r4, r8, asr lr */
/* @0xf1678 eoreq r5, r4, r12, asr #28 */
/* @0xf167c eoreq r5, r4, r4, asr #28 */
/* @0xf1680 eoreq r5, r4, r8, lsr lr */
/* @0xf1684 eoreq r5, r4, r12, lsr #28 */
/* @0xf1688 eoreq r5, r4, r0, lsr #28 */
/* @0xf168c eoreq r5, r4, r4, lsl lr */
/* @0xf1690 eoreq r5, r4, r8, lsl #28 */
/* @0xf1694 .word 0x00245dfc */
/* @0xf1698 .word 0x00245df0 */
/* @0xf169c eoreq r5, r4, r4, ror #27 */
/* @0xf16a0 .word 0x00245ddc */
/* @0xf16a4 .word 0x00245dd0 */
/* @0xf16a8 eoreq r5, r4, r4, asr #27 */
/* @0xf16ac eoreq r5, r4, r4, asr #27 */
/* @0xf16b0 eoreq r5, r4, r4, asr #27 */
/* @0xf16b4 eoreq r4, r4, r8, asr #29 */
/* @0xf16b8 eoreq r4, r4, r0, asr #29 */
/* @0xf16bc eoreq r4, r4, r4, lsr r11 */
/* @0xf16c0 eoreq r4, r4, r0, lsr r11 */
/* @0xf16c4 eoreq r4, r4, r0, lsr r11 */
/* @0xf16c8 eoreq r4, r4, r4, lsr r11 */
/* @0xf16cc eoreq r4, r4, r0, lsr r11 */
/* @0xf16d0 eoreq r4, r4, r12, lsr #22 */
/* @0xf16d4 eoreq r4, r4, r8, lsr #22 */
/* @0xf16d8 eoreq r4, r4, r8, lsr #22 */
/* @0xf16dc eoreq r4, r4, r4, lsr #22 */
/* @0xf16e0 eoreq r4, r4, r4, lsr #22 */
/* @0xf16e4 eoreq r4, r4, r4, lsr #22 */
/* @0xf16e8 eoreq r4, r4, r4, lsr #22 */
/* @0xf16ec eoreq r4, r4, r0, lsr #22 */
/* @0xf16f0 eoreq r4, r4, r0, lsr #22 */
/* @0xf16f4 eoreq r4, r4, r0, lsr #22 */
/* @0xf16f8 eoreq r4, r4, r8, lsr #22 */
/* @0xf16fc eoreq r4, r4, r0, lsr r11 */
/* @0xf1700 eoreq r4, r4, r4, lsr r11 */
/* @0xf1704 eoreq r4, r4, r8, lsr r11 */
/* @0xf1708 eoreq r4, r4, r8, lsr r11 */
/* @0xf170c eoreq r4, r4, r0, asr #22 */
/* @0xf1710 eoreq r4, r4, r4, asr #22 */
/* @0xf1714 eoreq r4, r4, r8, asr #22 */
/* @0xf1718 eoreq r4, r4, r12, asr #22 */
/* @0xf171c eoreq r4, r4, r4, asr r11 */
/* @0xf1720 eoreq r4, r4, r8, asr r11 */
/* @0xf1724 .word 0x002442f8 */
/* @0xf1728 .word 0x002442f0 */
/* @0xf172c eoreq r4, r4, r4, ror #5 */
/* @0xf1730 eoreq r3, r4, r0, ror #25 */
/* @0xf1734 .word 0x00243cd8 */
/* @0xf1738 eoreq r3, r4, r12, asr #25 */
/* @0xf173c eoreq r3, r4, r8, asr #25 */
/* @0xf1740 .word 0x00243cbc */
/* @0xf1744 eoreq r3, r4, r12, lsr #25 */

/* ── FUNC 0xf1748 · AddStringConstant(char const*, char const*) · size=40 · insn=10 */
/* @0xf1748 push {r4, r5, lr} */
/* @0xf174c sub sp, sp, #20 */
/* @0xf1750 mov r5, r0 */
/* @0xf1754 mov r0, sp */
/* @0xf1758 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xf175c mov r0, r5 */
/* @0xf1760 mov r1, sp */
/* @0xf1764 bl 0xedd00 <_Z11AddConstantPKcP6RValue> */
/* @0xf1768 add sp, sp, #20 */
/* @0xf176c pop {r4, r5, pc} */

/* ── FUNC 0xf1770 · Code_Constant_Find(char const*, RValue*) · size=672 · insn=168 */
/* @0xf1770 mov r2, #0 */
/* @0xf1774 push {r3, r4, r5, r6, r7, lr} */
/* @0xf1778 mov r3, r2 */
/* @0xf177c movt r2, #0xbff0 */
/* @0xf1780 str r3, [r1, #0xc] */
/* @0xf1784 str r2, [r1, #0x4] */
/* @0xf1788 mov r4, r1 */
/* @0xf178c str r3, [r1] */
/* @0xf1790 mov r5, r0 */
/* @0xf1794 bl 0x1eef64 <_Z11Sprite_FindPKc> */
/* @0xf1798 cmp r0, #0 */
/* @0xf179c blt 0xf17b8 <_Z18Code_Constant_FindPKcP6RValue+0x48> */
/* @0xf17a0 vmov s15, r0 */
/* @0xf17a4 mov r0, #1 */
/* @0xf17a8 vcvt.f64.s32 d7, s15 */
/* @0xf17ac vmov r2, r3, d7 */
/* @0xf17b0 stm r4, {r2, r3} */
/* @0xf17b4 pop {r3, r4, r5, r6, r7, pc} */
/* @0xf17b8 mov r0, r5 */
/* @0xf17bc bl 0x21fc54 <_Z10Sound_FindPKc> */
/* @0xf17c0 cmp r0, #0 */
/* @0xf17c4 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30> */
/* @0xf17c8 mov r0, r5 */
/* @0xf17cc bl 0x19edf4 <_Z11Object_FindPKc> */
/* @0xf17d0 cmp r0, #0 */
/* @0xf17d4 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30> */
/* @0xf17d8 mov r0, r5 */
/* @0xf17dc bl 0x219794 <_Z10Audio_FindPKc> */
/* @0xf17e0 cmp r0, #0 */
/* @0xf17e4 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30> */
/* @0xf17e8 mov r0, r5 */
/* @0xf17ec bl 0xc370c <_Z15Background_FindPKc> */
/* @0xf17f0 cmp r0, #0 */
/* @0xf17f4 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30> */
/* @0xf17f8 mov r0, r5 */
/* @0xf17fc bl 0x1a80d4 <_Z9Path_FindPKc> */
/* @0xf1800 cmp r0, #0 */
/* @0xf1804 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30> */
/* @0xf1808 mov r0, r5 */
/* @0xf180c bl 0xfa374 <_Z9Font_FindPKc> */
/* @0xf1810 cmp r0, #0 */
/* @0xf1814 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30> */
/* @0xf1818 mov r0, r5 */
/* @0xf181c bl 0x1f2bcc <_Z13TimeLine_FindPKc> */
/* @0xf1820 cmp r0, #0 */
/* @0xf1824 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30> */
/* @0xf1828 mov r0, r5 */
/* @0xf182c bl 0x1e0610 <_Z11Script_FindPKc> */
/* @0xf1830 cmp r0, #0 */
/* @0xf1834 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30> */
/* @0xf1838 mov r0, r5 */
/* @0xf183c bl 0x1b524c <_Z9Room_FindPKc> */
/* @0xf1840 cmp r0, #0 */
/* @0xf1844 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30> */
/* @0xf1848 mov r0, r5 */
/* @0xf184c bl 0x1e12dc <_Z11Shader_FindPKc> */
/* @0xf1850 cmp r0, #0 */
/* @0xf1854 bge 0xf17a0 <_Z18Code_Constant_FindPKcP6RValue+0x30> */
/* @0xf1858 ldr r2, [pc, #0x1a4] */
/* @0xf185c ldr r3, [pc, #0x1a4] */
/* @0xf1860 ldr r2, [pc, r2] */
/* @0xf1864 ldr r3, [pc, r3] */
/* @0xf1868 ldr r2, [r2] */
/* @0xf186c ldr r7, [r3] */
/* @0xf1870 sub r6, r2, #1 */
/* @0xf1874 add r7, r7, r2, lsl #2 */
/* @0xf1878 cmp r6, #0 */
/* @0xf187c mov r1, r5 */
/* @0xf1880 blt 0xf189c <_Z18Code_Constant_FindPKcP6RValue+0x12c> */
/* @0xf1884 ldr r0, [r7, #-0x4]! */
/* @0xf1888 bl 0xb6574 <strcmp@plt> */
/* @0xf188c cmp r0, #0 */
/* @0xf1890 beq 0xf18a4 <_Z18Code_Constant_FindPKcP6RValue+0x134> */
/* @0xf1894 sub r6, r6, #1 */
/* @0xf1898 b 0xf1878 <_Z18Code_Constant_FindPKcP6RValue+0x108> */
/* @0xf189c mov r0, #0 */
/* @0xf18a0 pop {r3, r4, r5, r6, r7, pc} */
/* @0xf18a4 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0xf18a8 ldr r3, [pc, #0x15c] */
/* @0xf18ac ldr r2, [r4, #0xc] */
/* @0xf18b0 lsl r5, r6, #4 */
/* @0xf18b4 ldr r3, [pc, r3] */
/* @0xf18b8 bic r1, r2, #-16777216 */
/* @0xf18bc ldr r6, [r3] */
/* @0xf18c0 cmp r1, #1 */
/* @0xf18c4 add r7, r6, r5 */
/* @0xf18c8 beq 0xf1968 <_Z18Code_Constant_FindPKcP6RValue+0x1f8> */
/* @0xf18cc cmp r1, #2 */
/* @0xf18d0 bne 0xf1900 <_Z18Code_Constant_FindPKcP6RValue+0x190> */
/* @0xf18d4 sub r3, r2, #1 */
/* @0xf18d8 bic r3, r3, #-16777216 */
/* @0xf18dc bic r3, r3, #3 */
/* @0xf18e0 cmp r3, #0 */
/* @0xf18e4 bne 0xf18f0 <_Z18Code_Constant_FindPKcP6RValue+0x180> */
/* @0xf18e8 mov r0, r4 */
/* @0xf18ec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xf18f0 mov r2, #0 */
/* @0xf18f4 mov r3, #5 */
/* @0xf18f8 str r2, [r4, #0x8] */
/* @0xf18fc str r3, [r4, #0xc] */
/* @0xf1900 ldr r3, [r7, #0xc] */
/* @0xf1904 mov r1, #0 */
/* @0xf1908 ldr r2, [r7, #0x8] */
/* @0xf190c str r1, [r4] */
/* @0xf1910 str r3, [r4, #0xc] */
/* @0xf1914 ldr r3, [r7, #0xc] */
/* @0xf1918 str r2, [r4, #0x8] */
/* @0xf191c bic r3, r3, #-16777216 */
/* @0xf1920 cmp r3, #14 */
/* @0xf1924 addls pc, pc, r3, lsl #2 */
/* @0xf1928 b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228> */
/* @0xf192c b 0xf19a4 <_Z18Code_Constant_FindPKcP6RValue+0x234> */
/* @0xf1930 b 0xf19ec <_Z18Code_Constant_FindPKcP6RValue+0x27c> */
/* @0xf1934 b 0xf19b4 <_Z18Code_Constant_FindPKcP6RValue+0x244> */
/* @0xf1938 b 0xf19e0 <_Z18Code_Constant_FindPKcP6RValue+0x270> */
/* @0xf193c b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228> */
/* @0xf1940 b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228> */
/* @0xf1944 b 0xf1978 <_Z18Code_Constant_FindPKcP6RValue+0x208> */
/* @0xf1948 b 0xf19e0 <_Z18Code_Constant_FindPKcP6RValue+0x270> */
/* @0xf194c b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228> */
/* @0xf1950 b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228> */
/* @0xf1954 b 0xf19a4 <_Z18Code_Constant_FindPKcP6RValue+0x234> */
/* @0xf1958 b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228> */
/* @0xf195c b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228> */
/* @0xf1960 b 0xf19a4 <_Z18Code_Constant_FindPKcP6RValue+0x234> */
/* @0xf1964 b 0xf19e0 <_Z18Code_Constant_FindPKcP6RValue+0x270> */
/* @0xf1968 ldr r0, [r4] */
/* @0xf196c bl 0xdc42c <_ZN9_RefThingIPKcE6removeEPS2_> */
/* @0xf1970 str r0, [r4] */
/* @0xf1974 b 0xf1900 <_Z18Code_Constant_FindPKcP6RValue+0x190> */
/* @0xf1978 ldr r3, [r6, r5] */
/* @0xf197c str r3, [r4] */
/* @0xf1980 ldr r3, [r6, r5] */
/* @0xf1984 cmp r3, #0 */
/* @0xf1988 beq 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228> */
/* @0xf198c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xf1990 ldr r1, [r6, r5] */
/* @0xf1994 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xf1998 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0xf199c mov r0, #1 */
/* @0xf19a0 pop {r3, r4, r5, r6, r7, pc} */
/* @0xf19a4 ldr r2, [r6, r5] */
/* @0xf19a8 ldr r3, [r7, #0x4] */
/* @0xf19ac stm r4, {r2, r3} */
/* @0xf19b0 b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228> */
/* @0xf19b4 ldr r3, [r6, r5] */
/* @0xf19b8 cmp r3, #0 */
/* @0xf19bc str r3, [r4] */
/* @0xf19c0 beq 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228> */
/* @0xf19c4 ldr r1, [r3, #0x8] */
/* @0xf19c8 ldr r2, [r3] */
/* @0xf19cc cmp r1, #0 */
/* @0xf19d0 streq r4, [r3, #0x8] */
/* @0xf19d4 add r2, r2, #1 */
/* @0xf19d8 str r2, [r3] */
/* @0xf19dc b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228> */
/* @0xf19e0 ldr r3, [r6, r5] */
/* @0xf19e4 str r3, [r4] */
/* @0xf19e8 b 0xf1998 <_Z18Code_Constant_FindPKcP6RValue+0x228> */
/* @0xf19ec ldr r3, [r6, r5] */
/* @0xf19f0 cmp r3, #0 */
/* @0xf19f4 ldrne r2, [r3, #0x4] */
/* @0xf19f8 addne r2, r2, #1 */
/* @0xf19fc strne r2, [r3, #0x4] */
/* @0xf1a00 b 0xf19e4 <_Z18Code_Constant_FindPKcP6RValue+0x274> */
/* @0xf1a04 eoreq r12, pc, r4, ror #10 */
/* @0xf1a08 eoreq r12, pc, r4, ror #10 */
/* @0xf1a0c eoreq r12, pc, r8, lsl r5 */

/* ── FUNC 0xf1a10 · Code_Constant_Add(char const*, char const*) · size=308 · insn=77 */
/* @0xf1a10 push {r4, r5, r6, r7, lr} */
/* @0xf1a14 sub sp, sp, #1040 */
/* @0xf1a18 ldr r4, [pc, #0x11c] */
/* @0xf1a1c sub sp, sp, #12 */
/* @0xf1a20 mov r1, r0 */
/* @0xf1a24 mov r3, #0 */
/* @0xf1a28 ldr r4, [pc, r4] */
/* @0xf1a2c mov r0, sp */
/* @0xf1a30 str r3, [sp, #0x10] */
/* @0xf1a34 add r6, sp, #4 */
/* @0xf1a38 ldr r12, [r4] */
/* @0xf1a3c str r3, [sp] */
/* @0xf1a40 str r3, [sp, #0x4] */
/* @0xf1a44 str r12, [sp, #0x414] */
/* @0xf1a48 str r3, [sp, #0x8] */
/* @0xf1a4c str r3, [sp, #0xc] */
/* @0xf1a50 bl 0xc4728 <_Z4TrimRPKcS0_> */
/* @0xf1a54 ldr r0, [sp] */
/* @0xf1a58 bl 0xedc04 <_Z14CheckConstNamePKc> */
/* @0xf1a5c subs r5, r0, #0 */
/* @0xf1a60 bne 0xf1ad4 <_Z17Code_Constant_AddPKcS0_+0xc4> */
/* @0xf1a64 add r7, sp, #20 */
/* @0xf1a68 ldr r2, [pc, #0xd0] */
/* @0xf1a6c mov r1, #1024 */
/* @0xf1a70 ldr r3, [sp] */
/* @0xf1a74 add r2, pc, r2 */
/* @0xf1a78 mov r0, r7 */
/* @0xf1a7c bl 0xb65c8 <snprintf@plt> */
/* @0xf1a80 mov r0, r7 */
/* @0xf1a84 bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0xf1a88 ldr r0, [sp] */
/* @0xf1a8c cmp r0, #0 */
/* @0xf1a90 beq 0xf1a9c <_Z17Code_Constant_AddPKcS0_+0x8c> */
/* @0xf1a94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf1a98 str r5, [sp] */
/* @0xf1a9c ldr r3, [sp, #0x10] */
/* @0xf1aa0 sub r3, r3, #1 */
/* @0xf1aa4 bic r3, r3, #-16777216 */
/* @0xf1aa8 bic r3, r3, #3 */
/* @0xf1aac cmp r3, #0 */
/* @0xf1ab0 beq 0xf1b20 <_Z17Code_Constant_AddPKcS0_+0x110> */
/* @0xf1ab4 ldr r2, [sp, #0x414] */
/* @0xf1ab8 mov r0, r5 */
/* @0xf1abc ldr r3, [r4] */
/* @0xf1ac0 cmp r2, r3 */
/* @0xf1ac4 bne 0xf1b38 <_Z17Code_Constant_AddPKcS0_+0x128> */
/* @0xf1ac8 add sp, sp, #1040 */
/* @0xf1acc add sp, sp, #12 */
/* @0xf1ad0 pop {r4, r5, r6, r7, pc} */
/* @0xf1ad4 ldr r0, [sp] */
/* @0xf1ad8 mov r1, r6 */
/* @0xf1adc bl 0xedd00 <_Z11AddConstantPKcP6RValue> */
/* @0xf1ae0 ldr r3, [sp, #0x10] */
/* @0xf1ae4 sub r3, r3, #1 */
/* @0xf1ae8 bic r3, r3, #-16777216 */
/* @0xf1aec bic r3, r3, #3 */
/* @0xf1af0 cmp r3, #0 */
/* @0xf1af4 beq 0xf1b2c <_Z17Code_Constant_AddPKcS0_+0x11c> */
/* @0xf1af8 ldr r0, [sp] */
/* @0xf1afc mov r3, #0 */
/* @0xf1b00 mov r2, #5 */
/* @0xf1b04 str r3, [sp, #0xc] */
/* @0xf1b08 cmp r0, r3 */
/* @0xf1b0c str r3, [sp, #0x4] */
/* @0xf1b10 str r2, [sp, #0x10] */
/* @0xf1b14 beq 0xf1ab4 <_Z17Code_Constant_AddPKcS0_+0xa4> */
/* @0xf1b18 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf1b1c b 0xf1ab4 <_Z17Code_Constant_AddPKcS0_+0xa4> */
/* @0xf1b20 mov r0, r6 */
/* @0xf1b24 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xf1b28 b 0xf1ab4 <_Z17Code_Constant_AddPKcS0_+0xa4> */
/* @0xf1b2c mov r0, r6 */
/* @0xf1b30 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xf1b34 b 0xf1af8 <_Z17Code_Constant_AddPKcS0_+0xe8> */
/* @0xf1b38 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xf1b3c eoreq r11, pc, r8, lsr #30 */
/* @0xf1b40 mlaeq r4, r0, r4, r5 */

/* ── FUNC 0xf1b44 · Code_Constant_Prepare() · size=108 · insn=27 */
/* @0xf1b44 push {r3, r4, r5, r6, r7, lr} */
/* @0xf1b48 ldr r5, [pc, #0x54] */
/* @0xf1b4c ldr r5, [pc, r5] */
/* @0xf1b50 ldr r3, [r5] */
/* @0xf1b54 cmp r3, #0 */
/* @0xf1b58 ble 0xf1b9c <_Z21Code_Constant_Preparev+0x58> */
/* @0xf1b5c ldr r7, [pc, #0x44] */
/* @0xf1b60 mov r4, #0 */
/* @0xf1b64 ldr r6, [pc, #0x40] */
/* @0xf1b68 ldr r7, [pc, r7] */
/* @0xf1b6c ldr r6, [pc, r6] */
/* @0xf1b70 ldr r2, [r7] */
/* @0xf1b74 ldr r3, [r6] */
/* @0xf1b78 ldr r0, [r2, r4, lsl #2] */
/* @0xf1b7c ldr r1, [r3, r4, lsl #2] */
/* @0xf1b80 add r4, r4, #1 */
/* @0xf1b84 bl 0xf1a10 <_Z17Code_Constant_AddPKcS0_> */
/* @0xf1b88 cmp r0, #0 */
/* @0xf1b8c popeq {r3, r4, r5, r6, r7, pc} */
/* @0xf1b90 ldr r3, [r5] */
/* @0xf1b94 cmp r3, r4 */
/* @0xf1b98 bgt 0xf1b70 <_Z21Code_Constant_Preparev+0x2c> */
/* @0xf1b9c mov r0, #1 */
/* @0xf1ba0 pop {r3, r4, r5, r6, r7, pc} */
/* @0xf1ba4 eoreq r12, pc, r8, lsl #5 */
/* @0xf1ba8 eoreq r12, pc, r0, ror r2 */
/* @0xf1bac eoreq r12, pc, r0, ror r2 */

/* ── FUNC 0xf1bb0 · FINALIZE_Code_Constant() · size=224 · insn=56 */
/* @0xf1bb0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf1bb4 ldr r3, [pc, #0xc4] */
/* @0xf1bb8 ldr r2, [pc, #0xc4] */
/* @0xf1bbc add r3, pc, r3 */
/* @0xf1bc0 ldr r8, [r3, r2] */
/* @0xf1bc4 ldr r0, [r8] */
/* @0xf1bc8 cmp r0, #0 */
/* @0xf1bcc popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf1bd0 ldr r2, [pc, #0xb0] */
/* @0xf1bd4 ldr r10, [r3, r2] */
/* @0xf1bd8 ldr r1, [r10] */
/* @0xf1bdc cmp r1, #0 */
/* @0xf1be0 ldr r1, [pc, #0xa4] */
/* @0xf1be4 ble 0xf1c5c <_Z22FINALIZE_Code_Constantv+0xac> */
/* @0xf1be8 mov r4, #0 */
/* @0xf1bec ldr r9, [r3, r1] */
/* @0xf1bf0 mov r11, r4 */
/* @0xf1bf4 b 0xf1c18 <_Z22FINALIZE_Code_Constantv+0x68> */
/* @0xf1bf8 mov r3, #5 */
/* @0xf1bfc str r11, [r5, #0x8] */
/* @0xf1c00 str r3, [r5, #0xc] */
/* @0xf1c04 str r11, [r7, r6] */
/* @0xf1c08 ldr r3, [r10] */
/* @0xf1c0c ldr r0, [r8] */
/* @0xf1c10 cmp r3, r4 */
/* @0xf1c14 ble 0xf1c60 <_Z22FINALIZE_Code_Constantv+0xb0> */
/* @0xf1c18 ldr r0, [r0, r4, lsl #2] */
/* @0xf1c1c lsl r6, r4, #4 */
/* @0xf1c20 add r4, r4, #1 */
/* @0xf1c24 cmp r0, #0 */
/* @0xf1c28 beq 0xf1c30 <_Z22FINALIZE_Code_Constantv+0x80> */
/* @0xf1c2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf1c30 ldr r7, [r9] */
/* @0xf1c34 add r5, r7, r6 */
/* @0xf1c38 ldr r3, [r5, #0xc] */
/* @0xf1c3c sub r3, r3, #1 */
/* @0xf1c40 bic r3, r3, #-16777216 */
/* @0xf1c44 bic r3, r3, #3 */
/* @0xf1c48 cmp r3, #0 */
/* @0xf1c4c bne 0xf1bf8 <_Z22FINALIZE_Code_Constantv+0x48> */
/* @0xf1c50 mov r0, r5 */
/* @0xf1c54 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xf1c58 b 0xf1bf8 <_Z22FINALIZE_Code_Constantv+0x48> */
/* @0xf1c5c ldr r9, [r3, r1] */
/* @0xf1c60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf1c64 ldr r0, [r9] */
/* @0xf1c68 mov r4, #0 */
/* @0xf1c6c str r4, [r8] */
/* @0xf1c70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf1c74 str r4, [r10] */
/* @0xf1c78 str r4, [r9] */
/* @0xf1c7c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf1c80 mlaseq r0, r4, r0, r0 */
/* @0xf1c84 .word 0xffffc178 */
/* @0xf1c88 .word 0xffffc174 */
/* @0xf1c8c .word 0xffffc17c */

/* ── FUNC 0xf1c90 · Code_Error::Create() · size=4 · insn=1 */
/* @0xf1c90 bx lr */

/* ── FUNC 0xf1c94 · Code_Error::Show() · size=20 · insn=5 */
/* @0xf1c94 push {r3, lr} */
/* @0xf1c98 ldr r0, [r0] */
/* @0xf1c9c bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0xf1ca0 mov r0, #1 */
/* @0xf1ca4 pop {r3, pc} */

/* ── FUNC 0xf1ca8 · DIALOG_REQ_CONTEXT::~DIALOG_REQ_CONTEXT() · size=116 · insn=29 */
/* @0xf1ca8 push {r4, lr} */
/* @0xf1cac mov r4, r0 */
/* @0xf1cb0 ldr r0, [r0, #0x48] */
/* @0xf1cb4 ldr r3, [pc, #0x5c] */
/* @0xf1cb8 cmp r0, #0 */
/* @0xf1cbc ldr r3, [pc, r3] */
/* @0xf1cc0 add r3, r3, #8 */
/* @0xf1cc4 str r3, [r4] */
/* @0xf1cc8 beq 0xf1cd8 <_ZN18DIALOG_REQ_CONTEXTD2Ev+0x30> */
/* @0xf1ccc bl 0xb655c <free@plt> */
/* @0xf1cd0 mov r3, #0 */
/* @0xf1cd4 str r3, [r4, #0x48] */
/* @0xf1cd8 ldr r0, [r4, #0x4c] */
/* @0xf1cdc cmp r0, #0 */
/* @0xf1ce0 beq 0xf1cf0 <_ZN18DIALOG_REQ_CONTEXTD2Ev+0x48> */
/* @0xf1ce4 bl 0xb655c <free@plt> */
/* @0xf1ce8 mov r3, #0 */
/* @0xf1cec str r3, [r4, #0x4c] */
/* @0xf1cf0 ldr r0, [r4, #0x50] */
/* @0xf1cf4 cmp r0, #0 */
/* @0xf1cf8 beq 0xf1d08 <_ZN18DIALOG_REQ_CONTEXTD2Ev+0x60> */
/* @0xf1cfc bl 0xb655c <free@plt> */
/* @0xf1d00 mov r3, #0 */
/* @0xf1d04 str r3, [r4, #0x50] */
/* @0xf1d08 mov r0, r4 */
/* @0xf1d0c bl 0x18d724 <_ZN16HTTP_REQ_CONTEXTD2Ev> */
/* @0xf1d10 mov r0, r4 */
/* @0xf1d14 pop {r4, pc} */
/* @0xf1d18 eoreq r12, pc, r4, lsr #2 */

/* ── FUNC 0xf1ca8 · DIALOG_REQ_CONTEXT::~DIALOG_REQ_CONTEXT() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf1d1c · DIALOG_REQ_CONTEXT::~DIALOG_REQ_CONTEXT() · size=124 · insn=31 */
/* @0xf1d1c push {r4, lr} */
/* @0xf1d20 mov r4, r0 */
/* @0xf1d24 ldr r0, [r0, #0x48] */
/* @0xf1d28 ldr r3, [pc, #0x64] */
/* @0xf1d2c cmp r0, #0 */
/* @0xf1d30 ldr r3, [pc, r3] */
/* @0xf1d34 add r3, r3, #8 */
/* @0xf1d38 str r3, [r4] */
/* @0xf1d3c beq 0xf1d4c <_ZN18DIALOG_REQ_CONTEXTD0Ev+0x30> */
/* @0xf1d40 bl 0xb655c <free@plt> */
/* @0xf1d44 mov r3, #0 */
/* @0xf1d48 str r3, [r4, #0x48] */
/* @0xf1d4c ldr r0, [r4, #0x4c] */
/* @0xf1d50 cmp r0, #0 */
/* @0xf1d54 beq 0xf1d64 <_ZN18DIALOG_REQ_CONTEXTD0Ev+0x48> */
/* @0xf1d58 bl 0xb655c <free@plt> */
/* @0xf1d5c mov r3, #0 */
/* @0xf1d60 str r3, [r4, #0x4c] */
/* @0xf1d64 ldr r0, [r4, #0x50] */
/* @0xf1d68 cmp r0, #0 */
/* @0xf1d6c beq 0xf1d7c <_ZN18DIALOG_REQ_CONTEXTD0Ev+0x60> */
/* @0xf1d70 bl 0xb655c <free@plt> */
/* @0xf1d74 mov r3, #0 */
/* @0xf1d78 str r3, [r4, #0x50] */
/* @0xf1d7c mov r0, r4 */
/* @0xf1d80 bl 0x18d724 <_ZN16HTTP_REQ_CONTEXTD2Ev> */
/* @0xf1d84 mov r0, r4 */
/* @0xf1d88 bl 0x27d1d0 <_ZdlPv> */
/* @0xf1d8c mov r0, r4 */
/* @0xf1d90 pop {r4, pc} */
/* @0xf1d94 strhteq r12, [pc], -r0 */

/* ── FUNC 0xf1d98 · RemoveDialogAndKick(HTTP_REQ_CONTEXT*) · size=228 · insn=57 */
/* @0xf1d98 ldr r3, [pc, #0xd8] */
/* @0xf1d9c ldr r3, [pc, r3] */
/* @0xf1da0 ldr r12, [r3] */
/* @0xf1da4 cmp r12, #0 */
/* @0xf1da8 bxeq lr */
/* @0xf1dac ldr r2, [r12, #0x24] */
/* @0xf1db0 ldr r0, [r0, #0x24] */
/* @0xf1db4 cmp r2, r0 */
/* @0xf1db8 movne r2, r12 */
/* @0xf1dbc bne 0xf1dd4 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x3c> */
/* @0xf1dc0 b 0xf1e64 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0xcc> */
/* @0xf1dc4 ldr r1, [r3, #0x24] */
/* @0xf1dc8 cmp r1, r0 */
/* @0xf1dcc beq 0xf1e14 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x7c> */
/* @0xf1dd0 mov r2, r3 */
/* @0xf1dd4 ldr r3, [r2, #0x44] */
/* @0xf1dd8 cmp r3, #0 */
/* @0xf1ddc bne 0xf1dc4 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x2c> */
/* @0xf1de0 b 0xf1de8 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x50> */
/* @0xf1de4 mov r12, r3 */
/* @0xf1de8 ldr r3, [r12, #0x44] */
/* @0xf1dec cmp r3, #0 */
/* @0xf1df0 bne 0xf1de4 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x4c> */
/* @0xf1df4 ldr r3, [r12, #0x54] */
/* @0xf1df8 cmp r3, #3 */
/* @0xf1dfc addls pc, pc, r3, lsl #2 */
/* @0xf1e00 b 0xf1e20 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x88> */
/* @0xf1e04 b 0xf1e34 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x9c> */
/* @0xf1e08 b 0xf1e44 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0xac> */
/* @0xf1e0c b 0xf1e54 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0xbc> */
/* @0xf1e10 b 0xf1e24 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x8c> */
/* @0xf1e14 ldr r3, [r3, #0x44] */
/* @0xf1e18 str r3, [r2, #0x44] */
/* @0xf1e1c b 0xf1de8 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x50> */
/* @0xf1e20 bx lr */
/* @0xf1e24 ldr r0, [r12, #0x48] */
/* @0xf1e28 ldr r1, [r12, #0x4c] */
/* @0xf1e2c ldr r2, [r12, #0x24] */
/* @0xf1e30 b 0xf2ad0 <loginDialogAsync> */
/* @0xf1e34 add r0, r12, #72 */
/* @0xf1e38 ldr r3, [r12, #0x24] */
/* @0xf1e3c ldm r0, {r0, r1, r2} */
/* @0xf1e40 b 0xf29f4 <inputDialogAsync> */
/* @0xf1e44 ldr r0, [r12, #0x48] */
/* @0xf1e48 ldr r1, [r12, #0x4c] */
/* @0xf1e4c ldr r2, [r12, #0x24] */
/* @0xf1e50 b 0xf2a70 <questionDialogAsync> */
/* @0xf1e54 ldr r0, [r12, #0x48] */
/* @0xf1e58 ldr r1, [r12, #0x4c] */
/* @0xf1e5c ldr r2, [r12, #0x24] */
/* @0xf1e60 b 0xf2b4c <showMessage> */
/* @0xf1e64 ldr r12, [r12, #0x44] */
/* @0xf1e68 cmp r12, #0 */
/* @0xf1e6c str r12, [r3] */
/* @0xf1e70 bxeq lr */
/* @0xf1e74 b 0xf1de8 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT+0x50> */
/* @0xf1e78 eoreq r12, pc, r8, asr #32 */

/* ── FUNC 0xf1e7c · InputDialogASync(HTTP_REQ_CONTEXT*, void*, int*) · size=252 · insn=63 */
/* @0xf1e7c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xf1e80 vpush {d8} */
/* @0xf1e84 mov r6, r0 */
/* @0xf1e88 ldr r1, [pc, #0xd4] */
/* @0xf1e8c sub sp, sp, #56 */
/* @0xf1e90 ldr r0, [r0, #0x3c] */
/* @0xf1e94 mov r3, #1 */
/* @0xf1e98 mov r9, r2 */
/* @0xf1e9c add r1, pc, r1 */
/* @0xf1ea0 add r0, r0, r3 */
/* @0xf1ea4 mov r2, #130 */
/* @0xf1ea8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf1eac ldr r2, [r6, #0x3c] */
/* @0xf1eb0 ldr r1, [r6, #0x34] */
/* @0xf1eb4 mov r7, #0 */
/* @0xf1eb8 ldr r10, [pc, #0xa8] */
/* @0xf1ebc mov r4, #0 */
/* @0xf1ec0 mov r5, #0 */
/* @0xf1ec4 add r10, pc, r10 */
/* @0xf1ec8 mov r8, r0 */
/* @0xf1ecc bl 0xb65bc <memcpy@plt> */
/* @0xf1ed0 ldr r3, [r6, #0x3c] */
/* @0xf1ed4 mov r0, r8 */
/* @0xf1ed8 mov r1, r7 */
/* @0xf1edc strb r7, [r8, r3] */
/* @0xf1ee0 vldr s15, [r6, #36] */
/* @0xf1ee4 vcvt.f64.s32 d8, s15 */
/* @0xf1ee8 bl 0xb6658 <strtod@plt> */
/* @0xf1eec vldr s14, [r6, #40] */
/* @0xf1ef0 ldr lr, [pc, #0x74] */
/* @0xf1ef4 ldr r12, [pc, #0x74] */
/* @0xf1ef8 add lr, pc, lr */
/* @0xf1efc strd r4, r5, [sp, #8] */
/* @0xf1f00 add r12, pc, r12 */
/* @0xf1f04 str lr, [sp, #0x14] */
/* @0xf1f08 str r12, [sp, #0x24] */
/* @0xf1f0c str r7, [sp] */
/* @0xf1f10 vcvt.f64.s32 d7, s14 */
/* @0xf1f14 str r8, [sp, #0x10] */
/* @0xf1f18 vmov r2, r3, d8 */
/* @0xf1f1c str r7, [sp, #0x20] */
/* @0xf1f20 str r7, [sp, #0x30] */
/* @0xf1f24 str r10, [sp, #0x4] */
/* @0xf1f28 vstr d7, [sp, #40] */
/* @0xf1f2c strd r0, r1, [sp, #24] */
/* @0xf1f30 mov r0, #4 */
/* @0xf1f34 ldr r1, [pc, #0x38] */
/* @0xf1f38 add r1, pc, r1 */
/* @0xf1f3c bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0xf1f40 str r0, [r9] */
/* @0xf1f44 mov r0, r8 */
/* @0xf1f48 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf1f4c mov r0, r6 */
/* @0xf1f50 bl 0xf1d98 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT> */
/* @0xf1f54 mov r0, #63 */
/* @0xf1f58 add sp, sp, #56 */
/* @0xf1f5c vpop {d8} */
/* @0xf1f60 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xf1f64 eoreq r5, r4, r8, lsl #1 */
/* @0xf1f68 mlaeq r4, r4, r0, r5 */
/* @0xf1f6c eoreq r5, r4, r8, rrx */
/* @0xf1f70 eoreq lr, r3, r0, asr r11 */
/* @0xf1f74 eoreq lr, r3, r8, lsl #22 */

/* ── FUNC 0xf1f78 · QuestionDialogASync(HTTP_REQ_CONTEXT*, void*, int*) · size=252 · insn=63 */
/* @0xf1f78 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xf1f7c vpush {d8} */
/* @0xf1f80 mov r6, r0 */
/* @0xf1f84 ldr r1, [pc, #0xd4] */
/* @0xf1f88 sub sp, sp, #56 */
/* @0xf1f8c ldr r0, [r0, #0x3c] */
/* @0xf1f90 mov r3, #1 */
/* @0xf1f94 mov r9, r2 */
/* @0xf1f98 add r1, pc, r1 */
/* @0xf1f9c add r0, r0, r3 */
/* @0xf1fa0 mov r2, #148 */
/* @0xf1fa4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf1fa8 ldr r2, [r6, #0x3c] */
/* @0xf1fac ldr r1, [r6, #0x34] */
/* @0xf1fb0 mov r7, #0 */
/* @0xf1fb4 ldr r10, [pc, #0xa8] */
/* @0xf1fb8 mov r4, #0 */
/* @0xf1fbc mov r5, #0 */
/* @0xf1fc0 add r10, pc, r10 */
/* @0xf1fc4 mov r8, r0 */
/* @0xf1fc8 bl 0xb65bc <memcpy@plt> */
/* @0xf1fcc ldr r3, [r6, #0x3c] */
/* @0xf1fd0 mov r0, r8 */
/* @0xf1fd4 mov r1, r7 */
/* @0xf1fd8 strb r7, [r8, r3] */
/* @0xf1fdc vldr s15, [r6, #36] */
/* @0xf1fe0 vcvt.f64.s32 d8, s15 */
/* @0xf1fe4 bl 0xb6658 <strtod@plt> */
/* @0xf1fe8 vldr s14, [r6, #40] */
/* @0xf1fec ldr lr, [pc, #0x74] */
/* @0xf1ff0 ldr r12, [pc, #0x74] */
/* @0xf1ff4 add lr, pc, lr */
/* @0xf1ff8 strd r4, r5, [sp, #8] */
/* @0xf1ffc add r12, pc, r12 */
/* @0xf2000 str lr, [sp, #0x14] */
/* @0xf2004 str r12, [sp, #0x24] */
/* @0xf2008 str r7, [sp] */
/* @0xf200c vcvt.f64.s32 d7, s14 */
/* @0xf2010 str r8, [sp, #0x10] */
/* @0xf2014 vmov r2, r3, d8 */
/* @0xf2018 str r7, [sp, #0x20] */
/* @0xf201c str r7, [sp, #0x30] */
/* @0xf2020 str r10, [sp, #0x4] */
/* @0xf2024 vstr d7, [sp, #40] */
/* @0xf2028 strd r0, r1, [sp, #24] */
/* @0xf202c mov r0, #4 */
/* @0xf2030 ldr r1, [pc, #0x38] */
/* @0xf2034 add r1, pc, r1 */
/* @0xf2038 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0xf203c str r0, [r9] */
/* @0xf2040 mov r0, r8 */
/* @0xf2044 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf2048 mov r0, r6 */
/* @0xf204c bl 0xf1d98 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT> */
/* @0xf2050 mov r0, #63 */
/* @0xf2054 add sp, sp, #56 */
/* @0xf2058 vpop {d8} */
/* @0xf205c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xf2060 eoreq r4, r4, r12, lsl #31 */
/* @0xf2064 mlaeq r4, r8, pc, r4 */
/* @0xf2068 eoreq r4, r4, r12, ror #30 */
/* @0xf206c eoreq lr, r3, r4, asr r10 */
/* @0xf2070 eoreq lr, r3, r12, lsl #20 */

/* ── FUNC 0xf2074 · LoginDialogASync(HTTP_REQ_CONTEXT*, void*, int*) · size=300 · insn=75 */
/* @0xf2074 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xf2078 mov r6, r0 */
/* @0xf207c ldr r5, [pc, #0x108] */
/* @0xf2080 sub sp, sp, #60 */
/* @0xf2084 ldr r0, [r0, #0x3c] */
/* @0xf2088 mov r3, #1 */
/* @0xf208c add r5, pc, r5 */
/* @0xf2090 mov r9, r2 */
/* @0xf2094 add r0, r0, r3 */
/* @0xf2098 mov r2, #167 */
/* @0xf209c mov r1, r5 */
/* @0xf20a0 mov r8, #0 */
/* @0xf20a4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf20a8 ldr r1, [r6, #0x34] */
/* @0xf20ac ldr r2, [r6, #0x3c] */
/* @0xf20b0 mov r7, r0 */
/* @0xf20b4 bl 0xb65bc <memcpy@plt> */
/* @0xf20b8 ldr r3, [r6, #0x3c] */
/* @0xf20bc mov r0, r7 */
/* @0xf20c0 strb r8, [r7, r3] */
/* @0xf20c4 bl 0xb6538 <strlen@plt> */
/* @0xf20c8 ldr r3, [r6, #0x34] */
/* @0xf20cc add r0, r0, #1 */
/* @0xf20d0 add r4, r3, r0 */
/* @0xf20d4 mov r0, r4 */
/* @0xf20d8 bl 0xb6538 <strlen@plt> */
/* @0xf20dc mov r3, #1 */
/* @0xf20e0 mov r1, r5 */
/* @0xf20e4 mov r2, #173 */
/* @0xf20e8 mov r5, #0 */
/* @0xf20ec add r0, r0, r3 */
/* @0xf20f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf20f4 mov r1, r4 */
/* @0xf20f8 bl 0xb65a4 <strcpy@plt> */
/* @0xf20fc vldr s14, [r6, #40] */
/* @0xf2100 vcvt.f64.s32 d7, s14 */
/* @0xf2104 ldr r2, [r6, #0x24] */
/* @0xf2108 ldr r1, [pc, #0x80] */
/* @0xf210c mov r4, #0 */
/* @0xf2110 ldr lr, [pc, #0x7c] */
/* @0xf2114 add r1, pc, r1 */
/* @0xf2118 ldr r12, [pc, #0x78] */
/* @0xf211c str r1, [sp, #0x24] */
/* @0xf2120 add lr, pc, lr */
/* @0xf2124 ldr r1, [pc, #0x70] */
/* @0xf2128 add r12, pc, r12 */
/* @0xf212c str lr, [sp, #0x4] */
/* @0xf2130 vstr d7, [sp, #40] */
/* @0xf2134 vmov s15, r2 */
/* @0xf2138 str r12, [sp, #0x14] */
/* @0xf213c add r1, pc, r1 */
/* @0xf2140 vcvt.f64.s32 d7, s15 */
/* @0xf2144 strd r4, r5, [sp, #8] */
/* @0xf2148 strd r4, r5, [sp, #24] */
/* @0xf214c str r8, [sp] */
/* @0xf2150 str r7, [sp, #0x10] */
/* @0xf2154 str r8, [sp, #0x30] */
/* @0xf2158 mov r3, r0 */
/* @0xf215c mov r0, #4 */
/* @0xf2160 str r3, [sp, #0x20] */
/* @0xf2164 vmov r2, r3, d7 */
/* @0xf2168 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0xf216c str r0, [r9] */
/* @0xf2170 mov r0, r7 */
/* @0xf2174 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf2178 mov r0, r6 */
/* @0xf217c bl 0xf1d98 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT> */
/* @0xf2180 mov r0, #63 */
/* @0xf2184 add sp, sp, #60 */
/* @0xf2188 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xf218c mlaeq r4, r8, lr, r4 */
/* @0xf2190 eoreq lr, r3, r12, lsr r9 */
/* @0xf2194 eoreq r4, r4, r8, asr #28 */
/* @0xf2198 eoreq r4, r4, r12, asr #28 */
/* @0xf219c eoreq lr, r3, r4, lsl #18 */

/* ── FUNC 0xf21a0 · MessageDialogASync(HTTP_REQ_CONTEXT*, void*, int*) · size=116 · insn=29 */
/* @0xf21a0 vldr s14, [r0, #40] */
/* @0xf21a4 vcvt.f64.s32 d7, s14 */
/* @0xf21a8 push {r4, r5, lr} */
/* @0xf21ac mov r5, r2 */
/* @0xf21b0 ldr r2, [r0, #0x24] */
/* @0xf21b4 sub sp, sp, #28 */
/* @0xf21b8 ldr r1, [pc, #0x4c] */
/* @0xf21bc mov r4, r0 */
/* @0xf21c0 mov r3, #0 */
/* @0xf21c4 mov r0, #2 */
/* @0xf21c8 add r1, pc, r1 */
/* @0xf21cc str r1, [sp, #0x4] */
/* @0xf21d0 vstr d7, [sp, #8] */
/* @0xf21d4 vmov s15, r2 */
/* @0xf21d8 ldr r1, [pc, #0x30] */
/* @0xf21dc vcvt.f64.s32 d7, s15 */
/* @0xf21e0 str r3, [sp] */
/* @0xf21e4 str r3, [sp, #0x10] */
/* @0xf21e8 add r1, pc, r1 */
/* @0xf21ec vmov r2, r3, d7 */
/* @0xf21f0 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0xf21f4 str r0, [r5] */
/* @0xf21f8 mov r0, r4 */
/* @0xf21fc bl 0xf1d98 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT> */
/* @0xf2200 mov r0, #63 */
/* @0xf2204 add sp, sp, #28 */
/* @0xf2208 pop {r4, r5, pc} */
/* @0xf220c eoreq lr, r3, r8, lsl #17 */
/* @0xf2210 eoreq lr, r3, r8, asr r8 */

/* ── FUNC 0xf2214 · DIALOG_REQ_CONTEXT::AddInputDialog(char const*, char const*, char const*) · size=316 · insn=79 */
/* @0xf2214 push {r4, r5, r6, r7, lr} */
/* @0xf2218 mov r7, r0 */
/* @0xf221c sub sp, sp, #20 */
/* @0xf2220 mov r0, #88 */
/* @0xf2224 mov r6, r1 */
/* @0xf2228 mov r5, r2 */
/* @0xf222c bl 0x27c524 <_Znwj> */
/* @0xf2230 ldr r3, [pc, #0x10c] */
/* @0xf2234 mov r12, #0 */
/* @0xf2238 str r12, [sp] */
/* @0xf223c ldr r3, [pc, r3] */
/* @0xf2240 mov r1, r12 */
/* @0xf2244 str r12, [sp, #0x4] */
/* @0xf2248 mov r2, r12 */
/* @0xf224c str r12, [sp, #0x8] */
/* @0xf2250 mov r4, r0 */
/* @0xf2254 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0xf2258 ldr r3, [pc, #0xe8] */
/* @0xf225c subs r0, r7, #0 */
/* @0xf2260 ldr r3, [pc, r3] */
/* @0xf2264 add r3, r3, #8 */
/* @0xf2268 str r3, [r4] */
/* @0xf226c beq 0xf2274 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0x60> */
/* @0xf2270 bl 0xb6640 <strdup@plt> */
/* @0xf2274 cmp r6, #0 */
/* @0xf2278 str r0, [r4, #0x48] */
/* @0xf227c mov r0, r6 */
/* @0xf2280 beq 0xf2288 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0x74> */
/* @0xf2284 bl 0xb6640 <strdup@plt> */
/* @0xf2288 cmp r5, #0 */
/* @0xf228c str r0, [r4, #0x4c] */
/* @0xf2290 mov r0, r5 */
/* @0xf2294 beq 0xf229c <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0x88> */
/* @0xf2298 bl 0xb6640 <strdup@plt> */
/* @0xf229c ldr r1, [pc, #0xa8] */
/* @0xf22a0 mov r3, #1 */
/* @0xf22a4 str r3, [r4, #0x30] */
/* @0xf22a8 mov r2, #0 */
/* @0xf22ac ldr r1, [pc, r1] */
/* @0xf22b0 str r0, [r4, #0x50] */
/* @0xf22b4 str r2, [r4, #0x54] */
/* @0xf22b8 ldr r3, [r1] */
/* @0xf22bc str r4, [r1] */
/* @0xf22c0 cmp r3, r2 */
/* @0xf22c4 str r3, [r4, #0x44] */
/* @0xf22c8 beq 0xf22d8 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xc4> */
/* @0xf22cc ldr r0, [r4, #0x24] */
/* @0xf22d0 add sp, sp, #20 */
/* @0xf22d4 pop {r4, r5, r6, r7, pc} */
/* @0xf22d8 cmp r3, #3 */
/* @0xf22dc addls pc, pc, r3, lsl #2 */
/* @0xf22e0 b 0xf22cc <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xb8> */
/* @0xf22e4 b 0xf2330 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0x11c> */
/* @0xf22e8 b 0xf231c <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0x108> */
/* @0xf22ec b 0xf2308 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xf4> */
/* @0xf22f0 b 0xf22f4 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xe0> */
/* @0xf22f4 ldr r0, [r4, #0x48] */
/* @0xf22f8 ldr r1, [r4, #0x4c] */
/* @0xf22fc ldr r2, [r4, #0x24] */
/* @0xf2300 bl 0xf2ad0 <loginDialogAsync> */
/* @0xf2304 b 0xf22cc <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xb8> */
/* @0xf2308 ldr r0, [r4, #0x48] */
/* @0xf230c ldr r1, [r4, #0x4c] */
/* @0xf2310 ldr r2, [r4, #0x24] */
/* @0xf2314 bl 0xf2b4c <showMessage> */
/* @0xf2318 b 0xf22cc <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xb8> */
/* @0xf231c ldr r0, [r4, #0x48] */
/* @0xf2320 ldr r1, [r4, #0x4c] */
/* @0xf2324 ldr r2, [r4, #0x24] */
/* @0xf2328 bl 0xf2a70 <questionDialogAsync> */
/* @0xf232c b 0xf22cc <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xb8> */
/* @0xf2330 add r0, r4, #72 */
/* @0xf2334 ldr r3, [r4, #0x24] */
/* @0xf2338 ldm r0, {r0, r1, r2} */
/* @0xf233c bl 0xf29f4 <inputDialogAsync> */
/* @0xf2340 b 0xf22cc <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_+0xb8> */
/* @0xf2344 eoreq r11, pc, r12, lsr #23 */
/* @0xf2348 eoreq r11, pc, r0, lsl #23 */
/* @0xf234c eoreq r11, pc, r8, lsr r11 */

/* ── FUNC 0xf2350 · DIALOG_REQ_CONTEXT::AddQuestionDialog(char const*, char const*) · size=292 · insn=73 */
/* @0xf2350 push {r4, r5, r6, lr} */
/* @0xf2354 mov r6, r0 */
/* @0xf2358 sub sp, sp, #16 */
/* @0xf235c mov r0, #88 */
/* @0xf2360 mov r5, r1 */
/* @0xf2364 bl 0x27c524 <_Znwj> */
/* @0xf2368 ldr r3, [pc, #0xf8] */
/* @0xf236c mov r2, #0 */
/* @0xf2370 mov r1, r2 */
/* @0xf2374 str r2, [sp] */
/* @0xf2378 ldr r3, [pc, r3] */
/* @0xf237c str r2, [sp, #0x4] */
/* @0xf2380 str r2, [sp, #0x8] */
/* @0xf2384 mov r4, r0 */
/* @0xf2388 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0xf238c ldr r3, [pc, #0xd8] */
/* @0xf2390 subs r0, r6, #0 */
/* @0xf2394 ldr r3, [pc, r3] */
/* @0xf2398 add r3, r3, #8 */
/* @0xf239c str r3, [r4] */
/* @0xf23a0 beq 0xf23a8 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0x58> */
/* @0xf23a4 bl 0xb6640 <strdup@plt> */
/* @0xf23a8 cmp r5, #0 */
/* @0xf23ac str r0, [r4, #0x48] */
/* @0xf23b0 mov r0, r5 */
/* @0xf23b4 beq 0xf23bc <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0x6c> */
/* @0xf23b8 bl 0xb6640 <strdup@plt> */
/* @0xf23bc ldr r2, [pc, #0xac] */
/* @0xf23c0 mov r1, #0 */
/* @0xf23c4 str r1, [r4, #0x50] */
/* @0xf23c8 mov r3, #1 */
/* @0xf23cc ldr r2, [pc, r2] */
/* @0xf23d0 str r0, [r4, #0x4c] */
/* @0xf23d4 str r3, [r4, #0x54] */
/* @0xf23d8 ldr r1, [r2] */
/* @0xf23dc str r3, [r4, #0x30] */
/* @0xf23e0 cmp r1, #0 */
/* @0xf23e4 str r4, [r2] */
/* @0xf23e8 str r1, [r4, #0x44] */
/* @0xf23ec beq 0xf23fc <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xac> */
/* @0xf23f0 ldr r0, [r4, #0x24] */
/* @0xf23f4 add sp, sp, #16 */
/* @0xf23f8 pop {r4, r5, r6, pc} */
/* @0xf23fc cmp r3, #3 */
/* @0xf2400 addls pc, pc, r3, lsl #2 */
/* @0xf2404 b 0xf23f0 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xa0> */
/* @0xf2408 b 0xf2454 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0x104> */
/* @0xf240c b 0xf2440 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xf0> */
/* @0xf2410 b 0xf242c <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xdc> */
/* @0xf2414 b 0xf2418 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xc8> */
/* @0xf2418 ldr r0, [r4, #0x48] */
/* @0xf241c ldr r1, [r4, #0x4c] */
/* @0xf2420 ldr r2, [r4, #0x24] */
/* @0xf2424 bl 0xf2ad0 <loginDialogAsync> */
/* @0xf2428 b 0xf23f0 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xa0> */
/* @0xf242c ldr r0, [r4, #0x48] */
/* @0xf2430 ldr r1, [r4, #0x4c] */
/* @0xf2434 ldr r2, [r4, #0x24] */
/* @0xf2438 bl 0xf2b4c <showMessage> */
/* @0xf243c b 0xf23f0 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xa0> */
/* @0xf2440 ldr r0, [r4, #0x48] */
/* @0xf2444 ldr r1, [r4, #0x4c] */
/* @0xf2448 ldr r2, [r4, #0x24] */
/* @0xf244c bl 0xf2a70 <questionDialogAsync> */
/* @0xf2450 b 0xf23f0 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xa0> */
/* @0xf2454 add r0, r4, #72 */
/* @0xf2458 ldr r3, [r4, #0x24] */
/* @0xf245c ldm r0, {r0, r1, r2} */
/* @0xf2460 bl 0xf29f4 <inputDialogAsync> */
/* @0xf2464 b 0xf23f0 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xa0> */
/* @0xf2468 eoreq r11, pc, r4, ror r10 */
/* @0xf246c eoreq r11, pc, r12, asr #20 */
/* @0xf2470 eoreq r11, pc, r8, lsl r10 */

/* ── FUNC 0xf2474 · DIALOG_REQ_CONTEXT::AddLoginDialog(char const*, char const*) · size=296 · insn=74 */
/* @0xf2474 push {r4, r5, r6, lr} */
/* @0xf2478 mov r6, r0 */
/* @0xf247c sub sp, sp, #16 */
/* @0xf2480 mov r0, #88 */
/* @0xf2484 mov r5, r1 */
/* @0xf2488 bl 0x27c524 <_Znwj> */
/* @0xf248c ldr r3, [pc, #0xfc] */
/* @0xf2490 mov r2, #0 */
/* @0xf2494 mov r1, r2 */
/* @0xf2498 str r2, [sp] */
/* @0xf249c ldr r3, [pc, r3] */
/* @0xf24a0 str r2, [sp, #0x4] */
/* @0xf24a4 str r2, [sp, #0x8] */
/* @0xf24a8 mov r4, r0 */
/* @0xf24ac bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0xf24b0 ldr r3, [pc, #0xdc] */
/* @0xf24b4 subs r0, r6, #0 */
/* @0xf24b8 ldr r3, [pc, r3] */
/* @0xf24bc add r3, r3, #8 */
/* @0xf24c0 str r3, [r4] */
/* @0xf24c4 beq 0xf24cc <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0x58> */
/* @0xf24c8 bl 0xb6640 <strdup@plt> */
/* @0xf24cc cmp r5, #0 */
/* @0xf24d0 str r0, [r4, #0x48] */
/* @0xf24d4 mov r0, r5 */
/* @0xf24d8 beq 0xf24e0 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0x6c> */
/* @0xf24dc bl 0xb6640 <strdup@plt> */
/* @0xf24e0 ldr r3, [pc, #0xb0] */
/* @0xf24e4 mov r1, #0 */
/* @0xf24e8 str r1, [r4, #0x50] */
/* @0xf24ec mov r2, #3 */
/* @0xf24f0 ldr r3, [pc, r3] */
/* @0xf24f4 str r0, [r4, #0x4c] */
/* @0xf24f8 str r2, [r4, #0x54] */
/* @0xf24fc mov r0, #1 */
/* @0xf2500 ldr r1, [r3] */
/* @0xf2504 str r0, [r4, #0x30] */
/* @0xf2508 cmp r1, #0 */
/* @0xf250c str r4, [r3] */
/* @0xf2510 str r1, [r4, #0x44] */
/* @0xf2514 beq 0xf2524 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xb0> */
/* @0xf2518 ldr r0, [r4, #0x24] */
/* @0xf251c add sp, sp, #16 */
/* @0xf2520 pop {r4, r5, r6, pc} */
/* @0xf2524 cmp r2, r2 */
/* @0xf2528 addls pc, pc, r2, lsl #2 */
/* @0xf252c b 0xf2518 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xa4> */
/* @0xf2530 b 0xf257c <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0x108> */
/* @0xf2534 b 0xf2568 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xf4> */
/* @0xf2538 b 0xf2554 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xe0> */
/* @0xf253c b 0xf2540 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xcc> */
/* @0xf2540 ldr r0, [r4, #0x48] */
/* @0xf2544 ldr r1, [r4, #0x4c] */
/* @0xf2548 ldr r2, [r4, #0x24] */
/* @0xf254c bl 0xf2ad0 <loginDialogAsync> */
/* @0xf2550 b 0xf2518 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xa4> */
/* @0xf2554 ldr r0, [r4, #0x48] */
/* @0xf2558 ldr r1, [r4, #0x4c] */
/* @0xf255c ldr r2, [r4, #0x24] */
/* @0xf2560 bl 0xf2b4c <showMessage> */
/* @0xf2564 b 0xf2518 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xa4> */
/* @0xf2568 ldr r0, [r4, #0x48] */
/* @0xf256c ldr r1, [r4, #0x4c] */
/* @0xf2570 ldr r2, [r4, #0x24] */
/* @0xf2574 bl 0xf2a70 <questionDialogAsync> */
/* @0xf2578 b 0xf2518 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xa4> */
/* @0xf257c add r0, r4, #72 */
/* @0xf2580 ldr r3, [r4, #0x24] */
/* @0xf2584 ldm r0, {r0, r1, r2} */
/* @0xf2588 bl 0xf29f4 <inputDialogAsync> */
/* @0xf258c b 0xf2518 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xa4> */
/* @0xf2590 eoreq r11, pc, r4, asr r9 */
/* @0xf2594 eoreq r11, pc, r8, lsr #18 */
/* @0xf2598 .word 0x002fb8f4 */

/* ── FUNC 0xf259c · DIALOG_REQ_CONTEXT::AddMessageDialog(char const*, char const*) · size=296 · insn=74 */
/* @0xf259c push {r4, r5, r6, lr} */
/* @0xf25a0 mov r6, r0 */
/* @0xf25a4 sub sp, sp, #16 */
/* @0xf25a8 mov r0, #88 */
/* @0xf25ac mov r5, r1 */
/* @0xf25b0 bl 0x27c524 <_Znwj> */
/* @0xf25b4 ldr r3, [pc, #0xfc] */
/* @0xf25b8 mov r2, #0 */
/* @0xf25bc mov r1, r2 */
/* @0xf25c0 str r2, [sp] */
/* @0xf25c4 ldr r3, [pc, r3] */
/* @0xf25c8 str r2, [sp, #0x4] */
/* @0xf25cc str r2, [sp, #0x8] */
/* @0xf25d0 mov r4, r0 */
/* @0xf25d4 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0xf25d8 ldr r3, [pc, #0xdc] */
/* @0xf25dc subs r0, r6, #0 */
/* @0xf25e0 ldr r3, [pc, r3] */
/* @0xf25e4 add r3, r3, #8 */
/* @0xf25e8 str r3, [r4] */
/* @0xf25ec beq 0xf25f4 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0x58> */
/* @0xf25f0 bl 0xb6640 <strdup@plt> */
/* @0xf25f4 cmp r5, #0 */
/* @0xf25f8 str r0, [r4, #0x48] */
/* @0xf25fc mov r0, r5 */
/* @0xf2600 beq 0xf2608 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0x6c> */
/* @0xf2604 bl 0xb6640 <strdup@plt> */
/* @0xf2608 ldr r3, [pc, #0xb0] */
/* @0xf260c mov r1, #0 */
/* @0xf2610 str r1, [r4, #0x50] */
/* @0xf2614 mov r2, #2 */
/* @0xf2618 ldr r3, [pc, r3] */
/* @0xf261c str r0, [r4, #0x4c] */
/* @0xf2620 str r2, [r4, #0x54] */
/* @0xf2624 mov r0, #1 */
/* @0xf2628 ldr r1, [r3] */
/* @0xf262c str r0, [r4, #0x30] */
/* @0xf2630 cmp r1, #0 */
/* @0xf2634 str r4, [r3] */
/* @0xf2638 str r1, [r4, #0x44] */
/* @0xf263c beq 0xf264c <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xb0> */
/* @0xf2640 ldr r0, [r4, #0x24] */
/* @0xf2644 add sp, sp, #16 */
/* @0xf2648 pop {r4, r5, r6, pc} */
/* @0xf264c cmp r2, #3 */
/* @0xf2650 addls pc, pc, r2, lsl #2 */
/* @0xf2654 b 0xf2640 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xa4> */
/* @0xf2658 b 0xf26a4 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0x108> */
/* @0xf265c b 0xf2690 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xf4> */
/* @0xf2660 b 0xf267c <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xe0> */
/* @0xf2664 b 0xf2668 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xcc> */
/* @0xf2668 ldr r0, [r4, #0x48] */
/* @0xf266c ldr r1, [r4, #0x4c] */
/* @0xf2670 ldr r2, [r4, #0x24] */
/* @0xf2674 bl 0xf2ad0 <loginDialogAsync> */
/* @0xf2678 b 0xf2640 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xa4> */
/* @0xf267c ldr r0, [r4, #0x48] */
/* @0xf2680 ldr r1, [r4, #0x4c] */
/* @0xf2684 ldr r2, [r4, #0x24] */
/* @0xf2688 bl 0xf2b4c <showMessage> */
/* @0xf268c b 0xf2640 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xa4> */
/* @0xf2690 ldr r0, [r4, #0x48] */
/* @0xf2694 ldr r1, [r4, #0x4c] */
/* @0xf2698 ldr r2, [r4, #0x24] */
/* @0xf269c bl 0xf2a70 <questionDialogAsync> */
/* @0xf26a0 b 0xf2640 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xa4> */
/* @0xf26a4 add r0, r4, #72 */
/* @0xf26a8 ldr r3, [r4, #0x24] */
/* @0xf26ac ldm r0, {r0, r1, r2} */
/* @0xf26b0 bl 0xf29f4 <inputDialogAsync> */
/* @0xf26b4 b 0xf2640 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xa4> */
/* @0xf26b8 eoreq r11, pc, r0, lsr r8 */
/* @0xf26bc eoreq r11, pc, r0, lsl #16 */
/* @0xf26c0 eoreq r11, pc, r12, asr #15 */

/* ── FUNC 0xf26c4 · InputQuery::InputAsync(char const*, char const*, char const*) · size=40 · insn=10 */
/* @0xf26c4 push {r4, r5, r6, lr} */
/* @0xf26c8 mov r6, r0 */
/* @0xf26cc mov r5, r1 */
/* @0xf26d0 mov r4, r2 */
/* @0xf26d4 bl 0x17df38 <_Z14ExitFullScreenv> */
/* @0xf26d8 mov r0, r6 */
/* @0xf26dc mov r1, r5 */
/* @0xf26e0 mov r2, r4 */
/* @0xf26e4 pop {r4, r5, r6, lr} */
/* @0xf26e8 b 0xf2214 <_ZN18DIALOG_REQ_CONTEXT14AddInputDialogEPKcS1_S1_> */

/* ── FUNC 0xf26ec · InputQuery::QuestionAsync(char const*, char const*) · size=32 · insn=8 */
/* @0xf26ec push {r3, r4, r5, lr} */
/* @0xf26f0 mov r5, r0 */
/* @0xf26f4 mov r4, r1 */
/* @0xf26f8 bl 0x17df38 <_Z14ExitFullScreenv> */
/* @0xf26fc mov r0, r5 */
/* @0xf2700 mov r1, r4 */
/* @0xf2704 pop {r3, r4, r5, lr} */
/* @0xf2708 b 0xf2350 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_> */

/* ── FUNC 0xf270c · InputQuery::ShowMessageASync(char const*, char const*) · size=32 · insn=8 */
/* @0xf270c push {r3, r4, r5, lr} */
/* @0xf2710 mov r5, r0 */
/* @0xf2714 mov r4, r1 */
/* @0xf2718 bl 0x17df38 <_Z14ExitFullScreenv> */
/* @0xf271c mov r0, r5 */
/* @0xf2720 mov r1, r4 */
/* @0xf2724 pop {r3, r4, r5, lr} */
/* @0xf2728 b 0xf259c <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_> */

/* ── FUNC 0xf272c · InputQuery::LoginASync(char const*, char const*) · size=32 · insn=8 */
/* @0xf272c push {r3, r4, r5, lr} */
/* @0xf2730 mov r5, r0 */
/* @0xf2734 mov r4, r1 */
/* @0xf2738 bl 0x17df38 <_Z14ExitFullScreenv> */
/* @0xf273c mov r0, r5 */
/* @0xf2740 mov r1, r4 */
/* @0xf2744 pop {r3, r4, r5, lr} */
/* @0xf2748 b 0xf2474 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_> */

/* ── FUNC 0xf274c · InputQuery::SetResult(int, int, char const*) · size=104 · insn=26 */
/* @0xf274c push {r3, r4, r5, lr} */
/* @0xf2750 mov r5, r2 */
/* @0xf2754 ldr r3, [pc, #0x54] */
/* @0xf2758 ldr r3, [pc, r3] */
/* @0xf275c ldr r4, [r3] */
/* @0xf2760 cmp r4, #0 */
/* @0xf2764 bne 0xf2778 <_ZN10InputQuery9SetResultEiiPKc+0x2c> */
/* @0xf2768 pop {r3, r4, r5, pc} */
/* @0xf276c ldr r4, [r4, #0x4] */
/* @0xf2770 cmp r4, #0 */
/* @0xf2774 beq 0xf27ac <_ZN10InputQuery9SetResultEiiPKc+0x60> */
/* @0xf2778 ldr r3, [r4, #0x24] */
/* @0xf277c cmp r3, r0 */
/* @0xf2780 bne 0xf276c <_ZN10InputQuery9SetResultEiiPKc+0x20> */
/* @0xf2784 mov r3, #7 */
/* @0xf2788 str r1, [r4, #0x28] */
/* @0xf278c mov r0, r5 */
/* @0xf2790 str r3, [r4, #0xc] */
/* @0xf2794 bl 0xb6538 <strlen@plt> */
/* @0xf2798 str r5, [r4, #0x34] */
/* @0xf279c add r0, r0, #1 */
/* @0xf27a0 str r0, [r4, #0x38] */
/* @0xf27a4 str r0, [r4, #0x3c] */
/* @0xf27a8 pop {r3, r4, r5, pc} */
/* @0xf27ac pop {r3, r4, r5, pc} */
/* @0xf27b0 eoreq r11, pc, r0, lsr #13 */
