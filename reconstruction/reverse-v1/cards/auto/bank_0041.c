/* libyoyo.so 覆盖卡组 0041
 * 函数 0x114624..0x115498，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x114624 · F_DateGetTimezone(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x114624 ldr r2, [pc, #0x24] */
/* @0x114628 mov r3, #0 */
/* @0x11462c str r3, [r0, #0xc] */
/* @0x114630 add r2, pc, r2 */
/* @0x114634 ldrb r2, [r2] */
/* @0x114638 cmp r2, r3 */
/* @0x11463c moveq r3, #0 */
/* @0x114640 movne r2, r3 */
/* @0x114644 movteq r3, #0x3ff0 */
/* @0x114648 stm r0, {r2, r3} */
/* @0x11464c bx lr */
/* @0x114650 eoreq sp, sp, r8, lsl #22 */

/* ── FUNC 0x114654 · F_EventObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x114654 push {r4, r5, r6, r7, r8, lr} */
/* @0x114658 mov r5, r1 */
/* @0x11465c ldr r4, [sp, #0x18] */
/* @0x114660 mov r1, #0 */
/* @0x114664 mov r8, r2 */
/* @0x114668 mov r0, r4 */
/* @0x11466c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114670 mov r1, #1 */
/* @0x114674 mov r7, r0 */
/* @0x114678 mov r0, r4 */
/* @0x11467c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114680 mov r1, #2 */
/* @0x114684 mov r6, r0 */
/* @0x114688 mov r0, r4 */
/* @0x11468c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114690 mov r1, r8 */
/* @0x114694 mov r2, r7 */
/* @0x114698 mov r3, r6 */
/* @0x11469c str r0, [sp, #0x18] */
/* @0x1146a0 mov r0, r5 */
/* @0x1146a4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1146a8 b 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> */

/* ── FUNC 0x1146ac · F_DateValidTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x1146ac push {r4, r5, r6, r7, r8, lr} */
/* @0x1146b0 mov r4, #0 */
/* @0x1146b4 ldr r6, [sp, #0x18] */
/* @0x1146b8 mov r1, r4 */
/* @0x1146bc str r4, [r0, #0xc] */
/* @0x1146c0 mov r5, r0 */
/* @0x1146c4 str r4, [r0] */
/* @0x1146c8 str r4, [r0, #0x4] */
/* @0x1146cc mov r0, r6 */
/* @0x1146d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1146d4 mov r1, #1 */
/* @0x1146d8 mov r7, r0 */
/* @0x1146dc mov r0, r6 */
/* @0x1146e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1146e4 mov r1, #2 */
/* @0x1146e8 mov r8, r0 */
/* @0x1146ec mov r0, r6 */
/* @0x1146f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1146f4 cmp r7, #23 */
/* @0x1146f8 pophi {r4, r5, r6, r7, r8, pc} */
/* @0x1146fc cmp r8, #59 */
/* @0x114700 pophi {r4, r5, r6, r7, r8, pc} */
/* @0x114704 cmp r0, #59 */
/* @0x114708 strls r4, [r5] */
/* @0x11470c movls r3, r4 */
/* @0x114710 movtls r3, #0x3ff0 */
/* @0x114714 strls r3, [r5, #0x4] */
/* @0x114718 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x11471c · F_DateCompareDate(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x11471c push {r3, r4, r5, r6, r7, lr} */
/* @0x114720 mov r5, #0 */
/* @0x114724 ldr r6, [sp, #0x18] */
/* @0x114728 mov r1, r5 */
/* @0x11472c str r5, [r0, #0xc] */
/* @0x114730 mov r4, r0 */
/* @0x114734 mov r0, r6 */
/* @0x114738 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11473c mov r1, #1 */
/* @0x114740 mov r7, r0 */
/* @0x114744 mov r0, r6 */
/* @0x114748 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11474c cmp r7, r0 */
/* @0x114750 moveq r3, r5 */
/* @0x114754 beq 0x114768 <_Z17F_DateCompareDateR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x114758 movgt r3, r5 */
/* @0x11475c movle r3, #0 */
/* @0x114760 movtgt r3, #0x3ff0 */
/* @0x114764 movtle r3, #0xbff0 */
/* @0x114768 str r5, [r4] */
/* @0x11476c str r3, [r4, #0x4] */
/* @0x114770 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x114774 · F_DateDateOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x114774 push {r4, lr} */
/* @0x114778 mov r3, #0 */
/* @0x11477c mov r1, r3 */
/* @0x114780 str r3, [r0, #0xc] */
/* @0x114784 mov r4, r0 */
/* @0x114788 ldr r0, [sp, #0x8] */
/* @0x11478c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114790 vmov s15, r0 */
/* @0x114794 vcvt.f64.s32 d7, s15 */
/* @0x114798 vmov r0, r1, d7 */
/* @0x11479c vmov r2, s14 */
/* @0x1147a0 mov r3, r1 */
/* @0x1147a4 stm r4, {r2, r3} */
/* @0x1147a8 pop {r4, pc} */

/* ── FUNC 0x1147ac · F_DateSetTimezone(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x1147ac push {r3, lr} */
/* @0x1147b0 mov r3, #0 */
/* @0x1147b4 mov r1, r3 */
/* @0x1147b8 str r3, [r0, #0xc] */
/* @0x1147bc str r3, [r0] */
/* @0x1147c0 str r3, [r0, #0x4] */
/* @0x1147c4 ldr r0, [sp, #0x8] */
/* @0x1147c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1147cc ldr r3, [pc, #0x10] */
/* @0x1147d0 add r3, pc, r3 */
/* @0x1147d4 rsbs r0, r0, #1 */
/* @0x1147d8 movlo r0, #0 */
/* @0x1147dc strb r0, [r3] */
/* @0x1147e0 pop {r3, pc} */
/* @0x1147e4 eoreq sp, sp, r8, ror #18 */

/* ── FUNC 0x1147e8 · F_EventPerform(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x1147e8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1147ec mov r5, r1 */
/* @0x1147f0 ldr r4, [sp, #0x18] */
/* @0x1147f4 mov r1, #0 */
/* @0x1147f8 mov r7, r2 */
/* @0x1147fc mov r0, r4 */
/* @0x114800 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114804 mov r1, #1 */
/* @0x114808 mov r6, r0 */
/* @0x11480c mov r0, r4 */
/* @0x114810 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114814 mov r1, r7 */
/* @0x114818 mov r2, r6 */
/* @0x11481c mov r3, r0 */
/* @0x114820 mov r0, r5 */
/* @0x114824 pop {r4, r5, r6, r7, r8, lr} */
/* @0x114828 b 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */

