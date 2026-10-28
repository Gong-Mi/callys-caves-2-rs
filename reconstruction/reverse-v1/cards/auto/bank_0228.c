/* libyoyo.so 覆盖卡组 0228
 * 函数 0x27b368..0x27b950，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x27b368 · CBucket<8u, 131072u, true>::Check() · size=124 · insn=31 */
/* @0x27b368 ldr r12, [r0, #0x8] */
/* @0x27b36c push {r4, r5, r6} */
/* @0x27b370 cmp r12, #0 */
/* @0x27b374 beq 0x27b3d8 <_ZN7CBucketILj8ELj131072ELb1EE5CheckEv+0x70> */
/* @0x27b378 ldr r4, [pc, #0x60] */
/* @0x27b37c mov r6, #0 */
/* @0x27b380 mov r5, #42 */
/* @0x27b384 ldr r4, [pc, r4] */
/* @0x27b388 ldr r3, [r0, #0x4] */
/* @0x27b38c cmp r3, #0 */
/* @0x27b390 beq 0x27b3bc <_ZN7CBucketILj8ELj131072ELb1EE5CheckEv+0x54> */
/* @0x27b394 add r1, r3, #8 */
/* @0x27b398 add r2, r3, #131072 */
/* @0x27b39c cmp r12, r1 */
/* @0x27b3a0 add r2, r2, #8 */
/* @0x27b3a4 blo 0x27b3b0 <_ZN7CBucketILj8ELj131072ELb1EE5CheckEv+0x48> */
/* @0x27b3a8 cmp r2, r12 */
/* @0x27b3ac bhi 0x27b3c0 <_ZN7CBucketILj8ELj131072ELb1EE5CheckEv+0x58> */
/* @0x27b3b0 ldr r3, [r3] */
/* @0x27b3b4 cmp r3, #0 */
/* @0x27b3b8 bne 0x27b394 <_ZN7CBucketILj8ELj131072ELb1EE5CheckEv+0x2c> */
/* @0x27b3bc str r5, [r6] */
/* @0x27b3c0 ldr r12, [r12] */
/* @0x27b3c4 ldr r3, [r4] */
/* @0x27b3c8 cmp r12, #0 */
/* @0x27b3cc add r3, r3, #1 */
/* @0x27b3d0 str r3, [r4] */
/* @0x27b3d4 bne 0x27b388 <_ZN7CBucketILj8ELj131072ELb1EE5CheckEv+0x20> */
/* @0x27b3d8 pop {r4, r5, r6} */
/* @0x27b3dc bx lr */
/* @0x27b3e0 andseq r2, r7, r0, asr #16 */

/* ── FUNC 0x27b3e4 · CBucket<16u, 262144u, true>::Check() · size=124 · insn=31 */
/* @0x27b3e4 ldr r12, [r0, #0x8] */
/* @0x27b3e8 push {r4, r5, r6} */
/* @0x27b3ec cmp r12, #0 */
/* @0x27b3f0 beq 0x27b454 <_ZN7CBucketILj16ELj262144ELb1EE5CheckEv+0x70> */
/* @0x27b3f4 ldr r4, [pc, #0x60] */
/* @0x27b3f8 mov r6, #0 */
/* @0x27b3fc mov r5, #42 */
/* @0x27b400 ldr r4, [pc, r4] */
/* @0x27b404 ldr r3, [r0, #0x4] */
/* @0x27b408 cmp r3, #0 */
/* @0x27b40c beq 0x27b438 <_ZN7CBucketILj16ELj262144ELb1EE5CheckEv+0x54> */
/* @0x27b410 add r1, r3, #8 */
/* @0x27b414 add r2, r3, #262144 */
/* @0x27b418 cmp r12, r1 */
/* @0x27b41c add r2, r2, #8 */
/* @0x27b420 blo 0x27b42c <_ZN7CBucketILj16ELj262144ELb1EE5CheckEv+0x48> */
/* @0x27b424 cmp r2, r12 */
/* @0x27b428 bhi 0x27b43c <_ZN7CBucketILj16ELj262144ELb1EE5CheckEv+0x58> */
/* @0x27b42c ldr r3, [r3] */
/* @0x27b430 cmp r3, #0 */
/* @0x27b434 bne 0x27b410 <_ZN7CBucketILj16ELj262144ELb1EE5CheckEv+0x2c> */
/* @0x27b438 str r5, [r6] */
/* @0x27b43c ldr r12, [r12] */
/* @0x27b440 ldr r3, [r4] */
/* @0x27b444 cmp r12, #0 */
/* @0x27b448 add r3, r3, #1 */
/* @0x27b44c str r3, [r4] */
/* @0x27b450 bne 0x27b404 <_ZN7CBucketILj16ELj262144ELb1EE5CheckEv+0x20> */
/* @0x27b454 pop {r4, r5, r6} */
/* @0x27b458 bx lr */
/* @0x27b45c andseq r2, r7, r4, asr #15 */

