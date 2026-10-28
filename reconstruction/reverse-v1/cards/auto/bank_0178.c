/* libyoyo.so 覆盖卡组 0178
 * 函数 0x1fbd38..0x1fc7d8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1fbd38 · SV_Friction(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fbd38 ldr r3, [r2, #0xc] */
/* @0x1fbd3c push {r4, lr} */
/* @0x1fbd40 bic r3, r3, #-16777216 */
/* @0x1fbd44 cmp r3, #0 */
/* @0x1fbd48 mov r4, r0 */
/* @0x1fbd4c bne 0x1fbd68 <_Z11SV_FrictionP9CInstanceiP6RValue+0x30> */
/* @0x1fbd50 ldm r2, {r0, r1} */
/* @0x1fbd54 vmov d6, r0, r1 */
/* @0x1fbd58 mov r0, #1 */
/* @0x1fbd5c vcvt.f32.f64 s15, d6 */
/* @0x1fbd60 vstr s15, [r4, #212] */
/* @0x1fbd64 pop {r4, pc} */
/* @0x1fbd68 mov r0, r2 */
/* @0x1fbd6c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbd70 b 0x1fbd54 <_Z11SV_FrictionP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbd74 · SV_Gravity(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fbd74 ldr r3, [r2, #0xc] */
/* @0x1fbd78 push {r4, lr} */
/* @0x1fbd7c bic r3, r3, #-16777216 */
/* @0x1fbd80 cmp r3, #0 */
/* @0x1fbd84 mov r4, r0 */
/* @0x1fbd88 bne 0x1fbda4 <_Z10SV_GravityP9CInstanceiP6RValue+0x30> */
/* @0x1fbd8c ldm r2, {r0, r1} */
/* @0x1fbd90 vmov d6, r0, r1 */
/* @0x1fbd94 mov r0, #1 */
/* @0x1fbd98 vcvt.f32.f64 s15, d6 */
/* @0x1fbd9c vstr s15, [r4, #220] */
/* @0x1fbda0 pop {r4, pc} */
/* @0x1fbda4 mov r0, r2 */
/* @0x1fbda8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbdac b 0x1fbd90 <_Z10SV_GravityP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbdb0 · SV_GravityDir(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fbdb0 ldr r3, [r2, #0xc] */
/* @0x1fbdb4 push {r4, lr} */
/* @0x1fbdb8 bic r3, r3, #-16777216 */
/* @0x1fbdbc cmp r3, #0 */
/* @0x1fbdc0 mov r4, r0 */
/* @0x1fbdc4 bne 0x1fbde0 <_Z13SV_GravityDirP9CInstanceiP6RValue+0x30> */
/* @0x1fbdc8 ldm r2, {r0, r1} */
/* @0x1fbdcc vmov d6, r0, r1 */
/* @0x1fbdd0 mov r0, #1 */
/* @0x1fbdd4 vcvt.f32.f64 s15, d6 */
/* @0x1fbdd8 vstr s15, [r4, #216] */
/* @0x1fbddc pop {r4, pc} */
/* @0x1fbde0 mov r0, r2 */
/* @0x1fbde4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbde8 b 0x1fbdcc <_Z13SV_GravityDirP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbdec · SV_Visible(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1fbdec ldr r3, [r2, #0xc] */
/* @0x1fbdf0 push {r4, lr} */
/* @0x1fbdf4 bic r3, r3, #-16777216 */
/* @0x1fbdf8 cmp r3, #0 */
/* @0x1fbdfc mov r4, r0 */
/* @0x1fbe00 bne 0x1fbe30 <_Z10SV_VisibleP9CInstanceiP6RValue+0x44> */
/* @0x1fbe04 ldm r2, {r0, r1} */
/* @0x1fbe08 vmov d6, r0, r1 */
/* @0x1fbe0c vcvt.f32.f64 s15, d6 */
/* @0x1fbe10 vcvt.f64.f32 d6, s15 */
/* @0x1fbe14 vmov r0, r1, d6 */
/* @0x1fbe18 bl 0xb66e8 <lrint@plt> */
/* @0x1fbe1c adds r3, r0, #0 */
/* @0x1fbe20 mov r0, #1 */
/* @0x1fbe24 movne r3, #1 */
/* @0x1fbe28 strb r3, [r4, #0x65] */
/* @0x1fbe2c pop {r4, pc} */
/* @0x1fbe30 mov r0, r2 */
/* @0x1fbe34 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbe38 b 0x1fbe08 <_Z10SV_VisibleP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbe3c · SV_Solid(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1fbe3c ldr r3, [r2, #0xc] */
/* @0x1fbe40 push {r4, lr} */
/* @0x1fbe44 bic r3, r3, #-16777216 */
/* @0x1fbe48 cmp r3, #0 */
/* @0x1fbe4c mov r4, r0 */
/* @0x1fbe50 bne 0x1fbe80 <_Z8SV_SolidP9CInstanceiP6RValue+0x44> */
/* @0x1fbe54 ldm r2, {r0, r1} */
/* @0x1fbe58 vmov d6, r0, r1 */
/* @0x1fbe5c vcvt.f32.f64 s15, d6 */
/* @0x1fbe60 vcvt.f64.f32 d6, s15 */
/* @0x1fbe64 vmov r0, r1, d6 */
/* @0x1fbe68 bl 0xb66e8 <lrint@plt> */
/* @0x1fbe6c adds r3, r0, #0 */
/* @0x1fbe70 mov r0, #1 */
/* @0x1fbe74 movne r3, #1 */
/* @0x1fbe78 strb r3, [r4, #0x66] */
/* @0x1fbe7c pop {r4, pc} */
/* @0x1fbe80 mov r0, r2 */
/* @0x1fbe84 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbe88 b 0x1fbe58 <_Z8SV_SolidP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbe8c · SV_Persistent(CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1fbe8c ldr r3, [r2, #0xc] */
/* @0x1fbe90 push {r4, lr} */
/* @0x1fbe94 bic r3, r3, #-16777216 */
/* @0x1fbe98 cmp r3, #0 */
/* @0x1fbe9c mov r4, r0 */
/* @0x1fbea0 bne 0x1fbed0 <_Z13SV_PersistentP9CInstanceiP6RValue+0x44> */
/* @0x1fbea4 ldm r2, {r0, r1} */
/* @0x1fbea8 vmov d6, r0, r1 */
/* @0x1fbeac vcvt.f32.f64 s15, d6 */
/* @0x1fbeb0 vcvt.f64.f32 d6, s15 */
/* @0x1fbeb4 vmov r0, r1, d6 */
/* @0x1fbeb8 bl 0xb66e8 <lrint@plt> */
/* @0x1fbebc adds r3, r0, #0 */
/* @0x1fbec0 mov r0, #1 */
/* @0x1fbec4 movne r3, #1 */
/* @0x1fbec8 strb r3, [r4, #0x67] */
/* @0x1fbecc pop {r4, pc} */
/* @0x1fbed0 mov r0, r2 */
/* @0x1fbed4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbed8 b 0x1fbea8 <_Z13SV_PersistentP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbedc · SV_PathScale(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fbedc ldr r3, [r2, #0xc] */
/* @0x1fbee0 push {r4, lr} */
/* @0x1fbee4 bic r3, r3, #-16777216 */
/* @0x1fbee8 cmp r3, #0 */
/* @0x1fbeec mov r4, r0 */
/* @0x1fbef0 bne 0x1fbf0c <_Z12SV_PathScaleP9CInstanceiP6RValue+0x30> */
/* @0x1fbef4 ldm r2, {r0, r1} */
/* @0x1fbef8 vmov d6, r0, r1 */
/* @0x1fbefc mov r0, #1 */
/* @0x1fbf00 vcvt.f32.f64 s15, d6 */
/* @0x1fbf04 vstr s15, [r4, #312] */
/* @0x1fbf08 pop {r4, pc} */
/* @0x1fbf0c mov r0, r2 */
/* @0x1fbf10 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbf14 b 0x1fbef8 <_Z12SV_PathScaleP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbf18 · SV_PathOrientation(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fbf18 ldr r3, [r2, #0xc] */
/* @0x1fbf1c push {r4, lr} */
/* @0x1fbf20 bic r3, r3, #-16777216 */
/* @0x1fbf24 cmp r3, #0 */
/* @0x1fbf28 mov r4, r0 */
/* @0x1fbf2c bne 0x1fbf48 <_Z18SV_PathOrientationP9CInstanceiP6RValue+0x30> */
/* @0x1fbf30 ldm r2, {r0, r1} */
/* @0x1fbf34 vmov d6, r0, r1 */
/* @0x1fbf38 mov r0, #1 */
/* @0x1fbf3c vcvt.f32.f64 s15, d6 */
/* @0x1fbf40 vstr s15, [r4, #316] */
/* @0x1fbf44 pop {r4, pc} */
/* @0x1fbf48 mov r0, r2 */
/* @0x1fbf4c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbf50 b 0x1fbf34 <_Z18SV_PathOrientationP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbf54 · SV_PathEndAction(CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1fbf54 ldr r3, [r2, #0xc] */
/* @0x1fbf58 push {r4, lr} */
/* @0x1fbf5c bic r3, r3, #-16777216 */
/* @0x1fbf60 cmp r3, #0 */
/* @0x1fbf64 mov r4, r0 */
/* @0x1fbf68 bne 0x1fbf90 <_Z16SV_PathEndActionP9CInstanceiP6RValue+0x3c> */
/* @0x1fbf6c ldm r2, {r0, r1} */
/* @0x1fbf70 vmov d6, r0, r1 */
/* @0x1fbf74 vcvt.f32.f64 s15, d6 */
/* @0x1fbf78 vcvt.f64.f32 d6, s15 */
/* @0x1fbf7c vmov r0, r1, d6 */
/* @0x1fbf80 bl 0xb66e8 <lrint@plt> */
/* @0x1fbf84 str r0, [r4, #0x140] */
/* @0x1fbf88 mov r0, #1 */
/* @0x1fbf8c pop {r4, pc} */
/* @0x1fbf90 mov r0, r2 */
/* @0x1fbf94 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbf98 b 0x1fbf70 <_Z16SV_PathEndActionP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbf9c · SV_TimelineIndex(CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1fbf9c ldr r3, [r2, #0xc] */
/* @0x1fbfa0 push {r4, lr} */
/* @0x1fbfa4 bic r3, r3, #-16777216 */
/* @0x1fbfa8 cmp r3, #0 */
/* @0x1fbfac mov r4, r0 */
/* @0x1fbfb0 bne 0x1fbfd8 <_Z16SV_TimelineIndexP9CInstanceiP6RValue+0x3c> */
/* @0x1fbfb4 ldm r2, {r0, r1} */
/* @0x1fbfb8 vmov d6, r0, r1 */
/* @0x1fbfbc vcvt.f32.f64 s15, d6 */
/* @0x1fbfc0 vcvt.f64.f32 d6, s15 */
/* @0x1fbfc4 vmov r0, r1, d6 */
/* @0x1fbfc8 bl 0xb66e8 <lrint@plt> */
/* @0x1fbfcc str r0, [r4, #0x14c] */
/* @0x1fbfd0 mov r0, #1 */
/* @0x1fbfd4 pop {r4, pc} */
/* @0x1fbfd8 mov r0, r2 */
/* @0x1fbfdc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fbfe0 b 0x1fbfb8 <_Z16SV_TimelineIndexP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fbfe4 · SV_TimelinePosition(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fbfe4 ldr r3, [r2, #0xc] */
/* @0x1fbfe8 push {r4, lr} */
/* @0x1fbfec bic r3, r3, #-16777216 */
/* @0x1fbff0 cmp r3, #0 */
/* @0x1fbff4 mov r4, r0 */
/* @0x1fbff8 bne 0x1fc014 <_Z19SV_TimelinePositionP9CInstanceiP6RValue+0x30> */
/* @0x1fbffc ldm r2, {r0, r1} */
/* @0x1fc000 vmov d6, r0, r1 */
/* @0x1fc004 mov r0, #1 */
/* @0x1fc008 vcvt.f32.f64 s15, d6 */
/* @0x1fc00c vstr s15, [r4, #340] */
/* @0x1fc010 pop {r4, pc} */
/* @0x1fc014 mov r0, r2 */
/* @0x1fc018 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc01c b 0x1fc000 <_Z19SV_TimelinePositionP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fc020 · SV_TimelineSpeed(CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1fc020 ldr r3, [r2, #0xc] */
/* @0x1fc024 push {r4, lr} */
/* @0x1fc028 bic r3, r3, #-16777216 */
/* @0x1fc02c cmp r3, #0 */
/* @0x1fc030 mov r4, r0 */
/* @0x1fc034 bne 0x1fc050 <_Z16SV_TimelineSpeedP9CInstanceiP6RValue+0x30> */
/* @0x1fc038 ldm r2, {r0, r1} */
/* @0x1fc03c vmov d6, r0, r1 */
/* @0x1fc040 mov r0, #1 */
/* @0x1fc044 vcvt.f32.f64 s15, d6 */
/* @0x1fc048 vstr s15, [r4, #344] */
/* @0x1fc04c pop {r4, pc} */
/* @0x1fc050 mov r0, r2 */
/* @0x1fc054 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc058 b 0x1fc03c <_Z16SV_TimelineSpeedP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fc05c · SV_TimelineRunning(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1fc05c ldr r3, [r2, #0xc] */
/* @0x1fc060 push {r4, lr} */
/* @0x1fc064 bic r3, r3, #-16777216 */
/* @0x1fc068 cmp r3, #0 */
/* @0x1fc06c mov r4, r0 */
/* @0x1fc070 bne 0x1fc0a4 <_Z18SV_TimelineRunningP9CInstanceiP6RValue+0x48> */
/* @0x1fc074 ldm r2, {r0, r1} */
/* @0x1fc078 bl 0xb66e8 <lrint@plt> */
/* @0x1fc07c vmov.f64 d7, #5.000000e-01 */
/* @0x1fc080 vmov s11, r0 */
/* @0x1fc084 mov r0, #1 */
/* @0x1fc088 vcvt.f64.s32 d6, s11 */
/* @0x1fc08c vcmpe.f64 d6, d7 */
/* @0x1fc090 vmrs APSR_nzcv, fpscr */
/* @0x1fc094 movle r3, #0 */
/* @0x1fc098 movgt r3, #1 */
/* @0x1fc09c strb r3, [r4, #0x15c] */
/* @0x1fc0a0 pop {r4, pc} */
/* @0x1fc0a4 mov r0, r2 */
/* @0x1fc0a8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc0ac b 0x1fc078 <_Z18SV_TimelineRunningP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fc0b0 · SV_TimelineLoop(CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1fc0b0 ldr r3, [r2, #0xc] */
/* @0x1fc0b4 push {r4, lr} */
/* @0x1fc0b8 bic r3, r3, #-16777216 */
/* @0x1fc0bc cmp r3, #0 */
/* @0x1fc0c0 mov r4, r0 */
/* @0x1fc0c4 bne 0x1fc0f8 <_Z15SV_TimelineLoopP9CInstanceiP6RValue+0x48> */
/* @0x1fc0c8 ldm r2, {r0, r1} */
/* @0x1fc0cc bl 0xb66e8 <lrint@plt> */
/* @0x1fc0d0 vmov.f64 d7, #5.000000e-01 */
/* @0x1fc0d4 vmov s11, r0 */
/* @0x1fc0d8 mov r0, #1 */
/* @0x1fc0dc vcvt.f64.s32 d6, s11 */
/* @0x1fc0e0 vcmpe.f64 d6, d7 */
/* @0x1fc0e4 vmrs APSR_nzcv, fpscr */
/* @0x1fc0e8 movle r3, #0 */
/* @0x1fc0ec movgt r3, #1 */
/* @0x1fc0f0 strb r3, [r4, #0x15d] */
/* @0x1fc0f4 pop {r4, pc} */
/* @0x1fc0f8 mov r0, r2 */
/* @0x1fc0fc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc100 b 0x1fc0cc <_Z15SV_TimelineLoopP9CInstanceiP6RValue+0x1c> */

