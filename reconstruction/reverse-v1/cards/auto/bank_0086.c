/* libyoyo.so 覆盖卡组 0086
 * 函数 0x151688..0x1551f0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x151688 · F_GamepadButtonValue(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x151688 push {r4, r5, r6, lr} */
/* @0x15168c mov r4, #0 */
/* @0x151690 ldr r6, [sp, #0x10] */
/* @0x151694 mov r5, r0 */
/* @0x151698 str r4, [r0, #0xc] */
/* @0x15169c str r4, [r0] */
/* @0x1516a0 str r4, [r0, #0x4] */
/* @0x1516a4 bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1516a8 mov r1, r4 */
/* @0x1516ac mov r0, r6 */
/* @0x1516b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1516b4 subs r4, r0, #0 */
/* @0x1516b8 poplt {r4, r5, r6, pc} */
/* @0x1516bc ldr r3, [pc, #0x58] */
/* @0x1516c0 ldr r3, [pc, r3] */
/* @0x1516c4 ldr r3, [r3] */
/* @0x1516c8 cmp r4, r3 */
/* @0x1516cc popge {r4, r5, r6, pc} */
/* @0x1516d0 mov r1, #1 */
/* @0x1516d4 mov r0, r6 */
/* @0x1516d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1516dc mov r1, r0 */
/* @0x1516e0 mov r0, r4 */
/* @0x1516e4 bl 0x190acc <_Z23TranslateGamepadButtonMii> */
/* @0x1516e8 ldr r3, [pc, #0x30] */
/* @0x1516ec ldr r3, [pc, r3] */
/* @0x1516f0 ldr r3, [r3] */
/* @0x1516f4 mov r1, r0 */
/* @0x1516f8 ldr r0, [r3, r4, lsl #2] */
/* @0x1516fc bl 0x18ed48 <_ZNK9GMGamePad11ButtonValueEi> */
/* @0x151700 vmov s15, r0 */
/* @0x151704 vcvt.f64.f32 d7, s15 */
/* @0x151708 vmov r0, r1, d7 */
/* @0x15170c vmov r2, s14 */
/* @0x151710 mov r3, r1 */
/* @0x151714 stm r5, {r2, r3} */
/* @0x151718 pop {r4, r5, r6, pc} */
/* @0x15171c eoreq lr, r9, r0, lsr #7 */
/* @0x151720 eoreq lr, r9, r8, ror r3 */

/* ── FUNC 0x151724 · F_GamepadAxisCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x151724 push {r4, lr} */
/* @0x151728 mov r3, #0 */
/* @0x15172c mov r4, r0 */
/* @0x151730 str r3, [r0, #0xc] */
/* @0x151734 str r3, [r0] */
/* @0x151738 mov r1, r3 */
/* @0x15173c str r3, [r0, #0x4] */
/* @0x151740 ldr r0, [sp, #0x8] */
/* @0x151744 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x151748 cmp r0, #0 */
/* @0x15174c poplt {r4, pc} */
/* @0x151750 ldr r3, [pc, #0x3c] */
/* @0x151754 ldr r3, [pc, r3] */
/* @0x151758 ldr r3, [r3] */
/* @0x15175c cmp r0, r3 */
/* @0x151760 popge {r4, pc} */
/* @0x151764 ldr r3, [pc, #0x2c] */
/* @0x151768 ldr r3, [pc, r3] */
/* @0x15176c ldr r3, [r3] */
/* @0x151770 ldr r0, [r3, r0, lsl #2] */
/* @0x151774 bl 0x18ed88 <_ZNK9GMGamePad9AxisCountEv> */
/* @0x151778 vmov s15, r0 */
/* @0x15177c vcvt.f64.s32 d7, s15 */
/* @0x151780 vmov r0, r1, d7 */
/* @0x151784 vmov r2, s14 */
/* @0x151788 mov r3, r1 */
/* @0x15178c stm r4, {r2, r3} */
/* @0x151790 pop {r4, pc} */
/* @0x151794 eoreq lr, r9, r12, lsl #6 */
/* @0x151798 .word 0x0029e2fc */

/* ── FUNC 0x15179c · F_GamepadSetColour(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x15179c push {r3, r4, r5, lr} */
/* @0x1517a0 mov r4, #0 */
/* @0x1517a4 ldr r5, [sp, #0x10] */
/* @0x1517a8 str r4, [r0, #0xc] */
/* @0x1517ac str r4, [r0] */
/* @0x1517b0 str r4, [r0, #0x4] */
/* @0x1517b4 bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1517b8 mov r1, r4 */
/* @0x1517bc mov r0, r5 */
/* @0x1517c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1517c4 subs r4, r0, #0 */
/* @0x1517c8 poplt {r3, r4, r5, pc} */
/* @0x1517cc ldr r3, [pc, #0x68] */
/* @0x1517d0 ldr r3, [pc, r3] */
/* @0x1517d4 ldr r3, [r3] */
/* @0x1517d8 cmp r4, r3 */
/* @0x1517dc popge {r3, r4, r5, pc} */
/* @0x1517e0 mov r0, r5 */
/* @0x1517e4 mov r1, #1 */
/* @0x1517e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1517ec ldr r3, [pc, #0x4c] */
/* @0x1517f0 ldr r1, [pc, #0x4c] */
/* @0x1517f4 ldr r3, [pc, r3] */
/* @0x1517f8 add r1, pc, r1 */
/* @0x1517fc ldr r3, [r3] */
/* @0x151800 ldr r2, [r3] */
/* @0x151804 ldr r12, [r2, #0xc] */
/* @0x151808 bic r5, r0, #-16777216 */
/* @0x15180c mov r0, r3 */
/* @0x151810 orr r5, r5, #16777216 */
/* @0x151814 mov r2, r5 */
/* @0x151818 blx r12 */
/* @0x15181c ldr r3, [pc, #0x24] */
/* @0x151820 mov r2, r5 */
/* @0x151824 mov r1, r4 */
/* @0x151828 ldr r3, [pc, r3] */
/* @0x15182c ldr r3, [r3] */
/* @0x151830 ldr r0, [r3, r4, lsl #2] */
/* @0x151834 pop {r3, r4, r5, lr} */
/* @0x151838 b 0x18ed84 <_ZN9GMGamePad9SetColourEij> */
/* @0x15183c mlaeq r9, r0, r2, lr */
/* @0x151840 eoreq r11, r9, r0, lsr #30 */
/* @0x151844 andseq r4, pc, r12, asr r3 */
/* @0x151848 eoreq lr, r9, r12, lsr r2 */

/* ── FUNC 0x15184c · F_GamepadAxisValue(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x15184c push {r4, r5, r6, lr} */
/* @0x151850 mov r4, #0 */
/* @0x151854 ldr r6, [sp, #0x10] */
/* @0x151858 mov r5, r0 */
/* @0x15185c str r4, [r0, #0xc] */
/* @0x151860 str r4, [r0] */
/* @0x151864 str r4, [r0, #0x4] */
/* @0x151868 bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x15186c mov r1, r4 */
/* @0x151870 mov r0, r6 */
/* @0x151874 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x151878 subs r4, r0, #0 */
/* @0x15187c poplt {r4, r5, r6, pc} */
/* @0x151880 ldr r3, [pc, #0x58] */
/* @0x151884 ldr r3, [pc, r3] */
/* @0x151888 ldr r3, [r3] */
/* @0x15188c cmp r4, r3 */
/* @0x151890 popge {r4, r5, r6, pc} */
/* @0x151894 mov r1, #1 */
/* @0x151898 mov r0, r6 */
/* @0x15189c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1518a0 mov r1, r0 */
/* @0x1518a4 mov r0, r4 */
/* @0x1518a8 bl 0x190b44 <_Z21TranslateGamepadAxisMii> */
/* @0x1518ac ldr r3, [pc, #0x30] */
/* @0x1518b0 ldr r3, [pc, r3] */
/* @0x1518b4 ldr r3, [r3] */
/* @0x1518b8 mov r1, r0 */
/* @0x1518bc ldr r0, [r3, r4, lsl #2] */
/* @0x1518c0 bl 0x18ed9c <_ZNK9GMGamePad9AxisValueEi> */
/* @0x1518c4 vmov s15, r0 */
/* @0x1518c8 vcvt.f64.f32 d7, s15 */
/* @0x1518cc vmov r0, r1, d7 */
/* @0x1518d0 vmov r2, s14 */
/* @0x1518d4 mov r3, r1 */
/* @0x1518d8 stm r5, {r2, r3} */
/* @0x1518dc pop {r4, r5, r6, pc} */
/* @0x1518e0 .word 0x0029e1dc */
/* @0x1518e4 .word 0x0029e1b4 */

/* ── FUNC 0x1518e8 · F_GamepadSetVibration(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x1518e8 push {r4, r5, r6, lr} */
/* @0x1518ec mov r4, #0 */
/* @0x1518f0 ldr r5, [sp, #0x10] */
/* @0x1518f4 str r4, [r0, #0xc] */
/* @0x1518f8 str r4, [r0] */
/* @0x1518fc str r4, [r0, #0x4] */
/* @0x151900 bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x151904 mov r0, r5 */
/* @0x151908 mov r1, r4 */
/* @0x15190c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x151910 subs r2, r0, #0 */
/* @0x151914 poplt {r4, r5, r6, pc} */
/* @0x151918 ldr r3, [pc, #0x4c] */
/* @0x15191c ldr r3, [pc, r3] */
/* @0x151920 ldr r3, [r3] */
/* @0x151924 cmp r2, r3 */
/* @0x151928 popge {r4, r5, r6, pc} */
/* @0x15192c ldr r3, [pc, #0x3c] */
/* @0x151930 mov r0, r5 */
/* @0x151934 mov r1, #1 */
/* @0x151938 ldr r3, [pc, r3] */
/* @0x15193c ldr r3, [r3] */
/* @0x151940 ldr r6, [r3, r2, lsl #2] */
/* @0x151944 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x151948 mov r1, #2 */
/* @0x15194c mov r4, r0 */
/* @0x151950 mov r0, r5 */
/* @0x151954 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x151958 mov r1, r4 */
/* @0x15195c mov r2, r0 */
/* @0x151960 mov r0, r6 */
/* @0x151964 pop {r4, r5, r6, lr} */
/* @0x151968 b 0x18eee8 <_ZN9GMGamePad14SetMotorSpeedsEff> */
/* @0x15196c eoreq lr, r9, r4, asr #2 */
/* @0x151970 eoreq lr, r9, r12, lsr #2 */

/* ── FUNC 0x151974 · F_GamepadSetButtonThreshold(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x151974 push {r3, r4, r5, lr} */
/* @0x151978 mov r3, #0 */
/* @0x15197c ldr r4, [sp, #0x10] */
/* @0x151980 mov r1, r3 */
/* @0x151984 str r3, [r0, #0xc] */
/* @0x151988 str r3, [r0] */
/* @0x15198c str r3, [r0, #0x4] */
/* @0x151990 mov r0, r4 */
/* @0x151994 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x151998 subs r5, r0, #0 */
/* @0x15199c poplt {r3, r4, r5, pc} */
/* @0x1519a0 ldr r3, [pc, #0x64] */
/* @0x1519a4 ldr r3, [pc, r3] */
/* @0x1519a8 ldr r3, [r3] */
/* @0x1519ac cmp r5, r3 */
/* @0x1519b0 popge {r3, r4, r5, pc} */
/* @0x1519b4 mov r0, r4 */
/* @0x1519b8 mov r1, #1 */
/* @0x1519bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1519c0 vmov s15, r0 */
/* @0x1519c4 vcmpe.f32 s15, #0 */
/* @0x1519c8 vmrs APSR_nzcv, fpscr */
/* @0x1519cc bmi 0x1519e0 <_Z27F_GamepadSetButtonThresholdR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1519d0 vmov.f32 s14, #1.000000e+00 */
/* @0x1519d4 vcmpe.f32 s15, s14 */
/* @0x1519d8 vmrs APSR_nzcv, fpscr */
/* @0x1519dc ble 0x1519f4 <_Z27F_GamepadSetButtonThresholdR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1519e0 ldr r0, [pc, #0x28] */
/* @0x1519e4 mov r1, #0 */
/* @0x1519e8 pop {r3, r4, r5, lr} */
/* @0x1519ec add r0, pc, r0 */
/* @0x1519f0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1519f4 ldr r3, [pc, #0x18] */
/* @0x1519f8 ldr r3, [pc, r3] */
/* @0x1519fc ldr r3, [r3] */
/* @0x151a00 ldr r3, [r3, r5, lsl #2] */
/* @0x151a04 vstr s15, [r3, #28] */
/* @0x151a08 pop {r3, r4, r5, pc} */
/* @0x151a0c strhteq lr, [r9], -r12 */
/* @0x151a10 andseq r4, pc, r4, lsl #3 */
/* @0x151a14 eoreq lr, r9, r12, rrx */

/* ── FUNC 0x151a18 · F_GamepadSetAxisDeadzone(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x151a18 push {r3, r4, r5, lr} */
/* @0x151a1c mov r3, #0 */
/* @0x151a20 ldr r4, [sp, #0x10] */
/* @0x151a24 mov r1, r3 */
/* @0x151a28 str r3, [r0, #0xc] */
/* @0x151a2c str r3, [r0] */
/* @0x151a30 str r3, [r0, #0x4] */
/* @0x151a34 mov r0, r4 */
/* @0x151a38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x151a3c subs r5, r0, #0 */
/* @0x151a40 poplt {r3, r4, r5, pc} */
/* @0x151a44 ldr r3, [pc, #0x64] */
/* @0x151a48 ldr r3, [pc, r3] */
/* @0x151a4c ldr r3, [r3] */
/* @0x151a50 cmp r5, r3 */
/* @0x151a54 popge {r3, r4, r5, pc} */
/* @0x151a58 mov r0, r4 */
/* @0x151a5c mov r1, #1 */
/* @0x151a60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x151a64 vmov s15, r0 */
/* @0x151a68 vcmpe.f32 s15, #0 */
/* @0x151a6c vmrs APSR_nzcv, fpscr */
/* @0x151a70 bmi 0x151a84 <_Z24F_GamepadSetAxisDeadzoneR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x151a74 vmov.f32 s14, #1.000000e+00 */
/* @0x151a78 vcmpe.f32 s15, s14 */
/* @0x151a7c vmrs APSR_nzcv, fpscr */
/* @0x151a80 ble 0x151a98 <_Z24F_GamepadSetAxisDeadzoneR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x151a84 ldr r0, [pc, #0x28] */
/* @0x151a88 mov r1, #0 */
/* @0x151a8c pop {r3, r4, r5, lr} */
/* @0x151a90 add r0, pc, r0 */
/* @0x151a94 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x151a98 ldr r3, [pc, #0x18] */
/* @0x151a9c ldr r3, [pc, r3] */
/* @0x151aa0 ldr r3, [r3] */
/* @0x151aa4 ldr r3, [r3, r5, lsl #2] */
/* @0x151aa8 vstr s15, [r3, #32] */
/* @0x151aac pop {r3, r4, r5, pc} */
/* @0x151ab0 eoreq lr, r9, r8, lsl r0 */
/* @0x151ab4 andseq r4, pc, r0, lsl r1 */
/* @0x151ab8 eoreq sp, r9, r8, asr #31 */

