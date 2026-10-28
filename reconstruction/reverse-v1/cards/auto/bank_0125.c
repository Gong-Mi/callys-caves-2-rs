/* libyoyo.so 覆盖卡组 0125
 * 函数 0x18c2fc..0x18de24，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x18c2fc · IO_Keymap_Set(int, int) · size=24 · insn=6 */
/* @0x18c2fc cmp r0, #255 */
/* @0x18c300 ldrls r3, [pc, #0x8] */
/* @0x18c304 ldrls r3, [pc, r3] */
/* @0x18c308 strls r1, [r3, r0, lsl #2] */
/* @0x18c30c bx lr */
/* @0x18c310 eoreq r4, r6, r12, lsl #6 */

/* ── FUNC 0x18c314 · IO_Keymap_Clear() · size=40 · insn=10 */
/* @0x18c314 ldr r2, [pc, #0x1c] */
/* @0x18c318 mov r3, #0 */
/* @0x18c31c ldr r2, [pc, r2] */
/* @0x18c320 sub r2, r2, #4 */
/* @0x18c324 str r3, [r2, #0x4]! */
/* @0x18c328 add r3, r3, #1 */
/* @0x18c32c cmp r3, #256 */
/* @0x18c330 bne 0x18c324 <_Z15IO_Keymap_Clearv+0x10> */
/* @0x18c334 bx lr */
/* @0x18c338 .word 0x002642f4 */

/* ── FUNC 0x18c33c · IO_Init() · size=356 · insn=89 */
/* @0x18c33c push {r3, r4, r5, r6, r7, lr} */
/* @0x18c340 mov r2, #2560 */
/* @0x18c344 ldr r4, [pc, #0x128] */
/* @0x18c348 mov r1, #0 */
/* @0x18c34c ldr r3, [pc, #0x124] */
/* @0x18c350 add r4, pc, r4 */
/* @0x18c354 ldr r0, [r4, r3] */
/* @0x18c358 bl 0xb65b0 <memset@plt> */
/* @0x18c35c bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0x18c360 bl 0x18c314 <_Z15IO_Keymap_Clearv> */
/* @0x18c364 ldr r3, [pc, #0x110] */
/* @0x18c368 ldr r3, [r4, r3] */
/* @0x18c36c ldrb r2, [r3] */
/* @0x18c370 cmp r2, #0 */
/* @0x18c374 bne 0x18c3f0 <_Z7IO_Initv+0xb4> */
/* @0x18c378 ldr r2, [pc, #0x100] */
/* @0x18c37c ldr r2, [r4, r2] */
/* @0x18c380 ldrb r2, [r2] */
/* @0x18c384 cmp r2, #0 */
/* @0x18c388 bne 0x18c3f0 <_Z7IO_Initv+0xb4> */
/* @0x18c38c ldr lr, [pc, #0xf0] */
/* @0x18c390 mov r3, #1 */
/* @0x18c394 ldr r1, [pc, #0xec] */
/* @0x18c398 mov r0, #5632 */
/* @0x18c39c mov r2, #171 */
/* @0x18c3a0 mov r12, #128 */
/* @0x18c3a4 ldr r5, [r4, lr] */
/* @0x18c3a8 add r1, pc, r1 */
/* @0x18c3ac str r12, [r5] */
/* @0x18c3b0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18c3b4 ldr r3, [pc, #0xd0] */
/* @0x18c3b8 ldr r12, [r5] */
/* @0x18c3bc ldr r3, [r4, r3] */
/* @0x18c3c0 cmp r12, #0 */
/* @0x18c3c4 str r0, [r3] */
/* @0x18c3c8 pople {r3, r4, r5, r6, r7, pc} */
/* @0x18c3cc mov r2, #0 */
/* @0x18c3d0 mov r3, r2 */
/* @0x18c3d4 add r1, r0, r2 */
/* @0x18c3d8 add r2, r2, #44 */
/* @0x18c3dc strh r3, [r1, #2] */
/* @0x18c3e0 add r3, r3, #1 */
/* @0x18c3e4 cmp r3, r12 */
/* @0x18c3e8 bne 0x18c3d4 <_Z7IO_Initv+0x98> */
/* @0x18c3ec pop {r3, r4, r5, r6, r7, pc} */
/* @0x18c3f0 ldr r2, [pc, #0x98] */
/* @0x18c3f4 ldr r5, [r4, r2] */
/* @0x18c3f8 ldr r2, [r5] */
/* @0x18c3fc cmp r2, #0 */
/* @0x18c400 beq 0x18c38c <_Z7IO_Initv+0x50> */
/* @0x18c404 ldr r1, [pc, #0x74] */
/* @0x18c408 ldr r7, [pc, #0x84] */
/* @0x18c40c ldr r1, [r4, r1] */
/* @0x18c410 add r7, pc, r7 */
/* @0x18c414 ldrb r1, [r1] */
/* @0x18c418 cmp r1, #0 */
/* @0x18c41c ldrne r7, [pc, #0x74] */
/* @0x18c420 movne r1, #0 */
/* @0x18c424 strbne r1, [r3] */
/* @0x18c428 addne r7, pc, r7 */
/* @0x18c42c ldr r3, [pc, #0x68] */
/* @0x18c430 ldr r6, [r4, r3] */
/* @0x18c434 ldr r0, [r6] */
/* @0x18c438 cmp r0, #0 */
/* @0x18c43c moveq r0, r2 */
/* @0x18c440 beq 0x18c44c <_Z7IO_Initv+0x110> */
/* @0x18c444 bl 0xb6850 <fclose@plt> */
/* @0x18c448 ldr r0, [r5] */
/* @0x18c44c mov r1, r7 */
/* @0x18c450 bl 0xb6844 <fopen@plt> */
/* @0x18c454 cmp r0, #0 */
/* @0x18c458 str r0, [r6] */
/* @0x18c45c beq 0x18c38c <_Z7IO_Initv+0x50> */
/* @0x18c460 mov r1, #0 */
/* @0x18c464 mov r2, #2 */
/* @0x18c468 mov r3, r1 */
/* @0x18c46c bl 0xb6928 <setvbuf@plt> */
/* @0x18c470 b 0x18c38c <_Z7IO_Initv+0x50> */
/* @0x18c474 eoreq r5, r6, r0, lsl #18 */
/* @0x18c478 .word 0xffffe9c4 */
/* @0x18c47c .word 0xffffe9c8 */
/* @0x18c480 .word 0xffffe9cc */
/* @0x18c484 .word 0xffffdf00 */
/* @0x18c488 andseq pc, r11, r4, lsr #29 */
/* @0x18c48c .word 0xffffdf04 */
/* @0x18c490 .word 0xffffe9d0 */
/* @0x18c494 andseq pc, r11, r8, lsr lr */
/* @0x18c498 ldrsbeq r11, [r10], -r0 */
/* @0x18c49c .word 0xffffe97c */

/* ── FUNC 0x18c4a0 · ValueToKey(char const*) · size=156 · insn=39 */
/* @0x18c4a0 push {r3, lr} */
/* @0x18c4a4 ldrb r3, [r0] */
/* @0x18c4a8 cmp r3, #86 */
/* @0x18c4ac beq 0x18c4fc <_Z10ValueToKeyPKc+0x5c> */
/* @0x18c4b0 cmp r3, #77 */
/* @0x18c4b4 beq 0x18c4e0 <_Z10ValueToKeyPKc+0x40> */
/* @0x18c4b8 ldr r2, [pc, #0x78] */
/* @0x18c4bc ldr r2, [pc, r2] */
/* @0x18c4c0 ldr r2, [r2] */
/* @0x18c4c4 add r2, r2, r3 */
/* @0x18c4c8 ldrb r2, [r2, #0x1] */
/* @0x18c4cc tst r2, #8 */
/* @0x18c4d0 beq 0x18c4d8 <_Z10ValueToKeyPKc+0x38> */
/* @0x18c4d4 mov r3, #0 */
/* @0x18c4d8 mov r0, r3 */
/* @0x18c4dc pop {r3, pc} */
/* @0x18c4e0 ldrb r1, [r0, #0x1] */
/* @0x18c4e4 cmp r1, #66 */
/* @0x18c4e8 bne 0x18c4b8 <_Z10ValueToKeyPKc+0x18> */
/* @0x18c4ec ldrb r2, [r0, #0x2] */
/* @0x18c4f0 cmp r2, #95 */
/* @0x18c4f4 bne 0x18c4b8 <_Z10ValueToKeyPKc+0x18> */
/* @0x18c4f8 b 0x18c4d4 <_Z10ValueToKeyPKc+0x34> */
/* @0x18c4fc ldrb r1, [r0, #0x1] */
/* @0x18c500 cmp r1, #75 */
/* @0x18c504 bne 0x18c4b8 <_Z10ValueToKeyPKc+0x18> */
/* @0x18c508 ldrb r2, [r0, #0x2] */
/* @0x18c50c cmp r2, #95 */
/* @0x18c510 bne 0x18c4b8 <_Z10ValueToKeyPKc+0x18> */
/* @0x18c514 bl 0xedc8c <_Z29Code_Constant_Find_IgnoreCasePKc> */
/* @0x18c518 cmp r0, #0 */
/* @0x18c51c beq 0x18c4d4 <_Z10ValueToKeyPKc+0x34> */
/* @0x18c520 ldm r0, {r2, r3} */
/* @0x18c524 vmov d7, r2, r3 */
/* @0x18c528 vcvt.u32.f64 s15, d7 */
/* @0x18c52c vmov r3, s15 */
/* @0x18c530 uxtb r3, r3 */
/* @0x18c534 b 0x18c4d8 <_Z10ValueToKeyPKc+0x38> */
/* @0x18c538 eoreq r1, r6, r4, asr #9 */

/* ── FUNC 0x18c53c · ValueToButton(char const*) · size=84 · insn=21 */
/* @0x18c53c push {r3, lr} */
/* @0x18c540 ldrb r2, [r0] */
/* @0x18c544 cmp r2, #77 */
/* @0x18c548 beq 0x18c554 <_Z13ValueToButtonPKc+0x18> */
/* @0x18c54c mov r0, #0 */
/* @0x18c550 pop {r3, pc} */
/* @0x18c554 ldrb r2, [r0, #0x1] */
/* @0x18c558 cmp r2, #66 */
/* @0x18c55c bne 0x18c54c <_Z13ValueToButtonPKc+0x10> */
/* @0x18c560 ldrb r3, [r0, #0x2] */
/* @0x18c564 cmp r3, #95 */
/* @0x18c568 bne 0x18c54c <_Z13ValueToButtonPKc+0x10> */
/* @0x18c56c bl 0xedc8c <_Z29Code_Constant_Find_IgnoreCasePKc> */
/* @0x18c570 cmp r0, #0 */
/* @0x18c574 beq 0x18c54c <_Z13ValueToButtonPKc+0x10> */
/* @0x18c578 ldm r0, {r2, r3} */
/* @0x18c57c vmov d7, r2, r3 */
/* @0x18c580 vcvt.u32.f64 s15, d7 */
/* @0x18c584 vmov r2, s15 */
/* @0x18c588 uxtb r0, r2 */
/* @0x18c58c pop {r3, pc} */

/* ── FUNC 0x18c590 · AllocateVirtualKey() · size=108 · insn=27 */
/* @0x18c590 ldr r3, [pc, #0x5c] */
/* @0x18c594 ldr r3, [pc, r3] */
/* @0x18c598 ldr r12, [r3] */
/* @0x18c59c cmp r12, #0 */
/* @0x18c5a0 ble 0x18c5e4 <_Z18AllocateVirtualKeyv+0x54> */
/* @0x18c5a4 ldr r3, [pc, #0x4c] */
/* @0x18c5a8 ldr r3, [pc, r3] */
/* @0x18c5ac ldr r2, [r3] */
/* @0x18c5b0 ldrsh r3, [r2] */
/* @0x18c5b4 cmp r3, #0 */
/* @0x18c5b8 beq 0x18c5ec <_Z18AllocateVirtualKeyv+0x5c> */
/* @0x18c5bc add r2, r2, #44 */
/* @0x18c5c0 mov r3, #0 */
/* @0x18c5c4 b 0x18c5d4 <_Z18AllocateVirtualKeyv+0x44> */
/* @0x18c5c8 ldrsh r1, [r2], #44 */
/* @0x18c5cc cmp r1, #0 */
/* @0x18c5d0 bxeq lr */
/* @0x18c5d4 add r3, r3, #1 */
/* @0x18c5d8 mov r0, r2 */
/* @0x18c5dc cmp r3, r12 */
/* @0x18c5e0 bne 0x18c5c8 <_Z18AllocateVirtualKeyv+0x38> */
/* @0x18c5e4 mov r0, #0 */
/* @0x18c5e8 bx lr */
/* @0x18c5ec mov r0, r2 */
/* @0x18c5f0 bx lr */
/* @0x18c5f4 .word 0x002635bc */
/* @0x18c5f8 eoreq r3, r6, r12, lsr #11 */

/* ── FUNC 0x18c5fc · FreeVirtualKey(SVirtualKeyDef*) · size=12 · insn=3 */
/* @0x18c5fc mov r3, #0 */
/* @0x18c600 strh r3, [r0] */
/* @0x18c604 bx lr */