/* ── FUNC 0x11482c · F_EventUser(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x11482c push {r4, r5, r6, lr} */
/* @0x114830 mov r4, r1 */
/* @0x114834 ldr r0, [sp, #0x10] */
/* @0x114838 mov r1, #0 */
/* @0x11483c mov r5, r2 */
/* @0x114840 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114844 mov r1, r5 */
/* @0x114848 mov r2, #7 */
/* @0x11484c add r3, r0, #10 */
/* @0x114850 mov r0, r4 */
/* @0x114854 pop {r4, r5, r6, lr} */
/* @0x114858 b 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */

/* ── FUNC 0x11485c · F_ExternalDefine(RValue&, CInstance*, CInstance*, int, RValue*) · size=492 · insn=123 */
/* @0x11485c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x114860 sub sp, sp, #100 */
/* @0x114864 add r7, sp, #28 */
/* @0x114868 mov r11, #0 */
/* @0x11486c ldr r4, [sp, #0x88] */
/* @0x114870 mov r1, r11 */
/* @0x114874 str r11, [r0] */
/* @0x114878 mov r5, r0 */
/* @0x11487c str r11, [r0, #0xc] */
/* @0x114880 mov r2, r11 */
/* @0x114884 movt r2, #0xbff0 */
/* @0x114888 str r2, [r0, #0x4] */
/* @0x11488c mov r2, #68 */
/* @0x114890 mov r0, r7 */
/* @0x114894 mov r9, r3 */
/* @0x114898 bl 0xb65b0 <memset@plt> */
/* @0x11489c mov r1, r11 */
/* @0x1148a0 mov r0, r4 */
/* @0x1148a4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1148a8 mov r1, #1 */
/* @0x1148ac str r0, [sp, #0x8] */
/* @0x1148b0 mov r0, r4 */
/* @0x1148b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1148b8 mov r1, #2 */
/* @0x1148bc str r0, [sp, #0xc] */
/* @0x1148c0 mov r0, r4 */
/* @0x1148c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1148c8 mov r1, #3 */
/* @0x1148cc str r0, [sp, #0x10] */
/* @0x1148d0 mov r0, r4 */
/* @0x1148d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1148d8 mov r1, #4 */
/* @0x1148dc mov r10, r0 */
/* @0x1148e0 mov r0, r4 */
/* @0x1148e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1148e8 cmp r9, #4 */
/* @0x1148ec mov r8, r0 */
/* @0x1148f0 ble 0x114900 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x1148f4 add r6, r0, #5 */
/* @0x1148f8 cmp r6, r9 */
/* @0x1148fc beq 0x114918 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x114900 ldr r0, [pc, #0x130] */
/* @0x114904 mov r1, #0 */
/* @0x114908 add r0, pc, r0 */
/* @0x11490c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x114910 add sp, sp, #100 */
/* @0x114914 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x114918 cmp r0, #16 */
/* @0x11491c ble 0x114934 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x114920 ldr r0, [pc, #0x114] */
/* @0x114924 mov r1, r11 */
/* @0x114928 add r0, pc, r0 */
/* @0x11492c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x114930 b 0x114910 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x114934 cmp r0, #4 */
/* @0x114938 movgt r11, #5 */
/* @0x11493c bgt 0x1149f0 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x114940 subs r2, r10, #1 */
/* @0x114944 rsbs r10, r2, #0 */
/* @0x114948 adcs r10, r10, r2 */
/* @0x11494c cmp r8, #0 */
/* @0x114950 str r10, [sp, #0x14] */
/* @0x114954 ble 0x11498c <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x114958 mov r9, #0 */
/* @0x11495c mov r10, #5 */
/* @0x114960 mov r11, r9 */
/* @0x114964 mov r1, r10 */
/* @0x114968 mov r0, r4 */
/* @0x11496c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114970 add r10, r10, #1 */
/* @0x114974 cmp r0, #1 */
/* @0x114978 movne r0, r11 */
/* @0x11497c cmp r10, r6 */
/* @0x114980 str r0, [r7, r9] */
/* @0x114984 add r9, r9, #4 */
/* @0x114988 bne 0x114964 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x11498c ldr r3, [sp, #0x14] */
/* @0x114990 mov r4, #0 */
/* @0x114994 str r7, [sp] */
/* @0x114998 ldr r1, [sp, #0xc] */
/* @0x11499c str r3, [sp, #0x4] */
/* @0x1149a0 mov r3, r8 */
/* @0x1149a4 ldr r2, [sp, #0x10] */
/* @0x1149a8 ldr r0, [sp, #0x8] */
/* @0x1149ac str r4, [r5, #0xc] */
/* @0x1149b0 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii> */
/* @0x1149b4 vmov.f64 d7, #-1.000000e+00 */
/* @0x1149b8 vmov s13, r0 */
/* @0x1149bc vcvt.f64.s32 d6, s13 */
/* @0x1149c0 vmov r0, r1, d6 */
/* @0x1149c4 vmov r2, s12 */
/* @0x1149c8 vcmp.f64 d6, d7 */
/* @0x1149cc vmrs APSR_nzcv, fpscr */
/* @0x1149d0 mov r3, r1 */
/* @0x1149d4 stm r5, {r2, r3} */
/* @0x1149d8 bne 0x114910 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x1149dc ldr r0, [pc, #0x5c] */
/* @0x1149e0 mov r1, r4 */
/* @0x1149e4 add r0, pc, r0 */
/* @0x1149e8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1149ec b 0x114910 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x1149f0 mov r1, r11 */
/* @0x1149f4 mov r0, r4 */
/* @0x1149f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1149fc add r11, r11, #1 */
/* @0x114a00 cmp r0, #0 */
/* @0x114a04 bne 0x114a24 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x114a08 cmp r11, r6 */
/* @0x114a0c bne 0x1149f0 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x114a10 subs r3, r10, #1 */
/* @0x114a14 rsbs r10, r3, #0 */
/* @0x114a18 adcs r10, r10, r3 */
/* @0x114a1c str r10, [sp, #0x14] */
/* @0x114a20 b 0x114958 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x114a24 ldr r0, [pc, #0x18] */
/* @0x114a28 mov r1, #0 */
/* @0x114a2c add r0, pc, r0 */
/* @0x114a30 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x114a34 b 0x114910 <_Z16F_ExternalDefineR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x114a38 eoreq r4, r2, r0, lsr #26 */
/* @0x114a3c eoreq r4, r2, r0, lsr #27 */
/* @0x114a40 .word 0x00224cbc */
/* @0x114a44 eoreq r4, r2, r12, lsr #24 */

