/* libyoyo.so 覆盖卡组 0056
 * 函数 0x127188..0x1291c8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x127188 · F_GetIntegerAsync(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x127188 ldr r1, [pc, #0xa4] */
/* @0x12718c mov r12, #16 */
/* @0x127190 push {r4, r5, r6, lr} */
/* @0x127194 sub sp, sp, #16 */
/* @0x127198 mov r4, r0 */
/* @0x12719c add r1, pc, r1 */
/* @0x1271a0 mov r0, r12 */
/* @0x1271a4 movw r2, #0x60d */
/* @0x1271a8 mov r3, #1 */
/* @0x1271ac str r12, [sp, #0x4] */
/* @0x1271b0 ldr r6, [sp, #0x20] */
/* @0x1271b4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1271b8 mov r5, #0 */
/* @0x1271bc add r2, sp, #4 */
/* @0x1271c0 add r1, sp, #8 */
/* @0x1271c4 mov r3, r0 */
/* @0x1271c8 add r0, sp, #16 */
/* @0x1271cc str r3, [sp, #0x8] */
/* @0x1271d0 str r3, [r0, #-0x4]! */
/* @0x1271d4 strb r5, [r3] */
/* @0x1271d8 add r3, r6, #16 */
/* @0x1271dc bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x1271e0 ldr r0, [sp, #0x8] */
/* @0x1271e4 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x1271e8 ldr r3, [pc, #0x48] */
/* @0x1271ec str r5, [r4, #0xc] */
/* @0x1271f0 mov r1, r5 */
/* @0x1271f4 ldr r3, [pc, r3] */
/* @0x1271f8 mov r0, r6 */
/* @0x1271fc ldr r5, [r3] */
/* @0x127200 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x127204 ldr r2, [sp, #0x8] */
/* @0x127208 mov r1, r0 */
/* @0x12720c mov r0, r5 */
/* @0x127210 bl 0xf26c4 <_ZN10InputQuery10InputAsyncEPKcS1_S1_> */
/* @0x127214 vmov s15, r0 */
/* @0x127218 ldr r0, [sp, #0x8] */
/* @0x12721c vcvt.f64.s32 d7, s15 */
/* @0x127220 vmov r2, r3, d7 */
/* @0x127224 stm r4, {r2, r3} */
/* @0x127228 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x12722c add sp, sp, #16 */
/* @0x127230 pop {r4, r5, r6, pc} */
/* @0x127234 mlaeq r1, r8, r0, r5 */
/* @0x127238 eoreq r7, r12, r12, lsl #17 */

/* ── FUNC 0x12723c · F_GetInteger(RValue&, CInstance*, CInstance*, int, RValue*) · size=272 · insn=68 */
/* @0x12723c ldr r1, [pc, #0xfc] */
/* @0x127240 mov r12, #16 */
/* @0x127244 push {r4, r5, r6, lr} */
/* @0x127248 sub sp, sp, #16 */
/* @0x12724c add r1, pc, r1 */
/* @0x127250 mov r2, #1520 */
/* @0x127254 mov r3, #1 */
/* @0x127258 mov r5, r0 */
/* @0x12725c mov r0, r12 */
/* @0x127260 str r12, [sp] */
/* @0x127264 ldr r6, [sp, #0x20] */
/* @0x127268 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x12726c mov r4, #0 */
/* @0x127270 mov r2, sp */
/* @0x127274 add r1, sp, #4 */
/* @0x127278 mov r3, r0 */
/* @0x12727c add r0, sp, #16 */
/* @0x127280 str r3, [sp, #0x4] */
/* @0x127284 str r3, [r0, #-0x8]! */
/* @0x127288 strb r4, [r3] */
/* @0x12728c add r3, r6, #16 */
/* @0x127290 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x127294 ldr r0, [sp, #0x4] */
/* @0x127298 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x12729c mov r0, r6 */
/* @0x1272a0 mov r1, r4 */
/* @0x1272a4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1272a8 str r4, [sp, #0xc] */
/* @0x1272ac mov r6, r0 */
/* @0x1272b0 bl 0x29cb74 <_Z19DebuggerIsConnectedv> */
/* @0x1272b4 cmp r0, r4 */
/* @0x1272b8 beq 0x127320 <_Z12F_GetIntegerR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x1272bc bl 0x29cb88 <_Z32DebuggerRunBackgroundMessageLoopv> */
/* @0x1272c0 ldr r0, [pc, #0x7c] */
/* @0x1272c4 mov r1, r6 */
/* @0x1272c8 ldr r2, [sp, #0x4] */
/* @0x1272cc ldr r0, [pc, r0] */
/* @0x1272d0 add r3, sp, #12 */
/* @0x1272d4 ldr r0, [r0] */
/* @0x1272d8 bl 0xf28b0 <_ZN10InputQuery5InputEPKcS1_S1_RPc> */
/* @0x1272dc bl 0x29cc30 <_Z33DebuggerStopBackgroundMessageLoopv> */
/* @0x1272e0 ldr r0, [sp, #0xc] */
/* @0x1272e4 cmp r0, #0 */
/* @0x1272e8 moveq r3, r0 */
/* @0x1272ec beq 0x127304 <_Z12F_GetIntegerR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x1272f0 mov r1, #0 */
/* @0x1272f4 str r1, [r5, #0xc] */
/* @0x1272f8 bl 0xb6658 <strtod@plt> */
/* @0x1272fc ldr r3, [sp, #0xc] */
/* @0x127300 stm r5, {r0, r1} */
/* @0x127304 mov r0, r3 */
/* @0x127308 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x12730c ldr r0, [sp, #0x4] */
/* @0x127310 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x127314 bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0x127318 add sp, sp, #16 */
/* @0x12731c pop {r4, r5, r6, pc} */
/* @0x127320 ldr r0, [pc, #0x20] */
/* @0x127324 mov r1, r6 */
/* @0x127328 ldr r2, [sp, #0x4] */
/* @0x12732c add r3, sp, #12 */
/* @0x127330 ldr r0, [pc, r0] */
/* @0x127334 ldr r0, [r0] */
/* @0x127338 bl 0xf28b0 <_ZN10InputQuery5InputEPKcS1_S1_RPc> */
/* @0x12733c b 0x1272e0 <_Z12F_GetIntegerR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x127340 eoreq r4, r1, r8, ror #31 */
/* @0x127344 .word 0x002c77b4 */
/* @0x127348 eoreq r7, r12, r0, asr r7 */

/* ── FUNC 0x12734c · F_KeyboardSetMap(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x12734c push {r3, r4, r5, lr} */
/* @0x127350 mov r1, #0 */
/* @0x127354 ldr r4, [sp, #0x10] */
/* @0x127358 mov r0, r4 */
/* @0x12735c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x127360 mov r1, #1 */
/* @0x127364 mov r5, r0 */
/* @0x127368 mov r0, r4 */
/* @0x12736c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x127370 mov r1, r0 */
/* @0x127374 mov r0, r5 */
/* @0x127378 pop {r3, r4, r5, lr} */
/* @0x12737c b 0x18c2fc <_Z13IO_Keymap_Setii> */

/* ── FUNC 0x127380 · F_KeyboardGetMap(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x127380 push {r4, lr} */
/* @0x127384 mov r3, #0 */
/* @0x127388 mov r1, r3 */
/* @0x12738c str r3, [r0, #0xc] */
/* @0x127390 mov r4, r0 */
/* @0x127394 ldr r0, [sp, #0x8] */
/* @0x127398 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12739c bl 0x18c2e0 <_Z13IO_Keymap_Geti> */
/* @0x1273a0 vmov s15, r0 */
/* @0x1273a4 vcvt.f64.s32 d7, s15 */
/* @0x1273a8 vmov r0, r1, d7 */
/* @0x1273ac vmov r2, s14 */
/* @0x1273b0 mov r3, r1 */
/* @0x1273b4 stm r4, {r2, r3} */
/* @0x1273b8 pop {r4, pc} */

/* ── FUNC 0x1273bc · F_KeyboardUnsetMap(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1273bc b 0x18c314 <_Z15IO_Keymap_Clearv> */

/* ── FUNC 0x1273c0 · F_IoClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=16 · insn=4 */
/* @0x1273c0 push {r3, lr} */
/* @0x1273c4 bl 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x1273c8 pop {r3, lr} */
/* @0x1273cc b 0x18c2c8 <_Z8IO_Clearv> */

/* ── FUNC 0x1273d0 · F_IoHandle(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1273d0 b 0x28fe64 <_Z15ProcessMessagesv> */

/* ── FUNC 0x1273d4 · F_KeyboardClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x1273d4 push {r4, lr} */
/* @0x1273d8 ldr r4, [sp, #0x8] */
/* @0x1273dc bl 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x1273e0 mov r1, #0 */
/* @0x1273e4 mov r0, r4 */
/* @0x1273e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1273ec pop {r4, lr} */
/* @0x1273f0 b 0x18bf54 <_Z12IO_Key_Cleari> */

/* ── FUNC 0x1273f4 · F_ShowError(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1273f4 push {r3, r4, r5, lr} */
/* @0x1273f8 mov r1, #0 */
/* @0x1273fc ldr r4, [sp, #0x10] */
/* @0x127400 mov r0, r4 */
/* @0x127404 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x127408 mov r1, #1 */
/* @0x12740c mov r5, r0 */
/* @0x127410 mov r0, r4 */
/* @0x127414 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x127418 mov r1, r0 */
/* @0x12741c mov r0, r5 */
/* @0x127420 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x127424 ldr r3, [pc, #0x34] */
/* @0x127428 ldr r3, [pc, r3] */
/* @0x12742c ldrb r3, [r3] */
/* @0x127430 cmp r3, #0 */
/* @0x127434 popeq {r3, r4, r5, pc} */
/* @0x127438 ldr r3, [pc, #0x24] */
/* @0x12743c ldr r3, [pc, r3] */
/* @0x127440 ldr r3, [r3] */
/* @0x127444 cmp r3, #0 */
/* @0x127448 popne {r3, r4, r5, pc} */
/* @0x12744c ldr r1, [pc, #0x14] */
/* @0x127450 mov r0, #1 */
/* @0x127454 pop {r3, r4, r5, lr} */
/* @0x127458 add r1, pc, r1 */
/* @0x12745c b 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x127460 .word 0x002c64fc */
/* @0x127464 eoreq r6, r12, r4, ror #31 */
/* @0x127468 mlaeq r1, r4, lr, r4 */

