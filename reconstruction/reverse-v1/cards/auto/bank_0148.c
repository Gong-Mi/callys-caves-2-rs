/* libyoyo.so 覆盖卡组 0148
 * 函数 0x1bb4d4..0x1bcd5c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1bb4d4 · F_LayerGetVspeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x1bb4d4 cmp r3, #1 */
/* @0x1bb4d8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bb4dc mov r4, #0 */
/* @0x1bb4e0 mov r5, r0 */
/* @0x1bb4e4 ldr r6, [sp, #0x18] */
/* @0x1bb4e8 str r4, [r0, #0xc] */
/* @0x1bb4ec str r4, [r0] */
/* @0x1bb4f0 str r4, [r0, #0x4] */
/* @0x1bb4f4 beq 0x1bb50c <_Z16F_LayerGetVspeedR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1bb4f8 ldr r0, [pc, #0x74] */
/* @0x1bb4fc mov r1, r4 */
/* @0x1bb500 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bb504 add r0, pc, r0 */
/* @0x1bb508 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb50c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb510 ldr r3, [r6, #0xc] */
/* @0x1bb514 mov r1, r4 */
/* @0x1bb518 bic r3, r3, #-16777216 */
/* @0x1bb51c cmp r3, #1 */
/* @0x1bb520 mov r7, r0 */
/* @0x1bb524 mov r0, r6 */
/* @0x1bb528 beq 0x1bb558 <_Z16F_LayerGetVspeedR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1bb52c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb530 mov r1, r0 */
/* @0x1bb534 mov r0, r7 */
/* @0x1bb538 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb53c cmp r0, #0 */
/* @0x1bb540 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bb544 vldr s15, [r0, #20] */
/* @0x1bb548 vcvt.f64.f32 d6, s15 */
/* @0x1bb54c vmov r2, r3, d6 */
/* @0x1bb550 stm r5, {r2, r3} */
/* @0x1bb554 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb558 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb55c mov r1, r0 */
/* @0x1bb560 mov r0, r7 */
/* @0x1bb564 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb568 cmp r0, #0 */
/* @0x1bb56c bne 0x1bb544 <_Z16F_LayerGetVspeedR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1bb570 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb574 andseq r2, r9, r8, lsr r6 */

/* ── FUNC 0x1bb578 · F_LayerScriptBegin(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1bb578 cmp r3, #2 */
/* @0x1bb57c mov r3, #0 */
/* @0x1bb580 push {r4, r5, r6, lr} */
/* @0x1bb584 mov r4, r3 */
/* @0x1bb588 ldr r5, [sp, #0x10] */
/* @0x1bb58c movt r3, #0xbff0 */
/* @0x1bb590 str r4, [r0, #0xc] */
/* @0x1bb594 str r3, [r0, #0x4] */
/* @0x1bb598 str r4, [r0] */
/* @0x1bb59c beq 0x1bb5b4 <_Z18F_LayerScriptBeginR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bb5a0 ldr r0, [pc, #0x7c] */
/* @0x1bb5a4 mov r1, r4 */
/* @0x1bb5a8 pop {r4, r5, r6, lr} */
/* @0x1bb5ac add r0, pc, r0 */
/* @0x1bb5b0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb5b4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb5b8 ldr r3, [r5, #0xc] */
/* @0x1bb5bc mov r1, r4 */
/* @0x1bb5c0 bic r3, r3, #-16777216 */
/* @0x1bb5c4 cmp r3, #1 */
/* @0x1bb5c8 mov r6, r0 */
/* @0x1bb5cc mov r0, r5 */
/* @0x1bb5d0 beq 0x1bb604 <_Z18F_LayerScriptBeginR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1bb5d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb5d8 mov r1, r0 */
/* @0x1bb5dc mov r0, r6 */
/* @0x1bb5e0 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb5e4 mov r4, r0 */
/* @0x1bb5e8 cmp r4, #0 */
/* @0x1bb5ec popeq {r4, r5, r6, pc} */
/* @0x1bb5f0 mov r0, r5 */
/* @0x1bb5f4 mov r1, #1 */
/* @0x1bb5f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb5fc str r0, [r4, #0x20] */
/* @0x1bb600 pop {r4, r5, r6, pc} */
/* @0x1bb604 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb608 mov r1, r0 */
/* @0x1bb60c mov r0, r6 */
/* @0x1bb610 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb614 mov r4, r0 */
/* @0x1bb618 cmp r4, #0 */
/* @0x1bb61c bne 0x1bb5f0 <_Z18F_LayerScriptBeginR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bb620 pop {r4, r5, r6, pc} */
/* @0x1bb624 andseq r2, r9, r0, asr #11 */

/* ── FUNC 0x1bb628 · F_LayerScriptEnd(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1bb628 cmp r3, #2 */
/* @0x1bb62c mov r3, #0 */
/* @0x1bb630 push {r4, r5, r6, lr} */
/* @0x1bb634 mov r4, r3 */
/* @0x1bb638 ldr r5, [sp, #0x10] */
/* @0x1bb63c movt r3, #0xbff0 */
/* @0x1bb640 str r4, [r0, #0xc] */
/* @0x1bb644 str r3, [r0, #0x4] */
/* @0x1bb648 str r4, [r0] */
/* @0x1bb64c beq 0x1bb664 <_Z16F_LayerScriptEndR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bb650 ldr r0, [pc, #0x7c] */
/* @0x1bb654 mov r1, r4 */
/* @0x1bb658 pop {r4, r5, r6, lr} */
/* @0x1bb65c add r0, pc, r0 */
/* @0x1bb660 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb664 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb668 ldr r3, [r5, #0xc] */
/* @0x1bb66c mov r1, r4 */
/* @0x1bb670 bic r3, r3, #-16777216 */
/* @0x1bb674 cmp r3, #1 */
/* @0x1bb678 mov r6, r0 */
/* @0x1bb67c mov r0, r5 */
/* @0x1bb680 beq 0x1bb6b4 <_Z16F_LayerScriptEndR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1bb684 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb688 mov r1, r0 */
/* @0x1bb68c mov r0, r6 */
/* @0x1bb690 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb694 mov r4, r0 */
/* @0x1bb698 cmp r4, #0 */
/* @0x1bb69c popeq {r4, r5, r6, pc} */
/* @0x1bb6a0 mov r0, r5 */
/* @0x1bb6a4 mov r1, #1 */
/* @0x1bb6a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb6ac str r0, [r4, #0x24] */
/* @0x1bb6b0 pop {r4, r5, r6, pc} */
/* @0x1bb6b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb6b8 mov r1, r0 */
/* @0x1bb6bc mov r0, r6 */
/* @0x1bb6c0 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb6c4 mov r4, r0 */
/* @0x1bb6c8 cmp r4, #0 */
/* @0x1bb6cc bne 0x1bb6a0 <_Z16F_LayerScriptEndR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bb6d0 pop {r4, r5, r6, pc} */
/* @0x1bb6d4 andseq r2, r9, r4, asr #10 */

/* ── FUNC 0x1bb6d8 · F_LayerShader(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1bb6d8 cmp r3, #2 */
/* @0x1bb6dc mov r3, #0 */
/* @0x1bb6e0 push {r4, r5, r6, lr} */
/* @0x1bb6e4 mov r4, r3 */
/* @0x1bb6e8 ldr r5, [sp, #0x10] */
/* @0x1bb6ec movt r3, #0xbff0 */
/* @0x1bb6f0 str r4, [r0, #0xc] */
/* @0x1bb6f4 str r3, [r0, #0x4] */
/* @0x1bb6f8 str r4, [r0] */
/* @0x1bb6fc beq 0x1bb714 <_Z13F_LayerShaderR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bb700 ldr r0, [pc, #0x7c] */
/* @0x1bb704 mov r1, r4 */
/* @0x1bb708 pop {r4, r5, r6, lr} */
/* @0x1bb70c add r0, pc, r0 */
/* @0x1bb710 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb714 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb718 ldr r3, [r5, #0xc] */
/* @0x1bb71c mov r1, r4 */
/* @0x1bb720 bic r3, r3, #-16777216 */
/* @0x1bb724 cmp r3, #1 */
/* @0x1bb728 mov r6, r0 */
/* @0x1bb72c mov r0, r5 */
/* @0x1bb730 beq 0x1bb764 <_Z13F_LayerShaderR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1bb734 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb738 mov r1, r0 */
/* @0x1bb73c mov r0, r6 */
/* @0x1bb740 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb744 mov r4, r0 */
/* @0x1bb748 cmp r4, #0 */
/* @0x1bb74c popeq {r4, r5, r6, pc} */
/* @0x1bb750 mov r0, r5 */
/* @0x1bb754 mov r1, #1 */
/* @0x1bb758 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb75c str r0, [r4, #0x28] */
/* @0x1bb760 pop {r4, r5, r6, pc} */
/* @0x1bb764 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb768 mov r1, r0 */
/* @0x1bb76c mov r0, r6 */
/* @0x1bb770 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb774 mov r4, r0 */
/* @0x1bb778 cmp r4, #0 */
/* @0x1bb77c bne 0x1bb750 <_Z13F_LayerShaderR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bb780 pop {r4, r5, r6, pc} */
/* @0x1bb784 andseq r2, r9, r4, asr #9 */

/* ── FUNC 0x1bb788 · F_LayerGetScriptBegin(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1bb788 cmp r3, #1 */
/* @0x1bb78c push {r3, r4, r5, r6, r7, lr} */
/* @0x1bb790 mov r3, #0 */
/* @0x1bb794 mov r5, r3 */
/* @0x1bb798 mov r4, r0 */
/* @0x1bb79c movt r3, #0xbff0 */
/* @0x1bb7a0 str r5, [r0, #0xc] */
/* @0x1bb7a4 str r3, [r0, #0x4] */
/* @0x1bb7a8 str r5, [r0] */
/* @0x1bb7ac ldr r6, [sp, #0x18] */
/* @0x1bb7b0 beq 0x1bb7c8 <_Z21F_LayerGetScriptBeginR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bb7b4 ldr r0, [pc, #0x78] */
/* @0x1bb7b8 mov r1, r5 */
/* @0x1bb7bc pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bb7c0 add r0, pc, r0 */
/* @0x1bb7c4 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb7c8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb7cc ldr r3, [r6, #0xc] */
/* @0x1bb7d0 mov r1, r5 */
/* @0x1bb7d4 bic r3, r3, #-16777216 */
/* @0x1bb7d8 cmp r3, #1 */
/* @0x1bb7dc mov r7, r0 */
/* @0x1bb7e0 mov r0, r6 */
/* @0x1bb7e4 beq 0x1bb818 <_Z21F_LayerGetScriptBeginR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1bb7e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb7ec mov r1, r0 */
/* @0x1bb7f0 mov r0, r7 */
/* @0x1bb7f4 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb7f8 cmp r0, #0 */
/* @0x1bb7fc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bb800 ldr r2, [r0, #0x20] */
/* @0x1bb804 vmov s15, r2 */
/* @0x1bb808 vcvt.f64.s32 d7, s15 */
/* @0x1bb80c vmov r2, r3, d7 */
/* @0x1bb810 stm r4, {r2, r3} */
/* @0x1bb814 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb818 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb81c mov r1, r0 */
/* @0x1bb820 mov r0, r7 */
/* @0x1bb824 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb828 cmp r0, #0 */
/* @0x1bb82c bne 0x1bb800 <_Z21F_LayerGetScriptBeginR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bb830 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb834 andseq r2, r9, r12, lsr r4 */

