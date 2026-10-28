/* libyoyo.so 覆盖卡组 0127
 * 函数 0x18ee74..0x190490，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x18ee74 · GMGamePad::Update(float*, float*) · size=116 · insn=29 */
/* @0x18ee74 ldr r3, [r0, #0x4] */
/* @0x18ee78 push {r4, r5, r6, lr} */
/* @0x18ee7c mov r4, r0 */
/* @0x18ee80 mov r5, r1 */
/* @0x18ee84 mov r6, r2 */
/* @0x18ee88 ldr r0, [r0, #0xc] */
/* @0x18ee8c lsl r2, r3, #2 */
/* @0x18ee90 ldr r1, [r4, #0x10] */
/* @0x18ee94 bl 0xb65bc <memcpy@plt> */
/* @0x18ee98 ldr r2, [r4, #0x8] */
/* @0x18ee9c cmp r2, #0 */
/* @0x18eea0 ble 0x18eeb4 <_ZN9GMGamePad6UpdateEPfS0_+0x40> */
/* @0x18eea4 lsl r2, r2, #2 */
/* @0x18eea8 ldr r0, [r4, #0x18] */
/* @0x18eeac ldr r1, [r4, #0x14] */
/* @0x18eeb0 bl 0xb65bc <memcpy@plt> */
/* @0x18eeb4 ldr r2, [r4, #0x4] */
/* @0x18eeb8 mov r1, r5 */
/* @0x18eebc ldr r0, [r4, #0x10] */
/* @0x18eec0 lsl r2, r2, #2 */
/* @0x18eec4 bl 0xb65bc <memcpy@plt> */
/* @0x18eec8 ldr r2, [r4, #0x8] */
/* @0x18eecc cmp r2, #0 */
/* @0x18eed0 pople {r4, r5, r6, pc} */
/* @0x18eed4 ldr r0, [r4, #0x14] */
/* @0x18eed8 mov r1, r6 */
/* @0x18eedc lsl r2, r2, #2 */
/* @0x18eee0 pop {r4, r5, r6, lr} */
/* @0x18eee4 b 0xb65bc <memcpy@plt> */

/* ── FUNC 0x18eee8 · GMGamePad::SetMotorSpeeds(float, float) · size=104 · insn=26 */
/* @0x18eee8 vmov s14, r1 */
/* @0x18eeec vmov s15, r2 */
/* @0x18eef0 vcmpe.f32 s14, #0 */
/* @0x18eef4 vmrs APSR_nzcv, fpscr */
/* @0x18eef8 bmi 0x18ef34 <_ZN9GMGamePad14SetMotorSpeedsEff+0x4c> */
/* @0x18eefc vmov.f32 s13, #1.000000e+00 */
/* @0x18ef00 vcmp.f32 s14, s13 */
/* @0x18ef04 vmrs APSR_nzcv, fpscr */
/* @0x18ef08 vcmpe.f32 s15, #0 */
/* @0x18ef0c vmovgt.f32 s14, s13 */
/* @0x18ef10 vmrs APSR_nzcv, fpscr */
/* @0x18ef14 bmi 0x18ef44 <_ZN9GMGamePad14SetMotorSpeedsEff+0x5c> */
/* @0x18ef18 vmov.f32 s13, #1.000000e+00 */
/* @0x18ef1c vcmp.f32 s15, s13 */
/* @0x18ef20 vmrs APSR_nzcv, fpscr */
/* @0x18ef24 vmovgt.f32 s15, s13 */
/* @0x18ef28 vstr s14, [r0, #36] */
/* @0x18ef2c vstr s15, [r0, #40] */
/* @0x18ef30 bx lr */
/* @0x18ef34 vcmpe.f32 s15, #0 */
/* @0x18ef38 vldr s14, [pc, #12] */
/* @0x18ef3c vmrs APSR_nzcv, fpscr */
/* @0x18ef40 bpl 0x18ef18 <_ZN9GMGamePad14SetMotorSpeedsEff+0x30> */
/* @0x18ef44 vldr s15, [pc] */
/* @0x18ef48 b 0x18ef28 <_ZN9GMGamePad14SetMotorSpeedsEff+0x40> */
/* @0x18ef4c andeq r0, r0, r0 */

/* ── FUNC 0x18ef50 · RegisterAndroidKeyEvent(int, int) · size=136 · insn=34 */
/* @0x18ef50 ldr r2, [pc, #0x74] */
/* @0x18ef54 push {r4, lr} */
/* @0x18ef58 add r2, pc, r2 */
/* @0x18ef5c sub sp, sp, #8 */
/* @0x18ef60 mov r4, r0 */
/* @0x18ef64 ldr r3, [r2] */
/* @0x18ef68 cmp r3, #0 */
/* @0x18ef6c beq 0x18efb4 <_Z23RegisterAndroidKeyEventii+0x64> */
/* @0x18ef70 ldr r0, [r3] */
/* @0x18ef74 str r0, [r2] */
/* @0x18ef78 ldr r12, [pc, #0x50] */
/* @0x18ef7c mov r0, #0 */
/* @0x18ef80 str r4, [r3, #0x4] */
/* @0x18ef84 add r12, pc, r12 */
/* @0x18ef88 str r1, [r3, #0x8] */
/* @0x18ef8c str r0, [r3] */
/* @0x18ef90 ldr r2, [r12, #0x4] */
/* @0x18ef94 cmp r2, r0 */
/* @0x18ef98 streq r3, [r12, #0x8] */
/* @0x18ef9c strne r3, [r2] */
/* @0x18efa0 ldr r2, [pc, #0x2c] */
/* @0x18efa4 add r2, pc, r2 */
/* @0x18efa8 str r3, [r2, #0x4] */
/* @0x18efac add sp, sp, #8 */
/* @0x18efb0 pop {r4, pc} */
/* @0x18efb4 mov r0, #12 */
/* @0x18efb8 str r1, [sp, #0x4] */
/* @0x18efbc bl 0x27c524 <_Znwj> */
/* @0x18efc0 ldr r1, [sp, #0x4] */
/* @0x18efc4 mov r3, r0 */
/* @0x18efc8 b 0x18ef78 <_Z23RegisterAndroidKeyEventii+0x28> */
/* @0x18efcc eorseq r6, r10, r8, ror #14 */
/* @0x18efd0 eorseq r6, r10, r12, lsr r7 */
/* @0x18efd4 eorseq r6, r10, r12, lsl r7 */

/* ── FUNC 0x18efd8 · ProfileFrameRequest(unsigned int, unsigned int) · size=44 · insn=11 */
/* @0x18efd8 rsbs r3, r0, #1 */
/* @0x18efdc movlo r3, #0 */
/* @0x18efe0 cmp r1, #0 */
/* @0x18efe4 moveq r3, #0 */
/* @0x18efe8 cmp r3, #0 */
/* @0x18efec ldrne r3, [pc, #0xc] */
/* @0x18eff0 movne r2, #1 */
/* @0x18eff4 ldrne r3, [pc, r3] */
/* @0x18eff8 strbne r2, [r3] */
/* @0x18effc bx lr */
/* @0x18f000 eoreq r1, r6, r0, asr r6 */

/* ── FUNC 0x18f004 · VMFlipRequest(unsigned int, unsigned int) · size=88 · insn=22 */
/* @0x18f004 rsbs r3, r0, #1 */
/* @0x18f008 movlo r3, #0 */
/* @0x18f00c cmp r1, #0 */
/* @0x18f010 moveq r3, #0 */
/* @0x18f014 cmp r3, #0 */
/* @0x18f018 bxeq lr */
/* @0x18f01c ldr r3, [pc, #0x2c] */
/* @0x18f020 ldr r3, [pc, r3] */
/* @0x18f024 ldrb r2, [r3] */
/* @0x18f028 eor r2, r2, #1 */
/* @0x18f02c strb r2, [r3] */
/* @0x18f030 cmp r2, #0 */
/* @0x18f034 bne 0x18f044 <_Z13VMFlipRequestjj+0x40> */
/* @0x18f038 ldr r0, [pc, #0x14] */
/* @0x18f03c add r0, pc, r0 */
/* @0x18f040 b 0xb694c <puts@plt> */
/* @0x18f044 ldr r0, [pc, #0xc] */
/* @0x18f048 add r0, pc, r0 */
/* @0x18f04c b 0xb694c <puts@plt> */
/* @0x18f050 eoreq r1, r6, r8, lsr #12 */
/* @0x18f054 andseq sp, r11, r12, ror #7 */
/* @0x18f058 ldrsbeq sp, [r11], -r4 */

/* ── FUNC 0x18f05c · IO_SetupM(IniFile*) · size=56 · insn=14 */
/* @0x18f05c ldr r1, [pc, #0x24] */
/* @0x18f060 ldr r2, [pc, #0x24] */
/* @0x18f064 push {r3, lr} */
/* @0x18f068 add r1, pc, r1 */
/* @0x18f06c mov r3, #0 */
/* @0x18f070 add r2, pc, r2 */
/* @0x18f074 bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i> */
/* @0x18f078 ldr r3, [pc, #0x10] */
/* @0x18f07c ldr r3, [pc, r3] */
/* @0x18f080 str r0, [r3] */
/* @0x18f084 pop {r3, pc} */
/* @0x18f088 andseq sp, r11, r12, asr #7 */
/* @0x18f08c ldrsbeq sp, [r11], -r4 */
/* @0x18f090 .word 0x002615d0 */

