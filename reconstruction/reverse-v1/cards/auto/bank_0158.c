/* libyoyo.so 覆盖卡组 0158
 * 函数 0x1d55f0..0x1d749c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1d55f0 · F_GestureRotateTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1d55f0 push {r4, lr} */
/* @0x1d55f4 mov r1, #0 */
/* @0x1d55f8 ldr r0, [sp, #0x8] */
/* @0x1d55fc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1d5600 vldr d7, [pc, #32] */
/* @0x1d5604 ldr r4, [pc, #0x24] */
/* @0x1d5608 ldr r4, [pc, r4] */
/* @0x1d560c vmov d6, r0, r1 */
/* @0x1d5610 vmul.f64 d6, d6, d7 */
/* @0x1d5614 vmov r0, r1, d6 */
/* @0x1d5618 bl 0x3194a0 <__fixdfdi> */
/* @0x1d561c strd r0, r1, [r4] */
/* @0x1d5620 pop {r4, pc} */
/* @0x1d5624 nop */
/* @0x1d5628 andeq r0, r0, r0 */
/* @0x1d562c smlawbmi lr, r0, r4, r8 */
/* @0x1d5630 .word 0x0021b5dc */

/* ── FUNC 0x1d5634 · anon_1d5634 · size=0 · insn=1 */
/* @0x1d5634 nop */

/* ── FUNC 0x1d5638 · F_GestureDragDistance(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1d5638 push {r3, lr} */
/* @0x1d563c mov r1, #0 */
/* @0x1d5640 ldr r0, [sp, #0x8] */
/* @0x1d5644 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1d5648 ldr r3, [pc, #0x8] */
/* @0x1d564c ldr r3, [pc, r3] */
/* @0x1d5650 str r0, [r3] */
/* @0x1d5654 pop {r3, pc} */
/* @0x1d5658 eoreq r11, r1, r12, ror r5 */

/* ── FUNC 0x1d565c · F_GestureFlickSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1d565c push {r3, lr} */
/* @0x1d5660 mov r1, #0 */
/* @0x1d5664 ldr r0, [sp, #0x8] */
/* @0x1d5668 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1d566c ldr r3, [pc, #0x8] */
/* @0x1d5670 ldr r3, [pc, r3] */
/* @0x1d5674 str r0, [r3] */
/* @0x1d5678 pop {r3, pc} */
/* @0x1d567c eoreq r11, r1, r12, asr r5 */

/* ── FUNC 0x1d5680 · F_GestureDoubleTapDistance(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1d5680 push {r3, lr} */
/* @0x1d5684 mov r1, #0 */
/* @0x1d5688 ldr r0, [sp, #0x8] */
/* @0x1d568c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1d5690 ldr r3, [pc, #0x8] */
/* @0x1d5694 ldr r3, [pc, r3] */
/* @0x1d5698 str r0, [r3] */
/* @0x1d569c pop {r3, pc} */
/* @0x1d56a0 eoreq r11, r1, r0, asr #10 */

/* ── FUNC 0x1d56a4 · F_GesturePinchDistance(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1d56a4 push {r3, lr} */
/* @0x1d56a8 mov r1, #0 */
/* @0x1d56ac ldr r0, [sp, #0x8] */
/* @0x1d56b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1d56b4 ldr r3, [pc, #0x8] */
/* @0x1d56b8 ldr r3, [pc, r3] */
/* @0x1d56bc str r0, [r3] */
/* @0x1d56c0 pop {r3, pc} */
/* @0x1d56c4 eoreq r11, r1, r0, lsr #10 */

/* ── FUNC 0x1d56c8 · F_GesturePinchAngleTowards(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1d56c8 push {r3, lr} */
/* @0x1d56cc mov r1, #0 */
/* @0x1d56d0 ldr r0, [sp, #0x8] */
/* @0x1d56d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1d56d8 ldr r3, [pc, #0x8] */
/* @0x1d56dc ldr r3, [pc, r3] */
/* @0x1d56e0 str r0, [r3] */
/* @0x1d56e4 pop {r3, pc} */
/* @0x1d56e8 eoreq r11, r1, r0, lsl #10 */

/* ── FUNC 0x1d56ec · F_GesturePinchAngleAway(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1d56ec push {r3, lr} */
/* @0x1d56f0 mov r1, #0 */
/* @0x1d56f4 ldr r0, [sp, #0x8] */
/* @0x1d56f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1d56fc ldr r3, [pc, #0x8] */
/* @0x1d5700 ldr r3, [pc, r3] */
/* @0x1d5704 str r0, [r3] */
/* @0x1d5708 pop {r3, pc} */
/* @0x1d570c eoreq r11, r1, r0, ror #9 */

/* ── FUNC 0x1d5710 · F_GestureRotateAngle(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1d5710 push {r3, lr} */
/* @0x1d5714 mov r1, #0 */
/* @0x1d5718 ldr r0, [sp, #0x8] */
/* @0x1d571c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1d5720 ldr r3, [pc, #0x8] */
/* @0x1d5724 ldr r3, [pc, r3] */
/* @0x1d5728 str r0, [r3] */
/* @0x1d572c pop {r3, pc} */
/* @0x1d5730 eoreq r11, r1, r4, asr #9 */

/* ── FUNC 0x1d5734 · F_GestureTapCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1d5734 push {r3, lr} */
/* @0x1d5738 mov r1, #0 */
/* @0x1d573c ldr r0, [sp, #0x8] */
/* @0x1d5740 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1d5744 ldr r3, [pc, #0x8] */
/* @0x1d5748 ldr r3, [pc, r3] */
/* @0x1d574c strb r0, [r3] */
/* @0x1d5750 pop {r3, pc} */
/* @0x1d5754 eoreq r11, r1, r4, lsr #9 */

/* ── FUNC 0x1d5758 · SLinkedList<CTouchAction>::~SLinkedList() · size=76 · insn=19 */
/* @0x1d5758 push {r4, r5, r6, lr} */
/* @0x1d575c mov r6, r0 */
/* @0x1d5760 ldr r4, [r0] */
/* @0x1d5764 cmp r4, #0 */
/* @0x1d5768 beq 0x1d578c <_ZN11SLinkedListI12CTouchActionED2Ev+0x34> */
/* @0x1d576c ldr r5, [r4] */
/* @0x1d5770 ldr r0, [r4, #0x8] */
/* @0x1d5774 bl 0x27d1d0 <_ZdlPv> */
/* @0x1d5778 mov r0, r4 */
/* @0x1d577c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d5780 cmp r5, #0 */
/* @0x1d5784 mov r4, r5 */
/* @0x1d5788 bne 0x1d576c <_ZN11SLinkedListI12CTouchActionED2Ev+0x14> */
/* @0x1d578c mov r3, #0 */
/* @0x1d5790 mov r0, r6 */
/* @0x1d5794 str r3, [r6, #0x8] */
/* @0x1d5798 str r3, [r6, #0x4] */
/* @0x1d579c str r3, [r6] */
/* @0x1d57a0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1d5758 · SLinkedList<CTouchAction>::~SLinkedList() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d57a4 · SLinkedList<CGesture>::~SLinkedList() · size=96 · insn=24 */
/* @0x1d57a4 push {r4, r5, r6, lr} */
/* @0x1d57a8 mov r6, r0 */
/* @0x1d57ac ldr r4, [r0] */
/* @0x1d57b0 cmp r4, #0 */
/* @0x1d57b4 beq 0x1d57ec <_ZN11SLinkedListI8CGestureED2Ev+0x48> */
/* @0x1d57b8 ldr r3, [r4, #0x8] */
/* @0x1d57bc ldr r5, [r4] */
/* @0x1d57c0 cmp r3, #0 */
/* @0x1d57c4 mov r0, r3 */
/* @0x1d57c8 beq 0x1d57d8 <_ZN11SLinkedListI8CGestureED2Ev+0x34> */
/* @0x1d57cc ldr r3, [r3] */
/* @0x1d57d0 ldr r3, [r3, #0x4] */
/* @0x1d57d4 blx r3 */
/* @0x1d57d8 mov r0, r4 */
/* @0x1d57dc mov r4, r5 */
/* @0x1d57e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d57e4 cmp r5, #0 */
/* @0x1d57e8 bne 0x1d57b8 <_ZN11SLinkedListI8CGestureED2Ev+0x14> */
/* @0x1d57ec mov r3, #0 */
/* @0x1d57f0 mov r0, r6 */
/* @0x1d57f4 str r3, [r6, #0x8] */
/* @0x1d57f8 str r3, [r6, #0x4] */
/* @0x1d57fc str r3, [r6] */
/* @0x1d5800 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1d57a4 · SLinkedList<CGesture>::~SLinkedList() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1d5804 · HandleKey(int) · size=368 · insn=92 */
/* @0x1d5804 ldr r1, [pc, #0x154] */
/* @0x1d5808 ldr r3, [pc, #0x154] */
/* @0x1d580c add r1, pc, r1 */
/* @0x1d5810 ldr r12, [pc, #0x150] */
/* @0x1d5814 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d5818 add r9, r0, #1280 */
/* @0x1d581c mov r8, r0 */
/* @0x1d5820 ldr r0, [r1, r3] */
/* @0x1d5824 sub sp, sp, #28 */
/* @0x1d5828 ldrd r10, r11, [r0] */
/* @0x1d582c adds r2, r10, #1 */
/* @0x1d5830 adc r3, r11, #0 */
/* @0x1d5834 strd r10, r11, [sp, #8] */
/* @0x1d5838 strd r2, r3, [r0] */
/* @0x1d583c ldr r11, [r1, r12] */
/* @0x1d5840 ldr r3, [r11, r9, lsl #2] */
/* @0x1d5844 cmp r3, #0 */
/* @0x1d5848 ble 0x1d5958 <_Z9HandleKeyi+0x154> */
/* @0x1d584c ldr r2, [pc, #0x118] */
/* @0x1d5850 mov r7, #0 */
/* @0x1d5854 ldr r3, [pc, #0x114] */
/* @0x1d5858 ldr r10, [r1, r2] */
/* @0x1d585c ldr r3, [r1, r3] */
/* @0x1d5860 add r10, r10, r9, lsl #3 */
/* @0x1d5864 str r3, [sp, #0x14] */
/* @0x1d5868 mov r3, r10 */
/* @0x1d586c mov r10, r11 */
/* @0x1d5870 mov r11, r3 */
/* @0x1d5874 ldr r12, [sp, #0x14] */
/* @0x1d5878 ldr r1, [r11, #0x4] */
/* @0x1d587c ldr r3, [r12] */
/* @0x1d5880 ldr r1, [r1, r7, lsl #2] */
/* @0x1d5884 ldr r2, [r3, #0x4] */
/* @0x1d5888 ldr r3, [r3] */
/* @0x1d588c and r2, r1, r2 */
/* @0x1d5890 ldr r3, [r3, r2, lsl #3] */
/* @0x1d5894 cmp r3, #0 */
/* @0x1d5898 bne 0x1d58ac <_Z9HandleKeyi+0xa8> */
/* @0x1d589c b 0x1d5948 <_Z9HandleKeyi+0x144> */
/* @0x1d58a0 ldr r3, [r3, #0x4] */
/* @0x1d58a4 cmp r3, #0 */
/* @0x1d58a8 beq 0x1d5948 <_Z9HandleKeyi+0x144> */
/* @0x1d58ac ldr r2, [r3, #0x8] */
/* @0x1d58b0 cmp r1, r2 */
/* @0x1d58b4 bne 0x1d58a0 <_Z9HandleKeyi+0x9c> */
/* @0x1d58b8 ldr r3, [r3, #0xc] */
/* @0x1d58bc cmp r3, #0 */
/* @0x1d58c0 beq 0x1d5948 <_Z9HandleKeyi+0x144> */
/* @0x1d58c4 ldr r6, [r3, #0xc4] */
/* @0x1d58c8 cmp r6, #0 */
/* @0x1d58cc beq 0x1d5948 <_Z9HandleKeyi+0x144> */
/* @0x1d58d0 ldr r3, [r6, #0x8] */
/* @0x1d58d4 cmp r3, #0 */
/* @0x1d58d8 beq 0x1d5948 <_Z9HandleKeyi+0x144> */
/* @0x1d58dc str r10, [sp, #0x10] */
/* @0x1d58e0 str r11, [sp, #0x4] */
/* @0x1d58e4 b 0x1d58f4 <_Z9HandleKeyi+0xf0> */
/* @0x1d58e8 ldr r3, [r6, #0x8] */
/* @0x1d58ec cmp r3, #0 */
/* @0x1d58f0 beq 0x1d5940 <_Z9HandleKeyi+0x13c> */
/* @0x1d58f4 ldr r0, [r6, #0x8] */
/* @0x1d58f8 ldr r6, [r6] */
/* @0x1d58fc ldrb r3, [r0, #0x68] */
/* @0x1d5900 cmp r3, #0 */
/* @0x1d5904 bne 0x1d5938 <_Z9HandleKeyi+0x134> */
/* @0x1d5908 ldrb r3, [r0, #0x69] */
/* @0x1d590c cmp r3, #0 */
/* @0x1d5910 bne 0x1d5938 <_Z9HandleKeyi+0x134> */
/* @0x1d5914 ldrd r4, r5, [r0, #112] */
/* @0x1d5918 mov r1, r0 */
/* @0x1d591c ldrd r10, r11, [sp, #8] */
/* @0x1d5920 mov r2, #5 */
/* @0x1d5924 mov r3, r8 */
/* @0x1d5928 cmp r10, r4 */
/* @0x1d592c sbcs r11, r11, r5 */
/* @0x1d5930 blt 0x1d5938 <_Z9HandleKeyi+0x134> */
/* @0x1d5934 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d5938 cmp r6, #0 */
/* @0x1d593c bne 0x1d58e8 <_Z9HandleKeyi+0xe4> */
/* @0x1d5940 ldr r10, [sp, #0x10] */
/* @0x1d5944 ldr r11, [sp, #0x4] */
/* @0x1d5948 ldr r3, [r10, r9, lsl #2] */
/* @0x1d594c add r7, r7, #1 */
/* @0x1d5950 cmp r3, r7 */
/* @0x1d5954 bgt 0x1d5874 <_Z9HandleKeyi+0x70> */
/* @0x1d5958 add sp, sp, #28 */
/* @0x1d595c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d5960 eoreq r12, r1, r4, asr #8 */
/* @0x1d5964 .word 0xffffdeb4 */
/* @0x1d5968 .word 0xffffdeb8 */
/* @0x1d596c .word 0xffffdebc */
/* @0x1d5970 .word 0xffffbfec */