/* ── FUNC 0x18c608 · FreeVirtualKey(int) · size=68 · insn=17 */
/* @0x18c608 cmp r0, #0 */
/* @0x18c60c bxlt lr */
/* @0x18c610 ldr r3, [pc, #0x2c] */
/* @0x18c614 ldr r3, [pc, r3] */
/* @0x18c618 ldr r3, [r3] */
/* @0x18c61c cmp r0, r3 */
/* @0x18c620 bxge lr */
/* @0x18c624 mov r2, #44 */
/* @0x18c628 ldr r3, [pc, #0x18] */
/* @0x18c62c mul r0, r2, r0 */
/* @0x18c630 ldr r3, [pc, r3] */
/* @0x18c634 mov r2, #0 */
/* @0x18c638 ldr r3, [r3] */
/* @0x18c63c strh r2, [r3, r0] */
/* @0x18c640 bx lr */
/* @0x18c644 eoreq r3, r6, r12, lsr r5 */
/* @0x18c648 eoreq r3, r6, r4, lsr #10 */

/* ── FUNC 0x18c64c · DeleteAllVirtualKeys() · size=76 · insn=19 */
/* @0x18c64c ldr r3, [pc, #0x3c] */
/* @0x18c650 ldr r3, [pc, r3] */
/* @0x18c654 ldr r3, [r3] */
/* @0x18c658 cmp r3, #0 */
/* @0x18c65c bxle lr */
/* @0x18c660 ldr r2, [pc, #0x2c] */
/* @0x18c664 mov r0, #44 */
/* @0x18c668 mul r0, r0, r3 */
/* @0x18c66c ldr r2, [pc, r2] */
/* @0x18c670 mov r3, #0 */
/* @0x18c674 ldr r1, [r2] */
/* @0x18c678 mov r2, r3 */
/* @0x18c67c strh r2, [r1, r3] */
/* @0x18c680 add r3, r3, #44 */
/* @0x18c684 cmp r3, r0 */
/* @0x18c688 bne 0x18c67c <_Z20DeleteAllVirtualKeysv+0x30> */
/* @0x18c68c bx lr */
/* @0x18c690 eoreq r3, r6, r0, lsl #10 */
/* @0x18c694 eoreq r3, r6, r8, ror #9 */

/* ── FUNC 0x18c698 · VirtualKeys_Serialise(IBuffer*) · size=928 · insn=232 */
/* @0x18c698 ldr r1, [r0] */
/* @0x18c69c mov r2, #38912 */
/* @0x18c6a0 ldr r3, [pc, #0x388] */
/* @0x18c6a4 movt r2, #0x408a */
/* @0x18c6a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18c6ac add r8, r0, #44 */
/* @0x18c6b0 sub sp, sp, #12 */
/* @0x18c6b4 mov r7, #0 */
/* @0x18c6b8 str r2, [r0, #0x30] */
/* @0x18c6bc mov r2, r8 */
/* @0x18c6c0 str r7, [r0, #0x2c] */
/* @0x18c6c4 mov r6, r0 */
/* @0x18c6c8 ldr r12, [r1, #0x8] */
/* @0x18c6cc mov r1, #6 */
/* @0x18c6d0 str r7, [r0, #0x38] */
/* @0x18c6d4 str r3, [sp, #0x4] */
/* @0x18c6d8 blx r12 */
/* @0x18c6dc ldr r3, [sp, #0x4] */
/* @0x18c6e0 ldr r12, [r6] */
/* @0x18c6e4 mov r2, r8 */
/* @0x18c6e8 ldr r3, [pc, r3] */
/* @0x18c6ec vldr s15, [r3] */
/* @0x18c6f0 vcvt.f64.s32 d7, s15 */
/* @0x18c6f4 str r7, [r6, #0x38] */
/* @0x18c6f8 mov r0, r6 */
/* @0x18c6fc mov r1, #6 */
/* @0x18c700 vmov r4, r5, d7 */
/* @0x18c704 vstr s14, [r6, #44] */
/* @0x18c708 str r5, [r6, #0x30] */
/* @0x18c70c ldr r12, [r12, #0x8] */
/* @0x18c710 str r3, [sp, #0x4] */
/* @0x18c714 blx r12 */
/* @0x18c718 ldr r3, [sp, #0x4] */
/* @0x18c71c ldr r2, [r3] */
/* @0x18c720 cmp r2, r7 */
/* @0x18c724 ble 0x18ca28 <_Z21VirtualKeys_SerialiseP7IBuffer+0x390> */
/* @0x18c728 ldr r9, [pc, #0x304] */
/* @0x18c72c mov r11, r7 */
/* @0x18c730 mov r10, r7 */
/* @0x18c734 ldr r9, [pc, r9] */
/* @0x18c738 ldr lr, [r9] */
/* @0x18c73c mov r1, #4 */
/* @0x18c740 ldr r12, [r6] */
/* @0x18c744 mov r2, r8 */
/* @0x18c748 mov r0, r6 */
/* @0x18c74c add r11, r11, #1 */
/* @0x18c750 ldrh r4, [lr, r7] */
/* @0x18c754 str r10, [r6, #0x38] */
/* @0x18c758 sxth r4, r4 */
/* @0x18c75c vmov s15, r4 */
/* @0x18c760 vcvt.f64.s32 d7, s15 */
/* @0x18c764 vmov r4, r5, d7 */
/* @0x18c768 vstr s14, [r6, #44] */
/* @0x18c76c str r5, [r6, #0x30] */
/* @0x18c770 ldr r12, [r12, #0x8] */
/* @0x18c774 str r3, [sp, #0x4] */
/* @0x18c778 blx r12 */
/* @0x18c77c ldr lr, [r9] */
/* @0x18c780 ldr r12, [r6] */
/* @0x18c784 mov r1, #4 */
/* @0x18c788 add lr, lr, r7 */
/* @0x18c78c mov r2, r8 */
/* @0x18c790 mov r0, r6 */
/* @0x18c794 ldrh r4, [lr, #2] */
/* @0x18c798 str r10, [r6, #0x38] */
/* @0x18c79c sxth r4, r4 */
/* @0x18c7a0 vmov s15, r4 */
/* @0x18c7a4 vcvt.f64.s32 d7, s15 */
/* @0x18c7a8 vmov r4, r5, d7 */
/* @0x18c7ac vstr s14, [r6, #44] */
/* @0x18c7b0 str r5, [r6, #0x30] */
/* @0x18c7b4 ldr r12, [r12, #0x8] */
/* @0x18c7b8 blx r12 */
/* @0x18c7bc ldr lr, [r9] */
/* @0x18c7c0 ldr r12, [r6] */
/* @0x18c7c4 mov r1, #6 */
/* @0x18c7c8 add lr, lr, r7 */
/* @0x18c7cc mov r2, r8 */
/* @0x18c7d0 mov r0, r6 */
/* @0x18c7d4 ldr r4, [lr, #0x4] */
/* @0x18c7d8 str r10, [r6, #0x38] */
/* @0x18c7dc vmov s15, r4 */
/* @0x18c7e0 vcvt.f64.s32 d7, s15 */
/* @0x18c7e4 vmov r4, r5, d7 */
/* @0x18c7e8 vstr s14, [r6, #44] */
/* @0x18c7ec str r5, [r6, #0x30] */
/* @0x18c7f0 ldr r12, [r12, #0x8] */
/* @0x18c7f4 blx r12 */
/* @0x18c7f8 ldr lr, [r9] */
/* @0x18c7fc ldr r12, [r6] */
/* @0x18c800 mov r1, #6 */
/* @0x18c804 add lr, lr, r7 */
/* @0x18c808 mov r2, r8 */
/* @0x18c80c mov r0, r6 */
/* @0x18c810 ldr r4, [lr, #0x8] */
/* @0x18c814 str r10, [r6, #0x38] */
/* @0x18c818 vmov s15, r4 */
/* @0x18c81c vcvt.f64.s32 d7, s15 */
/* @0x18c820 vmov r4, r5, d7 */
/* @0x18c824 vstr s14, [r6, #44] */
/* @0x18c828 str r5, [r6, #0x30] */
/* @0x18c82c ldr r12, [r12, #0x8] */
/* @0x18c830 blx r12 */
/* @0x18c834 ldr lr, [r9] */
/* @0x18c838 ldr r12, [r6] */
/* @0x18c83c mov r1, #6 */
/* @0x18c840 add lr, lr, r7 */
/* @0x18c844 mov r2, r8 */
/* @0x18c848 mov r0, r6 */
/* @0x18c84c ldr r4, [lr, #0xc] */
/* @0x18c850 str r10, [r6, #0x38] */
/* @0x18c854 vmov s15, r4 */
/* @0x18c858 vcvt.f64.s32 d7, s15 */
/* @0x18c85c vmov r4, r5, d7 */
/* @0x18c860 vstr s14, [r6, #44] */
/* @0x18c864 str r5, [r6, #0x30] */
/* @0x18c868 ldr r12, [r12, #0x8] */
/* @0x18c86c blx r12 */
/* @0x18c870 ldr lr, [r9] */
/* @0x18c874 ldr r12, [r6] */
/* @0x18c878 mov r1, #6 */
/* @0x18c87c add lr, lr, r7 */
/* @0x18c880 mov r2, r8 */
/* @0x18c884 mov r0, r6 */
/* @0x18c888 ldr r4, [lr, #0x10] */
/* @0x18c88c str r10, [r6, #0x38] */
/* @0x18c890 vmov s15, r4 */
/* @0x18c894 vcvt.f64.s32 d7, s15 */
/* @0x18c898 vmov r4, r5, d7 */
/* @0x18c89c vstr s14, [r6, #44] */
/* @0x18c8a0 str r5, [r6, #0x30] */
/* @0x18c8a4 ldr r12, [r12, #0x8] */
/* @0x18c8a8 blx r12 */
/* @0x18c8ac ldr lr, [r9] */
/* @0x18c8b0 ldr r12, [r6] */
/* @0x18c8b4 mov r1, #6 */
/* @0x18c8b8 add lr, lr, r7 */
/* @0x18c8bc mov r2, r8 */
/* @0x18c8c0 mov r0, r6 */
/* @0x18c8c4 ldr r4, [lr, #0x14] */
/* @0x18c8c8 str r10, [r6, #0x38] */
/* @0x18c8cc vmov s15, r4 */
/* @0x18c8d0 vcvt.f64.s32 d7, s15 */
/* @0x18c8d4 vmov r4, r5, d7 */
/* @0x18c8d8 vstr s14, [r6, #44] */
/* @0x18c8dc str r5, [r6, #0x30] */
/* @0x18c8e0 ldr r12, [r12, #0x8] */
/* @0x18c8e4 blx r12 */
/* @0x18c8e8 ldr lr, [r9] */
/* @0x18c8ec ldr r12, [r6] */
/* @0x18c8f0 mov r1, #6 */
/* @0x18c8f4 add lr, lr, r7 */
/* @0x18c8f8 mov r2, r8 */
/* @0x18c8fc mov r0, r6 */
/* @0x18c900 ldr r4, [lr, #0x18] */
/* @0x18c904 str r10, [r6, #0x38] */
/* @0x18c908 vmov s15, r4 */
/* @0x18c90c vcvt.f64.s32 d7, s15 */
/* @0x18c910 vmov r4, r5, d7 */
/* @0x18c914 vstr s14, [r6, #44] */
/* @0x18c918 str r5, [r6, #0x30] */
/* @0x18c91c ldr r12, [r12, #0x8] */
/* @0x18c920 blx r12 */
/* @0x18c924 ldr lr, [r9] */
/* @0x18c928 ldr r12, [r6] */
/* @0x18c92c mov r1, #6 */
/* @0x18c930 add lr, lr, r7 */
/* @0x18c934 mov r2, r8 */
/* @0x18c938 mov r0, r6 */
/* @0x18c93c ldr r4, [lr, #0x1c] */
/* @0x18c940 str r10, [r6, #0x38] */
/* @0x18c944 vmov s15, r4 */
/* @0x18c948 vcvt.f64.s32 d7, s15 */
/* @0x18c94c vmov r4, r5, d7 */
/* @0x18c950 vstr s14, [r6, #44] */
/* @0x18c954 str r5, [r6, #0x30] */
/* @0x18c958 ldr r12, [r12, #0x8] */
/* @0x18c95c blx r12 */
/* @0x18c960 ldr lr, [r9] */
/* @0x18c964 ldr r12, [r6] */
/* @0x18c968 mov r1, #6 */
/* @0x18c96c add lr, lr, r7 */
/* @0x18c970 mov r2, r8 */
/* @0x18c974 mov r0, r6 */
/* @0x18c978 ldr r4, [lr, #0x20] */
/* @0x18c97c str r10, [r6, #0x38] */
/* @0x18c980 vmov s15, r4 */
/* @0x18c984 vcvt.f64.s32 d7, s15 */
/* @0x18c988 vmov r4, r5, d7 */
/* @0x18c98c vstr s14, [r6, #44] */
/* @0x18c990 str r5, [r6, #0x30] */
/* @0x18c994 ldr r12, [r12, #0x8] */
/* @0x18c998 blx r12 */
/* @0x18c99c ldr lr, [r9] */
/* @0x18c9a0 ldr r12, [r6] */
/* @0x18c9a4 mov r1, #6 */
/* @0x18c9a8 add lr, lr, r7 */
/* @0x18c9ac mov r2, r8 */
/* @0x18c9b0 mov r0, r6 */
/* @0x18c9b4 ldr r4, [lr, #0x24] */
/* @0x18c9b8 str r10, [r6, #0x38] */
/* @0x18c9bc vmov s15, r4 */
/* @0x18c9c0 vcvt.f64.s32 d7, s15 */
/* @0x18c9c4 vmov r4, r5, d7 */
/* @0x18c9c8 vstr s14, [r6, #44] */
/* @0x18c9cc str r5, [r6, #0x30] */
/* @0x18c9d0 ldr r12, [r12, #0x8] */
/* @0x18c9d4 blx r12 */
/* @0x18c9d8 ldr lr, [r9] */
/* @0x18c9dc ldr r12, [r6] */
/* @0x18c9e0 mov r2, r8 */
/* @0x18c9e4 add lr, lr, r7 */
/* @0x18c9e8 mov r0, r6 */
/* @0x18c9ec mov r1, #6 */
/* @0x18c9f0 add r7, r7, #44 */
/* @0x18c9f4 ldr r4, [lr, #0x28] */
/* @0x18c9f8 str r10, [r6, #0x38] */
/* @0x18c9fc vmov s15, r4 */
/* @0x18ca00 vcvt.f64.s32 d7, s15 */
/* @0x18ca04 vmov r4, r5, d7 */
/* @0x18ca08 vstr s14, [r6, #44] */
/* @0x18ca0c str r5, [r6, #0x30] */
/* @0x18ca10 ldr r12, [r12, #0x8] */
/* @0x18ca14 blx r12 */
/* @0x18ca18 ldr r3, [sp, #0x4] */
/* @0x18ca1c ldr r2, [r3] */
/* @0x18ca20 cmp r2, r11 */
/* @0x18ca24 bgt 0x18c738 <_Z21VirtualKeys_SerialiseP7IBuffer+0xa0> */
/* @0x18ca28 add sp, sp, #12 */
/* @0x18ca2c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x18ca30 eoreq r3, r6, r8, ror #8 */
/* @0x18ca34 eoreq r3, r6, r0, lsr #8 */