/* ── FUNC 0x27b460 · CBucket<32u, 262144u, true>::Check() · size=124 · insn=31 */
/* @0x27b460 ldr r12, [r0, #0x8] */
/* @0x27b464 push {r4, r5, r6} */
/* @0x27b468 cmp r12, #0 */
/* @0x27b46c beq 0x27b4d0 <_ZN7CBucketILj32ELj262144ELb1EE5CheckEv+0x70> */
/* @0x27b470 ldr r4, [pc, #0x60] */
/* @0x27b474 mov r6, #0 */
/* @0x27b478 mov r5, #42 */
/* @0x27b47c ldr r4, [pc, r4] */
/* @0x27b480 ldr r3, [r0, #0x4] */
/* @0x27b484 cmp r3, #0 */
/* @0x27b488 beq 0x27b4b4 <_ZN7CBucketILj32ELj262144ELb1EE5CheckEv+0x54> */
/* @0x27b48c add r1, r3, #8 */
/* @0x27b490 add r2, r3, #262144 */
/* @0x27b494 cmp r12, r1 */
/* @0x27b498 add r2, r2, #8 */
/* @0x27b49c blo 0x27b4a8 <_ZN7CBucketILj32ELj262144ELb1EE5CheckEv+0x48> */
/* @0x27b4a0 cmp r2, r12 */
/* @0x27b4a4 bhi 0x27b4b8 <_ZN7CBucketILj32ELj262144ELb1EE5CheckEv+0x58> */
/* @0x27b4a8 ldr r3, [r3] */
/* @0x27b4ac cmp r3, #0 */
/* @0x27b4b0 bne 0x27b48c <_ZN7CBucketILj32ELj262144ELb1EE5CheckEv+0x2c> */
/* @0x27b4b4 str r5, [r6] */
/* @0x27b4b8 ldr r12, [r12] */
/* @0x27b4bc ldr r3, [r4] */
/* @0x27b4c0 cmp r12, #0 */
/* @0x27b4c4 add r3, r3, #1 */
/* @0x27b4c8 str r3, [r4] */
/* @0x27b4cc bne 0x27b480 <_ZN7CBucketILj32ELj262144ELb1EE5CheckEv+0x20> */
/* @0x27b4d0 pop {r4, r5, r6} */
/* @0x27b4d4 bx lr */
/* @0x27b4d8 andseq r2, r7, r8, asr #14 */