/* ── FUNC 0x18f094 · IO_UpdateM() · size=1080 · insn=270 */
/* @0x18f094 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x18f098 mov r1, #0 */
/* @0x18f09c ldr r4, [pc, #0x3f8] */
/* @0x18f0a0 mov r2, #256 */
/* @0x18f0a4 ldr r3, [pc, #0x3f4] */
/* @0x18f0a8 add r4, pc, r4 */
/* @0x18f0ac ldr r9, [r4, r3] */
/* @0x18f0b0 mov r0, r9 */
/* @0x18f0b4 bl 0xb65b0 <memset@plt> */
/* @0x18f0b8 ldr r3, [pc, #0x3e4] */
/* @0x18f0bc mov r1, #0 */
/* @0x18f0c0 mov r2, #256 */
/* @0x18f0c4 ldr r5, [r4, r3] */
/* @0x18f0c8 mov r0, r5 */
/* @0x18f0cc bl 0xb65b0 <memset@plt> */
/* @0x18f0d0 ldr r3, [pc, #0x3d0] */
/* @0x18f0d4 mov r1, #0 */
/* @0x18f0d8 mov r2, #30 */
/* @0x18f0dc ldr r6, [r4, r3] */
/* @0x18f0e0 mov r0, r6 */
/* @0x18f0e4 bl 0xb65b0 <memset@plt> */
/* @0x18f0e8 ldr r3, [pc, #0x3bc] */
/* @0x18f0ec mov r1, #0 */
/* @0x18f0f0 mov r2, #30 */
/* @0x18f0f4 ldr r8, [r4, r3] */
/* @0x18f0f8 mov r0, r8 */
/* @0x18f0fc bl 0xb65b0 <memset@plt> */
/* @0x18f100 ldr r3, [pc, #0x3a8] */
/* @0x18f104 mov r1, #0 */
/* @0x18f108 mov r2, #30 */
/* @0x18f10c ldr r7, [r4, r3] */
/* @0x18f110 mov r0, r7 */
/* @0x18f114 bl 0xb65b0 <memset@plt> */
/* @0x18f118 ldr r2, [pc, #0x394] */
/* @0x18f11c mov r1, #0 */
/* @0x18f120 add r2, pc, r2 */
/* @0x18f124 ldr r3, [r2, #0x8] */
/* @0x18f128 str r1, [r2, #0x4] */
/* @0x18f12c cmp r3, r1 */
/* @0x18f130 str r1, [r2, #0x8] */
/* @0x18f134 beq 0x18f488 <_Z10IO_UpdateMv+0x3f4> */
/* @0x18f138 ldr r0, [pc, #0x378] */
/* @0x18f13c ldr r1, [pc, #0x378] */
/* @0x18f140 ldr r10, [r2] */
/* @0x18f144 ldr r0, [r4, r0] */
/* @0x18f148 ldr r1, [r4, r1] */
/* @0x18f14c ldr r2, [r3, #0x8] */
/* @0x18f150 ldr lr, [r3] */
/* @0x18f154 sub r12, r2, #4 */
/* @0x18f158 cmp r12, #105 */
/* @0x18f15c addls pc, pc, r12, lsl #2 */
/* @0x18f160 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f164 b 0x18f474 <_Z10IO_UpdateMv+0x3e0> */
/* @0x18f168 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f16c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f170 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f174 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f178 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f17c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f180 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f184 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f188 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f18c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f190 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f194 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f198 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f19c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1a0 b 0x18f47c <_Z10IO_UpdateMv+0x3e8> */
/* @0x18f1a4 b 0x18f46c <_Z10IO_UpdateMv+0x3d8> */
/* @0x18f1a8 b 0x18f464 <_Z10IO_UpdateMv+0x3d0> */
/* @0x18f1ac b 0x18f45c <_Z10IO_UpdateMv+0x3c8> */
/* @0x18f1b0 b 0x18f454 <_Z10IO_UpdateMv+0x3c0> */
/* @0x18f1b4 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1b8 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1bc b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1c0 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1c4 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1c8 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1cc b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1d0 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1d4 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1d8 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1dc b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1e0 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1e4 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1e8 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1ec b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1f0 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1f4 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1f8 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f1fc b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f200 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f204 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f208 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f20c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f210 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f214 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f218 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f21c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f220 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f224 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f228 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f22c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f230 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f234 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f238 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f23c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f240 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f244 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f248 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f24c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f250 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f254 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f258 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f25c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f260 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f264 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f268 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f26c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f270 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f274 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f278 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f27c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f280 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f284 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f288 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f28c b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f290 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f294 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f298 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f29c b 0x18f44c <_Z10IO_UpdateMv+0x3b8> */
/* @0x18f2a0 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2a4 b 0x18f444 <_Z10IO_UpdateMv+0x3b0> */
/* @0x18f2a8 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2ac b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2b0 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2b4 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2b8 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2bc b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2c0 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2c4 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2c8 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2cc b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2d0 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2d4 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2d8 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2dc b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2e0 b 0x18f43c <_Z10IO_UpdateMv+0x3a8> */
/* @0x18f2e4 b 0x18f434 <_Z10IO_UpdateMv+0x3a0> */
/* @0x18f2e8 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2ec b 0x18f42c <_Z10IO_UpdateMv+0x398> */
/* @0x18f2f0 b 0x18f424 <_Z10IO_UpdateMv+0x390> */
/* @0x18f2f4 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2f8 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f2fc b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f300 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f304 b 0x18f344 <_Z10IO_UpdateMv+0x2b0> */
/* @0x18f308 b 0x18f30c <_Z10IO_UpdateMv+0x278> */
/* @0x18f30c mov r2, #13 */
/* @0x18f310 ldr r12, [r3, #0x4] */
/* @0x18f314 cmp r12, #0 */
/* @0x18f318 beq 0x18f354 <_Z10IO_UpdateMv+0x2c0> */
/* @0x18f31c cmp r12, #1 */
/* @0x18f320 strbeq r12, [r9, r2] */
/* @0x18f324 moveq r12, #0 */
/* @0x18f328 strbeq r12, [r1, r2] */
/* @0x18f32c cmp lr, #0 */
/* @0x18f330 str r10, [r3] */
/* @0x18f334 beq 0x18f378 <_Z10IO_UpdateMv+0x2e4> */
/* @0x18f338 mov r10, r3 */
/* @0x18f33c mov r3, lr */
/* @0x18f340 b 0x18f14c <_Z10IO_UpdateMv+0xb8> */
/* @0x18f344 ldr r12, [r3, #0x4] */
/* @0x18f348 mov r2, #161 */
/* @0x18f34c cmp r12, #0 */
/* @0x18f350 bne 0x18f31c <_Z10IO_UpdateMv+0x288> */
/* @0x18f354 ldrb r12, [r0, r2] */
/* @0x18f358 cmp r12, #0 */
/* @0x18f35c moveq r12, #1 */
/* @0x18f360 strbeq r12, [r5, r2] */
/* @0x18f364 cmp lr, #0 */
/* @0x18f368 mov r12, #1 */
/* @0x18f36c strb r12, [r1, r2] */
/* @0x18f370 str r10, [r3] */
/* @0x18f374 bne 0x18f338 <_Z10IO_UpdateMv+0x2a4> */
/* @0x18f378 ldr r2, [pc, #0x140] */
/* @0x18f37c add r2, pc, r2 */
/* @0x18f380 str r3, [r2] */
/* @0x18f384 mov r2, #256 */
/* @0x18f388 bl 0xb65bc <memcpy@plt> */
/* @0x18f38c ldr r2, [pc, #0x130] */
/* @0x18f390 ldr r3, [pc, #0x130] */
/* @0x18f394 mov r1, r7 */
/* @0x18f398 mov r12, #1 */
/* @0x18f39c ldr r7, [r4, r2] */
/* @0x18f3a0 mov r2, #0 */
/* @0x18f3a4 ldr r4, [r4, r3] */
/* @0x18f3a8 b 0x18f3ec <_Z10IO_UpdateMv+0x358> */
/* @0x18f3ac eor r0, r3, r0 */
/* @0x18f3b0 strb r12, [r1] */
/* @0x18f3b4 tst r0, #1 */
/* @0x18f3b8 strbne r12, [r6] */
/* @0x18f3bc ands r5, r3, #2 */
/* @0x18f3c0 beq 0x18f414 <_Z10IO_UpdateMv+0x380> */
/* @0x18f3c4 tst r0, #2 */
/* @0x18f3c8 strb r12, [r1, #0x1] */
/* @0x18f3cc strbne r12, [r6, #0x1] */
/* @0x18f3d0 str r3, [r4, r2] */
/* @0x18f3d4 add r2, r2, #4 */
/* @0x18f3d8 cmp r2, #40 */
/* @0x18f3dc add r6, r6, #3 */
/* @0x18f3e0 add r8, r8, #3 */
/* @0x18f3e4 add r1, r1, #3 */
/* @0x18f3e8 beq 0x18f484 <_Z10IO_UpdateMv+0x3f0> */
/* @0x18f3ec ldr r3, [r7, r2] */
/* @0x18f3f0 ldr r0, [r4, r2] */
/* @0x18f3f4 ands r5, r3, #1 */
/* @0x18f3f8 bne 0x18f3ac <_Z10IO_UpdateMv+0x318> */
/* @0x18f3fc eor r0, r3, r0 */
/* @0x18f400 strb r5, [r1] */
/* @0x18f404 tst r0, #1 */
/* @0x18f408 strbne r12, [r8] */
/* @0x18f40c ands r5, r3, #2 */
/* @0x18f410 bne 0x18f3c4 <_Z10IO_UpdateMv+0x330> */
/* @0x18f414 tst r0, #2 */
/* @0x18f418 strb r5, [r1, #0x1] */
/* @0x18f41c strbne r12, [r8, #0x1] */
/* @0x18f420 b 0x18f3d0 <_Z10IO_UpdateMv+0x33c> */
/* @0x18f424 mov r2, #82 */
/* @0x18f428 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f42c mov r2, #76 */
/* @0x18f430 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f434 mov r2, #84 */
/* @0x18f438 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f43c mov r2, #83 */
/* @0x18f440 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f444 mov r2, #17 */
/* @0x18f448 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f44c mov r2, #77 */
/* @0x18f450 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f454 mov r2, #32 */
/* @0x18f458 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f45c mov r2, #39 */
/* @0x18f460 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f464 mov r2, #37 */
/* @0x18f468 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f46c mov r2, #40 */
/* @0x18f470 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f474 mov r2, #8 */
/* @0x18f478 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f47c mov r2, #38 */
/* @0x18f480 b 0x18f310 <_Z10IO_UpdateMv+0x27c> */
/* @0x18f484 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x18f488 ldr r2, [pc, #0x28] */
/* @0x18f48c ldr r3, [pc, #0x28] */
/* @0x18f490 ldr r0, [r4, r2] */
/* @0x18f494 ldr r1, [r4, r3] */
/* @0x18f498 b 0x18f384 <_Z10IO_UpdateMv+0x2f0> */
/* @0x18f49c eoreq r2, r6, r8, lsr #23 */
/* @0x18f4a0 .word 0xffffe994 */
/* @0x18f4a4 .word 0xffffe998 */
/* @0x18f4a8 .word 0xffffe9ac */
/* @0x18f4ac .word 0xffffe9a8 */
/* @0x18f4b0 .word 0xffffe9a4 */
/* @0x18f4b4 eorseq r6, r10, r0, lsr #11 */
/* @0x18f4b8 .word 0xffffe990 */
/* @0x18f4bc .word 0xffffea00 */
/* @0x18f4c0 eorseq r6, r10, r4, asr #6 */
/* @0x18f4c4 .word 0xffffe9dc */
/* @0x18f4c8 .word 0xffffea04 */

/* ── FUNC 0x18f4cc · IO_Init_TForm(TForm*) · size=4 · insn=1 */
/* @0x18f4cc bx lr */

/* ── FUNC 0x18f4d0 · _ReadSaveFile(char const*, int*) · size=196 · insn=49 */
/* @0x18f4d0 push {r4, r5, r6, lr} */
/* @0x18f4d4 mov r5, r1 */
/* @0x18f4d8 ldr r1, [pc, #0xac] */
/* @0x18f4dc sub sp, sp, #8 */
/* @0x18f4e0 add r1, pc, r1 */
/* @0x18f4e4 bl 0xb6844 <fopen@plt> */
/* @0x18f4e8 subs r4, r0, #0 */
/* @0x18f4ec beq 0x18f584 <_Z13_ReadSaveFilePKcPi+0xb4> */
/* @0x18f4f0 mov r1, #0 */
/* @0x18f4f4 mov r3, #32768 */
/* @0x18f4f8 mov r2, r1 */
/* @0x18f4fc bl 0xb6928 <setvbuf@plt> */
/* @0x18f500 mov r2, #2 */
/* @0x18f504 mov r1, #0 */
/* @0x18f508 mov r0, r4 */
/* @0x18f50c bl 0xb68d4 <fseek@plt> */
/* @0x18f510 add r1, sp, #4 */
/* @0x18f514 mov r0, r4 */
/* @0x18f518 bl 0xb6958 <fgetpos@plt> */
/* @0x18f51c cmp r5, #0 */
/* @0x18f520 mov r1, #0 */
/* @0x18f524 mov r0, r4 */
/* @0x18f528 ldrne r3, [sp, #0x4] */
/* @0x18f52c mov r2, r1 */
/* @0x18f530 strne r3, [r5] */
/* @0x18f534 bl 0xb68d4 <fseek@plt> */
/* @0x18f538 ldr r5, [sp, #0x4] */
/* @0x18f53c ldr r1, [pc, #0x4c] */
/* @0x18f540 mov r2, #112 */
/* @0x18f544 cmp r5, #0 */
/* @0x18f548 mov r3, #1 */
/* @0x18f54c add r1, pc, r1 */
/* @0x18f550 movne r0, r5 */
/* @0x18f554 moveq r0, #1 */
/* @0x18f558 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18f55c mov r2, r5 */
/* @0x18f560 mov r1, #1 */
/* @0x18f564 mov r3, r4 */
/* @0x18f568 mov r6, r0 */
/* @0x18f56c bl 0xb68c8 <fread@plt> */
/* @0x18f570 mov r0, r4 */
/* @0x18f574 bl 0xb6850 <fclose@plt> */
/* @0x18f578 mov r0, r6 */
/* @0x18f57c add sp, sp, #8 */
/* @0x18f580 pop {r4, r5, r6, pc} */
/* @0x18f584 mov r6, r4 */
/* @0x18f588 b 0x18f578 <_Z13_ReadSaveFilePKcPi+0xa8> */
/* @0x18f58c andseq r8, r10, r8, lsl r7 */
/* @0x18f590 andseq r12, r11, r8, lsl #30 */

