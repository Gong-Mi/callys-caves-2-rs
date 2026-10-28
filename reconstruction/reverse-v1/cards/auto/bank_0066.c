/* libyoyo.so 覆盖卡组 0066
 * 函数 0x13445c..0x1351b8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x13445c · F_SoundEffectReverb(RValue&, CInstance*, CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x13445c ldr r3, [pc, #0xd0] */
/* @0x134460 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x134464 ldr r3, [pc, r3] */
/* @0x134468 sub sp, sp, #28 */
/* @0x13446c ldrb r3, [r3] */
/* @0x134470 ldr r10, [sp, #0x40] */
/* @0x134474 cmp r3, #0 */
/* @0x134478 bne 0x134490 <_Z19F_SoundEffectReverbR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x13447c ldr r3, [pc, #0xb4] */
/* @0x134480 ldr r3, [pc, r3] */
/* @0x134484 ldrb r1, [r3] */
/* @0x134488 cmp r1, #0 */
/* @0x13448c beq 0x134498 <_Z19F_SoundEffectReverbR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x134490 add sp, sp, #28 */
/* @0x134494 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x134498 mov r0, r10 */
/* @0x13449c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1344a0 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x1344a4 subs r1, r0, #0 */
/* @0x1344a8 beq 0x134520 <_Z19F_SoundEffectReverbR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x1344ac bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x1344b0 mov r1, #1 */
/* @0x1344b4 mov r11, r0 */
/* @0x1344b8 mov r0, r10 */
/* @0x1344bc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1344c0 mov r4, r0 */
/* @0x1344c4 mov r5, r1 */
/* @0x1344c8 mov r0, r10 */
/* @0x1344cc mov r1, #2 */
/* @0x1344d0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1344d4 mov r8, r0 */
/* @0x1344d8 mov r9, r1 */
/* @0x1344dc mov r0, r10 */
/* @0x1344e0 mov r1, #3 */
/* @0x1344e4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1344e8 mov r6, r0 */
/* @0x1344ec mov r7, r1 */
/* @0x1344f0 mov r0, r10 */
/* @0x1344f4 mov r1, #4 */
/* @0x1344f8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1344fc strd r8, r9, [sp] */
/* @0x134500 strd r6, r7, [sp, #8] */
/* @0x134504 mov r2, r4 */
/* @0x134508 mov r3, r5 */
/* @0x13450c strd r0, r1, [sp, #16] */
/* @0x134510 mov r0, r11 */
/* @0x134514 bl 0x21f154 <_Z21SND_Set_Effect_Reverbidddd> */
/* @0x134518 add sp, sp, #28 */
/* @0x13451c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x134520 ldr r0, [pc, #0x14] */
/* @0x134524 add r0, pc, r0 */
/* @0x134528 add sp, sp, #28 */
/* @0x13452c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x134530 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x134534 eoreq r10, r11, r12, asr #17 */
/* @0x134538 eoreq r10, r11, r12, asr #23 */
/* @0x13453c eoreq r10, r0, r8, ror #30 */

/* ── FUNC 0x134540 · F_Sound3DSetSoundPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x134540 ldr r3, [pc, #0xb8] */
/* @0x134544 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x134548 ldr r3, [pc, r3] */
/* @0x13454c sub sp, sp, #20 */
/* @0x134550 ldrb r3, [r3] */
/* @0x134554 ldr r8, [sp, #0x30] */
/* @0x134558 cmp r3, #0 */
/* @0x13455c bne 0x134574 <_Z25F_Sound3DSetSoundPositionR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x134560 ldr r3, [pc, #0x9c] */
/* @0x134564 ldr r3, [pc, r3] */
/* @0x134568 ldrb r1, [r3] */
/* @0x13456c cmp r1, #0 */
/* @0x134570 beq 0x13457c <_Z25F_Sound3DSetSoundPositionR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x134574 add sp, sp, #20 */
/* @0x134578 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x13457c mov r0, r8 */
/* @0x134580 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134584 bl 0x21fcd4 <_Z10Sound_Datai> */
/* @0x134588 subs r1, r0, #0 */
/* @0x13458c beq 0x1345ec <_Z25F_Sound3DSetSoundPositionR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x134590 bl 0x215748 <_ZN6CSound10GetSoundIdEv> */
/* @0x134594 mov r1, #1 */
/* @0x134598 mov r9, r0 */
/* @0x13459c mov r0, r8 */
/* @0x1345a0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1345a4 mov r4, r0 */
/* @0x1345a8 mov r5, r1 */
/* @0x1345ac mov r0, r8 */
/* @0x1345b0 mov r1, #2 */
/* @0x1345b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1345b8 mov r6, r0 */
/* @0x1345bc mov r7, r1 */
/* @0x1345c0 mov r0, r8 */
/* @0x1345c4 mov r1, #3 */
/* @0x1345c8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1345cc strd r6, r7, [sp] */
/* @0x1345d0 mov r2, r4 */
/* @0x1345d4 mov r3, r5 */
/* @0x1345d8 strd r0, r1, [sp, #8] */
/* @0x1345dc mov r0, r9 */
/* @0x1345e0 bl 0x21f16c <_Z25SND_3D_Set_Sound_Positioniddd> */
/* @0x1345e4 add sp, sp, #20 */
/* @0x1345e8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1345ec ldr r0, [pc, #0x14] */
/* @0x1345f0 add r0, pc, r0 */
/* @0x1345f4 add sp, sp, #20 */
/* @0x1345f8 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1345fc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x134600 eoreq r10, r11, r8, ror #15 */
/* @0x134604 eoreq r10, r11, r8, ror #21 */
/* @0x134608 mlaeq r0, r12, lr, r10 */

