/* libyoyo.so 覆盖卡组 0197
 * 函数 0x21e9f8..0x21f164，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x21e9f8 · SND_AddFromMemory(void*, int) · size=104 · insn=26 */
/* @0x21e9f8 push {r4, r5, r6, lr} */
/* @0x21e9fc mov r6, r0 */
/* @0x21ea00 mov r0, r1 */
/* @0x21ea04 bl 0x21e7f4 <_Z12SND_AddEmptyi> */
/* @0x21ea08 ldr r3, [pc, #0x48] */
/* @0x21ea0c ldr r3, [pc, r3] */
/* @0x21ea10 ldr r3, [r3, #0x4] */
/* @0x21ea14 add r5, r0, r0, lsl #2 */
/* @0x21ea18 mov r4, r0 */
/* @0x21ea1c add r5, r3, r5, lsl #2 */
/* @0x21ea20 ldr r3, [r5, #0x4] */
/* @0x21ea24 bic r3, r3, #2 */
/* @0x21ea28 cmp r3, #1 */
/* @0x21ea2c beq 0x21ea50 <_Z17SND_AddFromMemoryPvi+0x58> */
/* @0x21ea30 ldr r0, [pc, #0x24] */
/* @0x21ea34 add r1, r6, #4 */
/* @0x21ea38 ldr r2, [r6] */
/* @0x21ea3c mov r3, r4 */
/* @0x21ea40 add r0, pc, r0 */
/* @0x21ea44 ldr r0, [r0] */
/* @0x21ea48 bl 0x22054c <_ZN13SoundHardware4LoadEPvii> */
/* @0x21ea4c str r0, [r5, #0x8] */
/* @0x21ea50 mov r0, r4 */
/* @0x21ea54 pop {r4, r5, r6, pc} */
/* @0x21ea58 andseq r2, sp, r12, lsl #20 */
/* @0x21ea5c subseq r6, r3, r4, ror #17 */

/* ── FUNC 0x21ea60 · SND_AddFromMemory(CStream*, int) · size=124 · insn=31 */
/* @0x21ea60 push {r4, r5, r6, r7, r8, lr} */
/* @0x21ea64 mov r6, r0 */
/* @0x21ea68 mov r0, r1 */
/* @0x21ea6c bl 0x21e7f4 <_Z12SND_AddEmptyi> */
/* @0x21ea70 ldr r3, [pc, #0x5c] */
/* @0x21ea74 ldr r3, [pc, r3] */
/* @0x21ea78 ldr r3, [r3, #0x4] */
/* @0x21ea7c add r5, r0, r0, lsl #2 */
/* @0x21ea80 mov r4, r0 */
/* @0x21ea84 add r5, r3, r5, lsl #2 */
/* @0x21ea88 ldr r3, [r5, #0x4] */
/* @0x21ea8c cmp r3, #3 */
/* @0x21ea90 beq 0x21eacc <_Z17SND_AddFromMemoryP7CStreami+0x6c> */
/* @0x21ea94 ldr r3, [pc, #0x3c] */
/* @0x21ea98 mov r0, r6 */
/* @0x21ea9c add r3, pc, r3 */
/* @0x21eaa0 ldr r8, [r3] */
/* @0x21eaa4 bl 0x201158 <_ZN7CStream9GetMemoryEv> */
/* @0x21eaa8 mov r7, r0 */
/* @0x21eaac mov r0, r6 */
/* @0x21eab0 bl 0x201168 <_ZN7CStream7GetSizeEv> */
/* @0x21eab4 mov r1, r7 */
/* @0x21eab8 mov r3, r4 */
/* @0x21eabc mov r2, r0 */
/* @0x21eac0 mov r0, r8 */
/* @0x21eac4 bl 0x22054c <_ZN13SoundHardware4LoadEPvii> */
/* @0x21eac8 str r0, [r5, #0x8] */
/* @0x21eacc mov r0, r4 */
/* @0x21ead0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x21ead4 andseq r2, sp, r4, lsr #19 */
/* @0x21ead8 subseq r6, r3, r8, lsl #17 */

/* ── FUNC 0x21eadc · SND_Delete(int) · size=4 · insn=1 */
/* @0x21eadc bx lr */

