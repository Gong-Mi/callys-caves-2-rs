/* libyoyo.so 覆盖卡组 0204
 * 函数 0x22609c..0x2280d0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x22609c · COggAudio::Suspend() · size=100 · insn=25 */
/* @0x22609c push {r4, r5, r6, lr} */
/* @0x2260a0 mov r6, r0 */
/* @0x2260a4 ldr r0, [r0] */
/* @0x2260a8 cmp r0, #0 */
/* @0x2260ac popeq {r4, r5, r6, pc} */
/* @0x2260b0 ldr r3, [pc, #0x44] */
/* @0x2260b4 mov r2, #1 */
/* @0x2260b8 ldr r1, [r6, #0x14] */
/* @0x2260bc ldr r3, [pc, r3] */
/* @0x2260c0 cmp r1, #0 */
/* @0x2260c4 strb r2, [r3] */
/* @0x2260c8 pople {r4, r5, r6, pc} */
/* @0x2260cc mov r4, #0 */
/* @0x2260d0 mov r5, r4 */
/* @0x2260d4 add r0, r0, r4 */
/* @0x2260d8 add r5, r5, #1 */
/* @0x2260dc bl 0x223844 <_ZN10COggThread7SuspendEv> */
/* @0x2260e0 ldr r3, [r6, #0x14] */
/* @0x2260e4 add r4, r4, #2096 */
/* @0x2260e8 cmp r3, r5 */
/* @0x2260ec add r4, r4, #4 */
/* @0x2260f0 pople {r4, r5, r6, pc} */
/* @0x2260f4 ldr r0, [r6] */
/* @0x2260f8 b 0x2260d4 <_ZN9COggAudio7SuspendEv+0x38> */
/* @0x2260fc ldrheq r11, [r12], -r12 */

/* ── FUNC 0x226100 · COggAudio::Unsuspend() · size=24 · insn=6 */
/* @0x226100 ldr r3, [pc, #0xc] */
/* @0x226104 mov r2, #0 */
/* @0x226108 ldr r3, [pc, r3] */
/* @0x22610c strb r2, [r3] */
/* @0x226110 bx lr */
/* @0x226114 andseq r11, r12, r0, ror r3 */

/* ── FUNC 0x226118 · COggAudio::GetOggChannel(int, int) · size=188 · insn=47 */
/* @0x226118 cmn r2, #1 */
/* @0x22611c push {r4, r5, r6, lr} */
/* @0x226120 mov r5, r0 */
/* @0x226124 mov r4, r1 */
/* @0x226128 beq 0x226190 <_ZN9COggAudio13GetOggChannelEii+0x78> */
/* @0x22612c ldr r3, [r0, #0x4] */
/* @0x226130 cmp r2, r3 */
/* @0x226134 ldrlt r3, [r0, #0x10] */
/* @0x226138 movge r3, #0 */
/* @0x22613c ldrlt r3, [r3, r2, lsl #2] */
/* @0x226140 ldr r1, [r3, #0x80c] */
/* @0x226144 cmp r1, #0 */
/* @0x226148 ble 0x226188 <_ZN9COggAudio13GetOggChannelEii+0x70> */
/* @0x22614c ldr r0, [r3, #0x804] */
/* @0x226150 ldr r3, [r0, #0x2b8] */
/* @0x226154 cmp r3, r4 */
/* @0x226158 popeq {r4, r5, r6, pc} */
/* @0x22615c add r3, r0, #768 */
/* @0x226160 mov r2, #0 */
/* @0x226164 b 0x226174 <_ZN9COggAudio13GetOggChannelEii+0x5c> */
/* @0x226168 ldr r12, [r3, #-0x48] */
/* @0x22616c cmp r12, r4 */
/* @0x226170 popeq {r4, r5, r6, pc} */
/* @0x226174 add r2, r2, #1 */
/* @0x226178 mov r0, r3 */
/* @0x22617c cmp r2, r1 */
/* @0x226180 add r3, r3, #768 */
/* @0x226184 bne 0x226168 <_ZN9COggAudio13GetOggChannelEii+0x50> */
/* @0x226188 mov r0, #0 */
/* @0x22618c pop {r4, r5, r6, pc} */
/* @0x226190 ldr r6, [r0, #0x14] */
/* @0x226194 mov r0, r1 */
/* @0x226198 mov r1, r6 */
/* @0x22619c bl 0x318dec <__aeabi_idivmod> */
/* @0x2261a0 ldr r3, [r5] */
/* @0x2261a4 movw r5, #0x834 */
/* @0x2261a8 mla r5, r5, r1, r3 */
/* @0x2261ac ldrb r0, [r5, #0x802] */
/* @0x2261b0 cmp r0, #0 */
/* @0x2261b4 popeq {r4, r5, r6, pc} */
/* @0x2261b8 mov r0, r4 */
/* @0x2261bc mov r1, r6 */
/* @0x2261c0 bl 0x318d10 <__divsi3> */
/* @0x2261c4 ldr r3, [r5, #0x804] */
/* @0x2261c8 add r0, r0, r0, lsl #1 */
/* @0x2261cc add r0, r3, r0, lsl #8 */
/* @0x2261d0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2261d4 · COggAudio::StartSyncGroup(int) · size=32 · insn=8 */
/* @0x2261d4 ldr r3, [r0, #0x4] */
/* @0x2261d8 cmp r3, r1 */
/* @0x2261dc bxle lr */
/* @0x2261e0 ldr r3, [r0, #0x10] */
/* @0x2261e4 ldr r0, [r3, r1, lsl #2] */
/* @0x2261e8 cmp r0, #0 */
/* @0x2261ec bxeq lr */
/* @0x2261f0 b 0x225c20 <_ZN14COggSyncThread14StartSyncGroupEv> */

/* ── FUNC 0x2261f4 · COggAudio::StopSyncGroup(int) · size=32 · insn=8 */
/* @0x2261f4 ldr r3, [r0, #0x4] */
/* @0x2261f8 cmp r3, r1 */
/* @0x2261fc bxle lr */
/* @0x226200 ldr r3, [r0, #0x10] */
/* @0x226204 ldr r0, [r3, r1, lsl #2] */
/* @0x226208 cmp r0, #0 */
/* @0x22620c bxeq lr */
/* @0x226210 b 0x225c4c <_ZN14COggSyncThread13StopSyncGroupEv> */

/* ── FUNC 0x226214 · COggAudio::PauseSyncGroup(int) · size=32 · insn=8 */
/* @0x226214 ldr r3, [r0, #0x4] */
/* @0x226218 cmp r3, r1 */
/* @0x22621c bxle lr */
/* @0x226220 ldr r3, [r0, #0x10] */
/* @0x226224 ldr r0, [r3, r1, lsl #2] */
/* @0x226228 cmp r0, #0 */
/* @0x22622c bxeq lr */
/* @0x226230 b 0x225c74 <_ZN14COggSyncThread14PauseSyncGroupEv> */

/* ── FUNC 0x226234 · COggAudio::ResumeSyncGroup(int) · size=32 · insn=8 */
/* @0x226234 ldr r3, [r0, #0x4] */
/* @0x226238 cmp r3, r1 */
/* @0x22623c bxle lr */
/* @0x226240 ldr r3, [r0, #0x10] */
/* @0x226244 ldr r0, [r3, r1, lsl #2] */
/* @0x226248 cmp r0, #0 */
/* @0x22624c bxeq lr */
/* @0x226250 b 0x225c94 <_ZN14COggSyncThread15ResumeSyncGroupEv> */

/* ── FUNC 0x226254 · COggAudio::IsSyncGroupPlaying(int) · size=40 · insn=10 */
/* @0x226254 ldr r3, [r0, #0x4] */
/* @0x226258 cmp r3, r1 */
/* @0x22625c ble 0x226274 <_ZN9COggAudio18IsSyncGroupPlayingEi+0x20> */
/* @0x226260 ldr r3, [r0, #0x10] */
/* @0x226264 ldr r0, [r3, r1, lsl #2] */
/* @0x226268 cmp r0, #0 */
/* @0x22626c ldrbne r0, [r0, #0x854] */
/* @0x226270 bx lr */
/* @0x226274 mov r0, #0 */
/* @0x226278 bx lr */

/* ── FUNC 0x22627c · COggAudio::DebugSyncGroup(int) · size=8 · insn=2 */
/* @0x22627c str r1, [r0, #0x1c] */
/* @0x226280 bx lr */

/* ── FUNC 0x226284 · COggAudio::GetThreadForChannel(int, int&) · size=136 · insn=34 */
/* @0x226284 push {r4, r5, r6, r7, r8, lr} */
/* @0x226288 mov r4, r0 */
/* @0x22628c ldr r5, [r0, #0x14] */
/* @0x226290 mov r6, r1 */
/* @0x226294 mov r0, r1 */
/* @0x226298 mov r8, r2 */
/* @0x22629c mov r1, r5 */
/* @0x2262a0 bl 0x318dec <__aeabi_idivmod> */
/* @0x2262a4 mov r0, r6 */
/* @0x2262a8 mov r7, r1 */
/* @0x2262ac mov r1, r5 */
/* @0x2262b0 bl 0x318d10 <__divsi3> */
/* @0x2262b4 ldr r3, [r4] */
/* @0x2262b8 movw r5, #0x834 */
/* @0x2262bc mla r5, r5, r7, r3 */
/* @0x2262c0 ldrb r3, [r5, #0x802] */
/* @0x2262c4 cmp r3, #0 */
/* @0x2262c8 str r0, [r8] */
/* @0x2262cc beq 0x2262d8 <_ZN9COggAudio19GetThreadForChannelEiRi+0x54> */
/* @0x2262d0 mov r0, r5 */
/* @0x2262d4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2262d8 ldr r6, [r4, #0x14] */
/* @0x2262dc ldr r0, [r4, #0x18] */
/* @0x2262e0 mov r1, r6 */
/* @0x2262e4 bl 0x318d10 <__divsi3> */
/* @0x2262e8 mov r1, r7 */
/* @0x2262ec mov r2, r6 */
/* @0x2262f0 mov r3, r0 */
/* @0x2262f4 mov r0, r5 */
/* @0x2262f8 bl 0x223924 <_ZN10COggThread6CreateEiii> */
/* @0x2262fc cmp r0, #0 */
/* @0x226300 movne r0, r5 */
/* @0x226304 moveq r0, #0 */
/* @0x226308 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x22630c · COggAudio::Play_Sound(int, cAudio_Sound*, bool, float, int, int) · size=248 · insn=62 */
/* @0x22630c push {r4, r5, lr} */
/* @0x226310 mov r4, r2 */
/* @0x226314 ldrb r2, [r2, #0x24] */
/* @0x226318 sub sp, sp, #28 */
/* @0x22631c cmp r2, #0 */
/* @0x226320 ldr r12, [sp, #0x30] */
/* @0x226324 beq 0x226334 <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x28> */
/* @0x226328 ldr r2, [r4, #0x30] */
/* @0x22632c cmp r2, #0 */
/* @0x226330 beq 0x2263d0 <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0xc4> */
/* @0x226334 cmn r12, #1 */
/* @0x226338 mov r2, #0 */
/* @0x22633c str r2, [sp, #0x14] */
/* @0x226340 beq 0x226394 <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x88> */
/* @0x226344 ldr r5, [r0, #0x4] */
/* @0x226348 cmp r12, r5 */
/* @0x22634c movge r0, r2 */
/* @0x226350 bge 0x22638c <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x80> */
/* @0x226354 ldr r2, [r0, #0x10] */
/* @0x226358 ldr r0, [r2, r12, lsl #2] */
/* @0x22635c cmp r0, #0 */
/* @0x226360 beq 0x22638c <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x80> */
/* @0x226364 ldr r2, [sp, #0x2c] */
/* @0x226368 add r12, sp, #24 */
/* @0x22636c vldr s15, [sp, #40] */
/* @0x226370 vstr s15, [sp] */
/* @0x226374 str r2, [sp, #0x4] */
/* @0x226378 mov r2, r4 */
/* @0x22637c str r1, [r12, #-0x4]! */
/* @0x226380 mov r1, r12 */
/* @0x226384 bl 0x224e48 <_ZN14COggSyncThread10Play_SoundERiP12cAudio_Soundbfi> */
/* @0x226388 ldr r0, [sp, #0x14] */
/* @0x22638c add sp, sp, #28 */
/* @0x226390 pop {r4, r5, pc} */
/* @0x226394 add r2, sp, #20 */
/* @0x226398 str r3, [sp, #0xc] */
/* @0x22639c bl 0x226284 <_ZN9COggAudio19GetThreadForChannelEiRi> */
/* @0x2263a0 ldr r3, [sp, #0xc] */
/* @0x2263a4 cmp r0, #0 */
/* @0x2263a8 beq 0x226388 <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x7c> */
/* @0x2263ac ldr r2, [sp, #0x2c] */
/* @0x2263b0 vldr s15, [sp, #40] */
/* @0x2263b4 ldr r1, [sp, #0x14] */
/* @0x2263b8 vstr s15, [sp] */
/* @0x2263bc str r2, [sp, #0x4] */
/* @0x2263c0 mov r2, r4 */
/* @0x2263c4 bl 0x223aac <_ZN10COggThread10Play_SoundEiP12cAudio_Soundbfi> */
/* @0x2263c8 ldr r0, [sp, #0x14] */
/* @0x2263cc b 0x22638c <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x80> */
/* @0x2263d0 ldr r3, [pc, #0x24] */
/* @0x2263d4 ldr r1, [pc, #0x24] */
/* @0x2263d8 ldr r3, [pc, r3] */
/* @0x2263dc ldr r2, [r4] */
/* @0x2263e0 add r1, pc, r1 */
/* @0x2263e4 ldr r0, [r3] */
/* @0x2263e8 ldr r3, [r0] */
/* @0x2263ec ldr r3, [r3, #0xc] */
/* @0x2263f0 blx r3 */
/* @0x2263f4 mvn r0, #0 */
/* @0x2263f8 b 0x22638c <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii+0x80> */
/* @0x2263fc andseq r7, r12, r12, lsr r3 */
/* @0x226400 andseq lr, r2, r8, lsl #22 */

/* ── FUNC 0x226404 · COggAudio::Stop_Sound(int) · size=48 · insn=12 */
/* @0x226404 str lr, [sp, #-0x4]! */
/* @0x226408 sub sp, sp, #12 */
/* @0x22640c add r2, sp, #8 */
/* @0x226410 mov r3, #0 */
/* @0x226414 str r3, [r2, #-0x4]! */
/* @0x226418 bl 0x226284 <_ZN9COggAudio19GetThreadForChannelEiRi> */
/* @0x22641c cmp r0, #0 */
/* @0x226420 beq 0x22642c <_ZN9COggAudio10Stop_SoundEi+0x28> */
/* @0x226424 ldr r1, [sp, #0x4] */
/* @0x226428 bl 0x223b78 <_ZN10COggThread10Stop_SoundEi> */
/* @0x22642c add sp, sp, #12 */
/* @0x226430 ldr pc, [sp], #4 */

/* ── FUNC 0x226434 · COggAudio::Seek_Sound(int, float) · size=60 · insn=15 */
/* @0x226434 push {r4, lr} */
/* @0x226438 sub sp, sp, #8 */
/* @0x22643c add r3, sp, #8 */
/* @0x226440 mov r12, #0 */
/* @0x226444 mov r4, r2 */
/* @0x226448 str r12, [r3, #-0x4]! */
/* @0x22644c mov r2, r3 */
/* @0x226450 bl 0x226284 <_ZN9COggAudio19GetThreadForChannelEiRi> */
/* @0x226454 cmp r0, #0 */
/* @0x226458 beq 0x226468 <_ZN9COggAudio10Seek_SoundEif+0x34> */
/* @0x22645c mov r2, r4 */
/* @0x226460 ldr r1, [sp, #0x4] */
/* @0x226464 bl 0x223ba4 <_ZN10COggThread10Seek_SoundEif> */
/* @0x226468 add sp, sp, #8 */
/* @0x22646c pop {r4, pc} */