/* ── FUNC 0x18ca38 · VirtualKeys_DeSerialise(IBuffer*) · size=744 · insn=186 */
/* @0x18ca38 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18ca3c add r4, r0, #44 */
/* @0x18ca40 ldr r3, [r0] */
/* @0x18ca44 mov r1, #6 */
/* @0x18ca48 mov r2, r4 */
/* @0x18ca4c mov r5, r0 */
/* @0x18ca50 ldr r3, [r3, #0xc] */
/* @0x18ca54 blx r3 */
/* @0x18ca58 mov r0, r4 */
/* @0x18ca5c mov r1, #0 */
/* @0x18ca60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18ca64 movw r3, #0x353 */
/* @0x18ca68 cmp r0, r3 */
/* @0x18ca6c beq 0x18ca78 <_Z23VirtualKeys_DeSerialiseP7IBuffer+0x40> */
/* @0x18ca70 mov r0, #0 */
/* @0x18ca74 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x18ca78 ldr r3, [r5] */
/* @0x18ca7c mov r1, #6 */
/* @0x18ca80 mov r2, r4 */
/* @0x18ca84 mov r0, r5 */
/* @0x18ca88 ldr r11, [pc, #0x288] */
/* @0x18ca8c ldr r3, [r3, #0xc] */
/* @0x18ca90 blx r3 */
/* @0x18ca94 mov r0, r4 */
/* @0x18ca98 mov r1, #0 */
/* @0x18ca9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18caa0 ldr r11, [pc, r11] */
/* @0x18caa4 cmp r0, #0 */
/* @0x18caa8 str r0, [r11] */
/* @0x18caac ble 0x18cd10 <_Z23VirtualKeys_DeSerialiseP7IBuffer+0x2d8> */
/* @0x18cab0 ldr r7, [pc, #0x264] */
/* @0x18cab4 mov r6, #0 */
/* @0x18cab8 mov r8, r6 */
/* @0x18cabc ldr r7, [pc, r7] */
/* @0x18cac0 ldr r3, [r5] */
/* @0x18cac4 mov r2, r4 */
/* @0x18cac8 mov r1, #4 */
/* @0x18cacc mov r0, r5 */
/* @0x18cad0 ldr r10, [r7] */
/* @0x18cad4 add r8, r8, #1 */
/* @0x18cad8 ldr r3, [r3, #0xc] */
/* @0x18cadc blx r3 */
/* @0x18cae0 mov r1, #0 */
/* @0x18cae4 mov r0, r4 */
/* @0x18cae8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18caec ldr r3, [r5] */
/* @0x18caf0 ldr r9, [r7] */
/* @0x18caf4 mov r2, r4 */
/* @0x18caf8 mov r1, #4 */
/* @0x18cafc ldr r3, [r3, #0xc] */
/* @0x18cb00 add r9, r9, r6 */
/* @0x18cb04 strh r0, [r10, r6] */
/* @0x18cb08 mov r0, r5 */
/* @0x18cb0c blx r3 */
/* @0x18cb10 mov r1, #0 */
/* @0x18cb14 mov r0, r4 */
/* @0x18cb18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18cb1c ldr r3, [r5] */
/* @0x18cb20 ldr r10, [r7] */
/* @0x18cb24 mov r2, r4 */
/* @0x18cb28 mov r1, #6 */
/* @0x18cb2c ldr r3, [r3, #0xc] */
/* @0x18cb30 add r10, r10, r6 */
/* @0x18cb34 strh r0, [r9, #2] */
/* @0x18cb38 mov r0, r5 */
/* @0x18cb3c blx r3 */
/* @0x18cb40 mov r1, #0 */
/* @0x18cb44 mov r0, r4 */
/* @0x18cb48 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18cb4c ldr r3, [r5] */
/* @0x18cb50 mov r2, r4 */
/* @0x18cb54 mov r1, #6 */
/* @0x18cb58 ldr r9, [r7] */
/* @0x18cb5c ldr r3, [r3, #0xc] */
/* @0x18cb60 add r9, r9, r6 */
/* @0x18cb64 str r0, [r10, #0x4] */
/* @0x18cb68 mov r0, r5 */
/* @0x18cb6c blx r3 */
/* @0x18cb70 mov r1, #0 */
/* @0x18cb74 mov r0, r4 */
/* @0x18cb78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18cb7c ldr r3, [r5] */
/* @0x18cb80 mov r2, r4 */
/* @0x18cb84 mov r1, #6 */
/* @0x18cb88 ldr r10, [r7] */
/* @0x18cb8c ldr r3, [r3, #0xc] */
/* @0x18cb90 add r10, r10, r6 */
/* @0x18cb94 str r0, [r9, #0x8] */
/* @0x18cb98 mov r0, r5 */
/* @0x18cb9c blx r3 */
/* @0x18cba0 mov r1, #0 */
/* @0x18cba4 mov r0, r4 */
/* @0x18cba8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18cbac ldr r3, [r5] */
/* @0x18cbb0 mov r2, r4 */
/* @0x18cbb4 mov r1, #6 */
/* @0x18cbb8 ldr r9, [r7] */
/* @0x18cbbc ldr r3, [r3, #0xc] */
/* @0x18cbc0 add r9, r9, r6 */
/* @0x18cbc4 str r0, [r10, #0xc] */
/* @0x18cbc8 mov r0, r5 */
/* @0x18cbcc blx r3 */
/* @0x18cbd0 mov r1, #0 */
/* @0x18cbd4 mov r0, r4 */
/* @0x18cbd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18cbdc ldr r3, [r5] */
/* @0x18cbe0 mov r2, r4 */
/* @0x18cbe4 mov r1, #6 */
/* @0x18cbe8 ldr r10, [r7] */
/* @0x18cbec ldr r3, [r3, #0xc] */
/* @0x18cbf0 add r10, r10, r6 */
/* @0x18cbf4 str r0, [r9, #0x10] */
/* @0x18cbf8 mov r0, r5 */
/* @0x18cbfc blx r3 */
/* @0x18cc00 mov r1, #0 */
/* @0x18cc04 mov r0, r4 */
/* @0x18cc08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18cc0c ldr r3, [r5] */
/* @0x18cc10 mov r2, r4 */
/* @0x18cc14 mov r1, #6 */
/* @0x18cc18 ldr r9, [r7] */
/* @0x18cc1c ldr r3, [r3, #0xc] */
/* @0x18cc20 add r9, r9, r6 */
/* @0x18cc24 str r0, [r10, #0x14] */
/* @0x18cc28 mov r0, r5 */
/* @0x18cc2c blx r3 */
/* @0x18cc30 mov r1, #0 */
/* @0x18cc34 mov r0, r4 */
/* @0x18cc38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18cc3c ldr r3, [r5] */
/* @0x18cc40 mov r2, r4 */
/* @0x18cc44 mov r1, #6 */
/* @0x18cc48 ldr r10, [r7] */
/* @0x18cc4c ldr r3, [r3, #0xc] */
/* @0x18cc50 add r10, r10, r6 */
/* @0x18cc54 str r0, [r9, #0x18] */
/* @0x18cc58 mov r0, r5 */
/* @0x18cc5c blx r3 */
/* @0x18cc60 mov r1, #0 */
/* @0x18cc64 mov r0, r4 */
/* @0x18cc68 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18cc6c ldr r3, [r5] */
/* @0x18cc70 mov r2, r4 */
/* @0x18cc74 mov r1, #6 */
/* @0x18cc78 ldr r9, [r7] */
/* @0x18cc7c ldr r3, [r3, #0xc] */
/* @0x18cc80 add r9, r9, r6 */
/* @0x18cc84 str r0, [r10, #0x1c] */
/* @0x18cc88 mov r0, r5 */
/* @0x18cc8c blx r3 */
/* @0x18cc90 mov r1, #0 */
/* @0x18cc94 mov r0, r4 */
/* @0x18cc98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18cc9c ldr r3, [r5] */
/* @0x18cca0 mov r2, r4 */
/* @0x18cca4 mov r1, #6 */
/* @0x18cca8 ldr r10, [r7] */
/* @0x18ccac ldr r3, [r3, #0xc] */
/* @0x18ccb0 add r10, r10, r6 */
/* @0x18ccb4 str r0, [r9, #0x20] */
/* @0x18ccb8 mov r0, r5 */
/* @0x18ccbc blx r3 */
/* @0x18ccc0 mov r1, #0 */
/* @0x18ccc4 mov r0, r4 */
/* @0x18ccc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18cccc ldr r3, [r5] */
/* @0x18ccd0 mov r1, #6 */
/* @0x18ccd4 mov r2, r4 */
/* @0x18ccd8 ldr r9, [r7] */
/* @0x18ccdc ldr r3, [r3, #0xc] */
/* @0x18cce0 add r9, r9, r6 */
/* @0x18cce4 add r6, r6, #44 */
/* @0x18cce8 str r0, [r10, #0x24] */
/* @0x18ccec mov r0, r5 */
/* @0x18ccf0 blx r3 */
/* @0x18ccf4 mov r0, r4 */
/* @0x18ccf8 mov r1, #0 */
/* @0x18ccfc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x18cd00 ldr r3, [r11] */
/* @0x18cd04 cmp r3, r8 */
/* @0x18cd08 str r0, [r9, #0x28] */
/* @0x18cd0c bgt 0x18cac0 <_Z23VirtualKeys_DeSerialiseP7IBuffer+0x88> */
/* @0x18cd10 mov r0, #1 */
/* @0x18cd14 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x18cd18 strhteq r3, [r6], -r0 */
/* @0x18cd1c mlaeq r6, r8, r0, r3 */

