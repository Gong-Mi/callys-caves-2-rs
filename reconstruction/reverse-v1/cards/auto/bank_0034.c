/* libyoyo.so 覆盖卡组 0034
 * 函数 0x1096e4..0x10ac74，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1096e4 · F_InstanceCreateLayer(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0x1096e4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1096e8 mov r1, #3 */
/* @0x1096ec ldr r4, [sp, #0x18] */
/* @0x1096f0 mov r5, r0 */
/* @0x1096f4 ldr r6, [r4, #0x2c] */
/* @0x1096f8 mov r0, r4 */
/* @0x1096fc cmp r6, #1 */
/* @0x109700 beq 0x10979c <_Z21F_InstanceCreateLayerR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x109704 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109708 mov r1, #0 */
/* @0x10970c mov r8, r0 */
/* @0x109710 mov r0, r4 */
/* @0x109714 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109718 mov r1, #1 */
/* @0x10971c mov r7, r0 */
/* @0x109720 mov r0, r4 */
/* @0x109724 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109728 mov r1, #2 */
/* @0x10972c mov r6, r0 */
/* @0x109730 mov r0, r4 */
/* @0x109734 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109738 mov r1, r7 */
/* @0x10973c mov r2, r6 */
/* @0x109740 mov r3, r0 */
/* @0x109744 mov r0, r8 */
/* @0x109748 bl 0x1c9980 <_Z20Command_Create_Layeriffi> */
/* @0x10974c ldr r3, [pc, #0x94] */
/* @0x109750 ldr r3, [pc, r3] */
/* @0x109754 ldrb r3, [r3] */
/* @0x109758 cmp r3, #0 */
/* @0x10975c bne 0x10978c <_Z21F_InstanceCreateLayerR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x109760 cmp r0, #0 */
/* @0x109764 str r3, [r5, #0xc] */
/* @0x109768 ldrne r2, [r0, #0x78] */
/* @0x10976c moveq r3, #0 */
/* @0x109770 moveq r2, #0 */
/* @0x109774 movteq r3, #0xc010 */
/* @0x109778 vmovne s15, r2 */
/* @0x10977c vcvtne.f64.s32 d7, s15 */
/* @0x109780 vmovne r2, r3, d7 */
/* @0x109784 stm r5, {r2, r3} */
/* @0x109788 pop {r4, r5, r6, r7, r8, pc} */
/* @0x10978c mov r3, #6 */
/* @0x109790 str r0, [r5] */
/* @0x109794 str r3, [r5, #0xc] */
/* @0x109798 pop {r4, r5, r6, r7, r8, pc} */
/* @0x10979c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1097a0 mov r1, #0 */
/* @0x1097a4 mov r8, r0 */
/* @0x1097a8 mov r0, r4 */
/* @0x1097ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1097b0 mov r1, r6 */
/* @0x1097b4 mov r7, r0 */
/* @0x1097b8 mov r0, r4 */
/* @0x1097bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1097c0 mov r1, #2 */
/* @0x1097c4 mov r6, r0 */
/* @0x1097c8 mov r0, r4 */
/* @0x1097cc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1097d0 mov r1, r7 */
/* @0x1097d4 mov r2, r6 */
/* @0x1097d8 mov r3, r0 */
/* @0x1097dc mov r0, r8 */
/* @0x1097e0 bl 0x1c9a74 <_Z20Command_Create_LayeriffPKc> */
/* @0x1097e4 b 0x10974c <_Z21F_InstanceCreateLayerR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x1097e8 eoreq r4, lr, r8, ror #8 */

/* ── FUNC 0x1097ec · F_InstanceCopy(RValue&, CInstance*, CInstance*, int, RValue*) · size=336 · insn=84 */
/* @0x1097ec ldr r12, [pc, #0x13c] */
/* @0x1097f0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1097f4 ldr r12, [pc, r12] */
/* @0x1097f8 mov r8, r1 */
/* @0x1097fc sub sp, sp, #12 */
/* @0x109800 ldr r3, [r8, #0x7c] */
/* @0x109804 mov r5, r0 */
/* @0x109808 ldr r1, [r1, #0xb4] */
/* @0x10980c ldr r2, [r8, #0xb8] */
/* @0x109810 ldr r0, [r12] */
/* @0x109814 ldr r7, [sp, #0x28] */
/* @0x109818 bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi> */
/* @0x10981c ldr r6, [pc, #0x110] */
/* @0x109820 mov r1, r8 */
/* @0x109824 mov r2, #1 */
/* @0x109828 mov r4, r0 */
/* @0x10982c ldr r9, [r0, #0x78] */
/* @0x109830 bl 0x1986ec <_ZN9CInstance6AssignEPS_b> */
/* @0x109834 ldr r6, [pc, r6] */
/* @0x109838 ldr r1, [r6, #0x8] */
/* @0x10983c ldr r3, [r6, #0x4] */
/* @0x109840 str r9, [r4, #0x78] */
/* @0x109844 cmp r1, r3 */
/* @0x109848 beq 0x1098f8 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x10984c ldr r8, [r6] */
/* @0x109850 cmp r1, #0 */
/* @0x109854 ble 0x109888 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x109858 ldr r3, [r8] */
/* @0x10985c cmp r4, r3 */
/* @0x109860 beq 0x109894 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x109864 mov r12, r8 */
/* @0x109868 mov r3, #0 */
/* @0x10986c b 0x10987c <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x109870 ldr lr, [r12, #0x4]! */
/* @0x109874 cmp r4, lr */
/* @0x109878 beq 0x109894 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x10987c add r3, r3, #1 */
/* @0x109880 cmp r3, r1 */
/* @0x109884 bne 0x109870 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x109888 str r4, [r8, r1, lsl #2] */
/* @0x10988c add r1, r1, #1 */
/* @0x109890 str r1, [r6, #0x8] */
/* @0x109894 mov r0, r7 */
/* @0x109898 mov r1, #0 */
/* @0x10989c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1098a0 cmp r0, #0 */
/* @0x1098a4 beq 0x1098d8 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x1098a8 mov r0, r4 */
/* @0x1098ac mov r1, r4 */
/* @0x1098b0 mov r2, #14 */
/* @0x1098b4 mov r3, #0 */
/* @0x1098b8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1098bc mov r2, #0 */
/* @0x1098c0 mov r3, r2 */
/* @0x1098c4 mov r0, r4 */
/* @0x1098c8 mov r1, r4 */
/* @0x1098cc bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1098d0 mov r3, #1 */
/* @0x1098d4 strb r3, [r4, #0x6c] */
/* @0x1098d8 vmov s15, r9 */
/* @0x1098dc mov r1, #0 */
/* @0x1098e0 str r1, [r5, #0xc] */
/* @0x1098e4 vcvt.f64.s32 d7, s15 */
/* @0x1098e8 vmov r2, r3, d7 */
/* @0x1098ec stm r5, {r2, r3} */
/* @0x1098f0 add sp, sp, #12 */
/* @0x1098f4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1098f8 ldr r2, [pc, #0x38] */
/* @0x1098fc lsl r3, r1, #1 */
/* @0x109900 ldr r0, [r6] */
/* @0x109904 lsl r1, r1, #3 */
/* @0x109908 str r3, [r6, #0x4] */
/* @0x10990c add r2, pc, r2 */
/* @0x109910 mov r3, #0 */
/* @0x109914 str r3, [sp] */
/* @0x109918 mov r3, #74 */
/* @0x10991c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x109920 ldr r1, [r6, #0x8] */
/* @0x109924 mov r8, r0 */
/* @0x109928 str r0, [r6] */
/* @0x10992c b 0x109850 <_Z14F_InstanceCopyR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x109930 eoreq r4, lr, r4, lsr r1 */
/* @0x109934 eoreq r4, lr, r0, ror r8 */
/* @0x109938 eoreq r7, r2, r4, lsr #14 */

/* ── FUNC 0x10993c · F_InstanceChange(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x10993c push {r4, r5, r6, lr} */
/* @0x109940 mov r6, r1 */
/* @0x109944 ldr r4, [sp, #0x10] */
/* @0x109948 mov r1, #0 */
/* @0x10994c mov r0, r4 */
/* @0x109950 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109954 mov r1, #1 */
/* @0x109958 mov r5, r0 */
/* @0x10995c mov r0, r4 */
/* @0x109960 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x109964 mov r1, r5 */
/* @0x109968 mov r2, r0 */
/* @0x10996c mov r0, r6 */
/* @0x109970 pop {r4, r5, r6, lr} */
/* @0x109974 b 0x1c9bb4 <_Z14Command_ChangeP9CInstanceib> */

/* ── FUNC 0x109978 · F_InstanceSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x109978 push {r4, lr} */
/* @0x10997c mov r4, r1 */
/* @0x109980 ldr r0, [sp, #0x8] */
/* @0x109984 mov r1, #0 */
/* @0x109988 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10998c mov r1, r0 */
/* @0x109990 mov r0, r4 */
/* @0x109994 pop {r4, lr} */
/* @0x109998 b 0x1c9dbc <_Z17Command_SetSpriteP9CInstancei> */

/* ── FUNC 0x10999c · F_InstanceIdGet(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x10999c push {r3, r4, r5, lr} */
/* @0x1099a0 mov r4, r0 */
/* @0x1099a4 mov r5, r1 */
/* @0x1099a8 ldr r0, [sp, #0x10] */
/* @0x1099ac mov r1, #0 */
/* @0x1099b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1099b4 mov r2, r4 */
/* @0x1099b8 mov r1, r0 */
/* @0x1099bc mov r0, r5 */
/* @0x1099c0 pop {r3, r4, r5, lr} */
/* @0x1099c4 b 0x1fb0a8 <_Z13GV_InstanceIdP9CInstanceiP6RValue> */