/* ── FUNC 0x21eae0 · SND_Clear() · size=128 · insn=32 */
/* @0x21eae0 push {r4, r5, r6, lr} */
/* @0x21eae4 ldr r5, [pc, #0x6c] */
/* @0x21eae8 ldr r5, [pc, r5] */
/* @0x21eaec ldr r3, [r5] */
/* @0x21eaf0 cmp r3, #0 */
/* @0x21eaf4 movgt r4, #0 */
/* @0x21eaf8 ble 0x21eb14 <_Z9SND_Clearv+0x34> */
/* @0x21eafc mov r0, r4 */
/* @0x21eb00 add r4, r4, #1 */
/* @0x21eb04 bl 0x21eadc <_Z10SND_Deletei> */
/* @0x21eb08 ldr r3, [r5] */
/* @0x21eb0c cmp r3, r4 */
/* @0x21eb10 bgt 0x21eafc <_Z9SND_Clearv+0x1c> */
/* @0x21eb14 ldr r4, [pc, #0x40] */
/* @0x21eb18 ldr r4, [pc, r4] */
/* @0x21eb1c ldr r6, [r4, #0x4] */
/* @0x21eb20 cmp r6, #0 */
/* @0x21eb24 beq 0x21eb48 <_Z9SND_Clearv+0x68> */
/* @0x21eb28 mov r0, r6 */
/* @0x21eb2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21eb30 mov r3, #0 */
/* @0x21eb34 str r3, [r4, #0x4] */
/* @0x21eb38 mov r3, #0 */
/* @0x21eb3c str r3, [r4] */
/* @0x21eb40 str r3, [r5] */
/* @0x21eb44 pop {r4, r5, r6, pc} */
/* @0x21eb48 mov r0, r6 */
/* @0x21eb4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21eb50 str r6, [r4, #0x4] */
/* @0x21eb54 b 0x21eb38 <_Z9SND_Clearv+0x58> */
/* @0x21eb58 andseq r2, sp, r12, lsr #18 */
/* @0x21eb5c andseq r2, sp, r0, lsl #18 */

/* ── FUNC 0x21eb60 · SND_Set_Global_Volume(float) · size=24 · insn=6 */
/* @0x21eb60 ldr r3, [pc, #0xc] */
/* @0x21eb64 mov r1, r0 */
/* @0x21eb68 add r3, pc, r3 */
/* @0x21eb6c ldr r0, [r3] */
/* @0x21eb70 b 0x220884 <_ZN13SoundHardware15SetMasterVolumeEf> */
/* @0x21eb74 ldrheq r6, [r3], #-124 */

/* ── FUNC 0x21eb78 · SND_Set_Global_Tempo(double) · size=4 · insn=1 */
/* @0x21eb78 bx lr */

