/* libyoyo.so 覆盖卡组 0068
 * 函数 0x135cf4..0x137a3c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x135cf4 · F_AudioSoundGetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x135cf4 ldr r3, [pc, #0x40] */
/* @0x135cf8 push {r4, lr} */
/* @0x135cfc ldr r3, [pc, r3] */
/* @0x135d00 mov r4, r0 */
/* @0x135d04 ldrb r1, [r3] */
/* @0x135d08 cmp r1, #0 */
/* @0x135d0c popne {r4, pc} */
/* @0x135d10 str r1, [r0, #0xc] */
/* @0x135d14 ldr r0, [sp, #0x8] */
/* @0x135d18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135d1c bl 0x2183dc <_Z26Audio_SoundGetListenerMaski> */
/* @0x135d20 vmov s15, r0 */
/* @0x135d24 vcvt.f64.u32 d7, s15 */
/* @0x135d28 vmov r0, r1, d7 */
/* @0x135d2c vmov r2, s14 */
/* @0x135d30 mov r3, r1 */
/* @0x135d34 stm r4, {r2, r3} */
/* @0x135d38 pop {r4, pc} */
/* @0x135d3c eoreq r9, r11, r0, asr r3 */

/* ── FUNC 0x135d40 · F_AudioSoundSetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x135d40 push {r3, r4, r5, lr} */
/* @0x135d44 ldr r3, [pc, #0x38] */
/* @0x135d48 ldr r4, [sp, #0x10] */
/* @0x135d4c ldr r3, [pc, r3] */
/* @0x135d50 ldrb r1, [r3] */
/* @0x135d54 cmp r1, #0 */
/* @0x135d58 popne {r3, r4, r5, pc} */
/* @0x135d5c mov r0, r4 */
/* @0x135d60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135d64 mov r1, #1 */
/* @0x135d68 mov r5, r0 */
/* @0x135d6c mov r0, r4 */
/* @0x135d70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135d74 mov r1, r0 */
/* @0x135d78 mov r0, r5 */
/* @0x135d7c pop {r3, r4, r5, lr} */
/* @0x135d80 b 0x218444 <_Z26Audio_SoundSetListenerMaskij> */
/* @0x135d84 eoreq r9, r11, r0, lsl #6 */

/* ── FUNC 0x135d88 · F_AudioEmitterGetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x135d88 ldr r3, [pc, #0x40] */
/* @0x135d8c push {r4, lr} */
/* @0x135d90 ldr r3, [pc, r3] */
/* @0x135d94 mov r4, r0 */
/* @0x135d98 ldrb r1, [r3] */
/* @0x135d9c cmp r1, #0 */
/* @0x135da0 popne {r4, pc} */
/* @0x135da4 str r1, [r0, #0xc] */
/* @0x135da8 ldr r0, [sp, #0x8] */
/* @0x135dac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135db0 bl 0x2184b8 <_Z28Audio_EmitterGetListenerMaski> */
/* @0x135db4 vmov s15, r0 */
/* @0x135db8 vcvt.f64.u32 d7, s15 */
/* @0x135dbc vmov r0, r1, d7 */
/* @0x135dc0 vmov r2, s14 */
/* @0x135dc4 mov r3, r1 */
/* @0x135dc8 stm r4, {r2, r3} */
/* @0x135dcc pop {r4, pc} */
/* @0x135dd0 .word 0x002b92bc */

/* ── FUNC 0x135dd4 · F_AudioEmitterSetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x135dd4 push {r3, r4, r5, lr} */
/* @0x135dd8 ldr r3, [pc, #0x38] */
/* @0x135ddc ldr r4, [sp, #0x10] */
/* @0x135de0 ldr r3, [pc, r3] */
/* @0x135de4 ldrb r1, [r3] */
/* @0x135de8 cmp r1, #0 */
/* @0x135dec popne {r3, r4, r5, pc} */
/* @0x135df0 mov r0, r4 */
/* @0x135df4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135df8 mov r1, #1 */
/* @0x135dfc mov r5, r0 */
/* @0x135e00 mov r0, r4 */
/* @0x135e04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135e08 mov r1, r0 */
/* @0x135e0c mov r0, r5 */
/* @0x135e10 pop {r3, r4, r5, lr} */
/* @0x135e14 b 0x218520 <_Z28Audio_EmitterSetListenerMaskij> */
/* @0x135e18 eoreq r9, r11, r12, ror #4 */

/* ── FUNC 0x135e1c · F_AudioGetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x135e1c ldr r3, [pc, #0x38] */
/* @0x135e20 push {r4, lr} */
/* @0x135e24 ldr r3, [pc, r3] */
/* @0x135e28 mov r4, r0 */
/* @0x135e2c ldrb r3, [r3] */
/* @0x135e30 cmp r3, #0 */
/* @0x135e34 popne {r4, pc} */
/* @0x135e38 str r3, [r0, #0xc] */
/* @0x135e3c bl 0x21857c <_Z21Audio_GetListenerMaskv> */
/* @0x135e40 vmov s15, r0 */
/* @0x135e44 vcvt.f64.u32 d7, s15 */
/* @0x135e48 vmov r0, r1, d7 */
/* @0x135e4c vmov r2, s14 */
/* @0x135e50 mov r3, r1 */
/* @0x135e54 stm r4, {r2, r3} */
/* @0x135e58 pop {r4, pc} */
/* @0x135e5c eoreq r9, r11, r8, lsr #4 */

/* ── FUNC 0x135e60 · F_AudioSetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x135e60 push {r3, lr} */
/* @0x135e64 ldr r3, [pc, #0x1c] */
/* @0x135e68 ldr r0, [sp, #0x8] */
/* @0x135e6c ldr r3, [pc, r3] */
/* @0x135e70 ldrb r1, [r3] */
/* @0x135e74 cmp r1, #0 */
/* @0x135e78 popne {r3, pc} */
/* @0x135e7c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135e80 pop {r3, lr} */
/* @0x135e84 b 0x218590 <_Z21Audio_SetListenerMaskj> */
/* @0x135e88 eoreq r9, r11, r0, ror #3 */

/* ── FUNC 0x135e8c · F_AudioGetListenerInfo(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x135e8c ldr r3, [pc, #0x40] */
/* @0x135e90 push {r4, lr} */
/* @0x135e94 ldr r3, [pc, r3] */
/* @0x135e98 mov r4, r0 */
/* @0x135e9c ldrb r1, [r3] */
/* @0x135ea0 cmp r1, #0 */
/* @0x135ea4 popne {r4, pc} */
/* @0x135ea8 str r1, [r0, #0xc] */
/* @0x135eac ldr r0, [sp, #0x8] */
/* @0x135eb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135eb4 bl 0x2185a4 <_Z21Audio_GetListenerInfoi> */
/* @0x135eb8 vmov s15, r0 */
/* @0x135ebc vcvt.f64.s32 d7, s15 */
/* @0x135ec0 vmov r0, r1, d7 */
/* @0x135ec4 vmov r2, s14 */
/* @0x135ec8 mov r3, r1 */
/* @0x135ecc stm r4, {r2, r3} */
/* @0x135ed0 pop {r4, pc} */
/* @0x135ed4 .word 0x002b91b8 */

/* ── FUNC 0x135ed8 · F_AudioGetListenerCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x135ed8 ldr r3, [pc, #0x38] */
/* @0x135edc push {r4, lr} */
/* @0x135ee0 ldr r3, [pc, r3] */
/* @0x135ee4 mov r4, r0 */
/* @0x135ee8 ldrb r3, [r3] */
/* @0x135eec cmp r3, #0 */
/* @0x135ef0 popne {r4, pc} */
/* @0x135ef4 str r3, [r0, #0xc] */
/* @0x135ef8 bl 0x218638 <_Z22Audio_GetListenerCountv> */
/* @0x135efc vmov s15, r0 */
/* @0x135f00 vcvt.f64.s32 d7, s15 */
/* @0x135f04 vmov r0, r1, d7 */
/* @0x135f08 vmov r2, s14 */
/* @0x135f0c mov r3, r1 */
/* @0x135f10 stm r4, {r2, r3} */
/* @0x135f14 pop {r4, pc} */
/* @0x135f18 eoreq r9, r11, r12, ror #2 */

/* ── FUNC 0x135f1c · F_AudioCreateSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x135f1c ldr r3, [pc, #0x4c] */
/* @0x135f20 push {r4, lr} */
/* @0x135f24 ldr r3, [pc, r3] */
/* @0x135f28 mov r4, r0 */
/* @0x135f2c ldrb r1, [r3] */
/* @0x135f30 cmp r1, #0 */
/* @0x135f34 popne {r4, pc} */
/* @0x135f38 str r1, [r0, #0xc] */
/* @0x135f3c ldr r0, [sp, #0x8] */
/* @0x135f40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135f44 cmp r0, #0 */
/* @0x135f48 movle r0, #0 */
/* @0x135f4c movgt r0, #1 */
/* @0x135f50 bl 0x21d3c4 <_Z21Audio_CreateSyncGroupb> */
/* @0x135f54 vmov s15, r0 */
/* @0x135f58 vcvt.f64.s32 d7, s15 */
/* @0x135f5c vmov r0, r1, d7 */
/* @0x135f60 vmov r2, s14 */
/* @0x135f64 mov r3, r1 */
/* @0x135f68 stm r4, {r2, r3} */
/* @0x135f6c pop {r4, pc} */
/* @0x135f70 eoreq r9, r11, r8, lsr #2 */

/* ── FUNC 0x135f74 · F_AudioDestroySyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x135f74 push {r3, lr} */
/* @0x135f78 ldr r3, [pc, #0x24] */
/* @0x135f7c ldr r2, [sp, #0x8] */
/* @0x135f80 ldr r3, [pc, r3] */
/* @0x135f84 ldrb r1, [r3] */
/* @0x135f88 cmp r1, #0 */
/* @0x135f8c popne {r3, pc} */
/* @0x135f90 str r1, [r0, #0xc] */
/* @0x135f94 mov r0, r2 */
/* @0x135f98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135f9c pop {r3, lr} */
/* @0x135fa0 b 0x21d3f8 <_Z22Audio_DestroySyncGroupi> */
/* @0x135fa4 eoreq r9, r11, r12, asr #1 */

/* ── FUNC 0x135fa8 · F_AudioPlayInSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x135fa8 push {r3, r4, r5, lr} */
/* @0x135fac mov r4, r0 */
/* @0x135fb0 ldr r3, [pc, #0x50] */
/* @0x135fb4 ldr r3, [pc, r3] */
/* @0x135fb8 ldrb r1, [r3] */
/* @0x135fbc cmp r1, #0 */
/* @0x135fc0 popne {r3, r4, r5, pc} */
/* @0x135fc4 str r1, [r0, #0xc] */
/* @0x135fc8 ldr r0, [sp, #0x10] */
/* @0x135fcc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135fd0 mov r1, #1 */
/* @0x135fd4 mov r5, r0 */
/* @0x135fd8 ldr r0, [sp, #0x10] */
/* @0x135fdc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135fe0 mov r1, r0 */
/* @0x135fe4 mov r0, r5 */
/* @0x135fe8 bl 0x21d434 <_Z21Audio_PlayInSyncGroupii> */
/* @0x135fec vmov s15, r0 */
/* @0x135ff0 vcvt.f64.s32 d7, s15 */
/* @0x135ff4 vmov r0, r1, d7 */
/* @0x135ff8 vmov r2, s14 */
/* @0x135ffc mov r3, r1 */
/* @0x136000 stm r4, {r2, r3} */
/* @0x136004 pop {r3, r4, r5, pc} */
/* @0x136008 mlaeq r11, r8, r0, r9 */

/* ── FUNC 0x13600c · F_AudioStartSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x13600c push {r3, lr} */
/* @0x136010 ldr r3, [pc, #0x24] */
/* @0x136014 ldr r2, [sp, #0x8] */
/* @0x136018 ldr r3, [pc, r3] */
/* @0x13601c ldrb r1, [r3] */
/* @0x136020 cmp r1, #0 */
/* @0x136024 popne {r3, pc} */
/* @0x136028 str r1, [r0, #0xc] */
/* @0x13602c mov r0, r2 */
/* @0x136030 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x136034 pop {r3, lr} */
/* @0x136038 b 0x21d40c <_Z20Audio_StartSyncGroupi> */
/* @0x13603c eoreq r9, r11, r4, lsr r0 */