/* ── FUNC 0x1bb838 · F_LayerGetScriptEnd(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1bb838 cmp r3, #1 */
/* @0x1bb83c push {r3, r4, r5, r6, r7, lr} */
/* @0x1bb840 mov r3, #0 */
/* @0x1bb844 mov r5, r3 */
/* @0x1bb848 mov r4, r0 */
/* @0x1bb84c movt r3, #0xbff0 */
/* @0x1bb850 str r5, [r0, #0xc] */
/* @0x1bb854 str r3, [r0, #0x4] */
/* @0x1bb858 str r5, [r0] */
/* @0x1bb85c ldr r6, [sp, #0x18] */
/* @0x1bb860 beq 0x1bb878 <_Z19F_LayerGetScriptEndR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bb864 ldr r0, [pc, #0x78] */
/* @0x1bb868 mov r1, r5 */
/* @0x1bb86c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bb870 add r0, pc, r0 */
/* @0x1bb874 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb878 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb87c ldr r3, [r6, #0xc] */
/* @0x1bb880 mov r1, r5 */
/* @0x1bb884 bic r3, r3, #-16777216 */
/* @0x1bb888 cmp r3, #1 */
/* @0x1bb88c mov r7, r0 */
/* @0x1bb890 mov r0, r6 */
/* @0x1bb894 beq 0x1bb8c8 <_Z19F_LayerGetScriptEndR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1bb898 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb89c mov r1, r0 */
/* @0x1bb8a0 mov r0, r7 */
/* @0x1bb8a4 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb8a8 cmp r0, #0 */
/* @0x1bb8ac popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bb8b0 ldr r2, [r0, #0x24] */
/* @0x1bb8b4 vmov s15, r2 */
/* @0x1bb8b8 vcvt.f64.s32 d7, s15 */
/* @0x1bb8bc vmov r2, r3, d7 */
/* @0x1bb8c0 stm r4, {r2, r3} */
/* @0x1bb8c4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb8c8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb8cc mov r1, r0 */
/* @0x1bb8d0 mov r0, r7 */
/* @0x1bb8d4 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb8d8 cmp r0, #0 */
/* @0x1bb8dc bne 0x1bb8b0 <_Z19F_LayerGetScriptEndR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bb8e0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb8e4 andseq r2, r9, r4, asr #7 */

/* ── FUNC 0x1bb8e8 · F_LayerGetShader(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1bb8e8 cmp r3, #1 */
/* @0x1bb8ec push {r3, r4, r5, r6, r7, lr} */
/* @0x1bb8f0 mov r3, #0 */
/* @0x1bb8f4 mov r5, r3 */
/* @0x1bb8f8 mov r4, r0 */
/* @0x1bb8fc movt r3, #0xbff0 */
/* @0x1bb900 str r5, [r0, #0xc] */
/* @0x1bb904 str r3, [r0, #0x4] */
/* @0x1bb908 str r5, [r0] */
/* @0x1bb90c ldr r6, [sp, #0x18] */
/* @0x1bb910 beq 0x1bb928 <_Z16F_LayerGetShaderR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bb914 ldr r0, [pc, #0x78] */
/* @0x1bb918 mov r1, r5 */
/* @0x1bb91c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bb920 add r0, pc, r0 */
/* @0x1bb924 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb928 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb92c ldr r3, [r6, #0xc] */
/* @0x1bb930 mov r1, r5 */
/* @0x1bb934 bic r3, r3, #-16777216 */
/* @0x1bb938 cmp r3, #1 */
/* @0x1bb93c mov r7, r0 */
/* @0x1bb940 mov r0, r6 */
/* @0x1bb944 beq 0x1bb978 <_Z16F_LayerGetShaderR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1bb948 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb94c mov r1, r0 */
/* @0x1bb950 mov r0, r7 */
/* @0x1bb954 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb958 cmp r0, #0 */
/* @0x1bb95c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bb960 ldr r2, [r0, #0x28] */
/* @0x1bb964 vmov s15, r2 */
/* @0x1bb968 vcvt.f64.s32 d7, s15 */
/* @0x1bb96c vmov r2, r3, d7 */
/* @0x1bb970 stm r4, {r2, r3} */
/* @0x1bb974 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb978 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb97c mov r1, r0 */
/* @0x1bb980 mov r0, r7 */
/* @0x1bb984 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb988 cmp r0, #0 */
/* @0x1bb98c bne 0x1bb960 <_Z16F_LayerGetShaderR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bb990 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb994 andseq r2, r9, r8, asr #6 */

/* ── FUNC 0x1bb998 · F_LayerActivate(RValue&, CInstance*, CInstance*, int, RValue*) · size=352 · insn=88 */
/* @0x1bb998 push {r4, r5, r6, r7, r8, lr} */
/* @0x1bb99c cmp r3, #1 */
/* @0x1bb9a0 sub sp, sp, #8 */
/* @0x1bb9a4 mov r4, #0 */
/* @0x1bb9a8 str r4, [r0, #0xc] */
/* @0x1bb9ac ldr r5, [sp, #0x20] */
/* @0x1bb9b0 str r4, [r0] */
/* @0x1bb9b4 str r4, [r0, #0x4] */
/* @0x1bb9b8 beq 0x1bb9d4 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bb9bc ldr r0, [pc, #0x128] */
/* @0x1bb9c0 mov r1, r4 */
/* @0x1bb9c4 add r0, pc, r0 */
/* @0x1bb9c8 add sp, sp, #8 */
/* @0x1bb9cc pop {r4, r5, r6, r7, r8, lr} */
/* @0x1bb9d0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb9d4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb9d8 ldr r3, [r5, #0xc] */
/* @0x1bb9dc mov r1, r4 */
/* @0x1bb9e0 bic r3, r3, #-16777216 */
/* @0x1bb9e4 cmp r3, #1 */
/* @0x1bb9e8 mov r6, r0 */
/* @0x1bb9ec mov r0, r5 */
/* @0x1bb9f0 beq 0x1bbad8 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1bb9f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb9f8 mov r1, r0 */
/* @0x1bb9fc mov r0, r6 */
/* @0x1bba00 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bba04 cmp r0, #0 */
/* @0x1bba08 beq 0x1bbaa0 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x1bba0c ldr r4, [r0, #0x5c] */
/* @0x1bba10 cmp r4, #0 */
/* @0x1bba14 beq 0x1bbaa0 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x1bba18 ldr r8, [pc, #0xd0] */
/* @0x1bba1c mov r7, #0 */
/* @0x1bba20 add r8, pc, r8 */
/* @0x1bba24 b 0x1bba34 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1bba28 cmp r5, #0 */
/* @0x1bba2c mov r4, r5 */
/* @0x1bba30 beq 0x1bbaa0 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x1bba34 ldr r3, [r4] */
/* @0x1bba38 ldr r5, [r4, #0x18] */
/* @0x1bba3c cmp r3, #2 */
/* @0x1bba40 bne 0x1bba28 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1bba44 ldr r3, [r4, #0x20] */
/* @0x1bba48 mov r1, #0 */
/* @0x1bba4c ldr r6, [pc, #0xa0] */
/* @0x1bba50 cmp r3, r1 */
/* @0x1bba54 mov r0, r3 */
/* @0x1bba58 beq 0x1bba28 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1bba5c ldrb r3, [r3, #0x69] */
/* @0x1bba60 cmp r3, r1 */
/* @0x1bba64 beq 0x1bbaa0 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x1bba68 bl 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x1bba6c ldr r6, [pc, r6] */
/* @0x1bba70 ldr r4, [r4, #0x20] */
/* @0x1bba74 ldr r1, [r6, #0x8] */
/* @0x1bba78 ldr r3, [r6, #0x4] */
/* @0x1bba7c cmp r1, r3 */
/* @0x1bba80 beq 0x1bbaa8 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x1bba84 ldr r2, [r6] */
/* @0x1bba88 cmp r5, #0 */
/* @0x1bba8c str r4, [r2, r1, lsl #2] */
/* @0x1bba90 add r3, r1, #1 */
/* @0x1bba94 mov r4, r5 */
/* @0x1bba98 str r3, [r6, #0x8] */
/* @0x1bba9c bne 0x1bba34 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1bbaa0 add sp, sp, #8 */
/* @0x1bbaa4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1bbaa8 lsl r3, r1, #1 */
/* @0x1bbaac ldr r0, [r6] */
/* @0x1bbab0 str r3, [r6, #0x4] */
/* @0x1bbab4 lsl r1, r1, #3 */
/* @0x1bbab8 mov r2, r8 */
/* @0x1bbabc str r7, [sp] */
/* @0x1bbac0 mov r3, #74 */
/* @0x1bbac4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1bbac8 ldr r1, [r6, #0x8] */
/* @0x1bbacc mov r2, r0 */
/* @0x1bbad0 str r0, [r6] */
/* @0x1bbad4 b 0x1bba88 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x1bbad8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bbadc mov r1, r0 */
/* @0x1bbae0 mov r0, r6 */
/* @0x1bbae4 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bbae8 b 0x1bba04 <_Z15F_LayerActivateR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1bbaec ldrsbeq r2, [r9], -r4 */
/* @0x1bbaf0 andseq r5, r7, r0, lsl r6 */
/* @0x1bbaf4 .word 0x002321dc */

