/* libyoyo.so 覆盖卡组 0195
 * 函数 0x21c254..0x21db54，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x21c254 · GetRecorderFromDevice(int) · size=140 · insn=35 */
/* @0x21c254 ldr r3, [pc, #0x7c] */
/* @0x21c258 push {r4, r5, r6, r7, r8, lr} */
/* @0x21c25c ldr r3, [pc, r3] */
/* @0x21c260 ldr r2, [r3] */
/* @0x21c264 cmp r0, r2 */
/* @0x21c268 bge 0x21c2cc <_Z21GetRecorderFromDevicei+0x78> */
/* @0x21c26c ldr r3, [r3, #0x4] */
/* @0x21c270 ldr r8, [r3, r0, lsl #2] */
/* @0x21c274 cmp r8, #0 */
/* @0x21c278 moveq r5, r8 */
/* @0x21c27c beq 0x21c2d0 <_Z21GetRecorderFromDevicei+0x7c> */
/* @0x21c280 ldr r3, [pc, #0x54] */
/* @0x21c284 add r3, pc, r3 */
/* @0x21c288 ldr r6, [r3, #0x50] */
/* @0x21c28c cmp r6, #0 */
/* @0x21c290 ble 0x21c2cc <_Z21GetRecorderFromDevicei+0x78> */
/* @0x21c294 ldr r7, [r3, #0x54] */
/* @0x21c298 mov r4, #0 */
/* @0x21c29c sub r7, r7, #4 */
/* @0x21c2a0 ldr r5, [r7, #0x4]! */
/* @0x21c2a4 add r4, r4, #1 */
/* @0x21c2a8 cmp r5, #0 */
/* @0x21c2ac beq 0x21c2c4 <_Z21GetRecorderFromDevicei+0x70> */
/* @0x21c2b0 ldr r0, [r8] */
/* @0x21c2b4 ldr r1, [r5, #0x8] */
/* @0x21c2b8 bl 0xb6574 <strcmp@plt> */
/* @0x21c2bc cmp r0, #0 */
/* @0x21c2c0 beq 0x21c2d0 <_Z21GetRecorderFromDevicei+0x7c> */
/* @0x21c2c4 cmp r4, r6 */
/* @0x21c2c8 bne 0x21c2a0 <_Z21GetRecorderFromDevicei+0x4c> */
/* @0x21c2cc mov r5, #0 */
/* @0x21c2d0 mov r0, r5 */
/* @0x21c2d4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x21c2d8 mulseq sp, r12, r1 */
/* @0x21c2dc subseq r9, r3, r0, lsl r0 */

/* ── FUNC 0x21c2e0 · deviceListAdd(char const*) · size=400 · insn=100 */
/* @0x21c2e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21c2e4 mov r7, r0 */
/* @0x21c2e8 sub sp, sp, #20 */
/* @0x21c2ec mov r0, #4 */
/* @0x21c2f0 bl 0x27c524 <_Znwj> */
/* @0x21c2f4 mov r4, #0 */
/* @0x21c2f8 mov r6, r0 */
/* @0x21c2fc mov r0, r7 */
/* @0x21c300 str r4, [r6] */
/* @0x21c304 bl 0xb6538 <strlen@plt> */
/* @0x21c308 ldr r1, [pc, #0x154] */
/* @0x21c30c mov r3, #1 */
/* @0x21c310 movw r2, #0xd07 */
/* @0x21c314 add r1, pc, r1 */
/* @0x21c318 add r0, r0, r3 */
/* @0x21c31c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x21c320 subs r8, r0, #0 */
/* @0x21c324 beq 0x21c3f0 <_Z13deviceListAddPKc+0x110> */
/* @0x21c328 ldr r5, [pc, #0x138] */
/* @0x21c32c ldr r5, [pc, r5] */
/* @0x21c330 ldr r9, [r5] */
/* @0x21c334 adds r2, r9, #1 */
/* @0x21c338 str r2, [sp, #0xc] */
/* @0x21c33c bne 0x21c414 <_Z13deviceListAddPKc+0x134> */
/* @0x21c340 ldr r0, [r5, #0x4] */
/* @0x21c344 cmp r0, r4 */
/* @0x21c348 beq 0x21c3dc <_Z13deviceListAddPKc+0xfc> */
/* @0x21c34c cmp r9, r4 */
/* @0x21c350 ble 0x21c3dc <_Z13deviceListAddPKc+0xfc> */
/* @0x21c354 mov r4, r2 */
/* @0x21c358 mov r10, r2 */
/* @0x21c35c ldr r3, [r0] */
/* @0x21c360 movw r2, #0xfeee */
/* @0x21c364 movt r2, #0xfeee */
/* @0x21c368 movw r1, #0xfeee */
/* @0x21c36c cmp r3, r2 */
/* @0x21c370 movt r1, #0xfeee */
/* @0x21c374 lsl r11, r4, #2 */
/* @0x21c378 beq 0x21c3cc <_Z13deviceListAddPKc+0xec> */
/* @0x21c37c ldr r2, [r0, r4, lsl #2] */
/* @0x21c380 add lr, r0, r11 */
/* @0x21c384 cmp r2, #0 */
/* @0x21c388 beq 0x21c3cc <_Z13deviceListAddPKc+0xec> */
/* @0x21c38c ldr r3, [r2] */
/* @0x21c390 cmp r3, r1 */
/* @0x21c394 mov r0, r3 */
/* @0x21c398 beq 0x21c3c4 <_Z13deviceListAddPKc+0xe4> */
/* @0x21c39c cmp r3, #0 */
/* @0x21c3a0 beq 0x21c3b4 <_Z13deviceListAddPKc+0xd4> */
/* @0x21c3a4 str r2, [sp, #0x8] */
/* @0x21c3a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21c3ac ldr r2, [sp, #0x8] */
/* @0x21c3b0 str r10, [r2] */
/* @0x21c3b4 mov r0, r2 */
/* @0x21c3b8 bl 0x27d1d0 <_ZdlPv> */
/* @0x21c3bc ldr lr, [r5, #0x4] */
/* @0x21c3c0 add lr, lr, r11 */
/* @0x21c3c4 str r10, [lr] */
/* @0x21c3c8 ldr r0, [r5, #0x4] */
/* @0x21c3cc ldr r2, [r5] */
/* @0x21c3d0 add r4, r4, #1 */
/* @0x21c3d4 cmp r4, r2 */
/* @0x21c3d8 blt 0x21c35c <_Z13deviceListAddPKc+0x7c> */
/* @0x21c3dc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21c3e0 mov r2, #0 */
/* @0x21c3e4 mov r3, r2 */
/* @0x21c3e8 str r2, [r5, #0x4] */
/* @0x21c3ec b 0x21c440 <_Z13deviceListAddPKc+0x160> */
/* @0x21c3f0 ldr r0, [r6] */
/* @0x21c3f4 cmp r0, #0 */
/* @0x21c3f8 beq 0x21c404 <_Z13deviceListAddPKc+0x124> */
/* @0x21c3fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21c400 str r8, [r6] */
/* @0x21c404 mov r0, r6 */
/* @0x21c408 add sp, sp, #20 */
/* @0x21c40c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21c410 b 0x27d1d0 <_ZdlPv> */
/* @0x21c414 ldr r3, [sp, #0xc] */
/* @0x21c418 ldr r0, [r5, #0x4] */
/* @0x21c41c lsls r1, r3, #2 */
/* @0x21c420 beq 0x21c3dc <_Z13deviceListAddPKc+0xfc> */
/* @0x21c424 ldr r2, [pc, #0x40] */
/* @0x21c428 mov r3, #135 */
/* @0x21c42c str r4, [sp] */
/* @0x21c430 add r2, pc, r2 */
/* @0x21c434 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21c438 mov r3, r0 */
/* @0x21c43c str r0, [r5, #0x4] */
/* @0x21c440 ldr r2, [sp, #0xc] */
/* @0x21c444 mov r1, r7 */
/* @0x21c448 mov r0, r8 */
/* @0x21c44c str r2, [r5] */
/* @0x21c450 str r6, [r3, r9, lsl #2] */
/* @0x21c454 bl 0xb65a4 <strcpy@plt> */
/* @0x21c458 str r8, [r6] */
/* @0x21c45c add sp, sp, #20 */
/* @0x21c460 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21c464 andseq r7, r3, r4, lsl #21 */
/* @0x21c468 andseq r5, sp, r12, asr #1 */
/* @0x21c46c andseq r0, r3, r0, asr #29 */

/* ── FUNC 0x21c470 · deviceListClear() · size=220 · insn=55 */
/* @0x21c470 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x21c474 ldr r7, [pc, #0xcc] */
/* @0x21c478 ldr r7, [pc, r7] */
/* @0x21c47c ldr r3, [r7] */
/* @0x21c480 cmp r3, #0 */
/* @0x21c484 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21c488 ldr r5, [r7, #0x4] */
/* @0x21c48c cmp r5, #0 */
/* @0x21c490 beq 0x21c538 <_Z15deviceListClearv+0xc8> */
/* @0x21c494 cmp r3, #0 */
/* @0x21c498 ble 0x21c51c <_Z15deviceListClearv+0xac> */
/* @0x21c49c mov r4, #0 */
/* @0x21c4a0 mov r8, r4 */
/* @0x21c4a4 ldr r1, [r5] */
/* @0x21c4a8 movw r3, #0xfeee */
/* @0x21c4ac movt r3, #0xfeee */
/* @0x21c4b0 movw r2, #0xfeee */
/* @0x21c4b4 cmp r1, r3 */
/* @0x21c4b8 movt r2, #0xfeee */
/* @0x21c4bc lsl r9, r4, #2 */
/* @0x21c4c0 beq 0x21c50c <_Z15deviceListClearv+0x9c> */
/* @0x21c4c4 ldr r6, [r5, r4, lsl #2] */
/* @0x21c4c8 add r1, r5, r9 */
/* @0x21c4cc cmp r6, #0 */
/* @0x21c4d0 beq 0x21c50c <_Z15deviceListClearv+0x9c> */
/* @0x21c4d4 ldr r3, [r6] */
/* @0x21c4d8 cmp r3, r2 */
/* @0x21c4dc mov r0, r3 */
/* @0x21c4e0 beq 0x21c504 <_Z15deviceListClearv+0x94> */
/* @0x21c4e4 cmp r3, #0 */
/* @0x21c4e8 beq 0x21c4f4 <_Z15deviceListClearv+0x84> */
/* @0x21c4ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21c4f0 str r8, [r6] */
/* @0x21c4f4 mov r0, r6 */
/* @0x21c4f8 bl 0x27d1d0 <_ZdlPv> */
/* @0x21c4fc ldr r1, [r7, #0x4] */
/* @0x21c500 add r1, r1, r9 */
/* @0x21c504 str r8, [r1] */
/* @0x21c508 ldr r5, [r7, #0x4] */
/* @0x21c50c ldr r3, [r7] */
/* @0x21c510 add r4, r4, #1 */
/* @0x21c514 cmp r4, r3 */
/* @0x21c518 blt 0x21c4a4 <_Z15deviceListClearv+0x34> */
/* @0x21c51c mov r0, r5 */
/* @0x21c520 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21c524 mov r3, #0 */
/* @0x21c528 str r3, [r7, #0x4] */
/* @0x21c52c mov r3, #0 */
/* @0x21c530 str r3, [r7] */
/* @0x21c534 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21c538 mov r0, r5 */
/* @0x21c53c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21c540 str r5, [r7, #0x4] */
/* @0x21c544 b 0x21c52c <_Z15deviceListClearv+0xbc> */
/* @0x21c548 andseq r4, sp, r0, lsl #31 */

/* ── FUNC 0x21c54c · enumerateCaptureDevices() · size=108 · insn=27 */
/* @0x21c54c push {r3, r4, r5, lr} */
/* @0x21c550 bl 0x21c470 <_Z15deviceListClearv> */
/* @0x21c554 mov r0, #0 */
/* @0x21c558 mov r1, #784 */
/* @0x21c55c bl 0xb6b50 <alcGetString@plt> */
/* @0x21c560 subs r4, r0, #0 */
/* @0x21c564 beq 0x21c5b0 <_Z23enumerateCaptureDevicesv+0x64> */
/* @0x21c568 ldrb r5, [r4] */
/* @0x21c56c cmp r5, #0 */
/* @0x21c570 beq 0x21c5a8 <_Z23enumerateCaptureDevicesv+0x5c> */
/* @0x21c574 mov r5, #0 */
/* @0x21c578 b 0x21c588 <_Z23enumerateCaptureDevicesv+0x3c> */
/* @0x21c57c ldrb r3, [r4] */
/* @0x21c580 cmp r3, #0 */
/* @0x21c584 beq 0x21c5a8 <_Z23enumerateCaptureDevicesv+0x5c> */
/* @0x21c588 mov r0, r4 */
/* @0x21c58c add r5, r5, #1 */
/* @0x21c590 bl 0x21c2e0 <_Z13deviceListAddPKc> */
/* @0x21c594 mov r0, r4 */
/* @0x21c598 bl 0xb6538 <strlen@plt> */
/* @0x21c59c add r0, r0, #1 */
/* @0x21c5a0 adds r4, r4, r0 */
/* @0x21c5a4 bne 0x21c57c <_Z23enumerateCaptureDevicesv+0x30> */
/* @0x21c5a8 mov r0, r5 */
/* @0x21c5ac pop {r3, r4, r5, pc} */
/* @0x21c5b0 mov r5, r4 */
/* @0x21c5b4 b 0x21c5a8 <_Z23enumerateCaptureDevicesv+0x5c> */