/* ── FUNC 0x27b4dc · CBucket<64u, 524288u, true>::Check() · size=124 · insn=31 */
/* @0x27b4dc ldr r12, [r0, #0x8] */
/* @0x27b4e0 push {r4, r5, r6} */
/* @0x27b4e4 cmp r12, #0 */
/* @0x27b4e8 beq 0x27b54c <_ZN7CBucketILj64ELj524288ELb1EE5CheckEv+0x70> */
/* @0x27b4ec ldr r4, [pc, #0x60] */
/* @0x27b4f0 mov r6, #0 */
/* @0x27b4f4 mov r5, #42 */
/* @0x27b4f8 ldr r4, [pc, r4] */
/* @0x27b4fc ldr r3, [r0, #0x4] */
/* @0x27b500 cmp r3, #0 */
/* @0x27b504 beq 0x27b530 <_ZN7CBucketILj64ELj524288ELb1EE5CheckEv+0x54> */
/* @0x27b508 add r1, r3, #8 */
/* @0x27b50c add r2, r3, #524288 */
/* @0x27b510 cmp r12, r1 */
/* @0x27b514 add r2, r2, #8 */
/* @0x27b518 blo 0x27b524 <_ZN7CBucketILj64ELj524288ELb1EE5CheckEv+0x48> */
/* @0x27b51c cmp r2, r12 */
/* @0x27b520 bhi 0x27b534 <_ZN7CBucketILj64ELj524288ELb1EE5CheckEv+0x58> */
/* @0x27b524 ldr r3, [r3] */
/* @0x27b528 cmp r3, #0 */
/* @0x27b52c bne 0x27b508 <_ZN7CBucketILj64ELj524288ELb1EE5CheckEv+0x2c> */
/* @0x27b530 str r5, [r6] */
/* @0x27b534 ldr r12, [r12] */
/* @0x27b538 ldr r3, [r4] */
/* @0x27b53c cmp r12, #0 */
/* @0x27b540 add r3, r3, #1 */
/* @0x27b544 str r3, [r4] */
/* @0x27b548 bne 0x27b4fc <_ZN7CBucketILj64ELj524288ELb1EE5CheckEv+0x20> */
/* @0x27b54c pop {r4, r5, r6} */
/* @0x27b550 bx lr */
/* @0x27b554 andseq r2, r7, r12, asr #13 */

/* ── FUNC 0x27b558 · CBucket<128u, 524288u, true>::Check() · size=124 · insn=31 */
/* @0x27b558 ldr r12, [r0, #0x8] */
/* @0x27b55c push {r4, r5, r6} */
/* @0x27b560 cmp r12, #0 */
/* @0x27b564 beq 0x27b5c8 <_ZN7CBucketILj128ELj524288ELb1EE5CheckEv+0x70> */
/* @0x27b568 ldr r4, [pc, #0x60] */
/* @0x27b56c mov r6, #0 */
/* @0x27b570 mov r5, #42 */
/* @0x27b574 ldr r4, [pc, r4] */
/* @0x27b578 ldr r3, [r0, #0x4] */
/* @0x27b57c cmp r3, #0 */
/* @0x27b580 beq 0x27b5ac <_ZN7CBucketILj128ELj524288ELb1EE5CheckEv+0x54> */
/* @0x27b584 add r1, r3, #8 */
/* @0x27b588 add r2, r3, #524288 */
/* @0x27b58c cmp r12, r1 */
/* @0x27b590 add r2, r2, #8 */
/* @0x27b594 blo 0x27b5a0 <_ZN7CBucketILj128ELj524288ELb1EE5CheckEv+0x48> */
/* @0x27b598 cmp r2, r12 */
/* @0x27b59c bhi 0x27b5b0 <_ZN7CBucketILj128ELj524288ELb1EE5CheckEv+0x58> */
/* @0x27b5a0 ldr r3, [r3] */
/* @0x27b5a4 cmp r3, #0 */
/* @0x27b5a8 bne 0x27b584 <_ZN7CBucketILj128ELj524288ELb1EE5CheckEv+0x2c> */
/* @0x27b5ac str r5, [r6] */
/* @0x27b5b0 ldr r12, [r12] */
/* @0x27b5b4 ldr r3, [r4] */
/* @0x27b5b8 cmp r12, #0 */
/* @0x27b5bc add r3, r3, #1 */
/* @0x27b5c0 str r3, [r4] */
/* @0x27b5c4 bne 0x27b578 <_ZN7CBucketILj128ELj524288ELb1EE5CheckEv+0x20> */
/* @0x27b5c8 pop {r4, r5, r6} */
/* @0x27b5cc bx lr */
/* @0x27b5d0 andseq r2, r7, r0, asr r6 */