/* ── FUNC 0x226470 · COggAudio::Pause_Sound(int) · size=144 · insn=36 */
/* @0x226470 push {r4, r5, r6, lr} */
/* @0x226474 sub sp, sp, #8 */
/* @0x226478 ldr r4, [pc, #0x7c] */
/* @0x22647c mov r5, r1 */
/* @0x226480 mov r2, sp */
/* @0x226484 mov r6, r0 */
/* @0x226488 ldr r4, [pc, r4] */
/* @0x22648c movw r1, #0x1010 */
/* @0x226490 ldr r3, [r4] */
/* @0x226494 ldr r0, [r3, r5, lsl #2] */
/* @0x226498 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x22649c ldr r3, [sp] */
/* @0x2264a0 movw r2, #0x1012 */
/* @0x2264a4 cmp r3, r2 */
/* @0x2264a8 beq 0x2264ec <_ZN9COggAudio11Pause_SoundEi+0x7c> */
/* @0x2264ac movw r2, #0x1013 */
/* @0x2264b0 cmp r3, r2 */
/* @0x2264b4 beq 0x2264e4 <_ZN9COggAudio11Pause_SoundEi+0x74> */
/* @0x2264b8 add r2, sp, #8 */
/* @0x2264bc mov r3, #0 */
/* @0x2264c0 mov r0, r6 */
/* @0x2264c4 mov r1, r5 */
/* @0x2264c8 str r3, [r2, #-0x4]! */
/* @0x2264cc bl 0x226284 <_ZN9COggAudio19GetThreadForChannelEiRi> */
/* @0x2264d0 cmp r0, #0 */
/* @0x2264d4 beq 0x2264e4 <_ZN9COggAudio11Pause_SoundEi+0x74> */
/* @0x2264d8 ldr r1, [sp, #0x4] */
/* @0x2264dc mov r2, #1 */
/* @0x2264e0 bl 0x223b34 <_ZN10COggThread17PauseResume_SoundEib> */
/* @0x2264e4 add sp, sp, #8 */
/* @0x2264e8 pop {r4, r5, r6, pc} */
/* @0x2264ec ldr r3, [r4] */
/* @0x2264f0 ldr r0, [r3, r5, lsl #2] */
/* @0x2264f4 bl 0xb6ab4 <alSourcePause@plt> */
/* @0x2264f8 b 0x2264e4 <_ZN9COggAudio11Pause_SoundEi+0x74> */
/* @0x2264fc andseq r10, r12, r4, asr #30 */

/* ── FUNC 0x226500 · COggAudio::Resume_Sound(int) · size=144 · insn=36 */
/* @0x226500 push {r4, r5, r6, lr} */
/* @0x226504 sub sp, sp, #8 */
/* @0x226508 ldr r4, [pc, #0x7c] */
/* @0x22650c mov r5, r1 */
/* @0x226510 mov r2, sp */
/* @0x226514 mov r6, r0 */
/* @0x226518 ldr r4, [pc, r4] */
/* @0x22651c movw r1, #0x1010 */
/* @0x226520 ldr r3, [r4] */
/* @0x226524 ldr r0, [r3, r5, lsl #2] */
/* @0x226528 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x22652c ldr r3, [sp] */
/* @0x226530 movw r2, #0x1013 */
/* @0x226534 cmp r3, r2 */
/* @0x226538 beq 0x22657c <_ZN9COggAudio12Resume_SoundEi+0x7c> */
/* @0x22653c movw r2, #0x1012 */
/* @0x226540 cmp r3, r2 */
/* @0x226544 beq 0x226574 <_ZN9COggAudio12Resume_SoundEi+0x74> */
/* @0x226548 add r2, sp, #8 */
/* @0x22654c mov r4, #0 */
/* @0x226550 mov r0, r6 */
/* @0x226554 mov r1, r5 */
/* @0x226558 str r4, [r2, #-0x4]! */
/* @0x22655c bl 0x226284 <_ZN9COggAudio19GetThreadForChannelEiRi> */
/* @0x226560 cmp r0, r4 */
/* @0x226564 beq 0x226574 <_ZN9COggAudio12Resume_SoundEi+0x74> */
/* @0x226568 mov r2, r4 */
/* @0x22656c ldr r1, [sp, #0x4] */
/* @0x226570 bl 0x223b34 <_ZN10COggThread17PauseResume_SoundEib> */
/* @0x226574 add sp, sp, #8 */
/* @0x226578 pop {r4, r5, r6, pc} */
/* @0x22657c ldr r3, [r4] */
/* @0x226580 ldr r0, [r3, r5, lsl #2] */
/* @0x226584 bl 0xb6a84 <alSourcePlay@plt> */
/* @0x226588 b 0x226574 <_ZN9COggAudio12Resume_SoundEi+0x74> */
/* @0x22658c ldrheq r10, [r12], -r4 */

/* ── FUNC 0x226590 · COggAudio::Tick(cARRAY_CLASS<CNoise*>*) · size=764 · insn=191 */
/* @0x226590 ldr r2, [r0, #0x14] */
/* @0x226594 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x226598 cmp r2, #0 */
/* @0x22659c mov r10, r0 */
/* @0x2265a0 mov r9, r1 */
/* @0x2265a4 movgt r8, #0 */
/* @0x2265a8 sub sp, sp, #28 */
/* @0x2265ac movgt r11, r8 */
/* @0x2265b0 movgt r1, r0 */
/* @0x2265b4 movgt r10, r11 */
/* @0x2265b8 bgt 0x2265d4 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x44> */
/* @0x2265bc b 0x2266cc <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x13c> */
/* @0x2265c0 add r10, r10, #1 */
/* @0x2265c4 add r8, r8, #2096 */
/* @0x2265c8 cmp r2, r10 */
/* @0x2265cc add r8, r8, #4 */
/* @0x2265d0 ble 0x2266c8 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x138> */
/* @0x2265d4 ldr r6, [r1] */
/* @0x2265d8 add r6, r6, r8 */
/* @0x2265dc ldrb r3, [r6, #0x802] */
/* @0x2265e0 cmp r3, #0 */
/* @0x2265e4 beq 0x2265c0 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x30> */
/* @0x2265e8 mov r0, r6 */
/* @0x2265ec str r1, [sp, #0x4] */
/* @0x2265f0 bl 0x2247c0 <_ZN10COggThread4TickEv> */
/* @0x2265f4 ldr r0, [r6, #0x808] */
/* @0x2265f8 ldr r11, [r9] */
/* @0x2265fc cmp r0, #0 */
/* @0x226600 ldr r1, [sp, #0x4] */
/* @0x226604 ble 0x2266a8 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x118> */
/* @0x226608 ldr r7, [r6, #0x804] */
/* @0x22660c ldr r3, [r7, #0x2b8] */
/* @0x226610 cmp r11, r3 */
/* @0x226614 movgt r2, r11 */
/* @0x226618 movgt r4, #0 */
/* @0x22661c bgt 0x22664c <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0xbc> */
/* @0x226620 b 0x2266a8 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x118> */
/* @0x226624 add r4, r4, #1 */
/* @0x226628 cmp r0, r4 */
/* @0x22662c ble 0x2266a8 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x118> */
/* @0x226630 ldr r3, [r6, #0x804] */
/* @0x226634 add r7, r4, r4, lsl #1 */
/* @0x226638 add r7, r3, r7, lsl #8 */
/* @0x22663c ldr r3, [r7, #0x2b8] */
/* @0x226640 cmp r11, r3 */
/* @0x226644 ble 0x2266a8 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x118> */
/* @0x226648 ldr r2, [r9] */
/* @0x22664c cmp r3, r2 */
/* @0x226650 ldrlt r2, [r9, #0x4] */
/* @0x226654 movge r5, #0 */
/* @0x226658 ldrlt r5, [r2, r3, lsl #2] */
/* @0x22665c ldrb r3, [r5, #0x5] */
/* @0x226660 cmp r3, #0 */
/* @0x226664 beq 0x226624 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x94> */
/* @0x226668 ldrb r3, [r5, #0xc] */
/* @0x22666c cmp r3, #0 */
/* @0x226670 beq 0x226624 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x94> */
/* @0x226674 mov r0, r6 */
/* @0x226678 str r1, [sp, #0x4] */
/* @0x22667c bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x226680 ldrb r7, [r7, #0x2d5] */
/* @0x226684 mov r0, r6 */
/* @0x226688 bl 0x223aa4 <_ZN10COggThread6UnlockEv> */
/* @0x22668c cmp r7, #0 */
/* @0x226690 ldr r1, [sp, #0x4] */
/* @0x226694 beq 0x2266b0 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x120> */
/* @0x226698 ldr r0, [r6, #0x808] */
/* @0x22669c add r4, r4, #1 */
/* @0x2266a0 cmp r0, r4 */
/* @0x2266a4 bgt 0x226630 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0xa0> */
/* @0x2266a8 ldr r2, [r1, #0x14] */
/* @0x2266ac b 0x2265c0 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x30> */
/* @0x2266b0 mov r0, r5 */
/* @0x2266b4 str r1, [sp, #0x4] */
/* @0x2266b8 bl 0x21a048 <_Z22Audio_SetNoiseInactiveP6CNoise> */
/* @0x2266bc ldr r0, [r6, #0x808] */
/* @0x2266c0 ldr r1, [sp, #0x4] */
/* @0x2266c4 b 0x226624 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x94> */
/* @0x2266c8 mov r10, r1 */
/* @0x2266cc ldr r1, [pc, #0x1b4] */
/* @0x2266d0 ldr r1, [pc, r1] */
/* @0x2266d4 str r1, [sp, #0x10] */
/* @0x2266d8 ldr r3, [r1] */
/* @0x2266dc subs r9, r3, #1 */
/* @0x2266e0 lslpl r2, r9, #2 */
/* @0x2266e4 strpl r2, [sp, #0x8] */
/* @0x2266e8 movpl r11, r10 */
/* @0x2266ec bmi 0x226830 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2a0> */
/* @0x2266f0 cmp r3, r9 */
/* @0x2266f4 ble 0x2267b4 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x224> */
/* @0x2266f8 ldr r1, [sp, #0x10] */
/* @0x2266fc ldr r2, [sp, #0x8] */
/* @0x226700 ldr r3, [r1, #0x4] */
/* @0x226704 ldr r8, [r3, r2] */
/* @0x226708 cmp r8, #0 */
/* @0x22670c beq 0x2267b4 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x224> */
/* @0x226710 ldrb r3, [r8, #0x27] */
/* @0x226714 cmp r3, #0 */
/* @0x226718 beq 0x2267b4 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x224> */
/* @0x22671c ldr r4, [r11, #0x14] */
/* @0x226720 cmp r4, #0 */
/* @0x226724 ble 0x226804 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x274> */
/* @0x226728 mov r10, #0 */
/* @0x22672c str r9, [sp, #0x14] */
/* @0x226730 mov r9, r11 */
/* @0x226734 mov r11, r10 */
/* @0x226738 str r10, [sp, #0xc] */
/* @0x22673c ldr r7, [r9] */
/* @0x226740 add r7, r7, r11 */
/* @0x226744 ldrb r3, [r7, #0x802] */
/* @0x226748 cmp r3, #0 */
/* @0x22674c beq 0x22678c <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x1fc> */
/* @0x226750 ldr r0, [r7, #0x808] */
/* @0x226754 cmp r0, #0 */
/* @0x226758 ble 0x22678c <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x1fc> */
/* @0x22675c mov r4, #0 */
/* @0x226760 mov r5, r4 */
/* @0x226764 ldr r6, [r7, #0x804] */
/* @0x226768 add r6, r6, r4 */
/* @0x22676c ldr r3, [r6, #0x2bc] */
/* @0x226770 cmp r3, r8 */
/* @0x226774 beq 0x2267d8 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x248> */
/* @0x226778 add r5, r5, #1 */
/* @0x22677c add r4, r4, #768 */
/* @0x226780 cmp r0, r5 */
/* @0x226784 bgt 0x226764 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x1d4> */
/* @0x226788 ldr r4, [r9, #0x14] */
/* @0x22678c add r10, r10, #1 */
/* @0x226790 add r11, r11, #2096 */
/* @0x226794 cmp r4, r10 */
/* @0x226798 add r11, r11, #4 */
/* @0x22679c bgt 0x22673c <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x1ac> */
/* @0x2267a0 ldr r3, [sp, #0xc] */
/* @0x2267a4 mov r11, r9 */
/* @0x2267a8 ldr r9, [sp, #0x14] */
/* @0x2267ac cmp r3, #0 */
/* @0x2267b0 beq 0x226804 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x274> */
/* @0x2267b4 sub r9, r9, #1 */
/* @0x2267b8 ldr r1, [sp, #0x8] */
/* @0x2267bc cmn r9, #1 */
/* @0x2267c0 sub r1, r1, #4 */
/* @0x2267c4 str r1, [sp, #0x8] */
/* @0x2267c8 beq 0x22682c <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x29c> */
/* @0x2267cc ldr r2, [sp, #0x10] */
/* @0x2267d0 ldr r3, [r2] */
/* @0x2267d4 b 0x2266f0 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x160> */
/* @0x2267d8 mov r0, r7 */
/* @0x2267dc bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x2267e0 mov r0, r7 */
/* @0x2267e4 ldrb r6, [r6, #0x2d5] */
/* @0x2267e8 bl 0x223aa4 <_ZN10COggThread6UnlockEv> */
/* @0x2267ec ldr r0, [r7, #0x808] */
/* @0x2267f0 cmp r6, #0 */
/* @0x2267f4 ldrne r2, [sp, #0xc] */
/* @0x2267f8 addne r2, r2, #1 */
/* @0x2267fc strne r2, [sp, #0xc] */
/* @0x226800 b 0x226778 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x1e8> */
/* @0x226804 mov r0, r8 */
/* @0x226808 bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x22680c mov r0, r8 */
/* @0x226810 bl 0x27d1d0 <_ZdlPv> */
/* @0x226814 ldr r1, [sp, #0x10] */
/* @0x226818 ldr r2, [sp, #0x8] */
/* @0x22681c ldr r3, [r1, #0x4] */
/* @0x226820 mov r1, #0 */
/* @0x226824 str r1, [r3, r2] */
/* @0x226828 b 0x2267b4 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x224> */
/* @0x22682c mov r10, r11 */
/* @0x226830 ldr r3, [r10, #0x4] */
/* @0x226834 cmp r3, #0 */
/* @0x226838 movgt r4, #0 */
/* @0x22683c bgt 0x226854 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2c4> */
/* @0x226840 b 0x226880 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2f0> */
/* @0x226844 ldr r3, [r10, #0x4] */
/* @0x226848 add r4, r4, #1 */
/* @0x22684c cmp r3, r4 */
/* @0x226850 ble 0x226880 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2f0> */
/* @0x226854 ldr r2, [r10, #0x10] */
/* @0x226858 ldr r0, [r2, r4, lsl #2] */
/* @0x22685c cmp r0, #0 */
/* @0x226860 beq 0x226848 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2b8> */
/* @0x226864 bl 0x22510c <_ZN14COggSyncThread4TickEv> */
/* @0x226868 cmp r0, #0 */
/* @0x22686c beq 0x226844 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2b4> */
/* @0x226870 mov r0, r10 */
/* @0x226874 mov r1, r4 */
/* @0x226878 bl 0x225f2c <_ZN9COggAudio17Delete_SyncThreadEi> */
/* @0x22687c b 0x226844 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2b4> */
/* @0x226880 add sp, sp, #28 */
/* @0x226884 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x226888 andseq r10, r12, r8, lsl #26 */

/* ── FUNC 0x22688c · COggAudio::CalcSoundInfo(cAudio_Sound*) · size=168 · insn=42 */
/* @0x22688c push {r4, r5, r6, lr} */
/* @0x226890 sub sp, sp, #1024 */
/* @0x226894 ldr r4, [pc, #0x94] */
/* @0x226898 sub sp, sp, #8 */
/* @0x22689c ldrb r3, [r1, #0x24] */
/* @0x2268a0 mov r5, r1 */
/* @0x2268a4 ldr r4, [pc, r4] */
/* @0x2268a8 cmp r3, #0 */
/* @0x2268ac ldr r3, [r4] */
/* @0x2268b0 str r3, [sp, #0x404] */
/* @0x2268b4 beq 0x2268c4 <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound+0x38> */
/* @0x2268b8 ldr r3, [r1, #0x30] */
/* @0x2268bc cmp r3, #0 */
/* @0x2268c0 beq 0x2268e8 <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound+0x5c> */
/* @0x2268c4 mov r0, r5 */
/* @0x2268c8 bl 0x223eb0 <_Z13GetStreamInfoP12cAudio_Sound> */
/* @0x2268cc ldr r2, [sp, #0x404] */
/* @0x2268d0 ldr r3, [r4] */
/* @0x2268d4 cmp r2, r3 */
/* @0x2268d8 bne 0x22692c <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound+0xa0> */
/* @0x2268dc add sp, sp, #1024 */
/* @0x2268e0 add sp, sp, #8 */
/* @0x2268e4 pop {r4, r5, r6, pc} */
/* @0x2268e8 add r6, sp, #4 */
/* @0x2268ec mov r1, #1024 */
/* @0x2268f0 ldr r2, [r5] */
/* @0x2268f4 mov r0, r6 */
/* @0x2268f8 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x2268fc mov r0, r6 */
/* @0x226900 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x226904 cmp r0, #0 */
/* @0x226908 beq 0x2268c4 <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound+0x38> */
/* @0x22690c ldr r0, [r5, #0x30] */
/* @0x226910 cmp r0, #0 */
/* @0x226914 beq 0x22691c <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound+0x90> */
/* @0x226918 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x22691c mov r0, r6 */
/* @0x226920 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x226924 str r0, [r5, #0x30] */
/* @0x226928 b 0x2268c4 <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound+0x38> */
/* @0x22692c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x226930 andseq r7, r12, r12, lsr #1 */