/* ── FUNC 0x1fc104 · SV_ImageBlend(CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1fc104 ldr r3, [pc, #0x68] */
/* @0x1fc108 push {r4, lr} */
/* @0x1fc10c ldr r3, [pc, r3] */
/* @0x1fc110 mov r4, r0 */
/* @0x1fc114 ldrb r1, [r3] */
/* @0x1fc118 cmp r1, #0 */
/* @0x1fc11c beq 0x1fc160 <_Z13SV_ImageBlendP9CInstanceiP6RValue+0x5c> */
/* @0x1fc120 ldr r3, [r2, #0xc] */
/* @0x1fc124 bic r3, r3, #-16777216 */
/* @0x1fc128 cmp r3, #0 */
/* @0x1fc12c bne 0x1fc154 <_Z13SV_ImageBlendP9CInstanceiP6RValue+0x50> */
/* @0x1fc130 ldm r2, {r0, r1} */
/* @0x1fc134 vmov d6, r0, r1 */
/* @0x1fc138 vcvt.f32.f64 s15, d6 */
/* @0x1fc13c vcvt.f64.f32 d6, s15 */
/* @0x1fc140 vmov r0, r1, d6 */
/* @0x1fc144 bl 0xb66e8 <lrint@plt> */
/* @0x1fc148 str r0, [r4, #0xa8] */
/* @0x1fc14c mov r0, #1 */
/* @0x1fc150 pop {r4, pc} */
/* @0x1fc154 mov r0, r2 */
/* @0x1fc158 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc15c b 0x1fc134 <_Z13SV_ImageBlendP9CInstanceiP6RValue+0x30> */
/* @0x1fc160 ldr r0, [pc, #0x10] */
/* @0x1fc164 add r0, pc, r0 */
/* @0x1fc168 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1fc16c mov r0, #1 */
/* @0x1fc170 pop {r4, pc} */
/* @0x1fc174 ldrheq r4, [pc], -r0 */
/* @0x1fc178 andseq r6, r5, r8, asr r8 */