/* ── FUNC 0x27b5d4 · CBucket<256u, 1048576u, true>::Check() · size=124 · insn=31 */
/* @0x27b5d4 ldr r12, [r0, #0x8] */
/* @0x27b5d8 push {r4, r5, r6} */
/* @0x27b5dc cmp r12, #0 */
/* @0x27b5e0 beq 0x27b644 <_ZN7CBucketILj256ELj1048576ELb1EE5CheckEv+0x70> */
/* @0x27b5e4 ldr r4, [pc, #0x60] */
/* @0x27b5e8 mov r6, #0 */
/* @0x27b5ec mov r5, #42 */
/* @0x27b5f0 ldr r4, [pc, r4] */
/* @0x27b5f4 ldr r3, [r0, #0x4] */
/* @0x27b5f8 cmp r3, #0 */
/* @0x27b5fc beq 0x27b628 <_ZN7CBucketILj256ELj1048576ELb1EE5CheckEv+0x54> */
/* @0x27b600 add r1, r3, #8 */
/* @0x27b604 add r2, r3, #1048576 */
/* @0x27b608 cmp r12, r1 */
/* @0x27b60c add r2, r2, #8 */
/* @0x27b610 blo 0x27b61c <_ZN7CBucketILj256ELj1048576ELb1EE5CheckEv+0x48> */
/* @0x27b614 cmp r2, r12 */
/* @0x27b618 bhi 0x27b62c <_ZN7CBucketILj256ELj1048576ELb1EE5CheckEv+0x58> */
/* @0x27b61c ldr r3, [r3] */
/* @0x27b620 cmp r3, #0 */
/* @0x27b624 bne 0x27b600 <_ZN7CBucketILj256ELj1048576ELb1EE5CheckEv+0x2c> */
/* @0x27b628 str r5, [r6] */
/* @0x27b62c ldr r12, [r12] */
/* @0x27b630 ldr r3, [r4] */
/* @0x27b634 cmp r12, #0 */
/* @0x27b638 add r3, r3, #1 */
/* @0x27b63c str r3, [r4] */
/* @0x27b640 bne 0x27b5f4 <_ZN7CBucketILj256ELj1048576ELb1EE5CheckEv+0x20> */
/* @0x27b644 pop {r4, r5, r6} */
/* @0x27b648 bx lr */
/* @0x27b64c ldrsbeq r2, [r7], -r4 */

/* ── FUNC 0x27b650 · CBucket<8u, 131072u, true>::Init() · size=20 · insn=5 */
/* @0x27b650 mov r3, #0 */
/* @0x27b654 str r3, [r0, #0x4] */
/* @0x27b658 str r3, [r0, #0x8] */
/* @0x27b65c str r3, [r0, #0xc] */
/* @0x27b660 bx lr */

/* ── FUNC 0x27b664 · CBucket<16u, 262144u, true>::Init() · size=20 · insn=5 */
/* @0x27b664 mov r3, #0 */
/* @0x27b668 str r3, [r0, #0x4] */
/* @0x27b66c str r3, [r0, #0x8] */
/* @0x27b670 str r3, [r0, #0xc] */
/* @0x27b674 bx lr */

/* ── FUNC 0x27b678 · CBucket<32u, 262144u, true>::Init() · size=20 · insn=5 */
/* @0x27b678 mov r3, #0 */
/* @0x27b67c str r3, [r0, #0x4] */
/* @0x27b680 str r3, [r0, #0x8] */
/* @0x27b684 str r3, [r0, #0xc] */
/* @0x27b688 bx lr */

/* ── FUNC 0x27b68c · CBucket<64u, 524288u, true>::Init() · size=20 · insn=5 */
/* @0x27b68c mov r3, #0 */
/* @0x27b690 str r3, [r0, #0x4] */
/* @0x27b694 str r3, [r0, #0x8] */
/* @0x27b698 str r3, [r0, #0xc] */
/* @0x27b69c bx lr */

/* ── FUNC 0x27b6a0 · CBucket<128u, 524288u, true>::Init() · size=20 · insn=5 */
/* @0x27b6a0 mov r3, #0 */
/* @0x27b6a4 str r3, [r0, #0x4] */
/* @0x27b6a8 str r3, [r0, #0x8] */
/* @0x27b6ac str r3, [r0, #0xc] */
/* @0x27b6b0 bx lr */