/* ── FUNC 0x18f594 · LoadSave::_ReadFile(char const*, int*) · size=284 · insn=71 */
/* @0x18f594 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18f598 mov r2, #1 */
/* @0x18f59c ldr r4, [pc, #0xf8] */
/* @0x18f5a0 sub sp, sp, #36 */
/* @0x18f5a4 mov r5, r0 */
/* @0x18f5a8 mov r6, r1 */
/* @0x18f5ac ldr r4, [pc, r4] */
/* @0x18f5b0 mov r1, r0 */
/* @0x18f5b4 ldr r0, [r4] */
/* @0x18f5b8 blx 0x2a44b8 <zip_fopen> */
/* @0x18f5bc subs r7, r0, #0 */
/* @0x18f5c0 beq 0x18f670 <_ZN8LoadSave9_ReadFileEPKcPi+0xdc> */
/* @0x18f5c4 add r3, sp, #4 */
/* @0x18f5c8 mov r1, r5 */
/* @0x18f5cc mov r2, #1 */
/* @0x18f5d0 ldr r0, [r4] */
/* @0x18f5d4 blx 0x2a5670 <zip_stat> */
/* @0x18f5d8 cmp r6, #0 */
/* @0x18f5dc ldr r1, [pc, #0xbc] */
/* @0x18f5e0 mov r2, #191 */
/* @0x18f5e4 ldrne r3, [sp, #0x14] */
/* @0x18f5e8 ldreq r0, [sp, #0x14] */
/* @0x18f5ec add r1, pc, r1 */
/* @0x18f5f0 ldr r8, [pc, #0xac] */
/* @0x18f5f4 add r8, pc, r8 */
/* @0x18f5f8 strne r3, [r6] */
/* @0x18f5fc movne r0, r3 */
/* @0x18f600 cmp r0, #0 */
/* @0x18f604 mov r3, #1 */
/* @0x18f608 moveq r0, #1 */
/* @0x18f60c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18f610 ldr r5, [sp, #0x14] */
/* @0x18f614 cmp r5, #0 */
/* @0x18f618 mov r9, r0 */
/* @0x18f61c mov r6, r0 */
/* @0x18f620 beq 0x18f65c <_ZN8LoadSave9_ReadFileEPKcPi+0xc8> */
/* @0x18f624 mov r1, r6 */
/* @0x18f628 mov r0, r7 */
/* @0x18f62c mov r2, r5 */
/* @0x18f630 blx 0x2a476c <zip_fread> */
/* @0x18f634 mov r4, r0 */
/* @0x18f638 cmp r4, r5 */
/* @0x18f63c mov r0, r8 */
/* @0x18f640 add r6, r6, r4 */
/* @0x18f644 beq 0x18f65c <_ZN8LoadSave9_ReadFileEPKcPi+0xc8> */
/* @0x18f648 bl 0xb6964 <printf@plt> */
/* @0x18f64c cmp r4, #0 */
/* @0x18f650 beq 0x18f65c <_ZN8LoadSave9_ReadFileEPKcPi+0xc8> */
/* @0x18f654 subs r5, r5, r4 */
/* @0x18f658 bne 0x18f624 <_ZN8LoadSave9_ReadFileEPKcPi+0x90> */
/* @0x18f65c mov r0, r7 */
/* @0x18f660 blx 0x2a4388 <zip_fclose> */
/* @0x18f664 mov r0, r9 */
/* @0x18f668 add sp, sp, #36 */
/* @0x18f66c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18f670 ldr r3, [pc, #0x30] */
/* @0x18f674 mov r2, r5 */
/* @0x18f678 ldr r1, [pc, #0x2c] */
/* @0x18f67c mov r9, r7 */
/* @0x18f680 ldr r3, [pc, r3] */
/* @0x18f684 add r1, pc, r1 */
/* @0x18f688 ldr r0, [r3] */
/* @0x18f68c ldr r3, [r0] */
/* @0x18f690 ldr r3, [r3, #0xc] */
/* @0x18f694 blx r3 */
/* @0x18f698 b 0x18f664 <_ZN8LoadSave9_ReadFileEPKcPi+0xd0> */
/* @0x18f69c eoreq r0, r6, r8, ror #18 */
/* @0x18f6a0 andseq r12, r11, r8, ror #28 */
/* @0x18f6a4 mulseq r11, r8, lr */
/* @0x18f6a8 mlaeq r5, r4, r0, lr */
/* @0x18f6ac andseq r12, r11, r0, lsr #28 */

/* ── FUNC 0x18f6b0 · LoadSave::SaveData(char const*, int) · size=4 · insn=1 */
/* @0x18f6b0 bx lr */

/* ── FUNC 0x18f6b4 · LoadSave::LoadData(int*) · size=8 · insn=2 */
/* @0x18f6b4 mov r0, #0 */
/* @0x18f6b8 bx lr */

/* ── FUNC 0x18f6bc · LoadSave::SetUp(IniFile*) · size=4 · insn=1 */
/* @0x18f6bc bx lr */

/* ── FUNC 0x18f6c0 · LoadSave::_FileExists(char*) · size=116 · insn=29 */
/* @0x18f6c0 push {r3, r4, r5, lr} */
/* @0x18f6c4 mov r1, r0 */
/* @0x18f6c8 ldr r3, [pc, #0x58] */
/* @0x18f6cc mov r5, r0 */
/* @0x18f6d0 mov r2, #1 */
/* @0x18f6d4 ldr r3, [pc, r3] */
/* @0x18f6d8 ldr r0, [r3] */
/* @0x18f6dc blx 0x2a44b8 <zip_fopen> */
/* @0x18f6e0 adds r4, r0, #0 */
/* @0x18f6e4 movne r4, #1 */
/* @0x18f6e8 cmp r4, #0 */
/* @0x18f6ec bne 0x18f71c <_ZN8LoadSave11_FileExistsEPc+0x5c> */
/* @0x18f6f0 ldr r3, [pc, #0x34] */
/* @0x18f6f4 mov r2, r5 */
/* @0x18f6f8 ldr r1, [pc, #0x30] */
/* @0x18f6fc ldr r3, [pc, r3] */
/* @0x18f700 add r1, pc, r1 */
/* @0x18f704 ldr r0, [r3] */
/* @0x18f708 ldr r3, [r0] */
/* @0x18f70c ldr r3, [r3, #0xc] */
/* @0x18f710 blx r3 */
/* @0x18f714 mov r0, r4 */
/* @0x18f718 pop {r3, r4, r5, pc} */
/* @0x18f71c blx 0x2a4388 <zip_fclose> */
/* @0x18f720 mov r0, r4 */
/* @0x18f724 pop {r3, r4, r5, pc} */
/* @0x18f728 eoreq r0, r6, r0, asr #16 */
/* @0x18f72c eoreq lr, r5, r8, lsl r0 */
/* @0x18f730 andseq r12, r11, r8, asr #27 */

/* ── FUNC 0x18f734 · LoadSave::_GetSize(char const*) · size=88 · insn=22 */
/* @0x18f734 ldr r1, [pc, #0x4c] */
/* @0x18f738 push {r4, lr} */
/* @0x18f73c add r1, pc, r1 */
/* @0x18f740 sub sp, sp, #8 */
/* @0x18f744 bl 0xb6844 <fopen@plt> */
/* @0x18f748 subs r4, r0, #0 */
/* @0x18f74c beq 0x18f780 <_ZN8LoadSave8_GetSizeEPKc+0x4c> */
/* @0x18f750 mov r1, #0 */
/* @0x18f754 mov r2, #2 */
/* @0x18f758 bl 0xb68d4 <fseek@plt> */
/* @0x18f75c mov r0, r4 */
/* @0x18f760 add r1, sp, #4 */
/* @0x18f764 bl 0xb6958 <fgetpos@plt> */
/* @0x18f768 mov r0, r4 */
/* @0x18f76c ldr r4, [sp, #0x4] */
/* @0x18f770 bl 0xb6850 <fclose@plt> */
/* @0x18f774 mov r0, r4 */
/* @0x18f778 add sp, sp, #8 */
/* @0x18f77c pop {r4, pc} */
/* @0x18f780 mvn r4, #0 */
/* @0x18f784 b 0x18f774 <_ZN8LoadSave8_GetSizeEPKc+0x40> */
/* @0x18f788 ldrheq r8, [r10], -r12 */

/* ── FUNC 0x18f78c · LoadSave::_GetBundleFileName(char*, int, char const*) · size=188 · insn=47 */
/* @0x18f78c push {r4, r5, r6, lr} */
/* @0x18f790 subs r5, r2, #0 */
/* @0x18f794 mov r4, r0 */
/* @0x18f798 strbeq r5, [r0] */
/* @0x18f79c beq 0x18f800 <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0x74> */
/* @0x18f7a0 ldrb r3, [r5] */
/* @0x18f7a4 cmp r3, #47 */
/* @0x18f7a8 cmpne r3, #92 */
/* @0x18f7ac beq 0x18f83c <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0xb0> */
/* @0x18f7b0 bl 0x28fd5c <_Z14GetFilePrePendv> */
/* @0x18f7b4 mov r3, #0 */
/* @0x18f7b8 mov r2, #6 */
/* @0x18f7bc strb r3, [r4] */
/* @0x18f7c0 mov r1, r0 */
/* @0x18f7c4 mov r6, r0 */
/* @0x18f7c8 mov r0, r5 */
/* @0x18f7cc bl 0xb65e0 <strncmp@plt> */
/* @0x18f7d0 cmp r0, #0 */
/* @0x18f7d4 bne 0x18f7e8 <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0x5c> */
/* @0x18f7d8 ldrb r3, [r5, #0x6] */
/* @0x18f7dc cmp r3, #47 */
/* @0x18f7e0 cmpne r3, #92 */
/* @0x18f7e4 beq 0x18f7f4 <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0x68> */
/* @0x18f7e8 mov r1, r6 */
/* @0x18f7ec mov r0, r4 */
/* @0x18f7f0 bl 0xb65a4 <strcpy@plt> */
/* @0x18f7f4 mov r1, r5 */
/* @0x18f7f8 mov r0, r4 */
/* @0x18f7fc bl 0xb6628 <strcat@plt> */
/* @0x18f800 ldrb r3, [r4] */
/* @0x18f804 cmp r3, #0 */
/* @0x18f808 popeq {r4, r5, r6, pc} */
/* @0x18f80c add r0, r4, #1 */
/* @0x18f810 mov r1, #95 */
/* @0x18f814 mov r2, #47 */
/* @0x18f818 cmp r3, #92 */
/* @0x18f81c strbeq r2, [r0, #-0x1] */
/* @0x18f820 beq 0x18f82c <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0xa0> */
/* @0x18f824 cmp r3, #32 */
/* @0x18f828 strbeq r1, [r0, #-0x1] */
/* @0x18f82c ldrb r3, [r0], #1 */
/* @0x18f830 cmp r3, #0 */
/* @0x18f834 bne 0x18f818 <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0x8c> */
/* @0x18f838 pop {r4, r5, r6, pc} */
/* @0x18f83c mov r1, r5 */
/* @0x18f840 bl 0xb65a4 <strcpy@plt> */
/* @0x18f844 b 0x18f800 <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0x74> */

/* ── FUNC 0x18f848 · LoadSave::ReadBundleFile(char const*, int*) · size=100 · insn=25 */
/* @0x18f848 push {r4, r5, r6, lr} */
/* @0x18f84c sub sp, sp, #2048 */
/* @0x18f850 ldr r4, [pc, #0x50] */
/* @0x18f854 sub sp, sp, #8 */
/* @0x18f858 add r5, sp, #4 */
/* @0x18f85c mov r2, r0 */
/* @0x18f860 ldr r4, [pc, r4] */
/* @0x18f864 mov r6, r1 */
/* @0x18f868 mov r0, r5 */
/* @0x18f86c mov r1, #2048 */
/* @0x18f870 ldr r3, [r4] */
/* @0x18f874 str r3, [sp, #0x804] */
/* @0x18f878 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x18f87c mov r0, r5 */
/* @0x18f880 mov r1, r6 */
/* @0x18f884 bl 0x18f594 <_ZN8LoadSave9_ReadFileEPKcPi> */
/* @0x18f888 ldr r2, [sp, #0x804] */
/* @0x18f88c ldr r3, [r4] */
/* @0x18f890 cmp r2, r3 */
/* @0x18f894 bne 0x18f8a4 <_ZN8LoadSave14ReadBundleFileEPKcPi+0x5c> */
/* @0x18f898 add sp, sp, #2048 */
/* @0x18f89c add sp, sp, #8 */
/* @0x18f8a0 pop {r4, r5, r6, pc} */
/* @0x18f8a4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x18f8a8 .word 0x0025e0f0 */