/* ── FUNC 0x1bbaf8 · F_LayerDeactivate(RValue&, CInstance*, CInstance*, int, RValue*) · size=340 · insn=85 */
/* @0x1bbaf8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1bbafc cmp r3, #1 */
/* @0x1bbb00 sub sp, sp, #8 */
/* @0x1bbb04 mov r4, #0 */
/* @0x1bbb08 str r4, [r0, #0xc] */
/* @0x1bbb0c ldr r5, [sp, #0x20] */
/* @0x1bbb10 str r4, [r0] */
/* @0x1bbb14 str r4, [r0, #0x4] */
/* @0x1bbb18 beq 0x1bbb34 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bbb1c ldr r0, [pc, #0x11c] */
/* @0x1bbb20 mov r1, r4 */
/* @0x1bbb24 add r0, pc, r0 */
/* @0x1bbb28 add sp, sp, #8 */
/* @0x1bbb2c pop {r4, r5, r6, r7, r8, lr} */
/* @0x1bbb30 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bbb34 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bbb38 ldr r3, [r5, #0xc] */
/* @0x1bbb3c mov r1, r4 */
/* @0x1bbb40 bic r3, r3, #-16777216 */
/* @0x1bbb44 cmp r3, #1 */
/* @0x1bbb48 mov r6, r0 */
/* @0x1bbb4c mov r0, r5 */
/* @0x1bbb50 beq 0x1bbc2c <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1bbb54 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bbb58 mov r1, r0 */
/* @0x1bbb5c mov r0, r6 */
/* @0x1bbb60 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bbb64 cmp r0, #0 */
/* @0x1bbb68 beq 0x1bbbf4 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x1bbb6c ldr r4, [r0, #0x58] */
/* @0x1bbb70 cmp r4, #0 */
/* @0x1bbb74 beq 0x1bbbf4 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x1bbb78 ldr r8, [pc, #0xc4] */
/* @0x1bbb7c add r8, pc, r8 */
/* @0x1bbb80 b 0x1bbb90 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1bbb84 cmp r5, #0 */
/* @0x1bbb88 mov r4, r5 */
/* @0x1bbb8c beq 0x1bbbf4 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x1bbb90 ldr r3, [r4] */
/* @0x1bbb94 ldr r5, [r4, #0x14] */
/* @0x1bbb98 cmp r3, #2 */
/* @0x1bbb9c bne 0x1bbb84 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1bbba0 ldr r3, [r4, #0x20] */
/* @0x1bbba4 mov r1, #1 */
/* @0x1bbba8 ldr r6, [pc, #0x98] */
/* @0x1bbbac ldrb r7, [r3, #0x69] */
/* @0x1bbbb0 mov r0, r3 */
/* @0x1bbbb4 cmp r7, #0 */
/* @0x1bbbb8 bne 0x1bbbf4 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x1bbbbc bl 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x1bbbc0 ldr r6, [pc, r6] */
/* @0x1bbbc4 ldr r4, [r4, #0x20] */
/* @0x1bbbc8 ldr r1, [r6, #0x8] */
/* @0x1bbbcc ldr r3, [r6, #0x4] */
/* @0x1bbbd0 cmp r1, r3 */
/* @0x1bbbd4 beq 0x1bbbfc <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x1bbbd8 ldr r2, [r6] */
/* @0x1bbbdc cmp r5, #0 */
/* @0x1bbbe0 str r4, [r2, r1, lsl #2] */
/* @0x1bbbe4 add r3, r1, #1 */
/* @0x1bbbe8 mov r4, r5 */
/* @0x1bbbec str r3, [r6, #0x8] */
/* @0x1bbbf0 bne 0x1bbb90 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1bbbf4 add sp, sp, #8 */
/* @0x1bbbf8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1bbbfc lsl r3, r1, #1 */
/* @0x1bbc00 ldr r0, [r6] */
/* @0x1bbc04 str r3, [r6, #0x4] */
/* @0x1bbc08 lsl r1, r1, #3 */
/* @0x1bbc0c mov r2, r8 */
/* @0x1bbc10 str r7, [sp] */
/* @0x1bbc14 mov r3, #74 */
/* @0x1bbc18 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1bbc1c ldr r1, [r6, #0x8] */
/* @0x1bbc20 mov r2, r0 */
/* @0x1bbc24 str r0, [r6] */
/* @0x1bbc28 b 0x1bbbdc <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x1bbc2c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bbc30 mov r1, r0 */
/* @0x1bbc34 mov r0, r6 */
/* @0x1bbc38 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bbc3c b 0x1bbb64 <_Z17F_LayerDeactivateR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1bbc40 andseq r2, r9, r12, lsr #3 */
/* @0x1bbc44 ldrheq r5, [r7], -r4 */
/* @0x1bbc48 eoreq r2, r3, r8, lsl #1 */

/* ── FUNC 0x1bbc4c · F_LayerGetAllElements(RValue&, CInstance*, CInstance*, int, RValue*) · size=436 · insn=109 */
/* @0x1bbc4c cmp r3, #1 */
/* @0x1bbc50 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1bbc54 mov r3, #0 */
/* @0x1bbc58 mov r5, r3 */
/* @0x1bbc5c mov r4, r0 */
/* @0x1bbc60 movt r3, #0xbff0 */
/* @0x1bbc64 str r5, [r0, #0xc] */
/* @0x1bbc68 str r3, [r0, #0x4] */
/* @0x1bbc6c str r5, [r0] */
/* @0x1bbc70 ldr r6, [sp, #0x20] */
/* @0x1bbc74 beq 0x1bbc8c <_Z21F_LayerGetAllElementsR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bbc78 ldr r0, [pc, #0x170] */
/* @0x1bbc7c mov r1, r5 */
/* @0x1bbc80 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1bbc84 add r0, pc, r0 */
/* @0x1bbc88 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bbc8c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bbc90 subs r7, r0, #0 */
/* @0x1bbc94 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1bbc98 ldr r3, [r6, #0xc] */
/* @0x1bbc9c mov r0, r6 */
/* @0x1bbca0 mov r1, r5 */
/* @0x1bbca4 bic r3, r3, #-16777216 */
/* @0x1bbca8 cmp r3, #1 */
/* @0x1bbcac beq 0x1bbdb4 <_Z21F_LayerGetAllElementsR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1bbcb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bbcb4 mov r1, r0 */
/* @0x1bbcb8 mov r0, r7 */
/* @0x1bbcbc bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bbcc0 mov r5, r0 */
/* @0x1bbcc4 cmp r5, #0 */
/* @0x1bbcc8 beq 0x1bbdcc <_Z21F_LayerGetAllElementsR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x1bbccc ldr r6, [r5, #0x60] */
/* @0x1bbcd0 mov r3, #2 */
/* @0x1bbcd4 mov r0, r4 */
/* @0x1bbcd8 str r3, [r4, #0xc] */
/* @0x1bbcdc bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x1bbce0 ldr r9, [pc, #0x10c] */
/* @0x1bbce4 mov r8, #1 */
/* @0x1bbce8 movw r2, #0x14b7 */
/* @0x1bbcec add r9, pc, r9 */
/* @0x1bbcf0 mov r3, r8 */
/* @0x1bbcf4 mov r1, r9 */
/* @0x1bbcf8 mov r7, r0 */
/* @0x1bbcfc str r0, [r4] */
/* @0x1bbd00 str r8, [r0, #0x10] */
/* @0x1bbd04 mov r0, #8 */
/* @0x1bbd08 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1bbd0c mov r3, r8 */
/* @0x1bbd10 movw r2, #0x14b8 */
/* @0x1bbd14 mov r1, r9 */
/* @0x1bbd18 str r0, [r7, #0x4] */
/* @0x1bbd1c lsl r0, r6, #4 */
/* @0x1bbd20 ldr r12, [r4] */
/* @0x1bbd24 ldr r7, [r12, #0x4] */
/* @0x1bbd28 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1bbd2c ldr r12, [r5, #0x58] */
/* @0x1bbd30 cmp r12, #0 */
/* @0x1bbd34 str r0, [r7, #0x4] */
/* @0x1bbd38 ldr r3, [r4] */
/* @0x1bbd3c ldr r2, [r3, #0x4] */
/* @0x1bbd40 str r6, [r2] */
/* @0x1bbd44 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1bbd48 cmp r6, #0 */
/* @0x1bbd4c pople {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1bbd50 mov r1, #0 */
/* @0x1bbd54 ldr r3, [r4] */
/* @0x1bbd58 mov r7, r1 */
/* @0x1bbd5c b 0x1bbd70 <_Z21F_LayerGetAllElementsR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1bbd60 cmp r1, r6 */
/* @0x1bbd64 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1bbd68 ldr r3, [r4] */
/* @0x1bbd6c ldr r2, [r3, #0x4] */
/* @0x1bbd70 vldr s15, [r12, #4] */
/* @0x1bbd74 vcvt.f64.s32 d7, s15 */
/* @0x1bbd78 ldr r0, [r3, #0x4] */
/* @0x1bbd7c lsl r5, r1, #4 */
/* @0x1bbd80 ldr r8, [r2, #0x4] */
/* @0x1bbd84 ldr r0, [r0, #0x4] */
/* @0x1bbd88 add r8, r8, r5 */
/* @0x1bbd8c add r5, r0, r5 */
/* @0x1bbd90 str r7, [r8, #0xc] */
/* @0x1bbd94 vmov r2, r3, d7 */
/* @0x1bbd98 str r2, [r0, r1, lsl #4] */
/* @0x1bbd9c add r1, r1, #1 */
/* @0x1bbda0 str r3, [r5, #0x4] */
/* @0x1bbda4 ldr r12, [r12, #0x14] */
/* @0x1bbda8 cmp r12, #0 */
/* @0x1bbdac bne 0x1bbd60 <_Z21F_LayerGetAllElementsR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x1bbdb0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1bbdb4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bbdb8 mov r1, r0 */
/* @0x1bbdbc mov r0, r7 */
/* @0x1bbdc0 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bbdc4 mov r5, r0 */
/* @0x1bbdc8 b 0x1bbcc4 <_Z21F_LayerGetAllElementsR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bbdcc ldr r3, [pc, #0x24] */
/* @0x1bbdd0 ldr r1, [pc, #0x24] */
/* @0x1bbdd4 ldr r3, [pc, r3] */
/* @0x1bbdd8 add r1, pc, r1 */
/* @0x1bbddc ldr r0, [r3] */
/* @0x1bbde0 ldr r3, [r0] */
/* @0x1bbde4 ldr r3, [r3, #0xc] */
/* @0x1bbde8 blx r3 */
/* @0x1bbdec pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1bbdf0 andseq r2, r9, r4, lsl #1 */
/* @0x1bbdf4 andseq r1, r9, r0, lsl #21 */
/* @0x1bbdf8 eoreq r1, r3, r0, asr #18 */
/* @0x1bbdfc andseq r1, r9, r0, ror #30 */