/* ── FUNC 0x1fc17c · SV_Layer(CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1fc17c push {r4, r5, r6, lr} */
/* @0x1fc180 mov r1, r0 */
/* @0x1fc184 ldr r4, [pc, #0x64] */
/* @0x1fc188 mov r6, r2 */
/* @0x1fc18c mov r5, r0 */
/* @0x1fc190 ldr r4, [pc, r4] */
/* @0x1fc194 ldr r0, [r4] */
/* @0x1fc198 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> */
/* @0x1fc19c ldr r3, [r6, #0xc] */
/* @0x1fc1a0 bic r3, r3, #-16777216 */
/* @0x1fc1a4 cmp r3, #0 */
/* @0x1fc1a8 bne 0x1fc1e4 <_Z8SV_LayerP9CInstanceiP6RValue+0x68> */
/* @0x1fc1ac ldm r6, {r0, r1} */
/* @0x1fc1b0 vmov d7, r0, r1 */
/* @0x1fc1b4 ldr r0, [r4] */
/* @0x1fc1b8 vcvt.s32.f64 s15, d7 */
/* @0x1fc1bc vmov r1, s15 */
/* @0x1fc1c0 vstr s15, [r5, #368] */
/* @0x1fc1c4 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1fc1c8 subs r1, r0, #0 */
/* @0x1fc1cc beq 0x1fc1dc <_Z8SV_LayerP9CInstanceiP6RValue+0x60> */
/* @0x1fc1d0 ldr r0, [r4] */
/* @0x1fc1d4 mov r2, r5 */
/* @0x1fc1d8 bl 0x1c5a38 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance> */
/* @0x1fc1dc mov r0, #1 */
/* @0x1fc1e0 pop {r4, r5, r6, pc} */
/* @0x1fc1e4 mov r0, r6 */
/* @0x1fc1e8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc1ec b 0x1fc1b0 <_Z8SV_LayerP9CInstanceiP6RValue+0x34> */
/* @0x1fc1f0 mulseq pc, r8, r7 */

