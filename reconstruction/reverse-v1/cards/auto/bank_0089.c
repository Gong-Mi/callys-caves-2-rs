/* libyoyo.so 覆盖卡组 0089
 * 函数 0x156608..0x156fb0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x156608 · F_YoYo_AchievementsShowLeaderboards(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x156608 b 0x161280 <_Z28Achievement_Show_Leaderboardv> */

/* ── FUNC 0x15660c · F_YoYo_AchievementsLoadFriends(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x15660c b 0x161138 <_Z24Achievement_Load_Friendsv> */

/* ── FUNC 0x156610 · F_YoYo_Achievement_GetPic(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x156610 push {r3, lr} */
/* @0x156614 mov r1, #0 */
/* @0x156618 ldr r0, [sp, #0x8] */
/* @0x15661c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156620 pop {r3, lr} */
/* @0x156624 b 0x161168 <_Z20Achievement_Load_PicPc> */

/* ── FUNC 0x156628 · F_YoYo_Achievement_GetInfo(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x156628 push {r3, lr} */
/* @0x15662c mov r3, #0 */
/* @0x156630 ldr r12, [sp, #0x8] */
/* @0x156634 mov r1, r3 */
/* @0x156638 str r3, [r0, #0xc] */
/* @0x15663c str r3, [r0] */
/* @0x156640 str r3, [r0, #0x4] */
/* @0x156644 mov r0, r12 */
/* @0x156648 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x15664c pop {r3, lr} */
/* @0x156650 b 0x1610e8 <_Z20Achievement_Get_InfoPc> */

/* ── FUNC 0x156654 · F_YoYo_AchievementLoadLeaderboard(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x156654 push {r4, r5, r6, r7, r8, lr} */
/* @0x156658 mov r3, #0 */
/* @0x15665c ldr r4, [sp, #0x18] */
/* @0x156660 mov r1, r3 */
/* @0x156664 str r3, [r0, #0xc] */
/* @0x156668 str r3, [r0] */
/* @0x15666c str r3, [r0, #0x4] */
/* @0x156670 mov r0, r4 */
/* @0x156674 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156678 mov r1, #1 */
/* @0x15667c mov r7, r0 */
/* @0x156680 mov r0, r4 */
/* @0x156684 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156688 mov r1, #2 */
/* @0x15668c mov r6, r0 */
/* @0x156690 mov r0, r4 */
/* @0x156694 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156698 mov r1, #3 */
/* @0x15669c mov r5, r0 */
/* @0x1566a0 mov r0, r4 */
/* @0x1566a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1566a8 mov r1, r6 */
/* @0x1566ac mov r2, r5 */
/* @0x1566b0 mov r3, r0 */
/* @0x1566b4 mov r0, r7 */
/* @0x1566b8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1566bc b 0x16107c <_Z28Achievement_Load_LeaderboardPciii> */

/* ── FUNC 0x1566c0 · F_YoYo_AchievementLoadProgress(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x1566c0 mov r3, #0 */
/* @0x1566c4 str r3, [r0, #0xc] */
/* @0x1566c8 str r3, [r0] */
/* @0x1566cc str r3, [r0, #0x4] */
/* @0x1566d0 b 0x161208 <_Z25Achievement_Load_Progressv> */

/* ── FUNC 0x1566d4 · F_YoYo_AchievementSendChallenge(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x1566d4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1566d8 mov r3, #0 */
/* @0x1566dc ldr r4, [sp, #0x18] */
/* @0x1566e0 mov r1, r3 */
/* @0x1566e4 str r3, [r0, #0xc] */
/* @0x1566e8 str r3, [r0] */
/* @0x1566ec str r3, [r0, #0x4] */
/* @0x1566f0 mov r0, r4 */
/* @0x1566f4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1566f8 mov r1, #1 */
/* @0x1566fc mov r5, r0 */
/* @0x156700 mov r0, r4 */
/* @0x156704 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156708 mov r1, #2 */
/* @0x15670c mov r8, r0 */
/* @0x156710 mov r0, r4 */
/* @0x156714 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156718 mov r1, #3 */
/* @0x15671c mov r7, r0 */
/* @0x156720 mov r0, r4 */
/* @0x156724 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156728 mov r1, #4 */
/* @0x15672c mov r6, r0 */
/* @0x156730 mov r0, r4 */
/* @0x156734 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156738 mov r1, r8 */
/* @0x15673c mov r2, r7 */
/* @0x156740 mov r3, r6 */
/* @0x156744 str r0, [sp, #0x18] */
/* @0x156748 mov r0, r5 */
/* @0x15674c pop {r4, r5, r6, r7, r8, lr} */
/* @0x156750 b 0x161078 <_Z26Achievement_Send_ChallengePcS_iiS_> */

/* ── FUNC 0x156754 · F_YoYo_AchievementGetChallenges(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x156754 b 0x161074 <_Z26Achievement_Get_Challengesv> */

