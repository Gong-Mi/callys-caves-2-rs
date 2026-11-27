/* libyoyo.so 覆盖卡组 0152
 * 函数 0x1c3598..0x1c9594，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1c3598 · CLayerManager::AddLayer(CRoom*, int, char const*) · size=512 · insn=128 */
/* @0x1c3598 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c359c vpush {d8} */
/* @0x1c35a0 sub sp, sp, #20 */
/* @0x1c35a4 ldr r10, [pc, #0x1d8] */
/* @0x1c35a8 str r0, [sp, #0x8] */
/* @0x1c35ac ldr r10, [pc, r10] */
/* @0x1c35b0 str r1, [sp, #0xc] */
/* @0x1c35b4 str r2, [sp, #0x4] */
/* @0x1c35b8 ldr r6, [r10, #0x8] */
/* @0x1c35bc cmp r6, #0 */
/* @0x1c35c0 bne 0x1c36b4 <_ZN13CLayerManager8AddLayerEP5CRoomiPKc+0x11c> */
/* @0x1c35c4 ldr r3, [r10, #0x10] */
/* @0x1c35c8 cmp r3, #0 */
/* @0x1c35cc ble 0x1c36ac <_ZN13CLayerManager8AddLayerEP5CRoomiPKc+0x114> */
/* @0x1c35d0 ldr r8, [pc, #0x1b0] */
/* @0x1c35d4 mov r7, #1 */
/* @0x1c35d8 mov r4, #0 */
/* @0x1c35dc mov r5, #0 */
/* @0x1c35e0 add r8, pc, r8 */
/* @0x1c35e4 vldr s16, [pc, #404] */
/* @0x1c35e8 mov r3, #1 */
/* @0x1c35ec mov r0, #112 */
/* @0x1c35f0 mov r1, r8 */
/* @0x1c35f4 mov r2, #63 */
/* @0x1c35f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c35fc mov r11, #0 */
/* @0x1c3600 mvn r3, #0 */
/* @0x1c3604 subs r9, r0, #0 */
/* @0x1c3608 add r0, r9, #48 */
/* @0x1c360c beq 0x1c3660 <_ZN13CLayerManager8AddLayerEP5CRoomiPKc+0xc8> */
/* @0x1c3610 str r3, [r9] */
/* @0x1c3614 vstr s16, [r9, #8] */
/* @0x1c3618 str r11, [r9, #0x4] */
/* @0x1c361c vstr s16, [r9, #12] */
/* @0x1c3620 vstr s16, [r9, #16] */
/* @0x1c3624 vstr s16, [r9, #20] */
/* @0x1c3628 strb r7, [r9, #0x18] */
/* @0x1c362c strd r4, r5, [r9, #72] */
/* @0x1c3630 strb r11, [r9, #0x19] */
/* @0x1c3634 str r11, [r9, #0x1c] */
/* @0x1c3638 str r3, [r9, #0x20] */
/* @0x1c363c str r3, [r9, #0x24] */
/* @0x1c3640 str r3, [r9, #0x28] */
/* @0x1c3644 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1c3648 str r11, [r9, #0x5c] */
/* @0x1c364c str r11, [r9, #0x58] */
/* @0x1c3650 str r11, [r9, #0x60] */
/* @0x1c3654 str r7, [r9, #0x64] */
/* @0x1c3658 str r11, [r9, #0x68] */
/* @0x1c365c str r11, [r9, #0x6c] */
/* @0x1c3660 ldr r3, [r10] */
/* @0x1c3664 mov r1, #0 */
/* @0x1c3668 add r6, r6, #1 */
/* @0x1c366c ldr r2, [r10, #0x8] */
/* @0x1c3670 cmp r3, r1 */
/* @0x1c3674 streq r9, [r10, #0x4] */
/* @0x1c3678 strne r9, [r3, #0x6c] */
/* @0x1c367c add r2, r2, #1 */
/* @0x1c3680 streq r3, [r9, #0x6c] */
/* @0x1c3684 streq r3, [r9, #0x68] */
/* @0x1c3688 strne r3, [r9, #0x68] */
/* @0x1c368c ldr r3, [r10, #0x10] */
/* @0x1c3690 streq r9, [r10] */
/* @0x1c3694 strne r9, [r10] */
/* @0x1c3698 strne r1, [r9, #0x6c] */
/* @0x1c369c cmp r6, r3 */
/* @0x1c36a0 str r2, [r10, #0x8] */
/* @0x1c36a4 blt 0x1c35e8 <_ZN13CLayerManager8AddLayerEP5CRoomiPKc+0x50> */
/* @0x1c36a8 ldr r6, [r10, #0x8] */
/* @0x1c36ac lsl r3, r3, #1 */
/* @0x1c36b0 str r3, [r10, #0x10] */
/* @0x1c36b4 ldr r4, [r10] */
/* @0x1c36b8 sub r6, r6, #1 */
/* @0x1c36bc ldr r1, [sp, #0xc] */
/* @0x1c36c0 mov r0, #0 */
/* @0x1c36c4 str r6, [r10, #0x8] */
/* @0x1c36c8 ldr r3, [r4, #0x6c] */
/* @0x1c36cc ldr r2, [r4, #0x68] */
/* @0x1c36d0 cmp r3, #0 */
/* @0x1c36d4 strne r2, [r3, #0x68] */
/* @0x1c36d8 ldrne r2, [r4, #0x68] */
/* @0x1c36dc ldrne r3, [r4, #0x6c] */
/* @0x1c36e0 streq r2, [r10] */
/* @0x1c36e4 cmp r2, #0 */
/* @0x1c36e8 streq r3, [r10, #0x4] */
/* @0x1c36ec strne r3, [r2, #0x6c] */
/* @0x1c36f0 ldr r2, [pc, #0x94] */
/* @0x1c36f4 ldr r3, [pc, #0x94] */
/* @0x1c36f8 ldr r2, [pc, r2] */
/* @0x1c36fc str r1, [r4, #0x4] */
/* @0x1c3700 ldr r3, [pc, r3] */
/* @0x1c3704 strb r0, [r4, #0x19] */
/* @0x1c3708 ldr r1, [r2] */
/* @0x1c370c ldr r2, [r3] */
/* @0x1c3710 cmp r2, r1 */
/* @0x1c3714 movlt r2, r1 */
/* @0x1c3718 ldr r1, [sp, #0x4] */
/* @0x1c371c add r2, r2, #1 */
/* @0x1c3720 str r2, [r3] */
/* @0x1c3724 cmp r1, r0 */
/* @0x1c3728 str r2, [r4] */
/* @0x1c372c beq 0x1c3764 <_ZN13CLayerManager8AddLayerEP5CRoomiPKc+0x1cc> */
/* @0x1c3730 mov r0, r1 */
/* @0x1c3734 bl 0xb6538 <strlen@plt> */
/* @0x1c3738 mov r3, #1 */
/* @0x1c373c ldr r1, [pc, #0x50] */
/* @0x1c3740 movw r2, #0x4ea */
/* @0x1c3744 add r1, pc, r1 */
/* @0x1c3748 add r5, r0, r3 */
/* @0x1c374c mov r0, r5 */
/* @0x1c3750 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c3754 mov r2, r5 */
/* @0x1c3758 ldr r1, [sp, #0x4] */
/* @0x1c375c str r0, [r4, #0x1c] */
/* @0x1c3760 bl 0xb65bc <memcpy@plt> */
/* @0x1c3764 ldr r0, [sp, #0x8] */
/* @0x1c3768 mov r1, r4 */
/* @0x1c376c bl 0x1c30f8 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer> */
/* @0x1c3770 mov r0, r4 */
/* @0x1c3774 add sp, sp, #20 */
/* @0x1c3778 vpop {d8} */
/* @0x1c377c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c3780 andeq r0, r0, r0 */
/* @0x1c3784 .word 0x0022d2b0 */
/* @0x1c3788 ldrheq r10, [r8], -r4 */
/* @0x1c378c eoreq sp, r2, r8, lsl #3 */
/* @0x1c3790 .word 0x0022d3dc */
/* @0x1c3794 andseq r10, r8, r8, lsr #32 */

/* ── FUNC 0x1c3798 · F_LayerCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x1c3798 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c379c subs r7, r3, #0 */
/* @0x1c37a0 mov r2, #0 */
/* @0x1c37a4 mov r4, r0 */
/* @0x1c37a8 mov r5, r2 */
/* @0x1c37ac ldr r6, [sp, #0x18] */
/* @0x1c37b0 movt r2, #0xbff0 */
/* @0x1c37b4 str r5, [r0, #0xc] */
/* @0x1c37b8 str r2, [r0, #0x4] */
/* @0x1c37bc str r5, [r0] */
/* @0x1c37c0 ble 0x1c381c <_Z13F_LayerCreateR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1c37c4 mov r0, r6 */
/* @0x1c37c8 mov r1, r5 */
/* @0x1c37cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c37d0 cmp r7, #1 */
/* @0x1c37d4 mov r8, r0 */
/* @0x1c37d8 beq 0x1c37ec <_Z13F_LayerCreateR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1c37dc mov r0, r6 */
/* @0x1c37e0 mov r1, #1 */
/* @0x1c37e4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c37e8 mov r5, r0 */
/* @0x1c37ec bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c37f0 mov r1, r8 */
/* @0x1c37f4 mov r2, r5 */
/* @0x1c37f8 bl 0x1c3598 <_ZN13CLayerManager8AddLayerEP5CRoomiPKc> */
/* @0x1c37fc cmp r0, #0 */
/* @0x1c3800 beq 0x1c3830 <_Z13F_LayerCreateR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1c3804 ldr r2, [r0] */
/* @0x1c3808 vmov s15, r2 */
/* @0x1c380c vcvt.f64.s32 d7, s15 */
/* @0x1c3810 vmov r2, r3, d7 */
/* @0x1c3814 stm r4, {r2, r3} */
/* @0x1c3818 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c381c ldr r0, [pc, #0x20] */
/* @0x1c3820 mov r1, r5 */
/* @0x1c3824 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c3828 add r0, pc, r0 */
/* @0x1c382c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c3830 mov r1, r0 */
/* @0x1c3834 ldr r0, [pc, #0xc] */
/* @0x1c3838 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c383c add r0, pc, r0 */
/* @0x1c3840 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c3844 andseq r12, r8, r0, ror #31 */
/* @0x1c3848 ldrsheq r12, [r8], -r12 */

/* ── FUNC 0x1c384c · CHashMap<int, CLayerElementBase*, 7>::Insert(int, CLayerElementBase*) · size=1640 · insn=410 */
/* @0x1c384c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c3850 vpush {d8} */
/* @0x1c3854 sub sp, sp, #60 */
/* @0x1c3858 ldr r3, [r0, #0x4] */
/* @0x1c385c mov r11, r0 */
/* @0x1c3860 str r2, [sp, #0x24] */
/* @0x1c3864 ldr r2, [r0, #0xc] */
/* @0x1c3868 str r1, [sp, #0x1c] */
/* @0x1c386c cmp r3, r2 */
/* @0x1c3870 bgt 0x1c3980 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x134> */
/* @0x1c3874 add r3, r3, #1 */
/* @0x1c3878 ldr r0, [sp, #0x1c] */
/* @0x1c387c str r3, [r11, #0x4] */
/* @0x1c3880 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c3884 ldr r4, [r11, #0x8] */
/* @0x1c3888 ldr r6, [r11, #0x10] */
/* @0x1c388c bic r0, r0, #-2147483648 */
/* @0x1c3890 and r3, r0, r4 */
/* @0x1c3894 add r2, r3, r3, lsl #1 */
/* @0x1c3898 add r2, r6, r2, lsl #2 */
/* @0x1c389c ldr r12, [r2, #0x8] */
/* @0x1c38a0 cmp r12, #0 */
/* @0x1c38a4 beq 0x1c3960 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x114> */
/* @0x1c38a8 ldr r7, [r11] */
/* @0x1c38ac mov r1, #0 */
/* @0x1c38b0 ldr r8, [sp, #0x1c] */
/* @0x1c38b4 ldr r9, [sp, #0x24] */
/* @0x1c38b8 b 0x1c3900 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0xb4> */
/* @0x1c38bc ldr r10, [r2] */
/* @0x1c38c0 mov r1, r5 */
/* @0x1c38c4 ldr r5, [r2, #0x4] */
/* @0x1c38c8 str r0, [r2, #0x8] */
/* @0x1c38cc mov r0, r12 */
/* @0x1c38d0 str r8, [r2] */
/* @0x1c38d4 mov r8, r10 */
/* @0x1c38d8 str r9, [r2, #0x4] */
/* @0x1c38dc mov r9, r5 */
/* @0x1c38e0 add r3, r3, #1 */
/* @0x1c38e4 add r1, r1, #1 */
/* @0x1c38e8 and r3, r3, r4 */
/* @0x1c38ec add r2, r3, r3, lsl #1 */
/* @0x1c38f0 add r2, r6, r2, lsl #2 */
/* @0x1c38f4 ldr r12, [r2, #0x8] */
/* @0x1c38f8 cmp r12, #0 */
/* @0x1c38fc beq 0x1c3958 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x10c> */
/* @0x1c3900 add r5, r7, r3 */
/* @0x1c3904 and r10, r12, r4 */
/* @0x1c3908 rsb r5, r10, r5 */
/* @0x1c390c and r5, r5, r4 */
/* @0x1c3910 cmp r5, r1 */
/* @0x1c3914 blt 0x1c38bc <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x70> */
/* @0x1c3918 cmp r1, r5 */
/* @0x1c391c bne 0x1c38e0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x94> */
/* @0x1c3920 cmp r0, r12 */
/* @0x1c3924 bne 0x1c38e0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x94> */
/* @0x1c3928 ldr r12, [r2] */
/* @0x1c392c cmp r8, r12 */
/* @0x1c3930 bne 0x1c38e0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x94> */
/* @0x1c3934 ldr r3, [r11, #0x4] */
/* @0x1c3938 str r8, [sp, #0x1c] */
/* @0x1c393c str r8, [r2] */
/* @0x1c3940 sub r3, r3, #1 */
/* @0x1c3944 str r9, [r2, #0x4] */
/* @0x1c3948 str r0, [r2, #0x8] */
/* @0x1c394c str r9, [sp, #0x24] */
/* @0x1c3950 str r3, [r11, #0x4] */
/* @0x1c3954 b 0x1c3974 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x128> */
/* @0x1c3958 str r8, [sp, #0x1c] */
/* @0x1c395c str r9, [sp, #0x24] */
/* @0x1c3960 ldr r12, [sp, #0x1c] */
/* @0x1c3964 str r0, [r2, #0x8] */
/* @0x1c3968 str r12, [r2] */
/* @0x1c396c ldr r12, [sp, #0x24] */
/* @0x1c3970 str r12, [r2, #0x4] */
/* @0x1c3974 add sp, sp, #60 */
/* @0x1c3978 vpop {d8} */
/* @0x1c397c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c3980 ldr r12, [r0] */
/* @0x1c3984 mov r3, #1 */
/* @0x1c3988 ldr r1, [pc, #0x430] */
/* @0x1c398c mov r2, #70 */
/* @0x1c3990 str r12, [sp, #0x20] */
/* @0x1c3994 add r1, pc, r1 */
/* @0x1c3998 ldr r12, [r0, #0x10] */
/* @0x1c399c str r12, [sp, #0x30] */
/* @0x1c39a0 ldr r12, [sp, #0x20] */
/* @0x1c39a4 lsl r0, r12, r3 */
/* @0x1c39a8 str r0, [r11] */
/* @0x1c39ac add r4, r0, r12, lsl #2 */
/* @0x1c39b0 sub r0, r0, #1 */
/* @0x1c39b4 str r0, [r11, #0x8] */
/* @0x1c39b8 lsl r4, r4, #2 */
/* @0x1c39bc mov r0, r4 */
/* @0x1c39c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c39c4 mov r2, r4 */
/* @0x1c39c8 mov r1, #0 */
/* @0x1c39cc str r0, [r11, #0x10] */
/* @0x1c39d0 bl 0xb65b0 <memset@plt> */
/* @0x1c39d4 ldr r2, [r11] */
/* @0x1c39d8 vldr s15, [pc, #988] */
/* @0x1c39dc mov r1, #0 */
/* @0x1c39e0 cmp r2, r1 */
/* @0x1c39e4 str r1, [r11, #0x4] */
/* @0x1c39e8 vmov s13, r2 */
/* @0x1c39ec vcvt.f32.s32 s14, s13 */
/* @0x1c39f0 vmul.f32 s15, s14, s15 */
/* @0x1c39f4 vcvt.s32.f32 s15, s15 */
/* @0x1c39f8 vstr s15, [r11, #12] */
/* @0x1c39fc ble 0x1c3a1c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x1d0> */
/* @0x1c3a00 add r2, r2, r2, lsl #1 */
/* @0x1c3a04 ldr r3, [r11, #0x10] */
/* @0x1c3a08 add r2, r3, r2, lsl #2 */
/* @0x1c3a0c str r1, [r3, #0x8] */
/* @0x1c3a10 add r3, r3, #12 */
/* @0x1c3a14 cmp r3, r2 */
/* @0x1c3a18 bne 0x1c3a0c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x1c0> */
/* @0x1c3a1c ldr r12, [sp, #0x20] */
/* @0x1c3a20 cmp r12, #0 */
/* @0x1c3a24 ble 0x1c3b8c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x340> */
/* @0x1c3a28 ldr r12, [pc, #0x394] */
/* @0x1c3a2c vldr s16, [pc, #904] */
/* @0x1c3a30 add r12, pc, r12 */
/* @0x1c3a34 str r12, [sp, #0x34] */
/* @0x1c3a38 mov r12, #0 */
/* @0x1c3a3c str r12, [sp, #0xc] */
/* @0x1c3a40 ldr r12, [pc, #0x380] */
/* @0x1c3a44 add r12, pc, r12 */
/* @0x1c3a48 str r12, [sp, #0x2c] */
/* @0x1c3a4c ldr r12, [sp, #0x30] */
/* @0x1c3a50 str r12, [sp, #0x8] */
/* @0x1c3a54 ldr r12, [sp, #0x8] */
/* @0x1c3a58 ldr r3, [r12, #0x8] */
/* @0x1c3a5c cmp r3, #0 */
/* @0x1c3a60 ble 0x1c3b64 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x318> */
/* @0x1c3a64 ldr r12, [r12] */
/* @0x1c3a68 ldr r3, [r11, #0x4] */
/* @0x1c3a6c ldr r2, [r11, #0xc] */
/* @0x1c3a70 str r12, [sp, #0x10] */
/* @0x1c3a74 ldr r12, [sp, #0x8] */
/* @0x1c3a78 cmp r3, r2 */
/* @0x1c3a7c ldr r12, [r12, #0x4] */
/* @0x1c3a80 str r12, [sp, #0x18] */
/* @0x1c3a84 bgt 0x1c3bd4 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x388> */
/* @0x1c3a88 add r3, r3, #1 */
/* @0x1c3a8c ldr r0, [sp, #0x10] */
/* @0x1c3a90 str r3, [r11, #0x4] */
/* @0x1c3a94 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c3a98 ldr lr, [r11, #0x8] */
/* @0x1c3a9c ldr r6, [r11, #0x10] */
/* @0x1c3aa0 bic r0, r0, #-2147483648 */
/* @0x1c3aa4 and r3, r0, lr */
/* @0x1c3aa8 add r2, r3, r3, lsl #1 */
/* @0x1c3aac add r2, r6, r2, lsl #2 */
/* @0x1c3ab0 ldr r1, [r2, #0x8] */
/* @0x1c3ab4 cmp r1, #0 */
/* @0x1c3ab8 beq 0x1c3bbc <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x370> */
/* @0x1c3abc ldr r7, [r11] */
/* @0x1c3ac0 mov r4, #0 */
/* @0x1c3ac4 ldr r8, [sp, #0x10] */
/* @0x1c3ac8 ldr r9, [sp, #0x18] */
/* @0x1c3acc b 0x1c3b10 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x2c4> */
/* @0x1c3ad0 ldr r5, [r2] */
/* @0x1c3ad4 ldr r4, [r2, #0x4] */
/* @0x1c3ad8 str r0, [r2, #0x8] */
/* @0x1c3adc mov r0, r1 */
/* @0x1c3ae0 str r8, [r2] */
/* @0x1c3ae4 mov r8, r5 */
/* @0x1c3ae8 str r9, [r2, #0x4] */
/* @0x1c3aec mov r9, r4 */
/* @0x1c3af0 add r3, r3, #1 */
/* @0x1c3af4 add r4, r12, #1 */
/* @0x1c3af8 and r3, r3, lr */
/* @0x1c3afc add r2, r3, r3, lsl #1 */
/* @0x1c3b00 add r2, r6, r2, lsl #2 */
/* @0x1c3b04 ldr r1, [r2, #0x8] */
/* @0x1c3b08 cmp r1, #0 */
/* @0x1c3b0c beq 0x1c3bb4 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x368> */
/* @0x1c3b10 add r12, r7, r3 */
/* @0x1c3b14 and r5, r1, lr */
/* @0x1c3b18 rsb r12, r5, r12 */
/* @0x1c3b1c and r12, r12, lr */
/* @0x1c3b20 cmp r12, r4 */
/* @0x1c3b24 blt 0x1c3ad0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x284> */
/* @0x1c3b28 movne r12, r4 */
/* @0x1c3b2c bne 0x1c3af0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x2a4> */
/* @0x1c3b30 cmp r1, r0 */
/* @0x1c3b34 bne 0x1c3af0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x2a4> */
/* @0x1c3b38 ldr r4, [r2] */
/* @0x1c3b3c cmp r8, r4 */
/* @0x1c3b40 bne 0x1c3af0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x2a4> */
/* @0x1c3b44 ldr r3, [r11, #0x4] */
/* @0x1c3b48 str r8, [sp, #0x10] */
/* @0x1c3b4c str r8, [r2] */
/* @0x1c3b50 sub r3, r3, #1 */
/* @0x1c3b54 str r9, [r2, #0x4] */
/* @0x1c3b58 str r1, [r2, #0x8] */
/* @0x1c3b5c str r9, [sp, #0x18] */
/* @0x1c3b60 str r3, [r11, #0x4] */
/* @0x1c3b64 ldr r12, [sp, #0xc] */
/* @0x1c3b68 ldr r0, [sp, #0x20] */
/* @0x1c3b6c add r12, r12, #1 */
/* @0x1c3b70 str r12, [sp, #0xc] */
/* @0x1c3b74 ldr r12, [sp, #0x8] */
/* @0x1c3b78 add r12, r12, #12 */
/* @0x1c3b7c str r12, [sp, #0x8] */
/* @0x1c3b80 ldr r12, [sp, #0xc] */
/* @0x1c3b84 cmp r12, r0 */
/* @0x1c3b88 bne 0x1c3a54 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x208> */
/* @0x1c3b8c ldr r0, [sp, #0x30] */
/* @0x1c3b90 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c3b94 vldr s13, [r11] */
/* @0x1c3b98 vcvt.f32.s32 s14, s13 */
/* @0x1c3b9c vldr s15, [pc, #536] */
/* @0x1c3ba0 ldr r3, [r11, #0x4] */
/* @0x1c3ba4 vmul.f32 s15, s14, s15 */
/* @0x1c3ba8 vcvt.s32.f32 s15, s15 */
/* @0x1c3bac vstr s15, [r11, #12] */
/* @0x1c3bb0 b 0x1c3874 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x28> */
/* @0x1c3bb4 str r8, [sp, #0x10] */
/* @0x1c3bb8 str r9, [sp, #0x18] */
/* @0x1c3bbc ldr r12, [sp, #0x10] */
/* @0x1c3bc0 str r0, [r2, #0x8] */
/* @0x1c3bc4 str r12, [r2] */
/* @0x1c3bc8 ldr r12, [sp, #0x18] */
/* @0x1c3bcc str r12, [r2, #0x4] */
/* @0x1c3bd0 b 0x1c3b64 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x318> */
/* @0x1c3bd4 ldr r12, [r11] */
/* @0x1c3bd8 mov r3, #1 */
/* @0x1c3bdc ldr r1, [sp, #0x34] */
/* @0x1c3be0 mov r2, #70 */
/* @0x1c3be4 str r12, [sp, #0x14] */
/* @0x1c3be8 ldr r12, [r11, #0x10] */
/* @0x1c3bec str r12, [sp, #0x28] */
/* @0x1c3bf0 ldr r12, [sp, #0x14] */
/* @0x1c3bf4 lsl r0, r12, r3 */
/* @0x1c3bf8 str r0, [r11] */
/* @0x1c3bfc add r4, r0, r12, lsl #2 */
/* @0x1c3c00 sub r0, r0, #1 */
/* @0x1c3c04 str r0, [r11, #0x8] */
/* @0x1c3c08 lsl r4, r4, #2 */
/* @0x1c3c0c mov r0, r4 */
/* @0x1c3c10 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c3c14 mov r2, r4 */
/* @0x1c3c18 mov r1, #0 */
/* @0x1c3c1c str r0, [r11, #0x10] */
/* @0x1c3c20 bl 0xb65b0 <memset@plt> */
/* @0x1c3c24 ldr r2, [r11] */
/* @0x1c3c28 mov r0, #0 */
/* @0x1c3c2c str r0, [r11, #0x4] */
/* @0x1c3c30 cmp r2, r0 */
/* @0x1c3c34 vmov s13, r2 */
/* @0x1c3c38 vcvt.f32.s32 s15, s13 */
/* @0x1c3c3c vmul.f32 s15, s15, s16 */
/* @0x1c3c40 vcvt.s32.f32 s15, s15 */
/* @0x1c3c44 vstr s15, [r11, #12] */
/* @0x1c3c48 ble 0x1c3c6c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x420> */
/* @0x1c3c4c add r2, r2, r2, lsl #1 */
/* @0x1c3c50 ldr r3, [r11, #0x10] */
/* @0x1c3c54 add r2, r3, r2, lsl #2 */
/* @0x1c3c58 mov r0, #0 */
/* @0x1c3c5c add r3, r3, #12 */
/* @0x1c3c60 str r0, [r3, #-0x4] */
/* @0x1c3c64 cmp r3, r2 */
/* @0x1c3c68 bne 0x1c3c58 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x40c> */
/* @0x1c3c6c ldr r12, [sp, #0x14] */
/* @0x1c3c70 cmp r12, #0 */
/* @0x1c3c74 ble 0x1c3d8c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x540> */
/* @0x1c3c78 ldr r6, [sp, #0x28] */
/* @0x1c3c7c mov r12, #0 */
/* @0x1c3c80 str r12, [sp, #0x4] */
/* @0x1c3c84 ldr r3, [r6, #0x8] */
/* @0x1c3c88 cmp r3, #0 */
/* @0x1c3c8c ble 0x1c3d70 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x524> */
/* @0x1c3c90 ldr r3, [r11, #0x4] */
/* @0x1c3c94 ldr r2, [r11, #0xc] */
/* @0x1c3c98 ldr r4, [r6] */
/* @0x1c3c9c cmp r3, r2 */
/* @0x1c3ca0 ldr r5, [r6, #0x4] */
/* @0x1c3ca4 bgt 0x1c3dcc <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x580> */
/* @0x1c3ca8 add r3, r3, #1 */
/* @0x1c3cac mov r0, r4 */
/* @0x1c3cb0 str r3, [r11, #0x4] */
/* @0x1c3cb4 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c3cb8 ldr lr, [r11, #0x8] */
/* @0x1c3cbc ldr r9, [r11, #0x10] */
/* @0x1c3cc0 bic r0, r0, #-2147483648 */
/* @0x1c3cc4 and r3, r0, lr */
/* @0x1c3cc8 add r2, r3, r3, lsl #1 */
/* @0x1c3ccc add r2, r9, r2, lsl #2 */
/* @0x1c3cd0 ldr r1, [r2, #0x8] */
/* @0x1c3cd4 cmp r1, #0 */
/* @0x1c3cd8 ldrne r10, [r11] */
/* @0x1c3cdc movne r7, #0 */
/* @0x1c3ce0 bne 0x1c3d28 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x4dc> */
/* @0x1c3ce4 b 0x1c3db0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x564> */
/* @0x1c3ce8 ldr r8, [r2] */
/* @0x1c3cec ldr r7, [r2, #0x4] */
/* @0x1c3cf0 str r0, [r2, #0x8] */
/* @0x1c3cf4 mov r0, r1 */
/* @0x1c3cf8 str r4, [r2] */
/* @0x1c3cfc mov r4, r8 */
/* @0x1c3d00 str r5, [r2, #0x4] */
/* @0x1c3d04 mov r5, r7 */
/* @0x1c3d08 add r3, r3, #1 */
/* @0x1c3d0c add r7, r12, #1 */
/* @0x1c3d10 and r3, r3, lr */
/* @0x1c3d14 add r2, r3, r3, lsl #1 */
/* @0x1c3d18 add r2, r9, r2, lsl #2 */
/* @0x1c3d1c ldr r1, [r2, #0x8] */
/* @0x1c3d20 cmp r1, #0 */
/* @0x1c3d24 beq 0x1c3db0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x564> */
/* @0x1c3d28 add r12, r3, r10 */
/* @0x1c3d2c and r8, r1, lr */
/* @0x1c3d30 rsb r12, r8, r12 */
/* @0x1c3d34 and r12, r12, lr */
/* @0x1c3d38 cmp r12, r7 */
/* @0x1c3d3c blt 0x1c3ce8 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x49c> */
/* @0x1c3d40 movne r12, r7 */
/* @0x1c3d44 bne 0x1c3d08 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x4bc> */
/* @0x1c3d48 cmp r1, r0 */
/* @0x1c3d4c bne 0x1c3d08 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x4bc> */
/* @0x1c3d50 ldr r7, [r2] */
/* @0x1c3d54 cmp r4, r7 */
/* @0x1c3d58 bne 0x1c3d08 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x4bc> */
/* @0x1c3d5c ldr r3, [r11, #0x4] */
/* @0x1c3d60 stm r2, {r4, r5} */
/* @0x1c3d64 sub r3, r3, #1 */
/* @0x1c3d68 str r1, [r2, #0x8] */
/* @0x1c3d6c str r3, [r11, #0x4] */
/* @0x1c3d70 ldr r12, [sp, #0x4] */
/* @0x1c3d74 add r6, r6, #12 */
/* @0x1c3d78 ldr r0, [sp, #0x14] */
/* @0x1c3d7c add r12, r12, #1 */
/* @0x1c3d80 str r12, [sp, #0x4] */
/* @0x1c3d84 cmp r12, r0 */
/* @0x1c3d88 bne 0x1c3c84 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x438> */
/* @0x1c3d8c ldr r0, [sp, #0x28] */
/* @0x1c3d90 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c3d94 vldr s13, [r11] */
/* @0x1c3d98 vcvt.f32.s32 s15, s13 */
/* @0x1c3d9c ldr r3, [r11, #0x4] */
/* @0x1c3da0 vmul.f32 s15, s15, s16 */
/* @0x1c3da4 vcvt.s32.f32 s15, s15 */
/* @0x1c3da8 vstr s15, [r11, #12] */
/* @0x1c3dac b 0x1c3a88 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x23c> */
/* @0x1c3db0 stm r2, {r4, r5} */
/* @0x1c3db4 str r0, [r2, #0x8] */
/* @0x1c3db8 b 0x1c3d70 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x524> */
/* @0x1c3dbc svclo #0x19999a */
/* @0x1c3dc0 mulseq r6, r12, r6 */
/* @0x1c3dc4 andseq sp, r6, r0, lsl #12 */
/* @0x1c3dc8 andseq sp, r6, r12, ror #11 */
/* @0x1c3dcc ldr r8, [r11] */
/* @0x1c3dd0 mov r3, #1 */
/* @0x1c3dd4 ldr r1, [sp, #0x2c] */
/* @0x1c3dd8 mov r2, #70 */
/* @0x1c3ddc ldr r7, [r11, #0x10] */
/* @0x1c3de0 lsl r0, r8, r3 */
/* @0x1c3de4 str r0, [r11] */
/* @0x1c3de8 add r9, r0, r8, lsl #2 */
/* @0x1c3dec sub r0, r0, #1 */
/* @0x1c3df0 str r0, [r11, #0x8] */
/* @0x1c3df4 lsl r9, r9, #2 */
/* @0x1c3df8 mov r0, r9 */
/* @0x1c3dfc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c3e00 mov r2, r9 */
/* @0x1c3e04 mov r1, #0 */
/* @0x1c3e08 str r0, [r11, #0x10] */
/* @0x1c3e0c bl 0xb65b0 <memset@plt> */
/* @0x1c3e10 ldr r2, [r11] */
/* @0x1c3e14 mov r0, #0 */
/* @0x1c3e18 str r0, [r11, #0x4] */
/* @0x1c3e1c cmp r2, r0 */
/* @0x1c3e20 vmov s13, r2 */
/* @0x1c3e24 vcvt.f32.s32 s15, s13 */
/* @0x1c3e28 vmul.f32 s15, s15, s16 */
/* @0x1c3e2c vcvt.s32.f32 s15, s15 */
/* @0x1c3e30 vstr s15, [r11, #12] */
/* @0x1c3e34 ble 0x1c3e58 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x60c> */
/* @0x1c3e38 add r2, r2, r2, lsl #1 */
/* @0x1c3e3c ldr r3, [r11, #0x10] */
/* @0x1c3e40 add r2, r3, r2, lsl #2 */
/* @0x1c3e44 mov r0, #0 */
/* @0x1c3e48 add r3, r3, #12 */
/* @0x1c3e4c str r0, [r3, #-0x4] */
/* @0x1c3e50 cmp r3, r2 */
/* @0x1c3e54 bne 0x1c3e44 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x5f8> */
/* @0x1c3e58 cmp r8, #0 */
/* @0x1c3e5c movgt r9, r7 */
/* @0x1c3e60 movgt r10, #0 */
/* @0x1c3e64 ble 0x1c3e90 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x644> */
/* @0x1c3e68 ldr r3, [r9, #0x8] */
/* @0x1c3e6c mov r0, r11 */
/* @0x1c3e70 add r10, r10, #1 */
/* @0x1c3e74 cmp r3, #0 */
/* @0x1c3e78 ble 0x1c3e84 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x638> */
/* @0x1c3e7c ldm r9, {r1, r2} */
/* @0x1c3e80 bl 0x1c384c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_> */
/* @0x1c3e84 cmp r10, r8 */
/* @0x1c3e88 add r9, r9, #12 */
/* @0x1c3e8c bne 0x1c3e68 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x61c> */
/* @0x1c3e90 mov r0, r7 */
/* @0x1c3e94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c3e98 vldr s13, [r11] */
/* @0x1c3e9c vcvt.f32.s32 s15, s13 */
/* @0x1c3ea0 ldr r3, [r11, #0x4] */
/* @0x1c3ea4 vmul.f32 s15, s15, s16 */
/* @0x1c3ea8 vcvt.s32.f32 s15, s15 */
/* @0x1c3eac vstr s15, [r11, #12] */
/* @0x1c3eb0 b 0x1c3ca8 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x45c> */

/* ── FUNC 0x1c3eb4 · CHashMap<int, CLayerInstanceElement*, 7>::Insert(int, CLayerInstanceElement*) · size=1640 · insn=410 */
/* @0x1c3eb4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c3eb8 vpush {d8} */
/* @0x1c3ebc sub sp, sp, #60 */
/* @0x1c3ec0 ldr r3, [r0, #0x4] */
/* @0x1c3ec4 mov r11, r0 */
/* @0x1c3ec8 str r2, [sp, #0x24] */
/* @0x1c3ecc ldr r2, [r0, #0xc] */
/* @0x1c3ed0 str r1, [sp, #0x1c] */
/* @0x1c3ed4 cmp r3, r2 */
/* @0x1c3ed8 bgt 0x1c3fe8 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x134> */
/* @0x1c3edc add r3, r3, #1 */
/* @0x1c3ee0 ldr r0, [sp, #0x1c] */
/* @0x1c3ee4 str r3, [r11, #0x4] */
/* @0x1c3ee8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c3eec ldr r4, [r11, #0x8] */
/* @0x1c3ef0 ldr r6, [r11, #0x10] */
/* @0x1c3ef4 bic r0, r0, #-2147483648 */
/* @0x1c3ef8 and r3, r0, r4 */
/* @0x1c3efc add r2, r3, r3, lsl #1 */
/* @0x1c3f00 add r2, r6, r2, lsl #2 */
/* @0x1c3f04 ldr r12, [r2, #0x8] */
/* @0x1c3f08 cmp r12, #0 */
/* @0x1c3f0c beq 0x1c3fc8 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x114> */
/* @0x1c3f10 ldr r7, [r11] */
/* @0x1c3f14 mov r1, #0 */
/* @0x1c3f18 ldr r8, [sp, #0x1c] */
/* @0x1c3f1c ldr r9, [sp, #0x24] */
/* @0x1c3f20 b 0x1c3f68 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0xb4> */
/* @0x1c3f24 ldr r10, [r2] */
/* @0x1c3f28 mov r1, r5 */
/* @0x1c3f2c ldr r5, [r2, #0x4] */
/* @0x1c3f30 str r0, [r2, #0x8] */
/* @0x1c3f34 mov r0, r12 */
/* @0x1c3f38 str r8, [r2] */
/* @0x1c3f3c mov r8, r10 */
/* @0x1c3f40 str r9, [r2, #0x4] */
/* @0x1c3f44 mov r9, r5 */
/* @0x1c3f48 add r3, r3, #1 */
/* @0x1c3f4c add r1, r1, #1 */
/* @0x1c3f50 and r3, r3, r4 */
/* @0x1c3f54 add r2, r3, r3, lsl #1 */
/* @0x1c3f58 add r2, r6, r2, lsl #2 */
/* @0x1c3f5c ldr r12, [r2, #0x8] */
/* @0x1c3f60 cmp r12, #0 */
/* @0x1c3f64 beq 0x1c3fc0 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x10c> */
/* @0x1c3f68 add r5, r7, r3 */
/* @0x1c3f6c and r10, r12, r4 */
/* @0x1c3f70 rsb r5, r10, r5 */
/* @0x1c3f74 and r5, r5, r4 */
/* @0x1c3f78 cmp r5, r1 */
/* @0x1c3f7c blt 0x1c3f24 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x70> */
/* @0x1c3f80 cmp r1, r5 */
/* @0x1c3f84 bne 0x1c3f48 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x94> */
/* @0x1c3f88 cmp r0, r12 */
/* @0x1c3f8c bne 0x1c3f48 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x94> */
/* @0x1c3f90 ldr r12, [r2] */
/* @0x1c3f94 cmp r8, r12 */
/* @0x1c3f98 bne 0x1c3f48 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x94> */
/* @0x1c3f9c ldr r3, [r11, #0x4] */
/* @0x1c3fa0 str r8, [sp, #0x1c] */
/* @0x1c3fa4 str r8, [r2] */
/* @0x1c3fa8 sub r3, r3, #1 */
/* @0x1c3fac str r9, [r2, #0x4] */
/* @0x1c3fb0 str r0, [r2, #0x8] */
/* @0x1c3fb4 str r9, [sp, #0x24] */
/* @0x1c3fb8 str r3, [r11, #0x4] */
/* @0x1c3fbc b 0x1c3fdc <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x128> */
/* @0x1c3fc0 str r8, [sp, #0x1c] */
/* @0x1c3fc4 str r9, [sp, #0x24] */
/* @0x1c3fc8 ldr r12, [sp, #0x1c] */
/* @0x1c3fcc str r0, [r2, #0x8] */
/* @0x1c3fd0 str r12, [r2] */
/* @0x1c3fd4 ldr r12, [sp, #0x24] */
/* @0x1c3fd8 str r12, [r2, #0x4] */
/* @0x1c3fdc add sp, sp, #60 */
/* @0x1c3fe0 vpop {d8} */
/* @0x1c3fe4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c3fe8 ldr r12, [r0] */
/* @0x1c3fec mov r3, #1 */
/* @0x1c3ff0 ldr r1, [pc, #0x430] */
/* @0x1c3ff4 mov r2, #70 */
/* @0x1c3ff8 str r12, [sp, #0x20] */
/* @0x1c3ffc add r1, pc, r1 */
/* @0x1c4000 ldr r12, [r0, #0x10] */
/* @0x1c4004 str r12, [sp, #0x30] */
/* @0x1c4008 ldr r12, [sp, #0x20] */
/* @0x1c400c lsl r0, r12, r3 */
/* @0x1c4010 str r0, [r11] */
/* @0x1c4014 add r4, r0, r12, lsl #2 */
/* @0x1c4018 sub r0, r0, #1 */
/* @0x1c401c str r0, [r11, #0x8] */
/* @0x1c4020 lsl r4, r4, #2 */
/* @0x1c4024 mov r0, r4 */
/* @0x1c4028 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c402c mov r2, r4 */
/* @0x1c4030 mov r1, #0 */
/* @0x1c4034 str r0, [r11, #0x10] */
/* @0x1c4038 bl 0xb65b0 <memset@plt> */
/* @0x1c403c ldr r2, [r11] */
/* @0x1c4040 vldr s15, [pc, #988] */
/* @0x1c4044 mov r1, #0 */
/* @0x1c4048 cmp r2, r1 */
/* @0x1c404c str r1, [r11, #0x4] */
/* @0x1c4050 vmov s13, r2 */
/* @0x1c4054 vcvt.f32.s32 s14, s13 */
/* @0x1c4058 vmul.f32 s15, s14, s15 */
/* @0x1c405c vcvt.s32.f32 s15, s15 */
/* @0x1c4060 vstr s15, [r11, #12] */
/* @0x1c4064 ble 0x1c4084 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x1d0> */
/* @0x1c4068 add r2, r2, r2, lsl #1 */
/* @0x1c406c ldr r3, [r11, #0x10] */
/* @0x1c4070 add r2, r3, r2, lsl #2 */
/* @0x1c4074 str r1, [r3, #0x8] */
/* @0x1c4078 add r3, r3, #12 */
/* @0x1c407c cmp r3, r2 */
/* @0x1c4080 bne 0x1c4074 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x1c0> */
/* @0x1c4084 ldr r12, [sp, #0x20] */
/* @0x1c4088 cmp r12, #0 */
/* @0x1c408c ble 0x1c41f4 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x340> */
/* @0x1c4090 ldr r12, [pc, #0x394] */
/* @0x1c4094 vldr s16, [pc, #904] */
/* @0x1c4098 add r12, pc, r12 */
/* @0x1c409c str r12, [sp, #0x34] */
/* @0x1c40a0 mov r12, #0 */
/* @0x1c40a4 str r12, [sp, #0xc] */
/* @0x1c40a8 ldr r12, [pc, #0x380] */
/* @0x1c40ac add r12, pc, r12 */
/* @0x1c40b0 str r12, [sp, #0x2c] */
/* @0x1c40b4 ldr r12, [sp, #0x30] */
/* @0x1c40b8 str r12, [sp, #0x8] */
/* @0x1c40bc ldr r12, [sp, #0x8] */
/* @0x1c40c0 ldr r3, [r12, #0x8] */
/* @0x1c40c4 cmp r3, #0 */
/* @0x1c40c8 ble 0x1c41cc <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x318> */
/* @0x1c40cc ldr r12, [r12] */
/* @0x1c40d0 ldr r3, [r11, #0x4] */
/* @0x1c40d4 ldr r2, [r11, #0xc] */
/* @0x1c40d8 str r12, [sp, #0x10] */
/* @0x1c40dc ldr r12, [sp, #0x8] */
/* @0x1c40e0 cmp r3, r2 */
/* @0x1c40e4 ldr r12, [r12, #0x4] */
/* @0x1c40e8 str r12, [sp, #0x18] */
/* @0x1c40ec bgt 0x1c423c <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x388> */
/* @0x1c40f0 add r3, r3, #1 */
/* @0x1c40f4 ldr r0, [sp, #0x10] */
/* @0x1c40f8 str r3, [r11, #0x4] */
/* @0x1c40fc bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c4100 ldr lr, [r11, #0x8] */
/* @0x1c4104 ldr r6, [r11, #0x10] */
/* @0x1c4108 bic r0, r0, #-2147483648 */
/* @0x1c410c and r3, r0, lr */
/* @0x1c4110 add r2, r3, r3, lsl #1 */
/* @0x1c4114 add r2, r6, r2, lsl #2 */
/* @0x1c4118 ldr r1, [r2, #0x8] */
/* @0x1c411c cmp r1, #0 */
/* @0x1c4120 beq 0x1c4224 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x370> */
/* @0x1c4124 ldr r7, [r11] */
/* @0x1c4128 mov r4, #0 */
/* @0x1c412c ldr r8, [sp, #0x10] */
/* @0x1c4130 ldr r9, [sp, #0x18] */
/* @0x1c4134 b 0x1c4178 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x2c4> */
/* @0x1c4138 ldr r5, [r2] */
/* @0x1c413c ldr r4, [r2, #0x4] */
/* @0x1c4140 str r0, [r2, #0x8] */
/* @0x1c4144 mov r0, r1 */
/* @0x1c4148 str r8, [r2] */
/* @0x1c414c mov r8, r5 */
/* @0x1c4150 str r9, [r2, #0x4] */
/* @0x1c4154 mov r9, r4 */
/* @0x1c4158 add r3, r3, #1 */
/* @0x1c415c add r4, r12, #1 */
/* @0x1c4160 and r3, r3, lr */
/* @0x1c4164 add r2, r3, r3, lsl #1 */
/* @0x1c4168 add r2, r6, r2, lsl #2 */
/* @0x1c416c ldr r1, [r2, #0x8] */
/* @0x1c4170 cmp r1, #0 */
/* @0x1c4174 beq 0x1c421c <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x368> */
/* @0x1c4178 add r12, r7, r3 */
/* @0x1c417c and r5, r1, lr */
/* @0x1c4180 rsb r12, r5, r12 */
/* @0x1c4184 and r12, r12, lr */
/* @0x1c4188 cmp r12, r4 */
/* @0x1c418c blt 0x1c4138 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x284> */
/* @0x1c4190 movne r12, r4 */
/* @0x1c4194 bne 0x1c4158 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x2a4> */
/* @0x1c4198 cmp r1, r0 */
/* @0x1c419c bne 0x1c4158 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x2a4> */
/* @0x1c41a0 ldr r4, [r2] */
/* @0x1c41a4 cmp r8, r4 */
/* @0x1c41a8 bne 0x1c4158 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x2a4> */
/* @0x1c41ac ldr r3, [r11, #0x4] */
/* @0x1c41b0 str r8, [sp, #0x10] */
/* @0x1c41b4 str r8, [r2] */
/* @0x1c41b8 sub r3, r3, #1 */
/* @0x1c41bc str r9, [r2, #0x4] */
/* @0x1c41c0 str r1, [r2, #0x8] */
/* @0x1c41c4 str r9, [sp, #0x18] */
/* @0x1c41c8 str r3, [r11, #0x4] */
/* @0x1c41cc ldr r12, [sp, #0xc] */
/* @0x1c41d0 ldr r0, [sp, #0x20] */
/* @0x1c41d4 add r12, r12, #1 */
/* @0x1c41d8 str r12, [sp, #0xc] */
/* @0x1c41dc ldr r12, [sp, #0x8] */
/* @0x1c41e0 add r12, r12, #12 */
/* @0x1c41e4 str r12, [sp, #0x8] */
/* @0x1c41e8 ldr r12, [sp, #0xc] */
/* @0x1c41ec cmp r12, r0 */
/* @0x1c41f0 bne 0x1c40bc <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x208> */
/* @0x1c41f4 ldr r0, [sp, #0x30] */
/* @0x1c41f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c41fc vldr s13, [r11] */
/* @0x1c4200 vcvt.f32.s32 s14, s13 */
/* @0x1c4204 vldr s15, [pc, #536] */
/* @0x1c4208 ldr r3, [r11, #0x4] */
/* @0x1c420c vmul.f32 s15, s14, s15 */
/* @0x1c4210 vcvt.s32.f32 s15, s15 */
/* @0x1c4214 vstr s15, [r11, #12] */
/* @0x1c4218 b 0x1c3edc <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x28> */
/* @0x1c421c str r8, [sp, #0x10] */
/* @0x1c4220 str r9, [sp, #0x18] */
/* @0x1c4224 ldr r12, [sp, #0x10] */
/* @0x1c4228 str r0, [r2, #0x8] */
/* @0x1c422c str r12, [r2] */
/* @0x1c4230 ldr r12, [sp, #0x18] */
/* @0x1c4234 str r12, [r2, #0x4] */
/* @0x1c4238 b 0x1c41cc <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x318> */
/* @0x1c423c ldr r12, [r11] */
/* @0x1c4240 mov r3, #1 */
/* @0x1c4244 ldr r1, [sp, #0x34] */
/* @0x1c4248 mov r2, #70 */
/* @0x1c424c str r12, [sp, #0x14] */
/* @0x1c4250 ldr r12, [r11, #0x10] */
/* @0x1c4254 str r12, [sp, #0x28] */
/* @0x1c4258 ldr r12, [sp, #0x14] */
/* @0x1c425c lsl r0, r12, r3 */
/* @0x1c4260 str r0, [r11] */
/* @0x1c4264 add r4, r0, r12, lsl #2 */
/* @0x1c4268 sub r0, r0, #1 */
/* @0x1c426c str r0, [r11, #0x8] */
/* @0x1c4270 lsl r4, r4, #2 */
/* @0x1c4274 mov r0, r4 */
/* @0x1c4278 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c427c mov r2, r4 */
/* @0x1c4280 mov r1, #0 */
/* @0x1c4284 str r0, [r11, #0x10] */
/* @0x1c4288 bl 0xb65b0 <memset@plt> */
/* @0x1c428c ldr r2, [r11] */
/* @0x1c4290 mov r0, #0 */
/* @0x1c4294 str r0, [r11, #0x4] */
/* @0x1c4298 cmp r2, r0 */
/* @0x1c429c vmov s13, r2 */
/* @0x1c42a0 vcvt.f32.s32 s15, s13 */
/* @0x1c42a4 vmul.f32 s15, s15, s16 */
/* @0x1c42a8 vcvt.s32.f32 s15, s15 */
/* @0x1c42ac vstr s15, [r11, #12] */
/* @0x1c42b0 ble 0x1c42d4 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x420> */
/* @0x1c42b4 add r2, r2, r2, lsl #1 */
/* @0x1c42b8 ldr r3, [r11, #0x10] */
/* @0x1c42bc add r2, r3, r2, lsl #2 */
/* @0x1c42c0 mov r0, #0 */
/* @0x1c42c4 add r3, r3, #12 */
/* @0x1c42c8 str r0, [r3, #-0x4] */
/* @0x1c42cc cmp r3, r2 */
/* @0x1c42d0 bne 0x1c42c0 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x40c> */
/* @0x1c42d4 ldr r12, [sp, #0x14] */
/* @0x1c42d8 cmp r12, #0 */
/* @0x1c42dc ble 0x1c43f4 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x540> */
/* @0x1c42e0 ldr r6, [sp, #0x28] */
/* @0x1c42e4 mov r12, #0 */
/* @0x1c42e8 str r12, [sp, #0x4] */
/* @0x1c42ec ldr r3, [r6, #0x8] */
/* @0x1c42f0 cmp r3, #0 */
/* @0x1c42f4 ble 0x1c43d8 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x524> */
/* @0x1c42f8 ldr r3, [r11, #0x4] */
/* @0x1c42fc ldr r2, [r11, #0xc] */
/* @0x1c4300 ldr r4, [r6] */
/* @0x1c4304 cmp r3, r2 */
/* @0x1c4308 ldr r5, [r6, #0x4] */
/* @0x1c430c bgt 0x1c4434 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x580> */
/* @0x1c4310 add r3, r3, #1 */
/* @0x1c4314 mov r0, r4 */
/* @0x1c4318 str r3, [r11, #0x4] */
/* @0x1c431c bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c4320 ldr lr, [r11, #0x8] */
/* @0x1c4324 ldr r9, [r11, #0x10] */
/* @0x1c4328 bic r0, r0, #-2147483648 */
/* @0x1c432c and r3, r0, lr */
/* @0x1c4330 add r2, r3, r3, lsl #1 */
/* @0x1c4334 add r2, r9, r2, lsl #2 */
/* @0x1c4338 ldr r1, [r2, #0x8] */
/* @0x1c433c cmp r1, #0 */
/* @0x1c4340 ldrne r10, [r11] */
/* @0x1c4344 movne r7, #0 */
/* @0x1c4348 bne 0x1c4390 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x4dc> */
/* @0x1c434c b 0x1c4418 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x564> */
/* @0x1c4350 ldr r8, [r2] */
/* @0x1c4354 ldr r7, [r2, #0x4] */
/* @0x1c4358 str r0, [r2, #0x8] */
/* @0x1c435c mov r0, r1 */
/* @0x1c4360 str r4, [r2] */
/* @0x1c4364 mov r4, r8 */
/* @0x1c4368 str r5, [r2, #0x4] */
/* @0x1c436c mov r5, r7 */
/* @0x1c4370 add r3, r3, #1 */
/* @0x1c4374 add r7, r12, #1 */
/* @0x1c4378 and r3, r3, lr */
/* @0x1c437c add r2, r3, r3, lsl #1 */
/* @0x1c4380 add r2, r9, r2, lsl #2 */
/* @0x1c4384 ldr r1, [r2, #0x8] */
/* @0x1c4388 cmp r1, #0 */
/* @0x1c438c beq 0x1c4418 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x564> */
/* @0x1c4390 add r12, r3, r10 */
/* @0x1c4394 and r8, r1, lr */
/* @0x1c4398 rsb r12, r8, r12 */
/* @0x1c439c and r12, r12, lr */
/* @0x1c43a0 cmp r12, r7 */
/* @0x1c43a4 blt 0x1c4350 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x49c> */
/* @0x1c43a8 movne r12, r7 */
/* @0x1c43ac bne 0x1c4370 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x4bc> */
/* @0x1c43b0 cmp r1, r0 */
/* @0x1c43b4 bne 0x1c4370 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x4bc> */
/* @0x1c43b8 ldr r7, [r2] */
/* @0x1c43bc cmp r4, r7 */
/* @0x1c43c0 bne 0x1c4370 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x4bc> */
/* @0x1c43c4 ldr r3, [r11, #0x4] */
/* @0x1c43c8 stm r2, {r4, r5} */
/* @0x1c43cc sub r3, r3, #1 */
/* @0x1c43d0 str r1, [r2, #0x8] */
/* @0x1c43d4 str r3, [r11, #0x4] */
/* @0x1c43d8 ldr r12, [sp, #0x4] */
/* @0x1c43dc add r6, r6, #12 */
/* @0x1c43e0 ldr r0, [sp, #0x14] */
/* @0x1c43e4 add r12, r12, #1 */
/* @0x1c43e8 str r12, [sp, #0x4] */
/* @0x1c43ec cmp r12, r0 */
/* @0x1c43f0 bne 0x1c42ec <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x438> */
/* @0x1c43f4 ldr r0, [sp, #0x28] */
/* @0x1c43f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c43fc vldr s13, [r11] */
/* @0x1c4400 vcvt.f32.s32 s15, s13 */
/* @0x1c4404 ldr r3, [r11, #0x4] */
/* @0x1c4408 vmul.f32 s15, s15, s16 */
/* @0x1c440c vcvt.s32.f32 s15, s15 */
/* @0x1c4410 vstr s15, [r11, #12] */
/* @0x1c4414 b 0x1c40f0 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x23c> */
/* @0x1c4418 stm r2, {r4, r5} */
/* @0x1c441c str r0, [r2, #0x8] */
/* @0x1c4420 b 0x1c43d8 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x524> */
/* @0x1c4424 svclo #0x19999a */
/* @0x1c4428 andseq sp, r6, r4, lsr r0 */
/* @0x1c442c mulseq r6, r8, pc */
/* @0x1c4430 andseq r12, r6, r4, lsl #31 */
/* @0x1c4434 ldr r8, [r11] */
/* @0x1c4438 mov r3, #1 */
/* @0x1c443c ldr r1, [sp, #0x2c] */
/* @0x1c4440 mov r2, #70 */
/* @0x1c4444 ldr r7, [r11, #0x10] */
/* @0x1c4448 lsl r0, r8, r3 */
/* @0x1c444c str r0, [r11] */
/* @0x1c4450 add r9, r0, r8, lsl #2 */
/* @0x1c4454 sub r0, r0, #1 */
/* @0x1c4458 str r0, [r11, #0x8] */
/* @0x1c445c lsl r9, r9, #2 */
/* @0x1c4460 mov r0, r9 */
/* @0x1c4464 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4468 mov r2, r9 */
/* @0x1c446c mov r1, #0 */
/* @0x1c4470 str r0, [r11, #0x10] */
/* @0x1c4474 bl 0xb65b0 <memset@plt> */
/* @0x1c4478 ldr r2, [r11] */
/* @0x1c447c mov r0, #0 */
/* @0x1c4480 str r0, [r11, #0x4] */
/* @0x1c4484 cmp r2, r0 */
/* @0x1c4488 vmov s13, r2 */
/* @0x1c448c vcvt.f32.s32 s15, s13 */
/* @0x1c4490 vmul.f32 s15, s15, s16 */
/* @0x1c4494 vcvt.s32.f32 s15, s15 */
/* @0x1c4498 vstr s15, [r11, #12] */
/* @0x1c449c ble 0x1c44c0 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x60c> */
/* @0x1c44a0 add r2, r2, r2, lsl #1 */
/* @0x1c44a4 ldr r3, [r11, #0x10] */
/* @0x1c44a8 add r2, r3, r2, lsl #2 */
/* @0x1c44ac mov r0, #0 */
/* @0x1c44b0 add r3, r3, #12 */
/* @0x1c44b4 str r0, [r3, #-0x4] */
/* @0x1c44b8 cmp r3, r2 */
/* @0x1c44bc bne 0x1c44ac <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x5f8> */
/* @0x1c44c0 cmp r8, #0 */
/* @0x1c44c4 movgt r9, r7 */
/* @0x1c44c8 movgt r10, #0 */
/* @0x1c44cc ble 0x1c44f8 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x644> */
/* @0x1c44d0 ldr r3, [r9, #0x8] */
/* @0x1c44d4 mov r0, r11 */
/* @0x1c44d8 add r10, r10, #1 */
/* @0x1c44dc cmp r3, #0 */
/* @0x1c44e0 ble 0x1c44ec <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x638> */
/* @0x1c44e4 ldm r9, {r1, r2} */
/* @0x1c44e8 bl 0x1c3eb4 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_> */
/* @0x1c44ec cmp r10, r8 */
/* @0x1c44f0 add r9, r9, #12 */
/* @0x1c44f4 bne 0x1c44d0 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x61c> */
/* @0x1c44f8 mov r0, r7 */
/* @0x1c44fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c4500 vldr s13, [r11] */
/* @0x1c4504 vcvt.f32.s32 s15, s13 */
/* @0x1c4508 ldr r3, [r11, #0x4] */
/* @0x1c450c vmul.f32 s15, s15, s16 */
/* @0x1c4510 vcvt.s32.f32 s15, s15 */
/* @0x1c4514 vstr s15, [r11, #12] */
/* @0x1c4518 b 0x1c4310 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_+0x45c> */

/* ── FUNC 0x1c451c · CLayerManager::AddElementToLayer(CRoom*, CLayer*, CLayerElementBase*, bool) · size=708 · insn=177 */
/* @0x1c451c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c4520 cmp r3, #0 */
/* @0x1c4524 sub sp, sp, #12 */
/* @0x1c4528 mov r8, r0 */
/* @0x1c452c str r2, [sp, #0x4] */
/* @0x1c4530 beq 0x1c4570 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x54> */
/* @0x1c4534 ldr r3, [r1, #0x5c] */
/* @0x1c4538 ldr r2, [r1, #0x60] */
/* @0x1c453c cmp r3, #0 */
/* @0x1c4540 add r2, r2, #1 */
/* @0x1c4544 str r2, [r1, #0x60] */
/* @0x1c4548 beq 0x1c47a4 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x288> */
/* @0x1c454c ldr r2, [sp, #0x4] */
/* @0x1c4550 ldr r0, [sp, #0x4] */
/* @0x1c4554 str r2, [r3, #0x14] */
/* @0x1c4558 mov r3, #0 */
/* @0x1c455c ldr r2, [r1, #0x5c] */
/* @0x1c4560 str r2, [r0, #0x18] */
/* @0x1c4564 str r0, [r1, #0x5c] */
/* @0x1c4568 str r3, [r0, #0x14] */
/* @0x1c456c b 0x1c45a0 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x84> */
/* @0x1c4570 ldr r2, [r1, #0x58] */
/* @0x1c4574 ldr r0, [r1, #0x60] */
/* @0x1c4578 cmp r2, #0 */
/* @0x1c457c add r0, r0, #1 */
/* @0x1c4580 str r0, [r1, #0x60] */
/* @0x1c4584 beq 0x1c47a4 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x288> */
/* @0x1c4588 ldr r0, [sp, #0x4] */
/* @0x1c458c str r0, [r2, #0x18] */
/* @0x1c4590 ldr r2, [r1, #0x58] */
/* @0x1c4594 str r2, [r0, #0x14] */
/* @0x1c4598 str r0, [r1, #0x58] */
/* @0x1c459c str r3, [r0, #0x18] */
/* @0x1c45a0 ldr r3, [r8, #0xfc] */
/* @0x1c45a4 ldr r2, [r8, #0x104] */
/* @0x1c45a8 ldr r0, [sp, #0x4] */
/* @0x1c45ac cmp r3, r2 */
/* @0x1c45b0 str r1, [r0, #0x10] */
/* @0x1c45b4 ldr r7, [r0, #0x4] */
/* @0x1c45b8 bgt 0x1c46b0 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x194> */
/* @0x1c45bc add r3, r3, #1 */
/* @0x1c45c0 mov r0, r7 */
/* @0x1c45c4 str r3, [r8, #0xfc] */
/* @0x1c45c8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c45cc ldr r4, [r8, #0x100] */
/* @0x1c45d0 ldr r10, [r8, #0x108] */
/* @0x1c45d4 bic r0, r0, #-2147483648 */
/* @0x1c45d8 and r3, r0, r4 */
/* @0x1c45dc add r2, r3, r3, lsl #1 */
/* @0x1c45e0 add r2, r10, r2, lsl #2 */
/* @0x1c45e4 ldr r1, [r2, #0x8] */
/* @0x1c45e8 cmp r1, #0 */
/* @0x1c45ec beq 0x1c468c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x170> */
/* @0x1c45f0 ldr r11, [r8, #0xf8] */
/* @0x1c45f4 mov r5, #0 */
/* @0x1c45f8 ldr r9, [sp, #0x4] */
/* @0x1c45fc b 0x1c4640 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x124> */
/* @0x1c4600 ldr r6, [r2] */
/* @0x1c4604 ldr r5, [r2, #0x4] */
/* @0x1c4608 str r0, [r2, #0x8] */
/* @0x1c460c mov r0, r1 */
/* @0x1c4610 str r7, [r2] */
/* @0x1c4614 mov r7, r6 */
/* @0x1c4618 str r9, [r2, #0x4] */
/* @0x1c461c mov r9, r5 */
/* @0x1c4620 add r3, r3, #1 */
/* @0x1c4624 add r5, r12, #1 */
/* @0x1c4628 and r3, r3, r4 */
/* @0x1c462c add r2, r3, r3, lsl #1 */
/* @0x1c4630 add r2, r10, r2, lsl #2 */
/* @0x1c4634 ldr r1, [r2, #0x8] */
/* @0x1c4638 cmp r1, #0 */
/* @0x1c463c beq 0x1c4690 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x174> */
/* @0x1c4640 add r12, r11, r3 */
/* @0x1c4644 and r6, r1, r4 */
/* @0x1c4648 rsb r12, r6, r12 */
/* @0x1c464c and r12, r12, r4 */
/* @0x1c4650 cmp r12, r5 */
/* @0x1c4654 blt 0x1c4600 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0xe4> */
/* @0x1c4658 movne r12, r5 */
/* @0x1c465c bne 0x1c4620 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x104> */
/* @0x1c4660 cmp r1, r0 */
/* @0x1c4664 bne 0x1c4620 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x104> */
/* @0x1c4668 ldr r5, [r2] */
/* @0x1c466c cmp r7, r5 */
/* @0x1c4670 bne 0x1c4620 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x104> */
/* @0x1c4674 ldr r3, [r8, #0xfc] */
/* @0x1c4678 stm r2, {r7, r9} */
/* @0x1c467c sub r3, r3, #1 */
/* @0x1c4680 str r1, [r2, #0x8] */
/* @0x1c4684 str r3, [r8, #0xfc] */
/* @0x1c4688 b 0x1c4698 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x17c> */
/* @0x1c468c ldr r9, [sp, #0x4] */
/* @0x1c4690 stm r2, {r7, r9} */
/* @0x1c4694 str r0, [r2, #0x8] */
/* @0x1c4698 ldr r0, [sp, #0x4] */
/* @0x1c469c ldr r3, [r0] */
/* @0x1c46a0 cmp r3, #2 */
/* @0x1c46a4 beq 0x1c47c0 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x2a4> */
/* @0x1c46a8 add sp, sp, #12 */
/* @0x1c46ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c46b0 ldr r9, [r8, #0xf8] */
/* @0x1c46b4 mov r3, #1 */
/* @0x1c46b8 ldr r1, [pc, #0x11c] */
/* @0x1c46bc mov r2, #70 */
/* @0x1c46c0 ldr r6, [r8, #0x108] */
/* @0x1c46c4 lsl r0, r9, r3 */
/* @0x1c46c8 add r1, pc, r1 */
/* @0x1c46cc add r4, r0, r9, lsl #2 */
/* @0x1c46d0 str r0, [r8, #0xf8] */
/* @0x1c46d4 sub r0, r0, #1 */
/* @0x1c46d8 str r0, [r8, #0x100] */
/* @0x1c46dc lsl r4, r4, #2 */
/* @0x1c46e0 mov r0, r4 */
/* @0x1c46e4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c46e8 mov r2, r4 */
/* @0x1c46ec mov r1, #0 */
/* @0x1c46f0 str r0, [r8, #0x108] */
/* @0x1c46f4 bl 0xb65b0 <memset@plt> */
/* @0x1c46f8 ldr r2, [r8, #0xf8] */
/* @0x1c46fc vldr s15, [pc, #212] */
/* @0x1c4700 mov r1, #0 */
/* @0x1c4704 cmp r2, r1 */
/* @0x1c4708 str r1, [r8, #0xfc] */
/* @0x1c470c vmov s13, r2 */
/* @0x1c4710 vcvt.f32.s32 s14, s13 */
/* @0x1c4714 vmul.f32 s15, s14, s15 */
/* @0x1c4718 vcvt.s32.f32 s15, s15 */
/* @0x1c471c vstr s15, [r8, #260] */
/* @0x1c4720 ble 0x1c4740 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x224> */
/* @0x1c4724 add r2, r2, r2, lsl #1 */
/* @0x1c4728 ldr r3, [r8, #0x108] */
/* @0x1c472c add r2, r3, r2, lsl #2 */
/* @0x1c4730 str r1, [r3, #0x8] */
/* @0x1c4734 add r3, r3, #12 */
/* @0x1c4738 cmp r3, r2 */
/* @0x1c473c bne 0x1c4730 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x214> */
/* @0x1c4740 cmp r9, #0 */
/* @0x1c4744 addgt r10, r8, #248 */
/* @0x1c4748 movgt r4, r6 */
/* @0x1c474c movgt r5, #0 */
/* @0x1c4750 ble 0x1c477c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x260> */
/* @0x1c4754 ldr r3, [r4, #0x8] */
/* @0x1c4758 mov r0, r10 */
/* @0x1c475c add r5, r5, #1 */
/* @0x1c4760 cmp r3, #0 */
/* @0x1c4764 ble 0x1c4770 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x254> */
/* @0x1c4768 ldm r4, {r1, r2} */
/* @0x1c476c bl 0x1c384c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_> */
/* @0x1c4770 cmp r5, r9 */
/* @0x1c4774 add r4, r4, #12 */
/* @0x1c4778 bne 0x1c4754 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x238> */
/* @0x1c477c mov r0, r6 */
/* @0x1c4780 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c4784 vldr s13, [r8, #248] */
/* @0x1c4788 vcvt.f32.s32 s14, s13 */
/* @0x1c478c vldr s15, [pc, #68] */
/* @0x1c4790 ldr r3, [r8, #0xfc] */
/* @0x1c4794 vmul.f32 s15, s14, s15 */
/* @0x1c4798 vcvt.s32.f32 s15, s15 */
/* @0x1c479c vstr s15, [r8, #260] */
/* @0x1c47a0 b 0x1c45bc <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0xa0> */
/* @0x1c47a4 ldr r0, [sp, #0x4] */
/* @0x1c47a8 mov r3, #0 */
/* @0x1c47ac str r0, [r1, #0x5c] */
/* @0x1c47b0 str r0, [r1, #0x58] */
/* @0x1c47b4 str r3, [r0, #0x18] */
/* @0x1c47b8 str r3, [r0, #0x14] */
/* @0x1c47bc b 0x1c45a0 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x84> */
/* @0x1c47c0 ldr r2, [sp, #0x4] */
/* @0x1c47c4 add r0, r8, #272 */
/* @0x1c47c8 ldr r1, [r2, #0x1c] */
/* @0x1c47cc add sp, sp, #12 */
/* @0x1c47d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c47d4 b 0x1c3eb4 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_> */
/* @0x1c47d8 svclo #0x19999a */
/* @0x1c47dc andseq r12, r6, r8, ror #18 */

/* ── FUNC 0x1c47e0 · CLayerManager::DuplicateRoomLayers(CRoom*, CRoom*) · size=4692 · insn=1171 */
/* @0x1c47e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c47e4 vpush {d8, d9} */
/* @0x1c47e8 subs r4, r0, #0 */
/* @0x1c47ec sub sp, sp, #68 */
/* @0x1c47f0 ldr r12, [pc, #0x470] */
/* @0x1c47f4 str r4, [sp, #0xc] */
/* @0x1c47f8 add r12, pc, r12 */
/* @0x1c47fc mov r4, r1 */
/* @0x1c4800 str r12, [sp, #0x24] */
/* @0x1c4804 beq 0x1c4f44 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x764> */
/* @0x1c4808 cmp r1, #0 */
/* @0x1c480c beq 0x1c4f44 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x764> */
/* @0x1c4810 bl 0x1b93c8 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom> */
/* @0x1c4814 ldr r12, [sp, #0xc] */
/* @0x1c4818 ldr lr, [sp, #0xc] */
/* @0x1c481c mov r2, #70 */
/* @0x1c4820 ldr r1, [pc, #0x444] */
/* @0x1c4824 mov r3, #1 */
/* @0x1c4828 ldr r0, [r12, #0xe4] */
/* @0x1c482c add r1, pc, r1 */
/* @0x1c4830 sub r12, r0, #1 */
/* @0x1c4834 str r12, [lr, #0xec] */
/* @0x1c4838 add r0, r0, r0, lsl #1 */
/* @0x1c483c add r12, lr, #228 */
/* @0x1c4840 str r12, [sp, #0x28] */
/* @0x1c4844 lsl r5, r0, #2 */
/* @0x1c4848 mov r0, r5 */
/* @0x1c484c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4850 ldr r12, [sp, #0xc] */
/* @0x1c4854 mov r2, r5 */
/* @0x1c4858 mov r1, #0 */
/* @0x1c485c str r0, [r12, #0xf4] */
/* @0x1c4860 bl 0xb65b0 <memset@plt> */
/* @0x1c4864 ldr r12, [sp, #0xc] */
/* @0x1c4868 vldr s15, [pc, #1008] */
/* @0x1c486c mov r1, #0 */
/* @0x1c4870 ldr r2, [r12, #0xe4] */
/* @0x1c4874 str r1, [r12, #0xe8] */
/* @0x1c4878 cmp r2, r1 */
/* @0x1c487c vmov s13, r2 */
/* @0x1c4880 vcvt.f32.s32 s14, s13 */
/* @0x1c4884 vmul.f32 s15, s14, s15 */
/* @0x1c4888 vcvt.s32.f32 s15, s15 */
/* @0x1c488c vstr s15, [r12, #240] */
/* @0x1c4890 ble 0x1c48b4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xd4> */
/* @0x1c4894 ldr r12, [sp, #0xc] */
/* @0x1c4898 add r2, r2, r2, lsl #1 */
/* @0x1c489c ldr r3, [r12, #0xf4] */
/* @0x1c48a0 add r2, r3, r2, lsl #2 */
/* @0x1c48a4 str r1, [r3, #0x8] */
/* @0x1c48a8 add r3, r3, #12 */
/* @0x1c48ac cmp r3, r2 */
/* @0x1c48b0 bne 0x1c48a4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xc4> */
/* @0x1c48b4 ldr r12, [sp, #0xc] */
/* @0x1c48b8 mov r2, #70 */
/* @0x1c48bc ldr lr, [sp, #0xc] */
/* @0x1c48c0 mov r3, #1 */
/* @0x1c48c4 ldr r1, [pc, #0x3a4] */
/* @0x1c48c8 ldr r0, [r12, #0xf8] */
/* @0x1c48cc add r1, pc, r1 */
/* @0x1c48d0 sub r12, r0, #1 */
/* @0x1c48d4 str r12, [lr, #0x100] */
/* @0x1c48d8 add r0, r0, r0, lsl #1 */
/* @0x1c48dc lsl r5, r0, #2 */
/* @0x1c48e0 mov r0, r5 */
/* @0x1c48e4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c48e8 ldr r12, [sp, #0xc] */
/* @0x1c48ec mov r2, r5 */
/* @0x1c48f0 mov r1, #0 */
/* @0x1c48f4 str r0, [r12, #0x108] */
/* @0x1c48f8 bl 0xb65b0 <memset@plt> */
/* @0x1c48fc ldr r12, [sp, #0xc] */
/* @0x1c4900 vldr s15, [pc, #856] */
/* @0x1c4904 mov r1, #0 */
/* @0x1c4908 ldr r2, [r12, #0xf8] */
/* @0x1c490c str r1, [r12, #0xfc] */
/* @0x1c4910 cmp r2, r1 */
/* @0x1c4914 vmov s13, r2 */
/* @0x1c4918 vcvt.f32.s32 s14, s13 */
/* @0x1c491c vmul.f32 s15, s14, s15 */
/* @0x1c4920 vcvt.s32.f32 s15, s15 */
/* @0x1c4924 vstr s15, [r12, #260] */
/* @0x1c4928 ble 0x1c494c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x16c> */
/* @0x1c492c ldr r12, [sp, #0xc] */
/* @0x1c4930 add r2, r2, r2, lsl #1 */
/* @0x1c4934 ldr r3, [r12, #0x108] */
/* @0x1c4938 add r2, r3, r2, lsl #2 */
/* @0x1c493c str r1, [r3, #0x8] */
/* @0x1c4940 add r3, r3, #12 */
/* @0x1c4944 cmp r3, r2 */
/* @0x1c4948 bne 0x1c493c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x15c> */
/* @0x1c494c ldr r12, [sp, #0xc] */
/* @0x1c4950 mov r2, #70 */
/* @0x1c4954 ldr lr, [sp, #0xc] */
/* @0x1c4958 mov r3, #1 */
/* @0x1c495c ldr r1, [pc, #0x310] */
/* @0x1c4960 ldr r0, [r12, #0x110] */
/* @0x1c4964 add r1, pc, r1 */
/* @0x1c4968 sub r12, r0, #1 */
/* @0x1c496c str r12, [lr, #0x118] */
/* @0x1c4970 add r0, r0, r0, lsl #1 */
/* @0x1c4974 lsl r5, r0, #2 */
/* @0x1c4978 mov r0, r5 */
/* @0x1c497c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4980 ldr r12, [sp, #0xc] */
/* @0x1c4984 mov r2, r5 */
/* @0x1c4988 mov r1, #0 */
/* @0x1c498c str r0, [r12, #0x120] */
/* @0x1c4990 bl 0xb65b0 <memset@plt> */
/* @0x1c4994 ldr r12, [sp, #0xc] */
/* @0x1c4998 vldr s15, [pc, #704] */
/* @0x1c499c mov r1, #0 */
/* @0x1c49a0 ldr r2, [r12, #0x110] */
/* @0x1c49a4 str r1, [r12, #0x114] */
/* @0x1c49a8 cmp r2, r1 */
/* @0x1c49ac vmov s13, r2 */
/* @0x1c49b0 vcvt.f32.s32 s14, s13 */
/* @0x1c49b4 vmul.f32 s15, s14, s15 */
/* @0x1c49b8 vcvt.s32.f32 s15, s15 */
/* @0x1c49bc vstr s15, [r12, #284] */
/* @0x1c49c0 ble 0x1c49e4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x204> */
/* @0x1c49c4 ldr r12, [sp, #0xc] */
/* @0x1c49c8 add r2, r2, r2, lsl #1 */
/* @0x1c49cc ldr r3, [r12, #0x120] */
/* @0x1c49d0 add r2, r3, r2, lsl #2 */
/* @0x1c49d4 str r1, [r3, #0x8] */
/* @0x1c49d8 add r3, r3, #12 */
/* @0x1c49dc cmp r3, r2 */
/* @0x1c49e0 bne 0x1c49d4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x1f4> */
/* @0x1c49e4 ldr r4, [r4, #0xd4] */
/* @0x1c49e8 cmp r4, #0 */
/* @0x1c49ec str r4, [sp, #0x8] */
/* @0x1c49f0 beq 0x1c4f44 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x764> */
/* @0x1c49f4 ldr r4, [pc, #0x27c] */
/* @0x1c49f8 vldr s18, [pc, #612] */
/* @0x1c49fc ldr r3, [pc, #0x278] */
/* @0x1c4a00 vldr d8, [pc, #592] */
/* @0x1c4a04 add r4, pc, r4 */
/* @0x1c4a08 str r4, [sp, #0x34] */
/* @0x1c4a0c ldr r4, [sp, #0x24] */
/* @0x1c4a10 ldr r12, [pc, #0x268] */
/* @0x1c4a14 add r12, pc, r12 */
/* @0x1c4a18 str r12, [sp, #0x38] */
/* @0x1c4a1c ldr r11, [r4, r3] */
/* @0x1c4a20 ldr r12, [pc, #0x25c] */
/* @0x1c4a24 ldr r4, [pc, #0x25c] */
/* @0x1c4a28 mov r10, r11 */
/* @0x1c4a2c add r12, pc, r12 */
/* @0x1c4a30 add r4, pc, r4 */
/* @0x1c4a34 str r12, [sp, #0x2c] */
/* @0x1c4a38 str r4, [sp, #0x30] */
/* @0x1c4a3c ldr r4, [r10, #0x8] */
/* @0x1c4a40 cmp r4, #0 */
/* @0x1c4a44 bne 0x1c4b28 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x348> */
/* @0x1c4a48 ldr r3, [r10, #0x10] */
/* @0x1c4a4c cmp r3, #0 */
/* @0x1c4a50 ble 0x1c4b20 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x340> */
/* @0x1c4a54 ldr r8, [sp, #0x34] */
/* @0x1c4a58 mov r5, #1 */
/* @0x1c4a5c mov r3, #1 */
/* @0x1c4a60 mov r0, #112 */
/* @0x1c4a64 mov r1, r8 */
/* @0x1c4a68 mov r2, #63 */
/* @0x1c4a6c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4a70 mov r7, #0 */
/* @0x1c4a74 mvn r3, #0 */
/* @0x1c4a78 subs r6, r0, #0 */
/* @0x1c4a7c add r0, r6, #48 */
/* @0x1c4a80 beq 0x1c4ad4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x2f4> */
/* @0x1c4a84 str r3, [r6] */
/* @0x1c4a88 vstr s18, [r6, #8] */
/* @0x1c4a8c str r7, [r6, #0x4] */
/* @0x1c4a90 vstr s18, [r6, #12] */
/* @0x1c4a94 vstr s18, [r6, #16] */
/* @0x1c4a98 vstr s18, [r6, #20] */
/* @0x1c4a9c strb r5, [r6, #0x18] */
/* @0x1c4aa0 vstr d8, [r6, #72] */
/* @0x1c4aa4 strb r7, [r6, #0x19] */
/* @0x1c4aa8 str r7, [r6, #0x1c] */
/* @0x1c4aac str r3, [r6, #0x20] */
/* @0x1c4ab0 str r3, [r6, #0x24] */
/* @0x1c4ab4 str r3, [r6, #0x28] */
/* @0x1c4ab8 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1c4abc str r7, [r6, #0x5c] */
/* @0x1c4ac0 str r7, [r6, #0x58] */
/* @0x1c4ac4 str r7, [r6, #0x60] */
/* @0x1c4ac8 str r5, [r6, #0x64] */
/* @0x1c4acc str r7, [r6, #0x68] */
/* @0x1c4ad0 str r7, [r6, #0x6c] */
/* @0x1c4ad4 ldr r3, [r10] */
/* @0x1c4ad8 mov r1, #0 */
/* @0x1c4adc add r4, r4, #1 */
/* @0x1c4ae0 ldr r2, [r10, #0x8] */
/* @0x1c4ae4 cmp r3, r1 */
/* @0x1c4ae8 streq r6, [r10, #0x4] */
/* @0x1c4aec strne r6, [r3, #0x6c] */
/* @0x1c4af0 add r2, r2, #1 */
/* @0x1c4af4 streq r3, [r6, #0x6c] */
/* @0x1c4af8 streq r3, [r6, #0x68] */
/* @0x1c4afc strne r3, [r6, #0x68] */
/* @0x1c4b00 ldr r3, [r10, #0x10] */
/* @0x1c4b04 streq r6, [r10] */
/* @0x1c4b08 strne r6, [r10] */
/* @0x1c4b0c strne r1, [r6, #0x6c] */
/* @0x1c4b10 cmp r4, r3 */
/* @0x1c4b14 str r2, [r10, #0x8] */
/* @0x1c4b18 blt 0x1c4a5c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x27c> */
/* @0x1c4b1c ldr r4, [r10, #0x8] */
/* @0x1c4b20 lsl r3, r3, #1 */
/* @0x1c4b24 str r3, [r10, #0x10] */
/* @0x1c4b28 ldr r12, [r10] */
/* @0x1c4b2c sub r4, r4, #1 */
/* @0x1c4b30 ldr r3, [r12, #0x6c] */
/* @0x1c4b34 str r12, [sp, #0x4] */
/* @0x1c4b38 cmp r3, #0 */
/* @0x1c4b3c ldrne r12, [sp, #0x4] */
/* @0x1c4b40 ldreq r2, [r12, #0x68] */
/* @0x1c4b44 ldrne r2, [r12, #0x68] */
/* @0x1c4b48 streq r2, [r10] */
/* @0x1c4b4c strne r2, [r3, #0x68] */
/* @0x1c4b50 ldrne r2, [r12, #0x68] */
/* @0x1c4b54 ldrne r3, [r12, #0x6c] */
/* @0x1c4b58 ldr r12, [sp, #0x8] */
/* @0x1c4b5c cmp r2, #0 */
/* @0x1c4b60 streq r3, [r10, #0x4] */
/* @0x1c4b64 strne r3, [r2, #0x6c] */
/* @0x1c4b68 ldr r1, [r12, #0x8] */
/* @0x1c4b6c ldr r2, [r12] */
/* @0x1c4b70 ldr r3, [r12, #0x4] */
/* @0x1c4b74 str r4, [r10, #0x8] */
/* @0x1c4b78 ldr r4, [sp, #0x4] */
/* @0x1c4b7c ldr r0, [r12, #0x1c] */
/* @0x1c4b80 str r1, [r4, #0x8] */
/* @0x1c4b84 mov r4, r12 */
/* @0x1c4b88 ldr r1, [r4, #0x20] */
/* @0x1c4b8c cmp r0, #0 */
/* @0x1c4b90 ldr r4, [sp, #0x4] */
/* @0x1c4b94 ldrb r12, [r12, #0x18] */
/* @0x1c4b98 str r2, [r4] */
/* @0x1c4b9c ldr r4, [sp, #0x8] */
/* @0x1c4ba0 ldr r2, [r4, #0x24] */
/* @0x1c4ba4 ldr r4, [sp, #0x4] */
/* @0x1c4ba8 str r3, [r4, #0x4] */
/* @0x1c4bac ldr r4, [sp, #0x8] */
/* @0x1c4bb0 ldr r3, [r4, #0xc] */
/* @0x1c4bb4 ldr r4, [sp, #0x4] */
/* @0x1c4bb8 str r3, [r4, #0xc] */
/* @0x1c4bbc ldr r4, [sp, #0x8] */
/* @0x1c4bc0 ldr r3, [r4, #0x28] */
/* @0x1c4bc4 ldr lr, [r4, #0x10] */
/* @0x1c4bc8 ldr r4, [sp, #0x4] */
/* @0x1c4bcc str lr, [r4, #0x10] */
/* @0x1c4bd0 ldr r4, [sp, #0x8] */
/* @0x1c4bd4 ldr lr, [r4, #0x14] */
/* @0x1c4bd8 ldr r4, [sp, #0x4] */
/* @0x1c4bdc strb r12, [r4, #0x18] */
/* @0x1c4be0 str lr, [r4, #0x14] */
/* @0x1c4be4 str r1, [r4, #0x20] */
/* @0x1c4be8 str r2, [r4, #0x24] */
/* @0x1c4bec str r3, [r4, #0x28] */
/* @0x1c4bf0 beq 0x1c59fc <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x121c> */
/* @0x1c4bf4 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1c4bf8 ldr r12, [sp, #0x8] */
/* @0x1c4bfc cmp r0, #0 */
/* @0x1c4c00 ldr r0, [r12, #0x1c] */
/* @0x1c4c04 bne 0x1c59fc <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x121c> */
/* @0x1c4c08 bl 0xb6538 <strlen@plt> */
/* @0x1c4c0c mov r3, #1 */
/* @0x1c4c10 ldr r1, [sp, #0x38] */
/* @0x1c4c14 movw r2, #0x249 */
/* @0x1c4c18 add r4, r0, r3 */
/* @0x1c4c1c mov r0, r4 */
/* @0x1c4c20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4c24 mov r2, r4 */
/* @0x1c4c28 ldr r12, [sp, #0x8] */
/* @0x1c4c2c ldr r4, [sp, #0x4] */
/* @0x1c4c30 str r0, [r4, #0x1c] */
/* @0x1c4c34 ldr r1, [r12, #0x1c] */
/* @0x1c4c38 bl 0xb65bc <memcpy@plt> */
/* @0x1c4c3c ldr r4, [sp, #0x8] */
/* @0x1c4c40 ldr r11, [r4, #0x58] */
/* @0x1c4c44 cmp r11, #0 */
/* @0x1c4c48 beq 0x1c4ee0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x700> */
/* @0x1c4c4c ldr r4, [pc, #0x38] */
/* @0x1c4c50 str r10, [sp, #0x14] */
/* @0x1c4c54 b 0x1c4cd0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x4f0> */
/* @0x1c4c60 svclo #0x19999a */
/* @0x1c4c64 andeq r0, r0, r0 */
/* @0x1c4c68 eoreq sp, r2, r8, asr r4 */
/* @0x1c4c6c andseq r12, r6, r4, lsl #16 */
/* @0x1c4c70 andseq r12, r6, r4, ror #14 */
/* @0x1c4c74 andseq r12, r6, r12, asr #13 */
/* @0x1c4c78 mulseq r8, r0, r12 */
/* @0x1c4c7c .word 0xffffec0c */
/* @0x1c4c80 andseq r8, r8, r8, asr sp */
/* @0x1c4c84 andseq r8, r8, r8, ror #24 */
/* @0x1c4c88 andseq r8, r8, r4, ror #24 */
/* @0x1c4c8c mulseq r8, r8, r10 */
/* @0x1c4c90 ldrheq r8, [r8], -r0 */
/* @0x1c4c94 andseq r8, r8, r8, lsr #19 */
/* @0x1c4c98 .word 0xffffec28 */
/* @0x1c4c9c .word 0xffffec24 */
/* @0x1c4ca0 .word 0xffffec20 */
/* @0x1c4ca4 .word 0xffffec1c */
/* @0x1c4ca8 .word 0xffffec14 */
/* @0x1c4cac andseq r8, r8, r4, asr #5 */
/* @0x1c4cb0 .word 0xffffec18 */
/* @0x1c4cb4 mulseq r8, r4, r1 */
/* @0x1c4cb8 andseq r8, r8, r4, ror #2 */
/* @0x1c4cbc .word 0xffffec2c */
/* @0x1c4cc0 andseq r7, r8, r8, asr #31 */
/* @0x1c4cc4 .word 0xffffec10 */
/* @0x1c4cc8 andseq r7, r8, r12, asr #28 */
/* @0x1c4ccc andseq r7, r8, r0, lsl #29 */
/* @0x1c4cd0 ldr r10, [sp, #0x24] */
/* @0x1c4cd4 add r4, pc, r4 */
/* @0x1c4cd8 ldr r12, [pc, #-0x50] */
/* @0x1c4cdc str r4, [sp, #0x10] */
/* @0x1c4ce0 ldr r4, [pc, #-0x54] */
/* @0x1c4ce4 add r12, pc, r12 */
/* @0x1c4ce8 str r12, [sp, #0x18] */
/* @0x1c4cec add r4, pc, r4 */
/* @0x1c4cf0 str r4, [sp, #0x1c] */
/* @0x1c4cf4 ldr r3, [r11] */
/* @0x1c4cf8 sub r3, r3, #1 */
/* @0x1c4cfc cmp r3, #6 */
/* @0x1c4d00 addls pc, pc, r3, lsl #2 */
/* @0x1c4d04 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* @0x1c4d08 b 0x1c580c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x102c> */
/* @0x1c4d0c b 0x1c53a4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xbc4> */
/* @0x1c4d10 b 0x1c54c4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xce4> */
/* @0x1c4d14 b 0x1c520c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xa2c> */
/* @0x1c4d18 b 0x1c5070 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x890> */
/* @0x1c4d1c b 0x1c4f50 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x770> */
/* @0x1c4d20 b 0x1c4d24 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x544> */
/* @0x1c4d24 ldr r3, [pc, #-0x94] */
/* @0x1c4d28 ldr r5, [r10, r3] */
/* @0x1c4d2c ldr r6, [r5, #0x8] */
/* @0x1c4d30 cmp r6, #0 */
/* @0x1c4d34 bne 0x1c4e10 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x630> */
/* @0x1c4d38 ldr r3, [r5, #0x10] */
/* @0x1c4d3c cmp r3, #0 */
/* @0x1c4d40 ble 0x1c4e08 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x628> */
/* @0x1c4d44 ldr r7, [sp, #0x2c] */
/* @0x1c4d48 mov r4, r6 */
/* @0x1c4d4c mov r2, #63 */
/* @0x1c4d50 mov r3, #1 */
/* @0x1c4d54 mov r0, #80 */
/* @0x1c4d58 mov r1, r7 */
/* @0x1c4d5c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4d60 ldr r3, [r5] */
/* @0x1c4d64 mvn r2, #0 */
/* @0x1c4d68 mov r12, #7 */
/* @0x1c4d6c cmp r0, #0 */
/* @0x1c4d70 beq 0x1c4dc4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x5e4> */
/* @0x1c4d74 mov r1, #1065353216 */
/* @0x1c4d78 strb r4, [r0, #0x8] */
/* @0x1c4d7c str r4, [r0, #0xc] */
/* @0x1c4d80 vstr s18, [r0, #36] */
/* @0x1c4d84 str r4, [r0, #0x10] */
/* @0x1c4d88 vstr s18, [r0, #40] */
/* @0x1c4d8c str r4, [r0, #0x14] */
/* @0x1c4d90 vstr s18, [r0, #60] */
/* @0x1c4d94 str r4, [r0, #0x18] */
/* @0x1c4d98 str r2, [r0, #0x4] */
/* @0x1c4d9c str r2, [r0, #0x20] */
/* @0x1c4da0 str r4, [r0, #0x2c] */
/* @0x1c4da4 str r4, [r0, #0x30] */
/* @0x1c4da8 str r2, [r0, #0x40] */
/* @0x1c4dac str r4, [r0, #0x48] */
/* @0x1c4db0 str r1, [r0, #0x34] */
/* @0x1c4db4 str r4, [r0, #0x4c] */
/* @0x1c4db8 str r1, [r0, #0x38] */
/* @0x1c4dbc str r12, [r0] */
/* @0x1c4dc0 str r1, [r0, #0x44] */
/* @0x1c4dc4 cmp r3, #0 */
/* @0x1c4dc8 strne r0, [r3, #0x18] */
/* @0x1c4dcc streq r3, [r0, #0x18] */
/* @0x1c4dd0 add r6, r6, #1 */
/* @0x1c4dd4 streq r3, [r0, #0x14] */
/* @0x1c4dd8 strne r3, [r0, #0x14] */
/* @0x1c4ddc ldr r3, [r5, #0x10] */
/* @0x1c4de0 ldr r2, [r5, #0x8] */
/* @0x1c4de4 streq r0, [r5, #0x4] */
/* @0x1c4de8 streq r0, [r5] */
/* @0x1c4dec add r2, r2, #1 */
/* @0x1c4df0 strne r0, [r5] */
/* @0x1c4df4 strne r4, [r0, #0x18] */
/* @0x1c4df8 cmp r6, r3 */
/* @0x1c4dfc str r2, [r5, #0x8] */
/* @0x1c4e00 blt 0x1c4d4c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x56c> */
/* @0x1c4e04 ldr r6, [r5, #0x8] */
/* @0x1c4e08 lsl r3, r3, #1 */
/* @0x1c4e0c str r3, [r5, #0x10] */
/* @0x1c4e10 ldr r3, [r5] */
/* @0x1c4e14 sub r6, r6, #1 */
/* @0x1c4e18 ldr r12, [r11, #0x4] */
/* @0x1c4e1c ldr lr, [r11, #0x34] */
/* @0x1c4e20 ldr r2, [r3, #0x18] */
/* @0x1c4e24 ldr r1, [r3, #0x14] */
/* @0x1c4e28 cmp r2, #0 */
/* @0x1c4e2c str r6, [r5, #0x8] */
/* @0x1c4e30 ldr r4, [r11, #0x30] */
/* @0x1c4e34 strne r1, [r2, #0x14] */
/* @0x1c4e38 ldrne r1, [r3, #0x14] */
/* @0x1c4e3c ldrne r2, [r3, #0x18] */
/* @0x1c4e40 streq r1, [r5] */
/* @0x1c4e44 cmp r1, #0 */
/* @0x1c4e48 streq r2, [r5, #0x4] */
/* @0x1c4e4c strne r2, [r1, #0x18] */
/* @0x1c4e50 ldr r1, [r11, #0x20] */
/* @0x1c4e54 ldr r0, [r11, #0xc] */
/* @0x1c4e58 ldr r2, [r11, #0x40] */
/* @0x1c4e5c str lr, [r3, #0x34] */
/* @0x1c4e60 ldr lr, [r11, #0x48] */
/* @0x1c4e64 str r12, [r3, #0x4] */
/* @0x1c4e68 ldr r12, [r11, #0x4c] */
/* @0x1c4e6c str r0, [r3, #0xc] */
/* @0x1c4e70 ldr r0, [r11, #0x2c] */
/* @0x1c4e74 str r1, [r3, #0x20] */
/* @0x1c4e78 ldr r1, [r11, #0x38] */
/* @0x1c4e7c str r1, [r3, #0x38] */
/* @0x1c4e80 ldr r1, [r11, #0x3c] */
/* @0x1c4e84 str r2, [r3, #0x40] */
/* @0x1c4e88 ldr r2, [r11, #0x44] */
/* @0x1c4e8c str r1, [r3, #0x3c] */
/* @0x1c4e90 ldrb r1, [r11, #0x1c] */
/* @0x1c4e94 str r2, [r3, #0x44] */
/* @0x1c4e98 ldr r2, [r11, #0x24] */
/* @0x1c4e9c str r2, [r3, #0x24] */
/* @0x1c4ea0 ldr r2, [r11, #0x28] */
/* @0x1c4ea4 str lr, [r3, #0x48] */
/* @0x1c4ea8 str r0, [r3, #0x2c] */
/* @0x1c4eac str r2, [r3, #0x28] */
/* @0x1c4eb0 mov r2, r3 */
/* @0x1c4eb4 strb r1, [r3, #0x1c] */
/* @0x1c4eb8 str r12, [r3, #0x4c] */
/* @0x1c4ebc str r4, [r3, #0x30] */
/* @0x1c4ec0 mov r3, #0 */
/* @0x1c4ec4 ldr r0, [sp, #0xc] */
/* @0x1c4ec8 ldr r1, [sp, #0x4] */
/* @0x1c4ecc bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c4ed0 ldr r11, [r11, #0x14] */
/* @0x1c4ed4 cmp r11, #0 */
/* @0x1c4ed8 bne 0x1c4cf4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x514> */
/* @0x1c4edc ldr r10, [sp, #0x14] */
/* @0x1c4ee0 ldr r12, [sp, #0xc] */
/* @0x1c4ee4 ldr r3, [r12, #0xd8] */
/* @0x1c4ee8 ldr r2, [r12, #0xdc] */
/* @0x1c4eec cmp r3, #0 */
/* @0x1c4ef0 add r2, r2, #1 */
/* @0x1c4ef4 str r2, [r12, #0xdc] */
/* @0x1c4ef8 beq 0x1c5a18 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x1238> */
/* @0x1c4efc ldr r4, [sp, #0x4] */
/* @0x1c4f00 ldr r12, [sp, #0xc] */
/* @0x1c4f04 str r4, [r3, #0x68] */
/* @0x1c4f08 mov r3, #0 */
/* @0x1c4f0c ldr r2, [r12, #0xd8] */
/* @0x1c4f10 str r2, [r4, #0x6c] */
/* @0x1c4f14 str r4, [r12, #0xd8] */
/* @0x1c4f18 str r3, [r4, #0x68] */
/* @0x1c4f1c ldr r4, [sp, #0x4] */
/* @0x1c4f20 ldr r0, [sp, #0x28] */
/* @0x1c4f24 ldr r1, [r4] */
/* @0x1c4f28 mov r2, r4 */
/* @0x1c4f2c bl 0x1c2a90 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_> */
/* @0x1c4f30 ldr r12, [sp, #0x8] */
/* @0x1c4f34 ldr r12, [r12, #0x68] */
/* @0x1c4f38 cmp r12, #0 */
/* @0x1c4f3c str r12, [sp, #0x8] */
/* @0x1c4f40 bne 0x1c4a3c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x25c> */
/* @0x1c4f44 add sp, sp, #68 */
/* @0x1c4f48 vpop {d8, d9} */
/* @0x1c4f4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c4f50 ldr r3, [pc, #-0x2bc] */
/* @0x1c4f54 ldr r4, [r10, r3] */
/* @0x1c4f58 ldr r7, [r4, #0x8] */
/* @0x1c4f5c cmp r7, #0 */
/* @0x1c4f60 bne 0x1c500c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x82c> */
/* @0x1c4f64 ldr r3, [r4, #0x10] */
/* @0x1c4f68 cmp r3, #0 */
/* @0x1c4f6c ble 0x1c5004 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x824> */
/* @0x1c4f70 ldr r8, [sp, #0x30] */
/* @0x1c4f74 mvn r6, #0 */
/* @0x1c4f78 mov r5, r7 */
/* @0x1c4f7c mov r2, #63 */
/* @0x1c4f80 mov r3, #1 */
/* @0x1c4f84 mov r0, #32 */
/* @0x1c4f88 mov r1, r8 */
/* @0x1c4f8c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4f90 ldr r3, [r4] */
/* @0x1c4f94 mov r2, #6 */
/* @0x1c4f98 cmp r0, #0 */
/* @0x1c4f9c beq 0x1c4fc0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x7e0> */
/* @0x1c4fa0 strb r5, [r0, #0x8] */
/* @0x1c4fa4 str r5, [r0, #0xc] */
/* @0x1c4fa8 str r5, [r0, #0x10] */
/* @0x1c4fac str r5, [r0, #0x14] */
/* @0x1c4fb0 str r5, [r0, #0x18] */
/* @0x1c4fb4 str r6, [r0, #0x4] */
/* @0x1c4fb8 str r6, [r0, #0x1c] */
/* @0x1c4fbc str r2, [r0] */
/* @0x1c4fc0 cmp r3, #0 */
/* @0x1c4fc4 strne r0, [r3, #0x18] */
/* @0x1c4fc8 streq r3, [r0, #0x18] */
/* @0x1c4fcc add r7, r7, #1 */
/* @0x1c4fd0 streq r3, [r0, #0x14] */
/* @0x1c4fd4 strne r3, [r0, #0x14] */
/* @0x1c4fd8 ldr r3, [r4, #0x10] */
/* @0x1c4fdc ldr r2, [r4, #0x8] */
/* @0x1c4fe0 streq r0, [r4, #0x4] */
/* @0x1c4fe4 streq r0, [r4] */
/* @0x1c4fe8 add r2, r2, #1 */
/* @0x1c4fec strne r0, [r4] */
/* @0x1c4ff0 strne r5, [r0, #0x18] */
/* @0x1c4ff4 cmp r7, r3 */
/* @0x1c4ff8 str r2, [r4, #0x8] */
/* @0x1c4ffc blt 0x1c4f7c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x79c> */
/* @0x1c5000 ldr r7, [r4, #0x8] */
/* @0x1c5004 lsl r3, r3, #1 */
/* @0x1c5008 str r3, [r4, #0x10] */
/* @0x1c500c ldr r3, [r4] */
/* @0x1c5010 sub r7, r7, #1 */
/* @0x1c5014 ldr r0, [r11, #0x4] */
/* @0x1c5018 str r7, [r4, #0x8] */
/* @0x1c501c ldr r2, [r3, #0x18] */
/* @0x1c5020 ldr r1, [r3, #0x14] */
/* @0x1c5024 cmp r2, #0 */
/* @0x1c5028 strne r1, [r2, #0x14] */
/* @0x1c502c ldrne r1, [r3, #0x14] */
/* @0x1c5030 ldrne r2, [r3, #0x18] */
/* @0x1c5034 streq r1, [r4] */
/* @0x1c5038 cmp r1, #0 */
/* @0x1c503c streq r2, [r4, #0x4] */
/* @0x1c5040 strne r2, [r1, #0x18] */
/* @0x1c5044 mov r2, r3 */
/* @0x1c5048 ldr r1, [r11, #0x1c] */
/* @0x1c504c ldr r12, [r11, #0xc] */
/* @0x1c5050 str r0, [r3, #0x4] */
/* @0x1c5054 str r1, [r3, #0x1c] */
/* @0x1c5058 str r12, [r3, #0xc] */
/* @0x1c505c mov r3, #0 */
/* @0x1c5060 ldr r0, [sp, #0xc] */
/* @0x1c5064 ldr r1, [sp, #0x4] */
/* @0x1c5068 bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c506c b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* @0x1c5070 ldr r3, [pc, #-0x3d8] */
/* @0x1c5074 ldr r5, [r10, r3] */
/* @0x1c5078 ldr r6, [r5, #0x8] */
/* @0x1c507c cmp r6, #0 */
/* @0x1c5080 bne 0x1c514c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x96c> */
/* @0x1c5084 ldr r3, [r5, #0x10] */
/* @0x1c5088 cmp r3, #0 */
/* @0x1c508c ble 0x1c5144 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x964> */
/* @0x1c5090 ldr r7, [sp, #0x18] */
/* @0x1c5094 mov r4, r6 */
/* @0x1c5098 mov r1, r7 */
/* @0x1c509c mov r2, #63 */
/* @0x1c50a0 mov r3, #1 */
/* @0x1c50a4 mov r0, #60 */
/* @0x1c50a8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c50ac ldr r3, [r5] */
/* @0x1c50b0 mvn r2, #0 */
/* @0x1c50b4 mvn r12, #-2147483648 */
/* @0x1c50b8 mov r1, #5 */
/* @0x1c50bc cmp r0, #0 */
/* @0x1c50c0 beq 0x1c5100 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x920> */
/* @0x1c50c4 strb r4, [r0, #0x8] */
/* @0x1c50c8 vstr s18, [r0, #32] */
/* @0x1c50cc str r4, [r0, #0xc] */
/* @0x1c50d0 vstr s18, [r0, #36] */
/* @0x1c50d4 str r4, [r0, #0x10] */
/* @0x1c50d8 vstr s18, [r0, #48] */
/* @0x1c50dc str r4, [r0, #0x14] */
/* @0x1c50e0 str r4, [r0, #0x18] */
/* @0x1c50e4 str r2, [r0, #0x4] */
/* @0x1c50e8 str r2, [r0, #0x1c] */
/* @0x1c50ec str r4, [r0, #0x28] */
/* @0x1c50f0 str r4, [r0, #0x2c] */
/* @0x1c50f4 str r4, [r0, #0x34] */
/* @0x1c50f8 str r12, [r0, #0x38] */
/* @0x1c50fc str r1, [r0] */
/* @0x1c5100 cmp r3, #0 */
/* @0x1c5104 strne r0, [r3, #0x18] */
/* @0x1c5108 streq r3, [r0, #0x18] */
/* @0x1c510c add r6, r6, #1 */
/* @0x1c5110 streq r3, [r0, #0x14] */
/* @0x1c5114 strne r3, [r0, #0x14] */
/* @0x1c5118 ldr r3, [r5, #0x10] */
/* @0x1c511c ldr r2, [r5, #0x8] */
/* @0x1c5120 streq r0, [r5, #0x4] */
/* @0x1c5124 streq r0, [r5] */
/* @0x1c5128 add r2, r2, #1 */
/* @0x1c512c strne r0, [r5] */
/* @0x1c5130 strne r4, [r0, #0x18] */
/* @0x1c5134 cmp r6, r3 */
/* @0x1c5138 str r2, [r5, #0x8] */
/* @0x1c513c blt 0x1c5098 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x8b8> */
/* @0x1c5140 ldr r6, [r5, #0x8] */
/* @0x1c5144 lsl r3, r3, #1 */
/* @0x1c5148 str r3, [r5, #0x10] */
/* @0x1c514c ldr r4, [r5] */
/* @0x1c5150 sub r6, r6, #1 */
/* @0x1c5154 ldr lr, [r11, #0x20] */
/* @0x1c5158 ldr r1, [r11, #0x1c] */
/* @0x1c515c ldr r3, [r4, #0x18] */
/* @0x1c5160 ldr r2, [r4, #0x14] */
/* @0x1c5164 cmp r3, #0 */
/* @0x1c5168 ldr r12, [r11, #0x4] */
/* @0x1c516c str r6, [r5, #0x8] */
/* @0x1c5170 strne r2, [r3, #0x14] */
/* @0x1c5174 ldrne r2, [r4, #0x14] */
/* @0x1c5178 ldrne r3, [r4, #0x18] */
/* @0x1c517c streq r2, [r5] */
/* @0x1c5180 cmp r2, #0 */
/* @0x1c5184 streq r3, [r5, #0x4] */
/* @0x1c5188 strne r3, [r2, #0x18] */
/* @0x1c518c ldr r2, [r11, #0x28] */
/* @0x1c5190 ldr r3, [r11, #0x2c] */
/* @0x1c5194 str lr, [r4, #0x20] */
/* @0x1c5198 ldr lr, [r11, #0xc] */
/* @0x1c519c mul r0, r3, r2 */
/* @0x1c51a0 str r1, [r4, #0x1c] */
/* @0x1c51a4 ldr r1, [r11, #0x24] */
/* @0x1c51a8 str r3, [r4, #0x2c] */
/* @0x1c51ac ldr r3, [r11, #0x30] */
/* @0x1c51b0 str r12, [r4, #0x4] */
/* @0x1c51b4 str r2, [r4, #0x28] */
/* @0x1c51b8 lsl r0, r0, #2 */
/* @0x1c51bc str r1, [r4, #0x24] */
/* @0x1c51c0 movw r2, #0x2f1 */
/* @0x1c51c4 str lr, [r4, #0xc] */
/* @0x1c51c8 ldr r1, [sp, #0x10] */
/* @0x1c51cc str r3, [r4, #0x30] */
/* @0x1c51d0 mov r3, #1 */
/* @0x1c51d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c51d8 ldr r3, [r4, #0x28] */
/* @0x1c51dc ldr r2, [r4, #0x2c] */
/* @0x1c51e0 mul r2, r2, r3 */
/* @0x1c51e4 lsl r2, r2, #2 */
/* @0x1c51e8 str r0, [r4, #0x34] */
/* @0x1c51ec ldr r1, [r11, #0x34] */
/* @0x1c51f0 bl 0xb65bc <memcpy@plt> */
/* @0x1c51f4 ldr r0, [sp, #0xc] */
/* @0x1c51f8 ldr r1, [sp, #0x4] */
/* @0x1c51fc mov r2, r4 */
/* @0x1c5200 mov r3, #0 */
/* @0x1c5204 bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c5208 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* @0x1c520c ldr r3, [pc, #-0x570] */
/* @0x1c5210 ldr r4, [r10, r3] */
/* @0x1c5214 ldr r6, [r4, #0x8] */
/* @0x1c5218 cmp r6, #0 */
/* @0x1c521c bne 0x1c52f4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xb14> */
/* @0x1c5220 ldr r3, [r4, #0x10] */
/* @0x1c5224 cmp r3, #0 */
/* @0x1c5228 ble 0x1c52ec <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xb0c> */
/* @0x1c522c ldr r7, [sp, #0x1c] */
/* @0x1c5230 mov r5, r6 */
/* @0x1c5234 mov r1, r7 */
/* @0x1c5238 mov r2, #63 */
/* @0x1c523c mov r0, #72 */
/* @0x1c5240 mov r3, #1 */
/* @0x1c5244 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c5248 ldr r2, [r4] */
/* @0x1c524c mvn r1, #0 */
/* @0x1c5250 mov r12, #4 */
/* @0x1c5254 cmp r0, #0 */
/* @0x1c5258 beq 0x1c52a8 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xac8> */
/* @0x1c525c mov r3, #1065353216 */
/* @0x1c5260 strb r5, [r0, #0x8] */
/* @0x1c5264 str r5, [r0, #0xc] */
/* @0x1c5268 vstr s18, [r0, #32] */
/* @0x1c526c str r5, [r0, #0x10] */
/* @0x1c5270 vstr s18, [r0, #52] */
/* @0x1c5274 str r5, [r0, #0x14] */
/* @0x1c5278 vstr s18, [r0, #64] */
/* @0x1c527c str r5, [r0, #0x18] */
/* @0x1c5280 vstr s18, [r0, #68] */
/* @0x1c5284 str r1, [r0, #0x4] */
/* @0x1c5288 str r1, [r0, #0x1c] */
/* @0x1c528c str r5, [r0, #0x28] */
/* @0x1c5290 str r1, [r0, #0x38] */
/* @0x1c5294 str r12, [r0] */
/* @0x1c5298 str r3, [r0, #0x24] */
/* @0x1c529c str r3, [r0, #0x2c] */
/* @0x1c52a0 str r3, [r0, #0x30] */
/* @0x1c52a4 str r3, [r0, #0x3c] */
/* @0x1c52a8 ldr r3, [r4, #0x8] */
/* @0x1c52ac add r6, r6, #1 */
/* @0x1c52b0 cmp r2, #0 */
/* @0x1c52b4 strne r0, [r2, #0x18] */
/* @0x1c52b8 add r3, r3, #1 */
/* @0x1c52bc str r3, [r4, #0x8] */
/* @0x1c52c0 ldr r3, [r4, #0x10] */
/* @0x1c52c4 streq r0, [r4, #0x4] */
/* @0x1c52c8 streq r0, [r4] */
/* @0x1c52cc streq r2, [r0, #0x18] */
/* @0x1c52d0 streq r2, [r0, #0x14] */
/* @0x1c52d4 strne r0, [r4] */
/* @0x1c52d8 strne r2, [r0, #0x14] */
/* @0x1c52dc strne r5, [r0, #0x18] */
/* @0x1c52e0 cmp r6, r3 */
/* @0x1c52e4 blt 0x1c5234 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xa54> */
/* @0x1c52e8 ldr r6, [r4, #0x8] */
/* @0x1c52ec lsl r3, r3, #1 */
/* @0x1c52f0 str r3, [r4, #0x10] */
/* @0x1c52f4 ldr r2, [r4] */
/* @0x1c52f8 sub r6, r6, #1 */
/* @0x1c52fc ldr r0, [r11, #0x1c] */
/* @0x1c5300 ldr lr, [r11, #0x20] */
/* @0x1c5304 ldr r3, [r2, #0x18] */
/* @0x1c5308 ldr r1, [r2, #0x14] */
/* @0x1c530c cmp r3, #0 */
/* @0x1c5310 ldr r12, [r11, #0x4] */
/* @0x1c5314 str r6, [r4, #0x8] */
/* @0x1c5318 strne r1, [r3, #0x14] */
/* @0x1c531c ldrne r1, [r2, #0x14] */
/* @0x1c5320 ldrne r3, [r2, #0x18] */
/* @0x1c5324 streq r1, [r4] */
/* @0x1c5328 cmp r1, #0 */
/* @0x1c532c streq r3, [r4, #0x4] */
/* @0x1c5330 strne r3, [r1, #0x18] */
/* @0x1c5334 ldr r1, [r11, #0x28] */
/* @0x1c5338 ldr r3, [r11, #0x38] */
/* @0x1c533c str lr, [r2, #0x20] */
/* @0x1c5340 ldr lr, [r11, #0xc] */
/* @0x1c5344 str r0, [r2, #0x1c] */
/* @0x1c5348 ldr r0, [r11, #0x24] */
/* @0x1c534c str r1, [r2, #0x28] */
/* @0x1c5350 ldr r1, [r11, #0x2c] */
/* @0x1c5354 str r0, [r2, #0x24] */
/* @0x1c5358 str r12, [r2, #0x4] */
/* @0x1c535c str r1, [r2, #0x2c] */
/* @0x1c5360 ldr r1, [r11, #0x30] */
/* @0x1c5364 str r1, [r2, #0x30] */
/* @0x1c5368 ldr r1, [r11, #0x34] */
/* @0x1c536c str r1, [r2, #0x34] */
/* @0x1c5370 ldr r1, [r11, #0x3c] */
/* @0x1c5374 str r3, [r2, #0x38] */
/* @0x1c5378 ldr r3, [r11, #0x44] */
/* @0x1c537c str r1, [r2, #0x3c] */
/* @0x1c5380 ldr r1, [r11, #0x40] */
/* @0x1c5384 str r1, [r2, #0x40] */
/* @0x1c5388 str r3, [r2, #0x44] */
/* @0x1c538c mov r3, #0 */
/* @0x1c5390 str lr, [r2, #0xc] */
/* @0x1c5394 ldr r0, [sp, #0xc] */
/* @0x1c5398 ldr r1, [sp, #0x4] */
/* @0x1c539c bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c53a0 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* @0x1c53a4 ldr r3, [pc, #-0x704] */
/* @0x1c53a8 ldr r4, [r10, r3] */
/* @0x1c53ac ldr r8, [r4, #0x8] */
/* @0x1c53b0 cmp r8, #0 */
/* @0x1c53b4 bne 0x1c5468 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xc88> */
/* @0x1c53b8 ldr r3, [r4, #0x10] */
/* @0x1c53bc cmp r3, #0 */
/* @0x1c53c0 ble 0x1c5460 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xc80> */
/* @0x1c53c4 ldr r7, [pc, #-0x720] */
/* @0x1c53c8 mov r5, r8 */
/* @0x1c53cc mvn r6, #0 */
/* @0x1c53d0 add r7, pc, r7 */
/* @0x1c53d4 mov r2, #63 */
/* @0x1c53d8 mov r3, #1 */
/* @0x1c53dc mov r0, #36 */
/* @0x1c53e0 mov r1, r7 */
/* @0x1c53e4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c53e8 ldr r3, [r4] */
/* @0x1c53ec mov r2, #2 */
/* @0x1c53f0 cmp r0, #0 */
/* @0x1c53f4 beq 0x1c541c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xc3c> */
/* @0x1c53f8 strb r5, [r0, #0x8] */
/* @0x1c53fc str r5, [r0, #0xc] */
/* @0x1c5400 str r5, [r0, #0x10] */
/* @0x1c5404 str r5, [r0, #0x14] */
/* @0x1c5408 str r5, [r0, #0x18] */
/* @0x1c540c str r6, [r0, #0x4] */
/* @0x1c5410 str r6, [r0, #0x1c] */
/* @0x1c5414 str r5, [r0, #0x20] */
/* @0x1c5418 str r2, [r0] */
/* @0x1c541c cmp r3, #0 */
/* @0x1c5420 strne r0, [r3, #0x18] */
/* @0x1c5424 streq r3, [r0, #0x18] */
/* @0x1c5428 add r8, r8, #1 */
/* @0x1c542c streq r3, [r0, #0x14] */
/* @0x1c5430 strne r3, [r0, #0x14] */
/* @0x1c5434 ldr r3, [r4, #0x10] */
/* @0x1c5438 ldr r2, [r4, #0x8] */
/* @0x1c543c streq r0, [r4, #0x4] */
/* @0x1c5440 streq r0, [r4] */
/* @0x1c5444 add r2, r2, #1 */
/* @0x1c5448 strne r0, [r4] */
/* @0x1c544c strne r5, [r0, #0x18] */
/* @0x1c5450 cmp r8, r3 */
/* @0x1c5454 str r2, [r4, #0x8] */
/* @0x1c5458 blt 0x1c53d4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xbf4> */
/* @0x1c545c ldr r8, [r4, #0x8] */
/* @0x1c5460 lsl r3, r3, #1 */
/* @0x1c5464 str r3, [r4, #0x10] */
/* @0x1c5468 ldr r3, [r4] */
/* @0x1c546c sub r8, r8, #1 */
/* @0x1c5470 ldr r0, [r11, #0x4] */
/* @0x1c5474 str r8, [r4, #0x8] */
/* @0x1c5478 ldr r2, [r3, #0x18] */
/* @0x1c547c ldr r1, [r3, #0x14] */
/* @0x1c5480 cmp r2, #0 */
/* @0x1c5484 strne r1, [r2, #0x14] */
/* @0x1c5488 ldrne r1, [r3, #0x14] */
/* @0x1c548c ldrne r2, [r3, #0x18] */
/* @0x1c5490 streq r1, [r4] */
/* @0x1c5494 cmp r1, #0 */
/* @0x1c5498 streq r2, [r4, #0x4] */
/* @0x1c549c strne r2, [r1, #0x18] */
/* @0x1c54a0 mov r2, r3 */
/* @0x1c54a4 ldr r1, [r11, #0x1c] */
/* @0x1c54a8 str r0, [r3, #0x4] */
/* @0x1c54ac ldr r0, [sp, #0xc] */
/* @0x1c54b0 str r1, [r3, #0x1c] */
/* @0x1c54b4 mov r3, #0 */
/* @0x1c54b8 ldr r1, [sp, #0x4] */
/* @0x1c54bc bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c54c0 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* @0x1c54c4 ldr r3, [r11, #0x1c] */
/* @0x1c54c8 cmp r3, #0 */
/* @0x1c54cc beq 0x1c5a08 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x1228> */
/* @0x1c54d0 ldr r3, [pc, #-0x828] */
/* @0x1c54d4 ldr r5, [r10, r3] */
/* @0x1c54d8 ldr r9, [r5, #0x8] */
/* @0x1c54dc cmp r9, #0 */
/* @0x1c54e0 bne 0x1c55a8 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xdc8> */
/* @0x1c54e4 ldr r3, [r5, #0x10] */
/* @0x1c54e8 cmp r3, #0 */
/* @0x1c54ec ble 0x1c55a0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xdc0> */
/* @0x1c54f0 ldr r6, [pc, #-0x844] */
/* @0x1c54f4 mov r4, r9 */
/* @0x1c54f8 mov r8, #1 */
/* @0x1c54fc mvn r7, #0 */
/* @0x1c5500 add r6, pc, r6 */
/* @0x1c5504 mov r2, #63 */
/* @0x1c5508 mov r3, #1 */
/* @0x1c550c mov r0, #52 */
/* @0x1c5510 mov r1, r6 */
/* @0x1c5514 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c5518 ldr r3, [r5] */
/* @0x1c551c mov r2, #3 */
/* @0x1c5520 cmp r0, #0 */
/* @0x1c5524 beq 0x1c555c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xd7c> */
/* @0x1c5528 strb r4, [r0, #0x8] */
/* @0x1c552c str r4, [r0, #0xc] */
/* @0x1c5530 str r4, [r0, #0x10] */
/* @0x1c5534 str r4, [r0, #0x14] */
/* @0x1c5538 str r4, [r0, #0x18] */
/* @0x1c553c str r7, [r0, #0x4] */
/* @0x1c5540 str r4, [r0, #0x1c] */
/* @0x1c5544 str r4, [r0, #0x20] */
/* @0x1c5548 str r4, [r0, #0x28] */
/* @0x1c554c str r4, [r0, #0x24] */
/* @0x1c5550 str r4, [r0, #0x2c] */
/* @0x1c5554 str r8, [r0, #0x30] */
/* @0x1c5558 str r2, [r0] */
/* @0x1c555c cmp r3, #0 */
/* @0x1c5560 strne r0, [r3, #0x18] */
/* @0x1c5564 streq r3, [r0, #0x18] */
/* @0x1c5568 add r9, r9, #1 */
/* @0x1c556c streq r3, [r0, #0x14] */
/* @0x1c5570 strne r3, [r0, #0x14] */
/* @0x1c5574 ldr r3, [r5, #0x10] */
/* @0x1c5578 ldr r2, [r5, #0x8] */
/* @0x1c557c streq r0, [r5, #0x4] */
/* @0x1c5580 streq r0, [r5] */
/* @0x1c5584 add r2, r2, #1 */
/* @0x1c5588 strne r0, [r5] */
/* @0x1c558c strne r4, [r0, #0x18] */
/* @0x1c5590 cmp r9, r3 */
/* @0x1c5594 str r2, [r5, #0x8] */
/* @0x1c5598 blt 0x1c5504 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xd24> */
/* @0x1c559c ldr r9, [r5, #0x8] */
/* @0x1c55a0 lsl r3, r3, #1 */
/* @0x1c55a4 str r3, [r5, #0x10] */
/* @0x1c55a8 ldr r4, [r5] */
/* @0x1c55ac sub r9, r9, #1 */
/* @0x1c55b0 ldr r3, [r4, #0x18] */
/* @0x1c55b4 ldr r2, [r4, #0x14] */
/* @0x1c55b8 cmp r3, #0 */
/* @0x1c55bc strne r2, [r3, #0x14] */
/* @0x1c55c0 ldrne r2, [r4, #0x14] */
/* @0x1c55c4 ldrne r3, [r4, #0x18] */
/* @0x1c55c8 streq r2, [r5] */
/* @0x1c55cc cmp r2, #0 */
/* @0x1c55d0 streq r3, [r5, #0x4] */
/* @0x1c55d4 strne r3, [r2, #0x18] */
/* @0x1c55d8 ldr r3, [r11, #0x1c] */
/* @0x1c55dc ldr r2, [r11, #0x4] */
/* @0x1c55e0 cmp r3, #0 */
/* @0x1c55e4 str r9, [r5, #0x8] */
/* @0x1c55e8 str r2, [r4, #0x4] */
/* @0x1c55ec beq 0x1c56a4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xec4> */
/* @0x1c55f0 ldr r6, [r3] */
/* @0x1c55f4 mov r0, #52 */
/* @0x1c55f8 ldr r1, [pc, #-0x948] */
/* @0x1c55fc movw r2, #0x296 */
/* @0x1c5600 mov r3, #1 */
/* @0x1c5604 mul r0, r0, r6 */
/* @0x1c5608 add r1, pc, r1 */
/* @0x1c560c add r0, r0, #4 */
/* @0x1c5610 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c5614 cmp r6, #0 */
/* @0x1c5618 mov r1, #0 */
/* @0x1c561c mov r2, r0 */
/* @0x1c5620 strb r1, [r0, #0x3] */
/* @0x1c5624 str r0, [sp, #0x20] */
/* @0x1c5628 str r6, [r2], #4 */
/* @0x1c562c add r2, r2, r6, lsl #2 */
/* @0x1c5630 ldr r12, [r11, #0x1c] */
/* @0x1c5634 ble 0x1c569c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xebc> */
/* @0x1c5638 ldr r0, [sp, #0x20] */
/* @0x1c563c mov r5, r1 */
/* @0x1c5640 str r4, [sp, #0x3c] */
/* @0x1c5644 mov r4, r6 */
/* @0x1c5648 str r2, [r0, #0x4]! */
/* @0x1c564c mov r1, r2 */
/* @0x1c5650 ldr r3, [r12, #0x4]! */
/* @0x1c5654 add lr, r3, #48 */
/* @0x1c5658 ldr r9, [r3] */
/* @0x1c565c add r3, r3, #16 */
/* @0x1c5660 ldr r8, [r3, #-0xc] */
/* @0x1c5664 add r1, r1, #16 */
/* @0x1c5668 ldr r7, [r3, #-0x8] */
/* @0x1c566c ldr r6, [r3, #-0x4] */
/* @0x1c5670 cmp r3, lr */
/* @0x1c5674 str r9, [r1, #-0x10] */
/* @0x1c5678 str r8, [r1, #-0xc] */
/* @0x1c567c str r7, [r1, #-0x8] */
/* @0x1c5680 str r6, [r1, #-0x4] */
/* @0x1c5684 bne 0x1c5658 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xe78> */
/* @0x1c5688 add r5, r5, #1 */
/* @0x1c568c add r2, r2, #48 */
/* @0x1c5690 cmp r5, r4 */
/* @0x1c5694 bne 0x1c5648 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xe68> */
/* @0x1c5698 ldr r4, [sp, #0x3c] */
/* @0x1c569c ldr r12, [sp, #0x20] */
/* @0x1c56a0 str r12, [r4, #0x1c] */
/* @0x1c56a4 ldr r3, [r11, #0x2c] */
/* @0x1c56a8 cmp r3, #0 */
/* @0x1c56ac ble 0x1c57f4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x1014> */
/* @0x1c56b0 ldr r8, [r11, #0x24] */
/* @0x1c56b4 cmp r8, #0 */
/* @0x1c56b8 beq 0x1c57ec <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x100c> */
/* @0x1c56bc ldr r3, [pc, #-0xa08] */
/* @0x1c56c0 mov r6, #0 */
/* @0x1c56c4 ldr r7, [pc, #-0xa0c] */
/* @0x1c56c8 ldr r5, [r10, r3] */
/* @0x1c56cc add r7, pc, r7 */
/* @0x1c56d0 ldr r9, [r5, #0x8] */
/* @0x1c56d4 cmp r9, #0 */
/* @0x1c56d8 bne 0x1c575c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xf7c> */
/* @0x1c56dc ldr r3, [r5, #0x10] */
/* @0x1c56e0 cmp r3, #0 */
/* @0x1c56e4 ble 0x1c5754 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xf74> */
/* @0x1c56e8 mov r2, #63 */
/* @0x1c56ec mov r3, #1 */
/* @0x1c56f0 movw r0, #0x70c */
/* @0x1c56f4 mov r1, r7 */
/* @0x1c56f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c56fc ldr r3, [r5] */
/* @0x1c5700 add r9, r9, #1 */
/* @0x1c5704 ldr r2, [r5, #0x8] */
/* @0x1c5708 add r2, r2, #1 */
/* @0x1c570c str r2, [r5, #0x8] */
/* @0x1c5710 cmp r0, #0 */
/* @0x1c5714 strne r6, [r0, #0x704] */
/* @0x1c5718 strne r6, [r0, #0x708] */
/* @0x1c571c strne r6, [r0, #0x700] */
/* @0x1c5720 cmp r3, #0 */
/* @0x1c5724 strne r0, [r3, #0x708] */
/* @0x1c5728 streq r3, [r0, #0x708] */
/* @0x1c572c streq r3, [r0, #0x704] */
/* @0x1c5730 strne r3, [r0, #0x704] */
/* @0x1c5734 ldr r3, [r5, #0x10] */
/* @0x1c5738 streq r0, [r5, #0x4] */
/* @0x1c573c streq r0, [r5] */
/* @0x1c5740 strne r0, [r5] */
/* @0x1c5744 strne r6, [r0, #0x708] */
/* @0x1c5748 cmp r9, r3 */
/* @0x1c574c blt 0x1c56e8 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xf08> */
/* @0x1c5750 ldr r9, [r5, #0x8] */
/* @0x1c5754 lsl r3, r3, #1 */
/* @0x1c5758 str r3, [r5, #0x10] */
/* @0x1c575c ldr r3, [r5] */
/* @0x1c5760 sub r9, r9, #1 */
/* @0x1c5764 ldr r12, [r8, #0x700] */
/* @0x1c5768 str r9, [r5, #0x8] */
/* @0x1c576c ldr r2, [r3, #0x708] */
/* @0x1c5770 mov r0, r3 */
/* @0x1c5774 ldr r1, [r3, #0x704] */
/* @0x1c5778 cmp r2, #0 */
/* @0x1c577c strne r1, [r2, #0x704] */
/* @0x1c5780 ldrne r1, [r3, #0x704] */
/* @0x1c5784 ldrne r2, [r3, #0x708] */
/* @0x1c5788 streq r1, [r5] */
/* @0x1c578c cmp r1, #0 */
/* @0x1c5790 streq r2, [r5, #0x4] */
/* @0x1c5794 strne r2, [r1, #0x708] */
/* @0x1c5798 mov r1, r8 */
/* @0x1c579c mov r2, #1792 */
/* @0x1c57a0 str r12, [r3, #0x700] */
/* @0x1c57a4 bl 0xb65bc <memcpy@plt> */
/* @0x1c57a8 ldr r2, [r4, #0x28] */
/* @0x1c57ac ldr r1, [r4, #0x2c] */
/* @0x1c57b0 cmp r2, #0 */
/* @0x1c57b4 add r1, r1, #1 */
/* @0x1c57b8 str r1, [r4, #0x2c] */
/* @0x1c57bc strne r0, [r2, #0x704] */
/* @0x1c57c0 ldrne r2, [r4, #0x28] */
/* @0x1c57c4 streq r0, [r4, #0x28] */
/* @0x1c57c8 streq r0, [r4, #0x24] */
/* @0x1c57cc strne r2, [r0, #0x708] */
/* @0x1c57d0 streq r2, [r0, #0x708] */
/* @0x1c57d4 streq r2, [r0, #0x704] */
/* @0x1c57d8 strne r0, [r4, #0x28] */
/* @0x1c57dc strne r6, [r0, #0x704] */
/* @0x1c57e0 ldr r8, [r8, #0x704] */
/* @0x1c57e4 cmp r8, #0 */
/* @0x1c57e8 bne 0x1c56d0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xef0> */
/* @0x1c57ec mov r3, #1 */
/* @0x1c57f0 strb r3, [r4, #0x8] */
/* @0x1c57f4 mov r2, r4 */
/* @0x1c57f8 ldr r0, [sp, #0xc] */
/* @0x1c57fc ldr r1, [sp, #0x4] */
/* @0x1c5800 mov r3, #0 */
/* @0x1c5804 bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c5808 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* @0x1c580c ldr r3, [r11, #0x1c] */
/* @0x1c5810 cmp r3, #0 */
/* @0x1c5814 beq 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* @0x1c5818 ldr r3, [pc, #-0xb5c] */
/* @0x1c581c ldr r4, [r10, r3] */
/* @0x1c5820 ldr r9, [r4, #0x8] */
/* @0x1c5824 cmp r9, #0 */
/* @0x1c5828 bne 0x1c58d8 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x10f8> */
/* @0x1c582c ldr r3, [r4, #0x10] */
/* @0x1c5830 cmp r3, #0 */
/* @0x1c5834 ble 0x1c58d0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x10f0> */
/* @0x1c5838 ldr r6, [pc, #-0xb78] */
/* @0x1c583c mov r5, r9 */
/* @0x1c5840 mov r8, #1 */
/* @0x1c5844 mvn r7, #0 */
/* @0x1c5848 add r6, pc, r6 */
/* @0x1c584c mov r3, #1 */
/* @0x1c5850 mov r0, #32 */
/* @0x1c5854 mov r1, r6 */
/* @0x1c5858 mov r2, #63 */
/* @0x1c585c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c5860 ldr r3, [r4] */
/* @0x1c5864 cmp r0, #0 */
/* @0x1c5868 beq 0x1c588c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x10ac> */
/* @0x1c586c strb r5, [r0, #0x8] */
/* @0x1c5870 str r5, [r0, #0xc] */
/* @0x1c5874 str r5, [r0, #0x10] */
/* @0x1c5878 str r5, [r0, #0x14] */
/* @0x1c587c str r5, [r0, #0x18] */
/* @0x1c5880 str r7, [r0, #0x4] */
/* @0x1c5884 str r5, [r0, #0x1c] */
/* @0x1c5888 str r8, [r0] */
/* @0x1c588c cmp r3, #0 */
/* @0x1c5890 strne r0, [r3, #0x18] */
/* @0x1c5894 streq r3, [r0, #0x18] */
/* @0x1c5898 add r9, r9, #1 */
/* @0x1c589c streq r3, [r0, #0x14] */
/* @0x1c58a0 strne r3, [r0, #0x14] */
/* @0x1c58a4 ldr r3, [r4, #0x10] */
/* @0x1c58a8 ldr r2, [r4, #0x8] */
/* @0x1c58ac streq r0, [r4, #0x4] */
/* @0x1c58b0 streq r0, [r4] */
/* @0x1c58b4 add r2, r2, #1 */
/* @0x1c58b8 strne r0, [r4] */
/* @0x1c58bc strne r5, [r0, #0x18] */
/* @0x1c58c0 cmp r9, r3 */
/* @0x1c58c4 str r2, [r4, #0x8] */
/* @0x1c58c8 blt 0x1c584c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x106c> */
/* @0x1c58cc ldr r9, [r4, #0x8] */
/* @0x1c58d0 lsl r3, r3, #1 */
/* @0x1c58d4 str r3, [r4, #0x10] */
/* @0x1c58d8 ldr r5, [r4] */
/* @0x1c58dc sub r9, r9, #1 */
/* @0x1c58e0 ldr r1, [pc, #-0xc1c] */
/* @0x1c58e4 mov r0, #44 */
/* @0x1c58e8 ldr r3, [r5, #0x18] */
/* @0x1c58ec add r1, pc, r1 */
/* @0x1c58f0 ldr r2, [r5, #0x14] */
/* @0x1c58f4 cmp r3, #0 */
/* @0x1c58f8 strne r2, [r3, #0x14] */
/* @0x1c58fc ldrne r2, [r5, #0x14] */
/* @0x1c5900 ldrne r3, [r5, #0x18] */
/* @0x1c5904 streq r2, [r4] */
/* @0x1c5908 cmp r2, #0 */
/* @0x1c590c streq r3, [r4, #0x4] */
/* @0x1c5910 strne r3, [r2, #0x18] */
/* @0x1c5914 mov r2, #608 */
/* @0x1c5918 ldr r3, [r11, #0x4] */
/* @0x1c591c str r9, [r4, #0x8] */
/* @0x1c5920 str r3, [r5, #0x4] */
/* @0x1c5924 mov r3, #1 */
/* @0x1c5928 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c592c subs r3, r0, #0 */
/* @0x1c5930 beq 0x1c596c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x118c> */
/* @0x1c5934 mov r2, #0 */
/* @0x1c5938 vstr s18, [r3, #12] */
/* @0x1c593c vstr s18, [r3, #16] */
/* @0x1c5940 vstr s18, [r3, #28] */
/* @0x1c5944 vstr s18, [r3, #32] */
/* @0x1c5948 vstr s18, [r3, #36] */
/* @0x1c594c strb r2, [r3] */
/* @0x1c5950 strb r2, [r3, #0x1] */
/* @0x1c5954 str r2, [r3, #0x4] */
/* @0x1c5958 strb r2, [r3, #0x8] */
/* @0x1c595c strb r2, [r3, #0x9] */
/* @0x1c5960 strb r2, [r3, #0x14] */
/* @0x1c5964 str r2, [r3, #0x18] */
/* @0x1c5968 str r2, [r3, #0x28] */
/* @0x1c596c str r3, [r5, #0x1c] */
/* @0x1c5970 mov r2, r5 */
/* @0x1c5974 ldr r1, [r11, #0x1c] */
/* @0x1c5978 ldr r12, [r11, #0xc] */
/* @0x1c597c ldrb lr, [r1] */
/* @0x1c5980 ldr r7, [r1, #0x1c] */
/* @0x1c5984 ldr r6, [r1, #0xc] */
/* @0x1c5988 ldrb r0, [r1, #0x1] */
/* @0x1c598c strb lr, [r3] */
/* @0x1c5990 ldr lr, [r1, #0x4] */
/* @0x1c5994 strb r0, [r3, #0x1] */
/* @0x1c5998 ldrb r0, [r1, #0x8] */
/* @0x1c599c str lr, [r3, #0x4] */
/* @0x1c59a0 ldrb lr, [r1, #0x9] */
/* @0x1c59a4 ldr r4, [r1, #0x18] */
/* @0x1c59a8 strb r0, [r3, #0x8] */
/* @0x1c59ac ldrb r0, [r1, #0x14] */
/* @0x1c59b0 strb lr, [r3, #0x9] */
/* @0x1c59b4 ldr lr, [r1, #0x10] */
/* @0x1c59b8 strb r0, [r3, #0x14] */
/* @0x1c59bc ldr r0, [r1, #0x20] */
/* @0x1c59c0 str lr, [r3, #0x10] */
/* @0x1c59c4 ldr lr, [r1, #0x28] */
/* @0x1c59c8 ldr r1, [r1, #0x24] */
/* @0x1c59cc str r7, [r3, #0x1c] */
/* @0x1c59d0 str r6, [r3, #0xc] */
/* @0x1c59d4 str r4, [r3, #0x18] */
/* @0x1c59d8 str r0, [r3, #0x20] */
/* @0x1c59dc str r1, [r3, #0x24] */
/* @0x1c59e0 str lr, [r3, #0x28] */
/* @0x1c59e4 mov r3, #0 */
/* @0x1c59e8 ldr r0, [sp, #0xc] */
/* @0x1c59ec ldr r1, [sp, #0x4] */
/* @0x1c59f0 str r12, [r5, #0xc] */
/* @0x1c59f4 bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c59f8 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* @0x1c59fc ldr r4, [sp, #0x4] */
/* @0x1c5a00 str r0, [r4, #0x1c] */
/* @0x1c5a04 b 0x1c4c3c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x45c> */
/* @0x1c5a08 ldr r3, [r11, #0x2c] */
/* @0x1c5a0c cmp r3, #0 */
/* @0x1c5a10 bgt 0x1c54d0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xcf0> */
/* @0x1c5a14 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* @0x1c5a18 ldr r4, [sp, #0x4] */
/* @0x1c5a1c ldr r12, [sp, #0xc] */
/* @0x1c5a20 str r4, [r12, #0xd8] */
/* @0x1c5a24 str r4, [r12, #0xd4] */
/* @0x1c5a28 str r3, [r4, #0x6c] */
/* @0x1c5a2c str r3, [r4, #0x68] */
/* @0x1c5a30 b 0x1c4f1c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x73c> */

/* ── FUNC 0x1c5a34 · anon_1c5a34 · size=0 · insn=1 */
/* @0x1c5a34 nop */

/* ── FUNC 0x1c5a38 · CLayerManager::AddInstanceToLayer(CRoom*, CLayer*, CInstance*) · size=736 · insn=184 */
/* @0x1c5a38 cmp r1, #0 */
/* @0x1c5a3c cmpne r0, #0 */
/* @0x1c5a40 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c5a44 mov r9, r0 */
/* @0x1c5a48 sub sp, sp, #4 */
/* @0x1c5a4c mov r10, r1 */
/* @0x1c5a50 mov r8, r2 */
/* @0x1c5a54 beq 0x1c5a6c <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1c5a58 cmp r2, #0 */
/* @0x1c5a5c beq 0x1c5a6c <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1c5a60 ldrb r5, [r2, #0x174] */
/* @0x1c5a64 cmp r5, #0 */
/* @0x1c5a68 beq 0x1c5a74 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x3c> */
/* @0x1c5a6c add sp, sp, #4 */
/* @0x1c5a70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c5a74 ldr r0, [r2, #0x78] */
/* @0x1c5a78 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c5a7c ldr r4, [r9, #0x118] */
/* @0x1c5a80 ldr r1, [r9, #0x120] */
/* @0x1c5a84 bic r0, r0, #-2147483648 */
/* @0x1c5a88 and r3, r0, r4 */
/* @0x1c5a8c lsl r6, r3, #1 */
/* @0x1c5a90 add r2, r6, r3 */
/* @0x1c5a94 add r2, r1, r2, lsl #2 */
/* @0x1c5a98 ldr r2, [r2, #0x8] */
/* @0x1c5a9c cmp r2, #0 */
/* @0x1c5aa0 beq 0x1c5ac4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x8c> */
/* @0x1c5aa4 cmp r0, r2 */
/* @0x1c5aa8 beq 0x1c5c6c <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x234> */
/* @0x1c5aac ldr r11, [r9, #0x110] */
/* @0x1c5ab0 and r2, r4, r2 */
/* @0x1c5ab4 add r12, r11, r3 */
/* @0x1c5ab8 rsb r2, r2, r12 */
/* @0x1c5abc tst r2, r4 */
/* @0x1c5ac0 bpl 0x1c5c2c <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x1f4> */
/* @0x1c5ac4 ldr r4, [pc, #0x238] */
/* @0x1c5ac8 ldr r4, [pc, r4] */
/* @0x1c5acc ldr r11, [r4, #0x8] */
/* @0x1c5ad0 cmp r11, #0 */
/* @0x1c5ad4 bne 0x1c5b88 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x150> */
/* @0x1c5ad8 ldr r3, [r4, #0x10] */
/* @0x1c5adc cmp r3, #0 */
/* @0x1c5ae0 ble 0x1c5b80 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x148> */
/* @0x1c5ae4 ldr r7, [pc, #0x21c] */
/* @0x1c5ae8 mov r5, r11 */
/* @0x1c5aec mvn r6, #0 */
/* @0x1c5af0 add r7, pc, r7 */
/* @0x1c5af4 mov r3, #1 */
/* @0x1c5af8 mov r0, #36 */
/* @0x1c5afc mov r1, r7 */
/* @0x1c5b00 mov r2, #63 */
/* @0x1c5b04 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c5b08 mov r3, #2 */
/* @0x1c5b0c cmp r0, #0 */
/* @0x1c5b10 beq 0x1c5b38 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x100> */
/* @0x1c5b14 strb r5, [r0, #0x8] */
/* @0x1c5b18 str r5, [r0, #0xc] */
/* @0x1c5b1c str r5, [r0, #0x10] */
/* @0x1c5b20 str r5, [r0, #0x14] */
/* @0x1c5b24 str r5, [r0, #0x18] */
/* @0x1c5b28 str r6, [r0, #0x4] */
/* @0x1c5b2c str r6, [r0, #0x1c] */
/* @0x1c5b30 str r5, [r0, #0x20] */
/* @0x1c5b34 str r3, [r0] */
/* @0x1c5b38 ldr r3, [r4] */
/* @0x1c5b3c add r11, r11, #1 */
/* @0x1c5b40 ldr r2, [r4, #0x8] */
/* @0x1c5b44 cmp r3, #0 */
/* @0x1c5b48 streq r0, [r4, #0x4] */
/* @0x1c5b4c strne r0, [r3, #0x18] */
/* @0x1c5b50 add r2, r2, #1 */
/* @0x1c5b54 streq r3, [r0, #0x18] */
/* @0x1c5b58 streq r3, [r0, #0x14] */
/* @0x1c5b5c strne r3, [r0, #0x14] */
/* @0x1c5b60 ldr r3, [r4, #0x10] */
/* @0x1c5b64 streq r0, [r4] */
/* @0x1c5b68 strne r0, [r4] */
/* @0x1c5b6c strne r5, [r0, #0x18] */
/* @0x1c5b70 cmp r11, r3 */
/* @0x1c5b74 str r2, [r4, #0x8] */
/* @0x1c5b78 blt 0x1c5af4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0xbc> */
/* @0x1c5b7c ldr r11, [r4, #0x8] */
/* @0x1c5b80 lsl r3, r3, #1 */
/* @0x1c5b84 str r3, [r4, #0x10] */
/* @0x1c5b88 ldr r12, [r4] */
/* @0x1c5b8c sub r11, r11, #1 */
/* @0x1c5b90 ldr r5, [pc, #0x174] */
/* @0x1c5b94 mov r0, r9 */
/* @0x1c5b98 ldr r7, [r10] */
/* @0x1c5b9c mov r1, r10 */
/* @0x1c5ba0 ldr r3, [r12, #0x18] */
/* @0x1c5ba4 ldr r5, [pc, r5] */
/* @0x1c5ba8 ldr r2, [r12, #0x14] */
/* @0x1c5bac cmp r3, #0 */
/* @0x1c5bb0 str r11, [r4, #0x8] */
/* @0x1c5bb4 strne r2, [r3, #0x14] */
/* @0x1c5bb8 ldrne r2, [r12, #0x14] */
/* @0x1c5bbc ldrne r3, [r12, #0x18] */
/* @0x1c5bc0 streq r2, [r4] */
/* @0x1c5bc4 cmp r2, #0 */
/* @0x1c5bc8 streq r3, [r4, #0x4] */
/* @0x1c5bcc mov r4, #1 */
/* @0x1c5bd0 strne r3, [r2, #0x18] */
/* @0x1c5bd4 ldr r3, [r5] */
/* @0x1c5bd8 ldr r2, [r8, #0x78] */
/* @0x1c5bdc str r8, [r12, #0x20] */
/* @0x1c5be0 add r6, r3, r4 */
/* @0x1c5be4 str r3, [r12, #0x4] */
/* @0x1c5be8 str r2, [r12, #0x1c] */
/* @0x1c5bec mov r2, r12 */
/* @0x1c5bf0 str r7, [r8, #0x170] */
/* @0x1c5bf4 vldr s15, [r10, #4] */
/* @0x1c5bf8 vcvt.f32.s32 s15, s15 */
/* @0x1c5bfc strb r4, [r8, #0x174] */
/* @0x1c5c00 ldrb r3, [r8, #0x69] */
/* @0x1c5c04 str r6, [r5] */
/* @0x1c5c08 vstr s15, [r8, #384] */
/* @0x1c5c0c strb r4, [r12, #0x8] */
/* @0x1c5c10 add sp, sp, #4 */
/* @0x1c5c14 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c5c18 b 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c5c1c cmp r0, r12 */
/* @0x1c5c20 beq 0x1c5c64 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x22c> */
/* @0x1c5c24 cmp r7, r5 */
/* @0x1c5c28 blt 0x1c5ac4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x8c> */
/* @0x1c5c2c add r3, r3, #1 */
/* @0x1c5c30 add r5, r5, #1 */
/* @0x1c5c34 and r3, r4, r3 */
/* @0x1c5c38 add r7, r11, r3 */
/* @0x1c5c3c lsl r6, r3, #1 */
/* @0x1c5c40 add r2, r6, r3 */
/* @0x1c5c44 add r2, r1, r2, lsl #2 */
/* @0x1c5c48 ldr r12, [r2, #0x8] */
/* @0x1c5c4c and r2, r4, r12 */
/* @0x1c5c50 cmp r12, #0 */
/* @0x1c5c54 rsb r7, r2, r7 */
/* @0x1c5c58 and r7, r7, r4 */
/* @0x1c5c5c bne 0x1c5c1c <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x1e4> */
/* @0x1c5c60 b 0x1c5ac4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x8c> */
/* @0x1c5c64 cmn r3, #1 */
/* @0x1c5c68 beq 0x1c5ac4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x8c> */
/* @0x1c5c6c add r3, r6, r3 */
/* @0x1c5c70 add r1, r1, r3, lsl #2 */
/* @0x1c5c74 cmn r1, #4 */
/* @0x1c5c78 beq 0x1c5ac4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x8c> */
/* @0x1c5c7c ldr r3, [r1, #0x4] */
/* @0x1c5c80 cmp r3, #0 */
/* @0x1c5c84 beq 0x1c5ac4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x8c> */
/* @0x1c5c88 ldr r2, [r3, #0x20] */
/* @0x1c5c8c cmp r2, #0 */
/* @0x1c5c90 beq 0x1c5cc0 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x288> */
/* @0x1c5c94 ldr r3, [pc, #0x74] */
/* @0x1c5c98 ldr r1, [pc, #0x74] */
/* @0x1c5c9c ldr r3, [pc, r3] */
/* @0x1c5ca0 ldr r2, [r8, #0x78] */
/* @0x1c5ca4 add r1, pc, r1 */
/* @0x1c5ca8 ldr r0, [r3] */
/* @0x1c5cac ldr r3, [r0] */
/* @0x1c5cb0 ldr r3, [r3, #0xc] */
/* @0x1c5cb4 blx r3 */
/* @0x1c5cb8 add sp, sp, #4 */
/* @0x1c5cbc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c5cc0 ldr r0, [r10] */
/* @0x1c5cc4 mov r2, #1 */
/* @0x1c5cc8 str r8, [r3, #0x20] */
/* @0x1c5ccc ldrb r1, [r8, #0x69] */
/* @0x1c5cd0 str r0, [r8, #0x170] */
/* @0x1c5cd4 vldr s15, [r10, #4] */
/* @0x1c5cd8 vcvt.f32.s32 s15, s15 */
/* @0x1c5cdc cmp r1, #0 */
/* @0x1c5ce0 strb r2, [r8, #0x174] */
/* @0x1c5ce4 vstr s15, [r8, #384] */
/* @0x1c5ce8 strb r2, [r3, #0x8] */
/* @0x1c5cec beq 0x1c5a6c <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1c5cf0 mov r0, r9 */
/* @0x1c5cf4 mov r1, r8 */
/* @0x1c5cf8 add sp, sp, #4 */
/* @0x1c5cfc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c5d00 b 0x1b8a28 <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance> */
/* @0x1c5d04 mlaeq r2, r12, sp, r10 */
/* @0x1c5d08 andseq r7, r8, r4, lsr #23 */
/* @0x1c5d0c eoreq r10, r2, r12, lsr pc */
/* @0x1c5d10 eoreq r7, r2, r8, ror r10 */
/* @0x1c5d14 ldrheq r10, [r8], -r8 */

/* ── FUNC 0x1c5d18 · CLayerManager::AddInstance(CRoom*, CInstance*) · size=164 · insn=41 */
/* @0x1c5d18 push {r3, r4, r5, lr} */
/* @0x1c5d1c mov r4, r1 */
/* @0x1c5d20 ldr r3, [pc, #0x90] */
/* @0x1c5d24 mov r5, r0 */
/* @0x1c5d28 ldr r3, [pc, r3] */
/* @0x1c5d2c ldrb r3, [r3] */
/* @0x1c5d30 cmp r3, #0 */
/* @0x1c5d34 popeq {r3, r4, r5, pc} */
/* @0x1c5d38 cmp r0, #0 */
/* @0x1c5d3c popeq {r3, r4, r5, pc} */
/* @0x1c5d40 cmp r1, #0 */
/* @0x1c5d44 popeq {r3, r4, r5, pc} */
/* @0x1c5d48 ldrb r3, [r1, #0x174] */
/* @0x1c5d4c cmp r3, #0 */
/* @0x1c5d50 popne {r3, r4, r5, pc} */
/* @0x1c5d54 ldr r1, [r1, #0x170] */
/* @0x1c5d58 cmn r1, #1 */
/* @0x1c5d5c beq 0x1c5d7c <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance+0x64> */
/* @0x1c5d60 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c5d64 subs r1, r0, #0 */
/* @0x1c5d68 beq 0x1c5d7c <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance+0x64> */
/* @0x1c5d6c mov r0, r5 */
/* @0x1c5d70 mov r2, r4 */
/* @0x1c5d74 pop {r3, r4, r5, lr} */
/* @0x1c5d78 b 0x1c5a38 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance> */
/* @0x1c5d7c vldr s15, [r4, #384] */
/* @0x1c5d80 vcvt.s32.f32 s15, s15 */
/* @0x1c5d84 mov r0, r5 */
/* @0x1c5d88 mov r2, #1 */
/* @0x1c5d8c vmov r1, s15 */
/* @0x1c5d90 bl 0x1b87f4 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib> */
/* @0x1c5d94 subs r1, r0, #0 */
/* @0x1c5d98 bne 0x1c5d6c <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance+0x54> */
/* @0x1c5d9c vldr s15, [r4, #384] */
/* @0x1c5da0 vcvt.s32.f32 s15, s15 */
/* @0x1c5da4 mov r0, r5 */
/* @0x1c5da8 vmov r1, s15 */
/* @0x1c5dac bl 0x1c33e4 <_ZN13CLayerManager15AddDynamicLayerEP5CRoomi> */
/* @0x1c5db0 mov r1, r0 */
/* @0x1c5db4 b 0x1c5d6c <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance+0x54> */
/* @0x1c5db8 .word 0x00227bfc */

/* ── FUNC 0x1c5dbc · CLayerManager::BuildRoomLayerRuntimeData(CRoom*) · size=388 · insn=97 */
/* @0x1c5dbc ldr r3, [pc, #0x170] */
/* @0x1c5dc0 push {r4, r5, r6, r7, lr} */
/* @0x1c5dc4 ldr r3, [pc, r3] */
/* @0x1c5dc8 sub sp, sp, #12 */
/* @0x1c5dcc mov r6, r0 */
/* @0x1c5dd0 ldrb r3, [r3] */
/* @0x1c5dd4 cmp r3, #0 */
/* @0x1c5dd8 beq 0x1c5ef4 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x138> */
/* @0x1c5ddc ldr r5, [r0, #0xd4] */
/* @0x1c5de0 cmp r5, #0 */
/* @0x1c5de4 beq 0x1c5e24 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x68> */
/* @0x1c5de8 add r0, r5, #48 */
/* @0x1c5dec bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1c5df0 ldr r4, [r5, #0x58] */
/* @0x1c5df4 cmp r4, #0 */
/* @0x1c5df8 beq 0x1c5e18 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x5c> */
/* @0x1c5dfc mov r2, r4 */
/* @0x1c5e00 mov r0, r6 */
/* @0x1c5e04 mov r1, r5 */
/* @0x1c5e08 bl 0x1ba6bc <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase> */
/* @0x1c5e0c ldr r4, [r4, #0x14] */
/* @0x1c5e10 cmp r4, #0 */
/* @0x1c5e14 bne 0x1c5dfc <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x40> */
/* @0x1c5e18 ldr r5, [r5, #0x68] */
/* @0x1c5e1c cmp r5, #0 */
/* @0x1c5e20 bne 0x1c5de8 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x2c> */
/* @0x1c5e24 ldr r7, [pc, #0x10c] */
/* @0x1c5e28 mov r3, #0 */
/* @0x1c5e2c ldr r7, [pc, r7] */
/* @0x1c5e30 ldr r2, [r7] */
/* @0x1c5e34 ldr r1, [r7, #0x4] */
/* @0x1c5e38 b 0x1c5e44 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x88> */
/* @0x1c5e3c cmp r1, r3 */
/* @0x1c5e40 blt 0x1c5efc <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x140> */
/* @0x1c5e44 mov r5, r3 */
/* @0x1c5e48 add r3, r3, #1 */
/* @0x1c5e4c ldr r4, [r2, r5, lsl #3] */
/* @0x1c5e50 cmp r4, #0 */
/* @0x1c5e54 beq 0x1c5e3c <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x80> */
/* @0x1c5e58 cmp r4, #0 */
/* @0x1c5e5c beq 0x1c5ec0 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x104> */
/* @0x1c5e60 ldr r1, [r4, #0xc] */
/* @0x1c5e64 cmp r1, #0 */
/* @0x1c5e68 beq 0x1c5ec0 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x104> */
/* @0x1c5e6c mov r0, r6 */
/* @0x1c5e70 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1c5e74 ldr r4, [r4, #0x4] */
/* @0x1c5e78 cmp r4, #0 */
/* @0x1c5e7c bne 0x1c5e58 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x9c> */
/* @0x1c5e80 ldr r1, [r7, #0x4] */
/* @0x1c5e84 add r3, r5, #1 */
/* @0x1c5e88 cmp r3, r1 */
/* @0x1c5e8c bgt 0x1c5ec0 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x104> */
/* @0x1c5e90 ldr r2, [r7] */
/* @0x1c5e94 add r2, r2, r5, lsl #3 */
/* @0x1c5e98 b 0x1c5ea4 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0xe8> */
/* @0x1c5e9c cmp r3, r1 */
/* @0x1c5ea0 bgt 0x1c5ec0 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x104> */
/* @0x1c5ea4 ldr r4, [r2, #0x8] */
/* @0x1c5ea8 mov r5, r3 */
/* @0x1c5eac add r2, r2, #8 */
/* @0x1c5eb0 add r3, r3, #1 */
/* @0x1c5eb4 cmp r4, #0 */
/* @0x1c5eb8 beq 0x1c5e9c <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0xe0> */
/* @0x1c5ebc b 0x1c5e58 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x9c> */
/* @0x1c5ec0 ldr r4, [pc, #0x74] */
/* @0x1c5ec4 ldr r4, [pc, r4] */
/* @0x1c5ec8 ldr r5, [r4] */
/* @0x1c5ecc cmp r5, #0 */
/* @0x1c5ed0 beq 0x1c5f04 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x148> */
/* @0x1c5ed4 ldr r4, [r6, #0xd4] */
/* @0x1c5ed8 cmp r4, #0 */
/* @0x1c5edc beq 0x1c5ef4 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x138> */
/* @0x1c5ee0 mov r0, r4 */
/* @0x1c5ee4 bl 0x1b8bfc <_ZN13CLayerManager24SortDeactivatedInstancesEP6CLayer> */
/* @0x1c5ee8 ldr r4, [r4, #0x68] */
/* @0x1c5eec cmp r4, #0 */
/* @0x1c5ef0 bne 0x1c5ee0 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x124> */
/* @0x1c5ef4 add sp, sp, #12 */
/* @0x1c5ef8 pop {r4, r5, r6, r7, pc} */
/* @0x1c5efc mvn r5, #0 */
/* @0x1c5f00 b 0x1c5e58 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x9c> */
/* @0x1c5f04 mov r0, #432 */
/* @0x1c5f08 bl 0x27c524 <_Znwj> */
/* @0x1c5f0c mov r1, #0 */
/* @0x1c5f10 mvn r2, #0 */
/* @0x1c5f14 mov r3, r5 */
/* @0x1c5f18 str r2, [sp] */
/* @0x1c5f1c mov r2, r1 */
/* @0x1c5f20 str r5, [sp, #0x4] */
/* @0x1c5f24 mov r7, r0 */
/* @0x1c5f28 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1c5f2c str r7, [r4] */
/* @0x1c5f30 b 0x1c5ed4 <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom+0x118> */
/* @0x1c5f34 eoreq r7, r2, r0, ror #22 */
/* @0x1c5f38 eoreq r7, r2, r8, lsl lr */
/* @0x1c5f3c eoreq r7, r2, r12, lsr #27 */

/* ── FUNC 0x1c5f40 · CLayerManager::ChangeInstanceDepth(CRoom*, CInstance*) · size=176 · insn=44 */
/* @0x1c5f40 push {r4, r5, r6, lr} */
/* @0x1c5f44 subs r5, r0, #0 */
/* @0x1c5f48 mov r4, r1 */
/* @0x1c5f4c popeq {r4, r5, r6, pc} */
/* @0x1c5f50 cmp r1, #0 */
/* @0x1c5f54 popeq {r4, r5, r6, pc} */
/* @0x1c5f58 ldrb r3, [r1, #0x174] */
/* @0x1c5f5c cmp r3, #0 */
/* @0x1c5f60 popeq {r4, r5, r6, pc} */
/* @0x1c5f64 ldr r1, [r1, #0x170] */
/* @0x1c5f68 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c5f6c subs r1, r0, #0 */
/* @0x1c5f70 popeq {r4, r5, r6, pc} */
/* @0x1c5f74 vldr s15, [r4, #384] */
/* @0x1c5f78 vcvt.s32.f32 s15, s15 */
/* @0x1c5f7c ldr r3, [r1, #0x4] */
/* @0x1c5f80 vmov r2, s15 */
/* @0x1c5f84 cmp r3, r2 */
/* @0x1c5f88 popeq {r4, r5, r6, pc} */
/* @0x1c5f8c ldrb r3, [r1, #0x19] */
/* @0x1c5f90 cmp r3, #0 */
/* @0x1c5f94 beq 0x1c5fa4 <_ZN13CLayerManager19ChangeInstanceDepthEP5CRoomP9CInstance+0x64> */
/* @0x1c5f98 ldr r3, [r1, #0x60] */
/* @0x1c5f9c cmp r3, #1 */
/* @0x1c5fa0 beq 0x1c5fc8 <_ZN13CLayerManager19ChangeInstanceDepthEP5CRoomP9CInstance+0x88> */
/* @0x1c5fa4 mov r0, r5 */
/* @0x1c5fa8 mov r1, r4 */
/* @0x1c5fac bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> */
/* @0x1c5fb0 mov r0, r5 */
/* @0x1c5fb4 mvn r3, #0 */
/* @0x1c5fb8 mov r1, r4 */
/* @0x1c5fbc str r3, [r4, #0x170] */
/* @0x1c5fc0 pop {r4, r5, r6, lr} */
/* @0x1c5fc4 b 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1c5fc8 ldr r0, [r1, #0x58] */
/* @0x1c5fcc ldr r12, [r0] */
/* @0x1c5fd0 cmp r12, #2 */
/* @0x1c5fd4 popne {r4, r5, r6, pc} */
/* @0x1c5fd8 ldr r0, [r0, #0x20] */
/* @0x1c5fdc cmp r0, r4 */
/* @0x1c5fe0 popne {r4, r5, r6, pc} */
/* @0x1c5fe4 mov r0, r5 */
/* @0x1c5fe8 pop {r4, r5, r6, lr} */
/* @0x1c5fec b 0x1b8200 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib> */

/* ── FUNC 0x1c5ff0 · CLayerManager::AddNewElement(CRoom*, CLayer*, CLayerElementBase*, bool) · size=124 · insn=31 */
/* @0x1c5ff0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c5ff4 subs r8, r0, #0 */
/* @0x1c5ff8 mov r6, r3 */
/* @0x1c5ffc mov r5, r1 */
/* @0x1c6000 mov r4, r2 */
/* @0x1c6004 beq 0x1c6060 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x70> */
/* @0x1c6008 cmp r1, #0 */
/* @0x1c600c beq 0x1c6060 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x70> */
/* @0x1c6010 cmp r2, #0 */
/* @0x1c6014 beq 0x1c6060 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x70> */
/* @0x1c6018 ldr r12, [pc, #0x48] */
/* @0x1c601c mov r3, #0 */
/* @0x1c6020 ldr r12, [pc, r12] */
/* @0x1c6024 ldr lr, [r12] */
/* @0x1c6028 add r7, lr, #1 */
/* @0x1c602c str r7, [r12] */
/* @0x1c6030 str lr, [r2, #0x4] */
/* @0x1c6034 bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c6038 cmp r6, #0 */
/* @0x1c603c bne 0x1c6048 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x58> */
/* @0x1c6040 ldr r0, [r4, #0x4] */
/* @0x1c6044 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c6048 mov r0, r8 */
/* @0x1c604c mov r1, r5 */
/* @0x1c6050 mov r2, r4 */
/* @0x1c6054 bl 0x1ba6bc <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase> */
/* @0x1c6058 ldr r0, [r4, #0x4] */
/* @0x1c605c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c6060 mvn r0, #0 */
/* @0x1c6064 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c6068 eoreq r10, r2, r0, asr #21 */

/* ── FUNC 0x1c606c · anon_1c606c · size=0 · insn=1 */
/* @0x1c606c andeq r0, r0, r0 */

/* ── FUNC 0x1c6070 · CLayerManager::BuildRoomLayers(CRoom*, YYRoomLayers*) · size=3076 · insn=766 */
/* @0x1c6070 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c6074 vpush {d8, d9} */
/* @0x1c6078 sub sp, sp, #60 */
/* @0x1c607c cmp r0, #0 */
/* @0x1c6080 mov r4, r1 */
/* @0x1c6084 str r0, [sp, #0x4] */
/* @0x1c6088 ldr r0, [pc, #0x3c0] */
/* @0x1c608c add r0, pc, r0 */
/* @0x1c6090 str r0, [sp, #0x10] */
/* @0x1c6094 beq 0x1c6a84 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa14> */
/* @0x1c6098 cmp r1, #0 */
/* @0x1c609c beq 0x1c6a84 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa14> */
/* @0x1c60a0 ldr r3, [pc, #0x3ac] */
/* @0x1c60a4 ldr r3, [r0, r3] */
/* @0x1c60a8 ldrb r3, [r3] */
/* @0x1c60ac cmp r3, #0 */
/* @0x1c60b0 beq 0x1c6c6c <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xbfc> */
/* @0x1c60b4 ldr r1, [r4] */
/* @0x1c60b8 cmp r1, #0 */
/* @0x1c60bc str r1, [sp, #0x1c] */
/* @0x1c60c0 ble 0x1c6a84 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa14> */
/* @0x1c60c4 str r4, [sp, #0x14] */
/* @0x1c60c8 mov r4, #0 */
/* @0x1c60cc str r4, [sp, #0xc] */
/* @0x1c60d0 vldr s18, [pc, #880] */
/* @0x1c60d4 ldr r4, [pc, #0x37c] */
/* @0x1c60d8 vldr d8, [pc, #864] */
/* @0x1c60dc ldr r2, [pc, #0x378] */
/* @0x1c60e0 vldr s19, [pc, #868] */
/* @0x1c60e4 add r4, pc, r4 */
/* @0x1c60e8 ldr r3, [pc, #0x370] */
/* @0x1c60ec str r4, [sp, #0x28] */
/* @0x1c60f0 ldr r4, [sp, #0x10] */
/* @0x1c60f4 ldr r10, [r4, r2] */
/* @0x1c60f8 ldr r3, [r4, r3] */
/* @0x1c60fc ldr r4, [pc, #0x360] */
/* @0x1c6100 add r4, pc, r4 */
/* @0x1c6104 str r4, [sp, #0x34] */
/* @0x1c6108 ldr r4, [pc, #0x358] */
/* @0x1c610c str r3, [sp, #0x24] */
/* @0x1c6110 add r4, pc, r4 */
/* @0x1c6114 str r4, [sp, #0x30] */
/* @0x1c6118 ldr r4, [r10, #0x8] */
/* @0x1c611c cmp r4, #0 */
/* @0x1c6120 bne 0x1c6204 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x194> */
/* @0x1c6124 ldr r3, [r10, #0x10] */
/* @0x1c6128 cmp r3, #0 */
/* @0x1c612c ble 0x1c61fc <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x18c> */
/* @0x1c6130 ldr r8, [sp, #0x28] */
/* @0x1c6134 mov r5, #1 */
/* @0x1c6138 mov r3, #1 */
/* @0x1c613c mov r0, #112 */
/* @0x1c6140 mov r1, r8 */
/* @0x1c6144 mov r2, #63 */
/* @0x1c6148 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c614c mov r7, #0 */
/* @0x1c6150 mvn r3, #0 */
/* @0x1c6154 subs r6, r0, #0 */
/* @0x1c6158 add r0, r6, #48 */
/* @0x1c615c beq 0x1c61b0 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x140> */
/* @0x1c6160 str r3, [r6] */
/* @0x1c6164 vstr s18, [r6, #8] */
/* @0x1c6168 str r7, [r6, #0x4] */
/* @0x1c616c vstr s18, [r6, #12] */
/* @0x1c6170 vstr s18, [r6, #16] */
/* @0x1c6174 vstr s18, [r6, #20] */
/* @0x1c6178 strb r5, [r6, #0x18] */
/* @0x1c617c vstr d8, [r6, #72] */
/* @0x1c6180 strb r7, [r6, #0x19] */
/* @0x1c6184 str r7, [r6, #0x1c] */
/* @0x1c6188 str r3, [r6, #0x20] */
/* @0x1c618c str r3, [r6, #0x24] */
/* @0x1c6190 str r3, [r6, #0x28] */
/* @0x1c6194 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1c6198 str r7, [r6, #0x5c] */
/* @0x1c619c str r7, [r6, #0x58] */
/* @0x1c61a0 str r7, [r6, #0x60] */
/* @0x1c61a4 str r5, [r6, #0x64] */
/* @0x1c61a8 str r7, [r6, #0x68] */
/* @0x1c61ac str r7, [r6, #0x6c] */
/* @0x1c61b0 ldr r3, [r10] */
/* @0x1c61b4 mov r1, #0 */
/* @0x1c61b8 add r4, r4, #1 */
/* @0x1c61bc ldr r2, [r10, #0x8] */
/* @0x1c61c0 cmp r3, r1 */
/* @0x1c61c4 streq r6, [r10, #0x4] */
/* @0x1c61c8 strne r6, [r3, #0x6c] */
/* @0x1c61cc add r2, r2, #1 */
/* @0x1c61d0 streq r3, [r6, #0x6c] */
/* @0x1c61d4 streq r3, [r6, #0x68] */
/* @0x1c61d8 strne r3, [r6, #0x68] */
/* @0x1c61dc ldr r3, [r10, #0x10] */
/* @0x1c61e0 streq r6, [r10] */
/* @0x1c61e4 strne r6, [r10] */
/* @0x1c61e8 strne r1, [r6, #0x6c] */
/* @0x1c61ec cmp r4, r3 */
/* @0x1c61f0 str r2, [r10, #0x8] */
/* @0x1c61f4 blt 0x1c6138 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xc8> */
/* @0x1c61f8 ldr r4, [r10, #0x8] */
/* @0x1c61fc lsl r3, r3, #1 */
/* @0x1c6200 str r3, [r10, #0x10] */
/* @0x1c6204 ldr r7, [r10] */
/* @0x1c6208 sub r4, r4, #1 */
/* @0x1c620c str r4, [r10, #0x8] */
/* @0x1c6210 ldr r4, [sp, #0x14] */
/* @0x1c6214 ldr r3, [r7, #0x6c] */
/* @0x1c6218 ldr r2, [r7, #0x68] */
/* @0x1c621c cmp r3, #0 */
/* @0x1c6220 ldr r11, [r4, #0x4]! */
/* @0x1c6224 strne r2, [r3, #0x68] */
/* @0x1c6228 ldrne r2, [r7, #0x68] */
/* @0x1c622c ldrne r3, [r7, #0x6c] */
/* @0x1c6230 streq r2, [r10] */
/* @0x1c6234 cmp r2, #0 */
/* @0x1c6238 streq r3, [r10, #0x4] */
/* @0x1c623c strne r3, [r2, #0x6c] */
/* @0x1c6240 cmp r11, #0 */
/* @0x1c6244 str r4, [sp, #0x14] */
/* @0x1c6248 beq 0x1c6260 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x1f0> */
/* @0x1c624c ldr r3, [pc, #0x220] */
/* @0x1c6250 ldr r4, [sp, #0x10] */
/* @0x1c6254 ldr r3, [r4, r3] */
/* @0x1c6258 ldr r3, [r3] */
/* @0x1c625c add r11, r3, r11 */
/* @0x1c6260 ldr r3, [r11] */
/* @0x1c6264 cmp r3, #0 */
/* @0x1c6268 beq 0x1c6280 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x210> */
/* @0x1c626c ldr r2, [pc, #0x200] */
/* @0x1c6270 ldr r4, [sp, #0x10] */
/* @0x1c6274 ldr r2, [r4, r2] */
/* @0x1c6278 ldr r2, [r2] */
/* @0x1c627c add r3, r2, r3 */
/* @0x1c6280 ldr r2, [r11, #0x10] */
/* @0x1c6284 ldr r1, [r11, #0xc] */
/* @0x1c6288 ldr r0, [r11, #0x4] */
/* @0x1c628c ldr r12, [r11, #0x8] */
/* @0x1c6290 str r2, [r7, #0x8] */
/* @0x1c6294 ldr r2, [r11, #0x20] */
/* @0x1c6298 str r1, [r7, #0x4] */
/* @0x1c629c ldr r1, [r11, #0x14] */
/* @0x1c62a0 adds r2, r2, #0 */
/* @0x1c62a4 str r3, [r7, #0x1c] */
/* @0x1c62a8 sub r3, r12, #1 */
/* @0x1c62ac movne r2, #1 */
/* @0x1c62b0 str r0, [r7] */
/* @0x1c62b4 str r1, [r7, #0xc] */
/* @0x1c62b8 ldr r1, [r11, #0x18] */
/* @0x1c62bc str r1, [r7, #0x10] */
/* @0x1c62c0 ldr r1, [r11, #0x1c] */
/* @0x1c62c4 strb r2, [r7, #0x18] */
/* @0x1c62c8 str r1, [r7, #0x14] */
/* @0x1c62cc cmp r3, #3 */
/* @0x1c62d0 addls pc, pc, r3, lsl #2 */
/* @0x1c62d4 b 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c62d8 b 0x1c6a90 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa20> */
/* @0x1c62dc b 0x1c68fc <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x88c> */
/* @0x1c62e0 b 0x1c6494 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x424> */
/* @0x1c62e4 b 0x1c62e8 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x278> */
/* @0x1c62e8 ldr r3, [pc, #0x17c] */
/* @0x1c62ec ldr r4, [sp, #0x10] */
/* @0x1c62f0 ldr r5, [r4, r3] */
/* @0x1c62f4 ldr r6, [r5, #0x8] */
/* @0x1c62f8 cmp r6, #0 */
/* @0x1c62fc bne 0x1c63c8 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x358> */
/* @0x1c6300 ldr r3, [r5, #0x10] */
/* @0x1c6304 cmp r3, #0 */
/* @0x1c6308 ble 0x1c63c0 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x350> */
/* @0x1c630c ldr r8, [sp, #0x34] */
/* @0x1c6310 mov r4, r6 */
/* @0x1c6314 mov r1, r8 */
/* @0x1c6318 mov r2, #63 */
/* @0x1c631c mov r3, #1 */
/* @0x1c6320 mov r0, #60 */
/* @0x1c6324 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c6328 ldr r3, [r5] */
/* @0x1c632c mvn r2, #0 */
/* @0x1c6330 mvn r12, #-2147483648 */
/* @0x1c6334 mov r1, #5 */
/* @0x1c6338 cmp r0, #0 */
/* @0x1c633c beq 0x1c637c <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x30c> */
/* @0x1c6340 strb r4, [r0, #0x8] */
/* @0x1c6344 vstr s18, [r0, #32] */
/* @0x1c6348 str r4, [r0, #0xc] */
/* @0x1c634c vstr s18, [r0, #36] */
/* @0x1c6350 str r4, [r0, #0x10] */
/* @0x1c6354 vstr s18, [r0, #48] */
/* @0x1c6358 str r4, [r0, #0x14] */
/* @0x1c635c str r4, [r0, #0x18] */
/* @0x1c6360 str r2, [r0, #0x4] */
/* @0x1c6364 str r2, [r0, #0x1c] */
/* @0x1c6368 str r4, [r0, #0x28] */
/* @0x1c636c str r4, [r0, #0x2c] */
/* @0x1c6370 str r4, [r0, #0x34] */
/* @0x1c6374 str r12, [r0, #0x38] */
/* @0x1c6378 str r1, [r0] */
/* @0x1c637c cmp r3, #0 */
/* @0x1c6380 strne r0, [r3, #0x18] */
/* @0x1c6384 streq r3, [r0, #0x18] */
/* @0x1c6388 add r6, r6, #1 */
/* @0x1c638c streq r3, [r0, #0x14] */
/* @0x1c6390 strne r3, [r0, #0x14] */
/* @0x1c6394 ldr r3, [r5, #0x10] */
/* @0x1c6398 ldr r2, [r5, #0x8] */
/* @0x1c639c streq r0, [r5, #0x4] */
/* @0x1c63a0 streq r0, [r5] */
/* @0x1c63a4 add r2, r2, #1 */
/* @0x1c63a8 strne r0, [r5] */
/* @0x1c63ac strne r4, [r0, #0x18] */
/* @0x1c63b0 cmp r6, r3 */
/* @0x1c63b4 str r2, [r5, #0x8] */
/* @0x1c63b8 blt 0x1c6314 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x2a4> */
/* @0x1c63bc ldr r6, [r5, #0x8] */
/* @0x1c63c0 lsl r3, r3, #1 */
/* @0x1c63c4 str r3, [r5, #0x10] */
/* @0x1c63c8 ldr r3, [r5] */
/* @0x1c63cc sub r6, r6, #1 */
/* @0x1c63d0 ldr r0, [r11, #0x2c] */
/* @0x1c63d4 ldr r12, [r11, #0x24] */
/* @0x1c63d8 ldr r2, [r3, #0x18] */
/* @0x1c63dc ldr r1, [r3, #0x14] */
/* @0x1c63e0 cmp r2, #0 */
/* @0x1c63e4 str r6, [r5, #0x8] */
/* @0x1c63e8 strne r1, [r2, #0x14] */
/* @0x1c63ec ldrne r1, [r3, #0x14] */
/* @0x1c63f0 ldrne r2, [r3, #0x18] */
/* @0x1c63f4 streq r1, [r5] */
/* @0x1c63f8 cmp r1, #0 */
/* @0x1c63fc streq r2, [r5, #0x4] */
/* @0x1c6400 strne r2, [r1, #0x18] */
/* @0x1c6404 add r1, r11, #48 */
/* @0x1c6408 ldr r2, [r11, #0x28] */
/* @0x1c640c ldr lr, [r7, #0x1c] */
/* @0x1c6410 str r12, [r3, #0x1c] */
/* @0x1c6414 str r2, [r3, #0x28] */
/* @0x1c6418 mov r2, r3 */
/* @0x1c641c str r0, [r3, #0x2c] */
/* @0x1c6420 str r1, [r3, #0x34] */
/* @0x1c6424 mov r1, r7 */
/* @0x1c6428 str lr, [r3, #0xc] */
/* @0x1c642c mov r3, #0 */
/* @0x1c6430 ldr r0, [sp, #0x4] */
/* @0x1c6434 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c6438 b 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c643c nop */
/* @0x1c644c cmnmi pc, #0 */
/* @0x1c6450 eoreq r11, r2, r4, asr #23 */
/* @0x1c6454 .word 0xffffec08 */
/* @0x1c6458 ldrheq r7, [r8], -r0 */
/* @0x1c645c .word 0xffffec0c */
/* @0x1c6460 .word 0xffffec30 */
/* @0x1c6464 mulseq r8, r4, r5 */
/* @0x1c6468 andseq r7, r8, r4, lsl #11 */
/* @0x1c646c .word 0xffffec20 */
/* @0x1c6470 .word 0xffffec28 */
/* @0x1c6474 .word 0xffffbcf4 */
/* @0x1c6478 .word 0xffffec1c */
/* @0x1c647c andseq r6, r8, r12, ror pc */
/* @0x1c6480 andseq r6, r8, r4, ror sp */
/* @0x1c6484 .word 0xffffec14 */
/* @0x1c6488 .word 0xffffec10 */
/* @0x1c648c ldrsbeq r6, [r8], -r0 */
/* @0x1c6490 ldrsheq r6, [r8], -r12 */
/* @0x1c6494 ldr r3, [r11, #0x24] */
/* @0x1c6498 cmp r3, #0 */
/* @0x1c649c beq 0x1c66cc <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x65c> */
/* @0x1c64a0 ldr r2, [pc, #-0x34] */
/* @0x1c64a4 ldr r4, [sp, #0x10] */
/* @0x1c64a8 ldr r2, [r4, r2] */
/* @0x1c64ac str r2, [sp, #0x20] */
/* @0x1c64b0 ldr r2, [r2] */
/* @0x1c64b4 adds r12, r2, r3 */
/* @0x1c64b8 beq 0x1c66cc <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x65c> */
/* @0x1c64bc ldr r3, [r2, r3] */
/* @0x1c64c0 cmp r3, #0 */
/* @0x1c64c4 ble 0x1c66cc <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x65c> */
/* @0x1c64c8 ldr r3, [pc, #-0x60] */
/* @0x1c64cc mov r6, #0 */
/* @0x1c64d0 ldr r0, [sp, #0x10] */
/* @0x1c64d4 mov r4, r6 */
/* @0x1c64d8 ldr r8, [sp, #0x30] */
/* @0x1c64dc mov r9, r12 */
/* @0x1c64e0 ldr r5, [r0, r3] */
/* @0x1c64e4 str r10, [sp, #0x2c] */
/* @0x1c64e8 mov r10, r12 */
/* @0x1c64ec str r11, [sp, #0x18] */
/* @0x1c64f0 str r7, [sp, #0x8] */
/* @0x1c64f4 ldr r11, [r9, #0x4]! */
/* @0x1c64f8 ldr r2, [r5, #0x8] */
/* @0x1c64fc cmp r11, #0 */
/* @0x1c6500 ldrne r1, [sp, #0x20] */
/* @0x1c6504 ldrne r3, [r1] */
/* @0x1c6508 addne r11, r3, r11 */
/* @0x1c650c cmp r2, #0 */
/* @0x1c6510 bne 0x1c65e8 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x578> */
/* @0x1c6514 ldr r3, [r5, #0x10] */
/* @0x1c6518 cmp r3, #0 */
/* @0x1c651c ble 0x1c65e0 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x570> */
/* @0x1c6520 mov r7, r2 */
/* @0x1c6524 mov r1, r8 */
/* @0x1c6528 mov r3, #1 */
/* @0x1c652c mov r0, #80 */
/* @0x1c6530 mov r2, #63 */
/* @0x1c6534 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c6538 mvn r3, #0 */
/* @0x1c653c mov r1, #7 */
/* @0x1c6540 cmp r0, #0 */
/* @0x1c6544 beq 0x1c6598 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x528> */
/* @0x1c6548 mov r2, #1065353216 */
/* @0x1c654c strb r4, [r0, #0x8] */
/* @0x1c6550 str r4, [r0, #0xc] */
/* @0x1c6554 vstr s18, [r0, #36] */
/* @0x1c6558 str r4, [r0, #0x10] */
/* @0x1c655c vstr s18, [r0, #40] */
/* @0x1c6560 str r4, [r0, #0x14] */
/* @0x1c6564 vstr s18, [r0, #60] */
/* @0x1c6568 str r4, [r0, #0x18] */
/* @0x1c656c str r3, [r0, #0x4] */
/* @0x1c6570 str r3, [r0, #0x20] */
/* @0x1c6574 str r4, [r0, #0x2c] */
/* @0x1c6578 str r4, [r0, #0x30] */
/* @0x1c657c str r3, [r0, #0x40] */
/* @0x1c6580 str r4, [r0, #0x48] */
/* @0x1c6584 str r2, [r0, #0x34] */
/* @0x1c6588 str r4, [r0, #0x4c] */
/* @0x1c658c str r2, [r0, #0x38] */
/* @0x1c6590 str r1, [r0] */
/* @0x1c6594 str r2, [r0, #0x44] */
/* @0x1c6598 ldr r3, [r5] */
/* @0x1c659c add r7, r7, #1 */
/* @0x1c65a0 ldr r2, [r5, #0x8] */
/* @0x1c65a4 cmp r3, #0 */
/* @0x1c65a8 streq r0, [r5, #0x4] */
/* @0x1c65ac strne r0, [r3, #0x18] */
/* @0x1c65b0 add r2, r2, #1 */
/* @0x1c65b4 streq r3, [r0, #0x18] */
/* @0x1c65b8 streq r3, [r0, #0x14] */
/* @0x1c65bc strne r3, [r0, #0x14] */
/* @0x1c65c0 ldr r3, [r5, #0x10] */
/* @0x1c65c4 streq r0, [r5] */
/* @0x1c65c8 strne r0, [r5] */
/* @0x1c65cc strne r4, [r0, #0x18] */
/* @0x1c65d0 cmp r7, r3 */
/* @0x1c65d4 str r2, [r5, #0x8] */
/* @0x1c65d8 blt 0x1c6524 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x4b4> */
/* @0x1c65dc ldr r2, [r5, #0x8] */
/* @0x1c65e0 lsl r3, r3, #1 */
/* @0x1c65e4 str r3, [r5, #0x10] */
/* @0x1c65e8 ldr r12, [r5] */
/* @0x1c65ec vldr s14, [r11] */
/* @0x1c65f0 ldr r0, [r11, #0x24] */
/* @0x1c65f4 sub r2, r2, #1 */
/* @0x1c65f8 vldr s15, [r11, #4] */
/* @0x1c65fc vcvt.f32.s32 s14, s14 */
/* @0x1c6600 ldr r3, [r12, #0x18] */
/* @0x1c6604 mov lr, #1 */
/* @0x1c6608 ldr r1, [r12, #0x14] */
/* @0x1c660c add r6, r6, lr */
/* @0x1c6610 cmp r3, #0 */
/* @0x1c6614 strne r1, [r3, #0x14] */
/* @0x1c6618 ldrne r1, [r12, #0x14] */
/* @0x1c661c ldrne r3, [r12, #0x18] */
/* @0x1c6620 vcvt.f32.s32 s15, s15 */
/* @0x1c6624 streq r1, [r5] */
/* @0x1c6628 cmp r1, #0 */
/* @0x1c662c streq r3, [r5, #0x4] */
/* @0x1c6630 strne r3, [r1, #0x18] */
/* @0x1c6634 ldr r3, [r11, #0x2c] */
/* @0x1c6638 ldr r1, [r11, #0x8] */
/* @0x1c663c str r0, [r12, #0x34] */
/* @0x1c6640 lsr r0, r3, #24 */
/* @0x1c6644 str r2, [r5, #0x8] */
/* @0x1c6648 bic r3, r3, #-16777216 */
/* @0x1c664c ldr r2, [r11, #0x28] */
/* @0x1c6650 vmov s13, r0 */
/* @0x1c6654 str r3, [r12, #0x40] */
/* @0x1c6658 ldr r3, [r11, #0xc] */
/* @0x1c665c vcvt.f32.s32 s13, s13 */
/* @0x1c6660 str r1, [r12, #0x20] */
/* @0x1c6664 ldr r1, [r11, #0x14] */
/* @0x1c6668 str r3, [r12, #0x48] */
/* @0x1c666c ldr r3, [r11, #0x10] */
/* @0x1c6670 str r2, [r12, #0x38] */
/* @0x1c6674 mov r2, r12 */
/* @0x1c6678 ldr r0, [sp, #0x4] */
/* @0x1c667c str r3, [r12, #0x4c] */
/* @0x1c6680 vdiv.f32 s13, s13, s19 */
/* @0x1c6684 ldr r3, [r11, #0x18] */
/* @0x1c6688 str r1, [r12, #0x2c] */
/* @0x1c668c vstr s14, [r12, #36] */
/* @0x1c6690 vstr s18, [r12, #60] */
/* @0x1c6694 str r4, [r12, #0xc] */
/* @0x1c6698 ldr r1, [sp, #0x8] */
/* @0x1c669c vstr s13, [r12, #68] */
/* @0x1c66a0 str r3, [r12, #0x30] */
/* @0x1c66a4 mov r3, #0 */
/* @0x1c66a8 strb lr, [r12, #0x1c] */
/* @0x1c66ac vstr s15, [r12, #40] */
/* @0x1c66b0 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c66b4 ldr r3, [r10] */
/* @0x1c66b8 cmp r3, r6 */
/* @0x1c66bc bgt 0x1c64f4 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x484> */
/* @0x1c66c0 ldr r11, [sp, #0x18] */
/* @0x1c66c4 ldr r7, [sp, #0x8] */
/* @0x1c66c8 ldr r10, [sp, #0x2c] */
/* @0x1c66cc ldr r3, [r11, #0x28] */
/* @0x1c66d0 cmp r3, #0 */
/* @0x1c66d4 beq 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c66d8 ldr r2, [pc, #-0x26c] */
/* @0x1c66dc ldr r4, [sp, #0x10] */
/* @0x1c66e0 ldr r2, [r4, r2] */
/* @0x1c66e4 str r2, [sp, #0x20] */
/* @0x1c66e8 ldr r2, [r2] */
/* @0x1c66ec adds r11, r2, r3 */
/* @0x1c66f0 beq 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c66f4 ldr r2, [r2, r3] */
/* @0x1c66f8 cmp r2, #0 */
/* @0x1c66fc str r2, [sp, #0x8] */
/* @0x1c6700 ble 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c6704 ldr r3, [pc, #-0x294] */
/* @0x1c6708 mov r9, #0 */
/* @0x1c670c ldr r8, [pc, #-0x298] */
/* @0x1c6710 mov r5, r9 */
/* @0x1c6714 ldr r4, [r4, r3] */
/* @0x1c6718 add r8, pc, r8 */
/* @0x1c671c str r10, [sp, #0x2c] */
/* @0x1c6720 mov r10, r11 */
/* @0x1c6724 ldr r11, [sp, #0x20] */
/* @0x1c6728 str r7, [sp, #0x18] */
/* @0x1c672c ldr r12, [r10, #0x4]! */
/* @0x1c6730 ldr r6, [r4, #0x8] */
/* @0x1c6734 cmp r12, #0 */
/* @0x1c6738 ldrne r3, [r11] */
/* @0x1c673c moveq r7, r12 */
/* @0x1c6740 addne r7, r3, r12 */
/* @0x1c6744 cmp r6, #0 */
/* @0x1c6748 bne 0x1c6818 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x7a8> */
/* @0x1c674c ldr r3, [r4, #0x10] */
/* @0x1c6750 cmp r3, #0 */
/* @0x1c6754 ble 0x1c6810 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x7a0> */
/* @0x1c6758 mov r1, r8 */
/* @0x1c675c mov r2, #63 */
/* @0x1c6760 mov r0, #72 */
/* @0x1c6764 mov r3, #1 */
/* @0x1c6768 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c676c mvn r2, #0 */
/* @0x1c6770 mov r1, #4 */
/* @0x1c6774 cmp r0, #0 */
/* @0x1c6778 beq 0x1c67c8 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x758> */
/* @0x1c677c mov r3, #1065353216 */
/* @0x1c6780 strb r5, [r0, #0x8] */
/* @0x1c6784 str r5, [r0, #0xc] */
/* @0x1c6788 vstr s18, [r0, #32] */
/* @0x1c678c str r5, [r0, #0x10] */
/* @0x1c6790 vstr s18, [r0, #52] */
/* @0x1c6794 str r5, [r0, #0x14] */
/* @0x1c6798 vstr s18, [r0, #64] */
/* @0x1c679c str r5, [r0, #0x18] */
/* @0x1c67a0 vstr s18, [r0, #68] */
/* @0x1c67a4 str r2, [r0, #0x4] */
/* @0x1c67a8 str r2, [r0, #0x1c] */
/* @0x1c67ac str r5, [r0, #0x28] */
/* @0x1c67b0 str r2, [r0, #0x38] */
/* @0x1c67b4 str r1, [r0] */
/* @0x1c67b8 str r3, [r0, #0x24] */
/* @0x1c67bc str r3, [r0, #0x2c] */
/* @0x1c67c0 str r3, [r0, #0x30] */
/* @0x1c67c4 str r3, [r0, #0x3c] */
/* @0x1c67c8 ldr r3, [r4] */
/* @0x1c67cc add r6, r6, #1 */
/* @0x1c67d0 ldr r2, [r4, #0x8] */
/* @0x1c67d4 cmp r3, #0 */
/* @0x1c67d8 streq r0, [r4, #0x4] */
/* @0x1c67dc strne r0, [r3, #0x18] */
/* @0x1c67e0 add r2, r2, #1 */
/* @0x1c67e4 streq r3, [r0, #0x18] */
/* @0x1c67e8 streq r3, [r0, #0x14] */
/* @0x1c67ec strne r3, [r0, #0x14] */
/* @0x1c67f0 ldr r3, [r4, #0x10] */
/* @0x1c67f4 streq r0, [r4] */
/* @0x1c67f8 strne r0, [r4] */
/* @0x1c67fc strne r5, [r0, #0x18] */
/* @0x1c6800 cmp r6, r3 */
/* @0x1c6804 str r2, [r4, #0x8] */
/* @0x1c6808 blt 0x1c6758 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x6e8> */
/* @0x1c680c ldr r6, [r4, #0x8] */
/* @0x1c6810 lsl r3, r3, #1 */
/* @0x1c6814 str r3, [r4, #0x10] */
/* @0x1c6818 ldr r2, [r4] */
/* @0x1c681c vldr s14, [r7, #8] */
/* @0x1c6820 ldr r0, [r7, #0x4] */
/* @0x1c6824 vldr s15, [r7, #12] */
/* @0x1c6828 vcvt.f32.s32 s14, s14 */
/* @0x1c682c sub r6, r6, #1 */
/* @0x1c6830 ldr r3, [r2, #0x18] */
/* @0x1c6834 add r9, r9, #1 */
/* @0x1c6838 ldr r1, [r2, #0x14] */
/* @0x1c683c cmp r3, #0 */
/* @0x1c6840 str r6, [r4, #0x8] */
/* @0x1c6844 strne r1, [r3, #0x14] */
/* @0x1c6848 ldrne r1, [r2, #0x14] */
/* @0x1c684c ldrne r3, [r2, #0x18] */
/* @0x1c6850 vcvt.f32.s32 s15, s15 */
/* @0x1c6854 streq r1, [r4] */
/* @0x1c6858 cmp r1, #0 */
/* @0x1c685c streq r3, [r4, #0x4] */
/* @0x1c6860 strne r3, [r1, #0x18] */
/* @0x1c6864 ldr r3, [r7, #0x18] */
/* @0x1c6868 ldr r1, [r7, #0x24] */
/* @0x1c686c str r1, [r2, #0x20] */
/* @0x1c6870 lsr r1, r3, #24 */
/* @0x1c6874 bic r3, r3, #-16777216 */
/* @0x1c6878 vmov s13, r1 */
/* @0x1c687c ldr r1, [r7, #0x20] */
/* @0x1c6880 str r0, [r2, #0x1c] */
/* @0x1c6884 vcvt.f32.s32 s13, s13 */
/* @0x1c6888 ldr r0, [r7, #0x1c] */
/* @0x1c688c str r0, [r2, #0x24] */
/* @0x1c6890 ldr r0, [r7, #0x10] */
/* @0x1c6894 str r1, [r2, #0x28] */
/* @0x1c6898 ldr r1, [r7, #0x14] */
/* @0x1c689c vdiv.f32 s13, s13, s19 */
/* @0x1c68a0 str r0, [r2, #0x2c] */
/* @0x1c68a4 ldr r0, [r7, #0x28] */
/* @0x1c68a8 str r1, [r2, #0x30] */
/* @0x1c68ac ldr r1, [r7] */
/* @0x1c68b0 vstr s14, [r2, #64] */
/* @0x1c68b4 str r3, [r2, #0x38] */
/* @0x1c68b8 vstr s15, [r2, #68] */
/* @0x1c68bc cmp r1, #0 */
/* @0x1c68c0 str r0, [r2, #0x34] */
/* @0x1c68c4 ldrne r3, [r11] */
/* @0x1c68c8 addne r1, r3, r1 */
/* @0x1c68cc mov r3, #0 */
/* @0x1c68d0 vstr s13, [r2, #60] */
/* @0x1c68d4 str r1, [r2, #0xc] */
/* @0x1c68d8 ldr r0, [sp, #0x4] */
/* @0x1c68dc ldr r1, [sp, #0x18] */
/* @0x1c68e0 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c68e4 ldr r2, [sp, #0x8] */
/* @0x1c68e8 cmp r9, r2 */
/* @0x1c68ec bne 0x1c672c <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x6bc> */
/* @0x1c68f0 ldr r7, [sp, #0x18] */
/* @0x1c68f4 ldr r10, [sp, #0x2c] */
/* @0x1c68f8 b 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c68fc ldr r4, [r11, #0x24] */
/* @0x1c6900 cmp r4, #0 */
/* @0x1c6904 str r4, [sp, #0x8] */
/* @0x1c6908 ble 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c690c ldr r8, [pc, #-0x494] */
/* @0x1c6910 mov r9, #0 */
/* @0x1c6914 ldr r3, [pc, #-0x498] */
/* @0x1c6918 add r11, r11, #36 */
/* @0x1c691c ldr r0, [sp, #0x10] */
/* @0x1c6920 add r8, pc, r8 */
/* @0x1c6924 mov r5, r9 */
/* @0x1c6928 mvn r6, #0 */
/* @0x1c692c ldr r4, [r0, r3] */
/* @0x1c6930 str r10, [sp, #0x18] */
/* @0x1c6934 ldr r12, [r4, #0x8] */
/* @0x1c6938 cmp r12, #0 */
/* @0x1c693c bne 0x1c69e4 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x974> */
/* @0x1c6940 ldr r3, [r4, #0x10] */
/* @0x1c6944 cmp r3, #0 */
/* @0x1c6948 ble 0x1c69dc <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x96c> */
/* @0x1c694c mov r10, r12 */
/* @0x1c6950 mov r3, #1 */
/* @0x1c6954 mov r0, #36 */
/* @0x1c6958 mov r1, r8 */
/* @0x1c695c mov r2, #63 */
/* @0x1c6960 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c6964 mov r3, #2 */
/* @0x1c6968 cmp r0, #0 */
/* @0x1c696c beq 0x1c6994 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x924> */
/* @0x1c6970 strb r5, [r0, #0x8] */
/* @0x1c6974 str r5, [r0, #0xc] */
/* @0x1c6978 str r5, [r0, #0x10] */
/* @0x1c697c str r5, [r0, #0x14] */
/* @0x1c6980 str r5, [r0, #0x18] */
/* @0x1c6984 str r6, [r0, #0x4] */
/* @0x1c6988 str r6, [r0, #0x1c] */
/* @0x1c698c str r5, [r0, #0x20] */
/* @0x1c6990 str r3, [r0] */
/* @0x1c6994 ldr r3, [r4] */
/* @0x1c6998 add r10, r10, #1 */
/* @0x1c699c ldr r2, [r4, #0x8] */
/* @0x1c69a0 cmp r3, #0 */
/* @0x1c69a4 streq r0, [r4, #0x4] */
/* @0x1c69a8 strne r0, [r3, #0x18] */
/* @0x1c69ac add r2, r2, #1 */
/* @0x1c69b0 streq r3, [r0, #0x18] */
/* @0x1c69b4 streq r3, [r0, #0x14] */
/* @0x1c69b8 strne r3, [r0, #0x14] */
/* @0x1c69bc ldr r3, [r4, #0x10] */
/* @0x1c69c0 streq r0, [r4] */
/* @0x1c69c4 strne r0, [r4] */
/* @0x1c69c8 strne r5, [r0, #0x18] */
/* @0x1c69cc cmp r10, r3 */
/* @0x1c69d0 str r2, [r4, #0x8] */
/* @0x1c69d4 blt 0x1c6950 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x8e0> */
/* @0x1c69d8 ldr r12, [r4, #0x8] */
/* @0x1c69dc lsl r3, r3, #1 */
/* @0x1c69e0 str r3, [r4, #0x10] */
/* @0x1c69e4 ldr r3, [r4] */
/* @0x1c69e8 sub r12, r12, #1 */
/* @0x1c69ec str r12, [r4, #0x8] */
/* @0x1c69f0 add r9, r9, #1 */
/* @0x1c69f4 ldr r12, [r11, #0x4]! */
/* @0x1c69f8 ldr r2, [r3, #0x18] */
/* @0x1c69fc ldr r1, [r3, #0x14] */
/* @0x1c6a00 cmp r2, #0 */
/* @0x1c6a04 ldr r0, [sp, #0x4] */
/* @0x1c6a08 strne r1, [r2, #0x14] */
/* @0x1c6a0c ldrne r1, [r3, #0x14] */
/* @0x1c6a10 ldrne r2, [r3, #0x18] */
/* @0x1c6a14 streq r1, [r4] */
/* @0x1c6a18 cmp r1, #0 */
/* @0x1c6a1c streq r2, [r4, #0x4] */
/* @0x1c6a20 strne r2, [r1, #0x18] */
/* @0x1c6a24 mov r2, r3 */
/* @0x1c6a28 mov r1, r7 */
/* @0x1c6a2c str r12, [r3, #0x1c] */
/* @0x1c6a30 mov r3, #0 */
/* @0x1c6a34 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c6a38 ldr r1, [sp, #0x8] */
/* @0x1c6a3c cmp r9, r1 */
/* @0x1c6a40 bne 0x1c6934 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x8c4> */
/* @0x1c6a44 ldr r10, [sp, #0x18] */
/* @0x1c6a48 ldr r0, [sp, #0x4] */
/* @0x1c6a4c mov r1, r7 */
/* @0x1c6a50 bl 0x1c30f8 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer> */
/* @0x1c6a54 ldr r4, [sp, #0x24] */
/* @0x1c6a58 ldr r3, [r7] */
/* @0x1c6a5c ldr r0, [r4] */
/* @0x1c6a60 ldr r4, [sp, #0xc] */
/* @0x1c6a64 cmp r0, r3 */
/* @0x1c6a68 movlt r0, r3 */
/* @0x1c6a6c add r4, r4, #1 */
/* @0x1c6a70 str r4, [sp, #0xc] */
/* @0x1c6a74 bl 0x1b79f0 <_ZN13CLayerManager22SetLayerIndexWatermarkEi> */
/* @0x1c6a78 ldr r0, [sp, #0x1c] */
/* @0x1c6a7c cmp r4, r0 */
/* @0x1c6a80 bne 0x1c6118 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa8> */
/* @0x1c6a84 add sp, sp, #60 */
/* @0x1c6a88 vpop {d8, d9} */
/* @0x1c6a8c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c6a90 ldr r3, [pc, #-0x610] */
/* @0x1c6a94 ldr r0, [sp, #0x10] */
/* @0x1c6a98 ldr r4, [r0, r3] */
/* @0x1c6a9c ldr r12, [r4, #0x8] */
/* @0x1c6aa0 cmp r12, #0 */
/* @0x1c6aa4 bne 0x1c6b58 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xae8> */
/* @0x1c6aa8 ldr r3, [r4, #0x10] */
/* @0x1c6aac cmp r3, #0 */
/* @0x1c6ab0 ble 0x1c6b50 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xae0> */
/* @0x1c6ab4 ldr r6, [pc, #-0x630] */
/* @0x1c6ab8 mov r8, r12 */
/* @0x1c6abc mov r5, r12 */
/* @0x1c6ac0 mov r9, #1 */
/* @0x1c6ac4 add r6, pc, r6 */
/* @0x1c6ac8 mov r3, #1 */
/* @0x1c6acc mov r0, #32 */
/* @0x1c6ad0 mov r1, r6 */
/* @0x1c6ad4 mov r2, #63 */
/* @0x1c6ad8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c6adc ldr r3, [r4] */
/* @0x1c6ae0 cmp r0, #0 */
/* @0x1c6ae4 beq 0x1c6b0c <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa9c> */
/* @0x1c6ae8 mvn r1, #0 */
/* @0x1c6aec strb r5, [r0, #0x8] */
/* @0x1c6af0 str r5, [r0, #0xc] */
/* @0x1c6af4 str r5, [r0, #0x10] */
/* @0x1c6af8 str r5, [r0, #0x14] */
/* @0x1c6afc str r5, [r0, #0x18] */
/* @0x1c6b00 str r1, [r0, #0x4] */
/* @0x1c6b04 str r5, [r0, #0x1c] */
/* @0x1c6b08 str r9, [r0] */
/* @0x1c6b0c cmp r3, #0 */
/* @0x1c6b10 strne r0, [r3, #0x18] */
/* @0x1c6b14 streq r3, [r0, #0x18] */
/* @0x1c6b18 add r8, r8, #1 */
/* @0x1c6b1c streq r3, [r0, #0x14] */
/* @0x1c6b20 strne r3, [r0, #0x14] */
/* @0x1c6b24 ldr r3, [r4, #0x10] */
/* @0x1c6b28 ldr r2, [r4, #0x8] */
/* @0x1c6b2c streq r0, [r4, #0x4] */
/* @0x1c6b30 streq r0, [r4] */
/* @0x1c6b34 add r2, r2, #1 */
/* @0x1c6b38 strne r0, [r4] */
/* @0x1c6b3c strne r5, [r0, #0x18] */
/* @0x1c6b40 cmp r8, r3 */
/* @0x1c6b44 str r2, [r4, #0x8] */
/* @0x1c6b48 blt 0x1c6ac8 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0xa58> */
/* @0x1c6b4c ldr r12, [r4, #0x8] */
/* @0x1c6b50 lsl r3, r3, #1 */
/* @0x1c6b54 str r3, [r4, #0x10] */
/* @0x1c6b58 ldr r5, [r4] */
/* @0x1c6b5c sub r12, r12, #1 */
/* @0x1c6b60 ldr r1, [pc, #-0x6d8] */
/* @0x1c6b64 mov r0, #44 */
/* @0x1c6b68 str r12, [r4, #0x8] */
/* @0x1c6b6c ldr r3, [r5, #0x18] */
/* @0x1c6b70 add r1, pc, r1 */
/* @0x1c6b74 ldr r2, [r5, #0x14] */
/* @0x1c6b78 cmp r3, #0 */
/* @0x1c6b7c strne r2, [r3, #0x14] */
/* @0x1c6b80 ldrne r2, [r5, #0x14] */
/* @0x1c6b84 ldrne r3, [r5, #0x18] */
/* @0x1c6b88 streq r2, [r4] */
/* @0x1c6b8c cmp r2, #0 */
/* @0x1c6b90 streq r3, [r4, #0x4] */
/* @0x1c6b94 strne r3, [r2, #0x18] */
/* @0x1c6b98 mov r2, #240 */
/* @0x1c6b9c mov r3, #1 */
/* @0x1c6ba0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c6ba4 ldr r3, [r11, #0x3c] */
/* @0x1c6ba8 ldr r1, [r11, #0x24] */
/* @0x1c6bac mov r12, #0 */
/* @0x1c6bb0 ldr r2, [r11, #0x28] */
/* @0x1c6bb4 mov lr, #1065353216 */
/* @0x1c6bb8 lsr r4, r3, #24 */
/* @0x1c6bbc subs r1, r1, r12 */
/* @0x1c6bc0 bic r3, r3, #-16777216 */
/* @0x1c6bc4 vmov s15, r4 */
/* @0x1c6bc8 movne r1, #1 */
/* @0x1c6bcc subs r2, r2, r12 */
/* @0x1c6bd0 vcvt.f32.s32 s15, s15 */
/* @0x1c6bd4 movne r2, #1 */
/* @0x1c6bd8 vdiv.f32 s15, s15, s19 */
/* @0x1c6bdc str r0, [r5, #0x1c] */
/* @0x1c6be0 strb r2, [r0, #0x1] */
/* @0x1c6be4 ldr r2, [r11, #0x2c] */
/* @0x1c6be8 strb r12, [r0, #0x14] */
/* @0x1c6bec ldr r12, [r11, #0x40] */
/* @0x1c6bf0 str r2, [r0, #0x4] */
/* @0x1c6bf4 ldr r2, [r11, #0x30] */
/* @0x1c6bf8 strb r1, [r0] */
/* @0x1c6bfc adds r2, r2, #0 */
/* @0x1c6c00 ldr r1, [r11, #0x34] */
/* @0x1c6c04 str r12, [r0, #0x20] */
/* @0x1c6c08 movne r2, #1 */
/* @0x1c6c0c ldr r12, [r11, #0x38] */
/* @0x1c6c10 adds r1, r1, #0 */
/* @0x1c6c14 str lr, [r0, #0xc] */
/* @0x1c6c18 str lr, [r0, #0x10] */
/* @0x1c6c1c str r3, [r0, #0x18] */
/* @0x1c6c20 movne r1, #1 */
/* @0x1c6c24 ldr r3, [r7, #0x1c] */
/* @0x1c6c28 cmp r12, #0 */
/* @0x1c6c2c ldr lr, [r11, #0x44] */
/* @0x1c6c30 strb r2, [r0, #0x8] */
/* @0x1c6c34 ldr r2, [r11, #0x48] */
/* @0x1c6c38 strb r1, [r0, #0x9] */
/* @0x1c6c3c mov r1, r7 */
/* @0x1c6c40 str lr, [r0, #0x24] */
/* @0x1c6c44 vstr s15, [r0, #28] */
/* @0x1c6c48 str r2, [r0, #0x28] */
/* @0x1c6c4c mov r2, r5 */
/* @0x1c6c50 str r3, [r5, #0xc] */
/* @0x1c6c54 movne r3, #1 */
/* @0x1c6c58 strbne r3, [r0, #0x14] */
/* @0x1c6c5c mov r3, #0 */
/* @0x1c6c60 ldr r0, [sp, #0x4] */
/* @0x1c6c64 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c6c68 b 0x1c6a48 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x9d8> */
/* @0x1c6c6c bl 0x1b6f00 <_ZN13CLayerManager4InitEv> */
/* @0x1c6c70 b 0x1c60b4 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x44> */

/* ── FUNC 0x1c6c74 · anon_1c6c74 · size=0 · insn=1 */
/* @0x1c6c74 nop */

/* ── FUNC 0x1c6c78 · CLayerManager::AddNewElementAtDepth(CRoom*, int, CLayerElementBase*, bool, bool) · size=124 · insn=31 */
/* @0x1c6c78 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c6c7c subs r6, r0, #0 */
/* @0x1c6c80 mov r5, r2 */
/* @0x1c6c84 mov r7, r3 */
/* @0x1c6c88 mov r8, r1 */
/* @0x1c6c8c ldrb r4, [sp, #0x18] */
/* @0x1c6c90 beq 0x1c6cec <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb+0x74> */
/* @0x1c6c94 cmp r2, #0 */
/* @0x1c6c98 beq 0x1c6cec <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb+0x74> */
/* @0x1c6c9c mov r2, r4 */
/* @0x1c6ca0 bl 0x1b87f4 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib> */
/* @0x1c6ca4 cmp r0, #0 */
/* @0x1c6ca8 movne r4, #0 */
/* @0x1c6cac andeq r4, r4, #1 */
/* @0x1c6cb0 mov r1, r0 */
/* @0x1c6cb4 cmp r4, #0 */
/* @0x1c6cb8 bne 0x1c6cd8 <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb+0x60> */
/* @0x1c6cbc cmp r1, #0 */
/* @0x1c6cc0 beq 0x1c6cec <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb+0x74> */
/* @0x1c6cc4 mov r0, r6 */
/* @0x1c6cc8 mov r2, r5 */
/* @0x1c6ccc mov r3, r7 */
/* @0x1c6cd0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c6cd4 b 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c6cd8 mov r1, r8 */
/* @0x1c6cdc mov r0, r6 */
/* @0x1c6ce0 bl 0x1c33e4 <_ZN13CLayerManager15AddDynamicLayerEP5CRoomi> */
/* @0x1c6ce4 mov r1, r0 */
/* @0x1c6ce8 b 0x1c6cbc <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb+0x44> */
/* @0x1c6cec mvn r0, #0 */
/* @0x1c6cf0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x1c6cf4 · F_LayerAddInstance(RValue&, CInstance*, CInstance*, int, RValue*) · size=432 · insn=108 */
/* @0x1c6cf4 cmp r3, #2 */
/* @0x1c6cf8 mov r3, #0 */
/* @0x1c6cfc push {r4, r5, r6, lr} */
/* @0x1c6d00 mov r4, r3 */
/* @0x1c6d04 ldr r6, [sp, #0x10] */
/* @0x1c6d08 movt r3, #0xbff0 */
/* @0x1c6d0c str r4, [r0, #0xc] */
/* @0x1c6d10 str r3, [r0, #0x4] */
/* @0x1c6d14 str r4, [r0] */
/* @0x1c6d18 beq 0x1c6d30 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1c6d1c ldr r0, [pc, #0x16c] */
/* @0x1c6d20 mov r1, r4 */
/* @0x1c6d24 pop {r4, r5, r6, lr} */
/* @0x1c6d28 add r0, pc, r0 */
/* @0x1c6d2c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c6d30 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c6d34 ldr r3, [r6, #0xc] */
/* @0x1c6d38 mov r1, r4 */
/* @0x1c6d3c bic r3, r3, #-16777216 */
/* @0x1c6d40 cmp r3, #1 */
/* @0x1c6d44 mov r5, r0 */
/* @0x1c6d48 mov r0, r6 */
/* @0x1c6d4c beq 0x1c6de0 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x1c6d50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c6d54 mov r1, r0 */
/* @0x1c6d58 mov r0, r5 */
/* @0x1c6d5c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c6d60 mov r4, r0 */
/* @0x1c6d64 cmp r4, #0 */
/* @0x1c6d68 beq 0x1c6e7c <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x1c6d6c ldr r3, [pc, #0x120] */
/* @0x1c6d70 mov r0, r6 */
/* @0x1c6d74 mov r1, #1 */
/* @0x1c6d78 ldr r3, [pc, r3] */
/* @0x1c6d7c ldr r3, [r3] */
/* @0x1c6d80 cmp r5, r3 */
/* @0x1c6d84 beq 0x1c6df8 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x1c6d88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c6d8c mov r6, r0 */
/* @0x1c6d90 mov r0, r5 */
/* @0x1c6d94 mov r1, r6 */
/* @0x1c6d98 bl 0x1b8cb8 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi> */
/* @0x1c6d9c cmn r0, #1 */
/* @0x1c6da0 beq 0x1c6dc0 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x1c6da4 mov r1, r0 */
/* @0x1c6da8 mov r0, r5 */
/* @0x1c6dac bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c6db0 mov r2, r6 */
/* @0x1c6db4 mov r1, r0 */
/* @0x1c6db8 mov r0, r5 */
/* @0x1c6dbc bl 0x1b9ea4 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri> */
/* @0x1c6dc0 bl 0x1c0cdc <_ZN13CLayerManager21GetNewInstanceElementEv> */
/* @0x1c6dc4 mov r1, r4 */
/* @0x1c6dc8 mov r3, #0 */
/* @0x1c6dcc str r6, [r0, #0x1c] */
/* @0x1c6dd0 mov r2, r0 */
/* @0x1c6dd4 mov r0, r5 */
/* @0x1c6dd8 pop {r4, r5, r6, lr} */
/* @0x1c6ddc b 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c6de0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c6de4 mov r1, r0 */
/* @0x1c6de8 mov r0, r5 */
/* @0x1c6dec bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c6df0 mov r4, r0 */
/* @0x1c6df4 b 0x1c6d64 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1c6df8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c6dfc cmp r0, #0 */
/* @0x1c6e00 blt 0x1c6e24 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x1c6e04 ldr r3, [pc, #0x8c] */
/* @0x1c6e08 ldr r3, [pc, r3] */
/* @0x1c6e0c ldr r2, [r3, #0x4] */
/* @0x1c6e10 ldr r3, [r3] */
/* @0x1c6e14 and r2, r0, r2 */
/* @0x1c6e18 ldr r3, [r3, r2, lsl #3] */
/* @0x1c6e1c cmp r3, #0 */
/* @0x1c6e20 bne 0x1c6e44 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x1c6e24 ldr r0, [pc, #0x70] */
/* @0x1c6e28 mov r1, #0 */
/* @0x1c6e2c pop {r4, r5, r6, lr} */
/* @0x1c6e30 add r0, pc, r0 */
/* @0x1c6e34 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c6e38 ldr r3, [r3, #0x4] */
/* @0x1c6e3c cmp r3, #0 */
/* @0x1c6e40 beq 0x1c6e24 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x1c6e44 ldr r2, [r3, #0x8] */
/* @0x1c6e48 cmp r0, r2 */
/* @0x1c6e4c bne 0x1c6e38 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x1c6e50 ldr r6, [r3, #0xc] */
/* @0x1c6e54 cmp r6, #0 */
/* @0x1c6e58 beq 0x1c6e24 <_Z18F_LayerAddInstanceR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x1c6e5c mov r0, r5 */
/* @0x1c6e60 mov r1, r6 */
/* @0x1c6e64 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> */
/* @0x1c6e68 mov r0, r5 */
/* @0x1c6e6c mov r1, r4 */
/* @0x1c6e70 mov r2, r6 */
/* @0x1c6e74 pop {r4, r5, r6, lr} */
/* @0x1c6e78 b 0x1c5a38 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance> */
/* @0x1c6e7c ldr r0, [pc, #0x1c] */
/* @0x1c6e80 mov r1, r4 */
/* @0x1c6e84 pop {r4, r5, r6, lr} */
/* @0x1c6e88 add r0, pc, r0 */
/* @0x1c6e8c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c6e90 andseq r9, r8, r12, ror #22 */
/* @0x1c6e94 .word 0x00226bb0 */
/* @0x1c6e98 eoreq r6, r2, r12, lsr lr */
/* @0x1c6e9c andseq r9, r8, r0, ror #21 */
/* @0x1c6ea0 andseq r9, r8, r0, asr #20 */

/* ── FUNC 0x1c6ea4 · F_LayerBackgroundCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=436 · insn=109 */
/* @0x1c6ea4 cmp r3, #2 */
/* @0x1c6ea8 mov r3, #0 */
/* @0x1c6eac push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1c6eb0 mov r4, r3 */
/* @0x1c6eb4 mov r5, r0 */
/* @0x1c6eb8 movt r3, #0xbff0 */
/* @0x1c6ebc str r4, [r0, #0xc] */
/* @0x1c6ec0 str r3, [r0, #0x4] */
/* @0x1c6ec4 str r4, [r0] */
/* @0x1c6ec8 ldr r6, [sp, #0x20] */
/* @0x1c6ecc beq 0x1c6ee4 <_Z23F_LayerBackgroundCreateR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1c6ed0 ldr r0, [pc, #0x16c] */
/* @0x1c6ed4 mov r1, r4 */
/* @0x1c6ed8 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1c6edc add r0, pc, r0 */
/* @0x1c6ee0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c6ee4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c6ee8 ldr r3, [r6, #0xc] */
/* @0x1c6eec mov r1, r4 */
/* @0x1c6ef0 bic r3, r3, #-16777216 */
/* @0x1c6ef4 cmp r3, #1 */
/* @0x1c6ef8 mov r8, r0 */
/* @0x1c6efc mov r0, r6 */
/* @0x1c6f00 beq 0x1c7004 <_Z23F_LayerBackgroundCreateR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x1c6f04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c6f08 mov r1, r0 */
/* @0x1c6f0c mov r0, r8 */
/* @0x1c6f10 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c6f14 mov r9, r0 */
/* @0x1c6f18 cmp r9, #0 */
/* @0x1c6f1c beq 0x1c701c <_Z23F_LayerBackgroundCreateR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x1c6f20 bl 0x1c0bd8 <_ZN13CLayerManager23GetNewBackgroundElementEv> */
/* @0x1c6f24 ldr r1, [pc, #0x11c] */
/* @0x1c6f28 movw r2, #0xe61 */
/* @0x1c6f2c mov r3, #1 */
/* @0x1c6f30 add r1, pc, r1 */
/* @0x1c6f34 mov r7, r0 */
/* @0x1c6f38 mov r0, #44 */
/* @0x1c6f3c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c6f40 subs r4, r0, #0 */
/* @0x1c6f44 beq 0x1c6f70 <_Z23F_LayerBackgroundCreateR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x1c6f48 mov r3, #0 */
/* @0x1c6f4c mov r2, #0 */
/* @0x1c6f50 str r3, [r4, #0x4] */
/* @0x1c6f54 str r2, [r4, #0x1c] */
/* @0x1c6f58 strb r3, [r4, #0x8] */
/* @0x1c6f5c str r2, [r4, #0x20] */
/* @0x1c6f60 strb r3, [r4, #0x9] */
/* @0x1c6f64 str r2, [r4, #0x24] */
/* @0x1c6f68 str r3, [r4, #0x18] */
/* @0x1c6f6c str r3, [r4, #0x28] */
/* @0x1c6f70 str r4, [r7, #0x1c] */
/* @0x1c6f74 mov r10, #1065353216 */
/* @0x1c6f78 mov r1, #1 */
/* @0x1c6f7c mov r0, r6 */
/* @0x1c6f80 strb r1, [r4] */
/* @0x1c6f84 mov r6, #0 */
/* @0x1c6f88 str r10, [r4, #0xc] */
/* @0x1c6f8c strb r6, [r4, #0x14] */
/* @0x1c6f90 strb r6, [r4, #0x1] */
/* @0x1c6f94 str r10, [r4, #0x10] */
/* @0x1c6f98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c6f9c ldr r3, [pc, #0xa8] */
/* @0x1c6fa0 ldr r12, [r7, #0x1c] */
/* @0x1c6fa4 mov r1, r9 */
/* @0x1c6fa8 ldr r3, [pc, r3] */
/* @0x1c6fac mvn lr, #0 */
/* @0x1c6fb0 mov r2, r7 */
/* @0x1c6fb4 mov r9, #0 */
/* @0x1c6fb8 ldr r3, [r3] */
/* @0x1c6fbc cmp r3, r8 */
/* @0x1c6fc0 movne r3, #0 */
/* @0x1c6fc4 moveq r3, #1 */
/* @0x1c6fc8 str r0, [r4, #0x4] */
/* @0x1c6fcc mov r0, r8 */
/* @0x1c6fd0 strb r6, [r12, #0x8] */
/* @0x1c6fd4 strb r6, [r12, #0x9] */
/* @0x1c6fd8 str r10, [r12, #0x1c] */
/* @0x1c6fdc str r10, [r12, #0x24] */
/* @0x1c6fe0 str lr, [r12, #0x18] */
/* @0x1c6fe4 str r9, [r12, #0x20] */
/* @0x1c6fe8 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c6fec ldr r2, [r7, #0x4] */
/* @0x1c6ff0 vmov s15, r2 */
/* @0x1c6ff4 vcvt.f64.s32 d7, s15 */
/* @0x1c6ff8 vmov r2, r3, d7 */
/* @0x1c6ffc stm r5, {r2, r3} */
/* @0x1c7000 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1c7004 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c7008 mov r1, r0 */
/* @0x1c700c mov r0, r8 */
/* @0x1c7010 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c7014 mov r9, r0 */
/* @0x1c7018 b 0x1c6f18 <_Z23F_LayerBackgroundCreateR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1c701c ldr r3, [pc, #0x2c] */
/* @0x1c7020 mov r2, r9 */
/* @0x1c7024 ldr r1, [pc, #0x28] */
/* @0x1c7028 ldr r3, [pc, r3] */
/* @0x1c702c add r1, pc, r1 */
/* @0x1c7030 ldr r0, [r3] */
/* @0x1c7034 ldr r3, [r0] */
/* @0x1c7038 ldr r3, [r3, #0xc] */
/* @0x1c703c blx r3 */
/* @0x1c7040 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1c7044 andseq r9, r8, r0, ror r10 */
/* @0x1c7048 andseq r6, r8, r12, lsr r8 */
/* @0x1c704c eoreq r6, r2, r0, lsl #19 */
/* @0x1c7050 eoreq r6, r2, r12, ror #13 */
/* @0x1c7054 andseq r9, r8, r8, asr r9 */

/* ── FUNC 0x1c7058 · F_LayerSpriteCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=324 · insn=81 */
/* @0x1c7058 cmp r3, #4 */
/* @0x1c705c mov r3, #0 */
/* @0x1c7060 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c7064 mov r5, r3 */
/* @0x1c7068 mov r4, r0 */
/* @0x1c706c movt r3, #0xbff0 */
/* @0x1c7070 str r5, [r0, #0xc] */
/* @0x1c7074 str r3, [r0, #0x4] */
/* @0x1c7078 str r5, [r0] */
/* @0x1c707c ldr r6, [sp, #0x18] */
/* @0x1c7080 beq 0x1c7098 <_Z19F_LayerSpriteCreateR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1c7084 ldr r0, [pc, #0x100] */
/* @0x1c7088 mov r1, r5 */
/* @0x1c708c pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c7090 add r0, pc, r0 */
/* @0x1c7094 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c7098 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c709c ldr r3, [r6, #0xc] */
/* @0x1c70a0 mov r1, r5 */
/* @0x1c70a4 bic r3, r3, #-16777216 */
/* @0x1c70a8 cmp r3, #1 */
/* @0x1c70ac mov r8, r0 */
/* @0x1c70b0 mov r0, r6 */
/* @0x1c70b4 beq 0x1c714c <_Z19F_LayerSpriteCreateR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x1c70b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c70bc mov r1, r0 */
/* @0x1c70c0 mov r0, r8 */
/* @0x1c70c4 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c70c8 mov r7, r0 */
/* @0x1c70cc cmp r7, #0 */
/* @0x1c70d0 beq 0x1c7164 <_Z19F_LayerSpriteCreateR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x1c70d4 bl 0x1c0f00 <_ZN13CLayerManager19GetNewSpriteElementEv> */
/* @0x1c70d8 mov r1, #3 */
/* @0x1c70dc mov r5, r0 */
/* @0x1c70e0 mov r0, r6 */
/* @0x1c70e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c70e8 mov r1, #1 */
/* @0x1c70ec str r0, [r5, #0x1c] */
/* @0x1c70f0 mov r0, r6 */
/* @0x1c70f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c70f8 mov r1, #2 */
/* @0x1c70fc str r0, [r5, #0x40] */
/* @0x1c7100 mov r0, r6 */
/* @0x1c7104 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7108 ldr r3, [pc, #0x80] */
/* @0x1c710c mov r2, r5 */
/* @0x1c7110 mov r1, r7 */
/* @0x1c7114 ldr r3, [pc, r3] */
/* @0x1c7118 ldr r3, [r3] */
/* @0x1c711c subs r12, r3, r8 */
/* @0x1c7120 rsbs r3, r12, #0 */
/* @0x1c7124 adcs r3, r3, r12 */
/* @0x1c7128 str r0, [r5, #0x44] */
/* @0x1c712c mov r0, r8 */
/* @0x1c7130 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c7134 ldr r2, [r5, #0x4] */
/* @0x1c7138 vmov s15, r2 */
/* @0x1c713c vcvt.f64.s32 d7, s15 */
/* @0x1c7140 vmov r2, r3, d7 */
/* @0x1c7144 stm r4, {r2, r3} */
/* @0x1c7148 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c714c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c7150 mov r1, r0 */
/* @0x1c7154 mov r0, r8 */
/* @0x1c7158 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c715c mov r7, r0 */
/* @0x1c7160 b 0x1c70cc <_Z19F_LayerSpriteCreateR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1c7164 ldr r3, [pc, #0x28] */
/* @0x1c7168 mov r2, r7 */
/* @0x1c716c ldr r1, [pc, #0x24] */
/* @0x1c7170 ldr r3, [pc, r3] */
/* @0x1c7174 add r1, pc, r1 */
/* @0x1c7178 ldr r0, [r3] */
/* @0x1c717c ldr r3, [r0] */
/* @0x1c7180 ldr r3, [r3, #0xc] */
/* @0x1c7184 blx r3 */
/* @0x1c7188 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c718c andseq r9, r8, r0, asr #18 */
/* @0x1c7190 eoreq r6, r2, r4, lsl r8 */
/* @0x1c7194 eoreq r6, r2, r4, lsr #11 */
/* @0x1c7198 mulseq r8, r0, r8 */

/* ── FUNC 0x1c719c · F_LayerTilemapCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=420 · insn=105 */
/* @0x1c719c cmp r3, #6 */
/* @0x1c71a0 mov r3, #0 */
/* @0x1c71a4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c71a8 mov r5, r3 */
/* @0x1c71ac mov r4, r0 */
/* @0x1c71b0 movt r3, #0xbff0 */
/* @0x1c71b4 str r5, [r0, #0xc] */
/* @0x1c71b8 str r3, [r0, #0x4] */
/* @0x1c71bc str r5, [r0] */
/* @0x1c71c0 ldr r6, [sp, #0x18] */
/* @0x1c71c4 beq 0x1c71dc <_Z20F_LayerTilemapCreateR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1c71c8 ldr r0, [pc, #0x15c] */
/* @0x1c71cc mov r1, r5 */
/* @0x1c71d0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c71d4 add r0, pc, r0 */
/* @0x1c71d8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c71dc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c71e0 ldr r3, [r6, #0xc] */
/* @0x1c71e4 mov r1, r5 */
/* @0x1c71e8 bic r3, r3, #-16777216 */
/* @0x1c71ec cmp r3, #1 */
/* @0x1c71f0 mov r8, r0 */
/* @0x1c71f4 mov r0, r6 */
/* @0x1c71f8 beq 0x1c72ec <_Z20F_LayerTilemapCreateR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x1c71fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7200 mov r1, r0 */
/* @0x1c7204 mov r0, r8 */
/* @0x1c7208 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c720c mov r7, r0 */
/* @0x1c7210 cmp r7, #0 */
/* @0x1c7214 beq 0x1c7304 <_Z20F_LayerTilemapCreateR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1c7218 bl 0x1c1034 <_ZN13CLayerManager20GetNewTilemapElementEv> */
/* @0x1c721c mov r1, #3 */
/* @0x1c7220 mov r5, r0 */
/* @0x1c7224 mov r0, r6 */
/* @0x1c7228 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c722c mov r1, #1 */
/* @0x1c7230 str r0, [r5, #0x1c] */
/* @0x1c7234 mov r0, r6 */
/* @0x1c7238 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c723c mov r1, #2 */
/* @0x1c7240 str r0, [r5, #0x20] */
/* @0x1c7244 mov r0, r6 */
/* @0x1c7248 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c724c mov r1, #4 */
/* @0x1c7250 str r0, [r5, #0x24] */
/* @0x1c7254 mov r0, r6 */
/* @0x1c7258 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c725c mov r1, #5 */
/* @0x1c7260 str r0, [r5, #0x28] */
/* @0x1c7264 mov r0, r6 */
/* @0x1c7268 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c726c ldr r12, [r5, #0x28] */
/* @0x1c7270 ldr r1, [pc, #0xb8] */
/* @0x1c7274 movw r2, #0x105c */
/* @0x1c7278 mov r3, #1 */
/* @0x1c727c add r1, pc, r1 */
/* @0x1c7280 str r0, [r5, #0x2c] */
/* @0x1c7284 mul r0, r12, r0 */
/* @0x1c7288 lsl r0, r0, #2 */
/* @0x1c728c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c7290 ldr r3, [r5, #0x28] */
/* @0x1c7294 ldr r2, [r5, #0x2c] */
/* @0x1c7298 mov r1, #0 */
/* @0x1c729c mul r2, r2, r3 */
/* @0x1c72a0 lsl r2, r2, #2 */
/* @0x1c72a4 str r0, [r5, #0x34] */
/* @0x1c72a8 bl 0xb65b0 <memset@plt> */
/* @0x1c72ac ldr r3, [pc, #0x80] */
/* @0x1c72b0 mov r2, r5 */
/* @0x1c72b4 mov r0, r8 */
/* @0x1c72b8 ldr r3, [pc, r3] */
/* @0x1c72bc mov r1, r7 */
/* @0x1c72c0 ldr r3, [r3] */
/* @0x1c72c4 subs r12, r3, r8 */
/* @0x1c72c8 rsbs r3, r12, #0 */
/* @0x1c72cc adcs r3, r3, r12 */
/* @0x1c72d0 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c72d4 ldr r2, [r5, #0x4] */
/* @0x1c72d8 vmov s15, r2 */
/* @0x1c72dc vcvt.f64.s32 d7, s15 */
/* @0x1c72e0 vmov r2, r3, d7 */
/* @0x1c72e4 stm r4, {r2, r3} */
/* @0x1c72e8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c72ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c72f0 mov r1, r0 */
/* @0x1c72f4 mov r0, r8 */
/* @0x1c72f8 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c72fc mov r7, r0 */
/* @0x1c7300 b 0x1c7210 <_Z20F_LayerTilemapCreateR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1c7304 ldr r3, [pc, #0x2c] */
/* @0x1c7308 mov r2, r7 */
/* @0x1c730c ldr r1, [pc, #0x28] */
/* @0x1c7310 ldr r3, [pc, r3] */
/* @0x1c7314 add r1, pc, r1 */
/* @0x1c7318 ldr r0, [r3] */
/* @0x1c731c ldr r3, [r0] */
/* @0x1c7320 ldr r3, [r3, #0xc] */
/* @0x1c7324 blx r3 */
/* @0x1c7328 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c732c andseq r9, r8, r8, ror r8 */
/* @0x1c7330 ldrsheq r6, [r8], -r0 */
/* @0x1c7334 eoreq r6, r2, r0, ror r6 */
/* @0x1c7338 eoreq r6, r2, r4, lsl #8 */
/* @0x1c733c andseq r9, r8, r12, ror #14 */

/* ── FUNC 0x1c7340 · F_LayerTileCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=396 · insn=99 */
/* @0x1c7340 cmp r3, #8 */
/* @0x1c7344 mov r3, #0 */
/* @0x1c7348 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c734c mov r6, r3 */
/* @0x1c7350 mov r4, r0 */
/* @0x1c7354 movt r3, #0xbff0 */
/* @0x1c7358 str r6, [r0, #0xc] */
/* @0x1c735c str r3, [r0, #0x4] */
/* @0x1c7360 str r6, [r0] */
/* @0x1c7364 ldr r5, [sp, #0x18] */
/* @0x1c7368 beq 0x1c7380 <_Z17F_LayerTileCreateR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1c736c ldr r0, [pc, #0x148] */
/* @0x1c7370 mov r1, r6 */
/* @0x1c7374 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c7378 add r0, pc, r0 */
/* @0x1c737c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1c7380 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1c7384 ldr r3, [r5, #0xc] */
/* @0x1c7388 mov r1, r6 */
/* @0x1c738c bic r3, r3, #-16777216 */
/* @0x1c7390 cmp r3, #1 */
/* @0x1c7394 mov r8, r0 */
/* @0x1c7398 mov r0, r5 */
/* @0x1c739c beq 0x1c747c <_Z17F_LayerTileCreateR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x1c73a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c73a4 mov r1, r0 */
/* @0x1c73a8 mov r0, r8 */
/* @0x1c73ac bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c73b0 mov r7, r0 */
/* @0x1c73b4 cmp r7, #0 */
/* @0x1c73b8 beq 0x1c7494 <_Z17F_LayerTileCreateR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x1c73bc bl 0x1c1260 <_ZN13CLayerManager17GetNewTileElementEv> */
/* @0x1c73c0 mov r1, #3 */
/* @0x1c73c4 mov r6, r0 */
/* @0x1c73c8 mov r0, r5 */
/* @0x1c73cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c73d0 mov r1, #1 */
/* @0x1c73d4 str r0, [r6, #0x20] */
/* @0x1c73d8 mov r0, r5 */
/* @0x1c73dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c73e0 mov r1, #2 */
/* @0x1c73e4 str r0, [r6, #0x24] */
/* @0x1c73e8 mov r0, r5 */
/* @0x1c73ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c73f0 mov r1, #4 */
/* @0x1c73f4 str r0, [r6, #0x28] */
/* @0x1c73f8 mov r0, r5 */
/* @0x1c73fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7400 mov r1, #5 */
/* @0x1c7404 str r0, [r6, #0x48] */
/* @0x1c7408 mov r0, r5 */
/* @0x1c740c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7410 mov r1, #6 */
/* @0x1c7414 str r0, [r6, #0x4c] */
/* @0x1c7418 mov r0, r5 */
/* @0x1c741c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7420 mov r1, #7 */
/* @0x1c7424 str r0, [r6, #0x2c] */
/* @0x1c7428 mov r0, r5 */
/* @0x1c742c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7430 ldr r3, [pc, #0x88] */
/* @0x1c7434 mov r2, #1 */
/* @0x1c7438 mov r1, r7 */
/* @0x1c743c ldr r3, [pc, r3] */
/* @0x1c7440 strb r2, [r6, #0x1c] */
/* @0x1c7444 mov r2, r6 */
/* @0x1c7448 ldr r3, [r3] */
/* @0x1c744c subs r12, r3, r8 */
/* @0x1c7450 rsbs r3, r12, #0 */
/* @0x1c7454 adcs r3, r3, r12 */
/* @0x1c7458 str r0, [r6, #0x30] */
/* @0x1c745c mov r0, r8 */
/* @0x1c7460 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c7464 ldr r2, [r6, #0x4] */
/* @0x1c7468 vmov s15, r2 */
/* @0x1c746c vcvt.f64.s32 d7, s15 */
/* @0x1c7470 vmov r2, r3, d7 */
/* @0x1c7474 stm r4, {r2, r3} */
/* @0x1c7478 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c747c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1c7480 mov r1, r0 */
/* @0x1c7484 mov r0, r8 */
/* @0x1c7488 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c748c mov r7, r0 */
/* @0x1c7490 b 0x1c73b4 <_Z17F_LayerTileCreateR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1c7494 ldr r3, [pc, #0x28] */
/* @0x1c7498 mov r2, r7 */
/* @0x1c749c ldr r1, [pc, #0x24] */
/* @0x1c74a0 ldr r3, [pc, r3] */
/* @0x1c74a4 add r1, pc, r1 */
/* @0x1c74a8 ldr r0, [r3] */
/* @0x1c74ac ldr r3, [r0] */
/* @0x1c74b0 ldr r3, [r3, #0xc] */
/* @0x1c74b4 blx r3 */
/* @0x1c74b8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c74bc andseq r9, r8, r4, asr r7 */
/* @0x1c74c0 eoreq r6, r2, r12, ror #9 */
/* @0x1c74c4 eoreq r6, r2, r4, ror r2 */
/* @0x1c74c8 andseq r9, r8, r8, asr r6 */

/* ── FUNC 0x1c74cc · anon_1c74cc · size=0 · insn=1 */
/* @0x1c74cc andeq r0, r0, r0 */

/* ── FUNC 0x1c74d0 · CLayerManager::DeSerializeLayer(CRoom*, IBuffer*) · size=3760 · insn=937 */
/* @0x1c74d0 ldr r12, [pc, #0x424] */
/* @0x1c74d4 ldr r3, [pc, #0x424] */
/* @0x1c74d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c74dc vpush {d8, d9} */
/* @0x1c74e0 add r12, pc, r12 */
/* @0x1c74e4 sub sp, sp, #36 */
/* @0x1c74e8 mov r6, r1 */
/* @0x1c74ec str r12, [sp, #0x1c] */
/* @0x1c74f0 str r0, [sp, #0xc] */
/* @0x1c74f4 ldr r8, [r12, r3] */
/* @0x1c74f8 ldr r10, [r8, #0x8] */
/* @0x1c74fc cmp r10, #0 */
/* @0x1c7500 bne 0x1c75f0 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x120> */
/* @0x1c7504 ldr r3, [r8, #0x10] */
/* @0x1c7508 cmp r3, #0 */
/* @0x1c750c ble 0x1c75e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x118> */
/* @0x1c7510 ldr r9, [pc, #0x3ec] */
/* @0x1c7514 mov r7, #1 */
/* @0x1c7518 vldr s16, [pc, #984] */
/* @0x1c751c vldr d9, [pc, #972] */
/* @0x1c7520 add r9, pc, r9 */
/* @0x1c7524 mov r3, #1 */
/* @0x1c7528 mov r0, #112 */
/* @0x1c752c mov r1, r9 */
/* @0x1c7530 mov r2, #63 */
/* @0x1c7534 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c7538 mov r5, #0 */
/* @0x1c753c mvn r3, #0 */
/* @0x1c7540 subs r4, r0, #0 */
/* @0x1c7544 add r0, r4, #48 */
/* @0x1c7548 beq 0x1c759c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xcc> */
/* @0x1c754c str r3, [r4] */
/* @0x1c7550 vstr s16, [r4, #8] */
/* @0x1c7554 str r5, [r4, #0x4] */
/* @0x1c7558 vstr s16, [r4, #12] */
/* @0x1c755c vstr s16, [r4, #16] */
/* @0x1c7560 vstr s16, [r4, #20] */
/* @0x1c7564 strb r7, [r4, #0x18] */
/* @0x1c7568 vstr d9, [r4, #72] */
/* @0x1c756c strb r5, [r4, #0x19] */
/* @0x1c7570 str r5, [r4, #0x1c] */
/* @0x1c7574 str r3, [r4, #0x20] */
/* @0x1c7578 str r3, [r4, #0x24] */
/* @0x1c757c str r3, [r4, #0x28] */
/* @0x1c7580 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1c7584 str r5, [r4, #0x5c] */
/* @0x1c7588 str r5, [r4, #0x58] */
/* @0x1c758c str r5, [r4, #0x60] */
/* @0x1c7590 str r7, [r4, #0x64] */
/* @0x1c7594 str r5, [r4, #0x68] */
/* @0x1c7598 str r5, [r4, #0x6c] */
/* @0x1c759c ldr r3, [r8] */
/* @0x1c75a0 mov r1, #0 */
/* @0x1c75a4 add r10, r10, #1 */
/* @0x1c75a8 ldr r2, [r8, #0x8] */
/* @0x1c75ac cmp r3, r1 */
/* @0x1c75b0 streq r4, [r8, #0x4] */
/* @0x1c75b4 strne r4, [r3, #0x6c] */
/* @0x1c75b8 add r2, r2, #1 */
/* @0x1c75bc streq r3, [r4, #0x6c] */
/* @0x1c75c0 streq r3, [r4, #0x68] */
/* @0x1c75c4 strne r3, [r4, #0x68] */
/* @0x1c75c8 ldr r3, [r8, #0x10] */
/* @0x1c75cc streq r4, [r8] */
/* @0x1c75d0 strne r4, [r8] */
/* @0x1c75d4 strne r1, [r4, #0x6c] */
/* @0x1c75d8 cmp r10, r3 */
/* @0x1c75dc str r2, [r8, #0x8] */
/* @0x1c75e0 blt 0x1c7524 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x54> */
/* @0x1c75e4 ldr r10, [r8, #0x8] */
/* @0x1c75e8 lsl r3, r3, #1 */
/* @0x1c75ec str r3, [r8, #0x10] */
/* @0x1c75f0 ldr r12, [r8] */
/* @0x1c75f4 add r7, r6, #44 */
/* @0x1c75f8 sub r10, r10, #1 */
/* @0x1c75fc mov r1, #6 */
/* @0x1c7600 mov r0, r6 */
/* @0x1c7604 ldr r3, [r12, #0x6c] */
/* @0x1c7608 str r12, [sp, #0x4] */
/* @0x1c760c cmp r3, #0 */
/* @0x1c7610 ldrne r12, [sp, #0x4] */
/* @0x1c7614 ldreq r2, [r12, #0x68] */
/* @0x1c7618 ldrne r2, [r12, #0x68] */
/* @0x1c761c streq r2, [r8] */
/* @0x1c7620 strne r2, [r3, #0x68] */
/* @0x1c7624 ldrne r2, [r12, #0x68] */
/* @0x1c7628 ldrne r3, [r12, #0x6c] */
/* @0x1c762c cmp r2, #0 */
/* @0x1c7630 streq r3, [r8, #0x4] */
/* @0x1c7634 strne r3, [r2, #0x6c] */
/* @0x1c7638 mov r2, r7 */
/* @0x1c763c ldr r3, [r6] */
/* @0x1c7640 str r10, [r8, #0x8] */
/* @0x1c7644 ldr r3, [r3, #0xc] */
/* @0x1c7648 blx r3 */
/* @0x1c764c mov r1, #0 */
/* @0x1c7650 mov r0, r7 */
/* @0x1c7654 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7658 ldr r12, [sp, #0x4] */
/* @0x1c765c str r0, [r12] */
/* @0x1c7660 mov r0, r6 */
/* @0x1c7664 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* @0x1c7668 ldr r12, [sp, #0x4] */
/* @0x1c766c ldr r3, [r6] */
/* @0x1c7670 mov r2, r7 */
/* @0x1c7674 mov r1, #6 */
/* @0x1c7678 str r0, [r12, #0x1c] */
/* @0x1c767c mov r0, r6 */
/* @0x1c7680 ldr r3, [r3, #0xc] */
/* @0x1c7684 blx r3 */
/* @0x1c7688 mov r1, #0 */
/* @0x1c768c mov r0, r7 */
/* @0x1c7690 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7694 ldr r12, [sp, #0x4] */
/* @0x1c7698 ldr r3, [r6] */
/* @0x1c769c mov r2, r7 */
/* @0x1c76a0 mov r1, #8 */
/* @0x1c76a4 ldr r3, [r3, #0xc] */
/* @0x1c76a8 str r0, [r12, #0x4] */
/* @0x1c76ac mov r0, r6 */
/* @0x1c76b0 blx r3 */
/* @0x1c76b4 mov r1, #0 */
/* @0x1c76b8 mov r0, r7 */
/* @0x1c76bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c76c0 ldr r12, [sp, #0x4] */
/* @0x1c76c4 ldr r3, [r6] */
/* @0x1c76c8 mov r2, r7 */
/* @0x1c76cc mov r1, #8 */
/* @0x1c76d0 ldr r3, [r3, #0xc] */
/* @0x1c76d4 str r0, [r12, #0x8] */
/* @0x1c76d8 mov r0, r6 */
/* @0x1c76dc blx r3 */
/* @0x1c76e0 mov r1, #0 */
/* @0x1c76e4 mov r0, r7 */
/* @0x1c76e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c76ec ldr r12, [sp, #0x4] */
/* @0x1c76f0 ldr r3, [r6] */
/* @0x1c76f4 mov r2, r7 */
/* @0x1c76f8 mov r1, #8 */
/* @0x1c76fc ldr r3, [r3, #0xc] */
/* @0x1c7700 str r0, [r12, #0xc] */
/* @0x1c7704 mov r0, r6 */
/* @0x1c7708 blx r3 */
/* @0x1c770c mov r1, #0 */
/* @0x1c7710 mov r0, r7 */
/* @0x1c7714 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7718 ldr r12, [sp, #0x4] */
/* @0x1c771c ldr r3, [r6] */
/* @0x1c7720 mov r2, r7 */
/* @0x1c7724 mov r1, #8 */
/* @0x1c7728 ldr r3, [r3, #0xc] */
/* @0x1c772c str r0, [r12, #0x10] */
/* @0x1c7730 mov r0, r6 */
/* @0x1c7734 blx r3 */
/* @0x1c7738 mov r1, #0 */
/* @0x1c773c mov r0, r7 */
/* @0x1c7740 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7744 ldr r12, [sp, #0x4] */
/* @0x1c7748 ldr r3, [r6] */
/* @0x1c774c mov r2, r7 */
/* @0x1c7750 mov r1, #6 */
/* @0x1c7754 ldr r3, [r3, #0xc] */
/* @0x1c7758 str r0, [r12, #0x14] */
/* @0x1c775c mov r0, r6 */
/* @0x1c7760 blx r3 */
/* @0x1c7764 mov r1, #0 */
/* @0x1c7768 mov r0, r7 */
/* @0x1c776c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c7770 ldr r12, [sp, #0x4] */
/* @0x1c7774 ldr r3, [r6] */
/* @0x1c7778 mov r2, r7 */
/* @0x1c777c mov r1, #6 */
/* @0x1c7780 ldr r3, [r3, #0xc] */
/* @0x1c7784 strb r0, [r12, #0x18] */
/* @0x1c7788 mov r0, r6 */
/* @0x1c778c blx r3 */
/* @0x1c7790 mov r1, #0 */
/* @0x1c7794 mov r0, r7 */
/* @0x1c7798 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c779c ldr r12, [sp, #0x4] */
/* @0x1c77a0 ldr r3, [r6] */
/* @0x1c77a4 mov r2, r7 */
/* @0x1c77a8 mov r1, #6 */
/* @0x1c77ac ldr r3, [r3, #0xc] */
/* @0x1c77b0 strb r0, [r12, #0x19] */
/* @0x1c77b4 mov r0, r6 */
/* @0x1c77b8 blx r3 */
/* @0x1c77bc mov r1, #0 */
/* @0x1c77c0 mov r0, r7 */
/* @0x1c77c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c77c8 ldr r12, [sp, #0x4] */
/* @0x1c77cc ldr r3, [r6] */
/* @0x1c77d0 mov r2, r7 */
/* @0x1c77d4 mov r1, #6 */
/* @0x1c77d8 ldr r3, [r3, #0xc] */
/* @0x1c77dc str r0, [r12, #0x20] */
/* @0x1c77e0 mov r0, r6 */
/* @0x1c77e4 blx r3 */
/* @0x1c77e8 mov r1, #0 */
/* @0x1c77ec mov r0, r7 */
/* @0x1c77f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c77f4 ldr r12, [sp, #0x4] */
/* @0x1c77f8 ldr r3, [r6] */
/* @0x1c77fc mov r2, r7 */
/* @0x1c7800 mov r1, #6 */
/* @0x1c7804 ldr r3, [r3, #0xc] */
/* @0x1c7808 str r0, [r12, #0x24] */
/* @0x1c780c mov r0, r6 */
/* @0x1c7810 blx r3 */
/* @0x1c7814 mov r1, #0 */
/* @0x1c7818 mov r0, r7 */
/* @0x1c781c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7820 ldr r1, [sp, #0x4] */
/* @0x1c7824 str r0, [r1, #0x28] */
/* @0x1c7828 ldr r0, [sp, #0xc] */
/* @0x1c782c bl 0x1c30f8 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer> */
/* @0x1c7830 ldr r3, [r6] */
/* @0x1c7834 mov r2, r7 */
/* @0x1c7838 mov r1, #6 */
/* @0x1c783c mov r0, r6 */
/* @0x1c7840 ldr r3, [r3, #0xc] */
/* @0x1c7844 blx r3 */
/* @0x1c7848 mov r0, r7 */
/* @0x1c784c mov r1, #0 */
/* @0x1c7850 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7854 subs r10, r0, #0 */
/* @0x1c7858 ble 0x1c7b5c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x68c> */
/* @0x1c785c ldr r3, [pc, #0xac] */
/* @0x1c7860 mov r5, #0 */
/* @0x1c7864 ldr r12, [sp, #0x1c] */
/* @0x1c7868 mov r9, r5 */
/* @0x1c786c ldr r11, [pc, #0x94] */
/* @0x1c7870 vldr s16, [pc, #128] */
/* @0x1c7874 ldr r3, [r12, r3] */
/* @0x1c7878 add r11, pc, r11 */
/* @0x1c787c str r10, [sp, #0x8] */
/* @0x1c7880 ldr r10, [sp, #0xc] */
/* @0x1c7884 str r11, [sp, #0x10] */
/* @0x1c7888 mov r11, r6 */
/* @0x1c788c mov r6, r3 */
/* @0x1c7890 str r3, [sp, #0x14] */
/* @0x1c7894 bl 0x1c0bd8 <_ZN13CLayerManager23GetNewBackgroundElementEv> */
/* @0x1c7898 ldr r1, [sp, #0x10] */
/* @0x1c789c movw r2, #0x47c */
/* @0x1c78a0 mov r3, #1 */
/* @0x1c78a4 mov r8, r0 */
/* @0x1c78a8 mov r0, #44 */
/* @0x1c78ac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c78b0 subs r4, r0, #0 */
/* @0x1c78b4 beq 0x1c791c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x44c> */
/* @0x1c78b8 strb r9, [r4] */
/* @0x1c78bc vstr s16, [r4, #12] */
/* @0x1c78c0 strb r9, [r4, #0x1] */
/* @0x1c78c4 vstr s16, [r4, #16] */
/* @0x1c78c8 str r9, [r4, #0x4] */
/* @0x1c78cc vstr s16, [r4, #28] */
/* @0x1c78d0 strb r9, [r4, #0x8] */
/* @0x1c78d4 vstr s16, [r4, #32] */
/* @0x1c78d8 strb r9, [r4, #0x9] */
/* @0x1c78dc vstr s16, [r4, #36] */
/* @0x1c78e0 strb r9, [r4, #0x14] */
/* @0x1c78e4 str r9, [r4, #0x18] */
/* @0x1c78e8 str r9, [r4, #0x28] */
/* @0x1c78ec b 0x1c791c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x44c> */
/* @0x1c78fc eoreq r10, r2, r0, ror r7 */
/* @0x1c7900 .word 0xffffec0c */
/* @0x1c7904 andseq r6, r8, r4, ror r1 */
/* @0x1c7908 ldrsheq r5, [r8], -r4 */
/* @0x1c790c ldrsbeq r5, [r8], -r0 */
/* @0x1c7910 .word 0xffffbcd8 */
/* @0x1c7914 .word 0xffffec28 */
/* @0x1c7918 andseq r5, r8, r4, ror #12 */
/* @0x1c791c ldr r3, [r11] */
/* @0x1c7920 mov r2, r7 */
/* @0x1c7924 str r4, [r8, #0x1c] */
/* @0x1c7928 mov r1, #6 */
/* @0x1c792c mov r0, r11 */
/* @0x1c7930 add r5, r5, #1 */
/* @0x1c7934 ldr r3, [r3, #0xc] */
/* @0x1c7938 blx r3 */
/* @0x1c793c mov r1, #0 */
/* @0x1c7940 mov r0, r7 */
/* @0x1c7944 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c7948 ldr r3, [r11] */
/* @0x1c794c mov r2, r7 */
/* @0x1c7950 mov r1, #6 */
/* @0x1c7954 ldr r3, [r3, #0xc] */
/* @0x1c7958 strb r0, [r4] */
/* @0x1c795c mov r0, r11 */
/* @0x1c7960 blx r3 */
/* @0x1c7964 mov r1, #0 */
/* @0x1c7968 mov r0, r7 */
/* @0x1c796c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c7970 ldr r3, [r11] */
/* @0x1c7974 mov r2, r7 */
/* @0x1c7978 mov r1, #6 */
/* @0x1c797c ldr r3, [r3, #0xc] */
/* @0x1c7980 strb r0, [r4, #0x1] */
/* @0x1c7984 mov r0, r11 */
/* @0x1c7988 blx r3 */
/* @0x1c798c mov r1, #0 */
/* @0x1c7990 mov r0, r7 */
/* @0x1c7994 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7998 ldr r3, [r11] */
/* @0x1c799c mov r2, r7 */
/* @0x1c79a0 mov r1, #6 */
/* @0x1c79a4 ldr r3, [r3, #0xc] */
/* @0x1c79a8 str r0, [r4, #0x4] */
/* @0x1c79ac mov r0, r11 */
/* @0x1c79b0 blx r3 */
/* @0x1c79b4 mov r1, #0 */
/* @0x1c79b8 mov r0, r7 */
/* @0x1c79bc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c79c0 ldr r3, [r11] */
/* @0x1c79c4 mov r2, r7 */
/* @0x1c79c8 mov r1, #6 */
/* @0x1c79cc ldr r3, [r3, #0xc] */
/* @0x1c79d0 strb r0, [r4, #0x8] */
/* @0x1c79d4 mov r0, r11 */
/* @0x1c79d8 blx r3 */
/* @0x1c79dc mov r1, #0 */
/* @0x1c79e0 mov r0, r7 */
/* @0x1c79e4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c79e8 ldr r3, [r11] */
/* @0x1c79ec mov r2, r7 */
/* @0x1c79f0 mov r1, #8 */
/* @0x1c79f4 ldr r3, [r3, #0xc] */
/* @0x1c79f8 strb r0, [r4, #0x9] */
/* @0x1c79fc mov r0, r11 */
/* @0x1c7a00 blx r3 */
/* @0x1c7a04 mov r1, #0 */
/* @0x1c7a08 mov r0, r7 */
/* @0x1c7a0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7a10 ldr r3, [r11] */
/* @0x1c7a14 mov r2, r7 */
/* @0x1c7a18 mov r1, #8 */
/* @0x1c7a1c ldr r3, [r3, #0xc] */
/* @0x1c7a20 str r0, [r4, #0xc] */
/* @0x1c7a24 mov r0, r11 */
/* @0x1c7a28 blx r3 */
/* @0x1c7a2c mov r1, #0 */
/* @0x1c7a30 mov r0, r7 */
/* @0x1c7a34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7a38 ldr r3, [r11] */
/* @0x1c7a3c mov r2, r7 */
/* @0x1c7a40 mov r1, #6 */
/* @0x1c7a44 ldr r3, [r3, #0xc] */
/* @0x1c7a48 str r0, [r4, #0x10] */
/* @0x1c7a4c mov r0, r11 */
/* @0x1c7a50 blx r3 */
/* @0x1c7a54 mov r1, #0 */
/* @0x1c7a58 mov r0, r7 */
/* @0x1c7a5c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c7a60 ldr r3, [r11] */
/* @0x1c7a64 mov r2, r7 */
/* @0x1c7a68 mov r1, #6 */
/* @0x1c7a6c ldr r3, [r3, #0xc] */
/* @0x1c7a70 strb r0, [r4, #0x14] */
/* @0x1c7a74 mov r0, r11 */
/* @0x1c7a78 blx r3 */
/* @0x1c7a7c mov r1, #0 */
/* @0x1c7a80 mov r0, r7 */
/* @0x1c7a84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7a88 ldr r3, [r11] */
/* @0x1c7a8c mov r2, r7 */
/* @0x1c7a90 mov r1, #8 */
/* @0x1c7a94 ldr r3, [r3, #0xc] */
/* @0x1c7a98 str r0, [r4, #0x18] */
/* @0x1c7a9c mov r0, r11 */
/* @0x1c7aa0 blx r3 */
/* @0x1c7aa4 mov r1, #0 */
/* @0x1c7aa8 mov r0, r7 */
/* @0x1c7aac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7ab0 ldr r3, [r11] */
/* @0x1c7ab4 mov r2, r7 */
/* @0x1c7ab8 mov r1, #8 */
/* @0x1c7abc ldr r3, [r3, #0xc] */
/* @0x1c7ac0 str r0, [r4, #0x1c] */
/* @0x1c7ac4 mov r0, r11 */
/* @0x1c7ac8 blx r3 */
/* @0x1c7acc mov r1, #0 */
/* @0x1c7ad0 mov r0, r7 */
/* @0x1c7ad4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7ad8 ldr r3, [r11] */
/* @0x1c7adc mov r2, r7 */
/* @0x1c7ae0 mov r1, #8 */
/* @0x1c7ae4 ldr r3, [r3, #0xc] */
/* @0x1c7ae8 str r0, [r4, #0x20] */
/* @0x1c7aec mov r0, r11 */
/* @0x1c7af0 blx r3 */
/* @0x1c7af4 mov r1, #0 */
/* @0x1c7af8 mov r0, r7 */
/* @0x1c7afc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7b00 ldr r3, [r11] */
/* @0x1c7b04 mov r2, r7 */
/* @0x1c7b08 mov r1, #6 */
/* @0x1c7b0c ldr r3, [r3, #0xc] */
/* @0x1c7b10 str r0, [r4, #0x24] */
/* @0x1c7b14 mov r0, r11 */
/* @0x1c7b18 blx r3 */
/* @0x1c7b1c mov r1, #0 */
/* @0x1c7b20 mov r0, r7 */
/* @0x1c7b24 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7b28 ldr r3, [r6] */
/* @0x1c7b2c mov r2, r8 */
/* @0x1c7b30 ldr r1, [sp, #0x4] */
/* @0x1c7b34 subs r8, r10, r3 */
/* @0x1c7b38 rsbs r3, r8, #0 */
/* @0x1c7b3c adcs r3, r3, r8 */
/* @0x1c7b40 str r0, [r4, #0x28] */
/* @0x1c7b44 mov r0, r10 */
/* @0x1c7b48 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c7b4c ldr r12, [sp, #0x8] */
/* @0x1c7b50 cmp r5, r12 */
/* @0x1c7b54 bne 0x1c7894 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x3c4> */
/* @0x1c7b58 mov r6, r11 */
/* @0x1c7b5c ldr r3, [r6] */
/* @0x1c7b60 mov r1, #6 */
/* @0x1c7b64 mov r2, r7 */
/* @0x1c7b68 mov r0, r6 */
/* @0x1c7b6c ldr r3, [r3, #0xc] */
/* @0x1c7b70 blx r3 */
/* @0x1c7b74 mov r0, r7 */
/* @0x1c7b78 mov r1, #0 */
/* @0x1c7b7c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7b80 cmp r0, #0 */
/* @0x1c7b84 str r0, [sp, #0x10] */
/* @0x1c7b88 ble 0x1c7dd8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x908> */
/* @0x1c7b8c mov r12, #0 */
/* @0x1c7b90 str r12, [sp, #0x8] */
/* @0x1c7b94 ldr r12, [pc, #-0x290] */
/* @0x1c7b98 ldr r3, [pc, #-0x290] */
/* @0x1c7b9c add r12, pc, r12 */
/* @0x1c7ba0 str r12, [sp, #0x18] */
/* @0x1c7ba4 ldr r12, [sp, #0x1c] */
/* @0x1c7ba8 ldr r3, [r12, r3] */
/* @0x1c7bac str r3, [sp, #0x14] */
/* @0x1c7bb0 bl 0x1c1034 <_ZN13CLayerManager20GetNewTilemapElementEv> */
/* @0x1c7bb4 ldr r3, [r6] */
/* @0x1c7bb8 mov r2, r7 */
/* @0x1c7bbc mov r1, #6 */
/* @0x1c7bc0 ldr r3, [r3, #0xc] */
/* @0x1c7bc4 mov r8, r0 */
/* @0x1c7bc8 mov r0, r6 */
/* @0x1c7bcc blx r3 */
/* @0x1c7bd0 mov r1, #0 */
/* @0x1c7bd4 mov r0, r7 */
/* @0x1c7bd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7bdc str r0, [r8, #0x1c] */
/* @0x1c7be0 mov r0, r6 */
/* @0x1c7be4 bl 0xcde74 <_ZN7IBuffer10ReadStringEv> */
/* @0x1c7be8 ldr r3, [r6] */
/* @0x1c7bec mov r2, r7 */
/* @0x1c7bf0 mov r1, #8 */
/* @0x1c7bf4 str r0, [r8, #0xc] */
/* @0x1c7bf8 mov r0, r6 */
/* @0x1c7bfc ldr r3, [r3, #0xc] */
/* @0x1c7c00 blx r3 */
/* @0x1c7c04 mov r1, #0 */
/* @0x1c7c08 mov r0, r7 */
/* @0x1c7c0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7c10 ldr r3, [r6] */
/* @0x1c7c14 mov r2, r7 */
/* @0x1c7c18 mov r1, #8 */
/* @0x1c7c1c ldr r3, [r3, #0xc] */
/* @0x1c7c20 str r0, [r8, #0x20] */
/* @0x1c7c24 mov r0, r6 */
/* @0x1c7c28 blx r3 */
/* @0x1c7c2c mov r1, #0 */
/* @0x1c7c30 mov r0, r7 */
/* @0x1c7c34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7c38 ldr r3, [r6] */
/* @0x1c7c3c mov r2, r7 */
/* @0x1c7c40 mov r1, #6 */
/* @0x1c7c44 ldr r3, [r3, #0xc] */
/* @0x1c7c48 str r0, [r8, #0x24] */
/* @0x1c7c4c mov r0, r6 */
/* @0x1c7c50 blx r3 */
/* @0x1c7c54 mov r1, #0 */
/* @0x1c7c58 mov r0, r7 */
/* @0x1c7c5c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7c60 ldr r3, [r6] */
/* @0x1c7c64 mov r2, r7 */
/* @0x1c7c68 mov r1, #6 */
/* @0x1c7c6c ldr r3, [r3, #0xc] */
/* @0x1c7c70 str r0, [r8, #0x28] */
/* @0x1c7c74 mov r0, r6 */
/* @0x1c7c78 blx r3 */
/* @0x1c7c7c mov r1, #0 */
/* @0x1c7c80 mov r0, r7 */
/* @0x1c7c84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7c88 ldr r3, [r6] */
/* @0x1c7c8c mov r2, r7 */
/* @0x1c7c90 mov r1, #8 */
/* @0x1c7c94 ldr r3, [r3, #0xc] */
/* @0x1c7c98 str r0, [r8, #0x2c] */
/* @0x1c7c9c mov r0, r6 */
/* @0x1c7ca0 blx r3 */
/* @0x1c7ca4 mov r1, #0 */
/* @0x1c7ca8 mov r0, r7 */
/* @0x1c7cac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7cb0 ldr lr, [r8, #0x2c] */
/* @0x1c7cb4 ldr r12, [r8, #0x28] */
/* @0x1c7cb8 movw r2, #0x493 */
/* @0x1c7cbc ldr r1, [sp, #0x18] */
/* @0x1c7cc0 mov r3, #1 */
/* @0x1c7cc4 mul r12, lr, r12 */
/* @0x1c7cc8 str r0, [r8, #0x30] */
/* @0x1c7ccc lsl r0, r12, #2 */
/* @0x1c7cd0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c7cd4 ldr r3, [r8, #0x28] */
/* @0x1c7cd8 ldr r2, [r8, #0x2c] */
/* @0x1c7cdc mov r1, #0 */
/* @0x1c7ce0 mul r2, r2, r3 */
/* @0x1c7ce4 lsl r2, r2, #2 */
/* @0x1c7ce8 str r0, [r8, #0x34] */
/* @0x1c7cec bl 0xb65b0 <memset@plt> */
/* @0x1c7cf0 ldr r2, [r8, #0x28] */
/* @0x1c7cf4 cmp r2, #0 */
/* @0x1c7cf8 ble 0x1c7d6c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x89c> */
/* @0x1c7cfc ldr r3, [r8, #0x2c] */
/* @0x1c7d00 mov r10, #0 */
/* @0x1c7d04 mov r9, r10 */
/* @0x1c7d08 cmp r3, #0 */
/* @0x1c7d0c ble 0x1c7d60 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x890> */
/* @0x1c7d10 lsl r5, r9, #2 */
/* @0x1c7d14 mov r4, #0 */
/* @0x1c7d18 ldr r3, [r6] */
/* @0x1c7d1c mov r1, #5 */
/* @0x1c7d20 mov r2, r7 */
/* @0x1c7d24 mov r0, r6 */
/* @0x1c7d28 ldr r11, [r8, #0x34] */
/* @0x1c7d2c add r4, r4, #1 */
/* @0x1c7d30 ldr r3, [r3, #0xc] */
/* @0x1c7d34 add r9, r9, #1 */
/* @0x1c7d38 blx r3 */
/* @0x1c7d3c mov r0, r7 */
/* @0x1c7d40 mov r1, #0 */
/* @0x1c7d44 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x1c7d48 str r0, [r11, r5] */
/* @0x1c7d4c add r5, r5, #4 */
/* @0x1c7d50 ldr r3, [r8, #0x2c] */
/* @0x1c7d54 cmp r3, r4 */
/* @0x1c7d58 bgt 0x1c7d18 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x848> */
/* @0x1c7d5c ldr r2, [r8, #0x28] */
/* @0x1c7d60 add r10, r10, #1 */
/* @0x1c7d64 cmp r2, r10 */
/* @0x1c7d68 bgt 0x1c7d08 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x838> */
/* @0x1c7d6c ldr r3, [r6] */
/* @0x1c7d70 mov r2, r7 */
/* @0x1c7d74 ldr r12, [sp, #0x8] */
/* @0x1c7d78 mov r1, #5 */
/* @0x1c7d7c mov r0, r6 */
/* @0x1c7d80 add r12, r12, #1 */
/* @0x1c7d84 ldr r3, [r3, #0xc] */
/* @0x1c7d88 str r12, [sp, #0x8] */
/* @0x1c7d8c blx r3 */
/* @0x1c7d90 mov r1, #0 */
/* @0x1c7d94 mov r0, r7 */
/* @0x1c7d98 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x1c7d9c ldr r12, [sp, #0x14] */
/* @0x1c7da0 ldr r1, [sp, #0x4] */
/* @0x1c7da4 mov r2, r8 */
/* @0x1c7da8 ldr r3, [r12] */
/* @0x1c7dac ldr r12, [sp, #0xc] */
/* @0x1c7db0 subs lr, r12, r3 */
/* @0x1c7db4 rsbs r3, lr, #0 */
/* @0x1c7db8 adcs r3, r3, lr */
/* @0x1c7dbc str r0, [r8, #0x38] */
/* @0x1c7dc0 mov r0, r12 */
/* @0x1c7dc4 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c7dc8 ldr r12, [sp, #0x8] */
/* @0x1c7dcc ldr r1, [sp, #0x10] */
/* @0x1c7dd0 cmp r12, r1 */
/* @0x1c7dd4 bne 0x1c7bb0 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x6e0> */
/* @0x1c7dd8 ldr r3, [r6] */
/* @0x1c7ddc mov r1, #6 */
/* @0x1c7de0 mov r2, r7 */
/* @0x1c7de4 mov r0, r6 */
/* @0x1c7de8 ldr r3, [r3, #0xc] */
/* @0x1c7dec blx r3 */
/* @0x1c7df0 mov r0, r7 */
/* @0x1c7df4 mov r1, #0 */
/* @0x1c7df8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7dfc subs r8, r0, #0 */
/* @0x1c7e00 ble 0x1c7fe8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xb18> */
/* @0x1c7e04 ldr r3, [pc, #-0x4fc] */
/* @0x1c7e08 mov r5, #0 */
/* @0x1c7e0c ldr r12, [sp, #0x1c] */
/* @0x1c7e10 ldr r10, [sp, #0x4] */
/* @0x1c7e14 ldr r9, [sp, #0xc] */
/* @0x1c7e18 ldr r3, [r12, r3] */
/* @0x1c7e1c mov r11, r3 */
/* @0x1c7e20 str r3, [sp, #0x14] */
/* @0x1c7e24 bl 0x1c0f00 <_ZN13CLayerManager19GetNewSpriteElementEv> */
/* @0x1c7e28 ldr r3, [r6] */
/* @0x1c7e2c mov r2, r7 */
/* @0x1c7e30 mov r1, #6 */
/* @0x1c7e34 add r5, r5, #1 */
/* @0x1c7e38 ldr r3, [r3, #0xc] */
/* @0x1c7e3c mov r4, r0 */
/* @0x1c7e40 mov r0, r6 */
/* @0x1c7e44 blx r3 */
/* @0x1c7e48 mov r1, #0 */
/* @0x1c7e4c mov r0, r7 */
/* @0x1c7e50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7e54 ldr r3, [r6] */
/* @0x1c7e58 mov r2, r7 */
/* @0x1c7e5c mov r1, #8 */
/* @0x1c7e60 ldr r3, [r3, #0xc] */
/* @0x1c7e64 str r0, [r4, #0x1c] */
/* @0x1c7e68 mov r0, r6 */
/* @0x1c7e6c blx r3 */
/* @0x1c7e70 mov r1, #0 */
/* @0x1c7e74 mov r0, r7 */
/* @0x1c7e78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7e7c ldr r3, [r6] */
/* @0x1c7e80 mov r2, r7 */
/* @0x1c7e84 mov r1, #6 */
/* @0x1c7e88 ldr r3, [r3, #0xc] */
/* @0x1c7e8c str r0, [r4, #0x24] */
/* @0x1c7e90 mov r0, r6 */
/* @0x1c7e94 blx r3 */
/* @0x1c7e98 mov r1, #0 */
/* @0x1c7e9c mov r0, r7 */
/* @0x1c7ea0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7ea4 ldr r3, [r6] */
/* @0x1c7ea8 mov r2, r7 */
/* @0x1c7eac mov r1, #8 */
/* @0x1c7eb0 ldr r3, [r3, #0xc] */
/* @0x1c7eb4 str r0, [r4, #0x28] */
/* @0x1c7eb8 mov r0, r6 */
/* @0x1c7ebc blx r3 */
/* @0x1c7ec0 mov r1, #0 */
/* @0x1c7ec4 mov r0, r7 */
/* @0x1c7ec8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7ecc ldr r3, [r6] */
/* @0x1c7ed0 mov r2, r7 */
/* @0x1c7ed4 mov r1, #8 */
/* @0x1c7ed8 ldr r3, [r3, #0xc] */
/* @0x1c7edc str r0, [r4, #0x2c] */
/* @0x1c7ee0 mov r0, r6 */
/* @0x1c7ee4 blx r3 */
/* @0x1c7ee8 mov r1, #0 */
/* @0x1c7eec mov r0, r7 */
/* @0x1c7ef0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7ef4 ldr r3, [r6] */
/* @0x1c7ef8 mov r2, r7 */
/* @0x1c7efc mov r1, #8 */
/* @0x1c7f00 ldr r3, [r3, #0xc] */
/* @0x1c7f04 str r0, [r4, #0x30] */
/* @0x1c7f08 mov r0, r6 */
/* @0x1c7f0c blx r3 */
/* @0x1c7f10 mov r1, #0 */
/* @0x1c7f14 mov r0, r7 */
/* @0x1c7f18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7f1c ldr r3, [r6] */
/* @0x1c7f20 mov r2, r7 */
/* @0x1c7f24 mov r1, #6 */
/* @0x1c7f28 ldr r3, [r3, #0xc] */
/* @0x1c7f2c str r0, [r4, #0x34] */
/* @0x1c7f30 mov r0, r6 */
/* @0x1c7f34 blx r3 */
/* @0x1c7f38 mov r1, #0 */
/* @0x1c7f3c mov r0, r7 */
/* @0x1c7f40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c7f44 ldr r3, [r6] */
/* @0x1c7f48 mov r2, r7 */
/* @0x1c7f4c mov r1, #8 */
/* @0x1c7f50 ldr r3, [r3, #0xc] */
/* @0x1c7f54 str r0, [r4, #0x38] */
/* @0x1c7f58 mov r0, r6 */
/* @0x1c7f5c blx r3 */
/* @0x1c7f60 mov r1, #0 */
/* @0x1c7f64 mov r0, r7 */
/* @0x1c7f68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7f6c ldr r3, [r6] */
/* @0x1c7f70 mov r2, r7 */
/* @0x1c7f74 mov r1, #8 */
/* @0x1c7f78 ldr r3, [r3, #0xc] */
/* @0x1c7f7c str r0, [r4, #0x3c] */
/* @0x1c7f80 mov r0, r6 */
/* @0x1c7f84 blx r3 */
/* @0x1c7f88 mov r1, #0 */
/* @0x1c7f8c mov r0, r7 */
/* @0x1c7f90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7f94 ldr r3, [r6] */
/* @0x1c7f98 mov r2, r7 */
/* @0x1c7f9c mov r1, #8 */
/* @0x1c7fa0 ldr r3, [r3, #0xc] */
/* @0x1c7fa4 str r0, [r4, #0x40] */
/* @0x1c7fa8 mov r0, r6 */
/* @0x1c7fac blx r3 */
/* @0x1c7fb0 mov r1, #0 */
/* @0x1c7fb4 mov r0, r7 */
/* @0x1c7fb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c7fbc ldr r3, [r11] */
/* @0x1c7fc0 mov r2, r4 */
/* @0x1c7fc4 mov r1, r10 */
/* @0x1c7fc8 subs r12, r9, r3 */
/* @0x1c7fcc rsbs r3, r12, #0 */
/* @0x1c7fd0 adcs r3, r3, r12 */
/* @0x1c7fd4 str r0, [r4, #0x44] */
/* @0x1c7fd8 mov r0, r9 */
/* @0x1c7fdc bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c7fe0 cmp r5, r8 */
/* @0x1c7fe4 bne 0x1c7e24 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x954> */
/* @0x1c7fe8 ldr r3, [r6] */
/* @0x1c7fec mov r1, #6 */
/* @0x1c7ff0 mov r2, r7 */
/* @0x1c7ff4 mov r0, r6 */
/* @0x1c7ff8 ldr r3, [r3, #0xc] */
/* @0x1c7ffc blx r3 */
/* @0x1c8000 mov r0, r7 */
/* @0x1c8004 mov r1, #0 */
/* @0x1c8008 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c800c subs r11, r0, #0 */
/* @0x1c8010 ble 0x1c8370 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xea0> */
/* @0x1c8014 ldr r3, [pc, #-0x708] */
/* @0x1c8018 mov r9, #0 */
/* @0x1c801c ldr r12, [sp, #0x1c] */
/* @0x1c8020 mov r4, r9 */
/* @0x1c8024 ldr r8, [pc, #-0x714] */
/* @0x1c8028 vldr s16, [pc, #844] */
/* @0x1c802c ldr r10, [r12, r3] */
/* @0x1c8030 add r8, pc, r8 */
/* @0x1c8034 ldr r2, [r10, #0x8] */
/* @0x1c8038 cmp r2, #0 */
/* @0x1c803c bne 0x1c8114 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xc44> */
/* @0x1c8040 ldr r3, [r10, #0x10] */
/* @0x1c8044 cmp r3, #0 */
/* @0x1c8048 ble 0x1c810c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xc3c> */
/* @0x1c804c mov r5, r2 */
/* @0x1c8050 mov r1, r8 */
/* @0x1c8054 mov r3, #1 */
/* @0x1c8058 mov r0, #80 */
/* @0x1c805c mov r2, #63 */
/* @0x1c8060 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c8064 mvn r3, #0 */
/* @0x1c8068 mov r1, #7 */
/* @0x1c806c cmp r0, #0 */
/* @0x1c8070 beq 0x1c80c4 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xbf4> */
/* @0x1c8074 mov r2, #1065353216 */
/* @0x1c8078 strb r4, [r0, #0x8] */
/* @0x1c807c str r4, [r0, #0xc] */
/* @0x1c8080 vstr s16, [r0, #36] */
/* @0x1c8084 str r4, [r0, #0x10] */
/* @0x1c8088 vstr s16, [r0, #40] */
/* @0x1c808c str r4, [r0, #0x14] */
/* @0x1c8090 vstr s16, [r0, #60] */
/* @0x1c8094 str r4, [r0, #0x18] */
/* @0x1c8098 str r3, [r0, #0x4] */
/* @0x1c809c str r3, [r0, #0x20] */
/* @0x1c80a0 str r4, [r0, #0x2c] */
/* @0x1c80a4 str r4, [r0, #0x30] */
/* @0x1c80a8 str r3, [r0, #0x40] */
/* @0x1c80ac str r4, [r0, #0x48] */
/* @0x1c80b0 str r2, [r0, #0x34] */
/* @0x1c80b4 str r4, [r0, #0x4c] */
/* @0x1c80b8 str r2, [r0, #0x38] */
/* @0x1c80bc str r1, [r0] */
/* @0x1c80c0 str r2, [r0, #0x44] */
/* @0x1c80c4 ldr r3, [r10] */
/* @0x1c80c8 add r5, r5, #1 */
/* @0x1c80cc ldr r2, [r10, #0x8] */
/* @0x1c80d0 cmp r3, #0 */
/* @0x1c80d4 streq r0, [r10, #0x4] */
/* @0x1c80d8 strne r0, [r3, #0x18] */
/* @0x1c80dc add r2, r2, #1 */
/* @0x1c80e0 streq r3, [r0, #0x18] */
/* @0x1c80e4 streq r3, [r0, #0x14] */
/* @0x1c80e8 strne r3, [r0, #0x14] */
/* @0x1c80ec ldr r3, [r10, #0x10] */
/* @0x1c80f0 streq r0, [r10] */
/* @0x1c80f4 strne r0, [r10] */
/* @0x1c80f8 strne r4, [r0, #0x18] */
/* @0x1c80fc cmp r5, r3 */
/* @0x1c8100 str r2, [r10, #0x8] */
/* @0x1c8104 blt 0x1c8050 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xb80> */
/* @0x1c8108 ldr r2, [r10, #0x8] */
/* @0x1c810c lsl r3, r3, #1 */
/* @0x1c8110 str r3, [r10, #0x10] */
/* @0x1c8114 ldr r5, [r10] */
/* @0x1c8118 sub r2, r2, #1 */
/* @0x1c811c mov r0, r6 */
/* @0x1c8120 add r9, r9, #1 */
/* @0x1c8124 ldr r3, [r5, #0x18] */
/* @0x1c8128 ldr r1, [r5, #0x14] */
/* @0x1c812c cmp r3, #0 */
/* @0x1c8130 strne r1, [r3, #0x14] */
/* @0x1c8134 ldrne r1, [r5, #0x14] */
/* @0x1c8138 ldrne r3, [r5, #0x18] */
/* @0x1c813c streq r1, [r10] */
/* @0x1c8140 cmp r1, #0 */
/* @0x1c8144 streq r3, [r10, #0x4] */
/* @0x1c8148 strne r3, [r1, #0x18] */
/* @0x1c814c mov r1, #6 */
/* @0x1c8150 ldr r3, [r6] */
/* @0x1c8154 str r2, [r10, #0x8] */
/* @0x1c8158 mov r2, r7 */
/* @0x1c815c ldr r3, [r3, #0xc] */
/* @0x1c8160 blx r3 */
/* @0x1c8164 mov r1, #0 */
/* @0x1c8168 mov r0, r7 */
/* @0x1c816c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1c8170 ldr r3, [r6] */
/* @0x1c8174 mov r2, r7 */
/* @0x1c8178 mov r1, #6 */
/* @0x1c817c ldr r3, [r3, #0xc] */
/* @0x1c8180 strb r0, [r5, #0x1c] */
/* @0x1c8184 mov r0, r6 */
/* @0x1c8188 blx r3 */
/* @0x1c818c mov r1, #0 */
/* @0x1c8190 mov r0, r7 */
/* @0x1c8194 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c8198 ldr r3, [r6] */
/* @0x1c819c mov r2, r7 */
/* @0x1c81a0 mov r1, #8 */
/* @0x1c81a4 ldr r3, [r3, #0xc] */
/* @0x1c81a8 str r0, [r5, #0x20] */
/* @0x1c81ac mov r0, r6 */
/* @0x1c81b0 blx r3 */
/* @0x1c81b4 mov r1, #0 */
/* @0x1c81b8 mov r0, r7 */
/* @0x1c81bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c81c0 ldr r3, [r6] */
/* @0x1c81c4 mov r2, r7 */
/* @0x1c81c8 mov r1, #8 */
/* @0x1c81cc ldr r3, [r3, #0xc] */
/* @0x1c81d0 str r0, [r5, #0x24] */
/* @0x1c81d4 mov r0, r6 */
/* @0x1c81d8 blx r3 */
/* @0x1c81dc mov r1, #0 */
/* @0x1c81e0 mov r0, r7 */
/* @0x1c81e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c81e8 ldr r3, [r6] */
/* @0x1c81ec mov r2, r7 */
/* @0x1c81f0 mov r1, #6 */
/* @0x1c81f4 ldr r3, [r3, #0xc] */
/* @0x1c81f8 str r0, [r5, #0x28] */
/* @0x1c81fc mov r0, r6 */
/* @0x1c8200 blx r3 */
/* @0x1c8204 mov r1, #0 */
/* @0x1c8208 mov r0, r7 */
/* @0x1c820c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c8210 ldr r3, [r6] */
/* @0x1c8214 mov r2, r7 */
/* @0x1c8218 mov r1, #6 */
/* @0x1c821c ldr r3, [r3, #0xc] */
/* @0x1c8220 str r0, [r5, #0x2c] */
/* @0x1c8224 mov r0, r6 */
/* @0x1c8228 blx r3 */
/* @0x1c822c mov r1, #0 */
/* @0x1c8230 mov r0, r7 */
/* @0x1c8234 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c8238 ldr r3, [r6] */
/* @0x1c823c mov r2, r7 */
/* @0x1c8240 mov r1, #8 */
/* @0x1c8244 ldr r3, [r3, #0xc] */
/* @0x1c8248 str r0, [r5, #0x30] */
/* @0x1c824c mov r0, r6 */
/* @0x1c8250 blx r3 */
/* @0x1c8254 mov r1, #0 */
/* @0x1c8258 mov r0, r7 */
/* @0x1c825c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c8260 ldr r3, [r6] */
/* @0x1c8264 mov r2, r7 */
/* @0x1c8268 mov r1, #8 */
/* @0x1c826c ldr r3, [r3, #0xc] */
/* @0x1c8270 str r0, [r5, #0x34] */
/* @0x1c8274 mov r0, r6 */
/* @0x1c8278 blx r3 */
/* @0x1c827c mov r1, #0 */
/* @0x1c8280 mov r0, r7 */
/* @0x1c8284 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c8288 ldr r3, [r6] */
/* @0x1c828c mov r2, r7 */
/* @0x1c8290 mov r1, #8 */
/* @0x1c8294 ldr r3, [r3, #0xc] */
/* @0x1c8298 str r0, [r5, #0x38] */
/* @0x1c829c mov r0, r6 */
/* @0x1c82a0 blx r3 */
/* @0x1c82a4 mov r1, #0 */
/* @0x1c82a8 mov r0, r7 */
/* @0x1c82ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c82b0 ldr r3, [r6] */
/* @0x1c82b4 mov r2, r7 */
/* @0x1c82b8 mov r1, #5 */
/* @0x1c82bc ldr r3, [r3, #0xc] */
/* @0x1c82c0 str r0, [r5, #0x3c] */
/* @0x1c82c4 mov r0, r6 */
/* @0x1c82c8 blx r3 */
/* @0x1c82cc mov r1, #0 */
/* @0x1c82d0 mov r0, r7 */
/* @0x1c82d4 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x1c82d8 ldr r3, [r6] */
/* @0x1c82dc mov r2, r7 */
/* @0x1c82e0 mov r1, #8 */
/* @0x1c82e4 ldr r3, [r3, #0xc] */
/* @0x1c82e8 str r0, [r5, #0x40] */
/* @0x1c82ec mov r0, r6 */
/* @0x1c82f0 blx r3 */
/* @0x1c82f4 mov r1, #0 */
/* @0x1c82f8 mov r0, r7 */
/* @0x1c82fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1c8300 ldr r3, [r6] */
/* @0x1c8304 mov r2, r7 */
/* @0x1c8308 mov r1, #6 */
/* @0x1c830c ldr r3, [r3, #0xc] */
/* @0x1c8310 str r0, [r5, #0x44] */
/* @0x1c8314 mov r0, r6 */
/* @0x1c8318 blx r3 */
/* @0x1c831c mov r1, #0 */
/* @0x1c8320 mov r0, r7 */
/* @0x1c8324 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c8328 ldr r3, [r6] */
/* @0x1c832c mov r2, r7 */
/* @0x1c8330 mov r1, #6 */
/* @0x1c8334 ldr r3, [r3, #0xc] */
/* @0x1c8338 str r0, [r5, #0x48] */
/* @0x1c833c mov r0, r6 */
/* @0x1c8340 blx r3 */
/* @0x1c8344 mov r1, #0 */
/* @0x1c8348 mov r0, r7 */
/* @0x1c834c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1c8350 mov r2, r5 */
/* @0x1c8354 ldr r1, [sp, #0x4] */
/* @0x1c8358 mov r3, #0 */
/* @0x1c835c str r0, [r5, #0x4c] */
/* @0x1c8360 ldr r0, [sp, #0xc] */
/* @0x1c8364 bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c8368 cmp r9, r11 */
/* @0x1c836c bne 0x1c8034 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xb64> */
/* @0x1c8370 add sp, sp, #36 */
/* @0x1c8374 vpop {d8, d9} */
/* @0x1c8378 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c837c andeq r0, r0, r0 */

/* ── FUNC 0x1c8380 · anon_1c8380 · size=1568 · insn=393 */
/* @0x1c8380 push {r3, r4, r5, lr} */
/* @0x1c8384 mov r5, r1 */
/* @0x1c8388 ldr r4, [pc, #0x2c] */
/* @0x1c838c mov r1, r0 */
/* @0x1c8390 add r4, pc, r4 */
/* @0x1c8394 mov r0, r4 */
/* @0x1c8398 bl 0xb65a4 <strcpy@plt> */
/* @0x1c839c mov r0, r4 */
/* @0x1c83a0 bl 0xb6538 <strlen@plt> */
/* @0x1c83a4 mov r2, #10 */
/* @0x1c83a8 add r1, r4, r0 */
/* @0x1c83ac mov r0, r5 */
/* @0x1c83b0 bl 0xc4964 <_Z5_itoaiPci> */
/* @0x1c83b4 mov r0, r4 */
/* @0x1c83b8 pop {r3, r4, r5, pc} */
/* @0x1c83bc eorseq r10, r7, r12, lsl r3 */
/* @0x1c83c0 ldrb r3, [r0, #0x68] */
/* @0x1c83c4 push {r4, r5, r6, r7, lr} */
/* @0x1c83c8 cmp r3, #0 */
/* @0x1c83cc sub sp, sp, #12 */
/* @0x1c83d0 mov r5, r0 */
/* @0x1c83d4 mov r6, r1 */
/* @0x1c83d8 bne 0x1c83e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf18> */
/* @0x1c83dc ldrb r4, [r0, #0x69] */
/* @0x1c83e0 cmp r4, #0 */
/* @0x1c83e4 beq 0x1c83f8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf28> */
/* @0x1c83e8 mov r4, #1 */
/* @0x1c83ec mov r0, r4 */
/* @0x1c83f0 add sp, sp, #12 */
/* @0x1c83f4 pop {r4, r5, r6, r7, pc} */
/* @0x1c83f8 ldr r3, [r0, #0x48] */
/* @0x1c83fc cmp r3, #1 */
/* @0x1c8400 bne 0x1c83e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf18> */
/* @0x1c8404 ldr r7, [pc, #0xe8] */
/* @0x1c8408 add r7, pc, r7 */
/* @0x1c840c ldr r1, [r7] */
/* @0x1c8410 cmn r1, #3 */
/* @0x1c8414 beq 0x1c844c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf7c> */
/* @0x1c8418 movw r3, #0x869f */
/* @0x1c841c movt r3, #0x1 */
/* @0x1c8420 cmp r1, r3 */
/* @0x1c8424 bgt 0x1c84bc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xfec> */
/* @0x1c8428 cmp r1, #0 */
/* @0x1c842c blt 0x1c84cc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xffc> */
/* @0x1c8430 ldr r0, [r5, #0x80] */
/* @0x1c8434 ldr r3, [r0, #0x18] */
/* @0x1c8438 cmp r3, r1 */
/* @0x1c843c beq 0x1c844c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf7c> */
/* @0x1c8440 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi> */
/* @0x1c8444 cmp r0, #0 */
/* @0x1c8448 beq 0x1c83e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf18> */
/* @0x1c844c ldrb r3, [r6, #0x21] */
/* @0x1c8450 cmp r3, #0 */
/* @0x1c8454 beq 0x1c8464 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf94> */
/* @0x1c8458 ldr r3, [r6, #0x24] */
/* @0x1c845c cmp r3, r5 */
/* @0x1c8460 beq 0x1c83e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf18> */
/* @0x1c8464 vldr d7, [r6, #24] */
/* @0x1c8468 vldr d4, [r6] */
/* @0x1c846c vcvt.f32.f64 s14, d7 */
/* @0x1c8470 vldr d5, [r6, #8] */
/* @0x1c8474 vldr d6, [r6, #16] */
/* @0x1c8478 ldrb r3, [r6, #0x20] */
/* @0x1c847c mov r0, r5 */
/* @0x1c8480 str r3, [sp, #0x4] */
/* @0x1c8484 vcvt.f32.f64 s15, d4 */
/* @0x1c8488 vstr s14, [sp] */
/* @0x1c848c vmov r1, s15 */
/* @0x1c8490 vcvt.f32.f64 s15, d5 */
/* @0x1c8494 vmov r2, s15 */
/* @0x1c8498 vcvt.f32.f64 s15, d6 */
/* @0x1c849c vmov r3, s15 */
/* @0x1c84a0 bl 0x1946f4 <_ZN9CInstance19Collision_RectangleEffffb> */
/* @0x1c84a4 cmp r0, #0 */
/* @0x1c84a8 beq 0x1c83e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf18> */
/* @0x1c84ac ldr r3, [pc, #0x44] */
/* @0x1c84b0 ldr r3, [pc, r3] */
/* @0x1c84b4 str r5, [r3] */
/* @0x1c84b8 b 0x1c83ec <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf1c> */
/* @0x1c84bc ldr r3, [r5, #0x78] */
/* @0x1c84c0 cmp r1, r3 */
/* @0x1c84c4 bne 0x1c83e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf18> */
/* @0x1c84c8 b 0x1c844c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf7c> */
/* @0x1c84cc ldr r3, [pc, #0x28] */
/* @0x1c84d0 ldr r1, [pc, #0x28] */
/* @0x1c84d4 ldr r3, [pc, r3] */
/* @0x1c84d8 add r1, pc, r1 */
/* @0x1c84dc ldr r0, [r3] */
/* @0x1c84e0 ldr r3, [r0] */
/* @0x1c84e4 ldr r3, [r3, #0xc] */
/* @0x1c84e8 blx r3 */
/* @0x1c84ec ldr r1, [r7] */
/* @0x1c84f0 b 0x1c8430 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf60> */
/* @0x1c84f4 .word 0x0022ccd8 */
/* @0x1c84f8 eoreq r8, r2, r8, asr r6 */
/* @0x1c84fc eoreq r5, r2, r0, asr #4 */
/* @0x1c8500 andseq r8, r8, r12, ror #12 */
/* @0x1c8504 ldrb r3, [r0, #0x68] */
/* @0x1c8508 push {r4, r5, r6, r7, lr} */
/* @0x1c850c cmp r3, #0 */
/* @0x1c8510 sub sp, sp, #12 */
/* @0x1c8514 mov r5, r0 */
/* @0x1c8518 mov r6, r1 */
/* @0x1c851c bne 0x1c852c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x105c> */
/* @0x1c8520 ldrb r4, [r0, #0x69] */
/* @0x1c8524 cmp r4, #0 */
/* @0x1c8528 beq 0x1c853c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x106c> */
/* @0x1c852c mov r4, #1 */
/* @0x1c8530 mov r0, r4 */
/* @0x1c8534 add sp, sp, #12 */
/* @0x1c8538 pop {r4, r5, r6, r7, pc} */
/* @0x1c853c ldr r3, [r0, #0x48] */
/* @0x1c8540 cmp r3, #1 */
/* @0x1c8544 bne 0x1c852c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x105c> */
/* @0x1c8548 ldr r7, [pc, #0xe8] */
/* @0x1c854c add r7, pc, r7 */
/* @0x1c8550 ldr r1, [r7] */
/* @0x1c8554 cmn r1, #3 */
/* @0x1c8558 beq 0x1c8590 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x10c0> */
/* @0x1c855c movw r3, #0x869f */
/* @0x1c8560 movt r3, #0x1 */
/* @0x1c8564 cmp r1, r3 */
/* @0x1c8568 bgt 0x1c8600 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1130> */
/* @0x1c856c cmp r1, #0 */
/* @0x1c8570 blt 0x1c8610 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1140> */
/* @0x1c8574 ldr r0, [r5, #0x80] */
/* @0x1c8578 ldr r3, [r0, #0x18] */
/* @0x1c857c cmp r3, r1 */
/* @0x1c8580 beq 0x1c8590 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x10c0> */
/* @0x1c8584 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi> */
/* @0x1c8588 cmp r0, #0 */
/* @0x1c858c beq 0x1c852c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x105c> */
/* @0x1c8590 ldrb r3, [r6, #0x21] */
/* @0x1c8594 cmp r3, #0 */
/* @0x1c8598 beq 0x1c85a8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x10d8> */
/* @0x1c859c ldr r3, [r6, #0x24] */
/* @0x1c85a0 cmp r3, r5 */
/* @0x1c85a4 beq 0x1c852c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x105c> */
/* @0x1c85a8 vldr d7, [r6, #24] */
/* @0x1c85ac vldr d4, [r6] */
/* @0x1c85b0 vcvt.f32.f64 s14, d7 */
/* @0x1c85b4 vldr d5, [r6, #8] */
/* @0x1c85b8 vldr d6, [r6, #16] */
/* @0x1c85bc ldrb r3, [r6, #0x20] */
/* @0x1c85c0 mov r0, r5 */
/* @0x1c85c4 str r3, [sp, #0x4] */
/* @0x1c85c8 vcvt.f32.f64 s15, d4 */
/* @0x1c85cc vstr s14, [sp] */
/* @0x1c85d0 vmov r1, s15 */
/* @0x1c85d4 vcvt.f32.f64 s15, d5 */
/* @0x1c85d8 vmov r2, s15 */
/* @0x1c85dc vcvt.f32.f64 s15, d6 */
/* @0x1c85e0 vmov r3, s15 */
/* @0x1c85e4 bl 0x194f28 <_ZN9CInstance14Collision_LineEffffb> */
/* @0x1c85e8 cmp r0, #0 */
/* @0x1c85ec beq 0x1c852c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x105c> */
/* @0x1c85f0 ldr r3, [pc, #0x44] */
/* @0x1c85f4 ldr r3, [pc, r3] */
/* @0x1c85f8 str r5, [r3] */
/* @0x1c85fc b 0x1c8530 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1060> */
/* @0x1c8600 ldr r3, [r5, #0x78] */
/* @0x1c8604 cmp r1, r3 */
/* @0x1c8608 bne 0x1c852c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x105c> */
/* @0x1c860c b 0x1c8590 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x10c0> */
/* @0x1c8610 ldr r3, [pc, #0x28] */
/* @0x1c8614 ldr r1, [pc, #0x28] */
/* @0x1c8618 ldr r3, [pc, r3] */
/* @0x1c861c add r1, pc, r1 */
/* @0x1c8620 ldr r0, [r3] */
/* @0x1c8624 ldr r3, [r0] */
/* @0x1c8628 ldr r3, [r3, #0xc] */
/* @0x1c862c blx r3 */
/* @0x1c8630 ldr r1, [r7] */
/* @0x1c8634 b 0x1c8574 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x10a4> */
/* @0x1c8638 mlaeq r2, r4, r11, r12 */
/* @0x1c863c eoreq r8, r2, r4, lsl r5 */
/* @0x1c8640 .word 0x002250fc */
/* @0x1c8644 andseq r8, r8, r8, lsr #10 */
/* @0x1c8648 cmp r1, r0 */
/* @0x1c864c push {r3, r4, r5, r6, r7, lr} */
/* @0x1c8650 mov r5, r0 */
/* @0x1c8654 mov r6, r1 */
/* @0x1c8658 beq 0x1c8668 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1198> */
/* @0x1c865c ldrb r3, [r0, #0x68] */
/* @0x1c8660 cmp r3, #0 */
/* @0x1c8664 beq 0x1c8674 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x11a4> */
/* @0x1c8668 mov r4, #1 */
/* @0x1c866c mov r0, r4 */
/* @0x1c8670 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c8674 ldrb r4, [r0, #0x69] */
/* @0x1c8678 cmp r4, #0 */
/* @0x1c867c bne 0x1c8668 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1198> */
/* @0x1c8680 ldr r3, [r0, #0x48] */
/* @0x1c8684 cmp r3, #1 */
/* @0x1c8688 bne 0x1c8668 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1198> */
/* @0x1c868c ldr r7, [pc, #0xa0] */
/* @0x1c8690 add r7, pc, r7 */
/* @0x1c8694 ldr r1, [r7] */
/* @0x1c8698 cmn r1, #3 */
/* @0x1c869c beq 0x1c86d4 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1204> */
/* @0x1c86a0 movw r3, #0x869f */
/* @0x1c86a4 movt r3, #0x1 */
/* @0x1c86a8 cmp r1, r3 */
/* @0x1c86ac bgt 0x1c86fc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x122c> */
/* @0x1c86b0 cmp r1, #0 */
/* @0x1c86b4 blt 0x1c870c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x123c> */
/* @0x1c86b8 ldr r0, [r5, #0x80] */
/* @0x1c86bc ldr r3, [r0, #0x18] */
/* @0x1c86c0 cmp r3, r1 */
/* @0x1c86c4 beq 0x1c86d4 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1204> */
/* @0x1c86c8 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi> */
/* @0x1c86cc cmp r0, #0 */
/* @0x1c86d0 beq 0x1c8668 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1198> */
/* @0x1c86d4 mov r1, r6 */
/* @0x1c86d8 mov r0, r5 */
/* @0x1c86dc mov r2, #1 */
/* @0x1c86e0 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1c86e4 cmp r0, #0 */
/* @0x1c86e8 beq 0x1c8668 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1198> */
/* @0x1c86ec ldr r3, [pc, #0x44] */
/* @0x1c86f0 ldr r3, [pc, r3] */
/* @0x1c86f4 str r5, [r3] */
/* @0x1c86f8 b 0x1c866c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x119c> */
/* @0x1c86fc ldr r3, [r5, #0x78] */
/* @0x1c8700 cmp r1, r3 */
/* @0x1c8704 bne 0x1c8668 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1198> */
/* @0x1c8708 b 0x1c86d4 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1204> */
/* @0x1c870c ldr r3, [pc, #0x28] */
/* @0x1c8710 ldr r1, [pc, #0x28] */
/* @0x1c8714 ldr r3, [pc, r3] */
/* @0x1c8718 add r1, pc, r1 */
/* @0x1c871c ldr r0, [r3] */
/* @0x1c8720 ldr r3, [r0] */
/* @0x1c8724 ldr r3, [r3, #0xc] */
/* @0x1c8728 blx r3 */
/* @0x1c872c ldr r1, [r7] */
/* @0x1c8730 b 0x1c86b8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x11e8> */
/* @0x1c8734 eoreq r12, r2, r0, asr r10 */
/* @0x1c8738 eoreq r8, r2, r8, lsl r4 */
/* @0x1c873c eoreq r5, r2, r0 */
/* @0x1c8740 andseq r8, r8, r12, asr #8 */
/* @0x1c8744 push {r3, r4, r5, r6, r7, lr} */
/* @0x1c8748 mov r6, r1 */
/* @0x1c874c mov r5, r0 */
/* @0x1c8750 bl 0x1cc244 <_Z18CollisionIsRemovedP9CInstance> */
/* @0x1c8754 cmp r0, #0 */
/* @0x1c8758 bne 0x1c87c0 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x12f0> */
/* @0x1c875c ldrb r4, [r5, #0x68] */
/* @0x1c8760 cmp r4, #0 */
/* @0x1c8764 beq 0x1c8770 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x12a0> */
/* @0x1c8768 mov r0, r4 */
/* @0x1c876c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c8770 ldrb r4, [r5, #0x69] */
/* @0x1c8774 cmp r4, #0 */
/* @0x1c8778 bne 0x1c8768 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1298> */
/* @0x1c877c ldr r7, [r5, #0x48] */
/* @0x1c8780 cmp r7, #1 */
/* @0x1c8784 bne 0x1c87c0 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x12f0> */
/* @0x1c8788 ldr r2, [r5, #0x78] */
/* @0x1c878c ldr r3, [r6, #0x78] */
/* @0x1c8790 cmp r2, r3 */
/* @0x1c8794 beq 0x1c87cc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x12fc> */
/* @0x1c8798 mov r0, r5 */
/* @0x1c879c mov r1, r6 */
/* @0x1c87a0 mov r2, r7 */
/* @0x1c87a4 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1c87a8 cmp r0, #0 */
/* @0x1c87ac beq 0x1c87cc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x12fc> */
/* @0x1c87b0 ldr r3, [pc, #0x1c] */
/* @0x1c87b4 add r3, pc, r3 */
/* @0x1c87b8 strb r4, [r3, #0x200] */
/* @0x1c87bc b 0x1c8768 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1298> */
/* @0x1c87c0 mov r4, #1 */
/* @0x1c87c4 mov r0, r4 */
/* @0x1c87c8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c87cc mov r4, r7 */
/* @0x1c87d0 b 0x1c8768 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1298> */
/* @0x1c87d4 ldrshteq r9, [r7], -r8 */
/* @0x1c87d8 push {r4, r5, r6, lr} */
/* @0x1c87dc mov r6, r1 */
/* @0x1c87e0 mov r5, r0 */
/* @0x1c87e4 bl 0x1cc244 <_Z18CollisionIsRemovedP9CInstance> */
/* @0x1c87e8 cmp r0, #0 */
/* @0x1c87ec bne 0x1c883c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x136c> */
/* @0x1c87f0 ldrb r4, [r5, #0x68] */
/* @0x1c87f4 cmp r4, #0 */
/* @0x1c87f8 beq 0x1c8804 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1334> */
/* @0x1c87fc mov r0, r4 */
/* @0x1c8800 pop {r4, r5, r6, pc} */
/* @0x1c8804 ldrb r4, [r5, #0x69] */
/* @0x1c8808 cmp r4, #0 */
/* @0x1c880c bne 0x1c87fc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x132c> */
/* @0x1c8810 ldr r2, [r5, #0x48] */
/* @0x1c8814 cmp r2, #1 */
/* @0x1c8818 bne 0x1c883c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x136c> */
/* @0x1c881c ldr r1, [r5, #0x78] */
/* @0x1c8820 ldr r3, [r6, #0x78] */
/* @0x1c8824 cmp r1, r3 */
/* @0x1c8828 moveq r4, r2 */
/* @0x1c882c beq 0x1c87fc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x132c> */
/* @0x1c8830 ldrb r3, [r5, #0x66] */
/* @0x1c8834 cmp r3, #0 */
/* @0x1c8838 bne 0x1c8848 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1378> */
/* @0x1c883c mov r4, #1 */
/* @0x1c8840 mov r0, r4 */
/* @0x1c8844 pop {r4, r5, r6, pc} */
/* @0x1c8848 mov r0, r5 */
/* @0x1c884c mov r1, r6 */
/* @0x1c8850 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1c8854 cmp r0, #0 */
/* @0x1c8858 beq 0x1c883c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x136c> */
/* @0x1c885c ldr r3, [pc, #0x8] */
/* @0x1c8860 add r3, pc, r3 */
/* @0x1c8864 strb r4, [r3, #0x200] */
/* @0x1c8868 b 0x1c87fc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x132c> */
/* @0x1c886c eorseq r9, r7, r12, asr #28 */
/* @0x1c8870 ldr r3, [r1, #0x8] */
/* @0x1c8874 vldr s14, [r0] */
/* @0x1c8878 vldr s15, [r0, #4] */
/* @0x1c887c vldr s10, [r0, #12] */
/* @0x1c8880 add r2, r3, #1 */
/* @0x1c8884 vldr s12, [r0, #8] */
/* @0x1c8888 vmov s13, r2 */
/* @0x1c888c vcvt.f32.s32 s13, s13 */
/* @0x1c8890 vcmpe.f32 s14, s13 */
/* @0x1c8894 vmrs APSR_nzcv, fpscr */
/* @0x1c8898 bge 0x1c8994 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14c4> */
/* @0x1c889c vadd.f32 s12, s14, s12 */
/* @0x1c88a0 vldr s8, [r1] */
/* @0x1c88a4 vcvt.f32.s32 s11, s8 */
/* @0x1c88a8 vcmpe.f32 s12, s11 */
/* @0x1c88ac vmrs APSR_nzcv, fpscr */
/* @0x1c88b0 bmi 0x1c8994 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14c4> */
/* @0x1c88b4 vadd.f32 s13, s15, s10 */
/* @0x1c88b8 ldr r2, [r1, #0xc] */
/* @0x1c88bc add r2, r2, #1 */
/* @0x1c88c0 vmov s9, r2 */
/* @0x1c88c4 vcmpe.f32 s15, s13 */
/* @0x1c88c8 vcvt.f32.s32 s10, s9 */
/* @0x1c88cc vmrs APSR_nzcv, fpscr */
/* @0x1c88d0 vmovpl.f32 s9, s13 */
/* @0x1c88d4 vmovmi.f32 s9, s15 */
/* @0x1c88d8 vcmpe.f32 s10, s9 */
/* @0x1c88dc vmrs APSR_nzcv, fpscr */
/* @0x1c88e0 bls 0x1c8994 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14c4> */
/* @0x1c88e4 vcmpe.f32 s15, s13 */
/* @0x1c88e8 vldr s9, [r1, #4] */
/* @0x1c88ec vcvt.f32.s32 s9, s9 */
/* @0x1c88f0 vmrs APSR_nzcv, fpscr */
/* @0x1c88f4 vmovle.f32 s8, s13 */
/* @0x1c88f8 vmovgt.f32 s8, s15 */
/* @0x1c88fc vcmpe.f32 s9, s8 */
/* @0x1c8900 vmrs APSR_nzcv, fpscr */
/* @0x1c8904 bgt 0x1c8994 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14c4> */
/* @0x1c8908 vcmpe.f32 s14, s11 */
/* @0x1c890c vmrs APSR_nzcv, fpscr */
/* @0x1c8910 bpl 0x1c8930 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1460> */
/* @0x1c8914 vsub.f32 s7, s11, s14 */
/* @0x1c8918 vsub.f32 s8, s13, s15 */
/* @0x1c891c vmul.f32 s7, s7, s8 */
/* @0x1c8920 vsub.f32 s8, s12, s14 */
/* @0x1c8924 vmov.f32 s14, s11 */
/* @0x1c8928 vdiv.f32 s11, s7, s8 */
/* @0x1c892c vadd.f32 s15, s15, s11 */
/* @0x1c8930 vmov s8, r3 */
/* @0x1c8934 vcvt.f32.s32 s11, s8 */
/* @0x1c8938 vcmpe.f32 s12, s11 */
/* @0x1c893c vmrs APSR_nzcv, fpscr */
/* @0x1c8940 ble 0x1c895c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x148c> */
/* @0x1c8944 vsub.f32 s11, s11, s12 */
/* @0x1c8948 vsub.f32 s8, s13, s15 */
/* @0x1c894c vmul.f32 s11, s11, s8 */
/* @0x1c8950 vsub.f32 s12, s12, s14 */
/* @0x1c8954 vdiv.f32 s12, s11, s12 */
/* @0x1c8958 vadd.f32 s13, s13, s12 */
/* @0x1c895c vcmpe.f32 s9, s15 */
/* @0x1c8960 vmrs APSR_nzcv, fpscr */
/* @0x1c8964 ble 0x1c8974 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14a4> */
/* @0x1c8968 vcmpe.f32 s9, s13 */
/* @0x1c896c vmrs APSR_nzcv, fpscr */
/* @0x1c8970 bgt 0x1c8994 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14c4> */
/* @0x1c8974 vcmpe.f32 s10, s15 */
/* @0x1c8978 vmrs APSR_nzcv, fpscr */
/* @0x1c897c bhi 0x1c899c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14cc> */
/* @0x1c8980 vcmpe.f32 s10, s13 */
/* @0x1c8984 vmrs APSR_nzcv, fpscr */
/* @0x1c8988 movls r0, #0 */
/* @0x1c898c movhi r0, #1 */
/* @0x1c8990 bx lr */
/* @0x1c8994 mov r0, #0 */
/* @0x1c8998 bx lr */
/* @0x1c899c mov r0, #1 */
/* @0x1c89a0 bx lr */

/* ── FUNC 0x1c89a4 · Command_CollisionPoint(CInstance*, float, float, int, bool, bool) · size=528 · insn=132 */
/* @0x1c89a4 cmn r3, #3 */
/* @0x1c89a8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1c89ac mov r10, r0 */
/* @0x1c89b0 mov r9, r1 */
/* @0x1c89b4 mov r7, r2 */
/* @0x1c89b8 ldrb r8, [sp, #0x20] */
/* @0x1c89bc ldrb r6, [sp, #0x24] */
/* @0x1c89c0 beq 0x1c8b24 <_Z22Command_CollisionPointP9CInstanceffibb+0x180> */
/* @0x1c89c4 movw r2, #0x869f */
/* @0x1c89c8 movt r2, #0x1 */
/* @0x1c89cc cmp r3, r2 */
/* @0x1c89d0 bgt 0x1c8a9c <_Z22Command_CollisionPointP9CInstanceffibb+0xf8> */
/* @0x1c89d4 ldr r2, [pc, #0x1cc] */
/* @0x1c89d8 ldr r2, [pc, r2] */
/* @0x1c89dc ldr r2, [r2] */
/* @0x1c89e0 ldr r1, [r2, #0x4] */
/* @0x1c89e4 ldr r2, [r2] */
/* @0x1c89e8 and r1, r3, r1 */
/* @0x1c89ec ldr r12, [r2, r1, lsl #3] */
/* @0x1c89f0 cmp r12, #0 */
/* @0x1c89f4 bne 0x1c8a08 <_Z22Command_CollisionPointP9CInstanceffibb+0x64> */
/* @0x1c89f8 b 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c89fc ldr r12, [r12, #0x4] */
/* @0x1c8a00 cmp r12, #0 */
/* @0x1c8a04 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8a08 ldr r2, [r12, #0x8] */
/* @0x1c8a0c cmp r3, r2 */
/* @0x1c8a10 bne 0x1c89fc <_Z22Command_CollisionPointP9CInstanceffibb+0x58> */
/* @0x1c8a14 ldr r3, [r12, #0xc] */
/* @0x1c8a18 cmp r3, #0 */
/* @0x1c8a1c ldrne r4, [r3, #0xd0] */
/* @0x1c8a20 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8a24 cmp r4, #0 */
/* @0x1c8a28 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8a2c ldr r3, [r4, #0x8] */
/* @0x1c8a30 cmp r3, #0 */
/* @0x1c8a34 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8a38 ldr r5, [r4, #0x8] */
/* @0x1c8a3c ldr r4, [r4] */
/* @0x1c8a40 cmp r10, r5 */
/* @0x1c8a44 movne r3, #0 */
/* @0x1c8a48 andeq r3, r6, #1 */
/* @0x1c8a4c cmp r3, #0 */
/* @0x1c8a50 bne 0x1c8a24 <_Z22Command_CollisionPointP9CInstanceffibb+0x80> */
/* @0x1c8a54 ldrb r3, [r5, #0x68] */
/* @0x1c8a58 cmp r3, #0 */
/* @0x1c8a5c bne 0x1c8a24 <_Z22Command_CollisionPointP9CInstanceffibb+0x80> */
/* @0x1c8a60 ldrb r3, [r5, #0x69] */
/* @0x1c8a64 cmp r3, #0 */
/* @0x1c8a68 bne 0x1c8a24 <_Z22Command_CollisionPointP9CInstanceffibb+0x80> */
/* @0x1c8a6c mov r0, r5 */
/* @0x1c8a70 mov r1, r9 */
/* @0x1c8a74 mov r2, r7 */
/* @0x1c8a78 mov r3, r8 */
/* @0x1c8a7c bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c8a80 cmp r0, #0 */
/* @0x1c8a84 bne 0x1c8a94 <_Z22Command_CollisionPointP9CInstanceffibb+0xf0> */
/* @0x1c8a88 cmp r4, #0 */
/* @0x1c8a8c bne 0x1c8a2c <_Z22Command_CollisionPointP9CInstanceffibb+0x88> */
/* @0x1c8a90 mov r5, #0 */
/* @0x1c8a94 mov r0, r5 */
/* @0x1c8a98 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1c8a9c cmp r6, #0 */
/* @0x1c8aa0 bne 0x1c8b98 <_Z22Command_CollisionPointP9CInstanceffibb+0x1f4> */
/* @0x1c8aa4 ldr r2, [pc, #0x100] */
/* @0x1c8aa8 ldr r2, [pc, r2] */
/* @0x1c8aac ldr r1, [r2, #0x4] */
/* @0x1c8ab0 ldr r2, [r2] */
/* @0x1c8ab4 and r1, r3, r1 */
/* @0x1c8ab8 ldr r2, [r2, r1, lsl #3] */
/* @0x1c8abc cmp r2, #0 */
/* @0x1c8ac0 bne 0x1c8ad4 <_Z22Command_CollisionPointP9CInstanceffibb+0x130> */
/* @0x1c8ac4 b 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8ac8 ldr r2, [r2, #0x4] */
/* @0x1c8acc cmp r2, #0 */
/* @0x1c8ad0 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8ad4 ldr r1, [r2, #0x8] */
/* @0x1c8ad8 cmp r3, r1 */
/* @0x1c8adc bne 0x1c8ac8 <_Z22Command_CollisionPointP9CInstanceffibb+0x124> */
/* @0x1c8ae0 ldr r5, [r2, #0xc] */
/* @0x1c8ae4 cmp r5, #0 */
/* @0x1c8ae8 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8aec ldrb r3, [r5, #0x68] */
/* @0x1c8af0 cmp r3, #0 */
/* @0x1c8af4 bne 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8af8 ldrb r3, [r5, #0x69] */
/* @0x1c8afc cmp r3, #0 */
/* @0x1c8b00 bne 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8b04 mov r1, r9 */
/* @0x1c8b08 mov r3, r8 */
/* @0x1c8b0c mov r2, r7 */
/* @0x1c8b10 mov r0, r5 */
/* @0x1c8b14 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c8b18 cmp r0, #0 */
/* @0x1c8b1c bne 0x1c8a94 <_Z22Command_CollisionPointP9CInstanceffibb+0xf0> */
/* @0x1c8b20 b 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8b24 ldr r3, [pc, #0x84] */
/* @0x1c8b28 ldr r3, [pc, r3] */
/* @0x1c8b2c ldr r3, [r3] */
/* @0x1c8b30 ldr r5, [r3, #0x80] */
/* @0x1c8b34 cmp r5, #0 */
/* @0x1c8b38 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8b3c cmp r10, r5 */
/* @0x1c8b40 movne r3, #0 */
/* @0x1c8b44 andeq r3, r6, #1 */
/* @0x1c8b48 ldr r4, [r5, #0x178] */
/* @0x1c8b4c cmp r3, #0 */
/* @0x1c8b50 bne 0x1c8b88 <_Z22Command_CollisionPointP9CInstanceffibb+0x1e4> */
/* @0x1c8b54 ldrb r3, [r5, #0x68] */
/* @0x1c8b58 cmp r3, #0 */
/* @0x1c8b5c bne 0x1c8b88 <_Z22Command_CollisionPointP9CInstanceffibb+0x1e4> */
/* @0x1c8b60 ldrb r3, [r5, #0x69] */
/* @0x1c8b64 cmp r3, #0 */
/* @0x1c8b68 bne 0x1c8b88 <_Z22Command_CollisionPointP9CInstanceffibb+0x1e4> */
/* @0x1c8b6c mov r0, r5 */
/* @0x1c8b70 mov r1, r9 */
/* @0x1c8b74 mov r2, r7 */
/* @0x1c8b78 mov r3, r8 */
/* @0x1c8b7c bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c8b80 cmp r0, #0 */
/* @0x1c8b84 bne 0x1c8a94 <_Z22Command_CollisionPointP9CInstanceffibb+0xf0> */
/* @0x1c8b88 cmp r4, #0 */
/* @0x1c8b8c mov r5, r4 */
/* @0x1c8b90 bne 0x1c8b3c <_Z22Command_CollisionPointP9CInstanceffibb+0x198> */
/* @0x1c8b94 b 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8b98 ldr r2, [r0, #0x78] */
/* @0x1c8b9c cmp r3, r2 */
/* @0x1c8ba0 bne 0x1c8aa4 <_Z22Command_CollisionPointP9CInstanceffibb+0x100> */
/* @0x1c8ba4 b 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8ba8 eoreq r5, r2, r4, ror #4 */
/* @0x1c8bac mlaeq r2, r12, r1, r5 */
/* @0x1c8bb0 eoreq r4, r2, r0, lsl #28 */

/* ── FUNC 0x1c8bb4 · Command_CollisionEllipse(CInstance*, float, float, float, float, int, bool, bool) · size=580 · insn=145 */
/* @0x1c8bb4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c8bb8 vpush {d8} */
/* @0x1c8bbc sub sp, sp, #12 */
/* @0x1c8bc0 vldr s16, [sp, #56] */
/* @0x1c8bc4 mov r11, r0 */
/* @0x1c8bc8 mov r9, r1 */
/* @0x1c8bcc ldr r12, [sp, #0x3c] */
/* @0x1c8bd0 mov r8, r2 */
/* @0x1c8bd4 mov r7, r3 */
/* @0x1c8bd8 ldrb r10, [sp, #0x40] */
/* @0x1c8bdc cmn r12, #3 */
/* @0x1c8be0 ldrb r6, [sp, #0x44] */
/* @0x1c8be4 beq 0x1c8d60 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x1ac> */
/* @0x1c8be8 movw r3, #0x869f */
/* @0x1c8bec movt r3, #0x1 */
/* @0x1c8bf0 cmp r12, r3 */
/* @0x1c8bf4 bgt 0x1c8cd0 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x11c> */
/* @0x1c8bf8 ldr r3, [pc, #0x1ec] */
/* @0x1c8bfc ldr r3, [pc, r3] */
/* @0x1c8c00 ldr r3, [r3] */
/* @0x1c8c04 ldr r2, [r3, #0x4] */
/* @0x1c8c08 ldr r3, [r3] */
/* @0x1c8c0c and r2, r12, r2 */
/* @0x1c8c10 ldr r3, [r3, r2, lsl #3] */
/* @0x1c8c14 cmp r3, #0 */
/* @0x1c8c18 bne 0x1c8c2c <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x78> */
/* @0x1c8c1c b 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8c20 ldr r3, [r3, #0x4] */
/* @0x1c8c24 cmp r3, #0 */
/* @0x1c8c28 beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8c2c ldr r2, [r3, #0x8] */
/* @0x1c8c30 cmp r12, r2 */
/* @0x1c8c34 bne 0x1c8c20 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x6c> */
/* @0x1c8c38 ldr r3, [r3, #0xc] */
/* @0x1c8c3c cmp r3, #0 */
/* @0x1c8c40 ldrne r4, [r3, #0xd0] */
/* @0x1c8c44 beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8c48 cmp r4, #0 */
/* @0x1c8c4c beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8c50 ldr r3, [r4, #0x8] */
/* @0x1c8c54 cmp r3, #0 */
/* @0x1c8c58 beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8c5c ldr r5, [r4, #0x8] */
/* @0x1c8c60 ldr r4, [r4] */
/* @0x1c8c64 cmp r11, r5 */
/* @0x1c8c68 movne r3, #0 */
/* @0x1c8c6c andeq r3, r6, #1 */
/* @0x1c8c70 cmp r3, #0 */
/* @0x1c8c74 bne 0x1c8c48 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x94> */
/* @0x1c8c78 ldrb r3, [r5, #0x68] */
/* @0x1c8c7c cmp r3, #0 */
/* @0x1c8c80 bne 0x1c8c48 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x94> */
/* @0x1c8c84 ldrb r3, [r5, #0x69] */
/* @0x1c8c88 cmp r3, #0 */
/* @0x1c8c8c bne 0x1c8c48 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x94> */
/* @0x1c8c90 vstr s16, [sp] */
/* @0x1c8c94 str r10, [sp, #0x4] */
/* @0x1c8c98 mov r0, r5 */
/* @0x1c8c9c mov r1, r9 */
/* @0x1c8ca0 mov r2, r8 */
/* @0x1c8ca4 mov r3, r7 */
/* @0x1c8ca8 bl 0x194a90 <_ZN9CInstance17Collision_EllipseEffffb> */
/* @0x1c8cac cmp r0, #0 */
/* @0x1c8cb0 bne 0x1c8cc0 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x10c> */
/* @0x1c8cb4 cmp r4, #0 */
/* @0x1c8cb8 bne 0x1c8c50 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x9c> */
/* @0x1c8cbc mov r5, #0 */
/* @0x1c8cc0 mov r0, r5 */
/* @0x1c8cc4 add sp, sp, #12 */
/* @0x1c8cc8 vpop {d8} */
/* @0x1c8ccc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c8cd0 cmp r6, #0 */
/* @0x1c8cd4 bne 0x1c8ddc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x228> */
/* @0x1c8cd8 ldr r3, [pc, #0x110] */
/* @0x1c8cdc ldr r3, [pc, r3] */
/* @0x1c8ce0 ldr r2, [r3, #0x4] */
/* @0x1c8ce4 ldr r3, [r3] */
/* @0x1c8ce8 and r2, r12, r2 */
/* @0x1c8cec ldr r3, [r3, r2, lsl #3] */
/* @0x1c8cf0 cmp r3, #0 */
/* @0x1c8cf4 bne 0x1c8d08 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x154> */
/* @0x1c8cf8 b 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8cfc ldr r3, [r3, #0x4] */
/* @0x1c8d00 cmp r3, #0 */
/* @0x1c8d04 beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8d08 ldr r2, [r3, #0x8] */
/* @0x1c8d0c cmp r12, r2 */
/* @0x1c8d10 bne 0x1c8cfc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x148> */
/* @0x1c8d14 ldr r5, [r3, #0xc] */
/* @0x1c8d18 cmp r5, #0 */
/* @0x1c8d1c beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8d20 ldrb r3, [r5, #0x68] */
/* @0x1c8d24 cmp r3, #0 */
/* @0x1c8d28 bne 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8d2c ldrb r3, [r5, #0x69] */
/* @0x1c8d30 cmp r3, #0 */
/* @0x1c8d34 bne 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8d38 vstr s16, [sp] */
/* @0x1c8d3c str r10, [sp, #0x4] */
/* @0x1c8d40 mov r1, r9 */
/* @0x1c8d44 mov r0, r5 */
/* @0x1c8d48 mov r2, r8 */
/* @0x1c8d4c mov r3, r7 */
/* @0x1c8d50 bl 0x194a90 <_ZN9CInstance17Collision_EllipseEffffb> */
/* @0x1c8d54 cmp r0, #0 */
/* @0x1c8d58 bne 0x1c8cc0 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x10c> */
/* @0x1c8d5c b 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8d60 ldr r3, [pc, #0x8c] */
/* @0x1c8d64 ldr r3, [pc, r3] */
/* @0x1c8d68 ldr r3, [r3] */
/* @0x1c8d6c ldr r5, [r3, #0x80] */
/* @0x1c8d70 cmp r5, #0 */
/* @0x1c8d74 beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8d78 cmp r11, r5 */
/* @0x1c8d7c movne r3, #0 */
/* @0x1c8d80 andeq r3, r6, #1 */
/* @0x1c8d84 ldr r4, [r5, #0x178] */
/* @0x1c8d88 cmp r3, #0 */
/* @0x1c8d8c bne 0x1c8dcc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x218> */
/* @0x1c8d90 ldrb r3, [r5, #0x68] */
/* @0x1c8d94 cmp r3, #0 */
/* @0x1c8d98 bne 0x1c8dcc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x218> */
/* @0x1c8d9c ldrb r3, [r5, #0x69] */
/* @0x1c8da0 cmp r3, #0 */
/* @0x1c8da4 bne 0x1c8dcc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x218> */
/* @0x1c8da8 vstr s16, [sp] */
/* @0x1c8dac str r10, [sp, #0x4] */
/* @0x1c8db0 mov r0, r5 */
/* @0x1c8db4 mov r1, r9 */
/* @0x1c8db8 mov r2, r8 */
/* @0x1c8dbc mov r3, r7 */
/* @0x1c8dc0 bl 0x194a90 <_ZN9CInstance17Collision_EllipseEffffb> */
/* @0x1c8dc4 cmp r0, #0 */
/* @0x1c8dc8 bne 0x1c8cc0 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x10c> */
/* @0x1c8dcc cmp r4, #0 */
/* @0x1c8dd0 mov r5, r4 */
/* @0x1c8dd4 bne 0x1c8d78 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x1c4> */
/* @0x1c8dd8 b 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8ddc ldr r3, [r0, #0x78] */
/* @0x1c8de0 cmp r12, r3 */
/* @0x1c8de4 bne 0x1c8cd8 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x124> */
/* @0x1c8de8 b 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8dec eoreq r5, r2, r0, asr #32 */
/* @0x1c8df0 eoreq r4, r2, r8, ror #30 */
/* @0x1c8df4 eoreq r4, r2, r4, asr #23 */

/* ── FUNC 0x1c8df8 · ShouldUseFastCollision(int, CObjectGM**) · size=216 · insn=54 */
/* @0x1c8df8 movw r3, #0x869f */
/* @0x1c8dfc movt r3, #0x1 */
/* @0x1c8e00 cmp r0, r3 */
/* @0x1c8e04 ble 0x1c8e10 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0x18> */
/* @0x1c8e08 mov r0, #2 */
/* @0x1c8e0c bx lr */
/* @0x1c8e10 ldr r3, [pc, #0xac] */
/* @0x1c8e14 ldr r3, [pc, r3] */
/* @0x1c8e18 ldrb r3, [r3] */
/* @0x1c8e1c cmp r3, #0 */
/* @0x1c8e20 beq 0x1c8e08 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0x10> */
/* @0x1c8e24 cmn r0, #3 */
/* @0x1c8e28 beq 0x1c8eb4 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0xbc> */
/* @0x1c8e2c ldr r3, [pc, #0x94] */
/* @0x1c8e30 ldr r3, [pc, r3] */
/* @0x1c8e34 ldr r3, [r3] */
/* @0x1c8e38 ldr r2, [r3, #0x4] */
/* @0x1c8e3c ldr r3, [r3] */
/* @0x1c8e40 and r2, r0, r2 */
/* @0x1c8e44 ldr r3, [r3, r2, lsl #3] */
/* @0x1c8e48 cmp r3, #0 */
/* @0x1c8e4c bne 0x1c8e60 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0x68> */
/* @0x1c8e50 b 0x1c8ea4 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0xac> */
/* @0x1c8e54 ldr r3, [r3, #0x4] */
/* @0x1c8e58 cmp r3, #0 */
/* @0x1c8e5c beq 0x1c8ea4 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0xac> */
/* @0x1c8e60 ldr r2, [r3, #0x8] */
/* @0x1c8e64 cmp r0, r2 */
/* @0x1c8e68 bne 0x1c8e54 <_Z22ShouldUseFastCollisioniPP9CObjectGM+0x5c> */
/* @0x1c8e6c ldr r2, [r3, #0xc] */
/* @0x1c8e70 cmp r2, #0 */
/* @0x1c8e74 str r2, [r1] */
/* @0x1c8e78 beq 0x1c8ebc <_Z22ShouldUseFastCollisioniPP9CObjectGM+0xc4> */
/* @0x1c8e7c ldr r3, [pc, #0x48] */
/* @0x1c8e80 ldr r0, [r2, #0xd8] */
/* @0x1c8e84 ldr r3, [pc, r3] */
/* @0x1c8e88 ldr r3, [r3] */
/* @0x1c8e8c ldr r3, [r3, #0x10] */
/* @0x1c8e90 ldr r3, [r3, #0x4] */
/* @0x1c8e94 cmp r0, r3 */
/* @0x1c8e98 movge r0, #1 */
/* @0x1c8e9c movlt r0, #2 */
/* @0x1c8ea0 bx lr */
/* @0x1c8ea4 mov r3, #0 */
/* @0x1c8ea8 mvn r0, #0 */
/* @0x1c8eac str r3, [r1] */
/* @0x1c8eb0 bx lr */
/* @0x1c8eb4 mov r0, #1 */
/* @0x1c8eb8 bx lr */
/* @0x1c8ebc mvn r0, #0 */
/* @0x1c8ec0 bx lr */
/* @0x1c8ec4 eoreq r7, r2, r12, ror #16 */
/* @0x1c8ec8 eoreq r4, r2, r12, lsl #28 */
/* @0x1c8ecc eoreq r5, r2, r0, asr #7 */

/* ── FUNC 0x1c8ed0 · Command_InstanceNumber(int) · size=508 · insn=127 */
/* @0x1c8ed0 push {r4, r5} */
/* @0x1c8ed4 cmn r0, #3 */
/* @0x1c8ed8 ldr r4, [pc, #0x1d8] */
/* @0x1c8edc add r4, pc, r4 */
/* @0x1c8ee0 beq 0x1c8ff4 <_Z22Command_InstanceNumberi+0x124> */
/* @0x1c8ee4 movw r3, #0x869f */
/* @0x1c8ee8 movt r3, #0x1 */
/* @0x1c8eec cmp r0, r3 */
/* @0x1c8ef0 bgt 0x1c9040 <_Z22Command_InstanceNumberi+0x170> */
/* @0x1c8ef4 ldr r3, [pc, #0x1c0] */
/* @0x1c8ef8 ldr r3, [r4, r3] */
/* @0x1c8efc ldr r3, [r3] */
/* @0x1c8f00 ldr r2, [r3, #0x4] */
/* @0x1c8f04 ldr r3, [r3] */
/* @0x1c8f08 and r2, r0, r2 */
/* @0x1c8f0c ldr r3, [r3, r2, lsl #3] */
/* @0x1c8f10 cmp r3, #0 */
/* @0x1c8f14 bne 0x1c8f30 <_Z22Command_InstanceNumberi+0x60> */
/* @0x1c8f18 mov r0, r3 */
/* @0x1c8f1c pop {r4, r5} */
/* @0x1c8f20 bx lr */
/* @0x1c8f24 ldr r3, [r3, #0x4] */
/* @0x1c8f28 cmp r3, #0 */
/* @0x1c8f2c beq 0x1c8f18 <_Z22Command_InstanceNumberi+0x48> */
/* @0x1c8f30 ldr r2, [r3, #0x8] */
/* @0x1c8f34 cmp r0, r2 */
/* @0x1c8f38 bne 0x1c8f24 <_Z22Command_InstanceNumberi+0x54> */
/* @0x1c8f3c ldr r3, [r3, #0xc] */
/* @0x1c8f40 cmp r3, #0 */
/* @0x1c8f44 beq 0x1c8f18 <_Z22Command_InstanceNumberi+0x48> */
/* @0x1c8f48 ldr r2, [r3, #0xd0] */
/* @0x1c8f4c cmp r2, #0 */
/* @0x1c8f50 beq 0x1c90a8 <_Z22Command_InstanceNumberi+0x1d8> */
/* @0x1c8f54 ldr r3, [r2, #0x8] */
/* @0x1c8f58 cmp r3, #0 */
/* @0x1c8f5c beq 0x1c8f9c <_Z22Command_InstanceNumberi+0xcc> */
/* @0x1c8f60 mov r3, #0 */
/* @0x1c8f64 b 0x1c8f74 <_Z22Command_InstanceNumberi+0xa4> */
/* @0x1c8f68 ldr r1, [r2, #0x8] */
/* @0x1c8f6c cmp r1, #0 */
/* @0x1c8f70 beq 0x1c8f9c <_Z22Command_InstanceNumberi+0xcc> */
/* @0x1c8f74 ldr r1, [r2, #0x8] */
/* @0x1c8f78 ldr r2, [r2] */
/* @0x1c8f7c ldrb r12, [r1, #0x68] */
/* @0x1c8f80 cmp r12, #0 */
/* @0x1c8f84 bne 0x1c8f94 <_Z22Command_InstanceNumberi+0xc4> */
/* @0x1c8f88 ldrb r1, [r1, #0x69] */
/* @0x1c8f8c cmp r1, #0 */
/* @0x1c8f90 addeq r3, r3, #1 */
/* @0x1c8f94 cmp r2, #0 */
/* @0x1c8f98 bne 0x1c8f68 <_Z22Command_InstanceNumberi+0x98> */
/* @0x1c8f9c ldr r2, [pc, #0x11c] */
/* @0x1c8fa0 ldr r5, [r4, r2] */
/* @0x1c8fa4 ldr r4, [r5, #0x8] */
/* @0x1c8fa8 cmp r4, #0 */
/* @0x1c8fac ble 0x1c8f18 <_Z22Command_InstanceNumberi+0x48> */
/* @0x1c8fb0 mov r2, #0 */
/* @0x1c8fb4 b 0x1c8fc4 <_Z22Command_InstanceNumberi+0xf4> */
/* @0x1c8fb8 add r2, r2, #1 */
/* @0x1c8fbc cmp r2, r4 */
/* @0x1c8fc0 beq 0x1c8f18 <_Z22Command_InstanceNumberi+0x48> */
/* @0x1c8fc4 ldr r1, [r5] */
/* @0x1c8fc8 ldr r1, [r1, r2, lsl #2] */
/* @0x1c8fcc ldr r12, [r1, #0x7c] */
/* @0x1c8fd0 cmp r0, r12 */
/* @0x1c8fd4 bne 0x1c8fb8 <_Z22Command_InstanceNumberi+0xe8> */
/* @0x1c8fd8 ldrb r12, [r1, #0x68] */
/* @0x1c8fdc cmp r12, #0 */
/* @0x1c8fe0 bne 0x1c8fb8 <_Z22Command_InstanceNumberi+0xe8> */
/* @0x1c8fe4 ldrb r1, [r1, #0x69] */
/* @0x1c8fe8 cmp r1, #0 */
/* @0x1c8fec addeq r3, r3, #1 */
/* @0x1c8ff0 b 0x1c8fb8 <_Z22Command_InstanceNumberi+0xe8> */
/* @0x1c8ff4 ldr r3, [pc, #0xc8] */
/* @0x1c8ff8 ldr r3, [r4, r3] */
/* @0x1c8ffc ldr r3, [r3] */
/* @0x1c9000 ldr r2, [r3, #0x80] */
/* @0x1c9004 cmp r2, #0 */
/* @0x1c9008 beq 0x1c90b0 <_Z22Command_InstanceNumberi+0x1e0> */
/* @0x1c900c mov r0, #0 */
/* @0x1c9010 ldrb r12, [r2, #0x68] */
/* @0x1c9014 ldr r1, [r2, #0x178] */
/* @0x1c9018 cmp r12, #0 */
/* @0x1c901c bne 0x1c902c <_Z22Command_InstanceNumberi+0x15c> */
/* @0x1c9020 ldrb r12, [r2, #0x69] */
/* @0x1c9024 cmp r12, #0 */
/* @0x1c9028 addeq r0, r0, #1 */
/* @0x1c902c cmp r1, #0 */
/* @0x1c9030 mov r2, r1 */
/* @0x1c9034 bne 0x1c9010 <_Z22Command_InstanceNumberi+0x140> */
/* @0x1c9038 pop {r4, r5} */
/* @0x1c903c bx lr */
/* @0x1c9040 ldr r3, [pc, #0x80] */
/* @0x1c9044 ldr r3, [r4, r3] */
/* @0x1c9048 ldr r2, [r3, #0x4] */
/* @0x1c904c ldr r3, [r3] */
/* @0x1c9050 and r2, r0, r2 */
/* @0x1c9054 ldr r3, [r3, r2, lsl #3] */
/* @0x1c9058 cmp r3, #0 */
/* @0x1c905c beq 0x1c8f18 <_Z22Command_InstanceNumberi+0x48> */
/* @0x1c9060 ldr r2, [r3, #0x8] */
/* @0x1c9064 cmp r0, r2 */
/* @0x1c9068 beq 0x1c9084 <_Z22Command_InstanceNumberi+0x1b4> */
/* @0x1c906c ldr r3, [r3, #0x4] */
/* @0x1c9070 cmp r3, #0 */
/* @0x1c9074 beq 0x1c8f18 <_Z22Command_InstanceNumberi+0x48> */
/* @0x1c9078 ldr r2, [r3, #0x8] */
/* @0x1c907c cmp r0, r2 */
/* @0x1c9080 bne 0x1c906c <_Z22Command_InstanceNumberi+0x19c> */
/* @0x1c9084 ldr r0, [r3, #0xc] */
/* @0x1c9088 cmp r0, #0 */
/* @0x1c908c beq 0x1c8f1c <_Z22Command_InstanceNumberi+0x4c> */
/* @0x1c9090 ldrb r3, [r0, #0x68] */
/* @0x1c9094 cmp r3, #0 */
/* @0x1c9098 movne r0, #0 */
/* @0x1c909c ldrbeq r0, [r0, #0x69] */
/* @0x1c90a0 eoreq r0, r0, #1 */
/* @0x1c90a4 b 0x1c8f1c <_Z22Command_InstanceNumberi+0x4c> */
/* @0x1c90a8 mov r3, r2 */
/* @0x1c90ac b 0x1c8f9c <_Z22Command_InstanceNumberi+0xcc> */
/* @0x1c90b0 mov r0, r2 */
/* @0x1c90b4 b 0x1c8f1c <_Z22Command_InstanceNumberi+0x4c> */
/* @0x1c90b8 eoreq r8, r2, r4, ror sp */
/* @0x1c90bc .word 0xffffbfec */
/* @0x1c90c0 .word 0xffffbff0 */
/* @0x1c90c4 .word 0xffffbcd8 */
/* @0x1c90c8 .word 0xffffbff4 */

/* ── FUNC 0x1c90cc · Command_InstancePosition(float, float, int) · size=452 · insn=113 */
/* @0x1c90cc cmn r2, #3 */
/* @0x1c90d0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1c90d4 mov r7, r0 */
/* @0x1c90d8 mov r6, r1 */
/* @0x1c90dc beq 0x1c919c <_Z24Command_InstancePositionffi+0xd0> */
/* @0x1c90e0 movw r3, #0x869f */
/* @0x1c90e4 movt r3, #0x1 */
/* @0x1c90e8 cmp r2, r3 */
/* @0x1c90ec bgt 0x1c91fc <_Z24Command_InstancePositionffi+0x130> */
/* @0x1c90f0 ldr r3, [pc, #0x18c] */
/* @0x1c90f4 ldr r3, [pc, r3] */
/* @0x1c90f8 ldr r3, [r3] */
/* @0x1c90fc ldr r1, [r3, #0x4] */
/* @0x1c9100 ldr r3, [r3] */
/* @0x1c9104 and r1, r2, r1 */
/* @0x1c9108 ldr r3, [r3, r1, lsl #3] */
/* @0x1c910c cmp r3, #0 */
/* @0x1c9110 bne 0x1c912c <_Z24Command_InstancePositionffi+0x60> */
/* @0x1c9114 mov r5, #0 */
/* @0x1c9118 mov r0, r5 */
/* @0x1c911c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c9120 ldr r3, [r3, #0x4] */
/* @0x1c9124 cmp r3, #0 */
/* @0x1c9128 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c912c ldr r1, [r3, #0x8] */
/* @0x1c9130 cmp r2, r1 */
/* @0x1c9134 bne 0x1c9120 <_Z24Command_InstancePositionffi+0x54> */
/* @0x1c9138 ldr r3, [r3, #0xc] */
/* @0x1c913c cmp r3, #0 */
/* @0x1c9140 ldrne r4, [r3, #0xd0] */
/* @0x1c9144 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c9148 cmp r4, #0 */
/* @0x1c914c beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c9150 ldr r3, [r4, #0x8] */
/* @0x1c9154 cmp r3, #0 */
/* @0x1c9158 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c915c ldr r5, [r4, #0x8] */
/* @0x1c9160 ldr r4, [r4] */
/* @0x1c9164 ldrb r3, [r5, #0x68] */
/* @0x1c9168 cmp r3, #0 */
/* @0x1c916c bne 0x1c9148 <_Z24Command_InstancePositionffi+0x7c> */
/* @0x1c9170 ldrb r3, [r5, #0x69] */
/* @0x1c9174 cmp r3, #0 */
/* @0x1c9178 bne 0x1c9148 <_Z24Command_InstancePositionffi+0x7c> */
/* @0x1c917c mov r3, #1 */
/* @0x1c9180 mov r0, r5 */
/* @0x1c9184 mov r1, r7 */
/* @0x1c9188 mov r2, r6 */
/* @0x1c918c bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c9190 cmp r0, #0 */
/* @0x1c9194 beq 0x1c9148 <_Z24Command_InstancePositionffi+0x7c> */
/* @0x1c9198 b 0x1c9118 <_Z24Command_InstancePositionffi+0x4c> */
/* @0x1c919c ldr r3, [pc, #0xe4] */
/* @0x1c91a0 ldr r3, [pc, r3] */
/* @0x1c91a4 ldr r3, [r3] */
/* @0x1c91a8 ldr r5, [r3, #0x80] */
/* @0x1c91ac cmp r5, #0 */
/* @0x1c91b0 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c91b4 ldrb r3, [r5, #0x68] */
/* @0x1c91b8 ldr r4, [r5, #0x178] */
/* @0x1c91bc cmp r3, #0 */
/* @0x1c91c0 bne 0x1c91ec <_Z24Command_InstancePositionffi+0x120> */
/* @0x1c91c4 ldrb r3, [r5, #0x69] */
/* @0x1c91c8 cmp r3, #0 */
/* @0x1c91cc bne 0x1c91ec <_Z24Command_InstancePositionffi+0x120> */
/* @0x1c91d0 mov r3, #1 */
/* @0x1c91d4 mov r0, r5 */
/* @0x1c91d8 mov r1, r7 */
/* @0x1c91dc mov r2, r6 */
/* @0x1c91e0 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c91e4 cmp r0, #0 */
/* @0x1c91e8 bne 0x1c9118 <_Z24Command_InstancePositionffi+0x4c> */
/* @0x1c91ec cmp r4, #0 */
/* @0x1c91f0 mov r5, r4 */
/* @0x1c91f4 bne 0x1c91b4 <_Z24Command_InstancePositionffi+0xe8> */
/* @0x1c91f8 b 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c91fc ldr r3, [pc, #0x88] */
/* @0x1c9200 ldr r3, [pc, r3] */
/* @0x1c9204 ldr r1, [r3, #0x4] */
/* @0x1c9208 ldr r3, [r3] */
/* @0x1c920c and r1, r2, r1 */
/* @0x1c9210 ldr r3, [r3, r1, lsl #3] */
/* @0x1c9214 cmp r3, #0 */
/* @0x1c9218 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c921c ldr r1, [r3, #0x8] */
/* @0x1c9220 cmp r2, r1 */
/* @0x1c9224 beq 0x1c9240 <_Z24Command_InstancePositionffi+0x174> */
/* @0x1c9228 ldr r3, [r3, #0x4] */
/* @0x1c922c cmp r3, #0 */
/* @0x1c9230 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c9234 ldr r1, [r3, #0x8] */
/* @0x1c9238 cmp r2, r1 */
/* @0x1c923c bne 0x1c9228 <_Z24Command_InstancePositionffi+0x15c> */
/* @0x1c9240 ldr r5, [r3, #0xc] */
/* @0x1c9244 cmp r5, #0 */
/* @0x1c9248 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c924c ldrb r3, [r5, #0x68] */
/* @0x1c9250 cmp r3, #0 */
/* @0x1c9254 bne 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c9258 ldrb r3, [r5, #0x69] */
/* @0x1c925c cmp r3, #0 */
/* @0x1c9260 bne 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c9264 mov r1, r7 */
/* @0x1c9268 mov r0, r5 */
/* @0x1c926c mov r2, r6 */
/* @0x1c9270 mov r3, #1 */
/* @0x1c9274 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c9278 cmp r0, #0 */
/* @0x1c927c bne 0x1c9118 <_Z24Command_InstancePositionffi+0x4c> */
/* @0x1c9280 b 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c9284 eoreq r4, r2, r8, asr #22 */
/* @0x1c9288 eoreq r4, r2, r8, lsl #15 */
/* @0x1c928c eoreq r4, r2, r4, asr #20 */

/* ── FUNC 0x1c9290 · Command_InstanceNearest(float, float, int) · size=388 · insn=97 */
/* @0x1c9290 cmn r2, #3 */
/* @0x1c9294 vmov s13, r0 */
/* @0x1c9298 vmov s12, r1 */
/* @0x1c929c beq 0x1c9380 <_Z23Command_InstanceNearestffi+0xf0> */
/* @0x1c92a0 movw r3, #0x869f */
/* @0x1c92a4 movt r3, #0x1 */
/* @0x1c92a8 cmp r2, r3 */
/* @0x1c92ac bgt 0x1c93fc <_Z23Command_InstanceNearestffi+0x16c> */
/* @0x1c92b0 ldr r3, [pc, #0x154] */
/* @0x1c92b4 ldr r3, [pc, r3] */
/* @0x1c92b8 ldr r3, [r3] */
/* @0x1c92bc ldr r1, [r3, #0x4] */
/* @0x1c92c0 ldr r3, [r3] */
/* @0x1c92c4 and r1, r2, r1 */
/* @0x1c92c8 ldr r0, [r3, r1, lsl #3] */
/* @0x1c92cc cmp r0, #0 */
/* @0x1c92d0 bne 0x1c92e4 <_Z23Command_InstanceNearestffi+0x54> */
/* @0x1c92d4 bx lr */
/* @0x1c92d8 ldr r0, [r0, #0x4] */
/* @0x1c92dc cmp r0, #0 */
/* @0x1c92e0 beq 0x1c937c <_Z23Command_InstanceNearestffi+0xec> */
/* @0x1c92e4 ldr r3, [r0, #0x8] */
/* @0x1c92e8 cmp r2, r3 */
/* @0x1c92ec bne 0x1c92d8 <_Z23Command_InstanceNearestffi+0x48> */
/* @0x1c92f0 ldr r0, [r0, #0xc] */
/* @0x1c92f4 cmp r0, #0 */
/* @0x1c92f8 beq 0x1c9404 <_Z23Command_InstanceNearestffi+0x174> */
/* @0x1c92fc ldr r3, [r0, #0xd0] */
/* @0x1c9300 cmp r3, #0 */
/* @0x1c9304 beq 0x1c93f4 <_Z23Command_InstanceNearestffi+0x164> */
/* @0x1c9308 ldr r0, [r3, #0x8] */
/* @0x1c930c cmp r0, #0 */
/* @0x1c9310 bxeq lr */
/* @0x1c9314 mov r0, #0 */
/* @0x1c9318 vldr s11, [pc, #232] */
/* @0x1c931c ldr r2, [r3, #0x8] */
/* @0x1c9320 ldr r3, [r3] */
/* @0x1c9324 ldrb r1, [r2, #0x68] */
/* @0x1c9328 cmp r1, #0 */
/* @0x1c932c bne 0x1c9364 <_Z23Command_InstanceNearestffi+0xd4> */
/* @0x1c9330 ldrb r1, [r2, #0x69] */
/* @0x1c9334 cmp r1, #0 */
/* @0x1c9338 bne 0x1c9364 <_Z23Command_InstanceNearestffi+0xd4> */
/* @0x1c933c vldr s15, [r2, #184] */
/* @0x1c9340 vsub.f32 s15, s15, s12 */
/* @0x1c9344 vldr s14, [r2, #180] */
/* @0x1c9348 vmul.f32 s15, s15, s15 */
/* @0x1c934c vsub.f32 s14, s14, s13 */
/* @0x1c9350 vmla.f32 s15, s14, s14 */
/* @0x1c9354 vcmpe.f32 s15, s11 */
/* @0x1c9358 vmrs APSR_nzcv, fpscr */
/* @0x1c935c vmovmi.f32 s11, s15 */
/* @0x1c9360 movmi r0, r2 */
/* @0x1c9364 cmp r3, #0 */
/* @0x1c9368 bxeq lr */
/* @0x1c936c ldr r2, [r3, #0x8] */
/* @0x1c9370 cmp r2, #0 */
/* @0x1c9374 bne 0x1c931c <_Z23Command_InstanceNearestffi+0x8c> */
/* @0x1c9378 bx lr */
/* @0x1c937c bx lr */
/* @0x1c9380 ldr r3, [pc, #0x88] */
/* @0x1c9384 ldr r3, [pc, r3] */
/* @0x1c9388 ldr r3, [r3] */
/* @0x1c938c ldr r3, [r3, #0x80] */
/* @0x1c9390 cmp r3, #0 */
/* @0x1c9394 beq 0x1c93f4 <_Z23Command_InstanceNearestffi+0x164> */
/* @0x1c9398 mov r0, #0 */
/* @0x1c939c vldr s11, [pc, #100] */
/* @0x1c93a0 ldrb r1, [r3, #0x68] */
/* @0x1c93a4 ldr r2, [r3, #0x178] */
/* @0x1c93a8 cmp r1, #0 */
/* @0x1c93ac bne 0x1c93e4 <_Z23Command_InstanceNearestffi+0x154> */
/* @0x1c93b0 ldrb r1, [r3, #0x69] */
/* @0x1c93b4 cmp r1, #0 */
/* @0x1c93b8 bne 0x1c93e4 <_Z23Command_InstanceNearestffi+0x154> */
/* @0x1c93bc vldr s15, [r3, #184] */
/* @0x1c93c0 vsub.f32 s15, s15, s12 */
/* @0x1c93c4 vldr s14, [r3, #180] */
/* @0x1c93c8 vmul.f32 s15, s15, s15 */
/* @0x1c93cc vsub.f32 s14, s14, s13 */
/* @0x1c93d0 vmla.f32 s15, s14, s14 */
/* @0x1c93d4 vcmpe.f32 s11, s15 */
/* @0x1c93d8 vmrs APSR_nzcv, fpscr */
/* @0x1c93dc vmovgt.f32 s11, s15 */
/* @0x1c93e0 movgt r0, r3 */
/* @0x1c93e4 cmp r2, #0 */
/* @0x1c93e8 mov r3, r2 */
/* @0x1c93ec bne 0x1c93a0 <_Z23Command_InstanceNearestffi+0x110> */
/* @0x1c93f0 bx lr */
/* @0x1c93f4 mov r0, r3 */
/* @0x1c93f8 bx lr */
/* @0x1c93fc mov r0, #0 */
/* @0x1c9400 bx lr */
/* @0x1c9404 bx lr */
/* @0x1c9408 svcvc #0x7fffff */
/* @0x1c940c eoreq r4, r2, r8, lsl #19 */
/* @0x1c9410 eoreq r4, r2, r4, lsr #11 */

/* ── FUNC 0x1c9414 · Command_InstanceFurthest(float, float, int) · size=384 · insn=96 */
/* @0x1c9414 cmn r2, #3 */
/* @0x1c9418 vmov s13, r0 */
/* @0x1c941c vmov s12, r1 */
/* @0x1c9420 beq 0x1c9504 <_Z24Command_InstanceFurthestffi+0xf0> */
/* @0x1c9424 movw r3, #0x869f */
/* @0x1c9428 movt r3, #0x1 */
/* @0x1c942c cmp r2, r3 */
/* @0x1c9430 bgt 0x1c9580 <_Z24Command_InstanceFurthestffi+0x16c> */
/* @0x1c9434 ldr r3, [pc, #0x150] */
/* @0x1c9438 ldr r3, [pc, r3] */
/* @0x1c943c ldr r3, [r3] */
/* @0x1c9440 ldr r1, [r3, #0x4] */
/* @0x1c9444 ldr r3, [r3] */
/* @0x1c9448 and r1, r2, r1 */
/* @0x1c944c ldr r0, [r3, r1, lsl #3] */
/* @0x1c9450 cmp r0, #0 */
/* @0x1c9454 bne 0x1c9468 <_Z24Command_InstanceFurthestffi+0x54> */
/* @0x1c9458 bx lr */
/* @0x1c945c ldr r0, [r0, #0x4] */
/* @0x1c9460 cmp r0, #0 */
/* @0x1c9464 beq 0x1c9500 <_Z24Command_InstanceFurthestffi+0xec> */
/* @0x1c9468 ldr r3, [r0, #0x8] */
/* @0x1c946c cmp r2, r3 */
/* @0x1c9470 bne 0x1c945c <_Z24Command_InstanceFurthestffi+0x48> */
/* @0x1c9474 ldr r0, [r0, #0xc] */
/* @0x1c9478 cmp r0, #0 */
/* @0x1c947c beq 0x1c9588 <_Z24Command_InstanceFurthestffi+0x174> */
/* @0x1c9480 ldr r3, [r0, #0xd0] */
/* @0x1c9484 cmp r3, #0 */
/* @0x1c9488 beq 0x1c9578 <_Z24Command_InstanceFurthestffi+0x164> */
/* @0x1c948c ldr r0, [r3, #0x8] */
/* @0x1c9490 cmp r0, #0 */
/* @0x1c9494 bxeq lr */
/* @0x1c9498 vmov.f32 s11, #-1.000000e+00 */
/* @0x1c949c mov r0, #0 */
/* @0x1c94a0 ldr r2, [r3, #0x8] */
/* @0x1c94a4 ldr r3, [r3] */
/* @0x1c94a8 ldrb r1, [r2, #0x68] */
/* @0x1c94ac cmp r1, #0 */
/* @0x1c94b0 bne 0x1c94e8 <_Z24Command_InstanceFurthestffi+0xd4> */
/* @0x1c94b4 ldrb r1, [r2, #0x69] */
/* @0x1c94b8 cmp r1, #0 */
/* @0x1c94bc bne 0x1c94e8 <_Z24Command_InstanceFurthestffi+0xd4> */
/* @0x1c94c0 vldr s15, [r2, #184] */
/* @0x1c94c4 vsub.f32 s15, s15, s12 */
/* @0x1c94c8 vldr s14, [r2, #180] */
/* @0x1c94cc vmul.f32 s15, s15, s15 */
/* @0x1c94d0 vsub.f32 s14, s14, s13 */
/* @0x1c94d4 vmla.f32 s15, s14, s14 */
/* @0x1c94d8 vcmpe.f32 s15, s11 */
/* @0x1c94dc vmrs APSR_nzcv, fpscr */
/* @0x1c94e0 vmovgt.f32 s11, s15 */
/* @0x1c94e4 movgt r0, r2 */
/* @0x1c94e8 cmp r3, #0 */
/* @0x1c94ec bxeq lr */
/* @0x1c94f0 ldr r2, [r3, #0x8] */
/* @0x1c94f4 cmp r2, #0 */
/* @0x1c94f8 bne 0x1c94a0 <_Z24Command_InstanceFurthestffi+0x8c> */
/* @0x1c94fc bx lr */
/* @0x1c9500 bx lr */
/* @0x1c9504 ldr r3, [pc, #0x84] */
/* @0x1c9508 ldr r3, [pc, r3] */
/* @0x1c950c ldr r3, [r3] */
/* @0x1c9510 ldr r3, [r3, #0x80] */
/* @0x1c9514 cmp r3, #0 */
/* @0x1c9518 beq 0x1c9578 <_Z24Command_InstanceFurthestffi+0x164> */
/* @0x1c951c vmov.f32 s11, #-1.000000e+00 */
/* @0x1c9520 mov r0, #0 */
/* @0x1c9524 ldrb r1, [r3, #0x68] */
/* @0x1c9528 ldr r2, [r3, #0x178] */
/* @0x1c952c cmp r1, #0 */
/* @0x1c9530 bne 0x1c9568 <_Z24Command_InstanceFurthestffi+0x154> */
/* @0x1c9534 ldrb r1, [r3, #0x69] */
/* @0x1c9538 cmp r1, #0 */
/* @0x1c953c bne 0x1c9568 <_Z24Command_InstanceFurthestffi+0x154> */
/* @0x1c9540 vldr s15, [r3, #184] */
/* @0x1c9544 vsub.f32 s15, s15, s12 */
/* @0x1c9548 vldr s14, [r3, #180] */
/* @0x1c954c vmul.f32 s15, s15, s15 */
/* @0x1c9550 vsub.f32 s14, s14, s13 */
/* @0x1c9554 vmla.f32 s15, s14, s14 */
/* @0x1c9558 vcmpe.f32 s11, s15 */
/* @0x1c955c vmrs APSR_nzcv, fpscr */
/* @0x1c9560 vmovmi.f32 s11, s15 */
/* @0x1c9564 movmi r0, r3 */
/* @0x1c9568 cmp r2, #0 */
/* @0x1c956c mov r3, r2 */
/* @0x1c9570 bne 0x1c9524 <_Z24Command_InstanceFurthestffi+0x110> */
/* @0x1c9574 bx lr */
/* @0x1c9578 mov r0, r3 */
/* @0x1c957c bx lr */
/* @0x1c9580 mov r0, #0 */
/* @0x1c9584 bx lr */
/* @0x1c9588 bx lr */
/* @0x1c958c eoreq r4, r2, r4, lsl #16 */
/* @0x1c9590 eoreq r4, r2, r0, lsr #8 */

/* ── FUNC 0x1c9594 · Command_Snap(CInstance*, float, float) · size=136 · insn=34 */
/* @0x1c9594 push {r4, lr} */
/* @0x1c9598 vpush {d8, d9} */
/* @0x1c959c vmov s18, r1 */
/* @0x1c95a0 vldr s17, [r0, #180] */
/* @0x1c95a4 mov r4, r0 */
/* @0x1c95a8 vmov s16, r2 */
/* @0x1c95ac vcmpe.f32 s18, #0 */
/* @0x1c95b0 vldr s19, [r0, #184] */
/* @0x1c95b4 vmrs APSR_nzcv, fpscr */
/* @0x1c95b8 ble 0x1c95d8 <_Z12Command_SnapP9CInstanceff+0x44> */
/* @0x1c95bc vdiv.f32 s17, s17, s18 */
/* @0x1c95c0 vcvt.f64.f32 d6, s17 */
/* @0x1c95c4 vmov r0, r1, d6 */
/* @0x1c95c8 bl 0xb66e8 <lrint@plt> */
/* @0x1c95cc vmov s13, r0 */
/* @0x1c95d0 vcvt.f32.s32 s17, s13 */
/* @0x1c95d4 vmul.f32 s17, s17, s18 */
/* @0x1c95d8 vcmpe.f32 s16, #0 */
/* @0x1c95dc vmrs APSR_nzcv, fpscr */
/* @0x1c95e0 ble 0x1c9604 <_Z12Command_SnapP9CInstanceff+0x70> */
/* @0x1c95e4 vldr s15, [r4, #184] */
/* @0x1c95e8 vdiv.f32 s15, s15, s16 */
/* @0x1c95ec vcvt.f64.f32 d6, s15 */
/* @0x1c95f0 vmov r0, r1, d6 */
/* @0x1c95f4 bl 0xb66e8 <lrint@plt> */
/* @0x1c95f8 vmov s13, r0 */
/* @0x1c95fc vcvt.f32.s32 s19, s13 */
/* @0x1c9600 vmul.f32 s19, s19, s16 */
/* @0x1c9604 vmov r1, s17 */
/* @0x1c9608 mov r0, r4 */
/* @0x1c960c vmov r2, s19 */
/* @0x1c9610 vpop {d8, d9} */
/* @0x1c9614 pop {r4, lr} */
/* @0x1c9618 b 0x193e7c <_ZN9CInstance11SetPositionEff> */
