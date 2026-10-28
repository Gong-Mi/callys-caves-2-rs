/* libyoyo.so 覆盖卡组 0076
 * 函数 0x1415ac..0x1434a4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1415ac · F_ActionSetGravity(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1415ac push {r4, r5, r6, lr} */
/* @0x1415b0 mov r6, r1 */
/* @0x1415b4 ldr r4, [sp, #0x10] */
/* @0x1415b8 mov r1, #0 */
/* @0x1415bc mov r0, r4 */
/* @0x1415c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1415c4 mov r1, #1 */
/* @0x1415c8 mov r5, r0 */
/* @0x1415cc mov r0, r4 */
/* @0x1415d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1415d4 mov r1, r5 */
/* @0x1415d8 mov r2, r0 */
/* @0x1415dc mov r0, r6 */
/* @0x1415e0 pop {r4, r5, r6, lr} */
/* @0x1415e4 b 0x141574 <_Z24YYGML_action_set_gravityP9CInstanceff> */

/* ── FUNC 0x1415e8 · YYGML_action_move_point(CInstance*, float, float, float) · size=76 · insn=19 */
/* @0x1415e8 ldr r12, [pc, #0x40] */
/* @0x1415ec vmov s14, r1 */
/* @0x1415f0 str r4, [sp, #-0x4]! */
/* @0x1415f4 ldr r12, [pc, r12] */
/* @0x1415f8 vmov s15, r2 */
/* @0x1415fc ldrb r12, [r12] */
/* @0x141600 cmp r12, #0 */
/* @0x141604 bne 0x141610 <_Z23YYGML_action_move_pointP9CInstancefff+0x28> */
/* @0x141608 ldr r4, [sp], #4 */
/* @0x14160c b 0x1c97ec <_Z19Command_MoveTowardsP9CInstancefff> */
/* @0x141610 vldr s12, [r0, #180] */
/* @0x141614 vldr s13, [r0, #184] */
/* @0x141618 vadd.f32 s12, s14, s12 */
/* @0x14161c ldr r4, [sp], #4 */
/* @0x141620 vadd.f32 s13, s15, s13 */
/* @0x141624 vmov r1, s12 */
/* @0x141628 vmov r2, s13 */
/* @0x14162c b 0x1c97ec <_Z19Command_MoveTowardsP9CInstancefff> */
/* @0x141630 eoreq r12, r10, r8, asr #10 */

/* ── FUNC 0x141634 · F_ActionMovePoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x141634 push {r4, r5, r6, r7, r8, lr} */
/* @0x141638 mov r7, r1 */
/* @0x14163c ldr r4, [sp, #0x18] */
/* @0x141640 mov r1, #0 */
/* @0x141644 mov r0, r4 */
/* @0x141648 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14164c mov r1, #1 */
/* @0x141650 mov r6, r0 */
/* @0x141654 mov r0, r4 */
/* @0x141658 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14165c mov r1, #2 */
/* @0x141660 mov r5, r0 */
/* @0x141664 mov r0, r4 */
/* @0x141668 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14166c mov r1, r6 */
/* @0x141670 mov r2, r5 */
/* @0x141674 mov r3, r0 */
/* @0x141678 mov r0, r7 */
/* @0x14167c pop {r4, r5, r6, r7, r8, lr} */
/* @0x141680 b 0x1415e8 <_Z23YYGML_action_move_pointP9CInstancefff> */

/* ── FUNC 0x141684 · YYGML_action_reverse_xdir(CInstance*) · size=12 · insn=3 */
/* @0x141684 ldr r1, [r0, #0xe0] */
/* @0x141688 eor r1, r1, #-2147483648 */
/* @0x14168c b 0x1930f4 <_ZN9CInstance9SetHspeedEf> */

/* ── FUNC 0x141690 · YYGML_action_reverse_ydir(CInstance*) · size=12 · insn=3 */
/* @0x141690 ldr r1, [r0, #0xe4] */
/* @0x141694 eor r1, r1, #-2147483648 */
/* @0x141698 b 0x193114 <_ZN9CInstance9SetVspeedEf> */

/* ── FUNC 0x14169c · YYGML_action_path(CInstance*, int, float, int, bool) · size=48 · insn=12 */
/* @0x14169c str lr, [sp, #-0x4]! */
/* @0x1416a0 sub sp, sp, #20 */
/* @0x1416a4 mov lr, #0 */
/* @0x1416a8 ldrb r12, [sp, #0x18] */
/* @0x1416ac str r3, [sp, #0x8] */
/* @0x1416b0 mov r3, #1065353216 */
/* @0x1416b4 eor r12, r12, #1 */
/* @0x1416b8 str lr, [sp] */
/* @0x1416bc str r12, [sp, #0x4] */
/* @0x1416c0 bl 0x193fe0 <_ZN9CInstance11Assign_PathEifffbi> */
/* @0x1416c4 add sp, sp, #20 */
/* @0x1416c8 ldr pc, [sp], #4 */

/* ── FUNC 0x1416cc · YYGML_action_linear_step(CInstance*, float, float, float, bool) · size=96 · insn=24 */
/* @0x1416cc ldr r12, [pc, #0x54] */
/* @0x1416d0 vmov s15, r2 */
/* @0x1416d4 push {r4, lr} */
/* @0x1416d8 ldr r12, [pc, r12] */
/* @0x1416dc sub sp, sp, #8 */
/* @0x1416e0 vmov s14, r1 */
/* @0x1416e4 ldrb r12, [r12] */
/* @0x1416e8 ldrb lr, [sp, #0x10] */
/* @0x1416ec cmp r12, #0 */
/* @0x1416f0 str lr, [sp, #0x4] */
/* @0x1416f4 vldrne s12, [r0, #180] */
/* @0x1416f8 vldrne s13, [r0, #184] */
/* @0x1416fc vaddne.f32 s12, s14, s12 */
/* @0x141700 mvnne r2, #2 */
/* @0x141704 mvneq r12, #2 */
/* @0x141708 strne r2, [sp] */
/* @0x14170c streq r12, [sp] */
/* @0x141710 vaddne.f32 s13, s15, s13 */
/* @0x141714 vmovne r1, s12 */
/* @0x141718 vmovne r2, s13 */
/* @0x14171c bl 0x19c8a8 <_Z18Motion_Linear_StepP9CInstancefffib> */
/* @0x141720 add sp, sp, #8 */
/* @0x141724 pop {r4, pc} */
/* @0x141728 eoreq r12, r10, r4, ror #8 */

/* ── FUNC 0x14172c · YYGML_action_create_object(CInstance*, int, float, float) · size=320 · insn=80 */
/* @0x14172c push {r4, r5, r6, r7, r8, lr} */
/* @0x141730 vpush {d8} */
/* @0x141734 mov r6, r1 */
/* @0x141738 ldr r4, [pc, #0x118] */
/* @0x14173c vmov s16, r3 */
/* @0x141740 ldr r1, [pc, #0x114] */
/* @0x141744 sub sp, sp, #264 */
/* @0x141748 add r4, pc, r4 */
/* @0x14174c mov r7, r0 */
/* @0x141750 mov r0, r6 */
/* @0x141754 vmov s17, r2 */
/* @0x141758 ldr r5, [r4, r1] */
/* @0x14175c ldr r3, [r5] */
/* @0x141760 str r3, [sp, #0x104] */
/* @0x141764 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x141768 subs r8, r0, #0 */
/* @0x14176c beq 0x141824 <_Z26YYGML_action_create_objectP9CInstanceiff+0xf8> */
/* @0x141770 ldr r3, [pc, #0xe8] */
/* @0x141774 ldr r3, [r4, r3] */
/* @0x141778 ldrb r3, [r3] */
/* @0x14177c cmp r3, #0 */
/* @0x141780 bne 0x1417f0 <_Z26YYGML_action_create_objectP9CInstanceiff+0xc4> */
/* @0x141784 ldr r0, [pc, #0xd8] */
/* @0x141788 mov r3, r6 */
/* @0x14178c vmov r1, s17 */
/* @0x141790 vmov r2, s16 */
/* @0x141794 ldr r0, [r4, r0] */
/* @0x141798 ldr r0, [r0] */
/* @0x14179c bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi> */
/* @0x1417a0 mov r4, r0 */
/* @0x1417a4 mov r0, r4 */
/* @0x1417a8 mov r1, r4 */
/* @0x1417ac mov r2, #14 */
/* @0x1417b0 mov r3, #0 */
/* @0x1417b4 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1417b8 mov r2, #0 */
/* @0x1417bc mov r3, r2 */
/* @0x1417c0 mov r0, r4 */
/* @0x1417c4 mov r1, r4 */
/* @0x1417c8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1417cc mov r3, #1 */
/* @0x1417d0 strb r3, [r4, #0x6c] */
/* @0x1417d4 ldr r2, [sp, #0x104] */
/* @0x1417d8 ldr r3, [r5] */
/* @0x1417dc cmp r2, r3 */
/* @0x1417e0 bne 0x141854 <_Z26YYGML_action_create_objectP9CInstanceiff+0x128> */
/* @0x1417e4 add sp, sp, #264 */
/* @0x1417e8 vpop {d8} */
/* @0x1417ec pop {r4, r5, r6, r7, r8, pc} */
/* @0x1417f0 vldr s14, [r7, #180] */
/* @0x1417f4 vldr s15, [r7, #184] */
/* @0x1417f8 vadd.f32 s14, s17, s14 */
/* @0x1417fc ldr r2, [pc, #0x60] */
/* @0x141800 mov r3, r6 */
/* @0x141804 ldr r2, [r4, r2] */
/* @0x141808 ldr r0, [r2] */
/* @0x14180c vadd.f32 s15, s16, s15 */
/* @0x141810 vmov r1, s14 */
/* @0x141814 vmov r2, s15 */
/* @0x141818 bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi> */
/* @0x14181c mov r4, r0 */
/* @0x141820 b 0x1417a4 <_Z26YYGML_action_create_objectP9CInstanceiff+0x78> */
/* @0x141824 add r4, sp, #264 */
/* @0x141828 ldr r2, [pc, #0x38] */
/* @0x14182c mov r3, r6 */
/* @0x141830 mov r1, #256 */
/* @0x141834 strb r8, [r4, #-0x104]! */
/* @0x141838 add r2, pc, r2 */
/* @0x14183c mov r0, r4 */
/* @0x141840 bl 0xb65c8 <snprintf@plt> */
/* @0x141844 mov r0, r4 */
/* @0x141848 mov r1, r8 */
/* @0x14184c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x141850 b 0x1417d4 <_Z26YYGML_action_create_objectP9CInstanceiff+0xa8> */
/* @0x141854 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x141858 eoreq r0, r11, r8, lsl #10 */
/* @0x14185c .word 0xffffbd00 */
/* @0x141860 .word 0xffffbeec */
/* @0x141864 .word 0xffffbcd8 */
/* @0x141868 ldrsheq pc, [pc], -r4 */

/* ── FUNC 0x14186c · F_ActionCreateObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x14186c push {r4, r5, r6, r7, r8, lr} */
/* @0x141870 mov r7, r1 */
/* @0x141874 ldr r4, [sp, #0x18] */
/* @0x141878 mov r1, #0 */
/* @0x14187c mov r0, r4 */
/* @0x141880 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x141884 mov r1, #1 */
/* @0x141888 mov r6, r0 */
/* @0x14188c mov r0, r4 */
/* @0x141890 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x141894 mov r1, #2 */
/* @0x141898 mov r5, r0 */
/* @0x14189c mov r0, r4 */
/* @0x1418a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1418a4 mov r1, r6 */
/* @0x1418a8 mov r2, r5 */
/* @0x1418ac mov r3, r0 */
/* @0x1418b0 mov r0, r7 */
/* @0x1418b4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1418b8 b 0x14172c <_Z26YYGML_action_create_objectP9CInstanceiff> */