/* ── FUNC 0x1bbe00 · F_LayerGetName(RValue&, CInstance*, CInstance*, int, RValue*) · size=236 · insn=59 */
/* @0x1bbe00 cmp r3, #1 */
/* @0x1bbe04 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bbe08 mov r3, #0 */
/* @0x1bbe0c mov r5, r3 */
/* @0x1bbe10 mov r4, r0 */
/* @0x1bbe14 movt r3, #0xbff0 */
/* @0x1bbe18 str r5, [r0, #0xc] */
/* @0x1bbe1c str r3, [r0, #0x4] */
/* @0x1bbe20 str r5, [r0] */
/* @0x1bbe24 ldr r6, [sp, #0x18] */
/* @0x1bbe28 beq 0x1bbe40 <_Z14F_LayerGetNameR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bbe2c ldr r0, [pc, #0xa8] */
/* @0x1bbe30 mov r1, r5 */
/* @0x1bbe34 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bbe38 add r0, pc, r0 */
/* @0x1bbe3c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bbe40 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bbe44 subs r7, r0, #0 */
/* @0x1bbe48 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bbe4c ldr r3, [r6, #0xc] */
/* @0x1bbe50 mov r0, r6 */
/* @0x1bbe54 mov r1, r5 */
/* @0x1bbe58 bic r3, r3, #-16777216 */
/* @0x1bbe5c cmp r3, #1 */
/* @0x1bbe60 beq 0x1bbe94 <_Z14F_LayerGetNameR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1bbe64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bbe68 mov r1, r0 */
/* @0x1bbe6c mov r0, r7 */
/* @0x1bbe70 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bbe74 cmp r0, #0 */
/* @0x1bbe78 beq 0x1bbeb8 <_Z14F_LayerGetNameR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x1bbe7c ldr r1, [r0, #0x1c] */
/* @0x1bbe80 mov r0, r4 */
/* @0x1bbe84 cmp r1, #0 */
/* @0x1bbe88 beq 0x1bbea8 <_Z14F_LayerGetNameR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x1bbe8c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bbe90 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1bbe94 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bbe98 mov r1, r0 */
/* @0x1bbe9c mov r0, r7 */
/* @0x1bbea0 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bbea4 b 0x1bbe74 <_Z14F_LayerGetNameR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1bbea8 ldr r1, [pc, #0x30] */
/* @0x1bbeac pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bbeb0 add r1, pc, r1 */
/* @0x1bbeb4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1bbeb8 ldr r3, [pc, #0x24] */
/* @0x1bbebc ldr r1, [pc, #0x24] */
/* @0x1bbec0 ldr r3, [pc, r3] */
/* @0x1bbec4 add r1, pc, r1 */
/* @0x1bbec8 ldr r0, [r3] */
/* @0x1bbecc ldr r3, [r0] */
/* @0x1bbed0 ldr r3, [r3, #0xc] */
/* @0x1bbed4 blx r3 */
/* @0x1bbed8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bbedc andseq r1, r9, r8, lsr pc */
/* @0x1bbee0 andseq r2, r7, r6, lsl #25 */
/* @0x1bbee4 eoreq r1, r3, r4, asr r8 */
/* @0x1bbee8 andseq r1, r9, r4, ror lr */

/* ── FUNC 0x1bbeec · F_LayerDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=500 · insn=125 */
/* @0x1bbeec push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1bbef0 cmp r3, #2 */
/* @0x1bbef4 sub sp, sp, #8 */
/* @0x1bbef8 mov r3, #0 */
/* @0x1bbefc mov r4, r3 */
/* @0x1bbf00 movt r3, #0xbff0 */
/* @0x1bbf04 str r4, [r0, #0xc] */
/* @0x1bbf08 str r3, [r0, #0x4] */
/* @0x1bbf0c str r4, [r0] */
/* @0x1bbf10 ldr r5, [sp, #0x28] */
/* @0x1bbf14 beq 0x1bbf30 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1bbf18 ldr r0, [pc, #0x1ac] */
/* @0x1bbf1c mov r1, r4 */
/* @0x1bbf20 add r0, pc, r0 */
/* @0x1bbf24 add sp, sp, #8 */
/* @0x1bbf28 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1bbf2c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bbf30 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bbf34 subs r6, r0, #0 */
/* @0x1bbf38 beq 0x1bc058 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x1bbf3c ldr r3, [r5, #0xc] */
/* @0x1bbf40 mov r1, r4 */
/* @0x1bbf44 mov r0, r5 */
/* @0x1bbf48 bic r3, r3, #-16777216 */
/* @0x1bbf4c cmp r3, #1 */
/* @0x1bbf50 beq 0x1bc060 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x1bbf54 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bbf58 mov r1, r0 */
/* @0x1bbf5c mov r0, r6 */
/* @0x1bbf60 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bbf64 mov r4, r0 */
/* @0x1bbf68 cmp r4, #0 */
/* @0x1bbf6c beq 0x1bc078 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x1bbf70 mov r0, r5 */
/* @0x1bbf74 mov r1, #1 */
/* @0x1bbf78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bbf7c ldr r3, [r4, #0x4] */
/* @0x1bbf80 cmp r3, r0 */
/* @0x1bbf84 mov r8, r0 */
/* @0x1bbf88 beq 0x1bc058 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x1bbf8c mov r1, r4 */
/* @0x1bbf90 mov r0, r6 */
/* @0x1bbf94 mov r2, r8 */
/* @0x1bbf98 mov r3, #0 */
/* @0x1bbf9c bl 0x1b8200 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib> */
/* @0x1bbfa0 ldr r4, [r4, #0x58] */
/* @0x1bbfa4 cmp r4, #0 */
/* @0x1bbfa8 beq 0x1bc058 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x1bbfac ldr r10, [pc, #0x11c] */
/* @0x1bbfb0 mov r9, #0 */
/* @0x1bbfb4 add r10, pc, r10 */
/* @0x1bbfb8 b 0x1bbfc8 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x1bbfbc ldr r4, [r4, #0x14] */
/* @0x1bbfc0 cmp r4, #0 */
/* @0x1bbfc4 beq 0x1bc058 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x1bbfc8 ldr r3, [r4] */
/* @0x1bbfcc cmp r3, #2 */
/* @0x1bbfd0 bne 0x1bbfbc <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x1bbfd4 ldr r6, [r4, #0x20] */
/* @0x1bbfd8 cmp r6, #0 */
/* @0x1bbfdc beq 0x1bbfbc <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x1bbfe0 vmov s14, r8 */
/* @0x1bbfe4 ldr r7, [pc, #0xe8] */
/* @0x1bbfe8 vcvt.f32.s32 s15, s14 */
/* @0x1bbfec ldr r7, [pc, r7] */
/* @0x1bbff0 ldr r1, [r7, #0x8] */
/* @0x1bbff4 ldr r3, [r7, #0x4] */
/* @0x1bbff8 cmp r1, r3 */
/* @0x1bbffc vstr s15, [r6, #384] */
/* @0x1bc000 beq 0x1bc09c <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x1bc004 ldr r2, [r7] */
/* @0x1bc008 cmp r1, #0 */
/* @0x1bc00c ble 0x1bc040 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x1bc010 ldr r3, [r2] */
/* @0x1bc014 cmp r6, r3 */
/* @0x1bc018 beq 0x1bbfbc <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x1bc01c mov r12, r2 */
/* @0x1bc020 mov r3, #0 */
/* @0x1bc024 b 0x1bc034 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x1bc028 ldr r5, [r12, #0x4]! */
/* @0x1bc02c cmp r6, r5 */
/* @0x1bc030 beq 0x1bbfbc <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x1bc034 add r3, r3, #1 */
/* @0x1bc038 cmp r3, r1 */
/* @0x1bc03c bne 0x1bc028 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x1bc040 str r6, [r2, r1, lsl #2] */
/* @0x1bc044 add r1, r1, #1 */
/* @0x1bc048 ldr r4, [r4, #0x14] */
/* @0x1bc04c str r1, [r7, #0x8] */
/* @0x1bc050 cmp r4, #0 */
/* @0x1bc054 bne 0x1bbfc8 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x1bc058 add sp, sp, #8 */
/* @0x1bc05c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1bc060 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bc064 mov r1, r0 */
/* @0x1bc068 mov r0, r6 */
/* @0x1bc06c bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bc070 mov r4, r0 */
/* @0x1bc074 b 0x1bbf68 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x1bc078 ldr r3, [pc, #0x58] */
/* @0x1bc07c ldr r1, [pc, #0x58] */
/* @0x1bc080 ldr r3, [pc, r3] */
/* @0x1bc084 add r1, pc, r1 */
/* @0x1bc088 ldr r0, [r3] */
/* @0x1bc08c ldr r3, [r0] */
/* @0x1bc090 ldr r3, [r3, #0xc] */
/* @0x1bc094 blx r3 */
/* @0x1bc098 b 0x1bc058 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x1bc09c lsl r3, r1, #1 */
/* @0x1bc0a0 ldr r0, [r7] */
/* @0x1bc0a4 str r3, [r7, #0x4] */
/* @0x1bc0a8 lsl r1, r1, #3 */
/* @0x1bc0ac mov r2, r10 */
/* @0x1bc0b0 str r9, [sp] */
/* @0x1bc0b4 mov r3, #74 */
/* @0x1bc0b8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1bc0bc ldr r1, [r7, #0x8] */
/* @0x1bc0c0 mov r2, r0 */
/* @0x1bc0c4 str r0, [r7] */
/* @0x1bc0c8 b 0x1bc008 <_Z12F_LayerDepthR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x1bc0cc andseq r1, r9, r12, ror lr */
/* @0x1bc0d0 andseq r5, r7, r12, ror r0 */
/* @0x1bc0d4 strhteq r2, [r3], -r8 */
/* @0x1bc0d8 mlaeq r3, r4, r6, r1 */
/* @0x1bc0dc andseq r1, r9, r4, asr #26 */

/* ── FUNC 0x1bc0e0 · F_LayerDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x1bc0e0 cmp r3, #1 */
/* @0x1bc0e4 mov r3, #0 */
/* @0x1bc0e8 push {r4, r5, r6, lr} */
/* @0x1bc0ec mov r4, r3 */
/* @0x1bc0f0 ldr r5, [sp, #0x10] */
/* @0x1bc0f4 movt r3, #0xbff0 */
/* @0x1bc0f8 str r4, [r0, #0xc] */
/* @0x1bc0fc str r3, [r0, #0x4] */
/* @0x1bc100 str r4, [r0] */
/* @0x1bc104 beq 0x1bc11c <_Z14F_LayerDestroyR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bc108 ldr r0, [pc, #0x98] */
/* @0x1bc10c mov r1, r4 */
/* @0x1bc110 pop {r4, r5, r6, lr} */
/* @0x1bc114 add r0, pc, r0 */
/* @0x1bc118 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bc11c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bc120 ldr r3, [r5, #0xc] */
/* @0x1bc124 mov r1, r4 */
/* @0x1bc128 bic r3, r3, #-16777216 */
/* @0x1bc12c cmp r3, #1 */
/* @0x1bc130 mov r6, r0 */
/* @0x1bc134 mov r0, r5 */
/* @0x1bc138 beq 0x1bc16c <_Z14F_LayerDestroyR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1bc13c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc140 mov r1, r0 */
/* @0x1bc144 mov r0, r6 */
/* @0x1bc148 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bc14c mov r3, r0 */
/* @0x1bc150 cmp r3, #0 */
/* @0x1bc154 beq 0x1bc184 <_Z14F_LayerDestroyR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x1bc158 mov r0, r6 */
/* @0x1bc15c ldr r1, [r3] */
/* @0x1bc160 mov r2, #1 */
/* @0x1bc164 pop {r4, r5, r6, lr} */
/* @0x1bc168 b 0x1b95d8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib> */
/* @0x1bc16c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bc170 mov r1, r0 */
/* @0x1bc174 mov r0, r6 */
/* @0x1bc178 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bc17c mov r3, r0 */
/* @0x1bc180 b 0x1bc150 <_Z14F_LayerDestroyR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1bc184 ldr r3, [pc, #0x20] */
/* @0x1bc188 ldr r1, [pc, #0x20] */
/* @0x1bc18c ldr r3, [pc, r3] */
/* @0x1bc190 add r1, pc, r1 */
/* @0x1bc194 ldr r0, [r3] */
/* @0x1bc198 ldr r3, [r0] */
/* @0x1bc19c ldr r3, [r3, #0xc] */
/* @0x1bc1a0 blx r3 */
/* @0x1bc1a4 pop {r4, r5, r6, pc} */
/* @0x1bc1a8 andseq r1, r9, r0, ror #25 */
/* @0x1bc1ac eoreq r1, r3, r8, lsl #11 */
/* @0x1bc1b0 mulseq r9, r0, r12 */