/* ── FUNC 0x1d5974 · HandleKeyPress(int) · size=356 · insn=89 */
/* @0x1d5974 ldr r1, [pc, #0x148] */
/* @0x1d5978 ldr r3, [pc, #0x148] */
/* @0x1d597c add r1, pc, r1 */
/* @0x1d5980 ldr r12, [pc, #0x144] */
/* @0x1d5984 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d5988 add r9, r0, #2304 */
/* @0x1d598c mov r8, r0 */
/* @0x1d5990 ldr r0, [r1, r3] */
/* @0x1d5994 sub sp, sp, #28 */
/* @0x1d5998 ldrd r10, r11, [r0] */
/* @0x1d599c adds r2, r10, #1 */
/* @0x1d59a0 adc r3, r11, #0 */
/* @0x1d59a4 strd r10, r11, [sp, #8] */
/* @0x1d59a8 strd r2, r3, [r0] */
/* @0x1d59ac ldr r11, [r1, r12] */
/* @0x1d59b0 ldr r3, [r11, r9, lsl #2] */
/* @0x1d59b4 cmp r3, #0 */
/* @0x1d59b8 ble 0x1d5abc <_Z14HandleKeyPressi+0x148> */
/* @0x1d59bc ldr r2, [pc, #0x10c] */
/* @0x1d59c0 mov r7, #0 */
/* @0x1d59c4 ldr r3, [pc, #0x108] */
/* @0x1d59c8 ldr r10, [r1, r2] */
/* @0x1d59cc ldr r3, [r1, r3] */
/* @0x1d59d0 add r10, r10, r9, lsl #3 */
/* @0x1d59d4 str r3, [sp, #0x14] */
/* @0x1d59d8 ldr r12, [sp, #0x14] */
/* @0x1d59dc ldr r1, [r10, #0x4] */
/* @0x1d59e0 ldr r3, [r12] */
/* @0x1d59e4 ldr r1, [r1, r7, lsl #2] */
/* @0x1d59e8 ldr r2, [r3, #0x4] */
/* @0x1d59ec ldr r3, [r3] */
/* @0x1d59f0 and r2, r1, r2 */
/* @0x1d59f4 ldr r3, [r3, r2, lsl #3] */
/* @0x1d59f8 cmp r3, #0 */
/* @0x1d59fc bne 0x1d5a10 <_Z14HandleKeyPressi+0x9c> */
/* @0x1d5a00 b 0x1d5aac <_Z14HandleKeyPressi+0x138> */
/* @0x1d5a04 ldr r3, [r3, #0x4] */
/* @0x1d5a08 cmp r3, #0 */
/* @0x1d5a0c beq 0x1d5aac <_Z14HandleKeyPressi+0x138> */
/* @0x1d5a10 ldr r2, [r3, #0x8] */
/* @0x1d5a14 cmp r1, r2 */
/* @0x1d5a18 bne 0x1d5a04 <_Z14HandleKeyPressi+0x90> */
/* @0x1d5a1c ldr r3, [r3, #0xc] */
/* @0x1d5a20 cmp r3, #0 */
/* @0x1d5a24 beq 0x1d5aac <_Z14HandleKeyPressi+0x138> */
/* @0x1d5a28 ldr r6, [r3, #0xc4] */
/* @0x1d5a2c cmp r6, #0 */
/* @0x1d5a30 beq 0x1d5aac <_Z14HandleKeyPressi+0x138> */
/* @0x1d5a34 ldr r3, [r6, #0x8] */
/* @0x1d5a38 cmp r3, #0 */
/* @0x1d5a3c beq 0x1d5aac <_Z14HandleKeyPressi+0x138> */
/* @0x1d5a40 str r11, [sp, #0x10] */
/* @0x1d5a44 str r10, [sp, #0x4] */
/* @0x1d5a48 b 0x1d5a58 <_Z14HandleKeyPressi+0xe4> */
/* @0x1d5a4c ldr r3, [r6, #0x8] */
/* @0x1d5a50 cmp r3, #0 */
/* @0x1d5a54 beq 0x1d5aa4 <_Z14HandleKeyPressi+0x130> */
/* @0x1d5a58 ldr r0, [r6, #0x8] */
/* @0x1d5a5c ldr r6, [r6] */
/* @0x1d5a60 ldrb r3, [r0, #0x68] */
/* @0x1d5a64 cmp r3, #0 */
/* @0x1d5a68 bne 0x1d5a9c <_Z14HandleKeyPressi+0x128> */
/* @0x1d5a6c ldrb r3, [r0, #0x69] */
/* @0x1d5a70 cmp r3, #0 */
/* @0x1d5a74 bne 0x1d5a9c <_Z14HandleKeyPressi+0x128> */
/* @0x1d5a78 ldrd r4, r5, [r0, #112] */
/* @0x1d5a7c mov r1, r0 */
/* @0x1d5a80 ldrd r10, r11, [sp, #8] */
/* @0x1d5a84 mov r2, #9 */
/* @0x1d5a88 mov r3, r8 */
/* @0x1d5a8c cmp r10, r4 */
/* @0x1d5a90 sbcs r11, r11, r5 */
/* @0x1d5a94 blt 0x1d5a9c <_Z14HandleKeyPressi+0x128> */
/* @0x1d5a98 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d5a9c cmp r6, #0 */
/* @0x1d5aa0 bne 0x1d5a4c <_Z14HandleKeyPressi+0xd8> */
/* @0x1d5aa4 ldr r11, [sp, #0x10] */
/* @0x1d5aa8 ldr r10, [sp, #0x4] */
/* @0x1d5aac ldr r3, [r11, r9, lsl #2] */
/* @0x1d5ab0 add r7, r7, #1 */
/* @0x1d5ab4 cmp r3, r7 */
/* @0x1d5ab8 bgt 0x1d59d8 <_Z14HandleKeyPressi+0x64> */
/* @0x1d5abc add sp, sp, #28 */
/* @0x1d5ac0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d5ac4 .word 0x0021c2d4 */
/* @0x1d5ac8 .word 0xffffdeb4 */
/* @0x1d5acc .word 0xffffdeb8 */
/* @0x1d5ad0 .word 0xffffdebc */
/* @0x1d5ad4 .word 0xffffbfec */

/* ── FUNC 0x1d5ad8 · HandleKeyRelease(int) · size=356 · insn=89 */
/* @0x1d5ad8 ldr r1, [pc, #0x148] */
/* @0x1d5adc ldr r3, [pc, #0x148] */
/* @0x1d5ae0 add r1, pc, r1 */
/* @0x1d5ae4 ldr r12, [pc, #0x144] */
/* @0x1d5ae8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d5aec add r9, r0, #2560 */
/* @0x1d5af0 mov r8, r0 */
/* @0x1d5af4 ldr r0, [r1, r3] */
/* @0x1d5af8 sub sp, sp, #28 */
/* @0x1d5afc ldrd r10, r11, [r0] */
/* @0x1d5b00 adds r2, r10, #1 */
/* @0x1d5b04 adc r3, r11, #0 */
/* @0x1d5b08 strd r10, r11, [sp, #8] */
/* @0x1d5b0c strd r2, r3, [r0] */
/* @0x1d5b10 ldr r11, [r1, r12] */
/* @0x1d5b14 ldr r3, [r11, r9, lsl #2] */
/* @0x1d5b18 cmp r3, #0 */
/* @0x1d5b1c ble 0x1d5c20 <_Z16HandleKeyReleasei+0x148> */
/* @0x1d5b20 ldr r2, [pc, #0x10c] */
/* @0x1d5b24 mov r7, #0 */
/* @0x1d5b28 ldr r3, [pc, #0x108] */
/* @0x1d5b2c ldr r10, [r1, r2] */
/* @0x1d5b30 ldr r3, [r1, r3] */
/* @0x1d5b34 add r10, r10, r9, lsl #3 */
/* @0x1d5b38 str r3, [sp, #0x14] */
/* @0x1d5b3c ldr r12, [sp, #0x14] */
/* @0x1d5b40 ldr r1, [r10, #0x4] */
/* @0x1d5b44 ldr r3, [r12] */
/* @0x1d5b48 ldr r1, [r1, r7, lsl #2] */
/* @0x1d5b4c ldr r2, [r3, #0x4] */
/* @0x1d5b50 ldr r3, [r3] */
/* @0x1d5b54 and r2, r1, r2 */
/* @0x1d5b58 ldr r3, [r3, r2, lsl #3] */
/* @0x1d5b5c cmp r3, #0 */
/* @0x1d5b60 bne 0x1d5b74 <_Z16HandleKeyReleasei+0x9c> */
/* @0x1d5b64 b 0x1d5c10 <_Z16HandleKeyReleasei+0x138> */
/* @0x1d5b68 ldr r3, [r3, #0x4] */
/* @0x1d5b6c cmp r3, #0 */
/* @0x1d5b70 beq 0x1d5c10 <_Z16HandleKeyReleasei+0x138> */
/* @0x1d5b74 ldr r2, [r3, #0x8] */
/* @0x1d5b78 cmp r1, r2 */
/* @0x1d5b7c bne 0x1d5b68 <_Z16HandleKeyReleasei+0x90> */
/* @0x1d5b80 ldr r3, [r3, #0xc] */
/* @0x1d5b84 cmp r3, #0 */
/* @0x1d5b88 beq 0x1d5c10 <_Z16HandleKeyReleasei+0x138> */
/* @0x1d5b8c ldr r6, [r3, #0xc4] */
/* @0x1d5b90 cmp r6, #0 */
/* @0x1d5b94 beq 0x1d5c10 <_Z16HandleKeyReleasei+0x138> */
/* @0x1d5b98 ldr r3, [r6, #0x8] */
/* @0x1d5b9c cmp r3, #0 */
/* @0x1d5ba0 beq 0x1d5c10 <_Z16HandleKeyReleasei+0x138> */
/* @0x1d5ba4 str r11, [sp, #0x10] */
/* @0x1d5ba8 str r10, [sp, #0x4] */
/* @0x1d5bac b 0x1d5bbc <_Z16HandleKeyReleasei+0xe4> */
/* @0x1d5bb0 ldr r3, [r6, #0x8] */
/* @0x1d5bb4 cmp r3, #0 */
/* @0x1d5bb8 beq 0x1d5c08 <_Z16HandleKeyReleasei+0x130> */
/* @0x1d5bbc ldr r0, [r6, #0x8] */
/* @0x1d5bc0 ldr r6, [r6] */
/* @0x1d5bc4 ldrb r3, [r0, #0x68] */
/* @0x1d5bc8 cmp r3, #0 */
/* @0x1d5bcc bne 0x1d5c00 <_Z16HandleKeyReleasei+0x128> */
/* @0x1d5bd0 ldrb r3, [r0, #0x69] */
/* @0x1d5bd4 cmp r3, #0 */
/* @0x1d5bd8 bne 0x1d5c00 <_Z16HandleKeyReleasei+0x128> */
/* @0x1d5bdc ldrd r4, r5, [r0, #112] */
/* @0x1d5be0 mov r1, r0 */
/* @0x1d5be4 ldrd r10, r11, [sp, #8] */
/* @0x1d5be8 mov r2, #10 */
/* @0x1d5bec mov r3, r8 */
/* @0x1d5bf0 cmp r10, r4 */
/* @0x1d5bf4 sbcs r11, r11, r5 */
/* @0x1d5bf8 blt 0x1d5c00 <_Z16HandleKeyReleasei+0x128> */
/* @0x1d5bfc bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d5c00 cmp r6, #0 */
/* @0x1d5c04 bne 0x1d5bb0 <_Z16HandleKeyReleasei+0xd8> */
/* @0x1d5c08 ldr r11, [sp, #0x10] */
/* @0x1d5c0c ldr r10, [sp, #0x4] */
/* @0x1d5c10 ldr r3, [r11, r9, lsl #2] */
/* @0x1d5c14 add r7, r7, #1 */
/* @0x1d5c18 cmp r3, r7 */
/* @0x1d5c1c bgt 0x1d5b3c <_Z16HandleKeyReleasei+0x64> */
/* @0x1d5c20 add sp, sp, #28 */
/* @0x1d5c24 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d5c28 eoreq r12, r1, r0, ror r1 */
/* @0x1d5c2c .word 0xffffdeb4 */
/* @0x1d5c30 .word 0xffffdeb8 */
/* @0x1d5c34 .word 0xffffdebc */
/* @0x1d5c38 .word 0xffffbfec */

/* ── FUNC 0x1d5c3c · HandleKeyboard() · size=196 · insn=49 */
/* @0x1d5c3c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1d5c40 mov r9, #0 */
/* @0x1d5c44 ldr r7, [pc, #0xa8] */
/* @0x1d5c48 mov r8, r9 */
/* @0x1d5c4c ldr r5, [pc, #0xa4] */
/* @0x1d5c50 mov r10, r9 */
/* @0x1d5c54 ldr r6, [pc, #0xa0] */
/* @0x1d5c58 ldr r7, [pc, r7] */
/* @0x1d5c5c ldr r5, [pc, r5] */
/* @0x1d5c60 mov r4, #8 */
/* @0x1d5c64 ldr r6, [pc, r6] */
/* @0x1d5c68 b 0x1d5c78 <_Z14HandleKeyboardv+0x3c> */
/* @0x1d5c6c add r4, r4, #1 */
/* @0x1d5c70 cmp r4, #256 */
/* @0x1d5c74 beq 0x1d5cd8 <_Z14HandleKeyboardv+0x9c> */
/* @0x1d5c78 ldrb r3, [r7, r4] */
/* @0x1d5c7c mov r0, r4 */
/* @0x1d5c80 cmp r3, #0 */
/* @0x1d5c84 bne 0x1d5c94 <_Z14HandleKeyboardv+0x58> */
/* @0x1d5c88 ldrb r3, [r5, r4] */
/* @0x1d5c8c cmp r3, #0 */
/* @0x1d5c90 beq 0x1d5cb4 <_Z14HandleKeyboardv+0x78> */
/* @0x1d5c94 bl 0x1d5804 <_Z9HandleKeyi> */
/* @0x1d5c98 ldrb r3, [r5, r4] */
/* @0x1d5c9c mov r0, r4 */
/* @0x1d5ca0 mov r10, #1 */
/* @0x1d5ca4 cmp r3, #0 */
/* @0x1d5ca8 beq 0x1d5cb4 <_Z14HandleKeyboardv+0x78> */
/* @0x1d5cac mov r8, r10 */
/* @0x1d5cb0 bl 0x1d5974 <_Z14HandleKeyPressi> */
/* @0x1d5cb4 ldrb r3, [r6, r4] */
/* @0x1d5cb8 cmp r3, #0 */
/* @0x1d5cbc beq 0x1d5c6c <_Z14HandleKeyboardv+0x30> */
/* @0x1d5cc0 mov r0, r4 */
/* @0x1d5cc4 add r4, r4, #1 */
/* @0x1d5cc8 bl 0x1d5ad8 <_Z16HandleKeyReleasei> */
/* @0x1d5ccc cmp r4, #256 */
/* @0x1d5cd0 mov r9, #1 */
/* @0x1d5cd4 bne 0x1d5c78 <_Z14HandleKeyboardv+0x3c> */
/* @0x1d5cd8 mov r0, r10 */
/* @0x1d5cdc bl 0x1d5804 <_Z9HandleKeyi> */
/* @0x1d5ce0 mov r0, r8 */
/* @0x1d5ce4 bl 0x1d5974 <_Z14HandleKeyPressi> */
/* @0x1d5ce8 mov r0, r9 */
/* @0x1d5cec pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1d5cf0 b 0x1d5ad8 <_Z16HandleKeyReleasei> */
/* @0x1d5cf4 eoreq r10, r1, r8, lsl #19 */
/* @0x1d5cf8 eoreq r10, r1, r12, lsl #19 */
/* @0x1d5cfc eoreq r10, r1, r0, lsl #19 */