/* ── FUNC 0x1fc1f4 · SV_ViewVisible(CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x1fc1f4 ldr r3, [pc, #0x78] */
/* @0x1fc1f8 cmp r1, #7 */
/* @0x1fc1fc ldr r0, [r2, #0xc] */
/* @0x1fc200 ldr r3, [pc, r3] */
/* @0x1fc204 movhi r1, #0 */
/* @0x1fc208 bic r0, r0, #-16777216 */
/* @0x1fc20c add r1, r1, #18 */
/* @0x1fc210 ldr r3, [r3] */
/* @0x1fc214 cmp r0, #0 */
/* @0x1fc218 push {r4, lr} */
/* @0x1fc21c ldr r4, [r3, r1, lsl #2] */
/* @0x1fc220 bne 0x1fc260 <_Z14SV_ViewVisibleP9CInstanceiP6RValue+0x6c> */
/* @0x1fc224 ldr r12, [r2] */
/* @0x1fc228 ldr r3, [r2, #0x4] */
/* @0x1fc22c mov r1, r3 */
/* @0x1fc230 mov r0, r12 */
/* @0x1fc234 bl 0xb66e8 <lrint@plt> */
/* @0x1fc238 vmov.f64 d7, #5.000000e-01 */
/* @0x1fc23c vmov s11, r0 */
/* @0x1fc240 mov r0, #1 */
/* @0x1fc244 vcvt.f64.s32 d6, s11 */
/* @0x1fc248 vcmpe.f64 d6, d7 */
/* @0x1fc24c vmrs APSR_nzcv, fpscr */
/* @0x1fc250 movle r3, #0 */
/* @0x1fc254 movgt r3, #1 */
/* @0x1fc258 strb r3, [r4] */
/* @0x1fc25c pop {r4, pc} */
/* @0x1fc260 mov r0, r2 */
/* @0x1fc264 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc268 mov r12, r0 */
/* @0x1fc26c mov r3, r1 */
/* @0x1fc270 b 0x1fc22c <_Z14SV_ViewVisibleP9CInstanceiP6RValue+0x38> */
/* @0x1fc274 andseq r1, pc, r8, lsr #14 */

/* ── FUNC 0x1fc278 · SV_ViewXview(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fc278 ldr r3, [pc, #0x4c] */
/* @0x1fc27c cmp r1, #7 */
/* @0x1fc280 ldr r0, [r2, #0xc] */
/* @0x1fc284 ldr r3, [pc, r3] */
/* @0x1fc288 movhi r1, #0 */
/* @0x1fc28c bic r0, r0, #-16777216 */
/* @0x1fc290 add r1, r1, #18 */
/* @0x1fc294 ldr r3, [r3] */
/* @0x1fc298 cmp r0, #0 */
/* @0x1fc29c push {r4, lr} */
/* @0x1fc2a0 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc2a4 bne 0x1fc2c0 <_Z12SV_ViewXviewP9CInstanceiP6RValue+0x48> */
/* @0x1fc2a8 ldm r2, {r0, r1} */
/* @0x1fc2ac vmov d6, r0, r1 */
/* @0x1fc2b0 mov r0, #1 */
/* @0x1fc2b4 vcvt.f32.f64 s15, d6 */
/* @0x1fc2b8 vstr s15, [r4, #4] */
/* @0x1fc2bc pop {r4, pc} */
/* @0x1fc2c0 mov r0, r2 */
/* @0x1fc2c4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc2c8 b 0x1fc2ac <_Z12SV_ViewXviewP9CInstanceiP6RValue+0x34> */
/* @0x1fc2cc andseq r1, pc, r4, lsr #13 */