/* ── FUNC 0x114a48 · F_ExternalCall0(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x114a48 push {r4, r5, r6, lr} */
/* @0x114a4c mov r1, #0 */
/* @0x114a50 ldr r4, [sp, #0x10] */
/* @0x114a54 mov r5, r0 */
/* @0x114a58 mov r0, r4 */
/* @0x114a5c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114a60 mov r2, r4 */
/* @0x114a64 mov r3, r5 */
/* @0x114a68 mov r1, #0 */
/* @0x114a6c pop {r4, r5, r6, lr} */
/* @0x114a70 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_> */

/* ── FUNC 0x114a74 · F_ExternalCall1(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x114a74 push {r4, r5, r6, lr} */
/* @0x114a78 mov r1, #0 */
/* @0x114a7c ldr r4, [sp, #0x10] */
/* @0x114a80 mov r5, r0 */
/* @0x114a84 mov r0, r4 */
/* @0x114a88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114a8c add r2, r4, #16 */
/* @0x114a90 mov r3, r5 */
/* @0x114a94 mov r1, #1 */
/* @0x114a98 pop {r4, r5, r6, lr} */
/* @0x114a9c b 0x212b10 <_Z8DLL_CalliiP6RValueS0_> */

/* ── FUNC 0x114aa0 · F_ExternalCall2(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x114aa0 push {r4, r5, r6, lr} */
/* @0x114aa4 mov r1, #0 */
/* @0x114aa8 ldr r4, [sp, #0x10] */
/* @0x114aac mov r5, r0 */
/* @0x114ab0 mov r0, r4 */
/* @0x114ab4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114ab8 add r2, r4, #16 */
/* @0x114abc mov r3, r5 */
/* @0x114ac0 mov r1, #2 */
/* @0x114ac4 pop {r4, r5, r6, lr} */
/* @0x114ac8 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_> */

/* ── FUNC 0x114acc · F_ExternalCall3(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x114acc push {r4, r5, r6, lr} */
/* @0x114ad0 mov r1, #0 */
/* @0x114ad4 ldr r4, [sp, #0x10] */
/* @0x114ad8 mov r5, r0 */
/* @0x114adc mov r0, r4 */
/* @0x114ae0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114ae4 add r2, r4, #16 */
/* @0x114ae8 mov r3, r5 */
/* @0x114aec mov r1, #3 */
/* @0x114af0 pop {r4, r5, r6, lr} */
/* @0x114af4 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_> */

/* ── FUNC 0x114af8 · F_ExternalCall4(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x114af8 push {r4, r5, r6, lr} */
/* @0x114afc mov r1, #0 */
/* @0x114b00 ldr r4, [sp, #0x10] */
/* @0x114b04 mov r5, r0 */
/* @0x114b08 mov r0, r4 */
/* @0x114b0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114b10 add r2, r4, #16 */
/* @0x114b14 mov r3, r5 */
/* @0x114b18 mov r1, #4 */
/* @0x114b1c pop {r4, r5, r6, lr} */
/* @0x114b20 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_> */

/* ── FUNC 0x114b24 · F_ExternalCall5(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x114b24 push {r4, r5, r6, lr} */
/* @0x114b28 mov r1, #0 */
/* @0x114b2c ldr r4, [sp, #0x10] */
/* @0x114b30 mov r5, r0 */
/* @0x114b34 mov r0, r4 */
/* @0x114b38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114b3c add r2, r4, #16 */
/* @0x114b40 mov r3, r5 */
/* @0x114b44 mov r1, #5 */
/* @0x114b48 pop {r4, r5, r6, lr} */
/* @0x114b4c b 0x212b10 <_Z8DLL_CalliiP6RValueS0_> */

/* ── FUNC 0x114b50 · F_ExternalCall6(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x114b50 push {r4, r5, r6, lr} */
/* @0x114b54 mov r1, #0 */
/* @0x114b58 ldr r4, [sp, #0x10] */
/* @0x114b5c mov r5, r0 */
/* @0x114b60 mov r0, r4 */
/* @0x114b64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114b68 add r2, r4, #16 */
/* @0x114b6c mov r3, r5 */
/* @0x114b70 mov r1, #6 */
/* @0x114b74 pop {r4, r5, r6, lr} */
/* @0x114b78 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_> */

/* ── FUNC 0x114b7c · F_ExternalCall7(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x114b7c push {r4, r5, r6, lr} */
/* @0x114b80 mov r1, #0 */
/* @0x114b84 ldr r4, [sp, #0x10] */
/* @0x114b88 mov r5, r0 */
/* @0x114b8c mov r0, r4 */
/* @0x114b90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114b94 add r2, r4, #16 */
/* @0x114b98 mov r3, r5 */
/* @0x114b9c mov r1, #7 */
/* @0x114ba0 pop {r4, r5, r6, lr} */
/* @0x114ba4 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_> */

/* ── FUNC 0x114ba8 · F_ExternalCall8(RValue&, CInstance*, CInstance*, int, RValue*) · size=44 · insn=11 */
/* @0x114ba8 push {r4, r5, r6, lr} */
/* @0x114bac mov r1, #0 */
/* @0x114bb0 ldr r4, [sp, #0x10] */
/* @0x114bb4 mov r5, r0 */
/* @0x114bb8 mov r0, r4 */
/* @0x114bbc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x114bc0 add r2, r4, #16 */
/* @0x114bc4 mov r3, r5 */
/* @0x114bc8 mov r1, #8 */
/* @0x114bcc pop {r4, r5, r6, lr} */
/* @0x114bd0 b 0x212b10 <_Z8DLL_CalliiP6RValueS0_> */

/* ── FUNC 0x114bd4 · F_ExternalFree(RValue&, CInstance*, CInstance*, int, RValue*) · size=32 · insn=8 */
/* @0x114bd4 push {r3, lr} */
/* @0x114bd8 mov r1, #0 */
/* @0x114bdc ldr r0, [sp, #0x8] */
/* @0x114be0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x114be4 cmp r0, #0 */
/* @0x114be8 popeq {r3, pc} */
/* @0x114bec pop {r3, lr} */
/* @0x114bf0 b 0x214904 <_Z8DLL_FreePKc> */

