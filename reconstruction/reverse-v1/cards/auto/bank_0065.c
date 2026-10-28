/* libyoyo.so 覆盖卡组 0065
 * 函数 0x1337dc..0x134390，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1337dc · F_CDTrackLength(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1337dc push {r4, lr} */
/* @0x1337e0 mov r3, #0 */
/* @0x1337e4 mov r1, r3 */
/* @0x1337e8 str r3, [r0, #0xc] */
/* @0x1337ec mov r4, r0 */
/* @0x1337f0 ldr r0, [sp, #0x8] */
/* @0x1337f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1337f8 bl 0x21488c <_Z14CD_TrackLengthi> */
/* @0x1337fc vmov s15, r0 */
/* @0x133800 vcvt.f64.s32 d7, s15 */
/* @0x133804 vmov r0, r1, d7 */
/* @0x133808 vmov r2, s14 */
/* @0x13380c mov r3, r1 */
/* @0x133810 stm r4, {r2, r3} */
/* @0x133814 pop {r4, pc} */

/* ── FUNC 0x133818 · F_CDPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x133818 push {r4, lr} */
/* @0x13381c mov r3, #0 */
/* @0x133820 str r3, [r0, #0xc] */
/* @0x133824 mov r4, r0 */
/* @0x133828 bl 0x214894 <_Z11CD_Positionv> */
/* @0x13382c vmov s15, r0 */
/* @0x133830 vcvt.f64.s32 d7, s15 */
/* @0x133834 vmov r0, r1, d7 */
/* @0x133838 vmov r2, s14 */
/* @0x13383c mov r3, r1 */
/* @0x133840 stm r4, {r2, r3} */
/* @0x133844 pop {r4, pc} */

/* ── FUNC 0x133848 · F_CDTrackPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x133848 push {r4, lr} */
/* @0x13384c mov r3, #0 */
/* @0x133850 str r3, [r0, #0xc] */
/* @0x133854 mov r4, r0 */
/* @0x133858 bl 0x21489c <_Z16CD_TrackPositionv> */
/* @0x13385c vmov s15, r0 */
/* @0x133860 vcvt.f64.s32 d7, s15 */
/* @0x133864 vmov r0, r1, d7 */
/* @0x133868 vmov r2, s14 */
/* @0x13386c mov r3, r1 */
/* @0x133870 stm r4, {r2, r3} */
/* @0x133874 pop {r4, pc} */

/* ── FUNC 0x133878 · F_CDPlay(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x133878 push {r3, r4, r5, lr} */
/* @0x13387c mov r1, #0 */
/* @0x133880 ldr r4, [sp, #0x10] */
/* @0x133884 mov r0, r4 */
/* @0x133888 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13388c mov r1, #1 */
/* @0x133890 mov r5, r0 */
/* @0x133894 mov r0, r4 */
/* @0x133898 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13389c mov r1, r0 */
/* @0x1338a0 mov r0, r5 */
/* @0x1338a4 pop {r3, r4, r5, lr} */
/* @0x1338a8 b 0x2148a4 <_Z7CD_Playii> */

/* ── FUNC 0x1338ac · F_CDStop(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1338ac b 0x2148a8 <_Z7CD_Stopv> */

/* ── FUNC 0x1338b0 · F_CDPause(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1338b0 b 0x2148ac <_Z8CD_Pausev> */

/* ── FUNC 0x1338b4 · F_CDResume(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1338b4 b 0x2148b0 <_Z9CD_Resumev> */

/* ── FUNC 0x1338b8 · F_CDSetPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x1338b8 push {r3, lr} */
/* @0x1338bc mov r1, #0 */
/* @0x1338c0 ldr r0, [sp, #0x8] */
/* @0x1338c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1338c8 pop {r3, lr} */
/* @0x1338cc b 0x2148b4 <_Z14CD_SetPositioni> */

/* ── FUNC 0x1338d0 · F_CDSetTrackPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x1338d0 push {r3, lr} */
/* @0x1338d4 mov r1, #0 */
/* @0x1338d8 ldr r0, [sp, #0x8] */
/* @0x1338dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1338e0 pop {r3, lr} */
/* @0x1338e4 b 0x2148b8 <_Z19CD_SetTrackPositioni> */

/* ── FUNC 0x1338e8 · F_CDOpenDoor(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1338e8 b 0x2148bc <_Z11CD_OpenDoorv> */

/* ── FUNC 0x1338ec · F_CDCloseDoor(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1338ec b 0x2148c0 <_Z12CD_CloseDoorv> */

/* ── FUNC 0x1338f0 · F_MCICommand(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x1338f0 push {r4, r5, r6, lr} */
/* @0x1338f4 sub sp, sp, #264 */
/* @0x1338f8 ldr r4, [pc, #0x50] */
/* @0x1338fc add r6, sp, #4 */
/* @0x133900 mov r5, r0 */
/* @0x133904 mov r2, #256 */
/* @0x133908 ldr r4, [pc, r4] */
/* @0x13390c mov r1, #0 */
/* @0x133910 mov r0, r6 */
/* @0x133914 ldr r3, [r4] */
/* @0x133918 str r3, [sp, #0x104] */
/* @0x13391c bl 0xb65b0 <memset@plt> */
/* @0x133920 mov r3, #1 */
/* @0x133924 mov r1, r6 */
/* @0x133928 str r3, [r5, #0xc] */
/* @0x13392c mov r0, r5 */
/* @0x133930 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x133934 ldr r2, [sp, #0x104] */
/* @0x133938 ldr r3, [r4] */
/* @0x13393c cmp r2, r3 */
/* @0x133940 bne 0x13394c <_Z12F_MCICommandR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x133944 add sp, sp, #264 */
/* @0x133948 pop {r4, r5, r6, pc} */
/* @0x13394c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x133950 eoreq r10, r11, r8, asr #32 */

