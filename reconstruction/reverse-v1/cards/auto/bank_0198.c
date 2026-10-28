/* libyoyo.so 覆盖卡组 0198
 * 函数 0x21f168..0x220324，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x21f168 · SND_Get_Effect_Environmental(int, int*) · size=4 · insn=1 */
/* @0x21f168 bx lr */

/* ── FUNC 0x21f16c · SND_3D_Set_Sound_Position(int, double, double, double) · size=4 · insn=1 */
/* @0x21f16c bx lr */

/* ── FUNC 0x21f170 · SND_3D_Set_Sound_Velocity(int, double, double, double) · size=4 · insn=1 */
/* @0x21f170 bx lr */

/* ── FUNC 0x21f174 · SND_3D_Set_Sound_Distance(int, double, double) · size=4 · insn=1 */
/* @0x21f174 bx lr */

/* ── FUNC 0x21f178 · SND_3D_Set_Sound_Cone(int, double, double, double, int, int, double) · size=4 · insn=1 */
/* @0x21f178 bx lr */

/* ── FUNC 0x21f17c · Sound_Tick() · size=148 · insn=37 */
/* @0x21f17c push {r3, r4, r5, lr} */
/* @0x21f180 ldr r4, [pc, #0x74] */
/* @0x21f184 ldr r3, [pc, #0x74] */
/* @0x21f188 add r4, pc, r4 */
/* @0x21f18c ldr r3, [r4, r3] */
/* @0x21f190 ldrb r3, [r3] */
/* @0x21f194 cmp r3, #0 */
/* @0x21f198 popne {r3, r4, r5, pc} */
/* @0x21f19c ldr r3, [pc, #0x60] */
/* @0x21f1a0 ldr r5, [r4, r3] */
/* @0x21f1a4 ldrb r3, [r5] */
/* @0x21f1a8 cmp r3, #0 */
/* @0x21f1ac bne 0x21f1e4 <_Z10Sound_Tickv+0x68> */
/* @0x21f1b0 ldr r3, [pc, #0x50] */
/* @0x21f1b4 ldr r0, [pc, r3] */
/* @0x21f1b8 cmp r0, #0 */
/* @0x21f1bc beq 0x21f1c4 <_Z10Sound_Tickv+0x48> */
/* @0x21f1c0 bl 0x221134 <_ZN13SoundHardware4TickEv> */
/* @0x21f1c4 bl 0x21bc30 <_Z10Audio_Tickv> */
/* @0x21f1c8 ldrb r3, [r5] */
/* @0x21f1cc cmp r3, #0 */
/* @0x21f1d0 popeq {r3, r4, r5, pc} */
/* @0x21f1d4 ldr r3, [pc, #0x30] */
/* @0x21f1d8 ldr r0, [r4, r3] */
/* @0x21f1dc pop {r3, r4, r5, lr} */
/* @0x21f1e0 b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x21f1e4 ldr r3, [pc, #0x20] */
/* @0x21f1e8 mov r1, #6 */
/* @0x21f1ec mov r2, #17 */
/* @0x21f1f0 ldr r0, [r4, r3] */
/* @0x21f1f4 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x21f1f8 b 0x21f1b0 <_Z10Sound_Tickv+0x34> */
/* @0x21f1fc andseq r2, sp, r8, asr #21 */
/* @0x21f200 .word 0xffffd3fc */
/* @0x21f204 .word 0xffffbf18 */
/* @0x21f208 subseq r6, r3, r0, ror r1 */
/* @0x21f20c .word 0xffffbf1c */

/* ── FUNC 0x21f210 · INITIALIZE_Sound_DirectX() · size=4 · insn=1 */
/* @0x21f210 bx lr */

/* ── FUNC 0x21f214 · FINALIZATION_Sound_DirectX() · size=4 · insn=1 */
/* @0x21f214 bx lr */

/* ── FUNC 0x21f218 · cARRAY_CLASS<CSound*>::~cARRAY_CLASS() · size=204 · insn=51 */
/* @0x21f218 ldr r12, [r0] */
/* @0x21f21c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x21f220 cmp r12, #0 */
/* @0x21f224 mov r7, r0 */
/* @0x21f228 beq 0x21f2cc <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0xb4> */
/* @0x21f22c ldr r5, [r0, #0x4] */
/* @0x21f230 cmp r5, #0 */
/* @0x21f234 beq 0x21f2d4 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0xbc> */
/* @0x21f238 cmp r12, #0 */
/* @0x21f23c ble 0x21f2b4 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0x9c> */
/* @0x21f240 mov r4, #0 */
/* @0x21f244 mov r9, r4 */
/* @0x21f248 ldr r1, [r5] */
/* @0x21f24c movw r3, #0xfeee */
/* @0x21f250 movt r3, #0xfeee */
/* @0x21f254 movw r2, #0xfeee */
/* @0x21f258 cmp r1, r3 */
/* @0x21f25c movt r2, #0xfeee */
/* @0x21f260 lsl r8, r4, #2 */
/* @0x21f264 beq 0x21f2a8 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0x90> */
/* @0x21f268 ldr r6, [r5, r4, lsl #2] */
/* @0x21f26c add r3, r5, r8 */
/* @0x21f270 cmp r6, #0 */
/* @0x21f274 mov r0, r6 */
/* @0x21f278 beq 0x21f2a8 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0x90> */
/* @0x21f27c ldr r1, [r6] */
/* @0x21f280 cmp r1, r2 */
/* @0x21f284 beq 0x21f2a0 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0x88> */
/* @0x21f288 bl 0x215384 <_ZN6CSoundD2Ev> */
/* @0x21f28c mov r0, r6 */
/* @0x21f290 bl 0x27d1d0 <_ZdlPv> */
/* @0x21f294 ldr r3, [r7, #0x4] */
/* @0x21f298 ldr r12, [r7] */
/* @0x21f29c add r3, r3, r8 */
/* @0x21f2a0 str r9, [r3] */
/* @0x21f2a4 ldr r5, [r7, #0x4] */
/* @0x21f2a8 add r4, r4, #1 */
/* @0x21f2ac cmp r4, r12 */
/* @0x21f2b0 blt 0x21f248 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0x30> */
/* @0x21f2b4 mov r0, r5 */
/* @0x21f2b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f2bc mov r3, #0 */
/* @0x21f2c0 str r3, [r7, #0x4] */
/* @0x21f2c4 mov r3, #0 */
/* @0x21f2c8 str r3, [r7] */
/* @0x21f2cc mov r0, r7 */
/* @0x21f2d0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21f2d4 mov r0, r5 */
/* @0x21f2d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f2dc str r5, [r7, #0x4] */
/* @0x21f2e0 b 0x21f2c4 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0xac> */

/* ── FUNC 0x21f218 · cARRAY_CLASS<CSound*>::~cARRAY_CLASS() · alias of the symbol above · insn=0 */