/* ── FUNC 0x18f8ac · LoadSave::BundleFileExists(char const*) · size=92 · insn=23 */
/* @0x18f8ac push {r4, r5, lr} */
/* @0x18f8b0 sub sp, sp, #2048 */
/* @0x18f8b4 ldr r4, [pc, #0x48] */
/* @0x18f8b8 sub sp, sp, #12 */
/* @0x18f8bc add r5, sp, #4 */
/* @0x18f8c0 mov r2, r0 */
/* @0x18f8c4 ldr r4, [pc, r4] */
/* @0x18f8c8 mov r1, #2048 */
/* @0x18f8cc mov r0, r5 */
/* @0x18f8d0 ldr r3, [r4] */
/* @0x18f8d4 str r3, [sp, #0x804] */
/* @0x18f8d8 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x18f8dc mov r0, r5 */
/* @0x18f8e0 bl 0x18f6c0 <_ZN8LoadSave11_FileExistsEPc> */
/* @0x18f8e4 ldr r2, [sp, #0x804] */
/* @0x18f8e8 ldr r3, [r4] */
/* @0x18f8ec cmp r2, r3 */
/* @0x18f8f0 bne 0x18f900 <_ZN8LoadSave16BundleFileExistsEPKc+0x54> */
/* @0x18f8f4 add sp, sp, #2048 */
/* @0x18f8f8 add sp, sp, #12 */
/* @0x18f8fc pop {r4, r5, pc} */
/* @0x18f900 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x18f904 eoreq lr, r5, r12, lsl #1 */

/* ── FUNC 0x18f908 · LoadSave::GetBundleFileSize(char const*) · size=92 · insn=23 */
/* @0x18f908 push {r4, r5, lr} */
/* @0x18f90c sub sp, sp, #2048 */
/* @0x18f910 ldr r4, [pc, #0x48] */
/* @0x18f914 sub sp, sp, #12 */
/* @0x18f918 add r5, sp, #4 */
/* @0x18f91c mov r2, r0 */
/* @0x18f920 ldr r4, [pc, r4] */
/* @0x18f924 mov r1, #2048 */
/* @0x18f928 mov r0, r5 */
/* @0x18f92c ldr r3, [r4] */
/* @0x18f930 str r3, [sp, #0x804] */
/* @0x18f934 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x18f938 mov r0, r5 */
/* @0x18f93c bl 0x18f6c0 <_ZN8LoadSave11_FileExistsEPc> */
/* @0x18f940 ldr r2, [sp, #0x804] */
/* @0x18f944 ldr r3, [r4] */
/* @0x18f948 cmp r2, r3 */
/* @0x18f94c bne 0x18f95c <_ZN8LoadSave17GetBundleFileSizeEPKc+0x54> */
/* @0x18f950 add sp, sp, #2048 */
/* @0x18f954 add sp, sp, #12 */
/* @0x18f958 pop {r4, r5, pc} */
/* @0x18f95c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x18f960 eoreq lr, r5, r0, lsr r0 */

/* ── FUNC 0x18f964 · LoadSave::_GetSaveFileName(char*, int, char const*) · size=216 · insn=54 */
/* @0x18f964 push {r4, r5, r6, r7, r8, lr} */
/* @0x18f968 mov r4, r2 */
/* @0x18f96c mov r5, r0 */
/* @0x18f970 bl 0x28fd6c <_Z14GetSavePrePendv> */
/* @0x18f974 cmp r4, #0 */
/* @0x18f978 strbeq r4, [r5] */
/* @0x18f97c mov r8, r0 */
/* @0x18f980 beq 0x18f9d8 <_ZN8LoadSave16_GetSaveFileNameEPciPKc+0x74> */
/* @0x18f984 ldr r6, [pc, #0xac] */
/* @0x18f988 ldr r6, [pc, r6] */
/* @0x18f98c ldr r7, [r6] */
/* @0x18f990 mov r0, r7 */
/* @0x18f994 bl 0xb6538 <strlen@plt> */
/* @0x18f998 mov r1, r7 */
/* @0x18f99c mov r2, r0 */
/* @0x18f9a0 mov r0, r4 */
/* @0x18f9a4 bl 0xb65e0 <strncmp@plt> */
/* @0x18f9a8 cmp r0, #0 */
/* @0x18f9ac beq 0x18fa14 <_ZN8LoadSave16_GetSaveFileNameEPciPKc+0xb0> */
/* @0x18f9b0 ldrb r3, [r4] */
/* @0x18f9b4 cmp r3, #47 */
/* @0x18f9b8 cmpne r3, #92 */
/* @0x18f9bc beq 0x18fa04 <_ZN8LoadSave16_GetSaveFileNameEPciPKc+0xa0> */
/* @0x18f9c0 mov r1, r8 */
/* @0x18f9c4 mov r0, r5 */
/* @0x18f9c8 bl 0xb65a4 <strcpy@plt> */
/* @0x18f9cc mov r0, r5 */
/* @0x18f9d0 mov r1, r4 */
/* @0x18f9d4 bl 0xb6628 <strcat@plt> */
/* @0x18f9d8 ldrb r3, [r5] */
/* @0x18f9dc cmp r3, #0 */
/* @0x18f9e0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x18f9e4 add r0, r5, #1 */
/* @0x18f9e8 mov r2, #47 */
/* @0x18f9ec cmp r3, #92 */
/* @0x18f9f0 strbeq r2, [r0, #-0x1] */
/* @0x18f9f4 ldrb r3, [r0], #1 */
/* @0x18f9f8 cmp r3, #0 */
/* @0x18f9fc bne 0x18f9ec <_ZN8LoadSave16_GetSaveFileNameEPciPKc+0x88> */
/* @0x18fa00 pop {r4, r5, r6, r7, r8, pc} */
/* @0x18fa04 mov r1, r4 */
/* @0x18fa08 mov r0, r5 */
/* @0x18fa0c bl 0xb65a4 <strcpy@plt> */
/* @0x18fa10 b 0x18f9d8 <_ZN8LoadSave16_GetSaveFileNameEPciPKc+0x74> */
/* @0x18fa14 mov r1, r8 */
/* @0x18fa18 mov r0, r5 */
/* @0x18fa1c bl 0xb65a4 <strcpy@plt> */
/* @0x18fa20 ldr r0, [r6] */
/* @0x18fa24 bl 0xb6538 <strlen@plt> */
/* @0x18fa28 add r1, r4, r0 */
/* @0x18fa2c mov r0, r5 */
/* @0x18fa30 bl 0xb6628 <strcat@plt> */
/* @0x18fa34 b 0x18f9d8 <_ZN8LoadSave16_GetSaveFileNameEPciPKc+0x74> */
/* @0x18fa38 .word 0x00260cd0 */

/* ── FUNC 0x18fa3c · LoadSave::WriteFile(char const*, char const*, int) · size=204 · insn=51 */
/* @0x18fa3c push {r4, r5, r6, r7, lr} */
/* @0x18fa40 sub sp, sp, #2048 */
/* @0x18fa44 ldr r7, [pc, #0xb4] */
/* @0x18fa48 sub sp, sp, #12 */
/* @0x18fa4c add r6, sp, #4 */
/* @0x18fa50 mov r12, r0 */
/* @0x18fa54 ldr r7, [pc, r7] */
/* @0x18fa58 mov r5, r1 */
/* @0x18fa5c mov r0, r6 */
/* @0x18fa60 movw r1, #0x7ff */
/* @0x18fa64 ldr r3, [r7] */
/* @0x18fa68 mov r4, r2 */
/* @0x18fa6c mov r2, r12 */
/* @0x18fa70 str r3, [sp, #0x804] */
/* @0x18fa74 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x18fa78 mov r0, r6 */
/* @0x18fa7c bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc> */
/* @0x18fa80 ldr r1, [pc, #0x7c] */
/* @0x18fa84 mov r0, r6 */
/* @0x18fa88 add r1, pc, r1 */
/* @0x18fa8c bl 0xb6844 <fopen@plt> */
/* @0x18fa90 subs r6, r0, #0 */
/* @0x18fa94 beq 0x18faf4 <_ZN8LoadSave9WriteFileEPKcS1_i+0xb8> */
/* @0x18fa98 cmp r4, #0 */
/* @0x18fa9c bne 0x18fab0 <_ZN8LoadSave9WriteFileEPKcS1_i+0x74> */
/* @0x18faa0 b 0x18facc <_ZN8LoadSave9WriteFileEPKcS1_i+0x90> */
/* @0x18faa4 subs r4, r4, r0 */
/* @0x18faa8 add r5, r5, r0 */
/* @0x18faac beq 0x18facc <_ZN8LoadSave9WriteFileEPKcS1_i+0x90> */
/* @0x18fab0 mov r0, r5 */
/* @0x18fab4 mov r1, #1 */
/* @0x18fab8 mov r2, r4 */
/* @0x18fabc mov r3, r6 */
/* @0x18fac0 bl 0xb68bc <fwrite@plt> */
/* @0x18fac4 cmp r0, #0 */
/* @0x18fac8 bne 0x18faa4 <_ZN8LoadSave9WriteFileEPKcS1_i+0x68> */
/* @0x18facc mov r0, r6 */
/* @0x18fad0 bl 0xb6850 <fclose@plt> */
/* @0x18fad4 mov r0, #1 */
/* @0x18fad8 ldr r2, [sp, #0x804] */
/* @0x18fadc ldr r3, [r7] */
/* @0x18fae0 cmp r2, r3 */
/* @0x18fae4 bne 0x18fafc <_ZN8LoadSave9WriteFileEPKcS1_i+0xc0> */
/* @0x18fae8 add sp, sp, #2048 */
/* @0x18faec add sp, sp, #12 */
/* @0x18faf0 pop {r4, r5, r6, r7, pc} */
/* @0x18faf4 mov r0, r6 */
/* @0x18faf8 b 0x18fad8 <_ZN8LoadSave9WriteFileEPKcS1_i+0x9c> */
/* @0x18fafc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x18fb00 .word 0x0025defc */
/* @0x18fb04 ldrheq r0, [r11], -r12 */

/* ── FUNC 0x18fb08 · LoadSave::ReadSaveFile(char const*, int*) · size=100 · insn=25 */
/* @0x18fb08 push {r4, r5, r6, lr} */
/* @0x18fb0c sub sp, sp, #2048 */
/* @0x18fb10 ldr r4, [pc, #0x50] */
/* @0x18fb14 sub sp, sp, #8 */
/* @0x18fb18 add r5, sp, #4 */
/* @0x18fb1c mov r2, r0 */
/* @0x18fb20 ldr r4, [pc, r4] */
/* @0x18fb24 mov r6, r1 */
/* @0x18fb28 mov r0, r5 */
/* @0x18fb2c mov r1, #2048 */
/* @0x18fb30 ldr r3, [r4] */
/* @0x18fb34 str r3, [sp, #0x804] */
/* @0x18fb38 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x18fb3c mov r0, r5 */
/* @0x18fb40 mov r1, r6 */
/* @0x18fb44 bl 0x18f4d0 <_Z13_ReadSaveFilePKcPi> */
/* @0x18fb48 ldr r2, [sp, #0x804] */
/* @0x18fb4c ldr r3, [r4] */
/* @0x18fb50 cmp r2, r3 */
/* @0x18fb54 bne 0x18fb64 <_ZN8LoadSave12ReadSaveFileEPKcPi+0x5c> */
/* @0x18fb58 add sp, sp, #2048 */
/* @0x18fb5c add sp, sp, #8 */
/* @0x18fb60 pop {r4, r5, r6, pc} */
/* @0x18fb64 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x18fb68 eoreq sp, r5, r0, lsr lr */