/* ── FUNC 0x151abc · F_GamepadGetDatabase(RValue&, CInstance*, CInstance*, int, RValue*) · size=3032 · insn=758 */
/* @0x151abc ldr r3, [pc, #0xb94] */
/* @0x151ac0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x151ac4 ldr r3, [pc, r3] */
/* @0x151ac8 sub sp, sp, #68 */
/* @0x151acc mov r4, #0 */
/* @0x151ad0 ldr r10, [r3] */
/* @0x151ad4 str r0, [sp, #0x2c] */
/* @0x151ad8 cmp r10, r4 */
/* @0x151adc str r4, [sp, #0x34] */
/* @0x151ae0 str r4, [sp, #0x38] */
/* @0x151ae4 str r4, [sp, #0x3c] */
/* @0x151ae8 beq 0x152650 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb94> */
/* @0x151aec ldr r3, [pc, #0xb68] */
/* @0x151af0 mov r7, r4 */
/* @0x151af4 ldr r12, [pc, #0xb64] */
/* @0x151af8 mov r8, r4 */
/* @0x151afc add r3, pc, r3 */
/* @0x151b00 str r3, [sp, #0x14] */
/* @0x151b04 ldr r3, [pc, #0xb58] */
/* @0x151b08 add r12, pc, r12 */
/* @0x151b0c str r12, [sp, #0x1c] */
/* @0x151b10 ldr r12, [pc, #0xb50] */
/* @0x151b14 add r3, pc, r3 */
/* @0x151b18 str r3, [sp, #0x24] */
/* @0x151b1c ldr r3, [sp, #0x14] */
/* @0x151b20 add r12, pc, r12 */
/* @0x151b24 str r12, [sp, #0x20] */
/* @0x151b28 ldr r12, [pc, #0xb3c] */
/* @0x151b2c str r3, [sp, #0x18] */
/* @0x151b30 add r12, pc, r12 */
/* @0x151b34 str r10, [sp] */
/* @0x151b38 str r12, [sp, #0x28] */
/* @0x151b3c ldr r3, [sp] */
/* @0x151b40 ldr r6, [r3, #0x4] */
/* @0x151b44 cmp r6, #0 */
/* @0x151b48 beq 0x151be8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x151b4c mov r0, r6 */
/* @0x151b50 bl 0xb6538 <strlen@plt> */
/* @0x151b54 mvn r2, r7 */
/* @0x151b58 add r2, r2, r8 */
/* @0x151b5c add r3, r0, #1 */
/* @0x151b60 mov r5, r0 */
/* @0x151b64 cmp r3, r2 */
/* @0x151b68 ble 0x151bc8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x151b6c cmp r8, #0 */
/* @0x151b70 moveq r8, r3 */
/* @0x151b74 add r3, r3, r7 */
/* @0x151b78 add r8, r8, r8, lsl #1 */
/* @0x151b7c add r8, r8, r8, lsr #31 */
/* @0x151b80 asr r7, r8, #1 */
/* @0x151b84 cmp r7, r3 */
/* @0x151b88 addlt r3, r3, r3, lsl #1 */
/* @0x151b8c addlt r3, r3, r3, lsr #31 */
/* @0x151b90 asrlt r7, r3, #1 */
/* @0x151b94 mov r0, r7 */
/* @0x151b98 bl 0xcef4c <_Z7YYAlloci> */
/* @0x151b9c mov r1, r4 */
/* @0x151ba0 ldr r2, [sp, #0x38] */
/* @0x151ba4 str r0, [sp, #0x34] */
/* @0x151ba8 bl 0xb65bc <memcpy@plt> */
/* @0x151bac cmp r4, #0 */
/* @0x151bb0 str r7, [sp, #0x38] */
/* @0x151bb4 beq 0x151bc0 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x151bb8 mov r0, r4 */
/* @0x151bbc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x151bc0 ldr r7, [sp, #0x3c] */
/* @0x151bc4 ldr r4, [sp, #0x34] */
/* @0x151bc8 add r0, r4, r7 */
/* @0x151bcc mov r1, r6 */
/* @0x151bd0 bl 0xb65a4 <strcpy@plt> */
/* @0x151bd4 ldr r8, [sp, #0x38] */
/* @0x151bd8 ldr r4, [sp, #0x34] */
/* @0x151bdc ldr r7, [sp, #0x3c] */
/* @0x151be0 add r7, r5, r7 */
/* @0x151be4 str r7, [sp, #0x3c] */
/* @0x151be8 mvn r3, r7 */
/* @0x151bec add r3, r3, r8 */
/* @0x151bf0 cmp r3, #1 */
/* @0x151bf4 bgt 0x151c54 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x151bf8 cmp r8, #0 */
/* @0x151bfc add r7, r7, #2 */
/* @0x151c00 addne r8, r8, r8, lsl #1 */
/* @0x151c04 moveq r5, #3 */
/* @0x151c08 addne r8, r8, r8, lsr #31 */
/* @0x151c0c asrne r5, r8, #1 */
/* @0x151c10 cmp r7, r5 */
/* @0x151c14 addgt r7, r7, r7, lsl #1 */
/* @0x151c18 addgt r7, r7, r7, lsr #31 */
/* @0x151c1c asrgt r5, r7, #1 */
/* @0x151c20 mov r0, r5 */
/* @0x151c24 bl 0xcef4c <_Z7YYAlloci> */
/* @0x151c28 mov r1, r4 */
/* @0x151c2c ldr r2, [sp, #0x38] */
/* @0x151c30 str r0, [sp, #0x34] */
/* @0x151c34 bl 0xb65bc <memcpy@plt> */
/* @0x151c38 cmp r4, #0 */
/* @0x151c3c str r5, [sp, #0x38] */
/* @0x151c40 beq 0x151c4c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x151c44 mov r0, r4 */
/* @0x151c48 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x151c4c ldr r7, [sp, #0x3c] */
/* @0x151c50 ldr r4, [sp, #0x34] */
/* @0x151c54 ldr r12, [sp, #0x14] */
/* @0x151c58 ldrh r3, [r12] */
/* @0x151c5c strh r3, [r4, r7] */
/* @0x151c60 ldr r3, [sp] */
/* @0x151c64 ldr r5, [sp, #0x3c] */
/* @0x151c68 ldr r6, [r3, #0x8] */
/* @0x151c6c add r5, r5, #1 */
/* @0x151c70 str r5, [sp, #0x3c] */
/* @0x151c74 cmp r6, #0 */
/* @0x151c78 beq 0x151d18 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x151c7c mov r0, r6 */
/* @0x151c80 bl 0xb6538 <strlen@plt> */
/* @0x151c84 ldr r3, [sp, #0x38] */
/* @0x151c88 mvn r1, r5 */
/* @0x151c8c add r1, r3, r1 */
/* @0x151c90 add r2, r0, #1 */
/* @0x151c94 mov r4, r0 */
/* @0x151c98 cmp r2, r1 */
/* @0x151c9c ble 0x151cfc <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x240> */
/* @0x151ca0 cmp r3, #0 */
/* @0x151ca4 moveq r3, r2 */
/* @0x151ca8 add r2, r5, r2 */
/* @0x151cac add r3, r3, r3, lsl #1 */
/* @0x151cb0 ldr r5, [sp, #0x34] */
/* @0x151cb4 add r3, r3, r3, lsr #31 */
/* @0x151cb8 asr r7, r3, #1 */
/* @0x151cbc cmp r7, r2 */
/* @0x151cc0 addlt r2, r2, r2, lsl #1 */
/* @0x151cc4 addlt r2, r2, r2, lsr #31 */
/* @0x151cc8 asrlt r7, r2, #1 */
/* @0x151ccc mov r0, r7 */
/* @0x151cd0 bl 0xcef4c <_Z7YYAlloci> */
/* @0x151cd4 ldr r2, [sp, #0x38] */
/* @0x151cd8 mov r1, r5 */
/* @0x151cdc str r0, [sp, #0x34] */
/* @0x151ce0 bl 0xb65bc <memcpy@plt> */
/* @0x151ce4 cmp r5, #0 */
/* @0x151ce8 str r7, [sp, #0x38] */
/* @0x151cec beq 0x151cf8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x151cf0 mov r0, r5 */
/* @0x151cf4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x151cf8 ldr r5, [sp, #0x3c] */
/* @0x151cfc ldr r0, [sp, #0x34] */
/* @0x151d00 mov r1, r6 */
/* @0x151d04 add r0, r0, r5 */
/* @0x151d08 bl 0xb65a4 <strcpy@plt> */
/* @0x151d0c ldr r5, [sp, #0x3c] */
/* @0x151d10 add r5, r4, r5 */
/* @0x151d14 str r5, [sp, #0x3c] */
/* @0x151d18 ldr r3, [sp, #0x38] */
/* @0x151d1c mvn r2, r5 */
/* @0x151d20 add r2, r3, r2 */
/* @0x151d24 cmp r2, #1 */
/* @0x151d28 bgt 0x151d88 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x2cc> */
/* @0x151d2c cmp r3, #0 */
/* @0x151d30 add r5, r5, #2 */
/* @0x151d34 addne r3, r3, r3, lsl #1 */
/* @0x151d38 ldr r4, [sp, #0x34] */
/* @0x151d3c moveq r6, #3 */
/* @0x151d40 addne r3, r3, r3, lsr #31 */
/* @0x151d44 asrne r6, r3, #1 */
/* @0x151d48 cmp r5, r6 */
/* @0x151d4c addgt r5, r5, r5, lsl #1 */
/* @0x151d50 addgt r5, r5, r5, lsr #31 */
/* @0x151d54 asrgt r6, r5, #1 */
/* @0x151d58 mov r0, r6 */
/* @0x151d5c bl 0xcef4c <_Z7YYAlloci> */
/* @0x151d60 ldr r2, [sp, #0x38] */
/* @0x151d64 mov r1, r4 */
/* @0x151d68 str r0, [sp, #0x34] */
/* @0x151d6c bl 0xb65bc <memcpy@plt> */
/* @0x151d70 cmp r4, #0 */
/* @0x151d74 str r6, [sp, #0x38] */
/* @0x151d78 beq 0x151d84 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x2c8> */
/* @0x151d7c mov r0, r4 */
/* @0x151d80 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x151d84 ldr r5, [sp, #0x3c] */
/* @0x151d88 ldr r12, [sp, #0x18] */
/* @0x151d8c ldr r3, [sp, #0x34] */
/* @0x151d90 ldrh r2, [r12] */
/* @0x151d94 strh r2, [r3, r5] */
/* @0x151d98 ldr r1, [sp, #0x3c] */
/* @0x151d9c ldr r3, [sp, #0x38] */
/* @0x151da0 add r2, r1, #1 */
/* @0x151da4 str r2, [sp, #0x3c] */
/* @0x151da8 mvn r0, r2 */
/* @0x151dac add r0, r3, r0 */
/* @0x151db0 cmp r0, #9 */
/* @0x151db4 bgt 0x151e14 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x358> */
/* @0x151db8 cmp r3, #0 */
/* @0x151dbc add r1, r1, #11 */
/* @0x151dc0 addne r3, r3, r3, lsl #1 */
/* @0x151dc4 ldr r4, [sp, #0x34] */
/* @0x151dc8 moveq r5, #15 */
/* @0x151dcc addne r3, r3, r3, lsr #31 */
/* @0x151dd0 asrne r5, r3, #1 */
/* @0x151dd4 cmp r1, r5 */
/* @0x151dd8 addgt r1, r1, r1, lsl #1 */
/* @0x151ddc addgt r1, r1, r1, lsr #31 */
/* @0x151de0 asrgt r5, r1, #1 */
/* @0x151de4 mov r0, r5 */
/* @0x151de8 bl 0xcef4c <_Z7YYAlloci> */
/* @0x151dec ldr r2, [sp, #0x38] */
/* @0x151df0 mov r1, r4 */
/* @0x151df4 str r0, [sp, #0x34] */
/* @0x151df8 bl 0xb65bc <memcpy@plt> */
/* @0x151dfc cmp r4, #0 */
/* @0x151e00 str r5, [sp, #0x38] */
/* @0x151e04 beq 0x151e10 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x354> */
/* @0x151e08 mov r0, r4 */
/* @0x151e0c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x151e10 ldr r2, [sp, #0x3c] */
/* @0x151e14 ldr r3, [sp, #0x1c] */
/* @0x151e18 ldr lr, [sp, #0x34] */
/* @0x151e1c ldm r3!, {r0, r1} */
/* @0x151e20 add r12, lr, r2 */
/* @0x151e24 ldrh r3, [r3] */
/* @0x151e28 str r0, [lr, r2] */
/* @0x151e2c str r1, [r12, #0x4] */
/* @0x151e30 strh r3, [r12, #8] */
/* @0x151e34 ldr r3, [sp] */
/* @0x151e38 ldr r1, [sp, #0x3c] */
/* @0x151e3c ldr r2, [r3, #0xc] */
/* @0x151e40 add r3, r1, #9 */
/* @0x151e44 str r3, [sp, #0x3c] */
/* @0x151e48 cmp r2, #1 */
/* @0x151e4c beq 0x15257c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xac0> */
/* @0x151e50 cmp r2, #6 */
/* @0x151e54 ldr r2, [sp, #0x38] */
/* @0x151e58 mvn r0, r3 */
/* @0x151e5c add r0, r2, r0 */
/* @0x151e60 beq 0x1524ec <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xa30> */
/* @0x151e64 cmp r0, #7 */
/* @0x151e68 bgt 0x151ec8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x40c> */
/* @0x151e6c cmp r2, #0 */
/* @0x151e70 add r1, r1, #17 */
/* @0x151e74 addne r2, r2, r2, lsl #1 */
/* @0x151e78 ldr r4, [sp, #0x34] */
/* @0x151e7c moveq r5, #12 */
/* @0x151e80 addne r2, r2, r2, lsr #31 */
/* @0x151e84 asrne r5, r2, #1 */
/* @0x151e88 cmp r1, r5 */
/* @0x151e8c addgt r1, r1, r1, lsl #1 */
/* @0x151e90 addgt r1, r1, r1, lsr #31 */
/* @0x151e94 asrgt r5, r1, #1 */
/* @0x151e98 mov r0, r5 */
/* @0x151e9c bl 0xcef4c <_Z7YYAlloci> */
/* @0x151ea0 ldr r2, [sp, #0x38] */
/* @0x151ea4 mov r1, r4 */
/* @0x151ea8 str r0, [sp, #0x34] */
/* @0x151eac bl 0xb65bc <memcpy@plt> */
/* @0x151eb0 cmp r4, #0 */
/* @0x151eb4 str r5, [sp, #0x38] */
/* @0x151eb8 beq 0x151ec4 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x408> */
/* @0x151ebc mov r0, r4 */
/* @0x151ec0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x151ec4 ldr r3, [sp, #0x3c] */
/* @0x151ec8 ldr r2, [sp, #0x28] */
/* @0x151ecc ldr r12, [sp, #0x34] */
/* @0x151ed0 ldm r2!, {r0, r1} */
/* @0x151ed4 add r2, r12, r3 */
/* @0x151ed8 str r0, [r12, r3] */
/* @0x151edc str r1, [r2, #0x4] */
/* @0x151ee0 ldr r3, [sp, #0x3c] */
/* @0x151ee4 add r3, r3, #7 */
/* @0x151ee8 str r3, [sp, #0x3c] */
/* @0x151eec ldr r2, [sp, #0x38] */
/* @0x151ef0 mvn r1, r3 */
/* @0x151ef4 add r1, r2, r1 */
/* @0x151ef8 cmp r1, #1 */
/* @0x151efc bgt 0x151f5c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x4a0> */
/* @0x151f00 cmp r2, #0 */
/* @0x151f04 add r3, r3, #2 */
/* @0x151f08 addne r2, r2, r2, lsl #1 */
/* @0x151f0c ldr r4, [sp, #0x34] */
/* @0x151f10 moveq r5, #3 */
/* @0x151f14 addne r2, r2, r2, lsr #31 */
/* @0x151f18 asrne r5, r2, #1 */
/* @0x151f1c cmp r3, r5 */
/* @0x151f20 addgt r3, r3, r3, lsl #1 */
/* @0x151f24 addgt r3, r3, r3, lsr #31 */
/* @0x151f28 asrgt r5, r3, #1 */
/* @0x151f2c mov r0, r5 */
/* @0x151f30 bl 0xcef4c <_Z7YYAlloci> */
/* @0x151f34 ldr r2, [sp, #0x38] */
/* @0x151f38 mov r1, r4 */
/* @0x151f3c str r0, [sp, #0x34] */
/* @0x151f40 bl 0xb65bc <memcpy@plt> */
/* @0x151f44 cmp r4, #0 */
/* @0x151f48 str r5, [sp, #0x38] */
/* @0x151f4c beq 0x151f58 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x49c> */
/* @0x151f50 mov r0, r4 */
/* @0x151f54 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x151f58 ldr r3, [sp, #0x3c] */
/* @0x151f5c ldr r1, [pc, #0x70c] */
/* @0x151f60 mov r5, #0 */
/* @0x151f64 ldr r2, [sp, #0x34] */
/* @0x151f68 add r1, pc, r1 */
/* @0x151f6c ldr r12, [sp] */
/* @0x151f70 ldr r9, [pc, #0x6fc] */
/* @0x151f74 ldrh r1, [r1] */
/* @0x151f78 add r4, r12, #28 */
/* @0x151f7c ldr r12, [pc, #0x6f4] */
/* @0x151f80 add r9, pc, r9 */
/* @0x151f84 ldr r8, [pc, #0x6f0] */
/* @0x151f88 strh r1, [r2, r3] */
/* @0x151f8c add r12, pc, r12 */
/* @0x151f90 ldr r2, [sp, #0x3c] */
/* @0x151f94 add r8, pc, r8 */
/* @0x151f98 ldr r3, [pc, #0x6e0] */
/* @0x151f9c add r11, r2, #1 */
/* @0x151fa0 str r12, [sp, #0x4] */
/* @0x151fa4 add r3, pc, r3 */
/* @0x151fa8 ldr r12, [pc, #0x6d4] */
/* @0x151fac str r3, [sp, #0x8] */
/* @0x151fb0 mov r10, r11 */
/* @0x151fb4 ldr r3, [pc, #0x6cc] */
/* @0x151fb8 add r12, pc, r12 */
/* @0x151fbc str r11, [sp, #0x3c] */
/* @0x151fc0 add r3, pc, r3 */
/* @0x151fc4 str r12, [sp, #0xc] */
/* @0x151fc8 str r3, [sp, #0x10] */
/* @0x151fcc b 0x151fe0 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x524> */
/* @0x151fd0 add r5, r5, #8 */
/* @0x151fd4 add r4, r4, #12 */
/* @0x151fd8 cmp r5, #168 */
/* @0x151fdc beq 0x1521d8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x71c> */
/* @0x151fe0 ldr r3, [r4, #-0xc] */
/* @0x151fe4 cmp r3, #0 */
/* @0x151fe8 beq 0x151fd0 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x514> */
/* @0x151fec ldr r3, [pc, #0x698] */
/* @0x151ff0 ldr r3, [pc, r3] */
/* @0x151ff4 ldr r11, [r5, r3] */
/* @0x151ff8 cmp r11, #0 */
/* @0x151ffc beq 0x15209c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x5e0> */
/* @0x152000 mov r0, r11 */
/* @0x152004 bl 0xb6538 <strlen@plt> */
/* @0x152008 ldr r12, [sp, #0x38] */
/* @0x15200c add r1, r0, #1 */
/* @0x152010 mov r6, r0 */
/* @0x152014 mvn r0, r10 */
/* @0x152018 add r0, r12, r0 */
/* @0x15201c cmp r1, r0 */
/* @0x152020 ble 0x152080 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x5c4> */
/* @0x152024 cmp r12, #0 */
/* @0x152028 add r2, r1, r10 */
/* @0x15202c ldr r7, [sp, #0x34] */
/* @0x152030 moveq r12, r1 */
/* @0x152034 add r12, r12, r12, lsl #1 */
/* @0x152038 add r12, r12, r12, lsr #31 */
/* @0x15203c asr r10, r12, #1 */
/* @0x152040 cmp r10, r2 */
/* @0x152044 addlt r2, r2, r2, lsl #1 */
/* @0x152048 addlt r2, r2, r2, lsr #31 */
/* @0x15204c asrlt r10, r2, #1 */
/* @0x152050 mov r0, r10 */
/* @0x152054 bl 0xcef4c <_Z7YYAlloci> */
/* @0x152058 ldr r2, [sp, #0x38] */
/* @0x15205c mov r1, r7 */
/* @0x152060 str r0, [sp, #0x34] */
/* @0x152064 bl 0xb65bc <memcpy@plt> */
/* @0x152068 cmp r7, #0 */
/* @0x15206c str r10, [sp, #0x38] */
/* @0x152070 beq 0x15207c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x5c0> */
/* @0x152074 mov r0, r7 */
/* @0x152078 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x15207c ldr r10, [sp, #0x3c] */
/* @0x152080 ldr r0, [sp, #0x34] */
/* @0x152084 mov r1, r11 */
/* @0x152088 add r0, r0, r10 */
/* @0x15208c bl 0xb65a4 <strcpy@plt> */
/* @0x152090 ldr r2, [sp, #0x3c] */
/* @0x152094 add r10, r6, r2 */
/* @0x152098 str r10, [sp, #0x3c] */
/* @0x15209c ldr r7, [sp, #0x38] */
/* @0x1520a0 mvn r3, r10 */
/* @0x1520a4 add r3, r7, r3 */
/* @0x1520a8 cmp r3, #1 */
/* @0x1520ac bgt 0x15210c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x650> */
/* @0x1520b0 cmp r7, #0 */
/* @0x1520b4 add r2, r10, #2 */
/* @0x1520b8 addne r7, r7, r7, lsl #1 */
/* @0x1520bc ldr r6, [sp, #0x34] */
/* @0x1520c0 moveq r7, #3 */
/* @0x1520c4 addne r7, r7, r7, lsr #31 */
/* @0x1520c8 asrne r7, r7, #1 */
/* @0x1520cc cmp r2, r7 */
/* @0x1520d0 addgt r2, r2, r2, lsl #1 */
/* @0x1520d4 addgt r2, r2, r2, lsr #31 */
/* @0x1520d8 asrgt r7, r2, #1 */
/* @0x1520dc mov r0, r7 */
/* @0x1520e0 bl 0xcef4c <_Z7YYAlloci> */
/* @0x1520e4 ldr r2, [sp, #0x38] */
/* @0x1520e8 mov r1, r6 */
/* @0x1520ec str r0, [sp, #0x34] */
/* @0x1520f0 bl 0xb65bc <memcpy@plt> */
/* @0x1520f4 cmp r6, #0 */
/* @0x1520f8 str r7, [sp, #0x38] */
/* @0x1520fc beq 0x152108 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x64c> */
/* @0x152100 mov r0, r6 */
/* @0x152104 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x152108 ldr r10, [sp, #0x3c] */
/* @0x15210c ldr r3, [sp, #0x34] */
/* @0x152110 ldrh r1, [r9] */
/* @0x152114 strh r1, [r3, r10] */
/* @0x152118 ldr r0, [r4, #-0xc] */
/* @0x15211c ldr r2, [sp, #0x3c] */
/* @0x152120 cmp r0, #2 */
/* @0x152124 add r3, r2, #1 */
/* @0x152128 str r3, [sp, #0x3c] */
/* @0x15212c beq 0x15246c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x9b0> */
/* @0x152130 cmp r0, #3 */
/* @0x152134 beq 0x15232c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x870> */
/* @0x152138 cmp r0, #1 */
/* @0x15213c beq 0x15228c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x7d0> */
/* @0x152140 ldr r7, [sp, #0x38] */
/* @0x152144 mvn r2, r3 */
/* @0x152148 add r2, r7, r2 */
/* @0x15214c cmp r2, #1 */
/* @0x152150 bgt 0x1521b0 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x6f4> */
/* @0x152154 cmp r7, #0 */
/* @0x152158 add r3, r3, #2 */
/* @0x15215c addne r7, r7, r7, lsl #1 */
/* @0x152160 ldr r6, [sp, #0x34] */
/* @0x152164 moveq r7, #3 */
/* @0x152168 addne r7, r7, r7, lsr #31 */
/* @0x15216c asrne r7, r7, #1 */
/* @0x152170 cmp r3, r7 */
/* @0x152174 addgt r3, r3, r3, lsl #1 */
/* @0x152178 addgt r3, r3, r3, lsr #31 */
/* @0x15217c asrgt r7, r3, #1 */
/* @0x152180 mov r0, r7 */
/* @0x152184 bl 0xcef4c <_Z7YYAlloci> */
/* @0x152188 ldr r2, [sp, #0x38] */
/* @0x15218c mov r1, r6 */
/* @0x152190 str r0, [sp, #0x34] */
/* @0x152194 bl 0xb65bc <memcpy@plt> */
/* @0x152198 cmp r6, #0 */
/* @0x15219c str r7, [sp, #0x38] */
/* @0x1521a0 beq 0x1521ac <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x6f0> */
/* @0x1521a4 mov r0, r6 */
/* @0x1521a8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1521ac ldr r3, [sp, #0x3c] */
/* @0x1521b0 ldr r2, [sp, #0x34] */
/* @0x1521b4 add r5, r5, #8 */
/* @0x1521b8 ldrh r1, [r8] */
/* @0x1521bc cmp r5, #168 */
/* @0x1521c0 add r4, r4, #12 */
/* @0x1521c4 strh r1, [r2, r3] */
/* @0x1521c8 ldr r2, [sp, #0x3c] */
/* @0x1521cc add r10, r2, #1 */
/* @0x1521d0 str r10, [sp, #0x3c] */
/* @0x1521d4 bne 0x151fe0 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x524> */
/* @0x1521d8 ldr r3, [sp, #0x38] */
/* @0x1521dc mvn r1, r10 */
/* @0x1521e0 mov r11, r10 */
/* @0x1521e4 add r1, r3, r1 */
/* @0x1521e8 cmp r1, #1 */
/* @0x1521ec bgt 0x15224c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x1521f0 cmp r3, #0 */
/* @0x1521f4 add r2, r10, #2 */
/* @0x1521f8 addne r3, r3, r3, lsl #1 */
/* @0x1521fc ldr r4, [sp, #0x34] */
/* @0x152200 moveq r5, #3 */
/* @0x152204 addne r3, r3, r3, lsr #31 */
/* @0x152208 asrne r5, r3, #1 */
/* @0x15220c cmp r2, r5 */
/* @0x152210 addgt r2, r2, r2, lsl #1 */
/* @0x152214 addgt r2, r2, r2, lsr #31 */
/* @0x152218 asrgt r5, r2, #1 */
/* @0x15221c mov r0, r5 */
/* @0x152220 bl 0xcef4c <_Z7YYAlloci> */
/* @0x152224 ldr r2, [sp, #0x38] */
/* @0x152228 mov r1, r4 */
/* @0x15222c str r0, [sp, #0x34] */
/* @0x152230 bl 0xb65bc <memcpy@plt> */
/* @0x152234 cmp r4, #0 */
/* @0x152238 str r5, [sp, #0x38] */
/* @0x15223c beq 0x152248 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x78c> */
/* @0x152240 mov r0, r4 */
/* @0x152244 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x152248 ldr r11, [sp, #0x3c] */
/* @0x15224c ldr r1, [pc, #0x43c] */
/* @0x152250 ldr r3, [sp, #0x34] */
/* @0x152254 add r1, pc, r1 */
/* @0x152258 ldrh r1, [r1] */
/* @0x15225c strh r1, [r3, r11] */
/* @0x152260 ldr r3, [sp] */
/* @0x152264 ldr r7, [sp, #0x3c] */
/* @0x152268 ldr r3, [r3] */
/* @0x15226c add r7, r7, #1 */
/* @0x152270 str r7, [sp, #0x3c] */
/* @0x152274 cmp r3, #0 */
/* @0x152278 str r3, [sp] */
/* @0x15227c beq 0x15261c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb60> */
/* @0x152280 ldr r4, [sp, #0x34] */
/* @0x152284 ldr r8, [sp, #0x38] */
/* @0x152288 b 0x151b3c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x15228c ldr r1, [sp, #0x38] */
/* @0x152290 mvn r0, r3 */
/* @0x152294 add r0, r1, r0 */
/* @0x152298 cmp r0, #1 */
/* @0x15229c bgt 0x1522fc <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x840> */
/* @0x1522a0 cmp r1, #0 */
/* @0x1522a4 add r2, r2, #3 */
/* @0x1522a8 addne r1, r1, r1, lsl #1 */
/* @0x1522ac ldr r6, [sp, #0x34] */
/* @0x1522b0 moveq r7, #3 */
/* @0x1522b4 addne r1, r1, r1, lsr #31 */
/* @0x1522b8 asrne r7, r1, #1 */
/* @0x1522bc cmp r2, r7 */
/* @0x1522c0 addgt r2, r2, r2, lsl #1 */
/* @0x1522c4 addgt r2, r2, r2, lsr #31 */
/* @0x1522c8 asrgt r7, r2, #1 */
/* @0x1522cc mov r0, r7 */
/* @0x1522d0 bl 0xcef4c <_Z7YYAlloci> */
/* @0x1522d4 ldr r2, [sp, #0x38] */
/* @0x1522d8 mov r1, r6 */
/* @0x1522dc str r0, [sp, #0x34] */
/* @0x1522e0 bl 0xb65bc <memcpy@plt> */
/* @0x1522e4 cmp r6, #0 */
/* @0x1522e8 str r7, [sp, #0x38] */
/* @0x1522ec beq 0x1522f8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x83c> */
/* @0x1522f0 mov r0, r6 */
/* @0x1522f4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1522f8 ldr r3, [sp, #0x3c] */
/* @0x1522fc ldr r2, [sp, #0x34] */
/* @0x152300 add r0, sp, #52 */
/* @0x152304 ldr r12, [sp, #0x10] */
/* @0x152308 ldrh r1, [r12] */
/* @0x15230c strh r1, [r2, r3] */
/* @0x152310 ldr r3, [sp, #0x3c] */
/* @0x152314 ldr r1, [r4, #-0x8] */
/* @0x152318 add r3, r3, #1 */
/* @0x15231c str r3, [sp, #0x3c] */
/* @0x152320 bl 0xd58c4 <_ZN12YYStrBuilderlsEi> */
/* @0x152324 ldr r3, [sp, #0x3c] */
/* @0x152328 b 0x152140 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x684> */
/* @0x15232c ldr r1, [sp, #0x38] */
/* @0x152330 mvn r12, r3 */
/* @0x152334 add r12, r1, r12 */
/* @0x152338 cmp r12, #1 */
/* @0x15233c bgt 0x15239c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x8e0> */
/* @0x152340 cmp r1, #0 */
/* @0x152344 add r2, r2, #3 */
/* @0x152348 addne r1, r1, r1, lsl #1 */
/* @0x15234c ldr r6, [sp, #0x34] */
/* @0x152350 moveq r7, r0 */
/* @0x152354 addne r1, r1, r1, lsr #31 */
/* @0x152358 asrne r7, r1, #1 */
/* @0x15235c cmp r2, r7 */
/* @0x152360 addgt r2, r2, r2, lsl #1 */
/* @0x152364 addgt r2, r2, r2, lsr #31 */
/* @0x152368 asrgt r7, r2, #1 */
/* @0x15236c mov r0, r7 */
/* @0x152370 bl 0xcef4c <_Z7YYAlloci> */
/* @0x152374 ldr r2, [sp, #0x38] */
/* @0x152378 mov r1, r6 */
/* @0x15237c str r0, [sp, #0x34] */
/* @0x152380 bl 0xb65bc <memcpy@plt> */
/* @0x152384 cmp r6, #0 */
/* @0x152388 str r7, [sp, #0x38] */
/* @0x15238c beq 0x152398 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x8dc> */
/* @0x152390 mov r0, r6 */
/* @0x152394 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x152398 ldr r3, [sp, #0x3c] */
/* @0x15239c ldr r12, [sp, #0x8] */
/* @0x1523a0 add r6, sp, #52 */
/* @0x1523a4 ldr r2, [sp, #0x34] */
/* @0x1523a8 mov r0, r6 */
/* @0x1523ac ldrh r1, [r12] */
/* @0x1523b0 strh r1, [r2, r3] */
/* @0x1523b4 ldr r3, [sp, #0x3c] */
/* @0x1523b8 ldr r1, [r4, #-0x8] */
/* @0x1523bc add r3, r3, #1 */
/* @0x1523c0 str r3, [sp, #0x3c] */
/* @0x1523c4 bl 0xd58c4 <_ZN12YYStrBuilderlsEi> */
/* @0x1523c8 ldr r2, [sp, #0x3c] */
/* @0x1523cc ldr r3, [sp, #0x38] */
/* @0x1523d0 mvn r1, r2 */
/* @0x1523d4 add r1, r3, r1 */
/* @0x1523d8 cmp r1, #1 */
/* @0x1523dc bgt 0x15243c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x980> */
/* @0x1523e0 cmp r3, #0 */
/* @0x1523e4 add r2, r2, #2 */
/* @0x1523e8 addne r3, r3, r3, lsl #1 */
/* @0x1523ec ldr r7, [sp, #0x34] */
/* @0x1523f0 moveq r10, #3 */
/* @0x1523f4 addne r3, r3, r3, lsr #31 */
/* @0x1523f8 asrne r10, r3, #1 */
/* @0x1523fc cmp r2, r10 */
/* @0x152400 addgt r2, r2, r2, lsl #1 */
/* @0x152404 addgt r2, r2, r2, lsr #31 */
/* @0x152408 asrgt r10, r2, #1 */
/* @0x15240c mov r0, r10 */
/* @0x152410 bl 0xcef4c <_Z7YYAlloci> */
/* @0x152414 ldr r2, [sp, #0x38] */
/* @0x152418 mov r1, r7 */
/* @0x15241c str r0, [sp, #0x34] */
/* @0x152420 bl 0xb65bc <memcpy@plt> */
/* @0x152424 cmp r7, #0 */
/* @0x152428 str r10, [sp, #0x38] */
/* @0x15242c beq 0x152438 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x97c> */
/* @0x152430 mov r0, r7 */
/* @0x152434 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x152438 ldr r2, [sp, #0x3c] */
/* @0x15243c ldr r12, [sp, #0xc] */
/* @0x152440 mov r0, r6 */
/* @0x152444 ldr r3, [sp, #0x34] */
/* @0x152448 ldrh r1, [r12] */
/* @0x15244c strh r1, [r3, r2] */
/* @0x152450 ldr r3, [sp, #0x3c] */
/* @0x152454 ldr r1, [r4, #-0x4] */
/* @0x152458 add r3, r3, #1 */
/* @0x15245c str r3, [sp, #0x3c] */
/* @0x152460 bl 0xd58c4 <_ZN12YYStrBuilderlsEi> */
/* @0x152464 ldr r3, [sp, #0x3c] */
/* @0x152468 b 0x152140 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x684> */
/* @0x15246c ldr r1, [sp, #0x38] */
/* @0x152470 mvn r0, r3 */
/* @0x152474 add r0, r1, r0 */
/* @0x152478 cmp r0, #1 */
/* @0x15247c bgt 0x1524dc <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xa20> */
/* @0x152480 cmp r1, #0 */
/* @0x152484 add r2, r2, #3 */
/* @0x152488 addne r1, r1, r1, lsl #1 */
/* @0x15248c ldr r6, [sp, #0x34] */
/* @0x152490 moveq r7, #3 */
/* @0x152494 addne r1, r1, r1, lsr #31 */
/* @0x152498 asrne r7, r1, #1 */
/* @0x15249c cmp r2, r7 */
/* @0x1524a0 addgt r2, r2, r2, lsl #1 */
/* @0x1524a4 addgt r2, r2, r2, lsr #31 */
/* @0x1524a8 asrgt r7, r2, #1 */
/* @0x1524ac mov r0, r7 */
/* @0x1524b0 bl 0xcef4c <_Z7YYAlloci> */
/* @0x1524b4 ldr r2, [sp, #0x38] */
/* @0x1524b8 mov r1, r6 */
/* @0x1524bc str r0, [sp, #0x34] */
/* @0x1524c0 bl 0xb65bc <memcpy@plt> */
/* @0x1524c4 cmp r6, #0 */
/* @0x1524c8 str r7, [sp, #0x38] */
/* @0x1524cc beq 0x1524d8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xa1c> */
/* @0x1524d0 mov r0, r6 */
/* @0x1524d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1524d8 ldr r3, [sp, #0x3c] */
/* @0x1524dc ldr r2, [sp, #0x34] */
/* @0x1524e0 add r0, sp, #52 */
/* @0x1524e4 ldr r12, [sp, #0x4] */
/* @0x1524e8 b 0x152308 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x84c> */
/* @0x1524ec cmp r0, #5 */
/* @0x1524f0 bgt 0x152550 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xa94> */
/* @0x1524f4 cmp r2, #0 */
/* @0x1524f8 add r1, r1, #15 */
/* @0x1524fc addne r2, r2, r2, lsl #1 */
/* @0x152500 ldr r4, [sp, #0x34] */
/* @0x152504 moveq r5, #9 */
/* @0x152508 addne r2, r2, r2, lsr #31 */
/* @0x15250c asrne r5, r2, #1 */
/* @0x152510 cmp r1, r5 */
/* @0x152514 addgt r1, r1, r1, lsl #1 */
/* @0x152518 addgt r1, r1, r1, lsr #31 */
/* @0x15251c asrgt r5, r1, #1 */
/* @0x152520 mov r0, r5 */
/* @0x152524 bl 0xcef4c <_Z7YYAlloci> */
/* @0x152528 ldr r2, [sp, #0x38] */
/* @0x15252c mov r1, r4 */
/* @0x152530 str r0, [sp, #0x34] */
/* @0x152534 bl 0xb65bc <memcpy@plt> */
/* @0x152538 cmp r4, #0 */
/* @0x15253c str r5, [sp, #0x38] */
/* @0x152540 beq 0x15254c <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xa90> */
/* @0x152544 mov r0, r4 */
/* @0x152548 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x15254c ldr r3, [sp, #0x3c] */
/* @0x152550 ldr r12, [sp, #0x20] */
/* @0x152554 ldr r2, [sp, #0x34] */
/* @0x152558 ldr r0, [r12] */
/* @0x15255c add r1, r2, r3 */
/* @0x152560 ldrh r12, [r12, #4] */
/* @0x152564 str r0, [r2, r3] */
/* @0x152568 strh r12, [r1, #4] */
/* @0x15256c ldr r3, [sp, #0x3c] */
/* @0x152570 add r3, r3, #5 */
/* @0x152574 str r3, [sp, #0x3c] */
/* @0x152578 b 0x151eec <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x430> */
/* @0x15257c ldr r2, [sp, #0x38] */
/* @0x152580 mvn r0, r3 */
/* @0x152584 add r0, r2, r0 */
/* @0x152588 cmp r0, #8 */
/* @0x15258c bgt 0x1525ec <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb30> */
/* @0x152590 cmp r2, #0 */
/* @0x152594 add r1, r1, #18 */
/* @0x152598 addne r2, r2, r2, lsl #1 */
/* @0x15259c ldr r4, [sp, #0x34] */
/* @0x1525a0 moveq r5, #13 */
/* @0x1525a4 addne r2, r2, r2, lsr #31 */
/* @0x1525a8 asrne r5, r2, #1 */
/* @0x1525ac cmp r1, r5 */
/* @0x1525b0 addgt r1, r1, r1, lsl #1 */
/* @0x1525b4 addgt r1, r1, r1, lsr #31 */
/* @0x1525b8 asrgt r5, r1, #1 */
/* @0x1525bc mov r0, r5 */
/* @0x1525c0 bl 0xcef4c <_Z7YYAlloci> */
/* @0x1525c4 ldr r2, [sp, #0x38] */
/* @0x1525c8 mov r1, r4 */
/* @0x1525cc str r0, [sp, #0x34] */
/* @0x1525d0 bl 0xb65bc <memcpy@plt> */
/* @0x1525d4 cmp r4, #0 */
/* @0x1525d8 str r5, [sp, #0x38] */
/* @0x1525dc beq 0x1525e8 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb2c> */
/* @0x1525e0 mov r0, r4 */
/* @0x1525e4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1525e8 ldr r3, [sp, #0x3c] */
/* @0x1525ec ldr r2, [sp, #0x24] */
/* @0x1525f0 ldr lr, [sp, #0x34] */
/* @0x1525f4 ldm r2!, {r0, r1} */
/* @0x1525f8 add r12, lr, r3 */
/* @0x1525fc ldrb r2, [r2] */
/* @0x152600 str r0, [lr, r3] */
/* @0x152604 str r1, [r12, #0x4] */
/* @0x152608 strb r2, [r12, #0x8] */
/* @0x15260c ldr r3, [sp, #0x3c] */
/* @0x152610 add r3, r3, #8 */
/* @0x152614 str r3, [sp, #0x3c] */
/* @0x152618 b 0x151eec <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0x430> */
/* @0x15261c cmp r7, #0 */
/* @0x152620 beq 0x152650 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb94> */
/* @0x152624 ldr r1, [sp, #0x34] */
/* @0x152628 ldr r0, [sp, #0x2c] */
/* @0x15262c mov r3, #0 */
/* @0x152630 str r3, [sp, #0x3c] */
/* @0x152634 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x152638 ldr r0, [sp, #0x34] */
/* @0x15263c cmp r0, #0 */
/* @0x152640 beq 0x152648 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb8c> */
/* @0x152644 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x152648 add sp, sp, #68 */
/* @0x15264c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x152650 add r1, sp, #60 */
/* @0x152654 b 0x152628 <_Z20F_GamepadGetDatabaseR6RValueP9CInstanceS2_iPS_+0xb6c> */
/* @0x152658 eoreq sp, r9, r4, lsr #31 */
/* @0x15265c andseq r0, lr, r8, lsr #20 */
/* @0x152660 andseq r4, pc, r8, asr #1 */
/* @0x152664 ldrsbeq r4, [pc], -r0 */
/* @0x152668 ldrsbeq r4, [pc], -r0 */
/* @0x15266c andseq r4, pc, r12, lsr #1 */
/* @0x152670 ldrheq r0, [lr], -r12 */
/* @0x152674 andseq r0, lr, r4, lsl sp */
/* @0x152678 andseq r3, pc, r0, ror r12 */
/* @0x15267c mulseq lr, r0, r5 */
/* @0x152680 andseq r3, pc, r12, asr r12 */
/* @0x152684 andseq lr, lr, r4, lsl #7 */
/* @0x152688 andseq r3, pc, r8, lsr r12 */
/* @0x15268c eoreq sp, r9, r12, ror r10 */
/* @0x152690 andseq r0, lr, r4, asr #20 */