/* ── FUNC 0x13460c · F_AudioSetListenerPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x13460c ldr r3, [pc, #0x6c] */
/* @0x134610 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x134614 ldr r3, [pc, r3] */
/* @0x134618 sub sp, sp, #20 */
/* @0x13461c ldrb r8, [r3] */
/* @0x134620 ldr r9, [sp, #0x30] */
/* @0x134624 cmp r8, #0 */
/* @0x134628 bne 0x134678 <_Z26F_AudioSetListenerPositionR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x13462c mov r0, r9 */
/* @0x134630 mov r1, r8 */
/* @0x134634 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134638 mov r4, r0 */
/* @0x13463c mov r5, r1 */
/* @0x134640 mov r0, r9 */
/* @0x134644 mov r1, #1 */
/* @0x134648 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13464c mov r6, r0 */
/* @0x134650 mov r7, r1 */
/* @0x134654 mov r0, r9 */
/* @0x134658 mov r1, #2 */
/* @0x13465c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134660 strd r6, r7, [sp] */
/* @0x134664 mov r2, r4 */
/* @0x134668 mov r3, r5 */
/* @0x13466c strd r0, r1, [sp, #8] */
/* @0x134670 mov r0, r8 */
/* @0x134674 bl 0x2165c0 <_Z25Audio_SetListenerPositioniddd> */
/* @0x134678 add sp, sp, #20 */
/* @0x13467c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x134680 eoreq r10, r11, r8, lsr r10 */

/* ── FUNC 0x134684 · F_AudioSetListenerPositionN(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x134684 ldr r3, [pc, #0x78] */
/* @0x134688 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x13468c ldr r3, [pc, r3] */
/* @0x134690 sub sp, sp, #20 */
/* @0x134694 ldrb r1, [r3] */
/* @0x134698 ldr r8, [sp, #0x30] */
/* @0x13469c cmp r1, #0 */
/* @0x1346a0 bne 0x1346fc <_Z27F_AudioSetListenerPositionNR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1346a4 mov r0, r8 */
/* @0x1346a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1346ac mov r1, #1 */
/* @0x1346b0 mov r9, r0 */
/* @0x1346b4 mov r0, r8 */
/* @0x1346b8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1346bc mov r4, r0 */
/* @0x1346c0 mov r5, r1 */
/* @0x1346c4 mov r0, r8 */
/* @0x1346c8 mov r1, #2 */
/* @0x1346cc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1346d0 mov r6, r0 */
/* @0x1346d4 mov r7, r1 */
/* @0x1346d8 mov r0, r8 */
/* @0x1346dc mov r1, #3 */
/* @0x1346e0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1346e4 strd r6, r7, [sp] */
/* @0x1346e8 mov r2, r4 */
/* @0x1346ec mov r3, r5 */
/* @0x1346f0 strd r0, r1, [sp, #8] */
/* @0x1346f4 mov r0, r9 */
/* @0x1346f8 bl 0x2165c0 <_Z25Audio_SetListenerPositioniddd> */
/* @0x1346fc add sp, sp, #20 */
/* @0x134700 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x134704 eoreq r10, r11, r0, asr #19 */

/* ── FUNC 0x134708 · F_AudioSetListenerVelocity(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x134708 ldr r3, [pc, #0x6c] */
/* @0x13470c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x134710 ldr r3, [pc, r3] */
/* @0x134714 sub sp, sp, #20 */
/* @0x134718 ldrb r8, [r3] */
/* @0x13471c ldr r9, [sp, #0x30] */
/* @0x134720 cmp r8, #0 */
/* @0x134724 bne 0x134774 <_Z26F_AudioSetListenerVelocityR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x134728 mov r0, r9 */
/* @0x13472c mov r1, r8 */
/* @0x134730 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134734 mov r4, r0 */
/* @0x134738 mov r5, r1 */
/* @0x13473c mov r0, r9 */
/* @0x134740 mov r1, #1 */
/* @0x134744 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134748 mov r6, r0 */
/* @0x13474c mov r7, r1 */
/* @0x134750 mov r0, r9 */
/* @0x134754 mov r1, #2 */
/* @0x134758 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13475c strd r6, r7, [sp] */
/* @0x134760 mov r2, r4 */
/* @0x134764 mov r3, r5 */
/* @0x134768 strd r0, r1, [sp, #8] */
/* @0x13476c mov r0, r8 */
/* @0x134770 bl 0x216608 <_Z25Audio_SetListenerVelocityiddd> */
/* @0x134774 add sp, sp, #20 */
/* @0x134778 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x13477c eoreq r10, r11, r12, lsr r9 */

/* ── FUNC 0x134780 · F_AudioSetListenerVelocityN(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x134780 ldr r3, [pc, #0x78] */
/* @0x134784 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x134788 ldr r3, [pc, r3] */
/* @0x13478c sub sp, sp, #20 */
/* @0x134790 ldrb r1, [r3] */
/* @0x134794 ldr r8, [sp, #0x30] */
/* @0x134798 cmp r1, #0 */
/* @0x13479c bne 0x1347f8 <_Z27F_AudioSetListenerVelocityNR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1347a0 mov r0, r8 */
/* @0x1347a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1347a8 mov r1, #1 */
/* @0x1347ac mov r9, r0 */
/* @0x1347b0 mov r0, r8 */
/* @0x1347b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1347b8 mov r4, r0 */
/* @0x1347bc mov r5, r1 */
/* @0x1347c0 mov r0, r8 */
/* @0x1347c4 mov r1, #2 */
/* @0x1347c8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1347cc mov r6, r0 */
/* @0x1347d0 mov r7, r1 */
/* @0x1347d4 mov r0, r8 */
/* @0x1347d8 mov r1, #3 */
/* @0x1347dc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1347e0 strd r6, r7, [sp] */
/* @0x1347e4 mov r2, r4 */
/* @0x1347e8 mov r3, r5 */
/* @0x1347ec strd r0, r1, [sp, #8] */
/* @0x1347f0 mov r0, r9 */
/* @0x1347f4 bl 0x216608 <_Z25Audio_SetListenerVelocityiddd> */
/* @0x1347f8 add sp, sp, #20 */
/* @0x1347fc pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x134800 eoreq r10, r11, r4, asr #17 */

