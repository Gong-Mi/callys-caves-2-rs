/* libyoyo.so 覆盖卡组 0126
 * 函数 0x18de30..0x18ed9c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x18de30 · LoadSave::fseek(_YYFILE*, long, int) · size=76 · insn=19 */
/* @0x18de30 cmp r2, #1 */
/* @0x18de34 mov r3, r1 */
/* @0x18de38 push {r4, lr} */
/* @0x18de3c mov r4, r0 */
/* @0x18de40 beq 0x18de60 <_ZN8LoadSave5fseekEP7_YYFILEli+0x30> */
/* @0x18de44 cmp r2, #2 */
/* @0x18de48 beq 0x18de60 <_ZN8LoadSave5fseekEP7_YYFILEli+0x30> */
/* @0x18de4c cmp r2, #0 */
/* @0x18de50 beq 0x18de60 <_ZN8LoadSave5fseekEP7_YYFILEli+0x30> */
/* @0x18de54 ldr r3, [r4] */
/* @0x18de58 ldr r0, [r3, #0x1c] */
/* @0x18de5c pop {r4, pc} */
/* @0x18de60 ldr r0, [r4] */
/* @0x18de64 mov r1, r2 */
/* @0x18de68 mov r2, r3 */
/* @0x18de6c ldr r3, [r0] */
/* @0x18de70 ldr r3, [r3, #0x10] */
/* @0x18de74 blx r3 */
/* @0x18de78 b 0x18de54 <_ZN8LoadSave5fseekEP7_YYFILEli+0x24> */

/* ── FUNC 0x18de7c · LoadSave::yyfeof(_YYFILE*) · size=28 · insn=7 */
/* @0x18de7c ldr r3, [r0] */
/* @0x18de80 ldr r0, [r3, #0x1c] */
/* @0x18de84 ldr r3, [r3, #0x10] */
/* @0x18de88 cmp r0, r3 */
/* @0x18de8c movlt r0, #0 */
/* @0x18de90 movge r0, #1 */
/* @0x18de94 bx lr */

/* ── FUNC 0x18de98 · LoadSave::yyfeoln(_YYFILE*) · size=148 · insn=37 */
/* @0x18de98 push {r4, r5, r6, lr} */
/* @0x18de9c mov r5, r0 */
/* @0x18dea0 bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE> */
/* @0x18dea4 subs r4, r0, #0 */
/* @0x18dea8 beq 0x18deb4 <_ZN8LoadSave7yyfeolnEP7_YYFILE+0x1c> */
/* @0x18deac mov r0, #1 */
/* @0x18deb0 pop {r4, r5, r6, pc} */
/* @0x18deb4 ldr r0, [r5] */
/* @0x18deb8 mov r2, #1 */
/* @0x18debc add r6, r0, #44 */
/* @0x18dec0 ldr r12, [r0] */
/* @0x18dec4 ldr r1, [r0, #0x1c] */
/* @0x18dec8 mov r3, r6 */
/* @0x18decc ldr r12, [r12, #0x14] */
/* @0x18ded0 blx r12 */
/* @0x18ded4 mov r0, r6 */
/* @0x18ded8 mov r1, r4 */
/* @0x18dedc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18dee0 uxtb r0, r0 */
/* @0x18dee4 cmp r0, #13 */
/* @0x18dee8 beq 0x18deac <_ZN8LoadSave7yyfeolnEP7_YYFILE+0x14> */
/* @0x18deec ldr r0, [r5] */
/* @0x18def0 mov r2, #1 */
/* @0x18def4 add r5, r0, #44 */
/* @0x18def8 ldr r12, [r0] */
/* @0x18defc mov r3, r5 */
/* @0x18df00 ldr r1, [r0, #0x1c] */
/* @0x18df04 ldr r12, [r12, #0x14] */
/* @0x18df08 blx r12 */
/* @0x18df0c mov r0, r5 */
/* @0x18df10 mov r1, r4 */
/* @0x18df14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18df18 uxtb r0, r0 */
/* @0x18df1c subs r3, r0, #10 */
/* @0x18df20 rsbs r0, r3, #0 */
/* @0x18df24 adcs r0, r0, r3 */
/* @0x18df28 pop {r4, r5, r6, pc} */

/* ── FUNC 0x18df2c · LoadSave::fgetc(_YYFILE*) · size=92 · insn=23 */
/* @0x18df2c push {r3, r4, r5, lr} */
/* @0x18df30 mov r4, r0 */
/* @0x18df34 bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE> */
/* @0x18df38 mov r1, #1 */
/* @0x18df3c subs r5, r0, #0 */
/* @0x18df40 ldr r0, [r4] */
/* @0x18df44 beq 0x18df60 <_ZN8LoadSave5fgetcEP7_YYFILE+0x34> */
/* @0x18df48 ldr r3, [r0] */
/* @0x18df4c mov r2, r1 */
/* @0x18df50 ldr r3, [r3, #0x10] */
/* @0x18df54 blx r3 */
/* @0x18df58 mov r0, #255 */
/* @0x18df5c pop {r3, r4, r5, pc} */
/* @0x18df60 ldr r12, [r0] */
/* @0x18df64 add r4, r0, #44 */
/* @0x18df68 mov r2, r4 */
/* @0x18df6c ldr r3, [r12, #0xc] */
/* @0x18df70 blx r3 */
/* @0x18df74 mov r0, r4 */
/* @0x18df78 mov r1, r5 */
/* @0x18df7c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18df80 uxtb r0, r0 */
/* @0x18df84 pop {r3, r4, r5, pc} */

/* ── FUNC 0x18df88 · LoadSave::freadreal(_YYFILE*, double*) · size=232 · insn=58 */
/* @0x18df88 push {r4, r5, r6, r7, lr} */
/* @0x18df8c sub sp, sp, #12 */
/* @0x18df90 mov r4, r0 */
/* @0x18df94 mov r5, r1 */
/* @0x18df98 mov r0, r4 */
/* @0x18df9c bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE> */
/* @0x18dfa0 subs r6, r0, #0 */
/* @0x18dfa4 beq 0x18e008 <_ZN8LoadSave9freadrealEP7_YYFILEPd+0x80> */
/* @0x18dfa8 ldr r3, [r4] */
/* @0x18dfac add r1, sp, #8 */
/* @0x18dfb0 mov r2, #0 */
/* @0x18dfb4 str r2, [r1, #-0x4]! */
/* @0x18dfb8 ldr r0, [r3, #0xc] */
/* @0x18dfbc ldr r3, [r3, #0x1c] */
/* @0x18dfc0 add r0, r0, r3 */
/* @0x18dfc4 bl 0xb6658 <strtod@plt> */
/* @0x18dfc8 ldr r3, [r4] */
/* @0x18dfcc ldr r2, [sp, #0x4] */
/* @0x18dfd0 ldr r12, [r3] */
/* @0x18dfd4 ldr r12, [r12, #0x10] */
/* @0x18dfd8 strd r0, r1, [r5] */
/* @0x18dfdc mov r0, r3 */
/* @0x18dfe0 ldr r4, [r3, #0xc] */
/* @0x18dfe4 mov r1, #1 */
/* @0x18dfe8 ldr r3, [r3, #0x1c] */
/* @0x18dfec add r4, r4, r3 */
/* @0x18dff0 rsb r4, r4, r2 */
/* @0x18dff4 mov r2, r4 */
/* @0x18dff8 blx r12 */
/* @0x18dffc mov r0, r4 */
/* @0x18e000 add sp, sp, #12 */
/* @0x18e004 pop {r4, r5, r6, r7, pc} */
/* @0x18e008 ldr r0, [r4] */
/* @0x18e00c mov r2, #1 */
/* @0x18e010 add r7, r0, #44 */
/* @0x18e014 ldr r12, [r0] */
/* @0x18e018 ldr r1, [r0, #0x1c] */
/* @0x18e01c mov r3, r7 */
/* @0x18e020 ldr r12, [r12, #0x14] */
/* @0x18e024 blx r12 */
/* @0x18e028 mov r1, r6 */
/* @0x18e02c mov r0, r7 */
/* @0x18e030 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18e034 ldr r3, [pc, #0x30] */
/* @0x18e038 mov r1, #1 */
/* @0x18e03c ldr r3, [pc, r3] */
/* @0x18e040 mov r2, r1 */
/* @0x18e044 ldr r3, [r3] */
/* @0x18e048 uxtab r0, r3, r0 */
/* @0x18e04c ldrb r3, [r0, #0x1] */
/* @0x18e050 tst r3, #8 */
/* @0x18e054 beq 0x18dfa8 <_ZN8LoadSave9freadrealEP7_YYFILEPd+0x20> */
/* @0x18e058 ldr r0, [r4] */
/* @0x18e05c ldr r3, [r0] */
/* @0x18e060 ldr r3, [r3, #0x10] */
/* @0x18e064 blx r3 */
/* @0x18e068 b 0x18df98 <_ZN8LoadSave9freadrealEP7_YYFILEPd+0x10> */
/* @0x18e06c eoreq pc, r5, r4, asr #18 */