/* ── FUNC 0x152694 · SGamepadEntry::FromString(char const*) · size=152 · insn=38 */
/* @0x152694 push {r3, r4, r5, lr} */
/* @0x152698 mov r4, r1 */
/* @0x15269c mov r5, r0 */
/* @0x1526a0 add r0, r1, #1 */
/* @0x1526a4 bl 0xb66b8 <atoi@plt> */
/* @0x1526a8 ldrb r3, [r4] */
/* @0x1526ac cmp r3, #98 */
/* @0x1526b0 beq 0x152714 <_ZN13SGamepadEntry10FromStringEPKc+0x80> */
/* @0x1526b4 cmp r3, #104 */
/* @0x1526b8 beq 0x1526f8 <_ZN13SGamepadEntry10FromStringEPKc+0x64> */
/* @0x1526bc cmp r3, #97 */
/* @0x1526c0 streq r0, [r5, #0x4] */
/* @0x1526c4 moveq r3, #1 */
/* @0x1526c8 streq r3, [r5] */
/* @0x1526cc popeq {r3, r4, r5, pc} */
/* @0x1526d0 ldr r3, [pc, #0x4c] */
/* @0x1526d4 mov r2, r4 */
/* @0x1526d8 ldr r1, [pc, #0x48] */
/* @0x1526dc ldr r3, [pc, r3] */
/* @0x1526e0 add r1, pc, r1 */
/* @0x1526e4 ldr r0, [r3] */
/* @0x1526e8 ldr r3, [r0] */
/* @0x1526ec ldr r3, [r3, #0xc] */
/* @0x1526f0 blx r3 */
/* @0x1526f4 pop {r3, r4, r5, pc} */
/* @0x1526f8 str r0, [r5, #0x4] */
/* @0x1526fc mov r3, #3 */
/* @0x152700 add r0, r4, #3 */
/* @0x152704 str r3, [r5] */
/* @0x152708 bl 0xb66b8 <atoi@plt> */
/* @0x15270c str r0, [r5, #0x8] */
/* @0x152710 pop {r3, r4, r5, pc} */
/* @0x152714 mov r3, #2 */
/* @0x152718 str r0, [r5, #0x4] */
/* @0x15271c str r3, [r5] */
/* @0x152720 pop {r3, r4, r5, pc} */
/* @0x152724 eoreq r11, r9, r4, ror #4 */
/* @0x152728 andseq r3, pc, r4, lsr #10 */

/* ── FUNC 0x15272c · SGamepadMapping::SGamepadMapping(char const*, char const*) · size=100 · insn=25 */
/* @0x15272c push {r4, r5, r6, lr} */
/* @0x152730 mov r4, r0 */
/* @0x152734 mov r5, #0 */
/* @0x152738 mov r0, r1 */
/* @0x15273c str r5, [r4] */
/* @0x152740 mov r6, r2 */
/* @0x152744 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x152748 str r0, [r4, #0x4] */
/* @0x15274c mov r0, r6 */
/* @0x152750 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x152754 mvn r6, #0 */
/* @0x152758 add r3, r4, #28 */
/* @0x15275c add r12, r4, #280 */
/* @0x152760 mov r1, r5 */
/* @0x152764 mov r2, r6 */
/* @0x152768 str r6, [r4, #0xc] */
/* @0x15276c str r0, [r4, #0x8] */
/* @0x152770 str r1, [r3, #-0xc] */
/* @0x152774 add r3, r3, #12 */
/* @0x152778 str r2, [r3, #-0x14] */
/* @0x15277c str r2, [r3, #-0x10] */
/* @0x152780 cmp r3, r12 */
/* @0x152784 bne 0x152770 <_ZN15SGamepadMappingC2EPKcS1_+0x44> */
/* @0x152788 mov r0, r4 */
/* @0x15278c pop {r4, r5, r6, pc} */

/* ── FUNC 0x15272c · SGamepadMapping::SGamepadMapping(char const*, char const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x152790 · SGamepadMapping::CreateFromString(char const*) · size=512 · insn=128 */
/* @0x152790 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x152794 sub sp, sp, #28 */
/* @0x152798 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x15279c mov r1, #44 */
/* @0x1527a0 str r0, [sp, #0x10] */
/* @0x1527a4 bl 0xb6634 <strchr@plt> */
/* @0x1527a8 subs r5, r0, #0 */
/* @0x1527ac beq 0x152970 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x1e0> */
/* @0x1527b0 add r6, r5, #1 */
/* @0x1527b4 mov r1, #44 */
/* @0x1527b8 mov r0, r6 */
/* @0x1527bc bl 0xb6634 <strchr@plt> */
/* @0x1527c0 cmp r0, #0 */
/* @0x1527c4 beq 0x152958 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x1c8> */
/* @0x1527c8 mov r4, r0 */
/* @0x1527cc mov r7, #0 */
/* @0x1527d0 mov r0, #268 */
/* @0x1527d4 strb r7, [r5] */
/* @0x1527d8 strb r7, [r4], #1 */
/* @0x1527dc bl 0x27c524 <_Znwj> */
/* @0x1527e0 ldr r1, [sp, #0x10] */
/* @0x1527e4 mov r2, r6 */
/* @0x1527e8 ldr r9, [pc, #0x188] */
/* @0x1527ec add r9, pc, r9 */
/* @0x1527f0 str r0, [sp, #0x4] */
/* @0x1527f4 bl 0x15272c <_ZN15SGamepadMappingC2EPKcS1_> */
/* @0x1527f8 ldr r3, [pc, #0x17c] */
/* @0x1527fc ldr r2, [pc, #0x17c] */
/* @0x152800 ldr r3, [pc, r3] */
/* @0x152804 ldr r1, [pc, #0x178] */
/* @0x152808 add r2, pc, r2 */
/* @0x15280c str r2, [sp, #0x8] */
/* @0x152810 ldr r2, [pc, #0x170] */
/* @0x152814 add r1, pc, r1 */
/* @0x152818 str r1, [sp, #0x14] */
/* @0x15281c add r2, pc, r2 */
/* @0x152820 ldr r1, [sp, #0x4] */
/* @0x152824 str r2, [sp, #0xc] */
/* @0x152828 ldr r2, [r3] */
/* @0x15282c str r2, [r1] */
/* @0x152830 str r1, [r3] */
/* @0x152834 b 0x152890 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x100> */
/* @0x152838 mov r0, r5 */
/* @0x15283c ldr r1, [sp, #0x8] */
/* @0x152840 bl 0xb66d0 <strcasecmp@plt> */
/* @0x152844 cmp r0, #0 */
/* @0x152848 beq 0x15287c <_ZN15SGamepadMapping16CreateFromStringEPKc+0xec> */
/* @0x15284c mov r0, r5 */
/* @0x152850 ldr r1, [sp, #0xc] */
/* @0x152854 bl 0xb66d0 <strcasecmp@plt> */
/* @0x152858 cmp r0, #0 */
/* @0x15285c moveq r0, #1 */
/* @0x152860 beq 0x15287c <_ZN15SGamepadMapping16CreateFromStringEPKc+0xec> */
/* @0x152864 mov r0, r5 */
/* @0x152868 ldr r1, [sp, #0x14] */
/* @0x15286c bl 0xb66d0 <strcasecmp@plt> */
/* @0x152870 cmp r0, #0 */
/* @0x152874 moveq r0, #6 */
/* @0x152878 movne r0, #0 */
/* @0x15287c ldr r3, [sp, #0x4] */
/* @0x152880 str r0, [r3, #0xc] */
/* @0x152884 cmp r8, #0 */
/* @0x152888 add r4, r6, #1 */
/* @0x15288c bne 0x15295c <_ZN15SGamepadMapping16CreateFromStringEPKc+0x1cc> */
/* @0x152890 mov r0, r4 */
/* @0x152894 mov r1, #44 */
/* @0x152898 bl 0xb6634 <strchr@plt> */
/* @0x15289c subs r6, r0, #0 */
/* @0x1528a0 movne r8, #0 */
/* @0x1528a4 beq 0x152944 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x1b4> */
/* @0x1528a8 strb r7, [r6] */
/* @0x1528ac mov r0, r4 */
/* @0x1528b0 mov r1, #58 */
/* @0x1528b4 bl 0xb6634 <strchr@plt> */
/* @0x1528b8 subs r10, r0, #0 */
/* @0x1528bc beq 0x15295c <_ZN15SGamepadMapping16CreateFromStringEPKc+0x1cc> */
/* @0x1528c0 mov r5, r10 */
/* @0x1528c4 mov r0, r4 */
/* @0x1528c8 strb r7, [r5], #1 */
/* @0x1528cc mov r1, r9 */
/* @0x1528d0 bl 0xb66d0 <strcasecmp@plt> */
/* @0x1528d4 cmp r0, #0 */
/* @0x1528d8 beq 0x152838 <_ZN15SGamepadMapping16CreateFromStringEPKc+0xa8> */
/* @0x1528dc ldrb r3, [r10, #0x1] */
/* @0x1528e0 cmp r3, #0 */
/* @0x1528e4 beq 0x152884 <_ZN15SGamepadMapping16CreateFromStringEPKc+0xf4> */
/* @0x1528e8 ldr r3, [pc, #0x9c] */
/* @0x1528ec ldr r3, [pc, r3] */
/* @0x1528f0 ldr r10, [r3, #0x4] */
/* @0x1528f4 cmp r10, #21 */
/* @0x1528f8 beq 0x152884 <_ZN15SGamepadMapping16CreateFromStringEPKc+0xf4> */
/* @0x1528fc add r11, r3, #8 */
/* @0x152900 b 0x152910 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x180> */
/* @0x152904 ldr r10, [r11, #-0x4] */
/* @0x152908 cmp r10, #21 */
/* @0x15290c beq 0x152884 <_ZN15SGamepadMapping16CreateFromStringEPKc+0xf4> */
/* @0x152910 ldr r1, [r11, #-0x8] */
/* @0x152914 mov r0, r4 */
/* @0x152918 bl 0xb66d0 <strcasecmp@plt> */
/* @0x15291c add r11, r11, #8 */
/* @0x152920 cmp r0, #0 */
/* @0x152924 bne 0x152904 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x174> */
/* @0x152928 add r2, r10, r10, lsl #1 */
/* @0x15292c ldr r3, [sp, #0x4] */
/* @0x152930 mov r1, r5 */
/* @0x152934 add r0, r3, r2, lsl #2 */
/* @0x152938 add r0, r0, #16 */
/* @0x15293c bl 0x152694 <_ZN13SGamepadEntry10FromStringEPKc> */
/* @0x152940 b 0x152884 <_ZN15SGamepadMapping16CreateFromStringEPKc+0xf4> */
/* @0x152944 mov r0, r4 */
/* @0x152948 mov r8, #1 */
/* @0x15294c bl 0xb6538 <strlen@plt> */
/* @0x152950 add r6, r4, r0 */
/* @0x152954 b 0x1528a8 <_ZN15SGamepadMapping16CreateFromStringEPKc+0x118> */
/* @0x152958 str r0, [sp, #0x4] */
/* @0x15295c ldr r0, [sp, #0x10] */
/* @0x152960 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x152964 ldr r0, [sp, #0x4] */
/* @0x152968 add sp, sp, #28 */
/* @0x15296c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x152970 str r5, [sp, #0x4] */
/* @0x152974 b 0x15295c <_ZN15SGamepadMapping16CreateFromStringEPKc+0x1cc> */
/* @0x152978 andseq r3, pc, r4, asr #8 */
/* @0x15297c eoreq sp, r9, r8, ror #4 */
/* @0x152980 andseq r3, pc, r4, lsr r4 */
/* @0x152984 ldrsbeq r3, [pc], -r12 */
/* @0x152988 andseq r3, pc, r8, lsr #8 */
/* @0x15298c eoreq sp, r9, r0, lsl #3 */

/* ── FUNC 0x152990 · F_GamepadAddMappingFromString(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x152990 push {r4, lr} */
/* @0x152994 mov r1, #0 */
/* @0x152998 ldr r0, [sp, #0x8] */
/* @0x15299c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1529a0 mov r4, r0 */
/* @0x1529a4 bl 0x152790 <_ZN15SGamepadMapping16CreateFromStringEPKc> */
/* @0x1529a8 cmp r0, #0 */
/* @0x1529ac popne {r4, pc} */
/* @0x1529b0 ldr r3, [pc, #0x20] */
/* @0x1529b4 mov r2, r4 */
/* @0x1529b8 ldr r1, [pc, #0x1c] */
/* @0x1529bc ldr r3, [pc, r3] */
/* @0x1529c0 add r1, pc, r1 */
/* @0x1529c4 ldr r0, [r3] */
/* @0x1529c8 ldr r3, [r0] */
/* @0x1529cc ldr r3, [r3, #0xc] */
/* @0x1529d0 blx r3 */
/* @0x1529d4 pop {r4, pc} */
/* @0x1529d8 eoreq r10, r9, r4, lsl #31 */
/* @0x1529dc mulseq pc, r0, r2 */

/* ── FUNC 0x1529e0 · SGamepadMapping::CreateFromFileAsString(unsigned char*, int) · size=308 · insn=77 */
/* @0x1529e0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1529e4 subs r4, r0, #0 */
/* @0x1529e8 mov r5, r1 */
/* @0x1529ec moveq r6, r4 */
/* @0x1529f0 beq 0x152aa4 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xc4> */
/* @0x1529f4 mov r0, r1 */
/* @0x1529f8 ldr r7, [pc, #0x10c] */
/* @0x1529fc bl 0xcef4c <_Z7YYAlloci> */
/* @0x152a00 mov r1, r4 */
/* @0x152a04 mov r2, r5 */
/* @0x152a08 mov r6, #0 */
/* @0x152a0c mov r9, r6 */
/* @0x152a10 add r7, pc, r7 */
/* @0x152a14 mov r8, r0 */
/* @0x152a18 bl 0xb65bc <memcpy@plt> */
/* @0x152a1c mov r10, r8 */
/* @0x152a20 rsb r3, r8, r10 */
/* @0x152a24 cmp r5, r3 */
/* @0x152a28 ble 0x152a9c <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xbc> */
/* @0x152a2c ldrb r2, [r10] */
/* @0x152a30 cmp r2, #13 */
/* @0x152a34 beq 0x152aac <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xcc> */
/* @0x152a38 cmp r2, #10 */
/* @0x152a3c beq 0x152aac <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xcc> */
/* @0x152a40 add r3, r10, #1 */
/* @0x152a44 b 0x152a5c <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0x7c> */
/* @0x152a48 ldrb r12, [r3], #1 */
/* @0x152a4c cmp r12, #13 */
/* @0x152a50 beq 0x152ab0 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xd0> */
/* @0x152a54 cmp r12, #10 */
/* @0x152a58 beq 0x152ab0 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xd0> */
/* @0x152a5c rsb r12, r8, r3 */
/* @0x152a60 mov r4, r3 */
/* @0x152a64 cmp r5, r12 */
/* @0x152a68 bgt 0x152a48 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0x68> */
/* @0x152a6c mov r3, r2 */
/* @0x152a70 cmp r3, #35 */
/* @0x152a74 beq 0x152a8c <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xac> */
/* @0x152a78 mov r0, r10 */
/* @0x152a7c bl 0x152790 <_ZN15SGamepadMapping16CreateFromStringEPKc> */
/* @0x152a80 cmp r0, #0 */
/* @0x152a84 addne r6, r6, #1 */
/* @0x152a88 beq 0x152ae8 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0x108> */
/* @0x152a8c mov r10, r4 */
/* @0x152a90 rsb r3, r8, r10 */
/* @0x152a94 cmp r5, r3 */
/* @0x152a98 bgt 0x152a2c <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0x4c> */
/* @0x152a9c mov r0, r8 */
/* @0x152aa0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x152aa4 mov r0, r6 */
/* @0x152aa8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x152aac mov r4, r10 */
/* @0x152ab0 add r3, r4, #1 */
/* @0x152ab4 rsb r2, r8, r3 */
/* @0x152ab8 mov r4, r3 */
/* @0x152abc cmp r5, r2 */
/* @0x152ac0 strb r9, [r3, #-0x1] */
/* @0x152ac4 bgt 0x152ad0 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xf0> */
/* @0x152ac8 ldrb r3, [r10] */
/* @0x152acc b 0x152a70 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0x90> */
/* @0x152ad0 ldrb r2, [r3] */
/* @0x152ad4 add r3, r4, #1 */
/* @0x152ad8 cmp r2, #13 */
/* @0x152adc cmpne r2, #10 */
/* @0x152ae0 beq 0x152ab4 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xd4> */
/* @0x152ae4 b 0x152ac8 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xe8> */
/* @0x152ae8 ldr r3, [pc, #0x20] */
/* @0x152aec mov r2, r10 */
/* @0x152af0 mov r1, r7 */
/* @0x152af4 ldr r3, [pc, r3] */
/* @0x152af8 ldr r0, [r3] */
/* @0x152afc ldr r3, [r0] */
/* @0x152b00 ldr r3, [r3, #0xc] */
/* @0x152b04 blx r3 */
/* @0x152b08 b 0x152a8c <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi+0xac> */
/* @0x152b0c andseq r3, pc, r0, asr #4 */
/* @0x152b10 eoreq r10, r9, r12, asr #28 */

/* ── FUNC 0x152b14 · SGamepadMapping::CreateFromFile(char const*) · size=124 · insn=31 */
/* @0x152b14 push {r4, r5, lr} */
/* @0x152b18 sub sp, sp, #12 */
/* @0x152b1c mov r3, #0 */
/* @0x152b20 mov r5, r0 */
/* @0x152b24 str r3, [sp, #0x4] */
/* @0x152b28 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x152b2c cmp r0, #0 */
/* @0x152b30 mov r0, r5 */
/* @0x152b34 bne 0x152b80 <_ZN15SGamepadMapping14CreateFromFileEPKc+0x6c> */
/* @0x152b38 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x152b3c cmp r0, #0 */
/* @0x152b40 moveq r4, r0 */
/* @0x152b44 bne 0x152b6c <_ZN15SGamepadMapping14CreateFromFileEPKc+0x58> */
/* @0x152b48 ldr r1, [sp, #0x4] */
/* @0x152b4c mov r0, r4 */
/* @0x152b50 bl 0x1529e0 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi> */
/* @0x152b54 mov r5, r0 */
/* @0x152b58 mov r0, r4 */
/* @0x152b5c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x152b60 mov r0, r5 */
/* @0x152b64 add sp, sp, #12 */
/* @0x152b68 pop {r4, r5, pc} */
/* @0x152b6c mov r0, r5 */
/* @0x152b70 add r1, sp, #4 */
/* @0x152b74 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x152b78 mov r4, r0 */
/* @0x152b7c b 0x152b48 <_ZN15SGamepadMapping14CreateFromFileEPKc+0x34> */
/* @0x152b80 add r1, sp, #4 */
/* @0x152b84 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0x152b88 mov r4, r0 */
/* @0x152b8c b 0x152b48 <_ZN15SGamepadMapping14CreateFromFileEPKc+0x34> */

/* ── FUNC 0x152b90 · F_GamepadAddMappingFromFile(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x152b90 push {r4, lr} */
/* @0x152b94 mov r1, #0 */
/* @0x152b98 mov r4, r0 */
/* @0x152b9c ldr r0, [sp, #0x8] */
/* @0x152ba0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x152ba4 bl 0x152b14 <_ZN15SGamepadMapping14CreateFromFileEPKc> */
/* @0x152ba8 mov r3, #0 */
/* @0x152bac str r3, [r4, #0xc] */
/* @0x152bb0 vmov s15, r0 */
/* @0x152bb4 vcvt.f64.s32 d7, s15 */
/* @0x152bb8 vmov r0, r1, d7 */
/* @0x152bbc vmov r2, s14 */
/* @0x152bc0 mov r3, r1 */
/* @0x152bc4 stm r4, {r2, r3} */
/* @0x152bc8 pop {r4, pc} */

/* ── FUNC 0x152bcc · SGamepadMapping::FindFromGUID(unsigned char const*) · size=208 · insn=52 */
/* @0x152bcc push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x152bd0 sub sp, sp, #44 */
/* @0x152bd4 ldr r8, [pc, #0xb4] */
/* @0x152bd8 sub r5, r0, #1 */
/* @0x152bdc ldr r9, [pc, #0xb0] */
/* @0x152be0 add r6, sp, #32 */
/* @0x152be4 ldr r8, [pc, r8] */
/* @0x152be8 mov r4, sp */
/* @0x152bec add r9, pc, r9 */
/* @0x152bf0 ldr r3, [r8] */
/* @0x152bf4 str r3, [sp, #0x24] */
/* @0x152bf8 mov r0, r4 */
/* @0x152bfc mov r1, r9 */
/* @0x152c00 add r4, r4, #2 */
/* @0x152c04 ldrb r2, [r5, #0x1]! */
/* @0x152c08 bl 0xb6550 <sprintf@plt> */
/* @0x152c0c cmp r4, r6 */
/* @0x152c10 bne 0x152bf8 <_ZN15SGamepadMapping12FindFromGUIDEPKh+0x2c> */
/* @0x152c14 mov r3, #0 */
/* @0x152c18 strb r3, [sp, #0x20] */
/* @0x152c1c bl 0x159cf4 <_Z23YoYo_GetPlatform_DoWorkv> */
/* @0x152c20 ldr r3, [pc, #0x70] */
/* @0x152c24 ldr r3, [pc, r3] */
/* @0x152c28 ldr r4, [r3] */
/* @0x152c2c cmp r4, #0 */
/* @0x152c30 vmov d7, r0, r1 */
/* @0x152c34 vcvt.s32.f64 s15, d7 */
/* @0x152c38 vmov r5, s15 */
/* @0x152c3c bne 0x152c50 <_ZN15SGamepadMapping12FindFromGUIDEPKh+0x84> */
/* @0x152c40 b 0x152c70 <_ZN15SGamepadMapping12FindFromGUIDEPKh+0xa4> */
/* @0x152c44 ldr r4, [r4] */
/* @0x152c48 cmp r4, #0 */
/* @0x152c4c beq 0x152c70 <_ZN15SGamepadMapping12FindFromGUIDEPKh+0xa4> */
/* @0x152c50 ldr r3, [r4, #0xc] */
/* @0x152c54 cmp r3, r5 */
/* @0x152c58 bne 0x152c44 <_ZN15SGamepadMapping12FindFromGUIDEPKh+0x78> */
/* @0x152c5c ldr r0, [r4, #0x4] */
/* @0x152c60 mov r1, sp */
/* @0x152c64 bl 0xb66d0 <strcasecmp@plt> */
/* @0x152c68 cmp r0, #0 */
/* @0x152c6c bne 0x152c44 <_ZN15SGamepadMapping12FindFromGUIDEPKh+0x78> */
/* @0x152c70 ldr r2, [sp, #0x24] */
/* @0x152c74 mov r0, r4 */
/* @0x152c78 ldr r3, [r8] */
/* @0x152c7c cmp r2, r3 */
/* @0x152c80 bne 0x152c8c <_ZN15SGamepadMapping12FindFromGUIDEPKh+0xc0> */
/* @0x152c84 add sp, sp, #44 */
/* @0x152c88 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x152c8c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x152c90 eoreq r10, r9, r12, ror #26 */
/* @0x152c94 ldrheq pc, [sp], -r8 */
/* @0x152c98 eoreq r12, r9, r4, asr #28 */