/* ── FUNC 0x156758 · F_YoYo_AchievementShowChallengeNotifications(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x156758 push {r4, r5, r6, lr} */
/* @0x15675c mov r1, #0 */
/* @0x156760 ldr r4, [sp, #0x10] */
/* @0x156764 mov r0, r4 */
/* @0x156768 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15676c mov r1, #0 */
/* @0x156770 mov r6, r0 */
/* @0x156774 mov r0, r4 */
/* @0x156778 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15677c mov r1, #2 */
/* @0x156780 mov r5, r0 */
/* @0x156784 mov r0, r4 */
/* @0x156788 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15678c mov r1, r5 */
/* @0x156790 mov r2, r0 */
/* @0x156794 mov r0, r6 */
/* @0x156798 pop {r4, r5, r6, lr} */
/* @0x15679c b 0x161070 <_Z40Achievement_Show_Challenge_Notificationsiii> */

/* ── FUNC 0x1567a0 · F_YoYo_AchievementReset(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1567a0 b 0x16120c <_Z17Achievement_Resetv> */

/* ── FUNC 0x1567a4 · CloudFuncAsync(HTTP_REQ_CONTEXT*, void*, int*) · size=324 · insn=81 */
/* @0x1567a4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1567a8 mov r4, r0 */
/* @0x1567ac ldr r1, [pc, #0x11c] */
/* @0x1567b0 mov r3, #1 */
/* @0x1567b4 ldr r0, [r0, #0x3c] */
/* @0x1567b8 sub sp, sp, #72 */
/* @0x1567bc add r1, pc, r1 */
/* @0x1567c0 mov r7, r2 */
/* @0x1567c4 add r0, r0, #2 */
/* @0x1567c8 movw r2, #0x38a */
/* @0x1567cc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1567d0 ldr r2, [r4, #0x3c] */
/* @0x1567d4 ldr r1, [r4, #0x34] */
/* @0x1567d8 mov r6, r0 */
/* @0x1567dc bl 0xb65bc <memcpy@plt> */
/* @0x1567e0 ldr r2, [r4, #0x3c] */
/* @0x1567e4 mov r3, #0 */
/* @0x1567e8 strb r3, [r6, r2] */
/* @0x1567ec ldr r2, [r4, #0x3c] */
/* @0x1567f0 add r2, r6, r2 */
/* @0x1567f4 strb r3, [r2, #0x1] */
/* @0x1567f8 ldr r5, [r4, #0x28] */
/* @0x1567fc cmp r5, r3 */
/* @0x156800 blt 0x1568c4 <_Z14CloudFuncAsyncP16HTTP_REQ_CONTEXTPvPi+0x120> */
/* @0x156804 mov r0, r6 */
/* @0x156808 movne r10, r3 */
/* @0x15680c bne 0x156824 <_Z14CloudFuncAsyncP16HTTP_REQ_CONTEXTPvPi+0x80> */
/* @0x156810 bl 0xb6538 <strlen@plt> */
/* @0x156814 mov r10, r5 */
/* @0x156818 mov r3, r6 */
/* @0x15681c add r0, r0, #1 */
/* @0x156820 add r0, r6, r0 */
/* @0x156824 ldr r2, [r4, #0x24] */
/* @0x156828 vmov s12, r5 */
/* @0x15682c mov r1, #0 */
/* @0x156830 ldr r9, [pc, #0x9c] */
/* @0x156834 vcvt.f64.s32 d7, s12 */
/* @0x156838 str r1, [sp] */
/* @0x15683c vmov s13, r2 */
/* @0x156840 str r1, [sp, #0x30] */
/* @0x156844 ldr r8, [pc, #0x8c] */
/* @0x156848 mov r4, #0 */
/* @0x15684c ldr lr, [pc, #0x88] */
/* @0x156850 mov r5, #0 */
/* @0x156854 ldr r12, [pc, #0x84] */
/* @0x156858 add r9, pc, r9 */
/* @0x15685c ldr r1, [pc, #0x80] */
/* @0x156860 add lr, pc, lr */
/* @0x156864 add r12, pc, r12 */
/* @0x156868 str r0, [sp, #0x20] */
/* @0x15686c vcvt.f64.s32 d6, s13 */
/* @0x156870 str r3, [sp, #0x40] */
/* @0x156874 vstr d7, [sp, #40] */
/* @0x156878 str lr, [sp, #0x24] */
/* @0x15687c str r12, [sp, #0x34] */
/* @0x156880 add r1, pc, r1 */
/* @0x156884 add r8, pc, r8 */
/* @0x156888 strd r4, r5, [sp, #8] */
/* @0x15688c strd r4, r5, [sp, #24] */
/* @0x156890 mov r0, #5 */
/* @0x156894 str r10, [sp, #0x10] */
/* @0x156898 strd r4, r5, [sp, #56] */
/* @0x15689c vmov r2, r3, d6 */
/* @0x1568a0 str r9, [sp, #0x4] */
/* @0x1568a4 str r8, [sp, #0x14] */
/* @0x1568a8 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x1568ac str r0, [r7] */
/* @0x1568b0 mov r0, r6 */
/* @0x1568b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1568b8 mov r0, #67 */
/* @0x1568bc add sp, sp, #72 */
/* @0x1568c0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1568c4 mov r10, r6 */
/* @0x1568c8 mov r0, r3 */
/* @0x1568cc b 0x156824 <_Z14CloudFuncAsyncP16HTTP_REQ_CONTEXTPvPi+0x80> */
/* @0x1568d0 andseq pc, lr, r8, lsr #27 */
/* @0x1568d4 andseq pc, lr, r8, asr #26 */
/* @0x1568d8 andseq pc, lr, r8, lsr #26 */
/* @0x1568dc ldrsheq r10, [sp], -r0 */
/* @0x1568e0 andseq pc, lr, r8, asr sp */
/* @0x1568e4 andseq r10, sp, r0, asr #3 */