/* ── FUNC 0x18e070 · LoadSave::fread(void const*, unsigned int, unsigned int, _YYFILE*) · size=36 · insn=9 */
/* @0x18e070 str r4, [sp, #-0x4]! */
/* @0x18e074 mov r12, r2 */
/* @0x18e078 mov r4, r1 */
/* @0x18e07c mov r1, r0 */
/* @0x18e080 mov r2, r4 */
/* @0x18e084 ldr r0, [r3] */
/* @0x18e088 ldr r4, [sp], #4 */
/* @0x18e08c mov r3, r12 */
/* @0x18e090 b 0xcdc9c <_ZN7IBuffer4ReadEPKvjj> */

/* ── FUNC 0x18e094 · LoadSave::_WriteFile(char const*, char const*, int) · size=128 · insn=32 */
/* @0x18e094 push {r4, r5, r6, lr} */
/* @0x18e098 mov r5, r1 */
/* @0x18e09c ldr r1, [pc, #0x68] */
/* @0x18e0a0 mov r4, r2 */
/* @0x18e0a4 add r1, pc, r1 */
/* @0x18e0a8 bl 0xb6844 <fopen@plt> */
/* @0x18e0ac subs r6, r0, #0 */
/* @0x18e0b0 beq 0x18e0f8 <_ZN8LoadSave10_WriteFileEPKcS1_i+0x64> */
/* @0x18e0b4 cmp r4, #0 */
/* @0x18e0b8 bne 0x18e0c8 <_ZN8LoadSave10_WriteFileEPKcS1_i+0x34> */
/* @0x18e0bc b 0x18e0e8 <_ZN8LoadSave10_WriteFileEPKcS1_i+0x54> */
/* @0x18e0c0 subs r4, r4, r0 */
/* @0x18e0c4 beq 0x18e0e8 <_ZN8LoadSave10_WriteFileEPKcS1_i+0x54> */
/* @0x18e0c8 mov r0, r5 */
/* @0x18e0cc mov r1, #1 */
/* @0x18e0d0 mov r2, r4 */
/* @0x18e0d4 mov r3, r6 */
/* @0x18e0d8 bl 0xb68bc <fwrite@plt> */
/* @0x18e0dc cmp r0, #0 */
/* @0x18e0e0 add r5, r5, r0 */
/* @0x18e0e4 bne 0x18e0c0 <_ZN8LoadSave10_WriteFileEPKcS1_i+0x2c> */
/* @0x18e0e8 mov r0, r6 */
/* @0x18e0ec bl 0xb6850 <fclose@plt> */
/* @0x18e0f0 mov r0, #1 */
/* @0x18e0f4 pop {r4, r5, r6, pc} */
/* @0x18e0f8 ldr r0, [pc, #0x10] */
/* @0x18e0fc add r0, pc, r0 */
/* @0x18e100 bl 0xb6934 <perror@plt> */
/* @0x18e104 mov r0, r6 */
/* @0x18e108 pop {r4, r5, r6, pc} */
/* @0x18e10c andseq r2, r11, r0, lsr #5 */
/* @0x18e110 andseq lr, r11, r0, lsl r2 */

/* ── FUNC 0x18e114 · LoadSave::fputs(_YYFILE*, char const*) · size=412 · insn=103 */
/* @0x18e114 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18e118 sub sp, sp, #4096 */
/* @0x18e11c ldr r5, [pc, #0x184] */
/* @0x18e120 sub sp, sp, #12 */
/* @0x18e124 add r2, sp, #8192 */
/* @0x18e128 mov r6, r0 */
/* @0x18e12c ldr r5, [pc, r5] */
/* @0x18e130 mov r0, r1 */
/* @0x18e134 mov r7, r1 */
/* @0x18e138 ldr r3, [r5] */
/* @0x18e13c str r3, [r2, #-0xffc] */
/* @0x18e140 bl 0xb6538 <strlen@plt> */
/* @0x18e144 cmp r0, #0 */
/* @0x18e148 mov r4, r0 */
/* @0x18e14c mov r9, r0 */
/* @0x18e150 ble 0x18e268 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x154> */
/* @0x18e154 cmp r7, #0 */
/* @0x18e158 addeq r7, sp, #4 */
/* @0x18e15c ldrb r3, [r7] */
/* @0x18e160 subs r2, r3, #10 */
/* @0x18e164 rsbs r3, r2, #0 */
/* @0x18e168 adcs r3, r3, r2 */
/* @0x18e16c cmp r0, #1 */
/* @0x18e170 beq 0x18e1b0 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x9c> */
/* @0x18e174 mov r12, r7 */
/* @0x18e178 mov r2, #1 */
/* @0x18e17c b 0x18e18c <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x78> */
/* @0x18e180 add r2, r2, #1 */
/* @0x18e184 cmp r4, r2 */
/* @0x18e188 beq 0x18e1b0 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x9c> */
/* @0x18e18c ldrb lr, [r12, #0x1]! */
/* @0x18e190 cmp lr, #10 */
/* @0x18e194 bne 0x18e180 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x6c> */
/* @0x18e198 ldrb r1, [r12, #-0x1] */
/* @0x18e19c add r2, r2, #1 */
/* @0x18e1a0 cmp r1, #13 */
/* @0x18e1a4 addne r3, r3, #1 */
/* @0x18e1a8 cmp r4, r2 */
/* @0x18e1ac bne 0x18e18c <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x78> */
/* @0x18e1b0 cmp r3, #0 */
/* @0x18e1b4 beq 0x18e28c <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x178> */
/* @0x18e1b8 ldr r1, [pc, #0xec] */
/* @0x18e1bc add r9, r4, r3 */
/* @0x18e1c0 movw r2, #0x24a */
/* @0x18e1c4 add r0, r9, #1 */
/* @0x18e1c8 add r1, pc, r1 */
/* @0x18e1cc mov r3, #1 */
/* @0x18e1d0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18e1d4 sub r7, r7, #1 */
/* @0x18e1d8 mov r12, #0 */
/* @0x18e1dc mov r1, #10 */
/* @0x18e1e0 mov r8, r0 */
/* @0x18e1e4 mov r2, r0 */
/* @0x18e1e8 mov r0, #13 */
/* @0x18e1ec b 0x18e204 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0xf0> */
/* @0x18e1f0 add r12, r12, #1 */
/* @0x18e1f4 strb lr, [r2] */
/* @0x18e1f8 cmp r4, r12 */
/* @0x18e1fc add r2, r2, #1 */
/* @0x18e200 beq 0x18e244 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x130> */
/* @0x18e204 ldrb lr, [r7, #0x1]! */
/* @0x18e208 cmp lr, #10 */
/* @0x18e20c bne 0x18e1f0 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0xdc> */
/* @0x18e210 cmp r12, #0 */
/* @0x18e214 beq 0x18e224 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x110> */
/* @0x18e218 ldrb r3, [r7, #-0x1] */
/* @0x18e21c cmp r3, #13 */
/* @0x18e220 beq 0x18e1f0 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0xdc> */
/* @0x18e224 add r12, r12, #1 */
/* @0x18e228 mov r3, r2 */
/* @0x18e22c cmp r4, r12 */
/* @0x18e230 strb r0, [r3], #1 */
/* @0x18e234 strb r1, [r2, #0x1] */
/* @0x18e238 mov r2, r3 */
/* @0x18e23c add r2, r2, #1 */
/* @0x18e240 bne 0x18e204 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0xf0> */
/* @0x18e244 ldr r0, [r6] */
/* @0x18e248 mov r1, r8 */
/* @0x18e24c mov r2, #1 */
/* @0x18e250 mov r3, r9 */
/* @0x18e254 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x18e258 cmp r8, #0 */
/* @0x18e25c beq 0x18e268 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x154> */
/* @0x18e260 mov r0, r8 */
/* @0x18e264 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18e268 add r3, sp, #8192 */
/* @0x18e26c mov r0, r9 */
/* @0x18e270 ldr r2, [r3, #-0xffc] */
/* @0x18e274 ldr r3, [r5] */
/* @0x18e278 cmp r2, r3 */
/* @0x18e27c bne 0x18e2a4 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x190> */
/* @0x18e280 add sp, sp, #4096 */
/* @0x18e284 add sp, sp, #12 */
/* @0x18e288 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18e28c ldr r0, [r6] */
/* @0x18e290 mov r1, r7 */
/* @0x18e294 mov r3, r4 */
/* @0x18e298 mov r2, #1 */
/* @0x18e29c bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x18e2a0 b 0x18e268 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x154> */
/* @0x18e2a4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x18e2a8 eoreq pc, r5, r4, lsr #16 */
/* @0x18e2ac andseq lr, r11, r0, lsl r1 */

