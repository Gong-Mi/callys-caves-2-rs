/* libyoyo.so 覆盖卡组 0010
 * 函数 0xcd304..0xcec18，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xcd304 · IBuffer::Read(eBuffer_Type, RValue*) · size=860 · insn=215 */
/* @0xcd304 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xcd308 mov r3, #0 */
/* @0xcd30c mov r7, r1 */
/* @0xcd310 str r3, [r2] */
/* @0xcd314 str r3, [r2, #0x4] */
/* @0xcd318 mov r4, r0 */
/* @0xcd31c ldr r1, [r0, #0x24] */
/* @0xcd320 mov r6, r2 */
/* @0xcd324 ldr r5, [r0, #0x1c] */
/* @0xcd328 sub sp, sp, #12 */
/* @0xcd32c ldr r9, [r0, #0x14] */
/* @0xcd330 ldr r8, [r0, #0x10] */
/* @0xcd334 add r5, r1, r5 */
/* @0xcd338 sub r0, r9, #1 */
/* @0xcd33c rsb r2, r9, #0 */
/* @0xcd340 add r5, r5, r0 */
/* @0xcd344 str r3, [r6, #0xc] */
/* @0xcd348 and r5, r5, r2 */
/* @0xcd34c rsb r5, r1, r5 */
/* @0xcd350 str r5, [r4, #0x1c] */
/* @0xcd354 cmp r5, r8 */
/* @0xcd358 blt 0xcd3a4 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0xa0> */
/* @0xcd35c ldr r2, [r4, #0x18] */
/* @0xcd360 cmp r2, #2 */
/* @0xcd364 beq 0xcd384 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x80> */
/* @0xcd368 mvn r0, #0 */
/* @0xcd36c str r3, [r6] */
/* @0xcd370 mov r3, #0 */
/* @0xcd374 movt r3, #0xc008 */
/* @0xcd378 str r3, [r6, #0x4] */
/* @0xcd37c add sp, sp, #12 */
/* @0xcd380 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcd384 add r0, r8, r1 */
/* @0xcd388 rsb r5, r8, r5 */
/* @0xcd38c mov r1, r9 */
/* @0xcd390 bl 0x318dec <__aeabi_idivmod> */
/* @0xcd394 cmp r8, r5 */
/* @0xcd398 ble 0xcd384 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x80> */
/* @0xcd39c str r1, [r4, #0x24] */
/* @0xcd3a0 str r5, [r4, #0x1c] */
/* @0xcd3a4 mov r0, r7 */
/* @0xcd3a8 bl 0xcd100 <_ZN7IBuffer6SizeOfE12eBuffer_Type> */
/* @0xcd3ac cmp r7, #11 */
/* @0xcd3b0 cmpne r7, #13 */
/* @0xcd3b4 movne r12, #0 */
/* @0xcd3b8 moveq r12, #1 */
/* @0xcd3bc beq 0xcd4c0 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x1bc> */
/* @0xcd3c0 ldr r2, [r4, #0x1c] */
/* @0xcd3c4 ldr r9, [r4, #0x10] */
/* @0xcd3c8 add r1, r2, r0 */
/* @0xcd3cc ldr r3, [r4, #0x18] */
/* @0xcd3d0 cmp r1, r9 */
/* @0xcd3d4 bgt 0xcd450 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x14c> */
/* @0xcd3d8 ldr r10, [r4, #0xc] */
/* @0xcd3dc cmp r3, #2 */
/* @0xcd3e0 add r3, r10, r2 */
/* @0xcd3e4 beq 0xcd460 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x15c> */
/* @0xcd3e8 cmp r0, #0 */
/* @0xcd3ec subgt r12, sp, #1 */
/* @0xcd3f0 addgt r1, r3, r0 */
/* @0xcd3f4 ble 0xcd40c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x108> */
/* @0xcd3f8 ldrb r5, [r3], #1 */
/* @0xcd3fc cmp r3, r1 */
/* @0xcd400 strb r5, [r12, #0x1]! */
/* @0xcd404 bne 0xcd3f8 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0xf4> */
/* @0xcd408 add r1, r0, r2 */
/* @0xcd40c str r1, [r4, #0x1c] */
/* @0xcd410 sub r7, r7, #1 */
/* @0xcd414 cmp r7, #11 */
/* @0xcd418 addls pc, pc, r7, lsl #2 */
/* @0xcd41c b 0xcd63c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x338> */
/* @0xcd420 b 0xcd550 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x24c> */
/* @0xcd424 b 0xcd608 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x304> */
/* @0xcd428 b 0xcd5f0 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x2ec> */
/* @0xcd42c b 0xcd5d8 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x2d4> */
/* @0xcd430 b 0xcd5b8 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x2b4> */
/* @0xcd434 b 0xcd5a0 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x29c> */
/* @0xcd438 b 0xcd63c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x338> */
/* @0xcd43c b 0xcd580 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x27c> */
/* @0xcd440 b 0xcd56c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x268> */
/* @0xcd444 b 0xcd550 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x24c> */
/* @0xcd448 b 0xcd63c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x338> */
/* @0xcd44c b 0xcd620 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x31c> */
/* @0xcd450 cmp r3, #2 */
/* @0xcd454 ldreq r10, [r4, #0xc] */
/* @0xcd458 addeq r3, r10, r2 */
/* @0xcd45c bne 0xcd644 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x340> */
/* @0xcd460 cmp r0, #0 */
/* @0xcd464 ble 0xcd410 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x10c> */
/* @0xcd468 sub r5, sp, #1 */
/* @0xcd46c mov r8, #0 */
/* @0xcd470 add r11, r5, r0 */
/* @0xcd474 b 0xcd47c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x178> */
/* @0xcd478 ldr r2, [r4, #0x1c] */
/* @0xcd47c ldrb r1, [r3] */
/* @0xcd480 add r2, r2, #1 */
/* @0xcd484 cmp r2, r9 */
/* @0xcd488 str r2, [r4, #0x1c] */
/* @0xcd48c add r3, r3, #1 */
/* @0xcd490 strb r1, [r5, #0x1]! */
/* @0xcd494 blt 0xcd4b4 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x1b0> */
/* @0xcd498 ldr r0, [r4, #0x24] */
/* @0xcd49c ldr r1, [r4, #0x14] */
/* @0xcd4a0 add r0, r9, r0 */
/* @0xcd4a4 bl 0x318dec <__aeabi_idivmod> */
/* @0xcd4a8 mov r3, r10 */
/* @0xcd4ac str r8, [r4, #0x1c] */
/* @0xcd4b0 str r1, [r4, #0x24] */
/* @0xcd4b4 cmp r5, r11 */
/* @0xcd4b8 bne 0xcd478 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x174> */
/* @0xcd4bc b 0xcd410 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x10c> */
/* @0xcd4c0 ldr r3, [r4, #0x1c] */
/* @0xcd4c4 mov r7, #1 */
/* @0xcd4c8 ldr r0, [r4, #0xc] */
/* @0xcd4cc mov r8, #0 */
/* @0xcd4d0 ldr r1, [r4, #0x20] */
/* @0xcd4d4 add r0, r0, r3 */
/* @0xcd4d8 str r7, [r6, #0xc] */
/* @0xcd4dc rsb r1, r3, r1 */
/* @0xcd4e0 bl 0xdc3ec <_Z9YYstrnlenPKci> */
/* @0xcd4e4 ldr r1, [pc, #0x170] */
/* @0xcd4e8 mov r3, r7 */
/* @0xcd4ec movw r2, #0x2fb */
/* @0xcd4f0 add r1, pc, r1 */
/* @0xcd4f4 add r5, r0, r7 */
/* @0xcd4f8 mov r9, r0 */
/* @0xcd4fc mov r0, r5 */
/* @0xcd500 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcd504 ldr r3, [r4, #0x1c] */
/* @0xcd508 ldr r1, [r4, #0xc] */
/* @0xcd50c mov r2, r9 */
/* @0xcd510 add r1, r1, r3 */
/* @0xcd514 mov r7, r0 */
/* @0xcd518 bl 0xb65bc <memcpy@plt> */
/* @0xcd51c add r3, r7, r5 */
/* @0xcd520 mov r0, r6 */
/* @0xcd524 mov r1, r7 */
/* @0xcd528 strb r8, [r3, #-0x1] */
/* @0xcd52c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xcd530 mov r0, r7 */
/* @0xcd534 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcd538 ldr r3, [r4, #0x1c] */
/* @0xcd53c mov r0, r8 */
/* @0xcd540 add r5, r3, r5 */
/* @0xcd544 str r5, [r4, #0x1c] */
/* @0xcd548 add sp, sp, #12 */
/* @0xcd54c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcd550 ldrb r3, [sp] */
/* @0xcd554 mov r2, #7 */
/* @0xcd558 mov r0, #0 */
/* @0xcd55c str r2, [r6, #0xc] */
/* @0xcd560 str r3, [r6] */
/* @0xcd564 add sp, sp, #12 */
/* @0xcd568 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcd56c ldr r2, [sp] */
/* @0xcd570 mov r0, #0 */
/* @0xcd574 ldr r3, [sp, #0x4] */
/* @0xcd578 stm r6, {r2, r3} */
/* @0xcd57c b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78> */
/* @0xcd580 vldr s15, [sp] */
/* @0xcd584 vcvt.f64.f32 d6, s15 */
/* @0xcd588 mov r0, #0 */
/* @0xcd58c vmov r4, r5, d6 */
/* @0xcd590 vmov r2, s12 */
/* @0xcd594 mov r3, r5 */
/* @0xcd598 stm r6, {r2, r3} */
/* @0xcd59c b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78> */
/* @0xcd5a0 ldr r3, [sp] */
/* @0xcd5a4 mov r2, #7 */
/* @0xcd5a8 mov r0, #0 */
/* @0xcd5ac str r2, [r6, #0xc] */
/* @0xcd5b0 str r3, [r6] */
/* @0xcd5b4 b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78> */
/* @0xcd5b8 ldr r2, [sp] */
/* @0xcd5bc mov r3, #0 */
/* @0xcd5c0 mov r0, r3 */
/* @0xcd5c4 str r3, [r6, #0x4] */
/* @0xcd5c8 mov r3, #10 */
/* @0xcd5cc str r3, [r6, #0xc] */
/* @0xcd5d0 str r2, [r6] */
/* @0xcd5d4 b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78> */
/* @0xcd5d8 ldrsh r3, [sp] */
/* @0xcd5dc mov r2, #7 */
/* @0xcd5e0 mov r0, #0 */
/* @0xcd5e4 str r2, [r6, #0xc] */
/* @0xcd5e8 str r3, [r6] */
/* @0xcd5ec b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78> */
/* @0xcd5f0 ldrh r3, [sp] */
/* @0xcd5f4 mov r2, #7 */
/* @0xcd5f8 mov r0, #0 */
/* @0xcd5fc str r2, [r6, #0xc] */
/* @0xcd600 str r3, [r6] */
/* @0xcd604 b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78> */
/* @0xcd608 ldrsb r3, [sp] */
/* @0xcd60c mov r2, #7 */
/* @0xcd610 mov r0, #0 */
/* @0xcd614 str r2, [r6, #0xc] */
/* @0xcd618 str r3, [r6] */
/* @0xcd61c b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78> */
/* @0xcd620 ldr r2, [sp] */
/* @0xcd624 mov r1, #10 */
/* @0xcd628 ldr r3, [sp, #0x4] */
/* @0xcd62c mov r0, #0 */
/* @0xcd630 str r1, [r6, #0xc] */
/* @0xcd634 stm r6, {r2, r3} */
/* @0xcd638 b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78> */
/* @0xcd63c mvn r0, #0 */
/* @0xcd640 b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78> */
/* @0xcd644 mov r3, #0 */
/* @0xcd648 str r12, [r6] */
/* @0xcd64c movt r3, #0xc008 */
/* @0xcd650 mvn r0, #0 */
/* @0xcd654 str r3, [r6, #0x4] */
/* @0xcd658 b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78> */
/* @0xcd65c eoreq r4, r6, r0, lsl #25 */