/* ── FUNC 0x152c9c · InitGamepadFunctions() · size=856 · insn=214 */
/* @0x152c9c push {r3, r4, r5, lr} */
/* @0x152ca0 mov r2, #0 */
/* @0x152ca4 ldr r4, [pc, #0x294] */
/* @0x152ca8 mov r3, #1 */
/* @0x152cac ldr r1, [pc, #0x290] */
/* @0x152cb0 add r4, pc, r4 */
/* @0x152cb4 ldr r0, [pc, #0x28c] */
/* @0x152cb8 ldr r1, [r4, r1] */
/* @0x152cbc add r0, pc, r0 */
/* @0x152cc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152cc4 ldr r1, [pc, #0x280] */
/* @0x152cc8 ldr r0, [pc, #0x280] */
/* @0x152ccc mov r2, #0 */
/* @0x152cd0 mov r3, #1 */
/* @0x152cd4 ldr r1, [r4, r1] */
/* @0x152cd8 add r0, pc, r0 */
/* @0x152cdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152ce0 ldr r1, [pc, #0x26c] */
/* @0x152ce4 ldr r0, [pc, #0x26c] */
/* @0x152ce8 mov r2, #1 */
/* @0x152cec mov r3, r2 */
/* @0x152cf0 ldr r1, [r4, r1] */
/* @0x152cf4 add r0, pc, r0 */
/* @0x152cf8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152cfc ldr r1, [pc, #0x258] */
/* @0x152d00 ldr r0, [pc, #0x258] */
/* @0x152d04 mov r2, #1 */
/* @0x152d08 mov r3, r2 */
/* @0x152d0c ldr r1, [r4, r1] */
/* @0x152d10 add r0, pc, r0 */
/* @0x152d14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152d18 ldr r1, [pc, #0x244] */
/* @0x152d1c ldr r0, [pc, #0x244] */
/* @0x152d20 mov r2, #1 */
/* @0x152d24 mov r3, r2 */
/* @0x152d28 ldr r1, [r4, r1] */
/* @0x152d2c add r0, pc, r0 */
/* @0x152d30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152d34 ldr r1, [pc, #0x230] */
/* @0x152d38 ldr r0, [pc, #0x230] */
/* @0x152d3c mov r2, #2 */
/* @0x152d40 mov r3, #1 */
/* @0x152d44 ldr r1, [r4, r1] */
/* @0x152d48 add r0, pc, r0 */
/* @0x152d4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152d50 ldr r1, [pc, #0x21c] */
/* @0x152d54 ldr r0, [pc, #0x21c] */
/* @0x152d58 mov r2, #1 */
/* @0x152d5c mov r3, r2 */
/* @0x152d60 ldr r1, [r4, r1] */
/* @0x152d64 add r0, pc, r0 */
/* @0x152d68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152d6c ldr r1, [pc, #0x208] */
/* @0x152d70 ldr r0, [pc, #0x208] */
/* @0x152d74 mov r2, #2 */
/* @0x152d78 mov r3, #1 */
/* @0x152d7c ldr r1, [r4, r1] */
/* @0x152d80 add r0, pc, r0 */
/* @0x152d84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152d88 ldr r1, [pc, #0x1f4] */
/* @0x152d8c ldr r0, [pc, #0x1f4] */
/* @0x152d90 mov r2, #1 */
/* @0x152d94 mov r3, r2 */
/* @0x152d98 ldr r1, [r4, r1] */
/* @0x152d9c add r0, pc, r0 */
/* @0x152da0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152da4 ldr r1, [pc, #0x1e0] */
/* @0x152da8 ldr r0, [pc, #0x1e0] */
/* @0x152dac mov r2, #2 */
/* @0x152db0 mov r3, #1 */
/* @0x152db4 ldr r1, [r4, r1] */
/* @0x152db8 add r0, pc, r0 */
/* @0x152dbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152dc0 ldr r1, [pc, #0x1cc] */
/* @0x152dc4 ldr r0, [pc, #0x1cc] */
/* @0x152dc8 mov r2, #2 */
/* @0x152dcc mov r3, #1 */
/* @0x152dd0 ldr r1, [r4, r1] */
/* @0x152dd4 add r0, pc, r0 */
/* @0x152dd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152ddc ldr r1, [pc, #0x1b8] */
/* @0x152de0 ldr r0, [pc, #0x1b8] */
/* @0x152de4 mov r2, #2 */
/* @0x152de8 mov r3, #1 */
/* @0x152dec ldr r1, [r4, r1] */
/* @0x152df0 add r0, pc, r0 */
/* @0x152df4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152df8 ldr r1, [pc, #0x1a4] */
/* @0x152dfc ldr r0, [pc, #0x1a4] */
/* @0x152e00 mov r2, #2 */
/* @0x152e04 mov r3, #1 */
/* @0x152e08 ldr r1, [r4, r1] */
/* @0x152e0c add r0, pc, r0 */
/* @0x152e10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152e14 ldr r1, [pc, #0x190] */
/* @0x152e18 ldr r0, [pc, #0x190] */
/* @0x152e1c mov r2, #1 */
/* @0x152e20 mov r3, r2 */
/* @0x152e24 ldr r1, [r4, r1] */
/* @0x152e28 add r0, pc, r0 */
/* @0x152e2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152e30 ldr r1, [pc, #0x17c] */
/* @0x152e34 ldr r0, [pc, #0x17c] */
/* @0x152e38 mov r2, #2 */
/* @0x152e3c mov r3, #1 */
/* @0x152e40 ldr r1, [r4, r1] */
/* @0x152e44 add r0, pc, r0 */
/* @0x152e48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152e4c ldr r1, [pc, #0x168] */
/* @0x152e50 ldr r0, [pc, #0x168] */
/* @0x152e54 mov r2, #3 */
/* @0x152e58 mov r3, #1 */
/* @0x152e5c ldr r1, [r4, r1] */
/* @0x152e60 add r0, pc, r0 */
/* @0x152e64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152e68 ldr r1, [pc, #0x154] */
/* @0x152e6c ldr r0, [pc, #0x154] */
/* @0x152e70 mov r2, #1 */
/* @0x152e74 mov r3, r2 */
/* @0x152e78 ldr r1, [r4, r1] */
/* @0x152e7c add r0, pc, r0 */
/* @0x152e80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152e84 ldr r1, [pc, #0x140] */
/* @0x152e88 ldr r0, [pc, #0x140] */
/* @0x152e8c mov r2, #1 */
/* @0x152e90 mov r3, r2 */
/* @0x152e94 ldr r1, [r4, r1] */
/* @0x152e98 add r0, pc, r0 */
/* @0x152e9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152ea0 ldr r1, [pc, #0x12c] */
/* @0x152ea4 ldr r0, [pc, #0x12c] */
/* @0x152ea8 mov r2, #0 */
/* @0x152eac mov r3, #1 */
/* @0x152eb0 ldr r1, [r4, r1] */
/* @0x152eb4 add r0, pc, r0 */
/* @0x152eb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152ebc ldr r1, [pc, #0x118] */
/* @0x152ec0 ldr r0, [pc, #0x118] */
/* @0x152ec4 mov r2, #2 */
/* @0x152ec8 mov r3, #1 */
/* @0x152ecc ldr r5, [r4, r1] */
/* @0x152ed0 add r0, pc, r0 */
/* @0x152ed4 mov r1, r5 */
/* @0x152ed8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152edc ldr r0, [pc, #0x100] */
/* @0x152ee0 mov r2, #2 */
/* @0x152ee4 mov r1, r5 */
/* @0x152ee8 add r0, pc, r0 */
/* @0x152eec mov r3, #1 */
/* @0x152ef0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x152ef4 ldr r3, [pc, #0xec] */
/* @0x152ef8 ldr r3, [r4, r3] */
/* @0x152efc ldr r4, [r3] */
/* @0x152f00 mov r0, r4 */
/* @0x152f04 bl 0xb6538 <strlen@plt> */
/* @0x152f08 mov r1, r0 */
/* @0x152f0c mov r0, r4 */
/* @0x152f10 bl 0x1529e0 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi> */
/* @0x152f14 ldr r0, [pc, #0xd0] */
/* @0x152f18 add r0, pc, r0 */
/* @0x152f1c bl 0x152b14 <_ZN15SGamepadMapping14CreateFromFileEPKc> */
/* @0x152f20 ldr r0, [pc, #0xc8] */
/* @0x152f24 add r0, pc, r0 */
/* @0x152f28 bl 0x215284 <_Z22EnvironmentGetVariablePc> */
/* @0x152f2c cmp r0, #0 */
/* @0x152f30 beq 0x152f38 <_Z20InitGamepadFunctionsv+0x29c> */
/* @0x152f34 bl 0x152790 <_ZN15SGamepadMapping16CreateFromStringEPKc> */
/* @0x152f38 pop {r3, r4, r5, lr} */
/* @0x152f3c b 0x190014 <_Z12GamepadInitMv> */
/* @0x152f40 eoreq lr, r9, r0, lsr #31 */
/* @0x152f44 .word 0xffffde20 */
/* @0x152f48 ldrheq r2, [pc], -r12 */
/* @0x152f4c .word 0xffffde24 */
/* @0x152f50 ldrheq r2, [pc], -r8 */
/* @0x152f54 .word 0xffffde28 */
/* @0x152f58 ldrheq r2, [pc], -r8 */
/* @0x152f5c .word 0xffffde2c */
/* @0x152f60 ldrheq r2, [pc], -r4 */
/* @0x152f64 .word 0xffffde30 */
/* @0x152f68 ldrheq r2, [pc], -r0 */
/* @0x152f6c .word 0xffffde34 */
/* @0x152f70 ldrheq r2, [pc], -r4 */
/* @0x152f74 .word 0xffffde38 */
/* @0x152f78 ldrheq r2, [pc], -r8 */
/* @0x152f7c .word 0xffffde3c */
/* @0x152f80 ldrheq r2, [pc], -r8 */
/* @0x152f84 .word 0xffffde40 */
/* @0x152f88 ldrheq r2, [pc], -r8 */
/* @0x152f8c .word 0xffffde44 */
/* @0x152f90 ldrheq r2, [pc], -r4 */
/* @0x152f94 .word 0xffffde48 */
/* @0x152f98 ldrheq r2, [pc], -r0 */
/* @0x152f9c .word 0xffffde4c */
/* @0x152fa0 ldrheq r2, [pc], -r4 */
/* @0x152fa4 .word 0xffffde50 */
/* @0x152fa8 ldrheq r2, [pc], -r8 */
/* @0x152fac .word 0xffffde54 */
/* @0x152fb0 ldrheq r2, [pc], -r4 */
/* @0x152fb4 .word 0xffffde58 */
/* @0x152fb8 andseq r2, pc, r12, lsr #31 */
/* @0x152fbc .word 0xffffde5c */
/* @0x152fc0 andseq r2, pc, r4, lsr #31 */
/* @0x152fc4 .word 0xffffde60 */
/* @0x152fc8 andseq r2, pc, r0, lsr #31 */
/* @0x152fcc .word 0xffffde64 */
/* @0x152fd0 ldrheq r2, [pc], -r0 */
/* @0x152fd4 .word 0xffffde68 */
/* @0x152fd8 ldrheq r2, [pc], -r12 */
/* @0x152fdc .word 0xffffde6c */
/* @0x152fe0 andseq r2, pc, r0, asr #31 */
/* @0x152fe4 ldrheq r2, [pc], -r12 */
/* @0x152fe8 .word 0xffffde70 */
/* @0x152fec andseq r2, pc, r0, lsr #31 */
/* @0x152ff0 andseq r2, pc, r12, lsr #31 */

/* ── FUNC 0x152ff4 · F_IAP_StoreState(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x152ff4 ldr r3, [pc, #0x20] */
/* @0x152ff8 mov r2, #0 */
/* @0x152ffc str r2, [r0, #0xc] */
/* @0x153000 ldr r3, [pc, r3] */
/* @0x153004 ldr r2, [r3] */
/* @0x153008 vmov s15, r2 */
/* @0x15300c vcvt.f64.s32 d7, s15 */
/* @0x153010 vmov r2, r3, d7 */
/* @0x153014 stm r0, {r2, r3} */
/* @0x153018 bx lr */
/* @0x15301c eoreq r12, r9, r4, asr #21 */

/* ── FUNC 0x153020 · anon_153020 · size=508 · insn=128 */
/* @0x153020 push {r3, r4, r5, r6, r7, lr} */
/* @0x153024 ldr r3, [pc, #0x110] */
/* @0x153028 ldr r2, [pc, #0x110] */
/* @0x15302c add r3, pc, r3 */
/* @0x153030 ldr r1, [r3, r2] */
/* @0x153034 ldr r2, [pc, #0x108] */
/* @0x153038 ldr r5, [r1] */
/* @0x15303c ldr r7, [r3, r2] */
/* @0x153040 cmp r5, #0 */
/* @0x153044 ble 0x15307c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x153048 ldr r3, [r7, #0x4] */
/* @0x15304c ldr r6, [r3] */
/* @0x153050 cmp r6, #0 */
/* @0x153054 movne r4, #0 */
/* @0x153058 bne 0x15306c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x15305c b 0x1530d4 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x153060 ldr r2, [r3, #0x4]! */
/* @0x153064 cmp r2, #0 */
/* @0x153068 beq 0x1530d8 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x15306c add r4, r4, #1 */
/* @0x153070 cmp r4, r5 */
/* @0x153074 lsl r6, r4, #2 */
/* @0x153078 bne 0x153060 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x15307c ldr r3, [r7] */
/* @0x153080 add r4, r5, #1 */
/* @0x153084 str r4, [r1] */
/* @0x153088 cmp r3, r5 */
/* @0x15308c ble 0x15311c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x153090 mov r0, #32 */
/* @0x153094 bl 0x27c524 <_Znwj> */
/* @0x153098 ldr r1, [r7, #0x4] */
/* @0x15309c mov r2, #0 */
/* @0x1530a0 mvn r12, #1 */
/* @0x1530a4 mov r3, r0 */
/* @0x1530a8 mov r0, r5 */
/* @0x1530ac str r12, [r3, #0x1c] */
/* @0x1530b0 str r2, [r3] */
/* @0x1530b4 str r2, [r3, #0x4] */
/* @0x1530b8 str r2, [r3, #0x8] */
/* @0x1530bc str r2, [r3, #0xc] */
/* @0x1530c0 str r2, [r3, #0x10] */
/* @0x1530c4 str r2, [r3, #0x18] */
/* @0x1530c8 str r2, [r3, #0x14] */
/* @0x1530cc str r3, [r1, r5, lsl #2] */
/* @0x1530d0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1530d4 mov r4, r6 */
/* @0x1530d8 mov r0, #32 */
/* @0x1530dc bl 0x27c524 <_Znwj> */
/* @0x1530e0 ldr r1, [r7, #0x4] */
/* @0x1530e4 mov r2, #0 */
/* @0x1530e8 mvn r12, #1 */
/* @0x1530ec mov r3, r0 */
/* @0x1530f0 mov r0, r4 */
/* @0x1530f4 str r12, [r3, #0x1c] */
/* @0x1530f8 str r2, [r3] */
/* @0x1530fc str r2, [r3, #0x4] */
/* @0x153100 str r2, [r3, #0x8] */
/* @0x153104 str r2, [r3, #0xc] */
/* @0x153108 str r2, [r3, #0x10] */
/* @0x15310c str r2, [r3, #0x18] */
/* @0x153110 str r2, [r3, #0x14] */
/* @0x153114 str r3, [r1, r6] */
/* @0x153118 pop {r3, r4, r5, r6, r7, pc} */
/* @0x15311c ldr r2, [pc, #0x24] */
/* @0x153120 add r0, r7, #4 */
/* @0x153124 lsl r1, r4, #2 */
/* @0x153128 mov r3, #190 */
/* @0x15312c add r2, pc, r2 */
/* @0x153130 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x153134 str r4, [r7] */
/* @0x153138 b 0x153090 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x15313c eoreq lr, r9, r4, lsr #24 */
/* @0x153140 .word 0xffffde78 */
/* @0x153144 .word 0xffffde7c */
/* @0x153148 andseq r2, pc, r0, lsl #29 */
/* @0x15314c ldr r3, [pc, #0x70] */
/* @0x153150 push {r4, r5, r6, r7, r8, lr} */
/* @0x153154 ldr r3, [pc, r3] */
/* @0x153158 mov r8, r0 */
/* @0x15315c ldr r7, [r3] */
/* @0x153160 cmp r7, #0 */
/* @0x153164 ble 0x1531b4 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1c0> */
/* @0x153168 ldr r3, [pc, #0x58] */
/* @0x15316c mov r5, #0 */
/* @0x153170 ldr r3, [pc, r3] */
/* @0x153174 ldr r6, [r3, #0x4] */
/* @0x153178 sub r6, r6, #4 */
/* @0x15317c ldr r4, [r6, #0x4]! */
/* @0x153180 mov r1, r8 */
/* @0x153184 cmp r4, #0 */
/* @0x153188 beq 0x1531a8 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x15318c ldr r0, [r4, #0x4] */
/* @0x153190 bl 0xb6574 <strcmp@plt> */
/* @0x153194 cmp r0, #0 */
/* @0x153198 bne 0x1531a8 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x15319c ldr r3, [r4, #0x1c] */
/* @0x1531a0 cmp r3, #0 */
/* @0x1531a4 beq 0x1531bc <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x1531a8 add r5, r5, #1 */
/* @0x1531ac cmp r5, r7 */
/* @0x1531b0 bne 0x15317c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x1531b4 mvn r0, #0 */
/* @0x1531b8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1531bc mov r0, r5 */
/* @0x1531c0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1531c4 eoreq r12, r9, r4, ror r9 */
/* @0x1531c8 eoreq r12, r9, r12, asr r9 */
/* @0x1531cc push {r4, r5, lr} */
/* @0x1531d0 mov r5, r0 */
/* @0x1531d4 ldr r4, [pc, #0x40] */
/* @0x1531d8 sub sp, sp, #12 */
/* @0x1531dc add r4, pc, r4 */
/* @0x1531e0 ldr r3, [r4] */
/* @0x1531e4 cmn r3, #1 */
/* @0x1531e8 movne r0, r3 */
/* @0x1531ec beq 0x15320c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x218> */
/* @0x1531f0 str r5, [sp] */
/* @0x1531f4 mov r1, #1 */
/* @0x1531f8 mov r2, #0 */
/* @0x1531fc mov r3, #0 */
/* @0x153200 bl 0x2054a4 <_Z17DsQueueEnqueuePtriiz> */
/* @0x153204 add sp, sp, #12 */
/* @0x153208 pop {r4, r5, pc} */
/* @0x15320c bl 0x2053bc <_Z13DsQueueCreatev> */
/* @0x153210 mov r3, r0 */
/* @0x153214 str r3, [r4] */
/* @0x153218 b 0x1531f0 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x15321c eoreq pc, r9, r12, ror #2 */

/* ── FUNC 0x153220 · F_IAP_Deprecated(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x153220 ldr r0, [pc, #0x8] */
/* @0x153224 mov r1, #1 */
/* @0x153228 add r0, pc, r0 */
/* @0x15322c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x153230 andseq r2, pc, r0, asr #27 */

/* ── FUNC 0x153234 · F_IAP_ProductPurchased(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x153234 cmp r3, #0 */
/* @0x153238 push {r3, r4, r5, lr} */
/* @0x15323c mov r5, #0 */
/* @0x153240 mov r4, r0 */
/* @0x153244 str r5, [r0, #0xc] */
/* @0x153248 str r5, [r0] */
/* @0x15324c str r5, [r0, #0x4] */
/* @0x153250 pople {r3, r4, r5, pc} */
/* @0x153254 mov r1, r5 */
/* @0x153258 ldr r0, [sp, #0x10] */
/* @0x15325c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x153260 bl 0x15314c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x153264 mov r3, r5 */
/* @0x153268 str r5, [r4] */
/* @0x15326c cmp r0, r5 */
/* @0x153270 movtge r3, #0x3ff0 */
/* @0x153274 str r3, [r4, #0x4] */
/* @0x153278 pop {r3, r4, r5, pc} */

/* ── FUNC 0x15327c · anon_15327c · size=464 · insn=117 */
/* @0x15327c ldr r1, [r0, #0xc] */
/* @0x153280 push {r3, r4, r5, r6, r7, lr} */
/* @0x153284 cmp r1, #0 */
/* @0x153288 ldr r5, [pc, #0x104] */
/* @0x15328c add r5, pc, r5 */
/* @0x153290 beq 0x153304 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x153294 ldr r2, [pc, #0xfc] */
/* @0x153298 ldr r2, [r5, r2] */
/* @0x15329c ldr r6, [r2] */
/* @0x1532a0 cmp r6, #0 */
/* @0x1532a4 ble 0x1532f8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x1532a8 ldr r2, [pc, #0xec] */
/* @0x1532ac bic r1, r1, #-16777216 */
/* @0x1532b0 cmp r1, #1 */
/* @0x1532b4 ldr r2, [r5, r2] */
/* @0x1532b8 ldr r5, [r2, #0x4] */
/* @0x1532bc beq 0x15332c <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x1532c0 sub r5, r5, #4 */
/* @0x1532c4 mov r4, #0 */
/* @0x1532c8 b 0x1532d8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x1532cc add r4, r4, #1 */
/* @0x1532d0 cmp r4, r6 */
/* @0x1532d4 beq 0x1532f8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x1532d8 ldr r3, [r5, #0x4]! */
/* @0x1532dc mov r1, #0 */
/* @0x1532e0 ldr r0, [r3] */
/* @0x1532e4 bl 0xb6574 <strcmp@plt> */
/* @0x1532e8 cmp r0, #0 */
/* @0x1532ec bne 0x1532cc <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1532f0 mov r0, r4 */
/* @0x1532f4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1532f8 mvn r4, #0 */
/* @0x1532fc mov r0, r4 */
/* @0x153300 pop {r3, r4, r5, r6, r7, pc} */
/* @0x153304 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x153308 subs r4, r0, #0 */
/* @0x15330c blt 0x1532f8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x153310 ldr r3, [pc, #0x80] */
/* @0x153314 ldr r3, [r5, r3] */
/* @0x153318 ldr r3, [r3] */
/* @0x15331c cmp r4, r3 */
/* @0x153320 mvnge r4, #0 */
/* @0x153324 mov r0, r4 */
/* @0x153328 pop {r3, r4, r5, r6, r7, pc} */
/* @0x15332c ldr r7, [r0] */
/* @0x153330 mov r4, #0 */
/* @0x153334 sub r5, r5, #4 */
/* @0x153338 cmp r7, r4 */
/* @0x15333c bne 0x153350 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x153340 b 0x153378 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x153344 add r4, r4, #1 */
/* @0x153348 cmp r4, r6 */
/* @0x15334c beq 0x1532f8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x153350 ldr r3, [r5, #0x4]! */
/* @0x153354 ldr r1, [r7] */
/* @0x153358 ldr r0, [r3] */
/* @0x15335c bl 0xb6574 <strcmp@plt> */
/* @0x153360 cmp r0, #0 */
/* @0x153364 bne 0x153344 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x153368 b 0x1532f0 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x15336c add r4, r4, #1 */
/* @0x153370 cmp r4, r6 */
/* @0x153374 beq 0x1532f8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x153378 ldr r3, [r5, #0x4]! */
/* @0x15337c mov r1, #0 */
/* @0x153380 ldr r0, [r3] */
/* @0x153384 bl 0xb6574 <strcmp@plt> */
/* @0x153388 cmp r0, #0 */
/* @0x15338c bne 0x15336c <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x153390 b 0x1532f0 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x153394 eoreq lr, r9, r4, asr #19 */
/* @0x153398 .word 0xffffde80 */
/* @0x15339c .word 0xffffde84 */
/* @0x1533a0 ldr r1, [r0, #0xc] */
/* @0x1533a4 push {r3, r4, r5, r6, r7, lr} */
/* @0x1533a8 cmp r1, #0 */
/* @0x1533ac beq 0x153440 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x1533b0 bic r1, r1, #-16777216 */
/* @0x1533b4 cmp r1, #1 */
/* @0x1533b8 beq 0x1533c8 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x1533bc mvn r4, #0 */
/* @0x1533c0 mov r0, r4 */
/* @0x1533c4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1533c8 ldr r3, [r0] */
/* @0x1533cc cmp r3, #0 */
/* @0x1533d0 beq 0x1533bc <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x1533d4 ldr r7, [r3] */
/* @0x1533d8 cmp r7, #0 */
/* @0x1533dc beq 0x1533bc <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x1533e0 ldr r3, [pc, #0x60] */
/* @0x1533e4 ldr r3, [pc, r3] */
/* @0x1533e8 ldr r6, [r3] */
/* @0x1533ec cmp r6, #0 */
/* @0x1533f0 ble 0x1533bc <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x1533f4 ldr r3, [pc, #0x50] */
/* @0x1533f8 mov r4, #0 */
/* @0x1533fc ldr r3, [pc, r3] */
/* @0x153400 ldr r5, [r3, #0x4] */
/* @0x153404 sub r5, r5, #4 */
/* @0x153408 ldr r3, [r5, #0x4]! */
/* @0x15340c mov r1, r7 */
/* @0x153410 cmp r3, #0 */
/* @0x153414 beq 0x153430 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x153418 ldr r0, [r3] */
/* @0x15341c cmp r0, #0 */
/* @0x153420 beq 0x153430 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x153424 bl 0xb6574 <strcmp@plt> */
/* @0x153428 cmp r0, #0 */
/* @0x15342c beq 0x1533c0 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x153430 add r4, r4, #1 */
/* @0x153434 cmp r4, r6 */
/* @0x153438 bne 0x153408 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x15343c b 0x1533bc <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x153440 pop {r3, r4, r5, r6, r7, lr} */
/* @0x153444 b 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x153448 eoreq r12, r9, r4, ror #13 */
/* @0x15344c .word 0x0029c6d0 */

/* ── FUNC 0x153450 · F_IAP_PurchaseDetails(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x153450 push {r4, r5, r6, lr} */
/* @0x153454 mov r5, #0 */
/* @0x153458 ldr r6, [sp, #0x10] */
/* @0x15345c mov r4, r0 */
/* @0x153460 str r5, [r0, #0xc] */
/* @0x153464 str r5, [r0] */
/* @0x153468 str r5, [r0, #0x4] */
/* @0x15346c mov r0, r6 */
/* @0x153470 bl 0x1533a0 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x153474 subs r2, r0, #0 */
/* @0x153478 poplt {r4, r5, r6, pc} */
/* @0x15347c ldr r3, [pc, #0x48] */
/* @0x153480 ldr r3, [pc, r3] */
/* @0x153484 ldr r3, [r3] */
/* @0x153488 cmp r2, r3 */
/* @0x15348c popge {r4, r5, r6, pc} */
/* @0x153490 ldr r3, [pc, #0x38] */
/* @0x153494 mov r0, r6 */
/* @0x153498 mov r1, #1 */
/* @0x15349c ldr r3, [pc, r3] */
/* @0x1534a0 ldr r3, [r3, #0x4] */
/* @0x1534a4 ldr r6, [r3, r2, lsl #2] */
/* @0x1534a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1534ac mov r1, r0 */
/* @0x1534b0 mov r0, r6 */
/* @0x1534b4 bl 0x18ae38 <_ZN12CIAPPurchase11PopulateMapEi> */
/* @0x1534b8 mov r3, r5 */
/* @0x1534bc str r5, [r4] */
/* @0x1534c0 movt r3, #0x3ff0 */
/* @0x1534c4 str r3, [r4, #0x4] */
/* @0x1534c8 pop {r4, r5, r6, pc} */
/* @0x1534cc eoreq r12, r9, r8, asr #12 */
/* @0x1534d0 eoreq r12, r9, r0, lsr r6 */