/* ── FUNC 0x18e2b0 · LoadSave::fwrite(void const*, unsigned int, unsigned int, _YYFILE*) · size=36 · insn=9 */
/* @0x18e2b0 str r4, [sp, #-0x4]! */
/* @0x18e2b4 mov r12, r2 */
/* @0x18e2b8 mov r4, r1 */
/* @0x18e2bc mov r1, r0 */
/* @0x18e2c0 mov r2, r4 */
/* @0x18e2c4 ldr r0, [r3] */
/* @0x18e2c8 ldr r4, [sp], #4 */
/* @0x18e2cc mov r3, r12 */
/* @0x18e2d0 b 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */

/* ── FUNC 0x18e2d4 · HTTP_REQ_CONTEXT::SetResponseHeaders(char*) · size=464 · insn=116 */
/* @0x18e2d4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18e2d8 subs r5, r1, #0 */
/* @0x18e2dc sub sp, sp, #76 */
/* @0x18e2e0 mov r6, r0 */
/* @0x18e2e4 beq 0x18e48c <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0x1b8> */
/* @0x18e2e8 add r3, sp, #36 */
/* @0x18e2ec str r3, [sp, #0x1c] */
/* @0x18e2f0 ldr r4, [pc, #0x19c] */
/* @0x18e2f4 mov r0, r3 */
/* @0x18e2f8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x18e2fc ldr r3, [pc, #0x194] */
/* @0x18e300 ldr r2, [r6, #0x2c] */
/* @0x18e304 add r4, pc, r4 */
/* @0x18e308 ldr r3, [pc, r3] */
/* @0x18e30c mov r0, r5 */
/* @0x18e310 mov r1, r4 */
/* @0x18e314 ldr r3, [r3, #0x4] */
/* @0x18e318 ldr r3, [r3, r2, lsl #2] */
/* @0x18e31c str r3, [sp, #0x14] */
/* @0x18e320 bl 0xb6940 <strtok@plt> */
/* @0x18e324 subs r10, r0, #0 */
/* @0x18e328 beq 0x18e484 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0x1b0> */
/* @0x18e32c ldr r11, [pc, #0x168] */
/* @0x18e330 add r8, sp, #40 */
/* @0x18e334 ldr r3, [pc, #0x164] */
/* @0x18e338 add r6, sp, #56 */
/* @0x18e33c str r4, [sp, #0x10] */
/* @0x18e340 add r11, pc, r11 */
/* @0x18e344 add r3, pc, r3 */
/* @0x18e348 mov r4, #0 */
/* @0x18e34c str r3, [sp, #0x18] */
/* @0x18e350 mov r9, #1 */
/* @0x18e354 add r3, sp, #44 */
/* @0x18e358 str r3, [sp, #0x8] */
/* @0x18e35c add r3, sp, #48 */
/* @0x18e360 str r3, [sp, #0xc] */
/* @0x18e364 add r3, sp, #60 */
/* @0x18e368 str r3, [sp] */
/* @0x18e36c add r3, sp, #64 */
/* @0x18e370 str r3, [sp, #0x4] */
/* @0x18e374 b 0x18e3cc <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0xf8> */
/* @0x18e378 ldr r3, [sp, #0x44] */
/* @0x18e37c mov r2, #5 */
/* @0x18e380 str r4, [sp, #0x30] */
/* @0x18e384 sub r3, r3, #1 */
/* @0x18e388 str r4, [sp, #0x28] */
/* @0x18e38c bic r3, r3, #-16777216 */
/* @0x18e390 str r2, [sp, #0x34] */
/* @0x18e394 bic r3, r3, #3 */
/* @0x18e398 cmp r3, #0 */
/* @0x18e39c beq 0x18e478 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0x1a4> */
/* @0x18e3a0 mov r0, r7 */
/* @0x18e3a4 mov r3, #5 */
/* @0x18e3a8 str r4, [sp, #0x40] */
/* @0x18e3ac str r4, [sp, #0x38] */
/* @0x18e3b0 str r3, [sp, #0x44] */
/* @0x18e3b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18e3b8 mov r0, #0 */
/* @0x18e3bc ldr r1, [sp, #0x10] */
/* @0x18e3c0 bl 0xb6940 <strtok@plt> */
/* @0x18e3c4 subs r10, r0, #0 */
/* @0x18e3c8 beq 0x18e484 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0x1b0> */
/* @0x18e3cc mov r1, r11 */
/* @0x18e3d0 mov r0, r10 */
/* @0x18e3d4 str r4, [r8] */
/* @0x18e3d8 str r4, [sp, #0x2c] */
/* @0x18e3dc str r4, [sp, #0x30] */
/* @0x18e3e0 str r4, [r6] */
/* @0x18e3e4 str r4, [sp, #0x3c] */
/* @0x18e3e8 str r4, [sp, #0x40] */
/* @0x18e3ec str r9, [sp, #0x34] */
/* @0x18e3f0 str r9, [sp, #0x44] */
/* @0x18e3f4 bl 0xb6604 <strstr@plt> */
/* @0x18e3f8 subs r1, r0, #0 */
/* @0x18e3fc mov r0, r6 */
/* @0x18e400 rsb r5, r10, r1 */
/* @0x18e404 add r1, r1, #2 */
/* @0x18e408 beq 0x18e3b8 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0xe4> */
/* @0x18e40c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18e410 mov r3, #1 */
/* @0x18e414 ldr r1, [sp, #0x18] */
/* @0x18e418 mov r2, #125 */
/* @0x18e41c add r0, r5, #1 */
/* @0x18e420 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18e424 mov r2, r5 */
/* @0x18e428 mov r1, r10 */
/* @0x18e42c mov r7, r0 */
/* @0x18e430 bl 0xb6568 <strncpy@plt> */
/* @0x18e434 mov r1, r7 */
/* @0x18e438 mov r0, r8 */
/* @0x18e43c strb r4, [r7, r5] */
/* @0x18e440 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x18e444 ldr r0, [sp, #0x14] */
/* @0x18e448 mov r1, r8 */
/* @0x18e44c mov r2, r6 */
/* @0x18e450 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x18e454 ldr r3, [sp, #0x34] */
/* @0x18e458 sub r3, r3, #1 */
/* @0x18e45c bic r3, r3, #-16777216 */
/* @0x18e460 bic r3, r3, #3 */
/* @0x18e464 cmp r3, #0 */
/* @0x18e468 bne 0x18e378 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0xa4> */
/* @0x18e46c mov r0, r8 */
/* @0x18e470 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x18e474 b 0x18e378 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0xa4> */
/* @0x18e478 mov r0, r6 */
/* @0x18e47c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x18e480 b 0x18e3a0 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0xcc> */
/* @0x18e484 add r0, sp, #36 */
/* @0x18e488 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x18e48c add sp, sp, #76 */
/* @0x18e490 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x18e494 andseq r2, r11, r4, lsr r0 */
/* @0x18e498 eoreq pc, r5, r4, lsr r6 */
/* @0x18e49c ldrsheq r1, [r11], -r4 */
/* @0x18e4a0 mulseq r11, r4, pc */