/* ── FUNC 0xcd660 · IBuffer::SaveToFileInMemory(char**, int*, int, int, int) · size=332 · insn=83 */
/* @0xcd660 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xcd664 subs r10, r1, #0 */
/* @0xcd668 mov r11, r0 */
/* @0xcd66c mov r9, r2 */
/* @0xcd670 mov r4, r3 */
/* @0xcd674 ldr r8, [sp, #0x28] */
/* @0xcd678 beq 0xcd794 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x134> */
/* @0xcd67c cmp r2, #0 */
/* @0xcd680 beq 0xcd79c <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x13c> */
/* @0xcd684 ldr r3, [sp, #0x2c] */
/* @0xcd688 cmp r3, #0 */
/* @0xcd68c ldr r3, [r0, #0x10] */
/* @0xcd690 bne 0xcd6f0 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x90> */
/* @0xcd694 bic r4, r4, r4, asr #31 */
/* @0xcd698 cmp r3, r4 */
/* @0xcd69c suble r4, r3, #1 */
/* @0xcd6a0 cmp r8, #0 */
/* @0xcd6a4 movlt r8, r3 */
/* @0xcd6a8 add r2, r4, r8 */
/* @0xcd6ac cmp r3, r2 */
/* @0xcd6b0 rsblt r8, r4, r3 */
/* @0xcd6b4 ldr r1, [pc, #0xe8] */
/* @0xcd6b8 mov r2, #1808 */
/* @0xcd6bc mov r0, r8 */
/* @0xcd6c0 mov r3, #1 */
/* @0xcd6c4 add r1, pc, r1 */
/* @0xcd6c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcd6cc ldr r1, [r11, #0xc] */
/* @0xcd6d0 mov r2, r8 */
/* @0xcd6d4 add r1, r1, r4 */
/* @0xcd6d8 mov r7, r0 */
/* @0xcd6dc bl 0xb65bc <memcpy@plt> */
/* @0xcd6e0 str r7, [r10] */
/* @0xcd6e4 mov r0, #1 */
/* @0xcd6e8 str r8, [r9] */
/* @0xcd6ec pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcd6f0 cmp r4, #0 */
/* @0xcd6f4 bge 0xcd70c <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0xac> */
/* @0xcd6f8 adds r4, r4, r3 */
/* @0xcd6fc bmi 0xcd6f8 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x98> */
/* @0xcd700 cmp r3, r4 */
/* @0xcd704 bgt 0xcd714 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0xb4> */
/* @0xcd708 rsb r4, r3, r4 */
/* @0xcd70c cmp r3, r4 */
/* @0xcd710 ble 0xcd708 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0xa8> */
/* @0xcd714 cmp r8, #0 */
/* @0xcd718 blt 0xcd78c <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x12c> */
/* @0xcd71c cmp r3, r8 */
/* @0xcd720 bgt 0xcd6b4 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x54> */
/* @0xcd724 ldr r1, [pc, #0x7c] */
/* @0xcd728 mov r0, r8 */
/* @0xcd72c mov r2, #1808 */
/* @0xcd730 mov r3, #1 */
/* @0xcd734 add r1, pc, r1 */
/* @0xcd738 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcd73c cmp r8, #0 */
/* @0xcd740 mov r7, r0 */
/* @0xcd744 ble 0xcd6e0 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x80> */
/* @0xcd748 mov r5, r8 */
/* @0xcd74c mov r6, #0 */
/* @0xcd750 ldr r3, [r11, #0x10] */
/* @0xcd754 add r0, r7, r6 */
/* @0xcd758 ldr r1, [r11, #0xc] */
/* @0xcd75c rsb r3, r4, r3 */
/* @0xcd760 cmp r3, r5 */
/* @0xcd764 movge r3, r5 */
/* @0xcd768 add r1, r1, r4 */
/* @0xcd76c rsb r5, r3, r5 */
/* @0xcd770 mov r4, #0 */
/* @0xcd774 mov r2, r3 */
/* @0xcd778 add r6, r6, r3 */
/* @0xcd77c bl 0xb65bc <memcpy@plt> */
/* @0xcd780 cmp r5, r4 */
/* @0xcd784 bgt 0xcd750 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0xf0> */
/* @0xcd788 b 0xcd6e0 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0x80> */
/* @0xcd78c mov r8, r3 */
/* @0xcd790 b 0xcd724 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii+0xc4> */
/* @0xcd794 mov r0, r10 */
/* @0xcd798 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcd79c mov r0, r2 */
/* @0xcd7a0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcd7a4 eoreq r4, r6, r12, lsr #21 */
/* @0xcd7a8 eoreq r4, r6, r12, lsr r10 */

/* ── FUNC 0xcd7ac · IBuffer::Save(char const*, int, int) · size=88 · insn=22 */
/* @0xcd7ac push {r4, lr} */
/* @0xcd7b0 sub sp, sp, #16 */
/* @0xcd7b4 add r12, sp, #16 */
/* @0xcd7b8 mov lr, #0 */
/* @0xcd7bc str r3, [sp] */
/* @0xcd7c0 mov r4, r1 */
/* @0xcd7c4 str lr, [r12, #-0x8]! */
/* @0xcd7c8 mov r3, r2 */
/* @0xcd7cc mov r1, r12 */
/* @0xcd7d0 str lr, [sp, #0x4] */
/* @0xcd7d4 add r2, sp, #12 */
/* @0xcd7d8 bl 0xcd660 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii> */
/* @0xcd7dc ldr r1, [sp, #0x8] */
/* @0xcd7e0 ldr r2, [sp, #0xc] */
/* @0xcd7e4 mov r0, r4 */
/* @0xcd7e8 bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i> */
/* @0xcd7ec mov r4, r0 */
/* @0xcd7f0 ldr r0, [sp, #0x8] */
/* @0xcd7f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcd7f8 mov r0, r4 */
/* @0xcd7fc add sp, sp, #16 */
/* @0xcd800 pop {r4, pc} */

/* ── FUNC 0xcd804 · IBuffer::Base64encode(RValue*, int, int) · size=156 · insn=39 */
/* @0xcd804 push {r4, r5, lr} */
/* @0xcd808 subs r5, r1, #0 */
/* @0xcd80c sub sp, sp, #20 */
/* @0xcd810 beq 0xcd894 <_ZN7IBuffer12Base64encodeEP6RValueii+0x90> */
/* @0xcd814 add r1, sp, #16 */
/* @0xcd818 mov r12, #0 */
/* @0xcd81c str r3, [sp] */
/* @0xcd820 mov r3, r2 */
/* @0xcd824 str r12, [r1, #-0x8]! */
/* @0xcd828 add r2, sp, #12 */
/* @0xcd82c str r12, [sp, #0x4] */
/* @0xcd830 bl 0xcd660 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii> */
/* @0xcd834 ldr r12, [sp, #0xc] */
/* @0xcd838 movw lr, #0x5556 */
/* @0xcd83c movt lr, #0x5555 */
/* @0xcd840 ldr r1, [pc, #0x54] */
/* @0xcd844 mov r3, #1 */
/* @0xcd848 lsl r12, r12, #2 */
/* @0xcd84c movw r2, #0x49d */
/* @0xcd850 add r1, pc, r1 */
/* @0xcd854 smull r0, lr, lr, r12 */
/* @0xcd858 sub r0, lr, r12, asr #31 */
/* @0xcd85c add r0, r0, #4 */
/* @0xcd860 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcd864 ldr r1, [sp, #0xc] */
/* @0xcd868 mov r2, r0 */
/* @0xcd86c mov r4, r0 */
/* @0xcd870 ldr r0, [sp, #0x8] */
/* @0xcd874 bl 0x1d1e60 <_Z13base64_encodePKcjPc> */
/* @0xcd878 mov r0, r5 */
/* @0xcd87c mov r1, r4 */
/* @0xcd880 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xcd884 mov r0, r4 */
/* @0xcd888 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcd88c ldr r0, [sp, #0x8] */
/* @0xcd890 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcd894 add sp, sp, #20 */
/* @0xcd898 pop {r4, r5, pc} */
/* @0xcd89c eoreq r4, r6, r0, lsr #18 */

/* ── FUNC 0xcd8a0 · IBuffer::LoadFromFileInMemory(char*, int, int, int, int) · size=124 · insn=31 */
/* @0xcd8a0 cmp r1, #0 */
/* @0xcd8a4 push {r4, lr} */
/* @0xcd8a8 sub sp, sp, #24 */
/* @0xcd8ac beq 0xcd910 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii+0x70> */
/* @0xcd8b0 ldr r12, [r0, #0x18] */
/* @0xcd8b4 cmp r12, #1 */
/* @0xcd8b8 beq 0xcd908 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii+0x68> */
/* @0xcd8bc ldr lr, [r0, #0x10] */
/* @0xcd8c0 rsbs lr, lr, #1 */
/* @0xcd8c4 movlo lr, #0 */
/* @0xcd8c8 cmp r12, #2 */
/* @0xcd8cc beq 0xcd900 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii+0x60> */
/* @0xcd8d0 mov r12, #0 */
/* @0xcd8d4 ldr r4, [sp, #0x20] */
/* @0xcd8d8 str r12, [sp, #0xc] */
/* @0xcd8dc mov r12, #0 */
/* @0xcd8e0 str r12, [sp, #0x10] */
/* @0xcd8e4 str r4, [sp] */
/* @0xcd8e8 ldr r4, [sp, #0x24] */
/* @0xcd8ec stmib sp, {r4, lr} */
/* @0xcd8f0 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb> */
/* @0xcd8f4 mov r0, #1 */
/* @0xcd8f8 add sp, sp, #24 */
/* @0xcd8fc pop {r4, pc} */
/* @0xcd900 mov r12, #1 */
/* @0xcd904 b 0xcd8d4 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii+0x34> */
/* @0xcd908 mov lr, r12 */
/* @0xcd90c b 0xcd8d0 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii+0x30> */
/* @0xcd910 mov r0, r1 */
/* @0xcd914 add sp, sp, #24 */
/* @0xcd918 pop {r4, pc} */

/* ── FUNC 0xcd91c · IBuffer::Load(char const*, int, int, int) · size=252 · insn=63 */
/* @0xcd91c push {r4, r5, r6, r7, r8, lr} */
/* @0xcd920 mov r7, r0 */
/* @0xcd924 ldr r0, [pc, #0xe4] */
/* @0xcd928 sub sp, sp, #16 */
/* @0xcd92c mov r5, r2 */
/* @0xcd930 mov r2, #7 */
/* @0xcd934 add r0, pc, r0 */
/* @0xcd938 mov r6, r3 */
/* @0xcd93c mov r4, r1 */
/* @0xcd940 bl 0xb65e0 <strncmp@plt> */
/* @0xcd944 cmp r0, #0 */
/* @0xcd948 beq 0xcd9ec <_ZN7IBuffer4LoadEPKciii+0xd0> */
/* @0xcd94c ldr r0, [pc, #0xc0] */
/* @0xcd950 mov r1, r4 */
/* @0xcd954 mov r2, #8 */
/* @0xcd958 add r0, pc, r0 */
/* @0xcd95c bl 0xb65e0 <strncmp@plt> */
/* @0xcd960 cmp r0, #0 */
/* @0xcd964 moveq r4, r0 */
/* @0xcd968 bne 0xcd978 <_ZN7IBuffer4LoadEPKciii+0x5c> */
/* @0xcd96c mov r0, r4 */
/* @0xcd970 add sp, sp, #16 */
/* @0xcd974 pop {r4, r5, r6, r7, r8, pc} */
/* @0xcd978 mov r0, r4 */
/* @0xcd97c mov r3, #0 */
/* @0xcd980 str r3, [sp, #0xc] */
/* @0xcd984 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xcd988 cmp r0, #0 */
/* @0xcd98c mov r0, r4 */
/* @0xcd990 beq 0xcd9e0 <_ZN7IBuffer4LoadEPKciii+0xc4> */
/* @0xcd994 add r1, sp, #12 */
/* @0xcd998 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0xcd99c mov r8, r0 */
/* @0xcd9a0 cmp r8, #0 */
/* @0xcd9a4 beq 0xcd9ec <_ZN7IBuffer4LoadEPKciii+0xd0> */
/* @0xcd9a8 ldr r1, [sp, #0x28] */
/* @0xcd9ac mov r3, r5 */
/* @0xcd9b0 ldr r2, [sp, #0xc] */
/* @0xcd9b4 mov r0, r7 */
/* @0xcd9b8 str r6, [sp] */
/* @0xcd9bc str r1, [sp, #0x4] */
/* @0xcd9c0 mov r1, r8 */
/* @0xcd9c4 bl 0xcd8a0 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii> */
/* @0xcd9c8 mov r4, r0 */
/* @0xcd9cc mov r0, r8 */
/* @0xcd9d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcd9d4 mov r0, r4 */
/* @0xcd9d8 add sp, sp, #16 */
/* @0xcd9dc pop {r4, r5, r6, r7, r8, pc} */
/* @0xcd9e0 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0xcd9e4 cmp r0, #0 */
/* @0xcd9e8 bne 0xcd9fc <_ZN7IBuffer4LoadEPKciii+0xe0> */
/* @0xcd9ec mov r4, #0 */
/* @0xcd9f0 mov r0, r4 */
/* @0xcd9f4 add sp, sp, #16 */
/* @0xcd9f8 pop {r4, r5, r6, r7, r8, pc} */
/* @0xcd9fc mov r0, r4 */
/* @0xcda00 add r1, sp, #12 */
/* @0xcda04 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0xcda08 mov r8, r0 */
/* @0xcda0c b 0xcd9a0 <_ZN7IBuffer4LoadEPKciii+0x84> */
/* @0xcda10 eoreq r3, r6, r12, lsr #3 */
/* @0xcda14 mlaeq r6, r0, r1, r3 */

