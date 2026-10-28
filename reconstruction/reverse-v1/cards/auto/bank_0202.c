/* libyoyo.so 覆盖卡组 0202
 * 函数 0x223474..0x2247c0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x223474 · SOggChannel::Init(unsigned int) · size=92 · insn=23 */
/* @0x223474 push {r4, lr} */
/* @0x223478 mov r4, r0 */
/* @0x22347c ldr r0, [pc, #0x44] */
/* @0x223480 str r1, [r4, #0x2b4] */
/* @0x223484 add r0, pc, r0 */
/* @0x223488 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x22348c add r1, r4, #684 */
/* @0x223490 mov r0, #2 */
/* @0x223494 bl 0xb6af0 <alGenBuffers@plt> */
/* @0x223498 ldr r0, [pc, #0x2c] */
/* @0x22349c add r0, pc, r0 */
/* @0x2234a0 bl 0x215fd0 <_Z7checkALPKc> */
/* @0x2234a4 mov r3, #1 */
/* @0x2234a8 mov r0, #32768 */
/* @0x2234ac strb r3, [r4, #0x2d4] */
/* @0x2234b0 bl 0xb6544 <malloc@plt> */
/* @0x2234b4 add r3, r0, #16384 */
/* @0x2234b8 str r0, [r4, #0x29c] */
/* @0x2234bc str r0, [r4, #0x2a0] */
/* @0x2234c0 str r3, [r4, #0x2a4] */
/* @0x2234c4 pop {r4, pc} */
/* @0x2234c8 andseq r1, r3, r8, asr #16 */
/* @0x2234cc andseq r1, r3, r0, asr r8 */

/* ── FUNC 0x2234d0 · SOggChannel::~SOggChannel() · size=72 · insn=18 */
/* @0x2234d0 ldrb r3, [r0, #0x2d4] */
/* @0x2234d4 push {r4, lr} */
/* @0x2234d8 cmp r3, #0 */
/* @0x2234dc mov r4, r0 */
/* @0x2234e0 beq 0x2234f8 <_ZN11SOggChannelD2Ev+0x28> */
/* @0x2234e4 mov r0, #2 */
/* @0x2234e8 add r1, r4, #684 */
/* @0x2234ec bl 0xb6ae4 <alDeleteBuffers@plt> */
/* @0x2234f0 mov r3, #0 */
/* @0x2234f4 strb r3, [r4, #0x2d4] */
/* @0x2234f8 ldr r0, [r4, #0x29c] */
/* @0x2234fc bl 0xb655c <free@plt> */
/* @0x223500 mov r3, #0 */
/* @0x223504 mov r0, r4 */
/* @0x223508 str r3, [r4, #0x29c] */
/* @0x22350c bl 0x230ec4 <ov_clear> */
/* @0x223510 mov r0, r4 */
/* @0x223514 pop {r4, pc} */

/* ── FUNC 0x2234d0 · SOggChannel::~SOggChannel() · alias of the symbol above · insn=0 */

/* ── FUNC 0x223518 · ogg_zip_seek(void*, long long, int) · size=200 · insn=50 */
/* @0x223518 str r4, [sp, #-0x4]! */
/* @0x22351c ldr r1, [sp, #0x4] */
/* @0x223520 ldr r3, [r0, #0x2c8] */
/* @0x223524 cmp r1, #1 */
/* @0x223528 beq 0x2235ac <_Z12ogg_zip_seekPvxi+0x94> */
/* @0x22352c cmp r1, #2 */
/* @0x223530 beq 0x223580 <_Z12ogg_zip_seekPvxi+0x68> */
/* @0x223534 cmp r1, #0 */
/* @0x223538 mvnne r1, #0 */
/* @0x22353c beq 0x22354c <_Z12ogg_zip_seekPvxi+0x34> */
/* @0x223540 mov r0, r1 */
/* @0x223544 ldr r4, [sp], #4 */
/* @0x223548 bx lr */
/* @0x22354c ldr r4, [r0, #0x2d0] */
/* @0x223550 ldr r12, [r0, #0x2cc] */
/* @0x223554 ldr r0, [r3, #0x10] */
/* @0x223558 add r12, r12, r2 */
/* @0x22355c rsb r2, r2, r4 */
/* @0x223560 bic r0, r0, #5 */
/* @0x223564 str r12, [r3, #0x18] */
/* @0x223568 str r0, [r3, #0x10] */
/* @0x22356c mov r0, r1 */
/* @0x223570 str r2, [r3, #0x1c] */
/* @0x223574 str r2, [r3, #0x20] */
/* @0x223578 ldr r4, [sp], #4 */
/* @0x22357c bx lr */
/* @0x223580 ldr r4, [r0, #0x2d0] */
/* @0x223584 mov r1, #0 */
/* @0x223588 ldr r12, [r0, #0x2cc] */
/* @0x22358c rsb r0, r2, r4 */
/* @0x223590 str r2, [r3, #0x1c] */
/* @0x223594 add r0, r12, r0 */
/* @0x223598 str r2, [r3, #0x20] */
/* @0x22359c str r0, [r3, #0x18] */
/* @0x2235a0 mov r0, r1 */
/* @0x2235a4 ldr r4, [sp], #4 */
/* @0x2235a8 bx lr */
/* @0x2235ac ldr r0, [r3, #0x20] */
/* @0x2235b0 mov r1, #0 */
/* @0x2235b4 ldr r4, [r3, #0x18] */
/* @0x2235b8 ldr r12, [r3, #0x1c] */
/* @0x2235bc add r4, r4, r2 */
/* @0x2235c0 str r4, [r3, #0x18] */
/* @0x2235c4 rsb r12, r2, r12 */
/* @0x2235c8 ldr r4, [sp], #4 */
/* @0x2235cc rsb r2, r2, r0 */
/* @0x2235d0 str r12, [r3, #0x1c] */
/* @0x2235d4 mov r0, r1 */
/* @0x2235d8 str r2, [r3, #0x20] */
/* @0x2235dc bx lr */

/* ── FUNC 0x2235e0 · ogg_zip_tell(void*) · size=20 · insn=5 */
/* @0x2235e0 ldr r2, [r0, #0x2c8] */
/* @0x2235e4 ldr r3, [r0, #0x2cc] */
/* @0x2235e8 ldr r0, [r2, #0x18] */
/* @0x2235ec rsb r0, r3, r0 */
/* @0x2235f0 bx lr */

/* ── FUNC 0x2235f4 · ogg_seek(void*, long long, int) · size=112 · insn=28 */
/* @0x2235f4 ldr r3, [sp] */
/* @0x2235f8 ldr r1, [r0, #0x2bc] */
/* @0x2235fc cmp r3, #1 */
/* @0x223600 beq 0x223644 <_Z8ogg_seekPvxi+0x50> */
/* @0x223604 cmp r3, #2 */
/* @0x223608 beq 0x223634 <_Z8ogg_seekPvxi+0x40> */
/* @0x22360c cmp r3, #0 */
/* @0x223610 beq 0x22361c <_Z8ogg_seekPvxi+0x28> */
/* @0x223614 mvn r0, #0 */
/* @0x223618 bx lr */
/* @0x22361c ldr r3, [r1, #0x2c] */
/* @0x223620 str r2, [r0, #0x2c0] */
/* @0x223624 cmp r2, r3 */
/* @0x223628 bhi 0x223658 <_Z8ogg_seekPvxi+0x64> */
/* @0x22362c mov r0, #0 */
/* @0x223630 bx lr */
/* @0x223634 ldr r3, [r1, #0x2c] */
/* @0x223638 rsb r2, r2, r3 */
/* @0x22363c str r2, [r0, #0x2c0] */
/* @0x223640 b 0x223624 <_Z8ogg_seekPvxi+0x30> */
/* @0x223644 ldr r12, [r0, #0x2c0] */
/* @0x223648 ldr r3, [r1, #0x2c] */
/* @0x22364c add r2, r12, r2 */
/* @0x223650 str r2, [r0, #0x2c0] */
/* @0x223654 b 0x223624 <_Z8ogg_seekPvxi+0x30> */
/* @0x223658 str r3, [r0, #0x2c0] */
/* @0x22365c mvn r0, #0 */
/* @0x223660 bx lr */

/* ── FUNC 0x223664 · ogg_close(void*) · size=8 · insn=2 */
/* @0x223664 mov r0, #0 */
/* @0x223668 bx lr */

/* ── FUNC 0x22366c · ogg_tell(void*) · size=8 · insn=2 */
/* @0x22366c ldr r0, [r0, #0x2c0] */
/* @0x223670 bx lr */

/* ── FUNC 0x223674 · ogg_zip_read(void*, unsigned int, unsigned int, void*) · size=16 · insn=4 */
/* @0x223674 mul r2, r2, r1 */
/* @0x223678 mov r1, r0 */
/* @0x22367c ldr r0, [r3, #0x2c8] */
/* @0x223680 b 0x31ba7c <__udivdi3+0x3e4> */

/* ── FUNC 0x223684 · ogg_zip_close(void*) · size=8 · insn=2 */
/* @0x223684 ldr r0, [r0, #0x2c8] */
/* @0x223688 b 0x31ba8c <__udivdi3+0x3f4> */

