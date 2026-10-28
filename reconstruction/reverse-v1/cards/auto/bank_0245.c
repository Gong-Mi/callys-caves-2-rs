/* libyoyo.so 覆盖卡组 0245
 * 函数 0x2970f8..0x29922c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2970f8 · yyServer::yyServer(bool) · size=140 · insn=35 */
/* @0x2970f8 push {r4, r5, r6, lr} */
/* @0x2970fc mov r4, r0 */
/* @0x297100 strb r1, [r0, #0x1d] */
/* @0x297104 mov r5, #0 */
/* @0x297108 ldr r1, [pc, #0x6c] */
/* @0x29710c mov r2, #72 */
/* @0x297110 mov r3, #1 */
/* @0x297114 mov r0, #65536 */
/* @0x297118 add r1, pc, r1 */
/* @0x29711c str r5, [r4] */
/* @0x297120 str r5, [r4, #0x4] */
/* @0x297124 str r5, [r4, #0x8] */
/* @0x297128 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x29712c ldr r6, [pc, #0x4c] */
/* @0x297130 mov r12, #65536 */
/* @0x297134 mov r2, #131072 */
/* @0x297138 ldr r6, [pc, r6] */
/* @0x29713c movw r3, #0x3f6 */
/* @0x297140 strb r5, [r4, #0x1c] */
/* @0x297144 ldrb r1, [r6] */
/* @0x297148 str r5, [r4, #0x20] */
/* @0x29714c cmp r1, r5 */
/* @0x297150 str r5, [r4, #0x28] */
/* @0x297154 str r12, [r4, #0x10] */
/* @0x297158 str r2, [r4, #0x14] */
/* @0x29715c str r3, [r4, #0x24] */
/* @0x297160 str r0, [r4, #0xc] */
/* @0x297164 bne 0x297174 <_ZN8yyServerC2Eb+0x7c> */
/* @0x297168 bl 0x294d18 <_ZN8yySocket7StartupEv> */
/* @0x29716c mov r3, #1 */
/* @0x297170 strb r3, [r6] */
/* @0x297174 mov r0, r4 */
/* @0x297178 pop {r4, r5, r6, pc} */
/* @0x29717c andeq r2, r12, r12, lsl #8 */
/* @0x297180 andseq r10, r5, r4, ror #16 */

/* ── FUNC 0x2970f8 · yyServer::yyServer(bool) · alias of the symbol above · insn=0 */

/* ── FUNC 0x297184 · yyServer::~yyServer() · size=88 · insn=22 */
/* @0x297184 push {r3, r4, r5, lr} */
/* @0x297188 mov r4, r0 */
/* @0x29718c ldr r5, [r0] */
/* @0x297190 cmp r5, #0 */
/* @0x297194 beq 0x2971a8 <_ZN8yyServerD2Ev+0x24> */
/* @0x297198 mov r0, r5 */
/* @0x29719c bl 0x294cbc <_ZN8yySocketD2Ev> */
/* @0x2971a0 mov r0, r5 */
/* @0x2971a4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2971a8 mov r5, #0 */
/* @0x2971ac ldr r0, [r4, #0x4] */
/* @0x2971b0 str r5, [r4] */
/* @0x2971b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2971b8 ldr r0, [r4, #0x8] */
/* @0x2971bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2971c0 ldr r0, [r4, #0xc] */
/* @0x2971c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2971c8 str r5, [r4, #0x4] */
/* @0x2971cc str r5, [r4, #0x8] */
/* @0x2971d0 mov r0, r4 */
/* @0x2971d4 str r5, [r4, #0xc] */
/* @0x2971d8 pop {r3, r4, r5, pc} */

/* ── FUNC 0x297184 · yyServer::~yyServer() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2971dc · yyServer::Render() · size=4 · insn=1 */
/* @0x2971dc bx lr */

/* ── FUNC 0x2971e0 · yyServer::Init(eSocketType, int, int, bool) · size=752 · insn=188 */
/* @0x2971e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2971e4 mov r4, r1 */
/* @0x2971e8 ldr r7, [pc, #0x2c0] */
/* @0x2971ec sub r12, r4, #3 */
/* @0x2971f0 ldr r1, [pc, #0x2bc] */
/* @0x2971f4 sub sp, sp, #28 */
/* @0x2971f8 add r7, pc, r7 */
/* @0x2971fc cmp r12, #1 */
/* @0x297200 cmphi r4, #1 */
/* @0x297204 mov r6, r0 */
/* @0x297208 mov r10, r2 */
/* @0x29720c ldr r8, [r7, r1] */
/* @0x297210 str r3, [r0, #0x24] */
/* @0x297214 ldrb r11, [sp, #0x40] */
/* @0x297218 ldr r3, [r8] */
/* @0x29721c str r4, [r0, #0x20] */
/* @0x297220 str r3, [sp, #0x14] */
/* @0x297224 bls 0x297248 <_ZN8yyServer4InitE11eSocketTypeiib+0x68> */
/* @0x297228 mvn r9, #0 */
/* @0x29722c ldr r2, [sp, #0x14] */
/* @0x297230 mov r0, r9 */
/* @0x297234 ldr r3, [r8] */
/* @0x297238 cmp r2, r3 */
/* @0x29723c bne 0x2974ac <_ZN8yyServer4InitE11eSocketTypeiib+0x2cc> */
/* @0x297240 add sp, sp, #28 */
/* @0x297244 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x297248 mov r0, #200 */
/* @0x29724c bl 0x27c524 <_Znwj> */
/* @0x297250 mov r1, r4 */
/* @0x297254 mov r9, r0 */
/* @0x297258 bl 0x2970ac <_ZN8yySocketC2E11eSocketType> */
/* @0x29725c ldr r3, [pc, #0x254] */
/* @0x297260 mov r0, r9 */
/* @0x297264 ldr r5, [r7, r3] */
/* @0x297268 str r9, [r5] */
/* @0x29726c bl 0x294ec8 <_ZN8yySocket4InitEv> */
/* @0x297270 cmp r11, #0 */
/* @0x297274 ldrne r3, [r5] */
/* @0x297278 movne r2, #1 */
/* @0x29727c ldreq r0, [r5] */
/* @0x297280 movne r0, r3 */
/* @0x297284 strbne r2, [r3, #0x2c] */
/* @0x297288 bl 0x294f68 <_ZN8yySocket6CreateEv> */
/* @0x29728c ldr r0, [r5] */
/* @0x297290 ldr r9, [r0] */
/* @0x297294 cmn r9, #1 */
/* @0x297298 beq 0x2973ec <_ZN8yyServer4InitE11eSocketTypeiib+0x20c> */
/* @0x29729c mov r2, #0 */
/* @0x2972a0 mov r1, #2 */
/* @0x2972a4 str r2, [sp, #0x8] */
/* @0x2972a8 mov r3, r10 */
/* @0x2972ac str r2, [sp, #0xc] */
/* @0x2972b0 str r2, [sp, #0x10] */
/* @0x2972b4 strh r1, [sp, #4] */
/* @0x2972b8 rev16 r3, r3 */
/* @0x2972bc mov r2, #16 */
/* @0x2972c0 add r1, sp, #4 */
/* @0x2972c4 strh r3, [sp, #6] */
/* @0x2972c8 bl 0x2951c4 <_ZN8yySocket4BindEPK8sockaddri> */
/* @0x2972cc ldr r1, [pc, #0x1e8] */
/* @0x2972d0 ldr r3, [pc, #0x1e8] */
/* @0x2972d4 add r1, pc, r1 */
/* @0x2972d8 subs r9, r0, #0 */
/* @0x2972dc blt 0x29744c <_ZN8yyServer4InitE11eSocketTypeiib+0x26c> */
/* @0x2972e0 cmp r4, #0 */
/* @0x2972e4 cmpne r4, #3 */
/* @0x2972e8 beq 0x29742c <_ZN8yyServer4InitE11eSocketTypeiib+0x24c> */
/* @0x2972ec cmp r4, #1 */
/* @0x2972f0 cmpne r4, #4 */
/* @0x2972f4 beq 0x297470 <_ZN8yyServer4InitE11eSocketTypeiib+0x290> */
/* @0x2972f8 ldr r3, [r5] */
/* @0x2972fc str r3, [r6] */
/* @0x297300 movw r0, #0x1088 */
/* @0x297304 str r10, [r3, #0xac] */
/* @0x297308 mov r7, #0 */
/* @0x29730c bl 0x27c524 <_Znwj> */
/* @0x297310 mov r3, #1024 */
/* @0x297314 mov r1, r7 */
/* @0x297318 mov r2, #128 */
/* @0x29731c mov r4, r0 */
/* @0x297320 add r0, r0, #8 */
/* @0x297324 str r3, [r4] */
/* @0x297328 str r4, [r6, #0x4] */
/* @0x29732c str r7, [r4, #0x4] */
/* @0x297330 bl 0xb65b0 <memset@plt> */
/* @0x297334 add r0, r4, #136 */
/* @0x297338 mov r1, r7 */
/* @0x29733c mov r2, #4096 */
/* @0x297340 bl 0xb65b0 <memset@plt> */
/* @0x297344 ldr r0, [r6, #0x4] */
/* @0x297348 ldr r12, [r5] */
/* @0x29734c ldr r3, [r0, #0x4] */
/* @0x297350 cmp r3, #1024 */
/* @0x297354 bge 0x2973a4 <_ZN8yyServer4InitE11eSocketTypeiib+0x1c4> */
/* @0x297358 add r3, r0, #132 */
/* @0x29735c mov r1, r7 */
/* @0x297360 b 0x297370 <_ZN8yyServer4InitE11eSocketTypeiib+0x190> */
/* @0x297364 add r1, r1, #1 */
/* @0x297368 cmp r1, #1024 */
/* @0x29736c beq 0x297384 <_ZN8yyServer4InitE11eSocketTypeiib+0x1a4> */
/* @0x297370 ldr r2, [r3, #0x4]! */
/* @0x297374 cmp r2, #0 */
/* @0x297378 bne 0x297364 <_ZN8yyServer4InitE11eSocketTypeiib+0x184> */
/* @0x29737c add r1, r1, #34 */
/* @0x297380 str r12, [r0, r1, lsl #2] */
/* @0x297384 ldr r3, [r12] */
/* @0x297388 mov r12, #1 */
/* @0x29738c and r1, r3, #31 */
/* @0x297390 asr r3, r3, #5 */
/* @0x297394 add r0, r0, r3, lsl #2 */
/* @0x297398 ldr r2, [r0, #0x8] */
/* @0x29739c orr r3, r2, r12, lsl r1 */
/* @0x2973a0 str r3, [r0, #0x8] */
/* @0x2973a4 movw r0, #0x1088 */
/* @0x2973a8 mov r5, #0 */
/* @0x2973ac bl 0x27c524 <_Znwj> */
/* @0x2973b0 mov r3, #1024 */
/* @0x2973b4 mov r1, r5 */
/* @0x2973b8 mov r2, #128 */
/* @0x2973bc mov r9, r5 */
/* @0x2973c0 mov r4, r0 */
/* @0x2973c4 add r0, r0, #8 */
/* @0x2973c8 str r3, [r4] */
/* @0x2973cc str r4, [r6, #0x8] */
/* @0x2973d0 str r5, [r4, #0x4] */
/* @0x2973d4 bl 0xb65b0 <memset@plt> */
/* @0x2973d8 add r0, r4, #136 */
/* @0x2973dc mov r1, r5 */
/* @0x2973e0 mov r2, #4096 */
/* @0x2973e4 bl 0xb65b0 <memset@plt> */
/* @0x2973e8 b 0x29722c <_ZN8yyServer4InitE11eSocketTypeiib+0x4c> */
/* @0x2973ec ldr r3, [pc, #0xcc] */
/* @0x2973f0 ldr r1, [pc, #0xcc] */
/* @0x2973f4 ldr r3, [r7, r3] */
/* @0x2973f8 add r1, pc, r1 */
/* @0x2973fc ldr r0, [r3] */
/* @0x297400 ldr r3, [r0] */
/* @0x297404 ldr r3, [r3, #0xc] */
/* @0x297408 blx r3 */
/* @0x29740c ldr r4, [r5] */
/* @0x297410 cmp r4, #0 */
/* @0x297414 beq 0x297228 <_ZN8yyServer4InitE11eSocketTypeiib+0x48> */
/* @0x297418 mov r0, r4 */
/* @0x29741c bl 0x294cbc <_ZN8yySocketD2Ev> */
/* @0x297420 mov r0, r4 */
/* @0x297424 bl 0x27d1d0 <_ZdlPv> */
/* @0x297428 b 0x29722c <_ZN8yyServer4InitE11eSocketTypeiib+0x4c> */
/* @0x29742c ldr r0, [r5] */
/* @0x297430 mov r1, #5 */
/* @0x297434 bl 0x295240 <_ZN8yySocket6ListenEi> */
/* @0x297438 subs r9, r0, #0 */
/* @0x29743c bge 0x2972f8 <_ZN8yyServer4InitE11eSocketTypeiib+0x118> */
/* @0x297440 ldr r1, [pc, #0x80] */
/* @0x297444 ldr r3, [pc, #0x74] */
/* @0x297448 add r1, pc, r1 */
/* @0x29744c ldr r3, [r7, r3] */
/* @0x297450 ldr r0, [r3] */
/* @0x297454 ldr r3, [r0] */
/* @0x297458 ldr r3, [r3, #0xc] */
/* @0x29745c blx r3 */
/* @0x297460 ldr r4, [r5] */
/* @0x297464 cmp r4, #0 */
/* @0x297468 bne 0x297418 <_ZN8yyServer4InitE11eSocketTypeiib+0x238> */
/* @0x29746c b 0x29722c <_ZN8yyServer4InitE11eSocketTypeiib+0x4c> */
/* @0x297470 mov r0, #64 */
/* @0x297474 bl 0x27c524 <_Znwj> */
/* @0x297478 mov r2, #1 */
/* @0x29747c mov r3, r2 */
/* @0x297480 ldr r1, [r6, #0x14] */
/* @0x297484 mov r4, r0 */
/* @0x297488 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati> */
/* @0x29748c ldr r3, [pc, #0x38] */
/* @0x297490 ldr r2, [r5] */
/* @0x297494 ldr r1, [r7, r3] */
/* @0x297498 mov r3, r2 */
/* @0x29749c add r1, r1, #8 */
/* @0x2974a0 str r1, [r4] */
/* @0x2974a4 str r4, [r2, #0x4c] */
/* @0x2974a8 b 0x2972fc <_ZN8yyServer4InitE11eSocketTypeiib+0x11c> */
/* @0x2974ac bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2974b0 andseq r10, r5, r8, asr r10 */
/* @0x2974b4 .word 0xffffbd00 */
/* @0x2974b8 .word 0xfffffd50 */
/* @0x2974bc strheq r2, [r12], -r0 */
/* @0x2974c0 .word 0xffffbac4 */
/* @0x2974c4 andeq r2, r12, r4, ror #2 */
/* @0x2974c8 andeq r2, r12, r0, asr r1 */
/* @0x2974cc .word 0xffffbd60 */

/* ── FUNC 0x2974d0 · yyServer::Quit() · size=4 · insn=1 */
/* @0x2974d0 bx lr */

