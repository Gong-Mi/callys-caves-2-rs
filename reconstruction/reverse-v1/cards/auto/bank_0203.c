/* libyoyo.so 覆盖卡组 0203
 * 函数 0x224834..0x225fa4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x224834 · COggSyncThread::COggSyncThread() · size=180 · insn=45 */
/* @0x224834 push {r4, r5, r6, lr} */
/* @0x224838 mov r4, r0 */
/* @0x22483c mov r5, #0 */
/* @0x224840 mov r0, #8 */
/* @0x224844 strb r5, [r4, #0x83c] */
/* @0x224848 str r5, [r4, #0x834] */
/* @0x22484c str r5, [r4, #0x838] */
/* @0x224850 strb r5, [r4, #0x83d] */
/* @0x224854 str r5, [r4, #0x840] */
/* @0x224858 str r5, [r4, #0x844] */
/* @0x22485c bl 0x27c524 <_Znwj> */
/* @0x224860 ldr r1, [pc, #0x7c] */
/* @0x224864 add r1, pc, r1 */
/* @0x224868 mov r6, r0 */
/* @0x22486c bl 0x27e070 <_ZN5MutexC2EPKc> */
/* @0x224870 mov r1, #2080 */
/* @0x224874 str r6, [r4, #0x848] */
/* @0x224878 mvn r12, #0 */
/* @0x22487c strb r5, [r4, #0x800] */
/* @0x224880 mov r2, #0 */
/* @0x224884 mov r3, #0 */
/* @0x224888 strb r5, [r4, #0x801] */
/* @0x22488c mov r0, r4 */
/* @0x224890 strb r5, [r4] */
/* @0x224894 strb r5, [r4, #0x802] */
/* @0x224898 strb r5, [r4, #0x803] */
/* @0x22489c str r5, [r4, #0x808] */
/* @0x2248a0 str r5, [r4, #0x82c] */
/* @0x2248a4 strb r5, [r4, #0x84d] */
/* @0x2248a8 strb r5, [r4, #0x84e] */
/* @0x2248ac str r5, [r4, #0x80c] */
/* @0x2248b0 strb r5, [r4, #0x850] */
/* @0x2248b4 strb r5, [r4, #0x84f] */
/* @0x2248b8 strb r5, [r4, #0x851] */
/* @0x2248bc strb r5, [r4, #0x852] */
/* @0x2248c0 strb r5, [r4, #0x853] */
/* @0x2248c4 strb r5, [r4, #0x854] */
/* @0x2248c8 str r5, [r4, #0x828] */
/* @0x2248cc str r5, [r4, #0x858] */
/* @0x2248d0 str r5, [r4, #0x85c] */
/* @0x2248d4 str r5, [r4, #0x860] */
/* @0x2248d8 str r12, [r4, #0x810] */
/* @0x2248dc strd r2, r3, [r4, r1] */
/* @0x2248e0 pop {r4, r5, r6, pc} */
/* @0x2248e4 andseq sp, r0, r0, asr pc */

/* ── FUNC 0x224834 · COggSyncThread::COggSyncThread() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2248e8 · COggSyncThread::WaitForThreadExit() · size=12 · insn=3 */
/* @0x2248e8 add r0, r0, #2096 */
/* @0x2248ec add r0, r0, #4 */
/* @0x2248f0 b 0x27e108 <_ZN7CThread11WaitForExitEv> */

/* ── FUNC 0x2248f4 · COggSyncThread::Suspend() · size=76 · insn=19 */
/* @0x2248f4 push {r3, lr} */
/* @0x2248f8 ldrb r3, [r0, #0x803] */
/* @0x2248fc cmp r3, #0 */
/* @0x224900 popeq {r3, pc} */
/* @0x224904 ldrb r3, [r0, #0x84d] */
/* @0x224908 cmp r3, #0 */
/* @0x22490c beq 0x224904 <_ZN14COggSyncThread7SuspendEv+0x10> */
/* @0x224910 ldr r3, [pc, #0x20] */
/* @0x224914 ldr r2, [r0, #0x810] */
/* @0x224918 ldr r3, [pc, r3] */
/* @0x22491c ldr r1, [pc, #0x18] */
/* @0x224920 ldr r0, [r3] */
/* @0x224924 add r1, pc, r1 */
/* @0x224928 ldr r3, [r0] */
/* @0x22492c ldr r3, [r3, #0xc] */
/* @0x224930 blx r3 */
/* @0x224934 pop {r3, pc} */
/* @0x224938 ldrsheq r8, [r12], -r12 */
/* @0x22493c andseq r0, r3, r4, lsl #8 */

/* ── FUNC 0x224940 · COggSyncThread::CleanUp() · size=160 · insn=40 */
/* @0x224940 push {r4, r5, r6, lr} */
/* @0x224944 mov r5, r0 */
/* @0x224948 ldr r4, [r0, #0x830] */
/* @0x22494c cmp r4, #0 */
/* @0x224950 beq 0x224964 <_ZN14COggSyncThread7CleanUpEv+0x24> */
/* @0x224954 mov r0, r4 */
/* @0x224958 bl 0x27e020 <_ZN5MutexD2Ev> */
/* @0x22495c mov r0, r4 */
/* @0x224960 bl 0x27d1d0 <_ZdlPv> */
/* @0x224964 ldr r0, [r5, #0x804] */
/* @0x224968 cmp r0, #0 */
/* @0x22496c beq 0x2249ac <_ZN14COggSyncThread7CleanUpEv+0x6c> */
/* @0x224970 ldr r4, [r0, #-0x4] */
/* @0x224974 add r4, r4, r4, lsl #1 */
/* @0x224978 add r4, r0, r4, lsl #8 */
/* @0x22497c cmp r0, r4 */
/* @0x224980 beq 0x2249a4 <_ZN14COggSyncThread7CleanUpEv+0x64> */
/* @0x224984 sub r4, r4, #768 */
/* @0x224988 mov r0, r4 */
/* @0x22498c mov r6, r4 */
/* @0x224990 bl 0x2234d0 <_ZN11SOggChannelD2Ev> */
/* @0x224994 ldr r0, [r5, #0x804] */
/* @0x224998 cmp r0, r4 */
/* @0x22499c sub r4, r4, #768 */
/* @0x2249a0 bne 0x224988 <_ZN14COggSyncThread7CleanUpEv+0x48> */
/* @0x2249a4 sub r0, r0, #8 */
/* @0x2249a8 bl 0x27d1d4 <_ZdaPv> */
/* @0x2249ac ldr r0, [r5, #0x82c] */
/* @0x2249b0 mov r3, #0 */
/* @0x2249b4 str r3, [r5, #0x804] */
/* @0x2249b8 cmp r0, r3 */
/* @0x2249bc beq 0x2249c4 <_ZN14COggSyncThread7CleanUpEv+0x84> */
/* @0x2249c0 bl 0x27d1d4 <_ZdaPv> */
/* @0x2249c4 ldr r0, [r5, #0x858] */
/* @0x2249c8 bl 0xb655c <free@plt> */
/* @0x2249cc mov r3, #0 */
/* @0x2249d0 str r3, [r5, #0x858] */
/* @0x2249d4 str r3, [r5, #0x82c] */
/* @0x2249d8 strb r3, [r5, #0x803] */
/* @0x2249dc pop {r4, r5, r6, pc} */

/* ── FUNC 0x2249e0 · COggSyncThread::StartThread() · size=108 · insn=27 */
/* @0x2249e0 ldr r1, [pc, #0x58] */
/* @0x2249e4 push {r3, r4, r5, lr} */
/* @0x2249e8 mov r4, r0 */
/* @0x2249ec add r0, r0, #2096 */
/* @0x2249f0 mov r2, r4 */
/* @0x2249f4 add r0, r0, #4 */
/* @0x2249f8 add r1, pc, r1 */
/* @0x2249fc mov r3, #0 */
/* @0x224a00 bl 0x27e0c0 <_ZN7CThread5StartEPFPvS0_ES0_NS_9ePriorityE> */
/* @0x224a04 subs r5, r0, #0 */
/* @0x224a08 bne 0x224a38 <_ZN14COggSyncThread11StartThreadEv+0x58> */
/* @0x224a0c ldr r3, [pc, #0x30] */
/* @0x224a10 ldr r1, [pc, #0x30] */
/* @0x224a14 ldr r3, [pc, r3] */
/* @0x224a18 ldr r2, [r4, #0x838] */
/* @0x224a1c add r1, pc, r1 */
/* @0x224a20 ldr r0, [r3] */
/* @0x224a24 ldr r3, [r0] */
/* @0x224a28 ldr r3, [r3, #0xc] */
/* @0x224a2c blx r3 */
/* @0x224a30 mov r0, r4 */
/* @0x224a34 bl 0x224940 <_ZN14COggSyncThread7CleanUpEv> */
/* @0x224a38 mov r0, r5 */
/* @0x224a3c pop {r3, r4, r5, pc} */
/* @0x224a40 strheq r0, [r0], -r0 */
/* @0x224a44 andseq r8, r12, r0, lsl #26 */
/* @0x224a48 andseq r0, r3, r12, ror #5 */