/* ── FUNC 0x1bc1b4 · CLayerManager::MoveElement(CRoom*, CLayerElementBase*, CLayer*) · size=236 · insn=59 */
/* @0x1bc1b4 cmp r0, #0 */
/* @0x1bc1b8 str r4, [sp, #-0x4]! */
/* @0x1bc1bc beq 0x1bc26c <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0xb8> */
/* @0x1bc1c0 cmp r1, #0 */
/* @0x1bc1c4 beq 0x1bc26c <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0xb8> */
/* @0x1bc1c8 cmp r2, #0 */
/* @0x1bc1cc beq 0x1bc26c <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0xb8> */
/* @0x1bc1d0 ldr r3, [r1, #0x10] */
/* @0x1bc1d4 cmp r3, r2 */
/* @0x1bc1d8 beq 0x1bc26c <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0xb8> */
/* @0x1bc1dc cmp r3, #0 */
/* @0x1bc1e0 beq 0x1bc218 <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0x64> */
/* @0x1bc1e4 ldr r12, [r1, #0x18] */
/* @0x1bc1e8 ldr r4, [r1, #0x14] */
/* @0x1bc1ec cmp r12, #0 */
/* @0x1bc1f0 strne r4, [r12, #0x14] */
/* @0x1bc1f4 ldrne r12, [r1, #0x18] */
/* @0x1bc1f8 ldrne r4, [r1, #0x14] */
/* @0x1bc1fc streq r4, [r3, #0x58] */
/* @0x1bc200 cmp r4, #0 */
/* @0x1bc204 streq r12, [r3, #0x5c] */
/* @0x1bc208 strne r12, [r4, #0x18] */
/* @0x1bc20c ldr r12, [r3, #0x60] */
/* @0x1bc210 sub r12, r12, #1 */
/* @0x1bc214 str r12, [r3, #0x60] */
/* @0x1bc218 ldr r3, [r1] */
/* @0x1bc21c cmp r3, #2 */
/* @0x1bc220 beq 0x1bc274 <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0xc0> */
/* @0x1bc224 ldr r12, [r2, #0x58] */
/* @0x1bc228 ldr r4, [r2, #0x60] */
/* @0x1bc22c cmp r12, #0 */
/* @0x1bc230 streq r1, [r2, #0x5c] */
/* @0x1bc234 add r4, r4, #1 */
/* @0x1bc238 str r4, [r2, #0x60] */
/* @0x1bc23c strne r1, [r12, #0x18] */
/* @0x1bc240 movne r12, #0 */
/* @0x1bc244 ldrne r4, [r2, #0x58] */
/* @0x1bc248 streq r1, [r2, #0x58] */
/* @0x1bc24c streq r12, [r1, #0x18] */
/* @0x1bc250 strne r4, [r1, #0x14] */
/* @0x1bc254 streq r12, [r1, #0x14] */
/* @0x1bc258 strne r1, [r2, #0x58] */
/* @0x1bc25c strne r12, [r1, #0x18] */
/* @0x1bc260 cmp r3, #2 */
/* @0x1bc264 str r2, [r1, #0x10] */
/* @0x1bc268 beq 0x1bc294 <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0xe0> */
/* @0x1bc26c ldr r4, [sp], #4 */
/* @0x1bc270 bx lr */
/* @0x1bc274 ldr r12, [r1, #0x20] */
/* @0x1bc278 cmp r12, #0 */
/* @0x1bc27c ldrne r3, [r2] */
/* @0x1bc280 movne r4, #1 */
/* @0x1bc284 strbne r4, [r12, #0x174] */
/* @0x1bc288 strne r3, [r12, #0x170] */
/* @0x1bc28c ldrne r3, [r1] */
/* @0x1bc290 b 0x1bc224 <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0x70> */
/* @0x1bc294 ldr r1, [r1, #0x20] */
/* @0x1bc298 ldr r4, [sp], #4 */
/* @0x1bc29c b 0x1b8a28 <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance> */

/* ── FUNC 0x1bc2a0 · CLayerManager::GetElementFromID(CRoom*, int, CLayer**) · size=280 · insn=70 */
/* @0x1bc2a0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1bc2a4 subs r9, r0, #0 */
/* @0x1bc2a8 mov r10, r2 */
/* @0x1bc2ac beq 0x1bc364 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xc4> */
/* @0x1bc2b0 ldr r0, [r9, #0x10c] */
/* @0x1bc2b4 cmp r0, #0 */
/* @0x1bc2b8 beq 0x1bc2c8 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0x28> */
/* @0x1bc2bc ldr r3, [r0, #0x4] */
/* @0x1bc2c0 cmp r3, r1 */
/* @0x1bc2c4 beq 0x1bc3a4 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0x104> */
/* @0x1bc2c8 mov r0, r1 */
/* @0x1bc2cc bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1bc2d0 ldr r12, [r9, #0x100] */
/* @0x1bc2d4 ldr r8, [r9, #0x108] */
/* @0x1bc2d8 bic r0, r0, #-2147483648 */
/* @0x1bc2dc and r3, r0, r12 */
/* @0x1bc2e0 lsl r5, r3, #1 */
/* @0x1bc2e4 add r2, r5, r3 */
/* @0x1bc2e8 add r2, r8, r2, lsl #2 */
/* @0x1bc2ec ldr r1, [r2, #0x8] */
/* @0x1bc2f0 cmp r1, #0 */
/* @0x1bc2f4 beq 0x1bc364 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xc4> */
/* @0x1bc2f8 cmp r0, r1 */
/* @0x1bc2fc beq 0x1bc374 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xd4> */
/* @0x1bc300 ldr r2, [r9, #0xf8] */
/* @0x1bc304 and r1, r12, r1 */
/* @0x1bc308 add r4, r3, r2 */
/* @0x1bc30c rsb r1, r1, r4 */
/* @0x1bc310 tst r1, r12 */
/* @0x1bc314 bmi 0x1bc364 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xc4> */
/* @0x1bc318 mov r4, #0 */
/* @0x1bc31c b 0x1bc330 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0x90> */
/* @0x1bc320 cmp r0, r1 */
/* @0x1bc324 beq 0x1bc36c <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xcc> */
/* @0x1bc328 cmp r6, r4 */
/* @0x1bc32c blt 0x1bc364 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xc4> */
/* @0x1bc330 add r3, r3, #1 */
/* @0x1bc334 add r4, r4, #1 */
/* @0x1bc338 and r3, r12, r3 */
/* @0x1bc33c add r7, r3, r2 */
/* @0x1bc340 lsl r5, r3, #1 */
/* @0x1bc344 add r1, r5, r3 */
/* @0x1bc348 add r1, r8, r1, lsl #2 */
/* @0x1bc34c ldr r1, [r1, #0x8] */
/* @0x1bc350 and r6, r12, r1 */
/* @0x1bc354 cmp r1, #0 */
/* @0x1bc358 rsb r6, r6, r7 */
/* @0x1bc35c and r6, r6, r12 */
/* @0x1bc360 bne 0x1bc320 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0x80> */
/* @0x1bc364 mov r0, #0 */
/* @0x1bc368 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1bc36c cmn r3, #1 */
/* @0x1bc370 beq 0x1bc364 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xc4> */
/* @0x1bc374 add r3, r5, r3 */
/* @0x1bc378 add r8, r8, r3, lsl #2 */
/* @0x1bc37c cmn r8, #4 */
/* @0x1bc380 beq 0x1bc364 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xc4> */
/* @0x1bc384 cmp r10, #0 */
/* @0x1bc388 ldrne r3, [r8, #0x4] */
/* @0x1bc38c ldrne r3, [r3, #0x10] */
/* @0x1bc390 strne r3, [r10] */
/* @0x1bc394 ldr r3, [r8, #0x4] */
/* @0x1bc398 str r3, [r9, #0x10c] */
/* @0x1bc39c ldr r0, [r8, #0x4] */
/* @0x1bc3a0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1bc3a4 cmp r2, #0 */
/* @0x1bc3a8 ldrne r3, [r0, #0x10] */
/* @0x1bc3ac strne r3, [r2] */
/* @0x1bc3b0 ldrne r0, [r9, #0x10c] */
/* @0x1bc3b4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x1bc3b8 · F_LayerBackgroundVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bc3b8 cmp r3, #2 */
/* @0x1bc3bc mov r3, #0 */
/* @0x1bc3c0 push {r4, r5, r6, lr} */
/* @0x1bc3c4 mov r4, r3 */
/* @0x1bc3c8 ldr r5, [sp, #0x10] */
/* @0x1bc3cc movt r3, #0xbff0 */
/* @0x1bc3d0 str r4, [r0, #0xc] */
/* @0x1bc3d4 str r3, [r0, #0x4] */
/* @0x1bc3d8 str r4, [r0] */
/* @0x1bc3dc beq 0x1bc3f4 <_Z24F_LayerBackgroundVisibleR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bc3e0 ldr r0, [pc, #0x60] */
/* @0x1bc3e4 mov r1, r4 */
/* @0x1bc3e8 pop {r4, r5, r6, lr} */
/* @0x1bc3ec add r0, pc, r0 */
/* @0x1bc3f0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bc3f4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bc3f8 mov r1, r4 */
/* @0x1bc3fc mov r6, r0 */
/* @0x1bc400 mov r0, r5 */
/* @0x1bc404 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc408 mov r2, r4 */
/* @0x1bc40c mov r1, r0 */
/* @0x1bc410 mov r0, r6 */
/* @0x1bc414 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bc418 cmp r0, #0 */
/* @0x1bc41c popeq {r4, r5, r6, pc} */
/* @0x1bc420 ldr r1, [r0] */
/* @0x1bc424 cmp r1, #1 */
/* @0x1bc428 popne {r4, r5, r6, pc} */
/* @0x1bc42c ldr r4, [r0, #0x1c] */
/* @0x1bc430 cmp r4, #0 */
/* @0x1bc434 popeq {r4, r5, r6, pc} */
/* @0x1bc438 mov r0, r5 */
/* @0x1bc43c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1bc440 strb r0, [r4] */
/* @0x1bc444 pop {r4, r5, r6, pc} */
/* @0x1bc448 andseq r1, r9, r8, ror #20 */