/* ── FUNC 0x1534d4 · InitIAPFunctions() · size=572 · insn=143 */
/* @0x1534d4 push {r4, r5, r6, lr} */
/* @0x1534d8 mov r0, #8 */
/* @0x1534dc bl 0x27c524 <_Znwj> */
/* @0x1534e0 ldr r1, [pc, #0x1b8] */
/* @0x1534e4 ldr r4, [pc, #0x1b8] */
/* @0x1534e8 add r1, pc, r1 */
/* @0x1534ec add r4, pc, r4 */
/* @0x1534f0 mov r5, r0 */
/* @0x1534f4 bl 0x27e070 <_ZN5MutexC2EPKc> */
/* @0x1534f8 ldr r12, [pc, #0x1a8] */
/* @0x1534fc mov r2, #1 */
/* @0x153500 ldr r1, [pc, #0x1a4] */
/* @0x153504 mov r3, #0 */
/* @0x153508 add r12, pc, r12 */
/* @0x15350c ldr r0, [pc, #0x19c] */
/* @0x153510 str r5, [r12] */
/* @0x153514 add r0, pc, r0 */
/* @0x153518 ldr r1, [r4, r1] */
/* @0x15351c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x153520 ldr r1, [pc, #0x18c] */
/* @0x153524 ldr r0, [pc, #0x18c] */
/* @0x153528 mov r2, #0 */
/* @0x15352c mov r3, r2 */
/* @0x153530 ldr r5, [r4, r1] */
/* @0x153534 add r0, pc, r0 */
/* @0x153538 mov r1, r5 */
/* @0x15353c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x153540 ldr r1, [pc, #0x174] */
/* @0x153544 ldr r0, [pc, #0x174] */
/* @0x153548 mov r2, #2 */
/* @0x15354c mov r3, #0 */
/* @0x153550 ldr r1, [r4, r1] */
/* @0x153554 add r0, pc, r0 */
/* @0x153558 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15355c ldr r1, [pc, #0x160] */
/* @0x153560 ldr r0, [pc, #0x160] */
/* @0x153564 mov r2, #1 */
/* @0x153568 mov r3, #0 */
/* @0x15356c ldr r1, [r4, r1] */
/* @0x153570 add r0, pc, r0 */
/* @0x153574 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x153578 ldr r1, [pc, #0x14c] */
/* @0x15357c ldr r0, [pc, #0x14c] */
/* @0x153580 mov r2, #1 */
/* @0x153584 mov r3, #0 */
/* @0x153588 ldr r1, [r4, r1] */
/* @0x15358c add r0, pc, r0 */
/* @0x153590 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x153594 ldr r1, [pc, #0x138] */
/* @0x153598 ldr r0, [pc, #0x138] */
/* @0x15359c mov r2, #1 */
/* @0x1535a0 mov r3, #0 */
/* @0x1535a4 ldr r1, [r4, r1] */
/* @0x1535a8 add r0, pc, r0 */
/* @0x1535ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1535b0 ldr r1, [pc, #0x124] */
/* @0x1535b4 ldr r0, [pc, #0x124] */
/* @0x1535b8 mov r2, #0 */
/* @0x1535bc mov r3, r2 */
/* @0x1535c0 ldr r1, [r4, r1] */
/* @0x1535c4 add r0, pc, r0 */
/* @0x1535c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1535cc ldr r1, [pc, #0x110] */
/* @0x1535d0 ldr r0, [pc, #0x110] */
/* @0x1535d4 mov r2, #2 */
/* @0x1535d8 mov r3, #0 */
/* @0x1535dc ldr r1, [r4, r1] */
/* @0x1535e0 add r0, pc, r0 */
/* @0x1535e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1535e8 ldr r1, [pc, #0xfc] */
/* @0x1535ec ldr r0, [pc, #0xfc] */
/* @0x1535f0 mov r2, #2 */
/* @0x1535f4 mov r3, #0 */
/* @0x1535f8 ldr r1, [r4, r1] */
/* @0x1535fc add r0, pc, r0 */
/* @0x153600 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x153604 ldr r0, [pc, #0xe8] */
/* @0x153608 mov r2, #0 */
/* @0x15360c mov r1, r5 */
/* @0x153610 mov r3, r2 */
/* @0x153614 add r0, pc, r0 */
/* @0x153618 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15361c ldr r1, [pc, #0xd4] */
/* @0x153620 ldr r0, [pc, #0xd4] */
/* @0x153624 mov r2, #0 */
/* @0x153628 mov r3, r2 */
/* @0x15362c ldr r4, [r4, r1] */
/* @0x153630 add r0, pc, r0 */
/* @0x153634 mov r1, r4 */
/* @0x153638 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15363c ldr r0, [pc, #0xbc] */
/* @0x153640 mov r1, r4 */
/* @0x153644 mov r2, #1 */
/* @0x153648 add r0, pc, r0 */
/* @0x15364c mov r3, #0 */
/* @0x153650 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x153654 ldr r0, [pc, #0xa8] */
/* @0x153658 mov r1, r4 */
/* @0x15365c mov r2, #1 */
/* @0x153660 add r0, pc, r0 */
/* @0x153664 mov r3, #0 */
/* @0x153668 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x15366c ldr r0, [pc, #0x94] */
/* @0x153670 mov r1, r4 */
/* @0x153674 mov r2, #2 */
/* @0x153678 add r0, pc, r0 */
/* @0x15367c mov r3, #0 */
/* @0x153680 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x153684 ldr r0, [pc, #0x80] */
/* @0x153688 mov r2, #0 */
/* @0x15368c mov r1, r4 */
/* @0x153690 mov r3, r2 */
/* @0x153694 add r0, pc, r0 */
/* @0x153698 pop {r4, r5, r6, lr} */
/* @0x15369c b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1536a0 andseq r2, pc, r0, lsr #22 */
/* @0x1536a4 eoreq lr, r9, r4, ror #14 */
/* @0x1536a8 eorseq r1, r3, r8, lsr r5 */
/* @0x1536ac .word 0xffffde88 */
/* @0x1536b0 andseq r2, pc, r4, lsl #22 */
/* @0x1536b4 .word 0xffffde8c */
/* @0x1536b8 ldrsheq r2, [pc], -r4 */
/* @0x1536bc .word 0xffffde90 */
/* @0x1536c0 andseq r2, pc, r0, ror #21 */
/* @0x1536c4 .word 0xffffde94 */
/* @0x1536c8 ldrsbeq r2, [pc], -r0 */
/* @0x1536cc .word 0xffffde98 */
/* @0x1536d0 andseq r2, pc, r0, asr #21 */
/* @0x1536d4 .word 0xffffde9c */
/* @0x1536d8 ldrheq r2, [pc], -r8 */
/* @0x1536dc .word 0xffffdea0 */
/* @0x1536e0 ldrheq r2, [pc], -r4 */
/* @0x1536e4 .word 0xffffdea4 */
/* @0x1536e8 andseq r2, pc, r8, lsr #21 */
/* @0x1536ec .word 0xffffdea8 */
/* @0x1536f0 andseq r2, pc, r0, lsr #21 */
/* @0x1536f4 andseq r2, pc, r0, lsr #21 */
/* @0x1536f8 .word 0xffffdeac */
/* @0x1536fc mulseq pc, r8, r10 */
/* @0x153700 mulseq pc, r0, r10 */
/* @0x153704 andseq r2, pc, r12, lsl #21 */
/* @0x153708 andseq r2, pc, r8, lsl #21 */
/* @0x15370c andseq r2, pc, r0, lsl #21 */

/* ── FUNC 0x153710 · anon_153710 · size=1236 · insn=310 */
/* @0x153710 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x153714 sub sp, sp, #24 */
/* @0x153718 add r7, sp, #4 */
/* @0x15371c mov r6, r0 */
/* @0x153720 add r4, sp, #8 */
/* @0x153724 ldr r5, [pc, #0x37c] */
/* @0x153728 mov r0, r7 */
/* @0x15372c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x153730 ldr r1, [pc, #0x374] */
/* @0x153734 mov r0, r4 */
/* @0x153738 add r5, pc, r5 */
/* @0x15373c add r1, pc, r1 */
/* @0x153740 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x153744 mov r0, r6 */
/* @0x153748 mov r1, r4 */
/* @0x15374c bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x153750 ldr r3, [sp, #0x14] */
/* @0x153754 sub r3, r3, #1 */
/* @0x153758 bic r3, r3, #-16777216 */
/* @0x15375c bic r3, r3, #3 */
/* @0x153760 cmp r3, #0 */
/* @0x153764 mov r8, r0 */
/* @0x153768 beq 0x1537b0 <_Z16InitIAPFunctionsv+0x2dc> */
/* @0x15376c mov r3, #0 */
/* @0x153770 add r0, r8, #16 */
/* @0x153774 mov r1, r3 */
/* @0x153778 str r3, [sp, #0x10] */
/* @0x15377c str r3, [sp, #0x8] */
/* @0x153780 mov r3, #5 */
/* @0x153784 str r3, [sp, #0x14] */
/* @0x153788 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15378c ldr r3, [pc, #0x31c] */
/* @0x153790 cmp r0, #4 */
/* @0x153794 addls pc, pc, r0, lsl #2 */
/* @0x153798 b 0x153a4c <_Z16InitIAPFunctionsv+0x578> */
/* @0x15379c b 0x1537f4 <_Z16InitIAPFunctionsv+0x320> */
/* @0x1537a0 b 0x153808 <_Z16InitIAPFunctionsv+0x334> */
/* @0x1537a4 b 0x15394c <_Z16InitIAPFunctionsv+0x478> */
/* @0x1537a8 b 0x1539cc <_Z16InitIAPFunctionsv+0x4f8> */
/* @0x1537ac b 0x1537bc <_Z16InitIAPFunctionsv+0x2e8> */
/* @0x1537b0 mov r0, r4 */
/* @0x1537b4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1537b8 b 0x15376c <_Z16InitIAPFunctionsv+0x298> */
/* @0x1537bc ldr r3, [r5, r3] */
/* @0x1537c0 mov r2, #3 */
/* @0x1537c4 str r2, [r3] */
/* @0x1537c8 bl 0x16186c <_Z12IAP_RestoreMv> */
/* @0x1537cc bl 0x100014 <_Z18FindFreeDsMapIndexv> */
/* @0x1537d0 ldr r3, [pc, #0x2dc] */
/* @0x1537d4 ldr r3, [r5, r3] */
/* @0x1537d8 ldr r3, [r3, #0x4] */
/* @0x1537dc str r6, [r3, r0, lsl #2] */
/* @0x1537e0 bl 0x205334 <_Z12DestroyDsMapi> */
/* @0x1537e4 mov r0, r7 */
/* @0x1537e8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1537ec add sp, sp, #24 */
/* @0x1537f0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1537f4 ldr r3, [r5, r3] */
/* @0x1537f8 mov r2, #0 */
/* @0x1537fc str r2, [r3] */
/* @0x153800 bl 0x16173c <_Z13IAP_ActivateMv> */
/* @0x153804 b 0x1537cc <_Z16InitIAPFunctionsv+0x2f8> */
/* @0x153808 ldr r3, [r5, r3] */
/* @0x15380c mov r0, r4 */
/* @0x153810 ldr r1, [pc, #0x2a0] */
/* @0x153814 mov r2, #2 */
/* @0x153818 add r1, pc, r1 */
/* @0x15381c str r2, [r3] */
/* @0x153820 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x153824 mov r0, r6 */
/* @0x153828 mov r1, r4 */
/* @0x15382c bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x153830 ldr r3, [sp, #0x14] */
/* @0x153834 sub r3, r3, #1 */
/* @0x153838 bic r3, r3, #-16777216 */
/* @0x15383c bic r3, r3, #3 */
/* @0x153840 cmp r3, #0 */
/* @0x153844 mov r8, r0 */
/* @0x153848 beq 0x153a5c <_Z16InitIAPFunctionsv+0x588> */
/* @0x15384c ldr r1, [pc, #0x268] */
/* @0x153850 mov r0, r4 */
/* @0x153854 mov r3, #0 */
/* @0x153858 mov r2, #5 */
/* @0x15385c add r1, pc, r1 */
/* @0x153860 str r3, [sp, #0x10] */
/* @0x153864 str r3, [sp, #0x8] */
/* @0x153868 str r2, [sp, #0x14] */
/* @0x15386c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x153870 mov r0, r6 */
/* @0x153874 mov r1, r4 */
/* @0x153878 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x15387c ldr r3, [sp, #0x14] */
/* @0x153880 sub r3, r3, #1 */
/* @0x153884 bic r3, r3, #-16777216 */
/* @0x153888 bic r3, r3, #3 */
/* @0x15388c cmp r3, #0 */
/* @0x153890 mov r9, r0 */
/* @0x153894 beq 0x153a8c <_Z16InitIAPFunctionsv+0x5b8> */
/* @0x153898 ldr r1, [pc, #0x220] */
/* @0x15389c mov r0, r4 */
/* @0x1538a0 mov r3, #0 */
/* @0x1538a4 mov r2, #5 */
/* @0x1538a8 add r1, pc, r1 */
/* @0x1538ac str r3, [sp, #0x10] */
/* @0x1538b0 str r3, [sp, #0x8] */
/* @0x1538b4 str r2, [sp, #0x14] */
/* @0x1538b8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x1538bc mov r0, r6 */
/* @0x1538c0 mov r1, r4 */
/* @0x1538c4 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x1538c8 ldr r3, [sp, #0x14] */
/* @0x1538cc sub r3, r3, #1 */
/* @0x1538d0 bic r3, r3, #-16777216 */
/* @0x1538d4 bic r3, r3, #3 */
/* @0x1538d8 cmp r3, #0 */
/* @0x1538dc mov r10, r0 */
/* @0x1538e0 beq 0x153a80 <_Z16InitIAPFunctionsv+0x5ac> */
/* @0x1538e4 ldr r1, [r8, #0x1c] */
/* @0x1538e8 mov r3, #0 */
/* @0x1538ec mov r2, #5 */
/* @0x1538f0 str r3, [sp, #0x10] */
/* @0x1538f4 bic r1, r1, #-16777216 */
/* @0x1538f8 str r3, [sp, #0x8] */
/* @0x1538fc cmp r1, #1 */
/* @0x153900 str r2, [sp, #0x14] */
/* @0x153904 movne r4, r3 */
/* @0x153908 beq 0x153a98 <_Z16InitIAPFunctionsv+0x5c4> */
/* @0x15390c ldr r3, [r10, #0x1c] */
/* @0x153910 bic r3, r3, #-16777216 */
/* @0x153914 cmp r3, #1 */
/* @0x153918 movne r8, #0 */
/* @0x15391c bne 0x15392c <_Z16InitIAPFunctionsv+0x458> */
/* @0x153920 ldr r8, [r10, #0x10] */
/* @0x153924 cmp r8, #0 */
/* @0x153928 ldrne r8, [r8] */
/* @0x15392c add r0, r9, #16 */
/* @0x153930 mov r1, #0 */
/* @0x153934 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x153938 mov r1, r8 */
/* @0x15393c mov r2, r0 */
/* @0x153940 mov r0, r4 */
/* @0x153944 bl 0x16189c <_Z12IAP_AcquireMPKcS0_i> */
/* @0x153948 b 0x1537cc <_Z16InitIAPFunctionsv+0x2f8> */
/* @0x15394c ldr r3, [r5, r3] */
/* @0x153950 mov r0, r4 */
/* @0x153954 ldr r1, [pc, #0x168] */
/* @0x153958 mov r2, #2 */
/* @0x15395c add r1, pc, r1 */
/* @0x153960 str r2, [r3] */
/* @0x153964 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x153968 mov r0, r6 */
/* @0x15396c mov r1, r4 */
/* @0x153970 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x153974 ldr r3, [sp, #0x14] */
/* @0x153978 sub r3, r3, #1 */
/* @0x15397c bic r3, r3, #-16777216 */
/* @0x153980 bic r3, r3, #3 */
/* @0x153984 cmp r3, #0 */
/* @0x153988 mov r8, r0 */
/* @0x15398c beq 0x153a74 <_Z16InitIAPFunctionsv+0x5a0> */
/* @0x153990 ldr r1, [r8, #0x1c] */
/* @0x153994 mov r3, #0 */
/* @0x153998 mov r2, #5 */
/* @0x15399c str r3, [sp, #0x10] */
/* @0x1539a0 bic r1, r1, #-16777216 */
/* @0x1539a4 str r3, [sp, #0x8] */
/* @0x1539a8 cmp r1, #1 */
/* @0x1539ac str r2, [sp, #0x14] */
/* @0x1539b0 movne r0, r3 */
/* @0x1539b4 bne 0x1539c4 <_Z16InitIAPFunctionsv+0x4f0> */
/* @0x1539b8 ldr r0, [r8, #0x10] */
/* @0x1539bc cmp r0, r3 */
/* @0x1539c0 ldrne r0, [r0] */
/* @0x1539c4 bl 0x161940 <_Z12IAP_ConsumeMPKc> */
/* @0x1539c8 b 0x1537cc <_Z16InitIAPFunctionsv+0x2f8> */
/* @0x1539cc ldr r3, [r5, r3] */
/* @0x1539d0 mov r0, r4 */
/* @0x1539d4 ldr r1, [pc, #0xec] */
/* @0x1539d8 mov r2, #2 */
/* @0x1539dc add r1, pc, r1 */
/* @0x1539e0 str r2, [r3] */
/* @0x1539e4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x1539e8 mov r0, r6 */
/* @0x1539ec mov r1, r4 */
/* @0x1539f0 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x1539f4 ldr r3, [sp, #0x14] */
/* @0x1539f8 sub r3, r3, #1 */
/* @0x1539fc bic r3, r3, #-16777216 */
/* @0x153a00 bic r3, r3, #3 */
/* @0x153a04 cmp r3, #0 */
/* @0x153a08 mov r8, r0 */
/* @0x153a0c beq 0x153a68 <_Z16InitIAPFunctionsv+0x594> */
/* @0x153a10 ldr r1, [r8, #0x1c] */
/* @0x153a14 mov r3, #0 */
/* @0x153a18 mov r2, #5 */
/* @0x153a1c str r3, [sp, #0x10] */
/* @0x153a20 bic r1, r1, #-16777216 */
/* @0x153a24 str r3, [sp, #0x8] */
/* @0x153a28 cmp r1, #1 */
/* @0x153a2c str r2, [sp, #0x14] */
/* @0x153a30 movne r0, r3 */
/* @0x153a34 bne 0x153a44 <_Z16InitIAPFunctionsv+0x570> */
/* @0x153a38 ldr r0, [r8, #0x10] */
/* @0x153a3c cmp r0, r3 */
/* @0x153a40 ldrne r0, [r0] */
/* @0x153a44 bl 0x161ae8 <_Z21IAP_GetProductDetailMPKc> */
/* @0x153a48 b 0x1537cc <_Z16InitIAPFunctionsv+0x2f8> */
/* @0x153a4c ldr r3, [r5, r3] */
/* @0x153a50 mov r2, #1 */
/* @0x153a54 str r2, [r3] */
/* @0x153a58 b 0x1537cc <_Z16InitIAPFunctionsv+0x2f8> */
/* @0x153a5c mov r0, r4 */
/* @0x153a60 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x153a64 b 0x15384c <_Z16InitIAPFunctionsv+0x378> */
/* @0x153a68 mov r0, r4 */
/* @0x153a6c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x153a70 b 0x153a10 <_Z16InitIAPFunctionsv+0x53c> */
/* @0x153a74 mov r0, r4 */
/* @0x153a78 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x153a7c b 0x153990 <_Z16InitIAPFunctionsv+0x4bc> */
/* @0x153a80 mov r0, r4 */
/* @0x153a84 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x153a88 b 0x1538e4 <_Z16InitIAPFunctionsv+0x410> */
/* @0x153a8c mov r0, r4 */
/* @0x153a90 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x153a94 b 0x153898 <_Z16InitIAPFunctionsv+0x3c4> */
/* @0x153a98 ldr r4, [r8, #0x10] */
/* @0x153a9c cmp r4, r3 */
/* @0x153aa0 ldrne r4, [r4] */
/* @0x153aa4 b 0x15390c <_Z16InitIAPFunctionsv+0x438> */
/* @0x153aa8 eoreq lr, r9, r8, lsl r5 */
/* @0x153aac andseq r2, pc, r12, ror #19 */
/* @0x153ab0 .word 0xffffde74 */
/* @0x153ab4 .word 0xffffbcec */
/* @0x153ab8 andseq r2, pc, r8, lsl r9 */
/* @0x153abc ldrsbeq r2, [pc], -r12 */
/* @0x153ac0 andseq r2, pc, r0, lsr #17 */
/* @0x153ac4 ldrsbeq r2, [pc], -r4 */
/* @0x153ac8 andseq r2, pc, r4, asr r7 */
/* @0x153acc ldr r3, [pc, #0xf4] */
/* @0x153ad0 ldr r2, [pc, #0xf4] */
/* @0x153ad4 add r3, pc, r3 */
/* @0x153ad8 push {r4, r5, lr} */
/* @0x153adc mov r4, r0 */
/* @0x153ae0 ldr r2, [r3, r2] */
/* @0x153ae4 sub sp, sp, #12 */
/* @0x153ae8 ldr r2, [r2] */
/* @0x153aec add r2, r2, #2 */
/* @0x153af0 cmp r2, #4 */
/* @0x153af4 addls pc, pc, r2, lsl #2 */
/* @0x153af8 b 0x153b38 <_Z16InitIAPFunctionsv+0x664> */
/* @0x153afc b 0x153b10 <_Z16InitIAPFunctionsv+0x63c> */
/* @0x153b00 b 0x153b10 <_Z16InitIAPFunctionsv+0x63c> */
/* @0x153b04 b 0x153b58 <_Z16InitIAPFunctionsv+0x684> */
/* @0x153b08 b 0x153b40 <_Z16InitIAPFunctionsv+0x66c> */
/* @0x153b0c b 0x153b58 <_Z16InitIAPFunctionsv+0x684> */
/* @0x153b10 cmp r1, #0 */
/* @0x153b14 beq 0x153b48 <_Z16InitIAPFunctionsv+0x674> */
/* @0x153b18 ldr r1, [pc, #0xb0] */
/* @0x153b1c ldr r2, [pc, #0xb0] */
/* @0x153b20 add r1, pc, r1 */
/* @0x153b24 ldr r3, [r3, r2] */
/* @0x153b28 ldr r0, [r3] */
/* @0x153b2c ldr r3, [r0] */
/* @0x153b30 ldr r3, [r3, #0xc] */
/* @0x153b34 blx r3 */
/* @0x153b38 add sp, sp, #12 */
/* @0x153b3c pop {r4, r5, pc} */
/* @0x153b40 cmp r1, #0 */
/* @0x153b44 beq 0x153ba8 <_Z16InitIAPFunctionsv+0x6d4> */
/* @0x153b48 mov r0, r4 */
/* @0x153b4c add sp, sp, #12 */
/* @0x153b50 pop {r4, r5, lr} */
/* @0x153b54 b 0x153710 <_Z16InitIAPFunctionsv+0x23c> */
/* @0x153b58 ldr r2, [pc, #0x74] */
/* @0x153b5c ldr r5, [pc, #0x74] */
/* @0x153b60 ldr r1, [pc, #0x74] */
/* @0x153b64 ldr r3, [r3, r2] */
/* @0x153b68 add r5, pc, r5 */
/* @0x153b6c add r1, pc, r1 */
/* @0x153b70 ldr r0, [r3] */
/* @0x153b74 ldr r3, [r0] */
/* @0x153b78 ldr r3, [r3, #0xc] */
/* @0x153b7c blx r3 */
/* @0x153b80 ldr r0, [r5, #0x4] */
/* @0x153b84 cmn r0, #1 */
/* @0x153b88 beq 0x153bb8 <_Z16InitIAPFunctionsv+0x6e4> */
/* @0x153b8c str r4, [sp] */
/* @0x153b90 mov r1, #1 */
/* @0x153b94 mov r2, #0 */
/* @0x153b98 mov r3, #0 */
/* @0x153b9c bl 0x2054a4 <_Z17DsQueueEnqueuePtriiz> */
/* @0x153ba0 add sp, sp, #12 */
/* @0x153ba4 pop {r4, r5, pc} */
/* @0x153ba8 ldr r1, [pc, #0x30] */
/* @0x153bac ldr r2, [pc, #0x20] */
/* @0x153bb0 add r1, pc, r1 */
/* @0x153bb4 b 0x153b24 <_Z16InitIAPFunctionsv+0x650> */
/* @0x153bb8 bl 0x2053bc <_Z13DsQueueCreatev> */
/* @0x153bbc mov r3, r0 */
/* @0x153bc0 str r3, [r5, #0x4] */
/* @0x153bc4 b 0x153b8c <_Z16InitIAPFunctionsv+0x6b8> */
/* @0x153bc8 eoreq lr, r9, r12, ror r1 */
/* @0x153bcc .word 0xffffde74 */
/* @0x153bd0 andseq r2, pc, r0, lsr r6 */
/* @0x153bd4 .word 0xffffbcf0 */
/* @0x153bd8 eoreq lr, r9, r0, ror #15 */
/* @0x153bdc andseq r2, pc, r8, lsl r6 */
/* @0x153be0 andseq r2, pc, r0, lsl r6 */
/* @0x153be4 andeq r0, r0, r0 */