/* ── FUNC 0x1568e8 · F_YoYo_CloudFileSave(RValue&, CInstance*, CInstance*, int, RValue*) · size=540 · insn=135 */
/* @0x1568e8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1568ec cmp r3, #2 */
/* @0x1568f0 ldr r5, [pc, #0x1e0] */
/* @0x1568f4 sub sp, sp, #1024 */
/* @0x1568f8 ldr r3, [pc, #0x1dc] */
/* @0x1568fc sub sp, sp, #8 */
/* @0x156900 add r5, pc, r5 */
/* @0x156904 mov r1, #0 */
/* @0x156908 mov r4, r0 */
/* @0x15690c ldr r7, [sp, #0x428] */
/* @0x156910 ldr r6, [r5, r3] */
/* @0x156914 str r1, [r0, #0xc] */
/* @0x156918 str r1, [r0, #0x4] */
/* @0x15691c ldr r3, [r6] */
/* @0x156920 str r1, [r0] */
/* @0x156924 str r3, [sp, #0x404] */
/* @0x156928 beq 0x156954 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x15692c ldr r0, [pc, #0x1ac] */
/* @0x156930 add r0, pc, r0 */
/* @0x156934 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x156938 ldr r2, [sp, #0x404] */
/* @0x15693c ldr r3, [r6] */
/* @0x156940 cmp r2, r3 */
/* @0x156944 bne 0x156ad4 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x156948 add sp, sp, #1024 */
/* @0x15694c add sp, sp, #8 */
/* @0x156950 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x156954 ldr r3, [r7, #0xc] */
/* @0x156958 cmp r3, #1 */
/* @0x15695c beq 0x15697c <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x156960 ldr r3, [r7, #0x1c] */
/* @0x156964 cmp r3, #1 */
/* @0x156968 beq 0x15697c <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x15696c ldr r0, [pc, #0x170] */
/* @0x156970 add r0, pc, r0 */
/* @0x156974 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x156978 b 0x156938 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x15697c mov r1, #0 */
/* @0x156980 mov r0, r7 */
/* @0x156984 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156988 mov r8, r0 */
/* @0x15698c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x156990 cmp r0, #0 */
/* @0x156994 bne 0x156a80 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x156998 mov r0, r8 */
/* @0x15699c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1569a0 cmp r0, #0 */
/* @0x1569a4 beq 0x156a98 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x1569a8 add r9, sp, #4 */
/* @0x1569ac mov r2, r8 */
/* @0x1569b0 mov r1, #1024 */
/* @0x1569b4 mov r0, r9 */
/* @0x1569b8 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x1569bc ldr r1, [pc, #0x124] */
/* @0x1569c0 mov r0, r9 */
/* @0x1569c4 add r1, pc, r1 */
/* @0x1569c8 bl 0xb6844 <fopen@plt> */
/* @0x1569cc subs r8, r0, #0 */
/* @0x1569d0 beq 0x156ac0 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x1569d4 mov r1, #0 */
/* @0x1569d8 mov r2, #2 */
/* @0x1569dc bl 0xb68d4 <fseek@plt> */
/* @0x1569e0 mov r0, r8 */
/* @0x1569e4 bl 0xb68e0 <ftell@plt> */
/* @0x1569e8 mov r1, #0 */
/* @0x1569ec mov r2, r1 */
/* @0x1569f0 mov r10, r0 */
/* @0x1569f4 mov r0, r8 */
/* @0x1569f8 bl 0xb68d4 <fseek@plt> */
/* @0x1569fc ldr r1, [pc, #0xe8] */
/* @0x156a00 add r0, r10, #1 */
/* @0x156a04 movw r2, #0x3f3 */
/* @0x156a08 add r1, pc, r1 */
/* @0x156a0c mov r3, #1 */
/* @0x156a10 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x156a14 mov r2, r10 */
/* @0x156a18 mov r1, #1 */
/* @0x156a1c mov r3, r8 */
/* @0x156a20 mov r9, r0 */
/* @0x156a24 bl 0xb68c8 <fread@plt> */
/* @0x156a28 mov r3, #0 */
/* @0x156a2c mov r0, r8 */
/* @0x156a30 strb r3, [r9, r10] */
/* @0x156a34 bl 0xb6850 <fclose@plt> */
/* @0x156a38 ldr r3, [pc, #0xb0] */
/* @0x156a3c mov r0, r7 */
/* @0x156a40 mov r1, #1 */
/* @0x156a44 ldr r3, [r5, r3] */
/* @0x156a48 ldr r7, [r3] */
/* @0x156a4c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156a50 ldr r3, [pc, #0x9c] */
/* @0x156a54 ldr r2, [r5, r3] */
/* @0x156a58 mov r1, r0 */
/* @0x156a5c mov r0, r9 */
/* @0x156a60 bl 0x1612b0 <_Z17Cloud_String_SavePKcS0_PFiP16HTTP_REQ_CONTEXTPvPiE> */
/* @0x156a64 vmov s15, r7 */
/* @0x156a68 mov r0, r9 */
/* @0x156a6c vcvt.f64.s32 d7, s15 */
/* @0x156a70 vmov r2, r3, d7 */
/* @0x156a74 stm r4, {r2, r3} */
/* @0x156a78 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x156a7c b 0x156938 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x156a80 add r9, sp, #4 */
/* @0x156a84 mov r2, r8 */
/* @0x156a88 mov r1, #1024 */
/* @0x156a8c mov r0, r9 */
/* @0x156a90 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x156a94 b 0x1569bc <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x156a98 ldr r1, [pc, #0x58] */
/* @0x156a9c mov r2, r8 */
/* @0x156aa0 ldr r3, [pc, #0x54] */
/* @0x156aa4 add r1, pc, r1 */
/* @0x156aa8 ldr r3, [r5, r3] */
/* @0x156aac ldr r0, [r3] */
/* @0x156ab0 ldr r3, [r0] */
/* @0x156ab4 ldr r3, [r3, #0xc] */
/* @0x156ab8 blx r3 */
/* @0x156abc b 0x156938 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x156ac0 ldr r1, [pc, #0x38] */
/* @0x156ac4 mov r2, r9 */
/* @0x156ac8 ldr r3, [pc, #0x2c] */
/* @0x156acc add r1, pc, r1 */
/* @0x156ad0 b 0x156aa8 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x1c0> */
/* @0x156ad4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x156ad8 eoreq r11, r9, r0, asr r3 */
/* @0x156adc .word 0xffffbd00 */
/* @0x156ae0 mulseq lr, r8, r12 */
/* @0x156ae4 andseq r12, lr, r12, lsr r0 */
/* @0x156ae8 andseq r1, lr, r4, lsr r2 */
/* @0x156aec andseq pc, lr, r12, asr r11 */
/* @0x156af0 .word 0xffffd628 */
/* @0x156af4 .word 0xffffdf08 */
/* @0x156af8 andseq r9, lr, r0, lsr r5 */
/* @0x156afc .word 0xffffbac4 */
/* @0x156b00 andseq r9, lr, r8, lsl #10 */