/* ── FUNC 0x1bc44c · F_LayerBackgroundHtiled(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bc44c cmp r3, #2 */
/* @0x1bc450 mov r3, #0 */
/* @0x1bc454 push {r4, r5, r6, lr} */
/* @0x1bc458 mov r4, r3 */
/* @0x1bc45c ldr r5, [sp, #0x10] */
/* @0x1bc460 movt r3, #0xbff0 */
/* @0x1bc464 str r4, [r0, #0xc] */
/* @0x1bc468 str r3, [r0, #0x4] */
/* @0x1bc46c str r4, [r0] */
/* @0x1bc470 beq 0x1bc488 <_Z23F_LayerBackgroundHtiledR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bc474 ldr r0, [pc, #0x60] */
/* @0x1bc478 mov r1, r4 */
/* @0x1bc47c pop {r4, r5, r6, lr} */
/* @0x1bc480 add r0, pc, r0 */
/* @0x1bc484 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bc488 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bc48c mov r1, r4 */
/* @0x1bc490 mov r6, r0 */
/* @0x1bc494 mov r0, r5 */
/* @0x1bc498 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc49c mov r2, r4 */
/* @0x1bc4a0 mov r1, r0 */
/* @0x1bc4a4 mov r0, r6 */
/* @0x1bc4a8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bc4ac cmp r0, #0 */
/* @0x1bc4b0 popeq {r4, r5, r6, pc} */
/* @0x1bc4b4 ldr r1, [r0] */
/* @0x1bc4b8 cmp r1, #1 */
/* @0x1bc4bc popne {r4, r5, r6, pc} */
/* @0x1bc4c0 ldr r4, [r0, #0x1c] */
/* @0x1bc4c4 cmp r4, #0 */
/* @0x1bc4c8 popeq {r4, r5, r6, pc} */
/* @0x1bc4cc mov r0, r5 */
/* @0x1bc4d0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1bc4d4 strb r0, [r4, #0x8] */
/* @0x1bc4d8 pop {r4, r5, r6, pc} */
/* @0x1bc4dc andseq r1, r9, r12, lsl #20 */

/* ── FUNC 0x1bc4e0 · F_LayerBackgroundVtiled(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bc4e0 cmp r3, #2 */
/* @0x1bc4e4 mov r3, #0 */
/* @0x1bc4e8 push {r4, r5, r6, lr} */
/* @0x1bc4ec mov r4, r3 */
/* @0x1bc4f0 ldr r5, [sp, #0x10] */
/* @0x1bc4f4 movt r3, #0xbff0 */
/* @0x1bc4f8 str r4, [r0, #0xc] */
/* @0x1bc4fc str r3, [r0, #0x4] */
/* @0x1bc500 str r4, [r0] */
/* @0x1bc504 beq 0x1bc51c <_Z23F_LayerBackgroundVtiledR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bc508 ldr r0, [pc, #0x60] */
/* @0x1bc50c mov r1, r4 */
/* @0x1bc510 pop {r4, r5, r6, lr} */
/* @0x1bc514 add r0, pc, r0 */
/* @0x1bc518 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bc51c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bc520 mov r1, r4 */
/* @0x1bc524 mov r6, r0 */
/* @0x1bc528 mov r0, r5 */
/* @0x1bc52c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc530 mov r2, r4 */
/* @0x1bc534 mov r1, r0 */
/* @0x1bc538 mov r0, r6 */
/* @0x1bc53c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bc540 cmp r0, #0 */
/* @0x1bc544 popeq {r4, r5, r6, pc} */
/* @0x1bc548 ldr r1, [r0] */
/* @0x1bc54c cmp r1, #1 */
/* @0x1bc550 popne {r4, r5, r6, pc} */
/* @0x1bc554 ldr r4, [r0, #0x1c] */
/* @0x1bc558 cmp r4, #0 */
/* @0x1bc55c popeq {r4, r5, r6, pc} */
/* @0x1bc560 mov r0, r5 */
/* @0x1bc564 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1bc568 strb r0, [r4, #0x9] */
/* @0x1bc56c pop {r4, r5, r6, pc} */
/* @0x1bc570 ldrheq r1, [r9], -r0 */

/* ── FUNC 0x1bc574 · F_LayerBackgroundStretch(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bc574 cmp r3, #2 */
/* @0x1bc578 mov r3, #0 */
/* @0x1bc57c push {r4, r5, r6, lr} */
/* @0x1bc580 mov r4, r3 */
/* @0x1bc584 ldr r5, [sp, #0x10] */
/* @0x1bc588 movt r3, #0xbff0 */
/* @0x1bc58c str r4, [r0, #0xc] */
/* @0x1bc590 str r3, [r0, #0x4] */
/* @0x1bc594 str r4, [r0] */
/* @0x1bc598 beq 0x1bc5b0 <_Z24F_LayerBackgroundStretchR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bc59c ldr r0, [pc, #0x60] */
/* @0x1bc5a0 mov r1, r4 */
/* @0x1bc5a4 pop {r4, r5, r6, lr} */
/* @0x1bc5a8 add r0, pc, r0 */
/* @0x1bc5ac b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bc5b0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bc5b4 mov r1, r4 */
/* @0x1bc5b8 mov r6, r0 */
/* @0x1bc5bc mov r0, r5 */
/* @0x1bc5c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc5c4 mov r2, r4 */
/* @0x1bc5c8 mov r1, r0 */
/* @0x1bc5cc mov r0, r6 */
/* @0x1bc5d0 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bc5d4 cmp r0, #0 */
/* @0x1bc5d8 popeq {r4, r5, r6, pc} */
/* @0x1bc5dc ldr r1, [r0] */
/* @0x1bc5e0 cmp r1, #1 */
/* @0x1bc5e4 popne {r4, r5, r6, pc} */
/* @0x1bc5e8 ldr r4, [r0, #0x1c] */
/* @0x1bc5ec cmp r4, #0 */
/* @0x1bc5f0 popeq {r4, r5, r6, pc} */
/* @0x1bc5f4 mov r0, r5 */
/* @0x1bc5f8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1bc5fc strb r0, [r4, #0x14] */
/* @0x1bc600 pop {r4, r5, r6, pc} */
/* @0x1bc604 andseq r1, r9, r4, asr r9 */

/* ── FUNC 0x1bc608 · F_LayerBackgroundXscale(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bc608 cmp r3, #2 */
/* @0x1bc60c mov r3, #0 */
/* @0x1bc610 push {r4, r5, r6, lr} */
/* @0x1bc614 mov r4, r3 */
/* @0x1bc618 ldr r5, [sp, #0x10] */
/* @0x1bc61c movt r3, #0xbff0 */
/* @0x1bc620 str r4, [r0, #0xc] */
/* @0x1bc624 str r3, [r0, #0x4] */
/* @0x1bc628 str r4, [r0] */
/* @0x1bc62c beq 0x1bc644 <_Z23F_LayerBackgroundXscaleR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bc630 ldr r0, [pc, #0x60] */
/* @0x1bc634 mov r1, r4 */
/* @0x1bc638 pop {r4, r5, r6, lr} */
/* @0x1bc63c add r0, pc, r0 */
/* @0x1bc640 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bc644 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bc648 mov r1, r4 */
/* @0x1bc64c mov r6, r0 */
/* @0x1bc650 mov r0, r5 */
/* @0x1bc654 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc658 mov r2, r4 */
/* @0x1bc65c mov r1, r0 */
/* @0x1bc660 mov r0, r6 */
/* @0x1bc664 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bc668 cmp r0, #0 */
/* @0x1bc66c popeq {r4, r5, r6, pc} */
/* @0x1bc670 ldr r1, [r0] */
/* @0x1bc674 cmp r1, #1 */
/* @0x1bc678 popne {r4, r5, r6, pc} */
/* @0x1bc67c ldr r4, [r0, #0x1c] */
/* @0x1bc680 cmp r4, #0 */
/* @0x1bc684 popeq {r4, r5, r6, pc} */
/* @0x1bc688 mov r0, r5 */
/* @0x1bc68c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bc690 str r0, [r4, #0xc] */
/* @0x1bc694 pop {r4, r5, r6, pc} */
/* @0x1bc698 ldrsheq r1, [r9], -r8 */

/* ── FUNC 0x1bc69c · F_LayerBackgroundYscale(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bc69c cmp r3, #2 */
/* @0x1bc6a0 mov r3, #0 */
/* @0x1bc6a4 push {r4, r5, r6, lr} */
/* @0x1bc6a8 mov r4, r3 */
/* @0x1bc6ac ldr r5, [sp, #0x10] */
/* @0x1bc6b0 movt r3, #0xbff0 */
/* @0x1bc6b4 str r4, [r0, #0xc] */
/* @0x1bc6b8 str r3, [r0, #0x4] */
/* @0x1bc6bc str r4, [r0] */
/* @0x1bc6c0 beq 0x1bc6d8 <_Z23F_LayerBackgroundYscaleR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bc6c4 ldr r0, [pc, #0x60] */
/* @0x1bc6c8 mov r1, r4 */
/* @0x1bc6cc pop {r4, r5, r6, lr} */
/* @0x1bc6d0 add r0, pc, r0 */
/* @0x1bc6d4 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bc6d8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bc6dc mov r1, r4 */
/* @0x1bc6e0 mov r6, r0 */
/* @0x1bc6e4 mov r0, r5 */
/* @0x1bc6e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc6ec mov r2, r4 */
/* @0x1bc6f0 mov r1, r0 */
/* @0x1bc6f4 mov r0, r6 */
/* @0x1bc6f8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bc6fc cmp r0, #0 */
/* @0x1bc700 popeq {r4, r5, r6, pc} */
/* @0x1bc704 ldr r1, [r0] */
/* @0x1bc708 cmp r1, #1 */
/* @0x1bc70c popne {r4, r5, r6, pc} */
/* @0x1bc710 ldr r4, [r0, #0x1c] */
/* @0x1bc714 cmp r4, #0 */
/* @0x1bc718 popeq {r4, r5, r6, pc} */
/* @0x1bc71c mov r0, r5 */
/* @0x1bc720 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bc724 str r0, [r4, #0x10] */
/* @0x1bc728 pop {r4, r5, r6, pc} */
/* @0x1bc72c mulseq r9, r12, r8 */