/* ── FUNC 0x18cd20 · IO_Setup(IniFile*) · size=644 · insn=161 */
/* @0x18cd20 ldr r1, [pc, #0x240] */
/* @0x18cd24 mov r3, #0 */
/* @0x18cd28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18cd2c ldr r1, [pc, r1] */
/* @0x18cd30 ldr r6, [pc, #0x234] */
/* @0x18cd34 sub sp, sp, #156 */
/* @0x18cd38 ldr r12, [r1] */
/* @0x18cd3c mov r5, r0 */
/* @0x18cd40 add r6, pc, r6 */
/* @0x18cd44 ldr r2, [pc, #0x224] */
/* @0x18cd48 str r1, [sp, #0xc] */
/* @0x18cd4c add r2, pc, r2 */
/* @0x18cd50 mov r1, r6 */
/* @0x18cd54 str r12, [sp, #0x94] */
/* @0x18cd58 bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i> */
/* @0x18cd5c ldr r2, [pc, #0x210] */
/* @0x18cd60 mov r1, r6 */
/* @0x18cd64 mov r3, #0 */
/* @0x18cd68 ldr r4, [pc, #0x208] */
/* @0x18cd6c add r2, pc, r2 */
/* @0x18cd70 mov r7, r0 */
/* @0x18cd74 mov r0, r5 */
/* @0x18cd78 bl 0x235b78 <_ZN7IniFile10ReadStringEPKcS1_S1_> */
/* @0x18cd7c ldr r4, [pc, r4] */
/* @0x18cd80 mov r3, #0 */
/* @0x18cd84 str r3, [r4] */
/* @0x18cd88 subs r6, r0, #0 */
/* @0x18cd8c beq 0x18cdb4 <_Z8IO_SetupP7IniFile+0x94> */
/* @0x18cd90 bl 0xb6538 <strlen@plt> */
/* @0x18cd94 ldr r1, [pc, #0x1e0] */
/* @0x18cd98 movw r2, #0x44c */
/* @0x18cd9c mov r3, #1 */
/* @0x18cda0 add r1, pc, r1 */
/* @0x18cda4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18cda8 mov r1, r6 */
/* @0x18cdac str r0, [r4] */
/* @0x18cdb0 bl 0xb65a4 <strcpy@plt> */
/* @0x18cdb4 cmp r7, #0 */
/* @0x18cdb8 ble 0x18cf40 <_Z8IO_SetupP7IniFile+0x220> */
/* @0x18cdbc ldr r8, [pc, #0x1bc] */
/* @0x18cdc0 add r4, sp, #20 */
/* @0x18cdc4 ldr r11, [pc, #0x1b8] */
/* @0x18cdc8 mov r6, #0 */
/* @0x18cdcc ldr r10, [pc, #0x1b4] */
/* @0x18cdd0 add r8, pc, r8 */
/* @0x18cdd4 ldr r2, [pc, #0x1b0] */
/* @0x18cdd8 add r11, pc, r11 */
/* @0x18cddc ldr r3, [pc, #0x1ac] */
/* @0x18cde0 add r10, pc, r10 */
/* @0x18cde4 ldr r1, [pc, #0x1a8] */
/* @0x18cde8 add r2, pc, r2 */
/* @0x18cdec add r3, pc, r3 */
/* @0x18cdf0 str r2, [sp] */
/* @0x18cdf4 add r1, pc, r1 */
/* @0x18cdf8 str r3, [sp, #0x4] */
/* @0x18cdfc str r1, [sp, #0x8] */
/* @0x18ce00 mov r1, r8 */
/* @0x18ce04 mov r2, r6 */
/* @0x18ce08 mov r0, r4 */
/* @0x18ce0c bl 0xb6550 <sprintf@plt> */
/* @0x18ce10 bl 0x18c590 <_Z18AllocateVirtualKeyv> */
/* @0x18ce14 subs r9, r0, #0 */
/* @0x18ce18 beq 0x18cf34 <_Z8IO_SetupP7IniFile+0x214> */
/* @0x18ce1c mov r1, r4 */
/* @0x18ce20 mov r2, r11 */
/* @0x18ce24 mov r3, #0 */
/* @0x18ce28 mov r0, r5 */
/* @0x18ce2c bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i> */
/* @0x18ce30 mov r1, r4 */
/* @0x18ce34 mov r2, r10 */
/* @0x18ce38 mov r3, #0 */
/* @0x18ce3c str r0, [r9, #0x4] */
/* @0x18ce40 mov r0, r5 */
/* @0x18ce44 bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i> */
/* @0x18ce48 mov r1, r4 */
/* @0x18ce4c ldr r2, [sp] */
/* @0x18ce50 mov r3, #0 */
/* @0x18ce54 str r0, [r9, #0x8] */
/* @0x18ce58 mov r0, r5 */
/* @0x18ce5c bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i> */
/* @0x18ce60 mov r1, r4 */
/* @0x18ce64 ldr r2, [sp, #0x4] */
/* @0x18ce68 mov r3, #0 */
/* @0x18ce6c str r0, [r9, #0x14] */
/* @0x18ce70 mov r0, r5 */
/* @0x18ce74 bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i> */
/* @0x18ce78 mov r1, r4 */
/* @0x18ce7c ldr r2, [sp, #0x8] */
/* @0x18ce80 mov r3, #0 */
/* @0x18ce84 str r0, [r9, #0x18] */
/* @0x18ce88 mov r0, r5 */
/* @0x18ce8c bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i> */
/* @0x18ce90 ldr r2, [pc, #0x100] */
/* @0x18ce94 mov r1, r4 */
/* @0x18ce98 mov r3, #0 */
/* @0x18ce9c add r2, pc, r2 */
/* @0x18cea0 str r0, [r9, #0x1c] */
/* @0x18cea4 mov r0, r5 */
/* @0x18cea8 bl 0x235b1c <_ZN7IniFile7ReadIntEPKcS1_i> */
/* @0x18ceac ldr r1, [r9, #0x4] */
/* @0x18ceb0 ldr r3, [r9, #0x14] */
/* @0x18ceb4 mov r2, #0 */
/* @0x18ceb8 ldr lr, [r9, #0x8] */
/* @0x18cebc add r3, r1, r3 */
/* @0x18cec0 str r2, [r9, #0x24] */
/* @0x18cec4 ldr r1, [r9, #0x18] */
/* @0x18cec8 str r3, [r9, #0xc] */
/* @0x18cecc mov r3, r2 */
/* @0x18ced0 ldr r2, [pc, #0xc4] */
/* @0x18ced4 add r1, lr, r1 */
/* @0x18ced8 str r1, [r9, #0x10] */
/* @0x18cedc mov r1, r4 */
/* @0x18cee0 add r2, pc, r2 */
/* @0x18cee4 str r0, [r9, #0x20] */
/* @0x18cee8 mov r0, r5 */
/* @0x18ceec bl 0x235b78 <_ZN7IniFile10ReadStringEPKcS1_S1_> */
/* @0x18cef0 cmp r0, #0 */
/* @0x18cef4 beq 0x18cf00 <_Z8IO_SetupP7IniFile+0x1e0> */
/* @0x18cef8 bl 0x18c4a0 <_Z10ValueToKeyPKc> */
/* @0x18cefc str r0, [r9, #0x24] */
/* @0x18cf00 ldr r2, [pc, #0x98] */
/* @0x18cf04 mov r3, #0 */
/* @0x18cf08 mov r0, r5 */
/* @0x18cf0c str r3, [r9, #0x28] */
/* @0x18cf10 mov r1, r4 */
/* @0x18cf14 add r2, pc, r2 */
/* @0x18cf18 bl 0x235b78 <_ZN7IniFile10ReadStringEPKcS1_S1_> */
/* @0x18cf1c cmp r0, #0 */
/* @0x18cf20 beq 0x18cf2c <_Z8IO_SetupP7IniFile+0x20c> */
/* @0x18cf24 bl 0x18c53c <_Z13ValueToButtonPKc> */
/* @0x18cf28 str r0, [r9, #0x28] */
/* @0x18cf2c mov r3, #1 */
/* @0x18cf30 strh r3, [r9] */
/* @0x18cf34 add r6, r6, #1 */
/* @0x18cf38 cmp r6, r7 */
/* @0x18cf3c bne 0x18ce00 <_Z8IO_SetupP7IniFile+0xe0> */
/* @0x18cf40 mov r0, r5 */
/* @0x18cf44 bl 0x18f05c <_Z9IO_SetupMP7IniFile> */
/* @0x18cf48 ldr r1, [sp, #0xc] */
/* @0x18cf4c ldr r2, [sp, #0x94] */
/* @0x18cf50 ldr r3, [r1] */
/* @0x18cf54 cmp r2, r3 */
/* @0x18cf58 bne 0x18cf64 <_Z8IO_SetupP7IniFile+0x244> */
/* @0x18cf5c add sp, sp, #156 */
/* @0x18cf60 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x18cf64 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x18cf68 eoreq r0, r6, r4, lsr #24 */
/* @0x18cf6c andseq pc, r11, r12, lsr r5 */
/* @0x18cf70 andseq pc, r11, r4, asr #10 */
/* @0x18cf74 andseq pc, r11, r0, lsr r5 */
/* @0x18cf78 eoreq r3, r6, r8, lsr #17 */
/* @0x18cf7c andseq pc, r11, r12, lsr #9 */
/* @0x18cf80 ldrsbeq pc, [r11], -r4 */
/* @0x18cf84 ldrsbeq pc, [r11], -r12 */
/* @0x18cf88 ldrsbeq pc, [r11], -r8 */
/* @0x18cf8c ldrsbeq pc, [r11], -r4 */
/* @0x18cf90 ldrsbeq pc, [r11], -r4 */
/* @0x18cf94 ldrsbeq pc, [r11], -r0 */
/* @0x18cf98 andseq pc, r11, r12, lsr #8 */
/* @0x18cf9c andseq pc, r11, r12, ror #7 */
/* @0x18cfa0 ldrheq pc, [r11], -r12 */

