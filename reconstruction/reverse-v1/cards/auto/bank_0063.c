/* libyoyo.so 覆盖卡组 0063
 * 函数 0x12e710..0x12fd70，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x12e710 · F_RoomSetPersistent(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x12e710 push {r3, r4, r5, lr} */
/* @0x12e714 mov r1, #0 */
/* @0x12e718 ldr r4, [sp, #0x10] */
/* @0x12e71c mov r0, r4 */
/* @0x12e720 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e724 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e728 subs r5, r0, #0 */
/* @0x12e72c popeq {r3, r4, r5, pc} */
/* @0x12e730 mov r0, r4 */
/* @0x12e734 mov r1, #1 */
/* @0x12e738 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12e73c strb r0, [r5, #0x18] */
/* @0x12e740 pop {r3, r4, r5, pc} */

/* ── FUNC 0x12e744 · F_RoomSetBackgroundColor(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x12e744 push {r3, r4, r5, lr} */
/* @0x12e748 mov r1, #0 */
/* @0x12e74c ldr r4, [sp, #0x10] */
/* @0x12e750 mov r0, r4 */
/* @0x12e754 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e758 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e75c subs r5, r0, #0 */
/* @0x12e760 popeq {r3, r4, r5, pc} */
/* @0x12e764 mov r1, #1 */
/* @0x12e768 mov r0, r4 */
/* @0x12e76c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e770 mov r1, #2 */
/* @0x12e774 str r0, [r5, #0x1c] */
/* @0x12e778 mov r0, r4 */
/* @0x12e77c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12e780 strb r0, [r5, #0x20] */
/* @0x12e784 pop {r3, r4, r5, pc} */

/* ── FUNC 0x12e788 · F_RoomSetViewEnabled(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x12e788 push {r3, r4, r5, lr} */
/* @0x12e78c mov r1, #0 */
/* @0x12e790 ldr r4, [sp, #0x10] */
/* @0x12e794 mov r0, r4 */
/* @0x12e798 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e79c bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e7a0 subs r5, r0, #0 */
/* @0x12e7a4 popeq {r3, r4, r5, pc} */
/* @0x12e7a8 mov r0, r4 */
/* @0x12e7ac mov r1, #1 */
/* @0x12e7b0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12e7b4 strb r0, [r5, #0x44] */
/* @0x12e7b8 pop {r3, r4, r5, pc} */

/* ── FUNC 0x12e7bc · F_RoomAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x12e7bc push {r4, lr} */
/* @0x12e7c0 mov r3, #0 */
/* @0x12e7c4 str r3, [r0, #0xc] */
/* @0x12e7c8 mov r4, r0 */
/* @0x12e7cc bl 0x1b5348 <_Z8Room_Addv> */
/* @0x12e7d0 vmov s15, r0 */
/* @0x12e7d4 vcvt.f64.s32 d7, s15 */
/* @0x12e7d8 vmov r0, r1, d7 */
/* @0x12e7dc vmov r2, s14 */
/* @0x12e7e0 mov r3, r1 */
/* @0x12e7e4 stm r4, {r2, r3} */
/* @0x12e7e8 pop {r4, pc} */

/* ── FUNC 0x12e7ec · F_RoomDuplicate(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x12e7ec push {r3, r4, r5, lr} */
/* @0x12e7f0 mov r1, #0 */
/* @0x12e7f4 mov r4, r0 */
/* @0x12e7f8 ldr r0, [sp, #0x10] */
/* @0x12e7fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e800 mov r5, r0 */
/* @0x12e804 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e808 cmp r0, #0 */
/* @0x12e80c beq 0x12e834 <_Z15F_RoomDuplicateR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12e810 mov r0, r5 */
/* @0x12e814 bl 0x1b56e0 <_Z14Room_Duplicatei> */
/* @0x12e818 vmov s15, r0 */
/* @0x12e81c vcvt.f64.s32 d7, s15 */
/* @0x12e820 vmov r2, r3, d7 */
/* @0x12e824 mov r1, #0 */
/* @0x12e828 stm r4, {r2, r3} */
/* @0x12e82c str r1, [r4, #0xc] */
/* @0x12e830 pop {r3, r4, r5, pc} */
/* @0x12e834 mov r3, #0 */
/* @0x12e838 mov r2, #0 */
/* @0x12e83c movt r3, #0xbff0 */
/* @0x12e840 b 0x12e824 <_Z15F_RoomDuplicateR6RValueP9CInstanceS2_iPS_+0x38> */

/* ── FUNC 0x12e844 · F_RoomInstanceAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x12e844 push {r4, r5, r6, r7, r8, lr} */
/* @0x12e848 mov r1, #0 */
/* @0x12e84c ldr r4, [sp, #0x18] */
/* @0x12e850 mov r5, r0 */
/* @0x12e854 mov r0, r4 */
/* @0x12e858 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e85c bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e860 subs r6, r0, #0 */
/* @0x12e864 beq 0x12e8c4 <_Z17F_RoomInstanceAddR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12e868 mov r1, #1 */
/* @0x12e86c mov r0, r4 */
/* @0x12e870 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12e874 mov r1, #2 */
/* @0x12e878 mov r8, r0 */
/* @0x12e87c mov r0, r4 */
/* @0x12e880 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12e884 mov r1, #3 */
/* @0x12e888 mov r7, r0 */
/* @0x12e88c mov r0, r4 */
/* @0x12e890 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e894 mov r2, r7 */
/* @0x12e898 mov r1, r8 */
/* @0x12e89c mov r3, r0 */
/* @0x12e8a0 mov r0, r6 */
/* @0x12e8a4 bl 0x1aadac <_ZN5CRoom20AddInstanceToStorageEffi> */
/* @0x12e8a8 vmov s15, r0 */
/* @0x12e8ac vcvt.f64.s32 d7, s15 */
/* @0x12e8b0 vmov r2, r3, d7 */
/* @0x12e8b4 mov r1, #0 */
/* @0x12e8b8 stm r5, {r2, r3} */
/* @0x12e8bc str r1, [r5, #0xc] */
/* @0x12e8c0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x12e8c4 mov r3, #0 */
/* @0x12e8c8 mov r2, #0 */
/* @0x12e8cc movt r3, #0xbff0 */
/* @0x12e8d0 b 0x12e8b4 <_Z17F_RoomInstanceAddR6RValueP9CInstanceS2_iPS_+0x70> */

/* ── FUNC 0x12e8d4 · F_RoomInstanceClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x12e8d4 push {r3, lr} */
/* @0x12e8d8 mov r1, #0 */
/* @0x12e8dc ldr r0, [sp, #0x8] */
/* @0x12e8e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e8e4 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e8e8 cmp r0, #0 */
/* @0x12e8ec popeq {r3, pc} */
/* @0x12e8f0 pop {r3, lr} */
/* @0x12e8f4 b 0x1ab140 <_ZN5CRoom21ClearStorageInstancesEv> */

/* ── FUNC 0x12e8f8 · F_RoomTileAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=336 · insn=84 */
/* @0x12e8f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x12e8fc sub sp, sp, #44 */
/* @0x12e900 mov r1, #0 */
/* @0x12e904 mov r5, r0 */
/* @0x12e908 ldr r4, [sp, #0x50] */
/* @0x12e90c mov r0, r4 */
/* @0x12e910 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e914 mov r1, #1 */
/* @0x12e918 mov r6, r0 */
/* @0x12e91c mov r0, r4 */
/* @0x12e920 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e924 mov r7, r0 */
/* @0x12e928 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x12e92c subs r1, r0, #0 */
/* @0x12e930 beq 0x12ea08 <_Z13F_RoomTileAddR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x12e934 mov r0, r6 */
/* @0x12e938 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12e93c subs r6, r0, #0 */
/* @0x12e940 beq 0x12ea34 <_Z13F_RoomTileAddR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x12e944 mov r1, #2 */
/* @0x12e948 mov r0, r4 */
/* @0x12e94c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e950 mov r1, #3 */
/* @0x12e954 mov r2, r0 */
/* @0x12e958 mov r0, r4 */
/* @0x12e95c str r2, [sp, #0x20] */
/* @0x12e960 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e964 mov r1, #4 */
/* @0x12e968 mov r10, r0 */
/* @0x12e96c mov r0, r4 */
/* @0x12e970 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e974 mov r1, #5 */
/* @0x12e978 mov r3, r0 */
/* @0x12e97c mov r0, r4 */
/* @0x12e980 str r3, [sp, #0x24] */
/* @0x12e984 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e988 mov r1, #6 */
/* @0x12e98c mov r11, r0 */
/* @0x12e990 mov r0, r4 */
/* @0x12e994 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e998 mov r1, #7 */
/* @0x12e99c mov r9, r0 */
/* @0x12e9a0 mov r0, r4 */
/* @0x12e9a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e9a8 mov r1, #8 */
/* @0x12e9ac mov r8, r0 */
/* @0x12e9b0 mov r0, r4 */
/* @0x12e9b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12e9b8 ldr r3, [sp, #0x24] */
/* @0x12e9bc mov r12, #1065353216 */
/* @0x12e9c0 ldr r2, [sp, #0x20] */
/* @0x12e9c4 mvn lr, #0 */
/* @0x12e9c8 str r11, [sp, #0x4] */
/* @0x12e9cc str r3, [sp] */
/* @0x12e9d0 mov r1, r7 */
/* @0x12e9d4 mov r3, r10 */
/* @0x12e9d8 str r9, [sp, #0x8] */
/* @0x12e9dc str r8, [sp, #0xc] */
/* @0x12e9e0 str lr, [sp, #0x1c] */
/* @0x12e9e4 str r12, [sp, #0x14] */
/* @0x12e9e8 str r12, [sp, #0x18] */
/* @0x12e9ec str r0, [sp, #0x10] */
/* @0x12e9f0 mov r0, r6 */
/* @0x12e9f4 bl 0x1aaf78 <_ZN5CRoom16AddTileToStorageEiiiiiiiiffj> */
/* @0x12e9f8 vmov s15, r0 */
/* @0x12e9fc vcvt.f64.s32 d7, s15 */
/* @0x12ea00 vmov r2, r3, d7 */
/* @0x12ea04 b 0x12ea20 <_Z13F_RoomTileAddR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x12ea08 ldr r0, [pc, #0x34] */
/* @0x12ea0c add r0, pc, r0 */
/* @0x12ea10 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12ea14 mov r3, #0 */
/* @0x12ea18 movt r3, #0xbff0 */
/* @0x12ea1c mov r2, #0 */
/* @0x12ea20 mov r1, #0 */
/* @0x12ea24 stm r5, {r2, r3} */
/* @0x12ea28 str r1, [r5, #0xc] */
/* @0x12ea2c add sp, sp, #44 */
/* @0x12ea30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x12ea34 mov r3, #0 */
/* @0x12ea38 mov r2, #0 */
/* @0x12ea3c movt r3, #0xbff0 */
/* @0x12ea40 b 0x12ea20 <_Z13F_RoomTileAddR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x12ea44 eoreq r11, r0, r12, asr #11 */