/* ── FUNC 0x12746c · F_CheckKeyPressed(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0x12746c push {r4, r5, r6, r7, r8, lr} */
/* @0x127470 mov r8, #0 */
/* @0x127474 mov r5, r0 */
/* @0x127478 str r8, [r0, #0xc] */
/* @0x12747c str r8, [r0] */
/* @0x127480 mov r1, r8 */
/* @0x127484 str r8, [r0, #0x4] */
/* @0x127488 ldr r0, [sp, #0x18] */
/* @0x12748c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x127490 subs r3, r0, #0 */
/* @0x127494 bne 0x1274d4 <_Z17F_CheckKeyPressedR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x127498 mov r4, r3 */
/* @0x12749c str r3, [r5] */
/* @0x1274a0 mov r6, r3 */
/* @0x1274a4 mov r3, r8 */
/* @0x1274a8 movt r3, #0x3ff0 */
/* @0x1274ac str r3, [r5, #0x4] */
/* @0x1274b0 mov r0, r4 */
/* @0x1274b4 add r4, r4, #1 */
/* @0x1274b8 bl 0x18bf0c <_Z14IO_Key_Pressedi> */
/* @0x1274bc cmp r0, #0 */
/* @0x1274c0 strne r6, [r5] */
/* @0x1274c4 strne r6, [r5, #0x4] */
/* @0x1274c8 cmp r4, #256 */
/* @0x1274cc bne 0x1274b0 <_Z17F_CheckKeyPressedR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1274d0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1274d4 cmp r3, #1 */
/* @0x1274d8 beq 0x127508 <_Z17F_CheckKeyPressedR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1274dc sub r3, r3, #2 */
/* @0x1274e0 cmp r3, #253 */
/* @0x1274e4 pophi {r4, r5, r6, r7, r8, pc} */
/* @0x1274e8 bl 0x18bf0c <_Z14IO_Key_Pressedi> */
/* @0x1274ec vmov s15, r0 */
/* @0x1274f0 vcvt.f64.u32 d7, s15 */
/* @0x1274f4 vmov r0, r1, d7 */
/* @0x1274f8 vmov r2, s14 */
/* @0x1274fc mov r3, r1 */
/* @0x127500 stm r5, {r2, r3} */
/* @0x127504 pop {r4, r5, r6, r7, r8, pc} */
/* @0x127508 mov r6, #0 */
/* @0x12750c movt r6, #0x3ff0 */
/* @0x127510 mov r4, r8 */
/* @0x127514 mov r7, r8 */
/* @0x127518 str r8, [r5] */
/* @0x12751c str r8, [r5, #0x4] */
/* @0x127520 mov r0, r4 */
/* @0x127524 add r4, r4, #1 */
/* @0x127528 bl 0x18bf0c <_Z14IO_Key_Pressedi> */
/* @0x12752c cmp r0, #0 */
/* @0x127530 strne r7, [r5] */
/* @0x127534 strne r6, [r5, #0x4] */
/* @0x127538 cmp r4, #256 */
/* @0x12753c bne 0x127520 <_Z17F_CheckKeyPressedR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x127540 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x127544 · F_CheckKeyReleased(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x127544 push {r4, r5, r6, r7, r8, lr} */
/* @0x127548 mov r8, #0 */
/* @0x12754c mov r5, r0 */
/* @0x127550 str r8, [r0, #0xc] */
/* @0x127554 str r8, [r0] */
/* @0x127558 mov r1, r8 */
/* @0x12755c str r8, [r0, #0x4] */
/* @0x127560 ldr r0, [sp, #0x18] */
/* @0x127564 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x127568 subs r3, r0, #0 */
/* @0x12756c bne 0x1275ac <_Z18F_CheckKeyReleasedR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x127570 mov r4, r3 */
/* @0x127574 str r3, [r5] */
/* @0x127578 mov r6, r3 */
/* @0x12757c mov r3, r8 */
/* @0x127580 movt r3, #0x3ff0 */
/* @0x127584 str r3, [r5, #0x4] */
/* @0x127588 mov r0, r4 */
/* @0x12758c add r4, r4, #1 */
/* @0x127590 bl 0x18bf30 <_Z15IO_Key_Releasedi> */
/* @0x127594 cmp r0, #0 */
/* @0x127598 strne r6, [r5] */
/* @0x12759c strne r6, [r5, #0x4] */
/* @0x1275a0 cmp r4, #256 */
/* @0x1275a4 bne 0x127588 <_Z18F_CheckKeyReleasedR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1275a8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1275ac cmp r3, #1 */
/* @0x1275b0 beq 0x1275dc <_Z18F_CheckKeyReleasedR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1275b4 cmp r3, #255 */
/* @0x1275b8 pophi {r4, r5, r6, r7, r8, pc} */
/* @0x1275bc bl 0x18bf30 <_Z15IO_Key_Releasedi> */
/* @0x1275c0 vmov s15, r0 */
/* @0x1275c4 vcvt.f64.u32 d7, s15 */
/* @0x1275c8 vmov r0, r1, d7 */
/* @0x1275cc vmov r2, s14 */
/* @0x1275d0 mov r3, r1 */
/* @0x1275d4 stm r5, {r2, r3} */
/* @0x1275d8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1275dc mov r6, #0 */
/* @0x1275e0 movt r6, #0x3ff0 */
/* @0x1275e4 mov r4, r8 */
/* @0x1275e8 mov r7, r8 */
/* @0x1275ec str r8, [r5] */
/* @0x1275f0 str r8, [r5, #0x4] */
/* @0x1275f4 mov r0, r4 */
/* @0x1275f8 add r4, r4, #1 */
/* @0x1275fc bl 0x18bf30 <_Z15IO_Key_Releasedi> */
/* @0x127600 cmp r0, #0 */
/* @0x127604 strne r7, [r5] */
/* @0x127608 strne r6, [r5, #0x4] */
/* @0x12760c cmp r4, #256 */
/* @0x127610 bne 0x1275f4 <_Z18F_CheckKeyReleasedR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x127614 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x127618 · F_MouseClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x127618 push {r4, lr} */
/* @0x12761c ldr r4, [sp, #0x8] */
/* @0x127620 bl 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x127624 mov r1, #0 */
/* @0x127628 mov r0, r4 */
/* @0x12762c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x127630 cmn r0, #1 */
/* @0x127634 beq 0x127644 <_Z12F_MouseClearR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x127638 mov r1, #0 */
/* @0x12763c pop {r4, lr} */
/* @0x127640 b 0x18c1b0 <_Z15IO_Button_Clearii> */
/* @0x127644 mov r0, #1 */
/* @0x127648 mov r1, #0 */
/* @0x12764c bl 0x18c1b0 <_Z15IO_Button_Clearii> */
/* @0x127650 mov r0, #2 */
/* @0x127654 mov r1, #0 */
/* @0x127658 bl 0x18c1b0 <_Z15IO_Button_Clearii> */
/* @0x12765c mov r0, #3 */
/* @0x127660 mov r1, #0 */
/* @0x127664 pop {r4, lr} */
/* @0x127668 b 0x18c1b0 <_Z15IO_Button_Clearii> */

/* ── FUNC 0x12766c · F_HighscoreSetFont(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x12766c push {r4, r5, r6, lr} */
/* @0x127670 mov r1, #0 */
/* @0x127674 ldr r4, [sp, #0x10] */
/* @0x127678 mov r0, r4 */
/* @0x12767c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x127680 mov r1, #1 */
/* @0x127684 mov r5, r0 */
/* @0x127688 mov r0, r4 */
/* @0x12768c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x127690 cmp r5, #0 */
/* @0x127694 mov r6, r0 */
/* @0x127698 popeq {r4, r5, r6, pc} */
/* @0x12769c mov r0, #12 */
/* @0x1276a0 bl 0x27c524 <_Znwj> */
/* @0x1276a4 mov r4, r0 */
/* @0x1276a8 mov r0, r5 */
/* @0x1276ac bl 0xb6538 <strlen@plt> */
/* @0x1276b0 str r0, [r4, #0x8] */
/* @0x1276b4 mov r0, r5 */
/* @0x1276b8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1276bc ldr r2, [pc, #0x20] */
/* @0x1276c0 ldr r3, [pc, #0x20] */
/* @0x1276c4 mov r1, #1 */
/* @0x1276c8 ldr r2, [pc, r2] */
/* @0x1276cc str r1, [r4, #0x4] */
/* @0x1276d0 ldr r3, [pc, r3] */
/* @0x1276d4 str r0, [r4] */
/* @0x1276d8 str r4, [r2] */
/* @0x1276dc str r6, [r3] */
/* @0x1276e0 pop {r4, r5, r6, pc} */
/* @0x1276e4 eoreq r7, r12, r4, asr #7 */
/* @0x1276e8 eoreq r7, r12, r0, asr #7 */

/* ── FUNC 0x1276ec · F_HighscoreShowExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=268 · insn=67 */
/* @0x1276ec push {r4, r5, r6, r7, r8, lr} */
/* @0x1276f0 mov r1, #1 */
/* @0x1276f4 ldr r4, [sp, #0x18] */
/* @0x1276f8 ldr r5, [pc, #0xdc] */
/* @0x1276fc mov r0, r4 */
/* @0x127700 add r5, pc, r5 */
/* @0x127704 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x127708 ldr r3, [pc, #0xd0] */
/* @0x12770c mov r1, #2 */
/* @0x127710 ldr r3, [r5, r3] */
/* @0x127714 str r0, [r3] */
/* @0x127718 mov r0, r4 */
/* @0x12771c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x127720 ldr r3, [pc, #0xbc] */
/* @0x127724 mov r1, #3 */
/* @0x127728 ldr r3, [r5, r3] */
/* @0x12772c strb r0, [r3] */
/* @0x127730 mov r0, r4 */
/* @0x127734 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x127738 ldr r3, [pc, #0xa8] */
/* @0x12773c mov r1, #4 */
/* @0x127740 ldr r3, [r5, r3] */
/* @0x127744 str r0, [r3] */
/* @0x127748 mov r0, r4 */
/* @0x12774c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x127750 ldr r12, [pc, #0x94] */
/* @0x127754 ldr r2, [pc, #0x94] */
/* @0x127758 mov r1, #5 */
/* @0x12775c mov r3, #0 */
/* @0x127760 ldr r12, [r5, r12] */
/* @0x127764 str r0, [r12] */
/* @0x127768 mov r0, r4 */
/* @0x12776c ldr r8, [r5, r2] */
/* @0x127770 str r3, [r8] */
/* @0x127774 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x127778 mov r7, r0 */
/* @0x12777c mov r0, #12 */
/* @0x127780 bl 0x27c524 <_Znwj> */
/* @0x127784 mov r6, r0 */
/* @0x127788 subs r0, r7, #0 */
/* @0x12778c beq 0x127794 <_Z18F_HighscoreShowExtR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x127790 bl 0xb6538 <strlen@plt> */
/* @0x127794 str r0, [r6, #0x8] */
/* @0x127798 mov r0, r7 */
/* @0x12779c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1277a0 mov r3, #1 */
/* @0x1277a4 mov r1, #6 */
/* @0x1277a8 stm r6, {r0, r3} */
/* @0x1277ac mov r0, r4 */
/* @0x1277b0 str r6, [r8] */
/* @0x1277b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1277b8 ldr r3, [pc, #0x34] */
/* @0x1277bc mov r1, #0 */
/* @0x1277c0 ldr r3, [r5, r3] */
/* @0x1277c4 str r0, [r3] */
/* @0x1277c8 mov r0, r4 */
/* @0x1277cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1277d0 bl 0x1dc2d4 <_Z14HighScore_Showi> */
/* @0x1277d4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1277d8 b 0x18c2c8 <_Z8IO_Clearv> */
/* @0x1277dc eoreq r10, r12, r0, asr r5 */
/* @0x1277e0 .word 0xffffce28 */
/* @0x1277e4 .word 0xffffce08 */
/* @0x1277e8 .word 0xffffce20 */
/* @0x1277ec .word 0xffffce24 */
/* @0x1277f0 .word 0xffffce3c */
/* @0x1277f4 .word 0xffffce40 */

/* ── FUNC 0x1277f8 · YYGML_keyboard_check(int) · size=136 · insn=34 */
/* @0x1277f8 push {r3, r4, r5, lr} */
/* @0x1277fc subs r4, r0, #0 */
/* @0x127800 bne 0x12782c <_Z20YYGML_keyboard_checki+0x34> */
/* @0x127804 mov r5, #1 */
/* @0x127808 mov r0, r4 */
/* @0x12780c add r4, r4, #1 */
/* @0x127810 bl 0x18bee8 <_Z11IO_Key_Downi> */
/* @0x127814 cmp r0, #0 */
/* @0x127818 movne r5, #0 */
/* @0x12781c cmp r4, #256 */
/* @0x127820 bne 0x127808 <_Z20YYGML_keyboard_checki+0x10> */
/* @0x127824 mov r0, r5 */
/* @0x127828 pop {r3, r4, r5, pc} */
/* @0x12782c cmp r4, #1 */
/* @0x127830 beq 0x127848 <_Z20YYGML_keyboard_checki+0x50> */
/* @0x127834 cmp r4, #255 */
/* @0x127838 movhi r5, #0 */
/* @0x12783c bhi 0x127824 <_Z20YYGML_keyboard_checki+0x2c> */
/* @0x127840 pop {r3, r4, r5, lr} */
/* @0x127844 b 0x18bee8 <_Z11IO_Key_Downi> */
/* @0x127848 mov r4, #0 */
/* @0x12784c b 0x127858 <_Z20YYGML_keyboard_checki+0x60> */
/* @0x127850 cmp r4, #256 */
/* @0x127854 beq 0x127878 <_Z20YYGML_keyboard_checki+0x80> */
/* @0x127858 mov r0, r4 */
/* @0x12785c add r4, r4, #1 */
/* @0x127860 bl 0x18bee8 <_Z11IO_Key_Downi> */
/* @0x127864 cmp r0, #0 */
/* @0x127868 beq 0x127850 <_Z20YYGML_keyboard_checki+0x58> */
/* @0x12786c mov r5, #1 */
/* @0x127870 mov r0, r5 */
/* @0x127874 pop {r3, r4, r5, pc} */
/* @0x127878 mov r5, r0 */
/* @0x12787c b 0x127824 <_Z20YYGML_keyboard_checki+0x2c> */

/* ── FUNC 0x127880 · F_CheckKey(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x127880 push {r3, r4, r5, lr} */
/* @0x127884 mov r5, #0 */
/* @0x127888 mov r4, r0 */
/* @0x12788c mov r1, r5 */
/* @0x127890 str r5, [r0, #0xc] */
/* @0x127894 ldr r0, [sp, #0x10] */
/* @0x127898 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12789c bl 0x1277f8 <_Z20YYGML_keyboard_checki> */
/* @0x1278a0 cmp r0, #0 */
/* @0x1278a4 moveq r5, r0 */
/* @0x1278a8 movne r3, r5 */
/* @0x1278ac moveq r3, r5 */
/* @0x1278b0 movtne r3, #0x3ff0 */
/* @0x1278b4 str r5, [r4] */
/* @0x1278b8 str r3, [r4, #0x4] */
/* @0x1278bc pop {r3, r4, r5, pc} */

/* ── FUNC 0x1278c0 · YYGML_keyboard_check_direct(int) · size=4 · insn=1 */
/* @0x1278c0 b 0x1277f8 <_Z20YYGML_keyboard_checki> */