/* ── FUNC 0x2974d4 · yyServer::DeleteSocket(yySocket*) · size=132 · insn=33 */
/* @0x2974d4 push {r4, r5} */
/* @0x2974d8 mov r3, #0 */
/* @0x2974dc ldr r4, [r0, #0x4] */
/* @0x2974e0 add r2, r4, #132 */
/* @0x2974e4 b 0x2974f4 <_ZN8yyServer12DeleteSocketEP8yySocket+0x20> */
/* @0x2974e8 add r3, r3, #1 */
/* @0x2974ec cmp r3, #1024 */
/* @0x2974f0 beq 0x297548 <_ZN8yyServer12DeleteSocketEP8yySocket+0x74> */
/* @0x2974f4 ldr r12, [r2, #0x4]! */
/* @0x2974f8 cmp r1, r12 */
/* @0x2974fc bne 0x2974e8 <_ZN8yyServer12DeleteSocketEP8yySocket+0x14> */
/* @0x297500 add r3, r3, #34 */
/* @0x297504 ldr r5, [r0, #0x28] */
/* @0x297508 mov r12, #0 */
/* @0x29750c mov r2, #1 */
/* @0x297510 str r12, [r4, r3, lsl #2] */
/* @0x297514 mov r12, r2 */
/* @0x297518 ldr r3, [r1] */
/* @0x29751c sub r1, r5, #1 */
/* @0x297520 and r5, r3, #31 */
/* @0x297524 asr r3, r3, #5 */
/* @0x297528 add r4, r4, r3, lsl #2 */
/* @0x29752c ldr r3, [r4, #0x8] */
/* @0x297530 bic r2, r3, r2, lsl r5 */
/* @0x297534 str r2, [r4, #0x8] */
/* @0x297538 str r1, [r0, #0x28] */
/* @0x29753c mov r0, r12 */
/* @0x297540 pop {r4, r5} */
/* @0x297544 bx lr */
/* @0x297548 mov r12, #0 */
/* @0x29754c mov r0, r12 */
/* @0x297550 pop {r4, r5} */
/* @0x297554 bx lr */

/* ── FUNC 0x297558 · yyServer::SetSocketID(int) · size=20 · insn=5 */
/* @0x297558 ldr r3, [r0] */
/* @0x29755c str r1, [r0, #0x18] */
/* @0x297560 cmp r3, #0 */
/* @0x297564 strne r1, [r3, #0x68] */
/* @0x297568 bx lr */

/* ── FUNC 0x29756c · yyServer::SendCommand(yySocket*, eNetworkCommand) · size=56 · insn=14 */
/* @0x29756c str lr, [sp, #-0x4]! */
/* @0x297570 sub sp, sp, #52 */
/* @0x297574 mov r12, #44 */
/* @0x297578 mov r0, r1 */
/* @0x29757c str r2, [sp, #0x10] */
/* @0x297580 add r1, sp, #4 */
/* @0x297584 mov r2, r12 */
/* @0x297588 str r12, [sp, #0x8] */
/* @0x29758c movw r3, #0xc0de */
/* @0x297590 movt r3, #0xbe11 */
/* @0x297594 str r3, [sp, #0x4] */
/* @0x297598 bl 0x295464 <_ZN8yySocket5WriteEPvj> */
/* @0x29759c add sp, sp, #52 */
/* @0x2975a0 ldr pc, [sp], #4 */

/* ── FUNC 0x2975a4 · yyServer::ProcessDataPacket(yySocket*, unsigned char*, int) · size=428 · insn=107 */
/* @0x2975a4 push {r4, r5, r6, r7, lr} */
/* @0x2975a8 mov r4, r1 */
/* @0x2975ac ldr r5, [r1, #0x28] */
/* @0x2975b0 sub sp, sp, #36 */
/* @0x2975b4 mov r7, r0 */
/* @0x2975b8 mov r6, r2 */
/* @0x2975bc cmp r5, #1 */
/* @0x2975c0 beq 0x297608 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x64> */
/* @0x2975c4 cmp r5, #2 */
/* @0x2975c8 beq 0x2975dc <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x38> */
/* @0x2975cc ldr r2, [r0, #0x20] */
/* @0x2975d0 cmp r2, #1 */
/* @0x2975d4 cmpne r2, #4 */
/* @0x2975d8 bne 0x297600 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x5c> */
/* @0x2975dc ldr r1, [r6] */
/* @0x2975e0 movw r2, #0xc0de */
/* @0x2975e4 movt r2, #0xbe11 */
/* @0x2975e8 cmp r1, r2 */
/* @0x2975ec beq 0x297678 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0xd4> */
/* @0x2975f0 mov r0, r4 */
/* @0x2975f4 mov r1, r3 */
/* @0x2975f8 mov r2, r6 */
/* @0x2975fc bl 0x296b08 <_ZN8yySocket15SendDataToEventEiPh> */
/* @0x297600 add sp, sp, #36 */
/* @0x297604 pop {r4, r5, r6, r7, pc} */
/* @0x297608 ldr r2, [r2] */
/* @0x29760c movw r3, #0xbabe */
/* @0x297610 movt r3, #0xcafe */
/* @0x297614 cmp r2, r3 */
/* @0x297618 bne 0x29763c <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x98> */
/* @0x29761c ldr r2, [r6, #0x4] */
/* @0x297620 movw r3, #0xb00b */
/* @0x297624 movt r3, #0xdead */
/* @0x297628 cmp r2, r3 */
/* @0x29762c bne 0x29763c <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x98> */
/* @0x297630 ldr r3, [r6, #0x8] */
/* @0x297634 cmp r3, #16 */
/* @0x297638 beq 0x2976d0 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x12c> */
/* @0x29763c ldr r3, [pc, #0x104] */
/* @0x297640 ldr r1, [pc, #0x104] */
/* @0x297644 ldr r3, [pc, r3] */
/* @0x297648 add r1, pc, r1 */
/* @0x29764c ldr r0, [r3] */
/* @0x297650 ldr r3, [r0] */
/* @0x297654 ldr r3, [r3, #0xc] */
/* @0x297658 blx r3 */
/* @0x29765c mov r1, r4 */
/* @0x297660 mov r0, r7 */
/* @0x297664 bl 0x2974d4 <_ZN8yyServer12DeleteSocketEP8yySocket> */
/* @0x297668 mov r0, r4 */
/* @0x29766c bl 0x29955c <_Z10FreeSocketP8yySocket> */
/* @0x297670 add sp, sp, #36 */
/* @0x297674 pop {r4, r5, r6, r7, pc} */
/* @0x297678 ldr r2, [r6, #0x4] */
/* @0x29767c cmp r2, #44 */
/* @0x297680 bne 0x2975f0 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x4c> */
/* @0x297684 ldrb r2, [r4, #0x2c] */
/* @0x297688 cmp r2, #0 */
/* @0x29768c beq 0x2975f0 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x4c> */
/* @0x297690 ldr r5, [r4, #0x4c] */
/* @0x297694 mov r2, #0 */
/* @0x297698 str r4, [sp, #0x14] */
/* @0x29769c mov r1, r2 */
/* @0x2976a0 strb r2, [sp, #0x18] */
/* @0x2976a4 ldr r12, [r5] */
/* @0x2976a8 mov r0, r5 */
/* @0x2976ac ldr r12, [r12, #0x10] */
/* @0x2976b0 str r3, [sp, #0xc] */
/* @0x2976b4 blx r12 */
/* @0x2976b8 mov r1, r5 */
/* @0x2976bc mov r2, r6 */
/* @0x2976c0 ldr r3, [sp, #0xc] */
/* @0x2976c4 add r0, sp, #20 */
/* @0x2976c8 bl 0x29e50c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti> */
/* @0x2976cc b 0x297600 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x5c> */
/* @0x2976d0 mov r3, #12 */
/* @0x2976d4 mov r0, r1 */
/* @0x2976d8 mov r2, r3 */
/* @0x2976dc add r1, sp, #20 */
/* @0x2976e0 str r3, [sp, #0x1c] */
/* @0x2976e4 movw lr, #0xbead */
/* @0x2976e8 movw r12, #0xbeeb */
/* @0x2976ec movt lr, #0xdeaf */
/* @0x2976f0 movt r12, #0xf00d */
/* @0x2976f4 str lr, [sp, #0x14] */
/* @0x2976f8 str r12, [sp, #0x18] */
/* @0x2976fc bl 0x295464 <_ZN8yySocket5WriteEPvj> */
/* @0x297700 ldrb r3, [r4, #0x2c] */
/* @0x297704 cmp r3, #0 */
/* @0x297708 bne 0x297738 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x194> */
/* @0x29770c ldr r0, [r7, #0x18] */
/* @0x297710 add r12, r4, #108 */
/* @0x297714 ldr r1, [r4, #0x68] */
/* @0x297718 ldr r2, [r4, #0xac] */
/* @0x29771c ldr r3, [r4, #0xb0] */
/* @0x297720 str r5, [sp, #0x4] */
/* @0x297724 str r12, [sp] */
/* @0x297728 bl 0x2987cc <_Z33ThrowConnectingSocketNetworkEventiiiiPcb> */
/* @0x29772c mov r3, #2 */
/* @0x297730 str r3, [r4, #0x28] */
/* @0x297734 b 0x297600 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x5c> */
/* @0x297738 bl 0x29cd80 <_Z23DebuggerDestroyIPSocketv> */
/* @0x29773c mov r0, r5 */
/* @0x297740 bl 0x29cad0 <_Z20DebuggerSetConnectedb> */
/* @0x297744 b 0x29772c <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi+0x188> */
/* @0x297748 ldrsbeq r6, [r5], -r0 */
/* @0x29774c andeq r1, r12, r0, ror pc */