/* ── FUNC 0x226934 · COggAudio::GetSyncGroupTrackPos(int) · size=220 · insn=55 */
/* @0x226934 ldr r3, [r0, #0x4] */
/* @0x226938 push {r4, r5, lr} */
/* @0x22693c vpush {d8} */
/* @0x226940 cmp r3, r1 */
/* @0x226944 sub sp, sp, #12 */
/* @0x226948 mov r5, r0 */
/* @0x22694c ble 0x2269d4 <_ZN9COggAudio20GetSyncGroupTrackPosEi+0xa0> */
/* @0x226950 ldr r3, [r0, #0x10] */
/* @0x226954 ldr r4, [r3, r1, lsl #2] */
/* @0x226958 cmp r4, #0 */
/* @0x22695c beq 0x2269d4 <_ZN9COggAudio20GetSyncGroupTrackPosEi+0xa0> */
/* @0x226960 add r2, sp, #8 */
/* @0x226964 mov r3, #0 */
/* @0x226968 movw r1, #0x1025 */
/* @0x22696c ldr r0, [r4, #0x86c] */
/* @0x226970 str r3, [r2, #-0x4]! */
/* @0x226974 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x226978 ldr r3, [r4, #0x804] */
/* @0x22697c ldr r1, [r3, #0x2bc] */
/* @0x226980 cmp r1, #0 */
/* @0x226984 beq 0x2269e8 <_ZN9COggAudio20GetSyncGroupTrackPosEi+0xb4> */
/* @0x226988 ldr r3, [r1, #0x38] */
/* @0x22698c cmp r3, #0 */
/* @0x226990 ble 0x2269f0 <_ZN9COggAudio20GetSyncGroupTrackPosEi+0xbc> */
/* @0x226994 vmov s14, r3 */
/* @0x226998 vcvt.f32.s32 s16, s14 */
/* @0x22699c movw r3, #0x818 */
/* @0x2269a0 ldr r0, [sp, #0x4] */
/* @0x2269a4 ldrd r2, r3, [r3, r4] */
/* @0x2269a8 adds r4, r2, r0 */
/* @0x2269ac adc r5, r3, r0, asr #31 */
/* @0x2269b0 mov r0, r4 */
/* @0x2269b4 mov r1, r5 */
/* @0x2269b8 bl 0x319398 <__floatdisf> */
/* @0x2269bc vmov s14, r0 */
/* @0x2269c0 vdiv.f32 s15, s14, s16 */
/* @0x2269c4 vmov r0, s15 */
/* @0x2269c8 add sp, sp, #12 */
/* @0x2269cc vpop {d8} */
/* @0x2269d0 pop {r4, r5, pc} */
/* @0x2269d4 vmov.f32 s15, #-1.000000e+00 */
/* @0x2269d8 vmov r0, s15 */
/* @0x2269dc add sp, sp, #12 */
/* @0x2269e0 vpop {d8} */
/* @0x2269e4 pop {r4, r5, pc} */
/* @0x2269e8 vldr s16, [pc, #28] */
/* @0x2269ec b 0x22699c <_ZN9COggAudio20GetSyncGroupTrackPosEi+0x68> */
/* @0x2269f0 mov r0, r5 */
/* @0x2269f4 bl 0x22688c <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound> */
/* @0x2269f8 ldr r3, [r4, #0x804] */
/* @0x2269fc ldr r3, [r3, #0x2bc] */
/* @0x226a00 vldr s16, [r3, #56] */
/* @0x226a04 vcvt.f32.s32 s16, s16 */
/* @0x226a08 b 0x22699c <_ZN9COggAudio20GetSyncGroupTrackPosEi+0x68> */
/* @0x226a0c strmi r4, [r12, -r0, lsl #8]! */

/* ── FUNC 0x226a10 · COggAudio::SyncDrawDebug() · size=988 · insn=247 */
/* @0x226a10 ldr r3, [r0, #0x1c] */
/* @0x226a14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x226a18 vpush {d8, d9, d10} */
/* @0x226a1c cmn r3, #1 */
/* @0x226a20 sub sp, sp, #76 */
/* @0x226a24 str r0, [sp, #0x38] */
/* @0x226a28 beq 0x226ca0 <_ZN9COggAudio13SyncDrawDebugEv+0x290> */
/* @0x226a2c ldr r2, [r0, #0x4] */
/* @0x226a30 cmp r3, r2 */
/* @0x226a34 bge 0x226c70 <_ZN9COggAudio13SyncDrawDebugEv+0x260> */
/* @0x226a38 ldr r2, [r0, #0x10] */
/* @0x226a3c ldr r4, [r2, r3, lsl #2] */
/* @0x226a40 cmp r4, #0 */
/* @0x226a44 beq 0x226c70 <_ZN9COggAudio13SyncDrawDebugEv+0x260> */
/* @0x226a48 ldr r12, [sp, #0x38] */
/* @0x226a4c vldr s20, [pc, #876] */
/* @0x226a50 ldr r0, [pc, #0x37c] */
/* @0x226a54 mov r2, #-16777216 */
/* @0x226a58 ldr r10, [pc, #0x378] */
/* @0x226a5c mov r7, #0 */
/* @0x226a60 ldr r1, [r12, #0x8] */
/* @0x226a64 add r0, pc, r0 */
/* @0x226a68 str r3, [sp, #0x8] */
/* @0x226a6c mvn r3, #0 */
/* @0x226a70 str r0, [sp] */
/* @0x226a74 str r1, [sp, #0x4] */
/* @0x226a78 ldr r0, [r4, #0x80c] */
/* @0x226a7c vmov r1, s20 */
/* @0x226a80 str r0, [sp, #0xc] */
/* @0x226a84 mov r0, #0 */
/* @0x226a88 ldr r12, [r4, #0x828] */
/* @0x226a8c movt r0, #0x4120 */
/* @0x226a90 str r12, [sp, #0x10] */
/* @0x226a94 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x226a98 ldr r10, [pc, r10] */
/* @0x226a9c vldr s15, [r10] */
/* @0x226aa0 vadd.f32 s15, s15, s15 */
/* @0x226aa4 add r2, sp, #72 */
/* @0x226aa8 ldr r0, [r4, #0x86c] */
/* @0x226aac movw r1, #0x1015 */
/* @0x226ab0 str r7, [r2, #-0x8]! */
/* @0x226ab4 vadd.f32 s15, s15, s20 */
/* @0x226ab8 vmov r5, s15 */
/* @0x226abc bl 0xb6a9c <alGetSourcei@plt> */
/* @0x226ac0 ldr r3, [sp, #0x40] */
/* @0x226ac4 ldr r6, [r10] */
/* @0x226ac8 cmp r3, r7 */
/* @0x226acc addle r8, sp, #68 */
/* @0x226ad0 ble 0x226b90 <_ZN9COggAudio13SyncDrawDebugEv+0x180> */
/* @0x226ad4 vmov.f32 s16, #1.000000e+01 */
/* @0x226ad8 mov r9, #255 */
/* @0x226adc add r8, sp, #68 */
/* @0x226ae0 movt r9, #0xff00 */
/* @0x226ae4 mov r11, r7 */
/* @0x226ae8 mvn r7, #0 */
/* @0x226aec vldr s19, [pc, #720] */
/* @0x226af0 vldr s17, [pc, #720] */
/* @0x226af4 str r7, [sp] */
/* @0x226af8 mov r1, r5 */
/* @0x226afc vmov r0, s16 */
/* @0x226b00 mov r2, #0 */
/* @0x226b04 mov r3, r6 */
/* @0x226b08 movt r2, #0x42c8 */
/* @0x226b0c bl 0x17b83c <_ZN12GraphicsPerf15RenderRectangleEffffj> */
/* @0x226b10 cmp r11, #0 */
/* @0x226b14 bne 0x226b7c <_ZN9COggAudio13SyncDrawDebugEv+0x16c> */
/* @0x226b18 ldr r3, [r4, #0x804] */
/* @0x226b1c mov r1, #0 */
/* @0x226b20 mov r2, r8 */
/* @0x226b24 ldr r3, [r3, #0x2bc] */
/* @0x226b28 cmp r3, #0 */
/* @0x226b2c vldrne s18, [r3, #60] */
/* @0x226b30 str r1, [sp, #0x44] */
/* @0x226b34 movw r1, #0x1025 */
/* @0x226b38 ldr r0, [r4, #0x86c] */
/* @0x226b3c vldreq s18, [pc, #648] */
/* @0x226b40 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x226b44 vldr s13, [sp, #68] */
/* @0x226b48 vcvt.f32.s32 s15, s13 */
/* @0x226b4c str r9, [sp] */
/* @0x226b50 mov r1, r5 */
/* @0x226b54 mov r2, #1065353216 */
/* @0x226b58 mov r3, r6 */
/* @0x226b5c vmul.f32 s15, s15, s20 */
/* @0x226b60 vadd.f32 s15, s15, s15 */
/* @0x226b64 vcvt.f32.s32 s14, s18 */
/* @0x226b68 vmul.f32 s15, s15, s14 */
/* @0x226b6c vmov.f32 s14, s16 */
/* @0x226b70 vmla.f32 s14, s15, s19 */
/* @0x226b74 vmov r0, s14 */
/* @0x226b78 bl 0x17b83c <_ZN12GraphicsPerf15RenderRectangleEffffj> */
/* @0x226b7c ldr r3, [sp, #0x40] */
/* @0x226b80 add r11, r11, #1 */
/* @0x226b84 vadd.f32 s16, s16, s17 */
/* @0x226b88 cmp r3, r11 */
/* @0x226b8c bgt 0x226af4 <_ZN9COggAudio13SyncDrawDebugEv+0xe4> */
/* @0x226b90 ldr r1, [pc, #0x244] */
/* @0x226b94 mov r2, #-16777216 */
/* @0x226b98 str r3, [sp, #0x4] */
/* @0x226b9c mov r0, #0 */
/* @0x226ba0 mvn r3, #0 */
/* @0x226ba4 add r1, pc, r1 */
/* @0x226ba8 movt r0, #0x4120 */
/* @0x226bac str r1, [sp] */
/* @0x226bb0 mov r1, r5 */
/* @0x226bb4 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x226bb8 vldr s16, [r10] */
/* @0x226bbc vadd.f32 s16, s16, s16 */
/* @0x226bc0 mov r2, r8 */
/* @0x226bc4 vmov s15, r5 */
/* @0x226bc8 ldr r0, [r4, #0x86c] */
/* @0x226bcc movw r1, #0x1010 */
/* @0x226bd0 vadd.f32 s16, s16, s15 */
/* @0x226bd4 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x226bd8 ldr r3, [r4, #0x80c] */
/* @0x226bdc cmp r3, #0 */
/* @0x226be0 ble 0x226d28 <_ZN9COggAudio13SyncDrawDebugEv+0x318> */
/* @0x226be4 ldr r12, [pc, #0x1f4] */
/* @0x226be8 mov r5, #0 */
/* @0x226bec mov r7, r5 */
/* @0x226bf0 vldr s17, [pc, #472] */
/* @0x226bf4 add r12, pc, r12 */
/* @0x226bf8 str r12, [sp, #0x3c] */
/* @0x226bfc ldr r12, [pc, #0x1e0] */
/* @0x226c00 add r12, pc, r12 */
/* @0x226c04 str r12, [sp, #0x34] */
/* @0x226c08 ldr r3, [r4, #0x804] */
/* @0x226c0c add r0, r3, r5 */
/* @0x226c10 ldr r1, [r0, #0x2bc] */
/* @0x226c14 cmp r1, #0 */
/* @0x226c18 beq 0x226d80 <_ZN9COggAudio13SyncDrawDebugEv+0x370> */
/* @0x226c1c ldr r8, [r1, #0x38] */
/* @0x226c20 ldr r9, [r1, #0x3c] */
/* @0x226c24 cmp r8, #0 */
/* @0x226c28 ble 0x226da4 <_ZN9COggAudio13SyncDrawDebugEv+0x394> */
/* @0x226c2c vldr s15, [r1, #4] */
/* @0x226c30 vcmpe.f32 s15, s17 */
/* @0x226c34 ldr r11, [r1] */
/* @0x226c38 vmrs APSR_nzcv, fpscr */
/* @0x226c3c ble 0x226d8c <_ZN9COggAudio13SyncDrawDebugEv+0x37c> */
/* @0x226c40 mov r6, #65280 */
/* @0x226c44 bfi r6, r6, #16, #16 */
/* @0x226c48 ldr r2, [sp, #0x44] */
/* @0x226c4c sub r2, r2, #4096 */
/* @0x226c50 sub r2, r2, #17 */
/* @0x226c54 cmp r2, #3 */
/* @0x226c58 addls pc, pc, r2, lsl #2 */
/* @0x226c5c b 0x226d98 <_ZN9COggAudio13SyncDrawDebugEv+0x388> */
/* @0x226c60 b 0x226cac <_ZN9COggAudio13SyncDrawDebugEv+0x29c> */
/* @0x226c64 b 0x226d70 <_ZN9COggAudio13SyncDrawDebugEv+0x360> */
/* @0x226c68 b 0x226d58 <_ZN9COggAudio13SyncDrawDebugEv+0x348> */
/* @0x226c6c b 0x226d44 <_ZN9COggAudio13SyncDrawDebugEv+0x334> */
/* @0x226c70 ldr r1, [sp, #0x38] */
/* @0x226c74 mov r0, #0 */
/* @0x226c78 mov r2, #-16777216 */
/* @0x226c7c mvn r3, #0 */
/* @0x226c80 movt r0, #0x4120 */
/* @0x226c84 ldr r12, [r1, #0x8] */
/* @0x226c88 ldr r1, [pc, #0x158] */
/* @0x226c8c add r1, pc, r1 */
/* @0x226c90 stm sp, {r1, r12} */
/* @0x226c94 mov r1, #0 */
/* @0x226c98 movt r1, #0x42c8 */
/* @0x226c9c bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x226ca0 add sp, sp, #76 */
/* @0x226ca4 vpop {d8, d9, d10} */
/* @0x226ca8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x226cac mov r0, #0 */
/* @0x226cb0 mov r1, #0 */
/* @0x226cb4 mvn r6, #16711680 */
/* @0x226cb8 add r3, r3, r5 */
/* @0x226cbc ldr r12, [sp, #0x34] */
/* @0x226cc0 add r3, r3, #752 */
/* @0x226cc4 mov lr, #2080 */
/* @0x226cc8 add r5, r5, #768 */
/* @0x226ccc ldrd r2, r3, [r3] */
/* @0x226cd0 str r12, [sp] */
/* @0x226cd4 str r7, [sp, #0x4] */
/* @0x226cd8 add r7, r7, #1 */
/* @0x226cdc strd r2, r3, [sp, #32] */
/* @0x226ce0 str r11, [sp, #0x8] */
/* @0x226ce4 strd r0, r1, [sp, #16] */
/* @0x226ce8 str r9, [sp, #0x18] */
/* @0x226cec str r8, [sp, #0x1c] */
/* @0x226cf0 ldrd r0, r1, [r4, lr] */
/* @0x226cf4 bl 0x319414 <__aeabi_ldivmod> */
/* @0x226cf8 vmov r1, s16 */
/* @0x226cfc mov r0, #0 */
/* @0x226d00 movt r0, #0x4120 */
/* @0x226d04 strd r2, r3, [sp, #40] */
/* @0x226d08 mov r3, r6 */
/* @0x226d0c mov r2, #-16777216 */
/* @0x226d10 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz> */
/* @0x226d14 ldr r3, [r4, #0x80c] */
/* @0x226d18 vldr s15, [r10] */
/* @0x226d1c vadd.f32 s16, s16, s15 */
/* @0x226d20 cmp r3, r7 */
/* @0x226d24 bgt 0x226c08 <_ZN9COggAudio13SyncDrawDebugEv+0x1f8> */
/* @0x226d28 mov r0, r4 */
/* @0x226d2c bl 0x224c34 <_Z18UpdateTimingEventsP14COggSyncThread> */
/* @0x226d30 mov r0, r4 */
/* @0x226d34 bl 0x224cdc <_Z16DrawTimingEventsP14COggSyncThread> */
/* @0x226d38 add sp, sp, #76 */
/* @0x226d3c vpop {d8, d9, d10} */
/* @0x226d40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x226d44 mvn r1, #0 */
/* @0x226d48 mvn r6, #65280 */
/* @0x226d4c bl 0x23138c <ov_pcm_total> */
/* @0x226d50 ldr r3, [r4, #0x804] */
/* @0x226d54 b 0x226cb8 <_ZN9COggAudio13SyncDrawDebugEv+0x2a8> */
/* @0x226d58 mvn r1, #0 */
/* @0x226d5c mov r6, #0 */
/* @0x226d60 bl 0x23138c <ov_pcm_total> */
/* @0x226d64 movt r6, #0xffff */
/* @0x226d68 ldr r3, [r4, #0x804] */
/* @0x226d6c b 0x226cb8 <_ZN9COggAudio13SyncDrawDebugEv+0x2a8> */
/* @0x226d70 mvn r1, #0 */
/* @0x226d74 bl 0x23138c <ov_pcm_total> */
/* @0x226d78 ldr r3, [r4, #0x804] */
/* @0x226d7c b 0x226cb8 <_ZN9COggAudio13SyncDrawDebugEv+0x2a8> */
/* @0x226d80 ldr r11, [sp, #0x3c] */
/* @0x226d84 mov r9, #1 */
/* @0x226d88 movw r8, #0xac44 */
/* @0x226d8c mov r6, #255 */
/* @0x226d90 movt r6, #0xff00 */
/* @0x226d94 b 0x226c48 <_ZN9COggAudio13SyncDrawDebugEv+0x238> */
/* @0x226d98 mov r0, #0 */
/* @0x226d9c mov r1, #0 */
/* @0x226da0 b 0x226cb8 <_ZN9COggAudio13SyncDrawDebugEv+0x2a8> */
/* @0x226da4 ldr r0, [sp, #0x38] */
/* @0x226da8 bl 0x22688c <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound> */
/* @0x226dac ldr r3, [r4, #0x804] */
/* @0x226db0 add r0, r3, r5 */
/* @0x226db4 ldr r1, [r0, #0x2bc] */
/* @0x226db8 ldr r8, [r1, #0x38] */
/* @0x226dbc b 0x226c2c <_ZN9COggAudio13SyncDrawDebugEv+0x21c> */
/* @0x226dc0 sbcmi r0, r8, #0 */
/* @0x226dc4 .word 0x38800000 */
/* @0x226dc8 sbcsmi r0, r2, #0 */
/* @0x226dcc andeq r0, r0, r1 */
/* @0x226dd0 stclo p7, c13, [r3], #-40 */
/* @0x226dd4 andseq lr, r2, r0, ror #9 */
/* @0x226dd8 mulseq r12, r12, r8 */
/* @0x226ddc ldrsbeq lr, [r2], -r4 */
/* @0x226de0 andseq lr, r2, r4, lsr r3 */
/* @0x226de4 andseq lr, r2, r12, lsl #7 */
/* @0x226de8 andseq lr, r2, r4, lsr #5 */