/* ── FUNC 0x18cfa4 · ProcessVirtualKeys() · size=740 · insn=185 */
/* @0x18cfa4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18cfa8 sub sp, sp, #36 */
/* @0x18cfac ldr r4, [pc, #0x2a4] */
/* @0x18cfb0 ldr r3, [pc, #0x2a4] */
/* @0x18cfb4 add r4, pc, r4 */
/* @0x18cfb8 ldr r5, [r4, r3] */
/* @0x18cfbc ldr r3, [r5] */
/* @0x18cfc0 cmp r3, #0 */
/* @0x18cfc4 beq 0x18d250 <_Z18ProcessVirtualKeysv+0x2ac> */
/* @0x18cfc8 add r1, sp, #20 */
/* @0x18cfcc add r2, sp, #24 */
/* @0x18cfd0 add r3, sp, #28 */
/* @0x18cfd4 add r0, sp, #16 */
/* @0x18cfd8 bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_> */
/* @0x18cfdc ldr r2, [pc, #0x27c] */
/* @0x18cfe0 ldr r3, [pc, #0x27c] */
/* @0x18cfe4 mov r10, #0 */
/* @0x18cfe8 ldr r1, [r5] */
/* @0x18cfec mov r9, r10 */
/* @0x18cff0 ldr r12, [r4, r2] */
/* @0x18cff4 ldr r3, [r4, r3] */
/* @0x18cff8 ldr r2, [pc, #0x268] */
/* @0x18cffc add r8, r12, #2576 */
/* @0x18d000 add r8, r8, #4 */
/* @0x18d004 add r12, r12, #20 */
/* @0x18d008 ldr r3, [r3] */
/* @0x18d00c ldr r2, [r4, r2] */
/* @0x18d010 vldr s10, [r2] */
/* @0x18d014 vldr s11, [r2, #16] */
/* @0x18d018 vldr s12, [r2, #48] */
/* @0x18d01c vldr s7, [r2, #4] */
/* @0x18d020 vldr s8, [r2, #20] */
/* @0x18d024 vldr s9, [r2, #52] */
/* @0x18d028 b 0x18d038 <_Z18ProcessVirtualKeysv+0x94> */
/* @0x18d02c add r12, r12, #20 */
/* @0x18d030 cmp r12, r8 */
/* @0x18d034 beq 0x18d0f0 <_Z18ProcessVirtualKeysv+0x14c> */
/* @0x18d038 ldr r2, [r12, #-0x14] */
/* @0x18d03c cmp r2, #0 */
/* @0x18d040 bge 0x18d02c <_Z18ProcessVirtualKeysv+0x88> */
/* @0x18d044 cmp r3, #0 */
/* @0x18d048 ble 0x18d0e0 <_Z18ProcessVirtualKeysv+0x13c> */
/* @0x18d04c add r2, r1, #44 */
/* @0x18d050 mov r0, #0 */
/* @0x18d054 mov r5, #1 */
/* @0x18d058 ldrh r6, [r2, #-44] */
/* @0x18d05c add r0, r0, #1 */
/* @0x18d060 tst r6, #1 */
/* @0x18d064 beq 0x18d0d0 <_Z18ProcessVirtualKeysv+0x12c> */
/* @0x18d068 vldr s6, [r12, #-12] */
/* @0x18d06c vcvt.f32.s32 s13, s6 */
/* @0x18d070 vldr s6, [r12, #-16] */
/* @0x18d074 ldr r7, [r2, #-0x28] */
/* @0x18d078 vmul.f32 s15, s11, s13 */
/* @0x18d07c vcvt.f32.s32 s14, s6 */
/* @0x18d080 vmla.f32 s15, s10, s14 */
/* @0x18d084 vadd.f32 s15, s15, s12 */
/* @0x18d088 vcvt.s32.f32 s15, s15 */
/* @0x18d08c vmov r6, s15 */
/* @0x18d090 cmp r6, r7 */
/* @0x18d094 blt 0x18d0d0 <_Z18ProcessVirtualKeysv+0x12c> */
/* @0x18d098 ldr r7, [r2, #-0x20] */
/* @0x18d09c cmp r6, r7 */
/* @0x18d0a0 bge 0x18d0d0 <_Z18ProcessVirtualKeysv+0x12c> */
/* @0x18d0a4 vmul.f32 s13, s8, s13 */
/* @0x18d0a8 ldr r7, [r2, #-0x24] */
/* @0x18d0ac vmla.f32 s13, s7, s14 */
/* @0x18d0b0 vadd.f32 s13, s13, s9 */
/* @0x18d0b4 vcvt.s32.f32 s13, s13 */
/* @0x18d0b8 vmov r6, s13 */
/* @0x18d0bc cmp r6, r7 */
/* @0x18d0c0 blt 0x18d0d0 <_Z18ProcessVirtualKeysv+0x12c> */
/* @0x18d0c4 ldr r7, [r2, #-0x1c] */
/* @0x18d0c8 cmp r6, r7 */
/* @0x18d0cc orrlt r10, r10, r5 */
/* @0x18d0d0 cmp r0, r3 */
/* @0x18d0d4 lsl r5, r5, #1 */
/* @0x18d0d8 add r2, r2, #44 */
/* @0x18d0dc bne 0x18d058 <_Z18ProcessVirtualKeysv+0xb4> */
/* @0x18d0e0 str r9, [r12, #-0x14] */
/* @0x18d0e4 add r12, r12, #20 */
/* @0x18d0e8 cmp r12, r8 */
/* @0x18d0ec bne 0x18d038 <_Z18ProcessVirtualKeysv+0x94> */
/* @0x18d0f0 ldr r2, [pc, #0x174] */
/* @0x18d0f4 cmp r3, #0 */
/* @0x18d0f8 ldr r2, [r4, r2] */
/* @0x18d0fc str r2, [sp, #0xc] */
/* @0x18d100 ldr r2, [r2] */
/* @0x18d104 eor r2, r10, r2 */
/* @0x18d108 str r2, [sp, #0x4] */
/* @0x18d10c ble 0x18d248 <_Z18ProcessVirtualKeysv+0x2a4> */
/* @0x18d110 add r1, r1, #44 */
/* @0x18d114 mov r11, #0 */
/* @0x18d118 mov r2, #1 */
/* @0x18d11c str r10, [sp] */
/* @0x18d120 str r3, [sp, #0x8] */
/* @0x18d124 b 0x18d19c <_Z18ProcessVirtualKeysv+0x1f8> */
/* @0x18d128 adds r5, r0, #0 */
/* @0x18d12c ldr r10, [r4, r10] */
/* @0x18d130 movne r5, #1 */
/* @0x18d134 cmp r12, #0 */
/* @0x18d138 ldrb r6, [r10, r3] */
/* @0x18d13c moveq r12, #0 */
/* @0x18d140 movne r12, #1 */
/* @0x18d144 and r7, r12, r5 */
/* @0x18d148 orr r6, r7, r6 */
/* @0x18d14c strb r6, [r10, r3] */
/* @0x18d150 ldr r6, [r4, r9] */
/* @0x18d154 movne r5, #0 */
/* @0x18d158 andeq r5, r5, #1 */
/* @0x18d15c cmp r0, #0 */
/* @0x18d160 movne r0, #0 */
/* @0x18d164 andeq r0, r12, #1 */
/* @0x18d168 ldrb r12, [r6, r3] */
/* @0x18d16c orr r5, r5, r12 */
/* @0x18d170 strb r5, [r6, r3] */
/* @0x18d174 ldr r5, [r4, r8] */
/* @0x18d178 ldrb r12, [r5, r3] */
/* @0x18d17c orr r0, r0, r12 */
/* @0x18d180 strb r0, [r5, r3] */
/* @0x18d184 ldr r12, [sp, #0x8] */
/* @0x18d188 add r11, r11, #1 */
/* @0x18d18c lsl r2, r2, #1 */
/* @0x18d190 add r1, r1, #44 */
/* @0x18d194 cmp r11, r12 */
/* @0x18d198 beq 0x18d244 <_Z18ProcessVirtualKeysv+0x2a0> */
/* @0x18d19c ldrh r3, [r1, #-44] */
/* @0x18d1a0 ldr r5, [sp] */
/* @0x18d1a4 ldr r6, [sp, #0x4] */
/* @0x18d1a8 tst r3, #1 */
/* @0x18d1ac and r0, r2, r5 */
/* @0x18d1b0 and r12, r2, r6 */
/* @0x18d1b4 beq 0x18d184 <_Z18ProcessVirtualKeysv+0x1e0> */
/* @0x18d1b8 ldr r3, [r1, #-0x8] */
/* @0x18d1bc ldr r10, [pc, #0xac] */
/* @0x18d1c0 cmp r3, #0 */
/* @0x18d1c4 ldr r7, [pc, #0xa8] */
/* @0x18d1c8 ldr r9, [pc, #0xa8] */
/* @0x18d1cc ldr r6, [pc, #0xa8] */
/* @0x18d1d0 ldr r8, [pc, #0xa8] */
/* @0x18d1d4 ldr r5, [pc, #0xa8] */
/* @0x18d1d8 bne 0x18d128 <_Z18ProcessVirtualKeysv+0x184> */
/* @0x18d1dc ldr r3, [r1, #-0x4] */
/* @0x18d1e0 adds r8, r0, #0 */
/* @0x18d1e4 ldr r10, [r4, r7] */
/* @0x18d1e8 sub r3, r3, #1 */
/* @0x18d1ec movne r8, #1 */
/* @0x18d1f0 cmp r12, #0 */
/* @0x18d1f4 ldrb r7, [r10, r3] */
/* @0x18d1f8 moveq r12, #0 */
/* @0x18d1fc movne r12, #1 */
/* @0x18d200 and r9, r12, r8 */
/* @0x18d204 orr r7, r9, r7 */
/* @0x18d208 movne r8, #0 */
/* @0x18d20c andeq r8, r8, #1 */
/* @0x18d210 strb r7, [r10, r3] */
/* @0x18d214 cmp r0, #0 */
/* @0x18d218 movne r0, #0 */
/* @0x18d21c andeq r0, r12, #1 */
/* @0x18d220 ldr r12, [r4, r6] */
/* @0x18d224 ldrb r6, [r12, r3] */
/* @0x18d228 orr r8, r8, r6 */
/* @0x18d22c strb r8, [r12, r3] */
/* @0x18d230 ldr r12, [r4, r5] */
/* @0x18d234 ldrb r5, [r12, r3] */
/* @0x18d238 orr r0, r0, r5 */
/* @0x18d23c strb r0, [r12, r3] */
/* @0x18d240 b 0x18d184 <_Z18ProcessVirtualKeysv+0x1e0> */
/* @0x18d244 ldr r10, [sp] */
/* @0x18d248 ldr r0, [sp, #0xc] */
/* @0x18d24c str r10, [r0] */
/* @0x18d250 add sp, sp, #36 */
/* @0x18d254 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x18d258 mlaeq r6, r12, r12, r4 */
/* @0x18d25c .word 0xffffdf04 */
/* @0x18d260 .word 0xffffe9c4 */
/* @0x18d264 .word 0xffffdf00 */
/* @0x18d268 .word 0xffffdf50 */
/* @0x18d26c .word 0xffffe9d8 */
/* @0x18d270 .word 0xffffe998 */
/* @0x18d274 .word 0xffffe9ac */
/* @0x18d278 .word 0xffffe990 */
/* @0x18d27c .word 0xffffe9a4 */
/* @0x18d280 .word 0xffffe994 */
/* @0x18d284 .word 0xffffe9a8 */

/* ── FUNC 0x18d288 · IO_Update() · size=244 · insn=61 */
/* @0x18d288 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18d28c ldr r3, [pc, #0xd8] */
/* @0x18d290 ldr r3, [pc, r3] */
/* @0x18d294 ldrb r3, [r3] */
/* @0x18d298 cmp r3, #0 */
/* @0x18d29c beq 0x18d328 <_Z9IO_Updatev+0xa0> */
/* @0x18d2a0 ldr r9, [pc, #0xc8] */
/* @0x18d2a4 mov r5, #0 */
/* @0x18d2a8 ldr r6, [pc, #0xc4] */
/* @0x18d2ac mov r4, r5 */
/* @0x18d2b0 add r9, pc, r9 */
/* @0x18d2b4 ldr r6, [pc, r6] */
/* @0x18d2b8 add r7, r9, #3072 */
/* @0x18d2bc b 0x18d2d0 <_Z9IO_Updatev+0x48> */
/* @0x18d2c0 add r4, r4, #4 */
/* @0x18d2c4 add r5, r5, #8 */
/* @0x18d2c8 cmp r4, #40 */
/* @0x18d2cc beq 0x18d328 <_Z9IO_Updatev+0xa0> */
/* @0x18d2d0 ldr r3, [r6, r4] */
/* @0x18d2d4 add r2, r7, #4 */
/* @0x18d2d8 add r8, r6, r4 */
/* @0x18d2dc ldr r1, [r4, r2] */
/* @0x18d2e0 tst r3, #1 */
/* @0x18d2e4 str r3, [r4, r2] */
/* @0x18d2e8 eor r3, r1, r3 */
/* @0x18d2ec beq 0x18d2c0 <_Z9IO_Updatev+0x38> */
/* @0x18d2f0 tst r3, #1 */
/* @0x18d2f4 beq 0x18d2c0 <_Z9IO_Updatev+0x38> */
/* @0x18d2f8 bl 0x215148 <Timing_Time> */
/* @0x18d2fc add r12, r9, #3120 */
/* @0x18d300 ldr lr, [pc, #0x70] */
/* @0x18d304 ldrd r2, r3, [r5, r12] */
/* @0x18d308 cmp r0, r2 */
/* @0x18d30c sbcs r10, r1, r3 */
/* @0x18d310 bge 0x18d338 <_Z9IO_Updatev+0xb0> */
/* @0x18d314 strd r0, r1, [r5, r12] */
/* @0x18d318 add r4, r4, #4 */
/* @0x18d31c add r5, r5, #8 */
/* @0x18d320 cmp r4, #40 */
/* @0x18d324 bne 0x18d2d0 <_Z9IO_Updatev+0x48> */
/* @0x18d328 bl 0x18f094 <_Z10IO_UpdateMv> */
/* @0x18d32c bl 0x190ac0 <_Z14GamepadUpdateMv> */
/* @0x18d330 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18d334 b 0x18cfa4 <_Z18ProcessVirtualKeysv> */
/* @0x18d338 ldr lr, [pc, lr] */
/* @0x18d33c mov r10, r0 */
/* @0x18d340 mov r11, r1 */
/* @0x18d344 subs r10, r10, r2 */
/* @0x18d348 sbc r11, r11, r3 */
/* @0x18d34c ldrd r2, r3, [lr] */
/* @0x18d350 cmp r10, r2 */
/* @0x18d354 sbcs lr, r11, r3 */
/* @0x18d358 movlt r3, #-2147483646 */
/* @0x18d35c strlt r3, [r8] */
/* @0x18d360 blt 0x18d2c0 <_Z9IO_Updatev+0x38> */
/* @0x18d364 strd r0, r1, [r5, r12] */
/* @0x18d368 b 0x18d318 <_Z9IO_Updatev+0x90> */
/* @0x18d36c eoreq r1, r6, r12, asr #15 */
/* @0x18d370 eorseq r5, r10, r8, lsl sp */
/* @0x18d374 eoreq r3, r6, r8, ror r3 */
/* @0x18d378 .word 0x002632f8 */

/* ── FUNC 0x18d37c · IO_Start_Step() · size=268 · insn=67 */
/* @0x18d37c push {r4, lr} */
/* @0x18d380 mov r3, #0 */
/* @0x18d384 ldr r4, [pc, #0xd4] */
/* @0x18d388 mov r2, r3 */
/* @0x18d38c ldr r1, [pc, #0xd0] */
/* @0x18d390 add r4, pc, r4 */
/* @0x18d394 ldr r0, [pc, #0xcc] */
/* @0x18d398 ldr r12, [pc, #0xcc] */
/* @0x18d39c ldr r1, [r4, r1] */
/* @0x18d3a0 ldr lr, [r1] */
/* @0x18d3a4 add lr, lr, #1 */
/* @0x18d3a8 str lr, [r1] */
/* @0x18d3ac ldr r0, [r4, r0] */
/* @0x18d3b0 ldr r1, [r4, r12] */
/* @0x18d3b4 strb r2, [r0, r3] */
/* @0x18d3b8 strb r2, [r1, r3] */
/* @0x18d3bc add r3, r3, #1 */
/* @0x18d3c0 cmp r3, #256 */
/* @0x18d3c4 bne 0x18d3b4 <_Z13IO_Start_Stepv+0x38> */
/* @0x18d3c8 ldr r0, [pc, #0xa0] */
/* @0x18d3cc mov r2, #0 */
/* @0x18d3d0 ldr r1, [pc, #0x9c] */
/* @0x18d3d4 mov r3, r2 */
/* @0x18d3d8 ldr lr, [pc, #0x98] */
/* @0x18d3dc ldr r12, [pc, #0x98] */
/* @0x18d3e0 ldr r0, [r4, r0] */
/* @0x18d3e4 ldr r1, [r4, r1] */
/* @0x18d3e8 ldr lr, [r4, lr] */
/* @0x18d3ec ldr r12, [r4, r12] */
/* @0x18d3f0 strb r3, [lr, r2] */
/* @0x18d3f4 add r0, r0, #3 */
/* @0x18d3f8 strb r3, [r12, r2] */
/* @0x18d3fc add r2, r2, #1 */
/* @0x18d400 cmp r2, #10 */
/* @0x18d404 strb r3, [r0, #-0x3] */
/* @0x18d408 strb r3, [r1] */
/* @0x18d40c add r1, r1, #3 */
/* @0x18d410 strb r3, [r0, #-0x2] */
/* @0x18d414 strb r3, [r1, #-0x2] */
/* @0x18d418 strb r3, [r0, #-0x1] */
/* @0x18d41c strb r3, [r1, #-0x1] */
/* @0x18d420 bne 0x18d3f0 <_Z13IO_Start_Stepv+0x74> */
/* @0x18d424 ldr r3, [pc, #0x54] */
/* @0x18d428 ldr r3, [r4, r3] */
/* @0x18d42c ldrb r3, [r3] */
/* @0x18d430 cmp r3, #0 */
/* @0x18d434 beq 0x18d458 <_Z13IO_Start_Stepv+0xdc> */
/* @0x18d438 bl 0x18b8ec <_Z18IO_Playback_Updatev> */
/* @0x18d43c ldr r3, [pc, #0x40] */
/* @0x18d440 ldr r3, [r4, r3] */
/* @0x18d444 ldrb r3, [r3] */
/* @0x18d448 cmp r3, #0 */
/* @0x18d44c popeq {r4, pc} */
/* @0x18d450 pop {r4, lr} */
/* @0x18d454 b 0x18bb00 <_Z9IO_Recordv> */
/* @0x18d458 bl 0x18d288 <_Z9IO_Updatev> */
/* @0x18d45c b 0x18d43c <_Z13IO_Start_Stepv+0xc0> */
/* @0x18d460 eoreq r4, r6, r0, asr #17 */
/* @0x18d464 .word 0xffffe9e4 */
/* @0x18d468 .word 0xffffe998 */
/* @0x18d46c .word 0xffffe994 */
/* @0x18d470 .word 0xffffe9ac */
/* @0x18d474 .word 0xffffe9a8 */
/* @0x18d478 .word 0xffffe9b0 */
/* @0x18d47c .word 0xffffe9b4 */
/* @0x18d480 .word 0xffffe9cc */
/* @0x18d484 .word 0xffffe9c8 */