/* ── FUNC 0x21f2e4 · Sound_Init() · size=440 · insn=110 */
/* @0x21f2e4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21f2e8 ldr r8, [pc, #0x188] */
/* @0x21f2ec add r8, pc, r8 */
/* @0x21f2f0 ldr r3, [r8] */
/* @0x21f2f4 cmp r3, #0 */
/* @0x21f2f8 beq 0x21f3bc <_Z10Sound_Initv+0xd8> */
/* @0x21f2fc ldr r5, [r8, #0x4] */
/* @0x21f300 cmp r5, #0 */
/* @0x21f304 beq 0x21f468 <_Z10Sound_Initv+0x184> */
/* @0x21f308 cmp r3, #0 */
/* @0x21f30c ble 0x21f394 <_Z10Sound_Initv+0xb0> */
/* @0x21f310 ldr r10, [pc, #0x164] */
/* @0x21f314 mov r4, #0 */
/* @0x21f318 ldr r11, [pc, #0x160] */
/* @0x21f31c mov r9, r4 */
/* @0x21f320 add r10, pc, r10 */
/* @0x21f324 add r11, pc, r11 */
/* @0x21f328 ldr r1, [r5] */
/* @0x21f32c movw r3, #0xfeee */
/* @0x21f330 movt r3, #0xfeee */
/* @0x21f334 movw r2, #0xfeee */
/* @0x21f338 cmp r1, r3 */
/* @0x21f33c movt r2, #0xfeee */
/* @0x21f340 lsl r7, r4, #2 */
/* @0x21f344 beq 0x21f384 <_Z10Sound_Initv+0xa0> */
/* @0x21f348 ldr r6, [r5, r4, lsl #2] */
/* @0x21f34c add r3, r5, r7 */
/* @0x21f350 cmp r6, #0 */
/* @0x21f354 mov r0, r6 */
/* @0x21f358 beq 0x21f384 <_Z10Sound_Initv+0xa0> */
/* @0x21f35c ldr r1, [r6] */
/* @0x21f360 cmp r1, r2 */
/* @0x21f364 beq 0x21f37c <_Z10Sound_Initv+0x98> */
/* @0x21f368 bl 0x215384 <_ZN6CSoundD2Ev> */
/* @0x21f36c mov r0, r6 */
/* @0x21f370 bl 0x27d1d0 <_ZdlPv> */
/* @0x21f374 ldr r3, [r11, #0x4] */
/* @0x21f378 add r3, r3, r7 */
/* @0x21f37c str r9, [r3] */
/* @0x21f380 ldr r5, [r10, #0x4] */
/* @0x21f384 ldr r3, [r8] */
/* @0x21f388 add r4, r4, #1 */
/* @0x21f38c cmp r4, r3 */
/* @0x21f390 blt 0x21f328 <_Z10Sound_Initv+0x44> */
/* @0x21f394 mov r0, r5 */
/* @0x21f398 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f39c ldr r3, [pc, #0xe0] */
/* @0x21f3a0 mov r2, #0 */
/* @0x21f3a4 add r3, pc, r3 */
/* @0x21f3a8 str r2, [r3, #0x4] */
/* @0x21f3ac ldr r3, [pc, #0xd4] */
/* @0x21f3b0 mov r2, #0 */
/* @0x21f3b4 add r3, pc, r3 */
/* @0x21f3b8 str r2, [r3] */
/* @0x21f3bc ldr r5, [pc, #0xc8] */
/* @0x21f3c0 add r5, pc, r5 */
/* @0x21f3c4 ldr r6, [r5, #0xc] */
/* @0x21f3c8 cmp r6, #0 */
/* @0x21f3cc beq 0x21f458 <_Z10Sound_Initv+0x174> */
/* @0x21f3d0 ldr r3, [r5, #0x8] */
/* @0x21f3d4 cmp r3, #0 */
/* @0x21f3d8 ble 0x21f428 <_Z10Sound_Initv+0x144> */
/* @0x21f3dc ldr r8, [pc, #0xac] */
/* @0x21f3e0 mov r4, #0 */
/* @0x21f3e4 mov r7, r4 */
/* @0x21f3e8 add r8, pc, r8 */
/* @0x21f3ec ldr r0, [r6, r4, lsl #2] */
/* @0x21f3f0 lsl r6, r4, #2 */
/* @0x21f3f4 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x21f3f8 cmp r0, #0 */
/* @0x21f3fc beq 0x21f40c <_Z10Sound_Initv+0x128> */
/* @0x21f400 ldr r3, [r8, #0xc] */
/* @0x21f404 ldr r0, [r3, r4, lsl #2] */
/* @0x21f408 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f40c ldr r2, [r5, #0x8] */
/* @0x21f410 add r4, r4, #1 */
/* @0x21f414 ldr r3, [r5, #0xc] */
/* @0x21f418 cmp r4, r2 */
/* @0x21f41c str r7, [r3, r6] */
/* @0x21f420 ldr r6, [r5, #0xc] */
/* @0x21f424 blt 0x21f3ec <_Z10Sound_Initv+0x108> */
/* @0x21f428 mov r0, r6 */
/* @0x21f42c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f430 ldr r3, [pc, #0x5c] */
/* @0x21f434 mov r2, #0 */
/* @0x21f438 add r3, pc, r3 */
/* @0x21f43c str r2, [r3, #0xc] */
/* @0x21f440 ldr r3, [pc, #0x50] */
/* @0x21f444 mov r2, #0 */
/* @0x21f448 add r3, pc, r3 */
/* @0x21f44c str r2, [r3, #0x8] */
/* @0x21f450 str r2, [r3, #0x10] */
/* @0x21f454 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21f458 mov r0, r6 */
/* @0x21f45c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f460 str r6, [r5, #0xc] */
/* @0x21f464 b 0x21f440 <_Z10Sound_Initv+0x15c> */
/* @0x21f468 mov r0, r5 */
/* @0x21f46c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f470 str r5, [r8, #0x4] */
/* @0x21f474 b 0x21f3ac <_Z10Sound_Initv+0xc8> */
/* @0x21f478 subseq r6, r3, r12, asr #32 */
/* @0x21f47c subseq r6, r3, r8, lsl r0 */
/* @0x21f480 subseq r6, r3, r4, lsl r0 */
/* @0x21f484 .word 0x00535f94 */
/* @0x21f488 subseq r5, r3, r4, lsl #31 */
/* @0x21f48c subseq r5, r3, r8, ror pc */
/* @0x21f490 subseq r5, r3, r0, asr pc */
/* @0x21f494 subseq r5, r3, r0, lsl #30 */
/* @0x21f498 ldrsheq r5, [r3], #-224 */

/* ── FUNC 0x21f49c · FINALIZE_Sound() · size=404 · insn=101 */
/* @0x21f49c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21f4a0 ldr r3, [pc, #0x168] */
/* @0x21f4a4 ldr r8, [pc, r3] */
/* @0x21f4a8 cmp r8, #0 */
/* @0x21f4ac ble 0x21f528 <_Z14FINALIZE_Soundv+0x8c> */
/* @0x21f4b0 ldr r7, [pc, #0x15c] */
/* @0x21f4b4 mov r4, #0 */
/* @0x21f4b8 ldr r10, [pc, #0x158] */
/* @0x21f4bc mov r5, r4 */
/* @0x21f4c0 add r7, pc, r7 */
/* @0x21f4c4 mov r9, r4 */
/* @0x21f4c8 add r10, pc, r10 */
/* @0x21f4cc mov r2, r8 */
/* @0x21f4d0 b 0x21f4f0 <_Z14FINALIZE_Soundv+0x54> */
/* @0x21f4d4 ldr r3, [r10, #0x4] */
/* @0x21f4d8 add r3, r3, r4 */
/* @0x21f4dc add r5, r5, #1 */
/* @0x21f4e0 add r4, r4, #4 */
/* @0x21f4e4 cmp r5, r8 */
/* @0x21f4e8 str r9, [r3] */
/* @0x21f4ec beq 0x21f52c <_Z14FINALIZE_Soundv+0x90> */
/* @0x21f4f0 cmp r5, r2 */
/* @0x21f4f4 bge 0x21f4d4 <_Z14FINALIZE_Soundv+0x38> */
/* @0x21f4f8 ldr r1, [r7, #0x4] */
/* @0x21f4fc add r3, r1, r4 */
/* @0x21f500 ldr r6, [r1, r4] */
/* @0x21f504 cmp r6, #0 */
/* @0x21f508 mov r0, r6 */
/* @0x21f50c beq 0x21f4dc <_Z14FINALIZE_Soundv+0x40> */
/* @0x21f510 bl 0x215384 <_ZN6CSoundD2Ev> */
/* @0x21f514 mov r0, r6 */
/* @0x21f518 bl 0x27d1d0 <_ZdlPv> */
/* @0x21f51c ldm r7, {r2, r3} */
/* @0x21f520 add r3, r3, r4 */
/* @0x21f524 b 0x21f4dc <_Z14FINALIZE_Soundv+0x40> */
/* @0x21f528 mov r2, r8 */
/* @0x21f52c cmp r2, #0 */
/* @0x21f530 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21f534 ldr r8, [pc, #0xe0] */
/* @0x21f538 add r8, pc, r8 */
/* @0x21f53c ldr r5, [r8, #0x4] */
/* @0x21f540 cmp r5, #0 */
/* @0x21f544 beq 0x21f600 <_Z14FINALIZE_Soundv+0x164> */
/* @0x21f548 cmp r2, #0 */
/* @0x21f54c ble 0x21f5d4 <_Z14FINALIZE_Soundv+0x138> */
/* @0x21f550 ldr r10, [pc, #0xc8] */
/* @0x21f554 mov r4, #0 */
/* @0x21f558 ldr r11, [pc, #0xc4] */
/* @0x21f55c mov r9, r4 */
/* @0x21f560 add r10, pc, r10 */
/* @0x21f564 add r11, pc, r11 */
/* @0x21f568 ldr r1, [r5] */
/* @0x21f56c movw r3, #0xfeee */
/* @0x21f570 movt r3, #0xfeee */
/* @0x21f574 movw r2, #0xfeee */
/* @0x21f578 cmp r1, r3 */
/* @0x21f57c movt r2, #0xfeee */
/* @0x21f580 lsl r7, r4, #2 */
/* @0x21f584 beq 0x21f5c4 <_Z14FINALIZE_Soundv+0x128> */
/* @0x21f588 ldr r6, [r5, r4, lsl #2] */
/* @0x21f58c add r3, r5, r7 */
/* @0x21f590 cmp r6, #0 */
/* @0x21f594 mov r0, r6 */
/* @0x21f598 beq 0x21f5c4 <_Z14FINALIZE_Soundv+0x128> */
/* @0x21f59c ldr r1, [r6] */
/* @0x21f5a0 cmp r1, r2 */
/* @0x21f5a4 beq 0x21f5bc <_Z14FINALIZE_Soundv+0x120> */
/* @0x21f5a8 bl 0x215384 <_ZN6CSoundD2Ev> */
/* @0x21f5ac mov r0, r6 */
/* @0x21f5b0 bl 0x27d1d0 <_ZdlPv> */
/* @0x21f5b4 ldr r3, [r11, #0x4] */
/* @0x21f5b8 add r3, r3, r7 */
/* @0x21f5bc str r9, [r3] */
/* @0x21f5c0 ldr r5, [r10, #0x4] */
/* @0x21f5c4 ldr r3, [r8] */
/* @0x21f5c8 add r4, r4, #1 */
/* @0x21f5cc cmp r4, r3 */
/* @0x21f5d0 blt 0x21f568 <_Z14FINALIZE_Soundv+0xcc> */
/* @0x21f5d4 mov r0, r5 */
/* @0x21f5d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f5dc ldr r3, [pc, #0x44] */
/* @0x21f5e0 mov r2, #0 */
/* @0x21f5e4 add r3, pc, r3 */
/* @0x21f5e8 str r2, [r3, #0x4] */
/* @0x21f5ec ldr r3, [pc, #0x38] */
/* @0x21f5f0 mov r2, #0 */
/* @0x21f5f4 add r3, pc, r3 */
/* @0x21f5f8 str r2, [r3] */
/* @0x21f5fc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21f600 mov r0, r5 */
/* @0x21f604 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f608 str r5, [r8, #0x4] */
/* @0x21f60c b 0x21f5ec <_Z14FINALIZE_Soundv+0x150> */
/* @0x21f610 .word 0x00535e94 */
/* @0x21f614 subseq r5, r3, r8, ror lr */
/* @0x21f618 subseq r5, r3, r0, ror lr */
/* @0x21f61c subseq r5, r3, r0, lsl #28 */
/* @0x21f620 ldrsbeq r5, [r3], #-216 */
/* @0x21f624 ldrsbeq r5, [r3], #-212 */
/* @0x21f628 subseq r5, r3, r4, asr sp */
/* @0x21f62c subseq r5, r3, r4, asr #26 */