/* ── FUNC 0x297750 · yyServer::ProcessTCP() · size=1692 · insn=423 */
/* @0x297750 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x297754 sub sp, sp, #148 */
/* @0x297758 ldr r12, [pc, #0x650] */
/* @0x29775c mov r2, #128 */
/* @0x297760 ldr r3, [pc, #0x64c] */
/* @0x297764 mov r5, r0 */
/* @0x297768 add r12, pc, r12 */
/* @0x29776c str r12, [sp, #0x14] */
/* @0x297770 ldr r12, [r0, #0x4] */
/* @0x297774 ldr r10, [r0, #0x8] */
/* @0x297778 ldr r9, [r0] */
/* @0x29777c str r12, [sp, #0x10] */
/* @0x297780 add r4, r10, #8 */
/* @0x297784 ldr r12, [sp, #0x14] */
/* @0x297788 mov r0, r4 */
/* @0x29778c ldr r3, [r12, r3] */
/* @0x297790 ldr r12, [sp, #0x10] */
/* @0x297794 str r3, [sp, #0x2c] */
/* @0x297798 add r1, r12, #8 */
/* @0x29779c ldr r3, [r3] */
/* @0x2977a0 str r3, [sp, #0x8c] */
/* @0x2977a4 bl 0xb65bc <memcpy@plt> */
/* @0x2977a8 ldr r12, [sp, #0x10] */
/* @0x2977ac mov r2, #4096 */
/* @0x2977b0 add r0, r10, #136 */
/* @0x2977b4 add r1, r12, #136 */
/* @0x2977b8 bl 0xb65bc <memcpy@plt> */
/* @0x2977bc mov r12, #0 */
/* @0x2977c0 add lr, sp, #68 */
/* @0x2977c4 mov r2, r12 */
/* @0x2977c8 mov r1, r4 */
/* @0x2977cc mov r3, r12 */
/* @0x2977d0 mov r0, #1024 */
/* @0x2977d4 str lr, [sp] */
/* @0x2977d8 str r12, [sp, #0x44] */
/* @0x2977dc str r12, [sp, #0x48] */
/* @0x2977e0 bl 0xb6d84 <select@plt> */
/* @0x2977e4 cmp r0, #0 */
/* @0x2977e8 beq 0x2979a4 <_ZN8yyServer10ProcessTCPEv+0x254> */
/* @0x2977ec cmn r0, #1 */
/* @0x2977f0 beq 0x297d0c <_ZN8yyServer10ProcessTCPEv+0x5bc> */
/* @0x2977f4 ldr r12, [sp, #0x10] */
/* @0x2977f8 add r12, r12, #132 */
/* @0x2977fc str r12, [sp, #0x18] */
/* @0x297800 ldr r12, [sp, #0x10] */
/* @0x297804 ldr r11, [sp, #0x18] */
/* @0x297808 add r6, r12, #4224 */
/* @0x29780c ldr r12, [pc, #0x5a4] */
/* @0x297810 add r6, r6, #4 */
/* @0x297814 add r12, pc, r12 */
/* @0x297818 str r12, [sp, #0x24] */
/* @0x29781c ldr r12, [pc, #0x598] */
/* @0x297820 add r12, pc, r12 */
/* @0x297824 str r12, [sp, #0x30] */
/* @0x297828 ldr r12, [pc, #0x590] */
/* @0x29782c add r12, pc, r12 */
/* @0x297830 str r12, [sp, #0x34] */
/* @0x297834 ldr r12, [pc, #0x588] */
/* @0x297838 add r12, pc, r12 */
/* @0x29783c str r12, [sp, #0x3c] */
/* @0x297840 ldr r12, [pc, #0x580] */
/* @0x297844 add r12, pc, r12 */
/* @0x297848 str r12, [sp, #0x28] */
/* @0x29784c ldr r12, [pc, #0x578] */
/* @0x297850 add r12, pc, r12 */
/* @0x297854 str r12, [sp, #0x38] */
/* @0x297858 b 0x297864 <_ZN8yyServer10ProcessTCPEv+0x114> */
/* @0x29785c cmp r11, r6 */
/* @0x297860 beq 0x2979a4 <_ZN8yyServer10ProcessTCPEv+0x254> */
/* @0x297864 ldr r4, [r11, #0x4]! */
/* @0x297868 cmp r4, #0 */
/* @0x29786c beq 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c> */
/* @0x297870 ldr r3, [r4] */
/* @0x297874 mov r8, #1 */
/* @0x297878 and r2, r3, #31 */
/* @0x29787c asr r3, r3, #5 */
/* @0x297880 add r3, r3, #2 */
/* @0x297884 ldr r3, [r10, r3, lsl #2] */
/* @0x297888 ands r3, r3, r8, lsl r2 */
/* @0x29788c beq 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c> */
/* @0x297890 cmp r9, r4 */
/* @0x297894 beq 0x2979c0 <_ZN8yyServer10ProcessTCPEv+0x270> */
/* @0x297898 mov r0, r4 */
/* @0x29789c mov r1, r5 */
/* @0x2978a0 bl 0x296e1c <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer> */
/* @0x2978a4 subs r7, r0, #0 */
/* @0x2978a8 bne 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c> */
/* @0x2978ac ldr r12, [r4, #0x28] */
/* @0x2978b0 add r8, r4, #108 */
/* @0x2978b4 ldr r0, [pc, #0x514] */
/* @0x2978b8 mov r3, r8 */
/* @0x2978bc ldr r1, [sp, #0x24] */
/* @0x2978c0 str r12, [sp, #0x1c] */
/* @0x2978c4 ldr r12, [sp, #0x14] */
/* @0x2978c8 ldr r2, [r4, #0x68] */
/* @0x2978cc ldr r0, [r12, r0] */
/* @0x2978d0 add r12, sp, #76 */
/* @0x2978d4 str r12, [sp, #0xc] */
/* @0x2978d8 ldr r0, [r0] */
/* @0x2978dc ldr r12, [r0] */
/* @0x2978e0 ldr r12, [r12, #0xc] */
/* @0x2978e4 blx r12 */
/* @0x2978e8 ldr r3, [r4, #0xb0] */
/* @0x2978ec mov r1, r8 */
/* @0x2978f0 add r0, sp, #76 */
/* @0x2978f4 mov r2, #64 */
/* @0x2978f8 ldr r8, [r4, #0xac] */
/* @0x2978fc str r3, [sp, #0x20] */
/* @0x297900 bl 0xb6568 <strncpy@plt> */
/* @0x297904 ldrb r3, [r4, #0x2c] */
/* @0x297908 cmp r3, #0 */
/* @0x29790c bne 0x297b58 <_ZN8yyServer10ProcessTCPEv+0x408> */
/* @0x297910 ldr r1, [r5, #0x28] */
/* @0x297914 mov r3, #0 */
/* @0x297918 ldr r2, [sp, #0x18] */
/* @0x29791c sub r1, r1, #1 */
/* @0x297920 str r1, [r5, #0x28] */
/* @0x297924 b 0x297934 <_ZN8yyServer10ProcessTCPEv+0x1e4> */
/* @0x297928 add r3, r3, #1 */
/* @0x29792c cmp r3, #1024 */
/* @0x297930 beq 0x297970 <_ZN8yyServer10ProcessTCPEv+0x220> */
/* @0x297934 ldr r1, [r2, #0x4]! */
/* @0x297938 cmp r4, r1 */
/* @0x29793c bne 0x297928 <_ZN8yyServer10ProcessTCPEv+0x1d8> */
/* @0x297940 ldr r12, [sp, #0x10] */
/* @0x297944 add r3, r3, #34 */
/* @0x297948 mov r2, #0 */
/* @0x29794c mov r0, #1 */
/* @0x297950 str r2, [r12, r3, lsl #2] */
/* @0x297954 ldr r3, [r4] */
/* @0x297958 and r2, r3, #31 */
/* @0x29795c asr r3, r3, #5 */
/* @0x297960 add r3, r12, r3, lsl #2 */
/* @0x297964 ldr r1, [r3, #0x8] */
/* @0x297968 bic r2, r1, r0, lsl r2 */
/* @0x29796c str r2, [r3, #0x8] */
/* @0x297970 mov r0, r4 */
/* @0x297974 bl 0x295474 <_ZN8yySocket5CloseEv> */
/* @0x297978 ldrb r7, [r4, #0x2c] */
/* @0x29797c mov r3, #3 */
/* @0x297980 str r3, [r4, #0x28] */
/* @0x297984 cmp r7, #0 */
/* @0x297988 beq 0x297b20 <_ZN8yyServer10ProcessTCPEv+0x3d0> */
/* @0x29798c mov r0, r4 */
/* @0x297990 bl 0x294cbc <_ZN8yySocketD2Ev> */
/* @0x297994 mov r0, r4 */
/* @0x297998 bl 0x27d1d0 <_ZdlPv> */
/* @0x29799c cmp r11, r6 */
/* @0x2979a0 bne 0x297864 <_ZN8yyServer10ProcessTCPEv+0x114> */
/* @0x2979a4 ldr r12, [sp, #0x2c] */
/* @0x2979a8 ldr r2, [sp, #0x8c] */
/* @0x2979ac ldr r3, [r12] */
/* @0x2979b0 cmp r2, r3 */
/* @0x2979b4 bne 0x297dac <_ZN8yyServer10ProcessTCPEv+0x65c> */
/* @0x2979b8 add sp, sp, #148 */
/* @0x2979bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2979c0 mov r0, r9 */
/* @0x2979c4 bl 0x29528c <_ZN8yySocket6AcceptEv> */
/* @0x2979c8 mov r7, r0 */
/* @0x2979cc mov r0, #200 */
/* @0x2979d0 bl 0x27c524 <_Znwj> */
/* @0x2979d4 ldr r2, [r5, #0x20] */
/* @0x2979d8 mov r3, r8 */
/* @0x2979dc mov r1, r7 */
/* @0x2979e0 mov r4, r0 */
/* @0x2979e4 bl 0x2970c0 <_ZN8yySocketC2Ei11eSocketTypeb> */
/* @0x2979e8 mov r0, r4 */
/* @0x2979ec bl 0x294ec8 <_ZN8yySocket4InitEv> */
/* @0x2979f0 ldr r3, [r5, #0x28] */
/* @0x2979f4 ldr r2, [r5, #0x24] */
/* @0x2979f8 cmp r3, r2 */
/* @0x2979fc bge 0x297b70 <_ZN8yyServer10ProcessTCPEv+0x420> */
/* @0x297a00 ldrb r12, [r9, #0x2c] */
/* @0x297a04 cmp r12, #0 */
/* @0x297a08 beq 0x297cc4 <_ZN8yyServer10ProcessTCPEv+0x574> */
/* @0x297a0c mvn r7, #0 */
/* @0x297a10 strb r8, [r4, #0x2c] */
/* @0x297a14 add r3, r3, #1 */
/* @0x297a18 str r3, [r5, #0x28] */
/* @0x297a1c ldr r12, [sp, #0x10] */
/* @0x297a20 ldr r3, [r12, #0x4] */
/* @0x297a24 cmp r3, #1024 */
/* @0x297a28 bge 0x297a80 <_ZN8yyServer10ProcessTCPEv+0x330> */
/* @0x297a2c ldr r2, [sp, #0x18] */
/* @0x297a30 mov r3, #0 */
/* @0x297a34 b 0x297a44 <_ZN8yyServer10ProcessTCPEv+0x2f4> */
/* @0x297a38 add r3, r3, #1 */
/* @0x297a3c cmp r3, #1024 */
/* @0x297a40 beq 0x297a5c <_ZN8yyServer10ProcessTCPEv+0x30c> */
/* @0x297a44 ldr r1, [r2, #0x4]! */
/* @0x297a48 cmp r1, #0 */
/* @0x297a4c bne 0x297a38 <_ZN8yyServer10ProcessTCPEv+0x2e8> */
/* @0x297a50 ldr r12, [sp, #0x10] */
/* @0x297a54 add r3, r3, #34 */
/* @0x297a58 str r4, [r12, r3, lsl #2] */
/* @0x297a5c ldr r3, [r4] */
/* @0x297a60 mov r0, #1 */
/* @0x297a64 ldr r12, [sp, #0x10] */
/* @0x297a68 and r2, r3, #31 */
/* @0x297a6c asr r3, r3, #5 */
/* @0x297a70 add r3, r12, r3, lsl #2 */
/* @0x297a74 ldr r1, [r3, #0x8] */
/* @0x297a78 orr r2, r1, r0, lsl r2 */
/* @0x297a7c str r2, [r3, #0x8] */
/* @0x297a80 mov r0, r4 */
/* @0x297a84 add r12, r4, #108 */
/* @0x297a88 str r12, [sp, #0xc] */
/* @0x297a8c bl 0x296f64 <_ZN8yySocket9ResolveIPEv> */
/* @0x297a90 ldr r12, [sp, #0x14] */
/* @0x297a94 mov r2, r7 */
/* @0x297a98 ldr r0, [pc, #0x330] */
/* @0x297a9c ldr r3, [sp, #0xc] */
/* @0x297aa0 ldr r1, [sp, #0x28] */
/* @0x297aa4 ldr r0, [r12, r0] */
/* @0x297aa8 ldr r8, [r0] */
/* @0x297aac ldr r12, [r8] */
/* @0x297ab0 mov r0, r8 */
/* @0x297ab4 ldr r12, [r12, #0xc] */
/* @0x297ab8 blx r12 */
/* @0x297abc ldrb r3, [r5, #0x1d] */
/* @0x297ac0 ldr r2, [r9, #0xac] */
/* @0x297ac4 cmp r3, #0 */
/* @0x297ac8 str r2, [r4, #0xac] */
/* @0x297acc beq 0x297bf0 <_ZN8yyServer10ProcessTCPEv+0x4a0> */
/* @0x297ad0 ldrb r3, [r4, #0x2c] */
/* @0x297ad4 cmp r3, #0 */
/* @0x297ad8 bne 0x297c8c <_ZN8yyServer10ProcessTCPEv+0x53c> */
/* @0x297adc ldrb r3, [r5, #0x1d] */
/* @0x297ae0 cmn r7, #1 */
/* @0x297ae4 strne r7, [r4, #0x68] */
/* @0x297ae8 cmp r3, #0 */
/* @0x297aec beq 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c> */
/* @0x297af0 ldr lr, [sp, #0xc] */
/* @0x297af4 mov r3, #2 */
/* @0x297af8 ldr r1, [r4, #0x68] */
/* @0x297afc mov r12, #1 */
/* @0x297b00 str r3, [r4, #0x28] */
/* @0x297b04 ldr r2, [r4, #0xac] */
/* @0x297b08 ldr r0, [r5, #0x18] */
/* @0x297b0c ldr r3, [r4, #0xb0] */
/* @0x297b10 str lr, [sp] */
/* @0x297b14 str r12, [sp, #0x4] */
/* @0x297b18 bl 0x2987cc <_Z33ThrowConnectingSocketNetworkEventiiiiPcb> */
/* @0x297b1c b 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c> */
/* @0x297b20 mov r0, r4 */
/* @0x297b24 bl 0x29955c <_Z10FreeSocketP8yySocket> */
/* @0x297b28 ldr r12, [sp, #0x1c] */
/* @0x297b2c cmp r12, #1 */
/* @0x297b30 mov r1, r0 */
/* @0x297b34 bls 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c> */
/* @0x297b38 ldr r0, [r5, #0x18] */
/* @0x297b3c add lr, sp, #76 */
/* @0x297b40 mov r2, r8 */
/* @0x297b44 str lr, [sp] */
/* @0x297b48 str r7, [sp, #0x4] */
/* @0x297b4c ldr r3, [sp, #0x20] */
/* @0x297b50 bl 0x2987cc <_Z33ThrowConnectingSocketNetworkEventiiiiPcb> */
/* @0x297b54 b 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c> */
/* @0x297b58 bl 0x29cacc <_Z26Debug_DeleteALLBreakPointsv> */
/* @0x297b5c mov r0, r7 */
/* @0x297b60 bl 0x29c648 <_Z21Debug_StartStopTargetb> */
/* @0x297b64 mov r0, r7 */
/* @0x297b68 bl 0x29cad0 <_Z20DebuggerSetConnectedb> */
/* @0x297b6c b 0x297910 <_ZN8yyServer10ProcessTCPEv+0x1c0> */
/* @0x297b70 mov r0, r4 */
/* @0x297b74 bl 0x296f64 <_ZN8yySocket9ResolveIPEv> */
/* @0x297b78 ldr r12, [sp, #0x14] */
/* @0x297b7c ldr r3, [pc, #0x24c] */
/* @0x297b80 add r2, r4, #108 */
/* @0x297b84 ldr r1, [sp, #0x30] */
/* @0x297b88 ldr r3, [r12, r3] */
/* @0x297b8c ldr r7, [r3] */
/* @0x297b90 ldr r3, [r7] */
/* @0x297b94 mov r0, r7 */
/* @0x297b98 ldr r3, [r3, #0xc] */
/* @0x297b9c blx r3 */
/* @0x297ba0 mov r0, r4 */
/* @0x297ba4 ldr r1, [sp, #0x34] */
/* @0x297ba8 mov r2, #6 */
/* @0x297bac bl 0x295464 <_ZN8yySocket5WriteEPvj> */
/* @0x297bb0 cmp r0, #6 */
/* @0x297bb4 beq 0x297bcc <_ZN8yyServer10ProcessTCPEv+0x47c> */
/* @0x297bb8 ldr r3, [r7] */
/* @0x297bbc mov r0, r7 */
/* @0x297bc0 ldr r1, [sp, #0x3c] */
/* @0x297bc4 ldr r3, [r3, #0xc] */
/* @0x297bc8 blx r3 */
/* @0x297bcc mov r0, r4 */
/* @0x297bd0 bl 0x295474 <_ZN8yySocket5CloseEv> */
/* @0x297bd4 cmp r4, #0 */
/* @0x297bd8 beq 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c> */
/* @0x297bdc mov r0, r4 */
/* @0x297be0 bl 0x294cbc <_ZN8yySocketD2Ev> */
/* @0x297be4 mov r0, r4 */
/* @0x297be8 bl 0x27d1d0 <_ZdlPv> */
/* @0x297bec b 0x29799c <_ZN8yyServer10ProcessTCPEv+0x24c> */
/* @0x297bf0 mov r2, #1 */
/* @0x297bf4 mov r0, r4 */
/* @0x297bf8 str r2, [r4, #0x28] */
/* @0x297bfc mov r2, #18 */
/* @0x297c00 ldr r1, [sp, #0x38] */
/* @0x297c04 str r3, [sp, #0x8] */
/* @0x297c08 bl 0x295464 <_ZN8yySocket5WriteEPvj> */
/* @0x297c0c ldr r3, [sp, #0x8] */
/* @0x297c10 cmp r0, #18 */
/* @0x297c14 beq 0x297ad0 <_ZN8yyServer10ProcessTCPEv+0x380> */
/* @0x297c18 ldr r2, [sp, #0x18] */
/* @0x297c1c b 0x297c2c <_ZN8yyServer10ProcessTCPEv+0x4dc> */
/* @0x297c20 add r3, r3, #1 */
/* @0x297c24 cmp r3, #1024 */
/* @0x297c28 beq 0x297c68 <_ZN8yyServer10ProcessTCPEv+0x518> */
/* @0x297c2c ldr r1, [r2, #0x4]! */
/* @0x297c30 cmp r4, r1 */
/* @0x297c34 bne 0x297c20 <_ZN8yyServer10ProcessTCPEv+0x4d0> */
/* @0x297c38 ldr r12, [sp, #0x10] */
/* @0x297c3c add r3, r3, #34 */
/* @0x297c40 mov r2, #0 */
/* @0x297c44 mov r0, #1 */
/* @0x297c48 str r2, [r12, r3, lsl #2] */
/* @0x297c4c ldr r3, [r4] */
/* @0x297c50 and r2, r3, #31 */
/* @0x297c54 asr r3, r3, #5 */
/* @0x297c58 add r3, r12, r3, lsl #2 */
/* @0x297c5c ldr r1, [r3, #0x8] */
/* @0x297c60 bic r2, r1, r0, lsl r2 */
/* @0x297c64 str r2, [r3, #0x8] */
/* @0x297c68 ldr r3, [r8] */
/* @0x297c6c mov r0, r8 */
/* @0x297c70 ldr r1, [pc, #0x15c] */
/* @0x297c74 ldr r3, [r3, #0xc] */
/* @0x297c78 add r1, pc, r1 */
/* @0x297c7c blx r3 */
/* @0x297c80 ldrb r3, [r4, #0x2c] */
/* @0x297c84 cmp r3, #0 */
/* @0x297c88 beq 0x297adc <_ZN8yyServer10ProcessTCPEv+0x38c> */
/* @0x297c8c mov r0, #64 */
/* @0x297c90 bl 0x27c524 <_Znwj> */
/* @0x297c94 mov r2, #1 */
/* @0x297c98 mov r3, r2 */
/* @0x297c9c ldr r1, [r5, #0x14] */
/* @0x297ca0 mov r8, r0 */
/* @0x297ca4 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati> */
/* @0x297ca8 ldr r3, [pc, #0x128] */
/* @0x297cac ldr r12, [sp, #0x14] */
/* @0x297cb0 ldr r3, [r12, r3] */
/* @0x297cb4 add r3, r3, #8 */
/* @0x297cb8 str r3, [r8] */
/* @0x297cbc str r8, [r4, #0x4c] */
/* @0x297cc0 b 0x297adc <_ZN8yyServer10ProcessTCPEv+0x38c> */
/* @0x297cc4 str r12, [sp, #0x8] */
/* @0x297cc8 bl 0x298e28 <_Z11AllocSocketv> */
/* @0x297ccc ldr r12, [sp, #0x8] */
/* @0x297cd0 subs r7, r0, #0 */
/* @0x297cd4 blt 0x297d14 <_ZN8yyServer10ProcessTCPEv+0x5c4> */
/* @0x297cd8 ldr r1, [pc, #0xfc] */
/* @0x297cdc add r3, r7, r7, lsl #1 */
/* @0x297ce0 ldr r0, [sp, #0x14] */
/* @0x297ce4 cmp r4, #0 */
/* @0x297ce8 ldr r2, [r5, #0x28] */
/* @0x297cec ldr r1, [r0, r1] */
/* @0x297cf0 add r2, r2, #1 */
/* @0x297cf4 add r3, r1, r3, lsl #2 */
/* @0x297cf8 strb r8, [r3, #0x1] */
/* @0x297cfc stmib r3, {r4, r12} */
/* @0x297d00 str r2, [r5, #0x28] */
/* @0x297d04 bne 0x297a1c <_ZN8yyServer10ProcessTCPEv+0x2cc> */
/* @0x297d08 b 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c> */
/* @0x297d0c bl 0x294d24 <_ZN8yySocket9DumpErrorEv> */
/* @0x297d10 b 0x2977f4 <_ZN8yyServer10ProcessTCPEv+0xa4> */
/* @0x297d14 mov r0, r4 */
/* @0x297d18 bl 0x296f64 <_ZN8yySocket9ResolveIPEv> */
/* @0x297d1c ldr r12, [sp, #0x14] */
/* @0x297d20 ldr r3, [pc, #0xa8] */
/* @0x297d24 add r2, r4, #108 */
/* @0x297d28 ldr r1, [pc, #0xb0] */
/* @0x297d2c ldr r3, [r12, r3] */
/* @0x297d30 add r1, pc, r1 */
/* @0x297d34 ldr r7, [r3] */
/* @0x297d38 ldr r3, [r7] */
/* @0x297d3c mov r0, r7 */
/* @0x297d40 ldr r3, [r3, #0xc] */
/* @0x297d44 blx r3 */
/* @0x297d48 ldr r1, [pc, #0x94] */
/* @0x297d4c mov r0, r4 */
/* @0x297d50 mov r2, #6 */
/* @0x297d54 add r1, pc, r1 */
/* @0x297d58 bl 0x295464 <_ZN8yySocket5WriteEPvj> */
/* @0x297d5c cmp r0, #6 */
/* @0x297d60 beq 0x297d7c <_ZN8yyServer10ProcessTCPEv+0x62c> */
/* @0x297d64 ldr r3, [r7] */
/* @0x297d68 mov r0, r7 */
/* @0x297d6c ldr r1, [pc, #0x74] */
/* @0x297d70 ldr r3, [r3, #0xc] */
/* @0x297d74 add r1, pc, r1 */
/* @0x297d78 blx r3 */
/* @0x297d7c mov r0, r4 */
/* @0x297d80 bl 0x295474 <_ZN8yySocket5CloseEv> */
/* @0x297d84 cmp r4, #0 */
/* @0x297d88 beq 0x297d9c <_ZN8yyServer10ProcessTCPEv+0x64c> */
/* @0x297d8c mov r0, r4 */
/* @0x297d90 bl 0x294cbc <_ZN8yySocketD2Ev> */
/* @0x297d94 mov r0, r4 */
/* @0x297d98 bl 0x27d1d0 <_ZdlPv> */
/* @0x297d9c ldr r3, [r5, #0x28] */
/* @0x297da0 add r3, r3, #1 */
/* @0x297da4 str r3, [r5, #0x28] */
/* @0x297da8 b 0x29785c <_ZN8yyServer10ProcessTCPEv+0x10c> */
/* @0x297dac bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x297db0 andseq r10, r5, r8, ror #9 */
/* @0x297db4 .word 0xffffbd00 */
/* @0x297db8 andeq r1, r12, r0, lsl #28 */
/* @0x297dbc strheq r1, [r12], -r0 */
/* @0x297dc0 strheq r1, [r12], -r8 */
/* @0x297dc4 strheq r1, [r12], -r4 */
/* @0x297dc8 strheq r1, [r12], -r4 */
/* @0x297dcc andeq r1, r12, r12, asr r12 */
/* @0x297dd0 .word 0xffffbac4 */
/* @0x297dd4 andeq r1, r12, r4, ror r9 */
/* @0x297dd8 .word 0xffffbd60 */
/* @0x297ddc .word 0xfffffd54 */
/* @0x297de0 andeq r1, r12, r0, lsr #17 */
/* @0x297de4 muleq r12, r0, r8 */
/* @0x297de8 andeq r1, r12, r8, ror r8 */

