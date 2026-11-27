/* libyoyo.so 覆盖卡组 0153
 * 函数 0x1c961c..0x1cb390，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1c961c · Command_Wrap(CInstance*, bool, bool) · size=464 · insn=116 */
/* @0x1c961c push {r3, r4, r5, r6, r7, lr} */
/* @0x1c9620 vpush {d8} */
/* @0x1c9624 mov r4, r0 */
/* @0x1c9628 ldr r0, [r0, #0x8c] */
/* @0x1c962c mov r7, r1 */
/* @0x1c9630 mov r6, r2 */
/* @0x1c9634 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1c9638 ldr r5, [pc, #0x1a4] */
/* @0x1c963c add r5, pc, r5 */
/* @0x1c9640 cmp r0, #0 */
/* @0x1c9644 bne 0x1c9708 <_Z12Command_WrapP9CInstancebb+0xec> */
/* @0x1c9648 vldr s16, [pc, #400] */
/* @0x1c964c vmov.f32 s17, s16 */
/* @0x1c9650 cmp r7, #0 */
/* @0x1c9654 beq 0x1c9698 <_Z12Command_WrapP9CInstancebb+0x7c> */
/* @0x1c9658 vldr s15, [r4, #224] */
/* @0x1c965c vcmpe.f32 s15, #0 */
/* @0x1c9660 vmrs APSR_nzcv, fpscr */
/* @0x1c9664 bmi 0x1c979c <_Z12Command_WrapP9CInstancebb+0x180> */
/* @0x1c9668 vcmpe.f32 s15, #0 */
/* @0x1c966c vmrs APSR_nzcv, fpscr */
/* @0x1c9670 ble 0x1c9698 <_Z12Command_WrapP9CInstancebb+0x7c> */
/* @0x1c9674 ldr r3, [pc, #0x16c] */
/* @0x1c9678 vldr s14, [r4, #180] */
/* @0x1c967c ldr r3, [r5, r3] */
/* @0x1c9680 ldr r3, [r3] */
/* @0x1c9684 vldr s15, [r3, #16] */
/* @0x1c9688 vcvt.f32.s32 s15, s15 */
/* @0x1c968c vcmpe.f32 s14, s15 */
/* @0x1c9690 vmrs APSR_nzcv, fpscr */
/* @0x1c9694 bge 0x1c973c <_Z12Command_WrapP9CInstancebb+0x120> */
/* @0x1c9698 cmp r6, #0 */
/* @0x1c969c beq 0x1c9700 <_Z12Command_WrapP9CInstancebb+0xe4> */
/* @0x1c96a0 vldr s15, [r4, #228] */
/* @0x1c96a4 vcmpe.f32 s15, #0 */
/* @0x1c96a8 vmrs APSR_nzcv, fpscr */
/* @0x1c96ac bmi 0x1c9758 <_Z12Command_WrapP9CInstancebb+0x13c> */
/* @0x1c96b0 vcmpe.f32 s15, #0 */
/* @0x1c96b4 vmrs APSR_nzcv, fpscr */
/* @0x1c96b8 ble 0x1c9700 <_Z12Command_WrapP9CInstancebb+0xe4> */
/* @0x1c96bc ldr r3, [pc, #0x124] */
/* @0x1c96c0 vldr s14, [r4, #184] */
/* @0x1c96c4 ldr r3, [r5, r3] */
/* @0x1c96c8 ldr r3, [r3] */
/* @0x1c96cc vldr s15, [r3, #20] */
/* @0x1c96d0 vcvt.f32.s32 s15, s15 */
/* @0x1c96d4 vcmpe.f32 s14, s15 */
/* @0x1c96d8 vmrs APSR_nzcv, fpscr */
/* @0x1c96dc blt 0x1c9700 <_Z12Command_WrapP9CInstancebb+0xe4> */
/* @0x1c96e0 vsub.f32 s15, s14, s15 */
/* @0x1c96e4 mov r0, r4 */
/* @0x1c96e8 ldr r1, [r4, #0xb4] */
/* @0x1c96ec vsub.f32 s15, s15, s16 */
/* @0x1c96f0 vpop {d8} */
/* @0x1c96f4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1c96f8 vmov r2, s15 */
/* @0x1c96fc b 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1c9700 vpop {d8} */
/* @0x1c9704 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c9708 ldr r0, [r4, #0x8c] */
/* @0x1c970c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1c9710 vldr s15, [r4, #152] */
/* @0x1c9714 vldr s17, [r0, #28] */
/* @0x1c9718 vcvt.f32.s32 s17, s17 */
/* @0x1c971c ldr r0, [r4, #0x8c] */
/* @0x1c9720 vmul.f32 s17, s17, s15 */
/* @0x1c9724 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1c9728 vldr s15, [r4, #156] */
/* @0x1c972c vldr s16, [r0, #32] */
/* @0x1c9730 vcvt.f32.s32 s16, s16 */
/* @0x1c9734 vmul.f32 s16, s16, s15 */
/* @0x1c9738 b 0x1c9650 <_Z12Command_WrapP9CInstancebb+0x34> */
/* @0x1c973c vsub.f32 s15, s14, s15 */
/* @0x1c9740 mov r0, r4 */
/* @0x1c9744 ldr r2, [r4, #0xb8] */
/* @0x1c9748 vsub.f32 s15, s15, s17 */
/* @0x1c974c vmov r1, s15 */
/* @0x1c9750 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1c9754 b 0x1c9698 <_Z12Command_WrapP9CInstancebb+0x7c> */
/* @0x1c9758 vldr s14, [r4, #184] */
/* @0x1c975c vcmpe.f32 s14, #0 */
/* @0x1c9760 vmrs APSR_nzcv, fpscr */
/* @0x1c9764 bpl 0x1c96b0 <_Z12Command_WrapP9CInstancebb+0x94> */
/* @0x1c9768 ldr r3, [pc, #0x78] */
/* @0x1c976c mov r0, r4 */
/* @0x1c9770 ldr r1, [r4, #0xb4] */
/* @0x1c9774 ldr r3, [r5, r3] */
/* @0x1c9778 ldr r3, [r3] */
/* @0x1c977c vldr s15, [r3, #20] */
/* @0x1c9780 vcvt.f32.s32 s15, s15 */
/* @0x1c9784 vadd.f32 s14, s14, s15 */
/* @0x1c9788 vadd.f32 s14, s14, s16 */
/* @0x1c978c vmov r2, s14 */
/* @0x1c9790 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1c9794 vldr s15, [r4, #228] */
/* @0x1c9798 b 0x1c96b0 <_Z12Command_WrapP9CInstancebb+0x94> */
/* @0x1c979c vldr s14, [r4, #180] */
/* @0x1c97a0 vcmpe.f32 s14, #0 */
/* @0x1c97a4 vmrs APSR_nzcv, fpscr */
/* @0x1c97a8 bpl 0x1c9668 <_Z12Command_WrapP9CInstancebb+0x4c> */
/* @0x1c97ac ldr r3, [pc, #0x34] */
/* @0x1c97b0 mov r0, r4 */
/* @0x1c97b4 ldr r2, [r4, #0xb8] */
/* @0x1c97b8 ldr r3, [r5, r3] */
/* @0x1c97bc ldr r3, [r3] */
/* @0x1c97c0 vldr s15, [r3, #16] */
/* @0x1c97c4 vcvt.f32.s32 s15, s15 */
/* @0x1c97c8 vadd.f32 s14, s14, s15 */
/* @0x1c97cc vadd.f32 s14, s14, s17 */
/* @0x1c97d0 vmov r1, s14 */
/* @0x1c97d4 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1c97d8 vldr s15, [r4, #224] */
/* @0x1c97dc b 0x1c9668 <_Z12Command_WrapP9CInstancebb+0x4c> */
/* @0x1c97e0 andeq r0, r0, r0 */
/* @0x1c97e4 eoreq r8, r2, r4, lsl r6 */
/* @0x1c97e8 .word 0xffffbcd8 */

/* ── FUNC 0x1c97ec · Command_MoveTowards(CInstance*, float, float, float) · size=80 · insn=20 */
/* @0x1c97ec vmov s14, r1 */
/* @0x1c97f0 vldr s15, [r0, #180] */
/* @0x1c97f4 push {r3, r4, r5, lr} */
/* @0x1c97f8 vpush {d8} */
/* @0x1c97fc vsub.f32 s14, s14, s15 */
/* @0x1c9800 vmov s16, r2 */
/* @0x1c9804 mov r4, r0 */
/* @0x1c9808 mov r5, r3 */
/* @0x1c980c vmov r1, s14 */
/* @0x1c9810 bl 0x1930f4 <_ZN9CInstance9SetHspeedEf> */
/* @0x1c9814 vldr s15, [r4, #184] */
/* @0x1c9818 vsub.f32 s15, s16, s15 */
/* @0x1c981c mov r0, r4 */
/* @0x1c9820 vmov r1, s15 */
/* @0x1c9824 bl 0x193114 <_ZN9CInstance9SetVspeedEf> */
/* @0x1c9828 vpop {d8} */
/* @0x1c982c mov r0, r4 */
/* @0x1c9830 mov r1, r5 */
/* @0x1c9834 pop {r3, r4, r5, lr} */
/* @0x1c9838 b 0x1930d4 <_ZN9CInstance8SetSpeedEf> */

/* ── FUNC 0x1c983c · Command_Create(int, float, float) · size=152 · insn=38 */
/* @0x1c983c push {r3, r4, r5, r6, r7, lr} */
/* @0x1c9840 mov r6, r1 */
/* @0x1c9844 mov r4, r0 */
/* @0x1c9848 mov r5, r2 */
/* @0x1c984c bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1c9850 subs r7, r0, #0 */
/* @0x1c9854 beq 0x1c98ac <_Z14Command_Createiff+0x70> */
/* @0x1c9858 ldr r12, [pc, #0x6c] */
/* @0x1c985c mov r3, r4 */
/* @0x1c9860 mov r1, r6 */
/* @0x1c9864 mov r2, r5 */
/* @0x1c9868 ldr r12, [pc, r12] */
/* @0x1c986c ldr r0, [r12] */
/* @0x1c9870 bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi> */
/* @0x1c9874 mov r2, #14 */
/* @0x1c9878 mov r3, #0 */
/* @0x1c987c mov r1, r0 */
/* @0x1c9880 mov r4, r0 */
/* @0x1c9884 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9888 mov r2, #0 */
/* @0x1c988c mov r0, r4 */
/* @0x1c9890 mov r3, r2 */
/* @0x1c9894 mov r1, r4 */
/* @0x1c9898 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c989c mov r3, #1 */
/* @0x1c98a0 mov r0, r4 */
/* @0x1c98a4 strb r3, [r4, #0x6c] */
/* @0x1c98a8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c98ac ldr r0, [pc, #0x1c] */
/* @0x1c98b0 mov r1, r4 */
/* @0x1c98b4 add r0, pc, r0 */
/* @0x1c98b8 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c98bc mov r1, r7 */
/* @0x1c98c0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c98c4 mov r0, r7 */
/* @0x1c98c8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c98cc eoreq r4, r2, r0, asr #1 */
/* @0x1c98d0 ldrsbeq r7, [r8], -r0 */

/* ── FUNC 0x1c98d4 · Command_Create_Depth(int, float, float, int) · size=172 · insn=43 */
/* @0x1c98d4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c98d8 sub sp, sp, #8 */
/* @0x1c98dc mov r6, r1 */
/* @0x1c98e0 mov r7, r3 */
/* @0x1c98e4 mov r5, r2 */
/* @0x1c98e8 mov r4, r0 */
/* @0x1c98ec bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1c98f0 subs r8, r0, #0 */
/* @0x1c98f4 beq 0x1c9954 <_Z20Command_Create_Depthiffi+0x80> */
/* @0x1c98f8 ldr r12, [pc, #0x78] */
/* @0x1c98fc mov r3, r7 */
/* @0x1c9900 mov r1, r6 */
/* @0x1c9904 mov r2, r5 */
/* @0x1c9908 ldr r12, [pc, r12] */
/* @0x1c990c ldr r0, [r12] */
/* @0x1c9910 str r4, [sp] */
/* @0x1c9914 bl 0x1ab2e4 <_ZN5CRoom11AddInstanceEffii> */
/* @0x1c9918 mov r2, #14 */
/* @0x1c991c mov r3, #0 */
/* @0x1c9920 mov r1, r0 */
/* @0x1c9924 mov r4, r0 */
/* @0x1c9928 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c992c mov r2, #0 */
/* @0x1c9930 mov r0, r4 */
/* @0x1c9934 mov r3, r2 */
/* @0x1c9938 mov r1, r4 */
/* @0x1c993c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9940 mov r0, r4 */
/* @0x1c9944 mov r3, #1 */
/* @0x1c9948 strb r3, [r4, #0x6c] */
/* @0x1c994c add sp, sp, #8 */
/* @0x1c9950 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c9954 ldr r0, [pc, #0x20] */
/* @0x1c9958 mov r1, r4 */
/* @0x1c995c add r0, pc, r0 */
/* @0x1c9960 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9964 mov r1, r8 */
/* @0x1c9968 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c996c mov r0, r8 */
/* @0x1c9970 add sp, sp, #8 */
/* @0x1c9974 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c9978 eoreq r4, r2, r0, lsr #32 */
/* @0x1c997c andseq r7, r8, r8, lsr #4 */

/* ── FUNC 0x1c9980 · Command_Create_Layer(int, float, float, int) · size=244 · insn=61 */
/* @0x1c9980 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c9984 sub sp, sp, #16 */
/* @0x1c9988 mov r8, r1 */
/* @0x1c998c mov r6, r3 */
/* @0x1c9990 mov r7, r2 */
/* @0x1c9994 mov r5, r0 */
/* @0x1c9998 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1c999c subs r4, r0, #0 */
/* @0x1c99a0 beq 0x1c9a10 <_Z20Command_Create_Layeriffi+0x90> */
/* @0x1c99a4 ldr r4, [pc, #0xb8] */
/* @0x1c99a8 mov r1, r6 */
/* @0x1c99ac ldr r4, [pc, r4] */
/* @0x1c99b0 ldr r0, [r4] */
/* @0x1c99b4 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c99b8 subs r3, r0, #0 */
/* @0x1c99bc beq 0x1c9a34 <_Z20Command_Create_Layeriffi+0xb4> */
/* @0x1c99c0 ldr r0, [r4] */
/* @0x1c99c4 mov r1, r8 */
/* @0x1c99c8 mov r2, r7 */
/* @0x1c99cc str r5, [sp] */
/* @0x1c99d0 bl 0x1ab494 <_ZN5CRoom11AddInstanceEffP6CLayeri> */
/* @0x1c99d4 mov r2, #14 */
/* @0x1c99d8 mov r3, #0 */
/* @0x1c99dc mov r1, r0 */
/* @0x1c99e0 mov r4, r0 */
/* @0x1c99e4 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c99e8 mov r2, #0 */
/* @0x1c99ec mov r0, r4 */
/* @0x1c99f0 mov r3, r2 */
/* @0x1c99f4 mov r1, r4 */
/* @0x1c99f8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c99fc mov r0, r4 */
/* @0x1c9a00 mov r3, #1 */
/* @0x1c9a04 strb r3, [r4, #0x6c] */
/* @0x1c9a08 add sp, sp, #16 */
/* @0x1c9a0c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c9a10 ldr r0, [pc, #0x50] */
/* @0x1c9a14 mov r1, r5 */
/* @0x1c9a18 add r0, pc, r0 */
/* @0x1c9a1c bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9a20 mov r1, r4 */
/* @0x1c9a24 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9a28 mov r0, r4 */
/* @0x1c9a2c add sp, sp, #16 */
/* @0x1c9a30 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c9a34 ldr r2, [pc, #0x30] */
/* @0x1c9a38 ldr r1, [pc, #0x30] */
/* @0x1c9a3c ldr r2, [pc, r2] */
/* @0x1c9a40 add r1, pc, r1 */
/* @0x1c9a44 ldr r0, [r2] */
/* @0x1c9a48 ldr r2, [r0] */
/* @0x1c9a4c ldr r2, [r2, #0xc] */
/* @0x1c9a50 str r3, [sp, #0xc] */
/* @0x1c9a54 blx r2 */
/* @0x1c9a58 ldr r3, [sp, #0xc] */
/* @0x1c9a5c mov r0, r3 */
/* @0x1c9a60 b 0x1c9a08 <_Z20Command_Create_Layeriffi+0x88> */
/* @0x1c9a64 eoreq r3, r2, r12, ror pc */
/* @0x1c9a68 andseq r7, r8, r12, ror #2 */
/* @0x1c9a6c .word 0x00223cd8 */
/* @0x1c9a70 andseq r7, r8, r0, ror r1 */

