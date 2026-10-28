/* libyoyo.so 覆盖卡组 0193
 * 函数 0x217b44..0x218d64，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x217b44 · Audio_PauseSoundNoise(CNoise*) · size=260 · insn=65 */
/* @0x217b44 ldr r3, [pc, #0xe8] */
/* @0x217b48 push {r4, r5, lr} */
/* @0x217b4c ldr r3, [pc, r3] */
/* @0x217b50 sub sp, sp, #12 */
/* @0x217b54 mov r4, r0 */
/* @0x217b58 ldrb r3, [r3] */
/* @0x217b5c cmp r3, #0 */
/* @0x217b60 bne 0x217b78 <_Z21Audio_PauseSoundNoiseP6CNoise+0x34> */
/* @0x217b64 cmp r0, #0 */
/* @0x217b68 beq 0x217b78 <_Z21Audio_PauseSoundNoiseP6CNoise+0x34> */
/* @0x217b6c ldrb r3, [r0, #0x5] */
/* @0x217b70 cmp r3, #0 */
/* @0x217b74 bne 0x217b80 <_Z21Audio_PauseSoundNoiseP6CNoise+0x3c> */
/* @0x217b78 add sp, sp, #12 */
/* @0x217b7c pop {r4, r5, pc} */
/* @0x217b80 ldr r0, [r0, #0x18] */
/* @0x217b84 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x217b88 cmp r0, #0 */
/* @0x217b8c beq 0x217b78 <_Z21Audio_PauseSoundNoiseP6CNoise+0x34> */
/* @0x217b90 ldrb r3, [r0, #0x24] */
/* @0x217b94 cmp r3, #0 */
/* @0x217b98 bne 0x217c1c <_Z21Audio_PauseSoundNoiseP6CNoise+0xd8> */
/* @0x217b9c ldrb r3, [r0, #0x25] */
/* @0x217ba0 cmp r3, #0 */
/* @0x217ba4 bne 0x217c1c <_Z21Audio_PauseSoundNoiseP6CNoise+0xd8> */
/* @0x217ba8 ldr r5, [pc, #0x88] */
/* @0x217bac add r2, sp, #4 */
/* @0x217bb0 ldr r0, [r4, #0x10] */
/* @0x217bb4 movw r1, #0x1010 */
/* @0x217bb8 ldr r5, [pc, r5] */
/* @0x217bbc ldr r3, [r5] */
/* @0x217bc0 ldr r0, [r3, r0, lsl #2] */
/* @0x217bc4 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x217bc8 ldr r2, [sp, #0x4] */
/* @0x217bcc movw r3, #0x1012 */
/* @0x217bd0 cmp r2, r3 */
/* @0x217bd4 bne 0x217b78 <_Z21Audio_PauseSoundNoiseP6CNoise+0x34> */
/* @0x217bd8 ldr r3, [r5] */
/* @0x217bdc ldr r2, [r4, #0x10] */
/* @0x217be0 ldr r0, [r3, r2, lsl #2] */
/* @0x217be4 bl 0xb6ab4 <alSourcePause@plt> */
/* @0x217be8 bl 0xb6a54 <alGetError@plt> */
/* @0x217bec subs r3, r0, #0 */
/* @0x217bf0 beq 0x217b78 <_Z21Audio_PauseSoundNoiseP6CNoise+0x34> */
/* @0x217bf4 ldr r0, [pc, #0x40] */
/* @0x217bf8 ldr r1, [pc, #0x40] */
/* @0x217bfc ldr r0, [pc, r0] */
/* @0x217c00 ldr r2, [r4, #0x18] */
/* @0x217c04 add r1, pc, r1 */
/* @0x217c08 ldr r0, [r0] */
/* @0x217c0c ldr r12, [r0] */
/* @0x217c10 ldr r12, [r12, #0xc] */
/* @0x217c14 blx r12 */
/* @0x217c18 b 0x217b78 <_Z21Audio_PauseSoundNoiseP6CNoise+0x34> */
/* @0x217c1c ldr r0, [pc, #0x20] */
/* @0x217c20 ldr r1, [r4, #0x10] */
/* @0x217c24 add r0, pc, r0 */
/* @0x217c28 bl 0x226470 <_ZN9COggAudio11Pause_SoundEi> */
/* @0x217c2c add sp, sp, #12 */
/* @0x217c30 pop {r4, r5, pc} */
/* @0x217c34 andseq r7, sp, r0, lsl #10 */
/* @0x217c38 andseq r9, sp, r4, lsl r8 */
/* @0x217c3c andseq r5, sp, r8, lsl r11 */
/* @0x217c40 andseq r12, r3, r12, asr r0 */
/* @0x217c44 subseq sp, r3, r0, ror r6 */

/* ── FUNC 0x217c48 · Audio_PauseAll() · size=168 · insn=42 */
/* @0x217c48 push {r3, r4, r5, r6, r7, lr} */
/* @0x217c4c ldr r3, [pc, #0x88] */
/* @0x217c50 ldr r3, [pc, r3] */
/* @0x217c54 ldrb r4, [r3] */
/* @0x217c58 cmp r4, #0 */
/* @0x217c5c popne {r3, r4, r5, r6, r7, pc} */
/* @0x217c60 ldr r3, [pc, #0x78] */
/* @0x217c64 ldr r3, [pc, r3] */
/* @0x217c68 ldrb r3, [r3] */
/* @0x217c6c cmp r3, #0 */
/* @0x217c70 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x217c74 ldr r3, [pc, #0x68] */
/* @0x217c78 add r3, pc, r3 */
/* @0x217c7c ldr r5, [r3, #0x38] */
/* @0x217c80 cmp r5, #0 */
/* @0x217c84 pople {r3, r4, r5, r6, r7, pc} */
/* @0x217c88 ldr r7, [pc, #0x58] */
/* @0x217c8c mov r3, r5 */
/* @0x217c90 ldr r6, [pc, #0x54] */
/* @0x217c94 add r7, pc, r7 */
/* @0x217c98 add r6, pc, r6 */
/* @0x217c9c b 0x217cb0 <_Z14Audio_PauseAllv+0x68> */
/* @0x217ca0 add r4, r4, #1 */
/* @0x217ca4 cmp r4, r5 */
/* @0x217ca8 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x217cac ldr r3, [r6, #0x38] */
/* @0x217cb0 cmp r4, r3 */
/* @0x217cb4 bge 0x217ca0 <_Z14Audio_PauseAllv+0x58> */
/* @0x217cb8 ldr r3, [r7, #0x3c] */
/* @0x217cbc ldr r0, [r3, r4, lsl #2] */
/* @0x217cc0 cmp r0, #0 */
/* @0x217cc4 beq 0x217ca0 <_Z14Audio_PauseAllv+0x58> */
/* @0x217cc8 ldrb r3, [r0, #0x5] */
/* @0x217ccc cmp r3, #0 */
/* @0x217cd0 beq 0x217ca0 <_Z14Audio_PauseAllv+0x58> */
/* @0x217cd4 bl 0x217b44 <_Z21Audio_PauseSoundNoiseP6CNoise> */
/* @0x217cd8 b 0x217ca0 <_Z14Audio_PauseAllv+0x58> */
/* @0x217cdc ldrsheq r7, [sp], -r12 */
/* @0x217ce0 andseq r7, sp, r12, asr #1 */
/* @0x217ce4 subseq sp, r3, r12, lsl r6 */
/* @0x217ce8 subseq sp, r3, r0, lsl #12 */
/* @0x217cec ldrsheq sp, [r3], #-92 */

/* ── FUNC 0x217cf0 · Audio_ResumeSoundNoise(CNoise*) · size=260 · insn=65 */
/* @0x217cf0 ldr r3, [pc, #0xe8] */
/* @0x217cf4 push {r4, r5, lr} */
/* @0x217cf8 ldr r3, [pc, r3] */
/* @0x217cfc sub sp, sp, #12 */
/* @0x217d00 mov r4, r0 */
/* @0x217d04 ldrb r3, [r3] */
/* @0x217d08 cmp r3, #0 */
/* @0x217d0c bne 0x217d24 <_Z22Audio_ResumeSoundNoiseP6CNoise+0x34> */
/* @0x217d10 cmp r0, #0 */
/* @0x217d14 beq 0x217d24 <_Z22Audio_ResumeSoundNoiseP6CNoise+0x34> */
/* @0x217d18 ldrb r3, [r0, #0x5] */
/* @0x217d1c cmp r3, #0 */
/* @0x217d20 bne 0x217d2c <_Z22Audio_ResumeSoundNoiseP6CNoise+0x3c> */
/* @0x217d24 add sp, sp, #12 */
/* @0x217d28 pop {r4, r5, pc} */
/* @0x217d2c ldr r0, [r0, #0x18] */
/* @0x217d30 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x217d34 cmp r0, #0 */
/* @0x217d38 beq 0x217d24 <_Z22Audio_ResumeSoundNoiseP6CNoise+0x34> */
/* @0x217d3c ldrb r3, [r0, #0x24] */
/* @0x217d40 cmp r3, #0 */
/* @0x217d44 bne 0x217dc8 <_Z22Audio_ResumeSoundNoiseP6CNoise+0xd8> */
/* @0x217d48 ldrb r3, [r0, #0x25] */
/* @0x217d4c cmp r3, #0 */
/* @0x217d50 bne 0x217dc8 <_Z22Audio_ResumeSoundNoiseP6CNoise+0xd8> */
/* @0x217d54 ldr r5, [pc, #0x88] */
/* @0x217d58 add r2, sp, #4 */
/* @0x217d5c ldr r0, [r4, #0x10] */
/* @0x217d60 movw r1, #0x1010 */
/* @0x217d64 ldr r5, [pc, r5] */
/* @0x217d68 ldr r3, [r5] */
/* @0x217d6c ldr r0, [r3, r0, lsl #2] */
/* @0x217d70 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x217d74 ldr r2, [sp, #0x4] */
/* @0x217d78 movw r3, #0x1013 */
/* @0x217d7c cmp r2, r3 */
/* @0x217d80 bne 0x217d24 <_Z22Audio_ResumeSoundNoiseP6CNoise+0x34> */
/* @0x217d84 ldr r3, [r5] */
/* @0x217d88 ldr r2, [r4, #0x10] */
/* @0x217d8c ldr r0, [r3, r2, lsl #2] */
/* @0x217d90 bl 0xb6a84 <alSourcePlay@plt> */
/* @0x217d94 bl 0xb6a54 <alGetError@plt> */
/* @0x217d98 subs r3, r0, #0 */
/* @0x217d9c beq 0x217d24 <_Z22Audio_ResumeSoundNoiseP6CNoise+0x34> */
/* @0x217da0 ldr r0, [pc, #0x40] */
/* @0x217da4 ldr r1, [pc, #0x40] */
/* @0x217da8 ldr r0, [pc, r0] */
/* @0x217dac ldr r2, [r4, #0x18] */
/* @0x217db0 add r1, pc, r1 */
/* @0x217db4 ldr r0, [r0] */
/* @0x217db8 ldr r12, [r0] */
/* @0x217dbc ldr r12, [r12, #0xc] */
/* @0x217dc0 blx r12 */
/* @0x217dc4 b 0x217d24 <_Z22Audio_ResumeSoundNoiseP6CNoise+0x34> */
/* @0x217dc8 ldr r0, [pc, #0x20] */
/* @0x217dcc ldr r1, [r4, #0x10] */
/* @0x217dd0 add r0, pc, r0 */
/* @0x217dd4 bl 0x226500 <_ZN9COggAudio12Resume_SoundEi> */
/* @0x217dd8 add sp, sp, #12 */
/* @0x217ddc pop {r4, r5, pc} */
/* @0x217de0 andseq r7, sp, r4, asr r3 */
/* @0x217de4 andseq r9, sp, r8, ror #12 */
/* @0x217de8 andseq r5, sp, r12, ror #18 */
/* @0x217dec ldrsbeq r11, [r3], -r8 */
/* @0x217df0 subseq sp, r3, r4, asr #9 */