/* ── FUNC 0x297dec · yyServer::ProcessUDP() · size=428 · insn=107 */
/* @0x297dec ldr r1, [r0, #0x8] */
/* @0x297df0 mov r2, #128 */
/* @0x297df4 ldr r3, [pc, #0x194] */
/* @0x297df8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x297dfc add r6, r1, #8 */
/* @0x297e00 sub sp, sp, #44 */
/* @0x297e04 ldr r12, [r0] */
/* @0x297e08 ldr r11, [r0, #0x4] */
/* @0x297e0c ldr r3, [pc, r3] */
/* @0x297e10 str r1, [sp, #0x14] */
/* @0x297e14 mov r5, r0 */
/* @0x297e18 add r1, r11, #8 */
/* @0x297e1c mov r0, r6 */
/* @0x297e20 str r12, [r3] */
/* @0x297e24 bl 0xb65bc <memcpy@plt> */
/* @0x297e28 ldr r2, [sp, #0x14] */
/* @0x297e2c mov r4, #0 */
/* @0x297e30 add r1, r11, #136 */
/* @0x297e34 add r0, r2, #136 */
/* @0x297e38 mov r2, #4096 */
/* @0x297e3c bl 0xb65bc <memcpy@plt> */
/* @0x297e40 add r12, sp, #32 */
/* @0x297e44 mov r1, r6 */
/* @0x297e48 mov r2, r4 */
/* @0x297e4c mov r3, r4 */
/* @0x297e50 mov r0, #1024 */
/* @0x297e54 str r12, [sp] */
/* @0x297e58 str r4, [sp, #0x20] */
/* @0x297e5c str r4, [sp, #0x24] */
/* @0x297e60 bl 0xb6d84 <select@plt> */
/* @0x297e64 cmp r0, r4 */
/* @0x297e68 ble 0x297f88 <_ZN8yyServer10ProcessUDPEv+0x19c> */
/* @0x297e6c ldr r3, [pc, #0x120] */
/* @0x297e70 add r10, sp, #24 */
/* @0x297e74 add r9, sp, #28 */
/* @0x297e78 add r11, r11, #132 */
/* @0x297e7c add r3, pc, r3 */
/* @0x297e80 mov r1, #1024 */
/* @0x297e84 str r3, [sp, #0x10] */
/* @0x297e88 str r11, [sp, #0xc] */
/* @0x297e8c str r1, [sp, #0x8] */
/* @0x297e90 ldr r2, [sp, #0xc] */
/* @0x297e94 ldr r4, [r2, #0x4]! */
/* @0x297e98 cmp r4, #0 */
/* @0x297e9c str r2, [sp, #0xc] */
/* @0x297ea0 beq 0x297f78 <_ZN8yyServer10ProcessUDPEv+0x18c> */
/* @0x297ea4 ldr r3, [r4] */
/* @0x297ea8 ldr r1, [sp, #0x14] */
/* @0x297eac and r2, r3, #31 */
/* @0x297eb0 asr r3, r3, #5 */
/* @0x297eb4 add r3, r3, #2 */
/* @0x297eb8 ldr r3, [r1, r3, lsl #2] */
/* @0x297ebc mov r1, #1 */
/* @0x297ec0 ands r3, r3, r1, lsl r2 */
/* @0x297ec4 beq 0x297f78 <_ZN8yyServer10ProcessUDPEv+0x18c> */
/* @0x297ec8 ldr r7, [r5, #0xc] */
/* @0x297ecc add r8, r4, #108 */
/* @0x297ed0 ldr r6, [r5, #0x10] */
/* @0x297ed4 b 0x297f30 <_ZN8yyServer10ProcessUDPEv+0x144> */
/* @0x297ed8 mov r3, #0 */
/* @0x297edc cmp r11, r3 */
/* @0x297ee0 mov r2, r6 */
/* @0x297ee4 mov r1, r7 */
/* @0x297ee8 mov r0, r4 */
/* @0x297eec ble 0x297f78 <_ZN8yyServer10ProcessUDPEv+0x18c> */
/* @0x297ef0 str r10, [sp] */
/* @0x297ef4 str r9, [sp, #0x4] */
/* @0x297ef8 bl 0x2952ec <_ZN8yySocket8ReadFromEPvjjPPcPi> */
/* @0x297efc subs r11, r0, #0 */
/* @0x297f00 mov r0, r8 */
/* @0x297f04 ble 0x297f78 <_ZN8yyServer10ProcessUDPEv+0x18c> */
/* @0x297f08 ldr r1, [sp, #0x18] */
/* @0x297f0c bl 0xb65a4 <strcpy@plt> */
/* @0x297f10 ldr r12, [sp, #0x1c] */
/* @0x297f14 ldr r2, [r5, #0xc] */
/* @0x297f18 mov r3, r11 */
/* @0x297f1c mov r0, r5 */
/* @0x297f20 mov r1, r4 */
/* @0x297f24 str r12, [r4, #0xac] */
/* @0x297f28 str r12, [r4, #0xb0] */
/* @0x297f2c bl 0x2975a4 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi> */
/* @0x297f30 mov r0, r4 */
/* @0x297f34 bl 0x295438 <_ZN8yySocket4PeekEv> */
/* @0x297f38 ldr r3, [r5, #0x10] */
/* @0x297f3c cmp r0, r3 */
/* @0x297f40 mov r11, r0 */
/* @0x297f44 ble 0x297ed8 <_ZN8yyServer10ProcessUDPEv+0xec> */
/* @0x297f48 add r6, r3, #32768 */
/* @0x297f4c mov r2, #0 */
/* @0x297f50 mov r3, #74 */
/* @0x297f54 str r2, [sp] */
/* @0x297f58 mov r1, r6 */
/* @0x297f5c ldr r0, [r5, #0xc] */
/* @0x297f60 ldr r2, [sp, #0x10] */
/* @0x297f64 str r6, [r5, #0x10] */
/* @0x297f68 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x297f6c mov r7, r0 */
/* @0x297f70 str r0, [r5, #0xc] */
/* @0x297f74 b 0x297ed8 <_ZN8yyServer10ProcessUDPEv+0xec> */
/* @0x297f78 ldr r3, [sp, #0x8] */
/* @0x297f7c subs r3, r3, #1 */
/* @0x297f80 str r3, [sp, #0x8] */
/* @0x297f84 bne 0x297e90 <_ZN8yyServer10ProcessUDPEv+0xa4> */
/* @0x297f88 add sp, sp, #44 */
/* @0x297f8c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x297f90 mulseq r5, r4, r11 */
/* @0x297f94 strheq r9, [r9], -r4 */

/* ── FUNC 0x297f98 · yyServer::Process() · size=36 · insn=9 */
/* @0x297f98 ldr r2, [r0] */
/* @0x297f9c cmp r2, #0 */
/* @0x297fa0 bxeq lr */
/* @0x297fa4 ldr r3, [r0, #0x20] */
/* @0x297fa8 cmp r3, #0 */
/* @0x297fac cmpne r3, #3 */
/* @0x297fb0 beq 0x297fb8 <_ZN8yyServer7ProcessEv+0x20> */
/* @0x297fb4 b 0x297dec <_ZN8yyServer10ProcessUDPEv> */
/* @0x297fb8 b 0x297750 <_ZN8yyServer10ProcessTCPEv> */

/* ── FUNC 0x297fbc · F_NETWORK_Send_Packet(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x297fbc push {r4, r5, r6, r7, r8, lr} */
/* @0x297fc0 mov r1, #0 */
/* @0x297fc4 ldr r5, [sp, #0x18] */
/* @0x297fc8 mov r3, r1 */
/* @0x297fcc str r1, [r0, #0xc] */
/* @0x297fd0 movt r3, #0xbff0 */
/* @0x297fd4 mov r4, r0 */
/* @0x297fd8 stm r0, {r1, r3} */
/* @0x297fdc mov r0, r5 */
/* @0x297fe0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x297fe4 mov r1, #1 */
/* @0x297fe8 mov r6, r0 */
/* @0x297fec mov r0, r5 */
/* @0x297ff0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x297ff4 mov r1, #2 */
/* @0x297ff8 mov r7, r0 */
/* @0x297ffc mov r0, r5 */
/* @0x298000 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298004 cmp r6, #63 */
/* @0x298008 mov r5, r0 */
/* @0x29800c pophi {r4, r5, r6, r7, r8, pc} */
/* @0x298010 add r6, r6, r6, lsl #1 */
/* @0x298014 ldr r3, [pc, #0x5c] */
/* @0x298018 lsl r6, r6, #2 */
/* @0x29801c ldr r3, [pc, r3] */
/* @0x298020 add r8, r3, r6 */
/* @0x298024 ldrb r3, [r3, r6] */
/* @0x298028 cmp r3, #0 */
/* @0x29802c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x298030 mov r0, r7 */
/* @0x298034 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x298038 subs r3, r0, #0 */
/* @0x29803c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x298040 ldr r0, [r8, #0x4] */
/* @0x298044 mov r2, r5 */
/* @0x298048 ldr r1, [r3, #0xc] */
/* @0x29804c cmp r0, #0 */
/* @0x298050 ldreq r3, [r8, #0x8] */
/* @0x298054 ldreq r0, [r3] */
/* @0x298058 bl 0x296944 <_ZN8yySocket10SendPacketEPhi> */
/* @0x29805c vmov s15, r0 */
/* @0x298060 vcvt.f64.s32 d7, s15 */
/* @0x298064 vmov r0, r1, d7 */
/* @0x298068 vmov r2, s14 */
/* @0x29806c mov r3, r1 */
/* @0x298070 stm r4, {r2, r3} */
/* @0x298074 pop {r4, r5, r6, r7, r8, pc} */
/* @0x298078 andseq r9, r5, r8, lsl #19 */

/* ── FUNC 0x29807c · F_NETWORK_Resolve(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x29807c push {r4, r5, r6, lr} */
/* @0x298080 mov r5, r0 */
/* @0x298084 ldr r4, [pc, #0x3c] */
/* @0x298088 ldr r6, [sp, #0x10] */
/* @0x29808c ldr r4, [pc, r4] */
/* @0x298090 ldrb r3, [r4] */
/* @0x298094 cmp r3, #0 */
/* @0x298098 bne 0x2980a8 <_Z17F_NETWORK_ResolveR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x29809c bl 0x294d18 <_ZN8yySocket7StartupEv> */
/* @0x2980a0 mov r3, #1 */
/* @0x2980a4 strb r3, [r4] */
/* @0x2980a8 mov r1, #0 */
/* @0x2980ac mov r0, r6 */
/* @0x2980b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x2980b4 bl 0x2957c0 <_ZN8yySocket15ResolveToStringEPc> */
/* @0x2980b8 mov r1, r0 */
/* @0x2980bc mov r0, r5 */
/* @0x2980c0 pop {r4, r5, r6, lr} */
/* @0x2980c4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x2980c8 andseq r9, r5, r0, lsl r9 */