/* ── FUNC 0x1099c8 · F_PositionDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x1099c8 push {r3, r4, r5, lr} */
/* @0x1099cc mov r1, #0 */
/* @0x1099d0 ldr r4, [sp, #0x10] */
/* @0x1099d4 mov r0, r4 */
/* @0x1099d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1099dc mov r1, #1 */
/* @0x1099e0 mov r5, r0 */
/* @0x1099e4 mov r0, r4 */
/* @0x1099e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1099ec mov r1, r0 */
/* @0x1099f0 mov r0, r5 */
/* @0x1099f4 pop {r3, r4, r5, lr} */
/* @0x1099f8 b 0x1c9c88 <_Z17Command_DestroyAtff> */

/* ── FUNC 0x1099fc · F_PositionChange(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x1099fc push {r4, r5, r6, r7, r8, lr} */
/* @0x109a00 mov r1, #0 */
/* @0x109a04 ldr r4, [sp, #0x18] */
/* @0x109a08 mov r0, r4 */
/* @0x109a0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109a10 mov r1, #1 */
/* @0x109a14 mov r7, r0 */
/* @0x109a18 mov r0, r4 */
/* @0x109a1c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109a20 mov r1, #2 */
/* @0x109a24 mov r6, r0 */
/* @0x109a28 mov r0, r4 */
/* @0x109a2c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109a30 mov r1, #3 */
/* @0x109a34 mov r5, r0 */
/* @0x109a38 mov r0, r4 */
/* @0x109a3c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x109a40 mov r1, r6 */
/* @0x109a44 mov r2, r5 */
/* @0x109a48 mov r3, r0 */
/* @0x109a4c mov r0, r7 */
/* @0x109a50 pop {r4, r5, r6, r7, r8, lr} */
/* @0x109a54 b 0x1c9cf8 <_Z16Command_ChangeAtffib> */

/* ── FUNC 0x109a58 · F_PositionEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x109a58 push {r3, r4, r5, r6, r7, lr} */
/* @0x109a5c mov r5, #0 */
/* @0x109a60 ldr r6, [sp, #0x18] */
/* @0x109a64 mov r4, r0 */
/* @0x109a68 str r5, [r0, #0xc] */
/* @0x109a6c mov r1, r5 */
/* @0x109a70 mov r0, r6 */
/* @0x109a74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109a78 mov r1, #1 */
/* @0x109a7c mov r7, r0 */
/* @0x109a80 mov r0, r6 */
/* @0x109a84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109a88 mvn r2, #2 */
/* @0x109a8c mov r1, r0 */
/* @0x109a90 mov r0, r7 */
/* @0x109a94 bl 0x1c9da8 <_Z16Command_ObjectAtffi> */
/* @0x109a98 cmp r0, #0 */
/* @0x109a9c moveq r3, #0 */
/* @0x109aa0 moveq r5, r0 */
/* @0x109aa4 movteq r3, #0x3ff0 */
/* @0x109aa8 movne r3, r5 */
/* @0x109aac str r5, [r4] */
/* @0x109ab0 str r3, [r4, #0x4] */
/* @0x109ab4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x109ab8 · F_RoomGoto(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x109ab8 push {r3, lr} */
/* @0x109abc mov r1, #0 */
/* @0x109ac0 ldr r0, [sp, #0x8] */
/* @0x109ac4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109ac8 ldr r3, [pc, #0xc] */
/* @0x109acc ldr r3, [pc, r3] */
/* @0x109ad0 ldr r1, [r3] */
/* @0x109ad4 pop {r3, lr} */
/* @0x109ad8 b 0x1c9e08 <_Z16Command_GotoRoomii> */
/* @0x109adc .word 0x002e45dc */

/* ── FUNC 0x109ae0 · F_RoomGotoPrevious(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x109ae0 ldr r3, [pc, #0x8] */
/* @0x109ae4 ldr r3, [pc, r3] */
/* @0x109ae8 ldr r0, [r3] */
/* @0x109aec b 0x1c9e68 <_Z20Command_PreviousRoomi> */
/* @0x109af0 eoreq r4, lr, r4, asr #11 */

/* ── FUNC 0x109af4 · F_RoomGotoNext(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x109af4 ldr r3, [pc, #0x8] */
/* @0x109af8 ldr r3, [pc, r3] */
/* @0x109afc ldr r0, [r3] */
/* @0x109b00 b 0x1c9ed0 <_Z16Command_NextRoomi> */
/* @0x109b04 .word 0x002e45b0 */

/* ── FUNC 0x109b08 · F_RoomPrevious(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x109b08 push {r3, r4, r5, lr} */
/* @0x109b0c mov r1, #0 */
/* @0x109b10 mov r4, r0 */
/* @0x109b14 ldr r0, [sp, #0x10] */
/* @0x109b18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109b1c mov r3, #0 */
/* @0x109b20 str r3, [r4, #0xc] */
/* @0x109b24 mov r5, r0 */
/* @0x109b28 bl 0x1b52f8 <_Z11Room_Existsi> */
/* @0x109b2c cmp r0, #0 */
/* @0x109b30 bne 0x109b48 <_Z14F_RoomPreviousR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x109b34 mov r3, #0 */
/* @0x109b38 mov r2, r3 */
/* @0x109b3c movt r3, #0xbff0 */
/* @0x109b40 stm r4, {r2, r3} */
/* @0x109b44 pop {r3, r4, r5, pc} */
/* @0x109b48 bl 0x1b5d08 <_Z10Room_Firstv> */
/* @0x109b4c cmp r0, r5 */
/* @0x109b50 beq 0x109b34 <_Z14F_RoomPreviousR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x109b54 mov r0, r5 */
/* @0x109b58 bl 0x1b5d40 <_Z13Room_Previousi> */
/* @0x109b5c vmov s15, r0 */
/* @0x109b60 vcvt.f64.s32 d7, s15 */
/* @0x109b64 vmov r0, r1, d7 */
/* @0x109b68 vmov r2, s14 */
/* @0x109b6c mov r3, r1 */
/* @0x109b70 stm r4, {r2, r3} */
/* @0x109b74 pop {r3, r4, r5, pc} */

/* ── FUNC 0x109b78 · F_RoomNext(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x109b78 push {r3, r4, r5, lr} */
/* @0x109b7c mov r1, #0 */
/* @0x109b80 mov r4, r0 */
/* @0x109b84 ldr r0, [sp, #0x10] */
/* @0x109b88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109b8c mov r3, #0 */
/* @0x109b90 str r3, [r4, #0xc] */
/* @0x109b94 mov r5, r0 */
/* @0x109b98 bl 0x1b52f8 <_Z11Room_Existsi> */
/* @0x109b9c cmp r0, #0 */
/* @0x109ba0 bne 0x109bb8 <_Z10F_RoomNextR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x109ba4 mov r3, #0 */
/* @0x109ba8 mov r2, r3 */
/* @0x109bac movt r3, #0xbff0 */
/* @0x109bb0 stm r4, {r2, r3} */
/* @0x109bb4 pop {r3, r4, r5, pc} */
/* @0x109bb8 bl 0x1b5d20 <_Z9Room_Lastv> */
/* @0x109bbc cmp r0, r5 */
/* @0x109bc0 beq 0x109ba4 <_Z10F_RoomNextR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x109bc4 mov r0, r5 */
/* @0x109bc8 bl 0x1b5da4 <_Z9Room_Nexti> */
/* @0x109bcc vmov s15, r0 */
/* @0x109bd0 vcvt.f64.s32 d7, s15 */
/* @0x109bd4 vmov r0, r1, d7 */
/* @0x109bd8 vmov r2, s14 */
/* @0x109bdc mov r3, r1 */
/* @0x109be0 stm r4, {r2, r3} */
/* @0x109be4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x109be8 · F_RoomRestart(RValue&, CInstance*, CInstance*, int, RValue*) · size=20 · insn=5 */
/* @0x109be8 ldr r3, [pc, #0x8] */
/* @0x109bec ldr r3, [pc, r3] */
/* @0x109bf0 ldr r0, [r3] */
/* @0x109bf4 b 0x1c9f38 <_Z19Command_CurrentRoomi> */
/* @0x109bf8 .word 0x002e44bc */

/* ── FUNC 0x109bfc · F_GameEnd(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x109bfc b 0x1c9f50 <_Z15Command_EndGamev> */

/* ── FUNC 0x109c00 · F_GameRestart(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x109c00 b 0x1c9f54 <_Z19Command_RestartGamev> */

/* ── FUNC 0x109c04 · F_GameLoad(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x109c04 push {r3, lr} */
/* @0x109c08 mov r1, #0 */
/* @0x109c0c ldr r0, [sp, #0x8] */
/* @0x109c10 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x109c14 pop {r3, lr} */
/* @0x109c18 b 0x1d14fc <_Z16Command_LoadGamePKc> */

/* ── FUNC 0x109c1c · F_GameSave(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x109c1c push {r3, lr} */
/* @0x109c20 mov r1, #0 */
/* @0x109c24 ldr r0, [sp, #0x8] */
/* @0x109c28 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x109c2c pop {r3, lr} */
/* @0x109c30 b 0x1d1468 <_Z16Command_SaveGamePKc> */

/* ── FUNC 0x109c34 · F_GameSaveBuffer(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x109c34 push {r3, lr} */
/* @0x109c38 mov r1, #0 */
/* @0x109c3c ldr r0, [sp, #0x8] */
/* @0x109c40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109c44 pop {r3, lr} */
/* @0x109c48 b 0x1d07c8 <_Z16Command_SaveGamei> */

/* ── FUNC 0x109c4c · F_GameLoadBuffer(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x109c4c push {r3, lr} */
/* @0x109c50 mov r1, #0 */
/* @0x109c54 ldr r0, [sp, #0x8] */
/* @0x109c58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109c5c pop {r3, lr} */
/* @0x109c60 b 0x1d0dd8 <_Z16Command_LoadGamei> */