/* ── FUNC 0x217df4 · Audio_ResumeAll() · size=168 · insn=42 */
/* @0x217df4 push {r3, r4, r5, r6, r7, lr} */
/* @0x217df8 ldr r3, [pc, #0x88] */
/* @0x217dfc ldr r3, [pc, r3] */
/* @0x217e00 ldrb r4, [r3] */
/* @0x217e04 cmp r4, #0 */
/* @0x217e08 popne {r3, r4, r5, r6, r7, pc} */
/* @0x217e0c ldr r3, [pc, #0x78] */
/* @0x217e10 ldr r3, [pc, r3] */
/* @0x217e14 ldrb r3, [r3] */
/* @0x217e18 cmp r3, #0 */
/* @0x217e1c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x217e20 ldr r3, [pc, #0x68] */
/* @0x217e24 add r3, pc, r3 */
/* @0x217e28 ldr r5, [r3, #0x38] */
/* @0x217e2c cmp r5, #0 */
/* @0x217e30 pople {r3, r4, r5, r6, r7, pc} */
/* @0x217e34 ldr r7, [pc, #0x58] */
/* @0x217e38 mov r3, r5 */
/* @0x217e3c ldr r6, [pc, #0x54] */
/* @0x217e40 add r7, pc, r7 */
/* @0x217e44 add r6, pc, r6 */
/* @0x217e48 b 0x217e5c <_Z15Audio_ResumeAllv+0x68> */
/* @0x217e4c add r4, r4, #1 */
/* @0x217e50 cmp r4, r5 */
/* @0x217e54 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x217e58 ldr r3, [r6, #0x38] */
/* @0x217e5c cmp r4, r3 */
/* @0x217e60 bge 0x217e4c <_Z15Audio_ResumeAllv+0x58> */
/* @0x217e64 ldr r3, [r7, #0x3c] */
/* @0x217e68 ldr r0, [r3, r4, lsl #2] */
/* @0x217e6c cmp r0, #0 */
/* @0x217e70 beq 0x217e4c <_Z15Audio_ResumeAllv+0x58> */
/* @0x217e74 ldrb r3, [r0, #0x5] */
/* @0x217e78 cmp r3, #0 */
/* @0x217e7c beq 0x217e4c <_Z15Audio_ResumeAllv+0x58> */
/* @0x217e80 bl 0x217cf0 <_Z22Audio_ResumeSoundNoiseP6CNoise> */
/* @0x217e84 b 0x217e4c <_Z15Audio_ResumeAllv+0x58> */
/* @0x217e88 andseq r7, sp, r0, asr r2 */
/* @0x217e8c andseq r6, sp, r0, lsr #30 */
/* @0x217e90 subseq sp, r3, r0, ror r4 */
/* @0x217e94 subseq sp, r3, r4, asr r4 */
/* @0x217e98 subseq sp, r3, r0, asr r4 */

/* ── FUNC 0x217e9c · Audio_ResumeSound(int) · size=208 · insn=52 */
/* @0x217e9c ldr r3, [pc, #0xb0] */
/* @0x217ea0 push {r4, r5, r6, r7, r8, lr} */
/* @0x217ea4 ldr r3, [pc, r3] */
/* @0x217ea8 mov r5, r0 */
/* @0x217eac ldrb r4, [r3] */
/* @0x217eb0 cmp r4, #0 */
/* @0x217eb4 popne {r4, r5, r6, r7, r8, pc} */
/* @0x217eb8 ldr r3, [pc, #0x98] */
/* @0x217ebc ldr r3, [pc, r3] */
/* @0x217ec0 ldrb r3, [r3] */
/* @0x217ec4 cmp r3, #0 */
/* @0x217ec8 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x217ecc ldr r3, [pc, #0x88] */
/* @0x217ed0 ldr r3, [pc, r3] */
/* @0x217ed4 ldr r3, [r3] */
/* @0x217ed8 cmp r3, r0 */
/* @0x217edc ble 0x217f48 <_Z17Audio_ResumeSoundi+0xac> */
/* @0x217ee0 ldr r3, [pc, #0x78] */
/* @0x217ee4 add r3, pc, r3 */
/* @0x217ee8 ldr r6, [r3, #0x38] */
/* @0x217eec cmp r6, #0 */
/* @0x217ef0 pople {r4, r5, r6, r7, r8, pc} */
/* @0x217ef4 ldr r8, [pc, #0x68] */
/* @0x217ef8 mov r3, r6 */
/* @0x217efc ldr r7, [pc, #0x64] */
/* @0x217f00 add r8, pc, r8 */
/* @0x217f04 add r7, pc, r7 */
/* @0x217f08 b 0x217f1c <_Z17Audio_ResumeSoundi+0x80> */
/* @0x217f0c add r4, r4, #1 */
/* @0x217f10 cmp r4, r6 */
/* @0x217f14 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x217f18 ldr r3, [r7, #0x38] */
/* @0x217f1c cmp r4, r3 */
/* @0x217f20 bge 0x217f0c <_Z17Audio_ResumeSoundi+0x70> */
/* @0x217f24 ldr r3, [r8, #0x3c] */
/* @0x217f28 ldr r0, [r3, r4, lsl #2] */
/* @0x217f2c cmp r0, #0 */
/* @0x217f30 beq 0x217f0c <_Z17Audio_ResumeSoundi+0x70> */
/* @0x217f34 ldr r2, [r0, #0x18] */
/* @0x217f38 cmp r2, r5 */
/* @0x217f3c bne 0x217f0c <_Z17Audio_ResumeSoundi+0x70> */
/* @0x217f40 bl 0x217cf0 <_Z22Audio_ResumeSoundNoiseP6CNoise> */
/* @0x217f44 b 0x217f0c <_Z17Audio_ResumeSoundi+0x70> */
/* @0x217f48 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x217f4c pop {r4, r5, r6, r7, r8, lr} */
/* @0x217f50 b 0x217cf0 <_Z22Audio_ResumeSoundNoiseP6CNoise> */
/* @0x217f54 andseq r7, sp, r8, lsr #3 */
/* @0x217f58 andseq r6, sp, r4, ror lr */
/* @0x217f5c andseq r9, sp, r4, lsl r5 */
/* @0x217f60 ldrheq sp, [r3], #-48 */
/* @0x217f64 .word 0x0053d394 */
/* @0x217f68 .word 0x0053d390 */

/* ── FUNC 0x217f6c · Audio_PauseSound(int) · size=208 · insn=52 */
/* @0x217f6c ldr r3, [pc, #0xb0] */
/* @0x217f70 push {r4, r5, r6, r7, r8, lr} */
/* @0x217f74 ldr r3, [pc, r3] */
/* @0x217f78 mov r5, r0 */
/* @0x217f7c ldrb r4, [r3] */
/* @0x217f80 cmp r4, #0 */
/* @0x217f84 popne {r4, r5, r6, r7, r8, pc} */
/* @0x217f88 ldr r3, [pc, #0x98] */
/* @0x217f8c ldr r3, [pc, r3] */
/* @0x217f90 ldrb r3, [r3] */
/* @0x217f94 cmp r3, #0 */
/* @0x217f98 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x217f9c ldr r3, [pc, #0x88] */
/* @0x217fa0 ldr r3, [pc, r3] */
/* @0x217fa4 ldr r3, [r3] */
/* @0x217fa8 cmp r3, r0 */
/* @0x217fac ble 0x218018 <_Z16Audio_PauseSoundi+0xac> */
/* @0x217fb0 ldr r3, [pc, #0x78] */
/* @0x217fb4 add r3, pc, r3 */
/* @0x217fb8 ldr r6, [r3, #0x38] */
/* @0x217fbc cmp r6, #0 */
/* @0x217fc0 pople {r4, r5, r6, r7, r8, pc} */
/* @0x217fc4 ldr r8, [pc, #0x68] */
/* @0x217fc8 mov r3, r6 */
/* @0x217fcc ldr r7, [pc, #0x64] */
/* @0x217fd0 add r8, pc, r8 */
/* @0x217fd4 add r7, pc, r7 */
/* @0x217fd8 b 0x217fec <_Z16Audio_PauseSoundi+0x80> */
/* @0x217fdc add r4, r4, #1 */
/* @0x217fe0 cmp r4, r6 */
/* @0x217fe4 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x217fe8 ldr r3, [r7, #0x38] */
/* @0x217fec cmp r4, r3 */
/* @0x217ff0 bge 0x217fdc <_Z16Audio_PauseSoundi+0x70> */
/* @0x217ff4 ldr r3, [r8, #0x3c] */
/* @0x217ff8 ldr r0, [r3, r4, lsl #2] */
/* @0x217ffc cmp r0, #0 */
/* @0x218000 beq 0x217fdc <_Z16Audio_PauseSoundi+0x70> */
/* @0x218004 ldr r2, [r0, #0x18] */
/* @0x218008 cmp r2, r5 */
/* @0x21800c bne 0x217fdc <_Z16Audio_PauseSoundi+0x70> */
/* @0x218010 bl 0x217b44 <_Z21Audio_PauseSoundNoiseP6CNoise> */
/* @0x218014 b 0x217fdc <_Z16Audio_PauseSoundi+0x70> */
/* @0x218018 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x21801c pop {r4, r5, r6, r7, r8, lr} */
/* @0x218020 b 0x217b44 <_Z21Audio_PauseSoundNoiseP6CNoise> */
/* @0x218024 ldrsbeq r7, [sp], -r8 */
/* @0x218028 andseq r6, sp, r4, lsr #27 */
/* @0x21802c andseq r9, sp, r4, asr #8 */
/* @0x218030 subseq sp, r3, r0, ror #5 */
/* @0x218034 subseq sp, r3, r4, asr #5 */
/* @0x218038 subseq sp, r3, r0, asr #5 */