/* ── FUNC 0x2980cc · F_NETWORK_Set_Timeout(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x2980cc push {r3, r4, r5, r6, r7, lr} */
/* @0x2980d0 mov r3, #0 */
/* @0x2980d4 ldr r5, [sp, #0x18] */
/* @0x2980d8 mov r1, r3 */
/* @0x2980dc str r3, [r0, #0xc] */
/* @0x2980e0 mov r4, r0 */
/* @0x2980e4 str r3, [r0] */
/* @0x2980e8 str r3, [r0, #0x4] */
/* @0x2980ec mov r0, r5 */
/* @0x2980f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x2980f4 mov r1, #1 */
/* @0x2980f8 mov r6, r0 */
/* @0x2980fc mov r0, r5 */
/* @0x298100 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298104 mov r1, #2 */
/* @0x298108 mov r7, r0 */
/* @0x29810c mov r0, r5 */
/* @0x298110 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298114 cmp r6, #63 */
/* @0x298118 mov r2, r0 */
/* @0x29811c pophi {r3, r4, r5, r6, r7, pc} */
/* @0x298120 add r6, r6, r6, lsl #1 */
/* @0x298124 ldr r3, [pc, #0x48] */
/* @0x298128 lsl r6, r6, #2 */
/* @0x29812c ldr r3, [pc, r3] */
/* @0x298130 add r1, r3, r6 */
/* @0x298134 ldrb r3, [r3, r6] */
/* @0x298138 cmp r3, #0 */
/* @0x29813c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x298140 ldr r0, [r1, #0x4] */
/* @0x298144 cmp r0, #0 */
/* @0x298148 ldreq r3, [r1, #0x8] */
/* @0x29814c mov r1, r7 */
/* @0x298150 ldreq r0, [r3] */
/* @0x298154 bl 0x294ed4 <_ZN8yySocket10SetTimeoutEii> */
/* @0x298158 vmov s15, r0 */
/* @0x29815c vcvt.f64.s32 d7, s15 */
/* @0x298160 vmov r0, r1, d7 */
/* @0x298164 vmov r2, s14 */
/* @0x298168 mov r3, r1 */
/* @0x29816c stm r4, {r2, r3} */
/* @0x298170 pop {r3, r4, r5, r6, r7, pc} */
/* @0x298174 andseq r9, r5, r8, ror r8 */

/* ── FUNC 0x298178 · F_NETWORK_Connect(RValue&, CInstance*, CInstance*, int, RValue*) · size=244 · insn=61 */
/* @0x298178 push {r3, r4, r5, r6, r7, lr} */
/* @0x29817c mov r2, #0 */
/* @0x298180 ldr r5, [pc, #0xd4] */
/* @0x298184 mov r6, r3 */
/* @0x298188 str r2, [r0] */
/* @0x29818c mov r4, r0 */
/* @0x298190 ldr r5, [pc, r5] */
/* @0x298194 str r2, [r0, #0xc] */
/* @0x298198 str r2, [r0, #0x4] */
/* @0x29819c ldrb r3, [r5] */
/* @0x2981a0 ldr r7, [sp, #0x18] */
/* @0x2981a4 cmp r3, r2 */
/* @0x2981a8 beq 0x298238 <_Z17F_NETWORK_ConnectR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x2981ac cmp r6, #3 */
/* @0x2981b0 beq 0x2981c8 <_Z17F_NETWORK_ConnectR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x2981b4 ldr r0, [pc, #0xa4] */
/* @0x2981b8 mov r1, #0 */
/* @0x2981bc pop {r3, r4, r5, r6, r7, lr} */
/* @0x2981c0 add r0, pc, r0 */
/* @0x2981c4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x2981c8 mov r0, r7 */
/* @0x2981cc mov r1, #0 */
/* @0x2981d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x2981d4 cmp r0, #0 */
/* @0x2981d8 blt 0x298248 <_Z17F_NETWORK_ConnectR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x2981dc ldr r3, [pc, #0x80] */
/* @0x2981e0 add r2, r0, r0, lsl #1 */
/* @0x2981e4 mov r1, #1 */
/* @0x2981e8 mov r0, r7 */
/* @0x2981ec ldr r3, [pc, r3] */
/* @0x2981f0 add r3, r3, r2, lsl #2 */
/* @0x2981f4 ldr r6, [r3, #0x4] */
/* @0x2981f8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x2981fc mov r1, #2 */
/* @0x298200 mov r5, r0 */
/* @0x298204 mov r0, r7 */
/* @0x298208 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29820c mov r1, r5 */
/* @0x298210 mov r2, r0 */
/* @0x298214 mov r0, r6 */
/* @0x298218 bl 0x2966ac <_ZN8yySocket10ConnectGMSEPci> */
/* @0x29821c vmov s15, r0 */
/* @0x298220 vcvt.f64.s32 d7, s15 */
/* @0x298224 vmov r0, r1, d7 */
/* @0x298228 vmov r2, s14 */
/* @0x29822c mov r3, r1 */
/* @0x298230 stm r4, {r2, r3} */
/* @0x298234 pop {r3, r4, r5, r6, r7, pc} */
/* @0x298238 bl 0x294d18 <_ZN8yySocket7StartupEv> */
/* @0x29823c mov r3, #1 */
/* @0x298240 strb r3, [r5] */
/* @0x298244 b 0x2981ac <_Z17F_NETWORK_ConnectR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x298248 ldr r0, [pc, #0x18] */
/* @0x29824c mov r1, #0 */
/* @0x298250 pop {r3, r4, r5, r6, r7, lr} */
/* @0x298254 add r0, pc, r0 */
/* @0x298258 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x29825c andseq r9, r5, r12, lsl #16 */
/* @0x298260 andeq lr, r10, r8, lsl #8 */
/* @0x298264 ldrheq r9, [r5], -r8 */
/* @0x298268 andeq r1, r12, r0, ror #7 */

/* ── FUNC 0x29826c · F_NETWORK_Connect_ex(RValue&, CInstance*, CInstance*, int, RValue*) · size=236 · insn=59 */
/* @0x29826c push {r3, r4, r5, r6, r7, lr} */
/* @0x298270 mov r3, #0 */
/* @0x298274 ldr r5, [pc, #0xcc] */
/* @0x298278 mov r4, r0 */
/* @0x29827c str r3, [r0] */
/* @0x298280 ldr r5, [pc, r5] */
/* @0x298284 str r3, [r0, #0xc] */
/* @0x298288 str r3, [r0, #0x4] */
/* @0x29828c ldrb r3, [r5] */
/* @0x298290 ldr r6, [sp, #0x18] */
/* @0x298294 cmp r3, #0 */
/* @0x298298 beq 0x298324 <_Z20F_NETWORK_Connect_exR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x29829c ldr r3, [pc, #0xa8] */
/* @0x2982a0 ldr r3, [pc, r3] */
/* @0x2982a4 ldr r3, [r3] */
/* @0x2982a8 sub r3, r3, #2 */
/* @0x2982ac cmp r3, #2 */
/* @0x2982b0 pophi {r3, r4, r5, r6, r7, pc} */
/* @0x2982b4 mov r0, r6 */
/* @0x2982b8 mov r1, #0 */
/* @0x2982bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x2982c0 cmp r0, #0 */
/* @0x2982c4 blt 0x298334 <_Z20F_NETWORK_Connect_exR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x2982c8 ldr r3, [pc, #0x80] */
/* @0x2982cc add r2, r0, r0, lsl #1 */
/* @0x2982d0 mov r1, #1 */
/* @0x2982d4 mov r0, r6 */
/* @0x2982d8 ldr r3, [pc, r3] */
/* @0x2982dc add r3, r3, r2, lsl #2 */
/* @0x2982e0 ldr r7, [r3, #0x4] */
/* @0x2982e4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x2982e8 mov r1, #2 */
/* @0x2982ec mov r5, r0 */
/* @0x2982f0 mov r0, r6 */
/* @0x2982f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x2982f8 mov r1, r5 */
/* @0x2982fc mov r2, r0 */
/* @0x298300 mov r0, r7 */
/* @0x298304 bl 0x295858 <_ZN8yySocket7ConnectEPci> */
/* @0x298308 vmov s15, r0 */
/* @0x29830c vcvt.f64.s32 d7, s15 */
/* @0x298310 vmov r0, r1, d7 */
/* @0x298314 vmov r2, s14 */
/* @0x298318 mov r3, r1 */
/* @0x29831c stm r4, {r2, r3} */
/* @0x298320 pop {r3, r4, r5, r6, r7, pc} */
/* @0x298324 bl 0x294d18 <_ZN8yySocket7StartupEv> */
/* @0x298328 mov r3, #1 */
/* @0x29832c strb r3, [r5] */
/* @0x298330 b 0x29829c <_Z20F_NETWORK_Connect_exR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x298334 ldr r0, [pc, #0x18] */
/* @0x298338 mov r1, #0 */
/* @0x29833c pop {r3, r4, r5, r6, r7, lr} */
/* @0x298340 add r0, pc, r0 */
/* @0x298344 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x298348 andseq r9, r5, r12, lsl r7 */
/* @0x29834c andseq r8, r5, r0, lsl #1 */
/* @0x298350 andseq r9, r5, r12, asr #13 */
/* @0x298354 strdeq r1, r2, [r12], -r4 */

/* ── FUNC 0x298358 · F_NETWORK_Set_Config(RValue&, CInstance*, CInstance*, int, RValue*) · size=408 · insn=102 */
/* @0x298358 push {r4, r5, r6, lr} */
/* @0x29835c mov r3, #0 */
/* @0x298360 ldr r5, [sp, #0x10] */
/* @0x298364 mov r4, r0 */
/* @0x298368 ldr r6, [pc, #0x16c] */
/* @0x29836c mov r1, r3 */
/* @0x298370 str r3, [r0, #0xc] */
/* @0x298374 str r3, [r0] */
/* @0x298378 add r6, pc, r6 */
/* @0x29837c str r3, [r0, #0x4] */
/* @0x298380 mov r0, r5 */
/* @0x298384 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298388 cmp r0, #4 */
/* @0x29838c addls pc, pc, r0, lsl #2 */
/* @0x298390 b 0x2984b8 <_Z20F_NETWORK_Set_ConfigR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x298394 b 0x298400 <_Z20F_NETWORK_Set_ConfigR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x298398 b 0x29841c <_Z20F_NETWORK_Set_ConfigR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x29839c b 0x298438 <_Z20F_NETWORK_Set_ConfigR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x2983a0 b 0x298478 <_Z20F_NETWORK_Set_ConfigR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x2983a4 b 0x2983a8 <_Z20F_NETWORK_Set_ConfigR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x2983a8 mov r0, r5 */
/* @0x2983ac mov r1, #1 */
/* @0x2983b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x2983b4 cmp r0, #63 */
/* @0x2983b8 pophi {r4, r5, r6, pc} */
/* @0x2983bc ldr r3, [pc, #0x11c] */
/* @0x2983c0 add r0, r0, r0, lsl #1 */
/* @0x2983c4 lsl r0, r0, #2 */
/* @0x2983c8 ldr r3, [r6, r3] */
/* @0x2983cc ldrb r2, [r3, r0] */
/* @0x2983d0 cmp r2, #0 */
/* @0x2983d4 popeq {r4, r5, r6, pc} */
/* @0x2983d8 add r3, r3, r0 */
/* @0x2983dc ldr r0, [r3, #0x4] */
/* @0x2983e0 bl 0x294f30 <_ZN8yySocket13AvoidTimeWaitEv> */
/* @0x2983e4 vmov s15, r0 */
/* @0x2983e8 vcvt.f64.s32 d7, s15 */
/* @0x2983ec vmov r0, r1, d7 */
/* @0x2983f0 vmov r2, s14 */
/* @0x2983f4 mov r3, r1 */
/* @0x2983f8 stm r4, {r2, r3} */
/* @0x2983fc pop {r4, r5, r6, pc} */
/* @0x298400 mov r0, r5 */
/* @0x298404 mov r1, #1 */
/* @0x298408 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29840c ldr r3, [pc, #0xd0] */
/* @0x298410 ldr r3, [r6, r3] */
/* @0x298414 str r0, [r3] */
/* @0x298418 pop {r4, r5, r6, pc} */
/* @0x29841c mov r0, r5 */
/* @0x298420 mov r1, #1 */
/* @0x298424 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x298428 ldr r3, [pc, #0xb8] */
/* @0x29842c ldr r3, [r6, r3] */
/* @0x298430 strb r0, [r3] */
/* @0x298434 pop {r4, r5, r6, pc} */
/* @0x298438 mov r0, r5 */
/* @0x29843c mov r1, #1 */
/* @0x298440 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298444 cmp r0, #63 */
/* @0x298448 pophi {r4, r5, r6, pc} */
/* @0x29844c ldr r3, [pc, #0x8c] */
/* @0x298450 add r0, r0, r0, lsl #1 */
/* @0x298454 lsl r0, r0, #2 */
/* @0x298458 ldr r3, [r6, r3] */
/* @0x29845c ldrb r2, [r3, r0] */
/* @0x298460 cmp r2, #0 */
/* @0x298464 addne r3, r3, r0 */
/* @0x298468 movne r2, #1 */
/* @0x29846c ldrne r3, [r3, #0x4] */
/* @0x298470 strbne r2, [r3, #0x30] */
/* @0x298474 pop {r4, r5, r6, pc} */
/* @0x298478 mov r0, r5 */
/* @0x29847c mov r1, #1 */
/* @0x298480 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298484 cmp r0, #63 */
/* @0x298488 pophi {r4, r5, r6, pc} */
/* @0x29848c ldr r3, [pc, #0x4c] */
/* @0x298490 add r0, r0, r0, lsl #1 */
/* @0x298494 lsl r0, r0, #2 */
/* @0x298498 ldr r3, [r6, r3] */
/* @0x29849c ldrb r2, [r3, r0] */
/* @0x2984a0 cmp r2, #0 */
/* @0x2984a4 addne r3, r3, r0 */
/* @0x2984a8 movne r2, #0 */
/* @0x2984ac ldrne r3, [r3, #0x4] */
/* @0x2984b0 strbne r2, [r3, #0x30] */
/* @0x2984b4 pop {r4, r5, r6, pc} */
/* @0x2984b8 ldr r0, [pc, #0x2c] */
/* @0x2984bc mov r1, #0 */
/* @0x2984c0 add r0, pc, r0 */
/* @0x2984c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x2984c8 mov r3, #0 */
/* @0x2984cc mov r2, r3 */
/* @0x2984d0 movt r3, #0xbff0 */
/* @0x2984d4 stm r4, {r2, r3} */
/* @0x2984d8 pop {r4, r5, r6, pc} */
/* @0x2984dc ldrsbeq r9, [r5], -r8 */
/* @0x2984e0 .word 0xfffffd54 */
/* @0x2984e4 .word 0xfffffd3c */
/* @0x2984e8 .word 0xfffffd44 */
/* @0x2984ec andeq r1, r12, r12, lsl #3 */