/* ── FUNC 0x18e4a4 · GMGamePad::SetGamePadCount(int) · size=232 · insn=58 */
/* @0x18e4a4 push {r4, r5, r6, r7, lr} */
/* @0x18e4a8 mov r2, r0 */
/* @0x18e4ac ldr r5, [pc, #0xc0] */
/* @0x18e4b0 mov r4, r0 */
/* @0x18e4b4 ldr r3, [pc, #0xbc] */
/* @0x18e4b8 sub sp, sp, #12 */
/* @0x18e4bc add r5, pc, r5 */
/* @0x18e4c0 ldr r1, [pc, #0xb4] */
/* @0x18e4c4 ldr r3, [r5, r3] */
/* @0x18e4c8 add r1, pc, r1 */
/* @0x18e4cc ldr r0, [r3] */
/* @0x18e4d0 ldr r3, [r0] */
/* @0x18e4d4 ldr r3, [r3, #0xc] */
/* @0x18e4d8 blx r3 */
/* @0x18e4dc ldr r3, [pc, #0x9c] */
/* @0x18e4e0 ldr r6, [r5, r3] */
/* @0x18e4e4 ldr r3, [r6] */
/* @0x18e4e8 cmp r4, r3 */
/* @0x18e4ec beq 0x18e560 <_ZN9GMGamePad15SetGamePadCountEi+0xbc> */
/* @0x18e4f0 ldr r0, [pc, #0x8c] */
/* @0x18e4f4 mov r3, #74 */
/* @0x18e4f8 ldr r2, [pc, #0x88] */
/* @0x18e4fc mov r7, #0 */
/* @0x18e500 lsl r1, r4, #2 */
/* @0x18e504 ldr r5, [r5, r0] */
/* @0x18e508 add r2, pc, r2 */
/* @0x18e50c str r7, [sp] */
/* @0x18e510 ldr r0, [r5] */
/* @0x18e514 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x18e518 ldr r3, [r6] */
/* @0x18e51c cmp r4, r3 */
/* @0x18e520 str r0, [r5] */
/* @0x18e524 ble 0x18e554 <_ZN9GMGamePad15SetGamePadCountEi+0xb0> */
/* @0x18e528 lsl r1, r3, #2 */
/* @0x18e52c mov r12, r0 */
/* @0x18e530 mov r2, r7 */
/* @0x18e534 b 0x18e53c <_ZN9GMGamePad15SetGamePadCountEi+0x98> */
/* @0x18e538 ldr r12, [r5] */
/* @0x18e53c add r3, r3, #1 */
/* @0x18e540 str r2, [r12, r1] */
/* @0x18e544 cmp r3, r4 */
/* @0x18e548 add r1, r1, #4 */
/* @0x18e54c bne 0x18e538 <_ZN9GMGamePad15SetGamePadCountEi+0x94> */
/* @0x18e550 ldr r0, [r5] */
/* @0x18e554 str r4, [r6] */
/* @0x18e558 add sp, sp, #12 */
/* @0x18e55c pop {r4, r5, r6, r7, pc} */
/* @0x18e560 ldr r3, [pc, #0x1c] */
/* @0x18e564 ldr r3, [r5, r3] */
/* @0x18e568 ldr r0, [r3] */
/* @0x18e56c add sp, sp, #12 */
/* @0x18e570 pop {r4, r5, r6, r7, pc} */
/* @0x18e574 mlaeq r6, r4, r7, r3 */
/* @0x18e578 .word 0xffffbcf0 */
/* @0x18e57c andseq sp, r11, r0, asr lr */
/* @0x18e580 .word 0xffffde10 */
/* @0x18e584 .word 0xffffde14 */
/* @0x18e588 andseq sp, r11, r8, lsr lr */

/* ── FUNC 0x18e58c · GamePadRestart() · size=192 · insn=48 */
/* @0x18e58c ldr r3, [pc, #0xa4] */
/* @0x18e590 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x18e594 ldr r3, [pc, r3] */
/* @0x18e598 sub sp, sp, #24 */
/* @0x18e59c ldr r6, [r3] */
/* @0x18e5a0 cmp r6, #0 */
/* @0x18e5a4 ble 0x18e630 <_Z14GamePadRestartv+0xa4> */
/* @0x18e5a8 ldr r3, [pc, #0x8c] */
/* @0x18e5ac mov r4, #0 */
/* @0x18e5b0 ldr r10, [pc, #0x88] */
/* @0x18e5b4 mov r9, r4 */
/* @0x18e5b8 ldr r3, [pc, r3] */
/* @0x18e5bc ldr r8, [pc, #0x80] */
/* @0x18e5c0 ldr r7, [pc, #0x80] */
/* @0x18e5c4 add r10, pc, r10 */
/* @0x18e5c8 ldr r5, [r3] */
/* @0x18e5cc add r8, pc, r8 */
/* @0x18e5d0 add r7, pc, r7 */
/* @0x18e5d4 sub r5, r5, #4 */
/* @0x18e5d8 ldr r12, [r5, #0x4]! */
/* @0x18e5dc mov r1, r10 */
/* @0x18e5e0 mov r2, #0 */
/* @0x18e5e4 mov r3, #0 */
/* @0x18e5e8 cmp r12, #0 */
/* @0x18e5ec mov r0, #2 */
/* @0x18e5f0 beq 0x18e624 <_Z14GamePadRestartv+0x98> */
/* @0x18e5f4 ldrb r12, [r12] */
/* @0x18e5f8 cmp r12, #0 */
/* @0x18e5fc beq 0x18e624 <_Z14GamePadRestartv+0x98> */
/* @0x18e600 vmov s13, r4 */
/* @0x18e604 str r8, [sp] */
/* @0x18e608 str r7, [sp, #0x4] */
/* @0x18e60c vcvt.f64.s32 d7, s13 */
/* @0x18e610 str r9, [sp, #0x10] */
/* @0x18e614 vstr d7, [sp, #8] */
/* @0x18e618 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x18e61c mov r1, #75 */
/* @0x18e620 bl 0x18da04 <_Z24CreateAsynEventWithDSMapii> */
/* @0x18e624 add r4, r4, #1 */
/* @0x18e628 cmp r4, r6 */
/* @0x18e62c bne 0x18e5d8 <_Z14GamePadRestartv+0x4c> */
/* @0x18e630 add sp, sp, #24 */
/* @0x18e634 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x18e638 eoreq r1, r6, r12, asr #9 */
/* @0x18e63c eoreq r1, r6, r12, lsr #9 */
/* @0x18e640 andseq sp, r11, r0, asr #27 */
/* @0x18e644 andseq sp, r11, r4, asr #27 */
/* @0x18e648 ldrsbeq sp, [r11], -r4 */

/* ── FUNC 0x18e64c · GMGamePad::~GMGamePad() · size=80 · insn=20 */
/* @0x18e64c push {r4, lr} */
/* @0x18e650 mov r4, r0 */
/* @0x18e654 ldr r0, [r0, #0xc] */
/* @0x18e658 cmp r0, #0 */
/* @0x18e65c beq 0x18e664 <_ZN9GMGamePadD2Ev+0x18> */
/* @0x18e660 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18e664 ldr r0, [r4, #0x10] */
/* @0x18e668 cmp r0, #0 */
/* @0x18e66c beq 0x18e674 <_ZN9GMGamePadD2Ev+0x28> */
/* @0x18e670 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18e674 ldr r0, [r4, #0x14] */
/* @0x18e678 cmp r0, #0 */
/* @0x18e67c beq 0x18e684 <_ZN9GMGamePadD2Ev+0x38> */
/* @0x18e680 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18e684 ldr r0, [r4, #0x18] */
/* @0x18e688 cmp r0, #0 */
/* @0x18e68c beq 0x18e694 <_ZN9GMGamePadD2Ev+0x48> */
/* @0x18e690 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18e694 mov r0, r4 */
/* @0x18e698 pop {r4, pc} */

/* ── FUNC 0x18e64c · GMGamePad::~GMGamePad() · alias of the symbol above · insn=0 */

