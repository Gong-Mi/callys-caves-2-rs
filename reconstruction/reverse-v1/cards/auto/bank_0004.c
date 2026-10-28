/* libyoyo.so 覆盖卡组 0004
 * 函数 0xc4148..0xc4868，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xc4148 · Background_Assign(int, int) · size=168 · insn=42 */
/* @0xc4148 push {r4, r5, r6, lr} */
/* @0xc414c subs r4, r1, #0 */
/* @0xc4150 mov r5, r0 */
/* @0xc4154 blt 0xc41ac <_Z17Background_Assignii+0x64> */
/* @0xc4158 ldr r3, [pc, #0x84] */
/* @0xc415c ldr r3, [pc, r3] */
/* @0xc4160 ldr r3, [r3] */
/* @0xc4164 cmp r4, r3 */
/* @0xc4168 bge 0xc41ac <_Z17Background_Assignii+0x64> */
/* @0xc416c ldr r2, [pc, #0x74] */
/* @0xc4170 add r2, pc, r2 */
/* @0xc4174 ldr r2, [r2, #0x4] */
/* @0xc4178 ldr r1, [r2, r4, lsl #2] */
/* @0xc417c cmp r1, #0 */
/* @0xc4180 beq 0xc419c <_Z17Background_Assignii+0x54> */
/* @0xc4184 ldr r0, [r2, r5, lsl #2] */
/* @0xc4188 cmp r0, #0 */
/* @0xc418c beq 0xc41b4 <_Z17Background_Assignii+0x6c> */
/* @0xc4190 bl 0xc2b80 <_ZN11CBackground6AssignEPS_> */
/* @0xc4194 mov r0, #1 */
/* @0xc4198 pop {r4, r5, r6, pc} */
/* @0xc419c cmp r0, #0 */
/* @0xc41a0 blt 0xc41ac <_Z17Background_Assignii+0x64> */
/* @0xc41a4 cmp r3, r0 */
/* @0xc41a8 bgt 0xc4184 <_Z17Background_Assignii+0x3c> */
/* @0xc41ac mov r0, #0 */
/* @0xc41b0 pop {r4, r5, r6, pc} */
/* @0xc41b4 mov r0, #72 */
/* @0xc41b8 bl 0x27c524 <_Znwj> */
/* @0xc41bc mov r6, r0 */
/* @0xc41c0 bl 0xc2b58 <_ZN11CBackgroundC2Ev> */
/* @0xc41c4 ldr r3, [pc, #0x20] */
/* @0xc41c8 add r3, pc, r3 */
/* @0xc41cc ldr r2, [r3, #0x4] */
/* @0xc41d0 str r6, [r2, r5, lsl #2] */
/* @0xc41d4 ldr r3, [r3, #0x4] */
/* @0xc41d8 ldr r0, [r3, r5, lsl #2] */
/* @0xc41dc ldr r1, [r3, r4, lsl #2] */
/* @0xc41e0 b 0xc4190 <_Z17Background_Assignii+0x48> */
/* @0xc41e4 eorseq r9, r2, r12, ror #15 */
/* @0xc41e8 eorseq r5, r11, r8, lsr r11 */
/* @0xc41ec eorseq r5, r11, r0, ror #21 */