/* ── FUNC 0x156b04 · F_YoYo_CloudSynchronise(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x156b04 ldr r2, [pc, #0x3c] */
/* @0x156b08 push {r3, r4, r5, lr} */
/* @0x156b0c ldr r2, [pc, r2] */
/* @0x156b10 mov r4, r0 */
/* @0x156b14 mov r3, #0 */
/* @0x156b18 ldr r0, [pc, #0x2c] */
/* @0x156b1c str r3, [r4] */
/* @0x156b20 ldr r5, [r2] */
/* @0x156b24 ldr r0, [pc, r0] */
/* @0x156b28 str r3, [r4, #0xc] */
/* @0x156b2c str r3, [r4, #0x4] */
/* @0x156b30 bl 0x161390 <_Z17Cloud_SynchronisePFiP16HTTP_REQ_CONTEXTPvPiE> */
/* @0x156b34 vmov s15, r5 */
/* @0x156b38 vcvt.f64.s32 d7, s15 */
/* @0x156b3c vmov r2, r3, d7 */
/* @0x156b40 stm r4, {r2, r3} */
/* @0x156b44 pop {r3, r4, r5, pc} */
/* @0x156b48 eoreq r8, r9, r12, ror #14 */
/* @0x156b4c eoreq r9, r9, r4, lsr r0 */