/* ── FUNC 0x109c64 · F_Sleep(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x109c64 push {r3, lr} */
/* @0x109c68 mov r1, #0 */
/* @0x109c6c ldr r0, [sp, #0x8] */
/* @0x109c70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109c74 mov r3, #1000 */
/* @0x109c78 mul r0, r3, r0 */
/* @0x109c7c pop {r3, lr} */
/* @0x109c80 asr r1, r0, #31 */
/* @0x109c84 b 0x2151f0 <Timing_Sleep> */

/* ── FUNC 0x109c88 · F_MpLinearPath(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x109c88 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x109c8c sub sp, sp, #20 */
/* @0x109c90 mov r5, r0 */
/* @0x109c94 mov r6, r1 */
/* @0x109c98 ldr r4, [sp, #0x38] */
/* @0x109c9c mov r1, #0 */
/* @0x109ca0 mov r0, r4 */
/* @0x109ca4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109ca8 mov r7, r0 */
/* @0x109cac bl 0x1a8008 <_Z11Path_Existsi> */
/* @0x109cb0 subs r1, r0, #0 */
/* @0x109cb4 beq 0x109d50 <_Z14F_MpLinearPathR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x109cb8 mov r0, r7 */
/* @0x109cbc mov r7, #0 */
/* @0x109cc0 str r7, [r5, #0xc] */
/* @0x109cc4 bl 0x1a815c <_Z9Path_Datai> */
/* @0x109cc8 mov r1, #1 */
/* @0x109ccc mov r10, r0 */
/* @0x109cd0 mov r0, r4 */
/* @0x109cd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109cd8 mov r1, #2 */
/* @0x109cdc mov r9, r0 */
/* @0x109ce0 mov r0, r4 */
/* @0x109ce4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109ce8 mov r1, #3 */
/* @0x109cec mov r8, r0 */
/* @0x109cf0 mov r0, r4 */
/* @0x109cf4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109cf8 mov r1, #4 */
/* @0x109cfc mov r11, r0 */
/* @0x109d00 mov r0, r4 */
/* @0x109d04 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x109d08 mov r3, r8 */
/* @0x109d0c mvn r12, #2 */
/* @0x109d10 str r11, [sp] */
/* @0x109d14 mov r1, r10 */
/* @0x109d18 mov r2, r9 */
/* @0x109d1c str r12, [sp, #0x4] */
/* @0x109d20 str r0, [sp, #0x8] */
/* @0x109d24 mov r0, r6 */
/* @0x109d28 bl 0x19c9cc <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib> */
/* @0x109d2c cmp r0, #0 */
/* @0x109d30 moveq r7, r0 */
/* @0x109d34 movne r3, r7 */
/* @0x109d38 moveq r3, r7 */
/* @0x109d3c movtne r3, #0x3ff0 */
/* @0x109d40 str r7, [r5] */
/* @0x109d44 str r3, [r5, #0x4] */
/* @0x109d48 add sp, sp, #20 */
/* @0x109d4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x109d50 ldr r0, [pc, #0xc] */
/* @0x109d54 add r0, pc, r0 */
/* @0x109d58 add sp, sp, #20 */
/* @0x109d5c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x109d60 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x109d64 eoreq lr, r2, r8, ror r9 */

/* ── FUNC 0x109d68 · F_MpLinearPathObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x109d68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x109d6c sub sp, sp, #20 */
/* @0x109d70 mov r5, r0 */
/* @0x109d74 mov r6, r1 */
/* @0x109d78 ldr r4, [sp, #0x38] */
/* @0x109d7c mov r1, #0 */
/* @0x109d80 mov r0, r4 */
/* @0x109d84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109d88 mov r7, r0 */
/* @0x109d8c bl 0x1a8008 <_Z11Path_Existsi> */
/* @0x109d90 subs r1, r0, #0 */
/* @0x109d94 beq 0x109e2c <_Z20F_MpLinearPathObjectR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x109d98 mov r0, r7 */
/* @0x109d9c mov r7, #0 */
/* @0x109da0 str r7, [r5, #0xc] */
/* @0x109da4 bl 0x1a815c <_Z9Path_Datai> */
/* @0x109da8 mov r1, #1 */
/* @0x109dac mov r10, r0 */
/* @0x109db0 mov r0, r4 */
/* @0x109db4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109db8 mov r1, #2 */
/* @0x109dbc mov r9, r0 */
/* @0x109dc0 mov r0, r4 */
/* @0x109dc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109dc8 mov r1, #3 */
/* @0x109dcc mov r8, r0 */
/* @0x109dd0 mov r0, r4 */
/* @0x109dd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109dd8 mov r1, #4 */
/* @0x109ddc mov r11, r0 */
/* @0x109de0 mov r0, r4 */
/* @0x109de4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109de8 mov r3, r8 */
/* @0x109dec mov r12, #1 */
/* @0x109df0 str r11, [sp] */
/* @0x109df4 mov r1, r10 */
/* @0x109df8 mov r2, r9 */
/* @0x109dfc stmib sp, {r0, r12} */
/* @0x109e00 mov r0, r6 */
/* @0x109e04 bl 0x19c9cc <_Z18Motion_Linear_PathP9CInstanceP5CPathfffib> */
/* @0x109e08 cmp r0, #0 */
/* @0x109e0c moveq r7, r0 */
/* @0x109e10 movne r3, r7 */
/* @0x109e14 moveq r3, r7 */
/* @0x109e18 movtne r3, #0x3ff0 */
/* @0x109e1c str r7, [r5] */
/* @0x109e20 str r3, [r5, #0x4] */
/* @0x109e24 add sp, sp, #20 */
/* @0x109e28 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x109e2c ldr r0, [pc, #0xc] */
/* @0x109e30 add r0, pc, r0 */
/* @0x109e34 add sp, sp, #20 */
/* @0x109e38 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x109e3c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x109e40 mlaeq r2, r12, r8, lr */

/* ── FUNC 0x109e44 · F_MpPotentialPath(RValue&, CInstance*, CInstance*, int, RValue*) · size=252 · insn=63 */
/* @0x109e44 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x109e48 sub sp, sp, #28 */
/* @0x109e4c mov r5, r0 */
/* @0x109e50 mov r6, r1 */
/* @0x109e54 ldr r4, [sp, #0x40] */
/* @0x109e58 mov r1, #0 */
/* @0x109e5c mov r0, r4 */
/* @0x109e60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109e64 mov r7, r0 */
/* @0x109e68 bl 0x1a8008 <_Z11Path_Existsi> */
/* @0x109e6c subs r1, r0, #0 */
/* @0x109e70 beq 0x109f28 <_Z17F_MpPotentialPathR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x109e74 mov r0, r7 */
/* @0x109e78 mov r7, #0 */
/* @0x109e7c str r7, [r5, #0xc] */
/* @0x109e80 bl 0x1a815c <_Z9Path_Datai> */
/* @0x109e84 mov r1, #1 */
/* @0x109e88 mov r10, r0 */
/* @0x109e8c mov r0, r4 */
/* @0x109e90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109e94 mov r1, #2 */
/* @0x109e98 mov r9, r0 */
/* @0x109e9c mov r0, r4 */
/* @0x109ea0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109ea4 mov r1, #3 */
/* @0x109ea8 mov r8, r0 */
/* @0x109eac mov r0, r4 */
/* @0x109eb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109eb4 mov r1, #4 */
/* @0x109eb8 mov r3, r0 */
/* @0x109ebc mov r0, r4 */
/* @0x109ec0 str r3, [sp, #0x14] */
/* @0x109ec4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109ec8 mov r1, #5 */
/* @0x109ecc mov r11, r0 */
/* @0x109ed0 mov r0, r4 */
/* @0x109ed4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x109ed8 ldr r3, [sp, #0x14] */
/* @0x109edc mvn r12, #2 */
/* @0x109ee0 str r11, [sp, #0x4] */
/* @0x109ee4 mov r1, r10 */
/* @0x109ee8 mov r2, r9 */
/* @0x109eec str r3, [sp] */
/* @0x109ef0 mov r3, r8 */
/* @0x109ef4 str r12, [sp, #0x8] */
/* @0x109ef8 str r0, [sp, #0xc] */
/* @0x109efc mov r0, r6 */
/* @0x109f00 bl 0x19ce94 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib> */
/* @0x109f04 cmp r0, #0 */
/* @0x109f08 moveq r7, r0 */
/* @0x109f0c movne r3, r7 */
/* @0x109f10 moveq r3, r7 */
/* @0x109f14 movtne r3, #0x3ff0 */
/* @0x109f18 str r7, [r5] */
/* @0x109f1c str r3, [r5, #0x4] */
/* @0x109f20 add sp, sp, #28 */
/* @0x109f24 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x109f28 ldr r0, [pc, #0xc] */
/* @0x109f2c add r0, pc, r0 */
/* @0x109f30 add sp, sp, #28 */
/* @0x109f34 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x109f38 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x109f3c eoreq lr, r2, r0, lsr #15 */