/* ── FUNC 0x27b6b4 · CBucket<256u, 1048576u, true>::Init() · size=20 · insn=5 */
/* @0x27b6b4 mov r3, #0 */
/* @0x27b6b8 str r3, [r0, #0x4] */
/* @0x27b6bc str r3, [r0, #0x8] */
/* @0x27b6c0 str r3, [r0, #0xc] */
/* @0x27b6c4 bx lr */

/* ── FUNC 0x27b6c8 · CBucket<16384u, 262144u, true>::Init() · size=20 · insn=5 */
/* @0x27b6c8 mov r3, #0 */
/* @0x27b6cc str r3, [r0, #0x4] */
/* @0x27b6d0 str r3, [r0, #0x8] */
/* @0x27b6d4 str r3, [r0, #0xc] */
/* @0x27b6d8 bx lr */

/* ── FUNC 0x27b6dc · CBucket<16384u, 262144u, true>::Check() · size=124 · insn=31 */
/* @0x27b6dc ldr r12, [r0, #0x8] */
/* @0x27b6e0 push {r4, r5, r6} */
/* @0x27b6e4 cmp r12, #0 */
/* @0x27b6e8 beq 0x27b74c <_ZN7CBucketILj16384ELj262144ELb1EE5CheckEv+0x70> */
/* @0x27b6ec ldr r4, [pc, #0x60] */
/* @0x27b6f0 mov r6, #0 */
/* @0x27b6f4 mov r5, #42 */
/* @0x27b6f8 ldr r4, [pc, r4] */
/* @0x27b6fc ldr r3, [r0, #0x4] */
/* @0x27b700 cmp r3, #0 */
/* @0x27b704 beq 0x27b730 <_ZN7CBucketILj16384ELj262144ELb1EE5CheckEv+0x54> */
/* @0x27b708 add r1, r3, #8 */
/* @0x27b70c add r2, r3, #262144 */
/* @0x27b710 cmp r12, r1 */
/* @0x27b714 add r2, r2, #8 */
/* @0x27b718 blo 0x27b724 <_ZN7CBucketILj16384ELj262144ELb1EE5CheckEv+0x48> */
/* @0x27b71c cmp r2, r12 */
/* @0x27b720 bhi 0x27b734 <_ZN7CBucketILj16384ELj262144ELb1EE5CheckEv+0x58> */
/* @0x27b724 ldr r3, [r3] */
/* @0x27b728 cmp r3, #0 */
/* @0x27b72c bne 0x27b708 <_ZN7CBucketILj16384ELj262144ELb1EE5CheckEv+0x2c> */
/* @0x27b730 str r5, [r6] */
/* @0x27b734 ldr r12, [r12] */
/* @0x27b738 ldr r3, [r4] */
/* @0x27b73c cmp r12, #0 */
/* @0x27b740 add r3, r3, #1 */
/* @0x27b744 str r3, [r4] */
/* @0x27b748 bne 0x27b6fc <_ZN7CBucketILj16384ELj262144ELb1EE5CheckEv+0x20> */
/* @0x27b74c pop {r4, r5, r6} */
/* @0x27b750 bx lr */
/* @0x27b754 andseq r2, r7, r12, asr #9 */

/* ── FUNC 0x27b758 · CBucket<16384u, 262144u, true>::GetSize() · size=8 · insn=2 */
/* @0x27b758 mov r0, #16384 */
/* @0x27b75c bx lr */

/* ── FUNC 0x27b760 · CBucket<16384u, 262144u, true>::Free(void const*) · size=56 · insn=14 */
/* @0x27b760 mov r3, r0 */
/* @0x27b764 str r4, [sp, #-0x4]! */
/* @0x27b768 ldr r4, [r0, #0x8] */
/* @0x27b76c mov r0, #1 */
/* @0x27b770 ldr r12, [r3, #0x10] */
/* @0x27b774 ldr r2, [r3, #0xc] */
/* @0x27b778 add r12, r12, r0 */
/* @0x27b77c str r4, [r1] */
/* @0x27b780 sub r2, r2, #1 */
/* @0x27b784 str r1, [r3, #0x8] */
/* @0x27b788 str r12, [r3, #0x10] */
/* @0x27b78c str r2, [r3, #0xc] */
/* @0x27b790 ldr r4, [sp], #4 */
/* @0x27b794 bx lr */