/* ── FUNC 0x21f630 · Sound_Load(unsigned char*, unsigned int, unsigned char*) · size=932 · insn=233 */
/* @0x21f630 ldr r3, [pc, #0x34c] */
/* @0x21f634 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21f638 ldr r3, [pc, r3] */
/* @0x21f63c sub sp, sp, #28 */
/* @0x21f640 ldr r1, [pc, #0x340] */
/* @0x21f644 ldr r6, [pc, #0x340] */
/* @0x21f648 str r0, [sp, #0xc] */
/* @0x21f64c add r1, pc, r1 */
/* @0x21f650 ldr r0, [r3] */
/* @0x21f654 add r6, pc, r6 */
/* @0x21f658 str r2, [sp, #0x10] */
/* @0x21f65c ldr r3, [r0] */
/* @0x21f660 ldr r3, [r3, #0xc] */
/* @0x21f664 blx r3 */
/* @0x21f668 ldr r3, [sp, #0xc] */
/* @0x21f66c ldr r2, [r6] */
/* @0x21f670 ldr r9, [r3] */
/* @0x21f674 cmp r9, r2 */
/* @0x21f678 str r9, [r6, #0x10] */
/* @0x21f67c moveq r6, r9 */
/* @0x21f680 beq 0x21f76c <_Z10Sound_LoadPhjS_+0x13c> */
/* @0x21f684 cmp r9, #0 */
/* @0x21f688 ldr r3, [r6, #0x4] */
/* @0x21f68c bne 0x21f740 <_Z10Sound_LoadPhjS_+0x110> */
/* @0x21f690 cmp r3, #0 */
/* @0x21f694 beq 0x21f740 <_Z10Sound_LoadPhjS_+0x110> */
/* @0x21f698 cmp r2, #0 */
/* @0x21f69c ble 0x21f724 <_Z10Sound_LoadPhjS_+0xf4> */
/* @0x21f6a0 ldr r10, [pc, #0x2e8] */
/* @0x21f6a4 mov r4, r9 */
/* @0x21f6a8 ldr r8, [pc, #0x2e4] */
/* @0x21f6ac mov r7, r9 */
/* @0x21f6b0 add r10, pc, r10 */
/* @0x21f6b4 add r8, pc, r8 */
/* @0x21f6b8 ldr r0, [r3] */
/* @0x21f6bc movw r2, #0xfeee */
/* @0x21f6c0 movt r2, #0xfeee */
/* @0x21f6c4 movw r1, #0xfeee */
/* @0x21f6c8 cmp r0, r2 */
/* @0x21f6cc movt r1, #0xfeee */
/* @0x21f6d0 lsl r11, r4, #2 */
/* @0x21f6d4 beq 0x21f714 <_Z10Sound_LoadPhjS_+0xe4> */
/* @0x21f6d8 ldr r5, [r3, r4, lsl #2] */
/* @0x21f6dc add r2, r3, r11 */
/* @0x21f6e0 cmp r5, #0 */
/* @0x21f6e4 mov r0, r5 */
/* @0x21f6e8 beq 0x21f714 <_Z10Sound_LoadPhjS_+0xe4> */
/* @0x21f6ec ldr r3, [r5] */
/* @0x21f6f0 cmp r3, r1 */
/* @0x21f6f4 beq 0x21f70c <_Z10Sound_LoadPhjS_+0xdc> */
/* @0x21f6f8 bl 0x215384 <_ZN6CSoundD2Ev> */
/* @0x21f6fc mov r0, r5 */
/* @0x21f700 bl 0x27d1d0 <_ZdlPv> */
/* @0x21f704 ldr r2, [r8, #0x4] */
/* @0x21f708 add r2, r2, r11 */
/* @0x21f70c str r7, [r2] */
/* @0x21f710 ldr r3, [r10, #0x4] */
/* @0x21f714 ldr r2, [r6] */
/* @0x21f718 add r4, r4, #1 */
/* @0x21f71c cmp r4, r2 */
/* @0x21f720 blt 0x21f6b8 <_Z10Sound_LoadPhjS_+0x88> */
/* @0x21f724 mov r0, r3 */
/* @0x21f728 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f72c ldr r3, [pc, #0x264] */
/* @0x21f730 mov r2, #0 */
/* @0x21f734 add r3, pc, r3 */
/* @0x21f738 str r2, [r3, #0x4] */
/* @0x21f73c b 0x21f75c <_Z10Sound_LoadPhjS_+0x12c> */
/* @0x21f740 lsls r4, r9, #2 */
/* @0x21f744 mov r0, r3 */
/* @0x21f748 bne 0x21f950 <_Z10Sound_LoadPhjS_+0x320> */
/* @0x21f74c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f750 ldr r3, [pc, #0x244] */
/* @0x21f754 add r3, pc, r3 */
/* @0x21f758 str r4, [r3, #0x4] */
/* @0x21f75c ldr r3, [pc, #0x23c] */
/* @0x21f760 add r3, pc, r3 */
/* @0x21f764 ldr r6, [r3, #0x10] */
/* @0x21f768 str r9, [r3] */
/* @0x21f76c cmp r6, #0 */
/* @0x21f770 bne 0x21f8ec <_Z10Sound_LoadPhjS_+0x2bc> */
/* @0x21f774 ldr r3, [pc, #0x228] */
/* @0x21f778 add r3, pc, r3 */
/* @0x21f77c ldr r0, [r3, #0xc] */
/* @0x21f780 cmp r0, #0 */
/* @0x21f784 beq 0x21f92c <_Z10Sound_LoadPhjS_+0x2fc> */
/* @0x21f788 ldr r2, [r3, #0x8] */
/* @0x21f78c cmp r2, #0 */
/* @0x21f790 ble 0x21f7e4 <_Z10Sound_LoadPhjS_+0x1b4> */
/* @0x21f794 ldr r10, [pc, #0x20c] */
/* @0x21f798 mov r8, r3 */
/* @0x21f79c mov r4, r6 */
/* @0x21f7a0 mov r7, r6 */
/* @0x21f7a4 add r10, pc, r10 */
/* @0x21f7a8 ldr r0, [r0, r4, lsl #2] */
/* @0x21f7ac lsl r5, r4, #2 */
/* @0x21f7b0 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x21f7b4 cmp r0, #0 */
/* @0x21f7b8 beq 0x21f7c8 <_Z10Sound_LoadPhjS_+0x198> */
/* @0x21f7bc ldr r3, [r10, #0xc] */
/* @0x21f7c0 ldr r0, [r3, r4, lsl #2] */
/* @0x21f7c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f7c8 ldr r2, [r8, #0x8] */
/* @0x21f7cc add r4, r4, #1 */
/* @0x21f7d0 ldr r3, [r8, #0xc] */
/* @0x21f7d4 cmp r4, r2 */
/* @0x21f7d8 str r7, [r3, r5] */
/* @0x21f7dc ldr r0, [r8, #0xc] */
/* @0x21f7e0 blt 0x21f7a8 <_Z10Sound_LoadPhjS_+0x178> */
/* @0x21f7e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f7e8 ldr r3, [pc, #0x1bc] */
/* @0x21f7ec mov r2, #0 */
/* @0x21f7f0 add r3, pc, r3 */
/* @0x21f7f4 str r2, [r3, #0xc] */
/* @0x21f7f8 ldr r10, [pc, #0x1b0] */
/* @0x21f7fc cmp r9, #0 */
/* @0x21f800 add r10, pc, r10 */
/* @0x21f804 str r6, [r10, #0x8] */
/* @0x21f808 beq 0x21f944 <_Z10Sound_LoadPhjS_+0x314> */
/* @0x21f80c ldr r3, [pc, #0x1a0] */
/* @0x21f810 mov r7, r10 */
/* @0x21f814 ldr r8, [sp, #0xc] */
/* @0x21f818 mov r4, #0 */
/* @0x21f81c add r3, pc, r3 */
/* @0x21f820 str r9, [sp, #0xc] */
/* @0x21f824 str r3, [sp, #0x14] */
/* @0x21f828 b 0x21f8d8 <_Z10Sound_LoadPhjS_+0x2a8> */
/* @0x21f82c ldr r9, [pc, #0x184] */
/* @0x21f830 ldr r9, [pc, r9] */
/* @0x21f834 ldr r11, [r9] */
/* @0x21f838 adds r1, r11, r5 */
/* @0x21f83c beq 0x21f97c <_Z10Sound_LoadPhjS_+0x34c> */
/* @0x21f840 mov r0, #64 */
/* @0x21f844 str r1, [sp, #0x8] */
/* @0x21f848 bl 0x27c524 <_Znwj> */
/* @0x21f84c mov r6, r0 */
/* @0x21f850 bl 0x215354 <_ZN6CSoundC2Ev> */
/* @0x21f854 ldr r1, [sp, #0x8] */
/* @0x21f858 mov r0, r6 */
/* @0x21f85c ldr r2, [sp, #0x10] */
/* @0x21f860 bl 0x215498 <_ZN6CSound13LoadFromChunkEP7YYSoundPh> */
/* @0x21f864 ldr r12, [r11, r5] */
/* @0x21f868 cmp r12, #0 */
/* @0x21f86c ldrne r3, [r9] */
/* @0x21f870 moveq r11, r12 */
/* @0x21f874 addne r11, r3, r12 */
/* @0x21f878 mov r0, r11 */
/* @0x21f87c bl 0xb6538 <strlen@plt> */
/* @0x21f880 ldr r1, [sp, #0x14] */
/* @0x21f884 mov r3, #1 */
/* @0x21f888 mov r2, #95 */
/* @0x21f88c add r0, r0, r3 */
/* @0x21f890 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x21f894 mov r1, r11 */
/* @0x21f898 mov r5, r0 */
/* @0x21f89c bl 0xb65a4 <strcpy@plt> */
/* @0x21f8a0 ldr r2, [r10, #0xc] */
/* @0x21f8a4 lsl r11, r4, #2 */
/* @0x21f8a8 ldr r0, [r2, r4, lsl #2] */
/* @0x21f8ac cmp r0, #0 */
/* @0x21f8b0 beq 0x21f8b8 <_Z10Sound_LoadPhjS_+0x288> */
/* @0x21f8b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f8b8 ldr r2, [r7, #0x4] */
/* @0x21f8bc add r4, r4, #1 */
/* @0x21f8c0 ldr r3, [sp, #0xc] */
/* @0x21f8c4 str r6, [r2, r11] */
/* @0x21f8c8 cmp r4, r3 */
/* @0x21f8cc ldr r2, [r7, #0xc] */
/* @0x21f8d0 str r5, [r2, r11] */
/* @0x21f8d4 beq 0x21f944 <_Z10Sound_LoadPhjS_+0x314> */
/* @0x21f8d8 ldr r5, [r8, #0x4]! */
/* @0x21f8dc cmp r5, #0 */
/* @0x21f8e0 bne 0x21f82c <_Z10Sound_LoadPhjS_+0x1fc> */
/* @0x21f8e4 mov r6, r5 */
/* @0x21f8e8 b 0x21f8a0 <_Z10Sound_LoadPhjS_+0x270> */
/* @0x21f8ec lsls r1, r6, #2 */
/* @0x21f8f0 beq 0x21f920 <_Z10Sound_LoadPhjS_+0x2f0> */
/* @0x21f8f4 ldr r4, [pc, #0xc0] */
/* @0x21f8f8 mov r3, #0 */
/* @0x21f8fc ldr r2, [pc, #0xbc] */
/* @0x21f900 add r4, pc, r4 */
/* @0x21f904 str r3, [sp] */
/* @0x21f908 add r2, pc, r2 */
/* @0x21f90c mov r3, #92 */
/* @0x21f910 ldr r0, [r4, #0xc] */
/* @0x21f914 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21f918 str r0, [r4, #0xc] */
/* @0x21f91c b 0x21f7f8 <_Z10Sound_LoadPhjS_+0x1c8> */
/* @0x21f920 ldr r3, [pc, #0x9c] */
/* @0x21f924 add r3, pc, r3 */
/* @0x21f928 ldr r0, [r3, #0xc] */
/* @0x21f92c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21f930 ldr r3, [pc, #0x90] */
/* @0x21f934 mov r2, #0 */
/* @0x21f938 add r3, pc, r3 */
/* @0x21f93c str r2, [r3, #0xc] */
/* @0x21f940 b 0x21f7f8 <_Z10Sound_LoadPhjS_+0x1c8> */
/* @0x21f944 mov r0, #1 */
/* @0x21f948 add sp, sp, #28 */
/* @0x21f94c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21f950 ldr r2, [pc, #0x74] */
/* @0x21f954 mov r3, #0 */
/* @0x21f958 mov r1, r4 */
/* @0x21f95c str r3, [sp] */
/* @0x21f960 add r2, pc, r2 */
/* @0x21f964 mov r3, #135 */
/* @0x21f968 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21f96c ldr r3, [pc, #0x5c] */
/* @0x21f970 add r3, pc, r3 */
/* @0x21f974 str r0, [r3, #0x4] */
/* @0x21f978 b 0x21f75c <_Z10Sound_LoadPhjS_+0x12c> */
/* @0x21f97c mov r5, r1 */
/* @0x21f980 b 0x21f8e4 <_Z10Sound_LoadPhjS_+0x2b4> */
/* @0x21f984 ldrsbeq lr, [r12], -r12 */
/* @0x21f988 andseq r5, r3, r0, lsr r1 */
/* @0x21f98c subseq r5, r3, r4, ror #25 */
/* @0x21f990 subseq r5, r3, r8, lsl #25 */
/* @0x21f994 subseq r5, r3, r4, lsl #25 */
/* @0x21f998 subseq r5, r3, r4, lsl #24 */
/* @0x21f99c subseq r5, r3, r4, ror #23 */
/* @0x21f9a0 ldrsbeq r5, [r3], #-184 */
/* @0x21f9a4 subseq r5, r3, r0, asr #23 */
/* @0x21f9a8 .word 0x00535b94 */
/* @0x21f9ac subseq r5, r3, r8, asr #22 */
/* @0x21f9b0 subseq r5, r3, r8, lsr r11 */
/* @0x21f9b4 ldrheq r4, [r3], -r0 */
/* @0x21f9b8 andseq lr, r12, r4, lsl r1 */
/* @0x21f9bc subseq r5, r3, r8, lsr r10 */
/* @0x21f9c0 andseq r4, r3, r12, asr #8 */
/* @0x21f9c4 subseq r5, r3, r4, lsl r10 */
/* @0x21f9c8 subseq r5, r3, r0, lsl #20 */
/* @0x21f9cc andseq r4, r3, r12, lsr #28 */
/* @0x21f9d0 subseq r5, r3, r8, asr #19 */