/* ── FUNC 0x226dec · COggAudio::DecompressOgg(cAudio_Sound*) · size=720 · insn=180 */
/* @0x226dec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x226df0 sub sp, sp, #828 */
/* @0x226df4 ldr r6, [pc, #0x298] */
/* @0x226df8 mov r4, r1 */
/* @0x226dfc ldr r8, [r1, #0x28] */
/* @0x226e00 ldr r6, [pc, r6] */
/* @0x226e04 cmp r8, #0 */
/* @0x226e08 ldr r3, [r6] */
/* @0x226e0c str r3, [sp, #0x334] */
/* @0x226e10 beq 0x226e20 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x34> */
/* @0x226e14 ldr r8, [r1, #0x2c] */
/* @0x226e18 cmp r8, #0 */
/* @0x226e1c bne 0x226e3c <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x50> */
/* @0x226e20 ldr r1, [sp, #0x334] */
/* @0x226e24 mov r0, r8 */
/* @0x226e28 ldr r3, [r6] */
/* @0x226e2c cmp r1, r3 */
/* @0x226e30 bne 0x227090 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x2a4> */
/* @0x226e34 add sp, sp, #828 */
/* @0x226e38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x226e3c ldr r3, [pc, #0x254] */
/* @0x226e40 add r7, sp, #48 */
/* @0x226e44 ldr r1, [pc, #0x250] */
/* @0x226e48 mov r8, #0 */
/* @0x226e4c ldr r3, [pc, r3] */
/* @0x226e50 ldr r2, [r4] */
/* @0x226e54 add r1, pc, r1 */
/* @0x226e58 ldr r3, [r3] */
/* @0x226e5c str r3, [sp, #0x1c] */
/* @0x226e60 ldr r3, [r3] */
/* @0x226e64 ldr r0, [sp, #0x1c] */
/* @0x226e68 ldr r3, [r3, #0xc] */
/* @0x226e6c blx r3 */
/* @0x226e70 mov r0, r7 */
/* @0x226e74 bl 0x2233f4 <_ZN11SOggChannelC2Ev> */
/* @0x226e78 ldr r1, [pc, #0x220] */
/* @0x226e7c str r4, [sp, #0x2ec] */
/* @0x226e80 ldr r1, [pc, r1] */
/* @0x226e84 str r8, [sp, #0x2f0] */
/* @0x226e88 ldm r1, {r0, r1, r2, r3} */
/* @0x226e8c stm sp, {r0, r1, r2, r3} */
/* @0x226e90 mov r0, r7 */
/* @0x226e94 mov r1, r7 */
/* @0x226e98 mov r2, r8 */
/* @0x226e9c mov r3, r8 */
/* @0x226ea0 bl 0x231c48 <ov_open_callbacks> */
/* @0x226ea4 subs r9, r0, #0 */
/* @0x226ea8 bne 0x227008 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x21c> */
/* @0x226eac mvn r1, #0 */
/* @0x226eb0 mov r0, r7 */
/* @0x226eb4 bl 0x232e28 <ov_info> */
/* @0x226eb8 movw r2, #0x1103 */
/* @0x226ebc movw r3, #0x1101 */
/* @0x226ec0 ldr r1, [r0, #0x4] */
/* @0x226ec4 str r0, [sp, #0x20] */
/* @0x226ec8 mov r0, r7 */
/* @0x226ecc cmp r1, #1 */
/* @0x226ed0 mvn r1, #0 */
/* @0x226ed4 movne r3, r2 */
/* @0x226ed8 movne r5, #4 */
/* @0x226edc moveq r5, #2 */
/* @0x226ee0 str r3, [sp, #0x24] */
/* @0x226ee4 bl 0x23138c <ov_pcm_total> */
/* @0x226ee8 movw r2, #0x29b */
/* @0x226eec mov r3, #1 */
/* @0x226ef0 umull r10, r11, r0, r5 */
/* @0x226ef4 mla r5, r5, r1, r11 */
/* @0x226ef8 ldr r1, [pc, #0x1a4] */
/* @0x226efc strd r10, r11, [sp, #16] */
/* @0x226f00 add r1, pc, r1 */
/* @0x226f04 ldr r0, [sp, #0x10] */
/* @0x226f08 str r5, [sp, #0x14] */
/* @0x226f0c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x226f10 subs r8, r0, #0 */
/* @0x226f14 beq 0x227038 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x24c> */
/* @0x226f18 ldrd r4, r5, [sp, #16] */
/* @0x226f1c str r9, [sp, #0x28] */
/* @0x226f20 cmp r4, #1 */
/* @0x226f24 sbcs r5, r5, #0 */
/* @0x226f28 mov r4, #0 */
/* @0x226f2c mov r5, #0 */
/* @0x226f30 blt 0x227088 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x29c> */
/* @0x226f34 mov r11, r9 */
/* @0x226f38 add r10, sp, #40 */
/* @0x226f3c ldr r9, [sp, #0x10] */
/* @0x226f40 b 0x226f60 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x174> */
/* @0x226f44 add r11, r11, r0 */
/* @0x226f48 ldrd r0, r1, [sp, #16] */
/* @0x226f4c asr r5, r11, #31 */
/* @0x226f50 mov r4, r11 */
/* @0x226f54 cmp r4, r0 */
/* @0x226f58 sbcs r1, r5, r1 */
/* @0x226f5c bge 0x226f80 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x194> */
/* @0x226f60 mov r0, r7 */
/* @0x226f64 add r1, r8, r11 */
/* @0x226f68 rsb r2, r11, r9 */
/* @0x226f6c mov r3, r10 */
/* @0x226f70 bl 0x232ec8 <ov_read> */
/* @0x226f74 cmp r0, #0 */
/* @0x226f78 bgt 0x226f44 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x158> */
/* @0x226f7c bne 0x227064 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x278> */
/* @0x226f80 ldrd r0, r1, [sp, #16] */
/* @0x226f84 cmp r1, r5 */
/* @0x226f88 cmpeq r0, r4 */
/* @0x226f8c beq 0x226fb8 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x1cc> */
/* @0x226f90 ldr r4, [sp, #0x1c] */
/* @0x226f94 mov r2, r11 */
/* @0x226f98 ldr r1, [pc, #0x108] */
/* @0x226f9c ldr r3, [r4] */
/* @0x226fa0 mov r0, r4 */
/* @0x226fa4 ldrd r4, r5, [sp, #16] */
/* @0x226fa8 add r1, pc, r1 */
/* @0x226fac strd r4, r5, [sp] */
/* @0x226fb0 ldr r3, [r3, #0xc] */
/* @0x226fb4 blx r3 */
/* @0x226fb8 add r1, sp, #824 */
/* @0x226fbc mov r3, #0 */
/* @0x226fc0 mov r0, #1 */
/* @0x226fc4 str r3, [r1, #-0x30c]! */
/* @0x226fc8 bl 0xb6af0 <alGenBuffers@plt> */
/* @0x226fcc ldr r5, [sp, #0x20] */
/* @0x226fd0 mov r2, r8 */
/* @0x226fd4 ldr r1, [sp, #0x24] */
/* @0x226fd8 mov r3, r11 */
/* @0x226fdc ldr r0, [sp, #0x2c] */
/* @0x226fe0 ldr lr, [r5, #0x8] */
/* @0x226fe4 str lr, [sp] */
/* @0x226fe8 bl 0xb6afc <alBufferData@plt> */
/* @0x226fec ldr r0, [pc, #0xb8] */
/* @0x226ff0 add r0, pc, r0 */
/* @0x226ff4 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x226ff8 mov r0, r8 */
/* @0x226ffc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x227000 ldr r8, [sp, #0x2c] */
/* @0x227004 b 0x22702c <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x240> */
/* @0x227008 ldr r5, [sp, #0x1c] */
/* @0x22700c mov r2, r9 */
/* @0x227010 ldr r1, [pc, #0x98] */
/* @0x227014 ldr r3, [r4] */
/* @0x227018 ldr r12, [r5] */
/* @0x22701c mov r0, r5 */
/* @0x227020 add r1, pc, r1 */
/* @0x227024 ldr r12, [r12, #0xc] */
/* @0x227028 blx r12 */
/* @0x22702c mov r0, r7 */
/* @0x227030 bl 0x2234d0 <_ZN11SOggChannelD2Ev> */
/* @0x227034 b 0x226e20 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x34> */
/* @0x227038 ldr r11, [sp, #0x1c] */
/* @0x22703c ldr lr, [r4] */
/* @0x227040 ldr r1, [pc, #0x6c] */
/* @0x227044 ldr r12, [r11] */
/* @0x227048 mov r0, r11 */
/* @0x22704c str lr, [sp] */
/* @0x227050 add r1, pc, r1 */
/* @0x227054 ldrd r2, r3, [sp, #16] */
/* @0x227058 ldr r12, [r12, #0xc] */
/* @0x22705c blx r12 */
/* @0x227060 b 0x22702c <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x240> */
/* @0x227064 ldr r10, [sp, #0x1c] */
/* @0x227068 mov r2, r0 */
/* @0x22706c ldr r1, [pc, #0x44] */
/* @0x227070 ldr r3, [r10] */
/* @0x227074 mov r0, r10 */
/* @0x227078 add r1, pc, r1 */
/* @0x22707c ldr r3, [r3, #0xc] */
/* @0x227080 blx r3 */
/* @0x227084 b 0x226f80 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x194> */
/* @0x227088 mov r11, r9 */
/* @0x22708c b 0x226f80 <_ZN9COggAudio13DecompressOggEP12cAudio_Sound+0x194> */
/* @0x227090 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x227094 andseq r6, r12, r0, asr r11 */
/* @0x227098 andseq r6, r12, r8, asr #17 */
/* @0x22709c andseq lr, r2, r12, ror r1 */
/* @0x2270a0 ldrsheq r10, [r12], -r4 */
/* @0x2270a4 andseq lr, r2, r12, lsl #2 */
/* @0x2270a8 ldrsbeq lr, [r2], -r4 */
/* @0x2270ac andseq lr, r2, r4, asr #1 */
/* @0x2270b0 andseq sp, r2, r8, asr #31 */
/* @0x2270b4 ldrsheq sp, [r2], -r0 */
/* @0x2270b8 andseq sp, r2, r4, ror #26 */

/* ── FUNC 0x2270bc · vorbis_block_init · size=40 · insn=10 */
/* @0x2270bc push {r3, r4, r5, lr} */
/* @0x2270c0 mov r4, r1 */
/* @0x2270c4 mov r5, r0 */
/* @0x2270c8 mov r1, #0 */
/* @0x2270cc mov r0, r4 */
/* @0x2270d0 mov r2, #88 */
/* @0x2270d4 bl 0xb65b0 <memset@plt> */
/* @0x2270d8 str r5, [r4, #0x40] */
/* @0x2270dc mov r0, #0 */
/* @0x2270e0 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2270e4 · _vorbis_block_alloc · size=128 · insn=32 */
/* @0x2270e4 push {r3, r4, r5, r6, r7, lr} */
/* @0x2270e8 add r1, r1, #7 */
/* @0x2270ec ldr r6, [r0, #0x48] */
/* @0x2270f0 bic r5, r1, #7 */
/* @0x2270f4 ldr r2, [r0, #0x4c] */
/* @0x2270f8 mov r4, r0 */
/* @0x2270fc add r3, r6, r5 */
/* @0x227100 cmp r3, r2 */
/* @0x227104 ble 0x22715c <_vorbis_block_alloc+0x78> */
/* @0x227108 ldr r7, [r0, #0x44] */
/* @0x22710c cmp r7, #0 */
/* @0x227110 beq 0x227138 <_vorbis_block_alloc+0x54> */
/* @0x227114 mov r0, #8 */
/* @0x227118 bl 0xb6544 <malloc@plt> */
/* @0x22711c ldr r2, [r4, #0x54] */
/* @0x227120 ldr r3, [r4, #0x50] */
/* @0x227124 add r6, r3, r6 */
/* @0x227128 str r7, [r0] */
/* @0x22712c str r2, [r0, #0x4] */
/* @0x227130 str r0, [r4, #0x54] */
/* @0x227134 str r6, [r4, #0x50] */
/* @0x227138 str r5, [r4, #0x4c] */
/* @0x22713c mov r0, r5 */
/* @0x227140 bl 0xb6544 <malloc@plt> */
/* @0x227144 mov r6, #0 */
/* @0x227148 mov r3, r5 */
/* @0x22714c str r0, [r4, #0x44] */
/* @0x227150 str r3, [r4, #0x48] */
/* @0x227154 add r0, r0, r6 */
/* @0x227158 pop {r3, r4, r5, r6, r7, pc} */
/* @0x22715c ldr r0, [r0, #0x44] */
/* @0x227160 b 0x227150 <_vorbis_block_alloc+0x6c> */