/* ── FUNC 0xcda18 · IBuffer::Base64decode(char const*, int, int) · size=164 · insn=41 */
/* @0xcda18 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xcda1c subs r6, r1, #0 */
/* @0xcda20 mov r8, r0 */
/* @0xcda24 sub sp, sp, #12 */
/* @0xcda28 mov r7, r2 */
/* @0xcda2c mov r9, r3 */
/* @0xcda30 mov r0, r6 */
/* @0xcda34 beq 0xcdab0 <_ZN7IBuffer12Base64decodeEPKcii+0x98> */
/* @0xcda38 bl 0xb6538 <strlen@plt> */
/* @0xcda3c ldr r1, [pc, #0x74] */
/* @0xcda40 movw r2, #0x4bd */
/* @0xcda44 mov r3, #1 */
/* @0xcda48 add r1, pc, r1 */
/* @0xcda4c add r5, r0, r0, lsl #1 */
/* @0xcda50 cmp r5, #0 */
/* @0xcda54 add r0, r5, #3 */
/* @0xcda58 movlt r5, r0 */
/* @0xcda5c asr r5, r5, #2 */
/* @0xcda60 add r5, r5, #4 */
/* @0xcda64 mov r0, r5 */
/* @0xcda68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xcda6c mov r1, r5 */
/* @0xcda70 mov r3, #0 */
/* @0xcda74 mov r4, r0 */
/* @0xcda78 mov r0, r6 */
/* @0xcda7c mov r2, r4 */
/* @0xcda80 bl 0x1d1ff0 <_Z13base64_decodePKcjPcb> */
/* @0xcda84 mov r2, r5 */
/* @0xcda88 mov r1, r4 */
/* @0xcda8c mov r3, #0 */
/* @0xcda90 str r9, [sp] */
/* @0xcda94 mov r0, r8 */
/* @0xcda98 str r7, [sp, #0x4] */
/* @0xcda9c bl 0xcd8a0 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii> */
/* @0xcdaa0 mov r6, r0 */
/* @0xcdaa4 mov r0, r4 */
/* @0xcdaa8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xcdaac mov r0, r6 */
/* @0xcdab0 add sp, sp, #12 */
/* @0xcdab4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xcdab8 eoreq r4, r6, r8, lsr #14 */

/* ── FUNC 0xcdabc · IBuffer::Write(void const*, unsigned int, unsigned int) · size=480 · insn=120 */
/* @0xcdabc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xcdac0 subs r10, r1, #0 */
/* @0xcdac4 mov r6, r0 */
/* @0xcdac8 beq 0xcdc04 <_ZN7IBuffer5WriteEPKvjj+0x148> */
/* @0xcdacc mul r9, r3, r2 */
/* @0xcdad0 cmp r9, #0 */
/* @0xcdad4 mov r2, r9 */
/* @0xcdad8 ble 0xcdb14 <_ZN7IBuffer5WriteEPKvjj+0x58> */
/* @0xcdadc ldr r3, [r0, #0x18] */
/* @0xcdae0 ldr r4, [r0, #0x1c] */
/* @0xcdae4 cmp r3, #1 */
/* @0xcdae8 beq 0xcdb1c <_ZN7IBuffer5WriteEPKvjj+0x60> */
/* @0xcdaec ldr r5, [r0, #0x10] */
/* @0xcdaf0 cmp r5, #0 */
/* @0xcdaf4 ble 0xcdb14 <_ZN7IBuffer5WriteEPKvjj+0x58> */
/* @0xcdaf8 cmp r3, #2 */
/* @0xcdafc beq 0xcdbc8 <_ZN7IBuffer5WriteEPKvjj+0x10c> */
/* @0xcdb00 cmp r4, #0 */
/* @0xcdb04 blt 0xcdb74 <_ZN7IBuffer5WriteEPKvjj+0xb8> */
/* @0xcdb08 cmp r4, r5 */
/* @0xcdb0c movlt r3, r4 */
/* @0xcdb10 blt 0xcdb7c <_ZN7IBuffer5WriteEPKvjj+0xc0> */
/* @0xcdb14 mov r0, #0 */
/* @0xcdb18 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcdb1c bic r4, r4, r4, asr #31 */
/* @0xcdb20 ldr r3, [r0, #0x10] */
/* @0xcdb24 add r5, r9, r4 */
/* @0xcdb28 cmp r5, r3 */
/* @0xcdb2c bgt 0xcdbb4 <_ZN7IBuffer5WriteEPKvjj+0xf8> */
/* @0xcdb30 mov r3, r4 */
/* @0xcdb34 ldr r0, [r6, #0xc] */
/* @0xcdb38 mov r1, r10 */
/* @0xcdb3c mov r2, r9 */
/* @0xcdb40 mov r4, r5 */
/* @0xcdb44 add r0, r0, r3 */
/* @0xcdb48 bl 0xb65bc <memcpy@plt> */
/* @0xcdb4c ldr r3, [r6, #0x10] */
/* @0xcdb50 mov r0, r9 */
/* @0xcdb54 ldr r2, [r6, #0x20] */
/* @0xcdb58 str r4, [r6, #0x1c] */
/* @0xcdb5c cmp r5, r2 */
/* @0xcdb60 movlt r5, r2 */
/* @0xcdb64 cmp r5, r3 */
/* @0xcdb68 strle r5, [r6, #0x20] */
/* @0xcdb6c strgt r3, [r6, #0x20] */
/* @0xcdb70 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcdb74 mov r3, #0 */
/* @0xcdb78 mov r4, r3 */
/* @0xcdb7c add r2, r4, r9 */
/* @0xcdb80 cmp r5, r2 */
/* @0xcdb84 bge 0xcdc0c <_ZN7IBuffer5WriteEPKvjj+0x150> */
/* @0xcdb88 rsb r2, r4, r5 */
/* @0xcdb8c mov r4, r5 */
/* @0xcdb90 ldr r0, [r6, #0xc] */
/* @0xcdb94 mov r1, r10 */
/* @0xcdb98 mov r9, r2 */
/* @0xcdb9c add r0, r0, r3 */
/* @0xcdba0 bl 0xb65bc <memcpy@plt> */
/* @0xcdba4 cmn r4, #1 */
/* @0xcdba8 movne r5, r4 */
/* @0xcdbac ldreq r5, [r6, #0x1c] */
/* @0xcdbb0 b 0xcdb4c <_ZN7IBuffer5WriteEPKvjj+0x90> */
/* @0xcdbb4 ldr r3, [r0] */
/* @0xcdbb8 mov r1, r5 */
/* @0xcdbbc ldr r3, [r3, #0x34] */
/* @0xcdbc0 blx r3 */
/* @0xcdbc4 b 0xcdb30 <_ZN7IBuffer5WriteEPKvjj+0x74> */
/* @0xcdbc8 cmp r4, #0 */
/* @0xcdbcc bge 0xcdbe4 <_ZN7IBuffer5WriteEPKvjj+0x128> */
/* @0xcdbd0 adds r4, r4, r5 */
/* @0xcdbd4 bmi 0xcdbd0 <_ZN7IBuffer5WriteEPKvjj+0x114> */
/* @0xcdbd8 cmp r5, r4 */
/* @0xcdbdc bgt 0xcdbec <_ZN7IBuffer5WriteEPKvjj+0x130> */
/* @0xcdbe0 rsb r4, r5, r4 */
/* @0xcdbe4 cmp r5, r4 */
/* @0xcdbe8 ble 0xcdbe0 <_ZN7IBuffer5WriteEPKvjj+0x124> */
/* @0xcdbec add r1, r4, r9 */
/* @0xcdbf0 cmp r5, r1 */
/* @0xcdbf4 blt 0xcdc14 <_ZN7IBuffer5WriteEPKvjj+0x158> */
/* @0xcdbf8 mov r3, r4 */
/* @0xcdbfc mov r4, r1 */
/* @0xcdc00 b 0xcdb90 <_ZN7IBuffer5WriteEPKvjj+0xd4> */
/* @0xcdc04 mov r0, r10 */
/* @0xcdc08 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xcdc0c mov r5, r2 */
/* @0xcdc10 b 0xcdb34 <_ZN7IBuffer5WriteEPKvjj+0x78> */
/* @0xcdc14 mov r8, r9 */
/* @0xcdc18 mov r7, #0 */
/* @0xcdc1c rsb r3, r7, r9 */
/* @0xcdc20 rsb r5, r4, r5 */
/* @0xcdc24 cmp r5, r3 */
/* @0xcdc28 movge r5, r3 */
/* @0xcdc2c ldr r0, [r6, #0xc] */
/* @0xcdc30 cmp r5, r8 */
/* @0xcdc34 movge r5, r8 */
/* @0xcdc38 add r1, r10, r7 */
/* @0xcdc3c add r0, r0, r4 */
/* @0xcdc40 rsb r8, r5, r8 */
/* @0xcdc44 mov r2, r5 */
/* @0xcdc48 add r7, r7, r5 */
/* @0xcdc4c bl 0xb65bc <memcpy@plt> */
/* @0xcdc50 add r0, r4, r5 */
/* @0xcdc54 cmn r0, #1 */
/* @0xcdc58 ldr r5, [r6, #0x10] */
/* @0xcdc5c mov r3, r0 */
/* @0xcdc60 ldr r2, [r6, #0x20] */
/* @0xcdc64 ldreq r3, [r6, #0x1c] */
/* @0xcdc68 mov r1, r5 */
/* @0xcdc6c cmp r3, r2 */
/* @0xcdc70 movlt r3, r2 */
/* @0xcdc74 cmp r3, r5 */
/* @0xcdc78 strle r3, [r6, #0x20] */
/* @0xcdc7c strgt r5, [r6, #0x20] */
/* @0xcdc80 bl 0x318dec <__aeabi_idivmod> */
/* @0xcdc84 cmp r8, #0 */
/* @0xcdc88 mov r4, r1 */
/* @0xcdc8c bgt 0xcdc1c <_ZN7IBuffer5WriteEPKvjj+0x160> */
/* @0xcdc90 mov r0, r9 */
/* @0xcdc94 str r4, [r6, #0x1c] */
/* @0xcdc98 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0xcdc9c · IBuffer::Read(void const*, unsigned int, unsigned int) · size=284 · insn=71 */
/* @0xcdc9c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xcdca0 subs r9, r1, #0 */
/* @0xcdca4 mov r8, r0 */
/* @0xcdca8 beq 0xcddb0 <_ZN7IBuffer4ReadEPKvjj+0x114> */
/* @0xcdcac mul r5, r3, r2 */
/* @0xcdcb0 cmp r5, #0 */
/* @0xcdcb4 mov r10, r5 */
/* @0xcdcb8 ble 0xcdd08 <_ZN7IBuffer4ReadEPKvjj+0x6c> */
/* @0xcdcbc ldr r2, [r0, #0x18] */
/* @0xcdcc0 ldr r3, [r0, #0x1c] */
/* @0xcdcc4 cmp r2, #2 */
/* @0xcdcc8 beq 0xcdd10 <_ZN7IBuffer4ReadEPKvjj+0x74> */
/* @0xcdccc ldr r2, [r0, #0x10] */
/* @0xcdcd0 bic r3, r3, r3, asr #31 */
/* @0xcdcd4 cmp r2, r3 */
/* @0xcdcd8 ble 0xcdd08 <_ZN7IBuffer4ReadEPKvjj+0x6c> */
/* @0xcdcdc add r7, r5, r3 */
/* @0xcdce0 cmp r2, r7 */
/* @0xcdce4 blt 0xcdda4 <_ZN7IBuffer4ReadEPKvjj+0x108> */
/* @0xcdce8 ldr r1, [r8, #0xc] */
/* @0xcdcec mov r0, r9 */
/* @0xcdcf0 mov r2, r5 */
/* @0xcdcf4 add r1, r1, r3 */
/* @0xcdcf8 bl 0xb65bc <memcpy@plt> */
/* @0xcdcfc mov r0, r5 */
/* @0xcdd00 str r7, [r8, #0x1c] */
/* @0xcdd04 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcdd08 mov r0, #0 */
/* @0xcdd0c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcdd10 cmp r3, #0 */
/* @0xcdd14 ldr r4, [r0, #0x10] */
/* @0xcdd18 bge 0xcdd34 <_ZN7IBuffer4ReadEPKvjj+0x98> */
/* @0xcdd1c adds r3, r3, r4 */
/* @0xcdd20 bpl 0xcdd34 <_ZN7IBuffer4ReadEPKvjj+0x98> */
/* @0xcdd24 adds r3, r3, r4 */
/* @0xcdd28 bmi 0xcdd1c <_ZN7IBuffer4ReadEPKvjj+0x80> */
/* @0xcdd2c b 0xcdd34 <_ZN7IBuffer4ReadEPKvjj+0x98> */
/* @0xcdd30 rsb r3, r4, r3 */
/* @0xcdd34 cmp r3, r4 */
/* @0xcdd38 bge 0xcdd30 <_ZN7IBuffer4ReadEPKvjj+0x94> */
/* @0xcdd3c add r7, r3, r5 */
/* @0xcdd40 cmp r7, r4 */
/* @0xcdd44 ble 0xcdce8 <_ZN7IBuffer4ReadEPKvjj+0x4c> */
/* @0xcdd48 mov r7, r3 */
/* @0xcdd4c mov r11, #0 */
/* @0xcdd50 rsb r4, r7, r4 */
/* @0xcdd54 ldr r1, [r8, #0xc] */
/* @0xcdd58 cmp r4, r5 */
/* @0xcdd5c movlt r6, r4 */
/* @0xcdd60 movge r6, r5 */
/* @0xcdd64 add r0, r9, r11 */
/* @0xcdd68 add r1, r1, r7 */
/* @0xcdd6c rsb r5, r6, r5 */
/* @0xcdd70 mov r2, r6 */
/* @0xcdd74 add r11, r11, r6 */
/* @0xcdd78 bl 0xb65bc <memcpy@plt> */
/* @0xcdd7c ldr r4, [r8, #0x10] */
/* @0xcdd80 add r0, r7, r6 */
/* @0xcdd84 mov r1, r4 */
/* @0xcdd88 bl 0x318dec <__aeabi_idivmod> */
/* @0xcdd8c cmp r5, #0 */
/* @0xcdd90 mov r7, r1 */
/* @0xcdd94 bgt 0xcdd50 <_ZN7IBuffer4ReadEPKvjj+0xb4> */
/* @0xcdd98 mov r0, r10 */
/* @0xcdd9c str r7, [r8, #0x1c] */
/* @0xcdda0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xcdda4 rsb r5, r3, r2 */
/* @0xcdda8 mov r7, r2 */
/* @0xcddac b 0xcdce8 <_ZN7IBuffer4ReadEPKvjj+0x4c> */
/* @0xcddb0 mov r0, r9 */
/* @0xcddb4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0xcddb8 · IBuffer::Write(char const*) · size=188 · insn=47 */
/* @0xcddb8 push {r4, r5, r6, r7, r11, lr} */
/* @0xcddbc add r11, sp, #20 */
/* @0xcddc0 ldr r5, [pc, #0xa8] */
/* @0xcddc4 sub sp, sp, #8 */
/* @0xcddc8 subs r3, r1, #0 */
/* @0xcddcc ldr r5, [pc, r5] */
/* @0xcddd0 subeq sp, sp, #16 */
/* @0xcddd4 add r6, r0, #44 */
/* @0xcddd8 mov r4, r0 */
/* @0xcdddc ldr r2, [r5] */
/* @0xcdde0 moveq r3, sp */
/* @0xcdde4 strbeq r1, [r3, #0x1] */
/* @0xcdde8 mov r0, r6 */
/* @0xcddec mov r1, r3 */
/* @0xcddf0 str r2, [r11, #-0x18] */
/* @0xcddf4 moveq r2, #4 */
/* @0xcddf8 strbeq r2, [r3] */
/* @0xcddfc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xcde00 ldr r3, [r4] */
/* @0xcde04 mov r2, r6 */
/* @0xcde08 mov r0, r4 */
/* @0xcde0c mov r1, #11 */
/* @0xcde10 ldr r3, [r3, #0x8] */
/* @0xcde14 blx r3 */
/* @0xcde18 ldr r3, [r4, #0x38] */
/* @0xcde1c sub r3, r3, #1 */
/* @0xcde20 bic r3, r3, #-16777216 */
/* @0xcde24 bic r3, r3, #3 */
/* @0xcde28 cmp r3, #0 */
/* @0xcde2c mov r7, r0 */
/* @0xcde30 bne 0xcde3c <_ZN7IBuffer5WriteEPKc+0x84> */
/* @0xcde34 mov r0, r6 */
/* @0xcde38 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xcde3c ldr r12, [r11, #-0x18] */
/* @0xcde40 mov r3, #0 */
/* @0xcde44 ldr r1, [r5] */
/* @0xcde48 mov r2, #5 */
/* @0xcde4c mov r0, r7 */
/* @0xcde50 str r3, [r4, #0x34] */
/* @0xcde54 cmp r12, r1 */
/* @0xcde58 str r3, [r4, #0x2c] */
/* @0xcde5c str r2, [r4, #0x38] */
/* @0xcde60 bne 0xcde6c <_ZN7IBuffer5WriteEPKc+0xb4> */
/* @0xcde64 sub sp, r11, #20 */
/* @0xcde68 pop {r4, r5, r6, r7, r11, pc} */
/* @0xcde6c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xcde70 eorseq pc, r1, r4, lsl #23 */

