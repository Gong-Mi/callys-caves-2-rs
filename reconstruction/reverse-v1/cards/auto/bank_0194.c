/* libyoyo.so 覆盖卡组 0194
 * 函数 0x218ea4..0x21c220，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x218ea4 · cAudio_Sound::cAudio_Sound() · size=128 · insn=32 */
/* @0x218ea4 str r4, [sp, #-0x4]! */
/* @0x218ea8 mov r4, #1065353216 */
/* @0x218eac mvn r3, #0 */
/* @0x218eb0 mov r12, #1 */
/* @0x218eb4 str r3, [r0, #0x18] */
/* @0x218eb8 mov r2, #0 */
/* @0x218ebc mov r3, #0 */
/* @0x218ec0 str r12, [r0, #0x3c] */
/* @0x218ec4 strd r2, r3, [r0, #64] */
/* @0x218ec8 mov r12, #0 */
/* @0x218ecc mov r3, #0 */
/* @0x218ed0 str r4, [r0, #0x4] */
/* @0x218ed4 str r4, [r0, #0x8] */
/* @0x218ed8 str r12, [r0] */
/* @0x218edc str r3, [r0, #0x1c] */
/* @0x218ee0 str r12, [r0, #0xc] */
/* @0x218ee4 str r3, [r0, #0x34] */
/* @0x218ee8 str r12, [r0, #0x14] */
/* @0x218eec str r3, [r0, #0x48] */
/* @0x218ef0 str r12, [r0, #0x20] */
/* @0x218ef4 strb r12, [r0, #0x24] */
/* @0x218ef8 strb r12, [r0, #0x25] */
/* @0x218efc strb r12, [r0, #0x26] */
/* @0x218f00 strb r12, [r0, #0x27] */
/* @0x218f04 str r12, [r0, #0x28] */
/* @0x218f08 str r12, [r0, #0x2c] */
/* @0x218f0c str r12, [r0, #0x30] */
/* @0x218f10 str r12, [r0, #0x38] */
/* @0x218f14 str r12, [r0, #0x4c] */
/* @0x218f18 strb r12, [r0, #0x5c] */
/* @0x218f1c ldr r4, [sp], #4 */
/* @0x218f20 bx lr */

/* ── FUNC 0x218ea4 · cAudio_Sound::cAudio_Sound() · alias of the symbol above · insn=0 */

/* ── FUNC 0x218f24 · cAudio_Sound::~cAudio_Sound() · size=88 · insn=22 */
/* @0x218f24 push {r3, r4, r5, lr} */
/* @0x218f28 mov r4, r0 */
/* @0x218f2c ldr r0, [r0] */
/* @0x218f30 mov r5, #0 */
/* @0x218f34 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x218f38 ldr r0, [r4, #0x30] */
/* @0x218f3c str r5, [r4] */
/* @0x218f40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x218f44 str r5, [r4, #0x30] */
/* @0x218f48 ldr r0, [r4, #0x18] */
/* @0x218f4c bl 0xb6ad8 <alIsBuffer@plt> */
/* @0x218f50 cmp r0, r5 */
/* @0x218f54 beq 0x218f6c <_ZN12cAudio_SoundD2Ev+0x48> */
/* @0x218f58 mov r0, #1 */
/* @0x218f5c add r1, r4, #24 */
/* @0x218f60 bl 0xb6ae4 <alDeleteBuffers@plt> */
/* @0x218f64 mvn r3, #0 */
/* @0x218f68 str r3, [r4, #0x18] */
/* @0x218f6c mov r3, #0 */
/* @0x218f70 mov r0, r4 */
/* @0x218f74 str r3, [r4, #0x58] */
/* @0x218f78 pop {r3, r4, r5, pc} */

/* ── FUNC 0x218f24 · cAudio_Sound::~cAudio_Sound() · alias of the symbol above · insn=0 */

/* ── FUNC 0x218f7c · cARRAY_CLASS<cAudio_Sound*>::~cARRAY_CLASS() · size=204 · insn=51 */
/* @0x218f7c ldr r12, [r0] */
/* @0x218f80 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x218f84 cmp r12, #0 */
/* @0x218f88 mov r7, r0 */
/* @0x218f8c beq 0x219030 <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0xb4> */
/* @0x218f90 ldr r5, [r0, #0x4] */
/* @0x218f94 cmp r5, #0 */
/* @0x218f98 beq 0x219038 <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0xbc> */
/* @0x218f9c cmp r12, #0 */
/* @0x218fa0 ble 0x219018 <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0x9c> */
/* @0x218fa4 mov r4, #0 */
/* @0x218fa8 mov r9, r4 */
/* @0x218fac ldr r1, [r5] */
/* @0x218fb0 movw r3, #0xfeee */
/* @0x218fb4 movt r3, #0xfeee */
/* @0x218fb8 movw r2, #0xfeee */
/* @0x218fbc cmp r1, r3 */
/* @0x218fc0 movt r2, #0xfeee */
/* @0x218fc4 lsl r8, r4, #2 */
/* @0x218fc8 beq 0x21900c <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0x90> */
/* @0x218fcc ldr r6, [r5, r4, lsl #2] */
/* @0x218fd0 add r3, r5, r8 */
/* @0x218fd4 cmp r6, #0 */
/* @0x218fd8 mov r0, r6 */
/* @0x218fdc beq 0x21900c <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0x90> */
/* @0x218fe0 ldr r1, [r6] */
/* @0x218fe4 cmp r1, r2 */
/* @0x218fe8 beq 0x219004 <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0x88> */
/* @0x218fec bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x218ff0 mov r0, r6 */
/* @0x218ff4 bl 0x27d1d0 <_ZdlPv> */
/* @0x218ff8 ldr r3, [r7, #0x4] */
/* @0x218ffc ldr r12, [r7] */
/* @0x219000 add r3, r3, r8 */
/* @0x219004 str r9, [r3] */
/* @0x219008 ldr r5, [r7, #0x4] */
/* @0x21900c add r4, r4, #1 */
/* @0x219010 cmp r4, r12 */
/* @0x219014 blt 0x218fac <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0x30> */
/* @0x219018 mov r0, r5 */
/* @0x21901c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x219020 mov r3, #0 */
/* @0x219024 str r3, [r7, #0x4] */
/* @0x219028 mov r3, #0 */
/* @0x21902c str r3, [r7] */
/* @0x219030 mov r0, r7 */
/* @0x219034 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x219038 mov r0, r5 */
/* @0x21903c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x219040 str r5, [r7, #0x4] */
/* @0x219044 b 0x219028 <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0xac> */

/* ── FUNC 0x218f7c · cARRAY_CLASS<cAudio_Sound*>::~cARRAY_CLASS() · alias of the symbol above · insn=0 */

/* ── FUNC 0x219048 · Audio_Load(unsigned char*, unsigned int, unsigned char*) · size=908 · insn=227 */
/* @0x219048 ldr r3, [pc, #0x334] */
/* @0x21904c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x219050 ldr r3, [pc, r3] */
/* @0x219054 mov r8, r0 */
/* @0x219058 ldr r6, [pc, #0x328] */
/* @0x21905c ldr r0, [r3] */
/* @0x219060 sub sp, sp, #28 */
/* @0x219064 ldr r1, [pc, #0x320] */
/* @0x219068 add r6, pc, r6 */
/* @0x21906c str r2, [sp, #0x10] */
/* @0x219070 ldr r3, [r0] */
/* @0x219074 add r1, pc, r1 */
/* @0x219078 ldr r3, [r3, #0xc] */
/* @0x21907c blx r3 */
/* @0x219080 ldr r9, [r8] */
/* @0x219084 ldr r2, [r6, #0x20] */
/* @0x219088 cmp r9, r2 */
/* @0x21908c beq 0x21917c <_Z10Audio_LoadPhjS_+0x134> */
/* @0x219090 cmp r9, #0 */
/* @0x219094 ldr r3, [r6, #0x24] */
/* @0x219098 bne 0x219154 <_Z10Audio_LoadPhjS_+0x10c> */
/* @0x21909c cmp r3, #0 */
/* @0x2190a0 beq 0x219154 <_Z10Audio_LoadPhjS_+0x10c> */
/* @0x2190a4 cmp r2, #0 */
/* @0x2190a8 ble 0x219138 <_Z10Audio_LoadPhjS_+0xf0> */
/* @0x2190ac ldr r11, [pc, #0x2dc] */
/* @0x2190b0 mov r4, r9 */
/* @0x2190b4 ldr r12, [pc, #0x2d8] */
/* @0x2190b8 mov r7, r9 */
/* @0x2190bc add r11, pc, r11 */
/* @0x2190c0 add r12, pc, r12 */
/* @0x2190c4 ldr r0, [r3] */
/* @0x2190c8 movw r2, #0xfeee */
/* @0x2190cc movt r2, #0xfeee */
/* @0x2190d0 movw r1, #0xfeee */
/* @0x2190d4 cmp r0, r2 */
/* @0x2190d8 movt r1, #0xfeee */
/* @0x2190dc lsl r10, r4, #2 */
/* @0x2190e0 beq 0x219128 <_Z10Audio_LoadPhjS_+0xe0> */
/* @0x2190e4 ldr r5, [r3, r4, lsl #2] */
/* @0x2190e8 add lr, r3, r10 */
/* @0x2190ec cmp r5, #0 */
/* @0x2190f0 mov r0, r5 */
/* @0x2190f4 beq 0x219128 <_Z10Audio_LoadPhjS_+0xe0> */
/* @0x2190f8 ldr r3, [r5] */
/* @0x2190fc cmp r3, r1 */
/* @0x219100 beq 0x219120 <_Z10Audio_LoadPhjS_+0xd8> */
/* @0x219104 str r12, [sp, #0xc] */
/* @0x219108 bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x21910c mov r0, r5 */
/* @0x219110 bl 0x27d1d0 <_ZdlPv> */
/* @0x219114 ldr r12, [sp, #0xc] */
/* @0x219118 ldr lr, [r12, #0x24] */
/* @0x21911c add lr, lr, r10 */
/* @0x219120 str r7, [lr] */
/* @0x219124 ldr r3, [r11, #0x24] */
/* @0x219128 ldr r2, [r6, #0x20] */
/* @0x21912c add r4, r4, #1 */
/* @0x219130 cmp r4, r2 */
/* @0x219134 blt 0x2190c4 <_Z10Audio_LoadPhjS_+0x7c> */
/* @0x219138 mov r0, r3 */
/* @0x21913c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x219140 ldr r3, [pc, #0x250] */
/* @0x219144 mov r2, #0 */
/* @0x219148 add r3, pc, r3 */
/* @0x21914c str r2, [r3, #0x24] */
/* @0x219150 b 0x219170 <_Z10Audio_LoadPhjS_+0x128> */
/* @0x219154 lsls r4, r9, #2 */
/* @0x219158 mov r0, r3 */
/* @0x21915c bne 0x219350 <_Z10Audio_LoadPhjS_+0x308> */
/* @0x219160 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x219164 ldr r3, [pc, #0x230] */
/* @0x219168 add r3, pc, r3 */
/* @0x21916c str r4, [r3, #0x24] */
/* @0x219170 ldr r3, [pc, #0x228] */
/* @0x219174 add r3, pc, r3 */
/* @0x219178 str r9, [r3, #0x20] */
/* @0x21917c cmp r9, #0 */
/* @0x219180 bne 0x2192f0 <_Z10Audio_LoadPhjS_+0x2a8> */
/* @0x219184 ldr r5, [pc, #0x218] */
/* @0x219188 add r5, pc, r5 */
/* @0x21918c ldr r0, [r5, #0x4c] */
/* @0x219190 cmp r0, #0 */
/* @0x219194 beq 0x2192fc <_Z10Audio_LoadPhjS_+0x2b4> */
/* @0x219198 ldr r3, [r5, #0x48] */
/* @0x21919c cmp r3, #0 */
/* @0x2191a0 ble 0x2191f0 <_Z10Audio_LoadPhjS_+0x1a8> */
/* @0x2191a4 ldr r7, [pc, #0x1fc] */
/* @0x2191a8 mov r4, r9 */
/* @0x2191ac mov r6, r9 */
/* @0x2191b0 add r7, pc, r7 */
/* @0x2191b4 ldr r0, [r0, r4, lsl #2] */
/* @0x2191b8 lsl r11, r4, #2 */
/* @0x2191bc bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x2191c0 cmp r0, #0 */
/* @0x2191c4 beq 0x2191d4 <_Z10Audio_LoadPhjS_+0x18c> */
/* @0x2191c8 ldr r3, [r7, #0x4c] */
/* @0x2191cc ldr r0, [r3, r4, lsl #2] */
/* @0x2191d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2191d4 ldr r2, [r5, #0x48] */
/* @0x2191d8 add r4, r4, #1 */
/* @0x2191dc ldr r3, [r5, #0x4c] */
/* @0x2191e0 cmp r4, r2 */
/* @0x2191e4 str r6, [r3, r11] */
/* @0x2191e8 ldr r0, [r5, #0x4c] */
/* @0x2191ec blt 0x2191b4 <_Z10Audio_LoadPhjS_+0x16c> */
/* @0x2191f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2191f4 ldr r3, [pc, #0x1b0] */
/* @0x2191f8 mov r2, #0 */
/* @0x2191fc add r3, pc, r3 */
/* @0x219200 str r2, [r3, #0x4c] */
/* @0x219204 ldr r7, [pc, #0x1a4] */
/* @0x219208 cmp r9, #0 */
/* @0x21920c add r7, pc, r7 */
/* @0x219210 str r9, [r7, #0x48] */
/* @0x219214 beq 0x219344 <_Z10Audio_LoadPhjS_+0x2fc> */
/* @0x219218 ldr r3, [pc, #0x194] */
/* @0x21921c mov r4, #0 */
/* @0x219220 add r3, pc, r3 */
/* @0x219224 str r3, [sp, #0x14] */
/* @0x219228 b 0x2192dc <_Z10Audio_LoadPhjS_+0x294> */
/* @0x21922c ldr r10, [pc, #0x184] */
/* @0x219230 ldr r10, [pc, r10] */
/* @0x219234 ldr r11, [r10] */
/* @0x219238 adds r1, r11, r5 */
/* @0x21923c beq 0x21937c <_Z10Audio_LoadPhjS_+0x334> */
/* @0x219240 mov r0, #96 */
/* @0x219244 str r1, [sp, #0xc] */
/* @0x219248 bl 0x27c524 <_Znwj> */
/* @0x21924c mov r6, r0 */
/* @0x219250 bl 0x218ea4 <_ZN12cAudio_SoundC2Ev> */
/* @0x219254 ldr r1, [sp, #0xc] */
/* @0x219258 mov r0, r6 */
/* @0x21925c ldr r2, [sp, #0x10] */
/* @0x219260 bl 0x218d64 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh> */
/* @0x219264 ldr r12, [r11, r5] */
/* @0x219268 cmp r12, #0 */
/* @0x21926c ldrne r3, [r10] */
/* @0x219270 moveq r11, r12 */
/* @0x219274 addne r11, r3, r12 */
/* @0x219278 mov r0, r11 */
/* @0x21927c bl 0xb6538 <strlen@plt> */
/* @0x219280 ldr r1, [sp, #0x14] */
/* @0x219284 mov r3, #1 */
/* @0x219288 movw r2, #0xb42 */
/* @0x21928c add r0, r0, r3 */
/* @0x219290 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x219294 mov r1, r11 */
/* @0x219298 mov r5, r0 */
/* @0x21929c bl 0xb65a4 <strcpy@plt> */
/* @0x2192a0 ldr r3, [r7, #0x24] */
/* @0x2192a4 lsl r11, r4, #2 */
/* @0x2192a8 str r6, [r3, r4, lsl #2] */
/* @0x2192ac ldr r3, [r7, #0x4c] */
/* @0x2192b0 add r1, r3, r11 */
/* @0x2192b4 ldr r0, [r3, r4, lsl #2] */
/* @0x2192b8 cmp r0, #0 */
/* @0x2192bc beq 0x2192cc <_Z10Audio_LoadPhjS_+0x284> */
/* @0x2192c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2192c4 ldr r1, [r7, #0x4c] */
/* @0x2192c8 add r1, r1, r11 */
/* @0x2192cc add r4, r4, #1 */
/* @0x2192d0 str r5, [r1] */
/* @0x2192d4 cmp r4, r9 */
/* @0x2192d8 beq 0x219344 <_Z10Audio_LoadPhjS_+0x2fc> */
/* @0x2192dc ldr r5, [r8, #0x4]! */
/* @0x2192e0 cmp r5, #0 */
/* @0x2192e4 bne 0x21922c <_Z10Audio_LoadPhjS_+0x1e4> */
/* @0x2192e8 mov r6, r5 */
/* @0x2192ec b 0x2192a0 <_Z10Audio_LoadPhjS_+0x258> */
/* @0x2192f0 ldr r3, [pc, #0xc4] */
/* @0x2192f4 add r3, pc, r3 */
/* @0x2192f8 ldr r0, [r3, #0x4c] */
/* @0x2192fc lsls r4, r9, #2 */
/* @0x219300 beq 0x219330 <_Z10Audio_LoadPhjS_+0x2e8> */
/* @0x219304 ldr r2, [pc, #0xb4] */
/* @0x219308 mov r3, #0 */
/* @0x21930c mov r1, r4 */
/* @0x219310 str r3, [sp] */
/* @0x219314 add r2, pc, r2 */
/* @0x219318 mov r3, #92 */
/* @0x21931c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x219320 ldr r3, [pc, #0x9c] */
/* @0x219324 add r3, pc, r3 */
/* @0x219328 str r0, [r3, #0x4c] */
/* @0x21932c b 0x219204 <_Z10Audio_LoadPhjS_+0x1bc> */
/* @0x219330 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x219334 ldr r3, [pc, #0x8c] */
/* @0x219338 add r3, pc, r3 */
/* @0x21933c str r4, [r3, #0x4c] */
/* @0x219340 b 0x219204 <_Z10Audio_LoadPhjS_+0x1bc> */
/* @0x219344 mov r0, #1 */
/* @0x219348 add sp, sp, #28 */
/* @0x21934c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x219350 ldr r2, [pc, #0x74] */
/* @0x219354 mov r3, #0 */
/* @0x219358 mov r1, r4 */
/* @0x21935c str r3, [sp] */
/* @0x219360 add r2, pc, r2 */
/* @0x219364 mov r3, #135 */
/* @0x219368 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21936c ldr r3, [pc, #0x5c] */
/* @0x219370 add r3, pc, r3 */
/* @0x219374 str r0, [r3, #0x24] */
/* @0x219378 b 0x219170 <_Z10Audio_LoadPhjS_+0x128> */
/* @0x21937c mov r5, r1 */
/* @0x219380 b 0x2192e8 <_Z10Audio_LoadPhjS_+0x2a0> */
/* @0x219384 andseq r6, sp, r12, asr #21 */
/* @0x219388 subseq r12, r3, r12, lsr #4 */
/* @0x21938c ldrsbeq r10, [r3], -r0 */
/* @0x219390 ldrsbeq r12, [r3], #-24 */
/* @0x219394 ldrsbeq r12, [r3], #-20 */
/* @0x219398 subseq r12, r3, r12, asr #2 */
/* @0x21939c subseq r12, r3, r12, lsr #2 */
/* @0x2193a0 subseq r12, r3, r0, lsr #2 */
/* @0x2193a4 subseq r12, r3, r12, lsl #2 */
/* @0x2193a8 subseq r12, r3, r4, ror #1 */
/* @0x2193ac .word 0x0053c098 */
/* @0x2193b0 subseq r12, r3, r8, lsl #1 */
/* @0x2193b4 andseq r10, r3, r8, ror r11 */
/* @0x2193b8 andseq r4, sp, r4, lsl r7 */
/* @0x2193bc subseq r11, r3, r0, lsr #31 */
/* @0x2193c0 andseq r10, r3, r0, asr #20 */
/* @0x2193c4 subseq r11, r3, r0, ror pc */
/* @0x2193c8 subseq r11, r3, r12, asr pc */
/* @0x2193cc mulseq r3, r0, pc */
/* @0x2193d0 subseq r11, r3, r4, lsr #30 */

/* ── FUNC 0x2193d4 · cAudio_Sound::FreeALBuffer() · size=48 · insn=12 */
/* @0x2193d4 push {r4, lr} */
/* @0x2193d8 mov r4, r0 */
/* @0x2193dc ldr r0, [r0, #0x18] */
/* @0x2193e0 bl 0xb6ad8 <alIsBuffer@plt> */
/* @0x2193e4 cmp r0, #0 */
/* @0x2193e8 popeq {r4, pc} */
/* @0x2193ec mov r0, #1 */
/* @0x2193f0 add r1, r4, #24 */
/* @0x2193f4 bl 0xb6ae4 <alDeleteBuffers@plt> */
/* @0x2193f8 mvn r3, #0 */
/* @0x2193fc str r3, [r4, #0x18] */
/* @0x219400 pop {r4, pc} */

/* ── FUNC 0x219404 · cAudio_Sound::Prepare(int) · size=220 · insn=55 */
/* @0x219404 push {r3, r4, r5, lr} */
/* @0x219408 mov r4, r0 */
/* @0x21940c ldr r3, [pc, #0xc0] */
/* @0x219410 ldr r3, [pc, r3] */
/* @0x219414 ldrb r2, [r3] */
/* @0x219418 cmp r2, #0 */
/* @0x21941c popne {r3, r4, r5, pc} */
/* @0x219420 ldr r0, [r0, #0xc] */
/* @0x219424 cmp r0, #0 */
/* @0x219428 popeq {r3, r4, r5, pc} */
/* @0x21942c ldr r3, [pc, #0xa4] */
/* @0x219430 ldr r3, [pc, r3] */
/* @0x219434 ldr r3, [r3, #0x4] */
/* @0x219438 cmp r3, #0 */
/* @0x21943c ble 0x2194ac <_ZN12cAudio_Sound7PrepareEi+0xa8> */
/* @0x219440 ldr r3, [r4, #0x4c] */
/* @0x219444 cmp r1, r3 */
/* @0x219448 popne {r3, r4, r5, pc} */
/* @0x21944c ldrb r3, [r4, #0x24] */
/* @0x219450 cmp r3, #0 */
/* @0x219454 movne r3, #0 */
/* @0x219458 strne r3, [r4, #0x30] */
/* @0x21945c popne {r3, r4, r5, pc} */
/* @0x219460 ldrb r3, [r4, #0x26] */
/* @0x219464 ldr r2, [r0], #4 */
/* @0x219468 cmp r3, #0 */
/* @0x21946c bne 0x2194b4 <_ZN12cAudio_Sound7PrepareEi+0xb0> */
/* @0x219470 ldrb r3, [r4, #0x25] */
/* @0x219474 cmp r3, #0 */
/* @0x219478 strne r0, [r4, #0x28] */
/* @0x21947c strne r2, [r4, #0x2c] */
/* @0x219480 popne {r3, r4, r5, pc} */
/* @0x219484 mov r1, r2 */
/* @0x219488 bl 0x222638 <alutCreateBufferFromFileImage> */
/* @0x21948c mov r5, r0 */
/* @0x219490 bl 0x221714 <alutGetError> */
/* @0x219494 cmp r0, #0 */
/* @0x219498 popne {r3, r4, r5, pc} */
/* @0x21949c bl 0xb6a54 <alGetError@plt> */
/* @0x2194a0 cmp r0, #0 */
/* @0x2194a4 streq r5, [r4, #0x18] */
/* @0x2194a8 pop {r3, r4, r5, pc} */
/* @0x2194ac str r2, [r4, #0x4c] */
/* @0x2194b0 b 0x21944c <_ZN12cAudio_Sound7PrepareEi+0x48> */
/* @0x2194b4 str r0, [r4, #0x28] */
/* @0x2194b8 mov r1, r4 */
/* @0x2194bc ldr r0, [pc, #0x18] */
/* @0x2194c0 str r2, [r4, #0x2c] */
/* @0x2194c4 add r0, pc, r0 */
/* @0x2194c8 bl 0x226dec <_ZN9COggAudio13DecompressOggEP12cAudio_Sound> */
/* @0x2194cc str r0, [r4, #0x18] */
/* @0x2194d0 pop {r3, r4, r5, pc} */
/* @0x2194d4 andseq r5, sp, r12, lsr r12 */
/* @0x2194d8 andseq r5, sp, r0, lsr #24 */
/* @0x2194dc ldrsbeq r11, [r3], #-208 */

/* ── FUNC 0x2194e0 · Audio_Prepare() · size=176 · insn=44 */
/* @0x2194e0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2194e4 ldr r3, [pc, #0x8c] */
/* @0x2194e8 ldr r3, [pc, r3] */
/* @0x2194ec ldrb r4, [r3] */
/* @0x2194f0 cmp r4, #0 */
/* @0x2194f4 popne {r3, r4, r5, r6, r7, pc} */
/* @0x2194f8 ldr r3, [pc, #0x7c] */
/* @0x2194fc ldr r3, [pc, r3] */
/* @0x219500 ldrb r3, [r3] */
/* @0x219504 cmp r3, #0 */
/* @0x219508 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x21950c ldr r5, [pc, #0x6c] */
/* @0x219510 ldr r0, [pc, #0x6c] */
/* @0x219514 add r5, pc, r5 */
/* @0x219518 add r1, r5, #32 */
/* @0x21951c ldr r0, [pc, r0] */
/* @0x219520 bl 0x21df78 <_ZN14CAudioGroupMan14InitSoundListsER12cARRAY_CLASSIP12cAudio_SoundE> */
/* @0x219524 ldr r5, [r5, #0x20] */
/* @0x219528 cmp r5, #0 */
/* @0x21952c pople {r3, r4, r5, r6, r7, pc} */
/* @0x219530 ldr r7, [pc, #0x50] */
/* @0x219534 mov r3, r5 */
/* @0x219538 ldr r6, [pc, #0x4c] */
/* @0x21953c add r7, pc, r7 */
/* @0x219540 add r6, pc, r6 */
/* @0x219544 cmp r3, r4 */
/* @0x219548 mov r1, #0 */
/* @0x21954c ble 0x219564 <_Z13Audio_Preparev+0x84> */
/* @0x219550 ldr r3, [r7, #0x24] */
/* @0x219554 ldr r0, [r3, r4, lsl #2] */
/* @0x219558 cmp r0, r1 */
/* @0x21955c beq 0x219564 <_Z13Audio_Preparev+0x84> */
/* @0x219560 bl 0x219404 <_ZN12cAudio_Sound7PrepareEi> */
/* @0x219564 add r4, r4, #1 */
/* @0x219568 cmp r4, r5 */
/* @0x21956c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x219570 ldr r3, [r6, #0x20] */
/* @0x219574 b 0x219544 <_Z13Audio_Preparev+0x64> */
/* @0x219578 andseq r5, sp, r4, ror #22 */
/* @0x21957c andseq r5, sp, r4, lsr r8 */
/* @0x219580 subseq r11, r3, r0, lsl #27 */
/* @0x219584 andseq r5, sp, r4, lsr r11 */
/* @0x219588 subseq r11, r3, r8, asr sp */
/* @0x21958c subseq r11, r3, r4, asr sp */