/* ── FUNC 0x1418bc · YYGML_action_create_object_motion(CInstance*, int, float, float, float, float) · size=344 · insn=86 */
/* @0x1418bc push {r4, r5, r6, r7, r8, lr} */
/* @0x1418c0 vpush {d8} */
/* @0x1418c4 mov r6, r1 */
/* @0x1418c8 ldr r4, [pc, #0x130] */
/* @0x1418cc vmov s16, r3 */
/* @0x1418d0 ldr r1, [pc, #0x12c] */
/* @0x1418d4 sub sp, sp, #264 */
/* @0x1418d8 add r4, pc, r4 */
/* @0x1418dc mov r7, r0 */
/* @0x1418e0 mov r0, r6 */
/* @0x1418e4 vmov s17, r2 */
/* @0x1418e8 ldr r5, [r4, r1] */
/* @0x1418ec ldr r3, [r5] */
/* @0x1418f0 str r3, [sp, #0x104] */
/* @0x1418f4 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1418f8 subs r8, r0, #0 */
/* @0x1418fc beq 0x1419cc <_Z33YYGML_action_create_object_motionP9CInstanceiffff+0x110> */
/* @0x141900 ldr r3, [pc, #0x100] */
/* @0x141904 ldr r3, [r4, r3] */
/* @0x141908 ldrb r3, [r3] */
/* @0x14190c cmp r3, #0 */
/* @0x141910 bne 0x141998 <_Z33YYGML_action_create_object_motionP9CInstanceiffff+0xdc> */
/* @0x141914 ldr r0, [pc, #0xf0] */
/* @0x141918 mov r3, r6 */
/* @0x14191c vmov r1, s17 */
/* @0x141920 vmov r2, s16 */
/* @0x141924 ldr r0, [r4, r0] */
/* @0x141928 ldr r0, [r0] */
/* @0x14192c bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi> */
/* @0x141930 mov r4, r0 */
/* @0x141934 mov r0, r4 */
/* @0x141938 ldr r1, [sp, #0x128] */
/* @0x14193c bl 0x1930d4 <_ZN9CInstance8SetSpeedEf> */
/* @0x141940 mov r0, r4 */
/* @0x141944 ldr r1, [sp, #0x12c] */
/* @0x141948 bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x14194c mov r0, r4 */
/* @0x141950 mov r1, r4 */
/* @0x141954 mov r2, #14 */
/* @0x141958 mov r3, #0 */
/* @0x14195c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x141960 mov r2, #0 */
/* @0x141964 mov r3, r2 */
/* @0x141968 mov r0, r4 */
/* @0x14196c mov r1, r4 */
/* @0x141970 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x141974 mov r3, #1 */
/* @0x141978 strb r3, [r4, #0x6c] */
/* @0x14197c ldr r2, [sp, #0x104] */
/* @0x141980 ldr r3, [r5] */
/* @0x141984 cmp r2, r3 */
/* @0x141988 bne 0x1419fc <_Z33YYGML_action_create_object_motionP9CInstanceiffff+0x140> */
/* @0x14198c add sp, sp, #264 */
/* @0x141990 vpop {d8} */
/* @0x141994 pop {r4, r5, r6, r7, r8, pc} */
/* @0x141998 vldr s14, [r7, #180] */
/* @0x14199c vldr s15, [r7, #184] */
/* @0x1419a0 vadd.f32 s14, s17, s14 */
/* @0x1419a4 ldr r2, [pc, #0x60] */
/* @0x1419a8 mov r3, r6 */
/* @0x1419ac ldr r2, [r4, r2] */
/* @0x1419b0 ldr r0, [r2] */
/* @0x1419b4 vadd.f32 s15, s16, s15 */
/* @0x1419b8 vmov r1, s14 */
/* @0x1419bc vmov r2, s15 */
/* @0x1419c0 bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi> */
/* @0x1419c4 mov r4, r0 */
/* @0x1419c8 b 0x141934 <_Z33YYGML_action_create_object_motionP9CInstanceiffff+0x78> */
/* @0x1419cc add r4, sp, #264 */
/* @0x1419d0 ldr r2, [pc, #0x38] */
/* @0x1419d4 mov r3, r6 */
/* @0x1419d8 mov r1, #256 */
/* @0x1419dc strb r8, [r4, #-0x104]! */
/* @0x1419e0 add r2, pc, r2 */
/* @0x1419e4 mov r0, r4 */
/* @0x1419e8 bl 0xb65c8 <snprintf@plt> */
/* @0x1419ec mov r0, r4 */
/* @0x1419f0 mov r1, r8 */
/* @0x1419f4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1419f8 b 0x14197c <_Z33YYGML_action_create_object_motionP9CInstanceiffff+0xc0> */
/* @0x1419fc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x141a00 eoreq r0, r11, r8, ror r3 */
/* @0x141a04 .word 0xffffbd00 */
/* @0x141a08 .word 0xffffbeec */
/* @0x141a0c .word 0xffffbcd8 */
/* @0x141a10 andseq pc, pc, r12, asr #32 */

/* ── FUNC 0x141a14 · F_ActionCreateObjectMotion(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x141a14 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x141a18 sub sp, sp, #12 */
/* @0x141a1c mov r5, r1 */
/* @0x141a20 mov r1, #0 */
/* @0x141a24 ldr r4, [sp, #0x28] */
/* @0x141a28 mov r0, r4 */
/* @0x141a2c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x141a30 mov r1, #1 */
/* @0x141a34 mov r8, r0 */
/* @0x141a38 mov r0, r4 */
/* @0x141a3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x141a40 mov r1, #2 */
/* @0x141a44 mov r7, r0 */
/* @0x141a48 mov r0, r4 */
/* @0x141a4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x141a50 mov r1, #3 */
/* @0x141a54 mov r6, r0 */
/* @0x141a58 mov r0, r4 */
/* @0x141a5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x141a60 mov r1, #4 */
/* @0x141a64 mov r9, r0 */
/* @0x141a68 mov r0, r4 */
/* @0x141a6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x141a70 str r9, [sp] */
/* @0x141a74 mov r1, r8 */
/* @0x141a78 mov r2, r7 */
/* @0x141a7c mov r3, r6 */
/* @0x141a80 str r0, [sp, #0x4] */
/* @0x141a84 mov r0, r5 */
/* @0x141a88 bl 0x1418bc <_Z33YYGML_action_create_object_motionP9CInstanceiffff> */
/* @0x141a8c add sp, sp, #12 */
/* @0x141a90 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x141a94 · YYGML_action_change_object(CInstance*, int, bool) · size=4 · insn=1 */
/* @0x141a94 b 0x1c9bb4 <_Z14Command_ChangeP9CInstanceib> */

/* ── FUNC 0x141a98 · YYGML_action_kill_object(CInstance*) · size=96 · insn=24 */
/* @0x141a98 push {r4, r5, r6, lr} */
/* @0x141a9c mov r4, r0 */
/* @0x141aa0 ldrb r5, [r0, #0x6a] */
/* @0x141aa4 cmp r5, #0 */
/* @0x141aa8 popne {r4, r5, r6, pc} */
/* @0x141aac mov r6, #1 */
/* @0x141ab0 mov r1, r0 */
/* @0x141ab4 strb r6, [r0, #0x6a] */
/* @0x141ab8 mov r2, r6 */
/* @0x141abc mov r3, r5 */
/* @0x141ac0 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x141ac4 mov r3, r5 */
/* @0x141ac8 mov r2, #12 */
/* @0x141acc mov r0, r4 */
/* @0x141ad0 mov r1, r4 */
/* @0x141ad4 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x141ad8 ldr r3, [pc, #0x14] */
/* @0x141adc strb r6, [r4, #0x68] */
/* @0x141ae0 ldr r3, [pc, r3] */
/* @0x141ae4 ldr r2, [r3] */
/* @0x141ae8 add r2, r2, r6 */
/* @0x141aec str r2, [r3] */
/* @0x141af0 pop {r4, r5, r6, pc} */
/* @0x141af4 .word 0x002ac5d4 */

/* ── FUNC 0x141af8 · F_ActionKillObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=8 · insn=2 */
/* @0x141af8 mov r0, r1 */
/* @0x141afc b 0x141a98 <_Z24YYGML_action_kill_objectP9CInstance> */

/* ── FUNC 0x141b00 · YYGML_action_sound(int, bool) · size=132 · insn=33 */
/* @0x141b00 ldr r3, [pc, #0x74] */
/* @0x141b04 push {r4, r5, lr} */
/* @0x141b08 ldr r3, [pc, r3] */
/* @0x141b0c sub sp, sp, #12 */
/* @0x141b10 mov r4, r1 */
/* @0x141b14 ldrb r3, [r3] */
/* @0x141b18 cmp r3, #0 */
/* @0x141b1c bne 0x141b4c <_Z18YYGML_action_soundib+0x4c> */
/* @0x141b20 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x141b24 subs r1, r0, #0 */
/* @0x141b28 beq 0x141b68 <_Z18YYGML_action_soundib+0x68> */
/* @0x141b2c ldr r5, [r1, #0xc] */
/* @0x141b30 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x141b34 mov r2, r4 */
/* @0x141b38 mov r1, r0 */
/* @0x141b3c mov r0, r5 */
/* @0x141b40 add sp, sp, #12 */
/* @0x141b44 pop {r4, r5, lr} */
/* @0x141b48 b 0x21eb7c <_Z8SND_PlayPKcib> */
/* @0x141b4c str r1, [sp] */
/* @0x141b50 mov r2, #0 */
/* @0x141b54 mov r3, #0 */
/* @0x141b58 movt r3, #0x3ff0 */
/* @0x141b5c bl 0x21b5d8 <_Z15Audio_PlaySoundidi> */
/* @0x141b60 add sp, sp, #12 */
/* @0x141b64 pop {r4, r5, pc} */
/* @0x141b68 ldr r0, [pc, #0x10] */
/* @0x141b6c add r0, pc, r0 */
/* @0x141b70 add sp, sp, #12 */
/* @0x141b74 pop {r4, r5, lr} */
/* @0x141b78 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x141b7c eoreq sp, r10, r8, lsr #4 */
/* @0x141b80 ldrsheq lr, [pc], -r0 */

/* ── FUNC 0x141b84 · F_ActionSound(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x141b84 push {r3, r4, r5, lr} */
/* @0x141b88 mov r1, #0 */
/* @0x141b8c ldr r4, [sp, #0x10] */
/* @0x141b90 mov r0, r4 */
/* @0x141b94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x141b98 mov r1, #1 */
/* @0x141b9c mov r5, r0 */
/* @0x141ba0 mov r0, r4 */
/* @0x141ba4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x141ba8 mov r1, r0 */
/* @0x141bac mov r0, r5 */
/* @0x141bb0 pop {r3, r4, r5, lr} */
/* @0x141bb4 b 0x141b00 <_Z18YYGML_action_soundib> */

/* ── FUNC 0x141bb8 · YYGML_action_end_sound(int) · size=92 · insn=23 */
/* @0x141bb8 ldr r3, [pc, #0x4c] */
/* @0x141bbc push {r4, lr} */
/* @0x141bc0 ldr r3, [pc, r3] */
/* @0x141bc4 ldrb r3, [r3] */
/* @0x141bc8 cmp r3, #0 */
/* @0x141bcc bne 0x141bf4 <_Z22YYGML_action_end_soundi+0x3c> */
/* @0x141bd0 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x141bd4 subs r1, r0, #0 */
/* @0x141bd8 beq 0x141bfc <_Z22YYGML_action_end_soundi+0x44> */
/* @0x141bdc ldr r4, [r1, #0xc] */
/* @0x141be0 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x141be4 mov r1, r0 */
/* @0x141be8 mov r0, r4 */
/* @0x141bec pop {r4, lr} */
/* @0x141bf0 b 0x21ecf4 <_Z8SND_StopPKci> */
/* @0x141bf4 pop {r4, lr} */
/* @0x141bf8 b 0x21a210 <_Z15Audio_StopSoundi> */
/* @0x141bfc ldr r0, [pc, #0xc] */
/* @0x141c00 pop {r4, lr} */
/* @0x141c04 add r0, pc, r0 */
/* @0x141c08 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x141c0c eoreq sp, r10, r0, ror r1 */
/* @0x141c10 andseq lr, pc, r12, ror lr */

/* ── FUNC 0x141c14 · F_ActionEndSound(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x141c14 push {r3, lr} */
/* @0x141c18 mov r1, #0 */
/* @0x141c1c ldr r0, [sp, #0x8] */
/* @0x141c20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x141c24 pop {r3, lr} */
/* @0x141c28 b 0x141bb8 <_Z22YYGML_action_end_soundi> */

/* ── FUNC 0x141c2c · YYGML_action_next_room() · size=8 · insn=2 */
/* @0x141c2c mov r0, #0 */
/* @0x141c30 b 0x1c9ed0 <_Z16Command_NextRoomi> */

/* ── FUNC 0x141c34 · YYGML_action_set_alarm(CInstance*, int, int) · size=108 · insn=27 */
/* @0x141c34 ldr r3, [pc, #0x60] */
/* @0x141c38 push {r4, r5, r6, lr} */
/* @0x141c3c ldr r3, [pc, r3] */
/* @0x141c40 mov r6, r1 */
/* @0x141c44 mov r4, r2 */
/* @0x141c48 ldrb r3, [r3] */
/* @0x141c4c mov r5, r0 */
/* @0x141c50 cmp r3, #0 */
/* @0x141c54 bne 0x141c6c <_Z22YYGML_action_set_alarmP9CInstanceii+0x38> */
/* @0x141c58 mov r0, r5 */
/* @0x141c5c mov r1, r4 */
/* @0x141c60 mov r2, r6 */
/* @0x141c64 pop {r4, r5, r6, lr} */
/* @0x141c68 b 0x193148 <_ZN9CInstance8SetTimerEii> */
/* @0x141c6c mov r1, r2 */
/* @0x141c70 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0x141c74 cmp r0, #0 */
/* @0x141c78 blt 0x141c58 <_Z22YYGML_action_set_alarmP9CInstanceii+0x24> */
/* @0x141c7c mov r1, r4 */
/* @0x141c80 mov r0, r5 */
/* @0x141c84 bl 0x193134 <_ZN9CInstance8GetTimerEi> */
/* @0x141c88 mov r1, r4 */
/* @0x141c8c add r2, r0, r6 */
/* @0x141c90 mov r0, r5 */
/* @0x141c94 pop {r4, r5, r6, lr} */
/* @0x141c98 b 0x193148 <_ZN9CInstance8SetTimerEii> */
/* @0x141c9c eoreq r11, r10, r0, lsl #30 */

/* ── FUNC 0x141ca0 · YYGML_action_end_game() · size=4 · insn=1 */
/* @0x141ca0 b 0x1c9f50 <_Z15Command_EndGamev> */

/* ── FUNC 0x141ca4 · YYGML_action_restart_game() · size=4 · insn=1 */
/* @0x141ca4 b 0x1c9f54 <_Z19Command_RestartGamev> */

/* ── FUNC 0x141ca8 · YYGML_action_if_number(int, double, int) · size=116 · insn=29 */
/* @0x141ca8 push {r4, lr} */
/* @0x141cac vpush {d8} */
/* @0x141cb0 vmov d8, r2, r3 */
/* @0x141cb4 ldr r4, [sp, #0x10] */
/* @0x141cb8 bl 0x1c8ed0 <_Z22Command_InstanceNumberi> */
/* @0x141cbc cmp r4, #1 */
/* @0x141cc0 vmov s13, r0 */
/* @0x141cc4 vcvt.f64.s32 d7, s13 */
/* @0x141cc8 beq 0x141cec <_Z22YYGML_action_if_numberidi+0x44> */
/* @0x141ccc cmp r4, #2 */
/* @0x141cd0 beq 0x141d04 <_Z22YYGML_action_if_numberidi+0x5c> */
/* @0x141cd4 vcmp.f64 d7, d8 */
/* @0x141cd8 vpop {d8} */
/* @0x141cdc vmrs APSR_nzcv, fpscr */
/* @0x141ce0 movne r0, #0 */
/* @0x141ce4 moveq r0, #1 */
/* @0x141ce8 pop {r4, pc} */
/* @0x141cec vcmpe.f64 d7, d8 */
/* @0x141cf0 vpop {d8} */
/* @0x141cf4 vmrs APSR_nzcv, fpscr */
/* @0x141cf8 movpl r0, #0 */
/* @0x141cfc movmi r0, #1 */
/* @0x141d00 pop {r4, pc} */
/* @0x141d04 vcmpe.f64 d7, d8 */
/* @0x141d08 vpop {d8} */
/* @0x141d0c vmrs APSR_nzcv, fpscr */
/* @0x141d10 movle r0, #0 */
/* @0x141d14 movgt r0, #1 */
/* @0x141d18 pop {r4, pc} */