/* ── FUNC 0x1278c4 · InitInteractionFunctions() · size=4032 · insn=1008 */
/* @0x1278c4 push {r4, r5, r6, lr} */
/* @0x1278c8 ldr r4, [pc, #0xc40] */
/* @0x1278cc ldr r3, [pc, #0xc40] */
/* @0x1278d0 add r4, pc, r4 */
/* @0x1278d4 ldr r5, [r4, r3] */
/* @0x1278d8 ldr r0, [r5] */
/* @0x1278dc bl 0xb6538 <strlen@plt> */
/* @0x1278e0 mov r3, #1 */
/* @0x1278e4 ldr r1, [pc, #0xc2c] */
/* @0x1278e8 movw r2, #0x6e8 */
/* @0x1278ec add r1, pc, r1 */
/* @0x1278f0 add r6, r0, r3 */
/* @0x1278f4 mov r0, r6 */
/* @0x1278f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1278fc ldr r3, [pc, #0xc18] */
/* @0x127900 mov r2, r6 */
/* @0x127904 ldr r1, [r5] */
/* @0x127908 ldr r3, [r4, r3] */
/* @0x12790c str r0, [r3] */
/* @0x127910 bl 0xb65bc <memcpy@plt> */
/* @0x127914 ldr r1, [pc, #0xc04] */
/* @0x127918 mov r2, #1 */
/* @0x12791c ldr r0, [pc, #0xc00] */
/* @0x127920 mov r3, r2 */
/* @0x127924 add r0, pc, r0 */
/* @0x127928 ldr r1, [r4, r1] */
/* @0x12792c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127930 ldr r1, [pc, #0xbf0] */
/* @0x127934 ldr r0, [pc, #0xbf0] */
/* @0x127938 mov r2, #1 */
/* @0x12793c mov r3, r2 */
/* @0x127940 add r0, pc, r0 */
/* @0x127944 ldr r1, [r4, r1] */
/* @0x127948 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12794c ldr r1, [pc, #0xbdc] */
/* @0x127950 ldr r0, [pc, #0xbdc] */
/* @0x127954 mov r2, #1 */
/* @0x127958 mov r3, r2 */
/* @0x12795c add r0, pc, r0 */
/* @0x127960 ldr r1, [r4, r1] */
/* @0x127964 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127968 ldr r1, [pc, #0xbc8] */
/* @0x12796c ldr r0, [pc, #0xbc8] */
/* @0x127970 mov r2, #2 */
/* @0x127974 mov r3, #1 */
/* @0x127978 add r0, pc, r0 */
/* @0x12797c ldr r1, [r4, r1] */
/* @0x127980 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127984 ldr r1, [pc, #0xbb4] */
/* @0x127988 ldr r0, [pc, #0xbb4] */
/* @0x12798c mov r2, #1 */
/* @0x127990 mov r3, r2 */
/* @0x127994 add r0, pc, r0 */
/* @0x127998 ldr r1, [r4, r1] */
/* @0x12799c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1279a0 ldr r1, [pc, #0xba0] */
/* @0x1279a4 ldr r0, [pc, #0xba0] */
/* @0x1279a8 mov r2, #1 */
/* @0x1279ac mov r3, r2 */
/* @0x1279b0 add r0, pc, r0 */
/* @0x1279b4 ldr r1, [r4, r1] */
/* @0x1279b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1279bc ldr r1, [pc, #0xb8c] */
/* @0x1279c0 ldr r0, [pc, #0xb8c] */
/* @0x1279c4 mov r2, #1 */
/* @0x1279c8 mov r3, r2 */
/* @0x1279cc add r0, pc, r0 */
/* @0x1279d0 ldr r1, [r4, r1] */
/* @0x1279d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1279d8 ldr r1, [pc, #0xb78] */
/* @0x1279dc ldr r0, [pc, #0xb78] */
/* @0x1279e0 mov r2, #1 */
/* @0x1279e4 mov r3, r2 */
/* @0x1279e8 add r0, pc, r0 */
/* @0x1279ec ldr r1, [r4, r1] */
/* @0x1279f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1279f4 ldr r1, [pc, #0xb64] */
/* @0x1279f8 ldr r0, [pc, #0xb64] */
/* @0x1279fc mov r2, #1 */
/* @0x127a00 mov r3, r2 */
/* @0x127a04 add r0, pc, r0 */
/* @0x127a08 ldr r1, [r4, r1] */
/* @0x127a0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127a10 ldr r1, [pc, #0xb50] */
/* @0x127a14 ldr r0, [pc, #0xb50] */
/* @0x127a18 mov r2, #1 */
/* @0x127a1c mov r3, r2 */
/* @0x127a20 add r0, pc, r0 */
/* @0x127a24 ldr r1, [r4, r1] */
/* @0x127a28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127a2c ldr r1, [pc, #0xb3c] */
/* @0x127a30 ldr r0, [pc, #0xb3c] */
/* @0x127a34 mov r2, #1 */
/* @0x127a38 mov r3, r2 */
/* @0x127a3c add r0, pc, r0 */
/* @0x127a40 ldr r1, [r4, r1] */
/* @0x127a44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127a48 ldr r1, [pc, #0xb28] */
/* @0x127a4c ldr r0, [pc, #0xb28] */
/* @0x127a50 mov r2, #1 */
/* @0x127a54 mov r3, r2 */
/* @0x127a58 add r0, pc, r0 */
/* @0x127a5c ldr r1, [r4, r1] */
/* @0x127a60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127a64 ldr r1, [pc, #0xb14] */
/* @0x127a68 ldr r0, [pc, #0xb14] */
/* @0x127a6c mov r2, #1 */
/* @0x127a70 mov r3, r2 */
/* @0x127a74 add r0, pc, r0 */
/* @0x127a78 ldr r1, [r4, r1] */
/* @0x127a7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127a80 ldr r1, [pc, #0xb00] */
/* @0x127a84 ldr r0, [pc, #0xb00] */
/* @0x127a88 mov r2, #2 */
/* @0x127a8c mov r3, #1 */
/* @0x127a90 add r0, pc, r0 */
/* @0x127a94 ldr r1, [r4, r1] */
/* @0x127a98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127a9c ldr r1, [pc, #0xaec] */
/* @0x127aa0 ldr r0, [pc, #0xaec] */
/* @0x127aa4 mov r2, #2 */
/* @0x127aa8 mov r3, #1 */
/* @0x127aac add r0, pc, r0 */
/* @0x127ab0 ldr r1, [r4, r1] */
/* @0x127ab4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127ab8 ldr r1, [pc, #0xad8] */
/* @0x127abc ldr r0, [pc, #0xad8] */
/* @0x127ac0 mov r2, #2 */
/* @0x127ac4 mov r3, #1 */
/* @0x127ac8 add r0, pc, r0 */
/* @0x127acc ldr r1, [r4, r1] */
/* @0x127ad0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127ad4 ldr r1, [pc, #0xac4] */
/* @0x127ad8 ldr r0, [pc, #0xac4] */
/* @0x127adc mov r2, #3 */
/* @0x127ae0 mov r3, #1 */
/* @0x127ae4 add r0, pc, r0 */
/* @0x127ae8 ldr r1, [r4, r1] */
/* @0x127aec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127af0 ldr r1, [pc, #0xab0] */
/* @0x127af4 ldr r0, [pc, #0xab0] */
/* @0x127af8 mov r2, #3 */
/* @0x127afc mov r3, #1 */
/* @0x127b00 add r0, pc, r0 */
/* @0x127b04 ldr r1, [r4, r1] */
/* @0x127b08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127b0c ldr r1, [pc, #0xa9c] */
/* @0x127b10 ldr r0, [pc, #0xa9c] */
/* @0x127b14 mov r2, #4 */
/* @0x127b18 mov r3, #1 */
/* @0x127b1c add r0, pc, r0 */
/* @0x127b20 ldr r1, [r4, r1] */
/* @0x127b24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127b28 ldr r1, [pc, #0xa88] */
/* @0x127b2c ldr r0, [pc, #0xa88] */
/* @0x127b30 mov r2, #1 */
/* @0x127b34 mov r3, #0 */
/* @0x127b38 add r0, pc, r0 */
/* @0x127b3c ldr r1, [r4, r1] */
/* @0x127b40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127b44 ldr r1, [pc, #0xa74] */
/* @0x127b48 ldr r0, [pc, #0xa74] */
/* @0x127b4c mov r2, #1 */
/* @0x127b50 mov r3, #0 */
/* @0x127b54 add r0, pc, r0 */
/* @0x127b58 ldr r1, [r4, r1] */
/* @0x127b5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127b60 ldr r1, [pc, #0xa60] */
/* @0x127b64 ldr r0, [pc, #0xa60] */
/* @0x127b68 mov r2, #1 */
/* @0x127b6c mov r3, #0 */
/* @0x127b70 add r0, pc, r0 */
/* @0x127b74 ldr r1, [r4, r1] */
/* @0x127b78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127b7c ldr r1, [pc, #0xa4c] */
/* @0x127b80 ldr r0, [pc, #0xa4c] */
/* @0x127b84 mov r2, #1 */
/* @0x127b88 mov r3, #0 */
/* @0x127b8c add r0, pc, r0 */
/* @0x127b90 ldr r1, [r4, r1] */
/* @0x127b94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127b98 ldr r1, [pc, #0xa38] */
/* @0x127b9c ldr r0, [pc, #0xa38] */
/* @0x127ba0 mov r2, #2 */
/* @0x127ba4 mov r3, #0 */
/* @0x127ba8 add r0, pc, r0 */
/* @0x127bac ldr r1, [r4, r1] */
/* @0x127bb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127bb4 ldr r1, [pc, #0xa24] */
/* @0x127bb8 ldr r0, [pc, #0xa24] */
/* @0x127bbc mov r2, #0 */
/* @0x127bc0 mov r3, r2 */
/* @0x127bc4 add r0, pc, r0 */
/* @0x127bc8 ldr r1, [r4, r1] */
/* @0x127bcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127bd0 ldr r1, [pc, #0xa10] */
/* @0x127bd4 ldr r0, [pc, #0xa10] */
/* @0x127bd8 mov r2, #1 */
/* @0x127bdc mov r3, #0 */
/* @0x127be0 add r0, pc, r0 */
/* @0x127be4 ldr r1, [r4, r1] */
/* @0x127be8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127bec ldr r1, [pc, #0x9fc] */
/* @0x127bf0 ldr r0, [pc, #0x9fc] */
/* @0x127bf4 mov r2, #1 */
/* @0x127bf8 mov r3, #0 */
/* @0x127bfc add r0, pc, r0 */
/* @0x127c00 ldr r1, [r4, r1] */
/* @0x127c04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127c08 ldr r1, [pc, #0x9e8] */
/* @0x127c0c ldr r0, [pc, #0x9e8] */
/* @0x127c10 mov r2, #1 */
/* @0x127c14 mov r3, #0 */
/* @0x127c18 add r0, pc, r0 */
/* @0x127c1c ldr r1, [r4, r1] */
/* @0x127c20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127c24 ldr r1, [pc, #0x9d4] */
/* @0x127c28 ldr r0, [pc, #0x9d4] */
/* @0x127c2c mov r2, #1 */
/* @0x127c30 mov r3, #0 */
/* @0x127c34 add r0, pc, r0 */
/* @0x127c38 ldr r1, [r4, r1] */
/* @0x127c3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127c40 ldr r1, [pc, #0x9c0] */
/* @0x127c44 ldr r0, [pc, #0x9c0] */
/* @0x127c48 mov r2, #3 */
/* @0x127c4c mov r3, #0 */
/* @0x127c50 add r0, pc, r0 */
/* @0x127c54 ldr r1, [r4, r1] */
/* @0x127c58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127c5c ldr r1, [pc, #0x9ac] */
/* @0x127c60 ldr r0, [pc, #0x9ac] */
/* @0x127c64 mov r2, #3 */
/* @0x127c68 mov r3, #0 */
/* @0x127c6c add r0, pc, r0 */
/* @0x127c70 ldr r1, [r4, r1] */
/* @0x127c74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127c78 ldr r1, [pc, #0x998] */
/* @0x127c7c ldr r0, [pc, #0x998] */
/* @0x127c80 mov r2, #3 */
/* @0x127c84 mov r3, #0 */
/* @0x127c88 add r0, pc, r0 */
/* @0x127c8c ldr r1, [r4, r1] */
/* @0x127c90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127c94 ldr r1, [pc, #0x984] */
/* @0x127c98 ldr r0, [pc, #0x984] */
/* @0x127c9c mov r2, #7 */
/* @0x127ca0 mov r3, #0 */
/* @0x127ca4 add r0, pc, r0 */
/* @0x127ca8 ldr r1, [r4, r1] */
/* @0x127cac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127cb0 ldr r1, [pc, #0x970] */
/* @0x127cb4 ldr r0, [pc, #0x970] */
/* @0x127cb8 mov r2, #0 */
/* @0x127cbc mov r3, r2 */
/* @0x127cc0 add r0, pc, r0 */
/* @0x127cc4 ldr r1, [r4, r1] */
/* @0x127cc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127ccc ldr r1, [pc, #0x95c] */
/* @0x127cd0 ldr r0, [pc, #0x95c] */
/* @0x127cd4 mov r2, #2 */
/* @0x127cd8 mov r3, #0 */
/* @0x127cdc add r0, pc, r0 */
/* @0x127ce0 ldr r1, [r4, r1] */
/* @0x127ce4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127ce8 ldr r1, [pc, #0x948] */
/* @0x127cec ldr r0, [pc, #0x948] */
/* @0x127cf0 mov r2, #0 */
/* @0x127cf4 mov r3, r2 */
/* @0x127cf8 add r0, pc, r0 */
/* @0x127cfc ldr r1, [r4, r1] */
/* @0x127d00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127d04 ldr r1, [pc, #0x934] */
/* @0x127d08 ldr r0, [pc, #0x934] */
/* @0x127d0c mov r2, #1 */
/* @0x127d10 mov r3, #0 */
/* @0x127d14 add r0, pc, r0 */
/* @0x127d18 ldr r1, [r4, r1] */
/* @0x127d1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127d20 ldr r1, [pc, #0x920] */
/* @0x127d24 ldr r0, [pc, #0x920] */
/* @0x127d28 mov r2, #1 */
/* @0x127d2c mov r3, #0 */
/* @0x127d30 add r0, pc, r0 */
/* @0x127d34 ldr r1, [r4, r1] */
/* @0x127d38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127d3c ldr r1, [pc, #0x90c] */
/* @0x127d40 ldr r0, [pc, #0x90c] */
/* @0x127d44 mov r2, #4 */
/* @0x127d48 mov r3, #0 */
/* @0x127d4c add r0, pc, r0 */
/* @0x127d50 ldr r1, [r4, r1] */
/* @0x127d54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127d58 ldr r1, [pc, #0x8f8] */
/* @0x127d5c ldr r0, [pc, #0x8f8] */
/* @0x127d60 mov r2, #4 */
/* @0x127d64 mov r3, #0 */
/* @0x127d68 add r0, pc, r0 */
/* @0x127d6c ldr r1, [r4, r1] */
/* @0x127d70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127d74 ldr r1, [pc, #0x8e4] */
/* @0x127d78 ldr r0, [pc, #0x8e4] */
/* @0x127d7c mov r2, #1 */
/* @0x127d80 mov r3, #0 */
/* @0x127d84 add r0, pc, r0 */
/* @0x127d88 ldr r1, [r4, r1] */
/* @0x127d8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127d90 ldr r1, [pc, #0x8d0] */
/* @0x127d94 ldr r0, [pc, #0x8d0] */
/* @0x127d98 mov r2, #1 */
/* @0x127d9c mov r3, #0 */
/* @0x127da0 add r0, pc, r0 */
/* @0x127da4 ldr r1, [r4, r1] */
/* @0x127da8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127dac ldr r1, [pc, #0x8bc] */
/* @0x127db0 ldr r0, [pc, #0x8bc] */
/* @0x127db4 mov r2, #1 */
/* @0x127db8 mov r3, #0 */
/* @0x127dbc add r0, pc, r0 */
/* @0x127dc0 ldr r1, [r4, r1] */
/* @0x127dc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127dc8 ldr r1, [pc, #0x8a8] */
/* @0x127dcc ldr r0, [pc, #0x8a8] */
/* @0x127dd0 mov r2, #4 */
/* @0x127dd4 mov r3, #0 */
/* @0x127dd8 add r0, pc, r0 */
/* @0x127ddc ldr r1, [r4, r1] */
/* @0x127de0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127de4 ldr r1, [pc, #0x894] */
/* @0x127de8 ldr r0, [pc, #0x894] */
/* @0x127dec mov r2, #4 */
/* @0x127df0 mov r3, #0 */
/* @0x127df4 add r0, pc, r0 */
/* @0x127df8 ldr r1, [r4, r1] */
/* @0x127dfc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127e00 ldr r1, [pc, #0x880] */
/* @0x127e04 ldr r0, [pc, #0x880] */
/* @0x127e08 mov r2, #4 */
/* @0x127e0c mov r3, #0 */
/* @0x127e10 add r0, pc, r0 */
/* @0x127e14 ldr r1, [r4, r1] */
/* @0x127e18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127e1c ldr r1, [pc, #0x86c] */
/* @0x127e20 ldr r0, [pc, #0x86c] */
/* @0x127e24 mov r2, #1 */
/* @0x127e28 mov r3, #0 */
/* @0x127e2c add r0, pc, r0 */
/* @0x127e30 ldr r1, [r4, r1] */
/* @0x127e34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127e38 ldr r1, [pc, #0x858] */
/* @0x127e3c ldr r0, [pc, #0x858] */
/* @0x127e40 mov r2, #1 */
/* @0x127e44 mov r3, #0 */
/* @0x127e48 add r0, pc, r0 */
/* @0x127e4c ldr r1, [r4, r1] */
/* @0x127e50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127e54 ldr r1, [pc, #0x844] */
/* @0x127e58 ldr r0, [pc, #0x844] */
/* @0x127e5c mov r2, #2 */
/* @0x127e60 mov r3, #0 */
/* @0x127e64 add r0, pc, r0 */
/* @0x127e68 ldr r1, [r4, r1] */
/* @0x127e6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127e70 ldr r1, [pc, #0x830] */
/* @0x127e74 ldr r0, [pc, #0x830] */
/* @0x127e78 mov r2, #2 */
/* @0x127e7c mov r3, #0 */
/* @0x127e80 add r0, pc, r0 */
/* @0x127e84 ldr r1, [r4, r1] */
/* @0x127e88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127e8c ldr r1, [pc, #0x81c] */
/* @0x127e90 ldr r0, [pc, #0x81c] */
/* @0x127e94 mov r2, #2 */
/* @0x127e98 mov r3, #0 */
/* @0x127e9c add r0, pc, r0 */
/* @0x127ea0 ldr r1, [r4, r1] */
/* @0x127ea4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127ea8 ldr r1, [pc, #0x808] */
/* @0x127eac ldr r0, [pc, #0x808] */
/* @0x127eb0 mov r2, #2 */
/* @0x127eb4 mov r3, #0 */
/* @0x127eb8 add r0, pc, r0 */
/* @0x127ebc ldr r1, [r4, r1] */
/* @0x127ec0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127ec4 ldr r1, [pc, #0x7f4] */
/* @0x127ec8 ldr r0, [pc, #0x7f4] */
/* @0x127ecc mov r2, #4 */
/* @0x127ed0 mov r3, #0 */
/* @0x127ed4 add r0, pc, r0 */
/* @0x127ed8 ldr r1, [r4, r1] */
/* @0x127edc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127ee0 ldr r1, [pc, #0x7e0] */
/* @0x127ee4 ldr r0, [pc, #0x7e0] */
/* @0x127ee8 mov r2, #2 */
/* @0x127eec mov r3, #0 */
/* @0x127ef0 add r0, pc, r0 */
/* @0x127ef4 ldr r1, [r4, r1] */
/* @0x127ef8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127efc ldr r1, [pc, #0x7cc] */
/* @0x127f00 ldr r0, [pc, #0x7cc] */
/* @0x127f04 mov r2, #2 */
/* @0x127f08 mov r3, #0 */
/* @0x127f0c add r0, pc, r0 */
/* @0x127f10 ldr r1, [r4, r1] */
/* @0x127f14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127f18 ldr r1, [pc, #0x7b8] */
/* @0x127f1c ldr r0, [pc, #0x7b8] */
/* @0x127f20 mov r2, #2 */
/* @0x127f24 mov r3, #0 */
/* @0x127f28 add r0, pc, r0 */
/* @0x127f2c ldr r1, [r4, r1] */
/* @0x127f30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127f34 ldr r1, [pc, #0x7a4] */
/* @0x127f38 ldr r0, [pc, #0x7a4] */
/* @0x127f3c mov r2, #2 */
/* @0x127f40 mov r3, #0 */
/* @0x127f44 add r0, pc, r0 */
/* @0x127f48 ldr r1, [r4, r1] */
/* @0x127f4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127f50 ldr r1, [pc, #0x790] */
/* @0x127f54 ldr r0, [pc, #0x790] */
/* @0x127f58 mov r2, #2 */
/* @0x127f5c mov r3, #0 */
/* @0x127f60 add r0, pc, r0 */
/* @0x127f64 ldr r1, [r4, r1] */
/* @0x127f68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127f6c ldr r1, [pc, #0x77c] */
/* @0x127f70 ldr r0, [pc, #0x77c] */
/* @0x127f74 mov r2, #1 */
/* @0x127f78 mov r3, #0 */
/* @0x127f7c add r0, pc, r0 */
/* @0x127f80 ldr r1, [r4, r1] */
/* @0x127f84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127f88 ldr r1, [pc, #0x768] */
/* @0x127f8c ldr r0, [pc, #0x768] */
/* @0x127f90 mov r2, #2 */
/* @0x127f94 mov r3, #0 */
/* @0x127f98 add r0, pc, r0 */
/* @0x127f9c ldr r1, [r4, r1] */
/* @0x127fa0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127fa4 ldr r1, [pc, #0x754] */
/* @0x127fa8 ldr r0, [pc, #0x754] */
/* @0x127fac mov r2, #2 */
/* @0x127fb0 mov r3, #0 */
/* @0x127fb4 add r0, pc, r0 */
/* @0x127fb8 ldr r1, [r4, r1] */
/* @0x127fbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127fc0 ldr r1, [pc, #0x740] */
/* @0x127fc4 ldr r0, [pc, #0x740] */
/* @0x127fc8 mov r2, #4 */
/* @0x127fcc mov r3, #0 */
/* @0x127fd0 add r0, pc, r0 */
/* @0x127fd4 ldr r1, [r4, r1] */
/* @0x127fd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127fdc ldr r1, [pc, #0x72c] */
/* @0x127fe0 ldr r0, [pc, #0x72c] */
/* @0x127fe4 mov r2, #4 */
/* @0x127fe8 mov r3, #0 */
/* @0x127fec add r0, pc, r0 */
/* @0x127ff0 ldr r1, [r4, r1] */
/* @0x127ff4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x127ff8 ldr r1, [pc, #0x718] */
/* @0x127ffc ldr r0, [pc, #0x718] */
/* @0x128000 mov r2, #1 */
/* @0x128004 mov r3, #0 */
/* @0x128008 add r0, pc, r0 */
/* @0x12800c ldr r1, [r4, r1] */
/* @0x128010 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128014 ldr r1, [pc, #0x704] */
/* @0x128018 ldr r0, [pc, #0x704] */
/* @0x12801c mov r2, #2 */
/* @0x128020 mov r3, #0 */
/* @0x128024 add r0, pc, r0 */
/* @0x128028 ldr r1, [r4, r1] */
/* @0x12802c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128030 ldr r1, [pc, #0x6f0] */
/* @0x128034 ldr r0, [pc, #0x6f0] */
/* @0x128038 mov r2, #0 */
/* @0x12803c mov r3, r2 */
/* @0x128040 add r0, pc, r0 */
/* @0x128044 ldr r1, [r4, r1] */
/* @0x128048 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12804c ldr r1, [pc, #0x6dc] */
/* @0x128050 ldr r0, [pc, #0x6dc] */
/* @0x128054 mov r2, #1 */
/* @0x128058 mov r3, #0 */
/* @0x12805c add r0, pc, r0 */
/* @0x128060 ldr r1, [r4, r1] */
/* @0x128064 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128068 ldr r1, [pc, #0x6c8] */
/* @0x12806c ldr r0, [pc, #0x6c8] */
/* @0x128070 mov r2, #1 */
/* @0x128074 mov r3, #0 */
/* @0x128078 add r0, pc, r0 */
/* @0x12807c ldr r1, [r4, r1] */
/* @0x128080 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128084 ldr r1, [pc, #0x6b4] */
/* @0x128088 ldr r0, [pc, #0x6b4] */
/* @0x12808c mov r2, #1 */
/* @0x128090 mov r3, #0 */
/* @0x128094 add r0, pc, r0 */
/* @0x128098 ldr r1, [r4, r1] */
/* @0x12809c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1280a0 ldr r1, [pc, #0x6a0] */
/* @0x1280a4 ldr r0, [pc, #0x6a0] */
/* @0x1280a8 mov r2, #2 */
/* @0x1280ac mov r3, #0 */
/* @0x1280b0 add r0, pc, r0 */
/* @0x1280b4 ldr r1, [r4, r1] */
/* @0x1280b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1280bc ldr r1, [pc, #0x68c] */
/* @0x1280c0 ldr r0, [pc, #0x68c] */
/* @0x1280c4 mov r2, #1 */
/* @0x1280c8 mov r3, #0 */
/* @0x1280cc add r0, pc, r0 */
/* @0x1280d0 ldr r1, [r4, r1] */
/* @0x1280d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1280d8 ldr r1, [pc, #0x678] */
/* @0x1280dc ldr r0, [pc, #0x678] */
/* @0x1280e0 mov r2, #0 */
/* @0x1280e4 mov r3, r2 */
/* @0x1280e8 add r0, pc, r0 */
/* @0x1280ec ldr r1, [r4, r1] */
/* @0x1280f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1280f4 ldr r1, [pc, #0x664] */
/* @0x1280f8 ldr r0, [pc, #0x664] */
/* @0x1280fc mov r2, #1 */
/* @0x128100 mov r3, #0 */
/* @0x128104 add r0, pc, r0 */
/* @0x128108 ldr r1, [r4, r1] */
/* @0x12810c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128110 ldr r1, [pc, #0x650] */
/* @0x128114 ldr r0, [pc, #0x650] */
/* @0x128118 mov r2, #1 */
/* @0x12811c mov r3, #0 */
/* @0x128120 add r0, pc, r0 */
/* @0x128124 ldr r1, [r4, r1] */
/* @0x128128 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12812c ldr r1, [pc, #0x63c] */
/* @0x128130 ldr r0, [pc, #0x63c] */
/* @0x128134 mov r2, #1 */
/* @0x128138 mov r3, #0 */
/* @0x12813c add r0, pc, r0 */
/* @0x128140 ldr r1, [r4, r1] */
/* @0x128144 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128148 ldr r1, [pc, #0x628] */
/* @0x12814c ldr r0, [pc, #0x628] */
/* @0x128150 mov r2, #1 */
/* @0x128154 mov r3, #0 */
/* @0x128158 add r0, pc, r0 */
/* @0x12815c ldr r1, [r4, r1] */
/* @0x128160 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128164 ldr r1, [pc, #0x614] */
/* @0x128168 ldr r0, [pc, #0x614] */
/* @0x12816c mov r2, #1 */
/* @0x128170 mov r3, #0 */
/* @0x128174 add r0, pc, r0 */
/* @0x128178 ldr r1, [r4, r1] */
/* @0x12817c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128180 ldr r1, [pc, #0x600] */
/* @0x128184 ldr r0, [pc, #0x600] */
/* @0x128188 mov r2, #1 */
/* @0x12818c mov r3, #0 */
/* @0x128190 add r0, pc, r0 */
/* @0x128194 ldr r1, [r4, r1] */
/* @0x128198 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12819c ldr r1, [pc, #0x5ec] */
/* @0x1281a0 ldr r0, [pc, #0x5ec] */
/* @0x1281a4 mov r2, #1 */
/* @0x1281a8 mov r3, #0 */
/* @0x1281ac add r0, pc, r0 */
/* @0x1281b0 ldr r1, [r4, r1] */
/* @0x1281b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1281b8 ldr r1, [pc, #0x5d8] */
/* @0x1281bc ldr r0, [pc, #0x5d8] */
/* @0x1281c0 mov r2, #0 */
/* @0x1281c4 mov r3, r2 */
/* @0x1281c8 add r0, pc, r0 */
/* @0x1281cc ldr r1, [r4, r1] */
/* @0x1281d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1281d4 ldr r1, [pc, #0x5c4] */
/* @0x1281d8 ldr r0, [pc, #0x5c4] */
/* @0x1281dc mov r2, #0 */
/* @0x1281e0 mov r3, r2 */
/* @0x1281e4 add r0, pc, r0 */
/* @0x1281e8 ldr r1, [r4, r1] */
/* @0x1281ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1281f0 ldr r3, [pc, #0x5b0] */
/* @0x1281f4 ldr r6, [r4, r3] */
/* @0x1281f8 ldrb r5, [r6] */
/* @0x1281fc cmp r5, #0 */
/* @0x128200 beq 0x128384 <_Z24InitInteractionFunctionsv+0xac0> */
/* @0x128204 ldr r1, [pc, #0x5a0] */
/* @0x128208 mov r2, #1 */
/* @0x12820c ldr r0, [pc, #0x59c] */
/* @0x128210 mov r3, #0 */
/* @0x128214 add r0, pc, r0 */
/* @0x128218 ldr r1, [r4, r1] */
/* @0x12821c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128220 ldr r1, [pc, #0x58c] */
/* @0x128224 ldr r0, [pc, #0x58c] */
/* @0x128228 mov r2, #1 */
/* @0x12822c mov r3, #0 */
/* @0x128230 add r0, pc, r0 */
/* @0x128234 ldr r1, [r4, r1] */
/* @0x128238 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12823c ldr r1, [pc, #0x578] */
/* @0x128240 ldr r0, [pc, #0x578] */
/* @0x128244 mov r2, #0 */
/* @0x128248 mov r3, r2 */
/* @0x12824c add r0, pc, r0 */
/* @0x128250 ldr r1, [r4, r1] */
/* @0x128254 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128258 ldr r1, [pc, #0x564] */
/* @0x12825c ldr r0, [pc, #0x564] */
/* @0x128260 mov r2, #0 */
/* @0x128264 mov r3, r2 */
/* @0x128268 add r0, pc, r0 */
/* @0x12826c ldr r1, [r4, r1] */
/* @0x128270 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128274 ldr r1, [pc, #0x550] */
/* @0x128278 ldr r0, [pc, #0x550] */
/* @0x12827c mov r2, #0 */
/* @0x128280 mov r3, r2 */
/* @0x128284 add r0, pc, r0 */
/* @0x128288 ldr r1, [r4, r1] */
/* @0x12828c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128290 ldr r1, [pc, #0x53c] */
/* @0x128294 ldr r0, [pc, #0x53c] */
/* @0x128298 mov r2, #0 */
/* @0x12829c mov r3, r2 */
/* @0x1282a0 add r0, pc, r0 */
/* @0x1282a4 ldr r1, [r4, r1] */
/* @0x1282a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1282ac ldr r1, [pc, #0x528] */
/* @0x1282b0 ldr r0, [pc, #0x528] */
/* @0x1282b4 mov r2, #0 */
/* @0x1282b8 mov r3, r2 */
/* @0x1282bc add r0, pc, r0 */
/* @0x1282c0 ldr r1, [r4, r1] */
/* @0x1282c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1282c8 ldr r1, [pc, #0x514] */
/* @0x1282cc ldr r0, [pc, #0x514] */
/* @0x1282d0 mov r2, #1 */
/* @0x1282d4 mov r3, #0 */
/* @0x1282d8 add r0, pc, r0 */
/* @0x1282dc ldr r1, [r4, r1] */
/* @0x1282e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1282e4 ldr r1, [pc, #0x500] */
/* @0x1282e8 ldr r0, [pc, #0x500] */
/* @0x1282ec mov r2, #2 */
/* @0x1282f0 mov r3, #0 */
/* @0x1282f4 add r0, pc, r0 */
/* @0x1282f8 ldr r1, [r4, r1] */
/* @0x1282fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128300 ldr r1, [pc, #0x4ec] */
/* @0x128304 ldr r0, [pc, #0x4ec] */
/* @0x128308 mov r2, #1 */
/* @0x12830c mov r3, #0 */
/* @0x128310 add r0, pc, r0 */
/* @0x128314 ldr r1, [r4, r1] */
/* @0x128318 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12831c ldr r1, [pc, #0x4d8] */
/* @0x128320 ldr r0, [pc, #0x4d8] */
/* @0x128324 mov r2, #1 */
/* @0x128328 mov r3, #0 */
/* @0x12832c add r0, pc, r0 */
/* @0x128330 ldr r1, [r4, r1] */
/* @0x128334 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128338 ldr r1, [pc, #0x4c4] */
/* @0x12833c ldr r0, [pc, #0x4c4] */
/* @0x128340 mov r2, #2 */
/* @0x128344 mov r3, #0 */
/* @0x128348 add r0, pc, r0 */
/* @0x12834c ldr r1, [r4, r1] */
/* @0x128350 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128354 ldr r1, [pc, #0x4b0] */
/* @0x128358 ldr r0, [pc, #0x4b0] */
/* @0x12835c mov r3, #0 */
/* @0x128360 mov r2, #2 */
/* @0x128364 add r0, pc, r0 */
/* @0x128368 ldr r1, [r4, r1] */
/* @0x12836c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128370 ldrb r3, [r6] */
/* @0x128374 cmp r3, #0 */
/* @0x128378 popeq {r4, r5, r6, pc} */
/* @0x12837c pop {r4, r5, r6, lr} */
/* @0x128380 b 0x1dbb30 <_Z19AddGestureFunctionsv> */
/* @0x128384 ldr r1, [pc, #0x488] */
/* @0x128388 mov r3, r5 */
/* @0x12838c ldr r0, [pc, #0x484] */
/* @0x128390 mov r2, #1 */
/* @0x128394 ldr r1, [r4, r1] */
/* @0x128398 add r0, pc, r0 */
/* @0x12839c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1283a0 ldr r1, [pc, #0x474] */
/* @0x1283a4 ldr r0, [pc, #0x474] */
/* @0x1283a8 mov r3, r5 */
/* @0x1283ac mov r2, #1 */
/* @0x1283b0 ldr r1, [r4, r1] */
/* @0x1283b4 add r0, pc, r0 */
/* @0x1283b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1283bc ldr r1, [pc, #0x460] */
/* @0x1283c0 ldr r0, [pc, #0x460] */
/* @0x1283c4 mov r3, r5 */
/* @0x1283c8 mov r2, #1 */
/* @0x1283cc ldr r1, [r4, r1] */
/* @0x1283d0 add r0, pc, r0 */
/* @0x1283d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1283d8 ldr r1, [pc, #0x44c] */
/* @0x1283dc ldr r0, [pc, #0x44c] */
/* @0x1283e0 mov r3, r5 */
/* @0x1283e4 mov r2, #1 */
/* @0x1283e8 ldr r1, [r4, r1] */
/* @0x1283ec add r0, pc, r0 */
/* @0x1283f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1283f4 ldr r1, [pc, #0x438] */
/* @0x1283f8 ldr r0, [pc, #0x438] */
/* @0x1283fc mov r3, r5 */
/* @0x128400 mov r2, #1 */
/* @0x128404 ldr r1, [r4, r1] */
/* @0x128408 add r0, pc, r0 */
/* @0x12840c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128410 ldr r1, [pc, #0x424] */
/* @0x128414 ldr r0, [pc, #0x424] */
/* @0x128418 mov r3, r5 */
/* @0x12841c mov r2, #1 */
/* @0x128420 ldr r1, [r4, r1] */
/* @0x128424 add r0, pc, r0 */
/* @0x128428 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12842c ldr r1, [pc, #0x410] */
/* @0x128430 ldr r0, [pc, #0x410] */
/* @0x128434 mov r3, r5 */
/* @0x128438 mov r2, #2 */
/* @0x12843c ldr r1, [r4, r1] */
/* @0x128440 add r0, pc, r0 */
/* @0x128444 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128448 ldr r1, [pc, #0x3fc] */
/* @0x12844c ldr r0, [pc, #0x3fc] */
/* @0x128450 mov r3, r5 */
/* @0x128454 mov r2, #1 */
/* @0x128458 ldr r1, [r4, r1] */
/* @0x12845c add r0, pc, r0 */
/* @0x128460 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128464 ldr r1, [pc, #0x3e8] */
/* @0x128468 ldr r0, [pc, #0x3e8] */
/* @0x12846c mov r3, r5 */
/* @0x128470 mov r2, #1 */
/* @0x128474 ldr r1, [r4, r1] */
/* @0x128478 add r0, pc, r0 */
/* @0x12847c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128480 ldr r1, [pc, #0x3d4] */
/* @0x128484 ldr r0, [pc, #0x3d4] */
/* @0x128488 mov r3, r5 */
/* @0x12848c mov r2, #1 */
/* @0x128490 ldr r1, [r4, r1] */
/* @0x128494 add r0, pc, r0 */
/* @0x128498 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12849c ldr r1, [pc, #0x3c0] */
/* @0x1284a0 ldr r0, [pc, #0x3c0] */
/* @0x1284a4 mov r3, r5 */
/* @0x1284a8 mov r2, #1 */
/* @0x1284ac ldr r1, [r4, r1] */
/* @0x1284b0 add r0, pc, r0 */
/* @0x1284b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1284b8 ldr r1, [pc, #0x3ac] */
/* @0x1284bc ldr r0, [pc, #0x3ac] */
/* @0x1284c0 mov r3, r5 */
/* @0x1284c4 mov r2, #1 */
/* @0x1284c8 ldr r1, [r4, r1] */
/* @0x1284cc add r0, pc, r0 */
/* @0x1284d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1284d4 ldr r1, [pc, #0x398] */
/* @0x1284d8 ldr r0, [pc, #0x398] */
/* @0x1284dc mov r3, r5 */
/* @0x1284e0 mov r2, #1 */
/* @0x1284e4 ldr r1, [r4, r1] */
/* @0x1284e8 add r0, pc, r0 */
/* @0x1284ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1284f0 ldr r1, [pc, #0x384] */
/* @0x1284f4 ldr r0, [pc, #0x384] */
/* @0x1284f8 mov r3, r5 */
/* @0x1284fc mov r2, #1 */
/* @0x128500 add r0, pc, r0 */
/* @0x128504 ldr r1, [r4, r1] */
/* @0x128508 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x12850c b 0x128204 <_Z24InitInteractionFunctionsv+0x940> */
/* @0x128510 eoreq r10, r12, r0, lsl #7 */
/* @0x128514 .word 0xffffce44 */
/* @0x128518 eoreq r4, r1, r8, asr #18 */
/* @0x12851c .word 0xffffce30 */
/* @0x128520 .word 0xffffce48 */
/* @0x128524 .word 0x002149d4 */
/* @0x128528 .word 0xffffce4c */
/* @0x12852c eoreq r4, r1, r12, asr #19 */
/* @0x128530 .word 0xffffce50 */
/* @0x128534 eoreq r4, r1, r8, asr #19 */
/* @0x128538 .word 0xffffce54 */
/* @0x12853c eoreq r4, r1, r0, asr #19 */
/* @0x128540 .word 0xffffce58 */
/* @0x128544 .word 0x002149b4 */
/* @0x128548 .word 0xffffce5c */
/* @0x12854c eoreq r4, r1, r12, lsr #19 */
/* @0x128550 .word 0xffffce60 */
/* @0x128554 eoreq r4, r1, r0, lsr #19 */
/* @0x128558 .word 0xffffce64 */
/* @0x12855c mlaeq r1, r8, r9, r4 */
/* @0x128560 .word 0xffffce68 */
/* @0x128564 eoreq r4, r1, r12, lsl #19 */
/* @0x128568 .word 0xffffce6c */
/* @0x12856c eoreq r4, r1, r4, lsl #19 */
/* @0x128570 .word 0xffffce70 */
/* @0x128574 eoreq r4, r1, r12, ror r9 */
/* @0x128578 .word 0xffffce74 */
/* @0x12857c eoreq r4, r1, r8, ror r9 */
/* @0x128580 .word 0xffffce78 */
/* @0x128584 eoreq r4, r1, r0, ror r9 */
/* @0x128588 .word 0xffffce7c */
/* @0x12858c eoreq r4, r1, r12, ror #18 */
/* @0x128590 .word 0xffffce80 */
/* @0x128594 eoreq r4, r1, r4, ror #18 */
/* @0x128598 .word 0xffffce84 */
/* @0x12859c eoreq r4, r1, r12, asr r9 */
/* @0x1285a0 .word 0xffffce88 */
/* @0x1285a4 eoreq r4, r1, r4, asr r9 */
/* @0x1285a8 .word 0xffffce8c */
/* @0x1285ac eoreq r4, r1, r4, asr #18 */
/* @0x1285b0 .word 0xffffce90 */
/* @0x1285b4 eoreq r4, r1, r4, lsr r9 */
/* @0x1285b8 .word 0xffffce94 */
/* @0x1285bc eoreq r4, r1, r4, lsr #18 */
/* @0x1285c0 .word 0xffffce98 */
/* @0x1285c4 eoreq r4, r1, r8, lsl r9 */
/* @0x1285c8 .word 0xffffce9c */
/* @0x1285cc eoreq r4, r1, r12, lsl #18 */
/* @0x1285d0 .word 0xffffcea0 */
/* @0x1285d4 eoreq r4, r1, r4, lsl #18 */
/* @0x1285d8 .word 0xffffcea4 */
/* @0x1285dc .word 0x002148fc */
/* @0x1285e0 .word 0xffffcea8 */
/* @0x1285e4 eoreq r4, r1, r12, ror #17 */
/* @0x1285e8 .word 0xffffceac */
/* @0x1285ec .word 0x002148dc */
/* @0x1285f0 .word 0xffffceb0 */
/* @0x1285f4 eoreq r4, r1, r12, asr #17 */
/* @0x1285f8 .word 0xffffceb4 */
/* @0x1285fc eoreq r4, r1, r0, asr #17 */
/* @0x128600 .word 0xffffceb8 */
/* @0x128604 eoreq r4, r1, r0, asr #17 */
/* @0x128608 .word 0xffffcebc */
/* @0x12860c .word 0x002148bc */
/* @0x128610 .word 0xffffcec0 */
/* @0x128614 .word 0x002148b4 */
/* @0x128618 .word 0xffffcec4 */
/* @0x12861c .word 0x002148b0 */
/* @0x128620 .word 0xffffcec8 */
/* @0x128624 eoreq r4, r1, r12, lsr #17 */
/* @0x128628 .word 0xffffcecc */
/* @0x12862c eoreq r4, r1, r4, lsr #17 */
/* @0x128630 .word 0xffffced0 */
/* @0x128634 mlaeq r1, r8, r8, r4 */
/* @0x128638 .word 0xffffced4 */
/* @0x12863c eoreq r4, r1, r12, lsl #17 */
/* @0x128640 .word 0xffffced8 */
/* @0x128644 eoreq r4, r1, r8, lsl #17 */
/* @0x128648 .word 0xffffcedc */
/* @0x12864c eoreq r4, r1, r12, ror r8 */
/* @0x128650 .word 0xffffcee0 */
/* @0x128654 eoreq r4, r1, r0, ror r8 */
/* @0x128658 .word 0xffffcee4 */
/* @0x12865c eoreq r4, r1, r4, ror #16 */
/* @0x128660 .word 0xffffcee8 */
/* @0x128664 eoreq r4, r1, r12, asr r8 */
/* @0x128668 .word 0xffffceec */
/* @0x12866c eoreq r4, r1, r4, asr r8 */
/* @0x128670 .word 0xffffcef0 */
/* @0x128674 eoreq r4, r1, r8, asr #16 */
/* @0x128678 .word 0xffffcef4 */
/* @0x12867c eoreq r4, r1, r12, lsr r8 */
/* @0x128680 .word 0xffffcef8 */
/* @0x128684 eoreq r4, r1, r4, lsr r8 */
/* @0x128688 .word 0xffffcefc */
/* @0x12868c eoreq r4, r1, r12, lsr #16 */
/* @0x128690 .word 0xffffcf00 */
/* @0x128694 eoreq r4, r1, r4, lsr #16 */
/* @0x128698 .word 0xffffcf04 */
/* @0x12869c eoreq r4, r1, r12, lsl r8 */
/* @0x1286a0 .word 0xffffcf08 */
/* @0x1286a4 eoreq r4, r1, r4, lsl r8 */
/* @0x1286a8 .word 0xffffcf0c */
/* @0x1286ac eoreq r4, r1, r12, lsl #16 */
/* @0x1286b0 .word 0xffffcf10 */
/* @0x1286b4 eoreq r4, r1, r0, lsl #16 */
/* @0x1286b8 .word 0xffffcf14 */
/* @0x1286bc .word 0x002147f4 */
/* @0x1286c0 .word 0xffffcf18 */
/* @0x1286c4 eoreq r4, r1, r4, ror #15 */
/* @0x1286c8 .word 0xffffcf1c */
/* @0x1286cc .word 0x002147d8 */
/* @0x1286d0 .word 0xffffcf20 */
/* @0x1286d4 eoreq r4, r1, r8, asr #15 */
/* @0x1286d8 .word 0xffffcf24 */
/* @0x1286dc eoreq r4, r1, r0, asr #15 */
/* @0x1286e0 .word 0xffffcf28 */
/* @0x1286e4 .word 0x002147b0 */
/* @0x1286e8 .word 0xffffcf2c */
/* @0x1286ec eoreq r4, r1, r8, lsr #15 */
/* @0x1286f0 .word 0xffffcf30 */
/* @0x1286f4 mlaeq r1, r12, r7, r4 */
/* @0x1286f8 .word 0xffffcf34 */
/* @0x1286fc eoreq r4, r1, r12, lsl #15 */
/* @0x128700 .word 0xffffcf38 */
/* @0x128704 eoreq r4, r1, r4, lsl #15 */
/* @0x128708 .word 0xffffcf3c */
/* @0x12870c eoreq r4, r1, r12, ror r7 */
/* @0x128710 .word 0xffffcf40 */
/* @0x128714 eoreq r4, r1, r8, ror r7 */
/* @0x128718 .word 0xffffcf44 */
/* @0x12871c eoreq r4, r1, r4, ror r7 */
/* @0x128720 .word 0xffffcf48 */
/* @0x128724 eoreq r4, r1, r8, ror #14 */
/* @0x128728 .word 0xffffcf4c */
/* @0x12872c eoreq r4, r1, r0, ror #14 */
/* @0x128730 .word 0xffffcf50 */
/* @0x128734 eoreq r4, r1, r12, asr r7 */
/* @0x128738 .word 0xffffcf54 */
/* @0x12873c eoreq r4, r1, r8, asr r7 */
/* @0x128740 .word 0xffffcf58 */
/* @0x128744 eoreq r4, r1, r0, asr r7 */
/* @0x128748 .word 0xffffcf5c */
/* @0x12874c eoreq r4, r1, r12, asr #14 */
/* @0x128750 .word 0xffffcf60 */
/* @0x128754 eoreq r4, r1, r4, asr #14 */
/* @0x128758 .word 0xffffcf64 */
/* @0x12875c eoreq r4, r1, r12, lsr r7 */
/* @0x128760 .word 0xffffcf68 */
/* @0x128764 eoreq r4, r1, r4, lsr r7 */
/* @0x128768 .word 0xffffcf6c */
/* @0x12876c eoreq r4, r1, r8, lsr #14 */
/* @0x128770 .word 0xffffcf70 */
/* @0x128774 eoreq r4, r1, r4, lsr #14 */
/* @0x128778 .word 0xffffcf74 */
/* @0x12877c eoreq r4, r1, r0, lsr #14 */
/* @0x128780 .word 0xffffcf78 */
/* @0x128784 eoreq r4, r1, r12, lsl r7 */
/* @0x128788 .word 0xffffcf7c */
/* @0x12878c eoreq r4, r1, r4, lsl r7 */
/* @0x128790 .word 0xffffcf80 */
/* @0x128794 eoreq r4, r1, r4, lsl r7 */
/* @0x128798 .word 0xffffcf84 */
/* @0x12879c eoreq r4, r1, r4, lsl r7 */
/* @0x1287a0 .word 0xffffcf88 */
/* @0x1287a4 eoreq r4, r1, r8, lsl #14 */
/* @0x1287a8 .word 0xffffbcd4 */
/* @0x1287ac .word 0xffffcf8c */
/* @0x1287b0 eoreq r4, r1, r0, ror #15 */
/* @0x1287b4 .word 0xffffcf90 */
/* @0x1287b8 .word 0x002147d4 */
/* @0x1287bc .word 0xffffcf94 */
/* @0x1287c0 eoreq r4, r1, r4, asr #15 */
/* @0x1287c4 .word 0xffffcf98 */
/* @0x1287c8 .word 0x002147b4 */
/* @0x1287cc .word 0xffffcf9c */
/* @0x1287d0 eoreq r4, r1, r4, lsr #15 */
/* @0x1287d4 .word 0xffffcfa0 */
/* @0x1287d8 eoreq r4, r1, r4, lsr #15 */
/* @0x1287dc .word 0xffffcfa4 */
/* @0x1287e0 mlaeq r1, r8, r7, r4 */
/* @0x1287e4 .word 0xffffcfa8 */
/* @0x1287e8 eoreq r4, r1, r8, lsl #15 */
/* @0x1287ec .word 0xffffcfac */
/* @0x1287f0 eoreq r4, r1, r4, lsl #15 */
/* @0x1287f4 .word 0xffffcfb0 */
/* @0x1287f8 eoreq r4, r1, r4, ror r7 */
/* @0x1287fc .word 0xffffcfb4 */
/* @0x128800 eoreq r4, r1, r4, ror #14 */
/* @0x128804 .word 0xffffcfb8 */
/* @0x128808 eoreq r4, r1, r4, asr r7 */
/* @0x12880c .word 0xffffcfbc */
/* @0x128810 eoreq r4, r1, r8, asr #14 */
/* @0x128814 .word 0xffffcfc0 */
/* @0x128818 eoreq r4, r1, r8, ror #10 */
/* @0x12881c .word 0xffffcfc4 */
/* @0x128820 eoreq r4, r1, r12, asr r5 */
/* @0x128824 .word 0xffffcfc8 */
/* @0x128828 eoreq r4, r1, r4, asr r5 */
/* @0x12882c .word 0xffffcfcc */
/* @0x128830 eoreq r4, r1, r8, asr #10 */
/* @0x128834 .word 0xffffcfd0 */
/* @0x128838 eoreq r4, r1, r12, lsr r5 */
/* @0x12883c .word 0xffffcfd4 */
/* @0x128840 eoreq r4, r1, r4, lsr r5 */
/* @0x128844 .word 0xffffcfd8 */
/* @0x128848 eoreq r4, r1, r12, lsr #10 */
/* @0x12884c .word 0xffffcfdc */
/* @0x128850 eoreq r4, r1, r8, lsr #10 */
/* @0x128854 .word 0xffffcfe0 */
/* @0x128858 eoreq r4, r1, r12, lsl r5 */
/* @0x12885c .word 0xffffcfe4 */
/* @0x128860 eoreq r4, r1, r0, lsl r5 */
/* @0x128864 .word 0xffffcfe8 */
/* @0x128868 eoreq r4, r1, r4, lsl #10 */
/* @0x12886c .word 0xffffcfec */
/* @0x128870 .word 0x002144f8 */
/* @0x128874 .word 0xffffcff0 */
/* @0x128878 eoreq r4, r1, r12, ror #9 */
/* @0x12887c .word 0xffffcff4 */
/* @0x128880 eoreq r4, r1, r4, ror #9 */