/* ── FUNC 0x133954 · F_AudioPlayMusic(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x133954 push {r3, lr} */
/* @0x133958 ldr r3, [pc, #0x30] */
/* @0x13395c ldr r3, [pc, r3] */
/* @0x133960 ldrb r3, [r3] */
/* @0x133964 cmp r3, #0 */
/* @0x133968 popne {r3, pc} */
/* @0x13396c ldr r3, [pc, #0x20] */
/* @0x133970 ldr r1, [pc, #0x20] */
/* @0x133974 ldr r3, [pc, r3] */
/* @0x133978 add r1, pc, r1 */
/* @0x13397c ldr r0, [r3] */
/* @0x133980 ldr r3, [r0] */
/* @0x133984 ldr r3, [r3, #0xc] */
/* @0x133988 blx r3 */
/* @0x13398c pop {r3, pc} */
/* @0x133990 .word 0x002bb6f0 */
/* @0x133994 eoreq r9, r11, r0, lsr #27 */
/* @0x133998 eoreq r11, r0, r8, lsl #20 */

/* ── FUNC 0x13399c · F_AudioStopMusic(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x13399c push {r3, lr} */
/* @0x1339a0 ldr r3, [pc, #0x30] */
/* @0x1339a4 ldr r3, [pc, r3] */
/* @0x1339a8 ldrb r3, [r3] */
/* @0x1339ac cmp r3, #0 */
/* @0x1339b0 popne {r3, pc} */
/* @0x1339b4 ldr r3, [pc, #0x20] */
/* @0x1339b8 ldr r1, [pc, #0x20] */
/* @0x1339bc ldr r3, [pc, r3] */
/* @0x1339c0 add r1, pc, r1 */
/* @0x1339c4 ldr r0, [r3] */
/* @0x1339c8 ldr r3, [r0] */
/* @0x1339cc ldr r3, [r3, #0xc] */
/* @0x1339d0 blx r3 */
/* @0x1339d4 pop {r3, pc} */
/* @0x1339d8 eoreq r11, r11, r8, lsr #13 */
/* @0x1339dc eoreq r9, r11, r8, asr sp */
/* @0x1339e0 eoreq r11, r0, r12, ror #19 */

/* ── FUNC 0x1339e4 · F_AudioPauseMusic(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x1339e4 push {r3, lr} */
/* @0x1339e8 ldr r3, [pc, #0x30] */
/* @0x1339ec ldr r3, [pc, r3] */
/* @0x1339f0 ldrb r3, [r3] */
/* @0x1339f4 cmp r3, #0 */
/* @0x1339f8 popne {r3, pc} */
/* @0x1339fc ldr r3, [pc, #0x20] */
/* @0x133a00 ldr r1, [pc, #0x20] */
/* @0x133a04 ldr r3, [pc, r3] */
/* @0x133a08 add r1, pc, r1 */
/* @0x133a0c ldr r0, [r3] */
/* @0x133a10 ldr r3, [r0] */
/* @0x133a14 ldr r3, [r3, #0xc] */
/* @0x133a18 blx r3 */
/* @0x133a1c pop {r3, pc} */
/* @0x133a20 eoreq r11, r11, r0, ror #12 */
/* @0x133a24 eoreq r9, r11, r0, lsl sp */
/* @0x133a28 .word 0x0020b9d0 */

/* ── FUNC 0x133a2c · F_AudioResumeMusic(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x133a2c push {r3, lr} */
/* @0x133a30 ldr r3, [pc, #0x30] */
/* @0x133a34 ldr r3, [pc, r3] */
/* @0x133a38 ldrb r3, [r3] */
/* @0x133a3c cmp r3, #0 */
/* @0x133a40 popne {r3, pc} */
/* @0x133a44 ldr r3, [pc, #0x20] */
/* @0x133a48 ldr r1, [pc, #0x20] */
/* @0x133a4c ldr r3, [pc, r3] */
/* @0x133a50 add r1, pc, r1 */
/* @0x133a54 ldr r0, [r3] */
/* @0x133a58 ldr r3, [r0] */
/* @0x133a5c ldr r3, [r3, #0xc] */
/* @0x133a60 blx r3 */
/* @0x133a64 pop {r3, pc} */
/* @0x133a68 eoreq r11, r11, r8, lsl r6 */
/* @0x133a6c eoreq r9, r11, r8, asr #25 */
/* @0x133a70 .word 0x0020b9b4 */

/* ── FUNC 0x133a74 · F_AudioMusicIsPlaying(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x133a74 push {r3, r4, r5, lr} */
/* @0x133a78 mov r5, r0 */
/* @0x133a7c ldr r3, [pc, #0x3c] */
/* @0x133a80 ldr r3, [pc, r3] */
/* @0x133a84 ldrb r4, [r3] */
/* @0x133a88 cmp r4, #0 */
/* @0x133a8c popne {r3, r4, r5, pc} */
/* @0x133a90 ldr r3, [pc, #0x2c] */
/* @0x133a94 ldr r1, [pc, #0x2c] */
/* @0x133a98 ldr r3, [pc, r3] */
/* @0x133a9c add r1, pc, r1 */
/* @0x133aa0 ldr r0, [r3] */
/* @0x133aa4 ldr r3, [r0] */
/* @0x133aa8 ldr r3, [r3, #0xc] */
/* @0x133aac blx r3 */
/* @0x133ab0 str r4, [r5, #0xc] */
/* @0x133ab4 str r4, [r5] */
/* @0x133ab8 str r4, [r5, #0x4] */
/* @0x133abc pop {r3, r4, r5, pc} */
/* @0x133ac0 eoreq r11, r11, r12, asr #11 */
/* @0x133ac4 eoreq r9, r11, r12, ror r12 */
/* @0x133ac8 mlaeq r0, r4, r9, r11 */