/* ── FUNC 0x21803c · Audio_SetEmitterGain(int, double) · size=112 · insn=28 */
/* @0x21803c ldr r1, [pc, #0x5c] */
/* @0x218040 vmov d7, r2, r3 */
/* @0x218044 ldr r1, [pc, r1] */
/* @0x218048 ldrb r3, [r1] */
/* @0x21804c cmp r3, #0 */
/* @0x218050 bxne lr */
/* @0x218054 ldr r3, [pc, #0x48] */
/* @0x218058 ldr r3, [pc, r3] */
/* @0x21805c ldrb r3, [r3] */
/* @0x218060 cmp r3, #0 */
/* @0x218064 bxeq lr */
/* @0x218068 vcmpe.f64 d7, #0 */
/* @0x21806c vmrs APSR_nzcv, fpscr */
/* @0x218070 bxlt lr */
/* @0x218074 cmp r0, #0 */
/* @0x218078 bxlt lr */
/* @0x21807c ldr r3, [pc, #0x24] */
/* @0x218080 add r3, pc, r3 */
/* @0x218084 ldr r2, [r3, #0x40] */
/* @0x218088 cmp r0, r2 */
/* @0x21808c vcvtlt.f32.f64 s14, d7 */
/* @0x218090 ldrlt r3, [r3, #0x44] */
/* @0x218094 ldrlt r3, [r3, r0, lsl #2] */
/* @0x218098 vstrlt s14, [r3, #40] */
/* @0x21809c bx lr */
/* @0x2180a0 andseq r7, sp, r8 */
/* @0x2180a4 ldrsbeq r6, [sp], -r8 */
/* @0x2180a8 subseq sp, r3, r4, lsl r2 */

/* ── FUNC 0x2180ac · Audio_GetEmitterGain(int) · size=104 · insn=26 */
/* @0x2180ac ldr r3, [pc, #0x54] */
/* @0x2180b0 ldr r3, [pc, r3] */
/* @0x2180b4 ldrb r3, [r3] */
/* @0x2180b8 cmp r3, #0 */
/* @0x2180bc bne 0x218100 <_Z20Audio_GetEmitterGaini+0x54> */
/* @0x2180c0 ldr r3, [pc, #0x44] */
/* @0x2180c4 ldr r3, [pc, r3] */
/* @0x2180c8 ldrb r3, [r3] */
/* @0x2180cc cmp r3, #0 */
/* @0x2180d0 beq 0x218100 <_Z20Audio_GetEmitterGaini+0x54> */
/* @0x2180d4 cmp r0, #0 */
/* @0x2180d8 blt 0x218100 <_Z20Audio_GetEmitterGaini+0x54> */
/* @0x2180dc ldr r3, [pc, #0x2c] */
/* @0x2180e0 add r3, pc, r3 */
/* @0x2180e4 ldr r2, [r3, #0x40] */
/* @0x2180e8 cmp r0, r2 */
/* @0x2180ec bge 0x218100 <_Z20Audio_GetEmitterGaini+0x54> */
/* @0x2180f0 ldr r3, [r3, #0x44] */
/* @0x2180f4 ldr r3, [r3, r0, lsl #2] */
/* @0x2180f8 ldr r0, [r3, #0x28] */
/* @0x2180fc bx lr */
/* @0x218100 mov r0, #0 */
/* @0x218104 bx lr */
/* @0x218108 mulseq sp, r12, pc */
/* @0x21810c andseq r6, sp, r12, ror #24 */
/* @0x218110 ldrheq sp, [r3], #-20 */

/* ── FUNC 0x218114 · anon_218114 · size=0 · insn=1 */
/* @0x218114 andeq r0, r0, r0 */

/* ── FUNC 0x218118 · Audio_SetMasterGain(int, double) · size=116 · insn=27 */
/* @0x218118 ldr r1, [pc, #0x60] */
/* @0x21811c vmov d7, r2, r3 */
/* @0x218120 ldr r1, [pc, r1] */
/* @0x218124 ldrb r3, [r1] */
/* @0x218128 cmp r3, #0 */
/* @0x21812c bxne lr */
/* @0x218130 ldr r3, [pc, #0x4c] */
/* @0x218134 ldr r3, [pc, r3] */
/* @0x218138 ldrb r3, [r3] */
/* @0x21813c cmp r3, #0 */
/* @0x218140 bxeq lr */
/* @0x218144 vcmp.f64 d7, #0 */
/* @0x218148 vldr d6, [pc, #40] */
/* @0x21814c vmrs APSR_nzcv, fpscr */
/* @0x218150 vmovmi.f64 d7, d6 */
/* @0x218154 cmp r0, #0 */
/* @0x218158 bxne lr */
/* @0x21815c vcvt.f32.f64 s13, d7 */
/* @0x218160 ldr r3, [pc, #0x20] */
/* @0x218164 ldr r3, [pc, r3] */
/* @0x218168 ldr r0, [r3] */
/* @0x21816c vmov r1, s13 */
/* @0x218170 b 0x215b34 <_ZN9CListener7SetGainEf> */
/* @0x218174 nop */
/* @0x218180 andseq r6, sp, r12, lsr #30 */
/* @0x218184 ldrsheq r6, [sp], -r12 */
/* @0x218188 andseq r9, sp, r8, ror r2 */

/* ── FUNC 0x21818c · anon_21818c · size=0 · insn=1 */
/* @0x21818c nop */

/* ── FUNC 0x218190 · Audio_GetMasterGain(int) · size=44 · insn=11 */
/* @0x218190 cmp r0, #0 */
/* @0x218194 bne 0x2181b0 <_Z19Audio_GetMasterGaini+0x20> */
/* @0x218198 ldr r3, [pc, #0x18] */
/* @0x21819c ldr r3, [pc, r3] */
/* @0x2181a0 ldr r0, [r3] */
/* @0x2181a4 cmp r0, #0 */
/* @0x2181a8 beq 0x2181b0 <_Z19Audio_GetMasterGaini+0x20> */
/* @0x2181ac b 0x215b40 <_ZN9CListener7GetGainEv> */
/* @0x2181b0 mov r0, #0 */
/* @0x2181b4 bx lr */
/* @0x2181b8 andseq r9, sp, r0, asr #4 */

/* ── FUNC 0x2181bc · Audio_SetEmitterPitch(int, double) · size=292 · insn=73 */
/* @0x2181bc ldr r1, [pc, #0x10c] */
/* @0x2181c0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2181c4 vpush {d8} */
/* @0x2181c8 ldr r1, [pc, r1] */
/* @0x2181cc vmov d8, r2, r3 */
/* @0x2181d0 ldrb r4, [r1] */
/* @0x2181d4 cmp r4, #0 */
/* @0x2181d8 bne 0x2182c8 <_Z21Audio_SetEmitterPitchid+0x10c> */
/* @0x2181dc ldr r3, [pc, #0xf0] */
/* @0x2181e0 ldr r3, [pc, r3] */
/* @0x2181e4 ldrb r3, [r3] */
/* @0x2181e8 cmp r3, #0 */
/* @0x2181ec beq 0x2182c8 <_Z21Audio_SetEmitterPitchid+0x10c> */
/* @0x2181f0 vcmpe.f64 d8, #0 */
/* @0x2181f4 vmrs APSR_nzcv, fpscr */
/* @0x2181f8 blt 0x2182c8 <_Z21Audio_SetEmitterPitchid+0x10c> */
/* @0x2181fc cmp r0, #0 */
/* @0x218200 blt 0x2182c8 <_Z21Audio_SetEmitterPitchid+0x10c> */
/* @0x218204 ldr r3, [pc, #0xcc] */
/* @0x218208 add r3, pc, r3 */
/* @0x21820c ldr r2, [r3, #0x40] */
/* @0x218210 cmp r0, r2 */
/* @0x218214 bge 0x2182c8 <_Z21Audio_SetEmitterPitchid+0x10c> */
/* @0x218218 ldr r3, [r3, #0x44] */
/* @0x21821c vcvt.f32.f64 s15, d8 */
/* @0x218220 ldr r6, [r3, r0, lsl #2] */
/* @0x218224 ldr r7, [r6, #0x34] */
/* @0x218228 vstr s15, [r6, #44] */
/* @0x21822c cmp r7, #0 */
/* @0x218230 ble 0x2182c8 <_Z21Audio_SetEmitterPitchid+0x10c> */
/* @0x218234 mov r3, r7 */
/* @0x218238 b 0x218240 <_Z21Audio_SetEmitterPitchid+0x84> */
/* @0x21823c ldr r3, [r6, #0x34] */
/* @0x218240 cmp r4, r3 */
/* @0x218244 bge 0x2182bc <_Z21Audio_SetEmitterPitchid+0x100> */
/* @0x218248 ldr r3, [r6, #0x38] */
/* @0x21824c ldr r5, [r3, r4, lsl #2] */
/* @0x218250 cmp r5, #0 */
/* @0x218254 beq 0x2182bc <_Z21Audio_SetEmitterPitchid+0x100> */
/* @0x218258 ldrb r3, [r5, #0x5] */
/* @0x21825c cmp r3, #0 */
/* @0x218260 beq 0x2182bc <_Z21Audio_SetEmitterPitchid+0x100> */
/* @0x218264 ldr r3, [r5, #0x8] */
/* @0x218268 cmp r3, #0 */
/* @0x21826c bne 0x2182bc <_Z21Audio_SetEmitterPitchid+0x100> */
/* @0x218270 ldr r3, [r5, #0x10] */
/* @0x218274 cmp r3, #0 */
/* @0x218278 blt 0x2182bc <_Z21Audio_SetEmitterPitchid+0x100> */
/* @0x21827c ldr r0, [r5, #0x18] */
/* @0x218280 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x218284 ldr r3, [pc, #0x50] */
/* @0x218288 movw r1, #0x1003 */
/* @0x21828c cmp r0, #0 */
/* @0x218290 beq 0x2182bc <_Z21Audio_SetEmitterPitchid+0x100> */
/* @0x218294 vldr s14, [r6, #44] */
/* @0x218298 vcvt.f64.f32 d7, s14 */
/* @0x21829c ldr r3, [pc, r3] */
/* @0x2182a0 ldr r2, [r5, #0x10] */
/* @0x2182a4 ldr r3, [r3] */
/* @0x2182a8 ldr r0, [r3, r2, lsl #2] */
/* @0x2182ac vmul.f64 d7, d7, d8 */
/* @0x2182b0 vcvt.f32.f64 s13, d7 */
/* @0x2182b4 vmov r2, s13 */
/* @0x2182b8 bl 0xb6a78 <alSourcef@plt> */
/* @0x2182bc add r4, r4, #1 */
/* @0x2182c0 cmp r4, r7 */
/* @0x2182c4 bne 0x21823c <_Z21Audio_SetEmitterPitchid+0x80> */
/* @0x2182c8 vpop {d8} */
/* @0x2182cc pop {r3, r4, r5, r6, r7, pc} */
/* @0x2182d0 andseq r6, sp, r4, lsl #29 */
/* @0x2182d4 andseq r6, sp, r0, asr r11 */
/* @0x2182d8 subseq sp, r3, r12, lsl #1 */
/* @0x2182dc andseq r9, sp, r0, lsr r1 */