/* ── FUNC 0xcde74 · IBuffer::ReadString() · size=152 · insn=38 */
/* @0xcde74 ldr r3, [r0] */
/* @0xcde78 mov r1, #11 */
/* @0xcde7c push {r4, r5, r6, lr} */
/* @0xcde80 add r6, r0, #44 */
/* @0xcde84 mov r4, r0 */
/* @0xcde88 ldr r3, [r3, #0xc] */
/* @0xcde8c mov r2, r6 */
/* @0xcde90 blx r3 */
/* @0xcde94 ldr r3, [r4, #0x38] */
/* @0xcde98 bic r2, r3, #-16777216 */
/* @0xcde9c cmp r2, #1 */
/* @0xcdea0 movne r5, #0 */
/* @0xcdea4 beq 0xcdee0 <_ZN7IBuffer10ReadStringEv+0x6c> */
/* @0xcdea8 sub r3, r3, #1 */
/* @0xcdeac bic r3, r3, #-16777216 */
/* @0xcdeb0 bic r3, r3, #3 */
/* @0xcdeb4 cmp r3, #0 */
/* @0xcdeb8 bne 0xcdec4 <_ZN7IBuffer10ReadStringEv+0x50> */
/* @0xcdebc mov r0, r6 */
/* @0xcdec0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xcdec4 mov r3, #0 */
/* @0xcdec8 mov r2, #5 */
/* @0xcdecc mov r0, r5 */
/* @0xcded0 str r3, [r4, #0x34] */
/* @0xcded4 str r3, [r4, #0x2c] */
/* @0xcded8 str r2, [r4, #0x38] */
/* @0xcdedc pop {r4, r5, r6, pc} */
/* @0xcdee0 ldr r5, [r4, #0x2c] */
/* @0xcdee4 cmp r5, #0 */
/* @0xcdee8 beq 0xcdea8 <_ZN7IBuffer10ReadStringEv+0x34> */
/* @0xcdeec ldr r0, [r5] */
/* @0xcdef0 cmp r0, #0 */
/* @0xcdef4 moveq r5, r0 */
/* @0xcdef8 beq 0xcdea8 <_ZN7IBuffer10ReadStringEv+0x34> */
/* @0xcdefc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xcdf00 ldr r3, [r4, #0x38] */
/* @0xcdf04 mov r5, r0 */
/* @0xcdf08 b 0xcdea8 <_ZN7IBuffer10ReadStringEv+0x34> */

/* ── FUNC 0xcdf0c · Code_Function_GET_the_function(int, char const**, void**, int*, int*) · size=120 · insn=30 */
/* @0xcdf0c ldr r12, [pc, #0x68] */
/* @0xcdf10 str r4, [sp, #-0x4]! */
/* @0xcdf14 ldr r12, [pc, r12] */
/* @0xcdf18 ldr r12, [r12] */
/* @0xcdf1c cmp r12, r0 */
/* @0xcdf20 blt 0xcdf74 <_Z30Code_Function_GET_the_functioniPPKcPPvPiS4_+0x68> */
/* @0xcdf24 cmp r0, #0 */
/* @0xcdf28 blt 0xcdf74 <_Z30Code_Function_GET_the_functioniPPKcPPvPiS4_+0x68> */
/* @0xcdf2c ldr r12, [pc, #0x4c] */
/* @0xcdf30 add r0, r0, r0, lsl #2 */
/* @0xcdf34 ldr r12, [pc, r12] */
/* @0xcdf38 lsl r0, r0, #4 */
/* @0xcdf3c ldr r4, [r12] */
/* @0xcdf40 add r4, r4, r0 */
/* @0xcdf44 str r4, [r1] */
/* @0xcdf48 ldr r1, [r12] */
/* @0xcdf4c add r1, r1, r0 */
/* @0xcdf50 ldr r1, [r1, #0x40] */
/* @0xcdf54 str r1, [r2] */
/* @0xcdf58 ldr r2, [r12] */
/* @0xcdf5c add r0, r2, r0 */
/* @0xcdf60 ldr r1, [r0, #0x44] */
/* @0xcdf64 ldrb r2, [r0, #0x48] */
/* @0xcdf68 str r1, [r3] */
/* @0xcdf6c ldr r3, [sp, #0x4] */
/* @0xcdf70 str r2, [r3] */
/* @0xcdf74 ldr r4, [sp], #4 */
/* @0xcdf78 bx lr */
/* @0xcdf7c eorseq pc, r1, r0, lsl #24 */
/* @0xcdf80 eorseq pc, r1, r4, ror #23 */

/* ── FUNC 0xcdf84 · Function_Add(char const*, void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool) · size=236 · insn=59 */
/* @0xcdf84 ldr r12, [pc, #0xd0] */
/* @0xcdf88 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xcdf8c add r12, pc, r12 */
/* @0xcdf90 ldr lr, [pc, #0xc8] */
/* @0xcdf94 mov r10, r0 */
/* @0xcdf98 ldr r0, [pc, #0xc4] */
/* @0xcdf9c mov r7, r3 */
/* @0xcdfa0 mov r9, r1 */
/* @0xcdfa4 mov r8, r2 */
/* @0xcdfa8 ldr r4, [r12, lr] */
/* @0xcdfac add r0, pc, r0 */
/* @0xcdfb0 ldr r3, [r0] */
/* @0xcdfb4 ldr r5, [r4] */
/* @0xcdfb8 cmp r5, r3 */
/* @0xcdfbc bge 0xce028 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib+0xa4> */
/* @0xcdfc0 ldr r3, [pc, #0xa0] */
/* @0xcdfc4 ldr r6, [r12, r3] */
/* @0xcdfc8 mov r0, r10 */
/* @0xcdfcc add r5, r5, #1 */
/* @0xcdfd0 str r5, [r4] */
/* @0xcdfd4 bl 0xb6538 <strlen@plt> */
/* @0xcdfd8 add r5, r5, r5, lsl #2 */
/* @0xcdfdc ldr r3, [r6] */
/* @0xcdfe0 mov r1, r10 */
/* @0xcdfe4 lsl r5, r5, #4 */
/* @0xcdfe8 sub r5, r5, #80 */
/* @0xcdfec add r2, r0, #1 */
/* @0xcdff0 add r0, r3, r5 */
/* @0xcdff4 bl 0xb65bc <memcpy@plt> */
/* @0xcdff8 ldr r3, [r4] */
/* @0xcdffc ldr r0, [r6] */
/* @0xce000 mvn r2, #0 */
/* @0xce004 add r3, r3, r3, lsl #2 */
/* @0xce008 lsl r3, r3, #4 */
/* @0xce00c sub r3, r3, #80 */
/* @0xce010 add r0, r0, r3 */
/* @0xce014 str r9, [r0, #0x40] */
/* @0xce018 str r8, [r0, #0x44] */
/* @0xce01c strb r7, [r0, #0x48] */
/* @0xce020 str r2, [r0, #0x4c] */
/* @0xce024 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xce028 ldr lr, [pc, #0x38] */
/* @0xce02c add r1, r3, #500 */
/* @0xce030 str r1, [r0] */
/* @0xce034 mov r3, #71 */
/* @0xce038 add r1, r1, r1, lsl #2 */
/* @0xce03c ldr r2, [pc, #0x28] */
/* @0xce040 ldr r6, [r12, lr] */
/* @0xce044 add r2, pc, r2 */
/* @0xce048 lsl r1, r1, #4 */
/* @0xce04c mov r0, r6 */
/* @0xce050 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xce054 ldr r5, [r4] */
/* @0xce058 b 0xcdfc8 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib+0x44> */
/* @0xce05c eorseq r3, r2, r4, asr #25 */
/* @0xce060 .word 0xffffbec4 */
/* @0xce064 mlaseq r10, r0, r1, r12 */
/* @0xce068 .word 0xffffbec8 */
/* @0xce06c eoreq r4, r6, r0, ror r1 */