/* ── FUNC 0x219590 · Audio_PrepareGroup(int) · size=240 · insn=60 */
/* @0x219590 push {r4, r5, r6, r7, r8, lr} */
/* @0x219594 mov r6, r0 */
/* @0x219598 ldr r7, [pc, #0xd8] */
/* @0x21959c mov r1, r6 */
/* @0x2195a0 ldr r0, [pc, #0xd4] */
/* @0x2195a4 add r7, pc, r7 */
/* @0x2195a8 ldr r0, [pc, r0] */
/* @0x2195ac ldr r5, [r7, #0x20] */
/* @0x2195b0 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi> */
/* @0x2195b4 cmp r5, #0 */
/* @0x2195b8 mov r8, r0 */
/* @0x2195bc pople {r4, r5, r6, r7, r8, pc} */
/* @0x2195c0 cmp r0, #0 */
/* @0x2195c4 movne r4, #0 */
/* @0x2195c8 bne 0x2195dc <_Z18Audio_PrepareGroupi+0x4c> */
/* @0x2195cc b 0x219624 <_Z18Audio_PrepareGroupi+0x94> */
/* @0x2195d0 add r4, r4, #1 */
/* @0x2195d4 cmp r4, r5 */
/* @0x2195d8 beq 0x219620 <_Z18Audio_PrepareGroupi+0x90> */
/* @0x2195dc ldr r3, [r7, #0x20] */
/* @0x2195e0 cmp r3, r4 */
/* @0x2195e4 ble 0x2195d0 <_Z18Audio_PrepareGroupi+0x40> */
/* @0x2195e8 ldr r3, [r7, #0x24] */
/* @0x2195ec ldr r0, [r3, r4, lsl #2] */
/* @0x2195f0 cmp r0, #0 */
/* @0x2195f4 beq 0x2195d0 <_Z18Audio_PrepareGroupi+0x40> */
/* @0x2195f8 ldr r2, [r0, #0x4c] */
/* @0x2195fc cmp r2, r6 */
/* @0x219600 bne 0x2195d0 <_Z18Audio_PrepareGroupi+0x40> */
/* @0x219604 mov r1, r6 */
/* @0x219608 add r4, r4, #1 */
/* @0x21960c bl 0x219404 <_ZN12cAudio_Sound7PrepareEi> */
/* @0x219610 mov r0, r8 */
/* @0x219614 bl 0x21ddf4 <_ZN11CAudioGroup12IncLoadCountEv> */
/* @0x219618 cmp r4, r5 */
/* @0x21961c bne 0x2195dc <_Z18Audio_PrepareGroupi+0x4c> */
/* @0x219620 pop {r4, r5, r6, r7, r8, pc} */
/* @0x219624 mov r4, r0 */
/* @0x219628 b 0x219638 <_Z18Audio_PrepareGroupi+0xa8> */
/* @0x21962c add r4, r4, #1 */
/* @0x219630 cmp r4, r5 */
/* @0x219634 beq 0x219674 <_Z18Audio_PrepareGroupi+0xe4> */
/* @0x219638 ldr r3, [r7, #0x20] */
/* @0x21963c cmp r3, r4 */
/* @0x219640 ble 0x21962c <_Z18Audio_PrepareGroupi+0x9c> */
/* @0x219644 ldr r3, [r7, #0x24] */
/* @0x219648 ldr r0, [r3, r4, lsl #2] */
/* @0x21964c cmp r0, #0 */
/* @0x219650 beq 0x21962c <_Z18Audio_PrepareGroupi+0x9c> */
/* @0x219654 ldr r3, [r0, #0x4c] */
/* @0x219658 cmp r3, r6 */
/* @0x21965c bne 0x21962c <_Z18Audio_PrepareGroupi+0x9c> */
/* @0x219660 mov r1, r6 */
/* @0x219664 add r4, r4, #1 */
/* @0x219668 bl 0x219404 <_ZN12cAudio_Sound7PrepareEi> */
/* @0x21966c cmp r4, r5 */
/* @0x219670 bne 0x219638 <_Z18Audio_PrepareGroupi+0xa8> */
/* @0x219674 pop {r4, r5, r6, r7, r8, pc} */
/* @0x219678 ldrsheq r11, [r3], #-192 */
/* @0x21967c andseq r5, sp, r8, lsr #21 */

/* ── FUNC 0x219680 · Audio_WAVs(unsigned char*, unsigned int, unsigned char*, int) · size=276 · insn=69 */
/* @0x219680 ldr r12, [pc, #0xfc] */
/* @0x219684 push {r3, r4, r5, r6, r7, lr} */
/* @0x219688 ldr r12, [pc, r12] */
/* @0x21968c mov r4, r0 */
/* @0x219690 mov r7, r2 */
/* @0x219694 ldr r0, [r12] */
/* @0x219698 mov r6, r3 */
/* @0x21969c ldr r1, [pc, #0xe4] */
/* @0x2196a0 ldr r2, [r0] */
/* @0x2196a4 add r1, pc, r1 */
/* @0x2196a8 ldr r3, [r2, #0xc] */
/* @0x2196ac blx r3 */
/* @0x2196b0 ldr r2, [pc, #0xd4] */
/* @0x2196b4 add r0, r4, #4 */
/* @0x2196b8 add r2, pc, r2 */
/* @0x2196bc ldr r5, [r2, #0x20] */
/* @0x2196c0 cmp r5, #0 */
/* @0x2196c4 ble 0x21971c <_Z10Audio_WAVsPhjS_i+0x9c> */
/* @0x2196c8 ldr r3, [pc, #0xc0] */
/* @0x2196cc ldr r1, [r2, #0x24] */
/* @0x2196d0 ldr r3, [pc, r3] */
/* @0x2196d4 ldr r3, [r3, #0x4] */
/* @0x2196d8 cmp r3, #0 */
/* @0x2196dc ble 0x219724 <_Z10Audio_WAVsPhjS_i+0xa4> */
/* @0x2196e0 add r5, r1, r5, lsl #2 */
/* @0x2196e4 ldr r12, [r1], #4 */
/* @0x2196e8 cmp r12, #0 */
/* @0x2196ec beq 0x219714 <_Z10Audio_WAVsPhjS_i+0x94> */
/* @0x2196f0 ldr r4, [r12, #0x4c] */
/* @0x2196f4 cmp r6, r4 */
/* @0x2196f8 bne 0x219714 <_Z10Audio_WAVsPhjS_i+0x94> */
/* @0x2196fc ldr r3, [r12, #0x14] */
/* @0x219700 ldr r4, [r0, r3, lsl #2] */
/* @0x219704 cmp r4, #0 */
/* @0x219708 add r3, r7, r4 */
/* @0x21970c moveq r3, r4 */
/* @0x219710 str r3, [r12, #0xc] */
/* @0x219714 cmp r1, r5 */
/* @0x219718 bne 0x2196e4 <_Z10Audio_WAVsPhjS_i+0x64> */
/* @0x21971c mov r0, #1 */
/* @0x219720 pop {r3, r4, r5, r6, r7, pc} */
/* @0x219724 cmp r6, #0 */
/* @0x219728 mov r2, #0 */
/* @0x21972c add r5, r1, r5, lsl #2 */
/* @0x219730 beq 0x219758 <_Z10Audio_WAVsPhjS_i+0xd8> */
/* @0x219734 ldr r3, [r1], #4 */
/* @0x219738 cmp r1, r5 */
/* @0x21973c str r2, [r3, #0x4c] */
/* @0x219740 beq 0x21971c <_Z10Audio_WAVsPhjS_i+0x9c> */
/* @0x219744 ldr r3, [r1], #4 */
/* @0x219748 cmp r1, r5 */
/* @0x21974c str r2, [r3, #0x4c] */
/* @0x219750 bne 0x219734 <_Z10Audio_WAVsPhjS_i+0xb4> */
/* @0x219754 b 0x21971c <_Z10Audio_WAVsPhjS_i+0x9c> */
/* @0x219758 ldr r3, [r1], #4 */
/* @0x21975c ldr r12, [r3, #0x14] */
/* @0x219760 str r2, [r3, #0x4c] */
/* @0x219764 ldr r12, [r0, r12, lsl #2] */
/* @0x219768 cmp r12, #0 */
/* @0x21976c mov r4, r12 */
/* @0x219770 addne r4, r7, r12 */
/* @0x219774 cmp r1, r5 */
/* @0x219778 str r4, [r3, #0xc] */
/* @0x21977c bne 0x219758 <_Z10Audio_WAVsPhjS_i+0xd8> */
/* @0x219780 b 0x21971c <_Z10Audio_WAVsPhjS_i+0x9c> */
/* @0x219784 mulseq sp, r4, r4 */
/* @0x219788 andseq r10, r3, r8, lsr #14 */
/* @0x21978c ldrsbeq r11, [r3], #-188 */
/* @0x219790 andseq r5, sp, r0, lsl #19 */

/* ── FUNC 0x219794 · Audio_Find(char const*) · size=104 · insn=26 */
/* @0x219794 ldr r3, [pc, #0x5c] */
/* @0x219798 push {r4, r5, r6, r7, r8, lr} */
/* @0x21979c add r3, pc, r3 */
/* @0x2197a0 mov r8, r0 */
/* @0x2197a4 ldr r7, [r3, #0x48] */
/* @0x2197a8 cmp r7, #0 */
/* @0x2197ac ble 0x2197f0 <_Z10Audio_FindPKc+0x5c> */
/* @0x2197b0 ldr r5, [r3, #0x4c] */
/* @0x2197b4 mov r4, #0 */
/* @0x2197b8 mvn r6, #0 */
/* @0x2197bc sub r5, r5, #4 */
/* @0x2197c0 ldr r0, [r5, #0x4]! */
/* @0x2197c4 mov r1, r8 */
/* @0x2197c8 cmp r0, #0 */
/* @0x2197cc beq 0x2197dc <_Z10Audio_FindPKc+0x48> */
/* @0x2197d0 bl 0xb6574 <strcmp@plt> */
/* @0x2197d4 cmp r0, #0 */
/* @0x2197d8 moveq r6, r4 */
/* @0x2197dc add r4, r4, #1 */
/* @0x2197e0 cmp r4, r7 */
/* @0x2197e4 bne 0x2197c0 <_Z10Audio_FindPKc+0x2c> */
/* @0x2197e8 mov r0, r6 */
/* @0x2197ec pop {r4, r5, r6, r7, r8, pc} */
/* @0x2197f0 mvn r6, #0 */
/* @0x2197f4 b 0x2197e8 <_Z10Audio_FindPKc+0x54> */
/* @0x2197f8 ldrsheq r11, [r3], #-168 */

/* ── FUNC 0x2197fc · Audio_Suspend() · size=116 · insn=29 */
/* @0x2197fc ldr r3, [pc, #0x58] */
/* @0x219800 push {r4, lr} */
/* @0x219804 ldr r3, [pc, r3] */
/* @0x219808 ldr r1, [pc, #0x50] */
/* @0x21980c ldr r4, [r3] */
/* @0x219810 add r1, pc, r1 */
/* @0x219814 ldr r3, [r4] */
/* @0x219818 mov r0, r4 */
/* @0x21981c ldr r3, [r3, #0xc] */
/* @0x219820 blx r3 */
/* @0x219824 ldr r3, [pc, #0x38] */
/* @0x219828 ldr r0, [pc, #0x38] */
/* @0x21982c mov r2, #1 */
/* @0x219830 ldr r3, [pc, r3] */
/* @0x219834 add r0, pc, r0 */
/* @0x219838 strb r2, [r3] */
/* @0x21983c bl 0x22609c <_ZN9COggAudio7SuspendEv> */
/* @0x219840 ldr r3, [r4] */
/* @0x219844 mov r0, r4 */
/* @0x219848 ldr r1, [pc, #0x1c] */
/* @0x21984c ldr r3, [r3, #0xc] */
/* @0x219850 add r1, pc, r1 */
/* @0x219854 blx r3 */
/* @0x219858 pop {r4, pc} */
/* @0x21985c andseq r3, sp, r0, lsl pc */
/* @0x219860 andseq r10, r3, r12, asr #11 */
/* @0x219864 ldrheq r7, [sp], -r12 */
/* @0x219868 subseq r11, r3, r0, ror #20 */
/* @0x21986c andseq r10, r3, r4, lsr #11 */

/* ── FUNC 0x219870 · Audio_Unsuspend() · size=48 · insn=12 */
/* @0x219870 ldr r3, [pc, #0x20] */
/* @0x219874 ldr r3, [pc, r3] */
/* @0x219878 ldrb r2, [r3] */
/* @0x21987c cmp r2, #0 */
/* @0x219880 bxeq lr */
/* @0x219884 ldr r0, [pc, #0x10] */
/* @0x219888 mov r2, #0 */
/* @0x21988c strb r2, [r3] */
/* @0x219890 add r0, pc, r0 */
/* @0x219894 b 0x226100 <_ZN9COggAudio9UnsuspendEv> */
/* @0x219898 andseq r7, sp, r8, ror r11 */
/* @0x21989c subseq r11, r3, r4, lsl #20 */

/* ── FUNC 0x2198a0 · Audio_CreateBufferSound(int, int, int, int, int, int) · size=1232 · insn=308 */
/* @0x2198a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2198a4 cmp r1, #4 */
/* @0x2198a8 cmpne r1, #1 */
/* @0x2198ac sub sp, sp, #60 */
/* @0x2198b0 ldr r4, [pc, #0x46c] */
/* @0x2198b4 mov r9, r1 */
/* @0x2198b8 mov r5, r2 */
/* @0x2198bc add r4, pc, r4 */
/* @0x2198c0 mov r10, r3 */
/* @0x2198c4 str r0, [sp, #0xc] */
/* @0x2198c8 ldr r7, [sp, #0x60] */
/* @0x2198cc bne 0x219b98 <_Z23Audio_CreateBufferSoundiiiiii+0x2f8> */
/* @0x2198d0 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x2198d4 subs r6, r0, #0 */
/* @0x2198d8 beq 0x219c60 <_Z23Audio_CreateBufferSoundiiiiii+0x3c0> */
/* @0x2198dc ldr r8, [r6, #0x20] */
/* @0x2198e0 cmp r8, #0 */
/* @0x2198e4 beq 0x219c34 <_Z23Audio_CreateBufferSoundiiiiii+0x394> */
/* @0x2198e8 cmp r5, #1000 */
/* @0x2198ec movlt r5, #1000 */
/* @0x2198f0 bge 0x219b5c <_Z23Audio_CreateBufferSoundiiiiii+0x2bc> */
/* @0x2198f4 ldr r1, [sp, #0x64] */
/* @0x2198f8 cmp r1, #2 */
/* @0x2198fc bhi 0x219c1c <_Z23Audio_CreateBufferSoundiiiiii+0x37c> */
/* @0x219900 bic r10, r10, r10, asr #31 */
/* @0x219904 add r3, r10, r7 */
/* @0x219908 cmp r8, r3 */
/* @0x21990c blt 0x219bec <_Z23Audio_CreateBufferSoundiiiiii+0x34c> */
/* @0x219910 ldr r3, [pc, #0x410] */
/* @0x219914 cmp r7, #0 */
/* @0x219918 rsbeq r7, r10, r8 */
/* @0x21991c add r3, pc, r3 */
/* @0x219920 ldr r0, [r3, #0x28] */
/* @0x219924 cmp r0, #0 */
/* @0x219928 ble 0x219960 <_Z23Audio_CreateBufferSoundiiiiii+0xc0> */
/* @0x21992c ldr r2, [r3, #0x2c] */
/* @0x219930 ldr r12, [r2] */
/* @0x219934 cmp r12, #0 */
/* @0x219938 movne r3, #0 */
/* @0x21993c bne 0x219950 <_Z23Audio_CreateBufferSoundiiiiii+0xb0> */
/* @0x219940 b 0x219c74 <_Z23Audio_CreateBufferSoundiiiiii+0x3d4> */
/* @0x219944 ldr r1, [r2, #0x4]! */
/* @0x219948 cmp r1, #0 */
/* @0x21994c beq 0x219cb0 <_Z23Audio_CreateBufferSoundiiiiii+0x410> */
/* @0x219950 add r3, r3, #1 */
/* @0x219954 cmp r3, r0 */
/* @0x219958 lsl r12, r3, #2 */
/* @0x21995c bne 0x219944 <_Z23Audio_CreateBufferSoundiiiiii+0xa4> */
/* @0x219960 mov r0, #96 */
/* @0x219964 ldr r11, [pc, #0x3c0] */
/* @0x219968 bl 0x27c524 <_Znwj> */
/* @0x21996c add r11, pc, r11 */
/* @0x219970 mov r4, r0 */
/* @0x219974 bl 0x218ea4 <_ZN12cAudio_SoundC2Ev> */
/* @0x219978 ldr r12, [r11, #0x28] */
/* @0x21997c adds r2, r12, #16 */
/* @0x219980 str r2, [sp, #0x10] */
/* @0x219984 bne 0x219bb0 <_Z23Audio_CreateBufferSoundiiiiii+0x310> */
/* @0x219988 ldr r3, [r11, #0x2c] */
/* @0x21998c cmp r3, #0 */
/* @0x219990 beq 0x219b70 <_Z23Audio_CreateBufferSoundiiiiii+0x2d0> */
/* @0x219994 cmp r12, #0 */
/* @0x219998 ble 0x219a64 <_Z23Audio_CreateBufferSoundiiiiii+0x1c4> */
/* @0x21999c ldr r1, [pc, #0x38c] */
/* @0x2199a0 ldr r2, [pc, #0x38c] */
/* @0x2199a4 add r1, pc, r1 */
/* @0x2199a8 str r1, [sp, #0x14] */
/* @0x2199ac add r2, pc, r2 */
/* @0x2199b0 mov r1, r11 */
/* @0x2199b4 str r6, [sp, #0x20] */
/* @0x2199b8 ldr r11, [sp, #0x10] */
/* @0x2199bc ldr r6, [sp, #0x14] */
/* @0x2199c0 str r10, [sp, #0x1c] */
/* @0x2199c4 mov r10, r2 */
/* @0x2199c8 str r5, [sp, #0x28] */
/* @0x2199cc mov r5, r1 */
/* @0x2199d0 str r4, [sp, #0x18] */
/* @0x2199d4 str r12, [sp, #0x24] */
/* @0x2199d8 str r7, [sp, #0x2c] */
/* @0x2199dc ldr r0, [r3] */
/* @0x2199e0 movw r1, #0xfeee */
/* @0x2199e4 movt r1, #0xfeee */
/* @0x2199e8 movw r2, #0xfeee */
/* @0x2199ec cmp r0, r1 */
/* @0x2199f0 movt r2, #0xfeee */
/* @0x2199f4 lsl r7, r11, #2 */
/* @0x2199f8 beq 0x219a3c <_Z23Audio_CreateBufferSoundiiiiii+0x19c> */
/* @0x2199fc ldr r4, [r3, r11, lsl #2] */
/* @0x219a00 add lr, r3, r7 */
/* @0x219a04 cmp r4, #0 */
/* @0x219a08 mov r0, r4 */
/* @0x219a0c beq 0x219a3c <_Z23Audio_CreateBufferSoundiiiiii+0x19c> */
/* @0x219a10 ldr r3, [r4] */
/* @0x219a14 cmp r3, r2 */
/* @0x219a18 beq 0x219a30 <_Z23Audio_CreateBufferSoundiiiiii+0x190> */
/* @0x219a1c bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x219a20 mov r0, r4 */
/* @0x219a24 bl 0x27d1d0 <_ZdlPv> */
/* @0x219a28 ldr lr, [r10, #0x2c] */
/* @0x219a2c add lr, lr, r7 */
/* @0x219a30 mov r2, #0 */
/* @0x219a34 str r2, [lr] */
/* @0x219a38 ldr r3, [r6, #0x2c] */
/* @0x219a3c ldr r2, [r5, #0x28] */
/* @0x219a40 add r11, r11, #1 */
/* @0x219a44 cmp r11, r2 */
/* @0x219a48 blt 0x2199dc <_Z23Audio_CreateBufferSoundiiiiii+0x13c> */
/* @0x219a4c ldr r4, [sp, #0x18] */
/* @0x219a50 ldr r10, [sp, #0x1c] */
/* @0x219a54 ldr r6, [sp, #0x20] */
/* @0x219a58 ldr r12, [sp, #0x24] */
/* @0x219a5c ldr r5, [sp, #0x28] */
/* @0x219a60 ldr r7, [sp, #0x2c] */
/* @0x219a64 mov r0, r3 */
/* @0x219a68 str r12, [sp, #0x8] */
/* @0x219a6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x219a70 ldr r1, [pc, #0x2c0] */
/* @0x219a74 ldr r12, [sp, #0x8] */
/* @0x219a78 mov r2, #0 */
/* @0x219a7c add r1, pc, r1 */
/* @0x219a80 mov r3, r2 */
/* @0x219a84 str r2, [r1, #0x2c] */
/* @0x219a88 ldr r2, [pc, #0x2ac] */
/* @0x219a8c add r11, r12, #99328 */
/* @0x219a90 ldr r1, [sp, #0x10] */
/* @0x219a94 add r11, r11, #672 */
/* @0x219a98 add r2, pc, r2 */
/* @0x219a9c str r1, [r2, #0x28] */
/* @0x219aa0 str r4, [r3, r12, lsl #2] */
/* @0x219aa4 add r1, sp, #56 */
/* @0x219aa8 mov r3, #0 */
/* @0x219aac mov r0, #1 */
/* @0x219ab0 str r3, [r1, #-0x4]! */
/* @0x219ab4 bl 0xb6af0 <alGenBuffers@plt> */
/* @0x219ab8 ldr r0, [pc, #0x280] */
/* @0x219abc add r0, pc, r0 */
/* @0x219ac0 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x219ac4 cmp r9, #1 */
/* @0x219ac8 beq 0x219d0c <_Z23Audio_CreateBufferSoundiiiiii+0x46c> */
/* @0x219acc ldr r1, [sp, #0x64] */
/* @0x219ad0 cmp r1, #1 */
/* @0x219ad4 movwne r9, #0x1101 */
/* @0x219ad8 beq 0x219cbc <_Z23Audio_CreateBufferSoundiiiiii+0x41c> */
/* @0x219adc ldr r2, [r6, #0xc] */
/* @0x219ae0 mov r3, r7 */
/* @0x219ae4 ldr r0, [sp, #0x34] */
/* @0x219ae8 mov r1, r9 */
/* @0x219aec add r2, r2, r10 */
/* @0x219af0 str r5, [sp] */
/* @0x219af4 bl 0xb6afc <alBufferData@plt> */
/* @0x219af8 ldr r0, [pc, #0x244] */
/* @0x219afc add r0, pc, r0 */
/* @0x219b00 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x219b04 vmov s13, r8 */
/* @0x219b08 movw r2, #0x1101 */
/* @0x219b0c cmp r9, r2 */
/* @0x219b10 vcvt.f32.s32 s14, s13 */
/* @0x219b14 ldr r3, [sp, #0x34] */
/* @0x219b18 vmov s13, r5 */
/* @0x219b1c mov r2, #1 */
/* @0x219b20 str r2, [r4, #0x3c] */
/* @0x219b24 str r3, [r4, #0x18] */
/* @0x219b28 vcvt.f32.s32 s15, s13 */
/* @0x219b2c vdiv.f32 s15, s14, s15 */
/* @0x219b30 vmoveq.f32 s14, #5.000000e-01 */
/* @0x219b34 vmuleq.f32 s15, s15, s14 */
/* @0x219b38 ldr r1, [sp, #0xc] */
/* @0x219b3c mov r0, r11 */
/* @0x219b40 vstr s15, [r4, #52] */
/* @0x219b44 str r1, [r4, #0x10] */
/* @0x219b48 ldr r3, [r6, #0x28] */
/* @0x219b4c add r3, r3, #1 */
/* @0x219b50 str r3, [r6, #0x28] */
/* @0x219b54 add sp, sp, #60 */
/* @0x219b58 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x219b5c movw r3, #0xbb80 */
/* @0x219b60 cmp r5, r3 */
/* @0x219b64 movge r5, r3 */
/* @0x219b68 b 0x2198f4 <_Z23Audio_CreateBufferSoundiiiiii+0x54> */
/* @0x219b6c ldr r3, [r11, #0x2c] */
/* @0x219b70 mov r0, r3 */
/* @0x219b74 str r12, [sp, #0x8] */
/* @0x219b78 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x219b7c ldr r1, [pc, #0x1c4] */
/* @0x219b80 mov r2, #0 */
/* @0x219b84 ldr r12, [sp, #0x8] */
/* @0x219b88 add r1, pc, r1 */
/* @0x219b8c mov r3, r2 */
/* @0x219b90 str r2, [r1, #0x2c] */
/* @0x219b94 b 0x219a88 <_Z23Audio_CreateBufferSoundiiiiii+0x1e8> */
/* @0x219b98 ldr r0, [pc, #0x1ac] */
/* @0x219b9c mov r1, #0 */
/* @0x219ba0 add r0, pc, r0 */
/* @0x219ba4 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x219ba8 mvn r0, #0 */
/* @0x219bac b 0x219b54 <_Z23Audio_CreateBufferSoundiiiiii+0x2b4> */
/* @0x219bb0 ldr r3, [sp, #0x10] */
/* @0x219bb4 lsls r1, r3, #2 */
/* @0x219bb8 beq 0x219b6c <_Z23Audio_CreateBufferSoundiiiiii+0x2cc> */
/* @0x219bbc ldr r2, [pc, #0x18c] */
/* @0x219bc0 mov r3, #0 */
/* @0x219bc4 ldr r0, [r11, #0x2c] */
/* @0x219bc8 add r2, pc, r2 */
/* @0x219bcc str r3, [sp] */
/* @0x219bd0 mov r3, #135 */
/* @0x219bd4 str r12, [sp, #0x8] */
/* @0x219bd8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x219bdc ldr r12, [sp, #0x8] */
/* @0x219be0 mov r3, r0 */
/* @0x219be4 str r0, [r11, #0x2c] */
/* @0x219be8 b 0x219a88 <_Z23Audio_CreateBufferSoundiiiiii+0x1e8> */
/* @0x219bec ldr r0, [pc, #0x160] */
/* @0x219bf0 mov r2, r10 */
/* @0x219bf4 ldr r1, [pc, #0x15c] */
/* @0x219bf8 mov r3, r7 */
/* @0x219bfc ldr r0, [r4, r0] */
/* @0x219c00 add r1, pc, r1 */
/* @0x219c04 ldr r0, [r0] */
/* @0x219c08 ldr r12, [r0] */
/* @0x219c0c ldr r12, [r12, #0xc] */
/* @0x219c10 blx r12 */
/* @0x219c14 mvn r0, #0 */
/* @0x219c18 b 0x219b54 <_Z23Audio_CreateBufferSoundiiiiii+0x2b4> */
/* @0x219c1c ldr r0, [pc, #0x138] */
/* @0x219c20 mov r1, #0 */
/* @0x219c24 add r0, pc, r0 */
/* @0x219c28 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x219c2c mvn r0, #0 */
/* @0x219c30 b 0x219b54 <_Z23Audio_CreateBufferSoundiiiiii+0x2b4> */
/* @0x219c34 ldr r1, [pc, #0x124] */
/* @0x219c38 ldr r3, [pc, #0x114] */
/* @0x219c3c ldr r2, [sp, #0xc] */
/* @0x219c40 add r1, pc, r1 */
/* @0x219c44 ldr r3, [r4, r3] */
/* @0x219c48 ldr r0, [r3] */
/* @0x219c4c ldr r3, [r0] */
/* @0x219c50 ldr r3, [r3, #0xc] */
/* @0x219c54 blx r3 */
/* @0x219c58 mvn r0, #0 */
/* @0x219c5c b 0x219b54 <_Z23Audio_CreateBufferSoundiiiiii+0x2b4> */
/* @0x219c60 ldr r1, [pc, #0xfc] */
/* @0x219c64 ldr r3, [pc, #0xe8] */
/* @0x219c68 ldr r2, [sp, #0xc] */
/* @0x219c6c add r1, pc, r1 */
/* @0x219c70 b 0x219c44 <_Z23Audio_CreateBufferSoundiiiiii+0x3a4> */
/* @0x219c74 movw r11, #0x86a0 */
/* @0x219c78 movt r11, #0x1 */
/* @0x219c7c mov r0, #96 */
/* @0x219c80 str r12, [sp, #0x8] */
/* @0x219c84 bl 0x27c524 <_Znwj> */
/* @0x219c88 mov r4, r0 */
/* @0x219c8c bl 0x218ea4 <_ZN12cAudio_SoundC2Ev> */
/* @0x219c90 ldr r3, [pc, #0xd0] */
/* @0x219c94 cmp r4, #0 */
/* @0x219c98 ldr r12, [sp, #0x8] */
/* @0x219c9c add r3, pc, r3 */
/* @0x219ca0 ldr r3, [r3, #0x2c] */
/* @0x219ca4 str r4, [r3, r12] */
/* @0x219ca8 bne 0x219aa4 <_Z23Audio_CreateBufferSoundiiiiii+0x204> */
/* @0x219cac b 0x219960 <_Z23Audio_CreateBufferSoundiiiiii+0xc0> */
/* @0x219cb0 add r3, r3, #99328 */
/* @0x219cb4 add r11, r3, #672 */
/* @0x219cb8 b 0x219c7c <_Z23Audio_CreateBufferSoundiiiiii+0x3dc> */
/* @0x219cbc movw r1, #0x1103 */
/* @0x219cc0 ldr r2, [r6, #0xc] */
/* @0x219cc4 mov r3, r7 */
/* @0x219cc8 ldr r0, [sp, #0x34] */
/* @0x219ccc add r2, r2, r10 */
/* @0x219cd0 str r5, [sp] */
/* @0x219cd4 bl 0xb6afc <alBufferData@plt> */
/* @0x219cd8 ldr r0, [pc, #0x8c] */
/* @0x219cdc add r0, pc, r0 */
/* @0x219ce0 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x219ce4 vmov s13, r8 */
/* @0x219ce8 ldr r3, [sp, #0x34] */
/* @0x219cec mov r2, #2 */
/* @0x219cf0 vcvt.f32.s32 s14, s13 */
/* @0x219cf4 str r2, [r4, #0x3c] */
/* @0x219cf8 vmov s13, r5 */
/* @0x219cfc str r3, [r4, #0x18] */
/* @0x219d00 vcvt.f32.s32 s15, s13 */
/* @0x219d04 vdiv.f32 s15, s14, s15 */
/* @0x219d08 b 0x219b38 <_Z23Audio_CreateBufferSoundiiiiii+0x298> */
/* @0x219d0c ldr r2, [sp, #0x64] */
/* @0x219d10 cmp r2, #1 */
/* @0x219d14 movne r9, #4352 */
/* @0x219d18 bne 0x219adc <_Z23Audio_CreateBufferSoundiiiiii+0x23c> */
/* @0x219d1c movw r1, #0x1102 */
/* @0x219d20 b 0x219cc0 <_Z23Audio_CreateBufferSoundiiiiii+0x420> */
/* @0x219d24 mulseq sp, r4, r3 */
/* @0x219d28 subseq r11, r3, r8, ror r9 */
/* @0x219d2c subseq r11, r3, r8, lsr #18 */
/* @0x219d30 ldrsheq r11, [r3], #-128 */
/* @0x219d34 subseq r11, r3, r8, ror #17 */
/* @0x219d38 subseq r11, r3, r8, lsl r8 */
/* @0x219d3c ldrsheq r11, [r3], #-124 */
/* @0x219d40 andseq r10, r3, r4, asr #9 */
/* @0x219d44 andseq r10, r3, r0, lsr #9 */
/* @0x219d48 subseq r11, r3, r12, lsl #14 */
/* @0x219d4c andseq r10, r3, r8, ror #4 */
/* @0x219d50 andseq r3, r3, r8, lsr #14 */
/* @0x219d54 .word 0xffffbac4 */
/* @0x219d58 andseq r10, r3, r0, lsr #6 */
/* @0x219d5c andseq r10, r3, r8, lsr #5 */
/* @0x219d60 andseq r10, r3, r8, asr #4 */
/* @0x219d64 andseq r10, r3, r8, ror #3 */
/* @0x219d68 ldrsheq r11, [r3], #-88 */
/* @0x219d6c andseq r10, r3, r0, asr #5 */