/* ── FUNC 0x2182e0 · Audio_GetEmitterPitch(int) · size=104 · insn=26 */
/* @0x2182e0 ldr r3, [pc, #0x54] */
/* @0x2182e4 ldr r3, [pc, r3] */
/* @0x2182e8 ldrb r3, [r3] */
/* @0x2182ec cmp r3, #0 */
/* @0x2182f0 bne 0x218334 <_Z21Audio_GetEmitterPitchi+0x54> */
/* @0x2182f4 ldr r3, [pc, #0x44] */
/* @0x2182f8 ldr r3, [pc, r3] */
/* @0x2182fc ldrb r3, [r3] */
/* @0x218300 cmp r3, #0 */
/* @0x218304 beq 0x218334 <_Z21Audio_GetEmitterPitchi+0x54> */
/* @0x218308 cmp r0, #0 */
/* @0x21830c blt 0x218334 <_Z21Audio_GetEmitterPitchi+0x54> */
/* @0x218310 ldr r3, [pc, #0x2c] */
/* @0x218314 add r3, pc, r3 */
/* @0x218318 ldr r2, [r3, #0x40] */
/* @0x21831c cmp r0, r2 */
/* @0x218320 bge 0x218334 <_Z21Audio_GetEmitterPitchi+0x54> */
/* @0x218324 ldr r3, [r3, #0x44] */
/* @0x218328 ldr r3, [r3, r0, lsl #2] */
/* @0x21832c ldr r0, [r3, #0x2c] */
/* @0x218330 bx lr */
/* @0x218334 mov r0, #1065353216 */
/* @0x218338 bx lr */
/* @0x21833c andseq r6, sp, r8, ror #26 */
/* @0x218340 andseq r6, sp, r8, lsr r10 */
/* @0x218344 subseq r12, r3, r0, lsl #31 */

/* ── FUNC 0x218348 · Audio_GetName(int) · size=148 · insn=37 */
/* @0x218348 push {r3, lr} */
/* @0x21834c mov r2, r0 */
/* @0x218350 ldr r3, [pc, #0x70] */
/* @0x218354 ldr r3, [pc, r3] */
/* @0x218358 ldrb r3, [r3] */
/* @0x21835c cmp r3, #0 */
/* @0x218360 beq 0x2183bc <_Z13Audio_GetNamei+0x74> */
/* @0x218364 ldr r3, [pc, #0x60] */
/* @0x218368 ldr r3, [pc, r3] */
/* @0x21836c ldr r3, [r3] */
/* @0x218370 cmp r0, r3 */
/* @0x218374 bge 0x2183a0 <_Z13Audio_GetNamei+0x58> */
/* @0x218378 cmp r2, #0 */
/* @0x21837c blt 0x2183b0 <_Z13Audio_GetNamei+0x68> */
/* @0x218380 ldr r3, [pc, #0x48] */
/* @0x218384 add r3, pc, r3 */
/* @0x218388 ldr r1, [r3, #0x20] */
/* @0x21838c cmp r2, r1 */
/* @0x218390 bge 0x2183b0 <_Z13Audio_GetNamei+0x68> */
/* @0x218394 ldr r3, [r3, #0x4c] */
/* @0x218398 ldr r0, [r3, r2, lsl #2] */
/* @0x21839c pop {r3, pc} */
/* @0x2183a0 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x2183a4 cmp r0, #0 */
/* @0x2183a8 ldrne r2, [r0, #0x18] */
/* @0x2183ac bne 0x218378 <_Z13Audio_GetNamei+0x30> */
/* @0x2183b0 ldr r0, [pc, #0x1c] */
/* @0x2183b4 add r0, pc, r0 */
/* @0x2183b8 pop {r3, pc} */
/* @0x2183bc ldr r0, [pc, #0x14] */
/* @0x2183c0 add r0, pc, r0 */
/* @0x2183c4 pop {r3, pc} */
/* @0x2183c8 ldrsbeq r6, [sp], -r12 */
/* @0x2183cc andseq r9, sp, r12, ror r0 */
/* @0x2183d0 subseq r12, r3, r0, lsl pc */
/* @0x2183d4 andseq r8, r1, r12, lsl #14 */
/* @0x2183d8 andseq r8, r1, r0, lsl #14 */

/* ── FUNC 0x2183dc · Audio_SoundGetListenerMask(int) · size=104 · insn=26 */
/* @0x2183dc push {r3, lr} */
/* @0x2183e0 ldr r3, [pc, #0x50] */
/* @0x2183e4 ldr r3, [pc, r3] */
/* @0x2183e8 ldrb r3, [r3] */
/* @0x2183ec cmp r3, #0 */
/* @0x2183f0 bne 0x21841c <_Z26Audio_SoundGetListenerMaski+0x40> */
/* @0x2183f4 ldr r3, [pc, #0x40] */
/* @0x2183f8 ldr r3, [pc, r3] */
/* @0x2183fc ldrb r3, [r3] */
/* @0x218400 cmp r3, #0 */
/* @0x218404 beq 0x21841c <_Z26Audio_SoundGetListenerMaski+0x40> */
/* @0x218408 ldr r3, [pc, #0x30] */
/* @0x21840c ldr r3, [pc, r3] */
/* @0x218410 ldr r3, [r3] */
/* @0x218414 cmp r3, r0 */
/* @0x218418 ble 0x218424 <_Z26Audio_SoundGetListenerMaski+0x48> */
/* @0x21841c mov r0, #1 */
/* @0x218420 pop {r3, pc} */
/* @0x218424 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x218428 cmp r0, #0 */
/* @0x21842c beq 0x21841c <_Z26Audio_SoundGetListenerMaski+0x40> */
/* @0x218430 ldr r0, [r0, #0x34] */
/* @0x218434 pop {r3, pc} */
/* @0x218438 andseq r6, sp, r8, ror #24 */
/* @0x21843c andseq r6, sp, r8, lsr r9 */
/* @0x218440 ldrsbeq r8, [sp], -r8 */

/* ── FUNC 0x218444 · Audio_SoundSetListenerMask(int, unsigned int) · size=116 · insn=29 */
/* @0x218444 ldr r3, [pc, #0x60] */
/* @0x218448 str lr, [sp, #-0x4]! */
/* @0x21844c ldr r3, [pc, r3] */
/* @0x218450 sub sp, sp, #12 */
/* @0x218454 ldrb r3, [r3] */
/* @0x218458 cmp r3, #0 */
/* @0x21845c bne 0x218488 <_Z26Audio_SoundSetListenerMaskij+0x44> */
/* @0x218460 ldr r3, [pc, #0x48] */
/* @0x218464 ldr r3, [pc, r3] */
/* @0x218468 ldrb r3, [r3] */
/* @0x21846c cmp r3, #0 */
/* @0x218470 beq 0x218488 <_Z26Audio_SoundSetListenerMaskij+0x44> */
/* @0x218474 ldr r3, [pc, #0x38] */
/* @0x218478 ldr r3, [pc, r3] */
/* @0x21847c ldr r3, [r3] */
/* @0x218480 cmp r3, r0 */
/* @0x218484 ble 0x218490 <_Z26Audio_SoundSetListenerMaskij+0x4c> */
/* @0x218488 add sp, sp, #12 */
/* @0x21848c ldr pc, [sp], #4 */
/* @0x218490 str r1, [sp, #0x4] */
/* @0x218494 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x218498 ldr r1, [sp, #0x4] */
/* @0x21849c cmp r0, #0 */
/* @0x2184a0 strne r1, [r0, #0x34] */
/* @0x2184a4 add sp, sp, #12 */
/* @0x2184a8 ldr pc, [sp], #4 */
/* @0x2184ac andseq r6, sp, r0, lsl #24 */
/* @0x2184b0 andseq r6, sp, r12, asr #17 */
/* @0x2184b4 andseq r8, sp, r12, ror #30 */