/* ── FUNC 0x21c5b8 · Audio_GetRecorderCount() · size=4 · insn=1 */
/* @0x21c5b8 b 0x21c54c <_Z23enumerateCaptureDevicesv> */

/* ── FUNC 0x21c5bc · Audio_GetRecorderInfo(int) · size=324 · insn=81 */
/* @0x21c5bc subs r12, r0, #0 */
/* @0x21c5c0 ldr r3, [pc, #0x110] */
/* @0x21c5c4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x21c5c8 add r3, pc, r3 */
/* @0x21c5cc sub sp, sp, #72 */
/* @0x21c5d0 blt 0x21c6c4 <_Z21Audio_GetRecorderInfoi+0x108> */
/* @0x21c5d4 ldr r2, [pc, #0x100] */
/* @0x21c5d8 ldr r2, [r3, r2] */
/* @0x21c5dc ldr r1, [r2] */
/* @0x21c5e0 cmp r12, r1 */
/* @0x21c5e4 bgt 0x21c6c4 <_Z21Audio_GetRecorderInfoi+0x108> */
/* @0x21c5e8 bge 0x21c698 <_Z21Audio_GetRecorderInfoi+0xdc> */
/* @0x21c5ec ldr r2, [r2, #0x4] */
/* @0x21c5f0 ldr r2, [r2, r12, lsl #2] */
/* @0x21c5f4 cmp r2, #0 */
/* @0x21c5f8 beq 0x21c698 <_Z21Audio_GetRecorderInfoi+0xdc> */
/* @0x21c5fc vmov s13, r12 */
/* @0x21c600 ldr r10, [r2] */
/* @0x21c604 mov r1, #0 */
/* @0x21c608 ldr r0, [pc, #0xd0] */
/* @0x21c60c vcvt.f64.s32 d7, s13 */
/* @0x21c610 ldr r9, [pc, #0xcc] */
/* @0x21c614 ldr r8, [pc, #0xcc] */
/* @0x21c618 add r0, pc, r0 */
/* @0x21c61c ldr lr, [pc, #0xc8] */
/* @0x21c620 mov r4, #0 */
/* @0x21c624 str r1, [sp, #0x10] */
/* @0x21c628 mov r5, #0 */
/* @0x21c62c str r1, [sp, #0x20] */
/* @0x21c630 movt r5, #0x4010 */
/* @0x21c634 str r1, [sp, #0x30] */
/* @0x21c638 mov r2, #0 */
/* @0x21c63c str r1, [sp, #0x40] */
/* @0x21c640 mov r3, #0 */
/* @0x21c644 ldr r1, [pc, #0xa4] */
/* @0x21c648 add r9, pc, r9 */
/* @0x21c64c add r8, pc, r8 */
/* @0x21c650 add lr, pc, lr */
/* @0x21c654 mov r6, #0 */
/* @0x21c658 mov r7, #16384 */
/* @0x21c65c str r0, [sp, #0x4] */
/* @0x21c660 movt r7, #0x40cf */
/* @0x21c664 strd r2, r3, [sp, #56] */
/* @0x21c668 mov r0, #5 */
/* @0x21c66c str r10, [sp] */
/* @0x21c670 add r1, pc, r1 */
/* @0x21c674 strd r6, r7, [sp, #40] */
/* @0x21c678 vstr d7, [sp, #8] */
/* @0x21c67c str r9, [sp, #0x14] */
/* @0x21c680 str r8, [sp, #0x24] */
/* @0x21c684 str lr, [sp, #0x34] */
/* @0x21c688 strd r4, r5, [sp, #24] */
/* @0x21c68c bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x21c690 add sp, sp, #72 */
/* @0x21c694 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x21c698 ldr r1, [pc, #0x54] */
/* @0x21c69c mov r2, r12 */
/* @0x21c6a0 ldr r0, [pc, #0x50] */
/* @0x21c6a4 add r1, pc, r1 */
/* @0x21c6a8 ldr r3, [r3, r0] */
/* @0x21c6ac ldr r0, [r3] */
/* @0x21c6b0 ldr r3, [r0] */
/* @0x21c6b4 ldr r3, [r3, #0xc] */
/* @0x21c6b8 blx r3 */
/* @0x21c6bc mvn r0, #0 */
/* @0x21c6c0 b 0x21c690 <_Z21Audio_GetRecorderInfoi+0xd4> */
/* @0x21c6c4 ldr r1, [pc, #0x30] */
/* @0x21c6c8 mov r2, r12 */
/* @0x21c6cc ldr r0, [pc, #0x24] */
/* @0x21c6d0 add r1, pc, r1 */
/* @0x21c6d4 b 0x21c6a8 <_Z21Audio_GetRecorderInfoi+0xec> */
/* @0x21c6d8 andseq r5, sp, r8, lsl #13 */
/* @0x21c6dc .word 0xfffff7a8 */
/* @0x21c6e0 ldrsheq r9, [r2], -r0 */
/* @0x21c6e4 andseq r7, r3, r12, lsl r12 */
/* @0x21c6e8 andseq r7, r3, r4, lsr #24 */
/* @0x21c6ec andseq r7, r3, r12, lsr #24 */
/* @0x21c6f0 mulseq r1, r8, r1 */
/* @0x21c6f4 andseq r7, r3, r8, lsl #23 */
/* @0x21c6f8 .word 0xffffbac4 */
/* @0x21c6fc andseq r7, r3, r8, lsr #22 */