/* ── FUNC 0x12ea48 · F_RoomTileAddExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=468 · insn=117 */
/* @0x12ea48 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x12ea4c sub sp, sp, #60 */
/* @0x12ea50 mov r1, #0 */
/* @0x12ea54 mov r5, r0 */
/* @0x12ea58 ldr r4, [sp, #0x60] */
/* @0x12ea5c mov r0, r4 */
/* @0x12ea60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ea64 mov r1, #1 */
/* @0x12ea68 mov r7, r0 */
/* @0x12ea6c mov r0, r4 */
/* @0x12ea70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ea74 mov r6, r0 */
/* @0x12ea78 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x12ea7c subs r1, r0, #0 */
/* @0x12ea80 beq 0x12ebd0 <_Z16F_RoomTileAddExtR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x12ea84 mov r0, r7 */
/* @0x12ea88 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12ea8c subs r7, r0, #0 */
/* @0x12ea90 beq 0x12ec04 <_Z16F_RoomTileAddExtR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x12ea94 mov r0, r4 */
/* @0x12ea98 mov r1, #11 */
/* @0x12ea9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12eaa0 vmov s15, r0 */
/* @0x12eaa4 vcmpe.f32 s15, #0 */
/* @0x12eaa8 vmrs APSR_nzcv, fpscr */
/* @0x12eaac mvnmi r12, #-16777216 */
/* @0x12eab0 bmi 0x12eae0 <_Z16F_RoomTileAddExtR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x12eab4 vmov.f32 s14, #1.000000e+00 */
/* @0x12eab8 vcmpe.f32 s15, s14 */
/* @0x12eabc vmrs APSR_nzcv, fpscr */
/* @0x12eac0 vldrle s14, [pc, #332] */
/* @0x12eac4 vmulle.f32 s15, s15, s14 */
/* @0x12eac8 mvngt r12, #0 */
/* @0x12eacc vcvtle.s32.f32 s15, s15 */
/* @0x12ead0 vmovle r1, s15 */
/* @0x12ead4 lslle r3, r1, #24 */
/* @0x12ead8 mvnle r12, r3, lsr #24 */
/* @0x12eadc mvnle r12, r12, lsl #24 */
/* @0x12eae0 mov r1, #2 */
/* @0x12eae4 mov r0, r4 */
/* @0x12eae8 str r12, [sp, #0x24] */
/* @0x12eaec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12eaf0 mov r1, #3 */
/* @0x12eaf4 mov r10, r0 */
/* @0x12eaf8 mov r0, r4 */
/* @0x12eafc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12eb00 mov r1, #4 */
/* @0x12eb04 mov r8, r0 */
/* @0x12eb08 mov r0, r4 */
/* @0x12eb0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12eb10 mov r1, #5 */
/* @0x12eb14 str r0, [sp, #0x30] */
/* @0x12eb18 mov r0, r4 */
/* @0x12eb1c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12eb20 mov r1, #6 */
/* @0x12eb24 mov r2, r0 */
/* @0x12eb28 mov r0, r4 */
/* @0x12eb2c str r2, [sp, #0x28] */
/* @0x12eb30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12eb34 mov r1, #7 */
/* @0x12eb38 mov r11, r0 */
/* @0x12eb3c mov r0, r4 */
/* @0x12eb40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12eb44 mov r1, #8 */
/* @0x12eb48 mov r9, r0 */
/* @0x12eb4c mov r0, r4 */
/* @0x12eb50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12eb54 mov r1, #9 */
/* @0x12eb58 str r0, [sp, #0x34] */
/* @0x12eb5c mov r0, r4 */
/* @0x12eb60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12eb64 mov r1, #10 */
/* @0x12eb68 mov r3, r0 */
/* @0x12eb6c mov r0, r4 */
/* @0x12eb70 str r3, [sp, #0x2c] */
/* @0x12eb74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12eb78 ldr r1, [sp, #0x30] */
/* @0x12eb7c ldr r2, [sp, #0x28] */
/* @0x12eb80 ldr r3, [sp, #0x2c] */
/* @0x12eb84 str r1, [sp] */
/* @0x12eb88 ldr r12, [sp, #0x24] */
/* @0x12eb8c ldr r1, [sp, #0x34] */
/* @0x12eb90 str r2, [sp, #0x4] */
/* @0x12eb94 mov r2, r10 */
/* @0x12eb98 str r3, [sp, #0x14] */
/* @0x12eb9c mov r3, r8 */
/* @0x12eba0 str r1, [sp, #0x10] */
/* @0x12eba4 mov r1, r6 */
/* @0x12eba8 str r11, [sp, #0x8] */
/* @0x12ebac str r9, [sp, #0xc] */
/* @0x12ebb0 str r12, [sp, #0x1c] */
/* @0x12ebb4 str r0, [sp, #0x18] */
/* @0x12ebb8 mov r0, r7 */
/* @0x12ebbc bl 0x1aaf78 <_ZN5CRoom16AddTileToStorageEiiiiiiiiffj> */
/* @0x12ebc0 vmov s15, r0 */
/* @0x12ebc4 vcvt.f64.s32 d7, s15 */
/* @0x12ebc8 vmov r0, r1, d7 */
/* @0x12ebcc b 0x12ebe8 <_Z16F_RoomTileAddExtR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x12ebd0 ldr r0, [pc, #0x40] */
/* @0x12ebd4 add r0, pc, r0 */
/* @0x12ebd8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12ebdc mov r1, #0 */
/* @0x12ebe0 movt r1, #0xbff0 */
/* @0x12ebe4 mov r0, #0 */
/* @0x12ebe8 mov r3, #0 */
/* @0x12ebec mov r2, r0 */
/* @0x12ebf0 str r3, [r5, #0xc] */
/* @0x12ebf4 mov r3, r1 */
/* @0x12ebf8 stm r5, {r2, r3} */
/* @0x12ebfc add sp, sp, #60 */
/* @0x12ec00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x12ec04 mov r1, #0 */
/* @0x12ec08 mov r0, #0 */
/* @0x12ec0c movt r1, #0xbff0 */
/* @0x12ec10 b 0x12ebe8 <_Z16F_RoomTileAddExtR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x12ec14 cmnmi pc, #0 */
/* @0x12ec18 eoreq r11, r0, r4, lsl #8 */

/* ── FUNC 0x12ec1c · F_RoomTileClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x12ec1c push {r3, lr} */
/* @0x12ec20 mov r1, #0 */
/* @0x12ec24 ldr r0, [sp, #0x8] */
/* @0x12ec28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ec2c bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12ec30 cmp r0, #0 */
/* @0x12ec34 popeq {r3, pc} */
/* @0x12ec38 pop {r3, lr} */
/* @0x12ec3c b 0x1ab104 <_ZN5CRoom17ClearStorageTilesEv> */

/* ── FUNC 0x12ec40 · F_ResourceGetIndex(RValue&, CInstance*, CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x12ec40 push {r4, lr} */
/* @0x12ec44 mov r1, #0 */
/* @0x12ec48 mov r4, r0 */
/* @0x12ec4c ldr r0, [sp, #0x8] */
/* @0x12ec50 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12ec54 mov r1, r4 */
/* @0x12ec58 pop {r4, lr} */
/* @0x12ec5c b 0xf1770 <_Z18Code_Constant_FindPKcP6RValue> */