/* ── FUNC 0x2184b8 · Audio_EmitterGetListenerMask(int) · size=104 · insn=26 */
/* @0x2184b8 ldr r3, [pc, #0x54] */
/* @0x2184bc ldr r3, [pc, r3] */
/* @0x2184c0 ldrb r3, [r3] */
/* @0x2184c4 cmp r3, #0 */
/* @0x2184c8 bne 0x21850c <_Z28Audio_EmitterGetListenerMaski+0x54> */
/* @0x2184cc ldr r3, [pc, #0x44] */
/* @0x2184d0 ldr r3, [pc, r3] */
/* @0x2184d4 ldrb r3, [r3] */
/* @0x2184d8 cmp r3, #0 */
/* @0x2184dc beq 0x21850c <_Z28Audio_EmitterGetListenerMaski+0x54> */
/* @0x2184e0 cmp r0, #0 */
/* @0x2184e4 blt 0x21850c <_Z28Audio_EmitterGetListenerMaski+0x54> */
/* @0x2184e8 ldr r3, [pc, #0x2c] */
/* @0x2184ec add r3, pc, r3 */
/* @0x2184f0 ldr r2, [r3, #0x40] */
/* @0x2184f4 cmp r0, r2 */
/* @0x2184f8 bge 0x21850c <_Z28Audio_EmitterGetListenerMaski+0x54> */
/* @0x2184fc ldr r3, [r3, #0x44] */
/* @0x218500 ldr r3, [r3, r0, lsl #2] */
/* @0x218504 ldr r0, [r3, #0x30] */
/* @0x218508 bx lr */
/* @0x21850c mov r0, #1 */
/* @0x218510 bx lr */
/* @0x218514 mulseq sp, r0, r11 */
/* @0x218518 andseq r6, sp, r0, ror #16 */
/* @0x21851c subseq r12, r3, r8, lsr #27 */

/* ── FUNC 0x218520 · Audio_EmitterSetListenerMask(int, unsigned int) · size=92 · insn=23 */
/* @0x218520 ldr r3, [pc, #0x48] */
/* @0x218524 ldr r3, [pc, r3] */
/* @0x218528 ldrb r3, [r3] */
/* @0x21852c cmp r3, #0 */
/* @0x218530 bxne lr */
/* @0x218534 ldr r3, [pc, #0x38] */
/* @0x218538 ldr r3, [pc, r3] */
/* @0x21853c ldrb r3, [r3] */
/* @0x218540 cmp r3, #0 */
/* @0x218544 bxeq lr */
/* @0x218548 cmp r0, #0 */
/* @0x21854c bxlt lr */
/* @0x218550 ldr r3, [pc, #0x20] */
/* @0x218554 add r3, pc, r3 */
/* @0x218558 ldr r2, [r3, #0x40] */
/* @0x21855c cmp r0, r2 */
/* @0x218560 ldrlt r3, [r3, #0x44] */
/* @0x218564 ldrlt r3, [r3, r0, lsl #2] */
/* @0x218568 strlt r1, [r3, #0x30] */
/* @0x21856c bx lr */
/* @0x218570 andseq r6, sp, r8, lsr #22 */
/* @0x218574 ldrsheq r6, [sp], -r8 */
/* @0x218578 subseq r12, r3, r0, asr #26 */

/* ── FUNC 0x21857c · Audio_GetListenerMask() · size=20 · insn=5 */
/* @0x21857c ldr r3, [pc, #0x8] */
/* @0x218580 ldr r3, [pc, r3] */
/* @0x218584 ldr r0, [r3] */
/* @0x218588 bx lr */
/* @0x21858c andseq r8, sp, r8, asr #28 */

/* ── FUNC 0x218590 · Audio_SetListenerMask(unsigned int) · size=20 · insn=5 */
/* @0x218590 ldr r3, [pc, #0x8] */
/* @0x218594 ldr r3, [pc, r3] */
/* @0x218598 str r0, [r3] */
/* @0x21859c bx lr */
/* @0x2185a0 andseq r8, sp, r4, lsr lr */

/* ── FUNC 0x2185a4 · Audio_GetListenerInfo(int) · size=148 · insn=37 */
/* @0x2185a4 subs r12, r0, #0 */
/* @0x2185a8 push {r4, r5, r6, r7, r8, lr} */
/* @0x2185ac sub sp, sp, #40 */
/* @0x2185b0 bne 0x218620 <_Z21Audio_GetListenerInfoi+0x7c> */
/* @0x2185b4 ldr r1, [pc, #0x6c] */
/* @0x2185b8 mov r4, #0 */
/* @0x2185bc ldr r8, [pc, #0x68] */
/* @0x2185c0 mov r5, #0 */
/* @0x2185c4 ldr r1, [pc, r1] */
/* @0x2185c8 ldr lr, [pc, #0x60] */
/* @0x2185cc mov r6, #0 */
/* @0x2185d0 mov r7, #0 */
/* @0x2185d4 ldr r1, [r1] */
/* @0x2185d8 movt r7, #0x3ff0 */
/* @0x2185dc add r8, pc, r8 */
/* @0x2185e0 add lr, pc, lr */
/* @0x2185e4 mov r2, r4 */
/* @0x2185e8 mov r3, r5 */
/* @0x2185ec str r1, [sp] */
/* @0x2185f0 mov r0, #3 */
/* @0x2185f4 ldr r1, [pc, #0x38] */
/* @0x2185f8 strd r4, r5, [sp, #24] */
/* @0x2185fc str r12, [sp, #0x10] */
/* @0x218600 add r1, pc, r1 */
/* @0x218604 str r12, [sp, #0x20] */
/* @0x218608 str r8, [sp, #0x4] */
/* @0x21860c str lr, [sp, #0x14] */
/* @0x218610 strd r6, r7, [sp, #8] */
/* @0x218614 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x218618 add sp, sp, #40 */
/* @0x21861c pop {r4, r5, r6, r7, r8, pc} */
/* @0x218620 mvn r0, #0 */
/* @0x218624 b 0x218618 <_Z21Audio_GetListenerInfoi+0x74> */
/* @0x218628 andseq r8, sp, r4, lsr #28 */
/* @0x21862c ldrsbeq r11, [r3], -r4 */
/* @0x218630 andseq sp, r2, r8, lsr #24 */
/* @0x218634 andseq r8, r1, r8, lsl #4 */

/* ── FUNC 0x218638 · Audio_GetListenerCount() · size=8 · insn=2 */
/* @0x218638 mov r0, #1 */
/* @0x21863c bx lr */

/* ── FUNC 0x218640 · Audio_SoundLength(int) · size=364 · insn=91 */
/* @0x218640 ldr r3, [pc, #0x154] */
/* @0x218644 push {r4, r5, lr} */
/* @0x218648 ldr r3, [pc, r3] */
/* @0x21864c sub sp, sp, #20 */
/* @0x218650 ldrb r3, [r3] */
/* @0x218654 cmp r3, #0 */
/* @0x218658 bne 0x218758 <_Z17Audio_SoundLengthi+0x118> */
/* @0x21865c ldr r3, [pc, #0x13c] */
/* @0x218660 ldr r3, [pc, r3] */
/* @0x218664 ldrb r3, [r3] */
/* @0x218668 cmp r3, #0 */
/* @0x21866c beq 0x218758 <_Z17Audio_SoundLengthi+0x118> */
/* @0x218670 ldr r3, [pc, #0x12c] */
/* @0x218674 ldr r3, [pc, r3] */
/* @0x218678 ldr r3, [r3] */
/* @0x21867c cmp r3, r0 */
/* @0x218680 ble 0x218768 <_Z17Audio_SoundLengthi+0x128> */
/* @0x218684 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x218688 mov r4, r0 */
/* @0x21868c cmp r4, #0 */
/* @0x218690 beq 0x218758 <_Z17Audio_SoundLengthi+0x118> */
/* @0x218694 vldr s15, [r4, #52] */
/* @0x218698 vcmpe.f32 s15, #0 */
/* @0x21869c vmrs APSR_nzcv, fpscr */
/* @0x2186a0 bge 0x21875c <_Z17Audio_SoundLengthi+0x11c> */
/* @0x2186a4 ldrb r3, [r4, #0x24] */
/* @0x2186a8 cmp r3, #0 */
/* @0x2186ac bne 0x218784 <_Z17Audio_SoundLengthi+0x144> */
/* @0x2186b0 ldrb r3, [r4, #0x25] */
/* @0x2186b4 cmp r3, #0 */
/* @0x2186b8 bne 0x218784 <_Z17Audio_SoundLengthi+0x144> */
/* @0x2186bc ldr r5, [r4, #0x18] */
/* @0x2186c0 cmn r5, #1 */
/* @0x2186c4 beq 0x21875c <_Z17Audio_SoundLengthi+0x11c> */
/* @0x2186c8 mov r0, r5 */
/* @0x2186cc movw r1, #0x2004 */
/* @0x2186d0 mov r2, sp */
/* @0x2186d4 bl 0xb6ac0 <alGetBufferi@plt> */
/* @0x2186d8 mov r0, r5 */
/* @0x2186dc movw r1, #0x2002 */
/* @0x2186e0 add r2, sp, #4 */
/* @0x2186e4 bl 0xb6ac0 <alGetBufferi@plt> */
/* @0x2186e8 mov r0, r5 */
/* @0x2186ec movw r1, #0x2003 */
/* @0x2186f0 add r2, sp, #8 */
/* @0x2186f4 bl 0xb6ac0 <alGetBufferi@plt> */
/* @0x2186f8 mov r0, r5 */
/* @0x2186fc movw r1, #0x2001 */
/* @0x218700 add r2, sp, #12 */
/* @0x218704 bl 0xb6ac0 <alGetBufferi@plt> */
/* @0x218708 bl 0xb6a54 <alGetError@plt> */
/* @0x21870c cmp r0, #0 */
/* @0x218710 bne 0x218758 <_Z17Audio_SoundLengthi+0x118> */
/* @0x218714 ldr r1, [sp, #0x8] */
/* @0x218718 ldr r0, [sp] */
/* @0x21871c bl 0x318c48 <__udivsi3> */
/* @0x218720 ldr r3, [sp, #0x4] */
/* @0x218724 cmp r3, #0 */
/* @0x218728 add r2, r3, #7 */
/* @0x21872c movge r1, r3 */
/* @0x218730 movlt r1, r2 */
/* @0x218734 asr r1, r1, #3 */
/* @0x218738 bl 0x318c48 <__udivsi3> */
/* @0x21873c vldr s13, [sp, #12] */
/* @0x218740 vcvt.f32.s32 s15, s13 */
/* @0x218744 vmov s13, r0 */
/* @0x218748 vcvt.f32.u32 s14, s13 */
/* @0x21874c vdiv.f32 s15, s14, s15 */
/* @0x218750 vstr s15, [r4, #52] */
/* @0x218754 b 0x21875c <_Z17Audio_SoundLengthi+0x11c> */
/* @0x218758 vmov.f32 s15, #-1.000000e+00 */
/* @0x21875c vmov r0, s15 */
/* @0x218760 add sp, sp, #20 */
/* @0x218764 pop {r4, r5, pc} */
/* @0x218768 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x21876c cmp r0, #0 */
/* @0x218770 beq 0x218758 <_Z17Audio_SoundLengthi+0x118> */
/* @0x218774 ldr r0, [r0, #0x18] */
/* @0x218778 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21877c mov r4, r0 */
/* @0x218780 b 0x21868c <_Z17Audio_SoundLengthi+0x4c> */
/* @0x218784 ldr r0, [pc, #0x1c] */
/* @0x218788 mov r1, r4 */
/* @0x21878c add r0, pc, r0 */
/* @0x218790 bl 0x22688c <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound> */
/* @0x218794 vldr s15, [r4, #52] */
/* @0x218798 b 0x21875c <_Z17Audio_SoundLengthi+0x11c> */
/* @0x21879c andseq r6, sp, r4, lsl #20 */
/* @0x2187a0 ldrsbeq r6, [sp], -r0 */
/* @0x2187a4 andseq r8, sp, r0, ror sp */
/* @0x2187a8 subseq r12, r3, r8, lsl #22 */

