/* libyoyo.so 覆盖卡组 0030
 * 函数 0xff564..0x101a84，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xff564 · F_DsMapReplaceList(RValue&, CInstance*, CInstance*, int, RValue*) · size=332 · insn=83 */
/* @0xff564 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xff568 sub sp, sp, #8 */
/* @0xff56c add r7, sp, #4 */
/* @0xff570 mov r5, r0 */
/* @0xff574 ldr r8, [sp, #0x28] */
/* @0xff578 mov r4, #0 */
/* @0xff57c mov r0, r7 */
/* @0xff580 ldr r6, [pc, #0x10c] */
/* @0xff584 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xff588 str r4, [r5, #0xc] */
/* @0xff58c str r4, [r5] */
/* @0xff590 mov r0, r8 */
/* @0xff594 str r4, [r5, #0x4] */
/* @0xff598 mov r1, r4 */
/* @0xff59c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff5a0 add r6, pc, r6 */
/* @0xff5a4 subs r9, r0, #0 */
/* @0xff5a8 blt 0xff654 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0xff5ac ldr r3, [pc, #0xe4] */
/* @0xff5b0 ldr r3, [r6, r3] */
/* @0xff5b4 ldr r3, [r3] */
/* @0xff5b8 cmp r9, r3 */
/* @0xff5bc bge 0xff654 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0xff5c0 ldr r3, [pc, #0xd4] */
/* @0xff5c4 ldr r10, [r6, r3] */
/* @0xff5c8 ldr r3, [r10, #0x4] */
/* @0xff5cc ldr r3, [r3, r9, lsl #2] */
/* @0xff5d0 cmp r3, r4 */
/* @0xff5d4 beq 0xff654 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0xff5d8 mov r0, r8 */
/* @0xff5dc mov r1, #2 */
/* @0xff5e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff5e4 cmp r0, #0 */
/* @0xff5e8 blt 0xff674 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0xff5ec ldr r3, [pc, #0xac] */
/* @0xff5f0 ldr r3, [r6, r3] */
/* @0xff5f4 ldr r3, [r3] */
/* @0xff5f8 cmp r0, r3 */
/* @0xff5fc bge 0xff674 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0xff600 ldr r3, [pc, #0x9c] */
/* @0xff604 ldr r3, [r6, r3] */
/* @0xff608 ldr r3, [r3, #0x4] */
/* @0xff60c ldr r3, [r3, r0, lsl #2] */
/* @0xff610 cmp r3, #0 */
/* @0xff614 beq 0xff674 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0xff618 ldr r3, [r8, #0x2c] */
/* @0xff61c add r1, r8, #16 */
/* @0xff620 ldr r0, [r10, #0x4] */
/* @0xff624 add r2, r8, #32 */
/* @0xff628 bic r3, r3, #-268435456 */
/* @0xff62c orr r3, r3, #1073741824 */
/* @0xff630 ldr r0, [r0, r9, lsl #2] */
/* @0xff634 str r3, [r8, #0x2c] */
/* @0xff638 bl 0x20bc44 <_ZN7CDS_Map7ReplaceEP6RValueS1_> */
/* @0xff63c cmp r0, #0 */
/* @0xff640 movne r3, #0 */
/* @0xff644 strne r4, [r5] */
/* @0xff648 movtne r3, #0x3ff0 */
/* @0xff64c strne r3, [r5, #0x4] */
/* @0xff650 b 0xff664 <_Z18F_DsMapReplaceListR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0xff654 ldr r0, [pc, #0x4c] */
/* @0xff658 mov r1, #0 */
/* @0xff65c add r0, pc, r0 */
/* @0xff660 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff664 mov r0, r7 */
/* @0xff668 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff66c add sp, sp, #8 */
/* @0xff670 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xff674 ldr r0, [pc, #0x30] */
/* @0xff678 mov r1, #0 */
/* @0xff67c add r0, pc, r0 */
/* @0xff680 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff684 mov r0, r7 */
/* @0xff688 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff68c add sp, sp, #8 */
/* @0xff690 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xff694 .word 0x002f26b0 */
/* @0xff698 .word 0xffffc028 */
/* @0xff69c .word 0xffffbcec */
/* @0xff6a0 .word 0xffffc02c */
/* @0xff6a4 .word 0xffffc030 */
/* @0xff6a8 eoreq r8, r3, r0, lsr #11 */
/* @0xff6ac eoreq r8, r3, r12, ror #11 */

/* ── FUNC 0xff6b0 · F_DsMapReplaceMap(RValue&, CInstance*, CInstance*, int, RValue*) · size=324 · insn=81 */
/* @0xff6b0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xff6b4 sub sp, sp, #8 */
/* @0xff6b8 add r7, sp, #4 */
/* @0xff6bc mov r5, r0 */
/* @0xff6c0 ldr r9, [sp, #0x28] */
/* @0xff6c4 mov r4, #0 */
/* @0xff6c8 mov r0, r7 */
/* @0xff6cc bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xff6d0 str r4, [r5, #0xc] */
/* @0xff6d4 str r4, [r5] */
/* @0xff6d8 mov r0, r9 */
/* @0xff6dc str r4, [r5, #0x4] */
/* @0xff6e0 mov r1, r4 */
/* @0xff6e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff6e8 subs r8, r0, #0 */
/* @0xff6ec blt 0xff78c <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0xff6f0 ldr r6, [pc, #0xe8] */
/* @0xff6f4 ldr r6, [pc, r6] */
/* @0xff6f8 ldr r3, [r6] */
/* @0xff6fc cmp r8, r3 */
/* @0xff700 bge 0xff78c <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0xff704 ldr r10, [pc, #0xd8] */
/* @0xff708 ldr r10, [pc, r10] */
/* @0xff70c ldr r3, [r10, #0x4] */
/* @0xff710 ldr r3, [r3, r8, lsl #2] */
/* @0xff714 cmp r3, r4 */
/* @0xff718 beq 0xff78c <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0xff71c mov r0, r9 */
/* @0xff720 mov r1, #2 */
/* @0xff724 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff728 cmp r0, r8 */
/* @0xff72c beq 0xff7cc <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0xff730 cmp r0, #0 */
/* @0xff734 blt 0xff7ac <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0xff738 ldr r3, [r6] */
/* @0xff73c cmp r0, r3 */
/* @0xff740 bge 0xff7ac <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0xff744 ldr r3, [r10, #0x4] */
/* @0xff748 ldr r2, [r3, r0, lsl #2] */
/* @0xff74c cmp r2, #0 */
/* @0xff750 beq 0xff7ac <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0xff754 ldr r12, [r9, #0x2c] */
/* @0xff758 add r1, r9, #16 */
/* @0xff75c ldr r0, [r3, r8, lsl #2] */
/* @0xff760 add r2, r9, #32 */
/* @0xff764 bic r3, r12, #-268435456 */
/* @0xff768 orr r3, r3, #-2147483648 */
/* @0xff76c str r3, [r9, #0x2c] */
/* @0xff770 bl 0x20bc44 <_ZN7CDS_Map7ReplaceEP6RValueS1_> */
/* @0xff774 cmp r0, #0 */
/* @0xff778 movne r3, #0 */
/* @0xff77c strne r4, [r5] */
/* @0xff780 movtne r3, #0x3ff0 */
/* @0xff784 strne r3, [r5, #0x4] */
/* @0xff788 b 0xff79c <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0xff78c ldr r0, [pc, #0x54] */
/* @0xff790 mov r1, #0 */
/* @0xff794 add r0, pc, r0 */
/* @0xff798 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff79c mov r0, r7 */
/* @0xff7a0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff7a4 add sp, sp, #8 */
/* @0xff7a8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xff7ac ldr r0, [pc, #0x38] */
/* @0xff7b0 mov r1, #0 */
/* @0xff7b4 add r0, pc, r0 */
/* @0xff7b8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff7bc mov r0, r7 */
/* @0xff7c0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff7c4 add sp, sp, #8 */
/* @0xff7c8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xff7cc ldr r0, [pc, #0x1c] */
/* @0xff7d0 mov r1, r4 */
/* @0xff7d4 add r0, pc, r0 */
/* @0xff7d8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff7dc b 0xff79c <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0xff7e0 eoreq lr, lr, r4, lsl #11 */
/* @0xff7e4 eoreq lr, lr, r4, lsr r2 */
/* @0xff7e8 eoreq r8, r3, r8, ror #8 */
/* @0xff7ec .word 0x002384d4 */
/* @0xff7f0 .word 0x002384d0 */

/* ── FUNC 0xff7f4 · F_DsMapDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0xff7f4 push {r4, r5, lr} */
/* @0xff7f8 sub sp, sp, #12 */
/* @0xff7fc add r4, sp, #4 */
/* @0xff800 ldr r5, [sp, #0x18] */
/* @0xff804 mov r0, r4 */
/* @0xff808 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xff80c mov r1, #0 */
/* @0xff810 mov r0, r5 */
/* @0xff814 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff818 cmp r0, #0 */
/* @0xff81c blt 0xff864 <_Z13F_DsMapDeleteR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xff820 ldr r3, [pc, #0x5c] */
/* @0xff824 ldr r3, [pc, r3] */
/* @0xff828 ldr r3, [r3] */
/* @0xff82c cmp r0, r3 */
/* @0xff830 bge 0xff864 <_Z13F_DsMapDeleteR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xff834 ldr r3, [pc, #0x4c] */
/* @0xff838 ldr r3, [pc, r3] */
/* @0xff83c ldr r3, [r3, #0x4] */
/* @0xff840 ldr r0, [r3, r0, lsl #2] */
/* @0xff844 cmp r0, #0 */
/* @0xff848 beq 0xff864 <_Z13F_DsMapDeleteR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xff84c add r1, r5, #16 */
/* @0xff850 bl 0x20b6cc <_ZN7CDS_Map6DeleteEP6RValue> */
/* @0xff854 mov r0, r4 */
/* @0xff858 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff85c add sp, sp, #12 */
/* @0xff860 pop {r4, r5, pc} */
/* @0xff864 ldr r0, [pc, #0x20] */
/* @0xff868 mov r1, #0 */
/* @0xff86c add r0, pc, r0 */
/* @0xff870 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff874 mov r0, r4 */
/* @0xff878 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff87c add sp, sp, #12 */
/* @0xff880 pop {r4, r5, pc} */
/* @0xff884 eoreq lr, lr, r4, asr r4 */
/* @0xff888 eoreq lr, lr, r4, lsl #2 */
/* @0xff88c mlaeq r3, r0, r3, r8 */

/* ── FUNC 0xff890 · F_DsMapExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0xff890 push {r4, r5, r6, lr} */
/* @0xff894 sub sp, sp, #8 */
/* @0xff898 add r4, sp, #4 */
/* @0xff89c mov r6, r0 */
/* @0xff8a0 ldr r5, [sp, #0x18] */
/* @0xff8a4 mov r0, r4 */
/* @0xff8a8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xff8ac mov r1, #0 */
/* @0xff8b0 mov r0, r5 */
/* @0xff8b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff8b8 cmp r0, #0 */
/* @0xff8bc blt 0xff928 <_Z13F_DsMapExistsR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xff8c0 ldr r3, [pc, #0x80] */
/* @0xff8c4 ldr r3, [pc, r3] */
/* @0xff8c8 ldr r3, [r3] */
/* @0xff8cc cmp r0, r3 */
/* @0xff8d0 bge 0xff928 <_Z13F_DsMapExistsR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xff8d4 ldr r3, [pc, #0x70] */
/* @0xff8d8 ldr r3, [pc, r3] */
/* @0xff8dc ldr r3, [r3, #0x4] */
/* @0xff8e0 ldr r0, [r3, r0, lsl #2] */
/* @0xff8e4 cmp r0, #0 */
/* @0xff8e8 beq 0xff928 <_Z13F_DsMapExistsR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xff8ec add r1, r5, #16 */
/* @0xff8f0 mov r5, #0 */
/* @0xff8f4 str r5, [r6, #0xc] */
/* @0xff8f8 bl 0x203a6c <_ZN7CDS_Map6ExistsEP6RValue> */
/* @0xff8fc cmp r0, #0 */
/* @0xff900 moveq r5, r0 */
/* @0xff904 movne r3, r5 */
/* @0xff908 moveq r3, r5 */
/* @0xff90c movtne r3, #0x3ff0 */
/* @0xff910 str r5, [r6] */
/* @0xff914 mov r0, r4 */
/* @0xff918 str r3, [r6, #0x4] */
/* @0xff91c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff920 add sp, sp, #8 */
/* @0xff924 pop {r4, r5, r6, pc} */
/* @0xff928 ldr r0, [pc, #0x20] */
/* @0xff92c mov r1, #0 */
/* @0xff930 add r0, pc, r0 */
/* @0xff934 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff938 mov r0, r4 */
/* @0xff93c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff940 add sp, sp, #8 */
/* @0xff944 pop {r4, r5, r6, pc} */
/* @0xff948 .word 0x002ee3b4 */
/* @0xff94c eoreq lr, lr, r4, rrx */
/* @0xff950 eoreq r8, r3, r12, asr #5 */

/* ── FUNC 0xff954 · F_DsMapWrite(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0xff954 push {r4, r5, r6, lr} */
/* @0xff958 sub sp, sp, #8 */
/* @0xff95c mov r6, r0 */
/* @0xff960 ldr r5, [sp, #0x18] */
/* @0xff964 mov r0, sp */
/* @0xff968 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xff96c mov r1, #0 */
/* @0xff970 mov r0, r5 */
/* @0xff974 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff978 subs r2, r0, #0 */
/* @0xff97c blt 0xff9e4 <_Z12F_DsMapWriteR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xff980 ldr r3, [pc, #0x7c] */
/* @0xff984 ldr r3, [pc, r3] */
/* @0xff988 ldr r3, [r3] */
/* @0xff98c cmp r2, r3 */
/* @0xff990 bge 0xff9e4 <_Z12F_DsMapWriteR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xff994 ldr r3, [pc, #0x6c] */
/* @0xff998 ldr r3, [pc, r3] */
/* @0xff99c ldr r3, [r3, #0x4] */
/* @0xff9a0 ldr r1, [r3, r2, lsl #2] */
/* @0xff9a4 cmp r1, #0 */
/* @0xff9a8 beq 0xff9e4 <_Z12F_DsMapWriteR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xff9ac add r1, sp, #8 */
/* @0xff9b0 mov r0, #0 */
/* @0xff9b4 str r0, [r1, #-0x4]! */
/* @0xff9b8 ldr r0, [r3, r2, lsl #2] */
/* @0xff9bc bl 0x203948 <_ZN7CDS_Map13WriteToStringERPKc> */
/* @0xff9c0 ldr r1, [sp, #0x4] */
/* @0xff9c4 mov r0, r6 */
/* @0xff9c8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xff9cc ldr r0, [sp, #0x4] */
/* @0xff9d0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xff9d4 mov r0, sp */
/* @0xff9d8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff9dc add sp, sp, #8 */
/* @0xff9e0 pop {r4, r5, r6, pc} */
/* @0xff9e4 ldr r0, [pc, #0x20] */
/* @0xff9e8 mov r1, #0 */
/* @0xff9ec add r0, pc, r0 */
/* @0xff9f0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff9f4 mov r0, sp */
/* @0xff9f8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff9fc add sp, sp, #8 */
/* @0xffa00 pop {r4, r5, r6, pc} */
/* @0xffa04 .word 0x002ee2f4 */
/* @0xffa08 eoreq sp, lr, r4, lsr #31 */
/* @0xffa0c eoreq r8, r3, r0, lsl r2 */