/* ── FUNC 0x224a4c · COggSyncThread::Create(int, int, int, bool) · size=472 · insn=118 */
/* @0x224a4c cmp r3, #2785280 */
/* @0x224a50 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x224a54 mov r7, r0 */
/* @0x224a58 addls r0, r3, r3, lsl #1 */
/* @0x224a5c sub sp, sp, #12 */
/* @0x224a60 str r3, [r7, #0x808] */
/* @0x224a64 mvnhi r0, #0 */
/* @0x224a68 lslls r0, r0, #8 */
/* @0x224a6c mov r8, r3 */
/* @0x224a70 addls r0, r0, #8 */
/* @0x224a74 mov r10, r1 */
/* @0x224a78 mov r9, r2 */
/* @0x224a7c ldrb r4, [sp, #0x30] */
/* @0x224a80 bl 0x27d14c <_Znaj> */
/* @0x224a84 sub r6, r8, #1 */
/* @0x224a88 cmn r6, #1 */
/* @0x224a8c mov r3, #768 */
/* @0x224a90 add r11, r0, #8 */
/* @0x224a94 str r8, [r0, #0x4] */
/* @0x224a98 str r3, [r0] */
/* @0x224a9c movne r5, r11 */
/* @0x224aa0 beq 0x224abc <_ZN14COggSyncThread6CreateEiiib+0x70> */
/* @0x224aa4 mov r0, r5 */
/* @0x224aa8 sub r6, r6, #1 */
/* @0x224aac bl 0x2233f4 <_ZN11SOggChannelC2Ev> */
/* @0x224ab0 cmn r6, #1 */
/* @0x224ab4 add r5, r5, #768 */
/* @0x224ab8 bne 0x224aa4 <_ZN14COggSyncThread6CreateEiiib+0x58> */
/* @0x224abc cmp r4, #0 */
/* @0x224ac0 mov r5, #0 */
/* @0x224ac4 mov r0, r11 */
/* @0x224ac8 strb r5, [r7, #0x84c] */
/* @0x224acc str r10, [r7, #0x810] */
/* @0x224ad0 str r11, [r7, #0x804] */
/* @0x224ad4 strb r5, [r7, #0x800] */
/* @0x224ad8 strb r5, [r7, #0x801] */
/* @0x224adc strb r5, [r7, #0x802] */
/* @0x224ae0 strb r5, [r7, #0x84d] */
/* @0x224ae4 bne 0x224b8c <_ZN14COggSyncThread6CreateEiiib+0x140> */
/* @0x224ae8 cmp r8, #0 */
/* @0x224aec ble 0x224b40 <_ZN14COggSyncThread6CreateEiiib+0xf4> */
/* @0x224af0 ldr r11, [pc, #0x124] */
/* @0x224af4 lsl r6, r10, #2 */
/* @0x224af8 lsl r3, r9, #2 */
/* @0x224afc str r3, [sp, #0x4] */
/* @0x224b00 ldr r11, [pc, r11] */
/* @0x224b04 add r3, r4, r4, lsl #1 */
/* @0x224b08 ldr r2, [r11] */
/* @0x224b0c add r4, r4, #1 */
/* @0x224b10 lsl r5, r3, #8 */
/* @0x224b14 add r0, r0, r5 */
/* @0x224b18 ldr r1, [r2, r6] */
/* @0x224b1c bl 0x223474 <_ZN11SOggChannel4InitEj> */
/* @0x224b20 ldr r0, [r7, #0x804] */
/* @0x224b24 ldr r3, [sp, #0x4] */
/* @0x224b28 cmp r4, r8 */
/* @0x224b2c add r6, r6, r3 */
/* @0x224b30 add r3, r0, r5 */
/* @0x224b34 str r10, [r3, #0x2b8] */
/* @0x224b38 add r10, r10, r9 */
/* @0x224b3c bne 0x224b04 <_ZN14COggSyncThread6CreateEiiib+0xb8> */
/* @0x224b40 cmp r8, #266338304 */
/* @0x224b44 mvnhi r0, #0 */
/* @0x224b48 lslls r0, r8, #3 */
/* @0x224b4c bl 0x27d14c <_Znaj> */
/* @0x224b50 str r0, [r7, #0x82c] */
/* @0x224b54 mov r0, #8 */
/* @0x224b58 bl 0x27c524 <_Znwj> */
/* @0x224b5c ldr r1, [pc, #0xbc] */
/* @0x224b60 add r1, pc, r1 */
/* @0x224b64 mov r4, r0 */
/* @0x224b68 bl 0x27e070 <_ZN5MutexC2EPKc> */
/* @0x224b6c str r4, [r7, #0x830] */
/* @0x224b70 mov r0, r7 */
/* @0x224b74 bl 0x2249e0 <_ZN14COggSyncThread11StartThreadEv> */
/* @0x224b78 cmp r0, #0 */
/* @0x224b7c movne r0, #1 */
/* @0x224b80 strbne r0, [r7, #0x803] */
/* @0x224b84 add sp, sp, #12 */
/* @0x224b88 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x224b8c movw r0, #0x807f */
/* @0x224b90 mov r4, r7 */
/* @0x224b94 bl 0xb6544 <malloc@plt> */
/* @0x224b98 add r3, r0, #127 */
/* @0x224b9c str r0, [r7, #0x858] */
/* @0x224ba0 bic r3, r3, #127 */
/* @0x224ba4 mov r0, #1 */
/* @0x224ba8 str r3, [r7, #0x85c] */
/* @0x224bac add r3, r3, #16384 */
/* @0x224bb0 str r3, [r4, #0x860]! */
/* @0x224bb4 add r1, r4, #12 */
/* @0x224bb8 bl 0xb6a90 <alGenSources@plt> */
/* @0x224bbc ldr r0, [r7, #0x86c] */
/* @0x224bc0 movw r1, #0x100a */
/* @0x224bc4 mov r2, #0 */
/* @0x224bc8 bl 0xb6a78 <alSourcef@plt> */
/* @0x224bcc add r1, r4, #4 */
/* @0x224bd0 mov r0, #2 */
/* @0x224bd4 bl 0xb6af0 <alGenBuffers@plt> */
/* @0x224bd8 cmp r8, #0 */
/* @0x224bdc str r5, [r7, #0x870] */
/* @0x224be0 ble 0x224b40 <_ZN14COggSyncThread6CreateEiiib+0xf4> */
/* @0x224be4 ldr r0, [r7, #0x804] */
/* @0x224be8 mov r4, r5 */
/* @0x224bec mvn r6, #0 */
/* @0x224bf0 add r0, r0, r4 */
/* @0x224bf4 mvn r1, #0 */
/* @0x224bf8 bl 0x223474 <_ZN11SOggChannel4InitEj> */
/* @0x224bfc ldr r0, [r7, #0x804] */
/* @0x224c00 add r5, r5, #1 */
/* @0x224c04 add r3, r0, r4 */
/* @0x224c08 cmp r5, r8 */
/* @0x224c0c add r4, r4, #768 */
/* @0x224c10 str r6, [r3, #0x2b8] */
/* @0x224c14 bne 0x224bf0 <_ZN14COggSyncThread6CreateEiiib+0x1a4> */
/* @0x224c18 b 0x224b40 <_ZN14COggSyncThread6CreateEiiib+0xf4> */
/* @0x224c1c andseq r12, r12, r12, asr #17 */
/* @0x224c20 andseq r0, r3, r4, ror #3 */

/* ── FUNC 0x224c24 · COggSyncThread::Lock() · size=8 · insn=2 */
/* @0x224c24 ldr r0, [r0, #0x830] */
/* @0x224c28 b 0x27e084 <_ZN5Mutex4LockEv> */

/* ── FUNC 0x224c2c · COggSyncThread::Unlock() · size=8 · insn=2 */
/* @0x224c2c ldr r0, [r0, #0x830] */
/* @0x224c30 b 0x27e09c <_ZN5Mutex6UnlockEv> */

/* ── FUNC 0x224c34 · UpdateTimingEvents(COggSyncThread*) · size=168 · insn=42 */
/* @0x224c34 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x224c38 mov r6, r0 */
/* @0x224c3c bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x224c40 bl 0x215148 <Timing_Time> */
/* @0x224c44 ldr r8, [pc, #0x8c] */
/* @0x224c48 movw r4, #0x7b80 */
/* @0x224c4c movt r4, #0xffe1 */
/* @0x224c50 ldr r8, [pc, r8] */
/* @0x224c54 mvn r5, #0 */
/* @0x224c58 ldr r12, [r8] */
/* @0x224c5c adds r4, r4, r0 */
/* @0x224c60 adc r5, r5, r1 */
/* @0x224c64 cmp r12, #0 */
/* @0x224c68 movne r7, #0 */
/* @0x224c6c bne 0x224cac <_Z18UpdateTimingEventsP14COggSyncThread+0x78> */
/* @0x224c70 b 0x224ccc <_Z18UpdateTimingEventsP14COggSyncThread+0x98> */
/* @0x224c74 cmp r7, #0 */
/* @0x224c78 mov r0, r12 */
/* @0x224c7c ldrne r3, [r12, #0x18] */
/* @0x224c80 strne r3, [r7, #0x18] */
/* @0x224c84 ldr r3, [r8] */
/* @0x224c88 cmp r12, r3 */
/* @0x224c8c ldreq r3, [r12, #0x18] */
/* @0x224c90 ldrne r9, [r12, #0x18] */
/* @0x224c94 moveq r9, r3 */
/* @0x224c98 streq r3, [r8] */
/* @0x224c9c bl 0x27d1d0 <_ZdlPv> */
/* @0x224ca0 mov r12, r9 */
/* @0x224ca4 cmp r12, #0 */
/* @0x224ca8 beq 0x224ccc <_Z18UpdateTimingEventsP14COggSyncThread+0x98> */
/* @0x224cac ldrd r2, r3, [r12, #16] */
/* @0x224cb0 cmp r2, r4 */
/* @0x224cb4 sbcs r1, r3, r5 */
/* @0x224cb8 blt 0x224c74 <_Z18UpdateTimingEventsP14COggSyncThread+0x40> */
/* @0x224cbc mov r7, r12 */
/* @0x224cc0 ldr r12, [r12, #0x18] */
/* @0x224cc4 cmp r12, #0 */
/* @0x224cc8 bne 0x224cac <_Z18UpdateTimingEventsP14COggSyncThread+0x78> */
/* @0x224ccc mov r0, r6 */
/* @0x224cd0 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x224cd4 b 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x224cd8 andseq r12, r12, r12, lsr #16 */

/* ── FUNC 0x224cdc · DrawTimingEvents(COggSyncThread*) · size=276 · insn=69 */
/* @0x224cdc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x224ce0 vpush {d8, d9} */
/* @0x224ce4 sub sp, sp, #12 */
/* @0x224ce8 mov r6, r0 */
/* @0x224cec bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x224cf0 bl 0x215148 <Timing_Time> */
/* @0x224cf4 mov r9, r1 */
/* @0x224cf8 mov r8, r0 */
/* @0x224cfc bl 0x17af50 <_Z19GR_Window_Get_Widthv> */
/* @0x224d00 vldr s15, [pc, #220] */
/* @0x224d04 vmov s14, r0 */
/* @0x224d08 vcvt.f32.s32 s16, s14 */
/* @0x224d0c vdiv.f32 s16, s16, s15 */
/* @0x224d10 bl 0x17af64 <_Z20GR_Window_Get_Heightv> */
/* @0x224d14 ldr r3, [pc, #0xcc] */
/* @0x224d18 ldr r2, [pc, #0xcc] */
/* @0x224d1c ldr r3, [pc, r3] */
/* @0x224d20 ldr r2, [pc, r2] */
/* @0x224d24 ldr r7, [r3] */
/* @0x224d28 ldr r11, [r2] */
/* @0x224d2c cmp r7, #0 */
/* @0x224d30 sub r0, r0, #50 */
/* @0x224d34 vmov s15, r0 */
/* @0x224d38 vcvt.f32.s32 s15, s15 */
/* @0x224d3c vmov r10, s15 */
/* @0x224d40 beq 0x224dd0 <_Z16DrawTimingEventsP14COggSyncThread+0xf4> */
/* @0x224d44 ldrd r4, r5, [r7, #8] */
/* @0x224d48 mov r2, #2000 */
/* @0x224d4c mov r3, #0 */
/* @0x224d50 mov r0, r8 */
/* @0x224d54 mov r1, r9 */
/* @0x224d58 subs r0, r0, r4 */
/* @0x224d5c sbc r1, r1, r5 */
/* @0x224d60 bl 0x319414 <__aeabi_ldivmod> */
/* @0x224d64 bl 0x319398 <__floatdisf> */
/* @0x224d68 mov r2, #2000 */
/* @0x224d6c mov r3, #0 */
/* @0x224d70 vmov s14, r0 */
/* @0x224d74 ldrd r0, r1, [r7, #16] */
/* @0x224d78 subs r0, r0, r4 */
/* @0x224d7c sbc r1, r1, r5 */
/* @0x224d80 vmul.f32 s17, s14, s16 */
/* @0x224d84 bl 0x319414 <__aeabi_ldivmod> */
/* @0x224d88 bl 0x319398 <__floatdisf> */
/* @0x224d8c vmov s15, r0 */
/* @0x224d90 vmul.f32 s18, s15, s16 */
/* @0x224d94 bl 0x17af50 <_Z19GR_Window_Get_Widthv> */
/* @0x224d98 ldr r2, [r7] */
/* @0x224d9c mov r1, r10 */
/* @0x224da0 mov r3, r11 */
/* @0x224da4 str r2, [sp] */
/* @0x224da8 vmov r2, s18 */
/* @0x224dac sub r0, r0, #10 */
/* @0x224db0 vmov s14, r0 */
/* @0x224db4 vcvt.f32.s32 s15, s14 */
/* @0x224db8 vsub.f32 s15, s15, s17 */
/* @0x224dbc vmov r0, s15 */
/* @0x224dc0 bl 0x17b83c <_ZN12GraphicsPerf15RenderRectangleEffffj> */
/* @0x224dc4 ldr r7, [r7, #0x18] */
/* @0x224dc8 cmp r7, #0 */
/* @0x224dcc bne 0x224d44 <_Z16DrawTimingEventsP14COggSyncThread+0x68> */
/* @0x224dd0 mov r0, r6 */
/* @0x224dd4 add sp, sp, #12 */
/* @0x224dd8 vpop {d8, d9} */
/* @0x224ddc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x224de0 b 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x224de4 ldrbtmi r0, [r10], #-0 */
/* @0x224de8 andseq r12, r12, r0, ror #14 */
/* @0x224dec andseq r11, r12, r4, lsl r6 */

/* ── FUNC 0x224df0 · AddTimingEvent(COggSyncThread*, unsigned int, long long, long long) · size=88 · insn=22 */
/* @0x224df0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x224df4 mov r8, r1 */
/* @0x224df8 mov r6, r2 */
/* @0x224dfc mov r7, r3 */
/* @0x224e00 mov r9, r0 */
/* @0x224e04 ldrd r4, r5, [sp, #32] */
/* @0x224e08 bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x224e0c mov r0, #32 */
/* @0x224e10 bl 0x27c524 <_Znwj> */
/* @0x224e14 ldr r2, [pc, #0x28] */
/* @0x224e18 ldr r2, [pc, r2] */
/* @0x224e1c ldr r1, [r2] */
/* @0x224e20 mov r3, r0 */
/* @0x224e24 mov r0, r9 */
/* @0x224e28 str r8, [r3] */
/* @0x224e2c strd r6, r7, [r3, #8] */
/* @0x224e30 strd r4, r5, [r3, #16] */
/* @0x224e34 str r3, [r2] */
/* @0x224e38 str r1, [r3, #0x18] */
/* @0x224e3c pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x224e40 b 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x224e44 andseq r12, r12, r4, ror #12 */