/* ── FUNC 0x219d70 · Audio_FreeBufferSound(int) · size=248 · insn=62 */
/* @0x219d70 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x219d74 sub r7, r0, #99328 */
/* @0x219d78 subs r7, r7, #672 */
/* @0x219d7c mov r5, r0 */
/* @0x219d80 bmi 0x219e50 <_Z21Audio_FreeBufferSoundi+0xe0> */
/* @0x219d84 ldr r3, [pc, #0xcc] */
/* @0x219d88 add r3, pc, r3 */
/* @0x219d8c ldr r2, [r3, #0x28] */
/* @0x219d90 cmp r7, r2 */
/* @0x219d94 bge 0x219e50 <_Z21Audio_FreeBufferSoundi+0xe0> */
/* @0x219d98 ldr r2, [r3, #0x2c] */
/* @0x219d9c ldr r8, [r2, r7, lsl #2] */
/* @0x219da0 cmp r8, #0 */
/* @0x219da4 beq 0x219e50 <_Z21Audio_FreeBufferSoundi+0xe0> */
/* @0x219da8 ldr r6, [r3, #0x38] */
/* @0x219dac cmp r6, #0 */
/* @0x219db0 ble 0x219e0c <_Z21Audio_FreeBufferSoundi+0x9c> */
/* @0x219db4 ldr r10, [pc, #0xa0] */
/* @0x219db8 mov r3, r6 */
/* @0x219dbc ldr r9, [pc, #0x9c] */
/* @0x219dc0 mov r4, #0 */
/* @0x219dc4 add r10, pc, r10 */
/* @0x219dc8 add r9, pc, r9 */
/* @0x219dcc b 0x219ddc <_Z21Audio_FreeBufferSoundi+0x6c> */
/* @0x219dd0 cmp r4, r6 */
/* @0x219dd4 beq 0x219e0c <_Z21Audio_FreeBufferSoundi+0x9c> */
/* @0x219dd8 ldr r3, [r9, #0x38] */
/* @0x219ddc cmp r3, r4 */
/* @0x219de0 mov r0, #0 */
/* @0x219de4 ldrgt r3, [r10, #0x3c] */
/* @0x219de8 ldrgt r0, [r3, r4, lsl #2] */
/* @0x219dec add r4, r4, #1 */
/* @0x219df0 ldr r2, [r0, #0x18] */
/* @0x219df4 cmp r2, r5 */
/* @0x219df8 bne 0x219dd0 <_Z21Audio_FreeBufferSoundi+0x60> */
/* @0x219dfc mov r1, #1 */
/* @0x219e00 bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb> */
/* @0x219e04 cmp r4, r6 */
/* @0x219e08 bne 0x219dd8 <_Z21Audio_FreeBufferSoundi+0x68> */
/* @0x219e0c ldr r0, [r8, #0x10] */
/* @0x219e10 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x219e14 cmp r0, #0 */
/* @0x219e18 ldrne r3, [r0, #0x28] */
/* @0x219e1c subne r3, r3, #1 */
/* @0x219e20 strne r3, [r0, #0x28] */
/* @0x219e24 mov r0, r8 */
/* @0x219e28 bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x219e2c mov r0, r8 */
/* @0x219e30 bl 0x27d1d0 <_ZdlPv> */
/* @0x219e34 ldr r3, [pc, #0x28] */
/* @0x219e38 mov r2, #0 */
/* @0x219e3c mov r0, #1 */
/* @0x219e40 add r3, pc, r3 */
/* @0x219e44 ldr r3, [r3, #0x2c] */
/* @0x219e48 str r2, [r3, r7, lsl #2] */
/* @0x219e4c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x219e50 mov r0, #0 */
/* @0x219e54 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x219e58 subseq r11, r3, r12, lsl #10 */
/* @0x219e5c ldrsbeq r11, [r3], #-64 */
/* @0x219e60 subseq r11, r3, r12, asr #9 */
/* @0x219e64 subseq r11, r3, r4, asr r4 */

/* ── FUNC 0x219e68 · Audio_Unqueue_Processed_Buffers(CNoise*, int, bool) · size=480 · insn=118 */
/* @0x219e68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x219e6c vpush {d8, d9} */
/* @0x219e70 subs r8, r0, #0 */
/* @0x219e74 sub sp, sp, #84 */
/* @0x219e78 vmov s18, r1 */
/* @0x219e7c str r2, [sp, #0x34] */
/* @0x219e80 beq 0x21a004 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x19c> */
/* @0x219e84 ldr r6, [pc, #0x1a4] */
/* @0x219e88 add r2, sp, #80 */
/* @0x219e8c ldr r4, [r8, #0x10] */
/* @0x219e90 mvn r5, #0 */
/* @0x219e94 ldr r6, [pc, r6] */
/* @0x219e98 str r5, [r2, #-0xc]! */
/* @0x219e9c movw r1, #0x1016 */
/* @0x219ea0 ldr r3, [r6] */
/* @0x219ea4 lsl r12, r4, #2 */
/* @0x219ea8 str r12, [sp, #0x2c] */
/* @0x219eac ldr r0, [r3, r4, lsl #2] */
/* @0x219eb0 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x219eb4 ldr r3, [r6] */
/* @0x219eb8 add r2, sp, #80 */
/* @0x219ebc movw r1, #0x1015 */
/* @0x219ec0 str r5, [r2, #-0x8]! */
/* @0x219ec4 ldr r0, [r3, r4, lsl #2] */
/* @0x219ec8 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x219ecc ldr r3, [sp, #0x44] */
/* @0x219ed0 cmp r3, #0 */
/* @0x219ed4 ble 0x21a004 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x19c> */
/* @0x219ed8 ldr r11, [pc, #0x154] */
/* @0x219edc movw r9, #0x869f */
/* @0x219ee0 ldr r4, [pc, #0x150] */
/* @0x219ee4 movt r9, #0x1 */
/* @0x219ee8 ldr r12, [pc, #0x14c] */
/* @0x219eec add r11, pc, r11 */
/* @0x219ef0 add r4, pc, r4 */
/* @0x219ef4 mov r5, #0 */
/* @0x219ef8 add r12, pc, r12 */
/* @0x219efc str r12, [sp, #0x38] */
/* @0x219f00 add r12, sp, #76 */
/* @0x219f04 str r12, [sp, #0x30] */
/* @0x219f08 ldr r12, [pc, #0x130] */
/* @0x219f0c vldr d8, [pc, #276] */
/* @0x219f10 add r12, pc, r12 */
/* @0x219f14 str r12, [sp, #0x3c] */
/* @0x219f18 ldr r3, [r6] */
/* @0x219f1c mov r7, #0 */
/* @0x219f20 ldr r12, [sp, #0x2c] */
/* @0x219f24 mov r1, #1 */
/* @0x219f28 str r7, [sp, #0x4c] */
/* @0x219f2c add r2, sp, #76 */
/* @0x219f30 ldr r0, [r3, r12] */
/* @0x219f34 bl 0xb6b08 <alSourceUnqueueBuffers@plt> */
/* @0x219f38 ldr r3, [r11, #0x28] */
/* @0x219f3c cmp r3, r7 */
/* @0x219f40 ble 0x219f7c <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x114> */
/* @0x219f44 add r10, r7, #99328 */
/* @0x219f48 add r7, r7, #1 */
/* @0x219f4c add r10, r10, #672 */
/* @0x219f50 mov r0, r10 */
/* @0x219f54 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x219f58 cmp r0, #0 */
/* @0x219f5c beq 0x219f70 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x108> */
/* @0x219f60 ldr r2, [r0, #0x18] */
/* @0x219f64 ldr r3, [sp, #0x4c] */
/* @0x219f68 cmp r2, r3 */
/* @0x219f6c beq 0x21a010 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x1a8> */
/* @0x219f70 ldr r3, [r4, #0x28] */
/* @0x219f74 cmp r3, r7 */
/* @0x219f78 bgt 0x219f44 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0xdc> */
/* @0x219f7c mvn r7, #0 */
/* @0x219f80 ldr r3, [r8, #0x18] */
/* @0x219f84 sub r3, r3, #199680 */
/* @0x219f88 sub r3, r3, #320 */
/* @0x219f8c cmp r3, r9 */
/* @0x219f90 bhi 0x219ff4 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x18c> */
/* @0x219f94 vmov.f64 d7, #1.000000e+00 */
/* @0x219f98 ldr r12, [sp, #0x34] */
/* @0x219f9c vmov s11, r7 */
/* @0x219fa0 ldr r2, [pc, #0x9c] */
/* @0x219fa4 cmp r12, #0 */
/* @0x219fa8 ldr r12, [sp, #0x3c] */
/* @0x219fac mov r3, #0 */
/* @0x219fb0 add r2, pc, r2 */
/* @0x219fb4 ldr r1, [sp, #0x38] */
/* @0x219fb8 mov r0, #3 */
/* @0x219fbc str r2, [sp, #0x14] */
/* @0x219fc0 str r3, [sp] */
/* @0x219fc4 str r3, [sp, #0x10] */
/* @0x219fc8 str r3, [sp, #0x20] */
/* @0x219fcc str r12, [sp, #0x4] */
/* @0x219fd0 vmoveq.f64 d7, d8 */
/* @0x219fd4 vstr d7, [sp, #24] */
/* @0x219fd8 vcvt.f64.s32 d6, s11 */
/* @0x219fdc vcvt.f64.s32 d7, s18 */
/* @0x219fe0 vstr d6, [sp, #8] */
/* @0x219fe4 vmov r2, r3, d7 */
/* @0x219fe8 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x219fec mov r1, #74 */
/* @0x219ff0 bl 0x18da04 <_Z24CreateAsynEventWithDSMapii> */
/* @0x219ff4 ldr r3, [sp, #0x44] */
/* @0x219ff8 add r5, r5, #1 */
/* @0x219ffc cmp r3, r5 */
/* @0x21a000 bgt 0x219f18 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0xb0> */
/* @0x21a004 add sp, sp, #84 */
/* @0x21a008 vpop {d8, d9} */
/* @0x21a00c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21a010 mov r2, r0 */
/* @0x21a014 mov r0, r10 */
/* @0x21a018 ldr r7, [r2, #0x10] */
/* @0x21a01c bl 0x219d70 <_Z21Audio_FreeBufferSoundi> */
/* @0x21a020 b 0x219f80 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x118> */
/* @0x21a024 nop */
/* @0x21a030 andseq r7, sp, r8, lsr r5 */
/* @0x21a034 subseq r11, r3, r8, lsr #7 */
/* @0x21a038 subseq r11, r3, r4, lsr #7 */
/* @0x21a03c andseq r10, r3, r0, asr #1 */
/* @0x21a040 ldrheq r10, [r3], -r4 */
/* @0x21a044 andseq r10, r3, r0, lsr #32 */

/* ── FUNC 0x21a048 · Audio_SetNoiseInactive(CNoise*) · size=104 · insn=26 */
/* @0x21a048 push {r3, r4, r5, lr} */
/* @0x21a04c mov r4, r0 */
/* @0x21a050 ldr r0, [r0, #0x38] */
/* @0x21a054 mov r5, #0 */
/* @0x21a058 strb r5, [r4, #0x5] */
/* @0x21a05c cmp r0, r5 */
/* @0x21a060 str r5, [r4, #0x8] */
/* @0x21a064 strb r5, [r4, #0xd] */
/* @0x21a068 beq 0x21a078 <_Z22Audio_SetNoiseInactiveP6CNoise+0x30> */
/* @0x21a06c mov r1, r4 */
/* @0x21a070 bl 0x2158dc <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise> */
/* @0x21a074 str r5, [r4, #0x38] */
/* @0x21a078 mov r0, r4 */
/* @0x21a07c ldr r1, [r4, #0x18] */
/* @0x21a080 mov r2, #1 */
/* @0x21a084 bl 0x219e68 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib> */
/* @0x21a088 ldr r3, [pc, #0x1c] */
/* @0x21a08c ldr r0, [r4, #0x10] */
/* @0x21a090 movw r1, #0x1009 */
/* @0x21a094 ldr r3, [pc, r3] */
/* @0x21a098 mov r2, #0 */
/* @0x21a09c ldr r3, [r3] */
/* @0x21a0a0 ldr r0, [r3, r0, lsl #2] */
/* @0x21a0a4 pop {r3, r4, r5, lr} */
/* @0x21a0a8 b 0xb6a6c <alSourcei@plt> */
/* @0x21a0ac andseq r7, sp, r8, lsr r3 */

/* ── FUNC 0x21a0b0 · Audio_StopSoundNoise(CNoise*, bool) · size=352 · insn=88 */
/* @0x21a0b0 push {r3, r4, r5, lr} */
/* @0x21a0b4 mov r4, r0 */
/* @0x21a0b8 ldr r5, [pc, #0x138] */
/* @0x21a0bc ldr r3, [pc, #0x138] */
/* @0x21a0c0 add r5, pc, r5 */
/* @0x21a0c4 ldr r3, [r5, r3] */
/* @0x21a0c8 ldrb r3, [r3] */
/* @0x21a0cc cmp r3, #0 */
/* @0x21a0d0 popne {r3, r4, r5, pc} */
/* @0x21a0d4 cmp r0, #0 */
/* @0x21a0d8 popeq {r3, r4, r5, pc} */
/* @0x21a0dc ldrb r3, [r0, #0x5] */
/* @0x21a0e0 cmp r3, #0 */
/* @0x21a0e4 beq 0x21a138 <_Z20Audio_StopSoundNoiseP6CNoiseb+0x88> */
/* @0x21a0e8 cmp r1, #0 */
/* @0x21a0ec bne 0x21a15c <_Z20Audio_StopSoundNoiseP6CNoiseb+0xac> */
/* @0x21a0f0 ldr r3, [r4, #0x8] */
/* @0x21a0f4 cmp r3, #0 */
/* @0x21a0f8 popne {r3, r4, r5, pc} */
/* @0x21a0fc ldr r3, [pc, #0xfc] */
/* @0x21a100 mov r1, #1 */
/* @0x21a104 mov r2, #0 */
/* @0x21a108 str r1, [r4, #0x8] */
/* @0x21a10c str r2, [r4, #0x24] */
/* @0x21a110 movw r1, #0x6b28 */
/* @0x21a114 movt r1, #0xce6e */
/* @0x21a118 str r1, [r4, #0x1c] */
/* @0x21a11c ldr r3, [r5, r3] */
/* @0x21a120 movw r1, #0x100a */
/* @0x21a124 ldr r0, [r4, #0x10] */
/* @0x21a128 ldr r3, [r3] */
/* @0x21a12c ldr r0, [r3, r0, lsl #2] */
/* @0x21a130 pop {r3, r4, r5, lr} */
/* @0x21a134 b 0xb6a78 <alSourcef@plt> */
/* @0x21a138 ldr r2, [r0, #0x18] */
/* @0x21a13c movw r3, #0x869f */
/* @0x21a140 movt r3, #0x1 */
/* @0x21a144 sub r2, r2, #199680 */
/* @0x21a148 sub r2, r2, #320 */
/* @0x21a14c cmp r2, r3 */
/* @0x21a150 pophi {r3, r4, r5, pc} */
/* @0x21a154 cmp r1, #0 */
/* @0x21a158 beq 0x21a0f0 <_Z20Audio_StopSoundNoiseP6CNoiseb+0x40> */
/* @0x21a15c mov r3, #1 */
/* @0x21a160 ldr r0, [r4, #0x18] */
/* @0x21a164 strb r3, [r4, #0xd] */
/* @0x21a168 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21a16c cmp r0, #0 */
/* @0x21a170 beq 0x21a1a0 <_Z20Audio_StopSoundNoiseP6CNoiseb+0xf0> */
/* @0x21a174 ldrb r3, [r0, #0x24] */
/* @0x21a178 cmp r3, #0 */
/* @0x21a17c beq 0x21a194 <_Z20Audio_StopSoundNoiseP6CNoiseb+0xe4> */
/* @0x21a180 ldr r0, [pc, #0x7c] */
/* @0x21a184 ldr r1, [r4, #0x10] */
/* @0x21a188 add r0, pc, r0 */
/* @0x21a18c pop {r3, r4, r5, lr} */
/* @0x21a190 b 0x226404 <_ZN9COggAudio10Stop_SoundEi> */
/* @0x21a194 ldrb r3, [r0, #0x25] */
/* @0x21a198 cmp r3, #0 */
/* @0x21a19c bne 0x21a180 <_Z20Audio_StopSoundNoiseP6CNoiseb+0xd0> */
/* @0x21a1a0 ldr r3, [pc, #0x58] */
/* @0x21a1a4 ldr r2, [r4, #0x10] */
/* @0x21a1a8 ldr r3, [r5, r3] */
/* @0x21a1ac ldr r3, [r3] */
/* @0x21a1b0 ldr r0, [r3, r2, lsl #2] */
/* @0x21a1b4 bl 0xb6b14 <alSourceStop@plt> */
/* @0x21a1b8 bl 0xb6a54 <alGetError@plt> */
/* @0x21a1bc subs r3, r0, #0 */
/* @0x21a1c0 bne 0x21a1d0 <_Z20Audio_StopSoundNoiseP6CNoiseb+0x120> */
/* @0x21a1c4 mov r0, r4 */
/* @0x21a1c8 pop {r3, r4, r5, lr} */
/* @0x21a1cc b 0x21a048 <_Z22Audio_SetNoiseInactiveP6CNoise> */
/* @0x21a1d0 ldr r0, [pc, #0x30] */
/* @0x21a1d4 ldr r1, [pc, #0x30] */
/* @0x21a1d8 ldr r2, [r4, #0x18] */
/* @0x21a1dc ldr r0, [r5, r0] */
/* @0x21a1e0 add r1, pc, r1 */
/* @0x21a1e4 ldr r0, [r0] */
/* @0x21a1e8 ldr r12, [r0] */
/* @0x21a1ec ldr r12, [r12, #0xc] */
/* @0x21a1f0 blx r12 */
/* @0x21a1f4 b 0x21a1c4 <_Z20Audio_StopSoundNoiseP6CNoiseb+0x114> */
/* @0x21a1f8 mulseq sp, r0, r11 */
/* @0x21a1fc .word 0xffffd3fc */
/* @0x21a200 .word 0xfffff77c */
/* @0x21a204 subseq r11, r3, r12, lsl #2 */
/* @0x21a208 .word 0xffffbac4 */
/* @0x21a20c andseq r9, r3, r0, lsl #28 */