/* ── FUNC 0x114bf4 · F_DebugEvent(RValue&, CInstance*, CInstance*, int, RValue*) · size=444 · insn=111 */
/* @0x114bf4 push {r3, r4, r5, lr} */
/* @0x114bf8 mov r1, #0 */
/* @0x114bfc ldr r0, [sp, #0x10] */
/* @0x114c00 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x114c04 ldr r4, [pc, #0x170] */
/* @0x114c08 add r4, pc, r4 */
/* @0x114c0c mov r5, r0 */
/* @0x114c10 bl 0x27ba28 <_Z11memLogEventPKcz> */
/* @0x114c14 ldr r1, [pc, #0x164] */
/* @0x114c18 mov r0, r5 */
/* @0x114c1c mov r2, #6 */
/* @0x114c20 add r1, pc, r1 */
/* @0x114c24 bl 0xb65e0 <strncmp@plt> */
/* @0x114c28 cmp r0, #0 */
/* @0x114c2c beq 0x114ce0 <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x114c30 ldr r1, [pc, #0x14c] */
/* @0x114c34 mov r0, r5 */
/* @0x114c38 mov r2, #9 */
/* @0x114c3c add r1, pc, r1 */
/* @0x114c40 bl 0xb65e0 <strncmp@plt> */
/* @0x114c44 cmp r0, #0 */
/* @0x114c48 bne 0x114c94 <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x114c4c ldr r3, [pc, #0x134] */
/* @0x114c50 mov r2, #1 */
/* @0x114c54 ldr r3, [r4, r3] */
/* @0x114c58 strb r2, [r3] */
/* @0x114c5c ldr r3, [pc, #0x128] */
/* @0x114c60 ldr r3, [r4, r3] */
/* @0x114c64 ldrb r3, [r3] */
/* @0x114c68 cmp r3, #0 */
/* @0x114c6c popeq {r3, r4, r5, pc} */
/* @0x114c70 ldr r3, [pc, #0x118] */
/* @0x114c74 ldr r3, [r4, r3] */
/* @0x114c78 ldr r3, [r3] */
/* @0x114c7c cmp r3, #0 */
/* @0x114c80 popne {r3, r4, r5, pc} */
/* @0x114c84 mov r1, r5 */
/* @0x114c88 mov r0, #1 */
/* @0x114c8c pop {r3, r4, r5, lr} */
/* @0x114c90 b 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x114c94 ldr r1, [pc, #0xf8] */
/* @0x114c98 mov r0, r5 */
/* @0x114c9c mov r2, #10 */
/* @0x114ca0 add r1, pc, r1 */
/* @0x114ca4 bl 0xb65e0 <strncmp@plt> */
/* @0x114ca8 cmp r0, #0 */
/* @0x114cac beq 0x114ce8 <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x114cb0 ldr r1, [pc, #0xe0] */
/* @0x114cb4 mov r0, r5 */
/* @0x114cb8 mov r2, #15 */
/* @0x114cbc add r1, pc, r1 */
/* @0x114cc0 bl 0xb65e0 <strncmp@plt> */
/* @0x114cc4 cmp r0, #0 */
/* @0x114cc8 bne 0x114cf8 <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x114ccc ldr r3, [pc, #0xc8] */
/* @0x114cd0 mov r2, #1 */
/* @0x114cd4 ldr r3, [r4, r3] */
/* @0x114cd8 strb r2, [r3] */
/* @0x114cdc b 0x114c5c <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x114ce0 bl 0x27c28c <_ZN13MemoryManager10DumpMemoryEP7__sFILE> */
/* @0x114ce4 b 0x114c5c <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x114ce8 ldr r3, [pc, #0x98] */
/* @0x114cec ldr r3, [r4, r3] */
/* @0x114cf0 strb r0, [r3] */
/* @0x114cf4 b 0x114c5c <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x114cf8 ldr r1, [pc, #0xa0] */
/* @0x114cfc mov r0, r5 */
/* @0x114d00 mov r2, #14 */
/* @0x114d04 add r1, pc, r1 */
/* @0x114d08 bl 0xb65e0 <strncmp@plt> */
/* @0x114d0c cmp r0, #0 */
/* @0x114d10 beq 0x114d44 <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x114d14 ldr r1, [pc, #0x88] */
/* @0x114d18 mov r0, r5 */
/* @0x114d1c mov r2, #15 */
/* @0x114d20 add r1, pc, r1 */
/* @0x114d24 bl 0xb65e0 <strncmp@plt> */
/* @0x114d28 cmp r0, #0 */
/* @0x114d2c bne 0x114d54 <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x114d30 ldr r3, [pc, #0x70] */
/* @0x114d34 mov r2, #1 */
/* @0x114d38 ldr r3, [r4, r3] */
/* @0x114d3c strb r2, [r3] */
/* @0x114d40 b 0x114c5c <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x114d44 ldr r3, [pc, #0x50] */
/* @0x114d48 ldr r3, [r4, r3] */
/* @0x114d4c strb r0, [r3] */
/* @0x114d50 b 0x114c5c <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x114d54 ldr r1, [pc, #0x50] */
/* @0x114d58 mov r0, r5 */
/* @0x114d5c mov r2, #15 */
/* @0x114d60 add r1, pc, r1 */
/* @0x114d64 bl 0xb65e0 <strncmp@plt> */
/* @0x114d68 cmp r0, #0 */
/* @0x114d6c ldreq r3, [pc, #0x34] */
/* @0x114d70 ldreq r3, [r4, r3] */
/* @0x114d74 strbeq r0, [r3] */
/* @0x114d78 b 0x114c5c <_Z12F_DebugEventR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x114d7c eoreq sp, sp, r8, asr #32 */
/* @0x114d80 .word 0x00224ad4 */
/* @0x114d84 eoreq r4, r2, r4, asr #21 */
/* @0x114d88 .word 0xffffc7cc */
/* @0x114d8c .word 0xffffbcd4 */
/* @0x114d90 .word 0xffffc7d0 */
/* @0x114d94 eoreq r4, r2, r12, ror #20 */
/* @0x114d98 eoreq r4, r2, r12, asr r10 */
/* @0x114d9c .word 0xffffc0fc */
/* @0x114da0 eoreq r4, r2, r4, lsr #20 */
/* @0x114da4 eoreq r4, r2, r8, lsl r10 */
/* @0x114da8 .word 0xffffc7d4 */
/* @0x114dac eoreq r4, r2, r8, ror #19 */