/* ── FUNC 0x21c700 · Audio_StartRecording(int) · size=1016 · insn=254 */
/* @0x21c700 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21c704 subs r5, r0, #0 */
/* @0x21c708 ldr r6, [pc, #0x394] */
/* @0x21c70c sub sp, sp, #20 */
/* @0x21c710 add r6, pc, r6 */
/* @0x21c714 blt 0x21ca30 <_Z20Audio_StartRecordingi+0x330> */
/* @0x21c718 ldr r3, [pc, #0x388] */
/* @0x21c71c ldr r3, [r6, r3] */
/* @0x21c720 ldr r2, [r3] */
/* @0x21c724 cmp r5, r2 */
/* @0x21c728 bgt 0x21ca30 <_Z20Audio_StartRecordingi+0x330> */
/* @0x21c72c bge 0x21c9c8 <_Z20Audio_StartRecordingi+0x2c8> */
/* @0x21c730 ldr r3, [r3, #0x4] */
/* @0x21c734 ldr r7, [r3, r5, lsl #2] */
/* @0x21c738 cmp r7, #0 */
/* @0x21c73c beq 0x21c9c8 <_Z20Audio_StartRecordingi+0x2c8> */
/* @0x21c740 bl 0x21c254 <_Z21GetRecorderFromDevicei> */
/* @0x21c744 subs r4, r0, #0 */
/* @0x21c748 beq 0x21c7c4 <_Z20Audio_StartRecordingi+0xc4> */
/* @0x21c74c ldrb r3, [r4, #0xc] */
/* @0x21c750 cmp r3, #0 */
/* @0x21c754 bne 0x21ca44 <_Z20Audio_StartRecordingi+0x344> */
/* @0x21c758 ldr r0, [r4, #0x10] */
/* @0x21c75c bl 0xb6b5c <alcCaptureStart@plt> */
/* @0x21c760 ldr r0, [pc, #0x344] */
/* @0x21c764 add r0, pc, r0 */
/* @0x21c768 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x21c76c ldr r2, [pc, #0x33c] */
/* @0x21c770 mov r3, #1 */
/* @0x21c774 strb r3, [r4, #0xc] */
/* @0x21c778 add r2, pc, r2 */
/* @0x21c77c ldr r3, [r2, #0x50] */
/* @0x21c780 cmp r3, #0 */
/* @0x21c784 ble 0x21c918 <_Z20Audio_StartRecordingi+0x218> */
/* @0x21c788 ldr r2, [r2, #0x54] */
/* @0x21c78c mov r0, #0 */
/* @0x21c790 ldr r1, [r2] */
/* @0x21c794 cmp r4, r1 */
/* @0x21c798 beq 0x21c7bc <_Z20Audio_StartRecordingi+0xbc> */
/* @0x21c79c add r0, r0, #1 */
/* @0x21c7a0 cmp r0, r3 */
/* @0x21c7a4 beq 0x21c918 <_Z20Audio_StartRecordingi+0x218> */
/* @0x21c7a8 ldr r1, [r2, #0x4]! */
/* @0x21c7ac cmp r4, r1 */
/* @0x21c7b0 bne 0x21c79c <_Z20Audio_StartRecordingi+0x9c> */
/* @0x21c7b4 cmn r0, #1 */
/* @0x21c7b8 beq 0x21c918 <_Z20Audio_StartRecordingi+0x218> */
/* @0x21c7bc add sp, sp, #20 */
/* @0x21c7c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21c7c4 ldr r3, [pc, #0x2e8] */
/* @0x21c7c8 add r3, pc, r3 */
/* @0x21c7cc ldr r1, [r3, #0x50] */
/* @0x21c7d0 cmp r1, #0 */
/* @0x21c7d4 ble 0x21c80c <_Z20Audio_StartRecordingi+0x10c> */
/* @0x21c7d8 ldr r3, [r3, #0x54] */
/* @0x21c7dc ldr r8, [r3] */
/* @0x21c7e0 cmp r8, #0 */
/* @0x21c7e4 movne r5, r4 */
/* @0x21c7e8 bne 0x21c7fc <_Z20Audio_StartRecordingi+0xfc> */
/* @0x21c7ec b 0x21c944 <_Z20Audio_StartRecordingi+0x244> */
/* @0x21c7f0 ldr r2, [r3, #0x4]! */
/* @0x21c7f4 cmp r2, #0 */
/* @0x21c7f8 beq 0x21c948 <_Z20Audio_StartRecordingi+0x248> */
/* @0x21c7fc add r5, r5, #1 */
/* @0x21c800 cmp r5, r1 */
/* @0x21c804 lsl r8, r5, #2 */
/* @0x21c808 bne 0x21c7f0 <_Z20Audio_StartRecordingi+0xf0> */
/* @0x21c80c mov r0, #20 */
/* @0x21c810 ldr r11, [pc, #0x2a0] */
/* @0x21c814 bl 0x27c524 <_Znwj> */
/* @0x21c818 mov r3, #0 */
/* @0x21c81c add r11, pc, r11 */
/* @0x21c820 ldr r5, [r11, #0x50] */
/* @0x21c824 adds r9, r5, #1 */
/* @0x21c828 mov r4, r0 */
/* @0x21c82c str r3, [r0] */
/* @0x21c830 str r3, [r0, #0x4] */
/* @0x21c834 str r3, [r0, #0x8] */
/* @0x21c838 strb r3, [r0, #0xc] */
/* @0x21c83c str r3, [r0, #0x10] */
/* @0x21c840 bne 0x21c9f4 <_Z20Audio_StartRecordingi+0x2f4> */
/* @0x21c844 ldr r3, [r11, #0x54] */
/* @0x21c848 cmp r3, #0 */
/* @0x21c84c beq 0x21ca5c <_Z20Audio_StartRecordingi+0x35c> */
/* @0x21c850 cmp r5, #0 */
/* @0x21c854 ble 0x21c8f8 <_Z20Audio_StartRecordingi+0x1f8> */
/* @0x21c858 ldr r12, [pc, #0x25c] */
/* @0x21c85c mov r8, r9 */
/* @0x21c860 ldr r2, [pc, #0x258] */
/* @0x21c864 add r12, pc, r12 */
/* @0x21c868 str r6, [sp, #0xc] */
/* @0x21c86c mov r6, r5 */
/* @0x21c870 mov r5, r4 */
/* @0x21c874 mov r4, r12 */
/* @0x21c878 add r2, pc, r2 */
/* @0x21c87c str r2, [sp, #0x8] */
/* @0x21c880 ldr r0, [r3] */
/* @0x21c884 movw r1, #0xfeee */
/* @0x21c888 movt r1, #0xfeee */
/* @0x21c88c movw r2, #0xfeee */
/* @0x21c890 cmp r0, r1 */
/* @0x21c894 movt r2, #0xfeee */
/* @0x21c898 lsl r10, r8, #2 */
/* @0x21c89c beq 0x21c8dc <_Z20Audio_StartRecordingi+0x1dc> */
/* @0x21c8a0 ldr r1, [r3, r8, lsl #2] */
/* @0x21c8a4 add lr, r3, r10 */
/* @0x21c8a8 cmp r1, #0 */
/* @0x21c8ac mov r0, r1 */
/* @0x21c8b0 beq 0x21c8dc <_Z20Audio_StartRecordingi+0x1dc> */
/* @0x21c8b4 ldr r3, [r1] */
/* @0x21c8b8 cmp r3, r2 */
/* @0x21c8bc beq 0x21c8d0 <_Z20Audio_StartRecordingi+0x1d0> */
/* @0x21c8c0 bl 0x27d1d0 <_ZdlPv> */
/* @0x21c8c4 ldr r3, [sp, #0x8] */
/* @0x21c8c8 ldr lr, [r3, #0x54] */
/* @0x21c8cc add lr, lr, r10 */
/* @0x21c8d0 mov r2, #0 */
/* @0x21c8d4 str r2, [lr] */
/* @0x21c8d8 ldr r3, [r4, #0x54] */
/* @0x21c8dc ldr r2, [r11, #0x50] */
/* @0x21c8e0 add r8, r8, #1 */
/* @0x21c8e4 cmp r8, r2 */
/* @0x21c8e8 blt 0x21c880 <_Z20Audio_StartRecordingi+0x180> */
/* @0x21c8ec mov r4, r5 */
/* @0x21c8f0 mov r5, r6 */
/* @0x21c8f4 ldr r6, [sp, #0xc] */
/* @0x21c8f8 mov r0, r3 */
/* @0x21c8fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21c900 ldr r1, [pc, #0x1bc] */
/* @0x21c904 mov r2, #0 */
/* @0x21c908 add r1, pc, r1 */
/* @0x21c90c mov r3, r2 */
/* @0x21c910 str r2, [r1, #0x54] */
/* @0x21c914 b 0x21ca1c <_Z20Audio_StartRecordingi+0x31c> */
/* @0x21c918 ldr r3, [pc, #0x1a8] */
/* @0x21c91c ldr r1, [pc, #0x1a8] */
/* @0x21c920 ldr r3, [r6, r3] */
/* @0x21c924 add r1, pc, r1 */
/* @0x21c928 ldr r0, [r3] */
/* @0x21c92c ldr r3, [r0] */
/* @0x21c930 ldr r3, [r3, #0xc] */
/* @0x21c934 blx r3 */
/* @0x21c938 mvn r0, #0 */
/* @0x21c93c add sp, sp, #20 */
/* @0x21c940 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21c944 mov r5, r8 */
/* @0x21c948 mov r0, #20 */
/* @0x21c94c bl 0x27c524 <_Znwj> */
/* @0x21c950 ldr r2, [pc, #0x178] */
/* @0x21c954 mov r3, #0 */
/* @0x21c958 add r2, pc, r2 */
/* @0x21c95c ldr r2, [r2, #0x54] */
/* @0x21c960 mov r4, r0 */
/* @0x21c964 str r3, [r0] */
/* @0x21c968 str r3, [r0, #0x4] */
/* @0x21c96c str r3, [r0, #0x8] */
/* @0x21c970 strb r3, [r0, #0xc] */
/* @0x21c974 str r3, [r0, #0x10] */
/* @0x21c978 str r0, [r2, r8] */
/* @0x21c97c mov r3, #32000 */
/* @0x21c980 mov r1, #16000 */
/* @0x21c984 movw r2, #0x1101 */
/* @0x21c988 ldr r0, [r7] */
/* @0x21c98c bl 0xb6b68 <alcCaptureOpenDevice@plt> */
/* @0x21c990 str r0, [r4, #0x10] */
/* @0x21c994 ldr r0, [pc, #0x138] */
/* @0x21c998 add r0, pc, r0 */
/* @0x21c99c bl 0x215fd0 <_Z7checkALPKc> */
/* @0x21c9a0 ldr r3, [r4, #0x10] */
/* @0x21c9a4 cmp r3, #0 */
/* @0x21c9a8 beq 0x21ca7c <_Z20Audio_StartRecordingi+0x37c> */
/* @0x21c9ac ldr r0, [r7] */
/* @0x21c9b0 mov r2, #16000 */
/* @0x21c9b4 movw r3, #0x1101 */
/* @0x21c9b8 stm r4, {r2, r3} */
/* @0x21c9bc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x21c9c0 str r0, [r4, #0x8] */
/* @0x21c9c4 b 0x21c758 <_Z20Audio_StartRecordingi+0x58> */
/* @0x21c9c8 ldr r1, [pc, #0x108] */
/* @0x21c9cc mov r2, r5 */
/* @0x21c9d0 ldr r3, [pc, #0xf0] */
/* @0x21c9d4 add r1, pc, r1 */
/* @0x21c9d8 ldr r3, [r6, r3] */
/* @0x21c9dc ldr r0, [r3] */
/* @0x21c9e0 ldr r3, [r0] */
/* @0x21c9e4 ldr r3, [r3, #0xc] */
/* @0x21c9e8 blx r3 */
/* @0x21c9ec mvn r0, #0 */
/* @0x21c9f0 b 0x21c7bc <_Z20Audio_StartRecordingi+0xbc> */
/* @0x21c9f4 lsls r1, r9, #2 */
/* @0x21c9f8 beq 0x21ca58 <_Z20Audio_StartRecordingi+0x358> */
/* @0x21c9fc ldr r2, [pc, #0xd8] */
/* @0x21ca00 ldr r0, [r11, #0x54] */
/* @0x21ca04 add r2, pc, r2 */
/* @0x21ca08 str r3, [sp] */
/* @0x21ca0c mov r3, #135 */
/* @0x21ca10 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21ca14 mov r3, r0 */
/* @0x21ca18 str r0, [r11, #0x54] */
/* @0x21ca1c ldr r2, [pc, #0xbc] */
/* @0x21ca20 add r2, pc, r2 */
/* @0x21ca24 str r9, [r2, #0x50] */
/* @0x21ca28 str r4, [r3, r5, lsl #2] */
/* @0x21ca2c b 0x21c97c <_Z20Audio_StartRecordingi+0x27c> */
/* @0x21ca30 ldr r1, [pc, #0xac] */
/* @0x21ca34 mov r2, r5 */
/* @0x21ca38 ldr r3, [pc, #0x88] */
/* @0x21ca3c add r1, pc, r1 */
/* @0x21ca40 b 0x21c9d8 <_Z20Audio_StartRecordingi+0x2d8> */
/* @0x21ca44 ldr r1, [pc, #0x9c] */
/* @0x21ca48 mov r2, r5 */
/* @0x21ca4c ldr r3, [pc, #0x74] */
/* @0x21ca50 add r1, pc, r1 */
/* @0x21ca54 b 0x21c9d8 <_Z20Audio_StartRecordingi+0x2d8> */
/* @0x21ca58 ldr r3, [r11, #0x54] */
/* @0x21ca5c mov r0, r3 */
/* @0x21ca60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ca64 ldr r1, [pc, #0x80] */
/* @0x21ca68 mov r2, #0 */
/* @0x21ca6c add r1, pc, r1 */
/* @0x21ca70 mov r3, r2 */
/* @0x21ca74 str r2, [r1, #0x54] */
/* @0x21ca78 b 0x21ca1c <_Z20Audio_StartRecordingi+0x31c> */
/* @0x21ca7c ldr r0, [pc, #0x6c] */
/* @0x21ca80 ldr r2, [pc, #0x40] */
/* @0x21ca84 add r0, pc, r0 */
/* @0x21ca88 ldr r1, [pc, #0x64] */
/* @0x21ca8c ldr r0, [r0, #0x54] */
/* @0x21ca90 add r1, pc, r1 */
/* @0x21ca94 str r3, [r0, r5, lsl #2] */
/* @0x21ca98 ldr r3, [r6, r2] */
/* @0x21ca9c ldr r2, [r7] */
/* @0x21caa0 b 0x21c9dc <_Z20Audio_StartRecordingi+0x2dc> */
/* @0x21caa4 andseq r5, sp, r0, asr #10 */
/* @0x21caa8 .word 0xfffff7a8 */
/* @0x21caac andseq r7, r3, r0, lsl r12 */
/* @0x21cab0 subseq r8, r3, r12, lsl r11 */
/* @0x21cab4 subseq r8, r3, r12, asr #21 */
/* @0x21cab8 subseq r8, r3, r8, ror r10 */
/* @0x21cabc subseq r8, r3, r0, lsr r10 */
/* @0x21cac0 subseq r8, r3, r12, lsl r10 */
/* @0x21cac4 subseq r8, r3, r12, lsl #19 */
/* @0x21cac8 .word 0xffffbac4 */
/* @0x21cacc andseq r7, r3, r0, ror #20 */
/* @0x21cad0 subseq r8, r3, r12, lsr r9 */
/* @0x21cad4 andseq r7, r3, r0, asr r9 */
/* @0x21cad8 andseq r7, r3, r4, ror #17 */
/* @0x21cadc andseq r0, r3, r12, ror #17 */
/* @0x21cae0 subseq r8, r3, r4, ror r8 */
/* @0x21cae4 andseq r7, r3, r12, asr #16 */
/* @0x21cae8 ldrsheq r7, [r3], -r0 */
/* @0x21caec subseq r8, r3, r8, lsr #16 */
/* @0x21caf0 subseq r8, r3, r0, lsl r8 */
/* @0x21caf4 andseq r7, r3, r0, ror r8 */

/* ── FUNC 0x21caf8 · Audio_StopRecording(int) · size=148 · insn=37 */
/* @0x21caf8 push {r3, r4, r5, lr} */
/* @0x21cafc mov r5, r0 */
/* @0x21cb00 bl 0x21c220 <_Z11GetRecorderi> */
/* @0x21cb04 subs r4, r0, #0 */
/* @0x21cb08 beq 0x21cb54 <_Z19Audio_StopRecordingi+0x5c> */
/* @0x21cb0c ldrb r3, [r4, #0xc] */
/* @0x21cb10 cmp r3, #0 */
/* @0x21cb14 beq 0x21cb54 <_Z19Audio_StopRecordingi+0x5c> */
/* @0x21cb18 ldr r0, [r4, #0x10] */
/* @0x21cb1c bl 0xb6b74 <alcCaptureStop@plt> */
/* @0x21cb20 ldr r0, [r4, #0x10] */
/* @0x21cb24 bl 0xb6b80 <alcCaptureCloseDevice@plt> */
/* @0x21cb28 ldr r0, [r4, #0x8] */
/* @0x21cb2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21cb30 mov r0, r4 */
/* @0x21cb34 bl 0x27d1d0 <_ZdlPv> */
/* @0x21cb38 ldr r2, [pc, #0x40] */
/* @0x21cb3c mov r3, #0 */
/* @0x21cb40 add r2, pc, r2 */
/* @0x21cb44 mov r0, r3 */
/* @0x21cb48 ldr r2, [r2, #0x54] */
/* @0x21cb4c str r3, [r2, r5, lsl #2] */
/* @0x21cb50 pop {r3, r4, r5, pc} */
/* @0x21cb54 ldr r3, [pc, #0x28] */
/* @0x21cb58 mov r2, r5 */
/* @0x21cb5c ldr r1, [pc, #0x24] */
/* @0x21cb60 ldr r3, [pc, r3] */
/* @0x21cb64 add r1, pc, r1 */
/* @0x21cb68 ldr r0, [r3] */
/* @0x21cb6c ldr r3, [r0] */
/* @0x21cb70 ldr r3, [r3, #0xc] */
/* @0x21cb74 blx r3 */
/* @0x21cb78 mvn r0, #0 */
/* @0x21cb7c pop {r3, r4, r5, pc} */
/* @0x21cb80 subseq r8, r3, r4, asr r7 */
/* @0x21cb84 ldrheq r0, [sp], -r4 */
/* @0x21cb88 andseq r7, r3, r8, asr r8 */