/* ── FUNC 0x2984f0 · F_NETWORK_Send_Raw(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x2984f0 ldr r3, [pc, #0xd0] */
/* @0x2984f4 mov r1, #0 */
/* @0x2984f8 push {r4, r5, r6, r7, r8, lr} */
/* @0x2984fc ldr r3, [pc, r3] */
/* @0x298500 str r1, [r0] */
/* @0x298504 mov r2, r1 */
/* @0x298508 ldr r3, [r3] */
/* @0x29850c movt r2, #0xbff0 */
/* @0x298510 mov r4, r0 */
/* @0x298514 str r1, [r0, #0xc] */
/* @0x298518 sub r3, r3, #2 */
/* @0x29851c str r2, [r0, #0x4] */
/* @0x298520 cmp r3, #2 */
/* @0x298524 ldr r5, [sp, #0x18] */
/* @0x298528 pophi {r4, r5, r6, r7, r8, pc} */
/* @0x29852c mov r0, r5 */
/* @0x298530 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298534 mov r1, #1 */
/* @0x298538 mov r6, r0 */
/* @0x29853c mov r0, r5 */
/* @0x298540 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298544 mov r1, #2 */
/* @0x298548 mov r7, r0 */
/* @0x29854c mov r0, r5 */
/* @0x298550 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298554 cmp r6, #63 */
/* @0x298558 mov r5, r0 */
/* @0x29855c pophi {r4, r5, r6, r7, r8, pc} */
/* @0x298560 add r6, r6, r6, lsl #1 */
/* @0x298564 ldr r3, [pc, #0x60] */
/* @0x298568 lsl r6, r6, #2 */
/* @0x29856c ldr r3, [pc, r3] */
/* @0x298570 add r8, r3, r6 */
/* @0x298574 ldrb r3, [r3, r6] */
/* @0x298578 cmp r3, #0 */
/* @0x29857c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x298580 mov r0, r7 */
/* @0x298584 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x298588 subs r3, r0, #0 */
/* @0x29858c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x298590 ldr r0, [r8, #0x4] */
/* @0x298594 mov r2, r5 */
/* @0x298598 ldr r1, [r3, #0xc] */
/* @0x29859c cmp r0, #0 */
/* @0x2985a0 ldreq r3, [r8, #0x8] */
/* @0x2985a4 ldreq r0, [r3] */
/* @0x2985a8 bl 0x295464 <_ZN8yySocket5WriteEPvj> */
/* @0x2985ac vmov s15, r0 */
/* @0x2985b0 vcvt.f64.s32 d7, s15 */
/* @0x2985b4 vmov r0, r1, d7 */
/* @0x2985b8 vmov r2, s14 */
/* @0x2985bc mov r3, r1 */
/* @0x2985c0 stm r4, {r2, r3} */
/* @0x2985c4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2985c8 andseq r7, r5, r4, lsr #28 */
/* @0x2985cc andseq r9, r5, r8, lsr r4 */

/* ── FUNC 0x2985d0 · F_NETWORK_Send_Broadcast(RValue&, CInstance*, CInstance*, int, RValue*) · size=332 · insn=83 */
/* @0x2985d0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2985d4 mov r2, #0 */
/* @0x2985d8 ldr r4, [pc, #0x12c] */
/* @0x2985dc mov r3, r2 */
/* @0x2985e0 str r2, [r0] */
/* @0x2985e4 movt r3, #0xbff0 */
/* @0x2985e8 ldr r4, [pc, r4] */
/* @0x2985ec str r2, [r0, #0xc] */
/* @0x2985f0 mov r5, r0 */
/* @0x2985f4 str r3, [r0, #0x4] */
/* @0x2985f8 ldrb r2, [r4] */
/* @0x2985fc ldr r6, [sp, #0x20] */
/* @0x298600 cmp r2, #0 */
/* @0x298604 beq 0x2986ec <_Z24F_NETWORK_Send_BroadcastR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x298608 ldr r3, [pc, #0x100] */
/* @0x29860c ldr r3, [pc, r3] */
/* @0x298610 ldr r3, [r3] */
/* @0x298614 sub r3, r3, #2 */
/* @0x298618 cmp r3, #2 */
/* @0x29861c pophi {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x298620 mov r1, #2 */
/* @0x298624 mov r0, r6 */
/* @0x298628 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29862c bl 0xc6720 <_Z10GetIBufferi> */
/* @0x298630 subs r1, r0, #0 */
/* @0x298634 beq 0x2986fc <_Z24F_NETWORK_Send_BroadcastR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x298638 mov r0, r6 */
/* @0x29863c mov r1, #0 */
/* @0x298640 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298644 mov r1, #1 */
/* @0x298648 mov r4, r0 */
/* @0x29864c mov r0, r6 */
/* @0x298650 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298654 mov r1, #2 */
/* @0x298658 mov r8, r0 */
/* @0x29865c mov r0, r6 */
/* @0x298660 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298664 mov r1, #3 */
/* @0x298668 mov r7, r0 */
/* @0x29866c mov r0, r6 */
/* @0x298670 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298674 cmp r4, #63 */
/* @0x298678 mov r6, r0 */
/* @0x29867c pophi {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x298680 add r4, r4, r4, lsl #1 */
/* @0x298684 ldr r12, [pc, #0x88] */
/* @0x298688 lsl r4, r4, #2 */
/* @0x29868c ldr r12, [pc, r12] */
/* @0x298690 add r9, r12, r4 */
/* @0x298694 ldrb r3, [r12, r4] */
/* @0x298698 cmp r3, #0 */
/* @0x29869c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2986a0 mov r0, r7 */
/* @0x2986a4 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x2986a8 subs r3, r0, #0 */
/* @0x2986ac popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2986b0 ldr r0, [r9, #0x4] */
/* @0x2986b4 mov r1, r8 */
/* @0x2986b8 ldr r2, [r3, #0xc] */
/* @0x2986bc cmp r0, #0 */
/* @0x2986c0 ldreq r3, [r9, #0x8] */
/* @0x2986c4 ldreq r0, [r3] */
/* @0x2986c8 mov r3, r6 */
/* @0x2986cc bl 0x295bc8 <_ZN8yySocket9BroadcastEiPhi> */
/* @0x2986d0 cmp r0, #0 */
/* @0x2986d4 vmovlt s15, r0 */
/* @0x2986d8 vmovge s15, r6 */
/* @0x2986dc vcvt.f64.s32 d7, s15 */
/* @0x2986e0 vmov r2, r3, d7 */
/* @0x2986e4 stm r5, {r2, r3} */
/* @0x2986e8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2986ec bl 0x294d18 <_ZN8yySocket7StartupEv> */
/* @0x2986f0 mov r3, #1 */
/* @0x2986f4 strb r3, [r4] */
/* @0x2986f8 b 0x298608 <_Z24F_NETWORK_Send_BroadcastR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x2986fc ldr r0, [pc, #0x14] */
/* @0x298700 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x298704 add r0, pc, r0 */
/* @0x298708 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x29870c ldrheq r9, [r5], -r4 */
/* @0x298710 andseq r7, r5, r4, lsl sp */
/* @0x298714 andseq r9, r5, r8, lsl r3 */
/* @0x298718 andeq r0, r12, r0, ror pc */

/* ── FUNC 0x29871c · InitNetworkEvent() · size=176 · insn=44 */
/* @0x29871c push {r4, r5, lr} */
/* @0x298720 mov r3, #0 */
/* @0x298724 ldr r5, [pc, #0x98] */
/* @0x298728 sub sp, sp, #28 */
/* @0x29872c ldr r12, [pc, #0x94] */
/* @0x298730 ldr r5, [pc, r5] */
/* @0x298734 ldr r12, [pc, r12] */
/* @0x298738 ldr r4, [r5] */
/* @0x29873c str r3, [r12, #0xc] */
/* @0x298740 cmp r4, r3 */
/* @0x298744 str r3, [r12] */
/* @0x298748 str r3, [r12, #0x4] */
/* @0x29874c str r3, [r12, #0x1c] */
/* @0x298750 str r3, [r12, #0x10] */
/* @0x298754 str r3, [r12, #0x14] */
/* @0x298758 blt 0x298790 <_Z16InitNetworkEventv+0x74> */
/* @0x29875c vmov s15, r4 */
/* @0x298760 mov r1, r3 */
/* @0x298764 mov r2, r3 */
/* @0x298768 add r0, sp, #8 */
/* @0x29876c vcvt.f64.s32 d7, s15 */
/* @0x298770 mov r3, #1 */
/* @0x298774 vmov r4, r5, d7 */
/* @0x298778 mov lr, r5 */
/* @0x29877c stm r12, {r4, lr} */
/* @0x298780 str r12, [sp] */
/* @0x298784 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_> */
/* @0x298788 add sp, sp, #28 */
/* @0x29878c pop {r4, r5, pc} */
/* @0x298790 mov r1, r3 */
/* @0x298794 mov r2, r3 */
/* @0x298798 add r0, sp, #8 */
/* @0x29879c movt r3, #0x4020 */
/* @0x2987a0 str r3, [r12, #0x4] */
/* @0x2987a4 mov r3, #1 */
/* @0x2987a8 str r12, [sp] */
/* @0x2987ac bl 0x1000f4 <_Z13F_DsMapCreateR6RValueP9CInstanceS2_iPS_> */
/* @0x2987b0 vldr d7, [sp, #8] */
/* @0x2987b4 vcvt.s32.f64 s14, d7 */
/* @0x2987b8 vstr s14, [r5] */
/* @0x2987bc add sp, sp, #28 */
/* @0x2987c0 pop {r4, r5, pc} */
/* @0x2987c4 andseq r8, r5, r0, ror r12 */
/* @0x2987c8 andseq r9, r5, r4, ror r2 */

/* ── FUNC 0x2987cc · ThrowConnectingSocketNetworkEvent(int, int, int, int, char*, bool) · size=480 · insn=120 */
/* @0x2987cc push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2987d0 mov r10, r0 */
/* @0x2987d4 mov r9, r1 */
/* @0x2987d8 mov r8, r2 */
/* @0x2987dc mov r7, r3 */
/* @0x2987e0 ldrb r4, [sp, #0x2c] */
/* @0x2987e4 ldr r6, [sp, #0x28] */
/* @0x2987e8 bl 0x29871c <_Z16InitNetworkEventv> */
/* @0x2987ec vmov.f64 d6, #2.000000e+00 */
/* @0x2987f0 ldr r5, [pc, #0x184] */
/* @0x2987f4 ldr r12, [pc, #0x184] */
/* @0x2987f8 cmp r4, #0 */
/* @0x2987fc add r5, pc, r5 */
/* @0x298800 ldr r1, [pc, #0x17c] */
/* @0x298804 ldr r4, [r5, r12] */
/* @0x298808 add r1, pc, r1 */
/* @0x29880c ldr r0, [r4] */
/* @0x298810 vmov.f64 d7, #1.000000e+00 */
/* @0x298814 vmovne r2, r3, d7 */
/* @0x298818 vmoveq r2, r3, d6 */
/* @0x29881c bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298820 ldr r1, [pc, #0x160] */
/* @0x298824 vmov s15, r10 */
/* @0x298828 ldr r0, [r4] */
/* @0x29882c add r1, pc, r1 */
/* @0x298830 movw r10, #0x1d10 */
/* @0x298834 vcvt.f64.s32 d7, s15 */
/* @0x298838 vmov r2, r3, d7 */
/* @0x29883c bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298840 ldr r1, [pc, #0x144] */
/* @0x298844 vmov s15, r9 */
/* @0x298848 ldr r0, [r4] */
/* @0x29884c add r1, pc, r1 */
/* @0x298850 vcvt.f64.s32 d7, s15 */
/* @0x298854 vmov r2, r3, d7 */
/* @0x298858 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x29885c ldr r1, [pc, #0x12c] */
/* @0x298860 vmov s15, r8 */
/* @0x298864 ldr r0, [r4] */
/* @0x298868 add r1, pc, r1 */
/* @0x29886c vcvt.f64.s32 d7, s15 */
/* @0x298870 vmov r2, r3, d7 */
/* @0x298874 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298878 ldr r1, [pc, #0x114] */
/* @0x29887c vmov s15, r7 */
/* @0x298880 ldr r0, [r4] */
/* @0x298884 add r1, pc, r1 */
/* @0x298888 vcvt.f64.s32 d7, s15 */
/* @0x29888c vmov r2, r3, d7 */
/* @0x298890 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298894 ldr r1, [pc, #0xfc] */
/* @0x298898 mov r2, r6 */
/* @0x29889c ldr r0, [r4] */
/* @0x2988a0 add r1, pc, r1 */
/* @0x2988a4 bl 0x104f64 <_Z19F_DsMapAdd_InternaliPcS_> */
/* @0x2988a8 ldr r1, [pc, #0xec] */
/* @0x2988ac ldr r3, [pc, #0xec] */
/* @0x2988b0 ldr r2, [r4] */
/* @0x2988b4 ldr r8, [r5, r1] */
/* @0x2988b8 str r2, [r8] */
/* @0x2988bc ldr r9, [r5, r3] */
/* @0x2988c0 ldr r3, [r9, r10] */
/* @0x2988c4 cmp r3, #0 */
/* @0x2988c8 ble 0x298970 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x1a4> */
/* @0x2988cc ldr r2, [pc, #0xd0] */
/* @0x2988d0 mov r4, #0 */
/* @0x2988d4 ldr r3, [pc, #0xcc] */
/* @0x2988d8 movw r7, #0x3a24 */
/* @0x2988dc ldr r6, [r5, r2] */
/* @0x2988e0 ldr r5, [r5, r3] */
/* @0x2988e4 ldr r3, [r6] */
/* @0x2988e8 ldr r1, [r5, r7] */
/* @0x2988ec ldr r2, [r3, #0x4] */
/* @0x2988f0 ldr r1, [r1, r4, lsl #2] */
/* @0x2988f4 ldr r3, [r3] */
/* @0x2988f8 and r2, r1, r2 */
/* @0x2988fc ldr r3, [r3, r2, lsl #3] */
/* @0x298900 cmp r3, #0 */
/* @0x298904 bne 0x298918 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x14c> */
/* @0x298908 b 0x298928 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x15c> */
/* @0x29890c ldr r3, [r3, #0x4] */
/* @0x298910 cmp r3, #0 */
/* @0x298914 beq 0x298928 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x15c> */
/* @0x298918 ldr r2, [r3, #0x8] */
/* @0x29891c cmp r1, r2 */
/* @0x298920 bne 0x29890c <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x140> */
/* @0x298924 ldr r3, [r3, #0xc] */
/* @0x298928 ldr r11, [r3, #0xc4] */
/* @0x29892c cmp r11, #0 */
/* @0x298930 bne 0x298954 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x188> */
/* @0x298934 b 0x298960 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x194> */
/* @0x298938 ldr r11, [r11] */
/* @0x29893c mov r1, r0 */
/* @0x298940 mov r2, #7 */
/* @0x298944 mov r3, #68 */
/* @0x298948 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x29894c cmp r11, #0 */
/* @0x298950 beq 0x298960 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x194> */
/* @0x298954 ldr r0, [r11, #0x8] */
/* @0x298958 cmp r0, #0 */
/* @0x29895c bne 0x298938 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x16c> */
/* @0x298960 ldr r3, [r9, r10] */
/* @0x298964 add r4, r4, #1 */
/* @0x298968 cmp r3, r4 */
/* @0x29896c bgt 0x2988e4 <_Z33ThrowConnectingSocketNetworkEventiiiiPcb+0x118> */
/* @0x298970 mvn r3, #0 */
/* @0x298974 str r3, [r8] */
/* @0x298978 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29897c andseq r9, r5, r4, asr r4 */
/* @0x298980 .word 0xfffff750 */
/* @0x298984 andeq sp, r10, r0, lsr #18 */
/* @0x298988 andeq r8, r9, r4, lsl r2 */
/* @0x29898c andeq r0, r12, r12, lsr lr */
/* @0x298990 andeq r0, r12, r8, lsr #28 */
/* @0x298994 andeq r0, r12, r4, lsl lr */
/* @0x298998 andeq r0, r12, r4, lsl #28 */
/* @0x29899c .word 0xffffdec8 */
/* @0x2989a0 .word 0xffffdeb8 */
/* @0x2989a4 .word 0xffffbfec */
/* @0x2989a8 .word 0xffffdebc */