/* ── FUNC 0x1c9a74 · Command_Create_Layer(int, float, float, char const*) · size=224 · insn=56 */
/* @0x1c9a74 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c9a78 sub sp, sp, #16 */
/* @0x1c9a7c mov r8, r1 */
/* @0x1c9a80 mov r6, r3 */
/* @0x1c9a84 mov r7, r2 */
/* @0x1c9a88 mov r5, r0 */
/* @0x1c9a8c bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1c9a90 subs r4, r0, #0 */
/* @0x1c9a94 beq 0x1c9b04 <_Z20Command_Create_LayeriffPKc+0x90> */
/* @0x1c9a98 ldr r4, [pc, #0xa8] */
/* @0x1c9a9c mov r1, r6 */
/* @0x1c9aa0 ldr r4, [pc, r4] */
/* @0x1c9aa4 ldr r0, [r4] */
/* @0x1c9aa8 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c9aac subs r3, r0, #0 */
/* @0x1c9ab0 beq 0x1c9b28 <_Z20Command_Create_LayeriffPKc+0xb4> */
/* @0x1c9ab4 ldr r0, [r4] */
/* @0x1c9ab8 mov r1, r8 */
/* @0x1c9abc mov r2, r7 */
/* @0x1c9ac0 str r5, [sp] */
/* @0x1c9ac4 bl 0x1ab494 <_ZN5CRoom11AddInstanceEffP6CLayeri> */
/* @0x1c9ac8 mov r2, #14 */
/* @0x1c9acc mov r3, #0 */
/* @0x1c9ad0 mov r1, r0 */
/* @0x1c9ad4 mov r4, r0 */
/* @0x1c9ad8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9adc mov r2, #0 */
/* @0x1c9ae0 mov r0, r4 */
/* @0x1c9ae4 mov r3, r2 */
/* @0x1c9ae8 mov r1, r4 */
/* @0x1c9aec bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9af0 mov r0, r4 */
/* @0x1c9af4 mov r3, #1 */
/* @0x1c9af8 strb r3, [r4, #0x6c] */
/* @0x1c9afc add sp, sp, #16 */
/* @0x1c9b00 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c9b04 ldr r0, [pc, #0x40] */
/* @0x1c9b08 mov r1, r5 */
/* @0x1c9b0c add r0, pc, r0 */
/* @0x1c9b10 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9b14 mov r1, r4 */
/* @0x1c9b18 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9b1c mov r0, r4 */
/* @0x1c9b20 add sp, sp, #16 */
/* @0x1c9b24 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c9b28 ldr r0, [pc, #0x20] */
/* @0x1c9b2c mov r1, r6 */
/* @0x1c9b30 str r3, [sp, #0xc] */
/* @0x1c9b34 add r0, pc, r0 */
/* @0x1c9b38 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x1c9b3c ldr r3, [sp, #0xc] */
/* @0x1c9b40 mov r0, r3 */
/* @0x1c9b44 b 0x1c9afc <_Z20Command_Create_LayeriffPKc+0x88> */
/* @0x1c9b48 eoreq r3, r2, r8, lsl #29 */
/* @0x1c9b4c andseq r7, r8, r8, ror r0 */
/* @0x1c9b50 mulseq r8, r12, r0 */

/* ── FUNC 0x1c9b54 · Command_Destroy(CInstance*) · size=96 · insn=24 */
/* @0x1c9b54 push {r4, r5, r6, lr} */
/* @0x1c9b58 mov r4, r0 */
/* @0x1c9b5c ldrb r5, [r0, #0x6a] */
/* @0x1c9b60 cmp r5, #0 */
/* @0x1c9b64 popne {r4, r5, r6, pc} */
/* @0x1c9b68 mov r6, #1 */
/* @0x1c9b6c mov r1, r0 */
/* @0x1c9b70 strb r6, [r0, #0x6a] */
/* @0x1c9b74 mov r2, r6 */
/* @0x1c9b78 mov r3, r5 */
/* @0x1c9b7c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9b80 mov r3, r5 */
/* @0x1c9b84 mov r2, #12 */
/* @0x1c9b88 mov r0, r4 */
/* @0x1c9b8c mov r1, r4 */
/* @0x1c9b90 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9b94 ldr r3, [pc, #0x14] */
/* @0x1c9b98 strb r6, [r4, #0x68] */
/* @0x1c9b9c ldr r3, [pc, r3] */
/* @0x1c9ba0 ldr r2, [r3] */
/* @0x1c9ba4 add r2, r2, r6 */
/* @0x1c9ba8 str r2, [r3] */
/* @0x1c9bac pop {r4, r5, r6, pc} */
/* @0x1c9bb0 eoreq r4, r2, r8, lsl r5 */

/* ── FUNC 0x1c9bb4 · Command_Change(CInstance*, int, bool) · size=212 · insn=53 */
/* @0x1c9bb4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c9bb8 mov r4, r0 */
/* @0x1c9bbc mov r0, r1 */
/* @0x1c9bc0 mov r5, r1 */
/* @0x1c9bc4 mov r6, r2 */
/* @0x1c9bc8 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1c9bcc subs r7, r0, #0 */
/* @0x1c9bd0 beq 0x1c9c3c <_Z14Command_ChangeP9CInstanceib+0x88> */
/* @0x1c9bd4 ldr r3, [r4, #0x7c] */
/* @0x1c9bd8 cmp r5, r3 */
/* @0x1c9bdc popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1c9be0 cmp r6, #0 */
/* @0x1c9be4 beq 0x1c9c2c <_Z14Command_ChangeP9CInstanceib+0x78> */
/* @0x1c9be8 ldrb r6, [r4, #0x6a] */
/* @0x1c9bec cmp r6, #0 */
/* @0x1c9bf0 beq 0x1c9c58 <_Z14Command_ChangeP9CInstanceib+0xa4> */
/* @0x1c9bf4 mov r1, r5 */
/* @0x1c9bf8 mov r0, r4 */
/* @0x1c9bfc bl 0x193368 <_ZN9CInstance17ChangeObjectIndexEi> */
/* @0x1c9c00 mov r0, r4 */
/* @0x1c9c04 mov r1, r4 */
/* @0x1c9c08 mov r2, #14 */
/* @0x1c9c0c mov r3, #0 */
/* @0x1c9c10 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9c14 mov r2, #0 */
/* @0x1c9c18 mov r0, r4 */
/* @0x1c9c1c mov r1, r4 */
/* @0x1c9c20 mov r3, r2 */
/* @0x1c9c24 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c9c28 b 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9c2c mov r0, r4 */
/* @0x1c9c30 mov r1, r5 */
/* @0x1c9c34 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c9c38 b 0x193368 <_ZN9CInstance17ChangeObjectIndexEi> */
/* @0x1c9c3c ldr r0, [pc, #0x40] */
/* @0x1c9c40 mov r1, r5 */
/* @0x1c9c44 add r0, pc, r0 */
/* @0x1c9c48 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9c4c mov r1, r7 */
/* @0x1c9c50 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c9c54 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9c58 mov r0, r4 */
/* @0x1c9c5c mov r1, r4 */
/* @0x1c9c60 mov r3, r6 */
/* @0x1c9c64 mov r2, #1 */
/* @0x1c9c68 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9c6c mov r0, r4 */
/* @0x1c9c70 mov r1, r4 */
/* @0x1c9c74 mov r3, r6 */
/* @0x1c9c78 mov r2, #12 */
/* @0x1c9c7c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9c80 b 0x1c9bf4 <_Z14Command_ChangeP9CInstanceib+0x40> */
/* @0x1c9c84 andseq r6, r8, r12, asr #31 */

/* ── FUNC 0x1c9c88 · Command_DestroyAt(float, float) · size=112 · insn=28 */
/* @0x1c9c88 push {r3, r4, r5, r6, r7, lr} */
/* @0x1c9c8c mov r7, r0 */
/* @0x1c9c90 ldr r3, [pc, #0x5c] */
/* @0x1c9c94 mov r6, r1 */
/* @0x1c9c98 ldr r3, [pc, r3] */
/* @0x1c9c9c ldr r3, [r3] */
/* @0x1c9ca0 ldr r4, [r3, #0x80] */
/* @0x1c9ca4 cmp r4, #0 */
/* @0x1c9ca8 bne 0x1c9cbc <_Z17Command_DestroyAtff+0x34> */
/* @0x1c9cac pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c9cb0 cmp r5, #0 */
/* @0x1c9cb4 mov r4, r5 */
/* @0x1c9cb8 beq 0x1c9cf0 <_Z17Command_DestroyAtff+0x68> */
/* @0x1c9cbc mov r0, r4 */
/* @0x1c9cc0 mov r1, r7 */
/* @0x1c9cc4 mov r2, r6 */
/* @0x1c9cc8 mov r3, #1 */
/* @0x1c9ccc ldr r5, [r4, #0x178] */
/* @0x1c9cd0 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c9cd4 cmp r0, #0 */
/* @0x1c9cd8 beq 0x1c9cb0 <_Z17Command_DestroyAtff+0x28> */
/* @0x1c9cdc mov r0, r4 */
/* @0x1c9ce0 mov r4, r5 */
/* @0x1c9ce4 bl 0x1c9b54 <_Z15Command_DestroyP9CInstance> */
/* @0x1c9ce8 cmp r5, #0 */
/* @0x1c9cec bne 0x1c9cbc <_Z17Command_DestroyAtff+0x34> */
/* @0x1c9cf0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c9cf4 mlaeq r2, r0, r12, r3 */

/* ── FUNC 0x1c9cf8 · Command_ChangeAt(float, float, int, bool) · size=176 · insn=44 */
/* @0x1c9cf8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1c9cfc mov r6, r0 */
/* @0x1c9d00 mov r0, r2 */
/* @0x1c9d04 mov r8, r2 */
/* @0x1c9d08 mov r7, r1 */
/* @0x1c9d0c mov r9, r3 */
/* @0x1c9d10 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1c9d14 subs r4, r0, #0 */
/* @0x1c9d18 beq 0x1c9d84 <_Z16Command_ChangeAtffib+0x8c> */
/* @0x1c9d1c ldr r3, [pc, #0x7c] */
/* @0x1c9d20 ldr r3, [pc, r3] */
/* @0x1c9d24 ldr r3, [r3] */
/* @0x1c9d28 ldr r4, [r3, #0x80] */
/* @0x1c9d2c cmp r4, #0 */
/* @0x1c9d30 bne 0x1c9d44 <_Z16Command_ChangeAtffib+0x4c> */
/* @0x1c9d34 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1c9d38 cmp r5, #0 */
/* @0x1c9d3c mov r4, r5 */
/* @0x1c9d40 beq 0x1c9d80 <_Z16Command_ChangeAtffib+0x88> */
/* @0x1c9d44 mov r0, r4 */
/* @0x1c9d48 mov r1, r6 */
/* @0x1c9d4c mov r2, r7 */
/* @0x1c9d50 mov r3, #1 */
/* @0x1c9d54 ldr r5, [r4, #0x178] */
/* @0x1c9d58 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c9d5c cmp r0, #0 */
/* @0x1c9d60 beq 0x1c9d38 <_Z16Command_ChangeAtffib+0x40> */
/* @0x1c9d64 mov r0, r4 */
/* @0x1c9d68 mov r1, r8 */
/* @0x1c9d6c mov r2, r9 */
/* @0x1c9d70 mov r4, r5 */
/* @0x1c9d74 bl 0x1c9bb4 <_Z14Command_ChangeP9CInstanceib> */
/* @0x1c9d78 cmp r5, #0 */
/* @0x1c9d7c bne 0x1c9d44 <_Z16Command_ChangeAtffib+0x4c> */
/* @0x1c9d80 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1c9d84 ldr r0, [pc, #0x18] */
/* @0x1c9d88 mov r1, r8 */
/* @0x1c9d8c add r0, pc, r0 */
/* @0x1c9d90 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9d94 mov r1, r4 */
/* @0x1c9d98 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1c9d9c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9da0 eoreq r3, r2, r8, lsl #24 */
/* @0x1c9da4 andseq r6, r8, r4, lsl #29 */

/* ── FUNC 0x1c9da8 · Command_ObjectAt(float, float, int) · size=20 · insn=5 */
/* @0x1c9da8 push {r3, lr} */
/* @0x1c9dac bl 0x1c90cc <_Z24Command_InstancePositionffi> */
/* @0x1c9db0 adds r0, r0, #0 */
/* @0x1c9db4 movne r0, #1 */
/* @0x1c9db8 pop {r3, pc} */

/* ── FUNC 0x1c9dbc · Command_SetSprite(CInstance*, int) · size=76 · insn=19 */
/* @0x1c9dbc push {r4, r5, r6, lr} */
/* @0x1c9dc0 mov r5, r0 */
/* @0x1c9dc4 mov r0, r1 */
/* @0x1c9dc8 mov r4, r1 */
/* @0x1c9dcc bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1c9dd0 subs r6, r0, #0 */
/* @0x1c9dd4 beq 0x1c9de8 <_Z17Command_SetSpriteP9CInstancei+0x2c> */
/* @0x1c9dd8 mov r0, r5 */
/* @0x1c9ddc mov r1, r4 */
/* @0x1c9de0 pop {r4, r5, r6, lr} */
/* @0x1c9de4 b 0x1931c0 <_ZN9CInstance14SetSpriteIndexEi> */
/* @0x1c9de8 ldr r0, [pc, #0x14] */
/* @0x1c9dec mov r1, r4 */
/* @0x1c9df0 add r0, pc, r0 */
/* @0x1c9df4 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9df8 mov r1, r6 */
/* @0x1c9dfc pop {r4, r5, r6, lr} */
/* @0x1c9e00 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9e04 andseq r6, r8, r12, asr #28 */

/* ── FUNC 0x1c9e08 · Command_GotoRoom(int, int) · size=96 · insn=24 */
/* @0x1c9e08 push {r4, lr} */
/* @0x1c9e0c mov r2, #0 */
/* @0x1c9e10 ldr r4, [pc, #0x44] */
/* @0x1c9e14 ldr r3, [pc, #0x44] */
/* @0x1c9e18 ldr r4, [pc, r4] */
/* @0x1c9e1c ldr r3, [pc, r3] */
/* @0x1c9e20 str r0, [r4] */
/* @0x1c9e24 str r2, [r3] */
/* @0x1c9e28 bl 0x1b52f8 <_Z11Room_Existsi> */
/* @0x1c9e2c cmp r0, #0 */
/* @0x1c9e30 popne {r4, pc} */
/* @0x1c9e34 ldr r0, [pc, #0x28] */
/* @0x1c9e38 ldr r1, [r4] */
/* @0x1c9e3c add r0, pc, r0 */
/* @0x1c9e40 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9e44 mov r1, #1 */
/* @0x1c9e48 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9e4c movw r3, #0xfe70 */
/* @0x1c9e50 movt r3, #0xffff */
/* @0x1c9e54 str r3, [r4] */
/* @0x1c9e58 pop {r4, pc} */
/* @0x1c9e5c eoreq r3, r2, r12, lsl #31 */
/* @0x1c9e60 eoreq r4, r2, r12, lsl #5 */
/* @0x1c9e64 andseq r6, r8, r12, lsr #28 */

/* ── FUNC 0x1c9e68 · Command_PreviousRoom(int) · size=104 · insn=26 */
/* @0x1c9e68 push {r4, lr} */
/* @0x1c9e6c mov r4, r0 */
/* @0x1c9e70 bl 0x1b5d08 <_Z10Room_Firstv> */
/* @0x1c9e74 ldr r3, [pc, #0x48] */
/* @0x1c9e78 ldr r3, [pc, r3] */
/* @0x1c9e7c ldr r3, [r3] */
/* @0x1c9e80 cmp r0, r3 */
/* @0x1c9e84 beq 0x1c9e9c <_Z20Command_PreviousRoomi+0x34> */
/* @0x1c9e88 mov r0, r3 */
/* @0x1c9e8c bl 0x1b5d40 <_Z13Room_Previousi> */
/* @0x1c9e90 mov r1, r4 */
/* @0x1c9e94 pop {r4, lr} */
/* @0x1c9e98 b 0x1c9e08 <_Z16Command_GotoRoomii> */
/* @0x1c9e9c ldr r0, [pc, #0x24] */
/* @0x1c9ea0 mov r1, #1 */
/* @0x1c9ea4 add r0, pc, r0 */
/* @0x1c9ea8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9eac ldr r3, [pc, #0x18] */
/* @0x1c9eb0 movw r2, #0xfe70 */
/* @0x1c9eb4 movt r2, #0xffff */
/* @0x1c9eb8 ldr r3, [pc, r3] */
/* @0x1c9ebc str r2, [r3] */
/* @0x1c9ec0 pop {r4, pc} */
/* @0x1c9ec4 eoreq r5, r2, r12, asr r5 */
/* @0x1c9ec8 andseq r6, r8, r0, ror #27 */
/* @0x1c9ecc eoreq r3, r2, r12, ror #29 */