/* ── FUNC 0x21cb8c · Audio_CreatePlayQueue(int, int, int) · size=772 · insn=193 */
/* @0x21cb8c cmp r2, #2 */
/* @0x21cb90 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21cb94 mov r7, r2 */
/* @0x21cb98 sub sp, sp, #28 */
/* @0x21cb9c mov r5, r0 */
/* @0x21cba0 mov r6, r1 */
/* @0x21cba4 bhi 0x21cdec <_Z21Audio_CreatePlayQueueiii+0x260> */
/* @0x21cba8 cmp r1, #1000 */
/* @0x21cbac movlt r6, #1000 */
/* @0x21cbb0 bge 0x21cd88 <_Z21Audio_CreatePlayQueueiii+0x1fc> */
/* @0x21cbb4 cmp r5, #4 */
/* @0x21cbb8 cmpne r5, #1 */
/* @0x21cbbc moveq r3, #0 */
/* @0x21cbc0 movne r3, #1 */
/* @0x21cbc4 bne 0x21ce04 <_Z21Audio_CreatePlayQueueiii+0x278> */
/* @0x21cbc8 ldr r2, [pc, #0x28c] */
/* @0x21cbcc add r2, pc, r2 */
/* @0x21cbd0 ldr r0, [r2, #0x30] */
/* @0x21cbd4 cmp r0, #0 */
/* @0x21cbd8 ble 0x21cc0c <_Z21Audio_CreatePlayQueueiii+0x80> */
/* @0x21cbdc ldr r2, [r2, #0x34] */
/* @0x21cbe0 ldr r8, [r2] */
/* @0x21cbe4 cmp r8, #0 */
/* @0x21cbe8 bne 0x21cbfc <_Z21Audio_CreatePlayQueueiii+0x70> */
/* @0x21cbec b 0x21ce50 <_Z21Audio_CreatePlayQueueiii+0x2c4> */
/* @0x21cbf0 ldr r1, [r2, #0x4]! */
/* @0x21cbf4 cmp r1, #0 */
/* @0x21cbf8 beq 0x21ce1c <_Z21Audio_CreatePlayQueueiii+0x290> */
/* @0x21cbfc add r3, r3, #1 */
/* @0x21cc00 cmp r3, r0 */
/* @0x21cc04 lsl r8, r3, #2 */
/* @0x21cc08 bne 0x21cbf0 <_Z21Audio_CreatePlayQueueiii+0x64> */
/* @0x21cc0c mov r0, #96 */
/* @0x21cc10 ldr r9, [pc, #0x248] */
/* @0x21cc14 bl 0x27c524 <_Znwj> */
/* @0x21cc18 add r9, pc, r9 */
/* @0x21cc1c mov r4, r0 */
/* @0x21cc20 bl 0x218ea4 <_ZN12cAudio_SoundC2Ev> */
/* @0x21cc24 ldr r8, [r9, #0x30] */
/* @0x21cc28 adds r11, r8, #1 */
/* @0x21cc2c bne 0x21cdbc <_Z21Audio_CreatePlayQueueiii+0x230> */
/* @0x21cc30 ldr r3, [r9, #0x34] */
/* @0x21cc34 cmp r3, #0 */
/* @0x21cc38 beq 0x21cd9c <_Z21Audio_CreatePlayQueueiii+0x210> */
/* @0x21cc3c cmp r8, #0 */
/* @0x21cc40 ble 0x21ccf4 <_Z21Audio_CreatePlayQueueiii+0x168> */
/* @0x21cc44 ldr r2, [pc, #0x218] */
/* @0x21cc48 mov r12, r9 */
/* @0x21cc4c ldr r10, [pc, #0x214] */
/* @0x21cc50 mov r9, r11 */
/* @0x21cc54 add r2, pc, r2 */
/* @0x21cc58 str r8, [sp, #0xc] */
/* @0x21cc5c add r10, pc, r10 */
/* @0x21cc60 str r5, [sp, #0x10] */
/* @0x21cc64 mov r8, r2 */
/* @0x21cc68 mov r5, r12 */
/* @0x21cc6c str r4, [sp, #0x8] */
/* @0x21cc70 str r6, [sp, #0x14] */
/* @0x21cc74 ldr r0, [r3] */
/* @0x21cc78 movw r1, #0xfeee */
/* @0x21cc7c movt r1, #0xfeee */
/* @0x21cc80 movw r2, #0xfeee */
/* @0x21cc84 cmp r0, r1 */
/* @0x21cc88 movt r2, #0xfeee */
/* @0x21cc8c lsl r6, r9, #2 */
/* @0x21cc90 beq 0x21ccd4 <_Z21Audio_CreatePlayQueueiii+0x148> */
/* @0x21cc94 ldr r4, [r3, r9, lsl #2] */
/* @0x21cc98 add lr, r3, r6 */
/* @0x21cc9c cmp r4, #0 */
/* @0x21cca0 mov r0, r4 */
/* @0x21cca4 beq 0x21ccd4 <_Z21Audio_CreatePlayQueueiii+0x148> */
/* @0x21cca8 ldr r3, [r4] */
/* @0x21ccac cmp r3, r2 */
/* @0x21ccb0 beq 0x21ccc8 <_Z21Audio_CreatePlayQueueiii+0x13c> */
/* @0x21ccb4 bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x21ccb8 mov r0, r4 */
/* @0x21ccbc bl 0x27d1d0 <_ZdlPv> */
/* @0x21ccc0 ldr lr, [r10, #0x34] */
/* @0x21ccc4 add lr, lr, r6 */
/* @0x21ccc8 mov r3, #0 */
/* @0x21cccc str r3, [lr] */
/* @0x21ccd0 ldr r3, [r8, #0x34] */
/* @0x21ccd4 ldr r2, [r5, #0x30] */
/* @0x21ccd8 add r9, r9, #1 */
/* @0x21ccdc cmp r9, r2 */
/* @0x21cce0 blt 0x21cc74 <_Z21Audio_CreatePlayQueueiii+0xe8> */
/* @0x21cce4 ldr r4, [sp, #0x8] */
/* @0x21cce8 ldr r8, [sp, #0xc] */
/* @0x21ccec ldr r5, [sp, #0x10] */
/* @0x21ccf0 ldr r6, [sp, #0x14] */
/* @0x21ccf4 mov r0, r3 */
/* @0x21ccf8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21ccfc ldr r1, [pc, #0x168] */
/* @0x21cd00 mov r2, #0 */
/* @0x21cd04 add r1, pc, r1 */
/* @0x21cd08 mov r3, r2 */
/* @0x21cd0c str r2, [r1, #0x34] */
/* @0x21cd10 ldr r2, [pc, #0x158] */
/* @0x21cd14 add r9, r8, #199680 */
/* @0x21cd18 add r9, r9, #320 */
/* @0x21cd1c add r2, pc, r2 */
/* @0x21cd20 str r11, [r2, #0x30] */
/* @0x21cd24 str r4, [r3, r8, lsl #2] */
/* @0x21cd28 ldr r3, [pc, #0x144] */
/* @0x21cd2c mov r1, #1 */
/* @0x21cd30 mov r12, #0 */
/* @0x21cd34 mvn r2, #0 */
/* @0x21cd38 ldr r3, [pc, r3] */
/* @0x21cd3c str r12, [r4, #0x58] */
/* @0x21cd40 str r2, [r4, #0x18] */
/* @0x21cd44 mov r2, r9 */
/* @0x21cd48 ldr r0, [r3] */
/* @0x21cd4c mov r3, #0 */
/* @0x21cd50 str r3, [r4, #0x34] */
/* @0x21cd54 str r6, [r4, #0x38] */
/* @0x21cd58 ldr r3, [r0] */
/* @0x21cd5c str r1, [r4, #0x3c] */
/* @0x21cd60 strb r1, [r4, #0x5c] */
/* @0x21cd64 ldr r1, [pc, #0x10c] */
/* @0x21cd68 str r5, [r4, #0x50] */
/* @0x21cd6c str r7, [r4, #0x54] */
/* @0x21cd70 add r1, pc, r1 */
/* @0x21cd74 ldr r3, [r3, #0xc] */
/* @0x21cd78 blx r3 */
/* @0x21cd7c mov r0, r9 */
/* @0x21cd80 add sp, sp, #28 */
/* @0x21cd84 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21cd88 movw r3, #0xbb80 */
/* @0x21cd8c cmp r6, r3 */
/* @0x21cd90 movge r6, r3 */
/* @0x21cd94 b 0x21cbb4 <_Z21Audio_CreatePlayQueueiii+0x28> */
/* @0x21cd98 ldr r3, [r9, #0x34] */
/* @0x21cd9c mov r0, r3 */
/* @0x21cda0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21cda4 ldr r1, [pc, #0xd0] */
/* @0x21cda8 mov r2, #0 */
/* @0x21cdac add r1, pc, r1 */
/* @0x21cdb0 mov r3, r2 */
/* @0x21cdb4 str r2, [r1, #0x34] */
/* @0x21cdb8 b 0x21cd10 <_Z21Audio_CreatePlayQueueiii+0x184> */
/* @0x21cdbc lsls r1, r11, #2 */
/* @0x21cdc0 beq 0x21cd98 <_Z21Audio_CreatePlayQueueiii+0x20c> */
/* @0x21cdc4 ldr r2, [pc, #0xb4] */
/* @0x21cdc8 mov r3, #0 */
/* @0x21cdcc ldr r0, [r9, #0x34] */
/* @0x21cdd0 add r2, pc, r2 */
/* @0x21cdd4 str r3, [sp] */
/* @0x21cdd8 mov r3, #135 */
/* @0x21cddc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21cde0 mov r3, r0 */
/* @0x21cde4 str r0, [r9, #0x34] */
/* @0x21cde8 b 0x21cd10 <_Z21Audio_CreatePlayQueueiii+0x184> */
/* @0x21cdec ldr r0, [pc, #0x90] */
/* @0x21cdf0 mov r1, #0 */
/* @0x21cdf4 add r0, pc, r0 */
/* @0x21cdf8 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x21cdfc mvn r0, #0 */
/* @0x21ce00 b 0x21cd80 <_Z21Audio_CreatePlayQueueiii+0x1f4> */
/* @0x21ce04 ldr r0, [pc, #0x7c] */
/* @0x21ce08 mov r1, #0 */
/* @0x21ce0c add r0, pc, r0 */
/* @0x21ce10 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x21ce14 mvn r0, #0 */
/* @0x21ce18 b 0x21cd80 <_Z21Audio_CreatePlayQueueiii+0x1f4> */
/* @0x21ce1c add r3, r3, #199680 */
/* @0x21ce20 add r9, r3, #320 */
/* @0x21ce24 mov r0, #96 */
/* @0x21ce28 bl 0x27c524 <_Znwj> */
/* @0x21ce2c mov r4, r0 */
/* @0x21ce30 bl 0x218ea4 <_ZN12cAudio_SoundC2Ev> */
/* @0x21ce34 ldr r3, [pc, #0x50] */
/* @0x21ce38 cmp r4, #0 */
/* @0x21ce3c add r3, pc, r3 */
/* @0x21ce40 ldr r3, [r3, #0x34] */
/* @0x21ce44 str r4, [r3, r8] */
/* @0x21ce48 bne 0x21cd28 <_Z21Audio_CreatePlayQueueiii+0x19c> */
/* @0x21ce4c b 0x21cc0c <_Z21Audio_CreatePlayQueueiii+0x80> */
/* @0x21ce50 mov r9, #3392 */
/* @0x21ce54 movt r9, #0x3 */
/* @0x21ce58 b 0x21ce24 <_Z21Audio_CreatePlayQueueiii+0x298> */
/* @0x21ce5c subseq r8, r3, r8, asr #13 */
/* @0x21ce60 subseq r8, r3, r12, ror r6 */
/* @0x21ce64 subseq r8, r3, r0, asr #12 */
/* @0x21ce68 subseq r8, r3, r8, lsr r6 */
/* @0x21ce6c .word 0x00538590 */
/* @0x21ce70 subseq r8, r3, r8, ror r5 */
/* @0x21ce74 ldrsbeq r0, [sp], -r12 */
/* @0x21ce78 andseq r7, r3, r8, lsr #14 */
/* @0x21ce7c subseq r8, r3, r8, ror #9 */
/* @0x21ce80 andseq r0, r3, r0, lsr #10 */
/* @0x21ce84 andseq r7, r3, r8, lsl #12 */
/* @0x21ce88 andseq r7, r3, r4, asr #12 */
/* @0x21ce8c subseq r8, r3, r8, asr r4 */