/* ── FUNC 0x128884 · F_HighscoreSetStrings(RValue&, CInstance*, CInstance*, int, RValue*) · size=660 · insn=165 */
/* @0x128884 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x128888 ldr r7, [pc, #0x27c] */
/* @0x12888c ldr r8, [sp, #0x20] */
/* @0x128890 ldr r7, [pc, r7] */
/* @0x128894 ldr r4, [r7] */
/* @0x128898 cmp r4, #0 */
/* @0x12889c beq 0x1288c4 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1288a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1288a4 ldr r5, [r4, #0x4] */
/* @0x1288a8 sub r5, r5, #1 */
/* @0x1288ac str r5, [r4, #0x4] */
/* @0x1288b0 cmp r5, #0 */
/* @0x1288b4 beq 0x128a68 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1288b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1288bc mov r0, r4 */
/* @0x1288c0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1288c4 ldr r6, [pc, #0x244] */
/* @0x1288c8 ldr r6, [pc, r6] */
/* @0x1288cc ldr r4, [r6] */
/* @0x1288d0 cmp r4, #0 */
/* @0x1288d4 beq 0x1288fc <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1288d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1288dc ldr r5, [r4, #0x4] */
/* @0x1288e0 sub r5, r5, #1 */
/* @0x1288e4 str r5, [r4, #0x4] */
/* @0x1288e8 cmp r5, #0 */
/* @0x1288ec beq 0x128a30 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x1288f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1288f4 mov r0, r4 */
/* @0x1288f8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1288fc ldr r5, [pc, #0x210] */
/* @0x128900 ldr r5, [pc, r5] */
/* @0x128904 ldr r4, [r5] */
/* @0x128908 cmp r4, #0 */
/* @0x12890c beq 0x128934 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x128910 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x128914 ldr r9, [r4, #0x4] */
/* @0x128918 sub r9, r9, #1 */
/* @0x12891c str r9, [r4, #0x4] */
/* @0x128920 cmp r9, #0 */
/* @0x128924 beq 0x1289f8 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x128928 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x12892c mov r0, r4 */
/* @0x128930 bl 0x27d1d0 <_ZdlPv> */
/* @0x128934 mov r1, #0 */
/* @0x128938 mov r0, r8 */
/* @0x12893c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x128940 mov r9, r0 */
/* @0x128944 mov r0, #12 */
/* @0x128948 bl 0x27c524 <_Znwj> */
/* @0x12894c mov r4, r0 */
/* @0x128950 subs r0, r9, #0 */
/* @0x128954 beq 0x12895c <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x128958 bl 0xb6538 <strlen@plt> */
/* @0x12895c str r0, [r4, #0x8] */
/* @0x128960 mov r0, r9 */
/* @0x128964 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x128968 mov r3, #1 */
/* @0x12896c mov r1, r3 */
/* @0x128970 stm r4, {r0, r3} */
/* @0x128974 mov r0, r8 */
/* @0x128978 str r4, [r7] */
/* @0x12897c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x128980 mov r7, r0 */
/* @0x128984 mov r0, #12 */
/* @0x128988 bl 0x27c524 <_Znwj> */
/* @0x12898c mov r4, r0 */
/* @0x128990 subs r0, r7, #0 */
/* @0x128994 beq 0x12899c <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x128998 bl 0xb6538 <strlen@plt> */
/* @0x12899c str r0, [r4, #0x8] */
/* @0x1289a0 mov r0, r7 */
/* @0x1289a4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1289a8 mov r3, #1 */
/* @0x1289ac mov r1, #2 */
/* @0x1289b0 stm r4, {r0, r3} */
/* @0x1289b4 mov r0, r8 */
/* @0x1289b8 str r4, [r6] */
/* @0x1289bc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1289c0 mov r6, r0 */
/* @0x1289c4 mov r0, #12 */
/* @0x1289c8 bl 0x27c524 <_Znwj> */
/* @0x1289cc mov r4, r0 */
/* @0x1289d0 subs r0, r6, #0 */
/* @0x1289d4 beq 0x1289dc <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x1289d8 bl 0xb6538 <strlen@plt> */
/* @0x1289dc str r0, [r4, #0x8] */
/* @0x1289e0 mov r0, r6 */
/* @0x1289e4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1289e8 mov r3, #1 */
/* @0x1289ec stm r4, {r0, r3} */
/* @0x1289f0 str r4, [r5] */
/* @0x1289f4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1289f8 ldr r0, [r4] */
/* @0x1289fc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x128a00 str r9, [r4] */
/* @0x128a04 str r9, [r4, #0x8] */
/* @0x128a08 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x128a0c ldr r9, [r4, #0x4] */
/* @0x128a10 sub r9, r9, #1 */
/* @0x128a14 str r9, [r4, #0x4] */
/* @0x128a18 cmp r9, #0 */
/* @0x128a1c beq 0x128aa0 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x128a20 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x128a24 mov r0, r4 */
/* @0x128a28 bl 0x27d1d0 <_ZdlPv> */
/* @0x128a2c b 0x128928 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x128a30 ldr r0, [r4] */
/* @0x128a34 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x128a38 str r5, [r4] */
/* @0x128a3c str r5, [r4, #0x8] */
/* @0x128a40 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x128a44 ldr r5, [r4, #0x4] */
/* @0x128a48 sub r5, r5, #1 */
/* @0x128a4c str r5, [r4, #0x4] */
/* @0x128a50 cmp r5, #0 */
/* @0x128a54 beq 0x128ae8 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x128a58 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x128a5c mov r0, r4 */
/* @0x128a60 bl 0x27d1d0 <_ZdlPv> */
/* @0x128a64 b 0x1288f0 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x128a68 ldr r0, [r4] */
/* @0x128a6c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x128a70 str r5, [r4] */
/* @0x128a74 str r5, [r4, #0x8] */
/* @0x128a78 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x128a7c ldr r5, [r4, #0x4] */
/* @0x128a80 sub r5, r5, #1 */
/* @0x128a84 str r5, [r4, #0x4] */
/* @0x128a88 cmp r5, #0 */
/* @0x128a8c beq 0x128ac4 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x240> */
/* @0x128a90 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x128a94 mov r0, r4 */
/* @0x128a98 bl 0x27d1d0 <_ZdlPv> */
/* @0x128a9c b 0x1288b8 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x128aa0 ldr r0, [r4] */
/* @0x128aa4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x128aa8 mov r0, r4 */
/* @0x128aac str r9, [r4] */
/* @0x128ab0 str r9, [r4, #0x8] */
/* @0x128ab4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x128ab8 mov r0, r4 */
/* @0x128abc bl 0x27d1d0 <_ZdlPv> */
/* @0x128ac0 b 0x128a20 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x128ac4 ldr r0, [r4] */
/* @0x128ac8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x128acc mov r0, r4 */
/* @0x128ad0 str r5, [r4] */
/* @0x128ad4 str r5, [r4, #0x8] */
/* @0x128ad8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x128adc mov r0, r4 */
/* @0x128ae0 bl 0x27d1d0 <_ZdlPv> */
/* @0x128ae4 b 0x128a90 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x128ae8 ldr r0, [r4] */
/* @0x128aec bl 0xcef90 <_Z6YYFreePKv> */
/* @0x128af0 mov r0, r4 */
/* @0x128af4 str r5, [r4] */
/* @0x128af8 str r5, [r4, #0x8] */
/* @0x128afc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x128b00 mov r0, r4 */
/* @0x128b04 bl 0x27d1d0 <_ZdlPv> */
/* @0x128b08 b 0x128a58 <_Z21F_HighscoreSetStringsR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x128b0c .word 0x002c63b8 */
/* @0x128b10 eoreq r6, r12, r4, lsl #7 */
/* @0x128b14 eoreq r6, r12, r0, asr r3 */