/* ── FUNC 0x224e48 · COggSyncThread::Play_Sound(int&, cAudio_Sound*, bool, float, int) · size=236 · insn=59 */
/* @0x224e48 push {r4, r5, r6, r7, r8, lr} */
/* @0x224e4c vpush {d8} */
/* @0x224e50 mov r5, r0 */
/* @0x224e54 vldr s16, [sp, #32] */
/* @0x224e58 ldrb r0, [r0, #0x84e] */
/* @0x224e5c mov r6, r2 */
/* @0x224e60 mov r8, r3 */
/* @0x224e64 ldr r7, [sp, #0x24] */
/* @0x224e68 cmp r0, #0 */
/* @0x224e6c beq 0x224e90 <_ZN14COggSyncThread10Play_SoundERiP12cAudio_Soundbfi+0x48> */
/* @0x224e70 ldr r3, [r5, #0x80c] */
/* @0x224e74 str r3, [r1] */
/* @0x224e78 ldr r0, [r5, #0x80c] */
/* @0x224e7c ldr r3, [r5, #0x808] */
/* @0x224e80 add r0, r0, #1 */
/* @0x224e84 str r0, [r5, #0x80c] */
/* @0x224e88 cmp r0, r3 */
/* @0x224e8c bgt 0x224f04 <_ZN14COggSyncThread10Play_SoundERiP12cAudio_Soundbfi+0xbc> */
/* @0x224e90 ldr r1, [r1] */
/* @0x224e94 mov r0, r5 */
/* @0x224e98 ldr r3, [r5, #0x804] */
/* @0x224e9c add r1, r1, r1, lsl #1 */
/* @0x224ea0 add r4, r3, r1, lsl #8 */
/* @0x224ea4 bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x224ea8 vcmpe.f32 s16, #0 */
/* @0x224eac cmp r8, #0 */
/* @0x224eb0 mov r3, #1 */
/* @0x224eb4 strb r3, [r4, #0x2d6] */
/* @0x224eb8 movne r3, #3 */
/* @0x224ebc strbne r3, [r4, #0x2d6] */
/* @0x224ec0 mov r3, #0 */
/* @0x224ec4 str r7, [r4, #0x2dc] */
/* @0x224ec8 vmrs APSR_nzcv, fpscr */
/* @0x224ecc ldrbgt r3, [r4, #0x2d6] */
/* @0x224ed0 vstrgt s16, [r4, #744] */
/* @0x224ed4 strle r3, [r4, #0x2e8] */
/* @0x224ed8 orrgt r3, r3, #16 */
/* @0x224edc str r6, [r4, #0x2d8] */
/* @0x224ee0 strbgt r3, [r4, #0x2d6] */
/* @0x224ee4 mov r0, r5 */
/* @0x224ee8 vpop {d8} */
/* @0x224eec mov r2, #1 */
/* @0x224ef0 mov r3, #0 */
/* @0x224ef4 strb r2, [r4, #0x2d5] */
/* @0x224ef8 str r3, [r4, #0x2e0] */
/* @0x224efc pop {r4, r5, r6, r7, r8, lr} */
/* @0x224f00 b 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x224f04 ldr r3, [pc, #0x20] */
/* @0x224f08 ldr r1, [pc, #0x20] */
/* @0x224f0c ldr r3, [pc, r3] */
/* @0x224f10 add r1, pc, r1 */
/* @0x224f14 ldr r0, [r3] */
/* @0x224f18 ldr r3, [r0] */
/* @0x224f1c ldr r3, [r3, #0xc] */
/* @0x224f20 blx r3 */
/* @0x224f24 vpop {d8} */
/* @0x224f28 pop {r4, r5, r6, r7, r8, pc} */
/* @0x224f2c andseq r8, r12, r8, lsl #16 */
/* @0x224f30 andseq pc, r2, r4, asr #30 */

/* ── FUNC 0x224f34 · COggSyncThread::PauseResume_Sound(int, bool) · size=68 · insn=17 */
/* @0x224f34 ldr r3, [r0, #0x804] */
/* @0x224f38 add r1, r1, r1, lsl #1 */
/* @0x224f3c push {r4, r5, r6, lr} */
/* @0x224f40 add r5, r3, r1, lsl #8 */
/* @0x224f44 mov r4, r0 */
/* @0x224f48 mov r6, r2 */
/* @0x224f4c bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x224f50 ldrb r3, [r5, #0x2d6] */
/* @0x224f54 tst r3, #1 */
/* @0x224f58 beq 0x224f6c <_ZN14COggSyncThread17PauseResume_SoundEib+0x38> */
/* @0x224f5c cmp r6, #0 */
/* @0x224f60 orrne r3, r3, #4 */
/* @0x224f64 biceq r3, r3, #4 */
/* @0x224f68 strb r3, [r5, #0x2d6] */
/* @0x224f6c mov r0, r4 */
/* @0x224f70 pop {r4, r5, r6, lr} */
/* @0x224f74 b 0x224c2c <_ZN14COggSyncThread6UnlockEv> */

/* ── FUNC 0x224f78 · COggSyncThread::Stop_Sound(int) · size=44 · insn=11 */
/* @0x224f78 push {r3, r4, r5, lr} */
/* @0x224f7c add r1, r1, r1, lsl #1 */
/* @0x224f80 ldr r3, [r0, #0x804] */
/* @0x224f84 mov r4, r0 */
/* @0x224f88 add r5, r3, r1, lsl #8 */
/* @0x224f8c bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x224f90 mov r3, #8 */
/* @0x224f94 mov r0, r4 */
/* @0x224f98 strb r3, [r5, #0x2d6] */
/* @0x224f9c pop {r3, r4, r5, lr} */
/* @0x224fa0 b 0x224c2c <_ZN14COggSyncThread6UnlockEv> */

/* ── FUNC 0x224fa4 · COggSyncThread::Seek_Sound(int, float) · size=56 · insn=14 */
/* @0x224fa4 ldr r3, [r0, #0x804] */
/* @0x224fa8 add r1, r1, r1, lsl #1 */
/* @0x224fac push {r4, r5, r6, lr} */
/* @0x224fb0 add r4, r3, r1, lsl #8 */
/* @0x224fb4 mov r5, r0 */
/* @0x224fb8 mov r6, r2 */
/* @0x224fbc bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x224fc0 ldrb r3, [r4, #0x2d6] */
/* @0x224fc4 str r6, [r4, #0x2e8] */
/* @0x224fc8 mov r0, r5 */
/* @0x224fcc orr r3, r3, #16 */
/* @0x224fd0 strb r3, [r4, #0x2d6] */
/* @0x224fd4 pop {r4, r5, r6, lr} */
/* @0x224fd8 b 0x224c2c <_ZN14COggSyncThread6UnlockEv> */

/* ── FUNC 0x224fdc · COggSyncThread::LogError(char const*, ...) · size=156 · insn=39 */
/* @0x224fdc push {r1, r2, r3} */
/* @0x224fe0 mov r1, #255 */
/* @0x224fe4 push {r4, r5, r6, lr} */
/* @0x224fe8 sub sp, sp, #268 */
/* @0x224fec ldr r5, [pc, #0x80] */
/* @0x224ff0 add r12, sp, #288 */
/* @0x224ff4 add r6, sp, #4 */
/* @0x224ff8 mov r4, r0 */
/* @0x224ffc ldr r5, [pc, r5] */
/* @0x225000 mov r3, r12 */
/* @0x225004 ldr r2, [sp, #0x11c] */
/* @0x225008 mov r0, r6 */
/* @0x22500c ldr lr, [r5] */
/* @0x225010 str r12, [sp] */
/* @0x225014 str lr, [sp, #0x104] */
/* @0x225018 bl 0xb6610 <vsnprintf@plt> */
/* @0x22501c mov r0, r4 */
/* @0x225020 bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x225024 mov r3, #1 */
/* @0x225028 mov r0, r4 */
/* @0x22502c strb r3, [r4, #0x800] */
/* @0x225030 bl 0xb6538 <strlen@plt> */
/* @0x225034 mov r1, r6 */
/* @0x225038 rsb r2, r0, #2032 */
/* @0x22503c mov r0, r4 */
/* @0x225040 add r2, r2, #15 */
/* @0x225044 bl 0xb6c1c <strncat@plt> */
/* @0x225048 mov r0, r4 */
/* @0x22504c bl 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x225050 ldr r2, [sp, #0x104] */
/* @0x225054 ldr r3, [r5] */
/* @0x225058 cmp r2, r3 */
/* @0x22505c bne 0x225070 <_ZN14COggSyncThread8LogErrorEPKcz+0x94> */
/* @0x225060 add sp, sp, #268 */
/* @0x225064 pop {r4, r5, r6, lr} */
/* @0x225068 add sp, sp, #12 */
/* @0x22506c bx lr */
/* @0x225070 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x225074 andseq r8, r12, r4, asr r9 */

/* ── FUNC 0x225078 · COggSyncThread::ShowError() · size=80 · insn=20 */
/* @0x225078 push {r4, lr} */
/* @0x22507c mov r4, r0 */
/* @0x225080 bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x225084 ldrb r3, [r4, #0x800] */
/* @0x225088 cmp r3, #0 */
/* @0x22508c beq 0x2250b8 <_ZN14COggSyncThread9ShowErrorEv+0x40> */
/* @0x225090 ldr r3, [pc, #0x2c] */
/* @0x225094 mov r1, r4 */
/* @0x225098 ldr r3, [pc, r3] */
/* @0x22509c ldr r0, [r3] */
/* @0x2250a0 ldr r3, [r0] */
/* @0x2250a4 ldr r3, [r3, #0xc] */
/* @0x2250a8 blx r3 */
/* @0x2250ac mov r3, #0 */
/* @0x2250b0 strb r3, [r4] */
/* @0x2250b4 strb r3, [r4, #0x800] */
/* @0x2250b8 mov r0, r4 */
/* @0x2250bc pop {r4, lr} */
/* @0x2250c0 b 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x2250c4 andseq r8, r12, r12, ror r6 */

/* ── FUNC 0x2250c8 · COggSyncThread::Quit() · size=68 · insn=17 */
/* @0x2250c8 ldrb r3, [r0, #0x803] */
/* @0x2250cc push {r4, lr} */
/* @0x2250d0 cmp r3, #0 */
/* @0x2250d4 mov r4, r0 */
/* @0x2250d8 popeq {r4, pc} */
/* @0x2250dc bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x2250e0 mov r3, #1 */
/* @0x2250e4 mov r0, r4 */
/* @0x2250e8 strb r3, [r4, #0x802] */
/* @0x2250ec bl 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x2250f0 mov r0, r4 */
/* @0x2250f4 bl 0x2248e8 <_ZN14COggSyncThread17WaitForThreadExitEv> */
/* @0x2250f8 mov r0, r4 */
/* @0x2250fc bl 0x225078 <_ZN14COggSyncThread9ShowErrorEv> */
/* @0x225100 mov r0, r4 */
/* @0x225104 pop {r4, lr} */
/* @0x225108 b 0x224940 <_ZN14COggSyncThread7CleanUpEv> */

/* ── FUNC 0x22510c · COggSyncThread::Tick() · size=124 · insn=31 */
/* @0x22510c push {r3, r4, r5, lr} */
/* @0x225110 mov r4, r0 */
/* @0x225114 bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x225118 ldrb r3, [r4, #0x800] */
/* @0x22511c cmp r3, #0 */
/* @0x225120 beq 0x22516c <_ZN14COggSyncThread4TickEv+0x60> */
/* @0x225124 ldr r3, [pc, #0x54] */
/* @0x225128 ldr r1, [pc, #0x54] */
/* @0x22512c ldr r3, [pc, r3] */
/* @0x225130 ldr r2, [r4, #0x810] */
/* @0x225134 add r1, pc, r1 */
/* @0x225138 ldr r5, [r3] */
/* @0x22513c ldr r3, [r5] */
/* @0x225140 mov r0, r5 */
/* @0x225144 ldr r3, [r3, #0xc] */
/* @0x225148 blx r3 */
/* @0x22514c ldr r3, [r5] */
/* @0x225150 mov r0, r5 */
/* @0x225154 mov r1, r4 */
/* @0x225158 ldr r3, [r3, #0xc] */
/* @0x22515c blx r3 */
/* @0x225160 mov r3, #0 */
/* @0x225164 strb r3, [r4] */
/* @0x225168 strb r3, [r4, #0x800] */
/* @0x22516c ldrb r5, [r4, #0x801] */
/* @0x225170 mov r0, r4 */
/* @0x225174 bl 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x225178 mov r0, r5 */
/* @0x22517c pop {r3, r4, r5, pc} */
/* @0x225180 andseq r8, r12, r8, ror #11 */
/* @0x225184 andseq pc, r2, r8, lsl sp */