/* ── FUNC 0x2989ac · ThrowNonBlockingConnectSocketNetworkEvent(int, bool) · size=496 · insn=124 */
/* @0x2989ac push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2989b0 vpush {d8} */
/* @0x2989b4 mov r6, r0 */
/* @0x2989b8 ldr r5, [pc, #0x1a8] */
/* @0x2989bc mov r7, r1 */
/* @0x2989c0 bl 0x29871c <_Z16InitNetworkEventv> */
/* @0x2989c4 ldr r0, [pc, #0x1a0] */
/* @0x2989c8 add r5, pc, r5 */
/* @0x2989cc ldr r1, [pc, #0x19c] */
/* @0x2989d0 mov r2, #0 */
/* @0x2989d4 mov r3, #0 */
/* @0x2989d8 ldr r4, [r5, r0] */
/* @0x2989dc add r1, pc, r1 */
/* @0x2989e0 movt r3, #0x4010 */
/* @0x2989e4 movw r10, #0x1d10 */
/* @0x2989e8 ldr r0, [r4] */
/* @0x2989ec bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x2989f0 vmov s14, r6 */
/* @0x2989f4 ldr r1, [pc, #0x178] */
/* @0x2989f8 add r6, r6, r6, lsl #1 */
/* @0x2989fc vcvt.f64.s32 d8, s14 */
/* @0x298a00 ldr r0, [r4] */
/* @0x298a04 add r1, pc, r1 */
/* @0x298a08 vmov r2, r3, d8 */
/* @0x298a0c bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298a10 ldr r1, [pc, #0x160] */
/* @0x298a14 vmov r2, r3, d8 */
/* @0x298a18 add r1, pc, r1 */
/* @0x298a1c ldr r0, [r4] */
/* @0x298a20 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298a24 vmov s15, r7 */
/* @0x298a28 ldr r1, [pc, #0x14c] */
/* @0x298a2c vcvt.f64.u32 d7, s15 */
/* @0x298a30 ldr r0, [r4] */
/* @0x298a34 add r1, pc, r1 */
/* @0x298a38 vmov r2, r3, d7 */
/* @0x298a3c bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298a40 ldr r3, [pc, #0x138] */
/* @0x298a44 ldr r1, [pc, #0x138] */
/* @0x298a48 ldr r0, [r4] */
/* @0x298a4c ldr r3, [r5, r3] */
/* @0x298a50 add r1, pc, r1 */
/* @0x298a54 add r3, r3, r6, lsl #2 */
/* @0x298a58 ldr r2, [r3, #0x8] */
/* @0x298a5c ldr r6, [r3, #0x4] */
/* @0x298a60 cmp r2, #0 */
/* @0x298a64 ldrne r6, [r2] */
/* @0x298a68 add r2, r6, #108 */
/* @0x298a6c bl 0x104f64 <_Z19F_DsMapAdd_InternaliPcS_> */
/* @0x298a70 ldr r2, [r6, #0xac] */
/* @0x298a74 ldr r1, [pc, #0x10c] */
/* @0x298a78 ldr r0, [r4] */
/* @0x298a7c vmov s15, r2 */
/* @0x298a80 add r1, pc, r1 */
/* @0x298a84 vcvt.f64.s32 d7, s15 */
/* @0x298a88 vmov r2, r3, d7 */
/* @0x298a8c bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298a90 ldr r1, [pc, #0xf4] */
/* @0x298a94 ldr r3, [pc, #0xf4] */
/* @0x298a98 ldr r2, [r4] */
/* @0x298a9c ldr r8, [r5, r1] */
/* @0x298aa0 str r2, [r8] */
/* @0x298aa4 ldr r9, [r5, r3] */
/* @0x298aa8 ldr r3, [r9, r10] */
/* @0x298aac cmp r3, #0 */
/* @0x298ab0 ble 0x298b58 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x1ac> */
/* @0x298ab4 ldr r2, [pc, #0xd8] */
/* @0x298ab8 mov r4, #0 */
/* @0x298abc ldr r3, [pc, #0xd4] */
/* @0x298ac0 movw r7, #0x3a24 */
/* @0x298ac4 ldr r6, [r5, r2] */
/* @0x298ac8 ldr r5, [r5, r3] */
/* @0x298acc ldr r3, [r6] */
/* @0x298ad0 ldr r1, [r5, r7] */
/* @0x298ad4 ldr r2, [r3, #0x4] */
/* @0x298ad8 ldr r1, [r1, r4, lsl #2] */
/* @0x298adc ldr r3, [r3] */
/* @0x298ae0 and r2, r1, r2 */
/* @0x298ae4 ldr r3, [r3, r2, lsl #3] */
/* @0x298ae8 cmp r3, #0 */
/* @0x298aec bne 0x298b00 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x154> */
/* @0x298af0 b 0x298b10 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x164> */
/* @0x298af4 ldr r3, [r3, #0x4] */
/* @0x298af8 cmp r3, #0 */
/* @0x298afc beq 0x298b10 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x164> */
/* @0x298b00 ldr r2, [r3, #0x8] */
/* @0x298b04 cmp r1, r2 */
/* @0x298b08 bne 0x298af4 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x148> */
/* @0x298b0c ldr r3, [r3, #0xc] */
/* @0x298b10 ldr r11, [r3, #0xc4] */
/* @0x298b14 cmp r11, #0 */
/* @0x298b18 bne 0x298b3c <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x190> */
/* @0x298b1c b 0x298b48 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x19c> */
/* @0x298b20 ldr r11, [r11] */
/* @0x298b24 mov r1, r0 */
/* @0x298b28 mov r2, #7 */
/* @0x298b2c mov r3, #68 */
/* @0x298b30 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x298b34 cmp r11, #0 */
/* @0x298b38 beq 0x298b48 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x19c> */
/* @0x298b3c ldr r0, [r11, #0x8] */
/* @0x298b40 cmp r0, #0 */
/* @0x298b44 bne 0x298b20 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x174> */
/* @0x298b48 ldr r3, [r9, r10] */
/* @0x298b4c add r4, r4, #1 */
/* @0x298b50 cmp r3, r4 */
/* @0x298b54 bgt 0x298acc <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x120> */
/* @0x298b58 vpop {d8} */
/* @0x298b5c mvn r3, #0 */
/* @0x298b60 str r3, [r8] */
/* @0x298b64 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x298b68 andseq r9, r5, r8, lsl #5 */
/* @0x298b6c .word 0xfffff750 */
/* @0x298b70 andeq sp, r10, r12, asr #14 */
/* @0x298b74 andeq r0, r12, r4, lsl #25 */
/* @0x298b78 andeq r8, r9, r8, lsr #32 */
/* @0x298b7c andeq r0, r12, r4, ror r12 */
/* @0x298b80 .word 0xfffffd54 */
/* @0x298b84 andeq r0, r12, r4, asr r12 */
/* @0x298b88 andeq r0, r12, r0, lsl r12 */
/* @0x298b8c .word 0xffffdec8 */
/* @0x298b90 .word 0xffffdeb8 */
/* @0x298b94 .word 0xffffbfec */
/* @0x298b98 .word 0xffffdebc */

/* ── FUNC 0x298b9c · ThrowNetworkEvent(int, int, int) · size=536 · insn=134 */
/* @0x298b9c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x298ba0 sub sp, sp, #20 */
/* @0x298ba4 ldr r7, [pc, #0x1d4] */
/* @0x298ba8 mov r5, r0 */
/* @0x298bac mov r6, r2 */
/* @0x298bb0 mov r8, r1 */
/* @0x298bb4 bl 0x29871c <_Z16InitNetworkEventv> */
/* @0x298bb8 ldr r0, [pc, #0x1c4] */
/* @0x298bbc add r7, pc, r7 */
/* @0x298bc0 ldr r1, [pc, #0x1c0] */
/* @0x298bc4 mov r2, #0 */
/* @0x298bc8 mov r3, #0 */
/* @0x298bcc ldr r4, [r7, r0] */
/* @0x298bd0 add r1, pc, r1 */
/* @0x298bd4 movt r3, #0x4008 */
/* @0x298bd8 movw r10, #0x1d10 */
/* @0x298bdc ldr r0, [r4] */
/* @0x298be0 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298be4 vmov s15, r5 */
/* @0x298be8 ldr r1, [pc, #0x19c] */
/* @0x298bec add r5, r5, r5, lsl #1 */
/* @0x298bf0 vcvt.f64.s32 d7, s15 */
/* @0x298bf4 ldr r0, [r4] */
/* @0x298bf8 add r1, pc, r1 */
/* @0x298bfc vmov r2, r3, d7 */
/* @0x298c00 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298c04 ldr r1, [pc, #0x184] */
/* @0x298c08 vmov s15, r8 */
/* @0x298c0c ldr r0, [r4] */
/* @0x298c10 add r1, pc, r1 */
/* @0x298c14 vcvt.f64.s32 d7, s15 */
/* @0x298c18 vmov r2, r3, d7 */
/* @0x298c1c bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298c20 ldr r1, [pc, #0x16c] */
/* @0x298c24 vmov s15, r6 */
/* @0x298c28 ldr r0, [r4] */
/* @0x298c2c add r1, pc, r1 */
/* @0x298c30 vcvt.f64.s32 d7, s15 */
/* @0x298c34 vmov r2, r3, d7 */
/* @0x298c38 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298c3c ldr r3, [pc, #0x154] */
/* @0x298c40 ldr r1, [pc, #0x154] */
/* @0x298c44 ldr r0, [r4] */
/* @0x298c48 ldr r3, [r7, r3] */
/* @0x298c4c add r1, pc, r1 */
/* @0x298c50 add r3, r3, r5, lsl #2 */
/* @0x298c54 ldr r2, [r3, #0x8] */
/* @0x298c58 ldr r5, [r3, #0x4] */
/* @0x298c5c cmp r2, #0 */
/* @0x298c60 ldrne r5, [r2] */
/* @0x298c64 add r2, r5, #108 */
/* @0x298c68 bl 0x104f64 <_Z19F_DsMapAdd_InternaliPcS_> */
/* @0x298c6c ldr r2, [r5, #0xac] */
/* @0x298c70 ldr r1, [pc, #0x128] */
/* @0x298c74 ldr r0, [r4] */
/* @0x298c78 vmov s15, r2 */
/* @0x298c7c add r1, pc, r1 */
/* @0x298c80 vcvt.f64.s32 d7, s15 */
/* @0x298c84 vmov r2, r3, d7 */
/* @0x298c88 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd> */
/* @0x298c8c ldr r1, [pc, #0x110] */
/* @0x298c90 ldr r3, [pc, #0x110] */
/* @0x298c94 ldr r2, [r4] */
/* @0x298c98 ldr r1, [r7, r1] */
/* @0x298c9c str r1, [sp, #0xc] */
/* @0x298ca0 str r2, [r1] */
/* @0x298ca4 ldr r6, [r7, r3] */
/* @0x298ca8 ldr r3, [r6, r10] */
/* @0x298cac cmp r3, #0 */
/* @0x298cb0 ble 0x298d6c <_Z17ThrowNetworkEventiii+0x1d0> */
/* @0x298cb4 ldr r2, [pc, #0xf0] */
/* @0x298cb8 mov r5, #0 */
/* @0x298cbc ldr r3, [pc, #0xec] */
/* @0x298cc0 movw r9, #0x3a24 */
/* @0x298cc4 mov r4, #68 */
/* @0x298cc8 ldr r8, [r7, r2] */
/* @0x298ccc ldr r7, [r7, r3] */
/* @0x298cd0 ldr r3, [r8] */
/* @0x298cd4 ldr r1, [r7, r9] */
/* @0x298cd8 ldr r2, [r3, #0x4] */
/* @0x298cdc ldr r1, [r1, r5, lsl #2] */
/* @0x298ce0 ldr r3, [r3] */
/* @0x298ce4 and r2, r1, r2 */
/* @0x298ce8 ldr r3, [r3, r2, lsl #3] */
/* @0x298cec cmp r3, #0 */
/* @0x298cf0 bne 0x298d04 <_Z17ThrowNetworkEventiii+0x168> */
/* @0x298cf4 b 0x298d14 <_Z17ThrowNetworkEventiii+0x178> */
/* @0x298cf8 ldr r3, [r3, #0x4] */
/* @0x298cfc cmp r3, #0 */
/* @0x298d00 beq 0x298d14 <_Z17ThrowNetworkEventiii+0x178> */
/* @0x298d04 ldr r2, [r3, #0x8] */
/* @0x298d08 cmp r1, r2 */
/* @0x298d0c bne 0x298cf8 <_Z17ThrowNetworkEventiii+0x15c> */
/* @0x298d10 ldr r3, [r3, #0xc] */
/* @0x298d14 ldr r11, [r3, #0xc4] */
/* @0x298d18 cmp r11, #0 */
/* @0x298d1c beq 0x298d5c <_Z17ThrowNetworkEventiii+0x1c0> */
/* @0x298d20 ldr r3, [r11, #0x8] */
/* @0x298d24 cmp r3, #0 */
/* @0x298d28 beq 0x298d5c <_Z17ThrowNetworkEventiii+0x1c0> */
/* @0x298d2c ldr r2, [r11, #0x8] */
/* @0x298d30 mov r3, #7 */
/* @0x298d34 ldr r11, [r11] */
/* @0x298d38 cmp r2, #0 */
/* @0x298d3c mov r0, r2 */
/* @0x298d40 mov r1, r2 */
/* @0x298d44 beq 0x298d18 <_Z17ThrowNetworkEventiii+0x17c> */
/* @0x298d48 ldr r2, [r2, #0x7c] */
/* @0x298d4c str r4, [sp] */
/* @0x298d50 bl 0xf31f8 <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii> */
/* @0x298d54 cmp r11, #0 */
/* @0x298d58 bne 0x298d20 <_Z17ThrowNetworkEventiii+0x184> */
/* @0x298d5c ldr r3, [r6, r10] */
/* @0x298d60 add r5, r5, #1 */
/* @0x298d64 cmp r3, r5 */
/* @0x298d68 bgt 0x298cd0 <_Z17ThrowNetworkEventiii+0x134> */
/* @0x298d6c ldr r1, [sp, #0xc] */
/* @0x298d70 mvn r3, #0 */
/* @0x298d74 str r3, [r1] */
/* @0x298d78 add sp, sp, #20 */
/* @0x298d7c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x298d80 mulseq r5, r4, r0 */
/* @0x298d84 .word 0xfffff750 */
/* @0x298d88 andeq sp, r10, r8, asr r5 */
/* @0x298d8c andeq r7, r9, r8, asr #28 */
/* @0x298d90 andeq r0, r12, r4, lsr #21 */
/* @0x298d94 muleq r12, r0, r10 */
/* @0x298d98 .word 0xfffffd54 */
/* @0x298d9c andeq r0, r12, r8, asr r10 */
/* @0x298da0 andeq r0, r12, r4, lsl r10 */
/* @0x298da4 .word 0xffffdec8 */
/* @0x298da8 .word 0xffffdeb8 */
/* @0x298dac .word 0xffffbfec */
/* @0x298db0 .word 0xffffdebc */

/* ── FUNC 0x298db4 · PollServersOnly() · size=64 · insn=16 */
/* @0x298db4 push {r3, r4, r5, lr} */
/* @0x298db8 ldr r4, [pc, #0x30] */
/* @0x298dbc ldr r4, [pc, r4] */
/* @0x298dc0 add r5, r4, #768 */
/* @0x298dc4 ldrb r3, [r4] */
/* @0x298dc8 cmp r3, #0 */
/* @0x298dcc beq 0x298de0 <_Z15PollServersOnlyv+0x2c> */
/* @0x298dd0 ldr r0, [r4, #0x8] */
/* @0x298dd4 cmp r0, #0 */
/* @0x298dd8 beq 0x298de0 <_Z15PollServersOnlyv+0x2c> */
/* @0x298ddc bl 0x297f98 <_ZN8yyServer7ProcessEv> */
/* @0x298de0 add r4, r4, #12 */
/* @0x298de4 cmp r4, r5 */
/* @0x298de8 bne 0x298dc4 <_Z15PollServersOnlyv+0x10> */
/* @0x298dec pop {r3, r4, r5, pc} */
/* @0x298df0 andseq r8, r5, r8, ror #23 */