/* ── FUNC 0x21eb7c · SND_Play(char const*, int, bool) · size=376 · insn=94 */
/* @0x21eb7c push {r3, r4, r5, r6, r7, lr} */
/* @0x21eb80 mov r5, r1 */
/* @0x21eb84 ldr r4, [pc, #0x148] */
/* @0x21eb88 mov r7, r2 */
/* @0x21eb8c ldr r3, [pc, #0x144] */
/* @0x21eb90 mov r6, r0 */
/* @0x21eb94 add r4, pc, r4 */
/* @0x21eb98 ldr r3, [r4, r3] */
/* @0x21eb9c ldrb r3, [r3] */
/* @0x21eba0 cmp r3, #0 */
/* @0x21eba4 popne {r3, r4, r5, r6, r7, pc} */
/* @0x21eba8 cmp r0, #0 */
/* @0x21ebac beq 0x21ebd0 <_Z8SND_PlayPKcib+0x54> */
/* @0x21ebb0 bl 0xb6538 <strlen@plt> */
/* @0x21ebb4 add r0, r6, r0 */
/* @0x21ebb8 ldrb r3, [r0, #-0x4] */
/* @0x21ebbc cmp r3, #46 */
/* @0x21ebc0 beq 0x21ec1c <_Z8SND_PlayPKcib+0xa0> */
/* @0x21ebc4 ldrb r2, [r0, #-0x5] */
/* @0x21ebc8 cmp r2, #46 */
/* @0x21ebcc beq 0x21ec70 <_Z8SND_PlayPKcib+0xf4> */
/* @0x21ebd0 cmp r5, #0 */
/* @0x21ebd4 poplt {r3, r4, r5, r6, r7, pc} */
/* @0x21ebd8 ldr r3, [pc, #0xfc] */
/* @0x21ebdc ldr r3, [r4, r3] */
/* @0x21ebe0 ldr r3, [r3] */
/* @0x21ebe4 cmp r5, r3 */
/* @0x21ebe8 popge {r3, r4, r5, r6, r7, pc} */
/* @0x21ebec ldr r3, [pc, #0xec] */
/* @0x21ebf0 add r5, r5, r5, lsl #2 */
/* @0x21ebf4 ldr r1, [pc, #0xe8] */
/* @0x21ebf8 mov r2, r7 */
/* @0x21ebfc ldr r3, [r4, r3] */
/* @0x21ec00 add r1, pc, r1 */
/* @0x21ec04 ldr r0, [r1] */
/* @0x21ec08 ldr r3, [r3, #0x4] */
/* @0x21ec0c add r5, r3, r5, lsl #2 */
/* @0x21ec10 ldr r1, [r5, #0x8] */
/* @0x21ec14 pop {r3, r4, r5, r6, r7, lr} */
/* @0x21ec18 b 0x220764 <_ZN13SoundHardware4PlayEPvb> */
/* @0x21ec1c ldrb r3, [r0, #-0x3] */
/* @0x21ec20 cmp r3, #109 */
/* @0x21ec24 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54> */
/* @0x21ec28 ldrb r3, [r0, #-0x2] */
/* @0x21ec2c cmp r3, #112 */
/* @0x21ec30 beq 0x21eca0 <_Z8SND_PlayPKcib+0x124> */
/* @0x21ec34 cmp r3, #105 */
/* @0x21ec38 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54> */
/* @0x21ec3c ldrb r3, [r0, #-0x1] */
/* @0x21ec40 cmp r3, #100 */
/* @0x21ec44 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54> */
/* @0x21ec48 ldr r3, [pc, #0x98] */
/* @0x21ec4c mov r2, r7 */
/* @0x21ec50 ldr r0, [pc, #0x94] */
/* @0x21ec54 mov r1, r6 */
/* @0x21ec58 ldr r3, [r4, r3] */
/* @0x21ec5c add r0, pc, r0 */
/* @0x21ec60 ldr r0, [r0] */
/* @0x21ec64 str r6, [r3] */
/* @0x21ec68 pop {r3, r4, r5, r6, r7, lr} */
/* @0x21ec6c b 0x220adc <_ZN13SoundHardware8PlayMIDIEPKcb> */
/* @0x21ec70 cmp r3, #109 */
/* @0x21ec74 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54> */
/* @0x21ec78 ldrb r3, [r0, #-0x3] */
/* @0x21ec7c cmp r3, #105 */
/* @0x21ec80 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54> */
/* @0x21ec84 ldrb r3, [r0, #-0x2] */
/* @0x21ec88 cmp r3, #100 */
/* @0x21ec8c bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54> */
/* @0x21ec90 ldrb r3, [r0, #-0x1] */
/* @0x21ec94 cmp r3, #105 */
/* @0x21ec98 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54> */
/* @0x21ec9c b 0x21ec48 <_Z8SND_PlayPKcib+0xcc> */
/* @0x21eca0 ldrb r3, [r0, #-0x1] */
/* @0x21eca4 cmp r3, #51 */
/* @0x21eca8 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54> */
/* @0x21ecac ldr r3, [pc, #0x34] */
/* @0x21ecb0 mov r2, r7 */
/* @0x21ecb4 ldr r0, [pc, #0x34] */
/* @0x21ecb8 mov r1, r6 */
/* @0x21ecbc ldr r3, [r4, r3] */
/* @0x21ecc0 add r0, pc, r0 */
/* @0x21ecc4 ldr r0, [r0] */
/* @0x21ecc8 str r6, [r3] */
/* @0x21eccc pop {r3, r4, r5, r6, r7, lr} */
/* @0x21ecd0 b 0x2209fc <_ZN13SoundHardware7PlayMP3EPKcb> */
/* @0x21ecd4 ldrheq r3, [sp], -r12 */
/* @0x21ecd8 .word 0xffffd3fc */
/* @0x21ecdc .word 0xfffff7c4 */
/* @0x21ece0 .word 0xfffff7c8 */
/* @0x21ece4 subseq r6, r3, r4, lsr #14 */
/* @0x21ece8 .word 0xfffff7cc */
/* @0x21ecec subseq r6, r3, r8, asr #13 */
/* @0x21ecf0 subseq r6, r3, r4, ror #12 */