/* ── FUNC 0x1c9ed0 · Command_NextRoom(int) · size=104 · insn=26 */
/* @0x1c9ed0 push {r4, lr} */
/* @0x1c9ed4 mov r4, r0 */
/* @0x1c9ed8 bl 0x1b5d20 <_Z9Room_Lastv> */
/* @0x1c9edc ldr r3, [pc, #0x48] */
/* @0x1c9ee0 ldr r3, [pc, r3] */
/* @0x1c9ee4 ldr r3, [r3] */
/* @0x1c9ee8 cmp r0, r3 */
/* @0x1c9eec beq 0x1c9f04 <_Z16Command_NextRoomi+0x34> */
/* @0x1c9ef0 mov r0, r3 */
/* @0x1c9ef4 bl 0x1b5da4 <_Z9Room_Nexti> */
/* @0x1c9ef8 mov r1, r4 */
/* @0x1c9efc pop {r4, lr} */
/* @0x1c9f00 b 0x1c9e08 <_Z16Command_GotoRoomii> */
/* @0x1c9f04 ldr r0, [pc, #0x24] */
/* @0x1c9f08 mov r1, #1 */
/* @0x1c9f0c add r0, pc, r0 */
/* @0x1c9f10 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9f14 ldr r3, [pc, #0x18] */
/* @0x1c9f18 movw r2, #0xfe70 */
/* @0x1c9f1c movt r2, #0xffff */
/* @0x1c9f20 ldr r3, [pc, r3] */
/* @0x1c9f24 str r2, [r3] */
/* @0x1c9f28 pop {r4, pc} */
/* @0x1c9f2c .word 0x002254f4 */
/* @0x1c9f30 andseq r6, r8, r8, lsr #27 */
/* @0x1c9f34 eoreq r3, r2, r4, lsl #29 */

/* ── FUNC 0x1c9f38 · Command_CurrentRoom(int) · size=24 · insn=6 */
/* @0x1c9f38 ldr r3, [pc, #0xc] */
/* @0x1c9f3c mov r1, r0 */
/* @0x1c9f40 ldr r3, [pc, r3] */
/* @0x1c9f44 ldr r0, [r3] */
/* @0x1c9f48 b 0x1c9e08 <_Z16Command_GotoRoomii> */
/* @0x1c9f4c mlaeq r2, r4, r4, r5 */

/* ── FUNC 0x1c9f50 · Command_EndGame() · size=4 · insn=1 */
/* @0x1c9f50 bx lr */

/* ── FUNC 0x1c9f54 · Command_RestartGame() · size=88 · insn=22 */
/* @0x1c9f54 ldr r2, [pc, #0x40] */
/* @0x1c9f58 mvn r1, #199 */
/* @0x1c9f5c ldr r3, [pc, #0x3c] */
/* @0x1c9f60 ldr r2, [pc, r2] */
/* @0x1c9f64 ldr r3, [pc, r3] */
/* @0x1c9f68 ldrb r2, [r2] */
/* @0x1c9f6c str r1, [r3] */
/* @0x1c9f70 cmp r2, #0 */
/* @0x1c9f74 bxeq lr */
/* @0x1c9f78 ldr r3, [pc, #0x24] */
/* @0x1c9f7c ldr r3, [pc, r3] */
/* @0x1c9f80 ldr r3, [r3] */
/* @0x1c9f84 cmp r3, #0 */
/* @0x1c9f88 bxne lr */
/* @0x1c9f8c ldr r1, [pc, #0x14] */
/* @0x1c9f90 mov r0, #2 */
/* @0x1c9f94 add r1, pc, r1 */
/* @0x1c9f98 b 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x1c9f9c eoreq r3, r2, r4, asr #19 */
/* @0x1c9fa0 eoreq r3, r2, r0, asr #28 */
/* @0x1c9fa4 eoreq r4, r2, r4, lsr #9 */
/* @0x1c9fa8 andseq r6, r8, r12, asr #26 */

/* ── FUNC 0x1c9fac · Command_ScreenShot(char const*) · size=148 · insn=37 */
/* @0x1c9fac push {r4, r5, lr} */
/* @0x1c9fb0 subs r4, r0, #0 */
/* @0x1c9fb4 sub sp, sp, #20 */
/* @0x1c9fb8 beq 0x1ca024 <_Z18Command_ScreenShotPKc+0x78> */
/* @0x1c9fbc ldrb r3, [r4] */
/* @0x1c9fc0 cmp r3, #0 */
/* @0x1c9fc4 beq 0x1ca024 <_Z18Command_ScreenShotPKc+0x78> */
/* @0x1c9fc8 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv> */
/* @0x1c9fcc str r0, [sp, #0x8] */
/* @0x1c9fd0 bl 0x17999c <_Z27GR_Window_Get_Region_Heightv> */
/* @0x1c9fd4 add r12, sp, #16 */
/* @0x1c9fd8 mov r2, #0 */
/* @0x1c9fdc add lr, sp, #12 */
/* @0x1c9fe0 mov r3, r2 */
/* @0x1c9fe4 mov r1, r0 */
/* @0x1c9fe8 str r0, [sp, #0xc] */
/* @0x1c9fec ldr r0, [r12, #-0x8]! */
/* @0x1c9ff0 stm sp, {r12, lr} */
/* @0x1c9ff4 bl 0x17e0dc <_ZN8Graphics14GrabScreenRectEiiiiPiS0_> */
/* @0x1c9ff8 subs r5, r0, #0 */
/* @0x1c9ffc beq 0x1ca01c <_Z18Command_ScreenShotPKc+0x70> */
/* @0x1ca000 mov r0, r4 */
/* @0x1ca004 mov r1, r5 */
/* @0x1ca008 ldr r2, [sp, #0x8] */
/* @0x1ca00c ldr r3, [sp, #0xc] */
/* @0x1ca010 bl 0x16cc8c <_Z10WritePNG32PcPvii> */
/* @0x1ca014 mov r0, r5 */
/* @0x1ca018 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ca01c add sp, sp, #20 */
/* @0x1ca020 pop {r4, r5, pc} */
/* @0x1ca024 ldr r0, [pc, #0x10] */
/* @0x1ca028 mov r1, #0 */
/* @0x1ca02c add r0, pc, r0 */
/* @0x1ca030 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1ca034 add sp, sp, #20 */
/* @0x1ca038 pop {r4, r5, pc} */
/* @0x1ca03c andseq r6, r8, r4, asr #25 */

/* ── FUNC 0x1ca040 · Command_Unzip(char const*, char const*, int, int, char*) · size=784 · insn=196 */
/* @0x1ca040 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ca044 sub sp, sp, #1120 */
/* @0x1ca048 sub sp, sp, #4 */
/* @0x1ca04c ldr r12, [pc, #0x2d4] */
/* @0x1ca050 mov r4, r0 */
/* @0x1ca054 mov r0, #64 */
/* @0x1ca058 add r12, pc, r12 */
/* @0x1ca05c str r12, [sp, #0x2c] */
/* @0x1ca060 ldr lr, [sp, #0x2c] */
/* @0x1ca064 mov r6, #0 */
/* @0x1ca068 ldr r12, [pc, #0x2bc] */
/* @0x1ca06c str r1, [sp, #0xc] */
/* @0x1ca070 str r2, [sp, #0x20] */
/* @0x1ca074 str r3, [sp, #0x18] */
/* @0x1ca078 ldr r12, [lr, r12] */
/* @0x1ca07c ldr r10, [sp, #0x488] */
/* @0x1ca080 ldr r3, [r12] */
/* @0x1ca084 str r12, [sp, #0x30] */
/* @0x1ca088 str r3, [sp, #0x45c] */
/* @0x1ca08c bl 0x27c524 <_Znwj> */
/* @0x1ca090 mov r2, #1 */
/* @0x1ca094 mov r1, r6 */
/* @0x1ca098 mov r3, r2 */
/* @0x1ca09c str r0, [sp, #0x28] */
/* @0x1ca0a0 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati> */
/* @0x1ca0a4 ldr lr, [sp, #0x2c] */
/* @0x1ca0a8 mov r1, r4 */
/* @0x1ca0ac ldr r12, [pc, #0x27c] */
/* @0x1ca0b0 mov r2, r6 */
/* @0x1ca0b4 ldr r0, [sp, #0x28] */
/* @0x1ca0b8 mvn r3, #0 */
/* @0x1ca0bc ldr r12, [lr, r12] */
/* @0x1ca0c0 add r12, r12, #8 */
/* @0x1ca0c4 str r12, [r0] */
/* @0x1ca0c8 str r6, [sp] */
/* @0x1ca0cc bl 0xcd91c <_ZN7IBuffer4LoadEPKciii> */
/* @0x1ca0d0 ldr r0, [sp, #0x28] */
/* @0x1ca0d4 mov r1, r6 */
/* @0x1ca0d8 mov r2, r6 */
/* @0x1ca0dc blx 0x2a51a0 <zip_open_buff> */
/* @0x1ca0e0 subs r8, r0, #0 */
/* @0x1ca0e4 beq 0x1ca2e0 <_Z13Command_UnzipPKcS0_iiPc+0x2a0> */
/* @0x1ca0e8 blx 0x2a490e <zip_get_num_files> */
/* @0x1ca0ec cmp r0, #0 */
/* @0x1ca0f0 str r0, [sp, #0x1c] */
/* @0x1ca0f4 ble 0x1ca27c <_Z13Command_UnzipPKcS0_iiPc+0x23c> */
/* @0x1ca0f8 ldr r12, [pc, #0x234] */
/* @0x1ca0fc str r10, [sp, #0x8] */
/* @0x1ca100 add r12, pc, r12 */
/* @0x1ca104 str r12, [sp, #0x34] */
/* @0x1ca108 add r12, sp, #64 */
/* @0x1ca10c str r12, [sp, #0x24] */
/* @0x1ca110 ldr r12, [pc, #0x220] */
/* @0x1ca114 add r12, pc, r12 */
/* @0x1ca118 str r12, [sp, #0x38] */
/* @0x1ca11c ldr r12, [pc, #0x218] */
/* @0x1ca120 add r12, pc, r12 */
/* @0x1ca124 str r12, [sp, #0x14] */
/* @0x1ca128 ldr r12, [pc, #0x210] */
/* @0x1ca12c add r12, pc, r12 */
/* @0x1ca130 str r12, [sp, #0x10] */
/* @0x1ca134 ldr r12, [pc, #0x208] */
/* @0x1ca138 add r12, pc, r12 */
/* @0x1ca13c str r12, [sp, #0x3c] */
/* @0x1ca140 b 0x1ca198 <_Z13Command_UnzipPKcS0_iiPc+0x158> */
/* @0x1ca144 mov r1, r7 */
/* @0x1ca148 mov r2, #1 */
/* @0x1ca14c mov r0, r8 */
/* @0x1ca150 blx 0x2a44b8 <zip_fopen> */
/* @0x1ca154 mov r1, r7 */
/* @0x1ca158 mov r2, #1 */
/* @0x1ca15c add r3, sp, #64 */
/* @0x1ca160 mov r5, r0 */
/* @0x1ca164 mov r0, r8 */
/* @0x1ca168 blx 0x2a5670 <zip_stat> */
/* @0x1ca16c ldr r0, [sp, #0x50] */
/* @0x1ca170 cmp r0, #0 */
/* @0x1ca174 bne 0x1ca1d8 <_Z13Command_UnzipPKcS0_iiPc+0x198> */
/* @0x1ca178 ldr r12, [sp, #0x8] */
/* @0x1ca17c add r6, r6, #1 */
/* @0x1ca180 ldr lr, [sp, #0x18] */
/* @0x1ca184 add r12, r12, lr */
/* @0x1ca188 str r12, [sp, #0x8] */
/* @0x1ca18c ldr r12, [sp, #0x1c] */
/* @0x1ca190 cmp r6, r12 */
/* @0x1ca194 beq 0x1ca27c <_Z13Command_UnzipPKcS0_iiPc+0x23c> */
/* @0x1ca198 mov r0, r8 */
/* @0x1ca19c mov r1, r6 */
/* @0x1ca1a0 mov r2, #8 */
/* @0x1ca1a4 blx 0x2a4970 <zip_get_name> */
/* @0x1ca1a8 ldr r12, [sp, #0x20] */
/* @0x1ca1ac cmp r12, r6 */
/* @0x1ca1b0 mov r7, r0 */
/* @0x1ca1b4 ble 0x1ca144 <_Z13Command_UnzipPKcS0_iiPc+0x104> */
/* @0x1ca1b8 ldr r12, [sp, #0x18] */
/* @0x1ca1bc str r0, [sp] */
/* @0x1ca1c0 sub r1, r12, #1 */
/* @0x1ca1c4 ldr r0, [sp, #0x8] */
/* @0x1ca1c8 ldr r2, [sp, #0x34] */
/* @0x1ca1cc ldr r3, [sp, #0xc] */
/* @0x1ca1d0 bl 0xb65c8 <snprintf@plt> */
/* @0x1ca1d4 b 0x1ca144 <_Z13Command_UnzipPKcS0_iiPc+0x104> */
/* @0x1ca1d8 ldr r1, [sp, #0x38] */
/* @0x1ca1dc movw r2, #0x78e */
/* @0x1ca1e0 mov r3, #1 */
/* @0x1ca1e4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ca1e8 ldr r11, [sp, #0x50] */
/* @0x1ca1ec cmp r11, #0 */
/* @0x1ca1f0 mov r9, r0 */
/* @0x1ca1f4 movne r4, r0 */
/* @0x1ca1f8 beq 0x1ca234 <_Z13Command_UnzipPKcS0_iiPc+0x1f4> */
/* @0x1ca1fc mov r0, r5 */
/* @0x1ca200 mov r1, r4 */
/* @0x1ca204 mov r2, r11 */
/* @0x1ca208 blx 0x2a476c <zip_fread> */
/* @0x1ca20c cmp r0, r11 */
/* @0x1ca210 mov r10, r0 */
/* @0x1ca214 beq 0x1ca234 <_Z13Command_UnzipPKcS0_iiPc+0x1f4> */
/* @0x1ca218 ldr r0, [sp, #0x14] */
/* @0x1ca21c bl 0xb6964 <printf@plt> */
/* @0x1ca220 cmp r10, #0 */
/* @0x1ca224 beq 0x1ca234 <_Z13Command_UnzipPKcS0_iiPc+0x1f4> */
/* @0x1ca228 subs r11, r11, r10 */
/* @0x1ca22c add r4, r4, r10 */
/* @0x1ca230 bne 0x1ca1fc <_Z13Command_UnzipPKcS0_iiPc+0x1bc> */
/* @0x1ca234 add r4, sp, #92 */
/* @0x1ca238 mov r0, r5 */
/* @0x1ca23c blx 0x2a4388 <zip_fclose> */
/* @0x1ca240 movw r1, #0x3ff */
/* @0x1ca244 ldr r2, [sp, #0x10] */
/* @0x1ca248 mov r0, r4 */
/* @0x1ca24c ldr r3, [sp, #0xc] */
/* @0x1ca250 str r7, [sp] */
/* @0x1ca254 bl 0xb65c8 <snprintf@plt> */
/* @0x1ca258 mov r0, r4 */
/* @0x1ca25c mov r1, r9 */
/* @0x1ca260 ldr r2, [sp, #0x50] */
/* @0x1ca264 bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i> */
/* @0x1ca268 cmp r0, #0 */
/* @0x1ca26c beq 0x1ca2bc <_Z13Command_UnzipPKcS0_iiPc+0x27c> */
/* @0x1ca270 mov r0, r9 */
/* @0x1ca274 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ca278 b 0x1ca178 <_Z13Command_UnzipPKcS0_iiPc+0x138> */
/* @0x1ca27c mov r0, r8 */
/* @0x1ca280 blx 0x2a31ec <zip_close> */
/* @0x1ca284 ldr r12, [sp, #0x28] */
/* @0x1ca288 ldr r3, [r12] */
/* @0x1ca28c mov r0, r12 */
/* @0x1ca290 ldr r3, [r3, #0x4] */
/* @0x1ca294 blx r3 */
/* @0x1ca298 ldr r0, [sp, #0x1c] */
/* @0x1ca29c ldr r12, [sp, #0x30] */
/* @0x1ca2a0 ldr r2, [sp, #0x45c] */
/* @0x1ca2a4 ldr r3, [r12] */
/* @0x1ca2a8 cmp r2, r3 */
/* @0x1ca2ac bne 0x1ca324 <_Z13Command_UnzipPKcS0_iiPc+0x2e4> */
/* @0x1ca2b0 add sp, sp, #1120 */
/* @0x1ca2b4 add sp, sp, #4 */
/* @0x1ca2b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ca2bc ldr r12, [sp, #0x2c] */
/* @0x1ca2c0 ldr r3, [pc, #0x80] */
/* @0x1ca2c4 ldr r1, [sp, #0x3c] */
/* @0x1ca2c8 ldr r3, [r12, r3] */
/* @0x1ca2cc ldr r0, [r3] */
/* @0x1ca2d0 ldr r3, [r0] */
/* @0x1ca2d4 ldr r3, [r3, #0xc] */
/* @0x1ca2d8 blx r3 */
/* @0x1ca2dc b 0x1ca270 <_Z13Command_UnzipPKcS0_iiPc+0x230> */
/* @0x1ca2e0 ldr r12, [sp, #0x28] */
/* @0x1ca2e4 ldr r3, [r12] */
/* @0x1ca2e8 mov r0, r12 */
/* @0x1ca2ec ldr r3, [r3, #0x4] */
/* @0x1ca2f0 blx r3 */
/* @0x1ca2f4 ldr r12, [sp, #0x2c] */
/* @0x1ca2f8 ldr r3, [pc, #0x48] */
/* @0x1ca2fc mov r2, r4 */
/* @0x1ca300 ldr r1, [pc, #0x44] */
/* @0x1ca304 ldr r3, [r12, r3] */
/* @0x1ca308 add r1, pc, r1 */
/* @0x1ca30c ldr r0, [r3] */
/* @0x1ca310 ldr r3, [r0] */
/* @0x1ca314 ldr r3, [r3, #0xc] */
/* @0x1ca318 blx r3 */
/* @0x1ca31c mov r0, r8 */
/* @0x1ca320 b 0x1ca29c <_Z13Command_UnzipPKcS0_iiPc+0x25c> */
/* @0x1ca324 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1ca328 .word 0x00227bf8 */
/* @0x1ca32c .word 0xffffbd00 */
/* @0x1ca330 .word 0xffffbd60 */
/* @0x1ca334 andseq r6, r8, r8, asr #24 */
/* @0x1ca338 andseq r6, r8, r12, lsr r12 */
/* @0x1ca33c andseq r2, r8, r12, ror #6 */
/* @0x1ca340 andseq r6, r8, r12, lsl r12 */
/* @0x1ca344 andseq r6, r8, r12, asr #24 */
/* @0x1ca348 .word 0xffffbac4 */
/* @0x1ca34c andseq r6, r8, r8, lsl r10 */