/* ── FUNC 0xc41f0 · Background_AddEmpty() · size=260 · insn=65 */
/* @0xc41f0 push {r4, r5, r6, r7, r8, lr} */
/* @0xc41f4 sub sp, sp, #264 */
/* @0xc41f8 ldr r4, [pc, #0xdc] */
/* @0xc41fc movw r3, #0x2b9 */
/* @0xc4200 ldr r5, [pc, #0xd8] */
/* @0xc4204 ldr r4, [pc, r4] */
/* @0xc4208 ldr r8, [pc, #0xd4] */
/* @0xc420c ldr r5, [pc, r5] */
/* @0xc4210 ldr r7, [pc, #0xd0] */
/* @0xc4214 ldr r12, [r4] */
/* @0xc4218 add r8, pc, r8 */
/* @0xc421c ldr lr, [r5] */
/* @0xc4220 add r7, pc, r7 */
/* @0xc4224 add r12, r12, #1 */
/* @0xc4228 mov r2, r8 */
/* @0xc422c add r0, r7, #4 */
/* @0xc4230 ldr r6, [pc, #0xb4] */
/* @0xc4234 lsl r1, r12, #2 */
/* @0xc4238 str lr, [sp, #0x104] */
/* @0xc423c str r12, [r4] */
/* @0xc4240 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xc4244 ldr r12, [r4] */
/* @0xc4248 ldr r6, [pc, r6] */
/* @0xc424c mov r2, r8 */
/* @0xc4250 movw r3, #0x2bb */
/* @0xc4254 mov r0, r6 */
/* @0xc4258 add r8, sp, #4 */
/* @0xc425c lsl r1, r12, #2 */
/* @0xc4260 str r12, [r7] */
/* @0xc4264 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xc4268 ldr r3, [r4] */
/* @0xc426c ldr r2, [pc, #0x7c] */
/* @0xc4270 mov r1, #256 */
/* @0xc4274 mov r0, r8 */
/* @0xc4278 sub r3, r3, #1 */
/* @0xc427c add r2, pc, r2 */
/* @0xc4280 bl 0xb65c8 <snprintf@plt> */
/* @0xc4284 ldr r3, [r4] */
/* @0xc4288 mov r0, r8 */
/* @0xc428c ldr r6, [r6] */
/* @0xc4290 sub r8, r3, #-1073741823 */
/* @0xc4294 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xc4298 str r0, [r6, r8, lsl #2] */
/* @0xc429c mov r0, #72 */
/* @0xc42a0 bl 0x27c524 <_Znwj> */
/* @0xc42a4 mov r6, r0 */
/* @0xc42a8 bl 0xc2b58 <_ZN11CBackgroundC2Ev> */
/* @0xc42ac ldr r0, [r4] */
/* @0xc42b0 ldr r1, [r7, #0x4] */
/* @0xc42b4 sub r12, r0, #-1073741823 */
/* @0xc42b8 ldr r2, [sp, #0x104] */
/* @0xc42bc sub r0, r0, #1 */
/* @0xc42c0 str r6, [r1, r12, lsl #2] */
/* @0xc42c4 ldr r3, [r5] */
/* @0xc42c8 cmp r2, r3 */
/* @0xc42cc bne 0xc42d8 <_Z19Background_AddEmptyv+0xe8> */
/* @0xc42d0 add sp, sp, #264 */
/* @0xc42d4 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc42d8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xc42dc eorseq r9, r2, r4, asr #14 */
/* @0xc42e0 eorseq r9, r2, r4, asr #14 */
/* @0xc42e4 eoreq r12, r6, r8, ror #16 */
/* @0xc42e8 eorseq r5, r11, r8, lsl #21 */
/* @0xc42ec eorseq r9, r2, r4, lsl #14 */
/* @0xc42f0 eoreq r12, r6, r0, asr r8 */