/* ── FUNC 0x153be8 · YYIAPEventsDispatch() · size=3720 · insn=928 */
/* @0x153be8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x153bec vpush {d8, d9} */
/* @0x153bf0 add r11, sp, #48 */
/* @0x153bf4 ldr r12, [pc, #0x43c] */
/* @0x153bf8 sub sp, sp, #196 */
/* @0x153bfc ldr r3, [pc, #0x438] */
/* @0x153c00 add r12, pc, r12 */
/* @0x153c04 str r12, [r11, #-0x94] */
/* @0x153c08 sub r12, r11, #140 */
/* @0x153c0c str r12, [r11, #-0xd8] */
/* @0x153c10 ldr r4, [pc, #0x428] */
/* @0x153c14 mov r0, r12 */
/* @0x153c18 ldr r12, [r11, #-0x94] */
/* @0x153c1c add r4, pc, r4 */
/* @0x153c20 ldr r3, [r12, r3] */
/* @0x153c24 str r3, [r11, #-0xdc] */
/* @0x153c28 ldr r3, [r3] */
/* @0x153c2c str r3, [r11, #-0x38] */
/* @0x153c30 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x153c34 ldr r3, [pc, #0x408] */
/* @0x153c38 ldr r0, [pc, r3] */
/* @0x153c3c bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x153c40 ldr r0, [r4] */
/* @0x153c44 cmp r0, #0 */
/* @0x153c48 blt 0x153e0c <_Z19YYIAPEventsDispatchv+0x224> */
/* @0x153c4c bl 0x2055c8 <_Z11DsQueueSizei> */
/* @0x153c50 cmp r0, #0 */
/* @0x153c54 ble 0x153e0c <_Z19YYIAPEventsDispatchv+0x224> */
/* @0x153c58 ldr r0, [r4] */
/* @0x153c5c sub r7, r11, #52 */
/* @0x153c60 bl 0x2055c8 <_Z11DsQueueSizei> */
/* @0x153c64 mov r3, #0 */
/* @0x153c68 str r3, [r7, #-0x24]! */
/* @0x153c6c mov r8, #0 */
/* @0x153c70 str r3, [r11, #-0xac] */
/* @0x153c74 lsl r0, r0, #2 */
/* @0x153c78 add r3, r0, #14 */
/* @0x153c7c bic r3, r3, #7 */
/* @0x153c80 sub sp, sp, r3 */
/* @0x153c84 add r6, sp, #8 */
/* @0x153c88 sub r5, r6, #4 */
/* @0x153c8c b 0x153ca8 <_Z19YYIAPEventsDispatchv+0xc0> */
/* @0x153c90 ldr r0, [r4] */
/* @0x153c94 mov r1, r7 */
/* @0x153c98 bl 0x20557c <_Z14DsQueueDequeueiR6RValue> */
/* @0x153c9c ldr r3, [r11, #-0x58] */
/* @0x153ca0 add r8, r8, #1 */
/* @0x153ca4 str r3, [r5, #0x4]! */
/* @0x153ca8 ldr r0, [r4] */
/* @0x153cac bl 0x2055c8 <_Z11DsQueueSizei> */
/* @0x153cb0 cmp r0, #0 */
/* @0x153cb4 bgt 0x153c90 <_Z19YYIAPEventsDispatchv+0xa8> */
/* @0x153cb8 ldr r0, [r4] */
/* @0x153cbc str r8, [r11, #-0xac] */
/* @0x153cc0 bl 0x205620 <_Z12DsQueueCleari> */
/* @0x153cc4 ldr r3, [pc, #0x37c] */
/* @0x153cc8 ldr r0, [pc, r3] */
/* @0x153ccc bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x153cd0 ldr r8, [r11, #-0xac] */
/* @0x153cd4 cmp r8, #0 */
/* @0x153cd8 beq 0x153e18 <_Z19YYIAPEventsDispatchv+0x230> */
/* @0x153cdc sub r12, r11, #136 */
/* @0x153ce0 ldr r0, [pc, #0x364] */
/* @0x153ce4 str r12, [r11, #-0xa4] */
/* @0x153ce8 mov r12, #0 */
/* @0x153cec str r12, [r11, #-0x9c] */
/* @0x153cf0 vldr d8, [pc, #824] */
/* @0x153cf4 ldr r12, [r11, #-0x94] */
/* @0x153cf8 str r6, [r11, #-0xa0] */
/* @0x153cfc ldr r1, [pc, #0x34c] */
/* @0x153d00 ldr r0, [r12, r0] */
/* @0x153d04 ldr r2, [pc, #0x348] */
/* @0x153d08 ldr r3, [pc, #0x348] */
/* @0x153d0c str r0, [r11, #-0xb8] */
/* @0x153d10 ldr r1, [r12, r1] */
/* @0x153d14 str r1, [r11, #-0xb4] */
/* @0x153d18 ldr r2, [r12, r2] */
/* @0x153d1c str r2, [r11, #-0xa8] */
/* @0x153d20 ldr r8, [r12, r3] */
/* @0x153d24 ldr r12, [pc, #0x330] */
/* @0x153d28 add r12, pc, r12 */
/* @0x153d2c str r12, [r11, #-0xbc] */
/* @0x153d30 ldr r12, [pc, #0x328] */
/* @0x153d34 mov r10, r8 */
/* @0x153d38 add r12, pc, r12 */
/* @0x153d3c str r12, [r11, #-0xcc] */
/* @0x153d40 ldr r12, [pc, #0x31c] */
/* @0x153d44 add r12, pc, r12 */
/* @0x153d48 str r12, [r11, #-0xe4] */
/* @0x153d4c ldr r12, [pc, #0x314] */
/* @0x153d50 add r12, pc, r12 */
/* @0x153d54 str r12, [r11, #-0xd0] */
/* @0x153d58 ldr r12, [pc, #0x30c] */
/* @0x153d5c add r12, pc, r12 */
/* @0x153d60 str r12, [r11, #-0xe8] */
/* @0x153d64 bl 0x100014 <_Z18FindFreeDsMapIndexv> */
/* @0x153d68 ldr r12, [r11, #-0xa0] */
/* @0x153d6c ldr r1, [r11, #-0xbc] */
/* @0x153d70 ldr r2, [r12] */
/* @0x153d74 ldr r12, [r11, #-0xb8] */
/* @0x153d78 ldr r3, [r12, #0x4] */
/* @0x153d7c str r0, [r11, #-0x98] */
/* @0x153d80 sub r0, r11, #136 */
/* @0x153d84 ldr r12, [r11, #-0x98] */
/* @0x153d88 str r2, [r3, r12, lsl #2] */
/* @0x153d8c ldr r12, [r11, #-0xa0] */
/* @0x153d90 ldr r9, [r12], #4 */
/* @0x153d94 str r12, [r11, #-0xa0] */
/* @0x153d98 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x153d9c mov r0, r9 */
/* @0x153da0 sub r1, r11, #136 */
/* @0x153da4 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x153da8 ldr r3, [r11, #-0x7c] */
/* @0x153dac sub r3, r3, #1 */
/* @0x153db0 bic r3, r3, #-16777216 */
/* @0x153db4 bic r3, r3, #3 */
/* @0x153db8 cmp r3, #0 */
/* @0x153dbc mov r4, r0 */
/* @0x153dc0 beq 0x154750 <_Z19YYIAPEventsDispatchv+0xb68> */
/* @0x153dc4 cmp r4, #0 */
/* @0x153dc8 mov r3, #0 */
/* @0x153dcc mov r2, #5 */
/* @0x153dd0 str r3, [r11, #-0x80] */
/* @0x153dd4 str r3, [r11, #-0x88] */
/* @0x153dd8 str r2, [r11, #-0x7c] */
/* @0x153ddc beq 0x153fa0 <_Z19YYIAPEventsDispatchv+0x3b8> */
/* @0x153de0 ldr r0, [r4, #0x10] */
/* @0x153de4 ldr r1, [r4, #0x14] */
/* @0x153de8 bl 0xb66e8 <lrint@plt> */
/* @0x153dec cmp r0, #4 */
/* @0x153df0 addls pc, pc, r0, lsl #2 */
/* @0x153df4 b 0x153fa0 <_Z19YYIAPEventsDispatchv+0x3b8> */
/* @0x153df8 b 0x1542ac <_Z19YYIAPEventsDispatchv+0x6c4> */
/* @0x153dfc b 0x15455c <_Z19YYIAPEventsDispatchv+0x974> */
/* @0x153e00 b 0x15432c <_Z19YYIAPEventsDispatchv+0x744> */
/* @0x153e04 b 0x15419c <_Z19YYIAPEventsDispatchv+0x5b4> */
/* @0x153e08 b 0x153ec0 <_Z19YYIAPEventsDispatchv+0x2d8> */
/* @0x153e0c ldr r3, [pc, #0x25c] */
/* @0x153e10 ldr r0, [pc, r3] */
/* @0x153e14 bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x153e18 sub r0, r11, #140 */
/* @0x153e1c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x153e20 ldr r12, [r11, #-0xdc] */
/* @0x153e24 ldr r2, [r11, #-0x38] */
/* @0x153e28 ldr r3, [r12] */
/* @0x153e2c cmp r2, r3 */
/* @0x153e30 bne 0x154a6c <_Z19YYIAPEventsDispatchv+0xe84> */
/* @0x153e34 sub sp, r11, #48 */
/* @0x153e38 vpop {d8, d9} */
/* @0x153e3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x153e40 ldr r3, [r11, #-0xc0] */
/* @0x153e44 ldr r12, [r11, #-0xb0] */
/* @0x153e48 ldr r9, [r11, #-0xd4] */
/* @0x153e4c cmp r12, #0 */
/* @0x153e50 moveq r3, #0 */
/* @0x153e54 andne r3, r3, #1 */
/* @0x153e58 cmp r3, #0 */
/* @0x153e5c bne 0x15479c <_Z19YYIAPEventsDispatchv+0xbb4> */
/* @0x153e60 ldr r3, [r11, #-0xb0] */
/* @0x153e64 mov r2, #0 */
/* @0x153e68 ldr r1, [pc, #0x204] */
/* @0x153e6c mov r0, r9 */
/* @0x153e70 str r3, [sp] */
/* @0x153e74 add r1, pc, r1 */
/* @0x153e78 mov r3, #0 */
/* @0x153e7c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x153e80 vmov.f64 d7, #1.000000e+00 */
/* @0x153e84 ldr r12, [r11, #-0xc0] */
/* @0x153e88 cmp r12, #0 */
/* @0x153e8c vmovne r2, r3, d7 */
/* @0x153e90 vmoveq r2, r3, d8 */
/* @0x153e94 mov r1, #0 */
/* @0x153e98 str r1, [sp] */
/* @0x153e9c ldr r1, [pc, #0x1d4] */
/* @0x153ea0 mov r0, r9 */
/* @0x153ea4 add r1, pc, r1 */
/* @0x153ea8 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x153eac mov r0, r9 */
/* @0x153eb0 ldr r1, [r11, #-0x90] */
/* @0x153eb4 bl 0x20b6cc <_ZN7CDS_Map6DeleteEP6RValue> */
/* @0x153eb8 vmov r0, s18 */
/* @0x153ebc bl 0x27e7c8 <json_object_put> */
/* @0x153ec0 ldr r3, [pc, #0x1e8] */
/* @0x153ec4 ldr r12, [r11, #-0x94] */
/* @0x153ec8 mov r2, #1 */
/* @0x153ecc ldr r3, [r12, r3] */
/* @0x153ed0 str r2, [r3] */
/* @0x153ed4 ldr r12, [r11, #-0xcc] */
/* @0x153ed8 ldr r0, [r12, #0x4] */
/* @0x153edc bl 0x2055c8 <_Z11DsQueueSizei> */
/* @0x153ee0 cmp r0, #0 */
/* @0x153ee4 beq 0x153fa0 <_Z19YYIAPEventsDispatchv+0x3b8> */
/* @0x153ee8 ldr r12, [r11, #-0xcc] */
/* @0x153eec sub r5, r11, #52 */
/* @0x153ef0 mov r3, #0 */
/* @0x153ef4 str r3, [r11, #-0x4c] */
/* @0x153ef8 str r3, [r5, #-0x24]! */
/* @0x153efc mov r1, r5 */
/* @0x153f00 ldr r0, [r12, #0x4] */
/* @0x153f04 bl 0x20557c <_Z14DsQueueDequeueiR6RValue> */
/* @0x153f08 ldr r4, [r11, #-0x58] */
/* @0x153f0c mov r0, r5 */
/* @0x153f10 ldr r1, [r11, #-0xe4] */
/* @0x153f14 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x153f18 mov r1, r5 */
/* @0x153f1c mov r0, r4 */
/* @0x153f20 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x153f24 ldr r3, [r11, #-0x4c] */
/* @0x153f28 sub r3, r3, #1 */
/* @0x153f2c bic r3, r3, #-16777216 */
/* @0x153f30 bic r3, r3, #3 */
/* @0x153f34 cmp r3, #0 */
/* @0x153f38 mov r6, r0 */
/* @0x153f3c bne 0x153f48 <_Z19YYIAPEventsDispatchv+0x360> */
/* @0x153f40 mov r0, r5 */
/* @0x153f44 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x153f48 ldr r12, [r11, #-0x94] */
/* @0x153f4c mov r3, #0 */
/* @0x153f50 ldr r1, [pc, #0x15c] */
/* @0x153f54 mov r2, #5 */
/* @0x153f58 str r3, [r11, #-0x58] */
/* @0x153f5c str r3, [r11, #-0x50] */
/* @0x153f60 str r2, [r11, #-0x4c] */
/* @0x153f64 ldr r1, [r12, r1] */
/* @0x153f68 ldr r2, [r6, #0x10] */
/* @0x153f6c ldr r3, [r6, #0x14] */
/* @0x153f70 ldr r5, [r1] */
/* @0x153f74 mov r0, r2 */
/* @0x153f78 mov r1, r3 */
/* @0x153f7c ldr r12, [r5] */
/* @0x153f80 ldr r6, [r12, #0xc] */
/* @0x153f84 bl 0xb66e8 <lrint@plt> */
/* @0x153f88 ldr r1, [r11, #-0xd0] */
/* @0x153f8c mov r2, r0 */
/* @0x153f90 mov r0, r5 */
/* @0x153f94 blx r6 */
/* @0x153f98 mov r0, r4 */
/* @0x153f9c bl 0x153710 <_Z16InitIAPFunctionsv+0x23c> */
/* @0x153fa0 ldr lr, [r11, #-0xa8] */
/* @0x153fa4 movw r12, #0x1d08 */
/* @0x153fa8 ldr r0, [r11, #-0x98] */
/* @0x153fac ldr r1, [r10, r12] */
/* @0x153fb0 ldrd r4, r5, [lr] */
/* @0x153fb4 ldr lr, [r11, #-0xb4] */
/* @0x153fb8 adds r2, r4, #1 */
/* @0x153fbc adc r3, r5, #0 */
/* @0x153fc0 cmp r1, #0 */
/* @0x153fc4 str r0, [lr] */
/* @0x153fc8 ldr r0, [r11, #-0xa8] */
/* @0x153fcc strd r2, r3, [r0] */
/* @0x153fd0 ble 0x154174 <_Z19YYIAPEventsDispatchv+0x58c> */
/* @0x153fd4 mov r8, r12 */
/* @0x153fd8 ldr r3, [pc, #0x9c] */
/* @0x153fdc ldr r12, [r11, #-0x94] */
/* @0x153fe0 mov r7, #0 */
/* @0x153fe4 ldr r2, [pc, #0x94] */
/* @0x153fe8 ldr r3, [r12, r3] */
/* @0x153fec ldr r9, [r12, r2] */
/* @0x153ff0 str r3, [r11, #-0x90] */
/* @0x153ff4 mov r3, r10 */
/* @0x153ff8 mov r10, r9 */
/* @0x153ffc mov r9, r3 */
/* @0x154000 ldr r12, [r11, #-0x90] */
/* @0x154004 movw lr, #0x3a14 */
/* @0x154008 ldr r3, [r10] */
/* @0x15400c ldr r1, [r12, lr] */
/* @0x154010 ldr r2, [r3, #0x4] */
/* @0x154014 ldr r3, [r3] */
/* @0x154018 ldr r1, [r1, r7, lsl #2] */
/* @0x15401c and r2, r1, r2 */
/* @0x154020 ldr r3, [r3, r2, lsl #3] */
/* @0x154024 cmp r3, #0 */
/* @0x154028 bne 0x1540e8 <_Z19YYIAPEventsDispatchv+0x500> */
/* @0x15402c b 0x154160 <_Z19YYIAPEventsDispatchv+0x578> */
/* @0x154038 eoreq lr, r9, r0, asr r0 */
/* @0x15403c .word 0xffffbd00 */
/* @0x154040 eoreq lr, r9, r12, lsr #14 */
/* @0x154044 eorseq r0, r3, r8, lsl #28 */
/* @0x154048 eorseq r0, r3, r8, ror sp */
/* @0x15404c .word 0xffffbcec */
/* @0x154050 .word 0xffffdeb0 */
/* @0x154054 .word 0xffffdeb4 */
/* @0x154058 .word 0xffffdeb8 */
/* @0x15405c andseq r2, pc, r0, lsl #8 */
/* @0x154060 eoreq lr, r9, r0, lsl r6 */
/* @0x154064 andseq r2, pc, r4, ror #7 */
/* @0x154068 andseq r2, pc, r8, lsl r5 */
/* @0x15406c andseq r2, pc, r4, lsr #9 */
/* @0x154070 eorseq r0, r3, r0, lsr r12 */
/* @0x154074 ldrheq r2, [pc], -r12 */
/* @0x154078 andseq r2, pc, r0, lsl #7 */
/* @0x15407c .word 0xffffdebc */
/* @0x154080 .word 0xffffbfec */
/* @0x154084 andseq r2, pc, r8 */
/* @0x154088 andseq r2, pc, r12 */
/* @0x15408c ldrsheq r1, [pc], -r0 */
/* @0x154090 ldrsheq r0, [lr], -r0 */
/* @0x154094 mulseq sp, r12, r7 */
/* @0x154098 andseq r1, pc, r8, asr #29 */
/* @0x15409c andseq r1, pc, r4, lsl #27 */
/* @0x1540a0 andseq r1, pc, r8, ror #26 */
/* @0x1540a4 mulseq pc, r8, r12 */
/* @0x1540a8 andseq r1, pc, r12, lsr #21 */
/* @0x1540ac andseq r1, pc, r4, ror #22 */
/* @0x1540b0 .word 0xffffde74 */
/* @0x1540b4 .word 0xffffbcf0 */
/* @0x1540b8 andseq r1, pc, r12, lsl #21 */
/* @0x1540bc .word 0xffffde7c */
/* @0x1540c0 .word 0xffffde78 */
/* @0x1540c4 andseq r1, pc, r8, lsl #21 */
/* @0x1540c8 ldrsheq r1, [pc], -r8 */
/* @0x1540cc andseq r1, pc, r4, lsr #15 */
/* @0x1540d0 .word 0xffffde80 */
/* @0x1540d4 .word 0xffffde84 */
/* @0x1540d8 ldrheq r1, [pc], -r0 */
/* @0x1540dc ldr r3, [r3, #0x4] */
/* @0x1540e0 cmp r3, #0 */
/* @0x1540e4 beq 0x154160 <_Z19YYIAPEventsDispatchv+0x578> */
/* @0x1540e8 ldr r2, [r3, #0x8] */
/* @0x1540ec cmp r1, r2 */
/* @0x1540f0 bne 0x1540dc <_Z19YYIAPEventsDispatchv+0x4f4> */
/* @0x1540f4 ldr r3, [r3, #0xc] */
/* @0x1540f8 cmp r3, #0 */
/* @0x1540fc ldrne r6, [r3, #0xc4] */
/* @0x154100 beq 0x154160 <_Z19YYIAPEventsDispatchv+0x578> */
/* @0x154104 cmp r6, #0 */
/* @0x154108 beq 0x154160 <_Z19YYIAPEventsDispatchv+0x578> */
/* @0x15410c ldr r3, [r6, #0x8] */
/* @0x154110 cmp r3, #0 */
/* @0x154114 beq 0x154160 <_Z19YYIAPEventsDispatchv+0x578> */
/* @0x154118 ldr r0, [r6, #0x8] */
/* @0x15411c ldr r6, [r6] */
/* @0x154120 ldrb r3, [r0, #0x68] */
/* @0x154124 cmp r3, #0 */
/* @0x154128 bne 0x154104 <_Z19YYIAPEventsDispatchv+0x51c> */
/* @0x15412c ldrb r3, [r0, #0x69] */
/* @0x154130 cmp r3, #0 */
/* @0x154134 bne 0x154104 <_Z19YYIAPEventsDispatchv+0x51c> */
/* @0x154138 ldrd r2, r3, [r0, #112] */
/* @0x15413c cmp r4, r2 */
/* @0x154140 sbcs lr, r5, r3 */
/* @0x154144 blt 0x154104 <_Z19YYIAPEventsDispatchv+0x51c> */
/* @0x154148 mov r2, #7 */
/* @0x15414c mov r1, r0 */
/* @0x154150 mov r3, #66 */
/* @0x154154 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x154158 cmp r6, #0 */
/* @0x15415c bne 0x15410c <_Z19YYIAPEventsDispatchv+0x524> */
/* @0x154160 ldr r3, [r9, r8] */
/* @0x154164 add r7, r7, #1 */
/* @0x154168 cmp r3, r7 */
/* @0x15416c bgt 0x154000 <_Z19YYIAPEventsDispatchv+0x418> */
/* @0x154170 mov r10, r9 */
/* @0x154174 ldr r12, [r11, #-0x9c] */
/* @0x154178 ldr r0, [r11, #-0x98] */
/* @0x15417c add r12, r12, #1 */
/* @0x154180 str r12, [r11, #-0x9c] */
/* @0x154184 bl 0x205334 <_Z12DestroyDsMapi> */
/* @0x154188 ldr r12, [r11, #-0x9c] */
/* @0x15418c ldr lr, [r11, #-0xac] */
/* @0x154190 cmp r12, lr */
/* @0x154194 bne 0x153d64 <_Z19YYIAPEventsDispatchv+0x17c> */
/* @0x154198 b 0x153e18 <_Z19YYIAPEventsDispatchv+0x230> */
/* @0x15419c sub r12, r11, #88 */
/* @0x1541a0 ldr r1, [r11, #-0xe8] */
/* @0x1541a4 str r12, [r11, #-0x90] */
/* @0x1541a8 mov r0, r12 */
/* @0x1541ac bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x1541b0 mov r0, r9 */
/* @0x1541b4 ldr r1, [r11, #-0x90] */
/* @0x1541b8 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x1541bc ldr r3, [r11, #-0x4c] */
/* @0x1541c0 sub r3, r3, #1 */
/* @0x1541c4 bic r3, r3, #-16777216 */
/* @0x1541c8 bic r3, r3, #3 */
/* @0x1541cc cmp r3, #0 */
/* @0x1541d0 mov r4, r0 */
/* @0x1541d4 beq 0x154790 <_Z19YYIAPEventsDispatchv+0xba8> */
/* @0x1541d8 mov r5, #0 */
/* @0x1541dc mov r3, #5 */
/* @0x1541e0 str r5, [r11, #-0x50] */
/* @0x1541e4 str r5, [r11, #-0x58] */
/* @0x1541e8 str r3, [r11, #-0x4c] */
/* @0x1541ec ldr r2, [r4, #0x10] */
/* @0x1541f0 ldr r3, [r4, #0x14] */
/* @0x1541f4 vmov d7, r2, r3 */
/* @0x1541f8 vcvt.s32.f64 s18, d7 */
/* @0x1541fc vmov r0, s18 */
/* @0x154200 bl 0x27e8f4 <json_object_get_object> */
/* @0x154204 ldr r4, [r0, #0x20] */
/* @0x154208 cmp r4, r5 */
/* @0x15420c beq 0x154978 <_Z19YYIAPEventsDispatchv+0xd90> */
/* @0x154210 ldr r3, [pc, #-0x194] */
/* @0x154214 ldr r7, [pc, #-0x194] */
/* @0x154218 ldr r8, [pc, #-0x194] */
/* @0x15421c add r3, pc, r3 */
/* @0x154220 ldr r2, [pc, #-0x198] */
/* @0x154224 add r7, pc, r7 */
/* @0x154228 str r9, [r11, #-0xd4] */
/* @0x15422c add r8, pc, r8 */
/* @0x154230 add r2, pc, r2 */
/* @0x154234 str r5, [r11, #-0xc4] */
/* @0x154238 str r5, [r11, #-0xc0] */
/* @0x15423c mov r9, r3 */
/* @0x154240 str r5, [r11, #-0xb0] */
/* @0x154244 str r2, [r11, #-0xc8] */
/* @0x154248 b 0x154280 <_Z19YYIAPEventsDispatchv+0x698> */
/* @0x15424c mov r0, r5 */
/* @0x154250 mov r1, r8 */
/* @0x154254 bl 0xb66d0 <strcasecmp@plt> */
/* @0x154258 cmp r0, #0 */
/* @0x15425c beq 0x15475c <_Z19YYIAPEventsDispatchv+0xb74> */
/* @0x154260 mov r0, r5 */
/* @0x154264 mov r1, r9 */
/* @0x154268 bl 0xb66d0 <strcasecmp@plt> */
/* @0x15426c cmp r0, #0 */
/* @0x154270 beq 0x15476c <_Z19YYIAPEventsDispatchv+0xb84> */
/* @0x154274 ldr r4, [r4, #0x8] */
/* @0x154278 cmp r4, #0 */
/* @0x15427c beq 0x153e40 <_Z19YYIAPEventsDispatchv+0x258> */
/* @0x154280 ldr r5, [r4] */
/* @0x154284 mov r1, r7 */
/* @0x154288 ldr r6, [r4, #0x4] */
/* @0x15428c mov r0, r5 */
/* @0x154290 bl 0xb66d0 <strcasecmp@plt> */
/* @0x154294 cmp r0, #0 */
/* @0x154298 bne 0x15424c <_Z19YYIAPEventsDispatchv+0x664> */
/* @0x15429c mov r0, r6 */
/* @0x1542a0 bl 0x27ed58 <json_object_get_string> */
/* @0x1542a4 str r0, [r11, #-0xb0] */
/* @0x1542a8 b 0x154274 <_Z19YYIAPEventsDispatchv+0x68c> */
/* @0x1542ac ldr r1, [pc, #-0x220] */
/* @0x1542b0 sub r0, r11, #136 */
/* @0x1542b4 add r1, pc, r1 */
/* @0x1542b8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x1542bc mov r0, r9 */
/* @0x1542c0 sub r1, r11, #136 */
/* @0x1542c4 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x1542c8 ldr r3, [r11, #-0x7c] */
/* @0x1542cc sub r3, r3, #1 */
/* @0x1542d0 bic r3, r3, #-16777216 */
/* @0x1542d4 bic r3, r3, #3 */
/* @0x1542d8 cmp r3, #0 */
/* @0x1542dc mov r4, r0 */
/* @0x1542e0 beq 0x154960 <_Z19YYIAPEventsDispatchv+0xd78> */
/* @0x1542e4 ldr r3, [r4, #0x14] */
/* @0x1542e8 mov r1, #0 */
/* @0x1542ec ldr r2, [r4, #0x10] */
/* @0x1542f0 str r1, [r11, #-0x80] */
/* @0x1542f4 str r1, [r11, #-0x88] */
/* @0x1542f8 mov r1, #5 */
/* @0x1542fc mov r0, r2 */
/* @0x154300 str r1, [r11, #-0x7c] */
/* @0x154304 mov r1, r3 */
/* @0x154308 bl 0xb66e8 <lrint@plt> */
/* @0x15430c ldr r3, [pc, #-0x264] */
/* @0x154310 cmp r0, #0 */
/* @0x154314 beq 0x153ec4 <_Z19YYIAPEventsDispatchv+0x2dc> */
/* @0x154318 ldr r12, [r11, #-0x94] */
/* @0x15431c mvn r2, #0 */
/* @0x154320 ldr r3, [r12, r3] */
/* @0x154324 str r2, [r3] */
/* @0x154328 b 0x153fa0 <_Z19YYIAPEventsDispatchv+0x3b8> */
/* @0x15432c sub r8, r11, #120 */
/* @0x154330 ldr r1, [pc, #-0x2a0] */
/* @0x154334 mov r0, r8 */
/* @0x154338 add r1, pc, r1 */
/* @0x15433c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x154340 mov r0, r9 */
/* @0x154344 mov r1, r8 */
/* @0x154348 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x15434c ldr r3, [r11, #-0x6c] */
/* @0x154350 sub r3, r3, #1 */
/* @0x154354 bic r3, r3, #-16777216 */
/* @0x154358 bic r3, r3, #3 */
/* @0x15435c cmp r3, #0 */
/* @0x154360 mov r4, r0 */
/* @0x154364 beq 0x15496c <_Z19YYIAPEventsDispatchv+0xd84> */
/* @0x154368 mov r12, #0 */
/* @0x15436c mov r3, #5 */
/* @0x154370 str r12, [r11, #-0x70] */
/* @0x154374 sub lr, r11, #88 */
/* @0x154378 str r12, [r11, #-0x78] */
/* @0x15437c str r3, [r11, #-0x6c] */
/* @0x154380 ldr r2, [r4, #0x10] */
/* @0x154384 ldr r3, [r4, #0x14] */
/* @0x154388 str lr, [r11, #-0x90] */
/* @0x15438c mvn lr, #1 */
/* @0x154390 ldr r0, [r11, #-0x90] */
/* @0x154394 vmov d7, r2, r3 */
/* @0x154398 str r12, [r11, #-0x58] */
/* @0x15439c str r12, [r11, #-0x54] */
/* @0x1543a0 vcvt.s32.f64 s15, d7 */
/* @0x1543a4 str r12, [r11, #-0x50] */
/* @0x1543a8 str r12, [r11, #-0x4c] */
/* @0x1543ac str r12, [r11, #-0x48] */
/* @0x1543b0 str r12, [r11, #-0x40] */
/* @0x1543b4 str r12, [r11, #-0x44] */
/* @0x1543b8 str lr, [r11, #-0x3c] */
/* @0x1543bc vmov r1, s15 */
/* @0x1543c0 vmov r7, s15 */
/* @0x1543c4 bl 0x18ab40 <_ZN12CIAPPurchase11SetFromJSONEP11json_object> */
/* @0x1543c8 mov r5, r0 */
/* @0x1543cc ldr r0, [r11, #-0x54] */
/* @0x1543d0 cmp r0, #0 */
/* @0x1543d4 beq 0x154470 <_Z19YYIAPEventsDispatchv+0x888> */
/* @0x1543d8 ldr r3, [pc, #-0x324] */
/* @0x1543dc cmp r5, #0 */
/* @0x1543e0 ldr r12, [r11, #-0x94] */
/* @0x1543e4 ldr r6, [r12, r3] */
/* @0x1543e8 blt 0x15440c <_Z19YYIAPEventsDispatchv+0x824> */
/* @0x1543ec ldr r3, [r6, #0x4] */
/* @0x1543f0 ldr r4, [r3, r5, lsl #2] */
/* @0x1543f4 ldr r1, [r4, #0x4] */
/* @0x1543f8 cmp r1, #0 */
/* @0x1543fc beq 0x15440c <_Z19YYIAPEventsDispatchv+0x824> */
/* @0x154400 bl 0xb66d0 <strcasecmp@plt> */
/* @0x154404 cmp r0, #0 */
/* @0x154408 beq 0x154464 <_Z19YYIAPEventsDispatchv+0x87c> */
/* @0x15440c sub r4, r11, #104 */
/* @0x154410 ldr r1, [r11, #-0x58] */
/* @0x154414 mov r0, r4 */
/* @0x154418 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x15441c mov r0, r4 */
/* @0x154420 bl 0x1533a0 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x154424 ldr r3, [r11, #-0x5c] */
/* @0x154428 sub r3, r3, #1 */
/* @0x15442c bic r3, r3, #-16777216 */
/* @0x154430 bic r3, r3, #3 */
/* @0x154434 cmp r3, #0 */
/* @0x154438 mov r5, r0 */
/* @0x15443c beq 0x154a60 <_Z19YYIAPEventsDispatchv+0xe78> */
/* @0x154440 cmp r5, #0 */
/* @0x154444 mov r3, #0 */
/* @0x154448 mov r2, #5 */
/* @0x15444c str r3, [r11, #-0x60] */
/* @0x154450 str r3, [r11, #-0x68] */
/* @0x154454 str r2, [r11, #-0x5c] */
/* @0x154458 blt 0x154a44 <_Z19YYIAPEventsDispatchv+0xe5c> */
/* @0x15445c ldr r3, [r6, #0x4] */
/* @0x154460 ldr r4, [r3, r5, lsl #2] */
/* @0x154464 mov r0, r4 */
/* @0x154468 ldr r1, [r11, #-0x90] */
/* @0x15446c bl 0x18aa6c <_ZN12CIAPPurchase15SetFromPurchaseERKS_> */
/* @0x154470 vmov s15, r5 */
/* @0x154474 ldr r1, [pc, #-0x3e0] */
/* @0x154478 mov r4, #0 */
/* @0x15447c mov r0, r9 */
/* @0x154480 vcvt.f64.s32 d7, s15 */
/* @0x154484 add r1, pc, r1 */
/* @0x154488 str r4, [sp] */
/* @0x15448c vmov r2, r3, d7 */
/* @0x154490 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x154494 vldr s15, [r11, #-68] */
/* @0x154498 vcvt.f64.s32 d7, s15 */
/* @0x15449c ldr r1, [pc, #-0x404] */
/* @0x1544a0 str r4, [sp] */
/* @0x1544a4 mov r0, r9 */
/* @0x1544a8 add r1, pc, r1 */
/* @0x1544ac vmov r2, r3, d7 */
/* @0x1544b0 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x1544b4 mov r0, r9 */
/* @0x1544b8 mov r1, r8 */
/* @0x1544bc bl 0x20b6cc <_ZN7CDS_Map6DeleteEP6RValue> */
/* @0x1544c0 mov r0, r7 */
/* @0x1544c4 bl 0x27e7c8 <json_object_put> */
/* @0x1544c8 ldr r0, [r11, #-0x58] */
/* @0x1544cc cmp r0, r4 */
/* @0x1544d0 beq 0x1544dc <_Z19YYIAPEventsDispatchv+0x8f4> */
/* @0x1544d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1544d8 str r4, [r11, #-0x58] */
/* @0x1544dc ldr r0, [r11, #-0x54] */
/* @0x1544e0 cmp r0, #0 */
/* @0x1544e4 beq 0x1544f4 <_Z19YYIAPEventsDispatchv+0x90c> */
/* @0x1544e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1544ec mov r3, #0 */
/* @0x1544f0 str r3, [r11, #-0x54] */
/* @0x1544f4 ldr r0, [r11, #-0x50] */
/* @0x1544f8 cmp r0, #0 */
/* @0x1544fc beq 0x15450c <_Z19YYIAPEventsDispatchv+0x924> */
/* @0x154500 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x154504 mov r3, #0 */
/* @0x154508 str r3, [r11, #-0x50] */
/* @0x15450c ldr r0, [r11, #-0x4c] */
/* @0x154510 cmp r0, #0 */
/* @0x154514 beq 0x154524 <_Z19YYIAPEventsDispatchv+0x93c> */
/* @0x154518 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x15451c mov r3, #0 */
/* @0x154520 str r3, [r11, #-0x4c] */
/* @0x154524 ldr r0, [r11, #-0x48] */
/* @0x154528 cmp r0, #0 */
/* @0x15452c beq 0x154534 <_Z19YYIAPEventsDispatchv+0x94c> */
/* @0x154530 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x154534 ldr r3, [pc, #-0x48c] */
/* @0x154538 ldr r12, [r11, #-0x94] */
/* @0x15453c ldr r3, [r12, r3] */
/* @0x154540 ldr r2, [r3] */
/* @0x154544 cmp r2, #3 */
/* @0x154548 cmpne r2, #0 */
/* @0x15454c beq 0x153fa0 <_Z19YYIAPEventsDispatchv+0x3b8> */
/* @0x154550 mov r2, #1 */
/* @0x154554 str r2, [r3] */
/* @0x154558 b 0x153ed4 <_Z19YYIAPEventsDispatchv+0x2ec> */
/* @0x15455c sub r8, r11, #120 */
/* @0x154560 ldr r1, [pc, #-0x4c4] */
/* @0x154564 mov r0, r8 */
/* @0x154568 add r1, pc, r1 */
/* @0x15456c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x154570 mov r0, r9 */
/* @0x154574 mov r1, r8 */
/* @0x154578 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x15457c ldr r3, [r11, #-0x6c] */
/* @0x154580 sub r3, r3, #1 */
/* @0x154584 bic r3, r3, #-16777216 */
/* @0x154588 bic r3, r3, #3 */
/* @0x15458c cmp r3, #0 */
/* @0x154590 mov r4, r0 */
/* @0x154594 beq 0x154954 <_Z19YYIAPEventsDispatchv+0xd6c> */
/* @0x154598 mov r12, #0 */
/* @0x15459c mov r3, #5 */
/* @0x1545a0 str r12, [r11, #-0x70] */
/* @0x1545a4 sub lr, r11, #88 */
/* @0x1545a8 str r12, [r11, #-0x78] */
/* @0x1545ac str r3, [r11, #-0x6c] */
/* @0x1545b0 mov r0, lr */
/* @0x1545b4 ldr r2, [r4, #0x10] */
/* @0x1545b8 ldr r3, [r4, #0x14] */
/* @0x1545bc str lr, [r11, #-0x90] */
/* @0x1545c0 str r12, [r11, #-0x58] */
/* @0x1545c4 vmov d7, r2, r3 */
/* @0x1545c8 str r12, [r11, #-0x54] */
/* @0x1545cc str r12, [r11, #-0x50] */
/* @0x1545d0 vcvt.s32.f64 s18, d7 */
/* @0x1545d4 str r12, [r11, #-0x4c] */
/* @0x1545d8 str r12, [r11, #-0x48] */
/* @0x1545dc strb r12, [r11, #-0x44] */
/* @0x1545e0 vmov r1, s18 */
/* @0x1545e4 bl 0x18b168 <_ZN11CIAPProduct11SetFromJSONEP11json_object> */
/* @0x1545e8 ldr r1, [r11, #-0x58] */
/* @0x1545ec cmp r1, #0 */
/* @0x1545f0 beq 0x1549ac <_Z19YYIAPEventsDispatchv+0xdc4> */
/* @0x1545f4 sub r4, r11, #104 */
/* @0x1545f8 mov r0, r4 */
/* @0x1545fc bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x154600 mov r0, r4 */
/* @0x154604 bl 0x15327c <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x154608 ldr r3, [r11, #-0x5c] */
/* @0x15460c sub r3, r3, #1 */
/* @0x154610 bic r3, r3, #-16777216 */
/* @0x154614 bic r3, r3, #3 */
/* @0x154618 cmp r3, #0 */
/* @0x15461c mov r7, r0 */
/* @0x154620 beq 0x1549a0 <_Z19YYIAPEventsDispatchv+0xdb8> */
/* @0x154624 cmp r7, #0 */
/* @0x154628 mov r4, #0 */
/* @0x15462c mov r3, #5 */
/* @0x154630 str r4, [r11, #-0x60] */
/* @0x154634 str r4, [r11, #-0x68] */
/* @0x154638 str r3, [r11, #-0x5c] */
/* @0x15463c blt 0x1549b8 <_Z19YYIAPEventsDispatchv+0xdd0> */
/* @0x154640 ldr r3, [pc, #-0x574] */
/* @0x154644 lsl r6, r7, #2 */
/* @0x154648 ldr r12, [r11, #-0x94] */
/* @0x15464c ldr r5, [r12, r3] */
/* @0x154650 ldr r3, [r5, #0x4] */
/* @0x154654 ldr r1, [r11, #-0x90] */
/* @0x154658 ldr r0, [r3, r6] */
/* @0x15465c bl 0x18b04c <_ZN11CIAPProduct14SetFromProductERKS_> */
/* @0x154660 ldr r3, [r5, #0x4] */
/* @0x154664 mov r2, #1 */
/* @0x154668 ldr r3, [r3, r6] */
/* @0x15466c strb r2, [r3, #0x14] */
/* @0x154670 ldr r3, [r11, #-0x58] */
/* @0x154674 ldr r1, [pc, #-0x5d4] */
/* @0x154678 mov r2, #0 */
/* @0x15467c str r3, [sp] */
/* @0x154680 mov r0, r9 */
/* @0x154684 add r1, pc, r1 */
/* @0x154688 mov r3, #0 */
/* @0x15468c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x154690 vmov s15, r7 */
/* @0x154694 ldr r1, [pc, #-0x5f0] */
/* @0x154698 mov r4, #0 */
/* @0x15469c vcvt.f64.s32 d7, s15 */
/* @0x1546a0 str r4, [sp] */
/* @0x1546a4 add r1, pc, r1 */
/* @0x1546a8 mov r0, r9 */
/* @0x1546ac vmov r2, r3, d7 */
/* @0x1546b0 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x1546b4 mov r0, r9 */
/* @0x1546b8 mov r1, r8 */
/* @0x1546bc bl 0x20b6cc <_ZN7CDS_Map6DeleteEP6RValue> */
/* @0x1546c0 vmov r0, s18 */
/* @0x1546c4 bl 0x27e7c8 <json_object_put> */
/* @0x1546c8 ldr r0, [r11, #-0x58] */
/* @0x1546cc cmp r0, r4 */
/* @0x1546d0 beq 0x1546dc <_Z19YYIAPEventsDispatchv+0xaf4> */
/* @0x1546d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1546d8 str r4, [r11, #-0x58] */
/* @0x1546dc ldr r0, [r11, #-0x54] */
/* @0x1546e0 cmp r0, #0 */
/* @0x1546e4 beq 0x1546f4 <_Z19YYIAPEventsDispatchv+0xb0c> */
/* @0x1546e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1546ec mov r3, #0 */
/* @0x1546f0 str r3, [r11, #-0x54] */
/* @0x1546f4 ldr r0, [r11, #-0x50] */
/* @0x1546f8 cmp r0, #0 */
/* @0x1546fc beq 0x15470c <_Z19YYIAPEventsDispatchv+0xb24> */
/* @0x154700 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x154704 mov r3, #0 */
/* @0x154708 str r3, [r11, #-0x50] */
/* @0x15470c ldr r0, [r11, #-0x4c] */
/* @0x154710 cmp r0, #0 */
/* @0x154714 beq 0x154724 <_Z19YYIAPEventsDispatchv+0xb3c> */
/* @0x154718 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x15471c mov r3, #0 */
/* @0x154720 str r3, [r11, #-0x4c] */
/* @0x154724 ldr r0, [r11, #-0x48] */
/* @0x154728 cmp r0, #0 */
/* @0x15472c beq 0x154734 <_Z19YYIAPEventsDispatchv+0xb4c> */
/* @0x154730 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x154734 ldr r3, [pc, #-0x68c] */
/* @0x154738 ldr r12, [r11, #-0x94] */
/* @0x15473c ldr r3, [r12, r3] */
/* @0x154740 ldr r2, [r3] */
/* @0x154744 cmp r2, #0 */
/* @0x154748 beq 0x153fa0 <_Z19YYIAPEventsDispatchv+0x3b8> */
/* @0x15474c b 0x154550 <_Z19YYIAPEventsDispatchv+0x968> */
/* @0x154750 sub r0, r11, #136 */
/* @0x154754 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x154758 b 0x153dc4 <_Z19YYIAPEventsDispatchv+0x1dc> */
/* @0x15475c mov r0, r6 */
/* @0x154760 bl 0x27ed58 <json_object_get_string> */
/* @0x154764 str r0, [r11, #-0xc4] */
/* @0x154768 b 0x154274 <_Z19YYIAPEventsDispatchv+0x68c> */
/* @0x15476c mov r0, r6 */
/* @0x154770 bl 0x27ed58 <json_object_get_string> */
/* @0x154774 mov r1, r0 */
/* @0x154778 ldr r0, [r11, #-0xc8] */
/* @0x15477c bl 0xb66d0 <strcasecmp@plt> */
/* @0x154780 rsbs r0, r0, #1 */
/* @0x154784 movlo r0, #0 */
/* @0x154788 str r0, [r11, #-0xc0] */
/* @0x15478c b 0x154274 <_Z19YYIAPEventsDispatchv+0x68c> */
/* @0x154790 ldr r0, [r11, #-0x90] */
/* @0x154794 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x154798 b 0x1541d8 <_Z19YYIAPEventsDispatchv+0x5f0> */
/* @0x15479c ldr r12, [r11, #-0x94] */
/* @0x1547a0 ldr r3, [pc, #-0x6f4] */
/* @0x1547a4 ldr r1, [pc, #-0x6f4] */
/* @0x1547a8 ldr r2, [r11, #-0xb0] */
/* @0x1547ac ldr r3, [r12, r3] */
/* @0x1547b0 add r1, pc, r1 */
/* @0x1547b4 ldr r3, [r3] */
/* @0x1547b8 str r3, [r11, #-0xc0] */
/* @0x1547bc ldr r3, [r3] */
/* @0x1547c0 ldr r0, [r11, #-0xc0] */
/* @0x1547c4 ldr r3, [r3, #0xc] */
/* @0x1547c8 blx r3 */
/* @0x1547cc ldr r3, [pc, #-0x718] */
/* @0x1547d0 ldr r12, [r11, #-0x94] */
/* @0x1547d4 ldr r6, [r12, r3] */
/* @0x1547d8 ldr r3, [r6] */
/* @0x1547dc cmp r3, #0 */
/* @0x1547e0 ble 0x154924 <_Z19YYIAPEventsDispatchv+0xd3c> */
/* @0x1547e4 ldr r3, [pc, #-0x72c] */
/* @0x1547e8 ldr r3, [r12, r3] */
/* @0x1547ec str r3, [r11, #-0xc8] */
/* @0x1547f0 ldr r3, [r3] */
/* @0x1547f4 cmp r3, #0 */
/* @0x1547f8 ble 0x154924 <_Z19YYIAPEventsDispatchv+0xd3c> */
/* @0x1547fc ldr r3, [pc, #-0x740] */
/* @0x154800 mov r7, r4 */
/* @0x154804 mov r8, r4 */
/* @0x154808 add r3, pc, r3 */
/* @0x15480c str r3, [r11, #-0xe0] */
/* @0x154810 ldr r3, [r6, #0x4] */
/* @0x154814 lsl r4, r7, #2 */
/* @0x154818 ldr r3, [r3, r7, lsl #2] */
/* @0x15481c cmp r3, #0 */
/* @0x154820 beq 0x154910 <_Z19YYIAPEventsDispatchv+0xd28> */
/* @0x154824 ldr r0, [r3, #0x4] */
/* @0x154828 cmp r0, #0 */
/* @0x15482c beq 0x154910 <_Z19YYIAPEventsDispatchv+0xd28> */
/* @0x154830 ldr r5, [r3, #0xc] */
/* @0x154834 cmp r5, #0 */
/* @0x154838 beq 0x154910 <_Z19YYIAPEventsDispatchv+0xd28> */
/* @0x15483c ldr r1, [r11, #-0xb0] */
/* @0x154840 bl 0xb6574 <strcmp@plt> */
/* @0x154844 cmp r0, #0 */
/* @0x154848 bne 0x154910 <_Z19YYIAPEventsDispatchv+0xd28> */
/* @0x15484c mov r0, r5 */
/* @0x154850 ldr r1, [r11, #-0xc4] */
/* @0x154854 bl 0xb6574 <strcmp@plt> */
/* @0x154858 cmp r0, #0 */
/* @0x15485c str r0, [r11, #-0xd4] */
/* @0x154860 bne 0x154910 <_Z19YYIAPEventsDispatchv+0xd28> */
/* @0x154864 ldr r12, [r11, #-0xc0] */
/* @0x154868 mov r2, r7 */
/* @0x15486c ldr r1, [r11, #-0xe0] */
/* @0x154870 ldr r3, [r12] */
/* @0x154874 mov r0, r12 */
/* @0x154878 ldr r3, [r3, #0xc] */
/* @0x15487c blx r3 */
/* @0x154880 ldr r3, [r6, #0x4] */
/* @0x154884 add r2, r3, r4 */
/* @0x154888 ldr r5, [r3, r4] */
/* @0x15488c cmp r5, #0 */
/* @0x154890 beq 0x15490c <_Z19YYIAPEventsDispatchv+0xd24> */
/* @0x154894 ldr r0, [r5] */
/* @0x154898 cmp r0, #0 */
/* @0x15489c beq 0x1548ac <_Z19YYIAPEventsDispatchv+0xcc4> */
/* @0x1548a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1548a4 ldr r12, [r11, #-0xd4] */
/* @0x1548a8 str r12, [r5] */
/* @0x1548ac ldr r0, [r5, #0x4] */
/* @0x1548b0 cmp r0, #0 */
/* @0x1548b4 beq 0x1548c0 <_Z19YYIAPEventsDispatchv+0xcd8> */
/* @0x1548b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1548bc str r8, [r5, #0x4] */
/* @0x1548c0 ldr r0, [r5, #0x8] */
/* @0x1548c4 cmp r0, #0 */
/* @0x1548c8 beq 0x1548d4 <_Z19YYIAPEventsDispatchv+0xcec> */
/* @0x1548cc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1548d0 str r8, [r5, #0x8] */
/* @0x1548d4 ldr r0, [r5, #0xc] */
/* @0x1548d8 cmp r0, #0 */
/* @0x1548dc beq 0x1548e8 <_Z19YYIAPEventsDispatchv+0xd00> */
/* @0x1548e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1548e4 str r8, [r5, #0xc] */
/* @0x1548e8 ldr r0, [r5, #0x10] */
/* @0x1548ec cmp r0, #0 */
/* @0x1548f0 beq 0x1548fc <_Z19YYIAPEventsDispatchv+0xd14> */
/* @0x1548f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1548f8 str r8, [r5, #0x10] */
/* @0x1548fc mov r0, r5 */
/* @0x154900 bl 0x27d1d0 <_ZdlPv> */
/* @0x154904 ldr r2, [r6, #0x4] */
/* @0x154908 add r2, r2, r4 */
/* @0x15490c str r8, [r2] */
/* @0x154910 ldr r12, [r11, #-0xc8] */
/* @0x154914 add r7, r7, #1 */
/* @0x154918 ldr r3, [r12] */
/* @0x15491c cmp r7, r3 */
/* @0x154920 blt 0x154810 <_Z19YYIAPEventsDispatchv+0xc28> */
/* @0x154924 ldr r3, [r11, #-0xb0] */
/* @0x154928 mov r2, #0 */
/* @0x15492c ldr r1, [pc, #-0x86c] */
/* @0x154930 mov r0, r9 */
/* @0x154934 str r3, [sp] */
/* @0x154938 add r1, pc, r1 */
/* @0x15493c mov r3, #0 */
/* @0x154940 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x154944 mov r3, #0 */
/* @0x154948 mov r2, #0 */
/* @0x15494c movt r3, #0x3ff0 */
/* @0x154950 b 0x153e94 <_Z19YYIAPEventsDispatchv+0x2ac> */
/* @0x154954 mov r0, r8 */
/* @0x154958 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x15495c b 0x154598 <_Z19YYIAPEventsDispatchv+0x9b0> */
/* @0x154960 sub r0, r11, #136 */
/* @0x154964 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x154968 b 0x1542e4 <_Z19YYIAPEventsDispatchv+0x6fc> */
/* @0x15496c mov r0, r8 */
/* @0x154970 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x154974 b 0x154368 <_Z19YYIAPEventsDispatchv+0x780> */
/* @0x154978 ldr r1, [pc, #-0x8b4] */
/* @0x15497c mov r2, #0 */
/* @0x154980 mov r3, #0 */
/* @0x154984 str r4, [sp] */
/* @0x154988 mov r0, r9 */
/* @0x15498c add r1, pc, r1 */
/* @0x154990 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_> */
/* @0x154994 mov r2, #0 */
/* @0x154998 mov r3, #0 */
/* @0x15499c b 0x153e94 <_Z19YYIAPEventsDispatchv+0x2ac> */
/* @0x1549a0 mov r0, r4 */
/* @0x1549a4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1549a8 b 0x154624 <_Z19YYIAPEventsDispatchv+0xa3c> */
/* @0x1549ac mov r3, r1 */
/* @0x1549b0 mvn r7, #0 */
/* @0x1549b4 b 0x154674 <_Z19YYIAPEventsDispatchv+0xa8c> */
/* @0x1549b8 ldr r12, [r11, #-0x94] */
/* @0x1549bc ldr r3, [pc, #-0x8f4] */
/* @0x1549c0 ldr r2, [pc, #-0x8f4] */
/* @0x1549c4 ldr lr, [r11, #-0x94] */
/* @0x1549c8 ldr r3, [r12, r3] */
/* @0x1549cc ldr r7, [r3] */
/* @0x1549d0 add r12, r7, #1 */
/* @0x1549d4 str r12, [r3] */
/* @0x1549d8 ldr r5, [lr, r2] */
/* @0x1549dc ldr r3, [r5] */
/* @0x1549e0 cmp r7, r3 */
/* @0x1549e4 lsllt r6, r7, #2 */
/* @0x1549e8 blt 0x154650 <_Z19YYIAPEventsDispatchv+0xa68> */
/* @0x1549ec lsl r6, r12, #2 */
/* @0x1549f0 ldr r2, [pc, #-0x920] */
/* @0x1549f4 add r0, r5, #4 */
/* @0x1549f8 movw r3, #0x219 */
/* @0x1549fc add r2, pc, r2 */
/* @0x154a00 mov r1, r6 */
/* @0x154a04 str r12, [r11, #-0xec] */
/* @0x154a08 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x154a0c ldr r12, [r11, #-0xec] */
/* @0x154a10 mov r0, #24 */
/* @0x154a14 sub r6, r6, #4 */
/* @0x154a18 str r12, [r5] */
/* @0x154a1c bl 0x27c524 <_Znwj> */
/* @0x154a20 ldr r2, [r5, #0x4] */
/* @0x154a24 str r4, [r0, #0x8] */
/* @0x154a28 str r4, [r0] */
/* @0x154a2c str r4, [r0, #0x4] */
/* @0x154a30 str r4, [r0, #0xc] */
/* @0x154a34 str r4, [r0, #0x10] */
/* @0x154a38 strb r4, [r0, #0x14] */
/* @0x154a3c str r0, [r2, r6] */
/* @0x154a40 b 0x154650 <_Z19YYIAPEventsDispatchv+0xa68> */
/* @0x154a44 ldr r0, [r11, #-0x54] */
/* @0x154a48 bl 0x15314c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x154a4c subs r5, r0, #0 */
/* @0x154a50 bge 0x15445c <_Z19YYIAPEventsDispatchv+0x874> */
/* @0x154a54 bl 0x153020 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x154a58 mov r5, r0 */
/* @0x154a5c b 0x15445c <_Z19YYIAPEventsDispatchv+0x874> */
/* @0x154a60 mov r0, r4 */
/* @0x154a64 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x154a68 b 0x154440 <_Z19YYIAPEventsDispatchv+0x858> */
/* @0x154a6c bl 0xb65d4 <__stack_chk_fail@plt> */