/* ── FUNC 0x21ecf4 · SND_Stop(char const*, int) · size=204 · insn=51 */
/* @0x21ecf4 push {r3, r4, r5, r6, r7, lr} */
/* @0x21ecf8 mov r2, r0 */
/* @0x21ecfc ldr r4, [pc, #0xa0] */
/* @0x21ed00 mov r5, r1 */
/* @0x21ed04 ldr r3, [pc, #0x9c] */
/* @0x21ed08 add r4, pc, r4 */
/* @0x21ed0c ldr r3, [r4, r3] */
/* @0x21ed10 ldrb r3, [r3] */
/* @0x21ed14 cmp r3, #0 */
/* @0x21ed18 popne {r3, r4, r5, r6, r7, pc} */
/* @0x21ed1c ldr r3, [pc, #0x88] */
/* @0x21ed20 ldr r6, [r4, r3] */
/* @0x21ed24 ldr r0, [r6] */
/* @0x21ed28 cmp r0, #0 */
/* @0x21ed2c beq 0x21ed48 <_Z8SND_StopPKci+0x54> */
/* @0x21ed30 cmp r2, #0 */
/* @0x21ed34 beq 0x21ed48 <_Z8SND_StopPKci+0x54> */
/* @0x21ed38 mov r1, r2 */
/* @0x21ed3c bl 0xb6574 <strcmp@plt> */
/* @0x21ed40 subs r7, r0, #0 */
/* @0x21ed44 beq 0x21ed90 <_Z8SND_StopPKci+0x9c> */
/* @0x21ed48 cmp r5, #0 */
/* @0x21ed4c poplt {r3, r4, r5, r6, r7, pc} */
/* @0x21ed50 ldr r3, [pc, #0x58] */
/* @0x21ed54 ldr r3, [r4, r3] */
/* @0x21ed58 ldr r3, [r3] */
/* @0x21ed5c cmp r5, r3 */
/* @0x21ed60 popge {r3, r4, r5, r6, r7, pc} */
/* @0x21ed64 ldr r3, [pc, #0x48] */
/* @0x21ed68 add r5, r5, r5, lsl #2 */
/* @0x21ed6c ldr r2, [pc, #0x44] */
/* @0x21ed70 ldr r3, [r4, r3] */
/* @0x21ed74 add r2, pc, r2 */
/* @0x21ed78 ldr r0, [r2] */
/* @0x21ed7c ldr r3, [r3, #0x4] */
/* @0x21ed80 add r5, r3, r5, lsl #2 */
/* @0x21ed84 ldr r1, [r5, #0x8] */
/* @0x21ed88 pop {r3, r4, r5, r6, r7, lr} */
/* @0x21ed8c b 0x220d90 <_ZN13SoundHardware4StopEPv> */
/* @0x21ed90 ldr r3, [pc, #0x24] */
/* @0x21ed94 ldr r0, [pc, r3] */
/* @0x21ed98 bl 0x220950 <_ZN13SoundHardware9StopMusicEv> */
/* @0x21ed9c str r7, [r6] */
/* @0x21eda0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x21eda4 andseq r2, sp, r8, asr #30 */
/* @0x21eda8 .word 0xffffd3fc */
/* @0x21edac .word 0xfffff7cc */
/* @0x21edb0 .word 0xfffff7c4 */
/* @0x21edb4 .word 0xfffff7c8 */
/* @0x21edb8 ldrheq r6, [r3], #-80 */
/* @0x21edbc .word 0x00536590 */