/* ── FUNC 0x1bc730 · F_LayerBackgroundBlend(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bc730 cmp r3, #2 */
/* @0x1bc734 mov r3, #0 */
/* @0x1bc738 push {r4, r5, r6, lr} */
/* @0x1bc73c mov r4, r3 */
/* @0x1bc740 ldr r5, [sp, #0x10] */
/* @0x1bc744 movt r3, #0xbff0 */
/* @0x1bc748 str r4, [r0, #0xc] */
/* @0x1bc74c str r3, [r0, #0x4] */
/* @0x1bc750 str r4, [r0] */
/* @0x1bc754 beq 0x1bc76c <_Z22F_LayerBackgroundBlendR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bc758 ldr r0, [pc, #0x60] */
/* @0x1bc75c mov r1, r4 */
/* @0x1bc760 pop {r4, r5, r6, lr} */
/* @0x1bc764 add r0, pc, r0 */
/* @0x1bc768 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bc76c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bc770 mov r1, r4 */
/* @0x1bc774 mov r6, r0 */
/* @0x1bc778 mov r0, r5 */
/* @0x1bc77c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc780 mov r2, r4 */
/* @0x1bc784 mov r1, r0 */
/* @0x1bc788 mov r0, r6 */
/* @0x1bc78c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bc790 cmp r0, #0 */
/* @0x1bc794 popeq {r4, r5, r6, pc} */
/* @0x1bc798 ldr r1, [r0] */
/* @0x1bc79c cmp r1, #1 */
/* @0x1bc7a0 popne {r4, r5, r6, pc} */
/* @0x1bc7a4 ldr r4, [r0, #0x1c] */
/* @0x1bc7a8 cmp r4, #0 */
/* @0x1bc7ac popeq {r4, r5, r6, pc} */
/* @0x1bc7b0 mov r0, r5 */
/* @0x1bc7b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc7b8 str r0, [r4, #0x18] */
/* @0x1bc7bc pop {r4, r5, r6, pc} */
/* @0x1bc7c0 andseq r1, r9, r0, asr #16 */

/* ── FUNC 0x1bc7c4 · F_LayerBackgroundAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bc7c4 cmp r3, #2 */
/* @0x1bc7c8 mov r3, #0 */
/* @0x1bc7cc push {r4, r5, r6, lr} */
/* @0x1bc7d0 mov r4, r3 */
/* @0x1bc7d4 ldr r5, [sp, #0x10] */
/* @0x1bc7d8 movt r3, #0xbff0 */
/* @0x1bc7dc str r4, [r0, #0xc] */
/* @0x1bc7e0 str r3, [r0, #0x4] */
/* @0x1bc7e4 str r4, [r0] */
/* @0x1bc7e8 beq 0x1bc800 <_Z22F_LayerBackgroundAlphaR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bc7ec ldr r0, [pc, #0x60] */
/* @0x1bc7f0 mov r1, r4 */
/* @0x1bc7f4 pop {r4, r5, r6, lr} */
/* @0x1bc7f8 add r0, pc, r0 */
/* @0x1bc7fc b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bc800 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bc804 mov r1, r4 */
/* @0x1bc808 mov r6, r0 */
/* @0x1bc80c mov r0, r5 */
/* @0x1bc810 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc814 mov r2, r4 */
/* @0x1bc818 mov r1, r0 */
/* @0x1bc81c mov r0, r6 */
/* @0x1bc820 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bc824 cmp r0, #0 */
/* @0x1bc828 popeq {r4, r5, r6, pc} */
/* @0x1bc82c ldr r1, [r0] */
/* @0x1bc830 cmp r1, #1 */
/* @0x1bc834 popne {r4, r5, r6, pc} */
/* @0x1bc838 ldr r4, [r0, #0x1c] */
/* @0x1bc83c cmp r4, #0 */
/* @0x1bc840 popeq {r4, r5, r6, pc} */
/* @0x1bc844 mov r0, r5 */
/* @0x1bc848 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bc84c str r0, [r4, #0x1c] */
/* @0x1bc850 pop {r4, r5, r6, pc} */
/* @0x1bc854 andseq r1, r9, r4, ror #15 */

/* ── FUNC 0x1bc858 · F_LayerBackgroundIndex(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bc858 cmp r3, #2 */
/* @0x1bc85c mov r3, #0 */
/* @0x1bc860 push {r4, r5, r6, lr} */
/* @0x1bc864 mov r4, r3 */
/* @0x1bc868 ldr r5, [sp, #0x10] */
/* @0x1bc86c movt r3, #0xbff0 */
/* @0x1bc870 str r4, [r0, #0xc] */
/* @0x1bc874 str r3, [r0, #0x4] */
/* @0x1bc878 str r4, [r0] */
/* @0x1bc87c beq 0x1bc894 <_Z22F_LayerBackgroundIndexR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bc880 ldr r0, [pc, #0x60] */
/* @0x1bc884 mov r1, r4 */
/* @0x1bc888 pop {r4, r5, r6, lr} */
/* @0x1bc88c add r0, pc, r0 */
/* @0x1bc890 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bc894 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bc898 mov r1, r4 */
/* @0x1bc89c mov r6, r0 */
/* @0x1bc8a0 mov r0, r5 */
/* @0x1bc8a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc8a8 mov r2, r4 */
/* @0x1bc8ac mov r1, r0 */
/* @0x1bc8b0 mov r0, r6 */
/* @0x1bc8b4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bc8b8 cmp r0, #0 */
/* @0x1bc8bc popeq {r4, r5, r6, pc} */
/* @0x1bc8c0 ldr r1, [r0] */
/* @0x1bc8c4 cmp r1, #1 */
/* @0x1bc8c8 popne {r4, r5, r6, pc} */
/* @0x1bc8cc ldr r4, [r0, #0x1c] */
/* @0x1bc8d0 cmp r4, #0 */
/* @0x1bc8d4 popeq {r4, r5, r6, pc} */
/* @0x1bc8d8 mov r0, r5 */
/* @0x1bc8dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bc8e0 str r0, [r4, #0x20] */
/* @0x1bc8e4 pop {r4, r5, r6, pc} */
/* @0x1bc8e8 andseq r1, r9, r8, lsl #15 */

/* ── FUNC 0x1bc8ec · F_LayerBackgroundSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bc8ec cmp r3, #2 */
/* @0x1bc8f0 mov r3, #0 */
/* @0x1bc8f4 push {r4, r5, r6, lr} */
/* @0x1bc8f8 mov r4, r3 */
/* @0x1bc8fc ldr r5, [sp, #0x10] */
/* @0x1bc900 movt r3, #0xbff0 */
/* @0x1bc904 str r4, [r0, #0xc] */
/* @0x1bc908 str r3, [r0, #0x4] */
/* @0x1bc90c str r4, [r0] */
/* @0x1bc910 beq 0x1bc928 <_Z22F_LayerBackgroundSpeedR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bc914 ldr r0, [pc, #0x60] */
/* @0x1bc918 mov r1, r4 */
/* @0x1bc91c pop {r4, r5, r6, lr} */
/* @0x1bc920 add r0, pc, r0 */
/* @0x1bc924 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bc928 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bc92c mov r1, r4 */
/* @0x1bc930 mov r6, r0 */
/* @0x1bc934 mov r0, r5 */
/* @0x1bc938 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc93c mov r2, r4 */
/* @0x1bc940 mov r1, r0 */
/* @0x1bc944 mov r0, r6 */
/* @0x1bc948 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bc94c cmp r0, #0 */
/* @0x1bc950 popeq {r4, r5, r6, pc} */
/* @0x1bc954 ldr r1, [r0] */
/* @0x1bc958 cmp r1, #1 */
/* @0x1bc95c popne {r4, r5, r6, pc} */
/* @0x1bc960 ldr r4, [r0, #0x1c] */
/* @0x1bc964 cmp r4, #0 */
/* @0x1bc968 popeq {r4, r5, r6, pc} */
/* @0x1bc96c mov r0, r5 */
/* @0x1bc970 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bc974 str r0, [r4, #0x24] */
/* @0x1bc978 pop {r4, r5, r6, pc} */
/* @0x1bc97c andseq r1, r9, r12, lsr #14 */

/* ── FUNC 0x1bc980 · F_LayerBackgroundSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1bc980 cmp r3, #2 */
/* @0x1bc984 mov r3, #0 */
/* @0x1bc988 push {r4, r5, r6, lr} */
/* @0x1bc98c mov r4, r3 */
/* @0x1bc990 ldr r5, [sp, #0x10] */
/* @0x1bc994 movt r3, #0xbff0 */
/* @0x1bc998 str r4, [r0, #0xc] */
/* @0x1bc99c str r3, [r0, #0x4] */
/* @0x1bc9a0 str r4, [r0] */
/* @0x1bc9a4 beq 0x1bc9bc <_Z23F_LayerBackgroundSpriteR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bc9a8 ldr r0, [pc, #0x60] */
/* @0x1bc9ac mov r1, r4 */
/* @0x1bc9b0 pop {r4, r5, r6, lr} */
/* @0x1bc9b4 add r0, pc, r0 */
/* @0x1bc9b8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bc9bc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bc9c0 mov r1, r4 */
/* @0x1bc9c4 mov r6, r0 */
/* @0x1bc9c8 mov r0, r5 */
/* @0x1bc9cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bc9d0 mov r2, r4 */
/* @0x1bc9d4 mov r1, r0 */
/* @0x1bc9d8 mov r0, r6 */
/* @0x1bc9dc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bc9e0 cmp r0, #0 */
/* @0x1bc9e4 popeq {r4, r5, r6, pc} */
/* @0x1bc9e8 ldr r1, [r0] */
/* @0x1bc9ec cmp r1, #1 */
/* @0x1bc9f0 popne {r4, r5, r6, pc} */
/* @0x1bc9f4 ldr r4, [r0, #0x1c] */
/* @0x1bc9f8 cmp r4, #0 */
/* @0x1bc9fc popeq {r4, r5, r6, pc} */
/* @0x1bca00 mov r0, r5 */
/* @0x1bca04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bca08 str r0, [r4, #0x4] */
/* @0x1bca0c pop {r4, r5, r6, pc} */
/* @0x1bca10 ldrsbeq r1, [r9], -r0 */

/* ── FUNC 0x1bca14 · F_LayerBackgroundGetVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1bca14 cmp r3, #1 */
/* @0x1bca18 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bca1c mov r3, #0 */
/* @0x1bca20 mov r5, r3 */
/* @0x1bca24 mov r4, r0 */
/* @0x1bca28 movt r3, #0xbff0 */
/* @0x1bca2c str r5, [r0, #0xc] */
/* @0x1bca30 str r3, [r0, #0x4] */
/* @0x1bca34 str r5, [r0] */
/* @0x1bca38 ldr r6, [sp, #0x18] */
/* @0x1bca3c beq 0x1bca54 <_Z27F_LayerBackgroundGetVisibleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bca40 ldr r0, [pc, #0x78] */
/* @0x1bca44 mov r1, r5 */
/* @0x1bca48 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bca4c add r0, pc, r0 */
/* @0x1bca50 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bca54 str r5, [r0] */
/* @0x1bca58 mov r3, #0 */
/* @0x1bca5c movt r3, #0x3ff0 */
/* @0x1bca60 str r3, [r0, #0x4] */
/* @0x1bca64 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bca68 mov r1, r5 */
/* @0x1bca6c mov r7, r0 */
/* @0x1bca70 mov r0, r6 */
/* @0x1bca74 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bca78 mov r2, r5 */
/* @0x1bca7c mov r1, r0 */
/* @0x1bca80 mov r0, r7 */
/* @0x1bca84 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bca88 cmp r0, #0 */
/* @0x1bca8c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bca90 ldr r3, [r0] */
/* @0x1bca94 cmp r3, #1 */
/* @0x1bca98 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bca9c ldr r3, [r0, #0x1c] */
/* @0x1bcaa0 cmp r3, #0 */
/* @0x1bcaa4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcaa8 ldrb r2, [r3] */
/* @0x1bcaac vmov s15, r2 */
/* @0x1bcab0 vcvt.f64.u32 d7, s15 */
/* @0x1bcab4 vmov r2, r3, d7 */
/* @0x1bcab8 stm r4, {r2, r3} */
/* @0x1bcabc pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bcac0 andseq r1, r9, r0, ror r6 */