/* ── FUNC 0x12ec60 · F_ResourceGetType(RValue&, CInstance*, CInstance*, int, RValue*) · size=404 · insn=101 */
/* @0x12ec60 push {r4, r5, r6, lr} */
/* @0x12ec64 mov r5, #0 */
/* @0x12ec68 mov r1, r5 */
/* @0x12ec6c str r5, [r0, #0xc] */
/* @0x12ec70 str r5, [r0] */
/* @0x12ec74 mov r4, r0 */
/* @0x12ec78 mov r3, r5 */
/* @0x12ec7c movt r3, #0xbff0 */
/* @0x12ec80 str r3, [r0, #0x4] */
/* @0x12ec84 ldr r0, [sp, #0x10] */
/* @0x12ec88 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12ec8c mov r6, r0 */
/* @0x12ec90 bl 0x19edf4 <_Z11Object_FindPKc> */
/* @0x12ec94 cmp r0, r5 */
/* @0x12ec98 blt 0x12eca8 <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12ec9c str r5, [r4] */
/* @0x12eca0 str r5, [r4, #0x4] */
/* @0x12eca4 pop {r4, r5, r6, pc} */
/* @0x12eca8 mov r0, r6 */
/* @0x12ecac bl 0x1eef64 <_Z11Sprite_FindPKc> */
/* @0x12ecb0 cmp r0, #0 */
/* @0x12ecb4 blt 0x12eccc <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x12ecb8 mov r3, #0 */
/* @0x12ecbc str r5, [r4] */
/* @0x12ecc0 movt r3, #0x3ff0 */
/* @0x12ecc4 str r3, [r4, #0x4] */
/* @0x12ecc8 pop {r4, r5, r6, pc} */
/* @0x12eccc mov r0, r6 */
/* @0x12ecd0 bl 0x21fc54 <_Z10Sound_FindPKc> */
/* @0x12ecd4 cmp r0, #0 */
/* @0x12ecd8 blt 0x12ecec <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x12ecdc mov r3, #1073741824 */
/* @0x12ece0 str r5, [r4] */
/* @0x12ece4 str r3, [r4, #0x4] */
/* @0x12ece8 pop {r4, r5, r6, pc} */
/* @0x12ecec mov r0, r6 */
/* @0x12ecf0 bl 0x219794 <_Z10Audio_FindPKc> */
/* @0x12ecf4 cmp r0, #0 */
/* @0x12ecf8 bge 0x12ecdc <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x12ecfc mov r0, r6 */
/* @0x12ed00 bl 0xc370c <_Z15Background_FindPKc> */
/* @0x12ed04 cmp r0, #0 */
/* @0x12ed08 blt 0x12ed20 <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x12ed0c mov r3, #0 */
/* @0x12ed10 str r5, [r4] */
/* @0x12ed14 movt r3, #0x4010 */
/* @0x12ed18 str r3, [r4, #0x4] */
/* @0x12ed1c pop {r4, r5, r6, pc} */
/* @0x12ed20 mov r0, r6 */
/* @0x12ed24 bl 0x1a80d4 <_Z9Path_FindPKc> */
/* @0x12ed28 cmp r0, #0 */
/* @0x12ed2c blt 0x12ed44 <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x12ed30 mov r3, #0 */
/* @0x12ed34 str r5, [r4] */
/* @0x12ed38 movt r3, #0x4014 */
/* @0x12ed3c str r3, [r4, #0x4] */
/* @0x12ed40 pop {r4, r5, r6, pc} */
/* @0x12ed44 mov r0, r6 */
/* @0x12ed48 bl 0xfa374 <_Z9Font_FindPKc> */
/* @0x12ed4c cmp r0, #0 */
/* @0x12ed50 blt 0x12ed68 <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x12ed54 mov r3, #0 */
/* @0x12ed58 str r5, [r4] */
/* @0x12ed5c movt r3, #0x401c */
/* @0x12ed60 str r3, [r4, #0x4] */
/* @0x12ed64 pop {r4, r5, r6, pc} */
/* @0x12ed68 mov r0, r6 */
/* @0x12ed6c bl 0x1f2bcc <_Z13TimeLine_FindPKc> */
/* @0x12ed70 cmp r0, #0 */
/* @0x12ed74 blt 0x12ed8c <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x12ed78 mov r3, #0 */
/* @0x12ed7c str r5, [r4] */
/* @0x12ed80 movt r3, #0x4020 */
/* @0x12ed84 str r3, [r4, #0x4] */
/* @0x12ed88 pop {r4, r5, r6, pc} */
/* @0x12ed8c mov r0, r6 */
/* @0x12ed90 bl 0x1e0610 <_Z11Script_FindPKc> */
/* @0x12ed94 cmp r0, #0 */
/* @0x12ed98 blt 0x12edb0 <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x12ed9c mov r3, #0 */
/* @0x12eda0 str r5, [r4] */
/* @0x12eda4 movt r3, #0x4018 */
/* @0x12eda8 str r3, [r4, #0x4] */
/* @0x12edac pop {r4, r5, r6, pc} */
/* @0x12edb0 mov r0, r6 */
/* @0x12edb4 bl 0x1b524c <_Z9Room_FindPKc> */
/* @0x12edb8 cmp r0, #0 */
/* @0x12edbc blt 0x12edd4 <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x12edc0 mov r3, #0 */
/* @0x12edc4 mov r2, r3 */
/* @0x12edc8 movt r3, #0x4008 */
/* @0x12edcc stm r4, {r2, r3} */
/* @0x12edd0 pop {r4, r5, r6, pc} */
/* @0x12edd4 mov r0, r6 */
/* @0x12edd8 bl 0x1e12dc <_Z11Shader_FindPKc> */
/* @0x12eddc cmp r0, #0 */
/* @0x12ede0 movge r3, #0 */
/* @0x12ede4 movge r2, r3 */
/* @0x12ede8 movtge r3, #0x4024 */
/* @0x12edec stmge r4, {r2, r3} */
/* @0x12edf0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x12edf4 · F_SpritePrefetch(RValue&, CInstance*, CInstance*, int, RValue*) · size=312 · insn=78 */
/* @0x12edf4 push {r4, r5, r6, r7, r8, lr} */
/* @0x12edf8 mov r1, #0 */
/* @0x12edfc mov r3, r1 */
/* @0x12ee00 str r1, [r0, #0xc] */
/* @0x12ee04 movt r3, #0xbff0 */
/* @0x12ee08 mov r8, r0 */
/* @0x12ee0c stm r0, {r1, r3} */
/* @0x12ee10 ldr r0, [sp, #0x18] */
/* @0x12ee14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ee18 mov r5, r0 */
/* @0x12ee1c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12ee20 ldr r3, [pc, #0xf0] */
/* @0x12ee24 add r3, pc, r3 */
/* @0x12ee28 subs r6, r0, #0 */
/* @0x12ee2c beq 0x12eef0 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x12ee30 ldr r4, [r6, #0x74] */
/* @0x12ee34 cmp r4, #0 */
/* @0x12ee38 bne 0x12eec8 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x12ee3c ldr r7, [r6, #0x18] */
/* @0x12ee40 cmp r7, #0 */
/* @0x12ee44 ble 0x12eeb8 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x12ee48 ldr r2, [pc, #0xcc] */
/* @0x12ee4c ldr r5, [r3, r2] */
/* @0x12ee50 b 0x12ee7c <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x12ee54 cmn r0, #1 */
/* @0x12ee58 beq 0x12ee94 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x12ee5c ldrsh r2, [r0, #20] */
/* @0x12ee60 ldr r3, [r5, #0x4] */
/* @0x12ee64 ldr r3, [r3, r2, lsl #2] */
/* @0x12ee68 ldr r0, [r3] */
/* @0x12ee6c bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv> */
/* @0x12ee70 add r4, r4, #1 */
/* @0x12ee74 cmp r4, r7 */
/* @0x12ee78 beq 0x12eeb8 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x12ee7c mov r0, r6 */
/* @0x12ee80 mov r1, r4 */
/* @0x12ee84 bl 0x1e57f4 <_ZN7CSprite10GetTextureEi> */
/* @0x12ee88 ldr r3, [r5] */
/* @0x12ee8c cmp r0, r3 */
/* @0x12ee90 bhi 0x12ee54 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x12ee94 ldr r3, [r5, #0x4] */
/* @0x12ee98 ldr r3, [r3, r0, lsl #2] */
/* @0x12ee9c cmp r3, #0 */
/* @0x12eea0 beq 0x12ee70 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x12eea4 ldr r0, [r3] */
/* @0x12eea8 add r4, r4, #1 */
/* @0x12eeac bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv> */
/* @0x12eeb0 cmp r4, r7 */
/* @0x12eeb4 bne 0x12ee7c <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x12eeb8 mov r3, #0 */
/* @0x12eebc str r3, [r8] */
/* @0x12eec0 str r3, [r8, #0x4] */
/* @0x12eec4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x12eec8 ldr r0, [pc, #0x50] */
/* @0x12eecc mov r2, r5 */
/* @0x12eed0 ldr r1, [pc, #0x4c] */
/* @0x12eed4 ldr r3, [r3, r0] */
/* @0x12eed8 add r1, pc, r1 */
/* @0x12eedc ldr r0, [r3] */
/* @0x12eee0 ldr r3, [r0] */
/* @0x12eee4 ldr r3, [r3, #0xc] */
/* @0x12eee8 blx r3 */
/* @0x12eeec pop {r4, r5, r6, r7, r8, pc} */
/* @0x12eef0 ldr r0, [pc, #0x28] */
/* @0x12eef4 mov r2, r5 */
/* @0x12eef8 ldr r1, [pc, #0x28] */
/* @0x12eefc ldr r3, [r3, r0] */
/* @0x12ef00 add r1, pc, r1 */
/* @0x12ef04 ldr r0, [r3] */
/* @0x12ef08 ldr r3, [r0] */
/* @0x12ef0c ldr r3, [r3, #0xc] */
/* @0x12ef10 blx r3 */
/* @0x12ef14 b 0x12eeb8 <_Z16F_SpritePrefetchR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x12ef18 eoreq r2, r12, r12, lsr #28 */
/* @0x12ef1c .word 0xffffbccc */
/* @0x12ef20 .word 0xffffbac4 */
/* @0x12ef24 eoreq lr, r0, r0, ror #15 */
/* @0x12ef28 eoreq lr, r0, r12, lsl #15 */