/* ── FUNC 0x141d1c · YYGML_action_if_variable(RValue const&, RValue const&, int) · size=116 · insn=29 */
/* @0x141d1c ldr r3, [pc, #0x68] */
/* @0x141d20 push {r4, lr} */
/* @0x141d24 ldr r3, [pc, r3] */
/* @0x141d28 mov r4, r2 */
/* @0x141d2c ldrd r2, r3, [r3] */
/* @0x141d30 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d> */
/* @0x141d34 cmp r4, #1 */
/* @0x141d38 beq 0x141d64 <_Z24YYGML_action_if_variableRK6RValueS1_i+0x48> */
/* @0x141d3c cmp r4, #2 */
/* @0x141d40 beq 0x141d6c <_Z24YYGML_action_if_variableRK6RValueS1_i+0x50> */
/* @0x141d44 cmp r4, #3 */
/* @0x141d48 beq 0x141d7c <_Z24YYGML_action_if_variableRK6RValueS1_i+0x60> */
/* @0x141d4c cmp r4, #4 */
/* @0x141d50 beq 0x141d60 <_Z24YYGML_action_if_variableRK6RValueS1_i+0x44> */
/* @0x141d54 rsbs r0, r0, #1 */
/* @0x141d58 movlo r0, #0 */
/* @0x141d5c pop {r4, pc} */
/* @0x141d60 mvn r0, r0 */
/* @0x141d64 lsr r0, r0, #31 */
/* @0x141d68 pop {r4, pc} */
/* @0x141d6c cmp r0, #0 */
/* @0x141d70 movle r0, #0 */
/* @0x141d74 movgt r0, #1 */
/* @0x141d78 pop {r4, pc} */
/* @0x141d7c cmp r0, #0 */
/* @0x141d80 movgt r0, #0 */
/* @0x141d84 movle r0, #1 */
/* @0x141d88 pop {r4, pc} */
/* @0x141d8c .word 0x002abff4 */

/* ── FUNC 0x141d90 · F_ActionIfVariable(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x141d90 push {r3, r4, r5, lr} */
/* @0x141d94 mov r1, #2 */
/* @0x141d98 ldr r5, [sp, #0x10] */
/* @0x141d9c mov r3, #0 */
/* @0x141da0 mov r4, r0 */
/* @0x141da4 str r3, [r0, #0xc] */
/* @0x141da8 mov r0, r5 */
/* @0x141dac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x141db0 add r1, r5, #16 */
/* @0x141db4 mov r2, r0 */
/* @0x141db8 mov r0, r5 */
/* @0x141dbc bl 0x141d1c <_Z24YYGML_action_if_variableRK6RValueS1_i> */
/* @0x141dc0 vmov s15, r0 */
/* @0x141dc4 vcvt.f64.u32 d7, s15 */
/* @0x141dc8 vmov r0, r1, d7 */
/* @0x141dcc vmov r2, s14 */
/* @0x141dd0 mov r3, r1 */
/* @0x141dd4 stm r4, {r2, r3} */
/* @0x141dd8 pop {r3, r4, r5, pc} */

/* ── FUNC 0x141ddc · YYGML_action_fullscreen(int) · size=64 · insn=16 */
/* @0x141ddc cmp r0, #1 */
/* @0x141de0 push {r3, lr} */
/* @0x141de4 beq 0x141e10 <_Z23YYGML_action_fullscreeni+0x34> */
/* @0x141de8 cmp r0, #2 */
/* @0x141dec beq 0x141e04 <_Z23YYGML_action_fullscreeni+0x28> */
/* @0x141df0 bl 0x17af24 <_Z24GR_Window_Get_FullScreenv> */
/* @0x141df4 pop {r3, lr} */
/* @0x141df8 eor r0, r0, #1 */
/* @0x141dfc uxtb r0, r0 */
/* @0x141e00 b 0x17af10 <_Z24GR_Window_Set_FullScreenb> */
/* @0x141e04 mov r0, #1 */
/* @0x141e08 pop {r3, lr} */
/* @0x141e0c b 0x17af10 <_Z24GR_Window_Set_FullScreenb> */
/* @0x141e10 mov r0, #0 */
/* @0x141e14 pop {r3, lr} */
/* @0x141e18 b 0x17af10 <_Z24GR_Window_Set_FullScreenb> */

/* ── FUNC 0x141e1c · F_ActionFullScreen(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x141e1c push {r3, lr} */
/* @0x141e20 mov r1, #0 */
/* @0x141e24 ldr r0, [sp, #0x8] */
/* @0x141e28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x141e2c pop {r3, lr} */
/* @0x141e30 b 0x141ddc <_Z23YYGML_action_fullscreeni> */

/* ── FUNC 0x141e34 · YYGML_action_set_relative(bool) · size=20 · insn=5 */
/* @0x141e34 ldr r3, [pc, #0x8] */
/* @0x141e38 ldr r3, [pc, r3] */
/* @0x141e3c strb r0, [r3] */
/* @0x141e40 bx lr */
/* @0x141e44 eoreq r11, r10, r4, lsl #26 */

/* ── FUNC 0x141e48 · F_ActionSetRelative(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x141e48 push {r3, lr} */
/* @0x141e4c mov r1, #0 */
/* @0x141e50 ldr r0, [sp, #0x8] */
/* @0x141e54 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x141e58 pop {r3, lr} */
/* @0x141e5c b 0x141e34 <_Z25YYGML_action_set_relativeb> */