/* ── FUNC 0x18e69c · GMGamePad::UpdateCounts(int, int) · size=220 · insn=55 */
/* @0x18e69c ldr r3, [r0, #0x4] */
/* @0x18e6a0 push {r4, r5, r6, r7, r8, lr} */
/* @0x18e6a4 cmp r3, r1 */
/* @0x18e6a8 sub sp, sp, #8 */
/* @0x18e6ac mov r4, r0 */
/* @0x18e6b0 mov r5, r2 */
/* @0x18e6b4 beq 0x18e708 <_ZN9GMGamePad12UpdateCountsEii+0x6c> */
/* @0x18e6b8 ldr r6, [pc, #0xb0] */
/* @0x18e6bc lsl r7, r1, #2 */
/* @0x18e6c0 ldr r0, [r0, #0xc] */
/* @0x18e6c4 mov r8, #0 */
/* @0x18e6c8 add r6, pc, r6 */
/* @0x18e6cc str r1, [r4, #0x4] */
/* @0x18e6d0 mov r3, #74 */
/* @0x18e6d4 mov r1, r7 */
/* @0x18e6d8 mov r2, r6 */
/* @0x18e6dc str r8, [sp] */
/* @0x18e6e0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x18e6e4 ldr r12, [r4, #0x10] */
/* @0x18e6e8 mov r1, r7 */
/* @0x18e6ec str r8, [sp] */
/* @0x18e6f0 mov r2, r6 */
/* @0x18e6f4 mov r3, #74 */
/* @0x18e6f8 str r0, [r4, #0xc] */
/* @0x18e6fc mov r0, r12 */
/* @0x18e700 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x18e704 str r0, [r4, #0x10] */
/* @0x18e708 ldr r3, [r4, #0x8] */
/* @0x18e70c cmp r3, r5 */
/* @0x18e710 beq 0x18e768 <_ZN9GMGamePad12UpdateCountsEii+0xcc> */
/* @0x18e714 ldr r3, [pc, #0x58] */
/* @0x18e718 lsl r6, r5, #2 */
/* @0x18e71c str r5, [r4, #0x8] */
/* @0x18e720 mov r7, #0 */
/* @0x18e724 add r3, pc, r3 */
/* @0x18e728 ldr r0, [r4, #0x14] */
/* @0x18e72c mov r1, r6 */
/* @0x18e730 str r7, [sp] */
/* @0x18e734 mov r2, r3 */
/* @0x18e738 mov r5, r3 */
/* @0x18e73c mov r3, #74 */
/* @0x18e740 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x18e744 ldr r12, [r4, #0x18] */
/* @0x18e748 mov r1, r6 */
/* @0x18e74c str r7, [sp] */
/* @0x18e750 mov r2, r5 */
/* @0x18e754 mov r3, #74 */
/* @0x18e758 str r0, [r4, #0x14] */
/* @0x18e75c mov r0, r12 */
/* @0x18e760 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x18e764 str r0, [r4, #0x18] */
/* @0x18e768 add sp, sp, #8 */
/* @0x18e76c pop {r4, r5, r6, r7, r8, pc} */
/* @0x18e770 andseq sp, r11, r8, ror r12 */
/* @0x18e774 andseq sp, r11, r12, lsl r12 */

/* ── FUNC 0x18e778 · GMGamePad::Clear() · size=124 · insn=31 */
/* @0x18e778 push {r4, lr} */
/* @0x18e77c mov r4, r0 */
/* @0x18e780 ldr r0, [r0, #0xc] */
/* @0x18e784 cmp r0, #0 */
/* @0x18e788 beq 0x18e79c <_ZN9GMGamePad5ClearEv+0x24> */
/* @0x18e78c ldr r2, [r4, #0x4] */
/* @0x18e790 mov r1, #0 */
/* @0x18e794 lsl r2, r2, #2 */
/* @0x18e798 bl 0xb65b0 <memset@plt> */
/* @0x18e79c ldr r0, [r4, #0x10] */
/* @0x18e7a0 cmp r0, #0 */
/* @0x18e7a4 beq 0x18e7b8 <_ZN9GMGamePad5ClearEv+0x40> */
/* @0x18e7a8 ldr r2, [r4, #0x4] */
/* @0x18e7ac mov r1, #0 */
/* @0x18e7b0 lsl r2, r2, #2 */
/* @0x18e7b4 bl 0xb65b0 <memset@plt> */
/* @0x18e7b8 ldr r0, [r4, #0x14] */
/* @0x18e7bc cmp r0, #0 */
/* @0x18e7c0 beq 0x18e7d4 <_ZN9GMGamePad5ClearEv+0x5c> */
/* @0x18e7c4 ldr r2, [r4, #0x8] */
/* @0x18e7c8 mov r1, #0 */
/* @0x18e7cc lsl r2, r2, #2 */
/* @0x18e7d0 bl 0xb65b0 <memset@plt> */
/* @0x18e7d4 ldr r0, [r4, #0x18] */
/* @0x18e7d8 cmp r0, #0 */
/* @0x18e7dc popeq {r4, pc} */
/* @0x18e7e0 ldr r2, [r4, #0x8] */
/* @0x18e7e4 mov r1, #0 */
/* @0x18e7e8 pop {r4, lr} */
/* @0x18e7ec lsl r2, r2, #2 */
/* @0x18e7f0 b 0xb65b0 <memset@plt> */

/* ── FUNC 0x18e7f4 · GMGamePad::SetConnected(bool) · size=248 · insn=62 */
/* @0x18e7f4 ldrb r3, [r0] */
/* @0x18e7f8 push {r4, lr} */
/* @0x18e7fc cmp r3, r1 */
/* @0x18e800 sub sp, sp, #24 */
/* @0x18e804 mov r4, r0 */
/* @0x18e808 strb r1, [r0] */
/* @0x18e80c beq 0x18e8a8 <_ZN9GMGamePad12SetConnectedEb+0xb4> */
/* @0x18e810 ldr r3, [pc, #0xbc] */
/* @0x18e814 ldr r3, [pc, r3] */
/* @0x18e818 ldr r0, [r3] */
/* @0x18e81c cmp r0, #0 */
/* @0x18e820 ble 0x18e850 <_ZN9GMGamePad12SetConnectedEb+0x5c> */
/* @0x18e824 ldr r2, [pc, #0xac] */
/* @0x18e828 mov r3, #0 */
/* @0x18e82c ldr r2, [pc, r2] */
/* @0x18e830 ldr r2, [r2] */
/* @0x18e834 sub r2, r2, #4 */
/* @0x18e838 ldr r12, [r2, #0x4]! */
/* @0x18e83c cmp r12, r4 */
/* @0x18e840 beq 0x18e8c8 <_ZN9GMGamePad12SetConnectedEb+0xd4> */
/* @0x18e844 add r3, r3, #1 */
/* @0x18e848 cmp r3, r0 */
/* @0x18e84c bne 0x18e838 <_ZN9GMGamePad12SetConnectedEb+0x44> */
/* @0x18e850 vmov.f64 d7, #-1.000000e+00 */
/* @0x18e854 ldr r2, [pc, #0x80] */
/* @0x18e858 cmp r1, #0 */
/* @0x18e85c add r2, pc, r2 */
/* @0x18e860 ldrne r2, [pc, #0x78] */
/* @0x18e864 addne r2, pc, r2 */
/* @0x18e868 ldr r3, [pc, #0x74] */
/* @0x18e86c vstr d7, [sp, #8] */
/* @0x18e870 ldr r1, [pc, #0x70] */
/* @0x18e874 mov r0, #2 */
/* @0x18e878 add r3, pc, r3 */
/* @0x18e87c str r2, [sp] */
/* @0x18e880 str r3, [sp, #0x4] */
/* @0x18e884 mov r2, #0 */
/* @0x18e888 mov r3, #0 */
/* @0x18e88c str r2, [sp, #0x10] */
/* @0x18e890 add r1, pc, r1 */
/* @0x18e894 mov r2, #0 */
/* @0x18e898 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x18e89c mov r1, #75 */
/* @0x18e8a0 bl 0x18da04 <_Z24CreateAsynEventWithDSMapii> */
/* @0x18e8a4 ldrb r3, [r4] */
/* @0x18e8a8 cmp r3, #0 */
/* @0x18e8ac beq 0x18e8b8 <_ZN9GMGamePad12SetConnectedEb+0xc4> */
/* @0x18e8b0 add sp, sp, #24 */
/* @0x18e8b4 pop {r4, pc} */
/* @0x18e8b8 mov r0, r4 */
/* @0x18e8bc add sp, sp, #24 */
/* @0x18e8c0 pop {r4, lr} */
/* @0x18e8c4 b 0x18e778 <_ZN9GMGamePad5ClearEv> */
/* @0x18e8c8 vmov s13, r3 */
/* @0x18e8cc vcvt.f64.s32 d7, s13 */
/* @0x18e8d0 b 0x18e854 <_ZN9GMGamePad12SetConnectedEb+0x60> */
/* @0x18e8d4 eoreq r1, r6, r12, asr #4 */
/* @0x18e8d8 eoreq r1, r6, r8, lsr r2 */
/* @0x18e8dc andseq sp, r11, r4, asr r11 */
/* @0x18e8e0 andseq sp, r11, r12, lsr #22 */
/* @0x18e8e4 andseq sp, r11, r12, lsr #22 */
/* @0x18e8e8 ldrsheq sp, [r11], -r4 */