/* ── FUNC 0x12ef2c · F_BackgroundPrefetch(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x12ef2c push {r3, r4, r5, lr} */
/* @0x12ef30 mov r1, #0 */
/* @0x12ef34 mov r3, r1 */
/* @0x12ef38 str r1, [r0, #0xc] */
/* @0x12ef3c movt r3, #0xbff0 */
/* @0x12ef40 mov r4, r0 */
/* @0x12ef44 stm r0, {r1, r3} */
/* @0x12ef48 ldr r0, [sp, #0x10] */
/* @0x12ef4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ef50 mov r5, r0 */
/* @0x12ef54 bl 0xc3794 <_Z15Background_Datai> */
/* @0x12ef58 cmp r0, #0 */
/* @0x12ef5c beq 0x12efc0 <_Z20F_BackgroundPrefetchR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x12ef60 bl 0xc1e8c <_ZN11CBackground10GetTextureEv> */
/* @0x12ef64 ldr r3, [pc, #0x7c] */
/* @0x12ef68 ldr r3, [pc, r3] */
/* @0x12ef6c ldr r2, [r3] */
/* @0x12ef70 cmp r0, r2 */
/* @0x12ef74 bhi 0x12efa0 <_Z20F_BackgroundPrefetchR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12ef78 ldr r3, [r3, #0x4] */
/* @0x12ef7c ldr r3, [r3, r0, lsl #2] */
/* @0x12ef80 cmp r3, #0 */
/* @0x12ef84 beq 0x12ef90 <_Z20F_BackgroundPrefetchR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x12ef88 ldr r0, [r3] */
/* @0x12ef8c bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv> */
/* @0x12ef90 mov r3, #0 */
/* @0x12ef94 str r3, [r4] */
/* @0x12ef98 str r3, [r4, #0x4] */
/* @0x12ef9c pop {r3, r4, r5, pc} */
/* @0x12efa0 cmn r0, #1 */
/* @0x12efa4 beq 0x12ef78 <_Z20F_BackgroundPrefetchR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x12efa8 ldrsh r2, [r0, #20] */
/* @0x12efac ldr r3, [r3, #0x4] */
/* @0x12efb0 ldr r3, [r3, r2, lsl #2] */
/* @0x12efb4 ldr r0, [r3] */
/* @0x12efb8 bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv> */
/* @0x12efbc b 0x12ef90 <_Z20F_BackgroundPrefetchR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x12efc0 ldr r3, [pc, #0x24] */
/* @0x12efc4 mov r2, r5 */
/* @0x12efc8 ldr r1, [pc, #0x20] */
/* @0x12efcc ldr r3, [pc, r3] */
/* @0x12efd0 add r1, pc, r1 */
/* @0x12efd4 ldr r0, [r3] */
/* @0x12efd8 ldr r3, [r0] */
/* @0x12efdc ldr r3, [r3, #0xc] */
/* @0x12efe0 blx r3 */
/* @0x12efe4 b 0x12ef90 <_Z20F_BackgroundPrefetchR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x12efe8 .word 0x002be9b4 */
/* @0x12efec eoreq lr, r11, r8, asr #14 */
/* @0x12eff0 eoreq lr, r0, r12, lsr #14 */

/* ── FUNC 0x12eff4 · F_BackgroundFlush(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0x12eff4 push {r4, r5, r6, lr} */
/* @0x12eff8 mov r1, #0 */
/* @0x12effc mov r3, r1 */
/* @0x12f000 str r1, [r0, #0xc] */
/* @0x12f004 movt r3, #0xbff0 */
/* @0x12f008 mov r4, r0 */
/* @0x12f00c stm r0, {r1, r3} */
/* @0x12f010 ldr r0, [sp, #0x10] */
/* @0x12f014 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f018 mov r6, r0 */
/* @0x12f01c bl 0xc3794 <_Z15Background_Datai> */
/* @0x12f020 subs r5, r0, #0 */
/* @0x12f024 beq 0x12f090 <_Z17F_BackgroundFlushR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x12f028 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x12f02c mov r0, r5 */
/* @0x12f030 bl 0xc1e8c <_ZN11CBackground10GetTextureEv> */
/* @0x12f034 ldr r3, [pc, #0x7c] */
/* @0x12f038 ldr r3, [pc, r3] */
/* @0x12f03c ldr r2, [r3] */
/* @0x12f040 cmp r0, r2 */
/* @0x12f044 bhi 0x12f070 <_Z17F_BackgroundFlushR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x12f048 ldr r3, [r3, #0x4] */
/* @0x12f04c ldr r3, [r3, r0, lsl #2] */
/* @0x12f050 cmp r3, #0 */
/* @0x12f054 beq 0x12f060 <_Z17F_BackgroundFlushR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x12f058 ldr r0, [r3] */
/* @0x12f05c bl 0x1811bc <_ZN8Graphics12FlushTextureEPv> */
/* @0x12f060 mov r3, #0 */
/* @0x12f064 str r3, [r4] */
/* @0x12f068 str r3, [r4, #0x4] */
/* @0x12f06c pop {r4, r5, r6, pc} */
/* @0x12f070 cmn r0, #1 */
/* @0x12f074 beq 0x12f048 <_Z17F_BackgroundFlushR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x12f078 ldrsh r2, [r0, #20] */
/* @0x12f07c ldr r3, [r3, #0x4] */
/* @0x12f080 ldr r3, [r3, r2, lsl #2] */
/* @0x12f084 ldr r0, [r3] */
/* @0x12f088 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv> */
/* @0x12f08c b 0x12f060 <_Z17F_BackgroundFlushR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x12f090 ldr r3, [pc, #0x24] */
/* @0x12f094 mov r2, r6 */
/* @0x12f098 ldr r1, [pc, #0x20] */
/* @0x12f09c ldr r3, [pc, r3] */
/* @0x12f0a0 add r1, pc, r1 */
/* @0x12f0a4 ldr r0, [r3] */
/* @0x12f0a8 ldr r3, [r0] */
/* @0x12f0ac ldr r3, [r3, #0xc] */
/* @0x12f0b0 blx r3 */
/* @0x12f0b4 b 0x12f060 <_Z17F_BackgroundFlushR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x12f0b8 eoreq lr, r11, r4, ror #17 */
/* @0x12f0bc eoreq lr, r11, r8, ror r6 */
/* @0x12f0c0 mlaeq r0, r0, r6, lr */

/* ── FUNC 0x12f0c4 · F_SpriteFlush(RValue&, CInstance*, CInstance*, int, RValue*) · size=316 · insn=79 */
/* @0x12f0c4 push {r4, r5, r6, r7, r8, lr} */
/* @0x12f0c8 mov r1, #0 */
/* @0x12f0cc mov r3, r1 */
/* @0x12f0d0 str r1, [r0, #0xc] */
/* @0x12f0d4 movt r3, #0xbff0 */
/* @0x12f0d8 mov r8, r0 */
/* @0x12f0dc stm r0, {r1, r3} */
/* @0x12f0e0 ldr r0, [sp, #0x18] */
/* @0x12f0e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f0e8 ldr r5, [pc, #0xfc] */
/* @0x12f0ec add r5, pc, r5 */
/* @0x12f0f0 mov r7, r0 */
/* @0x12f0f4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12f0f8 subs r6, r0, #0 */
/* @0x12f0fc beq 0x12f1c4 <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x12f100 ldr r4, [r6, #0x74] */
/* @0x12f104 cmp r4, #0 */
/* @0x12f108 bne 0x12f19c <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x12f10c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x12f110 ldr r7, [r6, #0x18] */
/* @0x12f114 cmp r7, #0 */
/* @0x12f118 ble 0x12f18c <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x12f11c ldr r3, [pc, #0xcc] */
/* @0x12f120 ldr r5, [r5, r3] */
/* @0x12f124 b 0x12f150 <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x12f128 cmn r0, #1 */
/* @0x12f12c beq 0x12f168 <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x12f130 ldrsh r2, [r0, #20] */
/* @0x12f134 ldr r3, [r5, #0x4] */
/* @0x12f138 ldr r3, [r3, r2, lsl #2] */
/* @0x12f13c ldr r0, [r3] */
/* @0x12f140 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv> */
/* @0x12f144 add r4, r4, #1 */
/* @0x12f148 cmp r4, r7 */
/* @0x12f14c beq 0x12f18c <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x12f150 mov r0, r6 */
/* @0x12f154 mov r1, r4 */
/* @0x12f158 bl 0x1e57f4 <_ZN7CSprite10GetTextureEi> */
/* @0x12f15c ldr r3, [r5] */
/* @0x12f160 cmp r0, r3 */
/* @0x12f164 bhi 0x12f128 <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x12f168 ldr r3, [r5, #0x4] */
/* @0x12f16c ldr r3, [r3, r0, lsl #2] */
/* @0x12f170 cmp r3, #0 */
/* @0x12f174 beq 0x12f144 <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12f178 ldr r0, [r3] */
/* @0x12f17c add r4, r4, #1 */
/* @0x12f180 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv> */
/* @0x12f184 cmp r4, r7 */
/* @0x12f188 bne 0x12f150 <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x12f18c mov r3, #0 */
/* @0x12f190 str r3, [r8] */
/* @0x12f194 str r3, [r8, #0x4] */
/* @0x12f198 pop {r4, r5, r6, r7, r8, pc} */
/* @0x12f19c ldr r3, [pc, #0x50] */
/* @0x12f1a0 mov r2, r7 */
/* @0x12f1a4 ldr r1, [pc, #0x4c] */
/* @0x12f1a8 ldr r3, [r5, r3] */
/* @0x12f1ac add r1, pc, r1 */
/* @0x12f1b0 ldr r0, [r3] */
/* @0x12f1b4 ldr r3, [r0] */
/* @0x12f1b8 ldr r3, [r3, #0xc] */
/* @0x12f1bc blx r3 */
/* @0x12f1c0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x12f1c4 ldr r3, [pc, #0x28] */
/* @0x12f1c8 mov r2, r7 */
/* @0x12f1cc ldr r1, [pc, #0x28] */
/* @0x12f1d0 ldr r3, [r5, r3] */
/* @0x12f1d4 add r1, pc, r1 */
/* @0x12f1d8 ldr r0, [r3] */
/* @0x12f1dc ldr r3, [r0] */
/* @0x12f1e0 ldr r3, [r3, #0xc] */
/* @0x12f1e4 blx r3 */
/* @0x12f1e8 b 0x12f18c <_Z13F_SpriteFlushR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x12f1ec eoreq r2, r12, r4, ror #22 */
/* @0x12f1f0 .word 0xffffbccc */
/* @0x12f1f4 .word 0xffffbac4 */
/* @0x12f1f8 .word 0x0020e5dc */
/* @0x12f1fc eoreq lr, r0, r12, lsl #11 */