/* ── FUNC 0xc42f4 · FINALIZE_Background() · size=124 · insn=31 */
/* @0xc42f4 push {r3, r4, r5, r6, r7, lr} */
/* @0xc42f8 ldr r5, [pc, #0x68] */
/* @0xc42fc ldr r5, [pc, r5] */
/* @0xc4300 ldr r0, [r5] */
/* @0xc4304 cmp r0, #0 */
/* @0xc4308 beq 0xc435c <_Z19FINALIZE_Backgroundv+0x68> */
/* @0xc430c ldr r6, [pc, #0x58] */
/* @0xc4310 ldr r6, [pc, r6] */
/* @0xc4314 ldr r3, [r6] */
/* @0xc4318 cmp r3, #0 */
/* @0xc431c ble 0xc434c <_Z19FINALIZE_Backgroundv+0x58> */
/* @0xc4320 mov r4, #0 */
/* @0xc4324 mov r7, r4 */
/* @0xc4328 ldr r0, [r0, r4, lsl #2] */
/* @0xc432c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc4330 ldr r2, [r5] */
/* @0xc4334 ldr r3, [r6] */
/* @0xc4338 str r7, [r2, r4, lsl #2] */
/* @0xc433c add r4, r4, #1 */
/* @0xc4340 cmp r3, r4 */
/* @0xc4344 ldr r0, [r5] */
/* @0xc4348 bgt 0xc4328 <_Z19FINALIZE_Backgroundv+0x34> */
/* @0xc434c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc4350 mov r3, #0 */
/* @0xc4354 str r3, [r5] */
/* @0xc4358 str r3, [r6] */
/* @0xc435c bl 0xc35d8 <_Z23Background_FreeTexturesv> */
/* @0xc4360 pop {r3, r4, r5, r6, r7, lr} */
/* @0xc4364 b 0xc34d0 <_Z15Background_Freev> */
/* @0xc4368 eorseq r9, r2, r0, asr r6 */
/* @0xc436c eorseq r9, r2, r8, lsr r6 */

/* ── FUNC 0xc4370 · tagIConsole::~tagIConsole() · size=24 · insn=6 */
/* @0xc4370 ldr r3, [pc, #0xc] */
/* @0xc4374 ldr r3, [pc, r3] */
/* @0xc4378 add r3, r3, #8 */
/* @0xc437c str r3, [r0] */
/* @0xc4380 bx lr */
/* @0xc4384 eorseq r9, r2, r12, ror #11 */

/* ── FUNC 0xc4370 · tagIConsole::~tagIConsole() · alias of the symbol above · insn=0 */

/* ── FUNC 0xc4388 · DummyConsole::Create(wchar_t const*, bool) · size=8 · insn=2 */
/* @0xc4388 mov r0, #1 */
/* @0xc438c bx lr */

/* ── FUNC 0xc4390 · DummyConsole::Output(char const*, ...) · size=12 · insn=3 */
/* @0xc4390 push {r1, r2, r3} */
/* @0xc4394 add sp, sp, #12 */
/* @0xc4398 bx lr */

/* ── FUNC 0xc439c · DummyConsole::~DummyConsole() · size=24 · insn=6 */
/* @0xc439c ldr r3, [pc, #0xc] */
/* @0xc43a0 ldr r3, [pc, r3] */
/* @0xc43a4 add r3, r3, #8 */
/* @0xc43a8 str r3, [r0] */
/* @0xc43ac bx lr */
/* @0xc43b0 eorseq r9, r2, r0, asr #11 */

/* ── FUNC 0xc439c · DummyConsole::~DummyConsole() · alias of the symbol above · insn=0 */

/* ── FUNC 0xc43b4 · tagIConsole::~tagIConsole() · size=40 · insn=10 */
/* @0xc43b4 ldr r3, [pc, #0x1c] */
/* @0xc43b8 push {r4, lr} */
/* @0xc43bc ldr r3, [pc, r3] */
/* @0xc43c0 mov r4, r0 */
/* @0xc43c4 add r3, r3, #8 */
/* @0xc43c8 str r3, [r0] */
/* @0xc43cc bl 0x27d1d0 <_ZdlPv> */
/* @0xc43d0 mov r0, r4 */
/* @0xc43d4 pop {r4, pc} */
/* @0xc43d8 eorseq r9, r2, r4, lsr #11 */

/* ── FUNC 0xc43dc · DummyConsole::~DummyConsole() · size=40 · insn=10 */
/* @0xc43dc ldr r3, [pc, #0x1c] */
/* @0xc43e0 push {r4, lr} */
/* @0xc43e4 ldr r3, [pc, r3] */
/* @0xc43e8 mov r4, r0 */
/* @0xc43ec add r3, r3, #8 */
/* @0xc43f0 str r3, [r0] */
/* @0xc43f4 bl 0x27d1d0 <_ZdlPv> */
/* @0xc43f8 mov r0, r4 */
/* @0xc43fc pop {r4, pc} */
/* @0xc4400 eorseq r9, r2, r12, ror r5 */