/* ── FUNC 0x2187ac · Audio_SetTrackPos(int, float) · size=348 · insn=87 */
/* @0x2187ac push {r3, r4, r5, lr} */
/* @0x2187b0 vpush {d8} */
/* @0x2187b4 vmov s16, r1 */
/* @0x2187b8 vldr s15, [pc, #300] */
/* @0x2187bc ldr r3, [pc, #0x12c] */
/* @0x2187c0 mov r4, r0 */
/* @0x2187c4 vcmp.f32 s16, s15 */
/* @0x2187c8 ldr r3, [pc, r3] */
/* @0x2187cc ldr r3, [r3] */
/* @0x2187d0 vmrs APSR_nzcv, fpscr */
/* @0x2187d4 vmovmi.f32 s16, s15 */
/* @0x2187d8 cmp r3, r0 */
/* @0x2187dc ble 0x218838 <_Z17Audio_SetTrackPosif+0x8c> */
/* @0x2187e0 sub r2, r0, #199680 */
/* @0x2187e4 movw r3, #0x869f */
/* @0x2187e8 sub r2, r2, #320 */
/* @0x2187ec movt r3, #0x1 */
/* @0x2187f0 cmp r2, r3 */
/* @0x2187f4 bls 0x2188c4 <_Z17Audio_SetTrackPosif+0x118> */
/* @0x2187f8 cmp r0, #0 */
/* @0x2187fc blt 0x218830 <_Z17Audio_SetTrackPosif+0x84> */
/* @0x218800 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x218804 subs r5, r0, #0 */
/* @0x218808 beq 0x218830 <_Z17Audio_SetTrackPosif+0x84> */
/* @0x21880c mov r0, r4 */
/* @0x218810 bl 0x218640 <_Z17Audio_SoundLengthi> */
/* @0x218814 vcmpe.f32 s16, #0 */
/* @0x218818 vmrs APSR_nzcv, fpscr */
/* @0x21881c vmov s15, r0 */
/* @0x218820 blt 0x218830 <_Z17Audio_SetTrackPosif+0x84> */
/* @0x218824 vcmpe.f32 s16, s15 */
/* @0x218828 vmrs APSR_nzcv, fpscr */
/* @0x21882c vstrmi s16, [r5, #72] */
/* @0x218830 vpop {d8} */
/* @0x218834 pop {r3, r4, r5, pc} */
/* @0x218838 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x21883c subs r4, r0, #0 */
/* @0x218840 beq 0x218830 <_Z17Audio_SetTrackPosif+0x84> */
/* @0x218844 ldr r0, [r4, #0x18] */
/* @0x218848 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21884c ldrb r3, [r0, #0x24] */
/* @0x218850 cmp r3, #0 */
/* @0x218854 bne 0x2188a8 <_Z17Audio_SetTrackPosif+0xfc> */
/* @0x218858 ldrb r3, [r0, #0x25] */
/* @0x21885c cmp r3, #0 */
/* @0x218860 bne 0x2188a8 <_Z17Audio_SetTrackPosif+0xfc> */
/* @0x218864 mov r0, r4 */
/* @0x218868 bl 0x2164bc <_Z20Audio_NoiseIsPlayingP6CNoise> */
/* @0x21886c cmp r0, #0 */
/* @0x218870 beq 0x218830 <_Z17Audio_SetTrackPosif+0x84> */
/* @0x218874 ldr r3, [pc, #0x78] */
/* @0x218878 movw r1, #0x1024 */
/* @0x21887c ldr r0, [r4, #0x10] */
/* @0x218880 ldr r3, [pc, r3] */
/* @0x218884 vmov r2, s16 */
/* @0x218888 ldr r3, [r3] */
/* @0x21888c ldr r0, [r3, r0, lsl #2] */
/* @0x218890 bl 0xb6a78 <alSourcef@plt> */
/* @0x218894 vpop {d8} */
/* @0x218898 ldr r0, [pc, #0x58] */
/* @0x21889c add r0, pc, r0 */
/* @0x2188a0 pop {r3, r4, r5, lr} */
/* @0x2188a4 b 0x215fd0 <_Z7checkALPKc> */
/* @0x2188a8 vmov r2, s16 */
/* @0x2188ac vpop {d8} */
/* @0x2188b0 ldr r0, [pc, #0x44] */
/* @0x2188b4 ldr r1, [r4, #0x10] */
/* @0x2188b8 add r0, pc, r0 */
/* @0x2188bc pop {r3, r4, r5, lr} */
/* @0x2188c0 b 0x226434 <_ZN9COggAudio10Seek_SoundEif> */
/* @0x2188c4 ldr r3, [pc, #0x34] */
/* @0x2188c8 ldr r1, [pc, #0x34] */
/* @0x2188cc ldr r3, [pc, r3] */
/* @0x2188d0 add r1, pc, r1 */
/* @0x2188d4 ldr r0, [r3] */
/* @0x2188d8 ldr r3, [r0] */
/* @0x2188dc ldr r3, [r3, #0xc] */
/* @0x2188e0 blx r3 */
/* @0x2188e4 vpop {d8} */
/* @0x2188e8 pop {r3, r4, r5, pc} */
/* @0x2188ec andeq r0, r0, r0 */
/* @0x2188f0 andseq r8, sp, r12, lsl r12 */
/* @0x2188f4 andseq r8, sp, r12, asr #22 */
/* @0x2188f8 andseq r11, r3, r12, lsl r4 */
/* @0x2188fc ldrsbeq r12, [r3], #-156 */
/* @0x218900 andseq r4, sp, r8, asr #28 */
/* @0x218904 andseq r11, r3, r4, lsl #8 */