/* ── FUNC 0x114db0 · F_VariableGlobalGet(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x114db0 push {r4, r5, r6, lr} */
/* @0x114db4 mov r1, #0 */
/* @0x114db8 mov r4, r0 */
/* @0x114dbc ldr r0, [sp, #0x10] */
/* @0x114dc0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x114dc4 ldr r12, [pc, #0x7c] */
/* @0x114dc8 ldr r12, [pc, r12] */
/* @0x114dcc ldr r5, [r12] */
/* @0x114dd0 mov r6, r0 */
/* @0x114dd4 bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc> */
/* @0x114dd8 subs r1, r0, #0 */
/* @0x114ddc blt 0x114e20 <_Z19F_VariableGlobalGetR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x114de0 ldr r12, [pc, #0x64] */
/* @0x114de4 ldr r12, [pc, r12] */
/* @0x114de8 ldr r3, [r12] */
/* @0x114dec cmp r1, r3 */
/* @0x114df0 bge 0x114e0c <_Z19F_VariableGlobalGetR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x114df4 mov r3, #0 */
/* @0x114df8 mov r2, #5 */
/* @0x114dfc str r3, [r4, #0x8] */
/* @0x114e00 str r2, [r4, #0xc] */
/* @0x114e04 str r3, [r4] */
/* @0x114e08 pop {r4, r5, r6, pc} */
/* @0x114e0c mov r0, r5 */
/* @0x114e10 mov r3, r4 */
/* @0x114e14 mov r2, #-2147483648 */
/* @0x114e18 pop {r4, r5, r6, lr} */
/* @0x114e1c b 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x114e20 mov r1, r6 */
/* @0x114e24 mov r0, r5 */
/* @0x114e28 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0x114e2c mov r2, r4 */
/* @0x114e30 mov r1, #-2147483648 */
/* @0x114e34 pop {r4, r5, r6, lr} */
/* @0x114e38 cmp r0, #0 */
/* @0x114e3c addge r0, r0, #99328 */
/* @0x114e40 addge r0, r0, #672 */
/* @0x114e44 b 0x1f3984 <_Z22Variable_Global_GetVariiP6RValue> */
/* @0x114e48 eoreq r8, sp, r12, ror #27 */
/* @0x114e4c eoreq r9, sp, r4, asr #12 */

/* ── FUNC 0x114e50 · F_VariableGlobalSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x114e50 push {r4, r5, r6, lr} */
/* @0x114e54 mov r1, #0 */
/* @0x114e58 ldr r4, [sp, #0x10] */
/* @0x114e5c mov r0, r4 */
/* @0x114e60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x114e64 ldr r12, [pc, #0x64] */
/* @0x114e68 ldr r12, [pc, r12] */
/* @0x114e6c ldr r5, [r12] */
/* @0x114e70 mov r6, r0 */
/* @0x114e74 bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc> */
/* @0x114e78 subs r1, r0, #0 */
/* @0x114e7c blt 0x114ea8 <_Z19F_VariableGlobalSetR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x114e80 ldr r12, [pc, #0x4c] */
/* @0x114e84 ldr r12, [pc, r12] */
/* @0x114e88 ldr r3, [r12] */
/* @0x114e8c cmp r1, r3 */
/* @0x114e90 poplt {r4, r5, r6, pc} */
/* @0x114e94 mov r0, r5 */
/* @0x114e98 add r3, r4, #16 */
/* @0x114e9c mov r2, #-2147483648 */
/* @0x114ea0 pop {r4, r5, r6, lr} */
/* @0x114ea4 b 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x114ea8 mov r1, r6 */
/* @0x114eac mov r0, r5 */
/* @0x114eb0 bl 0xd2c84 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc> */
/* @0x114eb4 add r2, r4, #16 */
/* @0x114eb8 mov r1, #-2147483648 */
/* @0x114ebc pop {r4, r5, r6, lr} */
/* @0x114ec0 cmp r0, #0 */
/* @0x114ec4 addge r0, r0, #99328 */
/* @0x114ec8 addge r0, r0, #672 */
/* @0x114ecc b 0x1f38f8 <_Z22Variable_Global_SetVariiP6RValue> */
/* @0x114ed0 eoreq r8, sp, r12, asr #26 */
/* @0x114ed4 eoreq r9, sp, r4, lsr #11 */

/* ── FUNC 0x114ed8 · F_DateCurrentDateTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x114ed8 mov r3, #0 */
/* @0x114edc push {r4, lr} */
/* @0x114ee0 mov r4, r0 */
/* @0x114ee4 str r3, [r4, #0xc] */
/* @0x114ee8 mov r0, r3 */
/* @0x114eec bl 0xb67fc <time@plt> */
/* @0x114ef0 vmov.f64 d6, #5.000000e-01 */
/* @0x114ef4 vldr d5, [pc, #36] */
/* @0x114ef8 vldr d7, [pc, #40] */
/* @0x114efc vmov s7, r0 */
/* @0x114f00 vcvt.f64.s32 d4, s7 */
/* @0x114f04 vadd.f64 d6, d4, d6 */
/* @0x114f08 vdiv.f64 d6, d6, d5 */
/* @0x114f0c vadd.f64 d5, d6, d7 */
/* @0x114f10 vmov r2, r3, d5 */
/* @0x114f14 stm r4, {r2, r3} */
/* @0x114f18 pop {r4, pc} */
/* @0x114f1c nop */
/* @0x114f20 andeq r0, r0, r0 */
/* @0x114f24 rscsmi r1, r5, r0, lsl #16 */
/* @0x114f28 andeq r0, r0, r0 */
/* @0x114f2c sbcsmi pc, r8, r0, asr #16 */

/* ── FUNC 0x114f30 · F_DateCurrentDate(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x114f30 mov r3, #0 */
/* @0x114f34 push {r4, lr} */
/* @0x114f38 mov r4, r0 */
/* @0x114f3c str r3, [r4, #0xc] */
/* @0x114f40 mov r0, r3 */
/* @0x114f44 bl 0xb67fc <time@plt> */
/* @0x114f48 vmov.f64 d6, #5.000000e-01 */
/* @0x114f4c vldr d5, [pc, #36] */
/* @0x114f50 vldr d7, [pc, #40] */
/* @0x114f54 vmov s7, r0 */
/* @0x114f58 vcvt.f64.s32 d4, s7 */
/* @0x114f5c vadd.f64 d6, d4, d6 */
/* @0x114f60 vdiv.f64 d6, d6, d5 */
/* @0x114f64 vadd.f64 d5, d6, d7 */
/* @0x114f68 vmov r2, r3, d5 */
/* @0x114f6c stm r4, {r2, r3} */
/* @0x114f70 pop {r4, pc} */
/* @0x114f74 nop */
/* @0x114f78 andeq r0, r0, r0 */
/* @0x114f7c rscsmi r1, r5, r0, lsl #16 */
/* @0x114f80 andeq r0, r0, r0 */
/* @0x114f84 sbcsmi pc, r8, r0, asr #16 */