/* ── FUNC 0x21ce90 · Audio_FreePlayQueue(int) · size=592 · insn=148 */
/* @0x21ce90 sub r0, r0, #199680 */
/* @0x21ce94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21ce98 subs r0, r0, #320 */
/* @0x21ce9c sub sp, sp, #76 */
/* @0x21cea0 str r0, [sp, #0x2c] */
/* @0x21cea4 bmi 0x21d03c <_Z19Audio_FreePlayQueuei+0x1ac> */
/* @0x21cea8 ldr r10, [pc, #0x214] */
/* @0x21ceac add r10, pc, r10 */
/* @0x21ceb0 ldr r3, [r10, #0x30] */
/* @0x21ceb4 cmp r0, r3 */
/* @0x21ceb8 bge 0x21d03c <_Z19Audio_FreePlayQueuei+0x1ac> */
/* @0x21cebc ldr r3, [r10, #0x34] */
/* @0x21cec0 ldr r3, [r3, r0, lsl #2] */
/* @0x21cec4 cmp r3, #0 */
/* @0x21cec8 str r3, [sp, #0x30] */
/* @0x21cecc beq 0x21d0bc <_Z19Audio_FreePlayQueuei+0x22c> */
/* @0x21ced0 ldr r6, [r3, #0x58] */
/* @0x21ced4 cmp r6, #0 */
/* @0x21ced8 beq 0x21d008 <_Z19Audio_FreePlayQueuei+0x178> */
/* @0x21cedc ldr r7, [pc, #0x1e4] */
/* @0x21cee0 ldr r2, [r6, #0x10] */
/* @0x21cee4 ldr r7, [pc, r7] */
/* @0x21cee8 ldr r3, [r7] */
/* @0x21ceec ldr r0, [r3, r2, lsl #2] */
/* @0x21cef0 bl 0xb6a84 <alSourcePlay@plt> */
/* @0x21cef4 ldr r3, [r7] */
/* @0x21cef8 ldr r2, [r6, #0x10] */
/* @0x21cefc ldr r0, [r3, r2, lsl #2] */
/* @0x21cf00 bl 0xb6b14 <alSourceStop@plt> */
/* @0x21cf04 ldr r3, [r7] */
/* @0x21cf08 ldr r0, [r6, #0x10] */
/* @0x21cf0c add r2, sp, #72 */
/* @0x21cf10 mvn r12, #0 */
/* @0x21cf14 movw r1, #0x1016 */
/* @0x21cf18 str r12, [r2, #-0x8]! */
/* @0x21cf1c ldr r0, [r3, r0, lsl #2] */
/* @0x21cf20 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x21cf24 ldr r3, [sp, #0x40] */
/* @0x21cf28 cmp r3, #0 */
/* @0x21cf2c ble 0x21cffc <_Z19Audio_FreePlayQueuei+0x16c> */
/* @0x21cf30 ldr r4, [pc, #0x194] */
/* @0x21cf34 movw r9, #0x869f */
/* @0x21cf38 ldr r1, [pc, #0x190] */
/* @0x21cf3c movt r9, #0x1 */
/* @0x21cf40 ldr r2, [pc, #0x18c] */
/* @0x21cf44 add r4, pc, r4 */
/* @0x21cf48 add r1, pc, r1 */
/* @0x21cf4c str r1, [sp, #0x34] */
/* @0x21cf50 ldr r1, [pc, #0x180] */
/* @0x21cf54 mov r5, #0 */
/* @0x21cf58 add r2, pc, r2 */
/* @0x21cf5c add r3, sp, #68 */
/* @0x21cf60 add r1, pc, r1 */
/* @0x21cf64 str r2, [sp, #0x38] */
/* @0x21cf68 str r3, [sp, #0x28] */
/* @0x21cf6c str r1, [sp, #0x3c] */
/* @0x21cf70 ldr r3, [r7] */
/* @0x21cf74 mov r8, #0 */
/* @0x21cf78 ldr r0, [r6, #0x10] */
/* @0x21cf7c mov r1, #1 */
/* @0x21cf80 str r8, [sp, #0x44] */
/* @0x21cf84 add r2, sp, #68 */
/* @0x21cf88 ldr r0, [r3, r0, lsl #2] */
/* @0x21cf8c bl 0xb6b08 <alSourceUnqueueBuffers@plt> */
/* @0x21cf90 ldr r3, [r10, #0x28] */
/* @0x21cf94 cmp r3, r8 */
/* @0x21cf98 ble 0x21cfd4 <_Z19Audio_FreePlayQueuei+0x144> */
/* @0x21cf9c add r11, r8, #99328 */
/* @0x21cfa0 add r8, r8, #1 */
/* @0x21cfa4 add r11, r11, #672 */
/* @0x21cfa8 mov r0, r11 */
/* @0x21cfac bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21cfb0 cmp r0, #0 */
/* @0x21cfb4 beq 0x21cfc8 <_Z19Audio_FreePlayQueuei+0x138> */
/* @0x21cfb8 ldr r2, [r0, #0x18] */
/* @0x21cfbc ldr r3, [sp, #0x44] */
/* @0x21cfc0 cmp r2, r3 */
/* @0x21cfc4 beq 0x21d048 <_Z19Audio_FreePlayQueuei+0x1b8> */
/* @0x21cfc8 ldr r3, [r4, #0x28] */
/* @0x21cfcc cmp r3, r8 */
/* @0x21cfd0 bgt 0x21cf9c <_Z19Audio_FreePlayQueuei+0x10c> */
/* @0x21cfd4 mvn r8, #0 */
/* @0x21cfd8 ldr r3, [r6, #0x18] */
/* @0x21cfdc sub r3, r3, #199680 */
/* @0x21cfe0 sub r3, r3, #320 */
/* @0x21cfe4 cmp r3, r9 */
/* @0x21cfe8 bls 0x21d05c <_Z19Audio_FreePlayQueuei+0x1cc> */
/* @0x21cfec ldr r3, [sp, #0x40] */
/* @0x21cff0 add r5, r5, #1 */
/* @0x21cff4 cmp r3, r5 */
/* @0x21cff8 bgt 0x21cf70 <_Z19Audio_FreePlayQueuei+0xe0> */
/* @0x21cffc mov r0, r6 */
/* @0x21d000 mov r1, #1 */
/* @0x21d004 bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb> */
/* @0x21d008 ldr r0, [sp, #0x30] */
/* @0x21d00c bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x21d010 ldr r0, [sp, #0x30] */
/* @0x21d014 bl 0x27d1d0 <_ZdlPv> */
/* @0x21d018 ldr r3, [pc, #0xbc] */
/* @0x21d01c ldr r1, [sp, #0x2c] */
/* @0x21d020 mov r2, #0 */
/* @0x21d024 add r3, pc, r3 */
/* @0x21d028 mov r0, #1 */
/* @0x21d02c ldr r3, [r3, #0x34] */
/* @0x21d030 str r2, [r3, r1, lsl #2] */
/* @0x21d034 add sp, sp, #76 */
/* @0x21d038 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21d03c mov r0, #0 */
/* @0x21d040 add sp, sp, #76 */
/* @0x21d044 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21d048 mov r2, r0 */
/* @0x21d04c mov r0, r11 */
/* @0x21d050 ldr r8, [r2, #0x10] */
/* @0x21d054 bl 0x219d70 <_Z21Audio_FreeBufferSoundi> */
/* @0x21d058 b 0x21cfd8 <_Z19Audio_FreePlayQueuei+0x148> */
/* @0x21d05c vmov s13, r8 */
/* @0x21d060 ldr r1, [sp, #0x38] */
/* @0x21d064 mov r2, #0 */
/* @0x21d068 mov r3, #0 */
/* @0x21d06c vcvt.f64.s32 d7, s13 */
/* @0x21d070 movt r3, #0x3ff0 */
/* @0x21d074 str r1, [sp, #0x4] */
/* @0x21d078 mov r0, #3 */
/* @0x21d07c ldr r1, [sp, #0x3c] */
/* @0x21d080 strd r2, r3, [sp, #24] */
/* @0x21d084 str r1, [sp, #0x14] */
/* @0x21d088 mov r1, #0 */
/* @0x21d08c str r1, [sp] */
/* @0x21d090 vstr d7, [sp, #8] */
/* @0x21d094 vldr s15, [sp, #44] */
/* @0x21d098 vcvt.f64.s32 d7, s15 */
/* @0x21d09c str r1, [sp, #0x10] */
/* @0x21d0a0 str r1, [sp, #0x20] */
/* @0x21d0a4 ldr r1, [sp, #0x34] */
/* @0x21d0a8 vmov r2, r3, d7 */
/* @0x21d0ac bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x21d0b0 mov r1, #74 */
/* @0x21d0b4 bl 0x18da04 <_Z24CreateAsynEventWithDSMapii> */
/* @0x21d0b8 b 0x21cfec <_Z19Audio_FreePlayQueuei+0x15c> */
/* @0x21d0bc ldr r0, [sp, #0x30] */
/* @0x21d0c0 b 0x21d040 <_Z19Audio_FreePlayQueuei+0x1b0> */
/* @0x21d0c4 subseq r8, r3, r8, ror #7 */
/* @0x21d0c8 andseq r4, sp, r8, ror #9 */
/* @0x21d0cc subseq r8, r3, r0, asr r3 */
/* @0x21d0d0 andseq r7, r3, r0, ror r0 */
/* @0x21d0d4 andseq r7, r3, r12, rrx */
/* @0x21d0d8 andseq r7, r3, r0, ror r0 */
/* @0x21d0dc subseq r8, r3, r0, ror r2 */