/* ── FUNC 0xce070 · Function_Replace(char const*, void (*)(RValue&, CInstance*, CInstance*, int, RValue*)) · size=108 · insn=27 */
/* @0xce070 ldr r3, [pc, #0x5c] */
/* @0xce074 push {r4, r5, r6, r7, r8, lr} */
/* @0xce078 ldr r3, [pc, r3] */
/* @0xce07c mov r7, r0 */
/* @0xce080 mov r8, r1 */
/* @0xce084 ldr r6, [r3] */
/* @0xce088 cmp r6, #0 */
/* @0xce08c pople {r4, r5, r6, r7, r8, pc} */
/* @0xce090 ldr r3, [pc, #0x40] */
/* @0xce094 mov r5, #0 */
/* @0xce098 ldr r3, [pc, r3] */
/* @0xce09c ldr r4, [r3] */
/* @0xce0a0 b 0xce0b0 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E+0x40> */
/* @0xce0a4 cmp r5, r6 */
/* @0xce0a8 add r4, r4, #80 */
/* @0xce0ac beq 0xce0d0 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E+0x60> */
/* @0xce0b0 mov r0, r4 */
/* @0xce0b4 mov r1, r7 */
/* @0xce0b8 bl 0xb6574 <strcmp@plt> */
/* @0xce0bc add r5, r5, #1 */
/* @0xce0c0 cmp r0, #0 */
/* @0xce0c4 bne 0xce0a4 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E+0x34> */
/* @0xce0c8 str r8, [r4, #0x40] */
/* @0xce0cc pop {r4, r5, r6, r7, r8, pc} */
/* @0xce0d0 pop {r4, r5, r6, r7, r8, pc} */
/* @0xce0d4 mlaseq r1, r12, r10, pc */
/* @0xce0d8 eorseq pc, r1, r0, lsl #21 */

/* ── FUNC 0xce0dc · Function_GetArguments(int) · size=124 · insn=31 */
/* @0xce0dc movw r3, #0xa11f */
/* @0xce0e0 movt r3, #0x7 */
/* @0xce0e4 cmp r0, r3 */
/* @0xce0e8 bgt 0xce134 <_Z21Function_GetArgumentsi+0x58> */
/* @0xce0ec movw r3, #0x869f */
/* @0xce0f0 movt r3, #0x1 */
/* @0xce0f4 cmp r0, r3 */
/* @0xce0f8 bgt 0xce148 <_Z21Function_GetArgumentsi+0x6c> */
/* @0xce0fc cmp r0, #0 */
/* @0xce100 blt 0xce140 <_Z21Function_GetArgumentsi+0x64> */
/* @0xce104 ldr r3, [pc, #0x44] */
/* @0xce108 ldr r3, [pc, r3] */
/* @0xce10c ldr r3, [r3] */
/* @0xce110 cmp r0, r3 */
/* @0xce114 bge 0xce140 <_Z21Function_GetArgumentsi+0x64> */
/* @0xce118 ldr r3, [pc, #0x34] */
/* @0xce11c add r0, r0, r0, lsl #2 */
/* @0xce120 ldr r3, [pc, r3] */
/* @0xce124 ldr r3, [r3] */
/* @0xce128 add r0, r3, r0, lsl #4 */
/* @0xce12c ldr r0, [r0, #0x44] */
/* @0xce130 bx lr */
/* @0xce134 sub r0, r0, #499712 */
/* @0xce138 sub r0, r0, #288 */
/* @0xce13c b 0xf6240 <_Z31Extension_Function_GetArgumentsi> */
/* @0xce140 mvn r0, #99 */
/* @0xce144 bx lr */
/* @0xce148 mvn r0, #0 */
/* @0xce14c bx lr */
/* @0xce150 eorseq pc, r1, r12, lsl #20 */
/* @0xce154 ldrshteq pc, [r1], -r8 */

/* ── FUNC 0xce158 · Code_Function_Find(char const*, int*) · size=284 · insn=71 */
/* @0xce158 push {r4, r5, r6, r7, r8, lr} */
/* @0xce15c subs r4, r0, #0 */
/* @0xce160 mvn r3, #0 */
/* @0xce164 mov r5, r1 */
/* @0xce168 str r3, [r1] */
/* @0xce16c beq 0xce17c <_Z18Code_Function_FindPKcPi+0x24> */
/* @0xce170 ldrb r3, [r4] */
/* @0xce174 cmp r3, #0 */
/* @0xce178 bne 0xce184 <_Z18Code_Function_FindPKcPi+0x2c> */
/* @0xce17c mov r0, #0 */
/* @0xce180 pop {r4, r5, r6, r7, r8, pc} */
/* @0xce184 bl 0x1e0610 <_Z11Script_FindPKc> */
/* @0xce188 movw r3, #0x869f */
/* @0xce18c movt r3, #0x1 */
/* @0xce190 add r0, r0, #99328 */
/* @0xce194 add r0, r0, #672 */
/* @0xce198 str r0, [r5] */
/* @0xce19c cmp r0, r3 */
/* @0xce1a0 ble 0xce1ac <_Z18Code_Function_FindPKcPi+0x54> */
/* @0xce1a4 mov r0, #1 */
/* @0xce1a8 pop {r4, r5, r6, r7, r8, pc} */
/* @0xce1ac mov r0, r4 */
/* @0xce1b0 movw r6, #0xa11f */
/* @0xce1b4 bl 0xf61c0 <_Z24Extension_Function_GetIdPKc> */
/* @0xce1b8 movt r6, #0x7 */
/* @0xce1bc add r0, r0, #499712 */
/* @0xce1c0 add r3, r0, #288 */
/* @0xce1c4 str r3, [r5] */
/* @0xce1c8 cmp r3, r6 */
/* @0xce1cc bgt 0xce1a4 <_Z18Code_Function_FindPKcPi+0x4c> */
/* @0xce1d0 ldr r3, [pc, #0x8c] */
/* @0xce1d4 ldr r3, [pc, r3] */
/* @0xce1d8 ldrb r3, [r3] */
/* @0xce1dc cmp r3, #0 */
/* @0xce1e0 beq 0xce240 <_Z18Code_Function_FindPKcPi+0xe8> */
/* @0xce1e4 ldr r3, [pc, #0x7c] */
/* @0xce1e8 mvn r2, #0 */
/* @0xce1ec str r2, [r5] */
/* @0xce1f0 ldr r3, [pc, r3] */
/* @0xce1f4 ldr r8, [r3] */
/* @0xce1f8 cmp r8, #0 */
/* @0xce1fc ble 0xce17c <_Z18Code_Function_FindPKcPi+0x24> */
/* @0xce200 ldr r3, [pc, #0x64] */
/* @0xce204 mov r7, #0 */
/* @0xce208 ldr r3, [pc, r3] */
/* @0xce20c ldr r6, [r3] */
/* @0xce210 b 0xce220 <_Z18Code_Function_FindPKcPi+0xc8> */
/* @0xce214 add r7, r7, #1 */
/* @0xce218 cmp r7, r8 */
/* @0xce21c beq 0xce17c <_Z18Code_Function_FindPKcPi+0x24> */
/* @0xce220 mov r0, r6 */
/* @0xce224 mov r1, r4 */
/* @0xce228 bl 0xb6574 <strcmp@plt> */
/* @0xce22c add r6, r6, #80 */
/* @0xce230 cmp r0, #0 */
/* @0xce234 bne 0xce214 <_Z18Code_Function_FindPKcPi+0xbc> */
/* @0xce238 str r7, [r5] */
/* @0xce23c b 0xce1a4 <_Z18Code_Function_FindPKcPi+0x4c> */
/* @0xce240 ldr r0, [pc, #0x28] */
/* @0xce244 mov r1, r4 */
/* @0xce248 add r0, pc, r0 */
/* @0xce24c bl 0xb6574 <strcmp@plt> */
/* @0xce250 cmp r0, #0 */
/* @0xce254 bne 0xce1e4 <_Z18Code_Function_FindPKcPi+0x8c> */
/* @0xce258 str r6, [r5] */
/* @0xce25c mov r0, #1 */
/* @0xce260 pop {r4, r5, r6, r7, r8, pc} */
/* @0xce264 eorseq pc, r1, r8, asr #18 */
/* @0xce268 eorseq pc, r1, r4, lsr #18 */
/* @0xce26c eorseq pc, r1, r0, lsl r9 */
/* @0xce270 eoreq r3, r6, r4, lsr #31 */

/* ── FUNC 0xce274 · FINALIZE_Code_Function() · size=68 · insn=17 */
/* @0xce274 push {r4, lr} */
/* @0xce278 ldr r4, [pc, #0x2c] */
/* @0xce27c ldr r4, [pc, r4] */
/* @0xce280 ldr r0, [r4] */
/* @0xce284 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xce288 ldr r2, [pc, #0x20] */
/* @0xce28c ldr r1, [pc, #0x20] */
/* @0xce290 mov r3, #0 */
/* @0xce294 ldr r2, [pc, r2] */
/* @0xce298 str r3, [r4] */
/* @0xce29c add r1, pc, r1 */
/* @0xce2a0 str r3, [r2] */
/* @0xce2a4 str r3, [r1] */
/* @0xce2a8 pop {r4, pc} */
/* @0xce2ac mlaseq r1, r12, r8, pc */
/* @0xce2b0 eorseq pc, r1, r0, lsl #17 */
/* @0xce2b4 eorseq r11, r10, r0, lsr #29 */