/* ── FUNC 0x21f9d4 · Sound_WAVs(unsigned char*, unsigned int, unsigned char*) · size=152 · insn=38 */
/* @0x21f9d4 push {r3, r4, r5, lr} */
/* @0x21f9d8 mov r4, r0 */
/* @0x21f9dc ldr r3, [pc, #0x78] */
/* @0x21f9e0 ldr r1, [pc, #0x78] */
/* @0x21f9e4 ldr r3, [pc, r3] */
/* @0x21f9e8 add r1, pc, r1 */
/* @0x21f9ec ldr r0, [r3] */
/* @0x21f9f0 ldr r2, [r0] */
/* @0x21f9f4 ldr r3, [r2, #0xc] */
/* @0x21f9f8 blx r3 */
/* @0x21f9fc ldr r2, [pc, #0x60] */
/* @0x21fa00 add r0, r4, #4 */
/* @0x21fa04 add r2, pc, r2 */
/* @0x21fa08 ldr r4, [r2] */
/* @0x21fa0c cmp r4, #0 */
/* @0x21fa10 ble 0x21fa54 <_Z10Sound_WAVsPhjS_+0x80> */
/* @0x21fa14 ldr r3, [pc, #0x4c] */
/* @0x21fa18 ldr r1, [r2, #0x4] */
/* @0x21fa1c ldr r3, [pc, r3] */
/* @0x21fa20 add r4, r1, r4, lsl #2 */
/* @0x21fa24 ldr r5, [r3] */
/* @0x21fa28 ldr r2, [r1], #4 */
/* @0x21fa2c cmp r2, #0 */
/* @0x21fa30 beq 0x21fa4c <_Z10Sound_WAVsPhjS_+0x78> */
/* @0x21fa34 ldr r3, [r2, #0x3c] */
/* @0x21fa38 ldr r3, [r0, r3, lsl #2] */
/* @0x21fa3c cmp r3, #0 */
/* @0x21fa40 add r12, r3, r5 */
/* @0x21fa44 moveq r12, r3 */
/* @0x21fa48 str r12, [r2, #0x38] */
/* @0x21fa4c cmp r1, r4 */
/* @0x21fa50 bne 0x21fa28 <_Z10Sound_WAVsPhjS_+0x54> */
/* @0x21fa54 mov r0, #1 */
/* @0x21fa58 pop {r3, r4, r5, pc} */
/* @0x21fa5c andseq sp, r12, r0, lsr sp */
/* @0x21fa60 andseq r4, r3, r8, lsl lr */
/* @0x21fa64 subseq r5, r3, r4, lsr r9 */
/* @0x21fa68 andseq sp, r12, r8, lsr #30 */