/* ── FUNC 0x156b50 · F_YoYo_AchievementEvent(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x156b50 push {r3, r4, r5, lr} */
/* @0x156b54 mov r4, r0 */
/* @0x156b58 ldr r3, [pc, #0x40] */
/* @0x156b5c ldr r1, [pc, #0x40] */
/* @0x156b60 ldr r3, [pc, r3] */
/* @0x156b64 ldr r5, [sp, #0x10] */
/* @0x156b68 add r1, pc, r1 */
/* @0x156b6c ldr r0, [r3] */
/* @0x156b70 ldr r2, [r0] */
/* @0x156b74 ldr r3, [r2, #0xc] */
/* @0x156b78 blx r3 */
/* @0x156b7c mov r3, #0 */
/* @0x156b80 mov r0, r5 */
/* @0x156b84 str r3, [r4, #0xc] */
/* @0x156b88 str r3, [r4] */
/* @0x156b8c mov r1, r3 */
/* @0x156b90 str r3, [r4, #0x4] */
/* @0x156b94 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156b98 pop {r3, r4, r5, lr} */
/* @0x156b9c b 0x1611b8 <_Z17Achievement_EventPc> */
/* @0x156ba0 eoreq r6, r9, r0, ror #27 */
/* @0x156ba4 andseq pc, lr, r8, ror r10 */

/* ── FUNC 0x156ba8 · F_YoYo_GetDomain(RValue&, CInstance*, CInstance*, int, RValue*) · size=16 · insn=4 */
/* @0x156ba8 ldr r1, [pc, #0x4] */
/* @0x156bac add r1, pc, r1 */
/* @0x156bb0 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x156bb4 andseq pc, lr, r8, asr r10 */

/* ── FUNC 0x156bb8 · F_YoYo_GetConfig(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x156bb8 ldr r3, [pc, #0x8] */
/* @0x156bbc ldr r3, [pc, r3] */
/* @0x156bc0 ldr r1, [r3] */
/* @0x156bc4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x156bc8 eoreq r8, r9, r0, lsr #31 */

/* ── FUNC 0x156bcc · F_PlayerGetLaunchArgs(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x156bcc ldr r3, [pc, #0x8] */
/* @0x156bd0 ldr r3, [pc, r3] */
/* @0x156bd4 ldr r1, [r3] */
/* @0x156bd8 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x156bdc mlaeq r9, r0, pc, r8 */