/* ── FUNC 0x21d0e0 · Audio_QueueBufferSound(int, int, int, int) · size=740 · insn=185 */
/* @0x21d0e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21d0e4 mov r8, r0 */
/* @0x21d0e8 ldr r4, [pc, #0x2a0] */
/* @0x21d0ec sub sp, sp, #20 */
/* @0x21d0f0 ldr r12, [pc, #0x29c] */
/* @0x21d0f4 mov r0, r1 */
/* @0x21d0f8 add r4, pc, r4 */
/* @0x21d0fc mov r5, r3 */
/* @0x21d100 ldr r12, [r4, r12] */
/* @0x21d104 ldrb r7, [r12] */
/* @0x21d108 cmp r7, #0 */
/* @0x21d10c bne 0x21d220 <_Z22Audio_QueueBufferSoundiiii+0x140> */
/* @0x21d110 ldr r3, [pc, #0x280] */
/* @0x21d114 ldr r3, [r4, r3] */
/* @0x21d118 ldrb r3, [r3] */
/* @0x21d11c cmp r3, #0 */
/* @0x21d120 beq 0x21d220 <_Z22Audio_QueueBufferSoundiiii+0x140> */
/* @0x21d124 sub r12, r8, #199680 */
/* @0x21d128 subs r12, r12, #320 */
/* @0x21d12c bmi 0x21d350 <_Z22Audio_QueueBufferSoundiiii+0x270> */
/* @0x21d130 ldr r3, [pc, #0x264] */
/* @0x21d134 add r3, pc, r3 */
/* @0x21d138 ldr r1, [r3, #0x30] */
/* @0x21d13c cmp r12, r1 */
/* @0x21d140 bge 0x21d350 <_Z22Audio_QueueBufferSoundiiii+0x270> */
/* @0x21d144 ldr r3, [r3, #0x34] */
/* @0x21d148 ldr r6, [r3, r12, lsl #2] */
/* @0x21d14c cmp r6, #0 */
/* @0x21d150 beq 0x21d350 <_Z22Audio_QueueBufferSoundiiii+0x270> */
/* @0x21d154 ldr lr, [r6, #0x38] */
/* @0x21d158 mov r3, r2 */
/* @0x21d15c ldr r1, [r6, #0x50] */
/* @0x21d160 str r5, [sp] */
/* @0x21d164 ldr r12, [r6, #0x54] */
/* @0x21d168 mov r2, lr */
/* @0x21d16c str r12, [sp, #0x4] */
/* @0x21d170 bl 0x2198a0 <_Z23Audio_CreateBufferSoundiiiiii> */
/* @0x21d174 mov r5, r0 */
/* @0x21d178 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21d17c subs r9, r0, #0 */
/* @0x21d180 beq 0x21d37c <_Z22Audio_QueueBufferSoundiiii+0x29c> */
/* @0x21d184 ldr r5, [r6, #0x58] */
/* @0x21d188 cmp r5, #0 */
/* @0x21d18c beq 0x21d24c <_Z22Audio_QueueBufferSoundiiii+0x16c> */
/* @0x21d190 ldr r3, [r9, #0x18] */
/* @0x21d194 ldr r6, [r5, #0x10] */
/* @0x21d198 cmp r3, #0 */
/* @0x21d19c str r3, [sp, #0xc] */
/* @0x21d1a0 bne 0x21d1e0 <_Z22Audio_QueueBufferSoundiiii+0x100> */
/* @0x21d1a4 bl 0xb6a54 <alGetError@plt> */
/* @0x21d1a8 subs r2, r0, #0 */
/* @0x21d1ac bne 0x21d1bc <_Z22Audio_QueueBufferSoundiiii+0xdc> */
/* @0x21d1b0 ldr r0, [r5, #0x14] */
/* @0x21d1b4 add sp, sp, #20 */
/* @0x21d1b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21d1bc ldr r3, [pc, #0x1dc] */
/* @0x21d1c0 ldr r1, [pc, #0x1dc] */
/* @0x21d1c4 ldr r3, [r4, r3] */
/* @0x21d1c8 add r1, pc, r1 */
/* @0x21d1cc ldr r0, [r3] */
/* @0x21d1d0 ldr r3, [r0] */
/* @0x21d1d4 ldr r3, [r3, #0xc] */
/* @0x21d1d8 blx r3 */
/* @0x21d1dc b 0x21d1b0 <_Z22Audio_QueueBufferSoundiiii+0xd0> */
/* @0x21d1e0 ldr r3, [pc, #0x1c0] */
/* @0x21d1e4 add r2, sp, #12 */
/* @0x21d1e8 mov r1, #1 */
/* @0x21d1ec ldr r7, [r4, r3] */
/* @0x21d1f0 ldr r3, [r7] */
/* @0x21d1f4 ldr r0, [r3, r6, lsl #2] */
/* @0x21d1f8 bl 0xb6b8c <alSourceQueueBuffers@plt> */
/* @0x21d1fc bl 0xb6a54 <alGetError@plt> */
/* @0x21d200 subs r2, r0, #0 */
/* @0x21d204 bne 0x21d228 <_Z22Audio_QueueBufferSoundiiii+0x148> */
/* @0x21d208 ldr r3, [r7] */
/* @0x21d20c movw r1, #0x1007 */
/* @0x21d210 mov r2, #0 */
/* @0x21d214 ldr r0, [r3, r6, lsl #2] */
/* @0x21d218 bl 0xb6a6c <alSourcei@plt> */
/* @0x21d21c b 0x21d1a4 <_Z22Audio_QueueBufferSoundiiii+0xc4> */
/* @0x21d220 mvn r0, #0 */
/* @0x21d224 b 0x21d1b4 <_Z22Audio_QueueBufferSoundiiii+0xd4> */
/* @0x21d228 ldr r3, [pc, #0x170] */
/* @0x21d22c ldr r1, [pc, #0x178] */
/* @0x21d230 ldr r3, [r4, r3] */
/* @0x21d234 add r1, pc, r1 */
/* @0x21d238 ldr r0, [r3] */
/* @0x21d23c ldr r3, [r0] */
/* @0x21d240 ldr r3, [r3, #0xc] */
/* @0x21d244 blx r3 */
/* @0x21d248 b 0x21d208 <_Z22Audio_QueueBufferSoundiiii+0x128> */
/* @0x21d24c mov r0, r8 */
/* @0x21d250 mov r1, #0 */
/* @0x21d254 movt r1, #0x4120 */
/* @0x21d258 mov r11, #1065353216 */
/* @0x21d25c bl 0x21addc <_Z26Audio_GetSoundSourceToPlayif> */
/* @0x21d260 ldr r3, [pc, #0x148] */
/* @0x21d264 ldr lr, [pc, #0x148] */
/* @0x21d268 movw r1, #0x1023 */
/* @0x21d26c ldr r12, [pc, #0x134] */
/* @0x21d270 mov r10, #0 */
/* @0x21d274 ldr r2, [r4, r3] */
/* @0x21d278 ldr r3, [r2] */
/* @0x21d27c mov r5, r0 */
/* @0x21d280 str r8, [r0, #0x18] */
/* @0x21d284 str r7, [r0, #0x2c] */
/* @0x21d288 add r8, r3, #1 */
/* @0x21d28c str r3, [r5, #0x14] */
/* @0x21d290 str r8, [r2] */
/* @0x21d294 mov r2, #0 */
/* @0x21d298 str r11, [r5, #0x24] */
/* @0x21d29c movt r2, #0x4120 */
/* @0x21d2a0 ldr r3, [r4, lr] */
/* @0x21d2a4 ldr r0, [pc, #0x10c] */
/* @0x21d2a8 strb r7, [r5, #0x4] */
/* @0x21d2ac ldr r3, [r3] */
/* @0x21d2b0 str r2, [r5, #0x1c] */
/* @0x21d2b4 ldr r7, [r5, #0x10] */
/* @0x21d2b8 str r3, [r5, #0x34] */
/* @0x21d2bc ldr r8, [r4, r12] */
/* @0x21d2c0 ldr r2, [r4, r0] */
/* @0x21d2c4 ldr r3, [r8] */
/* @0x21d2c8 ldr r2, [r2] */
/* @0x21d2cc ldr r0, [r3, r7, lsl #2] */
/* @0x21d2d0 bl 0xb6a78 <alSourcef@plt> */
/* @0x21d2d4 ldr r3, [r8] */
/* @0x21d2d8 movw r1, #0x100a */
/* @0x21d2dc ldr r2, [r6, #0x4] */
/* @0x21d2e0 ldr r0, [r3, r7, lsl #2] */
/* @0x21d2e4 bl 0xb6a78 <alSourcef@plt> */
/* @0x21d2e8 ldr r3, [r8] */
/* @0x21d2ec movw r1, #0x1003 */
/* @0x21d2f0 ldr r2, [r6, #0x8] */
/* @0x21d2f4 ldr r0, [r3, r7, lsl #2] */
/* @0x21d2f8 bl 0xb6a78 <alSourcef@plt> */
/* @0x21d2fc ldr r3, [r8] */
/* @0x21d300 movw r1, #0x202 */
/* @0x21d304 mov r2, #1 */
/* @0x21d308 ldr r0, [r3, r7, lsl #2] */
/* @0x21d30c bl 0xb6a6c <alSourcei@plt> */
/* @0x21d310 ldr r0, [r8] */
/* @0x21d314 mov r2, r10 */
/* @0x21d318 movw r1, #0x1004 */
/* @0x21d31c mov r3, r10 */
/* @0x21d320 ldr r0, [r0, r7, lsl #2] */
/* @0x21d324 str r10, [sp] */
/* @0x21d328 bl 0xb6b2c <alSource3f@plt> */
/* @0x21d32c ldr r3, [r8] */
/* @0x21d330 mov r2, r10 */
/* @0x21d334 movw r1, #0x1006 */
/* @0x21d338 ldr r0, [r3, r7, lsl #2] */
/* @0x21d33c mov r3, r10 */
/* @0x21d340 str r10, [sp] */
/* @0x21d344 bl 0xb6b2c <alSource3f@plt> */
/* @0x21d348 str r5, [r6, #0x58] */
/* @0x21d34c b 0x21d190 <_Z22Audio_QueueBufferSoundiiii+0xb0> */
/* @0x21d350 ldr r1, [pc, #0x64] */
/* @0x21d354 mov r2, r8 */
/* @0x21d358 ldr r3, [pc, #0x40] */
/* @0x21d35c add r1, pc, r1 */
/* @0x21d360 ldr r3, [r4, r3] */
/* @0x21d364 ldr r0, [r3] */
/* @0x21d368 ldr r3, [r0] */
/* @0x21d36c ldr r3, [r3, #0xc] */
/* @0x21d370 blx r3 */
/* @0x21d374 mvn r0, #0 */
/* @0x21d378 b 0x21d1b4 <_Z22Audio_QueueBufferSoundiiii+0xd4> */
/* @0x21d37c ldr r1, [pc, #0x3c] */
/* @0x21d380 mov r2, r5 */
/* @0x21d384 ldr r3, [pc, #0x14] */
/* @0x21d388 add r1, pc, r1 */
/* @0x21d38c b 0x21d360 <_Z22Audio_QueueBufferSoundiiii+0x280> */
/* @0x21d390 andseq r4, sp, r8, asr r11 */
/* @0x21d394 .word 0xffffd3fc */
/* @0x21d398 .word 0xffffd0e0 */
/* @0x21d39c subseq r8, r3, r0, ror #2 */
/* @0x21d3a0 .word 0xffffbac4 */
/* @0x21d3a4 andseq r7, r3, r12, lsl #7 */
/* @0x21d3a8 .word 0xfffff77c */
/* @0x21d3ac andseq r7, r3, r4, ror #5 */
/* @0x21d3b0 .word 0xfffff7a0 */
/* @0x21d3b4 .word 0xfffff778 */
/* @0x21d3b8 .word 0xfffff7a4 */
/* @0x21d3bc andseq r7, r3, r0, asr r1 */
/* @0x21d3c0 andseq r7, r3, r8, asr r1 */

/* ── FUNC 0x21d3c4 · Audio_CreateSyncGroup(bool) · size=52 · insn=13 */
/* @0x21d3c4 mov r1, r0 */
/* @0x21d3c8 ldr r0, [pc, #0x20] */
/* @0x21d3cc push {r4, lr} */
/* @0x21d3d0 add r0, pc, r0 */
/* @0x21d3d4 bl 0x225d94 <_ZN9COggAudio17Create_SyncThreadEb> */
/* @0x21d3d8 mov r4, r0 */
/* @0x21d3dc ldr r0, [pc, #0x10] */
/* @0x21d3e0 add r0, pc, r0 */
/* @0x21d3e4 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x21d3e8 mov r0, r4 */
/* @0x21d3ec pop {r4, pc} */
/* @0x21d3f0 subseq r7, r3, r4, asr #29 */
/* @0x21d3f4 ldrsbeq r0, [r4], -r0 */

/* ── FUNC 0x21d3f8 · Audio_DestroySyncGroup(int) · size=20 · insn=5 */
/* @0x21d3f8 mov r1, r0 */
/* @0x21d3fc ldr r0, [pc, #0x4] */
/* @0x21d400 add r0, pc, r0 */
/* @0x21d404 b 0x225f2c <_ZN9COggAudio17Delete_SyncThreadEi> */
/* @0x21d408 .word 0x00537e94 */

/* ── FUNC 0x21d40c · Audio_StartSyncGroup(int) · size=20 · insn=5 */
/* @0x21d40c mov r1, r0 */
/* @0x21d410 ldr r0, [pc, #0x4] */
/* @0x21d414 add r0, pc, r0 */
/* @0x21d418 b 0x2261d4 <_ZN9COggAudio14StartSyncGroupEi> */
/* @0x21d41c subseq r7, r3, r0, lsl #29 */

/* ── FUNC 0x21d420 · Audio_StopSyncGroup(int) · size=20 · insn=5 */
/* @0x21d420 mov r1, r0 */
/* @0x21d424 ldr r0, [pc, #0x4] */
/* @0x21d428 add r0, pc, r0 */
/* @0x21d42c b 0x2261f4 <_ZN9COggAudio13StopSyncGroupEi> */
/* @0x21d430 subseq r7, r3, r12, ror #28 */

/* ── FUNC 0x21d434 · Audio_PlayInSyncGroup(int, int) · size=464 · insn=116 */
/* @0x21d434 push {r4, r5, r6, r7, r8, lr} */
/* @0x21d438 sub sp, sp, #1040 */
/* @0x21d43c ldr r4, [pc, #0x198] */
/* @0x21d440 sub sp, sp, #8 */
/* @0x21d444 ldr r3, [pc, #0x194] */
/* @0x21d448 mov r8, r0 */
/* @0x21d44c add r4, pc, r4 */
/* @0x21d450 ldr r2, [pc, #0x18c] */
/* @0x21d454 mov r7, r1 */
/* @0x21d458 ldr r6, [r4, r3] */
/* @0x21d45c ldr r3, [r6] */
/* @0x21d460 str r3, [sp, #0x414] */
/* @0x21d464 ldr r3, [r4, r2] */
/* @0x21d468 ldrb r3, [r3] */
/* @0x21d46c cmp r3, #0 */
/* @0x21d470 bne 0x21d550 <_Z21Audio_PlayInSyncGroupii+0x11c> */
/* @0x21d474 ldr r3, [pc, #0x16c] */
/* @0x21d478 ldr r3, [r4, r3] */
/* @0x21d47c ldrb r3, [r3] */
/* @0x21d480 cmp r3, #0 */
/* @0x21d484 beq 0x21d550 <_Z21Audio_PlayInSyncGroupii+0x11c> */
/* @0x21d488 mov r0, r1 */
/* @0x21d48c bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x21d490 ldr r1, [pc, #0x154] */
/* @0x21d494 ldr r3, [pc, #0x154] */
/* @0x21d498 add r1, pc, r1 */
/* @0x21d49c subs r5, r0, #0 */
/* @0x21d4a0 beq 0x21d534 <_Z21Audio_PlayInSyncGroupii+0x100> */
/* @0x21d4a4 ldrb r3, [r5, #0x24] */
/* @0x21d4a8 cmp r3, #0 */
/* @0x21d4ac beq 0x21d51c <_Z21Audio_PlayInSyncGroupii+0xe8> */
/* @0x21d4b0 ldr r3, [pc, #0x13c] */
/* @0x21d4b4 ldr r1, [r5, #0x4c] */
/* @0x21d4b8 ldr r0, [r4, r3] */
/* @0x21d4bc bl 0x21e1e0 <_ZN14CAudioGroupMan13IsGroupLoadedEi> */
/* @0x21d4c0 cmp r0, #0 */
/* @0x21d4c4 beq 0x21d59c <_Z21Audio_PlayInSyncGroupii+0x168> */
/* @0x21d4c8 ldr r3, [r5, #0x30] */
/* @0x21d4cc cmp r3, #0 */
/* @0x21d4d0 beq 0x21d558 <_Z21Audio_PlayInSyncGroupii+0x124> */
/* @0x21d4d4 ldr r0, [pc, #0x11c] */
/* @0x21d4d8 mov r1, #0 */
/* @0x21d4dc mov r3, #1 */
/* @0x21d4e0 str r1, [sp] */
/* @0x21d4e4 str r3, [sp, #0x4] */
/* @0x21d4e8 mov r2, r5 */
/* @0x21d4ec str r8, [sp, #0x8] */
/* @0x21d4f0 add r0, pc, r0 */
/* @0x21d4f4 mvn r1, #0 */
/* @0x21d4f8 mov r3, #0 */
/* @0x21d4fc bl 0x22630c <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii> */
/* @0x21d500 ldr r2, [sp, #0x414] */
/* @0x21d504 ldr r3, [r6] */
/* @0x21d508 cmp r2, r3 */
/* @0x21d50c bne 0x21d5d8 <_Z21Audio_PlayInSyncGroupii+0x1a4> */
/* @0x21d510 add sp, sp, #1040 */
/* @0x21d514 add sp, sp, #8 */
/* @0x21d518 pop {r4, r5, r6, r7, r8, pc} */
/* @0x21d51c ldrb r3, [r5, #0x25] */
/* @0x21d520 cmp r3, #0 */
/* @0x21d524 bne 0x21d4b0 <_Z21Audio_PlayInSyncGroupii+0x7c> */
/* @0x21d528 ldr r1, [pc, #0xcc] */
/* @0x21d52c ldr r3, [pc, #0xbc] */
/* @0x21d530 add r1, pc, r1 */
/* @0x21d534 ldr r3, [r4, r3] */
/* @0x21d538 ldr r0, [r3] */
/* @0x21d53c ldr r3, [r0] */
/* @0x21d540 ldr r3, [r3, #0xc] */
/* @0x21d544 blx r3 */
/* @0x21d548 mvn r0, #0 */
/* @0x21d54c b 0x21d500 <_Z21Audio_PlayInSyncGroupii+0xcc> */
/* @0x21d550 mvn r0, #0 */
/* @0x21d554 b 0x21d500 <_Z21Audio_PlayInSyncGroupii+0xcc> */
/* @0x21d558 add r4, sp, #20 */
/* @0x21d55c mov r1, #1024 */
/* @0x21d560 ldr r2, [r5] */
/* @0x21d564 mov r0, r4 */
/* @0x21d568 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x21d56c mov r0, r4 */
/* @0x21d570 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x21d574 cmp r0, #0 */
/* @0x21d578 beq 0x21d4d4 <_Z21Audio_PlayInSyncGroupii+0xa0> */
/* @0x21d57c ldr r0, [r5, #0x30] */
/* @0x21d580 cmp r0, #0 */
/* @0x21d584 beq 0x21d58c <_Z21Audio_PlayInSyncGroupii+0x158> */
/* @0x21d588 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x21d58c mov r0, r4 */
/* @0x21d590 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x21d594 str r0, [r5, #0x30] */
/* @0x21d598 b 0x21d4d4 <_Z21Audio_PlayInSyncGroupii+0xa0> */
/* @0x21d59c ldr r3, [pc, #0x4c] */
/* @0x21d5a0 mov r0, r7 */
/* @0x21d5a4 ldr r3, [r4, r3] */
/* @0x21d5a8 ldr r4, [r3] */
/* @0x21d5ac ldr r3, [r4] */
/* @0x21d5b0 ldr r7, [r3, #0xc] */
/* @0x21d5b4 bl 0x218348 <_Z13Audio_GetNamei> */
/* @0x21d5b8 ldr r1, [pc, #0x40] */
/* @0x21d5bc ldr r3, [r5, #0x4c] */
/* @0x21d5c0 add r1, pc, r1 */
/* @0x21d5c4 mov r2, r0 */
/* @0x21d5c8 mov r0, r4 */
/* @0x21d5cc blx r7 */
/* @0x21d5d0 mvn r0, #0 */
/* @0x21d5d4 b 0x21d500 <_Z21Audio_PlayInSyncGroupii+0xcc> */
/* @0x21d5d8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x21d5dc andseq r4, sp, r4, lsl #16 */
/* @0x21d5e0 .word 0xffffbd00 */
/* @0x21d5e4 .word 0xffffd3fc */
/* @0x21d5e8 .word 0xffffd0e0 */
/* @0x21d5ec mulseq r3, r4, r11 */
/* @0x21d5f0 .word 0xffffbac4 */
/* @0x21d5f4 .word 0xffffd400 */
/* @0x21d5f8 subseq r7, r3, r4, lsr #27 */
/* @0x21d5fc andseq r7, r3, r4, rrx */
/* @0x21d600 mulseq r3, r4, r10 */