/* ── FUNC 0x18fb6c · LoadSave::SaveFileExists(char const*) · size=124 · insn=31 */
/* @0x18fb6c push {r4, r5, lr} */
/* @0x18fb70 sub sp, sp, #2048 */
/* @0x18fb74 ldr r4, [pc, #0x64] */
/* @0x18fb78 sub sp, sp, #12 */
/* @0x18fb7c add r5, sp, #4 */
/* @0x18fb80 mov r2, r0 */
/* @0x18fb84 ldr r4, [pc, r4] */
/* @0x18fb88 mov r1, #2048 */
/* @0x18fb8c mov r0, r5 */
/* @0x18fb90 ldr r3, [r4] */
/* @0x18fb94 str r3, [sp, #0x804] */
/* @0x18fb98 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x18fb9c ldr r1, [pc, #0x40] */
/* @0x18fba0 mov r0, r5 */
/* @0x18fba4 add r1, pc, r1 */
/* @0x18fba8 bl 0xb6844 <fopen@plt> */
/* @0x18fbac subs r5, r0, #0 */
/* @0x18fbb0 beq 0x18fbb8 <_ZN8LoadSave14SaveFileExistsEPKc+0x4c> */
/* @0x18fbb4 bl 0xb6850 <fclose@plt> */
/* @0x18fbb8 ldr r2, [sp, #0x804] */
/* @0x18fbbc adds r0, r5, #0 */
/* @0x18fbc0 ldr r3, [r4] */
/* @0x18fbc4 movne r0, #1 */
/* @0x18fbc8 cmp r2, r3 */
/* @0x18fbcc bne 0x18fbdc <_ZN8LoadSave14SaveFileExistsEPKc+0x70> */
/* @0x18fbd0 add sp, sp, #2048 */
/* @0x18fbd4 add sp, sp, #12 */
/* @0x18fbd8 pop {r4, r5, pc} */
/* @0x18fbdc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x18fbe0 eoreq sp, r5, r12, asr #27 */
/* @0x18fbe4 andseq r8, r10, r4, asr r0 */

/* ── FUNC 0x18fbe8 · LoadSave::GetSaveFileSize(char const*) · size=92 · insn=23 */
/* @0x18fbe8 push {r4, r5, lr} */
/* @0x18fbec sub sp, sp, #2048 */
/* @0x18fbf0 ldr r4, [pc, #0x48] */
/* @0x18fbf4 sub sp, sp, #12 */
/* @0x18fbf8 add r5, sp, #4 */
/* @0x18fbfc mov r2, r0 */
/* @0x18fc00 ldr r4, [pc, r4] */
/* @0x18fc04 mov r1, #2048 */
/* @0x18fc08 mov r0, r5 */
/* @0x18fc0c ldr r3, [r4] */
/* @0x18fc10 str r3, [sp, #0x804] */
/* @0x18fc14 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x18fc18 mov r0, r5 */
/* @0x18fc1c bl 0x18f734 <_ZN8LoadSave8_GetSizeEPKc> */
/* @0x18fc20 ldr r2, [sp, #0x804] */
/* @0x18fc24 ldr r3, [r4] */
/* @0x18fc28 cmp r2, r3 */
/* @0x18fc2c bne 0x18fc3c <_ZN8LoadSave15GetSaveFileSizeEPKc+0x54> */
/* @0x18fc30 add sp, sp, #2048 */
/* @0x18fc34 add sp, sp, #12 */
/* @0x18fc38 pop {r4, r5, pc} */
/* @0x18fc3c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x18fc40 eoreq sp, r5, r0, asr sp */

/* ── FUNC 0x18fc44 · LoadSave::_ExpandCompressedFile(char const*, char const*, char*, int, int) · size=36 · insn=9 */
/* @0x18fc44 str r4, [sp, #-0x4]! */
/* @0x18fc48 mov r4, r0 */
/* @0x18fc4c ldr r12, [sp, #0x4] */
/* @0x18fc50 mov r0, r1 */
/* @0x18fc54 str r2, [sp, #0x4] */
/* @0x18fc58 mov r1, r4 */
/* @0x18fc5c ldr r4, [sp], #4 */
/* @0x18fc60 mov r2, r12 */
/* @0x18fc64 b 0x1ca040 <_Z13Command_UnzipPKcS0_iiPc> */

/* ── FUNC 0x18fc68 · LoadSave::HTTP_Get(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*) · size=152 · insn=38 */
/* @0x18fc68 push {r4, r5, r6, r7, r8, lr} */
/* @0x18fc6c sub sp, sp, #16 */
/* @0x18fc70 mov r4, r0 */
/* @0x18fc74 mov r0, #68 */
/* @0x18fc78 mov r7, r2 */
/* @0x18fc7c mov r8, r3 */
/* @0x18fc80 ldr r6, [sp, #0x28] */
/* @0x18fc84 bl 0x27c524 <_Znwj> */
/* @0x18fc88 mov r12, #0 */
/* @0x18fc8c mov r2, #131072 */
/* @0x18fc90 str r12, [sp, #0x8] */
/* @0x18fc94 mov r3, r7 */
/* @0x18fc98 mov r1, r4 */
/* @0x18fc9c str r8, [sp] */
/* @0x18fca0 str r6, [sp, #0x4] */
/* @0x18fca4 mov r5, r0 */
/* @0x18fca8 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0x18fcac bl 0x290274 <getJNIEnv> */
/* @0x18fcb0 mov r1, r4 */
/* @0x18fcb4 ldr r3, [r0] */
/* @0x18fcb8 ldr r3, [r3, #0x29c] */
/* @0x18fcbc blx r3 */
/* @0x18fcc0 mov r4, r0 */
/* @0x18fcc4 bl 0x290274 <getJNIEnv> */
/* @0x18fcc8 ldr r1, [pc, #0x28] */
/* @0x18fccc mov r3, r4 */
/* @0x18fcd0 ldr r2, [pc, #0x24] */
/* @0x18fcd4 ldr r12, [r5, #0x24] */
/* @0x18fcd8 ldr r1, [pc, r1] */
/* @0x18fcdc ldr r2, [pc, r2] */
/* @0x18fce0 ldr r1, [r1] */
/* @0x18fce4 ldr r2, [r2] */
/* @0x18fce8 str r12, [sp, #0x28] */
/* @0x18fcec add sp, sp, #16 */
/* @0x18fcf0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x18fcf4 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x18fcf8 eoreq sp, r5, r12, asr #25 */
/* @0x18fcfc eoreq r0, r6, r0, lsl #19 */

/* ── FUNC 0x18fd00 · LoadSave::HTTP_Post(char const*, char const*, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*) · size=184 · insn=46 */
/* @0x18fd00 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18fd04 sub sp, sp, #20 */
/* @0x18fd08 mov r4, r0 */
/* @0x18fd0c mov r0, #68 */
/* @0x18fd10 ldr r5, [sp, #0x30] */
/* @0x18fd14 mov r8, r2 */
/* @0x18fd18 mov r7, r1 */
/* @0x18fd1c mov r9, r3 */
/* @0x18fd20 bl 0x27c524 <_Znwj> */
/* @0x18fd24 mov r12, #0 */
/* @0x18fd28 mov r2, #131072 */
/* @0x18fd2c str r12, [sp, #0x8] */
/* @0x18fd30 mov r3, r8 */
/* @0x18fd34 mov r1, r4 */
/* @0x18fd38 str r5, [sp, #0x4] */
/* @0x18fd3c str r9, [sp] */
/* @0x18fd40 mov r6, r0 */
/* @0x18fd44 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0x18fd48 bl 0x290274 <getJNIEnv> */
/* @0x18fd4c mov r1, r4 */
/* @0x18fd50 ldr r3, [r0] */
/* @0x18fd54 ldr r3, [r3, #0x29c] */
/* @0x18fd58 blx r3 */
/* @0x18fd5c mov r5, r0 */
/* @0x18fd60 bl 0x290274 <getJNIEnv> */
/* @0x18fd64 mov r1, r7 */
/* @0x18fd68 ldr r3, [r0] */
/* @0x18fd6c ldr r3, [r3, #0x29c] */
/* @0x18fd70 blx r3 */
/* @0x18fd74 mov r4, r0 */
/* @0x18fd78 bl 0x290274 <getJNIEnv> */
/* @0x18fd7c ldr r1, [pc, #0x2c] */
/* @0x18fd80 mov r3, r5 */
/* @0x18fd84 ldr r2, [pc, #0x28] */
/* @0x18fd88 ldr r1, [pc, r1] */
/* @0x18fd8c ldr r2, [pc, r2] */
/* @0x18fd90 ldr r1, [r1] */
/* @0x18fd94 ldr r2, [r2] */
/* @0x18fd98 str r4, [sp] */
/* @0x18fd9c ldr r12, [r6, #0x24] */
/* @0x18fda0 str r12, [sp, #0x4] */
/* @0x18fda4 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x18fda8 add sp, sp, #20 */
/* @0x18fdac pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18fdb0 eoreq sp, r5, r12, lsl r12 */
/* @0x18fdb4 .word 0x002608d4 */