/* ── FUNC 0x27b798 · CBucket<256u, 1048576u, true>::GetSize() · size=8 · insn=2 */
/* @0x27b798 mov r0, #256 */
/* @0x27b79c bx lr */

/* ── FUNC 0x27b7a0 · CBucket<256u, 1048576u, true>::Free(void const*) · size=56 · insn=14 */
/* @0x27b7a0 mov r3, r0 */
/* @0x27b7a4 str r4, [sp, #-0x4]! */
/* @0x27b7a8 ldr r4, [r0, #0x8] */
/* @0x27b7ac mov r0, #1 */
/* @0x27b7b0 ldr r12, [r3, #0x10] */
/* @0x27b7b4 ldr r2, [r3, #0xc] */
/* @0x27b7b8 add r12, r12, r0 */
/* @0x27b7bc str r4, [r1] */
/* @0x27b7c0 sub r2, r2, #1 */
/* @0x27b7c4 str r1, [r3, #0x8] */
/* @0x27b7c8 str r12, [r3, #0x10] */
/* @0x27b7cc str r2, [r3, #0xc] */
/* @0x27b7d0 ldr r4, [sp], #4 */
/* @0x27b7d4 bx lr */

/* ── FUNC 0x27b7d8 · CBucket<128u, 524288u, true>::GetSize() · size=8 · insn=2 */
/* @0x27b7d8 mov r0, #128 */
/* @0x27b7dc bx lr */

/* ── FUNC 0x27b7e0 · CBucket<128u, 524288u, true>::Free(void const*) · size=56 · insn=14 */
/* @0x27b7e0 mov r3, r0 */
/* @0x27b7e4 str r4, [sp, #-0x4]! */
/* @0x27b7e8 ldr r4, [r0, #0x8] */
/* @0x27b7ec mov r0, #1 */
/* @0x27b7f0 ldr r12, [r3, #0x10] */
/* @0x27b7f4 ldr r2, [r3, #0xc] */
/* @0x27b7f8 add r12, r12, r0 */
/* @0x27b7fc str r4, [r1] */
/* @0x27b800 sub r2, r2, #1 */
/* @0x27b804 str r1, [r3, #0x8] */
/* @0x27b808 str r12, [r3, #0x10] */
/* @0x27b80c str r2, [r3, #0xc] */
/* @0x27b810 ldr r4, [sp], #4 */
/* @0x27b814 bx lr */

/* ── FUNC 0x27b818 · CBucket<64u, 524288u, true>::GetSize() · size=8 · insn=2 */
/* @0x27b818 mov r0, #64 */
/* @0x27b81c bx lr */

/* ── FUNC 0x27b820 · CBucket<64u, 524288u, true>::Free(void const*) · size=56 · insn=14 */
/* @0x27b820 mov r3, r0 */
/* @0x27b824 str r4, [sp, #-0x4]! */
/* @0x27b828 ldr r4, [r0, #0x8] */
/* @0x27b82c mov r0, #1 */
/* @0x27b830 ldr r12, [r3, #0x10] */
/* @0x27b834 ldr r2, [r3, #0xc] */
/* @0x27b838 add r12, r12, r0 */
/* @0x27b83c str r4, [r1] */
/* @0x27b840 sub r2, r2, #1 */
/* @0x27b844 str r1, [r3, #0x8] */
/* @0x27b848 str r12, [r3, #0x10] */
/* @0x27b84c str r2, [r3, #0xc] */
/* @0x27b850 ldr r4, [sp], #4 */
/* @0x27b854 bx lr */

/* ── FUNC 0x27b858 · CBucket<32u, 262144u, true>::GetSize() · size=8 · insn=2 */
/* @0x27b858 mov r0, #32 */
/* @0x27b85c bx lr */