/* ── FUNC 0x136040 · F_AudioStopSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x136040 push {r3, lr} */
/* @0x136044 ldr r3, [pc, #0x24] */
/* @0x136048 ldr r2, [sp, #0x8] */
/* @0x13604c ldr r3, [pc, r3] */
/* @0x136050 ldrb r1, [r3] */
/* @0x136054 cmp r1, #0 */
/* @0x136058 popne {r3, pc} */
/* @0x13605c str r1, [r0, #0xc] */
/* @0x136060 mov r0, r2 */
/* @0x136064 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x136068 pop {r3, lr} */
/* @0x13606c b 0x21d420 <_Z19Audio_StopSyncGroupi> */
/* @0x136070 eoreq r9, r11, r0 */

/* ── FUNC 0x136074 · F_AudioPauseSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x136074 push {r3, lr} */
/* @0x136078 ldr r3, [pc, #0x24] */
/* @0x13607c ldr r2, [sp, #0x8] */
/* @0x136080 ldr r3, [pc, r3] */
/* @0x136084 ldrb r1, [r3] */
/* @0x136088 cmp r1, #0 */
/* @0x13608c popne {r3, pc} */
/* @0x136090 str r1, [r0, #0xc] */
/* @0x136094 mov r0, r2 */
/* @0x136098 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13609c pop {r3, lr} */
/* @0x1360a0 b 0x21d604 <_Z20Audio_PauseSyncGroupi> */
/* @0x1360a4 eoreq r8, r11, r12, asr #31 */

/* ── FUNC 0x1360a8 · F_AudioResumeSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1360a8 push {r3, lr} */
/* @0x1360ac ldr r3, [pc, #0x24] */
/* @0x1360b0 ldr r2, [sp, #0x8] */
/* @0x1360b4 ldr r3, [pc, r3] */
/* @0x1360b8 ldrb r1, [r3] */
/* @0x1360bc cmp r1, #0 */
/* @0x1360c0 popne {r3, pc} */
/* @0x1360c4 str r1, [r0, #0xc] */
/* @0x1360c8 mov r0, r2 */
/* @0x1360cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1360d0 pop {r3, lr} */
/* @0x1360d4 b 0x21d618 <_Z21Audio_ResumeSyncGroupi> */
/* @0x1360d8 mlaeq r11, r8, pc, r8 */

/* ── FUNC 0x1360dc · F_AudioSyncGroupGetTrackPos(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1360dc ldr r3, [pc, #0x40] */
/* @0x1360e0 push {r4, lr} */
/* @0x1360e4 ldr r3, [pc, r3] */
/* @0x1360e8 mov r4, r0 */
/* @0x1360ec ldrb r1, [r3] */
/* @0x1360f0 cmp r1, #0 */
/* @0x1360f4 popne {r4, pc} */
/* @0x1360f8 str r1, [r0, #0xc] */
/* @0x1360fc ldr r0, [sp, #0x8] */
/* @0x136100 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x136104 bl 0x21d62c <_Z26Audio_SyncGroupGetTrackPosi> */
/* @0x136108 vmov s15, r0 */
/* @0x13610c vcvt.f64.f32 d7, s15 */
/* @0x136110 vmov r0, r1, d7 */
/* @0x136114 vmov r2, s14 */
/* @0x136118 mov r3, r1 */
/* @0x13611c stm r4, {r2, r3} */
/* @0x136120 pop {r4, pc} */
/* @0x136124 eoreq r8, r11, r8, ror #30 */

/* ── FUNC 0x136128 · F_AudioSyncGroupDebug(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x136128 push {r3, lr} */
/* @0x13612c ldr r3, [pc, #0x24] */
/* @0x136130 ldr r2, [sp, #0x8] */
/* @0x136134 ldr r3, [pc, r3] */
/* @0x136138 ldrb r1, [r3] */
/* @0x13613c cmp r1, #0 */
/* @0x136140 popne {r3, pc} */
/* @0x136144 str r1, [r0, #0xc] */
/* @0x136148 mov r0, r2 */
/* @0x13614c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x136150 pop {r3, lr} */
/* @0x136154 b 0x21d68c <_Z20Audio_SyncGroupDebugi> */
/* @0x136158 eoreq r8, r11, r8, lsl pc */

/* ── FUNC 0x13615c · F_AudioSyncGroupIsPlaying(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x13615c ldr r3, [pc, #0x40] */
/* @0x136160 push {r4, lr} */
/* @0x136164 ldr r3, [pc, r3] */
/* @0x136168 mov r4, r0 */
/* @0x13616c ldrb r1, [r3] */
/* @0x136170 cmp r1, #0 */
/* @0x136174 popne {r4, pc} */
/* @0x136178 str r1, [r0, #0xc] */
/* @0x13617c ldr r0, [sp, #0x8] */
/* @0x136180 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x136184 bl 0x21d640 <_Z24Audio_SyncGroupIsPlayingi> */
/* @0x136188 vmov s15, r0 */
/* @0x13618c vcvt.f64.u32 d7, s15 */
/* @0x136190 vmov r0, r1, d7 */
/* @0x136194 vmov r2, s14 */
/* @0x136198 mov r3, r1 */
/* @0x13619c stm r4, {r2, r3} */
/* @0x1361a0 pop {r4, pc} */
/* @0x1361a4 eoreq r8, r11, r8, ror #29 */

/* ── FUNC 0x1361a8 · F_AudioDebug(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1361a8 push {r3, lr} */
/* @0x1361ac ldr r3, [pc, #0x30] */
/* @0x1361b0 ldr r2, [sp, #0x8] */
/* @0x1361b4 ldr r3, [pc, r3] */
/* @0x1361b8 ldrb r1, [r3] */
/* @0x1361bc cmp r1, #0 */
/* @0x1361c0 popne {r3, pc} */
/* @0x1361c4 str r1, [r0, #0xc] */
/* @0x1361c8 mov r0, r2 */
/* @0x1361cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1361d0 pop {r3, lr} */
/* @0x1361d4 cmp r0, #0 */
/* @0x1361d8 movle r0, #0 */
/* @0x1361dc movgt r0, #1 */
/* @0x1361e0 b 0x21d6bc <_Z11Audio_Debugb> */
/* @0x1361e4 mlaeq r11, r8, lr, r8 */

/* ── FUNC 0x1361e8 · F_Sound3DSetSoundVelocity(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x1361e8 ldr r3, [pc, #0xa4] */
/* @0x1361ec push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1361f0 ldr r3, [pc, r3] */
/* @0x1361f4 sub sp, sp, #20 */
/* @0x1361f8 ldrb r1, [r3] */
/* @0x1361fc ldr r8, [sp, #0x30] */
/* @0x136200 cmp r1, #0 */
/* @0x136204 beq 0x136210 <_Z25F_Sound3DSetSoundVelocityR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x136208 add sp, sp, #20 */
/* @0x13620c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x136210 mov r0, r8 */
/* @0x136214 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x136218 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x13621c subs r1, r0, #0 */
/* @0x136220 beq 0x136280 <_Z25F_Sound3DSetSoundVelocityR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x136224 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x136228 mov r1, #1 */
/* @0x13622c mov r9, r0 */
/* @0x136230 mov r0, r8 */
/* @0x136234 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x136238 mov r4, r0 */
/* @0x13623c mov r5, r1 */
/* @0x136240 mov r0, r8 */
/* @0x136244 mov r1, #2 */
/* @0x136248 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13624c mov r6, r0 */
/* @0x136250 mov r7, r1 */
/* @0x136254 mov r0, r8 */
/* @0x136258 mov r1, #3 */
/* @0x13625c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x136260 strd r6, r7, [sp] */
/* @0x136264 mov r2, r4 */
/* @0x136268 mov r3, r5 */
/* @0x13626c strd r0, r1, [sp, #8] */
/* @0x136270 mov r0, r9 */
/* @0x136274 bl 0x21f170 <_Z25SND_3D_Set_Sound_Velocityiddd> */
/* @0x136278 add sp, sp, #20 */
/* @0x13627c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x136280 ldr r0, [pc, #0x10] */
/* @0x136284 add r0, pc, r0 */
/* @0x136288 add sp, sp, #20 */
/* @0x13628c pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x136290 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x136294 eoreq r8, r11, r12, asr lr */
/* @0x136298 eoreq r9, r0, r8, lsl #4 */

/* ── FUNC 0x13629c · F_Sound3DSetSoundDistance(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x13629c ldr r3, [pc, #0x8c] */
/* @0x1362a0 push {r4, r5, r6, r7, lr} */
/* @0x1362a4 ldr r3, [pc, r3] */
/* @0x1362a8 sub sp, sp, #12 */
/* @0x1362ac ldrb r1, [r3] */
/* @0x1362b0 ldr r6, [sp, #0x20] */
/* @0x1362b4 cmp r1, #0 */
/* @0x1362b8 beq 0x1362c4 <_Z25F_Sound3DSetSoundDistanceR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x1362bc add sp, sp, #12 */
/* @0x1362c0 pop {r4, r5, r6, r7, pc} */
/* @0x1362c4 mov r0, r6 */
/* @0x1362c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1362cc bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x1362d0 subs r1, r0, #0 */
/* @0x1362d4 beq 0x13631c <_Z25F_Sound3DSetSoundDistanceR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1362d8 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x1362dc mov r1, #1 */
/* @0x1362e0 mov r7, r0 */
/* @0x1362e4 mov r0, r6 */
/* @0x1362e8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1362ec mov r4, r0 */
/* @0x1362f0 mov r5, r1 */
/* @0x1362f4 mov r0, r6 */
/* @0x1362f8 mov r1, #2 */
/* @0x1362fc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x136300 mov r2, r4 */
/* @0x136304 mov r3, r5 */
/* @0x136308 strd r0, r1, [sp] */
/* @0x13630c mov r0, r7 */
/* @0x136310 bl 0x21f174 <_Z25SND_3D_Set_Sound_Distanceidd> */
/* @0x136314 add sp, sp, #12 */
/* @0x136318 pop {r4, r5, r6, r7, pc} */
/* @0x13631c ldr r0, [pc, #0x10] */
/* @0x136320 add r0, pc, r0 */
/* @0x136324 add sp, sp, #12 */
/* @0x136328 pop {r4, r5, r6, r7, lr} */
/* @0x13632c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x136330 eoreq r8, r11, r8, lsr #27 */
/* @0x136334 eoreq r9, r0, r12, ror #2 */

/* ── FUNC 0x136338 · F_Sound3DSetSoundCone(RValue&, CInstance*, CInstance*, int, RValue*) · size=260 · insn=65 */
/* @0x136338 ldr r3, [pc, #0xf4] */
/* @0x13633c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x136340 ldr r3, [pc, r3] */
/* @0x136344 sub sp, sp, #44 */
/* @0x136348 ldrb r1, [r3] */
/* @0x13634c ldr r10, [sp, #0x50] */
/* @0x136350 cmp r1, #0 */
/* @0x136354 beq 0x136360 <_Z21F_Sound3DSetSoundConeR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x136358 add sp, sp, #44 */
/* @0x13635c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x136360 mov r0, r10 */
/* @0x136364 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x136368 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x13636c subs r1, r0, #0 */
/* @0x136370 beq 0x136420 <_Z21F_Sound3DSetSoundConeR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x136374 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x136378 mov r1, #1 */
/* @0x13637c mov r11, r0 */
/* @0x136380 mov r0, r10 */
/* @0x136384 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x136388 mov r4, r0 */
/* @0x13638c mov r5, r1 */
/* @0x136390 mov r0, r10 */
/* @0x136394 mov r1, #2 */
/* @0x136398 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13639c mov r8, r0 */
/* @0x1363a0 mov r9, r1 */
/* @0x1363a4 mov r0, r10 */
/* @0x1363a8 mov r1, #3 */
/* @0x1363ac bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1363b0 mov r6, r0 */
/* @0x1363b4 mov r7, r1 */
/* @0x1363b8 mov r0, r10 */
/* @0x1363bc mov r1, #4 */
/* @0x1363c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1363c4 mov r1, #5 */
/* @0x1363c8 mov r2, r0 */
/* @0x1363cc mov r0, r10 */
/* @0x1363d0 str r2, [sp, #0x20] */
/* @0x1363d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1363d8 mov r1, #6 */
/* @0x1363dc mov r3, r0 */
/* @0x1363e0 mov r0, r10 */
/* @0x1363e4 str r3, [sp, #0x24] */
/* @0x1363e8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1363ec ldr r2, [sp, #0x20] */
/* @0x1363f0 ldr r3, [sp, #0x24] */
/* @0x1363f4 strd r8, r9, [sp] */
/* @0x1363f8 str r2, [sp, #0x10] */
/* @0x1363fc mov r2, r4 */
/* @0x136400 str r3, [sp, #0x14] */
/* @0x136404 mov r3, r5 */
/* @0x136408 strd r6, r7, [sp, #8] */
/* @0x13640c strd r0, r1, [sp, #24] */
/* @0x136410 mov r0, r11 */
/* @0x136414 bl 0x21f178 <_Z21SND_3D_Set_Sound_Coneidddiid> */
/* @0x136418 add sp, sp, #44 */
/* @0x13641c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x136420 ldr r0, [pc, #0x10] */
/* @0x136424 add r0, pc, r0 */
/* @0x136428 add sp, sp, #44 */
/* @0x13642c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x136430 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x136434 eoreq r8, r11, r12, lsl #26 */
/* @0x136438 eoreq r9, r0, r8, rrx */