/* ── FUNC 0xc4404 · ReportSpineError · size=52 · insn=13 */
/* @0xc4404 push {r3, lr} */
/* @0xc4408 mov r2, r0 */
/* @0xc440c ldr r3, [pc, #0x1c] */
/* @0xc4410 ldr r1, [pc, #0x1c] */
/* @0xc4414 ldr r3, [pc, r3] */
/* @0xc4418 add r1, pc, r1 */
/* @0xc441c ldr r0, [r3] */
/* @0xc4420 ldr r3, [r0] */
/* @0xc4424 ldr r3, [r3, #0xc] */
/* @0xc4428 blx r3 */
/* @0xc442c pop {r3, pc} */
/* @0xc4430 eorseq r9, r2, r0, lsl #6 */
/* @0xc4434 .word 0x0026c6dc */

/* ── FUNC 0xc4438 · InitRandom(unsigned int) · size=116 · insn=29 */
/* @0xc4438 str r4, [sp, #-0x4]! */
/* @0xc443c movw r12, #0x43fd */
/* @0xc4440 ldr r4, [pc, #0x58] */
/* @0xc4444 movt r12, #0x3 */
/* @0xc4448 ldr r1, [pc, #0x54] */
/* @0xc444c mov r3, r0 */
/* @0xc4450 ldr r4, [pc, r4] */
/* @0xc4454 ldr r1, [pc, r1] */
/* @0xc4458 sub r2, r4, #4 */
/* @0xc445c add r4, r4, #60 */
/* @0xc4460 str r0, [r1] */
/* @0xc4464 mul r1, r12, r3 */
/* @0xc4468 movw r3, #0x9ec3 */
/* @0xc446c movt r3, #0x26 */
/* @0xc4470 add r3, r1, r3 */
/* @0xc4474 asr r3, r3, #16 */
/* @0xc4478 bic r3, r3, #-2147483648 */
/* @0xc447c str r3, [r2, #0x4]! */
/* @0xc4480 cmp r2, r4 */
/* @0xc4484 bne 0xc4464 <_Z10InitRandomj+0x2c> */
/* @0xc4488 ldr r3, [pc, #0x18] */
/* @0xc448c mov r2, #0 */
/* @0xc4490 ldr r4, [sp], #4 */
/* @0xc4494 ldr r3, [pc, r3] */
/* @0xc4498 str r2, [r3] */
/* @0xc449c bx lr */
/* @0xc44a0 eorseq r9, r2, r4, lsl r5 */
/* @0xc44a4 eorseq r9, r2, r4, lsl r5 */
/* @0xc44a8 ldrsbteq r9, [r2], -r8 */

/* ── FUNC 0xc44ac · ChangeToOldPoly(bool) · size=64 · insn=16 */
/* @0xc44ac cmp r0, #0 */
/* @0xc44b0 bne 0xc44cc <_Z15ChangeToOldPolyb+0x20> */
/* @0xc44b4 ldr r2, [pc, #0x28] */
/* @0xc44b8 movw r3, #0x2d24 */
/* @0xc44bc movt r3, #0xda44 */
/* @0xc44c0 add r2, pc, r2 */
/* @0xc44c4 str r3, [r2] */
/* @0xc44c8 bx lr */
/* @0xc44cc ldr r2, [pc, #0x14] */
/* @0xc44d0 movw r3, #0x2d20 */
/* @0xc44d4 movt r3, #0xda44 */
/* @0xc44d8 add r2, pc, r2 */
/* @0xc44dc str r3, [r2] */
/* @0xc44e0 bx lr */
/* @0xc44e4 eorseq sp, r2, r12, lsr r11 */
/* @0xc44e8 eorseq sp, r2, r4, lsr #22 */