/* ── FUNC 0xffa10 · F_DsMapRead(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0xffa10 push {r4, r5, r6, r7, r8, lr} */
/* @0xffa14 sub sp, sp, #8 */
/* @0xffa18 add r6, sp, #4 */
/* @0xffa1c mov r7, r3 */
/* @0xffa20 ldr r5, [sp, #0x20] */
/* @0xffa24 mov r0, r6 */
/* @0xffa28 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xffa2c mov r1, #0 */
/* @0xffa30 mov r0, r5 */
/* @0xffa34 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xffa38 mov r1, #1 */
/* @0xffa3c mov r4, r0 */
/* @0xffa40 mov r0, r5 */
/* @0xffa44 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xffa48 cmp r7, #3 */
/* @0xffa4c movne r2, #0 */
/* @0xffa50 mov r8, r0 */
/* @0xffa54 beq 0xffac4 <_Z11F_DsMapReadR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xffa58 cmp r4, #0 */
/* @0xffa5c blt 0xffaa4 <_Z11F_DsMapReadR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0xffa60 ldr r3, [pc, #0x78] */
/* @0xffa64 ldr r3, [pc, r3] */
/* @0xffa68 ldr r3, [r3] */
/* @0xffa6c cmp r4, r3 */
/* @0xffa70 bge 0xffaa4 <_Z11F_DsMapReadR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0xffa74 ldr r3, [pc, #0x68] */
/* @0xffa78 ldr r3, [pc, r3] */
/* @0xffa7c ldr r3, [r3, #0x4] */
/* @0xffa80 ldr r0, [r3, r4, lsl #2] */
/* @0xffa84 cmp r0, #0 */
/* @0xffa88 beq 0xffaa4 <_Z11F_DsMapReadR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0xffa8c mov r1, r8 */
/* @0xffa90 bl 0x20de08 <_ZN7CDS_Map14ReadFromStringEPKcb> */
/* @0xffa94 mov r0, r6 */
/* @0xffa98 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xffa9c add sp, sp, #8 */
/* @0xffaa0 pop {r4, r5, r6, r7, r8, pc} */
/* @0xffaa4 ldr r0, [pc, #0x3c] */
/* @0xffaa8 mov r1, #0 */
/* @0xffaac add r0, pc, r0 */
/* @0xffab0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xffab4 mov r0, r6 */
/* @0xffab8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xffabc add sp, sp, #8 */
/* @0xffac0 pop {r4, r5, r6, r7, r8, pc} */
/* @0xffac4 mov r0, r5 */
/* @0xffac8 mov r1, #2 */
/* @0xffacc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xffad0 cmp r0, #0 */
/* @0xffad4 movle r2, #0 */
/* @0xffad8 movgt r2, #1 */
/* @0xffadc b 0xffa58 <_Z11F_DsMapReadR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0xffae0 eoreq lr, lr, r4, lsl r2 */
/* @0xffae4 eoreq sp, lr, r4, asr #29 */
/* @0xffae8 eoreq r8, r3, r0, asr r1 */

/* ── FUNC 0xffaec · F_DsExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=432 · insn=108 */
/* @0xffaec push {r4, r5, r6, r7, r8, lr} */
/* @0xffaf0 sub sp, sp, #8 */
/* @0xffaf4 add r6, sp, #4 */
/* @0xffaf8 mov r4, r0 */
/* @0xffafc ldr r7, [sp, #0x20] */
/* @0xffb00 mov r0, r6 */
/* @0xffb04 ldr r5, [pc, #0x15c] */
/* @0xffb08 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xffb0c mov r1, #0 */
/* @0xffb10 mov r3, r1 */
/* @0xffb14 str r1, [r4, #0xc] */
/* @0xffb18 movt r3, #0x3ff0 */
/* @0xffb1c mov r0, r7 */
/* @0xffb20 stm r4, {r1, r3} */
/* @0xffb24 add r5, pc, r5 */
/* @0xffb28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xffb2c mov r1, #1 */
/* @0xffb30 mov r8, r0 */
/* @0xffb34 mov r0, r7 */
/* @0xffb38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xffb3c sub r0, r0, #1 */
/* @0xffb40 cmp r0, #5 */
/* @0xffb44 addls pc, pc, r0, lsl #2 */
/* @0xffb48 b 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffb4c b 0xffbb4 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0xffb50 b 0xffbd8 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0xffb54 b 0xffbfc <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0xffb58 b 0xffc20 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0xffb5c b 0xffc44 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0xffb60 b 0xffb64 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xffb64 cmp r8, #0 */
/* @0xffb68 blt 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffb6c ldr r3, [pc, #0xf8] */
/* @0xffb70 ldr r3, [r5, r3] */
/* @0xffb74 ldr r3, [r3] */
/* @0xffb78 cmp r8, r3 */
/* @0xffb7c bge 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffb80 ldr r3, [pc, #0xe8] */
/* @0xffb84 ldr r3, [r5, r3] */
/* @0xffb88 ldr r3, [r3, #0x4] */
/* @0xffb8c ldr r3, [r3, r8, lsl #2] */
/* @0xffb90 cmp r3, #0 */
/* @0xffb94 bne 0xffba4 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xffb98 mov r3, #0 */
/* @0xffb9c str r3, [r4] */
/* @0xffba0 str r3, [r4, #0x4] */
/* @0xffba4 mov r0, r6 */
/* @0xffba8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xffbac add sp, sp, #8 */
/* @0xffbb0 pop {r4, r5, r6, r7, r8, pc} */
/* @0xffbb4 cmp r8, #0 */
/* @0xffbb8 blt 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffbbc ldr r3, [pc, #0xb0] */
/* @0xffbc0 ldr r3, [r5, r3] */
/* @0xffbc4 ldr r3, [r3] */
/* @0xffbc8 cmp r8, r3 */
/* @0xffbcc bge 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffbd0 ldr r3, [pc, #0xa0] */
/* @0xffbd4 b 0xffb84 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xffbd8 cmp r8, #0 */
/* @0xffbdc blt 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffbe0 ldr r3, [pc, #0x94] */
/* @0xffbe4 ldr r3, [r5, r3] */
/* @0xffbe8 ldr r3, [r3] */
/* @0xffbec cmp r8, r3 */
/* @0xffbf0 bge 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffbf4 ldr r3, [pc, #0x84] */
/* @0xffbf8 b 0xffb84 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xffbfc cmp r8, #0 */
/* @0xffc00 blt 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffc04 ldr r3, [pc, #0x78] */
/* @0xffc08 ldr r3, [r5, r3] */
/* @0xffc0c ldr r3, [r3] */
/* @0xffc10 cmp r8, r3 */
/* @0xffc14 bge 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffc18 ldr r3, [pc, #0x68] */
/* @0xffc1c b 0xffb84 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xffc20 cmp r8, #0 */
/* @0xffc24 blt 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffc28 ldr r3, [pc, #0x5c] */
/* @0xffc2c ldr r3, [r5, r3] */
/* @0xffc30 ldr r3, [r3] */
/* @0xffc34 cmp r8, r3 */
/* @0xffc38 bge 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffc3c ldr r3, [pc, #0x4c] */
/* @0xffc40 b 0xffb84 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xffc44 cmp r8, #0 */
/* @0xffc48 blt 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffc4c ldr r3, [pc, #0x40] */
/* @0xffc50 ldr r3, [r5, r3] */
/* @0xffc54 ldr r3, [r3] */
/* @0xffc58 cmp r8, r3 */
/* @0xffc5c bge 0xffb98 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xffc60 ldr r3, [pc, #0x30] */
/* @0xffc64 b 0xffb84 <_Z10F_DsExistsR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xffc68 eoreq r2, pc, r12, lsr #2 */
/* @0xffc6c .word 0xffffc224 */
/* @0xffc70 .word 0xffffc228 */
/* @0xffc74 .word 0xffffc028 */
/* @0xffc78 .word 0xffffbcec */
/* @0xffc7c .word 0xffffc02c */
/* @0xffc80 .word 0xffffc030 */
/* @0xffc84 .word 0xffffc22c */
/* @0xffc88 .word 0xffffc230 */
/* @0xffc8c .word 0xffffc21c */
/* @0xffc90 .word 0xffffc220 */
/* @0xffc94 .word 0xffffc234 */
/* @0xffc98 .word 0xffffc238 */

/* ── FUNC 0xffc9c · GetTheStacks(int&) · size=40 · insn=10 */
/* @0xffc9c ldr r2, [pc, #0x18] */
/* @0xffca0 ldr r3, [pc, #0x18] */
/* @0xffca4 ldr r2, [pc, r2] */
/* @0xffca8 ldr r3, [pc, r3] */
/* @0xffcac ldr r2, [r2] */
/* @0xffcb0 str r2, [r0] */
/* @0xffcb4 ldr r0, [r3, #0x4] */
/* @0xffcb8 bx lr */
/* @0xffcbc .word 0x002ee1d8 */
/* @0xffcc0 .word 0x002ee1d8 */

/* ── FUNC 0xffcc4 · YYGML_ds_stack_create() · size=240 · insn=60 */
/* @0xffcc4 ldr r3, [pc, #0xd8] */
/* @0xffcc8 ldr r2, [pc, #0xd8] */
/* @0xffccc add r3, pc, r3 */
/* @0xffcd0 push {r4, r5, r6, r7, r8, lr} */
/* @0xffcd4 ldr r8, [r3, r2] */
/* @0xffcd8 ldr r2, [pc, #0xcc] */
/* @0xffcdc ldr r5, [r8] */
/* @0xffce0 ldr r7, [r3, r2] */
/* @0xffce4 cmp r5, #0 */
/* @0xffce8 ble 0xffd20 <_Z21YYGML_ds_stack_createv+0x5c> */
/* @0xffcec ldr r3, [r7, #0x4] */
/* @0xffcf0 ldr r6, [r3] */
/* @0xffcf4 cmp r6, #0 */
/* @0xffcf8 beq 0xffd9c <_Z21YYGML_ds_stack_createv+0xd8> */
/* @0xffcfc mov r4, #0 */
/* @0xffd00 b 0xffd10 <_Z21YYGML_ds_stack_createv+0x4c> */
/* @0xffd04 ldr r2, [r3, #0x4]! */
/* @0xffd08 cmp r2, #0 */
/* @0xffd0c beq 0xffd40 <_Z21YYGML_ds_stack_createv+0x7c> */
/* @0xffd10 add r4, r4, #1 */
/* @0xffd14 cmp r4, r5 */
/* @0xffd18 lsl r6, r4, #2 */
/* @0xffd1c bne 0xffd04 <_Z21YYGML_ds_stack_createv+0x40> */
/* @0xffd20 ldr r3, [r7] */
/* @0xffd24 cmp r5, r3 */
/* @0xffd28 movlt r3, r5 */
/* @0xffd2c bge 0xffd60 <_Z21YYGML_ds_stack_createv+0x9c> */
/* @0xffd30 lsl r6, r5, #2 */
/* @0xffd34 mov r4, r5 */
/* @0xffd38 add r3, r3, #1 */
/* @0xffd3c str r3, [r8] */
/* @0xffd40 mov r0, #16 */
/* @0xffd44 bl 0x27c524 <_Znwj> */
/* @0xffd48 mov r5, r0 */
/* @0xffd4c bl 0x20f4dc <_ZN9CDS_StackC2Ev> */
/* @0xffd50 ldr r3, [r7, #0x4] */
/* @0xffd54 mov r0, r4 */
/* @0xffd58 str r5, [r3, r6] */
/* @0xffd5c pop {r4, r5, r6, r7, r8, pc} */
/* @0xffd60 add r1, r5, #16 */
/* @0xffd64 ldr r2, [pc, #0x44] */
/* @0xffd68 mov r3, #145 */
/* @0xffd6c add r0, r7, #4 */
/* @0xffd70 add r2, pc, r2 */
/* @0xffd74 lsl r1, r1, #2 */
/* @0xffd78 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xffd7c ldr r3, [r8] */
/* @0xffd80 lsl r6, r5, #2 */
/* @0xffd84 mov r4, r5 */
/* @0xffd88 add r2, r3, #16 */
/* @0xffd8c add r3, r3, #1 */
/* @0xffd90 str r2, [r7] */
/* @0xffd94 str r3, [r8] */
/* @0xffd98 b 0xffd40 <_Z21YYGML_ds_stack_createv+0x7c> */
/* @0xffd9c mov r4, r6 */
/* @0xffda0 b 0xffd40 <_Z21YYGML_ds_stack_createv+0x7c> */
/* @0xffda4 eoreq r1, pc, r4, lsl #31 */
/* @0xffda8 .word 0xffffc22c */
/* @0xffdac .word 0xffffc230 */
/* @0xffdb0 eoreq r7, r3, r12, lsr #28 */

/* ── FUNC 0xffdb4 · F_DsStackCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0xffdb4 push {r4, lr} */
/* @0xffdb8 mov r3, #0 */
/* @0xffdbc str r3, [r0, #0xc] */
/* @0xffdc0 mov r4, r0 */
/* @0xffdc4 bl 0xffcc4 <_Z21YYGML_ds_stack_createv> */
/* @0xffdc8 vmov s15, r0 */
/* @0xffdcc vcvt.f64.s32 d7, s15 */
/* @0xffdd0 vmov r0, r1, d7 */
/* @0xffdd4 vmov r2, s14 */
/* @0xffdd8 mov r3, r1 */
/* @0xffddc stm r4, {r2, r3} */
/* @0xffde0 pop {r4, pc} */

/* ── FUNC 0xffde4 · YYGML_ds_stack_push(int, YYRValue**) · size=160 · insn=40 */
/* @0xffde4 push {r4, r5, r6, r7, r8, lr} */
/* @0xffde8 mov r5, r1 */
/* @0xffdec mov r6, r0 */
/* @0xffdf0 mov r1, #0 */
/* @0xffdf4 ldr r0, [r5] */
/* @0xffdf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xffdfc cmp r6, #1 */
/* @0xffe00 movgt r3, #0 */
/* @0xffe04 movle r3, #1 */
/* @0xffe08 orrs r3, r3, r0, lsr #31 */
/* @0xffe0c bne 0xffe64 <_Z19YYGML_ds_stack_pushiPP8YYRValue+0x80> */
/* @0xffe10 ldr r3, [pc, #0x60] */
/* @0xffe14 ldr r3, [pc, r3] */
/* @0xffe18 ldr r3, [r3] */
/* @0xffe1c cmp r0, r3 */
/* @0xffe20 bge 0xffe64 <_Z19YYGML_ds_stack_pushiPP8YYRValue+0x80> */
/* @0xffe24 ldr r7, [pc, #0x50] */
/* @0xffe28 lsl r8, r0, #2 */
/* @0xffe2c ldr r7, [pc, r7] */
/* @0xffe30 ldr r3, [r7, #0x4] */
/* @0xffe34 ldr r0, [r3, r0, lsl #2] */
/* @0xffe38 cmp r0, #0 */
/* @0xffe3c movne r4, #1 */
/* @0xffe40 beq 0xffe64 <_Z19YYGML_ds_stack_pushiPP8YYRValue+0x80> */
/* @0xffe44 add r4, r4, #1 */
/* @0xffe48 ldr r1, [r5, #0x4]! */
/* @0xffe4c bl 0x20566c <_ZN9CDS_Stack4PushEP6RValue> */
/* @0xffe50 cmp r6, r4 */
/* @0xffe54 pople {r4, r5, r6, r7, r8, pc} */
/* @0xffe58 ldr r3, [r7, #0x4] */
/* @0xffe5c ldr r0, [r3, r8] */
/* @0xffe60 b 0xffe44 <_Z19YYGML_ds_stack_pushiPP8YYRValue+0x60> */
/* @0xffe64 ldr r0, [pc, #0x14] */
/* @0xffe68 mov r1, #0 */
/* @0xffe6c pop {r4, r5, r6, r7, r8, lr} */
/* @0xffe70 add r0, pc, r0 */
/* @0xffe74 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xffe78 eoreq lr, lr, r8, rrx */
/* @0xffe7c eoreq lr, lr, r4, asr r0 */
/* @0xffe80 eoreq r7, r3, r12, lsl #27 */

/* ── FUNC 0xffe84 · YYGML_ds_stack_pop(int) · size=100 · insn=25 */
/* @0xffe84 cmp r0, #0 */
/* @0xffe88 push {r3, lr} */
/* @0xffe8c blt 0xffec4 <_Z18YYGML_ds_stack_popi+0x40> */
/* @0xffe90 ldr r3, [pc, #0x44] */
/* @0xffe94 ldr r3, [pc, r3] */
/* @0xffe98 ldr r3, [r3] */
/* @0xffe9c cmp r0, r3 */
/* @0xffea0 bge 0xffec4 <_Z18YYGML_ds_stack_popi+0x40> */
/* @0xffea4 ldr r3, [pc, #0x34] */
/* @0xffea8 ldr r3, [pc, r3] */
/* @0xffeac ldr r3, [r3, #0x4] */
/* @0xffeb0 ldr r0, [r3, r0, lsl #2] */
/* @0xffeb4 cmp r0, #0 */
/* @0xffeb8 beq 0xffec4 <_Z18YYGML_ds_stack_popi+0x40> */
/* @0xffebc pop {r3, lr} */
/* @0xffec0 b 0x202d00 <_ZN9CDS_Stack3PopEv> */
/* @0xffec4 ldr r0, [pc, #0x18] */
/* @0xffec8 mov r1, #0 */
/* @0xffecc add r0, pc, r0 */
/* @0xffed0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xffed4 mov r0, #0 */
/* @0xffed8 pop {r3, pc} */
/* @0xffedc eoreq sp, lr, r8, ror #31 */
/* @0xffee0 .word 0x002edfd8 */
/* @0xffee4 eoreq r7, r3, r0, lsr sp */