/* ── FUNC 0x18fdb8 · LoadSave::HTTP_Request(char const*, char const*, char const*, char const*, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, int) · size=504 · insn=126 */
/* @0x18fdb8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18fdbc add r11, sp, #32 */
/* @0x18fdc0 sub sp, sp, #36 */
/* @0x18fdc4 mov r6, r0 */
/* @0x18fdc8 mov r0, #68 */
/* @0x18fdcc ldr lr, [r11, #0xc] */
/* @0x18fdd0 mov r9, r1 */
/* @0x18fdd4 ldr r12, [r11, #0x8] */
/* @0x18fdd8 mov r8, r2 */
/* @0x18fddc ldr r10, [r11, #0x4] */
/* @0x18fde0 mov r5, r3 */
/* @0x18fde4 str lr, [r11, #-0x28] */
/* @0x18fde8 ldr r4, [r11, #0x10] */
/* @0x18fdec str r12, [r11, #-0x30] */
/* @0x18fdf0 bl 0x27c524 <_Znwj> */
/* @0x18fdf4 ldr r12, [r11, #-0x30] */
/* @0x18fdf8 mov r3, r10 */
/* @0x18fdfc mov r1, r6 */
/* @0x18fe00 ldr r10, [pc, #0x19c] */
/* @0x18fe04 str r12, [sp] */
/* @0x18fe08 mov r12, #0 */
/* @0x18fe0c ldr r2, [r11, #-0x28] */
/* @0x18fe10 add r10, pc, r10 */
/* @0x18fe14 str r12, [sp, #0x8] */
/* @0x18fe18 str r2, [sp, #0x4] */
/* @0x18fe1c mov r2, #131072 */
/* @0x18fe20 mov r7, r0 */
/* @0x18fe24 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0x18fe28 bl 0x290274 <getJNIEnv> */
/* @0x18fe2c mov r1, r6 */
/* @0x18fe30 ldr r3, [r0] */
/* @0x18fe34 ldr r3, [r3, #0x29c] */
/* @0x18fe38 blx r3 */
/* @0x18fe3c str r0, [r11, #-0x28] */
/* @0x18fe40 bl 0x290274 <getJNIEnv> */
/* @0x18fe44 mov r1, r9 */
/* @0x18fe48 ldr r3, [r0] */
/* @0x18fe4c ldr r3, [r3, #0x29c] */
/* @0x18fe50 blx r3 */
/* @0x18fe54 mov r9, r0 */
/* @0x18fe58 bl 0x290274 <getJNIEnv> */
/* @0x18fe5c mov r1, r8 */
/* @0x18fe60 ldr r3, [r0] */
/* @0x18fe64 ldr r3, [r3, #0x29c] */
/* @0x18fe68 blx r3 */
/* @0x18fe6c adds r3, r5, #0 */
/* @0x18fe70 movne r3, #1 */
/* @0x18fe74 cmn r4, #1 */
/* @0x18fe78 movne r3, #0 */
/* @0x18fe7c cmp r3, #0 */
/* @0x18fe80 mov r8, r0 */
/* @0x18fe84 beq 0x18fe94 <_ZN8LoadSave12HTTP_RequestEPKcS1_S1_S1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_i+0xdc> */
/* @0x18fe88 mov r0, r5 */
/* @0x18fe8c bl 0xb6538 <strlen@plt> */
/* @0x18fe90 mov r4, r0 */
/* @0x18fe94 cmp r4, #0 */
/* @0x18fe98 ble 0x18ff60 <_ZN8LoadSave12HTTP_RequestEPKcS1_S1_S1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_i+0x1a8> */
/* @0x18fe9c add r2, r4, #7 */
/* @0x18fea0 str sp, [r11, #-0x2c] */
/* @0x18fea4 bic r2, r2, #7 */
/* @0x18fea8 mov r6, #0 */
/* @0x18feac sub sp, sp, r2 */
/* @0x18feb0 add r12, sp, #16 */
/* @0x18feb4 ldrb r2, [r5, r6] */
/* @0x18feb8 strb r2, [r12, r6] */
/* @0x18febc add r6, r6, #1 */
/* @0x18fec0 cmp r6, r4 */
/* @0x18fec4 bne 0x18feb4 <_ZN8LoadSave12HTTP_RequestEPKcS1_S1_S1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_i+0xfc> */
/* @0x18fec8 str r12, [r11, #-0x30] */
/* @0x18fecc bl 0x290274 <getJNIEnv> */
/* @0x18fed0 mov r1, r6 */
/* @0x18fed4 ldr r2, [r0] */
/* @0x18fed8 ldr r2, [r2, #0x2c0] */
/* @0x18fedc blx r2 */
/* @0x18fee0 mov r4, r0 */
/* @0x18fee4 bl 0x290274 <getJNIEnv> */
/* @0x18fee8 ldr r12, [r11, #-0x30] */
/* @0x18feec mov r3, r6 */
/* @0x18fef0 mov r1, r4 */
/* @0x18fef4 mov r2, #0 */
/* @0x18fef8 ldr lr, [r0] */
/* @0x18fefc str r12, [sp] */
/* @0x18ff00 ldr r12, [lr, #0x340] */
/* @0x18ff04 blx r12 */
/* @0x18ff08 bl 0x290274 <getJNIEnv> */
/* @0x18ff0c ldr r1, [pc, #0x94] */
/* @0x18ff10 ldr r2, [pc, #0x94] */
/* @0x18ff14 ldr r3, [r11, #-0x28] */
/* @0x18ff18 ldr r1, [r10, r1] */
/* @0x18ff1c ldr r2, [r10, r2] */
/* @0x18ff20 ldr r1, [r1] */
/* @0x18ff24 ldr r2, [r2] */
/* @0x18ff28 str r4, [sp, #0x8] */
/* @0x18ff2c str r9, [sp] */
/* @0x18ff30 str r8, [sp, #0x4] */
/* @0x18ff34 ldr r12, [r7, #0x24] */
/* @0x18ff38 str r12, [sp, #0xc] */
/* @0x18ff3c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x18ff40 bl 0x290274 <getJNIEnv> */
/* @0x18ff44 mov r1, r4 */
/* @0x18ff48 ldr r3, [r0] */
/* @0x18ff4c ldr r3, [r3, #0x5c] */
/* @0x18ff50 blx r3 */
/* @0x18ff54 ldr sp, [r11, #-0x2c] */
/* @0x18ff58 sub sp, r11, #32 */
/* @0x18ff5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x18ff60 bl 0x290274 <getJNIEnv> */
/* @0x18ff64 ldr r1, [pc, #0x3c] */
/* @0x18ff68 ldr r2, [pc, #0x3c] */
/* @0x18ff6c mov r12, #0 */
/* @0x18ff70 ldr r3, [r11, #-0x28] */
/* @0x18ff74 ldr r1, [r10, r1] */
/* @0x18ff78 ldr r2, [r10, r2] */
/* @0x18ff7c str r9, [r11, #0x4] */
/* @0x18ff80 ldr r1, [r1] */
/* @0x18ff84 ldr r2, [r2] */
/* @0x18ff88 str r8, [r11, #0x8] */
/* @0x18ff8c str r12, [r11, #0xc] */
/* @0x18ff90 ldr r12, [r7, #0x24] */
/* @0x18ff94 str r12, [r11, #0x10] */
/* @0x18ff98 sub sp, r11, #32 */
/* @0x18ff9c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18ffa0 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x18ffa4 eoreq r1, r6, r0, asr #28 */
/* @0x18ffa8 .word 0xffffbd54 */
/* @0x18ffac .word 0xffffea14 */

/* ── FUNC 0x18ffb0 · LoadSave::RemoveSaveFile(char const*) · size=100 · insn=25 */
/* @0x18ffb0 push {r4, r5, lr} */
/* @0x18ffb4 sub sp, sp, #2048 */
/* @0x18ffb8 ldr r4, [pc, #0x50] */
/* @0x18ffbc sub sp, sp, #12 */
/* @0x18ffc0 add r5, sp, #4 */
/* @0x18ffc4 mov r2, r0 */
/* @0x18ffc8 ldr r4, [pc, r4] */
/* @0x18ffcc mov r1, #2048 */
/* @0x18ffd0 mov r0, r5 */
/* @0x18ffd4 ldr r3, [r4] */
/* @0x18ffd8 str r3, [sp, #0x804] */
/* @0x18ffdc bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x18ffe0 mov r0, r5 */
/* @0x18ffe4 bl 0xb6970 <remove@plt> */
/* @0x18ffe8 ldr r2, [sp, #0x804] */
/* @0x18ffec ldr r3, [r4] */
/* @0x18fff0 rsbs r0, r0, #1 */
/* @0x18fff4 movlo r0, #0 */
/* @0x18fff8 cmp r2, r3 */
/* @0x18fffc bne 0x19000c <_ZN8LoadSave14RemoveSaveFileEPKc+0x5c> */
/* @0x190000 add sp, sp, #2048 */
/* @0x190004 add sp, sp, #12 */
/* @0x190008 pop {r4, r5, pc} */
/* @0x19000c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x190010 eoreq sp, r5, r8, lsl #19 */

/* ── FUNC 0x190014 · GamepadInitM() · size=448 · insn=112 */
/* @0x190014 push {r4, r5, r6, lr} */
/* @0x190018 ldr r4, [pc, #0x178] */
/* @0x19001c add r4, pc, r4 */
/* @0x190020 ldr r3, [r4] */
/* @0x190024 tst r3, #1 */
/* @0x190028 beq 0x190150 <_Z12GamepadInitMv+0x13c> */
/* @0x19002c tst r3, #2 */
/* @0x190030 popne {r4, r5, r6, pc} */
/* @0x190034 bl 0x290274 <getJNIEnv> */
/* @0x190038 cmp r0, #0 */
/* @0x19003c popeq {r4, r5, r6, pc} */
/* @0x190040 bl 0x290274 <getJNIEnv> */
/* @0x190044 ldr r5, [pc, #0x150] */
/* @0x190048 ldr r2, [pc, #0x150] */
/* @0x19004c ldr r5, [pc, r5] */
/* @0x190050 ldr r3, [pc, #0x14c] */
/* @0x190054 add r2, pc, r2 */
/* @0x190058 ldr r4, [pc, #0x148] */
/* @0x19005c add r3, pc, r3 */
/* @0x190060 ldr r1, [r5] */
/* @0x190064 add r4, pc, r4 */
/* @0x190068 ldr r6, [pc, #0x13c] */
/* @0x19006c add r6, pc, r6 */
/* @0x190070 ldr r12, [r0] */
/* @0x190074 ldr r12, [r12, #0x1c4] */
/* @0x190078 blx r12 */
/* @0x19007c str r0, [r4, #0x4] */
/* @0x190080 bl 0x290274 <getJNIEnv> */
/* @0x190084 ldr r2, [pc, #0x124] */
/* @0x190088 ldr r3, [pc, #0x124] */
/* @0x19008c ldr r1, [r5] */
/* @0x190090 add r2, pc, r2 */
/* @0x190094 add r3, pc, r3 */
/* @0x190098 ldr r12, [r0] */
/* @0x19009c ldr r12, [r12, #0x1c4] */
/* @0x1900a0 blx r12 */
/* @0x1900a4 str r0, [r4, #0x8] */
/* @0x1900a8 bl 0x290274 <getJNIEnv> */
/* @0x1900ac ldr r2, [pc, #0x104] */
/* @0x1900b0 ldr r3, [pc, #0x104] */
/* @0x1900b4 ldr r1, [r5] */
/* @0x1900b8 add r2, pc, r2 */
/* @0x1900bc add r3, pc, r3 */
/* @0x1900c0 ldr r12, [r0] */
/* @0x1900c4 ldr r12, [r12, #0x1c4] */
/* @0x1900c8 blx r12 */
/* @0x1900cc str r0, [r4, #0xc] */
/* @0x1900d0 bl 0x290274 <getJNIEnv> */
/* @0x1900d4 ldr r2, [pc, #0xe4] */
/* @0x1900d8 mov r3, r6 */
/* @0x1900dc ldr r1, [r5] */
/* @0x1900e0 add r2, pc, r2 */
/* @0x1900e4 ldr r12, [r0] */
/* @0x1900e8 ldr r12, [r12, #0x1c4] */
/* @0x1900ec blx r12 */
/* @0x1900f0 str r0, [r4, #0x10] */
/* @0x1900f4 bl 0x290274 <getJNIEnv> */
/* @0x1900f8 ldr r2, [pc, #0xc4] */
/* @0x1900fc mov r3, r6 */
/* @0x190100 ldr r1, [r5] */
/* @0x190104 add r2, pc, r2 */
/* @0x190108 ldr r12, [r0] */
/* @0x19010c ldr r12, [r12, #0x1c4] */
/* @0x190110 blx r12 */
/* @0x190114 str r0, [r4, #0x14] */
/* @0x190118 bl 0x290274 <getJNIEnv> */
/* @0x19011c ldr r2, [pc, #0xa4] */
/* @0x190120 ldr r3, [pc, #0xa4] */
/* @0x190124 ldr r1, [r5] */
/* @0x190128 add r2, pc, r2 */
/* @0x19012c add r3, pc, r3 */
/* @0x190130 ldr r12, [r0] */
/* @0x190134 ldr r12, [r12, #0x1c4] */
/* @0x190138 blx r12 */
/* @0x19013c ldr r3, [r4] */
/* @0x190140 orr r3, r3, #2 */
/* @0x190144 str r3, [r4] */
/* @0x190148 str r0, [r4, #0x18] */
/* @0x19014c pop {r4, r5, r6, pc} */
/* @0x190150 mov r0, #1 */
/* @0x190154 orr r3, r3, r0 */
/* @0x190158 str r3, [r4] */
/* @0x19015c bl 0x18e4a4 <_ZN9GMGamePad15SetGamePadCountEi> */
/* @0x190160 ldr r3, [pc, #0x68] */
/* @0x190164 mov r0, #556 */
/* @0x190168 ldr r3, [pc, r3] */
/* @0x19016c ldr r5, [r3] */
/* @0x190170 bl 0x27c524 <_Znwj> */
/* @0x190174 mov r1, #8 */
/* @0x190178 mov r2, #2 */
/* @0x19017c mov r6, r0 */
/* @0x190180 bl 0x18e9d4 <_ZN9GMGamePadC2Eii> */
/* @0x190184 ldr r3, [r4] */
/* @0x190188 str r6, [r5] */
/* @0x19018c tst r3, #2 */
/* @0x190190 popne {r4, r5, r6, pc} */
/* @0x190194 b 0x190034 <_Z12GamepadInitMv+0x20> */
/* @0x190198 eorseq r5, r10, r12, lsl #16 */
/* @0x19019c eoreq sp, r5, r8, asr r9 */
/* @0x1901a0 mulseq r11, r4, r4 */
/* @0x1901a4 mulseq r11, r12, r4 */
/* @0x1901a8 eorseq r5, r10, r4, asr #15 */
/* @0x1901ac andseq r12, r11, r12, ror #9 */
/* @0x1901b0 andseq r12, r11, r12, ror #8 */
/* @0x1901b4 andseq r12, r11, r12, ror r4 */
/* @0x1901b8 andseq r12, r11, r0, ror #8 */
/* @0x1901bc andseq r12, r11, r0, ror r4 */
/* @0x1901c0 andseq r12, r11, r4, ror #8 */
/* @0x1901c4 andseq r12, r11, r12, asr r4 */
/* @0x1901c8 andseq r12, r11, r12, asr #8 */
/* @0x1901cc andseq r12, r11, r12, asr r4 */
/* @0x1901d0 .word 0x0025f8fc */