/* ── FUNC 0x133acc · F_AudioMusicGain(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x133acc push {r3, lr} */
/* @0x133ad0 ldr r3, [pc, #0x30] */
/* @0x133ad4 ldr r3, [pc, r3] */
/* @0x133ad8 ldrb r3, [r3] */
/* @0x133adc cmp r3, #0 */
/* @0x133ae0 popne {r3, pc} */
/* @0x133ae4 ldr r3, [pc, #0x20] */
/* @0x133ae8 ldr r1, [pc, #0x20] */
/* @0x133aec ldr r3, [pc, r3] */
/* @0x133af0 add r1, pc, r1 */
/* @0x133af4 ldr r0, [r3] */
/* @0x133af8 ldr r3, [r0] */
/* @0x133afc ldr r3, [r3, #0xc] */
/* @0x133b00 blx r3 */
/* @0x133b04 pop {r3, pc} */
/* @0x133b08 eoreq r11, r11, r8, ror r5 */
/* @0x133b0c eoreq r9, r11, r8, lsr #24 */
/* @0x133b10 eoreq r11, r0, r0, ror r9 */

/* ── FUNC 0x133b14 · F_SoundStopAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x133b14 ldr r3, [pc, #0x24] */
/* @0x133b18 ldr r3, [pc, r3] */
/* @0x133b1c ldrb r3, [r3] */
/* @0x133b20 cmp r3, #0 */
/* @0x133b24 bxne lr */
/* @0x133b28 ldr r3, [pc, #0x14] */
/* @0x133b2c ldr r3, [pc, r3] */
/* @0x133b30 ldrb r3, [r3] */
/* @0x133b34 cmp r3, #0 */
/* @0x133b38 bxne lr */
/* @0x133b3c b 0x21ee90 <_Z11SND_StopAllv> */
/* @0x133b40 eoreq r11, r11, r8, lsl r2 */
/* @0x133b44 eoreq r11, r11, r0, lsr #10 */

/* ── FUNC 0x133b48 · F_SoundVolume(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x133b48 ldr r3, [pc, #0x94] */
/* @0x133b4c push {r4, r5, r6, lr} */
/* @0x133b50 ldr r3, [pc, r3] */
/* @0x133b54 ldr r4, [sp, #0x10] */
/* @0x133b58 ldrb r3, [r3] */
/* @0x133b5c cmp r3, #0 */
/* @0x133b60 popne {r4, r5, r6, pc} */
/* @0x133b64 ldr r3, [pc, #0x7c] */
/* @0x133b68 ldr r3, [pc, r3] */
/* @0x133b6c ldrb r1, [r3] */
/* @0x133b70 cmp r1, #0 */
/* @0x133b74 popne {r4, r5, r6, pc} */
/* @0x133b78 mov r0, r4 */
/* @0x133b7c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x133b80 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x133b84 subs r5, r0, #0 */
/* @0x133b88 beq 0x133bd0 <_Z13F_SoundVolumeR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x133b8c mov r0, r4 */
/* @0x133b90 mov r1, #1 */
/* @0x133b94 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x133b98 strd r0, r1, [r5, #32] */
/* @0x133b9c mov r0, r5 */
/* @0x133ba0 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x133ba4 mov r1, #1 */
/* @0x133ba8 mov r5, r0 */
/* @0x133bac mov r0, r4 */
/* @0x133bb0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x133bb4 mov r2, r0 */
/* @0x133bb8 mov r3, r1 */
/* @0x133bbc mov r0, r5 */
/* @0x133bc0 mov r1, #1 */
/* @0x133bc4 str r1, [sp, #0x10] */
/* @0x133bc8 pop {r4, r5, r6, lr} */
/* @0x133bcc b 0x21f07c <_Z14SND_Set_Volumeidi> */
/* @0x133bd0 ldr r0, [pc, #0x14] */
/* @0x133bd4 mov r1, r5 */
/* @0x133bd8 pop {r4, r5, r6, lr} */
/* @0x133bdc add r0, pc, r0 */
/* @0x133be0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x133be4 eoreq r11, r11, r0, ror #3 */
/* @0x133be8 eoreq r11, r11, r4, ror #9 */
/* @0x133bec .word 0x0020b8b0 */