/* ── FUNC 0x156be0 · F_ExtensionStubFuncString(RValue&, CInstance*, CInstance*, int, RValue*) · size=8 · insn=2 */
/* @0x156be0 mov r1, #0 */
/* @0x156be4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x156be8 · F_YoYo_OpenURL(RValue&, CInstance*, CInstance*, int, RValue*) · size=472 · insn=118 */
/* @0x156be8 push {r4, r5, r6, r7, r8, lr} */
/* @0x156bec cmp r3, #1 */
/* @0x156bf0 ldr r4, [pc, #0x1ac] */
/* @0x156bf4 sub sp, sp, #1024 */
/* @0x156bf8 sub sp, sp, #8 */
/* @0x156bfc mov r5, r0 */
/* @0x156c00 ldr r4, [pc, r4] */
/* @0x156c04 mov r1, #0 */
/* @0x156c08 str r1, [r0, #0xc] */
/* @0x156c0c ldr r3, [r4] */
/* @0x156c10 str r1, [r0, #0x4] */
/* @0x156c14 ldr r0, [sp, #0x420] */
/* @0x156c18 str r1, [r5] */
/* @0x156c1c str r3, [sp, #0x404] */
/* @0x156c20 beq 0x156c4c <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x156c24 ldr r0, [pc, #0x17c] */
/* @0x156c28 add r0, pc, r0 */
/* @0x156c2c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x156c30 ldr r2, [sp, #0x404] */
/* @0x156c34 ldr r3, [r4] */
/* @0x156c38 cmp r2, r3 */
/* @0x156c3c bne 0x156da0 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x156c40 add sp, sp, #1024 */
/* @0x156c44 add sp, sp, #8 */
/* @0x156c48 pop {r4, r5, r6, r7, r8, pc} */
/* @0x156c4c ldr r3, [r0, #0xc] */
/* @0x156c50 cmp r3, #1 */
/* @0x156c54 beq 0x156c68 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x156c58 ldr r0, [pc, #0x14c] */
/* @0x156c5c add r0, pc, r0 */
/* @0x156c60 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x156c64 b 0x156c30 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x156c68 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156c6c mov r1, #58 */
/* @0x156c70 mov r6, r0 */
/* @0x156c74 bl 0xb6634 <strchr@plt> */
/* @0x156c78 cmp r0, #0 */
/* @0x156c7c beq 0x156ce8 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x156c80 rsb r0, r6, r0 */
/* @0x156c84 cmp r0, #1 */
/* @0x156c88 addne r7, sp, #4 */
/* @0x156c8c beq 0x156ce8 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x156c90 ldr r0, [r6] */
/* @0x156c94 mov r1, r7 */
/* @0x156c98 mov r3, #0 */
/* @0x156c9c str r0, [sp, #0x4] */
/* @0x156ca0 ldr r0, [pc, #0x108] */
/* @0x156ca4 ldrh r12, [r6, #4] */
/* @0x156ca8 ldrb r2, [r6, #0x6] */
/* @0x156cac add r0, pc, r0 */
/* @0x156cb0 strh r12, [r7, #4] */
/* @0x156cb4 strb r2, [r7, #0x6] */
/* @0x156cb8 strb r3, [sp, #0xb] */
/* @0x156cbc bl 0xb66d0 <strcasecmp@plt> */
/* @0x156cc0 subs r1, r0, #0 */
/* @0x156cc4 beq 0x156cd8 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x156cc8 mov r0, r6 */
/* @0x156ccc bl 0x160eec <_Z7OpenURLPKc> */
/* @0x156cd0 stm r5, {r0, r1} */
/* @0x156cd4 b 0x156c30 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x156cd8 ldr r0, [pc, #0xd4] */
/* @0x156cdc add r0, pc, r0 */
/* @0x156ce0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x156ce4 b 0x156c30 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x156ce8 ldr r3, [pc, #0xc8] */
/* @0x156cec add r7, sp, #8 */
/* @0x156cf0 movw r2, #0x3f9 */
/* @0x156cf4 add r3, pc, r3 */
/* @0x156cf8 ldm r3, {r0, r1} */
/* @0x156cfc lsr r3, r1, #16 */
/* @0x156d00 strb r3, [sp, #0xa] */
/* @0x156d04 strh r1, [r7], #-4 */
/* @0x156d08 mov r1, #0 */
/* @0x156d0c str r0, [sp, #0x4] */
/* @0x156d10 add r0, sp, #11 */
/* @0x156d14 bl 0xb65b0 <memset@plt> */
/* @0x156d18 mov r0, r7 */
/* @0x156d1c bl 0xb6538 <strlen@plt> */
/* @0x156d20 mov r8, r0 */
/* @0x156d24 mov r0, r6 */
/* @0x156d28 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x156d2c cmp r0, #0 */
/* @0x156d30 beq 0x156d6c <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x156d34 add r0, r7, r8 */
/* @0x156d38 rsb r1, r8, #1024 */
/* @0x156d3c mov r2, r6 */
/* @0x156d40 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x156d44 add r3, sp, #1024 */
/* @0x156d48 add r3, r3, #8 */
/* @0x156d4c add r8, r3, r8 */
/* @0x156d50 ldrb r3, [r8, #-0x404] */
/* @0x156d54 cmp r3, #0 */
/* @0x156d58 beq 0x156c90 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x156d5c mov r0, r7 */
/* @0x156d60 bl 0x160eec <_Z7OpenURLPKc> */
/* @0x156d64 stm r5, {r0, r1} */
/* @0x156d68 b 0x156c30 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x156d6c mov r0, r6 */
/* @0x156d70 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x156d74 subs r1, r0, #0 */
/* @0x156d78 beq 0x156d90 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x156d7c add r0, r7, r8 */
/* @0x156d80 rsb r1, r8, #1024 */
/* @0x156d84 mov r2, r6 */
/* @0x156d88 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x156d8c b 0x156d44 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x156d90 ldr r0, [pc, #0x24] */
/* @0x156d94 add r0, pc, r0 */
/* @0x156d98 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x156d9c b 0x156c30 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x156da0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x156da4 eoreq r6, r9, r0, asr sp */
/* @0x156da8 andseq pc, lr, r0, lsr #19 */
/* @0x156dac andseq r11, lr, r0, asr sp */
/* @0x156db0 eoreq r5, r0, r12, lsl #28 */
/* @0x156db4 andseq pc, lr, r0, lsr #19 */
/* @0x156db8 eoreq r5, r0, r4, asr #27 */
/* @0x156dbc andseq pc, lr, r12, ror r8 */

/* ── FUNC 0x156dc0 · F_YoYo_OpenURL_full(RValue&, CInstance*, CInstance*, int, RValue*) · size=12 · insn=3 */
/* @0x156dc0 cmp r3, #1 */
/* @0x156dc4 movge r3, #1 */
/* @0x156dc8 b 0x156be8 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_> */

/* ── FUNC 0x156dcc · F_YoYo_OpenURL_ext(RValue&, CInstance*, CInstance*, int, RValue*) · size=12 · insn=3 */
/* @0x156dcc cmp r3, #1 */
/* @0x156dd0 movge r3, #1 */
/* @0x156dd4 b 0x156be8 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_> */