/* ── FUNC 0x1d5d00 · HandleMouseGlobal(int) · size=368 · insn=92 */
/* @0x1d5d00 ldr r1, [pc, #0x154] */
/* @0x1d5d04 ldr r3, [pc, #0x154] */
/* @0x1d5d08 add r1, pc, r1 */
/* @0x1d5d0c ldr r12, [pc, #0x150] */
/* @0x1d5d10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d5d14 add r9, r0, #1536 */
/* @0x1d5d18 mov r8, r0 */
/* @0x1d5d1c ldr r0, [r1, r3] */
/* @0x1d5d20 sub sp, sp, #28 */
/* @0x1d5d24 ldrd r10, r11, [r0] */
/* @0x1d5d28 adds r2, r10, #1 */
/* @0x1d5d2c adc r3, r11, #0 */
/* @0x1d5d30 strd r10, r11, [sp, #8] */
/* @0x1d5d34 strd r2, r3, [r0] */
/* @0x1d5d38 ldr r11, [r1, r12] */
/* @0x1d5d3c ldr r3, [r11, r9, lsl #2] */
/* @0x1d5d40 cmp r3, #0 */
/* @0x1d5d44 ble 0x1d5e54 <_Z17HandleMouseGlobali+0x154> */
/* @0x1d5d48 ldr r2, [pc, #0x118] */
/* @0x1d5d4c mov r7, #0 */
/* @0x1d5d50 ldr r3, [pc, #0x114] */
/* @0x1d5d54 ldr r10, [r1, r2] */
/* @0x1d5d58 ldr r3, [r1, r3] */
/* @0x1d5d5c add r10, r10, r9, lsl #3 */
/* @0x1d5d60 str r3, [sp, #0x14] */
/* @0x1d5d64 mov r3, r10 */
/* @0x1d5d68 mov r10, r11 */
/* @0x1d5d6c mov r11, r3 */
/* @0x1d5d70 ldr r12, [sp, #0x14] */
/* @0x1d5d74 ldr r1, [r11, #0x4] */
/* @0x1d5d78 ldr r3, [r12] */
/* @0x1d5d7c ldr r1, [r1, r7, lsl #2] */
/* @0x1d5d80 ldr r2, [r3, #0x4] */
/* @0x1d5d84 ldr r3, [r3] */
/* @0x1d5d88 and r2, r1, r2 */
/* @0x1d5d8c ldr r3, [r3, r2, lsl #3] */
/* @0x1d5d90 cmp r3, #0 */
/* @0x1d5d94 bne 0x1d5da8 <_Z17HandleMouseGlobali+0xa8> */
/* @0x1d5d98 b 0x1d5e44 <_Z17HandleMouseGlobali+0x144> */
/* @0x1d5d9c ldr r3, [r3, #0x4] */
/* @0x1d5da0 cmp r3, #0 */
/* @0x1d5da4 beq 0x1d5e44 <_Z17HandleMouseGlobali+0x144> */
/* @0x1d5da8 ldr r2, [r3, #0x8] */
/* @0x1d5dac cmp r1, r2 */
/* @0x1d5db0 bne 0x1d5d9c <_Z17HandleMouseGlobali+0x9c> */
/* @0x1d5db4 ldr r3, [r3, #0xc] */
/* @0x1d5db8 cmp r3, #0 */
/* @0x1d5dbc beq 0x1d5e44 <_Z17HandleMouseGlobali+0x144> */
/* @0x1d5dc0 ldr r6, [r3, #0xc4] */
/* @0x1d5dc4 cmp r6, #0 */
/* @0x1d5dc8 beq 0x1d5e44 <_Z17HandleMouseGlobali+0x144> */
/* @0x1d5dcc ldr r3, [r6, #0x8] */
/* @0x1d5dd0 cmp r3, #0 */
/* @0x1d5dd4 beq 0x1d5e44 <_Z17HandleMouseGlobali+0x144> */
/* @0x1d5dd8 str r10, [sp, #0x10] */
/* @0x1d5ddc str r11, [sp, #0x4] */
/* @0x1d5de0 b 0x1d5df0 <_Z17HandleMouseGlobali+0xf0> */
/* @0x1d5de4 ldr r3, [r6, #0x8] */
/* @0x1d5de8 cmp r3, #0 */
/* @0x1d5dec beq 0x1d5e3c <_Z17HandleMouseGlobali+0x13c> */
/* @0x1d5df0 ldr r0, [r6, #0x8] */
/* @0x1d5df4 ldr r6, [r6] */
/* @0x1d5df8 ldrb r3, [r0, #0x68] */
/* @0x1d5dfc cmp r3, #0 */
/* @0x1d5e00 bne 0x1d5e34 <_Z17HandleMouseGlobali+0x134> */
/* @0x1d5e04 ldrb r3, [r0, #0x69] */
/* @0x1d5e08 cmp r3, #0 */
/* @0x1d5e0c bne 0x1d5e34 <_Z17HandleMouseGlobali+0x134> */
/* @0x1d5e10 ldrd r4, r5, [r0, #112] */
/* @0x1d5e14 mov r1, r0 */
/* @0x1d5e18 ldrd r10, r11, [sp, #8] */
/* @0x1d5e1c mov r2, #6 */
/* @0x1d5e20 mov r3, r8 */
/* @0x1d5e24 cmp r10, r4 */
/* @0x1d5e28 sbcs r11, r11, r5 */
/* @0x1d5e2c blt 0x1d5e34 <_Z17HandleMouseGlobali+0x134> */
/* @0x1d5e30 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d5e34 cmp r6, #0 */
/* @0x1d5e38 bne 0x1d5de4 <_Z17HandleMouseGlobali+0xe4> */
/* @0x1d5e3c ldr r10, [sp, #0x10] */
/* @0x1d5e40 ldr r11, [sp, #0x4] */
/* @0x1d5e44 ldr r3, [r10, r9, lsl #2] */
/* @0x1d5e48 add r7, r7, #1 */
/* @0x1d5e4c cmp r3, r7 */
/* @0x1d5e50 bgt 0x1d5d70 <_Z17HandleMouseGlobali+0x70> */
/* @0x1d5e54 add sp, sp, #28 */
/* @0x1d5e58 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d5e5c eoreq r11, r1, r8, asr #30 */
/* @0x1d5e60 .word 0xffffdeb4 */
/* @0x1d5e64 .word 0xffffdeb8 */
/* @0x1d5e68 .word 0xffffdebc */
/* @0x1d5e6c .word 0xffffbfec */

/* ── FUNC 0x1d5e70 · HandleButton(int) · size=376 · insn=94 */
/* @0x1d5e70 ldr r1, [pc, #0x158] */
/* @0x1d5e74 ldr r3, [pc, #0x158] */
/* @0x1d5e78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d5e7c add r1, pc, r1 */
/* @0x1d5e80 sub sp, sp, #20 */
/* @0x1d5e84 add r7, r0, #1536 */
/* @0x1d5e88 ldr r12, [pc, #0x148] */
/* @0x1d5e8c str r0, [sp, #0xc] */
/* @0x1d5e90 ldr r0, [r1, r3] */
/* @0x1d5e94 ldrd r2, r3, [r0] */
/* @0x1d5e98 strd r2, r3, [sp] */
/* @0x1d5e9c adds r2, r2, #1 */
/* @0x1d5ea0 adc r3, r3, #0 */
/* @0x1d5ea4 strd r2, r3, [r0] */
/* @0x1d5ea8 ldr r8, [r1, r12] */
/* @0x1d5eac ldr r3, [r8, r7, lsl #2] */
/* @0x1d5eb0 cmp r3, #0 */
/* @0x1d5eb4 ble 0x1d5fc8 <_Z12HandleButtoni+0x158> */
/* @0x1d5eb8 ldr r2, [pc, #0x11c] */
/* @0x1d5ebc mov r6, #0 */
/* @0x1d5ec0 ldr r3, [pc, #0x118] */
/* @0x1d5ec4 ldr r11, [pc, #0x118] */
/* @0x1d5ec8 ldr r9, [r1, r2] */
/* @0x1d5ecc ldr r10, [r1, r3] */
/* @0x1d5ed0 add r11, pc, r11 */
/* @0x1d5ed4 add r9, r9, r7, lsl #3 */
/* @0x1d5ed8 ldr r3, [r10] */
/* @0x1d5edc ldr r1, [r9, #0x4] */
/* @0x1d5ee0 ldr r2, [r3, #0x4] */
/* @0x1d5ee4 ldr r1, [r1, r6, lsl #2] */
/* @0x1d5ee8 ldr r3, [r3] */
/* @0x1d5eec and r2, r1, r2 */
/* @0x1d5ef0 ldr r3, [r3, r2, lsl #3] */
/* @0x1d5ef4 cmp r3, #0 */
/* @0x1d5ef8 bne 0x1d5f0c <_Z12HandleButtoni+0x9c> */
/* @0x1d5efc b 0x1d5fb8 <_Z12HandleButtoni+0x148> */
/* @0x1d5f00 ldr r3, [r3, #0x4] */
/* @0x1d5f04 cmp r3, #0 */
/* @0x1d5f08 beq 0x1d5fb8 <_Z12HandleButtoni+0x148> */
/* @0x1d5f0c ldr r2, [r3, #0x8] */
/* @0x1d5f10 cmp r1, r2 */
/* @0x1d5f14 bne 0x1d5f00 <_Z12HandleButtoni+0x90> */
/* @0x1d5f18 ldr r3, [r3, #0xc] */
/* @0x1d5f1c cmp r3, #0 */
/* @0x1d5f20 ldrne r4, [r3, #0xc4] */
/* @0x1d5f24 beq 0x1d5fb8 <_Z12HandleButtoni+0x148> */
/* @0x1d5f28 cmp r4, #0 */
/* @0x1d5f2c beq 0x1d5fb8 <_Z12HandleButtoni+0x148> */
/* @0x1d5f30 ldr r3, [r4, #0x8] */
/* @0x1d5f34 cmp r3, #0 */
/* @0x1d5f38 beq 0x1d5fb8 <_Z12HandleButtoni+0x148> */
/* @0x1d5f3c ldr r5, [r4, #0x8] */
/* @0x1d5f40 ldr r4, [r4] */
/* @0x1d5f44 ldrb r3, [r5, #0x68] */
/* @0x1d5f48 cmp r3, #0 */
/* @0x1d5f4c bne 0x1d5f28 <_Z12HandleButtoni+0xb8> */
/* @0x1d5f50 ldrb r3, [r5, #0x69] */
/* @0x1d5f54 cmp r3, #0 */
/* @0x1d5f58 bne 0x1d5f28 <_Z12HandleButtoni+0xb8> */
/* @0x1d5f5c ldrd r2, r3, [r5, #112] */
/* @0x1d5f60 ldrd r0, r1, [sp] */
/* @0x1d5f64 cmp r0, r2 */
/* @0x1d5f68 sbcs r1, r1, r3 */
/* @0x1d5f6c blt 0x1d5f28 <_Z12HandleButtoni+0xb8> */
/* @0x1d5f70 vldr s15, [r11, #4] */
/* @0x1d5f74 vcvt.f32.s32 s15, s15 */
/* @0x1d5f78 mov r3, #1 */
/* @0x1d5f7c mov r0, r5 */
/* @0x1d5f80 vmov r2, s15 */
/* @0x1d5f84 vldr s15, [r11] */
/* @0x1d5f88 vcvt.f32.s32 s15, s15 */
/* @0x1d5f8c vmov r1, s15 */
/* @0x1d5f90 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1d5f94 cmp r0, #0 */
/* @0x1d5f98 beq 0x1d5f28 <_Z12HandleButtoni+0xb8> */
/* @0x1d5f9c mov r2, #6 */
/* @0x1d5fa0 mov r0, r5 */
/* @0x1d5fa4 ldr r3, [sp, #0xc] */
/* @0x1d5fa8 mov r1, r5 */
/* @0x1d5fac bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d5fb0 cmp r4, #0 */
/* @0x1d5fb4 bne 0x1d5f30 <_Z12HandleButtoni+0xc0> */
/* @0x1d5fb8 ldr r3, [r8, r7, lsl #2] */
/* @0x1d5fbc add r6, r6, #1 */
/* @0x1d5fc0 cmp r3, r6 */
/* @0x1d5fc4 bgt 0x1d5ed8 <_Z12HandleButtoni+0x68> */
/* @0x1d5fc8 add sp, sp, #20 */
/* @0x1d5fcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d5fd0 .word 0x0021bdd4 */
/* @0x1d5fd4 .word 0xffffdeb4 */
/* @0x1d5fd8 .word 0xffffdeb8 */
/* @0x1d5fdc .word 0xffffdebc */
/* @0x1d5fe0 .word 0xffffbfec */
/* @0x1d5fe4 eorseq lr, r6, r0, lsr #23 */