/* ── FUNC 0x128b18 · F_YoYo_Win8_NULL(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x128b18 push {r3, lr} */
/* @0x128b1c mov r2, #0 */
/* @0x128b20 ldr r3, [pc, #0x28] */
/* @0x128b24 str r2, [r0] */
/* @0x128b28 ldr r3, [pc, r3] */
/* @0x128b2c str r2, [r0, #0x4] */
/* @0x128b30 str r2, [r0, #0xc] */
/* @0x128b34 ldr r0, [r3] */
/* @0x128b38 ldr r1, [pc, #0x14] */
/* @0x128b3c ldr r3, [r0] */
/* @0x128b40 add r1, pc, r1 */
/* @0x128b44 ldr r3, [r3, #0xc] */
/* @0x128b48 blx r3 */
/* @0x128b4c pop {r3, pc} */
/* @0x128b50 eoreq r4, r12, r12, ror #23 */
/* @0x128b54 eoreq r3, r1, r0, lsl #31 */

/* ── FUNC 0x128b58 · InitMetroFunctions() · size=1000 · insn=250 */
/* @0x128b58 push {r4, lr} */
/* @0x128b5c mov r2, #4 */
/* @0x128b60 ldr r4, [pc, #0x348] */
/* @0x128b64 mov r3, #0 */
/* @0x128b68 ldr r0, [pc, #0x344] */
/* @0x128b6c ldr r4, [pc, r4] */
/* @0x128b70 add r0, pc, r0 */
/* @0x128b74 mov r1, r4 */
/* @0x128b78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128b7c ldr r0, [pc, #0x334] */
/* @0x128b80 mov r2, #0 */
/* @0x128b84 mov r1, r4 */
/* @0x128b88 mov r3, r2 */
/* @0x128b8c add r0, pc, r0 */
/* @0x128b90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128b94 ldr r0, [pc, #0x320] */
/* @0x128b98 mov r1, r4 */
/* @0x128b9c mov r2, #1 */
/* @0x128ba0 add r0, pc, r0 */
/* @0x128ba4 mov r3, #0 */
/* @0x128ba8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128bac ldr r0, [pc, #0x30c] */
/* @0x128bb0 mov r2, #0 */
/* @0x128bb4 mov r1, r4 */
/* @0x128bb8 mov r3, r2 */
/* @0x128bbc add r0, pc, r0 */
/* @0x128bc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128bc4 ldr r0, [pc, #0x2f8] */
/* @0x128bc8 mov r1, r4 */
/* @0x128bcc mov r2, #1 */
/* @0x128bd0 add r0, pc, r0 */
/* @0x128bd4 mov r3, #0 */
/* @0x128bd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128bdc ldr r0, [pc, #0x2e4] */
/* @0x128be0 mov r1, r4 */
/* @0x128be4 mov r2, #1 */
/* @0x128be8 add r0, pc, r0 */
/* @0x128bec mov r3, #0 */
/* @0x128bf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128bf4 ldr r0, [pc, #0x2d0] */
/* @0x128bf8 mov r1, r4 */
/* @0x128bfc mov r2, #6 */
/* @0x128c00 add r0, pc, r0 */
/* @0x128c04 mov r3, #0 */
/* @0x128c08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128c0c ldr r0, [pc, #0x2bc] */
/* @0x128c10 mov r1, r4 */
/* @0x128c14 mov r2, #1 */
/* @0x128c18 add r0, pc, r0 */
/* @0x128c1c mov r3, #0 */
/* @0x128c20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128c24 ldr r0, [pc, #0x2a8] */
/* @0x128c28 mov r1, r4 */
/* @0x128c2c mov r2, #3 */
/* @0x128c30 add r0, pc, r0 */
/* @0x128c34 mov r3, #0 */
/* @0x128c38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128c3c ldr r0, [pc, #0x294] */
/* @0x128c40 mov r1, r4 */
/* @0x128c44 mov r2, #2 */
/* @0x128c48 add r0, pc, r0 */
/* @0x128c4c mov r3, #0 */
/* @0x128c50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128c54 ldr r0, [pc, #0x280] */
/* @0x128c58 mov r1, r4 */
/* @0x128c5c mov r2, #3 */
/* @0x128c60 add r0, pc, r0 */
/* @0x128c64 mov r3, #0 */
/* @0x128c68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128c6c ldr r0, [pc, #0x26c] */
/* @0x128c70 mov r1, r4 */
/* @0x128c74 mov r2, #3 */
/* @0x128c78 add r0, pc, r0 */
/* @0x128c7c mov r3, #0 */
/* @0x128c80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128c84 ldr r0, [pc, #0x258] */
/* @0x128c88 mov r1, r4 */
/* @0x128c8c mov r2, #3 */
/* @0x128c90 add r0, pc, r0 */
/* @0x128c94 mov r3, #0 */
/* @0x128c98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128c9c ldr r0, [pc, #0x244] */
/* @0x128ca0 mov r1, r4 */
/* @0x128ca4 mov r2, #2 */
/* @0x128ca8 add r0, pc, r0 */
/* @0x128cac mov r3, #0 */
/* @0x128cb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128cb4 ldr r0, [pc, #0x230] */
/* @0x128cb8 mov r1, r4 */
/* @0x128cbc mov r2, #3 */
/* @0x128cc0 add r0, pc, r0 */
/* @0x128cc4 mov r3, #0 */
/* @0x128cc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128ccc ldr r0, [pc, #0x21c] */
/* @0x128cd0 mov r1, r4 */
/* @0x128cd4 mov r2, #4 */
/* @0x128cd8 add r0, pc, r0 */
/* @0x128cdc mov r3, #0 */
/* @0x128ce0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128ce4 ldr r0, [pc, #0x208] */
/* @0x128ce8 mov r1, r4 */
/* @0x128cec mov r2, #4 */
/* @0x128cf0 add r0, pc, r0 */
/* @0x128cf4 mov r3, #0 */
/* @0x128cf8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128cfc ldr r0, [pc, #0x1f4] */
/* @0x128d00 mov r1, r4 */
/* @0x128d04 mov r2, #3 */
/* @0x128d08 add r0, pc, r0 */
/* @0x128d0c mov r3, #0 */
/* @0x128d10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128d14 ldr r0, [pc, #0x1e0] */
/* @0x128d18 mov r1, r4 */
/* @0x128d1c mov r2, #1 */
/* @0x128d20 add r0, pc, r0 */
/* @0x128d24 mov r3, #0 */
/* @0x128d28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128d2c ldr r0, [pc, #0x1cc] */
/* @0x128d30 mov r1, r4 */
/* @0x128d34 mov r2, #1 */
/* @0x128d38 add r0, pc, r0 */
/* @0x128d3c mov r3, #0 */
/* @0x128d40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128d44 ldr r0, [pc, #0x1b8] */
/* @0x128d48 mov r2, #0 */
/* @0x128d4c mov r1, r4 */
/* @0x128d50 mov r3, r2 */
/* @0x128d54 add r0, pc, r0 */
/* @0x128d58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128d5c ldr r0, [pc, #0x1a4] */
/* @0x128d60 mov r1, r4 */
/* @0x128d64 mov r2, #1 */
/* @0x128d68 add r0, pc, r0 */
/* @0x128d6c mov r3, #0 */
/* @0x128d70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128d74 ldr r0, [pc, #0x190] */
/* @0x128d78 mov r2, #0 */
/* @0x128d7c mov r1, r4 */
/* @0x128d80 mov r3, r2 */
/* @0x128d84 add r0, pc, r0 */
/* @0x128d88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128d8c ldr r0, [pc, #0x17c] */
/* @0x128d90 mov r1, r4 */
/* @0x128d94 mov r2, #8 */
/* @0x128d98 add r0, pc, r0 */
/* @0x128d9c mov r3, #0 */
/* @0x128da0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128da4 ldr r0, [pc, #0x168] */
/* @0x128da8 mov r1, r4 */
/* @0x128dac mov r2, #1 */
/* @0x128db0 add r0, pc, r0 */
/* @0x128db4 mov r3, #0 */
/* @0x128db8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128dbc ldr r0, [pc, #0x154] */
/* @0x128dc0 mov r1, r4 */
/* @0x128dc4 mov r2, #2 */
/* @0x128dc8 add r0, pc, r0 */
/* @0x128dcc mov r3, #0 */
/* @0x128dd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128dd4 ldr r0, [pc, #0x140] */
/* @0x128dd8 mov r1, r4 */
/* @0x128ddc mov r2, #1 */
/* @0x128de0 add r0, pc, r0 */
/* @0x128de4 mov r3, #0 */
/* @0x128de8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128dec ldr r0, [pc, #0x12c] */
/* @0x128df0 mov r2, #0 */
/* @0x128df4 mov r1, r4 */
/* @0x128df8 mov r3, r2 */
/* @0x128dfc add r0, pc, r0 */
/* @0x128e00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128e04 ldr r0, [pc, #0x118] */
/* @0x128e08 mov r1, r4 */
/* @0x128e0c mov r2, #1 */
/* @0x128e10 add r0, pc, r0 */
/* @0x128e14 mov r3, #0 */
/* @0x128e18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128e1c ldr r0, [pc, #0x104] */
/* @0x128e20 mov r1, r4 */
/* @0x128e24 mov r2, #2 */
/* @0x128e28 add r0, pc, r0 */
/* @0x128e2c mov r3, #0 */
/* @0x128e30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128e34 ldr r0, [pc, #0xf0] */
/* @0x128e38 mov r1, r4 */
/* @0x128e3c mov r2, #1 */
/* @0x128e40 add r0, pc, r0 */
/* @0x128e44 mov r3, #0 */
/* @0x128e48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128e4c ldr r0, [pc, #0xdc] */
/* @0x128e50 mov r1, r4 */
/* @0x128e54 mov r2, #1 */
/* @0x128e58 add r0, pc, r0 */
/* @0x128e5c mov r3, #0 */
/* @0x128e60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128e64 ldr r0, [pc, #0xc8] */
/* @0x128e68 mov r1, r4 */
/* @0x128e6c mov r2, #1 */
/* @0x128e70 add r0, pc, r0 */
/* @0x128e74 mov r3, #0 */
/* @0x128e78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128e7c ldr r0, [pc, #0xb4] */
/* @0x128e80 mov r1, r4 */
/* @0x128e84 mov r2, #1 */
/* @0x128e88 add r0, pc, r0 */
/* @0x128e8c mov r3, #0 */
/* @0x128e90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128e94 ldr r0, [pc, #0xa0] */
/* @0x128e98 mov r2, #0 */
/* @0x128e9c mov r1, r4 */
/* @0x128ea0 mov r3, r2 */
/* @0x128ea4 add r0, pc, r0 */
/* @0x128ea8 pop {r4, lr} */
/* @0x128eac b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x128eb0 eoreq r6, r12, r8, ror #1 */
/* @0x128eb4 eoreq r3, r1, r8, ror pc */
/* @0x128eb8 eoreq r3, r1, r12, ror pc */
/* @0x128ebc eoreq r3, r1, r4, lsl #31 */
/* @0x128ec0 eoreq r3, r1, r12, lsl #31 */
/* @0x128ec4 mlaeq r1, r4, pc, r3 */
/* @0x128ec8 mlaeq r1, r8, pc, r3 */
/* @0x128ecc mlaeq r1, r4, pc, r3 */
/* @0x128ed0 mlaeq r1, r4, pc, r3 */
/* @0x128ed4 mlaeq r1, r8, pc, r3 */
/* @0x128ed8 mlaeq r1, r4, pc, r3 */
/* @0x128edc mlaeq r1, r4, pc, r3 */
/* @0x128ee0 eoreq r3, r1, r12, lsl #31 */
/* @0x128ee4 eoreq r3, r1, r4, lsl #31 */
/* @0x128ee8 eoreq r3, r1, r12, ror pc */
/* @0x128eec eoreq r3, r1, r4, lsl #31 */
/* @0x128ef0 mlaeq r1, r0, pc, r3 */
/* @0x128ef4 mlaeq r1, r12, pc, r3 */
/* @0x128ef8 eoreq r3, r1, r12, lsr #31 */
/* @0x128efc .word 0x00213fbc */
/* @0x128f00 eoreq r3, r1, r4, asr #31 */
/* @0x128f04 .word 0x00213fbc */
/* @0x128f08 .word 0x00213fbc */
/* @0x128f0c .word 0x00213fbc */
/* @0x128f10 eoreq r3, r1, r12, asr #31 */
/* @0x128f14 eoreq r3, r1, r12, asr #31 */
/* @0x128f18 .word 0x00213fd0 */
/* @0x128f1c eoreq r3, r1, r0, ror #31 */
/* @0x128f20 eoreq r3, r1, r4, ror #31 */
/* @0x128f24 eoreq r3, r1, r12, ror #31 */
/* @0x128f28 .word 0x00213ff8 */
/* @0x128f2c eoreq r4, r1, r12 */
/* @0x128f30 eoreq r4, r1, r8, lsl r0 */
/* @0x128f34 eoreq r4, r1, r0, lsr #32 */
/* @0x128f38 eoreq r4, r1, r12, lsr #32 */
/* @0x128f3c eoreq r4, r1, r8, lsr r0 */