/* ── FUNC 0x21a210 · Audio_StopSound(int) · size=232 · insn=58 */
/* @0x21a210 ldr r3, [pc, #0xc8] */
/* @0x21a214 push {r4, r5, r6, r7, r8, lr} */
/* @0x21a218 ldr r3, [pc, r3] */
/* @0x21a21c mov r5, r0 */
/* @0x21a220 ldrb r4, [r3] */
/* @0x21a224 cmp r4, #0 */
/* @0x21a228 popne {r4, r5, r6, r7, r8, pc} */
/* @0x21a22c ldr r3, [pc, #0xb0] */
/* @0x21a230 ldr r3, [pc, r3] */
/* @0x21a234 ldrb r3, [r3] */
/* @0x21a238 cmp r3, #0 */
/* @0x21a23c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x21a240 ldr r3, [pc, #0xa0] */
/* @0x21a244 ldr r3, [pc, r3] */
/* @0x21a248 ldr r3, [r3] */
/* @0x21a24c cmp r3, r0 */
/* @0x21a250 ble 0x21a2c8 <_Z15Audio_StopSoundi+0xb8> */
/* @0x21a254 ldr r3, [pc, #0x90] */
/* @0x21a258 add r3, pc, r3 */
/* @0x21a25c ldr r6, [r3, #0x38] */
/* @0x21a260 cmp r6, #0 */
/* @0x21a264 pople {r4, r5, r6, r7, r8, pc} */
/* @0x21a268 ldr r8, [pc, #0x80] */
/* @0x21a26c mov r3, r6 */
/* @0x21a270 ldr r7, [pc, #0x7c] */
/* @0x21a274 add r8, pc, r8 */
/* @0x21a278 add r7, pc, r7 */
/* @0x21a27c b 0x21a28c <_Z15Audio_StopSoundi+0x7c> */
/* @0x21a280 cmp r4, r6 */
/* @0x21a284 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x21a288 ldr r3, [r7, #0x38] */
/* @0x21a28c cmp r3, r4 */
/* @0x21a290 mov r0, #0 */
/* @0x21a294 ldrgt r3, [r8, #0x3c] */
/* @0x21a298 ldrgt r0, [r3, r4, lsl #2] */
/* @0x21a29c add r4, r4, #1 */
/* @0x21a2a0 ldr r2, [r0, #0x18] */
/* @0x21a2a4 cmp r2, r5 */
/* @0x21a2a8 bne 0x21a280 <_Z15Audio_StopSoundi+0x70> */
/* @0x21a2ac ldrb r1, [r0, #0xd] */
/* @0x21a2b0 cmp r1, #0 */
/* @0x21a2b4 bne 0x21a280 <_Z15Audio_StopSoundi+0x70> */
/* @0x21a2b8 bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb> */
/* @0x21a2bc cmp r4, r6 */
/* @0x21a2c0 bne 0x21a288 <_Z15Audio_StopSoundi+0x78> */
/* @0x21a2c4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x21a2c8 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x21a2cc cmp r0, #0 */
/* @0x21a2d0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x21a2d4 mov r1, r4 */
/* @0x21a2d8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x21a2dc b 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb> */
/* @0x21a2e0 andseq r4, sp, r4, lsr lr */
/* @0x21a2e4 andseq r4, sp, r0, lsl #22 */
/* @0x21a2e8 andseq r7, sp, r0, lsr #3 */
/* @0x21a2ec subseq r11, r3, r12, lsr r0 */
/* @0x21a2f0 subseq r11, r3, r0, lsr #32 */
/* @0x21a2f4 subseq r11, r3, r12, lsl r0 */

/* ── FUNC 0x21a2f8 · Audio_ReleaseEmitter(int) · size=196 · insn=49 */
/* @0x21a2f8 ldr r3, [pc, #0xb4] */
/* @0x21a2fc push {r4, r5, r6, lr} */
/* @0x21a300 ldr r3, [pc, r3] */
/* @0x21a304 ldrb r3, [r3] */
/* @0x21a308 cmp r3, #0 */
/* @0x21a30c popeq {r4, r5, r6, pc} */
/* @0x21a310 ldr r3, [pc, #0xa0] */
/* @0x21a314 add r3, pc, r3 */
/* @0x21a318 ldr r4, [r3, #0x40] */
/* @0x21a31c cmp r4, r0 */
/* @0x21a320 movgt r4, #0 */
/* @0x21a324 movle r4, #1 */
/* @0x21a328 orrs r4, r4, r0, lsr #31 */
/* @0x21a32c popne {r4, r5, r6, pc} */
/* @0x21a330 ldr r3, [r3, #0x44] */
/* @0x21a334 ldr r5, [r3, r0, lsl #2] */
/* @0x21a338 cmp r5, #0 */
/* @0x21a33c popeq {r4, r5, r6, pc} */
/* @0x21a340 ldr r6, [r5, #0x34] */
/* @0x21a344 cmp r6, #0 */
/* @0x21a348 movgt r3, r6 */
/* @0x21a34c bgt 0x21a358 <_Z20Audio_ReleaseEmitteri+0x60> */
/* @0x21a350 b 0x21a3a8 <_Z20Audio_ReleaseEmitteri+0xb0> */
/* @0x21a354 ldr r3, [r5, #0x34] */
/* @0x21a358 cmp r3, r4 */
/* @0x21a35c ble 0x21a39c <_Z20Audio_ReleaseEmitteri+0xa4> */
/* @0x21a360 ldr r3, [r5, #0x38] */
/* @0x21a364 ldr r3, [r3, r4, lsl #2] */
/* @0x21a368 cmp r3, #0 */
/* @0x21a36c beq 0x21a39c <_Z20Audio_ReleaseEmitteri+0xa4> */
/* @0x21a370 ldrb r2, [r3, #0x5] */
/* @0x21a374 cmp r2, #0 */
/* @0x21a378 beq 0x21a39c <_Z20Audio_ReleaseEmitteri+0xa4> */
/* @0x21a37c ldr r2, [r3, #0x8] */
/* @0x21a380 cmp r2, #0 */
/* @0x21a384 bne 0x21a39c <_Z20Audio_ReleaseEmitteri+0xa4> */
/* @0x21a388 ldr r2, [r3, #0x10] */
/* @0x21a38c cmp r2, #0 */
/* @0x21a390 blt 0x21a39c <_Z20Audio_ReleaseEmitteri+0xa4> */
/* @0x21a394 ldr r0, [r3, #0x14] */
/* @0x21a398 bl 0x21a210 <_Z15Audio_StopSoundi> */
/* @0x21a39c add r4, r4, #1 */
/* @0x21a3a0 cmp r4, r6 */
/* @0x21a3a4 bne 0x21a354 <_Z20Audio_ReleaseEmitteri+0x5c> */
/* @0x21a3a8 mov r3, #0 */
/* @0x21a3ac strb r3, [r5, #0x18] */
/* @0x21a3b0 pop {r4, r5, r6, pc} */
/* @0x21a3b4 andseq r4, sp, r0, lsr r10 */
/* @0x21a3b8 subseq r10, r3, r0, lsl #31 */

/* ── FUNC 0x21a3bc · Audio_StopAll(bool) · size=152 · insn=38 */
/* @0x21a3bc ldr r3, [pc, #0x7c] */
/* @0x21a3c0 push {r4, r5, r6, r7, r8, lr} */
/* @0x21a3c4 ldr r3, [pc, r3] */
/* @0x21a3c8 mov r6, r0 */
/* @0x21a3cc ldrb r4, [r3] */
/* @0x21a3d0 cmp r4, #0 */
/* @0x21a3d4 popne {r4, r5, r6, r7, r8, pc} */
/* @0x21a3d8 ldr r3, [pc, #0x64] */
/* @0x21a3dc ldr r3, [pc, r3] */
/* @0x21a3e0 ldrb r3, [r3] */
/* @0x21a3e4 cmp r3, #0 */
/* @0x21a3e8 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x21a3ec ldr r3, [pc, #0x54] */
/* @0x21a3f0 add r3, pc, r3 */
/* @0x21a3f4 ldr r5, [r3, #0x38] */
/* @0x21a3f8 cmp r5, #0 */
/* @0x21a3fc pople {r4, r5, r6, r7, r8, pc} */
/* @0x21a400 ldr r8, [pc, #0x44] */
/* @0x21a404 mov r3, r5 */
/* @0x21a408 ldr r7, [pc, #0x40] */
/* @0x21a40c add r8, pc, r8 */
/* @0x21a410 add r7, pc, r7 */
/* @0x21a414 cmp r3, r4 */
/* @0x21a418 mov r0, #0 */
/* @0x21a41c mov r1, r6 */
/* @0x21a420 ldrgt r3, [r8, #0x3c] */
/* @0x21a424 ldrgt r0, [r3, r4, lsl #2] */
/* @0x21a428 add r4, r4, #1 */
/* @0x21a42c bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb> */
/* @0x21a430 cmp r4, r5 */
/* @0x21a434 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x21a438 ldr r3, [r7, #0x38] */
/* @0x21a43c b 0x21a414 <_Z13Audio_StopAllb+0x58> */
/* @0x21a440 andseq r4, sp, r8, lsl #25 */
/* @0x21a444 andseq r4, sp, r4, asr r9 */
/* @0x21a448 subseq r10, r3, r4, lsr #29 */
/* @0x21a44c subseq r10, r3, r8, lsl #29 */
/* @0x21a450 subseq r10, r3, r4, lsl #29 */

/* ── FUNC 0x21a454 · Audio_SetNumChannels(int) · size=528 · insn=132 */
/* @0x21a454 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21a458 sub sp, sp, #12 */
/* @0x21a45c ldr r4, [pc, #0x1d0] */
/* @0x21a460 ldr r3, [pc, #0x1d0] */
/* @0x21a464 add r4, pc, r4 */
/* @0x21a468 ldr r3, [r4, r3] */
/* @0x21a46c ldrb r3, [r3] */
/* @0x21a470 cmp r3, #0 */
/* @0x21a474 beq 0x21a61c <_Z20Audio_SetNumChannelsi+0x1c8> */
/* @0x21a478 ldr r3, [pc, #0x1bc] */
/* @0x21a47c cmp r0, #1 */
/* @0x21a480 andgt r7, r0, #3 */
/* @0x21a484 addgt r7, r0, r7 */
/* @0x21a488 movle r7, #4 */
/* @0x21a48c ldr r5, [r4, r3] */
/* @0x21a490 ldr r3, [r5] */
/* @0x21a494 cmp r7, r3 */
/* @0x21a498 beq 0x21a61c <_Z20Audio_SetNumChannelsi+0x1c8> */
/* @0x21a49c ldr r3, [pc, #0x19c] */
/* @0x21a4a0 mov r2, r7 */
/* @0x21a4a4 ldr r1, [pc, #0x198] */
/* @0x21a4a8 ldr r3, [r4, r3] */
/* @0x21a4ac add r1, pc, r1 */
/* @0x21a4b0 ldr r0, [r3] */
/* @0x21a4b4 ldr r3, [r0] */
/* @0x21a4b8 ldr r3, [r3, #0xc] */
/* @0x21a4bc blx r3 */
/* @0x21a4c0 mov r0, #1 */
/* @0x21a4c4 bl 0x21a3bc <_Z13Audio_StopAllb> */
/* @0x21a4c8 ldr r0, [pc, #0x178] */
/* @0x21a4cc add r0, pc, r0 */
/* @0x21a4d0 bl 0x225fa4 <_ZN9COggAudio4QuitEv> */
/* @0x21a4d4 ldr r3, [pc, #0x170] */
/* @0x21a4d8 ldr r6, [r4, r3] */
/* @0x21a4dc ldr r1, [r6] */
/* @0x21a4e0 cmp r1, #0 */
/* @0x21a4e4 beq 0x21a530 <_Z20Audio_SetNumChannelsi+0xdc> */
/* @0x21a4e8 ldr r0, [r5] */
/* @0x21a4ec cmp r0, #0 */
/* @0x21a4f0 ble 0x21a51c <_Z20Audio_SetNumChannelsi+0xc8> */
/* @0x21a4f4 mov r4, #0 */
/* @0x21a4f8 ldr r0, [r1, r4, lsl #2] */
/* @0x21a4fc mov r2, #0 */
/* @0x21a500 movw r1, #0x1009 */
/* @0x21a504 add r4, r4, #1 */
/* @0x21a508 bl 0xb6a6c <alSourcei@plt> */
/* @0x21a50c ldr r0, [r5] */
/* @0x21a510 ldr r1, [r6] */
/* @0x21a514 cmp r0, r4 */
/* @0x21a518 bgt 0x21a4f8 <_Z20Audio_SetNumChannelsi+0xa4> */
/* @0x21a51c bl 0xb6b20 <alDeleteSources@plt> */
/* @0x21a520 ldr r0, [r6] */
/* @0x21a524 bl 0x27d1d0 <_ZdlPv> */
/* @0x21a528 mov r3, #0 */
/* @0x21a52c str r3, [r6] */
/* @0x21a530 ldr r9, [pc, #0x118] */
/* @0x21a534 add r9, pc, r9 */
/* @0x21a538 ldr r3, [r9, #0x38] */
/* @0x21a53c cmp r3, #0 */
/* @0x21a540 beq 0x21a60c <_Z20Audio_SetNumChannelsi+0x1b8> */
/* @0x21a544 ldr r5, [r9, #0x3c] */
/* @0x21a548 cmp r5, #0 */
/* @0x21a54c beq 0x21a624 <_Z20Audio_SetNumChannelsi+0x1d0> */
/* @0x21a550 cmp r3, #0 */
/* @0x21a554 ble 0x21a5e4 <_Z20Audio_SetNumChannelsi+0x190> */
/* @0x21a558 ldr r11, [pc, #0xf4] */
/* @0x21a55c mov r4, #0 */
/* @0x21a560 ldr r2, [pc, #0xf0] */
/* @0x21a564 mov r10, r4 */
/* @0x21a568 add r11, pc, r11 */
/* @0x21a56c add r2, pc, r2 */
/* @0x21a570 ldr r0, [r5] */
/* @0x21a574 movw r3, #0xfeee */
/* @0x21a578 movt r3, #0xfeee */
/* @0x21a57c movw r1, #0xfeee */
/* @0x21a580 cmp r0, r3 */
/* @0x21a584 movt r1, #0xfeee */
/* @0x21a588 lsl r8, r4, #2 */
/* @0x21a58c beq 0x21a5d4 <_Z20Audio_SetNumChannelsi+0x180> */
/* @0x21a590 ldr r6, [r5, r4, lsl #2] */
/* @0x21a594 add r3, r5, r8 */
/* @0x21a598 cmp r6, #0 */
/* @0x21a59c mov r0, r6 */
/* @0x21a5a0 beq 0x21a5d4 <_Z20Audio_SetNumChannelsi+0x180> */
/* @0x21a5a4 ldr r12, [r6] */
/* @0x21a5a8 cmp r12, r1 */
/* @0x21a5ac beq 0x21a5cc <_Z20Audio_SetNumChannelsi+0x178> */
/* @0x21a5b0 str r2, [sp, #0x4] */
/* @0x21a5b4 bl 0x21db28 <_ZN6CNoiseD2Ev> */
/* @0x21a5b8 mov r0, r6 */
/* @0x21a5bc bl 0x27d1d0 <_ZdlPv> */
/* @0x21a5c0 ldr r2, [sp, #0x4] */
/* @0x21a5c4 ldr r3, [r2, #0x3c] */
/* @0x21a5c8 add r3, r3, r8 */
/* @0x21a5cc str r10, [r3] */
/* @0x21a5d0 ldr r5, [r11, #0x3c] */
/* @0x21a5d4 ldr r3, [r9, #0x38] */
/* @0x21a5d8 add r4, r4, #1 */
/* @0x21a5dc cmp r4, r3 */
/* @0x21a5e0 blt 0x21a570 <_Z20Audio_SetNumChannelsi+0x11c> */
/* @0x21a5e4 mov r0, r5 */
/* @0x21a5e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21a5ec ldr r3, [pc, #0x68] */
/* @0x21a5f0 mov r2, #0 */
/* @0x21a5f4 add r3, pc, r3 */
/* @0x21a5f8 str r2, [r3, #0x3c] */
/* @0x21a5fc ldr r3, [pc, #0x5c] */
/* @0x21a600 mov r2, #0 */
/* @0x21a604 add r3, pc, r3 */
/* @0x21a608 str r2, [r3, #0x38] */
/* @0x21a60c mov r0, r7 */
/* @0x21a610 add sp, sp, #12 */
/* @0x21a614 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21a618 b 0x21625c <_Z19Audio_CreateSourcesi> */
/* @0x21a61c add sp, sp, #12 */
/* @0x21a620 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21a624 mov r0, r5 */
/* @0x21a628 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21a62c str r5, [r9, #0x3c] */
/* @0x21a630 b 0x21a5fc <_Z20Audio_SetNumChannelsi+0x1a8> */
/* @0x21a634 andseq r7, sp, r12, ror #15 */
/* @0x21a638 .word 0xffffd0e0 */
/* @0x21a63c .word 0xfffff780 */
/* @0x21a640 .word 0xffffbac4 */
/* @0x21a644 andseq r9, r3, r12, asr r11 */
/* @0x21a648 subseq r10, r3, r8, asr #27 */
/* @0x21a64c .word 0xfffff77c */
/* @0x21a650 subseq r10, r3, r0, ror #26 */
/* @0x21a654 subseq r10, r3, r12, lsr #26 */
/* @0x21a658 subseq r10, r3, r8, lsr #26 */
/* @0x21a65c subseq r10, r3, r0, lsr #25 */
/* @0x21a660 .word 0x0053ac90 */