/* ── FUNC 0x1fc2d0 · SV_ViewYview(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fc2d0 ldr r3, [pc, #0x4c] */
/* @0x1fc2d4 cmp r1, #7 */
/* @0x1fc2d8 ldr r0, [r2, #0xc] */
/* @0x1fc2dc ldr r3, [pc, r3] */
/* @0x1fc2e0 movhi r1, #0 */
/* @0x1fc2e4 bic r0, r0, #-16777216 */
/* @0x1fc2e8 add r1, r1, #18 */
/* @0x1fc2ec ldr r3, [r3] */
/* @0x1fc2f0 cmp r0, #0 */
/* @0x1fc2f4 push {r4, lr} */
/* @0x1fc2f8 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc2fc bne 0x1fc318 <_Z12SV_ViewYviewP9CInstanceiP6RValue+0x48> */
/* @0x1fc300 ldm r2, {r0, r1} */
/* @0x1fc304 vmov d6, r0, r1 */
/* @0x1fc308 mov r0, #1 */
/* @0x1fc30c vcvt.f32.f64 s15, d6 */
/* @0x1fc310 vstr s15, [r4, #8] */
/* @0x1fc314 pop {r4, pc} */
/* @0x1fc318 mov r0, r2 */
/* @0x1fc31c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc320 b 0x1fc304 <_Z12SV_ViewYviewP9CInstanceiP6RValue+0x34> */
/* @0x1fc324 andseq r1, pc, r12, asr #12 */

/* ── FUNC 0x1fc328 · SV_ViewWview(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fc328 ldr r3, [pc, #0x4c] */
/* @0x1fc32c cmp r1, #7 */
/* @0x1fc330 ldr r0, [r2, #0xc] */
/* @0x1fc334 ldr r3, [pc, r3] */
/* @0x1fc338 movhi r1, #0 */
/* @0x1fc33c bic r0, r0, #-16777216 */
/* @0x1fc340 add r1, r1, #18 */
/* @0x1fc344 ldr r3, [r3] */
/* @0x1fc348 cmp r0, #0 */
/* @0x1fc34c push {r4, lr} */
/* @0x1fc350 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc354 bne 0x1fc370 <_Z12SV_ViewWviewP9CInstanceiP6RValue+0x48> */
/* @0x1fc358 ldm r2, {r0, r1} */
/* @0x1fc35c vmov d6, r0, r1 */
/* @0x1fc360 mov r0, #1 */
/* @0x1fc364 vcvt.f32.f64 s15, d6 */
/* @0x1fc368 vstr s15, [r4, #12] */
/* @0x1fc36c pop {r4, pc} */
/* @0x1fc370 mov r0, r2 */
/* @0x1fc374 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc378 b 0x1fc35c <_Z12SV_ViewWviewP9CInstanceiP6RValue+0x34> */
/* @0x1fc37c ldrsheq r1, [pc], -r4 */

/* ── FUNC 0x1fc380 · SV_ViewHview(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fc380 ldr r3, [pc, #0x4c] */
/* @0x1fc384 cmp r1, #7 */
/* @0x1fc388 ldr r0, [r2, #0xc] */
/* @0x1fc38c ldr r3, [pc, r3] */
/* @0x1fc390 movhi r1, #0 */
/* @0x1fc394 bic r0, r0, #-16777216 */
/* @0x1fc398 add r1, r1, #18 */
/* @0x1fc39c ldr r3, [r3] */
/* @0x1fc3a0 cmp r0, #0 */
/* @0x1fc3a4 push {r4, lr} */
/* @0x1fc3a8 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc3ac bne 0x1fc3c8 <_Z12SV_ViewHviewP9CInstanceiP6RValue+0x48> */
/* @0x1fc3b0 ldm r2, {r0, r1} */
/* @0x1fc3b4 vmov d6, r0, r1 */
/* @0x1fc3b8 mov r0, #1 */
/* @0x1fc3bc vcvt.f32.f64 s15, d6 */
/* @0x1fc3c0 vstr s15, [r4, #16] */
/* @0x1fc3c4 pop {r4, pc} */
/* @0x1fc3c8 mov r0, r2 */
/* @0x1fc3cc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc3d0 b 0x1fc3b4 <_Z12SV_ViewHviewP9CInstanceiP6RValue+0x34> */
/* @0x1fc3d4 mulseq pc, r12, r5 */