/* ── FUNC 0x22368c · ogg_read(void*, unsigned int, unsigned int, void*) · size=72 · insn=18 */
/* @0x22368c push {r3, r4, r5, lr} */
/* @0x223690 mov r4, r3 */
/* @0x223694 ldr r3, [r3, #0x2bc] */
/* @0x223698 mul r2, r2, r1 */
/* @0x22369c ldr r1, [r4, #0x2c0] */
/* @0x2236a0 ldr r5, [r3, #0x2c] */
/* @0x2236a4 ldr r3, [r3, #0x28] */
/* @0x2236a8 rsb r5, r1, r5 */
/* @0x2236ac cmp r5, r2 */
/* @0x2236b0 movge r5, r2 */
/* @0x2236b4 add r1, r3, r1 */
/* @0x2236b8 mov r2, r5 */
/* @0x2236bc bl 0xb65bc <memcpy@plt> */
/* @0x2236c0 ldr r3, [r4, #0x2c0] */
/* @0x2236c4 mov r0, r5 */
/* @0x2236c8 add r5, r3, r5 */
/* @0x2236cc str r5, [r4, #0x2c0] */
/* @0x2236d0 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2236d4 · anon_2236d4 · size=124 · insn=31 */
/* @0x2236d4 push {r4, r5, lr} */
/* @0x2236d8 sub sp, sp, #12 */
/* @0x2236dc mov r4, r0 */
/* @0x2236e0 ldr r0, [r0, #0x2b4] */
/* @0x2236e4 bl 0xb6b14 <alSourceStop@plt> */
/* @0x2236e8 ldr r0, [r4, #0x2b4] */
/* @0x2236ec movw r1, #0x1015 */
/* @0x2236f0 mov r2, sp */
/* @0x2236f4 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x2236f8 ldr r3, [sp] */
/* @0x2236fc cmp r3, #0 */
/* @0x223700 sub r3, r3, #1 */
/* @0x223704 addne r5, sp, #4 */
/* @0x223708 str r3, [sp] */
/* @0x22370c beq 0x223734 <_Z8ogg_readPvjjS_+0xa8> */
/* @0x223710 ldr r0, [r4, #0x2b4] */
/* @0x223714 mov r1, #1 */
/* @0x223718 mov r2, r5 */
/* @0x22371c bl 0xb6b08 <alSourceUnqueueBuffers@plt> */
/* @0x223720 ldr r3, [sp] */
/* @0x223724 cmp r3, #0 */
/* @0x223728 sub r3, r3, #1 */
/* @0x22372c str r3, [sp] */
/* @0x223730 bne 0x223710 <_Z8ogg_readPvjjS_+0x84> */
/* @0x223734 mov r0, r4 */
/* @0x223738 bl 0x230ec4 <ov_clear> */
/* @0x22373c mov r3, #0 */
/* @0x223740 str r3, [r4, #0x2c4] */
/* @0x223744 str r3, [r4, #0x2e0] */
/* @0x223748 add sp, sp, #12 */
/* @0x22374c pop {r4, r5, pc} */

/* ── FUNC 0x223750 · COggThread::COggThread() · size=132 · insn=33 */
/* @0x223750 push {r4, r5, r6, lr} */
/* @0x223754 mov r4, r0 */
/* @0x223758 mov r5, #0 */
/* @0x22375c mov r0, #8 */
/* @0x223760 strb r5, [r4, #0x820] */
/* @0x223764 str r5, [r4, #0x818] */
/* @0x223768 str r5, [r4, #0x81c] */
/* @0x22376c strb r5, [r4, #0x821] */
/* @0x223770 str r5, [r4, #0x824] */
/* @0x223774 str r5, [r4, #0x828] */
/* @0x223778 bl 0x27c524 <_Znwj> */
/* @0x22377c ldr r1, [pc, #0x4c] */
/* @0x223780 add r1, pc, r1 */
/* @0x223784 mov r6, r0 */
/* @0x223788 bl 0x27e070 <_ZN5MutexC2EPKc> */
/* @0x22378c str r6, [r4, #0x82c] */
/* @0x223790 mov r0, r4 */
/* @0x223794 strb r5, [r4, #0x800] */
/* @0x223798 mov r1, r5 */
/* @0x22379c mov r2, #2048 */
/* @0x2237a0 bl 0xb65b0 <memset@plt> */
/* @0x2237a4 mvn r3, #0 */
/* @0x2237a8 strb r5, [r4, #0x801] */
/* @0x2237ac mov r0, r4 */
/* @0x2237b0 strb r5, [r4, #0x802] */
/* @0x2237b4 str r5, [r4, #0x808] */
/* @0x2237b8 str r5, [r4, #0x810] */
/* @0x2237bc strb r5, [r4, #0x831] */
/* @0x2237c0 str r5, [r4, #0x804] */
/* @0x2237c4 str r5, [r4, #0x814] */
/* @0x2237c8 str r3, [r4, #0x80c] */
/* @0x2237cc pop {r4, r5, r6, pc} */
/* @0x2237d0 andseq pc, r0, r4, lsr r0 */

/* ── FUNC 0x223750 · COggThread::COggThread() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2237d4 · COggThread::StartThread() · size=100 · insn=25 */
/* @0x2237d4 ldr r1, [pc, #0x50] */
/* @0x2237d8 push {r3, r4, r5, lr} */
/* @0x2237dc mov r4, r0 */
/* @0x2237e0 add r0, r0, #2064 */
/* @0x2237e4 mov r2, r4 */
/* @0x2237e8 add r0, r0, #8 */
/* @0x2237ec add r1, pc, r1 */
/* @0x2237f0 mov r3, #0 */
/* @0x2237f4 bl 0x27e0c0 <_ZN7CThread5StartEPFPvS0_ES0_NS_9ePriorityE> */
/* @0x2237f8 subs r5, r0, #0 */
/* @0x2237fc bne 0x223824 <_ZN10COggThread11StartThreadEv+0x50> */
/* @0x223800 ldr r3, [pc, #0x28] */
/* @0x223804 ldr r1, [pc, #0x28] */
/* @0x223808 ldr r3, [pc, r3] */
/* @0x22380c ldr r2, [r4, #0x81c] */
/* @0x223810 add r1, pc, r1 */
/* @0x223814 ldr r0, [r3] */
/* @0x223818 ldr r3, [r0] */
/* @0x22381c ldr r3, [r3, #0xc] */
/* @0x223820 blx r3 */
/* @0x223824 mov r0, r5 */
/* @0x223828 pop {r3, r4, r5, pc} */
/* @0x22382c strheq r0, [r0], -r4 */
/* @0x223830 andseq r9, r12, r12, lsl #30 */
/* @0x223834 ldrsheq r1, [r3], -r8 */

/* ── FUNC 0x223838 · COggThread::WaitForThreadExit() · size=12 · insn=3 */
/* @0x223838 add r0, r0, #2064 */
/* @0x22383c add r0, r0, #8 */
/* @0x223840 b 0x27e108 <_ZN7CThread11WaitForExitEv> */

/* ── FUNC 0x223844 · COggThread::Suspend() · size=76 · insn=19 */
/* @0x223844 push {r3, lr} */
/* @0x223848 ldrb r3, [r0, #0x802] */
/* @0x22384c cmp r3, #0 */
/* @0x223850 popeq {r3, pc} */
/* @0x223854 ldrb r3, [r0, #0x831] */
/* @0x223858 cmp r3, #0 */
/* @0x22385c beq 0x223854 <_ZN10COggThread7SuspendEv+0x10> */
/* @0x223860 ldr r3, [pc, #0x20] */
/* @0x223864 ldr r2, [r0, #0x80c] */
/* @0x223868 ldr r3, [pc, r3] */
/* @0x22386c ldr r1, [pc, #0x18] */
/* @0x223870 ldr r0, [r3] */
/* @0x223874 add r1, pc, r1 */
/* @0x223878 ldr r3, [r0] */
/* @0x22387c ldr r3, [r3, #0xc] */
/* @0x223880 blx r3 */
/* @0x223884 pop {r3, pc} */
/* @0x223888 andseq r9, r12, r12, lsr #29 */
/* @0x22388c ldrheq r1, [r3], -r4 */

/* ── FUNC 0x223890 · COggThread::CleanUp() · size=148 · insn=37 */
/* @0x223890 push {r4, r5, r6, lr} */
/* @0x223894 mov r6, r0 */
/* @0x223898 ldr r4, [r0, #0x814] */
/* @0x22389c cmp r4, #0 */
/* @0x2238a0 beq 0x2238b4 <_ZN10COggThread7CleanUpEv+0x24> */
/* @0x2238a4 mov r0, r4 */
/* @0x2238a8 bl 0x27e020 <_ZN5MutexD2Ev> */
/* @0x2238ac mov r0, r4 */
/* @0x2238b0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2238b4 ldr r0, [r6, #0x804] */
/* @0x2238b8 cmp r0, #0 */
/* @0x2238bc beq 0x2238fc <_ZN10COggThread7CleanUpEv+0x6c> */
/* @0x2238c0 ldr r4, [r0, #-0x4] */
/* @0x2238c4 add r4, r4, r4, lsl #1 */
/* @0x2238c8 add r4, r0, r4, lsl #8 */
/* @0x2238cc cmp r0, r4 */
/* @0x2238d0 beq 0x2238f4 <_ZN10COggThread7CleanUpEv+0x64> */
/* @0x2238d4 sub r4, r4, #768 */
/* @0x2238d8 mov r0, r4 */
/* @0x2238dc mov r5, r4 */
/* @0x2238e0 bl 0x2234d0 <_ZN11SOggChannelD2Ev> */
/* @0x2238e4 ldr r0, [r6, #0x804] */
/* @0x2238e8 cmp r0, r4 */
/* @0x2238ec sub r4, r4, #768 */
/* @0x2238f0 bne 0x2238d8 <_ZN10COggThread7CleanUpEv+0x48> */
/* @0x2238f4 sub r0, r0, #8 */
/* @0x2238f8 bl 0x27d1d4 <_ZdaPv> */
/* @0x2238fc ldr r0, [r6, #0x810] */
/* @0x223900 mov r3, #0 */
/* @0x223904 str r3, [r6, #0x804] */
/* @0x223908 cmp r0, r3 */
/* @0x22390c beq 0x223914 <_ZN10COggThread7CleanUpEv+0x84> */
/* @0x223910 bl 0x27d1d4 <_ZdaPv> */
/* @0x223914 mov r3, #0 */
/* @0x223918 str r3, [r6, #0x810] */
/* @0x22391c strb r3, [r6, #0x802] */
/* @0x223920 pop {r4, r5, r6, pc} */