/* ── FUNC 0x21edc0 · SND_IsPlaying(char const*, int) · size=208 · insn=52 */
/* @0x21edc0 push {r3, r4, r5, lr} */
/* @0x21edc4 mov r2, r0 */
/* @0x21edc8 ldr r4, [pc, #0xa4] */
/* @0x21edcc mov r5, r1 */
/* @0x21edd0 ldr r3, [pc, #0xa0] */
/* @0x21edd4 add r4, pc, r4 */
/* @0x21edd8 ldr r3, [r4, r3] */
/* @0x21eddc ldrb r3, [r3] */
/* @0x21ede0 cmp r3, #0 */
/* @0x21ede4 bne 0x21ee30 <_Z13SND_IsPlayingPKci+0x70> */
/* @0x21ede8 ldr r3, [pc, #0x8c] */
/* @0x21edec ldr r3, [r4, r3] */
/* @0x21edf0 ldr r0, [r3] */
/* @0x21edf4 cmp r0, #0 */
/* @0x21edf8 beq 0x21ee14 <_Z13SND_IsPlayingPKci+0x54> */
/* @0x21edfc cmp r2, #0 */
/* @0x21ee00 beq 0x21ee14 <_Z13SND_IsPlayingPKci+0x54> */
/* @0x21ee04 mov r1, r2 */
/* @0x21ee08 bl 0xb6574 <strcmp@plt> */
/* @0x21ee0c cmp r0, #0 */
/* @0x21ee10 beq 0x21ee64 <_Z13SND_IsPlayingPKci+0xa4> */
/* @0x21ee14 cmp r5, #0 */
/* @0x21ee18 blt 0x21ee30 <_Z13SND_IsPlayingPKci+0x70> */
/* @0x21ee1c ldr r3, [pc, #0x5c] */
/* @0x21ee20 ldr r3, [r4, r3] */
/* @0x21ee24 ldr r3, [r3] */
/* @0x21ee28 cmp r5, r3 */
/* @0x21ee2c blt 0x21ee38 <_Z13SND_IsPlayingPKci+0x78> */
/* @0x21ee30 mov r0, #0 */
/* @0x21ee34 pop {r3, r4, r5, pc} */
/* @0x21ee38 ldr r3, [pc, #0x44] */
/* @0x21ee3c add r5, r5, r5, lsl #2 */
/* @0x21ee40 ldr r2, [pc, #0x40] */
/* @0x21ee44 ldr r3, [r4, r3] */
/* @0x21ee48 add r2, pc, r2 */
/* @0x21ee4c ldr r0, [r2] */
/* @0x21ee50 ldr r3, [r3, #0x4] */
/* @0x21ee54 add r5, r3, r5, lsl #2 */
/* @0x21ee58 ldr r1, [r5, #0x8] */
/* @0x21ee5c pop {r3, r4, r5, lr} */
/* @0x21ee60 b 0x220ee0 <_ZN13SoundHardware7PlayingEPv> */
/* @0x21ee64 ldr r3, [pc, #0x20] */
/* @0x21ee68 ldr r0, [pc, r3] */
/* @0x21ee6c pop {r3, r4, r5, lr} */
/* @0x21ee70 b 0x221078 <_ZN13SoundHardware10PlayingMP3Ev> */
/* @0x21ee74 andseq r2, sp, r12, ror lr */
/* @0x21ee78 .word 0xffffd3fc */
/* @0x21ee7c .word 0xfffff7cc */
/* @0x21ee80 .word 0xfffff7c4 */
/* @0x21ee84 .word 0xfffff7c8 */
/* @0x21ee88 ldrsbeq r6, [r3], #-76 */
/* @0x21ee8c ldrheq r6, [r3], #-76 */