/* ── FUNC 0x13643c · F_AudioCreateStream(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x13643c ldr r3, [pc, #0x40] */
/* @0x136440 push {r4, lr} */
/* @0x136444 ldr r3, [pc, r3] */
/* @0x136448 mov r4, r0 */
/* @0x13644c ldrb r1, [r3] */
/* @0x136450 cmp r1, #0 */
/* @0x136454 popne {r4, pc} */
/* @0x136458 str r1, [r0, #0xc] */
/* @0x13645c ldr r0, [sp, #0x8] */
/* @0x136460 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x136464 bl 0x21d6dc <_Z18Audio_CreateStreamPKc> */
/* @0x136468 vmov s15, r0 */
/* @0x13646c vcvt.f64.s32 d7, s15 */
/* @0x136470 vmov r0, r1, d7 */
/* @0x136474 vmov r2, s14 */
/* @0x136478 mov r3, r1 */
/* @0x13647c stm r4, {r2, r3} */
/* @0x136480 pop {r4, pc} */
/* @0x136484 eoreq r8, r11, r8, lsl #24 */

/* ── FUNC 0x136488 · F_AudioDestroyStream(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x136488 ldr r3, [pc, #0x40] */
/* @0x13648c push {r4, lr} */
/* @0x136490 ldr r3, [pc, r3] */
/* @0x136494 mov r4, r0 */
/* @0x136498 ldrb r1, [r3] */
/* @0x13649c cmp r1, #0 */
/* @0x1364a0 popne {r4, pc} */
/* @0x1364a4 str r1, [r0, #0xc] */
/* @0x1364a8 ldr r0, [sp, #0x8] */
/* @0x1364ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1364b0 bl 0x21d9a8 <_Z19Audio_DestroyStreami> */
/* @0x1364b4 vmov s15, r0 */
/* @0x1364b8 vcvt.f64.s32 d7, s15 */
/* @0x1364bc vmov r0, r1, d7 */
/* @0x1364c0 vmov r2, s14 */
/* @0x1364c4 mov r3, r1 */
/* @0x1364c8 stm r4, {r2, r3} */
/* @0x1364cc pop {r4, pc} */
/* @0x1364d0 .word 0x002b8bbc */

/* ── FUNC 0x1364d4 · F_SoundIsPlaying(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x1364d4 push {r3, r4, r5, lr} */
/* @0x1364d8 mov r4, r0 */
/* @0x1364dc ldr r3, [pc, #0x70] */
/* @0x1364e0 ldr r3, [pc, r3] */
/* @0x1364e4 ldrb r3, [r3] */
/* @0x1364e8 cmp r3, #0 */
/* @0x1364ec popne {r3, r4, r5, pc} */
/* @0x1364f0 ldr r3, [pc, #0x60] */
/* @0x1364f4 ldr r3, [pc, r3] */
/* @0x1364f8 ldrb r1, [r3] */
/* @0x1364fc cmp r1, #0 */
/* @0x136500 popne {r3, r4, r5, pc} */
/* @0x136504 str r1, [r0, #0xc] */
/* @0x136508 ldr r0, [sp, #0x10] */
/* @0x13650c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x136510 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x136514 subs r3, r0, #0 */
/* @0x136518 streq r3, [r4] */
/* @0x13651c streq r3, [r4, #0x4] */
/* @0x136520 popeq {r3, r4, r5, pc} */
/* @0x136524 ldr r5, [r3, #0xc] */
/* @0x136528 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x13652c mov r1, r0 */
/* @0x136530 mov r0, r5 */
/* @0x136534 bl 0x21edc0 <_Z13SND_IsPlayingPKci> */
/* @0x136538 vmov s15, r0 */
/* @0x13653c vcvt.f64.u32 d7, s15 */
/* @0x136540 vmov r0, r1, d7 */
/* @0x136544 vmov r2, s14 */
/* @0x136548 mov r3, r1 */
/* @0x13654c stm r4, {r2, r3} */
/* @0x136550 pop {r3, r4, r5, pc} */
/* @0x136554 eoreq r8, r11, r0, asr r8 */
/* @0x136558 eoreq r8, r11, r8, asr r11 */

/* ── FUNC 0x13655c · F_SoundLoop(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x13655c ldr r3, [pc, #0x80] */
/* @0x136560 push {r4, r5, r6, lr} */
/* @0x136564 ldr r3, [pc, r3] */
/* @0x136568 ldr r0, [sp, #0x10] */
/* @0x13656c ldrb r3, [r3] */
/* @0x136570 cmp r3, #0 */
/* @0x136574 popne {r4, r5, r6, pc} */
/* @0x136578 ldr r3, [pc, #0x68] */
/* @0x13657c ldr r3, [pc, r3] */
/* @0x136580 ldrb r1, [r3] */
/* @0x136584 cmp r1, #0 */
/* @0x136588 popne {r4, r5, r6, pc} */
/* @0x13658c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x136590 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x136594 subs r4, r0, #0 */
/* @0x136598 beq 0x1365d0 <_Z11F_SoundLoopR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x13659c ldr r5, [r4, #0xc] */
/* @0x1365a0 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x1365a4 mov r2, #1 */
/* @0x1365a8 mov r1, r0 */
/* @0x1365ac mov r0, r5 */
/* @0x1365b0 bl 0x21eb7c <_Z8SND_PlayPKcib> */
/* @0x1365b4 mov r0, r4 */
/* @0x1365b8 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x1365bc ldrd r2, r3, [r4, #32] */
/* @0x1365c0 mov r1, #1 */
/* @0x1365c4 str r1, [sp, #0x10] */
/* @0x1365c8 pop {r4, r5, r6, lr} */
/* @0x1365cc b 0x21f07c <_Z14SND_Set_Volumeidi> */
/* @0x1365d0 ldr r0, [pc, #0x14] */
/* @0x1365d4 mov r1, r4 */
/* @0x1365d8 pop {r4, r5, r6, lr} */
/* @0x1365dc add r0, pc, r0 */
/* @0x1365e0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1365e4 eoreq r8, r11, r12, asr #15 */
/* @0x1365e8 .word 0x002b8ad0 */
/* @0x1365ec .word 0x00208eb0 */

/* ── FUNC 0x1365f0 · YYGML_sound_play(int) · size=160 · insn=40 */
/* @0x1365f0 ldr r3, [pc, #0x8c] */
/* @0x1365f4 push {r4, r5, r6, lr} */
/* @0x1365f8 ldr r3, [pc, r3] */
/* @0x1365fc sub sp, sp, #8 */
/* @0x136600 ldrb r3, [r3] */
/* @0x136604 cmp r3, #0 */
/* @0x136608 bne 0x136620 <_Z16YYGML_sound_playi+0x30> */
/* @0x13660c ldr r3, [pc, #0x74] */
/* @0x136610 ldr r3, [pc, r3] */
/* @0x136614 ldrb r4, [r3] */
/* @0x136618 cmp r4, #0 */
/* @0x13661c beq 0x136628 <_Z16YYGML_sound_playi+0x38> */
/* @0x136620 add sp, sp, #8 */
/* @0x136624 pop {r4, r5, r6, pc} */
/* @0x136628 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x13662c subs r5, r0, #0 */
/* @0x136630 beq 0x13666c <_Z16YYGML_sound_playi+0x7c> */
/* @0x136634 ldr r6, [r5, #0xc] */
/* @0x136638 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x13663c mov r2, r4 */
/* @0x136640 mov r1, r0 */
/* @0x136644 mov r0, r6 */
/* @0x136648 bl 0x21eb7c <_Z8SND_PlayPKcib> */
/* @0x13664c mov r0, r5 */
/* @0x136650 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x136654 ldrd r2, r3, [r5, #32] */
/* @0x136658 mov r1, #1 */
/* @0x13665c str r1, [sp] */
/* @0x136660 bl 0x21f07c <_Z14SND_Set_Volumeidi> */
/* @0x136664 add sp, sp, #8 */
/* @0x136668 pop {r4, r5, r6, pc} */
/* @0x13666c ldr r0, [pc, #0x18] */
/* @0x136670 mov r1, r5 */
/* @0x136674 add r0, pc, r0 */
/* @0x136678 add sp, sp, #8 */
/* @0x13667c pop {r4, r5, r6, lr} */
/* @0x136680 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x136684 eoreq r8, r11, r8, lsr r7 */
/* @0x136688 eoreq r8, r11, r12, lsr r10 */
/* @0x13668c eoreq r8, r0, r8, lsl lr */

/* ── FUNC 0x136690 · F_SoundPlay(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x136690 push {r3, lr} */
/* @0x136694 mov r1, #0 */
/* @0x136698 ldr r0, [sp, #0x8] */
/* @0x13669c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1366a0 pop {r3, lr} */
/* @0x1366a4 b 0x1365f0 <_Z16YYGML_sound_playi> */

/* ── FUNC 0x1366a8 · YYGML_sound_stop(int) · size=108 · insn=27 */
/* @0x1366a8 ldr r3, [pc, #0x58] */
/* @0x1366ac push {r4, lr} */
/* @0x1366b0 ldr r3, [pc, r3] */
/* @0x1366b4 ldrb r3, [r3] */
/* @0x1366b8 cmp r3, #0 */
/* @0x1366bc popne {r4, pc} */
/* @0x1366c0 ldr r3, [pc, #0x44] */
/* @0x1366c4 ldr r3, [pc, r3] */
/* @0x1366c8 ldrb r3, [r3] */
/* @0x1366cc cmp r3, #0 */
/* @0x1366d0 popne {r4, pc} */
/* @0x1366d4 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x1366d8 subs r1, r0, #0 */
/* @0x1366dc beq 0x1366f8 <_Z16YYGML_sound_stopi+0x50> */
/* @0x1366e0 ldr r4, [r1, #0xc] */
/* @0x1366e4 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x1366e8 mov r1, r0 */
/* @0x1366ec mov r0, r4 */
/* @0x1366f0 pop {r4, lr} */
/* @0x1366f4 b 0x21ecf4 <_Z8SND_StopPKci> */
/* @0x1366f8 ldr r0, [pc, #0x10] */
/* @0x1366fc pop {r4, lr} */
/* @0x136700 add r0, pc, r0 */
/* @0x136704 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x136708 eoreq r8, r11, r0, lsl #13 */
/* @0x13670c eoreq r8, r11, r8, lsl #19 */
/* @0x136710 eoreq r8, r0, r12, lsl #27 */

/* ── FUNC 0x136714 · F_SoundStop(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x136714 push {r3, lr} */
/* @0x136718 mov r1, #0 */
/* @0x13671c ldr r0, [sp, #0x8] */
/* @0x136720 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x136724 pop {r3, lr} */
/* @0x136728 b 0x1366a8 <_Z16YYGML_sound_stopi> */