/* ── FUNC 0xffee8 · GetTheQueues(int&) · size=40 · insn=10 */
/* @0xffee8 ldr r2, [pc, #0x18] */
/* @0xffeec ldr r3, [pc, #0x18] */
/* @0xffef0 ldr r2, [pc, r2] */
/* @0xffef4 ldr r3, [pc, r3] */
/* @0xffef8 ldr r2, [r2] */
/* @0xffefc str r2, [r0] */
/* @0xfff00 ldr r0, [r3, #0x4] */
/* @0xfff04 bx lr */
/* @0xfff08 eoreq sp, lr, r12, ror pc */
/* @0xfff0c eoreq sp, lr, r12, ror pc */

/* ── FUNC 0xfff10 · FindFreeDsListIndex() · size=180 · insn=45 */
/* @0xfff10 ldr r3, [pc, #0x9c] */
/* @0xfff14 ldr r2, [pc, #0x9c] */
/* @0xfff18 add r3, pc, r3 */
/* @0xfff1c push {r4, r5, r6, lr} */
/* @0xfff20 ldr r6, [r3, r2] */
/* @0xfff24 ldr r2, [pc, #0x90] */
/* @0xfff28 ldr r4, [r6] */
/* @0xfff2c ldr r5, [r3, r2] */
/* @0xfff30 cmp r4, #0 */
/* @0xfff34 ble 0xfff68 <_Z19FindFreeDsListIndexv+0x58> */
/* @0xfff38 ldr r3, [r5, #0x4] */
/* @0xfff3c ldr r0, [r3] */
/* @0xfff40 cmp r0, #0 */
/* @0xfff44 popeq {r4, r5, r6, pc} */
/* @0xfff48 mov r0, #0 */
/* @0xfff4c b 0xfff5c <_Z19FindFreeDsListIndexv+0x4c> */
/* @0xfff50 ldr r2, [r3, #0x4]! */
/* @0xfff54 cmp r2, #0 */
/* @0xfff58 popeq {r4, r5, r6, pc} */
/* @0xfff5c add r0, r0, #1 */
/* @0xfff60 cmp r0, r4 */
/* @0xfff64 bne 0xfff50 <_Z19FindFreeDsListIndexv+0x40> */
/* @0xfff68 ldr r3, [r5] */
/* @0xfff6c cmp r4, r3 */
/* @0xfff70 movlt r3, r4 */
/* @0xfff74 bge 0xfff88 <_Z19FindFreeDsListIndexv+0x78> */
/* @0xfff78 add r3, r3, #1 */
/* @0xfff7c mov r0, r4 */
/* @0xfff80 str r3, [r6] */
/* @0xfff84 pop {r4, r5, r6, pc} */
/* @0xfff88 add r1, r4, #16 */
/* @0xfff8c ldr r2, [pc, #0x2c] */
/* @0xfff90 movw r3, #0x246 */
/* @0xfff94 add r0, r5, #4 */
/* @0xfff98 add r2, pc, r2 */
/* @0xfff9c lsl r1, r1, #2 */
/* @0xfffa0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xfffa4 ldr r3, [r6] */
/* @0xfffa8 add r2, r3, #16 */
/* @0xfffac str r2, [r5] */
/* @0xfffb0 b 0xfff78 <_Z19FindFreeDsListIndexv+0x68> */
/* @0xfffb4 eoreq r1, pc, r8, lsr sp */
/* @0xfffb8 .word 0xffffc02c */
/* @0xfffbc .word 0xffffc030 */
/* @0xfffc0 eoreq r7, r3, r4, lsl #24 */

/* ── FUNC 0xfffc4 · F_DsListCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0xfffc4 push {r4, r5, r6, lr} */
/* @0xfffc8 mov r4, r0 */
/* @0xfffcc bl 0xfff10 <_Z19FindFreeDsListIndexv> */
/* @0xfffd0 mov r5, r0 */
/* @0xfffd4 mov r0, #16 */
/* @0xfffd8 bl 0x27c524 <_Znwj> */
/* @0xfffdc mov r6, r0 */
/* @0xfffe0 bl 0x202ff8 <_ZN8CDS_ListC2Ev> */
/* @0xfffe4 vmov s15, r5 */
/* @0xfffe8 ldr r1, [pc, #0x20] */
/* @0xfffec mov r0, #0 */
/* @0xffff0 vcvt.f64.s32 d7, s15 */
/* @0xffff4 ldr r1, [pc, r1] */
/* @0xffff8 ldr r1, [r1, #0x4] */
/* @0xffffc str r6, [r1, r5, lsl #2] */
/* @0x100000 str r0, [r4, #0xc] */
/* @0x100004 vmov r2, r3, d7 */
/* @0x100008 stm r4, {r2, r3} */
/* @0x10000c pop {r4, r5, r6, pc} */
/* @0x100010 eoreq sp, lr, r12, lsl #25 */

/* ── FUNC 0x100014 · FindFreeDsMapIndex() · size=224 · insn=56 */
/* @0x100014 push {r4, r5, r6, r7, r8, lr} */
/* @0x100018 sub sp, sp, #8 */
/* @0x10001c add r6, sp, #4 */
/* @0x100020 ldr r4, [pc, #0xbc] */
/* @0x100024 mov r0, r6 */
/* @0x100028 add r4, pc, r4 */
/* @0x10002c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x100030 ldr r3, [pc, #0xb0] */
/* @0x100034 ldr r8, [r4, r3] */
/* @0x100038 ldr r3, [pc, #0xac] */
/* @0x10003c ldr r5, [r8] */
/* @0x100040 ldr r7, [r4, r3] */
/* @0x100044 cmp r5, #0 */
/* @0x100048 ble 0x10007c <_Z18FindFreeDsMapIndexv+0x68> */
/* @0x10004c ldr r3, [r7, #0x4] */
/* @0x100050 ldr r4, [r3] */
/* @0x100054 cmp r4, #0 */
/* @0x100058 beq 0x100098 <_Z18FindFreeDsMapIndexv+0x84> */
/* @0x10005c mov r4, #0 */
/* @0x100060 b 0x100070 <_Z18FindFreeDsMapIndexv+0x5c> */
/* @0x100064 ldr r2, [r3, #0x4]! */
/* @0x100068 cmp r2, #0 */
/* @0x10006c beq 0x100098 <_Z18FindFreeDsMapIndexv+0x84> */
/* @0x100070 add r4, r4, #1 */
/* @0x100074 cmp r4, r5 */
/* @0x100078 bne 0x100064 <_Z18FindFreeDsMapIndexv+0x50> */
/* @0x10007c ldr r3, [r7] */
/* @0x100080 cmp r5, r3 */
/* @0x100084 movlt r3, r5 */
/* @0x100088 bge 0x1000ac <_Z18FindFreeDsMapIndexv+0x98> */
/* @0x10008c mov r4, r5 */
/* @0x100090 add r3, r3, #1 */
/* @0x100094 str r3, [r8] */
/* @0x100098 mov r0, r6 */
/* @0x10009c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1000a0 mov r0, r4 */
/* @0x1000a4 add sp, sp, #8 */
/* @0x1000a8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1000ac add r1, r5, #16 */
/* @0x1000b0 ldr r2, [pc, #0x38] */
/* @0x1000b4 movw r3, #0x3aa */
/* @0x1000b8 add r0, r7, #4 */
/* @0x1000bc add r2, pc, r2 */
/* @0x1000c0 lsl r1, r1, #2 */
/* @0x1000c4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1000c8 ldr r3, [r8] */
/* @0x1000cc mov r4, r5 */
/* @0x1000d0 add r2, r3, #16 */
/* @0x1000d4 add r3, r3, #1 */
/* @0x1000d8 str r2, [r7] */
/* @0x1000dc str r3, [r8] */
/* @0x1000e0 b 0x100098 <_Z18FindFreeDsMapIndexv+0x84> */
/* @0x1000e4 eoreq r1, pc, r8, lsr #24 */
/* @0x1000e8 .word 0xffffc028 */
/* @0x1000ec .word 0xffffbcec */
/* @0x1000f0 eoreq r7, r3, r0, ror #21 */

/* ── FUNC 0x1000f4 · F_DsMapCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x1000f4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1000f8 sub sp, sp, #8 */
/* @0x1000fc add r5, sp, #4 */
/* @0x100100 mov r4, r0 */
/* @0x100104 mov r7, r3 */
/* @0x100108 mov r0, r5 */
/* @0x10010c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x100110 bl 0x100014 <_Z18FindFreeDsMapIndexv> */
/* @0x100114 cmp r7, #1 */
/* @0x100118 mov r6, r0 */
/* @0x10011c beq 0x100168 <_Z13F_DsMapCreateR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x100120 mov r0, #4 */
/* @0x100124 bl 0x27c524 <_Znwj> */
/* @0x100128 mov r7, r0 */
/* @0x10012c bl 0x203624 <_ZN7CDS_MapC2Ev> */
/* @0x100130 ldr r3, [pc, #0x68] */
/* @0x100134 ldr r3, [pc, r3] */
/* @0x100138 ldr r3, [r3, #0x4] */
/* @0x10013c str r7, [r3, r6, lsl #2] */
/* @0x100140 vmov s15, r6 */
/* @0x100144 mov r1, #0 */
/* @0x100148 mov r0, r5 */
/* @0x10014c str r1, [r4, #0xc] */
/* @0x100150 vcvt.f64.s32 d7, s15 */
/* @0x100154 vmov r2, r3, d7 */
/* @0x100158 stm r4, {r2, r3} */
/* @0x10015c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x100160 add sp, sp, #8 */
/* @0x100164 pop {r4, r5, r6, r7, r8, pc} */
/* @0x100168 mov r1, #0 */
/* @0x10016c ldr r0, [sp, #0x20] */
/* @0x100170 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x100174 mov r8, r0 */
/* @0x100178 mov r0, #4 */
/* @0x10017c bl 0x27c524 <_Znwj> */
/* @0x100180 mov r1, r8 */
/* @0x100184 mov r7, r0 */
/* @0x100188 bl 0x203680 <_ZN7CDS_MapC2Ei> */
/* @0x10018c ldr r3, [pc, #0x10] */
/* @0x100190 ldr r3, [pc, r3] */
/* @0x100194 ldr r3, [r3, #0x4] */
/* @0x100198 str r7, [r3, r6, lsl #2] */
/* @0x10019c b 0x100140 <_Z13F_DsMapCreateR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x1001a0 eoreq sp, lr, r8, lsl #16 */
/* @0x1001a4 eoreq sp, lr, r12, lsr #15 */

/* ── FUNC 0x1001a8 · YYGML_ds_map_add(int, YYRValue const&, YYRValue const&) · size=156 · insn=39 */
/* @0x1001a8 push {r4, r5, r6, r7, lr} */
/* @0x1001ac sub sp, sp, #12 */
/* @0x1001b0 add r5, sp, #4 */
/* @0x1001b4 mov r4, r0 */
/* @0x1001b8 mov r7, r1 */
/* @0x1001bc mov r6, r2 */
/* @0x1001c0 mov r0, r5 */
/* @0x1001c4 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x1001c8 cmp r4, #0 */
/* @0x1001cc blt 0x100210 <_Z16YYGML_ds_map_addiRK8YYRValueS1_+0x68> */
/* @0x1001d0 ldr r3, [pc, #0x60] */
/* @0x1001d4 ldr r3, [pc, r3] */
/* @0x1001d8 ldr r3, [r3] */
/* @0x1001dc cmp r4, r3 */
/* @0x1001e0 bge 0x100210 <_Z16YYGML_ds_map_addiRK8YYRValueS1_+0x68> */
/* @0x1001e4 ldr r3, [pc, #0x50] */
/* @0x1001e8 ldr r3, [pc, r3] */
/* @0x1001ec ldr r3, [r3, #0x4] */
/* @0x1001f0 ldr r0, [r3, r4, lsl #2] */
/* @0x1001f4 cmp r0, #0 */
/* @0x1001f8 beq 0x100210 <_Z16YYGML_ds_map_addiRK8YYRValueS1_+0x68> */
/* @0x1001fc mov r1, r7 */
/* @0x100200 mov r2, r6 */
/* @0x100204 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x100208 mov r4, r0 */
/* @0x10020c b 0x100224 <_Z16YYGML_ds_map_addiRK8YYRValueS1_+0x7c> */
/* @0x100210 ldr r0, [pc, #0x28] */
/* @0x100214 mov r1, r4 */
/* @0x100218 mov r4, #0 */
/* @0x10021c add r0, pc, r0 */
/* @0x100220 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x100224 mov r0, r5 */
/* @0x100228 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x10022c mov r0, r4 */
/* @0x100230 add sp, sp, #12 */
/* @0x100234 pop {r4, r5, r6, r7, pc} */
/* @0x100238 eoreq sp, lr, r4, lsr #21 */
/* @0x10023c eoreq sp, lr, r4, asr r7 */
/* @0x100240 eoreq r7, r3, r12, lsr #21 */

/* ── FUNC 0x100244 · GetThePriorityQueues(int&) · size=40 · insn=10 */
/* @0x100244 ldr r2, [pc, #0x18] */
/* @0x100248 ldr r3, [pc, #0x18] */
/* @0x10024c ldr r2, [pc, r2] */
/* @0x100250 ldr r3, [pc, r3] */
/* @0x100254 ldr r2, [r2] */
/* @0x100258 str r2, [r0] */
/* @0x10025c ldr r0, [r3, #0x4] */
/* @0x100260 bx lr */
/* @0x100264 eoreq sp, lr, r8, lsr #24 */
/* @0x100268 eoreq sp, lr, r8, lsr #24 */

/* ── FUNC 0x10026c · GetTheGrids(int&) · size=40 · insn=10 */
/* @0x10026c ldr r2, [pc, #0x18] */
/* @0x100270 ldr r3, [pc, #0x18] */
/* @0x100274 ldr r2, [pc, r2] */
/* @0x100278 ldr r3, [pc, r3] */
/* @0x10027c ldr r2, [r2] */
/* @0x100280 str r2, [r0] */
/* @0x100284 ldr r0, [r3, #0x4] */
/* @0x100288 bx lr */
/* @0x10028c eoreq sp, lr, r0, lsl r12 */
/* @0x100290 eoreq sp, lr, r0, lsl r12 */