/* ── FUNC 0x134804 · F_AudioSetListenerOrientation(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x134804 ldr r3, [pc, #0xbc] */
/* @0x134808 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13480c ldr r3, [pc, r3] */
/* @0x134810 sub sp, sp, #60 */
/* @0x134814 ldrb r11, [r3] */
/* @0x134818 ldr r10, [sp, #0x60] */
/* @0x13481c cmp r11, #0 */
/* @0x134820 bne 0x1348c0 <_Z29F_AudioSetListenerOrientationR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x134824 mov r0, r10 */
/* @0x134828 mov r1, r11 */
/* @0x13482c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134830 mov r2, r0 */
/* @0x134834 mov r3, r1 */
/* @0x134838 mov r0, r10 */
/* @0x13483c mov r1, #1 */
/* @0x134840 str r2, [sp, #0x2c] */
/* @0x134844 str r3, [sp, #0x28] */
/* @0x134848 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13484c mov r8, r0 */
/* @0x134850 mov r9, r1 */
/* @0x134854 mov r0, r10 */
/* @0x134858 mov r1, #2 */
/* @0x13485c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134860 mov r6, r0 */
/* @0x134864 mov r7, r1 */
/* @0x134868 mov r0, r10 */
/* @0x13486c mov r1, #3 */
/* @0x134870 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134874 mov r4, r0 */
/* @0x134878 mov r5, r1 */
/* @0x13487c mov r0, r10 */
/* @0x134880 mov r1, #4 */
/* @0x134884 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134888 strd r0, r1, [sp, #48] */
/* @0x13488c mov r0, r10 */
/* @0x134890 mov r1, #5 */
/* @0x134894 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134898 vldr d7, [sp, #48] */
/* @0x13489c strd r8, r9, [sp] */
/* @0x1348a0 vstr d7, [sp, #24] */
/* @0x1348a4 strd r6, r7, [sp, #8] */
/* @0x1348a8 strd r4, r5, [sp, #16] */
/* @0x1348ac ldr r2, [sp, #0x2c] */
/* @0x1348b0 ldr r3, [sp, #0x28] */
/* @0x1348b4 strd r0, r1, [sp, #32] */
/* @0x1348b8 mov r0, r11 */
/* @0x1348bc bl 0x216650 <_Z28Audio_SetListenerOrientationidddddd> */
/* @0x1348c0 add sp, sp, #60 */
/* @0x1348c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1348c8 eoreq r10, r11, r0, asr #16 */

/* ── FUNC 0x1348cc · F_AudioSetListenerOrientationN(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x1348cc ldr r3, [pc, #0xc8] */
/* @0x1348d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1348d4 ldr r3, [pc, r3] */
/* @0x1348d8 sub sp, sp, #60 */
/* @0x1348dc ldrb r1, [r3] */
/* @0x1348e0 ldr r10, [sp, #0x60] */
/* @0x1348e4 cmp r1, #0 */
/* @0x1348e8 bne 0x134994 <_Z30F_AudioSetListenerOrientationNR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x1348ec mov r0, r10 */
/* @0x1348f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1348f4 mov r1, #1 */
/* @0x1348f8 mov r11, r0 */
/* @0x1348fc mov r0, r10 */
/* @0x134900 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134904 mov r2, r0 */
/* @0x134908 mov r3, r1 */
/* @0x13490c mov r0, r10 */
/* @0x134910 mov r1, #2 */
/* @0x134914 str r2, [sp, #0x2c] */
/* @0x134918 str r3, [sp, #0x28] */
/* @0x13491c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134920 mov r8, r0 */
/* @0x134924 mov r9, r1 */
/* @0x134928 mov r0, r10 */
/* @0x13492c mov r1, #3 */
/* @0x134930 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134934 mov r6, r0 */
/* @0x134938 mov r7, r1 */
/* @0x13493c mov r0, r10 */
/* @0x134940 mov r1, #4 */
/* @0x134944 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134948 mov r4, r0 */
/* @0x13494c mov r5, r1 */
/* @0x134950 mov r0, r10 */
/* @0x134954 mov r1, #5 */
/* @0x134958 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13495c strd r0, r1, [sp, #48] */
/* @0x134960 mov r0, r10 */
/* @0x134964 mov r1, #6 */
/* @0x134968 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13496c vldr d7, [sp, #48] */
/* @0x134970 strd r8, r9, [sp] */
/* @0x134974 vstr d7, [sp, #24] */
/* @0x134978 strd r6, r7, [sp, #8] */
/* @0x13497c strd r4, r5, [sp, #16] */
/* @0x134980 ldr r2, [sp, #0x2c] */
/* @0x134984 ldr r3, [sp, #0x28] */
/* @0x134988 strd r0, r1, [sp, #32] */
/* @0x13498c mov r0, r11 */
/* @0x134990 bl 0x216650 <_Z28Audio_SetListenerOrientationidddddd> */
/* @0x134994 add sp, sp, #60 */
/* @0x134998 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13499c eoreq r10, r11, r8, ror r7 */

/* ── FUNC 0x1349a0 · F_AudioSystem(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1349a0 ldr r3, [pc, #0x38] */
/* @0x1349a4 push {r4, lr} */
/* @0x1349a8 ldr r3, [pc, r3] */
/* @0x1349ac mov r4, r0 */
/* @0x1349b0 ldrb r3, [r3] */
/* @0x1349b4 cmp r3, #0 */
/* @0x1349b8 popne {r4, pc} */
/* @0x1349bc str r3, [r0, #0xc] */
/* @0x1349c0 bl 0x216998 <_Z11Audio_Modelv> */
/* @0x1349c4 vmov s15, r0 */
/* @0x1349c8 vcvt.f64.s32 d7, s15 */
/* @0x1349cc vmov r0, r1, d7 */
/* @0x1349d0 vmov r2, s14 */
/* @0x1349d4 mov r3, r1 */
/* @0x1349d8 stm r4, {r2, r3} */
/* @0x1349dc pop {r4, pc} */
/* @0x1349e0 eoreq r10, r11, r4, lsr #13 */