/* ── FUNC 0x1ca350 · Command_CollisionRectangle(CInstance*, float, float, float, float, int, bool, bool) · size=904 · insn=226 */
/* @0x1ca350 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1ca354 vpush {d8, d9} */
/* @0x1ca358 sub sp, sp, #72 */
/* @0x1ca35c vldr s19, [sp, #120] */
/* @0x1ca360 add r12, sp, #72 */
/* @0x1ca364 mov r7, r0 */
/* @0x1ca368 ldr r4, [sp, #0x7c] */
/* @0x1ca36c mov r5, #0 */
/* @0x1ca370 vmov s17, r1 */
/* @0x1ca374 str r5, [r12, #-0x3c]! */
/* @0x1ca378 mov r1, r12 */
/* @0x1ca37c vmov s18, r2 */
/* @0x1ca380 mov r0, r4 */
/* @0x1ca384 vmov s16, r3 */
/* @0x1ca388 ldrb r8, [sp, #0x80] */
/* @0x1ca38c ldrb r6, [sp, #0x84] */
/* @0x1ca390 bl 0x1c8df8 <_Z22ShouldUseFastCollisioniPP9CObjectGM> */
/* @0x1ca394 ldr r9, [pc, #0x31c] */
/* @0x1ca398 add r9, pc, r9 */
/* @0x1ca39c cmn r0, #1 */
/* @0x1ca3a0 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca3a4 cmp r0, #1 */
/* @0x1ca3a8 beq 0x1ca578 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x228> */
/* @0x1ca3ac cmn r4, #3 */
/* @0x1ca3b0 beq 0x1ca4ec <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x19c> */
/* @0x1ca3b4 movw r3, #0x869f */
/* @0x1ca3b8 movt r3, #0x1 */
/* @0x1ca3bc cmp r4, r3 */
/* @0x1ca3c0 bgt 0x1ca45c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x10c> */
/* @0x1ca3c4 ldr r3, [sp, #0xc] */
/* @0x1ca3c8 cmp r3, #0 */
/* @0x1ca3cc beq 0x1ca658 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x308> */
/* @0x1ca3d0 ldr r4, [r3, #0xd0] */
/* @0x1ca3d4 cmp r4, #0 */
/* @0x1ca3d8 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca3dc ldr r3, [r4, #0x8] */
/* @0x1ca3e0 cmp r3, #0 */
/* @0x1ca3e4 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca3e8 ldr r5, [r4, #0x8] */
/* @0x1ca3ec ldr r4, [r4] */
/* @0x1ca3f0 cmp r7, r5 */
/* @0x1ca3f4 movne r3, #0 */
/* @0x1ca3f8 andeq r3, r6, #1 */
/* @0x1ca3fc cmp r3, #0 */
/* @0x1ca400 bne 0x1ca3d4 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x84> */
/* @0x1ca404 ldrb r3, [r5, #0x68] */
/* @0x1ca408 cmp r3, #0 */
/* @0x1ca40c bne 0x1ca3d4 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x84> */
/* @0x1ca410 ldrb r3, [r5, #0x69] */
/* @0x1ca414 cmp r3, #0 */
/* @0x1ca418 bne 0x1ca3d4 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x84> */
/* @0x1ca41c vstr s19, [sp] */
/* @0x1ca420 str r8, [sp, #0x4] */
/* @0x1ca424 mov r0, r5 */
/* @0x1ca428 vmov r1, s17 */
/* @0x1ca42c vmov r2, s18 */
/* @0x1ca430 vmov r3, s16 */
/* @0x1ca434 bl 0x1946f4 <_ZN9CInstance19Collision_RectangleEffffb> */
/* @0x1ca438 cmp r0, #0 */
/* @0x1ca43c bne 0x1ca44c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xfc> */
/* @0x1ca440 cmp r4, #0 */
/* @0x1ca444 bne 0x1ca3dc <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x8c> */
/* @0x1ca448 mov r5, #0 */
/* @0x1ca44c mov r0, r5 */
/* @0x1ca450 add sp, sp, #72 */
/* @0x1ca454 vpop {d8, d9} */
/* @0x1ca458 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1ca45c cmp r6, #0 */
/* @0x1ca460 bne 0x1ca568 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x218> */
/* @0x1ca464 ldr r3, [pc, #0x250] */
/* @0x1ca468 ldr r3, [r9, r3] */
/* @0x1ca46c ldr r2, [r3, #0x4] */
/* @0x1ca470 ldr r3, [r3] */
/* @0x1ca474 and r2, r4, r2 */
/* @0x1ca478 ldr r3, [r3, r2, lsl #3] */
/* @0x1ca47c cmp r3, #0 */
/* @0x1ca480 bne 0x1ca494 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x144> */
/* @0x1ca484 b 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca488 ldr r3, [r3, #0x4] */
/* @0x1ca48c cmp r3, #0 */
/* @0x1ca490 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca494 ldr r2, [r3, #0x8] */
/* @0x1ca498 cmp r4, r2 */
/* @0x1ca49c bne 0x1ca488 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x138> */
/* @0x1ca4a0 ldr r5, [r3, #0xc] */
/* @0x1ca4a4 cmp r5, #0 */
/* @0x1ca4a8 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca4ac ldrb r3, [r5, #0x68] */
/* @0x1ca4b0 cmp r3, #0 */
/* @0x1ca4b4 bne 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca4b8 ldrb r3, [r5, #0x69] */
/* @0x1ca4bc cmp r3, #0 */
/* @0x1ca4c0 bne 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca4c4 vstr s19, [sp] */
/* @0x1ca4c8 str r8, [sp, #0x4] */
/* @0x1ca4cc mov r0, r5 */
/* @0x1ca4d0 vmov r1, s17 */
/* @0x1ca4d4 vmov r2, s18 */
/* @0x1ca4d8 vmov r3, s16 */
/* @0x1ca4dc bl 0x1946f4 <_ZN9CInstance19Collision_RectangleEffffb> */
/* @0x1ca4e0 cmp r0, #0 */
/* @0x1ca4e4 bne 0x1ca44c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xfc> */
/* @0x1ca4e8 b 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca4ec ldr r3, [pc, #0x1cc] */
/* @0x1ca4f0 ldr r3, [r9, r3] */
/* @0x1ca4f4 ldr r3, [r3] */
/* @0x1ca4f8 ldr r5, [r3, #0x80] */
/* @0x1ca4fc cmp r5, #0 */
/* @0x1ca500 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca504 cmp r7, r5 */
/* @0x1ca508 movne r3, #0 */
/* @0x1ca50c andeq r3, r6, #1 */
/* @0x1ca510 ldr r4, [r5, #0x178] */
/* @0x1ca514 cmp r3, #0 */
/* @0x1ca518 bne 0x1ca558 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x208> */
/* @0x1ca51c ldrb r3, [r5, #0x68] */
/* @0x1ca520 cmp r3, #0 */
/* @0x1ca524 bne 0x1ca558 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x208> */
/* @0x1ca528 ldrb r3, [r5, #0x69] */
/* @0x1ca52c cmp r3, #0 */
/* @0x1ca530 bne 0x1ca558 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x208> */
/* @0x1ca534 vstr s19, [sp] */
/* @0x1ca538 str r8, [sp, #0x4] */
/* @0x1ca53c mov r0, r5 */
/* @0x1ca540 vmov r1, s17 */
/* @0x1ca544 vmov r2, s18 */
/* @0x1ca548 vmov r3, s16 */
/* @0x1ca54c bl 0x1946f4 <_ZN9CInstance19Collision_RectangleEffffb> */
/* @0x1ca550 cmp r0, #0 */
/* @0x1ca554 bne 0x1ca44c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xfc> */
/* @0x1ca558 cmp r4, #0 */
/* @0x1ca55c mov r5, r4 */
/* @0x1ca560 bne 0x1ca504 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x1b4> */
/* @0x1ca564 b 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca568 ldr r3, [r7, #0x78] */
/* @0x1ca56c cmp r4, r3 */
/* @0x1ca570 bne 0x1ca464 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x114> */
/* @0x1ca574 b 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca578 bl 0x1cc24c <_Z10UpdateTreev> */
/* @0x1ca57c ldr r3, [pc, #0x140] */
/* @0x1ca580 cmp r6, #0 */
/* @0x1ca584 ldr r10, [r9, r3] */
/* @0x1ca588 str r5, [r10] */
/* @0x1ca58c beq 0x1ca59c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x24c> */
/* @0x1ca590 ldr r3, [r7, #0x78] */
/* @0x1ca594 cmp r4, r3 */
/* @0x1ca598 beq 0x1ca44c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xfc> */
/* @0x1ca59c vcvt.f64.f32 d6, s17 */
/* @0x1ca5a0 ldr r3, [pc, #0x120] */
/* @0x1ca5a4 strb r8, [sp, #0x40] */
/* @0x1ca5a8 add r3, pc, r3 */
/* @0x1ca5ac strb r6, [sp, #0x41] */
/* @0x1ca5b0 str r7, [sp, #0x44] */
/* @0x1ca5b4 str r4, [r3] */
/* @0x1ca5b8 vcvt.f64.f32 d7, s18 */
/* @0x1ca5bc vstr d6, [sp, #32] */
/* @0x1ca5c0 vstr d7, [sp, #40] */
/* @0x1ca5c4 vcvt.f64.f32 d6, s16 */
/* @0x1ca5c8 vcvt.f64.f32 d7, s19 */
/* @0x1ca5cc vstr d6, [sp, #48] */
/* @0x1ca5d0 vcmpe.f32 s17, s16 */
/* @0x1ca5d4 vstr d7, [sp, #56] */
/* @0x1ca5d8 vmrs APSR_nzcv, fpscr */
/* @0x1ca5dc bpl 0x1ca6ac <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x35c> */
/* @0x1ca5e0 vcvt.s32.f32 s15, s17 */
/* @0x1ca5e4 vmov r3, s15 */
/* @0x1ca5e8 vcmpe.f32 s18, s19 */
/* @0x1ca5ec ldr r0, [pc, #0xd8] */
/* @0x1ca5f0 str r3, [sp, #0x10] */
/* @0x1ca5f4 add r12, sp, #32 */
/* @0x1ca5f8 ldr r3, [pc, #0xd0] */
/* @0x1ca5fc add r1, sp, #16 */
/* @0x1ca600 add r2, sp, #24 */
/* @0x1ca604 vmrs APSR_nzcv, fpscr */
/* @0x1ca608 vcmpe.f32 s17, s16 */
/* @0x1ca60c add r3, pc, r3 */
/* @0x1ca610 vcvtmi.s32.f32 s15, s18 */
/* @0x1ca614 vcvtpl.s32.f32 s15, s19 */
/* @0x1ca618 vmrs APSR_nzcv, fpscr */
/* @0x1ca61c vcmpe.f32 s18, s19 */
/* @0x1ca620 vstr s15, [sp, #20] */
/* @0x1ca624 vcvtgt.s32.f32 s16, s17 */
/* @0x1ca628 vcvtle.s32.f32 s16, s16 */
/* @0x1ca62c vmrs APSR_nzcv, fpscr */
/* @0x1ca630 vcvtgt.s32.f32 s18, s18 */
/* @0x1ca634 vstr s16, [sp, #24] */
/* @0x1ca638 vcvtle.s32.f32 s18, s19 */
/* @0x1ca63c vstr s18, [sp, #28] */
/* @0x1ca640 ldr r0, [r9, r0] */
/* @0x1ca644 str r12, [sp] */
/* @0x1ca648 ldr r0, [r0] */
/* @0x1ca64c bl 0x10d720 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPKiS4_PFbS1_PvES5_> */
/* @0x1ca650 ldr r5, [r10] */
/* @0x1ca654 b 0x1ca44c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xfc> */
/* @0x1ca658 ldr r3, [pc, #0x74] */
/* @0x1ca65c ldr r3, [r9, r3] */
/* @0x1ca660 ldr r3, [r3] */
/* @0x1ca664 ldr r2, [r3, #0x4] */
/* @0x1ca668 ldr r3, [r3] */
/* @0x1ca66c and r2, r4, r2 */
/* @0x1ca670 ldr r3, [r3, r2, lsl #3] */
/* @0x1ca674 cmp r3, #0 */
/* @0x1ca678 bne 0x1ca68c <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x33c> */
/* @0x1ca67c b 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca680 ldr r3, [r3, #0x4] */
/* @0x1ca684 cmp r3, #0 */
/* @0x1ca688 beq 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca68c ldr r2, [r3, #0x8] */
/* @0x1ca690 cmp r4, r2 */
/* @0x1ca694 bne 0x1ca680 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x330> */
/* @0x1ca698 ldr r3, [r3, #0xc] */
/* @0x1ca69c cmp r3, #0 */
/* @0x1ca6a0 str r3, [sp, #0xc] */
/* @0x1ca6a4 bne 0x1ca3d0 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x80> */
/* @0x1ca6a8 b 0x1ca448 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0xf8> */
/* @0x1ca6ac vcvt.s32.f32 s15, s16 */
/* @0x1ca6b0 vmov r3, s15 */
/* @0x1ca6b4 b 0x1ca5e8 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x298> */
/* @0x1ca6b8 .word 0x002278b8 */
/* @0x1ca6bc .word 0xffffbff4 */
/* @0x1ca6c0 .word 0xffffbcd8 */
/* @0x1ca6c4 .word 0xffffeeb8 */
/* @0x1ca6c8 eoreq r10, r2, r8, lsr r11 */
/* @0x1ca6cc .word 0xffffc5f4 */
/* @0x1ca6d0 .word 0xffffddac */
/* @0x1ca6d4 .word 0xffffbfec */