/* ── FUNC 0x225188 · COggSyncThread::MixData(void*, int, int, int, float, float) · size=168 · insn=42 */
/* @0x225188 add r3, r3, r3, lsr #31 */
/* @0x22518c ldr r2, [r0, #0x870] */
/* @0x225190 push {r4, r5} */
/* @0x225194 asr r12, r3, #1 */
/* @0x225198 vldr s12, [sp, #12] */
/* @0x22519c add r0, r0, r2, lsl #2 */
/* @0x2251a0 cmp r12, #0 */
/* @0x2251a4 vldr s11, [sp, #16] */
/* @0x2251a8 vsub.f32 s11, s11, s12 */
/* @0x2251ac ldr r0, [r0, #0x85c] */
/* @0x2251b0 ble 0x225228 <_ZN14COggSyncThread7MixDataEPviiiff+0xa0> */
/* @0x2251b4 vmov s9, r12 */
/* @0x2251b8 movw r4, #0x8001 */
/* @0x2251bc sub r1, r1, #2 */
/* @0x2251c0 movt r4, #0xffff */
/* @0x2251c4 mov r3, #0 */
/* @0x2251c8 movw r5, #0x7fff */
/* @0x2251cc vcvt.f32.s32 s10, s9 */
/* @0x2251d0 vmov s9, r3 */
/* @0x2251d4 ldrsh r2, [r0] */
/* @0x2251d8 add r3, r3, #1 */
/* @0x2251dc vmov s15, r2 */
/* @0x2251e0 ldrsh r2, [r1, #2]! */
/* @0x2251e4 vcvt.f32.s32 s14, s9 */
/* @0x2251e8 vmov s13, r2 */
/* @0x2251ec vdiv.f32 s14, s14, s10 */
/* @0x2251f0 vmov.f32 s9, s12 */
/* @0x2251f4 vmla.f32 s9, s14, s11 */
/* @0x2251f8 vcvt.f32.s32 s15, s15 */
/* @0x2251fc vcvt.f32.s32 s13, s13 */
/* @0x225200 vmla.f32 s15, s13, s9 */
/* @0x225204 vcvt.s32.f32 s15, s15 */
/* @0x225208 vmov r2, s15 */
/* @0x22520c cmp r2, r4 */
/* @0x225210 movlt r2, r4 */
/* @0x225214 cmp r2, r5 */
/* @0x225218 movge r2, r5 */
/* @0x22521c cmp r3, r12 */
/* @0x225220 strh r2, [r0], #2 */
/* @0x225224 bne 0x2251d0 <_ZN14COggSyncThread7MixDataEPviiiff+0x48> */
/* @0x225228 pop {r4, r5} */
/* @0x22522c bx lr */