/* ── FUNC 0x223924 · COggThread::Create(int, int, int) · size=376 · insn=94 */
/* @0x223924 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x223928 mov r8, r3 */
/* @0x22392c ldr r3, [pc, #0x15c] */
/* @0x223930 sub r6, r8, #1 */
/* @0x223934 mov r9, r2 */
/* @0x223938 mov r7, r0 */
/* @0x22393c ldr r3, [pc, r3] */
/* @0x223940 sub sp, sp, #12 */
/* @0x223944 mla r2, r2, r6, r1 */
/* @0x223948 ldr r3, [r3] */
/* @0x22394c mov r5, r1 */
/* @0x223950 cmp r2, r3 */
/* @0x223954 movge r0, #0 */
/* @0x223958 bge 0x223a6c <_ZN10COggThread6CreateEiii+0x148> */
/* @0x22395c cmp r8, #2785280 */
/* @0x223960 str r8, [r7, #0x808] */
/* @0x223964 addls r0, r8, r8, lsl #1 */
/* @0x223968 mvnhi r0, #0 */
/* @0x22396c lslls r0, r0, #8 */
/* @0x223970 addls r0, r0, #8 */
/* @0x223974 bl 0x27d14c <_Znaj> */
/* @0x223978 cmn r6, #1 */
/* @0x22397c mov r3, #768 */
/* @0x223980 add r10, r0, #8 */
/* @0x223984 str r8, [r0, #0x4] */
/* @0x223988 str r3, [r0] */
/* @0x22398c movne r4, r10 */
/* @0x223990 beq 0x2239ac <_ZN10COggThread6CreateEiii+0x88> */
/* @0x223994 mov r0, r4 */
/* @0x223998 sub r6, r6, #1 */
/* @0x22399c bl 0x2233f4 <_ZN11SOggChannelC2Ev> */
/* @0x2239a0 cmn r6, #1 */
/* @0x2239a4 add r4, r4, #768 */
/* @0x2239a8 bne 0x223994 <_ZN10COggThread6CreateEiii+0x70> */
/* @0x2239ac cmp r8, #0 */
/* @0x2239b0 mov r4, #0 */
/* @0x2239b4 mov r0, r10 */
/* @0x2239b8 strb r4, [r7, #0x830] */
/* @0x2239bc str r5, [r7, #0x80c] */
/* @0x2239c0 str r10, [r7, #0x804] */
/* @0x2239c4 strb r4, [r7, #0x800] */
/* @0x2239c8 strb r4, [r7, #0x801] */
/* @0x2239cc strb r4, [r7, #0x831] */
/* @0x2239d0 ble 0x223a24 <_ZN10COggThread6CreateEiii+0x100> */
/* @0x2239d4 ldr r10, [pc, #0xb8] */
/* @0x2239d8 lsl r6, r5, #2 */
/* @0x2239dc lsl r3, r9, #2 */
/* @0x2239e0 str r3, [sp, #0x4] */
/* @0x2239e4 ldr r10, [pc, r10] */
/* @0x2239e8 add r11, r4, r4, lsl #1 */
/* @0x2239ec ldr r2, [r10] */
/* @0x2239f0 add r4, r4, #1 */
/* @0x2239f4 lsl r11, r11, #8 */
/* @0x2239f8 add r0, r0, r11 */
/* @0x2239fc ldr r1, [r2, r6] */
/* @0x223a00 bl 0x223474 <_ZN11SOggChannel4InitEj> */
/* @0x223a04 ldr r0, [r7, #0x804] */
/* @0x223a08 ldr r3, [sp, #0x4] */
/* @0x223a0c cmp r4, r8 */
/* @0x223a10 add r11, r0, r11 */
/* @0x223a14 add r6, r6, r3 */
/* @0x223a18 str r5, [r11, #0x2b8] */
/* @0x223a1c add r5, r5, r9 */
/* @0x223a20 bne 0x2239e8 <_ZN10COggThread6CreateEiii+0xc4> */
/* @0x223a24 cmp r8, #266338304 */
/* @0x223a28 mvnhi r0, #0 */
/* @0x223a2c bls 0x223a74 <_ZN10COggThread6CreateEiii+0x150> */
/* @0x223a30 bl 0x27d14c <_Znaj> */
/* @0x223a34 str r0, [r7, #0x810] */
/* @0x223a38 mov r0, #8 */
/* @0x223a3c bl 0x27c524 <_Znwj> */
/* @0x223a40 ldr r1, [pc, #0x50] */
/* @0x223a44 add r1, pc, r1 */
/* @0x223a48 mov r4, r0 */
/* @0x223a4c bl 0x27e070 <_ZN5MutexC2EPKc> */
/* @0x223a50 str r4, [r7, #0x814] */
/* @0x223a54 mov r0, r7 */
/* @0x223a58 bl 0x2237d4 <_ZN10COggThread11StartThreadEv> */
/* @0x223a5c subs r4, r0, #0 */
/* @0x223a60 movne r0, #1 */
/* @0x223a64 strbne r0, [r7, #0x802] */
/* @0x223a68 beq 0x223a7c <_ZN10COggThread6CreateEiii+0x158> */
/* @0x223a6c add sp, sp, #12 */
/* @0x223a70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x223a74 lsl r0, r8, #3 */
/* @0x223a78 b 0x223a30 <_ZN10COggThread6CreateEiii+0x10c> */
/* @0x223a7c mov r0, r7 */
/* @0x223a80 bl 0x223890 <_ZN10COggThread7CleanUpEv> */
/* @0x223a84 mov r0, r4 */
/* @0x223a88 add sp, sp, #12 */
/* @0x223a8c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x223a90 mulseq r12, r4, r10 */
/* @0x223a94 andseq sp, r12, r8, ror #19 */
/* @0x223a98 andseq r1, r3, r0, lsl #6 */

/* ── FUNC 0x223a9c · COggThread::Lock() · size=8 · insn=2 */
/* @0x223a9c ldr r0, [r0, #0x814] */
/* @0x223aa0 b 0x27e084 <_ZN5Mutex4LockEv> */

/* ── FUNC 0x223aa4 · COggThread::Unlock() · size=8 · insn=2 */
/* @0x223aa4 ldr r0, [r0, #0x814] */
/* @0x223aa8 b 0x27e09c <_ZN5Mutex6UnlockEv> */

/* ── FUNC 0x223aac · COggThread::Play_Sound(int, cAudio_Sound*, bool, float, int) · size=136 · insn=34 */
/* @0x223aac ldr r12, [r0, #0x804] */
/* @0x223ab0 add r1, r1, r1, lsl #1 */
/* @0x223ab4 push {r4, r5, r6, r7, r8, lr} */
/* @0x223ab8 vpush {d8} */
/* @0x223abc add r4, r12, r1, lsl #8 */
/* @0x223ac0 vldr s16, [sp, #32] */
/* @0x223ac4 mov r6, r2 */
/* @0x223ac8 ldr r7, [sp, #0x24] */
/* @0x223acc mov r8, r3 */
/* @0x223ad0 mov r5, r0 */
/* @0x223ad4 bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x223ad8 vcmpe.f32 s16, #0 */
/* @0x223adc cmp r8, #0 */
/* @0x223ae0 mov r3, #1 */
/* @0x223ae4 strb r3, [r4, #0x2d6] */
/* @0x223ae8 mov r0, r5 */
/* @0x223aec movne r3, #3 */
/* @0x223af0 strbne r3, [r4, #0x2d6] */
/* @0x223af4 mov r3, #0 */
/* @0x223af8 vmrs APSR_nzcv, fpscr */
/* @0x223afc ldrbgt r3, [r4, #0x2d6] */
/* @0x223b00 vstrgt s16, [r4, #744] */
/* @0x223b04 strle r3, [r4, #0x2e8] */
/* @0x223b08 mov r2, #1 */
/* @0x223b0c orrgt r3, r3, #16 */
/* @0x223b10 str r7, [r4, #0x2dc] */
/* @0x223b14 strbgt r3, [r4, #0x2d6] */
/* @0x223b18 mov r3, #0 */
/* @0x223b1c vpop {d8} */
/* @0x223b20 str r6, [r4, #0x2d8] */
/* @0x223b24 strb r2, [r4, #0x2d5] */
/* @0x223b28 str r3, [r4, #0x2e0] */
/* @0x223b2c pop {r4, r5, r6, r7, r8, lr} */
/* @0x223b30 b 0x223aa4 <_ZN10COggThread6UnlockEv> */

/* ── FUNC 0x223b34 · COggThread::PauseResume_Sound(int, bool) · size=68 · insn=17 */
/* @0x223b34 ldr r3, [r0, #0x804] */
/* @0x223b38 add r1, r1, r1, lsl #1 */
/* @0x223b3c push {r4, r5, r6, lr} */
/* @0x223b40 add r5, r3, r1, lsl #8 */
/* @0x223b44 mov r4, r0 */
/* @0x223b48 mov r6, r2 */
/* @0x223b4c bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x223b50 ldrb r3, [r5, #0x2d6] */
/* @0x223b54 tst r3, #1 */
/* @0x223b58 beq 0x223b6c <_ZN10COggThread17PauseResume_SoundEib+0x38> */
/* @0x223b5c cmp r6, #0 */
/* @0x223b60 orrne r3, r3, #4 */
/* @0x223b64 biceq r3, r3, #4 */
/* @0x223b68 strb r3, [r5, #0x2d6] */
/* @0x223b6c mov r0, r4 */
/* @0x223b70 pop {r4, r5, r6, lr} */
/* @0x223b74 b 0x223aa4 <_ZN10COggThread6UnlockEv> */

/* ── FUNC 0x223b78 · COggThread::Stop_Sound(int) · size=44 · insn=11 */
/* @0x223b78 push {r3, r4, r5, lr} */
/* @0x223b7c add r1, r1, r1, lsl #1 */
/* @0x223b80 ldr r3, [r0, #0x804] */
/* @0x223b84 mov r4, r0 */
/* @0x223b88 add r5, r3, r1, lsl #8 */
/* @0x223b8c bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x223b90 mov r3, #8 */
/* @0x223b94 mov r0, r4 */
/* @0x223b98 strb r3, [r5, #0x2d6] */
/* @0x223b9c pop {r3, r4, r5, lr} */
/* @0x223ba0 b 0x223aa4 <_ZN10COggThread6UnlockEv> */

/* ── FUNC 0x223ba4 · COggThread::Seek_Sound(int, float) · size=56 · insn=14 */
/* @0x223ba4 ldr r3, [r0, #0x804] */
/* @0x223ba8 add r1, r1, r1, lsl #1 */
/* @0x223bac push {r4, r5, r6, lr} */
/* @0x223bb0 add r4, r3, r1, lsl #8 */
/* @0x223bb4 mov r5, r0 */
/* @0x223bb8 mov r6, r2 */
/* @0x223bbc bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x223bc0 ldrb r3, [r4, #0x2d6] */
/* @0x223bc4 str r6, [r4, #0x2e8] */
/* @0x223bc8 mov r0, r5 */
/* @0x223bcc orr r3, r3, #16 */
/* @0x223bd0 strb r3, [r4, #0x2d6] */
/* @0x223bd4 pop {r4, r5, r6, lr} */
/* @0x223bd8 b 0x223aa4 <_ZN10COggThread6UnlockEv> */