/* ── FUNC 0x1ca6d8 · Command_InstancePlace(CInstance*, float, float, int) · size=800 · insn=200 */
/* @0x1ca6d8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1ca6dc sub sp, sp, #32 */
/* @0x1ca6e0 mov r5, r3 */
/* @0x1ca6e4 add r3, sp, #32 */
/* @0x1ca6e8 mov r6, r0 */
/* @0x1ca6ec mov r7, r1 */
/* @0x1ca6f0 mov r4, #0 */
/* @0x1ca6f4 mov r0, r5 */
/* @0x1ca6f8 str r4, [r3, #-0x14]! */
/* @0x1ca6fc mov r1, r3 */
/* @0x1ca700 mov r8, r2 */
/* @0x1ca704 bl 0x1c8df8 <_Z22ShouldUseFastCollisioniPP9CObjectGM> */
/* @0x1ca708 ldr r9, [pc, #0x2c8] */
/* @0x1ca70c add r9, pc, r9 */
/* @0x1ca710 cmn r0, #1 */
/* @0x1ca714 beq 0x1ca9d0 <_Z21Command_InstancePlaceP9CInstanceffi+0x2f8> */
/* @0x1ca718 cmp r0, #1 */
/* @0x1ca71c beq 0x1ca820 <_Z21Command_InstancePlaceP9CInstanceffi+0x148> */
/* @0x1ca720 mov r1, r7 */
/* @0x1ca724 mov r2, r8 */
/* @0x1ca728 mov r0, r6 */
/* @0x1ca72c ldr r7, [r6, #0xb4] */
/* @0x1ca730 ldr r8, [r6, #0xb8] */
/* @0x1ca734 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1ca738 cmn r5, #3 */
/* @0x1ca73c beq 0x1ca8e4 <_Z21Command_InstancePlaceP9CInstanceffi+0x20c> */
/* @0x1ca740 movw r3, #0x869f */
/* @0x1ca744 movt r3, #0x1 */
/* @0x1ca748 cmp r5, r3 */
/* @0x1ca74c bgt 0x1ca954 <_Z21Command_InstancePlaceP9CInstanceffi+0x27c> */
/* @0x1ca750 ldr r3, [sp, #0xc] */
/* @0x1ca754 cmp r3, #0 */
/* @0x1ca758 beq 0x1ca7c8 <_Z21Command_InstancePlaceP9CInstanceffi+0xf0> */
/* @0x1ca75c ldr r5, [r3, #0xd0] */
/* @0x1ca760 cmp r5, #0 */
/* @0x1ca764 beq 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca768 ldr r3, [r5, #0x8] */
/* @0x1ca76c cmp r3, #0 */
/* @0x1ca770 beq 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca774 ldr r4, [r5, #0x8] */
/* @0x1ca778 ldr r5, [r5] */
/* @0x1ca77c ldrb r3, [r4, #0x68] */
/* @0x1ca780 cmp r3, #0 */
/* @0x1ca784 bne 0x1ca760 <_Z21Command_InstancePlaceP9CInstanceffi+0x88> */
/* @0x1ca788 ldrb r3, [r4, #0x69] */
/* @0x1ca78c cmp r3, #0 */
/* @0x1ca790 bne 0x1ca760 <_Z21Command_InstancePlaceP9CInstanceffi+0x88> */
/* @0x1ca794 mov r2, #1 */
/* @0x1ca798 mov r0, r4 */
/* @0x1ca79c mov r1, r6 */
/* @0x1ca7a0 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1ca7a4 cmp r0, #0 */
/* @0x1ca7a8 beq 0x1ca760 <_Z21Command_InstancePlaceP9CInstanceffi+0x88> */
/* @0x1ca7ac mov r0, r6 */
/* @0x1ca7b0 mov r1, r7 */
/* @0x1ca7b4 mov r2, r8 */
/* @0x1ca7b8 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1ca7bc mov r0, r4 */
/* @0x1ca7c0 add sp, sp, #32 */
/* @0x1ca7c4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1ca7c8 ldr r3, [pc, #0x20c] */
/* @0x1ca7cc ldr r3, [r9, r3] */
/* @0x1ca7d0 ldr r3, [r3] */
/* @0x1ca7d4 ldr r2, [r3, #0x4] */
/* @0x1ca7d8 ldr r3, [r3] */
/* @0x1ca7dc and r2, r5, r2 */
/* @0x1ca7e0 ldr r3, [r3, r2, lsl #3] */
/* @0x1ca7e4 cmp r3, #0 */
/* @0x1ca7e8 bne 0x1ca7fc <_Z21Command_InstancePlaceP9CInstanceffi+0x124> */
/* @0x1ca7ec b 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca7f0 ldr r3, [r3, #0x4] */
/* @0x1ca7f4 cmp r3, #0 */
/* @0x1ca7f8 beq 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca7fc ldr r2, [r3, #0x8] */
/* @0x1ca800 cmp r5, r2 */
/* @0x1ca804 bne 0x1ca7f0 <_Z21Command_InstancePlaceP9CInstanceffi+0x118> */
/* @0x1ca808 ldr r3, [r3, #0xc] */
/* @0x1ca80c cmp r3, #0 */
/* @0x1ca810 str r3, [sp, #0xc] */
/* @0x1ca814 bne 0x1ca75c <_Z21Command_InstancePlaceP9CInstanceffi+0x84> */
/* @0x1ca818 mov r4, #0 */
/* @0x1ca81c b 0x1ca7ac <_Z21Command_InstancePlaceP9CInstanceffi+0xd4> */
/* @0x1ca820 bl 0x1cc24c <_Z10UpdateTreev> */
/* @0x1ca824 mov r1, r7 */
/* @0x1ca828 mov r2, r8 */
/* @0x1ca82c mov r0, r6 */
/* @0x1ca830 ldr r8, [r6, #0xb4] */
/* @0x1ca834 ldr r7, [r6, #0xb8] */
/* @0x1ca838 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1ca83c ldrb r3, [r6, #0x64] */
/* @0x1ca840 cmp r3, r4 */
/* @0x1ca844 bne 0x1ca944 <_Z21Command_InstancePlaceP9CInstanceffi+0x26c> */
/* @0x1ca848 ldr r3, [r6, #0xec] */
/* @0x1ca84c mov r10, #0 */
/* @0x1ca850 ldr r0, [r6, #0xf4] */
/* @0x1ca854 add r1, sp, #16 */
/* @0x1ca858 ldr r12, [r6, #0xe8] */
/* @0x1ca85c add r2, sp, #24 */
/* @0x1ca860 ldr lr, [r6, #0xf0] */
/* @0x1ca864 ldr r4, [pc, #0x174] */
/* @0x1ca868 cmp r0, r3 */
/* @0x1ca86c strle r0, [sp, #0x14] */
/* @0x1ca870 strgt r3, [sp, #0x14] */
/* @0x1ca874 cmp r0, r3 */
/* @0x1ca878 strge r0, [sp, #0x1c] */
/* @0x1ca87c strlt r3, [sp, #0x1c] */
/* @0x1ca880 ldr r0, [pc, #0x15c] */
/* @0x1ca884 cmp lr, r12 */
/* @0x1ca888 strle lr, [sp, #0x10] */
/* @0x1ca88c strgt r12, [sp, #0x10] */
/* @0x1ca890 cmp lr, r12 */
/* @0x1ca894 strge lr, [sp, #0x18] */
/* @0x1ca898 strlt r12, [sp, #0x18] */
/* @0x1ca89c add r0, pc, r0 */
/* @0x1ca8a0 ldr r4, [r9, r4] */
/* @0x1ca8a4 ldr r3, [pc, #0x13c] */
/* @0x1ca8a8 str r5, [r0] */
/* @0x1ca8ac str r10, [r4] */
/* @0x1ca8b0 ldr r0, [r9, r3] */
/* @0x1ca8b4 ldr r3, [pc, #0x130] */
/* @0x1ca8b8 str r6, [sp] */
/* @0x1ca8bc add r3, pc, r3 */
/* @0x1ca8c0 ldr r0, [r0] */
/* @0x1ca8c4 bl 0x10d720 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPKiS4_PFbS1_PvES5_> */
/* @0x1ca8c8 mov r0, r6 */
/* @0x1ca8cc mov r1, r8 */
/* @0x1ca8d0 mov r2, r7 */
/* @0x1ca8d4 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1ca8d8 ldr r0, [r4] */
/* @0x1ca8dc add sp, sp, #32 */
/* @0x1ca8e0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1ca8e4 ldr r3, [pc, #0x104] */
/* @0x1ca8e8 ldr r3, [r9, r3] */
/* @0x1ca8ec ldr r3, [r3] */
/* @0x1ca8f0 ldr r4, [r3, #0x80] */
/* @0x1ca8f4 cmp r4, #0 */
/* @0x1ca8f8 beq 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca8fc ldrb r3, [r4, #0x68] */
/* @0x1ca900 ldr r5, [r4, #0x178] */
/* @0x1ca904 cmp r3, #0 */
/* @0x1ca908 bne 0x1ca930 <_Z21Command_InstancePlaceP9CInstanceffi+0x258> */
/* @0x1ca90c ldrb r3, [r4, #0x69] */
/* @0x1ca910 cmp r3, #0 */
/* @0x1ca914 bne 0x1ca930 <_Z21Command_InstancePlaceP9CInstanceffi+0x258> */
/* @0x1ca918 mov r2, #1 */
/* @0x1ca91c mov r0, r4 */
/* @0x1ca920 mov r1, r6 */
/* @0x1ca924 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1ca928 cmp r0, #0 */
/* @0x1ca92c bne 0x1ca7ac <_Z21Command_InstancePlaceP9CInstanceffi+0xd4> */
/* @0x1ca930 cmp r5, #0 */
/* @0x1ca934 mov r4, r5 */
/* @0x1ca938 bne 0x1ca8fc <_Z21Command_InstancePlaceP9CInstanceffi+0x224> */
/* @0x1ca93c mov r4, #0 */
/* @0x1ca940 b 0x1ca7ac <_Z21Command_InstancePlaceP9CInstanceffi+0xd4> */
/* @0x1ca944 mov r1, r4 */
/* @0x1ca948 mov r0, r6 */
/* @0x1ca94c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1ca950 b 0x1ca848 <_Z21Command_InstancePlaceP9CInstanceffi+0x170> */
/* @0x1ca954 ldr r3, [pc, #0x98] */
/* @0x1ca958 ldr r3, [r9, r3] */
/* @0x1ca95c ldr r2, [r3, #0x4] */
/* @0x1ca960 ldr r3, [r3] */
/* @0x1ca964 and r2, r5, r2 */
/* @0x1ca968 ldr r2, [r3, r2, lsl #3] */
/* @0x1ca96c cmp r2, #0 */
/* @0x1ca970 bne 0x1ca984 <_Z21Command_InstancePlaceP9CInstanceffi+0x2ac> */
/* @0x1ca974 b 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca978 ldr r2, [r2, #0x4] */
/* @0x1ca97c cmp r2, #0 */
/* @0x1ca980 beq 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca984 ldr r3, [r2, #0x8] */
/* @0x1ca988 cmp r5, r3 */
/* @0x1ca98c bne 0x1ca978 <_Z21Command_InstancePlaceP9CInstanceffi+0x2a0> */
/* @0x1ca990 ldr r4, [r2, #0xc] */
/* @0x1ca994 cmp r4, #0 */
/* @0x1ca998 beq 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca99c ldrb r3, [r4, #0x68] */
/* @0x1ca9a0 cmp r3, #0 */
/* @0x1ca9a4 bne 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca9a8 ldrb r3, [r4, #0x69] */
/* @0x1ca9ac cmp r3, #0 */
/* @0x1ca9b0 bne 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca9b4 mov r0, r4 */
/* @0x1ca9b8 mov r1, r6 */
/* @0x1ca9bc mov r2, #1 */
/* @0x1ca9c0 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1ca9c4 cmp r0, #0 */
/* @0x1ca9c8 bne 0x1ca7ac <_Z21Command_InstancePlaceP9CInstanceffi+0xd4> */
/* @0x1ca9cc b 0x1ca818 <_Z21Command_InstancePlaceP9CInstanceffi+0x140> */
/* @0x1ca9d0 mov r0, r4 */
/* @0x1ca9d4 b 0x1ca7c0 <_Z21Command_InstancePlaceP9CInstanceffi+0xe8> */
/* @0x1ca9d8 eoreq r7, r2, r4, asr #10 */
/* @0x1ca9dc .word 0xffffbfec */
/* @0x1ca9e0 .word 0xffffeeb8 */
/* @0x1ca9e4 eoreq r10, r2, r4, asr #16 */
/* @0x1ca9e8 .word 0xffffc5f4 */
/* @0x1ca9ec .word 0xffffdd84 */
/* @0x1ca9f0 .word 0xffffbcd8 */
/* @0x1ca9f4 .word 0xffffbff4 */

/* ── FUNC 0x1ca9f8 · Command_IsMeeting(CInstance*, int, float, float) · size=36 · insn=9 */
/* @0x1ca9f8 mov r12, r1 */
/* @0x1ca9fc mov r1, r2 */
/* @0x1caa00 push {r3, lr} */
/* @0x1caa04 mov r2, r3 */
/* @0x1caa08 mov r3, r12 */
/* @0x1caa0c bl 0x1ca6d8 <_Z21Command_InstancePlaceP9CInstanceffi> */
/* @0x1caa10 adds r0, r0, #0 */
/* @0x1caa14 movne r0, #1 */
/* @0x1caa18 pop {r3, pc} */

/* ── FUNC 0x1caa1c · Command_IsEmpty(CInstance*, float, float) · size=376 · insn=94 */
/* @0x1caa1c ldr r3, [pc, #0x15c] */
/* @0x1caa20 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1caa24 ldr r3, [pc, r3] */
/* @0x1caa28 sub sp, sp, #24 */
/* @0x1caa2c mov r5, r0 */
/* @0x1caa30 ldrb r3, [r3] */
/* @0x1caa34 mov r6, r1 */
/* @0x1caa38 mov r4, r2 */
/* @0x1caa3c cmp r3, #0 */
/* @0x1caa40 beq 0x1caafc <_Z15Command_IsEmptyP9CInstanceff+0xe0> */
/* @0x1caa44 bl 0x1cc24c <_Z10UpdateTreev> */
/* @0x1caa48 mov r1, r6 */
/* @0x1caa4c mov r2, r4 */
/* @0x1caa50 mov r0, r5 */
/* @0x1caa54 ldr r8, [r5, #0xb4] */
/* @0x1caa58 ldr r7, [r5, #0xb8] */
/* @0x1caa5c bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1caa60 ldrb r3, [r5, #0x64] */
/* @0x1caa64 cmp r3, #0 */
/* @0x1caa68 bne 0x1cab70 <_Z15Command_IsEmptyP9CInstanceff+0x154> */
/* @0x1caa6c ldr r3, [pc, #0x110] */
/* @0x1caa70 add r1, sp, #8 */
/* @0x1caa74 ldr r4, [pc, #0x10c] */
/* @0x1caa78 add r2, sp, #16 */
/* @0x1caa7c ldr r3, [pc, r3] */
/* @0x1caa80 ldr r12, [r5, #0xec] */
/* @0x1caa84 ldr lr, [r5, #0xf4] */
/* @0x1caa88 add r4, pc, r4 */
/* @0x1caa8c ldr r6, [r5, #0xe8] */
/* @0x1caa90 mov r10, #1 */
/* @0x1caa94 ldr r9, [r5, #0xf0] */
/* @0x1caa98 ldr r0, [r3] */
/* @0x1caa9c ldr r3, [pc, #0xe8] */
/* @0x1caaa0 str r5, [sp] */
/* @0x1caaa4 add r3, pc, r3 */
/* @0x1caaa8 strb r10, [r4, #0x200] */
/* @0x1caaac cmp lr, r12 */
/* @0x1caab0 strle lr, [sp, #0xc] */
/* @0x1caab4 strgt r12, [sp, #0xc] */
/* @0x1caab8 cmp lr, r12 */
/* @0x1caabc strge lr, [sp, #0x14] */
/* @0x1caac0 strlt r12, [sp, #0x14] */
/* @0x1caac4 cmp r9, r6 */
/* @0x1caac8 strle r9, [sp, #0x8] */
/* @0x1caacc strgt r6, [sp, #0x8] */
/* @0x1caad0 cmp r9, r6 */
/* @0x1caad4 strge r9, [sp, #0x10] */
/* @0x1caad8 strlt r6, [sp, #0x10] */
/* @0x1caadc bl 0x10d720 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPKiS4_PFbS1_PvES5_> */
/* @0x1caae0 mov r0, r5 */
/* @0x1caae4 mov r1, r8 */
/* @0x1caae8 mov r2, r7 */
/* @0x1caaec bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1caaf0 ldrb r0, [r4, #0x200] */
/* @0x1caaf4 add sp, sp, #24 */
/* @0x1caaf8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1caafc ldr r7, [r0, #0xb4] */
/* @0x1cab00 ldr r6, [r0, #0xb8] */
/* @0x1cab04 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cab08 ldr r3, [pc, #0x80] */
/* @0x1cab0c ldr r3, [pc, r3] */
/* @0x1cab10 ldr r3, [r3] */
/* @0x1cab14 ldr r3, [r3, #0x80] */
/* @0x1cab18 cmp r3, #0 */
/* @0x1cab1c beq 0x1cab48 <_Z15Command_IsEmptyP9CInstanceff+0x12c> */
/* @0x1cab20 mov r0, r3 */
/* @0x1cab24 mov r1, r5 */
/* @0x1cab28 mov r2, #1 */
/* @0x1cab2c ldr r4, [r3, #0x178] */
/* @0x1cab30 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1cab34 mov r3, r4 */
/* @0x1cab38 cmp r0, #0 */
/* @0x1cab3c bne 0x1cab68 <_Z15Command_IsEmptyP9CInstanceff+0x14c> */
/* @0x1cab40 cmp r4, #0 */
/* @0x1cab44 bne 0x1cab20 <_Z15Command_IsEmptyP9CInstanceff+0x104> */
/* @0x1cab48 mov r4, #1 */
/* @0x1cab4c mov r0, r5 */
/* @0x1cab50 mov r1, r7 */
/* @0x1cab54 mov r2, r6 */
/* @0x1cab58 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cab5c mov r0, r4 */
/* @0x1cab60 add sp, sp, #24 */
/* @0x1cab64 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1cab68 mov r4, #0 */
/* @0x1cab6c b 0x1cab4c <_Z15Command_IsEmptyP9CInstanceff+0x130> */
/* @0x1cab70 mov r0, r5 */
/* @0x1cab74 mov r1, #1 */
/* @0x1cab78 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cab7c b 0x1caa6c <_Z15Command_IsEmptyP9CInstanceff+0x50> */
/* @0x1cab80 eoreq r5, r2, r12, asr r12 */
/* @0x1cab84 eoreq r3, r2, r8, asr #15 */
/* @0x1cab88 eorseq r7, r7, r4, lsr #24 */
/* @0x1cab8c .word 0xffffdc98 */
/* @0x1cab90 eoreq r2, r2, r12, lsl lr */