/* ── FUNC 0x13672c · InitSoundFunctions() · size=4880 · insn=1220 */
/* @0x13672c push {r4, lr} */
/* @0x136730 mov r2, #1 */
/* @0x136734 ldr r4, [pc, #0xec4] */
/* @0x136738 mov r3, #0 */
/* @0x13673c ldr r1, [pc, #0xec0] */
/* @0x136740 add r4, pc, r4 */
/* @0x136744 ldr r0, [pc, #0xebc] */
/* @0x136748 ldr r1, [r4, r1] */
/* @0x13674c add r0, pc, r0 */
/* @0x136750 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136754 ldr r1, [pc, #0xeb0] */
/* @0x136758 ldr r0, [pc, #0xeb0] */
/* @0x13675c mov r2, #1 */
/* @0x136760 mov r3, #0 */
/* @0x136764 ldr r1, [r4, r1] */
/* @0x136768 add r0, pc, r0 */
/* @0x13676c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136770 ldr r1, [pc, #0xe9c] */
/* @0x136774 ldr r0, [pc, #0xe9c] */
/* @0x136778 mov r2, #1 */
/* @0x13677c mov r3, #0 */
/* @0x136780 ldr r1, [r4, r1] */
/* @0x136784 add r0, pc, r0 */
/* @0x136788 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13678c ldr r1, [pc, #0xe88] */
/* @0x136790 ldr r0, [pc, #0xe88] */
/* @0x136794 mov r2, #0 */
/* @0x136798 mov r3, r2 */
/* @0x13679c ldr r1, [r4, r1] */
/* @0x1367a0 add r0, pc, r0 */
/* @0x1367a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1367a8 ldr r1, [pc, #0xe74] */
/* @0x1367ac ldr r0, [pc, #0xe74] */
/* @0x1367b0 mov r2, #1 */
/* @0x1367b4 mov r3, #0 */
/* @0x1367b8 ldr r1, [r4, r1] */
/* @0x1367bc add r0, pc, r0 */
/* @0x1367c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1367c4 ldr r1, [pc, #0xe60] */
/* @0x1367c8 ldr r0, [pc, #0xe60] */
/* @0x1367cc mov r2, #2 */
/* @0x1367d0 mov r3, #0 */
/* @0x1367d4 ldr r1, [r4, r1] */
/* @0x1367d8 add r0, pc, r0 */
/* @0x1367dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1367e0 ldr r1, [pc, #0xe4c] */
/* @0x1367e4 ldr r0, [pc, #0xe4c] */
/* @0x1367e8 mov r2, #3 */
/* @0x1367ec mov r3, #0 */
/* @0x1367f0 ldr r1, [r4, r1] */
/* @0x1367f4 add r0, pc, r0 */
/* @0x1367f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1367fc ldr r1, [pc, #0xe38] */
/* @0x136800 ldr r0, [pc, #0xe38] */
/* @0x136804 mov r2, #2 */
/* @0x136808 mov r3, #0 */
/* @0x13680c ldr r1, [r4, r1] */
/* @0x136810 add r0, pc, r0 */
/* @0x136814 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136818 ldr r1, [pc, #0xe24] */
/* @0x13681c ldr r0, [pc, #0xe24] */
/* @0x136820 mov r2, #1 */
/* @0x136824 mov r3, #0 */
/* @0x136828 ldr r1, [r4, r1] */
/* @0x13682c add r0, pc, r0 */
/* @0x136830 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136834 ldr r1, [pc, #0xe10] */
/* @0x136838 ldr r0, [pc, #0xe10] */
/* @0x13683c mov r2, #1 */
/* @0x136840 mov r3, #0 */
/* @0x136844 ldr r1, [r4, r1] */
/* @0x136848 add r0, pc, r0 */
/* @0x13684c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136850 ldr r1, [pc, #0xdfc] */
/* @0x136854 ldr r0, [pc, #0xdfc] */
/* @0x136858 mov r2, #1 */
/* @0x13685c mov r3, #0 */
/* @0x136860 ldr r1, [r4, r1] */
/* @0x136864 add r0, pc, r0 */
/* @0x136868 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13686c ldr r1, [pc, #0xde8] */
/* @0x136870 ldr r0, [pc, #0xde8] */
/* @0x136874 mov r2, #2 */
/* @0x136878 mov r3, #1 */
/* @0x13687c ldr r1, [r4, r1] */
/* @0x136880 add r0, pc, r0 */
/* @0x136884 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136888 ldr r1, [pc, #0xdd4] */
/* @0x13688c ldr r0, [pc, #0xdd4] */
/* @0x136890 mov r2, #8 */
/* @0x136894 mov r3, #1 */
/* @0x136898 ldr r1, [r4, r1] */
/* @0x13689c add r0, pc, r0 */
/* @0x1368a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1368a4 ldr r1, [pc, #0xdc0] */
/* @0x1368a8 ldr r0, [pc, #0xdc0] */
/* @0x1368ac mov r2, #7 */
/* @0x1368b0 mov r3, #1 */
/* @0x1368b4 ldr r1, [r4, r1] */
/* @0x1368b8 add r0, pc, r0 */
/* @0x1368bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1368c0 ldr r1, [pc, #0xdac] */
/* @0x1368c4 ldr r0, [pc, #0xdac] */
/* @0x1368c8 mov r2, #6 */
/* @0x1368cc mov r3, #1 */
/* @0x1368d0 ldr r1, [r4, r1] */
/* @0x1368d4 add r0, pc, r0 */
/* @0x1368d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1368dc ldr r1, [pc, #0xd98] */
/* @0x1368e0 ldr r0, [pc, #0xd98] */
/* @0x1368e4 mov r2, #8 */
/* @0x1368e8 mov r3, #1 */
/* @0x1368ec ldr r1, [r4, r1] */
/* @0x1368f0 add r0, pc, r0 */
/* @0x1368f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1368f8 ldr r1, [pc, #0xd84] */
/* @0x1368fc ldr r0, [pc, #0xd84] */
/* @0x136900 mov r2, #3 */
/* @0x136904 mov r3, #1 */
/* @0x136908 ldr r1, [r4, r1] */
/* @0x13690c add r0, pc, r0 */
/* @0x136910 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136914 ldr r1, [pc, #0xd70] */
/* @0x136918 ldr r0, [pc, #0xd70] */
/* @0x13691c mov r2, #4 */
/* @0x136920 mov r3, #1 */
/* @0x136924 ldr r1, [r4, r1] */
/* @0x136928 add r0, pc, r0 */
/* @0x13692c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136930 ldr r1, [pc, #0xd5c] */
/* @0x136934 ldr r0, [pc, #0xd5c] */
/* @0x136938 mov r2, #5 */
/* @0x13693c mov r3, #1 */
/* @0x136940 ldr r1, [r4, r1] */
/* @0x136944 add r0, pc, r0 */
/* @0x136948 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13694c ldr r1, [pc, #0xd48] */
/* @0x136950 ldr r0, [pc, #0xd48] */
/* @0x136954 mov r2, #4 */
/* @0x136958 mov r3, #1 */
/* @0x13695c ldr r1, [r4, r1] */
/* @0x136960 add r0, pc, r0 */
/* @0x136964 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136968 ldr r1, [pc, #0xd34] */
/* @0x13696c ldr r0, [pc, #0xd34] */
/* @0x136970 mov r2, #4 */
/* @0x136974 mov r3, #1 */
/* @0x136978 ldr r1, [r4, r1] */
/* @0x13697c add r0, pc, r0 */
/* @0x136980 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136984 ldr r1, [pc, #0xd20] */
/* @0x136988 ldr r0, [pc, #0xd20] */
/* @0x13698c mov r2, #3 */
/* @0x136990 mov r3, #1 */
/* @0x136994 ldr r1, [r4, r1] */
/* @0x136998 add r0, pc, r0 */
/* @0x13699c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1369a0 ldr r1, [pc, #0xd0c] */
/* @0x1369a4 ldr r0, [pc, #0xd0c] */
/* @0x1369a8 mov r2, #7 */
/* @0x1369ac mov r3, #1 */
/* @0x1369b0 ldr r1, [r4, r1] */
/* @0x1369b4 add r0, pc, r0 */
/* @0x1369b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1369bc ldr r1, [pc, #0xcf8] */
/* @0x1369c0 ldr r0, [pc, #0xcf8] */
/* @0x1369c4 mov r2, #0 */
/* @0x1369c8 mov r3, #1 */
/* @0x1369cc ldr r1, [r4, r1] */
/* @0x1369d0 add r0, pc, r0 */
/* @0x1369d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1369d8 ldr r1, [pc, #0xce4] */
/* @0x1369dc ldr r0, [pc, #0xce4] */
/* @0x1369e0 mov r2, #0 */
/* @0x1369e4 mov r3, #1 */
/* @0x1369e8 ldr r1, [r4, r1] */
/* @0x1369ec add r0, pc, r0 */
/* @0x1369f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1369f4 ldr r1, [pc, #0xcd0] */
/* @0x1369f8 ldr r0, [pc, #0xcd0] */
/* @0x1369fc mov r2, #0 */
/* @0x136a00 mov r3, #1 */
/* @0x136a04 ldr r1, [r4, r1] */
/* @0x136a08 add r0, pc, r0 */
/* @0x136a0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136a10 ldr r1, [pc, #0xcbc] */
/* @0x136a14 ldr r0, [pc, #0xcbc] */
/* @0x136a18 mov r2, #0 */
/* @0x136a1c mov r3, #1 */
/* @0x136a20 ldr r1, [r4, r1] */
/* @0x136a24 add r0, pc, r0 */
/* @0x136a28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136a2c ldr r1, [pc, #0xca8] */
/* @0x136a30 ldr r0, [pc, #0xca8] */
/* @0x136a34 mov r2, #0 */
/* @0x136a38 mov r3, #1 */
/* @0x136a3c ldr r1, [r4, r1] */
/* @0x136a40 add r0, pc, r0 */
/* @0x136a44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136a48 ldr r1, [pc, #0xc94] */
/* @0x136a4c ldr r0, [pc, #0xc94] */
/* @0x136a50 mov r2, #0 */
/* @0x136a54 mov r3, #1 */
/* @0x136a58 ldr r1, [r4, r1] */
/* @0x136a5c add r0, pc, r0 */
/* @0x136a60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136a64 ldr r1, [pc, #0xc80] */
/* @0x136a68 ldr r0, [pc, #0xc80] */
/* @0x136a6c mov r2, #0 */
/* @0x136a70 mov r3, #1 */
/* @0x136a74 ldr r1, [r4, r1] */
/* @0x136a78 add r0, pc, r0 */
/* @0x136a7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136a80 ldr r1, [pc, #0xc6c] */
/* @0x136a84 ldr r0, [pc, #0xc6c] */
/* @0x136a88 mov r2, #1 */
/* @0x136a8c mov r3, r2 */
/* @0x136a90 ldr r1, [r4, r1] */
/* @0x136a94 add r0, pc, r0 */
/* @0x136a98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136a9c ldr r1, [pc, #0xc58] */
/* @0x136aa0 ldr r0, [pc, #0xc58] */
/* @0x136aa4 mov r2, #0 */
/* @0x136aa8 mov r3, #1 */
/* @0x136aac ldr r1, [r4, r1] */
/* @0x136ab0 add r0, pc, r0 */
/* @0x136ab4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136ab8 ldr r1, [pc, #0xc44] */
/* @0x136abc ldr r0, [pc, #0xc44] */
/* @0x136ac0 mov r2, #0 */
/* @0x136ac4 mov r3, #1 */
/* @0x136ac8 ldr r1, [r4, r1] */
/* @0x136acc add r0, pc, r0 */
/* @0x136ad0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136ad4 ldr r1, [pc, #0xc30] */
/* @0x136ad8 ldr r0, [pc, #0xc30] */
/* @0x136adc mov r2, #2 */
/* @0x136ae0 mov r3, #1 */
/* @0x136ae4 ldr r1, [r4, r1] */
/* @0x136ae8 add r0, pc, r0 */
/* @0x136aec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136af0 ldr r1, [pc, #0xc1c] */
/* @0x136af4 ldr r0, [pc, #0xc1c] */
/* @0x136af8 mov r2, #0 */
/* @0x136afc mov r3, #1 */
/* @0x136b00 ldr r1, [r4, r1] */
/* @0x136b04 add r0, pc, r0 */
/* @0x136b08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136b0c ldr r1, [pc, #0xc08] */
/* @0x136b10 ldr r0, [pc, #0xc08] */
/* @0x136b14 mov r2, #0 */
/* @0x136b18 mov r3, #1 */
/* @0x136b1c ldr r1, [r4, r1] */
/* @0x136b20 add r0, pc, r0 */
/* @0x136b24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136b28 ldr r1, [pc, #0xbf4] */
/* @0x136b2c ldr r0, [pc, #0xbf4] */
/* @0x136b30 mov r2, #0 */
/* @0x136b34 mov r3, #1 */
/* @0x136b38 ldr r1, [r4, r1] */
/* @0x136b3c add r0, pc, r0 */
/* @0x136b40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136b44 ldr r1, [pc, #0xbe0] */
/* @0x136b48 ldr r0, [pc, #0xbe0] */
/* @0x136b4c mov r2, #1 */
/* @0x136b50 mov r3, r2 */
/* @0x136b54 ldr r1, [r4, r1] */
/* @0x136b58 add r0, pc, r0 */
/* @0x136b5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136b60 ldr r1, [pc, #0xbcc] */
/* @0x136b64 ldr r0, [pc, #0xbcc] */
/* @0x136b68 mov r2, #1 */
/* @0x136b6c mov r3, r2 */
/* @0x136b70 ldr r1, [r4, r1] */
/* @0x136b74 add r0, pc, r0 */
/* @0x136b78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136b7c ldr r1, [pc, #0xbb8] */
/* @0x136b80 ldr r0, [pc, #0xbb8] */
/* @0x136b84 mov r2, #0 */
/* @0x136b88 mov r3, #1 */
/* @0x136b8c ldr r1, [r4, r1] */
/* @0x136b90 add r0, pc, r0 */
/* @0x136b94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136b98 ldr r1, [pc, #0xba4] */
/* @0x136b9c ldr r0, [pc, #0xba4] */
/* @0x136ba0 mov r2, #0 */
/* @0x136ba4 mov r3, #1 */
/* @0x136ba8 ldr r1, [r4, r1] */
/* @0x136bac add r0, pc, r0 */
/* @0x136bb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136bb4 ldr r1, [pc, #0xb90] */
/* @0x136bb8 ldr r0, [pc, #0xb90] */
/* @0x136bbc mov r2, #1 */
/* @0x136bc0 mov r3, r2 */
/* @0x136bc4 ldr r1, [r4, r1] */
/* @0x136bc8 add r0, pc, r0 */
/* @0x136bcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136bd0 ldr r1, [pc, #0xb7c] */
/* @0x136bd4 ldr r0, [pc, #0xb7c] */
/* @0x136bd8 mov r2, #3 */
/* @0x136bdc mov r3, #1 */
/* @0x136be0 ldr r1, [r4, r1] */
/* @0x136be4 add r0, pc, r0 */
/* @0x136be8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136bec ldr r1, [pc, #0xb68] */
/* @0x136bf0 ldr r0, [pc, #0xb68] */
/* @0x136bf4 mov r2, #3 */
/* @0x136bf8 mov r3, #1 */
/* @0x136bfc ldr r1, [r4, r1] */
/* @0x136c00 add r0, pc, r0 */
/* @0x136c04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136c08 ldr r1, [pc, #0xb54] */
/* @0x136c0c ldr r0, [pc, #0xb54] */
/* @0x136c10 mov r2, #6 */
/* @0x136c14 mov r3, #1 */
/* @0x136c18 ldr r1, [r4, r1] */
/* @0x136c1c add r0, pc, r0 */
/* @0x136c20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136c24 ldr r1, [pc, #0xb40] */
/* @0x136c28 ldr r0, [pc, #0xb40] */
/* @0x136c2c mov r2, #4 */
/* @0x136c30 mov r3, #1 */
/* @0x136c34 ldr r1, [r4, r1] */
/* @0x136c38 add r0, pc, r0 */
/* @0x136c3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136c40 ldr r1, [pc, #0xb2c] */
/* @0x136c44 ldr r0, [pc, #0xb2c] */
/* @0x136c48 mov r2, #4 */
/* @0x136c4c mov r3, #1 */
/* @0x136c50 ldr r1, [r4, r1] */
/* @0x136c54 add r0, pc, r0 */
/* @0x136c58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136c5c ldr r1, [pc, #0xb18] */
/* @0x136c60 ldr r0, [pc, #0xb18] */
/* @0x136c64 mov r2, #0 */
/* @0x136c68 mov r3, #1 */
/* @0x136c6c ldr r1, [r4, r1] */
/* @0x136c70 add r0, pc, r0 */
/* @0x136c74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136c78 ldr r1, [pc, #0xb04] */
/* @0x136c7c ldr r0, [pc, #0xb04] */
/* @0x136c80 mov r2, #0 */
/* @0x136c84 mov r3, #1 */
/* @0x136c88 ldr r1, [r4, r1] */
/* @0x136c8c add r0, pc, r0 */
/* @0x136c90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136c94 ldr r1, [pc, #0xaf0] */
/* @0x136c98 ldr r0, [pc, #0xaf0] */
/* @0x136c9c mov r2, #1 */
/* @0x136ca0 mov r3, r2 */
/* @0x136ca4 ldr r1, [r4, r1] */
/* @0x136ca8 add r0, pc, r0 */
/* @0x136cac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136cb0 ldr r1, [pc, #0xadc] */
/* @0x136cb4 ldr r0, [pc, #0xadc] */
/* @0x136cb8 mov r2, #3 */
/* @0x136cbc mov r3, #1 */
/* @0x136cc0 ldr r1, [r4, r1] */
/* @0x136cc4 add r0, pc, r0 */
/* @0x136cc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136ccc ldr r1, [pc, #0xac8] */
/* @0x136cd0 ldr r0, [pc, #0xac8] */
/* @0x136cd4 mov r2, #4 */
/* @0x136cd8 mov r3, #1 */
/* @0x136cdc ldr r1, [r4, r1] */
/* @0x136ce0 add r0, pc, r0 */
/* @0x136ce4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136ce8 ldr r1, [pc, #0xab4] */
/* @0x136cec ldr r0, [pc, #0xab4] */
/* @0x136cf0 mov r2, #9 */
/* @0x136cf4 mov r3, #1 */
/* @0x136cf8 ldr r1, [r4, r1] */
/* @0x136cfc add r0, pc, r0 */
/* @0x136d00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136d04 ldr r1, [pc, #0xaa0] */
/* @0x136d08 ldr r0, [pc, #0xaa0] */
/* @0x136d0c mov r2, #1 */
/* @0x136d10 mov r3, r2 */
/* @0x136d14 ldr r1, [r4, r1] */
/* @0x136d18 add r0, pc, r0 */
/* @0x136d1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136d20 ldr r1, [pc, #0xa8c] */
/* @0x136d24 ldr r0, [pc, #0xa8c] */
/* @0x136d28 mov r2, #1 */
/* @0x136d2c mov r3, r2 */
/* @0x136d30 ldr r1, [r4, r1] */
/* @0x136d34 add r0, pc, r0 */
/* @0x136d38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136d3c ldr r1, [pc, #0xa78] */
/* @0x136d40 ldr r0, [pc, #0xa78] */
/* @0x136d44 mov r2, #1 */
/* @0x136d48 mov r3, r2 */
/* @0x136d4c ldr r1, [r4, r1] */
/* @0x136d50 add r0, pc, r0 */
/* @0x136d54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136d58 ldr r1, [pc, #0xa64] */
/* @0x136d5c ldr r0, [pc, #0xa64] */
/* @0x136d60 mov r2, #1 */
/* @0x136d64 mov r3, r2 */
/* @0x136d68 ldr r1, [r4, r1] */
/* @0x136d6c add r0, pc, r0 */
/* @0x136d70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136d74 ldr r1, [pc, #0xa50] */
/* @0x136d78 ldr r0, [pc, #0xa50] */
/* @0x136d7c mov r2, #0 */
/* @0x136d80 mov r3, #1 */
/* @0x136d84 ldr r1, [r4, r1] */
/* @0x136d88 add r0, pc, r0 */
/* @0x136d8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136d90 ldr r1, [pc, #0xa3c] */
/* @0x136d94 ldr r0, [pc, #0xa3c] */
/* @0x136d98 mov r2, #0 */
/* @0x136d9c mov r3, #1 */
/* @0x136da0 ldr r1, [r4, r1] */
/* @0x136da4 add r0, pc, r0 */
/* @0x136da8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136dac ldr r1, [pc, #0xa28] */
/* @0x136db0 ldr r0, [pc, #0xa28] */
/* @0x136db4 mov r2, #1 */
/* @0x136db8 mov r3, r2 */
/* @0x136dbc ldr r1, [r4, r1] */
/* @0x136dc0 add r0, pc, r0 */
/* @0x136dc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136dc8 ldr r1, [pc, #0xa14] */
/* @0x136dcc ldr r0, [pc, #0xa14] */
/* @0x136dd0 mov r2, #1 */
/* @0x136dd4 mov r3, r2 */
/* @0x136dd8 ldr r1, [r4, r1] */
/* @0x136ddc add r0, pc, r0 */
/* @0x136de0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136de4 ldr r1, [pc, #0xa00] */
/* @0x136de8 ldr r0, [pc, #0xa00] */
/* @0x136dec mov r2, #1 */
/* @0x136df0 mov r3, r2 */
/* @0x136df4 ldr r1, [r4, r1] */
/* @0x136df8 add r0, pc, r0 */
/* @0x136dfc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136e00 ldr r1, [pc, #0x9ec] */
/* @0x136e04 ldr r0, [pc, #0x9ec] */
/* @0x136e08 mov r2, #1 */
/* @0x136e0c mov r3, r2 */
/* @0x136e10 ldr r1, [r4, r1] */
/* @0x136e14 add r0, pc, r0 */
/* @0x136e18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136e1c ldr r1, [pc, #0x9d8] */
/* @0x136e20 ldr r0, [pc, #0x9d8] */
/* @0x136e24 mov r2, #1 */
/* @0x136e28 mov r3, r2 */
/* @0x136e2c ldr r1, [r4, r1] */
/* @0x136e30 add r0, pc, r0 */
/* @0x136e34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136e38 ldr r1, [pc, #0x9c4] */
/* @0x136e3c ldr r0, [pc, #0x9c4] */
/* @0x136e40 mov r2, #1 */
/* @0x136e44 mov r3, r2 */
/* @0x136e48 ldr r1, [r4, r1] */
/* @0x136e4c add r0, pc, r0 */
/* @0x136e50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136e54 ldr r1, [pc, #0x9b0] */
/* @0x136e58 ldr r0, [pc, #0x9b0] */
/* @0x136e5c mov r2, #2 */
/* @0x136e60 mov r3, #1 */
/* @0x136e64 ldr r1, [r4, r1] */
/* @0x136e68 add r0, pc, r0 */
/* @0x136e6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136e70 ldr r1, [pc, #0x99c] */
/* @0x136e74 ldr r0, [pc, #0x99c] */
/* @0x136e78 mov r2, #2 */
/* @0x136e7c mov r3, #1 */
/* @0x136e80 ldr r1, [r4, r1] */
/* @0x136e84 add r0, pc, r0 */
/* @0x136e88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136e8c ldr r1, [pc, #0x988] */
/* @0x136e90 ldr r0, [pc, #0x988] */
/* @0x136e94 mov r2, #4 */
/* @0x136e98 mov r3, #1 */
/* @0x136e9c ldr r1, [r4, r1] */
/* @0x136ea0 add r0, pc, r0 */
/* @0x136ea4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136ea8 ldr r1, [pc, #0x974] */
/* @0x136eac ldr r0, [pc, #0x974] */
/* @0x136eb0 mov r2, #1 */
/* @0x136eb4 mov r3, r2 */
/* @0x136eb8 ldr r1, [r4, r1] */
/* @0x136ebc add r0, pc, r0 */
/* @0x136ec0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136ec4 ldr r1, [pc, #0x960] */
/* @0x136ec8 ldr r0, [pc, #0x960] */
/* @0x136ecc mov r2, #2 */
/* @0x136ed0 mov r3, #0 */
/* @0x136ed4 ldr r1, [r4, r1] */
/* @0x136ed8 add r0, pc, r0 */
/* @0x136edc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136ee0 ldr r1, [pc, #0x94c] */
/* @0x136ee4 ldr r0, [pc, #0x94c] */
/* @0x136ee8 mov r2, #0 */
/* @0x136eec mov r3, #1 */
/* @0x136ef0 ldr r1, [r4, r1] */
/* @0x136ef4 add r0, pc, r0 */
/* @0x136ef8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136efc ldr r1, [pc, #0x938] */
/* @0x136f00 ldr r0, [pc, #0x938] */
/* @0x136f04 mov r2, #0 */
/* @0x136f08 mov r3, #1 */
/* @0x136f0c ldr r1, [r4, r1] */
/* @0x136f10 add r0, pc, r0 */
/* @0x136f14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136f18 ldr r1, [pc, #0x924] */
/* @0x136f1c ldr r0, [pc, #0x924] */
/* @0x136f20 mov r2, #0 */
/* @0x136f24 mov r3, #1 */
/* @0x136f28 ldr r1, [r4, r1] */
/* @0x136f2c add r0, pc, r0 */
/* @0x136f30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136f34 ldr r1, [pc, #0x910] */
/* @0x136f38 ldr r0, [pc, #0x910] */
/* @0x136f3c mov r2, #0 */
/* @0x136f40 mov r3, #1 */
/* @0x136f44 ldr r1, [r4, r1] */
/* @0x136f48 add r0, pc, r0 */
/* @0x136f4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136f50 ldr r1, [pc, #0x8fc] */
/* @0x136f54 ldr r0, [pc, #0x8fc] */
/* @0x136f58 mov r2, #2 */
/* @0x136f5c mov r3, #1 */
/* @0x136f60 ldr r1, [r4, r1] */
/* @0x136f64 add r0, pc, r0 */
/* @0x136f68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136f6c ldr r1, [pc, #0x8e8] */
/* @0x136f70 ldr r0, [pc, #0x8e8] */
/* @0x136f74 mov r2, #3 */
/* @0x136f78 mov r3, #1 */
/* @0x136f7c ldr r1, [r4, r1] */
/* @0x136f80 add r0, pc, r0 */
/* @0x136f84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136f88 ldr r1, [pc, #0x8d4] */
/* @0x136f8c ldr r0, [pc, #0x8d4] */
/* @0x136f90 mov r2, #2 */
/* @0x136f94 mov r3, #1 */
/* @0x136f98 ldr r1, [r4, r1] */
/* @0x136f9c add r0, pc, r0 */
/* @0x136fa0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136fa4 ldr r1, [pc, #0x8c0] */
/* @0x136fa8 ldr r0, [pc, #0x8c0] */
/* @0x136fac mov r2, #0 */
/* @0x136fb0 mov r3, #1 */
/* @0x136fb4 ldr r1, [r4, r1] */
/* @0x136fb8 add r0, pc, r0 */
/* @0x136fbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136fc0 ldr r1, [pc, #0x8ac] */
/* @0x136fc4 ldr r0, [pc, #0x8ac] */
/* @0x136fc8 mov r2, #1 */
/* @0x136fcc mov r3, r2 */
/* @0x136fd0 ldr r1, [r4, r1] */
/* @0x136fd4 add r0, pc, r0 */
/* @0x136fd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136fdc ldr r1, [pc, #0x898] */
/* @0x136fe0 ldr r0, [pc, #0x898] */
/* @0x136fe4 mov r2, #1 */
/* @0x136fe8 mov r3, r2 */
/* @0x136fec ldr r1, [r4, r1] */
/* @0x136ff0 add r0, pc, r0 */
/* @0x136ff4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x136ff8 ldr r1, [pc, #0x884] */
/* @0x136ffc ldr r0, [pc, #0x884] */
/* @0x137000 mov r2, #1 */
/* @0x137004 mov r3, r2 */
/* @0x137008 ldr r1, [r4, r1] */
/* @0x13700c add r0, pc, r0 */
/* @0x137010 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137014 ldr r1, [pc, #0x870] */
/* @0x137018 ldr r0, [pc, #0x870] */
/* @0x13701c mov r2, #1 */
/* @0x137020 mov r3, r2 */
/* @0x137024 ldr r1, [r4, r1] */
/* @0x137028 add r0, pc, r0 */
/* @0x13702c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137030 ldr r1, [pc, #0x85c] */
/* @0x137034 ldr r0, [pc, #0x85c] */
/* @0x137038 mov r2, #1 */
/* @0x13703c mov r3, r2 */
/* @0x137040 ldr r1, [r4, r1] */
/* @0x137044 add r0, pc, r0 */
/* @0x137048 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13704c ldr r1, [pc, #0x848] */
/* @0x137050 ldr r0, [pc, #0x848] */
/* @0x137054 mov r2, #1 */
/* @0x137058 mov r3, r2 */
/* @0x13705c ldr r1, [r4, r1] */
/* @0x137060 add r0, pc, r0 */
/* @0x137064 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137068 ldr r1, [pc, #0x834] */
/* @0x13706c ldr r0, [pc, #0x834] */
/* @0x137070 mov r2, #1 */
/* @0x137074 mov r3, r2 */
/* @0x137078 ldr r1, [r4, r1] */
/* @0x13707c add r0, pc, r0 */
/* @0x137080 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137084 ldr r1, [pc, #0x820] */
/* @0x137088 ldr r0, [pc, #0x820] */
/* @0x13708c mov r2, #1 */
/* @0x137090 mov r3, r2 */
/* @0x137094 ldr r1, [r4, r1] */
/* @0x137098 add r0, pc, r0 */
/* @0x13709c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1370a0 ldr r1, [pc, #0x80c] */
/* @0x1370a4 ldr r0, [pc, #0x80c] */
/* @0x1370a8 mov r2, #1 */
/* @0x1370ac mov r3, r2 */
/* @0x1370b0 ldr r1, [r4, r1] */
/* @0x1370b4 add r0, pc, r0 */
/* @0x1370b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1370bc ldr r1, [pc, #0x7f8] */
/* @0x1370c0 ldr r0, [pc, #0x7f8] */
/* @0x1370c4 mov r2, #4 */
/* @0x1370c8 mov r3, #1 */
/* @0x1370cc ldr r1, [r4, r1] */
/* @0x1370d0 add r0, pc, r0 */
/* @0x1370d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1370d8 ldr r1, [pc, #0x7e4] */
/* @0x1370dc ldr r0, [pc, #0x7e4] */
/* @0x1370e0 mov r2, #4 */
/* @0x1370e4 mov r3, #1 */
/* @0x1370e8 ldr r1, [r4, r1] */
/* @0x1370ec add r0, pc, r0 */
/* @0x1370f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1370f4 ldr r1, [pc, #0x7d0] */
/* @0x1370f8 ldr r0, [pc, #0x7d0] */
/* @0x1370fc mov r2, #7 */
/* @0x137100 mov r3, #1 */
/* @0x137104 ldr r1, [r4, r1] */
/* @0x137108 add r0, pc, r0 */
/* @0x13710c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137110 ldr r1, [pc, #0x7bc] */
/* @0x137114 ldr r0, [pc, #0x7bc] */
/* @0x137118 mov r2, #1 */
/* @0x13711c mov r3, r2 */
/* @0x137120 ldr r1, [r4, r1] */
/* @0x137124 add r0, pc, r0 */
/* @0x137128 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13712c ldr r1, [pc, #0x7a8] */
/* @0x137130 ldr r0, [pc, #0x7a8] */
/* @0x137134 mov r2, #2 */
/* @0x137138 mov r3, #1 */
/* @0x13713c ldr r1, [r4, r1] */
/* @0x137140 add r0, pc, r0 */
/* @0x137144 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137148 ldr r1, [pc, #0x794] */
/* @0x13714c ldr r0, [pc, #0x794] */
/* @0x137150 mov r2, #1 */
/* @0x137154 mov r3, r2 */
/* @0x137158 ldr r1, [r4, r1] */
/* @0x13715c add r0, pc, r0 */
/* @0x137160 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137164 ldr r1, [pc, #0x780] */
/* @0x137168 ldr r0, [pc, #0x780] */
/* @0x13716c mov r2, #1 */
/* @0x137170 mov r3, r2 */
/* @0x137174 ldr r1, [r4, r1] */
/* @0x137178 add r0, pc, r0 */
/* @0x13717c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137180 ldr r1, [pc, #0x76c] */
/* @0x137184 ldr r0, [pc, #0x76c] */
/* @0x137188 mov r2, #1 */
/* @0x13718c mov r3, r2 */
/* @0x137190 ldr r1, [r4, r1] */
/* @0x137194 add r0, pc, r0 */
/* @0x137198 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13719c ldr r1, [pc, #0x758] */
/* @0x1371a0 ldr r0, [pc, #0x758] */
/* @0x1371a4 mov r2, #1 */
/* @0x1371a8 mov r3, r2 */
/* @0x1371ac ldr r1, [r4, r1] */
/* @0x1371b0 add r0, pc, r0 */
/* @0x1371b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1371b8 ldr r1, [pc, #0x744] */
/* @0x1371bc ldr r0, [pc, #0x744] */
/* @0x1371c0 mov r2, #2 */
/* @0x1371c4 mov r3, #1 */
/* @0x1371c8 ldr r1, [r4, r1] */
/* @0x1371cc add r0, pc, r0 */
/* @0x1371d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1371d4 ldr r1, [pc, #0x730] */
/* @0x1371d8 ldr r0, [pc, #0x730] */
/* @0x1371dc mov r2, #1 */
/* @0x1371e0 mov r3, r2 */
/* @0x1371e4 ldr r1, [r4, r1] */
/* @0x1371e8 add r0, pc, r0 */
/* @0x1371ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1371f0 ldr r1, [pc, #0x71c] */
/* @0x1371f4 ldr r0, [pc, #0x71c] */
/* @0x1371f8 mov r2, #1 */
/* @0x1371fc mov r3, #0 */
/* @0x137200 ldr r1, [r4, r1] */
/* @0x137204 add r0, pc, r0 */
/* @0x137208 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13720c ldr r1, [pc, #0x708] */
/* @0x137210 ldr r0, [pc, #0x708] */
/* @0x137214 mov r2, #1 */
/* @0x137218 mov r3, #0 */
/* @0x13721c ldr r1, [r4, r1] */
/* @0x137220 add r0, pc, r0 */
/* @0x137224 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137228 ldr r1, [pc, #0x6f4] */
/* @0x13722c ldr r0, [pc, #0x6f4] */
/* @0x137230 mov r2, #1 */
/* @0x137234 mov r3, #0 */
/* @0x137238 ldr r1, [r4, r1] */
/* @0x13723c add r0, pc, r0 */
/* @0x137240 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137244 ldr r1, [pc, #0x6e0] */
/* @0x137248 ldr r0, [pc, #0x6e0] */
/* @0x13724c mov r2, #1 */
/* @0x137250 mov r3, #0 */
/* @0x137254 ldr r1, [r4, r1] */
/* @0x137258 add r0, pc, r0 */
/* @0x13725c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137260 ldr r1, [pc, #0x6cc] */
/* @0x137264 ldr r0, [pc, #0x6cc] */
/* @0x137268 mov r2, #1 */
/* @0x13726c mov r3, #0 */
/* @0x137270 ldr r1, [r4, r1] */
/* @0x137274 add r0, pc, r0 */
/* @0x137278 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13727c ldr r1, [pc, #0x6b8] */
/* @0x137280 ldr r0, [pc, #0x6b8] */
/* @0x137284 mov r2, #1 */
/* @0x137288 mov r3, #0 */
/* @0x13728c ldr r1, [r4, r1] */
/* @0x137290 add r0, pc, r0 */
/* @0x137294 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137298 ldr r1, [pc, #0x6a4] */
/* @0x13729c ldr r0, [pc, #0x6a4] */
/* @0x1372a0 mov r2, #3 */
/* @0x1372a4 mov r3, #0 */
/* @0x1372a8 ldr r1, [r4, r1] */
/* @0x1372ac add r0, pc, r0 */
/* @0x1372b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1372b4 ldr r1, [pc, #0x690] */
/* @0x1372b8 ldr r0, [pc, #0x690] */
/* @0x1372bc mov r2, #6 */
/* @0x1372c0 mov r3, #0 */
/* @0x1372c4 ldr r1, [r4, r1] */
/* @0x1372c8 add r0, pc, r0 */
/* @0x1372cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1372d0 ldr r1, [pc, #0x67c] */
/* @0x1372d4 ldr r0, [pc, #0x67c] */
/* @0x1372d8 mov r2, #1 */
/* @0x1372dc mov r3, #0 */
/* @0x1372e0 ldr r1, [r4, r1] */
/* @0x1372e4 add r0, pc, r0 */
/* @0x1372e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1372ec ldr r1, [pc, #0x668] */
/* @0x1372f0 ldr r0, [pc, #0x668] */
/* @0x1372f4 mov r2, #3 */
/* @0x1372f8 mov r3, #0 */
/* @0x1372fc ldr r1, [r4, r1] */
/* @0x137300 add r0, pc, r0 */
/* @0x137304 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137308 ldr r1, [pc, #0x654] */
/* @0x13730c ldr r0, [pc, #0x654] */
/* @0x137310 mov r2, #0 */
/* @0x137314 mov r3, r2 */
/* @0x137318 ldr r1, [r4, r1] */
/* @0x13731c add r0, pc, r0 */
/* @0x137320 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137324 ldr r1, [pc, #0x640] */
/* @0x137328 ldr r0, [pc, #0x640] */
/* @0x13732c mov r2, #4 */
/* @0x137330 mov r3, #0 */
/* @0x137334 ldr r1, [r4, r1] */
/* @0x137338 add r0, pc, r0 */
/* @0x13733c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137340 ldr r1, [pc, #0x62c] */
/* @0x137344 ldr r0, [pc, #0x62c] */
/* @0x137348 mov r2, #1 */
/* @0x13734c mov r3, #0 */
/* @0x137350 ldr r1, [r4, r1] */
/* @0x137354 add r0, pc, r0 */
/* @0x137358 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13735c ldr r1, [pc, #0x618] */
/* @0x137360 ldr r0, [pc, #0x618] */
/* @0x137364 mov r2, #1 */
/* @0x137368 mov r3, #0 */
/* @0x13736c ldr r1, [r4, r1] */
/* @0x137370 add r0, pc, r0 */
/* @0x137374 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137378 ldr r1, [pc, #0x604] */
/* @0x13737c ldr r0, [pc, #0x604] */
/* @0x137380 mov r2, #0 */
/* @0x137384 mov r3, r2 */
/* @0x137388 ldr r1, [r4, r1] */
/* @0x13738c add r0, pc, r0 */
/* @0x137390 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137394 ldr r1, [pc, #0x5f0] */
/* @0x137398 ldr r0, [pc, #0x5f0] */
/* @0x13739c mov r2, #1 */
/* @0x1373a0 mov r3, #0 */
/* @0x1373a4 ldr r1, [r4, r1] */
/* @0x1373a8 add r0, pc, r0 */
/* @0x1373ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1373b0 ldr r1, [pc, #0x5dc] */
/* @0x1373b4 ldr r0, [pc, #0x5dc] */
/* @0x1373b8 mov r2, #1 */
/* @0x1373bc mov r3, r2 */
/* @0x1373c0 ldr r1, [r4, r1] */
/* @0x1373c4 add r0, pc, r0 */
/* @0x1373c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1373cc ldr r1, [pc, #0x5c8] */
/* @0x1373d0 ldr r0, [pc, #0x5c8] */
/* @0x1373d4 mov r2, #2 */
/* @0x1373d8 mov r3, #1 */
/* @0x1373dc ldr r1, [r4, r1] */
/* @0x1373e0 add r0, pc, r0 */
/* @0x1373e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1373e8 ldr r1, [pc, #0x5b4] */
/* @0x1373ec ldr r0, [pc, #0x5b4] */
/* @0x1373f0 mov r2, #1 */
/* @0x1373f4 mov r3, r2 */
/* @0x1373f8 ldr r1, [r4, r1] */
/* @0x1373fc add r0, pc, r0 */
/* @0x137400 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137404 ldr r1, [pc, #0x5a0] */
/* @0x137408 ldr r0, [pc, #0x5a0] */
/* @0x13740c mov r2, #2 */
/* @0x137410 mov r3, #1 */
/* @0x137414 ldr r1, [r4, r1] */
/* @0x137418 add r0, pc, r0 */
/* @0x13741c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137420 ldr r1, [pc, #0x58c] */
/* @0x137424 ldr r0, [pc, #0x58c] */
/* @0x137428 mov r2, #0 */
/* @0x13742c mov r3, #1 */
/* @0x137430 ldr r1, [r4, r1] */
/* @0x137434 add r0, pc, r0 */
/* @0x137438 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13743c ldr r1, [pc, #0x578] */
/* @0x137440 ldr r0, [pc, #0x578] */
/* @0x137444 mov r2, #1 */
/* @0x137448 mov r3, r2 */
/* @0x13744c ldr r1, [r4, r1] */
/* @0x137450 add r0, pc, r0 */
/* @0x137454 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137458 ldr r1, [pc, #0x564] */
/* @0x13745c ldr r0, [pc, #0x564] */
/* @0x137460 mov r2, #0 */
/* @0x137464 mov r3, #1 */
/* @0x137468 ldr r1, [r4, r1] */
/* @0x13746c add r0, pc, r0 */
/* @0x137470 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137474 ldr r1, [pc, #0x550] */
/* @0x137478 ldr r0, [pc, #0x550] */
/* @0x13747c mov r2, #0 */
/* @0x137480 mov r3, #1 */
/* @0x137484 ldr r1, [r4, r1] */
/* @0x137488 add r0, pc, r0 */
/* @0x13748c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137490 ldr r1, [pc, #0x53c] */
/* @0x137494 ldr r0, [pc, #0x53c] */
/* @0x137498 mov r2, #1 */
/* @0x13749c mov r3, #0 */
/* @0x1374a0 ldr r1, [r4, r1] */
/* @0x1374a4 add r0, pc, r0 */
/* @0x1374a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1374ac ldr r1, [pc, #0x528] */
/* @0x1374b0 ldr r0, [pc, #0x528] */
/* @0x1374b4 mov r2, #1 */
/* @0x1374b8 mov r3, #0 */
/* @0x1374bc ldr r1, [r4, r1] */
/* @0x1374c0 add r0, pc, r0 */
/* @0x1374c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1374c8 ldr r1, [pc, #0x514] */
/* @0x1374cc ldr r0, [pc, #0x514] */
/* @0x1374d0 mov r2, #4 */
/* @0x1374d4 mov r3, #0 */
/* @0x1374d8 ldr r1, [r4, r1] */
/* @0x1374dc add r0, pc, r0 */
/* @0x1374e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1374e4 ldr r1, [pc, #0x500] */
/* @0x1374e8 ldr r0, [pc, #0x500] */
/* @0x1374ec mov r2, #1 */
/* @0x1374f0 mov r3, #0 */
/* @0x1374f4 ldr r1, [r4, r1] */
/* @0x1374f8 add r0, pc, r0 */
/* @0x1374fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137500 ldr r1, [pc, #0x4ec] */
/* @0x137504 ldr r0, [pc, #0x4ec] */
/* @0x137508 mov r2, #1 */
/* @0x13750c mov r3, #0 */
/* @0x137510 ldr r1, [r4, r1] */
/* @0x137514 add r0, pc, r0 */
/* @0x137518 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13751c ldr r1, [pc, #0x4d8] */
/* @0x137520 ldr r0, [pc, #0x4d8] */
/* @0x137524 mov r2, #1 */
/* @0x137528 mov r3, #0 */
/* @0x13752c ldr r1, [r4, r1] */
/* @0x137530 add r0, pc, r0 */
/* @0x137534 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137538 ldr r1, [pc, #0x4c4] */
/* @0x13753c ldr r0, [pc, #0x4c4] */
/* @0x137540 mov r2, #1 */
/* @0x137544 mov r3, #0 */
/* @0x137548 ldr r1, [r4, r1] */
/* @0x13754c add r0, pc, r0 */
/* @0x137550 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137554 ldr r1, [pc, #0x4b0] */
/* @0x137558 ldr r0, [pc, #0x4b0] */
/* @0x13755c mov r2, #1 */
/* @0x137560 mov r3, #0 */
/* @0x137564 ldr r1, [r4, r1] */
/* @0x137568 add r0, pc, r0 */
/* @0x13756c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137570 ldr r1, [pc, #0x49c] */
/* @0x137574 ldr r0, [pc, #0x49c] */
/* @0x137578 mov r2, #1 */
/* @0x13757c mov r3, #0 */
/* @0x137580 ldr r1, [r4, r1] */
/* @0x137584 add r0, pc, r0 */
/* @0x137588 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13758c ldr r1, [pc, #0x488] */
/* @0x137590 ldr r0, [pc, #0x488] */
/* @0x137594 mov r2, #1 */
/* @0x137598 mov r3, #0 */
/* @0x13759c ldr r1, [r4, r1] */
/* @0x1375a0 add r0, pc, r0 */
/* @0x1375a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1375a8 ldr r1, [pc, #0x474] */
/* @0x1375ac ldr r0, [pc, #0x474] */
/* @0x1375b0 mov r2, #1 */
/* @0x1375b4 mov r3, #0 */
/* @0x1375b8 ldr r1, [r4, r1] */
/* @0x1375bc add r0, pc, r0 */
/* @0x1375c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1375c4 ldr r1, [pc, #0x460] */
/* @0x1375c8 ldr r0, [pc, #0x460] */
/* @0x1375cc mov r2, #1 */
/* @0x1375d0 mov r3, #0 */
/* @0x1375d4 ldr r1, [r4, r1] */
/* @0x1375d8 add r0, pc, r0 */
/* @0x1375dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1375e0 ldr r1, [pc, #0x44c] */
/* @0x1375e4 ldr r0, [pc, #0x44c] */
/* @0x1375e8 mov r2, #1 */
/* @0x1375ec mov r3, #0 */
/* @0x1375f0 ldr r1, [r4, r1] */
/* @0x1375f4 add r0, pc, r0 */
/* @0x1375f8 pop {r4, lr} */
/* @0x1375fc b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x137600 eoreq r11, r11, r0, lsl r5 */
/* @0x137604 .word 0xffffd404 */
/* @0x137608 eoreq r8, r0, r8, asr sp */
/* @0x13760c .word 0xffffd408 */
/* @0x137610 eoreq r8, r0, r8, asr #26 */
/* @0x137614 .word 0xffffd40c */
/* @0x137618 eoreq r8, r0, r8, lsr sp */
/* @0x13761c .word 0xffffd410 */
/* @0x137620 eoreq r8, r0, r8, lsr #26 */
/* @0x137624 .word 0xffffd414 */
/* @0x137628 eoreq r8, r0, r12, lsl sp */
/* @0x13762c .word 0xffffd418 */
/* @0x137630 eoreq r8, r0, r0, lsl sp */
/* @0x137634 .word 0xffffd41c */
/* @0x137638 eoreq r8, r0, r4, lsl #26 */
/* @0x13763c .word 0xffffd420 */
/* @0x137640 .word 0x00208cf4 */
/* @0x137644 .word 0xffffd424 */
/* @0x137648 eoreq r8, r0, r4, ror #25 */
/* @0x13764c .word 0xffffd428 */
/* @0x137650 eoreq r8, r0, r0, ror #25 */
/* @0x137654 .word 0xffffd42c */
/* @0x137658 .word 0x00208cd8 */
/* @0x13765c .word 0xffffd430 */
/* @0x137660 .word 0x00208cd8 */
/* @0x137664 .word 0xffffd434 */
/* @0x137668 .word 0x00208cd0 */
/* @0x13766c .word 0xffffd438 */
/* @0x137670 eoreq r8, r0, r8, asr #25 */
/* @0x137674 .word 0xffffd43c */
/* @0x137678 eoreq r8, r0, r4, asr #25 */
/* @0x13767c .word 0xffffd440 */
/* @0x137680 .word 0x00208cbc */
/* @0x137684 .word 0xffffd444 */
/* @0x137688 .word 0x00208cb8 */
/* @0x13768c .word 0xffffd448 */
/* @0x137690 .word 0x00208cb0 */
/* @0x137694 .word 0xffffd44c */
/* @0x137698 eoreq r8, r0, r12, lsr #25 */
/* @0x13769c .word 0xffffd450 */
/* @0x1376a0 eoreq r8, r0, r4, lsr #25 */
/* @0x1376a4 .word 0xffffd454 */
/* @0x1376a8 eoreq r8, r0, r4, lsr #25 */
/* @0x1376ac .word 0xffffd458 */
/* @0x1376b0 eoreq r8, r0, r4, lsr #25 */
/* @0x1376b4 .word 0xffffd45c */
/* @0x1376b8 eoreq r8, r0, r4, lsr #25 */
/* @0x1376bc .word 0xffffd460 */
/* @0x1376c0 eoreq r8, r0, r0, lsr #25 */
/* @0x1376c4 .word 0xffffd464 */
/* @0x1376c8 eoreq r8, r0, r12, lsl #25 */
/* @0x1376cc .word 0xffffd468 */
/* @0x1376d0 eoreq r8, r0, r12, ror r12 */
/* @0x1376d4 .word 0xffffd46c */
/* @0x1376d8 eoreq r8, r0, r12, ror #24 */
/* @0x1376dc .word 0xffffd470 */
/* @0x1376e0 eoreq r8, r0, r12, asr r12 */
/* @0x1376e4 .word 0xffffd474 */
/* @0x1376e8 eoreq r8, r0, r12, asr #24 */
/* @0x1376ec .word 0xffffd478 */
/* @0x1376f0 eoreq r8, r0, r12, lsr r12 */
/* @0x1376f4 .word 0xffffd47c */
/* @0x1376f8 eoreq r8, r0, r12, lsr #24 */
/* @0x1376fc .word 0xffffd480 */
/* @0x137700 eoreq r8, r0, r0, lsr #24 */
/* @0x137704 .word 0xffffd484 */
/* @0x137708 eoreq r8, r0, r0, lsl r12 */
/* @0x13770c .word 0xffffd488 */
/* @0x137710 eoreq r8, r0, r8, lsl #24 */
/* @0x137714 .word 0xffffd48c */
/* @0x137718 .word 0x00208bf4 */
/* @0x13771c .word 0xffffd490 */
/* @0x137720 eoreq r8, r0, r0, ror #23 */
/* @0x137724 .word 0xffffd494 */
/* @0x137728 .word 0x00208bd0 */
/* @0x13772c .word 0xffffd498 */
/* @0x137730 eoreq r8, r0, r0, asr #23 */
/* @0x137734 .word 0xffffd49c */
/* @0x137738 .word 0x00208bb4 */
/* @0x13773c .word 0xffffd4a0 */
/* @0x137740 .word 0x00208bb0 */
/* @0x137744 .word 0xffffd4a4 */
/* @0x137748 eoreq r8, r0, r4, lsr #23 */
/* @0x13774c .word 0xffffd4a8 */
/* @0x137750 mlaeq r0, r8, r11, r8 */
/* @0x137754 .word 0xffffd4ac */
/* @0x137758 eoreq r8, r0, r8, lsl #23 */
/* @0x13775c .word 0xffffd4b0 */
/* @0x137760 eoreq r8, r0, r4, lsl #23 */
/* @0x137764 .word 0xffffd4b4 */
/* @0x137768 eoreq r8, r0, r0, lsl #23 */
/* @0x13776c .word 0xffffd4b8 */
/* @0x137770 eoreq r8, r0, r0, lsl #23 */
/* @0x137774 .word 0xffffd4bc */
/* @0x137778 eoreq r8, r0, r12, ror r11 */
/* @0x13777c .word 0xffffd4c0 */
/* @0x137780 eoreq r8, r0, r8, ror r11 */
/* @0x137784 .word 0xffffd4c4 */
/* @0x137788 eoreq r8, r0, r12, ror #22 */
/* @0x13778c .word 0xffffd4c8 */
/* @0x137790 eoreq r8, r0, r8, ror #22 */
/* @0x137794 .word 0xffffd4cc */
/* @0x137798 eoreq r8, r0, r0, ror #22 */
/* @0x13779c .word 0xffffd4d0 */
/* @0x1377a0 eoreq r8, r0, r8, asr r11 */
/* @0x1377a4 .word 0xffffd4d4 */
/* @0x1377a8 eoreq r8, r0, r0, asr r11 */
/* @0x1377ac .word 0xffffd4d8 */
/* @0x1377b0 eoreq r8, r0, r8, asr #22 */
/* @0x1377b4 .word 0xffffd4dc */
/* @0x1377b8 eoreq r8, r0, r4, asr #22 */
/* @0x1377bc .word 0xffffd4e0 */
/* @0x1377c0 eoreq r8, r0, r12, lsr r11 */
/* @0x1377c4 .word 0xffffd4e4 */
/* @0x1377c8 eoreq r8, r0, r4, lsr r11 */
/* @0x1377cc .word 0xffffd4e8 */
/* @0x1377d0 eoreq r8, r0, r12, lsr #22 */
/* @0x1377d4 .word 0xffffd4ec */
/* @0x1377d8 eoreq r8, r0, r0, lsr #22 */
/* @0x1377dc .word 0xffffd4f0 */
/* @0x1377e0 eoreq r8, r0, r8, lsl r11 */
/* @0x1377e4 .word 0xffffd4f4 */
/* @0x1377e8 eoreq r8, r0, r0, lsl r11 */
/* @0x1377ec .word 0xffffd4f8 */
/* @0x1377f0 eoreq r8, r0, r4, lsl #22 */
/* @0x1377f4 .word 0xffffd4fc */
/* @0x1377f8 .word 0x00208af8 */
/* @0x1377fc .word 0xffffd500 */
/* @0x137800 .word 0x00208af0 */
/* @0x137804 .word 0xffffd504 */
/* @0x137808 eoreq r8, r0, r12, ror #21 */
/* @0x13780c .word 0xffffd508 */
/* @0x137810 eoreq r8, r0, r0, ror #21 */
/* @0x137814 .word 0xffffd50c */
/* @0x137818 .word 0x00208ad8 */
/* @0x13781c .word 0xffffd510 */
/* @0x137820 .word 0x00208ad0 */
/* @0x137824 .word 0xffffd514 */
/* @0x137828 eoreq r8, r0, r12, asr #21 */
/* @0x13782c .word 0xffffd518 */
/* @0x137830 eoreq r8, r0, r4, asr #21 */
/* @0x137834 .word 0xffffd51c */
/* @0x137838 .word 0x00208abc */
/* @0x13783c .word 0xffffd520 */
/* @0x137840 .word 0x00208ab4 */
/* @0x137844 .word 0xffffd524 */
/* @0x137848 eoreq r8, r0, r12, lsr #21 */
/* @0x13784c .word 0xffffd528 */
/* @0x137850 eoreq r8, r0, r4, lsr #21 */
/* @0x137854 .word 0xffffd52c */
/* @0x137858 eoreq r8, r0, r0, lsr #21 */
/* @0x13785c .word 0xffffd530 */
/* @0x137860 mlaeq r0, r8, r10, r8 */
/* @0x137864 .word 0xffffd534 */
/* @0x137868 mlaeq r0, r0, r10, r8 */
/* @0x13786c .word 0xffffd538 */
/* @0x137870 eoreq r8, r0, r8, lsl #21 */
/* @0x137874 .word 0xffffd53c */
/* @0x137878 eoreq r8, r0, r12, ror r10 */
/* @0x13787c .word 0xffffd540 */
/* @0x137880 eoreq r8, r0, r4, ror r10 */
/* @0x137884 .word 0xffffd544 */
/* @0x137888 eoreq r8, r0, r0, ror r10 */
/* @0x13788c .word 0xffffd548 */
/* @0x137890 eoreq r8, r0, r12, ror #20 */
/* @0x137894 .word 0xffffd54c */
/* @0x137898 eoreq r8, r0, r4, ror #20 */
/* @0x13789c .word 0xffffd550 */
/* @0x1378a0 eoreq r8, r0, r12, asr r10 */
/* @0x1378a4 .word 0xffffd554 */
/* @0x1378a8 eoreq r8, r0, r4, asr r10 */
/* @0x1378ac .word 0xffffd558 */
/* @0x1378b0 eoreq r8, r0, r0, asr r10 */
/* @0x1378b4 .word 0xffffd55c */
/* @0x1378b8 eoreq r8, r0, r12, asr #20 */
/* @0x1378bc .word 0xffffd560 */
/* @0x1378c0 eoreq r8, r0, r8, asr #20 */
/* @0x1378c4 .word 0xffffd564 */
/* @0x1378c8 eoreq r8, r0, r8, asr #20 */
/* @0x1378cc .word 0xffffd568 */
/* @0x1378d0 eoreq r8, r0, r8, asr #20 */
/* @0x1378d4 .word 0xffffd56c */
/* @0x1378d8 eoreq r8, r0, r12, asr #20 */
/* @0x1378dc .word 0xffffd570 */
/* @0x1378e0 eoreq r8, r0, r8, asr #20 */
/* @0x1378e4 .word 0xffffd574 */
/* @0x1378e8 eoreq r8, r0, r4, asr #20 */
/* @0x1378ec .word 0xffffd578 */
/* @0x1378f0 eoreq r8, r0, r0, asr #20 */
/* @0x1378f4 .word 0xffffd57c */
/* @0x1378f8 eoreq r8, r0, r12, lsr r10 */
/* @0x1378fc .word 0xffffd580 */
/* @0x137900 eoreq r8, r0, r8, lsr r10 */
/* @0x137904 .word 0xffffd584 */
/* @0x137908 eoreq r8, r0, r12, lsr #20 */
/* @0x13790c .word 0xffffd588 */
/* @0x137910 eoreq r8, r0, r0, lsr r10 */
/* @0x137914 .word 0xffffd58c */
/* @0x137918 eoreq r8, r0, r4, lsr r10 */
/* @0x13791c .word 0xffffd590 */
/* @0x137920 eoreq r8, r0, r12, lsr #20 */
/* @0x137924 .word 0xffffd594 */
/* @0x137928 eoreq r8, r0, r4, lsr #20 */
/* @0x13792c .word 0xffffd598 */
/* @0x137930 eoreq r8, r0, r0, lsr #20 */
/* @0x137934 .word 0xffffd59c */
/* @0x137938 eoreq r8, r0, r0, lsr #20 */
/* @0x13793c .word 0xffffd5a0 */
/* @0x137940 eoreq r8, r0, r8, lsl r10 */
/* @0x137944 .word 0xffffd5a4 */
/* @0x137948 eoreq r8, r0, r4, lsl r10 */
/* @0x13794c .word 0xffffd5a8 */
/* @0x137950 eoreq r8, r0, r0, lsl r10 */
/* @0x137954 .word 0xffffd5ac */
/* @0x137958 eoreq r8, r0, r0, lsl r10 */
/* @0x13795c .word 0xffffd5b0 */
/* @0x137960 eoreq r8, r0, r12, lsl #20 */
/* @0x137964 .word 0xffffd5b4 */
/* @0x137968 eoreq r8, r0, r8, lsl #20 */
/* @0x13796c .word 0xffffd5b8 */
/* @0x137970 eoreq r8, r0, r4, lsl #20 */
/* @0x137974 .word 0xffffd5bc */
/* @0x137978 .word 0x002089fc */
/* @0x13797c .word 0xffffd5c0 */
/* @0x137980 .word 0x002089f8 */
/* @0x137984 .word 0xffffd5c4 */
/* @0x137988 .word 0x002089f4 */
/* @0x13798c .word 0xffffd5c8 */
/* @0x137990 .word 0x002089f4 */
/* @0x137994 .word 0xffffd5cc */
/* @0x137998 .word 0x002089f0 */
/* @0x13799c .word 0xffffd5d0 */
/* @0x1379a0 .word 0x002089f4 */
/* @0x1379a4 .word 0xffffd5d4 */
/* @0x1379a8 .word 0x002089f8 */
/* @0x1379ac .word 0xffffd5d8 */
/* @0x1379b0 .word 0x002089fc */
/* @0x1379b4 .word 0xffffd5dc */
/* @0x1379b8 eoreq r8, r0, r0, lsl #20 */
/* @0x1379bc .word 0xffffd5e0 */
/* @0x1379c0 .word 0x002089fc */
/* @0x1379c4 .word 0xffffd5e4 */
/* @0x1379c8 .word 0x002089f8 */
/* @0x1379cc .word 0xffffd5e8 */
/* @0x1379d0 .word 0x002089f4 */
/* @0x1379d4 .word 0xffffd5ec */
/* @0x1379d8 .word 0x002089f4 */
/* @0x1379dc .word 0xffffd5f0 */
/* @0x1379e0 .word 0x002089f0 */
/* @0x1379e4 .word 0xffffd5f4 */
/* @0x1379e8 .word 0x002089f0 */
/* @0x1379ec .word 0xffffd5f8 */
/* @0x1379f0 .word 0x002089f0 */
/* @0x1379f4 .word 0xffffd5fc */
/* @0x1379f8 eoreq r8, r0, r12, ror #19 */
/* @0x1379fc .word 0xffffd600 */
/* @0x137a00 eoreq r8, r0, r8, ror #19 */
/* @0x137a04 .word 0xffffd604 */
/* @0x137a08 eoreq r8, r0, r4, ror #19 */
/* @0x137a0c .word 0xffffd608 */
/* @0x137a10 eoreq r8, r0, r0, ror #19 */
/* @0x137a14 .word 0xffffd60c */
/* @0x137a18 eoreq r8, r0, r4, ror #19 */
/* @0x137a1c .word 0xffffd610 */
/* @0x137a20 eoreq r8, r0, r0, ror #19 */
/* @0x137a24 .word 0xffffd614 */
/* @0x137a28 eoreq r8, r0, r0, ror #19 */
/* @0x137a2c .word 0xffffd618 */
/* @0x137a30 .word 0x002089d8 */
/* @0x137a34 .word 0xffffd61c */
/* @0x137a38 .word 0x002089d4 */