/* ── FUNC 0x21a664 · Audio_Quit() · size=1704 · insn=426 */
/* @0x21a664 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21a668 sub sp, sp, #12 */
/* @0x21a66c ldr r5, [pc, #0x620] */
/* @0x21a670 ldr r3, [pc, #0x620] */
/* @0x21a674 add r5, pc, r5 */
/* @0x21a678 ldr r3, [r5, r3] */
/* @0x21a67c ldrb r3, [r3] */
/* @0x21a680 cmp r3, #0 */
/* @0x21a684 bne 0x21a690 <_Z10Audio_Quitv+0x2c> */
/* @0x21a688 add sp, sp, #12 */
/* @0x21a68c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21a690 ldr r7, [pc, #0x604] */
/* @0x21a694 mov r0, #1 */
/* @0x21a698 bl 0x21a3bc <_Z13Audio_StopAllb> */
/* @0x21a69c add r7, pc, r7 */
/* @0x21a6a0 mov r0, r7 */
/* @0x21a6a4 bl 0x225fa4 <_ZN9COggAudio4QuitEv> */
/* @0x21a6a8 ldr r3, [pc, #0x5f0] */
/* @0x21a6ac ldr r0, [r5, r3] */
/* @0x21a6b0 bl 0x21deb0 <_ZN14CAudioGroupMan8FinaliseEv> */
/* @0x21a6b4 ldr r6, [r7, #0x40] */
/* @0x21a6b8 cmp r6, #0 */
/* @0x21a6bc movgt r4, #0 */
/* @0x21a6c0 movgt r0, r7 */
/* @0x21a6c4 movgt lr, r4 */
/* @0x21a6c8 ble 0x21a70c <_Z10Audio_Quitv+0xa8> */
/* @0x21a6cc ldr r3, [r0, #0x44] */
/* @0x21a6d0 ldr r1, [r3, r4, lsl #2] */
/* @0x21a6d4 cmp r1, #0 */
/* @0x21a6d8 beq 0x21a700 <_Z10Audio_Quitv+0x9c> */
/* @0x21a6dc ldr r12, [r1, #0x34] */
/* @0x21a6e0 cmp r12, #0 */
/* @0x21a6e4 ble 0x21a700 <_Z10Audio_Quitv+0x9c> */
/* @0x21a6e8 mov r3, #0 */
/* @0x21a6ec ldr r2, [r1, #0x38] */
/* @0x21a6f0 str lr, [r2, r3, lsl #2] */
/* @0x21a6f4 add r3, r3, #1 */
/* @0x21a6f8 cmp r3, r12 */
/* @0x21a6fc bne 0x21a6ec <_Z10Audio_Quitv+0x88> */
/* @0x21a700 add r4, r4, #1 */
/* @0x21a704 cmp r4, r6 */
/* @0x21a708 bne 0x21a6cc <_Z10Audio_Quitv+0x68> */
/* @0x21a70c ldr r3, [pc, #0x590] */
/* @0x21a710 ldr r6, [r5, r3] */
/* @0x21a714 ldr r3, [r6] */
/* @0x21a718 cmp r3, #0 */
/* @0x21a71c beq 0x21a778 <_Z10Audio_Quitv+0x114> */
/* @0x21a720 ldr r2, [pc, #0x580] */
/* @0x21a724 ldr r7, [r5, r2] */
/* @0x21a728 ldr r0, [r7] */
/* @0x21a72c cmp r0, #0 */
/* @0x21a730 ble 0x21ac8c <_Z10Audio_Quitv+0x628> */
/* @0x21a734 mov r4, #0 */
/* @0x21a738 b 0x21a740 <_Z10Audio_Quitv+0xdc> */
/* @0x21a73c ldr r3, [r6] */
/* @0x21a740 ldr r0, [r3, r4, lsl #2] */
/* @0x21a744 movw r1, #0x1009 */
/* @0x21a748 mov r2, #0 */
/* @0x21a74c add r4, r4, #1 */
/* @0x21a750 bl 0xb6a6c <alSourcei@plt> */
/* @0x21a754 ldr r0, [r7] */
/* @0x21a758 cmp r0, r4 */
/* @0x21a75c bgt 0x21a73c <_Z10Audio_Quitv+0xd8> */
/* @0x21a760 ldr r1, [r6] */
/* @0x21a764 bl 0xb6b20 <alDeleteSources@plt> */
/* @0x21a768 ldr r0, [r6] */
/* @0x21a76c bl 0x27d1d0 <_ZdlPv> */
/* @0x21a770 mov r3, #0 */
/* @0x21a774 str r3, [r6] */
/* @0x21a778 ldr r9, [pc, #0x52c] */
/* @0x21a77c add r9, pc, r9 */
/* @0x21a780 ldr r3, [r9, #0x20] */
/* @0x21a784 cmp r3, #0 */
/* @0x21a788 beq 0x21a854 <_Z10Audio_Quitv+0x1f0> */
/* @0x21a78c ldr r6, [r9, #0x24] */
/* @0x21a790 cmp r6, #0 */
/* @0x21a794 beq 0x21ac4c <_Z10Audio_Quitv+0x5e8> */
/* @0x21a798 cmp r3, #0 */
/* @0x21a79c ble 0x21a82c <_Z10Audio_Quitv+0x1c8> */
/* @0x21a7a0 ldr r11, [pc, #0x508] */
/* @0x21a7a4 mov r4, #0 */
/* @0x21a7a8 ldr r1, [pc, #0x504] */
/* @0x21a7ac mov r10, r4 */
/* @0x21a7b0 add r11, pc, r11 */
/* @0x21a7b4 add r1, pc, r1 */
/* @0x21a7b8 ldr r0, [r6] */
/* @0x21a7bc movw r3, #0xfeee */
/* @0x21a7c0 movt r3, #0xfeee */
/* @0x21a7c4 movw r2, #0xfeee */
/* @0x21a7c8 cmp r0, r3 */
/* @0x21a7cc movt r2, #0xfeee */
/* @0x21a7d0 lsl r8, r4, #2 */
/* @0x21a7d4 beq 0x21a81c <_Z10Audio_Quitv+0x1b8> */
/* @0x21a7d8 ldr r7, [r6, r4, lsl #2] */
/* @0x21a7dc add r3, r6, r8 */
/* @0x21a7e0 cmp r7, #0 */
/* @0x21a7e4 mov r0, r7 */
/* @0x21a7e8 beq 0x21a81c <_Z10Audio_Quitv+0x1b8> */
/* @0x21a7ec ldr r12, [r7] */
/* @0x21a7f0 cmp r12, r2 */
/* @0x21a7f4 beq 0x21a814 <_Z10Audio_Quitv+0x1b0> */
/* @0x21a7f8 str r1, [sp, #0x4] */
/* @0x21a7fc bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x21a800 mov r0, r7 */
/* @0x21a804 bl 0x27d1d0 <_ZdlPv> */
/* @0x21a808 ldr r1, [sp, #0x4] */
/* @0x21a80c ldr r3, [r1, #0x24] */
/* @0x21a810 add r3, r3, r8 */
/* @0x21a814 str r10, [r3] */
/* @0x21a818 ldr r6, [r11, #0x24] */
/* @0x21a81c ldr r3, [r9, #0x20] */
/* @0x21a820 add r4, r4, #1 */
/* @0x21a824 cmp r4, r3 */
/* @0x21a828 blt 0x21a7b8 <_Z10Audio_Quitv+0x154> */
/* @0x21a82c mov r0, r6 */
/* @0x21a830 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21a834 ldr r3, [pc, #0x47c] */
/* @0x21a838 mov r2, #0 */
/* @0x21a83c add r3, pc, r3 */
/* @0x21a840 str r2, [r3, #0x24] */
/* @0x21a844 ldr r3, [pc, #0x470] */
/* @0x21a848 mov r2, #0 */
/* @0x21a84c add r3, pc, r3 */
/* @0x21a850 str r2, [r3, #0x20] */
/* @0x21a854 ldr r9, [pc, #0x464] */
/* @0x21a858 add r9, pc, r9 */
/* @0x21a85c ldr r3, [r9, #0x38] */
/* @0x21a860 cmp r3, #0 */
/* @0x21a864 beq 0x21a930 <_Z10Audio_Quitv+0x2cc> */
/* @0x21a868 ldr r6, [r9, #0x3c] */
/* @0x21a86c cmp r6, #0 */
/* @0x21a870 beq 0x21ac3c <_Z10Audio_Quitv+0x5d8> */
/* @0x21a874 cmp r3, #0 */
/* @0x21a878 ble 0x21a908 <_Z10Audio_Quitv+0x2a4> */
/* @0x21a87c ldr r11, [pc, #0x440] */
/* @0x21a880 mov r4, #0 */
/* @0x21a884 ldr r1, [pc, #0x43c] */
/* @0x21a888 mov r10, r4 */
/* @0x21a88c add r11, pc, r11 */
/* @0x21a890 add r1, pc, r1 */
/* @0x21a894 ldr r0, [r6] */
/* @0x21a898 movw r3, #0xfeee */
/* @0x21a89c movt r3, #0xfeee */
/* @0x21a8a0 movw r2, #0xfeee */
/* @0x21a8a4 cmp r0, r3 */
/* @0x21a8a8 movt r2, #0xfeee */
/* @0x21a8ac lsl r8, r4, #2 */
/* @0x21a8b0 beq 0x21a8f8 <_Z10Audio_Quitv+0x294> */
/* @0x21a8b4 ldr r7, [r6, r4, lsl #2] */
/* @0x21a8b8 add r3, r6, r8 */
/* @0x21a8bc cmp r7, #0 */
/* @0x21a8c0 mov r0, r7 */
/* @0x21a8c4 beq 0x21a8f8 <_Z10Audio_Quitv+0x294> */
/* @0x21a8c8 ldr r12, [r7] */
/* @0x21a8cc cmp r12, r2 */
/* @0x21a8d0 beq 0x21a8f0 <_Z10Audio_Quitv+0x28c> */
/* @0x21a8d4 str r1, [sp, #0x4] */
/* @0x21a8d8 bl 0x21db28 <_ZN6CNoiseD2Ev> */
/* @0x21a8dc mov r0, r7 */
/* @0x21a8e0 bl 0x27d1d0 <_ZdlPv> */
/* @0x21a8e4 ldr r1, [sp, #0x4] */
/* @0x21a8e8 ldr r3, [r1, #0x3c] */
/* @0x21a8ec add r3, r3, r8 */
/* @0x21a8f0 str r10, [r3] */
/* @0x21a8f4 ldr r6, [r11, #0x3c] */
/* @0x21a8f8 ldr r3, [r9, #0x38] */
/* @0x21a8fc add r4, r4, #1 */
/* @0x21a900 cmp r4, r3 */
/* @0x21a904 blt 0x21a894 <_Z10Audio_Quitv+0x230> */
/* @0x21a908 mov r0, r6 */
/* @0x21a90c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21a910 ldr r3, [pc, #0x3b4] */
/* @0x21a914 mov r2, #0 */
/* @0x21a918 add r3, pc, r3 */
/* @0x21a91c str r2, [r3, #0x3c] */
/* @0x21a920 ldr r3, [pc, #0x3a8] */
/* @0x21a924 mov r2, #0 */
/* @0x21a928 add r3, pc, r3 */
/* @0x21a92c str r2, [r3, #0x38] */
/* @0x21a930 ldr r6, [pc, #0x39c] */
/* @0x21a934 add r6, pc, r6 */
/* @0x21a938 ldr r7, [r6, #0x4c] */
/* @0x21a93c cmp r7, #0 */
/* @0x21a940 beq 0x21ac2c <_Z10Audio_Quitv+0x5c8> */
/* @0x21a944 ldr r3, [r6, #0x48] */
/* @0x21a948 cmp r3, #0 */
/* @0x21a94c ble 0x21a99c <_Z10Audio_Quitv+0x338> */
/* @0x21a950 ldr r9, [pc, #0x380] */
/* @0x21a954 mov r4, #0 */
/* @0x21a958 mov r8, r4 */
/* @0x21a95c add r9, pc, r9 */
/* @0x21a960 ldr r0, [r7, r4, lsl #2] */
/* @0x21a964 lsl r7, r4, #2 */
/* @0x21a968 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x21a96c cmp r0, #0 */
/* @0x21a970 beq 0x21a980 <_Z10Audio_Quitv+0x31c> */
/* @0x21a974 ldr r3, [r9, #0x4c] */
/* @0x21a978 ldr r0, [r3, r4, lsl #2] */
/* @0x21a97c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21a980 ldr r2, [r6, #0x48] */
/* @0x21a984 add r4, r4, #1 */
/* @0x21a988 ldr r3, [r6, #0x4c] */
/* @0x21a98c cmp r4, r2 */
/* @0x21a990 str r8, [r3, r7] */
/* @0x21a994 ldr r7, [r6, #0x4c] */
/* @0x21a998 blt 0x21a960 <_Z10Audio_Quitv+0x2fc> */
/* @0x21a99c mov r0, r7 */
/* @0x21a9a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21a9a4 ldr r3, [pc, #0x330] */
/* @0x21a9a8 mov r2, #0 */
/* @0x21a9ac add r3, pc, r3 */
/* @0x21a9b0 str r2, [r3, #0x4c] */
/* @0x21a9b4 ldr r9, [pc, #0x324] */
/* @0x21a9b8 mov r4, #0 */
/* @0x21a9bc add r9, pc, r9 */
/* @0x21a9c0 ldr r3, [r9, #0x28] */
/* @0x21a9c4 str r4, [r9, #0x48] */
/* @0x21a9c8 cmp r3, r4 */
/* @0x21a9cc beq 0x21aa94 <_Z10Audio_Quitv+0x430> */
/* @0x21a9d0 ldr r6, [r9, #0x2c] */
/* @0x21a9d4 cmp r6, r4 */
/* @0x21a9d8 beq 0x21ac7c <_Z10Audio_Quitv+0x618> */
/* @0x21a9dc cmp r3, r4 */
/* @0x21a9e0 ble 0x21aa6c <_Z10Audio_Quitv+0x408> */
/* @0x21a9e4 ldr r11, [pc, #0x2f8] */
/* @0x21a9e8 mov r10, r4 */
/* @0x21a9ec ldr r1, [pc, #0x2f4] */
/* @0x21a9f0 add r11, pc, r11 */
/* @0x21a9f4 add r1, pc, r1 */
/* @0x21a9f8 ldr r0, [r6] */
/* @0x21a9fc movw r3, #0xfeee */
/* @0x21aa00 movt r3, #0xfeee */
/* @0x21aa04 movw r2, #0xfeee */
/* @0x21aa08 cmp r0, r3 */
/* @0x21aa0c movt r2, #0xfeee */
/* @0x21aa10 lsl r8, r4, #2 */
/* @0x21aa14 beq 0x21aa5c <_Z10Audio_Quitv+0x3f8> */
/* @0x21aa18 ldr r7, [r6, r4, lsl #2] */
/* @0x21aa1c add r3, r6, r8 */
/* @0x21aa20 cmp r7, #0 */
/* @0x21aa24 mov r0, r7 */
/* @0x21aa28 beq 0x21aa5c <_Z10Audio_Quitv+0x3f8> */
/* @0x21aa2c ldr r12, [r7] */
/* @0x21aa30 cmp r12, r2 */
/* @0x21aa34 beq 0x21aa54 <_Z10Audio_Quitv+0x3f0> */
/* @0x21aa38 str r1, [sp, #0x4] */
/* @0x21aa3c bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x21aa40 mov r0, r7 */
/* @0x21aa44 bl 0x27d1d0 <_ZdlPv> */
/* @0x21aa48 ldr r1, [sp, #0x4] */
/* @0x21aa4c ldr r3, [r1, #0x2c] */
/* @0x21aa50 add r3, r3, r8 */
/* @0x21aa54 str r10, [r3] */
/* @0x21aa58 ldr r6, [r11, #0x2c] */
/* @0x21aa5c ldr r3, [r9, #0x28] */
/* @0x21aa60 add r4, r4, #1 */
/* @0x21aa64 cmp r4, r3 */
/* @0x21aa68 blt 0x21a9f8 <_Z10Audio_Quitv+0x394> */
/* @0x21aa6c mov r0, r6 */
/* @0x21aa70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21aa74 ldr r3, [pc, #0x270] */
/* @0x21aa78 mov r2, #0 */
/* @0x21aa7c add r3, pc, r3 */
/* @0x21aa80 str r2, [r3, #0x2c] */
/* @0x21aa84 ldr r3, [pc, #0x264] */
/* @0x21aa88 mov r2, #0 */
/* @0x21aa8c add r3, pc, r3 */
/* @0x21aa90 str r2, [r3, #0x28] */
/* @0x21aa94 ldr r9, [pc, #0x258] */
/* @0x21aa98 add r9, pc, r9 */
/* @0x21aa9c ldr r3, [r9, #0x30] */
/* @0x21aaa0 cmp r3, #0 */
/* @0x21aaa4 beq 0x21ab70 <_Z10Audio_Quitv+0x50c> */
/* @0x21aaa8 ldr r6, [r9, #0x34] */
/* @0x21aaac cmp r6, #0 */
/* @0x21aab0 beq 0x21ac6c <_Z10Audio_Quitv+0x608> */
/* @0x21aab4 cmp r3, #0 */
/* @0x21aab8 ble 0x21ab48 <_Z10Audio_Quitv+0x4e4> */
/* @0x21aabc ldr r11, [pc, #0x234] */
/* @0x21aac0 mov r4, #0 */
/* @0x21aac4 ldr r1, [pc, #0x230] */
/* @0x21aac8 mov r10, r4 */
/* @0x21aacc add r11, pc, r11 */
/* @0x21aad0 add r1, pc, r1 */
/* @0x21aad4 ldr r0, [r6] */
/* @0x21aad8 movw r3, #0xfeee */
/* @0x21aadc movt r3, #0xfeee */
/* @0x21aae0 movw r2, #0xfeee */
/* @0x21aae4 cmp r0, r3 */
/* @0x21aae8 movt r2, #0xfeee */
/* @0x21aaec lsl r8, r4, #2 */
/* @0x21aaf0 beq 0x21ab38 <_Z10Audio_Quitv+0x4d4> */
/* @0x21aaf4 ldr r7, [r6, r4, lsl #2] */
/* @0x21aaf8 add r3, r6, r8 */
/* @0x21aafc cmp r7, #0 */
/* @0x21ab00 mov r0, r7 */
/* @0x21ab04 beq 0x21ab38 <_Z10Audio_Quitv+0x4d4> */
/* @0x21ab08 ldr r12, [r7] */
/* @0x21ab0c cmp r12, r2 */
/* @0x21ab10 beq 0x21ab30 <_Z10Audio_Quitv+0x4cc> */
/* @0x21ab14 str r1, [sp, #0x4] */
/* @0x21ab18 bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x21ab1c mov r0, r7 */
/* @0x21ab20 bl 0x27d1d0 <_ZdlPv> */
/* @0x21ab24 ldr r1, [sp, #0x4] */
/* @0x21ab28 ldr r3, [r1, #0x34] */
/* @0x21ab2c add r3, r3, r8 */
/* @0x21ab30 str r10, [r3] */
/* @0x21ab34 ldr r6, [r11, #0x34] */
/* @0x21ab38 ldr r3, [r9, #0x30] */
/* @0x21ab3c add r4, r4, #1 */
/* @0x21ab40 cmp r4, r3 */
/* @0x21ab44 blt 0x21aad4 <_Z10Audio_Quitv+0x470> */
/* @0x21ab48 mov r0, r6 */
/* @0x21ab4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ab50 ldr r3, [pc, #0x1a8] */
/* @0x21ab54 mov r2, #0 */
/* @0x21ab58 add r3, pc, r3 */
/* @0x21ab5c str r2, [r3, #0x34] */
/* @0x21ab60 ldr r3, [pc, #0x19c] */
/* @0x21ab64 mov r2, #0 */
/* @0x21ab68 add r3, pc, r3 */
/* @0x21ab6c str r2, [r3, #0x30] */
/* @0x21ab70 ldr r3, [pc, #0x190] */
/* @0x21ab74 ldr r7, [r5, r3] */
/* @0x21ab78 ldr r3, [r7] */
/* @0x21ab7c cmp r3, #0 */
/* @0x21ab80 beq 0x21a688 <_Z10Audio_Quitv+0x24> */
/* @0x21ab84 ldr r5, [r7, #0x4] */
/* @0x21ab88 cmp r5, #0 */
/* @0x21ab8c beq 0x21ac5c <_Z10Audio_Quitv+0x5f8> */
/* @0x21ab90 cmp r3, #0 */
/* @0x21ab94 ble 0x21ac0c <_Z10Audio_Quitv+0x5a8> */
/* @0x21ab98 mov r4, #0 */
/* @0x21ab9c mov r9, r4 */
/* @0x21aba0 ldr r1, [r5] */
/* @0x21aba4 movw r3, #0xfeee */
/* @0x21aba8 movt r3, #0xfeee */
/* @0x21abac movw r2, #0xfeee */
/* @0x21abb0 cmp r1, r3 */
/* @0x21abb4 movt r2, #0xfeee */
/* @0x21abb8 lsl r8, r4, #2 */
/* @0x21abbc beq 0x21abfc <_Z10Audio_Quitv+0x598> */
/* @0x21abc0 ldr r6, [r5, r4, lsl #2] */
/* @0x21abc4 add r3, r5, r8 */
/* @0x21abc8 cmp r6, #0 */
/* @0x21abcc mov r0, r6 */
/* @0x21abd0 beq 0x21abfc <_Z10Audio_Quitv+0x598> */
/* @0x21abd4 ldr r1, [r6] */
/* @0x21abd8 cmp r1, r2 */
/* @0x21abdc beq 0x21abf4 <_Z10Audio_Quitv+0x590> */
/* @0x21abe0 bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x21abe4 mov r0, r6 */
/* @0x21abe8 bl 0x27d1d0 <_ZdlPv> */
/* @0x21abec ldr r3, [r7, #0x4] */
/* @0x21abf0 add r3, r3, r8 */
/* @0x21abf4 str r9, [r3] */
/* @0x21abf8 ldr r5, [r7, #0x4] */
/* @0x21abfc ldr r3, [r7] */
/* @0x21ac00 add r4, r4, #1 */
/* @0x21ac04 cmp r4, r3 */
/* @0x21ac08 blt 0x21aba0 <_Z10Audio_Quitv+0x53c> */
/* @0x21ac0c mov r0, r5 */
/* @0x21ac10 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac14 mov r3, #0 */
/* @0x21ac18 str r3, [r7, #0x4] */
/* @0x21ac1c mov r3, #0 */
/* @0x21ac20 str r3, [r7] */
/* @0x21ac24 add sp, sp, #12 */
/* @0x21ac28 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21ac2c mov r0, r7 */
/* @0x21ac30 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac34 str r7, [r6, #0x4c] */
/* @0x21ac38 b 0x21a9b4 <_Z10Audio_Quitv+0x350> */
/* @0x21ac3c mov r0, r6 */
/* @0x21ac40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac44 str r6, [r9, #0x3c] */
/* @0x21ac48 b 0x21a920 <_Z10Audio_Quitv+0x2bc> */
/* @0x21ac4c mov r0, r6 */
/* @0x21ac50 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac54 str r6, [r9, #0x24] */
/* @0x21ac58 b 0x21a844 <_Z10Audio_Quitv+0x1e0> */
/* @0x21ac5c mov r0, r5 */
/* @0x21ac60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac64 str r5, [r7, #0x4] */
/* @0x21ac68 b 0x21ac1c <_Z10Audio_Quitv+0x5b8> */
/* @0x21ac6c mov r0, r6 */
/* @0x21ac70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac74 str r6, [r9, #0x34] */
/* @0x21ac78 b 0x21ab60 <_Z10Audio_Quitv+0x4fc> */
/* @0x21ac7c mov r0, r6 */
/* @0x21ac80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ac84 str r6, [r9, #0x2c] */
/* @0x21ac88 b 0x21aa84 <_Z10Audio_Quitv+0x420> */
/* @0x21ac8c mov r1, r3 */
/* @0x21ac90 b 0x21a764 <_Z10Audio_Quitv+0x100> */
/* @0x21ac94 ldrsbeq r7, [sp], -r12 */
/* @0x21ac98 .word 0xffffd0e0 */
/* @0x21ac9c ldrsheq r10, [r3], #-184 */
/* @0x21aca0 .word 0xffffd400 */
/* @0x21aca4 .word 0xfffff77c */
/* @0x21aca8 .word 0xfffff780 */
/* @0x21acac subseq r10, r3, r8, lsl r11 */
/* @0x21acb0 subseq r10, r3, r4, ror #21 */
/* @0x21acb4 subseq r10, r3, r0, ror #21 */
/* @0x21acb8 subseq r10, r3, r8, asr r10 */
/* @0x21acbc subseq r10, r3, r8, asr #20 */
/* @0x21acc0 subseq r10, r3, r12, lsr r10 */
/* @0x21acc4 subseq r10, r3, r8, lsl #20 */
/* @0x21acc8 subseq r10, r3, r4, lsl #20 */
/* @0x21accc subseq r10, r3, r12, ror r9 */
/* @0x21acd0 subseq r10, r3, r12, ror #18 */
/* @0x21acd4 subseq r10, r3, r0, ror #18 */
/* @0x21acd8 subseq r10, r3, r8, lsr r9 */
/* @0x21acdc subseq r10, r3, r8, ror #17 */
/* @0x21ace0 ldrsbeq r10, [r3], #-136 */
/* @0x21ace4 subseq r10, r3, r4, lsr #17 */
/* @0x21ace8 subseq r10, r3, r0, lsr #17 */
/* @0x21acec subseq r10, r3, r8, lsl r8 */
/* @0x21acf0 subseq r10, r3, r8, lsl #16 */
/* @0x21acf4 ldrsheq r10, [r3], #-124 */
/* @0x21acf8 subseq r10, r3, r8, asr #15 */
/* @0x21acfc subseq r10, r3, r4, asr #15 */
/* @0x21ad00 subseq r10, r3, r12, lsr r7 */
/* @0x21ad04 subseq r10, r3, r12, lsr #14 */
/* @0x21ad08 .word 0xfffff788 */

/* ── FUNC 0x21ad0c · Audio_StopAllGroup(int) · size=208 · insn=52 */
/* @0x21ad0c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x21ad10 mov r7, r0 */
/* @0x21ad14 ldr r3, [pc, #0xac] */
/* @0x21ad18 ldr r3, [pc, r3] */
/* @0x21ad1c ldrb r4, [r3] */
/* @0x21ad20 cmp r4, #0 */
/* @0x21ad24 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21ad28 ldr r3, [pc, #0x9c] */
/* @0x21ad2c ldr r3, [pc, r3] */
/* @0x21ad30 ldrb r3, [r3] */
/* @0x21ad34 cmp r3, #0 */
/* @0x21ad38 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21ad3c ldr r3, [pc, #0x8c] */
/* @0x21ad40 add r3, pc, r3 */
/* @0x21ad44 ldr r6, [r3, #0x38] */
/* @0x21ad48 cmp r6, #0 */
/* @0x21ad4c pople {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21ad50 ldr r9, [pc, #0x7c] */
/* @0x21ad54 mov r3, r6 */
/* @0x21ad58 ldr r8, [pc, #0x78] */
/* @0x21ad5c add r9, pc, r9 */
/* @0x21ad60 add r8, pc, r8 */
/* @0x21ad64 b 0x21ad78 <_Z18Audio_StopAllGroupi+0x6c> */
/* @0x21ad68 add r4, r4, #1 */
/* @0x21ad6c cmp r4, r6 */
/* @0x21ad70 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21ad74 ldr r3, [r8, #0x38] */
/* @0x21ad78 cmp r3, r4 */
/* @0x21ad7c ble 0x21ad68 <_Z18Audio_StopAllGroupi+0x5c> */
/* @0x21ad80 ldr r3, [r9, #0x3c] */
/* @0x21ad84 ldr r5, [r3, r4, lsl #2] */
/* @0x21ad88 cmp r5, #0 */
/* @0x21ad8c beq 0x21ad68 <_Z18Audio_StopAllGroupi+0x5c> */
/* @0x21ad90 ldrb r3, [r5, #0x5] */
/* @0x21ad94 cmp r3, #0 */
/* @0x21ad98 beq 0x21ad68 <_Z18Audio_StopAllGroupi+0x5c> */
/* @0x21ad9c ldr r0, [r5, #0x18] */
/* @0x21ada0 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21ada4 cmp r0, #0 */
/* @0x21ada8 beq 0x21ad68 <_Z18Audio_StopAllGroupi+0x5c> */
/* @0x21adac ldr r3, [r0, #0x4c] */
/* @0x21adb0 cmp r3, r7 */
/* @0x21adb4 bne 0x21ad68 <_Z18Audio_StopAllGroupi+0x5c> */
/* @0x21adb8 mov r0, r5 */
/* @0x21adbc mov r1, #0 */
/* @0x21adc0 bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb> */
/* @0x21adc4 b 0x21ad68 <_Z18Audio_StopAllGroupi+0x5c> */
/* @0x21adc8 andseq r4, sp, r4, lsr r3 */
/* @0x21adcc andseq r4, sp, r4 */
/* @0x21add0 subseq r10, r3, r4, asr r5 */
/* @0x21add4 subseq r10, r3, r8, lsr r5 */
/* @0x21add8 subseq r10, r3, r4, lsr r5 */