/* ── FUNC 0x1cab94 · Command_IsFree(CInstance*, float, float) · size=388 · insn=97 */
/* @0x1cab94 ldr r3, [pc, #0x168] */
/* @0x1cab98 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1cab9c ldr r3, [pc, r3] */
/* @0x1caba0 sub sp, sp, #24 */
/* @0x1caba4 mov r5, r0 */
/* @0x1caba8 ldrb r3, [r3] */
/* @0x1cabac mov r6, r1 */
/* @0x1cabb0 mov r4, r2 */
/* @0x1cabb4 cmp r3, #0 */
/* @0x1cabb8 beq 0x1cac74 <_Z14Command_IsFreeP9CInstanceff+0xe0> */
/* @0x1cabbc bl 0x1cc24c <_Z10UpdateTreev> */
/* @0x1cabc0 mov r1, r6 */
/* @0x1cabc4 mov r2, r4 */
/* @0x1cabc8 mov r0, r5 */
/* @0x1cabcc ldr r8, [r5, #0xb4] */
/* @0x1cabd0 ldr r7, [r5, #0xb8] */
/* @0x1cabd4 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cabd8 ldrb r3, [r5, #0x64] */
/* @0x1cabdc cmp r3, #0 */
/* @0x1cabe0 bne 0x1cacec <_Z14Command_IsFreeP9CInstanceff+0x158> */
/* @0x1cabe4 ldr r3, [pc, #0x11c] */
/* @0x1cabe8 add r1, sp, #8 */
/* @0x1cabec ldr r4, [pc, #0x118] */
/* @0x1cabf0 add r2, sp, #16 */
/* @0x1cabf4 ldr r3, [pc, r3] */
/* @0x1cabf8 ldr r12, [r5, #0xec] */
/* @0x1cabfc ldr lr, [r5, #0xf4] */
/* @0x1cac00 add r4, pc, r4 */
/* @0x1cac04 ldr r6, [r5, #0xe8] */
/* @0x1cac08 mov r10, #1 */
/* @0x1cac0c ldr r9, [r5, #0xf0] */
/* @0x1cac10 ldr r0, [r3] */
/* @0x1cac14 ldr r3, [pc, #0xf4] */
/* @0x1cac18 str r5, [sp] */
/* @0x1cac1c add r3, pc, r3 */
/* @0x1cac20 strb r10, [r4, #0x200] */
/* @0x1cac24 cmp lr, r12 */
/* @0x1cac28 strle lr, [sp, #0xc] */
/* @0x1cac2c strgt r12, [sp, #0xc] */
/* @0x1cac30 cmp lr, r12 */
/* @0x1cac34 strge lr, [sp, #0x14] */
/* @0x1cac38 strlt r12, [sp, #0x14] */
/* @0x1cac3c cmp r9, r6 */
/* @0x1cac40 strle r9, [sp, #0x8] */
/* @0x1cac44 strgt r6, [sp, #0x8] */
/* @0x1cac48 cmp r9, r6 */
/* @0x1cac4c strge r9, [sp, #0x10] */
/* @0x1cac50 strlt r6, [sp, #0x10] */
/* @0x1cac54 bl 0x10d720 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPKiS4_PFbS1_PvES5_> */
/* @0x1cac58 mov r0, r5 */
/* @0x1cac5c mov r1, r8 */
/* @0x1cac60 mov r2, r7 */
/* @0x1cac64 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cac68 ldrb r0, [r4, #0x200] */
/* @0x1cac6c add sp, sp, #24 */
/* @0x1cac70 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1cac74 ldr r7, [r0, #0xb4] */
/* @0x1cac78 ldr r6, [r0, #0xb8] */
/* @0x1cac7c bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cac80 ldr r3, [pc, #0x8c] */
/* @0x1cac84 ldr r3, [pc, r3] */
/* @0x1cac88 ldr r3, [r3] */
/* @0x1cac8c ldr r0, [r3, #0x80] */
/* @0x1cac90 cmp r0, #0 */
/* @0x1cac94 bne 0x1cacd8 <_Z14Command_IsFreeP9CInstanceff+0x144> */
/* @0x1cac98 mov r4, #1 */
/* @0x1cac9c mov r0, r5 */
/* @0x1caca0 mov r1, r7 */
/* @0x1caca4 mov r2, r6 */
/* @0x1caca8 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cacac mov r0, r4 */
/* @0x1cacb0 add sp, sp, #24 */
/* @0x1cacb4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1cacb8 mov r1, r5 */
/* @0x1cacbc mov r2, #1 */
/* @0x1cacc0 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1cacc4 cmp r0, #0 */
/* @0x1cacc8 bne 0x1cacfc <_Z14Command_IsFreeP9CInstanceff+0x168> */
/* @0x1caccc cmp r4, #0 */
/* @0x1cacd0 mov r0, r4 */
/* @0x1cacd4 beq 0x1cac98 <_Z14Command_IsFreeP9CInstanceff+0x104> */
/* @0x1cacd8 ldrb r12, [r0, #0x66] */
/* @0x1cacdc ldr r4, [r0, #0x178] */
/* @0x1cace0 cmp r12, #0 */
/* @0x1cace4 beq 0x1caccc <_Z14Command_IsFreeP9CInstanceff+0x138> */
/* @0x1cace8 b 0x1cacb8 <_Z14Command_IsFreeP9CInstanceff+0x124> */
/* @0x1cacec mov r0, r5 */
/* @0x1cacf0 mov r1, #1 */
/* @0x1cacf4 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cacf8 b 0x1cabe4 <_Z14Command_IsFreeP9CInstanceff+0x50> */
/* @0x1cacfc mov r4, #0 */
/* @0x1cad00 b 0x1cac9c <_Z14Command_IsFreeP9CInstanceff+0x108> */
/* @0x1cad04 eoreq r5, r2, r4, ror #21 */
/* @0x1cad08 eoreq r3, r2, r0, asr r6 */
/* @0x1cad0c eorseq r7, r7, r12, lsr #21 */
/* @0x1cad10 .word 0xffffdbb4 */
/* @0x1cad14 eoreq r2, r2, r4, lsr #25 */

/* ── FUNC 0x1cad18 · Contact_TestFree(CInstance*, float, float, bool) · size=16 · insn=4 */
/* @0x1cad18 cmp r3, #0 */
/* @0x1cad1c bne 0x1cad24 <_Z16Contact_TestFreeP9CInstanceffb+0xc> */
/* @0x1cad20 b 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x1cad24 b 0x1caa1c <_Z15Command_IsEmptyP9CInstanceff> */

/* ── FUNC 0x1cad28 · Command_MoveContact(CInstance*, float, float, bool) · size=316 · insn=79 */
/* @0x1cad28 vmov s15, r2 */
/* @0x1cad2c push {r3, r4, r5, r6, r7, lr} */
/* @0x1cad30 vpush {d8} */
/* @0x1cad34 vcmpe.f32 s15, #0 */
/* @0x1cad38 mov r4, r0 */
/* @0x1cad3c mov r6, r3 */
/* @0x1cad40 vmov s17, r1 */
/* @0x1cad44 vmrs APSR_nzcv, fpscr */
/* @0x1cad48 bls 0x1cae10 <_Z19Command_MoveContactP9CInstanceffb+0xe8> */
/* @0x1cad4c vcvt.f64.f32 d6, s15 */
/* @0x1cad50 vldr s16, [pc, #260] */
/* @0x1cad54 vmov r0, r1, d6 */
/* @0x1cad58 bl 0xb66e8 <lrint@plt> */
/* @0x1cad5c vldr s15, [pc, #252] */
/* @0x1cad60 vmul.f32 s16, s17, s16 */
/* @0x1cad64 vdiv.f32 s16, s16, s15 */
/* @0x1cad68 mov r7, r0 */
/* @0x1cad6c vmov r0, s16 */
/* @0x1cad70 bl 0xb658c <cosf@plt> */
/* @0x1cad74 vmov s17, r0 */
/* @0x1cad78 vmov r0, s16 */
/* @0x1cad7c bl 0xb6580 <sinf@plt> */
/* @0x1cad80 ldr r1, [r4, #0xb4] */
/* @0x1cad84 mov r3, r6 */
/* @0x1cad88 ldr r2, [r4, #0xb8] */
/* @0x1cad8c vmov s16, r0 */
/* @0x1cad90 mov r0, r4 */
/* @0x1cad94 bl 0x1cad18 <_Z16Contact_TestFreeP9CInstanceffb> */
/* @0x1cad98 cmp r0, #0 */
/* @0x1cad9c beq 0x1cae08 <_Z19Command_MoveContactP9CInstanceffb+0xe0> */
/* @0x1cada0 cmp r7, #0 */
/* @0x1cada4 ble 0x1cae08 <_Z19Command_MoveContactP9CInstanceffb+0xe0> */
/* @0x1cada8 mov r5, #1 */
/* @0x1cadac b 0x1cadd4 <_Z19Command_MoveContactP9CInstanceffb+0xac> */
/* @0x1cadb0 vldr s14, [r4, #180] */
/* @0x1cadb4 vldr s15, [r4, #184] */
/* @0x1cadb8 vadd.f32 s14, s17, s14 */
/* @0x1cadbc vsub.f32 s15, s15, s16 */
/* @0x1cadc0 vmov r1, s14 */
/* @0x1cadc4 vmov r2, s15 */
/* @0x1cadc8 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cadcc cmp r5, r7 */
/* @0x1cadd0 bgt 0x1cae08 <_Z19Command_MoveContactP9CInstanceffb+0xe0> */
/* @0x1cadd4 vldr s14, [r4, #180] */
/* @0x1cadd8 vldr s15, [r4, #184] */
/* @0x1caddc vadd.f32 s14, s17, s14 */
/* @0x1cade0 mov r0, r4 */
/* @0x1cade4 mov r3, r6 */
/* @0x1cade8 add r5, r5, #1 */
/* @0x1cadec vsub.f32 s15, s15, s16 */
/* @0x1cadf0 vmov r1, s14 */
/* @0x1cadf4 vmov r2, s15 */
/* @0x1cadf8 bl 0x1cad18 <_Z16Contact_TestFreeP9CInstanceffb> */
/* @0x1cadfc cmp r0, #0 */
/* @0x1cae00 mov r0, r4 */
/* @0x1cae04 bne 0x1cadb0 <_Z19Command_MoveContactP9CInstanceffb+0x88> */
/* @0x1cae08 vpop {d8} */
/* @0x1cae0c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1cae10 vldr s16, [pc, #68] */
/* @0x1cae14 vmul.f32 s16, s17, s16 */
/* @0x1cae18 vldr s15, [pc, #64] */
/* @0x1cae1c vdiv.f32 s16, s16, s15 */
/* @0x1cae20 vmov r0, s16 */
/* @0x1cae24 bl 0xb658c <cosf@plt> */
/* @0x1cae28 vmov s17, r0 */
/* @0x1cae2c vmov r0, s16 */
/* @0x1cae30 bl 0xb6580 <sinf@plt> */
/* @0x1cae34 ldr r1, [r4, #0xb4] */
/* @0x1cae38 mov r3, r6 */
/* @0x1cae3c ldr r2, [r4, #0xb8] */
/* @0x1cae40 vmov s16, r0 */
/* @0x1cae44 mov r0, r4 */
/* @0x1cae48 bl 0x1cad18 <_Z16Contact_TestFreeP9CInstanceffb> */
/* @0x1cae4c cmp r0, #0 */
/* @0x1cae50 movne r7, #1000 */
/* @0x1cae54 bne 0x1cada8 <_Z19Command_MoveContactP9CInstanceffb+0x80> */
/* @0x1cae58 b 0x1cae08 <_Z19Command_MoveContactP9CInstanceffb+0xe0> */
/* @0x1cae5c ldrdmi r0, r1, [r9], #-251 */
/* @0x1cae60 teqmi r4, #0 */

/* ── FUNC 0x1cae64 · Command_MoveOutside(CInstance*, float, float, bool) · size=300 · insn=75 */
/* @0x1cae64 vmov s15, r2 */
/* @0x1cae68 push {r3, r4, r5, r6, r7, lr} */
/* @0x1cae6c vpush {d8} */
/* @0x1cae70 vcmpe.f32 s15, #0 */
/* @0x1cae74 mov r4, r0 */
/* @0x1cae78 mov r6, r3 */
/* @0x1cae7c vmov s16, r1 */
/* @0x1cae80 vmrs APSR_nzcv, fpscr */
/* @0x1cae84 bls 0x1caf3c <_Z19Command_MoveOutsideP9CInstanceffb+0xd8> */
/* @0x1cae88 vcvt.f64.f32 d6, s15 */
/* @0x1cae8c vldr s17, [pc, #244] */
/* @0x1cae90 vmov r0, r1, d6 */
/* @0x1cae94 bl 0xb66e8 <lrint@plt> */
/* @0x1cae98 vldr s15, [pc, #236] */
/* @0x1cae9c vmul.f32 s17, s16, s17 */
/* @0x1caea0 vdiv.f32 s17, s17, s15 */
/* @0x1caea4 mov r7, r0 */
/* @0x1caea8 vmov r0, s17 */
/* @0x1caeac bl 0xb658c <cosf@plt> */
/* @0x1caeb0 vmov s16, r0 */
/* @0x1caeb4 vmov r0, s17 */
/* @0x1caeb8 bl 0xb6580 <sinf@plt> */
/* @0x1caebc ldr r1, [r4, #0xb4] */
/* @0x1caec0 mov r3, r6 */
/* @0x1caec4 ldr r2, [r4, #0xb8] */
/* @0x1caec8 vmov s17, r0 */
/* @0x1caecc mov r0, r4 */
/* @0x1caed0 bl 0x1cad18 <_Z16Contact_TestFreeP9CInstanceffb> */
/* @0x1caed4 cmp r0, #0 */
/* @0x1caed8 bne 0x1caf34 <_Z19Command_MoveOutsideP9CInstanceffb+0xd0> */
/* @0x1caedc cmp r7, #0 */
/* @0x1caee0 ble 0x1caf34 <_Z19Command_MoveOutsideP9CInstanceffb+0xd0> */
/* @0x1caee4 mov r5, #1 */
/* @0x1caee8 b 0x1caef4 <_Z19Command_MoveOutsideP9CInstanceffb+0x90> */
/* @0x1caeec cmp r5, r7 */
/* @0x1caef0 bgt 0x1caf34 <_Z19Command_MoveOutsideP9CInstanceffb+0xd0> */
/* @0x1caef4 vldr s14, [r4, #180] */
/* @0x1caef8 vldr s15, [r4, #184] */
/* @0x1caefc vadd.f32 s14, s16, s14 */
/* @0x1caf00 mov r0, r4 */
/* @0x1caf04 add r5, r5, #1 */
/* @0x1caf08 vsub.f32 s15, s15, s17 */
/* @0x1caf0c vmov r1, s14 */
/* @0x1caf10 vmov r2, s15 */
/* @0x1caf14 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1caf18 mov r0, r4 */
/* @0x1caf1c ldr r1, [r4, #0xb4] */
/* @0x1caf20 mov r3, r6 */
/* @0x1caf24 ldr r2, [r4, #0xb8] */
/* @0x1caf28 bl 0x1cad18 <_Z16Contact_TestFreeP9CInstanceffb> */
/* @0x1caf2c cmp r0, #0 */
/* @0x1caf30 beq 0x1caeec <_Z19Command_MoveOutsideP9CInstanceffb+0x88> */
/* @0x1caf34 vpop {d8} */
/* @0x1caf38 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1caf3c vldr s15, [pc, #68] */
/* @0x1caf40 vmul.f32 s16, s16, s15 */
/* @0x1caf44 vldr s15, [pc, #64] */
/* @0x1caf48 vdiv.f32 s17, s16, s15 */
/* @0x1caf4c vmov r0, s17 */
/* @0x1caf50 bl 0xb658c <cosf@plt> */
/* @0x1caf54 vmov s16, r0 */
/* @0x1caf58 vmov r0, s17 */
/* @0x1caf5c bl 0xb6580 <sinf@plt> */
/* @0x1caf60 ldr r1, [r4, #0xb4] */
/* @0x1caf64 mov r3, r6 */
/* @0x1caf68 ldr r2, [r4, #0xb8] */
/* @0x1caf6c vmov s17, r0 */
/* @0x1caf70 mov r0, r4 */
/* @0x1caf74 bl 0x1cad18 <_Z16Contact_TestFreeP9CInstanceffb> */
/* @0x1caf78 cmp r0, #0 */
/* @0x1caf7c moveq r7, #1000 */
/* @0x1caf80 beq 0x1caee4 <_Z19Command_MoveOutsideP9CInstanceffb+0x80> */
/* @0x1caf84 b 0x1caf34 <_Z19Command_MoveOutsideP9CInstanceffb+0xd0> */
/* @0x1caf88 ldrdmi r0, r1, [r9], #-251 */
/* @0x1caf8c teqmi r4, #0 */