/* ── FUNC 0x114f88 · F_DateCurrentTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x114f88 mov r3, #0 */
/* @0x114f8c push {r4, lr} */
/* @0x114f90 mov r4, r0 */
/* @0x114f94 str r3, [r4, #0xc] */
/* @0x114f98 mov r0, r3 */
/* @0x114f9c bl 0xb67fc <time@plt> */
/* @0x114fa0 vmov.f64 d6, #5.000000e-01 */
/* @0x114fa4 vldr d5, [pc, #36] */
/* @0x114fa8 vldr d7, [pc, #40] */
/* @0x114fac vmov s7, r0 */
/* @0x114fb0 vcvt.f64.s32 d4, s7 */
/* @0x114fb4 vadd.f64 d6, d4, d6 */
/* @0x114fb8 vdiv.f64 d6, d6, d5 */
/* @0x114fbc vadd.f64 d5, d6, d7 */
/* @0x114fc0 vmov r2, r3, d5 */
/* @0x114fc4 stm r4, {r2, r3} */
/* @0x114fc8 pop {r4, pc} */
/* @0x114fcc nop */
/* @0x114fd0 andeq r0, r0, r0 */
/* @0x114fd4 rscsmi r1, r5, r0, lsl #16 */
/* @0x114fd8 andeq r0, r0, r0 */
/* @0x114fdc sbcsmi pc, r8, r0, asr #16 */

/* ── FUNC 0x114fe0 · F_DateCreateDateTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=336 · insn=84 */
/* @0x114fe0 push {r4, r5, lr} */
/* @0x114fe4 sub sp, sp, #52 */
/* @0x114fe8 mov r3, #0 */
/* @0x114fec mov r5, r0 */
/* @0x114ff0 ldr r4, [sp, #0x40] */
/* @0x114ff4 mov r1, r3 */
/* @0x114ff8 str r3, [r0, #0xc] */
/* @0x114ffc str r3, [sp, #0x4] */
/* @0x115000 mov r0, r4 */
/* @0x115004 str r3, [sp, #0x8] */
/* @0x115008 str r3, [sp, #0xc] */
/* @0x11500c str r3, [sp, #0x10] */
/* @0x115010 str r3, [sp, #0x14] */
/* @0x115014 str r3, [sp, #0x18] */
/* @0x115018 str r3, [sp, #0x1c] */
/* @0x11501c str r3, [sp, #0x20] */
/* @0x115020 str r3, [sp, #0x24] */
/* @0x115024 str r3, [sp, #0x28] */
/* @0x115028 str r3, [sp, #0x2c] */
/* @0x11502c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115030 mov r1, #1 */
/* @0x115034 sub r3, r0, #1888 */
/* @0x115038 mov r0, r4 */
/* @0x11503c subs r3, r3, #12 */
/* @0x115040 movmi r3, #0 */
/* @0x115044 str r3, [sp, #0x18] */
/* @0x115048 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11504c mov r1, #2 */
/* @0x115050 sub r3, r0, #1 */
/* @0x115054 mov r0, r4 */
/* @0x115058 str r3, [sp, #0x14] */
/* @0x11505c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115060 mov r1, #3 */
/* @0x115064 str r0, [sp, #0x10] */
/* @0x115068 mov r0, r4 */
/* @0x11506c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115070 mov r1, #4 */
/* @0x115074 str r0, [sp, #0xc] */
/* @0x115078 mov r0, r4 */
/* @0x11507c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115080 mov r1, #5 */
/* @0x115084 str r0, [sp, #0x8] */
/* @0x115088 mov r0, r4 */
/* @0x11508c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115090 ldr r3, [pc, #0x90] */
/* @0x115094 mvn r2, #0 */
/* @0x115098 str r2, [sp, #0x24] */
/* @0x11509c add r3, pc, r3 */
/* @0x1150a0 ldrb r3, [r3] */
/* @0x1150a4 cmp r3, #0 */
/* @0x1150a8 str r0, [sp, #0x4] */
/* @0x1150ac add r0, sp, #4 */
/* @0x1150b0 beq 0x1150f4 <_Z20F_DateCreateDateTimeR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x1150b4 bl 0xb6808 <mktime64@plt> */
/* @0x1150b8 mov r4, r0 */
/* @0x1150bc cmn r4, #1 */
/* @0x1150c0 beq 0x115104 <_Z20F_DateCreateDateTimeR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1150c4 vmov.f64 d4, #5.000000e-01 */
/* @0x1150c8 vldr d5, [pc, #72] */
/* @0x1150cc vmov s7, r4 */
/* @0x1150d0 vldr d7, [pc, #72] */
/* @0x1150d4 vcvt.f64.s32 d6, s7 */
/* @0x1150d8 vadd.f64 d6, d6, d4 */
/* @0x1150dc vdiv.f64 d6, d6, d5 */
/* @0x1150e0 vadd.f64 d5, d6, d7 */
/* @0x1150e4 vmov r2, r3, d5 */
/* @0x1150e8 stm r5, {r2, r3} */
/* @0x1150ec add sp, sp, #52 */
/* @0x1150f0 pop {r4, r5, pc} */
/* @0x1150f4 bl 0xb6814 <timegm64@plt> */
/* @0x1150f8 mov r4, r0 */
/* @0x1150fc cmn r4, #1 */
/* @0x115100 bne 0x1150c4 <_Z20F_DateCreateDateTimeR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x115104 ldr r0, [pc, #0x20] */
/* @0x115108 add r0, pc, r0 */
/* @0x11510c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x115110 b 0x1150c4 <_Z20F_DateCreateDateTimeR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x115114 nop */
/* @0x115118 andeq r0, r0, r0 */
/* @0x11511c rscsmi r1, r5, r0, lsl #16 */
/* @0x115120 andeq r0, r0, r0 */
/* @0x115124 sbcsmi pc, r8, r0, asr #16 */
/* @0x115128 mlaeq sp, r12, r0, sp */
/* @0x11512c eoreq r4, r2, r4, asr r6 */