/* ── FUNC 0x21fa6c · Sound_End() · size=256 · insn=64 */
/* @0x21fa6c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21fa70 ldr r8, [pc, #0xe0] */
/* @0x21fa74 add r8, pc, r8 */
/* @0x21fa78 ldr r3, [r8] */
/* @0x21fa7c cmp r3, #0 */
/* @0x21fa80 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21fa84 ldr r5, [r8, #0x4] */
/* @0x21fa88 cmp r5, #0 */
/* @0x21fa8c beq 0x21fb48 <_Z9Sound_Endv+0xdc> */
/* @0x21fa90 cmp r3, #0 */
/* @0x21fa94 ble 0x21fb1c <_Z9Sound_Endv+0xb0> */
/* @0x21fa98 ldr r10, [pc, #0xbc] */
/* @0x21fa9c mov r4, #0 */
/* @0x21faa0 ldr r11, [pc, #0xb8] */
/* @0x21faa4 mov r9, r4 */
/* @0x21faa8 add r10, pc, r10 */
/* @0x21faac add r11, pc, r11 */
/* @0x21fab0 ldr r1, [r5] */
/* @0x21fab4 movw r3, #0xfeee */
/* @0x21fab8 movt r3, #0xfeee */
/* @0x21fabc movw r2, #0xfeee */
/* @0x21fac0 cmp r1, r3 */
/* @0x21fac4 movt r2, #0xfeee */
/* @0x21fac8 lsl r7, r4, #2 */
/* @0x21facc beq 0x21fb0c <_Z9Sound_Endv+0xa0> */
/* @0x21fad0 ldr r6, [r5, r4, lsl #2] */
/* @0x21fad4 add r3, r5, r7 */
/* @0x21fad8 cmp r6, #0 */
/* @0x21fadc mov r0, r6 */
/* @0x21fae0 beq 0x21fb0c <_Z9Sound_Endv+0xa0> */
/* @0x21fae4 ldr r1, [r6] */
/* @0x21fae8 cmp r1, r2 */
/* @0x21faec beq 0x21fb04 <_Z9Sound_Endv+0x98> */
/* @0x21faf0 bl 0x215384 <_ZN6CSoundD2Ev> */
/* @0x21faf4 mov r0, r6 */
/* @0x21faf8 bl 0x27d1d0 <_ZdlPv> */
/* @0x21fafc ldr r3, [r11, #0x4] */
/* @0x21fb00 add r3, r3, r7 */
/* @0x21fb04 str r9, [r3] */
/* @0x21fb08 ldr r5, [r10, #0x4] */
/* @0x21fb0c ldr r3, [r8] */
/* @0x21fb10 add r4, r4, #1 */
/* @0x21fb14 cmp r4, r3 */
/* @0x21fb18 blt 0x21fab0 <_Z9Sound_Endv+0x44> */
/* @0x21fb1c mov r0, r5 */
/* @0x21fb20 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21fb24 ldr r3, [pc, #0x38] */
/* @0x21fb28 mov r2, #0 */
/* @0x21fb2c add r3, pc, r3 */
/* @0x21fb30 str r2, [r3, #0x4] */
/* @0x21fb34 ldr r3, [pc, #0x2c] */
/* @0x21fb38 mov r2, #0 */
/* @0x21fb3c add r3, pc, r3 */
/* @0x21fb40 str r2, [r3] */
/* @0x21fb44 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21fb48 mov r0, r5 */
/* @0x21fb4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21fb50 str r5, [r8, #0x4] */
/* @0x21fb54 b 0x21fb34 <_Z9Sound_Endv+0xc8> */
/* @0x21fb58 subseq r5, r3, r4, asr #17 */
/* @0x21fb5c .word 0x00535890 */
/* @0x21fb60 subseq r5, r3, r12, lsl #17 */
/* @0x21fb64 subseq r5, r3, r12, lsl #16 */
/* @0x21fb68 ldrsheq r5, [r3], #-124 */

/* ── FUNC 0x21fb6c · Sound_Number() · size=20 · insn=5 */
/* @0x21fb6c ldr r3, [pc, #0x8] */
/* @0x21fb70 add r3, pc, r3 */
/* @0x21fb74 ldr r0, [r3, #0x10] */
/* @0x21fb78 bx lr */
/* @0x21fb7c subseq r5, r3, r8, asr #15 */

/* ── FUNC 0x21fb80 · Sound_Prepare() · size=80 · insn=20 */
/* @0x21fb80 push {r3, r4, r5, lr} */
/* @0x21fb84 mov r4, #0 */
/* @0x21fb88 ldr r5, [pc, #0x3c] */
/* @0x21fb8c add r5, pc, r5 */
/* @0x21fb90 b 0x21fbb8 <_Z13Sound_Preparev+0x38> */
/* @0x21fb94 ldr r3, [r5] */
/* @0x21fb98 cmp r4, r3 */
/* @0x21fb9c bge 0x21fbb4 <_Z13Sound_Preparev+0x34> */
/* @0x21fba0 ldr r3, [r5, #0x4] */
/* @0x21fba4 ldr r0, [r3, r4, lsl #2] */
/* @0x21fba8 cmp r0, #0 */
/* @0x21fbac beq 0x21fbb4 <_Z13Sound_Preparev+0x34> */
/* @0x21fbb0 bl 0x21568c <_ZN6CSound7PrepareEv> */
/* @0x21fbb4 add r4, r4, #1 */
/* @0x21fbb8 bl 0x21fb6c <_Z12Sound_Numberv> */
/* @0x21fbbc cmp r4, r0 */
/* @0x21fbc0 blt 0x21fb94 <_Z13Sound_Preparev+0x14> */
/* @0x21fbc4 mov r0, #1 */
/* @0x21fbc8 pop {r3, r4, r5, pc} */
/* @0x21fbcc subseq r5, r3, r12, lsr #15 */

/* ── FUNC 0x21fbd0 · Sound_Exists(int) · size=72 · insn=18 */
/* @0x21fbd0 cmp r0, #0 */
/* @0x21fbd4 blt 0x21fc0c <_Z12Sound_Existsi+0x3c> */
/* @0x21fbd8 ldr r3, [pc, #0x34] */
/* @0x21fbdc add r3, pc, r3 */
/* @0x21fbe0 ldr r2, [r3, #0x10] */
/* @0x21fbe4 cmp r0, r2 */
/* @0x21fbe8 bge 0x21fc0c <_Z12Sound_Existsi+0x3c> */
/* @0x21fbec ldr r2, [r3] */
/* @0x21fbf0 cmp r0, r2 */
/* @0x21fbf4 bge 0x21fc0c <_Z12Sound_Existsi+0x3c> */
/* @0x21fbf8 ldr r3, [r3, #0x4] */
/* @0x21fbfc ldr r0, [r3, r0, lsl #2] */
/* @0x21fc00 adds r0, r0, #0 */
/* @0x21fc04 movne r0, #1 */
/* @0x21fc08 bx lr */
/* @0x21fc0c mov r0, #0 */
/* @0x21fc10 bx lr */
/* @0x21fc14 subseq r5, r3, r12, asr r7 */

/* ── FUNC 0x21fc18 · Sound_Name(int) · size=60 · insn=15 */
/* @0x21fc18 push {r4, lr} */
/* @0x21fc1c mov r4, r0 */
/* @0x21fc20 bl 0x21fbd0 <_Z12Sound_Existsi> */
/* @0x21fc24 cmp r0, #0 */
/* @0x21fc28 beq 0x21fc40 <_Z10Sound_Namei+0x28> */
/* @0x21fc2c ldr r3, [pc, #0x18] */
/* @0x21fc30 add r3, pc, r3 */
/* @0x21fc34 ldr r3, [r3, #0xc] */
/* @0x21fc38 ldr r0, [r3, r4, lsl #2] */
/* @0x21fc3c pop {r4, pc} */
/* @0x21fc40 ldr r0, [pc, #0x8] */
/* @0x21fc44 add r0, pc, r0 */
/* @0x21fc48 pop {r4, pc} */
/* @0x21fc4c subseq r5, r3, r8, lsl #14 */
/* @0x21fc50 andseq r0, r1, r12, ror lr */

/* ── FUNC 0x21fc54 · Sound_Find(char const*) · size=128 · insn=32 */
/* @0x21fc54 ldr r3, [pc, #0x74] */
/* @0x21fc58 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x21fc5c add r3, pc, r3 */
/* @0x21fc60 mov r7, r0 */
/* @0x21fc64 ldr r6, [r3, #0x10] */
/* @0x21fc68 cmp r6, #0 */
/* @0x21fc6c ble 0x21fcc8 <_Z10Sound_FindPKc+0x74> */
/* @0x21fc70 mov r5, #0 */
/* @0x21fc74 ldr r8, [r3] */
/* @0x21fc78 ldr r10, [r3, #0x4] */
/* @0x21fc7c mov r4, r5 */
/* @0x21fc80 ldr r9, [r3, #0xc] */
/* @0x21fc84 b 0x21fc98 <_Z10Sound_FindPKc+0x44> */
/* @0x21fc88 add r4, r4, #1 */
/* @0x21fc8c add r5, r5, #4 */
/* @0x21fc90 cmp r4, r6 */
/* @0x21fc94 beq 0x21fcc8 <_Z10Sound_FindPKc+0x74> */
/* @0x21fc98 cmp r4, r8 */
/* @0x21fc9c mov r1, r7 */
/* @0x21fca0 bge 0x21fc88 <_Z10Sound_FindPKc+0x34> */
/* @0x21fca4 ldr r3, [r10, r5] */
/* @0x21fca8 cmp r3, #0 */
/* @0x21fcac beq 0x21fc88 <_Z10Sound_FindPKc+0x34> */
/* @0x21fcb0 ldr r0, [r9, r5] */
/* @0x21fcb4 bl 0xb6574 <strcmp@plt> */
/* @0x21fcb8 cmp r0, #0 */
/* @0x21fcbc bne 0x21fc88 <_Z10Sound_FindPKc+0x34> */
/* @0x21fcc0 mov r0, r4 */
/* @0x21fcc4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21fcc8 mvn r0, #0 */
/* @0x21fccc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21fcd0 ldrsbeq r5, [r3], #-108 */

/* ── FUNC 0x21fcd4 · Sound_Data(int) · size=64 · insn=16 */
/* @0x21fcd4 cmp r0, #0 */
/* @0x21fcd8 blt 0x21fd08 <_Z10Sound_Datai+0x34> */
/* @0x21fcdc ldr r3, [pc, #0x2c] */
/* @0x21fce0 add r3, pc, r3 */
/* @0x21fce4 ldr r2, [r3, #0x10] */
/* @0x21fce8 cmp r0, r2 */
/* @0x21fcec bge 0x21fd08 <_Z10Sound_Datai+0x34> */
/* @0x21fcf0 ldr r2, [r3] */
/* @0x21fcf4 cmp r0, r2 */
/* @0x21fcf8 bge 0x21fd08 <_Z10Sound_Datai+0x34> */
/* @0x21fcfc ldr r3, [r3, #0x4] */
/* @0x21fd00 ldr r0, [r3, r0, lsl #2] */
/* @0x21fd04 bx lr */
/* @0x21fd08 mov r0, #0 */
/* @0x21fd0c bx lr */
/* @0x21fd10 subseq r5, r3, r8, asr r6 */