/* ── FUNC 0x141e60 · InitActionFunctions() · size=4924 · insn=1231 */
/* @0x141e60 push {r4, r5, r6, lr} */
/* @0x141e64 mov r5, #64 */
/* @0x141e68 ldr r4, [pc, #0xf04] */
/* @0x141e6c mvn r12, #0 */
/* @0x141e70 ldr r0, [pc, #0xf00] */
/* @0x141e74 mov r2, r5 */
/* @0x141e78 add r4, pc, r4 */
/* @0x141e7c ldr r3, [pc, #0xef8] */
/* @0x141e80 mov r1, #0 */
/* @0x141e84 ldr r0, [r4, r0] */
/* @0x141e88 str r12, [r0] */
/* @0x141e8c ldr r0, [r4, r3] */
/* @0x141e90 bl 0xb65b0 <memset@plt> */
/* @0x141e94 ldr r3, [pc, #0xee4] */
/* @0x141e98 mov r2, r5 */
/* @0x141e9c mov r1, #0 */
/* @0x141ea0 ldr r0, [r4, r3] */
/* @0x141ea4 bl 0xb65b0 <memset@plt> */
/* @0x141ea8 ldr r1, [pc, #0xed4] */
/* @0x141eac ldr r0, [pc, #0xed4] */
/* @0x141eb0 mov r2, #3 */
/* @0x141eb4 mov r3, #0 */
/* @0x141eb8 ldr r5, [r4, r1] */
/* @0x141ebc add r0, pc, r0 */
/* @0x141ec0 mov r1, r5 */
/* @0x141ec4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141ec8 ldr r1, [pc, #0xebc] */
/* @0x141ecc ldr r0, [pc, #0xebc] */
/* @0x141ed0 mov r2, #2 */
/* @0x141ed4 mov r3, #0 */
/* @0x141ed8 ldr r1, [r4, r1] */
/* @0x141edc add r0, pc, r0 */
/* @0x141ee0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141ee4 ldr r0, [pc, #0xea8] */
/* @0x141ee8 mov r1, r5 */
/* @0x141eec mov r2, #1 */
/* @0x141ef0 add r0, pc, r0 */
/* @0x141ef4 mov r3, #0 */
/* @0x141ef8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141efc ldr r0, [pc, #0xe94] */
/* @0x141f00 mov r1, r5 */
/* @0x141f04 mov r2, #6 */
/* @0x141f08 add r0, pc, r0 */
/* @0x141f0c mov r3, #0 */
/* @0x141f10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141f14 ldr r0, [pc, #0xe80] */
/* @0x141f18 mov r1, r5 */
/* @0x141f1c mov r2, #1 */
/* @0x141f20 add r0, pc, r0 */
/* @0x141f24 mov r3, #0 */
/* @0x141f28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141f2c ldr r0, [pc, #0xe6c] */
/* @0x141f30 mov r1, r5 */
/* @0x141f34 mov r2, #1 */
/* @0x141f38 add r0, pc, r0 */
/* @0x141f3c mov r3, #0 */
/* @0x141f40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141f44 ldr r0, [pc, #0xe58] */
/* @0x141f48 mov r1, r5 */
/* @0x141f4c mov r2, #1 */
/* @0x141f50 add r0, pc, r0 */
/* @0x141f54 mov r3, #0 */
/* @0x141f58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141f5c ldr r0, [pc, #0xe44] */
/* @0x141f60 mov r1, r5 */
/* @0x141f64 mov r2, #1 */
/* @0x141f68 add r0, pc, r0 */
/* @0x141f6c mov r3, #0 */
/* @0x141f70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141f74 ldr r0, [pc, #0xe30] */
/* @0x141f78 mov r2, #0 */
/* @0x141f7c mov r1, r5 */
/* @0x141f80 mov r3, r2 */
/* @0x141f84 add r0, pc, r0 */
/* @0x141f88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141f8c ldr r1, [pc, #0xe1c] */
/* @0x141f90 ldr r0, [pc, #0xe1c] */
/* @0x141f94 mov r2, #1 */
/* @0x141f98 mov r3, #0 */
/* @0x141f9c ldr r1, [r4, r1] */
/* @0x141fa0 add r0, pc, r0 */
/* @0x141fa4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141fa8 ldr r1, [pc, #0xe08] */
/* @0x141fac ldr r0, [pc, #0xe08] */
/* @0x141fb0 mov r2, #2 */
/* @0x141fb4 mov r3, #0 */
/* @0x141fb8 ldr r1, [r4, r1] */
/* @0x141fbc add r0, pc, r0 */
/* @0x141fc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141fc4 ldr r1, [pc, #0xdf4] */
/* @0x141fc8 ldr r0, [pc, #0xdf4] */
/* @0x141fcc mov r2, #2 */
/* @0x141fd0 mov r3, #0 */
/* @0x141fd4 ldr r1, [r4, r1] */
/* @0x141fd8 add r0, pc, r0 */
/* @0x141fdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141fe0 ldr r1, [pc, #0xde0] */
/* @0x141fe4 ldr r0, [pc, #0xde0] */
/* @0x141fe8 mov r2, #1 */
/* @0x141fec mov r3, #0 */
/* @0x141ff0 ldr r1, [r4, r1] */
/* @0x141ff4 add r0, pc, r0 */
/* @0x141ff8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x141ffc ldr r1, [pc, #0xdcc] */
/* @0x142000 ldr r0, [pc, #0xdcc] */
/* @0x142004 mov r2, #1 */
/* @0x142008 mov r3, #0 */
/* @0x14200c ldr r1, [r4, r1] */
/* @0x142010 add r0, pc, r0 */
/* @0x142014 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142018 ldr r1, [pc, #0xdb8] */
/* @0x14201c ldr r0, [pc, #0xdb8] */
/* @0x142020 mov r2, #2 */
/* @0x142024 mov r3, #0 */
/* @0x142028 ldr r1, [r4, r1] */
/* @0x14202c add r0, pc, r0 */
/* @0x142030 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142034 ldr r1, [pc, #0xda4] */
/* @0x142038 ldr r0, [pc, #0xda4] */
/* @0x14203c mov r2, #1 */
/* @0x142040 mov r3, #0 */
/* @0x142044 ldr r1, [r4, r1] */
/* @0x142048 add r0, pc, r0 */
/* @0x14204c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142050 ldr r1, [pc, #0xd90] */
/* @0x142054 ldr r0, [pc, #0xd90] */
/* @0x142058 mov r2, #3 */
/* @0x14205c mov r3, #0 */
/* @0x142060 ldr r1, [r4, r1] */
/* @0x142064 add r0, pc, r0 */
/* @0x142068 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14206c ldr r1, [pc, #0xd7c] */
/* @0x142070 ldr r0, [pc, #0xd7c] */
/* @0x142074 mov r2, #2 */
/* @0x142078 mov r3, #0 */
/* @0x14207c ldr r1, [r4, r1] */
/* @0x142080 add r0, pc, r0 */
/* @0x142084 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142088 ldr r1, [pc, #0xd68] */
/* @0x14208c ldr r0, [pc, #0xd68] */
/* @0x142090 mov r2, #0 */
/* @0x142094 mov r3, r2 */
/* @0x142098 ldr r1, [r4, r1] */
/* @0x14209c add r0, pc, r0 */
/* @0x1420a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1420a4 ldr r1, [pc, #0xd54] */
/* @0x1420a8 ldr r0, [pc, #0xd54] */
/* @0x1420ac mov r2, #2 */
/* @0x1420b0 mov r3, #0 */
/* @0x1420b4 ldr r1, [r4, r1] */
/* @0x1420b8 add r0, pc, r0 */
/* @0x1420bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1420c0 ldr r1, [pc, #0xd40] */
/* @0x1420c4 ldr r0, [pc, #0xd40] */
/* @0x1420c8 mov r2, #2 */
/* @0x1420cc mov r3, #0 */
/* @0x1420d0 ldr r1, [r4, r1] */
/* @0x1420d4 add r0, pc, r0 */
/* @0x1420d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1420dc ldr r1, [pc, #0xd2c] */
/* @0x1420e0 ldr r0, [pc, #0xd2c] */
/* @0x1420e4 mov r2, #1 */
/* @0x1420e8 mov r3, #0 */
/* @0x1420ec ldr r1, [r4, r1] */
/* @0x1420f0 add r0, pc, r0 */
/* @0x1420f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1420f8 ldr r1, [pc, #0xd18] */
/* @0x1420fc ldr r0, [pc, #0xd18] */
/* @0x142100 mov r2, #0 */
/* @0x142104 mov r3, r2 */
/* @0x142108 ldr r1, [r4, r1] */
/* @0x14210c add r0, pc, r0 */
/* @0x142110 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142114 ldr r1, [pc, #0xd04] */
/* @0x142118 ldr r0, [pc, #0xd04] */
/* @0x14211c mov r2, #0 */
/* @0x142120 mov r3, r2 */
/* @0x142124 ldr r1, [r4, r1] */
/* @0x142128 add r0, pc, r0 */
/* @0x14212c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142130 ldr r1, [pc, #0xcf0] */
/* @0x142134 ldr r0, [pc, #0xcf0] */
/* @0x142138 mov r2, #3 */
/* @0x14213c mov r3, #0 */
/* @0x142140 ldr r1, [r4, r1] */
/* @0x142144 add r0, pc, r0 */
/* @0x142148 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14214c ldr r1, [pc, #0xcdc] */
/* @0x142150 ldr r0, [pc, #0xcdc] */
/* @0x142154 mov r2, #2 */
/* @0x142158 mov r3, #0 */
/* @0x14215c ldr r1, [r4, r1] */
/* @0x142160 add r0, pc, r0 */
/* @0x142164 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142168 ldr r1, [pc, #0xcc8] */
/* @0x14216c ldr r0, [pc, #0xcc8] */
/* @0x142170 mov r2, #4 */
/* @0x142174 mov r3, #0 */
/* @0x142178 ldr r1, [r4, r1] */
/* @0x14217c add r0, pc, r0 */
/* @0x142180 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142184 ldr r1, [pc, #0xcb4] */
/* @0x142188 ldr r0, [pc, #0xcb4] */
/* @0x14218c mov r2, #0 */
/* @0x142190 mov r3, r2 */
/* @0x142194 ldr r1, [r4, r1] */
/* @0x142198 add r0, pc, r0 */
/* @0x14219c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1421a0 ldr r1, [pc, #0xca0] */
/* @0x1421a4 ldr r0, [pc, #0xca0] */
/* @0x1421a8 mov r2, #1 */
/* @0x1421ac mov r3, #0 */
/* @0x1421b0 ldr r1, [r4, r1] */
/* @0x1421b4 add r0, pc, r0 */
/* @0x1421b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1421bc ldr r1, [pc, #0xc8c] */
/* @0x1421c0 ldr r0, [pc, #0xc8c] */
/* @0x1421c4 mov r2, #1 */
/* @0x1421c8 mov r3, #0 */
/* @0x1421cc ldr r1, [r4, r1] */
/* @0x1421d0 add r0, pc, r0 */
/* @0x1421d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1421d8 ldr r1, [pc, #0xc78] */
/* @0x1421dc ldr r0, [pc, #0xc78] */
/* @0x1421e0 mov r2, #4 */
/* @0x1421e4 mov r3, #0 */
/* @0x1421e8 ldr r1, [r4, r1] */
/* @0x1421ec add r0, pc, r0 */
/* @0x1421f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1421f4 ldr r1, [pc, #0xc64] */
/* @0x1421f8 ldr r0, [pc, #0xc64] */
/* @0x1421fc mov r2, #4 */
/* @0x142200 mov r3, #0 */
/* @0x142204 ldr r1, [r4, r1] */
/* @0x142208 add r0, pc, r0 */
/* @0x14220c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142210 ldr r1, [pc, #0xc50] */
/* @0x142214 ldr r0, [pc, #0xc50] */
/* @0x142218 mov r2, #0 */
/* @0x14221c mov r3, r2 */
/* @0x142220 ldr r1, [r4, r1] */
/* @0x142224 add r0, pc, r0 */
/* @0x142228 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14222c ldr r1, [pc, #0xc3c] */
/* @0x142230 ldr r0, [pc, #0xc3c] */
/* @0x142234 mov r2, #3 */
/* @0x142238 mov r3, #0 */
/* @0x14223c ldr r1, [r4, r1] */
/* @0x142240 add r0, pc, r0 */
/* @0x142244 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142248 ldr r1, [pc, #0xc28] */
/* @0x14224c ldr r0, [pc, #0xc28] */
/* @0x142250 mov r2, #5 */
/* @0x142254 mov r3, #0 */
/* @0x142258 ldr r1, [r4, r1] */
/* @0x14225c add r0, pc, r0 */
/* @0x142260 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142264 ldr r1, [pc, #0xc14] */
/* @0x142268 ldr r0, [pc, #0xc14] */
/* @0x14226c mov r2, #6 */
/* @0x142270 mov r3, #0 */
/* @0x142274 ldr r1, [r4, r1] */
/* @0x142278 add r0, pc, r0 */
/* @0x14227c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142280 ldr r1, [pc, #0xc00] */
/* @0x142284 ldr r0, [pc, #0xc00] */
/* @0x142288 mov r2, #2 */
/* @0x14228c mov r3, #0 */
/* @0x142290 ldr r1, [r4, r1] */
/* @0x142294 add r0, pc, r0 */
/* @0x142298 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14229c ldr r1, [pc, #0xbec] */
/* @0x1422a0 ldr r0, [pc, #0xbec] */
/* @0x1422a4 mov r2, #2 */
/* @0x1422a8 mov r3, #0 */
/* @0x1422ac ldr r1, [r4, r1] */
/* @0x1422b0 add r0, pc, r0 */
/* @0x1422b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1422b8 ldr r1, [pc, #0xbd8] */
/* @0x1422bc ldr r0, [pc, #0xbd8] */
/* @0x1422c0 mov r2, #3 */
/* @0x1422c4 mov r3, #0 */
/* @0x1422c8 ldr r1, [r4, r1] */
/* @0x1422cc add r0, pc, r0 */
/* @0x1422d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1422d4 ldr r1, [pc, #0xbc4] */
/* @0x1422d8 ldr r0, [pc, #0xbc4] */
/* @0x1422dc mov r2, #4 */
/* @0x1422e0 mov r3, #1 */
/* @0x1422e4 ldr r1, [r4, r1] */
/* @0x1422e8 add r0, pc, r0 */
/* @0x1422ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1422f0 ldr r1, [pc, #0xbb0] */
/* @0x1422f4 ldr r0, [pc, #0xbb0] */
/* @0x1422f8 mov r2, #2 */
/* @0x1422fc mov r3, #1 */
/* @0x142300 ldr r5, [r4, r1] */
/* @0x142304 add r0, pc, r0 */
/* @0x142308 mov r1, r5 */
/* @0x14230c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142310 ldr r0, [pc, #0xb98] */
/* @0x142314 mov r1, r5 */
/* @0x142318 mov r2, #2 */
/* @0x14231c add r0, pc, r0 */
/* @0x142320 mov r3, #1 */
/* @0x142324 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142328 ldr r1, [pc, #0xb84] */
/* @0x14232c ldr r0, [pc, #0xb84] */
/* @0x142330 mov r2, #2 */
/* @0x142334 mov r3, #0 */
/* @0x142338 ldr r1, [r4, r1] */
/* @0x14233c add r0, pc, r0 */
/* @0x142340 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142344 ldr r1, [pc, #0xb70] */
/* @0x142348 ldr r0, [pc, #0xb70] */
/* @0x14234c mov r2, #1 */
/* @0x142350 mov r3, #0 */
/* @0x142354 ldr r1, [r4, r1] */
/* @0x142358 add r0, pc, r0 */
/* @0x14235c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142360 ldr r1, [pc, #0xb5c] */
/* @0x142364 ldr r0, [pc, #0xb5c] */
/* @0x142368 mov r2, #1 */
/* @0x14236c mov r3, #0 */
/* @0x142370 ldr r1, [r4, r1] */
/* @0x142374 add r0, pc, r0 */
/* @0x142378 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14237c ldr r1, [pc, #0xb48] */
/* @0x142380 ldr r0, [pc, #0xb48] */
/* @0x142384 mov r2, #1 */
/* @0x142388 mov r3, #0 */
/* @0x14238c ldr r1, [r4, r1] */
/* @0x142390 add r0, pc, r0 */
/* @0x142394 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142398 ldr r1, [pc, #0xb34] */
/* @0x14239c ldr r0, [pc, #0xb34] */
/* @0x1423a0 mov r2, #0 */
/* @0x1423a4 mov r3, r2 */
/* @0x1423a8 ldr r1, [r4, r1] */
/* @0x1423ac add r0, pc, r0 */
/* @0x1423b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1423b4 ldr r1, [pc, #0xb20] */
/* @0x1423b8 ldr r0, [pc, #0xb20] */
/* @0x1423bc mov r2, #0 */
/* @0x1423c0 mov r3, r2 */
/* @0x1423c4 ldr r1, [r4, r1] */
/* @0x1423c8 add r0, pc, r0 */
/* @0x1423cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1423d0 ldr r1, [pc, #0xb0c] */
/* @0x1423d4 ldr r0, [pc, #0xb0c] */
/* @0x1423d8 mov r2, #0 */
/* @0x1423dc mov r3, r2 */
/* @0x1423e0 ldr r1, [r4, r1] */
/* @0x1423e4 add r0, pc, r0 */
/* @0x1423e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1423ec ldr r1, [pc, #0xaf8] */
/* @0x1423f0 ldr r0, [pc, #0xaf8] */
/* @0x1423f4 mov r2, #0 */
/* @0x1423f8 mov r3, r2 */
/* @0x1423fc ldr r1, [r4, r1] */
/* @0x142400 add r0, pc, r0 */
/* @0x142404 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142408 ldr r1, [pc, #0xae4] */
/* @0x14240c ldr r0, [pc, #0xae4] */
/* @0x142410 mov r2, #0 */
/* @0x142414 mov r3, r2 */
/* @0x142418 ldr r1, [r4, r1] */
/* @0x14241c add r0, pc, r0 */
/* @0x142420 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142424 ldr r1, [pc, #0xad0] */
/* @0x142428 ldr r0, [pc, #0xad0] */
/* @0x14242c mov r2, #2 */
/* @0x142430 mov r3, #0 */
/* @0x142434 ldr r1, [r4, r1] */
/* @0x142438 add r0, pc, r0 */
/* @0x14243c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142440 ldr r1, [pc, #0xabc] */
/* @0x142444 ldr r0, [pc, #0xabc] */
/* @0x142448 mov r2, #2 */
/* @0x14244c mov r3, #0 */
/* @0x142450 ldr r1, [r4, r1] */
/* @0x142454 add r0, pc, r0 */
/* @0x142458 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14245c ldr r1, [pc, #0xaa8] */
/* @0x142460 ldr r0, [pc, #0xaa8] */
/* @0x142464 mov r2, #2 */
/* @0x142468 mov r3, #0 */
/* @0x14246c ldr r1, [r4, r1] */
/* @0x142470 add r0, pc, r0 */
/* @0x142474 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142478 ldr r1, [pc, #0xa94] */
/* @0x14247c ldr r0, [pc, #0xa94] */
/* @0x142480 mov r2, #1 */
/* @0x142484 mov r3, #0 */
/* @0x142488 ldr r1, [r4, r1] */
/* @0x14248c add r0, pc, r0 */
/* @0x142490 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142494 ldr r1, [pc, #0xa80] */
/* @0x142498 ldr r0, [pc, #0xa80] */
/* @0x14249c mov r2, #1 */
/* @0x1424a0 mov r3, #0 */
/* @0x1424a4 ldr r1, [r4, r1] */
/* @0x1424a8 add r0, pc, r0 */
/* @0x1424ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1424b0 ldr r1, [pc, #0xa6c] */
/* @0x1424b4 ldr r0, [pc, #0xa6c] */
/* @0x1424b8 mov r2, #4 */
/* @0x1424bc mov r3, #0 */
/* @0x1424c0 ldr r1, [r4, r1] */
/* @0x1424c4 add r0, pc, r0 */
/* @0x1424c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1424cc ldr r1, [pc, #0xa58] */
/* @0x1424d0 ldr r0, [pc, #0xa58] */
/* @0x1424d4 mov r2, #0 */
/* @0x1424d8 mov r3, r2 */
/* @0x1424dc ldr r1, [r4, r1] */
/* @0x1424e0 add r0, pc, r0 */
/* @0x1424e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1424e8 ldr r1, [pc, #0xa44] */
/* @0x1424ec ldr r0, [pc, #0xa44] */
/* @0x1424f0 mov r2, #0 */
/* @0x1424f4 mov r3, r2 */
/* @0x1424f8 ldr r1, [r4, r1] */
/* @0x1424fc add r0, pc, r0 */
/* @0x142500 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142504 ldr r1, [pc, #0xa30] */
/* @0x142508 ldr r0, [pc, #0xa30] */
/* @0x14250c mov r2, #0 */
/* @0x142510 mov r3, r2 */
/* @0x142514 ldr r1, [r4, r1] */
/* @0x142518 add r0, pc, r0 */
/* @0x14251c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142520 ldr r1, [pc, #0xa1c] */
/* @0x142524 ldr r0, [pc, #0xa1c] */
/* @0x142528 mov r2, #1 */
/* @0x14252c mov r3, #0 */
/* @0x142530 ldr r1, [r4, r1] */
/* @0x142534 add r0, pc, r0 */
/* @0x142538 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14253c ldr r1, [pc, #0xa08] */
/* @0x142540 ldr r0, [pc, #0xa08] */
/* @0x142544 mov r2, #0 */
/* @0x142548 mov r3, r2 */
/* @0x14254c ldr r1, [r4, r1] */
/* @0x142550 add r0, pc, r0 */
/* @0x142554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142558 ldr r1, [pc, #0x9f4] */
/* @0x14255c ldr r0, [pc, #0x9f4] */
/* @0x142560 mov r2, #3 */
/* @0x142564 mov r3, #1 */
/* @0x142568 ldr r1, [r4, r1] */
/* @0x14256c add r0, pc, r0 */
/* @0x142570 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142574 ldr r1, [pc, #0x9e0] */
/* @0x142578 ldr r0, [pc, #0x9e0] */
/* @0x14257c mov r2, #0 */
/* @0x142580 mov r3, r2 */
/* @0x142584 ldr r1, [r4, r1] */
/* @0x142588 add r0, pc, r0 */
/* @0x14258c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142590 ldr r1, [pc, #0x9cc] */
/* @0x142594 ldr r0, [pc, #0x9cc] */
/* @0x142598 mov r2, #0 */
/* @0x14259c mov r3, r2 */
/* @0x1425a0 ldr r1, [r4, r1] */
/* @0x1425a4 add r0, pc, r0 */
/* @0x1425a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1425ac ldr r1, [pc, #0x9b8] */
/* @0x1425b0 ldr r0, [pc, #0x9b8] */
/* @0x1425b4 mov r2, #1 */
/* @0x1425b8 mov r3, #0 */
/* @0x1425bc ldr r1, [r4, r1] */
/* @0x1425c0 add r0, pc, r0 */
/* @0x1425c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1425c8 ldr r1, [pc, #0x9a4] */
/* @0x1425cc ldr r0, [pc, #0x9a4] */
/* @0x1425d0 mov r2, #1 */
/* @0x1425d4 mov r3, #0 */
/* @0x1425d8 ldr r1, [r4, r1] */
/* @0x1425dc add r0, pc, r0 */
/* @0x1425e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1425e4 ldr r1, [pc, #0x990] */
/* @0x1425e8 ldr r0, [pc, #0x990] */
/* @0x1425ec mov r2, #3 */
/* @0x1425f0 mov r3, #1 */
/* @0x1425f4 ldr r1, [r4, r1] */
/* @0x1425f8 add r0, pc, r0 */
/* @0x1425fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142600 ldr r1, [pc, #0x97c] */
/* @0x142604 ldr r0, [pc, #0x97c] */
/* @0x142608 mov r2, #2 */
/* @0x14260c mov r3, #1 */
/* @0x142610 ldr r1, [r4, r1] */
/* @0x142614 add r0, pc, r0 */
/* @0x142618 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14261c ldr r1, [pc, #0x968] */
/* @0x142620 ldr r0, [pc, #0x968] */
/* @0x142624 mov r2, #2 */
/* @0x142628 mov r3, #1 */
/* @0x14262c ldr r1, [r4, r1] */
/* @0x142630 add r0, pc, r0 */
/* @0x142634 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142638 ldr r1, [pc, #0x954] */
/* @0x14263c ldr r0, [pc, #0x954] */
/* @0x142640 mov r2, #3 */
/* @0x142644 mov r3, #0 */
/* @0x142648 ldr r1, [r4, r1] */
/* @0x14264c add r0, pc, r0 */
/* @0x142650 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142654 ldr r1, [pc, #0x940] */
/* @0x142658 ldr r0, [pc, #0x940] */
/* @0x14265c mov r2, #3 */
/* @0x142660 mov r3, #0 */
/* @0x142664 ldr r1, [r4, r1] */
/* @0x142668 add r0, pc, r0 */
/* @0x14266c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142670 ldr r1, [pc, #0x92c] */
/* @0x142674 ldr r0, [pc, #0x92c] */
/* @0x142678 mov r2, #1 */
/* @0x14267c mov r3, #0 */
/* @0x142680 ldr r1, [r4, r1] */
/* @0x142684 add r0, pc, r0 */
/* @0x142688 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14268c ldr r1, [pc, #0x918] */
/* @0x142690 ldr r0, [pc, #0x918] */
/* @0x142694 mov r2, #3 */
/* @0x142698 mov r3, #0 */
/* @0x14269c ldr r1, [r4, r1] */
/* @0x1426a0 add r0, pc, r0 */
/* @0x1426a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1426a8 ldr r1, [pc, #0x904] */
/* @0x1426ac ldr r0, [pc, #0x904] */
/* @0x1426b0 mov r2, #3 */
/* @0x1426b4 mov r3, #0 */
/* @0x1426b8 ldr r1, [r4, r1] */
/* @0x1426bc add r0, pc, r0 */
/* @0x1426c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1426c4 ldr r1, [pc, #0x8f0] */
/* @0x1426c8 ldr r0, [pc, #0x8f0] */
/* @0x1426cc mov r2, #1 */
/* @0x1426d0 mov r3, #0 */
/* @0x1426d4 ldr r1, [r4, r1] */
/* @0x1426d8 add r0, pc, r0 */
/* @0x1426dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1426e0 ldr r1, [pc, #0x8dc] */
/* @0x1426e4 ldr r0, [pc, #0x8dc] */
/* @0x1426e8 mov r2, #1 */
/* @0x1426ec mov r3, #0 */
/* @0x1426f0 ldr r1, [r4, r1] */
/* @0x1426f4 add r0, pc, r0 */
/* @0x1426f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1426fc ldr r1, [pc, #0x8c8] */
/* @0x142700 ldr r0, [pc, #0x8c8] */
/* @0x142704 mov r2, #1 */
/* @0x142708 mov r3, #0 */
/* @0x14270c ldr r1, [r4, r1] */
/* @0x142710 add r0, pc, r0 */
/* @0x142714 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142718 ldr r1, [pc, #0x8b4] */
/* @0x14271c ldr r0, [pc, #0x8b4] */
/* @0x142720 mov r2, #2 */
/* @0x142724 mov r3, #0 */
/* @0x142728 ldr r1, [r4, r1] */
/* @0x14272c add r0, pc, r0 */
/* @0x142730 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142734 ldr r1, [pc, #0x8a0] */
/* @0x142738 ldr r0, [pc, #0x8a0] */
/* @0x14273c mov r2, #6 */
/* @0x142740 mov r3, #0 */
/* @0x142744 ldr r1, [r4, r1] */
/* @0x142748 add r0, pc, r0 */
/* @0x14274c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142750 ldr r1, [pc, #0x88c] */
/* @0x142754 ldr r0, [pc, #0x88c] */
/* @0x142758 mov r2, #0 */
/* @0x14275c mov r3, r2 */
/* @0x142760 ldr r1, [r4, r1] */
/* @0x142764 add r0, pc, r0 */
/* @0x142768 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14276c ldr r1, [pc, #0x878] */
/* @0x142770 ldr r0, [pc, #0x878] */
/* @0x142774 mov r2, #3 */
/* @0x142778 mov r3, #0 */
/* @0x14277c ldr r1, [r4, r1] */
/* @0x142780 add r0, pc, r0 */
/* @0x142784 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142788 ldr r1, [pc, #0x864] */
/* @0x14278c ldr r0, [pc, #0x864] */
/* @0x142790 mov r2, #3 */
/* @0x142794 mov r3, #0 */
/* @0x142798 ldr r1, [r4, r1] */
/* @0x14279c add r0, pc, r0 */
/* @0x1427a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1427a4 ldr r1, [pc, #0x850] */
/* @0x1427a8 ldr r0, [pc, #0x850] */
/* @0x1427ac mov r2, #1 */
/* @0x1427b0 mov r3, #0 */
/* @0x1427b4 ldr r1, [r4, r1] */
/* @0x1427b8 add r0, pc, r0 */
/* @0x1427bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1427c0 ldr r1, [pc, #0x83c] */
/* @0x1427c4 ldr r0, [pc, #0x83c] */
/* @0x1427c8 mov r2, #2 */
/* @0x1427cc mov r3, #0 */
/* @0x1427d0 ldr r1, [r4, r1] */
/* @0x1427d4 add r0, pc, r0 */
/* @0x1427d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1427dc ldr r1, [pc, #0x828] */
/* @0x1427e0 ldr r0, [pc, #0x828] */
/* @0x1427e4 mov r2, #3 */
/* @0x1427e8 mov r3, #0 */
/* @0x1427ec ldr r1, [r4, r1] */
/* @0x1427f0 add r0, pc, r0 */
/* @0x1427f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1427f8 ldr r1, [pc, #0x814] */
/* @0x1427fc ldr r0, [pc, #0x814] */
/* @0x142800 mov r2, #11 */
/* @0x142804 mov r3, #0 */
/* @0x142808 ldr r1, [r4, r1] */
/* @0x14280c add r0, pc, r0 */
/* @0x142810 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142814 ldr r1, [pc, #0x800] */
/* @0x142818 ldr r0, [pc, #0x800] */
/* @0x14281c mov r2, #0 */
/* @0x142820 mov r3, r2 */
/* @0x142824 ldr r1, [r4, r1] */
/* @0x142828 add r0, pc, r0 */
/* @0x14282c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142830 ldr r1, [pc, #0x7ec] */
/* @0x142834 ldr r0, [pc, #0x7ec] */
/* @0x142838 mov r2, #1 */
/* @0x14283c mov r3, #0 */
/* @0x142840 ldr r1, [r4, r1] */
/* @0x142844 add r0, pc, r0 */
/* @0x142848 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14284c ldr r1, [pc, #0x7d8] */
/* @0x142850 ldr r0, [pc, #0x7d8] */
/* @0x142854 mov r2, #2 */
/* @0x142858 mov r3, #0 */
/* @0x14285c ldr r1, [r4, r1] */
/* @0x142860 add r0, pc, r0 */
/* @0x142864 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142868 ldr r1, [pc, #0x7c4] */
/* @0x14286c ldr r0, [pc, #0x7c4] */
/* @0x142870 mov r2, #3 */
/* @0x142874 mov r3, #0 */
/* @0x142878 ldr r1, [r4, r1] */
/* @0x14287c add r0, pc, r0 */
/* @0x142880 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142884 ldr r1, [pc, #0x7b0] */
/* @0x142888 ldr r0, [pc, #0x7b0] */
/* @0x14288c mov r2, #3 */
/* @0x142890 mov r3, #0 */
/* @0x142894 ldr r1, [r4, r1] */
/* @0x142898 add r0, pc, r0 */
/* @0x14289c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1428a0 ldr r1, [pc, #0x79c] */
/* @0x1428a4 ldr r0, [pc, #0x79c] */
/* @0x1428a8 mov r2, #1 */
/* @0x1428ac mov r3, #0 */
/* @0x1428b0 ldr r1, [r4, r1] */
/* @0x1428b4 add r0, pc, r0 */
/* @0x1428b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1428bc ldr r1, [pc, #0x788] */
/* @0x1428c0 ldr r0, [pc, #0x788] */
/* @0x1428c4 mov r2, #2 */
/* @0x1428c8 mov r3, #0 */
/* @0x1428cc ldr r1, [r4, r1] */
/* @0x1428d0 add r0, pc, r0 */
/* @0x1428d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1428d8 ldr r1, [pc, #0x774] */
/* @0x1428dc ldr r0, [pc, #0x774] */
/* @0x1428e0 mov r2, #6 */
/* @0x1428e4 mov r3, #0 */
/* @0x1428e8 ldr r1, [r4, r1] */
/* @0x1428ec add r0, pc, r0 */
/* @0x1428f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1428f4 ldr r1, [pc, #0x760] */
/* @0x1428f8 ldr r0, [pc, #0x760] */
/* @0x1428fc mov r2, #6 */
/* @0x142900 mov r3, #0 */
/* @0x142904 ldr r1, [r4, r1] */
/* @0x142908 add r0, pc, r0 */
/* @0x14290c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142910 ldr r1, [pc, #0x74c] */
/* @0x142914 ldr r0, [pc, #0x74c] */
/* @0x142918 mov r2, #1 */
/* @0x14291c mov r3, r2 */
/* @0x142920 ldr r1, [r4, r1] */
/* @0x142924 add r0, pc, r0 */
/* @0x142928 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14292c ldr r1, [pc, #0x738] */
/* @0x142930 ldr r0, [pc, #0x738] */
/* @0x142934 mov r2, #0 */
/* @0x142938 mov r3, #1 */
/* @0x14293c ldr r1, [r4, r1] */
/* @0x142940 add r0, pc, r0 */
/* @0x142944 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142948 ldr r1, [pc, #0x724] */
/* @0x14294c ldr r0, [pc, #0x724] */
/* @0x142950 mov r2, #0 */
/* @0x142954 mov r3, #1 */
/* @0x142958 ldr r1, [r4, r1] */
/* @0x14295c add r0, pc, r0 */
/* @0x142960 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142964 ldr r1, [pc, #0x710] */
/* @0x142968 ldr r0, [pc, #0x710] */
/* @0x14296c mov r2, #6 */
/* @0x142970 mov r3, #1 */
/* @0x142974 ldr r1, [r4, r1] */
/* @0x142978 add r0, pc, r0 */
/* @0x14297c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142980 ldr r1, [pc, #0x6fc] */
/* @0x142984 ldr r0, [pc, #0x6fc] */
/* @0x142988 mov r2, #6 */
/* @0x14298c mov r3, #1 */
/* @0x142990 ldr r1, [r4, r1] */
/* @0x142994 add r0, pc, r0 */
/* @0x142998 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x14299c ldr r1, [pc, #0x6e8] */
/* @0x1429a0 ldr r0, [pc, #0x6e8] */
/* @0x1429a4 mov r2, #6 */
/* @0x1429a8 mov r3, #1 */
/* @0x1429ac ldr r5, [r4, r1] */
/* @0x1429b0 add r0, pc, r0 */
/* @0x1429b4 mov r1, r5 */
/* @0x1429b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1429bc ldr r0, [pc, #0x6d0] */
/* @0x1429c0 mov r1, r5 */
/* @0x1429c4 mov r2, #6 */
/* @0x1429c8 add r0, pc, r0 */
/* @0x1429cc mov r3, #1 */
/* @0x1429d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1429d4 ldr r1, [pc, #0x6bc] */
/* @0x1429d8 ldr r0, [pc, #0x6bc] */
/* @0x1429dc mov r2, #3 */
/* @0x1429e0 mov r3, #1 */
/* @0x1429e4 ldr r1, [r4, r1] */
/* @0x1429e8 add r0, pc, r0 */
/* @0x1429ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1429f0 ldr r1, [pc, #0x6a8] */
/* @0x1429f4 ldr r0, [pc, #0x6a8] */
/* @0x1429f8 mov r2, #6 */
/* @0x1429fc mov r3, #1 */
/* @0x142a00 ldr r1, [r4, r1] */
/* @0x142a04 add r0, pc, r0 */
/* @0x142a08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142a0c ldr r1, [pc, #0x694] */
/* @0x142a10 ldr r0, [pc, #0x694] */
/* @0x142a14 mov r2, #3 */
/* @0x142a18 mov r3, #1 */
/* @0x142a1c ldr r1, [r4, r1] */
/* @0x142a20 add r0, pc, r0 */
/* @0x142a24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142a28 ldr r1, [pc, #0x680] */
/* @0x142a2c ldr r0, [pc, #0x680] */
/* @0x142a30 mov r2, #5 */
/* @0x142a34 mov r3, #1 */
/* @0x142a38 ldr r1, [r4, r1] */
/* @0x142a3c add r0, pc, r0 */
/* @0x142a40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142a44 ldr r1, [pc, #0x66c] */
/* @0x142a48 ldr r0, [pc, #0x66c] */
/* @0x142a4c mov r2, #6 */
/* @0x142a50 mov r3, #1 */
/* @0x142a54 ldr r1, [r4, r1] */
/* @0x142a58 add r0, pc, r0 */
/* @0x142a5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142a60 ldr r1, [pc, #0x658] */
/* @0x142a64 ldr r0, [pc, #0x658] */
/* @0x142a68 mov r2, #1 */
/* @0x142a6c mov r3, r2 */
/* @0x142a70 ldr r1, [r4, r1] */
/* @0x142a74 add r0, pc, r0 */
/* @0x142a78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142a7c ldr r1, [pc, #0x644] */
/* @0x142a80 ldr r0, [pc, #0x644] */
/* @0x142a84 mov r2, #3 */
/* @0x142a88 mov r3, #1 */
/* @0x142a8c ldr r1, [r4, r1] */
/* @0x142a90 add r0, pc, r0 */
/* @0x142a94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142a98 ldr r1, [pc, #0x630] */
/* @0x142a9c ldr r0, [pc, #0x630] */
/* @0x142aa0 mov r2, #3 */
/* @0x142aa4 mov r3, #1 */
/* @0x142aa8 ldr r1, [r4, r1] */
/* @0x142aac add r0, pc, r0 */
/* @0x142ab0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142ab4 ldr r1, [pc, #0x61c] */
/* @0x142ab8 ldr r0, [pc, #0x61c] */
/* @0x142abc mov r2, #2 */
/* @0x142ac0 mov r3, #1 */
/* @0x142ac4 ldr r1, [r4, r1] */
/* @0x142ac8 add r0, pc, r0 */
/* @0x142acc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142ad0 ldr r1, [pc, #0x608] */
/* @0x142ad4 ldr r0, [pc, #0x608] */
/* @0x142ad8 mov r2, #0 */
/* @0x142adc mov r3, #1 */
/* @0x142ae0 ldr r1, [r4, r1] */
/* @0x142ae4 add r0, pc, r0 */
/* @0x142ae8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142aec ldr r1, [pc, #0x5f4] */
/* @0x142af0 ldr r0, [pc, #0x5f4] */
/* @0x142af4 mov r2, #0 */
/* @0x142af8 mov r3, #1 */
/* @0x142afc ldr r1, [r4, r1] */
/* @0x142b00 add r0, pc, r0 */
/* @0x142b04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142b08 ldr r1, [pc, #0x5e0] */
/* @0x142b0c ldr r0, [pc, #0x5e0] */
/* @0x142b10 mov r2, #0 */
/* @0x142b14 mov r3, #1 */
/* @0x142b18 ldr r1, [r4, r1] */
/* @0x142b1c add r0, pc, r0 */
/* @0x142b20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142b24 ldr r1, [pc, #0x5cc] */
/* @0x142b28 ldr r0, [pc, #0x5cc] */
/* @0x142b2c mov r2, #0 */
/* @0x142b30 mov r3, #1 */
/* @0x142b34 ldr r1, [r4, r1] */
/* @0x142b38 add r0, pc, r0 */
/* @0x142b3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142b40 ldr r1, [pc, #0x5b8] */
/* @0x142b44 ldr r0, [pc, #0x5b8] */
/* @0x142b48 mov r2, #0 */
/* @0x142b4c mov r3, #1 */
/* @0x142b50 ldr r1, [r4, r1] */
/* @0x142b54 add r0, pc, r0 */
/* @0x142b58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142b5c ldr r1, [pc, #0x5a4] */
/* @0x142b60 ldr r0, [pc, #0x5a4] */
/* @0x142b64 mov r2, #2 */
/* @0x142b68 mov r3, #1 */
/* @0x142b6c ldr r1, [r4, r1] */
/* @0x142b70 add r0, pc, r0 */
/* @0x142b74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142b78 ldr r1, [pc, #0x590] */
/* @0x142b7c ldr r0, [pc, #0x590] */
/* @0x142b80 mov r2, #1 */
/* @0x142b84 mov r3, r2 */
/* @0x142b88 ldr r1, [r4, r1] */
/* @0x142b8c add r0, pc, r0 */
/* @0x142b90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142b94 ldr r1, [pc, #0x57c] */
/* @0x142b98 ldr r0, [pc, #0x57c] */
/* @0x142b9c mov r2, #4 */
/* @0x142ba0 mov r3, #0 */
/* @0x142ba4 ldr r1, [r4, r1] */
/* @0x142ba8 add r0, pc, r0 */
/* @0x142bac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142bb0 ldr r1, [pc, #0x568] */
/* @0x142bb4 ldr r0, [pc, #0x568] */
/* @0x142bb8 mov r2, #4 */
/* @0x142bbc mov r3, #0 */
/* @0x142bc0 ldr r1, [r4, r1] */
/* @0x142bc4 add r0, pc, r0 */
/* @0x142bc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142bcc ldr r1, [pc, #0x554] */
/* @0x142bd0 ldr r0, [pc, #0x554] */
/* @0x142bd4 mov r2, #3 */
/* @0x142bd8 mov r3, #0 */
/* @0x142bdc ldr r1, [r4, r1] */
/* @0x142be0 add r0, pc, r0 */
/* @0x142be4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142be8 ldr r1, [pc, #0x540] */
/* @0x142bec ldr r0, [pc, #0x540] */
/* @0x142bf0 mov r2, #6 */
/* @0x142bf4 mov r3, #1 */
/* @0x142bf8 ldr r1, [r4, r1] */
/* @0x142bfc add r0, pc, r0 */
/* @0x142c00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142c04 ldr r1, [pc, #0x52c] */
/* @0x142c08 ldr r0, [pc, #0x52c] */
/* @0x142c0c mov r2, #5 */
/* @0x142c10 mov r3, #0 */
/* @0x142c14 ldr r1, [r4, r1] */
/* @0x142c18 add r0, pc, r0 */
/* @0x142c1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142c20 ldr r1, [pc, #0x518] */
/* @0x142c24 ldr r0, [pc, #0x518] */
/* @0x142c28 mov r2, #6 */
/* @0x142c2c mov r3, #1 */
/* @0x142c30 ldr r1, [r4, r1] */
/* @0x142c34 add r0, pc, r0 */
/* @0x142c38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142c3c ldr r1, [pc, #0x504] */
/* @0x142c40 ldr r0, [pc, #0x504] */
/* @0x142c44 mov r2, #6 */
/* @0x142c48 mov r3, #1 */
/* @0x142c4c ldr r1, [r4, r1] */
/* @0x142c50 add r0, pc, r0 */
/* @0x142c54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142c58 ldr r1, [pc, #0x4f0] */
/* @0x142c5c ldr r0, [pc, #0x4f0] */
/* @0x142c60 mov r2, #5 */
/* @0x142c64 mov r3, #0 */
/* @0x142c68 ldr r1, [r4, r1] */
/* @0x142c6c add r0, pc, r0 */
/* @0x142c70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142c74 ldr r1, [pc, #0x4dc] */
/* @0x142c78 ldr r0, [pc, #0x4dc] */
/* @0x142c7c mov r2, #6 */
/* @0x142c80 mov r3, #1 */
/* @0x142c84 ldr r1, [r4, r1] */
/* @0x142c88 add r0, pc, r0 */
/* @0x142c8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142c90 ldr r1, [pc, #0x4c8] */
/* @0x142c94 ldr r0, [pc, #0x4c8] */
/* @0x142c98 mov r2, #4 */
/* @0x142c9c mov r3, #0 */
/* @0x142ca0 ldr r1, [r4, r1] */
/* @0x142ca4 add r0, pc, r0 */
/* @0x142ca8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142cac ldr r1, [pc, #0x4b4] */
/* @0x142cb0 ldr r0, [pc, #0x4b4] */
/* @0x142cb4 mov r2, #5 */
/* @0x142cb8 mov r3, #0 */
/* @0x142cbc ldr r1, [r4, r1] */
/* @0x142cc0 add r0, pc, r0 */
/* @0x142cc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142cc8 ldr r1, [pc, #0x4a0] */
/* @0x142ccc ldr r0, [pc, #0x4a0] */
/* @0x142cd0 mov r2, #1 */
/* @0x142cd4 mov r3, #0 */
/* @0x142cd8 ldr r5, [r4, r1] */
/* @0x142cdc add r0, pc, r0 */
/* @0x142ce0 mov r1, r5 */
/* @0x142ce4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142ce8 ldr r0, [pc, #0x488] */
/* @0x142cec mov r1, r5 */
/* @0x142cf0 mov r2, #1 */
/* @0x142cf4 add r0, pc, r0 */
/* @0x142cf8 mov r3, #0 */
/* @0x142cfc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142d00 ldr r1, [pc, #0x474] */
/* @0x142d04 ldr r0, [pc, #0x474] */
/* @0x142d08 mov r2, #2 */
/* @0x142d0c mov r3, #0 */
/* @0x142d10 ldr r1, [r4, r1] */
/* @0x142d14 add r0, pc, r0 */
/* @0x142d18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142d1c ldr r1, [pc, #0x460] */
/* @0x142d20 ldr r0, [pc, #0x460] */
/* @0x142d24 mov r2, #1 */
/* @0x142d28 mov r3, #0 */
/* @0x142d2c ldr r1, [r4, r1] */
/* @0x142d30 add r0, pc, r0 */
/* @0x142d34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142d38 ldr r1, [pc, #0x44c] */
/* @0x142d3c ldr r0, [pc, #0x44c] */
/* @0x142d40 mov r2, #1 */
/* @0x142d44 mov r3, r2 */
/* @0x142d48 ldr r1, [r4, r1] */
/* @0x142d4c add r0, pc, r0 */
/* @0x142d50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142d54 ldr r1, [pc, #0x438] */
/* @0x142d58 ldr r0, [pc, #0x438] */
/* @0x142d5c mov r2, #6 */
/* @0x142d60 mov r3, #1 */
/* @0x142d64 ldr r1, [r4, r1] */
/* @0x142d68 add r0, pc, r0 */
/* @0x142d6c pop {r4, r5, r6, lr} */
/* @0x142d70 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x142d74 .word 0x002afdd8 */
/* @0x142d78 .word 0xffffd78c */
/* @0x142d7c .word 0xffffd790 */
/* @0x142d80 .word 0xffffd794 */
/* @0x142d84 .word 0xffffd7a0 */
/* @0x142d88 andseq lr, pc, r8, ror #23 */
/* @0x142d8c .word 0xffffd7a4 */
/* @0x142d90 ldrsbeq lr, [pc], -r8 */
/* @0x142d94 ldrsbeq lr, [pc], -r8 */
/* @0x142d98 ldrsbeq lr, [pc], -r4 */
/* @0x142d9c ldrsbeq lr, [pc], -r4 */
/* @0x142da0 ldrsbeq lr, [pc], -r0 */
/* @0x142da4 andseq lr, pc, r12, asr #23 */
/* @0x142da8 andseq lr, pc, r8, asr #23 */
/* @0x142dac andseq lr, pc, r0, asr #23 */
/* @0x142db0 .word 0xffffd7a8 */
/* @0x142db4 ldrheq lr, [pc], -r8 */
/* @0x142db8 .word 0xffffd7ac */
/* @0x142dbc ldrheq lr, [pc], -r0 */
/* @0x142dc0 .word 0xffffd7b0 */
/* @0x142dc4 andseq lr, pc, r0, lsr #23 */
/* @0x142dc8 .word 0xffffd7b4 */
/* @0x142dcc mulseq pc, r8, r11 */
/* @0x142dd0 .word 0xffffd7b8 */
/* @0x142dd4 mulseq pc, r0, r11 */
/* @0x142dd8 .word 0xffffd7bc */
/* @0x142ddc andseq lr, pc, r8, lsl #23 */
/* @0x142de0 .word 0xffffd7c0 */
/* @0x142de4 andseq lr, pc, r0, lsl #23 */
/* @0x142de8 .word 0xffffd7c4 */
/* @0x142dec andseq lr, pc, r8, ror r11 */
/* @0x142df0 .word 0xffffd7c8 */
/* @0x142df4 andseq lr, pc, r0, ror r11 */
/* @0x142df8 .word 0xffffd7cc */
/* @0x142dfc andseq lr, pc, r4, ror #22 */
/* @0x142e00 .word 0xffffd7d0 */
/* @0x142e04 andseq lr, pc, r12, asr r11 */
/* @0x142e08 .word 0xffffd7d4 */
/* @0x142e0c andseq lr, pc, r4, asr r11 */
/* @0x142e10 .word 0xffffd7d8 */
/* @0x142e14 andseq lr, pc, r4, asr #22 */
/* @0x142e18 .word 0xffffd7dc */
/* @0x142e1c andseq lr, pc, r4, lsr r11 */
/* @0x142e20 .word 0xffffd7e0 */
/* @0x142e24 andseq lr, pc, r12, lsr #22 */
/* @0x142e28 .word 0xffffd7e4 */
/* @0x142e2c andseq lr, pc, r4, lsr #22 */
/* @0x142e30 .word 0xffffd7e8 */
/* @0x142e34 andseq lr, pc, r12, lsl r11 */
/* @0x142e38 .word 0xffffd7ec */
/* @0x142e3c andseq lr, pc, r0, lsl r11 */
/* @0x142e40 .word 0xffffd7f0 */
/* @0x142e44 andseq lr, pc, r0, lsl #22 */
/* @0x142e48 .word 0xffffd7f4 */
/* @0x142e4c ldrsheq lr, [pc], -r4 */
/* @0x142e50 .word 0xffffd7f8 */
/* @0x142e54 ldrsheq lr, [pc], -r0 */
/* @0x142e58 .word 0xffffd7fc */
/* @0x142e5c andseq lr, pc, r8, ror #21 */
/* @0x142e60 .word 0xffffd800 */
/* @0x142e64 andseq lr, pc, r0, ror #21 */
/* @0x142e68 .word 0xffffd804 */
/* @0x142e6c ldrsbeq lr, [pc], -r12 */
/* @0x142e70 .word 0xffffd808 */
/* @0x142e74 ldrsbeq lr, [pc], -r4 */
/* @0x142e78 .word 0xffffd80c */
/* @0x142e7c ldrsbeq lr, [pc], -r0 */
/* @0x142e80 .word 0xffffd810 */
/* @0x142e84 ldrsbeq lr, [pc], -r0 */
/* @0x142e88 .word 0xffffd814 */
/* @0x142e8c ldrsbeq lr, [pc], -r0 */
/* @0x142e90 .word 0xffffd818 */
/* @0x142e94 andseq lr, pc, r12, asr #21 */
/* @0x142e98 .word 0xffffd81c */
/* @0x142e9c andseq lr, pc, r8, asr #21 */
/* @0x142ea0 .word 0xffffd820 */
/* @0x142ea4 andseq lr, pc, r0, asr #21 */
/* @0x142ea8 .word 0xffffd824 */
/* @0x142eac ldrheq lr, [pc], -r12 */
/* @0x142eb0 ldrheq lr, [pc], -r8 */
/* @0x142eb4 .word 0xffffd828 */
/* @0x142eb8 ldrheq lr, [pc], -r0 */
/* @0x142ebc .word 0xffffd82c */
/* @0x142ec0 andseq lr, pc, r4, lsr #21 */
/* @0x142ec4 .word 0xffffd830 */
/* @0x142ec8 mulseq pc, r12, r10 */
/* @0x142ecc .word 0xffffd834 */
/* @0x142ed0 mulseq pc, r0, r10 */
/* @0x142ed4 .word 0xffffd838 */
/* @0x142ed8 andseq lr, pc, r8, lsl #21 */
/* @0x142edc .word 0xffffd83c */
/* @0x142ee0 andseq lr, pc, r0, lsl #21 */
/* @0x142ee4 .word 0xffffd840 */
/* @0x142ee8 andseq lr, pc, r12, ror r10 */
/* @0x142eec .word 0xffffd844 */
/* @0x142ef0 andseq lr, pc, r4, ror r10 */
/* @0x142ef4 .word 0xffffd848 */
/* @0x142ef8 andseq lr, pc, r0, ror r10 */
/* @0x142efc .word 0xffffd84c */
/* @0x142f00 andseq lr, pc, r8, ror #20 */
/* @0x142f04 .word 0xffffd850 */
/* @0x142f08 andseq lr, pc, r0, ror #20 */
/* @0x142f0c .word 0xffffd854 */
/* @0x142f10 andseq lr, pc, r4, asr r10 */
/* @0x142f14 .word 0xffffd858 */
/* @0x142f18 andseq lr, pc, r12, asr #20 */
/* @0x142f1c .word 0xffffd85c */
/* @0x142f20 andseq lr, pc, r0, asr r10 */
/* @0x142f24 .word 0xffffd860 */
/* @0x142f28 andseq lr, pc, r0, asr r10 */
/* @0x142f2c .word 0xffffd864 */
/* @0x142f30 andseq lr, pc, r8, asr #20 */
/* @0x142f34 .word 0xffffd868 */
/* @0x142f38 andseq lr, pc, r4, asr #20 */
/* @0x142f3c .word 0xffffd86c */
/* @0x142f40 andseq lr, pc, r0, asr #20 */
/* @0x142f44 .word 0xffffd870 */
/* @0x142f48 andseq lr, pc, r12, lsr r10 */
/* @0x142f4c .word 0xffffd874 */
/* @0x142f50 andseq lr, pc, r0, lsr r10 */
/* @0x142f54 .word 0xffffd878 */
/* @0x142f58 andseq lr, pc, r8, lsr #20 */
/* @0x142f5c .word 0xffffd87c */
/* @0x142f60 andseq lr, pc, r0, lsr #20 */
/* @0x142f64 .word 0xffffd880 */
/* @0x142f68 andseq lr, pc, r4, lsl r10 */
/* @0x142f6c .word 0xffffd884 */
/* @0x142f70 andseq lr, pc, r12, lsl #20 */
/* @0x142f74 .word 0xffffd888 */
/* @0x142f78 andseq lr, pc, r4, lsl #20 */
/* @0x142f7c .word 0xffffd88c */
/* @0x142f80 ldrsheq lr, [pc], -r12 */
/* @0x142f84 .word 0xffffd890 */
/* @0x142f88 ldrsheq lr, [pc], -r8 */
/* @0x142f8c .word 0xffffd894 */
/* @0x142f90 ldrsheq lr, [pc], -r4 */
/* @0x142f94 .word 0xffffd898 */
/* @0x142f98 ldrsheq lr, [pc], -r4 */
/* @0x142f9c .word 0xffffd89c */
/* @0x142fa0 andseq lr, pc, r8, ror #19 */
/* @0x142fa4 .word 0xffffd8a0 */
/* @0x142fa8 andseq lr, pc, r0, ror #19 */
/* @0x142fac .word 0xffffd8a4 */
/* @0x142fb0 ldrsbeq lr, [pc], -r0 */
/* @0x142fb4 .word 0xffffd8a8 */
/* @0x142fb8 andseq lr, pc, r8, asr #19 */
/* @0x142fbc .word 0xffffd8ac */
/* @0x142fc0 andseq lr, pc, r0, asr #19 */
/* @0x142fc4 .word 0xffffd8b0 */
/* @0x142fc8 ldrheq lr, [pc], -r8 */
/* @0x142fcc .word 0xffffd8b4 */
/* @0x142fd0 andseq lr, pc, r12, lsr #19 */
/* @0x142fd4 .word 0xffffd8b8 */
/* @0x142fd8 andseq lr, pc, r0, lsr #19 */
/* @0x142fdc .word 0xffffd8bc */
/* @0x142fe0 mulseq pc, r8, r9 */
/* @0x142fe4 .word 0xffffd8c0 */
/* @0x142fe8 mulseq pc, r4, r9 */
/* @0x142fec .word 0xffffd8c4 */
/* @0x142ff0 andseq lr, pc, r12, lsl #19 */
/* @0x142ff4 .word 0xffffd8c8 */
/* @0x142ff8 andseq lr, pc, r4, lsl #19 */
/* @0x142ffc .word 0xffffd8cc */
/* @0x143000 andseq lr, pc, r0, lsl #19 */
/* @0x143004 .word 0xffffd8d0 */
/* @0x143008 andseq lr, pc, r8, ror r9 */
/* @0x14300c .word 0xffffd8d4 */
/* @0x143010 andseq lr, pc, r12, ror #18 */
/* @0x143014 .word 0xffffd8d8 */
/* @0x143018 andseq lr, pc, r4, ror #18 */
/* @0x14301c .word 0xffffd8dc */
/* @0x143020 andseq lr, pc, r0, ror #18 */
/* @0x143024 .word 0xffffd8e0 */
/* @0x143028 andseq lr, pc, r12, asr r9 */
/* @0x14302c .word 0xffffd8e4 */
/* @0x143030 andseq lr, pc, r0, asr r9 */
/* @0x143034 .word 0xffffd8e8 */
/* @0x143038 andseq lr, pc, r4, asr #18 */
/* @0x14303c .word 0xffffd8ec */
/* @0x143040 andseq lr, pc, r12, lsr r9 */
/* @0x143044 .word 0xffffd8f0 */
/* @0x143048 andseq lr, pc, r8, lsr r9 */
/* @0x14304c .word 0xffffd8f4 */
/* @0x143050 andseq lr, pc, r0, lsr r9 */
/* @0x143054 .word 0xffffd8f8 */
/* @0x143058 andseq lr, pc, r8, lsr #18 */
/* @0x14305c .word 0xffffd8fc */
/* @0x143060 andseq lr, pc, r0, lsr #18 */
/* @0x143064 .word 0xffffd900 */
/* @0x143068 andseq lr, pc, r8, lsl r9 */
/* @0x14306c .word 0xffffd904 */
/* @0x143070 andseq lr, pc, r4, lsl r9 */
/* @0x143074 .word 0xffffd908 */
/* @0x143078 andseq lr, pc, r0, lsl r9 */
/* @0x14307c .word 0xffffd90c */
/* @0x143080 andseq lr, pc, r12, lsl #18 */
/* @0x143084 .word 0xffffd910 */
/* @0x143088 andseq lr, pc, r12, lsl #18 */
/* @0x14308c .word 0xffffd914 */
/* @0x143090 andseq lr, pc, r8, lsl #18 */
/* @0x143094 andseq lr, pc, r8, lsl #18 */
/* @0x143098 .word 0xffffd918 */
/* @0x14309c andseq lr, pc, r0, lsl #18 */
/* @0x1430a0 .word 0xffffd91c */
/* @0x1430a4 ldrsheq lr, [pc], -r12 */
/* @0x1430a8 .word 0xffffd920 */
/* @0x1430ac ldrsheq lr, [pc], -r8 */
/* @0x1430b0 .word 0xffffd924 */
/* @0x1430b4 ldrsheq lr, [pc], -r4 */
/* @0x1430b8 .word 0xffffd928 */
/* @0x1430bc ldrsheq lr, [pc], -r4 */
/* @0x1430c0 .word 0xffffd92c */
/* @0x1430c4 ldrsheq lr, [pc], -r0 */
/* @0x1430c8 .word 0xffffd930 */
/* @0x1430cc andseq lr, pc, r12, ror #17 */
/* @0x1430d0 .word 0xffffd934 */
/* @0x1430d4 andseq lr, pc, r8, ror #17 */
/* @0x1430d8 .word 0xffffd938 */
/* @0x1430dc andseq lr, pc, r4, ror #17 */
/* @0x1430e0 .word 0xffffd93c */
/* @0x1430e4 ldrsbeq lr, [pc], -r8 */
/* @0x1430e8 .word 0xffffd940 */
/* @0x1430ec andseq lr, pc, r12, asr #17 */
/* @0x1430f0 .word 0xffffd944 */
/* @0x1430f4 andseq lr, pc, r0, asr #17 */
/* @0x1430f8 .word 0xffffd948 */
/* @0x1430fc ldrheq lr, [pc], -r8 */
/* @0x143100 .word 0xffffd94c */
/* @0x143104 ldrheq lr, [pc], -r0 */
/* @0x143108 .word 0xffffd950 */
/* @0x14310c andseq lr, pc, r8, lsr #17 */
/* @0x143110 .word 0xffffd954 */
/* @0x143114 andseq lr, pc, r0, lsr #17 */
/* @0x143118 .word 0xffffd958 */
/* @0x14311c mulseq pc, r4, r8 */
/* @0x143120 .word 0xffffd95c */
/* @0x143124 andseq lr, pc, r12, lsl #17 */
/* @0x143128 .word 0xffffd960 */
/* @0x14312c andseq lr, pc, r8, lsl #17 */
/* @0x143130 .word 0xffffd964 */
/* @0x143134 andseq lr, pc, r0, lsl #17 */
/* @0x143138 .word 0xffffd968 */
/* @0x14313c andseq lr, pc, r4, lsl #17 */
/* @0x143140 .word 0xffffd96c */
/* @0x143144 andseq lr, pc, r0, lsl #17 */
/* @0x143148 .word 0xffffd970 */
/* @0x14314c andseq lr, pc, r0, lsl #17 */
/* @0x143150 .word 0xffffd974 */
/* @0x143154 andseq lr, pc, r0, lsl #17 */
/* @0x143158 .word 0xffffd978 */
/* @0x14315c andseq lr, pc, r8, ror r8 */
/* @0x143160 .word 0xffffd97c */
/* @0x143164 andseq lr, pc, r12, ror r8 */
/* @0x143168 .word 0xffffd980 */
/* @0x14316c andseq lr, pc, r4, ror r8 */
/* @0x143170 .word 0xffffd984 */
/* @0x143174 andseq lr, pc, r12, ror #16 */
/* @0x143178 andseq lr, pc, r4, ror #16 */
/* @0x14317c .word 0xffffd988 */
/* @0x143180 andseq lr, pc, r4, asr r8 */
/* @0x143184 .word 0xffffd98c */
/* @0x143188 andseq lr, pc, r4, asr #16 */
/* @0x14318c .word 0xffffd990 */
/* @0x143190 andseq lr, pc, r12, lsr r8 */
/* @0x143194 .word 0xffffd994 */
/* @0x143198 andseq lr, pc, r0, lsr r8 */