/* ── FUNC 0xc44ec · YYRandom() · size=156 · insn=39 */
/* @0xc44ec ldr r1, [pc, #0x88] */
/* @0xc44f0 ldr r3, [pc, #0x88] */
/* @0xc44f4 ldr r1, [pc, r1] */
/* @0xc44f8 ldr r0, [pc, #0x84] */
/* @0xc44fc ldr r3, [pc, r3] */
/* @0xc4500 ldr r2, [r1] */
/* @0xc4504 add r0, pc, r0 */
/* @0xc4508 push {r4, r5, r6} */
/* @0xc450c add r4, r2, #13 */
/* @0xc4510 add r5, r2, #9 */
/* @0xc4514 ldr r6, [r3, r2, lsl #2] */
/* @0xc4518 and r4, r4, #15 */
/* @0xc451c and r5, r5, #15 */
/* @0xc4520 add r12, r2, #15 */
/* @0xc4524 ldr r0, [r0] */
/* @0xc4528 ldr r4, [r3, r4, lsl #2] */
/* @0xc452c eor r6, r6, r6, lsl #16 */
/* @0xc4530 ldr r5, [r3, r5, lsl #2] */
/* @0xc4534 and r12, r12, #15 */
/* @0xc4538 eor r6, r6, r4 */
/* @0xc453c str r12, [r1] */
/* @0xc4540 eor r1, r6, r4, lsl #15 */
/* @0xc4544 eor r5, r5, r5, lsr #11 */
/* @0xc4548 eor r4, r5, r1 */
/* @0xc454c str r4, [r3, r2, lsl #2] */
/* @0xc4550 ldr r2, [r3, r12, lsl #2] */
/* @0xc4554 and r6, r0, r4, lsl #5 */
/* @0xc4558 eor r2, r2, r2, lsl #2 */
/* @0xc455c eor r0, r2, r1 */
/* @0xc4560 eor r0, r0, r4 */
/* @0xc4564 eor r0, r0, r1, lsl #18 */
/* @0xc4568 eor r0, r0, r5, lsl #28 */
/* @0xc456c eor r0, r0, r6 */
/* @0xc4570 str r0, [r3, r12, lsl #2] */
/* @0xc4574 pop {r4, r5, r6} */
/* @0xc4578 bx lr */
/* @0xc457c eorseq r9, r2, r8, ror r4 */
/* @0xc4580 eorseq r9, r2, r8, ror #8 */
/* @0xc4584 ldrshteq sp, [r2], -r8 */

/* ── FUNC 0xc4588 · iYYRandom() · size=16 · insn=4 */
/* @0xc4588 push {r3, lr} */
/* @0xc458c bl 0xc44ec <_Z8YYRandomv> */
/* @0xc4590 bic r0, r0, #-2147483648 */
/* @0xc4594 pop {r3, pc} */

/* ── FUNC 0xc4598 · fYYRandom(double) · size=104 · insn=26 */
/* @0xc4598 vmov.f64 d7, #1.000000e+00 */
/* @0xc459c push {r3, lr} */
/* @0xc45a0 vpush {d8} */
/* @0xc45a4 vmov d8, r0, r1 */
/* @0xc45a8 vcmp.f64 d8, d7 */
/* @0xc45ac vmrs APSR_nzcv, fpscr */
/* @0xc45b0 beq 0xc45d8 <_Z9fYYRandomd+0x40> */
/* @0xc45b4 bl 0xc44ec <_Z8YYRandomv> */
/* @0xc45b8 vldr d7, [pc, #56] */
/* @0xc45bc vmov s11, r0 */
/* @0xc45c0 vcvt.f64.u32 d6, s11 */
/* @0xc45c4 vmul.f64 d7, d6, d7 */
/* @0xc45c8 vmul.f64 d8, d7, d8 */
/* @0xc45cc vmov r0, r1, d8 */
/* @0xc45d0 vpop {d8} */
/* @0xc45d4 pop {r3, pc} */
/* @0xc45d8 bl 0xc44ec <_Z8YYRandomv> */
/* @0xc45dc vldr d7, [pc, #20] */
/* @0xc45e0 vmov s11, r0 */
/* @0xc45e4 vcvt.f64.u32 d8, s11 */
/* @0xc45e8 vmul.f64 d8, d8, d7 */
/* @0xc45ec vmov r0, r1, d8 */
/* @0xc45f0 vpop {d8} */
/* @0xc45f4 pop {r3, pc} */
/* @0xc45f8 andeq r0, r0, r0 */
/* @0xc45fc ldcllo p0, c0, [r0, #0]! */