/* ── FUNC 0x1901d4 · SetupGMLMappings(int) · size=700 · insn=175 */
/* @0x1901d4 cmp r0, #63 */
/* @0x1901d8 push {r4, r5, r6, r7, lr} */
/* @0x1901dc mov r4, r0 */
/* @0x1901e0 sub sp, sp, #12 */
/* @0x1901e4 bgt 0x190480 <_Z16SetupGMLMappingsi+0x2ac> */
/* @0x1901e8 ldr r5, [pc, #0x298] */
/* @0x1901ec bl 0x290274 <getJNIEnv> */
/* @0x1901f0 ldr r6, [pc, #0x294] */
/* @0x1901f4 movw r12, #0x8001 */
/* @0x1901f8 ldr r5, [pc, r5] */
/* @0x1901fc mov r3, r4 */
/* @0x190200 add r6, pc, r6 */
/* @0x190204 mov r7, #84 */
/* @0x190208 ldr r1, [r5] */
/* @0x19020c ldr r2, [r6, #0x18] */
/* @0x190210 str r12, [sp] */
/* @0x190214 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x190218 mla r7, r7, r4, r6 */
/* @0x19021c str r0, [r7, #0x20] */
/* @0x190220 bl 0x290274 <getJNIEnv> */
/* @0x190224 ldr r1, [r5] */
/* @0x190228 movw r12, #0x8002 */
/* @0x19022c ldr r2, [r6, #0x18] */
/* @0x190230 mov r3, r4 */
/* @0x190234 str r12, [sp] */
/* @0x190238 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19023c str r0, [r7, #0x24] */
/* @0x190240 bl 0x290274 <getJNIEnv> */
/* @0x190244 ldr r1, [r5] */
/* @0x190248 movw r12, #0x8003 */
/* @0x19024c ldr r2, [r6, #0x18] */
/* @0x190250 mov r3, r4 */
/* @0x190254 str r12, [sp] */
/* @0x190258 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19025c str r0, [r7, #0x28] */
/* @0x190260 bl 0x290274 <getJNIEnv> */
/* @0x190264 ldr r1, [r5] */
/* @0x190268 movw r12, #0x8004 */
/* @0x19026c ldr r2, [r6, #0x18] */
/* @0x190270 mov r3, r4 */
/* @0x190274 str r12, [sp] */
/* @0x190278 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19027c str r0, [r7, #0x2c] */
/* @0x190280 bl 0x290274 <getJNIEnv> */
/* @0x190284 ldr r1, [r5] */
/* @0x190288 movw r12, #0x8005 */
/* @0x19028c ldr r2, [r6, #0x18] */
/* @0x190290 mov r3, r4 */
/* @0x190294 str r12, [sp] */
/* @0x190298 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19029c str r0, [r7, #0x30] */
/* @0x1902a0 bl 0x290274 <getJNIEnv> */
/* @0x1902a4 ldr r1, [r5] */
/* @0x1902a8 movw r12, #0x8006 */
/* @0x1902ac ldr r2, [r6, #0x18] */
/* @0x1902b0 mov r3, r4 */
/* @0x1902b4 str r12, [sp] */
/* @0x1902b8 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x1902bc str r0, [r7, #0x34] */
/* @0x1902c0 bl 0x290274 <getJNIEnv> */
/* @0x1902c4 ldr r1, [r5] */
/* @0x1902c8 movw r12, #0x8007 */
/* @0x1902cc ldr r2, [r6, #0x18] */
/* @0x1902d0 mov r3, r4 */
/* @0x1902d4 str r12, [sp] */
/* @0x1902d8 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x1902dc str r0, [r7, #0x38] */
/* @0x1902e0 bl 0x290274 <getJNIEnv> */
/* @0x1902e4 ldr r1, [r5] */
/* @0x1902e8 movw r12, #0x8008 */
/* @0x1902ec ldr r2, [r6, #0x18] */
/* @0x1902f0 mov r3, r4 */
/* @0x1902f4 str r12, [sp] */
/* @0x1902f8 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x1902fc str r0, [r7, #0x3c] */
/* @0x190300 bl 0x290274 <getJNIEnv> */
/* @0x190304 ldr r1, [r5] */
/* @0x190308 movw r12, #0x8009 */
/* @0x19030c ldr r2, [r6, #0x18] */
/* @0x190310 mov r3, r4 */
/* @0x190314 str r12, [sp] */
/* @0x190318 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19031c str r0, [r7, #0x40] */
/* @0x190320 bl 0x290274 <getJNIEnv> */
/* @0x190324 ldr r1, [r5] */
/* @0x190328 movw r12, #0x800a */
/* @0x19032c ldr r2, [r6, #0x18] */
/* @0x190330 mov r3, r4 */
/* @0x190334 str r12, [sp] */
/* @0x190338 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19033c str r0, [r7, #0x44] */
/* @0x190340 bl 0x290274 <getJNIEnv> */
/* @0x190344 ldr r1, [r5] */
/* @0x190348 movw r12, #0x800b */
/* @0x19034c ldr r2, [r6, #0x18] */
/* @0x190350 mov r3, r4 */
/* @0x190354 str r12, [sp] */
/* @0x190358 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19035c str r0, [r7, #0x48] */
/* @0x190360 bl 0x290274 <getJNIEnv> */
/* @0x190364 ldr r1, [r5] */
/* @0x190368 movw r12, #0x800c */
/* @0x19036c ldr r2, [r6, #0x18] */
/* @0x190370 mov r3, r4 */
/* @0x190374 str r12, [sp] */
/* @0x190378 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19037c str r0, [r7, #0x4c] */
/* @0x190380 bl 0x290274 <getJNIEnv> */
/* @0x190384 ldr r1, [r5] */
/* @0x190388 movw r12, #0x800d */
/* @0x19038c ldr r2, [r6, #0x18] */
/* @0x190390 mov r3, r4 */
/* @0x190394 str r12, [sp] */
/* @0x190398 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19039c str r0, [r7, #0x50] */
/* @0x1903a0 bl 0x290274 <getJNIEnv> */
/* @0x1903a4 ldr r1, [r5] */
/* @0x1903a8 movw r12, #0x800e */
/* @0x1903ac ldr r2, [r6, #0x18] */
/* @0x1903b0 mov r3, r4 */
/* @0x1903b4 str r12, [sp] */
/* @0x1903b8 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x1903bc str r0, [r7, #0x54] */
/* @0x1903c0 bl 0x290274 <getJNIEnv> */
/* @0x1903c4 ldr r1, [r5] */
/* @0x1903c8 movw r12, #0x800f */
/* @0x1903cc ldr r2, [r6, #0x18] */
/* @0x1903d0 mov r3, r4 */
/* @0x1903d4 str r12, [sp] */
/* @0x1903d8 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x1903dc str r0, [r7, #0x58] */
/* @0x1903e0 bl 0x290274 <getJNIEnv> */
/* @0x1903e4 ldr r1, [r5] */
/* @0x1903e8 movw r12, #0x8010 */
/* @0x1903ec ldr r2, [r6, #0x18] */
/* @0x1903f0 mov r3, r4 */
/* @0x1903f4 str r12, [sp] */
/* @0x1903f8 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x1903fc str r0, [r7, #0x5c] */
/* @0x190400 bl 0x290274 <getJNIEnv> */
/* @0x190404 ldr r1, [r5] */
/* @0x190408 movw r12, #0x8011 */
/* @0x19040c ldr r2, [r6, #0x18] */
/* @0x190410 mov r3, r4 */
/* @0x190414 str r12, [sp] */
/* @0x190418 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19041c str r0, [r7, #0x60] */
/* @0x190420 bl 0x290274 <getJNIEnv> */
/* @0x190424 ldr r1, [r5] */
/* @0x190428 movw r12, #0x8012 */
/* @0x19042c ldr r2, [r6, #0x18] */
/* @0x190430 mov r3, r4 */
/* @0x190434 str r12, [sp] */
/* @0x190438 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19043c str r0, [r7, #0x64] */
/* @0x190440 bl 0x290274 <getJNIEnv> */
/* @0x190444 ldr r1, [r5] */
/* @0x190448 movw r12, #0x8013 */
/* @0x19044c ldr r2, [r6, #0x18] */
/* @0x190450 mov r3, r4 */
/* @0x190454 str r12, [sp] */
/* @0x190458 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19045c str r0, [r7, #0x68] */
/* @0x190460 bl 0x290274 <getJNIEnv> */
/* @0x190464 ldr r1, [r5] */
/* @0x190468 movw r12, #0x8014 */
/* @0x19046c ldr r2, [r6, #0x18] */
/* @0x190470 mov r3, r4 */
/* @0x190474 str r12, [sp] */
/* @0x190478 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x19047c str r0, [r7, #0x6c] */
/* @0x190480 add sp, sp, #12 */
/* @0x190484 pop {r4, r5, r6, r7, pc} */
/* @0x190488 eoreq sp, r5, r12, lsr #15 */
/* @0x19048c eorseq r5, r10, r8, lsr #12 */