/* ── FUNC 0x21ee90 · SND_StopAll() · size=144 · insn=36 */
/* @0x21ee90 ldr r3, [pc, #0x74] */
/* @0x21ee94 push {r4, r5, r6, r7, r8, lr} */
/* @0x21ee98 ldr r3, [pc, r3] */
/* @0x21ee9c ldrb r4, [r3] */
/* @0x21eea0 cmp r4, #0 */
/* @0x21eea4 popne {r4, r5, r6, r7, r8, pc} */
/* @0x21eea8 ldr r6, [pc, #0x60] */
/* @0x21eeac ldr r6, [pc, r6] */
/* @0x21eeb0 ldr r3, [r6] */
/* @0x21eeb4 cmp r3, #0 */
/* @0x21eeb8 ble 0x21eefc <_Z11SND_StopAllv+0x6c> */
/* @0x21eebc ldr r7, [pc, #0x50] */
/* @0x21eec0 mov r5, r4 */
/* @0x21eec4 ldr r8, [pc, #0x4c] */
/* @0x21eec8 ldr r7, [pc, r7] */
/* @0x21eecc add r8, pc, r8 */
/* @0x21eed0 ldr r3, [r7, #0x4] */
/* @0x21eed4 add r5, r5, #1 */
/* @0x21eed8 adds r3, r3, r4 */
/* @0x21eedc add r4, r4, #20 */
/* @0x21eee0 beq 0x21eef0 <_Z11SND_StopAllv+0x60> */
/* @0x21eee4 ldr r1, [r3, #0x8] */
/* @0x21eee8 ldr r0, [r8] */
/* @0x21eeec bl 0x220d90 <_ZN13SoundHardware4StopEPv> */
/* @0x21eef0 ldr r3, [r6] */
/* @0x21eef4 cmp r3, r5 */
/* @0x21eef8 bgt 0x21eed0 <_Z11SND_StopAllv+0x40> */
/* @0x21eefc ldr r3, [pc, #0x18] */
/* @0x21ef00 pop {r4, r5, r6, r7, r8, lr} */
/* @0x21ef04 ldr r0, [pc, r3] */
/* @0x21ef08 b 0x220950 <_ZN13SoundHardware9StopMusicEv> */
/* @0x21ef0c ldrheq r0, [sp], -r4 */
/* @0x21ef10 andseq r2, sp, r8, ror #10 */
/* @0x21ef14 andseq r2, sp, r0, asr r5 */
/* @0x21ef18 subseq r6, r3, r8, asr r4 */
/* @0x21ef1c subseq r6, r3, r0, lsr #8 */

/* ── FUNC 0x21ef20 · SND_PlatformPause() · size=168 · insn=42 */
/* @0x21ef20 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x21ef24 ldr r3, [pc, #0x84] */
/* @0x21ef28 ldr r2, [pc, #0x84] */
/* @0x21ef2c add r3, pc, r3 */
/* @0x21ef30 ldr r2, [r3, r2] */
/* @0x21ef34 ldrb r2, [r2] */
/* @0x21ef38 cmp r2, #0 */
/* @0x21ef3c popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21ef40 ldr r2, [pc, #0x70] */
/* @0x21ef44 ldr r2, [r3, r2] */
/* @0x21ef48 ldrb r4, [r2] */
/* @0x21ef4c cmp r4, #0 */
/* @0x21ef50 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21ef54 ldr r2, [pc, #0x60] */
/* @0x21ef58 ldr r7, [r3, r2] */
/* @0x21ef5c ldr r2, [r7] */
/* @0x21ef60 cmp r2, #0 */
/* @0x21ef64 pople {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21ef68 ldr r2, [pc, #0x50] */
/* @0x21ef6c mov r5, r4 */
/* @0x21ef70 ldr r8, [pc, #0x4c] */
/* @0x21ef74 ldr r9, [r3, r2] */
/* @0x21ef78 add r8, pc, r8 */
/* @0x21ef7c ldr r3, [r9, #0x4] */
/* @0x21ef80 add r5, r5, #1 */
/* @0x21ef84 adds r6, r3, r4 */
/* @0x21ef88 add r4, r4, #20 */
/* @0x21ef8c beq 0x21efa0 <_Z17SND_PlatformPausev+0x80> */
/* @0x21ef90 ldr r0, [r8] */
/* @0x21ef94 ldr r1, [r6, #0x8] */
/* @0x21ef98 bl 0x220fe8 <_ZN13SoundHardware5PauseEPv> */
/* @0x21ef9c strb r0, [r6, #0x1] */
/* @0x21efa0 ldr r3, [r7] */
/* @0x21efa4 cmp r3, r5 */
/* @0x21efa8 bgt 0x21ef7c <_Z17SND_PlatformPausev+0x5c> */
/* @0x21efac pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21efb0 andseq r2, sp, r4, lsr #26 */
/* @0x21efb4 .word 0xffffd3fc */
/* @0x21efb8 .word 0xffffd0e0 */
/* @0x21efbc .word 0xfffff7c4 */
/* @0x21efc0 .word 0xfffff7c8 */
/* @0x21efc4 subseq r6, r3, r12, lsr #7 */