/* ── FUNC 0x1349e4 · F_AudioCreateEmitter(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1349e4 ldr r3, [pc, #0x38] */
/* @0x1349e8 push {r4, lr} */
/* @0x1349ec ldr r3, [pc, r3] */
/* @0x1349f0 mov r4, r0 */
/* @0x1349f4 ldrb r3, [r3] */
/* @0x1349f8 cmp r3, #0 */
/* @0x1349fc popne {r4, pc} */
/* @0x134a00 str r3, [r0, #0xc] */
/* @0x134a04 bl 0x2169ac <_Z19Audio_CreateEmitterv> */
/* @0x134a08 vmov s15, r0 */
/* @0x134a0c vcvt.f64.s32 d7, s15 */
/* @0x134a10 vmov r0, r1, d7 */
/* @0x134a14 vmov r2, s14 */
/* @0x134a18 mov r3, r1 */
/* @0x134a1c stm r4, {r2, r3} */
/* @0x134a20 pop {r4, pc} */
/* @0x134a24 eoreq r10, r11, r0, ror #12 */

/* ── FUNC 0x134a28 · F_AudioReleaseEmitter(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x134a28 push {r3, lr} */
/* @0x134a2c ldr r3, [pc, #0x1c] */
/* @0x134a30 ldr r0, [sp, #0x8] */
/* @0x134a34 ldr r3, [pc, r3] */
/* @0x134a38 ldrb r1, [r3] */
/* @0x134a3c cmp r1, #0 */
/* @0x134a40 popne {r3, pc} */
/* @0x134a44 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134a48 pop {r3, lr} */
/* @0x134a4c b 0x21a2f8 <_Z20Audio_ReleaseEmitteri> */
/* @0x134a50 eoreq r10, r11, r8, lsl r6 */

/* ── FUNC 0x134a54 · F_AudioSetEmitterPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x134a54 ldr r3, [pc, #0x78] */
/* @0x134a58 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x134a5c ldr r3, [pc, r3] */
/* @0x134a60 sub sp, sp, #20 */
/* @0x134a64 ldrb r1, [r3] */
/* @0x134a68 ldr r8, [sp, #0x30] */
/* @0x134a6c cmp r1, #0 */
/* @0x134a70 bne 0x134acc <_Z25F_AudioSetEmitterPositionR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x134a74 mov r0, r8 */
/* @0x134a78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134a7c mov r1, #1 */
/* @0x134a80 mov r9, r0 */
/* @0x134a84 mov r0, r8 */
/* @0x134a88 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134a8c mov r4, r0 */
/* @0x134a90 mov r5, r1 */
/* @0x134a94 mov r0, r8 */
/* @0x134a98 mov r1, #2 */
/* @0x134a9c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134aa0 mov r6, r0 */
/* @0x134aa4 mov r7, r1 */
/* @0x134aa8 mov r0, r8 */
/* @0x134aac mov r1, #3 */
/* @0x134ab0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134ab4 strd r6, r7, [sp] */
/* @0x134ab8 mov r2, r4 */
/* @0x134abc mov r3, r5 */
/* @0x134ac0 strd r0, r1, [sp, #8] */
/* @0x134ac4 mov r0, r9 */
/* @0x134ac8 bl 0x216df8 <_Z24Audio_SetEmitterPositioniddd> */
/* @0x134acc add sp, sp, #20 */
/* @0x134ad0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x134ad4 .word 0x002ba5f0 */

/* ── FUNC 0x134ad8 · F_AudioSetEmitterVelocity(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x134ad8 ldr r3, [pc, #0x78] */
/* @0x134adc push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x134ae0 ldr r3, [pc, r3] */
/* @0x134ae4 sub sp, sp, #20 */
/* @0x134ae8 ldrb r1, [r3] */
/* @0x134aec ldr r8, [sp, #0x30] */
/* @0x134af0 cmp r1, #0 */
/* @0x134af4 bne 0x134b50 <_Z25F_AudioSetEmitterVelocityR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x134af8 mov r0, r8 */
/* @0x134afc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134b00 mov r1, #1 */
/* @0x134b04 mov r9, r0 */
/* @0x134b08 mov r0, r8 */
/* @0x134b0c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134b10 mov r4, r0 */
/* @0x134b14 mov r5, r1 */
/* @0x134b18 mov r0, r8 */
/* @0x134b1c mov r1, #2 */
/* @0x134b20 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134b24 mov r6, r0 */
/* @0x134b28 mov r7, r1 */
/* @0x134b2c mov r0, r8 */
/* @0x134b30 mov r1, #3 */
/* @0x134b34 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134b38 strd r6, r7, [sp] */
/* @0x134b3c mov r2, r4 */
/* @0x134b40 mov r3, r5 */
/* @0x134b44 strd r0, r1, [sp, #8] */
/* @0x134b48 mov r0, r9 */
/* @0x134b4c bl 0x216ed8 <_Z24Audio_SetEmitterVelocityiddd> */
/* @0x134b50 add sp, sp, #20 */
/* @0x134b54 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x134b58 eoreq r10, r11, r12, ror #10 */