/* ── FUNC 0x18e8ec · ForgetAllGamePads() · size=88 · insn=22 */
/* @0x18e8ec ldr r3, [pc, #0x48] */
/* @0x18e8f0 push {r4, r5, r6, lr} */
/* @0x18e8f4 ldr r3, [pc, r3] */
/* @0x18e8f8 ldr r6, [r3] */
/* @0x18e8fc cmp r6, #0 */
/* @0x18e900 pople {r4, r5, r6, pc} */
/* @0x18e904 ldr r3, [pc, #0x34] */
/* @0x18e908 mov r4, #0 */
/* @0x18e90c ldr r3, [pc, r3] */
/* @0x18e910 ldr r5, [r3] */
/* @0x18e914 sub r5, r5, #4 */
/* @0x18e918 ldr r0, [r5, #0x4]! */
/* @0x18e91c mov r1, #0 */
/* @0x18e920 add r4, r4, #1 */
/* @0x18e924 cmp r0, r1 */
/* @0x18e928 beq 0x18e930 <_Z17ForgetAllGamePadsv+0x44> */
/* @0x18e92c bl 0x18e7f4 <_ZN9GMGamePad12SetConnectedEb> */
/* @0x18e930 cmp r4, r6 */
/* @0x18e934 bne 0x18e918 <_Z17ForgetAllGamePadsv+0x2c> */
/* @0x18e938 pop {r4, r5, r6, pc} */
/* @0x18e93c eoreq r1, r6, r12, ror #2 */
/* @0x18e940 eoreq r1, r6, r8, asr r1 */

/* ── FUNC 0x18e944 · GMGamePad::SetDeviceId(char const*) · size=56 · insn=14 */
/* @0x18e944 push {r3, r4, r5, lr} */
/* @0x18e948 subs r5, r1, #0 */
/* @0x18e94c popeq {r3, r4, r5, pc} */
/* @0x18e950 add r4, r0, #44 */
/* @0x18e954 mov r2, #512 */
/* @0x18e958 mov r0, r4 */
/* @0x18e95c bl 0xb65e0 <strncmp@plt> */
/* @0x18e960 cmp r0, #0 */
/* @0x18e964 popeq {r3, r4, r5, pc} */
/* @0x18e968 mov r0, r4 */
/* @0x18e96c mov r1, r5 */
/* @0x18e970 mov r2, #512 */
/* @0x18e974 pop {r3, r4, r5, lr} */
/* @0x18e978 b 0xb6568 <strncpy@plt> */

/* ── FUNC 0x18e97c · GMGamePad::GMGamePad() · size=88 · insn=22 */
/* @0x18e97c ldr r1, [pc, #0x4c] */
/* @0x18e980 mov r3, #0 */
/* @0x18e984 push {r4, lr} */
/* @0x18e988 mov r2, #0 */
/* @0x18e98c mov r12, #1056964608 */
/* @0x18e990 mov r4, r0 */
/* @0x18e994 strb r3, [r0] */
/* @0x18e998 add r1, pc, r1 */
/* @0x18e99c str r2, [r0, #0x20] */
/* @0x18e9a0 str r3, [r0, #0x4] */
/* @0x18e9a4 str r2, [r0, #0x28] */
/* @0x18e9a8 str r3, [r0, #0x8] */
/* @0x18e9ac str r2, [r0, #0x24] */
/* @0x18e9b0 str r3, [r0, #0xc] */
/* @0x18e9b4 str r3, [r0, #0x10] */
/* @0x18e9b8 str r3, [r0, #0x14] */
/* @0x18e9bc str r3, [r0, #0x18] */
/* @0x18e9c0 str r12, [r0, #0x1c] */
/* @0x18e9c4 bl 0x18e944 <_ZN9GMGamePad11SetDeviceIdEPKc> */
/* @0x18e9c8 mov r0, r4 */
/* @0x18e9cc pop {r4, pc} */
/* @0x18e9d0 mulseq r10, lr, r1 */

/* ── FUNC 0x18e97c · GMGamePad::GMGamePad() · alias of the symbol above · insn=0 */

/* ── FUNC 0x18e9d4 · GMGamePad::GMGamePad(int, int) · size=252 · insn=63 */
/* @0x18e9d4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x18e9d8 lsl r9, r1, #2 */
/* @0x18e9dc ldr r5, [pc, #0xdc] */
/* @0x18e9e0 mov r4, r0 */
/* @0x18e9e4 str r1, [r0, #0x4] */
/* @0x18e9e8 mov r12, #1056964608 */
/* @0x18e9ec add r5, pc, r5 */
/* @0x18e9f0 str r12, [r4, #0x1c] */
/* @0x18e9f4 mov r6, r2 */
/* @0x18e9f8 mov r7, #0 */
/* @0x18e9fc str r2, [r4, #0x8] */
/* @0x18ea00 mov r1, r5 */
/* @0x18ea04 mov r3, #0 */
/* @0x18ea08 mov r0, r9 */
/* @0x18ea0c strb r3, [r4] */
/* @0x18ea10 mov r2, #91 */
/* @0x18ea14 str r7, [r4, #0x20] */
/* @0x18ea18 mov r3, #1 */
/* @0x18ea1c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18ea20 mov r1, r5 */
/* @0x18ea24 mov r2, #92 */
/* @0x18ea28 mov r3, #1 */
/* @0x18ea2c lsl r8, r6, #2 */
/* @0x18ea30 str r0, [r4, #0xc] */
/* @0x18ea34 mov r0, r9 */
/* @0x18ea38 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18ea3c mov r1, r5 */
/* @0x18ea40 mov r2, #93 */
/* @0x18ea44 mov r3, #1 */
/* @0x18ea48 str r0, [r4, #0x10] */
/* @0x18ea4c mov r0, r8 */
/* @0x18ea50 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18ea54 mov r1, r5 */
/* @0x18ea58 mov r2, #94 */
/* @0x18ea5c mov r3, #1 */
/* @0x18ea60 str r0, [r4, #0x14] */
/* @0x18ea64 mov r0, r8 */
/* @0x18ea68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18ea6c ldr r12, [pc, #0x50] */
/* @0x18ea70 ldr r1, [pc, #0x50] */
/* @0x18ea74 mov r2, r6 */
/* @0x18ea78 ldr r12, [pc, r12] */
/* @0x18ea7c add r1, pc, r1 */
/* @0x18ea80 mov r3, r0 */
/* @0x18ea84 str r0, [r4, #0x18] */
/* @0x18ea88 ldr r0, [r12] */
/* @0x18ea8c ldr r12, [r0] */
/* @0x18ea90 ldr r12, [r12, #0xc] */
/* @0x18ea94 blx r12 */
/* @0x18ea98 mov r0, r4 */
/* @0x18ea9c bl 0x18e778 <_ZN9GMGamePad5ClearEv> */
/* @0x18eaa0 ldr r1, [pc, #0x24] */
/* @0x18eaa4 mov r0, r4 */
/* @0x18eaa8 str r7, [r4, #0x28] */
/* @0x18eaac str r7, [r4, #0x24] */
/* @0x18eab0 add r1, pc, r1 */
/* @0x18eab4 bl 0x18e944 <_ZN9GMGamePad11SetDeviceIdEPKc> */
/* @0x18eab8 mov r0, r4 */
/* @0x18eabc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x18eac0 ldrsbeq sp, [r11], -r4 */
/* @0x18eac4 eoreq r1, r6, r4, lsr #1 */
/* @0x18eac8 andseq sp, r11, r8, ror r9 */
/* @0x18eacc andseq r0, r10, r6, lsl #1 */