/* ── FUNC 0x109f40 · F_MpPotentialPathObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=252 · insn=63 */
/* @0x109f40 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x109f44 sub sp, sp, #28 */
/* @0x109f48 mov r5, r0 */
/* @0x109f4c mov r6, r1 */
/* @0x109f50 ldr r4, [sp, #0x40] */
/* @0x109f54 mov r1, #0 */
/* @0x109f58 mov r0, r4 */
/* @0x109f5c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109f60 mov r7, r0 */
/* @0x109f64 bl 0x1a8008 <_Z11Path_Existsi> */
/* @0x109f68 subs r1, r0, #0 */
/* @0x109f6c beq 0x10a024 <_Z23F_MpPotentialPathObjectR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x109f70 mov r0, r7 */
/* @0x109f74 mov r7, #0 */
/* @0x109f78 str r7, [r5, #0xc] */
/* @0x109f7c bl 0x1a815c <_Z9Path_Datai> */
/* @0x109f80 mov r1, #1 */
/* @0x109f84 mov r10, r0 */
/* @0x109f88 mov r0, r4 */
/* @0x109f8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109f90 mov r1, #2 */
/* @0x109f94 mov r9, r0 */
/* @0x109f98 mov r0, r4 */
/* @0x109f9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109fa0 mov r1, #3 */
/* @0x109fa4 mov r8, r0 */
/* @0x109fa8 mov r0, r4 */
/* @0x109fac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109fb0 mov r1, #4 */
/* @0x109fb4 mov r3, r0 */
/* @0x109fb8 mov r0, r4 */
/* @0x109fbc str r3, [sp, #0x14] */
/* @0x109fc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x109fc4 mov r1, #5 */
/* @0x109fc8 mov r11, r0 */
/* @0x109fcc mov r0, r4 */
/* @0x109fd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x109fd4 ldr r3, [sp, #0x14] */
/* @0x109fd8 mov r12, #1 */
/* @0x109fdc str r11, [sp, #0x4] */
/* @0x109fe0 mov r1, r10 */
/* @0x109fe4 mov r2, r9 */
/* @0x109fe8 str r3, [sp] */
/* @0x109fec mov r3, r8 */
/* @0x109ff0 str r12, [sp, #0xc] */
/* @0x109ff4 str r0, [sp, #0x8] */
/* @0x109ff8 mov r0, r6 */
/* @0x109ffc bl 0x19ce94 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib> */
/* @0x10a000 cmp r0, #0 */
/* @0x10a004 moveq r7, r0 */
/* @0x10a008 movne r3, r7 */
/* @0x10a00c moveq r3, r7 */
/* @0x10a010 movtne r3, #0x3ff0 */
/* @0x10a014 str r7, [r5] */
/* @0x10a018 str r3, [r5, #0x4] */
/* @0x10a01c add sp, sp, #28 */
/* @0x10a020 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x10a024 ldr r0, [pc, #0xc] */
/* @0x10a028 add r0, pc, r0 */
/* @0x10a02c add sp, sp, #28 */
/* @0x10a030 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10a034 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x10a038 eoreq lr, r2, r4, lsr #13 */

/* ── FUNC 0x10a03c · F_MpGridPath(RValue&, CInstance*, CInstance*, int, RValue*) · size=252 · insn=63 */
/* @0x10a03c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10a040 sub sp, sp, #28 */
/* @0x10a044 mov r1, #1 */
/* @0x10a048 mov r5, r0 */
/* @0x10a04c ldr r4, [sp, #0x40] */
/* @0x10a050 mov r0, r4 */
/* @0x10a054 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10a058 mov r7, r0 */
/* @0x10a05c bl 0x1a8008 <_Z11Path_Existsi> */
/* @0x10a060 subs r1, r0, #0 */
/* @0x10a064 beq 0x10a120 <_Z12F_MpGridPathR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x10a068 mov r6, #0 */
/* @0x10a06c mov r0, r4 */
/* @0x10a070 mov r1, r6 */
/* @0x10a074 str r6, [r5, #0xc] */
/* @0x10a078 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10a07c mov r8, r0 */
/* @0x10a080 mov r0, r7 */
/* @0x10a084 bl 0x1a815c <_Z9Path_Datai> */
/* @0x10a088 mov r1, #2 */
/* @0x10a08c mov r10, r0 */
/* @0x10a090 mov r0, r4 */
/* @0x10a094 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10a098 mov r1, #3 */
/* @0x10a09c mov r9, r0 */
/* @0x10a0a0 mov r0, r4 */
/* @0x10a0a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10a0a8 mov r1, #4 */
/* @0x10a0ac mov r7, r0 */
/* @0x10a0b0 mov r0, r4 */
/* @0x10a0b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10a0b8 mov r1, #5 */
/* @0x10a0bc mov r3, r0 */
/* @0x10a0c0 mov r0, r4 */
/* @0x10a0c4 str r3, [sp, #0x14] */
/* @0x10a0c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10a0cc mov r1, #6 */
/* @0x10a0d0 mov r11, r0 */
/* @0x10a0d4 mov r0, r4 */
/* @0x10a0d8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x10a0dc ldr r3, [sp, #0x14] */
/* @0x10a0e0 mov r1, r10 */
/* @0x10a0e4 mov r2, r9 */
/* @0x10a0e8 stm sp, {r3, r11} */
/* @0x10a0ec mov r3, r7 */
/* @0x10a0f0 str r0, [sp, #0x8] */
/* @0x10a0f4 mov r0, r8 */
/* @0x10a0f8 bl 0x19a8f8 <_Z16Motion_Grid_PathiP5CPathiiiib> */
/* @0x10a0fc cmp r0, #0 */
/* @0x10a100 moveq r6, r0 */
/* @0x10a104 movne r3, r6 */
/* @0x10a108 moveq r3, r6 */
/* @0x10a10c movtne r3, #0x3ff0 */
/* @0x10a110 str r6, [r5] */
/* @0x10a114 str r3, [r5, #0x4] */
/* @0x10a118 add sp, sp, #28 */
/* @0x10a11c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x10a120 ldr r0, [pc, #0xc] */
/* @0x10a124 add r0, pc, r0 */
/* @0x10a128 add sp, sp, #28 */
/* @0x10a12c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10a130 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x10a134 eoreq lr, r2, r8, lsr #11 */

/* ── FUNC 0x10a138 · collisionResultPM(CInstance*, void*) · size=264 · insn=66 */
/* @0x10a138 push {r3, r4, r5, r6, r7, lr} */
/* @0x10a13c mov r6, r1 */
/* @0x10a140 mov r5, r0 */
/* @0x10a144 bl 0x1cc244 <_Z18CollisionIsRemovedP9CInstance> */
/* @0x10a148 cmp r0, #0 */
/* @0x10a14c bne 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24> */
/* @0x10a150 ldrb r3, [r5, #0x68] */
/* @0x10a154 cmp r3, #0 */
/* @0x10a158 beq 0x10a168 <_Z17collisionResultPMP9CInstancePv+0x30> */
/* @0x10a15c mov r4, #1 */
/* @0x10a160 mov r0, r4 */
/* @0x10a164 pop {r3, r4, r5, r6, r7, pc} */
/* @0x10a168 ldrb r4, [r5, #0x69] */
/* @0x10a16c cmp r4, #0 */
/* @0x10a170 bne 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24> */
/* @0x10a174 ldr r7, [r5, #0x48] */
/* @0x10a178 cmp r7, #1 */
/* @0x10a17c bne 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24> */
/* @0x10a180 movw r2, #0x869f */
/* @0x10a184 movt r2, #0x1 */
/* @0x10a188 cmp r6, r2 */
/* @0x10a18c bgt 0x10a1f0 <_Z17collisionResultPMP9CInstancePv+0xb8> */
/* @0x10a190 ldr r0, [r5, #0x80] */
/* @0x10a194 ldr r3, [r0, #0x18] */
/* @0x10a198 cmp r6, r3 */
/* @0x10a19c beq 0x10a1b0 <_Z17collisionResultPMP9CInstancePv+0x78> */
/* @0x10a1a0 mov r1, r6 */
/* @0x10a1a4 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi> */
/* @0x10a1a8 cmp r0, #0 */
/* @0x10a1ac beq 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24> */
/* @0x10a1b0 ldr r6, [pc, #0x80] */
/* @0x10a1b4 mov r3, #1 */
/* @0x10a1b8 mov r0, r5 */
/* @0x10a1bc add r6, pc, r6 */
/* @0x10a1c0 vldr s15, [r6, #4] */
/* @0x10a1c4 vcvt.f32.s32 s15, s15 */
/* @0x10a1c8 vmov r1, s15 */
/* @0x10a1cc vldr s15, [r6, #8] */
/* @0x10a1d0 vcvt.f32.s32 s15, s15 */
/* @0x10a1d4 vmov r2, s15 */
/* @0x10a1d8 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x10a1dc cmp r0, #0 */
/* @0x10a1e0 movne r3, #1 */
/* @0x10a1e4 strbne r3, [r6] */
/* @0x10a1e8 bne 0x10a160 <_Z17collisionResultPMP9CInstancePv+0x28> */
/* @0x10a1ec b 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24> */
/* @0x10a1f0 ldr r3, [r5, #0x78] */
/* @0x10a1f4 cmp r3, r6 */
/* @0x10a1f8 bne 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24> */
/* @0x10a1fc ldr r6, [pc, #0x38] */
/* @0x10a200 mov r0, r5 */
/* @0x10a204 mov r3, r7 */
/* @0x10a208 add r6, pc, r6 */
/* @0x10a20c vldr s15, [r6, #4] */
/* @0x10a210 vcvt.f32.s32 s15, s15 */
/* @0x10a214 vmov r1, s15 */
/* @0x10a218 vldr s15, [r6, #8] */
/* @0x10a21c vcvt.f32.s32 s15, s15 */
/* @0x10a220 vmov r2, s15 */
/* @0x10a224 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x10a228 cmp r0, #0 */
/* @0x10a22c strbne r7, [r6] */
/* @0x10a230 bne 0x10a160 <_Z17collisionResultPMP9CInstancePv+0x28> */
/* @0x10a234 b 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24> */
/* @0x10a238 eorseq r9, r7, r12, lsl r5 */
/* @0x10a23c ldrsbteq r9, [r7], -r0 */