/* ── FUNC 0x12f200 · F_SpriteSetAlphaFromSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x12f200 push {r4, r5, r6, lr} */
/* @0x12f204 mov r1, #0 */
/* @0x12f208 ldr r4, [sp, #0x10] */
/* @0x12f20c mov r0, r4 */
/* @0x12f210 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f214 mov r1, #1 */
/* @0x12f218 mov r5, r0 */
/* @0x12f21c mov r0, r4 */
/* @0x12f220 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f224 mov r6, r0 */
/* @0x12f228 mov r0, r5 */
/* @0x12f22c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12f230 mov r4, r0 */
/* @0x12f234 mov r0, r6 */
/* @0x12f238 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12f23c cmp r0, #0 */
/* @0x12f240 cmpne r4, #0 */
/* @0x12f244 mov r1, r0 */
/* @0x12f248 popeq {r4, r5, r6, pc} */
/* @0x12f24c ldr r3, [r4, #0x74] */
/* @0x12f250 cmp r3, #0 */
/* @0x12f254 bne 0x12f270 <_Z26F_SpriteSetAlphaFromSpriteR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x12f258 ldr r2, [r0, #0x74] */
/* @0x12f25c cmp r2, #0 */
/* @0x12f260 bne 0x12f284 <_Z26F_SpriteSetAlphaFromSpriteR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x12f264 mov r0, r4 */
/* @0x12f268 pop {r4, r5, r6, lr} */
/* @0x12f26c b 0x1e5c90 <_ZN7CSprite18SetAlphaFromSpriteEPS_> */
/* @0x12f270 ldr r0, [pc, #0x20] */
/* @0x12f274 mov r1, #0 */
/* @0x12f278 pop {r4, r5, r6, lr} */
/* @0x12f27c add r0, pc, r0 */
/* @0x12f280 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12f284 ldr r0, [pc, #0x10] */
/* @0x12f288 mov r1, r3 */
/* @0x12f28c pop {r4, r5, r6, lr} */
/* @0x12f290 add r0, pc, r0 */
/* @0x12f294 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12f298 eoreq lr, r0, r12, asr #10 */
/* @0x12f29c eoreq lr, r0, r0, lsr #11 */

/* ── FUNC 0x12f2a0 · F_SpriteAddFromScreen(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0x12f2a0 push {r4, r5, r6, r7, r8, lr} */
/* @0x12f2a4 sub sp, sp, #8 */
/* @0x12f2a8 mov r1, #0 */
/* @0x12f2ac ldr r4, [sp, #0x20] */
/* @0x12f2b0 mov r0, r4 */
/* @0x12f2b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f2b8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12f2bc subs r6, r0, #0 */
/* @0x12f2c0 beq 0x12f384 <_Z21F_SpriteAddFromScreenR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x12f2c4 ldr r3, [r6, #0x74] */
/* @0x12f2c8 cmp r3, #0 */
/* @0x12f2cc bne 0x12f38c <_Z21F_SpriteAddFromScreenR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x12f2d0 mov r1, #1 */
/* @0x12f2d4 mov r0, r4 */
/* @0x12f2d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f2dc mov r1, #2 */
/* @0x12f2e0 mov r8, r0 */
/* @0x12f2e4 mov r0, r4 */
/* @0x12f2e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f2ec mov r1, #3 */
/* @0x12f2f0 mov r7, r0 */
/* @0x12f2f4 mov r0, r4 */
/* @0x12f2f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f2fc mov r1, #4 */
/* @0x12f300 mov r5, r0 */
/* @0x12f304 mov r0, r4 */
/* @0x12f308 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f30c mov r2, r5 */
/* @0x12f310 mov r1, r7 */
/* @0x12f314 mov r3, r0 */
/* @0x12f318 mov r0, r8 */
/* @0x12f31c bl 0x169b34 <_Z22GR_D3D_Screenshot_Partiiii> */
/* @0x12f320 mov r1, #5 */
/* @0x12f324 mov r5, r0 */
/* @0x12f328 mov r0, r4 */
/* @0x12f32c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f330 mov r1, #6 */
/* @0x12f334 cmp r0, #0 */
/* @0x12f338 mov r0, r4 */
/* @0x12f33c movle r7, #0 */
/* @0x12f340 movgt r7, #1 */
/* @0x12f344 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f348 eor r3, r7, #1 */
/* @0x12f34c mov r2, r7 */
/* @0x12f350 str r3, [sp] */
/* @0x12f354 mov r1, r5 */
/* @0x12f358 cmp r0, #0 */
/* @0x12f35c mov r0, r6 */
/* @0x12f360 movle r3, #0 */
/* @0x12f364 movgt r3, #1 */
/* @0x12f368 bl 0x1e5988 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb> */
/* @0x12f36c cmp r5, #0 */
/* @0x12f370 beq 0x12f384 <_Z21F_SpriteAddFromScreenR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x12f374 ldr r3, [r5] */
/* @0x12f378 mov r0, r5 */
/* @0x12f37c ldr r3, [r3, #0x4] */
/* @0x12f380 blx r3 */
/* @0x12f384 add sp, sp, #8 */
/* @0x12f388 pop {r4, r5, r6, r7, r8, pc} */
/* @0x12f38c ldr r0, [pc, #0x10] */
/* @0x12f390 mov r1, #0 */
/* @0x12f394 add r0, pc, r0 */
/* @0x12f398 add sp, sp, #8 */
/* @0x12f39c pop {r4, r5, r6, r7, r8, lr} */
/* @0x12f3a0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12f3a4 eoreq lr, r0, r4, lsl r5 */

/* ── FUNC 0x12f3a8 · F_SpriteAddFromSurface(RValue&, CInstance*, CInstance*, int, RValue*) · size=280 · insn=70 */
/* @0x12f3a8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x12f3ac sub sp, sp, #12 */
/* @0x12f3b0 mov r1, #0 */
/* @0x12f3b4 ldr r4, [sp, #0x28] */
/* @0x12f3b8 mov r0, r4 */
/* @0x12f3bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f3c0 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12f3c4 subs r5, r0, #0 */
/* @0x12f3c8 beq 0x12f49c <_Z22F_SpriteAddFromSurfaceR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x12f3cc ldr r3, [r5, #0x74] */
/* @0x12f3d0 cmp r3, #0 */
/* @0x12f3d4 bne 0x12f4a4 <_Z22F_SpriteAddFromSurfaceR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x12f3d8 mov r1, #1 */
/* @0x12f3dc mov r0, r4 */
/* @0x12f3e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f3e4 mov r1, #2 */
/* @0x12f3e8 mov r6, r0 */
/* @0x12f3ec mov r0, r4 */
/* @0x12f3f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f3f4 mov r1, #3 */
/* @0x12f3f8 mov r9, r0 */
/* @0x12f3fc mov r0, r4 */
/* @0x12f400 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f404 mov r1, #4 */
/* @0x12f408 mov r8, r0 */
/* @0x12f40c mov r0, r4 */
/* @0x12f410 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f414 mov r1, #5 */
/* @0x12f418 mov r7, r0 */
/* @0x12f41c mov r0, r4 */
/* @0x12f420 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f424 mov r1, r9 */
/* @0x12f428 mov r2, r8 */
/* @0x12f42c mov r3, r7 */
/* @0x12f430 str r0, [sp] */
/* @0x12f434 mov r0, r6 */
/* @0x12f438 bl 0x1720e4 <_Z26GR_Surface_Screenshot_Partiiiii> */
/* @0x12f43c subs r6, r0, #0 */
/* @0x12f440 beq 0x12f49c <_Z22F_SpriteAddFromSurfaceR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x12f444 mov r1, #6 */
/* @0x12f448 mov r0, r4 */
/* @0x12f44c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f450 mov r1, #7 */
/* @0x12f454 cmp r0, #0 */
/* @0x12f458 mov r0, r4 */
/* @0x12f45c movle r7, #0 */
/* @0x12f460 movgt r7, #1 */
/* @0x12f464 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f468 eor r3, r7, #1 */
/* @0x12f46c mov r2, r7 */
/* @0x12f470 str r3, [sp] */
/* @0x12f474 mov r1, r6 */
/* @0x12f478 cmp r0, #0 */
/* @0x12f47c mov r0, r5 */
/* @0x12f480 movle r3, #0 */
/* @0x12f484 movgt r3, #1 */
/* @0x12f488 bl 0x1e5988 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb> */
/* @0x12f48c ldr r3, [r6] */
/* @0x12f490 mov r0, r6 */
/* @0x12f494 ldr r3, [r3, #0x4] */
/* @0x12f498 blx r3 */
/* @0x12f49c add sp, sp, #12 */
/* @0x12f4a0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x12f4a4 ldr r0, [pc, #0x10] */
/* @0x12f4a8 mov r1, #0 */
/* @0x12f4ac add r0, pc, r0 */
/* @0x12f4b0 add sp, sp, #12 */
/* @0x12f4b4 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x12f4b8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12f4bc eoreq lr, r0, r8, lsr r4 */