/* ── FUNC 0x134b5c · F_AudioPlaySound(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x134b5c ldr r3, [pc, #0x80] */
/* @0x134b60 push {r4, r5, r6, r7, r8, lr} */
/* @0x134b64 ldr r3, [pc, r3] */
/* @0x134b68 sub sp, sp, #8 */
/* @0x134b6c mov r7, r0 */
/* @0x134b70 ldrb r1, [r3] */
/* @0x134b74 ldr r6, [sp, #0x20] */
/* @0x134b78 cmp r1, #0 */
/* @0x134b7c bne 0x134bdc <_Z16F_AudioPlaySoundR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x134b80 str r1, [r0, #0xc] */
/* @0x134b84 mov r0, r6 */
/* @0x134b88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134b8c mov r1, #1 */
/* @0x134b90 mov r8, r0 */
/* @0x134b94 mov r0, r6 */
/* @0x134b98 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134b9c mov r4, r0 */
/* @0x134ba0 mov r5, r1 */
/* @0x134ba4 mov r0, r6 */
/* @0x134ba8 mov r1, #2 */
/* @0x134bac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134bb0 mov r2, r4 */
/* @0x134bb4 mov r3, r5 */
/* @0x134bb8 str r0, [sp] */
/* @0x134bbc mov r0, r8 */
/* @0x134bc0 bl 0x21b5d8 <_Z15Audio_PlaySoundidi> */
/* @0x134bc4 vmov s15, r0 */
/* @0x134bc8 vcvt.f64.s32 d7, s15 */
/* @0x134bcc vmov r0, r1, d7 */
/* @0x134bd0 vmov r2, s14 */
/* @0x134bd4 mov r3, r1 */
/* @0x134bd8 stm r7, {r2, r3} */
/* @0x134bdc add sp, sp, #8 */
/* @0x134be0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x134be4 eoreq r10, r11, r8, ror #9 */

/* ── FUNC 0x134be8 · F_Audio_SetFalloff(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x134be8 push {r3, lr} */
/* @0x134bec ldr r3, [pc, #0x1c] */
/* @0x134bf0 ldr r0, [sp, #0x8] */
/* @0x134bf4 ldr r3, [pc, r3] */
/* @0x134bf8 ldrb r1, [r3] */
/* @0x134bfc cmp r1, #0 */
/* @0x134c00 popne {r3, pc} */
/* @0x134c04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134c08 pop {r3, lr} */
/* @0x134c0c b 0x217a80 <_Z16Audio_FalloffSeti> */
/* @0x134c10 eoreq r10, r11, r8, asr r4 */

/* ── FUNC 0x134c14 · F_AudioPlaySoundOn(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0x134c14 ldr r3, [pc, #0x8c] */
/* @0x134c18 push {r4, r5, r6, r7, r8, lr} */
/* @0x134c1c ldr r3, [pc, r3] */
/* @0x134c20 sub sp, sp, #8 */
/* @0x134c24 mov r5, r0 */
/* @0x134c28 ldrb r1, [r3] */
/* @0x134c2c ldr r4, [sp, #0x20] */
/* @0x134c30 cmp r1, #0 */
/* @0x134c34 bne 0x134ca0 <_Z18F_AudioPlaySoundOnR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x134c38 str r1, [r0, #0xc] */
/* @0x134c3c mov r0, r4 */
/* @0x134c40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134c44 mov r1, #1 */
/* @0x134c48 mov r7, r0 */
/* @0x134c4c mov r0, r4 */
/* @0x134c50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134c54 mov r1, #2 */
/* @0x134c58 mov r6, r0 */
/* @0x134c5c mov r0, r4 */
/* @0x134c60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134c64 mov r1, #3 */
/* @0x134c68 mov r8, r0 */
/* @0x134c6c mov r0, r4 */
/* @0x134c70 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134c74 mov r2, r8 */
/* @0x134c78 strd r0, r1, [sp] */
/* @0x134c7c mov r1, r6 */
/* @0x134c80 mov r0, r7 */
/* @0x134c84 bl 0x21b8c0 <_Z17Audio_PlaySoundOniiid> */
/* @0x134c88 vmov s15, r0 */
/* @0x134c8c vcvt.f64.s32 d7, s15 */
/* @0x134c90 vmov r0, r1, d7 */
/* @0x134c94 vmov r2, s14 */
/* @0x134c98 mov r3, r1 */
/* @0x134c9c stm r5, {r2, r3} */
/* @0x134ca0 add sp, sp, #8 */
/* @0x134ca4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x134ca8 eoreq r10, r11, r0, lsr r4 */