/* ── FUNC 0x10a240 · InstanceRegionDeactivate(CInstance*) · size=336 · insn=84 */
/* @0x10a240 ldrb r3, [r0, #0x68] */
/* @0x10a244 push {r4, r5, lr} */
/* @0x10a248 cmp r3, #0 */
/* @0x10a24c sub sp, sp, #12 */
/* @0x10a250 mov r4, r0 */
/* @0x10a254 bne 0x10a334 <_Z24InstanceRegionDeactivateP9CInstance+0xf4> */
/* @0x10a258 ldrb r3, [r0, #0x69] */
/* @0x10a25c cmp r3, #0 */
/* @0x10a260 bne 0x10a334 <_Z24InstanceRegionDeactivateP9CInstance+0xf4> */
/* @0x10a264 ldrb r3, [r0, #0x64] */
/* @0x10a268 cmp r3, #0 */
/* @0x10a26c bne 0x10a33c <_Z24InstanceRegionDeactivateP9CInstance+0xfc> */
/* @0x10a270 vldr s11, [r4, #232] */
/* @0x10a274 vcvt.f32.s32 s14, s11 */
/* @0x10a278 ldr r3, [pc, #0x100] */
/* @0x10a27c add r3, pc, r3 */
/* @0x10a280 vldr s15, [r3, #24] */
/* @0x10a284 vldr s13, [r3, #16] */
/* @0x10a288 ldr r3, [r4, #0xf0] */
/* @0x10a28c vcmpe.f32 s14, s15 */
/* @0x10a290 vmrs APSR_nzcv, fpscr */
/* @0x10a294 movgt r3, #1 */
/* @0x10a298 bgt 0x10a2b4 <_Z24InstanceRegionDeactivateP9CInstance+0x74> */
/* @0x10a29c vmov s12, r3 */
/* @0x10a2a0 vcvt.f32.s32 s15, s12 */
/* @0x10a2a4 vcmpe.f32 s15, s13 */
/* @0x10a2a8 vmrs APSR_nzcv, fpscr */
/* @0x10a2ac movpl r3, #0 */
/* @0x10a2b0 movmi r3, #1 */
/* @0x10a2b4 vldr s14, [r4, #244] */
/* @0x10a2b8 vcvt.f32.s32 s12, s14 */
/* @0x10a2bc vldr s11, [r4, #236] */
/* @0x10a2c0 ldr r2, [pc, #0xbc] */
/* @0x10a2c4 add r2, pc, r2 */
/* @0x10a2c8 vldr s13, [r2, #20] */
/* @0x10a2cc vldr s15, [r2, #28] */
/* @0x10a2d0 ldrb r2, [r2, #0xc] */
/* @0x10a2d4 vcvt.f32.s32 s14, s11 */
/* @0x10a2d8 vcmp.f32 s12, s13 */
/* @0x10a2dc vmrs APSR_nzcv, fpscr */
/* @0x10a2e0 vcmp.f32 s14, s15 */
/* @0x10a2e4 movmi r3, #1 */
/* @0x10a2e8 vmrs APSR_nzcv, fpscr */
/* @0x10a2ec movgt r3, #1 */
/* @0x10a2f0 cmp r2, r3 */
/* @0x10a2f4 beq 0x10a334 <_Z24InstanceRegionDeactivateP9CInstance+0xf4> */
/* @0x10a2f8 ldr r5, [pc, #0x88] */
/* @0x10a2fc ldr r5, [pc, r5] */
/* @0x10a300 ldr r1, [r5, #0x8] */
/* @0x10a304 ldr r3, [r5, #0x4] */
/* @0x10a308 cmp r1, r3 */
/* @0x10a30c beq 0x10a348 <_Z24InstanceRegionDeactivateP9CInstance+0x108> */
/* @0x10a310 ldr r3, [r5] */
/* @0x10a314 str r4, [r3, r1, lsl #2] */
/* @0x10a318 mov r0, r4 */
/* @0x10a31c add r3, r1, #1 */
/* @0x10a320 mov r1, #1 */
/* @0x10a324 str r3, [r5, #0x8] */
/* @0x10a328 add sp, sp, #12 */
/* @0x10a32c pop {r4, r5, lr} */
/* @0x10a330 b 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10a334 add sp, sp, #12 */
/* @0x10a338 pop {r4, r5, pc} */
/* @0x10a33c mov r1, #1 */
/* @0x10a340 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x10a344 b 0x10a270 <_Z24InstanceRegionDeactivateP9CInstance+0x30> */
/* @0x10a348 ldr r2, [pc, #0x3c] */
/* @0x10a34c lsl r3, r1, #1 */
/* @0x10a350 ldr r0, [r5] */
/* @0x10a354 lsl r1, r1, #3 */
/* @0x10a358 str r3, [r5, #0x4] */
/* @0x10a35c add r2, pc, r2 */
/* @0x10a360 mov r3, #0 */
/* @0x10a364 str r3, [sp] */
/* @0x10a368 mov r3, #74 */
/* @0x10a36c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10a370 ldr r1, [r5, #0x8] */
/* @0x10a374 mov r3, r0 */
/* @0x10a378 str r0, [r5] */
/* @0x10a37c b 0x10a314 <_Z24InstanceRegionDeactivateP9CInstance+0xd4> */
/* @0x10a380 eorseq r9, r7, r12, asr r4 */
/* @0x10a384 eorseq r9, r7, r4, lsl r4 */
/* @0x10a388 eoreq r3, lr, r12, asr #18 */
/* @0x10a38c .word 0x00226cd4 */

/* ── FUNC 0x10a390 · InstanceRegionActivate(CInstance*) · size=496 · insn=124 */
/* @0x10a390 push {r4, r5, lr} */
/* @0x10a394 mov r4, r0 */
/* @0x10a398 sub sp, sp, #12 */
/* @0x10a39c ldr r0, [r0, #0x8c] */
/* @0x10a3a0 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x10a3a4 cmp r0, #0 */
/* @0x10a3a8 beq 0x10a48c <_Z22InstanceRegionActivateP9CInstance+0xfc> */
/* @0x10a3ac ldrb r3, [r4, #0x64] */
/* @0x10a3b0 cmp r3, #0 */
/* @0x10a3b4 bne 0x10a554 <_Z22InstanceRegionActivateP9CInstance+0x1c4> */
/* @0x10a3b8 vldr s11, [r4, #232] */
/* @0x10a3bc vcvt.f32.s32 s14, s11 */
/* @0x10a3c0 ldr r3, [pc, #0x19c] */
/* @0x10a3c4 add r3, pc, r3 */
/* @0x10a3c8 vldr s15, [r3, #24] */
/* @0x10a3cc vldr s13, [r3, #16] */
/* @0x10a3d0 ldr r3, [r4, #0xf0] */
/* @0x10a3d4 vcmpe.f32 s14, s15 */
/* @0x10a3d8 vmrs APSR_nzcv, fpscr */
/* @0x10a3dc movgt r3, #1 */
/* @0x10a3e0 ble 0x10a504 <_Z22InstanceRegionActivateP9CInstance+0x174> */
/* @0x10a3e4 vldr s14, [r4, #244] */
/* @0x10a3e8 vcvt.f32.s32 s12, s14 */
/* @0x10a3ec vldr s11, [r4, #236] */
/* @0x10a3f0 ldr r2, [pc, #0x170] */
/* @0x10a3f4 add r2, pc, r2 */
/* @0x10a3f8 vldr s13, [r2, #20] */
/* @0x10a3fc vldr s15, [r2, #28] */
/* @0x10a400 vcvt.f32.s32 s14, s11 */
/* @0x10a404 vcmp.f32 s12, s13 */
/* @0x10a408 vmrs APSR_nzcv, fpscr */
/* @0x10a40c vcmpe.f32 s14, s15 */
/* @0x10a410 movmi r3, #1 */
/* @0x10a414 vmrs APSR_nzcv, fpscr */
/* @0x10a418 bgt 0x10a4fc <_Z22InstanceRegionActivateP9CInstance+0x16c> */
/* @0x10a41c ldr r2, [pc, #0x148] */
/* @0x10a420 add r2, pc, r2 */
/* @0x10a424 ldrb r2, [r2, #0xc] */
/* @0x10a428 cmp r2, r3 */
/* @0x10a42c beq 0x10a484 <_Z22InstanceRegionActivateP9CInstance+0xf4> */
/* @0x10a430 ldrb r12, [r4, #0x68] */
/* @0x10a434 cmp r12, #0 */
/* @0x10a438 bne 0x10a484 <_Z22InstanceRegionActivateP9CInstance+0xf4> */
/* @0x10a43c ldrb r3, [r4, #0x69] */
/* @0x10a440 cmp r3, #0 */
/* @0x10a444 beq 0x10a484 <_Z22InstanceRegionActivateP9CInstance+0xf4> */
/* @0x10a448 ldr r5, [pc, #0x120] */
/* @0x10a44c ldr r5, [pc, r5] */
/* @0x10a450 ldr r1, [r5, #0x8] */
/* @0x10a454 ldr r3, [r5, #0x4] */
/* @0x10a458 cmp r1, r3 */
/* @0x10a45c beq 0x10a520 <_Z22InstanceRegionActivateP9CInstance+0x190> */
/* @0x10a460 ldr r3, [r5] */
/* @0x10a464 str r4, [r3, r1, lsl #2] */
/* @0x10a468 mov r0, r4 */
/* @0x10a46c add r3, r1, #1 */
/* @0x10a470 mov r1, #0 */
/* @0x10a474 str r3, [r5, #0x8] */
/* @0x10a478 add sp, sp, #12 */
/* @0x10a47c pop {r4, r5, lr} */
/* @0x10a480 b 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10a484 add sp, sp, #12 */
/* @0x10a488 pop {r4, r5, pc} */
/* @0x10a48c ldr r0, [r4, #0xac] */
/* @0x10a490 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x10a494 cmp r0, #0 */
/* @0x10a498 bne 0x10a3ac <_Z22InstanceRegionActivateP9CInstance+0x1c> */
/* @0x10a49c ldr r3, [pc, #0xd0] */
/* @0x10a4a0 vldr s15, [r4, #180] */
/* @0x10a4a4 add r3, pc, r3 */
/* @0x10a4a8 vldr s14, [r3, #24] */
/* @0x10a4ac vcmpe.f32 s15, s14 */
/* @0x10a4b0 vldr s14, [r3, #16] */
/* @0x10a4b4 vmrs APSR_nzcv, fpscr */
/* @0x10a4b8 movgt r3, #1 */
/* @0x10a4bc bgt 0x10a4d0 <_Z22InstanceRegionActivateP9CInstance+0x140> */
/* @0x10a4c0 vcmpe.f32 s15, s14 */
/* @0x10a4c4 vmrs APSR_nzcv, fpscr */
/* @0x10a4c8 movpl r3, #0 */
/* @0x10a4cc movmi r3, #1 */
/* @0x10a4d0 ldr r2, [pc, #0xa0] */
/* @0x10a4d4 vldr s15, [r4, #184] */
/* @0x10a4d8 add r2, pc, r2 */
/* @0x10a4dc vldr s14, [r2, #20] */
/* @0x10a4e0 vcmp.f32 s15, s14 */
/* @0x10a4e4 vldr s14, [r2, #28] */
/* @0x10a4e8 vmrs APSR_nzcv, fpscr */
/* @0x10a4ec vcmpe.f32 s15, s14 */
/* @0x10a4f0 movmi r3, #1 */
/* @0x10a4f4 vmrs APSR_nzcv, fpscr */
/* @0x10a4f8 ble 0x10a41c <_Z22InstanceRegionActivateP9CInstance+0x8c> */
/* @0x10a4fc mov r3, #1 */
/* @0x10a500 b 0x10a41c <_Z22InstanceRegionActivateP9CInstance+0x8c> */
/* @0x10a504 vmov s12, r3 */
/* @0x10a508 vcvt.f32.s32 s15, s12 */
/* @0x10a50c vcmpe.f32 s15, s13 */
/* @0x10a510 vmrs APSR_nzcv, fpscr */
/* @0x10a514 movpl r3, #0 */
/* @0x10a518 movmi r3, #1 */
/* @0x10a51c b 0x10a3e4 <_Z22InstanceRegionActivateP9CInstance+0x54> */
/* @0x10a520 ldr r2, [pc, #0x54] */
/* @0x10a524 lsl r3, r1, #1 */
/* @0x10a528 ldr r0, [r5] */
/* @0x10a52c lsl r1, r1, #3 */
/* @0x10a530 str r3, [r5, #0x4] */
/* @0x10a534 add r2, pc, r2 */
/* @0x10a538 mov r3, #74 */
/* @0x10a53c str r12, [sp] */
/* @0x10a540 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10a544 ldr r1, [r5, #0x8] */
/* @0x10a548 mov r3, r0 */
/* @0x10a54c str r0, [r5] */
/* @0x10a550 b 0x10a464 <_Z22InstanceRegionActivateP9CInstance+0xd4> */
/* @0x10a554 mov r0, r4 */
/* @0x10a558 mov r1, #1 */
/* @0x10a55c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x10a560 b 0x10a3b8 <_Z22InstanceRegionActivateP9CInstance+0x28> */
/* @0x10a564 eorseq r9, r7, r4, lsl r3 */
/* @0x10a568 eorseq r9, r7, r4, ror #5 */
/* @0x10a56c ldrhteq r9, [r7], -r8 */
/* @0x10a570 .word 0x002e37fc */
/* @0x10a574 eorseq r9, r7, r4, lsr r2 */
/* @0x10a578 eorseq r9, r7, r0, lsl #4 */
/* @0x10a57c .word 0x00226afc */