/* ── FUNC 0x100294 · YYGML_ds_grid_create(int, int) · size=256 · insn=64 */
/* @0x100294 ldr r3, [pc, #0xe8] */
/* @0x100298 ldr r2, [pc, #0xe8] */
/* @0x10029c add r3, pc, r3 */
/* @0x1002a0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1002a4 mov r7, r0 */
/* @0x1002a8 ldr r9, [r3, r2] */
/* @0x1002ac mov r8, r1 */
/* @0x1002b0 ldr r2, [pc, #0xd4] */
/* @0x1002b4 ldr r5, [r9] */
/* @0x1002b8 ldr r10, [r3, r2] */
/* @0x1002bc cmp r5, #0 */
/* @0x1002c0 ble 0x1002f8 <_Z20YYGML_ds_grid_createii+0x64> */
/* @0x1002c4 ldr r3, [r10, #0x4] */
/* @0x1002c8 ldr r6, [r3] */
/* @0x1002cc cmp r6, #0 */
/* @0x1002d0 beq 0x10037c <_Z20YYGML_ds_grid_createii+0xe8> */
/* @0x1002d4 mov r4, #0 */
/* @0x1002d8 b 0x1002e8 <_Z20YYGML_ds_grid_createii+0x54> */
/* @0x1002dc ldr r12, [r3, #0x4]! */
/* @0x1002e0 cmp r12, #0 */
/* @0x1002e4 beq 0x100318 <_Z20YYGML_ds_grid_createii+0x84> */
/* @0x1002e8 add r4, r4, #1 */
/* @0x1002ec cmp r4, r5 */
/* @0x1002f0 lsl r6, r4, #2 */
/* @0x1002f4 bne 0x1002dc <_Z20YYGML_ds_grid_createii+0x48> */
/* @0x1002f8 ldr r3, [r10] */
/* @0x1002fc cmp r5, r3 */
/* @0x100300 movlt r3, r5 */
/* @0x100304 bge 0x100340 <_Z20YYGML_ds_grid_createii+0xac> */
/* @0x100308 lsl r6, r5, #2 */
/* @0x10030c mov r4, r5 */
/* @0x100310 add r3, r3, #1 */
/* @0x100314 str r3, [r9] */
/* @0x100318 mov r0, #12 */
/* @0x10031c bl 0x27c524 <_Znwj> */
/* @0x100320 mov r1, r7 */
/* @0x100324 mov r2, r8 */
/* @0x100328 mov r5, r0 */
/* @0x10032c bl 0x20b10c <_ZN8CDS_GridC2Eii> */
/* @0x100330 ldr r3, [r10, #0x4] */
/* @0x100334 mov r0, r4 */
/* @0x100338 str r5, [r3, r6] */
/* @0x10033c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x100340 add r1, r5, #16 */
/* @0x100344 ldr r2, [pc, #0x44] */
/* @0x100348 mov r3, #2304 */
/* @0x10034c add r0, r10, #4 */
/* @0x100350 add r2, pc, r2 */
/* @0x100354 lsl r1, r1, #2 */
/* @0x100358 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x10035c ldr r3, [r9] */
/* @0x100360 lsl r6, r5, #2 */
/* @0x100364 mov r4, r5 */
/* @0x100368 add r2, r3, #16 */
/* @0x10036c add r3, r3, #1 */
/* @0x100370 str r2, [r10] */
/* @0x100374 str r3, [r9] */
/* @0x100378 b 0x100318 <_Z20YYGML_ds_grid_createii+0x84> */
/* @0x10037c mov r4, r6 */
/* @0x100380 b 0x100318 <_Z20YYGML_ds_grid_createii+0x84> */
/* @0x100384 .word 0x002f19b4 */
/* @0x100388 .word 0xffffc234 */
/* @0x10038c .word 0xffffc238 */
/* @0x100390 eoreq r7, r3, r12, asr #16 */

/* ── FUNC 0x100394 · F_DsGridCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x100394 push {r4, r5, r6, lr} */
/* @0x100398 mov r1, #0 */
/* @0x10039c ldr r5, [sp, #0x10] */
/* @0x1003a0 mov r4, r0 */
/* @0x1003a4 str r1, [r0, #0xc] */
/* @0x1003a8 mov r0, r5 */
/* @0x1003ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1003b0 mov r1, #1 */
/* @0x1003b4 mov r6, r0 */
/* @0x1003b8 mov r0, r5 */
/* @0x1003bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1003c0 mov r1, r0 */
/* @0x1003c4 mov r0, r6 */
/* @0x1003c8 bl 0x100294 <_Z20YYGML_ds_grid_createii> */
/* @0x1003cc vmov s15, r0 */
/* @0x1003d0 vcvt.f64.s32 d7, s15 */
/* @0x1003d4 vmov r0, r1, d7 */
/* @0x1003d8 vmov r2, s14 */
/* @0x1003dc mov r3, r1 */
/* @0x1003e0 stm r4, {r2, r3} */
/* @0x1003e4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1003e8 · YYGML_ds_grid_get(int, int, int) · size=260 · insn=65 */
/* @0x1003e8 ldr r12, [pc, #0xe0] */
/* @0x1003ec ldr r3, [pc, #0xe0] */
/* @0x1003f0 add r12, pc, r12 */
/* @0x1003f4 push {r4, r5, r6, r7, lr} */
/* @0x1003f8 mov r5, r2 */
/* @0x1003fc ldr r3, [r12, r3] */
/* @0x100400 sub sp, sp, #20 */
/* @0x100404 ldrb r3, [r3] */
/* @0x100408 cmp r3, #0 */
/* @0x10040c beq 0x100490 <_Z17YYGML_ds_grid_getiii+0xa8> */
/* @0x100410 cmp r0, #0 */
/* @0x100414 blt 0x1004b8 <_Z17YYGML_ds_grid_getiii+0xd0> */
/* @0x100418 ldr r3, [pc, #0xb8] */
/* @0x10041c ldr r3, [r12, r3] */
/* @0x100420 ldr r3, [r3] */
/* @0x100424 cmp r0, r3 */
/* @0x100428 bge 0x1004b8 <_Z17YYGML_ds_grid_getiii+0xd0> */
/* @0x10042c ldr r3, [pc, #0xa8] */
/* @0x100430 ldr r3, [r12, r3] */
/* @0x100434 ldr r2, [r3, #0x4] */
/* @0x100438 ldr r4, [r2, r0, lsl #2] */
/* @0x10043c cmp r4, #0 */
/* @0x100440 beq 0x1004b8 <_Z17YYGML_ds_grid_getiii+0xd0> */
/* @0x100444 ldmib r4, {r6, r7} */
/* @0x100448 cmp r1, r6 */
/* @0x10044c bhs 0x100458 <_Z17YYGML_ds_grid_getiii+0x70> */
/* @0x100450 cmp r5, r7 */
/* @0x100454 blo 0x100498 <_Z17YYGML_ds_grid_getiii+0xb0> */
/* @0x100458 ldr lr, [pc, #0x80] */
/* @0x10045c mov r2, r0 */
/* @0x100460 mov r3, r1 */
/* @0x100464 ldr r1, [pc, #0x78] */
/* @0x100468 ldr r0, [r12, lr] */
/* @0x10046c add r1, pc, r1 */
/* @0x100470 ldr r0, [r0] */
/* @0x100474 ldr r12, [r0] */
/* @0x100478 stm sp, {r5, r6, r7} */
/* @0x10047c ldr r12, [r12, #0xc] */
/* @0x100480 blx r12 */
/* @0x100484 ldr r0, [r4] */
/* @0x100488 add sp, sp, #20 */
/* @0x10048c pop {r4, r5, r6, r7, pc} */
/* @0x100490 ldr r3, [pc, #0x44] */
/* @0x100494 ldr r3, [r12, r3] */
/* @0x100498 ldr r3, [r3, #0x4] */
/* @0x10049c ldr r3, [r3, r0, lsl #2] */
/* @0x1004a0 ldr r0, [r3, #0x4] */
/* @0x1004a4 ldr r3, [r3] */
/* @0x1004a8 mla r1, r0, r5, r1 */
/* @0x1004ac add r0, r3, r1, lsl #4 */
/* @0x1004b0 add sp, sp, #20 */
/* @0x1004b4 pop {r4, r5, r6, r7, pc} */
/* @0x1004b8 ldr r0, [pc, #0x28] */
/* @0x1004bc mov r1, #0 */
/* @0x1004c0 add r0, pc, r0 */
/* @0x1004c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1004c8 mov r0, #0 */
/* @0x1004cc b 0x100488 <_Z17YYGML_ds_grid_getiii+0xa0> */
/* @0x1004d0 eoreq r1, pc, r0, ror #16 */
/* @0x1004d4 .word 0xffffc240 */
/* @0x1004d8 .word 0xffffc234 */
/* @0x1004dc .word 0xffffc238 */
/* @0x1004e0 .word 0xffffbcf0 */
/* @0x1004e4 eoreq r7, r3, r12, lsl #17 */
/* @0x1004e8 eoreq r7, r3, r12, lsr r7 */

/* ── FUNC 0x1004ec · Setup_SetupDataStructureFunctions(bool) · size=144 · insn=36 */
/* @0x1004ec push {r4, lr} */
/* @0x1004f0 cmp r0, #0 */
/* @0x1004f4 ldr r4, [pc, #0x5c] */
/* @0x1004f8 add r4, pc, r4 */
/* @0x1004fc bne 0x10052c <_Z33Setup_SetupDataStructureFunctionsb+0x40> */
/* @0x100500 ldr r3, [pc, #0x54] */
/* @0x100504 ldr r0, [pc, #0x54] */
/* @0x100508 ldr r1, [r4, r3] */
/* @0x10050c add r0, pc, r0 */
/* @0x100510 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0x100514 ldr r3, [pc, #0x48] */
/* @0x100518 ldr r0, [pc, #0x48] */
/* @0x10051c ldr r1, [r4, r3] */
/* @0x100520 add r0, pc, r0 */
/* @0x100524 pop {r4, lr} */
/* @0x100528 b 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0x10052c ldr r3, [pc, #0x38] */
/* @0x100530 ldr r0, [pc, #0x38] */
/* @0x100534 ldr r1, [r4, r3] */
/* @0x100538 add r0, pc, r0 */
/* @0x10053c bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0x100540 ldr r3, [pc, #0x2c] */
/* @0x100544 ldr r0, [pc, #0x2c] */
/* @0x100548 ldr r1, [r4, r3] */
/* @0x10054c add r0, pc, r0 */
/* @0x100550 pop {r4, lr} */
/* @0x100554 b 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E> */
/* @0x100558 eoreq r1, pc, r8, asr r7 */
/* @0x10055c .word 0xffffc244 */
/* @0x100560 eoreq r7, r3, r12, lsr #16 */
/* @0x100564 .word 0xffffc248 */
/* @0x100568 eoreq r7, r3, r4, lsr #16 */
/* @0x10056c .word 0xffffc24c */
/* @0x100570 eoreq r7, r3, r0, lsl #16 */
/* @0x100574 .word 0xffffc250 */
/* @0x100578 .word 0x002377f8 */