/* ── FUNC 0x128f40 · F_PartTypeCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x128f40 push {r4, lr} */
/* @0x128f44 mov r3, #0 */
/* @0x128f48 str r3, [r0, #0xc] */
/* @0x128f4c mov r4, r0 */
/* @0x128f50 bl 0x1a3068 <_Z19ParticleType_Createv> */
/* @0x128f54 vmov s15, r0 */
/* @0x128f58 vcvt.f64.s32 d7, s15 */
/* @0x128f5c vmov r0, r1, d7 */
/* @0x128f60 vmov r2, s14 */
/* @0x128f64 mov r3, r1 */
/* @0x128f68 stm r4, {r2, r3} */
/* @0x128f6c pop {r4, pc} */

/* ── FUNC 0x128f70 · F_PartTypeDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x128f70 push {r3, lr} */
/* @0x128f74 mov r1, #0 */
/* @0x128f78 ldr r0, [sp, #0x8] */
/* @0x128f7c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x128f80 pop {r3, lr} */
/* @0x128f84 b 0x1a3160 <_Z20ParticleType_Destroyi> */

/* ── FUNC 0x128f88 · F_PartTypeExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x128f88 push {r4, lr} */
/* @0x128f8c mov r3, #0 */
/* @0x128f90 mov r1, r3 */
/* @0x128f94 str r3, [r0, #0xc] */
/* @0x128f98 mov r4, r0 */
/* @0x128f9c ldr r0, [sp, #0x8] */
/* @0x128fa0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x128fa4 bl 0x1a2e14 <_Z19ParticleType_Existsi> */
/* @0x128fa8 vmov s15, r0 */
/* @0x128fac vcvt.f64.u32 d7, s15 */
/* @0x128fb0 vmov r0, r1, d7 */
/* @0x128fb4 vmov r2, s14 */
/* @0x128fb8 mov r3, r1 */
/* @0x128fbc stm r4, {r2, r3} */
/* @0x128fc0 pop {r4, pc} */