/* ── FUNC 0x10a580 · F_InstanceDeactivateObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=392 · insn=98 */
/* @0x10a580 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x10a584 sub sp, sp, #48 */
/* @0x10a588 mov r7, r1 */
/* @0x10a58c mov r1, #0 */
/* @0x10a590 ldr r0, [sp, #0x50] */
/* @0x10a594 mov r4, r2 */
/* @0x10a598 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10a59c ldr r1, [pc, #0x154] */
/* @0x10a5a0 mov r2, #50 */
/* @0x10a5a4 mov r3, #1 */
/* @0x10a5a8 add r1, pc, r1 */
/* @0x10a5ac add r5, sp, #12 */
/* @0x10a5b0 mov r6, #0 */
/* @0x10a5b4 mov r9, r0 */
/* @0x10a5b8 mov r0, #128 */
/* @0x10a5bc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x10a5c0 mov r1, r9 */
/* @0x10a5c4 ldr r9, [pc, #0x130] */
/* @0x10a5c8 mov r2, r7 */
/* @0x10a5cc mov r3, r4 */
/* @0x10a5d0 str r6, [sp] */
/* @0x10a5d4 mov r7, #32 */
/* @0x10a5d8 add r9, pc, r9 */
/* @0x10a5dc mov r8, r0 */
/* @0x10a5e0 mov r0, r5 */
/* @0x10a5e4 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */
/* @0x10a5e8 b 0x10a630 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10a5ec bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10a5f0 ldrb r3, [r0, #0x68] */
/* @0x10a5f4 mov r4, r0 */
/* @0x10a5f8 cmp r3, #0 */
/* @0x10a5fc bne 0x10a628 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x10a600 ldrb r3, [r0, #0x69] */
/* @0x10a604 cmp r3, #0 */
/* @0x10a608 bne 0x10a628 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x10a60c cmp r6, r7 */
/* @0x10a610 beq 0x10a6d4 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x10a614 str r4, [r8, r6, lsl #2] */
/* @0x10a618 mov r1, #1 */
/* @0x10a61c mov r0, r4 */
/* @0x10a620 add r6, r6, r1 */
/* @0x10a624 bl 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10a628 mov r0, r5 */
/* @0x10a62c bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */
/* @0x10a630 mov r0, r5 */
/* @0x10a634 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10a638 subs r4, r0, #0 */
/* @0x10a63c mov r0, r5 */
/* @0x10a640 bne 0x10a5ec <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x10a644 cmp r6, #0 */
/* @0x10a648 beq 0x10a6c4 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x10a64c ldr r5, [pc, #0xac] */
/* @0x10a650 mov r9, r4 */
/* @0x10a654 ldr r10, [pc, #0xa8] */
/* @0x10a658 ldr r5, [pc, r5] */
/* @0x10a65c add r10, pc, r10 */
/* @0x10a660 ldr r1, [r5, #0x8] */
/* @0x10a664 b 0x10a684 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x10a668 ldr r3, [r5] */
/* @0x10a66c add r4, r4, #1 */
/* @0x10a670 str r7, [r3, r1, lsl #2] */
/* @0x10a674 cmp r4, r6 */
/* @0x10a678 add r1, r1, #1 */
/* @0x10a67c str r1, [r5, #0x8] */
/* @0x10a680 beq 0x10a6c4 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x10a684 ldr r3, [r5, #0x4] */
/* @0x10a688 ldr r7, [r8, r4, lsl #2] */
/* @0x10a68c cmp r1, r3 */
/* @0x10a690 bne 0x10a668 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x10a694 lsl r3, r1, #1 */
/* @0x10a698 ldr r0, [r5] */
/* @0x10a69c str r3, [r5, #0x4] */
/* @0x10a6a0 lsl r1, r1, #3 */
/* @0x10a6a4 mov r3, #74 */
/* @0x10a6a8 mov r2, r10 */
/* @0x10a6ac str r9, [sp] */
/* @0x10a6b0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10a6b4 ldr r1, [r5, #0x8] */
/* @0x10a6b8 mov r3, r0 */
/* @0x10a6bc str r0, [r5] */
/* @0x10a6c0 b 0x10a66c <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x10a6c4 mov r0, r8 */
/* @0x10a6c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x10a6cc add sp, sp, #48 */
/* @0x10a6d0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x10a6d4 str r3, [sp] */
/* @0x10a6d8 mov r0, r8 */
/* @0x10a6dc lsl r1, r6, #3 */
/* @0x10a6e0 mov r2, r9 */
/* @0x10a6e4 mov r3, #74 */
/* @0x10a6e8 lsl r7, r6, #1 */
/* @0x10a6ec bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10a6f0 mov r8, r0 */
/* @0x10a6f4 b 0x10a614 <_Z26F_InstanceDeactivateObjectR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x10a6f8 eoreq lr, r2, r0, asr r1 */
/* @0x10a6fc eoreq r6, r2, r8, asr r10 */
/* @0x10a700 .word 0x002e35f0 */
/* @0x10a704 .word 0x002269d4 */