/* ── FUNC 0x218908 · Audio_GetTrackPos(int) · size=472 · insn=118 */
/* @0x218908 ldr r3, [pc, #0x1bc] */
/* @0x21890c push {r4, r5, r6, r7, lr} */
/* @0x218910 ldr r3, [pc, r3] */
/* @0x218914 sub sp, sp, #12 */
/* @0x218918 ldr r3, [r3] */
/* @0x21891c cmp r3, r0 */
/* @0x218920 ble 0x21895c <_Z17Audio_GetTrackPosi+0x54> */
/* @0x218924 sub r1, r0, #199680 */
/* @0x218928 movw r3, #0x869f */
/* @0x21892c sub r1, r1, #320 */
/* @0x218930 movt r3, #0x1 */
/* @0x218934 cmp r1, r3 */
/* @0x218938 bls 0x218a20 <_Z17Audio_GetTrackPosi+0x118> */
/* @0x21893c cmp r0, #0 */
/* @0x218940 blt 0x218a14 <_Z17Audio_GetTrackPosi+0x10c> */
/* @0x218944 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x218948 cmp r0, #0 */
/* @0x21894c beq 0x218a14 <_Z17Audio_GetTrackPosi+0x10c> */
/* @0x218950 ldr r0, [r0, #0x48] */
/* @0x218954 add sp, sp, #12 */
/* @0x218958 pop {r4, r5, r6, r7, pc} */
/* @0x21895c bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x218960 mov r4, r0 */
/* @0x218964 cmp r4, #0 */
/* @0x218968 mov r3, #0 */
/* @0x21896c str r3, [sp] */
/* @0x218970 beq 0x218a14 <_Z17Audio_GetTrackPosi+0x10c> */
/* @0x218974 ldr r0, [r4, #0x18] */
/* @0x218978 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21897c subs r5, r0, #0 */
/* @0x218980 beq 0x218a14 <_Z17Audio_GetTrackPosi+0x10c> */
/* @0x218984 ldr r3, [pc, #0x144] */
/* @0x218988 ldrb r1, [r5, #0x24] */
/* @0x21898c ldr r3, [pc, r3] */
/* @0x218990 ldr r2, [r4, #0x10] */
/* @0x218994 cmp r1, #0 */
/* @0x218998 ldr r3, [r3] */
/* @0x21899c ldr r6, [r3, r2, lsl #2] */
/* @0x2189a0 bne 0x2189b0 <_Z17Audio_GetTrackPosi+0xa8> */
/* @0x2189a4 ldrb r3, [r5, #0x25] */
/* @0x2189a8 cmp r3, #0 */
/* @0x2189ac beq 0x218a9c <_Z17Audio_GetTrackPosi+0x194> */
/* @0x2189b0 ldrb r3, [r4, #0xd] */
/* @0x2189b4 cmp r3, #0 */
/* @0x2189b8 bne 0x218a14 <_Z17Audio_GetTrackPosi+0x10c> */
/* @0x2189bc ldr r3, [r5, #0x38] */
/* @0x2189c0 cmp r3, #0 */
/* @0x2189c4 ble 0x218ab8 <_Z17Audio_GetTrackPosi+0x1b0> */
/* @0x2189c8 add r2, sp, #8 */
/* @0x2189cc mov r3, #0 */
/* @0x2189d0 movw r1, #0x1025 */
/* @0x2189d4 mov r0, r6 */
/* @0x2189d8 str r3, [r2, #-0x4]! */
/* @0x2189dc bl 0xb6a9c <alGetSourcei@plt> */
/* @0x2189e0 ldr r0, [pc, #0xec] */
/* @0x2189e4 add r0, pc, r0 */
/* @0x2189e8 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x2189ec ldr r0, [pc, #0xe4] */
/* @0x2189f0 ldr r1, [r4, #0x10] */
/* @0x2189f4 add r0, pc, r0 */
/* @0x2189f8 ldr r2, [r4, #0x30] */
/* @0x2189fc bl 0x226118 <_ZN9COggAudio13GetOggChannelEii> */
/* @0x218a00 subs r7, r0, #0 */
/* @0x218a04 beq 0x218a14 <_Z17Audio_GetTrackPosi+0x10c> */
/* @0x218a08 ldr r6, [r5, #0x38] */
/* @0x218a0c cmp r6, #0 */
/* @0x218a10 bgt 0x218a2c <_Z17Audio_GetTrackPosi+0x124> */
/* @0x218a14 mov r0, #0 */
/* @0x218a18 add sp, sp, #12 */
/* @0x218a1c pop {r4, r5, r6, r7, pc} */
/* @0x218a20 bl 0x216560 <_Z31Audio_GetNoiseFromQueuedSoundIDi> */
/* @0x218a24 mov r4, r0 */
/* @0x218a28 b 0x218964 <_Z17Audio_GetTrackPosi+0x5c> */
/* @0x218a2c ldr r1, [r5, #0x3c] */
/* @0x218a30 mov r0, #16384 */
/* @0x218a34 lsl r1, r1, #1 */
/* @0x218a38 bl 0x318d10 <__divsi3> */
/* @0x218a3c ldr r2, [r7, #0x2e0] */
/* @0x218a40 ldr r3, [sp, #0x4] */
/* @0x218a44 vmov s11, r6 */
/* @0x218a48 vldr s13, [r7, #744] */
/* @0x218a4c vldr s14, [r5, #52] */
/* @0x218a50 vcvt.f32.s32 s12, s11 */
/* @0x218a54 mla r0, r2, r0, r3 */
/* @0x218a58 vmov s11, r0 */
/* @0x218a5c vcvt.f32.s32 s15, s11 */
/* @0x218a60 vdiv.f32 s15, s15, s12 */
/* @0x218a64 vadd.f32 s15, s15, s13 */
/* @0x218a68 vcmpe.f32 s15, s14 */
/* @0x218a6c vstr s15, [sp] */
/* @0x218a70 vmrs APSR_nzcv, fpscr */
/* @0x218a74 vmovle r0, s15 */
/* @0x218a78 ble 0x218a18 <_Z17Audio_GetTrackPosi+0x110> */
/* @0x218a7c ldrb r3, [r4, #0x4] */
/* @0x218a80 cmp r3, #0 */
/* @0x218a84 vmoveq r0, s14 */
/* @0x218a88 beq 0x218a18 <_Z17Audio_GetTrackPosi+0x110> */
/* @0x218a8c vmov r0, s15 */
/* @0x218a90 vmov r1, s14 */
/* @0x218a94 bl 0xb6790 <fmodf@plt> */
/* @0x218a98 b 0x218a18 <_Z17Audio_GetTrackPosi+0x110> */
/* @0x218a9c mov r0, r6 */
/* @0x218aa0 movw r1, #0x1024 */
/* @0x218aa4 mov r2, sp */
/* @0x218aa8 bl 0xb6acc <alGetSourcef@plt> */
/* @0x218aac ldr r0, [sp] */
/* @0x218ab0 add sp, sp, #12 */
/* @0x218ab4 pop {r4, r5, r6, r7, pc} */
/* @0x218ab8 ldr r0, [pc, #0x1c] */
/* @0x218abc mov r1, r5 */
/* @0x218ac0 add r0, pc, r0 */
/* @0x218ac4 bl 0x22688c <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound> */
/* @0x218ac8 b 0x2189c8 <_Z17Audio_GetTrackPosi+0xc0> */
/* @0x218acc ldrsbeq r8, [sp], -r4 */
/* @0x218ad0 andseq r8, sp, r0, asr #20 */
/* @0x218ad4 andseq r11, r3, r8, lsr r3 */
/* @0x218ad8 subseq r12, r3, r0, lsr #17 */
/* @0x218adc ldrsbeq r12, [r3], #-116 */

/* ── FUNC 0x218ae0 · Audio_AllGroupSoundsStopped(int) · size=164 · insn=41 */
/* @0x218ae0 ldr r3, [pc, #0x90] */
/* @0x218ae4 push {r4, r5, r6, r7, r8, lr} */
/* @0x218ae8 add r3, pc, r3 */
/* @0x218aec mov r7, r0 */
/* @0x218af0 ldr r5, [r3, #0x38] */
/* @0x218af4 cmp r5, #0 */
/* @0x218af8 ble 0x218b70 <_Z27Audio_AllGroupSoundsStoppedi+0x90> */
/* @0x218afc ldr r8, [pc, #0x78] */
/* @0x218b00 mov r3, r5 */
/* @0x218b04 ldr r6, [pc, #0x74] */
/* @0x218b08 mov r4, #0 */
/* @0x218b0c add r8, pc, r8 */
/* @0x218b10 add r6, pc, r6 */
/* @0x218b14 b 0x218b28 <_Z27Audio_AllGroupSoundsStoppedi+0x48> */
/* @0x218b18 add r4, r4, #1 */
/* @0x218b1c cmp r4, r5 */
/* @0x218b20 beq 0x218b70 <_Z27Audio_AllGroupSoundsStoppedi+0x90> */
/* @0x218b24 ldr r3, [r6, #0x38] */
/* @0x218b28 cmp r4, r3 */
/* @0x218b2c bge 0x218b18 <_Z27Audio_AllGroupSoundsStoppedi+0x38> */
/* @0x218b30 ldr r3, [r8, #0x3c] */
/* @0x218b34 ldr r3, [r3, r4, lsl #2] */
/* @0x218b38 cmp r3, #0 */
/* @0x218b3c beq 0x218b18 <_Z27Audio_AllGroupSoundsStoppedi+0x38> */
/* @0x218b40 ldrb r2, [r3, #0x5] */
/* @0x218b44 cmp r2, #0 */
/* @0x218b48 beq 0x218b18 <_Z27Audio_AllGroupSoundsStoppedi+0x38> */
/* @0x218b4c ldr r0, [r3, #0x18] */
/* @0x218b50 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x218b54 cmp r0, #0 */
/* @0x218b58 beq 0x218b18 <_Z27Audio_AllGroupSoundsStoppedi+0x38> */
/* @0x218b5c ldr r3, [r0, #0x4c] */
/* @0x218b60 cmp r3, r7 */
/* @0x218b64 bne 0x218b18 <_Z27Audio_AllGroupSoundsStoppedi+0x38> */
/* @0x218b68 mov r0, #0 */
/* @0x218b6c pop {r4, r5, r6, r7, r8, pc} */
/* @0x218b70 mov r0, #1 */
/* @0x218b74 pop {r4, r5, r6, r7, r8, pc} */
/* @0x218b78 subseq r12, r3, r12, lsr #15 */
/* @0x218b7c subseq r12, r3, r8, lsl #15 */
/* @0x218b80 subseq r12, r3, r4, lsl #15 */

/* ── FUNC 0x218b84 · Audio_SetGainGroup(int, float, int) · size=120 · insn=30 */
/* @0x218b84 ldr r3, [pc, #0x6c] */
/* @0x218b88 push {r4, r5, r6, r7, r8, lr} */
/* @0x218b8c add r3, pc, r3 */
/* @0x218b90 mov r6, r0 */
/* @0x218b94 mov r7, r1 */
/* @0x218b98 ldr r5, [r3, #0x20] */
/* @0x218b9c mov r8, r2 */
/* @0x218ba0 cmp r5, #0 */
/* @0x218ba4 pople {r4, r5, r6, r7, r8, pc} */
/* @0x218ba8 mov r4, #0 */
/* @0x218bac b 0x218bbc <_Z18Audio_SetGainGroupifi+0x38> */
/* @0x218bb0 add r4, r4, #1 */
/* @0x218bb4 cmp r4, r5 */
/* @0x218bb8 beq 0x218bf4 <_Z18Audio_SetGainGroupifi+0x70> */
/* @0x218bbc mov r0, r4 */
/* @0x218bc0 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x218bc4 cmp r0, #0 */
/* @0x218bc8 beq 0x218bb0 <_Z18Audio_SetGainGroupifi+0x2c> */
/* @0x218bcc ldr r3, [r0, #0x4c] */
/* @0x218bd0 cmp r3, r6 */
/* @0x218bd4 bne 0x218bb0 <_Z18Audio_SetGainGroupifi+0x2c> */
/* @0x218bd8 mov r0, r4 */
/* @0x218bdc mov r1, r7 */
/* @0x218be0 mov r2, r8 */
/* @0x218be4 add r4, r4, #1 */
/* @0x218be8 bl 0x2178f0 <_Z15Audio_SoundGainifi> */
/* @0x218bec cmp r4, r5 */
/* @0x218bf0 bne 0x218bbc <_Z18Audio_SetGainGroupifi+0x38> */
/* @0x218bf4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x218bf8 subseq r12, r3, r8, lsl #14 */