/* ── FUNC 0x1fc3d8 · SV_ViewXport(CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1fc3d8 ldr r3, [pc, #0x5c] */
/* @0x1fc3dc cmp r1, #7 */
/* @0x1fc3e0 ldr r0, [r2, #0xc] */
/* @0x1fc3e4 ldr r3, [pc, r3] */
/* @0x1fc3e8 movhi r1, #0 */
/* @0x1fc3ec bic r0, r0, #-16777216 */
/* @0x1fc3f0 add r1, r1, #18 */
/* @0x1fc3f4 ldr r3, [r3] */
/* @0x1fc3f8 cmp r0, #0 */
/* @0x1fc3fc push {r4, lr} */
/* @0x1fc400 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc404 bne 0x1fc428 <_Z12SV_ViewXportP9CInstanceiP6RValue+0x50> */
/* @0x1fc408 ldr r12, [r2] */
/* @0x1fc40c ldr r3, [r2, #0x4] */
/* @0x1fc410 mov r0, r12 */
/* @0x1fc414 mov r1, r3 */
/* @0x1fc418 bl 0xb66e8 <lrint@plt> */
/* @0x1fc41c str r0, [r4, #0x14] */
/* @0x1fc420 mov r0, #1 */
/* @0x1fc424 pop {r4, pc} */
/* @0x1fc428 mov r0, r2 */
/* @0x1fc42c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc430 mov r12, r0 */
/* @0x1fc434 mov r3, r1 */
/* @0x1fc438 b 0x1fc410 <_Z12SV_ViewXportP9CInstanceiP6RValue+0x38> */
/* @0x1fc43c andseq r1, pc, r4, asr #10 */

/* ── FUNC 0x1fc440 · SV_ViewYport(CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1fc440 ldr r3, [pc, #0x5c] */
/* @0x1fc444 cmp r1, #7 */
/* @0x1fc448 ldr r0, [r2, #0xc] */
/* @0x1fc44c ldr r3, [pc, r3] */
/* @0x1fc450 movhi r1, #0 */
/* @0x1fc454 bic r0, r0, #-16777216 */
/* @0x1fc458 add r1, r1, #18 */
/* @0x1fc45c ldr r3, [r3] */
/* @0x1fc460 cmp r0, #0 */
/* @0x1fc464 push {r4, lr} */
/* @0x1fc468 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc46c bne 0x1fc490 <_Z12SV_ViewYportP9CInstanceiP6RValue+0x50> */
/* @0x1fc470 ldr r12, [r2] */
/* @0x1fc474 ldr r3, [r2, #0x4] */
/* @0x1fc478 mov r0, r12 */
/* @0x1fc47c mov r1, r3 */
/* @0x1fc480 bl 0xb66e8 <lrint@plt> */
/* @0x1fc484 str r0, [r4, #0x18] */
/* @0x1fc488 mov r0, #1 */
/* @0x1fc48c pop {r4, pc} */
/* @0x1fc490 mov r0, r2 */
/* @0x1fc494 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc498 mov r12, r0 */
/* @0x1fc49c mov r3, r1 */
/* @0x1fc4a0 b 0x1fc478 <_Z12SV_ViewYportP9CInstanceiP6RValue+0x38> */
/* @0x1fc4a4 ldrsbeq r1, [pc], -r12 */

/* ── FUNC 0x1fc4a8 · SV_ViewWport(CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1fc4a8 ldr r3, [pc, #0x5c] */
/* @0x1fc4ac cmp r1, #7 */
/* @0x1fc4b0 ldr r0, [r2, #0xc] */
/* @0x1fc4b4 ldr r3, [pc, r3] */
/* @0x1fc4b8 movhi r1, #0 */
/* @0x1fc4bc bic r0, r0, #-16777216 */
/* @0x1fc4c0 add r1, r1, #18 */
/* @0x1fc4c4 ldr r3, [r3] */
/* @0x1fc4c8 cmp r0, #0 */
/* @0x1fc4cc push {r4, lr} */
/* @0x1fc4d0 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc4d4 bne 0x1fc4f8 <_Z12SV_ViewWportP9CInstanceiP6RValue+0x50> */
/* @0x1fc4d8 ldr r12, [r2] */
/* @0x1fc4dc ldr r3, [r2, #0x4] */
/* @0x1fc4e0 mov r0, r12 */
/* @0x1fc4e4 mov r1, r3 */
/* @0x1fc4e8 bl 0xb66e8 <lrint@plt> */
/* @0x1fc4ec str r0, [r4, #0x1c] */
/* @0x1fc4f0 mov r0, #1 */
/* @0x1fc4f4 pop {r4, pc} */
/* @0x1fc4f8 mov r0, r2 */
/* @0x1fc4fc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc500 mov r12, r0 */
/* @0x1fc504 mov r3, r1 */
/* @0x1fc508 b 0x1fc4e0 <_Z12SV_ViewWportP9CInstanceiP6RValue+0x38> */
/* @0x1fc50c andseq r1, pc, r4, ror r4 */

/* ── FUNC 0x1fc510 · SV_ViewHport(CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1fc510 ldr r3, [pc, #0x5c] */
/* @0x1fc514 cmp r1, #7 */
/* @0x1fc518 ldr r0, [r2, #0xc] */
/* @0x1fc51c ldr r3, [pc, r3] */
/* @0x1fc520 movhi r1, #0 */
/* @0x1fc524 bic r0, r0, #-16777216 */
/* @0x1fc528 add r1, r1, #18 */
/* @0x1fc52c ldr r3, [r3] */
/* @0x1fc530 cmp r0, #0 */
/* @0x1fc534 push {r4, lr} */
/* @0x1fc538 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc53c bne 0x1fc560 <_Z12SV_ViewHportP9CInstanceiP6RValue+0x50> */
/* @0x1fc540 ldr r12, [r2] */
/* @0x1fc544 ldr r3, [r2, #0x4] */
/* @0x1fc548 mov r0, r12 */
/* @0x1fc54c mov r1, r3 */
/* @0x1fc550 bl 0xb66e8 <lrint@plt> */
/* @0x1fc554 str r0, [r4, #0x20] */
/* @0x1fc558 mov r0, #1 */
/* @0x1fc55c pop {r4, pc} */
/* @0x1fc560 mov r0, r2 */
/* @0x1fc564 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc568 mov r12, r0 */
/* @0x1fc56c mov r3, r1 */
/* @0x1fc570 b 0x1fc548 <_Z12SV_ViewHportP9CInstanceiP6RValue+0x38> */
/* @0x1fc574 andseq r1, pc, r12, lsl #8 */