/* ── FUNC 0x1d5fe8 · HandleEnter() · size=1384 · insn=346 */
/* @0x1d5fe8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d5fec sub sp, sp, #36 */
/* @0x1d5ff0 ldr r4, [pc, #0x53c] */
/* @0x1d5ff4 movw r12, #0x1828 */
/* @0x1d5ff8 ldr r3, [pc, #0x538] */
/* @0x1d5ffc add r4, pc, r4 */
/* @0x1d6000 str r4, [sp, #0x18] */
/* @0x1d6004 ldr r1, [pc, #0x530] */
/* @0x1d6008 ldr r3, [r4, r3] */
/* @0x1d600c str r3, [sp, #0x1c] */
/* @0x1d6010 ldrd r6, r7, [r3] */
/* @0x1d6014 ldr r8, [sp, #0x1c] */
/* @0x1d6018 adds r2, r6, #1 */
/* @0x1d601c adc r3, r7, #0 */
/* @0x1d6020 strd r6, r7, [sp, #16] */
/* @0x1d6024 strd r2, r3, [r8] */
/* @0x1d6028 ldr r8, [r4, r1] */
/* @0x1d602c ldr r3, [r8, r12] */
/* @0x1d6030 cmp r3, #0 */
/* @0x1d6034 ble 0x1d618c <_Z11HandleEnterv+0x1a4> */
/* @0x1d6038 ldr r9, [sp, #0x18] */
/* @0x1d603c mov r10, #0 */
/* @0x1d6040 ldr r2, [pc, #0x4f8] */
/* @0x1d6044 ldr r3, [pc, #0x4f8] */
/* @0x1d6048 ldr r11, [pc, #0x4f8] */
/* @0x1d604c ldr r7, [r9, r2] */
/* @0x1d6050 ldr r5, [r9, r3] */
/* @0x1d6054 add r11, pc, r11 */
/* @0x1d6058 mov r9, r5 */
/* @0x1d605c mov r5, r7 */
/* @0x1d6060 movw r0, #0x3054 */
/* @0x1d6064 ldr r3, [r5] */
/* @0x1d6068 ldr r1, [r9, r0] */
/* @0x1d606c ldr r2, [r3, #0x4] */
/* @0x1d6070 ldr r1, [r1, r10, lsl #2] */
/* @0x1d6074 ldr r3, [r3] */
/* @0x1d6078 and r2, r1, r2 */
/* @0x1d607c ldr r3, [r3, r2, lsl #3] */
/* @0x1d6080 cmp r3, #0 */
/* @0x1d6084 bne 0x1d6098 <_Z11HandleEnterv+0xb0> */
/* @0x1d6088 b 0x1d617c <_Z11HandleEnterv+0x194> */
/* @0x1d608c ldr r3, [r3, #0x4] */
/* @0x1d6090 cmp r3, #0 */
/* @0x1d6094 beq 0x1d617c <_Z11HandleEnterv+0x194> */
/* @0x1d6098 ldr r2, [r3, #0x8] */
/* @0x1d609c cmp r1, r2 */
/* @0x1d60a0 bne 0x1d608c <_Z11HandleEnterv+0xa4> */
/* @0x1d60a4 ldr r3, [r3, #0xc] */
/* @0x1d60a8 cmp r3, #0 */
/* @0x1d60ac beq 0x1d617c <_Z11HandleEnterv+0x194> */
/* @0x1d60b0 ldr r6, [r3, #0xc4] */
/* @0x1d60b4 cmp r6, #0 */
/* @0x1d60b8 beq 0x1d617c <_Z11HandleEnterv+0x194> */
/* @0x1d60bc ldr r3, [r6, #0x8] */
/* @0x1d60c0 cmp r3, #0 */
/* @0x1d60c4 beq 0x1d617c <_Z11HandleEnterv+0x194> */
/* @0x1d60c8 stm sp, {r8, r9, r10} */
/* @0x1d60cc mov r10, r5 */
/* @0x1d60d0 b 0x1d60e0 <_Z11HandleEnterv+0xf8> */
/* @0x1d60d4 ldr r3, [r6, #0x8] */
/* @0x1d60d8 cmp r3, #0 */
/* @0x1d60dc beq 0x1d6170 <_Z11HandleEnterv+0x188> */
/* @0x1d60e0 ldr r7, [r6, #0x8] */
/* @0x1d60e4 ldr r6, [r6] */
/* @0x1d60e8 ldrb r3, [r7, #0x68] */
/* @0x1d60ec cmp r3, #0 */
/* @0x1d60f0 bne 0x1d6168 <_Z11HandleEnterv+0x180> */
/* @0x1d60f4 ldrb r3, [r7, #0x69] */
/* @0x1d60f8 cmp r3, #0 */
/* @0x1d60fc bne 0x1d6168 <_Z11HandleEnterv+0x180> */
/* @0x1d6100 ldrd r4, r5, [r7, #112] */
/* @0x1d6104 mov r0, r7 */
/* @0x1d6108 ldrd r8, r9, [sp, #16] */
/* @0x1d610c mov r3, #1 */
/* @0x1d6110 cmp r4, r8 */
/* @0x1d6114 sbcs r9, r5, r9 */
/* @0x1d6118 bge 0x1d6168 <_Z11HandleEnterv+0x180> */
/* @0x1d611c vldr s15, [r11] */
/* @0x1d6120 vcvt.f32.s32 s15, s15 */
/* @0x1d6124 ldrd r8, r9, [sp, #16] */
/* @0x1d6128 ldr r4, [r7, #0x16c] */
/* @0x1d612c strd r8, r9, [r7, #112] */
/* @0x1d6130 and r4, r4, #3 */
/* @0x1d6134 vmov r1, s15 */
/* @0x1d6138 vldr s15, [r11, #4] */
/* @0x1d613c vcvt.f32.s32 s15, s15 */
/* @0x1d6140 str r12, [sp, #0xc] */
/* @0x1d6144 vmov r2, s15 */
/* @0x1d6148 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1d614c ldr r12, [sp, #0xc] */
/* @0x1d6150 cmp r0, #0 */
/* @0x1d6154 moveq r0, #2 */
/* @0x1d6158 movne r0, #1 */
/* @0x1d615c eor r4, r0, r4 */
/* @0x1d6160 orr r0, r0, r4, lsl #2 */
/* @0x1d6164 str r0, [r7, #0x16c] */
/* @0x1d6168 cmp r6, #0 */
/* @0x1d616c bne 0x1d60d4 <_Z11HandleEnterv+0xec> */
/* @0x1d6170 mov r3, r10 */
/* @0x1d6174 ldm sp, {r8, r9, r10} */
/* @0x1d6178 mov r5, r3 */
/* @0x1d617c ldr r3, [r8, r12] */
/* @0x1d6180 add r10, r10, #1 */
/* @0x1d6184 cmp r3, r10 */
/* @0x1d6188 bgt 0x1d6060 <_Z11HandleEnterv+0x78> */
/* @0x1d618c movw r12, #0x182c */
/* @0x1d6190 ldr r3, [r8, r12] */
/* @0x1d6194 cmp r3, #0 */
/* @0x1d6198 ble 0x1d62f0 <_Z11HandleEnterv+0x308> */
/* @0x1d619c ldr r9, [sp, #0x18] */
/* @0x1d61a0 mov r10, #0 */
/* @0x1d61a4 ldr r2, [pc, #0x394] */
/* @0x1d61a8 ldr r3, [pc, #0x394] */
/* @0x1d61ac ldr r11, [pc, #0x398] */
/* @0x1d61b0 ldr r7, [r9, r2] */
/* @0x1d61b4 ldr r5, [r9, r3] */
/* @0x1d61b8 add r11, pc, r11 */
/* @0x1d61bc mov r9, r5 */
/* @0x1d61c0 mov r5, r7 */
/* @0x1d61c4 movw r0, #0x305c */
/* @0x1d61c8 ldr r3, [r5] */
/* @0x1d61cc ldr r1, [r9, r0] */
/* @0x1d61d0 ldr r2, [r3, #0x4] */
/* @0x1d61d4 ldr r1, [r1, r10, lsl #2] */
/* @0x1d61d8 ldr r3, [r3] */
/* @0x1d61dc and r2, r1, r2 */
/* @0x1d61e0 ldr r3, [r3, r2, lsl #3] */
/* @0x1d61e4 cmp r3, #0 */
/* @0x1d61e8 bne 0x1d61fc <_Z11HandleEnterv+0x214> */
/* @0x1d61ec b 0x1d62e0 <_Z11HandleEnterv+0x2f8> */
/* @0x1d61f0 ldr r3, [r3, #0x4] */
/* @0x1d61f4 cmp r3, #0 */
/* @0x1d61f8 beq 0x1d62e0 <_Z11HandleEnterv+0x2f8> */
/* @0x1d61fc ldr r2, [r3, #0x8] */
/* @0x1d6200 cmp r1, r2 */
/* @0x1d6204 bne 0x1d61f0 <_Z11HandleEnterv+0x208> */
/* @0x1d6208 ldr r3, [r3, #0xc] */
/* @0x1d620c cmp r3, #0 */
/* @0x1d6210 beq 0x1d62e0 <_Z11HandleEnterv+0x2f8> */
/* @0x1d6214 ldr r6, [r3, #0xc4] */
/* @0x1d6218 cmp r6, #0 */
/* @0x1d621c beq 0x1d62e0 <_Z11HandleEnterv+0x2f8> */
/* @0x1d6220 ldr r3, [r6, #0x8] */
/* @0x1d6224 cmp r3, #0 */
/* @0x1d6228 beq 0x1d62e0 <_Z11HandleEnterv+0x2f8> */
/* @0x1d622c stm sp, {r8, r9, r10} */
/* @0x1d6230 mov r10, r5 */
/* @0x1d6234 b 0x1d6244 <_Z11HandleEnterv+0x25c> */
/* @0x1d6238 ldr r3, [r6, #0x8] */
/* @0x1d623c cmp r3, #0 */
/* @0x1d6240 beq 0x1d62d4 <_Z11HandleEnterv+0x2ec> */
/* @0x1d6244 ldr r7, [r6, #0x8] */
/* @0x1d6248 ldr r6, [r6] */
/* @0x1d624c ldrb r3, [r7, #0x68] */
/* @0x1d6250 cmp r3, #0 */
/* @0x1d6254 bne 0x1d62cc <_Z11HandleEnterv+0x2e4> */
/* @0x1d6258 ldrb r3, [r7, #0x69] */
/* @0x1d625c cmp r3, #0 */
/* @0x1d6260 bne 0x1d62cc <_Z11HandleEnterv+0x2e4> */
/* @0x1d6264 ldrd r4, r5, [r7, #112] */
/* @0x1d6268 mov r0, r7 */
/* @0x1d626c ldrd r8, r9, [sp, #16] */
/* @0x1d6270 mov r3, #1 */
/* @0x1d6274 cmp r4, r8 */
/* @0x1d6278 sbcs r9, r5, r9 */
/* @0x1d627c bge 0x1d62cc <_Z11HandleEnterv+0x2e4> */
/* @0x1d6280 vldr s15, [r11] */
/* @0x1d6284 vcvt.f32.s32 s15, s15 */
/* @0x1d6288 ldrd r8, r9, [sp, #16] */
/* @0x1d628c ldr r4, [r7, #0x16c] */
/* @0x1d6290 strd r8, r9, [r7, #112] */
/* @0x1d6294 and r4, r4, #3 */
/* @0x1d6298 vmov r1, s15 */
/* @0x1d629c vldr s15, [r11, #4] */
/* @0x1d62a0 vcvt.f32.s32 s15, s15 */
/* @0x1d62a4 str r12, [sp, #0xc] */
/* @0x1d62a8 vmov r2, s15 */
/* @0x1d62ac bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1d62b0 ldr r12, [sp, #0xc] */
/* @0x1d62b4 cmp r0, #0 */
/* @0x1d62b8 moveq r0, #2 */
/* @0x1d62bc movne r0, #1 */
/* @0x1d62c0 eor r4, r0, r4 */
/* @0x1d62c4 orr r0, r0, r4, lsl #2 */
/* @0x1d62c8 str r0, [r7, #0x16c] */
/* @0x1d62cc cmp r6, #0 */
/* @0x1d62d0 bne 0x1d6238 <_Z11HandleEnterv+0x250> */
/* @0x1d62d4 mov r3, r10 */
/* @0x1d62d8 ldm sp, {r8, r9, r10} */
/* @0x1d62dc mov r5, r3 */
/* @0x1d62e0 ldr r3, [r8, r12] */
/* @0x1d62e4 add r10, r10, #1 */
/* @0x1d62e8 cmp r3, r10 */
/* @0x1d62ec bgt 0x1d61c4 <_Z11HandleEnterv+0x1dc> */
/* @0x1d62f0 ldr r4, [sp, #0x1c] */
/* @0x1d62f4 movw r6, #0x1828 */
/* @0x1d62f8 ldr r3, [r8, r6] */
/* @0x1d62fc ldr r7, [sp, #0x1c] */
/* @0x1d6300 ldrd r10, r11, [r4] */
/* @0x1d6304 adds r4, r10, #1 */
/* @0x1d6308 adc r5, r11, #0 */
/* @0x1d630c cmp r3, #0 */
/* @0x1d6310 strd r4, r5, [r7] */
/* @0x1d6314 ble 0x1d640c <_Z11HandleEnterv+0x424> */
/* @0x1d6318 ldr r4, [sp, #0x18] */
/* @0x1d631c mov r9, #0 */
/* @0x1d6320 ldr r2, [pc, #0x218] */
/* @0x1d6324 ldr r3, [pc, #0x218] */
/* @0x1d6328 ldr r7, [r4, r2] */
/* @0x1d632c ldr r5, [r4, r3] */
/* @0x1d6330 movw r0, #0x3054 */
/* @0x1d6334 ldr r3, [r7] */
/* @0x1d6338 ldr r1, [r5, r0] */
/* @0x1d633c ldr r2, [r3, #0x4] */
/* @0x1d6340 ldr r1, [r1, r9, lsl #2] */
/* @0x1d6344 ldr r3, [r3] */
/* @0x1d6348 and r2, r1, r2 */
/* @0x1d634c ldr r3, [r3, r2, lsl #3] */
/* @0x1d6350 cmp r3, #0 */
/* @0x1d6354 bne 0x1d6368 <_Z11HandleEnterv+0x380> */
/* @0x1d6358 b 0x1d63f4 <_Z11HandleEnterv+0x40c> */
/* @0x1d635c ldr r3, [r3, #0x4] */
/* @0x1d6360 cmp r3, #0 */
/* @0x1d6364 beq 0x1d63f4 <_Z11HandleEnterv+0x40c> */
/* @0x1d6368 ldr r2, [r3, #0x8] */
/* @0x1d636c cmp r1, r2 */
/* @0x1d6370 bne 0x1d635c <_Z11HandleEnterv+0x374> */
/* @0x1d6374 ldr r3, [r3, #0xc] */
/* @0x1d6378 cmp r3, #0 */
/* @0x1d637c ldrne r4, [r3, #0xc4] */
/* @0x1d6380 beq 0x1d63f4 <_Z11HandleEnterv+0x40c> */
/* @0x1d6384 cmp r4, #0 */
/* @0x1d6388 beq 0x1d63f4 <_Z11HandleEnterv+0x40c> */
/* @0x1d638c ldr r3, [r4, #0x8] */
/* @0x1d6390 cmp r3, #0 */
/* @0x1d6394 beq 0x1d63f4 <_Z11HandleEnterv+0x40c> */
/* @0x1d6398 ldr r0, [r4, #0x8] */
/* @0x1d639c ldr r4, [r4] */
/* @0x1d63a0 ldrb r3, [r0, #0x68] */
/* @0x1d63a4 cmp r3, #0 */
/* @0x1d63a8 bne 0x1d6384 <_Z11HandleEnterv+0x39c> */
/* @0x1d63ac ldrb r3, [r0, #0x69] */
/* @0x1d63b0 cmp r3, #0 */
/* @0x1d63b4 bne 0x1d6384 <_Z11HandleEnterv+0x39c> */
/* @0x1d63b8 ldrd r2, r3, [r0, #112] */
/* @0x1d63bc cmp r10, r2 */
/* @0x1d63c0 sbcs r1, r11, r3 */
/* @0x1d63c4 blt 0x1d6384 <_Z11HandleEnterv+0x39c> */
/* @0x1d63c8 ldr r3, [r0, #0x16c] */
/* @0x1d63cc tst r3, #4 */
/* @0x1d63d0 beq 0x1d6384 <_Z11HandleEnterv+0x39c> */
/* @0x1d63d4 tst r3, #1 */
/* @0x1d63d8 beq 0x1d6384 <_Z11HandleEnterv+0x39c> */
/* @0x1d63dc mov r2, #6 */
/* @0x1d63e0 mov r3, #10 */
/* @0x1d63e4 mov r1, r0 */
/* @0x1d63e8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d63ec cmp r4, #0 */
/* @0x1d63f0 bne 0x1d638c <_Z11HandleEnterv+0x3a4> */
/* @0x1d63f4 ldr r3, [r8, r6] */
/* @0x1d63f8 add r9, r9, #1 */
/* @0x1d63fc cmp r3, r9 */
/* @0x1d6400 bgt 0x1d6330 <_Z11HandleEnterv+0x348> */
/* @0x1d6404 ldr r5, [sp, #0x1c] */
/* @0x1d6408 ldrd r4, r5, [r5] */
/* @0x1d640c strd r4, r5, [sp, #16] */
/* @0x1d6410 movw r10, #0x182c */
/* @0x1d6414 ldrd r2, r3, [sp, #16] */
/* @0x1d6418 ldr r1, [r8, r10] */
/* @0x1d641c adds r2, r2, #1 */
/* @0x1d6420 ldr r6, [sp, #0x1c] */
/* @0x1d6424 adc r3, r3, #0 */
/* @0x1d6428 cmp r1, #0 */
/* @0x1d642c strd r2, r3, [r6] */
/* @0x1d6430 ble 0x1d652c <_Z11HandleEnterv+0x544> */
/* @0x1d6434 ldr r4, [sp, #0x18] */
/* @0x1d6438 mov r9, #0 */
/* @0x1d643c ldr r2, [pc, #0xfc] */
/* @0x1d6440 movw r11, #0x305c */
/* @0x1d6444 ldr r3, [pc, #0xf8] */
/* @0x1d6448 ldr r7, [r4, r2] */
/* @0x1d644c ldr r5, [r4, r3] */
/* @0x1d6450 str r7, [sp, #0x18] */
/* @0x1d6454 ldr r6, [sp, #0x18] */
/* @0x1d6458 ldr r1, [r5, r11] */
/* @0x1d645c ldr r3, [r6] */
/* @0x1d6460 ldr r1, [r1, r9, lsl #2] */
/* @0x1d6464 ldr r2, [r3, #0x4] */
/* @0x1d6468 ldr r3, [r3] */
/* @0x1d646c and r2, r1, r2 */
/* @0x1d6470 ldr r3, [r3, r2, lsl #3] */
/* @0x1d6474 cmp r3, #0 */
/* @0x1d6478 bne 0x1d648c <_Z11HandleEnterv+0x4a4> */
/* @0x1d647c b 0x1d651c <_Z11HandleEnterv+0x534> */
/* @0x1d6480 ldr r3, [r3, #0x4] */
/* @0x1d6484 cmp r3, #0 */
/* @0x1d6488 beq 0x1d651c <_Z11HandleEnterv+0x534> */
/* @0x1d648c ldr r2, [r3, #0x8] */
/* @0x1d6490 cmp r1, r2 */
/* @0x1d6494 bne 0x1d6480 <_Z11HandleEnterv+0x498> */
/* @0x1d6498 ldr r3, [r3, #0xc] */
/* @0x1d649c cmp r3, #0 */
/* @0x1d64a0 ldrne r4, [r3, #0xc4] */
/* @0x1d64a4 beq 0x1d651c <_Z11HandleEnterv+0x534> */
/* @0x1d64a8 cmp r4, #0 */
/* @0x1d64ac beq 0x1d651c <_Z11HandleEnterv+0x534> */
/* @0x1d64b0 ldr r3, [r4, #0x8] */
/* @0x1d64b4 cmp r3, #0 */
/* @0x1d64b8 beq 0x1d651c <_Z11HandleEnterv+0x534> */
/* @0x1d64bc ldr r0, [r4, #0x8] */
/* @0x1d64c0 ldr r4, [r4] */
/* @0x1d64c4 ldrb r3, [r0, #0x68] */
/* @0x1d64c8 cmp r3, #0 */
/* @0x1d64cc bne 0x1d64a8 <_Z11HandleEnterv+0x4c0> */
/* @0x1d64d0 ldrb r3, [r0, #0x69] */
/* @0x1d64d4 cmp r3, #0 */
/* @0x1d64d8 bne 0x1d64a8 <_Z11HandleEnterv+0x4c0> */
/* @0x1d64dc ldrd r6, r7, [sp, #16] */
/* @0x1d64e0 ldrd r2, r3, [r0, #112] */
/* @0x1d64e4 cmp r6, r2 */
/* @0x1d64e8 sbcs r3, r7, r3 */
/* @0x1d64ec blt 0x1d64a8 <_Z11HandleEnterv+0x4c0> */
/* @0x1d64f0 ldr r3, [r0, #0x16c] */
/* @0x1d64f4 tst r3, #8 */
/* @0x1d64f8 beq 0x1d64a8 <_Z11HandleEnterv+0x4c0> */
/* @0x1d64fc tst r3, #2 */
/* @0x1d6500 beq 0x1d64a8 <_Z11HandleEnterv+0x4c0> */
/* @0x1d6504 mov r2, #6 */
/* @0x1d6508 mov r3, #11 */
/* @0x1d650c mov r1, r0 */
/* @0x1d6510 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d6514 cmp r4, #0 */
/* @0x1d6518 bne 0x1d64b0 <_Z11HandleEnterv+0x4c8> */
/* @0x1d651c ldr r3, [r8, r10] */
/* @0x1d6520 add r9, r9, #1 */
/* @0x1d6524 cmp r3, r9 */
/* @0x1d6528 bgt 0x1d6454 <_Z11HandleEnterv+0x46c> */
/* @0x1d652c add sp, sp, #36 */
/* @0x1d6530 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d6534 eoreq r11, r1, r4, asr r12 */
/* @0x1d6538 .word 0xffffdeb4 */
/* @0x1d653c .word 0xffffdeb8 */
/* @0x1d6540 .word 0xffffbfec */
/* @0x1d6544 .word 0xffffdebc */
/* @0x1d6548 eorseq lr, r6, r12, lsl r10 */
/* @0x1d654c ldrhteq lr, [r6], -r8 */