/* ── FUNC 0x1caf90 · Bounce_Test(CInstance*, float, float, bool) · size=16 · insn=4 */
/* @0x1caf90 cmp r3, #0 */
/* @0x1caf94 bne 0x1caf9c <_Z11Bounce_TestP9CInstanceffb+0xc> */
/* @0x1caf98 b 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x1caf9c b 0x1caa1c <_Z15Command_IsEmptyP9CInstanceff> */

/* ── FUNC 0x1cafa0 · Command_Bounce(CInstance*, bool, bool) · size=660 · insn=165 */
/* @0x1cafa0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1cafa4 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x1cafa8 mov r3, r2 */
/* @0x1cafac mov r6, r2 */
/* @0x1cafb0 mov r5, r1 */
/* @0x1cafb4 ldr r2, [r0, #0xb8] */
/* @0x1cafb8 mov r4, r0 */
/* @0x1cafbc ldr r1, [r0, #0xb4] */
/* @0x1cafc0 bl 0x1caf90 <_Z11Bounce_TestP9CInstanceffb> */
/* @0x1cafc4 cmp r0, #0 */
/* @0x1cafc8 movne r7, #0 */
/* @0x1cafcc beq 0x1cb1bc <_Z14Command_BounceP9CInstancebb+0x21c> */
/* @0x1cafd0 cmp r5, #0 */
/* @0x1cafd4 vldr s21, [r4, #180] */
/* @0x1cafd8 vldr s20, [r4, #184] */
/* @0x1cafdc beq 0x1cb104 <_Z14Command_BounceP9CInstancebb+0x164> */
/* @0x1cafe0 vmov.f32 s16, #1.000000e+01 */
/* @0x1cafe4 vldr s15, [r4, #204] */
/* @0x1cafe8 mov r5, #35 */
/* @0x1cafec vldr s25, [pc, #568] */
/* @0x1caff0 vldr s23, [pc, #568] */
/* @0x1caff4 vdiv.f32 s15, s15, s16 */
/* @0x1caff8 vcvt.f64.f32 d6, s15 */
/* @0x1caffc vmov r0, r1, d6 */
/* @0x1cb000 bl 0xb66e8 <lrint@plt> */
/* @0x1cb004 vmov.f32 s22, s16 */
/* @0x1cb008 vmov s13, r0 */
/* @0x1cb00c vcvt.f32.s32 s24, s13 */
/* @0x1cb010 vmul.f32 s24, s24, s16 */
/* @0x1cb014 vmov.f32 s16, s24 */
/* @0x1cb018 b 0x1cb028 <_Z14Command_BounceP9CInstancebb+0x88> */
/* @0x1cb01c subs r5, r5, #1 */
/* @0x1cb020 mov r7, #1 */
/* @0x1cb024 beq 0x1cb07c <_Z14Command_BounceP9CInstancebb+0xdc> */
/* @0x1cb028 vsub.f32 s16, s16, s22 */
/* @0x1cb02c vldr s17, [r4, #208] */
/* @0x1cb030 vmul.f32 s18, s16, s25 */
/* @0x1cb034 vdiv.f32 s18, s18, s23 */
/* @0x1cb038 vmov r0, s18 */
/* @0x1cb03c bl 0xb658c <cosf@plt> */
/* @0x1cb040 vmov s19, r0 */
/* @0x1cb044 vmov r0, s18 */
/* @0x1cb048 bl 0xb6580 <sinf@plt> */
/* @0x1cb04c vmov.f32 s14, s21 */
/* @0x1cb050 mov r3, r6 */
/* @0x1cb054 vmov.f32 s15, s20 */
/* @0x1cb058 vmla.f32 s14, s17, s19 */
/* @0x1cb05c vmov r1, s14 */
/* @0x1cb060 vmov s12, r0 */
/* @0x1cb064 mov r0, r4 */
/* @0x1cb068 vmls.f32 s15, s17, s12 */
/* @0x1cb06c vmov r2, s15 */
/* @0x1cb070 bl 0x1caf90 <_Z11Bounce_TestP9CInstanceffb> */
/* @0x1cb074 cmp r0, #0 */
/* @0x1cb078 beq 0x1cb01c <_Z14Command_BounceP9CInstancebb+0x7c> */
/* @0x1cb07c vmov.f32 s26, #1.000000e+01 */
/* @0x1cb080 mov r5, #35 */
/* @0x1cb084 vldr s25, [pc, #416] */
/* @0x1cb088 vldr s23, [pc, #416] */
/* @0x1cb08c vmov.f32 s17, s24 */
/* @0x1cb090 b 0x1cb0a0 <_Z14Command_BounceP9CInstancebb+0x100> */
/* @0x1cb094 subs r5, r5, #1 */
/* @0x1cb098 mov r7, #1 */
/* @0x1cb09c beq 0x1cb1f0 <_Z14Command_BounceP9CInstancebb+0x250> */
/* @0x1cb0a0 vadd.f32 s17, s17, s26 */
/* @0x1cb0a4 vldr s18, [r4, #208] */
/* @0x1cb0a8 vmul.f32 s19, s17, s25 */
/* @0x1cb0ac vdiv.f32 s19, s19, s23 */
/* @0x1cb0b0 vmov r0, s19 */
/* @0x1cb0b4 bl 0xb658c <cosf@plt> */
/* @0x1cb0b8 vmov s22, r0 */
/* @0x1cb0bc vmov r0, s19 */
/* @0x1cb0c0 bl 0xb6580 <sinf@plt> */
/* @0x1cb0c4 vmov.f32 s13, s21 */
/* @0x1cb0c8 mov r3, r6 */
/* @0x1cb0cc vmov.f32 s15, s20 */
/* @0x1cb0d0 vmla.f32 s13, s18, s22 */
/* @0x1cb0d4 vmov r1, s13 */
/* @0x1cb0d8 vmov s14, r0 */
/* @0x1cb0dc mov r0, r4 */
/* @0x1cb0e0 vmls.f32 s15, s18, s14 */
/* @0x1cb0e4 vmov r2, s15 */
/* @0x1cb0e8 bl 0x1caf90 <_Z11Bounce_TestP9CInstanceffb> */
/* @0x1cb0ec cmp r0, #0 */
/* @0x1cb0f0 beq 0x1cb094 <_Z14Command_BounceP9CInstancebb+0xf4> */
/* @0x1cb0f4 cmp r7, #0 */
/* @0x1cb0f8 bne 0x1cb1f0 <_Z14Command_BounceP9CInstancebb+0x250> */
/* @0x1cb0fc vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1cb100 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1cb104 vldr s15, [r4, #224] */
/* @0x1cb108 vadd.f32 s15, s21, s15 */
/* @0x1cb10c mov r3, r6 */
/* @0x1cb110 vmov r2, s20 */
/* @0x1cb114 mov r0, r4 */
/* @0x1cb118 vmov r1, s15 */
/* @0x1cb11c bl 0x1caf90 <_Z11Bounce_TestP9CInstanceffb> */
/* @0x1cb120 vldr s14, [r4, #184] */
/* @0x1cb124 vldr s15, [r4, #228] */
/* @0x1cb128 vadd.f32 s15, s14, s15 */
/* @0x1cb12c ldr r1, [r4, #0xb4] */
/* @0x1cb130 mov r3, r6 */
/* @0x1cb134 vmov r2, s15 */
/* @0x1cb138 mov r5, r0 */
/* @0x1cb13c mov r0, r4 */
/* @0x1cb140 bl 0x1caf90 <_Z11Bounce_TestP9CInstanceffb> */
/* @0x1cb144 vldr s12, [r4, #180] */
/* @0x1cb148 vldr s13, [r4, #224] */
/* @0x1cb14c vldr s14, [r4, #184] */
/* @0x1cb150 vldr s15, [r4, #228] */
/* @0x1cb154 vadd.f32 s13, s12, s13 */
/* @0x1cb158 mov r3, r6 */
/* @0x1cb15c vadd.f32 s15, s14, s15 */
/* @0x1cb160 vmov r1, s13 */
/* @0x1cb164 vmov r2, s15 */
/* @0x1cb168 mov r7, r0 */
/* @0x1cb16c mov r0, r4 */
/* @0x1cb170 bl 0x1caf90 <_Z11Bounce_TestP9CInstanceffb> */
/* @0x1cb174 eor r2, r7, #1 */
/* @0x1cb178 eor r3, r5, #1 */
/* @0x1cb17c and r3, r2, r3 */
/* @0x1cb180 tst r3, #255 */
/* @0x1cb184 bne 0x1cb1dc <_Z14Command_BounceP9CInstancebb+0x23c> */
/* @0x1cb188 and r3, r7, r5 */
/* @0x1cb18c tst r3, #255 */
/* @0x1cb190 bne 0x1cb1d4 <_Z14Command_BounceP9CInstancebb+0x234> */
/* @0x1cb194 cmp r5, #0 */
/* @0x1cb198 beq 0x1cb214 <_Z14Command_BounceP9CInstancebb+0x274> */
/* @0x1cb19c cmp r7, #0 */
/* @0x1cb1a0 bne 0x1cb0fc <_Z14Command_BounceP9CInstancebb+0x15c> */
/* @0x1cb1a4 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1cb1a8 mov r0, r4 */
/* @0x1cb1ac ldr r1, [r4, #0xe4] */
/* @0x1cb1b0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1cb1b4 eor r1, r1, #-2147483648 */
/* @0x1cb1b8 b 0x193114 <_ZN9CInstance9SetVspeedEf> */
/* @0x1cb1bc mov r0, r4 */
/* @0x1cb1c0 ldr r1, [r4, #0xc4] */
/* @0x1cb1c4 ldr r2, [r4, #0xc8] */
/* @0x1cb1c8 mov r7, #1 */
/* @0x1cb1cc bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cb1d0 b 0x1cafd0 <_Z14Command_BounceP9CInstancebb+0x30> */
/* @0x1cb1d4 cmp r0, #0 */
/* @0x1cb1d8 bne 0x1cb0fc <_Z14Command_BounceP9CInstancebb+0x15c> */
/* @0x1cb1dc ldr r1, [r4, #0xe0] */
/* @0x1cb1e0 mov r0, r4 */
/* @0x1cb1e4 eor r1, r1, #-2147483648 */
/* @0x1cb1e8 bl 0x1930f4 <_ZN9CInstance9SetHspeedEf> */
/* @0x1cb1ec b 0x1cb1a4 <_Z14Command_BounceP9CInstancebb+0x204> */
/* @0x1cb1f0 vadd.f32 s16, s16, s17 */
/* @0x1cb1f4 vldr s15, [pc, #52] */
/* @0x1cb1f8 mov r0, r4 */
/* @0x1cb1fc vadd.f32 s16, s16, s15 */
/* @0x1cb200 vsub.f32 s16, s16, s24 */
/* @0x1cb204 vmov r1, s16 */
/* @0x1cb208 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1cb20c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1cb210 b 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x1cb214 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1cb218 mov r0, r4 */
/* @0x1cb21c ldr r1, [r4, #0xe0] */
/* @0x1cb220 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1cb224 eor r1, r1, #-2147483648 */
/* @0x1cb228 b 0x1930f4 <_ZN9CInstance9SetHspeedEf> */
/* @0x1cb22c ldrdmi r0, r1, [r9], #-251 */
/* @0x1cb230 teqmi r4, #0 */

/* ── FUNC 0x1cb234 · RTree<CInstance*, int, float, 6, 2>::SearchLine(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Line*, int&, bool (*)(CInstance*, void*), void*) · size=348 · insn=87 */
/* @0x1cb234 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1cb238 mov r7, r1 */
/* @0x1cb23c ldr r1, [r1, #0x4] */
/* @0x1cb240 sub sp, sp, #12 */
/* @0x1cb244 mov r11, r0 */
/* @0x1cb248 mov r6, r2 */
/* @0x1cb24c cmp r1, #0 */
/* @0x1cb250 mov r8, r3 */
/* @0x1cb254 ldr r5, [r7] */
/* @0x1cb258 ldr r9, [sp, #0x34] */
/* @0x1cb25c ble 0x1cb2e0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xac> */
/* @0x1cb260 cmp r5, #0 */
/* @0x1cb264 ble 0x1cb2d4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xa0> */
/* @0x1cb268 add r4, r7, #8 */
/* @0x1cb26c mov r10, #0 */
/* @0x1cb270 b 0x1cb284 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x50> */
/* @0x1cb274 add r10, r10, #1 */
/* @0x1cb278 add r4, r4, #24 */
/* @0x1cb27c cmp r5, r10 */
/* @0x1cb280 ble 0x1cb2d4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xa0> */
/* @0x1cb284 mov r0, r6 */
/* @0x1cb288 mov r1, r4 */
/* @0x1cb28c bl 0x1c8870 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x13a0> */
/* @0x1cb290 cmp r0, #0 */
/* @0x1cb294 beq 0x1cb274 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x40> */
/* @0x1cb298 ldr r3, [sp, #0x30] */
/* @0x1cb29c mov r0, r11 */
/* @0x1cb2a0 ldr r1, [r4, #0x10] */
/* @0x1cb2a4 mov r2, r6 */
/* @0x1cb2a8 str r9, [sp, #0x4] */
/* @0x1cb2ac str r3, [sp] */
/* @0x1cb2b0 mov r3, r8 */
/* @0x1cb2b4 bl 0x1cb234 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_> */
/* @0x1cb2b8 cmp r0, #0 */
/* @0x1cb2bc beq 0x1cb34c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x118> */
/* @0x1cb2c0 ldr r5, [r7] */
/* @0x1cb2c4 add r10, r10, #1 */
/* @0x1cb2c8 add r4, r4, #24 */
/* @0x1cb2cc cmp r5, r10 */
/* @0x1cb2d0 bgt 0x1cb284 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x50> */
/* @0x1cb2d4 mov r0, #1 */
/* @0x1cb2d8 add sp, sp, #12 */
/* @0x1cb2dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1cb2e0 cmp r5, #0 */
/* @0x1cb2e4 ble 0x1cb2d4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xa0> */
/* @0x1cb2e8 ldr r3, [sp, #0x30] */
/* @0x1cb2ec add r4, r7, #8 */
/* @0x1cb2f0 cmp r3, #0 */
/* @0x1cb2f4 movne r11, #0 */
/* @0x1cb2f8 beq 0x1cb358 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x124> */
/* @0x1cb2fc mov r1, r4 */
/* @0x1cb300 mov r0, r6 */
/* @0x1cb304 bl 0x1c8870 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x13a0> */
/* @0x1cb308 mov r1, r9 */
/* @0x1cb30c cmp r0, #0 */
/* @0x1cb310 beq 0x1cb338 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x104> */
/* @0x1cb314 ldr r3, [r8] */
/* @0x1cb318 ldr r0, [r4, #0x14] */
/* @0x1cb31c add r3, r3, #1 */
/* @0x1cb320 str r3, [r8] */
/* @0x1cb324 ldr r3, [sp, #0x30] */
/* @0x1cb328 blx r3 */
/* @0x1cb32c cmp r0, #0 */
/* @0x1cb330 beq 0x1cb34c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x118> */
/* @0x1cb334 ldr r5, [r7] */
/* @0x1cb338 add r11, r11, #1 */
/* @0x1cb33c add r4, r4, #24 */
/* @0x1cb340 cmp r5, r11 */
/* @0x1cb344 bgt 0x1cb2fc <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xc8> */
/* @0x1cb348 b 0x1cb2d4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xa0> */
/* @0x1cb34c mov r0, #0 */
/* @0x1cb350 add sp, sp, #12 */
/* @0x1cb354 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1cb358 mov r10, r3 */
/* @0x1cb35c mov r1, r4 */
/* @0x1cb360 mov r0, r6 */
/* @0x1cb364 bl 0x1c8870 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x13a0> */
/* @0x1cb368 add r10, r10, #1 */
/* @0x1cb36c add r4, r4, #24 */
/* @0x1cb370 cmp r0, #0 */
/* @0x1cb374 ldrne r3, [r8] */
/* @0x1cb378 addne r3, r3, #1 */
/* @0x1cb37c strne r3, [r8] */
/* @0x1cb380 ldrne r5, [r7] */
/* @0x1cb384 cmp r10, r5 */
/* @0x1cb388 blt 0x1cb35c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0x128> */
/* @0x1cb38c b 0x1cb2d4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_+0xa0> */