/* ── FUNC 0x128fc4 · F_PartTypeClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x128fc4 push {r3, lr} */
/* @0x128fc8 mov r1, #0 */
/* @0x128fcc ldr r0, [sp, #0x8] */
/* @0x128fd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x128fd4 pop {r3, lr} */
/* @0x128fd8 b 0x1a2f7c <_Z18ParticleType_Cleari> */

/* ── FUNC 0x128fdc · F_PartTypeShape(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x128fdc push {r3, r4, r5, lr} */
/* @0x128fe0 mov r1, #0 */
/* @0x128fe4 ldr r4, [sp, #0x10] */
/* @0x128fe8 mov r0, r4 */
/* @0x128fec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x128ff0 mov r1, #1 */
/* @0x128ff4 mov r5, r0 */
/* @0x128ff8 mov r0, r4 */
/* @0x128ffc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129000 mov r1, r0 */
/* @0x129004 mov r0, r5 */
/* @0x129008 pop {r3, r4, r5, lr} */
/* @0x12900c b 0x1a31a4 <_Z18ParticleType_Shapeii> */

/* ── FUNC 0x129010 · F_PartTypeSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x129010 push {r4, r5, r6, r7, r8, lr} */
/* @0x129014 mov r1, #0 */
/* @0x129018 ldr r4, [sp, #0x18] */
/* @0x12901c mov r0, r4 */
/* @0x129020 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129024 mov r1, #1 */
/* @0x129028 mov r5, r0 */
/* @0x12902c mov r0, r4 */
/* @0x129030 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129034 mov r1, #2 */
/* @0x129038 mov r8, r0 */
/* @0x12903c mov r0, r4 */
/* @0x129040 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x129044 mov r1, #3 */
/* @0x129048 mov r7, r0 */
/* @0x12904c mov r0, r4 */
/* @0x129050 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x129054 mov r1, #4 */
/* @0x129058 mov r6, r0 */
/* @0x12905c mov r0, r4 */
/* @0x129060 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x129064 mov r1, r8 */
/* @0x129068 mov r2, r7 */
/* @0x12906c mov r3, r6 */
/* @0x129070 str r0, [sp, #0x18] */
/* @0x129074 mov r0, r5 */
/* @0x129078 pop {r4, r5, r6, r7, r8, lr} */
/* @0x12907c b 0x1a31e0 <_Z19ParticleType_Spriteiibbb> */