/* ── FUNC 0x10a708 · InstanceRegionDeactivateSpecial(CInstance*) · size=1388 · insn=347 */
/* @0x10a708 ldrb r3, [r0, #0x68] */
/* @0x10a70c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x10a710 cmp r3, #0 */
/* @0x10a714 ldr r4, [pc, #0x530] */
/* @0x10a718 sub sp, sp, #8 */
/* @0x10a71c mov r5, r0 */
/* @0x10a720 add r4, pc, r4 */
/* @0x10a724 bne 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c> */
/* @0x10a728 ldrb r10, [r0, #0x69] */
/* @0x10a72c cmp r10, #0 */
/* @0x10a730 bne 0x10a9ac <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x2a4> */
/* @0x10a734 ldr r2, [pc, #0x514] */
/* @0x10a738 mvn r3, #-16777216 */
/* @0x10a73c ldr r2, [r4, r2] */
/* @0x10a740 ldr r7, [r2] */
/* @0x10a744 ldr r2, [r7, #0xc] */
/* @0x10a748 cmp r2, r3 */
/* @0x10a74c beq 0x10a888 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x180> */
/* @0x10a750 ldr r0, [r7] */
/* @0x10a754 ldr r8, [r5, #0x80] */
/* @0x10a758 ldr r3, [r0, #0x4] */
/* @0x10a75c ldm r3, {r2, r9} */
/* @0x10a760 cmp r2, #0 */
/* @0x10a764 ble 0x10a888 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x180> */
/* @0x10a768 vldr s11, [r5, #124] */
/* @0x10a76c vcvt.f64.s32 d6, s11 */
/* @0x10a770 vldr s14, [r9] */
/* @0x10a774 vldr s15, [r9, #4] */
/* @0x10a778 vcmp.f64 d6, d7 */
/* @0x10a77c vmrs APSR_nzcv, fpscr */
/* @0x10a780 beq 0x10a84c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x144> */
/* @0x10a784 vldr s11, [r5, #120] */
/* @0x10a788 vcvt.f64.s32 d6, s11 */
/* @0x10a78c vcmp.f64 d7, d6 */
/* @0x10a790 vmrs APSR_nzcv, fpscr */
/* @0x10a794 beq 0x10a84c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x144> */
/* @0x10a798 ldr r3, [pc, #0x4b4] */
/* @0x10a79c add r9, r9, #16 */
/* @0x10a7a0 ldr r6, [r4, r3] */
/* @0x10a7a4 vcvt.s32.f64 s12, d7 */
/* @0x10a7a8 ldr r3, [r6] */
/* @0x10a7ac ldr r2, [r3, #0x4] */
/* @0x10a7b0 ldr r3, [r3] */
/* @0x10a7b4 vmov r1, s12 */
/* @0x10a7b8 and r2, r1, r2 */
/* @0x10a7bc ldr r3, [r3, r2, lsl #3] */
/* @0x10a7c0 cmp r3, #0 */
/* @0x10a7c4 bne 0x10a7d8 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0xd0> */
/* @0x10a7c8 b 0x10a804 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0xfc> */
/* @0x10a7cc ldr r3, [r3, #0x4] */
/* @0x10a7d0 cmp r3, #0 */
/* @0x10a7d4 beq 0x10a804 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0xfc> */
/* @0x10a7d8 ldr r2, [r3, #0x8] */
/* @0x10a7dc cmp r1, r2 */
/* @0x10a7e0 bne 0x10a7cc <_Z31InstanceRegionDeactivateSpecialP9CInstance+0xc4> */
/* @0x10a7e4 ldr r3, [r3, #0xc] */
/* @0x10a7e8 cmp r3, #0 */
/* @0x10a7ec beq 0x10a804 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0xfc> */
/* @0x10a7f0 mov r0, r8 */
/* @0x10a7f4 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi> */
/* @0x10a7f8 cmp r0, #0 */
/* @0x10a7fc bne 0x10a84c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x144> */
/* @0x10a800 ldr r0, [r7] */
/* @0x10a804 ldr r3, [r0, #0x4] */
/* @0x10a808 add r10, r10, #1 */
/* @0x10a80c ldr r3, [r3] */
/* @0x10a810 cmp r10, r3 */
/* @0x10a814 bge 0x10a888 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x180> */
/* @0x10a818 vldr s11, [r5, #124] */
/* @0x10a81c vcvt.f64.s32 d6, s11 */
/* @0x10a820 vldr s14, [r9] */
/* @0x10a824 vldr s15, [r9, #4] */
/* @0x10a828 vcmp.f64 d6, d7 */
/* @0x10a82c vmrs APSR_nzcv, fpscr */
/* @0x10a830 beq 0x10a84c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x144> */
/* @0x10a834 vldr s11, [r5, #120] */
/* @0x10a838 vcvt.f64.s32 d6, s11 */
/* @0x10a83c add r9, r9, #16 */
/* @0x10a840 vcmp.f64 d7, d6 */
/* @0x10a844 vmrs APSR_nzcv, fpscr */
/* @0x10a848 bne 0x10a7a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x9c> */
/* @0x10a84c ldr r3, [pc, #0x404] */
/* @0x10a850 ldr r4, [r4, r3] */
/* @0x10a854 ldr r1, [r4, #0x8] */
/* @0x10a858 ldr r3, [r4, #0x4] */
/* @0x10a85c cmp r1, r3 */
/* @0x10a860 beq 0x10abf4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x4ec> */
/* @0x10a864 ldr r3, [r4] */
/* @0x10a868 str r5, [r3, r1, lsl #2] */
/* @0x10a86c mov r0, r5 */
/* @0x10a870 add r3, r1, #1 */
/* @0x10a874 mov r1, #1 */
/* @0x10a878 str r3, [r4, #0x8] */
/* @0x10a87c add sp, sp, #8 */
/* @0x10a880 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x10a884 b 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10a888 ldr r2, [pc, #0x3cc] */
/* @0x10a88c mvn r3, #-16777216 */
/* @0x10a890 ldr r2, [r4, r2] */
/* @0x10a894 ldr r7, [r2] */
/* @0x10a898 ldr r2, [r7, #0xc] */
/* @0x10a89c cmp r2, r3 */
/* @0x10a8a0 beq 0x10ab04 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3fc> */
/* @0x10a8a4 ldr r0, [r7] */
/* @0x10a8a8 ldr r8, [r5, #0x80] */
/* @0x10a8ac ldr r3, [r0, #0x4] */
/* @0x10a8b0 ldm r3, {r2, r9} */
/* @0x10a8b4 cmp r2, #0 */
/* @0x10a8b8 ble 0x10ab04 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3fc> */
/* @0x10a8bc vldr s11, [r5, #124] */
/* @0x10a8c0 vcvt.f64.s32 d6, s11 */
/* @0x10a8c4 vldr s14, [r9] */
/* @0x10a8c8 vldr s15, [r9, #4] */
/* @0x10a8cc vcmp.f64 d6, d7 */
/* @0x10a8d0 vmrs APSR_nzcv, fpscr */
/* @0x10a8d4 beq 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c> */
/* @0x10a8d8 vldr s11, [r5, #120] */
/* @0x10a8dc vcvt.f64.s32 d6, s11 */
/* @0x10a8e0 vcmp.f64 d7, d6 */
/* @0x10a8e4 vmrs APSR_nzcv, fpscr */
/* @0x10a8e8 beq 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c> */
/* @0x10a8ec ldr r3, [pc, #0x360] */
/* @0x10a8f0 add r9, r9, #16 */
/* @0x10a8f4 mov r10, #0 */
/* @0x10a8f8 ldr r6, [r4, r3] */
/* @0x10a8fc vcvt.s32.f64 s12, d7 */
/* @0x10a900 ldr r3, [r6] */
/* @0x10a904 ldr r2, [r3, #0x4] */
/* @0x10a908 ldr r3, [r3] */
/* @0x10a90c vmov r1, s12 */
/* @0x10a910 and r2, r1, r2 */
/* @0x10a914 ldr r3, [r3, r2, lsl #3] */
/* @0x10a918 cmp r3, #0 */
/* @0x10a91c bne 0x10a930 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x228> */
/* @0x10a920 b 0x10a95c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x254> */
/* @0x10a924 ldr r3, [r3, #0x4] */
/* @0x10a928 cmp r3, #0 */
/* @0x10a92c beq 0x10a95c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x254> */
/* @0x10a930 ldr r2, [r3, #0x8] */
/* @0x10a934 cmp r1, r2 */
/* @0x10a938 bne 0x10a924 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x21c> */
/* @0x10a93c ldr r3, [r3, #0xc] */
/* @0x10a940 cmp r3, #0 */
/* @0x10a944 beq 0x10a95c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x254> */
/* @0x10a948 mov r0, r8 */
/* @0x10a94c bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi> */
/* @0x10a950 cmp r0, #0 */
/* @0x10a954 bne 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c> */
/* @0x10a958 ldr r0, [r7] */
/* @0x10a95c ldr r3, [r0, #0x4] */
/* @0x10a960 add r10, r10, #1 */
/* @0x10a964 ldr r3, [r3] */
/* @0x10a968 cmp r10, r3 */
/* @0x10a96c bge 0x10ab04 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3fc> */
/* @0x10a970 vldr s11, [r5, #124] */
/* @0x10a974 vcvt.f64.s32 d6, s11 */
/* @0x10a978 vldr s14, [r9] */
/* @0x10a97c vldr s15, [r9, #4] */
/* @0x10a980 vcmp.f64 d6, d7 */
/* @0x10a984 vmrs APSR_nzcv, fpscr */
/* @0x10a988 beq 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c> */
/* @0x10a98c vldr s11, [r5, #120] */
/* @0x10a990 vcvt.f64.s32 d6, s11 */
/* @0x10a994 add r9, r9, #16 */
/* @0x10a998 vcmp.f64 d7, d6 */
/* @0x10a99c vmrs APSR_nzcv, fpscr */
/* @0x10a9a0 bne 0x10a8fc <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x1f4> */
/* @0x10a9a4 add sp, sp, #8 */
/* @0x10a9a8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x10a9ac ldr r1, [pc, #0x2a8] */
/* @0x10a9b0 mvn r2, #-16777216 */
/* @0x10a9b4 ldr r1, [r4, r1] */
/* @0x10a9b8 ldr r7, [r1] */
/* @0x10a9bc ldr r1, [r7, #0xc] */
/* @0x10a9c0 cmp r1, r2 */
/* @0x10a9c4 beq 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c> */
/* @0x10a9c8 ldr r0, [r7] */
/* @0x10a9cc ldr r8, [r5, #0x80] */
/* @0x10a9d0 ldr r2, [r0, #0x4] */
/* @0x10a9d4 ldm r2, {r1, r9} */
/* @0x10a9d8 cmp r1, #0 */
/* @0x10a9dc ble 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c> */
/* @0x10a9e0 vldr s11, [r5, #124] */
/* @0x10a9e4 vcvt.f64.s32 d6, s11 */
/* @0x10a9e8 vldr s14, [r9] */
/* @0x10a9ec vldr s15, [r9, #4] */
/* @0x10a9f0 vcmp.f64 d6, d7 */
/* @0x10a9f4 vmrs APSR_nzcv, fpscr */
/* @0x10a9f8 beq 0x10aac8 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3c0> */
/* @0x10a9fc vldr s11, [r5, #120] */
/* @0x10aa00 vcvt.f64.s32 d6, s11 */
/* @0x10aa04 vcmp.f64 d7, d6 */
/* @0x10aa08 vmrs APSR_nzcv, fpscr */
/* @0x10aa0c beq 0x10aac8 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3c0> */
/* @0x10aa10 ldr r2, [pc, #0x23c] */
/* @0x10aa14 add r9, r9, #16 */
/* @0x10aa18 mov r10, r3 */
/* @0x10aa1c ldr r6, [r4, r2] */
/* @0x10aa20 vcvt.s32.f64 s12, d7 */
/* @0x10aa24 ldr r3, [r6] */
/* @0x10aa28 ldr r2, [r3, #0x4] */
/* @0x10aa2c ldr r3, [r3] */
/* @0x10aa30 vmov r1, s12 */
/* @0x10aa34 and r2, r1, r2 */
/* @0x10aa38 ldr r3, [r3, r2, lsl #3] */
/* @0x10aa3c cmp r3, #0 */
/* @0x10aa40 bne 0x10aa54 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x34c> */
/* @0x10aa44 b 0x10aa80 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x378> */
/* @0x10aa48 ldr r3, [r3, #0x4] */
/* @0x10aa4c cmp r3, #0 */
/* @0x10aa50 beq 0x10aa80 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x378> */
/* @0x10aa54 ldr r2, [r3, #0x8] */
/* @0x10aa58 cmp r1, r2 */
/* @0x10aa5c bne 0x10aa48 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x340> */
/* @0x10aa60 ldr r3, [r3, #0xc] */
/* @0x10aa64 cmp r3, #0 */
/* @0x10aa68 beq 0x10aa80 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x378> */
/* @0x10aa6c mov r0, r8 */
/* @0x10aa70 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi> */
/* @0x10aa74 cmp r0, #0 */
/* @0x10aa78 bne 0x10aac8 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3c0> */
/* @0x10aa7c ldr r0, [r7] */
/* @0x10aa80 ldr r3, [r0, #0x4] */
/* @0x10aa84 add r10, r10, #1 */
/* @0x10aa88 ldr r3, [r3] */
/* @0x10aa8c cmp r10, r3 */
/* @0x10aa90 bge 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c> */
/* @0x10aa94 vldr s11, [r5, #124] */
/* @0x10aa98 vcvt.f64.s32 d6, s11 */
/* @0x10aa9c vldr s14, [r9] */
/* @0x10aaa0 vldr s15, [r9, #4] */
/* @0x10aaa4 vcmp.f64 d6, d7 */
/* @0x10aaa8 vmrs APSR_nzcv, fpscr */
/* @0x10aaac beq 0x10aac8 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3c0> */
/* @0x10aab0 vldr s11, [r5, #120] */
/* @0x10aab4 vcvt.f64.s32 d6, s11 */
/* @0x10aab8 add r9, r9, #16 */
/* @0x10aabc vcmp.f64 d7, d6 */
/* @0x10aac0 vmrs APSR_nzcv, fpscr */
/* @0x10aac4 bne 0x10aa20 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x318> */
/* @0x10aac8 ldr r3, [pc, #0x188] */
/* @0x10aacc ldr r4, [r4, r3] */
/* @0x10aad0 ldr r1, [r4, #0x8] */
/* @0x10aad4 ldr r3, [r4, #0x4] */
/* @0x10aad8 cmp r1, r3 */
/* @0x10aadc beq 0x10ac14 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x50c> */
/* @0x10aae0 ldr r3, [r4] */
/* @0x10aae4 str r5, [r3, r1, lsl #2] */
/* @0x10aae8 mov r0, r5 */
/* @0x10aaec add r3, r1, #1 */
/* @0x10aaf0 mov r1, #0 */
/* @0x10aaf4 str r3, [r4, #0x8] */
/* @0x10aaf8 add sp, sp, #8 */
/* @0x10aafc pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x10ab00 b 0x19230c <_ZN9CInstance14SetDeactivatedEb> */
/* @0x10ab04 ldrb r3, [r5, #0x64] */
/* @0x10ab08 cmp r3, #0 */
/* @0x10ab0c beq 0x10ab1c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x414> */
/* @0x10ab10 mov r0, r5 */
/* @0x10ab14 mov r1, #1 */
/* @0x10ab18 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x10ab1c vldr s12, [r5, #232] */
/* @0x10ab20 vcvt.f32.s32 s14, s12 */
/* @0x10ab24 ldr r3, [pc, #0x134] */
/* @0x10ab28 add r3, pc, r3 */
/* @0x10ab2c vldr s15, [r3, #24] */
/* @0x10ab30 vldr s13, [r3, #16] */
/* @0x10ab34 ldr r3, [r5, #0xf0] */
/* @0x10ab38 vcmpe.f32 s14, s15 */
/* @0x10ab3c vmrs APSR_nzcv, fpscr */
/* @0x10ab40 movgt r3, #1 */
/* @0x10ab44 bgt 0x10ab60 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x458> */
/* @0x10ab48 vmov s14, r3 */
/* @0x10ab4c vcvt.f32.s32 s15, s14 */
/* @0x10ab50 vcmpe.f32 s15, s13 */
/* @0x10ab54 vmrs APSR_nzcv, fpscr */
/* @0x10ab58 movpl r3, #0 */
/* @0x10ab5c movmi r3, #1 */
/* @0x10ab60 vldr s15, [r5, #244] */
/* @0x10ab64 vcvt.f32.s32 s12, s15 */
/* @0x10ab68 vldr s11, [r5, #236] */
/* @0x10ab6c ldr r2, [pc, #0xf0] */
/* @0x10ab70 add r2, pc, r2 */
/* @0x10ab74 vldr s13, [r2, #20] */
/* @0x10ab78 vldr s15, [r2, #28] */
/* @0x10ab7c ldrb r2, [r2, #0xc] */
/* @0x10ab80 vcvt.f32.s32 s14, s11 */
/* @0x10ab84 vcmp.f32 s12, s13 */
/* @0x10ab88 vmrs APSR_nzcv, fpscr */
/* @0x10ab8c vcmp.f32 s14, s15 */
/* @0x10ab90 movmi r3, #1 */
/* @0x10ab94 vmrs APSR_nzcv, fpscr */
/* @0x10ab98 movgt r3, #1 */
/* @0x10ab9c cmp r2, r3 */
/* @0x10aba0 beq 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c> */
/* @0x10aba4 ldr r3, [pc, #0xac] */
/* @0x10aba8 ldr r4, [r4, r3] */
/* @0x10abac ldr r1, [r4, #0x8] */
/* @0x10abb0 ldr r3, [r4, #0x4] */
/* @0x10abb4 cmp r1, r3 */
/* @0x10abb8 bne 0x10a864 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x15c> */
/* @0x10abbc ldr r2, [pc, #0xa4] */
/* @0x10abc0 lsl r3, r1, #1 */
/* @0x10abc4 ldr r0, [r4] */
/* @0x10abc8 lsl r1, r1, #3 */
/* @0x10abcc add r2, pc, r2 */
/* @0x10abd0 str r3, [r4, #0x4] */
/* @0x10abd4 mov r3, #0 */
/* @0x10abd8 str r3, [sp] */
/* @0x10abdc mov r3, #74 */
/* @0x10abe0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10abe4 ldr r1, [r4, #0x8] */
/* @0x10abe8 mov r3, r0 */
/* @0x10abec str r0, [r4] */
/* @0x10abf0 b 0x10a868 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x160> */
/* @0x10abf4 ldr r2, [pc, #0x70] */
/* @0x10abf8 lsl r3, r1, #1 */
/* @0x10abfc ldr r0, [r4] */
/* @0x10ac00 lsl r1, r1, #3 */
/* @0x10ac04 str r3, [r4, #0x4] */
/* @0x10ac08 add r2, pc, r2 */
/* @0x10ac0c mov r3, #0 */
/* @0x10ac10 b 0x10abd8 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x4d0> */
/* @0x10ac14 ldr r2, [pc, #0x54] */
/* @0x10ac18 lsl r3, r1, #1 */
/* @0x10ac1c ldr r0, [r4] */
/* @0x10ac20 lsl r1, r1, #3 */
/* @0x10ac24 str r3, [r4, #0x4] */
/* @0x10ac28 add r2, pc, r2 */
/* @0x10ac2c mov r3, #0 */
/* @0x10ac30 str r3, [sp] */
/* @0x10ac34 mov r3, #74 */
/* @0x10ac38 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x10ac3c ldr r1, [r4, #0x8] */
/* @0x10ac40 mov r3, r0 */
/* @0x10ac44 str r0, [r4] */
/* @0x10ac48 b 0x10aae4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3dc> */
/* @0x10ac4c eoreq r7, lr, r0, lsr r5 */
/* @0x10ac50 .word 0xffffc45c */
/* @0x10ac54 .word 0xffffbfec */
/* @0x10ac58 .word 0xffffbff8 */
/* @0x10ac5c .word 0xffffc460 */
/* @0x10ac60 ldrhteq r8, [r7], -r0 */
/* @0x10ac64 eorseq r8, r7, r8, ror #22 */
/* @0x10ac68 eoreq r6, r2, r4, ror #8 */
/* @0x10ac6c eoreq r6, r2, r8, lsr #8 */
/* @0x10ac70 eoreq r6, r2, r8, lsl #8 */

/* ── FUNC 0x10ac74 · YYGML_place_free(CInstance*, float, float) · size=4 · insn=1 */
/* @0x10ac74 b 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