/* ── FUNC 0x21fd14 · Sound_Add(char const*, int, bool) · size=772 · insn=193 */
/* @0x21fd14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21fd18 sub sp, sp, #28 */
/* @0x21fd1c ldr r10, [pc, #0x2b4] */
/* @0x21fd20 mov r8, r0 */
/* @0x21fd24 str r2, [sp, #0x10] */
/* @0x21fd28 add r10, pc, r10 */
/* @0x21fd2c str r1, [sp, #0xc] */
/* @0x21fd30 ldr r7, [r10, #0x10] */
/* @0x21fd34 ldr r2, [r10] */
/* @0x21fd38 add r7, r7, #1 */
/* @0x21fd3c str r7, [r10, #0x10] */
/* @0x21fd40 cmp r7, r2 */
/* @0x21fd44 beq 0x21fe4c <_Z9Sound_AddPKcib+0x138> */
/* @0x21fd48 cmp r7, #0 */
/* @0x21fd4c bne 0x21fe14 <_Z9Sound_AddPKcib+0x100> */
/* @0x21fd50 ldr r3, [r10, #0x4] */
/* @0x21fd54 cmp r3, #0 */
/* @0x21fd58 beq 0x21ffb4 <_Z9Sound_AddPKcib+0x2a0> */
/* @0x21fd5c cmp r2, #0 */
/* @0x21fd60 ble 0x21fdf8 <_Z9Sound_AddPKcib+0xe4> */
/* @0x21fd64 ldr r2, [pc, #0x270] */
/* @0x21fd68 mov r4, r7 */
/* @0x21fd6c ldr r9, [pc, #0x26c] */
/* @0x21fd70 mov r11, r7 */
/* @0x21fd74 add r2, pc, r2 */
/* @0x21fd78 str r7, [sp, #0x14] */
/* @0x21fd7c add r9, pc, r9 */
/* @0x21fd80 mov r7, r9 */
/* @0x21fd84 mov r9, r2 */
/* @0x21fd88 ldr r0, [r3] */
/* @0x21fd8c movw r1, #0xfeee */
/* @0x21fd90 movt r1, #0xfeee */
/* @0x21fd94 movw r12, #0xfeee */
/* @0x21fd98 cmp r0, r1 */
/* @0x21fd9c movt r12, #0xfeee */
/* @0x21fda0 lsl r6, r4, #2 */
/* @0x21fda4 beq 0x21fde4 <_Z9Sound_AddPKcib+0xd0> */
/* @0x21fda8 ldr r5, [r3, r4, lsl #2] */
/* @0x21fdac add r1, r3, r6 */
/* @0x21fdb0 cmp r5, #0 */
/* @0x21fdb4 mov r0, r5 */
/* @0x21fdb8 beq 0x21fde4 <_Z9Sound_AddPKcib+0xd0> */
/* @0x21fdbc ldr r3, [r5] */
/* @0x21fdc0 cmp r3, r12 */
/* @0x21fdc4 beq 0x21fddc <_Z9Sound_AddPKcib+0xc8> */
/* @0x21fdc8 bl 0x215384 <_ZN6CSoundD2Ev> */
/* @0x21fdcc mov r0, r5 */
/* @0x21fdd0 bl 0x27d1d0 <_ZdlPv> */
/* @0x21fdd4 ldr r1, [r7, #0x4] */
/* @0x21fdd8 add r1, r1, r6 */
/* @0x21fddc str r11, [r1] */
/* @0x21fde0 ldr r3, [r9, #0x4] */
/* @0x21fde4 ldr r1, [r10] */
/* @0x21fde8 add r4, r4, #1 */
/* @0x21fdec cmp r4, r1 */
/* @0x21fdf0 blt 0x21fd88 <_Z9Sound_AddPKcib+0x74> */
/* @0x21fdf4 ldr r7, [sp, #0x14] */
/* @0x21fdf8 mov r0, r3 */
/* @0x21fdfc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21fe00 ldr r3, [pc, #0x1dc] */
/* @0x21fe04 mov r2, #0 */
/* @0x21fe08 add r3, pc, r3 */
/* @0x21fe0c str r2, [r3, #0x4] */
/* @0x21fe10 b 0x21fe3c <_Z9Sound_AddPKcib+0x128> */
/* @0x21fe14 lsls r1, r7, #2 */
/* @0x21fe18 beq 0x21ffb0 <_Z9Sound_AddPKcib+0x29c> */
/* @0x21fe1c ldr r2, [pc, #0x1c4] */
/* @0x21fe20 mov r3, #0 */
/* @0x21fe24 ldr r0, [r10, #0x4] */
/* @0x21fe28 add r2, pc, r2 */
/* @0x21fe2c str r3, [sp] */
/* @0x21fe30 mov r3, #135 */
/* @0x21fe34 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21fe38 str r0, [r10, #0x4] */
/* @0x21fe3c ldr r3, [pc, #0x1a8] */
/* @0x21fe40 add r3, pc, r3 */
/* @0x21fe44 str r7, [r3] */
/* @0x21fe48 ldr r7, [r3, #0x10] */
/* @0x21fe4c cmp r7, #0 */
/* @0x21fe50 bne 0x21ff58 <_Z9Sound_AddPKcib+0x244> */
/* @0x21fe54 ldr r11, [pc, #0x194] */
/* @0x21fe58 add r11, pc, r11 */
/* @0x21fe5c ldr r0, [r11, #0xc] */
/* @0x21fe60 cmp r0, #0 */
/* @0x21fe64 beq 0x21ff98 <_Z9Sound_AddPKcib+0x284> */
/* @0x21fe68 ldr r3, [r11, #0x8] */
/* @0x21fe6c cmp r3, #0 */
/* @0x21fe70 ble 0x21fec0 <_Z9Sound_AddPKcib+0x1ac> */
/* @0x21fe74 ldr r10, [pc, #0x178] */
/* @0x21fe78 mov r4, r7 */
/* @0x21fe7c mov r6, r7 */
/* @0x21fe80 add r10, pc, r10 */
/* @0x21fe84 ldr r0, [r0, r4, lsl #2] */
/* @0x21fe88 lsl r5, r4, #2 */
/* @0x21fe8c bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x21fe90 cmp r0, #0 */
/* @0x21fe94 beq 0x21fea4 <_Z9Sound_AddPKcib+0x190> */
/* @0x21fe98 ldr r3, [r10, #0xc] */
/* @0x21fe9c ldr r0, [r3, r4, lsl #2] */
/* @0x21fea0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21fea4 ldr r2, [r11, #0x8] */
/* @0x21fea8 add r4, r4, #1 */
/* @0x21feac ldr r3, [r11, #0xc] */
/* @0x21feb0 cmp r4, r2 */
/* @0x21feb4 str r6, [r3, r5] */
/* @0x21feb8 ldr r0, [r11, #0xc] */
/* @0x21febc blt 0x21fe84 <_Z9Sound_AddPKcib+0x170> */
/* @0x21fec0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21fec4 ldr r3, [pc, #0x12c] */
/* @0x21fec8 mov r2, #0 */
/* @0x21fecc add r3, pc, r3 */
/* @0x21fed0 str r2, [r3, #0xc] */
/* @0x21fed4 ldr r4, [pc, #0x120] */
/* @0x21fed8 mov r0, r8 */
/* @0x21fedc add r4, pc, r4 */
/* @0x21fee0 str r7, [r4, #0x8] */
/* @0x21fee4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x21fee8 ldr r5, [r4, #0x10] */
/* @0x21feec ldr r3, [r4, #0xc] */
/* @0x21fef0 sub r5, r5, #1 */
/* @0x21fef4 str r0, [r3, r5, lsl #2] */
/* @0x21fef8 mov r0, #64 */
/* @0x21fefc bl 0x27c524 <_Znwj> */
/* @0x21ff00 mov r6, r0 */
/* @0x21ff04 bl 0x215354 <_ZN6CSoundC2Ev> */
/* @0x21ff08 ldr r3, [r4, #0x10] */
/* @0x21ff0c ldm r4, {r1, r2} */
/* @0x21ff10 sub r3, r3, #1 */
/* @0x21ff14 cmp r3, r1 */
/* @0x21ff18 mov r1, r8 */
/* @0x21ff1c str r6, [r2, r5, lsl #2] */
/* @0x21ff20 ldrlt r2, [r4, #0x4] */
/* @0x21ff24 movge r0, #0 */
/* @0x21ff28 ldrlt r0, [r2, r3, lsl #2] */
/* @0x21ff2c ldr r2, [sp, #0xc] */
/* @0x21ff30 ldr r3, [sp, #0x10] */
/* @0x21ff34 bl 0x21569c <_ZN6CSound12LoadFromFileEPKcib> */
/* @0x21ff38 cmp r0, #0 */
/* @0x21ff3c beq 0x21ffd0 <_Z9Sound_AddPKcib+0x2bc> */
/* @0x21ff40 ldr r3, [pc, #0xb8] */
/* @0x21ff44 add r3, pc, r3 */
/* @0x21ff48 ldr r0, [r3, #0x10] */
/* @0x21ff4c sub r0, r0, #1 */
/* @0x21ff50 add sp, sp, #28 */
/* @0x21ff54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21ff58 lsls r1, r7, #2 */
/* @0x21ff5c beq 0x21ff8c <_Z9Sound_AddPKcib+0x278> */
/* @0x21ff60 ldr r4, [pc, #0x9c] */
/* @0x21ff64 mov r3, #0 */
/* @0x21ff68 ldr r2, [pc, #0x98] */
/* @0x21ff6c add r4, pc, r4 */
/* @0x21ff70 str r3, [sp] */
/* @0x21ff74 add r2, pc, r2 */
/* @0x21ff78 mov r3, #92 */
/* @0x21ff7c ldr r0, [r4, #0xc] */
/* @0x21ff80 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21ff84 str r0, [r4, #0xc] */
/* @0x21ff88 b 0x21fed4 <_Z9Sound_AddPKcib+0x1c0> */
/* @0x21ff8c ldr r3, [pc, #0x78] */
/* @0x21ff90 add r3, pc, r3 */
/* @0x21ff94 ldr r0, [r3, #0xc] */
/* @0x21ff98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ff9c ldr r3, [pc, #0x6c] */
/* @0x21ffa0 mov r2, #0 */
/* @0x21ffa4 add r3, pc, r3 */
/* @0x21ffa8 str r2, [r3, #0xc] */
/* @0x21ffac b 0x21fed4 <_Z9Sound_AddPKcib+0x1c0> */
/* @0x21ffb0 ldr r3, [r10, #0x4] */
/* @0x21ffb4 mov r0, r3 */
/* @0x21ffb8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ffbc ldr r3, [pc, #0x50] */
/* @0x21ffc0 mov r2, #0 */
/* @0x21ffc4 add r3, pc, r3 */
/* @0x21ffc8 str r2, [r3, #0x4] */
/* @0x21ffcc b 0x21fe3c <_Z9Sound_AddPKcib+0x128> */
/* @0x21ffd0 mvn r0, #0 */
/* @0x21ffd4 b 0x21ff50 <_Z9Sound_AddPKcib+0x23c> */
/* @0x21ffd8 subseq r5, r3, r0, lsl r6 */
/* @0x21ffdc subseq r5, r3, r4, asr #11 */
/* @0x21ffe0 ldrheq r5, [r3], #-92 */
/* @0x21ffe4 subseq r5, r3, r0, lsr r5 */
/* @0x21ffe8 andseq r4, r3, r4, ror #18 */
/* @0x21ffec ldrsheq r5, [r3], #-72 */
/* @0x21fff0 subseq r5, r3, r0, ror #9 */
/* @0x21fff4 ldrheq r5, [r3], #-72 */
/* @0x21fff8 subseq r5, r3, r12, ror #8 */
/* @0x21fffc subseq r5, r3, r12, asr r4 */
/* @0x220000 ldrsheq r5, [r3], #-52 */
/* @0x220004 subseq r5, r3, r12, asr #7 */
/* @0x220008 andseq r3, r3, r0, ror #27 */
/* @0x22000c subseq r5, r3, r8, lsr #7 */
/* @0x220010 .word 0x00535394 */
/* @0x220014 subseq r5, r3, r4, ror r3 */