/* ── FUNC 0xc4600 · YYRandom(int) · size=32 · insn=8 */
/* @0xc4600 push {r4, lr} */
/* @0xc4604 mov r4, r0 */
/* @0xc4608 bl 0xc44ec <_Z8YYRandomv> */
/* @0xc460c eor r1, r4, r4, asr #31 */
/* @0xc4610 sub r1, r1, r4, asr #31 */
/* @0xc4614 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0xc4618 mov r0, r1 */
/* @0xc461c pop {r4, pc} */

/* ── FUNC 0xc4620 · ASCIIToUnicode(char const*) · size=100 · insn=25 */
/* @0xc4620 push {r3, r4, r5, lr} */
/* @0xc4624 mov r5, r0 */
/* @0xc4628 bl 0xb6538 <strlen@plt> */
/* @0xc462c ldr r1, [pc, #0x4c] */
/* @0xc4630 mov r2, #191 */
/* @0xc4634 mov r3, #1 */
/* @0xc4638 add r1, pc, r1 */
/* @0xc463c mov r4, r0 */
/* @0xc4640 add r0, r0, #1 */
/* @0xc4644 lsl r0, r0, #1 */
/* @0xc4648 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xc464c cmp r4, #0 */
/* @0xc4650 movgt r3, #0 */
/* @0xc4654 subgt r2, r0, #2 */
/* @0xc4658 ble 0xc4670 <_Z14ASCIIToUnicodePKc+0x50> */
/* @0xc465c ldrb r1, [r5, r3] */
/* @0xc4660 add r3, r3, #1 */
/* @0xc4664 cmp r4, r3 */
/* @0xc4668 strh r1, [r2, #2]! */
/* @0xc466c bne 0xc465c <_Z14ASCIIToUnicodePKc+0x3c> */
/* @0xc4670 lsl r4, r4, #1 */
/* @0xc4674 mov r3, #0 */
/* @0xc4678 strh r3, [r0, r4] */
/* @0xc467c pop {r3, r4, r5, pc} */
/* @0xc4680 eoreq r12, r6, r12, asr #9 */

/* ── FUNC 0xc4684 · UnicodeToASCII(char const*) · size=92 · insn=23 */
/* @0xc4684 push {r3, r4, r5, lr} */
/* @0xc4688 mov r5, r0 */
/* @0xc468c bl 0xb65ec <wcslen@plt> */
/* @0xc4690 ldr r1, [pc, #0x44] */
/* @0xc4694 mov r2, #214 */
/* @0xc4698 mov r3, #1 */
/* @0xc469c add r1, pc, r1 */
/* @0xc46a0 mov r4, r0 */
/* @0xc46a4 add r0, r0, #1 */
/* @0xc46a8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xc46ac cmp r4, #0 */
/* @0xc46b0 subgt r2, r5, #2 */
/* @0xc46b4 movgt r3, #0 */
/* @0xc46b8 ble 0xc46d0 <_Z14UnicodeToASCIIPKc+0x4c> */
/* @0xc46bc ldrh r1, [r2, #2]! */
/* @0xc46c0 strb r1, [r0, r3] */
/* @0xc46c4 add r3, r3, #1 */
/* @0xc46c8 cmp r4, r3 */
/* @0xc46cc bne 0xc46bc <_Z14UnicodeToASCIIPKc+0x38> */
/* @0xc46d0 mov r3, #0 */
/* @0xc46d4 strb r3, [r0, r4] */
/* @0xc46d8 pop {r3, r4, r5, pc} */
/* @0xc46dc eoreq r12, r6, r8, ror #8 */