/* ── FUNC 0x1bcac4 · F_LayerBackgroundGetSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x1bcac4 cmp r3, #1 */
/* @0x1bcac8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bcacc mov r3, #0 */
/* @0x1bcad0 mov r4, r3 */
/* @0x1bcad4 mov r5, r0 */
/* @0x1bcad8 movt r3, #0xbff0 */
/* @0x1bcadc str r4, [r0, #0xc] */
/* @0x1bcae0 str r3, [r0, #0x4] */
/* @0x1bcae4 str r4, [r0] */
/* @0x1bcae8 ldr r6, [sp, #0x18] */
/* @0x1bcaec beq 0x1bcb04 <_Z26F_LayerBackgroundGetSpriteR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bcaf0 ldr r0, [pc, #0x68] */
/* @0x1bcaf4 mov r1, r4 */
/* @0x1bcaf8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bcafc add r0, pc, r0 */
/* @0x1bcb00 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bcb04 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bcb08 mov r1, r4 */
/* @0x1bcb0c mov r7, r0 */
/* @0x1bcb10 mov r0, r6 */
/* @0x1bcb14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bcb18 mov r2, r4 */
/* @0x1bcb1c mov r1, r0 */
/* @0x1bcb20 mov r0, r7 */
/* @0x1bcb24 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bcb28 cmp r0, #0 */
/* @0x1bcb2c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcb30 ldr r3, [r0] */
/* @0x1bcb34 cmp r3, #1 */
/* @0x1bcb38 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bcb3c ldr r3, [r0, #0x1c] */
/* @0x1bcb40 cmp r3, #0 */
/* @0x1bcb44 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcb48 ldr r2, [r3, #0x4] */
/* @0x1bcb4c vmov s15, r2 */
/* @0x1bcb50 vcvt.f64.s32 d7, s15 */
/* @0x1bcb54 vmov r2, r3, d7 */
/* @0x1bcb58 stm r5, {r2, r3} */
/* @0x1bcb5c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bcb60 ldrsheq r1, [r9], -r12 */

/* ── FUNC 0x1bcb64 · F_LayerBackgroundGetHtiled(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x1bcb64 cmp r3, #1 */
/* @0x1bcb68 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bcb6c mov r3, #0 */
/* @0x1bcb70 mov r4, r3 */
/* @0x1bcb74 mov r5, r0 */
/* @0x1bcb78 movt r3, #0xbff0 */
/* @0x1bcb7c str r4, [r0, #0xc] */
/* @0x1bcb80 str r3, [r0, #0x4] */
/* @0x1bcb84 str r4, [r0] */
/* @0x1bcb88 ldr r6, [sp, #0x18] */
/* @0x1bcb8c beq 0x1bcba4 <_Z26F_LayerBackgroundGetHtiledR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bcb90 ldr r0, [pc, #0x70] */
/* @0x1bcb94 mov r1, r4 */
/* @0x1bcb98 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bcb9c add r0, pc, r0 */
/* @0x1bcba0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bcba4 str r4, [r0] */
/* @0x1bcba8 str r4, [r0, #0x4] */
/* @0x1bcbac bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bcbb0 mov r1, r4 */
/* @0x1bcbb4 mov r7, r0 */
/* @0x1bcbb8 mov r0, r6 */
/* @0x1bcbbc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bcbc0 mov r2, r4 */
/* @0x1bcbc4 mov r1, r0 */
/* @0x1bcbc8 mov r0, r7 */
/* @0x1bcbcc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bcbd0 cmp r0, #0 */
/* @0x1bcbd4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcbd8 ldr r3, [r0] */
/* @0x1bcbdc cmp r3, #1 */
/* @0x1bcbe0 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bcbe4 ldr r3, [r0, #0x1c] */
/* @0x1bcbe8 cmp r3, #0 */
/* @0x1bcbec popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcbf0 ldrb r2, [r3, #0x8] */
/* @0x1bcbf4 vmov s15, r2 */
/* @0x1bcbf8 vcvt.f64.u32 d7, s15 */
/* @0x1bcbfc vmov r2, r3, d7 */
/* @0x1bcc00 stm r5, {r2, r3} */
/* @0x1bcc04 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bcc08 mulseq r9, r8, r5 */

/* ── FUNC 0x1bcc0c · F_LayerBackgroundGetVtiled(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x1bcc0c cmp r3, #1 */
/* @0x1bcc10 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bcc14 mov r3, #0 */
/* @0x1bcc18 mov r4, r3 */
/* @0x1bcc1c mov r5, r0 */
/* @0x1bcc20 movt r3, #0xbff0 */
/* @0x1bcc24 str r4, [r0, #0xc] */
/* @0x1bcc28 str r3, [r0, #0x4] */
/* @0x1bcc2c str r4, [r0] */
/* @0x1bcc30 ldr r6, [sp, #0x18] */
/* @0x1bcc34 beq 0x1bcc4c <_Z26F_LayerBackgroundGetVtiledR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bcc38 ldr r0, [pc, #0x70] */
/* @0x1bcc3c mov r1, r4 */
/* @0x1bcc40 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bcc44 add r0, pc, r0 */
/* @0x1bcc48 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bcc4c str r4, [r0] */
/* @0x1bcc50 str r4, [r0, #0x4] */
/* @0x1bcc54 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bcc58 mov r1, r4 */
/* @0x1bcc5c mov r7, r0 */
/* @0x1bcc60 mov r0, r6 */
/* @0x1bcc64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bcc68 mov r2, r4 */
/* @0x1bcc6c mov r1, r0 */
/* @0x1bcc70 mov r0, r7 */
/* @0x1bcc74 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bcc78 cmp r0, #0 */
/* @0x1bcc7c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcc80 ldr r3, [r0] */
/* @0x1bcc84 cmp r3, #1 */
/* @0x1bcc88 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bcc8c ldr r3, [r0, #0x1c] */
/* @0x1bcc90 cmp r3, #0 */
/* @0x1bcc94 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcc98 ldrb r2, [r3, #0x9] */
/* @0x1bcc9c vmov s15, r2 */
/* @0x1bcca0 vcvt.f64.u32 d7, s15 */
/* @0x1bcca4 vmov r2, r3, d7 */
/* @0x1bcca8 stm r5, {r2, r3} */
/* @0x1bccac pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bccb0 andseq r1, r9, r12, lsr #10 */

/* ── FUNC 0x1bccb4 · F_LayerBackgroundGetStretch(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x1bccb4 cmp r3, #1 */
/* @0x1bccb8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bccbc mov r3, #0 */
/* @0x1bccc0 mov r4, r3 */
/* @0x1bccc4 mov r5, r0 */
/* @0x1bccc8 movt r3, #0xbff0 */
/* @0x1bcccc str r4, [r0, #0xc] */
/* @0x1bccd0 str r3, [r0, #0x4] */
/* @0x1bccd4 str r4, [r0] */
/* @0x1bccd8 ldr r6, [sp, #0x18] */
/* @0x1bccdc beq 0x1bccf4 <_Z27F_LayerBackgroundGetStretchR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bcce0 ldr r0, [pc, #0x70] */
/* @0x1bcce4 mov r1, r4 */
/* @0x1bcce8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bccec add r0, pc, r0 */
/* @0x1bccf0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bccf4 str r4, [r0] */
/* @0x1bccf8 str r4, [r0, #0x4] */
/* @0x1bccfc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bcd00 mov r1, r4 */
/* @0x1bcd04 mov r7, r0 */
/* @0x1bcd08 mov r0, r6 */
/* @0x1bcd0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bcd10 mov r2, r4 */
/* @0x1bcd14 mov r1, r0 */
/* @0x1bcd18 mov r0, r7 */
/* @0x1bcd1c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bcd20 cmp r0, #0 */
/* @0x1bcd24 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcd28 ldr r3, [r0] */
/* @0x1bcd2c cmp r3, #1 */
/* @0x1bcd30 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bcd34 ldr r3, [r0, #0x1c] */
/* @0x1bcd38 cmp r3, #0 */
/* @0x1bcd3c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcd40 ldrb r2, [r3, #0x14] */
/* @0x1bcd44 vmov s15, r2 */
/* @0x1bcd48 vcvt.f64.u32 d7, s15 */
/* @0x1bcd4c vmov r2, r3, d7 */
/* @0x1bcd50 stm r5, {r2, r3} */
/* @0x1bcd54 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bcd58 andseq r1, r9, r0, asr #9 */

/* ── FUNC 0x1bcd5c · F_LayerBackgroundGetXscale(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x1bcd5c cmp r3, #1 */
/* @0x1bcd60 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bcd64 mov r3, #0 */
/* @0x1bcd68 mov r5, r3 */
/* @0x1bcd6c mov r4, r0 */
/* @0x1bcd70 movt r3, #0xbff0 */
/* @0x1bcd74 str r5, [r0, #0xc] */
/* @0x1bcd78 str r3, [r0, #0x4] */
/* @0x1bcd7c str r5, [r0] */
/* @0x1bcd80 ldr r6, [sp, #0x18] */
/* @0x1bcd84 beq 0x1bcd9c <_Z26F_LayerBackgroundGetXscaleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bcd88 ldr r0, [pc, #0x74] */
/* @0x1bcd8c mov r1, r5 */
/* @0x1bcd90 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bcd94 add r0, pc, r0 */
/* @0x1bcd98 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bcd9c str r5, [r0] */
/* @0x1bcda0 mov r3, #0 */
/* @0x1bcda4 movt r3, #0x3ff0 */
/* @0x1bcda8 str r3, [r0, #0x4] */
/* @0x1bcdac bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bcdb0 mov r1, r5 */
/* @0x1bcdb4 mov r7, r0 */
/* @0x1bcdb8 mov r0, r6 */
/* @0x1bcdbc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bcdc0 mov r2, r5 */
/* @0x1bcdc4 mov r1, r0 */
/* @0x1bcdc8 mov r0, r7 */
/* @0x1bcdcc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer> */
/* @0x1bcdd0 cmp r0, #0 */
/* @0x1bcdd4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcdd8 ldr r3, [r0] */
/* @0x1bcddc cmp r3, #1 */
/* @0x1bcde0 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1bcde4 ldr r3, [r0, #0x1c] */
/* @0x1bcde8 cmp r3, #0 */
/* @0x1bcdec popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bcdf0 vldr s15, [r3, #12] */
/* @0x1bcdf4 vcvt.f64.f32 d6, s15 */
/* @0x1bcdf8 vmov r2, r3, d6 */
/* @0x1bcdfc stm r4, {r2, r3} */
/* @0x1bce00 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bce04 andseq r1, r9, r4, asr r4 */