/* ── FUNC 0x1d6550 · HandleJoy(int) · size=368 · insn=92 */
/* @0x1d6550 ldr r1, [pc, #0x154] */
/* @0x1d6554 ldr r3, [pc, #0x154] */
/* @0x1d6558 add r1, pc, r1 */
/* @0x1d655c ldr r12, [pc, #0x150] */
/* @0x1d6560 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d6564 add r9, r0, #1536 */
/* @0x1d6568 mov r8, r0 */
/* @0x1d656c ldr r0, [r1, r3] */
/* @0x1d6570 sub sp, sp, #28 */
/* @0x1d6574 ldrd r10, r11, [r0] */
/* @0x1d6578 adds r2, r10, #1 */
/* @0x1d657c adc r3, r11, #0 */
/* @0x1d6580 strd r10, r11, [sp, #8] */
/* @0x1d6584 strd r2, r3, [r0] */
/* @0x1d6588 ldr r11, [r1, r12] */
/* @0x1d658c ldr r3, [r11, r9, lsl #2] */
/* @0x1d6590 cmp r3, #0 */
/* @0x1d6594 ble 0x1d66a4 <_Z9HandleJoyi+0x154> */
/* @0x1d6598 ldr r2, [pc, #0x118] */
/* @0x1d659c mov r7, #0 */
/* @0x1d65a0 ldr r3, [pc, #0x114] */
/* @0x1d65a4 ldr r10, [r1, r2] */
/* @0x1d65a8 ldr r3, [r1, r3] */
/* @0x1d65ac add r10, r10, r9, lsl #3 */
/* @0x1d65b0 str r3, [sp, #0x14] */
/* @0x1d65b4 mov r3, r10 */
/* @0x1d65b8 mov r10, r11 */
/* @0x1d65bc mov r11, r3 */
/* @0x1d65c0 ldr r12, [sp, #0x14] */
/* @0x1d65c4 ldr r1, [r11, #0x4] */
/* @0x1d65c8 ldr r3, [r12] */
/* @0x1d65cc ldr r1, [r1, r7, lsl #2] */
/* @0x1d65d0 ldr r2, [r3, #0x4] */
/* @0x1d65d4 ldr r3, [r3] */
/* @0x1d65d8 and r2, r1, r2 */
/* @0x1d65dc ldr r3, [r3, r2, lsl #3] */
/* @0x1d65e0 cmp r3, #0 */
/* @0x1d65e4 bne 0x1d65f8 <_Z9HandleJoyi+0xa8> */
/* @0x1d65e8 b 0x1d6694 <_Z9HandleJoyi+0x144> */
/* @0x1d65ec ldr r3, [r3, #0x4] */
/* @0x1d65f0 cmp r3, #0 */
/* @0x1d65f4 beq 0x1d6694 <_Z9HandleJoyi+0x144> */
/* @0x1d65f8 ldr r2, [r3, #0x8] */
/* @0x1d65fc cmp r1, r2 */
/* @0x1d6600 bne 0x1d65ec <_Z9HandleJoyi+0x9c> */
/* @0x1d6604 ldr r3, [r3, #0xc] */
/* @0x1d6608 cmp r3, #0 */
/* @0x1d660c beq 0x1d6694 <_Z9HandleJoyi+0x144> */
/* @0x1d6610 ldr r6, [r3, #0xc4] */
/* @0x1d6614 cmp r6, #0 */
/* @0x1d6618 beq 0x1d6694 <_Z9HandleJoyi+0x144> */
/* @0x1d661c ldr r3, [r6, #0x8] */
/* @0x1d6620 cmp r3, #0 */
/* @0x1d6624 beq 0x1d6694 <_Z9HandleJoyi+0x144> */
/* @0x1d6628 str r10, [sp, #0x10] */
/* @0x1d662c str r11, [sp, #0x4] */
/* @0x1d6630 b 0x1d6640 <_Z9HandleJoyi+0xf0> */
/* @0x1d6634 ldr r3, [r6, #0x8] */
/* @0x1d6638 cmp r3, #0 */
/* @0x1d663c beq 0x1d668c <_Z9HandleJoyi+0x13c> */
/* @0x1d6640 ldr r0, [r6, #0x8] */
/* @0x1d6644 ldr r6, [r6] */
/* @0x1d6648 ldrb r3, [r0, #0x68] */
/* @0x1d664c cmp r3, #0 */
/* @0x1d6650 bne 0x1d6684 <_Z9HandleJoyi+0x134> */
/* @0x1d6654 ldrb r3, [r0, #0x69] */
/* @0x1d6658 cmp r3, #0 */
/* @0x1d665c bne 0x1d6684 <_Z9HandleJoyi+0x134> */
/* @0x1d6660 ldrd r4, r5, [r0, #112] */
/* @0x1d6664 mov r1, r0 */
/* @0x1d6668 ldrd r10, r11, [sp, #8] */
/* @0x1d666c mov r2, #6 */
/* @0x1d6670 mov r3, r8 */
/* @0x1d6674 cmp r10, r4 */
/* @0x1d6678 sbcs r11, r11, r5 */
/* @0x1d667c blt 0x1d6684 <_Z9HandleJoyi+0x134> */
/* @0x1d6680 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d6684 cmp r6, #0 */
/* @0x1d6688 bne 0x1d6634 <_Z9HandleJoyi+0xe4> */
/* @0x1d668c ldr r10, [sp, #0x10] */
/* @0x1d6690 ldr r11, [sp, #0x4] */
/* @0x1d6694 ldr r3, [r10, r9, lsl #2] */
/* @0x1d6698 add r7, r7, #1 */
/* @0x1d669c cmp r3, r7 */
/* @0x1d66a0 bgt 0x1d65c0 <_Z9HandleJoyi+0x70> */
/* @0x1d66a4 add sp, sp, #28 */
/* @0x1d66a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d66ac .word 0x0021b6f8 */
/* @0x1d66b0 .word 0xffffdeb4 */
/* @0x1d66b4 .word 0xffffdeb8 */
/* @0x1d66b8 .word 0xffffdebc */
/* @0x1d66bc .word 0xffffbfec */

/* ── FUNC 0x1d66c0 · ConvertXDPI(float) · size=36 · insn=9 */
/* @0x1d66c0 push {r3, lr} */
/* @0x1d66c4 vpush {d8} */
/* @0x1d66c8 vmov s16, r0 */
/* @0x1d66cc bl 0x15f244 <_Z7GetDPIXv> */
/* @0x1d66d0 vmov s15, r0 */
/* @0x1d66d4 vdiv.f32 s15, s16, s15 */
/* @0x1d66d8 vpop {d8} */
/* @0x1d66dc vmov r0, s15 */
/* @0x1d66e0 pop {r3, pc} */

/* ── FUNC 0x1d66e4 · ConvertYDPI(float) · size=36 · insn=9 */
/* @0x1d66e4 push {r3, lr} */
/* @0x1d66e8 vpush {d8} */
/* @0x1d66ec vmov s16, r0 */
/* @0x1d66f0 bl 0x15f258 <_Z7GetDPIYv> */
/* @0x1d66f4 vmov s15, r0 */
/* @0x1d66f8 vdiv.f32 s15, s16, s15 */
/* @0x1d66fc vpop {d8} */
/* @0x1d6700 vmov r0, s15 */
/* @0x1d6704 pop {r3, pc} */

/* ── FUNC 0x1d6708 · CalcDistInches(int, int) · size=116 · insn=29 */
/* @0x1d6708 vmov s13, r0 */
/* @0x1d670c str lr, [sp, #-0x4]! */
/* @0x1d6710 vpush {d8} */
/* @0x1d6714 vcvt.f32.s32 s13, s13 */
/* @0x1d6718 sub sp, sp, #12 */
/* @0x1d671c str r1, [sp, #0x4] */
/* @0x1d6720 vmov r0, s13 */
/* @0x1d6724 bl 0x1d66c0 <_Z11ConvertXDPIf> */
/* @0x1d6728 ldr r1, [sp, #0x4] */
/* @0x1d672c vmov s15, r1 */
/* @0x1d6730 vcvt.f32.s32 s15, s15 */
/* @0x1d6734 vmov s16, r0 */
/* @0x1d6738 vmov r0, s15 */
/* @0x1d673c bl 0x1d66e4 <_Z11ConvertYDPIf> */
/* @0x1d6740 vmov s13, r0 */
/* @0x1d6744 vmul.f32 s14, s13, s13 */
/* @0x1d6748 vmla.f32 s14, s16, s16 */
/* @0x1d674c vsqrt.f32 s15, s14 */
/* @0x1d6750 vcmp.f32 s15, s15 */
/* @0x1d6754 vmrs APSR_nzcv, fpscr */
/* @0x1d6758 bne 0x1d676c <_Z14CalcDistInchesii+0x64> */
/* @0x1d675c vmov r0, s15 */
/* @0x1d6760 add sp, sp, #12 */
/* @0x1d6764 vpop {d8} */
/* @0x1d6768 ldr pc, [sp], #4 */
/* @0x1d676c vmov r0, s14 */
/* @0x1d6770 bl 0xb6700 <sqrtf@plt> */
/* @0x1d6774 vmov s15, r0 */
/* @0x1d6778 b 0x1d675c <_Z14CalcDistInchesii+0x54> */

/* ── FUNC 0x1d677c · CSingleFingerGesture::CommonUpdate(long long) · size=216 · insn=54 */
/* @0x1d677c push {r4, r5, r6, lr} */
/* @0x1d6780 vpush {d8} */
/* @0x1d6784 mov r6, r0 */
/* @0x1d6788 ldr r1, [r6, #0x28] */
/* @0x1d678c mov r0, #1 */
/* @0x1d6790 mov r4, r2 */
/* @0x1d6794 mov r5, r3 */
/* @0x1d6798 bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x1d679c cmp r0, #0 */
/* @0x1d67a0 bne 0x1d67ac <_ZN20CSingleFingerGesture12CommonUpdateEx+0x30> */
/* @0x1d67a4 vpop {d8} */
/* @0x1d67a8 pop {r4, r5, r6, pc} */
/* @0x1d67ac ldr r2, [r6, #0x30] */
/* @0x1d67b0 ldr r3, [r6, #0x34] */
/* @0x1d67b4 ldr r0, [r6, #0x28] */
/* @0x1d67b8 str r2, [r6, #0x38] */
/* @0x1d67bc str r3, [r6, #0x3c] */
/* @0x1d67c0 bl 0x159e8c <_Z12GetRawMouseXi> */
/* @0x1d67c4 str r0, [r6, #0x30] */
/* @0x1d67c8 ldr r0, [r6, #0x28] */
/* @0x1d67cc bl 0x159eec <_Z12GetRawMouseYi> */
/* @0x1d67d0 ldrd r2, r3, [r6, #32] */
/* @0x1d67d4 ldr r1, [r6, #0x3c] */
/* @0x1d67d8 subs r4, r4, r2 */
/* @0x1d67dc sbc r5, r5, r3 */
/* @0x1d67e0 ldr r2, [r6, #0x30] */
/* @0x1d67e4 cmp r4, #1 */
/* @0x1d67e8 sbcs r3, r5, #0 */
/* @0x1d67ec ldr r3, [r6, #0x38] */
/* @0x1d67f0 rsb r1, r1, r0 */
/* @0x1d67f4 str r0, [r6, #0x34] */
/* @0x1d67f8 str r1, [r6, #0x4c] */
/* @0x1d67fc rsb r0, r3, r2 */
/* @0x1d6800 str r0, [r6, #0x48] */
/* @0x1d6804 blt 0x1d6830 <_ZN20CSingleFingerGesture12CommonUpdateEx+0xb4> */
/* @0x1d6808 bl 0x1d6708 <_Z14CalcDistInchesii> */
/* @0x1d680c mov r1, r5 */
/* @0x1d6810 vmov s16, r0 */
/* @0x1d6814 mov r0, r4 */
/* @0x1d6818 bl 0x319398 <__floatdisf> */
/* @0x1d681c vldr s15, [pc, #44] */
/* @0x1d6820 vmov s14, r0 */
/* @0x1d6824 vdiv.f32 s15, s14, s15 */
/* @0x1d6828 vdiv.f32 s16, s16, s15 */
/* @0x1d682c vstr s16, [r6, #88] */
/* @0x1d6830 ldr r3, [r6, #0x2c] */
/* @0x1d6834 cmn r3, #1 */
/* @0x1d6838 bne 0x1d67a4 <_ZN20CSingleFingerGesture12CommonUpdateEx+0x28> */
/* @0x1d683c ldr r0, [r6, #0x30] */
/* @0x1d6840 ldr r1, [r6, #0x34] */
/* @0x1d6844 bl 0x17a3b8 <_Z22GR_Window_Views_Get_IDii> */
/* @0x1d6848 str r0, [r6, #0x2c] */
/* @0x1d684c b 0x1d67a4 <_ZN20CSingleFingerGesture12CommonUpdateEx+0x28> */
/* @0x1d6850 ldmdbmi r4!, {r10, sp} ^ */

/* ── FUNC 0x1d6854 · CalcVelocity(float, float, float, float, float, float&, float&) · size=76 · insn=19 */
/* @0x1d6854 vldr s15, [sp] */
/* @0x1d6858 vcmp.f32 s15, #0 */
/* @0x1d685c vmov s12, r0 */
/* @0x1d6860 ldr r0, [sp, #0x8] */
/* @0x1d6864 vmov s14, r1 */
/* @0x1d6868 ldr r1, [sp, #0x4] */
/* @0x1d686c vmov s11, r2 */
/* @0x1d6870 mov r2, #0 */
/* @0x1d6874 vmov s13, r3 */
/* @0x1d6878 vmrs APSR_nzcv, fpscr */
/* @0x1d687c vsubne.f32 s12, s11, s12 */
/* @0x1d6880 streq r2, [r1] */
/* @0x1d6884 streq r2, [r0] */
/* @0x1d6888 vsubne.f32 s14, s13, s14 */
/* @0x1d688c vdivne.f32 s12, s12, s15 */
/* @0x1d6890 vdivne.f32 s15, s14, s15 */
/* @0x1d6894 vstrne s12, [r1] */
/* @0x1d6898 vstrne s15, [r0] */
/* @0x1d689c bx lr */