/* ── FUNC 0x227164 · _vorbis_block_ripcord · size=164 · insn=41 */
/* @0x227164 push {r3, r4, r5, r6, r7, lr} */
/* @0x227168 mov r7, r0 */
/* @0x22716c ldr r5, [r0, #0x54] */
/* @0x227170 cmp r5, #0 */
/* @0x227174 movne r4, #0 */
/* @0x227178 beq 0x2271c0 <_vorbis_block_ripcord+0x5c> */
/* @0x22717c ldm r5, {r0, r6} */
/* @0x227180 bl 0xb655c <free@plt> */
/* @0x227184 mov r3, r5 */
/* @0x227188 strb r4, [r3], #1 */
/* @0x22718c add r3, r3, #1 */
/* @0x227190 strb r4, [r5, #0x1] */
/* @0x227194 mov r0, r5 */
/* @0x227198 strb r4, [r3], #1 */
/* @0x22719c mov r5, r6 */
/* @0x2271a0 strb r4, [r3], #1 */
/* @0x2271a4 strb r4, [r3], #1 */
/* @0x2271a8 strb r4, [r3], #1 */
/* @0x2271ac strb r4, [r3], #1 */
/* @0x2271b0 strb r4, [r3] */
/* @0x2271b4 bl 0xb655c <free@plt> */
/* @0x2271b8 cmp r6, #0 */
/* @0x2271bc bne 0x22717c <_vorbis_block_ripcord+0x18> */
/* @0x2271c0 ldr r3, [r7, #0x50] */
/* @0x2271c4 cmp r3, #0 */
/* @0x2271c8 beq 0x2271f8 <_vorbis_block_ripcord+0x94> */
/* @0x2271cc ldr r1, [r7, #0x4c] */
/* @0x2271d0 ldr r0, [r7, #0x44] */
/* @0x2271d4 add r1, r3, r1 */
/* @0x2271d8 bl 0xb6c28 <realloc@plt> */
/* @0x2271dc ldr r2, [r7, #0x4c] */
/* @0x2271e0 ldr r3, [r7, #0x50] */
/* @0x2271e4 mov r1, #0 */
/* @0x2271e8 str r1, [r7, #0x50] */
/* @0x2271ec add r3, r2, r3 */
/* @0x2271f0 str r3, [r7, #0x4c] */
/* @0x2271f4 str r0, [r7, #0x44] */
/* @0x2271f8 mov r3, #0 */
/* @0x2271fc str r3, [r7, #0x48] */
/* @0x227200 str r3, [r7, #0x54] */
/* @0x227204 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x227208 · vorbis_block_clear · size=52 · insn=13 */
/* @0x227208 push {r4, lr} */
/* @0x22720c mov r4, r0 */
/* @0x227210 bl 0x227164 <_vorbis_block_ripcord> */
/* @0x227214 ldr r0, [r4, #0x44] */
/* @0x227218 cmp r0, #0 */
/* @0x22721c beq 0x227224 <vorbis_block_clear+0x1c> */
/* @0x227220 bl 0xb655c <free@plt> */
/* @0x227224 mov r0, r4 */
/* @0x227228 mov r1, #0 */
/* @0x22722c mov r2, #88 */
/* @0x227230 bl 0xb65b0 <memset@plt> */
/* @0x227234 mov r0, #0 */
/* @0x227238 pop {r4, pc} */

/* ── FUNC 0x22723c · vorbis_synthesis_restart · size=112 · insn=28 */
/* @0x22723c ldr r12, [r0, #0x48] */
/* @0x227240 mov r1, r0 */
/* @0x227244 str r4, [sp, #-0x4]! */
/* @0x227248 cmp r12, #0 */
/* @0x22724c ldr r3, [r0, #0x4] */
/* @0x227250 beq 0x2272a4 <vorbis_synthesis_restart+0x68> */
/* @0x227254 cmp r3, #0 */
/* @0x227258 beq 0x2272a4 <vorbis_synthesis_restart+0x68> */
/* @0x22725c ldr r3, [r3, #0x1c] */
/* @0x227260 cmp r3, #0 */
/* @0x227264 beq 0x2272a4 <vorbis_synthesis_restart+0x68> */
/* @0x227268 ldr r4, [r3, #0x4] */
/* @0x22726c mvn r0, #0 */
/* @0x227270 str r0, [r1, #0x18] */
/* @0x227274 mov r0, #0 */
/* @0x227278 mvn r2, #0 */
/* @0x22727c mvn r3, #0 */
/* @0x227280 add r4, r4, r4, lsr #31 */
/* @0x227284 strd r2, r3, [r1, #56] */
/* @0x227288 strd r2, r3, [r1, #64] */
/* @0x22728c asr r4, r4, #1 */
/* @0x227290 str r4, [r1, #0x30] */
/* @0x227294 str r4, [r1, #0x14] */
/* @0x227298 strd r2, r3, [r12, #16] */
/* @0x22729c ldr r4, [sp], #4 */
/* @0x2272a0 bx lr */
/* @0x2272a4 mvn r0, #0 */
/* @0x2272a8 b 0x22729c <vorbis_synthesis_restart+0x60> */

/* ── FUNC 0x2272ac · vorbis_dsp_clear · size=292 · insn=73 */
/* @0x2272ac push {r4, r5, r6, r7, r8, lr} */
/* @0x2272b0 subs r7, r0, #0 */
/* @0x2272b4 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x2272b8 ldr r5, [r7, #0x4] */
/* @0x2272bc ldr r3, [r7, #0x8] */
/* @0x2272c0 cmp r5, #0 */
/* @0x2272c4 ldr r6, [r7, #0x48] */
/* @0x2272c8 ldrne r8, [r5, #0x1c] */
/* @0x2272cc moveq r8, r5 */
/* @0x2272d0 cmp r3, #0 */
/* @0x2272d4 beq 0x227324 <vorbis_dsp_clear+0x78> */
/* @0x2272d8 ldr r2, [r5, #0x4] */
/* @0x2272dc cmp r2, #0 */
/* @0x2272e0 ble 0x22730c <vorbis_dsp_clear+0x60> */
/* @0x2272e4 mov r4, #0 */
/* @0x2272e8 ldr r0, [r3, r4, lsl #2] */
/* @0x2272ec add r4, r4, #1 */
/* @0x2272f0 cmp r0, #0 */
/* @0x2272f4 beq 0x227304 <vorbis_dsp_clear+0x58> */
/* @0x2272f8 bl 0xb655c <free@plt> */
/* @0x2272fc ldr r3, [r7, #0x8] */
/* @0x227300 ldr r2, [r5, #0x4] */
/* @0x227304 cmp r2, r4 */
/* @0x227308 bgt 0x2272e8 <vorbis_dsp_clear+0x3c> */
/* @0x22730c mov r0, r3 */
/* @0x227310 bl 0xb655c <free@plt> */
/* @0x227314 ldr r0, [r7, #0xc] */
/* @0x227318 cmp r0, #0 */
/* @0x22731c beq 0x227324 <vorbis_dsp_clear+0x78> */
/* @0x227320 bl 0xb655c <free@plt> */
/* @0x227324 cmp r8, #0 */
/* @0x227328 beq 0x2273bc <vorbis_dsp_clear+0x110> */
/* @0x22732c ldr r0, [r8, #0x8] */
/* @0x227330 cmp r0, #0 */
/* @0x227334 ble 0x2273bc <vorbis_dsp_clear+0x110> */
/* @0x227338 cmp r6, #0 */
/* @0x22733c beq 0x2273a8 <vorbis_dsp_clear+0xfc> */
/* @0x227340 ldr r2, [r6, #0xc] */
/* @0x227344 add r5, r8, #28 */
/* @0x227348 mov r4, #0 */
/* @0x22734c ldr r1, [r5, #0x4]! */
/* @0x227350 cmp r2, #0 */
/* @0x227354 ldr r3, [pc, #0x70] */
/* @0x227358 ldr r1, [r1, #0xc] */
/* @0x22735c add r1, r1, #72 */
/* @0x227360 ldr r1, [r8, r1, lsl #2] */
/* @0x227364 beq 0x227384 <vorbis_dsp_clear+0xd8> */
/* @0x227368 ldr r3, [pc, r3] */
/* @0x22736c ldr r0, [r2, r4, lsl #2] */
/* @0x227370 ldr r3, [r3, r1, lsl #2] */
/* @0x227374 ldr r3, [r3, #0xc] */
/* @0x227378 blx r3 */
/* @0x22737c ldr r0, [r8, #0x8] */
/* @0x227380 ldr r2, [r6, #0xc] */
/* @0x227384 add r4, r4, #1 */
/* @0x227388 cmp r0, r4 */
/* @0x22738c bgt 0x22734c <vorbis_dsp_clear+0xa0> */
/* @0x227390 cmp r2, #0 */
/* @0x227394 beq 0x2273a0 <vorbis_dsp_clear+0xf4> */
/* @0x227398 mov r0, r2 */
/* @0x22739c bl 0xb655c <free@plt> */
/* @0x2273a0 mov r0, r6 */
/* @0x2273a4 bl 0xb655c <free@plt> */
/* @0x2273a8 mov r0, r7 */
/* @0x2273ac mov r1, #0 */
/* @0x2273b0 mov r2, #80 */
/* @0x2273b4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x2273b8 b 0xb65b0 <memset@plt> */
/* @0x2273bc cmp r6, #0 */
/* @0x2273c0 beq 0x2273a8 <vorbis_dsp_clear+0xfc> */
/* @0x2273c4 ldr r2, [r6, #0xc] */
/* @0x2273c8 b 0x227390 <vorbis_dsp_clear+0xe4> */
/* @0x2273cc andseq r10, r12, r8, lsl r1 */

/* ── FUNC 0x2273d0 · vorbis_synthesis_init · size=616 · insn=154 */
/* @0x2273d0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2273d4 mov r6, r1 */
/* @0x2273d8 ldr r5, [r1, #0x1c] */
/* @0x2273dc mov r7, r0 */
/* @0x2273e0 cmp r5, #0 */
/* @0x2273e4 beq 0x2275e8 <vorbis_synthesis_init+0x218> */
/* @0x2273e8 mov r2, #80 */
/* @0x2273ec mov r1, #0 */
/* @0x2273f0 bl 0xb65b0 <memset@plt> */
/* @0x2273f4 mov r0, #1 */
/* @0x2273f8 mov r1, #24 */
/* @0x2273fc bl 0xb6c34 <calloc@plt> */
/* @0x227400 ldr r2, [r5, #0x8] */
/* @0x227404 str r6, [r7, #0x4] */
/* @0x227408 cmp r2, #0 */
/* @0x22740c mov r8, r0 */
/* @0x227410 str r0, [r7, #0x48] */
/* @0x227414 bne 0x22753c <vorbis_synthesis_init+0x16c> */
/* @0x227418 ldr r3, [r5] */
/* @0x22741c mov r0, #0 */
/* @0x227420 str r2, [r8, #0x8] */
/* @0x227424 add r1, r3, r3, lsr #31 */
/* @0x227428 asr r1, r1, #1 */
/* @0x22742c bl 0x233028 <_vorbis_window> */
/* @0x227430 ldr r3, [r5, #0x4] */
/* @0x227434 add r1, r3, r3, lsr #31 */
/* @0x227438 asr r1, r1, #1 */
/* @0x22743c str r0, [r8] */
/* @0x227440 mov r0, #0 */
/* @0x227444 bl 0x233028 <_vorbis_window> */
/* @0x227448 ldr r9, [r5, #0xc20] */
/* @0x22744c cmp r9, #0 */
/* @0x227450 str r0, [r8, #0x4] */
/* @0x227454 beq 0x22755c <vorbis_synthesis_init+0x18c> */
/* @0x227458 ldr r9, [r6, #0x4] */
/* @0x22745c ldr r10, [r5, #0x4] */
/* @0x227460 lsl r4, r9, #2 */
/* @0x227464 str r10, [r7, #0x10] */
/* @0x227468 mov r0, r4 */
/* @0x22746c bl 0xb6544 <malloc@plt> */
/* @0x227470 mov r6, r0 */
/* @0x227474 mov r0, r4 */
/* @0x227478 str r6, [r7, #0x8] */
/* @0x22747c bl 0xb6544 <malloc@plt> */
/* @0x227480 cmp r9, #0 */
/* @0x227484 movgt r4, #0 */
/* @0x227488 str r0, [r7, #0xc] */
/* @0x22748c bgt 0x227498 <vorbis_synthesis_init+0xc8> */
/* @0x227490 b 0x2274b4 <vorbis_synthesis_init+0xe4> */
/* @0x227494 ldr r6, [r7, #0x8] */
/* @0x227498 mov r0, r10 */
/* @0x22749c mov r1, #4 */
/* @0x2274a0 bl 0xb6c34 <calloc@plt> */
/* @0x2274a4 str r0, [r6, r4, lsl #2] */
/* @0x2274a8 add r4, r4, #1 */
/* @0x2274ac cmp r4, r9 */
/* @0x2274b0 bne 0x227494 <vorbis_synthesis_init+0xc4> */
/* @0x2274b4 ldr r6, [r5, #0x8] */
/* @0x2274b8 mov r4, #0 */
/* @0x2274bc mov r1, #4 */
/* @0x2274c0 str r4, [r7, #0x24] */
/* @0x2274c4 str r4, [r7, #0x28] */
/* @0x2274c8 mov r0, r6 */
/* @0x2274cc bl 0xb6c34 <calloc@plt> */
/* @0x2274d0 cmp r6, r4 */
/* @0x2274d4 str r0, [r8, #0xc] */
/* @0x2274d8 ble 0x22752c <vorbis_synthesis_init+0x15c> */
/* @0x2274dc ldr r9, [pc, #0x150] */
/* @0x2274e0 add r6, r5, #28 */
/* @0x2274e4 mov r10, r0 */
/* @0x2274e8 ldr r9, [pc, r9] */
/* @0x2274ec b 0x2274f4 <vorbis_synthesis_init+0x124> */
/* @0x2274f0 ldr r10, [r8, #0xc] */
/* @0x2274f4 ldr r1, [r6, #0x4]! */
/* @0x2274f8 mov r0, r7 */
/* @0x2274fc ldr r3, [r1, #0xc] */
/* @0x227500 add r3, r5, r3, lsl #2 */
/* @0x227504 ldr r12, [r3, #0x120] */
/* @0x227508 ldr r2, [r3, #0x220] */
/* @0x22750c ldr r3, [r9, r12, lsl #2] */
/* @0x227510 ldr r3, [r3, #0x4] */
/* @0x227514 blx r3 */
/* @0x227518 ldr r3, [r5, #0x8] */
/* @0x22751c str r0, [r10, r4, lsl #2] */
/* @0x227520 add r4, r4, #1 */
/* @0x227524 cmp r4, r3 */
/* @0x227528 blt 0x2274f0 <vorbis_synthesis_init+0x120> */
/* @0x22752c mov r0, r7 */
/* @0x227530 bl 0x22723c <vorbis_synthesis_restart> */
/* @0x227534 mov r0, #0 */
/* @0x227538 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22753c subs r3, r2, #1 */
/* @0x227540 moveq r2, r3 */
/* @0x227544 beq 0x227418 <vorbis_synthesis_init+0x48> */
/* @0x227548 mov r2, #0 */
/* @0x22754c lsrs r3, r3, #1 */
/* @0x227550 add r2, r2, #1 */
/* @0x227554 bne 0x22754c <vorbis_synthesis_init+0x17c> */
/* @0x227558 b 0x227418 <vorbis_synthesis_init+0x48> */
/* @0x22755c ldr r4, [r5, #0x1c] */
/* @0x227560 mov r1, #52 */
/* @0x227564 mov r0, r4 */
/* @0x227568 bl 0xb6c34 <calloc@plt> */
/* @0x22756c cmp r4, #0 */
/* @0x227570 str r0, [r5, #0xc20] */
/* @0x227574 ble 0x227458 <vorbis_synthesis_init+0x88> */
/* @0x227578 ldr r1, [r5, #0x820] */
/* @0x22757c cmp r1, #0 */
/* @0x227580 beq 0x2275f4 <vorbis_synthesis_init+0x224> */
/* @0x227584 mov r10, r9 */
/* @0x227588 mov r4, r5 */
/* @0x22758c b 0x2275bc <vorbis_synthesis_init+0x1ec> */
/* @0x227590 ldr r0, [r4, #0x820] */
/* @0x227594 bl 0x22f554 <vorbis_staticbook_destroy> */
/* @0x227598 str r11, [r4, #0x820] */
/* @0x22759c ldr r3, [r5, #0x1c] */
/* @0x2275a0 cmp r10, r3 */
/* @0x2275a4 bge 0x227458 <vorbis_synthesis_init+0x88> */
/* @0x2275a8 ldr r1, [r4, #0x824] */
/* @0x2275ac add r4, r4, #4 */
/* @0x2275b0 cmp r1, #0 */
/* @0x2275b4 beq 0x2275f0 <vorbis_synthesis_init+0x220> */
/* @0x2275b8 ldr r0, [r5, #0xc20] */
/* @0x2275bc add r0, r0, r9 */
/* @0x2275c0 add r10, r10, #1 */
/* @0x2275c4 bl 0x22f604 <vorbis_book_init_decode> */
/* @0x2275c8 add r9, r9, #52 */
/* @0x2275cc subs r11, r0, #0 */
/* @0x2275d0 beq 0x227590 <vorbis_synthesis_init+0x1c0> */
/* @0x2275d4 ldr r3, [r5, #0x1c] */
/* @0x2275d8 cmp r3, #0 */
/* @0x2275dc bgt 0x2275f0 <vorbis_synthesis_init+0x220> */
/* @0x2275e0 mov r0, r7 */
/* @0x2275e4 bl 0x2272ac <vorbis_dsp_clear> */
/* @0x2275e8 mov r0, #1 */
/* @0x2275ec pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2275f0 ldr r1, [r5, #0x820] */
/* @0x2275f4 add r6, r5, #2080 */
/* @0x2275f8 mov r4, #0 */
/* @0x2275fc add r6, r6, #4 */
/* @0x227600 mov r8, r4 */
/* @0x227604 b 0x22760c <vorbis_synthesis_init+0x23c> */
/* @0x227608 ldr r1, [r6], #4 */
/* @0x22760c cmp r1, #0 */
/* @0x227610 add r4, r4, #1 */
/* @0x227614 mov r0, r1 */
/* @0x227618 beq 0x227624 <vorbis_synthesis_init+0x254> */
/* @0x22761c bl 0x22f554 <vorbis_staticbook_destroy> */
/* @0x227620 str r8, [r6, #-0x4] */
/* @0x227624 ldr r3, [r5, #0x1c] */
/* @0x227628 cmp r4, r3 */
/* @0x22762c blt 0x227608 <vorbis_synthesis_init+0x238> */
/* @0x227630 b 0x2275e0 <vorbis_synthesis_init+0x210> */
/* @0x227634 mulseq r12, r8, pc */