/* ── FUNC 0x1fc578 · SV_ViewAngle(CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1fc578 ldr r3, [pc, #0x4c] */
/* @0x1fc57c cmp r1, #7 */
/* @0x1fc580 ldr r0, [r2, #0xc] */
/* @0x1fc584 ldr r3, [pc, r3] */
/* @0x1fc588 movhi r1, #0 */
/* @0x1fc58c bic r0, r0, #-16777216 */
/* @0x1fc590 add r1, r1, #18 */
/* @0x1fc594 ldr r3, [r3] */
/* @0x1fc598 cmp r0, #0 */
/* @0x1fc59c push {r4, lr} */
/* @0x1fc5a0 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc5a4 bne 0x1fc5c0 <_Z12SV_ViewAngleP9CInstanceiP6RValue+0x48> */
/* @0x1fc5a8 ldm r2, {r0, r1} */
/* @0x1fc5ac vmov d6, r0, r1 */
/* @0x1fc5b0 mov r0, #1 */
/* @0x1fc5b4 vcvt.f32.f64 s15, d6 */
/* @0x1fc5b8 vstr s15, [r4, #36] */
/* @0x1fc5bc pop {r4, pc} */
/* @0x1fc5c0 mov r0, r2 */
/* @0x1fc5c4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc5c8 b 0x1fc5ac <_Z12SV_ViewAngleP9CInstanceiP6RValue+0x34> */
/* @0x1fc5cc andseq r1, pc, r4, lsr #7 */

/* ── FUNC 0x1fc5d0 · SV_ViewHBorder(CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1fc5d0 ldr r3, [pc, #0x5c] */
/* @0x1fc5d4 cmp r1, #7 */
/* @0x1fc5d8 ldr r0, [r2, #0xc] */
/* @0x1fc5dc ldr r3, [pc, r3] */
/* @0x1fc5e0 movhi r1, #0 */
/* @0x1fc5e4 bic r0, r0, #-16777216 */
/* @0x1fc5e8 add r1, r1, #18 */
/* @0x1fc5ec ldr r3, [r3] */
/* @0x1fc5f0 cmp r0, #0 */
/* @0x1fc5f4 push {r4, lr} */
/* @0x1fc5f8 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc5fc bne 0x1fc620 <_Z14SV_ViewHBorderP9CInstanceiP6RValue+0x50> */
/* @0x1fc600 ldr r12, [r2] */
/* @0x1fc604 ldr r3, [r2, #0x4] */
/* @0x1fc608 mov r0, r12 */
/* @0x1fc60c mov r1, r3 */
/* @0x1fc610 bl 0xb66e8 <lrint@plt> */
/* @0x1fc614 str r0, [r4, #0x28] */
/* @0x1fc618 mov r0, #1 */
/* @0x1fc61c pop {r4, pc} */
/* @0x1fc620 mov r0, r2 */
/* @0x1fc624 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc628 mov r12, r0 */
/* @0x1fc62c mov r3, r1 */
/* @0x1fc630 b 0x1fc608 <_Z14SV_ViewHBorderP9CInstanceiP6RValue+0x38> */
/* @0x1fc634 andseq r1, pc, r12, asr #6 */

/* ── FUNC 0x1fc638 · SV_ViewVBorder(CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1fc638 ldr r3, [pc, #0x5c] */
/* @0x1fc63c cmp r1, #7 */
/* @0x1fc640 ldr r0, [r2, #0xc] */
/* @0x1fc644 ldr r3, [pc, r3] */
/* @0x1fc648 movhi r1, #0 */
/* @0x1fc64c bic r0, r0, #-16777216 */
/* @0x1fc650 add r1, r1, #18 */
/* @0x1fc654 ldr r3, [r3] */
/* @0x1fc658 cmp r0, #0 */
/* @0x1fc65c push {r4, lr} */
/* @0x1fc660 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc664 bne 0x1fc688 <_Z14SV_ViewVBorderP9CInstanceiP6RValue+0x50> */
/* @0x1fc668 ldr r12, [r2] */
/* @0x1fc66c ldr r3, [r2, #0x4] */
/* @0x1fc670 mov r0, r12 */
/* @0x1fc674 mov r1, r3 */
/* @0x1fc678 bl 0xb66e8 <lrint@plt> */
/* @0x1fc67c str r0, [r4, #0x2c] */
/* @0x1fc680 mov r0, #1 */
/* @0x1fc684 pop {r4, pc} */
/* @0x1fc688 mov r0, r2 */
/* @0x1fc68c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc690 mov r12, r0 */
/* @0x1fc694 mov r3, r1 */
/* @0x1fc698 b 0x1fc670 <_Z14SV_ViewVBorderP9CInstanceiP6RValue+0x38> */
/* @0x1fc69c andseq r1, pc, r4, ror #5 */

/* ── FUNC 0x1fc6a0 · SV_ViewHSpeed(CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1fc6a0 ldr r3, [pc, #0x5c] */
/* @0x1fc6a4 cmp r1, #7 */
/* @0x1fc6a8 ldr r0, [r2, #0xc] */
/* @0x1fc6ac ldr r3, [pc, r3] */
/* @0x1fc6b0 movhi r1, #0 */
/* @0x1fc6b4 bic r0, r0, #-16777216 */
/* @0x1fc6b8 add r1, r1, #18 */
/* @0x1fc6bc ldr r3, [r3] */
/* @0x1fc6c0 cmp r0, #0 */
/* @0x1fc6c4 push {r4, lr} */
/* @0x1fc6c8 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc6cc bne 0x1fc6f0 <_Z13SV_ViewHSpeedP9CInstanceiP6RValue+0x50> */
/* @0x1fc6d0 ldr r12, [r2] */
/* @0x1fc6d4 ldr r3, [r2, #0x4] */
/* @0x1fc6d8 mov r0, r12 */
/* @0x1fc6dc mov r1, r3 */
/* @0x1fc6e0 bl 0xb66e8 <lrint@plt> */
/* @0x1fc6e4 str r0, [r4, #0x30] */
/* @0x1fc6e8 mov r0, #1 */
/* @0x1fc6ec pop {r4, pc} */
/* @0x1fc6f0 mov r0, r2 */
/* @0x1fc6f4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc6f8 mov r12, r0 */
/* @0x1fc6fc mov r3, r1 */
/* @0x1fc700 b 0x1fc6d8 <_Z13SV_ViewHSpeedP9CInstanceiP6RValue+0x38> */
/* @0x1fc704 andseq r1, pc, r12, ror r2 */