/* ── FUNC 0x1d68a0 · GetInstanceListWithEventType(int, int, float, float, int**, int*, bool) · size=676 · insn=169 */
/* @0x1d68a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d68a4 vpush {d8} */
/* @0x1d68a8 sub sp, sp, #52 */
/* @0x1d68ac mov r6, r0 */
/* @0x1d68b0 ldr r4, [pc, #0x274] */
/* @0x1d68b4 ldr r12, [sp, #0x60] */
/* @0x1d68b8 mov r5, r1 */
/* @0x1d68bc ldr r0, [sp, #0x64] */
/* @0x1d68c0 add r4, pc, r4 */
/* @0x1d68c4 vmov s17, r2 */
/* @0x1d68c8 cmp r0, #0 */
/* @0x1d68cc cmpne r12, #0 */
/* @0x1d68d0 ldrb r12, [sp, #0x68] */
/* @0x1d68d4 vmov s16, r3 */
/* @0x1d68d8 str r12, [sp, #0x14] */
/* @0x1d68dc beq 0x1d6af0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x250> */
/* @0x1d68e0 cmp r12, #0 */
/* @0x1d68e4 ldr r12, [sp, #0x60] */
/* @0x1d68e8 ldr r0, [r12] */
/* @0x1d68ec beq 0x1d6afc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x25c> */
/* @0x1d68f0 ldr r12, [sp, #0x64] */
/* @0x1d68f4 mov r10, r0 */
/* @0x1d68f8 ldr r7, [r12] */
/* @0x1d68fc vcvt.s32.f32 s17, s17 */
/* @0x1d6900 add r2, sp, #40 */
/* @0x1d6904 add r3, sp, #44 */
/* @0x1d6908 add r11, r5, r6, lsl #8 */
/* @0x1d690c vcvt.s32.f32 s16, s16 */
/* @0x1d6910 vmov r0, s17 */
/* @0x1d6914 vmov r1, s16 */
/* @0x1d6918 bl 0x17a6a0 <_Z23GR_Window_Views_ConvertiiRiS_> */
/* @0x1d691c ldr r3, [pc, #0x20c] */
/* @0x1d6920 ldr r1, [pc, #0x20c] */
/* @0x1d6924 ldr r0, [r4, r3] */
/* @0x1d6928 ldrd r2, r3, [r0] */
/* @0x1d692c strd r2, r3, [sp, #8] */
/* @0x1d6930 adds r2, r2, #1 */
/* @0x1d6934 adc r3, r3, #0 */
/* @0x1d6938 strd r2, r3, [r0] */
/* @0x1d693c ldr r1, [r4, r1] */
/* @0x1d6940 ldr r3, [r1, r11, lsl #2] */
/* @0x1d6944 str r1, [sp, #0x18] */
/* @0x1d6948 cmp r3, #0 */
/* @0x1d694c ble 0x1d6b24 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x284> */
/* @0x1d6950 ldr r2, [pc, #0x1e0] */
/* @0x1d6954 mov r8, #0 */
/* @0x1d6958 ldr r3, [pc, #0x1dc] */
/* @0x1d695c mov r9, r7 */
/* @0x1d6960 ldr r12, [pc, #0x1d8] */
/* @0x1d6964 add r12, pc, r12 */
/* @0x1d6968 str r12, [sp, #0x24] */
/* @0x1d696c ldr r2, [r4, r2] */
/* @0x1d6970 ldr r3, [r4, r3] */
/* @0x1d6974 str r2, [sp, #0x1c] */
/* @0x1d6978 add r3, r3, r11, lsl #3 */
/* @0x1d697c str r3, [sp, #0x20] */
/* @0x1d6980 ldr r12, [sp, #0x1c] */
/* @0x1d6984 ldr r3, [r12] */
/* @0x1d6988 ldr r12, [sp, #0x20] */
/* @0x1d698c ldr r2, [r3, #0x4] */
/* @0x1d6990 ldr r1, [r12, #0x4] */
/* @0x1d6994 ldr r3, [r3] */
/* @0x1d6998 ldr r1, [r1, r8, lsl #2] */
/* @0x1d699c and r2, r1, r2 */
/* @0x1d69a0 ldr r3, [r3, r2, lsl #3] */
/* @0x1d69a4 cmp r3, #0 */
/* @0x1d69a8 bne 0x1d69bc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x11c> */
/* @0x1d69ac b 0x1d6acc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x22c> */
/* @0x1d69b0 ldr r3, [r3, #0x4] */
/* @0x1d69b4 cmp r3, #0 */
/* @0x1d69b8 beq 0x1d6acc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x22c> */
/* @0x1d69bc ldr r2, [r3, #0x8] */
/* @0x1d69c0 cmp r1, r2 */
/* @0x1d69c4 bne 0x1d69b0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x110> */
/* @0x1d69c8 ldr r3, [r3, #0xc] */
/* @0x1d69cc cmp r3, #0 */
/* @0x1d69d0 ldrne r4, [r3, #0xc4] */
/* @0x1d69d4 beq 0x1d6acc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x22c> */
/* @0x1d69d8 cmp r4, #0 */
/* @0x1d69dc beq 0x1d6acc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x22c> */
/* @0x1d69e0 ldr r3, [r4, #0x8] */
/* @0x1d69e4 cmp r3, #0 */
/* @0x1d69e8 beq 0x1d6acc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x22c> */
/* @0x1d69ec ldr r5, [r4, #0x8] */
/* @0x1d69f0 ldr r4, [r4] */
/* @0x1d69f4 ldrb r3, [r5, #0x68] */
/* @0x1d69f8 cmp r3, #0 */
/* @0x1d69fc bne 0x1d69d8 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x138> */
/* @0x1d6a00 ldrb r6, [r5, #0x69] */
/* @0x1d6a04 cmp r6, #0 */
/* @0x1d6a08 bne 0x1d69d8 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x138> */
/* @0x1d6a0c ldrd r2, r3, [r5, #112] */
/* @0x1d6a10 ldrd r0, r1, [sp, #8] */
/* @0x1d6a14 cmp r0, r2 */
/* @0x1d6a18 sbcs r1, r1, r3 */
/* @0x1d6a1c blt 0x1d69d8 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x138> */
/* @0x1d6a20 vldr s15, [sp, #40] */
/* @0x1d6a24 vcvt.f32.s32 s15, s15 */
/* @0x1d6a28 mov r0, r5 */
/* @0x1d6a2c mov r3, #1 */
/* @0x1d6a30 vmov r1, s15 */
/* @0x1d6a34 vldr s15, [sp, #44] */
/* @0x1d6a38 vcvt.f32.s32 s15, s15 */
/* @0x1d6a3c vmov r2, s15 */
/* @0x1d6a40 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1d6a44 cmp r0, #0 */
/* @0x1d6a48 beq 0x1d69d8 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x138> */
/* @0x1d6a4c ldr r12, [sp, #0x14] */
/* @0x1d6a50 cmp r12, #0 */
/* @0x1d6a54 beq 0x1d6a90 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x1f0> */
/* @0x1d6a58 cmp r7, #0 */
/* @0x1d6a5c ldr r1, [r5, #0x78] */
/* @0x1d6a60 ble 0x1d6a90 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x1f0> */
/* @0x1d6a64 ldr r3, [r10] */
/* @0x1d6a68 cmp r1, r3 */
/* @0x1d6a6c beq 0x1d69d8 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x138> */
/* @0x1d6a70 mov r3, r10 */
/* @0x1d6a74 b 0x1d6a84 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x1e4> */
/* @0x1d6a78 ldr r2, [r3, #0x4]! */
/* @0x1d6a7c cmp r1, r2 */
/* @0x1d6a80 beq 0x1d69d8 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x138> */
/* @0x1d6a84 add r6, r6, #1 */
/* @0x1d6a88 cmp r6, r7 */
/* @0x1d6a8c bne 0x1d6a78 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x1d8> */
/* @0x1d6a90 add r9, r9, #1 */
/* @0x1d6a94 mov r0, #0 */
/* @0x1d6a98 mov r3, #74 */
/* @0x1d6a9c str r0, [sp] */
/* @0x1d6aa0 lsl r6, r9, #2 */
/* @0x1d6aa4 mov r0, r10 */
/* @0x1d6aa8 ldr r2, [sp, #0x24] */
/* @0x1d6aac mov r1, r6 */
/* @0x1d6ab0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1d6ab4 ldr r3, [r5, #0x78] */
/* @0x1d6ab8 cmp r4, #0 */
/* @0x1d6abc add r6, r0, r6 */
/* @0x1d6ac0 mov r10, r0 */
/* @0x1d6ac4 str r3, [r6, #-0x4] */
/* @0x1d6ac8 bne 0x1d69e0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x140> */
/* @0x1d6acc ldr r12, [sp, #0x18] */
/* @0x1d6ad0 add r8, r8, #1 */
/* @0x1d6ad4 ldr r3, [r12, r11, lsl #2] */
/* @0x1d6ad8 cmp r8, r3 */
/* @0x1d6adc blt 0x1d6980 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0xe0> */
/* @0x1d6ae0 ldr r12, [sp, #0x64] */
/* @0x1d6ae4 str r9, [r12] */
/* @0x1d6ae8 ldr r12, [sp, #0x60] */
/* @0x1d6aec str r10, [r12] */
/* @0x1d6af0 add sp, sp, #52 */
/* @0x1d6af4 vpop {d8} */
/* @0x1d6af8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d6afc cmp r0, #0 */
/* @0x1d6b00 beq 0x1d68f0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x50> */
/* @0x1d6b04 ldr r10, [sp, #0x14] */
/* @0x1d6b08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d6b0c ldr r7, [sp, #0x14] */
/* @0x1d6b10 ldr r12, [sp, #0x60] */
/* @0x1d6b14 ldr r0, [sp, #0x64] */
/* @0x1d6b18 str r7, [r12] */
/* @0x1d6b1c str r7, [r0] */
/* @0x1d6b20 b 0x1d68fc <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x5c> */
/* @0x1d6b24 mov r9, r7 */
/* @0x1d6b28 b 0x1d6ae0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b+0x240> */
/* @0x1d6b2c mlaeq r1, r0, r3, r11 */
/* @0x1d6b30 .word 0xffffdeb4 */
/* @0x1d6b34 .word 0xffffdeb8 */
/* @0x1d6b38 .word 0xffffbfec */
/* @0x1d6b3c .word 0xffffdebc */
/* @0x1d6b40 andseq r10, r5, r12, asr #13 */

/* ── FUNC 0x1d6b44 · ConvertGestureEventToGMEvent(int, bool) · size=76 · insn=19 */
/* @0x1d6b44 cmp r1, #0 */
/* @0x1d6b48 bne 0x1d6b5c <_Z28ConvertGestureEventToGMEventib+0x18> */
/* @0x1d6b4c cmp r0, #12 */
/* @0x1d6b50 bls 0x1d6b78 <_Z28ConvertGestureEventToGMEventib+0x34> */
/* @0x1d6b54 mvn r0, #0 */
/* @0x1d6b58 bx lr */
/* @0x1d6b5c cmp r0, #12 */
/* @0x1d6b60 bhi 0x1d6b54 <_Z28ConvertGestureEventToGMEventib+0x10> */
/* @0x1d6b64 ldr r3, [pc, #0x1c] */
/* @0x1d6b68 add r3, pc, r3 */
/* @0x1d6b6c add r0, r3, r0, lsl #2 */
/* @0x1d6b70 ldr r0, [r0, #0x34] */
/* @0x1d6b74 bx lr */
/* @0x1d6b78 ldr r3, [pc, #0xc] */
/* @0x1d6b7c add r3, pc, r3 */
/* @0x1d6b80 ldr r0, [r3, r0, lsl #2] */
/* @0x1d6b84 bx lr */
/* @0x1d6b88 andseq r7, r8, r8, lsr #5 */
/* @0x1d6b8c mulseq r8, r4, r2 */