/* ── FUNC 0x227638 · vorbis_synthesis_blockin · size=1608 · insn=402 */
/* @0x227638 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x22763c sub sp, sp, #112 */
/* @0x227640 ldr r7, [r0, #0x4] */
/* @0x227644 mov r4, r0 */
/* @0x227648 ldr r12, [r0, #0x18] */
/* @0x22764c ldr r3, [r0, #0x14] */
/* @0x227650 str r1, [sp, #0x38] */
/* @0x227654 ldr r0, [r0, #0x48] */
/* @0x227658 cmp r3, r12 */
/* @0x22765c ldr r1, [r7, #0x1c] */
/* @0x227660 str r0, [sp, #0x48] */
/* @0x227664 str r1, [sp, #0x2c] */
/* @0x227668 ble 0x227674 <vorbis_synthesis_blockin+0x3c> */
/* @0x22766c cmn r12, #1 */
/* @0x227670 bne 0x227c5c <vorbis_synthesis_blockin+0x624> */
/* @0x227674 ldr r5, [r4, #0x28] */
/* @0x227678 mvn r0, #0 */
/* @0x22767c ldr r6, [sp, #0x38] */
/* @0x227680 mvn r1, #0 */
/* @0x227684 ldrd r2, r3, [r4, #64] */
/* @0x227688 str r5, [sp, #0xc] */
/* @0x22768c mvn r5, #0 */
/* @0x227690 ldr r6, [r6, #0x1c] */
/* @0x227694 cmp r3, r1 */
/* @0x227698 cmpeq r2, r0 */
/* @0x22769c ldr r8, [sp, #0xc] */
/* @0x2276a0 str r5, [r4, #0x2c] */
/* @0x2276a4 str r6, [sp, #0x8] */
/* @0x2276a8 str r8, [r4, #0x24] */
/* @0x2276ac str r6, [r4, #0x28] */
/* @0x2276b0 beq 0x227bbc <vorbis_synthesis_blockin+0x584> */
/* @0x2276b4 ldr r5, [sp, #0x38] */
/* @0x2276b8 adds r2, r2, #1 */
/* @0x2276bc adc r3, r3, #0 */
/* @0x2276c0 ldrd r0, r1, [r5, #56] */
/* @0x2276c4 cmp r3, r1 */
/* @0x2276c8 cmpeq r2, r0 */
/* @0x2276cc movne r2, r0 */
/* @0x2276d0 movne r0, r1 */
/* @0x2276d4 beq 0x227c40 <vorbis_synthesis_blockin+0x608> */
/* @0x2276d8 mvn r1, #0 */
/* @0x2276dc str r1, [sp, #0x30] */
/* @0x2276e0 str r1, [sp, #0x34] */
/* @0x2276e4 ldrd r8, r9, [sp, #48] */
/* @0x2276e8 str r1, [r4, #0x38] */
/* @0x2276ec str r1, [r4, #0x3c] */
/* @0x2276f0 strd r8, r9, [sp, #88] */
/* @0x2276f4 ldr r9, [sp, #0x48] */
/* @0x2276f8 str r1, [r9, #0x10] */
/* @0x2276fc str r1, [r9, #0x14] */
/* @0x227700 ldr r1, [sp, #0x38] */
/* @0x227704 ldr r1, [r1] */
/* @0x227708 str r2, [r4, #0x40] */
/* @0x22770c cmp r1, #0 */
/* @0x227710 str r0, [r4, #0x44] */
/* @0x227714 str r1, [sp, #0x10] */
/* @0x227718 beq 0x227920 <vorbis_synthesis_blockin+0x2e8> */
/* @0x22771c ldr r3, [sp, #0x2c] */
/* @0x227720 ldr r6, [sp, #0x8] */
/* @0x227724 ldr r5, [r4, #0x30] */
/* @0x227728 ldr r2, [r3, #0x4] */
/* @0x22772c ldr r6, [r3, r6, lsl #2] */
/* @0x227730 cmp r5, #0 */
/* @0x227734 ldr r3, [r3] */
/* @0x227738 add r2, r2, r2, lsr #31 */
/* @0x22773c ldr r1, [r7, #0x4] */
/* @0x227740 str r5, [sp, #0x64] */
/* @0x227744 asr r2, r2, #1 */
/* @0x227748 str r2, [sp, #0x24] */
/* @0x22774c ldr r8, [sp, #0x24] */
/* @0x227750 add r2, r6, r6, lsr #31 */
/* @0x227754 ldr r9, [sp, #0x24] */
/* @0x227758 add r3, r3, r3, lsr #31 */
/* @0x22775c asr r2, r2, #1 */
/* @0x227760 str r6, [sp, #0x44] */
/* @0x227764 movne r8, #0 */
/* @0x227768 asr r3, r3, #1 */
/* @0x22776c moveq r9, #0 */
/* @0x227770 cmp r1, #0 */
/* @0x227774 str r8, [sp, #0x50] */
/* @0x227778 str r9, [sp, #0x68] */
/* @0x22777c str r2, [sp, #0x14] */
/* @0x227780 str r3, [sp, #0x18] */
/* @0x227784 ble 0x2278c4 <vorbis_synthesis_blockin+0x28c> */
/* @0x227788 ldr r12, [sp, #0x24] */
/* @0x22778c mov r0, r3 */
/* @0x227790 add r3, r3, r3, lsr #31 */
/* @0x227794 ldr r9, [sp, #0x50] */
/* @0x227798 bic r1, r0, r0, asr #31 */
/* @0x22779c ldr r5, [r4, #0x8] */
/* @0x2277a0 add r2, r12, r12, lsr #31 */
/* @0x2277a4 ldr r0, [sp, #0x14] */
/* @0x2277a8 ldr r12, [sp, #0x68] */
/* @0x2277ac lsl r8, r1, #2 */
/* @0x2277b0 asr r2, r2, #1 */
/* @0x2277b4 str r1, [sp, #0x40] */
/* @0x2277b8 add r6, r2, r3, asr #1 */
/* @0x2277bc str r6, [sp, #0x4c] */
/* @0x2277c0 sub r3, r2, r3, asr #1 */
/* @0x2277c4 rsb r10, r1, r6 */
/* @0x2277c8 add r2, r9, r3 */
/* @0x2277cc ldr r6, [sp, #0x18] */
/* @0x2277d0 lsl r3, r3, #2 */
/* @0x2277d4 str r3, [sp, #0x60] */
/* @0x2277d8 ldr r3, [sp, #0x24] */
/* @0x2277dc lsl r1, r9, #2 */
/* @0x2277e0 lsl r2, r2, #2 */
/* @0x2277e4 str r5, [sp, #0x20] */
/* @0x2277e8 str r2, [sp, #0x54] */
/* @0x2277ec mov r5, #0 */
/* @0x2277f0 lsl r10, r10, #2 */
/* @0x2277f4 lsl r2, r0, #2 */
/* @0x2277f8 lsl r9, r3, #2 */
/* @0x2277fc str r1, [sp, #0x28] */
/* @0x227800 str r4, [sp, #0x6c] */
/* @0x227804 lsl r1, r6, #2 */
/* @0x227808 mov r4, r7 */
/* @0x22780c mov r6, r5 */
/* @0x227810 lsl r12, r12, #2 */
/* @0x227814 str r8, [sp, #0x3c] */
/* @0x227818 str r12, [sp, #0x1c] */
/* @0x22781c ldr r8, [sp, #0xc] */
/* @0x227820 cmp r8, #0 */
/* @0x227824 beq 0x227a84 <vorbis_synthesis_blockin+0x44c> */
/* @0x227828 ldr r12, [sp, #0x8] */
/* @0x22782c cmp r12, #0 */
/* @0x227830 beq 0x227b64 <vorbis_synthesis_blockin+0x52c> */
/* @0x227834 ldr r3, [sp, #0x20] */
/* @0x227838 ldr r0, [sp, #0x24] */
/* @0x22783c ldr r12, [sp, #0x10] */
/* @0x227840 ldr r8, [r3, r5] */
/* @0x227844 cmp r0, #0 */
/* @0x227848 ldr r3, [sp, #0x28] */
/* @0x22784c ldr r11, [r12, r5] */
/* @0x227850 add r0, r8, r3 */
/* @0x227854 ble 0x227878 <vorbis_synthesis_blockin+0x240> */
/* @0x227858 mov r3, #0 */
/* @0x22785c ldr r7, [r0, r3] */
/* @0x227860 ldr r12, [r11, r3] */
/* @0x227864 add r12, r7, r12 */
/* @0x227868 str r12, [r0, r3] */
/* @0x22786c add r3, r3, #4 */
/* @0x227870 cmp r3, r9 */
/* @0x227874 bne 0x22785c <vorbis_synthesis_blockin+0x224> */
/* @0x227878 ldr r12, [sp, #0x14] */
/* @0x22787c add r11, r11, r2 */
/* @0x227880 ldr r0, [sp, #0x1c] */
/* @0x227884 cmp r12, #0 */
/* @0x227888 add r8, r8, r0 */
/* @0x22788c movgt r3, #0 */
/* @0x227890 ble 0x2278a8 <vorbis_synthesis_blockin+0x270> */
/* @0x227894 ldr r0, [r11, r3] */
/* @0x227898 str r0, [r8, r3] */
/* @0x22789c add r3, r3, #4 */
/* @0x2278a0 cmp r3, r2 */
/* @0x2278a4 bne 0x227894 <vorbis_synthesis_blockin+0x25c> */
/* @0x2278a8 ldr r3, [r4, #0x4] */
/* @0x2278ac add r6, r6, #1 */
/* @0x2278b0 add r5, r5, #4 */
/* @0x2278b4 cmp r3, r6 */
/* @0x2278b8 bgt 0x22781c <vorbis_synthesis_blockin+0x1e4> */
/* @0x2278bc ldr r4, [sp, #0x6c] */
/* @0x2278c0 ldr r12, [r4, #0x18] */
/* @0x2278c4 ldr r1, [sp, #0x64] */
/* @0x2278c8 cmp r1, #0 */
/* @0x2278cc ldreq r2, [sp, #0x24] */
/* @0x2278d0 movne r3, #0 */
/* @0x2278d4 strne r3, [r4, #0x30] */
/* @0x2278d8 streq r2, [r4, #0x30] */
/* @0x2278dc cmn r12, #1 */
/* @0x2278e0 beq 0x227be0 <vorbis_synthesis_blockin+0x5a8> */
/* @0x2278e4 ldr r5, [sp, #0xc] */
/* @0x2278e8 ldr r6, [sp, #0x2c] */
/* @0x2278ec ldr r8, [sp, #0x44] */
/* @0x2278f0 ldr r9, [sp, #0x50] */
/* @0x2278f4 ldr r3, [r6, r5, lsl #2] */
/* @0x2278f8 cmp r8, #0 */
/* @0x2278fc add r2, r8, #3 */
/* @0x227900 add r1, r3, #3 */
/* @0x227904 movge r2, r8 */
/* @0x227908 cmp r3, #0 */
/* @0x22790c str r9, [r4, #0x18] */
/* @0x227910 movlt r3, r1 */
/* @0x227914 add r3, r9, r3, asr #2 */
/* @0x227918 add r2, r3, r2, asr #2 */
/* @0x22791c str r2, [r4, #0x14] */
/* @0x227920 ldrd r0, r1, [sp, #88] */
/* @0x227924 mvn r2, #0 */
/* @0x227928 mvn r3, #0 */
/* @0x22792c cmp r1, r3 */
/* @0x227930 cmpeq r0, r2 */
/* @0x227934 beq 0x227bcc <vorbis_synthesis_blockin+0x594> */
/* @0x227938 ldr r3, [sp, #0x8] */
/* @0x22793c ldr r5, [sp, #0x2c] */
/* @0x227940 ldr r6, [sp, #0xc] */
/* @0x227944 ldr r8, [sp, #0x48] */
/* @0x227948 ldr r2, [r5, r3, lsl #2] */
/* @0x22794c ldr r3, [r5, r6, lsl #2] */
/* @0x227950 add r1, r2, #3 */
/* @0x227954 cmp r2, #0 */
/* @0x227958 movlt r2, r1 */
/* @0x22795c add r1, r3, #3 */
/* @0x227960 cmp r3, #0 */
/* @0x227964 asr r2, r2, #2 */
/* @0x227968 movlt r3, r1 */
/* @0x22796c add r1, r2, r3, asr #2 */
/* @0x227970 ldrd r2, r3, [sp, #88] */
/* @0x227974 adds r2, r2, r1 */
/* @0x227978 adc r3, r3, r1, asr #31 */
/* @0x22797c strd r2, r3, [r8, #16] */
/* @0x227980 ldrd r0, r1, [sp, #48] */
/* @0x227984 mvn r2, #0 */
/* @0x227988 mvn r3, #0 */
/* @0x22798c cmp r1, r3 */
/* @0x227990 cmpeq r0, r2 */
/* @0x227994 beq 0x227a44 <vorbis_synthesis_blockin+0x40c> */
/* @0x227998 ldr r6, [sp, #0x2c] */
/* @0x22799c ldr r5, [sp, #0x8] */
/* @0x2279a0 ldr r8, [sp, #0xc] */
/* @0x2279a4 ldr r9, [sp, #0x38] */
/* @0x2279a8 ldr r0, [r6, r5, lsl #2] */
/* @0x2279ac ldr r1, [r6, r8, lsl #2] */
/* @0x2279b0 add r12, r0, #3 */
/* @0x2279b4 cmp r0, #0 */
/* @0x2279b8 ldrd r6, r7, [r9, #48] */
/* @0x2279bc movlt r0, r12 */
/* @0x2279c0 add r12, r1, #3 */
/* @0x2279c4 cmp r1, #0 */
/* @0x2279c8 asr r0, r0, #2 */
/* @0x2279cc movlt r1, r12 */
/* @0x2279d0 add r12, r0, r1, asr #2 */
/* @0x2279d4 ldrd r0, r1, [sp, #48] */
/* @0x2279d8 adds r0, r0, r12 */
/* @0x2279dc adc r1, r1, r12, asr #31 */
/* @0x2279e0 cmp r7, r3 */
/* @0x2279e4 cmpeq r6, r2 */
/* @0x2279e8 strd r0, r1, [r4, #56] */
/* @0x2279ec beq 0x227a5c <vorbis_synthesis_blockin+0x424> */
/* @0x2279f0 cmp r1, r7 */
/* @0x2279f4 cmpeq r0, r6 */
/* @0x2279f8 beq 0x227a5c <vorbis_synthesis_blockin+0x424> */
/* @0x2279fc cmp r6, r0 */
/* @0x227a00 sbcs r12, r7, r1 */
/* @0x227a04 bge 0x227bac <vorbis_synthesis_blockin+0x574> */
/* @0x227a08 subs r2, r0, r6 */
/* @0x227a0c beq 0x227bac <vorbis_synthesis_blockin+0x574> */
/* @0x227a10 ldr r3, [sp, #0x38] */
/* @0x227a14 ldr r0, [r3, #0x2c] */
/* @0x227a18 cmp r0, #0 */
/* @0x227a1c beq 0x227bb4 <vorbis_synthesis_blockin+0x57c> */
/* @0x227a20 ldr r3, [r4, #0x14] */
/* @0x227a24 ldr r1, [r4, #0x18] */
/* @0x227a28 rsb r1, r1, r3 */
/* @0x227a2c cmp r2, r1 */
/* @0x227a30 movge r2, r1 */
/* @0x227a34 bic r2, r2, r2, asr #31 */
/* @0x227a38 rsb r3, r2, r3 */
/* @0x227a3c str r3, [r4, #0x14] */
/* @0x227a40 b 0x227bb4 <vorbis_synthesis_blockin+0x57c> */
/* @0x227a44 ldr r1, [sp, #0x38] */
/* @0x227a48 ldrd r8, r9, [sp, #48] */
/* @0x227a4c ldrd r2, r3, [r1, #48] */
/* @0x227a50 cmp r3, r9 */
/* @0x227a54 cmpeq r2, r8 */
/* @0x227a58 bne 0x227bf0 <vorbis_synthesis_blockin+0x5b8> */
/* @0x227a5c ldr r9, [sp, #0x38] */
/* @0x227a60 ldr r0, [r9, #0x2c] */
/* @0x227a64 cmp r0, #0 */
/* @0x227a68 beq 0x227a78 <vorbis_synthesis_blockin+0x440> */
/* @0x227a6c mov r0, #0 */
/* @0x227a70 mov r3, #1 */
/* @0x227a74 str r3, [r4, #0x20] */
/* @0x227a78 add sp, sp, #112 */
/* @0x227a7c pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x227a80 bx lr */
/* @0x227a84 ldr r8, [sp, #0x8] */
/* @0x227a88 cmp r8, #0 */
/* @0x227a8c beq 0x227b1c <vorbis_synthesis_blockin+0x4e4> */
/* @0x227a90 ldr r0, [sp, #0x20] */
/* @0x227a94 ldr r3, [sp, #0x10] */
/* @0x227a98 ldr r12, [sp, #0x18] */
/* @0x227a9c ldr r8, [r0, r5] */
/* @0x227aa0 ldr r11, [r3, r5] */
/* @0x227aa4 cmp r12, #0 */
/* @0x227aa8 ldr r3, [sp, #0x60] */
/* @0x227aac ldr r12, [sp, #0x28] */
/* @0x227ab0 add r7, r11, r3 */
/* @0x227ab4 add r0, r8, r12 */
/* @0x227ab8 ble 0x227ae4 <vorbis_synthesis_blockin+0x4ac> */
/* @0x227abc ldr r3, [sp, #0xc] */
/* @0x227ac0 str r2, [sp, #0x4] */
/* @0x227ac4 ldr r12, [r0, r3] */
/* @0x227ac8 ldr r2, [r7, r3] */
/* @0x227acc add r12, r12, r2 */
/* @0x227ad0 str r12, [r0, r3] */
/* @0x227ad4 add r3, r3, #4 */
/* @0x227ad8 cmp r1, r3 */
/* @0x227adc bne 0x227ac4 <vorbis_synthesis_blockin+0x48c> */
/* @0x227ae0 ldr r2, [sp, #0x4] */
/* @0x227ae4 ldr r3, [sp, #0x40] */
/* @0x227ae8 ldr r12, [sp, #0x4c] */
/* @0x227aec cmp r3, r12 */
/* @0x227af0 bge 0x227878 <vorbis_synthesis_blockin+0x240> */
/* @0x227af4 ldr r3, [sp, #0x3c] */
/* @0x227af8 add r7, r7, r3 */
/* @0x227afc add r0, r0, r3 */
/* @0x227b00 mov r3, #0 */
/* @0x227b04 ldr r12, [r7, r3] */
/* @0x227b08 str r12, [r0, r3] */
/* @0x227b0c add r3, r3, #4 */
/* @0x227b10 cmp r3, r10 */
/* @0x227b14 bne 0x227b04 <vorbis_synthesis_blockin+0x4cc> */
/* @0x227b18 b 0x227878 <vorbis_synthesis_blockin+0x240> */
/* @0x227b1c ldr r12, [sp, #0x20] */
/* @0x227b20 ldr r8, [sp, #0x18] */
/* @0x227b24 ldr r0, [sp, #0x10] */
/* @0x227b28 cmp r8, #0 */
/* @0x227b2c ldr r3, [sp, #0x28] */
/* @0x227b30 ldr r8, [r12, r5] */
/* @0x227b34 ldr r11, [r0, r5] */
/* @0x227b38 add r0, r8, r3 */
/* @0x227b3c ble 0x227878 <vorbis_synthesis_blockin+0x240> */
/* @0x227b40 ldr r3, [sp, #0x8] */
/* @0x227b44 ldr r7, [r0, r3] */
/* @0x227b48 ldr r12, [r11, r3] */
/* @0x227b4c add r12, r7, r12 */
/* @0x227b50 str r12, [r0, r3] */
/* @0x227b54 add r3, r3, #4 */
/* @0x227b58 cmp r1, r3 */
/* @0x227b5c bne 0x227b44 <vorbis_synthesis_blockin+0x50c> */
/* @0x227b60 b 0x227878 <vorbis_synthesis_blockin+0x240> */
/* @0x227b64 ldr r12, [sp, #0x20] */
/* @0x227b68 ldr r8, [sp, #0x18] */
/* @0x227b6c ldr r0, [sp, #0x10] */
/* @0x227b70 cmp r8, #0 */
/* @0x227b74 ldr r3, [sp, #0x54] */
/* @0x227b78 ldr r8, [r12, r5] */
/* @0x227b7c ldr r11, [r0, r5] */
/* @0x227b80 add r0, r8, r3 */
/* @0x227b84 ble 0x227878 <vorbis_synthesis_blockin+0x240> */
/* @0x227b88 ldr r3, [sp, #0x8] */
/* @0x227b8c ldr r7, [r0, r3] */
/* @0x227b90 ldr r12, [r11, r3] */
/* @0x227b94 add r12, r7, r12 */
/* @0x227b98 str r12, [r0, r3] */
/* @0x227b9c add r3, r3, #4 */
/* @0x227ba0 cmp r3, r1 */
/* @0x227ba4 bne 0x227b8c <vorbis_synthesis_blockin+0x554> */
/* @0x227ba8 b 0x227878 <vorbis_synthesis_blockin+0x240> */
/* @0x227bac ldr r1, [sp, #0x38] */
/* @0x227bb0 ldr r0, [r1, #0x2c] */
/* @0x227bb4 strd r6, r7, [r4, #56] */
/* @0x227bb8 b 0x227a64 <vorbis_synthesis_blockin+0x42c> */
/* @0x227bbc ldr r9, [sp, #0x38] */
/* @0x227bc0 ldr r2, [r9, #0x38] */
/* @0x227bc4 ldr r0, [r9, #0x3c] */
/* @0x227bc8 b 0x2276d8 <vorbis_synthesis_blockin+0xa0> */
/* @0x227bcc ldr r1, [sp, #0x48] */
/* @0x227bd0 mov r2, #0 */
/* @0x227bd4 mov r3, #0 */
/* @0x227bd8 strd r2, r3, [r1, #16] */
/* @0x227bdc b 0x227980 <vorbis_synthesis_blockin+0x348> */
/* @0x227be0 ldr r3, [sp, #0x68] */
/* @0x227be4 str r3, [r4, #0x18] */
/* @0x227be8 str r3, [r4, #0x14] */
/* @0x227bec b 0x227920 <vorbis_synthesis_blockin+0x2e8> */
/* @0x227bf0 ldr r12, [sp, #0x48] */
/* @0x227bf4 ldrd r6, r7, [r12, #16] */
/* @0x227bf8 strd r2, r3, [r4, #56] */
/* @0x227bfc cmp r2, r6 */
/* @0x227c00 sbcs r0, r3, r7 */
/* @0x227c04 bge 0x227a5c <vorbis_synthesis_blockin+0x424> */
/* @0x227c08 ldr r1, [sp, #0x38] */
/* @0x227c0c rsb r2, r2, r6 */
/* @0x227c10 bic r2, r2, r2, asr #31 */
/* @0x227c14 ldr r0, [r1, #0x2c] */
/* @0x227c18 cmp r0, #0 */
/* @0x227c1c beq 0x227c64 <vorbis_synthesis_blockin+0x62c> */
/* @0x227c20 ldr r3, [r4, #0x14] */
/* @0x227c24 ldr r1, [r4, #0x18] */
/* @0x227c28 rsb r1, r1, r3 */
/* @0x227c2c cmp r2, r1 */
/* @0x227c30 movge r2, r1 */
/* @0x227c34 rsb r3, r2, r3 */
/* @0x227c38 str r3, [r4, #0x14] */
/* @0x227c3c b 0x227a6c <vorbis_synthesis_blockin+0x434> */
/* @0x227c40 ldr r9, [sp, #0x48] */
/* @0x227c44 ldrd r0, r1, [r4, #56] */
/* @0x227c48 ldrd r8, r9, [r9, #16] */
/* @0x227c4c strd r0, r1, [sp, #48] */
/* @0x227c50 mov r0, r3 */
/* @0x227c54 strd r8, r9, [sp, #88] */
/* @0x227c58 b 0x227700 <vorbis_synthesis_blockin+0xc8> */
/* @0x227c5c mvn r0, #130 */
/* @0x227c60 b 0x227a78 <vorbis_synthesis_blockin+0x440> */
/* @0x227c64 ldr r1, [r4, #0x18] */
/* @0x227c68 ldr r3, [r4, #0x14] */
/* @0x227c6c add r2, r2, r1 */
/* @0x227c70 str r2, [r4, #0x18] */
/* @0x227c74 cmp r2, r3 */
/* @0x227c78 strgt r3, [r4, #0x18] */
/* @0x227c7c b 0x227a78 <vorbis_synthesis_blockin+0x440> */