/* ── FUNC 0x223bdc · COggThread::Quit() · size=60 · insn=15 */
/* @0x223bdc ldrb r3, [r0, #0x802] */
/* @0x223be0 push {r4, lr} */
/* @0x223be4 cmp r3, #0 */
/* @0x223be8 mov r4, r0 */
/* @0x223bec popeq {r4, pc} */
/* @0x223bf0 bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x223bf4 mov r3, #1 */
/* @0x223bf8 mov r0, r4 */
/* @0x223bfc strb r3, [r4, #0x801] */
/* @0x223c00 bl 0x223aa4 <_ZN10COggThread6UnlockEv> */
/* @0x223c04 mov r0, r4 */
/* @0x223c08 bl 0x223838 <_ZN10COggThread17WaitForThreadExitEv> */
/* @0x223c0c mov r0, r4 */
/* @0x223c10 pop {r4, lr} */
/* @0x223c14 b 0x223890 <_ZN10COggThread7CleanUpEv> */

/* ── FUNC 0x223c18 · COggThread::LogError(char const*, ...) · size=156 · insn=39 */
/* @0x223c18 push {r1, r2, r3} */
/* @0x223c1c mov r1, #255 */
/* @0x223c20 push {r4, r5, r6, lr} */
/* @0x223c24 sub sp, sp, #268 */
/* @0x223c28 ldr r5, [pc, #0x80] */
/* @0x223c2c add r12, sp, #288 */
/* @0x223c30 add r6, sp, #4 */
/* @0x223c34 mov r4, r0 */
/* @0x223c38 ldr r5, [pc, r5] */
/* @0x223c3c mov r3, r12 */
/* @0x223c40 ldr r2, [sp, #0x11c] */
/* @0x223c44 mov r0, r6 */
/* @0x223c48 ldr lr, [r5] */
/* @0x223c4c str r12, [sp] */
/* @0x223c50 str lr, [sp, #0x104] */
/* @0x223c54 bl 0xb6610 <vsnprintf@plt> */
/* @0x223c58 mov r0, r4 */
/* @0x223c5c bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x223c60 mov r3, #1 */
/* @0x223c64 mov r0, r4 */
/* @0x223c68 strb r3, [r4, #0x800] */
/* @0x223c6c bl 0xb6538 <strlen@plt> */
/* @0x223c70 mov r1, r6 */
/* @0x223c74 rsb r2, r0, #2032 */
/* @0x223c78 mov r0, r4 */
/* @0x223c7c add r2, r2, #15 */
/* @0x223c80 bl 0xb6c1c <strncat@plt> */
/* @0x223c84 mov r0, r4 */
/* @0x223c88 bl 0x223aa4 <_ZN10COggThread6UnlockEv> */
/* @0x223c8c ldr r2, [sp, #0x104] */
/* @0x223c90 ldr r3, [r5] */
/* @0x223c94 cmp r2, r3 */
/* @0x223c98 bne 0x223cac <_ZN10COggThread8LogErrorEPKcz+0x94> */
/* @0x223c9c add sp, sp, #268 */
/* @0x223ca0 pop {r4, r5, r6, lr} */
/* @0x223ca4 add sp, sp, #12 */
/* @0x223ca8 bx lr */
/* @0x223cac bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x223cb0 andseq r9, r12, r8, lsl sp */

/* ── FUNC 0x223cb4 · anon_223cb4 · size=508 · insn=127 */
/* @0x223cb4 ldr r12, [pc, #0x64] */
/* @0x223cb8 push {r4, r5, lr} */
/* @0x223cbc ldr r12, [pc, r12] */
/* @0x223cc0 mov lr, r0 */
/* @0x223cc4 mov r4, #0 */
/* @0x223cc8 mov r5, r1 */
/* @0x223ccc str r4, [r0, #0x2c0] */
/* @0x223cd0 ldm r12, {r0, r1, r2, r3} */
/* @0x223cd4 sub sp, sp, #20 */
/* @0x223cd8 stm sp, {r0, r1, r2, r3} */
/* @0x223cdc mov r2, r4 */
/* @0x223ce0 mov r0, lr */
/* @0x223ce4 mov r1, lr */
/* @0x223ce8 mov r3, r4 */
/* @0x223cec bl 0x231c48 <ov_open_callbacks> */
/* @0x223cf0 subs r2, r0, #0 */
/* @0x223cf4 moveq r0, #1 */
/* @0x223cf8 beq 0x223d18 <_ZN10COggThread8LogErrorEPKcz+0x100> */
/* @0x223cfc cmp r5, r4 */
/* @0x223d00 mov r0, r5 */
/* @0x223d04 beq 0x223d18 <_ZN10COggThread8LogErrorEPKcz+0x100> */
/* @0x223d08 ldr r1, [pc, #0x14] */
/* @0x223d0c add r1, pc, r1 */
/* @0x223d10 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz> */
/* @0x223d14 mov r0, r4 */
/* @0x223d18 add sp, sp, #20 */
/* @0x223d1c pop {r4, r5, pc} */
/* @0x223d20 ldrheq sp, [r12], -r8 */
/* @0x223d24 andseq r1, r3, r4, asr #32 */
/* @0x223d28 ldr r3, [pc, #0xd0] */
/* @0x223d2c push {r4, r5, r6, r7, lr} */
/* @0x223d30 ldr r3, [pc, r3] */
/* @0x223d34 sub sp, sp, #20 */
/* @0x223d38 mov r6, r0 */
/* @0x223d3c mov r4, r1 */
/* @0x223d40 mov r7, r2 */
/* @0x223d44 mov r1, r0 */
/* @0x223d48 mov r2, #1 */
/* @0x223d4c ldr r0, [r3] */
/* @0x223d50 blx 0x2a44b8 <zip_fopen> */
/* @0x223d54 subs r5, r0, #0 */
/* @0x223d58 beq 0x223dd8 <_ZN10COggThread8LogErrorEPKcz+0x1c0> */
/* @0x223d5c ldr r3, [pc, #0xa0] */
/* @0x223d60 ldr lr, [r5, #0x18] */
/* @0x223d64 add r3, pc, r3 */
/* @0x223d68 ldr r12, [r5, #0x1c] */
/* @0x223d6c str r5, [r4, #0x2c8] */
/* @0x223d70 ldm r3, {r0, r1, r2, r3} */
/* @0x223d74 str lr, [r4, #0x2cc] */
/* @0x223d78 str r12, [r4, #0x2d0] */
/* @0x223d7c stm sp, {r0, r1, r2, r3} */
/* @0x223d80 mov r2, #0 */
/* @0x223d84 mov r0, r4 */
/* @0x223d88 mov r1, r4 */
/* @0x223d8c mov r3, r2 */
/* @0x223d90 bl 0x231c48 <ov_open_callbacks> */
/* @0x223d94 subs r4, r0, #0 */
/* @0x223d98 moveq r0, #1 */
/* @0x223d9c bne 0x223da8 <_ZN10COggThread8LogErrorEPKcz+0x190> */
/* @0x223da0 add sp, sp, #20 */
/* @0x223da4 pop {r4, r5, r6, r7, pc} */
/* @0x223da8 mov r0, r5 */
/* @0x223dac blx 0x2a4388 <zip_fclose> */
/* @0x223db0 cmp r7, #0 */
/* @0x223db4 beq 0x223dcc <_ZN10COggThread8LogErrorEPKcz+0x1b4> */
/* @0x223db8 ldr r1, [pc, #0x48] */
/* @0x223dbc mov r0, r7 */
/* @0x223dc0 mov r2, r4 */
/* @0x223dc4 add r1, pc, r1 */
/* @0x223dc8 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz> */
/* @0x223dcc mov r0, #0 */
/* @0x223dd0 add sp, sp, #20 */
/* @0x223dd4 pop {r4, r5, r6, r7, pc} */
/* @0x223dd8 cmp r7, #0 */
/* @0x223ddc beq 0x223dcc <_ZN10COggThread8LogErrorEPKcz+0x1b4> */
/* @0x223de0 ldr r1, [pc, #0x24] */
/* @0x223de4 mov r0, r7 */
/* @0x223de8 mov r2, r6 */
/* @0x223dec add r1, pc, r1 */
/* @0x223df0 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz> */
/* @0x223df4 mov r0, r5 */
/* @0x223df8 add sp, sp, #20 */
/* @0x223dfc pop {r4, r5, r6, r7, pc} */
/* @0x223e00 andseq r12, r12, r4, ror #3 */
/* @0x223e04 mulseq r12, r4, r1 */
/* @0x223e08 andseq r0, r3, r12, lsl #31 */
/* @0x223e0c andseq r0, r3, r0, lsl #31 */
/* @0x223e10 push {r3, r4, r5, r6, r7, lr} */
/* @0x223e14 mov r5, r1 */
/* @0x223e18 ldr r1, [pc, #0x84] */
/* @0x223e1c mov r4, r2 */
/* @0x223e20 mov r7, r0 */
/* @0x223e24 add r1, pc, r1 */
/* @0x223e28 bl 0xb6844 <fopen@plt> */
/* @0x223e2c subs r6, r0, #0 */
/* @0x223e30 beq 0x223e80 <_ZN10COggThread8LogErrorEPKcz+0x268> */
/* @0x223e34 mov r2, #0 */
/* @0x223e38 mov r1, r5 */
/* @0x223e3c mov r3, r2 */
/* @0x223e40 bl 0x231cec <ov_open> */
/* @0x223e44 subs r5, r0, #0 */
/* @0x223e48 bne 0x223e54 <_ZN10COggThread8LogErrorEPKcz+0x23c> */
/* @0x223e4c mov r0, #1 */
/* @0x223e50 pop {r3, r4, r5, r6, r7, pc} */
/* @0x223e54 mov r0, r6 */
/* @0x223e58 bl 0xb6850 <fclose@plt> */
/* @0x223e5c cmp r4, #0 */
/* @0x223e60 beq 0x223e78 <_ZN10COggThread8LogErrorEPKcz+0x260> */
/* @0x223e64 ldr r1, [pc, #0x3c] */
/* @0x223e68 mov r0, r4 */
/* @0x223e6c mov r2, r5 */
/* @0x223e70 add r1, pc, r1 */
/* @0x223e74 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz> */
/* @0x223e78 mov r0, #0 */
/* @0x223e7c pop {r3, r4, r5, r6, r7, pc} */
/* @0x223e80 cmp r4, #0 */
/* @0x223e84 beq 0x223e78 <_ZN10COggThread8LogErrorEPKcz+0x260> */
/* @0x223e88 ldr r1, [pc, #0x1c] */
/* @0x223e8c mov r0, r4 */
/* @0x223e90 mov r2, r7 */
/* @0x223e94 add r1, pc, r1 */
/* @0x223e98 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz> */
/* @0x223e9c mov r0, r6 */
/* @0x223ea0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x223ea4 ldrsbeq r3, [r1], -r4 */
/* @0x223ea8 andseq r0, r3, r8, lsr pc */
/* @0x223eac ldrsheq r0, [r3], -r8 */