/* ── FUNC 0x225230 · anon_225230 · size=2544 · insn=636 */
/* @0x225230 ldr r3, [r0, #0x2a8] */
/* @0x225234 cmp r2, #0 */
/* @0x225238 push {r4, r5, r6, r7, r8, lr} */
/* @0x22523c add r3, r3, #168 */
/* @0x225240 sub sp, sp, #24 */
/* @0x225244 mov r4, #0 */
/* @0x225248 mov r5, r0 */
/* @0x22524c add r7, sp, #20 */
/* @0x225250 mov r8, r1 */
/* @0x225254 str r4, [sp, #0x14] */
/* @0x225258 ldr r6, [r0, r3, lsl #2] */
/* @0x22525c bne 0x22526c <_ZN14COggSyncThread7MixDataEPviiiff+0xe4> */
/* @0x225260 b 0x22534c <_ZN14COggSyncThread7MixDataEPviiiff+0x1c4> */
/* @0x225264 cmp r4, #16384 */
/* @0x225268 bge 0x2252c4 <_ZN14COggSyncThread7MixDataEPviiiff+0x13c> */
/* @0x22526c add r1, r6, r4 */
/* @0x225270 rsb r2, r4, #16384 */
/* @0x225274 mov r0, r5 */
/* @0x225278 mov r3, r7 */
/* @0x22527c bl 0x232ec8 <ov_read> */
/* @0x225280 subs r12, r0, #0 */
/* @0x225284 addgt r4, r4, r12 */
/* @0x225288 bgt 0x225264 <_ZN14COggSyncThread7MixDataEPviiiff+0xdc> */
/* @0x22528c mov r0, r5 */
/* @0x225290 mov r2, #0 */
/* @0x225294 mov r3, #0 */
/* @0x225298 bne 0x225330 <_ZN14COggSyncThread7MixDataEPviiiff+0x1a8> */
/* @0x22529c bl 0x231618 <ov_raw_seek> */
/* @0x2252a0 cmp r0, #0 */
/* @0x2252a4 beq 0x225264 <_ZN14COggSyncThread7MixDataEPviiiff+0xdc> */
/* @0x2252a8 ldr r1, [pc, #0xcc] */
/* @0x2252ac mov r2, r0 */
/* @0x2252b0 mov r0, r8 */
/* @0x2252b4 add r1, pc, r1 */
/* @0x2252b8 bl 0x224fdc <_ZN14COggSyncThread8LogErrorEPKcz> */
/* @0x2252bc cmp r4, #0 */
/* @0x2252c0 beq 0x225314 <_ZN14COggSyncThread7MixDataEPviiiff+0x18c> */
/* @0x2252c4 ldr r12, [r5, #0x298] */
/* @0x2252c8 mov r0, r8 */
/* @0x2252cc ldr r8, [r5, #0x2ec] */
/* @0x2252d0 mov r1, r6 */
/* @0x2252d4 movw lr, #0x1101 */
/* @0x2252d8 movw r2, #0x1103 */
/* @0x2252dc ldr r6, [r12, #0x4] */
/* @0x2252e0 mov r3, r4 */
/* @0x2252e4 ldr r7, [r12, #0x8] */
/* @0x2252e8 str r8, [sp, #0x4] */
/* @0x2252ec cmp r6, #1 */
/* @0x2252f0 ldr r12, [r5, #0x2bc] */
/* @0x2252f4 str r7, [sp] */
/* @0x2252f8 moveq r2, lr */
/* @0x2252fc ldr r12, [r12, #0x4] */
/* @0x225300 str r12, [sp, #0x8] */
/* @0x225304 bl 0x225188 <_ZN14COggSyncThread7MixDataEPviiiff> */
/* @0x225308 ldr r3, [r5, #0x2bc] */
/* @0x22530c ldr r3, [r3, #0x4] */
/* @0x225310 str r3, [r5, #0x2ec] */
/* @0x225314 ldr r3, [r5, #0x2a8] */
/* @0x225318 mov r0, r4 */
/* @0x22531c eor r3, r3, #1 */
/* @0x225320 str r3, [r5, #0x2a8] */
/* @0x225324 add sp, sp, #24 */
/* @0x225328 pop {r4, r5, r6, r7, r8, pc} */
/* @0x22532c beq 0x2252bc <_ZN14COggSyncThread7MixDataEPviiiff+0x134> */
/* @0x225330 ldr r1, [pc, #0x48] */
/* @0x225334 mov r0, r8 */
/* @0x225338 mov r2, r12 */
/* @0x22533c mov r4, #0 */
/* @0x225340 add r1, pc, r1 */
/* @0x225344 bl 0x224fdc <_ZN14COggSyncThread8LogErrorEPKcz> */
/* @0x225348 b 0x225314 <_ZN14COggSyncThread7MixDataEPviiiff+0x18c> */
/* @0x22534c mov r4, r2 */
/* @0x225350 mov r0, r5 */
/* @0x225354 add r1, r6, r4 */
/* @0x225358 rsb r2, r4, #16384 */
/* @0x22535c mov r3, r7 */
/* @0x225360 bl 0x232ec8 <ov_read> */
/* @0x225364 subs r12, r0, #0 */
/* @0x225368 ble 0x22532c <_ZN14COggSyncThread7MixDataEPviiiff+0x1a4> */
/* @0x22536c add r4, r4, r12 */
/* @0x225370 cmp r4, #16384 */
/* @0x225374 blt 0x225350 <_ZN14COggSyncThread7MixDataEPviiiff+0x1c8> */
/* @0x225378 b 0x2252c4 <_ZN14COggSyncThread7MixDataEPviiiff+0x13c> */
/* @0x22537c andseq pc, r2, r12, lsr r11 */
/* @0x225380 mulseq r2, r12, r10 */
/* @0x225384 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x225388 vpush {d8} */
/* @0x22538c subs r9, r1, #0 */
/* @0x225390 sub sp, sp, #12 */
/* @0x225394 mov r8, r2 */
/* @0x225398 str r3, [sp, #0x4] */
/* @0x22539c ble 0x22549c <_ZN14COggSyncThread7MixDataEPviiiff+0x314> */
/* @0x2253a0 mov r11, #0 */
/* @0x2253a4 add r7, r0, #752 */
/* @0x2253a8 mov r6, r0 */
/* @0x2253ac mov r10, #2080 */
/* @0x2253b0 vldr s16, [pc, #240] */
/* @0x2253b4 b 0x2253d8 <_ZN14COggSyncThread7MixDataEPviiiff+0x250> */
/* @0x2253b8 ldr r3, [r6, #0x2c4] */
/* @0x2253bc cmp r3, #3 */
/* @0x2253c0 beq 0x22546c <_ZN14COggSyncThread7MixDataEPviiiff+0x2e4> */
/* @0x2253c4 add r11, r11, #1 */
/* @0x2253c8 add r7, r7, #768 */
/* @0x2253cc cmp r11, r9 */
/* @0x2253d0 add r6, r6, #768 */
/* @0x2253d4 beq 0x22549c <_ZN14COggSyncThread7MixDataEPviiiff+0x314> */
/* @0x2253d8 vldr s15, [r7, #-4] */
/* @0x2253dc vcmpe.f32 s15, s16 */
/* @0x2253e0 ldrd r0, r1, [r8, r10] */
/* @0x2253e4 ldrd r2, r3, [r7] */
/* @0x2253e8 vmrs APSR_nzcv, fpscr */
/* @0x2253ec bpl 0x225404 <_ZN14COggSyncThread7MixDataEPviiiff+0x27c> */
/* @0x2253f0 ldr r4, [r6, #0x2bc] */
/* @0x2253f4 vldr s15, [r4, #4] */
/* @0x2253f8 vcmpe.f32 s15, s16 */
/* @0x2253fc vmrs APSR_nzcv, fpscr */
/* @0x225400 bmi 0x2253c4 <_ZN14COggSyncThread7MixDataEPviiiff+0x23c> */
/* @0x225404 ldrb r4, [r6, #0x2d5] */
/* @0x225408 cmp r4, #0 */
/* @0x22540c beq 0x2253c4 <_ZN14COggSyncThread7MixDataEPviiiff+0x23c> */
/* @0x225410 bl 0x319414 <__aeabi_ldivmod> */
/* @0x225414 mov r0, r6 */
/* @0x225418 mov r5, r3 */
/* @0x22541c ldr r3, [r6, #0x2e0] */
/* @0x225420 mov r4, r2 */
/* @0x225424 add r3, r3, #1 */
/* @0x225428 str r3, [r6, #0x2e0] */
/* @0x22542c bl 0x232cec <ov_pcm_tell> */
/* @0x225430 mov r2, r4 */
/* @0x225434 mov r3, r5 */
/* @0x225438 cmp r5, r1 */
/* @0x22543c cmpeq r4, r0 */
/* @0x225440 mov r0, r6 */
/* @0x225444 beq 0x22544c <_ZN14COggSyncThread7MixDataEPviiiff+0x2c4> */
/* @0x225448 bl 0x2326f4 <ov_pcm_seek> */
/* @0x22544c mov r0, r6 */
/* @0x225450 mov r1, r8 */
/* @0x225454 ldr r2, [sp, #0x4] */
/* @0x225458 bl 0x225230 <_ZN14COggSyncThread7MixDataEPviiiff+0xa8> */
/* @0x22545c cmp r0, #0 */
/* @0x225460 movle r3, #3 */
/* @0x225464 strle r3, [r6, #0x2c4] */
/* @0x225468 bgt 0x2253b8 <_ZN14COggSyncThread7MixDataEPviiiff+0x230> */
/* @0x22546c mov r0, r6 */
/* @0x225470 bl 0x230ec4 <ov_clear> */
/* @0x225474 mov r3, #0 */
/* @0x225478 mov r0, r8 */
/* @0x22547c str r3, [r6, #0x2c4] */
/* @0x225480 str r3, [r6, #0x2e0] */
/* @0x225484 bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x225488 mov r3, #0 */
/* @0x22548c mov r0, r8 */
/* @0x225490 strb r3, [r6, #0x2d5] */
/* @0x225494 bl 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x225498 b 0x2253c4 <_ZN14COggSyncThread7MixDataEPviiiff+0x23c> */
/* @0x22549c add sp, sp, #12 */
/* @0x2254a0 vpop {d8} */
/* @0x2254a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2254a8 stclo p7, c13, [r3], #-40 */
/* @0x2254ac andeq r0, r0, r0 */
/* @0x2254b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2254b4 vpush {d8, d9} */
/* @0x2254b8 sub sp, sp, #76 */
/* @0x2254bc vldr d8, [pc, #476] */
/* @0x2254c0 ldr r5, [pc, #0x1e8] */
/* @0x2254c4 mvn r4, #0 */
/* @0x2254c8 ldr r12, [pc, #0x1e4] */
/* @0x2254cc vldr s18, [pc, #468] */
/* @0x2254d0 ldr r8, [r0, #0xc] */
/* @0x2254d4 ldr r5, [pc, r5] */
/* @0x2254d8 add r12, pc, r12 */
/* @0x2254dc str r4, [sp, #0x14] */
/* @0x2254e0 str r12, [sp, #0x28] */
/* @0x2254e4 mov r4, #0 */
/* @0x2254e8 ldr r12, [pc, #0x1c8] */
/* @0x2254ec mov r10, r4 */
/* @0x2254f0 vldr s19, [pc, #436] */
/* @0x2254f4 add r12, pc, r12 */
/* @0x2254f8 str r12, [sp, #0x2c] */
/* @0x2254fc add r12, sp, #64 */
/* @0x225500 str r12, [sp, #0x20] */
/* @0x225504 mvn r12, #0 */
/* @0x225508 str r12, [sp, #0x24] */
/* @0x22550c bl 0x215148 <Timing_Time> */
/* @0x225510 ldrb r3, [r5] */
/* @0x225514 uxtb r3, r3 */
/* @0x225518 strb r3, [r8, #0x84d] */
/* @0x22551c ldrb r11, [r8, #0x84d] */
/* @0x225520 ands r11, r11, #255 */
/* @0x225524 strd r0, r1, [sp, #8] */
/* @0x225528 bne 0x225988 <_ZN14COggSyncThread7MixDataEPviiiff+0x800> */
/* @0x22552c mov r0, r8 */
/* @0x225530 bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x225534 ldrb r12, [r8, #0x84f] */
/* @0x225538 ldr r3, [r8, #0x808] */
/* @0x22553c ldrb r7, [r8, #0x850] */
/* @0x225540 str r12, [sp, #0x10] */
/* @0x225544 cmp r3, #0 */
/* @0x225548 ldrb r12, [r8, #0x851] */
/* @0x22554c movgt r1, r11 */
/* @0x225550 strb r11, [r8, #0x850] */
/* @0x225554 strb r11, [r8, #0x84f] */
/* @0x225558 str r12, [sp, #0x18] */
/* @0x22555c ldrb r12, [r8, #0x852] */
/* @0x225560 strb r11, [r8, #0x851] */
/* @0x225564 ldrb r6, [r8, #0x802] */
/* @0x225568 str r12, [sp, #0x1c] */
/* @0x22556c strb r11, [r8, #0x852] */
/* @0x225570 ldrb r9, [r8, #0x801] */
/* @0x225574 movgt r2, r1 */
/* @0x225578 ble 0x2255c0 <_ZN14COggSyncThread7MixDataEPviiiff+0x438> */
/* @0x22557c ldr r3, [r8, #0x804] */
/* @0x225580 ldr r0, [r8, #0x82c] */
/* @0x225584 add r3, r3, r1 */
/* @0x225588 add r1, r1, #768 */
/* @0x22558c ldrb r12, [r3, #0x2d6] */
/* @0x225590 strb r12, [r0, r2, lsl #3] */
/* @0x225594 vldr s15, [r3, #744] */
/* @0x225598 vmul.f32 s15, s15, s18 */
/* @0x22559c strb r10, [r3, #0x2d6] */
/* @0x2255a0 ldr r12, [r8, #0x808] */
/* @0x2255a4 add r2, r2, #1 */
/* @0x2255a8 ldr r0, [r3, #0x2d8] */
/* @0x2255ac cmp r12, r2 */
/* @0x2255b0 str r0, [r3, #0x2bc] */
/* @0x2255b4 vcvt.s32.f32 s15, s15 */
/* @0x2255b8 vstr s15, [r3, #740] */
/* @0x2255bc bgt 0x22557c <_ZN14COggSyncThread7MixDataEPviiiff+0x3f4> */
/* @0x2255c0 mov r0, r8 */
/* @0x2255c4 bl 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x2255c8 cmp r9, #0 */
/* @0x2255cc beq 0x2259c4 <_ZN14COggSyncThread7MixDataEPviiiff+0x83c> */
/* @0x2255d0 ldr r0, [r8, #0x86c] */
/* @0x2255d4 bl 0xb6b14 <alSourceStop@plt> */
/* @0x2255d8 add r2, sp, #64 */
/* @0x2255dc ldr r0, [r8, #0x86c] */
/* @0x2255e0 movw r1, #0x1015 */
/* @0x2255e4 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x2255e8 ldr r3, [sp, #0x40] */
/* @0x2255ec cmp r3, #0 */
/* @0x2255f0 sub r3, r3, #1 */
/* @0x2255f4 addne r4, sp, #68 */
/* @0x2255f8 str r3, [sp, #0x40] */
/* @0x2255fc beq 0x225624 <_ZN14COggSyncThread7MixDataEPviiiff+0x49c> */
/* @0x225600 ldr r0, [r8, #0x86c] */
/* @0x225604 mov r1, #1 */
/* @0x225608 mov r2, r4 */
/* @0x22560c bl 0xb6b08 <alSourceUnqueueBuffers@plt> */
/* @0x225610 ldr r3, [sp, #0x40] */
/* @0x225614 cmp r3, #0 */
/* @0x225618 sub r3, r3, #1 */
/* @0x22561c str r3, [sp, #0x40] */
/* @0x225620 bne 0x225600 <_ZN14COggSyncThread7MixDataEPviiiff+0x478> */
/* @0x225624 mov r0, r8 */
/* @0x225628 bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x22562c ldr r2, [r8, #0x808] */
/* @0x225630 cmp r2, #0 */
/* @0x225634 movgt r5, #0 */
/* @0x225638 movgt r6, r5 */
/* @0x22563c movgt r7, r5 */
/* @0x225640 ble 0x225680 <_ZN14COggSyncThread7MixDataEPviiiff+0x4f8> */
/* @0x225644 ldr r4, [r8, #0x804] */
/* @0x225648 add r6, r6, #1 */
/* @0x22564c add r4, r4, r5 */
/* @0x225650 add r5, r5, #768 */
/* @0x225654 ldr r3, [r4, #0x2c4] */
/* @0x225658 mov r0, r4 */
/* @0x22565c cmp r3, #0 */
/* @0x225660 beq 0x225678 <_ZN14COggSyncThread7MixDataEPviiiff+0x4f0> */
/* @0x225664 bl 0x230ec4 <ov_clear> */
/* @0x225668 ldr r2, [r8, #0x808] */
/* @0x22566c str r7, [r4, #0x2c4] */
/* @0x225670 str r7, [r4, #0x2e0] */
/* @0x225674 strb r7, [r4, #0x2d5] */
/* @0x225678 cmp r6, r2 */
/* @0x22567c blt 0x225644 <_ZN14COggSyncThread7MixDataEPviiiff+0x4bc> */
/* @0x225680 mov r0, r8 */
/* @0x225684 bl 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x225688 mov r0, #0 */
/* @0x22568c strb r0, [r8, #0x84c] */
/* @0x225690 add sp, sp, #76 */
/* @0x225694 vpop {d8, d9} */
/* @0x225698 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22569c nop */
/* @0x2256a0 rscsle r10, r1, #252, #18 */
/* @0x2256a4 svclo #0x50624d */
/* @0x2256a8 ldrbtmi r0, [r10], #-0 */
/* @0x2256ac stclo p7, c13, [r3], #-40 */
/* @0x2256b0 andseq r11, r12, r4, lsr #31 */
/* @0x2256b4 ldrsheq pc, [r2], -r4 */
/* @0x2256b8 mulseq r2, r12, r9 */
/* @0x2256bc ldr r5, [sp, #0x30] */
/* @0x2256c0 ldrb r3, [r8, #0x853] */
/* @0x2256c4 cmp r3, #0 */
/* @0x2256c8 beq 0x2256d8 <_ZN14COggSyncThread7MixDataEPviiiff+0x550> */
/* @0x2256cc ldr r0, [r8, #0x804] */
/* @0x2256d0 mvn r1, #0 */
/* @0x2256d4 bl 0x23138c <ov_pcm_total> */
/* @0x2256d8 ldr r1, [r8, #0x804] */
/* @0x2256dc movw r12, #0x1101 */
/* @0x2256e0 movw lr, #0x1103 */
/* @0x2256e4 ldr r2, [r8, #0x85c] */
/* @0x2256e8 ldr r0, [r8, #0x864] */
/* @0x2256ec mov r3, #16384 */
/* @0x2256f0 ldr r1, [r1, #0x298] */
/* @0x2256f4 mov r11, #2080 */
/* @0x2256f8 ldr r6, [r1, #0x4] */
/* @0x2256fc ldr r1, [r1, #0x8] */
/* @0x225700 cmp r6, #1 */
/* @0x225704 moveq lr, r12 */
/* @0x225708 str r1, [sp, #0x14] */
/* @0x22570c str r1, [sp] */
/* @0x225710 mov r1, lr */
/* @0x225714 str lr, [sp, #0x24] */
/* @0x225718 bl 0xb6afc <alBufferData@plt> */
/* @0x22571c ldr r9, [r8, #0x804] */
/* @0x225720 mov r0, #16384 */
/* @0x225724 ldr r3, [r9, #0x298] */
/* @0x225728 ldr r1, [r3, #0x4] */
/* @0x22572c lsl r1, r1, #1 */
/* @0x225730 bl 0x318d10 <__divsi3> */
/* @0x225734 ldrd r6, r7, [r8, r11] */
/* @0x225738 movw r12, #0x818 */
/* @0x22573c mov r3, #1 */
/* @0x225740 mov r1, r4 */
/* @0x225744 str r3, [r8, #0x870] */
/* @0x225748 mov r2, r8 */
/* @0x22574c ldrb r3, [r8, #0x853] */
/* @0x225750 adds r6, r6, r0 */
/* @0x225754 adc r7, r7, r0, asr #31 */
/* @0x225758 mov r0, r9 */
/* @0x22575c strd r6, r7, [r8, r11] */
/* @0x225760 strd r6, r7, [r8, r12] */
/* @0x225764 bl 0x225384 <_ZN14COggSyncThread7MixDataEPviiiff+0x1fc> */
/* @0x225768 ldr r12, [sp, #0x14] */
/* @0x22576c ldr r2, [r8, #0x860] */
/* @0x225770 mov r3, #16384 */
/* @0x225774 ldr r0, [r8, #0x868] */
/* @0x225778 ldr r1, [sp, #0x24] */
/* @0x22577c str r12, [sp] */
/* @0x225780 bl 0xb6afc <alBufferData@plt> */
/* @0x225784 ldr r3, [r8, #0x804] */
/* @0x225788 mov r0, #16384 */
/* @0x22578c ldr r3, [r3, #0x298] */
/* @0x225790 ldr r1, [r3, #0x4] */
/* @0x225794 lsl r1, r1, #1 */
/* @0x225798 bl 0x318d10 <__divsi3> */
/* @0x22579c ldrd r6, r7, [r8, r11] */
/* @0x2257a0 add r2, r8, #2144 */
/* @0x2257a4 mov r1, #2 */
/* @0x2257a8 add r2, r2, #4 */
/* @0x2257ac adds r6, r6, r0 */
/* @0x2257b0 adc r7, r7, r0, asr #31 */
/* @0x2257b4 ldr r0, [r8, #0x86c] */
/* @0x2257b8 strd r6, r7, [r8, r11] */
/* @0x2257bc bl 0xb6b8c <alSourceQueueBuffers@plt> */
/* @0x2257c0 ldrd r2, r3, [r8, r11] */
/* @0x2257c4 movw r1, #0x818 */
/* @0x2257c8 ldr r0, [r8, #0x86c] */
/* @0x2257cc strd r2, r3, [r8, r1] */
/* @0x2257d0 bl 0xb6a84 <alSourcePlay@plt> */
/* @0x2257d4 ldr r0, [r8, #0x86c] */
/* @0x2257d8 movw r1, #0x100a */
/* @0x2257dc mov r2, #1065353216 */
/* @0x2257e0 bl 0xb6a78 <alSourcef@plt> */
/* @0x2257e4 str r10, [r8, #0x870] */
/* @0x2257e8 ldr r12, [sp, #0x10] */
/* @0x2257ec cmp r12, #0 */
/* @0x2257f0 bne 0x225b3c <_ZN14COggSyncThread7MixDataEPviiiff+0x9b4> */
/* @0x2257f4 cmp r4, #0 */
/* @0x2257f8 ldr r3, [sp, #0x3c] */
/* @0x2257fc beq 0x225810 <_ZN14COggSyncThread7MixDataEPviiiff+0x688> */
/* @0x225800 movw r2, #0x1014 */
/* @0x225804 cmp r3, r2 */
/* @0x225808 moveq r11, #1 */
/* @0x22580c beq 0x225820 <_ZN14COggSyncThread7MixDataEPviiiff+0x698> */
/* @0x225810 movw r2, #0x1012 */
/* @0x225814 cmp r3, r2 */
/* @0x225818 bne 0x225948 <_ZN14COggSyncThread7MixDataEPviiiff+0x7c0> */
/* @0x22581c mov r11, #0 */
/* @0x225820 str r10, [sp, #0x40] */
/* @0x225824 movw r1, #0x1016 */
/* @0x225828 ldr r0, [r8, #0x86c] */
/* @0x22582c add r2, sp, #64 */
/* @0x225830 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x225834 ldr r3, [sp, #0x40] */
/* @0x225838 cmp r3, #0 */
/* @0x22583c sub r3, r3, #1 */
/* @0x225840 str r3, [sp, #0x40] */
/* @0x225844 ble 0x22592c <_ZN14COggSyncThread7MixDataEPviiiff+0x7a4> */
/* @0x225848 str r11, [sp, #0x30] */
/* @0x22584c add r6, sp, #68 */
/* @0x225850 ldr r11, [sp, #0x14] */
/* @0x225854 movw r9, #0x818 */
/* @0x225858 mov r7, #2080 */
/* @0x22585c str r4, [sp, #0x10] */
/* @0x225860 str r5, [sp, #0x34] */
/* @0x225864 mov r2, r6 */
/* @0x225868 ldr r0, [r8, #0x86c] */
/* @0x22586c mov r1, #1 */
/* @0x225870 bl 0xb6b08 <alSourceUnqueueBuffers@plt> */
/* @0x225874 ldr r3, [r8, #0x804] */
/* @0x225878 mov r0, #16384 */
/* @0x22587c ldr r3, [r3, #0x298] */
/* @0x225880 ldr r1, [r3, #0x4] */
/* @0x225884 lsl r1, r1, #1 */
/* @0x225888 bl 0x318d10 <__divsi3> */
/* @0x22588c ldr r12, [r8, #0x870] */
/* @0x225890 ldrd r4, r5, [r8, r7] */
/* @0x225894 mov r1, #0 */
/* @0x225898 mov r2, #16384 */
/* @0x22589c add r3, r8, r12, lsl #2 */
/* @0x2258a0 adds r4, r4, r0 */
/* @0x2258a4 adc r5, r5, r0, asr #31 */
/* @0x2258a8 ldr r0, [r3, #0x85c] */
/* @0x2258ac strd r4, r5, [r8, r9] */
/* @0x2258b0 bl 0xb65b0 <memset@plt> */
/* @0x2258b4 ldr r0, [r8, #0x804] */
/* @0x2258b8 ldr r1, [sp, #0x10] */
/* @0x2258bc mov r2, r8 */
/* @0x2258c0 ldrb r3, [r8, #0x853] */
/* @0x2258c4 bl 0x225384 <_ZN14COggSyncThread7MixDataEPviiiff+0x1fc> */
/* @0x2258c8 ldr r2, [r8, #0x870] */
/* @0x2258cc ldr r0, [sp, #0x44] */
/* @0x2258d0 mov r3, #16384 */
/* @0x2258d4 ldr r1, [sp, #0x24] */
/* @0x2258d8 add r2, r8, r2, lsl #2 */
/* @0x2258dc ldr r2, [r2, #0x85c] */
/* @0x2258e0 str r11, [sp] */
/* @0x2258e4 bl 0xb6afc <alBufferData@plt> */
/* @0x2258e8 ldrd r2, r3, [r8, r9] */
/* @0x2258ec ldr r12, [r8, #0x870] */
/* @0x2258f0 mov r1, #1 */
/* @0x2258f4 ldr r0, [r8, #0x86c] */
/* @0x2258f8 eor r12, r12, r1 */
/* @0x2258fc strd r2, r3, [r8, r7] */
/* @0x225900 str r12, [r8, #0x870] */
/* @0x225904 mov r2, r6 */
/* @0x225908 bl 0xb6b8c <alSourceQueueBuffers@plt> */
/* @0x22590c ldr r3, [sp, #0x40] */
/* @0x225910 cmp r3, #0 */
/* @0x225914 sub r3, r3, #1 */
/* @0x225918 str r3, [sp, #0x40] */
/* @0x22591c bgt 0x225864 <_ZN14COggSyncThread7MixDataEPviiiff+0x6dc> */
/* @0x225920 ldr r4, [sp, #0x10] */
/* @0x225924 ldr r11, [sp, #0x30] */
/* @0x225928 ldr r5, [sp, #0x34] */
/* @0x22592c cmp r11, #0 */
/* @0x225930 beq 0x225948 <_ZN14COggSyncThread7MixDataEPviiiff+0x7c0> */
/* @0x225934 ldr r0, [r8, #0x86c] */
/* @0x225938 bl 0xb6a84 <alSourcePlay@plt> */
/* @0x22593c ldr r3, [r8, #0x828] */
/* @0x225940 add r3, r3, #1 */
/* @0x225944 str r3, [r8, #0x828] */
/* @0x225948 ldr r12, [sp, #0x18] */
/* @0x22594c cmp r12, #0 */
/* @0x225950 beq 0x225964 <_ZN14COggSyncThread7MixDataEPviiiff+0x7dc> */
/* @0x225954 ldr r2, [sp, #0x3c] */
/* @0x225958 movw r3, #0x1012 */
/* @0x22595c cmp r2, r3 */
/* @0x225960 beq 0x225c10 <_ZN14COggSyncThread7MixDataEPviiiff+0xa88> */
/* @0x225964 ldr r12, [sp, #0x1c] */
/* @0x225968 cmp r12, #0 */
/* @0x22596c beq 0x225988 <_ZN14COggSyncThread7MixDataEPviiiff+0x800> */
/* @0x225970 ldr r2, [sp, #0x3c] */
/* @0x225974 movw r3, #0x1013 */
/* @0x225978 cmp r2, r3 */
/* @0x22597c bne 0x225988 <_ZN14COggSyncThread7MixDataEPviiiff+0x800> */
/* @0x225980 ldr r0, [r8, #0x86c] */
/* @0x225984 bl 0xb6a84 <alSourcePlay@plt> */
/* @0x225988 bl 0x215148 <Timing_Time> */
/* @0x22598c ldrd r2, r3, [sp, #8] */
/* @0x225990 subs r0, r0, r2 */
/* @0x225994 sbc r1, r1, r3 */
/* @0x225998 bl 0x319164 <__floatdidf> */
/* @0x22599c vmov d6, r0, r1 */
/* @0x2259a0 vmul.f64 d7, d6, d8 */
/* @0x2259a4 vcvt.s32.f64 s13, d7 */
/* @0x2259a8 vmov r0, s13 */
/* @0x2259ac rsb r0, r0, #16 */
/* @0x2259b0 bic r0, r0, r0, asr #31 */
/* @0x2259b4 cmp r0, #0 */
/* @0x2259b8 beq 0x22550c <_ZN14COggSyncThread7MixDataEPviiiff+0x384> */
/* @0x2259bc bl 0x27e114 <_ZN7CThread5SleepEi> */
/* @0x2259c0 b 0x22550c <_ZN14COggSyncThread7MixDataEPviiiff+0x384> */
/* @0x2259c4 cmp r6, #0 */
/* @0x2259c8 bne 0x2255d0 <_ZN14COggSyncThread7MixDataEPviiiff+0x448> */
/* @0x2259cc ldr r0, [r8, #0x86c] */
/* @0x2259d0 movw r1, #0x1010 */
/* @0x2259d4 add r2, sp, #60 */
/* @0x2259d8 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x2259dc cmp r7, #0 */
/* @0x2259e0 beq 0x2257e8 <_ZN14COggSyncThread7MixDataEPviiiff+0x660> */
/* @0x2259e4 ldr r2, [sp, #0x3c] */
/* @0x2259e8 movw r3, #0x1012 */
/* @0x2259ec cmp r2, r3 */
/* @0x2259f0 beq 0x225c00 <_ZN14COggSyncThread7MixDataEPviiiff+0xa78> */
/* @0x2259f4 mov r1, r6 */
/* @0x2259f8 mov r2, #16384 */
/* @0x2259fc ldr r0, [r8, #0x85c] */
/* @0x225a00 bl 0xb65b0 <memset@plt> */
/* @0x225a04 mov r1, r6 */
/* @0x225a08 mov r2, #16384 */
/* @0x225a0c ldr r0, [r8, #0x860] */
/* @0x225a10 bl 0xb65b0 <memset@plt> */
/* @0x225a14 ldr r12, [r8, #0x808] */
/* @0x225a18 ldr r6, [r8, #0x804] */
/* @0x225a1c mov r1, #2080 */
/* @0x225a20 cmp r12, #0 */
/* @0x225a24 mov r2, #0 */
/* @0x225a28 mov r3, #0 */
/* @0x225a2c strd r2, r3, [r8, r1] */
/* @0x225a30 movgt r3, #1 */
/* @0x225a34 movgt r2, r6 */
/* @0x225a38 ble 0x225a5c <_ZN14COggSyncThread7MixDataEPviiiff+0x8d4> */
/* @0x225a3c ldr r1, [r2, #0x2d8] */
/* @0x225a40 add r2, r2, #768 */
/* @0x225a44 cmp r1, #0 */
/* @0x225a48 strne r1, [r2, #-0x44] */
/* @0x225a4c movne r4, r3 */
/* @0x225a50 cmp r12, r3 */
/* @0x225a54 add r3, r3, #1 */
/* @0x225a58 bgt 0x225a3c <_ZN14COggSyncThread7MixDataEPviiiff+0x8b4> */
/* @0x225a5c cmp r4, #0 */
/* @0x225a60 str r10, [r8, #0x870] */
/* @0x225a64 beq 0x2256c0 <_ZN14COggSyncThread7MixDataEPviiiff+0x538> */
/* @0x225a68 add r7, r6, #748 */
/* @0x225a6c mov r9, #0 */
/* @0x225a70 str r5, [sp, #0x30] */
/* @0x225a74 b 0x225af8 <_ZN14COggSyncThread7MixDataEPviiiff+0x970> */
/* @0x225a78 mov r0, r6 */
/* @0x225a7c bl 0x223cb4 <_ZN10COggThread8LogErrorEPKcz+0x9c> */
/* @0x225a80 cmp r0, #0 */
/* @0x225a84 beq 0x225bd4 <_ZN14COggSyncThread7MixDataEPviiiff+0xa4c> */
/* @0x225a88 mov r1, #2 */
/* @0x225a8c mov r0, r6 */
/* @0x225a90 str r1, [r6, #0x2c4] */
/* @0x225a94 mvn r1, #0 */
/* @0x225a98 bl 0x232e28 <ov_info> */
/* @0x225a9c str r10, [r6, #0x2e0] */
/* @0x225aa0 mvn r1, #0 */
/* @0x225aa4 str r0, [r6, #0x298] */
/* @0x225aa8 mov r0, r6 */
/* @0x225aac bl 0x23138c <ov_pcm_total> */
/* @0x225ab0 strd r0, r1, [r7, #4] */
/* @0x225ab4 vldr s15, [r11, #4] */
/* @0x225ab8 vcmpe.f32 s15, s19 */
/* @0x225abc vmrs APSR_nzcv, fpscr */
/* @0x225ac0 strmi r10, [r6, #0x2a8] */
/* @0x225ac4 bmi 0x225ae4 <_ZN14COggSyncThread7MixDataEPviiiff+0x95c> */
/* @0x225ac8 str r10, [r6, #0x2a8] */
/* @0x225acc mov r0, r6 */
/* @0x225ad0 mov r1, r8 */
/* @0x225ad4 mov r2, #1 */
/* @0x225ad8 bl 0x225230 <_ZN14COggSyncThread7MixDataEPviiiff+0xa8> */
/* @0x225adc cmp r0, #0 */
/* @0x225ae0 ble 0x225ba0 <_ZN14COggSyncThread7MixDataEPviiiff+0xa18> */
/* @0x225ae4 add r9, r9, #1 */
/* @0x225ae8 add r6, r6, #768 */
/* @0x225aec cmp r9, r4 */
/* @0x225af0 add r7, r7, #768 */
/* @0x225af4 beq 0x2256bc <_ZN14COggSyncThread7MixDataEPviiiff+0x534> */
/* @0x225af8 ldr r11, [r6, #0x2bc] */
/* @0x225afc ldr r3, [r11, #0x4] */
/* @0x225b00 str r3, [r7] */
/* @0x225b04 ldrb r1, [r11, #0x24] */
/* @0x225b08 cmp r1, #0 */
/* @0x225b0c beq 0x225a78 <_ZN14COggSyncThread7MixDataEPviiiff+0x8f0> */
/* @0x225b10 ldr r5, [r11, #0x30] */
/* @0x225b14 mov r2, #0 */
/* @0x225b18 mov r1, r6 */
/* @0x225b1c mov r0, r5 */
/* @0x225b20 bl 0x223d28 <_ZN10COggThread8LogErrorEPKcz+0x110> */
/* @0x225b24 subs r2, r0, #0 */
/* @0x225b28 bne 0x225a88 <_ZN14COggSyncThread7MixDataEPviiiff+0x900> */
/* @0x225b2c mov r0, r5 */
/* @0x225b30 mov r1, r6 */
/* @0x225b34 bl 0x223e10 <_ZN10COggThread8LogErrorEPKcz+0x1f8> */
/* @0x225b38 b 0x225a80 <_ZN14COggSyncThread7MixDataEPviiiff+0x8f8> */
/* @0x225b3c ldr r0, [r8, #0x86c] */
/* @0x225b40 bl 0xb6b14 <alSourceStop@plt> */
/* @0x225b44 str r10, [sp, #0x40] */
/* @0x225b48 movw r1, #0x1015 */
/* @0x225b4c ldr r0, [r8, #0x86c] */
/* @0x225b50 add r2, sp, #64 */
/* @0x225b54 bl 0xb6a9c <alGetSourcei@plt> */
/* @0x225b58 ldr r3, [sp, #0x40] */
/* @0x225b5c cmp r3, #0 */
/* @0x225b60 sub r3, r3, #1 */
/* @0x225b64 addne r6, sp, #68 */
/* @0x225b68 str r3, [sp, #0x40] */
/* @0x225b6c beq 0x225b94 <_ZN14COggSyncThread7MixDataEPviiiff+0xa0c> */
/* @0x225b70 ldr r0, [r8, #0x86c] */
/* @0x225b74 mov r1, #1 */
/* @0x225b78 mov r2, r6 */
/* @0x225b7c bl 0xb6b08 <alSourceUnqueueBuffers@plt> */
/* @0x225b80 ldr r3, [sp, #0x40] */
/* @0x225b84 cmp r3, #0 */
/* @0x225b88 sub r3, r3, #1 */
/* @0x225b8c str r3, [sp, #0x40] */
/* @0x225b90 bne 0x225b70 <_ZN14COggSyncThread7MixDataEPviiiff+0x9e8> */
/* @0x225b94 ldr r3, [sp, #0x3c] */
/* @0x225b98 mov r4, #0 */
/* @0x225b9c b 0x225810 <_ZN14COggSyncThread7MixDataEPviiiff+0x688> */
/* @0x225ba0 ldr r3, [r6, #0x2c4] */
/* @0x225ba4 cmp r3, #0 */
/* @0x225ba8 beq 0x225bbc <_ZN14COggSyncThread7MixDataEPviiiff+0xa34> */
/* @0x225bac mov r0, r6 */
/* @0x225bb0 bl 0x230ec4 <ov_clear> */
/* @0x225bb4 str r10, [r6, #0x2c4] */
/* @0x225bb8 str r10, [r6, #0x2e0] */
/* @0x225bbc mov r0, r8 */
/* @0x225bc0 bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x225bc4 strb r10, [r6, #0x2d5] */
/* @0x225bc8 mov r0, r8 */
/* @0x225bcc bl 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x225bd0 b 0x225ae4 <_ZN14COggSyncThread7MixDataEPviiiff+0x95c> */
/* @0x225bd4 mov r0, r8 */
/* @0x225bd8 ldr r1, [sp, #0x28] */
/* @0x225bdc ldr r5, [sp, #0x30] */
/* @0x225be0 bl 0x224fdc <_ZN14COggSyncThread8LogErrorEPKcz> */
/* @0x225be4 mov r0, r8 */
/* @0x225be8 bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x225bec mov r3, #1 */
/* @0x225bf0 mov r0, r8 */
/* @0x225bf4 strb r3, [r8, #0x801] */
/* @0x225bf8 bl 0x224c2c <_ZN14COggSyncThread6UnlockEv> */
/* @0x225bfc b 0x22550c <_ZN14COggSyncThread7MixDataEPviiiff+0x384> */
/* @0x225c00 mov r0, r8 */
/* @0x225c04 ldr r1, [sp, #0x2c] */
/* @0x225c08 bl 0x224fdc <_ZN14COggSyncThread8LogErrorEPKcz> */
/* @0x225c0c b 0x22550c <_ZN14COggSyncThread7MixDataEPviiiff+0x384> */
/* @0x225c10 ldr r0, [r8, #0x86c] */
/* @0x225c14 bl 0xb6ab4 <alSourcePause@plt> */
/* @0x225c18 b 0x225964 <_ZN14COggSyncThread7MixDataEPviiiff+0x7dc> */
/* @0x225c1c nop */