/* ── FUNC 0x227c80 · vorbis_synthesis_pcmout · size=124 · insn=31 */
/* @0x227c80 push {r4, r5, r6, r7} */
/* @0x227c84 ldr r6, [r0, #0x18] */
/* @0x227c88 ldr r3, [r0, #0x4] */
/* @0x227c8c cmp r6, #0 */
/* @0x227c90 blt 0x227cf0 <vorbis_synthesis_pcmout+0x70> */
/* @0x227c94 ldr r7, [r0, #0x14] */
/* @0x227c98 cmp r6, r7 */
/* @0x227c9c bge 0x227cf0 <vorbis_synthesis_pcmout+0x70> */
/* @0x227ca0 cmp r1, #0 */
/* @0x227ca4 beq 0x227ce4 <vorbis_synthesis_pcmout+0x64> */
/* @0x227ca8 ldr r4, [r3, #0x4] */
/* @0x227cac cmp r4, #0 */
/* @0x227cb0 lslgt r5, r6, #2 */
/* @0x227cb4 movgt r3, #0 */
/* @0x227cb8 ble 0x227cdc <vorbis_synthesis_pcmout+0x5c> */
/* @0x227cbc ldr r12, [r0, #0x8] */
/* @0x227cc0 ldr r2, [r0, #0xc] */
/* @0x227cc4 ldr r12, [r12, r3, lsl #2] */
/* @0x227cc8 add r12, r12, r5 */
/* @0x227ccc str r12, [r2, r3, lsl #2] */
/* @0x227cd0 add r3, r3, #1 */
/* @0x227cd4 cmp r3, r4 */
/* @0x227cd8 bne 0x227cbc <vorbis_synthesis_pcmout+0x3c> */
/* @0x227cdc ldr r3, [r0, #0xc] */
/* @0x227ce0 str r3, [r1] */
/* @0x227ce4 rsb r0, r6, r7 */
/* @0x227ce8 pop {r4, r5, r6, r7} */
/* @0x227cec bx lr */
/* @0x227cf0 mov r0, #0 */
/* @0x227cf4 pop {r4, r5, r6, r7} */
/* @0x227cf8 bx lr */

/* ── FUNC 0x227cfc · vorbis_synthesis_read · size=52 · insn=13 */
/* @0x227cfc cmp r1, #0 */
/* @0x227d00 bne 0x227d14 <vorbis_synthesis_read+0x18> */
/* @0x227d04 ldr r1, [r0, #0x18] */
/* @0x227d08 str r1, [r0, #0x18] */
/* @0x227d0c mov r0, #0 */
/* @0x227d10 bx lr */
/* @0x227d14 ldr r2, [r0, #0x18] */
/* @0x227d18 ldr r3, [r0, #0x14] */
/* @0x227d1c add r1, r1, r2 */
/* @0x227d20 cmp r1, r3 */
/* @0x227d24 ble 0x227d08 <vorbis_synthesis_read+0xc> */
/* @0x227d28 mvn r0, #130 */
/* @0x227d2c bx lr */