/* ── FUNC 0x115130 · F_DateCreateDate(RValue&, CInstance*, CInstance*, int, RValue*) · size=288 · insn=72 */
/* @0x115130 push {r4, r5, r6, lr} */
/* @0x115134 sub sp, sp, #48 */
/* @0x115138 mov r3, #0 */
/* @0x11513c mov r4, r0 */
/* @0x115140 ldr r5, [sp, #0x40] */
/* @0x115144 mov r1, r3 */
/* @0x115148 str r3, [r0, #0xc] */
/* @0x11514c add r6, sp, #4 */
/* @0x115150 str r3, [sp, #0x4] */
/* @0x115154 mov r0, r5 */
/* @0x115158 str r3, [sp, #0x8] */
/* @0x11515c str r3, [sp, #0xc] */
/* @0x115160 str r3, [sp, #0x10] */
/* @0x115164 str r3, [sp, #0x14] */
/* @0x115168 str r3, [sp, #0x18] */
/* @0x11516c str r3, [sp, #0x1c] */
/* @0x115170 str r3, [sp, #0x20] */
/* @0x115174 str r3, [sp, #0x24] */
/* @0x115178 str r3, [sp, #0x28] */
/* @0x11517c str r3, [sp, #0x2c] */
/* @0x115180 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x115184 mov r1, #1 */
/* @0x115188 sub r3, r0, #1888 */
/* @0x11518c mov r0, r5 */
/* @0x115190 sub r3, r3, #12 */
/* @0x115194 str r3, [sp, #0x18] */
/* @0x115198 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11519c mov r1, #2 */
/* @0x1151a0 sub r3, r0, #1 */
/* @0x1151a4 mov r0, r5 */
/* @0x1151a8 str r3, [sp, #0x14] */
/* @0x1151ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1151b0 ldr r3, [pc, #0x90] */
/* @0x1151b4 mvn r2, #0 */
/* @0x1151b8 str r2, [sp, #0x24] */
/* @0x1151bc add r3, pc, r3 */
/* @0x1151c0 ldrb r3, [r3] */
/* @0x1151c4 cmp r3, #0 */
/* @0x1151c8 str r0, [sp, #0x10] */
/* @0x1151cc mov r0, r6 */
/* @0x1151d0 beq 0x115214 <_Z16F_DateCreateDateR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x1151d4 bl 0xb6808 <mktime64@plt> */
/* @0x1151d8 mov r5, r0 */
/* @0x1151dc cmn r5, #1 */
/* @0x1151e0 beq 0x115224 <_Z16F_DateCreateDateR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x1151e4 vmov.f64 d4, #5.000000e-01 */
/* @0x1151e8 vldr d5, [pc, #72] */
/* @0x1151ec vmov s7, r5 */
/* @0x1151f0 vldr d7, [pc, #72] */
/* @0x1151f4 vcvt.f64.s32 d6, s7 */
/* @0x1151f8 vadd.f64 d6, d6, d4 */
/* @0x1151fc vdiv.f64 d6, d6, d5 */
/* @0x115200 vadd.f64 d5, d6, d7 */
/* @0x115204 vmov r2, r3, d5 */
/* @0x115208 stm r4, {r2, r3} */
/* @0x11520c add sp, sp, #48 */
/* @0x115210 pop {r4, r5, r6, pc} */
/* @0x115214 bl 0xb6814 <timegm64@plt> */
/* @0x115218 mov r5, r0 */
/* @0x11521c cmn r5, #1 */
/* @0x115220 bne 0x1151e4 <_Z16F_DateCreateDateR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x115224 ldr r0, [pc, #0x20] */
/* @0x115228 add r0, pc, r0 */
/* @0x11522c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x115230 b 0x1151e4 <_Z16F_DateCreateDateR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x115234 nop */
/* @0x115238 andeq r0, r0, r0 */
/* @0x11523c rscsmi r1, r5, r0, lsl #16 */
/* @0x115240 andeq r0, r0, r0 */
/* @0x115244 sbcsmi pc, r8, r0, asr #16 */
/* @0x115248 eoreq r12, sp, r12, ror pc */
/* @0x11524c eoreq r4, r2, r4, lsr r5 */

/* ── FUNC 0x115250 · F_DateCreateTime(RValue&, CInstance*, CInstance*, int, RValue*) · size=272 · insn=68 */
/* @0x115250 push {r4, r5, r6, lr} */
/* @0x115254 sub sp, sp, #48 */
/* @0x115258 mov r3, #0 */
/* @0x11525c mov r4, r0 */
/* @0x115260 ldr r5, [sp, #0x40] */
/* @0x115264 mov r1, r3 */
/* @0x115268 str r3, [r0, #0xc] */
/* @0x11526c add r6, sp, #4 */
/* @0x115270 str r3, [sp, #0x4] */
/* @0x115274 mov r0, r5 */
/* @0x115278 str r3, [sp, #0x8] */
/* @0x11527c str r3, [sp, #0xc] */
/* @0x115280 str r3, [sp, #0x10] */
/* @0x115284 str r3, [sp, #0x14] */
/* @0x115288 str r3, [sp, #0x18] */
/* @0x11528c str r3, [sp, #0x1c] */
/* @0x115290 str r3, [sp, #0x20] */
/* @0x115294 str r3, [sp, #0x24] */
/* @0x115298 str r3, [sp, #0x28] */
/* @0x11529c str r3, [sp, #0x2c] */
/* @0x1152a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1152a4 mov r1, #1 */
/* @0x1152a8 str r0, [sp, #0xc] */
/* @0x1152ac mov r0, r5 */
/* @0x1152b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1152b4 mov r1, #2 */
/* @0x1152b8 str r0, [sp, #0x8] */
/* @0x1152bc mov r0, r5 */
/* @0x1152c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1152c4 ldr r3, [pc, #0x8c] */
/* @0x1152c8 mvn r2, #0 */
/* @0x1152cc str r2, [sp, #0x24] */
/* @0x1152d0 add r3, pc, r3 */
/* @0x1152d4 ldrb r3, [r3] */
/* @0x1152d8 cmp r3, #0 */
/* @0x1152dc str r0, [sp, #0x4] */
/* @0x1152e0 mov r0, r6 */
/* @0x1152e4 beq 0x115328 <_Z16F_DateCreateTimeR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x1152e8 bl 0xb6808 <mktime64@plt> */
/* @0x1152ec mov r5, r0 */
/* @0x1152f0 cmn r5, #1 */
/* @0x1152f4 beq 0x115338 <_Z16F_DateCreateTimeR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x1152f8 vmov.f64 d4, #5.000000e-01 */
/* @0x1152fc vldr d5, [pc, #68] */
/* @0x115300 vmov s7, r5 */
/* @0x115304 vldr d7, [pc, #68] */
/* @0x115308 vcvt.f64.s32 d6, s7 */
/* @0x11530c vadd.f64 d6, d6, d4 */
/* @0x115310 vdiv.f64 d6, d6, d5 */
/* @0x115314 vadd.f64 d5, d6, d7 */
/* @0x115318 vmov r2, r3, d5 */
/* @0x11531c stm r4, {r2, r3} */
/* @0x115320 add sp, sp, #48 */
/* @0x115324 pop {r4, r5, r6, pc} */
/* @0x115328 bl 0xb6814 <timegm64@plt> */
/* @0x11532c mov r5, r0 */
/* @0x115330 cmn r5, #1 */
/* @0x115334 bne 0x1152f8 <_Z16F_DateCreateTimeR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x115338 ldr r0, [pc, #0x1c] */
/* @0x11533c add r0, pc, r0 */
/* @0x115340 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x115344 b 0x1152f8 <_Z16F_DateCreateTimeR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x115348 andeq r0, r0, r0 */
/* @0x11534c rscsmi r1, r5, r0, lsl #16 */
/* @0x115350 andeq r0, r0, r0 */
/* @0x115354 sbcsmi pc, r8, r0, asr #16 */
/* @0x115358 eoreq r12, sp, r8, ror #28 */
/* @0x11535c eoreq r4, r2, r0, lsr #8 */