/* ── FUNC 0x225c20 · COggSyncThread::StartSyncGroup() · size=44 · insn=11 */
/* @0x225c20 push {r4, lr} */
/* @0x225c24 mov r4, r0 */
/* @0x225c28 bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x225c2c ldr r3, [r4, #0x80c] */
/* @0x225c30 mov r0, r4 */
/* @0x225c34 cmp r3, #0 */
/* @0x225c38 movgt r3, #1 */
/* @0x225c3c strbgt r3, [r4, #0x850] */
/* @0x225c40 strbgt r3, [r4, #0x854] */
/* @0x225c44 pop {r4, lr} */
/* @0x225c48 b 0x224c2c <_ZN14COggSyncThread6UnlockEv> */

/* ── FUNC 0x225c4c · COggSyncThread::StopSyncGroup() · size=40 · insn=10 */
/* @0x225c4c push {r4, lr} */
/* @0x225c50 mov r4, r0 */
/* @0x225c54 bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x225c58 mov r2, #1 */
/* @0x225c5c mov r3, #0 */
/* @0x225c60 strb r2, [r4, #0x84f] */
/* @0x225c64 mov r0, r4 */
/* @0x225c68 strb r3, [r4, #0x854] */
/* @0x225c6c pop {r4, lr} */
/* @0x225c70 b 0x224c2c <_ZN14COggSyncThread6UnlockEv> */