/* ── FUNC 0x133bf0 · F_SoundFade(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x133bf0 ldr r3, [pc, #0x8c] */
/* @0x133bf4 push {r4, r5, r6, r7, r8, lr} */
/* @0x133bf8 ldr r3, [pc, r3] */
/* @0x133bfc ldr r6, [sp, #0x18] */
/* @0x133c00 ldrb r3, [r3] */
/* @0x133c04 cmp r3, #0 */
/* @0x133c08 popne {r4, r5, r6, r7, r8, pc} */
/* @0x133c0c ldr r3, [pc, #0x74] */
/* @0x133c10 ldr r3, [pc, r3] */
/* @0x133c14 ldrb r1, [r3] */
/* @0x133c18 cmp r1, #0 */
/* @0x133c1c popne {r4, r5, r6, r7, r8, pc} */
/* @0x133c20 mov r0, r6 */
/* @0x133c24 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x133c28 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x133c2c subs r1, r0, #0 */
/* @0x133c30 beq 0x133c74 <_Z11F_SoundFadeR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x133c34 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x133c38 mov r1, #1 */
/* @0x133c3c mov r7, r0 */
/* @0x133c40 mov r0, r6 */
/* @0x133c44 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x133c48 mov r4, r0 */
/* @0x133c4c mov r5, r1 */
/* @0x133c50 mov r0, r6 */
/* @0x133c54 mov r1, #2 */
/* @0x133c58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x133c5c mov r2, r4 */
/* @0x133c60 mov r3, r5 */
/* @0x133c64 str r0, [sp, #0x18] */
/* @0x133c68 mov r0, r7 */
/* @0x133c6c pop {r4, r5, r6, r7, r8, lr} */
/* @0x133c70 b 0x21f07c <_Z14SND_Set_Volumeidi> */
/* @0x133c74 ldr r0, [pc, #0x10] */
/* @0x133c78 pop {r4, r5, r6, r7, r8, lr} */
/* @0x133c7c add r0, pc, r0 */
/* @0x133c80 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x133c84 eoreq r11, r11, r8, lsr r1 */
/* @0x133c88 eoreq r11, r11, r12, lsr r4 */
/* @0x133c8c eoreq r11, r0, r0, lsl r8 */

/* ── FUNC 0x133c90 · F_SoundPan(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x133c90 ldr r3, [pc, #0x74] */
/* @0x133c94 push {r4, r5, r6, lr} */
/* @0x133c98 ldr r3, [pc, r3] */
/* @0x133c9c ldr r4, [sp, #0x10] */
/* @0x133ca0 ldrb r3, [r3] */
/* @0x133ca4 cmp r3, #0 */
/* @0x133ca8 popne {r4, r5, r6, pc} */
/* @0x133cac ldr r3, [pc, #0x5c] */
/* @0x133cb0 ldr r3, [pc, r3] */
/* @0x133cb4 ldrb r1, [r3] */
/* @0x133cb8 cmp r1, #0 */
/* @0x133cbc popne {r4, r5, r6, pc} */
/* @0x133cc0 mov r0, r4 */
/* @0x133cc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x133cc8 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x133ccc subs r1, r0, #0 */
/* @0x133cd0 beq 0x133cfc <_Z10F_SoundPanR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x133cd4 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x133cd8 mov r1, #1 */
/* @0x133cdc mov r5, r0 */
/* @0x133ce0 mov r0, r4 */
/* @0x133ce4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x133ce8 mov r2, r0 */
/* @0x133cec mov r3, r1 */
/* @0x133cf0 mov r0, r5 */
/* @0x133cf4 pop {r4, r5, r6, lr} */
/* @0x133cf8 b 0x21f11c <_Z15SND_Set_Panningid> */
/* @0x133cfc ldr r0, [pc, #0x10] */
/* @0x133d00 pop {r4, r5, r6, lr} */
/* @0x133d04 add r0, pc, r0 */
/* @0x133d08 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x133d0c mlaeq r11, r8, r0, r11 */
/* @0x133d10 mlaeq r11, r12, r3, r11 */
/* @0x133d14 eoreq r11, r0, r8, lsl #15 */

/* ── FUNC 0x133d18 · F_SoundBackgroundTempo(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x133d18 push {r3, lr} */
/* @0x133d1c ldr r3, [pc, #0x30] */
/* @0x133d20 ldr r0, [sp, #0x8] */
/* @0x133d24 ldr r3, [pc, r3] */
/* @0x133d28 ldrb r3, [r3] */
/* @0x133d2c cmp r3, #0 */
/* @0x133d30 popne {r3, pc} */
/* @0x133d34 ldr r3, [pc, #0x1c] */
/* @0x133d38 ldr r3, [pc, r3] */
/* @0x133d3c ldrb r1, [r3] */
/* @0x133d40 cmp r1, #0 */
/* @0x133d44 popne {r3, pc} */
/* @0x133d48 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x133d4c pop {r3, lr} */
/* @0x133d50 b 0x21eb78 <_Z20SND_Set_Global_Tempod> */
/* @0x133d54 eoreq r11, r11, r12 */
/* @0x133d58 eoreq r11, r11, r4, lsl r3 */

/* ── FUNC 0x133d5c · F_SoundGlobalVolume(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x133d5c push {r3, lr} */
/* @0x133d60 ldr r3, [pc, #0x30] */
/* @0x133d64 ldr r0, [sp, #0x8] */
/* @0x133d68 ldr r3, [pc, r3] */
/* @0x133d6c ldrb r3, [r3] */
/* @0x133d70 cmp r3, #0 */
/* @0x133d74 popne {r3, pc} */
/* @0x133d78 ldr r3, [pc, #0x1c] */
/* @0x133d7c ldr r3, [pc, r3] */
/* @0x133d80 ldrb r1, [r3] */
/* @0x133d84 cmp r1, #0 */
/* @0x133d88 popne {r3, pc} */
/* @0x133d8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x133d90 pop {r3, lr} */
/* @0x133d94 b 0x21eb60 <_Z21SND_Set_Global_Volumef> */
/* @0x133d98 eoreq r10, r11, r8, asr #31 */
/* @0x133d9c .word 0x002bb2d0 */