/* ── FUNC 0x1d6b90 · CGestureDrag::Update(long long) · size=1548 · insn=387 */
/* @0x1d6b90 ldr r1, [r0] */
/* @0x1d6b94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d6b98 vpush {d8, d9} */
/* @0x1d6b9c mov r4, r0 */
/* @0x1d6ba0 sub sp, sp, #36 */
/* @0x1d6ba4 ldr r1, [r1, #0x18] */
/* @0x1d6ba8 mov r10, r2 */
/* @0x1d6bac mov r11, r3 */
/* @0x1d6bb0 blx r1 */
/* @0x1d6bb4 ldr r5, [r4, #0x14] */
/* @0x1d6bb8 ldr r6, [pc, #0x5b8] */
/* @0x1d6bbc cmp r5, #0 */
/* @0x1d6bc0 add r6, pc, r6 */
/* @0x1d6bc4 beq 0x1d6bdc <_ZN12CGestureDrag6UpdateEx+0x4c> */
/* @0x1d6bc8 cmp r5, #1 */
/* @0x1d6bcc beq 0x1d6dc4 <_ZN12CGestureDrag6UpdateEx+0x234> */
/* @0x1d6bd0 add sp, sp, #36 */
/* @0x1d6bd4 vpop {d8, d9} */
/* @0x1d6bd8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d6bdc mov r0, #16 */
/* @0x1d6be0 mov r9, #2 */
/* @0x1d6be4 bl 0x27c524 <_Znwj> */
/* @0x1d6be8 ldr lr, [r4] */
/* @0x1d6bec ldr r1, [r4, #0x40] */
/* @0x1d6bf0 mvn r3, #0 */
/* @0x1d6bf4 ldr r12, [r4, #0x44] */
/* @0x1d6bf8 mov r8, #1 */
/* @0x1d6bfc mov r2, r12 */
/* @0x1d6c00 mov r7, r0 */
/* @0x1d6c04 mov r0, r4 */
/* @0x1d6c08 str r5, [r7, #0x8] */
/* @0x1d6c0c str r3, [r7, #0x4] */
/* @0x1d6c10 mov r3, r1 */
/* @0x1d6c14 str r5, [r7, #0xc] */
/* @0x1d6c18 str r9, [r7] */
/* @0x1d6c1c strd r10, r11, [sp, #8] */
/* @0x1d6c20 add r10, r4, #16 */
/* @0x1d6c24 str r12, [sp] */
/* @0x1d6c28 add r11, r4, #12 */
/* @0x1d6c2c ldr r12, [lr, #0x1c] */
/* @0x1d6c30 blx r12 */
/* @0x1d6c34 mov r1, r5 */
/* @0x1d6c38 str r0, [r7, #0x4] */
/* @0x1d6c3c mov r0, r9 */
/* @0x1d6c40 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d6c44 ldr r2, [r4, #0x40] */
/* @0x1d6c48 ldr r3, [r4, #0x44] */
/* @0x1d6c4c str r5, [sp, #0x8] */
/* @0x1d6c50 vmov s14, r2 */
/* @0x1d6c54 str r11, [sp] */
/* @0x1d6c58 vmov s15, r3 */
/* @0x1d6c5c str r10, [sp, #0x4] */
/* @0x1d6c60 vcvt.f32.s32 s14, s14 */
/* @0x1d6c64 vcvt.f32.s32 s15, s15 */
/* @0x1d6c68 vmov r2, s14 */
/* @0x1d6c6c vmov r3, s15 */
/* @0x1d6c70 mov r1, r0 */
/* @0x1d6c74 mov r0, #13 */
/* @0x1d6c78 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d6c7c mov r1, r5 */
/* @0x1d6c80 mov r0, #3 */
/* @0x1d6c84 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d6c88 ldr r2, [r4, #0x40] */
/* @0x1d6c8c ldr r3, [r4, #0x44] */
/* @0x1d6c90 str r11, [sp] */
/* @0x1d6c94 vmov s14, r2 */
/* @0x1d6c98 str r10, [sp, #0x4] */
/* @0x1d6c9c vmov s15, r3 */
/* @0x1d6ca0 str r8, [sp, #0x8] */
/* @0x1d6ca4 vcvt.f32.s32 s14, s14 */
/* @0x1d6ca8 vcvt.f32.s32 s15, s15 */
/* @0x1d6cac vmov r2, s14 */
/* @0x1d6cb0 vmov r3, s15 */
/* @0x1d6cb4 mov r1, r0 */
/* @0x1d6cb8 mov r0, #13 */
/* @0x1d6cbc bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d6cc0 mov r1, r5 */
/* @0x1d6cc4 mov r0, #4 */
/* @0x1d6cc8 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d6ccc ldr r2, [r4, #0x40] */
/* @0x1d6cd0 ldr r3, [r4, #0x44] */
/* @0x1d6cd4 str r11, [sp] */
/* @0x1d6cd8 vmov s14, r2 */
/* @0x1d6cdc str r10, [sp, #0x4] */
/* @0x1d6ce0 vmov s15, r3 */
/* @0x1d6ce4 str r8, [sp, #0x8] */
/* @0x1d6ce8 vcvt.f32.s32 s14, s14 */
/* @0x1d6cec vcvt.f32.s32 s15, s15 */
/* @0x1d6cf0 vmov r2, s14 */
/* @0x1d6cf4 vmov r3, s15 */
/* @0x1d6cf8 mov r1, r0 */
/* @0x1d6cfc mov r0, #13 */
/* @0x1d6d00 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d6d04 mov r1, r5 */
/* @0x1d6d08 mov r0, #5 */
/* @0x1d6d0c bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d6d10 ldr r2, [r4, #0x40] */
/* @0x1d6d14 ldr r3, [r4, #0x44] */
/* @0x1d6d18 str r11, [sp] */
/* @0x1d6d1c vmov s14, r2 */
/* @0x1d6d20 str r10, [sp, #0x4] */
/* @0x1d6d24 vmov s15, r3 */
/* @0x1d6d28 str r8, [sp, #0x8] */
/* @0x1d6d2c vcvt.f32.s32 s14, s14 */
/* @0x1d6d30 vcvt.f32.s32 s15, s15 */
/* @0x1d6d34 vmov r2, s14 */
/* @0x1d6d38 vmov r3, s15 */
/* @0x1d6d3c mov r1, r0 */
/* @0x1d6d40 mov r0, #13 */
/* @0x1d6d44 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d6d48 ldr r2, [r4, #0xc] */
/* @0x1d6d4c ldr r12, [r4, #0x10] */
/* @0x1d6d50 mov r3, r8 */
/* @0x1d6d54 ldr r1, [pc, #0x420] */
/* @0x1d6d58 mov r0, #12 */
/* @0x1d6d5c str r2, [r7, #0x8] */
/* @0x1d6d60 mov r2, #143 */
/* @0x1d6d64 str r12, [r7, #0xc] */
/* @0x1d6d68 ldr r6, [r6, r1] */
/* @0x1d6d6c ldr r1, [pc, #0x40c] */
/* @0x1d6d70 ldr r12, [r6, #0x8] */
/* @0x1d6d74 add r1, pc, r1 */
/* @0x1d6d78 add r12, r12, r8 */
/* @0x1d6d7c str r12, [r6, #0x8] */
/* @0x1d6d80 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d6d84 ldr r3, [r6, #0x4] */
/* @0x1d6d88 cmp r3, #0 */
/* @0x1d6d8c str r7, [r0, #0x8] */
/* @0x1d6d90 streq r0, [r6, #0x4] */
/* @0x1d6d94 strne r0, [r3] */
/* @0x1d6d98 streq r3, [r0, #0x4] */
/* @0x1d6d9c strne r3, [r0, #0x4] */
/* @0x1d6da0 streq r0, [r6] */
/* @0x1d6da4 strne r0, [r6, #0x4] */
/* @0x1d6da8 streq r3, [r0] */
/* @0x1d6dac mov r3, #1 */
/* @0x1d6db0 strne r5, [r0] */
/* @0x1d6db4 str r3, [r4, #0x14] */
/* @0x1d6db8 add sp, sp, #36 */
/* @0x1d6dbc vpop {d8, d9} */
/* @0x1d6dc0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d6dc4 mov r0, r5 */
/* @0x1d6dc8 ldr r1, [r4, #0x28] */
/* @0x1d6dcc bl 0x18c0b4 <_Z14IO_Button_Downii> */
/* @0x1d6dd0 subs r8, r0, #0 */
/* @0x1d6dd4 beq 0x1d6eb4 <_ZN12CGestureDrag6UpdateEx+0x324> */
/* @0x1d6dd8 ldr r2, [r4, #0x30] */
/* @0x1d6ddc ldr r3, [r4, #0x38] */
/* @0x1d6de0 cmp r2, r3 */
/* @0x1d6de4 bne 0x1d6df8 <_ZN12CGestureDrag6UpdateEx+0x268> */
/* @0x1d6de8 ldr r2, [r4, #0x34] */
/* @0x1d6dec ldr r3, [r4, #0x3c] */
/* @0x1d6df0 cmp r2, r3 */
/* @0x1d6df4 beq 0x1d6bd0 <_ZN12CGestureDrag6UpdateEx+0x40> */
/* @0x1d6df8 mov r0, #16 */
/* @0x1d6dfc mov r7, #0 */
/* @0x1d6e00 bl 0x27c524 <_Znwj> */
/* @0x1d6e04 ldr lr, [r4, #0x3c] */
/* @0x1d6e08 ldr r12, [r4] */
/* @0x1d6e0c mvn r9, #0 */
/* @0x1d6e10 ldr r1, [r4, #0x30] */
/* @0x1d6e14 mov r8, #3 */
/* @0x1d6e18 ldr r2, [r4, #0x34] */
/* @0x1d6e1c ldr r3, [r4, #0x38] */
/* @0x1d6e20 mov r5, r0 */
/* @0x1d6e24 mov r0, r4 */
/* @0x1d6e28 str r7, [r5, #0x8] */
/* @0x1d6e2c stm r5, {r8, r9} */
/* @0x1d6e30 str r7, [r5, #0xc] */
/* @0x1d6e34 str lr, [sp] */
/* @0x1d6e38 strd r10, r11, [sp, #8] */
/* @0x1d6e3c ldr r12, [r12, #0x1c] */
/* @0x1d6e40 blx r12 */
/* @0x1d6e44 ldr r1, [r4, #0x10] */
/* @0x1d6e48 ldr lr, [r4, #0xc] */
/* @0x1d6e4c mov r3, #1 */
/* @0x1d6e50 ldr r12, [pc, #0x324] */
/* @0x1d6e54 mov r2, #143 */
/* @0x1d6e58 str r1, [r5, #0xc] */
/* @0x1d6e5c str lr, [r5, #0x8] */
/* @0x1d6e60 ldr r1, [pc, #0x31c] */
/* @0x1d6e64 add r1, pc, r1 */
/* @0x1d6e68 str r0, [r5, #0x4] */
/* @0x1d6e6c mov r0, #12 */
/* @0x1d6e70 ldr r4, [r6, r12] */
/* @0x1d6e74 ldr r12, [r4, #0x8] */
/* @0x1d6e78 add r12, r12, r3 */
/* @0x1d6e7c str r12, [r4, #0x8] */
/* @0x1d6e80 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d6e84 ldr r3, [r4, #0x4] */
/* @0x1d6e88 cmp r3, r7 */
/* @0x1d6e8c str r5, [r0, #0x8] */
/* @0x1d6e90 streq r0, [r4, #0x4] */
/* @0x1d6e94 strne r0, [r3] */
/* @0x1d6e98 streq r0, [r4] */
/* @0x1d6e9c strne r3, [r0, #0x4] */
/* @0x1d6ea0 streq r3, [r0, #0x4] */
/* @0x1d6ea4 strne r0, [r4, #0x4] */
/* @0x1d6ea8 streq r3, [r0] */
/* @0x1d6eac strne r7, [r0] */
/* @0x1d6eb0 b 0x1d6bd0 <_ZN12CGestureDrag6UpdateEx+0x40> */
/* @0x1d6eb4 mov r0, #16 */
/* @0x1d6eb8 mvn r9, #0 */
/* @0x1d6ebc bl 0x27c524 <_Znwj> */
/* @0x1d6ec0 ldr lr, [r4, #0x3c] */
/* @0x1d6ec4 ldr r12, [r4] */
/* @0x1d6ec8 ldr r1, [r4, #0x30] */
/* @0x1d6ecc str lr, [sp, #0x14] */
/* @0x1d6ed0 mov lr, #4 */
/* @0x1d6ed4 ldr r2, [r4, #0x34] */
/* @0x1d6ed8 ldr r3, [r4, #0x38] */
/* @0x1d6edc mov r7, r0 */
/* @0x1d6ee0 mov r0, r4 */
/* @0x1d6ee4 str lr, [r7] */
/* @0x1d6ee8 ldr lr, [sp, #0x14] */
/* @0x1d6eec str r8, [r7, #0x8] */
/* @0x1d6ef0 str r8, [r7, #0xc] */
/* @0x1d6ef4 str r9, [r7, #0x4] */
/* @0x1d6ef8 str lr, [sp] */
/* @0x1d6efc strd r10, r11, [sp, #8] */
/* @0x1d6f00 ldr r12, [r12, #0x1c] */
/* @0x1d6f04 blx r12 */
/* @0x1d6f08 ldrd r2, r3, [r4, #32] */
/* @0x1d6f0c vldr s14, [r4, #56] */
/* @0x1d6f10 vldr s15, [r4, #60] */
/* @0x1d6f14 vcvt.f32.s32 s16, s14 */
/* @0x1d6f18 mov r1, r11 */
/* @0x1d6f1c vldr s14, [r4, #48] */
/* @0x1d6f20 vcvt.f32.s32 s19, s15 */
/* @0x1d6f24 vldr s15, [r4, #52] */
/* @0x1d6f28 vcvt.f32.s32 s18, s14 */
/* @0x1d6f2c vcvt.f32.s32 s17, s15 */
/* @0x1d6f30 str r0, [r7, #0x4] */
/* @0x1d6f34 mov r0, r10 */
/* @0x1d6f38 subs r0, r0, r2 */
/* @0x1d6f3c sbc r1, r1, r3 */
/* @0x1d6f40 bl 0x319398 <__floatdisf> */
/* @0x1d6f44 vldr s15, [pc, #552] */
/* @0x1d6f48 vmov r3, s17 */
/* @0x1d6f4c add r12, sp, #24 */
/* @0x1d6f50 vmov r1, s19 */
/* @0x1d6f54 vmov r2, s18 */
/* @0x1d6f58 str r12, [sp, #0x4] */
/* @0x1d6f5c add r12, sp, #28 */
/* @0x1d6f60 str r12, [sp, #0x8] */
/* @0x1d6f64 vmov s14, r0 */
/* @0x1d6f68 vmov r0, s16 */
/* @0x1d6f6c vdiv.f32 s15, s14, s15 */
/* @0x1d6f70 vstr s15, [sp] */
/* @0x1d6f74 bl 0x1d6854 <_Z12CalcVelocityfffffRfS_> */
/* @0x1d6f78 vldr s14, [sp, #24] */
/* @0x1d6f7c vldr s15, [sp, #28] */
/* @0x1d6f80 vcvt.s32.f32 s14, s14 */
/* @0x1d6f84 vcvt.s32.f32 s15, s15 */
/* @0x1d6f88 vmov r0, s14 */
/* @0x1d6f8c vmov r1, s15 */
/* @0x1d6f90 bl 0x1d6708 <_Z14CalcDistInchesii> */
/* @0x1d6f94 ldr r3, [pc, #0x1ec] */
/* @0x1d6f98 ldr r3, [r6, r3] */
/* @0x1d6f9c vldr s15, [r3] */
/* @0x1d6fa0 vmov s14, r0 */
/* @0x1d6fa4 ldr r0, [r7, #0x4] */
/* @0x1d6fa8 vcmpe.f32 s14, s15 */
/* @0x1d6fac vmrs APSR_nzcv, fpscr */
/* @0x1d6fb0 ble 0x1d704c <_ZN12CGestureDrag6UpdateEx+0x4bc> */
/* @0x1d6fb4 ldr r1, [pc, #0x1d0] */
/* @0x1d6fb8 mov r3, #0 */
/* @0x1d6fbc mov r2, #0 */
/* @0x1d6fc0 movt r3, #0x3ff0 */
/* @0x1d6fc4 add r1, pc, r1 */
/* @0x1d6fc8 bl 0x20bf40 <_Z10AddToDsMapiPcd> */
/* @0x1d6fcc ldr r12, [r4, #0x10] */
/* @0x1d6fd0 mov r2, #143 */
/* @0x1d6fd4 ldr lr, [r4, #0xc] */
/* @0x1d6fd8 mov r3, #1 */
/* @0x1d6fdc ldr r1, [pc, #0x198] */
/* @0x1d6fe0 mov r0, #12 */
/* @0x1d6fe4 str r12, [r7, #0xc] */
/* @0x1d6fe8 str lr, [r7, #0x8] */
/* @0x1d6fec ldr r6, [r6, r1] */
/* @0x1d6ff0 ldr r1, [pc, #0x198] */
/* @0x1d6ff4 ldr r12, [r6, #0x8] */
/* @0x1d6ff8 add r1, pc, r1 */
/* @0x1d6ffc add r12, r12, r3 */
/* @0x1d7000 str r12, [r6, #0x8] */
/* @0x1d7004 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d7008 ldr r3, [r6, #0x4] */
/* @0x1d700c cmp r3, #0 */
/* @0x1d7010 movne r2, #0 */
/* @0x1d7014 streq r0, [r6, #0x4] */
/* @0x1d7018 streq r0, [r6] */
/* @0x1d701c str r7, [r0, #0x8] */
/* @0x1d7020 streq r3, [r0, #0x4] */
/* @0x1d7024 strne r0, [r3] */
/* @0x1d7028 streq r3, [r0] */
/* @0x1d702c strne r3, [r0, #0x4] */
/* @0x1d7030 strne r0, [r6, #0x4] */
/* @0x1d7034 strne r2, [r0] */
/* @0x1d7038 cmp r5, #0 */
/* @0x1d703c bne 0x1d7068 <_ZN12CGestureDrag6UpdateEx+0x4d8> */
/* @0x1d7040 mvn r3, #0 */
/* @0x1d7044 str r3, [r4, #0x14] */
/* @0x1d7048 b 0x1d6bd0 <_ZN12CGestureDrag6UpdateEx+0x40> */
/* @0x1d704c ldr r1, [pc, #0x140] */
/* @0x1d7050 mov r2, #0 */
/* @0x1d7054 mov r3, #0 */
/* @0x1d7058 mov r5, r8 */
/* @0x1d705c add r1, pc, r1 */
/* @0x1d7060 bl 0x20bf40 <_Z10AddToDsMapiPcd> */
/* @0x1d7064 b 0x1d6fcc <_ZN12CGestureDrag6UpdateEx+0x43c> */
/* @0x1d7068 mov r0, #16 */
/* @0x1d706c mov r7, #0 */
/* @0x1d7070 bl 0x27c524 <_Znwj> */
/* @0x1d7074 ldr lr, [r4, #0x3c] */
/* @0x1d7078 ldr r2, [r4, #0x34] */
/* @0x1d707c mvn r9, #0 */
/* @0x1d7080 ldr r3, [r4, #0x38] */
/* @0x1d7084 mov r8, #1 */
/* @0x1d7088 str lr, [sp, #0x14] */
/* @0x1d708c mov lr, #5 */
/* @0x1d7090 ldr r12, [r4] */
/* @0x1d7094 ldr r1, [r4, #0x30] */
/* @0x1d7098 mov r5, r0 */
/* @0x1d709c mov r0, r4 */
/* @0x1d70a0 str lr, [r5] */
/* @0x1d70a4 ldr lr, [sp, #0x14] */
/* @0x1d70a8 str r7, [r5, #0x8] */
/* @0x1d70ac str r9, [r5, #0x4] */
/* @0x1d70b0 str r7, [r5, #0xc] */
/* @0x1d70b4 str lr, [sp] */
/* @0x1d70b8 strd r10, r11, [sp, #8] */
/* @0x1d70bc ldr r12, [r12, #0x1c] */
/* @0x1d70c0 blx r12 */
/* @0x1d70c4 mov r1, r7 */
/* @0x1d70c8 str r0, [r5, #0x4] */
/* @0x1d70cc ldr r0, [r5] */
/* @0x1d70d0 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d70d4 ldr r2, [r4, #0x30] */
/* @0x1d70d8 ldr r3, [r4, #0x34] */
/* @0x1d70dc add r12, r4, #12 */
/* @0x1d70e0 str r12, [sp] */
/* @0x1d70e4 vmov s14, r2 */
/* @0x1d70e8 vmov s15, r3 */
/* @0x1d70ec vcvt.f32.s32 s14, s14 */
/* @0x1d70f0 vcvt.f32.s32 s15, s15 */
/* @0x1d70f4 vmov r2, s14 */
/* @0x1d70f8 vmov r3, s15 */
/* @0x1d70fc mov r1, r0 */
/* @0x1d7100 add r0, r4, #16 */
/* @0x1d7104 stmib sp, {r0, r8} */
/* @0x1d7108 mov r0, #13 */
/* @0x1d710c bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b> */
/* @0x1d7110 ldr r1, [r4, #0x10] */
/* @0x1d7114 ldr r2, [r4, #0xc] */
/* @0x1d7118 mov r3, r8 */
/* @0x1d711c ldr r12, [r6, #0x8] */
/* @0x1d7120 mov r0, #12 */
/* @0x1d7124 str r1, [r5, #0xc] */
/* @0x1d7128 ldr r1, [pc, #0x68] */
/* @0x1d712c add r12, r12, r8 */
/* @0x1d7130 str r2, [r5, #0x8] */
/* @0x1d7134 mov r2, #143 */
/* @0x1d7138 add r1, pc, r1 */
/* @0x1d713c str r12, [r6, #0x8] */
/* @0x1d7140 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d7144 ldr r3, [r6, #0x4] */
/* @0x1d7148 cmp r3, r7 */
/* @0x1d714c str r5, [r0, #0x8] */
/* @0x1d7150 streq r0, [r6, #0x4] */
/* @0x1d7154 strne r0, [r3] */
/* @0x1d7158 streq r0, [r6] */
/* @0x1d715c strne r3, [r0, #0x4] */
/* @0x1d7160 streq r3, [r0, #0x4] */
/* @0x1d7164 strne r0, [r6, #0x4] */
/* @0x1d7168 streq r3, [r0] */
/* @0x1d716c strne r7, [r0] */
/* @0x1d7170 b 0x1d7040 <_ZN12CGestureDrag6UpdateEx+0x4b0> */
/* @0x1d7174 ldmdbmi r4!, {r10, sp} ^ */
/* @0x1d7178 mlaeq r1, r0, r0, r11 */
/* @0x1d717c .word 0xffffefb0 */
/* @0x1d7180 ldrheq r6, [r7], -r12 */
/* @0x1d7184 andseq r5, r7, r12, asr #31 */
/* @0x1d7188 .word 0xffffef7c */
/* @0x1d718c andseq r10, r7, r0, lsr #3 */
/* @0x1d7190 andseq r5, r7, r8, lsr lr */
/* @0x1d7194 andseq r10, r7, r8, lsl #2 */
/* @0x1d7198 ldrsheq r5, [r7], -r8 */