/* ── FUNC 0x298df4 · InitNetworking() · size=52 · insn=13 */
/* @0x298df4 ldr r1, [pc, #0x28] */
/* @0x298df8 mov r2, #0 */
/* @0x298dfc ldr r1, [pc, r1] */
/* @0x298e00 add r3, r1, #8 */
/* @0x298e04 add r1, r1, #776 */
/* @0x298e08 strb r2, [r3, #-0x8] */
/* @0x298e0c strb r2, [r3, #-0x7] */
/* @0x298e10 str r2, [r3, #-0x4] */
/* @0x298e14 str r2, [r3], #12 */
/* @0x298e18 cmp r3, r1 */
/* @0x298e1c bne 0x298e08 <_Z14InitNetworkingv+0x14> */
/* @0x298e20 bx lr */
/* @0x298e24 andseq r8, r5, r8, lsr #23 */

/* ── FUNC 0x298e28 · AllocSocket() · size=108 · insn=27 */
/* @0x298e28 ldr r1, [pc, #0x60] */
/* @0x298e2c mov r3, #0 */
/* @0x298e30 str r4, [sp, #-0x4]! */
/* @0x298e34 mov r0, r3 */
/* @0x298e38 ldr r1, [pc, r1] */
/* @0x298e3c b 0x298e4c <_Z11AllocSocketv+0x24> */
/* @0x298e40 add r0, r0, #1 */
/* @0x298e44 cmp r0, #64 */
/* @0x298e48 beq 0x298e84 <_Z11AllocSocketv+0x5c> */
/* @0x298e4c ldrb r2, [r1, r3] */
/* @0x298e50 add r3, r3, #12 */
/* @0x298e54 cmp r2, #0 */
/* @0x298e58 bne 0x298e40 <_Z11AllocSocketv+0x18> */
/* @0x298e5c add r12, r0, r0, lsl #1 */
/* @0x298e60 mov r4, #1 */
/* @0x298e64 lsl r12, r12, #2 */
/* @0x298e68 add r3, r1, r12 */
/* @0x298e6c strb r4, [r1, r12] */
/* @0x298e70 strb r2, [r3, #0x1] */
/* @0x298e74 str r2, [r3, #0x4] */
/* @0x298e78 str r2, [r3, #0x8] */
/* @0x298e7c ldr r4, [sp], #4 */
/* @0x298e80 bx lr */
/* @0x298e84 mvn r0, #0 */
/* @0x298e88 ldr r4, [sp], #4 */
/* @0x298e8c bx lr */
/* @0x298e90 andseq r8, r5, r12, ror #22 */

/* ── FUNC 0x298e94 · F_NETWORK_Create_Socket(RValue&, CInstance*, CInstance*, int, RValue*) · size=316 · insn=79 */
/* @0x298e94 push {r4, r5, r6, r7, r8, lr} */
/* @0x298e98 mov r2, #0 */
/* @0x298e9c ldr r5, [pc, #0x118] */
/* @0x298ea0 mov r3, r2 */
/* @0x298ea4 str r2, [r0] */
/* @0x298ea8 movt r3, #0xbff0 */
/* @0x298eac ldr r5, [pc, r5] */
/* @0x298eb0 str r2, [r0, #0xc] */
/* @0x298eb4 mov r4, r0 */
/* @0x298eb8 str r3, [r0, #0x4] */
/* @0x298ebc ldrb r2, [r5] */
/* @0x298ec0 ldr r6, [sp, #0x18] */
/* @0x298ec4 cmp r2, #0 */
/* @0x298ec8 beq 0x298fa0 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x298ecc mov r0, r6 */
/* @0x298ed0 mov r1, #0 */
/* @0x298ed4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x298ed8 ldr r3, [pc, #0xe0] */
/* @0x298edc ldr r3, [pc, r3] */
/* @0x298ee0 ldr r3, [r3] */
/* @0x298ee4 sub r3, r3, #2 */
/* @0x298ee8 cmp r3, #2 */
/* @0x298eec mov r5, r0 */
/* @0x298ef0 bls 0x298f68 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x298ef4 cmp r0, #0 */
/* @0x298ef8 popne {r4, r5, r6, r7, r8, pc} */
/* @0x298efc bl 0x298e28 <_Z11AllocSocketv> */
/* @0x298f00 subs r6, r0, #0 */
/* @0x298f04 blt 0x298f8c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x298f08 mov r0, #200 */
/* @0x298f0c add r7, r6, r6, lsl #1 */
/* @0x298f10 bl 0x27c524 <_Znwj> */
/* @0x298f14 mov r1, r5 */
/* @0x298f18 mov r8, r0 */
/* @0x298f1c bl 0x2970ac <_ZN8yySocketC2E11eSocketType> */
/* @0x298f20 ldr r3, [pc, #0x9c] */
/* @0x298f24 mov r0, r8 */
/* @0x298f28 ldr r3, [pc, r3] */
/* @0x298f2c add r7, r3, r7, lsl #2 */
/* @0x298f30 str r8, [r7, #0x4] */
/* @0x298f34 bl 0x294ec8 <_ZN8yySocket4InitEv> */
/* @0x298f38 ldr r0, [r7, #0x4] */
/* @0x298f3c mov r1, #65536 */
/* @0x298f40 str r6, [r0, #0x68] */
/* @0x298f44 bl 0x296080 <_ZN8yySocket14AllocateBufferEi> */
/* @0x298f48 cmp r5, #1 */
/* @0x298f4c cmpne r5, #4 */
/* @0x298f50 beq 0x298fb0 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x298f54 vmov s15, r6 */
/* @0x298f58 vcvt.f64.s32 d7, s15 */
/* @0x298f5c vmov r2, r3, d7 */
/* @0x298f60 stm r4, {r2, r3} */
/* @0x298f64 pop {r4, r5, r6, r7, r8, pc} */
/* @0x298f68 cmp r0, #2 */
/* @0x298f6c bne 0x298efc <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x298f70 ldr r0, [pc, #0x50] */
/* @0x298f74 mov r1, #0 */
/* @0x298f78 add r0, pc, r0 */
/* @0x298f7c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x298f80 bl 0x298e28 <_Z11AllocSocketv> */
/* @0x298f84 subs r6, r0, #0 */
/* @0x298f88 bge 0x298f08 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x298f8c ldr r0, [pc, #0x38] */
/* @0x298f90 mov r1, #0 */
/* @0x298f94 pop {r4, r5, r6, r7, r8, lr} */
/* @0x298f98 add r0, pc, r0 */
/* @0x298f9c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x298fa0 bl 0x294d18 <_ZN8yySocket7StartupEv> */
/* @0x298fa4 mov r3, #1 */
/* @0x298fa8 strb r3, [r5] */
/* @0x298fac b 0x298ecc <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x298fb0 ldr r0, [r7, #0x4] */
/* @0x298fb4 bl 0x295fec <_ZN8yySocket12CreateSocketEv> */
/* @0x298fb8 b 0x298f54 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x298fbc ldrsheq r8, [r5], -r0 */
/* @0x298fc0 andseq r7, r5, r4, asr #8 */
/* @0x298fc4 andseq r8, r5, r12, ror r10 */
/* @0x298fc8 andeq r0, r12, r12, asr #14 */
/* @0x298fcc andeq r0, r12, r4, asr r7 */

/* ── FUNC 0x298fd0 · anon_298fd0 · size=604 · insn=151 */
/* @0x298fd0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x298fd4 mov r9, r2 */
/* @0x298fd8 ldr r11, [pc, #0x228] */
/* @0x298fdc sub sp, sp, #284 */
/* @0x298fe0 ldr r6, [pc, #0x224] */
/* @0x298fe4 mov r4, r0 */
/* @0x298fe8 add r11, pc, r11 */
/* @0x298fec ldr lr, [pc, #0x21c] */
/* @0x298ff0 mov r3, #0 */
/* @0x298ff4 mov r0, #0 */
/* @0x298ff8 ldr r6, [r11, r6] */
/* @0x298ffc movt r0, #0xbff0 */
/* @0x299000 str r3, [r4, #0xc] */
/* @0x299004 mov r5, r1 */
/* @0x299008 str r0, [r4, #0x4] */
/* @0x29900c ldr r2, [r6] */
/* @0x299010 str r6, [sp, #0x8] */
/* @0x299014 str r3, [r4] */
/* @0x299018 str r2, [sp, #0x114] */
/* @0x29901c ldr r7, [r11, lr] */
/* @0x299020 ldrb r3, [r7] */
/* @0x299024 cmp r3, #0 */
/* @0x299028 beq 0x299174 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2e0> */
/* @0x29902c mov r0, r5 */
/* @0x299030 mov r1, #2 */
/* @0x299034 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x299038 movw r2, #0x3f6 */
/* @0x29903c cmp r0, r2 */
/* @0x299040 mov r6, r0 */
/* @0x299044 bgt 0x299184 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2f0> */
/* @0x299048 cmp r0, #0 */
/* @0x29904c ble 0x2991c8 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x334> */
/* @0x299050 mov r0, r5 */
/* @0x299054 mov r1, #0 */
/* @0x299058 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29905c ldr r2, [pc, #0x1b0] */
/* @0x299060 ldr r10, [r11, r2] */
/* @0x299064 ldr r2, [r10] */
/* @0x299068 sub r2, r2, #2 */
/* @0x29906c cmp r2, #2 */
/* @0x299070 mov r8, r0 */
/* @0x299074 bhi 0x299168 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2d4> */
/* @0x299078 cmp r0, #2 */
/* @0x29907c beq 0x2991dc <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x348> */
/* @0x299080 bl 0x298e28 <_Z11AllocSocketv> */
/* @0x299084 subs r7, r0, #0 */
/* @0x299088 blt 0x2991f0 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x35c> */
/* @0x29908c ldr r2, [r10] */
/* @0x299090 mov r0, #44 */
/* @0x299094 lsl r3, r7, #1 */
/* @0x299098 str r3, [sp, #0xc] */
/* @0x29909c sub r2, r2, #2 */
/* @0x2990a0 cmp r2, #2 */
/* @0x2990a4 movhi r6, #1 */
/* @0x2990a8 bl 0x27c524 <_Znwj> */
/* @0x2990ac mov r1, r9 */
/* @0x2990b0 mov r10, r0 */
/* @0x2990b4 bl 0x2970f8 <_ZN8yyServerC2Eb> */
/* @0x2990b8 ldr r2, [pc, #0x158] */
/* @0x2990bc mov r0, r5 */
/* @0x2990c0 ldr r1, [sp, #0xc] */
/* @0x2990c4 ldr r5, [r11, r2] */
/* @0x2990c8 add r9, r1, r7 */
/* @0x2990cc mov r1, #1 */
/* @0x2990d0 add r9, r5, r9, lsl #2 */
/* @0x2990d4 str r10, [r9, #0x8] */
/* @0x2990d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x2990dc mov r12, #0 */
/* @0x2990e0 mov r3, r6 */
/* @0x2990e4 mov r1, r8 */
/* @0x2990e8 str r12, [sp] */
/* @0x2990ec mov r2, r0 */
/* @0x2990f0 mov r0, r10 */
/* @0x2990f4 bl 0x2971e0 <_ZN8yyServer4InitE11eSocketTypeiib> */
/* @0x2990f8 cmp r0, #0 */
/* @0x2990fc bge 0x2991a8 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x314> */
/* @0x299100 ldr r8, [r9, #0x8] */
/* @0x299104 cmp r8, #0 */
/* @0x299108 beq 0x29911c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x288> */
/* @0x29910c mov r0, r8 */
/* @0x299110 bl 0x297184 <_ZN8yyServerD2Ev> */
/* @0x299114 mov r0, r8 */
/* @0x299118 bl 0x27d1d0 <_ZdlPv> */
/* @0x29911c ldr r3, [sp, #0xc] */
/* @0x299120 add r7, r3, r7 */
/* @0x299124 mov r3, #0 */
/* @0x299128 mov r1, r3 */
/* @0x29912c movt r1, #0xbff0 */
/* @0x299130 lsl r7, r7, #2 */
/* @0x299134 add r0, r5, r7 */
/* @0x299138 str r3, [r0, #0x8] */
/* @0x29913c strb r3, [r5, r7] */
/* @0x299140 strb r3, [r0, #0x1] */
/* @0x299144 str r3, [r4] */
/* @0x299148 str r1, [r4, #0x4] */
/* @0x29914c ldr r1, [sp, #0x8] */
/* @0x299150 ldr r2, [sp, #0x114] */
/* @0x299154 ldr r3, [r1] */
/* @0x299158 cmp r2, r3 */
/* @0x29915c bne 0x299204 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x370> */
/* @0x299160 add sp, sp, #284 */
/* @0x299164 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x299168 cmp r0, #0 */
/* @0x29916c beq 0x299080 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x299170 b 0x29914c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2b8> */
/* @0x299174 bl 0x294d18 <_ZN8yySocket7StartupEv> */
/* @0x299178 mov r3, #1 */
/* @0x29917c strb r3, [r7] */
/* @0x299180 b 0x29902c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x299184 add r4, sp, #20 */
/* @0x299188 ldr r1, [pc, #0x8c] */
/* @0x29918c mov r0, r4 */
/* @0x299190 add r1, pc, r1 */
/* @0x299194 bl 0xb6550 <sprintf@plt> */
/* @0x299198 mov r0, r4 */
/* @0x29919c mov r1, #0 */
/* @0x2991a0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x2991a4 b 0x29914c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2b8> */
/* @0x2991a8 ldr r0, [r9, #0x8] */
/* @0x2991ac mov r1, r7 */
/* @0x2991b0 bl 0x297558 <_ZN8yyServer11SetSocketIDEi> */
/* @0x2991b4 vmov s15, r7 */
/* @0x2991b8 vcvt.f64.s32 d7, s15 */
/* @0x2991bc vmov r2, r3, d7 */
/* @0x2991c0 stm r4, {r2, r3} */
/* @0x2991c4 b 0x29914c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2b8> */
/* @0x2991c8 ldr r0, [pc, #0x50] */
/* @0x2991cc mov r1, #0 */
/* @0x2991d0 add r0, pc, r0 */
/* @0x2991d4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x2991d8 b 0x29914c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2b8> */
/* @0x2991dc ldr r0, [pc, #0x40] */
/* @0x2991e0 mov r1, #0 */
/* @0x2991e4 add r0, pc, r0 */
/* @0x2991e8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x2991ec b 0x299080 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x2991f0 ldr r0, [pc, #0x30] */
/* @0x2991f4 mov r1, #0 */
/* @0x2991f8 add r0, pc, r0 */
/* @0x2991fc bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x299200 b 0x29914c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2b8> */
/* @0x299204 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x299208 andseq r8, r5, r8, ror #24 */
/* @0x29920c .word 0xffffbd00 */
/* @0x299210 .word 0xfffffd4c */
/* @0x299214 .word 0xffffe6d0 */
/* @0x299218 .word 0xfffffd54 */
/* @0x29921c andeq r0, r12, r0, lsl #11 */
/* @0x299220 andeq r0, r12, r12, lsl #11 */
/* @0x299224 andeq r0, r12, r0, ror #9 */
/* @0x299228 andeq r0, r12, r0, lsr #11 */

/* ── FUNC 0x29922c · F_NETWORK_Create_Server(RValue&, CInstance*, CInstance*, int, RValue*) · size=12 · insn=3 */
/* @0x29922c ldr r1, [sp] */
/* @0x299230 mov r2, #0 */
/* @0x299234 b 0x298fd0 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x13c> */