/* ── FUNC 0x1fc708 · SV_ViewVSpeed(CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1fc708 ldr r3, [pc, #0x5c] */
/* @0x1fc70c cmp r1, #7 */
/* @0x1fc710 ldr r0, [r2, #0xc] */
/* @0x1fc714 ldr r3, [pc, r3] */
/* @0x1fc718 movhi r1, #0 */
/* @0x1fc71c bic r0, r0, #-16777216 */
/* @0x1fc720 add r1, r1, #18 */
/* @0x1fc724 ldr r3, [r3] */
/* @0x1fc728 cmp r0, #0 */
/* @0x1fc72c push {r4, lr} */
/* @0x1fc730 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc734 bne 0x1fc758 <_Z13SV_ViewVSpeedP9CInstanceiP6RValue+0x50> */
/* @0x1fc738 ldr r12, [r2] */
/* @0x1fc73c ldr r3, [r2, #0x4] */
/* @0x1fc740 mov r0, r12 */
/* @0x1fc744 mov r1, r3 */
/* @0x1fc748 bl 0xb66e8 <lrint@plt> */
/* @0x1fc74c str r0, [r4, #0x34] */
/* @0x1fc750 mov r0, #1 */
/* @0x1fc754 pop {r4, pc} */
/* @0x1fc758 mov r0, r2 */
/* @0x1fc75c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc760 mov r12, r0 */
/* @0x1fc764 mov r3, r1 */
/* @0x1fc768 b 0x1fc740 <_Z13SV_ViewVSpeedP9CInstanceiP6RValue+0x38> */
/* @0x1fc76c andseq r1, pc, r4, lsl r2 */

/* ── FUNC 0x1fc770 · SV_ViewObject(CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1fc770 ldr r3, [pc, #0x5c] */
/* @0x1fc774 cmp r1, #7 */
/* @0x1fc778 ldr r0, [r2, #0xc] */
/* @0x1fc77c ldr r3, [pc, r3] */
/* @0x1fc780 movhi r1, #0 */
/* @0x1fc784 bic r0, r0, #-16777216 */
/* @0x1fc788 add r1, r1, #18 */
/* @0x1fc78c ldr r3, [r3] */
/* @0x1fc790 cmp r0, #0 */
/* @0x1fc794 push {r4, lr} */
/* @0x1fc798 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc79c bne 0x1fc7c0 <_Z13SV_ViewObjectP9CInstanceiP6RValue+0x50> */
/* @0x1fc7a0 ldr r12, [r2] */
/* @0x1fc7a4 ldr r3, [r2, #0x4] */
/* @0x1fc7a8 mov r0, r12 */
/* @0x1fc7ac mov r1, r3 */
/* @0x1fc7b0 bl 0xb66e8 <lrint@plt> */
/* @0x1fc7b4 str r0, [r4, #0x38] */
/* @0x1fc7b8 mov r0, #1 */
/* @0x1fc7bc pop {r4, pc} */
/* @0x1fc7c0 mov r0, r2 */
/* @0x1fc7c4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc7c8 mov r12, r0 */
/* @0x1fc7cc mov r3, r1 */
/* @0x1fc7d0 b 0x1fc7a8 <_Z13SV_ViewObjectP9CInstanceiP6RValue+0x38> */
/* @0x1fc7d4 andseq r1, pc, r12, lsr #3 */

/* ── FUNC 0x1fc7d8 · SV_ViewSurfaceID(CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1fc7d8 ldr r3, [pc, #0x5c] */
/* @0x1fc7dc cmp r1, #7 */
/* @0x1fc7e0 ldr r0, [r2, #0xc] */
/* @0x1fc7e4 ldr r3, [pc, r3] */
/* @0x1fc7e8 movhi r1, #0 */
/* @0x1fc7ec bic r0, r0, #-16777216 */
/* @0x1fc7f0 add r1, r1, #18 */
/* @0x1fc7f4 ldr r3, [r3] */
/* @0x1fc7f8 cmp r0, #0 */
/* @0x1fc7fc push {r4, lr} */
/* @0x1fc800 ldr r4, [r3, r1, lsl #2] */
/* @0x1fc804 bne 0x1fc828 <_Z16SV_ViewSurfaceIDP9CInstanceiP6RValue+0x50> */
/* @0x1fc808 ldr r12, [r2] */
/* @0x1fc80c ldr r3, [r2, #0x4] */
/* @0x1fc810 mov r0, r12 */
/* @0x1fc814 mov r1, r3 */
/* @0x1fc818 bl 0xb66e8 <lrint@plt> */
/* @0x1fc81c str r0, [r4, #0x3c] */
/* @0x1fc820 mov r0, #1 */
/* @0x1fc824 pop {r4, pc} */
/* @0x1fc828 mov r0, r2 */
/* @0x1fc82c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue> */
/* @0x1fc830 mov r12, r0 */
/* @0x1fc834 mov r3, r1 */
/* @0x1fc838 b 0x1fc810 <_Z16SV_ViewSurfaceIDP9CInstanceiP6RValue+0x38> */
/* @0x1fc83c andseq r1, pc, r4, asr #2 */