/* ── FUNC 0x12f4c0 · F_SpriteAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=432 · insn=108 */
/* @0x12f4c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x12f4c4 cmp r3, #6 */
/* @0x12f4c8 sub sp, sp, #28 */
/* @0x12f4cc mov r3, #0 */
/* @0x12f4d0 mov r6, r3 */
/* @0x12f4d4 mov r5, r0 */
/* @0x12f4d8 movt r3, #0xbff0 */
/* @0x12f4dc str r6, [r0, #0xc] */
/* @0x12f4e0 str r3, [r0, #0x4] */
/* @0x12f4e4 str r6, [r0] */
/* @0x12f4e8 ldr r4, [sp, #0x40] */
/* @0x12f4ec beq 0x12f5dc <_Z11F_SpriteAddR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x12f4f0 mov r1, r6 */
/* @0x12f4f4 mov r0, r4 */
/* @0x12f4f8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12f4fc mov r1, #1 */
/* @0x12f500 mov r6, r0 */
/* @0x12f504 mov r0, r4 */
/* @0x12f508 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f50c mov r1, #2 */
/* @0x12f510 mov r10, r0 */
/* @0x12f514 mov r0, r4 */
/* @0x12f518 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f51c mov r1, #3 */
/* @0x12f520 mov r8, r0 */
/* @0x12f524 mov r0, r4 */
/* @0x12f528 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f52c mov r1, #4 */
/* @0x12f530 mov r7, r0 */
/* @0x12f534 mov r0, r4 */
/* @0x12f538 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f53c mov r1, #5 */
/* @0x12f540 mov r3, r0 */
/* @0x12f544 mov r0, r4 */
/* @0x12f548 str r3, [sp, #0x14] */
/* @0x12f54c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f550 mov r1, #6 */
/* @0x12f554 mov r11, r0 */
/* @0x12f558 mov r0, r4 */
/* @0x12f55c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f560 mov r1, #7 */
/* @0x12f564 mov r9, r0 */
/* @0x12f568 mov r0, r4 */
/* @0x12f56c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f570 ldr r3, [sp, #0x14] */
/* @0x12f574 mov r1, r10 */
/* @0x12f578 str r9, [sp, #0x8] */
/* @0x12f57c cmp r3, #0 */
/* @0x12f580 movle r3, #0 */
/* @0x12f584 movgt r3, #1 */
/* @0x12f588 cmp r11, #0 */
/* @0x12f58c movle r11, #0 */
/* @0x12f590 movgt r11, #1 */
/* @0x12f594 cmp r8, #0 */
/* @0x12f598 stm sp, {r3, r11} */
/* @0x12f59c movle r2, #0 */
/* @0x12f5a0 movgt r2, #1 */
/* @0x12f5a4 cmp r7, #0 */
/* @0x12f5a8 movle r3, #0 */
/* @0x12f5ac movgt r3, #1 */
/* @0x12f5b0 str r0, [sp, #0xc] */
/* @0x12f5b4 mov r0, r6 */
/* @0x12f5b8 bl 0x1f114c <_Z10Sprite_AddPKcibbbbii> */
/* @0x12f5bc vmov s15, r0 */
/* @0x12f5c0 vcvt.f64.s32 d7, s15 */
/* @0x12f5c4 vmov r0, r1, d7 */
/* @0x12f5c8 vmov r2, s14 */
/* @0x12f5cc mov r3, r1 */
/* @0x12f5d0 stm r5, {r2, r3} */
/* @0x12f5d4 add sp, sp, #28 */
/* @0x12f5d8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x12f5dc mov r1, r6 */
/* @0x12f5e0 mov r0, r4 */
/* @0x12f5e4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12f5e8 mov r1, #1 */
/* @0x12f5ec mov r7, r0 */
/* @0x12f5f0 mov r0, r4 */
/* @0x12f5f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f5f8 mov r1, #2 */
/* @0x12f5fc mov r9, r0 */
/* @0x12f600 mov r0, r4 */
/* @0x12f604 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f608 mov r1, #3 */
/* @0x12f60c mov r8, r0 */
/* @0x12f610 mov r0, r4 */
/* @0x12f614 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f618 mov r1, #4 */
/* @0x12f61c mov r11, r0 */
/* @0x12f620 mov r0, r4 */
/* @0x12f624 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f628 mov r1, #5 */
/* @0x12f62c mov r10, r0 */
/* @0x12f630 mov r0, r4 */
/* @0x12f634 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f638 cmp r11, r6 */
/* @0x12f63c str r10, [sp, #0x8] */
/* @0x12f640 mov r1, r9 */
/* @0x12f644 movle r11, #0 */
/* @0x12f648 movgt r11, #1 */
/* @0x12f64c cmp r8, r6 */
/* @0x12f650 str r11, [sp] */
/* @0x12f654 str r6, [sp, #0x4] */
/* @0x12f658 mov r2, r6 */
/* @0x12f65c movle r3, #0 */
/* @0x12f660 movgt r3, #1 */
/* @0x12f664 str r0, [sp, #0xc] */
/* @0x12f668 mov r0, r7 */
/* @0x12f66c b 0x12f5b8 <_Z11F_SpriteAddR6RValueP9CInstanceS2_iPS_+0xf8> */

/* ── FUNC 0x12f670 · F_BackgroundAssign(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x12f670 push {r3, r4, r5, lr} */
/* @0x12f674 mov r1, #0 */
/* @0x12f678 ldr r4, [sp, #0x10] */
/* @0x12f67c mov r0, r4 */
/* @0x12f680 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f684 mov r1, #1 */
/* @0x12f688 mov r5, r0 */
/* @0x12f68c mov r0, r4 */
/* @0x12f690 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f694 mov r1, r0 */
/* @0x12f698 mov r0, r5 */
/* @0x12f69c bl 0xc4148 <_Z17Background_Assignii> */
/* @0x12f6a0 subs r1, r0, #0 */
/* @0x12f6a4 popne {r3, r4, r5, pc} */
/* @0x12f6a8 ldr r0, [pc, #0x8] */
/* @0x12f6ac pop {r3, r4, r5, lr} */
/* @0x12f6b0 add r0, pc, r0 */
/* @0x12f6b4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12f6b8 eoreq lr, r0, r0, ror r2 */

/* ── FUNC 0x12f6bc · F_SoundDiscard(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x12f6bc push {r3, lr} */
/* @0x12f6c0 ldr r3, [pc, #0x28] */
/* @0x12f6c4 ldr r0, [sp, #0x8] */
/* @0x12f6c8 ldr r3, [pc, r3] */
/* @0x12f6cc ldrb r1, [r3] */
/* @0x12f6d0 cmp r1, #0 */
/* @0x12f6d4 popne {r3, pc} */
/* @0x12f6d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f6dc bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x12f6e0 cmp r0, #0 */
/* @0x12f6e4 popeq {r3, pc} */
/* @0x12f6e8 pop {r3, lr} */
/* @0x12f6ec b 0x215724 <_ZN6CSound7DiscardEv> */
/* @0x12f6f0 eoreq pc, r11, r8, ror #12 */

/* ── FUNC 0x12f6f4 · F_SoundRestore(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x12f6f4 push {r3, lr} */
/* @0x12f6f8 ldr r3, [pc, #0x28] */
/* @0x12f6fc ldr r0, [sp, #0x8] */
/* @0x12f700 ldr r3, [pc, r3] */
/* @0x12f704 ldrb r1, [r3] */
/* @0x12f708 cmp r1, #0 */
/* @0x12f70c popne {r3, pc} */
/* @0x12f710 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f714 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x12f718 cmp r0, #0 */
/* @0x12f71c popeq {r3, pc} */
/* @0x12f720 pop {r3, lr} */
/* @0x12f724 b 0x215540 <_ZN6CSound7RestoreEv> */
/* @0x12f728 eoreq pc, r11, r0, lsr r6 */

/* ── FUNC 0x12f72c · F_SoundAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x12f72c push {r3, r4, r5, r6, r7, lr} */
/* @0x12f730 mov r5, r0 */
/* @0x12f734 ldr r3, [pc, #0x68] */
/* @0x12f738 ldr r4, [sp, #0x18] */
/* @0x12f73c ldr r3, [pc, r3] */
/* @0x12f740 ldrb r1, [r3] */
/* @0x12f744 cmp r1, #0 */
/* @0x12f748 popne {r3, r4, r5, r6, r7, pc} */
/* @0x12f74c str r1, [r0, #0xc] */
/* @0x12f750 mov r0, r4 */
/* @0x12f754 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12f758 mov r1, #1 */
/* @0x12f75c mov r7, r0 */
/* @0x12f760 mov r0, r4 */
/* @0x12f764 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f768 mov r1, #2 */
/* @0x12f76c mov r6, r0 */
/* @0x12f770 mov r0, r4 */
/* @0x12f774 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12f778 mov r1, r6 */
/* @0x12f77c mov r2, r0 */
/* @0x12f780 mov r0, r7 */
/* @0x12f784 bl 0x21fd14 <_Z9Sound_AddPKcib> */
/* @0x12f788 vmov s15, r0 */
/* @0x12f78c vcvt.f64.s32 d7, s15 */
/* @0x12f790 vmov r0, r1, d7 */
/* @0x12f794 vmov r2, s14 */
/* @0x12f798 mov r3, r1 */
/* @0x12f79c stm r5, {r2, r3} */
/* @0x12f7a0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x12f7a4 .word 0x002bf5f4 */

/* ── FUNC 0x12f7a8 · F_SoundReplace(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x12f7a8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x12f7ac mov r6, r0 */
/* @0x12f7b0 ldr r3, [pc, #0x9c] */
/* @0x12f7b4 ldr r5, [sp, #0x20] */
/* @0x12f7b8 ldr r3, [pc, r3] */
/* @0x12f7bc ldrb r4, [r3] */
/* @0x12f7c0 cmp r4, #0 */
/* @0x12f7c4 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x12f7c8 mov r1, r4 */
/* @0x12f7cc mov r0, r5 */
/* @0x12f7d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f7d4 mov r7, r0 */
/* @0x12f7d8 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x12f7dc cmp r0, #0 */
/* @0x12f7e0 beq 0x12f844 <_Z14F_SoundReplaceR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x12f7e4 mov r1, #1 */
/* @0x12f7e8 mov r0, r5 */
/* @0x12f7ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12f7f0 mov r1, #2 */
/* @0x12f7f4 mov r9, r0 */
/* @0x12f7f8 mov r0, r5 */
/* @0x12f7fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f800 mov r1, #3 */
/* @0x12f804 mov r8, r0 */
/* @0x12f808 mov r0, r5 */
/* @0x12f80c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12f810 mov r1, r9 */
/* @0x12f814 mov r2, r8 */
/* @0x12f818 mov r3, r0 */
/* @0x12f81c mov r0, r7 */
/* @0x12f820 bl 0x220018 <_Z13Sound_ReplaceiPKcib> */
/* @0x12f824 str r4, [r6, #0xc] */
/* @0x12f828 cmp r0, #0 */
/* @0x12f82c movne r3, #0 */
/* @0x12f830 movtne r3, #0x3ff0 */
/* @0x12f834 beq 0x12f848 <_Z14F_SoundReplaceR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x12f838 str r4, [r6] */
/* @0x12f83c str r3, [r6, #0x4] */
/* @0x12f840 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x12f844 str r0, [r6, #0xc] */
/* @0x12f848 mov r4, #0 */
/* @0x12f84c mov r3, r4 */
/* @0x12f850 b 0x12f838 <_Z14F_SoundReplaceR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x12f854 eoreq pc, r11, r8, ror r5 */