/* ── FUNC 0x133da0 · F_SoundSetSearchDirectory(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x133da0 push {r3, lr} */
/* @0x133da4 ldr r3, [pc, #0x30] */
/* @0x133da8 ldr r0, [sp, #0x8] */
/* @0x133dac ldr r3, [pc, r3] */
/* @0x133db0 ldrb r3, [r3] */
/* @0x133db4 cmp r3, #0 */
/* @0x133db8 popne {r3, pc} */
/* @0x133dbc ldr r3, [pc, #0x1c] */
/* @0x133dc0 ldr r3, [pc, r3] */
/* @0x133dc4 ldrb r1, [r3] */
/* @0x133dc8 cmp r1, #0 */
/* @0x133dcc popne {r3, pc} */
/* @0x133dd0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x133dd4 pop {r3, lr} */
/* @0x133dd8 b 0x21e9ec <_Z24SND_Set_Search_DirectoryPKc> */
/* @0x133ddc eoreq r10, r11, r4, lsl #31 */
/* @0x133de0 eoreq r11, r11, r12, lsl #5 */

/* ── FUNC 0x133de4 · F_SoundEffectSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x133de4 push {r3, r4, r5, lr} */
/* @0x133de8 ldr r3, [pc, #0x6c] */
/* @0x133dec ldr r4, [sp, #0x10] */
/* @0x133df0 ldr r3, [pc, r3] */
/* @0x133df4 ldrb r3, [r3] */
/* @0x133df8 cmp r3, #0 */
/* @0x133dfc popne {r3, r4, r5, pc} */
/* @0x133e00 ldr r3, [pc, #0x58] */
/* @0x133e04 ldr r3, [pc, r3] */
/* @0x133e08 ldrb r1, [r3] */
/* @0x133e0c cmp r1, #0 */
/* @0x133e10 popne {r3, r4, r5, pc} */
/* @0x133e14 mov r0, r4 */
/* @0x133e18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x133e1c bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x133e20 subs r1, r0, #0 */
/* @0x133e24 beq 0x133e4c <_Z16F_SoundEffectSetR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x133e28 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x133e2c mov r1, #1 */
/* @0x133e30 mov r5, r0 */
/* @0x133e34 mov r0, r4 */
/* @0x133e38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x133e3c mov r1, r0 */
/* @0x133e40 mov r0, r5 */
/* @0x133e44 pop {r3, r4, r5, lr} */
/* @0x133e48 b 0x21f120 <_Z14SND_Set_Effectii> */
/* @0x133e4c ldr r0, [pc, #0x10] */
/* @0x133e50 pop {r3, r4, r5, lr} */
/* @0x133e54 add r0, pc, r0 */
/* @0x133e58 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x133e5c eoreq r10, r11, r0, asr #30 */
/* @0x133e60 eoreq r11, r11, r8, asr #4 */
/* @0x133e64 eoreq r11, r0, r8, lsr r6 */

/* ── FUNC 0x133e68 · F_SoundEffectChorus(RValue&, CInstance*, CInstance*, int, RValue*) · size=312 · insn=78 */
/* @0x133e68 ldr r3, [pc, #0x124] */
/* @0x133e6c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x133e70 ldr r3, [pc, r3] */
/* @0x133e74 sub sp, sp, #76 */
/* @0x133e78 ldrb r3, [r3] */
/* @0x133e7c ldr r10, [sp, #0x70] */
/* @0x133e80 cmp r3, #0 */
/* @0x133e84 bne 0x133e9c <_Z19F_SoundEffectChorusR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x133e88 ldr r3, [pc, #0x108] */
/* @0x133e8c ldr r3, [pc, r3] */
/* @0x133e90 ldrb r1, [r3] */
/* @0x133e94 cmp r1, #0 */
/* @0x133e98 beq 0x133ea4 <_Z19F_SoundEffectChorusR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x133e9c add sp, sp, #76 */
/* @0x133ea0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x133ea4 mov r0, r10 */
/* @0x133ea8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x133eac bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x133eb0 subs r1, r0, #0 */
/* @0x133eb4 beq 0x133f80 <_Z19F_SoundEffectChorusR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x133eb8 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x133ebc mov r1, #1 */
/* @0x133ec0 mov r11, r0 */
/* @0x133ec4 mov r0, r10 */
/* @0x133ec8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x133ecc mov r2, r0 */
/* @0x133ed0 mov r3, r1 */
/* @0x133ed4 mov r0, r10 */
/* @0x133ed8 mov r1, #2 */
/* @0x133edc str r2, [sp, #0x38] */
/* @0x133ee0 str r3, [sp, #0x34] */
/* @0x133ee4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x133ee8 mov r8, r0 */
/* @0x133eec mov r9, r1 */
/* @0x133ef0 mov r0, r10 */
/* @0x133ef4 mov r1, #3 */
/* @0x133ef8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x133efc mov r6, r0 */
/* @0x133f00 mov r7, r1 */
/* @0x133f04 mov r0, r10 */
/* @0x133f08 mov r1, #4 */
/* @0x133f0c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x133f10 mov r4, r0 */
/* @0x133f14 mov r5, r1 */
/* @0x133f18 mov r0, r10 */
/* @0x133f1c mov r1, #5 */
/* @0x133f20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x133f24 mov r1, #6 */
/* @0x133f28 mov r12, r0 */
/* @0x133f2c mov r0, r10 */
/* @0x133f30 str r12, [sp, #0x3c] */
/* @0x133f34 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x133f38 strd r0, r1, [sp, #64] */
/* @0x133f3c mov r1, #7 */
/* @0x133f40 mov r0, r10 */
/* @0x133f44 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x133f48 ldr r12, [sp, #0x3c] */
/* @0x133f4c vldr d7, [sp, #64] */
/* @0x133f50 strd r8, r9, [sp] */
/* @0x133f54 strd r6, r7, [sp, #8] */
/* @0x133f58 vstr d7, [sp, #32] */
/* @0x133f5c strd r4, r5, [sp, #16] */
/* @0x133f60 str r12, [sp, #0x18] */
/* @0x133f64 ldr r2, [sp, #0x38] */
/* @0x133f68 ldr r3, [sp, #0x34] */
/* @0x133f6c str r0, [sp, #0x28] */
/* @0x133f70 mov r0, r11 */
/* @0x133f74 bl 0x21f124 <_Z21SND_Set_Effect_Chorusiddddidi> */
/* @0x133f78 add sp, sp, #76 */
/* @0x133f7c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x133f80 ldr r0, [pc, #0x14] */
/* @0x133f84 add r0, pc, r0 */
/* @0x133f88 add sp, sp, #76 */
/* @0x133f8c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x133f90 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x133f94 eoreq r10, r11, r0, asr #29 */
/* @0x133f98 eoreq r11, r11, r0, asr #3 */
/* @0x133f9c eoreq r11, r0, r8, lsl #10 */