/* ── FUNC 0x115360 · F_DateYearSpan(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x115360 push {r3, r4, r5, lr} */
/* @0x115364 vpush {d8} */
/* @0x115368 mov r3, #0 */
/* @0x11536c ldr r5, [sp, #0x18] */
/* @0x115370 mov r1, r3 */
/* @0x115374 str r3, [r0, #0xc] */
/* @0x115378 mov r4, r0 */
/* @0x11537c str r3, [r0] */
/* @0x115380 str r3, [r0, #0x4] */
/* @0x115384 mov r0, r5 */
/* @0x115388 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11538c vmov d8, r0, r1 */
/* @0x115390 mov r0, r5 */
/* @0x115394 mov r1, #1 */
/* @0x115398 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11539c vldr d7, [pc, #28] */
/* @0x1153a0 vmov d6, r0, r1 */
/* @0x1153a4 vsub.f64 d8, d8, d6 */
/* @0x1153a8 vmul.f64 d8, d8, d7 */
/* @0x1153ac vabs.f64 d7, d8 */
/* @0x1153b0 vmov r2, r3, d7 */
/* @0x1153b4 stm r4, {r2, r3} */
/* @0x1153b8 vpop {d8} */
/* @0x1153bc pop {r3, r4, r5, pc} */
/* @0x1153c0 rscsvc r2, r2, #5046272 */
/* @0x1153c4 svclo #0x666db0 */

/* ── FUNC 0x1153c8 · F_DateMonthSpan(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x1153c8 push {r3, r4, r5, lr} */
/* @0x1153cc vpush {d8} */
/* @0x1153d0 mov r3, #0 */
/* @0x1153d4 ldr r5, [sp, #0x18] */
/* @0x1153d8 mov r1, r3 */
/* @0x1153dc str r3, [r0, #0xc] */
/* @0x1153e0 mov r4, r0 */
/* @0x1153e4 str r3, [r0] */
/* @0x1153e8 str r3, [r0, #0x4] */
/* @0x1153ec mov r0, r5 */
/* @0x1153f0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1153f4 vmov d8, r0, r1 */
/* @0x1153f8 mov r0, r5 */
/* @0x1153fc mov r1, #1 */
/* @0x115400 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x115404 vldr d7, [pc, #28] */
/* @0x115408 vmov d6, r0, r1 */
/* @0x11540c vsub.f64 d8, d8, d6 */
/* @0x115410 vmul.f64 d8, d8, d7 */
/* @0x115414 vabs.f64 d7, d8 */
/* @0x115418 vmov r2, r3, d7 */
/* @0x11541c stm r4, {r2, r3} */
/* @0x115420 vpop {d8} */
/* @0x115424 pop {r3, r4, r5, pc} */
/* @0x115428 shasxpl r9, r5, r10 */
/* @0x11542c svclo #0xa0d244 */

/* ── FUNC 0x115430 · F_DateWeekSpan(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x115430 push {r3, r4, r5, lr} */
/* @0x115434 vpush {d8} */
/* @0x115438 mov r3, #0 */
/* @0x11543c ldr r5, [sp, #0x18] */
/* @0x115440 mov r1, r3 */
/* @0x115444 str r3, [r0, #0xc] */
/* @0x115448 mov r4, r0 */
/* @0x11544c str r3, [r0] */
/* @0x115450 str r3, [r0, #0x4] */
/* @0x115454 mov r0, r5 */
/* @0x115458 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11545c vmov d8, r0, r1 */
/* @0x115460 mov r0, r5 */
/* @0x115464 mov r1, #1 */
/* @0x115468 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11546c vldr d7, [pc, #28] */
/* @0x115470 vmov d6, r0, r1 */
/* @0x115474 vsub.f64 d8, d8, d6 */
/* @0x115478 vmul.f64 d8, d8, d7 */
/* @0x11547c vabs.f64 d7, d8 */
/* @0x115480 vmov r2, r3, d7 */
/* @0x115484 stm r4, {r2, r3} */
/* @0x115488 vpop {d8} */
/* @0x11548c pop {r3, r4, r5, pc} */
/* @0x115490 subls r2, r9, #-1845493760 */
/* @0x115494 svclo #0xc24924 */

/* ── FUNC 0x115498 · F_DateDaySpan(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x115498 push {r3, r4, r5, lr} */
/* @0x11549c vpush {d8} */
/* @0x1154a0 mov r3, #0 */
/* @0x1154a4 ldr r5, [sp, #0x18] */
/* @0x1154a8 mov r1, r3 */
/* @0x1154ac str r3, [r0, #0xc] */
/* @0x1154b0 mov r4, r0 */
/* @0x1154b4 str r3, [r0] */
/* @0x1154b8 str r3, [r0, #0x4] */
/* @0x1154bc mov r0, r5 */
/* @0x1154c0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1154c4 vmov d8, r0, r1 */
/* @0x1154c8 mov r0, r5 */
/* @0x1154cc mov r1, #1 */
/* @0x1154d0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1154d4 vmov d7, r0, r1 */
/* @0x1154d8 vcmpe.f64 d8, d7 */
/* @0x1154dc vmrs APSR_nzcv, fpscr */
/* @0x1154e0 vmovpl.f64 d6, d7 */
/* @0x1154e4 vmovpl.f64 d7, d8 */
/* @0x1154e8 vmovpl.f64 d8, d6 */
/* @0x1154ec vsub.f64 d8, d7, d8 */
/* @0x1154f0 vabs.f64 d7, d8 */
/* @0x1154f4 vmov r2, r3, d7 */
/* @0x1154f8 stm r4, {r2, r3} */
/* @0x1154fc vpop {d8} */
/* @0x115500 pop {r3, r4, r5, pc} */