/* ── FUNC 0x10057c · InitDataStructuresFunctions() · size=4700 · insn=1175 */
/* @0x10057c push {r4, lr} */
/* @0x100580 mov r2, #1 */
/* @0x100584 ldr r4, [pc, #0xe38] */
/* @0x100588 mov r3, r2 */
/* @0x10058c ldr r1, [pc, #0xe34] */
/* @0x100590 add r4, pc, r4 */
/* @0x100594 ldr r0, [pc, #0xe30] */
/* @0x100598 ldr r1, [r4, r1] */
/* @0x10059c add r0, pc, r0 */
/* @0x1005a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1005a4 ldr r1, [pc, #0xe24] */
/* @0x1005a8 ldr r0, [pc, #0xe24] */
/* @0x1005ac mov r2, #2 */
/* @0x1005b0 mov r3, #1 */
/* @0x1005b4 ldr r1, [r4, r1] */
/* @0x1005b8 add r0, pc, r0 */
/* @0x1005bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1005c0 ldr r1, [pc, #0xe10] */
/* @0x1005c4 ldr r0, [pc, #0xe10] */
/* @0x1005c8 mov r2, #0 */
/* @0x1005cc mov r3, #1 */
/* @0x1005d0 ldr r1, [r4, r1] */
/* @0x1005d4 add r0, pc, r0 */
/* @0x1005d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1005dc ldr r1, [pc, #0xdfc] */
/* @0x1005e0 ldr r0, [pc, #0xdfc] */
/* @0x1005e4 mov r2, #1 */
/* @0x1005e8 mov r3, r2 */
/* @0x1005ec ldr r1, [r4, r1] */
/* @0x1005f0 add r0, pc, r0 */
/* @0x1005f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1005f8 ldr r1, [pc, #0xde8] */
/* @0x1005fc ldr r0, [pc, #0xde8] */
/* @0x100600 mov r2, #1 */
/* @0x100604 mov r3, r2 */
/* @0x100608 ldr r1, [r4, r1] */
/* @0x10060c add r0, pc, r0 */
/* @0x100610 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100614 ldr r1, [pc, #0xdd4] */
/* @0x100618 ldr r0, [pc, #0xdd4] */
/* @0x10061c mov r2, #2 */
/* @0x100620 mov r3, #1 */
/* @0x100624 ldr r1, [r4, r1] */
/* @0x100628 add r0, pc, r0 */
/* @0x10062c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100630 ldr r1, [pc, #0xdc0] */
/* @0x100634 ldr r0, [pc, #0xdc0] */
/* @0x100638 mov r2, #1 */
/* @0x10063c mov r3, r2 */
/* @0x100640 ldr r1, [r4, r1] */
/* @0x100644 add r0, pc, r0 */
/* @0x100648 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x10064c ldr r1, [pc, #0xdac] */
/* @0x100650 ldr r0, [pc, #0xdac] */
/* @0x100654 mov r2, #1 */
/* @0x100658 mov r3, r2 */
/* @0x10065c ldr r1, [r4, r1] */
/* @0x100660 add r0, pc, r0 */
/* @0x100664 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100668 ldr r1, [pc, #0xd98] */
/* @0x10066c ldr r0, [pc, #0xd98] */
/* @0x100670 mvn r2, #0 */
/* @0x100674 mov r3, #1 */
/* @0x100678 ldr r1, [r4, r1] */
/* @0x10067c add r0, pc, r0 */
/* @0x100680 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100684 ldr r1, [pc, #0xd84] */
/* @0x100688 ldr r0, [pc, #0xd84] */
/* @0x10068c mov r2, #1 */
/* @0x100690 mov r3, r2 */
/* @0x100694 ldr r1, [r4, r1] */
/* @0x100698 add r0, pc, r0 */
/* @0x10069c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1006a0 ldr r1, [pc, #0xd70] */
/* @0x1006a4 ldr r0, [pc, #0xd70] */
/* @0x1006a8 mov r2, #1 */
/* @0x1006ac mov r3, r2 */
/* @0x1006b0 ldr r1, [r4, r1] */
/* @0x1006b4 add r0, pc, r0 */
/* @0x1006b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1006bc ldr r1, [pc, #0xd5c] */
/* @0x1006c0 ldr r0, [pc, #0xd5c] */
/* @0x1006c4 mov r2, #1 */
/* @0x1006c8 mov r3, r2 */
/* @0x1006cc ldr r1, [r4, r1] */
/* @0x1006d0 add r0, pc, r0 */
/* @0x1006d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1006d8 ldr r1, [pc, #0xd48] */
/* @0x1006dc ldr r0, [pc, #0xd48] */
/* @0x1006e0 mov r2, #2 */
/* @0x1006e4 mov r3, #1 */
/* @0x1006e8 ldr r1, [r4, r1] */
/* @0x1006ec add r0, pc, r0 */
/* @0x1006f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1006f4 ldr r1, [pc, #0xd34] */
/* @0x1006f8 ldr r0, [pc, #0xd34] */
/* @0x1006fc mov r2, #0 */
/* @0x100700 mov r3, #1 */
/* @0x100704 ldr r1, [r4, r1] */
/* @0x100708 add r0, pc, r0 */
/* @0x10070c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100710 ldr r1, [pc, #0xd20] */
/* @0x100714 ldr r0, [pc, #0xd20] */
/* @0x100718 mov r2, #1 */
/* @0x10071c mov r3, r2 */
/* @0x100720 ldr r1, [r4, r1] */
/* @0x100724 add r0, pc, r0 */
/* @0x100728 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x10072c ldr r1, [pc, #0xd0c] */
/* @0x100730 ldr r0, [pc, #0xd0c] */
/* @0x100734 mov r2, #1 */
/* @0x100738 mov r3, r2 */
/* @0x10073c ldr r1, [r4, r1] */
/* @0x100740 add r0, pc, r0 */
/* @0x100744 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100748 ldr r1, [pc, #0xcf8] */
/* @0x10074c ldr r0, [pc, #0xcf8] */
/* @0x100750 mov r2, #2 */
/* @0x100754 mov r3, #1 */
/* @0x100758 ldr r1, [r4, r1] */
/* @0x10075c add r0, pc, r0 */
/* @0x100760 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100764 ldr r1, [pc, #0xce4] */
/* @0x100768 ldr r0, [pc, #0xce4] */
/* @0x10076c mov r2, #1 */
/* @0x100770 mov r3, r2 */
/* @0x100774 ldr r1, [r4, r1] */
/* @0x100778 add r0, pc, r0 */
/* @0x10077c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100780 ldr r1, [pc, #0xcd0] */
/* @0x100784 ldr r0, [pc, #0xcd0] */
/* @0x100788 mov r2, #1 */
/* @0x10078c mov r3, r2 */
/* @0x100790 ldr r1, [r4, r1] */
/* @0x100794 add r0, pc, r0 */
/* @0x100798 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x10079c ldr r1, [pc, #0xcbc] */
/* @0x1007a0 ldr r0, [pc, #0xcbc] */
/* @0x1007a4 mvn r2, #0 */
/* @0x1007a8 mov r3, #1 */
/* @0x1007ac ldr r1, [r4, r1] */
/* @0x1007b0 add r0, pc, r0 */
/* @0x1007b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1007b8 ldr r1, [pc, #0xca8] */
/* @0x1007bc ldr r0, [pc, #0xca8] */
/* @0x1007c0 mov r2, #1 */
/* @0x1007c4 mov r3, r2 */
/* @0x1007c8 ldr r1, [r4, r1] */
/* @0x1007cc add r0, pc, r0 */
/* @0x1007d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1007d4 ldr r1, [pc, #0xc94] */
/* @0x1007d8 ldr r0, [pc, #0xc94] */
/* @0x1007dc mov r2, #1 */
/* @0x1007e0 mov r3, r2 */
/* @0x1007e4 ldr r1, [r4, r1] */
/* @0x1007e8 add r0, pc, r0 */
/* @0x1007ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1007f0 ldr r1, [pc, #0xc80] */
/* @0x1007f4 ldr r0, [pc, #0xc80] */
/* @0x1007f8 mov r2, #1 */
/* @0x1007fc mov r3, r2 */
/* @0x100800 ldr r1, [r4, r1] */
/* @0x100804 add r0, pc, r0 */
/* @0x100808 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x10080c ldr r1, [pc, #0xc6c] */
/* @0x100810 ldr r0, [pc, #0xc6c] */
/* @0x100814 mov r2, #1 */
/* @0x100818 mov r3, r2 */
/* @0x10081c ldr r1, [r4, r1] */
/* @0x100820 add r0, pc, r0 */
/* @0x100824 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100828 ldr r1, [pc, #0xc58] */
/* @0x10082c ldr r0, [pc, #0xc58] */
/* @0x100830 mov r2, #2 */
/* @0x100834 mov r3, #1 */
/* @0x100838 ldr r1, [r4, r1] */
/* @0x10083c add r0, pc, r0 */
/* @0x100840 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100844 ldr r1, [pc, #0xc44] */
/* @0x100848 ldr r0, [pc, #0xc44] */
/* @0x10084c mov r2, #0 */
/* @0x100850 mov r3, #1 */
/* @0x100854 ldr r1, [r4, r1] */
/* @0x100858 add r0, pc, r0 */
/* @0x10085c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100860 ldr r1, [pc, #0xc30] */
/* @0x100864 ldr r0, [pc, #0xc30] */
/* @0x100868 mov r2, #1 */
/* @0x10086c mov r3, r2 */
/* @0x100870 ldr r1, [r4, r1] */
/* @0x100874 add r0, pc, r0 */
/* @0x100878 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x10087c ldr r1, [pc, #0xc1c] */
/* @0x100880 ldr r0, [pc, #0xc1c] */
/* @0x100884 mov r2, #1 */
/* @0x100888 mov r3, r2 */
/* @0x10088c ldr r1, [r4, r1] */
/* @0x100890 add r0, pc, r0 */
/* @0x100894 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100898 ldr r1, [pc, #0xc08] */
/* @0x10089c ldr r0, [pc, #0xc08] */
/* @0x1008a0 mov r2, #2 */
/* @0x1008a4 mov r3, #1 */
/* @0x1008a8 ldr r1, [r4, r1] */
/* @0x1008ac add r0, pc, r0 */
/* @0x1008b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1008b4 ldr r1, [pc, #0xbf4] */
/* @0x1008b8 ldr r0, [pc, #0xbf4] */
/* @0x1008bc mov r2, #1 */
/* @0x1008c0 mov r3, r2 */
/* @0x1008c4 ldr r1, [r4, r1] */
/* @0x1008c8 add r0, pc, r0 */
/* @0x1008cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1008d0 ldr r1, [pc, #0xbe0] */
/* @0x1008d4 ldr r0, [pc, #0xbe0] */
/* @0x1008d8 mov r2, #1 */
/* @0x1008dc mov r3, r2 */
/* @0x1008e0 ldr r1, [r4, r1] */
/* @0x1008e4 add r0, pc, r0 */
/* @0x1008e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1008ec ldr r1, [pc, #0xbcc] */
/* @0x1008f0 ldr r0, [pc, #0xbcc] */
/* @0x1008f4 mvn r2, #0 */
/* @0x1008f8 mov r3, #1 */
/* @0x1008fc ldr r1, [r4, r1] */
/* @0x100900 add r0, pc, r0 */
/* @0x100904 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100908 ldr r1, [pc, #0xbb8] */
/* @0x10090c ldr r0, [pc, #0xbb8] */
/* @0x100910 mov r2, #3 */
/* @0x100914 mov r3, #1 */
/* @0x100918 ldr r1, [r4, r1] */
/* @0x10091c add r0, pc, r0 */
/* @0x100920 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100924 ldr r1, [pc, #0xba4] */
/* @0x100928 ldr r0, [pc, #0xba4] */
/* @0x10092c mov r2, #3 */
/* @0x100930 mov r3, #1 */
/* @0x100934 ldr r1, [r4, r1] */
/* @0x100938 add r0, pc, r0 */
/* @0x10093c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100940 ldr r1, [pc, #0xb90] */
/* @0x100944 ldr r0, [pc, #0xb90] */
/* @0x100948 mov r2, #2 */
/* @0x10094c mov r3, #1 */
/* @0x100950 ldr r1, [r4, r1] */
/* @0x100954 add r0, pc, r0 */
/* @0x100958 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x10095c ldr r1, [pc, #0xb7c] */
/* @0x100960 ldr r0, [pc, #0xb7c] */
/* @0x100964 mov r2, #2 */
/* @0x100968 mov r3, #1 */
/* @0x10096c ldr r1, [r4, r1] */
/* @0x100970 add r0, pc, r0 */
/* @0x100974 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100978 ldr r1, [pc, #0xb68] */
/* @0x10097c ldr r0, [pc, #0xb68] */
/* @0x100980 mov r2, #2 */
/* @0x100984 mov r3, #1 */
/* @0x100988 ldr r1, [r4, r1] */
/* @0x10098c add r0, pc, r0 */
/* @0x100990 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100994 ldr r1, [pc, #0xb54] */
/* @0x100998 ldr r0, [pc, #0xb54] */
/* @0x10099c mov r2, #2 */
/* @0x1009a0 mov r3, #1 */
/* @0x1009a4 ldr r1, [r4, r1] */
/* @0x1009a8 add r0, pc, r0 */
/* @0x1009ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1009b0 ldr r1, [pc, #0xb40] */
/* @0x1009b4 ldr r0, [pc, #0xb40] */
/* @0x1009b8 mov r2, #2 */
/* @0x1009bc mov r3, #1 */
/* @0x1009c0 ldr r1, [r4, r1] */
/* @0x1009c4 add r0, pc, r0 */
/* @0x1009c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1009cc ldr r1, [pc, #0xb2c] */
/* @0x1009d0 ldr r0, [pc, #0xb2c] */
/* @0x1009d4 mov r2, #2 */
/* @0x1009d8 mov r3, #1 */
/* @0x1009dc ldr r1, [r4, r1] */
/* @0x1009e0 add r0, pc, r0 */
/* @0x1009e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1009e8 ldr r1, [pc, #0xb18] */
/* @0x1009ec ldr r0, [pc, #0xb18] */
/* @0x1009f0 mov r2, #1 */
/* @0x1009f4 mov r3, r2 */
/* @0x1009f8 ldr r1, [r4, r1] */
/* @0x1009fc add r0, pc, r0 */
/* @0x100a00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100a04 ldr r1, [pc, #0xb04] */
/* @0x100a08 ldr r0, [pc, #0xb04] */
/* @0x100a0c mov r2, #1 */
/* @0x100a10 mov r3, r2 */
/* @0x100a14 ldr r1, [r4, r1] */
/* @0x100a18 add r0, pc, r0 */
/* @0x100a1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100a20 ldr r1, [pc, #0xaf0] */
/* @0x100a24 ldr r0, [pc, #0xaf0] */
/* @0x100a28 mov r2, #2 */
/* @0x100a2c mov r3, #1 */
/* @0x100a30 ldr r1, [r4, r1] */
/* @0x100a34 add r0, pc, r0 */
/* @0x100a38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100a3c ldr r1, [pc, #0xadc] */
/* @0x100a40 ldr r0, [pc, #0xadc] */
/* @0x100a44 mov r2, #3 */
/* @0x100a48 mov r3, #1 */
/* @0x100a4c ldr r1, [r4, r1] */
/* @0x100a50 add r0, pc, r0 */
/* @0x100a54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100a58 ldr r1, [pc, #0xac8] */
/* @0x100a5c ldr r0, [pc, #0xac8] */
/* @0x100a60 mov r2, #3 */
/* @0x100a64 mov r3, #1 */
/* @0x100a68 ldr r1, [r4, r1] */
/* @0x100a6c add r0, pc, r0 */
/* @0x100a70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100a74 ldr r1, [pc, #0xab4] */
/* @0x100a78 ldr r0, [pc, #0xab4] */
/* @0x100a7c mov r2, #3 */
/* @0x100a80 mov r3, #1 */
/* @0x100a84 ldr r1, [r4, r1] */
/* @0x100a88 add r0, pc, r0 */
/* @0x100a8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100a90 ldr r1, [pc, #0xaa0] */
/* @0x100a94 ldr r0, [pc, #0xaa0] */
/* @0x100a98 mov r2, #0 */
/* @0x100a9c mov r3, #1 */
/* @0x100aa0 ldr r1, [r4, r1] */
/* @0x100aa4 add r0, pc, r0 */
/* @0x100aa8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100aac ldr r1, [pc, #0xa8c] */
/* @0x100ab0 ldr r0, [pc, #0xa8c] */
/* @0x100ab4 mov r2, #1 */
/* @0x100ab8 mov r3, r2 */
/* @0x100abc ldr r1, [r4, r1] */
/* @0x100ac0 add r0, pc, r0 */
/* @0x100ac4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100ac8 ldr r1, [pc, #0xa78] */
/* @0x100acc ldr r0, [pc, #0xa78] */
/* @0x100ad0 mov r2, #1 */
/* @0x100ad4 mov r3, r2 */
/* @0x100ad8 ldr r1, [r4, r1] */
/* @0x100adc add r0, pc, r0 */
/* @0x100ae0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100ae4 ldr r1, [pc, #0xa64] */
/* @0x100ae8 ldr r0, [pc, #0xa64] */
/* @0x100aec mov r2, #2 */
/* @0x100af0 mov r3, #1 */
/* @0x100af4 ldr r1, [r4, r1] */
/* @0x100af8 add r0, pc, r0 */
/* @0x100afc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100b00 ldr r1, [pc, #0xa50] */
/* @0x100b04 ldr r0, [pc, #0xa50] */
/* @0x100b08 mov r2, #1 */
/* @0x100b0c mov r3, r2 */
/* @0x100b10 ldr r1, [r4, r1] */
/* @0x100b14 add r0, pc, r0 */
/* @0x100b18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100b1c ldr r1, [pc, #0xa3c] */
/* @0x100b20 ldr r0, [pc, #0xa3c] */
/* @0x100b24 mov r2, #1 */
/* @0x100b28 mov r3, r2 */
/* @0x100b2c ldr r1, [r4, r1] */
/* @0x100b30 add r0, pc, r0 */
/* @0x100b34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100b38 ldr r1, [pc, #0xa28] */
/* @0x100b3c ldr r0, [pc, #0xa28] */
/* @0x100b40 mov r2, #3 */
/* @0x100b44 mov r3, #1 */
/* @0x100b48 ldr r1, [r4, r1] */
/* @0x100b4c add r0, pc, r0 */
/* @0x100b50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100b54 ldr r1, [pc, #0xa14] */
/* @0x100b58 ldr r0, [pc, #0xa14] */
/* @0x100b5c mov r2, #3 */
/* @0x100b60 mov r3, #1 */
/* @0x100b64 ldr r1, [r4, r1] */
/* @0x100b68 add r0, pc, r0 */
/* @0x100b6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100b70 ldr r1, [pc, #0xa00] */
/* @0x100b74 ldr r0, [pc, #0xa00] */
/* @0x100b78 mov r2, #3 */
/* @0x100b7c mov r3, #1 */
/* @0x100b80 ldr r1, [r4, r1] */
/* @0x100b84 add r0, pc, r0 */
/* @0x100b88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100b8c ldr r1, [pc, #0x9ec] */
/* @0x100b90 ldr r0, [pc, #0x9ec] */
/* @0x100b94 mov r2, #3 */
/* @0x100b98 mov r3, #1 */
/* @0x100b9c ldr r1, [r4, r1] */
/* @0x100ba0 add r0, pc, r0 */
/* @0x100ba4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100ba8 ldr r1, [pc, #0x9d8] */
/* @0x100bac ldr r0, [pc, #0x9d8] */
/* @0x100bb0 mov r2, #3 */
/* @0x100bb4 mov r3, #1 */
/* @0x100bb8 ldr r1, [r4, r1] */
/* @0x100bbc add r0, pc, r0 */
/* @0x100bc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100bc4 ldr r1, [pc, #0x9c4] */
/* @0x100bc8 ldr r0, [pc, #0x9c4] */
/* @0x100bcc mov r2, #3 */
/* @0x100bd0 mov r3, #1 */
/* @0x100bd4 ldr r1, [r4, r1] */
/* @0x100bd8 add r0, pc, r0 */
/* @0x100bdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100be0 ldr r1, [pc, #0x9b0] */
/* @0x100be4 ldr r0, [pc, #0x9b0] */
/* @0x100be8 mov r2, #3 */
/* @0x100bec mov r3, #1 */
/* @0x100bf0 ldr r1, [r4, r1] */
/* @0x100bf4 add r0, pc, r0 */
/* @0x100bf8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100bfc ldr r1, [pc, #0x99c] */
/* @0x100c00 ldr r0, [pc, #0x99c] */
/* @0x100c04 mov r2, #3 */
/* @0x100c08 mov r3, #1 */
/* @0x100c0c ldr r1, [r4, r1] */
/* @0x100c10 add r0, pc, r0 */
/* @0x100c14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100c18 ldr r1, [pc, #0x988] */
/* @0x100c1c ldr r0, [pc, #0x988] */
/* @0x100c20 mov r2, #3 */
/* @0x100c24 mov r3, #1 */
/* @0x100c28 ldr r1, [r4, r1] */
/* @0x100c2c add r0, pc, r0 */
/* @0x100c30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100c34 ldr r1, [pc, #0x974] */
/* @0x100c38 ldr r0, [pc, #0x974] */
/* @0x100c3c mov r2, #2 */
/* @0x100c40 mov r3, #1 */
/* @0x100c44 ldr r1, [r4, r1] */
/* @0x100c48 add r0, pc, r0 */
/* @0x100c4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100c50 ldr r1, [pc, #0x960] */
/* @0x100c54 ldr r0, [pc, #0x960] */
/* @0x100c58 mov r2, #2 */
/* @0x100c5c mov r3, #1 */
/* @0x100c60 ldr r1, [r4, r1] */
/* @0x100c64 add r0, pc, r0 */
/* @0x100c68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100c6c ldr r1, [pc, #0x94c] */
/* @0x100c70 ldr r0, [pc, #0x94c] */
/* @0x100c74 mov r2, #2 */
/* @0x100c78 mov r3, #1 */
/* @0x100c7c ldr r1, [r4, r1] */
/* @0x100c80 add r0, pc, r0 */
/* @0x100c84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100c88 ldr r1, [pc, #0x938] */
/* @0x100c8c ldr r0, [pc, #0x938] */
/* @0x100c90 mov r2, #2 */
/* @0x100c94 mov r3, #1 */
/* @0x100c98 ldr r1, [r4, r1] */
/* @0x100c9c add r0, pc, r0 */
/* @0x100ca0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100ca4 ldr r1, [pc, #0x924] */
/* @0x100ca8 ldr r0, [pc, #0x924] */
/* @0x100cac mov r2, #2 */
/* @0x100cb0 mov r3, #1 */
/* @0x100cb4 ldr r1, [r4, r1] */
/* @0x100cb8 add r0, pc, r0 */
/* @0x100cbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100cc0 ldr r1, [pc, #0x910] */
/* @0x100cc4 ldr r0, [pc, #0x910] */
/* @0x100cc8 mov r2, #1 */
/* @0x100ccc mov r3, r2 */
/* @0x100cd0 ldr r1, [r4, r1] */
/* @0x100cd4 add r0, pc, r0 */
/* @0x100cd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100cdc ldr r1, [pc, #0x8fc] */
/* @0x100ce0 ldr r0, [pc, #0x8fc] */
/* @0x100ce4 mov r2, #1 */
/* @0x100ce8 mov r3, r2 */
/* @0x100cec ldr r1, [r4, r1] */
/* @0x100cf0 add r0, pc, r0 */
/* @0x100cf4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100cf8 ldr r1, [pc, #0x8e8] */
/* @0x100cfc ldr r0, [pc, #0x8e8] */
/* @0x100d00 mov r2, #1 */
/* @0x100d04 mov r3, r2 */
/* @0x100d08 ldr r1, [r4, r1] */
/* @0x100d0c add r0, pc, r0 */
/* @0x100d10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100d14 ldr r1, [pc, #0x8d4] */
/* @0x100d18 ldr r0, [pc, #0x8d4] */
/* @0x100d1c mov r2, #2 */
/* @0x100d20 mov r3, #1 */
/* @0x100d24 ldr r1, [r4, r1] */
/* @0x100d28 add r0, pc, r0 */
/* @0x100d2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100d30 ldr r1, [pc, #0x8c0] */
/* @0x100d34 ldr r0, [pc, #0x8c0] */
/* @0x100d38 mov r2, #2 */
/* @0x100d3c mov r3, #1 */
/* @0x100d40 ldr r1, [r4, r1] */
/* @0x100d44 add r0, pc, r0 */
/* @0x100d48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100d4c ldr r1, [pc, #0x8ac] */
/* @0x100d50 ldr r0, [pc, #0x8ac] */
/* @0x100d54 mov r2, #1 */
/* @0x100d58 mov r3, r2 */
/* @0x100d5c ldr r1, [r4, r1] */
/* @0x100d60 add r0, pc, r0 */
/* @0x100d64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100d68 ldr r1, [pc, #0x898] */
/* @0x100d6c ldr r0, [pc, #0x898] */
/* @0x100d70 mov r2, #1 */
/* @0x100d74 mov r3, r2 */
/* @0x100d78 ldr r1, [r4, r1] */
/* @0x100d7c add r0, pc, r0 */
/* @0x100d80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100d84 ldr r1, [pc, #0x884] */
/* @0x100d88 ldr r0, [pc, #0x884] */
/* @0x100d8c mov r2, #2 */
/* @0x100d90 mov r3, #1 */
/* @0x100d94 ldr r1, [r4, r1] */
/* @0x100d98 add r0, pc, r0 */
/* @0x100d9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100da0 ldr r1, [pc, #0x870] */
/* @0x100da4 ldr r0, [pc, #0x870] */
/* @0x100da8 mov r2, #0 */
/* @0x100dac mov r3, #1 */
/* @0x100db0 ldr r1, [r4, r1] */
/* @0x100db4 add r0, pc, r0 */
/* @0x100db8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100dbc ldr r1, [pc, #0x85c] */
/* @0x100dc0 ldr r0, [pc, #0x85c] */
/* @0x100dc4 mov r2, #1 */
/* @0x100dc8 mov r3, r2 */
/* @0x100dcc ldr r1, [r4, r1] */
/* @0x100dd0 add r0, pc, r0 */
/* @0x100dd4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100dd8 ldr r1, [pc, #0x848] */
/* @0x100ddc ldr r0, [pc, #0x848] */
/* @0x100de0 mov r2, #1 */
/* @0x100de4 mov r3, r2 */
/* @0x100de8 ldr r1, [r4, r1] */
/* @0x100dec add r0, pc, r0 */
/* @0x100df0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100df4 ldr r1, [pc, #0x834] */
/* @0x100df8 ldr r0, [pc, #0x834] */
/* @0x100dfc mov r2, #2 */
/* @0x100e00 mov r3, #1 */
/* @0x100e04 ldr r1, [r4, r1] */
/* @0x100e08 add r0, pc, r0 */
/* @0x100e0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100e10 ldr r1, [pc, #0x820] */
/* @0x100e14 ldr r0, [pc, #0x820] */
/* @0x100e18 mov r2, #1 */
/* @0x100e1c mov r3, r2 */
/* @0x100e20 ldr r1, [r4, r1] */
/* @0x100e24 add r0, pc, r0 */
/* @0x100e28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100e2c ldr r1, [pc, #0x80c] */
/* @0x100e30 ldr r0, [pc, #0x80c] */
/* @0x100e34 mov r2, #1 */
/* @0x100e38 mov r3, r2 */
/* @0x100e3c ldr r1, [r4, r1] */
/* @0x100e40 add r0, pc, r0 */
/* @0x100e44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100e48 ldr r1, [pc, #0x7f8] */
/* @0x100e4c ldr r0, [pc, #0x7f8] */
/* @0x100e50 mov r2, #3 */
/* @0x100e54 mov r3, #1 */
/* @0x100e58 ldr r1, [r4, r1] */
/* @0x100e5c add r0, pc, r0 */
/* @0x100e60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100e64 ldr r1, [pc, #0x7e4] */
/* @0x100e68 ldr r0, [pc, #0x7e4] */
/* @0x100e6c mov r2, #3 */
/* @0x100e70 mov r3, #1 */
/* @0x100e74 ldr r1, [r4, r1] */
/* @0x100e78 add r0, pc, r0 */
/* @0x100e7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100e80 ldr r1, [pc, #0x7d0] */
/* @0x100e84 ldr r0, [pc, #0x7d0] */
/* @0x100e88 mov r2, #2 */
/* @0x100e8c mov r3, #1 */
/* @0x100e90 ldr r1, [r4, r1] */
/* @0x100e94 add r0, pc, r0 */
/* @0x100e98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100e9c ldr r1, [pc, #0x7bc] */
/* @0x100ea0 ldr r0, [pc, #0x7bc] */
/* @0x100ea4 mov r2, #2 */
/* @0x100ea8 mov r3, #1 */
/* @0x100eac ldr r1, [r4, r1] */
/* @0x100eb0 add r0, pc, r0 */
/* @0x100eb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100eb8 ldr r1, [pc, #0x7a8] */
/* @0x100ebc ldr r0, [pc, #0x7a8] */
/* @0x100ec0 mov r2, #1 */
/* @0x100ec4 mov r3, r2 */
/* @0x100ec8 ldr r1, [r4, r1] */
/* @0x100ecc add r0, pc, r0 */
/* @0x100ed0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100ed4 ldr r1, [pc, #0x794] */
/* @0x100ed8 ldr r0, [pc, #0x794] */
/* @0x100edc mov r2, #1 */
/* @0x100ee0 mov r3, r2 */
/* @0x100ee4 ldr r1, [r4, r1] */
/* @0x100ee8 add r0, pc, r0 */
/* @0x100eec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100ef0 ldr r1, [pc, #0x780] */
/* @0x100ef4 ldr r0, [pc, #0x780] */
/* @0x100ef8 mov r2, #1 */
/* @0x100efc mov r3, r2 */
/* @0x100f00 ldr r1, [r4, r1] */
/* @0x100f04 add r0, pc, r0 */
/* @0x100f08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100f0c ldr r1, [pc, #0x76c] */
/* @0x100f10 ldr r0, [pc, #0x76c] */
/* @0x100f14 mov r2, #1 */
/* @0x100f18 mov r3, r2 */
/* @0x100f1c ldr r1, [r4, r1] */
/* @0x100f20 add r0, pc, r0 */
/* @0x100f24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100f28 ldr r1, [pc, #0x758] */
/* @0x100f2c ldr r0, [pc, #0x758] */
/* @0x100f30 mov r2, #1 */
/* @0x100f34 mov r3, r2 */
/* @0x100f38 ldr r1, [r4, r1] */
/* @0x100f3c add r0, pc, r0 */
/* @0x100f40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100f44 ldr r1, [pc, #0x744] */
/* @0x100f48 ldr r0, [pc, #0x744] */
/* @0x100f4c mov r2, #2 */
/* @0x100f50 mov r3, #1 */
/* @0x100f54 ldr r1, [r4, r1] */
/* @0x100f58 add r0, pc, r0 */
/* @0x100f5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100f60 ldr r1, [pc, #0x730] */
/* @0x100f64 ldr r0, [pc, #0x730] */
/* @0x100f68 mov r2, #2 */
/* @0x100f6c mov r3, #1 */
/* @0x100f70 ldr r1, [r4, r1] */
/* @0x100f74 add r0, pc, r0 */
/* @0x100f78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100f7c ldr r1, [pc, #0x71c] */
/* @0x100f80 ldr r0, [pc, #0x71c] */
/* @0x100f84 mov r2, #1 */
/* @0x100f88 mov r3, r2 */
/* @0x100f8c ldr r1, [r4, r1] */
/* @0x100f90 add r0, pc, r0 */
/* @0x100f94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100f98 ldr r1, [pc, #0x708] */
/* @0x100f9c ldr r0, [pc, #0x708] */
/* @0x100fa0 mov r2, #2 */
/* @0x100fa4 mov r3, #1 */
/* @0x100fa8 ldr r1, [r4, r1] */
/* @0x100fac add r0, pc, r0 */
/* @0x100fb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100fb4 ldr r1, [pc, #0x6f4] */
/* @0x100fb8 ldr r0, [pc, #0x6f4] */
/* @0x100fbc mov r2, #3 */
/* @0x100fc0 mov r3, #1 */
/* @0x100fc4 ldr r1, [r4, r1] */
/* @0x100fc8 add r0, pc, r0 */
/* @0x100fcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100fd0 ldr r1, [pc, #0x6e0] */
/* @0x100fd4 ldr r0, [pc, #0x6e0] */
/* @0x100fd8 mov r2, #1 */
/* @0x100fdc mov r3, r2 */
/* @0x100fe0 ldr r1, [r4, r1] */
/* @0x100fe4 add r0, pc, r0 */
/* @0x100fe8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x100fec ldr r1, [pc, #0x6cc] */
/* @0x100ff0 ldr r0, [pc, #0x6cc] */
/* @0x100ff4 mov r2, #1 */
/* @0x100ff8 mov r3, r2 */
/* @0x100ffc ldr r1, [r4, r1] */
/* @0x101000 add r0, pc, r0 */
/* @0x101004 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101008 ldr r1, [pc, #0x6b8] */
/* @0x10100c ldr r0, [pc, #0x6b8] */
/* @0x101010 mov r2, #2 */
/* @0x101014 mov r3, #1 */
/* @0x101018 ldr r1, [r4, r1] */
/* @0x10101c add r0, pc, r0 */
/* @0x101020 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101024 ldr r1, [pc, #0x6a4] */
/* @0x101028 ldr r0, [pc, #0x6a4] */
/* @0x10102c mov r2, #4 */
/* @0x101030 mov r3, #1 */
/* @0x101034 ldr r1, [r4, r1] */
/* @0x101038 add r0, pc, r0 */
/* @0x10103c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101040 ldr r1, [pc, #0x690] */
/* @0x101044 ldr r0, [pc, #0x690] */
/* @0x101048 mov r2, #4 */
/* @0x10104c mov r3, #1 */
/* @0x101050 ldr r1, [r4, r1] */
/* @0x101054 add r0, pc, r0 */
/* @0x101058 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x10105c ldr r1, [pc, #0x67c] */
/* @0x101060 ldr r0, [pc, #0x67c] */
/* @0x101064 mov r2, #4 */
/* @0x101068 mov r3, #1 */
/* @0x10106c ldr r1, [r4, r1] */
/* @0x101070 add r0, pc, r0 */
/* @0x101074 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101078 ldr r1, [pc, #0x668] */
/* @0x10107c ldr r0, [pc, #0x668] */
/* @0x101080 mov r2, #4 */
/* @0x101084 mov r3, #1 */
/* @0x101088 ldr r1, [r4, r1] */
/* @0x10108c add r0, pc, r0 */
/* @0x101090 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101094 ldr r1, [pc, #0x654] */
/* @0x101098 ldr r0, [pc, #0x654] */
/* @0x10109c mov r2, #4 */
/* @0x1010a0 mov r3, #1 */
/* @0x1010a4 ldr r1, [r4, r1] */
/* @0x1010a8 add r0, pc, r0 */
/* @0x1010ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1010b0 ldr r1, [pc, #0x640] */
/* @0x1010b4 ldr r0, [pc, #0x640] */
/* @0x1010b8 mov r2, #6 */
/* @0x1010bc mov r3, #1 */
/* @0x1010c0 ldr r1, [r4, r1] */
/* @0x1010c4 add r0, pc, r0 */
/* @0x1010c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1010cc ldr r1, [pc, #0x62c] */
/* @0x1010d0 ldr r0, [pc, #0x62c] */
/* @0x1010d4 mov r2, #6 */
/* @0x1010d8 mov r3, #1 */
/* @0x1010dc ldr r1, [r4, r1] */
/* @0x1010e0 add r0, pc, r0 */
/* @0x1010e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1010e8 ldr r1, [pc, #0x618] */
/* @0x1010ec ldr r0, [pc, #0x618] */
/* @0x1010f0 mov r2, #6 */
/* @0x1010f4 mov r3, #1 */
/* @0x1010f8 ldr r1, [r4, r1] */
/* @0x1010fc add r0, pc, r0 */
/* @0x101100 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101104 ldr r1, [pc, #0x604] */
/* @0x101108 ldr r0, [pc, #0x604] */
/* @0x10110c mov r2, #5 */
/* @0x101110 mov r3, #1 */
/* @0x101114 ldr r1, [r4, r1] */
/* @0x101118 add r0, pc, r0 */
/* @0x10111c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101120 ldr r1, [pc, #0x5f0] */
/* @0x101124 ldr r0, [pc, #0x5f0] */
/* @0x101128 mov r2, #5 */
/* @0x10112c mov r3, #1 */
/* @0x101130 ldr r1, [r4, r1] */
/* @0x101134 add r0, pc, r0 */
/* @0x101138 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x10113c ldr r1, [pc, #0x5dc] */
/* @0x101140 ldr r0, [pc, #0x5dc] */
/* @0x101144 mov r2, #5 */
/* @0x101148 mov r3, #1 */
/* @0x10114c ldr r1, [r4, r1] */
/* @0x101150 add r0, pc, r0 */
/* @0x101154 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101158 ldr r1, [pc, #0x5c8] */
/* @0x10115c ldr r0, [pc, #0x5c8] */
/* @0x101160 mov r2, #8 */
/* @0x101164 mov r3, #1 */
/* @0x101168 ldr r1, [r4, r1] */
/* @0x10116c add r0, pc, r0 */
/* @0x101170 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101174 ldr r1, [pc, #0x5b4] */
/* @0x101178 ldr r0, [pc, #0x5b4] */
/* @0x10117c mov r2, #8 */
/* @0x101180 mov r3, #1 */
/* @0x101184 ldr r1, [r4, r1] */
/* @0x101188 add r0, pc, r0 */
/* @0x10118c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101190 ldr r1, [pc, #0x5a0] */
/* @0x101194 ldr r0, [pc, #0x5a0] */
/* @0x101198 mov r2, #8 */
/* @0x10119c mov r3, #1 */
/* @0x1011a0 ldr r1, [r4, r1] */
/* @0x1011a4 add r0, pc, r0 */
/* @0x1011a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1011ac ldr r1, [pc, #0x58c] */
/* @0x1011b0 ldr r0, [pc, #0x58c] */
/* @0x1011b4 mov r2, #3 */
/* @0x1011b8 mov r3, #1 */
/* @0x1011bc ldr r1, [r4, r1] */
/* @0x1011c0 add r0, pc, r0 */
/* @0x1011c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1011c8 ldr r1, [pc, #0x578] */
/* @0x1011cc ldr r0, [pc, #0x578] */
/* @0x1011d0 mov r2, #5 */
/* @0x1011d4 mov r3, #1 */
/* @0x1011d8 ldr r1, [r4, r1] */
/* @0x1011dc add r0, pc, r0 */
/* @0x1011e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1011e4 ldr r1, [pc, #0x564] */
/* @0x1011e8 ldr r0, [pc, #0x564] */
/* @0x1011ec mov r2, #5 */
/* @0x1011f0 mov r3, #1 */
/* @0x1011f4 ldr r1, [r4, r1] */
/* @0x1011f8 add r0, pc, r0 */
/* @0x1011fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101200 ldr r1, [pc, #0x550] */
/* @0x101204 ldr r0, [pc, #0x550] */
/* @0x101208 mov r2, #5 */
/* @0x10120c mov r3, #1 */
/* @0x101210 ldr r1, [r4, r1] */
/* @0x101214 add r0, pc, r0 */
/* @0x101218 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x10121c ldr r1, [pc, #0x53c] */
/* @0x101220 ldr r0, [pc, #0x53c] */
/* @0x101224 mov r2, #5 */
/* @0x101228 mov r3, #1 */
/* @0x10122c ldr r1, [r4, r1] */
/* @0x101230 add r0, pc, r0 */
/* @0x101234 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101238 ldr r1, [pc, #0x528] */
/* @0x10123c ldr r0, [pc, #0x528] */
/* @0x101240 mov r2, #4 */
/* @0x101244 mov r3, #1 */
/* @0x101248 ldr r1, [r4, r1] */
/* @0x10124c add r0, pc, r0 */
/* @0x101250 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101254 ldr r1, [pc, #0x514] */
/* @0x101258 ldr r0, [pc, #0x514] */
/* @0x10125c mov r2, #4 */
/* @0x101260 mov r3, #1 */
/* @0x101264 ldr r1, [r4, r1] */
/* @0x101268 add r0, pc, r0 */
/* @0x10126c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101270 ldr r1, [pc, #0x500] */
/* @0x101274 ldr r0, [pc, #0x500] */
/* @0x101278 mov r2, #4 */
/* @0x10127c mov r3, #1 */
/* @0x101280 ldr r1, [r4, r1] */
/* @0x101284 add r0, pc, r0 */
/* @0x101288 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x10128c ldr r1, [pc, #0x4ec] */
/* @0x101290 ldr r0, [pc, #0x4ec] */
/* @0x101294 mov r2, #4 */
/* @0x101298 mov r3, #1 */
/* @0x10129c ldr r1, [r4, r1] */
/* @0x1012a0 add r0, pc, r0 */
/* @0x1012a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1012a8 ldr r1, [pc, #0x4d8] */
/* @0x1012ac ldr r0, [pc, #0x4d8] */
/* @0x1012b0 mov r2, #6 */
/* @0x1012b4 mov r3, #1 */
/* @0x1012b8 ldr r1, [r4, r1] */
/* @0x1012bc add r0, pc, r0 */
/* @0x1012c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1012c4 ldr r1, [pc, #0x4c4] */
/* @0x1012c8 ldr r0, [pc, #0x4c4] */
/* @0x1012cc mov r2, #6 */
/* @0x1012d0 mov r3, #1 */
/* @0x1012d4 ldr r1, [r4, r1] */
/* @0x1012d8 add r0, pc, r0 */
/* @0x1012dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1012e0 ldr r1, [pc, #0x4b0] */
/* @0x1012e4 ldr r0, [pc, #0x4b0] */
/* @0x1012e8 mov r2, #6 */
/* @0x1012ec mov r3, #1 */
/* @0x1012f0 ldr r1, [r4, r1] */
/* @0x1012f4 add r0, pc, r0 */
/* @0x1012f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1012fc ldr r1, [pc, #0x49c] */
/* @0x101300 ldr r0, [pc, #0x49c] */
/* @0x101304 mov r2, #5 */
/* @0x101308 mov r3, #1 */
/* @0x10130c ldr r1, [r4, r1] */
/* @0x101310 add r0, pc, r0 */
/* @0x101314 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101318 ldr r1, [pc, #0x488] */
/* @0x10131c ldr r0, [pc, #0x488] */
/* @0x101320 mov r2, #5 */
/* @0x101324 mov r3, #1 */
/* @0x101328 ldr r1, [r4, r1] */
/* @0x10132c add r0, pc, r0 */
/* @0x101330 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101334 ldr r1, [pc, #0x474] */
/* @0x101338 ldr r0, [pc, #0x474] */
/* @0x10133c mov r2, #5 */
/* @0x101340 mov r3, #1 */
/* @0x101344 ldr r1, [r4, r1] */
/* @0x101348 add r0, pc, r0 */
/* @0x10134c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101350 ldr r1, [pc, #0x460] */
/* @0x101354 ldr r0, [pc, #0x460] */
/* @0x101358 mov r2, #1 */
/* @0x10135c mov r3, r2 */
/* @0x101360 ldr r1, [r4, r1] */
/* @0x101364 add r0, pc, r0 */
/* @0x101368 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x10136c ldr r1, [pc, #0x44c] */
/* @0x101370 ldr r0, [pc, #0x44c] */
/* @0x101374 mov r2, #1 */
/* @0x101378 mov r3, r2 */
/* @0x10137c ldr r1, [r4, r1] */
/* @0x101380 add r0, pc, r0 */
/* @0x101384 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x101388 ldr r1, [pc, #0x438] */
/* @0x10138c ldr r0, [pc, #0x438] */
/* @0x101390 mov r2, #2 */
/* @0x101394 mov r3, #1 */
/* @0x101398 ldr r1, [r4, r1] */
/* @0x10139c add r0, pc, r0 */
/* @0x1013a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1013a4 ldr r1, [pc, #0x424] */
/* @0x1013a8 ldr r0, [pc, #0x424] */
/* @0x1013ac mov r2, #3 */
/* @0x1013b0 mov r3, #1 */
/* @0x1013b4 ldr r1, [r4, r1] */
/* @0x1013b8 add r0, pc, r0 */
/* @0x1013bc pop {r4, lr} */
/* @0x1013c0 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1013c4 eoreq r1, pc, r0, asr #13 */
/* @0x1013c8 .word 0xffffc254 */
/* @0x1013cc .word 0x002377b4 */
/* @0x1013d0 .word 0xffffc258 */
/* @0x1013d4 eoreq r7, r3, r12, lsr #15 */
/* @0x1013d8 .word 0xffffc25c */
/* @0x1013dc mlaeq r3, r12, r7, r7 */
/* @0x1013e0 .word 0xffffc260 */
/* @0x1013e4 mlaeq r3, r0, r7, r7 */
/* @0x1013e8 .word 0xffffc264 */
/* @0x1013ec eoreq r7, r3, r8, lsl #15 */
/* @0x1013f0 .word 0xffffc268 */
/* @0x1013f4 eoreq r7, r3, r12, ror r7 */
/* @0x1013f8 .word 0xffffc26c */
/* @0x1013fc eoreq r7, r3, r0, ror r7 */
/* @0x101400 .word 0xffffc270 */
/* @0x101404 eoreq r7, r3, r4, ror #14 */
/* @0x101408 .word 0xffffc274 */
/* @0x10140c eoreq r7, r3, r8, asr r7 */
/* @0x101410 .word 0xffffc278 */
/* @0x101414 eoreq r7, r3, r12, asr #14 */
/* @0x101418 .word 0xffffc27c */
/* @0x10141c eoreq r7, r3, r0, asr #14 */
/* @0x101420 .word 0xffffc280 */
/* @0x101424 eoreq r7, r3, r4, lsr r7 */
/* @0x101428 .word 0xffffc284 */
/* @0x10142c eoreq r7, r3, r8, lsr #14 */
/* @0x101430 .word 0xffffc288 */
/* @0x101434 eoreq r7, r3, r12, lsl r7 */
/* @0x101438 .word 0xffffc28c */
/* @0x10143c eoreq r7, r3, r0, lsl r7 */
/* @0x101440 .word 0xffffc290 */
/* @0x101444 eoreq r7, r3, r8, lsl #14 */
/* @0x101448 .word 0xffffc294 */
/* @0x10144c .word 0x002376fc */
/* @0x101450 .word 0xffffc298 */
/* @0x101454 .word 0x002376f0 */
/* @0x101458 .word 0xffffc29c */
/* @0x10145c eoreq r7, r3, r4, ror #13 */
/* @0x101460 .word 0xffffc2a0 */
/* @0x101464 .word 0x002376d8 */
/* @0x101468 .word 0xffffc2a4 */
/* @0x10146c .word 0x002376d0 */
/* @0x101470 .word 0xffffc2a8 */
/* @0x101474 eoreq r7, r3, r8, asr #13 */
/* @0x101478 .word 0xffffc2ac */
/* @0x10147c .word 0x002376bc */
/* @0x101480 .word 0xffffc2b0 */
/* @0x101484 .word 0x002376b0 */
/* @0x101488 .word 0xffffc2b4 */
/* @0x10148c eoreq r7, r3, r4, lsr #13 */
/* @0x101490 .word 0xffffc2b8 */
/* @0x101494 mlaeq r3, r8, r6, r7 */
/* @0x101498 .word 0xffffc2bc */
/* @0x10149c eoreq r7, r3, r12, lsl #13 */
/* @0x1014a0 .word 0xffffc2c0 */
/* @0x1014a4 eoreq r7, r3, r0, lsl #13 */
/* @0x1014a8 .word 0xffffc2c4 */
/* @0x1014ac eoreq r7, r3, r4, ror r6 */
/* @0x1014b0 .word 0xffffc2c8 */
/* @0x1014b4 eoreq r7, r3, r8, ror #12 */
/* @0x1014b8 .word 0xffffc2cc */
/* @0x1014bc eoreq r7, r3, r12, asr r6 */
/* @0x1014c0 .word 0xffffc2d0 */
/* @0x1014c4 eoreq r7, r3, r0, asr r6 */
/* @0x1014c8 .word 0xffffc2d4 */
/* @0x1014cc eoreq r7, r3, r0, asr #12 */
/* @0x1014d0 .word 0xffffc2d8 */
/* @0x1014d4 eoreq r7, r3, r4, lsr r6 */
/* @0x1014d8 .word 0xffffc2dc */
/* @0x1014dc eoreq r7, r3, r8, lsr #12 */
/* @0x1014e0 .word 0xffffc2e0 */
/* @0x1014e4 eoreq r7, r3, r12, lsl r6 */
/* @0x1014e8 .word 0xffffc2e4 */
/* @0x1014ec eoreq r7, r3, r4, lsl r6 */
/* @0x1014f0 .word 0xffffc2e8 */
/* @0x1014f4 eoreq r7, r3, r12, lsl #12 */
/* @0x1014f8 .word 0xffffc2ec */
/* @0x1014fc eoreq r7, r3, r8, lsl #12 */
/* @0x101500 .word 0xffffc2f0 */
/* @0x101504 eoreq r7, r3, r0, lsl #12 */
/* @0x101508 .word 0xffffc2f4 */
/* @0x10150c .word 0x002375f4 */
/* @0x101510 .word 0xffffc2f8 */
/* @0x101514 eoreq r7, r3, r8, ror #11 */
/* @0x101518 .word 0xffffc2fc */
/* @0x10151c .word 0x002375dc */
/* @0x101520 .word 0xffffc300 */
/* @0x101524 .word 0x002375d0 */
/* @0x101528 .word 0xffffc304 */
/* @0x10152c eoreq r7, r3, r0, asr #11 */
/* @0x101530 .word 0xffffc308 */
/* @0x101534 .word 0x002375b8 */
/* @0x101538 .word 0xffffc30c */
/* @0x10153c eoreq r7, r3, r12, lsr #11 */
/* @0x101540 .word 0xffffc310 */
/* @0x101544 eoreq r7, r3, r0, lsr #11 */
/* @0x101548 .word 0xffffc314 */
/* @0x10154c mlaeq r3, r4, r5, r7 */
/* @0x101550 .word 0xffffc318 */
/* @0x101554 eoreq r7, r3, r8, lsl #11 */
/* @0x101558 .word 0xffffc31c */
/* @0x10155c eoreq r7, r3, r8, ror r5 */
/* @0x101560 .word 0xffffc320 */
/* @0x101564 eoreq r7, r3, r8, ror #10 */
/* @0x101568 .word 0xffffc324 */
/* @0x10156c eoreq r7, r3, r12, asr r5 */
/* @0x101570 .word 0xffffc328 */
/* @0x101574 eoreq r7, r3, r12, asr #10 */
/* @0x101578 .word 0xffffc32c */
/* @0x10157c eoreq r7, r3, r12, lsr r5 */
/* @0x101580 .word 0xffffc330 */
/* @0x101584 eoreq r7, r3, r0, lsr r5 */
/* @0x101588 .word 0xffffc334 */
/* @0x10158c eoreq r7, r3, r4, lsr #10 */
/* @0x101590 .word 0xffffc338 */
/* @0x101594 eoreq r7, r3, r8, lsl r5 */
/* @0x101598 .word 0xffffc33c */
/* @0x10159c eoreq r7, r3, r12, lsl #10 */
/* @0x1015a0 .word 0xffffc340 */
/* @0x1015a4 eoreq r7, r3, r0, lsl #10 */
/* @0x1015a8 .word 0xffffc344 */
/* @0x1015ac .word 0x002374f8 */
/* @0x1015b0 .word 0xffffc348 */
/* @0x1015b4 .word 0x002374f0 */
/* @0x1015b8 .word 0xffffc34c */
/* @0x1015bc eoreq r7, r3, r4, ror #9 */
/* @0x1015c0 .word 0xffffc350 */
/* @0x1015c4 .word 0x002374d8 */
/* @0x1015c8 .word 0xffffc354 */
/* @0x1015cc .word 0x002374d0 */
/* @0x1015d0 .word 0xffffc358 */
/* @0x1015d4 eoreq r7, r3, r12, asr #9 */
/* @0x1015d8 .word 0xffffc35c */
/* @0x1015dc eoreq r7, r3, r4, asr #9 */
/* @0x1015e0 .word 0xffffc360 */
/* @0x1015e4 .word 0x002374bc */
/* @0x1015e8 .word 0xffffc364 */
/* @0x1015ec .word 0x002374b4 */
/* @0x1015f0 .word 0xffffc368 */
/* @0x1015f4 eoreq r7, r3, r8, lsr #9 */
/* @0x1015f8 .word 0xffffc36c */
/* @0x1015fc mlaeq r3, r8, r4, r7 */
/* @0x101600 .word 0xffffc370 */
/* @0x101604 mlaeq r3, r0, r4, r7 */
/* @0x101608 .word 0xffffc374 */
/* @0x10160c eoreq r7, r3, r8, lsl #9 */
/* @0x101610 .word 0xffffc378 */
/* @0x101614 eoreq r7, r3, r8, lsl #9 */
/* @0x101618 .word 0xffffc37c */
/* @0x10161c eoreq r7, r3, r8, lsl #9 */
/* @0x101620 .word 0xffffc380 */
/* @0x101624 eoreq r7, r3, r0, lsl #9 */
/* @0x101628 .word 0xffffc384 */
/* @0x10162c eoreq r7, r3, r8, ror r4 */
/* @0x101630 .word 0xffffc388 */
/* @0x101634 eoreq r7, r3, r0, ror r4 */
/* @0x101638 .word 0xffffc38c */
/* @0x10163c eoreq r7, r3, r8, ror #8 */
/* @0x101640 .word 0xffffc390 */
/* @0x101644 eoreq r7, r3, r0, ror #8 */
/* @0x101648 .word 0xffffc394 */
/* @0x10164c eoreq r7, r3, r8, asr r4 */
/* @0x101650 .word 0xffffc398 */
/* @0x101654 eoreq r7, r3, r12, asr #8 */
/* @0x101658 .word 0xffffc39c */
/* @0x10165c eoreq r7, r3, r12, asr #8 */
/* @0x101660 .word 0xffffc3a0 */
/* @0x101664 eoreq r7, r3, r12, asr #8 */
/* @0x101668 .word 0xffffc3a4 */
/* @0x10166c eoreq r7, r3, r12, asr #8 */
/* @0x101670 .word 0xffffc3a8 */
/* @0x101674 eoreq r7, r3, r8, asr #8 */
/* @0x101678 .word 0xffffc3ac */
/* @0x10167c eoreq r7, r3, r4, asr #8 */
/* @0x101680 .word 0xffffc3b0 */
/* @0x101684 eoreq r7, r3, r0, asr #8 */
/* @0x101688 .word 0xffffc3b4 */
/* @0x10168c eoreq r7, r3, r12, lsr r4 */
/* @0x101690 .word 0xffffc3b8 */
/* @0x101694 eoreq r7, r3, r4, lsr r4 */
/* @0x101698 .word 0xffffc3bc */
/* @0x10169c eoreq r7, r3, r12, lsr #8 */
/* @0x1016a0 .word 0xffffc3c0 */
/* @0x1016a4 eoreq r7, r3, r0, lsr #8 */
/* @0x1016a8 .word 0xffffc3c4 */
/* @0x1016ac eoreq r7, r3, r4, lsl r4 */
/* @0x1016b0 .word 0xffffc3c8 */
/* @0x1016b4 eoreq r7, r3, r8, lsl #8 */
/* @0x1016b8 .word 0xffffc3cc */
/* @0x1016bc .word 0x002373fc */
/* @0x1016c0 .word 0xffffc3d0 */
/* @0x1016c4 .word 0x002373f0 */
/* @0x1016c8 .word 0xffffc3d4 */
/* @0x1016cc eoreq r7, r3, r4, ror #7 */
/* @0x1016d0 .word 0xffffc24c */
/* @0x1016d4 eoreq r6, r3, r0, lsl #26 */
/* @0x1016d8 .word 0xffffc3d8 */
/* @0x1016dc .word 0x002373bc */
/* @0x1016e0 .word 0xffffc3dc */
/* @0x1016e4 .word 0x002373b0 */
/* @0x1016e8 .word 0xffffc3e0 */
/* @0x1016ec eoreq r7, r3, r8, lsr #7 */
/* @0x1016f0 .word 0xffffc3e4 */
/* @0x1016f4 mlaeq r3, r8, r3, r7 */
/* @0x1016f8 .word 0xffffc3e8 */
/* @0x1016fc mlaeq r3, r0, r3, r7 */
/* @0x101700 .word 0xffffc3ec */
/* @0x101704 eoreq r7, r3, r8, lsl #7 */
/* @0x101708 .word 0xffffc3f0 */
/* @0x10170c eoreq r7, r3, r0, lsl #7 */
/* @0x101710 .word 0xffffc3f4 */
/* @0x101714 eoreq r7, r3, r12, ror r3 */
/* @0x101718 .word 0xffffc3f8 */
/* @0x10171c eoreq r7, r3, r4, ror r3 */
/* @0x101720 .word 0xffffc3fc */
/* @0x101724 eoreq r7, r3, r12, ror #6 */
/* @0x101728 .word 0xffffc400 */
/* @0x10172c eoreq r7, r3, r8, ror #6 */
/* @0x101730 .word 0xffffc404 */
/* @0x101734 eoreq r7, r3, r4, ror #6 */
/* @0x101738 .word 0xffffc408 */
/* @0x10173c eoreq r7, r3, r0, ror #6 */
/* @0x101740 .word 0xffffc250 */
/* @0x101744 eoreq r6, r3, r4, lsl #23 */
/* @0x101748 .word 0xffffc40c */
/* @0x10174c eoreq r7, r3, r8, asr #6 */
/* @0x101750 .word 0xffffc410 */
/* @0x101754 eoreq r7, r3, r12, lsr r3 */
/* @0x101758 .word 0xffffc414 */
/* @0x10175c eoreq r7, r3, r0, lsr r3 */
/* @0x101760 .word 0xffffc418 */
/* @0x101764 eoreq r7, r3, r4, lsr #6 */
/* @0x101768 .word 0xffffc41c */
/* @0x10176c eoreq r7, r3, r12, lsl r3 */
/* @0x101770 .word 0xffffc420 */
/* @0x101774 eoreq r7, r3, r8, lsl r3 */
/* @0x101778 .word 0xffffc424 */
/* @0x10177c eoreq r7, r3, r4, lsl r3 */
/* @0x101780 .word 0xffffc428 */
/* @0x101784 eoreq r7, r3, r0, lsl r3 */
/* @0x101788 .word 0xffffc42c */
/* @0x10178c eoreq r7, r3, r12, lsl #6 */
/* @0x101790 .word 0xffffc430 */
/* @0x101794 eoreq r7, r3, r8, lsl #6 */
/* @0x101798 .word 0xffffc434 */
/* @0x10179c .word 0x002372fc */
/* @0x1017a0 .word 0xffffc438 */
/* @0x1017a4 .word 0x002372f0 */
/* @0x1017a8 .word 0xffffc43c */
/* @0x1017ac .word 0x002372f0 */
/* @0x1017b0 .word 0xffffc440 */
/* @0x1017b4 eoreq r7, r3, r12, ror #5 */
/* @0x1017b8 .word 0xffffc444 */
/* @0x1017bc eoreq r7, r3, r8, ror #5 */
/* @0x1017c0 .word 0xffffc448 */
/* @0x1017c4 .word 0x002372dc */
/* @0x1017c8 .word 0xffffc44c */
/* @0x1017cc .word 0x002372d0 */
/* @0x1017d0 .word 0xffffc450 */
/* @0x1017d4 eoreq r7, r3, r4, asr #5 */