/* ── FUNC 0x133fa0 · F_SoundEffectCompressor(RValue&, CInstance*, CInstance*, int, RValue*) · size=284 · insn=71 */
/* @0x133fa0 ldr r3, [pc, #0x108] */
/* @0x133fa4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x133fa8 ldr r3, [pc, r3] */
/* @0x133fac sub sp, sp, #60 */
/* @0x133fb0 ldrb r3, [r3] */
/* @0x133fb4 ldr r10, [sp, #0x60] */
/* @0x133fb8 cmp r3, #0 */
/* @0x133fbc bne 0x133fd4 <_Z23F_SoundEffectCompressorR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x133fc0 ldr r3, [pc, #0xec] */
/* @0x133fc4 ldr r3, [pc, r3] */
/* @0x133fc8 ldrb r1, [r3] */
/* @0x133fcc cmp r1, #0 */
/* @0x133fd0 beq 0x133fdc <_Z23F_SoundEffectCompressorR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x133fd4 add sp, sp, #60 */
/* @0x133fd8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x133fdc mov r0, r10 */
/* @0x133fe0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x133fe4 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x133fe8 subs r1, r0, #0 */
/* @0x133fec beq 0x13409c <_Z23F_SoundEffectCompressorR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x133ff0 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x133ff4 mov r1, #1 */
/* @0x133ff8 mov r11, r0 */
/* @0x133ffc mov r0, r10 */
/* @0x134000 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134004 mov r2, r0 */
/* @0x134008 mov r3, r1 */
/* @0x13400c mov r0, r10 */
/* @0x134010 mov r1, #2 */
/* @0x134014 str r2, [sp, #0x2c] */
/* @0x134018 str r3, [sp, #0x28] */
/* @0x13401c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134020 mov r8, r0 */
/* @0x134024 mov r9, r1 */
/* @0x134028 mov r0, r10 */
/* @0x13402c mov r1, #3 */
/* @0x134030 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134034 mov r6, r0 */
/* @0x134038 mov r7, r1 */
/* @0x13403c mov r0, r10 */
/* @0x134040 mov r1, #4 */
/* @0x134044 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134048 mov r4, r0 */
/* @0x13404c mov r5, r1 */
/* @0x134050 mov r0, r10 */
/* @0x134054 mov r1, #5 */
/* @0x134058 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13405c strd r0, r1, [sp, #48] */
/* @0x134060 mov r0, r10 */
/* @0x134064 mov r1, #6 */
/* @0x134068 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13406c vldr d7, [sp, #48] */
/* @0x134070 strd r8, r9, [sp] */
/* @0x134074 vstr d7, [sp, #24] */
/* @0x134078 strd r6, r7, [sp, #8] */
/* @0x13407c strd r4, r5, [sp, #16] */
/* @0x134080 ldr r2, [sp, #0x2c] */
/* @0x134084 ldr r3, [sp, #0x28] */
/* @0x134088 strd r0, r1, [sp, #32] */
/* @0x13408c mov r0, r11 */
/* @0x134090 bl 0x21f12c <_Z25SND_Set_Effect_Compressoridddddd> */
/* @0x134094 add sp, sp, #60 */
/* @0x134098 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13409c ldr r0, [pc, #0x14] */
/* @0x1340a0 add r0, pc, r0 */
/* @0x1340a4 add sp, sp, #60 */
/* @0x1340a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1340ac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1340b0 eoreq r10, r11, r8, lsl #27 */
/* @0x1340b4 eoreq r11, r11, r8, lsl #1 */
/* @0x1340b8 eoreq r11, r0, r12, ror #7 */

