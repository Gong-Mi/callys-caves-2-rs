/* libyoyo.so 覆盖卡组 0155
 * 函数 0x1ce134..0x1d317c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1ce134 · HandleWebEvent(int) · size=392 · insn=98 */
/* @0x1ce134 sub r3, r0, #60 */
/* @0x1ce138 ldr r1, [pc, #0x168] */
/* @0x1ce13c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ce140 cmp r0, #67 */
/* @0x1ce144 cmpne r3, #4 */
/* @0x1ce148 sub sp, sp, #28 */
/* @0x1ce14c add r1, pc, r1 */
/* @0x1ce150 str r0, [sp, #0x14] */
/* @0x1ce154 bls 0x1ce16c <_Z14HandleWebEventi+0x38> */
/* @0x1ce158 sub r3, r0, #69 */
/* @0x1ce15c cmp r3, #6 */
/* @0x1ce160 bls 0x1ce16c <_Z14HandleWebEventi+0x38> */
/* @0x1ce164 add sp, sp, #28 */
/* @0x1ce168 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ce16c ldr r3, [pc, #0x138] */
/* @0x1ce170 ldr r12, [pc, #0x138] */
/* @0x1ce174 ldr r9, [sp, #0x14] */
/* @0x1ce178 ldr r0, [r1, r3] */
/* @0x1ce17c add r8, r9, #1792 */
/* @0x1ce180 ldrd r4, r5, [r0] */
/* @0x1ce184 adds r2, r4, #1 */
/* @0x1ce188 adc r3, r5, #0 */
/* @0x1ce18c strd r2, r3, [r0] */
/* @0x1ce190 ldr r9, [r1, r12] */
/* @0x1ce194 ldr r3, [r9, r8, lsl #2] */
/* @0x1ce198 cmp r3, #0 */
/* @0x1ce19c ble 0x1ce164 <_Z14HandleWebEventi+0x30> */
/* @0x1ce1a0 ldr r2, [pc, #0x10c] */
/* @0x1ce1a4 mov r7, #0 */
/* @0x1ce1a8 ldr r3, [pc, #0x108] */
/* @0x1ce1ac ldr r10, [r1, r2] */
/* @0x1ce1b0 ldr r11, [r1, r3] */
/* @0x1ce1b4 add r10, r10, r8, lsl #3 */
/* @0x1ce1b8 ldr r3, [r11] */
/* @0x1ce1bc ldr r1, [r10, #0x4] */
/* @0x1ce1c0 ldr r2, [r3, #0x4] */
/* @0x1ce1c4 ldr r1, [r1, r7, lsl #2] */
/* @0x1ce1c8 ldr r3, [r3] */
/* @0x1ce1cc and r2, r1, r2 */
/* @0x1ce1d0 ldr r3, [r3, r2, lsl #3] */
/* @0x1ce1d4 cmp r3, #0 */
/* @0x1ce1d8 bne 0x1ce1ec <_Z14HandleWebEventi+0xb8> */
/* @0x1ce1dc b 0x1ce290 <_Z14HandleWebEventi+0x15c> */
/* @0x1ce1e0 ldr r3, [r3, #0x4] */
/* @0x1ce1e4 cmp r3, #0 */
/* @0x1ce1e8 beq 0x1ce290 <_Z14HandleWebEventi+0x15c> */
/* @0x1ce1ec ldr r2, [r3, #0x8] */
/* @0x1ce1f0 cmp r1, r2 */
/* @0x1ce1f4 bne 0x1ce1e0 <_Z14HandleWebEventi+0xac> */
/* @0x1ce1f8 ldr r3, [r3, #0xc] */
/* @0x1ce1fc cmp r3, #0 */
/* @0x1ce200 beq 0x1ce290 <_Z14HandleWebEventi+0x15c> */
/* @0x1ce204 ldr r6, [r3, #0xc4] */
/* @0x1ce208 cmp r6, #0 */
/* @0x1ce20c beq 0x1ce290 <_Z14HandleWebEventi+0x15c> */
/* @0x1ce210 ldr r3, [r6, #0x8] */
/* @0x1ce214 cmp r3, #0 */
/* @0x1ce218 beq 0x1ce290 <_Z14HandleWebEventi+0x15c> */
/* @0x1ce21c str r8, [sp, #0x10] */
/* @0x1ce220 str r9, [sp, #0xc] */
/* @0x1ce224 b 0x1ce234 <_Z14HandleWebEventi+0x100> */
/* @0x1ce228 ldr r3, [r6, #0x8] */
/* @0x1ce22c cmp r3, #0 */
/* @0x1ce230 beq 0x1ce288 <_Z14HandleWebEventi+0x154> */
/* @0x1ce234 ldr r2, [r6, #0x8] */
/* @0x1ce238 ldr r6, [r6] */
/* @0x1ce23c ldrb r3, [r2, #0x68] */
/* @0x1ce240 cmp r3, #0 */
/* @0x1ce244 bne 0x1ce280 <_Z14HandleWebEventi+0x14c> */
/* @0x1ce248 ldrb r3, [r2, #0x69] */
/* @0x1ce24c cmp r3, #0 */
/* @0x1ce250 bne 0x1ce280 <_Z14HandleWebEventi+0x14c> */
/* @0x1ce254 ldrd r8, r9, [r2, #112] */
/* @0x1ce258 mov r0, r2 */
/* @0x1ce25c mov r1, r2 */
/* @0x1ce260 mov r3, #7 */
/* @0x1ce264 cmp r4, r8 */
/* @0x1ce268 sbcs r9, r5, r9 */
/* @0x1ce26c blt 0x1ce280 <_Z14HandleWebEventi+0x14c> */
/* @0x1ce270 ldr r12, [sp, #0x14] */
/* @0x1ce274 ldr r2, [r2, #0x7c] */
/* @0x1ce278 str r12, [sp] */
/* @0x1ce27c bl 0xf31f8 <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii> */
/* @0x1ce280 cmp r6, #0 */
/* @0x1ce284 bne 0x1ce228 <_Z14HandleWebEventi+0xf4> */
/* @0x1ce288 ldr r8, [sp, #0x10] */
/* @0x1ce28c ldr r9, [sp, #0xc] */
/* @0x1ce290 ldr r3, [r9, r8, lsl #2] */
/* @0x1ce294 add r7, r7, #1 */
/* @0x1ce298 cmp r3, r7 */
/* @0x1ce29c bgt 0x1ce1b8 <_Z14HandleWebEventi+0x84> */
/* @0x1ce2a0 add sp, sp, #28 */
/* @0x1ce2a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ce2a8 eoreq r3, r2, r4, lsl #22 */
/* @0x1ce2ac .word 0xffffdeb4 */
/* @0x1ce2b0 .word 0xffffdeb8 */
/* @0x1ce2b4 .word 0xffffdebc */
/* @0x1ce2b8 .word 0xffffbfec */

/* ── FUNC 0x1ce2bc · HttpCreateUpdateMap(HTTP_REQ_CONTEXT*, void*, int*) · size=208 · insn=52 */
/* @0x1ce2bc vldr s14, [r0, #60] */
/* @0x1ce2c0 vcvt.f64.s32 d7, s14 */
/* @0x1ce2c4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1ce2c8 vldr s12, [r0, #64] */
/* @0x1ce2cc mov r8, r2 */
/* @0x1ce2d0 ldr r2, [r0, #0x24] */
/* @0x1ce2d4 sub sp, sp, #76 */
/* @0x1ce2d8 ldr r9, [r0, #0x20] */
/* @0x1ce2dc mov r6, #0 */
/* @0x1ce2e0 ldr r1, [pc, #0x90] */
/* @0x1ce2e4 mov r7, #0 */
/* @0x1ce2e8 ldr lr, [pc, #0x8c] */
/* @0x1ce2ec mov r3, #0 */
/* @0x1ce2f0 vstr d7, [sp, #56] */
/* @0x1ce2f4 vmov s15, r2 */
/* @0x1ce2f8 vcvt.f64.s32 d6, s12 */
/* @0x1ce2fc strd r6, r7, [sp, #24] */
/* @0x1ce300 add r1, pc, r1 */
/* @0x1ce304 ldr r6, [pc, #0x74] */
/* @0x1ce308 str r1, [sp, #0x34] */
/* @0x1ce30c add lr, pc, lr */
/* @0x1ce310 ldr r12, [pc, #0x6c] */
/* @0x1ce314 mov r4, #0 */
/* @0x1ce318 ldr r1, [pc, #0x68] */
/* @0x1ce31c add r6, pc, r6 */
/* @0x1ce320 add r12, pc, r12 */
/* @0x1ce324 str r3, [sp] */
/* @0x1ce328 str r3, [sp, #0x10] */
/* @0x1ce32c add r1, pc, r1 */
/* @0x1ce330 vcvt.f64.s32 d7, s15 */
/* @0x1ce334 str r3, [sp, #0x30] */
/* @0x1ce338 str r3, [sp, #0x40] */
/* @0x1ce33c vstr d6, [sp, #40] */
/* @0x1ce340 str r9, [sp, #0x20] */
/* @0x1ce344 mov r5, #0 */
/* @0x1ce348 str r6, [sp, #0x4] */
/* @0x1ce34c movt r5, #0x3ff0 */
/* @0x1ce350 str lr, [sp, #0x14] */
/* @0x1ce354 mov r0, #5 */
/* @0x1ce358 strd r4, r5, [sp, #8] */
/* @0x1ce35c str r12, [sp, #0x24] */
/* @0x1ce360 vmov r2, r3, d7 */
/* @0x1ce364 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x1ce368 str r0, [r8] */
/* @0x1ce36c mov r0, #62 */
/* @0x1ce370 add sp, sp, #76 */
/* @0x1ce374 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1ce378 ldrsheq r1, [r7], -r4 */
/* @0x1ce37c andseq r1, r7, r0, asr #27 */
/* @0x1ce380 andseq r2, r6, r4, lsr r7 */
/* @0x1ce384 andseq r1, r7, r4, asr #27 */
/* @0x1ce388 andseq r2, r6, r4, lsl r7 */

/* ── FUNC 0x1ce38c · HandleAsyncEvents() · size=520 · insn=130 */
/* @0x1ce38c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ce390 sub sp, sp, #20 */
/* @0x1ce394 add r10, sp, #12 */
/* @0x1ce398 bl 0x153be8 <_Z19YYIAPEventsDispatchv> */
/* @0x1ce39c ldr r6, [pc, #0x1e0] */
/* @0x1ce3a0 bl 0x155bf8 <_Z19Push_DispatchEventsv> */
/* @0x1ce3a4 bl 0x15dbe8 <_Z19ProcessGMLCallbacksv> */
/* @0x1ce3a8 mov r0, r10 */
/* @0x1ce3ac bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x1ce3b0 ldr r3, [pc, #0x1d0] */
/* @0x1ce3b4 add r6, pc, r6 */
/* @0x1ce3b8 ldr r8, [r6, r3] */
/* @0x1ce3bc ldr r4, [r8] */
/* @0x1ce3c0 cmp r4, #0 */
/* @0x1ce3c4 movne r11, #0 */
/* @0x1ce3c8 mvnne r7, #0 */
/* @0x1ce3cc movne r9, r11 */
/* @0x1ce3d0 bne 0x1ce4b0 <_Z17HandleAsyncEventsv+0x124> */
/* @0x1ce3d4 b 0x1ce574 <_Z17HandleAsyncEventsv+0x1e8> */
/* @0x1ce3d8 cmp r3, #7 */
/* @0x1ce3dc bne 0x1ce4a0 <_Z17HandleAsyncEventsv+0x114> */
/* @0x1ce3e0 ldr r2, [pc, #0x1a4] */
/* @0x1ce3e4 cmp r11, #0 */
/* @0x1ce3e8 ldr r3, [r4, #0x10] */
/* @0x1ce3ec strne r5, [r11, #0x4] */
/* @0x1ce3f0 streq r5, [r8] */
/* @0x1ce3f4 cmp r3, #0 */
/* @0x1ce3f8 ldr r11, [r6, r2] */
/* @0x1ce3fc str r7, [r11] */
/* @0x1ce400 beq 0x1ce470 <_Z17HandleAsyncEventsv+0xe4> */
/* @0x1ce404 mov r0, r4 */
/* @0x1ce408 ldr r1, [r4, #0x1c] */
/* @0x1ce40c mov r2, r11 */
/* @0x1ce410 blx r3 */
/* @0x1ce414 cmp r0, #59 */
/* @0x1ce418 ble 0x1ce420 <_Z17HandleAsyncEventsv+0x94> */
/* @0x1ce41c bl 0x1ce134 <_Z14HandleWebEventi> */
/* @0x1ce420 ldr r3, [r11] */
/* @0x1ce424 cmp r3, #0 */
/* @0x1ce428 blt 0x1ce470 <_Z17HandleAsyncEventsv+0xe4> */
/* @0x1ce42c ldr r2, [pc, #0x15c] */
/* @0x1ce430 ldr r1, [r6, r2] */
/* @0x1ce434 ldr r2, [r1, #0x4] */
/* @0x1ce438 add r0, r2, r3, lsl #2 */
/* @0x1ce43c ldr r5, [r2, r3, lsl #2] */
/* @0x1ce440 cmp r5, #0 */
/* @0x1ce444 beq 0x1ce46c <_Z17HandleAsyncEventsv+0xe0> */
/* @0x1ce448 mov r0, r5 */
/* @0x1ce44c str r1, [sp] */
/* @0x1ce450 bl 0x20d9e8 <_ZN7CDS_MapD2Ev> */
/* @0x1ce454 mov r0, r5 */
/* @0x1ce458 bl 0x27d1d0 <_ZdlPv> */
/* @0x1ce45c ldr r1, [sp] */
/* @0x1ce460 ldr r0, [r11] */
/* @0x1ce464 ldr r3, [r1, #0x4] */
/* @0x1ce468 add r0, r3, r0, lsl #2 */
/* @0x1ce46c str r9, [r0] */
/* @0x1ce470 ldr r3, [r4, #0x14] */
/* @0x1ce474 str r7, [r11] */
/* @0x1ce478 cmp r3, #0 */
/* @0x1ce47c beq 0x1ce488 <_Z17HandleAsyncEventsv+0xfc> */
/* @0x1ce480 mov r0, r4 */
/* @0x1ce484 blx r3 */
/* @0x1ce488 ldr r3, [r4] */
/* @0x1ce48c mov r0, r4 */
/* @0x1ce490 mov r4, #0 */
/* @0x1ce494 ldr r3, [r3, #0x4] */
/* @0x1ce498 blx r3 */
/* @0x1ce49c ldr r5, [r8] */
/* @0x1ce4a0 cmp r5, #0 */
/* @0x1ce4a4 beq 0x1ce574 <_Z17HandleAsyncEventsv+0x1e8> */
/* @0x1ce4a8 mov r11, r4 */
/* @0x1ce4ac mov r4, r5 */
/* @0x1ce4b0 ldrb r3, [r4, #0x8] */
/* @0x1ce4b4 ldr r5, [r4, #0x4] */
/* @0x1ce4b8 cmp r3, #0 */
/* @0x1ce4bc beq 0x1ce4a0 <_Z17HandleAsyncEventsv+0x114> */
/* @0x1ce4c0 ldr r3, [r4, #0x18] */
/* @0x1ce4c4 cmp r3, #0 */
/* @0x1ce4c8 beq 0x1ce4d4 <_Z17HandleAsyncEventsv+0x148> */
/* @0x1ce4cc mov r0, r4 */
/* @0x1ce4d0 blx r3 */
/* @0x1ce4d4 ldr r3, [r4, #0xc] */
/* @0x1ce4d8 cmp r3, #3 */
/* @0x1ce4dc bne 0x1ce3d8 <_Z17HandleAsyncEventsv+0x4c> */
/* @0x1ce4e0 ldr r2, [pc, #0xa4] */
/* @0x1ce4e4 ldr r3, [r4, #0x10] */
/* @0x1ce4e8 ldr r11, [r6, r2] */
/* @0x1ce4ec cmp r3, #0 */
/* @0x1ce4f0 str r7, [r11] */
/* @0x1ce4f4 beq 0x1ce568 <_Z17HandleAsyncEventsv+0x1dc> */
/* @0x1ce4f8 mov r0, r4 */
/* @0x1ce4fc ldr r1, [r4, #0x1c] */
/* @0x1ce500 mov r2, r11 */
/* @0x1ce504 bl 0x1ce2bc <_Z19HttpCreateUpdateMapP16HTTP_REQ_CONTEXTPvPi> */
/* @0x1ce508 cmp r0, #59 */
/* @0x1ce50c ble 0x1ce514 <_Z17HandleAsyncEventsv+0x188> */
/* @0x1ce510 bl 0x1ce134 <_Z14HandleWebEventi> */
/* @0x1ce514 ldr r3, [r11] */
/* @0x1ce518 cmp r3, #0 */
/* @0x1ce51c blt 0x1ce568 <_Z17HandleAsyncEventsv+0x1dc> */
/* @0x1ce520 ldr r2, [pc, #0x68] */
/* @0x1ce524 ldr r1, [r6, r2] */
/* @0x1ce528 ldr r2, [r1, #0x4] */
/* @0x1ce52c add r0, r2, r3, lsl #2 */
/* @0x1ce530 ldr r3, [r2, r3, lsl #2] */
/* @0x1ce534 cmp r3, #0 */
/* @0x1ce538 beq 0x1ce564 <_Z17HandleAsyncEventsv+0x1d8> */
/* @0x1ce53c mov r0, r3 */
/* @0x1ce540 stm sp, {r1, r3} */
/* @0x1ce544 bl 0x20d9e8 <_ZN7CDS_MapD2Ev> */
/* @0x1ce548 ldr r3, [sp, #0x4] */
/* @0x1ce54c mov r0, r3 */
/* @0x1ce550 bl 0x27d1d0 <_ZdlPv> */
/* @0x1ce554 ldr r1, [sp] */
/* @0x1ce558 ldr r0, [r11] */
/* @0x1ce55c ldr r3, [r1, #0x4] */
/* @0x1ce560 add r0, r3, r0, lsl #2 */
/* @0x1ce564 str r9, [r0] */
/* @0x1ce568 cmp r5, #0 */
/* @0x1ce56c str r7, [r11] */
/* @0x1ce570 bne 0x1ce4a8 <_Z17HandleAsyncEventsv+0x11c> */
/* @0x1ce574 mov r0, r10 */
/* @0x1ce578 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1ce57c add sp, sp, #20 */
/* @0x1ce580 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ce584 mlaeq r2, r12, r8, r3 */
/* @0x1ce588 .word 0xffffc1a8 */
/* @0x1ce58c .word 0xffffdec8 */
/* @0x1ce590 .word 0xffffbcec */

/* ── FUNC 0x1ce594 · HandleOther() · size=6944 · insn=1736 */
/* @0x1ce594 ldr r12, [pc, #0x680] */
/* @0x1ce598 ldr r3, [pc, #0x680] */
/* @0x1ce59c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ce5a0 vpush {d8, d9, d10, d11} */
/* @0x1ce5a4 add r12, pc, r12 */
/* @0x1ce5a8 sub sp, sp, #828 */
/* @0x1ce5ac str r12, [sp, #0x40] */
/* @0x1ce5b0 ldr r3, [r12, r3] */
/* @0x1ce5b4 str r3, [sp, #0x54] */
/* @0x1ce5b8 ldrb r3, [r3] */
/* @0x1ce5bc cmp r3, #0 */
/* @0x1ce5c0 bne 0x1d000c <_Z11HandleOtherv+0x1a78> */
/* @0x1ce5c4 ldr r12, [sp, #0x40] */
/* @0x1ce5c8 mov r8, #7168 */
/* @0x1ce5cc ldr r3, [pc, #0x650] */
/* @0x1ce5d0 ldr r1, [pc, #0x650] */
/* @0x1ce5d4 ldr r3, [r12, r3] */
/* @0x1ce5d8 str r3, [sp, #0x44] */
/* @0x1ce5dc ldrd r2, r3, [r3] */
/* @0x1ce5e0 ldr r12, [sp, #0x44] */
/* @0x1ce5e4 strd r2, r3, [sp, #8] */
/* @0x1ce5e8 adds r2, r2, #1 */
/* @0x1ce5ec adc r3, r3, #0 */
/* @0x1ce5f0 strd r2, r3, [r12] */
/* @0x1ce5f4 ldr r12, [sp, #0x40] */
/* @0x1ce5f8 ldr r1, [r12, r1] */
/* @0x1ce5fc str r1, [sp, #0x48] */
/* @0x1ce600 ldr r1, [r1, r8] */
/* @0x1ce604 cmp r1, #0 */
/* @0x1ce608 ble 0x1d0044 <_Z11HandleOtherv+0x1ab0> */
/* @0x1ce60c ldr r3, [pc, #0x618] */
/* @0x1ce610 mov r5, #0 */
/* @0x1ce614 ldr r2, [pc, #0x61c] */
/* @0x1ce618 movw r9, #0x3804 */
/* @0x1ce61c ldr r1, [pc, #0x618] */
/* @0x1ce620 ldr r3, [r12, r3] */
/* @0x1ce624 ldr r6, [r12, r2] */
/* @0x1ce628 ldr r11, [sp, #0x48] */
/* @0x1ce62c mov r10, r3 */
/* @0x1ce630 ldr r7, [r12, r1] */
/* @0x1ce634 str r3, [sp, #0x3c] */
/* @0x1ce638 str r6, [sp, #0x18] */
/* @0x1ce63c ldr r12, [sp, #0x18] */
/* @0x1ce640 ldr r3, [r7] */
/* @0x1ce644 ldr r1, [r12, r9] */
/* @0x1ce648 ldr r2, [r3, #0x4] */
/* @0x1ce64c ldr r3, [r3] */
/* @0x1ce650 ldr r1, [r1, r5, lsl #2] */
/* @0x1ce654 and r2, r1, r2 */
/* @0x1ce658 ldr r3, [r3, r2, lsl #3] */
/* @0x1ce65c cmp r3, #0 */
/* @0x1ce660 bne 0x1ce674 <_Z11HandleOtherv+0xe0> */
/* @0x1ce664 b 0x1ce768 <_Z11HandleOtherv+0x1d4> */
/* @0x1ce668 ldr r3, [r3, #0x4] */
/* @0x1ce66c cmp r3, #0 */
/* @0x1ce670 beq 0x1ce768 <_Z11HandleOtherv+0x1d4> */
/* @0x1ce674 ldr r2, [r3, #0x8] */
/* @0x1ce678 cmp r1, r2 */
/* @0x1ce67c bne 0x1ce668 <_Z11HandleOtherv+0xd4> */
/* @0x1ce680 ldr r3, [r3, #0xc] */
/* @0x1ce684 cmp r3, #0 */
/* @0x1ce688 ldrne r4, [r3, #0xc4] */
/* @0x1ce68c beq 0x1ce768 <_Z11HandleOtherv+0x1d4> */
/* @0x1ce690 cmp r4, #0 */
/* @0x1ce694 beq 0x1ce768 <_Z11HandleOtherv+0x1d4> */
/* @0x1ce698 ldr r3, [r4, #0x8] */
/* @0x1ce69c cmp r3, #0 */
/* @0x1ce6a0 beq 0x1ce768 <_Z11HandleOtherv+0x1d4> */
/* @0x1ce6a4 ldr r6, [r4, #0x8] */
/* @0x1ce6a8 ldr r4, [r4] */
/* @0x1ce6ac ldrb r3, [r6, #0x68] */
/* @0x1ce6b0 cmp r3, #0 */
/* @0x1ce6b4 bne 0x1ce690 <_Z11HandleOtherv+0xfc> */
/* @0x1ce6b8 ldrb r3, [r6, #0x69] */
/* @0x1ce6bc cmp r3, #0 */
/* @0x1ce6c0 bne 0x1ce690 <_Z11HandleOtherv+0xfc> */
/* @0x1ce6c4 ldrd r2, r3, [r6, #112] */
/* @0x1ce6c8 ldrd r0, r1, [sp, #8] */
/* @0x1ce6cc cmp r0, r2 */
/* @0x1ce6d0 sbcs r1, r1, r3 */
/* @0x1ce6d4 blt 0x1ce690 <_Z11HandleOtherv+0xfc> */
/* @0x1ce6d8 ldr r0, [r6, #0x8c] */
/* @0x1ce6dc bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1ce6e0 cmp r0, #0 */
/* @0x1ce6e4 beq 0x1ceb90 <_Z11HandleOtherv+0x5fc> */
/* @0x1ce6e8 ldrb r3, [r6, #0x64] */
/* @0x1ce6ec cmp r3, #0 */
/* @0x1ce6f0 bne 0x1cf828 <_Z11HandleOtherv+0x1294> */
/* @0x1ce6f4 ldr r3, [r6, #0xf0] */
/* @0x1ce6f8 cmp r3, #0 */
/* @0x1ce6fc blt 0x1cebec <_Z11HandleOtherv+0x658> */
/* @0x1ce700 ldrb r3, [r6, #0x64] */
/* @0x1ce704 cmp r3, #0 */
/* @0x1ce708 bne 0x1cf990 <_Z11HandleOtherv+0x13fc> */
/* @0x1ce70c ldr r3, [r10] */
/* @0x1ce710 ldr r2, [r6, #0xe8] */
/* @0x1ce714 ldr r3, [r3, #0x10] */
/* @0x1ce718 cmp r2, r3 */
/* @0x1ce71c bgt 0x1cebec <_Z11HandleOtherv+0x658> */
/* @0x1ce720 ldrb r3, [r6, #0x64] */
/* @0x1ce724 cmp r3, #0 */
/* @0x1ce728 bne 0x1cfa60 <_Z11HandleOtherv+0x14cc> */
/* @0x1ce72c ldr r3, [r6, #0xf4] */
/* @0x1ce730 cmp r3, #0 */
/* @0x1ce734 blt 0x1cebec <_Z11HandleOtherv+0x658> */
/* @0x1ce738 ldrb r3, [r6, #0x64] */
/* @0x1ce73c cmp r3, #0 */
/* @0x1ce740 bne 0x1cfc94 <_Z11HandleOtherv+0x1700> */
/* @0x1ce744 ldr r3, [r10] */
/* @0x1ce748 ldr r2, [r6, #0xec] */
/* @0x1ce74c ldr r3, [r3, #0x14] */
/* @0x1ce750 cmp r2, r3 */
/* @0x1ce754 bgt 0x1cebec <_Z11HandleOtherv+0x658> */
/* @0x1ce758 mov r3, #0 */
/* @0x1ce75c cmp r4, #0 */
/* @0x1ce760 strb r3, [r6, #0x15e] */
/* @0x1ce764 bne 0x1ce698 <_Z11HandleOtherv+0x104> */
/* @0x1ce768 ldr r3, [r11, r8] */
/* @0x1ce76c add r5, r5, #1 */
/* @0x1ce770 cmp r3, r5 */
/* @0x1ce774 bgt 0x1ce63c <_Z11HandleOtherv+0xa8> */
/* @0x1ce778 ldr r1, [sp, #0x44] */
/* @0x1ce77c ldrd r0, r1, [r1] */
/* @0x1ce780 strd r0, r1, [sp, #8] */
/* @0x1ce784 ldr r12, [sp, #0x48] */
/* @0x1ce788 movw r8, #0x1c04 */
/* @0x1ce78c ldrd r2, r3, [sp, #8] */
/* @0x1ce790 ldr r1, [r12, r8] */
/* @0x1ce794 adds r2, r2, #1 */
/* @0x1ce798 ldr r12, [sp, #0x44] */
/* @0x1ce79c adc r3, r3, #0 */
/* @0x1ce7a0 cmp r1, #0 */
/* @0x1ce7a4 strd r2, r3, [r12] */
/* @0x1ce7a8 ble 0x1ce91c <_Z11HandleOtherv+0x388> */
/* @0x1ce7ac ldr r12, [sp, #0x40] */
/* @0x1ce7b0 mov r5, #0 */
/* @0x1ce7b4 ldr r3, [pc, #0x47c] */
/* @0x1ce7b8 movw r9, #0x380c */
/* @0x1ce7bc ldr r2, [pc, #0x478] */
/* @0x1ce7c0 ldr r10, [sp, #0x3c] */
/* @0x1ce7c4 ldr r6, [r12, r3] */
/* @0x1ce7c8 ldr r11, [sp, #0x48] */
/* @0x1ce7cc ldr r7, [r12, r2] */
/* @0x1ce7d0 str r6, [sp, #0x18] */
/* @0x1ce7d4 ldr r12, [sp, #0x18] */
/* @0x1ce7d8 ldr r3, [r7] */
/* @0x1ce7dc ldr r1, [r12, r9] */
/* @0x1ce7e0 ldr r2, [r3, #0x4] */
/* @0x1ce7e4 ldr r3, [r3] */
/* @0x1ce7e8 ldr r1, [r1, r5, lsl #2] */
/* @0x1ce7ec and r2, r1, r2 */
/* @0x1ce7f0 ldr r3, [r3, r2, lsl #3] */
/* @0x1ce7f4 cmp r3, #0 */
/* @0x1ce7f8 bne 0x1ce80c <_Z11HandleOtherv+0x278> */
/* @0x1ce7fc b 0x1ce90c <_Z11HandleOtherv+0x378> */
/* @0x1ce800 ldr r3, [r3, #0x4] */
/* @0x1ce804 cmp r3, #0 */
/* @0x1ce808 beq 0x1ce90c <_Z11HandleOtherv+0x378> */
/* @0x1ce80c ldr r2, [r3, #0x8] */
/* @0x1ce810 cmp r1, r2 */
/* @0x1ce814 bne 0x1ce800 <_Z11HandleOtherv+0x26c> */
/* @0x1ce818 ldr r3, [r3, #0xc] */
/* @0x1ce81c cmp r3, #0 */
/* @0x1ce820 ldrne r4, [r3, #0xc4] */
/* @0x1ce824 beq 0x1ce90c <_Z11HandleOtherv+0x378> */
/* @0x1ce828 cmp r4, #0 */
/* @0x1ce82c beq 0x1ce90c <_Z11HandleOtherv+0x378> */
/* @0x1ce830 ldr r3, [r4, #0x8] */
/* @0x1ce834 cmp r3, #0 */
/* @0x1ce838 beq 0x1ce90c <_Z11HandleOtherv+0x378> */
/* @0x1ce83c ldr r6, [r4, #0x8] */
/* @0x1ce840 ldr r4, [r4] */
/* @0x1ce844 ldrb r3, [r6, #0x68] */
/* @0x1ce848 cmp r3, #0 */
/* @0x1ce84c bne 0x1ce828 <_Z11HandleOtherv+0x294> */
/* @0x1ce850 ldrb r3, [r6, #0x69] */
/* @0x1ce854 cmp r3, #0 */
/* @0x1ce858 bne 0x1ce828 <_Z11HandleOtherv+0x294> */
/* @0x1ce85c ldrd r2, r3, [r6, #112] */
/* @0x1ce860 ldrd r0, r1, [sp, #8] */
/* @0x1ce864 cmp r0, r2 */
/* @0x1ce868 sbcs r1, r1, r3 */
/* @0x1ce86c blt 0x1ce828 <_Z11HandleOtherv+0x294> */
/* @0x1ce870 ldr r0, [r6, #0x8c] */
/* @0x1ce874 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1ce878 cmp r0, #0 */
/* @0x1ce87c beq 0x1cf6a8 <_Z11HandleOtherv+0x1114> */
/* @0x1ce880 ldrb r3, [r6, #0x64] */
/* @0x1ce884 cmp r3, #0 */
/* @0x1ce888 bne 0x1cf838 <_Z11HandleOtherv+0x12a4> */
/* @0x1ce88c ldr r3, [r6, #0xe8] */
/* @0x1ce890 cmp r3, #0 */
/* @0x1ce894 blt 0x1ce8f0 <_Z11HandleOtherv+0x35c> */
/* @0x1ce898 ldrb r3, [r6, #0x64] */
/* @0x1ce89c cmp r3, #0 */
/* @0x1ce8a0 bne 0x1cf9a0 <_Z11HandleOtherv+0x140c> */
/* @0x1ce8a4 ldr r3, [r10] */
/* @0x1ce8a8 ldr r2, [r6, #0xf0] */
/* @0x1ce8ac ldr r3, [r3, #0x10] */
/* @0x1ce8b0 cmp r2, r3 */
/* @0x1ce8b4 bgt 0x1ce8f0 <_Z11HandleOtherv+0x35c> */
/* @0x1ce8b8 ldrb r3, [r6, #0x64] */
/* @0x1ce8bc cmp r3, #0 */
/* @0x1ce8c0 bne 0x1cfa50 <_Z11HandleOtherv+0x14bc> */
/* @0x1ce8c4 ldr r3, [r6, #0xec] */
/* @0x1ce8c8 cmp r3, #0 */
/* @0x1ce8cc blt 0x1ce8f0 <_Z11HandleOtherv+0x35c> */
/* @0x1ce8d0 ldrb r3, [r6, #0x64] */
/* @0x1ce8d4 cmp r3, #0 */
/* @0x1ce8d8 bne 0x1cfca4 <_Z11HandleOtherv+0x1710> */
/* @0x1ce8dc ldr r3, [r10] */
/* @0x1ce8e0 ldr r2, [r6, #0xf4] */
/* @0x1ce8e4 ldr r3, [r3, #0x14] */
/* @0x1ce8e8 cmp r2, r3 */
/* @0x1ce8ec ble 0x1ce828 <_Z11HandleOtherv+0x294> */
/* @0x1ce8f0 mov r0, r6 */
/* @0x1ce8f4 mov r2, #7 */
/* @0x1ce8f8 mov r1, r6 */
/* @0x1ce8fc mov r3, #1 */
/* @0x1ce900 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1ce904 cmp r4, #0 */
/* @0x1ce908 bne 0x1ce830 <_Z11HandleOtherv+0x29c> */
/* @0x1ce90c ldr r3, [r11, r8] */
/* @0x1ce910 add r5, r5, #1 */
/* @0x1ce914 cmp r3, r5 */
/* @0x1ce918 bgt 0x1ce7d4 <_Z11HandleOtherv+0x240> */
/* @0x1ce91c vmov.f32 s16, #5.000000e-01 */
/* @0x1ce920 add r3, sp, #324 */
/* @0x1ce924 add r12, sp, #316 */
/* @0x1ce928 add r4, sp, #568 */
/* @0x1ce92c add r9, sp, #320 */
/* @0x1ce930 add r5, sp, #312 */
/* @0x1ce934 add r8, sp, #336 */
/* @0x1ce938 mov r2, #0 */
/* @0x1ce93c mov r11, r3 */
/* @0x1ce940 str r12, [sp, #0x34] */
/* @0x1ce944 mov r6, r2 */
/* @0x1ce948 str r2, [sp, #0x58] */
/* @0x1ce94c str r2, [sp, #0x5c] */
/* @0x1ce950 mov r7, r2 */
/* @0x1ce954 str r2, [sp, #0x60] */
/* @0x1ce958 mov r10, r12 */
/* @0x1ce95c str r2, [sp, #0x64] */
/* @0x1ce960 add r12, sp, #88 */
/* @0x1ce964 str r2, [sp, #0x68] */
/* @0x1ce968 vldr s17, [pc, #676] */
/* @0x1ce96c vmov.f32 s18, #-1.000000e+00 */
/* @0x1ce970 str r2, [sp, #0x6c] */
/* @0x1ce974 str r2, [sp, #0x70] */
/* @0x1ce978 vldr s19, [pc, #664] */
/* @0x1ce97c str r2, [sp, #0x74] */
/* @0x1ce980 add r2, sp, #248 */
/* @0x1ce984 str r12, [sp, #0x4c] */
/* @0x1ce988 str r2, [sp, #0x10] */
/* @0x1ce98c ldr r12, [sp, #0x3c] */
/* @0x1ce990 ldr r1, [r12] */
/* @0x1ce994 ldrb r0, [r1, #0x44] */
/* @0x1ce998 cmp r0, #0 */
/* @0x1ce99c beq 0x1ced9c <_Z11HandleOtherv+0x808> */
/* @0x1ce9a0 add r12, r7, #18 */
/* @0x1ce9a4 ldr r1, [r1, r12, lsl #2] */
/* @0x1ce9a8 ldrb r0, [r1] */
/* @0x1ce9ac cmp r0, #0 */
/* @0x1ce9b0 beq 0x1ced9c <_Z11HandleOtherv+0x808> */
/* @0x1ce9b4 ldr r0, [pc, #0x274] */
/* @0x1ce9b8 ldr r2, [sp, #0x40] */
/* @0x1ce9bc ldr r0, [r2, r0] */
/* @0x1ce9c0 ldrb r0, [r0] */
/* @0x1ce9c4 cmp r0, #0 */
/* @0x1ce9c8 beq 0x1cec40 <_Z11HandleOtherv+0x6ac> */
/* @0x1ce9cc ldr r12, [sp, #0x40] */
/* @0x1ce9d0 ldr r0, [pc, #0x25c] */
/* @0x1ce9d4 ldr r1, [r1, #0x40] */
/* @0x1ce9d8 ldr r0, [r12, r0] */
/* @0x1ce9dc bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> */
/* @0x1ce9e0 subs r1, r0, #0 */
/* @0x1ce9e4 beq 0x1cfe24 <_Z11HandleOtherv+0x1890> */
/* @0x1ce9e8 str r1, [sp, #0x4] */
/* @0x1ce9ec bl 0x16d378 <_ZN7CCamera11IsViewDirtyEv> */
/* @0x1ce9f0 ldr r1, [sp, #0x4] */
/* @0x1ce9f4 cmp r0, #0 */
/* @0x1ce9f8 beq 0x1cea0c <_Z11HandleOtherv+0x478> */
/* @0x1ce9fc mov r0, r1 */
/* @0x1cea00 str r1, [sp, #0x4] */
/* @0x1cea04 bl 0x170b30 <_ZN7CCamera12CameraUpdateEv> */
/* @0x1cea08 ldr r1, [sp, #0x4] */
/* @0x1cea0c add r0, sp, #248 */
/* @0x1cea10 bl 0x16d260 <_ZN7CCamera17GetInvViewProjMatEv> */
/* @0x1cea14 vldr s5, [sp, #248] */
/* @0x1cea18 vldr s6, [sp, #264] */
/* @0x1cea1c vldr s10, [sp, #252] */
/* @0x1cea20 vsub.f32 s12, s6, s5 */
/* @0x1cea24 vldr s7, [sp, #268] */
/* @0x1cea28 vldr s8, [sp, #296] */
/* @0x1cea2c vldr s9, [sp, #300] */
/* @0x1cea30 vadd.f32 s14, s6, s5 */
/* @0x1cea34 vneg.f32 s4, s10 */
/* @0x1cea38 vneg.f32 s11, s5 */
/* @0x1cea3c vsub.f32 s13, s7, s10 */
/* @0x1cea40 vadd.f32 s15, s7, s10 */
/* @0x1cea44 vsub.f32 s11, s11, s6 */
/* @0x1cea48 vsub.f32 s10, s10, s7 */
/* @0x1cea4c vsub.f32 s6, s5, s6 */
/* @0x1cea50 vsub.f32 s7, s4, s7 */
/* @0x1cea54 vadd.f32 s12, s12, s8 */
/* @0x1cea58 vadd.f32 s14, s14, s8 */
/* @0x1cea5c vstr s12, [r5] */
/* @0x1cea60 vadd.f32 s13, s13, s9 */
/* @0x1cea64 vadd.f32 s15, s15, s9 */
/* @0x1cea68 vstr s13, [r10] */
/* @0x1cea6c vstr s14, [r9] */
/* @0x1cea70 vadd.f32 s11, s11, s8 */
/* @0x1cea74 vstr s15, [r11] */
/* @0x1cea78 vadd.f32 s10, s10, s9 */
/* @0x1cea7c vadd.f32 s8, s6, s8 */
/* @0x1cea80 vstr s10, [r5, #20] */
/* @0x1cea84 vadd.f32 s9, s7, s9 */
/* @0x1cea88 vstr s8, [r5, #16] */
/* @0x1cea8c vstr s11, [r8] */
/* @0x1cea90 vcmpe.f32 s12, s14 */
/* @0x1cea94 vstr s9, [r5, #28] */
/* @0x1cea98 vmrs APSR_nzcv, fpscr */
/* @0x1cea9c bpl 0x1cf9e8 <_Z11HandleOtherv+0x1454> */
/* @0x1ceaa0 vcmpe.f32 s12, s11 */
/* @0x1ceaa4 vmrs APSR_nzcv, fpscr */
/* @0x1ceaa8 bpl 0x1cfccc <_Z11HandleOtherv+0x1738> */
/* @0x1ceaac vcmpe.f32 s12, s8 */
/* @0x1ceab0 vmrs APSR_nzcv, fpscr */
/* @0x1ceab4 bmi 0x1cfa1c <_Z11HandleOtherv+0x1488> */
/* @0x1ceab8 vcvt.s32.f32 s7, s8 */
/* @0x1ceabc vmov r0, s7 */
/* @0x1ceac0 add r1, sp, #120 */
/* @0x1ceac4 vcmpe.f32 s13, s15 */
/* @0x1ceac8 vmrs APSR_nzcv, fpscr */
/* @0x1ceacc str r0, [r6, r1] */
/* @0x1cead0 bpl 0x1cfcd4 <_Z11HandleOtherv+0x1740> */
/* @0x1cead4 vcmpe.f32 s13, s9 */
/* @0x1cead8 vmrs APSR_nzcv, fpscr */
/* @0x1ceadc bpl 0x1cfe1c <_Z11HandleOtherv+0x1888> */
/* @0x1ceae0 vcmpe.f32 s13, s10 */
/* @0x1ceae4 vmrs APSR_nzcv, fpscr */
/* @0x1ceae8 bmi 0x1cfd08 <_Z11HandleOtherv+0x1774> */
/* @0x1ceaec vcvt.s32.f32 s7, s10 */
/* @0x1ceaf0 vmov r2, s7 */
/* @0x1ceaf4 add r1, sp, #152 */
/* @0x1ceaf8 vcmpe.f32 s12, s14 */
/* @0x1ceafc vmrs APSR_nzcv, fpscr */
/* @0x1ceb00 str r2, [r6, r1] */
/* @0x1ceb04 ble 0x1cfd3c <_Z11HandleOtherv+0x17a8> */
/* @0x1ceb08 vcmpe.f32 s12, s11 */
/* @0x1ceb0c vmrs APSR_nzcv, fpscr */
/* @0x1ceb10 ble 0x1cfe0c <_Z11HandleOtherv+0x1878> */
/* @0x1ceb14 vcmpe.f32 s12, s8 */
/* @0x1ceb18 vmrs APSR_nzcv, fpscr */
/* @0x1ceb1c bgt 0x1cfd70 <_Z11HandleOtherv+0x17dc> */
/* @0x1ceb20 vcvt.s32.f32 s14, s8 */
/* @0x1ceb24 vmov r3, s14 */
/* @0x1ceb28 add r1, sp, #184 */
/* @0x1ceb2c vcmpe.f32 s13, s15 */
/* @0x1ceb30 vmrs APSR_nzcv, fpscr */
/* @0x1ceb34 str r3, [r6, r1] */
/* @0x1ceb38 ble 0x1cfda4 <_Z11HandleOtherv+0x1810> */
/* @0x1ceb3c vcmpe.f32 s13, s9 */
/* @0x1ceb40 vmrs APSR_nzcv, fpscr */
/* @0x1ceb44 ble 0x1cfe14 <_Z11HandleOtherv+0x1880> */
/* @0x1ceb48 vcmpe.f32 s13, s10 */
/* @0x1ceb4c vmrs APSR_nzcv, fpscr */
/* @0x1ceb50 bgt 0x1cfdd8 <_Z11HandleOtherv+0x1844> */
/* @0x1ceb54 vcvt.s32.f32 s13, s10 */
/* @0x1ceb58 vmov r12, s13 */
/* @0x1ceb5c add r1, sp, #216 */
/* @0x1ceb60 add r0, sp, #88 */
/* @0x1ceb64 vldr s15, [r9] */
/* @0x1ceb68 vldr s14, [r5] */
/* @0x1ceb6c vldr s13, [r11] */
/* @0x1ceb70 str r12, [r6, r1] */
/* @0x1ceb74 add r1, r0, r6 */
/* @0x1ceb78 vstr s18, [r1] */
/* @0x1ceb7c vldr s12, [r10] */
/* @0x1ceb80 vldr s11, [r5, #16] */
/* @0x1ceb84 vldr s10, [r5, #20] */
/* @0x1ceb88 vldr s8, [r8] */
/* @0x1ceb8c b 0x1ced5c <_Z11HandleOtherv+0x7c8> */
/* @0x1ceb90 ldr r0, [r6, #0xac] */
/* @0x1ceb94 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1ceb98 cmp r0, #0 */
/* @0x1ceb9c bne 0x1ce6e8 <_Z11HandleOtherv+0x154> */
/* @0x1ceba0 vldr s14, [r6, #180] */
/* @0x1ceba4 vcmpe.f32 s14, #0 */
/* @0x1ceba8 vmrs APSR_nzcv, fpscr */
/* @0x1cebac bmi 0x1cebec <_Z11HandleOtherv+0x658> */
/* @0x1cebb0 ldr r3, [r10] */
/* @0x1cebb4 vldr s12, [r3, #16] */
/* @0x1cebb8 vcvt.f32.s32 s15, s12 */
/* @0x1cebbc vcmpe.f32 s14, s15 */
/* @0x1cebc0 vmrs APSR_nzcv, fpscr */
/* @0x1cebc4 bgt 0x1cebec <_Z11HandleOtherv+0x658> */
/* @0x1cebc8 vldr s15, [r6, #184] */
/* @0x1cebcc vcmpe.f32 s15, #0 */
/* @0x1cebd0 vmrs APSR_nzcv, fpscr */
/* @0x1cebd4 bmi 0x1cebec <_Z11HandleOtherv+0x658> */
/* @0x1cebd8 vldr s14, [r3, #20] */
/* @0x1cebdc vcvt.f32.s32 s14, s14 */
/* @0x1cebe0 vcmpe.f32 s15, s14 */
/* @0x1cebe4 vmrs APSR_nzcv, fpscr */
/* @0x1cebe8 ble 0x1ce758 <_Z11HandleOtherv+0x1c4> */
/* @0x1cebec ldrb r3, [r6, #0x15e] */
/* @0x1cebf0 cmp r3, #0 */
/* @0x1cebf4 movne r3, #1 */
/* @0x1cebf8 bne 0x1ce75c <_Z11HandleOtherv+0x1c8> */
/* @0x1cebfc mov r0, r6 */
/* @0x1cec00 mov r1, r6 */
/* @0x1cec04 mov r2, #7 */
/* @0x1cec08 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1cec0c mov r3, #1 */
/* @0x1cec10 b 0x1ce75c <_Z11HandleOtherv+0x1c8> */
/* @0x1cec14 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x1cec18 vstmialo lr, {s30, s31} */
/* @0x1cec1c eoreq r3, r2, r12, lsr #13 */
/* @0x1cec20 .word 0xffffbf18 */
/* @0x1cec24 .word 0xffffdeb4 */
/* @0x1cec28 .word 0xffffdeb8 */
/* @0x1cec2c .word 0xffffbcd8 */
/* @0x1cec30 .word 0xffffbcd4 */
/* @0x1cec34 .word 0xffffc024 */
/* @0x1cec38 .word 0xffffdebc */
/* @0x1cec3c .word 0xffffbfec */
/* @0x1cec40 vldr s15, [r1, #36] */
/* @0x1cec44 vcmpe.f32 s15, s17 */
/* @0x1cec48 vmrs APSR_nzcv, fpscr */
/* @0x1cec4c bhi 0x1cfa70 <_Z11HandleOtherv+0x14dc> */
/* @0x1cec50 vldr s15, [r1, #4] */
/* @0x1cec54 vcvt.f64.f32 d6, s15 */
/* @0x1cec58 str r12, [sp] */
/* @0x1cec5c vmov r0, r1, d6 */
/* @0x1cec60 bl 0xb66e8 <lrint@plt> */
/* @0x1cec64 ldr r12, [sp] */
/* @0x1cec68 vmov s22, r0 */
/* @0x1cec6c ldr r0, [sp, #0x3c] */
/* @0x1cec70 vmov r2, s22 */
/* @0x1cec74 ldr r1, [r0] */
/* @0x1cec78 add r0, sp, #120 */
/* @0x1cec7c ldr r1, [r1, r12, lsl #2] */
/* @0x1cec80 vldr s15, [r1, #8] */
/* @0x1cec84 vcvt.f64.f32 d6, s15 */
/* @0x1cec88 str r2, [r6, r0] */
/* @0x1cec8c vmov r0, r1, d6 */
/* @0x1cec90 bl 0xb66e8 <lrint@plt> */
/* @0x1cec94 ldr r12, [sp] */
/* @0x1cec98 add lr, sp, #152 */
/* @0x1cec9c vmov s21, r0 */
/* @0x1ceca0 ldr r0, [sp, #0x3c] */
/* @0x1ceca4 vmov r2, s21 */
/* @0x1ceca8 ldr r1, [r0] */
/* @0x1cecac ldr r1, [r1, r12, lsl #2] */
/* @0x1cecb0 vldr s14, [r1, #4] */
/* @0x1cecb4 vldr s15, [r1, #12] */
/* @0x1cecb8 vadd.f32 s15, s14, s15 */
/* @0x1cecbc vcvt.f64.f32 d6, s15 */
/* @0x1cecc0 str r2, [r6, lr] */
/* @0x1cecc4 vmov r0, r1, d6 */
/* @0x1cecc8 bl 0xb66e8 <lrint@plt> */
/* @0x1ceccc ldr r12, [sp] */
/* @0x1cecd0 add lr, sp, #184 */
/* @0x1cecd4 vmov s20, r0 */
/* @0x1cecd8 ldr r0, [sp, #0x3c] */
/* @0x1cecdc vmov r2, s20 */
/* @0x1cece0 ldr r1, [r0] */
/* @0x1cece4 ldr r1, [r1, r12, lsl #2] */
/* @0x1cece8 vldr s14, [r1, #8] */
/* @0x1cecec vldr s15, [r1, #16] */
/* @0x1cecf0 vadd.f32 s15, s14, s15 */
/* @0x1cecf4 vcvt.f64.f32 d6, s15 */
/* @0x1cecf8 str r2, [r6, lr] */
/* @0x1cecfc vmov r0, r1, d6 */
/* @0x1ced00 bl 0xb66e8 <lrint@plt> */
/* @0x1ced04 add r1, sp, #216 */
/* @0x1ced08 vcvt.f32.s32 s22, s22 */
/* @0x1ced0c vcvt.f32.s32 s21, s21 */
/* @0x1ced10 vstr s22, [r5] */
/* @0x1ced14 vcvt.f32.s32 s20, s20 */
/* @0x1ced18 vstr s21, [r10] */
/* @0x1ced1c vstr s20, [r9] */
/* @0x1ced20 vstr s21, [r11] */
/* @0x1ced24 vstr s20, [r5, #16] */
/* @0x1ced28 vmov s13, r0 */
/* @0x1ced2c str r0, [r6, r1] */
/* @0x1ced30 vcvt.f32.s32 s9, s13 */
/* @0x1ced34 vstr s9, [r5, #20] */
/* @0x1ced38 vstr s22, [r8] */
/* @0x1ced3c vstr s9, [r5, #28] */
/* @0x1ced40 vldr s14, [r5] */
/* @0x1ced44 vldr s15, [r9] */
/* @0x1ced48 vldr s13, [r11] */
/* @0x1ced4c vldr s12, [r10] */
/* @0x1ced50 vldr s11, [r5, #16] */
/* @0x1ced54 vldr s10, [r5, #20] */
/* @0x1ced58 vldr s8, [r8] */
/* @0x1ced5c vsub.f32 s7, s15, s14 */
/* @0x1ced60 vsub.f32 s15, s11, s15 */
/* @0x1ced64 vstr s7, [r4] */
/* @0x1ced68 vsub.f32 s11, s8, s11 */
/* @0x1ced6c vstr s15, [r4, #8] */
/* @0x1ced70 vsub.f32 s14, s14, s8 */
/* @0x1ced74 vstr s11, [r4, #16] */
/* @0x1ced78 vsub.f32 s15, s13, s12 */
/* @0x1ced7c vstr s14, [r4, #24] */
/* @0x1ced80 vsub.f32 s13, s10, s13 */
/* @0x1ced84 vstr s15, [r4, #4] */
/* @0x1ced88 vsub.f32 s10, s9, s10 */
/* @0x1ced8c vstr s13, [r4, #12] */
/* @0x1ced90 vsub.f32 s12, s12, s9 */
/* @0x1ced94 vstr s10, [r4, #20] */
/* @0x1ced98 vstr s12, [r4, #28] */
/* @0x1ced9c add r7, r7, #1 */
/* @0x1ceda0 add r4, r4, #32 */
/* @0x1ceda4 cmp r7, #8 */
/* @0x1ceda8 add r6, r6, #4 */
/* @0x1cedac add r9, r9, #32 */
/* @0x1cedb0 add r5, r5, #32 */
/* @0x1cedb4 add r11, r11, #32 */
/* @0x1cedb8 add r10, r10, #32 */
/* @0x1cedbc add r8, r8, #32 */
/* @0x1cedc0 bne 0x1ce98c <_Z11HandleOtherv+0x3f8> */
/* @0x1cedc4 ldr r1, [sp, #0x44] */
/* @0x1cedc8 add r12, sp, #572 */
/* @0x1cedcc str r12, [sp, #0x38] */
/* @0x1cedd0 add r12, sp, #256 */
/* @0x1cedd4 str r12, [sp, #0x18] */
/* @0x1cedd8 add r12, sp, #572 */
/* @0x1ceddc ldrd r0, r1, [r1] */
/* @0x1cede0 add r6, sp, #288 */
/* @0x1cede4 str r12, [sp, #0x24] */
/* @0x1cede8 add r12, sp, #88 */
/* @0x1cedec str r12, [sp, #0x30] */
/* @0x1cedf0 adds r2, r0, #1 */
/* @0x1cedf4 ldr r12, [sp, #0x44] */
/* @0x1cedf8 mov r7, #0 */
/* @0x1cedfc adc r3, r1, #0 */
/* @0x1cee00 strd r0, r1, [sp, #16] */
/* @0x1cee04 str r7, [sp, #0x20] */
/* @0x1cee08 strd r2, r3, [r12] */
/* @0x1cee0c add r12, sp, #316 */
/* @0x1cee10 str r12, [sp, #0x28] */
/* @0x1cee14 ldr r12, [sp, #0x3c] */
/* @0x1cee18 ldr r3, [r12] */
/* @0x1cee1c ldrb r2, [r3, #0x44] */
/* @0x1cee20 cmp r2, #0 */
/* @0x1cee24 beq 0x1cf0bc <_Z11HandleOtherv+0xb28> */
/* @0x1cee28 ldr r12, [sp, #0x20] */
/* @0x1cee2c add r2, r12, #18 */
/* @0x1cee30 ldr r3, [r3, r2, lsl #2] */
/* @0x1cee34 ldrb r3, [r3] */
/* @0x1cee38 cmp r3, #0 */
/* @0x1cee3c beq 0x1cf0bc <_Z11HandleOtherv+0xb28> */
/* @0x1cee40 ldr r12, [sp, #0x48] */
/* @0x1cee44 add r3, r12, r7 */
/* @0x1cee48 ldr r12, [sp, #0x20] */
/* @0x1cee4c add r3, r3, #7296 */
/* @0x1cee50 add r8, r12, #40 */
/* @0x1cee54 add r12, r3, #32 */
/* @0x1cee58 ldr r0, [r3, #0x20] */
/* @0x1cee5c str r12, [sp, #0x2c] */
/* @0x1cee60 cmp r0, #0 */
/* @0x1cee64 ble 0x1cf0bc <_Z11HandleOtherv+0xb28> */
/* @0x1cee68 ldr r12, [sp, #0x40] */
/* @0x1cee6c mov r5, #0 */
/* @0x1cee70 ldr r2, [pc, #-0x240] */
/* @0x1cee74 ldr r3, [pc, #-0x240] */
/* @0x1cee78 ldr r10, [r12, r2] */
/* @0x1cee7c ldr r11, [r12, r3] */
/* @0x1cee80 ldr r12, [sp, #0x20] */
/* @0x1cee84 add r10, r10, r12, lsl #3 */
/* @0x1cee88 add r10, r10, #14656 */
/* @0x1cee8c add r10, r10, #4 */
/* @0x1cee90 ldr r3, [r11] */
/* @0x1cee94 ldr r1, [r10] */
/* @0x1cee98 ldr r2, [r3, #0x4] */
/* @0x1cee9c ldr r1, [r1, r5, lsl #2] */
/* @0x1ceea0 ldr r3, [r3] */
/* @0x1ceea4 and r2, r1, r2 */
/* @0x1ceea8 ldr r3, [r3, r2, lsl #3] */
/* @0x1ceeac cmp r3, #0 */
/* @0x1ceeb0 bne 0x1ceec4 <_Z11HandleOtherv+0x930> */
/* @0x1ceeb4 b 0x1cf0b0 <_Z11HandleOtherv+0xb1c> */
/* @0x1ceeb8 ldr r3, [r3, #0x4] */
/* @0x1ceebc cmp r3, #0 */
/* @0x1ceec0 beq 0x1cf0b0 <_Z11HandleOtherv+0xb1c> */
/* @0x1ceec4 ldr r2, [r3, #0x8] */
/* @0x1ceec8 cmp r1, r2 */
/* @0x1ceecc bne 0x1ceeb8 <_Z11HandleOtherv+0x924> */
/* @0x1ceed0 ldr r3, [r3, #0xc] */
/* @0x1ceed4 cmp r3, #0 */
/* @0x1ceed8 beq 0x1cf0b0 <_Z11HandleOtherv+0xb1c> */
/* @0x1ceedc ldr r4, [r3, #0xc4] */
/* @0x1ceee0 cmp r4, #0 */
/* @0x1ceee4 beq 0x1cf0b0 <_Z11HandleOtherv+0xb1c> */
/* @0x1ceee8 ldr r3, [r4, #0x8] */
/* @0x1ceeec cmp r3, #0 */
/* @0x1ceef0 beq 0x1cf0b0 <_Z11HandleOtherv+0xb1c> */
/* @0x1ceef4 ldr r9, [r4, #0x8] */
/* @0x1ceef8 ldr r4, [r4] */
/* @0x1ceefc ldrb r3, [r9, #0x68] */
/* @0x1cef00 cmp r3, #0 */
/* @0x1cef04 bne 0x1cf094 <_Z11HandleOtherv+0xb00> */
/* @0x1cef08 ldrb r3, [r9, #0x69] */
/* @0x1cef0c cmp r3, #0 */
/* @0x1cef10 bne 0x1cf094 <_Z11HandleOtherv+0xb00> */
/* @0x1cef14 ldrd r2, r3, [r9, #112] */
/* @0x1cef18 ldrd r0, r1, [sp, #16] */
/* @0x1cef1c cmp r0, r2 */
/* @0x1cef20 sbcs r1, r1, r3 */
/* @0x1cef24 blt 0x1cf094 <_Z11HandleOtherv+0xb00> */
/* @0x1cef28 ldr r0, [r9, #0x8c] */
/* @0x1cef2c bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1cef30 cmp r0, #0 */
/* @0x1cef34 beq 0x1cf41c <_Z11HandleOtherv+0xe88> */
/* @0x1cef38 ldrb r3, [r9, #0x64] */
/* @0x1cef3c cmp r3, #0 */
/* @0x1cef40 bne 0x1cf534 <_Z11HandleOtherv+0xfa0> */
/* @0x1cef44 add r3, sp, #120 */
/* @0x1cef48 ldr r2, [r9, #0xf0] */
/* @0x1cef4c ldr r3, [r7, r3] */
/* @0x1cef50 cmp r2, r3 */
/* @0x1cef54 blt 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cef58 ldrb r3, [r9, #0x64] */
/* @0x1cef5c cmp r3, #0 */
/* @0x1cef60 bne 0x1cf698 <_Z11HandleOtherv+0x1104> */
/* @0x1cef64 add r3, sp, #184 */
/* @0x1cef68 ldr r2, [r9, #0xe8] */
/* @0x1cef6c ldr r3, [r7, r3] */
/* @0x1cef70 cmp r2, r3 */
/* @0x1cef74 bgt 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cef78 ldrb r3, [r9, #0x64] */
/* @0x1cef7c cmp r3, #0 */
/* @0x1cef80 bne 0x1cf958 <_Z11HandleOtherv+0x13c4> */
/* @0x1cef84 add r3, sp, #152 */
/* @0x1cef88 ldr r2, [r9, #0xf4] */
/* @0x1cef8c ldr r3, [r7, r3] */
/* @0x1cef90 cmp r2, r3 */
/* @0x1cef94 blt 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cef98 ldrb r3, [r9, #0x64] */
/* @0x1cef9c cmp r3, #0 */
/* @0x1cefa0 bne 0x1cf9d8 <_Z11HandleOtherv+0x1444> */
/* @0x1cefa4 vldr s13, [r9, #236] */
/* @0x1cefa8 vmov r2, s13 */
/* @0x1cefac add r3, sp, #216 */
/* @0x1cefb0 ldr r3, [r7, r3] */
/* @0x1cefb4 cmp r2, r3 */
/* @0x1cefb8 bgt 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cefbc ldr r12, [sp, #0x30] */
/* @0x1cefc0 vldr s15, [r12] */
/* @0x1cefc4 vcmp.f32 s15, #0 */
/* @0x1cefc8 vmrs APSR_nzcv, fpscr */
/* @0x1cefcc beq 0x1cf094 <_Z11HandleOtherv+0xb00> */
/* @0x1cefd0 ldrb r3, [r9, #0x64] */
/* @0x1cefd4 cmp r3, #0 */
/* @0x1cefd8 bne 0x1cf708 <_Z11HandleOtherv+0x1174> */
/* @0x1cefdc vldr s14, [r9, #232] */
/* @0x1cefe0 vcvt.f32.s32 s16, s14 */
/* @0x1cefe4 vstr s16, [sp, #248] */
/* @0x1cefe8 vcvt.f32.s32 s17, s13 */
/* @0x1cefec vstr s17, [sp, #252] */
/* @0x1ceff0 vldr s15, [r9, #240] */
/* @0x1ceff4 vcvt.f32.s32 s12, s15 */
/* @0x1ceff8 vstr s12, [sp, #256] */
/* @0x1ceffc vcvt.f32.s32 s13, s13 */
/* @0x1cf000 vstr s13, [sp, #260] */
/* @0x1cf004 vcvt.f32.s32 s15, s15 */
/* @0x1cf008 vstr s15, [sp, #264] */
/* @0x1cf00c vldr s15, [r9, #244] */
/* @0x1cf010 vcvt.f32.s32 s13, s15 */
/* @0x1cf014 vstr s13, [sp, #268] */
/* @0x1cf018 vcvt.f32.s32 s14, s14 */
/* @0x1cf01c vstr s14, [sp, #272] */
/* @0x1cf020 vcvt.f32.s32 s15, s15 */
/* @0x1cf024 ldr r1, [sp, #0x24] */
/* @0x1cf028 ldr r2, [sp, #0x28] */
/* @0x1cf02c mov r0, #4 */
/* @0x1cf030 vstr s15, [sp, #276] */
/* @0x1cf034 vmov.f32 s14, s17 */
/* @0x1cf038 add r3, sp, #256 */
/* @0x1cf03c vldr s10, [r2, #-4] */
/* @0x1cf040 vldr s11, [r2] */
/* @0x1cf044 vldr s12, [r1, #-4] */
/* @0x1cf048 vldr s13, [r1] */
/* @0x1cf04c vmov.f32 s15, s16 */
/* @0x1cf050 add r3, r3, #8 */
/* @0x1cf054 vsub.f32 s15, s15, s10 */
/* @0x1cf058 vmul.f32 s15, s15, s13 */
/* @0x1cf05c vsub.f32 s14, s14, s11 */
/* @0x1cf060 vnmls.f32 s15, s14, s12 */
/* @0x1cf064 vcmpe.f32 s15, #0 */
/* @0x1cf068 vmrs APSR_nzcv, fpscr */
/* @0x1cf06c bmi 0x1cf674 <_Z11HandleOtherv+0x10e0> */
/* @0x1cf070 cmp r3, r6 */
/* @0x1cf074 vldrne s15, [r3, #-8] */
/* @0x1cf078 vldrne s14, [r3, #-4] */
/* @0x1cf07c bne 0x1cf050 <_Z11HandleOtherv+0xabc> */
/* @0x1cf080 mov r0, r9 */
/* @0x1cf084 mov r2, #7 */
/* @0x1cf088 mov r1, r9 */
/* @0x1cf08c mov r3, r8 */
/* @0x1cf090 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1cf094 cmp r4, #0 */
/* @0x1cf098 beq 0x1cf0a8 <_Z11HandleOtherv+0xb14> */
/* @0x1cf09c ldr r3, [r4, #0x8] */
/* @0x1cf0a0 cmp r3, #0 */
/* @0x1cf0a4 bne 0x1ceef4 <_Z11HandleOtherv+0x960> */
/* @0x1cf0a8 ldr r12, [sp, #0x2c] */
/* @0x1cf0ac ldr r0, [r12] */
/* @0x1cf0b0 add r5, r5, #1 */
/* @0x1cf0b4 cmp r0, r5 */
/* @0x1cf0b8 bgt 0x1cee90 <_Z11HandleOtherv+0x8fc> */
/* @0x1cf0bc ldr r12, [sp, #0x20] */
/* @0x1cf0c0 add r7, r7, #4 */
/* @0x1cf0c4 add r12, r12, #1 */
/* @0x1cf0c8 str r12, [sp, #0x20] */
/* @0x1cf0cc cmp r12, #8 */
/* @0x1cf0d0 ldr r12, [sp, #0x28] */
/* @0x1cf0d4 add r12, r12, #32 */
/* @0x1cf0d8 str r12, [sp, #0x28] */
/* @0x1cf0dc ldr r12, [sp, #0x24] */
/* @0x1cf0e0 add r12, r12, #32 */
/* @0x1cf0e4 str r12, [sp, #0x24] */
/* @0x1cf0e8 ldr r12, [sp, #0x30] */
/* @0x1cf0ec add r12, r12, #4 */
/* @0x1cf0f0 str r12, [sp, #0x30] */
/* @0x1cf0f4 bne 0x1cee14 <_Z11HandleOtherv+0x880> */
/* @0x1cf0f8 ldr r1, [sp, #0x44] */
/* @0x1cf0fc add r12, sp, #256 */
/* @0x1cf100 str r12, [sp, #0x28] */
/* @0x1cf104 add r12, sp, #572 */
/* @0x1cf108 str r12, [sp, #0x38] */
/* @0x1cf10c add r12, sp, #316 */
/* @0x1cf110 ldrd r0, r1, [r1] */
/* @0x1cf114 mov r8, #0 */
/* @0x1cf118 str r12, [sp, #0x34] */
/* @0x1cf11c add r11, sp, #288 */
/* @0x1cf120 ldr r12, [sp, #0x44] */
/* @0x1cf124 adds r2, r0, #1 */
/* @0x1cf128 mov r10, r8 */
/* @0x1cf12c adc r3, r1, #0 */
/* @0x1cf130 strd r0, r1, [sp, #24] */
/* @0x1cf134 strd r2, r3, [r12] */
/* @0x1cf138 str r8, [sp, #0x2c] */
/* @0x1cf13c ldr r12, [sp, #0x3c] */
/* @0x1cf140 ldr r3, [r12] */
/* @0x1cf144 ldrb r2, [r3, #0x44] */
/* @0x1cf148 cmp r2, #0 */
/* @0x1cf14c beq 0x1cf3d0 <_Z11HandleOtherv+0xe3c> */
/* @0x1cf150 ldr r12, [sp, #0x2c] */
/* @0x1cf154 add r2, r12, #18 */
/* @0x1cf158 ldr r3, [r3, r2, lsl #2] */
/* @0x1cf15c ldrb r7, [r3] */
/* @0x1cf160 cmp r7, #0 */
/* @0x1cf164 beq 0x1cf3d0 <_Z11HandleOtherv+0xe3c> */
/* @0x1cf168 ldr r12, [sp, #0x48] */
/* @0x1cf16c add r3, r12, r10 */
/* @0x1cf170 ldr r12, [sp, #0x2c] */
/* @0x1cf174 add r3, r3, #7360 */
/* @0x1cf178 add r12, r12, #50 */
/* @0x1cf17c str r12, [sp, #0x44] */
/* @0x1cf180 ldr r0, [r3, #0x8] */
/* @0x1cf184 add r12, r3, #8 */
/* @0x1cf188 str r12, [sp, #0x30] */
/* @0x1cf18c cmp r0, #0 */
/* @0x1cf190 ble 0x1cf3d0 <_Z11HandleOtherv+0xe3c> */
/* @0x1cf194 add r12, sp, #88 */
/* @0x1cf198 ldr r3, [pc, #-0x568] */
/* @0x1cf19c add r12, r12, r10 */
/* @0x1cf1a0 ldr r2, [pc, #-0x56c] */
/* @0x1cf1a4 str r12, [sp, #0x50] */
/* @0x1cf1a8 mov r6, #0 */
/* @0x1cf1ac ldr r12, [sp, #0x40] */
/* @0x1cf1b0 ldr r3, [r12, r3] */
/* @0x1cf1b4 ldr r2, [r12, r2] */
/* @0x1cf1b8 ldr r12, [sp, #0x2c] */
/* @0x1cf1bc str r10, [sp, #0x8] */
/* @0x1cf1c0 str r2, [sp, #0x24] */
/* @0x1cf1c4 add r3, r3, r12, lsl #3 */
/* @0x1cf1c8 add r3, r3, #14720 */
/* @0x1cf1cc add r3, r3, #20 */
/* @0x1cf1d0 str r3, [sp, #0x20] */
/* @0x1cf1d4 ldr r12, [sp, #0x24] */
/* @0x1cf1d8 ldr r3, [r12] */
/* @0x1cf1dc ldr r12, [sp, #0x20] */
/* @0x1cf1e0 ldr r2, [r3, #0x4] */
/* @0x1cf1e4 ldr r1, [r12] */
/* @0x1cf1e8 ldr r3, [r3] */
/* @0x1cf1ec ldr r1, [r1, r6, lsl #2] */
/* @0x1cf1f0 and r2, r1, r2 */
/* @0x1cf1f4 ldr r3, [r3, r2, lsl #3] */
/* @0x1cf1f8 cmp r3, #0 */
/* @0x1cf1fc bne 0x1cf210 <_Z11HandleOtherv+0xc7c> */
/* @0x1cf200 b 0x1cf3c0 <_Z11HandleOtherv+0xe2c> */
/* @0x1cf204 ldr r3, [r3, #0x4] */
/* @0x1cf208 cmp r3, #0 */
/* @0x1cf20c beq 0x1cf3c0 <_Z11HandleOtherv+0xe2c> */
/* @0x1cf210 ldr r2, [r3, #0x8] */
/* @0x1cf214 cmp r1, r2 */
/* @0x1cf218 bne 0x1cf204 <_Z11HandleOtherv+0xc70> */
/* @0x1cf21c ldr r3, [r3, #0xc] */
/* @0x1cf220 cmp r3, #0 */
/* @0x1cf224 beq 0x1cf3c0 <_Z11HandleOtherv+0xe2c> */
/* @0x1cf228 ldr r4, [r3, #0xc4] */
/* @0x1cf22c cmp r4, #0 */
/* @0x1cf230 beq 0x1cf3c0 <_Z11HandleOtherv+0xe2c> */
/* @0x1cf234 ldr r3, [r4, #0x8] */
/* @0x1cf238 cmp r3, #0 */
/* @0x1cf23c bne 0x1cf250 <_Z11HandleOtherv+0xcbc> */
/* @0x1cf240 b 0x1cf3c0 <_Z11HandleOtherv+0xe2c> */
/* @0x1cf244 ldr r3, [r4, #0x8] */
/* @0x1cf248 cmp r3, #0 */
/* @0x1cf24c beq 0x1cf3b8 <_Z11HandleOtherv+0xe24> */
/* @0x1cf250 ldr r5, [r4, #0x8] */
/* @0x1cf254 ldr r4, [r4] */
/* @0x1cf258 ldrb r3, [r5, #0x68] */
/* @0x1cf25c cmp r3, #0 */
/* @0x1cf260 bne 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf264 ldrb r3, [r5, #0x69] */
/* @0x1cf268 cmp r3, #0 */
/* @0x1cf26c bne 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf270 ldrd r2, r3, [r5, #112] */
/* @0x1cf274 ldrd r0, r1, [sp, #24] */
/* @0x1cf278 cmp r0, r2 */
/* @0x1cf27c sbcs r1, r1, r3 */
/* @0x1cf280 blt 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf284 ldr r0, [r5, #0x8c] */
/* @0x1cf288 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1cf28c cmp r0, #0 */
/* @0x1cf290 beq 0x1cf508 <_Z11HandleOtherv+0xf74> */
/* @0x1cf294 ldrb r3, [r5, #0x64] */
/* @0x1cf298 cmp r3, #0 */
/* @0x1cf29c bne 0x1cf524 <_Z11HandleOtherv+0xf90> */
/* @0x1cf2a0 ldr r12, [sp, #0x8] */
/* @0x1cf2a4 add r2, sp, #120 */
/* @0x1cf2a8 ldr r3, [r5, #0xf0] */
/* @0x1cf2ac ldr r8, [r12, r2] */
/* @0x1cf2b0 cmp r3, r8 */
/* @0x1cf2b4 blt 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf2b8 ldrb r3, [r5, #0x64] */
/* @0x1cf2bc cmp r3, #0 */
/* @0x1cf2c0 bne 0x1cf688 <_Z11HandleOtherv+0x10f4> */
/* @0x1cf2c4 ldr r12, [sp, #0x8] */
/* @0x1cf2c8 add r2, sp, #184 */
/* @0x1cf2cc ldr r3, [r5, #0xe8] */
/* @0x1cf2d0 ldr r9, [r12, r2] */
/* @0x1cf2d4 cmp r3, r9 */
/* @0x1cf2d8 bgt 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf2dc ldrb r3, [r5, #0x64] */
/* @0x1cf2e0 cmp r3, #0 */
/* @0x1cf2e4 bne 0x1cf968 <_Z11HandleOtherv+0x13d4> */
/* @0x1cf2e8 ldr r12, [sp, #0x8] */
/* @0x1cf2ec add r2, sp, #152 */
/* @0x1cf2f0 ldr r3, [r5, #0xf4] */
/* @0x1cf2f4 ldr r10, [r12, r2] */
/* @0x1cf2f8 cmp r3, r10 */
/* @0x1cf2fc blt 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf300 ldrb r3, [r5, #0x64] */
/* @0x1cf304 cmp r3, #0 */
/* @0x1cf308 bne 0x1cf9b0 <_Z11HandleOtherv+0x141c> */
/* @0x1cf30c vldr s15, [r5, #236] */
/* @0x1cf310 vmov r0, s15 */
/* @0x1cf314 ldr r12, [sp, #0x8] */
/* @0x1cf318 add r3, sp, #216 */
/* @0x1cf31c ldr r3, [r12, r3] */
/* @0x1cf320 cmp r0, r3 */
/* @0x1cf324 bgt 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf328 ldr r12, [sp, #0x50] */
/* @0x1cf32c vldr s14, [r12] */
/* @0x1cf330 vcmp.f32 s14, #0 */
/* @0x1cf334 vmrs APSR_nzcv, fpscr */
/* @0x1cf338 bne 0x1cf544 <_Z11HandleOtherv+0xfb0> */
/* @0x1cf33c ldrb r2, [r5, #0x64] */
/* @0x1cf340 cmp r2, #0 */
/* @0x1cf344 bne 0x1cf978 <_Z11HandleOtherv+0x13e4> */
/* @0x1cf348 ldr r2, [r5, #0xf0] */
/* @0x1cf34c cmp r9, r2 */
/* @0x1cf350 ble 0x1cf39c <_Z11HandleOtherv+0xe08> */
/* @0x1cf354 ldrb r2, [r5, #0x64] */
/* @0x1cf358 cmp r2, #0 */
/* @0x1cf35c bne 0x1cf9c0 <_Z11HandleOtherv+0x142c> */
/* @0x1cf360 ldr r2, [r5, #0xe8] */
/* @0x1cf364 cmp r8, r2 */
/* @0x1cf368 bge 0x1cf39c <_Z11HandleOtherv+0xe08> */
/* @0x1cf36c ldrb r2, [r5, #0x64] */
/* @0x1cf370 cmp r2, #0 */
/* @0x1cf374 bne 0x1cfcb4 <_Z11HandleOtherv+0x1720> */
/* @0x1cf378 ldr r2, [r5, #0xf4] */
/* @0x1cf37c cmp r3, r2 */
/* @0x1cf380 ble 0x1cf39c <_Z11HandleOtherv+0xe08> */
/* @0x1cf384 ldrb r3, [r5, #0x64] */
/* @0x1cf388 cmp r3, #0 */
/* @0x1cf38c bne 0x1cffe0 <_Z11HandleOtherv+0x1a4c> */
/* @0x1cf390 ldr r3, [r5, #0xec] */
/* @0x1cf394 cmp r10, r3 */
/* @0x1cf398 blt 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf39c mov r0, r5 */
/* @0x1cf3a0 mov r2, #7 */
/* @0x1cf3a4 mov r1, r5 */
/* @0x1cf3a8 ldr r3, [sp, #0x44] */
/* @0x1cf3ac bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1cf3b0 cmp r4, #0 */
/* @0x1cf3b4 bne 0x1cf244 <_Z11HandleOtherv+0xcb0> */
/* @0x1cf3b8 ldr r12, [sp, #0x30] */
/* @0x1cf3bc ldr r0, [r12] */
/* @0x1cf3c0 add r6, r6, #1 */
/* @0x1cf3c4 cmp r0, r6 */
/* @0x1cf3c8 bgt 0x1cf1d4 <_Z11HandleOtherv+0xc40> */
/* @0x1cf3cc ldr r10, [sp, #0x8] */
/* @0x1cf3d0 ldr r12, [sp, #0x2c] */
/* @0x1cf3d4 add r10, r10, #4 */
/* @0x1cf3d8 add r12, r12, #1 */
/* @0x1cf3dc str r12, [sp, #0x2c] */
/* @0x1cf3e0 cmp r12, #8 */
/* @0x1cf3e4 ldr r12, [sp, #0x34] */
/* @0x1cf3e8 add r12, r12, #32 */
/* @0x1cf3ec str r12, [sp, #0x34] */
/* @0x1cf3f0 ldr r12, [sp, #0x38] */
/* @0x1cf3f4 add r12, r12, #32 */
/* @0x1cf3f8 str r12, [sp, #0x38] */
/* @0x1cf3fc bne 0x1cf13c <_Z11HandleOtherv+0xba8> */
/* @0x1cf400 ldr r12, [sp, #0x54] */
/* @0x1cf404 ldrb r3, [r12] */
/* @0x1cf408 cmp r3, #0 */
/* @0x1cf40c bne 0x1cfff0 <_Z11HandleOtherv+0x1a5c> */
/* @0x1cf410 add sp, sp, #828 */
/* @0x1cf414 vpop {d8, d9, d10, d11} */
/* @0x1cf418 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1cf41c ldr r0, [r9, #0xac] */
/* @0x1cf420 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1cf424 cmp r0, #0 */
/* @0x1cf428 bne 0x1cef38 <_Z11HandleOtherv+0x9a4> */
/* @0x1cf42c add r3, sp, #120 */
/* @0x1cf430 vldr s11, [r9, #180] */
/* @0x1cf434 ldr r3, [r7, r3] */
/* @0x1cf438 vmov s15, r3 */
/* @0x1cf43c vcvt.f32.s32 s15, s15 */
/* @0x1cf440 vcmpe.f32 s11, s15 */
/* @0x1cf444 vmrs APSR_nzcv, fpscr */
/* @0x1cf448 bmi 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cf44c add r3, sp, #184 */
/* @0x1cf450 ldr r3, [r7, r3] */
/* @0x1cf454 vmov s15, r3 */
/* @0x1cf458 vcvt.f32.s32 s15, s15 */
/* @0x1cf45c vcmpe.f32 s11, s15 */
/* @0x1cf460 vmrs APSR_nzcv, fpscr */
/* @0x1cf464 bgt 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cf468 add r3, sp, #152 */
/* @0x1cf46c vldr s10, [r9, #184] */
/* @0x1cf470 ldr r3, [r7, r3] */
/* @0x1cf474 vmov s15, r3 */
/* @0x1cf478 vcvt.f32.s32 s15, s15 */
/* @0x1cf47c vcmpe.f32 s10, s15 */
/* @0x1cf480 vmrs APSR_nzcv, fpscr */
/* @0x1cf484 bmi 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cf488 add r3, sp, #216 */
/* @0x1cf48c ldr r3, [r7, r3] */
/* @0x1cf490 vmov s15, r3 */
/* @0x1cf494 vcvt.f32.s32 s15, s15 */
/* @0x1cf498 vcmpe.f32 s10, s15 */
/* @0x1cf49c vmrs APSR_nzcv, fpscr */
/* @0x1cf4a0 bgt 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cf4a4 ldr r12, [sp, #0x30] */
/* @0x1cf4a8 vldr s15, [r12] */
/* @0x1cf4ac vcmp.f32 s15, #0 */
/* @0x1cf4b0 vmrs APSR_nzcv, fpscr */
/* @0x1cf4b4 beq 0x1cf094 <_Z11HandleOtherv+0xb00> */
/* @0x1cf4b8 ldr r2, [sp, #0x24] */
/* @0x1cf4bc mov r1, #0 */
/* @0x1cf4c0 ldr r3, [sp, #0x28] */
/* @0x1cf4c4 vldr s15, [r3, #-4] */
/* @0x1cf4c8 vsub.f32 s15, s11, s15 */
/* @0x1cf4cc vldr s12, [r2] */
/* @0x1cf4d0 vldr s13, [r3] */
/* @0x1cf4d4 vldr s14, [r2, #-4] */
/* @0x1cf4d8 add r1, r1, #1 */
/* @0x1cf4dc add r3, r3, #8 */
/* @0x1cf4e0 add r2, r2, #8 */
/* @0x1cf4e4 vmul.f32 s15, s15, s12 */
/* @0x1cf4e8 vsub.f32 s13, s10, s13 */
/* @0x1cf4ec vnmls.f32 s15, s13, s14 */
/* @0x1cf4f0 vcmpe.f32 s15, #0 */
/* @0x1cf4f4 vmrs APSR_nzcv, fpscr */
/* @0x1cf4f8 bmi 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cf4fc cmp r1, #4 */
/* @0x1cf500 bne 0x1cf4c4 <_Z11HandleOtherv+0xf30> */
/* @0x1cf504 b 0x1cf094 <_Z11HandleOtherv+0xb00> */
/* @0x1cf508 ldr r0, [r5, #0xac] */
/* @0x1cf50c bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1cf510 cmp r0, #0 */
/* @0x1cf514 beq 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf518 ldrb r3, [r5, #0x64] */
/* @0x1cf51c cmp r3, #0 */
/* @0x1cf520 beq 0x1cf2a0 <_Z11HandleOtherv+0xd0c> */
/* @0x1cf524 mov r0, r5 */
/* @0x1cf528 mov r1, #1 */
/* @0x1cf52c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf530 b 0x1cf2a0 <_Z11HandleOtherv+0xd0c> */
/* @0x1cf534 mov r0, r9 */
/* @0x1cf538 mov r1, #1 */
/* @0x1cf53c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf540 b 0x1cef44 <_Z11HandleOtherv+0x9b0> */
/* @0x1cf544 ldrb r3, [r5, #0x64] */
/* @0x1cf548 cmp r3, #0 */
/* @0x1cf54c bne 0x1cf848 <_Z11HandleOtherv+0x12b4> */
/* @0x1cf550 vldr s14, [r5, #232] */
/* @0x1cf554 vcvt.f32.s32 s16, s14 */
/* @0x1cf558 vstr s16, [sp, #248] */
/* @0x1cf55c vcvt.f32.s32 s17, s15 */
/* @0x1cf560 vstr s17, [sp, #252] */
/* @0x1cf564 vldr s13, [r5, #240] */
/* @0x1cf568 vcvt.f32.s32 s12, s13 */
/* @0x1cf56c vstr s12, [sp, #256] */
/* @0x1cf570 vcvt.f32.s32 s15, s15 */
/* @0x1cf574 vstr s15, [sp, #260] */
/* @0x1cf578 vcvt.f32.s32 s13, s13 */
/* @0x1cf57c vstr s13, [sp, #264] */
/* @0x1cf580 vldr s15, [r5, #244] */
/* @0x1cf584 vcvt.f32.s32 s13, s15 */
/* @0x1cf588 vstr s13, [sp, #268] */
/* @0x1cf58c vcvt.f32.s32 s14, s14 */
/* @0x1cf590 vstr s14, [sp, #272] */
/* @0x1cf594 vcvt.f32.s32 s15, s15 */
/* @0x1cf598 ldr r9, [sp, #0x38] */
/* @0x1cf59c ldr r8, [sp, #0x34] */
/* @0x1cf5a0 mov r10, #4 */
/* @0x1cf5a4 mov r12, #1 */
/* @0x1cf5a8 vstr s15, [sp, #276] */
/* @0x1cf5ac vmov.f32 s14, s17 */
/* @0x1cf5b0 add r3, sp, #256 */
/* @0x1cf5b4 mov r0, #1 */
/* @0x1cf5b8 vldr s10, [r8, #-4] */
/* @0x1cf5bc vldr s11, [r8] */
/* @0x1cf5c0 vldr s12, [r9, #-4] */
/* @0x1cf5c4 vldr s13, [r9] */
/* @0x1cf5c8 vmov.f32 s15, s16 */
/* @0x1cf5cc eor r1, r0, #1 */
/* @0x1cf5d0 mov r2, r7 */
/* @0x1cf5d4 vsub.f32 s15, s15, s10 */
/* @0x1cf5d8 vmul.f32 s15, s15, s13 */
/* @0x1cf5dc vsub.f32 s14, s14, s11 */
/* @0x1cf5e0 vnmls.f32 s15, s14, s12 */
/* @0x1cf5e4 vcmpe.f32 s15, #0 */
/* @0x1cf5e8 vmrs APSR_nzcv, fpscr */
/* @0x1cf5ec movgt r12, #0 */
/* @0x1cf5f0 ble 0x1cf614 <_Z11HandleOtherv+0x1080> */
/* @0x1cf5f4 tst r1, r2 */
/* @0x1cf5f8 add r3, r3, #8 */
/* @0x1cf5fc bne 0x1cf630 <_Z11HandleOtherv+0x109c> */
/* @0x1cf600 cmp r3, r11 */
/* @0x1cf604 beq 0x1cf650 <_Z11HandleOtherv+0x10bc> */
/* @0x1cf608 vldr s15, [r3, #-8] */
/* @0x1cf60c vldr s14, [r3, #-4] */
/* @0x1cf610 b 0x1cf5cc <_Z11HandleOtherv+0x1038> */
/* @0x1cf614 eor r1, r0, #1 */
/* @0x1cf618 eor r2, r12, #1 */
/* @0x1cf61c movmi r1, r7 */
/* @0x1cf620 movmi r0, #0 */
/* @0x1cf624 tst r1, r2 */
/* @0x1cf628 add r3, r3, #8 */
/* @0x1cf62c beq 0x1cf600 <_Z11HandleOtherv+0x106c> */
/* @0x1cf630 subs r10, r10, #1 */
/* @0x1cf634 mov r12, #0 */
/* @0x1cf638 add r8, r8, #8 */
/* @0x1cf63c add r9, r9, #8 */
/* @0x1cf640 bne 0x1cf5ac <_Z11HandleOtherv+0x1018> */
/* @0x1cf644 cmp r12, #0 */
/* @0x1cf648 bne 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf64c b 0x1cf39c <_Z11HandleOtherv+0xe08> */
/* @0x1cf650 cmp r0, #0 */
/* @0x1cf654 bne 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf658 subs r10, r10, #1 */
/* @0x1cf65c add r8, r8, #8 */
/* @0x1cf660 add r9, r9, #8 */
/* @0x1cf664 bne 0x1cf5ac <_Z11HandleOtherv+0x1018> */
/* @0x1cf668 cmp r12, #0 */
/* @0x1cf66c bne 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf670 b 0x1cf39c <_Z11HandleOtherv+0xe08> */
/* @0x1cf674 subs r0, r0, #1 */
/* @0x1cf678 add r2, r2, #8 */
/* @0x1cf67c add r1, r1, #8 */
/* @0x1cf680 bne 0x1cf034 <_Z11HandleOtherv+0xaa0> */
/* @0x1cf684 b 0x1cf094 <_Z11HandleOtherv+0xb00> */
/* @0x1cf688 mov r0, r5 */
/* @0x1cf68c mov r1, #1 */
/* @0x1cf690 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf694 b 0x1cf2c4 <_Z11HandleOtherv+0xd30> */
/* @0x1cf698 mov r0, r9 */
/* @0x1cf69c mov r1, #1 */
/* @0x1cf6a0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf6a4 b 0x1cef64 <_Z11HandleOtherv+0x9d0> */
/* @0x1cf6a8 ldr r0, [r6, #0xac] */
/* @0x1cf6ac bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1cf6b0 cmp r0, #0 */
/* @0x1cf6b4 bne 0x1ce880 <_Z11HandleOtherv+0x2ec> */
/* @0x1cf6b8 vldr s14, [r6, #180] */
/* @0x1cf6bc vcmpe.f32 s14, #0 */
/* @0x1cf6c0 vmrs APSR_nzcv, fpscr */
/* @0x1cf6c4 bmi 0x1ce8f0 <_Z11HandleOtherv+0x35c> */
/* @0x1cf6c8 ldr r3, [r10] */
/* @0x1cf6cc vldr s12, [r3, #16] */
/* @0x1cf6d0 vcvt.f32.s32 s15, s12 */
/* @0x1cf6d4 vcmpe.f32 s14, s15 */
/* @0x1cf6d8 vmrs APSR_nzcv, fpscr */
/* @0x1cf6dc bgt 0x1ce8f0 <_Z11HandleOtherv+0x35c> */
/* @0x1cf6e0 vldr s15, [r6, #184] */
/* @0x1cf6e4 vcmpe.f32 s15, #0 */
/* @0x1cf6e8 vmrs APSR_nzcv, fpscr */
/* @0x1cf6ec bmi 0x1ce8f0 <_Z11HandleOtherv+0x35c> */
/* @0x1cf6f0 vldr s14, [r3, #20] */
/* @0x1cf6f4 vcvt.f32.s32 s14, s14 */
/* @0x1cf6f8 vcmpe.f32 s15, s14 */
/* @0x1cf6fc vmrs APSR_nzcv, fpscr */
/* @0x1cf700 bgt 0x1ce8f0 <_Z11HandleOtherv+0x35c> */
/* @0x1cf704 b 0x1ce828 <_Z11HandleOtherv+0x294> */
/* @0x1cf708 mov r0, r9 */
/* @0x1cf70c mov r1, #1 */
/* @0x1cf710 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf714 vldr s14, [r9, #232] */
/* @0x1cf718 vcvt.f32.s32 s16, s14 */
/* @0x1cf71c ldrb r3, [r9, #0x64] */
/* @0x1cf720 cmp r3, #0 */
/* @0x1cf724 vldreq s13, [r9, #236] */
/* @0x1cf728 vstr s16, [sp, #248] */
/* @0x1cf72c beq 0x1cefe8 <_Z11HandleOtherv+0xa54> */
/* @0x1cf730 mov r0, r9 */
/* @0x1cf734 mov r1, #1 */
/* @0x1cf738 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf73c vldr s13, [r9, #236] */
/* @0x1cf740 vcvt.f32.s32 s17, s13 */
/* @0x1cf744 ldrb r3, [r9, #0x64] */
/* @0x1cf748 cmp r3, #0 */
/* @0x1cf74c vldreq s14, [r9, #232] */
/* @0x1cf750 vstr s17, [sp, #252] */
/* @0x1cf754 beq 0x1ceff0 <_Z11HandleOtherv+0xa5c> */
/* @0x1cf758 mov r0, r9 */
/* @0x1cf75c mov r1, #1 */
/* @0x1cf760 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf764 vldr s15, [r9, #240] */
/* @0x1cf768 vcvt.f32.s32 s14, s15 */
/* @0x1cf76c ldrb r3, [r9, #0x64] */
/* @0x1cf770 cmp r3, #0 */
/* @0x1cf774 vstr s14, [sp, #256] */
/* @0x1cf778 beq 0x1d0098 <_Z11HandleOtherv+0x1b04> */
/* @0x1cf77c mov r0, r9 */
/* @0x1cf780 mov r1, #1 */
/* @0x1cf784 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf788 vldr s12, [r9, #236] */
/* @0x1cf78c vcvt.f32.s32 s15, s12 */
/* @0x1cf790 ldrb r3, [r9, #0x64] */
/* @0x1cf794 cmp r3, #0 */
/* @0x1cf798 vstr s15, [sp, #260] */
/* @0x1cf79c beq 0x1d005c <_Z11HandleOtherv+0x1ac8> */
/* @0x1cf7a0 mov r0, r9 */
/* @0x1cf7a4 mov r1, #1 */
/* @0x1cf7a8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf7ac vldr s13, [r9, #240] */
/* @0x1cf7b0 vcvt.f32.s32 s15, s13 */
/* @0x1cf7b4 ldrb r3, [r9, #0x64] */
/* @0x1cf7b8 cmp r3, #0 */
/* @0x1cf7bc vldreq s14, [r9, #232] */
/* @0x1cf7c0 vstr s15, [sp, #264] */
/* @0x1cf7c4 beq 0x1cf00c <_Z11HandleOtherv+0xa78> */
/* @0x1cf7c8 mov r0, r9 */
/* @0x1cf7cc mov r1, #1 */
/* @0x1cf7d0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf7d4 vldr s15, [r9, #244] */
/* @0x1cf7d8 vcvt.f32.s32 s14, s15 */
/* @0x1cf7dc ldrb r3, [r9, #0x64] */
/* @0x1cf7e0 cmp r3, #0 */
/* @0x1cf7e4 vstr s14, [sp, #268] */
/* @0x1cf7e8 vldreq s14, [r9, #232] */
/* @0x1cf7ec beq 0x1cf018 <_Z11HandleOtherv+0xa84> */
/* @0x1cf7f0 mov r0, r9 */
/* @0x1cf7f4 mov r1, #1 */
/* @0x1cf7f8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf7fc vldr s14, [r9, #232] */
/* @0x1cf800 vcvt.f32.s32 s15, s14 */
/* @0x1cf804 ldrb r3, [r9, #0x64] */
/* @0x1cf808 cmp r3, #0 */
/* @0x1cf80c vstr s15, [sp, #272] */
/* @0x1cf810 beq 0x1cf820 <_Z11HandleOtherv+0x128c> */
/* @0x1cf814 mov r0, r9 */
/* @0x1cf818 mov r1, #1 */
/* @0x1cf81c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf820 vldr s15, [r9, #244] */
/* @0x1cf824 b 0x1cf020 <_Z11HandleOtherv+0xa8c> */
/* @0x1cf828 mov r0, r6 */
/* @0x1cf82c mov r1, #1 */
/* @0x1cf830 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf834 b 0x1ce6f4 <_Z11HandleOtherv+0x160> */
/* @0x1cf838 mov r0, r6 */
/* @0x1cf83c mov r1, #1 */
/* @0x1cf840 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf844 b 0x1ce88c <_Z11HandleOtherv+0x2f8> */
/* @0x1cf848 mov r0, r5 */
/* @0x1cf84c mov r1, #1 */
/* @0x1cf850 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf854 vldr s14, [r5, #232] */
/* @0x1cf858 vcvt.f32.s32 s16, s14 */
/* @0x1cf85c ldrb r3, [r5, #0x64] */
/* @0x1cf860 cmp r3, #0 */
/* @0x1cf864 vstr s16, [sp, #248] */
/* @0x1cf868 beq 0x1d0090 <_Z11HandleOtherv+0x1afc> */
/* @0x1cf86c mov r0, r5 */
/* @0x1cf870 mov r1, #1 */
/* @0x1cf874 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf878 vldr s15, [r5, #236] */
/* @0x1cf87c vcvt.f32.s32 s17, s15 */
/* @0x1cf880 ldrb r3, [r5, #0x64] */
/* @0x1cf884 cmp r3, #0 */
/* @0x1cf888 vstr s17, [sp, #252] */
/* @0x1cf88c beq 0x1d00a4 <_Z11HandleOtherv+0x1b10> */
/* @0x1cf890 mov r0, r5 */
/* @0x1cf894 mov r1, #1 */
/* @0x1cf898 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf89c vldr s13, [r5, #240] */
/* @0x1cf8a0 vcvt.f32.s32 s15, s13 */
/* @0x1cf8a4 ldrb r3, [r5, #0x64] */
/* @0x1cf8a8 cmp r3, #0 */
/* @0x1cf8ac vstr s15, [sp, #256] */
/* @0x1cf8b0 beq 0x1d007c <_Z11HandleOtherv+0x1ae8> */
/* @0x1cf8b4 mov r0, r5 */
/* @0x1cf8b8 mov r1, #1 */
/* @0x1cf8bc bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf8c0 vldr s12, [r5, #236] */
/* @0x1cf8c4 vcvt.f32.s32 s15, s12 */
/* @0x1cf8c8 ldrb r3, [r5, #0x64] */
/* @0x1cf8cc cmp r3, #0 */
/* @0x1cf8d0 vstr s15, [sp, #260] */
/* @0x1cf8d4 beq 0x1d0070 <_Z11HandleOtherv+0x1adc> */
/* @0x1cf8d8 mov r0, r5 */
/* @0x1cf8dc mov r1, #1 */
/* @0x1cf8e0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf8e4 vldr s13, [r5, #240] */
/* @0x1cf8e8 vcvt.f32.s32 s15, s13 */
/* @0x1cf8ec ldrb r3, [r5, #0x64] */
/* @0x1cf8f0 cmp r3, #0 */
/* @0x1cf8f4 vstr s15, [sp, #264] */
/* @0x1cf8f8 beq 0x1d0068 <_Z11HandleOtherv+0x1ad4> */
/* @0x1cf8fc mov r0, r5 */
/* @0x1cf900 mov r1, #1 */
/* @0x1cf904 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf908 vldr s15, [r5, #244] */
/* @0x1cf90c vcvt.f32.s32 s14, s15 */
/* @0x1cf910 ldrb r3, [r5, #0x64] */
/* @0x1cf914 cmp r3, #0 */
/* @0x1cf918 vstr s14, [sp, #268] */
/* @0x1cf91c beq 0x1d0088 <_Z11HandleOtherv+0x1af4> */
/* @0x1cf920 mov r0, r5 */
/* @0x1cf924 mov r1, #1 */
/* @0x1cf928 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf92c vldr s14, [r5, #232] */
/* @0x1cf930 vcvt.f32.s32 s15, s14 */
/* @0x1cf934 ldrb r3, [r5, #0x64] */
/* @0x1cf938 cmp r3, #0 */
/* @0x1cf93c vstr s15, [sp, #272] */
/* @0x1cf940 beq 0x1cf950 <_Z11HandleOtherv+0x13bc> */
/* @0x1cf944 mov r0, r5 */
/* @0x1cf948 mov r1, #1 */
/* @0x1cf94c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf950 vldr s15, [r5, #244] */
/* @0x1cf954 b 0x1cf594 <_Z11HandleOtherv+0x1000> */
/* @0x1cf958 mov r0, r9 */
/* @0x1cf95c mov r1, #1 */
/* @0x1cf960 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf964 b 0x1cef84 <_Z11HandleOtherv+0x9f0> */
/* @0x1cf968 mov r0, r5 */
/* @0x1cf96c mov r1, #1 */
/* @0x1cf970 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf974 b 0x1cf2e8 <_Z11HandleOtherv+0xd54> */
/* @0x1cf978 mov r0, r5 */
/* @0x1cf97c mov r1, #1 */
/* @0x1cf980 str r3, [sp, #0x4] */
/* @0x1cf984 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf988 ldr r3, [sp, #0x4] */
/* @0x1cf98c b 0x1cf348 <_Z11HandleOtherv+0xdb4> */
/* @0x1cf990 mov r0, r6 */
/* @0x1cf994 mov r1, #1 */
/* @0x1cf998 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf99c b 0x1ce70c <_Z11HandleOtherv+0x178> */
/* @0x1cf9a0 mov r0, r6 */
/* @0x1cf9a4 mov r1, #1 */
/* @0x1cf9a8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf9ac b 0x1ce8a4 <_Z11HandleOtherv+0x310> */
/* @0x1cf9b0 mov r0, r5 */
/* @0x1cf9b4 mov r1, #1 */
/* @0x1cf9b8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf9bc b 0x1cf30c <_Z11HandleOtherv+0xd78> */
/* @0x1cf9c0 mov r0, r5 */
/* @0x1cf9c4 mov r1, #1 */
/* @0x1cf9c8 str r3, [sp, #0x4] */
/* @0x1cf9cc bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf9d0 ldr r3, [sp, #0x4] */
/* @0x1cf9d4 b 0x1cf360 <_Z11HandleOtherv+0xdcc> */
/* @0x1cf9d8 mov r0, r9 */
/* @0x1cf9dc mov r1, #1 */
/* @0x1cf9e0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf9e4 b 0x1cefa4 <_Z11HandleOtherv+0xa10> */
/* @0x1cf9e8 vcmpe.f32 s14, s11 */
/* @0x1cf9ec vmrs APSR_nzcv, fpscr */
/* @0x1cf9f0 bpl 0x1cfccc <_Z11HandleOtherv+0x1738> */
/* @0x1cf9f4 vcmpe.f32 s12, s14 */
/* @0x1cf9f8 vmrs APSR_nzcv, fpscr */
/* @0x1cf9fc vmovpl.f32 s7, s14 */
/* @0x1cfa00 bmi 0x1ceaac <_Z11HandleOtherv+0x518> */
/* @0x1cfa04 vcmpe.f32 s7, s8 */
/* @0x1cfa08 vmrs APSR_nzcv, fpscr */
/* @0x1cfa0c bpl 0x1ceab8 <_Z11HandleOtherv+0x524> */
/* @0x1cfa10 vcmpe.f32 s12, s14 */
/* @0x1cfa14 vmrs APSR_nzcv, fpscr */
/* @0x1cfa18 bpl 0x1cfa30 <_Z11HandleOtherv+0x149c> */
/* @0x1cfa1c vcmpe.f32 s12, s11 */
/* @0x1cfa20 vmrs APSR_nzcv, fpscr */
/* @0x1cfa24 bmi 0x1cfa48 <_Z11HandleOtherv+0x14b4> */
/* @0x1cfa28 vcvt.s32.f32 s7, s11 */
/* @0x1cfa2c b 0x1ceabc <_Z11HandleOtherv+0x528> */
/* @0x1cfa30 vcmpe.f32 s14, s11 */
/* @0x1cfa34 vmrs APSR_nzcv, fpscr */
/* @0x1cfa38 bpl 0x1cfa28 <_Z11HandleOtherv+0x1494> */
/* @0x1cfa3c vcmpe.f32 s12, s14 */
/* @0x1cfa40 vmrs APSR_nzcv, fpscr */
/* @0x1cfa44 bpl 0x1d0024 <_Z11HandleOtherv+0x1a90> */
/* @0x1cfa48 vcvt.s32.f32 s7, s12 */
/* @0x1cfa4c b 0x1ceabc <_Z11HandleOtherv+0x528> */
/* @0x1cfa50 mov r0, r6 */
/* @0x1cfa54 mov r1, #1 */
/* @0x1cfa58 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cfa5c b 0x1ce8c4 <_Z11HandleOtherv+0x330> */
/* @0x1cfa60 mov r0, r6 */
/* @0x1cfa64 mov r1, #1 */
/* @0x1cfa68 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cfa6c b 0x1ce72c <_Z11HandleOtherv+0x198> */
/* @0x1cfa70 vnmul.f32 s21, s15, s19 */
/* @0x1cfa74 str r1, [sp, #0x4] */
/* @0x1cfa78 str r12, [sp] */
/* @0x1cfa7c vmov r0, s21 */
/* @0x1cfa80 bl 0xb6580 <sinf@plt> */
/* @0x1cfa84 vmov s20, r0 */
/* @0x1cfa88 vmov r0, s21 */
/* @0x1cfa8c bl 0xb658c <cosf@plt> */
/* @0x1cfa90 ldr r1, [sp, #0x4] */
/* @0x1cfa94 vldr s13, [r1, #12] */
/* @0x1cfa98 vmul.f32 s13, s13, s16 */
/* @0x1cfa9c vldr s15, [r1, #16] */
/* @0x1cfaa0 vldr s14, [r1, #4] */
/* @0x1cfaa4 vldr s10, [r1, #8] */
/* @0x1cfaa8 ldr r12, [sp] */
/* @0x1cfaac vmul.f32 s15, s15, s16 */
/* @0x1cfab0 vnmul.f32 s8, s20, s13 */
/* @0x1cfab4 vmov s11, r0 */
/* @0x1cfab8 vmul.f32 s12, s13, s11 */
/* @0x1cfabc vadd.f32 s13, s13, s14 */
/* @0x1cfac0 vmul.f32 s14, s15, s20 */
/* @0x1cfac4 vadd.f32 s10, s15, s10 */
/* @0x1cfac8 vmul.f32 s15, s15, s11 */
/* @0x1cfacc vsub.f32 s11, s13, s12 */
/* @0x1cfad0 vsub.f32 s9, s10, s8 */
/* @0x1cfad4 vadd.f32 s12, s12, s13 */
/* @0x1cfad8 vadd.f32 s13, s8, s10 */
/* @0x1cfadc vadd.f32 s10, s14, s11 */
/* @0x1cfae0 vsub.f32 s11, s11, s14 */
/* @0x1cfae4 vstr s10, [r5] */
/* @0x1cfae8 vadd.f32 s10, s14, s12 */
/* @0x1cfaec vsub.f32 s14, s12, s14 */
/* @0x1cfaf0 vadd.f32 s12, s15, s9 */
/* @0x1cfaf4 vsub.f32 s9, s9, s15 */
/* @0x1cfaf8 vstr s12, [r10] */
/* @0x1cfafc vstr s10, [r9] */
/* @0x1cfb00 vadd.f32 s12, s15, s13 */
/* @0x1cfb04 vsub.f32 s15, s13, s15 */
/* @0x1cfb08 vstr s12, [r11] */
/* @0x1cfb0c vstr s14, [r5, #16] */
/* @0x1cfb10 vstr s15, [r5, #20] */
/* @0x1cfb14 vstr s11, [r8] */
/* @0x1cfb18 vstr s9, [r5, #28] */
/* @0x1cfb1c vldr s14, [r5] */
/* @0x1cfb20 vldr s15, [r9] */
/* @0x1cfb24 vcmpe.f32 s14, s15 */
/* @0x1cfb28 vldr s11, [r5, #16] */
/* @0x1cfb2c vmrs APSR_nzcv, fpscr */
/* @0x1cfb30 bpl 0x1cfc28 <_Z11HandleOtherv+0x1694> */
/* @0x1cfb34 vcmpe.f32 s14, s11 */
/* @0x1cfb38 vmrs APSR_nzcv, fpscr */
/* @0x1cfb3c bpl 0x1cffa0 <_Z11HandleOtherv+0x1a0c> */
/* @0x1cfb40 vldr s8, [r8] */
/* @0x1cfb44 vcmpe.f32 s14, s8 */
/* @0x1cfb48 vmrs APSR_nzcv, fpscr */
/* @0x1cfb4c bmi 0x1cfc60 <_Z11HandleOtherv+0x16cc> */
/* @0x1cfb50 vcvt.s32.f32 s10, s8 */
/* @0x1cfb54 vmov r0, s10 */
/* @0x1cfb58 vldr s12, [r10] */
/* @0x1cfb5c vldr s13, [r11] */
/* @0x1cfb60 add r1, sp, #120 */
/* @0x1cfb64 vldr s10, [r5, #20] */
/* @0x1cfb68 vcmpe.f32 s12, s13 */
/* @0x1cfb6c vmrs APSR_nzcv, fpscr */
/* @0x1cfb70 str r0, [r6, r1] */
/* @0x1cfb74 bpl 0x1cfe68 <_Z11HandleOtherv+0x18d4> */
/* @0x1cfb78 vcmpe.f32 s10, s12 */
/* @0x1cfb7c vmrs APSR_nzcv, fpscr */
/* @0x1cfb80 ble 0x1cffa8 <_Z11HandleOtherv+0x1a14> */
/* @0x1cfb84 vcmpe.f32 s9, s12 */
/* @0x1cfb88 vmrs APSR_nzcv, fpscr */
/* @0x1cfb8c bgt 0x1cfe9c <_Z11HandleOtherv+0x1908> */
/* @0x1cfb90 vcvt.s32.f32 s7, s9 */
/* @0x1cfb94 vmov r2, s7 */
/* @0x1cfb98 add r1, sp, #152 */
/* @0x1cfb9c vcmpe.f32 s14, s15 */
/* @0x1cfba0 vmrs APSR_nzcv, fpscr */
/* @0x1cfba4 str r2, [r6, r1] */
/* @0x1cfba8 ble 0x1cfed0 <_Z11HandleOtherv+0x193c> */
/* @0x1cfbac vcmpe.f32 s14, s11 */
/* @0x1cfbb0 vmrs APSR_nzcv, fpscr */
/* @0x1cfbb4 ble 0x1cffb0 <_Z11HandleOtherv+0x1a1c> */
/* @0x1cfbb8 vcmpe.f32 s8, s14 */
/* @0x1cfbbc vmrs APSR_nzcv, fpscr */
/* @0x1cfbc0 bmi 0x1cff04 <_Z11HandleOtherv+0x1970> */
/* @0x1cfbc4 vcvt.s32.f32 s7, s8 */
/* @0x1cfbc8 vmov r3, s7 */
/* @0x1cfbcc add r1, sp, #184 */
/* @0x1cfbd0 vcmpe.f32 s12, s13 */
/* @0x1cfbd4 vmrs APSR_nzcv, fpscr */
/* @0x1cfbd8 str r3, [r6, r1] */
/* @0x1cfbdc ble 0x1cff38 <_Z11HandleOtherv+0x19a4> */
/* @0x1cfbe0 vcmpe.f32 s12, s10 */
/* @0x1cfbe4 vmrs APSR_nzcv, fpscr */
/* @0x1cfbe8 ble 0x1cffb8 <_Z11HandleOtherv+0x1a24> */
/* @0x1cfbec vcmpe.f32 s9, s12 */
/* @0x1cfbf0 vmrs APSR_nzcv, fpscr */
/* @0x1cfbf4 bmi 0x1cff6c <_Z11HandleOtherv+0x19d8> */
/* @0x1cfbf8 vcvt.s32.f32 s7, s9 */
/* @0x1cfbfc vmov r2, s7 */
/* @0x1cfc00 add r3, sp, #88 */
/* @0x1cfc04 ldr r1, [sp, #0x3c] */
/* @0x1cfc08 ldr r0, [r1] */
/* @0x1cfc0c add r1, sp, #216 */
/* @0x1cfc10 ldr r0, [r0, r12, lsl #2] */
/* @0x1cfc14 ldr r0, [r0, #0x24] */
/* @0x1cfc18 str r2, [r6, r1] */
/* @0x1cfc1c add r1, r3, r6 */
/* @0x1cfc20 str r0, [r1] */
/* @0x1cfc24 b 0x1ced5c <_Z11HandleOtherv+0x7c8> */
/* @0x1cfc28 vcmpe.f32 s15, s11 */
/* @0x1cfc2c vmrs APSR_nzcv, fpscr */
/* @0x1cfc30 bpl 0x1cffa0 <_Z11HandleOtherv+0x1a0c> */
/* @0x1cfc34 vcmpe.f32 s14, s15 */
/* @0x1cfc38 vmrs APSR_nzcv, fpscr */
/* @0x1cfc3c vmovpl.f32 s13, s15 */
/* @0x1cfc40 bmi 0x1cfb40 <_Z11HandleOtherv+0x15ac> */
/* @0x1cfc44 vldr s8, [r8] */
/* @0x1cfc48 vcmpe.f32 s13, s8 */
/* @0x1cfc4c vmrs APSR_nzcv, fpscr */
/* @0x1cfc50 bpl 0x1cfb50 <_Z11HandleOtherv+0x15bc> */
/* @0x1cfc54 vcmpe.f32 s14, s15 */
/* @0x1cfc58 vmrs APSR_nzcv, fpscr */
/* @0x1cfc5c bpl 0x1cfc74 <_Z11HandleOtherv+0x16e0> */
/* @0x1cfc60 vcmpe.f32 s14, s11 */
/* @0x1cfc64 vmrs APSR_nzcv, fpscr */
/* @0x1cfc68 bpl 0x1cffd8 <_Z11HandleOtherv+0x1a44> */
/* @0x1cfc6c vcvt.s32.f32 s10, s14 */
/* @0x1cfc70 b 0x1cfb54 <_Z11HandleOtherv+0x15c0> */
/* @0x1cfc74 vcmpe.f32 s15, s11 */
/* @0x1cfc78 vmrs APSR_nzcv, fpscr */
/* @0x1cfc7c bpl 0x1cffd8 <_Z11HandleOtherv+0x1a44> */
/* @0x1cfc80 vcmpe.f32 s14, s15 */
/* @0x1cfc84 vmrs APSR_nzcv, fpscr */
/* @0x1cfc88 bmi 0x1cfc6c <_Z11HandleOtherv+0x16d8> */
/* @0x1cfc8c vcvt.s32.f32 s10, s15 */
/* @0x1cfc90 b 0x1cfb54 <_Z11HandleOtherv+0x15c0> */
/* @0x1cfc94 mov r0, r6 */
/* @0x1cfc98 mov r1, #1 */
/* @0x1cfc9c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cfca0 b 0x1ce744 <_Z11HandleOtherv+0x1b0> */
/* @0x1cfca4 mov r0, r6 */
/* @0x1cfca8 mov r1, #1 */
/* @0x1cfcac bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cfcb0 b 0x1ce8dc <_Z11HandleOtherv+0x348> */
/* @0x1cfcb4 mov r0, r5 */
/* @0x1cfcb8 mov r1, #1 */
/* @0x1cfcbc str r3, [sp, #0x4] */
/* @0x1cfcc0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cfcc4 ldr r3, [sp, #0x4] */
/* @0x1cfcc8 b 0x1cf378 <_Z11HandleOtherv+0xde4> */
/* @0x1cfccc vmov.f32 s7, s11 */
/* @0x1cfcd0 b 0x1cfa04 <_Z11HandleOtherv+0x1470> */
/* @0x1cfcd4 vcmpe.f32 s15, s9 */
/* @0x1cfcd8 vmrs APSR_nzcv, fpscr */
/* @0x1cfcdc bpl 0x1cfe1c <_Z11HandleOtherv+0x1888> */
/* @0x1cfce0 vcmpe.f32 s13, s15 */
/* @0x1cfce4 vmrs APSR_nzcv, fpscr */
/* @0x1cfce8 vmovpl.f32 s7, s15 */
/* @0x1cfcec bmi 0x1ceae0 <_Z11HandleOtherv+0x54c> */
/* @0x1cfcf0 vcmpe.f32 s7, s10 */
/* @0x1cfcf4 vmrs APSR_nzcv, fpscr */
/* @0x1cfcf8 bpl 0x1ceaec <_Z11HandleOtherv+0x558> */
/* @0x1cfcfc vcmpe.f32 s13, s15 */
/* @0x1cfd00 vmrs APSR_nzcv, fpscr */
/* @0x1cfd04 bpl 0x1cfd1c <_Z11HandleOtherv+0x1788> */
/* @0x1cfd08 vcmpe.f32 s13, s9 */
/* @0x1cfd0c vmrs APSR_nzcv, fpscr */
/* @0x1cfd10 bmi 0x1cfd34 <_Z11HandleOtherv+0x17a0> */
/* @0x1cfd14 vcvt.s32.f32 s7, s9 */
/* @0x1cfd18 b 0x1ceaf0 <_Z11HandleOtherv+0x55c> */
/* @0x1cfd1c vcmpe.f32 s15, s9 */
/* @0x1cfd20 vmrs APSR_nzcv, fpscr */
/* @0x1cfd24 bpl 0x1cfd14 <_Z11HandleOtherv+0x1780> */
/* @0x1cfd28 vcmpe.f32 s13, s15 */
/* @0x1cfd2c vmrs APSR_nzcv, fpscr */
/* @0x1cfd30 bpl 0x1d0034 <_Z11HandleOtherv+0x1aa0> */
/* @0x1cfd34 vcvt.s32.f32 s7, s13 */
/* @0x1cfd38 b 0x1ceaf0 <_Z11HandleOtherv+0x55c> */
/* @0x1cfd3c vcmpe.f32 s14, s11 */
/* @0x1cfd40 vmrs APSR_nzcv, fpscr */
/* @0x1cfd44 ble 0x1cfe0c <_Z11HandleOtherv+0x1878> */
/* @0x1cfd48 vcmpe.f32 s12, s14 */
/* @0x1cfd4c vmrs APSR_nzcv, fpscr */
/* @0x1cfd50 vmovle.f32 s7, s14 */
/* @0x1cfd54 bgt 0x1ceb14 <_Z11HandleOtherv+0x580> */
/* @0x1cfd58 vcmpe.f32 s7, s8 */
/* @0x1cfd5c vmrs APSR_nzcv, fpscr */
/* @0x1cfd60 ble 0x1ceb20 <_Z11HandleOtherv+0x58c> */
/* @0x1cfd64 vcmpe.f32 s12, s14 */
/* @0x1cfd68 vmrs APSR_nzcv, fpscr */
/* @0x1cfd6c ble 0x1cfd84 <_Z11HandleOtherv+0x17f0> */
/* @0x1cfd70 vcmpe.f32 s12, s11 */
/* @0x1cfd74 vmrs APSR_nzcv, fpscr */
/* @0x1cfd78 bgt 0x1cfd9c <_Z11HandleOtherv+0x1808> */
/* @0x1cfd7c vcvt.s32.f32 s14, s11 */
/* @0x1cfd80 b 0x1ceb24 <_Z11HandleOtherv+0x590> */
/* @0x1cfd84 vcmpe.f32 s14, s11 */
/* @0x1cfd88 vmrs APSR_nzcv, fpscr */
/* @0x1cfd8c ble 0x1cfd7c <_Z11HandleOtherv+0x17e8> */
/* @0x1cfd90 vcmpe.f32 s12, s14 */
/* @0x1cfd94 vmrs APSR_nzcv, fpscr */
/* @0x1cfd98 ble 0x1d003c <_Z11HandleOtherv+0x1aa8> */
/* @0x1cfd9c vcvt.s32.f32 s14, s12 */
/* @0x1cfda0 b 0x1ceb24 <_Z11HandleOtherv+0x590> */
/* @0x1cfda4 vcmpe.f32 s15, s9 */
/* @0x1cfda8 vmrs APSR_nzcv, fpscr */
/* @0x1cfdac ble 0x1cfe14 <_Z11HandleOtherv+0x1880> */
/* @0x1cfdb0 vcmpe.f32 s13, s15 */
/* @0x1cfdb4 vmrs APSR_nzcv, fpscr */
/* @0x1cfdb8 vmovle.f32 s14, s15 */
/* @0x1cfdbc bgt 0x1ceb48 <_Z11HandleOtherv+0x5b4> */
/* @0x1cfdc0 vcmpe.f32 s14, s10 */
/* @0x1cfdc4 vmrs APSR_nzcv, fpscr */
/* @0x1cfdc8 ble 0x1ceb54 <_Z11HandleOtherv+0x5c0> */
/* @0x1cfdcc vcmpe.f32 s13, s15 */
/* @0x1cfdd0 vmrs APSR_nzcv, fpscr */
/* @0x1cfdd4 ble 0x1cfdec <_Z11HandleOtherv+0x1858> */
/* @0x1cfdd8 vcmpe.f32 s13, s9 */
/* @0x1cfddc vmrs APSR_nzcv, fpscr */
/* @0x1cfde0 bgt 0x1cfe04 <_Z11HandleOtherv+0x1870> */
/* @0x1cfde4 vcvt.s32.f32 s13, s9 */
/* @0x1cfde8 b 0x1ceb58 <_Z11HandleOtherv+0x5c4> */
/* @0x1cfdec vcmpe.f32 s15, s9 */
/* @0x1cfdf0 vmrs APSR_nzcv, fpscr */
/* @0x1cfdf4 ble 0x1cfde4 <_Z11HandleOtherv+0x1850> */
/* @0x1cfdf8 vcmpe.f32 s13, s15 */
/* @0x1cfdfc vmrs APSR_nzcv, fpscr */
/* @0x1cfe00 ble 0x1d002c <_Z11HandleOtherv+0x1a98> */
/* @0x1cfe04 vcvt.s32.f32 s13, s13 */
/* @0x1cfe08 b 0x1ceb58 <_Z11HandleOtherv+0x5c4> */
/* @0x1cfe0c vmov.f32 s7, s11 */
/* @0x1cfe10 b 0x1cfd58 <_Z11HandleOtherv+0x17c4> */
/* @0x1cfe14 vmov.f32 s14, s9 */
/* @0x1cfe18 b 0x1cfdc0 <_Z11HandleOtherv+0x182c> */
/* @0x1cfe1c vmov.f32 s7, s9 */
/* @0x1cfe20 b 0x1cfcf0 <_Z11HandleOtherv+0x175c> */
/* @0x1cfe24 add r0, sp, #216 */
/* @0x1cfe28 vldr s15, [r9] */
/* @0x1cfe2c vldr s14, [r5] */
/* @0x1cfe30 vldr s13, [r11] */
/* @0x1cfe34 str r1, [r6, r0] */
/* @0x1cfe38 add r0, sp, #184 */
/* @0x1cfe3c vldr s12, [r10] */
/* @0x1cfe40 vldr s11, [r5, #16] */
/* @0x1cfe44 str r1, [r6, r0] */
/* @0x1cfe48 add r0, sp, #152 */
/* @0x1cfe4c vldr s10, [r5, #20] */
/* @0x1cfe50 vldr s8, [r8] */
/* @0x1cfe54 str r1, [r6, r0] */
/* @0x1cfe58 add r0, sp, #120 */
/* @0x1cfe5c vldr s9, [r5, #28] */
/* @0x1cfe60 str r1, [r6, r0] */
/* @0x1cfe64 b 0x1ced5c <_Z11HandleOtherv+0x7c8> */
/* @0x1cfe68 vcmpe.f32 s13, s10 */
/* @0x1cfe6c vmrs APSR_nzcv, fpscr */
/* @0x1cfe70 bpl 0x1cffa8 <_Z11HandleOtherv+0x1a14> */
/* @0x1cfe74 vcmpe.f32 s12, s13 */
/* @0x1cfe78 vmrs APSR_nzcv, fpscr */
/* @0x1cfe7c vmovpl.f32 s7, s13 */
/* @0x1cfe80 bmi 0x1cfb84 <_Z11HandleOtherv+0x15f0> */
/* @0x1cfe84 vcmpe.f32 s7, s9 */
/* @0x1cfe88 vmrs APSR_nzcv, fpscr */
/* @0x1cfe8c bpl 0x1cfb90 <_Z11HandleOtherv+0x15fc> */
/* @0x1cfe90 vcmpe.f32 s12, s13 */
/* @0x1cfe94 vmrs APSR_nzcv, fpscr */
/* @0x1cfe98 bpl 0x1cfeb0 <_Z11HandleOtherv+0x191c> */
/* @0x1cfe9c vcmpe.f32 s12, s10 */
/* @0x1cfea0 vmrs APSR_nzcv, fpscr */
/* @0x1cfea4 bpl 0x1cffd0 <_Z11HandleOtherv+0x1a3c> */
/* @0x1cfea8 vcvt.s32.f32 s7, s12 */
/* @0x1cfeac b 0x1cfb94 <_Z11HandleOtherv+0x1600> */
/* @0x1cfeb0 vcmpe.f32 s13, s10 */
/* @0x1cfeb4 vmrs APSR_nzcv, fpscr */
/* @0x1cfeb8 bpl 0x1cffd0 <_Z11HandleOtherv+0x1a3c> */
/* @0x1cfebc vcmpe.f32 s12, s13 */
/* @0x1cfec0 vmrs APSR_nzcv, fpscr */
/* @0x1cfec4 bmi 0x1cfea8 <_Z11HandleOtherv+0x1914> */
/* @0x1cfec8 vcvt.s32.f32 s7, s13 */
/* @0x1cfecc b 0x1cfb94 <_Z11HandleOtherv+0x1600> */
/* @0x1cfed0 vcmpe.f32 s15, s11 */
/* @0x1cfed4 vmrs APSR_nzcv, fpscr */
/* @0x1cfed8 ble 0x1cffb0 <_Z11HandleOtherv+0x1a1c> */
/* @0x1cfedc vcmpe.f32 s14, s15 */
/* @0x1cfee0 vmrs APSR_nzcv, fpscr */
/* @0x1cfee4 vmovle.f32 s7, s15 */
/* @0x1cfee8 bgt 0x1cfbb8 <_Z11HandleOtherv+0x1624> */
/* @0x1cfeec vcmpe.f32 s7, s8 */
/* @0x1cfef0 vmrs APSR_nzcv, fpscr */
/* @0x1cfef4 ble 0x1cfbc4 <_Z11HandleOtherv+0x1630> */
/* @0x1cfef8 vcmpe.f32 s14, s15 */
/* @0x1cfefc vmrs APSR_nzcv, fpscr */
/* @0x1cff00 ble 0x1cff18 <_Z11HandleOtherv+0x1984> */
/* @0x1cff04 vcmpe.f32 s14, s11 */
/* @0x1cff08 vmrs APSR_nzcv, fpscr */
/* @0x1cff0c ble 0x1cffc8 <_Z11HandleOtherv+0x1a34> */
/* @0x1cff10 vcvt.s32.f32 s7, s14 */
/* @0x1cff14 b 0x1cfbc8 <_Z11HandleOtherv+0x1634> */
/* @0x1cff18 vcmpe.f32 s15, s11 */
/* @0x1cff1c vmrs APSR_nzcv, fpscr */
/* @0x1cff20 ble 0x1cffc8 <_Z11HandleOtherv+0x1a34> */
/* @0x1cff24 vcmpe.f32 s14, s15 */
/* @0x1cff28 vmrs APSR_nzcv, fpscr */
/* @0x1cff2c bgt 0x1cff10 <_Z11HandleOtherv+0x197c> */
/* @0x1cff30 vcvt.s32.f32 s7, s15 */
/* @0x1cff34 b 0x1cfbc8 <_Z11HandleOtherv+0x1634> */
/* @0x1cff38 vcmpe.f32 s13, s10 */
/* @0x1cff3c vmrs APSR_nzcv, fpscr */
/* @0x1cff40 ble 0x1cffb8 <_Z11HandleOtherv+0x1a24> */
/* @0x1cff44 vcmpe.f32 s12, s13 */
/* @0x1cff48 vmrs APSR_nzcv, fpscr */
/* @0x1cff4c vmovle.f32 s7, s13 */
/* @0x1cff50 bgt 0x1cfbec <_Z11HandleOtherv+0x1658> */
/* @0x1cff54 vcmpe.f32 s7, s9 */
/* @0x1cff58 vmrs APSR_nzcv, fpscr */
/* @0x1cff5c ble 0x1cfbf8 <_Z11HandleOtherv+0x1664> */
/* @0x1cff60 vcmpe.f32 s12, s13 */
/* @0x1cff64 vmrs APSR_nzcv, fpscr */
/* @0x1cff68 ble 0x1cff80 <_Z11HandleOtherv+0x19ec> */
/* @0x1cff6c vcmpe.f32 s12, s10 */
/* @0x1cff70 vmrs APSR_nzcv, fpscr */
/* @0x1cff74 ble 0x1cffc0 <_Z11HandleOtherv+0x1a2c> */
/* @0x1cff78 vcvt.s32.f32 s7, s12 */
/* @0x1cff7c b 0x1cfbfc <_Z11HandleOtherv+0x1668> */
/* @0x1cff80 vcmpe.f32 s13, s10 */
/* @0x1cff84 vmrs APSR_nzcv, fpscr */
/* @0x1cff88 ble 0x1cffc0 <_Z11HandleOtherv+0x1a2c> */
/* @0x1cff8c vcmpe.f32 s12, s13 */
/* @0x1cff90 vmrs APSR_nzcv, fpscr */
/* @0x1cff94 bgt 0x1cff78 <_Z11HandleOtherv+0x19e4> */
/* @0x1cff98 vcvt.s32.f32 s7, s13 */
/* @0x1cff9c b 0x1cfbfc <_Z11HandleOtherv+0x1668> */
/* @0x1cffa0 vmov.f32 s13, s11 */
/* @0x1cffa4 b 0x1cfc44 <_Z11HandleOtherv+0x16b0> */
/* @0x1cffa8 vmov.f32 s7, s10 */
/* @0x1cffac b 0x1cfe84 <_Z11HandleOtherv+0x18f0> */
/* @0x1cffb0 vmov.f32 s7, s11 */
/* @0x1cffb4 b 0x1cfeec <_Z11HandleOtherv+0x1958> */
/* @0x1cffb8 vmov.f32 s7, s10 */
/* @0x1cffbc b 0x1cff54 <_Z11HandleOtherv+0x19c0> */
/* @0x1cffc0 vcvt.s32.f32 s7, s10 */
/* @0x1cffc4 b 0x1cfbfc <_Z11HandleOtherv+0x1668> */
/* @0x1cffc8 vcvt.s32.f32 s7, s11 */
/* @0x1cffcc b 0x1cfbc8 <_Z11HandleOtherv+0x1634> */
/* @0x1cffd0 vcvt.s32.f32 s7, s10 */
/* @0x1cffd4 b 0x1cfb94 <_Z11HandleOtherv+0x1600> */
/* @0x1cffd8 vcvt.s32.f32 s10, s11 */
/* @0x1cffdc b 0x1cfb54 <_Z11HandleOtherv+0x15c0> */
/* @0x1cffe0 mov r0, r5 */
/* @0x1cffe4 mov r1, #1 */
/* @0x1cffe8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cffec b 0x1cf390 <_Z11HandleOtherv+0xdfc> */
/* @0x1cfff0 ldr r3, [pc, #0xb4] */
/* @0x1cfff4 ldr r12, [sp, #0x40] */
/* @0x1cfff8 ldr r0, [r12, r3] */
/* @0x1cfffc add sp, sp, #828 */
/* @0x1d0000 vpop {d8, d9, d10, d11} */
/* @0x1d0004 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d0008 b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1d000c ldr r3, [pc, #0x98] */
/* @0x1d0010 mov r1, #6 */
/* @0x1d0014 mov r2, #10 */
/* @0x1d0018 ldr r0, [r12, r3] */
/* @0x1d001c bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1d0020 b 0x1ce5c4 <_Z11HandleOtherv+0x30> */
/* @0x1d0024 vcvt.s32.f32 s7, s14 */
/* @0x1d0028 b 0x1ceabc <_Z11HandleOtherv+0x528> */
/* @0x1d002c vcvt.s32.f32 s13, s15 */
/* @0x1d0030 b 0x1ceb58 <_Z11HandleOtherv+0x5c4> */
/* @0x1d0034 vcvt.s32.f32 s7, s15 */
/* @0x1d0038 b 0x1ceaf0 <_Z11HandleOtherv+0x55c> */
/* @0x1d003c vcvt.s32.f32 s14, s14 */
/* @0x1d0040 b 0x1ceb24 <_Z11HandleOtherv+0x590> */
/* @0x1d0044 ldr r1, [pc, #0x64] */
/* @0x1d0048 ldr r12, [sp, #0x40] */
/* @0x1d004c strd r2, r3, [sp, #8] */
/* @0x1d0050 ldr r3, [r12, r1] */
/* @0x1d0054 str r3, [sp, #0x3c] */
/* @0x1d0058 b 0x1ce784 <_Z11HandleOtherv+0x1f0> */
/* @0x1d005c vldr s15, [r9, #240] */
/* @0x1d0060 vldr s14, [r9, #232] */
/* @0x1d0064 b 0x1cf004 <_Z11HandleOtherv+0xa70> */
/* @0x1d0068 vldr s14, [r5, #232] */
/* @0x1d006c b 0x1cf580 <_Z11HandleOtherv+0xfec> */
/* @0x1d0070 vldr s13, [r5, #240] */
/* @0x1d0074 vldr s14, [r5, #232] */
/* @0x1d0078 b 0x1cf578 <_Z11HandleOtherv+0xfe4> */
/* @0x1d007c vldr s14, [r5, #232] */
/* @0x1d0080 vldr s15, [r5, #236] */
/* @0x1d0084 b 0x1cf570 <_Z11HandleOtherv+0xfdc> */
/* @0x1d0088 vldr s14, [r5, #232] */
/* @0x1d008c b 0x1cf58c <_Z11HandleOtherv+0xff8> */
/* @0x1d0090 vldr s15, [r5, #236] */
/* @0x1d0094 b 0x1cf55c <_Z11HandleOtherv+0xfc8> */
/* @0x1d0098 vldr s14, [r9, #232] */
/* @0x1d009c vldr s13, [r9, #236] */
/* @0x1d00a0 b 0x1ceffc <_Z11HandleOtherv+0xa68> */
/* @0x1d00a4 vldr s14, [r5, #232] */
/* @0x1d00a8 b 0x1cf564 <_Z11HandleOtherv+0xfd0> */
/* @0x1d00ac .word 0xffffbf1c */
/* @0x1d00b0 .word 0xffffbcd8 */

/* ── FUNC 0x1d00b4 · HandleTimeLine() · size=728 · insn=182 */
/* @0x1d00b4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d00b8 vpush {d8, d9} */
/* @0x1d00bc ldr r3, [pc, #0x2c0] */
/* @0x1d00c0 ldr r1, [pc, #0x2c0] */
/* @0x1d00c4 ldr r3, [pc, r3] */
/* @0x1d00c8 ldr r1, [pc, r1] */
/* @0x1d00cc ldr r3, [r3] */
/* @0x1d00d0 ldrd r4, r5, [r1] */
/* @0x1d00d4 ldr r6, [r3, #0x80] */
/* @0x1d00d8 adds r2, r4, #1 */
/* @0x1d00dc adc r3, r5, #0 */
/* @0x1d00e0 strd r2, r3, [r1] */
/* @0x1d00e4 cmp r6, #0 */
/* @0x1d00e8 beq 0x1d01f4 <_Z14HandleTimeLinev+0x140> */
/* @0x1d00ec vldr s17, [pc, #652] */
/* @0x1d00f0 ldrb r3, [r6, #0x68] */
/* @0x1d00f4 ldr r7, [r6, #0x178] */
/* @0x1d00f8 cmp r3, #0 */
/* @0x1d00fc bne 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d0100 ldrb r3, [r6, #0x69] */
/* @0x1d0104 cmp r3, #0 */
/* @0x1d0108 bne 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d010c ldrd r2, r3, [r6, #112] */
/* @0x1d0110 cmp r4, r2 */
/* @0x1d0114 sbcs r1, r5, r3 */
/* @0x1d0118 blt 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d011c ldrb r3, [r6, #0x15c] */
/* @0x1d0120 cmp r3, #0 */
/* @0x1d0124 beq 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d0128 ldr r9, [r6, #0x14c] */
/* @0x1d012c cmp r9, #0 */
/* @0x1d0130 blt 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d0134 mov r0, r9 */
/* @0x1d0138 bl 0x1f2c48 <_Z13TimeLine_Datai> */
/* @0x1d013c subs r10, r0, #0 */
/* @0x1d0140 beq 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d0144 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv> */
/* @0x1d0148 cmp r0, #0 */
/* @0x1d014c ble 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d0150 vldr s15, [r6, #344] */
/* @0x1d0154 vcmp.f32 s15, #0 */
/* @0x1d0158 vmrs APSR_nzcv, fpscr */
/* @0x1d015c beq 0x1d01fc <_Z14HandleTimeLinev+0x148> */
/* @0x1d0160 vcmpe.f32 s15, #0 */
/* @0x1d0164 vldr s16, [r6, #340] */
/* @0x1d0168 mov r0, r10 */
/* @0x1d016c vcvt.f64.f32 d7, s16 */
/* @0x1d0170 vmrs APSR_nzcv, fpscr */
/* @0x1d0174 vmov r2, r3, d7 */
/* @0x1d0178 ble 0x1d02e0 <_Z14HandleTimeLinev+0x22c> */
/* @0x1d017c bl 0x1f1c70 <_ZN9CTimeLine10FindLargerEd> */
/* @0x1d0180 vldr s18, [r6, #344] */
/* @0x1d0184 vadd.f32 s18, s16, s18 */
/* @0x1d0188 vcvt.f64.f32 d6, s18 */
/* @0x1d018c vmov r2, r3, d6 */
/* @0x1d0190 mov r8, r0 */
/* @0x1d0194 mov r0, r10 */
/* @0x1d0198 bl 0x1f1c70 <_ZN9CTimeLine10FindLargerEd> */
/* @0x1d019c cmp r8, r0 */
/* @0x1d01a0 mov r11, r0 */
/* @0x1d01a4 bge 0x1d01c8 <_Z14HandleTimeLinev+0x114> */
/* @0x1d01a8 mov r3, r8 */
/* @0x1d01ac mov r0, r6 */
/* @0x1d01b0 mov r1, r6 */
/* @0x1d01b4 mov r2, r9 */
/* @0x1d01b8 add r8, r8, #1 */
/* @0x1d01bc bl 0xf30ec <_Z22Perform_Event_TimeLineP9CInstanceS0_ii> */
/* @0x1d01c0 cmp r8, r11 */
/* @0x1d01c4 bne 0x1d01a8 <_Z14HandleTimeLinev+0xf4> */
/* @0x1d01c8 vldr s15, [r6, #340] */
/* @0x1d01cc vcmp.f32 s16, s15 */
/* @0x1d01d0 ldrb r3, [r6, #0x15d] */
/* @0x1d01d4 vstr s16, [r6, #336] */
/* @0x1d01d8 vmrs APSR_nzcv, fpscr */
/* @0x1d01dc vstreq s18, [r6, #340] */
/* @0x1d01e0 cmp r3, #0 */
/* @0x1d01e4 bne 0x1d02ac <_Z14HandleTimeLinev+0x1f8> */
/* @0x1d01e8 cmp r7, #0 */
/* @0x1d01ec movne r6, r7 */
/* @0x1d01f0 bne 0x1d00f0 <_Z14HandleTimeLinev+0x3c> */
/* @0x1d01f4 vpop {d8, d9} */
/* @0x1d01f8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d01fc vldr s15, [r6, #336] */
/* @0x1d0200 vcvt.f64.f32 d6, s15 */
/* @0x1d0204 mov r0, r10 */
/* @0x1d0208 vmov r2, r3, d6 */
/* @0x1d020c bl 0x1f1c70 <_ZN9CTimeLine10FindLargerEd> */
/* @0x1d0210 vldr s16, [r6, #340] */
/* @0x1d0214 vldr s18, [r6, #344] */
/* @0x1d0218 vadd.f32 s18, s16, s18 */
/* @0x1d021c vcvt.f64.f32 d7, s18 */
/* @0x1d0220 vmov r2, r3, d7 */
/* @0x1d0224 mov r8, r0 */
/* @0x1d0228 mov r0, r10 */
/* @0x1d022c bl 0x1f1c70 <_ZN9CTimeLine10FindLargerEd> */
/* @0x1d0230 cmp r8, r0 */
/* @0x1d0234 mov r11, r0 */
/* @0x1d0238 bge 0x1d025c <_Z14HandleTimeLinev+0x1a8> */
/* @0x1d023c mov r3, r8 */
/* @0x1d0240 mov r0, r6 */
/* @0x1d0244 mov r1, r6 */
/* @0x1d0248 mov r2, r9 */
/* @0x1d024c add r8, r8, #1 */
/* @0x1d0250 bl 0xf30ec <_Z22Perform_Event_TimeLineP9CInstanceS0_ii> */
/* @0x1d0254 cmp r8, r11 */
/* @0x1d0258 bne 0x1d023c <_Z14HandleTimeLinev+0x188> */
/* @0x1d025c vldr s15, [r6, #340] */
/* @0x1d0260 vcmp.f32 s16, s15 */
/* @0x1d0264 ldrb r3, [r6, #0x15d] */
/* @0x1d0268 vstr s16, [r6, #336] */
/* @0x1d026c vmrs APSR_nzcv, fpscr */
/* @0x1d0270 vstreq s18, [r6, #340] */
/* @0x1d0274 cmp r3, #0 */
/* @0x1d0278 beq 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d027c mov r0, r10 */
/* @0x1d0280 vldr s16, [r6, #340] */
/* @0x1d0284 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv> */
/* @0x1d0288 sub r1, r0, #1 */
/* @0x1d028c mov r0, r10 */
/* @0x1d0290 bl 0x1f1738 <_ZN9CTimeLine7GetStepEi> */
/* @0x1d0294 vmov s12, r0 */
/* @0x1d0298 vcvt.f32.s32 s15, s12 */
/* @0x1d029c vcmpe.f32 s16, s15 */
/* @0x1d02a0 vmrs APSR_nzcv, fpscr */
/* @0x1d02a4 bgt 0x1d02d8 <_Z14HandleTimeLinev+0x224> */
/* @0x1d02a8 b 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d02ac mov r0, r10 */
/* @0x1d02b0 vldr s16, [r6, #340] */
/* @0x1d02b4 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv> */
/* @0x1d02b8 sub r1, r0, #1 */
/* @0x1d02bc mov r0, r10 */
/* @0x1d02c0 bl 0x1f1738 <_ZN9CTimeLine7GetStepEi> */
/* @0x1d02c4 vmov s13, r0 */
/* @0x1d02c8 vcvt.f32.s32 s15, s13 */
/* @0x1d02cc vcmpe.f32 s16, s15 */
/* @0x1d02d0 vmrs APSR_nzcv, fpscr */
/* @0x1d02d4 ble 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d02d8 vstr s17, [r6, #340] */
/* @0x1d02dc b 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d02e0 bl 0x1f1d04 <_ZN9CTimeLine11FindSmallerEd> */
/* @0x1d02e4 vldr s18, [r6, #344] */
/* @0x1d02e8 vadd.f32 s18, s16, s18 */
/* @0x1d02ec vcvt.f64.f32 d6, s18 */
/* @0x1d02f0 vmov r2, r3, d6 */
/* @0x1d02f4 mov r8, r0 */
/* @0x1d02f8 mov r0, r10 */
/* @0x1d02fc bl 0x1f1c70 <_ZN9CTimeLine10FindLargerEd> */
/* @0x1d0300 cmp r8, r0 */
/* @0x1d0304 mov r11, r0 */
/* @0x1d0308 ble 0x1d032c <_Z14HandleTimeLinev+0x278> */
/* @0x1d030c mov r3, r8 */
/* @0x1d0310 mov r0, r6 */
/* @0x1d0314 mov r1, r6 */
/* @0x1d0318 mov r2, r9 */
/* @0x1d031c sub r8, r8, #1 */
/* @0x1d0320 bl 0xf30ec <_Z22Perform_Event_TimeLineP9CInstanceS0_ii> */
/* @0x1d0324 cmp r8, r11 */
/* @0x1d0328 bne 0x1d030c <_Z14HandleTimeLinev+0x258> */
/* @0x1d032c vldr s15, [r6, #340] */
/* @0x1d0330 vcmp.f32 s16, s15 */
/* @0x1d0334 ldrb r3, [r6, #0x15d] */
/* @0x1d0338 vstr s16, [r6, #336] */
/* @0x1d033c vmrs APSR_nzcv, fpscr */
/* @0x1d0340 vstreq s18, [r6, #340] */
/* @0x1d0344 cmp r3, #0 */
/* @0x1d0348 beq 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d034c vldr s15, [r6, #340] */
/* @0x1d0350 vcmpe.f32 s15, #0 */
/* @0x1d0354 vmrs APSR_nzcv, fpscr */
/* @0x1d0358 bpl 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d035c mov r0, r10 */
/* @0x1d0360 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv> */
/* @0x1d0364 sub r1, r0, #1 */
/* @0x1d0368 mov r0, r10 */
/* @0x1d036c bl 0x1f1738 <_ZN9CTimeLine7GetStepEi> */
/* @0x1d0370 vmov s13, r0 */
/* @0x1d0374 vcvt.f32.s32 s15, s13 */
/* @0x1d0378 vstr s15, [r6, #340] */
/* @0x1d037c b 0x1d01e8 <_Z14HandleTimeLinev+0x134> */
/* @0x1d0380 andeq r0, r0, r0 */
/* @0x1d0384 eoreq sp, r1, r4, ror #16 */
/* @0x1d0388 eoreq pc, r1, r12, lsr r10 */

/* ── FUNC 0x1d038c · Get_SaveGameVersion() · size=16 · insn=4 */
/* @0x1d038c ldr r3, [pc, #0x4] */
/* @0x1d0390 ldr r0, [pc, r3] */
/* @0x1d0394 bx lr */
/* @0x1d0398 eoreq r4, r2, r0, lsl #27 */

/* ── FUNC 0x1d039c · GlobalState_DeSerialise(IBuffer*) · size=1068 · insn=267 */
/* @0x1d039c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1d03a0 add r7, r0, #44 */
/* @0x1d03a4 ldr r3, [r0] */
/* @0x1d03a8 mov r1, #6 */
/* @0x1d03ac mov r2, r7 */
/* @0x1d03b0 mov r6, r0 */
/* @0x1d03b4 ldr r8, [pc, #0x3c0] */
/* @0x1d03b8 ldr r3, [r3, #0xc] */
/* @0x1d03bc blx r3 */
/* @0x1d03c0 mov r0, r7 */
/* @0x1d03c4 mov r1, #0 */
/* @0x1d03c8 add r8, pc, r8 */
/* @0x1d03cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1d03d0 ldr r3, [pc, #0x3a8] */
/* @0x1d03d4 movw r2, #0x353 */
/* @0x1d03d8 add r3, pc, r3 */
/* @0x1d03dc cmp r0, r2 */
/* @0x1d03e0 str r0, [r3] */
/* @0x1d03e4 movne r3, #0 */
/* @0x1d03e8 beq 0x1d03f4 <_Z23GlobalState_DeSerialiseP7IBuffer+0x58> */
/* @0x1d03ec mov r0, r3 */
/* @0x1d03f0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d03f4 ldr r3, [r6] */
/* @0x1d03f8 mov r2, r7 */
/* @0x1d03fc mov r1, #6 */
/* @0x1d0400 mov r0, r6 */
/* @0x1d0404 ldr r3, [r3, #0xc] */
/* @0x1d0408 blx r3 */
/* @0x1d040c mov r1, #0 */
/* @0x1d0410 mov r0, r7 */
/* @0x1d0414 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1d0418 ldr r12, [pc, #0x364] */
/* @0x1d041c ldr r3, [r6] */
/* @0x1d0420 mov r2, r7 */
/* @0x1d0424 mov r1, #6 */
/* @0x1d0428 ldr r12, [r8, r12] */
/* @0x1d042c ldr r3, [r3, #0xc] */
/* @0x1d0430 str r0, [r12] */
/* @0x1d0434 mov r0, r6 */
/* @0x1d0438 blx r3 */
/* @0x1d043c mov r1, #0 */
/* @0x1d0440 mov r0, r7 */
/* @0x1d0444 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1d0448 ldr r12, [pc, #0x338] */
/* @0x1d044c ldr r3, [r6] */
/* @0x1d0450 mov r2, r7 */
/* @0x1d0454 mov r1, #6 */
/* @0x1d0458 ldr r12, [r8, r12] */
/* @0x1d045c ldr r3, [r3, #0xc] */
/* @0x1d0460 str r0, [r12] */
/* @0x1d0464 mov r0, r6 */
/* @0x1d0468 blx r3 */
/* @0x1d046c mov r1, #0 */
/* @0x1d0470 mov r0, r7 */
/* @0x1d0474 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1d0478 ldr r12, [pc, #0x30c] */
/* @0x1d047c ldr r3, [r6] */
/* @0x1d0480 mov r2, r7 */
/* @0x1d0484 mov r1, #6 */
/* @0x1d0488 ldr r12, [r8, r12] */
/* @0x1d048c ldr r3, [r3, #0xc] */
/* @0x1d0490 str r0, [r12] */
/* @0x1d0494 mov r0, r6 */
/* @0x1d0498 blx r3 */
/* @0x1d049c mov r1, #0 */
/* @0x1d04a0 mov r0, r7 */
/* @0x1d04a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1d04a8 ldr r12, [pc, #0x2e0] */
/* @0x1d04ac ldr r3, [r6] */
/* @0x1d04b0 mov r2, r7 */
/* @0x1d04b4 mov r1, #6 */
/* @0x1d04b8 ldr r12, [r8, r12] */
/* @0x1d04bc ldr r3, [r3, #0xc] */
/* @0x1d04c0 str r0, [r12] */
/* @0x1d04c4 mov r0, r6 */
/* @0x1d04c8 blx r3 */
/* @0x1d04cc mov r1, #0 */
/* @0x1d04d0 mov r0, r7 */
/* @0x1d04d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1d04d8 ldr r12, [pc, #0x2b4] */
/* @0x1d04dc ldr r3, [r6] */
/* @0x1d04e0 mov r2, r7 */
/* @0x1d04e4 mov r1, #6 */
/* @0x1d04e8 ldr r12, [r8, r12] */
/* @0x1d04ec ldr r3, [r3, #0xc] */
/* @0x1d04f0 str r0, [r12] */
/* @0x1d04f4 mov r0, r6 */
/* @0x1d04f8 blx r3 */
/* @0x1d04fc mov r1, #0 */
/* @0x1d0500 mov r0, r7 */
/* @0x1d0504 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1d0508 ldr r12, [pc, #0x288] */
/* @0x1d050c ldr r3, [r6] */
/* @0x1d0510 mov r2, r7 */
/* @0x1d0514 mov r1, #6 */
/* @0x1d0518 ldr r12, [r8, r12] */
/* @0x1d051c ldr r3, [r3, #0xc] */
/* @0x1d0520 strb r0, [r12] */
/* @0x1d0524 mov r0, r6 */
/* @0x1d0528 blx r3 */
/* @0x1d052c mov r1, #0 */
/* @0x1d0530 mov r0, r7 */
/* @0x1d0534 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1d0538 ldr r3, [pc, #0x25c] */
/* @0x1d053c ldr r3, [r8, r3] */
/* @0x1d0540 strb r0, [r3] */
/* @0x1d0544 mov r0, r6 */
/* @0x1d0548 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* @0x1d054c mov r5, r0 */
/* @0x1d0550 mov r0, #12 */
/* @0x1d0554 bl 0x27c524 <_Znwj> */
/* @0x1d0558 mov r4, r0 */
/* @0x1d055c subs r0, r5, #0 */
/* @0x1d0560 beq 0x1d0568 <_Z23GlobalState_DeSerialiseP7IBuffer+0x1cc> */
/* @0x1d0564 bl 0xb6538 <strlen@plt> */
/* @0x1d0568 str r0, [r4, #0x8] */
/* @0x1d056c mov r0, r5 */
/* @0x1d0570 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1d0574 ldr r12, [pc, #0x224] */
/* @0x1d0578 ldr r3, [r6] */
/* @0x1d057c mov r2, #1 */
/* @0x1d0580 str r2, [r4, #0x4] */
/* @0x1d0584 mov r5, #0 */
/* @0x1d0588 mov r2, r7 */
/* @0x1d058c mov r1, #6 */
/* @0x1d0590 str r0, [r4] */
/* @0x1d0594 mov r0, r6 */
/* @0x1d0598 ldr r12, [r8, r12] */
/* @0x1d059c ldr r3, [r3, #0xc] */
/* @0x1d05a0 str r4, [r12] */
/* @0x1d05a4 blx r3 */
/* @0x1d05a8 mov r1, r5 */
/* @0x1d05ac mov r0, r7 */
/* @0x1d05b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1d05b4 ldr r12, [pc, #0x1e8] */
/* @0x1d05b8 ldr r3, [r6] */
/* @0x1d05bc mov r2, r7 */
/* @0x1d05c0 mov r1, #6 */
/* @0x1d05c4 ldr r12, [r8, r12] */
/* @0x1d05c8 ldr r3, [r3, #0xc] */
/* @0x1d05cc str r0, [r12] */
/* @0x1d05d0 mov r0, r6 */
/* @0x1d05d4 blx r3 */
/* @0x1d05d8 mov r1, r5 */
/* @0x1d05dc mov r0, r7 */
/* @0x1d05e0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1d05e4 ldr r3, [pc, #0x1bc] */
/* @0x1d05e8 ldr r3, [r8, r3] */
/* @0x1d05ec strb r0, [r3] */
/* @0x1d05f0 mov r0, r6 */
/* @0x1d05f4 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* @0x1d05f8 mov r5, r0 */
/* @0x1d05fc mov r0, #12 */
/* @0x1d0600 bl 0x27c524 <_Znwj> */
/* @0x1d0604 mov r4, r0 */
/* @0x1d0608 subs r0, r5, #0 */
/* @0x1d060c beq 0x1d0614 <_Z23GlobalState_DeSerialiseP7IBuffer+0x278> */
/* @0x1d0610 bl 0xb6538 <strlen@plt> */
/* @0x1d0614 str r0, [r4, #0x8] */
/* @0x1d0618 mov r0, r5 */
/* @0x1d061c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1d0620 ldr r12, [pc, #0x184] */
/* @0x1d0624 ldr r3, [r6] */
/* @0x1d0628 mov r2, #1 */
/* @0x1d062c str r2, [r4, #0x4] */
/* @0x1d0630 mov r1, #9 */
/* @0x1d0634 mov r2, r7 */
/* @0x1d0638 str r0, [r4] */
/* @0x1d063c mov r0, r6 */
/* @0x1d0640 ldr r12, [r8, r12] */
/* @0x1d0644 ldr r3, [r3, #0xc] */
/* @0x1d0648 str r4, [r12] */
/* @0x1d064c blx r3 */
/* @0x1d0650 ldr r12, [pc, #0x158] */
/* @0x1d0654 ldr r4, [r6, #0x2c] */
/* @0x1d0658 mov r2, r7 */
/* @0x1d065c ldr r3, [r6] */
/* @0x1d0660 mov r1, #6 */
/* @0x1d0664 ldr r12, [r8, r12] */
/* @0x1d0668 mov r0, r6 */
/* @0x1d066c ldr r5, [r6, #0x30] */
/* @0x1d0670 ldr r3, [r3, #0xc] */
/* @0x1d0674 strd r4, r5, [r12] */
/* @0x1d0678 blx r3 */
/* @0x1d067c mov r1, #0 */
/* @0x1d0680 mov r0, r7 */
/* @0x1d0684 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1d0688 ldr r3, [pc, #0x124] */
/* @0x1d068c ldr r3, [r8, r3] */
/* @0x1d0690 strb r0, [r3] */
/* @0x1d0694 mov r0, r6 */
/* @0x1d0698 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* @0x1d069c mov r5, r0 */
/* @0x1d06a0 mov r0, #12 */
/* @0x1d06a4 bl 0x27c524 <_Znwj> */
/* @0x1d06a8 mov r4, r0 */
/* @0x1d06ac subs r0, r5, #0 */
/* @0x1d06b0 beq 0x1d06b8 <_Z23GlobalState_DeSerialiseP7IBuffer+0x31c> */
/* @0x1d06b4 bl 0xb6538 <strlen@plt> */
/* @0x1d06b8 str r0, [r4, #0x8] */
/* @0x1d06bc mov r0, r5 */
/* @0x1d06c0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1d06c4 ldr r12, [pc, #0xec] */
/* @0x1d06c8 ldr r3, [r6] */
/* @0x1d06cc mov r9, #1 */
/* @0x1d06d0 str r9, [r4, #0x4] */
/* @0x1d06d4 mov r5, #0 */
/* @0x1d06d8 mov r2, r7 */
/* @0x1d06dc mov r1, #6 */
/* @0x1d06e0 str r0, [r4] */
/* @0x1d06e4 mov r0, r6 */
/* @0x1d06e8 ldr r12, [r8, r12] */
/* @0x1d06ec ldr r3, [r3, #0xc] */
/* @0x1d06f0 str r4, [r12] */
/* @0x1d06f4 blx r3 */
/* @0x1d06f8 mov r1, r5 */
/* @0x1d06fc mov r0, r7 */
/* @0x1d0700 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1d0704 ldr r12, [pc, #0xb0] */
/* @0x1d0708 ldr r3, [r6] */
/* @0x1d070c mov r2, r7 */
/* @0x1d0710 mov r1, #6 */
/* @0x1d0714 ldr r12, [r8, r12] */
/* @0x1d0718 ldr r3, [r3, #0xc] */
/* @0x1d071c str r0, [r12] */
/* @0x1d0720 mov r0, r6 */
/* @0x1d0724 blx r3 */
/* @0x1d0728 mov r1, r5 */
/* @0x1d072c mov r0, r7 */
/* @0x1d0730 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1d0734 ldr r12, [pc, #0x84] */
/* @0x1d0738 ldr r3, [r6] */
/* @0x1d073c mov r2, r7 */
/* @0x1d0740 mov r1, #6 */
/* @0x1d0744 ldr r12, [r8, r12] */
/* @0x1d0748 ldr r3, [r3, #0xc] */
/* @0x1d074c str r0, [r12] */
/* @0x1d0750 mov r0, r6 */
/* @0x1d0754 blx r3 */
/* @0x1d0758 mov r0, r7 */
/* @0x1d075c mov r1, r5 */
/* @0x1d0760 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1d0764 ldr r2, [pc, #0x58] */
/* @0x1d0768 mov r3, r9 */
/* @0x1d076c ldr r2, [r8, r2] */
/* @0x1d0770 strb r0, [r2] */
/* @0x1d0774 mov r0, r3 */
/* @0x1d0778 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d077c eoreq r1, r2, r8, lsl #17 */
/* @0x1d0780 eoreq r4, r2, r8, lsr sp */
/* @0x1d0784 .word 0xffffeec4 */
/* @0x1d0788 .word 0xffffd784 */
/* @0x1d078c .word 0xffffc154 */
/* @0x1d0790 .word 0xffffc458 */
/* @0x1d0794 .word 0xffffce34 */
/* @0x1d0798 .word 0xffffd99c */
/* @0x1d079c .word 0xffffd998 */
/* @0x1d07a0 .word 0xffffd9a0 */
/* @0x1d07a4 .word 0xffffd780 */
/* @0x1d07a8 .word 0xffffd9a4 */
/* @0x1d07ac .word 0xffffd9a8 */
/* @0x1d07b0 .word 0xffffd788 */
/* @0x1d07b4 .word 0xffffd9ac */
/* @0x1d07b8 .word 0xffffd9b0 */
/* @0x1d07bc .word 0xffffd798 */
/* @0x1d07c0 .word 0xffffebf0 */
/* @0x1d07c4 .word 0xffffc974 */

/* ── FUNC 0x1d07c8 · Command_SaveGame(int) · size=1552 · insn=388 */
/* @0x1d07c8 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d07cc bl 0xc6720 <_Z10GetIBufferi> */
/* @0x1d07d0 ldr r7, [pc, #0x594] */
/* @0x1d07d4 add r7, pc, r7 */
/* @0x1d07d8 subs r6, r0, #0 */
/* @0x1d07dc beq 0x1d0d34 <_Z16Command_SaveGamei+0x56c> */
/* @0x1d07e0 ldr r12, [r6] */
/* @0x1d07e4 add r8, r6, #44 */
/* @0x1d07e8 mov r9, #0 */
/* @0x1d07ec mov r1, #6 */
/* @0x1d07f0 str r9, [r6, #0x2c] */
/* @0x1d07f4 mov r2, r8 */
/* @0x1d07f8 mov r3, #38912 */
/* @0x1d07fc str r9, [r6, #0x38] */
/* @0x1d0800 movt r3, #0x408a */
/* @0x1d0804 str r3, [r6, #0x30] */
/* @0x1d0808 ldr r3, [r12, #0x8] */
/* @0x1d080c blx r3 */
/* @0x1d0810 ldr r12, [pc, #0x558] */
/* @0x1d0814 ldr r3, [r6] */
/* @0x1d0818 mov r2, r8 */
/* @0x1d081c mov r1, #6 */
/* @0x1d0820 mov r0, r6 */
/* @0x1d0824 ldr r12, [r7, r12] */
/* @0x1d0828 str r9, [r6, #0x38] */
/* @0x1d082c ldr r4, [r12] */
/* @0x1d0830 vmov s15, r4 */
/* @0x1d0834 vcvt.f64.s32 d7, s15 */
/* @0x1d0838 vmov r4, r5, d7 */
/* @0x1d083c vstr s14, [r6, #44] */
/* @0x1d0840 str r5, [r6, #0x30] */
/* @0x1d0844 ldr r3, [r3, #0x8] */
/* @0x1d0848 blx r3 */
/* @0x1d084c ldr r12, [pc, #0x520] */
/* @0x1d0850 ldr r3, [r6] */
/* @0x1d0854 mov r2, r8 */
/* @0x1d0858 mov r1, #6 */
/* @0x1d085c mov r0, r6 */
/* @0x1d0860 ldr r12, [r7, r12] */
/* @0x1d0864 str r9, [r6, #0x38] */
/* @0x1d0868 ldr r4, [r12] */
/* @0x1d086c vmov s15, r4 */
/* @0x1d0870 vcvt.f64.s32 d7, s15 */
/* @0x1d0874 vmov r4, r5, d7 */
/* @0x1d0878 vstr s14, [r6, #44] */
/* @0x1d087c str r5, [r6, #0x30] */
/* @0x1d0880 ldr r3, [r3, #0x8] */
/* @0x1d0884 blx r3 */
/* @0x1d0888 ldr r12, [pc, #0x4e8] */
/* @0x1d088c ldr r3, [r6] */
/* @0x1d0890 mov r2, r8 */
/* @0x1d0894 mov r1, #6 */
/* @0x1d0898 mov r0, r6 */
/* @0x1d089c ldr r12, [r7, r12] */
/* @0x1d08a0 str r9, [r6, #0x38] */
/* @0x1d08a4 ldr r4, [r12] */
/* @0x1d08a8 vmov s15, r4 */
/* @0x1d08ac vcvt.f64.s32 d7, s15 */
/* @0x1d08b0 vmov r4, r5, d7 */
/* @0x1d08b4 vstr s14, [r6, #44] */
/* @0x1d08b8 str r5, [r6, #0x30] */
/* @0x1d08bc ldr r3, [r3, #0x8] */
/* @0x1d08c0 blx r3 */
/* @0x1d08c4 ldr r12, [pc, #0x4b0] */
/* @0x1d08c8 ldr r3, [r6] */
/* @0x1d08cc mov r2, r8 */
/* @0x1d08d0 mov r1, #6 */
/* @0x1d08d4 mov r0, r6 */
/* @0x1d08d8 ldr r12, [r7, r12] */
/* @0x1d08dc str r9, [r6, #0x38] */
/* @0x1d08e0 ldr r4, [r12] */
/* @0x1d08e4 vmov s15, r4 */
/* @0x1d08e8 vcvt.f64.s32 d7, s15 */
/* @0x1d08ec vmov r4, r5, d7 */
/* @0x1d08f0 vstr s14, [r6, #44] */
/* @0x1d08f4 str r5, [r6, #0x30] */
/* @0x1d08f8 ldr r3, [r3, #0x8] */
/* @0x1d08fc blx r3 */
/* @0x1d0900 ldr r12, [pc, #0x478] */
/* @0x1d0904 ldr r3, [r6] */
/* @0x1d0908 mov r2, r8 */
/* @0x1d090c mov r1, #6 */
/* @0x1d0910 mov r0, r6 */
/* @0x1d0914 ldr r12, [r7, r12] */
/* @0x1d0918 str r9, [r6, #0x38] */
/* @0x1d091c ldr r4, [r12] */
/* @0x1d0920 vmov s15, r4 */
/* @0x1d0924 vcvt.f64.s32 d7, s15 */
/* @0x1d0928 vmov r4, r5, d7 */
/* @0x1d092c vstr s14, [r6, #44] */
/* @0x1d0930 str r5, [r6, #0x30] */
/* @0x1d0934 ldr r3, [r3, #0x8] */
/* @0x1d0938 blx r3 */
/* @0x1d093c ldr r12, [pc, #0x440] */
/* @0x1d0940 ldr r3, [r6] */
/* @0x1d0944 mov r2, r8 */
/* @0x1d0948 mov r1, #6 */
/* @0x1d094c mov r0, r6 */
/* @0x1d0950 ldr r12, [r7, r12] */
/* @0x1d0954 str r9, [r6, #0x38] */
/* @0x1d0958 ldrb r4, [r12] */
/* @0x1d095c vmov s15, r4 */
/* @0x1d0960 vcvt.f64.u32 d7, s15 */
/* @0x1d0964 vmov r4, r5, d7 */
/* @0x1d0968 vstr s14, [r6, #44] */
/* @0x1d096c str r5, [r6, #0x30] */
/* @0x1d0970 ldr r3, [r3, #0x8] */
/* @0x1d0974 blx r3 */
/* @0x1d0978 ldr r12, [pc, #0x408] */
/* @0x1d097c ldr r3, [r6] */
/* @0x1d0980 mov r2, r8 */
/* @0x1d0984 mov r0, r6 */
/* @0x1d0988 mov r1, #6 */
/* @0x1d098c ldr r12, [r7, r12] */
/* @0x1d0990 str r9, [r6, #0x38] */
/* @0x1d0994 ldrb r4, [r12] */
/* @0x1d0998 vmov s15, r4 */
/* @0x1d099c vcvt.f64.u32 d7, s15 */
/* @0x1d09a0 vmov r4, r5, d7 */
/* @0x1d09a4 vstr s14, [r6, #44] */
/* @0x1d09a8 str r5, [r6, #0x30] */
/* @0x1d09ac ldr r3, [r3, #0x8] */
/* @0x1d09b0 blx r3 */
/* @0x1d09b4 ldr r3, [pc, #0x3d0] */
/* @0x1d09b8 ldr r3, [r7, r3] */
/* @0x1d09bc ldr r3, [r3] */
/* @0x1d09c0 cmp r3, r9 */
/* @0x1d09c4 beq 0x1d0d54 <_Z16Command_SaveGamei+0x58c> */
/* @0x1d09c8 ldr r1, [r3] */
/* @0x1d09cc mov r0, r6 */
/* @0x1d09d0 mov r9, #0 */
/* @0x1d09d4 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x1d09d8 ldr r2, [pc, #0x3b0] */
/* @0x1d09dc ldr r3, [r6] */
/* @0x1d09e0 mov r1, #6 */
/* @0x1d09e4 mov r0, r6 */
/* @0x1d09e8 ldr r12, [r7, r2] */
/* @0x1d09ec mov r2, r8 */
/* @0x1d09f0 str r9, [r6, #0x38] */
/* @0x1d09f4 ldr r4, [r12] */
/* @0x1d09f8 vmov s15, r4 */
/* @0x1d09fc vcvt.f64.s32 d7, s15 */
/* @0x1d0a00 vmov r4, r5, d7 */
/* @0x1d0a04 vstr s14, [r6, #44] */
/* @0x1d0a08 str r5, [r6, #0x30] */
/* @0x1d0a0c ldr r3, [r3, #0x8] */
/* @0x1d0a10 blx r3 */
/* @0x1d0a14 ldr r12, [pc, #0x378] */
/* @0x1d0a18 ldr r3, [r6] */
/* @0x1d0a1c mov r0, r6 */
/* @0x1d0a20 mov r1, #6 */
/* @0x1d0a24 mov r2, r8 */
/* @0x1d0a28 ldr r12, [r7, r12] */
/* @0x1d0a2c str r9, [r6, #0x38] */
/* @0x1d0a30 ldrb r4, [r12] */
/* @0x1d0a34 vmov s15, r4 */
/* @0x1d0a38 vcvt.f64.u32 d7, s15 */
/* @0x1d0a3c vmov r4, r5, d7 */
/* @0x1d0a40 vstr s14, [r6, #44] */
/* @0x1d0a44 str r5, [r6, #0x30] */
/* @0x1d0a48 ldr r3, [r3, #0x8] */
/* @0x1d0a4c blx r3 */
/* @0x1d0a50 ldr r3, [pc, #0x340] */
/* @0x1d0a54 ldr r3, [r7, r3] */
/* @0x1d0a58 ldr r3, [r3] */
/* @0x1d0a5c cmp r3, r9 */
/* @0x1d0a60 beq 0x1d0d60 <_Z16Command_SaveGamei+0x598> */
/* @0x1d0a64 ldr r1, [r3] */
/* @0x1d0a68 mov r0, r6 */
/* @0x1d0a6c mov r10, #0 */
/* @0x1d0a70 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x1d0a74 ldr r3, [pc, #0x320] */
/* @0x1d0a78 ldr r12, [r6] */
/* @0x1d0a7c mov r1, #9 */
/* @0x1d0a80 mov r2, r8 */
/* @0x1d0a84 mov r0, r6 */
/* @0x1d0a88 ldr r3, [r7, r3] */
/* @0x1d0a8c str r10, [r6, #0x38] */
/* @0x1d0a90 ldr lr, [r3] */
/* @0x1d0a94 ldr r3, [r3, #0x4] */
/* @0x1d0a98 str lr, [r6, #0x2c] */
/* @0x1d0a9c str r3, [r6, #0x30] */
/* @0x1d0aa0 ldr r3, [r12, #0x8] */
/* @0x1d0aa4 blx r3 */
/* @0x1d0aa8 ldr r12, [pc, #0x2f0] */
/* @0x1d0aac ldr r3, [r6] */
/* @0x1d0ab0 mov r2, r8 */
/* @0x1d0ab4 mov r1, #6 */
/* @0x1d0ab8 mov r0, r6 */
/* @0x1d0abc ldr r12, [r7, r12] */
/* @0x1d0ac0 str r10, [r6, #0x38] */
/* @0x1d0ac4 ldrb r4, [r12] */
/* @0x1d0ac8 vmov s15, r4 */
/* @0x1d0acc vcvt.f64.u32 d7, s15 */
/* @0x1d0ad0 vmov r4, r5, d7 */
/* @0x1d0ad4 vstr s14, [r6, #44] */
/* @0x1d0ad8 str r5, [r6, #0x30] */
/* @0x1d0adc ldr r3, [r3, #0x8] */
/* @0x1d0ae0 blx r3 */
/* @0x1d0ae4 ldr r3, [pc, #0x2b8] */
/* @0x1d0ae8 mov r0, r6 */
/* @0x1d0aec ldr r3, [r7, r3] */
/* @0x1d0af0 ldr r3, [r3] */
/* @0x1d0af4 ldr r1, [r3] */
/* @0x1d0af8 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x1d0afc ldr r12, [pc, #0x2a4] */
/* @0x1d0b00 ldr r3, [r6] */
/* @0x1d0b04 mov r1, #6 */
/* @0x1d0b08 mov r2, r8 */
/* @0x1d0b0c mov r0, r6 */
/* @0x1d0b10 ldr r12, [r7, r12] */
/* @0x1d0b14 str r10, [r6, #0x38] */
/* @0x1d0b18 ldr r4, [r12] */
/* @0x1d0b1c vmov s15, r4 */
/* @0x1d0b20 vcvt.f64.s32 d7, s15 */
/* @0x1d0b24 vmov r4, r5, d7 */
/* @0x1d0b28 vstr s14, [r6, #44] */
/* @0x1d0b2c str r5, [r6, #0x30] */
/* @0x1d0b30 ldr r3, [r3, #0x8] */
/* @0x1d0b34 blx r3 */
/* @0x1d0b38 ldr r12, [pc, #0x26c] */
/* @0x1d0b3c ldr r3, [r6] */
/* @0x1d0b40 mov r1, #6 */
/* @0x1d0b44 mov r2, r8 */
/* @0x1d0b48 mov r0, r6 */
/* @0x1d0b4c ldr r12, [r7, r12] */
/* @0x1d0b50 str r10, [r6, #0x38] */
/* @0x1d0b54 ldr r4, [r12] */
/* @0x1d0b58 vmov s15, r4 */
/* @0x1d0b5c vcvt.f64.s32 d7, s15 */
/* @0x1d0b60 vmov r4, r5, d7 */
/* @0x1d0b64 vstr s14, [r6, #44] */
/* @0x1d0b68 str r5, [r6, #0x30] */
/* @0x1d0b6c ldr r3, [r3, #0x8] */
/* @0x1d0b70 blx r3 */
/* @0x1d0b74 ldr r12, [pc, #0x234] */
/* @0x1d0b78 ldr r3, [r6] */
/* @0x1d0b7c mov r2, r8 */
/* @0x1d0b80 mov r1, #6 */
/* @0x1d0b84 mov r0, r6 */
/* @0x1d0b88 ldr r12, [r7, r12] */
/* @0x1d0b8c str r10, [r6, #0x38] */
/* @0x1d0b90 ldrb r4, [r12] */
/* @0x1d0b94 vmov s15, r4 */
/* @0x1d0b98 vcvt.f64.u32 d7, s15 */
/* @0x1d0b9c vmov r4, r5, d7 */
/* @0x1d0ba0 vstr s14, [r6, #44] */
/* @0x1d0ba4 str r5, [r6, #0x30] */
/* @0x1d0ba8 ldr r3, [r3, #0x8] */
/* @0x1d0bac blx r3 */
/* @0x1d0bb0 mov r0, r6 */
/* @0x1d0bb4 bl 0x1f4a28 <_Z25Variable_Global_SerialiseP7IBuffer> */
/* @0x1d0bb8 ldr r3, [pc, #0x1f4] */
/* @0x1d0bbc mov r1, r6 */
/* @0x1d0bc0 ldr r0, [r7, r3] */
/* @0x1d0bc4 bl 0x16e874 <_ZN14CCameraManager9SerializeEP7IBuffer> */
/* @0x1d0bc8 ldr r12, [pc, #0x1e8] */
/* @0x1d0bcc ldr r3, [r6] */
/* @0x1d0bd0 mov r1, #6 */
/* @0x1d0bd4 mov r2, r8 */
/* @0x1d0bd8 mov r0, r6 */
/* @0x1d0bdc ldr r9, [r7, r12] */
/* @0x1d0be0 vldr s15, [r9] */
/* @0x1d0be4 vcvt.f64.s32 d7, s15 */
/* @0x1d0be8 str r10, [r6, #0x38] */
/* @0x1d0bec vmov r4, r5, d7 */
/* @0x1d0bf0 vstr s14, [r6, #44] */
/* @0x1d0bf4 str r5, [r6, #0x30] */
/* @0x1d0bf8 ldr r3, [r3, #0x8] */
/* @0x1d0bfc blx r3 */
/* @0x1d0c00 ldr r12, [pc, #0x1b4] */
/* @0x1d0c04 ldr r3, [r6] */
/* @0x1d0c08 mov r1, #6 */
/* @0x1d0c0c mov r2, r8 */
/* @0x1d0c10 mov r0, r6 */
/* @0x1d0c14 ldr r12, [r7, r12] */
/* @0x1d0c18 str r10, [r6, #0x38] */
/* @0x1d0c1c ldr r4, [r12] */
/* @0x1d0c20 vmov s15, r4 */
/* @0x1d0c24 vcvt.f64.s32 d7, s15 */
/* @0x1d0c28 vmov r4, r5, d7 */
/* @0x1d0c2c vstr s14, [r6, #44] */
/* @0x1d0c30 str r5, [r6, #0x30] */
/* @0x1d0c34 ldr r3, [r3, #0x8] */
/* @0x1d0c38 blx r3 */
/* @0x1d0c3c ldr r12, [pc, #0x17c] */
/* @0x1d0c40 ldr r3, [r6] */
/* @0x1d0c44 mov r0, r6 */
/* @0x1d0c48 mov r1, #6 */
/* @0x1d0c4c mov r2, r8 */
/* @0x1d0c50 ldr r12, [r7, r12] */
/* @0x1d0c54 str r10, [r6, #0x38] */
/* @0x1d0c58 ldr r4, [r12] */
/* @0x1d0c5c vmov s15, r4 */
/* @0x1d0c60 vcvt.f64.s32 d7, s15 */
/* @0x1d0c64 vmov r4, r5, d7 */
/* @0x1d0c68 vstr s14, [r6, #44] */
/* @0x1d0c6c str r5, [r6, #0x30] */
/* @0x1d0c70 ldr r3, [r3, #0x8] */
/* @0x1d0c74 blx r3 */
/* @0x1d0c78 ldr r3, [r9] */
/* @0x1d0c7c cmp r3, r10 */
/* @0x1d0c80 movgt r11, r10 */
/* @0x1d0c84 ble 0x1d0cfc <_Z16Command_SaveGamei+0x534> */
/* @0x1d0c88 ldr r12, [r9, #0x4] */
/* @0x1d0c8c mov r1, #6 */
/* @0x1d0c90 ldr r3, [r6] */
/* @0x1d0c94 mov r0, r6 */
/* @0x1d0c98 mov r2, r8 */
/* @0x1d0c9c ldr r4, [r12, r10, lsl #2] */
/* @0x1d0ca0 str r11, [r6, #0x38] */
/* @0x1d0ca4 adds r4, r4, #0 */
/* @0x1d0ca8 movne r4, #1 */
/* @0x1d0cac vmov s15, r4 */
/* @0x1d0cb0 vcvt.f64.u32 d7, s15 */
/* @0x1d0cb4 vmov r4, r5, d7 */
/* @0x1d0cb8 vstr s14, [r6, #44] */
/* @0x1d0cbc str r5, [r6, #0x30] */
/* @0x1d0cc0 ldr r3, [r3, #0x8] */
/* @0x1d0cc4 blx r3 */
/* @0x1d0cc8 ldr r3, [r9] */
/* @0x1d0ccc mov r1, r6 */
/* @0x1d0cd0 cmp r10, r3 */
/* @0x1d0cd4 bge 0x1d0cf0 <_Z16Command_SaveGamei+0x528> */
/* @0x1d0cd8 ldr r2, [r9, #0x4] */
/* @0x1d0cdc ldr r0, [r2, r10, lsl #2] */
/* @0x1d0ce0 cmp r0, #0 */
/* @0x1d0ce4 beq 0x1d0cf0 <_Z16Command_SaveGamei+0x528> */
/* @0x1d0ce8 bl 0x1aa228 <_ZN5CRoom9SerialiseEP7IBuffer> */
/* @0x1d0cec ldr r3, [r9] */
/* @0x1d0cf0 add r10, r10, #1 */
/* @0x1d0cf4 cmp r10, r3 */
/* @0x1d0cf8 blt 0x1d0c88 <_Z16Command_SaveGamei+0x4c0> */
/* @0x1d0cfc mov r0, r6 */
/* @0x1d0d00 bl 0x18c698 <_Z21VirtualKeys_SerialiseP7IBuffer> */
/* @0x1d0d04 ldr r3, [pc, #0xb8] */
/* @0x1d0d08 ldr r3, [r7, r3] */
/* @0x1d0d0c ldrb r3, [r3] */
/* @0x1d0d10 cmp r3, #0 */
/* @0x1d0d14 beq 0x1d0d2c <_Z16Command_SaveGamei+0x564> */
/* @0x1d0d18 ldr r3, [pc, #0xa8] */
/* @0x1d0d1c ldr r3, [r7, r3] */
/* @0x1d0d20 ldr r3, [r3] */
/* @0x1d0d24 cmp r3, #0 */
/* @0x1d0d28 beq 0x1d0d3c <_Z16Command_SaveGamei+0x574> */
/* @0x1d0d2c mov r0, #1 */
/* @0x1d0d30 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d0d34 mov r0, r6 */
/* @0x1d0d38 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d0d3c ldr r1, [pc, #0x88] */
/* @0x1d0d40 mov r0, #2 */
/* @0x1d0d44 add r1, pc, r1 */
/* @0x1d0d48 bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x1d0d4c mov r0, #1 */
/* @0x1d0d50 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d0d54 ldr r1, [pc, #0x74] */
/* @0x1d0d58 add r1, pc, r1 */
/* @0x1d0d5c b 0x1d09cc <_Z16Command_SaveGamei+0x204> */
/* @0x1d0d60 ldr r1, [pc, #0x6c] */
/* @0x1d0d64 add r1, pc, r1 */
/* @0x1d0d68 b 0x1d0a68 <_Z16Command_SaveGamei+0x2a0> */
/* @0x1d0d6c eoreq r1, r2, r12, ror r4 */
/* @0x1d0d70 .word 0xffffeec4 */
/* @0x1d0d74 .word 0xffffd784 */
/* @0x1d0d78 .word 0xffffc154 */
/* @0x1d0d7c .word 0xffffc458 */
/* @0x1d0d80 .word 0xffffce34 */
/* @0x1d0d84 .word 0xffffd99c */
/* @0x1d0d88 .word 0xffffd998 */
/* @0x1d0d8c .word 0xffffd9a0 */
/* @0x1d0d90 .word 0xffffd780 */
/* @0x1d0d94 .word 0xffffd9a4 */
/* @0x1d0d98 .word 0xffffd9a8 */
/* @0x1d0d9c .word 0xffffd788 */
/* @0x1d0da0 .word 0xffffd9ac */
/* @0x1d0da4 .word 0xffffd9b0 */
/* @0x1d0da8 .word 0xffffd798 */
/* @0x1d0dac .word 0xffffebf0 */
/* @0x1d0db0 .word 0xffffc974 */
/* @0x1d0db4 .word 0xffffc024 */
/* @0x1d0db8 .word 0xffffeed8 */
/* @0x1d0dbc .word 0xffffebbc */
/* @0x1d0dc0 .word 0xffffebc0 */
/* @0x1d0dc4 .word 0xffffbcd4 */
/* @0x1d0dc8 .word 0xffffc7d0 */
/* @0x1d0dcc mulseq r8, r0, r0 */
/* @0x1d0dd0 ldrsbeq sp, [r5], -lr */
/* @0x1d0dd4 ldrsbeq sp, [r5], -r2 */

/* ── FUNC 0x1d0dd8 · Command_LoadGame(int) · size=252 · insn=63 */
/* @0x1d0dd8 ldr r3, [pc, #0xd0] */
/* @0x1d0ddc push {r4, r5, r6, lr} */
/* @0x1d0de0 add r3, pc, r3 */
/* @0x1d0de4 ldr r4, [pc, #0xc8] */
/* @0x1d0de8 mov r5, r0 */
/* @0x1d0dec ldr r3, [r3, #0x4] */
/* @0x1d0df0 add r4, pc, r4 */
/* @0x1d0df4 cmn r3, #1 */
/* @0x1d0df8 beq 0x1d0e24 <_Z16Command_LoadGamei+0x4c> */
/* @0x1d0dfc ldr r3, [pc, #0xb4] */
/* @0x1d0e00 ldr r1, [pc, #0xb4] */
/* @0x1d0e04 ldr r3, [r4, r3] */
/* @0x1d0e08 add r1, pc, r1 */
/* @0x1d0e0c ldr r0, [r3] */
/* @0x1d0e10 ldr r3, [r0] */
/* @0x1d0e14 ldr r3, [r3, #0xc] */
/* @0x1d0e18 blx r3 */
/* @0x1d0e1c mov r0, #0 */
/* @0x1d0e20 pop {r4, r5, r6, pc} */
/* @0x1d0e24 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x1d0e28 subs r6, r0, #0 */
/* @0x1d0e2c beq 0x1d0e84 <_Z16Command_LoadGamei+0xac> */
/* @0x1d0e30 ldr r2, [pc, #0x88] */
/* @0x1d0e34 ldr r3, [pc, #0x88] */
/* @0x1d0e38 add r2, pc, r2 */
/* @0x1d0e3c str r6, [r2] */
/* @0x1d0e40 ldr r3, [r4, r3] */
/* @0x1d0e44 ldrb r3, [r3] */
/* @0x1d0e48 cmp r3, #0 */
/* @0x1d0e4c beq 0x1d0e64 <_Z16Command_LoadGamei+0x8c> */
/* @0x1d0e50 ldr r3, [pc, #0x70] */
/* @0x1d0e54 ldr r3, [r4, r3] */
/* @0x1d0e58 ldr r3, [r3] */
/* @0x1d0e5c cmp r3, #0 */
/* @0x1d0e60 beq 0x1d0e6c <_Z16Command_LoadGamei+0x94> */
/* @0x1d0e64 mov r0, #1 */
/* @0x1d0e68 pop {r4, r5, r6, pc} */
/* @0x1d0e6c ldr r1, [pc, #0x58] */
/* @0x1d0e70 mov r0, #2 */
/* @0x1d0e74 add r1, pc, r1 */
/* @0x1d0e78 bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x1d0e7c mov r0, #1 */
/* @0x1d0e80 pop {r4, r5, r6, pc} */
/* @0x1d0e84 ldr r3, [pc, #0x2c] */
/* @0x1d0e88 mov r2, r5 */
/* @0x1d0e8c ldr r1, [pc, #0x3c] */
/* @0x1d0e90 ldr r3, [r4, r3] */
/* @0x1d0e94 add r1, pc, r1 */
/* @0x1d0e98 ldr r0, [r3] */
/* @0x1d0e9c ldr r3, [r0] */
/* @0x1d0ea0 ldr r3, [r3, #0xc] */
/* @0x1d0ea4 blx r3 */
/* @0x1d0ea8 mov r0, r6 */
/* @0x1d0eac pop {r4, r5, r6, pc} */
/* @0x1d0eb0 eoreq r4, r2, r0, lsr r3 */
/* @0x1d0eb4 eoreq r0, r2, r0, ror #28 */
/* @0x1d0eb8 .word 0xffffbac4 */
/* @0x1d0ebc ldrsbeq pc, [r7], -r8 */
/* @0x1d0ec0 eorseq r1, r7, r12, lsl #23 */
/* @0x1d0ec4 .word 0xffffbcd4 */
/* @0x1d0ec8 .word 0xffffc7d0 */
/* @0x1d0ecc ldrsbeq pc, [r7], -r8 */
/* @0x1d0ed0 mulseq r7, r0, pc */

/* ── FUNC 0x1d0ed4 · Check_LoadGameState() · size=1428 · insn=357 */
/* @0x1d0ed4 ldr r3, [pc, #0x558] */
/* @0x1d0ed8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d0edc add r3, pc, r3 */
/* @0x1d0ee0 ldr r10, [pc, #0x550] */
/* @0x1d0ee4 sub sp, sp, #36 */
/* @0x1d0ee8 ldr r5, [r3] */
/* @0x1d0eec add r10, pc, r10 */
/* @0x1d0ef0 subs r0, r5, #0 */
/* @0x1d0ef4 beq 0x1d0f38 <_Z19Check_LoadGameStatev+0x64> */
/* @0x1d0ef8 mov r9, #0 */
/* @0x1d0efc str r9, [r3] */
/* @0x1d0f00 bl 0x1d039c <_Z23GlobalState_DeSerialiseP7IBuffer> */
/* @0x1d0f04 cmp r0, r9 */
/* @0x1d0f08 bne 0x1d0f40 <_Z19Check_LoadGameStatev+0x6c> */
/* @0x1d0f0c mov r5, #0 */
/* @0x1d0f10 ldr r4, [pc, #0x524] */
/* @0x1d0f14 add r4, pc, r4 */
/* @0x1d0f18 ldr r0, [r4, #0x4] */
/* @0x1d0f1c cmn r0, #1 */
/* @0x1d0f20 moveq r0, r5 */
/* @0x1d0f24 beq 0x1d0f38 <_Z19Check_LoadGameStatev+0x64> */
/* @0x1d0f28 bl 0xc6a88 <_Z11FreeIBufferi> */
/* @0x1d0f2c mov r0, r5 */
/* @0x1d0f30 mvn r3, #0 */
/* @0x1d0f34 str r3, [r4, #0x4] */
/* @0x1d0f38 add sp, sp, #36 */
/* @0x1d0f3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d0f40 mov r0, r5 */
/* @0x1d0f44 bl 0x1f4b64 <_Z27Variable_Global_DeSerialiseP7IBuffer> */
/* @0x1d0f48 cmp r0, #0 */
/* @0x1d0f4c beq 0x1d0f0c <_Z19Check_LoadGameStatev+0x38> */
/* @0x1d0f50 ldr r3, [pc, #0x4e8] */
/* @0x1d0f54 mov r1, r5 */
/* @0x1d0f58 ldr r0, [r10, r3] */
/* @0x1d0f5c bl 0x16f34c <_ZN14CCameraManager11DeSerializeEP7IBuffer> */
/* @0x1d0f60 cmp r0, #0 */
/* @0x1d0f64 beq 0x1d0f0c <_Z19Check_LoadGameStatev+0x38> */
/* @0x1d0f68 ldr r3, [pc, #0x4d4] */
/* @0x1d0f6c ldr r3, [r10, r3] */
/* @0x1d0f70 ldr r0, [r3] */
/* @0x1d0f74 str r3, [sp, #0x14] */
/* @0x1d0f78 bl 0x1ab798 <_ZN5CRoom14ClearInstancesEv> */
/* @0x1d0f7c ldr r3, [sp, #0x14] */
/* @0x1d0f80 ldr r0, [r3] */
/* @0x1d0f84 bl 0x1ab9c8 <_ZN5CRoom22ClearDeactiveInstancesEv> */
/* @0x1d0f88 bl 0x19f21c <_Z27Object_ClearAllInstanceInfov> */
/* @0x1d0f8c ldr r3, [pc, #0x4b4] */
/* @0x1d0f90 ldr r4, [r10, r3] */
/* @0x1d0f94 ldr r8, [r4, #0x4] */
/* @0x1d0f98 cmp r8, #0 */
/* @0x1d0f9c blt 0x1d1010 <_Z19Check_LoadGameStatev+0x13c> */
/* @0x1d0fa0 lsl r7, r8, #3 */
/* @0x1d0fa4 ldr r3, [r4] */
/* @0x1d0fa8 add r2, r3, r7 */
/* @0x1d0fac ldr r6, [r3, r7] */
/* @0x1d0fb0 str r9, [r3, r7] */
/* @0x1d0fb4 cmp r6, #0 */
/* @0x1d0fb8 str r9, [r2, #0x4] */
/* @0x1d0fbc beq 0x1d1000 <_Z19Check_LoadGameStatev+0x12c> */
/* @0x1d0fc0 ldr r3, [r6, #0xc] */
/* @0x1d0fc4 ldr r11, [r6, #0x4] */
/* @0x1d0fc8 cmp r3, #0 */
/* @0x1d0fcc mov r0, r3 */
/* @0x1d0fd0 beq 0x1d0fe0 <_Z19Check_LoadGameStatev+0x10c> */
/* @0x1d0fd4 ldr r3, [r3] */
/* @0x1d0fd8 ldr r3, [r3, #0x4] */
/* @0x1d0fdc blx r3 */
/* @0x1d0fe0 mov r0, r6 */
/* @0x1d0fe4 mov r6, r11 */
/* @0x1d0fe8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d0fec ldr r3, [r4, #0x8] */
/* @0x1d0ff0 cmp r11, #0 */
/* @0x1d0ff4 sub r3, r3, #1 */
/* @0x1d0ff8 str r3, [r4, #0x8] */
/* @0x1d0ffc bne 0x1d0fc0 <_Z19Check_LoadGameStatev+0xec> */
/* @0x1d1000 sub r8, r8, #1 */
/* @0x1d1004 sub r7, r7, #8 */
/* @0x1d1008 cmn r8, #1 */
/* @0x1d100c bne 0x1d0fa4 <_Z19Check_LoadGameStatev+0xd0> */
/* @0x1d1010 ldr r3, [r5] */
/* @0x1d1014 add r8, r5, #44 */
/* @0x1d1018 mov r1, #6 */
/* @0x1d101c mov r0, r5 */
/* @0x1d1020 mov r2, r8 */
/* @0x1d1024 ldr r3, [r3, #0xc] */
/* @0x1d1028 blx r3 */
/* @0x1d102c mov r1, #0 */
/* @0x1d1030 mov r0, r8 */
/* @0x1d1034 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1d1038 ldr r3, [r5] */
/* @0x1d103c mov r2, r8 */
/* @0x1d1040 mov r1, #6 */
/* @0x1d1044 ldr r3, [r3, #0xc] */
/* @0x1d1048 str r0, [sp, #0xc] */
/* @0x1d104c mov r0, r5 */
/* @0x1d1050 blx r3 */
/* @0x1d1054 mov r1, #0 */
/* @0x1d1058 mov r0, r8 */
/* @0x1d105c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1d1060 ldr r12, [pc, #0x3e4] */
/* @0x1d1064 ldr r3, [r5] */
/* @0x1d1068 mov r2, r8 */
/* @0x1d106c mov r1, #6 */
/* @0x1d1070 ldr r12, [r10, r12] */
/* @0x1d1074 ldr r3, [r3, #0xc] */
/* @0x1d1078 str r0, [r12] */
/* @0x1d107c mov r0, r5 */
/* @0x1d1080 blx r3 */
/* @0x1d1084 mov r0, r8 */
/* @0x1d1088 mov r1, #0 */
/* @0x1d108c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1d1090 ldr r2, [pc, #0x3b8] */
/* @0x1d1094 ldr r3, [pc, #0x3b8] */
/* @0x1d1098 ldr r2, [r10, r2] */
/* @0x1d109c str r0, [r2] */
/* @0x1d10a0 ldr r11, [r10, r3] */
/* @0x1d10a4 ldr r3, [sp, #0xc] */
/* @0x1d10a8 ldr r2, [r11] */
/* @0x1d10ac cmp r2, r3 */
/* @0x1d10b0 str r2, [sp, #0x1c] */
/* @0x1d10b4 beq 0x1d1168 <_Z19Check_LoadGameStatev+0x294> */
/* @0x1d10b8 cmp r3, #0 */
/* @0x1d10bc bne 0x1d13e0 <_Z19Check_LoadGameStatev+0x50c> */
/* @0x1d10c0 ldr r3, [r11, #0x4] */
/* @0x1d10c4 cmp r3, #0 */
/* @0x1d10c8 beq 0x1d1150 <_Z19Check_LoadGameStatev+0x27c> */
/* @0x1d10cc cmp r2, #0 */
/* @0x1d10d0 ble 0x1d1150 <_Z19Check_LoadGameStatev+0x27c> */
/* @0x1d10d4 ldr r6, [sp, #0xc] */
/* @0x1d10d8 mov r1, r6 */
/* @0x1d10dc ldr r0, [r3] */
/* @0x1d10e0 movw r2, #0xfeee */
/* @0x1d10e4 movt r2, #0xfeee */
/* @0x1d10e8 movw r12, #0xfeee */
/* @0x1d10ec cmp r0, r2 */
/* @0x1d10f0 movt r12, #0xfeee */
/* @0x1d10f4 lsl r9, r6, #2 */
/* @0x1d10f8 beq 0x1d1140 <_Z19Check_LoadGameStatev+0x26c> */
/* @0x1d10fc ldr r7, [r3, r6, lsl #2] */
/* @0x1d1100 add r2, r3, r9 */
/* @0x1d1104 cmp r7, #0 */
/* @0x1d1108 mov r0, r7 */
/* @0x1d110c beq 0x1d1140 <_Z19Check_LoadGameStatev+0x26c> */
/* @0x1d1110 ldr r3, [r7] */
/* @0x1d1114 cmp r3, r12 */
/* @0x1d1118 beq 0x1d1138 <_Z19Check_LoadGameStatev+0x264> */
/* @0x1d111c str r1, [sp, #0x8] */
/* @0x1d1120 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1d1124 mov r0, r7 */
/* @0x1d1128 bl 0x27d1d0 <_ZdlPv> */
/* @0x1d112c ldr r2, [r11, #0x4] */
/* @0x1d1130 ldr r1, [sp, #0x8] */
/* @0x1d1134 add r2, r2, r9 */
/* @0x1d1138 str r1, [r2] */
/* @0x1d113c ldr r3, [r11, #0x4] */
/* @0x1d1140 ldr r2, [r11] */
/* @0x1d1144 add r6, r6, #1 */
/* @0x1d1148 cmp r6, r2 */
/* @0x1d114c blt 0x1d10dc <_Z19Check_LoadGameStatev+0x208> */
/* @0x1d1150 mov r0, r3 */
/* @0x1d1154 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d1158 mov r3, #0 */
/* @0x1d115c str r3, [r11, #0x4] */
/* @0x1d1160 ldr r3, [sp, #0xc] */
/* @0x1d1164 str r3, [r11] */
/* @0x1d1168 ldr r2, [sp, #0xc] */
/* @0x1d116c ldr r3, [pc, #0x2e4] */
/* @0x1d1170 cmp r2, #0 */
/* @0x1d1174 ble 0x1d1428 <_Z19Check_LoadGameStatev+0x554> */
/* @0x1d1178 ldr r3, [r10, r3] */
/* @0x1d117c mov r7, #0 */
/* @0x1d1180 ldr r6, [sp, #0xc] */
/* @0x1d1184 mvn r9, #0 */
/* @0x1d1188 str r4, [sp, #0xc] */
/* @0x1d118c ldr r4, [sp, #0x1c] */
/* @0x1d1190 str r10, [sp, #0x18] */
/* @0x1d1194 mov r10, r7 */
/* @0x1d1198 str r3, [sp, #0x10] */
/* @0x1d119c cmp r4, #0 */
/* @0x1d11a0 ble 0x1d1218 <_Z19Check_LoadGameStatev+0x344> */
/* @0x1d11a4 ldr r3, [r11] */
/* @0x1d11a8 cmp r3, r10 */
/* @0x1d11ac ble 0x1d1218 <_Z19Check_LoadGameStatev+0x344> */
/* @0x1d11b0 ldr r3, [r11, #0x4] */
/* @0x1d11b4 ldr r1, [r3, r7] */
/* @0x1d11b8 cmp r1, #0 */
/* @0x1d11bc beq 0x1d1218 <_Z19Check_LoadGameStatev+0x344> */
/* @0x1d11c0 ldr r3, [pc, #0x294] */
/* @0x1d11c4 ldr r2, [sp, #0x18] */
/* @0x1d11c8 ldr r3, [r2, r3] */
/* @0x1d11cc ldrb r3, [r3] */
/* @0x1d11d0 cmp r3, #0 */
/* @0x1d11d4 beq 0x1d11f4 <_Z19Check_LoadGameStatev+0x320> */
/* @0x1d11d8 mov r2, r1 */
/* @0x1d11dc mov r3, #8 */
/* @0x1d11e0 ldr r0, [r2, #0x48] */
/* @0x1d11e4 subs r3, r3, #1 */
/* @0x1d11e8 add r2, r2, #4 */
/* @0x1d11ec str r9, [r0, #0x40] */
/* @0x1d11f0 bne 0x1d11e0 <_Z19Check_LoadGameStatev+0x30c> */
/* @0x1d11f4 mov r0, r1 */
/* @0x1d11f8 str r1, [sp, #0x8] */
/* @0x1d11fc bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1d1200 ldr r1, [sp, #0x8] */
/* @0x1d1204 mov r0, r1 */
/* @0x1d1208 bl 0x27d1d0 <_ZdlPv> */
/* @0x1d120c ldr r3, [r11, #0x4] */
/* @0x1d1210 mov r2, #0 */
/* @0x1d1214 str r2, [r3, r7] */
/* @0x1d1218 ldr r3, [r5] */
/* @0x1d121c mov r1, #6 */
/* @0x1d1220 mov r2, r8 */
/* @0x1d1224 mov r0, r5 */
/* @0x1d1228 ldr r3, [r3, #0xc] */
/* @0x1d122c blx r3 */
/* @0x1d1230 mov r0, r8 */
/* @0x1d1234 mov r1, #0 */
/* @0x1d1238 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1d123c cmp r0, #0 */
/* @0x1d1240 bne 0x1d1394 <_Z19Check_LoadGameStatev+0x4c0> */
/* @0x1d1244 add r10, r10, #1 */
/* @0x1d1248 add r7, r7, #4 */
/* @0x1d124c cmp r10, r6 */
/* @0x1d1250 bne 0x1d119c <_Z19Check_LoadGameStatev+0x2c8> */
/* @0x1d1254 ldr r4, [sp, #0xc] */
/* @0x1d1258 ldr r2, [sp, #0x10] */
/* @0x1d125c ldr r3, [r2] */
/* @0x1d1260 ldr r2, [r11] */
/* @0x1d1264 cmp r3, r2 */
/* @0x1d1268 movge r3, #0 */
/* @0x1d126c ldrlt r2, [r11, #0x4] */
/* @0x1d1270 ldrlt r3, [r2, r3, lsl #2] */
/* @0x1d1274 ldr r2, [sp, #0x14] */
/* @0x1d1278 str r3, [r2] */
/* @0x1d127c bl 0x1b29bc <_Z17Draw_Room_SetSizev> */
/* @0x1d1280 ldr r2, [sp, #0x14] */
/* @0x1d1284 ldr r3, [r2] */
/* @0x1d1288 ldr r7, [r3, #0x80] */
/* @0x1d128c cmp r7, #0 */
/* @0x1d1290 beq 0x1d1380 <_Z19Check_LoadGameStatev+0x4ac> */
/* @0x1d1294 ldr r8, [pc, #0x1c4] */
/* @0x1d1298 mov r9, #0 */
/* @0x1d129c add r8, pc, r8 */
/* @0x1d12a0 ldr r6, [r7, #0x78] */
/* @0x1d12a4 ldr r10, [r7, #0x178] */
/* @0x1d12a8 cmp r6, #0 */
/* @0x1d12ac blt 0x1d1410 <_Z19Check_LoadGameStatev+0x53c> */
/* @0x1d12b0 ldr r1, [r4, #0x4] */
/* @0x1d12b4 ldr r2, [r4] */
/* @0x1d12b8 and r1, r6, r1 */
/* @0x1d12bc ldr r3, [r2, r1, lsl #3] */
/* @0x1d12c0 add r1, r2, r1, lsl #3 */
/* @0x1d12c4 cmp r3, #0 */
/* @0x1d12c8 beq 0x1d12f4 <_Z19Check_LoadGameStatev+0x420> */
/* @0x1d12cc ldr r0, [r3, #0x8] */
/* @0x1d12d0 cmp r6, r0 */
/* @0x1d12d4 bne 0x1d12e8 <_Z19Check_LoadGameStatev+0x414> */
/* @0x1d12d8 b 0x1d136c <_Z19Check_LoadGameStatev+0x498> */
/* @0x1d12dc ldr r2, [r3, #0x8] */
/* @0x1d12e0 cmp r6, r2 */
/* @0x1d12e4 beq 0x1d136c <_Z19Check_LoadGameStatev+0x498> */
/* @0x1d12e8 ldr r3, [r3, #0x4] */
/* @0x1d12ec cmp r3, #0 */
/* @0x1d12f0 bne 0x1d12dc <_Z19Check_LoadGameStatev+0x408> */
/* @0x1d12f4 mov r11, r1 */
/* @0x1d12f8 mov r1, r8 */
/* @0x1d12fc movw r2, #0x132 */
/* @0x1d1300 mov r3, #1 */
/* @0x1d1304 mov r0, #16 */
/* @0x1d1308 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d130c ldr r3, [r11] */
/* @0x1d1310 ldr r2, [sp, #0x14] */
/* @0x1d1314 mov r1, r7 */
/* @0x1d1318 cmp r3, #0 */
/* @0x1d131c ldrne r3, [r11, #0x4] */
/* @0x1d1320 str r6, [r0, #0x8] */
/* @0x1d1324 strne r3, [r0] */
/* @0x1d1328 str r7, [r0, #0xc] */
/* @0x1d132c strne r0, [r3, #0x4] */
/* @0x1d1330 streq r0, [r11, #0x4] */
/* @0x1d1334 streq r0, [r11] */
/* @0x1d1338 streq r3, [r0, #0x4] */
/* @0x1d133c streq r3, [r0] */
/* @0x1d1340 ldr r3, [r4, #0x8] */
/* @0x1d1344 strne r0, [r11, #0x4] */
/* @0x1d1348 strne r9, [r0, #0x4] */
/* @0x1d134c add r3, r3, #1 */
/* @0x1d1350 ldr r0, [r2] */
/* @0x1d1354 str r3, [r4, #0x8] */
/* @0x1d1358 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1d135c cmp r10, #0 */
/* @0x1d1360 beq 0x1d1380 <_Z19Check_LoadGameStatev+0x4ac> */
/* @0x1d1364 mov r7, r10 */
/* @0x1d1368 b 0x1d12a0 <_Z19Check_LoadGameStatev+0x3cc> */
/* @0x1d136c ldr r3, [r3, #0xc] */
/* @0x1d1370 cmp r3, #0 */
/* @0x1d1374 beq 0x1d12f4 <_Z19Check_LoadGameStatev+0x420> */
/* @0x1d1378 cmp r10, #0 */
/* @0x1d137c bne 0x1d1364 <_Z19Check_LoadGameStatev+0x490> */
/* @0x1d1380 mov r0, r5 */
/* @0x1d1384 bl 0x18ca38 <_Z23VirtualKeys_DeSerialiseP7IBuffer> */
/* @0x1d1388 adds r5, r0, #0 */
/* @0x1d138c movne r5, #1 */
/* @0x1d1390 b 0x1d0f10 <_Z19Check_LoadGameStatev+0x3c> */
/* @0x1d1394 mov r0, #292 */
/* @0x1d1398 bl 0x27c524 <_Znwj> */
/* @0x1d139c str r0, [sp, #0x8] */
/* @0x1d13a0 bl 0x1ad2cc <_ZN5CRoomC2Ev> */
/* @0x1d13a4 ldm r11, {r1, r2} */
/* @0x1d13a8 ldr r3, [sp, #0x8] */
/* @0x1d13ac cmp r1, r10 */
/* @0x1d13b0 mov r1, r5 */
/* @0x1d13b4 str r3, [r2, r7] */
/* @0x1d13b8 movle r0, #0 */
/* @0x1d13bc ldrgt r3, [r11, #0x4] */
/* @0x1d13c0 ldrgt r0, [r3, r7] */
/* @0x1d13c4 ldr r3, [sp, #0x10] */
/* @0x1d13c8 ldr r2, [r3] */
/* @0x1d13cc subs r3, r10, r2 */
/* @0x1d13d0 rsbs r2, r3, #0 */
/* @0x1d13d4 adcs r2, r2, r3 */
/* @0x1d13d8 bl 0x1ac33c <_ZN5CRoom11DeSerialiseEP7IBufferb> */
/* @0x1d13dc b 0x1d1244 <_Z19Check_LoadGameStatev+0x370> */
/* @0x1d13e0 ldr r2, [sp, #0xc] */
/* @0x1d13e4 lsls r1, r2, #2 */
/* @0x1d13e8 beq 0x1d1420 <_Z19Check_LoadGameStatev+0x54c> */
/* @0x1d13ec ldr r2, [pc, #0x70] */
/* @0x1d13f0 mov r3, #0 */
/* @0x1d13f4 ldr r0, [r11, #0x4] */
/* @0x1d13f8 add r2, pc, r2 */
/* @0x1d13fc str r3, [sp] */
/* @0x1d1400 mov r3, #135 */
/* @0x1d1404 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1d1408 str r0, [r11, #0x4] */
/* @0x1d140c b 0x1d1160 <_Z19Check_LoadGameStatev+0x28c> */
/* @0x1d1410 ldm r4, {r3, r11} */
/* @0x1d1414 and r11, r6, r11 */
/* @0x1d1418 add r11, r3, r11, lsl #3 */
/* @0x1d141c b 0x1d12f8 <_Z19Check_LoadGameStatev+0x424> */
/* @0x1d1420 ldr r3, [r11, #0x4] */
/* @0x1d1424 b 0x1d1150 <_Z19Check_LoadGameStatev+0x27c> */
/* @0x1d1428 ldr r3, [r10, r3] */
/* @0x1d142c str r3, [sp, #0x10] */
/* @0x1d1430 b 0x1d1258 <_Z19Check_LoadGameStatev+0x384> */
/* @0x1d1434 eorseq r1, r7, r8, ror #21 */
/* @0x1d1438 eoreq r0, r2, r4, ror #26 */
/* @0x1d143c .word 0x002241fc */
/* @0x1d1440 .word 0xffffc024 */
/* @0x1d1444 .word 0xffffbcd8 */
/* @0x1d1448 .word 0xffffbff4 */
/* @0x1d144c .word 0xffffebbc */
/* @0x1d1450 .word 0xffffebc0 */
/* @0x1d1454 .word 0xffffeed8 */
/* @0x1d1458 .word 0xffffd784 */
/* @0x1d145c .word 0xffffbcd4 */
/* @0x1d1460 andseq r11, r7, r0, lsl r10 */
/* @0x1d1464 ldrsheq r11, [r7], -r8 */

/* ── FUNC 0x1d1468 · Command_SaveGame(char const*) · size=148 · insn=37 */
/* @0x1d1468 push {r4, r5, r6, r7, lr} */
/* @0x1d146c sub sp, sp, #1024 */
/* @0x1d1470 ldr r4, [pc, #0x80] */
/* @0x1d1474 sub sp, sp, #12 */
/* @0x1d1478 mov r1, #1 */
/* @0x1d147c mov r7, r0 */
/* @0x1d1480 ldr r4, [pc, r4] */
/* @0x1d1484 mov r2, r1 */
/* @0x1d1488 mov r0, #131072 */
/* @0x1d148c ldr r3, [r4] */
/* @0x1d1490 str r3, [sp, #0x404] */
/* @0x1d1494 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> */
/* @0x1d1498 mov r5, r0 */
/* @0x1d149c bl 0x1d07c8 <_Z16Command_SaveGamei> */
/* @0x1d14a0 mov r0, r5 */
/* @0x1d14a4 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x1d14a8 mov r2, r7 */
/* @0x1d14ac add r7, sp, #4 */
/* @0x1d14b0 mov r1, #1024 */
/* @0x1d14b4 mov r6, r0 */
/* @0x1d14b8 mov r0, r7 */
/* @0x1d14bc bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1d14c0 ldr r2, [r6, #0x1c] */
/* @0x1d14c4 ldr r1, [r6, #0xc] */
/* @0x1d14c8 mov r0, r7 */
/* @0x1d14cc bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i> */
/* @0x1d14d0 mov r0, r5 */
/* @0x1d14d4 bl 0xc6a88 <_Z11FreeIBufferi> */
/* @0x1d14d8 ldr r2, [sp, #0x404] */
/* @0x1d14dc ldr r3, [r4] */
/* @0x1d14e0 cmp r2, r3 */
/* @0x1d14e4 bne 0x1d14f4 <_Z16Command_SaveGamePKc+0x8c> */
/* @0x1d14e8 add sp, sp, #1024 */
/* @0x1d14ec add sp, sp, #12 */
/* @0x1d14f0 pop {r4, r5, r6, r7, pc} */
/* @0x1d14f4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1d14f8 .word 0x0021c4d0 */

/* ── FUNC 0x1d14fc · Command_LoadGame(char const*) · size=404 · insn=101 */
/* @0x1d14fc push {r4, r5, r6, r7, lr} */
/* @0x1d1500 sub sp, sp, #1024 */
/* @0x1d1504 ldr r5, [pc, #0x168] */
/* @0x1d1508 sub sp, sp, #12 */
/* @0x1d150c ldr r3, [pc, #0x164] */
/* @0x1d1510 subs r4, r0, #0 */
/* @0x1d1514 add r5, pc, r5 */
/* @0x1d1518 ldr r6, [r5, r3] */
/* @0x1d151c ldr r3, [r6] */
/* @0x1d1520 str r3, [sp, #0x404] */
/* @0x1d1524 beq 0x1d164c <_Z16Command_LoadGamePKc+0x150> */
/* @0x1d1528 mov r3, #0 */
/* @0x1d152c strb r3, [sp, #0x4] */
/* @0x1d1530 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x1d1534 cmp r0, #0 */
/* @0x1d1538 bne 0x1d15f4 <_Z16Command_LoadGamePKc+0xf8> */
/* @0x1d153c mov r0, r4 */
/* @0x1d1540 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1d1544 cmp r0, #0 */
/* @0x1d1548 addeq r7, sp, #4 */
/* @0x1d154c bne 0x1d1634 <_Z16Command_LoadGamePKc+0x138> */
/* @0x1d1550 ldr r1, [pc, #0x124] */
/* @0x1d1554 mov r0, r7 */
/* @0x1d1558 add r1, pc, r1 */
/* @0x1d155c bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x1d1560 subs r4, r0, #0 */
/* @0x1d1564 beq 0x1d160c <_Z16Command_LoadGamePKc+0x110> */
/* @0x1d1568 mov r1, #0 */
/* @0x1d156c mov r2, #2 */
/* @0x1d1570 bl 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli> */
/* @0x1d1574 mov r0, r4 */
/* @0x1d1578 bl 0x18de24 <_ZN8LoadSave5ftellEP7_YYFILE> */
/* @0x1d157c mov r1, #0 */
/* @0x1d1580 mov r2, r1 */
/* @0x1d1584 mov r7, r0 */
/* @0x1d1588 mov r0, r4 */
/* @0x1d158c bl 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli> */
/* @0x1d1590 mov r1, #1 */
/* @0x1d1594 mov r2, r1 */
/* @0x1d1598 mov r0, r7 */
/* @0x1d159c bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> */
/* @0x1d15a0 mov r5, r0 */
/* @0x1d15a4 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x1d15a8 mov r3, r4 */
/* @0x1d15ac mov r2, r7 */
/* @0x1d15b0 mov r1, #1 */
/* @0x1d15b4 ldr r0, [r0, #0xc] */
/* @0x1d15b8 bl 0x18e070 <_ZN8LoadSave5freadEPKvjjP7_YYFILE> */
/* @0x1d15bc mov r0, r4 */
/* @0x1d15c0 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE> */
/* @0x1d15c4 mov r0, r5 */
/* @0x1d15c8 bl 0x1d0dd8 <_Z16Command_LoadGamei> */
/* @0x1d15cc ldr r3, [pc, #0xac] */
/* @0x1d15d0 add r3, pc, r3 */
/* @0x1d15d4 str r5, [r3, #0x4] */
/* @0x1d15d8 ldr r2, [sp, #0x404] */
/* @0x1d15dc ldr r3, [r6] */
/* @0x1d15e0 cmp r2, r3 */
/* @0x1d15e4 bne 0x1d1670 <_Z16Command_LoadGamePKc+0x174> */
/* @0x1d15e8 add sp, sp, #1024 */
/* @0x1d15ec add sp, sp, #12 */
/* @0x1d15f0 pop {r4, r5, r6, r7, pc} */
/* @0x1d15f4 add r7, sp, #4 */
/* @0x1d15f8 mov r2, r4 */
/* @0x1d15fc mov r1, #1024 */
/* @0x1d1600 mov r0, r7 */
/* @0x1d1604 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1d1608 b 0x1d1550 <_Z16Command_LoadGamePKc+0x54> */
/* @0x1d160c ldr r3, [pc, #0x70] */
/* @0x1d1610 mov r2, r7 */
/* @0x1d1614 ldr r1, [pc, #0x6c] */
/* @0x1d1618 ldr r3, [r5, r3] */
/* @0x1d161c add r1, pc, r1 */
/* @0x1d1620 ldr r0, [r3] */
/* @0x1d1624 ldr r3, [r0] */
/* @0x1d1628 ldr r3, [r3, #0xc] */
/* @0x1d162c blx r3 */
/* @0x1d1630 b 0x1d15d8 <_Z16Command_LoadGamePKc+0xdc> */
/* @0x1d1634 add r7, sp, #4 */
/* @0x1d1638 mov r2, r4 */
/* @0x1d163c mov r1, #1024 */
/* @0x1d1640 mov r0, r7 */
/* @0x1d1644 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x1d1648 b 0x1d1550 <_Z16Command_LoadGamePKc+0x54> */
/* @0x1d164c ldr r3, [pc, #0x30] */
/* @0x1d1650 ldr r1, [pc, #0x34] */
/* @0x1d1654 ldr r3, [r5, r3] */
/* @0x1d1658 add r1, pc, r1 */
/* @0x1d165c ldr r0, [r3] */
/* @0x1d1660 ldr r3, [r0] */
/* @0x1d1664 ldr r3, [r3, #0xc] */
/* @0x1d1668 blx r3 */
/* @0x1d166c b 0x1d15d8 <_Z16Command_LoadGamePKc+0xdc> */
/* @0x1d1670 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1d1674 eoreq r0, r2, r12, lsr r7 */
/* @0x1d1678 .word 0xffffbd00 */
/* @0x1d167c andseq r6, r6, r0, lsr #13 */
/* @0x1d1680 eoreq r3, r2, r0, asr #22 */
/* @0x1d1684 .word 0xffffbac4 */
/* @0x1d1688 andseq pc, r7, r0, ror r8 */
/* @0x1d168c andseq pc, r7, r0, lsl #16 */

/* ── FUNC 0x1d1690 · List<CInstance*>::~List() · size=40 · insn=10 */
/* @0x1d1690 push {r4, lr} */
/* @0x1d1694 mov r4, r0 */
/* @0x1d1698 ldr r0, [r0] */
/* @0x1d169c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d16a0 mov r3, #0 */
/* @0x1d16a4 mov r0, r4 */
/* @0x1d16a8 str r3, [r4] */
/* @0x1d16ac str r3, [r4, #0x4] */
/* @0x1d16b0 str r3, [r4, #0x8] */
/* @0x1d16b4 pop {r4, pc} */

/* ── FUNC 0x1d1690 · List<CInstance*>::~List() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d16b8 · cARRAY_CLASS_NO_DELETE<CInstance*>::~cARRAY_CLASS_NO_DELETE() · size=108 · insn=27 */
/* @0x1d16b8 push {r3, r4, r5, lr} */
/* @0x1d16bc mov r5, r0 */
/* @0x1d16c0 ldr r4, [r0, #0x4] */
/* @0x1d16c4 cmp r4, #0 */
/* @0x1d16c8 beq 0x1d1714 <_ZN22cARRAY_CLASS_NO_DELETEIP9CInstanceED2Ev+0x5c> */
/* @0x1d16cc ldr r2, [r0] */
/* @0x1d16d0 cmp r2, #0 */
/* @0x1d16d4 ble 0x1d16f4 <_ZN22cARRAY_CLASS_NO_DELETEIP9CInstanceED2Ev+0x3c> */
/* @0x1d16d8 mov r3, #0 */
/* @0x1d16dc mov r1, r3 */
/* @0x1d16e0 str r1, [r4, r3, lsl #2] */
/* @0x1d16e4 add r3, r3, #1 */
/* @0x1d16e8 cmp r3, r2 */
/* @0x1d16ec ldr r4, [r5, #0x4] */
/* @0x1d16f0 bne 0x1d16e0 <_ZN22cARRAY_CLASS_NO_DELETEIP9CInstanceED2Ev+0x28> */
/* @0x1d16f4 mov r0, r4 */
/* @0x1d16f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d16fc mov r3, #0 */
/* @0x1d1700 str r3, [r5, #0x4] */
/* @0x1d1704 mov r3, #0 */
/* @0x1d1708 mov r0, r5 */
/* @0x1d170c str r3, [r5] */
/* @0x1d1710 pop {r3, r4, r5, pc} */
/* @0x1d1714 mov r0, r4 */
/* @0x1d1718 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d171c str r4, [r5, #0x4] */
/* @0x1d1720 b 0x1d1704 <_ZN22cARRAY_CLASS_NO_DELETEIP9CInstanceED2Ev+0x4c> */

/* ── FUNC 0x1d16b8 · cARRAY_CLASS_NO_DELETE<CInstance*>::~cARRAY_CLASS_NO_DELETE() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d1724 · EndRoom(bool) · size=1044 · insn=261 */
/* @0x1d1724 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d1728 mov r5, r0 */
/* @0x1d172c ldr r7, [pc, #0x3cc] */
/* @0x1d1730 sub sp, sp, #36 */
/* @0x1d1734 ldr r3, [pc, #0x3c8] */
/* @0x1d1738 add r7, pc, r7 */
/* @0x1d173c ldr r3, [r7, r3] */
/* @0x1d1740 ldrb r3, [r3] */
/* @0x1d1744 cmp r3, #0 */
/* @0x1d1748 bne 0x1d1aac <_Z7EndRoomb+0x388> */
/* @0x1d174c ldr r3, [pc, #0x3b4] */
/* @0x1d1750 ldr r3, [r7, r3] */
/* @0x1d1754 ldr r0, [r3] */
/* @0x1d1758 str r3, [sp, #0x18] */
/* @0x1d175c cmp r0, #0 */
/* @0x1d1760 beq 0x1d19e8 <_Z7EndRoomb+0x2c4> */
/* @0x1d1764 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d1768 ldr r2, [pc, #0x39c] */
/* @0x1d176c mov r0, #7 */
/* @0x1d1770 mov r1, #5 */
/* @0x1d1774 mvn r3, #0 */
/* @0x1d1778 ldr r4, [r7, r2] */
/* @0x1d177c ldr r6, [r4] */
/* @0x1d1780 str r3, [r4] */
/* @0x1d1784 bl 0xf33b0 <_Z17Perform_Event_Allii> */
/* @0x1d1788 ldr r2, [sp, #0x18] */
/* @0x1d178c ldr r0, [r2] */
/* @0x1d1790 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d1794 cmp r5, #0 */
/* @0x1d1798 bne 0x1d1abc <_Z7EndRoomb+0x398> */
/* @0x1d179c str r6, [r4] */
/* @0x1d17a0 bl 0x1a5cd8 <_Z34ParticleSystem_RemoveAllFromLayersv> */
/* @0x1d17a4 bl 0x18c64c <_Z20DeleteAllVirtualKeysv> */
/* @0x1d17a8 ldr r3, [pc, #0x360] */
/* @0x1d17ac ldr r0, [pc, #0x360] */
/* @0x1d17b0 mov r9, #0 */
/* @0x1d17b4 ldr r2, [pc, #0x35c] */
/* @0x1d17b8 mov r1, #40 */
/* @0x1d17bc ldr r11, [r7, r3] */
/* @0x1d17c0 mov r3, #76 */
/* @0x1d17c4 add r2, pc, r2 */
/* @0x1d17c8 str r9, [r11] */
/* @0x1d17cc ldr r6, [r7, r0] */
/* @0x1d17d0 str r9, [sp] */
/* @0x1d17d4 ldr r0, [r6, #0x4] */
/* @0x1d17d8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1d17dc ldr r2, [sp, #0x18] */
/* @0x1d17e0 ldr r3, [r2] */
/* @0x1d17e4 mov r2, #10 */
/* @0x1d17e8 str r2, [r6] */
/* @0x1d17ec ldr r4, [r3, #0x80] */
/* @0x1d17f0 cmp r4, r9 */
/* @0x1d17f4 str r0, [r6, #0x4] */
/* @0x1d17f8 beq 0x1d1af8 <_Z7EndRoomb+0x3d4> */
/* @0x1d17fc ldr r3, [pc, #0x318] */
/* @0x1d1800 add r3, pc, r3 */
/* @0x1d1804 str r3, [sp, #0x1c] */
/* @0x1d1808 b 0x1d1810 <_Z7EndRoomb+0xec> */
/* @0x1d180c mov r4, r5 */
/* @0x1d1810 ldrb r3, [r4, #0x68] */
/* @0x1d1814 ldr r5, [r4, #0x178] */
/* @0x1d1818 cmp r3, #0 */
/* @0x1d181c bne 0x1d18d0 <_Z7EndRoomb+0x1ac> */
/* @0x1d1820 ldrb r3, [r4, #0x69] */
/* @0x1d1824 cmp r3, #0 */
/* @0x1d1828 bne 0x1d18d0 <_Z7EndRoomb+0x1ac> */
/* @0x1d182c ldrb r2, [r4, #0x67] */
/* @0x1d1830 cmp r2, #0 */
/* @0x1d1834 beq 0x1d18d0 <_Z7EndRoomb+0x1ac> */
/* @0x1d1838 ldr r8, [r11] */
/* @0x1d183c ldr r2, [r6] */
/* @0x1d1840 add r1, r8, #1 */
/* @0x1d1844 str r1, [r11] */
/* @0x1d1848 cmp r1, r2 */
/* @0x1d184c bgt 0x1d19f0 <_Z7EndRoomb+0x2cc> */
/* @0x1d1850 ldr r3, [r4, #0x78] */
/* @0x1d1854 mov r0, #432 */
/* @0x1d1858 ldr r2, [r4, #0x7c] */
/* @0x1d185c ldr r1, [r4, #0xb4] */
/* @0x1d1860 ldr r10, [r4, #0xb8] */
/* @0x1d1864 str r2, [sp, #0xc] */
/* @0x1d1868 str r1, [sp, #0x14] */
/* @0x1d186c str r3, [sp, #0x10] */
/* @0x1d1870 bl 0x27c524 <_Znwj> */
/* @0x1d1874 ldr r2, [sp, #0xc] */
/* @0x1d1878 ldr r3, [sp, #0x10] */
/* @0x1d187c ldr r1, [sp, #0x14] */
/* @0x1d1880 str r2, [sp] */
/* @0x1d1884 mov r2, r10 */
/* @0x1d1888 str r9, [sp, #0x4] */
/* @0x1d188c mov r8, r0 */
/* @0x1d1890 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1d1894 ldr r12, [r11] */
/* @0x1d1898 mov r2, #0 */
/* @0x1d189c ldr r3, [r6, #0x4] */
/* @0x1d18a0 mov r0, r8 */
/* @0x1d18a4 sub r12, r12, #1 */
/* @0x1d18a8 mov r1, r4 */
/* @0x1d18ac str r8, [r3, r12, lsl #2] */
/* @0x1d18b0 bl 0x1986ec <_ZN9CInstance6AssignEPS_b> */
/* @0x1d18b4 ldr r3, [pc, #0x264] */
/* @0x1d18b8 mov r2, #1 */
/* @0x1d18bc strb r2, [r4, #0x68] */
/* @0x1d18c0 ldr r3, [r7, r3] */
/* @0x1d18c4 ldr r2, [r3] */
/* @0x1d18c8 add r2, r2, #1 */
/* @0x1d18cc str r2, [r3] */
/* @0x1d18d0 cmp r5, #0 */
/* @0x1d18d4 bne 0x1d180c <_Z7EndRoomb+0xe8> */
/* @0x1d18d8 ldr r3, [sp, #0x18] */
/* @0x1d18dc ldr r0, [r3] */
/* @0x1d18e0 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d18e4 ldr r2, [sp, #0x18] */
/* @0x1d18e8 ldr r0, [r2] */
/* @0x1d18ec ldrb r3, [r0, #0x18] */
/* @0x1d18f0 cmp r3, #0 */
/* @0x1d18f4 beq 0x1d1a54 <_Z7EndRoomb+0x330> */
/* @0x1d18f8 ldr r4, [r0, #0x80] */
/* @0x1d18fc cmp r4, #0 */
/* @0x1d1900 beq 0x1d19d4 <_Z7EndRoomb+0x2b0> */
/* @0x1d1904 ldrb r3, [r4, #0x68] */
/* @0x1d1908 ldr r5, [r4, #0x178] */
/* @0x1d190c cmp r3, #0 */
/* @0x1d1910 bne 0x1d19c0 <_Z7EndRoomb+0x29c> */
/* @0x1d1914 ldrb r3, [r4, #0x69] */
/* @0x1d1918 cmp r3, #0 */
/* @0x1d191c bne 0x1d19c0 <_Z7EndRoomb+0x29c> */
/* @0x1d1920 ldrb r3, [r4, #0x67] */
/* @0x1d1924 cmp r3, #0 */
/* @0x1d1928 bne 0x1d19c0 <_Z7EndRoomb+0x29c> */
/* @0x1d192c ldr r0, [r4, #0x80] */
/* @0x1d1930 mov r1, r4 */
/* @0x1d1934 bl 0x19e0fc <_ZN9CObjectGM14RemoveInstanceEP9CInstance> */
/* @0x1d1938 ldr r2, [sp, #0x18] */
/* @0x1d193c mov r1, r4 */
/* @0x1d1940 ldr r0, [r2] */
/* @0x1d1944 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> */
/* @0x1d1948 ldr r3, [pc, #0x1d4] */
/* @0x1d194c ldr r2, [r4, #0x78] */
/* @0x1d1950 ldr r4, [r7, r3] */
/* @0x1d1954 ldr r1, [r4, #0x4] */
/* @0x1d1958 ldr r12, [r4] */
/* @0x1d195c and r1, r2, r1 */
/* @0x1d1960 ldr r0, [r12, r1, lsl #3] */
/* @0x1d1964 add lr, r12, r1, lsl #3 */
/* @0x1d1968 cmp r0, #0 */
/* @0x1d196c bne 0x1d1980 <_Z7EndRoomb+0x25c> */
/* @0x1d1970 b 0x1d19c0 <_Z7EndRoomb+0x29c> */
/* @0x1d1974 ldr r0, [r0, #0x4] */
/* @0x1d1978 cmp r0, #0 */
/* @0x1d197c beq 0x1d19c0 <_Z7EndRoomb+0x29c> */
/* @0x1d1980 ldr r3, [r0, #0x8] */
/* @0x1d1984 cmp r2, r3 */
/* @0x1d1988 bne 0x1d1974 <_Z7EndRoomb+0x250> */
/* @0x1d198c ldr r3, [r0] */
/* @0x1d1990 ldr r2, [r0, #0x4] */
/* @0x1d1994 cmp r3, #0 */
/* @0x1d1998 strne r2, [r3, #0x4] */
/* @0x1d199c ldrne r2, [r0, #0x4] */
/* @0x1d19a0 streq r2, [r12, r1, lsl #3] */
/* @0x1d19a4 cmp r2, #0 */
/* @0x1d19a8 streq r3, [lr, #0x4] */
/* @0x1d19ac strne r3, [r2] */
/* @0x1d19b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d19b4 ldr r3, [r4, #0x8] */
/* @0x1d19b8 sub r3, r3, #1 */
/* @0x1d19bc str r3, [r4, #0x8] */
/* @0x1d19c0 cmp r5, #0 */
/* @0x1d19c4 movne r4, r5 */
/* @0x1d19c8 bne 0x1d1904 <_Z7EndRoomb+0x1e0> */
/* @0x1d19cc ldr r3, [sp, #0x18] */
/* @0x1d19d0 ldr r0, [r3] */
/* @0x1d19d4 bl 0x1b8f68 <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom> */
/* @0x1d19d8 ldr r3, [pc, #0x148] */
/* @0x1d19dc mov r2, #0 */
/* @0x1d19e0 ldr r3, [r7, r3] */
/* @0x1d19e4 str r2, [r3, #0x8] */
/* @0x1d19e8 add sp, sp, #36 */
/* @0x1d19ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d19f0 adds r8, r8, #6 */
/* @0x1d19f4 ldr r0, [r6, #0x4] */
/* @0x1d19f8 bne 0x1d1a30 <_Z7EndRoomb+0x30c> */
/* @0x1d19fc cmp r0, #0 */
/* @0x1d1a00 beq 0x1d1a24 <_Z7EndRoomb+0x300> */
/* @0x1d1a04 cmp r2, #0 */
/* @0x1d1a08 ble 0x1d1a24 <_Z7EndRoomb+0x300> */
/* @0x1d1a0c mov r3, r8 */
/* @0x1d1a10 str r9, [r0, r3, lsl #2] */
/* @0x1d1a14 add r3, r3, #1 */
/* @0x1d1a18 cmp r3, r2 */
/* @0x1d1a1c ldr r0, [r6, #0x4] */
/* @0x1d1a20 bne 0x1d1a10 <_Z7EndRoomb+0x2ec> */
/* @0x1d1a24 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d1a28 str r9, [r6, #0x4] */
/* @0x1d1a2c b 0x1d1a4c <_Z7EndRoomb+0x328> */
/* @0x1d1a30 lsls r1, r8, #2 */
/* @0x1d1a34 beq 0x1d1a24 <_Z7EndRoomb+0x300> */
/* @0x1d1a38 str r3, [sp] */
/* @0x1d1a3c mov r3, #76 */
/* @0x1d1a40 ldr r2, [sp, #0x1c] */
/* @0x1d1a44 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1d1a48 str r0, [r6, #0x4] */
/* @0x1d1a4c str r8, [r6] */
/* @0x1d1a50 b 0x1d1850 <_Z7EndRoomb+0x12c> */
/* @0x1d1a54 bl 0x1b8f68 <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom> */
/* @0x1d1a58 ldr r2, [pc, #0xcc] */
/* @0x1d1a5c ldr r3, [pc, #0xcc] */
/* @0x1d1a60 ldr r5, [r7, r2] */
/* @0x1d1a64 ldr r4, [r7, r3] */
/* @0x1d1a68 ldr r3, [r5] */
/* @0x1d1a6c ldr r2, [r4] */
/* @0x1d1a70 cmp r3, r2 */
/* @0x1d1a74 bge 0x1d1ae4 <_Z7EndRoomb+0x3c0> */
/* @0x1d1a78 ldr r1, [r4, #0x4] */
/* @0x1d1a7c add r2, r1, r3, lsl #2 */
/* @0x1d1a80 ldr r6, [r1, r3, lsl #2] */
/* @0x1d1a84 cmp r6, #0 */
/* @0x1d1a88 beq 0x1d1aec <_Z7EndRoomb+0x3c8> */
/* @0x1d1a8c mov r0, r6 */
/* @0x1d1a90 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1d1a94 mov r0, r6 */
/* @0x1d1a98 bl 0x27d1d0 <_ZdlPv> */
/* @0x1d1a9c ldr r2, [r5] */
/* @0x1d1aa0 ldr r3, [r4, #0x4] */
/* @0x1d1aa4 add r2, r3, r2, lsl #2 */
/* @0x1d1aa8 b 0x1d1aec <_Z7EndRoomb+0x3c8> */
/* @0x1d1aac ldr r3, [pc, #0x80] */
/* @0x1d1ab0 ldr r0, [r7, r3] */
/* @0x1d1ab4 bl 0x16ecf0 <_ZN14CCameraManager7EndRoomEv> */
/* @0x1d1ab8 b 0x1d174c <_Z7EndRoomb+0x28> */
/* @0x1d1abc ldr r3, [sp, #0x18] */
/* @0x1d1ac0 ldr r0, [r3] */
/* @0x1d1ac4 bl 0x1abad4 <_ZN5CRoom15CleanPersistentEv> */
/* @0x1d1ac8 mov r0, #7 */
/* @0x1d1acc mov r1, #3 */
/* @0x1d1ad0 bl 0xf33b0 <_Z17Perform_Event_Allii> */
/* @0x1d1ad4 ldr r2, [sp, #0x18] */
/* @0x1d1ad8 ldr r0, [r2] */
/* @0x1d1adc bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d1ae0 b 0x1d179c <_Z7EndRoomb+0x78> */
/* @0x1d1ae4 ldr r2, [r4, #0x4] */
/* @0x1d1ae8 add r2, r2, r3, lsl #2 */
/* @0x1d1aec mov r3, #0 */
/* @0x1d1af0 str r3, [r2] */
/* @0x1d1af4 b 0x1d19d8 <_Z7EndRoomb+0x2b4> */
/* @0x1d1af8 mov r0, r3 */
/* @0x1d1afc b 0x1d18e0 <_Z7EndRoomb+0x1bc> */
/* @0x1d1b00 eoreq r0, r2, r8, lsl r5 */
/* @0x1d1b04 .word 0xffffbcd4 */
/* @0x1d1b08 .word 0xffffbcd8 */
/* @0x1d1b0c .word 0xffffc154 */
/* @0x1d1b10 .word 0xffffeef4 */
/* @0x1d1b14 .word 0xffffeef8 */
/* @0x1d1b18 ldrsheq pc, [r7], -r4 */
/* @0x1d1b1c ldrheq pc, [r7], -r8 */
/* @0x1d1b20 .word 0xffffc464 */
/* @0x1d1b24 .word 0xffffbff4 */
/* @0x1d1b28 .word 0xffffbff8 */
/* @0x1d1b2c .word 0xffffd784 */
/* @0x1d1b30 .word 0xffffeed8 */
/* @0x1d1b34 .word 0xffffc024 */

/* ── FUNC 0x1d1b38 · Run_EndGame() · size=380 · insn=95 */
/* @0x1d1b38 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1d1b3c mov r0, #1 */
/* @0x1d1b40 ldr r4, [pc, #0x160] */
/* @0x1d1b44 bl 0x1d1724 <_Z7EndRoomb> */
/* @0x1d1b48 ldr r4, [pc, r4] */
/* @0x1d1b4c ldr r3, [r4] */
/* @0x1d1b50 cmp r3, #0 */
/* @0x1d1b54 ble 0x1d1ba4 <_Z11Run_EndGamev+0x6c> */
/* @0x1d1b58 mov r5, #0 */
/* @0x1d1b5c mov r8, r5 */
/* @0x1d1b60 ldr r2, [r4, #0x4] */
/* @0x1d1b64 lsl r7, r5, #2 */
/* @0x1d1b68 add r3, r2, r7 */
/* @0x1d1b6c ldr r6, [r2, r5, lsl #2] */
/* @0x1d1b70 add r5, r5, #1 */
/* @0x1d1b74 cmp r6, #0 */
/* @0x1d1b78 mov r0, r6 */
/* @0x1d1b7c beq 0x1d1b94 <_Z11Run_EndGamev+0x5c> */
/* @0x1d1b80 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1d1b84 mov r0, r6 */
/* @0x1d1b88 bl 0x27d1d0 <_ZdlPv> */
/* @0x1d1b8c ldr r3, [r4, #0x4] */
/* @0x1d1b90 add r3, r3, r7 */
/* @0x1d1b94 str r8, [r3] */
/* @0x1d1b98 ldr r3, [r4] */
/* @0x1d1b9c cmp r3, r5 */
/* @0x1d1ba0 bgt 0x1d1b60 <_Z11Run_EndGamev+0x28> */
/* @0x1d1ba4 cmp r3, #0 */
/* @0x1d1ba8 beq 0x1d1c50 <_Z11Run_EndGamev+0x118> */
/* @0x1d1bac ldr r6, [r4, #0x4] */
/* @0x1d1bb0 cmp r6, #0 */
/* @0x1d1bb4 beq 0x1d1c98 <_Z11Run_EndGamev+0x160> */
/* @0x1d1bb8 ldr r3, [r4] */
/* @0x1d1bbc cmp r3, #0 */
/* @0x1d1bc0 ble 0x1d1c38 <_Z11Run_EndGamev+0x100> */
/* @0x1d1bc4 mov r5, #0 */
/* @0x1d1bc8 mov r9, r5 */
/* @0x1d1bcc ldr r1, [r6] */
/* @0x1d1bd0 movw r3, #0xfeee */
/* @0x1d1bd4 movt r3, #0xfeee */
/* @0x1d1bd8 movw r2, #0xfeee */
/* @0x1d1bdc cmp r1, r3 */
/* @0x1d1be0 movt r2, #0xfeee */
/* @0x1d1be4 lsl r8, r5, #2 */
/* @0x1d1be8 beq 0x1d1c28 <_Z11Run_EndGamev+0xf0> */
/* @0x1d1bec ldr r7, [r6, r5, lsl #2] */
/* @0x1d1bf0 add r3, r6, r8 */
/* @0x1d1bf4 cmp r7, #0 */
/* @0x1d1bf8 mov r0, r7 */
/* @0x1d1bfc beq 0x1d1c28 <_Z11Run_EndGamev+0xf0> */
/* @0x1d1c00 ldr r1, [r7] */
/* @0x1d1c04 cmp r1, r2 */
/* @0x1d1c08 beq 0x1d1c20 <_Z11Run_EndGamev+0xe8> */
/* @0x1d1c0c bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1d1c10 mov r0, r7 */
/* @0x1d1c14 bl 0x27d1d0 <_ZdlPv> */
/* @0x1d1c18 ldr r3, [r4, #0x4] */
/* @0x1d1c1c add r3, r3, r8 */
/* @0x1d1c20 str r9, [r3] */
/* @0x1d1c24 ldr r6, [r4, #0x4] */
/* @0x1d1c28 ldr r3, [r4] */
/* @0x1d1c2c add r5, r5, #1 */
/* @0x1d1c30 cmp r5, r3 */
/* @0x1d1c34 blt 0x1d1bcc <_Z11Run_EndGamev+0x94> */
/* @0x1d1c38 mov r0, r6 */
/* @0x1d1c3c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d1c40 mov r3, #0 */
/* @0x1d1c44 str r3, [r4, #0x4] */
/* @0x1d1c48 mov r3, #0 */
/* @0x1d1c4c str r3, [r4] */
/* @0x1d1c50 ldr r3, [pc, #0x54] */
/* @0x1d1c54 mov r4, #0 */
/* @0x1d1c58 ldr r3, [pc, r3] */
/* @0x1d1c5c str r4, [r3] */
/* @0x1d1c60 bl 0xf6610 <_Z18Extension_Finalizev> */
/* @0x1d1c64 cmp r0, r4 */
/* @0x1d1c68 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1d1c6c mov r0, r4 */
/* @0x1d1c70 bl 0x17af8c <_Z20GR_Window_Set_Cursori> */
/* @0x1d1c74 mov r0, #1 */
/* @0x1d1c78 bl 0x21a3bc <_Z13Audio_StopAllb> */
/* @0x1d1c7c bl 0x173884 <_Z22GR_Text_ResetToDefaultv> */
/* @0x1d1c80 ldr r0, [pc, #0x28] */
/* @0x1d1c84 ldr r0, [pc, r0] */
/* @0x1d1c88 bl 0x167c34 <_ZN18RenderStateManager5ResetEv> */
/* @0x1d1c8c mov r0, r4 */
/* @0x1d1c90 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1d1c94 b 0xd6aac <_Z12MarkAndSweepP12YYObjectBase> */
/* @0x1d1c98 mov r0, r6 */
/* @0x1d1c9c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d1ca0 str r6, [r4, #0x4] */
/* @0x1d1ca4 b 0x1d1c48 <_Z11Run_EndGamev+0x110> */
/* @0x1d1ca8 eoreq lr, r1, r0, ror #31 */
/* @0x1d1cac .word 0x0021bcd0 */
/* @0x1d1cb0 eoreq r12, r1, r4, ror r0 */

/* ── FUNC 0x1d1cb4 · LoadGame() · size=56 · insn=14 */
/* @0x1d1cb4 push {r3, lr} */
/* @0x1d1cb8 mvn r2, #0 */
/* @0x1d1cbc ldr r3, [pc, #0x20] */
/* @0x1d1cc0 ldr r3, [pc, r3] */
/* @0x1d1cc4 str r2, [r3] */
/* @0x1d1cc8 bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0x1d1ccc ldr r3, [pc, #0x14] */
/* @0x1d1cd0 ldr r3, [pc, r3] */
/* @0x1d1cd4 ldr r3, [r3] */
/* @0x1d1cd8 ldr r0, [r3] */
/* @0x1d1cdc pop {r3, lr} */
/* @0x1d1ce0 b 0x1d14fc <_Z16Command_LoadGamePKc> */
/* @0x1d1ce4 eoreq r12, r1, r4, ror #1 */
/* @0x1d1ce8 eoreq lr, r1, r12, asr #28 */

/* ── FUNC 0x1d1cec · HandleInstanceMovement(bool) · size=372 · insn=93 */
/* @0x1d1cec push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d1cf0 mov r5, r0 */
/* @0x1d1cf4 ldr r8, [pc, #0x148] */
/* @0x1d1cf8 ldr r3, [pc, #0x148] */
/* @0x1d1cfc add r8, pc, r8 */
/* @0x1d1d00 ldr r9, [r8, r3] */
/* @0x1d1d04 ldrb r3, [r9] */
/* @0x1d1d08 cmp r3, #0 */
/* @0x1d1d0c bne 0x1d1d70 <_Z22HandleInstanceMovementb+0x84> */
/* @0x1d1d10 ldr r3, [pc, #0x134] */
/* @0x1d1d14 ldr r3, [r8, r3] */
/* @0x1d1d18 ldr r3, [r3] */
/* @0x1d1d1c ldr r4, [r3, #0xb4] */
/* @0x1d1d20 cmp r4, #0 */
/* @0x1d1d24 beq 0x1d1da4 <_Z22HandleInstanceMovementb+0xb8> */
/* @0x1d1d28 ldr r2, [pc, #0x120] */
/* @0x1d1d2c ldr r2, [r8, r2] */
/* @0x1d1d30 ldrb r2, [r2] */
/* @0x1d1d34 cmp r2, #0 */
/* @0x1d1d38 ldreq r1, [r3, #0xc] */
/* @0x1d1d3c bne 0x1d1d88 <_Z22HandleInstanceMovementb+0x9c> */
/* @0x1d1d40 mov r0, r4 */
/* @0x1d1d44 mov r2, r5 */
/* @0x1d1d48 mov r4, #1 */
/* @0x1d1d4c bl 0x2382b0 <_ZN13CPhysicsWorld6UpdateEib> */
/* @0x1d1d50 ldrb r3, [r9] */
/* @0x1d1d54 cmp r3, #0 */
/* @0x1d1d58 beq 0x1d1d68 <_Z22HandleInstanceMovementb+0x7c> */
/* @0x1d1d5c ldr r3, [pc, #0xf0] */
/* @0x1d1d60 ldr r0, [r8, r3] */
/* @0x1d1d64 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1d1d68 mov r0, r4 */
/* @0x1d1d6c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d1d70 ldr r3, [pc, #0xdc] */
/* @0x1d1d74 mov r1, #6 */
/* @0x1d1d78 mov r2, #5 */
/* @0x1d1d7c ldr r0, [r8, r3] */
/* @0x1d1d80 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1d1d84 b 0x1d1d10 <_Z22HandleInstanceMovementb+0x24> */
/* @0x1d1d88 ldr r3, [pc, #0xc8] */
/* @0x1d1d8c ldr r0, [r8, r3] */
/* @0x1d1d90 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1d1d94 vmov d7, r0, r1 */
/* @0x1d1d98 vcvt.s32.f64 s15, d7 */
/* @0x1d1d9c vmov r1, s15 */
/* @0x1d1da0 b 0x1d1d40 <_Z22HandleInstanceMovementb+0x54> */
/* @0x1d1da4 ldr r2, [pc, #0xb0] */
/* @0x1d1da8 ldr r10, [r3, #0x80] */
/* @0x1d1dac ldr r1, [r8, r2] */
/* @0x1d1db0 ldrd r6, r7, [r1] */
/* @0x1d1db4 adds r2, r6, #1 */
/* @0x1d1db8 adc r3, r7, #0 */
/* @0x1d1dbc cmp r10, #0 */
/* @0x1d1dc0 strd r2, r3, [r1] */
/* @0x1d1dc4 beq 0x1d1e3c <_Z22HandleInstanceMovementb+0x150> */
/* @0x1d1dc8 mov r0, r10 */
/* @0x1d1dcc ldr r11, [r10, #0x178] */
/* @0x1d1dd0 bl 0x193f2c <_ZN9CInstance11Adapt_SpeedEv> */
/* @0x1d1dd4 mov r0, r10 */
/* @0x1d1dd8 bl 0x19411c <_ZN9CInstance10Adapt_PathEv> */
/* @0x1d1ddc cmp r0, #0 */
/* @0x1d1de0 beq 0x1d1e08 <_Z22HandleInstanceMovementb+0x11c> */
/* @0x1d1de4 ldrd r4, r5, [r10, #112] */
/* @0x1d1de8 mov r0, r10 */
/* @0x1d1dec mov r1, r10 */
/* @0x1d1df0 mov r2, #7 */
/* @0x1d1df4 cmp r6, r4 */
/* @0x1d1df8 sbcs r12, r7, r5 */
/* @0x1d1dfc mov r3, #8 */
/* @0x1d1e00 blt 0x1d1e08 <_Z22HandleInstanceMovementb+0x11c> */
/* @0x1d1e04 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d1e08 vldr s13, [r10, #180] */
/* @0x1d1e0c vldr s15, [r10, #224] */
/* @0x1d1e10 vadd.f32 s15, s13, s15 */
/* @0x1d1e14 vldr s14, [r10, #184] */
/* @0x1d1e18 mov r0, r10 */
/* @0x1d1e1c vmov r1, s15 */
/* @0x1d1e20 vldr s15, [r10, #228] */
/* @0x1d1e24 vadd.f32 s15, s14, s15 */
/* @0x1d1e28 mov r10, r11 */
/* @0x1d1e2c vmov r2, s15 */
/* @0x1d1e30 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1d1e34 cmp r11, #0 */
/* @0x1d1e38 bne 0x1d1dc8 <_Z22HandleInstanceMovementb+0xdc> */
/* @0x1d1e3c mov r4, #0 */
/* @0x1d1e40 b 0x1d1d50 <_Z22HandleInstanceMovementb+0x64> */
/* @0x1d1e44 eoreq pc, r1, r4, asr pc */
/* @0x1d1e48 .word 0xffffbf18 */
/* @0x1d1e4c .word 0xffffbcd8 */
/* @0x1d1e50 .word 0xffffbcd4 */
/* @0x1d1e54 .word 0xffffbf1c */
/* @0x1d1e58 .word 0xffffbcdc */
/* @0x1d1e5c .word 0xffffdeb4 */

/* ── FUNC 0x1d1e60 · base64_encode(char const*, unsigned int, char*) · size=400 · insn=100 */
/* @0x1d1e60 push {r4, r5, r6, r7, r8, r9} */
/* @0x1d1e64 add r1, r0, r1 */
/* @0x1d1e68 ldr r5, [pc, #0x178] */
/* @0x1d1e6c sub sp, sp, #8 */
/* @0x1d1e70 mov r3, #0 */
/* @0x1d1e74 add r5, pc, r5 */
/* @0x1d1e78 b 0x1d1e80 <_Z13base64_encodePKcjPc+0x20> */
/* @0x1d1e7c mov r3, r12 */
/* @0x1d1e80 cmp r0, r1 */
/* @0x1d1e84 beq 0x1d1f0c <_Z13base64_encodePKcjPc+0xac> */
/* @0x1d1e88 add r12, r3, #1 */
/* @0x1d1e8c ldrb r4, [r0], #1 */
/* @0x1d1e90 add r6, sp, #8 */
/* @0x1d1e94 cmp r12, #3 */
/* @0x1d1e98 add r3, r6, r3 */
/* @0x1d1e9c strb r4, [r3, #-0x8] */
/* @0x1d1ea0 bne 0x1d1e7c <_Z13base64_encodePKcjPc+0x1c> */
/* @0x1d1ea4 ldrb r12, [sp] */
/* @0x1d1ea8 mov r3, #0 */
/* @0x1d1eac ldrb r6, [sp, #0x1] */
/* @0x1d1eb0 ldrb r4, [sp, #0x2] */
/* @0x1d1eb4 and r9, r12, #3 */
/* @0x1d1eb8 and r8, r6, #15 */
/* @0x1d1ebc lsr r12, r12, #2 */
/* @0x1d1ec0 lsr r6, r6, #4 */
/* @0x1d1ec4 strb r12, [sp, #0x4] */
/* @0x1d1ec8 lsr r7, r4, #6 */
/* @0x1d1ecc add r6, r6, r9, lsl #4 */
/* @0x1d1ed0 add r7, r7, r8, lsl #2 */
/* @0x1d1ed4 and r4, r4, #63 */
/* @0x1d1ed8 strb r6, [sp, #0x5] */
/* @0x1d1edc strb r7, [sp, #0x6] */
/* @0x1d1ee0 strb r4, [sp, #0x7] */
/* @0x1d1ee4 ldrb r12, [r5, r12] */
/* @0x1d1ee8 add r4, sp, #4 */
/* @0x1d1eec strb r12, [r2, r3] */
/* @0x1d1ef0 add r3, r3, #1 */
/* @0x1d1ef4 cmp r3, #4 */
/* @0x1d1ef8 ldrbne r12, [r3, r4] */
/* @0x1d1efc bne 0x1d1ee4 <_Z13base64_encodePKcjPc+0x84> */
/* @0x1d1f00 add r2, r2, #4 */
/* @0x1d1f04 mov r12, #0 */
/* @0x1d1f08 b 0x1d1e7c <_Z13base64_encodePKcjPc+0x1c> */
/* @0x1d1f0c cmp r3, #0 */
/* @0x1d1f10 mov r0, r3 */
/* @0x1d1f14 beq 0x1d1fa4 <_Z13base64_encodePKcjPc+0x144> */
/* @0x1d1f18 cmp r3, #2 */
/* @0x1d1f1c movle r12, sp */
/* @0x1d1f20 movle r1, #0 */
/* @0x1d1f24 bgt 0x1d1f38 <_Z13base64_encodePKcjPc+0xd8> */
/* @0x1d1f28 strb r1, [r12, r3] */
/* @0x1d1f2c add r3, r3, #1 */
/* @0x1d1f30 cmp r3, #3 */
/* @0x1d1f34 bne 0x1d1f28 <_Z13base64_encodePKcjPc+0xc8> */
/* @0x1d1f38 ldrb r1, [sp] */
/* @0x1d1f3c mov r3, #0 */
/* @0x1d1f40 ldrb r4, [sp, #0x1] */
/* @0x1d1f44 and r7, r1, #3 */
/* @0x1d1f48 ldrb r12, [sp, #0x2] */
/* @0x1d1f4c and r6, r4, #15 */
/* @0x1d1f50 lsr r1, r1, #2 */
/* @0x1d1f54 lsr r4, r4, #4 */
/* @0x1d1f58 strb r1, [sp, #0x4] */
/* @0x1d1f5c add r4, r4, r7, lsl #4 */
/* @0x1d1f60 strb r4, [sp, #0x5] */
/* @0x1d1f64 ldr r4, [pc, #0x80] */
/* @0x1d1f68 lsr r5, r12, #6 */
/* @0x1d1f6c add r5, r5, r6, lsl #2 */
/* @0x1d1f70 and r12, r12, #63 */
/* @0x1d1f74 add r4, pc, r4 */
/* @0x1d1f78 strb r5, [sp, #0x6] */
/* @0x1d1f7c strb r12, [sp, #0x7] */
/* @0x1d1f80 ldrb r1, [r4, r1] */
/* @0x1d1f84 add r12, sp, #4 */
/* @0x1d1f88 strb r1, [r2, r3] */
/* @0x1d1f8c add r3, r3, #1 */
/* @0x1d1f90 cmp r3, r0 */
/* @0x1d1f94 bgt 0x1d1fb8 <_Z13base64_encodePKcjPc+0x158> */
/* @0x1d1f98 ldrb r1, [r3, r12] */
/* @0x1d1f9c b 0x1d1f80 <_Z13base64_encodePKcjPc+0x120> */
/* @0x1d1fa0 mov r2, r3 */
/* @0x1d1fa4 mov r3, #0 */
/* @0x1d1fa8 strb r3, [r2] */
/* @0x1d1fac add sp, sp, #8 */
/* @0x1d1fb0 pop {r4, r5, r6, r7, r8, r9} */
/* @0x1d1fb4 bx lr */
/* @0x1d1fb8 bic r3, r0, r0, asr #31 */
/* @0x1d1fbc cmp r0, #3 */
/* @0x1d1fc0 add r3, r3, #1 */
/* @0x1d1fc4 add r3, r2, r3 */
/* @0x1d1fc8 beq 0x1d1fa0 <_Z13base64_encodePKcjPc+0x140> */
/* @0x1d1fcc rsb r2, r0, #3 */
/* @0x1d1fd0 mov r1, #61 */
/* @0x1d1fd4 add r2, r3, r2 */
/* @0x1d1fd8 strb r1, [r3], #1 */
/* @0x1d1fdc cmp r3, r2 */
/* @0x1d1fe0 bne 0x1d1fd8 <_Z13base64_encodePKcjPc+0x178> */
/* @0x1d1fe4 b 0x1d1fa4 <_Z13base64_encodePKcjPc+0x144> */
/* @0x1d1fe8 andseq r11, r8, r8, asr pc */
/* @0x1d1fec andseq r11, r8, r8, asr lr */

/* ── FUNC 0x1d1ff0 · base64_decode(char const*, unsigned int, char*, bool) · size=572 · insn=143 */
/* @0x1d1ff0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d1ff4 sub sp, sp, #20 */
/* @0x1d1ff8 mov r5, r1 */
/* @0x1d1ffc mov r4, r2 */
/* @0x1d2000 str r3, [sp, #0x4] */
/* @0x1d2004 mov r6, r0 */
/* @0x1d2008 bl 0xb6538 <strlen@plt> */
/* @0x1d200c ldr r3, [pc, #0x20c] */
/* @0x1d2010 sub r12, r5, #1 */
/* @0x1d2014 mov r2, #0 */
/* @0x1d2018 add r12, r4, r12 */
/* @0x1d201c add r5, sp, #15 */
/* @0x1d2020 add r3, pc, r3 */
/* @0x1d2024 mov r1, r2 */
/* @0x1d2028 cmp r2, r0 */
/* @0x1d202c beq 0x1d2084 <_Z13base64_decodePKcjPcb+0x94> */
/* @0x1d2030 ldrb r7, [r6, r2] */
/* @0x1d2034 cmp r7, #61 */
/* @0x1d2038 beq 0x1d2084 <_Z13base64_decodePKcjPcb+0x94> */
/* @0x1d203c ldr r8, [pc, #0x1e0] */
/* @0x1d2040 ldr r8, [pc, r8] */
/* @0x1d2044 ldr r8, [r8] */
/* @0x1d2048 add r8, r8, r7 */
/* @0x1d204c ldrb r8, [r8, #0x1] */
/* @0x1d2050 tst r8, #7 */
/* @0x1d2054 beq 0x1d2200 <_Z13base64_decodePKcjPcb+0x210> */
/* @0x1d2058 add r8, r1, #1 */
/* @0x1d205c add r9, sp, #16 */
/* @0x1d2060 add r1, r9, r1 */
/* @0x1d2064 cmp r8, #4 */
/* @0x1d2068 add r2, r2, #1 */
/* @0x1d206c addeq r9, sp, #11 */
/* @0x1d2070 strb r7, [r1, #-0x4] */
/* @0x1d2074 beq 0x1d2180 <_Z13base64_decodePKcjPcb+0x190> */
/* @0x1d2078 cmp r2, r0 */
/* @0x1d207c mov r1, r8 */
/* @0x1d2080 bne 0x1d2030 <_Z13base64_decodePKcjPcb+0x40> */
/* @0x1d2084 subs r6, r1, #0 */
/* @0x1d2088 beq 0x1d214c <_Z13base64_decodePKcjPcb+0x15c> */
/* @0x1d208c cmp r1, #3 */
/* @0x1d2090 bgt 0x1d20ac <_Z13base64_decodePKcjPcb+0xbc> */
/* @0x1d2094 add r2, sp, #12 */
/* @0x1d2098 mov r3, #0 */
/* @0x1d209c strb r3, [r2, r1] */
/* @0x1d20a0 add r1, r1, #1 */
/* @0x1d20a4 cmp r1, #4 */
/* @0x1d20a8 bne 0x1d209c <_Z13base64_decodePKcjPcb+0xac> */
/* @0x1d20ac ldr r0, [pc, #0x174] */
/* @0x1d20b0 add r5, sp, #11 */
/* @0x1d20b4 add r7, sp, #15 */
/* @0x1d20b8 add r0, pc, r0 */
/* @0x1d20bc ldrb r1, [r5, #0x1] */
/* @0x1d20c0 mov r3, #64 */
/* @0x1d20c4 b 0x1d20d0 <_Z13base64_decodePKcjPcb+0xe0> */
/* @0x1d20c8 subs r3, r3, #1 */
/* @0x1d20cc blo 0x1d2218 <_Z13base64_decodePKcjPcb+0x228> */
/* @0x1d20d0 ldrb r2, [r3, r0] */
/* @0x1d20d4 cmp r2, r1 */
/* @0x1d20d8 bne 0x1d20c8 <_Z13base64_decodePKcjPcb+0xd8> */
/* @0x1d20dc uxtb r3, r3 */
/* @0x1d20e0 strb r3, [r5, #0x1]! */
/* @0x1d20e4 cmp r5, r7 */
/* @0x1d20e8 bne 0x1d20bc <_Z13base64_decodePKcjPcb+0xcc> */
/* @0x1d20ec ldrb r2, [sp, #0xd] */
/* @0x1d20f0 cmp r6, #1 */
/* @0x1d20f4 ldrb r3, [sp, #0xe] */
/* @0x1d20f8 ldrb r7, [sp, #0xc] */
/* @0x1d20fc ubfx r0, r2, #0x4, #0x2 */
/* @0x1d2100 ldrb r1, [sp, #0xf] */
/* @0x1d2104 ubfx r5, r3, #0x2, #0x4 */
/* @0x1d2108 add r2, r5, r2, lsl #4 */
/* @0x1d210c strb r2, [sp, #0x9] */
/* @0x1d2110 add r0, r0, r7, lsl #2 */
/* @0x1d2114 add r3, r1, r3, lsl #6 */
/* @0x1d2118 strb r0, [sp, #0x8] */
/* @0x1d211c strb r3, [sp, #0xa] */
/* @0x1d2120 beq 0x1d214c <_Z13base64_decodePKcjPcb+0x15c> */
/* @0x1d2124 sub r6, r6, #1 */
/* @0x1d2128 mov r3, #0 */
/* @0x1d212c cmp r12, r4 */
/* @0x1d2130 add r2, sp, #8 */
/* @0x1d2134 ldrbhi r2, [r3, r2] */
/* @0x1d2138 add r3, r3, #1 */
/* @0x1d213c strbhi r2, [r4] */
/* @0x1d2140 addhi r4, r4, #1 */
/* @0x1d2144 cmp r3, r6 */
/* @0x1d2148 bne 0x1d212c <_Z13base64_decodePKcjPcb+0x13c> */
/* @0x1d214c ldr r3, [sp, #0x4] */
/* @0x1d2150 cmp r4, r12 */
/* @0x1d2154 movhs r3, #0 */
/* @0x1d2158 andlo r3, r3, #1 */
/* @0x1d215c cmp r3, #0 */
/* @0x1d2160 movne r3, #0 */
/* @0x1d2164 strbne r3, [r4] */
/* @0x1d2168 add sp, sp, #20 */
/* @0x1d216c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d2170 uxtb r1, r1 */
/* @0x1d2174 strb r1, [r9, #0x1]! */
/* @0x1d2178 cmp r9, r5 */
/* @0x1d217c beq 0x1d21a4 <_Z13base64_decodePKcjPcb+0x1b4> */
/* @0x1d2180 ldrb r8, [r9, #0x1] */
/* @0x1d2184 mov r1, #64 */
/* @0x1d2188 b 0x1d2194 <_Z13base64_decodePKcjPcb+0x1a4> */
/* @0x1d218c subs r1, r1, #1 */
/* @0x1d2190 blo 0x1d2210 <_Z13base64_decodePKcjPcb+0x220> */
/* @0x1d2194 ldrb r7, [r1, r3] */
/* @0x1d2198 cmp r7, r8 */
/* @0x1d219c bne 0x1d218c <_Z13base64_decodePKcjPcb+0x19c> */
/* @0x1d21a0 b 0x1d2170 <_Z13base64_decodePKcjPcb+0x180> */
/* @0x1d21a4 ldrb r8, [sp, #0xd] */
/* @0x1d21a8 mov r1, #0 */
/* @0x1d21ac ldrb r11, [sp, #0xc] */
/* @0x1d21b0 ldrb r7, [sp, #0xe] */
/* @0x1d21b4 ubfx r10, r8, #0x4, #0x2 */
/* @0x1d21b8 ldrb r9, [sp, #0xf] */
/* @0x1d21bc add r11, r10, r11, lsl #2 */
/* @0x1d21c0 ubfx r10, r7, #0x2, #0x4 */
/* @0x1d21c4 add r8, r10, r8, lsl #4 */
/* @0x1d21c8 add r7, r9, r7, lsl #6 */
/* @0x1d21cc strb r11, [sp, #0x8] */
/* @0x1d21d0 strb r8, [sp, #0x9] */
/* @0x1d21d4 strb r7, [sp, #0xa] */
/* @0x1d21d8 cmp r12, r4 */
/* @0x1d21dc add r7, sp, #8 */
/* @0x1d21e0 ldrbhi r7, [r1, r7] */
/* @0x1d21e4 add r1, r1, #1 */
/* @0x1d21e8 strbhi r7, [r4] */
/* @0x1d21ec addhi r4, r4, #1 */
/* @0x1d21f0 cmp r1, #3 */
/* @0x1d21f4 bne 0x1d21d8 <_Z13base64_decodePKcjPcb+0x1e8> */
/* @0x1d21f8 mov r1, #0 */
/* @0x1d21fc b 0x1d2028 <_Z13base64_decodePKcjPcb+0x38> */
/* @0x1d2200 and r8, r7, #251 */
/* @0x1d2204 cmp r8, #43 */
/* @0x1d2208 beq 0x1d2058 <_Z13base64_decodePKcjPcb+0x68> */
/* @0x1d220c b 0x1d2084 <_Z13base64_decodePKcjPcb+0x94> */
/* @0x1d2210 mov r1, #255 */
/* @0x1d2214 b 0x1d2174 <_Z13base64_decodePKcjPcb+0x184> */
/* @0x1d2218 mov r3, #255 */
/* @0x1d221c b 0x1d20e0 <_Z13base64_decodePKcjPcb+0xf0> */
/* @0x1d2220 andseq r11, r8, r12, lsr #27 */
/* @0x1d2224 eoreq r11, r1, r0, asr #18 */
/* @0x1d2228 andseq r11, r8, r4, lsl sp */

/* ── FUNC 0x1d222c · DecodeString(char*) · size=108 · insn=27 */
/* @0x1d222c ldr r3, [pc, #0x5c] */
/* @0x1d2230 mov r1, r0 */
/* @0x1d2234 ldr r2, [pc, #0x58] */
/* @0x1d2238 ldr r3, [pc, r3] */
/* @0x1d223c str r4, [sp, #-0x4]! */
/* @0x1d2240 ldr r2, [pc, r2] */
/* @0x1d2244 ldr r12, [r3] */
/* @0x1d2248 add r4, r12, #1 */
/* @0x1d224c cmp r4, #3 */
/* @0x1d2250 add r0, r2, r12, lsl #11 */
/* @0x1d2254 movgt r4, #0 */
/* @0x1d2258 str r4, [r3] */
/* @0x1d225c mov r3, #0 */
/* @0x1d2260 strb r3, [r2, r12, lsl #11] */
/* @0x1d2264 ldrb r3, [r1] */
/* @0x1d2268 cmp r3, #0 */
/* @0x1d226c beq 0x1d2288 <_Z12DecodeStringPc+0x5c> */
/* @0x1d2270 mov r2, r0 */
/* @0x1d2274 eor r3, r3, #26 */
/* @0x1d2278 strb r3, [r2], #1 */
/* @0x1d227c ldrb r3, [r1, #0x1]! */
/* @0x1d2280 cmp r3, #0 */
/* @0x1d2284 bne 0x1d2274 <_Z12DecodeStringPc+0x48> */
/* @0x1d2288 ldr r4, [sp], #4 */
/* @0x1d228c bx lr */
/* @0x1d2290 eoreq lr, r1, r4, lsl r9 */
/* @0x1d2294 eoreq lr, r1, r0, lsl r9 */

/* ── FUNC 0x1d2298 · RemoveQuotes(char*) · size=44 · insn=11 */
/* @0x1d2298 ldrb r3, [r0] */
/* @0x1d229c cmp r3, #0 */
/* @0x1d22a0 bxeq lr */
/* @0x1d22a4 add r2, r0, #1 */
/* @0x1d22a8 mov r1, #32 */
/* @0x1d22ac cmp r3, #34 */
/* @0x1d22b0 strbeq r1, [r2, #-0x1] */
/* @0x1d22b4 ldrb r3, [r2], #1 */
/* @0x1d22b8 cmp r3, #0 */
/* @0x1d22bc bne 0x1d22ac <_Z12RemoveQuotesPc+0x14> */
/* @0x1d22c0 bx lr */

/* ── FUNC 0x1d22c4 · urlEncode(char const*) · size=220 · insn=55 */
/* @0x1d22c4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1d22c8 sub sp, sp, #16 */
/* @0x1d22cc mov r4, #0 */
/* @0x1d22d0 mov r6, r0 */
/* @0x1d22d4 str r4, [sp, #0x4] */
/* @0x1d22d8 str r4, [sp, #0x8] */
/* @0x1d22dc str r4, [sp, #0xc] */
/* @0x1d22e0 bl 0xb6538 <strlen@plt> */
/* @0x1d22e4 subs r7, r0, #0 */
/* @0x1d22e8 ble 0x1d238c <_Z9urlEncodePKc+0xc8> */
/* @0x1d22ec ldr r10, [pc, #0xa0] */
/* @0x1d22f0 add r5, sp, #4 */
/* @0x1d22f4 ldr r8, [pc, #0x9c] */
/* @0x1d22f8 ldr r9, [pc, #0x9c] */
/* @0x1d22fc ldr r10, [pc, r10] */
/* @0x1d2300 add r8, pc, r8 */
/* @0x1d2304 add r9, pc, r9 */
/* @0x1d2308 ldrb r3, [r6, r4] */
/* @0x1d230c mov r0, r5 */
/* @0x1d2310 ldr r12, [r10] */
/* @0x1d2314 mov r1, r8 */
/* @0x1d2318 sub lr, r3, #45 */
/* @0x1d231c add r12, r12, r3 */
/* @0x1d2320 mov r2, r3 */
/* @0x1d2324 ldrb r12, [r12, #0x1] */
/* @0x1d2328 tst r12, #7 */
/* @0x1d232c bne 0x1d234c <_Z9urlEncodePKc+0x88> */
/* @0x1d2330 cmp r3, #95 */
/* @0x1d2334 cmpne lr, #1 */
/* @0x1d2338 bls 0x1d234c <_Z9urlEncodePKc+0x88> */
/* @0x1d233c cmp r3, #126 */
/* @0x1d2340 movne r2, r3 */
/* @0x1d2344 movne r0, r5 */
/* @0x1d2348 movne r1, r9 */
/* @0x1d234c add r4, r4, #1 */
/* @0x1d2350 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d2354 cmp r7, r4 */
/* @0x1d2358 bne 0x1d2308 <_Z9urlEncodePKc+0x44> */
/* @0x1d235c ldr r0, [sp, #0x4] */
/* @0x1d2360 mov r3, #0 */
/* @0x1d2364 str r3, [sp, #0xc] */
/* @0x1d2368 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1d236c mov r4, r0 */
/* @0x1d2370 ldr r0, [sp, #0x4] */
/* @0x1d2374 cmp r0, #0 */
/* @0x1d2378 beq 0x1d2380 <_Z9urlEncodePKc+0xbc> */
/* @0x1d237c bl 0xb655c <free@plt> */
/* @0x1d2380 mov r0, r4 */
/* @0x1d2384 add sp, sp, #16 */
/* @0x1d2388 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1d238c mov r0, r4 */
/* @0x1d2390 b 0x1d2360 <_Z9urlEncodePKc+0x9c> */
/* @0x1d2394 eoreq r11, r1, r4, lsl #13 */
/* @0x1d2398 ldrsbeq r7, [r6], -r12 */
/* @0x1d239c ldrsheq lr, [r7], -r12 */

/* ── FUNC 0x1d23a0 · CheckLicense · size=2816 · insn=704 */
/* @0x1d23a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d23a4 vpush {d8} */
/* @0x1d23a8 add r11, sp, #40 */
/* @0x1d23ac ldr r6, [pc, #0xa50] */
/* @0x1d23b0 sub sp, sp, #372 */
/* @0x1d23b4 ldr r2, [pc, #0xa4c] */
/* @0x1d23b8 add r6, pc, r6 */
/* @0x1d23bc ldr r3, [pc, #0xa48] */
/* @0x1d23c0 ldr r2, [r6, r2] */
/* @0x1d23c4 str r2, [r11, #-0x18c] */
/* @0x1d23c8 ldr r2, [r2] */
/* @0x1d23cc str r2, [r11, #-0x30] */
/* @0x1d23d0 ldr r5, [r6, r3] */
/* @0x1d23d4 ldr r3, [r5] */
/* @0x1d23d8 ldr r3, [r3, #0x4] */
/* @0x1d23dc cmp r3, #0 */
/* @0x1d23e0 bne 0x1d247c <CheckLicense+0xdc> */
/* @0x1d23e4 ldr r3, [pc, #0xa24] */
/* @0x1d23e8 ldr r3, [r6, r3] */
/* @0x1d23ec ldrd r2, r3, [r3] */
/* @0x1d23f0 orrs r1, r2, r3 */
/* @0x1d23f4 beq 0x1d2448 <CheckLicense+0xa8> */
/* @0x1d23f8 ldr r1, [pc, #0xa14] */
/* @0x1d23fc adds r4, r2, #1000 */
/* @0x1d2400 adc r5, r3, #0 */
/* @0x1d2404 ldr r1, [r6, r1] */
/* @0x1d2408 ldrd r0, r1, [r1] */
/* @0x1d240c cmp r1, r5 */
/* @0x1d2410 cmpeq r0, r4 */
/* @0x1d2414 beq 0x1d2448 <CheckLicense+0xa8> */
/* @0x1d2418 cmp r3, r1 */
/* @0x1d241c cmpeq r2, r0 */
/* @0x1d2420 beq 0x1d2cbc <CheckLicense+0x91c> */
/* @0x1d2424 ldr r3, [pc, #0x9ec] */
/* @0x1d2428 mov r2, #1 */
/* @0x1d242c ldr r3, [r6, r3] */
/* @0x1d2430 str r2, [r3] */
/* @0x1d2434 mov r0, #0 */
/* @0x1d2438 bl 0xb6688 <exit@plt> */
/* @0x1d243c cmp r0, r2 */
/* @0x1d2440 sbcs r12, r1, r3 */
/* @0x1d2444 blt 0x1d2de4 <CheckLicense+0xa44> */
/* @0x1d2448 ldr r3, [pc, #0x9c8] */
/* @0x1d244c ldr r3, [r6, r3] */
/* @0x1d2450 ldr r3, [r3] */
/* @0x1d2454 cmp r3, #0 */
/* @0x1d2458 bne 0x1d2434 <CheckLicense+0x94> */
/* @0x1d245c ldr r12, [r11, #-0x18c] */
/* @0x1d2460 ldr r2, [r11, #-0x30] */
/* @0x1d2464 ldr r3, [r12] */
/* @0x1d2468 cmp r2, r3 */
/* @0x1d246c bne 0x1d2e00 <CheckLicense+0xa60> */
/* @0x1d2470 sub sp, r11, #40 */
/* @0x1d2474 vpop {d8} */
/* @0x1d2478 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d247c mov r0, #3 */
/* @0x1d2480 mov r3, #0 */
/* @0x1d2484 str r3, [r11, #-0x178] */
/* @0x1d2488 bl 0xb6544 <malloc@plt> */
/* @0x1d248c ldr r4, [r11, #-0x178] */
/* @0x1d2490 mov r3, #3 */
/* @0x1d2494 str r3, [r11, #-0x17c] */
/* @0x1d2498 mov r2, #123 */
/* @0x1d249c add r4, r4, #1 */
/* @0x1d24a0 str r4, [r11, #-0x178] */
/* @0x1d24a4 mvn r3, r4 */
/* @0x1d24a8 add r3, r3, #3 */
/* @0x1d24ac cmp r3, #0 */
/* @0x1d24b0 strh r2, [r0] */
/* @0x1d24b4 movgt r2, r0 */
/* @0x1d24b8 str r0, [r11, #-0x180] */
/* @0x1d24bc ble 0x1d2b78 <CheckLicense+0x7d8> */
/* @0x1d24c0 sub r0, r11, #44 */
/* @0x1d24c4 sub r8, r11, #256 */
/* @0x1d24c8 mov r3, #0 */
/* @0x1d24cc strb r3, [r2, r4] */
/* @0x1d24d0 str r3, [r0, #-0x158]! */
/* @0x1d24d4 sub r7, r11, #169 */
/* @0x1d24d8 bl 0x15f574 <_Z6YYUDIDPPc> */
/* @0x1d24dc mov r0, r8 */
/* @0x1d24e0 bl 0x2140d8 <_Z7MD5InitP7MD5_CTX> */
/* @0x1d24e4 ldr r1, [r11, #-0x184] */
/* @0x1d24e8 sub r3, r11, #292 */
/* @0x1d24ec str r3, [r11, #-0x188] */
/* @0x1d24f0 ldr r9, [pc, #0x924] */
/* @0x1d24f4 sub r4, r11, #260 */
/* @0x1d24f8 mov r0, r1 */
/* @0x1d24fc mov r10, r3 */
/* @0x1d2500 str r1, [r11, #-0x194] */
/* @0x1d2504 bl 0xb6538 <strlen@plt> */
/* @0x1d2508 ldr r1, [r11, #-0x194] */
/* @0x1d250c add r9, pc, r9 */
/* @0x1d2510 mov r2, r0 */
/* @0x1d2514 mov r0, r8 */
/* @0x1d2518 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj> */
/* @0x1d251c mov r0, r8 */
/* @0x1d2520 bl 0x2141d0 <_Z8MD5FinalP7MD5_CTX> */
/* @0x1d2524 mov r0, r10 */
/* @0x1d2528 mov r1, r9 */
/* @0x1d252c add r10, r10, #2 */
/* @0x1d2530 ldrb r2, [r7, #0x1]! */
/* @0x1d2534 bl 0xb6550 <sprintf@plt> */
/* @0x1d2538 cmp r10, r4 */
/* @0x1d253c bne 0x1d2524 <CheckLicense+0x184> */
/* @0x1d2540 sub r7, r11, #384 */
/* @0x1d2544 ldr r1, [pc, #0x8d4] */
/* @0x1d2548 sub r2, r11, #292 */
/* @0x1d254c add r1, pc, r1 */
/* @0x1d2550 mov r0, r7 */
/* @0x1d2554 mov r10, r2 */
/* @0x1d2558 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d255c ldr r3, [pc, #0x8c0] */
/* @0x1d2560 ldr r3, [r6, r3] */
/* @0x1d2564 sub r8, r3, #1 */
/* @0x1d2568 mov r0, r10 */
/* @0x1d256c mov r1, r9 */
/* @0x1d2570 add r10, r10, #2 */
/* @0x1d2574 ldrb r2, [r8, #0x1]! */
/* @0x1d2578 bl 0xb6550 <sprintf@plt> */
/* @0x1d257c cmp r10, r4 */
/* @0x1d2580 bne 0x1d2568 <CheckLicense+0x1c8> */
/* @0x1d2584 ldr r1, [pc, #0x89c] */
/* @0x1d2588 mov r0, r7 */
/* @0x1d258c sub r2, r11, #292 */
/* @0x1d2590 sub r10, r11, #292 */
/* @0x1d2594 add r1, pc, r1 */
/* @0x1d2598 mov r4, #0 */
/* @0x1d259c bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d25a0 ldr r3, [r5] */
/* @0x1d25a4 mov r0, r10 */
/* @0x1d25a8 mov r1, r9 */
/* @0x1d25ac add r10, r10, #2 */
/* @0x1d25b0 add r3, r3, r4 */
/* @0x1d25b4 add r4, r4, #1 */
/* @0x1d25b8 ldrb r2, [r3, #0x8] */
/* @0x1d25bc bl 0xb6550 <sprintf@plt> */
/* @0x1d25c0 cmp r4, #16 */
/* @0x1d25c4 bne 0x1d25a0 <CheckLicense+0x200> */
/* @0x1d25c8 ldr r1, [pc, #0x85c] */
/* @0x1d25cc sub r2, r11, #292 */
/* @0x1d25d0 mov r0, r7 */
/* @0x1d25d4 add r1, pc, r1 */
/* @0x1d25d8 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d25dc ldr r3, [pc, #0x84c] */
/* @0x1d25e0 ldr r1, [pc, #0x84c] */
/* @0x1d25e4 mov r0, r7 */
/* @0x1d25e8 ldr r3, [r6, r3] */
/* @0x1d25ec add r1, pc, r1 */
/* @0x1d25f0 ldr r2, [r3] */
/* @0x1d25f4 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d25f8 ldr r3, [pc, #0x838] */
/* @0x1d25fc ldr r1, [pc, #0x838] */
/* @0x1d2600 mov r0, r7 */
/* @0x1d2604 ldr r3, [r6, r3] */
/* @0x1d2608 add r1, pc, r1 */
/* @0x1d260c ldr r12, [r3] */
/* @0x1d2610 ldr lr, [r12, #0x38] */
/* @0x1d2614 ldr r3, [r12, #0x30] */
/* @0x1d2618 ldr r2, [r12, #0x2c] */
/* @0x1d261c str lr, [sp] */
/* @0x1d2620 ldr r12, [r12, #0x34] */
/* @0x1d2624 str r12, [sp, #0x4] */
/* @0x1d2628 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d262c bl 0x159cf4 <_Z23YoYo_GetPlatform_DoWorkv> */
/* @0x1d2630 vmov d7, r0, r1 */
/* @0x1d2634 ldr r1, [pc, #0x804] */
/* @0x1d2638 mov r0, r7 */
/* @0x1d263c vcvt.u32.f64 s15, d7 */
/* @0x1d2640 add r1, pc, r1 */
/* @0x1d2644 vmov r2, s15 */
/* @0x1d2648 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d264c bl 0x15e5f8 <_Z11GetVersionMv> */
/* @0x1d2650 vmov d8, r0, r1 */
/* @0x1d2654 bl 0xb6598 <floor@plt> */
/* @0x1d2658 vmov d7, r0, r1 */
/* @0x1d265c mov r0, r7 */
/* @0x1d2660 vcmp.f64 d7, d8 */
/* @0x1d2664 vmrs APSR_nzcv, fpscr */
/* @0x1d2668 beq 0x1d2b60 <CheckLicense+0x7c0> */
/* @0x1d266c ldr r1, [pc, #0x7d0] */
/* @0x1d2670 vmov r2, r3, d8 */
/* @0x1d2674 add r1, pc, r1 */
/* @0x1d2678 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d267c bl 0x15f21c <_Z17GetLanguageStringv> */
/* @0x1d2680 ldr r1, [pc, #0x7c0] */
/* @0x1d2684 add r1, pc, r1 */
/* @0x1d2688 mov r2, r0 */
/* @0x1d268c mov r0, r7 */
/* @0x1d2690 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d2694 bl 0x15f230 <_Z15GetRegionStringv> */
/* @0x1d2698 ldr r1, [pc, #0x7ac] */
/* @0x1d269c add r1, pc, r1 */
/* @0x1d26a0 mov r2, r0 */
/* @0x1d26a4 mov r0, r7 */
/* @0x1d26a8 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d26ac bl 0x160240 <_Z17GetOSSpecificJSONv> */
/* @0x1d26b0 subs r4, r0, #0 */
/* @0x1d26b4 beq 0x1d2700 <CheckLicense+0x360> */
/* @0x1d26b8 bl 0xb6538 <strlen@plt> */
/* @0x1d26bc ldr r8, [r11, #-0x178] */
/* @0x1d26c0 ldr r2, [r11, #-0x17c] */
/* @0x1d26c4 mvn r3, r8 */
/* @0x1d26c8 add r3, r2, r3 */
/* @0x1d26cc add r5, r0, #1 */
/* @0x1d26d0 cmp r5, r3 */
/* @0x1d26d4 bgt 0x1d2d74 <CheckLicense+0x9d4> */
/* @0x1d26d8 ldr r0, [r11, #-0x180] */
/* @0x1d26dc add r0, r0, r8 */
/* @0x1d26e0 mov r1, r4 */
/* @0x1d26e4 bl 0xb65a4 <strcpy@plt> */
/* @0x1d26e8 ldr r3, [r11, #-0x178] */
/* @0x1d26ec mov r0, r4 */
/* @0x1d26f0 sub r3, r3, #1 */
/* @0x1d26f4 add r5, r3, r5 */
/* @0x1d26f8 str r5, [r11, #-0x178] */
/* @0x1d26fc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1d2700 bl 0x15e60c <_Z16GetBrowserWidthMv> */
/* @0x1d2704 vmov d8, r0, r1 */
/* @0x1d2708 bl 0x15e62c <_Z17GetBrowserHeightMv> */
/* @0x1d270c vcvt.s32.f64 s13, d8 */
/* @0x1d2710 vmov r2, s13 */
/* @0x1d2714 vmov d7, r0, r1 */
/* @0x1d2718 ldr r1, [pc, #0x730] */
/* @0x1d271c mov r0, r7 */
/* @0x1d2720 vcvt.s32.f64 s15, d7 */
/* @0x1d2724 add r1, pc, r1 */
/* @0x1d2728 vmov r3, s15 */
/* @0x1d272c bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d2730 bl 0x15f244 <_Z7GetDPIXv> */
/* @0x1d2734 vmov s16, r0 */
/* @0x1d2738 bl 0x15f258 <_Z7GetDPIYv> */
/* @0x1d273c ldr r1, [pc, #0x710] */
/* @0x1d2740 vcvt.f64.f32 d7, s16 */
/* @0x1d2744 add r1, pc, r1 */
/* @0x1d2748 vmov r2, r3, d7 */
/* @0x1d274c vmov s13, r0 */
/* @0x1d2750 mov r0, r7 */
/* @0x1d2754 vcvt.f64.f32 d7, s13 */
/* @0x1d2758 vstr d7, [sp] */
/* @0x1d275c bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d2760 ldr r3, [pc, #0x6f0] */
/* @0x1d2764 ldr r4, [r6, r3] */
/* @0x1d2768 ldrb r3, [r4] */
/* @0x1d276c cmp r3, #0 */
/* @0x1d2770 movne r2, #0 */
/* @0x1d2774 beq 0x1d2d68 <CheckLicense+0x9c8> */
/* @0x1d2778 ldr r1, [pc, #0x6dc] */
/* @0x1d277c mov r0, r7 */
/* @0x1d2780 add r1, pc, r1 */
/* @0x1d2784 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d2788 ldrb r3, [r4] */
/* @0x1d278c cmp r3, #0 */
/* @0x1d2790 bne 0x1d2bd0 <CheckLicense+0x830> */
/* @0x1d2794 bl 0x21dac0 <_Z19Audio_GetDeviceNamev> */
/* @0x1d2798 ldr r1, [pc, #0x6c0] */
/* @0x1d279c add r1, pc, r1 */
/* @0x1d27a0 mov r2, r0 */
/* @0x1d27a4 mov r0, r7 */
/* @0x1d27a8 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d27ac ldr r3, [pc, #0x6b0] */
/* @0x1d27b0 mov r0, #1 */
/* @0x1d27b4 mov r4, #0 */
/* @0x1d27b8 ldr r3, [r6, r3] */
/* @0x1d27bc str r4, [r11, #-0x16c] */
/* @0x1d27c0 ldr r8, [r3] */
/* @0x1d27c4 bl 0xb6544 <malloc@plt> */
/* @0x1d27c8 mov r3, #1 */
/* @0x1d27cc str r3, [r11, #-0x170] */
/* @0x1d27d0 cmp r8, r4 */
/* @0x1d27d4 str r0, [r11, #-0x174] */
/* @0x1d27d8 strb r4, [r0] */
/* @0x1d27dc ble 0x1d2df8 <CheckLicense+0xa58> */
/* @0x1d27e0 ldr r3, [pc, #0x680] */
/* @0x1d27e4 mov r5, r4 */
/* @0x1d27e8 ldr r12, [pc, #0x67c] */
/* @0x1d27ec add r12, pc, r12 */
/* @0x1d27f0 str r12, [r11, #-0x190] */
/* @0x1d27f4 sub r12, r11, #372 */
/* @0x1d27f8 str r12, [r11, #-0x188] */
/* @0x1d27fc ldr r10, [r6, r3] */
/* @0x1d2800 ldr r3, [r10] */
/* @0x1d2804 ldr r3, [r3, r4, lsl #2] */
/* @0x1d2808 ldrb r2, [r3] */
/* @0x1d280c cmp r2, #0 */
/* @0x1d2810 beq 0x1d2848 <CheckLicense+0x4a8> */
/* @0x1d2814 mov r0, r3 */
/* @0x1d2818 str r3, [r11, #-0x194] */
/* @0x1d281c bl 0x18ead0 <_ZNK9GMGamePad11ButtonCountEv> */
/* @0x1d2820 ldr r3, [r11, #-0x194] */
/* @0x1d2824 orr r5, r5, #1 */
/* @0x1d2828 mov r9, r0 */
/* @0x1d282c mov r0, r3 */
/* @0x1d2830 bl 0x18ed88 <_ZNK9GMGamePad9AxisCountEv> */
/* @0x1d2834 ldr r1, [r11, #-0x190] */
/* @0x1d2838 mov r2, r9 */
/* @0x1d283c mov r3, r0 */
/* @0x1d2840 sub r0, r11, #372 */
/* @0x1d2844 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d2848 add r4, r4, #1 */
/* @0x1d284c lsl r5, r5, #1 */
/* @0x1d2850 cmp r4, r8 */
/* @0x1d2854 bne 0x1d2800 <CheckLicense+0x460> */
/* @0x1d2858 ldr lr, [r11, #-0x174] */
/* @0x1d285c mov r2, r8 */
/* @0x1d2860 ldr r1, [pc, #0x608] */
/* @0x1d2864 mov r3, r5 */
/* @0x1d2868 mov r0, r7 */
/* @0x1d286c mov r12, #0 */
/* @0x1d2870 add r1, pc, r1 */
/* @0x1d2874 str lr, [sp] */
/* @0x1d2878 str r12, [r11, #-0x16c] */
/* @0x1d287c bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d2880 ldr r8, [r11, #-0x178] */
/* @0x1d2884 ldr r4, [r11, #-0x17c] */
/* @0x1d2888 mvn r3, r8 */
/* @0x1d288c add r3, r4, r3 */
/* @0x1d2890 cmp r3, #1 */
/* @0x1d2894 ble 0x1d2c54 <CheckLicense+0x8b4> */
/* @0x1d2898 ldr r12, [r11, #-0x180] */
/* @0x1d289c ldr lr, [pc, #0x5d0] */
/* @0x1d28a0 sub r7, r11, #348 */
/* @0x1d28a4 ldr r2, [pc, #0x5cc] */
/* @0x1d28a8 mov r3, #56 */
/* @0x1d28ac add lr, pc, lr */
/* @0x1d28b0 mov r1, #9 */
/* @0x1d28b4 add r2, pc, r2 */
/* @0x1d28b8 mov r0, r7 */
/* @0x1d28bc ldrh lr, [lr] */
/* @0x1d28c0 mov r5, #0 */
/* @0x1d28c4 sub r4, r11, #152 */
/* @0x1d28c8 strh lr, [r12, r8] */
/* @0x1d28cc ldr lr, [r11, #-0x178] */
/* @0x1d28d0 ldr r8, [r11, #-0x180] */
/* @0x1d28d4 add r12, lr, #2 */
/* @0x1d28d8 add lr, lr, #1 */
/* @0x1d28dc str lr, [r11, #-0x158] */
/* @0x1d28e0 lsl r12, r12, #1 */
/* @0x1d28e4 str r12, [r11, #-0x14c] */
/* @0x1d28e8 add lr, r12, #14 */
/* @0x1d28ec str r5, [r11, #-0x13c] */
/* @0x1d28f0 bic r12, lr, #7 */
/* @0x1d28f4 str r8, [r11, #-0x15c] */
/* @0x1d28f8 sub sp, sp, r12 */
/* @0x1d28fc str r5, [r11, #-0x138] */
/* @0x1d2900 add r8, sp, #8 */
/* @0x1d2904 str r5, [r11, #-0x134] */
/* @0x1d2908 str r5, [r11, #-0x178] */
/* @0x1d290c str r8, [r11, #-0x150] */
/* @0x1d2910 bl 0xb69a0 <deflateInit_@plt> */
/* @0x1d2914 mov r1, #4 */
/* @0x1d2918 mov r0, r7 */
/* @0x1d291c bl 0xb69ac <deflate@plt> */
/* @0x1d2920 mov r0, r7 */
/* @0x1d2924 bl 0xb69b8 <deflateEnd@plt> */
/* @0x1d2928 ldr r1, [r11, #-0x148] */
/* @0x1d292c movw r3, #0xaaab */
/* @0x1d2930 movt r3, #0xaaaa */
/* @0x1d2934 mov r0, r8 */
/* @0x1d2938 lsl r2, r1, #2 */
/* @0x1d293c add r2, r2, #2 */
/* @0x1d2940 umull r12, r3, r3, r2 */
/* @0x1d2944 bic r3, r3, #1 */
/* @0x1d2948 add r3, r3, #14 */
/* @0x1d294c bic r3, r3, #7 */
/* @0x1d2950 sub sp, sp, r3 */
/* @0x1d2954 add r7, sp, #8 */
/* @0x1d2958 mov r2, r7 */
/* @0x1d295c bl 0x1d1e60 <_Z13base64_encodePKcjPc> */
/* @0x1d2960 mov r0, r4 */
/* @0x1d2964 bl 0x2140d8 <_Z7MD5InitP7MD5_CTX> */
/* @0x1d2968 ldr r1, [pc, #0x50c] */
/* @0x1d296c mov r2, #5 */
/* @0x1d2970 mov r0, r4 */
/* @0x1d2974 add r1, pc, r1 */
/* @0x1d2978 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj> */
/* @0x1d297c mov r0, r7 */
/* @0x1d2980 bl 0xb6538 <strlen@plt> */
/* @0x1d2984 mov r1, r7 */
/* @0x1d2988 mov r2, r0 */
/* @0x1d298c mov r0, r4 */
/* @0x1d2990 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj> */
/* @0x1d2994 ldr r1, [pc, #0x4e4] */
/* @0x1d2998 mov r2, #5 */
/* @0x1d299c mov r0, r4 */
/* @0x1d29a0 add r1, pc, r1 */
/* @0x1d29a4 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj> */
/* @0x1d29a8 mov r0, r4 */
/* @0x1d29ac bl 0x2141d0 <_Z8MD5FinalP7MD5_CTX> */
/* @0x1d29b0 mov r0, #63 */
/* @0x1d29b4 str r5, [r11, #-0x160] */
/* @0x1d29b8 bl 0xb6544 <malloc@plt> */
/* @0x1d29bc ldr lr, [pc, #0x4c0] */
/* @0x1d29c0 mov r3, #63 */
/* @0x1d29c4 str r3, [r11, #-0x164] */
/* @0x1d29c8 add lr, pc, lr */
/* @0x1d29cc ldr r5, [r11, #-0x160] */
/* @0x1d29d0 add r5, r5, #41 */
/* @0x1d29d4 str r5, [r11, #-0x160] */
/* @0x1d29d8 str r0, [r11, #-0x168] */
/* @0x1d29dc mov r12, r0 */
/* @0x1d29e0 ldm lr!, {r0, r1, r2, r3} */
/* @0x1d29e4 stm r12!, {r0, r1, r2, r3} */
/* @0x1d29e8 ldm lr!, {r0, r1, r2, r3} */
/* @0x1d29ec stm r12!, {r0, r1, r2, r3} */
/* @0x1d29f0 ldm lr, {r0, r1, r2} */
/* @0x1d29f4 stm r12!, {r0, r1} */
/* @0x1d29f8 mov r0, r7 */
/* @0x1d29fc strh r2, [r12] */
/* @0x1d2a00 bl 0x1d22c4 <_Z9urlEncodePKc> */
/* @0x1d2a04 subs r9, r0, #0 */
/* @0x1d2a08 ldreq r5, [r11, #-0x160] */
/* @0x1d2a0c beq 0x1d2a50 <CheckLicense+0x6b0> */
/* @0x1d2a10 bl 0xb6538 <strlen@plt> */
/* @0x1d2a14 ldr r5, [r11, #-0x160] */
/* @0x1d2a18 ldr r2, [r11, #-0x164] */
/* @0x1d2a1c mvn r3, r5 */
/* @0x1d2a20 add r3, r2, r3 */
/* @0x1d2a24 add r7, r0, #1 */
/* @0x1d2a28 cmp r7, r3 */
/* @0x1d2a2c bgt 0x1d2cf8 <CheckLicense+0x958> */
/* @0x1d2a30 ldr r0, [r11, #-0x168] */
/* @0x1d2a34 add r0, r0, r5 */
/* @0x1d2a38 mov r1, r9 */
/* @0x1d2a3c bl 0xb65a4 <strcpy@plt> */
/* @0x1d2a40 ldr r5, [r11, #-0x160] */
/* @0x1d2a44 sub r5, r5, #1 */
/* @0x1d2a48 add r5, r5, r7 */
/* @0x1d2a4c str r5, [r11, #-0x160] */
/* @0x1d2a50 ldr r7, [r11, #-0x164] */
/* @0x1d2a54 mvn r3, r5 */
/* @0x1d2a58 add r3, r7, r3 */
/* @0x1d2a5c cmp r3, #10 */
/* @0x1d2a60 ble 0x1d2bec <CheckLicense+0x84c> */
/* @0x1d2a64 ldr r12, [r11, #-0x168] */
/* @0x1d2a68 ldr r3, [pc, #0x418] */
/* @0x1d2a6c add r2, r12, r5 */
/* @0x1d2a70 ldr r8, [pc, #0x414] */
/* @0x1d2a74 sub r7, r11, #360 */
/* @0x1d2a78 add r3, pc, r3 */
/* @0x1d2a7c add r8, pc, r8 */
/* @0x1d2a80 ldm r3!, {r0, r1} */
/* @0x1d2a84 ldrh lr, [r3] */
/* @0x1d2a88 ldrb r3, [r3, #0x2] */
/* @0x1d2a8c str r0, [r12, r5] */
/* @0x1d2a90 mov r0, #12 */
/* @0x1d2a94 str r1, [r2, #0x4] */
/* @0x1d2a98 strh lr, [r2, #8] */
/* @0x1d2a9c strb r3, [r2, #0xa] */
/* @0x1d2aa0 ldr r3, [r11, #-0x160] */
/* @0x1d2aa4 add r3, r3, #10 */
/* @0x1d2aa8 str r3, [r11, #-0x160] */
/* @0x1d2aac bl 0xc4600 <_Z8YYRandomi> */
/* @0x1d2ab0 cmp r0, #15 */
/* @0x1d2ab4 mov r5, r0 */
/* @0x1d2ab8 mov r10, r0 */
/* @0x1d2abc bgt 0x1d2ae8 <CheckLicense+0x748> */
/* @0x1d2ac0 add r3, r4, r10 */
/* @0x1d2ac4 mov r0, r7 */
/* @0x1d2ac8 add r10, r10, #1 */
/* @0x1d2acc mov r1, r8 */
/* @0x1d2ad0 ldrb r2, [r3, #0x58] */
/* @0x1d2ad4 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d2ad8 rsb r3, r5, r10 */
/* @0x1d2adc cmp r3, #1 */
/* @0x1d2ae0 cmple r10, #15 */
/* @0x1d2ae4 ble 0x1d2ac0 <CheckLicense+0x720> */
/* @0x1d2ae8 mov r4, #0 */
/* @0x1d2aec ldr r0, [r11, #-0x168] */
/* @0x1d2af0 mov r2, r4 */
/* @0x1d2af4 mov r3, r4 */
/* @0x1d2af8 mvn r1, #0 */
/* @0x1d2afc str r4, [sp] */
/* @0x1d2b00 str r4, [r11, #-0x160] */
/* @0x1d2b04 bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_> */
/* @0x1d2b08 mov r0, r9 */
/* @0x1d2b0c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x1d2b10 ldr r0, [r11, #-0x168] */
/* @0x1d2b14 cmp r0, r4 */
/* @0x1d2b18 beq 0x1d2b2c <CheckLicense+0x78c> */
/* @0x1d2b1c bl 0xb655c <free@plt> */
/* @0x1d2b20 str r4, [r11, #-0x168] */
/* @0x1d2b24 str r4, [r11, #-0x164] */
/* @0x1d2b28 str r4, [r11, #-0x160] */
/* @0x1d2b2c ldr r0, [r11, #-0x174] */
/* @0x1d2b30 cmp r0, #0 */
/* @0x1d2b34 beq 0x1d2b4c <CheckLicense+0x7ac> */
/* @0x1d2b38 bl 0xb655c <free@plt> */
/* @0x1d2b3c mov r3, #0 */
/* @0x1d2b40 str r3, [r11, #-0x174] */
/* @0x1d2b44 str r3, [r11, #-0x170] */
/* @0x1d2b48 str r3, [r11, #-0x16c] */
/* @0x1d2b4c ldr r0, [r11, #-0x180] */
/* @0x1d2b50 cmp r0, #0 */
/* @0x1d2b54 beq 0x1d23e4 <CheckLicense+0x44> */
/* @0x1d2b58 bl 0xb655c <free@plt> */
/* @0x1d2b5c b 0x1d23e4 <CheckLicense+0x44> */
/* @0x1d2b60 vcvt.u32.f64 s15, d8 */
/* @0x1d2b64 ldr r1, [pc, #0x324] */
/* @0x1d2b68 add r1, pc, r1 */
/* @0x1d2b6c vmov r2, s15 */
/* @0x1d2b70 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d2b74 b 0x1d267c <CheckLicense+0x2dc> */
/* @0x1d2b78 add r3, r4, #1 */
/* @0x1d2b7c mov r7, #4 */
/* @0x1d2b80 cmp r7, r3 */
/* @0x1d2b84 ldr r8, [r11, #-0x180] */
/* @0x1d2b88 addlt r3, r3, r3, lsl #1 */
/* @0x1d2b8c addlt r3, r3, r3, lsr #31 */
/* @0x1d2b90 asrlt r7, r3, #1 */
/* @0x1d2b94 mov r0, r7 */
/* @0x1d2b98 bl 0xb6544 <malloc@plt> */
/* @0x1d2b9c mov r2, #3 */
/* @0x1d2ba0 mov r1, r8 */
/* @0x1d2ba4 str r0, [r11, #-0x180] */
/* @0x1d2ba8 bl 0xb65bc <memcpy@plt> */
/* @0x1d2bac cmp r8, #0 */
/* @0x1d2bb0 str r7, [r11, #-0x17c] */
/* @0x1d2bb4 moveq r2, r0 */
/* @0x1d2bb8 beq 0x1d24c0 <CheckLicense+0x120> */
/* @0x1d2bbc mov r0, r8 */
/* @0x1d2bc0 bl 0xb655c <free@plt> */
/* @0x1d2bc4 ldr r2, [r11, #-0x180] */
/* @0x1d2bc8 ldr r4, [r11, #-0x178] */
/* @0x1d2bcc b 0x1d24c0 <CheckLicense+0x120> */
/* @0x1d2bd0 ldr r1, [pc, #0x2bc] */
/* @0x1d2bd4 mov r0, r7 */
/* @0x1d2bd8 ldr r2, [pc, #0x2b8] */
/* @0x1d2bdc add r1, pc, r1 */
/* @0x1d2be0 add r2, pc, r2 */
/* @0x1d2be4 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz> */
/* @0x1d2be8 b 0x1d27ac <CheckLicense+0x40c> */
/* @0x1d2bec cmp r7, #0 */
/* @0x1d2bf0 add r3, r5, #11 */
/* @0x1d2bf4 addne r10, r7, r7, lsl #1 */
/* @0x1d2bf8 ldr r8, [r11, #-0x168] */
/* @0x1d2bfc moveq r10, #16 */
/* @0x1d2c00 addne r10, r10, r10, lsr #31 */
/* @0x1d2c04 asrne r10, r10, #1 */
/* @0x1d2c08 cmp r10, r3 */
/* @0x1d2c0c addlt r3, r3, r3, lsl #1 */
/* @0x1d2c10 addlt r3, r3, r3, lsr #31 */
/* @0x1d2c14 asrlt r10, r3, #1 */
/* @0x1d2c18 mov r0, r10 */
/* @0x1d2c1c bl 0xb6544 <malloc@plt> */
/* @0x1d2c20 mov r2, r7 */
/* @0x1d2c24 mov r1, r8 */
/* @0x1d2c28 str r0, [r11, #-0x168] */
/* @0x1d2c2c bl 0xb65bc <memcpy@plt> */
/* @0x1d2c30 cmp r8, #0 */
/* @0x1d2c34 str r10, [r11, #-0x164] */
/* @0x1d2c38 mov r12, r0 */
/* @0x1d2c3c beq 0x1d2a68 <CheckLicense+0x6c8> */
/* @0x1d2c40 mov r0, r8 */
/* @0x1d2c44 bl 0xb655c <free@plt> */
/* @0x1d2c48 ldr r12, [r11, #-0x168] */
/* @0x1d2c4c ldr r5, [r11, #-0x160] */
/* @0x1d2c50 b 0x1d2a68 <CheckLicense+0x6c8> */
/* @0x1d2c54 cmp r4, #0 */
/* @0x1d2c58 add r3, r8, #2 */
/* @0x1d2c5c addne r5, r4, r4, lsl #1 */
/* @0x1d2c60 ldr r7, [r11, #-0x180] */
/* @0x1d2c64 moveq r5, #3 */
/* @0x1d2c68 addne r5, r5, r5, lsr #31 */
/* @0x1d2c6c asrne r5, r5, #1 */
/* @0x1d2c70 cmp r5, r3 */
/* @0x1d2c74 addlt r3, r3, r3, lsl #1 */
/* @0x1d2c78 addlt r3, r3, r3, lsr #31 */
/* @0x1d2c7c asrlt r5, r3, #1 */
/* @0x1d2c80 mov r0, r5 */
/* @0x1d2c84 bl 0xb6544 <malloc@plt> */
/* @0x1d2c88 mov r2, r4 */
/* @0x1d2c8c mov r1, r7 */
/* @0x1d2c90 str r0, [r11, #-0x180] */
/* @0x1d2c94 bl 0xb65bc <memcpy@plt> */
/* @0x1d2c98 cmp r7, #0 */
/* @0x1d2c9c str r5, [r11, #-0x17c] */
/* @0x1d2ca0 mov r12, r0 */
/* @0x1d2ca4 beq 0x1d289c <CheckLicense+0x4fc> */
/* @0x1d2ca8 mov r0, r7 */
/* @0x1d2cac bl 0xb655c <free@plt> */
/* @0x1d2cb0 ldr r12, [r11, #-0x180] */
/* @0x1d2cb4 ldr r8, [r11, #-0x178] */
/* @0x1d2cb8 b 0x1d289c <CheckLicense+0x4fc> */
/* @0x1d2cbc ldr r1, [pc, #0x1d8] */
/* @0x1d2cc0 ldr r1, [r6, r1] */
/* @0x1d2cc4 ldrd r0, r1, [r1] */
/* @0x1d2cc8 mov r4, r0 */
/* @0x1d2ccc mov r5, r1 */
/* @0x1d2cd0 subs r4, r4, r2 */
/* @0x1d2cd4 sbc r5, r5, r3 */
/* @0x1d2cd8 cmp r4, #900 */
/* @0x1d2cdc sbcs r12, r5, #0 */
/* @0x1d2ce0 blt 0x1d243c <CheckLicense+0x9c> */
/* @0x1d2ce4 ldr r3, [pc, #0x12c] */
/* @0x1d2ce8 mov r2, #2 */
/* @0x1d2cec ldr r3, [r6, r3] */
/* @0x1d2cf0 str r2, [r3] */
/* @0x1d2cf4 b 0x1d2434 <CheckLicense+0x94> */
/* @0x1d2cf8 cmp r2, #0 */
/* @0x1d2cfc add r3, r7, r5 */
/* @0x1d2d00 ldr r8, [r11, #-0x168] */
/* @0x1d2d04 movne r10, r2 */
/* @0x1d2d08 moveq r10, r7 */
/* @0x1d2d0c add r10, r10, r10, lsl #1 */
/* @0x1d2d10 str r2, [r11, #-0x194] */
/* @0x1d2d14 add r10, r10, r10, lsr #31 */
/* @0x1d2d18 asr r10, r10, #1 */
/* @0x1d2d1c cmp r10, r3 */
/* @0x1d2d20 addlt r3, r3, r3, lsl #1 */
/* @0x1d2d24 addlt r3, r3, r3, lsr #31 */
/* @0x1d2d28 asrlt r10, r3, #1 */
/* @0x1d2d2c mov r0, r10 */
/* @0x1d2d30 bl 0xb6544 <malloc@plt> */
/* @0x1d2d34 ldr r2, [r11, #-0x194] */
/* @0x1d2d38 mov r1, r8 */
/* @0x1d2d3c str r0, [r11, #-0x168] */
/* @0x1d2d40 bl 0xb65bc <memcpy@plt> */
/* @0x1d2d44 cmp r8, #0 */
/* @0x1d2d48 str r10, [r11, #-0x164] */
/* @0x1d2d4c moveq r0, r0 */
/* @0x1d2d50 beq 0x1d2a34 <CheckLicense+0x694> */
/* @0x1d2d54 mov r0, r8 */
/* @0x1d2d58 bl 0xb655c <free@plt> */
/* @0x1d2d5c ldr r0, [r11, #-0x168] */
/* @0x1d2d60 ldr r5, [r11, #-0x160] */
/* @0x1d2d64 b 0x1d2a34 <CheckLicense+0x694> */
/* @0x1d2d68 bl 0x21c5b8 <_Z22Audio_GetRecorderCountv> */
/* @0x1d2d6c mov r2, r0 */
/* @0x1d2d70 b 0x1d2778 <CheckLicense+0x3d8> */
/* @0x1d2d74 cmp r2, #0 */
/* @0x1d2d78 add r3, r5, r8 */
/* @0x1d2d7c ldr r9, [r11, #-0x180] */
/* @0x1d2d80 movne r10, r2 */
/* @0x1d2d84 moveq r10, r5 */
/* @0x1d2d88 add r10, r10, r10, lsl #1 */
/* @0x1d2d8c str r2, [r11, #-0x194] */
/* @0x1d2d90 add r10, r10, r10, lsr #31 */
/* @0x1d2d94 asr r10, r10, #1 */
/* @0x1d2d98 cmp r10, r3 */
/* @0x1d2d9c addlt r3, r3, r3, lsl #1 */
/* @0x1d2da0 addlt r3, r3, r3, lsr #31 */
/* @0x1d2da4 asrlt r10, r3, #1 */
/* @0x1d2da8 mov r0, r10 */
/* @0x1d2dac bl 0xb6544 <malloc@plt> */
/* @0x1d2db0 ldr r2, [r11, #-0x194] */
/* @0x1d2db4 mov r1, r9 */
/* @0x1d2db8 str r0, [r11, #-0x180] */
/* @0x1d2dbc bl 0xb65bc <memcpy@plt> */
/* @0x1d2dc0 cmp r9, #0 */
/* @0x1d2dc4 str r10, [r11, #-0x17c] */
/* @0x1d2dc8 moveq r0, r0 */
/* @0x1d2dcc beq 0x1d26dc <CheckLicense+0x33c> */
/* @0x1d2dd0 mov r0, r9 */
/* @0x1d2dd4 bl 0xb655c <free@plt> */
/* @0x1d2dd8 ldr r0, [r11, #-0x180] */
/* @0x1d2ddc ldr r8, [r11, #-0x178] */
/* @0x1d2de0 b 0x1d26dc <CheckLicense+0x33c> */
/* @0x1d2de4 ldr r3, [pc, #0x2c] */
/* @0x1d2de8 mov r2, #3 */
/* @0x1d2dec ldr r3, [r6, r3] */
/* @0x1d2df0 str r2, [r3] */
/* @0x1d2df4 b 0x1d2434 <CheckLicense+0x94> */
/* @0x1d2df8 mov r5, r4 */
/* @0x1d2dfc b 0x1d2858 <CheckLicense+0x4b8> */
/* @0x1d2e00 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1d2e04 mlaeq r1, r8, r8, pc */
/* @0x1d2e08 .word 0xffffbd00 */
/* @0x1d2e0c .word 0xffffef04 */
/* @0x1d2e10 .word 0xffffef08 */
/* @0x1d2e14 .word 0xffffef0c */
/* @0x1d2e18 .word 0xffffef10 */
/* @0x1d2e1c mulseq r5, r8, r12 */
/* @0x1d2e20 ldrheq lr, [r7], -r12 */
/* @0x1d2e24 .word 0xffffef14 */
/* @0x1d2e28 andseq lr, r7, r4, lsl #19 */
/* @0x1d2e2c andseq lr, r7, r4, asr r9 */
/* @0x1d2e30 .word 0xffffef18 */
/* @0x1d2e34 andseq lr, r7, r12, asr #18 */
/* @0x1d2e38 .word 0xffffe79c */
/* @0x1d2e3c andseq lr, r7, r0, asr #18 */
/* @0x1d2e40 andseq lr, r7, r0, lsr #18 */
/* @0x1d2e44 andseq lr, r7, r0, lsl r9 */
/* @0x1d2e48 andseq lr, r7, r0, lsl r9 */
/* @0x1d2e4c andseq lr, r7, r8, lsl #18 */
/* @0x1d2e50 mulseq r7, r0, r8 */
/* @0x1d2e54 andseq lr, r7, r4, lsl #17 */
/* @0x1d2e58 .word 0xffffd3fc */
/* @0x1d2e5c andseq lr, r7, r0, ror #16 */
/* @0x1d2e60 andseq lr, r7, r4, asr r8 */
/* @0x1d2e64 .word 0xffffde10 */
/* @0x1d2e68 .word 0xffffde14 */
/* @0x1d2e6c andseq lr, r7, r4, lsl #17 */
/* @0x1d2e70 mulseq r7, r0, r7 */
/* @0x1d2e74 andseq lr, r7, r0, ror r7 */
/* @0x1d2e78 andseq lr, r7, r12, ror #14 */
/* @0x1d2e7c ldrheq lr, [r7], -r4 */
/* @0x1d2e80 mulseq r7, r0, r6 */
/* @0x1d2e84 andseq lr, r7, r0, ror r6 */
/* @0x1d2e88 andseq lr, r7, r12, ror #11 */
/* @0x1d2e8c andseq pc, r5, r8, lsr #14 */
/* @0x1d2e90 andseq lr, r7, r8, lsl #8 */
/* @0x1d2e94 andseq lr, r7, r4, lsl r4 */
/* @0x1d2e98 andseq pc, r5, r0, ror #12 */
/* @0x1d2e9c .word 0xffffef1c */

/* ── FUNC 0x1d2ea0 · ChangeInstanceTypes() · size=72 · insn=18 */
/* @0x1d2ea0 push {r3, r4, r5, lr} */
/* @0x1d2ea4 ldr r5, [pc, #0x38] */
/* @0x1d2ea8 ldr r5, [pc, r5] */
/* @0x1d2eac ldr r3, [r5, #0x8] */
/* @0x1d2eb0 cmp r3, #0 */
/* @0x1d2eb4 movgt r4, #0 */
/* @0x1d2eb8 ble 0x1d2ed8 <_Z19ChangeInstanceTypesv+0x38> */
/* @0x1d2ebc ldr r3, [r5] */
/* @0x1d2ec0 ldr r0, [r3, r4, lsl #2] */
/* @0x1d2ec4 add r4, r4, #1 */
/* @0x1d2ec8 bl 0x192bc4 <_ZN9CInstance17RelinkObjectTypesEv> */
/* @0x1d2ecc ldr r3, [r5, #0x8] */
/* @0x1d2ed0 cmp r3, r4 */
/* @0x1d2ed4 bgt 0x1d2ebc <_Z19ChangeInstanceTypesv+0x1c> */
/* @0x1d2ed8 mov r3, #0 */
/* @0x1d2edc str r3, [r5, #0x8] */
/* @0x1d2ee0 pop {r3, r4, r5, pc} */
/* @0x1d2ee4 mlaeq r1, r8, sp, r10 */

/* ── FUNC 0x1d2ee8 · ChangeInstanceDepths() · size=396 · insn=99 */
/* @0x1d2ee8 push {r4, r5, r6, r7, r8} */
/* @0x1d2eec ldr r5, [pc, #0x178] */
/* @0x1d2ef0 ldr r5, [pc, r5] */
/* @0x1d2ef4 ldr r0, [r5, #0x8] */
/* @0x1d2ef8 cmp r0, #0 */
/* @0x1d2efc ble 0x1d300c <_Z20ChangeInstanceDepthsv+0x124> */
/* @0x1d2f00 ldr r8, [pc, #0x168] */
/* @0x1d2f04 mov r3, #0 */
/* @0x1d2f08 ldr r12, [r5] */
/* @0x1d2f0c mov r7, r3 */
/* @0x1d2f10 ldr r8, [pc, r8] */
/* @0x1d2f14 ldr r6, [r8] */
/* @0x1d2f18 b 0x1d2f28 <_Z20ChangeInstanceDepthsv+0x40> */
/* @0x1d2f1c add r3, r3, #1 */
/* @0x1d2f20 cmp r3, r0 */
/* @0x1d2f24 beq 0x1d2f80 <_Z20ChangeInstanceDepthsv+0x98> */
/* @0x1d2f28 ldr r2, [r12, r3, lsl #2] */
/* @0x1d2f2c ldrb r1, [r2, #0x69] */
/* @0x1d2f30 cmp r1, #0 */
/* @0x1d2f34 bne 0x1d2f1c <_Z20ChangeInstanceDepthsv+0x34> */
/* @0x1d2f38 ldr r1, [r2, #0x17c] */
/* @0x1d2f3c add r3, r3, #1 */
/* @0x1d2f40 ldr r4, [r2, #0x178] */
/* @0x1d2f44 cmp r1, #0 */
/* @0x1d2f48 strne r4, [r1, #0x178] */
/* @0x1d2f4c ldrne r1, [r2, #0x17c] */
/* @0x1d2f50 ldrne r4, [r2, #0x178] */
/* @0x1d2f54 streq r4, [r6, #0x80] */
/* @0x1d2f58 cmp r4, #0 */
/* @0x1d2f5c streq r1, [r6, #0x84] */
/* @0x1d2f60 strne r1, [r4, #0x17c] */
/* @0x1d2f64 cmp r3, r0 */
/* @0x1d2f68 ldr r1, [r6, #0x88] */
/* @0x1d2f6c str r7, [r2, #0x178] */
/* @0x1d2f70 str r7, [r2, #0x17c] */
/* @0x1d2f74 sub r2, r1, #1 */
/* @0x1d2f78 str r2, [r6, #0x88] */
/* @0x1d2f7c bne 0x1d2f28 <_Z20ChangeInstanceDepthsv+0x40> */
/* @0x1d2f80 ldr r0, [r8] */
/* @0x1d2f84 mov r2, #0 */
/* @0x1d2f88 ldr r4, [r5] */
/* @0x1d2f8c ldr r12, [r5, #0x8] */
/* @0x1d2f90 b 0x1d2fa0 <_Z20ChangeInstanceDepthsv+0xb8> */
/* @0x1d2f94 add r2, r2, #1 */
/* @0x1d2f98 cmp r12, r2 */
/* @0x1d2f9c ble 0x1d300c <_Z20ChangeInstanceDepthsv+0x124> */
/* @0x1d2fa0 ldr r1, [r4, r2, lsl #2] */
/* @0x1d2fa4 ldrb r3, [r1, #0x69] */
/* @0x1d2fa8 cmp r3, #0 */
/* @0x1d2fac bne 0x1d2f94 <_Z20ChangeInstanceDepthsv+0xac> */
/* @0x1d2fb0 ldr r3, [r0, #0x84] */
/* @0x1d2fb4 ldr r6, [r0, #0x88] */
/* @0x1d2fb8 cmp r3, #0 */
/* @0x1d2fbc vldrne s14, [r1, #384] */
/* @0x1d2fc0 add r6, r6, #1 */
/* @0x1d2fc4 str r6, [r0, #0x88] */
/* @0x1d2fc8 beq 0x1d3050 <_Z20ChangeInstanceDepthsv+0x168> */
/* @0x1d2fcc vldr s15, [r3, #388] */
/* @0x1d2fd0 vcmpe.f32 s14, s15 */
/* @0x1d2fd4 vmrs APSR_nzcv, fpscr */
/* @0x1d2fd8 bge 0x1d301c <_Z20ChangeInstanceDepthsv+0x134> */
/* @0x1d2fdc ldr r3, [r3, #0x17c] */
/* @0x1d2fe0 cmp r3, #0 */
/* @0x1d2fe4 bne 0x1d2fcc <_Z20ChangeInstanceDepthsv+0xe4> */
/* @0x1d2fe8 ldr r6, [r0, #0x80] */
/* @0x1d2fec add r2, r2, #1 */
/* @0x1d2ff0 cmp r12, r2 */
/* @0x1d2ff4 vstr s14, [r1, #388] */
/* @0x1d2ff8 str r1, [r6, #0x17c] */
/* @0x1d2ffc str r6, [r1, #0x178] */
/* @0x1d3000 str r1, [r0, #0x80] */
/* @0x1d3004 str r3, [r1, #0x17c] */
/* @0x1d3008 bgt 0x1d2fa0 <_Z20ChangeInstanceDepthsv+0xb8> */
/* @0x1d300c mov r3, #0 */
/* @0x1d3010 str r3, [r5, #0x8] */
/* @0x1d3014 pop {r4, r5, r6, r7, r8} */
/* @0x1d3018 bx lr */
/* @0x1d301c ldr r6, [r3, #0x178] */
/* @0x1d3020 cmp r6, #0 */
/* @0x1d3024 streq r3, [r1, #0x17c] */
/* @0x1d3028 strne r6, [r1, #0x178] */
/* @0x1d302c ldrne r6, [r3, #0x178] */
/* @0x1d3030 streq r1, [r3, #0x178] */
/* @0x1d3034 strne r3, [r1, #0x17c] */
/* @0x1d3038 streq r1, [r0, #0x84] */
/* @0x1d303c strne r1, [r6, #0x17c] */
/* @0x1d3040 streq r6, [r1, #0x178] */
/* @0x1d3044 strne r1, [r3, #0x178] */
/* @0x1d3048 vstr s14, [r1, #388] */
/* @0x1d304c b 0x1d2f94 <_Z20ChangeInstanceDepthsv+0xac> */
/* @0x1d3050 ldr r6, [r1, #0x180] */
/* @0x1d3054 str r1, [r0, #0x84] */
/* @0x1d3058 str r1, [r0, #0x80] */
/* @0x1d305c str r6, [r1, #0x184] */
/* @0x1d3060 str r3, [r1, #0x17c] */
/* @0x1d3064 str r3, [r1, #0x178] */
/* @0x1d3068 b 0x1d2f94 <_Z20ChangeInstanceDepthsv+0xac> */
/* @0x1d306c .word 0x0021b1b4 */
/* @0x1d3070 eoreq r10, r1, r8, lsl r10 */

/* ── FUNC 0x1d3074 · ProcessActivateDeactveLists() · size=48 · insn=12 */
/* @0x1d3074 push {r3, lr} */
/* @0x1d3078 ldr r3, [pc, #0x1c] */
/* @0x1d307c ldr r3, [pc, r3] */
/* @0x1d3080 ldr r0, [r3] */
/* @0x1d3084 bl 0x1abd9c <_ZN5CRoom12UpdateActiveEv> */
/* @0x1d3088 ldr r3, [pc, #0x10] */
/* @0x1d308c mov r2, #0 */
/* @0x1d3090 ldr r3, [pc, r3] */
/* @0x1d3094 str r2, [r3, #0x8] */
/* @0x1d3098 pop {r3, pc} */
/* @0x1d309c eoreq r10, r1, r12, lsr #17 */
/* @0x1d30a0 .word 0x0021abb8 */

/* ── FUNC 0x1d30a4 · UpdateActiveLists() · size=192 · insn=48 */
/* @0x1d30a4 push {r3, r4, r5, lr} */
/* @0x1d30a8 ldr r4, [pc, #0x9c] */
/* @0x1d30ac ldr r3, [pc, #0x9c] */
/* @0x1d30b0 add r4, pc, r4 */
/* @0x1d30b4 ldr r5, [r4, r3] */
/* @0x1d30b8 ldrb r3, [r5] */
/* @0x1d30bc cmp r3, #0 */
/* @0x1d30c0 bne 0x1d3134 <_Z17UpdateActiveListsv+0x90> */
/* @0x1d30c4 ldr r3, [pc, #0x88] */
/* @0x1d30c8 ldr r3, [r4, r3] */
/* @0x1d30cc ldr r3, [r3, #0x8] */
/* @0x1d30d0 cmp r3, #0 */
/* @0x1d30d4 bne 0x1d312c <_Z17UpdateActiveListsv+0x88> */
/* @0x1d30d8 ldr r3, [pc, #0x78] */
/* @0x1d30dc ldr r3, [r4, r3] */
/* @0x1d30e0 ldr r3, [r3, #0x8] */
/* @0x1d30e4 cmp r3, #0 */
/* @0x1d30e8 bne 0x1d3124 <_Z17UpdateActiveListsv+0x80> */
/* @0x1d30ec ldr r3, [pc, #0x68] */
/* @0x1d30f0 ldr r3, [r4, r3] */
/* @0x1d30f4 ldr r3, [r3, #0x8] */
/* @0x1d30f8 cmp r3, #0 */
/* @0x1d30fc bne 0x1d311c <_Z17UpdateActiveListsv+0x78> */
/* @0x1d3100 ldrb r3, [r5] */
/* @0x1d3104 cmp r3, #0 */
/* @0x1d3108 popeq {r3, r4, r5, pc} */
/* @0x1d310c ldr r3, [pc, #0x4c] */
/* @0x1d3110 ldr r0, [r4, r3] */
/* @0x1d3114 pop {r3, r4, r5, lr} */
/* @0x1d3118 b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1d311c bl 0x1d2ee8 <_Z20ChangeInstanceDepthsv> */
/* @0x1d3120 b 0x1d3100 <_Z17UpdateActiveListsv+0x5c> */
/* @0x1d3124 bl 0x1d2ea0 <_Z19ChangeInstanceTypesv> */
/* @0x1d3128 b 0x1d30ec <_Z17UpdateActiveListsv+0x48> */
/* @0x1d312c bl 0x1d3074 <_Z27ProcessActivateDeactveListsv> */
/* @0x1d3130 b 0x1d30d8 <_Z17UpdateActiveListsv+0x34> */
/* @0x1d3134 ldr r3, [pc, #0x24] */
/* @0x1d3138 mov r1, #6 */
/* @0x1d313c mov r2, #7 */
/* @0x1d3140 ldr r0, [r4, r3] */
/* @0x1d3144 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1d3148 b 0x1d30c4 <_Z17UpdateActiveListsv+0x20> */
/* @0x1d314c eoreq lr, r1, r0, lsr #23 */
/* @0x1d3150 .word 0xffffbf18 */
/* @0x1d3154 .word 0xffffbff8 */
/* @0x1d3158 .word 0xffffbff0 */
/* @0x1d315c .word 0xffffc454 */
/* @0x1d3160 .word 0xffffbf1c */

/* ── FUNC 0x1d3164 · Run_ResizeEvent(int, int) · size=24 · insn=6 */
/* @0x1d3164 ldr r3, [pc, #0xc] */
/* @0x1d3168 mov r2, #1 */
/* @0x1d316c add r3, pc, r3 */
/* @0x1d3170 strb r2, [r3] */
/* @0x1d3174 bx lr */
/* @0x1d3178 eorseq pc, r6, r12, asr r8 */

/* ── FUNC 0x1d317c · Instance_Animate(CInstance*) · size=324 · insn=81 */
/* @0x1d317c ldr r3, [pc, #0x134] */
/* @0x1d3180 push {r4, lr} */
/* @0x1d3184 vpush {d8} */
/* @0x1d3188 ldr r3, [pc, r3] */
/* @0x1d318c mov r4, r0 */
/* @0x1d3190 ldrb r3, [r3] */
/* @0x1d3194 cmp r3, #0 */
/* @0x1d3198 bne 0x1d31dc <_Z16Instance_AnimateP9CInstance+0x60> */
/* @0x1d319c vldr s16, [r4, #144] */
/* @0x1d31a0 vldr s15, [r4, #148] */
/* @0x1d31a4 vadd.f32 s16, s16, s15 */
/* @0x1d31a8 vstr s16, [r4, #144] */
/* @0x1d31ac mov r0, r4 */
/* @0x1d31b0 bl 0x19357c <_ZN9CInstance14GetImageNumberEv> */
/* @0x1d31b4 vcvt.s32.f32 s16, s16 */
/* @0x1d31b8 vmov r3, s16 */
/* @0x1d31bc cmp r3, r0 */
/* @0x1d31c0 bge 0x1d3234 <_Z16Instance_AnimateP9CInstance+0xb8> */
/* @0x1d31c4 vldr s16, [r4, #144] */
/* @0x1d31c8 vcmpe.f32 s16, #0 */
/* @0x1d31cc vmrs APSR_nzcv, fpscr */
/* @0x1d31d0 bmi 0x1d3284 <_Z16Instance_AnimateP9CInstance+0x108> */
/* @0x1d31d4 vpop {d8} */
/* @0x1d31d8 pop {r4, pc} */
/* @0x1d31dc ldr r0, [r0, #0x8c] */
/* @0x1d31e0 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1d31e4 cmp r0, #0 */
/* @0x1d31e8 beq 0x1d319c <_Z16Instance_AnimateP9CInstance+0x20> */
/* @0x1d31ec ldr r3, [r0, #0x70] */
/* @0x1d31f0 cmp r3, #1 */
/* @0x1d31f4 beq 0x1d326c <_Z16Instance_AnimateP9CInstance+0xf0> */
/* @0x1d31f8 ldr r3, [pc, #0xbc] */
/* @0x1d31fc vldr s17, [r0, #108] */
/* @0x1d3200 ldr r0, [pc, r3] */
/* @0x1d3204 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x1d3208 vmov d7, r0, r1 */
/* @0x1d320c vcmp.f64 d7, #0 */
/* @0x1d3210 vmrs APSR_nzcv, fpscr */
/* @0x1d3214 vcvtne.f32.f64 s14, d7 */
/* @0x1d3218 vldrne s16, [r4, #144] */
/* @0x1d321c vldrne s15, [r4, #148] */
/* @0x1d3220 vldreq s16, [r4, #144] */
/* @0x1d3224 vdivne.f32 s17, s17, s14 */
/* @0x1d3228 vmlane.f32 s16, s17, s15 */
/* @0x1d322c vstrne s16, [r4, #144] */
/* @0x1d3230 b 0x1d31ac <_Z16Instance_AnimateP9CInstance+0x30> */
/* @0x1d3234 mov r0, r4 */
/* @0x1d3238 vldr s16, [r4, #144] */
/* @0x1d323c bl 0x19357c <_ZN9CInstance14GetImageNumberEv> */
/* @0x1d3240 mov r2, #7 */
/* @0x1d3244 mov r1, r4 */
/* @0x1d3248 mov r3, r2 */
/* @0x1d324c vmov s14, r0 */
/* @0x1d3250 mov r0, r4 */
/* @0x1d3254 vcvt.f32.s32 s15, s14 */
/* @0x1d3258 vsub.f32 s16, s16, s15 */
/* @0x1d325c vstr s16, [r4, #144] */
/* @0x1d3260 vpop {d8} */
/* @0x1d3264 pop {r4, lr} */
/* @0x1d3268 b 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d326c vldr s15, [r0, #108] */
/* @0x1d3270 vldr s16, [r4, #144] */
/* @0x1d3274 vldr s14, [r4, #148] */
/* @0x1d3278 vmla.f32 s16, s14, s15 */
/* @0x1d327c vstr s16, [r4, #144] */
/* @0x1d3280 b 0x1d31ac <_Z16Instance_AnimateP9CInstance+0x30> */
/* @0x1d3284 mov r0, r4 */
/* @0x1d3288 bl 0x19357c <_ZN9CInstance14GetImageNumberEv> */
/* @0x1d328c mov r2, #7 */
/* @0x1d3290 mov r1, r4 */
/* @0x1d3294 mov r3, r2 */
/* @0x1d3298 vmov s14, r0 */
/* @0x1d329c mov r0, r4 */
/* @0x1d32a0 vcvt.f32.s32 s15, s14 */
/* @0x1d32a4 vadd.f32 s16, s16, s15 */
/* @0x1d32a8 vstr s16, [r4, #144] */
/* @0x1d32ac vpop {d8} */
/* @0x1d32b0 pop {r4, lr} */
/* @0x1d32b4 b 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d32b8 mlaeq r1, r12, r7, r10 */
/* @0x1d32bc eoreq r10, r1, r12, lsr #14 */