/* ── FUNC 0xce2b8 · CCode::~CCode() · size=180 · insn=45 */
/* @0xce2b8 ldrb r2, [r0, #0x68] */
/* @0xce2bc ldr r3, [pc, #0x9c] */
/* @0xce2c0 ldr r1, [pc, #0x9c] */
/* @0xce2c4 cmp r2, #0 */
/* @0xce2c8 ldr r3, [pc, r3] */
/* @0xce2cc ldr r1, [pc, r1] */
/* @0xce2d0 push {r4, lr} */
/* @0xce2d4 add r1, r1, #8 */
/* @0xce2d8 ldr r2, [r3] */
/* @0xce2dc mov r4, r0 */
/* @0xce2e0 str r1, [r0] */
/* @0xce2e4 bne 0xce328 <_ZN5CCodeD2Ev+0x70> */
/* @0xce2e8 cmp r2, #0 */
/* @0xce2ec beq 0xce314 <_ZN5CCodeD2Ev+0x5c> */
/* @0xce2f0 cmp r0, r2 */
/* @0xce2f4 bne 0xce308 <_ZN5CCodeD2Ev+0x50> */
/* @0xce2f8 b 0xce354 <_ZN5CCodeD2Ev+0x9c> */
/* @0xce2fc cmp r4, r3 */
/* @0xce300 beq 0xce348 <_ZN5CCodeD2Ev+0x90> */
/* @0xce304 mov r2, r3 */
/* @0xce308 ldr r3, [r2, #0x4] */
/* @0xce30c cmp r3, #0 */
/* @0xce310 bne 0xce2fc <_ZN5CCodeD2Ev+0x44> */
/* @0xce314 ldr r3, [pc, #0x4c] */
/* @0xce318 ldr r3, [pc, r3] */
/* @0xce31c ldr r2, [r3] */
/* @0xce320 sub r2, r2, #1 */
/* @0xce324 str r2, [r3] */
/* @0xce328 ldr r0, [r4, #0x50] */
/* @0xce32c cmp r0, #0 */
/* @0xce330 beq 0xce340 <_ZN5CCodeD2Ev+0x88> */
/* @0xce334 ldr r3, [r0] */
/* @0xce338 ldr r3, [r3, #0x4] */
/* @0xce33c blx r3 */
/* @0xce340 mov r0, r4 */
/* @0xce344 pop {r4, pc} */
/* @0xce348 ldr r3, [r4, #0x4] */
/* @0xce34c str r3, [r2, #0x4] */
/* @0xce350 b 0xce314 <_ZN5CCodeD2Ev+0x5c> */
/* @0xce354 ldr r2, [r0, #0x4] */
/* @0xce358 str r2, [r3] */
/* @0xce35c b 0xce314 <_ZN5CCodeD2Ev+0x5c> */
/* @0xce360 eorseq pc, r1, r8, asr r8 */
/* @0xce364 eorseq pc, r1, r8, asr r8 */
/* @0xce368 eorseq pc, r1, r0, lsl r8 */

/* ── FUNC 0xce2b8 · CCode::~CCode() · alias of the symbol above · insn=0 */

/* ── FUNC 0xce36c · CCode::~CCode() · size=28 · insn=7 */
/* @0xce36c push {r4, lr} */
/* @0xce370 mov r4, r0 */
/* @0xce374 bl 0xce2b8 <_ZN5CCodeD2Ev> */
/* @0xce378 mov r0, r4 */
/* @0xce37c bl 0x27d1d0 <_ZdlPv> */
/* @0xce380 mov r0, r4 */
/* @0xce384 pop {r4, pc} */

/* ── FUNC 0xce388 · anon_ce388 · size=176 · insn=45 */
/* @0xce388 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xce38c mov r4, r0 */
/* @0xce390 ldr r5, [r0] */
/* @0xce394 sub sp, sp, #20 */
/* @0xce398 mov r0, r3 */
/* @0xce39c mov r8, r2 */
/* @0xce3a0 mov r7, r3 */
/* @0xce3a4 ldr r11, [r1] */
/* @0xce3a8 mov r10, r1 */
/* @0xce3ac bl 0xb6538 <strlen@plt> */
/* @0xce3b0 rsb r9, r11, r5 */
/* @0xce3b4 ldr r3, [r8] */
/* @0xce3b8 add r2, r9, #1 */
/* @0xce3bc add r2, r0, r2 */
/* @0xce3c0 mov r6, r0 */
/* @0xce3c4 cmp r3, r2 */
/* @0xce3c8 bge 0xce418 <_ZN5CCodeD0Ev+0xac> */
/* @0xce3cc add r2, r2, #1 */
/* @0xce3d0 lsl r3, r3, #1 */
/* @0xce3d4 cmp r2, r3 */
/* @0xce3d8 movge r12, r2 */
/* @0xce3dc movlt r12, r3 */
/* @0xce3e0 ldr r2, [pc, #0x50] */
/* @0xce3e4 mov r3, #0 */
/* @0xce3e8 mov r0, r11 */
/* @0xce3ec mov r1, r12 */
/* @0xce3f0 str r3, [sp] */
/* @0xce3f4 add r2, pc, r2 */
/* @0xce3f8 movw r3, #0x38b */
/* @0xce3fc str r12, [sp, #0xc] */
/* @0xce400 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xce404 ldr r12, [sp, #0xc] */
/* @0xce408 str r0, [r10] */
/* @0xce40c add r5, r0, r9 */
/* @0xce410 str r5, [r4] */
/* @0xce414 str r12, [r8] */
/* @0xce418 mov r0, r5 */
/* @0xce41c mov r1, r7 */
/* @0xce420 bl 0xb65a4 <strcpy@plt> */
/* @0xce424 ldr r3, [r4] */
/* @0xce428 add r6, r3, r6 */
/* @0xce42c str r6, [r4] */
/* @0xce430 add sp, sp, #20 */
/* @0xce434 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xce438 eoreq r3, r6, r8, lsl #28 */

/* ── FUNC 0xce43c · VMBuffer::~VMBuffer() · size=132 · insn=33 */
/* @0xce43c push {r4, lr} */
/* @0xce440 mov r4, r0 */
/* @0xce444 ldr r0, [r0, #0x14] */
/* @0xce448 ldr r3, [pc, #0x6c] */
/* @0xce44c cmp r0, #0 */
/* @0xce450 ldr r3, [pc, r3] */
/* @0xce454 add r3, r3, #8 */
/* @0xce458 str r3, [r4] */
/* @0xce45c beq 0xce46c <_ZN8VMBufferD2Ev+0x30> */
/* @0xce460 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xce464 mov r3, #0 */
/* @0xce468 str r3, [r4, #0x14] */
/* @0xce46c ldr r0, [r4, #0x18] */
/* @0xce470 cmp r0, #0 */
/* @0xce474 beq 0xce484 <_ZN8VMBufferD2Ev+0x48> */
/* @0xce478 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xce47c mov r3, #0 */
/* @0xce480 str r3, [r4, #0x18] */
/* @0xce484 ldr r0, [r4, #0x10] */
/* @0xce488 cmp r0, #0 */
/* @0xce48c beq 0xce4b4 <_ZN8VMBufferD2Ev+0x78> */
/* @0xce490 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0xce494 cmp r0, #0 */
/* @0xce498 bne 0xce4b4 <_ZN8VMBufferD2Ev+0x78> */
/* @0xce49c ldr r0, [r4, #0x10] */
/* @0xce4a0 cmp r0, #0 */
/* @0xce4a4 beq 0xce4ac <_ZN8VMBufferD2Ev+0x70> */
/* @0xce4a8 bl 0x27d1d4 <_ZdaPv> */
/* @0xce4ac mov r3, #0 */
/* @0xce4b0 str r3, [r4, #0x10] */
/* @0xce4b4 mov r0, r4 */
/* @0xce4b8 pop {r4, pc} */
/* @0xce4bc ldrsbteq pc, [r1], -r12 */

/* ── FUNC 0xce43c · VMBuffer::~VMBuffer() · alias of the symbol above · insn=0 */

/* ── FUNC 0xce4c0 · VMBuffer::~VMBuffer() · size=140 · insn=35 */
/* @0xce4c0 push {r4, lr} */
/* @0xce4c4 mov r4, r0 */
/* @0xce4c8 ldr r0, [r0, #0x14] */
/* @0xce4cc ldr r3, [pc, #0x74] */
/* @0xce4d0 cmp r0, #0 */
/* @0xce4d4 ldr r3, [pc, r3] */
/* @0xce4d8 add r3, r3, #8 */
/* @0xce4dc str r3, [r4] */
/* @0xce4e0 beq 0xce4f0 <_ZN8VMBufferD0Ev+0x30> */
/* @0xce4e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xce4e8 mov r3, #0 */
/* @0xce4ec str r3, [r4, #0x14] */
/* @0xce4f0 ldr r0, [r4, #0x18] */
/* @0xce4f4 cmp r0, #0 */
/* @0xce4f8 beq 0xce508 <_ZN8VMBufferD0Ev+0x48> */
/* @0xce4fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xce500 mov r3, #0 */
/* @0xce504 str r3, [r4, #0x18] */
/* @0xce508 ldr r0, [r4, #0x10] */
/* @0xce50c cmp r0, #0 */
/* @0xce510 beq 0xce538 <_ZN8VMBufferD0Ev+0x78> */
/* @0xce514 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0xce518 cmp r0, #0 */
/* @0xce51c bne 0xce538 <_ZN8VMBufferD0Ev+0x78> */
/* @0xce520 ldr r0, [r4, #0x10] */
/* @0xce524 cmp r0, #0 */
/* @0xce528 beq 0xce530 <_ZN8VMBufferD0Ev+0x70> */
/* @0xce52c bl 0x27d1d4 <_ZdaPv> */
/* @0xce530 mov r3, #0 */
/* @0xce534 str r3, [r4, #0x10] */
/* @0xce538 mov r0, r4 */
/* @0xce53c bl 0x27d1d0 <_ZdlPv> */
/* @0xce540 mov r0, r4 */
/* @0xce544 pop {r4, pc} */
/* @0xce548 eorseq pc, r1, r8, asr r6 */

/* ── FUNC 0xce54c · KindName(RValue const*) · size=372 · insn=93 */
/* @0xce54c push {r3, lr} */
/* @0xce550 ldr r3, [r0, #0xc] */
/* @0xce554 bic r3, r3, #-16777216 */
/* @0xce558 cmp r3, #14 */
/* @0xce55c addls pc, pc, r3, lsl #2 */
/* @0xce560 b 0xce664 <_Z8KindNamePK6RValue+0x118> */
/* @0xce564 b 0xce5a0 <_Z8KindNamePK6RValue+0x54> */
/* @0xce568 b 0xce5ac <_Z8KindNamePK6RValue+0x60> */
/* @0xce56c b 0xce5b8 <_Z8KindNamePK6RValue+0x6c> */
/* @0xce570 b 0xce5c4 <_Z8KindNamePK6RValue+0x78> */
/* @0xce574 b 0xce5d0 <_Z8KindNamePK6RValue+0x84> */
/* @0xce578 b 0xce5dc <_Z8KindNamePK6RValue+0x90> */
/* @0xce57c b 0xce5e8 <_Z8KindNamePK6RValue+0x9c> */
/* @0xce580 b 0xce604 <_Z8KindNamePK6RValue+0xb8> */
/* @0xce584 b 0xce610 <_Z8KindNamePK6RValue+0xc4> */
/* @0xce588 b 0xce61c <_Z8KindNamePK6RValue+0xd0> */
/* @0xce58c b 0xce628 <_Z8KindNamePK6RValue+0xdc> */
/* @0xce590 b 0xce634 <_Z8KindNamePK6RValue+0xe8> */
/* @0xce594 b 0xce640 <_Z8KindNamePK6RValue+0xf4> */
/* @0xce598 b 0xce64c <_Z8KindNamePK6RValue+0x100> */
/* @0xce59c b 0xce658 <_Z8KindNamePK6RValue+0x10c> */
/* @0xce5a0 ldr r0, [pc, #0xd4] */
/* @0xce5a4 add r0, pc, r0 */
/* @0xce5a8 pop {r3, pc} */
/* @0xce5ac ldr r0, [pc, #0xcc] */
/* @0xce5b0 add r0, pc, r0 */
/* @0xce5b4 pop {r3, pc} */
/* @0xce5b8 ldr r0, [pc, #0xc4] */
/* @0xce5bc add r0, pc, r0 */
/* @0xce5c0 pop {r3, pc} */
/* @0xce5c4 ldr r0, [pc, #0xbc] */
/* @0xce5c8 add r0, pc, r0 */
/* @0xce5cc pop {r3, pc} */
/* @0xce5d0 ldr r0, [pc, #0xb4] */
/* @0xce5d4 add r0, pc, r0 */
/* @0xce5d8 pop {r3, pc} */
/* @0xce5dc ldr r0, [pc, #0xac] */
/* @0xce5e0 add r0, pc, r0 */
/* @0xce5e4 pop {r3, pc} */
/* @0xce5e8 ldr r0, [r0] */
/* @0xce5ec bl 0x240758 <_Z20JS_IsCallable_ObjectP12YYObjectBase> */
/* @0xce5f0 cmp r0, #0 */
/* @0xce5f4 beq 0xce670 <_Z8KindNamePK6RValue+0x124> */
/* @0xce5f8 ldr r0, [pc, #0x94] */
/* @0xce5fc add r0, pc, r0 */
/* @0xce600 pop {r3, pc} */
/* @0xce604 ldr r0, [pc, #0x8c] */
/* @0xce608 add r0, pc, r0 */
/* @0xce60c pop {r3, pc} */
/* @0xce610 ldr r0, [pc, #0x84] */
/* @0xce614 add r0, pc, r0 */
/* @0xce618 pop {r3, pc} */
/* @0xce61c ldr r0, [pc, #0x7c] */
/* @0xce620 add r0, pc, r0 */
/* @0xce624 pop {r3, pc} */
/* @0xce628 ldr r0, [pc, #0x74] */
/* @0xce62c add r0, pc, r0 */
/* @0xce630 pop {r3, pc} */
/* @0xce634 ldr r0, [pc, #0x6c] */
/* @0xce638 add r0, pc, r0 */
/* @0xce63c pop {r3, pc} */
/* @0xce640 ldr r0, [pc, #0x64] */
/* @0xce644 add r0, pc, r0 */
/* @0xce648 pop {r3, pc} */
/* @0xce64c ldr r0, [pc, #0x5c] */
/* @0xce650 add r0, pc, r0 */
/* @0xce654 pop {r3, pc} */
/* @0xce658 ldr r0, [pc, #0x54] */
/* @0xce65c add r0, pc, r0 */
/* @0xce660 pop {r3, pc} */
/* @0xce664 ldr r0, [pc, #0x4c] */
/* @0xce668 add r0, pc, r0 */
/* @0xce66c pop {r3, pc} */
/* @0xce670 ldr r0, [pc, #0x44] */
/* @0xce674 add r0, pc, r0 */
/* @0xce678 pop {r3, pc} */
/* @0xce67c eoreq r3, r6, r4, lsr #25 */
/* @0xce680 eoreq r2, r6, r8, ror r2 */
/* @0xce684 mlaeq r6, r4, r12, r3 */
/* @0xce688 eoreq r3, r6, r4, lsr #25 */
/* @0xce68c eoreq r3, r6, r12, lsr #25 */
/* @0xce690 eoreq r3, r6, r0, lsl #25 */
/* @0xce694 eoreq r3, r6, r4, lsr r12 */
/* @0xce698 eoreq r3, r6, r0, asr r12 */
/* @0xce69c eoreq r3, r6, r4, ror r12 */
/* @0xce6a0 eoreq r3, r6, r0, ror r12 */
/* @0xce6a4 eoreq r3, r6, r12, asr #24 */
/* @0xce6a8 eoreq r3, r6, r0, ror #24 */
/* @0xce6ac eoreq r3, r6, r0, ror #24 */
/* @0xce6b0 eoreq r3, r6, r0, lsr #24 */
/* @0xce6b4 eoreq r3, r6, r0, asr r12 */
/* @0xce6b8 .word 0x00263bd8 */
/* @0xce6bc eoreq r3, r6, r4, asr #23 */