/* ── FUNC 0x1340bc · F_SoundEffectEcho(RValue&, CInstance*, CInstance*, int, RValue*) · size=260 · insn=65 */
/* @0x1340bc ldr r3, [pc, #0xf0] */
/* @0x1340c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1340c4 ldr r3, [pc, r3] */
/* @0x1340c8 sub sp, sp, #44 */
/* @0x1340cc ldrb r3, [r3] */
/* @0x1340d0 ldr r10, [sp, #0x50] */
/* @0x1340d4 cmp r3, #0 */
/* @0x1340d8 bne 0x1340f0 <_Z17F_SoundEffectEchoR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1340dc ldr r3, [pc, #0xd4] */
/* @0x1340e0 ldr r3, [pc, r3] */
/* @0x1340e4 ldrb r1, [r3] */
/* @0x1340e8 cmp r1, #0 */
/* @0x1340ec beq 0x1340f8 <_Z17F_SoundEffectEchoR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1340f0 add sp, sp, #44 */
/* @0x1340f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1340f8 mov r0, r10 */
/* @0x1340fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134100 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x134104 subs r1, r0, #0 */
/* @0x134108 beq 0x1341a0 <_Z17F_SoundEffectEchoR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x13410c bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x134110 mov r1, #1 */
/* @0x134114 mov r11, r0 */
/* @0x134118 mov r0, r10 */
/* @0x13411c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134120 mov r2, r0 */
/* @0x134124 mov r3, r1 */
/* @0x134128 mov r0, r10 */
/* @0x13412c mov r1, #2 */
/* @0x134130 str r2, [sp, #0x24] */
/* @0x134134 str r3, [sp, #0x20] */
/* @0x134138 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13413c mov r8, r0 */
/* @0x134140 mov r9, r1 */
/* @0x134144 mov r0, r10 */
/* @0x134148 mov r1, #3 */
/* @0x13414c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134150 mov r6, r0 */
/* @0x134154 mov r7, r1 */
/* @0x134158 mov r0, r10 */
/* @0x13415c mov r1, #4 */
/* @0x134160 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134164 mov r4, r0 */
/* @0x134168 mov r5, r1 */
/* @0x13416c mov r0, r10 */
/* @0x134170 mov r1, #5 */
/* @0x134174 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134178 strd r8, r9, [sp] */
/* @0x13417c strd r6, r7, [sp, #8] */
/* @0x134180 strd r4, r5, [sp, #16] */
/* @0x134184 ldr r2, [sp, #0x24] */
/* @0x134188 ldr r3, [sp, #0x20] */
/* @0x13418c str r0, [sp, #0x18] */
/* @0x134190 mov r0, r11 */
/* @0x134194 bl 0x21f134 <_Z19SND_Set_Effect_Echoiddddi> */
/* @0x134198 add sp, sp, #44 */
/* @0x13419c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1341a0 ldr r0, [pc, #0x14] */
/* @0x1341a4 add r0, pc, r0 */
/* @0x1341a8 add sp, sp, #44 */
/* @0x1341ac pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1341b0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1341b4 eoreq r10, r11, r12, ror #24 */
/* @0x1341b8 eoreq r10, r11, r12, ror #30 */
/* @0x1341bc eoreq r11, r0, r8, ror #5 */

/* ── FUNC 0x1341c0 · F_SoundEffectFlanger(RValue&, CInstance*, CInstance*, int, RValue*) · size=312 · insn=78 */
/* @0x1341c0 ldr r3, [pc, #0x124] */
/* @0x1341c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1341c8 ldr r3, [pc, r3] */
/* @0x1341cc sub sp, sp, #76 */
/* @0x1341d0 ldrb r3, [r3] */
/* @0x1341d4 ldr r10, [sp, #0x70] */
/* @0x1341d8 cmp r3, #0 */
/* @0x1341dc bne 0x1341f4 <_Z20F_SoundEffectFlangerR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1341e0 ldr r3, [pc, #0x108] */
/* @0x1341e4 ldr r3, [pc, r3] */
/* @0x1341e8 ldrb r1, [r3] */
/* @0x1341ec cmp r1, #0 */
/* @0x1341f0 beq 0x1341fc <_Z20F_SoundEffectFlangerR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1341f4 add sp, sp, #76 */
/* @0x1341f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1341fc mov r0, r10 */
/* @0x134200 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134204 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x134208 subs r1, r0, #0 */
/* @0x13420c beq 0x1342d8 <_Z20F_SoundEffectFlangerR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x134210 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x134214 mov r1, #1 */
/* @0x134218 mov r11, r0 */
/* @0x13421c mov r0, r10 */
/* @0x134220 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134224 mov r2, r0 */
/* @0x134228 mov r3, r1 */
/* @0x13422c mov r0, r10 */
/* @0x134230 mov r1, #2 */
/* @0x134234 str r2, [sp, #0x38] */
/* @0x134238 str r3, [sp, #0x34] */
/* @0x13423c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134240 mov r8, r0 */
/* @0x134244 mov r9, r1 */
/* @0x134248 mov r0, r10 */
/* @0x13424c mov r1, #3 */
/* @0x134250 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134254 mov r6, r0 */
/* @0x134258 mov r7, r1 */
/* @0x13425c mov r0, r10 */
/* @0x134260 mov r1, #4 */
/* @0x134264 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134268 mov r4, r0 */
/* @0x13426c mov r5, r1 */
/* @0x134270 mov r0, r10 */
/* @0x134274 mov r1, #5 */
/* @0x134278 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13427c mov r1, #6 */
/* @0x134280 mov r12, r0 */
/* @0x134284 mov r0, r10 */
/* @0x134288 str r12, [sp, #0x3c] */
/* @0x13428c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134290 strd r0, r1, [sp, #64] */
/* @0x134294 mov r1, #7 */
/* @0x134298 mov r0, r10 */
/* @0x13429c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1342a0 ldr r12, [sp, #0x3c] */
/* @0x1342a4 vldr d7, [sp, #64] */
/* @0x1342a8 strd r8, r9, [sp] */
/* @0x1342ac strd r6, r7, [sp, #8] */
/* @0x1342b0 vstr d7, [sp, #32] */
/* @0x1342b4 strd r4, r5, [sp, #16] */
/* @0x1342b8 str r12, [sp, #0x18] */
/* @0x1342bc ldr r2, [sp, #0x38] */
/* @0x1342c0 ldr r3, [sp, #0x34] */
/* @0x1342c4 str r0, [sp, #0x28] */
/* @0x1342c8 mov r0, r11 */
/* @0x1342cc bl 0x21f13c <_Z22SND_Set_Effect_Flangeriddddidi> */
/* @0x1342d0 add sp, sp, #76 */
/* @0x1342d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1342d8 ldr r0, [pc, #0x14] */
/* @0x1342dc add r0, pc, r0 */
/* @0x1342e0 add sp, sp, #76 */
/* @0x1342e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1342e8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1342ec eoreq r10, r11, r8, ror #22 */
/* @0x1342f0 eoreq r10, r11, r8, ror #28 */
/* @0x1342f4 .word 0x0020b1b0 */