/* ── FUNC 0x14319c · F_ActionSetCaption(RValue&, CInstance*, CInstance*, int, RValue*) · size=776 · insn=194 */
/* @0x14319c push {r4, r5, r6, r7, r8, lr} */
/* @0x1431a0 mov r1, #0 */
/* @0x1431a4 ldr r4, [pc, #0x2d8] */
/* @0x1431a8 mov r2, #1 */
/* @0x1431ac ldr r3, [pc, #0x2d4] */
/* @0x1431b0 add r4, pc, r4 */
/* @0x1431b4 ldr r5, [sp, #0x18] */
/* @0x1431b8 ldr r3, [r4, r3] */
/* @0x1431bc mov r0, r5 */
/* @0x1431c0 strb r2, [r3] */
/* @0x1431c4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1431c8 ldr r2, [pc, #0x2bc] */
/* @0x1431cc ldr r3, [pc, #0x2bc] */
/* @0x1431d0 ldr r2, [r4, r2] */
/* @0x1431d4 strb r0, [r2] */
/* @0x1431d8 ldr r8, [r4, r3] */
/* @0x1431dc ldr r6, [r8] */
/* @0x1431e0 cmp r6, #0 */
/* @0x1431e4 beq 0x14320c <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1431e8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1431ec ldr r7, [r6, #0x4] */
/* @0x1431f0 sub r7, r7, #1 */
/* @0x1431f4 str r7, [r6, #0x4] */
/* @0x1431f8 cmp r7, #0 */
/* @0x1431fc beq 0x1433e0 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x244> */
/* @0x143200 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x143204 mov r0, r6 */
/* @0x143208 bl 0x27d1d0 <_ZdlPv> */
/* @0x14320c mov r1, #1 */
/* @0x143210 mov r0, r5 */
/* @0x143214 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x143218 mov r7, r0 */
/* @0x14321c mov r0, #12 */
/* @0x143220 bl 0x27c524 <_Znwj> */
/* @0x143224 mov r6, r0 */
/* @0x143228 subs r0, r7, #0 */
/* @0x14322c beq 0x143234 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x143230 bl 0xb6538 <strlen@plt> */
/* @0x143234 str r0, [r6, #0x8] */
/* @0x143238 mov r0, r7 */
/* @0x14323c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x143240 mov r3, #1 */
/* @0x143244 mov r1, #2 */
/* @0x143248 stm r6, {r0, r3} */
/* @0x14324c mov r0, r5 */
/* @0x143250 str r6, [r8] */
/* @0x143254 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x143258 ldr r2, [pc, #0x234] */
/* @0x14325c ldr r3, [pc, #0x234] */
/* @0x143260 ldr r2, [r4, r2] */
/* @0x143264 strb r0, [r2] */
/* @0x143268 ldr r8, [r4, r3] */
/* @0x14326c ldr r6, [r8] */
/* @0x143270 cmp r6, #0 */
/* @0x143274 beq 0x14329c <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x143278 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x14327c ldr r7, [r6, #0x4] */
/* @0x143280 sub r7, r7, #1 */
/* @0x143284 str r7, [r6, #0x4] */
/* @0x143288 cmp r7, #0 */
/* @0x14328c beq 0x1433a8 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x143290 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x143294 mov r0, r6 */
/* @0x143298 bl 0x27d1d0 <_ZdlPv> */
/* @0x14329c mov r1, #3 */
/* @0x1432a0 mov r0, r5 */
/* @0x1432a4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1432a8 mov r7, r0 */
/* @0x1432ac mov r0, #12 */
/* @0x1432b0 bl 0x27c524 <_Znwj> */
/* @0x1432b4 mov r6, r0 */
/* @0x1432b8 subs r0, r7, #0 */
/* @0x1432bc beq 0x1432c4 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x1432c0 bl 0xb6538 <strlen@plt> */
/* @0x1432c4 str r0, [r6, #0x8] */
/* @0x1432c8 mov r0, r7 */
/* @0x1432cc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1432d0 mov r3, #1 */
/* @0x1432d4 mov r1, #4 */
/* @0x1432d8 stm r6, {r0, r3} */
/* @0x1432dc mov r0, r5 */
/* @0x1432e0 str r6, [r8] */
/* @0x1432e4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1432e8 ldr r2, [pc, #0x1ac] */
/* @0x1432ec ldr r3, [pc, #0x1ac] */
/* @0x1432f0 ldr r2, [r4, r2] */
/* @0x1432f4 strb r0, [r2] */
/* @0x1432f8 ldr r6, [r4, r3] */
/* @0x1432fc ldr r4, [r6] */
/* @0x143300 cmp r4, #0 */
/* @0x143304 beq 0x14332c <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x143308 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x14330c ldr r7, [r4, #0x4] */
/* @0x143310 sub r7, r7, #1 */
/* @0x143314 str r7, [r4, #0x4] */
/* @0x143318 cmp r7, #0 */
/* @0x14331c beq 0x143370 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x143320 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x143324 mov r0, r4 */
/* @0x143328 bl 0x27d1d0 <_ZdlPv> */
/* @0x14332c mov r0, r5 */
/* @0x143330 mov r1, #5 */
/* @0x143334 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x143338 mov r5, r0 */
/* @0x14333c mov r0, #12 */
/* @0x143340 bl 0x27c524 <_Znwj> */
/* @0x143344 mov r4, r0 */
/* @0x143348 subs r0, r5, #0 */
/* @0x14334c beq 0x143354 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x143350 bl 0xb6538 <strlen@plt> */
/* @0x143354 str r0, [r4, #0x8] */
/* @0x143358 mov r0, r5 */
/* @0x14335c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x143360 mov r3, #1 */
/* @0x143364 stm r4, {r0, r3} */
/* @0x143368 str r4, [r6] */
/* @0x14336c pop {r4, r5, r6, r7, r8, pc} */
/* @0x143370 ldr r0, [r4] */
/* @0x143374 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x143378 str r7, [r4] */
/* @0x14337c str r7, [r4, #0x8] */
/* @0x143380 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x143384 ldr r7, [r4, #0x4] */
/* @0x143388 sub r7, r7, #1 */
/* @0x14338c str r7, [r4, #0x4] */
/* @0x143390 cmp r7, #0 */
/* @0x143394 beq 0x143418 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x27c> */
/* @0x143398 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x14339c mov r0, r4 */
/* @0x1433a0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1433a4 b 0x143320 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x1433a8 ldr r0, [r6] */
/* @0x1433ac bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1433b0 str r7, [r6] */
/* @0x1433b4 str r7, [r6, #0x8] */
/* @0x1433b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1433bc ldr r7, [r6, #0x4] */
/* @0x1433c0 sub r7, r7, #1 */
/* @0x1433c4 str r7, [r6, #0x4] */
/* @0x1433c8 cmp r7, #0 */
/* @0x1433cc beq 0x143460 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x2c4> */
/* @0x1433d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1433d4 mov r0, r6 */
/* @0x1433d8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1433dc b 0x143290 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x1433e0 ldr r0, [r6] */
/* @0x1433e4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1433e8 str r7, [r6] */
/* @0x1433ec str r7, [r6, #0x8] */
/* @0x1433f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1433f4 ldr r7, [r6, #0x4] */
/* @0x1433f8 sub r7, r7, #1 */
/* @0x1433fc str r7, [r6, #0x4] */
/* @0x143400 cmp r7, #0 */
/* @0x143404 beq 0x14343c <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x2a0> */
/* @0x143408 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x14340c mov r0, r6 */
/* @0x143410 bl 0x27d1d0 <_ZdlPv> */
/* @0x143414 b 0x143200 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x143418 ldr r0, [r4] */
/* @0x14341c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x143420 mov r0, r4 */
/* @0x143424 str r7, [r4] */
/* @0x143428 str r7, [r4, #0x8] */
/* @0x14342c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x143430 mov r0, r4 */
/* @0x143434 bl 0x27d1d0 <_ZdlPv> */
/* @0x143438 b 0x143398 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x14343c ldr r0, [r6] */
/* @0x143440 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x143444 mov r0, r6 */
/* @0x143448 str r7, [r6] */
/* @0x14344c str r7, [r6, #0x8] */
/* @0x143450 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x143454 mov r0, r6 */
/* @0x143458 bl 0x27d1d0 <_ZdlPv> */
/* @0x14345c b 0x143408 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x143460 ldr r0, [r6] */
/* @0x143464 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x143468 mov r0, r6 */
/* @0x14346c str r7, [r6] */
/* @0x143470 str r7, [r6, #0x8] */
/* @0x143474 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x143478 mov r0, r6 */
/* @0x14347c bl 0x27d1d0 <_ZdlPv> */
/* @0x143480 b 0x1433d0 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0x143484 eoreq lr, r10, r0, lsr #21 */
/* @0x143488 .word 0xffffd998 */
/* @0x14348c .word 0xffffd99c */
/* @0x143490 .word 0xffffd9a0 */
/* @0x143494 .word 0xffffd9a4 */
/* @0x143498 .word 0xffffd9a8 */
/* @0x14349c .word 0xffffd9ac */
/* @0x1434a0 .word 0xffffd9b0 */