/* ── FUNC 0x154a70 · anon_154a70 · size=352 · insn=89 */
/* @0x154a70 push {r0, r1, r2, r3} */
/* @0x154a74 mov r0, #4 */
/* @0x154a78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x154a7c sub sp, sp, #68 */
/* @0x154a80 bl 0x27c524 <_Znwj> */
/* @0x154a84 mov r8, r0 */
/* @0x154a88 bl 0x203624 <_ZN7CDS_MapC2Ev> */
/* @0x154a8c ldr r3, [sp, #0x68] */
/* @0x154a90 add r12, sp, #108 */
/* @0x154a94 str r12, [sp, #0x1c] */
/* @0x154a98 cmp r3, #0 */
/* @0x154a9c ble 0x154bc0 <_Z19YYIAPEventsDispatchv+0xfd8> */
/* @0x154aa0 add r7, sp, #32 */
/* @0x154aa4 mov r6, #0 */
/* @0x154aa8 add r3, sp, #40 */
/* @0x154aac add r11, sp, #36 */
/* @0x154ab0 str r3, [sp, #0x10] */
/* @0x154ab4 add r5, sp, #48 */
/* @0x154ab8 add r3, sp, #44 */
/* @0x154abc mov r10, r12 */
/* @0x154ac0 str r3, [sp, #0x14] */
/* @0x154ac4 mov r4, r7 */
/* @0x154ac8 add r3, sp, #52 */
/* @0x154acc mov r9, r6 */
/* @0x154ad0 str r3, [sp, #0x4] */
/* @0x154ad4 add r3, sp, #56 */
/* @0x154ad8 str r3, [sp, #0x8] */
/* @0x154adc add r3, sp, #60 */
/* @0x154ae0 str r3, [sp, #0xc] */
/* @0x154ae4 b 0x154b1c <_Z19YYIAPEventsDispatchv+0xf34> */
/* @0x154ae8 ldr r2, [sp, #0x3c] */
/* @0x154aec mov r3, #5 */
/* @0x154af0 str r9, [sp, #0x28] */
/* @0x154af4 sub r2, r2, #1 */
/* @0x154af8 str r3, [sp, #0x2c] */
/* @0x154afc bic r2, r2, #-16777216 */
/* @0x154b00 str r9, [sp, #0x20] */
/* @0x154b04 bic r2, r2, #3 */
/* @0x154b08 cmp r2, #0 */
/* @0x154b0c beq 0x154bac <_Z19YYIAPEventsDispatchv+0xfc4> */
/* @0x154b10 ldr r3, [sp, #0x68] */
/* @0x154b14 cmp r6, r3 */
/* @0x154b18 beq 0x154bc0 <_Z19YYIAPEventsDispatchv+0xfd8> */
/* @0x154b1c ldr r1, [r10], #11 */
/* @0x154b20 mov r0, r4 */
/* @0x154b24 str r9, [r7] */
/* @0x154b28 add r6, r6, #1 */
/* @0x154b2c str r9, [r11] */
/* @0x154b30 mov r7, r4 */
/* @0x154b34 str r9, [sp, #0x28] */
/* @0x154b38 str r9, [sp, #0x2c] */
/* @0x154b3c str r9, [r5] */
/* @0x154b40 str r9, [sp, #0x34] */
/* @0x154b44 str r9, [sp, #0x38] */
/* @0x154b48 str r9, [sp, #0x3c] */
/* @0x154b4c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x154b50 bic r2, r10, #7 */
/* @0x154b54 mov r0, r5 */
/* @0x154b58 add r10, r2, #12 */
/* @0x154b5c vldr d7, [r2] */
/* @0x154b60 ldr r1, [r2, #0x8] */
/* @0x154b64 vstr d7, [sp, #48] */
/* @0x154b68 str r10, [sp, #0x1c] */
/* @0x154b6c cmp r1, #0 */
/* @0x154b70 beq 0x154b78 <_Z19YYIAPEventsDispatchv+0xf90> */
/* @0x154b74 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x154b78 mov r2, r5 */
/* @0x154b7c mov r0, r8 */
/* @0x154b80 mov r1, r4 */
/* @0x154b84 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x154b88 ldr r2, [sp, #0x2c] */
/* @0x154b8c sub r2, r2, #1 */
/* @0x154b90 bic r2, r2, #-16777216 */
/* @0x154b94 bic r2, r2, #3 */
/* @0x154b98 cmp r2, #0 */
/* @0x154b9c bne 0x154ae8 <_Z19YYIAPEventsDispatchv+0xf00> */
/* @0x154ba0 mov r0, r4 */
/* @0x154ba4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x154ba8 b 0x154ae8 <_Z19YYIAPEventsDispatchv+0xf00> */
/* @0x154bac mov r0, r5 */
/* @0x154bb0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x154bb4 ldr r3, [sp, #0x68] */
/* @0x154bb8 cmp r6, r3 */
/* @0x154bbc bne 0x154b1c <_Z19YYIAPEventsDispatchv+0xf34> */
/* @0x154bc0 mov r0, r8 */
/* @0x154bc4 add sp, sp, #68 */
/* @0x154bc8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x154bcc add sp, sp, #16 */
/* @0x154bd0 bx lr */