/* ── FUNC 0xc46e0 · Trunc(double) · size=16 · insn=4 */
/* @0xc46e0 vmov d7, r0, r1 */
/* @0xc46e4 vcvt.s32.f64 s15, d7 */
/* @0xc46e8 vmov r0, s15 */
/* @0xc46ec bx lr */

/* ── FUNC 0xc46f0 · Pos(char const*, char const*) · size=56 · insn=14 */
/* @0xc46f0 cmp r0, #0 */
/* @0xc46f4 cmpne r1, #0 */
/* @0xc46f8 push {r4, lr} */
/* @0xc46fc mov r4, r1 */
/* @0xc4700 beq 0xc4720 <_Z3PosPKcS0_+0x30> */
/* @0xc4704 mov r1, r0 */
/* @0xc4708 mov r0, r4 */
/* @0xc470c bl 0xb6604 <strstr@plt> */
/* @0xc4710 cmp r0, #0 */
/* @0xc4714 rsbne r0, r4, r0 */
/* @0xc4718 addne r0, r0, #1 */
/* @0xc471c pop {r4, pc} */
/* @0xc4720 mov r0, #0 */
/* @0xc4724 pop {r4, pc} */

/* ── FUNC 0xc4728 · Trim(char const*&, char const*) · size=208 · insn=52 */
/* @0xc4728 push {r3, r4, r5, r6, r7, lr} */
/* @0xc472c mov r6, r0 */
/* @0xc4730 ldr r0, [r0] */
/* @0xc4734 mov r5, r1 */
/* @0xc4738 cmp r0, #0 */
/* @0xc473c beq 0xc4744 <_Z4TrimRPKcS0_+0x1c> */
/* @0xc4740 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc4744 mov r0, r5 */
/* @0xc4748 bl 0xb6538 <strlen@plt> */
/* @0xc474c cmp r5, #0 */
/* @0xc4750 streq r5, [r6] */
/* @0xc4754 popeq {r3, r4, r5, r6, r7, pc} */
/* @0xc4758 cmp r0, #0 */
/* @0xc475c ble 0xc4788 <_Z4TrimRPKcS0_+0x60> */
/* @0xc4760 mov lr, r5 */
/* @0xc4764 mov r12, #0 */
/* @0xc4768 mov r2, lr */
/* @0xc476c add lr, lr, #1 */
/* @0xc4770 ldrb r4, [r2] */
/* @0xc4774 cmp r4, #32 */
/* @0xc4778 bhi 0xc479c <_Z4TrimRPKcS0_+0x74> */
/* @0xc477c add r12, r12, #1 */
/* @0xc4780 cmp r0, r12 */
/* @0xc4784 bne 0xc4768 <_Z4TrimRPKcS0_+0x40> */
/* @0xc4788 ldr r0, [pc, #0x64] */
/* @0xc478c add r0, pc, r0 */
/* @0xc4790 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xc4794 str r0, [r6] */
/* @0xc4798 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc479c cmp r0, r12 */
/* @0xc47a0 ble 0xc4788 <_Z4TrimRPKcS0_+0x60> */
/* @0xc47a4 sub r3, r0, #1 */
/* @0xc47a8 ldrb r1, [r5, r3] */
/* @0xc47ac cmp r1, #32 */
/* @0xc47b0 bls 0xc47c4 <_Z4TrimRPKcS0_+0x9c> */
/* @0xc47b4 b 0xc47d0 <_Z4TrimRPKcS0_+0xa8> */
/* @0xc47b8 ldrb r12, [r5, r3] */
/* @0xc47bc cmp r12, #32 */
/* @0xc47c0 bhi 0xc47d0 <_Z4TrimRPKcS0_+0xa8> */
/* @0xc47c4 subs r3, r3, #1 */
/* @0xc47c8 blo 0xc4788 <_Z4TrimRPKcS0_+0x60> */
/* @0xc47cc b 0xc47b8 <_Z4TrimRPKcS0_+0x90> */
/* @0xc47d0 add r4, r3, #1 */
/* @0xc47d4 mov r0, r2 */
/* @0xc47d8 mov r3, #0 */
/* @0xc47dc ldrb r7, [r5, r4] */
/* @0xc47e0 strb r3, [r5, r4] */
/* @0xc47e4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xc47e8 str r0, [r6] */
/* @0xc47ec strb r7, [r5, r4] */
/* @0xc47f0 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc47f4 eoreq r7, r9, r8, asr #31 */