/* ── FUNC 0x18e9d4 · GMGamePad::GMGamePad(int, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x18ead0 · GMGamePad::ButtonCount() const · size=20 · insn=5 */
/* @0x18ead0 ldrb r3, [r0] */
/* @0x18ead4 cmp r3, #0 */
/* @0x18ead8 ldrne r0, [r0, #0x4] */
/* @0x18eadc moveq r0, r3 */
/* @0x18eae0 bx lr */

/* ── FUNC 0x18eae4 · GMGamePad::GetButtonValueFromAxis(int, float*) const · size=120 · insn=30 */
/* @0x18eae4 tst r1, #16384 */
/* @0x18eae8 biceq r1, r1, #4096 */
/* @0x18eaec bicne r1, r1, #20480 */
/* @0x18eaf0 tst r1, #8192 */
/* @0x18eaf4 beq 0x18eb24 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf+0x40> */
/* @0x18eaf8 vldr s14, [r0, #32] */
/* @0x18eafc vneg.f32 s14, s14 */
/* @0x18eb00 bic r1, r1, #8192 */
/* @0x18eb04 add r2, r2, r1, lsl #2 */
/* @0x18eb08 vldr s15, [r2] */
/* @0x18eb0c vcmpe.f32 s15, s14 */
/* @0x18eb10 vmrs APSR_nzcv, fpscr */
/* @0x18eb14 vabsmi.f32 s15, s15 */
/* @0x18eb18 bpl 0x18eb4c <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf+0x68> */
/* @0x18eb1c vmov r0, s15 */
/* @0x18eb20 bx lr */
/* @0x18eb24 vldr s13, [r0, #32] */
/* @0x18eb28 vneg.f32 s13, s13 */
/* @0x18eb2c add r1, r2, r1, lsl #2 */
/* @0x18eb30 vldr s15, [r1] */
/* @0x18eb34 vldr s14, [pc, #28] */
/* @0x18eb38 vcmpe.f32 s15, s13 */
/* @0x18eb3c vmrs APSR_nzcv, fpscr */
/* @0x18eb40 vmovle.f32 s15, s14 */
/* @0x18eb44 vmov r0, s15 */
/* @0x18eb48 bx lr */
/* @0x18eb4c vldr s15, [pc, #4] */
/* @0x18eb50 vmov r0, s15 */
/* @0x18eb54 bx lr */
/* @0x18eb58 andeq r0, r0, r0 */

/* ── FUNC 0x18eb5c · GMGamePad::ButtonDown(int) const · size=124 · insn=31 */
/* @0x18eb5c subs r3, r1, #0 */
/* @0x18eb60 push {r4, lr} */
/* @0x18eb64 mov r4, r0 */
/* @0x18eb68 blt 0x18ebac <_ZNK9GMGamePad10ButtonDownEi+0x50> */
/* @0x18eb6c ands r12, r3, #4096 */
/* @0x18eb70 bne 0x18ebb4 <_ZNK9GMGamePad10ButtonDownEi+0x58> */
/* @0x18eb74 ldr r2, [r0, #0x4] */
/* @0x18eb78 cmp r3, r2 */
/* @0x18eb7c bge 0x18eba4 <_ZNK9GMGamePad10ButtonDownEi+0x48> */
/* @0x18eb80 ldr r2, [r0, #0x10] */
/* @0x18eb84 vldr s15, [r0, #28] */
/* @0x18eb88 add r3, r2, r3, lsl #2 */
/* @0x18eb8c vldr s14, [r3] */
/* @0x18eb90 vcmpe.f32 s14, s15 */
/* @0x18eb94 vmrs APSR_nzcv, fpscr */
/* @0x18eb98 movlt r0, #0 */
/* @0x18eb9c movge r0, #1 */
/* @0x18eba0 pop {r4, pc} */
/* @0x18eba4 mov r0, r12 */
/* @0x18eba8 pop {r4, pc} */
/* @0x18ebac mov r0, #0 */
/* @0x18ebb0 pop {r4, pc} */
/* @0x18ebb4 ldr r2, [r0, #0x14] */
/* @0x18ebb8 bl 0x18eae4 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf> */
/* @0x18ebbc vldr s15, [r4, #28] */
/* @0x18ebc0 vmov s14, r0 */
/* @0x18ebc4 vcmpe.f32 s14, s15 */
/* @0x18ebc8 vmrs APSR_nzcv, fpscr */
/* @0x18ebcc movlt r0, #0 */
/* @0x18ebd0 movge r0, #1 */
/* @0x18ebd4 pop {r4, pc} */

/* ── FUNC 0x18ebd8 · GMGamePad::ButtonPressed(int) const · size=184 · insn=46 */
/* @0x18ebd8 push {r3, r4, r5, lr} */
/* @0x18ebdc vpush {d8} */
/* @0x18ebe0 subs r4, r1, #0 */
/* @0x18ebe4 mov r5, r0 */
/* @0x18ebe8 blt 0x18ec84 <_ZNK9GMGamePad13ButtonPressedEi+0xac> */
/* @0x18ebec ands r2, r4, #4096 */
/* @0x18ebf0 bne 0x18ec48 <_ZNK9GMGamePad13ButtonPressedEi+0x70> */
/* @0x18ebf4 ldr r3, [r0, #0x4] */
/* @0x18ebf8 cmp r4, r3 */
/* @0x18ebfc movge r0, r2 */
/* @0x18ec00 bge 0x18ec40 <_ZNK9GMGamePad13ButtonPressedEi+0x68> */
/* @0x18ec04 ldr r3, [r5, #0x10] */
/* @0x18ec08 lsl r4, r4, #2 */
/* @0x18ec0c vldr s15, [r5, #28] */
/* @0x18ec10 add r3, r3, r4 */
/* @0x18ec14 vldr s14, [r3] */
/* @0x18ec18 vcmpe.f32 s14, s15 */
/* @0x18ec1c vmrs APSR_nzcv, fpscr */
/* @0x18ec20 blt 0x18ec84 <_ZNK9GMGamePad13ButtonPressedEi+0xac> */
/* @0x18ec24 ldr r3, [r5, #0xc] */
/* @0x18ec28 add r4, r3, r4 */
/* @0x18ec2c vldr s14, [r4] */
/* @0x18ec30 vcmpe.f32 s15, s14 */
/* @0x18ec34 vmrs APSR_nzcv, fpscr */
/* @0x18ec38 ble 0x18ec84 <_ZNK9GMGamePad13ButtonPressedEi+0xac> */
/* @0x18ec3c mov r0, #1 */
/* @0x18ec40 vpop {d8} */
/* @0x18ec44 pop {r3, r4, r5, pc} */
/* @0x18ec48 ldr r2, [r0, #0x14] */
/* @0x18ec4c bl 0x18eae4 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf> */
/* @0x18ec50 mov r1, r4 */
/* @0x18ec54 ldr r2, [r5, #0x18] */
/* @0x18ec58 vmov s16, r0 */
/* @0x18ec5c mov r0, r5 */
/* @0x18ec60 bl 0x18eae4 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf> */
/* @0x18ec64 vldr s15, [r5, #28] */
/* @0x18ec68 vcmpe.f32 s16, s15 */
/* @0x18ec6c vmrs APSR_nzcv, fpscr */
/* @0x18ec70 vmov s14, r0 */
/* @0x18ec74 blt 0x18ec84 <_ZNK9GMGamePad13ButtonPressedEi+0xac> */
/* @0x18ec78 vcmpe.f32 s14, s15 */
/* @0x18ec7c vmrs APSR_nzcv, fpscr */
/* @0x18ec80 bmi 0x18ec3c <_ZNK9GMGamePad13ButtonPressedEi+0x64> */
/* @0x18ec84 vpop {d8} */
/* @0x18ec88 mov r0, #0 */
/* @0x18ec8c pop {r3, r4, r5, pc} */