/* ── FUNC 0x134cac · F_AudioPlaySoundAt(RValue&, CInstance*, CInstance*, int, RValue*) · size=300 · insn=75 */
/* @0x134cac ldr r3, [pc, #0x120] */
/* @0x134cb0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x134cb4 ldr r3, [pc, r3] */
/* @0x134cb8 sub sp, sp, #100 */
/* @0x134cbc mov r11, r0 */
/* @0x134cc0 ldrb r1, [r3] */
/* @0x134cc4 ldr r10, [sp, #0x88] */
/* @0x134cc8 cmp r1, #0 */
/* @0x134ccc bne 0x134dcc <_Z18F_AudioPlaySoundAtR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x134cd0 str r1, [r0, #0xc] */
/* @0x134cd4 mov r0, r10 */
/* @0x134cd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134cdc mov r1, #1 */
/* @0x134ce0 mov r12, r0 */
/* @0x134ce4 mov r0, r10 */
/* @0x134ce8 str r12, [sp, #0x3c] */
/* @0x134cec bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134cf0 mov r2, r0 */
/* @0x134cf4 mov r3, r1 */
/* @0x134cf8 mov r0, r10 */
/* @0x134cfc mov r1, #2 */
/* @0x134d00 str r2, [sp, #0x44] */
/* @0x134d04 str r3, [sp, #0x40] */
/* @0x134d08 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134d0c mov r8, r0 */
/* @0x134d10 mov r9, r1 */
/* @0x134d14 mov r0, r10 */
/* @0x134d18 mov r1, #3 */
/* @0x134d1c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134d20 mov r6, r0 */
/* @0x134d24 mov r7, r1 */
/* @0x134d28 mov r0, r10 */
/* @0x134d2c mov r1, #4 */
/* @0x134d30 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134d34 strd r0, r1, [sp, #72] */
/* @0x134d38 mov r0, r10 */
/* @0x134d3c mov r1, #5 */
/* @0x134d40 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134d44 strd r0, r1, [sp, #80] */
/* @0x134d48 mov r0, r10 */
/* @0x134d4c mov r1, #6 */
/* @0x134d50 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134d54 mov r4, r0 */
/* @0x134d58 mov r5, r1 */
/* @0x134d5c mov r0, r10 */
/* @0x134d60 mov r1, #7 */
/* @0x134d64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134d68 mov r1, #8 */
/* @0x134d6c str r0, [sp, #0x5c] */
/* @0x134d70 mov r0, r10 */
/* @0x134d74 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134d78 ldr lr, [sp, #0x5c] */
/* @0x134d7c ldr r12, [sp, #0x3c] */
/* @0x134d80 vldr d7, [sp, #72] */
/* @0x134d84 ldr r2, [sp, #0x44] */
/* @0x134d88 vstr d7, [sp, #16] */
/* @0x134d8c ldr r3, [sp, #0x40] */
/* @0x134d90 vldr d7, [sp, #80] */
/* @0x134d94 strd r8, r9, [sp] */
/* @0x134d98 vstr d7, [sp, #24] */
/* @0x134d9c strd r6, r7, [sp, #8] */
/* @0x134da0 strd r4, r5, [sp, #32] */
/* @0x134da4 str lr, [sp, #0x28] */
/* @0x134da8 strd r0, r1, [sp, #48] */
/* @0x134dac mov r0, r12 */
/* @0x134db0 bl 0x21b29c <_Z17Audio_PlaySoundAtiddddddid> */
/* @0x134db4 vmov s15, r0 */
/* @0x134db8 vcvt.f64.s32 d7, s15 */
/* @0x134dbc vmov r0, r1, d7 */
/* @0x134dc0 vmov r2, s14 */
/* @0x134dc4 mov r3, r1 */
/* @0x134dc8 stm r11, {r2, r3} */
/* @0x134dcc add sp, sp, #100 */
/* @0x134dd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x134dd4 mlaeq r11, r8, r3, r10 */

/* ── FUNC 0x134dd8 · F_AudioStopSound(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x134dd8 push {r3, lr} */
/* @0x134ddc ldr r3, [pc, #0x1c] */
/* @0x134de0 ldr r0, [sp, #0x8] */
/* @0x134de4 ldr r3, [pc, r3] */
/* @0x134de8 ldrb r1, [r3] */
/* @0x134dec cmp r1, #0 */
/* @0x134df0 popne {r3, pc} */
/* @0x134df4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134df8 pop {r3, lr} */
/* @0x134dfc b 0x21a210 <_Z15Audio_StopSoundi> */
/* @0x134e00 eoreq r10, r11, r8, ror #4 */

/* ── FUNC 0x134e04 · F_AudioPauseSound(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x134e04 push {r3, lr} */
/* @0x134e08 ldr r3, [pc, #0x1c] */
/* @0x134e0c ldr r0, [sp, #0x8] */
/* @0x134e10 ldr r3, [pc, r3] */
/* @0x134e14 ldrb r1, [r3] */
/* @0x134e18 cmp r1, #0 */
/* @0x134e1c popne {r3, pc} */
/* @0x134e20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134e24 pop {r3, lr} */
/* @0x134e28 b 0x217f6c <_Z16Audio_PauseSoundi> */
/* @0x134e2c eoreq r10, r11, r12, lsr r2 */

/* ── FUNC 0x134e30 · F_AudioExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x134e30 push {r3, r4, r5, lr} */
/* @0x134e34 mov r5, r0 */
/* @0x134e38 ldr r3, [pc, #0x40] */
/* @0x134e3c ldr r3, [pc, r3] */
/* @0x134e40 ldrb r4, [r3] */
/* @0x134e44 cmp r4, #0 */
/* @0x134e48 popne {r3, r4, r5, pc} */
/* @0x134e4c str r4, [r0, #0xc] */
/* @0x134e50 mov r1, r4 */
/* @0x134e54 ldr r0, [sp, #0x10] */
/* @0x134e58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134e5c bl 0x217260 <_Z12Audio_Existsi> */
/* @0x134e60 cmp r0, #0 */
/* @0x134e64 strne r4, [r5] */
/* @0x134e68 streq r0, [r5] */
/* @0x134e6c movne r3, #0 */
/* @0x134e70 streq r0, [r5, #0x4] */
/* @0x134e74 movtne r3, #0x3ff0 */
/* @0x134e78 strne r3, [r5, #0x4] */
/* @0x134e7c pop {r3, r4, r5, pc} */
/* @0x134e80 eoreq r10, r11, r0, lsl r2 */

/* ── FUNC 0x134e84 · F_AudioIsPlaying(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x134e84 ldr r3, [pc, #0x40] */
/* @0x134e88 push {r4, lr} */
/* @0x134e8c ldr r3, [pc, r3] */
/* @0x134e90 mov r4, r0 */
/* @0x134e94 ldrb r1, [r3] */
/* @0x134e98 cmp r1, #0 */
/* @0x134e9c popne {r4, pc} */
/* @0x134ea0 str r1, [r0, #0xc] */
/* @0x134ea4 ldr r0, [sp, #0x8] */
/* @0x134ea8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134eac bl 0x21717c <_Z20Audio_SoundIsPlayingi> */
/* @0x134eb0 vmov s15, r0 */
/* @0x134eb4 vcvt.f64.u32 d7, s15 */
/* @0x134eb8 vmov r0, r1, d7 */
/* @0x134ebc vmov r2, s14 */
/* @0x134ec0 mov r3, r1 */
/* @0x134ec4 stm r4, {r2, r3} */
/* @0x134ec8 pop {r4, pc} */
/* @0x134ecc eoreq r10, r11, r0, asr #3 */