/* ── FUNC 0x12f858 · F_SoundDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x12f858 push {r3, r4, r5, r6, r7, lr} */
/* @0x12f85c mov r5, r0 */
/* @0x12f860 ldr r3, [pc, #0x70] */
/* @0x12f864 ldr r3, [pc, r3] */
/* @0x12f868 ldrb r4, [r3] */
/* @0x12f86c cmp r4, #0 */
/* @0x12f870 popne {r3, r4, r5, r6, r7, pc} */
/* @0x12f874 mov r1, r4 */
/* @0x12f878 ldr r0, [sp, #0x18] */
/* @0x12f87c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f880 mov r6, r0 */
/* @0x12f884 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x12f888 subs r7, r0, #0 */
/* @0x12f88c beq 0x12f8b8 <_Z13F_SoundDeleteR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x12f890 mov r0, r6 */
/* @0x12f894 bl 0x2200cc <_Z12Sound_Deletei> */
/* @0x12f898 str r4, [r5, #0xc] */
/* @0x12f89c cmp r0, #0 */
/* @0x12f8a0 movne r3, #0 */
/* @0x12f8a4 movtne r3, #0x3ff0 */
/* @0x12f8a8 beq 0x12f8cc <_Z13F_SoundDeleteR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12f8ac str r4, [r5] */
/* @0x12f8b0 str r3, [r5, #0x4] */
/* @0x12f8b4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x12f8b8 ldr r0, [pc, #0x1c] */
/* @0x12f8bc mov r1, r7 */
/* @0x12f8c0 add r0, pc, r0 */
/* @0x12f8c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12f8c8 str r7, [r5, #0xc] */
/* @0x12f8cc mov r4, #0 */
/* @0x12f8d0 mov r3, r4 */
/* @0x12f8d4 b 0x12f8ac <_Z13F_SoundDeleteR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x12f8d8 eoreq pc, r11, r12, asr #9 */
/* @0x12f8dc eoreq lr, r0, r0, lsl #1 */

/* ── FUNC 0x12f8e0 · F_PathAssign(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x12f8e0 push {r3, r4, r5, lr} */
/* @0x12f8e4 mov r1, #0 */
/* @0x12f8e8 ldr r4, [sp, #0x10] */
/* @0x12f8ec mov r0, r4 */
/* @0x12f8f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f8f4 mov r1, #1 */
/* @0x12f8f8 mov r5, r0 */
/* @0x12f8fc mov r0, r4 */
/* @0x12f900 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f904 mov r1, r0 */
/* @0x12f908 mov r0, r5 */
/* @0x12f90c bl 0x1a8460 <_Z11Path_Assignii> */
/* @0x12f910 subs r1, r0, #0 */
/* @0x12f914 popne {r3, r4, r5, pc} */
/* @0x12f918 ldr r0, [pc, #0x8] */
/* @0x12f91c pop {r3, r4, r5, lr} */
/* @0x12f920 add r0, pc, r0 */
/* @0x12f924 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12f928 eoreq lr, r0, r8, asr #32 */

/* ── FUNC 0x12f92c · F_PathAppend(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x12f92c push {r4, r5, r6, lr} */
/* @0x12f930 mov r1, #0 */
/* @0x12f934 ldr r4, [sp, #0x10] */
/* @0x12f938 mov r0, r4 */
/* @0x12f93c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f940 mov r1, #1 */
/* @0x12f944 mov r5, r0 */
/* @0x12f948 mov r0, r4 */
/* @0x12f94c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f950 mov r6, r0 */
/* @0x12f954 mov r0, r5 */
/* @0x12f958 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12f95c mov r4, r0 */
/* @0x12f960 mov r0, r6 */
/* @0x12f964 bl 0x1a815c <_Z9Path_Datai> */
/* @0x12f968 cmp r4, #0 */
/* @0x12f96c mov r1, r0 */
/* @0x12f970 beq 0x12f980 <_Z12F_PathAppendR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x12f974 mov r0, r4 */
/* @0x12f978 pop {r4, r5, r6, lr} */
/* @0x12f97c b 0x1a79e8 <_ZN5CPath6AppendEPS_> */
/* @0x12f980 ldr r0, [pc, #0x1c] */
/* @0x12f984 mov r1, r4 */
/* @0x12f988 add r0, pc, r0 */
/* @0x12f98c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12f990 ldr r0, [pc, #0x10] */
/* @0x12f994 mov r1, r4 */
/* @0x12f998 add r0, pc, r0 */
/* @0x12f99c pop {r4, r5, r6, lr} */
/* @0x12f9a0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12f9a4 .word 0x0020dff8 */
/* @0x12f9a8 eoreq lr, r0, r8 */

/* ── FUNC 0x12f9ac · F_RoomAssign(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x12f9ac push {r3, r4, r5, lr} */
/* @0x12f9b0 mov r1, #0 */
/* @0x12f9b4 ldr r4, [sp, #0x10] */
/* @0x12f9b8 mov r0, r4 */
/* @0x12f9bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f9c0 mov r1, #1 */
/* @0x12f9c4 mov r5, r0 */
/* @0x12f9c8 mov r0, r4 */
/* @0x12f9cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12f9d0 mov r1, r0 */
/* @0x12f9d4 mov r0, r5 */
/* @0x12f9d8 bl 0x1b5af4 <_Z11Room_Assignii> */
/* @0x12f9dc subs r1, r0, #0 */
/* @0x12f9e0 popne {r3, r4, r5, pc} */
/* @0x12f9e4 ldr r0, [pc, #0x8] */
/* @0x12f9e8 pop {r3, r4, r5, lr} */
/* @0x12f9ec add r0, pc, r0 */
/* @0x12f9f0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x12f9f4 .word 0x0020dfd4 */

/* ── FUNC 0x12f9f8 · F_BackgroundPrefetchMulti(RValue&, CInstance*, CInstance*, int, RValue*) · size=440 · insn=110 */
/* @0x12f9f8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x12f9fc mov r4, #0 */
/* @0x12fa00 ldr r2, [sp, #0x20] */
/* @0x12fa04 mov r3, r4 */
/* @0x12fa08 str r4, [r0, #0xc] */
/* @0x12fa0c movt r3, #0xbff0 */
/* @0x12fa10 ldr r5, [pc, #0x17c] */
/* @0x12fa14 mov r6, r0 */
/* @0x12fa18 ldr r1, [r2, #0xc] */
/* @0x12fa1c add r5, pc, r5 */
/* @0x12fa20 str r4, [r0] */
/* @0x12fa24 cmp r1, #2 */
/* @0x12fa28 str r3, [r0, #0x4] */
/* @0x12fa2c bne 0x12fa78 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12fa30 ldr r7, [r2] */
/* @0x12fa34 cmp r7, #0 */
/* @0x12fa38 beq 0x12fa54 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x12fa3c ldr r3, [r7, #0x4] */
/* @0x12fa40 cmp r3, #0 */
/* @0x12fa44 beq 0x12fa54 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x12fa48 ldr r2, [r7, #0x10] */
/* @0x12fa4c cmp r2, #1 */
/* @0x12fa50 beq 0x12fa88 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x12fa54 ldr r1, [pc, #0x13c] */
/* @0x12fa58 ldr r3, [pc, #0x13c] */
/* @0x12fa5c add r1, pc, r1 */
/* @0x12fa60 ldr r3, [r5, r3] */
/* @0x12fa64 ldr r0, [r3] */
/* @0x12fa68 ldr r3, [r0] */
/* @0x12fa6c ldr r3, [r3, #0xc] */
/* @0x12fa70 blx r3 */
/* @0x12fa74 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x12fa78 ldr r1, [pc, #0x120] */
/* @0x12fa7c ldr r3, [pc, #0x118] */
/* @0x12fa80 add r1, pc, r1 */
/* @0x12fa84 b 0x12fa60 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x12fa88 ldr r2, [r3] */
/* @0x12fa8c cmp r2, #0 */
/* @0x12fa90 ble 0x12fb60 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x12fa94 ldr r9, [pc, #0x108] */
/* @0x12fa98 ldr r8, [pc, #0x108] */
/* @0x12fa9c add r9, pc, r9 */
/* @0x12faa0 add r8, pc, r8 */
/* @0x12faa4 b 0x12fad0 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x12faa8 ldr r3, [r5, r12] */
/* @0x12faac ldr r0, [r3] */
/* @0x12fab0 ldr r3, [r0] */
/* @0x12fab4 ldr r3, [r3, #0xc] */
/* @0x12fab8 blx r3 */
/* @0x12fabc ldr r3, [r7, #0x4] */
/* @0x12fac0 add r4, r4, #1 */
/* @0x12fac4 ldr r2, [r3] */
/* @0x12fac8 cmp r2, r4 */
/* @0x12facc ble 0x12fb60 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x12fad0 ldr r3, [r3, #0x4] */
/* @0x12fad4 mov r1, r8 */
/* @0x12fad8 ldr r12, [pc, #0xbc] */
/* @0x12fadc mov r2, r4 */
/* @0x12fae0 add r3, r3, r4, lsl #4 */
/* @0x12fae4 mov r0, r3 */
/* @0x12fae8 ldr r3, [r3, #0xc] */
/* @0x12faec cmp r3, #0 */
/* @0x12faf0 bne 0x12faa8 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x12faf4 mov r1, r3 */
/* @0x12faf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12fafc mov r10, r0 */
/* @0x12fb00 bl 0xc3794 <_Z15Background_Datai> */
/* @0x12fb04 cmp r0, #0 */
/* @0x12fb08 beq 0x12fb70 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x12fb0c bl 0xc1e8c <_ZN11CBackground10GetTextureEv> */
/* @0x12fb10 ldr r3, [pc, #0x94] */
/* @0x12fb14 ldr r3, [r5, r3] */
/* @0x12fb18 ldr r2, [r3] */
/* @0x12fb1c cmp r0, r2 */
/* @0x12fb20 bls 0x12fb44 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x12fb24 cmn r0, #1 */
/* @0x12fb28 beq 0x12fb44 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x12fb2c ldrsh r2, [r0, #20] */
/* @0x12fb30 ldr r3, [r3, #0x4] */
/* @0x12fb34 ldr r3, [r3, r2, lsl #2] */
/* @0x12fb38 ldr r0, [r3] */
/* @0x12fb3c bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv> */
/* @0x12fb40 b 0x12fabc <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x12fb44 ldr r3, [r3, #0x4] */
/* @0x12fb48 ldr r3, [r3, r0, lsl #2] */
/* @0x12fb4c cmp r3, #0 */
/* @0x12fb50 beq 0x12fabc <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x12fb54 ldr r0, [r3] */
/* @0x12fb58 bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv> */
/* @0x12fb5c b 0x12fabc <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x12fb60 mov r3, #0 */
/* @0x12fb64 str r3, [r6] */
/* @0x12fb68 str r3, [r6, #0x4] */
/* @0x12fb6c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x12fb70 ldr r3, [pc, #0x24] */
/* @0x12fb74 mov r2, r10 */
/* @0x12fb78 mov r1, r9 */
/* @0x12fb7c ldr r3, [r5, r3] */
/* @0x12fb80 ldr r0, [r3] */
/* @0x12fb84 ldr r3, [r0] */
/* @0x12fb88 ldr r3, [r3, #0xc] */
/* @0x12fb8c blx r3 */
/* @0x12fb90 b 0x12fabc <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x12fb94 eoreq r2, r12, r4, lsr r2 */
/* @0x12fb98 eoreq sp, r0, r4, asr #31 */
/* @0x12fb9c .word 0xffffbac4 */
/* @0x12fba0 eoreq sp, r0, r8, asr pc */
/* @0x12fba4 .word 0x0020dff4 */
/* @0x12fba8 .word 0x0020dfb4 */
/* @0x12fbac .word 0xffffbccc */