/* ── FUNC 0x1d719c · ProcessGestureEvents() · size=768 · insn=192 */
/* @0x1d719c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d71a0 sub sp, sp, #44 */
/* @0x1d71a4 ldr r10, [pc, #0x2d0] */
/* @0x1d71a8 ldr r3, [pc, #0x2d0] */
/* @0x1d71ac add r10, pc, r10 */
/* @0x1d71b0 str r10, [sp, #0x1c] */
/* @0x1d71b4 ldr r3, [r10, r3] */
/* @0x1d71b8 ldr r3, [r3] */
/* @0x1d71bc cmp r3, #0 */
/* @0x1d71c0 str r3, [sp, #0x18] */
/* @0x1d71c4 beq 0x1d7474 <_Z20ProcessGestureEventsv+0x2d8> */
/* @0x1d71c8 ldr r3, [r3, #0x8] */
/* @0x1d71cc cmp r3, #0 */
/* @0x1d71d0 beq 0x1d7474 <_Z20ProcessGestureEventsv+0x2d8> */
/* @0x1d71d4 ldr r1, [pc, #0x2a8] */
/* @0x1d71d8 ldr r2, [pc, #0x2a8] */
/* @0x1d71dc ldr r3, [pc, #0x2a8] */
/* @0x1d71e0 ldr r1, [r10, r1] */
/* @0x1d71e4 str r1, [sp, #0x20] */
/* @0x1d71e8 ldr r2, [r10, r2] */
/* @0x1d71ec str r2, [sp, #0x24] */
/* @0x1d71f0 ldr r11, [r10, r3] */
/* @0x1d71f4 ldr r12, [sp, #0x18] */
/* @0x1d71f8 mov r1, #0 */
/* @0x1d71fc ldr r6, [r12, #0x8] */
/* @0x1d7200 ldr r0, [r6] */
/* @0x1d7204 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d7208 ldr r3, [sp, #0x20] */
/* @0x1d720c ldr r1, [r6, #0xc] */
/* @0x1d7210 ldr r10, [sp, #0x20] */
/* @0x1d7214 ldrd r2, r3, [r3] */
/* @0x1d7218 ldr r12, [sp, #0x24] */
/* @0x1d721c strd r2, r3, [sp, #8] */
/* @0x1d7220 adds r2, r2, #1 */
/* @0x1d7224 adc r3, r3, #0 */
/* @0x1d7228 cmp r1, #0 */
/* @0x1d722c mov r5, r0 */
/* @0x1d7230 ldr r0, [r6, #0x4] */
/* @0x1d7234 strd r2, r3, [r10] */
/* @0x1d7238 str r0, [r12] */
/* @0x1d723c ble 0x1d7310 <_Z20ProcessGestureEventsv+0x174> */
/* @0x1d7240 mov r7, r11 */
/* @0x1d7244 ldr r8, [sp, #0x1c] */
/* @0x1d7248 ldrd r10, r11, [sp, #8] */
/* @0x1d724c mov r4, #0 */
/* @0x1d7250 ldr r3, [r6, #0x8] */
/* @0x1d7254 ldr r0, [r3, r4, lsl #2] */
/* @0x1d7258 cmp r0, #0 */
/* @0x1d725c blt 0x1d7300 <_Z20ProcessGestureEventsv+0x164> */
/* @0x1d7260 ldr r3, [pc, #0x228] */
/* @0x1d7264 ldr r3, [r8, r3] */
/* @0x1d7268 ldr r2, [r3, #0x4] */
/* @0x1d726c ldr r3, [r3] */
/* @0x1d7270 and r2, r0, r2 */
/* @0x1d7274 ldr r3, [r3, r2, lsl #3] */
/* @0x1d7278 cmp r3, #0 */
/* @0x1d727c bne 0x1d7290 <_Z20ProcessGestureEventsv+0xf4> */
/* @0x1d7280 b 0x1d7300 <_Z20ProcessGestureEventsv+0x164> */
/* @0x1d7284 ldr r3, [r3, #0x4] */
/* @0x1d7288 cmp r3, #0 */
/* @0x1d728c beq 0x1d7300 <_Z20ProcessGestureEventsv+0x164> */
/* @0x1d7290 ldr r2, [r3, #0x8] */
/* @0x1d7294 cmp r0, r2 */
/* @0x1d7298 bne 0x1d7284 <_Z20ProcessGestureEventsv+0xe8> */
/* @0x1d729c ldr r9, [r3, #0xc] */
/* @0x1d72a0 cmp r9, #0 */
/* @0x1d72a4 beq 0x1d7300 <_Z20ProcessGestureEventsv+0x164> */
/* @0x1d72a8 ldrb r2, [r9, #0x68] */
/* @0x1d72ac cmp r2, #0 */
/* @0x1d72b0 bne 0x1d7300 <_Z20ProcessGestureEventsv+0x164> */
/* @0x1d72b4 ldrb r2, [r9, #0x69] */
/* @0x1d72b8 cmp r2, #0 */
/* @0x1d72bc bne 0x1d7300 <_Z20ProcessGestureEventsv+0x164> */
/* @0x1d72c0 ldrd r2, r3, [r9, #112] */
/* @0x1d72c4 cmp r10, r2 */
/* @0x1d72c8 sbcs r0, r11, r3 */
/* @0x1d72cc blt 0x1d7300 <_Z20ProcessGestureEventsv+0x164> */
/* @0x1d72d0 ldr r0, [r9, #0x80] */
/* @0x1d72d4 mov r1, #13 */
/* @0x1d72d8 mov r2, r5 */
/* @0x1d72dc bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii> */
/* @0x1d72e0 cmp r0, #0 */
/* @0x1d72e4 beq 0x1d72fc <_Z20ProcessGestureEventsv+0x160> */
/* @0x1d72e8 mov r0, r9 */
/* @0x1d72ec mov r2, #13 */
/* @0x1d72f0 mov r1, r9 */
/* @0x1d72f4 mov r3, r5 */
/* @0x1d72f8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d72fc ldr r1, [r6, #0xc] */
/* @0x1d7300 add r4, r4, #1 */
/* @0x1d7304 cmp r1, r4 */
/* @0x1d7308 bgt 0x1d7250 <_Z20ProcessGestureEventsv+0xb4> */
/* @0x1d730c mov r11, r7 */
/* @0x1d7310 ldr r0, [r6] */
/* @0x1d7314 mov r1, #1 */
/* @0x1d7318 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib> */
/* @0x1d731c add r9, r0, #3328 */
/* @0x1d7320 mov r8, r0 */
/* @0x1d7324 ldr r3, [r11, r9, lsl #2] */
/* @0x1d7328 cmp r3, #0 */
/* @0x1d732c ble 0x1d7444 <_Z20ProcessGestureEventsv+0x2a8> */
/* @0x1d7330 ldr r12, [sp, #0x1c] */
/* @0x1d7334 mov r7, #0 */
/* @0x1d7338 ldr r2, [pc, #0x154] */
/* @0x1d733c ldr r3, [pc, #0x154] */
/* @0x1d7340 ldr r10, [r12, r2] */
/* @0x1d7344 ldr r3, [r12, r3] */
/* @0x1d7348 add r10, r10, r9, lsl #3 */
/* @0x1d734c str r3, [sp, #0x14] */
/* @0x1d7350 mov r3, r10 */
/* @0x1d7354 mov r10, r11 */
/* @0x1d7358 mov r11, r3 */
/* @0x1d735c ldr r12, [sp, #0x14] */
/* @0x1d7360 ldr r1, [r11, #0x4] */
/* @0x1d7364 ldr r3, [r12] */
/* @0x1d7368 ldr r1, [r1, r7, lsl #2] */
/* @0x1d736c ldr r2, [r3, #0x4] */
/* @0x1d7370 ldr r3, [r3] */
/* @0x1d7374 and r2, r1, r2 */
/* @0x1d7378 ldr r3, [r3, r2, lsl #3] */
/* @0x1d737c cmp r3, #0 */
/* @0x1d7380 bne 0x1d7394 <_Z20ProcessGestureEventsv+0x1f8> */
/* @0x1d7384 b 0x1d7430 <_Z20ProcessGestureEventsv+0x294> */
/* @0x1d7388 ldr r3, [r3, #0x4] */
/* @0x1d738c cmp r3, #0 */
/* @0x1d7390 beq 0x1d7430 <_Z20ProcessGestureEventsv+0x294> */
/* @0x1d7394 ldr r2, [r3, #0x8] */
/* @0x1d7398 cmp r1, r2 */
/* @0x1d739c bne 0x1d7388 <_Z20ProcessGestureEventsv+0x1ec> */
/* @0x1d73a0 ldr r3, [r3, #0xc] */
/* @0x1d73a4 cmp r3, #0 */
/* @0x1d73a8 beq 0x1d7430 <_Z20ProcessGestureEventsv+0x294> */
/* @0x1d73ac ldr r6, [r3, #0xc4] */
/* @0x1d73b0 cmp r6, #0 */
/* @0x1d73b4 beq 0x1d7430 <_Z20ProcessGestureEventsv+0x294> */
/* @0x1d73b8 ldr r3, [r6, #0x8] */
/* @0x1d73bc cmp r3, #0 */
/* @0x1d73c0 beq 0x1d7430 <_Z20ProcessGestureEventsv+0x294> */
/* @0x1d73c4 str r10, [sp, #0x10] */
/* @0x1d73c8 str r11, [sp, #0x4] */
/* @0x1d73cc b 0x1d73dc <_Z20ProcessGestureEventsv+0x240> */
/* @0x1d73d0 ldr r3, [r6, #0x8] */
/* @0x1d73d4 cmp r3, #0 */
/* @0x1d73d8 beq 0x1d7428 <_Z20ProcessGestureEventsv+0x28c> */
/* @0x1d73dc ldr r0, [r6, #0x8] */
/* @0x1d73e0 ldr r6, [r6] */
/* @0x1d73e4 ldrb r3, [r0, #0x68] */
/* @0x1d73e8 cmp r3, #0 */
/* @0x1d73ec bne 0x1d7420 <_Z20ProcessGestureEventsv+0x284> */
/* @0x1d73f0 ldrb r3, [r0, #0x69] */
/* @0x1d73f4 cmp r3, #0 */
/* @0x1d73f8 bne 0x1d7420 <_Z20ProcessGestureEventsv+0x284> */
/* @0x1d73fc ldrd r4, r5, [r0, #112] */
/* @0x1d7400 mov r1, r0 */
/* @0x1d7404 ldrd r10, r11, [sp, #8] */
/* @0x1d7408 mov r2, #13 */
/* @0x1d740c mov r3, r8 */
/* @0x1d7410 cmp r10, r4 */
/* @0x1d7414 sbcs r11, r11, r5 */
/* @0x1d7418 blt 0x1d7420 <_Z20ProcessGestureEventsv+0x284> */
/* @0x1d741c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1d7420 cmp r6, #0 */
/* @0x1d7424 bne 0x1d73d0 <_Z20ProcessGestureEventsv+0x234> */
/* @0x1d7428 ldr r10, [sp, #0x10] */
/* @0x1d742c ldr r11, [sp, #0x4] */
/* @0x1d7430 ldr r3, [r10, r9, lsl #2] */
/* @0x1d7434 add r7, r7, #1 */
/* @0x1d7438 cmp r3, r7 */
/* @0x1d743c bgt 0x1d735c <_Z20ProcessGestureEventsv+0x1c0> */
/* @0x1d7440 mov r11, r10 */
/* @0x1d7444 ldr r10, [sp, #0x18] */
/* @0x1d7448 mvn r0, #0 */
/* @0x1d744c ldr r12, [sp, #0x24] */
/* @0x1d7450 ldr r10, [r10] */
/* @0x1d7454 str r0, [r12] */
/* @0x1d7458 cmp r10, #0 */
/* @0x1d745c str r10, [sp, #0x18] */
/* @0x1d7460 beq 0x1d7474 <_Z20ProcessGestureEventsv+0x2d8> */
/* @0x1d7464 ldr r12, [sp, #0x18] */
/* @0x1d7468 ldr r3, [r12, #0x8] */
/* @0x1d746c cmp r3, #0 */
/* @0x1d7470 bne 0x1d71f4 <_Z20ProcessGestureEventsv+0x58> */
/* @0x1d7474 add sp, sp, #44 */
/* @0x1d7478 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1d747c eoreq r10, r1, r4, lsr #21 */
/* @0x1d7480 .word 0xffffefb0 */
/* @0x1d7484 .word 0xffffdeb4 */
/* @0x1d7488 .word 0xffffbce8 */
/* @0x1d748c .word 0xffffdeb8 */
/* @0x1d7490 .word 0xffffbff4 */
/* @0x1d7494 .word 0xffffdebc */
/* @0x1d7498 .word 0xffffbfec */

/* ── FUNC 0x1d749c · IsTouchDown(int, int) · size=192 · insn=48 */
/* @0x1d749c ldr r3, [pc, #0xb4] */
/* @0x1d74a0 cmn r1, #1 */
/* @0x1d74a4 ldr r3, [pc, r3] */
/* @0x1d74a8 ldr r12, [r3] */
/* @0x1d74ac beq 0x1d7504 <_Z11IsTouchDownii+0x68> */
/* @0x1d74b0 cmp r12, #0 */
/* @0x1d74b4 beq 0x1d74dc <_Z11IsTouchDownii+0x40> */
/* @0x1d74b8 ldr r2, [r12, #0x8] */
/* @0x1d74bc cmp r2, #0 */
/* @0x1d74c0 beq 0x1d7550 <_Z11IsTouchDownii+0xb4> */
/* @0x1d74c4 ldrb r3, [r2, #0x830] */
/* @0x1d74c8 cmp r3, #0 */
/* @0x1d74cc beq 0x1d74e4 <_Z11IsTouchDownii+0x48> */
/* @0x1d74d0 ldr r12, [r12] */
/* @0x1d74d4 cmp r12, #0 */
/* @0x1d74d8 bne 0x1d74b8 <_Z11IsTouchDownii+0x1c> */
/* @0x1d74dc mov r0, r12 */
/* @0x1d74e0 bx lr */
/* @0x1d74e4 ldr r3, [r2] */
/* @0x1d74e8 cmp r3, r0 */
/* @0x1d74ec bne 0x1d74d0 <_Z11IsTouchDownii+0x34> */
/* @0x1d74f0 ldr r3, [r2, #0x4] */
/* @0x1d74f4 cmp r3, r1 */
/* @0x1d74f8 bne 0x1d74d0 <_Z11IsTouchDownii+0x34> */
/* @0x1d74fc mov r0, #1 */
/* @0x1d7500 bx lr */
/* @0x1d7504 cmp r12, #0 */
/* @0x1d7508 beq 0x1d74dc <_Z11IsTouchDownii+0x40> */
/* @0x1d750c ldr r3, [r12, #0x8] */
/* @0x1d7510 cmp r3, #0 */
/* @0x1d7514 beq 0x1d7548 <_Z11IsTouchDownii+0xac> */
/* @0x1d7518 ldrb r2, [r3, #0x830] */
/* @0x1d751c cmp r2, #0 */
/* @0x1d7520 beq 0x1d7534 <_Z11IsTouchDownii+0x98> */
/* @0x1d7524 ldr r12, [r12] */
/* @0x1d7528 cmp r12, #0 */
/* @0x1d752c bne 0x1d750c <_Z11IsTouchDownii+0x70> */
/* @0x1d7530 b 0x1d74dc <_Z11IsTouchDownii+0x40> */
/* @0x1d7534 ldr r3, [r3] */
/* @0x1d7538 cmp r3, r0 */
/* @0x1d753c bne 0x1d7524 <_Z11IsTouchDownii+0x88> */
/* @0x1d7540 mov r0, #1 */
/* @0x1d7544 bx lr */
/* @0x1d7548 mov r0, r3 */
/* @0x1d754c bx lr */
/* @0x1d7550 mov r0, r2 */
/* @0x1d7554 bx lr */
/* @0x1d7558 eoreq r9, r1, r0, ror #14 */