/* ── FUNC 0x1434a4 · F_ActionIf(RValue&, CInstance*, CInstance*, int, RValue*) · size=452 · insn=113 */
/* @0x1434a4 ldr r2, [r0, #0xc] */
/* @0x1434a8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1434ac bic r3, r2, #-16777216 */
/* @0x1434b0 cmp r3, #1 */
/* @0x1434b4 mov r4, r0 */
/* @0x1434b8 ldr r5, [sp, #0x18] */
/* @0x1434bc beq 0x14356c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x1434c0 cmp r3, #2 */
/* @0x1434c4 bne 0x1434ec <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1434c8 sub r2, r2, #1 */
/* @0x1434cc bic r2, r2, #-16777216 */
/* @0x1434d0 bic r2, r2, #3 */
/* @0x1434d4 cmp r2, #0 */
/* @0x1434d8 beq 0x143660 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x1434dc mov r2, #0 */
/* @0x1434e0 mov r3, #5 */
/* @0x1434e4 str r2, [r4, #0x8] */
/* @0x1434e8 str r3, [r4, #0xc] */
/* @0x1434ec ldr r3, [r5, #0xc] */
/* @0x1434f0 mov r1, #0 */
/* @0x1434f4 ldr r2, [r5, #0x8] */
/* @0x1434f8 str r1, [r4] */
/* @0x1434fc str r3, [r4, #0xc] */
/* @0x143500 ldr r3, [r5, #0xc] */
/* @0x143504 str r2, [r4, #0x8] */
/* @0x143508 bic r3, r3, #-16777216 */
/* @0x14350c cmp r3, #14 */
/* @0x143510 addls pc, pc, r3, lsl #2 */
/* @0x143514 b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x143518 b 0x143560 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x14351c b 0x1435c4 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x143520 b 0x1435dc <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x143524 b 0x143554 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x143528 b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x14352c b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x143530 b 0x1435a0 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x143534 b 0x143554 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x143538 b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x14353c b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x143540 b 0x143560 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x143544 b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x143548 b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x14354c b 0x143560 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x143550 b 0x143554 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x143554 ldr r3, [r5] */
/* @0x143558 str r3, [r4] */
/* @0x14355c pop {r3, r4, r5, r6, r7, pc} */
/* @0x143560 ldm r5, {r2, r3} */
/* @0x143564 stm r4, {r2, r3} */
/* @0x143568 pop {r3, r4, r5, r6, r7, pc} */
/* @0x14356c ldr r6, [r0] */
/* @0x143570 cmp r6, #0 */
/* @0x143574 beq 0x143594 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x143578 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x14357c ldr r7, [r6, #0x4] */
/* @0x143580 sub r7, r7, #1 */
/* @0x143584 str r7, [r6, #0x4] */
/* @0x143588 cmp r7, #0 */
/* @0x14358c beq 0x143608 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x143590 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x143594 mov r3, #0 */
/* @0x143598 str r3, [r4] */
/* @0x14359c b 0x1434ec <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1435a0 ldr r3, [r5] */
/* @0x1435a4 str r3, [r4] */
/* @0x1435a8 ldr r3, [r5] */
/* @0x1435ac cmp r3, #0 */
/* @0x1435b0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1435b4 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1435b8 ldr r1, [r5] */
/* @0x1435bc pop {r3, r4, r5, r6, r7, lr} */
/* @0x1435c0 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1435c4 ldr r3, [r5] */
/* @0x1435c8 cmp r3, #0 */
/* @0x1435cc ldrne r2, [r3, #0x4] */
/* @0x1435d0 addne r2, r2, #1 */
/* @0x1435d4 strne r2, [r3, #0x4] */
/* @0x1435d8 b 0x143558 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x1435dc ldr r3, [r5] */
/* @0x1435e0 cmp r3, #0 */
/* @0x1435e4 str r3, [r4] */
/* @0x1435e8 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1435ec ldr r1, [r3, #0x8] */
/* @0x1435f0 ldr r2, [r3] */
/* @0x1435f4 cmp r1, #0 */
/* @0x1435f8 streq r4, [r3, #0x8] */
/* @0x1435fc add r2, r2, #1 */
/* @0x143600 str r2, [r3] */
/* @0x143604 pop {r3, r4, r5, r6, r7, pc} */
/* @0x143608 ldr r0, [r6] */
/* @0x14360c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x143610 str r7, [r6] */
/* @0x143614 str r7, [r6, #0x8] */
/* @0x143618 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x14361c ldr r7, [r6, #0x4] */
/* @0x143620 sub r7, r7, #1 */
/* @0x143624 str r7, [r6, #0x4] */
/* @0x143628 cmp r7, #0 */
/* @0x14362c bne 0x143650 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x143630 ldr r0, [r6] */
/* @0x143634 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x143638 mov r0, r6 */
/* @0x14363c str r7, [r6] */
/* @0x143640 str r7, [r6, #0x8] */
/* @0x143644 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x143648 mov r0, r6 */
/* @0x14364c bl 0x27d1d0 <_ZdlPv> */
/* @0x143650 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x143654 mov r0, r6 */
/* @0x143658 bl 0x27d1d0 <_ZdlPv> */
/* @0x14365c b 0x143590 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x143660 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x143664 b 0x1434dc <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x38> */