/* ── FUNC 0x220018 · Sound_Replace(int, char const*, int, bool) · size=180 · insn=45 */
/* @0x220018 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x22001c subs r4, r0, #0 */
/* @0x220020 mov r7, r1 */
/* @0x220024 mov r6, r2 */
/* @0x220028 mov r5, r3 */
/* @0x22002c blt 0x2200bc <_Z13Sound_ReplaceiPKcib+0xa4> */
/* @0x220030 ldr r0, [pc, #0x8c] */
/* @0x220034 add r0, pc, r0 */
/* @0x220038 ldr r12, [r0, #0x10] */
/* @0x22003c cmp r4, r12 */
/* @0x220040 bge 0x2200bc <_Z13Sound_ReplaceiPKcib+0xa4> */
/* @0x220044 ldr r3, [r0] */
/* @0x220048 cmp r4, r3 */
/* @0x22004c lslge r8, r4, #2 */
/* @0x220050 bge 0x220078 <_Z13Sound_ReplaceiPKcib+0x60> */
/* @0x220054 ldr r3, [r0, #0x4] */
/* @0x220058 lsl r8, r4, #2 */
/* @0x22005c ldr r9, [r3, r4, lsl #2] */
/* @0x220060 cmp r9, #0 */
/* @0x220064 beq 0x220078 <_Z13Sound_ReplaceiPKcib+0x60> */
/* @0x220068 mov r0, r9 */
/* @0x22006c bl 0x215384 <_ZN6CSoundD2Ev> */
/* @0x220070 mov r0, r9 */
/* @0x220074 bl 0x27d1d0 <_ZdlPv> */
/* @0x220078 mov r0, #64 */
/* @0x22007c bl 0x27c524 <_Znwj> */
/* @0x220080 mov r9, r0 */
/* @0x220084 bl 0x215354 <_ZN6CSoundC2Ev> */
/* @0x220088 ldr r12, [pc, #0x38] */
/* @0x22008c mov r1, r7 */
/* @0x220090 add r12, pc, r12 */
/* @0x220094 ldm r12, {r2, r3} */
/* @0x220098 cmp r4, r2 */
/* @0x22009c mov r2, r6 */
/* @0x2200a0 str r9, [r3, r8] */
/* @0x2200a4 ldrlt r3, [r12, #0x4] */
/* @0x2200a8 movge r0, #0 */
/* @0x2200ac ldrlt r0, [r3, r8] */
/* @0x2200b0 mov r3, r5 */
/* @0x2200b4 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2200b8 b 0x21569c <_ZN6CSound12LoadFromFileEPKcib> */
/* @0x2200bc mov r0, #0 */
/* @0x2200c0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2200c4 subseq r5, r3, r4, lsl #6 */
/* @0x2200c8 subseq r5, r3, r8, lsr #5 */

/* ── FUNC 0x2200cc · Sound_Delete(int) · size=152 · insn=38 */
/* @0x2200cc push {r3, r4, r5, r6, r7, lr} */
/* @0x2200d0 subs r4, r0, #0 */
/* @0x2200d4 blt 0x220154 <_Z12Sound_Deletei+0x88> */
/* @0x2200d8 ldr r5, [pc, #0x80] */
/* @0x2200dc add r5, pc, r5 */
/* @0x2200e0 ldr r3, [r5, #0x10] */
/* @0x2200e4 cmp r4, r3 */
/* @0x2200e8 bge 0x220154 <_Z12Sound_Deletei+0x88> */
/* @0x2200ec ldr r3, [r5] */
/* @0x2200f0 cmp r4, r3 */
/* @0x2200f4 bge 0x220154 <_Z12Sound_Deletei+0x88> */
/* @0x2200f8 ldr r3, [r5, #0x4] */
/* @0x2200fc lsl r7, r4, #2 */
/* @0x220100 ldr r6, [r3, r4, lsl #2] */
/* @0x220104 subs r0, r6, #0 */
/* @0x220108 beq 0x22015c <_Z12Sound_Deletei+0x90> */
/* @0x22010c bl 0x215384 <_ZN6CSoundD2Ev> */
/* @0x220110 mov r0, r6 */
/* @0x220114 bl 0x27d1d0 <_ZdlPv> */
/* @0x220118 ldr r3, [r5, #0x4] */
/* @0x22011c mov r2, #0 */
/* @0x220120 str r2, [r3, r4, lsl #2] */
/* @0x220124 ldr r2, [r5, #0xc] */
/* @0x220128 add r3, r2, r7 */
/* @0x22012c ldr r0, [r2, r4, lsl #2] */
/* @0x220130 cmp r0, #0 */
/* @0x220134 beq 0x220144 <_Z12Sound_Deletei+0x78> */
/* @0x220138 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x22013c ldr r3, [r5, #0xc] */
/* @0x220140 add r3, r3, r7 */
/* @0x220144 mov r2, #0 */
/* @0x220148 mov r0, #1 */
/* @0x22014c str r2, [r3] */
/* @0x220150 pop {r3, r4, r5, r6, r7, pc} */
/* @0x220154 mov r0, #0 */
/* @0x220158 pop {r3, r4, r5, r6, r7, pc} */
/* @0x22015c pop {r3, r4, r5, r6, r7, pc} */
/* @0x220160 subseq r5, r3, r12, asr r2 */

/* ── FUNC 0x220164 · ReadU32(void*) · size=36 · insn=9 */
/* @0x220164 ldrb r3, [r0, #0x2] */
/* @0x220168 ldrb r1, [r0, #0x1] */
/* @0x22016c ldrb r2, [r0] */
/* @0x220170 lsl r3, r3, #16 */
/* @0x220174 ldrb r0, [r0, #0x3] */
/* @0x220178 orr r3, r3, r1, lsl #8 */
/* @0x22017c orr r3, r3, r2 */
/* @0x220180 orr r0, r3, r0, lsl #24 */
/* @0x220184 bx lr */

/* ── FUNC 0x220188 · SoundHardware::SoundHardware() · size=12 · insn=3 */
/* @0x220188 mov r3, #1065353216 */
/* @0x22018c str r3, [r0] */
/* @0x220190 bx lr */

/* ── FUNC 0x220188 · SoundHardware::SoundHardware() · alias of the symbol above · insn=0 */

/* ── FUNC 0x220194 · SoundHardware::~SoundHardware() · size=4 · insn=1 */
/* @0x220194 bx lr */

/* ── FUNC 0x220194 · SoundHardware::~SoundHardware() · alias of the symbol above · insn=0 */