/* ── FUNC 0x27b860 · CBucket<32u, 262144u, true>::Free(void const*) · size=56 · insn=14 */
/* @0x27b860 mov r3, r0 */
/* @0x27b864 str r4, [sp, #-0x4]! */
/* @0x27b868 ldr r4, [r0, #0x8] */
/* @0x27b86c mov r0, #1 */
/* @0x27b870 ldr r12, [r3, #0x10] */
/* @0x27b874 ldr r2, [r3, #0xc] */
/* @0x27b878 add r12, r12, r0 */
/* @0x27b87c str r4, [r1] */
/* @0x27b880 sub r2, r2, #1 */
/* @0x27b884 str r1, [r3, #0x8] */
/* @0x27b888 str r12, [r3, #0x10] */
/* @0x27b88c str r2, [r3, #0xc] */
/* @0x27b890 ldr r4, [sp], #4 */
/* @0x27b894 bx lr */

/* ── FUNC 0x27b898 · CBucket<16u, 262144u, true>::GetSize() · size=8 · insn=2 */
/* @0x27b898 mov r0, #16 */
/* @0x27b89c bx lr */

/* ── FUNC 0x27b8a0 · CBucket<16u, 262144u, true>::Free(void const*) · size=56 · insn=14 */
/* @0x27b8a0 mov r3, r0 */
/* @0x27b8a4 str r4, [sp, #-0x4]! */
/* @0x27b8a8 ldr r4, [r0, #0x8] */
/* @0x27b8ac mov r0, #1 */
/* @0x27b8b0 ldr r12, [r3, #0x10] */
/* @0x27b8b4 ldr r2, [r3, #0xc] */
/* @0x27b8b8 add r12, r12, r0 */
/* @0x27b8bc str r4, [r1] */
/* @0x27b8c0 sub r2, r2, #1 */
/* @0x27b8c4 str r1, [r3, #0x8] */
/* @0x27b8c8 str r12, [r3, #0x10] */
/* @0x27b8cc str r2, [r3, #0xc] */
/* @0x27b8d0 ldr r4, [sp], #4 */
/* @0x27b8d4 bx lr */

/* ── FUNC 0x27b8d8 · CBucket<8u, 131072u, true>::GetSize() · size=8 · insn=2 */
/* @0x27b8d8 mov r0, #8 */
/* @0x27b8dc bx lr */

/* ── FUNC 0x27b8e0 · CBucket<8u, 131072u, true>::Free(void const*) · size=56 · insn=14 */
/* @0x27b8e0 mov r3, r0 */
/* @0x27b8e4 str r4, [sp, #-0x4]! */
/* @0x27b8e8 ldr r4, [r0, #0x8] */
/* @0x27b8ec mov r0, #1 */
/* @0x27b8f0 ldr r12, [r3, #0x10] */
/* @0x27b8f4 ldr r2, [r3, #0xc] */
/* @0x27b8f8 add r12, r12, r0 */
/* @0x27b8fc str r4, [r1] */
/* @0x27b900 sub r2, r2, #1 */
/* @0x27b904 str r1, [r3, #0x8] */
/* @0x27b908 str r12, [r3, #0x10] */
/* @0x27b90c str r2, [r3, #0xc] */
/* @0x27b910 ldr r4, [sp], #4 */
/* @0x27b914 bx lr */

/* ── FUNC 0x27b918 · anon_27b918 · size=48 · insn=12 */
/* @0x27b918 push {r3, lr} */
/* @0x27b91c mov r0, #8 */
/* @0x27b920 bl 0xb6544 <malloc@plt> */
/* @0x27b924 ldr r3, [pc, #0x14] */
/* @0x27b928 ldr r1, [pc, #0x14] */
/* @0x27b92c ldr r3, [pc, r3] */
/* @0x27b930 add r1, pc, r1 */
/* @0x27b934 str r0, [r3] */
/* @0x27b938 pop {r3, lr} */
/* @0x27b93c b 0x27e038 <_ZN5Mutex4InitEPKc> */
/* @0x27b940 ldrsheq r5, [r7], -r0 */
/* @0x27b944 andeq r0, sp, r12, lsr #25 */