/* ── FUNC 0x21addc · Audio_GetSoundSourceToPlay(int, float) · size=1216 · insn=304 */
/* @0x21addc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21ade0 vpush {d8} */
/* @0x21ade4 mov r5, r0 */
/* @0x21ade8 ldr r11, [pc, #0x46c] */
/* @0x21adec sub sp, sp, #36 */
/* @0x21adf0 ldr r3, [pc, #0x468] */
/* @0x21adf4 vmov s16, r1 */
/* @0x21adf8 add r11, pc, r11 */
/* @0x21adfc ldr r3, [r11, r3] */
/* @0x21ae00 ldrb r3, [r3] */
/* @0x21ae04 cmp r3, #0 */
/* @0x21ae08 bne 0x21b01c <_Z26Audio_GetSoundSourceToPlayif+0x240> */
/* @0x21ae0c ldr r3, [pc, #0x450] */
/* @0x21ae10 add r3, pc, r3 */
/* @0x21ae14 ldr r4, [r3, #0x38] */
/* @0x21ae18 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21ae1c ldrb r3, [r0, #0x24] */
/* @0x21ae20 cmp r3, #0 */
/* @0x21ae24 ldrbeq r3, [r0, #0x25] */
/* @0x21ae28 movne r3, #1 */
/* @0x21ae2c str r3, [sp, #0xc] */
/* @0x21ae30 ldrb r3, [r0, #0x5c] */
/* @0x21ae34 cmp r3, #0 */
/* @0x21ae38 bne 0x21b030 <_Z26Audio_GetSoundSourceToPlayif+0x254> */
/* @0x21ae3c cmp r4, #0 */
/* @0x21ae40 ble 0x21b008 <_Z26Audio_GetSoundSourceToPlayif+0x22c> */
/* @0x21ae44 ldr r7, [pc, #0x41c] */
/* @0x21ae48 mov r3, r11 */
/* @0x21ae4c mov r6, #0 */
/* @0x21ae50 movw r10, #0x869f */
/* @0x21ae54 mov r11, r4 */
/* @0x21ae58 add r7, pc, r7 */
/* @0x21ae5c add r8, sp, #28 */
/* @0x21ae60 movt r10, #0x1 */
/* @0x21ae64 mov r5, r6 */
/* @0x21ae68 mov r4, r3 */
/* @0x21ae6c b 0x21aebc <_Z26Audio_GetSoundSourceToPlayif+0xe0> */
/* @0x21ae70 ldrb r3, [r9, #0x5] */
/* @0x21ae74 cmp r3, #0 */
/* @0x21ae78 beq 0x21afb8 <_Z26Audio_GetSoundSourceToPlayif+0x1dc> */
/* @0x21ae7c ldrb r3, [r9, #0xc] */
/* @0x21ae80 cmp r3, #0 */
/* @0x21ae84 beq 0x21afc8 <_Z26Audio_GetSoundSourceToPlayif+0x1ec> */
/* @0x21ae88 ldrb r3, [r9, #0xd] */
/* @0x21ae8c cmp r3, #0 */
/* @0x21ae90 beq 0x21aeac <_Z26Audio_GetSoundSourceToPlayif+0xd0> */
/* @0x21ae94 ldr r3, [sp, #0xc] */
/* @0x21ae98 cmp r3, #0 */
/* @0x21ae9c beq 0x21aeac <_Z26Audio_GetSoundSourceToPlayif+0xd0> */
/* @0x21aea0 ldr r2, [r9, #0x8] */
/* @0x21aea4 cmp r2, #0 */
/* @0x21aea8 beq 0x21b214 <_Z26Audio_GetSoundSourceToPlayif+0x438> */
/* @0x21aeac add r5, r5, #1 */
/* @0x21aeb0 add r6, r6, #4 */
/* @0x21aeb4 cmp r5, r11 */
/* @0x21aeb8 beq 0x21af28 <_Z26Audio_GetSoundSourceToPlayif+0x14c> */
/* @0x21aebc ldr r3, [r7, #0x38] */
/* @0x21aec0 cmp r3, r5 */
/* @0x21aec4 ldrgt r3, [r7, #0x3c] */
/* @0x21aec8 movle r9, #0 */
/* @0x21aecc ldrgt r9, [r3, r6] */
/* @0x21aed0 ldr r3, [r9, #0x18] */
/* @0x21aed4 sub r3, r3, #199680 */
/* @0x21aed8 sub r3, r3, #320 */
/* @0x21aedc cmp r3, r10 */
/* @0x21aee0 bhi 0x21ae70 <_Z26Audio_GetSoundSourceToPlayif+0x94> */
/* @0x21aee4 ldr r3, [pc, #0x380] */
/* @0x21aee8 mvn r2, #0 */
/* @0x21aeec str r2, [sp, #0x1c] */
/* @0x21aef0 movw r1, #0x1015 */
/* @0x21aef4 ldr r0, [r9, #0x10] */
/* @0x21aef8 mov r2, r8 */
/* @0x21aefc ldr r3, [r4, r3] */
/* @0x21af00 ldr r3, [r3] */
/* @0x21af04 ldr r0, [r3, r0, lsl #2] */
/* @0x21af08 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x21af0c ldr r3, [sp, #0x1c] */
/* @0x21af10 cmp r3, #0 */
/* @0x21af14 ble 0x21ae70 <_Z26Audio_GetSoundSourceToPlayif+0x94> */
/* @0x21af18 add r5, r5, #1 */
/* @0x21af1c add r6, r6, #4 */
/* @0x21af20 cmp r5, r11 */
/* @0x21af24 bne 0x21aebc <_Z26Audio_GetSoundSourceToPlayif+0xe0> */
/* @0x21af28 mov r3, r4 */
/* @0x21af2c mov r4, r11 */
/* @0x21af30 mov r11, r3 */
/* @0x21af34 ldr r3, [pc, #0x334] */
/* @0x21af38 ldr r3, [r11, r3] */
/* @0x21af3c ldr r3, [r3] */
/* @0x21af40 cmp r4, r3 */
/* @0x21af44 blt 0x21b08c <_Z26Audio_GetSoundSourceToPlayif+0x2b0> */
/* @0x21af48 ldr r3, [pc, #0x324] */
/* @0x21af4c ldr r2, [sp, #0xc] */
/* @0x21af50 add r3, pc, r3 */
/* @0x21af54 cmp r2, #0 */
/* @0x21af58 ldr r1, [r3, #0x38] */
/* @0x21af5c ldr r0, [r3, #0x3c] */
/* @0x21af60 bne 0x21b054 <_Z26Audio_GetSoundSourceToPlayif+0x278> */
/* @0x21af64 mov r10, r2 */
/* @0x21af68 mov r9, r2 */
/* @0x21af6c cmp r10, r1 */
/* @0x21af70 mov r3, #0 */
/* @0x21af74 ldrlt r3, [r0, r10, lsl #2] */
/* @0x21af78 vldr s15, [r3, #28] */
/* @0x21af7c vcmpe.f32 s15, s16 */
/* @0x21af80 add r10, r10, #1 */
/* @0x21af84 vmrs APSR_nzcv, fpscr */
/* @0x21af88 bpl 0x21af9c <_Z26Audio_GetSoundSourceToPlayif+0x1c0> */
/* @0x21af8c ldrb r2, [r3, #0xc] */
/* @0x21af90 cmp r2, #0 */
/* @0x21af94 vmoveq.f32 s16, s15 */
/* @0x21af98 moveq r9, r3 */
/* @0x21af9c cmp r10, r4 */
/* @0x21afa0 bne 0x21af6c <_Z26Audio_GetSoundSourceToPlayif+0x190> */
/* @0x21afa4 cmp r9, #0 */
/* @0x21afa8 beq 0x21afb8 <_Z26Audio_GetSoundSourceToPlayif+0x1dc> */
/* @0x21afac mov r0, r9 */
/* @0x21afb0 mov r1, #1 */
/* @0x21afb4 bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb> */
/* @0x21afb8 mov r0, r9 */
/* @0x21afbc add sp, sp, #36 */
/* @0x21afc0 vpop {d8} */
/* @0x21afc4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21afc8 ldr r3, [pc, #0x29c] */
/* @0x21afcc movw r1, #0x1010 */
/* @0x21afd0 mov r2, r8 */
/* @0x21afd4 ldr r3, [r4, r3] */
/* @0x21afd8 ldr r3, [r3] */
/* @0x21afdc ldr r0, [r3, r6] */
/* @0x21afe0 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x21afe4 ldr r3, [sp, #0x1c] */
/* @0x21afe8 movw r2, #0x1014 */
/* @0x21afec movw r1, #0x1011 */
/* @0x21aff0 cmp r3, r2 */
/* @0x21aff4 cmpne r3, r1 */
/* @0x21aff8 bne 0x21aeac <_Z26Audio_GetSoundSourceToPlayif+0xd0> */
/* @0x21affc mov r0, r9 */
/* @0x21b000 bl 0x21a048 <_Z22Audio_SetNoiseInactiveP6CNoise> */
/* @0x21b004 b 0x21afb8 <_Z26Audio_GetSoundSourceToPlayif+0x1dc> */
/* @0x21b008 ldr r3, [pc, #0x260] */
/* @0x21b00c ldr r3, [r11, r3] */
/* @0x21b010 ldr r3, [r3] */
/* @0x21b014 cmp r4, r3 */
/* @0x21b018 blt 0x21b08c <_Z26Audio_GetSoundSourceToPlayif+0x2b0> */
/* @0x21b01c mov r9, #0 */
/* @0x21b020 mov r0, r9 */
/* @0x21b024 add sp, sp, #36 */
/* @0x21b028 vpop {d8} */
/* @0x21b02c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21b030 mov r0, r5 */
/* @0x21b034 bl 0x216560 <_Z31Audio_GetNoiseFromQueuedSoundIDi> */
/* @0x21b038 cmp r0, #0 */
/* @0x21b03c movne r9, r0 */
/* @0x21b040 beq 0x21ae3c <_Z26Audio_GetSoundSourceToPlayif+0x60> */
/* @0x21b044 mov r0, r9 */
/* @0x21b048 add sp, sp, #36 */
/* @0x21b04c vpop {d8} */
/* @0x21b050 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21b054 mov r3, #0 */
/* @0x21b058 mov r9, r3 */
/* @0x21b05c cmp r3, r1 */
/* @0x21b060 mov r2, #0 */
/* @0x21b064 ldrlt r2, [r0, r3, lsl #2] */
/* @0x21b068 vldr s15, [r2, #28] */
/* @0x21b06c vcmpe.f32 s15, s16 */
/* @0x21b070 add r3, r3, #1 */
/* @0x21b074 vmrs APSR_nzcv, fpscr */
/* @0x21b078 vmovmi.f32 s16, s15 */
/* @0x21b07c movmi r9, r2 */
/* @0x21b080 cmp r3, r4 */
/* @0x21b084 bne 0x21b05c <_Z26Audio_GetSoundSourceToPlayif+0x280> */
/* @0x21b088 b 0x21afa4 <_Z26Audio_GetSoundSourceToPlayif+0x1c8> */
/* @0x21b08c mov r0, #60 */
/* @0x21b090 ldr r10, [pc, #0x1e0] */
/* @0x21b094 bl 0x27c524 <_Znwj> */
/* @0x21b098 add r10, pc, r10 */
/* @0x21b09c mov r9, r0 */
/* @0x21b0a0 bl 0x21dad8 <_ZN6CNoiseC2Ev> */
/* @0x21b0a4 ldr r5, [r10, #0x38] */
/* @0x21b0a8 str r4, [r9, #0x10] */
/* @0x21b0ac adds r1, r5, #1 */
/* @0x21b0b0 str r1, [sp, #0xc] */
/* @0x21b0b4 bne 0x21b188 <_Z26Audio_GetSoundSourceToPlayif+0x3ac> */
/* @0x21b0b8 ldr r3, [r10, #0x3c] */
/* @0x21b0bc cmp r3, #0 */
/* @0x21b0c0 beq 0x21b23c <_Z26Audio_GetSoundSourceToPlayif+0x460> */
/* @0x21b0c4 cmp r5, #0 */
/* @0x21b0c8 ble 0x21b168 <_Z26Audio_GetSoundSourceToPlayif+0x38c> */
/* @0x21b0cc ldr r1, [pc, #0x1a8] */
/* @0x21b0d0 ldr r12, [pc, #0x1a8] */
/* @0x21b0d4 ldr r6, [sp, #0xc] */
/* @0x21b0d8 add r1, pc, r1 */
/* @0x21b0dc add r12, pc, r12 */
/* @0x21b0e0 str r4, [sp, #0x10] */
/* @0x21b0e4 mov r8, r1 */
/* @0x21b0e8 str r5, [sp, #0x14] */
/* @0x21b0ec mov r11, r6 */
/* @0x21b0f0 mov r4, r12 */
/* @0x21b0f4 ldr r1, [r3] */
/* @0x21b0f8 movw r2, #0xfeee */
/* @0x21b0fc movt r2, #0xfeee */
/* @0x21b100 movw lr, #0xfeee */
/* @0x21b104 cmp r1, r2 */
/* @0x21b108 movt lr, #0xfeee */
/* @0x21b10c lsl r5, r6, #2 */
/* @0x21b110 beq 0x21b150 <_Z26Audio_GetSoundSourceToPlayif+0x374> */
/* @0x21b114 ldr r7, [r3, r6, lsl #2] */
/* @0x21b118 add r1, r3, r5 */
/* @0x21b11c cmp r7, #0 */
/* @0x21b120 mov r0, r7 */
/* @0x21b124 beq 0x21b150 <_Z26Audio_GetSoundSourceToPlayif+0x374> */
/* @0x21b128 ldr r3, [r7] */
/* @0x21b12c cmp r3, lr */
/* @0x21b130 beq 0x21b148 <_Z26Audio_GetSoundSourceToPlayif+0x36c> */
/* @0x21b134 bl 0x21db28 <_ZN6CNoiseD2Ev> */
/* @0x21b138 mov r0, r7 */
/* @0x21b13c bl 0x27d1d0 <_ZdlPv> */
/* @0x21b140 ldr r1, [r4, #0x3c] */
/* @0x21b144 add r1, r1, r5 */
/* @0x21b148 str r11, [r1] */
/* @0x21b14c ldr r3, [r8, #0x3c] */
/* @0x21b150 ldr r2, [r10, #0x38] */
/* @0x21b154 add r6, r6, #1 */
/* @0x21b158 cmp r6, r2 */
/* @0x21b15c blt 0x21b0f4 <_Z26Audio_GetSoundSourceToPlayif+0x318> */
/* @0x21b160 ldr r4, [sp, #0x10] */
/* @0x21b164 ldr r5, [sp, #0x14] */
/* @0x21b168 mov r0, r3 */
/* @0x21b16c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21b170 ldr r1, [pc, #0x10c] */
/* @0x21b174 mov r3, #0 */
/* @0x21b178 add r1, pc, r1 */
/* @0x21b17c mov r2, r3 */
/* @0x21b180 str r3, [r1, #0x3c] */
/* @0x21b184 b 0x21b1b8 <_Z26Audio_GetSoundSourceToPlayif+0x3dc> */
/* @0x21b188 ldr r2, [sp, #0xc] */
/* @0x21b18c lsls r1, r2, #2 */
/* @0x21b190 beq 0x21b238 <_Z26Audio_GetSoundSourceToPlayif+0x45c> */
/* @0x21b194 ldr r2, [pc, #0xec] */
/* @0x21b198 mov r3, #0 */
/* @0x21b19c ldr r0, [r10, #0x3c] */
/* @0x21b1a0 add r2, pc, r2 */
/* @0x21b1a4 str r3, [sp] */
/* @0x21b1a8 mov r3, #135 */
/* @0x21b1ac bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21b1b0 mov r2, r0 */
/* @0x21b1b4 str r0, [r10, #0x3c] */
/* @0x21b1b8 ldr r3, [pc, #0xcc] */
/* @0x21b1bc cmp r4, r5 */
/* @0x21b1c0 ldr r1, [sp, #0xc] */
/* @0x21b1c4 add r3, pc, r3 */
/* @0x21b1c8 str r1, [r3, #0x38] */
/* @0x21b1cc bge 0x21b20c <_Z26Audio_GetSoundSourceToPlayif+0x430> */
/* @0x21b1d0 ldr r0, [pc, #0xb8] */
/* @0x21b1d4 lsl r3, r5, #2 */
/* @0x21b1d8 add r0, pc, r0 */
/* @0x21b1dc b 0x21b1e4 <_Z26Audio_GetSoundSourceToPlayif+0x408> */
/* @0x21b1e0 ldr r2, [r0, #0x3c] */
/* @0x21b1e4 add r1, r2, r3 */
/* @0x21b1e8 sub r5, r5, #1 */
/* @0x21b1ec cmp r5, r4 */
/* @0x21b1f0 ldr r1, [r1, #-0x4] */
/* @0x21b1f4 str r1, [r2, r3] */
/* @0x21b1f8 sub r3, r3, #4 */
/* @0x21b1fc bne 0x21b1e0 <_Z26Audio_GetSoundSourceToPlayif+0x404> */
/* @0x21b200 ldr r3, [pc, #0x8c] */
/* @0x21b204 add r3, pc, r3 */
/* @0x21b208 ldr r2, [r3, #0x3c] */
/* @0x21b20c str r9, [r2, r4, lsl #2] */
/* @0x21b210 b 0x21afb8 <_Z26Audio_GetSoundSourceToPlayif+0x1dc> */
/* @0x21b214 ldr r0, [r9, #0x38] */
/* @0x21b218 cmp r0, #0 */
/* @0x21b21c beq 0x21afb8 <_Z26Audio_GetSoundSourceToPlayif+0x1dc> */
/* @0x21b220 mov r1, r9 */
/* @0x21b224 str r2, [sp, #0x8] */
/* @0x21b228 bl 0x2158dc <_ZN8CEmitter22RemoveNoiseFromEmitterEP6CNoise> */
/* @0x21b22c ldr r2, [sp, #0x8] */
/* @0x21b230 str r2, [r9, #0x38] */
/* @0x21b234 b 0x21afb8 <_Z26Audio_GetSoundSourceToPlayif+0x1dc> */
/* @0x21b238 ldr r3, [r10, #0x3c] */
/* @0x21b23c mov r0, r3 */
/* @0x21b240 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21b244 ldr r1, [pc, #0x4c] */
/* @0x21b248 mov r3, #0 */
/* @0x21b24c add r1, pc, r1 */
/* @0x21b250 mov r2, r3 */
/* @0x21b254 str r3, [r1, #0x3c] */
/* @0x21b258 b 0x21b1b8 <_Z26Audio_GetSoundSourceToPlayif+0x3dc> */
/* @0x21b25c andseq r6, sp, r8, asr lr */
/* @0x21b260 .word 0xffffd3fc */
/* @0x21b264 subseq r10, r3, r4, lsl #9 */
/* @0x21b268 subseq r10, r3, r12, lsr r4 */
/* @0x21b26c .word 0xfffff77c */
/* @0x21b270 .word 0xfffff784 */
/* @0x21b274 subseq r10, r3, r4, asr #6 */
/* @0x21b278 ldrsheq r10, [r3], #-28 */
/* @0x21b27c ldrheq r10, [r3], #-28 */
/* @0x21b280 ldrheq r10, [r3], #-24 */
/* @0x21b284 subseq r10, r3, r12, lsl r1 */
/* @0x21b288 andseq r2, r3, r0, asr r1 */
/* @0x21b28c ldrsbeq r10, [r3], #-0 */
/* @0x21b290 ldrheq r10, [r3], #-12 */
/* @0x21b294 .word 0x0053a090 */
/* @0x21b298 subseq r10, r3, r8, asr #32 */

/* ── FUNC 0x21b29c · Audio_PlaySoundAt(int, double, double, double, double, double, double, int, double) · size=828 · insn=207 */
/* @0x21b29c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x21b2a0 vpush {d8, d9} */
/* @0x21b2a4 vmov d8, r2, r3 */
/* @0x21b2a8 ldr r4, [pc, #0x2f4] */
/* @0x21b2ac sub sp, sp, #8 */
/* @0x21b2b0 ldr r1, [pc, #0x2f0] */
/* @0x21b2b4 mov r9, r0 */
/* @0x21b2b8 add r4, pc, r4 */
/* @0x21b2bc ldr r3, [r4, r1] */
/* @0x21b2c0 ldrb r7, [r3] */
/* @0x21b2c4 cmp r7, #0 */
/* @0x21b2c8 bne 0x21b4dc <_Z17Audio_PlaySoundAtiddddddid+0x240> */
/* @0x21b2cc ldr r3, [pc, #0x2d8] */
/* @0x21b2d0 ldr r3, [r4, r3] */
/* @0x21b2d4 ldrb r3, [r3] */
/* @0x21b2d8 cmp r3, #0 */
/* @0x21b2dc beq 0x21b4dc <_Z17Audio_PlaySoundAtiddddddid+0x240> */
/* @0x21b2e0 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21b2e4 subs r8, r0, #0 */
/* @0x21b2e8 beq 0x21b57c <_Z17Audio_PlaySoundAtiddddddid+0x2e0> */
/* @0x21b2ec ldr r3, [pc, #0x2bc] */
/* @0x21b2f0 ldr r1, [r8, #0x4c] */
/* @0x21b2f4 ldr r0, [r4, r3] */
/* @0x21b2f8 bl 0x21e1e0 <_ZN14CAudioGroupMan13IsGroupLoadedEi> */
/* @0x21b2fc subs r5, r0, #0 */
/* @0x21b300 beq 0x21b498 <_Z17Audio_PlaySoundAtiddddddid+0x1fc> */
/* @0x21b304 vldr d6, [sp, #104] */
/* @0x21b308 vcvt.f32.f64 s18, d6 */
/* @0x21b30c mov r0, r9 */
/* @0x21b310 vmov r1, s18 */
/* @0x21b314 bl 0x21addc <_Z26Audio_GetSoundSourceToPlayif> */
/* @0x21b318 subs r5, r0, #0 */
/* @0x21b31c beq 0x21b4dc <_Z17Audio_PlaySoundAtiddddddid+0x240> */
/* @0x21b320 ldr r3, [pc, #0x28c] */
/* @0x21b324 mov r0, #1065353216 */
/* @0x21b328 ldr r2, [sp, #0x60] */
/* @0x21b32c ldr r10, [r8, #0x4] */
/* @0x21b330 cmp r2, #0 */
/* @0x21b334 ldr r2, [r4, r3] */
/* @0x21b338 vstr s18, [r5, #28] */
/* @0x21b33c str r9, [r5, #0x18] */
/* @0x21b340 movle r1, #0 */
/* @0x21b344 movgt r1, #1 */
/* @0x21b348 ldr r3, [r2] */
/* @0x21b34c strb r1, [r5, #0x4] */
/* @0x21b350 str r7, [r5, #0x2c] */
/* @0x21b354 add r1, r3, #1 */
/* @0x21b358 str r3, [r5, #0x14] */
/* @0x21b35c str r0, [r5, #0x24] */
/* @0x21b360 str r1, [r2] */
/* @0x21b364 ldr r6, [r5, #0x10] */
/* @0x21b368 bl 0xb6a54 <alGetError@plt> */
/* @0x21b36c subs r2, r0, #0 */
/* @0x21b370 bne 0x21b558 <_Z17Audio_PlaySoundAtiddddddid+0x2bc> */
/* @0x21b374 ldr r3, [pc, #0x23c] */
/* @0x21b378 movw r1, #0x202 */
/* @0x21b37c mov r2, #0 */
/* @0x21b380 ldr r7, [r4, r3] */
/* @0x21b384 ldr r3, [r7] */
/* @0x21b388 ldr r0, [r3, r6, lsl #2] */
/* @0x21b38c bl 0xb6a6c <alSourcei@plt> */
/* @0x21b390 ldr r3, [r7] */
/* @0x21b394 mov r2, r10 */
/* @0x21b398 movw r1, #0x100a */
/* @0x21b39c ldr r0, [r3, r6, lsl #2] */
/* @0x21b3a0 bl 0xb6a78 <alSourcef@plt> */
/* @0x21b3a4 ldr r3, [r7] */
/* @0x21b3a8 ldr r2, [r8, #0x8] */
/* @0x21b3ac movw r1, #0x1003 */
/* @0x21b3b0 ldr r0, [r3, r6, lsl #2] */
/* @0x21b3b4 bl 0xb6a78 <alSourcef@plt> */
/* @0x21b3b8 bl 0xb6a54 <alGetError@plt> */
/* @0x21b3bc subs r2, r0, #0 */
/* @0x21b3c0 bne 0x21b534 <_Z17Audio_PlaySoundAtiddddddid+0x298> */
/* @0x21b3c4 vldr d6, [sp, #80] */
/* @0x21b3c8 vcvt.f32.f64 s13, d6 */
/* @0x21b3cc ldr r3, [r7] */
/* @0x21b3d0 movw r1, #0x1023 */
/* @0x21b3d4 ldr r0, [r3, r6, lsl #2] */
/* @0x21b3d8 vmov r2, s13 */
/* @0x21b3dc bl 0xb6a78 <alSourcef@plt> */
/* @0x21b3e0 bl 0xb6a54 <alGetError@plt> */
/* @0x21b3e4 subs r2, r0, #0 */
/* @0x21b3e8 bne 0x21b510 <_Z17Audio_PlaySoundAtiddddddid+0x274> */
/* @0x21b3ec vldr d7, [sp, #72] */
/* @0x21b3f0 vcvt.f32.f64 s15, d7 */
/* @0x21b3f4 ldr r3, [r7] */
/* @0x21b3f8 movw r1, #0x1020 */
/* @0x21b3fc ldr r0, [r3, r6, lsl #2] */
/* @0x21b400 vmov r2, s15 */
/* @0x21b404 bl 0xb6a78 <alSourcef@plt> */
/* @0x21b408 vldr d6, [sp, #88] */
/* @0x21b40c vcvt.f32.f64 s13, d6 */
/* @0x21b410 ldr r3, [r7] */
/* @0x21b414 movw r1, #0x1021 */
/* @0x21b418 ldr r0, [r3, r6, lsl #2] */
/* @0x21b41c vmov r2, s13 */
/* @0x21b420 bl 0xb6a78 <alSourcef@plt> */
/* @0x21b424 vldr d6, [sp, #64] */
/* @0x21b428 vcvt.f32.f64 s15, d6 */
/* @0x21b42c ldr r3, [r7] */
/* @0x21b430 movw r1, #0x1004 */
/* @0x21b434 ldr r0, [r3, r6, lsl #2] */
/* @0x21b438 vcvt.f32.f64 s13, d8 */
/* @0x21b43c vstr s15, [sp] */
/* @0x21b440 vldr d7, [sp, #56] */
/* @0x21b444 vcvt.f32.f64 s15, d7 */
/* @0x21b448 vmov r2, s13 */
/* @0x21b44c vmov r3, s15 */
/* @0x21b450 bl 0xb6b2c <alSource3f@plt> */
/* @0x21b454 ldr r0, [r7] */
/* @0x21b458 mov r3, #0 */
/* @0x21b45c movw r1, #0x1006 */
/* @0x21b460 mov r2, r3 */
/* @0x21b464 ldr r0, [r0, r6, lsl #2] */
/* @0x21b468 str r3, [sp] */
/* @0x21b46c bl 0xb6b2c <alSource3f@plt> */
/* @0x21b470 bl 0xb6a54 <alGetError@plt> */
/* @0x21b474 subs r2, r0, #0 */
/* @0x21b478 bne 0x21b4ec <_Z17Audio_PlaySoundAtiddddddid+0x250> */
/* @0x21b47c mov r0, r8 */
/* @0x21b480 mov r1, r5 */
/* @0x21b484 bl 0x2173d8 <_Z21Audio_StartSoundNoiseP12cAudio_SoundP6CNoise> */
/* @0x21b488 ldr r0, [r5, #0x14] */
/* @0x21b48c add sp, sp, #8 */
/* @0x21b490 vpop {d8, d9} */
/* @0x21b494 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21b498 ldr r3, [pc, #0x11c] */
/* @0x21b49c mov r0, r9 */
/* @0x21b4a0 ldr r3, [r4, r3] */
/* @0x21b4a4 ldr r4, [r3] */
/* @0x21b4a8 ldr r3, [r4] */
/* @0x21b4ac ldr r6, [r3, #0xc] */
/* @0x21b4b0 bl 0x218348 <_Z13Audio_GetNamei> */
/* @0x21b4b4 ldr r1, [pc, #0x104] */
/* @0x21b4b8 ldr r3, [r8, #0x4c] */
/* @0x21b4bc add r1, pc, r1 */
/* @0x21b4c0 mov r2, r0 */
/* @0x21b4c4 mov r0, r4 */
/* @0x21b4c8 blx r6 */
/* @0x21b4cc mov r0, r5 */
/* @0x21b4d0 add sp, sp, #8 */
/* @0x21b4d4 vpop {d8, d9} */
/* @0x21b4d8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21b4dc mvn r0, #0 */
/* @0x21b4e0 add sp, sp, #8 */
/* @0x21b4e4 vpop {d8, d9} */
/* @0x21b4e8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21b4ec ldr r3, [pc, #0xc8] */
/* @0x21b4f0 ldr r1, [pc, #0xcc] */
/* @0x21b4f4 ldr r3, [r4, r3] */
/* @0x21b4f8 add r1, pc, r1 */
/* @0x21b4fc ldr r0, [r3] */
/* @0x21b500 ldr r3, [r0] */
/* @0x21b504 ldr r3, [r3, #0xc] */
/* @0x21b508 blx r3 */
/* @0x21b50c b 0x21b47c <_Z17Audio_PlaySoundAtiddddddid+0x1e0> */
/* @0x21b510 ldr r3, [pc, #0xa4] */
/* @0x21b514 ldr r1, [pc, #0xac] */
/* @0x21b518 ldr r3, [r4, r3] */
/* @0x21b51c add r1, pc, r1 */
/* @0x21b520 ldr r0, [r3] */
/* @0x21b524 ldr r3, [r0] */
/* @0x21b528 ldr r3, [r3, #0xc] */
/* @0x21b52c blx r3 */
/* @0x21b530 b 0x21b3ec <_Z17Audio_PlaySoundAtiddddddid+0x150> */
/* @0x21b534 ldr r3, [pc, #0x80] */
/* @0x21b538 ldr r1, [pc, #0x8c] */
/* @0x21b53c ldr r3, [r4, r3] */
/* @0x21b540 add r1, pc, r1 */
/* @0x21b544 ldr r0, [r3] */
/* @0x21b548 ldr r3, [r0] */
/* @0x21b54c ldr r3, [r3, #0xc] */
/* @0x21b550 blx r3 */
/* @0x21b554 b 0x21b3c4 <_Z17Audio_PlaySoundAtiddddddid+0x128> */
/* @0x21b558 ldr r3, [pc, #0x5c] */
/* @0x21b55c ldr r1, [pc, #0x6c] */
/* @0x21b560 ldr r3, [r4, r3] */
/* @0x21b564 add r1, pc, r1 */
/* @0x21b568 ldr r0, [r3] */
/* @0x21b56c ldr r3, [r0] */
/* @0x21b570 ldr r3, [r3, #0xc] */
/* @0x21b574 blx r3 */
/* @0x21b578 b 0x21b374 <_Z17Audio_PlaySoundAtiddddddid+0xd8> */
/* @0x21b57c ldr r3, [pc, #0x38] */
/* @0x21b580 ldr r1, [pc, #0x4c] */
/* @0x21b584 ldr r3, [r4, r3] */
/* @0x21b588 add r1, pc, r1 */
/* @0x21b58c ldr r0, [r3] */
/* @0x21b590 ldr r3, [r0] */
/* @0x21b594 ldr r3, [r3, #0xc] */
/* @0x21b598 blx r3 */
/* @0x21b59c mov r0, r8 */
/* @0x21b5a0 b 0x21b48c <_Z17Audio_PlaySoundAtiddddddid+0x1f0> */
/* @0x21b5a4 mulseq sp, r8, r9 */
/* @0x21b5a8 .word 0xffffd3fc */
/* @0x21b5ac .word 0xffffd0e0 */
/* @0x21b5b0 .word 0xffffd400 */
/* @0x21b5b4 .word 0xfffff7a0 */
/* @0x21b5b8 .word 0xfffff77c */
/* @0x21b5bc .word 0xffffbac4 */
/* @0x21b5c0 mulseq r3, r8, r11 */
/* @0x21b5c4 ldrheq r8, [r3], -r8 */
/* @0x21b5c8 andseq r8, r3, r12, ror r11 */
/* @0x21b5cc andseq r8, r3, r0, lsl #12 */
/* @0x21b5d0 andseq r8, r3, r4, lsl r11 */
/* @0x21b5d4 andseq r8, r3, r4, lsr #21 */