/* ── FUNC 0x1017d8 · dsMapClear · size=64 · insn=16 */
/* @0x1017d8 vmov s13, r0 */
/* @0x1017dc mov r12, #0 */
/* @0x1017e0 str lr, [sp, #-0x4]! */
/* @0x1017e4 vcvt.f64.s32 d7, s13 */
/* @0x1017e8 sub sp, sp, #44 */
/* @0x1017ec mov r1, r12 */
/* @0x1017f0 add r3, sp, #24 */
/* @0x1017f4 mov r2, r12 */
/* @0x1017f8 str r3, [sp] */
/* @0x1017fc add r0, sp, #8 */
/* @0x101800 mov r3, #1 */
/* @0x101804 str r12, [sp, #0x24] */
/* @0x101808 vstr d7, [sp, #24] */
/* @0x10180c bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_> */
/* @0x101810 add sp, sp, #44 */
/* @0x101814 ldr pc, [sp], #4 */

/* ── FUNC 0x101818 · dsMapCreate · size=56 · insn=14 */
/* @0x101818 str lr, [sp, #-0x4]! */
/* @0x10181c sub sp, sp, #28 */
/* @0x101820 add r0, sp, #24 */
/* @0x101824 mov r3, #0 */
/* @0x101828 mov r1, r3 */
/* @0x10182c str r3, [sp] */
/* @0x101830 mov r2, r3 */
/* @0x101834 str r3, [r0, #-0x10]! */
/* @0x101838 bl 0x1000f4 <_Z13F_DsMapCreateR6RValueP9CInstanceS2_iPS_> */
/* @0x10183c vldr d7, [sp, #8] */
/* @0x101840 vcvt.s32.f64 s15, d7 */
/* @0x101844 vmov r0, s15 */
/* @0x101848 add sp, sp, #28 */
/* @0x10184c ldr pc, [sp], #4 */