/* ── FUNC 0x18d488 · IO_Render() · size=652 · insn=163 */
/* @0x18d488 push {r4, r5, r6, r7, lr} */
/* @0x18d48c vpush {d8} */
/* @0x18d490 sub sp, sp, #20 */
/* @0x18d494 ldr r5, [pc, #0x25c] */
/* @0x18d498 ldr r2, [pc, #0x25c] */
/* @0x18d49c add r5, pc, r5 */
/* @0x18d4a0 ldr r3, [pc, #0x258] */
/* @0x18d4a4 ldr r7, [r5, r2] */
/* @0x18d4a8 ldr r6, [r5, r3] */
/* @0x18d4ac ldr r0, [r7] */
/* @0x18d4b0 ldr r2, [r6] */
/* @0x18d4b4 cmp r0, #0 */
/* @0x18d4b8 ble 0x18d6c0 <_Z9IO_Renderv+0x238> */
/* @0x18d4bc mov r3, #0 */
/* @0x18d4c0 add r2, r2, #44 */
/* @0x18d4c4 mov r4, r3 */
/* @0x18d4c8 ldrh r1, [r2, #-44] */
/* @0x18d4cc add r3, r3, #1 */
/* @0x18d4d0 cmp r3, r0 */
/* @0x18d4d4 add r2, r2, #44 */
/* @0x18d4d8 ubfx r1, r1, #0x1, #0x1 */
/* @0x18d4dc add r4, r4, r1 */
/* @0x18d4e0 bne 0x18d4c8 <_Z9IO_Renderv+0x40> */
/* @0x18d4e4 cmp r4, #0 */
/* @0x18d4e8 beq 0x18d6c0 <_Z9IO_Renderv+0x238> */
/* @0x18d4ec ldr r2, [pc, #0x210] */
/* @0x18d4f0 ldr r3, [pc, #0x210] */
/* @0x18d4f4 ldr r2, [r5, r2] */
/* @0x18d4f8 vldr s16, [r2] */
/* @0x18d4fc ldr r3, [r5, r3] */
/* @0x18d500 vldr s17, [r3] */
/* @0x18d504 vmov r3, s16 */
/* @0x18d508 cmn r3, #1 */
/* @0x18d50c beq 0x18d6dc <_Z9IO_Renderv+0x254> */
/* @0x18d510 vmov r3, s17 */
/* @0x18d514 cmn r3, #1 */
/* @0x18d518 beq 0x18d6cc <_Z9IO_Renderv+0x244> */
/* @0x18d51c bl 0x17b114 <_ZN12GraphicsPerf14BeginDebugDrawEv> */
/* @0x18d520 add r3, r4, r4, lsl #1 */
/* @0x18d524 mov r1, #0 */
/* @0x18d528 mov r2, #24 */
/* @0x18d52c lsl r3, r3, #1 */
/* @0x18d530 mov r0, #4 */
/* @0x18d534 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x18d538 add r2, sp, #8 */
/* @0x18d53c add r1, sp, #4 */
/* @0x18d540 add r3, sp, #12 */
/* @0x18d544 mov r4, r0 */
/* @0x18d548 mov r0, sp */
/* @0x18d54c bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_> */
/* @0x18d550 ldr r7, [r7] */
/* @0x18d554 ldr r2, [r6] */
/* @0x18d558 cmp r7, #0 */
/* @0x18d55c ble 0x18d6bc <_Z9IO_Renderv+0x234> */
/* @0x18d560 ldr r0, [pc, #0x1a4] */
/* @0x18d564 vldr s5, [sp] */
/* @0x18d568 ldr r3, [pc, #0x1a0] */
/* @0x18d56c vldr s6, [sp, #4] */
/* @0x18d570 add r2, r2, #44 */
/* @0x18d574 mov r12, #1056964608 */
/* @0x18d578 ldr r6, [r5, r0] */
/* @0x18d57c mov r1, #0 */
/* @0x18d580 ldr lr, [r5, r3] */
/* @0x18d584 mvn r0, #0 */
/* @0x18d588 mov r3, #0 */
/* @0x18d58c ldr r5, [r6] */
/* @0x18d590 vmov r6, s5 */
/* @0x18d594 ldr lr, [lr] */
/* @0x18d598 sub r6, r5, r6, lsl #1 */
/* @0x18d59c vmov r5, s6 */
/* @0x18d5a0 vmov s3, r6 */
/* @0x18d5a4 sub r5, lr, r5, lsl #1 */
/* @0x18d5a8 vmov s4, r5 */
/* @0x18d5ac ldrh lr, [r2, #-44] */
/* @0x18d5b0 add r1, r1, #1 */
/* @0x18d5b4 tst lr, #2 */
/* @0x18d5b8 beq 0x18d6b0 <_Z9IO_Renderv+0x228> */
/* @0x18d5bc vldr s7, [r2, #-40] */
/* @0x18d5c0 vldr s8, [r2, #-32] */
/* @0x18d5c4 vcvt.f32.s32 s14, s16 */
/* @0x18d5c8 vldr s9, [r2, #-36] */
/* @0x18d5cc vldr s10, [r2, #-28] */
/* @0x18d5d0 add r4, r4, #144 */
/* @0x18d5d4 str r3, [r4, #-0x80] */
/* @0x18d5d8 str r0, [r4, #-0x84] */
/* @0x18d5dc str r3, [r4, #-0x7c] */
/* @0x18d5e0 str r12, [r4, #-0x88] */
/* @0x18d5e4 str r0, [r4, #-0x6c] */
/* @0x18d5e8 vcvt.f32.s32 s7, s7 */
/* @0x18d5ec str r3, [r4, #-0x68] */
/* @0x18d5f0 str r3, [r4, #-0x64] */
/* @0x18d5f4 str r12, [r4, #-0x70] */
/* @0x18d5f8 str r0, [r4, #-0x54] */
/* @0x18d5fc str r3, [r4, #-0x50] */
/* @0x18d600 str r3, [r4, #-0x4c] */
/* @0x18d604 str r12, [r4, #-0x58] */
/* @0x18d608 vcvt.f32.s32 s8, s8 */
/* @0x18d60c str r0, [r4, #-0x3c] */
/* @0x18d610 str r3, [r4, #-0x38] */
/* @0x18d614 str r3, [r4, #-0x34] */
/* @0x18d618 str r12, [r4, #-0x40] */
/* @0x18d61c str r0, [r4, #-0x24] */
/* @0x18d620 str r3, [r4, #-0x20] */
/* @0x18d624 str r3, [r4, #-0x1c] */
/* @0x18d628 vcvt.f32.s32 s15, s17 */
/* @0x18d62c vcvt.f32.s32 s9, s9 */
/* @0x18d630 vcvt.f32.s32 s10, s10 */
/* @0x18d634 vdiv.f32 s7, s7, s14 */
/* @0x18d638 vdiv.f32 s8, s8, s14 */
/* @0x18d63c vdiv.f32 s9, s9, s15 */
/* @0x18d640 vdiv.f32 s10, s10, s15 */
/* @0x18d644 vcvt.f32.s32 s12, s5 */
/* @0x18d648 vcvt.f32.s32 s15, s3 */
/* @0x18d64c vcvt.f32.s32 s13, s6 */
/* @0x18d650 vmov.f32 s14, s12 */
/* @0x18d654 vcvt.f32.s32 s11, s4 */
/* @0x18d658 vmla.f32 s14, s15, s7 */
/* @0x18d65c vmla.f32 s12, s8, s15 */
/* @0x18d660 vstr s14, [r4, #-144] */
/* @0x18d664 vstr s14, [r4, #-48] */
/* @0x18d668 vmov.f32 s15, s13 */
/* @0x18d66c vstr s12, [r4, #-120] */
/* @0x18d670 vstr s12, [r4, #-96] */
/* @0x18d674 vstr s12, [r4, #-72] */
/* @0x18d678 vmla.f32 s15, s11, s9 */
/* @0x18d67c vmla.f32 s13, s10, s11 */
/* @0x18d680 vstr s15, [r4, #-140] */
/* @0x18d684 vstr s15, [r4, #-116] */
/* @0x18d688 vstr s13, [r4, #-92] */
/* @0x18d68c vstr s13, [r4, #-68] */
/* @0x18d690 vstr s13, [r4, #-44] */
/* @0x18d694 vstr s14, [r4, #-24] */
/* @0x18d698 vstr s15, [r4, #-20] */
/* @0x18d69c str r12, [r4, #-0x28] */
/* @0x18d6a0 str r0, [r4, #-0xc] */
/* @0x18d6a4 str r3, [r4, #-0x8] */
/* @0x18d6a8 str r3, [r4, #-0x4] */
/* @0x18d6ac str r12, [r4, #-0x10] */
/* @0x18d6b0 cmp r1, r7 */
/* @0x18d6b4 add r2, r2, #44 */
/* @0x18d6b8 bne 0x18d5ac <_Z9IO_Renderv+0x124> */
/* @0x18d6bc bl 0x17b3e4 <_ZN12GraphicsPerf12EndDebugDrawEv> */
/* @0x18d6c0 add sp, sp, #20 */
/* @0x18d6c4 vpop {d8} */
/* @0x18d6c8 pop {r4, r5, r6, r7, pc} */
/* @0x18d6cc ldr r3, [pc, #0x3c] */
/* @0x18d6d0 ldr r3, [r5, r3] */
/* @0x18d6d4 vldr s17, [r3] */
/* @0x18d6d8 b 0x18d51c <_Z9IO_Renderv+0x94> */
/* @0x18d6dc ldr r3, [pc, #0x28] */
/* @0x18d6e0 ldr r3, [r5, r3] */
/* @0x18d6e4 vldr s16, [r3] */
/* @0x18d6e8 vmov r3, s17 */
/* @0x18d6ec cmn r3, #1 */
/* @0x18d6f0 bne 0x18d51c <_Z9IO_Renderv+0x94> */
/* @0x18d6f4 b 0x18d6cc <_Z9IO_Renderv+0x244> */
/* @0x18d6f8 .word 0x002647b4 */
/* @0x18d6fc .word 0xffffdf00 */
/* @0x18d700 .word 0xffffdf04 */
/* @0x18d704 .word 0xffffdf18 */
/* @0x18d708 .word 0xffffdf24 */
/* @0x18d70c .word 0xffffe24c */
/* @0x18d710 .word 0xffffe250 */

/* ── FUNC 0x18d714 · PB_DSMap(HTTP_REQ_CONTEXT*, void*, int*) · size=16 · insn=4 */
/* @0x18d714 ldr r3, [r1] */
/* @0x18d718 str r3, [r2] */
/* @0x18d71c ldr r0, [r1, #0x4] */
/* @0x18d720 bx lr */

/* ── FUNC 0x18d724 · HTTP_REQ_CONTEXT::~HTTP_REQ_CONTEXT() · size=180 · insn=45 */
/* @0x18d724 ldr r3, [pc, #0xa4] */
/* @0x18d728 push {r4, r5, r6, r7, lr} */
/* @0x18d72c ldr r3, [pc, r3] */
/* @0x18d730 mov r4, r0 */
/* @0x18d734 add r3, r3, #8 */
/* @0x18d738 ldr r0, [r0, #0x34] */
/* @0x18d73c sub sp, sp, #12 */
/* @0x18d740 str r3, [r4] */
/* @0x18d744 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18d748 mov r3, #0 */
/* @0x18d74c ldr r0, [r4, #0x20] */
/* @0x18d750 str r3, [r4, #0x34] */
/* @0x18d754 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18d758 ldr r3, [r4, #0x2c] */
/* @0x18d75c cmn r3, #1 */
/* @0x18d760 beq 0x18d7bc <_ZN16HTTP_REQ_CONTEXTD2Ev+0x98> */
/* @0x18d764 add r7, sp, #4 */
/* @0x18d768 ldr r5, [pc, #0x64] */
/* @0x18d76c mov r0, r7 */
/* @0x18d770 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x18d774 ldr r5, [pc, r5] */
/* @0x18d778 ldr r2, [r4, #0x2c] */
/* @0x18d77c ldr r3, [r5, #0x4] */
/* @0x18d780 add r1, r3, r2, lsl #2 */
/* @0x18d784 ldr r6, [r3, r2, lsl #2] */
/* @0x18d788 cmp r6, #0 */
/* @0x18d78c beq 0x18d7ac <_ZN16HTTP_REQ_CONTEXTD2Ev+0x88> */
/* @0x18d790 mov r0, r6 */
/* @0x18d794 bl 0x20d9e8 <_ZN7CDS_MapD2Ev> */
/* @0x18d798 mov r0, r6 */
/* @0x18d79c bl 0x27d1d0 <_ZdlPv> */
/* @0x18d7a0 ldr r1, [r4, #0x2c] */
/* @0x18d7a4 ldr r3, [r5, #0x4] */
/* @0x18d7a8 add r1, r3, r1, lsl #2 */
/* @0x18d7ac mov r3, #0 */
/* @0x18d7b0 mov r0, r7 */
/* @0x18d7b4 str r3, [r1] */
/* @0x18d7b8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x18d7bc mov r3, #0 */
/* @0x18d7c0 mov r0, r4 */
/* @0x18d7c4 str r3, [r4, #0x20] */
/* @0x18d7c8 add sp, sp, #12 */
/* @0x18d7cc pop {r4, r5, r6, r7, pc} */
/* @0x18d7d0 eoreq r2, r6, r12, lsl #30 */
/* @0x18d7d4 eoreq r0, r6, r8, asr #3 */