/* ── FUNC 0x134ed0 · F_AudioIsPaused(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x134ed0 push {r3, r4, r5, lr} */
/* @0x134ed4 mov r5, r0 */
/* @0x134ed8 ldr r3, [pc, #0x40] */
/* @0x134edc ldr r3, [pc, r3] */
/* @0x134ee0 ldrb r4, [r3] */
/* @0x134ee4 cmp r4, #0 */
/* @0x134ee8 popne {r3, r4, r5, pc} */
/* @0x134eec str r4, [r0, #0xc] */
/* @0x134ef0 mov r1, r4 */
/* @0x134ef4 ldr r0, [sp, #0x10] */
/* @0x134ef8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134efc bl 0x217098 <_Z19Audio_SoundIsPausedi> */
/* @0x134f00 cmp r0, #0 */
/* @0x134f04 moveq r4, r0 */
/* @0x134f08 movne r3, #0 */
/* @0x134f0c moveq r3, r4 */
/* @0x134f10 movtne r3, #0x3ff0 */
/* @0x134f14 str r4, [r5] */
/* @0x134f18 str r3, [r5, #0x4] */
/* @0x134f1c pop {r3, r4, r5, pc} */
/* @0x134f20 eoreq r10, r11, r0, ror r1 */

/* ── FUNC 0x134f24 · F_AudioGetType(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x134f24 ldr r3, [pc, #0x40] */
/* @0x134f28 push {r4, lr} */
/* @0x134f2c ldr r3, [pc, r3] */
/* @0x134f30 mov r4, r0 */
/* @0x134f34 ldrb r1, [r3] */
/* @0x134f38 cmp r1, #0 */
/* @0x134f3c popne {r4, pc} */
/* @0x134f40 str r1, [r0, #0xc] */
/* @0x134f44 ldr r0, [sp, #0x8] */
/* @0x134f48 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134f4c bl 0x217028 <_Z18Audio_GetSoundTypei> */
/* @0x134f50 vmov s15, r0 */
/* @0x134f54 vcvt.f64.s32 d7, s15 */
/* @0x134f58 vmov r0, r1, d7 */
/* @0x134f5c vmov r2, s14 */
/* @0x134f60 mov r3, r1 */
/* @0x134f64 stm r4, {r2, r3} */
/* @0x134f68 pop {r4, pc} */
/* @0x134f6c eoreq r10, r11, r0, lsr #2 */

/* ── FUNC 0x134f70 · F_AudioEmitterExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x134f70 ldr r3, [pc, #0x40] */
/* @0x134f74 push {r4, lr} */
/* @0x134f78 ldr r3, [pc, r3] */
/* @0x134f7c mov r4, r0 */
/* @0x134f80 ldrb r1, [r3] */
/* @0x134f84 cmp r1, #0 */
/* @0x134f88 popne {r4, pc} */
/* @0x134f8c str r1, [r0, #0xc] */
/* @0x134f90 ldr r0, [sp, #0x8] */
/* @0x134f94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134f98 bl 0x217324 <_Z19Audio_EmitterExistsi> */
/* @0x134f9c vmov s15, r0 */
/* @0x134fa0 vcvt.f64.u32 d7, s15 */
/* @0x134fa4 vmov r0, r1, d7 */
/* @0x134fa8 vmov r2, s14 */
/* @0x134fac mov r3, r1 */
/* @0x134fb0 stm r4, {r2, r3} */
/* @0x134fb4 pop {r4, pc} */
/* @0x134fb8 .word 0x002ba0d4 */

/* ── FUNC 0x134fbc · F_AudioResumeSound(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x134fbc push {r3, lr} */
/* @0x134fc0 ldr r3, [pc, #0x1c] */
/* @0x134fc4 ldr r0, [sp, #0x8] */
/* @0x134fc8 ldr r3, [pc, r3] */
/* @0x134fcc ldrb r1, [r3] */
/* @0x134fd0 cmp r1, #0 */
/* @0x134fd4 popne {r3, pc} */
/* @0x134fd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134fdc pop {r3, lr} */
/* @0x134fe0 b 0x217e9c <_Z17Audio_ResumeSoundi> */
/* @0x134fe4 eoreq r10, r11, r4, lsl #1 */

/* ── FUNC 0x134fe8 · F_AudioSetMasterGain(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x134fe8 ldr r3, [pc, #0x30] */
/* @0x134fec push {r4, lr} */
/* @0x134ff0 ldr r3, [pc, r3] */
/* @0x134ff4 ldr r0, [sp, #0x8] */
/* @0x134ff8 ldrb r4, [r3] */
/* @0x134ffc cmp r4, #0 */
/* @0x135000 popne {r4, pc} */
/* @0x135004 mov r1, r4 */
/* @0x135008 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13500c mov r2, r0 */
/* @0x135010 mov r3, r1 */
/* @0x135014 mov r0, r4 */
/* @0x135018 pop {r4, lr} */
/* @0x13501c b 0x218118 <_Z19Audio_SetMasterGainid> */
/* @0x135020 eoreq r10, r11, r12, asr r0 */

/* ── FUNC 0x135024 · F_AudioSetMasterGainN(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x135024 ldr r3, [pc, #0x40] */
/* @0x135028 push {r4, r5, r6, lr} */
/* @0x13502c ldr r3, [pc, r3] */
/* @0x135030 ldr r4, [sp, #0x10] */
/* @0x135034 ldrb r1, [r3] */
/* @0x135038 cmp r1, #0 */
/* @0x13503c popne {r4, r5, r6, pc} */
/* @0x135040 mov r0, r4 */
/* @0x135044 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135048 mov r1, #1 */
/* @0x13504c mov r5, r0 */
/* @0x135050 mov r0, r4 */
/* @0x135054 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x135058 mov r2, r0 */
/* @0x13505c mov r3, r1 */
/* @0x135060 mov r0, r5 */
/* @0x135064 pop {r4, r5, r6, lr} */
/* @0x135068 b 0x218118 <_Z19Audio_SetMasterGainid> */
/* @0x13506c eoreq r10, r11, r0, lsr #32 */