/* ── FUNC 0x218bfc · Audio_PauseMusic() · size=76 · insn=19 */
/* @0x218bfc ldr r3, [pc, #0x38] */
/* @0x218c00 ldr r3, [pc, r3] */
/* @0x218c04 ldrb r3, [r3] */
/* @0x218c08 cmp r3, #0 */
/* @0x218c0c bxne lr */
/* @0x218c10 ldr r3, [pc, #0x28] */
/* @0x218c14 ldr r3, [pc, r3] */
/* @0x218c18 ldrb r3, [r3] */
/* @0x218c1c cmp r3, #0 */
/* @0x218c20 bxne lr */
/* @0x218c24 ldr r3, [pc, #0x18] */
/* @0x218c28 ldr r3, [pc, r3] */
/* @0x218c2c ldr r0, [r3] */
/* @0x218c30 cmp r0, #0 */
/* @0x218c34 bxeq lr */
/* @0x218c38 b 0x2208e8 <_ZN13SoundHardware10PauseMusicEv> */
/* @0x218c3c andseq r6, sp, r12, asr #8 */
/* @0x218c40 andseq r6, sp, r12, lsl r1 */
/* @0x218c44 ldrheq r8, [sp], -r8 */

/* ── FUNC 0x218c48 · Audio_ResumeMusic() · size=76 · insn=19 */
/* @0x218c48 ldr r3, [pc, #0x38] */
/* @0x218c4c ldr r3, [pc, r3] */
/* @0x218c50 ldrb r3, [r3] */
/* @0x218c54 cmp r3, #0 */
/* @0x218c58 bxne lr */
/* @0x218c5c ldr r3, [pc, #0x28] */
/* @0x218c60 ldr r3, [pc, r3] */
/* @0x218c64 ldrb r3, [r3] */
/* @0x218c68 cmp r3, #0 */
/* @0x218c6c bxne lr */
/* @0x218c70 ldr r3, [pc, #0x18] */
/* @0x218c74 ldr r3, [pc, r3] */
/* @0x218c78 ldr r0, [r3] */
/* @0x218c7c cmp r0, #0 */
/* @0x218c80 bxeq lr */
/* @0x218c84 b 0x22091c <_ZN13SoundHardware11ResumeMusicEv> */
/* @0x218c88 andseq r6, sp, r0, lsl #8 */
/* @0x218c8c ldrsbeq r6, [sp], -r0 */
/* @0x218c90 andseq r8, sp, r12, ror #14 */

/* ── FUNC 0x218c94 · AudioGroup_Load(unsigned char*, unsigned int, unsigned char*) · size=208 · insn=52 */
/* @0x218c94 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x218c98 mov r6, r0 */
/* @0x218c9c ldr r9, [pc, #0xac] */
/* @0x218ca0 ldr r3, [pc, #0xac] */
/* @0x218ca4 add r9, pc, r9 */
/* @0x218ca8 ldr r1, [pc, #0xa8] */
/* @0x218cac ldr r3, [r9, r3] */
/* @0x218cb0 add r1, pc, r1 */
/* @0x218cb4 ldr r0, [r3] */
/* @0x218cb8 ldr r2, [r0] */
/* @0x218cbc ldr r3, [r2, #0xc] */
/* @0x218cc0 blx r3 */
/* @0x218cc4 ldr r7, [r6] */
/* @0x218cc8 cmp r7, #0 */
/* @0x218ccc bne 0x218cd8 <_Z15AudioGroup_LoadPhjS_+0x44> */
/* @0x218cd0 mov r0, #1 */
/* @0x218cd4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x218cd8 ldr r3, [pc, #0x7c] */
/* @0x218cdc mov r1, r7 */
/* @0x218ce0 mov r4, #0 */
/* @0x218ce4 ldr r8, [r9, r3] */
/* @0x218ce8 mov r0, r8 */
/* @0x218cec bl 0x21de4c <_ZN14CAudioGroupMan12CreateGroupsEi> */
/* @0x218cf0 ldr r3, [r6, #0x4]! */
/* @0x218cf4 mov r0, r8 */
/* @0x218cf8 ldr r1, [pc, #0x60] */
/* @0x218cfc cmp r3, #0 */
/* @0x218d00 mov r2, r3 */
/* @0x218d04 ldrne r2, [r9, r1] */
/* @0x218d08 ldr r1, [pc, #0x50] */
/* @0x218d0c ldrne r2, [r2] */
/* @0x218d10 addne r2, r2, r3 */
/* @0x218d14 ldr r3, [r2] */
/* @0x218d18 cmp r3, #0 */
/* @0x218d1c mov r5, r3 */
/* @0x218d20 ldrne r2, [r9, r1] */
/* @0x218d24 mov r1, r4 */
/* @0x218d28 add r4, r4, #1 */
/* @0x218d2c ldrne r5, [r2] */
/* @0x218d30 addne r5, r5, r3 */
/* @0x218d34 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi> */
/* @0x218d38 mov r1, r5 */
/* @0x218d3c bl 0x21dbf4 <_ZN11CAudioGroup7SetNameEPKc> */
/* @0x218d40 cmp r4, r7 */
/* @0x218d44 bne 0x218cf0 <_Z15AudioGroup_LoadPhjS_+0x5c> */
/* @0x218d48 mov r0, #1 */
/* @0x218d4c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x218d50 andseq r8, sp, r12, lsr #31 */
/* @0x218d54 .word 0xffffdecc */
/* @0x218d58 andseq r11, r3, r0, lsl #1 */
/* @0x218d5c .word 0xffffd400 */
/* @0x218d60 .word 0xffffbcf4 */

/* ── FUNC 0x218d64 · cAudio_Sound::LoadFromChunk(YYSound*, unsigned char*) · size=320 · insn=80 */
/* @0x218d64 push {r3, r4, r5, r6, r7, lr} */
/* @0x218d68 mov r4, r0 */
/* @0x218d6c ldr r0, [r1, #0xc] */
/* @0x218d70 mov r3, #0 */
/* @0x218d74 mov r5, r1 */
/* @0x218d78 str r3, [r4] */
/* @0x218d7c cmp r0, r3 */
/* @0x218d80 ldrne r3, [pc, #0x118] */
/* @0x218d84 ldrne r3, [pc, r3] */
/* @0x218d88 ldrne r3, [r3] */
/* @0x218d8c addne r0, r3, r0 */
/* @0x218d90 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x218d94 ldr r12, [r5, #0x4] */
/* @0x218d98 ldr r3, [r5, #0x14] */
/* @0x218d9c mov r1, #0 */
/* @0x218da0 ldr r6, [r5, #0x20] */
/* @0x218da4 cmp r12, #99 */
/* @0x218da8 ldr r2, [r5, #0x1c] */
/* @0x218dac mov r7, #1065353216 */
/* @0x218db0 str r3, [r4, #0x4] */
/* @0x218db4 mov r5, #1 */
/* @0x218db8 mov r3, #0 */
/* @0x218dbc str r6, [r4, #0x14] */
/* @0x218dc0 str r3, [r4, #0x1c] */
/* @0x218dc4 mov r6, #0 */
/* @0x218dc8 str r2, [r4, #0x4c] */
/* @0x218dcc movt r6, #0xbf80 */
/* @0x218dd0 str r3, [r4, #0x48] */
/* @0x218dd4 mov r2, #0 */
/* @0x218dd8 mov r3, #0 */
/* @0x218ddc str r1, [r4, #0x20] */
/* @0x218de0 str r1, [r4, #0xc] */
/* @0x218de4 str r1, [r4, #0x18] */
/* @0x218de8 str r7, [r4, #0x8] */
/* @0x218dec str r1, [r4, #0x38] */
/* @0x218df0 strb r1, [r4, #0x26] */
/* @0x218df4 strd r2, r3, [r4, #64] */
/* @0x218df8 str r5, [r4, #0x3c] */
/* @0x218dfc str r6, [r4, #0x34] */
/* @0x218e00 str r0, [r4] */
/* @0x218e04 ble 0x218e4c <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xe8> */
/* @0x218e08 sub r12, r12, #100 */
/* @0x218e0c cmp r12, #3 */
/* @0x218e10 addls pc, pc, r12, lsl #2 */
/* @0x218e14 b 0x218e34 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xd0> */
/* @0x218e18 b 0x218e28 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xc4> */
/* @0x218e1c b 0x218e7c <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0x118> */
/* @0x218e20 b 0x218e8c <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0x128> */
/* @0x218e24 b 0x218e64 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0x100> */
/* @0x218e28 mov r3, #1 */
/* @0x218e2c strb r3, [r4, #0x25] */
/* @0x218e30 strb r3, [r4, #0x24] */
/* @0x218e34 mov r3, #0 */
/* @0x218e38 mov r0, #1 */
/* @0x218e3c str r3, [r4, #0x28] */
/* @0x218e40 str r3, [r4, #0x2c] */
/* @0x218e44 str r3, [r4, #0x30] */
/* @0x218e48 pop {r3, r4, r5, r6, r7, pc} */
/* @0x218e4c cmp r12, #0 */
/* @0x218e50 movle r12, #0 */
/* @0x218e54 movgt r12, #1 */
/* @0x218e58 strb r12, [r4, #0x25] */
/* @0x218e5c strb r12, [r4, #0x24] */
/* @0x218e60 b 0x218e34 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xd0> */
/* @0x218e64 mov r3, #0 */
/* @0x218e68 mov r2, #1 */
/* @0x218e6c strb r3, [r4, #0x24] */
/* @0x218e70 strb r3, [r4, #0x25] */
/* @0x218e74 strb r2, [r4, #0x26] */
/* @0x218e78 b 0x218e34 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xd0> */
/* @0x218e7c mov r3, #0 */
/* @0x218e80 strb r3, [r4, #0x25] */
/* @0x218e84 strb r3, [r4, #0x24] */
/* @0x218e88 b 0x218e34 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xd0> */
/* @0x218e8c mov r2, #0 */
/* @0x218e90 mov r3, #1 */
/* @0x218e94 strb r2, [r4, #0x24] */
/* @0x218e98 strb r3, [r4, #0x25] */
/* @0x218e9c b 0x218e34 <_ZN12cAudio_Sound13LoadFromChunkEP7YYSoundPh+0xd0> */
/* @0x218ea0 andseq r4, sp, r0, asr #23 */