/* ── FUNC 0x156dd8 · F_YoYo_EnableAds(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x156dd8 push {r3, r4, r5, lr} */
/* @0x156ddc mov r1, #0 */
/* @0x156de0 ldr r4, [sp, #0x10] */
/* @0x156de4 mov r0, r4 */
/* @0x156de8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156dec mov r1, #1 */
/* @0x156df0 mov r5, r0 */
/* @0x156df4 mov r0, r4 */
/* @0x156df8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156dfc mov r2, #0 */
/* @0x156e00 mov r1, r0 */
/* @0x156e04 mov r0, r5 */
/* @0x156e08 pop {r3, r4, r5, lr} */
/* @0x156e0c b 0x15e390 <_Z15EnableAdServingiii> */

/* ── FUNC 0x156e10 · F_YoYo_EnableAdsEx(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x156e10 push {r4, r5, r6, lr} */
/* @0x156e14 mov r1, #0 */
/* @0x156e18 ldr r4, [sp, #0x10] */
/* @0x156e1c mov r0, r4 */
/* @0x156e20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156e24 mov r1, #1 */
/* @0x156e28 mov r6, r0 */
/* @0x156e2c mov r0, r4 */
/* @0x156e30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156e34 mov r1, #2 */
/* @0x156e38 mov r5, r0 */
/* @0x156e3c mov r0, r4 */
/* @0x156e40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x156e44 mov r1, r5 */
/* @0x156e48 mov r2, r0 */
/* @0x156e4c mov r0, r6 */
/* @0x156e50 pop {r4, r5, r6, lr} */
/* @0x156e54 b 0x15e390 <_Z15EnableAdServingiii> */

/* ── FUNC 0x156e58 · F_YoYoAdsSetup(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x156e58 push {r3, lr} */
/* @0x156e5c mov r1, #0 */
/* @0x156e60 ldr r0, [sp, #0x8] */
/* @0x156e64 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156e68 pop {r3, lr} */
/* @0x156e6c b 0x15e2f0 <_Z8AdsSetupPc> */

/* ── FUNC 0x156e70 · F_YoYo_AdsPreload(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x156e70 push {r3, lr} */
/* @0x156e74 mov r1, #0 */
/* @0x156e78 ldr r0, [sp, #0x8] */
/* @0x156e7c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156e80 pop {r3, lr} */
/* @0x156e84 b 0x15e478 <_Z10AdsPreloadPc> */

/* ── FUNC 0x156e88 · F_YoYo_AdsEvent(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x156e88 push {r3, lr} */
/* @0x156e8c mov r1, #0 */
/* @0x156e90 ldr r0, [sp, #0x8] */
/* @0x156e94 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156e98 pop {r3, lr} */
/* @0x156e9c b 0x15e428 <_Z8AdsEventPc> */

/* ── FUNC 0x156ea0 · F_YoYo_LeaveRating(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x156ea0 push {r4, r5, r6, r7, r8, lr} */
/* @0x156ea4 mov r1, #0 */
/* @0x156ea8 ldr r4, [sp, #0x18] */
/* @0x156eac mov r0, r4 */
/* @0x156eb0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156eb4 mov r1, #1 */
/* @0x156eb8 mov r7, r0 */
/* @0x156ebc mov r0, r4 */
/* @0x156ec0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156ec4 mov r1, #2 */
/* @0x156ec8 mov r6, r0 */
/* @0x156ecc mov r0, r4 */
/* @0x156ed0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156ed4 mov r1, #3 */
/* @0x156ed8 mov r5, r0 */
/* @0x156edc mov r0, r4 */
/* @0x156ee0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x156ee4 mov r1, r6 */
/* @0x156ee8 mov r2, r5 */
/* @0x156eec mov r3, r0 */
/* @0x156ef0 mov r0, r7 */
/* @0x156ef4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x156ef8 b 0x15e538 <_Z11LeaveRatingPcPKcS1_S1_> */

/* ── FUNC 0x156efc · F_YoYo_GetDevice(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x156efc push {r4, lr} */
/* @0x156f00 mov r3, #0 */
/* @0x156f04 str r3, [r0, #0xc] */
/* @0x156f08 mov r4, r0 */
/* @0x156f0c bl 0x15e64c <_Z10GetDeviceMv> */
/* @0x156f10 vmov s15, r0 */
/* @0x156f14 vcvt.f64.s32 d7, s15 */
/* @0x156f18 vmov r0, r1, d7 */
/* @0x156f1c vmov r2, s14 */
/* @0x156f20 mov r3, r1 */
/* @0x156f24 stm r4, {r2, r3} */
/* @0x156f28 pop {r4, pc} */

/* ── FUNC 0x156f2c · GET_YoYo_GetDevice(CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x156f2c push {r4, r5, r6, lr} */
/* @0x156f30 mov r3, #0 */
/* @0x156f34 str r3, [r2, #0xc] */
/* @0x156f38 mov r6, r2 */
/* @0x156f3c bl 0x15e64c <_Z10GetDeviceMv> */
/* @0x156f40 vmov s15, r0 */
/* @0x156f44 mov r0, #1 */
/* @0x156f48 vcvt.f64.s32 d7, s15 */
/* @0x156f4c vmov r4, r5, d7 */
/* @0x156f50 vmov r2, s14 */
/* @0x156f54 mov r3, r5 */
/* @0x156f58 stm r6, {r2, r3} */
/* @0x156f5c pop {r4, r5, r6, pc} */