/* ── FUNC 0x135070 · F_AudioSetEmitterGain(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x135070 ldr r3, [pc, #0x40] */
/* @0x135074 push {r4, r5, r6, lr} */
/* @0x135078 ldr r3, [pc, r3] */
/* @0x13507c ldr r4, [sp, #0x10] */
/* @0x135080 ldrb r1, [r3] */
/* @0x135084 cmp r1, #0 */
/* @0x135088 popne {r4, r5, r6, pc} */
/* @0x13508c mov r0, r4 */
/* @0x135090 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135094 mov r1, #1 */
/* @0x135098 mov r5, r0 */
/* @0x13509c mov r0, r4 */
/* @0x1350a0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1350a4 mov r2, r0 */
/* @0x1350a8 mov r3, r1 */
/* @0x1350ac mov r0, r5 */
/* @0x1350b0 pop {r4, r5, r6, lr} */
/* @0x1350b4 b 0x21803c <_Z20Audio_SetEmitterGainid> */
/* @0x1350b8 .word 0x002b9fd4 */

/* ── FUNC 0x1350bc · F_AudioSetEmitterPitch(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x1350bc ldr r3, [pc, #0x40] */
/* @0x1350c0 push {r4, r5, r6, lr} */
/* @0x1350c4 ldr r3, [pc, r3] */
/* @0x1350c8 ldr r4, [sp, #0x10] */
/* @0x1350cc ldrb r1, [r3] */
/* @0x1350d0 cmp r1, #0 */
/* @0x1350d4 popne {r4, r5, r6, pc} */
/* @0x1350d8 mov r0, r4 */
/* @0x1350dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1350e0 mov r1, #1 */
/* @0x1350e4 mov r5, r0 */
/* @0x1350e8 mov r0, r4 */
/* @0x1350ec bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1350f0 mov r2, r0 */
/* @0x1350f4 mov r3, r1 */
/* @0x1350f8 mov r0, r5 */
/* @0x1350fc pop {r4, r5, r6, lr} */
/* @0x135100 b 0x2181bc <_Z21Audio_SetEmitterPitchid> */
/* @0x135104 eoreq r9, r11, r8, lsl #31 */

/* ── FUNC 0x135108 · F_AudioSetEmitterFalloff(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x135108 ldr r3, [pc, #0x78] */
/* @0x13510c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x135110 ldr r3, [pc, r3] */
/* @0x135114 sub sp, sp, #20 */
/* @0x135118 ldrb r1, [r3] */
/* @0x13511c ldr r8, [sp, #0x30] */
/* @0x135120 cmp r1, #0 */
/* @0x135124 bne 0x135180 <_Z24F_AudioSetEmitterFalloffR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x135128 mov r0, r8 */
/* @0x13512c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x135130 mov r1, #1 */
/* @0x135134 mov r9, r0 */
/* @0x135138 mov r0, r8 */
/* @0x13513c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x135140 mov r4, r0 */
/* @0x135144 mov r5, r1 */
/* @0x135148 mov r0, r8 */
/* @0x13514c mov r1, #2 */
/* @0x135150 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x135154 mov r6, r0 */
/* @0x135158 mov r7, r1 */
/* @0x13515c mov r0, r8 */
/* @0x135160 mov r1, #3 */
/* @0x135164 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x135168 strd r6, r7, [sp] */
/* @0x13516c mov r2, r4 */
/* @0x135170 mov r3, r5 */
/* @0x135174 strd r0, r1, [sp, #8] */
/* @0x135178 mov r0, r9 */
/* @0x13517c bl 0x216c94 <_Z23Audio_SetEmitterFalloffiddd> */
/* @0x135180 add sp, sp, #20 */
/* @0x135184 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x135188 eoreq r9, r11, r12, lsr pc */

/* ── FUNC 0x13518c · F_AudioSetNumChannels(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x13518c push {r3, lr} */
/* @0x135190 ldr r3, [pc, #0x1c] */
/* @0x135194 ldr r0, [sp, #0x8] */
/* @0x135198 ldr r3, [pc, r3] */
/* @0x13519c ldrb r1, [r3] */
/* @0x1351a0 cmp r1, #0 */
/* @0x1351a4 popne {r3, pc} */
/* @0x1351a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1351ac pop {r3, lr} */
/* @0x1351b0 b 0x21a454 <_Z20Audio_SetNumChannelsi> */
/* @0x1351b4 .word 0x002b9eb4 */

/* ── FUNC 0x1351b8 · F_AudioSoundGain(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x1351b8 ldr r3, [pc, #0x50] */
/* @0x1351bc push {r4, r5, r6, lr} */
/* @0x1351c0 ldr r3, [pc, r3] */
/* @0x1351c4 ldr r4, [sp, #0x10] */
/* @0x1351c8 ldrb r1, [r3] */
/* @0x1351cc cmp r1, #0 */
/* @0x1351d0 popne {r4, r5, r6, pc} */
/* @0x1351d4 mov r0, r4 */
/* @0x1351d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1351dc mov r1, #1 */
/* @0x1351e0 mov r6, r0 */
/* @0x1351e4 mov r0, r4 */
/* @0x1351e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1351ec mov r1, #2 */
/* @0x1351f0 mov r5, r0 */
/* @0x1351f4 mov r0, r4 */
/* @0x1351f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1351fc mov r1, r5 */
/* @0x135200 mov r2, r0 */
/* @0x135204 mov r0, r6 */
/* @0x135208 pop {r4, r5, r6, lr} */
/* @0x13520c b 0x2178f0 <_Z15Audio_SoundGainifi> */
/* @0x135210 eoreq r9, r11, r12, lsl #29 */