/* ── FUNC 0x18d724 · HTTP_REQ_CONTEXT::~HTTP_REQ_CONTEXT() · alias of the symbol above · insn=0 */

/* ── FUNC 0x18d7d8 · HTTP_REQ_CONTEXT::~HTTP_REQ_CONTEXT() · size=28 · insn=7 */
/* @0x18d7d8 push {r4, lr} */
/* @0x18d7dc mov r4, r0 */
/* @0x18d7e0 bl 0x18d724 <_ZN16HTTP_REQ_CONTEXTD2Ev> */
/* @0x18d7e4 mov r0, r4 */
/* @0x18d7e8 bl 0x27d1d0 <_ZdlPv> */
/* @0x18d7ec mov r0, r4 */
/* @0x18d7f0 pop {r4, pc} */

/* ── FUNC 0x18d7f4 · PB_DSMapCleanup(HTTP_REQ_CONTEXT*) · size=64 · insn=16 */
/* @0x18d7f4 push {r3, r4, r5, lr} */
/* @0x18d7f8 mov r5, r0 */
/* @0x18d7fc ldr r4, [r0, #0x1c] */
/* @0x18d800 cmp r4, #0 */
/* @0x18d804 popeq {r3, r4, r5, pc} */
/* @0x18d808 ldr r0, [r4] */
/* @0x18d80c bl 0x205334 <_Z12DestroyDsMapi> */
/* @0x18d810 ldr r0, [r4, #0x8] */
/* @0x18d814 cmp r0, #0 */
/* @0x18d818 blt 0x18d820 <_Z15PB_DSMapCleanupP16HTTP_REQ_CONTEXT+0x2c> */
/* @0x18d81c bl 0xc6a88 <_Z11FreeIBufferi> */
/* @0x18d820 mov r0, r4 */
/* @0x18d824 bl 0x27d1d0 <_ZdlPv> */
/* @0x18d828 mov r3, #0 */
/* @0x18d82c str r3, [r5, #0x1c] */
/* @0x18d830 pop {r3, r4, r5, pc} */

/* ── FUNC 0x18d834 · HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool) · size=388 · insn=97 */
/* @0x18d834 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x18d838 sub sp, sp, #12 */
/* @0x18d83c ldr r7, [pc, #0x15c] */
/* @0x18d840 add r6, sp, #4 */
/* @0x18d844 ldr lr, [pc, #0x158] */
/* @0x18d848 mov r10, r3 */
/* @0x18d84c add r7, pc, r7 */
/* @0x18d850 mov r4, r0 */
/* @0x18d854 mov r0, r6 */
/* @0x18d858 mov r5, r2 */
/* @0x18d85c ldr r3, [r7, lr] */
/* @0x18d860 mov r9, r1 */
/* @0x18d864 ldr r8, [sp, #0x30] */
/* @0x18d868 add r3, r3, #8 */
/* @0x18d86c str r3, [r4] */
/* @0x18d870 ldrb r11, [sp, #0x38] */
/* @0x18d874 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x18d878 cmp r5, #0 */
/* @0x18d87c mov r3, #0 */
/* @0x18d880 str r3, [r4, #0x30] */
/* @0x18d884 str r3, [r4, #0x34] */
/* @0x18d888 ble 0x18d8b4 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b+0x80> */
/* @0x18d88c ldr r1, [pc, #0x114] */
/* @0x18d890 mov r2, #46 */
/* @0x18d894 mov r0, r5 */
/* @0x18d898 mov r3, #1 */
/* @0x18d89c add r1, pc, r1 */
/* @0x18d8a0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18d8a4 mov r1, #255 */
/* @0x18d8a8 mov r2, r5 */
/* @0x18d8ac str r0, [r4, #0x34] */
/* @0x18d8b0 bl 0xb65b0 <memset@plt> */
/* @0x18d8b4 mov r3, #0 */
/* @0x18d8b8 str r3, [r4, #0x3c] */
/* @0x18d8bc mov r3, #1 */
/* @0x18d8c0 str r3, [r4, #0xc] */
/* @0x18d8c4 strb r3, [r4, #0x8] */
/* @0x18d8c8 mvn r2, #0 */
/* @0x18d8cc ldr r3, [pc, #0xd8] */
/* @0x18d8d0 cmp r11, #0 */
/* @0x18d8d4 str r2, [r4, #0x40] */
/* @0x18d8d8 str r5, [r4, #0x38] */
/* @0x18d8dc ldr r3, [r7, r3] */
/* @0x18d8e0 ldr r2, [r3] */
/* @0x18d8e4 beq 0x18d8f0 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b+0xbc> */
/* @0x18d8e8 cmp r2, #0 */
/* @0x18d8ec bne 0x18d988 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b+0x154> */
/* @0x18d8f0 str r2, [r4, #0x4] */
/* @0x18d8f4 str r4, [r3] */
/* @0x18d8f8 ldr r2, [sp, #0x34] */
/* @0x18d8fc mov r3, #0 */
/* @0x18d900 str r10, [r4, #0x10] */
/* @0x18d904 mov r0, r9 */
/* @0x18d908 str r3, [r4, #0x18] */
/* @0x18d90c str r2, [r4, #0x1c] */
/* @0x18d910 str r8, [r4, #0x14] */
/* @0x18d914 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18d918 ldr r2, [pc, #0x90] */
/* @0x18d91c mvn r3, #0 */
/* @0x18d920 str r3, [r4, #0x2c] */
/* @0x18d924 mov r3, #200 */
/* @0x18d928 str r0, [r4, #0x20] */
/* @0x18d92c mov r0, #4 */
/* @0x18d930 ldr r2, [r7, r2] */
/* @0x18d934 str r3, [r4, #0x28] */
/* @0x18d938 ldr r3, [r2] */
/* @0x18d93c add r1, r3, #1 */
/* @0x18d940 str r1, [r2] */
/* @0x18d944 str r3, [r4, #0x24] */
/* @0x18d948 bl 0x27c524 <_Znwj> */
/* @0x18d94c mov r5, r0 */
/* @0x18d950 bl 0x203624 <_ZN7CDS_MapC2Ev> */
/* @0x18d954 bl 0x100014 <_Z18FindFreeDsMapIndexv> */
/* @0x18d958 ldr r2, [pc, #0x54] */
/* @0x18d95c mov r3, r0 */
/* @0x18d960 str r3, [r4, #0x2c] */
/* @0x18d964 ldr r2, [r7, r2] */
/* @0x18d968 mov r0, r6 */
/* @0x18d96c ldr r2, [r2, #0x4] */
/* @0x18d970 str r5, [r2, r3, lsl #2] */
/* @0x18d974 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x18d978 mov r0, r4 */
/* @0x18d97c add sp, sp, #12 */
/* @0x18d980 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x18d984 mov r2, r3 */
/* @0x18d988 ldr r3, [r2, #0x4] */
/* @0x18d98c cmp r3, #0 */
/* @0x18d990 bne 0x18d984 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b+0x150> */
/* @0x18d994 str r4, [r2, #0x4] */
/* @0x18d998 str r3, [r4, #0x4] */
/* @0x18d99c b 0x18d8f8 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b+0xc4> */
/* @0x18d9a0 eoreq r4, r6, r4, lsl #8 */
/* @0x18d9a4 .word 0xffffe9e8 */
/* @0x18d9a8 andseq lr, r11, r12, lsr r10 */
/* @0x18d9ac .word 0xffffc1a8 */
/* @0x18d9b0 .word 0xffffd628 */
/* @0x18d9b4 .word 0xffffbcec */

/* ── FUNC 0x18d834 · HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool) · alias of the symbol above · insn=0 */

/* ── FUNC 0x18d9b8 · CreateCompletedHTTPRequest(void*, void*) · size=76 · insn=19 */
/* @0x18d9b8 push {r4, r5, r6, lr} */
/* @0x18d9bc mov r5, r0 */
/* @0x18d9c0 sub sp, sp, #16 */
/* @0x18d9c4 mov r0, #68 */
/* @0x18d9c8 mov r6, r1 */
/* @0x18d9cc bl 0x27c524 <_Znwj> */
/* @0x18d9d0 mov r12, #0 */
/* @0x18d9d4 mov r3, r5 */
/* @0x18d9d8 str r6, [sp, #0x4] */
/* @0x18d9dc mov r1, r12 */
/* @0x18d9e0 str r12, [sp] */
/* @0x18d9e4 mov r2, r12 */
/* @0x18d9e8 str r12, [sp, #0x8] */
/* @0x18d9ec mov r4, r0 */
/* @0x18d9f0 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0x18d9f4 mov r3, #7 */
/* @0x18d9f8 str r3, [r4, #0xc] */
/* @0x18d9fc add sp, sp, #16 */
/* @0x18da00 pop {r4, r5, r6, pc} */

/* ── FUNC 0x18da04 · CreateAsynEventWithDSMap(int, int) · size=124 · insn=31 */
/* @0x18da04 push {r4, r5, r6, lr} */
/* @0x18da08 mov r5, r0 */
/* @0x18da0c sub sp, sp, #16 */
/* @0x18da10 mov r0, #12 */
/* @0x18da14 mov r6, r1 */
/* @0x18da18 bl 0x27c524 <_Znwj> */
/* @0x18da1c mvn r3, #0 */
/* @0x18da20 mov r4, r0 */
/* @0x18da24 mov r0, #68 */
/* @0x18da28 str r5, [r4] */
/* @0x18da2c str r3, [r4, #0x8] */
/* @0x18da30 str r6, [r4, #0x4] */
/* @0x18da34 bl 0x27c524 <_Znwj> */
/* @0x18da38 ldr r3, [pc, #0x38] */
/* @0x18da3c ldr r12, [pc, #0x38] */
/* @0x18da40 mov r1, #0 */
/* @0x18da44 mov lr, #1 */
/* @0x18da48 mov r2, r1 */
/* @0x18da4c ldr r12, [pc, r12] */
/* @0x18da50 ldr r3, [pc, r3] */
/* @0x18da54 str r4, [sp, #0x4] */
/* @0x18da58 str r12, [sp] */
/* @0x18da5c str lr, [sp, #0x8] */
/* @0x18da60 mov r5, r0 */
/* @0x18da64 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0x18da68 mov r3, #7 */
/* @0x18da6c str r3, [r5, #0xc] */
/* @0x18da70 add sp, sp, #16 */
/* @0x18da74 pop {r4, r5, r6, pc} */
/* @0x18da78 eoreq r2, r6, r12, ror #23 */
/* @0x18da7c .word 0x00262bf4 */

/* ── FUNC 0x18da80 · CreateAsynEventWithDSMapAndBuffer(int, int, int) · size=124 · insn=31 */
/* @0x18da80 push {r4, r5, r6, r7, lr} */
/* @0x18da84 mov r5, r0 */
/* @0x18da88 sub sp, sp, #20 */
/* @0x18da8c mov r0, #12 */
/* @0x18da90 mov r6, r1 */
/* @0x18da94 mov r7, r2 */
/* @0x18da98 bl 0x27c524 <_Znwj> */
/* @0x18da9c mov r4, r0 */
/* @0x18daa0 str r5, [r0] */
/* @0x18daa4 str r6, [r4, #0x8] */
/* @0x18daa8 mov r0, #68 */
/* @0x18daac str r7, [r4, #0x4] */
/* @0x18dab0 bl 0x27c524 <_Znwj> */
/* @0x18dab4 ldr r3, [pc, #0x38] */
/* @0x18dab8 ldr r12, [pc, #0x38] */
/* @0x18dabc mov r1, #0 */
/* @0x18dac0 mov lr, #1 */
/* @0x18dac4 mov r2, r1 */
/* @0x18dac8 ldr r12, [pc, r12] */
/* @0x18dacc ldr r3, [pc, r3] */
/* @0x18dad0 str r4, [sp, #0x4] */
/* @0x18dad4 str r12, [sp] */
/* @0x18dad8 str lr, [sp, #0x8] */
/* @0x18dadc mov r5, r0 */
/* @0x18dae0 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0x18dae4 mov r3, #7 */
/* @0x18dae8 str r3, [r5, #0xc] */
/* @0x18daec add sp, sp, #20 */
/* @0x18daf0 pop {r4, r5, r6, r7, pc} */
/* @0x18daf4 eoreq r2, r6, r0, ror r11 */
/* @0x18daf8 eoreq r2, r6, r8, ror r11 */