/* ── FUNC 0x129080 · F_PartTypeSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x129080 push {r4, r5, r6, r7, r8, lr} */
/* @0x129084 mov r1, #0 */
/* @0x129088 ldr r4, [sp, #0x18] */
/* @0x12908c mov r0, r4 */
/* @0x129090 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129094 mov r1, #1 */
/* @0x129098 mov r5, r0 */
/* @0x12909c mov r0, r4 */
/* @0x1290a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1290a4 mov r1, #2 */
/* @0x1290a8 mov r8, r0 */
/* @0x1290ac mov r0, r4 */
/* @0x1290b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1290b4 mov r1, #3 */
/* @0x1290b8 mov r7, r0 */
/* @0x1290bc mov r0, r4 */
/* @0x1290c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1290c4 mov r1, #4 */
/* @0x1290c8 mov r6, r0 */
/* @0x1290cc mov r0, r4 */
/* @0x1290d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1290d4 mov r1, r8 */
/* @0x1290d8 mov r2, r7 */
/* @0x1290dc mov r3, r6 */
/* @0x1290e0 str r0, [sp, #0x18] */
/* @0x1290e4 mov r0, r5 */
/* @0x1290e8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1290ec b 0x1a322c <_Z17ParticleType_Sizeiffff> */

/* ── FUNC 0x1290f0 · F_PartTypeScale(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1290f0 push {r4, r5, r6, lr} */
/* @0x1290f4 mov r1, #0 */
/* @0x1290f8 ldr r4, [sp, #0x10] */
/* @0x1290fc mov r0, r4 */
/* @0x129100 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129104 mov r1, #1 */
/* @0x129108 mov r6, r0 */
/* @0x12910c mov r0, r4 */
/* @0x129110 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129114 mov r1, #2 */
/* @0x129118 mov r5, r0 */
/* @0x12911c mov r0, r4 */
/* @0x129120 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129124 mov r1, r5 */
/* @0x129128 mov r2, r0 */
/* @0x12912c mov r0, r6 */
/* @0x129130 pop {r4, r5, r6, lr} */
/* @0x129134 b 0x1a3278 <_Z18ParticleType_Scaleiff> */

/* ── FUNC 0x129138 · F_PartTypeLife(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x129138 push {r4, r5, r6, lr} */
/* @0x12913c mov r1, #0 */
/* @0x129140 ldr r4, [sp, #0x10] */
/* @0x129144 mov r0, r4 */
/* @0x129148 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12914c mov r1, #1 */
/* @0x129150 mov r6, r0 */
/* @0x129154 mov r0, r4 */
/* @0x129158 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12915c mov r1, #2 */
/* @0x129160 mov r5, r0 */
/* @0x129164 mov r0, r4 */
/* @0x129168 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12916c mov r1, r5 */
/* @0x129170 mov r2, r0 */
/* @0x129174 mov r0, r6 */
/* @0x129178 pop {r4, r5, r6, lr} */
/* @0x12917c b 0x1a32b4 <_Z17ParticleType_Lifeiii> */

/* ── FUNC 0x129180 · F_PartTypeStep(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x129180 push {r4, r5, r6, lr} */
/* @0x129184 mov r1, #0 */
/* @0x129188 ldr r4, [sp, #0x10] */
/* @0x12918c mov r0, r4 */
/* @0x129190 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129194 mov r1, #1 */
/* @0x129198 mov r6, r0 */
/* @0x12919c mov r0, r4 */
/* @0x1291a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1291a4 mov r1, #2 */
/* @0x1291a8 mov r5, r0 */
/* @0x1291ac mov r0, r4 */
/* @0x1291b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1291b4 mov r1, r5 */
/* @0x1291b8 mov r2, r0 */
/* @0x1291bc mov r0, r6 */
/* @0x1291c0 pop {r4, r5, r6, lr} */
/* @0x1291c4 b 0x1a32f0 <_Z17ParticleType_Stepiii> */

/* ── FUNC 0x1291c8 · F_PartTypeDeath(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1291c8 push {r4, r5, r6, lr} */
/* @0x1291cc mov r1, #0 */
/* @0x1291d0 ldr r4, [sp, #0x10] */
/* @0x1291d4 mov r0, r4 */
/* @0x1291d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1291dc mov r1, #1 */
/* @0x1291e0 mov r6, r0 */
/* @0x1291e4 mov r0, r4 */
/* @0x1291e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1291ec mov r1, #2 */
/* @0x1291f0 mov r5, r0 */
/* @0x1291f4 mov r0, r4 */
/* @0x1291f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1291fc mov r1, r5 */
/* @0x129200 mov r2, r0 */
/* @0x129204 mov r0, r6 */
/* @0x129208 pop {r4, r5, r6, lr} */
/* @0x12920c b 0x1a332c <_Z18ParticleType_Deathiii> */