/* ── FUNC 0x1cb390 · Command_CollisionLine(CInstance*, float, float, float, float, int, bool, bool) · size=996 · insn=249 */
/* @0x1cb390 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1cb394 vpush {d8} */
/* @0x1cb398 sub sp, sp, #84 */
/* @0x1cb39c vldr s16, [sp, #128] */
/* @0x1cb3a0 add lr, sp, #80 */
/* @0x1cb3a4 mov r11, r0 */
/* @0x1cb3a8 ldr r5, [sp, #0x84] */
/* @0x1cb3ac mov r9, r1 */
/* @0x1cb3b0 mov r4, #0 */
/* @0x1cb3b4 str r4, [lr, #-0x40]! */
/* @0x1cb3b8 mov r1, lr */
/* @0x1cb3bc mov r7, r3 */
/* @0x1cb3c0 mov r0, r5 */
/* @0x1cb3c4 mov r8, r2 */
/* @0x1cb3c8 ldrb r10, [sp, #0x88] */
/* @0x1cb3cc ldrb r6, [sp, #0x8c] */
/* @0x1cb3d0 bl 0x1c8df8 <_Z22ShouldUseFastCollisioniPP9CObjectGM> */
/* @0x1cb3d4 ldr r3, [pc, #0x378] */
/* @0x1cb3d8 add r3, pc, r3 */
/* @0x1cb3dc cmn r0, #1 */
/* @0x1cb3e0 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb3e4 cmp r0, #1 */
/* @0x1cb3e8 beq 0x1cb5b8 <_Z21Command_CollisionLineP9CInstanceffffibb+0x228> */
/* @0x1cb3ec cmn r5, #3 */
/* @0x1cb3f0 beq 0x1cb52c <_Z21Command_CollisionLineP9CInstanceffffibb+0x19c> */
/* @0x1cb3f4 movw r2, #0x869f */
/* @0x1cb3f8 movt r2, #0x1 */
/* @0x1cb3fc cmp r5, r2 */
/* @0x1cb400 bgt 0x1cb49c <_Z21Command_CollisionLineP9CInstanceffffibb+0x10c> */
/* @0x1cb404 ldr r2, [sp, #0x10] */
/* @0x1cb408 cmp r2, #0 */
/* @0x1cb40c beq 0x1cb6c0 <_Z21Command_CollisionLineP9CInstanceffffibb+0x330> */
/* @0x1cb410 ldr r4, [r2, #0xd0] */
/* @0x1cb414 cmp r4, #0 */
/* @0x1cb418 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb41c ldr r3, [r4, #0x8] */
/* @0x1cb420 cmp r3, #0 */
/* @0x1cb424 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb428 ldr r5, [r4, #0x8] */
/* @0x1cb42c ldr r4, [r4] */
/* @0x1cb430 cmp r11, r5 */
/* @0x1cb434 movne r3, #0 */
/* @0x1cb438 andeq r3, r6, #1 */
/* @0x1cb43c cmp r3, #0 */
/* @0x1cb440 bne 0x1cb414 <_Z21Command_CollisionLineP9CInstanceffffibb+0x84> */
/* @0x1cb444 ldrb r3, [r5, #0x68] */
/* @0x1cb448 cmp r3, #0 */
/* @0x1cb44c bne 0x1cb414 <_Z21Command_CollisionLineP9CInstanceffffibb+0x84> */
/* @0x1cb450 ldrb r3, [r5, #0x69] */
/* @0x1cb454 cmp r3, #0 */
/* @0x1cb458 bne 0x1cb414 <_Z21Command_CollisionLineP9CInstanceffffibb+0x84> */
/* @0x1cb45c vstr s16, [sp] */
/* @0x1cb460 str r10, [sp, #0x4] */
/* @0x1cb464 mov r0, r5 */
/* @0x1cb468 mov r1, r9 */
/* @0x1cb46c mov r2, r8 */
/* @0x1cb470 mov r3, r7 */
/* @0x1cb474 bl 0x194f28 <_ZN9CInstance14Collision_LineEffffb> */
/* @0x1cb478 cmp r0, #0 */
/* @0x1cb47c bne 0x1cb48c <_Z21Command_CollisionLineP9CInstanceffffibb+0xfc> */
/* @0x1cb480 cmp r4, #0 */
/* @0x1cb484 bne 0x1cb41c <_Z21Command_CollisionLineP9CInstanceffffibb+0x8c> */
/* @0x1cb488 mov r5, #0 */
/* @0x1cb48c mov r0, r5 */
/* @0x1cb490 add sp, sp, #84 */
/* @0x1cb494 vpop {d8} */
/* @0x1cb498 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1cb49c cmp r6, #0 */
/* @0x1cb4a0 bne 0x1cb5a8 <_Z21Command_CollisionLineP9CInstanceffffibb+0x218> */
/* @0x1cb4a4 ldr r2, [pc, #0x2ac] */
/* @0x1cb4a8 ldr r3, [r3, r2] */
/* @0x1cb4ac ldr r2, [r3, #0x4] */
/* @0x1cb4b0 ldr r3, [r3] */
/* @0x1cb4b4 and r2, r5, r2 */
/* @0x1cb4b8 ldr r3, [r3, r2, lsl #3] */
/* @0x1cb4bc cmp r3, #0 */
/* @0x1cb4c0 bne 0x1cb4d4 <_Z21Command_CollisionLineP9CInstanceffffibb+0x144> */
/* @0x1cb4c4 b 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb4c8 ldr r3, [r3, #0x4] */
/* @0x1cb4cc cmp r3, #0 */
/* @0x1cb4d0 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb4d4 ldr r2, [r3, #0x8] */
/* @0x1cb4d8 cmp r5, r2 */
/* @0x1cb4dc bne 0x1cb4c8 <_Z21Command_CollisionLineP9CInstanceffffibb+0x138> */
/* @0x1cb4e0 ldr r5, [r3, #0xc] */
/* @0x1cb4e4 cmp r5, #0 */
/* @0x1cb4e8 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb4ec ldrb r3, [r5, #0x68] */
/* @0x1cb4f0 cmp r3, #0 */
/* @0x1cb4f4 bne 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb4f8 ldrb r3, [r5, #0x69] */
/* @0x1cb4fc cmp r3, #0 */
/* @0x1cb500 bne 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb504 vstr s16, [sp] */
/* @0x1cb508 str r10, [sp, #0x4] */
/* @0x1cb50c mov r1, r9 */
/* @0x1cb510 mov r0, r5 */
/* @0x1cb514 mov r2, r8 */
/* @0x1cb518 mov r3, r7 */
/* @0x1cb51c bl 0x194f28 <_ZN9CInstance14Collision_LineEffffb> */
/* @0x1cb520 cmp r0, #0 */
/* @0x1cb524 bne 0x1cb48c <_Z21Command_CollisionLineP9CInstanceffffibb+0xfc> */
/* @0x1cb528 b 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb52c ldr r2, [pc, #0x228] */
/* @0x1cb530 ldr r3, [r3, r2] */
/* @0x1cb534 ldr r3, [r3] */
/* @0x1cb538 ldr r5, [r3, #0x80] */
/* @0x1cb53c cmp r5, #0 */
/* @0x1cb540 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb544 cmp r11, r5 */
/* @0x1cb548 movne r3, #0 */
/* @0x1cb54c andeq r3, r6, #1 */
/* @0x1cb550 ldr r4, [r5, #0x178] */
/* @0x1cb554 cmp r3, #0 */
/* @0x1cb558 bne 0x1cb598 <_Z21Command_CollisionLineP9CInstanceffffibb+0x208> */
/* @0x1cb55c ldrb r3, [r5, #0x68] */
/* @0x1cb560 cmp r3, #0 */
/* @0x1cb564 bne 0x1cb598 <_Z21Command_CollisionLineP9CInstanceffffibb+0x208> */
/* @0x1cb568 ldrb r3, [r5, #0x69] */
/* @0x1cb56c cmp r3, #0 */
/* @0x1cb570 bne 0x1cb598 <_Z21Command_CollisionLineP9CInstanceffffibb+0x208> */
/* @0x1cb574 vstr s16, [sp] */
/* @0x1cb578 str r10, [sp, #0x4] */
/* @0x1cb57c mov r0, r5 */
/* @0x1cb580 mov r1, r9 */
/* @0x1cb584 mov r2, r8 */
/* @0x1cb588 mov r3, r7 */
/* @0x1cb58c bl 0x194f28 <_ZN9CInstance14Collision_LineEffffb> */
/* @0x1cb590 cmp r0, #0 */
/* @0x1cb594 bne 0x1cb48c <_Z21Command_CollisionLineP9CInstanceffffibb+0xfc> */
/* @0x1cb598 cmp r4, #0 */
/* @0x1cb59c mov r5, r4 */
/* @0x1cb5a0 bne 0x1cb544 <_Z21Command_CollisionLineP9CInstanceffffibb+0x1b4> */
/* @0x1cb5a4 b 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb5a8 ldr r2, [r11, #0x78] */
/* @0x1cb5ac cmp r5, r2 */
/* @0x1cb5b0 bne 0x1cb4a4 <_Z21Command_CollisionLineP9CInstanceffffibb+0x114> */
/* @0x1cb5b4 b 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb5b8 str r3, [sp, #0x8] */
/* @0x1cb5bc bl 0x1cc24c <_Z10UpdateTreev> */
/* @0x1cb5c0 vmov s11, r9 */
/* @0x1cb5c4 ldr r3, [sp, #0x8] */
/* @0x1cb5c8 ldr r0, [pc, #0x190] */
/* @0x1cb5cc vcvt.f64.f32 d6, s11 */
/* @0x1cb5d0 ldr r1, [pc, #0x18c] */
/* @0x1cb5d4 vmov s11, r8 */
/* @0x1cb5d8 ldr r2, [pc, #0x188] */
/* @0x1cb5dc ldr r0, [r3, r0] */
/* @0x1cb5e0 add r1, pc, r1 */
/* @0x1cb5e4 strb r10, [sp, #0x48] */
/* @0x1cb5e8 strb r6, [sp, #0x49] */
/* @0x1cb5ec str r0, [sp, #0xc] */
/* @0x1cb5f0 str r4, [r0] */
/* @0x1cb5f4 vcvt.f64.f32 d7, s11 */
/* @0x1cb5f8 vstr d6, [sp, #40] */
/* @0x1cb5fc vmov s11, r7 */
/* @0x1cb600 str r11, [sp, #0x4c] */
/* @0x1cb604 str r5, [r1] */
/* @0x1cb608 vcvt.f64.f32 d6, s11 */
/* @0x1cb60c vstr d7, [sp, #48] */
/* @0x1cb610 vstr d6, [sp, #56] */
/* @0x1cb614 vmov s13, r9 */
/* @0x1cb618 vcvt.s32.f32 s11, s11 */
/* @0x1cb61c vcvt.s32.f32 s13, s13 */
/* @0x1cb620 vmov r7, s11 */
/* @0x1cb624 vmov r9, s13 */
/* @0x1cb628 vcvt.f64.f32 d7, s16 */
/* @0x1cb62c vstr d7, [sp, #64] */
/* @0x1cb630 ldr r3, [r3, r2] */
/* @0x1cb634 vmov s14, r8 */
/* @0x1cb638 vcvt.s32.f32 s16, s16 */
/* @0x1cb63c ldr r0, [r3] */
/* @0x1cb640 vcvt.s32.f32 s15, s14 */
/* @0x1cb644 cmp r9, r7 */
/* @0x1cb648 blt 0x1cb714 <_Z21Command_CollisionLineP9CInstanceffffibb+0x384> */
/* @0x1cb64c vmov r2, s15 */
/* @0x1cb650 rsb r9, r7, r9 */
/* @0x1cb654 vmov r3, s16 */
/* @0x1cb658 vmov s11, r9 */
/* @0x1cb65c vcvt.f32.s32 s16, s16 */
/* @0x1cb660 vcvt.f32.s32 s13, s11 */
/* @0x1cb664 vstr s16, [sp, #28] */
/* @0x1cb668 vstr s13, [sp, #32] */
/* @0x1cb66c vmov s13, r7 */
/* @0x1cb670 rsb r2, r3, r2 */
/* @0x1cb674 vmov s15, r2 */
/* @0x1cb678 vcvt.f32.s32 s14, s15 */
/* @0x1cb67c vcvt.f32.s32 s15, s13 */
/* @0x1cb680 vstr s14, [sp, #36] */
/* @0x1cb684 vstr s15, [sp, #24] */
/* @0x1cb688 ldr r12, [pc, #0xdc] */
/* @0x1cb68c add r3, sp, #40 */
/* @0x1cb690 ldr r1, [r0, #0x10] */
/* @0x1cb694 add r2, sp, #24 */
/* @0x1cb698 add r12, pc, r12 */
/* @0x1cb69c str r3, [sp, #0x4] */
/* @0x1cb6a0 str r12, [sp] */
/* @0x1cb6a4 add r3, sp, #20 */
/* @0x1cb6a8 mov r12, #0 */
/* @0x1cb6ac str r12, [sp, #0x14] */
/* @0x1cb6b0 bl 0x1cb234 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10SearchLineEPNS2_4NodeEPNS2_4LineERiPFbS1_PvES8_> */
/* @0x1cb6b4 ldr r0, [sp, #0xc] */
/* @0x1cb6b8 ldr r5, [r0] */
/* @0x1cb6bc b 0x1cb48c <_Z21Command_CollisionLineP9CInstanceffffibb+0xfc> */
/* @0x1cb6c0 ldr r2, [pc, #0xa8] */
/* @0x1cb6c4 ldr r3, [r3, r2] */
/* @0x1cb6c8 ldr r3, [r3] */
/* @0x1cb6cc ldr r2, [r3, #0x4] */
/* @0x1cb6d0 ldr r3, [r3] */
/* @0x1cb6d4 and r2, r5, r2 */
/* @0x1cb6d8 ldr r3, [r3, r2, lsl #3] */
/* @0x1cb6dc cmp r3, #0 */
/* @0x1cb6e0 bne 0x1cb6f4 <_Z21Command_CollisionLineP9CInstanceffffibb+0x364> */
/* @0x1cb6e4 b 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb6e8 ldr r3, [r3, #0x4] */
/* @0x1cb6ec cmp r3, #0 */
/* @0x1cb6f0 beq 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb6f4 ldr r2, [r3, #0x8] */
/* @0x1cb6f8 cmp r5, r2 */
/* @0x1cb6fc bne 0x1cb6e8 <_Z21Command_CollisionLineP9CInstanceffffibb+0x358> */
/* @0x1cb700 ldr r2, [r3, #0xc] */
/* @0x1cb704 cmp r2, #0 */
/* @0x1cb708 str r2, [sp, #0x10] */
/* @0x1cb70c bne 0x1cb410 <_Z21Command_CollisionLineP9CInstanceffffibb+0x80> */
/* @0x1cb710 b 0x1cb488 <_Z21Command_CollisionLineP9CInstanceffffibb+0xf8> */
/* @0x1cb714 vmov r2, s16 */
/* @0x1cb718 rsb r7, r9, r7 */
/* @0x1cb71c vmov r3, s15 */
/* @0x1cb720 vmov s11, r7 */
/* @0x1cb724 vcvt.f32.s32 s15, s15 */
/* @0x1cb728 vcvt.f32.s32 s13, s11 */
/* @0x1cb72c vstr s15, [sp, #28] */
/* @0x1cb730 vstr s13, [sp, #32] */
/* @0x1cb734 vmov s13, r9 */
/* @0x1cb738 vcvt.f32.s32 s15, s13 */
/* @0x1cb73c rsb r2, r3, r2 */
/* @0x1cb740 vmov s16, r2 */
/* @0x1cb744 vcvt.f32.s32 s14, s16 */
/* @0x1cb748 vstr s15, [sp, #24] */
/* @0x1cb74c vstr s14, [sp, #36] */
/* @0x1cb750 b 0x1cb688 <_Z21Command_CollisionLineP9CInstanceffffibb+0x2f8> */
/* @0x1cb754 eoreq r6, r2, r8, ror r8 */
/* @0x1cb758 .word 0xffffbff4 */
/* @0x1cb75c .word 0xffffbcd8 */
/* @0x1cb760 .word 0xffffeeb8 */
/* @0x1cb764 eoreq r9, r2, r0, lsl #22 */
/* @0x1cb768 .word 0xffffc5f4 */
/* @0x1cb76c .word 0xffffce64 */
/* @0x1cb770 .word 0xffffbfec */