/* ── FUNC 0x21d604 · Audio_PauseSyncGroup(int) · size=20 · insn=5 */
/* @0x21d604 mov r1, r0 */
/* @0x21d608 ldr r0, [pc, #0x4] */
/* @0x21d60c add r0, pc, r0 */
/* @0x21d610 b 0x226214 <_ZN9COggAudio14PauseSyncGroupEi> */
/* @0x21d614 subseq r7, r3, r8, lsl #25 */

/* ── FUNC 0x21d618 · Audio_ResumeSyncGroup(int) · size=20 · insn=5 */
/* @0x21d618 mov r1, r0 */
/* @0x21d61c ldr r0, [pc, #0x4] */
/* @0x21d620 add r0, pc, r0 */
/* @0x21d624 b 0x226234 <_ZN9COggAudio15ResumeSyncGroupEi> */
/* @0x21d628 subseq r7, r3, r4, ror r12 */

/* ── FUNC 0x21d62c · Audio_SyncGroupGetTrackPos(int) · size=20 · insn=5 */
/* @0x21d62c mov r1, r0 */
/* @0x21d630 ldr r0, [pc, #0x4] */
/* @0x21d634 add r0, pc, r0 */
/* @0x21d638 b 0x226934 <_ZN9COggAudio20GetSyncGroupTrackPosEi> */
/* @0x21d63c subseq r7, r3, r0, ror #24 */

/* ── FUNC 0x21d640 · Audio_SyncGroupIsPlaying(int) · size=76 · insn=19 */
/* @0x21d640 ldr r3, [pc, #0x38] */
/* @0x21d644 ldr r3, [pc, r3] */
/* @0x21d648 ldrb r3, [r3] */
/* @0x21d64c cmp r3, #0 */
/* @0x21d650 bne 0x21d668 <_Z24Audio_SyncGroupIsPlayingi+0x28> */
/* @0x21d654 ldr r3, [pc, #0x28] */
/* @0x21d658 ldr r3, [pc, r3] */
/* @0x21d65c ldrb r3, [r3] */
/* @0x21d660 cmp r3, #0 */
/* @0x21d664 bne 0x21d670 <_Z24Audio_SyncGroupIsPlayingi+0x30> */
/* @0x21d668 mov r0, #0 */
/* @0x21d66c bx lr */
/* @0x21d670 mov r1, r0 */
/* @0x21d674 ldr r0, [pc, #0xc] */
/* @0x21d678 add r0, pc, r0 */
/* @0x21d67c b 0x226254 <_ZN9COggAudio18IsSyncGroupPlayingEi> */
/* @0x21d680 andseq r1, sp, r8, lsl #20 */
/* @0x21d684 ldrsbeq r1, [sp], -r8 */
/* @0x21d688 subseq r7, r3, r12, lsl r12 */

/* ── FUNC 0x21d68c · Audio_SyncGroupDebug(int) · size=48 · insn=12 */
/* @0x21d68c ldr r3, [pc, #0x20] */
/* @0x21d690 cmn r0, #1 */
/* @0x21d694 mov r1, r0 */
/* @0x21d698 ldr r0, [pc, #0x18] */
/* @0x21d69c ldr r3, [pc, r3] */
/* @0x21d6a0 movne r2, #32 */
/* @0x21d6a4 moveq r2, #0 */
/* @0x21d6a8 add r0, pc, r0 */
/* @0x21d6ac str r2, [r3] */
/* @0x21d6b0 b 0x22627c <_ZN9COggAudio14DebugSyncGroupEi> */
/* @0x21d6b4 mulseq sp, r0, sp */
/* @0x21d6b8 subseq r7, r3, r12, ror #23 */

/* ── FUNC 0x21d6bc · Audio_Debug(bool) · size=32 · insn=8 */
/* @0x21d6bc ldr r3, [pc, #0x14] */
/* @0x21d6c0 cmp r0, #0 */
/* @0x21d6c4 ldr r3, [pc, r3] */
/* @0x21d6c8 movne r0, #16 */
/* @0x21d6cc moveq r0, #0 */
/* @0x21d6d0 str r0, [r3] */
/* @0x21d6d4 bx lr */
/* @0x21d6d8 andseq r0, sp, r8, ror #26 */

/* ── FUNC 0x21d6dc · Audio_CreateStream(char const*) · size=716 · insn=179 */
/* @0x21d6dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x21d6e0 sub sp, sp, #2080 */
/* @0x21d6e4 ldr r5, [pc, #0x2a0] */
/* @0x21d6e8 sub sp, sp, #4 */
/* @0x21d6ec ldr r3, [pc, #0x29c] */
/* @0x21d6f0 mov r4, r0 */
/* @0x21d6f4 add r5, pc, r5 */
/* @0x21d6f8 ldr r6, [r5, r3] */
/* @0x21d6fc ldr r3, [r6] */
/* @0x21d700 str r3, [sp, #0x81c] */
/* @0x21d704 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x21d708 cmp r0, #0 */
/* @0x21d70c beq 0x21d840 <_Z18Audio_CreateStreamPKc+0x164> */
/* @0x21d710 add r7, sp, #28 */
/* @0x21d714 mov r2, r4 */
/* @0x21d718 mov r1, #2048 */
/* @0x21d71c mov r0, r7 */
/* @0x21d720 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x21d724 ldr r3, [pc, #0x268] */
/* @0x21d728 ldr r8, [r5, r3] */
/* @0x21d72c ldr r12, [r8] */
/* @0x21d730 cmp r12, #0 */
/* @0x21d734 ble 0x21d76c <_Z18Audio_CreateStreamPKc+0x90> */
/* @0x21d738 ldr r2, [r8, #0x4] */
/* @0x21d73c ldr r4, [r2] */
/* @0x21d740 cmp r4, #0 */
/* @0x21d744 movne r3, #0 */
/* @0x21d748 bne 0x21d760 <_Z18Audio_CreateStreamPKc+0x84> */
/* @0x21d74c b 0x21d980 <_Z18Audio_CreateStreamPKc+0x2a4> */
/* @0x21d750 ldr r1, [r2, #0x4]! */
/* @0x21d754 lsl r4, r3, #2 */
/* @0x21d758 cmp r1, #0 */
/* @0x21d75c beq 0x21d954 <_Z18Audio_CreateStreamPKc+0x278> */
/* @0x21d760 add r3, r3, #1 */
/* @0x21d764 cmp r3, r12 */
/* @0x21d768 bne 0x21d750 <_Z18Audio_CreateStreamPKc+0x74> */
/* @0x21d76c mov r0, #96 */
/* @0x21d770 bl 0x27c524 <_Znwj> */
/* @0x21d774 mov r9, r0 */
/* @0x21d778 bl 0x218ea4 <_ZN12cAudio_SoundC2Ev> */
/* @0x21d77c ldr r4, [r8] */
/* @0x21d780 adds r11, r4, #1 */
/* @0x21d784 bne 0x21d868 <_Z18Audio_CreateStreamPKc+0x18c> */
/* @0x21d788 ldr r3, [r8, #0x4] */
/* @0x21d78c cmp r3, #0 */
/* @0x21d790 beq 0x21d828 <_Z18Audio_CreateStreamPKc+0x14c> */
/* @0x21d794 cmp r4, #0 */
/* @0x21d798 ble 0x21d828 <_Z18Audio_CreateStreamPKc+0x14c> */
/* @0x21d79c mov r10, r11 */
/* @0x21d7a0 mov r1, r11 */
/* @0x21d7a4 ldr r0, [r3] */
/* @0x21d7a8 movw r2, #0xfeee */
/* @0x21d7ac movt r2, #0xfeee */
/* @0x21d7b0 cmp r0, r2 */
/* @0x21d7b4 beq 0x21d818 <_Z18Audio_CreateStreamPKc+0x13c> */
/* @0x21d7b8 ldr r2, [r3, r10, lsl #2] */
/* @0x21d7bc lsl r12, r10, #2 */
/* @0x21d7c0 add r0, r3, r12 */
/* @0x21d7c4 cmp r2, #0 */
/* @0x21d7c8 beq 0x21d818 <_Z18Audio_CreateStreamPKc+0x13c> */
/* @0x21d7cc ldr lr, [r2] */
/* @0x21d7d0 movw r3, #0xfeee */
/* @0x21d7d4 movt r3, #0xfeee */
/* @0x21d7d8 cmp lr, r3 */
/* @0x21d7dc beq 0x21d810 <_Z18Audio_CreateStreamPKc+0x134> */
/* @0x21d7e0 mov r0, r2 */
/* @0x21d7e4 str r1, [sp, #0xc] */
/* @0x21d7e8 str r12, [sp, #0x10] */
/* @0x21d7ec str r2, [sp, #0x14] */
/* @0x21d7f0 bl 0x218f24 <_ZN12cAudio_SoundD2Ev> */
/* @0x21d7f4 ldr r2, [sp, #0x14] */
/* @0x21d7f8 mov r0, r2 */
/* @0x21d7fc bl 0x27d1d0 <_ZdlPv> */
/* @0x21d800 ldr r0, [r8, #0x4] */
/* @0x21d804 ldr r12, [sp, #0x10] */
/* @0x21d808 ldr r1, [sp, #0xc] */
/* @0x21d80c add r0, r0, r12 */
/* @0x21d810 str r1, [r0] */
/* @0x21d814 ldr r3, [r8, #0x4] */
/* @0x21d818 ldr r2, [r8] */
/* @0x21d81c add r10, r10, #1 */
/* @0x21d820 cmp r10, r2 */
/* @0x21d824 blt 0x21d7a4 <_Z18Audio_CreateStreamPKc+0xc8> */
/* @0x21d828 mov r0, r3 */
/* @0x21d82c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x21d830 mov r2, #0 */
/* @0x21d834 mov r3, r2 */
/* @0x21d838 str r2, [r8, #0x4] */
/* @0x21d83c b 0x21d894 <_Z18Audio_CreateStreamPKc+0x1b8> */
/* @0x21d840 mov r0, r4 */
/* @0x21d844 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x21d848 cmp r0, #0 */
/* @0x21d84c beq 0x21d91c <_Z18Audio_CreateStreamPKc+0x240> */
/* @0x21d850 add r7, sp, #28 */
/* @0x21d854 mov r2, r4 */
/* @0x21d858 mov r1, #2048 */
/* @0x21d85c mov r0, r7 */
/* @0x21d860 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x21d864 b 0x21d724 <_Z18Audio_CreateStreamPKc+0x48> */
/* @0x21d868 lsls r1, r11, #2 */
/* @0x21d86c beq 0x21d948 <_Z18Audio_CreateStreamPKc+0x26c> */
/* @0x21d870 ldr r2, [pc, #0x120] */
/* @0x21d874 mov r3, #0 */
/* @0x21d878 ldr r0, [r8, #0x4] */
/* @0x21d87c add r2, pc, r2 */
/* @0x21d880 str r3, [sp] */
/* @0x21d884 mov r3, #135 */
/* @0x21d888 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x21d88c mov r3, r0 */
/* @0x21d890 str r0, [r8, #0x4] */
/* @0x21d894 add r10, r4, #299008 */
/* @0x21d898 str r11, [r8] */
/* @0x21d89c add r10, r10, #992 */
/* @0x21d8a0 str r9, [r3, r4, lsl #2] */
/* @0x21d8a4 mov r3, #1 */
/* @0x21d8a8 mov r2, #0 */
/* @0x21d8ac str r3, [r9, #0x3c] */
/* @0x21d8b0 mov r0, r7 */
/* @0x21d8b4 strb r3, [r9, #0x24] */
/* @0x21d8b8 strb r3, [r9, #0x25] */
/* @0x21d8bc str r2, [r9, #0x18] */
/* @0x21d8c0 mov r2, #0 */
/* @0x21d8c4 str r2, [r9, #0x34] */
/* @0x21d8c8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x21d8cc str r0, [r9] */
/* @0x21d8d0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x21d8d4 ldr r3, [pc, #0xc0] */
/* @0x21d8d8 ldr r1, [pc, #0xc0] */
/* @0x21d8dc mov r2, r10 */
/* @0x21d8e0 add r1, pc, r1 */
/* @0x21d8e4 str r0, [r9, #0x30] */
/* @0x21d8e8 ldr r3, [r5, r3] */
/* @0x21d8ec ldr r0, [r3] */
/* @0x21d8f0 ldr r3, [r0] */
/* @0x21d8f4 ldr r3, [r3, #0xc] */
/* @0x21d8f8 blx r3 */
/* @0x21d8fc mov r0, r10 */
/* @0x21d900 ldr r2, [sp, #0x81c] */
/* @0x21d904 ldr r3, [r6] */
/* @0x21d908 cmp r2, r3 */
/* @0x21d90c bne 0x21d950 <_Z18Audio_CreateStreamPKc+0x274> */
/* @0x21d910 add sp, sp, #2080 */
/* @0x21d914 add sp, sp, #4 */
/* @0x21d918 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21d91c ldr r3, [pc, #0x78] */
/* @0x21d920 mov r2, r4 */
/* @0x21d924 ldr r1, [pc, #0x78] */
/* @0x21d928 ldr r3, [r5, r3] */
/* @0x21d92c add r1, pc, r1 */
/* @0x21d930 ldr r0, [r3] */
/* @0x21d934 ldr r3, [r0] */
/* @0x21d938 ldr r3, [r3, #0xc] */
/* @0x21d93c blx r3 */
/* @0x21d940 mvn r0, #0 */
/* @0x21d944 b 0x21d900 <_Z18Audio_CreateStreamPKc+0x224> */
/* @0x21d948 ldr r3, [r8, #0x4] */
/* @0x21d94c b 0x21d828 <_Z18Audio_CreateStreamPKc+0x14c> */
/* @0x21d950 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x21d954 add r3, r3, #299008 */
/* @0x21d958 add r10, r3, #992 */
/* @0x21d95c mov r0, #96 */
/* @0x21d960 bl 0x27c524 <_Znwj> */
/* @0x21d964 mov r9, r0 */
/* @0x21d968 bl 0x218ea4 <_ZN12cAudio_SoundC2Ev> */
/* @0x21d96c ldr r3, [r8, #0x4] */
/* @0x21d970 cmp r9, #0 */
/* @0x21d974 str r9, [r3, r4] */
/* @0x21d978 bne 0x21d8a4 <_Z18Audio_CreateStreamPKc+0x1c8> */
/* @0x21d97c b 0x21d76c <_Z18Audio_CreateStreamPKc+0x90> */
/* @0x21d980 movw r10, #0x93e0 */
/* @0x21d984 movt r10, #0x4 */
/* @0x21d988 b 0x21d95c <_Z18Audio_CreateStreamPKc+0x280> */
/* @0x21d98c andseq r4, sp, r12, asr r5 */
/* @0x21d990 .word 0xffffbd00 */
/* @0x21d994 .word 0xfffff788 */
/* @0x21d998 andseq pc, r2, r4, ror r10 */
/* @0x21d99c .word 0xffffbac4 */
/* @0x21d9a0 andseq r6, r3, r12, lsl sp */
/* @0x21d9a4 andseq r6, r3, r0, lsr #25 */