/* ── FUNC 0x21b5d8 · Audio_PlaySound(int, double, int) · size=744 · insn=186 */
/* @0x21b5d8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x21b5dc vpush {d8} */
/* @0x21b5e0 vmov d8, r2, r3 */
/* @0x21b5e4 ldr r5, [pc, #0x2a0] */
/* @0x21b5e8 sub sp, sp, #20 */
/* @0x21b5ec ldr r1, [pc, #0x29c] */
/* @0x21b5f0 mov r7, r0 */
/* @0x21b5f4 add r5, pc, r5 */
/* @0x21b5f8 ldr r3, [r5, r1] */
/* @0x21b5fc ldrb r3, [r3] */
/* @0x21b600 cmp r3, #0 */
/* @0x21b604 bne 0x21b7d4 <_Z15Audio_PlaySoundidi+0x1fc> */
/* @0x21b608 ldr r3, [pc, #0x284] */
/* @0x21b60c ldr r3, [r5, r3] */
/* @0x21b610 ldrb r3, [r3] */
/* @0x21b614 cmp r3, #0 */
/* @0x21b618 beq 0x21b7d4 <_Z15Audio_PlaySoundidi+0x1fc> */
/* @0x21b61c bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21b620 subs r9, r0, #0 */
/* @0x21b624 beq 0x21b82c <_Z15Audio_PlaySoundidi+0x254> */
/* @0x21b628 ldr r3, [pc, #0x268] */
/* @0x21b62c ldr r1, [r9, #0x4c] */
/* @0x21b630 ldr r0, [r5, r3] */
/* @0x21b634 bl 0x21e1e0 <_ZN14CAudioGroupMan13IsGroupLoadedEi> */
/* @0x21b638 cmp r0, #0 */
/* @0x21b63c beq 0x21b854 <_Z15Audio_PlaySoundidi+0x27c> */
/* @0x21b640 vcvt.f32.f64 s16, d8 */
/* @0x21b644 mov r0, r7 */
/* @0x21b648 vmov r1, s16 */
/* @0x21b64c bl 0x21addc <_Z26Audio_GetSoundSourceToPlayif> */
/* @0x21b650 sub r2, r7, #199680 */
/* @0x21b654 movw r3, #0x869f */
/* @0x21b658 sub r2, r2, #320 */
/* @0x21b65c movt r3, #0x1 */
/* @0x21b660 cmp r2, r3 */
/* @0x21b664 mov r4, r0 */
/* @0x21b668 bls 0x21b79c <_Z15Audio_PlaySoundidi+0x1c4> */
/* @0x21b66c cmp r0, #0 */
/* @0x21b670 beq 0x21b7d4 <_Z15Audio_PlaySoundidi+0x1fc> */
/* @0x21b674 ldr r3, [pc, #0x220] */
/* @0x21b678 ldr r6, [r5, r3] */
/* @0x21b67c bl 0xb6a54 <alGetError@plt> */
/* @0x21b680 subs r2, r0, #0 */
/* @0x21b684 bne 0x21b808 <_Z15Audio_PlaySoundidi+0x230> */
/* @0x21b688 ldr r3, [pc, #0x210] */
/* @0x21b68c mov r1, #0 */
/* @0x21b690 ldr r2, [sp, #0x38] */
/* @0x21b694 mov lr, #1065353216 */
/* @0x21b698 ldr r0, [pc, #0x204] */
/* @0x21b69c mov r8, #0 */
/* @0x21b6a0 cmp r2, r1 */
/* @0x21b6a4 ldr r2, [r5, r3] */
/* @0x21b6a8 str lr, [r4, #0x24] */
/* @0x21b6ac str r7, [r4, #0x18] */
/* @0x21b6b0 ldr r3, [r2] */
/* @0x21b6b4 str r1, [r4, #0x2c] */
/* @0x21b6b8 add r12, r3, #1 */
/* @0x21b6bc str r12, [r2] */
/* @0x21b6c0 str r3, [r4, #0x14] */
/* @0x21b6c4 ldr r3, [r5, r0] */
/* @0x21b6c8 vstr s16, [r4, #28] */
/* @0x21b6cc strble r1, [r4, #0x4] */
/* @0x21b6d0 movw r1, #0x1023 */
/* @0x21b6d4 ldr r7, [r4, #0x10] */
/* @0x21b6d8 ldr r3, [r3] */
/* @0x21b6dc ldr r2, [r6] */
/* @0x21b6e0 str r3, [r4, #0x34] */
/* @0x21b6e4 movgt r3, #1 */
/* @0x21b6e8 strbgt r3, [r4, #0x4] */
/* @0x21b6ec ldr r3, [pc, #0x1b4] */
/* @0x21b6f0 ldr r0, [r2, r7, lsl #2] */
/* @0x21b6f4 ldr r3, [r5, r3] */
/* @0x21b6f8 ldr r2, [r3] */
/* @0x21b6fc bl 0xb6a78 <alSourcef@plt> */
/* @0x21b700 ldr r3, [r6] */
/* @0x21b704 movw r1, #0x100a */
/* @0x21b708 ldr r2, [r9, #0x4] */
/* @0x21b70c ldr r0, [r3, r7, lsl #2] */
/* @0x21b710 bl 0xb6a78 <alSourcef@plt> */
/* @0x21b714 ldr r3, [r6] */
/* @0x21b718 movw r1, #0x1003 */
/* @0x21b71c ldr r2, [r9, #0x8] */
/* @0x21b720 ldr r0, [r3, r7, lsl #2] */
/* @0x21b724 bl 0xb6a78 <alSourcef@plt> */
/* @0x21b728 ldr r3, [r6] */
/* @0x21b72c movw r1, #0x202 */
/* @0x21b730 mov r2, #1 */
/* @0x21b734 ldr r0, [r3, r7, lsl #2] */
/* @0x21b738 bl 0xb6a6c <alSourcei@plt> */
/* @0x21b73c ldr r0, [r6] */
/* @0x21b740 mov r2, r8 */
/* @0x21b744 movw r1, #0x1004 */
/* @0x21b748 mov r3, r8 */
/* @0x21b74c ldr r0, [r0, r7, lsl #2] */
/* @0x21b750 str r8, [sp] */
/* @0x21b754 bl 0xb6b2c <alSource3f@plt> */
/* @0x21b758 ldr r3, [r6] */
/* @0x21b75c mov r2, r8 */
/* @0x21b760 movw r1, #0x1006 */
/* @0x21b764 ldr r0, [r3, r7, lsl #2] */
/* @0x21b768 mov r3, r8 */
/* @0x21b76c str r8, [sp] */
/* @0x21b770 bl 0xb6b2c <alSource3f@plt> */
/* @0x21b774 mov r1, r4 */
/* @0x21b778 mov r0, r9 */
/* @0x21b77c bl 0x2173d8 <_Z21Audio_StartSoundNoiseP12cAudio_SoundP6CNoise> */
/* @0x21b780 bl 0xb6a54 <alGetError@plt> */
/* @0x21b784 subs r2, r0, #0 */
/* @0x21b788 bne 0x21b7e4 <_Z15Audio_PlaySoundidi+0x20c> */
/* @0x21b78c ldr r0, [r4, #0x14] */
/* @0x21b790 add sp, sp, #20 */
/* @0x21b794 vpop {d8} */
/* @0x21b798 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x21b79c ldr r3, [pc, #0xf8] */
/* @0x21b7a0 add r2, sp, #16 */
/* @0x21b7a4 movw r1, #0x1011 */
/* @0x21b7a8 ldr r0, [r0, #0x10] */
/* @0x21b7ac str r1, [r2, #-0x4]! */
/* @0x21b7b0 movw r1, #0x1010 */
/* @0x21b7b4 ldr r6, [r5, r3] */
/* @0x21b7b8 ldr r3, [r6] */
/* @0x21b7bc ldr r0, [r3, r0, lsl #2] */
/* @0x21b7c0 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x21b7c4 ldr r2, [sp, #0xc] */
/* @0x21b7c8 movw r3, #0x1012 */
/* @0x21b7cc cmp r2, r3 */
/* @0x21b7d0 bne 0x21b67c <_Z15Audio_PlaySoundidi+0xa4> */
/* @0x21b7d4 mvn r0, #0 */
/* @0x21b7d8 add sp, sp, #20 */
/* @0x21b7dc vpop {d8} */
/* @0x21b7e0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x21b7e4 ldr r3, [pc, #0xc0] */
/* @0x21b7e8 ldr r1, [pc, #0xc0] */
/* @0x21b7ec ldr r3, [r5, r3] */
/* @0x21b7f0 add r1, pc, r1 */
/* @0x21b7f4 ldr r0, [r3] */
/* @0x21b7f8 ldr r3, [r0] */
/* @0x21b7fc ldr r3, [r3, #0xc] */
/* @0x21b800 blx r3 */
/* @0x21b804 b 0x21b78c <_Z15Audio_PlaySoundidi+0x1b4> */
/* @0x21b808 ldr r3, [pc, #0x9c] */
/* @0x21b80c ldr r1, [pc, #0xa0] */
/* @0x21b810 ldr r3, [r5, r3] */
/* @0x21b814 add r1, pc, r1 */
/* @0x21b818 ldr r0, [r3] */
/* @0x21b81c ldr r3, [r0] */
/* @0x21b820 ldr r3, [r3, #0xc] */
/* @0x21b824 blx r3 */
/* @0x21b828 b 0x21b688 <_Z15Audio_PlaySoundidi+0xb0> */
/* @0x21b82c ldr r3, [pc, #0x78] */
/* @0x21b830 ldr r1, [pc, #0x80] */
/* @0x21b834 ldr r3, [r5, r3] */
/* @0x21b838 add r1, pc, r1 */
/* @0x21b83c ldr r0, [r3] */
/* @0x21b840 ldr r3, [r0] */
/* @0x21b844 ldr r3, [r3, #0xc] */
/* @0x21b848 blx r3 */
/* @0x21b84c mov r0, r9 */
/* @0x21b850 b 0x21b790 <_Z15Audio_PlaySoundidi+0x1b8> */
/* @0x21b854 ldr r3, [pc, #0x50] */
/* @0x21b858 mov r0, r7 */
/* @0x21b85c ldr r3, [r5, r3] */
/* @0x21b860 ldr r4, [r3] */
/* @0x21b864 ldr r3, [r4] */
/* @0x21b868 ldr r5, [r3, #0xc] */
/* @0x21b86c bl 0x218348 <_Z13Audio_GetNamei> */
/* @0x21b870 ldr r1, [pc, #0x44] */
/* @0x21b874 ldr r3, [r9, #0x4c] */
/* @0x21b878 add r1, pc, r1 */
/* @0x21b87c mov r2, r0 */
/* @0x21b880 mov r0, r4 */
/* @0x21b884 blx r5 */
/* @0x21b888 b 0x21b7d4 <_Z15Audio_PlaySoundidi+0x1fc> */
/* @0x21b88c andseq r6, sp, r12, asr r6 */
/* @0x21b890 .word 0xffffd3fc */
/* @0x21b894 .word 0xffffd0e0 */
/* @0x21b898 .word 0xffffd400 */
/* @0x21b89c .word 0xfffff77c */
/* @0x21b8a0 .word 0xfffff7a0 */
/* @0x21b8a4 .word 0xfffff778 */
/* @0x21b8a8 .word 0xfffff7a4 */
/* @0x21b8ac .word 0xffffbac4 */
/* @0x21b8b0 andseq r8, r3, r0, lsl #18 */
/* @0x21b8b4 ldrheq r8, [r3], -r12 */
/* @0x21b8b8 ldrsheq r8, [r3], -r4 */
/* @0x21b8bc ldrsbeq r8, [r3], -r12 */

/* ── FUNC 0x21b8c0 · Audio_PlaySoundOn(int, int, int, double) · size=880 · insn=220 */
/* @0x21b8c0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x21b8c4 vpush {d8} */
/* @0x21b8c8 mov r6, r0 */
/* @0x21b8cc ldr r5, [pc, #0x324] */
/* @0x21b8d0 sub sp, sp, #8 */
/* @0x21b8d4 ldr r3, [pc, #0x320] */
/* @0x21b8d8 mov r7, r1 */
/* @0x21b8dc add r5, pc, r5 */
/* @0x21b8e0 mov r10, r2 */
/* @0x21b8e4 ldr r3, [r5, r3] */
/* @0x21b8e8 ldrb r3, [r3] */
/* @0x21b8ec cmp r3, #0 */
/* @0x21b8f0 bne 0x21bb98 <_Z17Audio_PlaySoundOniiid+0x2d8> */
/* @0x21b8f4 ldr r3, [pc, #0x304] */
/* @0x21b8f8 ldr r3, [r5, r3] */
/* @0x21b8fc ldrb r3, [r3] */
/* @0x21b900 cmp r3, #0 */
/* @0x21b904 beq 0x21bb98 <_Z17Audio_PlaySoundOniiid+0x2d8> */
/* @0x21b908 bl 0xb6a54 <alGetError@plt> */
/* @0x21b90c subs r2, r0, #0 */
/* @0x21b910 bne 0x21bb50 <_Z17Audio_PlaySoundOniiid+0x290> */
/* @0x21b914 ldr r3, [pc, #0x2e8] */
/* @0x21b918 lsr r8, r6, #31 */
/* @0x21b91c add r3, pc, r3 */
/* @0x21b920 ldr r2, [r3, #0x40] */
/* @0x21b924 cmp r2, r6 */
/* @0x21b928 orrle r8, r8, #1 */
/* @0x21b92c cmp r8, #0 */
/* @0x21b930 bne 0x21bb98 <_Z17Audio_PlaySoundOniiid+0x2d8> */
/* @0x21b934 ldr r3, [r3, #0x44] */
/* @0x21b938 ldr r4, [r3, r6, lsl #2] */
/* @0x21b93c cmp r4, #0 */
/* @0x21b940 beq 0x21bb74 <_Z17Audio_PlaySoundOniiid+0x2b4> */
/* @0x21b944 ldrb r3, [r4, #0x18] */
/* @0x21b948 cmp r3, #0 */
/* @0x21b94c beq 0x21bb74 <_Z17Audio_PlaySoundOniiid+0x2b4> */
/* @0x21b950 mov r0, r7 */
/* @0x21b954 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21b958 subs r9, r0, #0 */
/* @0x21b95c beq 0x21bbcc <_Z17Audio_PlaySoundOniiid+0x30c> */
/* @0x21b960 ldr r3, [pc, #0x2a0] */
/* @0x21b964 ldr r1, [r9, #0x4c] */
/* @0x21b968 ldr r0, [r5, r3] */
/* @0x21b96c bl 0x21e1e0 <_ZN14CAudioGroupMan13IsGroupLoadedEi> */
/* @0x21b970 subs r6, r0, #0 */
/* @0x21b974 beq 0x21bb0c <_Z17Audio_PlaySoundOniiid+0x24c> */
/* @0x21b978 vldr d7, [sp, #48] */
/* @0x21b97c vcvt.f32.f64 s16, d7 */
/* @0x21b980 mov r0, r7 */
/* @0x21b984 vmov r1, s16 */
/* @0x21b988 bl 0x21addc <_Z26Audio_GetSoundSourceToPlayif> */
/* @0x21b98c subs r6, r0, #0 */
/* @0x21b990 beq 0x21bb98 <_Z17Audio_PlaySoundOniiid+0x2d8> */
/* @0x21b994 ldr r3, [pc, #0x270] */
/* @0x21b998 cmp r10, #0 */
/* @0x21b99c vldr s17, [r9, #4] */
/* @0x21b9a0 mov lr, #1065353216 */
/* @0x21b9a4 movle r10, #0 */
/* @0x21b9a8 movgt r10, #1 */
/* @0x21b9ac ldr r2, [r5, r3] */
/* @0x21b9b0 mov r0, r4 */
/* @0x21b9b4 mov r1, r6 */
/* @0x21b9b8 str r7, [r6, #0x18] */
/* @0x21b9bc str lr, [r6, #0x24] */
/* @0x21b9c0 vstr s16, [r6, #28] */
/* @0x21b9c4 ldr r3, [r2] */
/* @0x21b9c8 strb r10, [r6, #0x4] */
/* @0x21b9cc str r8, [r6, #0x2c] */
/* @0x21b9d0 add r12, r3, #1 */
/* @0x21b9d4 str r3, [r6, #0x14] */
/* @0x21b9d8 str r12, [r2] */
/* @0x21b9dc bl 0x215944 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise> */
/* @0x21b9e0 ldr r7, [r6, #0x10] */
/* @0x21b9e4 bl 0xb6a54 <alGetError@plt> */
/* @0x21b9e8 subs r2, r0, #0 */
/* @0x21b9ec bne 0x21bba8 <_Z17Audio_PlaySoundOniiid+0x2e8> */
/* @0x21b9f0 ldr r3, [pc, #0x218] */
/* @0x21b9f4 movw r1, #0x202 */
/* @0x21b9f8 mov r2, #0 */
/* @0x21b9fc ldr r8, [r5, r3] */
/* @0x21ba00 ldr r3, [r8] */
/* @0x21ba04 ldr r0, [r3, r7, lsl #2] */
/* @0x21ba08 bl 0xb6a6c <alSourcei@plt> */
/* @0x21ba0c ldr r3, [r8] */
/* @0x21ba10 movw r1, #0x1023 */
/* @0x21ba14 ldr r2, [r4, #0x20] */
/* @0x21ba18 ldr r0, [r3, r7, lsl #2] */
/* @0x21ba1c bl 0xb6a78 <alSourcef@plt> */
/* @0x21ba20 vldr s15, [r4, #40] */
/* @0x21ba24 vmul.f32 s15, s17, s15 */
/* @0x21ba28 ldr r3, [r8] */
/* @0x21ba2c movw r1, #0x100a */
/* @0x21ba30 ldr r0, [r3, r7, lsl #2] */
/* @0x21ba34 vmov r2, s15 */
/* @0x21ba38 bl 0xb6a78 <alSourcef@plt> */
/* @0x21ba3c vldr s14, [r9, #8] */
/* @0x21ba40 vldr s15, [r4, #44] */
/* @0x21ba44 vmul.f32 s15, s15, s14 */
/* @0x21ba48 ldr r3, [r8] */
/* @0x21ba4c movw r1, #0x1003 */
/* @0x21ba50 ldr r0, [r3, r7, lsl #2] */
/* @0x21ba54 vmov r2, s15 */
/* @0x21ba58 bl 0xb6a78 <alSourcef@plt> */
/* @0x21ba5c ldr r3, [r8] */
/* @0x21ba60 movw r1, #0x1020 */
/* @0x21ba64 ldr r2, [r4, #0x1c] */
/* @0x21ba68 ldr r0, [r3, r7, lsl #2] */
/* @0x21ba6c bl 0xb6a78 <alSourcef@plt> */
/* @0x21ba70 ldr r3, [r8] */
/* @0x21ba74 movw r1, #0x1021 */
/* @0x21ba78 ldr r2, [r4, #0x24] */
/* @0x21ba7c ldr r0, [r3, r7, lsl #2] */
/* @0x21ba80 bl 0xb6a78 <alSourcef@plt> */
/* @0x21ba84 ldr r1, [r8] */
/* @0x21ba88 ldr r12, [r4, #0x8] */
/* @0x21ba8c ldr r2, [r4] */
/* @0x21ba90 ldr r0, [r1, r7, lsl #2] */
/* @0x21ba94 movw r1, #0x1004 */
/* @0x21ba98 ldr r3, [r4, #0x4] */
/* @0x21ba9c str r12, [sp] */
/* @0x21baa0 bl 0xb6b2c <alSource3f@plt> */
/* @0x21baa4 ldr r1, [r8] */
/* @0x21baa8 ldr r12, [r4, #0x14] */
/* @0x21baac ldr r2, [r4, #0xc] */
/* @0x21bab0 ldr r3, [r4, #0x10] */
/* @0x21bab4 ldr r0, [r1, r7, lsl #2] */
/* @0x21bab8 movw r1, #0x1006 */
/* @0x21babc str r12, [sp] */
/* @0x21bac0 bl 0xb6b2c <alSource3f@plt> */
/* @0x21bac4 mov r1, r6 */
/* @0x21bac8 mov r0, r9 */
/* @0x21bacc bl 0x2173d8 <_Z21Audio_StartSoundNoiseP12cAudio_SoundP6CNoise> */
/* @0x21bad0 bl 0xb6a54 <alGetError@plt> */
/* @0x21bad4 subs r2, r0, #0 */
/* @0x21bad8 beq 0x21bafc <_Z17Audio_PlaySoundOniiid+0x23c> */
/* @0x21badc ldr r3, [pc, #0x130] */
/* @0x21bae0 ldr r1, [pc, #0x130] */
/* @0x21bae4 ldr r3, [r5, r3] */
/* @0x21bae8 add r1, pc, r1 */
/* @0x21baec ldr r0, [r3] */
/* @0x21baf0 ldr r3, [r0] */
/* @0x21baf4 ldr r3, [r3, #0xc] */
/* @0x21baf8 blx r3 */
/* @0x21bafc ldr r0, [r6, #0x14] */
/* @0x21bb00 add sp, sp, #8 */
/* @0x21bb04 vpop {d8} */
/* @0x21bb08 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21bb0c ldr r3, [pc, #0x100] */
/* @0x21bb10 mov r0, r7 */
/* @0x21bb14 ldr r3, [r5, r3] */
/* @0x21bb18 ldr r4, [r3] */
/* @0x21bb1c ldr r3, [r4] */
/* @0x21bb20 ldr r5, [r3, #0xc] */
/* @0x21bb24 bl 0x218348 <_Z13Audio_GetNamei> */
/* @0x21bb28 ldr r1, [pc, #0xec] */
/* @0x21bb2c ldr r3, [r9, #0x4c] */
/* @0x21bb30 add r1, pc, r1 */
/* @0x21bb34 mov r2, r0 */
/* @0x21bb38 mov r0, r4 */
/* @0x21bb3c blx r5 */
/* @0x21bb40 mov r0, r6 */
/* @0x21bb44 add sp, sp, #8 */
/* @0x21bb48 vpop {d8} */
/* @0x21bb4c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21bb50 ldr r3, [pc, #0xbc] */
/* @0x21bb54 ldr r1, [pc, #0xc4] */
/* @0x21bb58 ldr r3, [r5, r3] */
/* @0x21bb5c add r1, pc, r1 */
/* @0x21bb60 ldr r0, [r3] */
/* @0x21bb64 ldr r3, [r0] */
/* @0x21bb68 ldr r3, [r3, #0xc] */
/* @0x21bb6c blx r3 */
/* @0x21bb70 b 0x21b914 <_Z17Audio_PlaySoundOniiid+0x54> */
/* @0x21bb74 ldr r3, [pc, #0x98] */
/* @0x21bb78 mov r2, r6 */
/* @0x21bb7c ldr r1, [pc, #0xa0] */
/* @0x21bb80 ldr r3, [r5, r3] */
/* @0x21bb84 add r1, pc, r1 */
/* @0x21bb88 ldr r0, [r3] */
/* @0x21bb8c ldr r3, [r0] */
/* @0x21bb90 ldr r3, [r3, #0xc] */
/* @0x21bb94 blx r3 */
/* @0x21bb98 mvn r0, #0 */
/* @0x21bb9c add sp, sp, #8 */
/* @0x21bba0 vpop {d8} */
/* @0x21bba4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21bba8 ldr r3, [pc, #0x64] */
/* @0x21bbac ldr r1, [pc, #0x74] */
/* @0x21bbb0 ldr r3, [r5, r3] */
/* @0x21bbb4 add r1, pc, r1 */
/* @0x21bbb8 ldr r0, [r3] */
/* @0x21bbbc ldr r3, [r0] */
/* @0x21bbc0 ldr r3, [r3, #0xc] */
/* @0x21bbc4 blx r3 */
/* @0x21bbc8 b 0x21b9f0 <_Z17Audio_PlaySoundOniiid+0x130> */
/* @0x21bbcc ldr r3, [pc, #0x40] */
/* @0x21bbd0 mov r2, r7 */
/* @0x21bbd4 ldr r1, [pc, #0x50] */
/* @0x21bbd8 ldr r3, [r5, r3] */
/* @0x21bbdc add r1, pc, r1 */
/* @0x21bbe0 ldr r0, [r3] */
/* @0x21bbe4 ldr r3, [r0] */
/* @0x21bbe8 ldr r3, [r3, #0xc] */
/* @0x21bbec blx r3 */
/* @0x21bbf0 mov r0, r9 */
/* @0x21bbf4 b 0x21bb00 <_Z17Audio_PlaySoundOniiid+0x240> */
/* @0x21bbf8 andseq r6, sp, r4, ror r3 */
/* @0x21bbfc .word 0xffffd3fc */
/* @0x21bc00 .word 0xffffd0e0 */
/* @0x21bc04 subseq r9, r3, r8, ror r9 */
/* @0x21bc08 .word 0xffffd400 */
/* @0x21bc0c .word 0xfffff7a0 */
/* @0x21bc10 .word 0xfffff77c */
/* @0x21bc14 .word 0xffffbac4 */
/* @0x21bc18 andseq r8, r3, r0, ror r6 */
/* @0x21bc1c andseq r8, r3, r4, lsr #10 */
/* @0x21bc20 ldrheq r8, [r3], -r4 */
/* @0x21bc24 ldrsheq r8, [r3], -r0 */
/* @0x21bc28 andseq r8, r3, r0, lsl #11 */
/* @0x21bc2c andseq r8, r3, r0, asr r4 */