/* ── FUNC 0x220198 · CheckALError() · size=132 · insn=33 */
/* @0x220198 push {r3, r4, r5, lr} */
/* @0x22019c bl 0xb6a54 <alGetError@plt> */
/* @0x2201a0 subs r2, r0, #0 */
/* @0x2201a4 bne 0x2201e4 <_Z12CheckALErrorv+0x4c> */
/* @0x2201a8 bl 0x221714 <alutGetError> */
/* @0x2201ac cmp r0, #0 */
/* @0x2201b0 popeq {r3, r4, r5, pc} */
/* @0x2201b4 ldr r3, [pc, #0x50] */
/* @0x2201b8 ldr r3, [pc, r3] */
/* @0x2201bc ldr r4, [r3] */
/* @0x2201c0 ldr r3, [r4] */
/* @0x2201c4 ldr r5, [r3, #0xc] */
/* @0x2201c8 bl 0x221730 <alutGetErrorString> */
/* @0x2201cc ldr r1, [pc, #0x3c] */
/* @0x2201d0 add r1, pc, r1 */
/* @0x2201d4 mov r2, r0 */
/* @0x2201d8 mov r0, r4 */
/* @0x2201dc blx r5 */
/* @0x2201e0 pop {r3, r4, r5, pc} */
/* @0x2201e4 ldr r0, [pc, #0x28] */
/* @0x2201e8 mov r3, r2 */
/* @0x2201ec ldr r1, [pc, #0x24] */
/* @0x2201f0 ldr r0, [pc, r0] */
/* @0x2201f4 add r1, pc, r1 */
/* @0x2201f8 ldr r0, [r0] */
/* @0x2201fc ldr r12, [r0] */
/* @0x220200 ldr r12, [r12, #0xc] */
/* @0x220204 blx r12 */
/* @0x220208 b 0x2201a8 <_Z12CheckALErrorv+0x10> */
/* @0x22020c andseq sp, r12, r12, asr r5 */
/* @0x220210 andseq r4, r3, r8, asr r6 */
/* @0x220214 andseq sp, r12, r4, lsr #10 */
/* @0x220218 andseq r4, r3, r12, lsl r6 */

/* ── FUNC 0x22021c · SoundHardware::Init() · size=264 · insn=66 */
/* @0x22021c push {r4, r5, lr} */
/* @0x220220 sub sp, sp, #12 */
/* @0x220224 ldr r4, [pc, #0xcc] */
/* @0x220228 ldr r3, [pc, #0xcc] */
/* @0x22022c add r4, pc, r4 */
/* @0x220230 ldr r3, [r4, r3] */
/* @0x220234 ldrb r3, [r3] */
/* @0x220238 cmp r3, #0 */
/* @0x22023c bne 0x2202cc <_ZN13SoundHardware4InitEv+0xb0> */
/* @0x220240 ldr r3, [pc, #0xb8] */
/* @0x220244 ldr r3, [r4, r3] */
/* @0x220248 ldrb r5, [r3] */
/* @0x22024c cmp r5, #0 */
/* @0x220250 beq 0x220260 <_ZN13SoundHardware4InitEv+0x44> */
/* @0x220254 mov r0, #0 */
/* @0x220258 add sp, sp, #12 */
/* @0x22025c pop {r4, r5, pc} */
/* @0x220260 bl 0x2232e0 <_Z11OpenAL_Initv> */
/* @0x220264 ldr r1, [pc, #0x98] */
/* @0x220268 ldr r2, [pc, #0x98] */
/* @0x22026c mov r0, #1 */
/* @0x220270 add r1, pc, r1 */
/* @0x220274 ldr r3, [pc, #0x90] */
/* @0x220278 strb r0, [r1] */
/* @0x22027c ldr r2, [r4, r2] */
/* @0x220280 strb r5, [r2] */
/* @0x220284 ldr r3, [r4, r3] */
/* @0x220288 ldrb r3, [r3] */
/* @0x22028c cmp r3, #0 */
/* @0x220290 bne 0x220254 <_ZN13SoundHardware4InitEv+0x38> */
/* @0x220294 ldr r3, [pc, #0x74] */
/* @0x220298 ldr r3, [r4, r3] */
/* @0x22029c ldrb r3, [r3] */
/* @0x2202a0 cmp r3, #0 */
/* @0x2202a4 bne 0x220254 <_ZN13SoundHardware4InitEv+0x38> */
/* @0x2202a8 ldr r2, [pc, #0x64] */
/* @0x2202ac add r1, sp, #4 */
/* @0x2202b0 mov r0, sp */
/* @0x2202b4 str r3, [sp] */
/* @0x2202b8 add r2, pc, r2 */
/* @0x2202bc str r2, [sp, #0x4] */
/* @0x2202c0 bl 0x221a34 <alutInit> */
/* @0x2202c4 bl 0x220198 <_Z12CheckALErrorv> */
/* @0x2202c8 b 0x220254 <_ZN13SoundHardware4InitEv+0x38> */
/* @0x2202cc ldr r3, [pc, #0x44] */
/* @0x2202d0 ldr r1, [pc, #0x44] */
/* @0x2202d4 ldr r2, [pc, #0x44] */
/* @0x2202d8 ldr r3, [r4, r3] */
/* @0x2202dc add r1, pc, r1 */
/* @0x2202e0 add r2, pc, r2 */
/* @0x2202e4 ldr r0, [r3] */
/* @0x2202e8 ldr r3, [r0] */
/* @0x2202ec ldr r3, [r3, #0xc] */
/* @0x2202f0 blx r3 */
/* @0x2202f4 b 0x220240 <_ZN13SoundHardware4InitEv+0x24> */
/* @0x2202f8 andseq r1, sp, r4, lsr #20 */
/* @0x2202fc .word 0xfffff7d8 */
/* @0x220300 .word 0xffffd3fc */
/* @0x220304 ldrsbeq r5, [r3], #-12 */
/* @0x220308 .word 0xfffff7dc */
/* @0x22030c .word 0xfffff7e0 */
/* @0x220310 .word 0xfffff7e4 */
/* @0x220314 andseq lr, r0, lr, ror r8 */
/* @0x220318 .word 0xffffbac4 */
/* @0x22031c andseq r4, r3, r0, ror #10 */
/* @0x220320 andseq sp, r3, r8, ror #25 */

/* ── FUNC 0x220324 · SoundHardware::Quit() · size=216 · insn=54 */
/* @0x220324 push {r4, lr} */
/* @0x220328 ldr r4, [pc, #0xa8] */
/* @0x22032c ldr r3, [pc, #0xa8] */
/* @0x220330 add r4, pc, r4 */
/* @0x220334 ldr r3, [r4, r3] */
/* @0x220338 ldrb r3, [r3] */
/* @0x22033c cmp r3, #0 */
/* @0x220340 bne 0x2203a0 <_ZN13SoundHardware4QuitEv+0x7c> */
/* @0x220344 ldr r3, [pc, #0x94] */
/* @0x220348 ldr r3, [r4, r3] */
/* @0x22034c ldrb r3, [r3] */
/* @0x220350 cmp r3, #0 */
/* @0x220354 popne {r4, pc} */
/* @0x220358 ldr r3, [pc, #0x84] */
/* @0x22035c ldr r3, [r4, r3] */
/* @0x220360 ldrb r3, [r3] */
/* @0x220364 cmp r3, #0 */
/* @0x220368 popne {r4, pc} */
/* @0x22036c ldr r3, [pc, #0x74] */
/* @0x220370 add r3, pc, r3 */
/* @0x220374 ldrb r3, [r3] */
/* @0x220378 cmp r3, #0 */
/* @0x22037c popeq {r4, pc} */
/* @0x220380 bl 0x21a664 <_Z10Audio_Quitv> */
/* @0x220384 ldr r3, [pc, #0x60] */
/* @0x220388 ldr r3, [r4, r3] */
/* @0x22038c ldrb r3, [r3] */
/* @0x220390 cmp r3, #0 */
/* @0x220394 beq 0x2203d0 <_ZN13SoundHardware4QuitEv+0xac> */
/* @0x220398 pop {r4, lr} */
/* @0x22039c b 0x2232e4 <_Z11OpenAL_Quitv> */
/* @0x2203a0 ldr r3, [pc, #0x48] */
/* @0x2203a4 ldr r2, [pc, #0x48] */
/* @0x2203a8 ldr r1, [pc, #0x48] */
/* @0x2203ac ldr r3, [r4, r3] */
/* @0x2203b0 add r2, pc, r2 */
/* @0x2203b4 add r1, pc, r1 */
/* @0x2203b8 add r2, r2, #8 */
/* @0x2203bc ldr r0, [r3] */
/* @0x2203c0 ldr r3, [r0] */
/* @0x2203c4 ldr r3, [r3, #0xc] */
/* @0x2203c8 blx r3 */
/* @0x2203cc b 0x220344 <_ZN13SoundHardware4QuitEv+0x20> */
/* @0x2203d0 bl 0x221b78 <alutExit> */
/* @0x2203d4 b 0x220398 <_ZN13SoundHardware4QuitEv+0x74> */
/* @0x2203d8 andseq r1, sp, r0, lsr #18 */
/* @0x2203dc .word 0xfffff7d8 */
/* @0x2203e0 .word 0xffffd3fc */
/* @0x2203e4 .word 0xfffff7e4 */
/* @0x2203e8 ldrsbeq r4, [r3], #-252 */
/* @0x2203ec .word 0xfffff7e0 */
/* @0x2203f0 .word 0xffffbac4 */
/* @0x2203f4 andseq sp, r3, r8, lsl r12 */
/* @0x2203f8 andseq r4, r3, r8, lsl #9 */