/* ── FUNC 0x21efc8 · SND_PlatformResume() · size=180 · insn=45 */
/* @0x21efc8 ldr r3, [pc, #0x94] */
/* @0x21efcc ldr r2, [pc, #0x94] */
/* @0x21efd0 add r3, pc, r3 */
/* @0x21efd4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x21efd8 ldr r2, [r3, r2] */
/* @0x21efdc ldrb r2, [r2] */
/* @0x21efe0 cmp r2, #0 */
/* @0x21efe4 popne {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21efe8 ldr r2, [pc, #0x7c] */
/* @0x21efec ldr r2, [r3, r2] */
/* @0x21eff0 ldrb r4, [r2] */
/* @0x21eff4 cmp r4, #0 */
/* @0x21eff8 popne {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21effc ldr r2, [pc, #0x6c] */
/* @0x21f000 ldr r9, [r3, r2] */
/* @0x21f004 ldr r2, [r9] */
/* @0x21f008 cmp r2, #0 */
/* @0x21f00c pople {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21f010 ldr r2, [pc, #0x5c] */
/* @0x21f014 mov r5, r4 */
/* @0x21f018 ldr r8, [pc, #0x58] */
/* @0x21f01c mov r7, r4 */
/* @0x21f020 ldr r10, [r3, r2] */
/* @0x21f024 add r8, pc, r8 */
/* @0x21f028 ldr r6, [r10, #0x4] */
/* @0x21f02c add r5, r5, #1 */
/* @0x21f030 add r6, r6, r4 */
/* @0x21f034 add r4, r4, #20 */
/* @0x21f038 ldrb r3, [r6, #0x1] */
/* @0x21f03c cmp r3, #0 */
/* @0x21f040 beq 0x21f054 <_Z18SND_PlatformResumev+0x8c> */
/* @0x21f044 ldr r0, [r8] */
/* @0x21f048 ldr r1, [r6, #0x8] */
/* @0x21f04c bl 0x220e68 <_ZN13SoundHardware6ResumeEPv> */
/* @0x21f050 strb r7, [r6, #0x1] */
/* @0x21f054 ldr r3, [r9] */
/* @0x21f058 cmp r3, r5 */
/* @0x21f05c bgt 0x21f028 <_Z18SND_PlatformResumev+0x60> */
/* @0x21f060 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21f064 andseq r2, sp, r0, lsl #25 */
/* @0x21f068 .word 0xffffd0e0 */
/* @0x21f06c .word 0xffffd3fc */
/* @0x21f070 .word 0xfffff7c4 */
/* @0x21f074 .word 0xfffff7c8 */
/* @0x21f078 subseq r6, r3, r0, lsl #6 */

/* ── FUNC 0x21f07c · SND_Set_Volume(int, double, int) · size=160 · insn=40 */
/* @0x21f07c ldr r1, [pc, #0x84] */
/* @0x21f080 vmov d7, r2, r3 */
/* @0x21f084 ldr r3, [sp] */
/* @0x21f088 ldr r1, [pc, r1] */
/* @0x21f08c ldrb r2, [r1] */
/* @0x21f090 cmp r2, #0 */
/* @0x21f094 bxne lr */
/* @0x21f098 cmp r0, #0 */
/* @0x21f09c bxlt lr */
/* @0x21f0a0 ldr r2, [pc, #0x64] */
/* @0x21f0a4 ldr r2, [pc, r2] */
/* @0x21f0a8 ldr r2, [r2] */
/* @0x21f0ac cmp r0, r2 */
/* @0x21f0b0 bxge lr */
/* @0x21f0b4 ldr r2, [pc, #0x54] */
/* @0x21f0b8 add r0, r0, r0, lsl #2 */
/* @0x21f0bc ldr r2, [pc, r2] */
/* @0x21f0c0 ldr r2, [r2, #0x4] */
/* @0x21f0c4 add r0, r2, r0, lsl #2 */
/* @0x21f0c8 ldr r1, [r0, #0x4] */
/* @0x21f0cc cmp r1, #1 */
/* @0x21f0d0 beq 0x21f0f0 <_Z14SND_Set_Volumeidi+0x74> */
/* @0x21f0d4 vcvt.f32.f64 s13, d7 */
/* @0x21f0d8 ldr r12, [pc, #0x34] */
/* @0x21f0dc ldr r1, [r0, #0x8] */
/* @0x21f0e0 add r12, pc, r12 */
/* @0x21f0e4 ldr r0, [r12] */
/* @0x21f0e8 vmov r2, s13 */
/* @0x21f0ec b 0x220be0 <_ZN13SoundHardware9SetVolumeEPvfi> */
/* @0x21f0f0 vcvt.f32.f64 s13, d7 */
/* @0x21f0f4 ldr r0, [pc, #0x1c] */
/* @0x21f0f8 add r0, pc, r0 */
/* @0x21f0fc ldr r0, [r0] */
/* @0x21f100 vmov r2, s13 */
/* @0x21f104 b 0x220be0 <_ZN13SoundHardware9SetVolumeEPvfi> */
/* @0x21f108 andseq pc, r12, r4, asr #31 */
/* @0x21f10c andseq r2, sp, r0, ror r3 */
/* @0x21f110 andseq r2, sp, r12, asr r3 */
/* @0x21f114 subseq r6, r3, r4, asr #4 */
/* @0x21f118 subseq r6, r3, r12, lsr #4 */