/* ── FUNC 0x154bd4 · F_IAP_Activate(RValue&, CInstance*, CInstance*, int, RValue*) · size=1176 · insn=294 */
/* @0x154bd4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x154bd8 vpush {d8} */
/* @0x154bdc cmp r3, #0 */
/* @0x154be0 sub sp, sp, #100 */
/* @0x154be4 ldr r4, [pc, #0x464] */
/* @0x154be8 mov r8, r0 */
/* @0x154bec add r4, pc, r4 */
/* @0x154bf0 str r1, [sp, #0xc] */
/* @0x154bf4 str r2, [sp, #0x10] */
/* @0x154bf8 ldr r12, [sp, #0x90] */
/* @0x154bfc ble 0x154c3c <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x154c00 ldr r9, [r12, #0xc] */
/* @0x154c04 cmp r9, #0 */
/* @0x154c08 beq 0x154c48 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x154c0c cmp r9, #1 */
/* @0x154c10 beq 0x154df8 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x154c14 ldr r1, [pc, #0x438] */
/* @0x154c18 mov r4, #0 */
/* @0x154c1c mov r0, #1 */
/* @0x154c20 str r4, [sp] */
/* @0x154c24 add r1, pc, r1 */
/* @0x154c28 mov r2, #0 */
/* @0x154c2c mov r3, #0 */
/* @0x154c30 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88> */
/* @0x154c34 mov r1, r4 */
/* @0x154c38 bl 0x153acc <_Z16InitIAPFunctionsv+0x5f8> */
/* @0x154c3c add sp, sp, #100 */
/* @0x154c40 vpop {d8} */
/* @0x154c44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x154c48 mov r0, r12 */
/* @0x154c4c mov r1, r9 */
/* @0x154c50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x154c54 add r1, sp, #48 */
/* @0x154c58 str r1, [sp, #0x8] */
/* @0x154c5c mov r3, #1 */
/* @0x154c60 add r7, sp, #64 */
/* @0x154c64 mov r1, r9 */
/* @0x154c68 str r7, [sp] */
/* @0x154c6c mov r2, r9 */
/* @0x154c70 str r9, [sp, #0x30] */
/* @0x154c74 str r9, [sp, #0x4c] */
/* @0x154c78 vmov s13, r0 */
/* @0x154c7c ldr r0, [sp, #0x8] */
/* @0x154c80 vcvt.f64.s32 d7, s13 */
/* @0x154c84 vstr d7, [sp, #64] */
/* @0x154c88 bl 0xfc350 <_Z12F_DsListSizeR6RValueP9CInstanceS2_iPS_> */
/* @0x154c8c ldr r3, [pc, #0x3c4] */
/* @0x154c90 ldr r6, [r4, r3] */
/* @0x154c94 ldr r3, [r6] */
/* @0x154c98 cmp r3, #0 */
/* @0x154c9c ble 0x154d44 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x154ca0 ldr r3, [pc, #0x3b4] */
/* @0x154ca4 mov r10, r9 */
/* @0x154ca8 ldr r5, [r4, r3] */
/* @0x154cac ldr r3, [r5, #0x4] */
/* @0x154cb0 lsl r11, r9, #2 */
/* @0x154cb4 ldr r8, [r3, r9, lsl #2] */
/* @0x154cb8 cmp r8, #0 */
/* @0x154cbc beq 0x154d34 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x154cc0 ldr r0, [r8] */
/* @0x154cc4 cmp r0, #0 */
/* @0x154cc8 beq 0x154cd4 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x154ccc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x154cd0 str r10, [r8] */
/* @0x154cd4 ldr r0, [r8, #0x4] */
/* @0x154cd8 cmp r0, #0 */
/* @0x154cdc beq 0x154ce8 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x154ce0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x154ce4 str r10, [r8, #0x4] */
/* @0x154ce8 ldr r0, [r8, #0x8] */
/* @0x154cec cmp r0, #0 */
/* @0x154cf0 beq 0x154cfc <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x154cf4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x154cf8 str r10, [r8, #0x8] */
/* @0x154cfc ldr r0, [r8, #0xc] */
/* @0x154d00 cmp r0, #0 */
/* @0x154d04 beq 0x154d10 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x154d08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x154d0c str r10, [r8, #0xc] */
/* @0x154d10 ldr r0, [r8, #0x10] */
/* @0x154d14 cmp r0, #0 */
/* @0x154d18 beq 0x154d24 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x154d1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x154d20 str r10, [r8, #0x10] */
/* @0x154d24 mov r0, r8 */
/* @0x154d28 bl 0x27d1d0 <_ZdlPv> */
/* @0x154d2c ldr r3, [r5, #0x4] */
/* @0x154d30 str r10, [r3, r11] */
/* @0x154d34 ldr r3, [r6] */
/* @0x154d38 add r9, r9, #1 */
/* @0x154d3c cmp r9, r3 */
/* @0x154d40 blt 0x154cac <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x154d44 vldr d7, [sp, #48] */
/* @0x154d48 vcvt.s32.f64 s13, d7 */
/* @0x154d4c vmov r9, s13 */
/* @0x154d50 cmp r9, r3 */
/* @0x154d54 bgt 0x154fa0 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x3cc> */
/* @0x154d58 cmp r9, #0 */
/* @0x154d5c ble 0x154c14 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x154d60 ldr r8, [sp, #0x8] */
/* @0x154d64 mov r5, #0 */
/* @0x154d68 mov r6, r5 */
/* @0x154d6c vmov s13, r5 */
/* @0x154d70 mov r1, #0 */
/* @0x154d74 mov r0, r8 */
/* @0x154d78 str r7, [sp] */
/* @0x154d7c vcvt.f64.s32 d7, s13 */
/* @0x154d80 mov r2, r1 */
/* @0x154d84 mov r3, #2 */
/* @0x154d88 str r6, [sp, #0x5c] */
/* @0x154d8c vstr d7, [sp, #80] */
/* @0x154d90 bl 0x106634 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_> */
/* @0x154d94 vldr d8, [sp, #48] */
/* @0x154d98 vcmpe.f64 d8, #0 */
/* @0x154d9c mov r0, #24 */
/* @0x154da0 vmrs APSR_nzcv, fpscr */
/* @0x154da4 blt 0x154de8 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x154da8 bl 0x27c524 <_Znwj> */
/* @0x154dac ldr r3, [pc, #0x2a8] */
/* @0x154db0 vcvt.s32.f64 s15, d8 */
/* @0x154db4 vmov r1, s15 */
/* @0x154db8 str r6, [r0] */
/* @0x154dbc str r6, [r0, #0x4] */
/* @0x154dc0 str r6, [r0, #0x8] */
/* @0x154dc4 str r6, [r0, #0xc] */
/* @0x154dc8 str r6, [r0, #0x10] */
/* @0x154dcc strb r6, [r0, #0x14] */
/* @0x154dd0 ldr r3, [r4, r3] */
/* @0x154dd4 ldr r2, [r3, #0x4] */
/* @0x154dd8 str r0, [r2, r5, lsl #2] */
/* @0x154ddc ldr r3, [r3, #0x4] */
/* @0x154de0 ldr r0, [r3, r5, lsl #2] */
/* @0x154de4 bl 0x18b5c4 <_ZN11CIAPProduct10SetFromMapEi> */
/* @0x154de8 add r5, r5, #1 */
/* @0x154dec cmp r5, r9 */
/* @0x154df0 bne 0x154d6c <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x154df4 b 0x154c14 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x154df8 str r12, [sp] */
/* @0x154dfc bl 0x13d348 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_> */
/* @0x154e00 ldm r8, {r0, r1} */
/* @0x154e04 bl 0xb66e8 <lrint@plt> */
/* @0x154e08 cmp r0, #0 */
/* @0x154e0c str r0, [sp, #0x18] */
/* @0x154e10 blt 0x154c14 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x154e14 add r1, sp, #44 */
/* @0x154e18 lsl r2, r0, #2 */
/* @0x154e1c str r1, [sp, #0x20] */
/* @0x154e20 mov r0, r1 */
/* @0x154e24 str r2, [sp, #0x14] */
/* @0x154e28 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x154e2c ldr r3, [pc, #0x22c] */
/* @0x154e30 ldr r1, [sp, #0x18] */
/* @0x154e34 ldr r3, [r4, r3] */
/* @0x154e38 str r3, [sp, #0x1c] */
/* @0x154e3c ldr r3, [r3, #0x4] */
/* @0x154e40 ldr r0, [r3, r1, lsl #2] */
/* @0x154e44 bl 0x2052c0 <_ZN7CDS_Map4SizeEv> */
/* @0x154e48 ldr r3, [pc, #0x208] */
/* @0x154e4c ldr r6, [r4, r3] */
/* @0x154e50 ldr r3, [r6] */
/* @0x154e54 cmp r0, r3 */
/* @0x154e58 mov r7, r0 */
/* @0x154e5c bgt 0x155020 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x44c> */
/* @0x154e60 ldr r2, [sp, #0x1c] */
/* @0x154e64 ldr r1, [sp, #0x18] */
/* @0x154e68 ldr r3, [r2, #0x4] */
/* @0x154e6c ldr r0, [r3, r1, lsl #2] */
/* @0x154e70 bl 0x203c8c <_ZN7CDS_Map9FindFirstEv> */
/* @0x154e74 subs r10, r0, #0 */
/* @0x154e78 beq 0x155048 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x474> */
/* @0x154e7c ldr r3, [pc, #0x1d8] */
/* @0x154e80 add r1, sp, #48 */
/* @0x154e84 str r1, [sp, #0x8] */
/* @0x154e88 add r7, sp, #64 */
/* @0x154e8c mov r9, #0 */
/* @0x154e90 mov r11, r1 */
/* @0x154e94 ldr r5, [r4, r3] */
/* @0x154e98 str r8, [sp, #0x24] */
/* @0x154e9c str r5, [sp, #0x8] */
/* @0x154ea0 ldr r5, [sp, #0x1c] */
/* @0x154ea4 b 0x154f24 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x350> */
/* @0x154ea8 ldr r0, [r4] */
/* @0x154eac cmp r0, #0 */
/* @0x154eb0 beq 0x154eb8 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x2e4> */
/* @0x154eb4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x154eb8 mov r0, r8 */
/* @0x154ebc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x154ec0 mov r12, r10 */
/* @0x154ec4 mov lr, r7 */
/* @0x154ec8 str r0, [r4] */
/* @0x154ecc ldr r0, [r12, #0x10]! */
/* @0x154ed0 ldr r1, [r12, #0x4] */
/* @0x154ed4 ldr r3, [r12, #0xc] */
/* @0x154ed8 ldr r2, [r12, #0x8] */
/* @0x154edc stm lr!, {r0, r1, r2, r3} */
/* @0x154ee0 mov r1, #0 */
/* @0x154ee4 ldr r3, [sp, #0x4c] */
/* @0x154ee8 mov r0, r7 */
/* @0x154eec bic r3, r3, #-16777216 */
/* @0x154ef0 str r3, [sp, #0x4c] */
/* @0x154ef4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x154ef8 subs r1, r0, #0 */
/* @0x154efc mov r0, r4 */
/* @0x154f00 blt 0x154f08 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x334> */
/* @0x154f04 bl 0x18b5c4 <_ZN11CIAPProduct10SetFromMapEi> */
/* @0x154f08 ldr r3, [r5, #0x4] */
/* @0x154f0c mov r1, r11 */
/* @0x154f10 ldr r2, [sp, #0x14] */
/* @0x154f14 ldr r0, [r3, r2] */
/* @0x154f18 bl 0x203b94 <_ZN7CDS_Map8FindNextEP6RValue> */
/* @0x154f1c subs r10, r0, #0 */
/* @0x154f20 beq 0x154fcc <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x3f8> */
/* @0x154f24 mov r0, #24 */
/* @0x154f28 mov r8, #0 */
/* @0x154f2c bl 0x27c524 <_Znwj> */
/* @0x154f30 ldr r1, [sp, #0x8] */
/* @0x154f34 ldr r3, [r6] */
/* @0x154f38 mov lr, r11 */
/* @0x154f3c ldr r2, [r1, #0x4] */
/* @0x154f40 add r1, r3, #1 */
/* @0x154f44 str r9, [r0] */
/* @0x154f48 mov r4, r0 */
/* @0x154f4c str r9, [r0, #0x4] */
/* @0x154f50 str r9, [r0, #0x8] */
/* @0x154f54 str r9, [r0, #0xc] */
/* @0x154f58 str r9, [r0, #0x10] */
/* @0x154f5c strb r9, [r0, #0x14] */
/* @0x154f60 str r1, [r6] */
/* @0x154f64 str r0, [r2, r3, lsl #2] */
/* @0x154f68 ldr r3, [r10, #0xc] */
/* @0x154f6c ldr r0, [r10] */
/* @0x154f70 ldr r1, [r10, #0x4] */
/* @0x154f74 ldr r2, [r10, #0x8] */
/* @0x154f78 stm lr!, {r0, r1, r2, r3} */
/* @0x154f7c ldr r3, [sp, #0x3c] */
/* @0x154f80 bic r3, r3, #-16777216 */
/* @0x154f84 str r3, [sp, #0x3c] */
/* @0x154f88 cmp r3, #1 */
/* @0x154f8c bne 0x154ea8 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x2d4> */
/* @0x154f90 ldr r8, [sp, #0x30] */
/* @0x154f94 cmp r8, #0 */
/* @0x154f98 ldrne r8, [r8] */
/* @0x154f9c b 0x154ea8 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x2d4> */
/* @0x154fa0 ldr r0, [pc, #0xb4] */
/* @0x154fa4 lsl r1, r9, #2 */
/* @0x154fa8 ldr r2, [pc, #0xb4] */
/* @0x154fac mov r3, #255 */
/* @0x154fb0 ldr r5, [r4, r0] */
/* @0x154fb4 add r2, pc, r2 */
/* @0x154fb8 add r0, r5, #4 */
/* @0x154fbc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x154fc0 str r9, [r5] */
/* @0x154fc4 str r9, [r6] */
/* @0x154fc8 b 0x154d58 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x154fcc ldr r8, [sp, #0x24] */
/* @0x154fd0 vldr s13, [sp, #24] */
/* @0x154fd4 vcvt.f64.s32 d7, s13 */
/* @0x154fd8 mov r0, r8 */
/* @0x154fdc ldr r1, [sp, #0xc] */
/* @0x154fe0 ldr r2, [sp, #0x10] */
/* @0x154fe4 mov r3, #1 */
/* @0x154fe8 str r7, [sp] */
/* @0x154fec mov r12, #0 */
/* @0x154ff0 str r12, [sp, #0x4c] */
/* @0x154ff4 vstr d7, [sp, #64] */
/* @0x154ff8 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_> */
/* @0x154ffc mov r0, r8 */
/* @0x155000 str r7, [sp] */
/* @0x155004 ldr r1, [sp, #0xc] */
/* @0x155008 mov r3, #1 */
/* @0x15500c ldr r2, [sp, #0x10] */
/* @0x155010 bl 0xfec90 <_Z14F_DsMapDestroyR6RValueP9CInstanceS2_iPS_> */
/* @0x155014 add r0, sp, #44 */
/* @0x155018 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x15501c b 0x154c14 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x155020 ldr r0, [pc, #0x34] */
/* @0x155024 lsl r1, r7, #2 */
/* @0x155028 ldr r2, [pc, #0x38] */
/* @0x15502c movw r3, #0x126 */
/* @0x155030 ldr r5, [r4, r0] */
/* @0x155034 add r2, pc, r2 */
/* @0x155038 add r0, r5, #4 */
/* @0x15503c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x155040 str r7, [r5] */
/* @0x155044 b 0x154e60 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x28c> */
/* @0x155048 add r7, sp, #64 */
/* @0x15504c b 0x154fd0 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x3fc> */
/* @0x155050 eoreq sp, r9, r4, rrx */
/* @0x155054 andseq r1, pc, r4, lsl #10 */
/* @0x155058 .word 0xffffde80 */
/* @0x15505c .word 0xffffde84 */
/* @0x155060 .word 0xffffbcec */
/* @0x155064 ldrsheq r0, [pc], -r8 */
/* @0x155068 andseq r0, pc, r8, ror pc */

/* ── FUNC 0x15506c · anon_15506c · size=0 · insn=1 */
/* @0x15506c andeq r0, r0, r0 */

/* ── FUNC 0x155070 · F_IAP_Acquire(RValue&, CInstance*, CInstance*, int, RValue*) · size=384 · insn=94 */
/* @0x155070 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x155074 sub sp, sp, #60 */
/* @0x155078 mov r6, r0 */
/* @0x15507c mov r2, #0 */
/* @0x155080 ldr r4, [sp, #0x60] */
/* @0x155084 mov r3, r2 */
/* @0x155088 mov r1, #1 */
/* @0x15508c str r3, [r0, #0xc] */
/* @0x155090 movt r2, #0xbff0 */
/* @0x155094 str r2, [r0, #0x4] */
/* @0x155098 str r3, [r6] */
/* @0x15509c mov r0, r4 */
/* @0x1550a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1550a4 mov r7, r0 */
/* @0x1550a8 mov r0, r4 */
/* @0x1550ac bl 0x15327c <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1550b0 cmp r0, #0 */
/* @0x1550b4 blt 0x1550cc <_Z13F_IAP_AcquireR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x1550b8 ldr r3, [pc, #0x110] */
/* @0x1550bc ldr r3, [pc, r3] */
/* @0x1550c0 ldr r2, [r3] */
/* @0x1550c4 cmp r0, r2 */
/* @0x1550c8 blt 0x1550f8 <_Z13F_IAP_AcquireR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1550cc ldr r3, [pc, #0x100] */
/* @0x1550d0 mov r2, r7 */
/* @0x1550d4 ldr r1, [pc, #0xfc] */
/* @0x1550d8 ldr r3, [pc, r3] */
/* @0x1550dc add r1, pc, r1 */
/* @0x1550e0 ldr r0, [r3] */
/* @0x1550e4 ldr r3, [r0] */
/* @0x1550e8 ldr r3, [r3, #0xc] */
/* @0x1550ec blx r3 */
/* @0x1550f0 add sp, sp, #60 */
/* @0x1550f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1550f8 ldr r3, [r3, #0x4] */
/* @0x1550fc ldr r3, [r3, r0, lsl #2] */
/* @0x155100 ldr r8, [r3] */
/* @0x155104 bl 0x153020 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x155108 ldr r3, [pc, #0xcc] */
/* @0x15510c ldr r3, [pc, r3] */
/* @0x155110 ldr r3, [r3, #0x4] */
/* @0x155114 ldr r9, [r3, r0, lsl #2] */
/* @0x155118 mov r4, r0 */
/* @0x15511c ldr r0, [r9, #0x4] */
/* @0x155120 cmp r0, #0 */
/* @0x155124 beq 0x15512c <_Z13F_IAP_AcquireR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x155128 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x15512c mov r0, r8 */
/* @0x155130 ldr r11, [pc, #0xa8] */
/* @0x155134 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x155138 vmov s15, r4 */
/* @0x15513c ldr r10, [pc, #0xa0] */
/* @0x155140 mov r12, #0 */
/* @0x155144 vcvt.f64.s32 d7, s15 */
/* @0x155148 ldr lr, [pc, #0x98] */
/* @0x15514c ldr r1, [pc, #0x98] */
/* @0x155150 mov r2, #0 */
/* @0x155154 add lr, pc, lr */
/* @0x155158 add r11, pc, r11 */
/* @0x15515c add r10, pc, r10 */
/* @0x155160 add r1, pc, r1 */
/* @0x155164 mov r3, #0 */
/* @0x155168 movt r3, #0x3ff0 */
/* @0x15516c vmov r4, r5, d7 */
/* @0x155170 vldr d7, [pc, #80] */
/* @0x155174 str r0, [r9, #0x4] */
/* @0x155178 vstr d7, [sp, #8] */
/* @0x15517c vstr d7, [sp, #24] */
/* @0x155180 str lr, [sp, #0x24] */
/* @0x155184 str r12, [sp] */
/* @0x155188 mov r0, #4 */
/* @0x15518c str r12, [sp, #0x30] */
/* @0x155190 strd r4, r5, [sp, #40] */
/* @0x155194 str r8, [sp, #0x10] */
/* @0x155198 str r7, [sp, #0x20] */
/* @0x15519c str r11, [sp, #0x4] */
/* @0x1551a0 str r10, [sp, #0x14] */
/* @0x1551a4 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88> */
/* @0x1551a8 mov r1, #1 */
/* @0x1551ac bl 0x153acc <_Z16InitIAPFunctionsv+0x5f8> */
/* @0x1551b0 mov r2, r4 */
/* @0x1551b4 mov r3, r5 */
/* @0x1551b8 stm r6, {r2, r3} */
/* @0x1551bc add sp, sp, #60 */
/* @0x1551c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1551c4 nop */
/* @0x1551d0 eoreq r10, r9, r8, lsl r10 */
/* @0x1551d4 eoreq r8, r9, r8, ror #16 */
/* @0x1551d8 ldrsbeq r1, [pc], -r12 */
/* @0x1551dc eoreq r10, r9, r0, asr #19 */
/* @0x1551e0 ldrsbeq r0, [pc], -r8 */
/* @0x1551e4 andseq r0, pc, r12, ror #31 */
/* @0x1551e8 andseq r0, pc, r4, ror #31 */
/* @0x1551ec andseq r0, pc, r8, asr #31 */

/* ── FUNC 0x1551f0 · F_IAP_Consume(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x1551f0 push {r4, r5, lr} */
/* @0x1551f4 sub sp, sp, #28 */
/* @0x1551f8 ldr r0, [sp, #0x28] */
/* @0x1551fc bl 0x15327c <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x155200 subs r12, r0, #0 */
/* @0x155204 blt 0x15521c <_Z13F_IAP_ConsumeR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x155208 ldr r3, [pc, #0x90] */
/* @0x15520c ldr r3, [pc, r3] */
/* @0x155210 ldr r2, [r3] */
/* @0x155214 cmp r12, r2 */
/* @0x155218 blt 0x155248 <_Z13F_IAP_ConsumeR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x15521c ldr r3, [pc, #0x80] */
/* @0x155220 mov r2, r12 */
/* @0x155224 ldr r1, [pc, #0x7c] */
/* @0x155228 ldr r3, [pc, r3] */
/* @0x15522c add r1, pc, r1 */
/* @0x155230 ldr r0, [r3] */
/* @0x155234 ldr r3, [r0] */
/* @0x155238 ldr r3, [r3, #0xc] */
/* @0x15523c blx r3 */
/* @0x155240 add sp, sp, #28 */
/* @0x155244 pop {r4, r5, pc} */
/* @0x155248 ldr r2, [pc, #0x5c] */
/* @0x15524c mov r1, #0 */
/* @0x155250 mov r4, #0 */
/* @0x155254 str r1, [sp] */
/* @0x155258 add r2, pc, r2 */
/* @0x15525c mov r5, #0 */
/* @0x155260 str r2, [sp, #0x4] */
/* @0x155264 mov r0, #2 */
/* @0x155268 strd r4, r5, [sp, #8] */
/* @0x15526c mov r2, #0 */
/* @0x155270 ldr lr, [r3, #0x4] */
/* @0x155274 mov r3, #1073741824 */
/* @0x155278 ldr r1, [pc, #0x30] */
/* @0x15527c ldr r12, [lr, r12, lsl #2] */
/* @0x155280 add r1, pc, r1 */
/* @0x155284 ldr r12, [r12] */
/* @0x155288 str r12, [sp, #0x10] */
/* @0x15528c bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88> */
/* @0x155290 mov r1, #2 */
/* @0x155294 add sp, sp, #28 */
/* @0x155298 pop {r4, r5, lr} */
/* @0x15529c b 0x153acc <_Z16InitIAPFunctionsv+0x5f8> */
/* @0x1552a0 eoreq r10, r9, r8, asr #17 */
/* @0x1552a4 eoreq r8, r9, r8, lsl r7 */
/* @0x1552a8 ldrheq r1, [pc], -r12 */
/* @0x1552ac ldrsbeq r0, [pc], -r8 */
/* @0x1552b0 andseq r0, pc, r8, lsr #29 */