/* ── FUNC 0xc47f8 · FINALIZE_All() · size=4 · insn=1 */
/* @0xc47f8 bx lr */

/* ── FUNC 0xc47fc · TConsole::~TConsole() · size=24 · insn=6 */
/* @0xc47fc ldr r3, [pc, #0xc] */
/* @0xc4800 ldr r3, [pc, r3] */
/* @0xc4804 add r3, r3, #8 */
/* @0xc4808 str r3, [r0] */
/* @0xc480c bx lr */
/* @0xc4810 eorseq r9, r2, r0, ror #2 */

/* ── FUNC 0xc47fc · TConsole::~TConsole() · alias of the symbol above · insn=0 */

/* ── FUNC 0xc4814 · TConsole::Create(wchar_t const*, bool) · size=8 · insn=2 */
/* @0xc4814 mov r0, #1 */
/* @0xc4818 bx lr */

/* ── FUNC 0xc481c · TConsole::Output(char const*, ...) · size=12 · insn=3 */
/* @0xc481c push {r1, r2, r3} */
/* @0xc4820 add sp, sp, #12 */
/* @0xc4824 bx lr */

/* ── FUNC 0xc4828 · TRelConsole::~TRelConsole() · size=24 · insn=6 */
/* @0xc4828 ldr r3, [pc, #0xc] */
/* @0xc482c ldr r3, [pc, r3] */
/* @0xc4830 add r3, r3, #8 */
/* @0xc4834 str r3, [r0] */
/* @0xc4838 bx lr */
/* @0xc483c eorseq r9, r2, r4, lsr r1 */

/* ── FUNC 0xc4828 · TRelConsole::~TRelConsole() · alias of the symbol above · insn=0 */

/* ── FUNC 0xc4840 · TConsole::~TConsole() · size=40 · insn=10 */
/* @0xc4840 ldr r3, [pc, #0x1c] */
/* @0xc4844 push {r4, lr} */
/* @0xc4848 ldr r3, [pc, r3] */
/* @0xc484c mov r4, r0 */
/* @0xc4850 add r3, r3, #8 */
/* @0xc4854 str r3, [r0] */
/* @0xc4858 bl 0x27d1d0 <_ZdlPv> */
/* @0xc485c mov r0, r4 */
/* @0xc4860 pop {r4, pc} */
/* @0xc4864 eorseq r9, r2, r8, lsl r1 */

/* ── FUNC 0xc4868 · TRelConsole::~TRelConsole() · size=40 · insn=10 */
/* @0xc4868 ldr r3, [pc, #0x1c] */
/* @0xc486c push {r4, lr} */
/* @0xc4870 ldr r3, [pc, r3] */
/* @0xc4874 mov r4, r0 */
/* @0xc4878 add r3, r3, #8 */
/* @0xc487c str r3, [r0] */
/* @0xc4880 bl 0x27d1d0 <_ZdlPv> */
/* @0xc4884 mov r0, r4 */
/* @0xc4888 pop {r4, pc} */
/* @0xc488c ldrshteq r9, [r2], -r0 */