/* ── FUNC 0x12fbb0 · F_BackgroundFlushMulti(RValue&, CInstance*, CInstance*, int, RValue*) · size=448 · insn=112 */
/* @0x12fbb0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x12fbb4 mov r4, #0 */
/* @0x12fbb8 ldr r2, [sp, #0x20] */
/* @0x12fbbc mov r3, r4 */
/* @0x12fbc0 str r4, [r0, #0xc] */
/* @0x12fbc4 movt r3, #0xbff0 */
/* @0x12fbc8 ldr r6, [pc, #0x184] */
/* @0x12fbcc mov r5, r0 */
/* @0x12fbd0 ldr r1, [r2, #0xc] */
/* @0x12fbd4 add r6, pc, r6 */
/* @0x12fbd8 str r4, [r0] */
/* @0x12fbdc cmp r1, #2 */
/* @0x12fbe0 str r3, [r0, #0x4] */
/* @0x12fbe4 bne 0x12fc30 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x12fbe8 ldr r7, [r2] */
/* @0x12fbec cmp r7, #0 */
/* @0x12fbf0 beq 0x12fc0c <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x12fbf4 ldr r3, [r7, #0x4] */
/* @0x12fbf8 cmp r3, #0 */
/* @0x12fbfc beq 0x12fc0c <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x12fc00 ldr r3, [r7, #0x10] */
/* @0x12fc04 cmp r3, #1 */
/* @0x12fc08 beq 0x12fc40 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x12fc0c ldr r1, [pc, #0x144] */
/* @0x12fc10 ldr r3, [pc, #0x144] */
/* @0x12fc14 add r1, pc, r1 */
/* @0x12fc18 ldr r3, [r6, r3] */
/* @0x12fc1c ldr r0, [r3] */
/* @0x12fc20 ldr r3, [r0] */
/* @0x12fc24 ldr r3, [r3, #0xc] */
/* @0x12fc28 blx r3 */
/* @0x12fc2c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x12fc30 ldr r1, [pc, #0x128] */
/* @0x12fc34 ldr r3, [pc, #0x120] */
/* @0x12fc38 add r1, pc, r1 */
/* @0x12fc3c b 0x12fc18 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x12fc40 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x12fc44 ldr r3, [r7, #0x4] */
/* @0x12fc48 ldr r2, [r3] */
/* @0x12fc4c cmp r2, #0 */
/* @0x12fc50 ble 0x12fd20 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x12fc54 ldr r8, [pc, #0x108] */
/* @0x12fc58 ldr r9, [pc, #0x108] */
/* @0x12fc5c add r8, pc, r8 */
/* @0x12fc60 add r9, pc, r9 */
/* @0x12fc64 b 0x12fc90 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x12fc68 ldr r3, [r6, r12] */
/* @0x12fc6c ldr r0, [r3] */
/* @0x12fc70 ldr r3, [r0] */
/* @0x12fc74 ldr r3, [r3, #0xc] */
/* @0x12fc78 blx r3 */
/* @0x12fc7c ldr r3, [r7, #0x4] */
/* @0x12fc80 add r4, r4, #1 */
/* @0x12fc84 ldr r2, [r3] */
/* @0x12fc88 cmp r2, r4 */
/* @0x12fc8c ble 0x12fd20 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x12fc90 ldr r3, [r3, #0x4] */
/* @0x12fc94 mov r1, r9 */
/* @0x12fc98 ldr r12, [pc, #0xbc] */
/* @0x12fc9c mov r2, r4 */
/* @0x12fca0 add r3, r3, r4, lsl #4 */
/* @0x12fca4 mov r0, r3 */
/* @0x12fca8 ldr r3, [r3, #0xc] */
/* @0x12fcac cmp r3, #0 */
/* @0x12fcb0 bne 0x12fc68 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x12fcb4 mov r1, r3 */
/* @0x12fcb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12fcbc mov r10, r0 */
/* @0x12fcc0 bl 0xc3794 <_Z15Background_Datai> */
/* @0x12fcc4 cmp r0, #0 */
/* @0x12fcc8 beq 0x12fd30 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x12fccc bl 0xc1e8c <_ZN11CBackground10GetTextureEv> */
/* @0x12fcd0 ldr r3, [pc, #0x94] */
/* @0x12fcd4 ldr r3, [r6, r3] */
/* @0x12fcd8 ldr r2, [r3] */
/* @0x12fcdc cmp r0, r2 */
/* @0x12fce0 bls 0x12fd04 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x12fce4 cmn r0, #1 */
/* @0x12fce8 beq 0x12fd04 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x12fcec ldrsh r2, [r0, #20] */
/* @0x12fcf0 ldr r3, [r3, #0x4] */
/* @0x12fcf4 ldr r3, [r3, r2, lsl #2] */
/* @0x12fcf8 ldr r0, [r3] */
/* @0x12fcfc bl 0x1811bc <_ZN8Graphics12FlushTextureEPv> */
/* @0x12fd00 b 0x12fc7c <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x12fd04 ldr r3, [r3, #0x4] */
/* @0x12fd08 ldr r3, [r3, r0, lsl #2] */
/* @0x12fd0c cmp r3, #0 */
/* @0x12fd10 beq 0x12fc7c <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x12fd14 ldr r0, [r3] */
/* @0x12fd18 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv> */
/* @0x12fd1c b 0x12fc7c <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x12fd20 mov r3, #0 */
/* @0x12fd24 str r3, [r5] */
/* @0x12fd28 str r3, [r5, #0x4] */
/* @0x12fd2c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x12fd30 ldr r3, [pc, #0x24] */
/* @0x12fd34 mov r2, r10 */
/* @0x12fd38 mov r1, r8 */
/* @0x12fd3c ldr r3, [r6, r3] */
/* @0x12fd40 ldr r0, [r3] */
/* @0x12fd44 ldr r3, [r0] */
/* @0x12fd48 ldr r3, [r3, #0xc] */
/* @0x12fd4c blx r3 */
/* @0x12fd50 b 0x12fc7c <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x12fd54 eoreq r2, r12, r12, ror r0 */
/* @0x12fd58 .word 0x0020defc */
/* @0x12fd5c .word 0xffffbac4 */
/* @0x12fd60 mlaeq r0, r0, lr, sp */
/* @0x12fd64 eoreq sp, r0, r0, lsr #30 */
/* @0x12fd68 eoreq sp, r0, r4, ror #29 */
/* @0x12fd6c .word 0xffffbccc */

/* ── FUNC 0x12fd70 · F_RoomSetCaption(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12fd70 push {r3, r4, r5, lr} */
/* @0x12fd74 mov r1, #0 */
/* @0x12fd78 ldr r4, [sp, #0x10] */
/* @0x12fd7c mov r0, r4 */
/* @0x12fd80 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12fd84 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12fd88 subs r5, r0, #0 */
/* @0x12fd8c popeq {r3, r4, r5, pc} */
/* @0x12fd90 mov r0, r4 */
/* @0x12fd94 mov r1, #1 */
/* @0x12fd98 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12fd9c mov r4, r0 */
/* @0x12fda0 ldr r0, [r5, #0x8] */
/* @0x12fda4 cmp r0, #0 */
/* @0x12fda8 beq 0x12fdb0 <_Z16F_RoomSetCaptionR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12fdac bl 0xcef90 <_Z6YYFreePKv> */
/* @0x12fdb0 mov r0, r4 */
/* @0x12fdb4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x12fdb8 str r0, [r5, #0x8] */
/* @0x12fdbc pop {r3, r4, r5, pc} */