/* ── FUNC 0x227d30 · vorbis_staticbook_unpack · size=928 · insn=232 */
/* @0x227d30 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x227d34 mov r1, #36 */
/* @0x227d38 mov r6, r0 */
/* @0x227d3c mov r0, #1 */
/* @0x227d40 bl 0xb6c34 <calloc@plt> */
/* @0x227d44 mov r1, #24 */
/* @0x227d48 mov r5, r0 */
/* @0x227d4c mov r0, r6 */
/* @0x227d50 bl 0x233b28 <oggpack_read> */
/* @0x227d54 movw r3, #0x4342 */
/* @0x227d58 movt r3, #0x56 */
/* @0x227d5c cmp r0, r3 */
/* @0x227d60 bne 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227d64 mov r1, #16 */
/* @0x227d68 mov r0, r6 */
/* @0x227d6c bl 0x233b28 <oggpack_read> */
/* @0x227d70 mov r1, #24 */
/* @0x227d74 str r0, [r5] */
/* @0x227d78 mov r0, r6 */
/* @0x227d7c bl 0x233b28 <oggpack_read> */
/* @0x227d80 cmn r0, #1 */
/* @0x227d84 str r0, [r5, #0x4] */
/* @0x227d88 beq 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227d8c ldr r0, [r5] */
/* @0x227d90 bl 0x22eaf0 <_ilog> */
/* @0x227d94 mov r4, r0 */
/* @0x227d98 ldr r0, [r5, #0x4] */
/* @0x227d9c bl 0x22eaf0 <_ilog> */
/* @0x227da0 add r0, r4, r0 */
/* @0x227da4 cmp r0, #24 */
/* @0x227da8 bgt 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227dac mov r0, r6 */
/* @0x227db0 mov r1, #1 */
/* @0x227db4 bl 0x233b28 <oggpack_read> */
/* @0x227db8 subs r4, r0, #0 */
/* @0x227dbc beq 0x227fa0 <vorbis_staticbook_unpack+0x270> */
/* @0x227dc0 cmp r4, #1 */
/* @0x227dc4 bne 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227dc8 mov r0, r6 */
/* @0x227dcc mov r1, #5 */
/* @0x227dd0 bl 0x233b28 <oggpack_read> */
/* @0x227dd4 adds r4, r0, #1 */
/* @0x227dd8 mov r9, r0 */
/* @0x227ddc beq 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227de0 ldr r8, [r5, #0x4] */
/* @0x227de4 lsl r0, r8, #2 */
/* @0x227de8 bl 0xb6544 <malloc@plt> */
/* @0x227dec cmp r8, #0 */
/* @0x227df0 str r0, [r5, #0x8] */
/* @0x227df4 ble 0x227e88 <vorbis_staticbook_unpack+0x158> */
/* @0x227df8 add r9, r9, #2 */
/* @0x227dfc mov r7, #0 */
/* @0x227e00 rsb r0, r7, r8 */
/* @0x227e04 bl 0x22eaf0 <_ilog> */
/* @0x227e08 mov r1, r0 */
/* @0x227e0c mov r0, r6 */
/* @0x227e10 bl 0x233b28 <oggpack_read> */
/* @0x227e14 cmn r0, #1 */
/* @0x227e18 beq 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227e1c cmp r4, #32 */
/* @0x227e20 bgt 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227e24 ldr r8, [r5, #0x4] */
/* @0x227e28 rsb r3, r7, r8 */
/* @0x227e2c cmp r0, r3 */
/* @0x227e30 bgt 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227e34 cmp r0, #0 */
/* @0x227e38 ble 0x227e78 <vorbis_staticbook_unpack+0x148> */
/* @0x227e3c sub r1, r0, #1 */
/* @0x227e40 asr r2, r4, #1 */
/* @0x227e44 asr r3, r9, #1 */
/* @0x227e48 asr r2, r1, r2 */
/* @0x227e4c asrs r3, r2, r3 */
/* @0x227e50 bne 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227e54 ldr r2, [r5, #0x8] */
/* @0x227e58 add r0, r7, r0 */
/* @0x227e5c add r3, r2, r7, lsl #2 */
/* @0x227e60 add r2, r2, r0, lsl #2 */
/* @0x227e64 str r4, [r3], #4 */
/* @0x227e68 cmp r3, r2 */
/* @0x227e6c bne 0x227e64 <vorbis_staticbook_unpack+0x134> */
/* @0x227e70 ldr r8, [r5, #0x4] */
/* @0x227e74 mov r7, r0 */
/* @0x227e78 cmp r8, r7 */
/* @0x227e7c add r9, r9, #1 */
/* @0x227e80 add r4, r4, #1 */
/* @0x227e84 bgt 0x227e00 <vorbis_staticbook_unpack+0xd0> */
/* @0x227e88 mov r0, r6 */
/* @0x227e8c mov r1, #4 */
/* @0x227e90 bl 0x233b28 <oggpack_read> */
/* @0x227e94 cmp r0, #0 */
/* @0x227e98 str r0, [r5, #0xc] */
/* @0x227e9c beq 0x227f98 <vorbis_staticbook_unpack+0x268> */
/* @0x227ea0 blt 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227ea4 cmp r0, #2 */
/* @0x227ea8 bgt 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227eac mov r1, #32 */
/* @0x227eb0 mov r0, r6 */
/* @0x227eb4 bl 0x233b28 <oggpack_read> */
/* @0x227eb8 mov r1, #32 */
/* @0x227ebc str r0, [r5, #0x10] */
/* @0x227ec0 mov r0, r6 */
/* @0x227ec4 bl 0x233b28 <oggpack_read> */
/* @0x227ec8 mov r1, #4 */
/* @0x227ecc str r0, [r5, #0x14] */
/* @0x227ed0 mov r0, r6 */
/* @0x227ed4 bl 0x233b28 <oggpack_read> */
/* @0x227ed8 mov r1, #1 */
/* @0x227edc add r3, r0, r1 */
/* @0x227ee0 mov r0, r6 */
/* @0x227ee4 str r3, [r5, #0x18] */
/* @0x227ee8 bl 0x233b28 <oggpack_read> */
/* @0x227eec cmn r0, #1 */
/* @0x227ef0 str r0, [r5, #0x1c] */
/* @0x227ef4 beq 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227ef8 ldr r3, [r5, #0xc] */
/* @0x227efc cmp r3, #1 */
/* @0x227f00 beq 0x2280ac <vorbis_staticbook_unpack+0x37c> */
/* @0x227f04 cmp r3, #2 */
/* @0x227f08 bne 0x2280a4 <vorbis_staticbook_unpack+0x374> */
/* @0x227f0c ldr r3, [r5, #0x4] */
/* @0x227f10 ldr r8, [r5] */
/* @0x227f14 mul r8, r8, r3 */
/* @0x227f18 mov r0, r6 */
/* @0x227f1c ldr r4, [r5, #0x18] */
/* @0x227f20 ldr r7, [r6, #0x10] */
/* @0x227f24 bl 0x233e28 <oggpack_bytes> */
/* @0x227f28 mul r4, r4, r8 */
/* @0x227f2c add r4, r4, #7 */
/* @0x227f30 asr r4, r4, #3 */
/* @0x227f34 rsb r0, r0, r7 */
/* @0x227f38 cmp r4, r0 */
/* @0x227f3c bgt 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227f40 lsl r9, r8, #2 */
/* @0x227f44 mov r0, r9 */
/* @0x227f48 bl 0xb6544 <malloc@plt> */
/* @0x227f4c cmp r8, #0 */
/* @0x227f50 str r0, [r5, #0x20] */
/* @0x227f54 ble 0x2280c8 <vorbis_staticbook_unpack+0x398> */
/* @0x227f58 mov r7, r0 */
/* @0x227f5c mov r4, #0 */
/* @0x227f60 b 0x227f68 <vorbis_staticbook_unpack+0x238> */
/* @0x227f64 ldr r7, [r5, #0x20] */
/* @0x227f68 mov r0, r6 */
/* @0x227f6c ldr r1, [r5, #0x18] */
/* @0x227f70 bl 0x233b28 <oggpack_read> */
/* @0x227f74 str r0, [r7, r4, lsl #2] */
/* @0x227f78 add r4, r4, #1 */
/* @0x227f7c cmp r4, r8 */
/* @0x227f80 bne 0x227f64 <vorbis_staticbook_unpack+0x234> */
/* @0x227f84 ldr r0, [r5, #0x20] */
/* @0x227f88 add r0, r0, r9 */
/* @0x227f8c ldr r3, [r0, #-0x4] */
/* @0x227f90 cmn r3, #1 */
/* @0x227f94 beq 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227f98 mov r0, r5 */
/* @0x227f9c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x227fa0 mov r1, #1 */
/* @0x227fa4 mov r0, r6 */
/* @0x227fa8 bl 0x233b28 <oggpack_read> */
/* @0x227fac ldr r9, [r5, #0x4] */
/* @0x227fb0 ldr r8, [r6, #0x10] */
/* @0x227fb4 mov r7, r0 */
/* @0x227fb8 mov r0, r6 */
/* @0x227fbc bl 0x233e28 <oggpack_bytes> */
/* @0x227fc0 cmp r7, #0 */
/* @0x227fc4 moveq r3, #5 */
/* @0x227fc8 movne r3, #1 */
/* @0x227fcc mul r3, r3, r9 */
/* @0x227fd0 rsb r0, r0, r8 */
/* @0x227fd4 add r3, r3, #7 */
/* @0x227fd8 cmp r0, r3, asr #3 */
/* @0x227fdc blt 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x227fe0 ldr r8, [r5, #0x4] */
/* @0x227fe4 lsl r0, r8, #2 */
/* @0x227fe8 bl 0xb6544 <malloc@plt> */
/* @0x227fec cmp r7, #0 */
/* @0x227ff0 str r0, [r5, #0x8] */
/* @0x227ff4 bne 0x228048 <vorbis_staticbook_unpack+0x318> */
/* @0x227ff8 cmp r8, #0 */
/* @0x227ffc movgt r4, r7 */
/* @0x228000 bgt 0x228020 <vorbis_staticbook_unpack+0x2f0> */
/* @0x228004 b 0x227e88 <vorbis_staticbook_unpack+0x158> */
/* @0x228008 ldr r2, [r5, #0x8] */
/* @0x22800c str r3, [r2, r4, lsl #2] */
/* @0x228010 add r4, r4, #1 */
/* @0x228014 ldr r3, [r5, #0x4] */
/* @0x228018 cmp r3, r4 */
/* @0x22801c ble 0x227e88 <vorbis_staticbook_unpack+0x158> */
/* @0x228020 mov r0, r6 */
/* @0x228024 mov r1, #5 */
/* @0x228028 bl 0x233b28 <oggpack_read> */
/* @0x22802c cmn r0, #1 */
/* @0x228030 add r3, r0, #1 */
/* @0x228034 bne 0x228008 <vorbis_staticbook_unpack+0x2d8> */
/* @0x228038 mov r0, r5 */
/* @0x22803c bl 0x22f554 <vorbis_staticbook_destroy> */
/* @0x228040 mov r0, #0 */
/* @0x228044 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x228048 cmp r8, #0 */
/* @0x22804c ble 0x227e88 <vorbis_staticbook_unpack+0x158> */
/* @0x228050 mov r7, r4 */
/* @0x228054 b 0x228074 <vorbis_staticbook_unpack+0x344> */
/* @0x228058 ldr r3, [r5, #0x8] */
/* @0x22805c add r7, r7, #1 */
/* @0x228060 str r0, [r3, r4] */
/* @0x228064 add r4, r4, #4 */
/* @0x228068 ldr r3, [r5, #0x4] */
/* @0x22806c cmp r3, r7 */
/* @0x228070 ble 0x227e88 <vorbis_staticbook_unpack+0x158> */
/* @0x228074 mov r0, r6 */
/* @0x228078 mov r1, #1 */
/* @0x22807c bl 0x233b28 <oggpack_read> */
/* @0x228080 cmp r0, #0 */
/* @0x228084 beq 0x228058 <vorbis_staticbook_unpack+0x328> */
/* @0x228088 mov r0, r6 */
/* @0x22808c mov r1, #5 */
/* @0x228090 bl 0x233b28 <oggpack_read> */
/* @0x228094 cmn r0, #1 */
/* @0x228098 add r0, r0, #1 */
/* @0x22809c bne 0x228058 <vorbis_staticbook_unpack+0x328> */
/* @0x2280a0 b 0x228038 <vorbis_staticbook_unpack+0x308> */
/* @0x2280a4 mov r8, #0 */
/* @0x2280a8 b 0x227f18 <vorbis_staticbook_unpack+0x1e8> */
/* @0x2280ac ldr r8, [r5] */
/* @0x2280b0 cmp r8, #0 */
/* @0x2280b4 beq 0x227f18 <vorbis_staticbook_unpack+0x1e8> */
/* @0x2280b8 mov r0, r5 */
/* @0x2280bc bl 0x22ed88 <_book_maptype1_quantvals> */
/* @0x2280c0 mov r8, r0 */
/* @0x2280c4 b 0x227f18 <vorbis_staticbook_unpack+0x1e8> */
/* @0x2280c8 beq 0x227f98 <vorbis_staticbook_unpack+0x268> */
/* @0x2280cc b 0x227f88 <vorbis_staticbook_unpack+0x258> */

/* ── FUNC 0x2280d0 · vorbis_book_decode · size=396 · insn=99 */
/* @0x2280d0 ldr r3, [r0, #0x8] */
/* @0x2280d4 push {r4, r5, r6, r7, r8, lr} */
/* @0x2280d8 cmp r3, #0 */
/* @0x2280dc mov r8, r0 */
/* @0x2280e0 mov r7, r1 */
/* @0x2280e4 ble 0x22822c <vorbis_book_decode+0x15c> */
/* @0x2280e8 mov r0, r1 */
/* @0x2280ec ldr r1, [r8, #0x24] */
/* @0x2280f0 ldr r4, [r8, #0x28] */
/* @0x2280f4 bl 0x23388c <oggpack_look> */
/* @0x2280f8 cmp r0, #0 */
/* @0x2280fc blt 0x228234 <vorbis_book_decode+0x164> */
/* @0x228100 ldr r3, [r8, #0x20] */
/* @0x228104 ldr r5, [r3, r0, lsl #2] */
/* @0x228108 cmp r5, #0 */
/* @0x22810c bge 0x228210 <vorbis_book_decode+0x140> */
/* @0x228110 ldr r6, [r8, #0x8] */
/* @0x228114 ubfx r3, r5, #0x0, #0xf */
/* @0x228118 ubfx r5, r5, #0xf, #0xf */
/* @0x22811c rsb r6, r3, r6 */
/* @0x228120 b 0x228128 <vorbis_book_decode+0x58> */
/* @0x228124 sub r4, r4, #1 */
/* @0x228128 mov r0, r7 */
/* @0x22812c mov r1, r4 */
/* @0x228130 bl 0x23388c <oggpack_look> */
/* @0x228134 cmp r4, #1 */
/* @0x228138 movle r3, #0 */
/* @0x22813c movgt r3, #1 */
/* @0x228140 ands r3, r3, r0, lsr #31 */
/* @0x228144 bne 0x228124 <vorbis_book_decode+0x54> */
/* @0x228148 cmp r0, #0 */
/* @0x22814c blt 0x22824c <vorbis_book_decode+0x17c> */
/* @0x228150 rev r0, r0 */
/* @0x228154 movw r3, #0xf0f */
/* @0x228158 movw r2, #0xf0f0 */
/* @0x22815c bfi r3, r3, #16, #16 */
/* @0x228160 bfi r2, r2, #16, #16 */
/* @0x228164 and r3, r3, r0, lsr #4 */
/* @0x228168 and r0, r2, r0, lsl #4 */
/* @0x22816c movw r2, #0x3333 */
/* @0x228170 orr r12, r0, r3 */
/* @0x228174 bfi r2, r2, #16, #16 */
/* @0x228178 movw r3, #0xcccc */
/* @0x22817c bfi r3, r3, #16, #16 */
/* @0x228180 and r2, r2, r12, lsr #2 */
/* @0x228184 and r3, r3, r12, lsl #2 */
/* @0x228188 orr r0, r3, r2 */
/* @0x22818c rsb r3, r5, r6 */
/* @0x228190 movw r1, #0xaaaa */
/* @0x228194 movw r2, #0x5555 */
/* @0x228198 bfi r1, r1, #16, #16 */
/* @0x22819c bfi r2, r2, #16, #16 */
/* @0x2281a0 cmp r3, #1 */
/* @0x2281a4 and r1, r1, r0, lsl #1 */
/* @0x2281a8 and r2, r2, r0, lsr #1 */
/* @0x2281ac orr r1, r1, r2 */
/* @0x2281b0 ble 0x2281ec <vorbis_book_decode+0x11c> */
/* @0x2281b4 ldr r12, [r8, #0x14] */
/* @0x2281b8 asr r3, r3, #1 */
/* @0x2281bc add r2, r3, r5 */
/* @0x2281c0 ldr r2, [r12, r2, lsl #2] */
/* @0x2281c4 cmp r2, r1 */
/* @0x2281c8 movls r0, r3 */
/* @0x2281cc movhi r0, #0 */
/* @0x2281d0 cmp r2, r1 */
/* @0x2281d4 add r5, r5, r0 */
/* @0x2281d8 movls r3, #0 */
/* @0x2281dc rsb r6, r3, r6 */
/* @0x2281e0 rsb r3, r5, r6 */
/* @0x2281e4 cmp r3, #1 */
/* @0x2281e8 bgt 0x2281b8 <vorbis_book_decode+0xe8> */
/* @0x2281ec ldr r3, [r8, #0x1c] */
/* @0x2281f0 mov r0, r7 */
/* @0x2281f4 ldrb r1, [r3, r5] */
/* @0x2281f8 cmp r1, r4 */
/* @0x2281fc bgt 0x228240 <vorbis_book_decode+0x170> */
/* @0x228200 bl 0x233a7c <oggpack_adv> */
/* @0x228204 ldr r3, [r8, #0x18] */
/* @0x228208 ldr r0, [r3, r5, lsl #2] */
/* @0x22820c pop {r4, r5, r6, r7, r8, pc} */
/* @0x228210 ldr r3, [r8, #0x1c] */
/* @0x228214 mov r0, r7 */
/* @0x228218 add r3, r3, r5 */
/* @0x22821c ldrb r1, [r3, #-0x1] */
/* @0x228220 bl 0x233a7c <oggpack_adv> */
/* @0x228224 subs r5, r5, #1 */
/* @0x228228 bhs 0x228204 <vorbis_book_decode+0x134> */
/* @0x22822c mvn r0, #0 */
/* @0x228230 pop {r4, r5, r6, r7, r8, pc} */
/* @0x228234 ldr r6, [r8, #0x8] */
/* @0x228238 mov r5, #0 */
/* @0x22823c b 0x228128 <vorbis_book_decode+0x58> */
/* @0x228240 add r1, r4, #1 */
/* @0x228244 bl 0x233a7c <oggpack_adv> */
/* @0x228248 b 0x22822c <vorbis_book_decode+0x15c> */
/* @0x22824c mov r0, r7 */
/* @0x228250 mov r1, #1 */
/* @0x228254 bl 0x233a7c <oggpack_adv> */
/* @0x228258 b 0x22822c <vorbis_book_decode+0x15c> */