/* ── FUNC 0xce6c0 · YYGetPtrOrInt(RValue const*, int) · size=168 · insn=42 */
/* @0xce6c0 add r2, r0, r1, lsl #4 */
/* @0xce6c4 push {r4, r5, r6, lr} */
/* @0xce6c8 mov r6, r1 */
/* @0xce6cc ldr r3, [r2, #0xc] */
/* @0xce6d0 bic r3, r3, #-16777216 */
/* @0xce6d4 cmp r3, #10 */
/* @0xce6d8 addls pc, pc, r3, lsl #2 */
/* @0xce6dc b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c> */
/* @0xce6e0 b 0xce714 <_Z13YYGetPtrOrIntPK6RValuei+0x54> */
/* @0xce6e4 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c> */
/* @0xce6e8 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c> */
/* @0xce6ec b 0xce70c <_Z13YYGetPtrOrIntPK6RValuei+0x4c> */
/* @0xce6f0 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c> */
/* @0xce6f4 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c> */
/* @0xce6f8 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c> */
/* @0xce6fc b 0xce70c <_Z13YYGetPtrOrIntPK6RValuei+0x4c> */
/* @0xce700 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c> */
/* @0xce704 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c> */
/* @0xce708 b 0xce70c <_Z13YYGetPtrOrIntPK6RValuei+0x4c> */
/* @0xce70c ldr r0, [r0, r1, lsl #4] */
/* @0xce710 pop {r4, r5, r6, pc} */
/* @0xce714 ldr r4, [r0, r1, lsl #4] */
/* @0xce718 ldr r5, [r2, #0x4] */
/* @0xce71c vmov d7, r4, r5 */
/* @0xce720 vcvt.s32.f64 s15, d7 */
/* @0xce724 vmov r0, s15 */
/* @0xce728 pop {r4, r5, r6, pc} */
/* @0xce72c ldr r3, [pc, #0x2c] */
/* @0xce730 mov r0, r2 */
/* @0xce734 ldr r3, [pc, r3] */
/* @0xce738 ldr r4, [r3] */
/* @0xce73c bl 0xce54c <_Z8KindNamePK6RValue> */
/* @0xce740 add r2, r6, #1 */
/* @0xce744 mov r1, r4 */
/* @0xce748 mov r3, r0 */
/* @0xce74c ldr r0, [pc, #0x10] */
/* @0xce750 add r0, pc, r0 */
/* @0xce754 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xce758 mvn r0, #0 */
/* @0xce75c pop {r4, r5, r6, pc} */
/* @0xce760 ldrshteq pc, [r1], -r12 */
/* @0xce764 eoreq r3, r6, r8, ror #22 */

/* ── FUNC 0xce768 · YYGetBool(RValue const*, int) · size=264 · insn=66 */
/* @0xce768 add r2, r0, r1, lsl #4 */
/* @0xce76c push {r4, r5, r6, lr} */
/* @0xce770 mov r6, r1 */
/* @0xce774 ldr r3, [r2, #0xc] */
/* @0xce778 bic r3, r3, #-16777216 */
/* @0xce77c cmp r3, #13 */
/* @0xce780 addls pc, pc, r3, lsl #2 */
/* @0xce784 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc> */
/* @0xce788 b 0xce810 <_Z9YYGetBoolPK6RValuei+0xa8> */
/* @0xce78c b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc> */
/* @0xce790 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc> */
/* @0xce794 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc> */
/* @0xce798 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc> */
/* @0xce79c b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc> */
/* @0xce7a0 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc> */
/* @0xce7a4 b 0xce7fc <_Z9YYGetBoolPK6RValuei+0x94> */
/* @0xce7a8 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc> */
/* @0xce7ac b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc> */
/* @0xce7b0 b 0xce7e0 <_Z9YYGetBoolPK6RValuei+0x78> */
/* @0xce7b4 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc> */
/* @0xce7b8 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc> */
/* @0xce7bc b 0xce7c0 <_Z9YYGetBoolPK6RValuei+0x58> */
/* @0xce7c0 ldr r4, [r0, r1, lsl #4] */
/* @0xce7c4 ldr r5, [r2, #0x4] */
/* @0xce7c8 vmov d6, r4, r5 */
/* @0xce7cc vcmp.f64 d6, #0 */
/* @0xce7d0 vmrs APSR_nzcv, fpscr */
/* @0xce7d4 moveq r0, #0 */
/* @0xce7d8 movne r0, #1 */
/* @0xce7dc pop {r4, r5, r6, pc} */
/* @0xce7e0 ldr r4, [r0, r1, lsl #4] */
/* @0xce7e4 ldr r5, [r2, #0x4] */
/* @0xce7e8 cmp r4, #1 */
/* @0xce7ec sbcs r3, r5, #0 */
/* @0xce7f0 movlt r0, #0 */
/* @0xce7f4 movge r0, #1 */
/* @0xce7f8 pop {r4, r5, r6, pc} */
/* @0xce7fc ldr r0, [r0, r1, lsl #4] */
/* @0xce800 cmp r0, #0 */
/* @0xce804 movle r0, #0 */
/* @0xce808 movgt r0, #1 */
/* @0xce80c pop {r4, r5, r6, pc} */
/* @0xce810 vmov.f64 d7, #5.000000e-01 */
/* @0xce814 ldr r4, [r0, r1, lsl #4] */
/* @0xce818 ldr r5, [r2, #0x4] */
/* @0xce81c vmov d6, r4, r5 */
/* @0xce820 vcmpe.f64 d6, d7 */
/* @0xce824 vmrs APSR_nzcv, fpscr */
/* @0xce828 movle r0, #0 */
/* @0xce82c movgt r0, #1 */
/* @0xce830 pop {r4, r5, r6, pc} */
/* @0xce834 ldr r3, [pc, #0x2c] */
/* @0xce838 mov r0, r2 */
/* @0xce83c ldr r3, [pc, r3] */
/* @0xce840 ldr r4, [r3] */
/* @0xce844 bl 0xce54c <_Z8KindNamePK6RValue> */
/* @0xce848 add r2, r6, #1 */
/* @0xce84c mov r1, r4 */
/* @0xce850 mov r3, r0 */
/* @0xce854 ldr r0, [pc, #0x10] */
/* @0xce858 add r0, pc, r0 */
/* @0xce85c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xce860 mov r0, #0 */
/* @0xce864 pop {r4, r5, r6, pc} */
/* @0xce868 ldrshteq pc, [r1], -r4 */
/* @0xce86c eoreq r3, r6, r4, lsr #21 */

/* ── FUNC 0xce870 · YYGetInt32(RValue const*, int) · size=224 · insn=56 */
/* @0xce870 push {r4, r5, r6, lr} */
/* @0xce874 mov r6, r1 */
/* @0xce878 add r1, r0, r1, lsl #4 */
/* @0xce87c sub sp, sp, #16 */
/* @0xce880 ldr r3, [r1, #0xc] */
/* @0xce884 bic r3, r3, #-16777216 */
/* @0xce888 cmp r3, #13 */
/* @0xce88c addls pc, pc, r3, lsl #2 */
/* @0xce890 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0> */
/* @0xce894 b 0xce8f4 <_Z10YYGetInt32PK6RValuei+0x84> */
/* @0xce898 b 0xce8d8 <_Z10YYGetInt32PK6RValuei+0x68> */
/* @0xce89c b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0> */
/* @0xce8a0 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0> */
/* @0xce8a4 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0> */
/* @0xce8a8 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0> */
/* @0xce8ac b 0xce8d8 <_Z10YYGetInt32PK6RValuei+0x68> */
/* @0xce8b0 b 0xce8cc <_Z10YYGetInt32PK6RValuei+0x5c> */
/* @0xce8b4 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0> */
/* @0xce8b8 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0> */
/* @0xce8bc b 0xce8cc <_Z10YYGetInt32PK6RValuei+0x5c> */
/* @0xce8c0 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0> */
/* @0xce8c4 b 0xce910 <_Z10YYGetInt32PK6RValuei+0xa0> */
/* @0xce8c8 b 0xce8f4 <_Z10YYGetInt32PK6RValuei+0x84> */
/* @0xce8cc ldr r0, [r0, r6, lsl #4] */
/* @0xce8d0 add sp, sp, #16 */
/* @0xce8d4 pop {r4, r5, r6, pc} */
/* @0xce8d8 mov r0, sp */
/* @0xce8dc bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xce8e0 mov r0, sp */
/* @0xce8e4 mov r1, #0 */
/* @0xce8e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xce8ec add sp, sp, #16 */
/* @0xce8f0 pop {r4, r5, r6, pc} */
/* @0xce8f4 ldr r4, [r0, r6, lsl #4] */
/* @0xce8f8 ldr r5, [r1, #0x4] */
/* @0xce8fc mov r0, r4 */
/* @0xce900 mov r1, r5 */
/* @0xce904 bl 0x3194a0 <__fixdfdi> */
/* @0xce908 add sp, sp, #16 */
/* @0xce90c pop {r4, r5, r6, pc} */
/* @0xce910 ldr r3, [pc, #0x30] */
/* @0xce914 mov r0, r1 */
/* @0xce918 ldr r3, [pc, r3] */
/* @0xce91c ldr r4, [r3] */
/* @0xce920 bl 0xce54c <_Z8KindNamePK6RValue> */
/* @0xce924 add r2, r6, #1 */
/* @0xce928 mov r1, r4 */
/* @0xce92c mov r3, r0 */
/* @0xce930 ldr r0, [pc, #0x14] */
/* @0xce934 add r0, pc, r0 */
/* @0xce938 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xce93c mov r0, #0 */
/* @0xce940 add sp, sp, #16 */
/* @0xce944 pop {r4, r5, r6, pc} */
/* @0xce948 eorseq pc, r1, r8, lsl r2 */
/* @0xce94c eoreq r3, r6, r8, lsl #20 */