/* ── FUNC 0x21f11c · SND_Set_Panning(int, double) · size=4 · insn=1 */
/* @0x21f11c bx lr */

/* ── FUNC 0x21f120 · SND_Set_Effect(int, int) · size=4 · insn=1 */
/* @0x21f120 bx lr */

/* ── FUNC 0x21f124 · SND_Set_Effect_Chorus(int, double, double, double, double, int, double, int) · size=4 · insn=1 */
/* @0x21f124 bx lr */

/* ── FUNC 0x21f128 · SND_Get_Effect_Chorus(int, double*, double*, double*, double*, int*, double*, int*) · size=4 · insn=1 */
/* @0x21f128 bx lr */

/* ── FUNC 0x21f12c · SND_Set_Effect_Compressor(int, double, double, double, double, double, double) · size=4 · insn=1 */
/* @0x21f12c bx lr */

/* ── FUNC 0x21f130 · SND_Get_Effect_Compressor(int, double*, double*, double*, double*, double*, double*) · size=4 · insn=1 */
/* @0x21f130 bx lr */

/* ── FUNC 0x21f134 · SND_Set_Effect_Echo(int, double, double, double, double, int) · size=4 · insn=1 */
/* @0x21f134 bx lr */

/* ── FUNC 0x21f138 · SND_Get_Effect_Echo(int, double*, double*, double*, double*, int*) · size=4 · insn=1 */
/* @0x21f138 bx lr */

/* ── FUNC 0x21f13c · SND_Set_Effect_Flanger(int, double, double, double, double, int, double, int) · size=4 · insn=1 */
/* @0x21f13c bx lr */

/* ── FUNC 0x21f140 · SND_Get_Effect_Flanger(int, double*, double*, double*, double*, int*, double*, int*) · size=4 · insn=1 */
/* @0x21f140 bx lr */

/* ── FUNC 0x21f144 · SND_Set_Effect_Gargle(int, int, int) · size=4 · insn=1 */
/* @0x21f144 bx lr */

/* ── FUNC 0x21f148 · SND_Get_Effect_Gargle(int, int*, int*) · size=4 · insn=1 */
/* @0x21f148 bx lr */

/* ── FUNC 0x21f14c · SND_Set_Effect_Equalizer(int, double, double, double) · size=4 · insn=1 */
/* @0x21f14c bx lr */

/* ── FUNC 0x21f150 · SND_Get_Effect_Equalizer(int, double*, double*, double*) · size=4 · insn=1 */
/* @0x21f150 bx lr */

/* ── FUNC 0x21f154 · SND_Set_Effect_Reverb(int, double, double, double, double) · size=4 · insn=1 */
/* @0x21f154 bx lr */

/* ── FUNC 0x21f158 · SND_Get_Effect_Reverb(int, double*, double*, double*, double*) · size=4 · insn=1 */
/* @0x21f158 bx lr */

/* ── FUNC 0x21f15c · SND_Set_Effect_Distortion(int, double, double, double, double, double) · size=4 · insn=1 */
/* @0x21f15c bx lr */

/* ── FUNC 0x21f160 · SND_Get_Effect_Distortion(int, double*, double*, double*, double*, double*) · size=4 · insn=1 */
/* @0x21f160 bx lr */

/* ── FUNC 0x21f164 · SND_Set_Effect_Environmental(int, int) · size=4 · insn=1 */
/* @0x21f164 bx lr */