/* ── FUNC 0x190490 · anon_190490 · size=996 · insn=249 */
/* @0x190490 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x190494 add r11, sp, #32 */
/* @0x190498 ldr r7, [pc, #0x3a0] */
/* @0x19049c sub sp, sp, #52 */
/* @0x1904a0 ldr r2, [pc, #0x39c] */
/* @0x1904a4 add r7, pc, r7 */
/* @0x1904a8 ldr r3, [pc, #0x398] */
/* @0x1904ac ldr r2, [r7, r2] */
/* @0x1904b0 add r3, pc, r3 */
/* @0x1904b4 str r2, [r11, #-0x38] */
/* @0x1904b8 ldr r12, [r11, #-0x38] */
/* @0x1904bc ldr r2, [r3] */
/* @0x1904c0 ldr r3, [r12] */
/* @0x1904c4 tst r2, #2 */
/* @0x1904c8 str r3, [r11, #-0x28] */
/* @0x1904cc beq 0x1907e0 <_Z16SetupGMLMappingsi+0x60c> */
/* @0x1904d0 ldr r3, [pc, #0x374] */
/* @0x1904d4 ldr r3, [r7, r3] */
/* @0x1904d8 ldr r3, [r3] */
/* @0x1904dc cmp r3, #0 */
/* @0x1904e0 str r3, [r11, #-0x34] */
/* @0x1904e4 ble 0x1907e0 <_Z16SetupGMLMappingsi+0x60c> */
/* @0x1904e8 ldr r12, [pc, #0x360] */
/* @0x1904ec mov r4, #0 */
/* @0x1904f0 ldr r8, [pc, #0x35c] */
/* @0x1904f4 add r12, pc, r12 */
/* @0x1904f8 str r12, [r11, #-0x48] */
/* @0x1904fc ldr r12, [pc, #0x354] */
/* @0x190500 add r8, pc, r8 */
/* @0x190504 add r12, pc, r12 */
/* @0x190508 str r12, [r11, #-0x4c] */
/* @0x19050c ldr r12, [pc, #0x348] */
/* @0x190510 add r12, pc, r12 */
/* @0x190514 str r12, [r11, #-0x3c] */
/* @0x190518 ldr r12, [pc, #0x340] */
/* @0x19051c add r12, pc, r12 */
/* @0x190520 str r12, [r11, #-0x40] */
/* @0x190524 ldr r12, [pc, #0x338] */
/* @0x190528 add r12, pc, r12 */
/* @0x19052c str r12, [r11, #-0x44] */
/* @0x190530 ldr r12, [r11, #-0x34] */
/* @0x190534 add r4, r4, #1 */
/* @0x190538 cmp r4, r12 */
/* @0x19053c beq 0x1907e0 <_Z16SetupGMLMappingsi+0x60c> */
/* @0x190540 cmp r4, #0 */
/* @0x190544 beq 0x190530 <_Z16SetupGMLMappingsi+0x35c> */
/* @0x190548 bl 0x290274 <getJNIEnv> */
/* @0x19054c ldr r1, [pc, #0x314] */
/* @0x190550 mov r3, r4 */
/* @0x190554 ldr r2, [r8, #0x8] */
/* @0x190558 lsl r9, r4, #2 */
/* @0x19055c ldr r1, [r7, r1] */
/* @0x190560 str r1, [r11, #-0x30] */
/* @0x190564 ldr r1, [r1] */
/* @0x190568 bl 0x15e0b0 <_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz> */
/* @0x19056c ldr r3, [pc, #0x2f8] */
/* @0x190570 ldr r12, [r7, r3] */
/* @0x190574 ldr r3, [r12] */
/* @0x190578 ldr r5, [r3, r4, lsl #2] */
/* @0x19057c cmp r5, #0 */
/* @0x190580 mov r6, r0 */
/* @0x190584 beq 0x190530 <_Z16SetupGMLMappingsi+0x35c> */
/* @0x190588 ldrb r3, [r5] */
/* @0x19058c cmp r3, r0 */
/* @0x190590 beq 0x190668 <_Z16SetupGMLMappingsi+0x494> */
/* @0x190594 cmp r0, #0 */
/* @0x190598 beq 0x1907fc <_Z16SetupGMLMappingsi+0x628> */
/* @0x19059c ldr r0, [pc, #0x2cc] */
/* @0x1905a0 mov r2, r4 */
/* @0x1905a4 ldr r1, [r11, #-0x44] */
/* @0x1905a8 add r3, r5, #44 */
/* @0x1905ac ldr r0, [r7, r0] */
/* @0x1905b0 ldr r0, [r0] */
/* @0x1905b4 ldr lr, [r0] */
/* @0x1905b8 ldr r10, [lr, #0xc] */
/* @0x1905bc str r12, [r11, #-0x50] */
/* @0x1905c0 blx r10 */
/* @0x1905c4 mov r0, r4 */
/* @0x1905c8 bl 0x1901d4 <_Z16SetupGMLMappingsi> */
/* @0x1905cc bl 0x290274 <getJNIEnv> */
/* @0x1905d0 ldr r3, [r11, #-0x30] */
/* @0x1905d4 ldr r2, [r8, #0xc] */
/* @0x1905d8 ldr r1, [r3] */
/* @0x1905dc mov r3, r4 */
/* @0x1905e0 bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz> */
/* @0x1905e4 mov r10, r0 */
/* @0x1905e8 bl 0x290274 <getJNIEnv> */
/* @0x1905ec mov r1, r10 */
/* @0x1905f0 mov r2, #0 */
/* @0x1905f4 ldr r3, [r0] */
/* @0x1905f8 ldr r3, [r3, #0x2a4] */
/* @0x1905fc blx r3 */
/* @0x190600 ldr r12, [r11, #-0x50] */
/* @0x190604 ldr r3, [r12] */
/* @0x190608 mov r2, r0 */
/* @0x19060c mov r1, r0 */
/* @0x190610 ldr r0, [r3, r9] */
/* @0x190614 str r2, [r11, #-0x50] */
/* @0x190618 bl 0x18e944 <_ZN9GMGamePad11SetDeviceIdEPKc> */
/* @0x19061c ldr r2, [r11, #-0x50] */
/* @0x190620 cmp r2, #0 */
/* @0x190624 cmpne r10, #0 */
/* @0x190628 beq 0x190658 <_Z16SetupGMLMappingsi+0x484> */
/* @0x19062c bl 0x290274 <getJNIEnv> */
/* @0x190630 mov r1, r10 */
/* @0x190634 ldr r2, [r11, #-0x50] */
/* @0x190638 ldr r3, [r0] */
/* @0x19063c ldr r3, [r3, #0x2a8] */
/* @0x190640 blx r3 */
/* @0x190644 bl 0x290274 <getJNIEnv> */
/* @0x190648 mov r1, r10 */
/* @0x19064c ldr r3, [r0] */
/* @0x190650 ldr r3, [r3, #0x5c] */
/* @0x190654 blx r3 */
/* @0x190658 adds r1, r6, #0 */
/* @0x19065c mov r0, r5 */
/* @0x190660 movne r1, #1 */
/* @0x190664 bl 0x18e7f4 <_ZN9GMGamePad12SetConnectedEb> */
/* @0x190668 cmp r6, #0 */
/* @0x19066c beq 0x190530 <_Z16SetupGMLMappingsi+0x35c> */
/* @0x190670 bl 0x290274 <getJNIEnv> */
/* @0x190674 ldr r12, [r11, #-0x30] */
/* @0x190678 mov r3, r4 */
/* @0x19067c ldr r1, [r12] */
/* @0x190680 ldr r12, [r11, #-0x48] */
/* @0x190684 ldr r2, [r12, #0x10] */
/* @0x190688 bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz> */
/* @0x19068c subs r6, r0, #0 */
/* @0x190690 beq 0x190834 <_Z16SetupGMLMappingsi+0x660> */
/* @0x190694 bl 0x290274 <getJNIEnv> */
/* @0x190698 mov r1, r6 */
/* @0x19069c ldr r3, [r0] */
/* @0x1906a0 ldr r3, [r3, #0x2ac] */
/* @0x1906a4 blx r3 */
/* @0x1906a8 cmp r0, #0 */
/* @0x1906ac ble 0x190834 <_Z16SetupGMLMappingsi+0x660> */
/* @0x1906b0 lsl r3, r0, #2 */
/* @0x1906b4 str r3, [r11, #-0x50] */
/* @0x1906b8 add r2, r3, #14 */
/* @0x1906bc bic r2, r2, #7 */
/* @0x1906c0 sub sp, sp, r2 */
/* @0x1906c4 bl 0x290274 <getJNIEnv> */
/* @0x1906c8 mov r1, r6 */
/* @0x1906cc mov r2, #0 */
/* @0x1906d0 mov r9, sp */
/* @0x1906d4 ldr r12, [r0] */
/* @0x1906d8 ldr r12, [r12, #0x2f4] */
/* @0x1906dc blx r12 */
/* @0x1906e0 ldr r3, [r11, #-0x50] */
/* @0x1906e4 mov r2, r3 */
/* @0x1906e8 mov r10, r0 */
/* @0x1906ec mov r0, sp */
/* @0x1906f0 mov r1, r10 */
/* @0x1906f4 bl 0xb65bc <memcpy@plt> */
/* @0x1906f8 bl 0x290274 <getJNIEnv> */
/* @0x1906fc mov r2, r10 */
/* @0x190700 mov r1, r6 */
/* @0x190704 mov r3, #0 */
/* @0x190708 ldr r12, [r0] */
/* @0x19070c ldr r12, [r12, #0x314] */
/* @0x190710 blx r12 */
/* @0x190714 bl 0x290274 <getJNIEnv> */
/* @0x190718 ldr r12, [r11, #-0x30] */
/* @0x19071c mov r3, r4 */
/* @0x190720 ldr r1, [r12] */
/* @0x190724 ldr r12, [r11, #-0x4c] */
/* @0x190728 ldr r2, [r12, #0x14] */
/* @0x19072c bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz> */
/* @0x190730 subs r6, r0, #0 */
/* @0x190734 beq 0x19082c <_Z16SetupGMLMappingsi+0x658> */
/* @0x190738 bl 0x290274 <getJNIEnv> */
/* @0x19073c mov r1, r6 */
/* @0x190740 ldr r3, [r0] */
/* @0x190744 ldr r3, [r3, #0x2ac] */
/* @0x190748 blx r3 */
/* @0x19074c cmp r0, #0 */
/* @0x190750 ble 0x19082c <_Z16SetupGMLMappingsi+0x658> */
/* @0x190754 lsl r12, r0, #2 */
/* @0x190758 str r12, [r11, #-0x50] */
/* @0x19075c add r3, r12, #14 */
/* @0x190760 bic r3, r3, #7 */
/* @0x190764 sub sp, sp, r3 */
/* @0x190768 bl 0x290274 <getJNIEnv> */
/* @0x19076c mov r1, r6 */
/* @0x190770 mov r2, #0 */
/* @0x190774 mov r10, sp */
/* @0x190778 ldr r3, [r0] */
/* @0x19077c ldr r3, [r3, #0x2f4] */
/* @0x190780 blx r3 */
/* @0x190784 ldr r12, [r11, #-0x50] */
/* @0x190788 mov r2, r12 */
/* @0x19078c mov r3, r0 */
/* @0x190790 mov r0, sp */
/* @0x190794 mov r1, r3 */
/* @0x190798 str r3, [r11, #-0x50] */
/* @0x19079c bl 0xb65bc <memcpy@plt> */
/* @0x1907a0 bl 0x290274 <getJNIEnv> */
/* @0x1907a4 ldr r3, [r11, #-0x50] */
/* @0x1907a8 mov r1, r6 */
/* @0x1907ac mov r2, r3 */
/* @0x1907b0 mov r3, #0 */
/* @0x1907b4 ldr r12, [r0] */
/* @0x1907b8 ldr r12, [r12, #0x314] */
/* @0x1907bc blx r12 */
/* @0x1907c0 mov r0, r5 */
/* @0x1907c4 mov r1, r9 */
/* @0x1907c8 mov r2, r10 */
/* @0x1907cc add r4, r4, #1 */
/* @0x1907d0 bl 0x18ee74 <_ZN9GMGamePad6UpdateEPfS0_> */
/* @0x1907d4 ldr r12, [r11, #-0x34] */
/* @0x1907d8 cmp r4, r12 */
/* @0x1907dc bne 0x190540 <_Z16SetupGMLMappingsi+0x36c> */
/* @0x1907e0 ldr r12, [r11, #-0x38] */
/* @0x1907e4 ldr r2, [r11, #-0x28] */
/* @0x1907e8 ldr r3, [r12] */
/* @0x1907ec cmp r2, r3 */
/* @0x1907f0 bne 0x19083c <_Z16SetupGMLMappingsi+0x668> */
/* @0x1907f4 sub sp, r11, #32 */
/* @0x1907f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1907fc mov r0, r5 */
/* @0x190800 ldr r1, [r11, #-0x3c] */
/* @0x190804 bl 0x18e944 <_ZN9GMGamePad11SetDeviceIdEPKc> */
/* @0x190808 ldr r3, [pc, #0x60] */
/* @0x19080c ldr r1, [r11, #-0x40] */
/* @0x190810 mov r2, r4 */
/* @0x190814 ldr r3, [r7, r3] */
/* @0x190818 ldr r0, [r3] */
/* @0x19081c ldr r3, [r0] */
/* @0x190820 ldr r3, [r3, #0xc] */
/* @0x190824 blx r3 */
/* @0x190828 b 0x190658 <_Z16SetupGMLMappingsi+0x484> */
/* @0x19082c mov r10, #0 */
/* @0x190830 b 0x1907c0 <_Z16SetupGMLMappingsi+0x5ec> */
/* @0x190834 mov r9, #0 */
/* @0x190838 b 0x190714 <_Z16SetupGMLMappingsi+0x540> */
/* @0x19083c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x190840 eoreq r1, r6, r12, lsr #15 */
/* @0x190844 .word 0xffffbd00 */
/* @0x190848 eorseq r5, r10, r8, ror r3 */
/* @0x19084c .word 0xffffde10 */
/* @0x190850 eorseq r5, r10, r4, lsr r3 */
/* @0x190854 eorseq r5, r10, r8, lsr #6 */
/* @0x190858 eorseq r5, r10, r4, lsr #6 */
/* @0x19085c andseq lr, r9, r6, lsr #12 */
/* @0x190860 mulseq r11, r12, r0 */
/* @0x190864 andseq r12, r11, r8, rrx */
/* @0x190868 .word 0xffffbd54 */
/* @0x19086c .word 0xffffde14 */
/* @0x190870 .word 0xffffbac4 */