/* ── FUNC 0x21bc30 · Audio_Tick() · size=1520 · insn=380 */
/* @0x21bc30 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21bc34 vpush {d8} */
/* @0x21bc38 sub sp, sp, #84 */
/* @0x21bc3c ldr r9, [pc, #0x580] */
/* @0x21bc40 ldr r3, [pc, #0x580] */
/* @0x21bc44 add r9, pc, r9 */
/* @0x21bc48 ldr r3, [r9, r3] */
/* @0x21bc4c ldrb r3, [r3] */
/* @0x21bc50 cmp r3, #0 */
/* @0x21bc54 beq 0x21bc6c <_Z10Audio_Tickv+0x3c> */
/* @0x21bc58 ldr r3, [pc, #0x56c] */
/* @0x21bc5c ldr r3, [r9, r3] */
/* @0x21bc60 ldrb r3, [r3] */
/* @0x21bc64 cmp r3, #0 */
/* @0x21bc68 beq 0x21bc78 <_Z10Audio_Tickv+0x48> */
/* @0x21bc6c add sp, sp, #84 */
/* @0x21bc70 vpop {d8} */
/* @0x21bc74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21bc78 ldr r3, [pc, #0x550] */
/* @0x21bc7c ldr r0, [r9, r3] */
/* @0x21bc80 bl 0x21e268 <_ZN14CAudioGroupMan6UpdateEv> */
/* @0x21bc84 ldr r3, [pc, #0x548] */
/* @0x21bc88 ldr r3, [r9, r3] */
/* @0x21bc8c ldr r0, [r3] */
/* @0x21bc90 cmp r0, #0 */
/* @0x21bc94 beq 0x21bc9c <_Z10Audio_Tickv+0x6c> */
/* @0x21bc98 bl 0x215b48 <_ZN9CListener6UpdateEv> */
/* @0x21bc9c ldr r0, [pc, #0x534] */
/* @0x21bca0 add r2, sp, #64 */
/* @0x21bca4 str r2, [sp, #0x3c] */
/* @0x21bca8 mov r4, #0 */
/* @0x21bcac add r0, pc, r0 */
/* @0x21bcb0 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x21bcb4 ldr r0, [pc, #0x520] */
/* @0x21bcb8 add r0, pc, r0 */
/* @0x21bcbc add r1, r0, #56 */
/* @0x21bcc0 bl 0x226590 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE> */
/* @0x21bcc4 vmov.f32 s13, #1.000000e+00 */
/* @0x21bcc8 ldr r3, [pc, #0x510] */
/* @0x21bccc add r12, sp, #64 */
/* @0x21bcd0 add lr, sp, #76 */
/* @0x21bcd4 add r3, pc, r3 */
/* @0x21bcd8 ldm r3, {r0, r1, r2} */
/* @0x21bcdc add r3, sp, #80 */
/* @0x21bce0 stmdb r3, {r0, r1, r2} */
/* @0x21bce4 ldr r3, [r12, #0x4]! */
/* @0x21bce8 ldr r0, [r3] */
/* @0x21bcec cmp r0, #0 */
/* @0x21bcf0 ble 0x21bd50 <_Z10Audio_Tickv+0x120> */
/* @0x21bcf4 ldr r1, [r3, #0x4] */
/* @0x21bcf8 add r0, r1, r0, lsl #2 */
/* @0x21bcfc ldr r3, [r1], #4 */
/* @0x21bd00 cmp r3, #0 */
/* @0x21bd04 beq 0x21bd48 <_Z10Audio_Tickv+0x118> */
/* @0x21bd08 ldr r2, [r3, #0x20] */
/* @0x21bd0c cmp r2, #0 */
/* @0x21bd10 ble 0x21bd48 <_Z10Audio_Tickv+0x118> */
/* @0x21bd14 vldr s14, [r3, #4] */
/* @0x21bd18 vldr s15, [r3, #28] */
/* @0x21bd1c vadd.f32 s15, s14, s15 */
/* @0x21bd20 vcmpe.f32 s15, #0 */
/* @0x21bd24 vmrs APSR_nzcv, fpscr */
/* @0x21bd28 strmi r4, [r3, #0x4] */
/* @0x21bd2c bmi 0x21bd40 <_Z10Audio_Tickv+0x110> */
/* @0x21bd30 vcmpe.f32 s15, s13 */
/* @0x21bd34 vmrs APSR_nzcv, fpscr */
/* @0x21bd38 vmovgt.f32 s15, s13 */
/* @0x21bd3c vstr s15, [r3, #4] */
/* @0x21bd40 sub r2, r2, #1 */
/* @0x21bd44 str r2, [r3, #0x20] */
/* @0x21bd48 cmp r1, r0 */
/* @0x21bd4c bne 0x21bcfc <_Z10Audio_Tickv+0xcc> */
/* @0x21bd50 cmp r12, lr */
/* @0x21bd54 bne 0x21bce4 <_Z10Audio_Tickv+0xb4> */
/* @0x21bd58 ldr r3, [pc, #0x484] */
/* @0x21bd5c add r3, pc, r3 */
/* @0x21bd60 ldr r6, [r3, #0x38] */
/* @0x21bd64 cmp r6, #0 */
/* @0x21bd68 ble 0x21be78 <_Z10Audio_Tickv+0x248> */
/* @0x21bd6c ldr r8, [pc, #0x474] */
/* @0x21bd70 mov r4, #0 */
/* @0x21bd74 ldr r7, [pc, #0x470] */
/* @0x21bd78 vmov.f32 s16, #1.000000e+00 */
/* @0x21bd7c add r8, pc, r8 */
/* @0x21bd80 mov r10, r4 */
/* @0x21bd84 add r7, pc, r7 */
/* @0x21bd88 mov r3, r6 */
/* @0x21bd8c mov r11, #0 */
/* @0x21bd90 b 0x21bdbc <_Z10Audio_Tickv+0x18c> */
/* @0x21bd94 add r3, r3, #1 */
/* @0x21bd98 str r3, [r5, #0x8] */
/* @0x21bd9c cmp r3, #3 */
/* @0x21bda0 strgt r10, [r5, #0x8] */
/* @0x21bda4 bgt 0x21bdac <_Z10Audio_Tickv+0x17c> */
/* @0x21bda8 beq 0x21c1b0 <_Z10Audio_Tickv+0x580> */
/* @0x21bdac add r4, r4, #1 */
/* @0x21bdb0 cmp r4, r6 */
/* @0x21bdb4 beq 0x21be78 <_Z10Audio_Tickv+0x248> */
/* @0x21bdb8 ldr r3, [r7, #0x38] */
/* @0x21bdbc cmp r3, r4 */
/* @0x21bdc0 ldrgt r3, [r8, #0x3c] */
/* @0x21bdc4 movle r5, #0 */
/* @0x21bdc8 ldrgt r5, [r3, r4, lsl #2] */
/* @0x21bdcc ldrb r3, [r5, #0x5] */
/* @0x21bdd0 cmp r3, #0 */
/* @0x21bdd4 beq 0x21bdac <_Z10Audio_Tickv+0x17c> */
/* @0x21bdd8 ldr r3, [r5, #0x8] */
/* @0x21bddc cmp r3, #0 */
/* @0x21bde0 bne 0x21bd94 <_Z10Audio_Tickv+0x164> */
/* @0x21bde4 ldr r3, [r5, #0x2c] */
/* @0x21bde8 cmp r3, #0 */
/* @0x21bdec ble 0x21be24 <_Z10Audio_Tickv+0x1f4> */
/* @0x21bdf0 vldr s14, [r5, #36] */
/* @0x21bdf4 vldr s15, [r5, #40] */
/* @0x21bdf8 vadd.f32 s15, s14, s15 */
/* @0x21bdfc vcmpe.f32 s15, #0 */
/* @0x21be00 vmrs APSR_nzcv, fpscr */
/* @0x21be04 strmi r11, [r5, #0x24] */
/* @0x21be08 bmi 0x21be1c <_Z10Audio_Tickv+0x1ec> */
/* @0x21be0c vcmpe.f32 s15, s16 */
/* @0x21be10 vmrs APSR_nzcv, fpscr */
/* @0x21be14 vmovgt.f32 s15, s16 */
/* @0x21be18 vstr s15, [r5, #36] */
/* @0x21be1c sub r3, r3, #1 */
/* @0x21be20 str r3, [r5, #0x2c] */
/* @0x21be24 ldr r3, [r5, #0x10] */
/* @0x21be28 cmp r3, #0 */
/* @0x21be2c blt 0x21bdac <_Z10Audio_Tickv+0x17c> */
/* @0x21be30 ldr r0, [r5, #0x18] */
/* @0x21be34 bl 0x217060 <_Z24Audio_GetGainFromSoundIDi> */
/* @0x21be38 vldr s15, [r5, #36] */
/* @0x21be3c ldr r3, [r5, #0x38] */
/* @0x21be40 movw r1, #0x100a */
/* @0x21be44 cmp r3, #0 */
/* @0x21be48 vldrne s14, [r3, #40] */
/* @0x21be4c ldr r3, [pc, #0x39c] */
/* @0x21be50 ldr r3, [r9, r3] */
/* @0x21be54 ldr r3, [r3] */
/* @0x21be58 vmov s11, r0 */
/* @0x21be5c ldr r0, [r5, #0x10] */
/* @0x21be60 vmul.f32 s15, s11, s15 */
/* @0x21be64 ldr r0, [r3, r0, lsl #2] */
/* @0x21be68 vmulne.f32 s15, s15, s14 */
/* @0x21be6c vmov r2, s15 */
/* @0x21be70 bl 0xb6a78 <alSourcef@plt> */
/* @0x21be74 b 0x21bdac <_Z10Audio_Tickv+0x17c> */
/* @0x21be78 ldr r3, [pc, #0x374] */
/* @0x21be7c add r3, pc, r3 */
/* @0x21be80 ldr r10, [r3, #0x40] */
/* @0x21be84 cmp r10, #0 */
/* @0x21be88 ble 0x21bfe4 <_Z10Audio_Tickv+0x3b4> */
/* @0x21be8c ldr r2, [pc, #0x364] */
/* @0x21be90 mov r3, r10 */
/* @0x21be94 ldr lr, [pc, #0x360] */
/* @0x21be98 mov r7, #0 */
/* @0x21be9c add r2, pc, r2 */
/* @0x21bea0 str r2, [sp, #0x34] */
/* @0x21bea4 ldr r2, [pc, #0x354] */
/* @0x21bea8 add lr, pc, lr */
/* @0x21beac str lr, [sp, #0x38] */
/* @0x21beb0 add r2, pc, r2 */
/* @0x21beb4 str r2, [sp, #0x30] */
/* @0x21beb8 cmp r7, r3 */
/* @0x21bebc bge 0x21bfd0 <_Z10Audio_Tickv+0x3a0> */
/* @0x21bec0 ldr lr, [sp, #0x34] */
/* @0x21bec4 ldr r3, [lr, #0x44] */
/* @0x21bec8 ldr r6, [r3, r7, lsl #2] */
/* @0x21becc cmp r6, #0 */
/* @0x21bed0 beq 0x21bfd0 <_Z10Audio_Tickv+0x3a0> */
/* @0x21bed4 ldrb r3, [r6, #0x18] */
/* @0x21bed8 cmp r3, #0 */
/* @0x21bedc beq 0x21bfd0 <_Z10Audio_Tickv+0x3a0> */
/* @0x21bee0 ldr r8, [r6, #0x34] */
/* @0x21bee4 cmp r8, #0 */
/* @0x21bee8 ble 0x21bfd0 <_Z10Audio_Tickv+0x3a0> */
/* @0x21beec mov r3, r8 */
/* @0x21bef0 mov r4, #0 */
/* @0x21bef4 b 0x21bf20 <_Z10Audio_Tickv+0x2f0> */
/* @0x21bef8 ldr r3, [r6, #0x38] */
/* @0x21befc strb r0, [r5, #0x5] */
/* @0x21bf00 str r0, [r5, #0x8] */
/* @0x21bf04 strb r0, [r5, #0xd] */
/* @0x21bf08 str r0, [r5, #0x38] */
/* @0x21bf0c str r0, [r3, r11] */
/* @0x21bf10 add r4, r4, #1 */
/* @0x21bf14 cmp r4, r8 */
/* @0x21bf18 beq 0x21bfd0 <_Z10Audio_Tickv+0x3a0> */
/* @0x21bf1c ldr r3, [r6, #0x34] */
/* @0x21bf20 cmp r3, r4 */
/* @0x21bf24 lsl r11, r4, #2 */
/* @0x21bf28 ble 0x21bf10 <_Z10Audio_Tickv+0x2e0> */
/* @0x21bf2c ldr r3, [r6, #0x38] */
/* @0x21bf30 ldr r5, [r3, r4, lsl #2] */
/* @0x21bf34 cmp r5, #0 */
/* @0x21bf38 mov r0, r5 */
/* @0x21bf3c beq 0x21bf10 <_Z10Audio_Tickv+0x2e0> */
/* @0x21bf40 bl 0x2164bc <_Z20Audio_NoiseIsPlayingP6CNoise> */
/* @0x21bf44 cmp r0, #0 */
/* @0x21bf48 beq 0x21bef8 <_Z10Audio_Tickv+0x2c8> */
/* @0x21bf4c ldr r1, [pc, #0x29c] */
/* @0x21bf50 ldr r12, [r5, #0x10] */
/* @0x21bf54 ldr lr, [r6, #0x8] */
/* @0x21bf58 ldr r11, [r9, r1] */
/* @0x21bf5c movw r1, #0x1004 */
/* @0x21bf60 ldr r2, [r6] */
/* @0x21bf64 ldr r3, [r6, #0x4] */
/* @0x21bf68 ldr r0, [r11] */
/* @0x21bf6c ldr r0, [r0, r12, lsl #2] */
/* @0x21bf70 str lr, [sp] */
/* @0x21bf74 bl 0xb6b2c <alSource3f@plt> */
/* @0x21bf78 ldr r1, [r11] */
/* @0x21bf7c ldr r0, [r5, #0x10] */
/* @0x21bf80 ldr r12, [r6, #0x14] */
/* @0x21bf84 ldr r2, [r6, #0xc] */
/* @0x21bf88 ldr r0, [r1, r0, lsl #2] */
/* @0x21bf8c movw r1, #0x1006 */
/* @0x21bf90 ldr r3, [r6, #0x10] */
/* @0x21bf94 str r12, [sp] */
/* @0x21bf98 bl 0xb6b2c <alSource3f@plt> */
/* @0x21bf9c bl 0xb6a54 <alGetError@plt> */
/* @0x21bfa0 subs r2, r0, #0 */
/* @0x21bfa4 beq 0x21bf10 <_Z10Audio_Tickv+0x2e0> */
/* @0x21bfa8 ldr r3, [pc, #0x254] */
/* @0x21bfac add r4, r4, #1 */
/* @0x21bfb0 ldr r1, [sp, #0x38] */
/* @0x21bfb4 ldr r3, [r9, r3] */
/* @0x21bfb8 ldr r0, [r3] */
/* @0x21bfbc ldr r3, [r0] */
/* @0x21bfc0 ldr r3, [r3, #0xc] */
/* @0x21bfc4 blx r3 */
/* @0x21bfc8 cmp r4, r8 */
/* @0x21bfcc bne 0x21bf1c <_Z10Audio_Tickv+0x2ec> */
/* @0x21bfd0 add r7, r7, #1 */
/* @0x21bfd4 cmp r7, r10 */
/* @0x21bfd8 ldrne r2, [sp, #0x30] */
/* @0x21bfdc ldrne r3, [r2, #0x40] */
/* @0x21bfe0 bne 0x21beb8 <_Z10Audio_Tickv+0x288> */
/* @0x21bfe4 ldr r10, [pc, #0x21c] */
/* @0x21bfe8 add r10, pc, r10 */
/* @0x21bfec ldr r3, [r10, #0x50] */
/* @0x21bff0 cmp r3, #0 */
/* @0x21bff4 ble 0x21c140 <_Z10Audio_Tickv+0x510> */
/* @0x21bff8 ldr r9, [pc, #0x20c] */
/* @0x21bffc mov r6, r10 */
/* @0x21c000 ldr r8, [pc, #0x208] */
/* @0x21c004 mov r4, #0 */
/* @0x21c008 ldr r7, [pc, #0x204] */
/* @0x21c00c add r9, pc, r9 */
/* @0x21c010 add r8, pc, r8 */
/* @0x21c014 vldr s16, [pc, #420] */
/* @0x21c018 add r7, pc, r7 */
/* @0x21c01c add r11, sp, #64 */
/* @0x21c020 b 0x21c034 <_Z10Audio_Tickv+0x404> */
/* @0x21c024 ldr r2, [r6, #0x50] */
/* @0x21c028 add r4, r4, #1 */
/* @0x21c02c cmp r2, r4 */
/* @0x21c030 ble 0x21c140 <_Z10Audio_Tickv+0x510> */
/* @0x21c034 ldr r3, [r10, #0x54] */
/* @0x21c038 ldr r5, [r3, r4, lsl #2] */
/* @0x21c03c cmp r5, #0 */
/* @0x21c040 beq 0x21c024 <_Z10Audio_Tickv+0x3f4> */
/* @0x21c044 ldrb r3, [r5, #0xc] */
/* @0x21c048 cmp r3, #0 */
/* @0x21c04c beq 0x21c024 <_Z10Audio_Tickv+0x3f4> */
/* @0x21c050 ldr r0, [r5, #0x10] */
/* @0x21c054 movw r1, #0x312 */
/* @0x21c058 mov r2, #1 */
/* @0x21c05c mov r3, r11 */
/* @0x21c060 mvn r12, #0 */
/* @0x21c064 str r12, [sp, #0x40] */
/* @0x21c068 bl 0xb6b38 <alcGetIntegerv@plt> */
/* @0x21c06c ldr r0, [sp, #0x40] */
/* @0x21c070 vldr s12, [r5] */
/* @0x21c074 vcvt.f32.s32 s15, s12 */
/* @0x21c078 vmov s11, r0 */
/* @0x21c07c vcvt.f32.s32 s14, s11 */
/* @0x21c080 vdiv.f32 s15, s14, s15 */
/* @0x21c084 vcmpe.f32 s15, s16 */
/* @0x21c088 vmrs APSR_nzcv, fpscr */
/* @0x21c08c ble 0x21c024 <_Z10Audio_Tickv+0x3f4> */
/* @0x21c090 mov r1, #3 */
/* @0x21c094 mov r2, #0 */
/* @0x21c098 lsl r0, r0, #1 */
/* @0x21c09c bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> */
/* @0x21c0a0 vmov s17, r0 */
/* @0x21c0a4 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x21c0a8 ldr r2, [sp, #0x40] */
/* @0x21c0ac mov r3, r0 */
/* @0x21c0b0 ldr r1, [r0, #0xc] */
/* @0x21c0b4 ldr r0, [r5, #0x10] */
/* @0x21c0b8 str r3, [sp, #0x2c] */
/* @0x21c0bc bl 0xb6b44 <alcCaptureSamples@plt> */
/* @0x21c0c0 ldr lr, [sp, #0x40] */
/* @0x21c0c4 mov r2, #0 */
/* @0x21c0c8 ldr r3, [sp, #0x2c] */
/* @0x21c0cc mov r0, #3 */
/* @0x21c0d0 vmov s11, lr */
/* @0x21c0d4 lsl r12, lr, #1 */
/* @0x21c0d8 ldr r1, [r3, #0x10] */
/* @0x21c0dc vcvt.f64.s32 d7, s11 */
/* @0x21c0e0 vmov s11, r4 */
/* @0x21c0e4 add r4, r4, #1 */
/* @0x21c0e8 cmp r12, r1 */
/* @0x21c0ec strle r12, [r3, #0x20] */
/* @0x21c0f0 strgt r1, [r3, #0x20] */
/* @0x21c0f4 mov r1, r9 */
/* @0x21c0f8 str r2, [sp] */
/* @0x21c0fc str r2, [sp, #0x10] */
/* @0x21c100 str r2, [sp, #0x20] */
/* @0x21c104 str r8, [sp, #0x4] */
/* @0x21c108 vcvt.f64.s32 d6, s11 */
/* @0x21c10c str r7, [sp, #0x14] */
/* @0x21c110 vadd.f64 d7, d7, d7 */
/* @0x21c114 vstr d6, [sp, #8] */
/* @0x21c118 vcvt.f64.s32 d6, s17 */
/* @0x21c11c vstr d7, [sp, #24] */
/* @0x21c120 vmov r2, r3, d6 */
/* @0x21c124 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x21c128 mov r2, #73 */
/* @0x21c12c vmov r1, s17 */
/* @0x21c130 bl 0x18da80 <_Z33CreateAsynEventWithDSMapAndBufferiii> */
/* @0x21c134 ldr r2, [r6, #0x50] */
/* @0x21c138 cmp r2, r4 */
/* @0x21c13c bgt 0x21c034 <_Z10Audio_Tickv+0x404> */
/* @0x21c140 ldr r6, [pc, #0xd0] */
/* @0x21c144 add r6, pc, r6 */
/* @0x21c148 ldr r3, [r6, #0x30] */
/* @0x21c14c cmp r3, #0 */
/* @0x21c150 movgt r4, #0 */
/* @0x21c154 movgt r7, r6 */
/* @0x21c158 ble 0x21c198 <_Z10Audio_Tickv+0x568> */
/* @0x21c15c ldr r3, [r6, #0x34] */
/* @0x21c160 add r5, r4, #199680 */
/* @0x21c164 add r5, r5, #320 */
/* @0x21c168 ldr r3, [r3, r4, lsl #2] */
/* @0x21c16c mov r0, r5 */
/* @0x21c170 add r4, r4, #1 */
/* @0x21c174 cmp r3, #0 */
/* @0x21c178 beq 0x21c18c <_Z10Audio_Tickv+0x55c> */
/* @0x21c17c bl 0x216560 <_Z31Audio_GetNoiseFromQueuedSoundIDi> */
/* @0x21c180 mov r1, r5 */
/* @0x21c184 mov r2, #0 */
/* @0x21c188 bl 0x219e68 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib> */
/* @0x21c18c ldr r3, [r7, #0x30] */
/* @0x21c190 cmp r3, r4 */
/* @0x21c194 bgt 0x21c15c <_Z10Audio_Tickv+0x52c> */
/* @0x21c198 ldr r0, [pc, #0x7c] */
/* @0x21c19c add r0, pc, r0 */
/* @0x21c1a0 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x21c1a4 add sp, sp, #84 */
/* @0x21c1a8 vpop {d8} */
/* @0x21c1ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21c1b0 mov r0, r5 */
/* @0x21c1b4 mov r1, #1 */
/* @0x21c1b8 bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb> */
/* @0x21c1bc b 0x21bdac <_Z10Audio_Tickv+0x17c> */
/* @0x21c1c0 stcllo p12, c12, [r12, #820] */
/* @0x21c1c4 andseq r6, sp, r12 */
/* @0x21c1c8 .word 0xffffd0e0 */
/* @0x21c1cc .word 0xfffff79c */
/* @0x21c1d0 .word 0xffffd400 */
/* @0x21c1d4 .word 0xfffff78c */
/* @0x21c1d8 andseq r8, r3, r12, lsl #10 */
/* @0x21c1dc ldrsbeq r9, [r3], #-92 */
/* @0x21c1e0 ldrsbeq r9, [sp], -r12 */
/* @0x21c1e4 subseq r9, r3, r8, lsr r5 */
/* @0x21c1e8 subseq r9, r3, r8, lsl r5 */
/* @0x21c1ec subseq r9, r3, r0, lsl r5 */
/* @0x21c1f0 .word 0xfffff77c */
/* @0x21c1f4 subseq r9, r3, r8, lsl r4 */
/* @0x21c1f8 ldrsheq r9, [r3], #-56 */
/* @0x21c1fc andseq r7, r3, r12, ror #26 */
/* @0x21c200 subseq r9, r3, r4, ror #7 */
/* @0x21c204 .word 0xffffbac4 */
/* @0x21c208 subseq r9, r3, r12, lsr #5 */
/* @0x21c20c ldrheq r7, [r3], -r8 */
/* @0x21c210 ldrheq r8, [r3], -r12 */
/* @0x21c214 andseq r8, r3, r4, asr #3 */
/* @0x21c218 subseq r9, r3, r0, asr r1 */
/* @0x21c21c andseq r8, r3, r12, asr #32 */

/* ── FUNC 0x21c220 · GetRecorder(int) · size=52 · insn=13 */
/* @0x21c220 cmp r0, #0 */
/* @0x21c224 blt 0x21c248 <_Z11GetRecorderi+0x28> */
/* @0x21c228 ldr r3, [pc, #0x20] */
/* @0x21c22c add r3, pc, r3 */
/* @0x21c230 ldr r2, [r3, #0x50] */
/* @0x21c234 cmp r0, r2 */
/* @0x21c238 bge 0x21c248 <_Z11GetRecorderi+0x28> */
/* @0x21c23c ldr r3, [r3, #0x54] */
/* @0x21c240 ldr r0, [r3, r0, lsl #2] */
/* @0x21c244 bx lr */
/* @0x21c248 mov r0, #0 */
/* @0x21c24c bx lr */
/* @0x21c250 subseq r9, r3, r8, rrx */