/* ── FUNC 0xce950 · YYGetUint32(RValue const*, int) · size=224 · insn=56 */
/* @0xce950 push {r4, r5, r6, lr} */
/* @0xce954 mov r6, r1 */
/* @0xce958 add r1, r0, r1, lsl #4 */
/* @0xce95c sub sp, sp, #16 */
/* @0xce960 ldr r3, [r1, #0xc] */
/* @0xce964 bic r3, r3, #-16777216 */
/* @0xce968 cmp r3, #13 */
/* @0xce96c addls pc, pc, r3, lsl #2 */
/* @0xce970 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0> */
/* @0xce974 b 0xce9d4 <_Z11YYGetUint32PK6RValuei+0x84> */
/* @0xce978 b 0xce9b8 <_Z11YYGetUint32PK6RValuei+0x68> */
/* @0xce97c b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0> */
/* @0xce980 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0> */
/* @0xce984 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0> */
/* @0xce988 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0> */
/* @0xce98c b 0xce9b8 <_Z11YYGetUint32PK6RValuei+0x68> */
/* @0xce990 b 0xce9ac <_Z11YYGetUint32PK6RValuei+0x5c> */
/* @0xce994 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0> */
/* @0xce998 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0> */
/* @0xce99c b 0xce9ac <_Z11YYGetUint32PK6RValuei+0x5c> */
/* @0xce9a0 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0> */
/* @0xce9a4 b 0xce9f0 <_Z11YYGetUint32PK6RValuei+0xa0> */
/* @0xce9a8 b 0xce9d4 <_Z11YYGetUint32PK6RValuei+0x84> */
/* @0xce9ac ldr r0, [r0, r6, lsl #4] */
/* @0xce9b0 add sp, sp, #16 */
/* @0xce9b4 pop {r4, r5, r6, pc} */
/* @0xce9b8 mov r0, sp */
/* @0xce9bc bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xce9c0 mov r0, sp */
/* @0xce9c4 mov r1, #0 */
/* @0xce9c8 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0xce9cc add sp, sp, #16 */
/* @0xce9d0 pop {r4, r5, r6, pc} */
/* @0xce9d4 ldr r4, [r0, r6, lsl #4] */
/* @0xce9d8 ldr r5, [r1, #0x4] */
/* @0xce9dc vmov d7, r4, r5 */
/* @0xce9e0 vcvt.u32.f64 s15, d7 */
/* @0xce9e4 vmov r0, s15 */
/* @0xce9e8 add sp, sp, #16 */
/* @0xce9ec pop {r4, r5, r6, pc} */
/* @0xce9f0 ldr r3, [pc, #0x30] */
/* @0xce9f4 mov r0, r1 */
/* @0xce9f8 ldr r3, [pc, r3] */
/* @0xce9fc ldr r4, [r3] */
/* @0xcea00 bl 0xce54c <_Z8KindNamePK6RValue> */
/* @0xcea04 add r2, r6, #1 */
/* @0xcea08 mov r1, r4 */
/* @0xcea0c mov r3, r0 */
/* @0xcea10 ldr r0, [pc, #0x14] */
/* @0xcea14 add r0, pc, r0 */
/* @0xcea18 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xcea1c mov r0, #0 */
/* @0xcea20 add sp, sp, #16 */
/* @0xcea24 pop {r4, r5, r6, pc} */
/* @0xcea28 eorseq pc, r1, r8, lsr r1 */
/* @0xcea2c eoreq r3, r6, r8, ror #18 */

/* ── FUNC 0xcea30 · YYGetInt64(RValue const*, int) · size=244 · insn=61 */
/* @0xcea30 add r2, r0, r1, lsl #4 */
/* @0xcea34 push {r4, r6, lr} */
/* @0xcea38 mov r6, r1 */
/* @0xcea3c ldr r3, [r2, #0xc] */
/* @0xcea40 sub sp, sp, #20 */
/* @0xcea44 bic r3, r3, #-16777216 */
/* @0xcea48 cmp r3, #13 */
/* @0xcea4c addls pc, pc, r3, lsl #2 */
/* @0xcea50 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0> */
/* @0xcea54 b 0xceacc <_Z10YYGetInt64PK6RValuei+0x9c> */
/* @0xcea58 b 0xceaac <_Z10YYGetInt64PK6RValuei+0x7c> */
/* @0xcea5c b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0> */
/* @0xcea60 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0> */
/* @0xcea64 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0> */
/* @0xcea68 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0> */
/* @0xcea6c b 0xceaac <_Z10YYGetInt64PK6RValuei+0x7c> */
/* @0xcea70 b 0xcea9c <_Z10YYGetInt64PK6RValuei+0x6c> */
/* @0xcea74 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0> */
/* @0xcea78 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0> */
/* @0xcea7c b 0xcea8c <_Z10YYGetInt64PK6RValuei+0x5c> */
/* @0xcea80 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0> */
/* @0xcea84 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0> */
/* @0xcea88 b 0xceacc <_Z10YYGetInt64PK6RValuei+0x9c> */
/* @0xcea8c ldr r0, [r0, r1, lsl #4] */
/* @0xcea90 ldr r1, [r2, #0x4] */
/* @0xcea94 add sp, sp, #20 */
/* @0xcea98 pop {r4, r6, pc} */
/* @0xcea9c ldr r0, [r0, r1, lsl #4] */
/* @0xceaa0 asr r1, r0, #31 */
/* @0xceaa4 add sp, sp, #20 */
/* @0xceaa8 pop {r4, r6, pc} */
/* @0xceaac mov r1, r2 */
/* @0xceab0 mov r0, sp */
/* @0xceab4 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xceab8 mov r0, sp */
/* @0xceabc mov r1, #0 */
/* @0xceac0 bl 0xcea30 <_Z10YYGetInt64PK6RValuei> */
/* @0xceac4 add sp, sp, #20 */
/* @0xceac8 pop {r4, r6, pc} */
/* @0xceacc ldr r0, [r0, r1, lsl #4] */
/* @0xcead0 ldr r1, [r2, #0x4] */
/* @0xcead4 bl 0x3194a0 <__fixdfdi> */
/* @0xcead8 add sp, sp, #20 */
/* @0xceadc pop {r4, r6, pc} */
/* @0xceae0 ldr r3, [pc, #0x34] */
/* @0xceae4 mov r0, r2 */
/* @0xceae8 ldr r3, [pc, r3] */
/* @0xceaec ldr r4, [r3] */
/* @0xceaf0 bl 0xce54c <_Z8KindNamePK6RValue> */
/* @0xceaf4 add r2, r6, #1 */
/* @0xceaf8 mov r1, r4 */
/* @0xceafc mov r3, r0 */
/* @0xceb00 ldr r0, [pc, #0x18] */
/* @0xceb04 add r0, pc, r0 */
/* @0xceb08 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xceb0c mov r0, #0 */
/* @0xceb10 mov r1, #0 */
/* @0xceb14 add sp, sp, #20 */
/* @0xceb18 pop {r4, r6, pc} */
/* @0xceb1c eorseq pc, r1, r8, asr #32 */
/* @0xceb20 .word 0x002638b8 */

/* ── FUNC 0xceb24 · YYGetReal(RValue const*, int) · size=244 · insn=61 */
/* @0xceb24 add r2, r0, r1, lsl #4 */
/* @0xceb28 push {r4, r5, lr} */
/* @0xceb2c mov r4, r1 */
/* @0xceb30 ldr r3, [r2, #0xc] */
/* @0xceb34 sub sp, sp, #20 */
/* @0xceb38 bic r3, r3, #-16777216 */
/* @0xceb3c cmp r3, #13 */
/* @0xceb40 addls pc, pc, r3, lsl #2 */
/* @0xceb44 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0> */
/* @0xceb48 b 0xcebc4 <_Z9YYGetRealPK6RValuei+0xa0> */
/* @0xceb4c b 0xcebac <_Z9YYGetRealPK6RValuei+0x88> */
/* @0xceb50 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0> */
/* @0xceb54 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0> */
/* @0xceb58 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0> */
/* @0xceb5c b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0> */
/* @0xceb60 b 0xcebac <_Z9YYGetRealPK6RValuei+0x88> */
/* @0xceb64 b 0xceb94 <_Z9YYGetRealPK6RValuei+0x70> */
/* @0xceb68 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0> */
/* @0xceb6c b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0> */
/* @0xceb70 b 0xceb80 <_Z9YYGetRealPK6RValuei+0x5c> */
/* @0xceb74 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0> */
/* @0xceb78 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0> */
/* @0xceb7c b 0xcebc4 <_Z9YYGetRealPK6RValuei+0xa0> */
/* @0xceb80 ldr r0, [r0, r1, lsl #4] */
/* @0xceb84 ldr r1, [r2, #0x4] */
/* @0xceb88 bl 0x319164 <__floatdidf> */
/* @0xceb8c add sp, sp, #20 */
/* @0xceb90 pop {r4, r5, pc} */
/* @0xceb94 ldr r0, [r0, r1, lsl #4] */
/* @0xceb98 vmov s15, r0 */
/* @0xceb9c vcvt.f64.s32 d7, s15 */
/* @0xceba0 vmov r0, r1, d7 */
/* @0xceba4 add sp, sp, #20 */
/* @0xceba8 pop {r4, r5, pc} */
/* @0xcebac mov r1, r2 */
/* @0xcebb0 mov r0, sp */
/* @0xcebb4 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xcebb8 ldrd r0, r1, [sp] */
/* @0xcebbc add sp, sp, #20 */
/* @0xcebc0 pop {r4, r5, pc} */
/* @0xcebc4 ldr r0, [r0, r1, lsl #4] */
/* @0xcebc8 ldr r1, [r2, #0x4] */
/* @0xcebcc add sp, sp, #20 */
/* @0xcebd0 pop {r4, r5, pc} */
/* @0xcebd4 ldr r3, [pc, #0x34] */
/* @0xcebd8 mov r0, r2 */
/* @0xcebdc ldr r3, [pc, r3] */
/* @0xcebe0 ldr r5, [r3] */
/* @0xcebe4 bl 0xce54c <_Z8KindNamePK6RValue> */
/* @0xcebe8 add r2, r4, #1 */
/* @0xcebec mov r1, r5 */
/* @0xcebf0 mov r3, r0 */
/* @0xcebf4 ldr r0, [pc, #0x18] */
/* @0xcebf8 add r0, pc, r0 */
/* @0xcebfc bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xcec00 mov r0, #0 */
/* @0xcec04 mov r1, #0 */
/* @0xcec08 add sp, sp, #20 */
/* @0xcec0c pop {r4, r5, pc} */
/* @0xcec10 eorseq lr, r1, r4, asr pc */
/* @0xcec14 .word 0x002637fc */

/* ── FUNC 0xcec18 · YYGetPtr(RValue const*, int) · size=108 · insn=27 */
/* @0xcec18 add r3, r0, r1, lsl #4 */
/* @0xcec1c push {r4, lr} */
/* @0xcec20 sub sp, sp, #8 */
/* @0xcec24 ldr r2, [r3, #0xc] */
/* @0xcec28 bic r2, r2, #-16777216 */
/* @0xcec2c cmp r2, #3 */
/* @0xcec30 bne 0xcec40 <_Z8YYGetPtrPK6RValuei+0x28> */
/* @0xcec34 ldr r0, [r0, r1, lsl #4] */
/* @0xcec38 add sp, sp, #8 */
/* @0xcec3c pop {r4, pc} */
/* @0xcec40 ldr r2, [pc, #0x34] */
/* @0xcec44 mov r0, r3 */
/* @0xcec48 ldr r2, [pc, r2] */
/* @0xcec4c ldr r4, [r2] */
/* @0xcec50 str r1, [sp, #0x4] */
/* @0xcec54 bl 0xce54c <_Z8KindNamePK6RValue> */
/* @0xcec58 ldr r1, [sp, #0x4] */
/* @0xcec5c add r2, r1, #1 */
/* @0xcec60 mov r1, r4 */
/* @0xcec64 mov r3, r0 */
/* @0xcec68 ldr r0, [pc, #0x10] */
/* @0xcec6c add r0, pc, r0 */
/* @0xcec70 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xcec74 mov r0, #0 */
/* @0xcec78 b 0xcec38 <_Z8YYGetPtrPK6RValuei+0x20> */
/* @0xcec7c eorseq lr, r1, r8, ror #29 */
/* @0xcec80 eoreq r3, r6, r8, asr #15 */