/* ── FUNC 0x101850 · dsMapAddInt · size=144 · insn=36 */
/* @0x101850 vmov s15, r0 */
/* @0x101854 mvn r3, #-16777216 */
/* @0x101858 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x10185c vcvt.f64.s32 d6, s15 */
/* @0x101860 sub sp, sp, #84 */
/* @0x101864 mov r6, #0 */
/* @0x101868 add r7, sp, #80 */
/* @0x10186c add r0, sp, #48 */
/* @0x101870 mov r4, #0 */
/* @0x101874 mov r5, #0 */
/* @0x101878 str r3, [sp, #0x3c] */
/* @0x10187c str r3, [sp, #0x4c] */
/* @0x101880 str r6, [sp, #0x10] */
/* @0x101884 vmov r8, r9, d6 */
/* @0x101888 str r6, [sp, #0x28] */
/* @0x10188c str r6, [sp, #0x38] */
/* @0x101890 str r6, [sp, #0x48] */
/* @0x101894 str r6, [sp, #0x2c] */
/* @0x101898 strd r4, r5, [sp, #48] */
/* @0x10189c strd r4, r5, [sp, #64] */
/* @0x1018a0 strd r8, r9, [r7, #-48]! */
/* @0x1018a4 str r2, [sp, #0xc] */
/* @0x1018a8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x1018ac ldr r2, [sp, #0xc] */
/* @0x1018b0 mov r1, r6 */
/* @0x1018b4 str r7, [sp] */
/* @0x1018b8 add r0, sp, #16 */
/* @0x1018bc mov r3, #3 */
/* @0x1018c0 str r6, [sp, #0x4c] */
/* @0x1018c4 vmov s13, r2 */
/* @0x1018c8 mov r2, r6 */
/* @0x1018cc vcvt.f64.s32 d7, s13 */
/* @0x1018d0 vstr d7, [sp, #64] */
/* @0x1018d4 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x1018d8 add sp, sp, #84 */
/* @0x1018dc pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x1018e0 · dsMapAddDouble · size=136 · insn=34 */
/* @0x1018e0 vmov s13, r0 */
/* @0x1018e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1018e8 vcvt.f64.s32 d7, s13 */
/* @0x1018ec sub sp, sp, #76 */
/* @0x1018f0 mov r8, #0 */
/* @0x1018f4 add r9, sp, #72 */
/* @0x1018f8 add r0, sp, #40 */
/* @0x1018fc mov r6, r2 */
/* @0x101900 mov r7, r3 */
/* @0x101904 mov r4, #0 */
/* @0x101908 mvn r3, #-16777216 */
/* @0x10190c mov r5, #0 */
/* @0x101910 str r3, [sp, #0x34] */
/* @0x101914 str r3, [sp, #0x44] */
/* @0x101918 vmov r10, r11, d7 */
/* @0x10191c str r8, [sp, #0x8] */
/* @0x101920 str r8, [sp, #0x20] */
/* @0x101924 str r8, [sp, #0x30] */
/* @0x101928 str r8, [sp, #0x40] */
/* @0x10192c str r8, [sp, #0x24] */
/* @0x101930 strd r4, r5, [sp, #40] */
/* @0x101934 strd r4, r5, [sp, #56] */
/* @0x101938 strd r10, r11, [r9, #-48]! */
/* @0x10193c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x101940 mov r1, r8 */
/* @0x101944 str r9, [sp] */
/* @0x101948 mov r2, r8 */
/* @0x10194c add r0, sp, #8 */
/* @0x101950 mov r3, #3 */
/* @0x101954 strd r6, r7, [sp, #56] */
/* @0x101958 str r8, [sp, #0x44] */
/* @0x10195c bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x101960 add sp, sp, #76 */
/* @0x101964 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x101968 · dsMapAddInt64 · size=140 · insn=35 */
/* @0x101968 vmov s13, r0 */
/* @0x10196c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x101970 vcvt.f64.s32 d7, s13 */
/* @0x101974 sub sp, sp, #76 */
/* @0x101978 mov r8, #0 */
/* @0x10197c add r9, sp, #72 */
/* @0x101980 add r0, sp, #40 */
/* @0x101984 mov r6, r2 */
/* @0x101988 mov r7, r3 */
/* @0x10198c mov r4, #0 */
/* @0x101990 mvn r3, #-16777216 */
/* @0x101994 mov r5, #0 */
/* @0x101998 str r3, [sp, #0x34] */
/* @0x10199c str r3, [sp, #0x44] */
/* @0x1019a0 vmov r10, r11, d7 */
/* @0x1019a4 str r8, [sp, #0x8] */
/* @0x1019a8 str r8, [sp, #0x20] */
/* @0x1019ac str r8, [sp, #0x30] */
/* @0x1019b0 str r8, [sp, #0x40] */
/* @0x1019b4 str r8, [sp, #0x24] */
/* @0x1019b8 strd r4, r5, [sp, #40] */
/* @0x1019bc strd r4, r5, [sp, #56] */
/* @0x1019c0 strd r10, r11, [r9, #-48]! */
/* @0x1019c4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x1019c8 mov r1, r8 */
/* @0x1019cc str r9, [sp] */
/* @0x1019d0 mov r2, r8 */
/* @0x1019d4 add r0, sp, #8 */
/* @0x1019d8 mov r3, #3 */
/* @0x1019dc mov r12, #10 */
/* @0x1019e0 strd r6, r7, [sp, #56] */
/* @0x1019e4 str r12, [sp, #0x44] */
/* @0x1019e8 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x1019ec add sp, sp, #76 */
/* @0x1019f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1019f4 · dsMapAddString · size=144 · insn=36 */
/* @0x1019f4 vmov s13, r0 */
/* @0x1019f8 mvn r3, #-16777216 */
/* @0x1019fc push {r4, r5, r6, r7, r8, lr} */
/* @0x101a00 vcvt.f64.s32 d7, s13 */
/* @0x101a04 sub sp, sp, #72 */
/* @0x101a08 mov r4, #0 */
/* @0x101a0c mov r5, #0 */
/* @0x101a10 add r7, sp, #72 */
/* @0x101a14 strd r4, r5, [sp, #8] */
/* @0x101a18 mov r8, r2 */
/* @0x101a1c strd r4, r5, [sp, #40] */
/* @0x101a20 add r0, sp, #40 */
/* @0x101a24 strd r4, r5, [sp, #56] */
/* @0x101a28 mov r6, #0 */
/* @0x101a2c str r3, [sp, #0x14] */
/* @0x101a30 vmov r4, r5, d7 */
/* @0x101a34 str r3, [sp, #0x34] */
/* @0x101a38 str r3, [sp, #0x44] */
/* @0x101a3c str r6, [sp, #0x10] */
/* @0x101a40 str r6, [sp, #0x20] */
/* @0x101a44 str r6, [sp, #0x30] */
/* @0x101a48 str r6, [sp, #0x40] */
/* @0x101a4c str r6, [sp, #0x24] */
/* @0x101a50 strd r4, r5, [r7, #-48]! */
/* @0x101a54 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x101a58 mov r1, r8 */
/* @0x101a5c add r0, sp, #56 */
/* @0x101a60 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x101a64 mov r1, r6 */
/* @0x101a68 str r7, [sp] */
/* @0x101a6c mov r2, r6 */
/* @0x101a70 add r0, sp, #8 */
/* @0x101a74 mov r3, #3 */
/* @0x101a78 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x101a7c add sp, sp, #72 */
/* @0x101a80 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x101a84 · dsMapAddPtr · size=136 · insn=34 */
/* @0x101a84 vmov s13, r0 */
/* @0x101a88 mvn r3, #-16777216 */
/* @0x101a8c push {r4, r5, r6, r7, r8, r10, r11, lr} */
/* @0x101a90 vcvt.f64.s32 d7, s13 */
/* @0x101a94 sub sp, sp, #72 */
/* @0x101a98 mov r6, #0 */
/* @0x101a9c add r7, sp, #72 */
/* @0x101aa0 add r0, sp, #40 */
/* @0x101aa4 mov r8, r2 */
/* @0x101aa8 mov r4, #0 */
/* @0x101aac mov r5, #0 */
/* @0x101ab0 str r3, [sp, #0x34] */
/* @0x101ab4 str r3, [sp, #0x44] */
/* @0x101ab8 str r6, [sp, #0x8] */
/* @0x101abc vmov r10, r11, d7 */
/* @0x101ac0 str r6, [sp, #0x20] */
/* @0x101ac4 str r6, [sp, #0x30] */
/* @0x101ac8 str r6, [sp, #0x40] */
/* @0x101acc str r6, [sp, #0x24] */
/* @0x101ad0 strd r4, r5, [sp, #40] */
/* @0x101ad4 strd r4, r5, [sp, #56] */
/* @0x101ad8 strd r10, r11, [r7, #-48]! */
/* @0x101adc bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x101ae0 mov r12, #3 */
/* @0x101ae4 mov r1, r6 */
/* @0x101ae8 str r7, [sp] */
/* @0x101aec mov r2, r6 */
/* @0x101af0 mov r3, r12 */
/* @0x101af4 add r0, sp, #8 */
/* @0x101af8 str r8, [sp, #0x38] */
/* @0x101afc str r12, [sp, #0x44] */
/* @0x101b00 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x101b04 add sp, sp, #72 */
/* @0x101b08 pop {r4, r5, r6, r7, r8, r10, r11, pc} */