/* ── FUNC 0x225c74 · COggSyncThread::PauseSyncGroup() · size=32 · insn=8 */
/* @0x225c74 push {r4, lr} */
/* @0x225c78 mov r4, r0 */
/* @0x225c7c bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x225c80 mov r3, #1 */
/* @0x225c84 mov r0, r4 */
/* @0x225c88 strb r3, [r4, #0x851] */
/* @0x225c8c pop {r4, lr} */
/* @0x225c90 b 0x224c2c <_ZN14COggSyncThread6UnlockEv> */

/* ── FUNC 0x225c94 · COggSyncThread::ResumeSyncGroup() · size=32 · insn=8 */
/* @0x225c94 push {r4, lr} */
/* @0x225c98 mov r4, r0 */
/* @0x225c9c bl 0x224c24 <_ZN14COggSyncThread4LockEv> */
/* @0x225ca0 mov r3, #1 */
/* @0x225ca4 mov r0, r4 */
/* @0x225ca8 strb r3, [r4, #0x852] */
/* @0x225cac pop {r4, lr} */
/* @0x225cb0 b 0x224c2c <_ZN14COggSyncThread6UnlockEv> */

/* ── FUNC 0x225cb4 · COggAudio::COggAudio() · size=100 · insn=25 */
/* @0x225cb4 push {r4, r5, r6, lr} */
/* @0x225cb8 sub sp, sp, #8 */
/* @0x225cbc ldr r2, [pc, #0x50] */
/* @0x225cc0 mov r4, r0 */
/* @0x225cc4 mov r5, #0 */
/* @0x225cc8 mov r6, #8 */
/* @0x225ccc str r5, [r0] */
/* @0x225cd0 mov r1, #32 */
/* @0x225cd4 str r5, [r0, #0x8] */
/* @0x225cd8 movw r3, #0x11b */
/* @0x225cdc str r5, [r4, #0x4] */
/* @0x225ce0 mov r0, r5 */
/* @0x225ce4 str r5, [r4, #0x10] */
/* @0x225ce8 add r2, pc, r2 */
/* @0x225cec str r5, [sp] */
/* @0x225cf0 str r6, [r4, #0xc] */
/* @0x225cf4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x225cf8 str r6, [r4, #0x4] */
/* @0x225cfc str r5, [r4, #0x14] */
/* @0x225d00 str r5, [r4, #0x18] */
/* @0x225d04 str r0, [r4, #0x10] */
/* @0x225d08 mov r0, r4 */
/* @0x225d0c add sp, sp, #8 */
/* @0x225d10 pop {r4, r5, r6, pc} */
/* @0x225d14 andseq r7, r2, r8, lsl #12 */

/* ── FUNC 0x225cb4 · COggAudio::COggAudio() · alias of the symbol above · insn=0 */