/* ── FUNC 0x21d9a8 · Audio_DestroyStream(int) · size=280 · insn=70 */
/* @0x21d9a8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x21d9ac movw r3, #0x93df */
/* @0x21d9b0 movt r3, #0x4 */
/* @0x21d9b4 mov r5, r0 */
/* @0x21d9b8 cmp r0, r3 */
/* @0x21d9bc ble 0x21d9d4 <_Z19Audio_DestroyStreami+0x2c> */
/* @0x21d9c0 ldr r3, [pc, #0xdc] */
/* @0x21d9c4 ldr r3, [pc, r3] */
/* @0x21d9c8 ldr r3, [r3] */
/* @0x21d9cc cmp r0, r3 */
/* @0x21d9d0 blt 0x21da00 <_Z19Audio_DestroyStreami+0x58> */
/* @0x21d9d4 ldr r3, [pc, #0xcc] */
/* @0x21d9d8 mov r2, r5 */
/* @0x21d9dc ldr r1, [pc, #0xc8] */
/* @0x21d9e0 ldr r3, [pc, r3] */
/* @0x21d9e4 add r1, pc, r1 */
/* @0x21d9e8 ldr r0, [r3] */
/* @0x21d9ec ldr r3, [r0] */
/* @0x21d9f0 ldr r3, [r3, #0xc] */
/* @0x21d9f4 blx r3 */
/* @0x21d9f8 mvn r0, #0 */
/* @0x21d9fc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21da00 ldr r3, [pc, #0xa8] */
/* @0x21da04 sub r2, r0, #299008 */
/* @0x21da08 sub r2, r2, #992 */
/* @0x21da0c ldr r3, [pc, r3] */
/* @0x21da10 ldr r1, [r3] */
/* @0x21da14 cmp r2, r1 */
/* @0x21da18 bge 0x21d9f8 <_Z19Audio_DestroyStreami+0x50> */
/* @0x21da1c ldr r3, [r3, #0x4] */
/* @0x21da20 ldr r7, [r3, r2, lsl #2] */
/* @0x21da24 cmp r7, #0 */
/* @0x21da28 beq 0x21d9f8 <_Z19Audio_DestroyStreami+0x50> */
/* @0x21da2c ldr r3, [pc, #0x80] */
/* @0x21da30 add r3, pc, r3 */
/* @0x21da34 ldr r6, [r3, #0x38] */
/* @0x21da38 cmp r6, #0 */
/* @0x21da3c ble 0x21da98 <_Z19Audio_DestroyStreami+0xf0> */
/* @0x21da40 ldr r9, [pc, #0x70] */
/* @0x21da44 mov r3, r6 */
/* @0x21da48 ldr r8, [pc, #0x6c] */
/* @0x21da4c mov r4, #0 */
/* @0x21da50 add r9, pc, r9 */
/* @0x21da54 add r8, pc, r8 */
/* @0x21da58 b 0x21da68 <_Z19Audio_DestroyStreami+0xc0> */
/* @0x21da5c cmp r4, r6 */
/* @0x21da60 beq 0x21da98 <_Z19Audio_DestroyStreami+0xf0> */
/* @0x21da64 ldr r3, [r8, #0x38] */
/* @0x21da68 cmp r4, r3 */
/* @0x21da6c mov r0, #0 */
/* @0x21da70 ldrlt r3, [r9, #0x3c] */
/* @0x21da74 ldrlt r0, [r3, r4, lsl #2] */
/* @0x21da78 add r4, r4, #1 */
/* @0x21da7c ldr r3, [r0, #0x18] */
/* @0x21da80 cmp r3, r5 */
/* @0x21da84 bne 0x21da5c <_Z19Audio_DestroyStreami+0xb4> */
/* @0x21da88 mov r1, #1 */
/* @0x21da8c bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb> */
/* @0x21da90 cmp r4, r6 */
/* @0x21da94 bne 0x21da64 <_Z19Audio_DestroyStreami+0xbc> */
/* @0x21da98 mov r0, #1 */
/* @0x21da9c strb r0, [r7, #0x27] */
/* @0x21daa0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21daa4 andseq r3, sp, r0, lsr #20 */
/* @0x21daa8 andseq pc, r12, r4, lsr sp */
/* @0x21daac andseq r6, r3, r12, lsr #24 */
/* @0x21dab0 andseq r3, sp, r12, asr #19 */
/* @0x21dab4 subseq r7, r3, r4, ror #16 */
/* @0x21dab8 subseq r7, r3, r4, asr #16 */
/* @0x21dabc subseq r7, r3, r0, asr #16 */

/* ── FUNC 0x21dac0 · Audio_GetDeviceName() · size=24 · insn=6 */
/* @0x21dac0 push {r3, lr} */
/* @0x21dac4 bl 0xb6a3c <alcGetCurrentContext@plt> */
/* @0x21dac8 bl 0xb6b98 <alcGetContextsDevice@plt> */
/* @0x21dacc movw r1, #0x1005 */
/* @0x21dad0 pop {r3, lr} */
/* @0x21dad4 b 0xb6b50 <alcGetString@plt> */

/* ── FUNC 0x21dad8 · CNoise::CNoise() · size=76 · insn=19 */
/* @0x21dad8 push {r4, lr} */
/* @0x21dadc mov r1, #0 */
/* @0x21dae0 mov r2, #60 */
/* @0x21dae4 mov r4, r0 */
/* @0x21dae8 bl 0xb65b0 <memset@plt> */
/* @0x21daec ldr r3, [pc, #0x2c] */
/* @0x21daf0 mov r2, #1065353216 */
/* @0x21daf4 mvn r1, #0 */
/* @0x21daf8 ldr r3, [pc, r3] */
/* @0x21dafc mov r0, r4 */
/* @0x21db00 str r1, [r4, #0x10] */
/* @0x21db04 ldr r3, [r3] */
/* @0x21db08 str r1, [r4, #0x30] */
/* @0x21db0c str r2, [r4, #0x1c] */
/* @0x21db10 str r3, [r4, #0x34] */
/* @0x21db14 str r2, [r4, #0x24] */
/* @0x21db18 str r2, [r4, #0x20] */
/* @0x21db1c pop {r4, pc} */
/* @0x21db20 ldrsbeq r3, [sp], -r0 */

/* ── FUNC 0x21dad8 · CNoise::CNoise() · alias of the symbol above · insn=0 */

/* ── FUNC 0x21db24 · CNoise::Clear() · size=4 · insn=1 */
/* @0x21db24 bx lr */

/* ── FUNC 0x21db28 · CNoise::~CNoise() · size=20 · insn=5 */
/* @0x21db28 push {r4, lr} */
/* @0x21db2c mov r4, r0 */
/* @0x21db30 bl 0x21db24 <_ZN6CNoise5ClearEv> */
/* @0x21db34 mov r0, r4 */
/* @0x21db38 pop {r4, pc} */

/* ── FUNC 0x21db28 · CNoise::~CNoise() · alias of the symbol above · insn=0 */

/* ── FUNC 0x21db3c · anon_21db3c · size=24 · insn=6 */
/* @0x21db3c push {r3, lr} */
/* @0x21db40 ldr r3, [r0, #0xc] */
/* @0x21db44 ldr r0, [r3, #0x4] */
/* @0x21db48 bl 0x219590 <_Z18Audio_PrepareGroupi> */
/* @0x21db4c mov r0, #0 */
/* @0x21db50 pop {r3, pc} */

/* ── FUNC 0x21db54 · CAudioGroup::CAudioGroup(int) · size=44 · insn=11 */
/* @0x21db54 mov r2, #0 */
/* @0x21db58 str r1, [r0, #0x4] */
/* @0x21db5c str r2, [r0, #0x18] */
/* @0x21db60 str r2, [r0] */
/* @0x21db64 str r2, [r0, #0x8] */
/* @0x21db68 str r2, [r0, #0xc] */
/* @0x21db6c str r2, [r0, #0x10] */
/* @0x21db70 str r2, [r0, #0x24] */
/* @0x21db74 str r2, [r0, #0x20] */
/* @0x21db78 str r2, [r0, #0x1c] */
/* @0x21db7c bx lr */