/* ── FUNC 0x1342f8 · F_SoundEffectGargle(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x1342f8 ldr r3, [pc, #0x84] */
/* @0x1342fc push {r4, r5, r6, lr} */
/* @0x134300 ldr r3, [pc, r3] */
/* @0x134304 ldr r4, [sp, #0x10] */
/* @0x134308 ldrb r3, [r3] */
/* @0x13430c cmp r3, #0 */
/* @0x134310 popne {r4, r5, r6, pc} */
/* @0x134314 ldr r3, [pc, #0x6c] */
/* @0x134318 ldr r3, [pc, r3] */
/* @0x13431c ldrb r1, [r3] */
/* @0x134320 cmp r1, #0 */
/* @0x134324 popne {r4, r5, r6, pc} */
/* @0x134328 mov r0, r4 */
/* @0x13432c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134330 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x134334 subs r1, r0, #0 */
/* @0x134338 beq 0x134374 <_Z19F_SoundEffectGargleR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x13433c bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x134340 mov r1, #1 */
/* @0x134344 mov r6, r0 */
/* @0x134348 mov r0, r4 */
/* @0x13434c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134350 mov r1, #2 */
/* @0x134354 mov r5, r0 */
/* @0x134358 mov r0, r4 */
/* @0x13435c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134360 mov r1, r5 */
/* @0x134364 mov r2, r0 */
/* @0x134368 mov r0, r6 */
/* @0x13436c pop {r4, r5, r6, lr} */
/* @0x134370 b 0x21f144 <_Z21SND_Set_Effect_Gargleiii> */
/* @0x134374 ldr r0, [pc, #0x10] */
/* @0x134378 pop {r4, r5, r6, lr} */
/* @0x13437c add r0, pc, r0 */
/* @0x134380 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x134384 eoreq r10, r11, r0, lsr r10 */
/* @0x134388 eoreq r10, r11, r4, lsr sp */
/* @0x13438c eoreq r11, r0, r0, lsl r1 */

/* ── FUNC 0x134390 · F_SoundEffectEqualizer(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x134390 ldr r3, [pc, #0xb8] */
/* @0x134394 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x134398 ldr r3, [pc, r3] */
/* @0x13439c sub sp, sp, #20 */
/* @0x1343a0 ldrb r3, [r3] */
/* @0x1343a4 ldr r8, [sp, #0x30] */
/* @0x1343a8 cmp r3, #0 */
/* @0x1343ac bne 0x1343c4 <_Z22F_SoundEffectEqualizerR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1343b0 ldr r3, [pc, #0x9c] */
/* @0x1343b4 ldr r3, [pc, r3] */
/* @0x1343b8 ldrb r1, [r3] */
/* @0x1343bc cmp r1, #0 */
/* @0x1343c0 beq 0x1343cc <_Z22F_SoundEffectEqualizerR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1343c4 add sp, sp, #20 */
/* @0x1343c8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1343cc mov r0, r8 */
/* @0x1343d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1343d4 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x1343d8 subs r1, r0, #0 */
/* @0x1343dc beq 0x13443c <_Z22F_SoundEffectEqualizerR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x1343e0 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x1343e4 mov r1, #1 */
/* @0x1343e8 mov r9, r0 */
/* @0x1343ec mov r0, r8 */
/* @0x1343f0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1343f4 mov r4, r0 */
/* @0x1343f8 mov r5, r1 */
/* @0x1343fc mov r0, r8 */
/* @0x134400 mov r1, #2 */
/* @0x134404 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134408 mov r6, r0 */
/* @0x13440c mov r7, r1 */
/* @0x134410 mov r0, r8 */
/* @0x134414 mov r1, #3 */
/* @0x134418 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13441c strd r6, r7, [sp] */
/* @0x134420 mov r2, r4 */
/* @0x134424 mov r3, r5 */
/* @0x134428 strd r0, r1, [sp, #8] */
/* @0x13442c mov r0, r9 */
/* @0x134430 bl 0x21f14c <_Z24SND_Set_Effect_Equalizeriddd> */
/* @0x134434 add sp, sp, #20 */
/* @0x134438 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x13443c ldr r0, [pc, #0x14] */
/* @0x134440 add r0, pc, r0 */
/* @0x134444 add sp, sp, #20 */
/* @0x134448 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x13444c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x134450 mlaeq r11, r8, r9, r10 */
/* @0x134454 mlaeq r11, r8, r12, r10 */
/* @0x134458 eoreq r11, r0, r12, asr #32 */