/* ── FUNC 0x223eb0 · GetStreamInfo(cAudio_Sound*) · size=452 · insn=113 */
/* @0x223eb0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x223eb4 sub sp, sp, #1792 */
/* @0x223eb8 ldr r8, [pc, #0x1a8] */
/* @0x223ebc sub sp, sp, #12 */
/* @0x223ec0 mov r7, r0 */
/* @0x223ec4 ldr r8, [pc, r8] */
/* @0x223ec8 mov r0, sp */
/* @0x223ecc ldr r3, [r8] */
/* @0x223ed0 str r3, [sp, #0x704] */
/* @0x223ed4 bl 0x2233f4 <_ZN11SOggChannelC2Ev> */
/* @0x223ed8 ldrb r1, [r7, #0x24] */
/* @0x223edc mov r3, #0 */
/* @0x223ee0 str r7, [sp, #0x2bc] */
/* @0x223ee4 cmp r1, r3 */
/* @0x223ee8 str r3, [sp, #0x2c0] */
/* @0x223eec beq 0x223fa8 <_Z13GetStreamInfoP12cAudio_Sound+0xf8> */
/* @0x223ef0 ldr r4, [r7, #0x30] */
/* @0x223ef4 cmp r4, #0 */
/* @0x223ef8 beq 0x223fcc <_Z13GetStreamInfoP12cAudio_Sound+0x11c> */
/* @0x223efc mov r2, #0 */
/* @0x223f00 mov r0, r4 */
/* @0x223f04 mov r1, sp */
/* @0x223f08 bl 0x223d28 <_ZN10COggThread8LogErrorEPKcz+0x110> */
/* @0x223f0c subs r2, r0, #0 */
/* @0x223f10 beq 0x223fbc <_Z13GetStreamInfoP12cAudio_Sound+0x10c> */
/* @0x223f14 mvn r1, #0 */
/* @0x223f18 mov r0, sp */
/* @0x223f1c bl 0x232e28 <ov_info> */
/* @0x223f20 mvn r1, #0 */
/* @0x223f24 mov r9, r0 */
/* @0x223f28 mov r0, sp */
/* @0x223f2c bl 0x23138c <ov_pcm_total> */
/* @0x223f30 mvn r2, #130 */
/* @0x223f34 mvn r3, #0 */
/* @0x223f38 mov r4, r0 */
/* @0x223f3c mov r5, r1 */
/* @0x223f40 cmp r5, r3 */
/* @0x223f44 cmpeq r4, r2 */
/* @0x223f48 beq 0x224020 <_Z13GetStreamInfoP12cAudio_Sound+0x170> */
/* @0x223f4c bl 0x319398 <__floatdisf> */
/* @0x223f50 ldr r3, [r9, #0x8] */
/* @0x223f54 vmov s14, r3 */
/* @0x223f58 vcvt.f32.s32 s15, s14 */
/* @0x223f5c vmov s14, r0 */
/* @0x223f60 vdiv.f32 s15, s14, s15 */
/* @0x223f64 ldr r1, [sp, #0x2c4] */
/* @0x223f68 vstr s15, [r7, #52] */
/* @0x223f6c ldr r2, [r9, #0x4] */
/* @0x223f70 cmp r1, #0 */
/* @0x223f74 str r3, [r7, #0x38] */
/* @0x223f78 strd r4, r5, [r7, #64] */
/* @0x223f7c str r2, [r7, #0x3c] */
/* @0x223f80 bne 0x224014 <_Z13GetStreamInfoP12cAudio_Sound+0x164> */
/* @0x223f84 mov r0, sp */
/* @0x223f88 bl 0x2234d0 <_ZN11SOggChannelD2Ev> */
/* @0x223f8c ldr r2, [sp, #0x704] */
/* @0x223f90 ldr r3, [r8] */
/* @0x223f94 cmp r2, r3 */
/* @0x223f98 bne 0x224060 <_Z13GetStreamInfoP12cAudio_Sound+0x1b0> */
/* @0x223f9c add sp, sp, #1792 */
/* @0x223fa0 add sp, sp, #12 */
/* @0x223fa4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x223fa8 mov r0, sp */
/* @0x223fac bl 0x223cb4 <_ZN10COggThread8LogErrorEPKcz+0x9c> */
/* @0x223fb0 cmp r0, #0 */
/* @0x223fb4 beq 0x223f84 <_Z13GetStreamInfoP12cAudio_Sound+0xd4> */
/* @0x223fb8 b 0x223f14 <_Z13GetStreamInfoP12cAudio_Sound+0x64> */
/* @0x223fbc mov r0, r4 */
/* @0x223fc0 mov r1, sp */
/* @0x223fc4 bl 0x223e10 <_ZN10COggThread8LogErrorEPKcz+0x1f8> */
/* @0x223fc8 b 0x223fb0 <_Z13GetStreamInfoP12cAudio_Sound+0x100> */
/* @0x223fcc add r4, sp, #772 */
/* @0x223fd0 mov r1, #1024 */
/* @0x223fd4 ldr r2, [r7] */
/* @0x223fd8 mov r0, r4 */
/* @0x223fdc bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x223fe0 mov r0, r4 */
/* @0x223fe4 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x223fe8 cmp r0, #0 */
/* @0x223fec beq 0x22402c <_Z13GetStreamInfoP12cAudio_Sound+0x17c> */
/* @0x223ff0 ldr r0, [r7, #0x30] */
/* @0x223ff4 cmp r0, #0 */
/* @0x223ff8 beq 0x224000 <_Z13GetStreamInfoP12cAudio_Sound+0x150> */
/* @0x223ffc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x224000 mov r0, r4 */
/* @0x224004 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x224008 mov r4, r0 */
/* @0x22400c str r0, [r7, #0x30] */
/* @0x224010 b 0x223efc <_Z13GetStreamInfoP12cAudio_Sound+0x4c> */
/* @0x224014 mov r0, sp */
/* @0x224018 bl 0x2236d4 <_Z8ogg_readPvjjS_+0x48> */
/* @0x22401c b 0x223f84 <_Z13GetStreamInfoP12cAudio_Sound+0xd4> */
/* @0x224020 ldr r3, [r9, #0x8] */
/* @0x224024 vldr s15, [pc, #56] */
/* @0x224028 b 0x223f64 <_Z13GetStreamInfoP12cAudio_Sound+0xb4> */
/* @0x22402c ldr r0, [pc, #0x38] */
/* @0x224030 mov r3, r4 */
/* @0x224034 ldr r1, [pc, #0x34] */
/* @0x224038 ldr r0, [pc, r0] */
/* @0x22403c ldr r2, [r7] */
/* @0x224040 add r1, pc, r1 */
/* @0x224044 ldr r0, [r0] */
/* @0x224048 ldr r12, [r0] */
/* @0x22404c ldr r12, [r12, #0xc] */
/* @0x224050 blx r12 */
/* @0x224054 mov r0, sp */
/* @0x224058 bl 0x2234d0 <_ZN11SOggChannelD2Ev> */
/* @0x22405c b 0x223f8c <_Z13GetStreamInfoP12cAudio_Sound+0xdc> */
/* @0x224060 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x224064 andeq r0, r0, r0 */
/* @0x224068 andseq r9, r12, r12, lsl #21 */
/* @0x22406c ldrsbeq r9, [r12], -r12 */
/* @0x224070 andseq r0, r3, r12, ror sp */