/* ── FUNC 0x18ec90 · GMGamePad::ButtonReleased(int) const · size=184 · insn=46 */
/* @0x18ec90 push {r3, r4, r5, lr} */
/* @0x18ec94 vpush {d8} */
/* @0x18ec98 subs r4, r1, #0 */
/* @0x18ec9c mov r5, r0 */
/* @0x18eca0 blt 0x18ed3c <_ZNK9GMGamePad14ButtonReleasedEi+0xac> */
/* @0x18eca4 ands r2, r4, #4096 */
/* @0x18eca8 bne 0x18ed00 <_ZNK9GMGamePad14ButtonReleasedEi+0x70> */
/* @0x18ecac ldr r3, [r0, #0x4] */
/* @0x18ecb0 cmp r4, r3 */
/* @0x18ecb4 movge r0, r2 */
/* @0x18ecb8 bge 0x18ecf8 <_ZNK9GMGamePad14ButtonReleasedEi+0x68> */
/* @0x18ecbc ldr r3, [r5, #0x10] */
/* @0x18ecc0 lsl r4, r4, #2 */
/* @0x18ecc4 vldr s15, [r5, #28] */
/* @0x18ecc8 add r3, r3, r4 */
/* @0x18eccc vldr s14, [r3] */
/* @0x18ecd0 vcmpe.f32 s14, s15 */
/* @0x18ecd4 vmrs APSR_nzcv, fpscr */
/* @0x18ecd8 bpl 0x18ed3c <_ZNK9GMGamePad14ButtonReleasedEi+0xac> */
/* @0x18ecdc ldr r3, [r5, #0xc] */
/* @0x18ece0 add r4, r3, r4 */
/* @0x18ece4 vldr s14, [r4] */
/* @0x18ece8 vcmpe.f32 s15, s14 */
/* @0x18ecec vmrs APSR_nzcv, fpscr */
/* @0x18ecf0 bhi 0x18ed3c <_ZNK9GMGamePad14ButtonReleasedEi+0xac> */
/* @0x18ecf4 mov r0, #1 */
/* @0x18ecf8 vpop {d8} */
/* @0x18ecfc pop {r3, r4, r5, pc} */
/* @0x18ed00 ldr r2, [r0, #0x14] */
/* @0x18ed04 bl 0x18eae4 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf> */
/* @0x18ed08 mov r1, r4 */
/* @0x18ed0c ldr r2, [r5, #0x18] */
/* @0x18ed10 vmov s16, r0 */
/* @0x18ed14 mov r0, r5 */
/* @0x18ed18 bl 0x18eae4 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf> */
/* @0x18ed1c vldr s15, [r5, #28] */
/* @0x18ed20 vcmpe.f32 s16, s15 */
/* @0x18ed24 vmrs APSR_nzcv, fpscr */
/* @0x18ed28 vmov s14, r0 */
/* @0x18ed2c bpl 0x18ed3c <_ZNK9GMGamePad14ButtonReleasedEi+0xac> */
/* @0x18ed30 vcmpe.f32 s14, s15 */
/* @0x18ed34 vmrs APSR_nzcv, fpscr */
/* @0x18ed38 bge 0x18ecf4 <_ZNK9GMGamePad14ButtonReleasedEi+0x64> */
/* @0x18ed3c vpop {d8} */
/* @0x18ed40 mov r0, #0 */
/* @0x18ed44 pop {r3, r4, r5, pc} */

/* ── FUNC 0x18ed48 · GMGamePad::ButtonValue(int) const · size=60 · insn=15 */
/* @0x18ed48 subs r3, r1, #0 */
/* @0x18ed4c blt 0x18ed74 <_ZNK9GMGamePad11ButtonValueEi+0x2c> */
/* @0x18ed50 tst r3, #4096 */
/* @0x18ed54 bne 0x18ed7c <_ZNK9GMGamePad11ButtonValueEi+0x34> */
/* @0x18ed58 ldr r1, [r0, #0x4] */
/* @0x18ed5c cmp r3, r1 */
/* @0x18ed60 bge 0x18ed74 <_ZNK9GMGamePad11ButtonValueEi+0x2c> */
/* @0x18ed64 ldr r2, [r0, #0x10] */
/* @0x18ed68 add r3, r2, r3, lsl #2 */
/* @0x18ed6c ldr r0, [r3] */
/* @0x18ed70 bx lr */
/* @0x18ed74 mov r0, #0 */
/* @0x18ed78 bx lr */
/* @0x18ed7c ldr r2, [r0, #0x14] */
/* @0x18ed80 b 0x18eae4 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf> */

/* ── FUNC 0x18ed84 · GMGamePad::SetColour(int, unsigned int) · size=4 · insn=1 */
/* @0x18ed84 bx lr */

/* ── FUNC 0x18ed88 · GMGamePad::AxisCount() const · size=20 · insn=5 */
/* @0x18ed88 ldrb r3, [r0] */
/* @0x18ed8c cmp r3, #0 */
/* @0x18ed90 ldrne r0, [r0, #0x8] */
/* @0x18ed94 moveq r0, r3 */
/* @0x18ed98 bx lr */

/* ── FUNC 0x18ed9c · GMGamePad::AxisValue(int) const · size=216 · insn=54 */
/* @0x18ed9c cmp r1, #0 */
/* @0x18eda0 blt 0x18edd0 <_ZNK9GMGamePad9AxisValueEi+0x34> */
/* @0x18eda4 tst r1, #4096 */
/* @0x18eda8 beq 0x18eddc <_ZNK9GMGamePad9AxisValueEi+0x40> */
/* @0x18edac ldr r3, [r0, #0x4] */
/* @0x18edb0 bic r1, r1, #4096 */
/* @0x18edb4 cmp r1, r3 */
/* @0x18edb8 bge 0x18edd0 <_ZNK9GMGamePad9AxisValueEi+0x34> */
/* @0x18edbc ldr r3, [r0, #0x10] */
/* @0x18edc0 add r1, r3, r1, lsl #2 */
/* @0x18edc4 vldr s15, [r1] */
/* @0x18edc8 vmov r0, s15 */
/* @0x18edcc bx lr */
/* @0x18edd0 vldr s15, [pc, #152] */
/* @0x18edd4 vmov r0, s15 */
/* @0x18edd8 bx lr */
/* @0x18eddc tst r1, #32768 */
/* @0x18ede0 ldr r3, [r0, #0x8] */
/* @0x18ede4 bicne r1, r1, #32768 */
/* @0x18ede8 vmovne.f32 s13, #-1.000000e+00 */
/* @0x18edec vmoveq.f32 s13, #1.000000e+00 */
/* @0x18edf0 cmp r1, r3 */
/* @0x18edf4 bge 0x18edd0 <_ZNK9GMGamePad9AxisValueEi+0x34> */
/* @0x18edf8 vldr s14, [r0, #32] */
/* @0x18edfc ldr r3, [r0, #0x14] */
/* @0x18ee00 add r1, r3, r1, lsl #2 */
/* @0x18ee04 vldr s15, [r1] */
/* @0x18ee08 vcmpe.f32 s14, #0 */
/* @0x18ee0c vmrs APSR_nzcv, fpscr */
/* @0x18ee10 ble 0x18ee48 <_ZNK9GMGamePad9AxisValueEi+0xac> */
/* @0x18ee14 vabs.f32 s12, s15 */
/* @0x18ee18 vcmpe.f32 s14, s12 */
/* @0x18ee1c vmrs APSR_nzcv, fpscr */
/* @0x18ee20 bgt 0x18ee54 <_ZNK9GMGamePad9AxisValueEi+0xb8> */
/* @0x18ee24 vmov.f32 s11, #1.000000e+00 */
/* @0x18ee28 vmov.f32 s10, #-1.000000e+00 */
/* @0x18ee2c vcmpe.f32 s15, #0 */
/* @0x18ee30 vmrs APSR_nzcv, fpscr */
/* @0x18ee34 vcmpe.f32 s14, s11 */
/* @0x18ee38 vmovlt.f32 s15, s10 */
/* @0x18ee3c vmovge.f32 s15, s11 */
/* @0x18ee40 vmrs APSR_nzcv, fpscr */
/* @0x18ee44 blt 0x18ee5c <_ZNK9GMGamePad9AxisValueEi+0xc0> */
/* @0x18ee48 vmul.f32 s15, s15, s13 */
/* @0x18ee4c vmov r0, s15 */
/* @0x18ee50 bx lr */
/* @0x18ee54 vldr s15, [pc, #20] */
/* @0x18ee58 b 0x18ee48 <_ZNK9GMGamePad9AxisValueEi+0xac> */
/* @0x18ee5c vsub.f32 s12, s12, s14 */
/* @0x18ee60 vsub.f32 s14, s11, s14 */
/* @0x18ee64 vdiv.f32 s14, s12, s14 */
/* @0x18ee68 vmul.f32 s15, s15, s14 */
/* @0x18ee6c b 0x18ee48 <_ZNK9GMGamePad9AxisValueEi+0xac> */
/* @0x18ee70 andeq r0, r0, r0 */