/* ── FUNC 0x156f60 · F_YoYo_GetCPUDetails(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x156f60 push {r4, lr} */
/* @0x156f64 mov r3, #0 */
/* @0x156f68 str r3, [r0, #0xc] */
/* @0x156f6c mov r4, r0 */
/* @0x156f70 bl 0x15e66c <_Z14GetCPUDetailsMv> */
/* @0x156f74 vmov s15, r0 */
/* @0x156f78 vcvt.f64.s32 d7, s15 */
/* @0x156f7c vmov r0, r1, d7 */
/* @0x156f80 vmov r2, s14 */
/* @0x156f84 mov r3, r1 */
/* @0x156f88 stm r4, {r2, r3} */
/* @0x156f8c pop {r4, pc} */

/* ── FUNC 0x156f90 · F_YoYo_GetTimer(RValue&, CInstance*, CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x156f90 push {r4, lr} */
/* @0x156f94 mov r3, #0 */
/* @0x156f98 str r3, [r0, #0xc] */
/* @0x156f9c mov r4, r0 */
/* @0x156fa0 bl 0x215148 <Timing_Time> */
/* @0x156fa4 bl 0x319164 <__floatdidf> */
/* @0x156fa8 stm r4, {r0, r1} */
/* @0x156fac pop {r4, pc} */

/* ── FUNC 0x156fb0 · F_YoYo_OsGetInfo(RValue&, CInstance*, CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x156fb0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x156fb4 sub sp, sp, #2064 */
/* @0x156fb8 ldr r4, [pc, #0xc4] */
/* @0x156fbc sub sp, sp, #4 */
/* @0x156fc0 mov r5, r0 */
/* @0x156fc4 add r6, sp, #16 */
/* @0x156fc8 ldr r4, [pc, r4] */
/* @0x156fcc ldr r3, [r4] */
/* @0x156fd0 str r3, [sp, #0x80c] */
/* @0x156fd4 bl 0x161220 <_Z11Os_Get_Infov> */
/* @0x156fd8 mov r8, r0 */
/* @0x156fdc bl 0x2052d4 <_Z8GetDsMapi> */
/* @0x156fe0 mov r3, #0 */
/* @0x156fe4 str r3, [sp, #0x8] */
/* @0x156fe8 mov r9, r0 */
/* @0x156fec sub r0, r6, #8 */
/* @0x156ff0 bl 0x15f574 <_Z6YYUDIDPPc> */
/* @0x156ff4 ldr r7, [sp, #0x8] */
/* @0x156ff8 ldr r1, [pc, #0x88] */
/* @0x156ffc mov r0, r7 */
/* @0x157000 add r1, pc, r1 */
/* @0x157004 bl 0xb6574 <strcmp@plt> */
/* @0x157008 cmp r0, #0 */
/* @0x15700c beq 0x157048 <_Z16F_YoYo_OsGetInfoR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x157010 sub r6, r6, #4 */
/* @0x157014 ldr r1, [pc, #0x70] */
/* @0x157018 mov r3, r7 */
/* @0x15701c movw r2, #0x7ff */
/* @0x157020 add r1, pc, r1 */
/* @0x157024 mov r0, r6 */
/* @0x157028 bl 0xb6550 <sprintf@plt> */
/* @0x15702c ldr r1, [pc, #0x5c] */
/* @0x157030 str r6, [sp] */
/* @0x157034 mov r0, r9 */
/* @0x157038 add r1, pc, r1 */
/* @0x15703c mov r2, #0 */
/* @0x157040 mov r3, #0 */
/* @0x157044 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x157048 vmov s15, r8 */
/* @0x15704c ldr r1, [sp, #0x80c] */
/* @0x157050 mov r0, #0 */
/* @0x157054 str r0, [r5, #0xc] */
/* @0x157058 vcvt.f64.s32 d7, s15 */
/* @0x15705c vmov r2, r3, d7 */
/* @0x157060 vstr s14, [r5] */
/* @0x157064 ldr r2, [r4] */
/* @0x157068 cmp r1, r2 */
/* @0x15706c str r3, [r5, #0x4] */
/* @0x157070 bne 0x157080 <_Z16F_YoYo_OsGetInfoR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x157074 add sp, sp, #2064 */
/* @0x157078 add sp, sp, #4 */
/* @0x15707c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x157080 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x157084 eoreq r6, r9, r8, lsl #19 */
/* @0x157088 mulseq lr, r12, r6 */
/* @0x15708c mulseq lr, r0, r6 */
/* @0x157090 andseq pc, lr, r0, lsl #13 */