/* ── FUNC 0x224074 · anon_224074 · size=1788 · insn=447 */
/* @0x224074 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x224078 mov r5, r0 */
/* @0x22407c ldr r0, [r0, #0x2a8] */
/* @0x224080 sub sp, sp, #20 */
/* @0x224084 cmp r3, #0 */
/* @0x224088 mov r4, #0 */
/* @0x22408c add r0, r0, #168 */
/* @0x224090 add r7, sp, #12 */
/* @0x224094 mov r9, r1 */
/* @0x224098 mov r8, r2 */
/* @0x22409c str r4, [sp, #0xc] */
/* @0x2240a0 ldr r6, [r5, r0, lsl #2] */
/* @0x2240a4 bne 0x2240b4 <_Z13GetStreamInfoP12cAudio_Sound+0x204> */
/* @0x2240a8 b 0x224170 <_Z13GetStreamInfoP12cAudio_Sound+0x2c0> */
/* @0x2240ac cmp r4, #16384 */
/* @0x2240b0 bge 0x224108 <_Z13GetStreamInfoP12cAudio_Sound+0x258> */
/* @0x2240b4 add r1, r6, r4 */
/* @0x2240b8 rsb r2, r4, #16384 */
/* @0x2240bc mov r0, r5 */
/* @0x2240c0 mov r3, r7 */
/* @0x2240c4 bl 0x232ec8 <ov_read> */
/* @0x2240c8 subs r12, r0, #0 */
/* @0x2240cc addgt r4, r4, r12 */
/* @0x2240d0 bgt 0x2240ac <_Z13GetStreamInfoP12cAudio_Sound+0x1fc> */
/* @0x2240d4 mov r0, r5 */
/* @0x2240d8 mov r2, #0 */
/* @0x2240dc mov r3, #0 */
/* @0x2240e0 bne 0x224154 <_Z13GetStreamInfoP12cAudio_Sound+0x2a4> */
/* @0x2240e4 bl 0x231618 <ov_raw_seek> */
/* @0x2240e8 subs r2, r0, #0 */
/* @0x2240ec beq 0x2240ac <_Z13GetStreamInfoP12cAudio_Sound+0x1fc> */
/* @0x2240f0 ldr r1, [pc, #0xa8] */
/* @0x2240f4 mov r0, r9 */
/* @0x2240f8 add r1, pc, r1 */
/* @0x2240fc bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz> */
/* @0x224100 cmp r4, #0 */
/* @0x224104 beq 0x224138 <_Z13GetStreamInfoP12cAudio_Sound+0x288> */
/* @0x224108 ldr r12, [r5, #0x298] */
/* @0x22410c mov r2, r6 */
/* @0x224110 movw lr, #0x1101 */
/* @0x224114 movw r1, #0x1103 */
/* @0x224118 mov r0, r8 */
/* @0x22411c mov r3, r4 */
/* @0x224120 ldr r6, [r12, #0x8] */
/* @0x224124 ldr r12, [r12, #0x4] */
/* @0x224128 cmp r12, #1 */
/* @0x22412c str r6, [sp] */
/* @0x224130 moveq r1, lr */
/* @0x224134 bl 0xb6afc <alBufferData@plt> */
/* @0x224138 ldr r3, [r5, #0x2a8] */
/* @0x22413c mov r0, r4 */
/* @0x224140 eor r3, r3, #1 */
/* @0x224144 str r3, [r5, #0x2a8] */
/* @0x224148 add sp, sp, #20 */
/* @0x22414c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x224150 beq 0x224100 <_Z13GetStreamInfoP12cAudio_Sound+0x250> */
/* @0x224154 ldr r1, [pc, #0x48] */
/* @0x224158 mov r0, r9 */
/* @0x22415c mov r2, r12 */
/* @0x224160 mov r4, #0 */
/* @0x224164 add r1, pc, r1 */
/* @0x224168 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz> */
/* @0x22416c b 0x224138 <_Z13GetStreamInfoP12cAudio_Sound+0x288> */
/* @0x224170 mov r4, r3 */
/* @0x224174 mov r0, r5 */
/* @0x224178 add r1, r6, r4 */
/* @0x22417c rsb r2, r4, #16384 */
/* @0x224180 mov r3, r7 */
/* @0x224184 bl 0x232ec8 <ov_read> */
/* @0x224188 subs r12, r0, #0 */
/* @0x22418c ble 0x224150 <_Z13GetStreamInfoP12cAudio_Sound+0x2a0> */
/* @0x224190 add r4, r4, r12 */
/* @0x224194 cmp r4, #16384 */
/* @0x224198 blt 0x224174 <_Z13GetStreamInfoP12cAudio_Sound+0x2c4> */
/* @0x22419c b 0x224108 <_Z13GetStreamInfoP12cAudio_Sound+0x258> */
/* @0x2241a0 ldrsheq r0, [r3], -r8 */
/* @0x2241a4 andseq r0, r3, r8, ror r12 */
/* @0x2241a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2241ac vpush {d8, d9} */
/* @0x2241b0 sub sp, sp, #52 */
/* @0x2241b4 vldr s18, [pc, #812] */
/* @0x2241b8 ldr r2, [pc, #0x32c] */
/* @0x2241bc mov r11, #0 */
/* @0x2241c0 ldr r10, [r0, #0xc] */
/* @0x2241c4 vldr d8, [pc, #788] */
/* @0x2241c8 ldr r2, [pc, r2] */
/* @0x2241cc ldr r3, [pc, #0x31c] */
/* @0x2241d0 str r2, [sp, #0x14] */
/* @0x2241d4 ldr r2, [pc, #0x318] */
/* @0x2241d8 add r3, pc, r3 */
/* @0x2241dc str r3, [sp, #0x18] */
/* @0x2241e0 add r2, pc, r2 */
/* @0x2241e4 str r2, [sp, #0x1c] */
/* @0x2241e8 bl 0x215148 <Timing_Time> */
/* @0x2241ec ldr r2, [sp, #0x14] */
/* @0x2241f0 ldrb r3, [r2] */
/* @0x2241f4 uxtb r3, r3 */
/* @0x2241f8 strb r3, [r10, #0x831] */
/* @0x2241fc strd r0, r1, [sp, #8] */
/* @0x224200 ldrb r1, [r10, #0x831] */
/* @0x224204 ands r4, r1, #255 */
/* @0x224208 bne 0x224388 <_Z13GetStreamInfoP12cAudio_Sound+0x4d8> */
/* @0x22420c mov r0, r10 */
/* @0x224210 bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x224214 ldr r3, [r10, #0x808] */
/* @0x224218 ldrb r6, [r10, #0x801] */
/* @0x22421c cmp r3, #0 */
/* @0x224220 movgt r1, r4 */
/* @0x224224 movgt r2, r1 */
/* @0x224228 ble 0x224270 <_Z13GetStreamInfoP12cAudio_Sound+0x3c0> */
/* @0x22422c ldr r3, [r10, #0x804] */
/* @0x224230 ldr r0, [r10, #0x810] */
/* @0x224234 add r3, r3, r1 */
/* @0x224238 add r1, r1, #768 */
/* @0x22423c ldrb r12, [r3, #0x2d6] */
/* @0x224240 strb r12, [r0, r2, lsl #3] */
/* @0x224244 vldr s15, [r3, #744] */
/* @0x224248 vmul.f32 s15, s15, s18 */
/* @0x22424c strb r11, [r3, #0x2d6] */
/* @0x224250 ldr r12, [r10, #0x808] */
/* @0x224254 add r2, r2, #1 */
/* @0x224258 ldr r0, [r3, #0x2d8] */
/* @0x22425c cmp r12, r2 */
/* @0x224260 str r0, [r3, #0x2bc] */
/* @0x224264 vcvt.s32.f32 s15, s15 */
/* @0x224268 vstr s15, [r3, #740] */
/* @0x22426c bgt 0x22422c <_Z13GetStreamInfoP12cAudio_Sound+0x37c> */
/* @0x224270 mov r0, r10 */
/* @0x224274 bl 0x223aa4 <_ZN10COggThread6UnlockEv> */
/* @0x224278 cmp r6, #0 */
/* @0x22427c bne 0x2246f4 <_Z13GetStreamInfoP12cAudio_Sound+0x844> */
/* @0x224280 ldr r2, [r10, #0x808] */
/* @0x224284 cmp r2, #0 */
/* @0x224288 addgt r3, sp, #40 */
/* @0x22428c addgt r4, sp, #44 */
/* @0x224290 strgt r3, [sp, #0x10] */
/* @0x224294 movgt r5, r6 */
/* @0x224298 ble 0x224388 <_Z13GetStreamInfoP12cAudio_Sound+0x4d8> */
/* @0x22429c ldr r3, [r10, #0x810] */
/* @0x2242a0 ldr r12, [r10, #0x804] */
/* @0x2242a4 ldrb r7, [r3, r5, lsl #3] */
/* @0x2242a8 add r9, r12, r6 */
/* @0x2242ac cmp r7, #0 */
/* @0x2242b0 ldr r3, [r9, #0x2c4] */
/* @0x2242b4 bne 0x2243c4 <_Z13GetStreamInfoP12cAudio_Sound+0x514> */
/* @0x2242b8 cmp r3, #0 */
/* @0x2242bc beq 0x224378 <_Z13GetStreamInfoP12cAudio_Sound+0x4c8> */
/* @0x2242c0 subs r3, r3, #2 */
/* @0x2242c4 ldr r0, [r9, #0x2b4] */
/* @0x2242c8 rsbs r7, r3, #0 */
/* @0x2242cc movw r1, #0x1016 */
/* @0x2242d0 add r2, sp, #40 */
/* @0x2242d4 adcs r7, r7, r3 */
/* @0x2242d8 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x2242dc ldr r3, [sp, #0x28] */
/* @0x2242e0 cmp r3, #0 */
/* @0x2242e4 sub r3, r3, #1 */
/* @0x2242e8 str r3, [sp, #0x28] */
/* @0x2242ec movne r8, #3 */
/* @0x2242f0 beq 0x224354 <_Z13GetStreamInfoP12cAudio_Sound+0x4a4> */
/* @0x2242f4 ldr r0, [r9, #0x2b4] */
/* @0x2242f8 mov r1, #1 */
/* @0x2242fc mov r2, r4 */
/* @0x224300 bl 0xb6b08 <alSourceUnqueueBuffers@plt> */
/* @0x224304 ldr r3, [r9, #0x2e0] */
/* @0x224308 mov r1, r10 */
/* @0x22430c mov r0, r9 */
/* @0x224310 add r3, r3, #1 */
/* @0x224314 str r3, [r9, #0x2e0] */
/* @0x224318 ldr r2, [sp, #0x2c] */
/* @0x22431c mov r3, r7 */
/* @0x224320 bl 0x224074 <_Z13GetStreamInfoP12cAudio_Sound+0x1c4> */
/* @0x224324 mov r1, #1 */
/* @0x224328 mov r2, r4 */
/* @0x22432c cmp r0, #0 */
/* @0x224330 strle r8, [r9, #0x2c4] */
/* @0x224334 ble 0x224340 <_Z13GetStreamInfoP12cAudio_Sound+0x490> */
/* @0x224338 ldr r0, [r9, #0x2b4] */
/* @0x22433c bl 0xb6b8c <alSourceQueueBuffers@plt> */
/* @0x224340 ldr r3, [sp, #0x28] */
/* @0x224344 cmp r3, #0 */
/* @0x224348 sub r3, r3, #1 */
/* @0x22434c str r3, [sp, #0x28] */
/* @0x224350 bne 0x2242f4 <_Z13GetStreamInfoP12cAudio_Sound+0x444> */
/* @0x224354 mov r2, r4 */
/* @0x224358 ldr r0, [r9, #0x2b4] */
/* @0x22435c movw r1, #0x1010 */
/* @0x224360 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x224364 ldr r2, [sp, #0x2c] */
/* @0x224368 movw r3, #0x1014 */
/* @0x22436c cmp r2, r3 */
/* @0x224370 beq 0x224698 <_Z13GetStreamInfoP12cAudio_Sound+0x7e8> */
/* @0x224374 ldr r2, [r10, #0x808] */
/* @0x224378 add r5, r5, #1 */
/* @0x22437c add r6, r6, #768 */
/* @0x224380 cmp r2, r5 */
/* @0x224384 bgt 0x22429c <_Z13GetStreamInfoP12cAudio_Sound+0x3ec> */
/* @0x224388 bl 0x215148 <Timing_Time> */
/* @0x22438c ldrd r2, r3, [sp, #8] */
/* @0x224390 subs r0, r0, r2 */
/* @0x224394 sbc r1, r1, r3 */
/* @0x224398 bl 0x319164 <__floatdidf> */
/* @0x22439c vmov d6, r0, r1 */
/* @0x2243a0 vmul.f64 d7, d6, d8 */
/* @0x2243a4 vcvt.s32.f64 s13, d7 */
/* @0x2243a8 vmov r0, s13 */
/* @0x2243ac rsb r0, r0, #16 */
/* @0x2243b0 bic r0, r0, r0, asr #31 */
/* @0x2243b4 cmp r0, #0 */
/* @0x2243b8 beq 0x2241e8 <_Z13GetStreamInfoP12cAudio_Sound+0x338> */
/* @0x2243bc bl 0x27e114 <_ZN7CThread5SleepEi> */
/* @0x2243c0 b 0x2241e8 <_Z13GetStreamInfoP12cAudio_Sound+0x338> */
/* @0x2243c4 ands r8, r7, #1 */
/* @0x2243c8 bne 0x2244f8 <_Z13GetStreamInfoP12cAudio_Sound+0x648> */
/* @0x2243cc cmp r7, #8 */
/* @0x2243d0 beq 0x2244f8 <_Z13GetStreamInfoP12cAudio_Sound+0x648> */
/* @0x2243d4 tst r7, #16 */
/* @0x2243d8 beq 0x2244d4 <_Z13GetStreamInfoP12cAudio_Sound+0x624> */
/* @0x2243dc cmp r3, #0 */
/* @0x2243e0 ldr r7, [r9, #0x2e4] */
/* @0x2243e4 beq 0x224374 <_Z13GetStreamInfoP12cAudio_Sound+0x4c4> */
/* @0x2243e8 add r2, sp, #36 */
/* @0x2243ec ldr r0, [r9, #0x2b4] */
/* @0x2243f0 movw r1, #0x1010 */
/* @0x2243f4 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x2243f8 ldr r0, [r9, #0x2b4] */
/* @0x2243fc ldr r8, [sp, #0x24] */
/* @0x224400 bl 0xb6b14 <alSourceStop@plt> */
/* @0x224404 ldr r0, [r9, #0x2b4] */
/* @0x224408 movw r1, #0x1015 */
/* @0x22440c add r2, sp, #40 */
/* @0x224410 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x224414 b 0x224428 <_Z13GetStreamInfoP12cAudio_Sound+0x578> */
/* @0x224418 ldr r0, [r9, #0x2b4] */
/* @0x22441c mov r1, #1 */
/* @0x224420 mov r2, r4 */
/* @0x224424 bl 0xb6b08 <alSourceUnqueueBuffers@plt> */
/* @0x224428 ldr r3, [sp, #0x28] */
/* @0x22442c cmp r3, #0 */
/* @0x224430 sub r3, r3, #1 */
/* @0x224434 str r3, [sp, #0x28] */
/* @0x224438 bne 0x224418 <_Z13GetStreamInfoP12cAudio_Sound+0x568> */
/* @0x22443c mov r2, r7 */
/* @0x224440 asr r3, r7, #31 */
/* @0x224444 str r11, [r9, #0x2e0] */
/* @0x224448 mov r0, r9 */
/* @0x22444c bl 0x232a44 <ov_time_seek> */
/* @0x224450 ldr r7, [r9, #0x2c4] */
/* @0x224454 str r11, [r9, #0x2a8] */
/* @0x224458 mov r0, r9 */
/* @0x22445c subs r2, r7, #2 */
/* @0x224460 mov r1, r10 */
/* @0x224464 rsbs r7, r2, #0 */
/* @0x224468 adcs r7, r7, r2 */
/* @0x22446c ldr r2, [r9, #0x2ac] */
/* @0x224470 mov r3, r7 */
/* @0x224474 bl 0x224074 <_Z13GetStreamInfoP12cAudio_Sound+0x1c4> */
/* @0x224478 cmp r0, #0 */
/* @0x22447c ble 0x22466c <_Z13GetStreamInfoP12cAudio_Sound+0x7bc> */
/* @0x224480 mov r1, r10 */
/* @0x224484 mov r3, r7 */
/* @0x224488 ldr r2, [r9, #0x2b0] */
/* @0x22448c mov r0, r9 */
/* @0x224490 bl 0x224074 <_Z13GetStreamInfoP12cAudio_Sound+0x1c4> */
/* @0x224494 add r2, r9, #684 */
/* @0x224498 cmp r0, #0 */
/* @0x22449c ldr r0, [r9, #0x2b4] */
/* @0x2244a0 movgt r1, #2 */
/* @0x2244a4 movle r1, #1 */
/* @0x2244a8 bl 0xb6b8c <alSourceQueueBuffers@plt> */
/* @0x2244ac ldr r0, [r9, #0x2b4] */
/* @0x2244b0 bl 0xb6a84 <alSourcePlay@plt> */
/* @0x2244b4 ldr r0, [r9, #0x2b4] */
/* @0x2244b8 movw r1, #0x1025 */
/* @0x2244bc mov r2, #0 */
/* @0x2244c0 bl 0xb6a78 <alSourcef@plt> */
/* @0x2244c4 movw r3, #0x1013 */
/* @0x2244c8 cmp r8, r3 */
/* @0x2244cc beq 0x224764 <_Z13GetStreamInfoP12cAudio_Sound+0x8b4> */
/* @0x2244d0 ldr r3, [r9, #0x2c4] */
/* @0x2244d4 cmp r3, #0 */
/* @0x2244d8 beq 0x224374 <_Z13GetStreamInfoP12cAudio_Sound+0x4c4> */
/* @0x2244dc b 0x2242c0 <_Z13GetStreamInfoP12cAudio_Sound+0x410> */
/* @0x2244e0 rscsle r10, r1, #252, #18 */
/* @0x2244e4 svclo #0x50624d */
/* @0x2244e8 ldrbtmi r0, [r10], #-0 */
/* @0x2244ec ldrheq sp, [r12], -r0 */
/* @0x2244f0 andseq r0, r3, r0, asr r12 */
/* @0x2244f4 andseq r0, r3, r8, lsr #24 */
/* @0x2244f8 cmp r3, #0 */
/* @0x2244fc beq 0x224524 <_Z13GetStreamInfoP12cAudio_Sound+0x674> */
/* @0x224500 mov r0, r9 */
/* @0x224504 bl 0x2236d4 <_Z8ogg_readPvjjS_+0x48> */
/* @0x224508 cmp r7, #8 */
/* @0x22450c bne 0x224524 <_Z13GetStreamInfoP12cAudio_Sound+0x674> */
/* @0x224510 mov r0, r10 */
/* @0x224514 bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x224518 strb r11, [r9, #0x2d5] */
/* @0x22451c mov r0, r10 */
/* @0x224520 bl 0x223aa4 <_ZN10COggThread6UnlockEv> */
/* @0x224524 cmp r8, #0 */
/* @0x224528 ldreq r3, [r9, #0x2c4] */
/* @0x22452c beq 0x2243d4 <_Z13GetStreamInfoP12cAudio_Sound+0x524> */
/* @0x224530 ldr r3, [r9, #0x2bc] */
/* @0x224534 and r8, r7, #16 */
/* @0x224538 ands r8, r8, #255 */
/* @0x22453c ldrb r2, [r3, #0x24] */
/* @0x224540 ldrne r8, [r9, #0x2e4] */
/* @0x224544 cmp r2, #0 */
/* @0x224548 bne 0x224634 <_Z13GetStreamInfoP12cAudio_Sound+0x784> */
/* @0x22454c mov r0, r9 */
/* @0x224550 mov r1, r10 */
/* @0x224554 bl 0x223cb4 <_ZN10COggThread8LogErrorEPKcz+0x9c> */
/* @0x224558 cmp r0, #0 */
/* @0x22455c beq 0x2244d0 <_Z13GetStreamInfoP12cAudio_Sound+0x620> */
/* @0x224560 ubfx r7, r7, #0x1, #0x1 */
/* @0x224564 mvn r1, #0 */
/* @0x224568 cmp r7, #0 */
/* @0x22456c mov r0, r9 */
/* @0x224570 moveq r3, #1 */
/* @0x224574 movne r3, #2 */
/* @0x224578 str r3, [r9, #0x2c4] */
/* @0x22457c bl 0x232e28 <ov_info> */
/* @0x224580 mov r2, #0 */
/* @0x224584 movw r1, #0x1009 */
/* @0x224588 str r11, [r9, #0x2e0] */
/* @0x22458c str r0, [r9, #0x298] */
/* @0x224590 ldr r0, [r9, #0x2b4] */
/* @0x224594 bl 0xb6a6c <alSourcei@plt> */
/* @0x224598 bl 0xb6a54 <alGetError@plt> */
/* @0x22459c subs r2, r0, #0 */
/* @0x2245a0 bne 0x2246d8 <_Z13GetStreamInfoP12cAudio_Sound+0x828> */
/* @0x2245a4 mov r2, #0 */
/* @0x2245a8 ldr r0, [r9, #0x2b4] */
/* @0x2245ac movw r1, #0x1007 */
/* @0x2245b0 bl 0xb6a6c <alSourcei@plt> */
/* @0x2245b4 bl 0xb6a54 <alGetError@plt> */
/* @0x2245b8 subs r2, r0, #0 */
/* @0x2245bc bne 0x2246c8 <_Z13GetStreamInfoP12cAudio_Sound+0x818> */
/* @0x2245c0 cmp r8, #0 */
/* @0x2245c4 ble 0x2245d8 <_Z13GetStreamInfoP12cAudio_Sound+0x728> */
/* @0x2245c8 mov r0, r9 */
/* @0x2245cc mov r2, r8 */
/* @0x2245d0 asr r3, r8, #31 */
/* @0x2245d4 bl 0x232a44 <ov_time_seek> */
/* @0x2245d8 str r11, [r9, #0x2a8] */
/* @0x2245dc mov r0, r9 */
/* @0x2245e0 mov r1, r10 */
/* @0x2245e4 ldr r2, [r9, #0x2ac] */
/* @0x2245e8 mov r3, r7 */
/* @0x2245ec bl 0x224074 <_Z13GetStreamInfoP12cAudio_Sound+0x1c4> */
/* @0x2245f0 cmp r0, #0 */
/* @0x2245f4 ble 0x22466c <_Z13GetStreamInfoP12cAudio_Sound+0x7bc> */
/* @0x2245f8 mov r1, r10 */
/* @0x2245fc mov r3, r7 */
/* @0x224600 ldr r2, [r9, #0x2b0] */
/* @0x224604 mov r0, r9 */
/* @0x224608 bl 0x224074 <_Z13GetStreamInfoP12cAudio_Sound+0x1c4> */
/* @0x22460c add r2, r9, #684 */
/* @0x224610 cmp r0, #0 */
/* @0x224614 ldr r0, [r9, #0x2b4] */
/* @0x224618 movgt r1, #2 */
/* @0x22461c movle r1, #1 */
/* @0x224620 bl 0xb6b8c <alSourceQueueBuffers@plt> */
/* @0x224624 ldr r0, [r9, #0x2b4] */
/* @0x224628 bl 0xb6a84 <alSourcePlay@plt> */
/* @0x22462c ldr r3, [r9, #0x2c4] */
/* @0x224630 b 0x2244d4 <_Z13GetStreamInfoP12cAudio_Sound+0x624> */
/* @0x224634 ldr r3, [r3, #0x30] */
/* @0x224638 mov r1, r9 */
/* @0x22463c mov r2, r10 */
/* @0x224640 mov r0, r3 */
/* @0x224644 str r3, [sp, #0x4] */
/* @0x224648 bl 0x223d28 <_ZN10COggThread8LogErrorEPKcz+0x110> */
/* @0x22464c ldr r3, [sp, #0x4] */
/* @0x224650 cmp r0, #0 */
/* @0x224654 bne 0x224560 <_Z13GetStreamInfoP12cAudio_Sound+0x6b0> */
/* @0x224658 mov r0, r3 */
/* @0x22465c mov r1, r9 */
/* @0x224660 mov r2, r10 */
/* @0x224664 bl 0x223e10 <_ZN10COggThread8LogErrorEPKcz+0x1f8> */
/* @0x224668 b 0x224558 <_Z13GetStreamInfoP12cAudio_Sound+0x6a8> */
/* @0x22466c ldr r3, [r9, #0x2c4] */
/* @0x224670 cmp r3, #0 */
/* @0x224674 beq 0x224680 <_Z13GetStreamInfoP12cAudio_Sound+0x7d0> */
/* @0x224678 mov r0, r9 */
/* @0x22467c bl 0x2236d4 <_Z8ogg_readPvjjS_+0x48> */
/* @0x224680 mov r0, r10 */
/* @0x224684 bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x224688 strb r11, [r9, #0x2d5] */
/* @0x22468c mov r0, r10 */
/* @0x224690 bl 0x223aa4 <_ZN10COggThread6UnlockEv> */
/* @0x224694 b 0x2244d0 <_Z13GetStreamInfoP12cAudio_Sound+0x620> */
/* @0x224698 ldr r3, [r9, #0x2c4] */
/* @0x22469c cmp r3, #3 */
/* @0x2246a0 bne 0x2246e8 <_Z13GetStreamInfoP12cAudio_Sound+0x838> */
/* @0x2246a4 mov r0, r9 */
/* @0x2246a8 bl 0x2236d4 <_Z8ogg_readPvjjS_+0x48> */
/* @0x2246ac mov r0, r10 */
/* @0x2246b0 bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x2246b4 strb r11, [r9, #0x2d5] */
/* @0x2246b8 mov r0, r10 */
/* @0x2246bc bl 0x223aa4 <_ZN10COggThread6UnlockEv> */
/* @0x2246c0 ldr r2, [r10, #0x808] */
/* @0x2246c4 b 0x224378 <_Z13GetStreamInfoP12cAudio_Sound+0x4c8> */
/* @0x2246c8 mov r0, r10 */
/* @0x2246cc ldr r1, [sp, #0x18] */
/* @0x2246d0 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz> */
/* @0x2246d4 b 0x2245c0 <_Z13GetStreamInfoP12cAudio_Sound+0x710> */
/* @0x2246d8 mov r0, r10 */
/* @0x2246dc ldr r1, [sp, #0x1c] */
/* @0x2246e0 bl 0x223c18 <_ZN10COggThread8LogErrorEPKcz> */
/* @0x2246e4 b 0x2245a4 <_Z13GetStreamInfoP12cAudio_Sound+0x6f4> */
/* @0x2246e8 ldr r0, [r9, #0x2b4] */
/* @0x2246ec bl 0xb6a84 <alSourcePlay@plt> */
/* @0x2246f0 b 0x224374 <_Z13GetStreamInfoP12cAudio_Sound+0x4c4> */
/* @0x2246f4 mov r0, r10 */
/* @0x2246f8 bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x2246fc ldr r2, [r10, #0x808] */
/* @0x224700 cmp r2, #0 */
/* @0x224704 movgt r4, #0 */
/* @0x224708 movgt r6, r4 */
/* @0x22470c movgt r7, r4 */
/* @0x224710 ble 0x224748 <_Z13GetStreamInfoP12cAudio_Sound+0x898> */
/* @0x224714 ldr r5, [r10, #0x804] */
/* @0x224718 add r6, r6, #1 */
/* @0x22471c add r5, r5, r4 */
/* @0x224720 add r4, r4, #768 */
/* @0x224724 ldr r3, [r5, #0x2c4] */
/* @0x224728 mov r0, r5 */
/* @0x22472c cmp r3, #0 */
/* @0x224730 beq 0x224740 <_Z13GetStreamInfoP12cAudio_Sound+0x890> */
/* @0x224734 bl 0x2236d4 <_Z8ogg_readPvjjS_+0x48> */
/* @0x224738 ldr r2, [r10, #0x808] */
/* @0x22473c strb r7, [r5, #0x2d5] */
/* @0x224740 cmp r6, r2 */
/* @0x224744 blt 0x224714 <_Z13GetStreamInfoP12cAudio_Sound+0x864> */
/* @0x224748 mov r0, r10 */
/* @0x22474c bl 0x223aa4 <_ZN10COggThread6UnlockEv> */
/* @0x224750 mov r0, #0 */
/* @0x224754 strb r0, [r10, #0x830] */
/* @0x224758 add sp, sp, #52 */
/* @0x22475c vpop {d8, d9} */
/* @0x224760 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x224764 ldr r0, [r9, #0x2b4] */
/* @0x224768 bl 0xb6ab4 <alSourcePause@plt> */
/* @0x22476c b 0x2244d0 <_Z13GetStreamInfoP12cAudio_Sound+0x620> */