/* ── FUNC 0x225d18 · COggAudio::Init(int, int) · size=124 · insn=31 */
/* @0x225d18 push {r3, r4, r5, r6, r7, lr} */
/* @0x225d1c mov r6, r0 */
/* @0x225d20 str r1, [r6, #0x14] */
/* @0x225d24 mov r0, r2 */
/* @0x225d28 mov r4, r1 */
/* @0x225d2c bl 0x318d10 <__divsi3> */
/* @0x225d30 cmp r4, #1015808 */
/* @0x225d34 sub r5, r4, #1 */
/* @0x225d38 mul r0, r4, r0 */
/* @0x225d3c str r0, [r6, #0x18] */
/* @0x225d40 movwls r0, #0x834 */
/* @0x225d44 mulls r0, r0, r4 */
/* @0x225d48 mvnhi r0, #0 */
/* @0x225d4c addls r0, r0, #8 */
/* @0x225d50 bl 0x27d14c <_Znaj> */
/* @0x225d54 cmn r5, #1 */
/* @0x225d58 movw r3, #0x834 */
/* @0x225d5c add r7, r0, #8 */
/* @0x225d60 str r4, [r0, #0x4] */
/* @0x225d64 str r3, [r0] */
/* @0x225d68 movne r4, r7 */
/* @0x225d6c beq 0x225d8c <_ZN9COggAudio4InitEii+0x74> */
/* @0x225d70 mov r0, r4 */
/* @0x225d74 sub r5, r5, #1 */
/* @0x225d78 bl 0x223750 <_ZN10COggThreadC2Ev> */
/* @0x225d7c cmn r5, #1 */
/* @0x225d80 add r4, r4, #2096 */
/* @0x225d84 add r4, r4, #4 */
/* @0x225d88 bne 0x225d70 <_ZN9COggAudio4InitEii+0x58> */
/* @0x225d8c str r7, [r6] */
/* @0x225d90 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x225d94 · COggAudio::Create_SyncThread(bool) · size=408 · insn=102 */
/* @0x225d94 push {r4, r5, r6, r7, lr} */
/* @0x225d98 mov r5, r0 */
/* @0x225d9c sub sp, sp, #12 */
/* @0x225da0 movw r0, #0x878 */
/* @0x225da4 mov r7, r1 */
/* @0x225da8 bl 0x27c524 <_Znwj> */
/* @0x225dac mov r6, r0 */
/* @0x225db0 bl 0x224834 <_ZN14COggSyncThreadC2Ev> */
/* @0x225db4 ldr r4, [r5, #0x8] */
/* @0x225db8 mov r3, #1 */
/* @0x225dbc strb r7, [r6, #0x853] */
/* @0x225dc0 cmp r4, #0 */
/* @0x225dc4 strb r3, [r6, #0x84e] */
/* @0x225dc8 ble 0x225e68 <_ZN9COggAudio17Create_SyncThreadEb+0xd4> */
/* @0x225dcc ldr r1, [r5, #0x4] */
/* @0x225dd0 cmp r1, #0 */
/* @0x225dd4 ldrle r12, [r5, #0x10] */
/* @0x225dd8 movle r3, #0 */
/* @0x225ddc ble 0x225e28 <_ZN9COggAudio17Create_SyncThreadEb+0x94> */
/* @0x225de0 ldr r0, [r5, #0x10] */
/* @0x225de4 ldr r3, [r0] */
/* @0x225de8 cmp r3, #0 */
/* @0x225dec addne r2, r0, #4 */
/* @0x225df0 movne r3, #0 */
/* @0x225df4 bne 0x225e08 <_ZN9COggAudio17Create_SyncThreadEb+0x74> */
/* @0x225df8 b 0x225f20 <_ZN9COggAudio17Create_SyncThreadEb+0x18c> */
/* @0x225dfc ldr lr, [r12] */
/* @0x225e00 cmp lr, #0 */
/* @0x225e04 beq 0x225e28 <_ZN9COggAudio17Create_SyncThreadEb+0x94> */
/* @0x225e08 add r3, r3, #1 */
/* @0x225e0c mov r12, r2 */
/* @0x225e10 cmp r3, r4 */
/* @0x225e14 add r2, r2, #4 */
/* @0x225e18 beq 0x225e70 <_ZN9COggAudio17Create_SyncThreadEb+0xdc> */
/* @0x225e1c cmp r3, r1 */
/* @0x225e20 bne 0x225dfc <_ZN9COggAudio17Create_SyncThreadEb+0x68> */
/* @0x225e24 add r12, r0, r3, lsl #2 */
/* @0x225e28 mov r4, r3 */
/* @0x225e2c str r6, [r12] */
/* @0x225e30 ldr r7, [r5, #0x14] */
/* @0x225e34 ldr r0, [r5, #0x18] */
/* @0x225e38 mov r1, r7 */
/* @0x225e3c bl 0x318d10 <__divsi3> */
/* @0x225e40 mov r12, #1 */
/* @0x225e44 mov r2, r7 */
/* @0x225e48 mov r1, r4 */
/* @0x225e4c str r12, [sp] */
/* @0x225e50 mov r3, r0 */
/* @0x225e54 mov r0, r6 */
/* @0x225e58 bl 0x224a4c <_ZN14COggSyncThread6CreateEiiib> */
/* @0x225e5c mov r0, r4 */
/* @0x225e60 add sp, sp, #12 */
/* @0x225e64 pop {r4, r5, r6, r7, pc} */
/* @0x225e68 ldr r0, [r5, #0x10] */
/* @0x225e6c ldr r1, [r5, #0x4] */
/* @0x225e70 cmp r1, r4 */
/* @0x225e74 beq 0x225e8c <_ZN9COggAudio17Create_SyncThreadEb+0xf8> */
/* @0x225e78 add r0, r0, r4, lsl #2 */
/* @0x225e7c add r3, r4, #1 */
/* @0x225e80 str r6, [r0] */
/* @0x225e84 str r3, [r5, #0x8] */
/* @0x225e88 b 0x225e30 <_ZN9COggAudio17Create_SyncThreadEb+0x9c> */
/* @0x225e8c ldr r7, [r5, #0xc] */
/* @0x225e90 add r7, r4, r7 */
/* @0x225e94 cmp r7, r4 */
/* @0x225e98 beq 0x225e78 <_ZN9COggAudio17Create_SyncThreadEb+0xe4> */
/* @0x225e9c cmp r7, #0 */
/* @0x225ea0 bne 0x225ecc <_ZN9COggAudio17Create_SyncThreadEb+0x138> */
/* @0x225ea4 cmp r0, #0 */
/* @0x225ea8 beq 0x225f00 <_ZN9COggAudio17Create_SyncThreadEb+0x16c> */
/* @0x225eac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x225eb0 mov r4, r7 */
/* @0x225eb4 mov r0, r7 */
/* @0x225eb8 mov r3, #1 */
/* @0x225ebc str r7, [r5, #0x10] */
/* @0x225ec0 str r7, [r5, #0x8] */
/* @0x225ec4 str r7, [r5, #0x4] */
/* @0x225ec8 b 0x225e80 <_ZN9COggAudio17Create_SyncThreadEb+0xec> */
/* @0x225ecc lsls r1, r7, #2 */
/* @0x225ed0 beq 0x225f00 <_ZN9COggAudio17Create_SyncThreadEb+0x16c> */
/* @0x225ed4 ldr r2, [pc, #0x4c] */
/* @0x225ed8 mov r3, #0 */
/* @0x225edc str r3, [sp] */
/* @0x225ee0 movw r3, #0x11b */
/* @0x225ee4 add r2, pc, r2 */
/* @0x225ee8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x225eec ldr r4, [r5, #0x8] */
/* @0x225ef0 add r3, r4, #1 */
/* @0x225ef4 str r0, [r5, #0x10] */
/* @0x225ef8 add r0, r0, r4, lsl #2 */
/* @0x225efc b 0x225ec4 <_ZN9COggAudio17Create_SyncThreadEb+0x130> */
/* @0x225f00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x225f04 mov r3, #0 */
/* @0x225f08 mov r0, r3 */
/* @0x225f0c str r3, [r5, #0x10] */
/* @0x225f10 str r3, [r5, #0x8] */
/* @0x225f14 mov r4, r3 */
/* @0x225f18 mov r3, #1 */
/* @0x225f1c b 0x225ec4 <_ZN9COggAudio17Create_SyncThreadEb+0x130> */
/* @0x225f20 mov r12, r0 */
/* @0x225f24 b 0x225e28 <_ZN9COggAudio17Create_SyncThreadEb+0x94> */
/* @0x225f28 andseq r7, r2, r12, lsl #8 */

/* ── FUNC 0x225f2c · COggAudio::Delete_SyncThread(int) · size=120 · insn=30 */
/* @0x225f2c push {r3, r4, r5, r6, r7, lr} */
/* @0x225f30 mov r4, r0 */
/* @0x225f34 ldr r3, [r0, #0x4] */
/* @0x225f38 mov r5, r1 */
/* @0x225f3c cmp r3, r1 */
/* @0x225f40 pople {r3, r4, r5, r6, r7, pc} */
/* @0x225f44 ldr r3, [r0, #0x10] */
/* @0x225f48 ldr r6, [r3, r1, lsl #2] */
/* @0x225f4c cmp r6, #0 */
/* @0x225f50 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x225f54 mov r0, r6 */
/* @0x225f58 bl 0x2250c8 <_ZN14COggSyncThread4QuitEv> */
/* @0x225f5c ldr r7, [r6, #0x848] */
/* @0x225f60 cmp r7, #0 */
/* @0x225f64 beq 0x225f78 <_ZN9COggAudio17Delete_SyncThreadEi+0x4c> */
/* @0x225f68 mov r0, r7 */
/* @0x225f6c bl 0x27e020 <_ZN5MutexD2Ev> */
/* @0x225f70 mov r0, r7 */
/* @0x225f74 bl 0x27d1d0 <_ZdlPv> */
/* @0x225f78 mov r0, r6 */
/* @0x225f7c bl 0x27d1d0 <_ZdlPv> */
/* @0x225f80 ldr r3, [r4, #0x8] */
/* @0x225f84 ldr r2, [r4, #0x10] */
/* @0x225f88 mov r1, #0 */
/* @0x225f8c cmp r5, r3 */
/* @0x225f90 str r1, [r2, r5, lsl #2] */
/* @0x225f94 addge r5, r5, #1 */
/* @0x225f98 movlt r5, r3 */
/* @0x225f9c str r5, [r4, #0x8] */
/* @0x225fa0 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x225fa4 · COggAudio::Quit() · size=248 · insn=62 */
/* @0x225fa4 ldr r3, [r0] */
/* @0x225fa8 push {r4, r5, r6, r7, r8, lr} */
/* @0x225fac cmp r3, #0 */
/* @0x225fb0 mov r4, r0 */
/* @0x225fb4 beq 0x22605c <_ZN9COggAudio4QuitEv+0xb8> */
/* @0x225fb8 ldr r2, [r0, #0x14] */
/* @0x225fbc cmp r2, #0 */
/* @0x225fc0 ble 0x225ff8 <_ZN9COggAudio4QuitEv+0x54> */
/* @0x225fc4 mov r5, #0 */
/* @0x225fc8 mov r6, r5 */
/* @0x225fcc add r0, r3, r5 */
/* @0x225fd0 add r6, r6, #1 */
/* @0x225fd4 bl 0x223bdc <_ZN10COggThread4QuitEv> */
/* @0x225fd8 ldr r3, [r4, #0x14] */
/* @0x225fdc add r5, r5, #2096 */
/* @0x225fe0 cmp r3, r6 */
/* @0x225fe4 add r5, r5, #4 */
/* @0x225fe8 ldr r3, [r4] */
/* @0x225fec bgt 0x225fcc <_ZN9COggAudio4QuitEv+0x28> */
/* @0x225ff0 cmp r3, #0 */
/* @0x225ff4 beq 0x226050 <_ZN9COggAudio4QuitEv+0xac> */
/* @0x225ff8 ldr r2, [r3, #-0x4] */
/* @0x225ffc movw r7, #0x834 */
/* @0x226000 mla r7, r7, r2, r3 */
/* @0x226004 sub r8, r7, #28 */
/* @0x226008 mov r5, r7 */
/* @0x22600c b 0x226038 <_ZN9COggAudio4QuitEv+0x94> */
/* @0x226010 ldr r6, [r2, #0x14] */
/* @0x226014 cmp r6, #0 */
/* @0x226018 mov r0, r6 */
/* @0x22601c beq 0x226030 <_ZN9COggAudio4QuitEv+0x8c> */
/* @0x226020 bl 0x27e020 <_ZN5MutexD2Ev> */
/* @0x226024 mov r0, r6 */
/* @0x226028 bl 0x27d1d0 <_ZdlPv> */
/* @0x22602c ldr r3, [r4] */
/* @0x226030 sub r5, r5, #2096 */
/* @0x226034 sub r5, r5, #4 */
/* @0x226038 cmp r3, r5 */
/* @0x22603c rsb r2, r7, r5 */
/* @0x226040 add r2, r2, r8 */
/* @0x226044 bne 0x226010 <_ZN9COggAudio4QuitEv+0x6c> */
/* @0x226048 sub r0, r3, #8 */
/* @0x22604c bl 0x27d1d4 <_ZdaPv> */
/* @0x226050 mov r3, #0 */
/* @0x226054 str r3, [r4] */
/* @0x226058 str r3, [r4, #0x14] */
/* @0x22605c ldr r3, [r4, #0x4] */
/* @0x226060 cmp r3, #0 */
/* @0x226064 pople {r4, r5, r6, r7, r8, pc} */
/* @0x226068 mov r5, #0 */
/* @0x22606c ldr r2, [r4, #0x10] */
/* @0x226070 mov r1, r5 */
/* @0x226074 mov r0, r4 */
/* @0x226078 ldr r2, [r2, r5, lsl #2] */
/* @0x22607c add r5, r5, #1 */
/* @0x226080 cmp r2, #0 */
/* @0x226084 beq 0x226090 <_ZN9COggAudio4QuitEv+0xec> */
/* @0x226088 bl 0x225f2c <_ZN9COggAudio17Delete_SyncThreadEi> */
/* @0x22608c ldr r3, [r4, #0x4] */
/* @0x226090 cmp r3, r5 */
/* @0x226094 bgt 0x22606c <_ZN9COggAudio4QuitEv+0xc8> */
/* @0x226098 pop {r4, r5, r6, r7, r8, pc} */