/* ── FUNC 0x18dafc · IsFilenameInWhiteList(YYWhitelistFilename*, char const*) · size=8 · insn=2 */
/* @0x18dafc mov r0, #0 */
/* @0x18db00 bx lr */

/* ── FUNC 0x18db04 · IsDirectoryInWhitelist(YYWhitelistFilename*, char const*) · size=8 · insn=2 */
/* @0x18db04 mov r0, #0 */
/* @0x18db08 bx lr */

/* ── FUNC 0x18db0c · AddToWhiteList(YYWhitelistFilename**, char const*, bool) · size=60 · insn=15 */
/* @0x18db0c push {r3, r4, r5, r6, r7, lr} */
/* @0x18db10 mov r5, r0 */
/* @0x18db14 mov r0, #12 */
/* @0x18db18 mov r6, r1 */
/* @0x18db1c mov r7, r2 */
/* @0x18db20 bl 0x27c524 <_Znwj> */
/* @0x18db24 mov r4, r0 */
/* @0x18db28 mov r0, r6 */
/* @0x18db2c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x18db30 strb r7, [r4, #0x8] */
/* @0x18db34 str r0, [r4, #0x4] */
/* @0x18db38 ldr r3, [r5] */
/* @0x18db3c str r3, [r4] */
/* @0x18db40 str r4, [r5] */
/* @0x18db44 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x18db48 · LoadSave::fopen(char const*, char const*) · size=624 · insn=156 */
/* @0x18db48 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x18db4c mov r4, r1 */
/* @0x18db50 sub sp, sp, #8 */
/* @0x18db54 mov r1, #116 */
/* @0x18db58 mov r6, r0 */
/* @0x18db5c mov r0, r4 */
/* @0x18db60 bl 0xb6634 <strchr@plt> */
/* @0x18db64 mov r1, #114 */
/* @0x18db68 adds r7, r0, #0 */
/* @0x18db6c mov r0, r4 */
/* @0x18db70 movne r7, #1 */
/* @0x18db74 bl 0xb6634 <strchr@plt> */
/* @0x18db78 mov r1, #119 */
/* @0x18db7c mov r8, r0 */
/* @0x18db80 mov r0, r4 */
/* @0x18db84 bl 0xb6634 <strchr@plt> */
/* @0x18db88 mov r1, #97 */
/* @0x18db8c mov r9, r0 */
/* @0x18db90 mov r0, r4 */
/* @0x18db94 bl 0xb6634 <strchr@plt> */
/* @0x18db98 cmp r0, #0 */
/* @0x18db9c movne r5, #1 */
/* @0x18dba0 movne r9, r5 */
/* @0x18dba4 movne r8, r5 */
/* @0x18dba8 beq 0x18dd24 <_ZN8LoadSave5fopenEPKcS1_+0x1dc> */
/* @0x18dbac mov r0, r4 */
/* @0x18dbb0 mov r1, #43 */
/* @0x18dbb4 bl 0xb6634 <strchr@plt> */
/* @0x18dbb8 cmp r0, #0 */
/* @0x18dbbc beq 0x18dc08 <_ZN8LoadSave5fopenEPKcS1_+0xc0> */
/* @0x18dbc0 cmp r8, #0 */
/* @0x18dbc4 bne 0x18dc28 <_ZN8LoadSave5fopenEPKcS1_+0xe0> */
/* @0x18dbc8 mov r0, #16 */
/* @0x18dbcc bl 0x27c524 <_Znwj> */
/* @0x18dbd0 mov r4, r0 */
/* @0x18dbd4 mov r0, #64 */
/* @0x18dbd8 bl 0x27c524 <_Znwj> */
/* @0x18dbdc mov r2, #1 */
/* @0x18dbe0 mov r3, r2 */
/* @0x18dbe4 mov r1, #0 */
/* @0x18dbe8 mov r5, r0 */
/* @0x18dbec bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati> */
/* @0x18dbf0 ldr r3, [pc, #0x1b4] */
/* @0x18dbf4 ldr r3, [pc, r3] */
/* @0x18dbf8 add r3, r3, #8 */
/* @0x18dbfc str r3, [r5] */
/* @0x18dc00 str r5, [r4] */
/* @0x18dc04 b 0x18dccc <_ZN8LoadSave5fopenEPKcS1_+0x184> */
/* @0x18dc08 cmp r8, #0 */
/* @0x18dc0c bne 0x18dc2c <_ZN8LoadSave5fopenEPKcS1_+0xe4> */
/* @0x18dc10 cmp r9, #0 */
/* @0x18dc14 moveq r4, r9 */
/* @0x18dc18 bne 0x18dbc8 <_ZN8LoadSave5fopenEPKcS1_+0x80> */
/* @0x18dc1c mov r0, r4 */
/* @0x18dc20 add sp, sp, #8 */
/* @0x18dc24 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x18dc28 mov r9, #1 */
/* @0x18dc2c add r4, sp, #8 */
/* @0x18dc30 mov r3, #0 */
/* @0x18dc34 mov r0, r6 */
/* @0x18dc38 str r3, [r4, #-0x4]! */
/* @0x18dc3c mov r1, r4 */
/* @0x18dc40 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x18dc44 subs r10, r0, #0 */
/* @0x18dc48 beq 0x18dd94 <_ZN8LoadSave5fopenEPKcS1_+0x24c> */
/* @0x18dc4c mov r0, #16 */
/* @0x18dc50 bl 0x27c524 <_Znwj> */
/* @0x18dc54 mov r4, r0 */
/* @0x18dc58 mov r0, #64 */
/* @0x18dc5c bl 0x27c524 <_Znwj> */
/* @0x18dc60 mov r2, #1 */
/* @0x18dc64 mov r3, r2 */
/* @0x18dc68 ldr r1, [sp, #0x4] */
/* @0x18dc6c mov r8, r0 */
/* @0x18dc70 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati> */
/* @0x18dc74 ldr r3, [pc, #0x134] */
/* @0x18dc78 mov r1, r10 */
/* @0x18dc7c ldr r2, [sp, #0x4] */
/* @0x18dc80 ldr r3, [pc, r3] */
/* @0x18dc84 ldr r0, [r8, #0xc] */
/* @0x18dc88 add r3, r3, #8 */
/* @0x18dc8c str r3, [r8] */
/* @0x18dc90 str r8, [r4] */
/* @0x18dc94 bl 0xb65bc <memcpy@plt> */
/* @0x18dc98 cmp r7, #0 */
/* @0x18dc9c mov r1, #0 */
/* @0x18dca0 str r1, [r4, #0x8] */
/* @0x18dca4 beq 0x18dcb4 <_ZN8LoadSave5fopenEPKcS1_+0x16c> */
/* @0x18dca8 ldr r3, [sp, #0x4] */
/* @0x18dcac cmp r3, #2 */
/* @0x18dcb0 bgt 0x18dd58 <_ZN8LoadSave5fopenEPKcS1_+0x210> */
/* @0x18dcb4 mov r0, r10 */
/* @0x18dcb8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18dcbc cmp r9, #0 */
/* @0x18dcc0 beq 0x18dd10 <_ZN8LoadSave5fopenEPKcS1_+0x1c8> */
/* @0x18dcc4 cmp r5, #0 */
/* @0x18dcc8 bne 0x18dd3c <_ZN8LoadSave5fopenEPKcS1_+0x1f4> */
/* @0x18dccc mov r0, r6 */
/* @0x18dcd0 bl 0xb6538 <strlen@plt> */
/* @0x18dcd4 ldr r1, [pc, #0xd8] */
/* @0x18dcd8 mov r3, #1 */
/* @0x18dcdc mov r2, #344 */
/* @0x18dce0 add r1, pc, r1 */
/* @0x18dce4 add r0, r0, r3 */
/* @0x18dce8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18dcec mov r1, r6 */
/* @0x18dcf0 str r0, [r4, #0x8] */
/* @0x18dcf4 bl 0xb65a4 <strcpy@plt> */
/* @0x18dcf8 mov r3, #1 */
/* @0x18dcfc strb r3, [r4, #0xc] */
/* @0x18dd00 mov r0, r4 */
/* @0x18dd04 strb r7, [r4, #0x4] */
/* @0x18dd08 add sp, sp, #8 */
/* @0x18dd0c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x18dd10 cmp r4, #0 */
/* @0x18dd14 bne 0x18dd00 <_ZN8LoadSave5fopenEPKcS1_+0x1b8> */
/* @0x18dd18 mov r0, r4 */
/* @0x18dd1c add sp, sp, #8 */
/* @0x18dd20 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x18dd24 adds r8, r8, #0 */
/* @0x18dd28 mov r5, r0 */
/* @0x18dd2c movne r8, #1 */
/* @0x18dd30 adds r9, r9, #0 */
/* @0x18dd34 movne r9, #1 */
/* @0x18dd38 b 0x18dbac <_ZN8LoadSave5fopenEPKcS1_+0x64> */
/* @0x18dd3c ldr r0, [r4] */
/* @0x18dd40 mov r1, #2 */
/* @0x18dd44 mov r2, #0 */
/* @0x18dd48 ldr r3, [r0] */
/* @0x18dd4c ldr r3, [r3, #0x10] */
/* @0x18dd50 blx r3 */
/* @0x18dd54 b 0x18dccc <_ZN8LoadSave5fopenEPKcS1_+0x184> */
/* @0x18dd58 ldrb r3, [r10] */
/* @0x18dd5c cmp r3, #239 */
/* @0x18dd60 bne 0x18dcb4 <_ZN8LoadSave5fopenEPKcS1_+0x16c> */
/* @0x18dd64 ldrb r3, [r10, #0x1] */
/* @0x18dd68 cmp r3, #187 */
/* @0x18dd6c bne 0x18dcb4 <_ZN8LoadSave5fopenEPKcS1_+0x16c> */
/* @0x18dd70 ldrb r3, [r10, #0x2] */
/* @0x18dd74 cmp r3, #191 */
/* @0x18dd78 bne 0x18dcb4 <_ZN8LoadSave5fopenEPKcS1_+0x16c> */
/* @0x18dd7c ldr r0, [r4] */
/* @0x18dd80 mov r2, #3 */
/* @0x18dd84 ldr r3, [r0] */
/* @0x18dd88 ldr r3, [r3, #0x10] */
/* @0x18dd8c blx r3 */
/* @0x18dd90 b 0x18dcb4 <_ZN8LoadSave5fopenEPKcS1_+0x16c> */
/* @0x18dd94 mov r1, r4 */
/* @0x18dd98 mov r0, r6 */
/* @0x18dd9c bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0x18dda0 subs r10, r0, #0 */
/* @0x18dda4 beq 0x18dc10 <_ZN8LoadSave5fopenEPKcS1_+0xc8> */
/* @0x18dda8 b 0x18dc4c <_ZN8LoadSave5fopenEPKcS1_+0x104> */
/* @0x18ddac .word 0x0025fdbc */
/* @0x18ddb0 eoreq pc, r5, r0, lsr sp */
/* @0x18ddb4 ldrsheq lr, [r11], -r8 */

/* ── FUNC 0x18ddb8 · LoadSave::fclose(_YYFILE*) · size=108 · insn=27 */
/* @0x18ddb8 ldrb r3, [r0, #0xc] */
/* @0x18ddbc push {r4, lr} */
/* @0x18ddc0 cmp r3, #0 */
/* @0x18ddc4 mov r4, r0 */
/* @0x18ddc8 beq 0x18ddf0 <_ZN8LoadSave6fcloseEP7_YYFILE+0x38> */
/* @0x18ddcc ldr r1, [r0, #0x8] */
/* @0x18ddd0 cmp r1, #0 */
/* @0x18ddd4 beq 0x18de00 <_ZN8LoadSave6fcloseEP7_YYFILE+0x48> */
/* @0x18ddd8 ldr r0, [r0] */
/* @0x18dddc mov r2, #0 */
/* @0x18dde0 ldr r12, [r0] */
/* @0x18dde4 ldr r3, [r0, #0x20] */
/* @0x18dde8 ldr r12, [r12, #0x1c] */
/* @0x18ddec blx r12 */
/* @0x18ddf0 ldr r0, [r4, #0x8] */
/* @0x18ddf4 cmp r0, #0 */
/* @0x18ddf8 beq 0x18de00 <_ZN8LoadSave6fcloseEP7_YYFILE+0x48> */
/* @0x18ddfc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x18de00 ldr r0, [r4] */
/* @0x18de04 cmp r0, #0 */
/* @0x18de08 beq 0x18de18 <_ZN8LoadSave6fcloseEP7_YYFILE+0x60> */
/* @0x18de0c ldr r3, [r0] */
/* @0x18de10 ldr r3, [r3, #0x4] */
/* @0x18de14 blx r3 */
/* @0x18de18 mov r0, r4 */
/* @0x18de1c pop {r4, lr} */
/* @0x18de20 b 0x27d1d0 <_ZdlPv> */

/* ── FUNC 0x18de24 · LoadSave::ftell(_YYFILE*) · size=12 · insn=3 */
/* @0x18de24 ldr r3, [r0] */
/* @0x18de28 ldr r0, [r3, #0x1c] */
/* @0x18de2c bx lr */