/* ── FUNC 0x224770 · COggThread::ShowError() · size=80 · insn=20 */
/* @0x224770 push {r4, lr} */
/* @0x224774 mov r4, r0 */
/* @0x224778 bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x22477c ldrb r3, [r4, #0x800] */
/* @0x224780 cmp r3, #0 */
/* @0x224784 beq 0x2247b0 <_ZN10COggThread9ShowErrorEv+0x40> */
/* @0x224788 ldr r3, [pc, #0x2c] */
/* @0x22478c mov r1, r4 */
/* @0x224790 ldr r3, [pc, r3] */
/* @0x224794 ldr r0, [r3] */
/* @0x224798 ldr r3, [r0] */
/* @0x22479c ldr r3, [r3, #0xc] */
/* @0x2247a0 blx r3 */
/* @0x2247a4 mov r3, #0 */
/* @0x2247a8 strb r3, [r4] */
/* @0x2247ac strb r3, [r4, #0x800] */
/* @0x2247b0 mov r0, r4 */
/* @0x2247b4 pop {r4, lr} */
/* @0x2247b8 b 0x223aa4 <_ZN10COggThread6UnlockEv> */
/* @0x2247bc andseq r8, r12, r4, lsl #31 */

/* ── FUNC 0x2247c0 · COggThread::Tick() · size=116 · insn=29 */
/* @0x2247c0 push {r3, r4, r5, lr} */
/* @0x2247c4 mov r4, r0 */
/* @0x2247c8 bl 0x223a9c <_ZN10COggThread4LockEv> */
/* @0x2247cc ldrb r3, [r4, #0x800] */
/* @0x2247d0 cmp r3, #0 */
/* @0x2247d4 beq 0x224820 <_ZN10COggThread4TickEv+0x60> */
/* @0x2247d8 ldr r3, [pc, #0x4c] */
/* @0x2247dc ldr r1, [pc, #0x4c] */
/* @0x2247e0 ldr r3, [pc, r3] */
/* @0x2247e4 ldr r2, [r4, #0x80c] */
/* @0x2247e8 add r1, pc, r1 */
/* @0x2247ec ldr r5, [r3] */
/* @0x2247f0 ldr r3, [r5] */
/* @0x2247f4 mov r0, r5 */
/* @0x2247f8 ldr r3, [r3, #0xc] */
/* @0x2247fc blx r3 */
/* @0x224800 ldr r3, [r5] */
/* @0x224804 mov r0, r5 */
/* @0x224808 mov r1, r4 */
/* @0x22480c ldr r3, [r3, #0xc] */
/* @0x224810 blx r3 */
/* @0x224814 mov r3, #0 */
/* @0x224818 strb r3, [r4] */
/* @0x22481c strb r3, [r4, #0x800] */
/* @0x224820 mov r0, r4 */
/* @0x224824 pop {r3, r4, r5, lr} */
/* @0x224828 b 0x223aa4 <_ZN10COggThread6UnlockEv> */
/* @0x22482c andseq r8, r12, r4, lsr pc */
/* @0x224830 andseq r0, r3, r4, ror #12 */