/* ── FUNC 0x27b948 · memLogPushContext(char const*) · size=4 · insn=1 */
/* @0x27b948 bx lr */

/* ── FUNC 0x27b94c · memLogPopContext() · size=4 · insn=1 */
/* @0x27b94c bx lr */

/* ── FUNC 0x27b950 · iffLogGetName(char const*) · size=216 · insn=54 */
/* @0x27b950 push {r4, r5, r6, r7, r8, lr} */
/* @0x27b954 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x27b958 ldr r2, [pc, #0xc4] */
/* @0x27b95c ldr r2, [pc, r2] */
/* @0x27b960 ldr r1, [r2, #0x8] */
/* @0x27b964 ldr r7, [r2, #0x10] */
/* @0x27b968 bic r0, r0, #-2147483648 */
/* @0x27b96c and r3, r0, r1 */
/* @0x27b970 lsl r4, r3, #1 */
/* @0x27b974 add r12, r4, r3 */
/* @0x27b978 add r12, r7, r12, lsl #2 */
/* @0x27b97c ldr r12, [r12, #0x8] */
/* @0x27b980 cmp r12, #0 */
/* @0x27b984 beq 0x27b9f4 <_Z13iffLogGetNamePKc+0xa4> */
/* @0x27b988 cmp r0, r12 */
/* @0x27b98c beq 0x27ba04 <_Z13iffLogGetNamePKc+0xb4> */
/* @0x27b990 ldr r8, [r2] */
/* @0x27b994 and r12, r1, r12 */
/* @0x27b998 add r2, r3, r8 */
/* @0x27b99c rsb r12, r12, r2 */
/* @0x27b9a0 tst r12, r1 */
/* @0x27b9a4 bmi 0x27b9f4 <_Z13iffLogGetNamePKc+0xa4> */
/* @0x27b9a8 mov r12, #0 */
/* @0x27b9ac b 0x27b9c0 <_Z13iffLogGetNamePKc+0x70> */
/* @0x27b9b0 cmp r0, r2 */
/* @0x27b9b4 beq 0x27b9fc <_Z13iffLogGetNamePKc+0xac> */
/* @0x27b9b8 cmp r5, r12 */
/* @0x27b9bc blt 0x27b9f4 <_Z13iffLogGetNamePKc+0xa4> */
/* @0x27b9c0 add r3, r3, #1 */
/* @0x27b9c4 add r12, r12, #1 */
/* @0x27b9c8 and r3, r3, r1 */
/* @0x27b9cc add r6, r3, r8 */
/* @0x27b9d0 lsl r4, r3, #1 */
/* @0x27b9d4 add r2, r4, r3 */
/* @0x27b9d8 add r2, r7, r2, lsl #2 */
/* @0x27b9dc ldr r2, [r2, #0x8] */
/* @0x27b9e0 and r5, r1, r2 */
/* @0x27b9e4 cmp r2, #0 */
/* @0x27b9e8 rsb r5, r5, r6 */
/* @0x27b9ec and r5, r5, r1 */
/* @0x27b9f0 bne 0x27b9b0 <_Z13iffLogGetNamePKc+0x60> */
/* @0x27b9f4 mvn r0, #0 */
/* @0x27b9f8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x27b9fc cmn r3, #1 */
/* @0x27ba00 beq 0x27ba1c <_Z13iffLogGetNamePKc+0xcc> */
/* @0x27ba04 add r3, r4, r3 */
/* @0x27ba08 add r7, r7, r3, lsl #2 */
/* @0x27ba0c cmn r7, #4 */
/* @0x27ba10 beq 0x27b9f4 <_Z13iffLogGetNamePKc+0xa4> */
/* @0x27ba14 ldr r0, [r7, #0x4] */
/* @0x27ba18 pop {r4, r5, r6, r7, r8, pc} */
/* @0x27ba1c mov r0, r3 */
/* @0x27ba20 pop {r4, r5, r6, r7, r8, pc} */
/* @0x27ba24 andseq r5, r7, r4, asr #29 */