/* ── FUNC 0x137a3c · F_DirectoryCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x137a3c push {r4, r5, r6, r7, lr} */
/* @0x137a40 sub sp, sp, #1024 */
/* @0x137a44 ldr r5, [pc, #0x7c] */
/* @0x137a48 sub sp, sp, #12 */
/* @0x137a4c mov r4, r0 */
/* @0x137a50 mov r1, #0 */
/* @0x137a54 ldr r5, [pc, r5] */
/* @0x137a58 ldr r0, [sp, #0x420] */
/* @0x137a5c mov r6, r1 */
/* @0x137a60 add r7, sp, #4 */
/* @0x137a64 ldr r3, [r5] */
/* @0x137a68 str r3, [sp, #0x404] */
/* @0x137a6c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x137a70 mov r1, #1024 */
/* @0x137a74 str r6, [r4, #0xc] */
/* @0x137a78 str r6, [r4] */
/* @0x137a7c str r6, [r4, #0x4] */
/* @0x137a80 mov r2, r0 */
/* @0x137a84 mov r0, r7 */
/* @0x137a88 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x137a8c mov r0, r7 */
/* @0x137a90 bl 0x2150b4 <_Z16ForceDirectoriesPKc> */
/* @0x137a94 ldr r2, [sp, #0x404] */
/* @0x137a98 cmp r0, r6 */
/* @0x137a9c strne r6, [r4] */
/* @0x137aa0 movne r3, r6 */
/* @0x137aa4 movtne r3, #0x3ff0 */
/* @0x137aa8 strne r3, [r4, #0x4] */
/* @0x137aac ldr r3, [r5] */
/* @0x137ab0 cmp r2, r3 */
/* @0x137ab4 bne 0x137ac4 <_Z17F_DirectoryCreateR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x137ab8 add sp, sp, #1024 */
/* @0x137abc add sp, sp, #12 */
/* @0x137ac0 pop {r4, r5, r6, r7, pc} */
/* @0x137ac4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x137ac8 .word 0x002b5efc */
