/* libyoyo.so 覆盖卡组 0262
 * 函数 0x2b33a4..0x2bb0f8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2b33a4 · anon_2b33a4 · size=256 · insn=65 */
/* @0x2b33a4 push {r3, r4, r5, r6, r7, lr} */
/* @0x2b33a8 mov r4, r0 */
/* @0x2b33ac ldr r3, [r0, #0x14] */
/* @0x2b33b0 cmp r3, #204 */
/* @0x2b33b4 beq 0x2b33d4 <jpeg_finish_decompress+0x114> */
/* @0x2b33b8 ldr r3, [r0, #0x180] */
/* @0x2b33bc ldr r3, [r3] */
/* @0x2b33c0 blx r3 */
/* @0x2b33c4 mov r2, #0 */
/* @0x2b33c8 mov r3, #204 */
/* @0x2b33cc str r2, [r4, #0x78] */
/* @0x2b33d0 str r3, [r4, #0x14] */
/* @0x2b33d4 ldr r3, [r4, #0x180] */
/* @0x2b33d8 ldrb r3, [r3, #0x8] */
/* @0x2b33dc cmp r3, #0 */
/* @0x2b33e0 beq 0x2b3484 <jpeg_finish_decompress+0x1c4> */
/* @0x2b33e4 mov r6, r4 */
/* @0x2b33e8 mov r7, #0 */
/* @0x2b33ec ldr r5, [r6, #0x78]! */
/* @0x2b33f0 b 0x2b3440 <jpeg_finish_decompress+0x180> */
/* @0x2b33f4 ldr r3, [r4, #0x8] */
/* @0x2b33f8 cmp r3, #0 */
/* @0x2b33fc beq 0x2b3414 <jpeg_finish_decompress+0x154> */
/* @0x2b3400 str r5, [r3, #0x4] */
/* @0x2b3404 str r1, [r3, #0x8] */
/* @0x2b3408 ldr r3, [r3] */
/* @0x2b340c blx r3 */
/* @0x2b3410 ldr r5, [r4, #0x78] */
/* @0x2b3414 ldr r12, [r4, #0x184] */
/* @0x2b3418 mov r1, #0 */
/* @0x2b341c mov r3, r1 */
/* @0x2b3420 mov r0, r4 */
/* @0x2b3424 mov r2, r6 */
/* @0x2b3428 ldr r12, [r12, #0x4] */
/* @0x2b342c blx r12 */
/* @0x2b3430 ldr r3, [r4, #0x78] */
/* @0x2b3434 cmp r3, r5 */
/* @0x2b3438 mov r5, r3 */
/* @0x2b343c beq 0x2b34a0 <jpeg_finish_decompress+0x1e0> */
/* @0x2b3440 ldr r1, [r4, #0x60] */
/* @0x2b3444 mov r0, r4 */
/* @0x2b3448 cmp r1, r5 */
/* @0x2b344c bhi 0x2b33f4 <jpeg_finish_decompress+0x134> */
/* @0x2b3450 ldr r3, [r4, #0x180] */
/* @0x2b3454 mov r5, #0 */
/* @0x2b3458 ldr r3, [r3, #0x4] */
/* @0x2b345c blx r3 */
/* @0x2b3460 ldr r3, [r4, #0x180] */
/* @0x2b3464 mov r0, r4 */
/* @0x2b3468 ldr r3, [r3] */
/* @0x2b346c blx r3 */
/* @0x2b3470 ldr r3, [r4, #0x180] */
/* @0x2b3474 str r7, [r4, #0x78] */
/* @0x2b3478 ldrb r3, [r3, #0x8] */
/* @0x2b347c cmp r3, r5 */
/* @0x2b3480 bne 0x2b3440 <jpeg_finish_decompress+0x180> */
/* @0x2b3484 ldrb r3, [r4, #0x41] */
/* @0x2b3488 mov r0, #1 */
/* @0x2b348c cmp r3, #0 */
/* @0x2b3490 movne r3, #206 */
/* @0x2b3494 moveq r3, #205 */
/* @0x2b3498 str r3, [r4, #0x14] */
/* @0x2b349c pop {r3, r4, r5, r6, r7, pc} */
/* @0x2b34a0 mov r0, #0 */
/* @0x2b34a4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2b34a8 · jpeg_start_decompress · size=280 · insn=70 */
/* @0x2b34a8 ldr r3, [r0, #0x14] */
/* @0x2b34ac push {r4, lr} */
/* @0x2b34b0 cmp r3, #202 */
/* @0x2b34b4 mov r4, r0 */
/* @0x2b34b8 beq 0x2b3598 <jpeg_start_decompress+0xf0> */
/* @0x2b34bc cmp r3, #203 */
/* @0x2b34c0 beq 0x2b34f4 <jpeg_start_decompress+0x4c> */
/* @0x2b34c4 cmp r3, #204 */
/* @0x2b34c8 beq 0x2b34e8 <jpeg_start_decompress+0x40> */
/* @0x2b34cc ldr r2, [r0] */
/* @0x2b34d0 mov r1, #20 */
/* @0x2b34d4 str r3, [r2, #0x18] */
/* @0x2b34d8 ldr r3, [r0] */
/* @0x2b34dc str r1, [r2, #0x14] */
/* @0x2b34e0 ldr r3, [r3] */
/* @0x2b34e4 blx r3 */
/* @0x2b34e8 mov r0, r4 */
/* @0x2b34ec pop {r4, lr} */
/* @0x2b34f0 b 0x2b33a4 <jpeg_finish_decompress+0xe4> */
/* @0x2b34f4 ldr r3, [r4, #0x190] */
/* @0x2b34f8 ldrb r3, [r3, #0x10] */
/* @0x2b34fc cmp r3, #0 */
/* @0x2b3500 beq 0x2b3584 <jpeg_start_decompress+0xdc> */
/* @0x2b3504 ldr r3, [r4, #0x8] */
/* @0x2b3508 cmp r3, #0 */
/* @0x2b350c beq 0x2b351c <jpeg_start_decompress+0x74> */
/* @0x2b3510 ldr r3, [r3] */
/* @0x2b3514 mov r0, r4 */
/* @0x2b3518 blx r3 */
/* @0x2b351c ldr r3, [r4, #0x190] */
/* @0x2b3520 mov r0, r4 */
/* @0x2b3524 ldr r3, [r3] */
/* @0x2b3528 blx r3 */
/* @0x2b352c cmp r0, #0 */
/* @0x2b3530 popeq {r4, pc} */
/* @0x2b3534 cmp r0, #2 */
/* @0x2b3538 beq 0x2b3584 <jpeg_start_decompress+0xdc> */
/* @0x2b353c ldr r3, [r4, #0x8] */
/* @0x2b3540 cmp r3, #0 */
/* @0x2b3544 beq 0x2b351c <jpeg_start_decompress+0x74> */
/* @0x2b3548 bic r0, r0, #2 */
/* @0x2b354c cmp r0, #1 */
/* @0x2b3550 bne 0x2b3508 <jpeg_start_decompress+0x60> */
/* @0x2b3554 ldr r2, [r3, #0x4] */
/* @0x2b3558 ldr r1, [r3, #0x8] */
/* @0x2b355c add r2, r2, #1 */
/* @0x2b3560 str r2, [r3, #0x4] */
/* @0x2b3564 cmp r2, r1 */
/* @0x2b3568 blt 0x2b3508 <jpeg_start_decompress+0x60> */
/* @0x2b356c ldr r2, [r4, #0x11c] */
/* @0x2b3570 cmp r3, #0 */
/* @0x2b3574 add r1, r1, r2 */
/* @0x2b3578 str r1, [r3, #0x8] */
/* @0x2b357c bne 0x2b3510 <jpeg_start_decompress+0x68> */
/* @0x2b3580 b 0x2b351c <jpeg_start_decompress+0x74> */
/* @0x2b3584 ldr r3, [r4, #0x7c] */
/* @0x2b3588 mov r0, r4 */
/* @0x2b358c str r3, [r4, #0x84] */
/* @0x2b3590 pop {r4, lr} */
/* @0x2b3594 b 0x2b33a4 <jpeg_finish_decompress+0xe4> */
/* @0x2b3598 bl 0x2b66d8 <jinit_master_decompress> */
/* @0x2b359c ldrb r3, [r4, #0x40] */
/* @0x2b35a0 cmp r3, #0 */
/* @0x2b35a4 moveq r3, #203 */
/* @0x2b35a8 streq r3, [r4, #0x14] */
/* @0x2b35ac beq 0x2b34f4 <jpeg_start_decompress+0x4c> */
/* @0x2b35b0 mov r3, #207 */
/* @0x2b35b4 mov r0, #1 */
/* @0x2b35b8 str r3, [r4, #0x14] */
/* @0x2b35bc pop {r4, pc} */

/* ── FUNC 0x2b35c0 · jpeg_read_scanlines · size=216 · insn=54 */
/* @0x2b35c0 ldr r12, [r0, #0x14] */
/* @0x2b35c4 push {r4, r5, r6, lr} */
/* @0x2b35c8 cmp r12, #205 */
/* @0x2b35cc sub sp, sp, #8 */
/* @0x2b35d0 mov r4, r0 */
/* @0x2b35d4 mov r6, r1 */
/* @0x2b35d8 mov r5, r2 */
/* @0x2b35dc beq 0x2b35fc <jpeg_read_scanlines+0x3c> */
/* @0x2b35e0 ldr r3, [r0] */
/* @0x2b35e4 mov r1, #20 */
/* @0x2b35e8 str r12, [r3, #0x18] */
/* @0x2b35ec ldr r2, [r0] */
/* @0x2b35f0 str r1, [r3, #0x14] */
/* @0x2b35f4 ldr r3, [r2] */
/* @0x2b35f8 blx r3 */
/* @0x2b35fc ldr r0, [r4, #0x78] */
/* @0x2b3600 ldr lr, [r4, #0x60] */
/* @0x2b3604 cmp r0, lr */
/* @0x2b3608 bhs 0x2b3670 <jpeg_read_scanlines+0xb0> */
/* @0x2b360c ldr r12, [r4, #0x8] */
/* @0x2b3610 cmp r12, #0 */
/* @0x2b3614 beq 0x2b362c <jpeg_read_scanlines+0x6c> */
/* @0x2b3618 str r0, [r12, #0x4] */
/* @0x2b361c mov r0, r4 */
/* @0x2b3620 str lr, [r12, #0x8] */
/* @0x2b3624 ldr r3, [r12] */
/* @0x2b3628 blx r3 */
/* @0x2b362c ldr lr, [r4, #0x184] */
/* @0x2b3630 add r12, sp, #8 */
/* @0x2b3634 mov r3, r5 */
/* @0x2b3638 mov r0, r4 */
/* @0x2b363c mov r1, r6 */
/* @0x2b3640 mov r2, #0 */
/* @0x2b3644 str r2, [r12, #-0x4]! */
/* @0x2b3648 mov r2, r12 */
/* @0x2b364c ldr r12, [lr, #0x4] */
/* @0x2b3650 blx r12 */
/* @0x2b3654 ldr r3, [sp, #0x4] */
/* @0x2b3658 ldr r2, [r4, #0x78] */
/* @0x2b365c mov r0, r3 */
/* @0x2b3660 add r3, r2, r3 */
/* @0x2b3664 str r3, [r4, #0x78] */
/* @0x2b3668 add sp, sp, #8 */
/* @0x2b366c pop {r4, r5, r6, pc} */
/* @0x2b3670 ldr r3, [r4] */
/* @0x2b3674 mov r0, r4 */
/* @0x2b3678 mov r2, #123 */
/* @0x2b367c mvn r1, #0 */
/* @0x2b3680 str r2, [r3, #0x14] */
/* @0x2b3684 ldr r3, [r3, #0x4] */
/* @0x2b3688 blx r3 */
/* @0x2b368c mov r0, #0 */
/* @0x2b3690 add sp, sp, #8 */
/* @0x2b3694 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2b3698 · jpeg_read_raw_data · size=232 · insn=58 */
/* @0x2b3698 push {r3, r4, r5, r6, r7, lr} */
/* @0x2b369c mov r4, r0 */
/* @0x2b36a0 ldr r3, [r0, #0x14] */
/* @0x2b36a4 mov r6, r1 */
/* @0x2b36a8 mov r7, r2 */
/* @0x2b36ac cmp r3, #206 */
/* @0x2b36b0 beq 0x2b36d0 <jpeg_read_raw_data+0x38> */
/* @0x2b36b4 ldr r2, [r0] */
/* @0x2b36b8 mov r1, #20 */
/* @0x2b36bc str r3, [r2, #0x18] */
/* @0x2b36c0 ldr r3, [r0] */
/* @0x2b36c4 str r1, [r2, #0x14] */
/* @0x2b36c8 ldr r3, [r3] */
/* @0x2b36cc blx r3 */
/* @0x2b36d0 ldr r0, [r4, #0x78] */
/* @0x2b36d4 ldr r12, [r4, #0x60] */
/* @0x2b36d8 cmp r0, r12 */
/* @0x2b36dc bhs 0x2b375c <jpeg_read_raw_data+0xc4> */
/* @0x2b36e0 ldr r3, [r4, #0x8] */
/* @0x2b36e4 cmp r3, #0 */
/* @0x2b36e8 beq 0x2b3700 <jpeg_read_raw_data+0x68> */
/* @0x2b36ec str r0, [r3, #0x4] */
/* @0x2b36f0 mov r0, r4 */
/* @0x2b36f4 str r12, [r3, #0x8] */
/* @0x2b36f8 ldr r3, [r3] */
/* @0x2b36fc blx r3 */
/* @0x2b3700 ldr r3, [r4, #0x114] */
/* @0x2b3704 ldr r5, [r4, #0x118] */
/* @0x2b3708 mul r5, r5, r3 */
/* @0x2b370c cmp r5, r7 */
/* @0x2b3710 bhi 0x2b3740 <jpeg_read_raw_data+0xa8> */
/* @0x2b3714 ldr r3, [r4, #0x188] */
/* @0x2b3718 mov r1, r6 */
/* @0x2b371c mov r0, r4 */
/* @0x2b3720 ldr r3, [r3, #0xc] */
/* @0x2b3724 blx r3 */
/* @0x2b3728 cmp r0, #0 */
/* @0x2b372c ldrne r3, [r4, #0x78] */
/* @0x2b3730 movne r0, r5 */
/* @0x2b3734 addne r5, r3, r5 */
/* @0x2b3738 strne r5, [r4, #0x78] */
/* @0x2b373c pop {r3, r4, r5, r6, r7, pc} */
/* @0x2b3740 ldr r3, [r4] */
/* @0x2b3744 mov r2, #23 */
/* @0x2b3748 mov r0, r4 */
/* @0x2b374c str r2, [r3, #0x14] */
/* @0x2b3750 ldr r3, [r3] */
/* @0x2b3754 blx r3 */
/* @0x2b3758 b 0x2b3714 <jpeg_read_raw_data+0x7c> */
/* @0x2b375c ldr r3, [r4] */
/* @0x2b3760 mov r0, r4 */
/* @0x2b3764 mov r2, #123 */
/* @0x2b3768 mvn r1, #0 */
/* @0x2b376c str r2, [r3, #0x14] */
/* @0x2b3770 ldr r3, [r3, #0x4] */
/* @0x2b3774 blx r3 */
/* @0x2b3778 mov r0, #0 */
/* @0x2b377c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2b3780 · jpeg_start_output · size=112 · insn=28 */
/* @0x2b3780 push {r3, r4, r5, lr} */
/* @0x2b3784 mov r4, r0 */
/* @0x2b3788 ldr r3, [r0, #0x14] */
/* @0x2b378c mov r5, r1 */
/* @0x2b3790 cmp r3, #204 */
/* @0x2b3794 cmpne r3, #207 */
/* @0x2b3798 bne 0x2b37d0 <jpeg_start_output+0x50> */
/* @0x2b379c ldr r3, [r4, #0x190] */
/* @0x2b37a0 cmp r5, #1 */
/* @0x2b37a4 movlt r5, #1 */
/* @0x2b37a8 ldrb r3, [r3, #0x11] */
/* @0x2b37ac cmp r3, #0 */
/* @0x2b37b0 beq 0x2b37c0 <jpeg_start_output+0x40> */
/* @0x2b37b4 ldr r3, [r4, #0x7c] */
/* @0x2b37b8 cmp r5, r3 */
/* @0x2b37bc movge r5, r3 */
/* @0x2b37c0 str r5, [r4, #0x84] */
/* @0x2b37c4 mov r0, r4 */
/* @0x2b37c8 pop {r3, r4, r5, lr} */
/* @0x2b37cc b 0x2b33a4 <jpeg_finish_decompress+0xe4> */
/* @0x2b37d0 ldr r2, [r0] */
/* @0x2b37d4 mov r1, #20 */
/* @0x2b37d8 str r3, [r2, #0x18] */
/* @0x2b37dc ldr r3, [r0] */
/* @0x2b37e0 str r1, [r2, #0x14] */
/* @0x2b37e4 ldr r3, [r3] */
/* @0x2b37e8 blx r3 */
/* @0x2b37ec b 0x2b379c <jpeg_start_output+0x1c> */

/* ── FUNC 0x2b37f0 · jpeg_finish_output · size=172 · insn=43 */
/* @0x2b37f0 ldr r3, [r0, #0x14] */
/* @0x2b37f4 push {r4, lr} */
/* @0x2b37f8 sub r2, r3, #205 */
/* @0x2b37fc cmp r2, #1 */
/* @0x2b3800 mov r4, r0 */
/* @0x2b3804 bls 0x2b3878 <jpeg_finish_output+0x88> */
/* @0x2b3808 cmp r3, #208 */
/* @0x2b380c beq 0x2b3854 <jpeg_finish_output+0x64> */
/* @0x2b3810 ldr r2, [r4] */
/* @0x2b3814 mov r1, #20 */
/* @0x2b3818 mov r0, r4 */
/* @0x2b381c str r3, [r2, #0x18] */
/* @0x2b3820 ldr r3, [r4] */
/* @0x2b3824 str r1, [r2, #0x14] */
/* @0x2b3828 ldr r3, [r3] */
/* @0x2b382c blx r3 */
/* @0x2b3830 b 0x2b3854 <jpeg_finish_output+0x64> */
/* @0x2b3834 ldr r3, [r4, #0x190] */
/* @0x2b3838 ldrb r2, [r3, #0x11] */
/* @0x2b383c cmp r2, #0 */
/* @0x2b3840 bne 0x2b3868 <jpeg_finish_output+0x78> */
/* @0x2b3844 ldr r3, [r3] */
/* @0x2b3848 blx r3 */
/* @0x2b384c cmp r0, #0 */
/* @0x2b3850 popeq {r4, pc} */
/* @0x2b3854 ldr r2, [r4, #0x7c] */
/* @0x2b3858 mov r0, r4 */
/* @0x2b385c ldr r3, [r4, #0x84] */
/* @0x2b3860 cmp r2, r3 */
/* @0x2b3864 ble 0x2b3834 <jpeg_finish_output+0x44> */
/* @0x2b3868 mov r3, #207 */
/* @0x2b386c mov r0, #1 */
/* @0x2b3870 str r3, [r4, #0x14] */
/* @0x2b3874 pop {r4, pc} */
/* @0x2b3878 ldrb r2, [r0, #0x40] */
/* @0x2b387c cmp r2, #0 */
/* @0x2b3880 beq 0x2b3810 <jpeg_finish_output+0x20> */
/* @0x2b3884 ldr r3, [r0, #0x180] */
/* @0x2b3888 ldr r3, [r3, #0x4] */
/* @0x2b388c blx r3 */
/* @0x2b3890 mov r3, #208 */
/* @0x2b3894 str r3, [r4, #0x14] */
/* @0x2b3898 b 0x2b3854 <jpeg_finish_output+0x64> */

/* ── FUNC 0x2b389c · anon_2b389c · size=1600 · insn=401 */
/* @0x2b389c ldr r3, [r0, #0x190] */
/* @0x2b38a0 ldr r2, [pc, #0x8] */
/* @0x2b38a4 add r2, pc, r2 */
/* @0x2b38a8 str r2, [r3] */
/* @0x2b38ac bx lr */
/* @0x2b38b0 andeq r0, r0, r0, lsl #6 */
/* @0x2b38b4 push {r3, r4, r5, lr} */
/* @0x2b38b8 mov r2, #1 */
/* @0x2b38bc ldr r3, [r0, #0x190] */
/* @0x2b38c0 mov r5, #0 */
/* @0x2b38c4 ldr r1, [pc, #0x38] */
/* @0x2b38c8 mov r4, r0 */
/* @0x2b38cc strb r2, [r3, #0x14] */
/* @0x2b38d0 add r1, pc, r1 */
/* @0x2b38d4 strb r5, [r3, #0x10] */
/* @0x2b38d8 strb r5, [r3, #0x11] */
/* @0x2b38dc ldr r2, [r0] */
/* @0x2b38e0 str r1, [r3] */
/* @0x2b38e4 ldr r3, [r2, #0x10] */
/* @0x2b38e8 blx r3 */
/* @0x2b38ec ldr r3, [r4, #0x194] */
/* @0x2b38f0 mov r0, r4 */
/* @0x2b38f4 ldr r3, [r3] */
/* @0x2b38f8 blx r3 */
/* @0x2b38fc str r5, [r4, #0x8c] */
/* @0x2b3900 pop {r3, r4, r5, pc} */
/* @0x2b3904 ldrdeq r0, r1, [r0], -r4 */
/* @0x2b3908 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b390c mov r5, r0 */
/* @0x2b3910 ldr r6, [r0, #0x124] */
/* @0x2b3914 sub sp, sp, #12 */
/* @0x2b3918 cmp r6, #1 */
/* @0x2b391c beq 0x2b3b28 <jpeg_finish_output+0x338> */
/* @0x2b3920 sub r3, r6, #1 */
/* @0x2b3924 cmp r3, #3 */
/* @0x2b3928 bhi 0x2b3b80 <jpeg_finish_output+0x390> */
/* @0x2b392c ldr r1, [r5, #0x110] */
/* @0x2b3930 ldr r0, [r5, #0x1c] */
/* @0x2b3934 lsl r1, r1, #3 */
/* @0x2b3938 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b393c ldr r1, [r5, #0x114] */
/* @0x2b3940 lsl r1, r1, #3 */
/* @0x2b3944 str r0, [r5, #0x138] */
/* @0x2b3948 ldr r0, [r5, #0x20] */
/* @0x2b394c bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b3950 ldr r2, [r5, #0x124] */
/* @0x2b3954 mov r3, #0 */
/* @0x2b3958 str r3, [r5, #0x140] */
/* @0x2b395c cmp r2, r3 */
/* @0x2b3960 str r0, [r5, #0x13c] */
/* @0x2b3964 ble 0x2b3a68 <jpeg_finish_output+0x278> */
/* @0x2b3968 mov r8, r3 */
/* @0x2b396c mov r4, r3 */
/* @0x2b3970 mov r9, r5 */
/* @0x2b3974 add r2, r5, #320 */
/* @0x2b3978 str r2, [sp, #0x4] */
/* @0x2b397c ldr r6, [r9, #0x128] */
/* @0x2b3980 ldr r7, [r6, #0x8] */
/* @0x2b3984 ldr r10, [r6, #0xc] */
/* @0x2b3988 ldr r2, [r6, #0x24] */
/* @0x2b398c str r7, [r6, #0x34] */
/* @0x2b3990 mov r1, r7 */
/* @0x2b3994 mul r11, r10, r7 */
/* @0x2b3998 str r10, [r6, #0x38] */
/* @0x2b399c mul r2, r2, r7 */
/* @0x2b39a0 ldr r0, [r6, #0x1c] */
/* @0x2b39a4 str r11, [r6, #0x3c] */
/* @0x2b39a8 str r2, [r6, #0x40] */
/* @0x2b39ac bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x2b39b0 ldr r0, [r6, #0x20] */
/* @0x2b39b4 cmp r1, #0 */
/* @0x2b39b8 movne r7, r1 */
/* @0x2b39bc mov r1, r10 */
/* @0x2b39c0 str r7, [r6, #0x44] */
/* @0x2b39c4 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x2b39c8 add r3, r11, r8 */
/* @0x2b39cc cmp r1, #0 */
/* @0x2b39d0 movne r10, r1 */
/* @0x2b39d4 cmp r3, #10 */
/* @0x2b39d8 str r10, [r6, #0x48] */
/* @0x2b39dc bgt 0x2b3aa0 <jpeg_finish_output+0x2b0> */
/* @0x2b39e0 cmp r11, #0 */
/* @0x2b39e4 sub r0, r11, #1 */
/* @0x2b39e8 ble 0x2b3a1c <jpeg_finish_output+0x22c> */
/* @0x2b39ec ldr r1, [r5, #0x140] */
/* @0x2b39f0 ldr r12, [sp, #0x4] */
/* @0x2b39f4 add r2, r11, r1 */
/* @0x2b39f8 add r3, r5, r1, lsl #2 */
/* @0x2b39fc add r2, r12, r2, lsl #2 */
/* @0x2b3a00 add r3, r3, #320 */
/* @0x2b3a04 str r4, [r3, #0x4]! */
/* @0x2b3a08 cmp r3, r2 */
/* @0x2b3a0c bne 0x2b3a04 <jpeg_finish_output+0x214> */
/* @0x2b3a10 add r1, r1, #1 */
/* @0x2b3a14 add r0, r0, r1 */
/* @0x2b3a18 str r0, [r5, #0x140] */
/* @0x2b3a1c ldr r6, [r5, #0x124] */
/* @0x2b3a20 add r4, r4, #1 */
/* @0x2b3a24 add r9, r9, #4 */
/* @0x2b3a28 cmp r4, r6 */
/* @0x2b3a2c ldrlt r8, [r5, #0x140] */
/* @0x2b3a30 blt 0x2b397c <jpeg_finish_output+0x18c> */
/* @0x2b3a34 cmp r6, #0 */
/* @0x2b3a38 ble 0x2b3a68 <jpeg_finish_output+0x278> */
/* @0x2b3a3c mov r7, r5 */
/* @0x2b3a40 mov r4, #0 */
/* @0x2b3a44 mov r9, #52 */
/* @0x2b3a48 ldr r8, [r7, #0x128] */
/* @0x2b3a4c ldr r3, [r8, #0x4c] */
/* @0x2b3a50 cmp r3, #0 */
/* @0x2b3a54 beq 0x2b3abc <jpeg_finish_output+0x2cc> */
/* @0x2b3a58 add r4, r4, #1 */
/* @0x2b3a5c add r7, r7, #4 */
/* @0x2b3a60 cmp r4, r6 */
/* @0x2b3a64 blt 0x2b3a48 <jpeg_finish_output+0x258> */
/* @0x2b3a68 ldr r3, [r5, #0x198] */
/* @0x2b3a6c mov r0, r5 */
/* @0x2b3a70 ldr r3, [r3] */
/* @0x2b3a74 blx r3 */
/* @0x2b3a78 ldr r3, [r5, #0x188] */
/* @0x2b3a7c mov r0, r5 */
/* @0x2b3a80 ldr r3, [r3] */
/* @0x2b3a84 blx r3 */
/* @0x2b3a88 ldr r2, [r5, #0x188] */
/* @0x2b3a8c ldr r3, [r5, #0x190] */
/* @0x2b3a90 ldr r2, [r2, #0x4] */
/* @0x2b3a94 str r2, [r3] */
/* @0x2b3a98 add sp, sp, #12 */
/* @0x2b3a9c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b3aa0 ldr r3, [r5] */
/* @0x2b3aa4 mov r12, #13 */
/* @0x2b3aa8 mov r0, r5 */
/* @0x2b3aac str r12, [r3, #0x14] */
/* @0x2b3ab0 ldr r3, [r3] */
/* @0x2b3ab4 blx r3 */
/* @0x2b3ab8 b 0x2b39e0 <jpeg_finish_output+0x1f0> */
/* @0x2b3abc ldr r3, [r8, #0x10] */
/* @0x2b3ac0 cmp r3, #3 */
/* @0x2b3ac4 add r6, r3, #36 */
/* @0x2b3ac8 bhi 0x2b3b08 <jpeg_finish_output+0x318> */
/* @0x2b3acc ldr r2, [r5, r6, lsl #2] */
/* @0x2b3ad0 cmp r2, #0 */
/* @0x2b3ad4 beq 0x2b3b08 <jpeg_finish_output+0x318> */
/* @0x2b3ad8 ldr r3, [r5, #0x4] */
/* @0x2b3adc mov r1, #1 */
/* @0x2b3ae0 mov r2, #130 */
/* @0x2b3ae4 mov r0, r5 */
/* @0x2b3ae8 ldr r3, [r3] */
/* @0x2b3aec blx r3 */
/* @0x2b3af0 ldr r1, [r5, r6, lsl #2] */
/* @0x2b3af4 mov r2, #130 */
/* @0x2b3af8 bl 0xb65bc <memcpy@plt> */
/* @0x2b3afc ldr r6, [r5, #0x124] */
/* @0x2b3b00 str r0, [r8, #0x4c] */
/* @0x2b3b04 b 0x2b3a58 <jpeg_finish_output+0x268> */
/* @0x2b3b08 ldr r2, [r5] */
/* @0x2b3b0c mov r0, r5 */
/* @0x2b3b10 str r3, [r2, #0x18] */
/* @0x2b3b14 ldr r3, [r5] */
/* @0x2b3b18 str r9, [r2, #0x14] */
/* @0x2b3b1c ldr r3, [r3] */
/* @0x2b3b20 blx r3 */
/* @0x2b3b24 b 0x2b3ad8 <jpeg_finish_output+0x2e8> */
/* @0x2b3b28 ldr r4, [r0, #0x128] */
/* @0x2b3b2c ldr r3, [r4, #0x20] */
/* @0x2b3b30 ldr r7, [r4, #0xc] */
/* @0x2b3b34 ldr r2, [r4, #0x24] */
/* @0x2b3b38 ldr r1, [r4, #0x1c] */
/* @0x2b3b3c str r1, [r0, #0x138] */
/* @0x2b3b40 mov r0, r3 */
/* @0x2b3b44 str r3, [r5, #0x13c] */
/* @0x2b3b48 mov r1, r7 */
/* @0x2b3b4c str r6, [r4, #0x34] */
/* @0x2b3b50 str r6, [r4, #0x38] */
/* @0x2b3b54 str r6, [r4, #0x3c] */
/* @0x2b3b58 str r6, [r4, #0x44] */
/* @0x2b3b5c str r2, [r4, #0x40] */
/* @0x2b3b60 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x2b3b64 mov r3, #0 */
/* @0x2b3b68 cmp r1, r3 */
/* @0x2b3b6c movne r7, r1 */
/* @0x2b3b70 str r7, [r4, #0x48] */
/* @0x2b3b74 str r6, [r5, #0x140] */
/* @0x2b3b78 str r3, [r5, #0x144] */
/* @0x2b3b7c b 0x2b3a3c <jpeg_finish_output+0x24c> */
/* @0x2b3b80 ldr r3, [r0] */
/* @0x2b3b84 mov r12, #26 */
/* @0x2b3b88 mov r1, #4 */
/* @0x2b3b8c str r6, [r3, #0x18] */
/* @0x2b3b90 ldr r2, [r0] */
/* @0x2b3b94 str r12, [r3, #0x14] */
/* @0x2b3b98 str r1, [r2, #0x1c] */
/* @0x2b3b9c ldr r3, [r0] */
/* @0x2b3ba0 ldr r3, [r3] */
/* @0x2b3ba4 blx r3 */
/* @0x2b3ba8 b 0x2b392c <jpeg_finish_output+0x13c> */
/* @0x2b3bac push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b3bb0 mov r4, r0 */
/* @0x2b3bb4 ldr r5, [r0, #0x190] */
/* @0x2b3bb8 ldrb r3, [r5, #0x11] */
/* @0x2b3bbc cmp r3, #0 */
/* @0x2b3bc0 beq 0x2b3bcc <jpeg_finish_output+0x3dc> */
/* @0x2b3bc4 mov r0, #2 */
/* @0x2b3bc8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b3bcc ldr r3, [r0, #0x194] */
/* @0x2b3bd0 ldr r3, [r3, #0x4] */
/* @0x2b3bd4 blx r3 */
/* @0x2b3bd8 cmp r0, #1 */
/* @0x2b3bdc mov r6, r0 */
/* @0x2b3be0 beq 0x2b3c30 <jpeg_finish_output+0x440> */
/* @0x2b3be4 cmp r0, #2 */
/* @0x2b3be8 bne 0x2b3c58 <jpeg_finish_output+0x468> */
/* @0x2b3bec ldrb r3, [r5, #0x14] */
/* @0x2b3bf0 mov r2, #1 */
/* @0x2b3bf4 strb r2, [r5, #0x11] */
/* @0x2b3bf8 cmp r3, #0 */
/* @0x2b3bfc beq 0x2b3c5c <jpeg_finish_output+0x46c> */
/* @0x2b3c00 ldr r3, [r4, #0x194] */
/* @0x2b3c04 ldrb r3, [r3, #0xd] */
/* @0x2b3c08 cmp r3, #0 */
/* @0x2b3c0c beq 0x2b3bc4 <jpeg_finish_output+0x3d4> */
/* @0x2b3c10 ldr r3, [r4] */
/* @0x2b3c14 mov r0, r4 */
/* @0x2b3c18 mov r1, #59 */
/* @0x2b3c1c ldr r2, [r3] */
/* @0x2b3c20 str r1, [r3, #0x14] */
/* @0x2b3c24 blx r2 */
/* @0x2b3c28 mov r0, r6 */
/* @0x2b3c2c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b3c30 ldrb r3, [r5, #0x14] */
/* @0x2b3c34 cmp r3, #0 */
/* @0x2b3c38 bne 0x2b3c74 <jpeg_finish_output+0x484> */
/* @0x2b3c3c ldrb r3, [r5, #0x10] */
/* @0x2b3c40 cmp r3, #0 */
/* @0x2b3c44 beq 0x2b3e74 <jpeg_finish_output+0x684> */
/* @0x2b3c48 mov r0, r4 */
/* @0x2b3c4c bl 0x2b3908 <jpeg_finish_output+0x118> */
/* @0x2b3c50 mov r0, #1 */
/* @0x2b3c54 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b3c58 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b3c5c ldr r3, [r4, #0x7c] */
/* @0x2b3c60 ldr r2, [r4, #0x84] */
/* @0x2b3c64 cmp r2, r3 */
/* @0x2b3c68 ble 0x2b3bc4 <jpeg_finish_output+0x3d4> */
/* @0x2b3c6c str r3, [r4, #0x84] */
/* @0x2b3c70 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b3c74 ldr r2, [r4, #0x20] */
/* @0x2b3c78 movw r3, #0xffdc */
/* @0x2b3c7c cmp r2, r3 */
/* @0x2b3c80 bgt 0x2b3c90 <jpeg_finish_output+0x4a0> */
/* @0x2b3c84 ldr r2, [r4, #0x1c] */
/* @0x2b3c88 cmp r2, r3 */
/* @0x2b3c8c ble 0x2b3cb4 <jpeg_finish_output+0x4c4> */
/* @0x2b3c90 ldr r3, [r4] */
/* @0x2b3c94 movw r2, #0xffdc */
/* @0x2b3c98 mov r1, #41 */
/* @0x2b3c9c mov r0, r4 */
/* @0x2b3ca0 str r2, [r3, #0x18] */
/* @0x2b3ca4 ldr r2, [r4] */
/* @0x2b3ca8 str r1, [r3, #0x14] */
/* @0x2b3cac ldr r3, [r2] */
/* @0x2b3cb0 blx r3 */
/* @0x2b3cb4 ldr r3, [r4, #0xc0] */
/* @0x2b3cb8 cmp r3, #8 */
/* @0x2b3cbc beq 0x2b3ce0 <jpeg_finish_output+0x4f0> */
/* @0x2b3cc0 ldr r2, [r4] */
/* @0x2b3cc4 mov r1, #15 */
/* @0x2b3cc8 mov r0, r4 */
/* @0x2b3ccc str r3, [r2, #0x18] */
/* @0x2b3cd0 ldr r3, [r4] */
/* @0x2b3cd4 str r1, [r2, #0x14] */
/* @0x2b3cd8 ldr r3, [r3] */
/* @0x2b3cdc blx r3 */
/* @0x2b3ce0 ldr r12, [r4, #0x24] */
/* @0x2b3ce4 cmp r12, #10 */
/* @0x2b3ce8 bgt 0x2b3ea0 <jpeg_finish_output+0x6b0> */
/* @0x2b3cec cmp r12, #0 */
/* @0x2b3cf0 mov r1, #1 */
/* @0x2b3cf4 ldr r6, [r4, #0xc4] */
/* @0x2b3cf8 str r1, [r4, #0x110] */
/* @0x2b3cfc str r1, [r4, #0x114] */
/* @0x2b3d00 ble 0x2b3ed4 <jpeg_finish_output+0x6e4> */
/* @0x2b3d04 mov r7, #0 */
/* @0x2b3d08 mov r8, #18 */
/* @0x2b3d0c b 0x2b3d4c <jpeg_finish_output+0x55c> */
/* @0x2b3d10 ldr r2, [r6, #0xc] */
/* @0x2b3d14 sub r1, r2, #1 */
/* @0x2b3d18 cmp r1, #3 */
/* @0x2b3d1c bhi 0x2b3d64 <jpeg_finish_output+0x574> */
/* @0x2b3d20 ldr r0, [r4, #0x110] */
/* @0x2b3d24 add r6, r6, #84 */
/* @0x2b3d28 ldr r1, [r4, #0x114] */
/* @0x2b3d2c cmp r0, r3 */
/* @0x2b3d30 strge r0, [r4, #0x110] */
/* @0x2b3d34 strlt r3, [r4, #0x110] */
/* @0x2b3d38 cmp r1, r2 */
/* @0x2b3d3c movlt r1, r2 */
/* @0x2b3d40 cmp r7, r12 */
/* @0x2b3d44 str r1, [r4, #0x114] */
/* @0x2b3d48 bge 0x2b3d84 <jpeg_finish_output+0x594> */
/* @0x2b3d4c ldr r3, [r6, #0x8] */
/* @0x2b3d50 mov r0, r4 */
/* @0x2b3d54 add r7, r7, #1 */
/* @0x2b3d58 sub r2, r3, #1 */
/* @0x2b3d5c cmp r2, #3 */
/* @0x2b3d60 bls 0x2b3d10 <jpeg_finish_output+0x520> */
/* @0x2b3d64 ldr r2, [r4] */
/* @0x2b3d68 ldr r3, [r2] */
/* @0x2b3d6c str r8, [r2, #0x14] */
/* @0x2b3d70 blx r3 */
/* @0x2b3d74 ldr r3, [r6, #0x8] */
/* @0x2b3d78 ldr r2, [r6, #0xc] */
/* @0x2b3d7c ldr r12, [r4, #0x24] */
/* @0x2b3d80 b 0x2b3d20 <jpeg_finish_output+0x530> */
/* @0x2b3d84 cmp r12, #0 */
/* @0x2b3d88 mov r10, #8 */
/* @0x2b3d8c ldr r6, [r4, #0xc4] */
/* @0x2b3d90 movgt r7, #0 */
/* @0x2b3d94 str r10, [r4, #0x118] */
/* @0x2b3d98 movgt r9, r7 */
/* @0x2b3d9c movgt r8, #1 */
/* @0x2b3da0 ble 0x2b3e30 <jpeg_finish_output+0x640> */
/* @0x2b3da4 str r10, [r6, #0x24] */
/* @0x2b3da8 add r7, r7, #1 */
/* @0x2b3dac ldr r3, [r4, #0x1c] */
/* @0x2b3db0 add r6, r6, #84 */
/* @0x2b3db4 ldr r0, [r6, #-0x4c] */
/* @0x2b3db8 ldr r1, [r4, #0x110] */
/* @0x2b3dbc mul r0, r0, r3 */
/* @0x2b3dc0 lsl r1, r1, #3 */
/* @0x2b3dc4 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b3dc8 ldr r3, [r6, #-0x48] */
/* @0x2b3dcc str r0, [r6, #-0x38] */
/* @0x2b3dd0 ldr r0, [r4, #0x20] */
/* @0x2b3dd4 ldr r1, [r4, #0x114] */
/* @0x2b3dd8 mul r0, r3, r0 */
/* @0x2b3ddc lsl r1, r1, #3 */
/* @0x2b3de0 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b3de4 ldr r3, [r6, #-0x4c] */
/* @0x2b3de8 str r0, [r6, #-0x34] */
/* @0x2b3dec ldr r0, [r4, #0x1c] */
/* @0x2b3df0 ldr r1, [r4, #0x110] */
/* @0x2b3df4 mul r0, r3, r0 */
/* @0x2b3df8 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b3dfc ldr r3, [r6, #-0x48] */
/* @0x2b3e00 str r0, [r6, #-0x2c] */
/* @0x2b3e04 ldr r0, [r4, #0x20] */
/* @0x2b3e08 ldr r1, [r4, #0x114] */
/* @0x2b3e0c mul r0, r3, r0 */
/* @0x2b3e10 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b3e14 strb r8, [r6, #-0x24] */
/* @0x2b3e18 str r9, [r6, #-0x8] */
/* @0x2b3e1c str r0, [r6, #-0x28] */
/* @0x2b3e20 ldr r3, [r4, #0x24] */
/* @0x2b3e24 cmp r7, r3 */
/* @0x2b3e28 blt 0x2b3da4 <jpeg_finish_output+0x5b4> */
/* @0x2b3e2c ldr r1, [r4, #0x114] */
/* @0x2b3e30 lsl r1, r1, #3 */
/* @0x2b3e34 ldr r0, [r4, #0x20] */
/* @0x2b3e38 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b3e3c ldr r2, [r4, #0x124] */
/* @0x2b3e40 ldr r3, [r4, #0x24] */
/* @0x2b3e44 cmp r2, r3 */
/* @0x2b3e48 str r0, [r4, #0x11c] */
/* @0x2b3e4c blt 0x2b3e90 <jpeg_finish_output+0x6a0> */
/* @0x2b3e50 ldrb r3, [r4, #0xc8] */
/* @0x2b3e54 cmp r3, #0 */
/* @0x2b3e58 bne 0x2b3e90 <jpeg_finish_output+0x6a0> */
/* @0x2b3e5c ldr r2, [r4, #0x190] */
/* @0x2b3e60 strb r3, [r2, #0x10] */
/* @0x2b3e64 mov r3, #0 */
/* @0x2b3e68 mov r0, #1 */
/* @0x2b3e6c strb r3, [r5, #0x14] */
/* @0x2b3e70 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b3e74 ldr r3, [r4] */
/* @0x2b3e78 mov r2, #35 */
/* @0x2b3e7c mov r0, r4 */
/* @0x2b3e80 str r2, [r3, #0x14] */
/* @0x2b3e84 ldr r3, [r3] */
/* @0x2b3e88 blx r3 */
/* @0x2b3e8c b 0x2b3c48 <jpeg_finish_output+0x458> */
/* @0x2b3e90 ldr r3, [r4, #0x190] */
/* @0x2b3e94 mov r2, #1 */
/* @0x2b3e98 strb r2, [r3, #0x10] */
/* @0x2b3e9c b 0x2b3e64 <jpeg_finish_output+0x674> */
/* @0x2b3ea0 ldr r3, [r4] */
/* @0x2b3ea4 mov lr, #26 */
/* @0x2b3ea8 mov r1, #10 */
/* @0x2b3eac mov r0, r4 */
/* @0x2b3eb0 str r12, [r3, #0x18] */
/* @0x2b3eb4 ldr r2, [r4] */
/* @0x2b3eb8 str lr, [r3, #0x14] */
/* @0x2b3ebc str r1, [r2, #0x1c] */
/* @0x2b3ec0 ldr r3, [r4] */
/* @0x2b3ec4 ldr r3, [r3] */
/* @0x2b3ec8 blx r3 */
/* @0x2b3ecc ldr r12, [r4, #0x24] */
/* @0x2b3ed0 b 0x2b3cec <jpeg_finish_output+0x4fc> */
/* @0x2b3ed4 mov r3, #8 */
/* @0x2b3ed8 str r3, [r4, #0x118] */
/* @0x2b3edc b 0x2b3e30 <jpeg_finish_output+0x640> */

/* ── FUNC 0x2b3ee0 · jinit_input_controller · size=120 · insn=30 */
/* @0x2b3ee0 ldr r3, [r0, #0x4] */
/* @0x2b3ee4 mov r1, #0 */
/* @0x2b3ee8 push {r4, r5, r6, lr} */
/* @0x2b3eec mov r2, #24 */
/* @0x2b3ef0 ldr r3, [r3] */
/* @0x2b3ef4 mov r4, r0 */
/* @0x2b3ef8 blx r3 */
/* @0x2b3efc ldr r5, [pc, #0x44] */
/* @0x2b3f00 ldr r6, [pc, #0x44] */
/* @0x2b3f04 mov r3, #0 */
/* @0x2b3f08 add r5, pc, r5 */
/* @0x2b3f0c ldr r12, [pc, #0x3c] */
/* @0x2b3f10 ldr r1, [pc, #0x3c] */
/* @0x2b3f14 add r6, pc, r6 */
/* @0x2b3f18 mov r2, #1 */
/* @0x2b3f1c add r12, pc, r12 */
/* @0x2b3f20 add r1, pc, r1 */
/* @0x2b3f24 str r0, [r4, #0x190] */
/* @0x2b3f28 mov r4, r5 */
/* @0x2b3f2c str r6, [r0] */
/* @0x2b3f30 stmib r0, {r4, r12} */
/* @0x2b3f34 str r1, [r0, #0xc] */
/* @0x2b3f38 strb r2, [r0, #0x14] */
/* @0x2b3f3c strb r3, [r0, #0x10] */
/* @0x2b3f40 strb r3, [r0, #0x11] */
/* @0x2b3f44 pop {r4, r5, r6, pc} */
/* @0x2b3f48 .word 0xfffff9a4 */
/* @0x2b3f4c .word 0xfffffc90 */
/* @0x2b3f50 .word 0xfffff9e4 */
/* @0x2b3f54 .word 0xfffff974 */

/* ── FUNC 0x2b3f58 · anon_2b3f58 · size=7748 · insn=1938 */
/* @0x2b3f58 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b3f5c mov r5, r0 */
/* @0x2b3f60 ldr r7, [r0, #0x18] */
/* @0x2b3f64 ldr r3, [r7, #0x4] */
/* @0x2b3f68 ldr r12, [r7] */
/* @0x2b3f6c cmp r3, #0 */
/* @0x2b3f70 strb r1, [r0, #0xc8] */
/* @0x2b3f74 strb r2, [r0, #0xc9] */
/* @0x2b3f78 beq 0x2b4208 <jinit_input_controller+0x328> */
/* @0x2b3f7c subs r3, r3, #1 */
/* @0x2b3f80 ldrb r4, [r12] */
/* @0x2b3f84 addne r12, r12, #1 */
/* @0x2b3f88 beq 0x2b4240 <jinit_input_controller+0x360> */
/* @0x2b3f8c subs r3, r3, #1 */
/* @0x2b3f90 ldrb r8, [r12] */
/* @0x2b3f94 addne r12, r12, #1 */
/* @0x2b3f98 beq 0x2b426c <jinit_input_controller+0x38c> */
/* @0x2b3f9c ldrb r2, [r12] */
/* @0x2b3fa0 subs r3, r3, #1 */
/* @0x2b3fa4 addne r12, r12, #1 */
/* @0x2b3fa8 str r2, [r5, #0xc0] */
/* @0x2b3fac beq 0x2b41e8 <jinit_input_controller+0x308> */
/* @0x2b3fb0 ldrb r2, [r12] */
/* @0x2b3fb4 subs r3, r3, #1 */
/* @0x2b3fb8 addne r12, r12, #1 */
/* @0x2b3fbc lsl r2, r2, #8 */
/* @0x2b3fc0 str r2, [r5, #0x20] */
/* @0x2b3fc4 beq 0x2b428c <jinit_input_controller+0x3ac> */
/* @0x2b3fc8 ldrb r1, [r12] */
/* @0x2b3fcc subs r3, r3, #1 */
/* @0x2b3fd0 addne r12, r12, #1 */
/* @0x2b3fd4 add r2, r1, r2 */
/* @0x2b3fd8 str r2, [r5, #0x20] */
/* @0x2b3fdc beq 0x2b42bc <jinit_input_controller+0x3dc> */
/* @0x2b3fe0 ldrb r2, [r12] */
/* @0x2b3fe4 subs r3, r3, #1 */
/* @0x2b3fe8 addne r12, r12, #1 */
/* @0x2b3fec lsl r2, r2, #8 */
/* @0x2b3ff0 str r2, [r5, #0x1c] */
/* @0x2b3ff4 beq 0x2b4308 <jinit_input_controller+0x428> */
/* @0x2b3ff8 subs r6, r3, #1 */
/* @0x2b3ffc ldrb r3, [r12] */
/* @0x2b4000 addne r10, r12, #1 */
/* @0x2b4004 add r2, r3, r2 */
/* @0x2b4008 str r2, [r5, #0x1c] */
/* @0x2b400c bne 0x2b402c <jinit_input_controller+0x14c> */
/* @0x2b4010 ldr r3, [r7, #0xc] */
/* @0x2b4014 mov r0, r5 */
/* @0x2b4018 blx r3 */
/* @0x2b401c cmp r0, #0 */
/* @0x2b4020 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b4024 ldr r10, [r7] */
/* @0x2b4028 ldr r6, [r7, #0x4] */
/* @0x2b402c ldrb r2, [r10] */
/* @0x2b4030 mov lr, #100 */
/* @0x2b4034 ldr r3, [r5] */
/* @0x2b4038 mov r1, #1 */
/* @0x2b403c ldr r12, [r5, #0x17c] */
/* @0x2b4040 mov r0, r5 */
/* @0x2b4044 str r2, [r5, #0x24] */
/* @0x2b4048 add r10, r10, r1 */
/* @0x2b404c ldr r2, [r3, #0x4] */
/* @0x2b4050 add r4, r8, r4, lsl #8 */
/* @0x2b4054 str r12, [r3, #0x18] */
/* @0x2b4058 sub r4, r4, #8 */
/* @0x2b405c ldr r12, [r5, #0x1c] */
/* @0x2b4060 sub r6, r6, #1 */
/* @0x2b4064 str r12, [r3, #0x1c] */
/* @0x2b4068 ldr r12, [r5, #0x20] */
/* @0x2b406c str r12, [r3, #0x20] */
/* @0x2b4070 ldr r12, [r5, #0x24] */
/* @0x2b4074 str lr, [r3, #0x14] */
/* @0x2b4078 str r12, [r3, #0x24] */
/* @0x2b407c blx r2 */
/* @0x2b4080 ldr r3, [r5, #0x194] */
/* @0x2b4084 ldrb r3, [r3, #0xd] */
/* @0x2b4088 cmp r3, #0 */
/* @0x2b408c bne 0x2b432c <jinit_input_controller+0x44c> */
/* @0x2b4090 ldr r3, [r5, #0x20] */
/* @0x2b4094 cmp r3, #0 */
/* @0x2b4098 beq 0x2b40a8 <jinit_input_controller+0x1c8> */
/* @0x2b409c ldr r3, [r5, #0x1c] */
/* @0x2b40a0 cmp r3, #0 */
/* @0x2b40a4 bne 0x2b42dc <jinit_input_controller+0x3fc> */
/* @0x2b40a8 ldr r3, [r5] */
/* @0x2b40ac mov r2, #32 */
/* @0x2b40b0 mov r0, r5 */
/* @0x2b40b4 str r2, [r3, #0x14] */
/* @0x2b40b8 ldr r3, [r3] */
/* @0x2b40bc blx r3 */
/* @0x2b40c0 ldr r3, [r5, #0x24] */
/* @0x2b40c4 add r2, r3, r3, lsl #1 */
/* @0x2b40c8 cmp r2, r4 */
/* @0x2b40cc beq 0x2b40ec <jinit_input_controller+0x20c> */
/* @0x2b40d0 ldr r3, [r5] */
/* @0x2b40d4 mov r2, #11 */
/* @0x2b40d8 mov r0, r5 */
/* @0x2b40dc str r2, [r3, #0x14] */
/* @0x2b40e0 ldr r3, [r3] */
/* @0x2b40e4 blx r3 */
/* @0x2b40e8 ldr r3, [r5, #0x24] */
/* @0x2b40ec ldr r4, [r5, #0xc4] */
/* @0x2b40f0 cmp r4, #0 */
/* @0x2b40f4 beq 0x2b4348 <jinit_input_controller+0x468> */
/* @0x2b40f8 cmp r3, #0 */
/* @0x2b40fc ble 0x2b42ec <jinit_input_controller+0x40c> */
/* @0x2b4100 add r4, r4, #84 */
/* @0x2b4104 mov r8, #0 */
/* @0x2b4108 mov r9, #101 */
/* @0x2b410c b 0x2b41bc <jinit_input_controller+0x2dc> */
/* @0x2b4110 ldrb r3, [r10] */
/* @0x2b4114 subs r6, r6, #1 */
/* @0x2b4118 addne r10, r10, #1 */
/* @0x2b411c str r3, [r4, #-0x54] */
/* @0x2b4120 beq 0x2b4220 <jinit_input_controller+0x340> */
/* @0x2b4124 ldrb r3, [r10] */
/* @0x2b4128 subs r6, r6, #1 */
/* @0x2b412c addne r10, r10, #1 */
/* @0x2b4130 and r2, r3, #15 */
/* @0x2b4134 str r2, [r4, #-0x48] */
/* @0x2b4138 asr r3, r3, #4 */
/* @0x2b413c str r3, [r4, #-0x4c] */
/* @0x2b4140 bne 0x2b4160 <jinit_input_controller+0x280> */
/* @0x2b4144 ldr r3, [r7, #0xc] */
/* @0x2b4148 mov r0, r5 */
/* @0x2b414c blx r3 */
/* @0x2b4150 cmp r0, #0 */
/* @0x2b4154 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b4158 ldr r10, [r7] */
/* @0x2b415c ldr r6, [r7, #0x4] */
/* @0x2b4160 ldrb r3, [r10] */
/* @0x2b4164 mov r1, #1 */
/* @0x2b4168 ldr r2, [r4, #-0x54] */
/* @0x2b416c mov r0, r5 */
/* @0x2b4170 add r8, r8, r1 */
/* @0x2b4174 add r10, r10, r1 */
/* @0x2b4178 str r3, [r4, #-0x44] */
/* @0x2b417c sub r6, r6, #1 */
/* @0x2b4180 ldr r3, [r5] */
/* @0x2b4184 add r4, r4, #84 */
/* @0x2b4188 str r2, [r3, #0x18] */
/* @0x2b418c ldr r12, [r4, #-0xa0] */
/* @0x2b4190 ldr r2, [r3, #0x4] */
/* @0x2b4194 str r12, [r3, #0x1c] */
/* @0x2b4198 ldr r12, [r4, #-0x9c] */
/* @0x2b419c str r12, [r3, #0x20] */
/* @0x2b41a0 ldr r12, [r4, #-0x98] */
/* @0x2b41a4 str r9, [r3, #0x14] */
/* @0x2b41a8 str r12, [r3, #0x24] */
/* @0x2b41ac blx r2 */
/* @0x2b41b0 ldr r3, [r5, #0x24] */
/* @0x2b41b4 cmp r3, r8 */
/* @0x2b41b8 ble 0x2b42ec <jinit_input_controller+0x40c> */
/* @0x2b41bc cmp r6, #0 */
/* @0x2b41c0 str r8, [r4, #-0x50] */
/* @0x2b41c4 bne 0x2b4110 <jinit_input_controller+0x230> */
/* @0x2b41c8 ldr r3, [r7, #0xc] */
/* @0x2b41cc mov r0, r5 */
/* @0x2b41d0 blx r3 */
/* @0x2b41d4 cmp r0, #0 */
/* @0x2b41d8 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b41dc ldr r10, [r7] */
/* @0x2b41e0 ldr r6, [r7, #0x4] */
/* @0x2b41e4 b 0x2b4110 <jinit_input_controller+0x230> */
/* @0x2b41e8 ldr r3, [r7, #0xc] */
/* @0x2b41ec mov r0, r5 */
/* @0x2b41f0 blx r3 */
/* @0x2b41f4 cmp r0, #0 */
/* @0x2b41f8 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b41fc ldr r12, [r7] */
/* @0x2b4200 ldr r3, [r7, #0x4] */
/* @0x2b4204 b 0x2b3fb0 <jinit_input_controller+0xd0> */
/* @0x2b4208 ldr r3, [r7, #0xc] */
/* @0x2b420c blx r3 */
/* @0x2b4210 cmp r0, #0 */
/* @0x2b4214 bne 0x2b42b0 <jinit_input_controller+0x3d0> */
/* @0x2b4218 mov r0, #0 */
/* @0x2b421c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b4220 ldr r3, [r7, #0xc] */
/* @0x2b4224 mov r0, r5 */
/* @0x2b4228 blx r3 */
/* @0x2b422c cmp r0, #0 */
/* @0x2b4230 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b4234 ldr r10, [r7] */
/* @0x2b4238 ldr r6, [r7, #0x4] */
/* @0x2b423c b 0x2b4124 <jinit_input_controller+0x244> */
/* @0x2b4240 ldr r3, [r7, #0xc] */
/* @0x2b4244 mov r0, r5 */
/* @0x2b4248 blx r3 */
/* @0x2b424c cmp r0, #0 */
/* @0x2b4250 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b4254 ldr r3, [r7, #0x4] */
/* @0x2b4258 ldr r12, [r7] */
/* @0x2b425c subs r3, r3, #1 */
/* @0x2b4260 ldrb r8, [r12] */
/* @0x2b4264 addne r12, r12, #1 */
/* @0x2b4268 bne 0x2b3f9c <jinit_input_controller+0xbc> */
/* @0x2b426c ldr r3, [r7, #0xc] */
/* @0x2b4270 mov r0, r5 */
/* @0x2b4274 blx r3 */
/* @0x2b4278 cmp r0, #0 */
/* @0x2b427c beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b4280 ldr r12, [r7] */
/* @0x2b4284 ldr r3, [r7, #0x4] */
/* @0x2b4288 b 0x2b3f9c <jinit_input_controller+0xbc> */
/* @0x2b428c ldr r3, [r7, #0xc] */
/* @0x2b4290 mov r0, r5 */
/* @0x2b4294 blx r3 */
/* @0x2b4298 cmp r0, #0 */
/* @0x2b429c beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b42a0 ldr r12, [r7] */
/* @0x2b42a4 ldr r3, [r7, #0x4] */
/* @0x2b42a8 ldr r2, [r5, #0x20] */
/* @0x2b42ac b 0x2b3fc8 <jinit_input_controller+0xe8> */
/* @0x2b42b0 ldr r12, [r7] */
/* @0x2b42b4 ldr r3, [r7, #0x4] */
/* @0x2b42b8 b 0x2b3f7c <jinit_input_controller+0x9c> */
/* @0x2b42bc ldr r3, [r7, #0xc] */
/* @0x2b42c0 mov r0, r5 */
/* @0x2b42c4 blx r3 */
/* @0x2b42c8 cmp r0, #0 */
/* @0x2b42cc beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b42d0 ldr r12, [r7] */
/* @0x2b42d4 ldr r3, [r7, #0x4] */
/* @0x2b42d8 b 0x2b3fe0 <jinit_input_controller+0x100> */
/* @0x2b42dc ldr r3, [r5, #0x24] */
/* @0x2b42e0 cmp r3, #0 */
/* @0x2b42e4 bgt 0x2b40c4 <jinit_input_controller+0x1e4> */
/* @0x2b42e8 b 0x2b40a8 <jinit_input_controller+0x1c8> */
/* @0x2b42ec ldr r2, [r5, #0x194] */
/* @0x2b42f0 mov r3, #1 */
/* @0x2b42f4 mov r0, r3 */
/* @0x2b42f8 strb r3, [r2, #0xd] */
/* @0x2b42fc str r10, [r7] */
/* @0x2b4300 str r6, [r7, #0x4] */
/* @0x2b4304 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b4308 ldr r3, [r7, #0xc] */
/* @0x2b430c mov r0, r5 */
/* @0x2b4310 blx r3 */
/* @0x2b4314 cmp r0, #0 */
/* @0x2b4318 beq 0x2b4218 <jinit_input_controller+0x338> */
/* @0x2b431c ldr r12, [r7] */
/* @0x2b4320 ldr r3, [r7, #0x4] */
/* @0x2b4324 ldr r2, [r5, #0x1c] */
/* @0x2b4328 b 0x2b3ff8 <jinit_input_controller+0x118> */
/* @0x2b432c ldr r3, [r5] */
/* @0x2b4330 mov r2, #58 */
/* @0x2b4334 mov r0, r5 */
/* @0x2b4338 str r2, [r3, #0x14] */
/* @0x2b433c ldr r3, [r3] */
/* @0x2b4340 blx r3 */
/* @0x2b4344 b 0x2b4090 <jinit_input_controller+0x1b0> */
/* @0x2b4348 ldr r1, [r5, #0x4] */
/* @0x2b434c mov r2, #84 */
/* @0x2b4350 mul r2, r2, r3 */
/* @0x2b4354 mov r0, r5 */
/* @0x2b4358 ldr r3, [r1] */
/* @0x2b435c mov r1, #1 */
/* @0x2b4360 blx r3 */
/* @0x2b4364 ldr r3, [r5, #0x24] */
/* @0x2b4368 mov r4, r0 */
/* @0x2b436c str r0, [r5, #0xc4] */
/* @0x2b4370 b 0x2b40f8 <jinit_input_controller+0x218> */
/* @0x2b4374 cmp r2, #13 */
/* @0x2b4378 add r3, r2, r3 */
/* @0x2b437c push {r4, r5, r6, r7, lr} */
/* @0x2b4380 mov r5, r1 */
/* @0x2b4384 sub sp, sp, #12 */
/* @0x2b4388 mov r4, r0 */
/* @0x2b438c bls 0x2b43c8 <jinit_input_controller+0x4e8> */
/* @0x2b4390 ldrb r2, [r1] */
/* @0x2b4394 cmp r2, #74 */
/* @0x2b4398 beq 0x2b43f0 <jinit_input_controller+0x510> */
/* @0x2b439c ldr r2, [r4] */
/* @0x2b43a0 mov r12, #77 */
/* @0x2b43a4 str r3, [r2, #0x18] */
/* @0x2b43a8 mov r0, r4 */
/* @0x2b43ac ldr r3, [r4] */
/* @0x2b43b0 mov r1, #1 */
/* @0x2b43b4 str r12, [r2, #0x14] */
/* @0x2b43b8 ldr r3, [r3, #0x4] */
/* @0x2b43bc blx r3 */
/* @0x2b43c0 add sp, sp, #12 */
/* @0x2b43c4 pop {r4, r5, r6, r7, pc} */
/* @0x2b43c8 cmp r2, #5 */
/* @0x2b43cc bls 0x2b439c <jinit_input_controller+0x4bc> */
/* @0x2b43d0 ldrb r2, [r1] */
/* @0x2b43d4 cmp r2, #74 */
/* @0x2b43d8 bne 0x2b439c <jinit_input_controller+0x4bc> */
/* @0x2b43dc ldrb r2, [r1, #0x1] */
/* @0x2b43e0 cmp r2, #70 */
/* @0x2b43e4 bne 0x2b439c <jinit_input_controller+0x4bc> */
/* @0x2b43e8 ldrb r2, [r1, #0x2] */
/* @0x2b43ec b 0x2b4408 <jinit_input_controller+0x528> */
/* @0x2b43f0 ldrb r2, [r1, #0x1] */
/* @0x2b43f4 cmp r2, #70 */
/* @0x2b43f8 bne 0x2b439c <jinit_input_controller+0x4bc> */
/* @0x2b43fc ldrb r2, [r1, #0x2] */
/* @0x2b4400 cmp r2, #73 */
/* @0x2b4404 beq 0x2b447c <jinit_input_controller+0x59c> */
/* @0x2b4408 cmp r2, #88 */
/* @0x2b440c bne 0x2b439c <jinit_input_controller+0x4bc> */
/* @0x2b4410 ldrb r2, [r5, #0x3] */
/* @0x2b4414 cmp r2, #88 */
/* @0x2b4418 bne 0x2b439c <jinit_input_controller+0x4bc> */
/* @0x2b441c ldrb r2, [r5, #0x4] */
/* @0x2b4420 cmp r2, #0 */
/* @0x2b4424 bne 0x2b439c <jinit_input_controller+0x4bc> */
/* @0x2b4428 ldrb r2, [r5, #0x5] */
/* @0x2b442c cmp r2, #17 */
/* @0x2b4430 beq 0x2b45b0 <jinit_input_controller+0x6d0> */
/* @0x2b4434 cmp r2, #19 */
/* @0x2b4438 beq 0x2b45a4 <jinit_input_controller+0x6c4> */
/* @0x2b443c cmp r2, #16 */
/* @0x2b4440 ldr r2, [r4] */
/* @0x2b4444 moveq r12, #108 */
/* @0x2b4448 beq 0x2b43a4 <jinit_input_controller+0x4c4> */
/* @0x2b444c mov r12, #89 */
/* @0x2b4450 str r12, [r2, #0x14] */
/* @0x2b4454 ldrb r12, [r5, #0x5] */
/* @0x2b4458 mov r0, r4 */
/* @0x2b445c mov r1, #1 */
/* @0x2b4460 str r12, [r2, #0x18] */
/* @0x2b4464 ldr r2, [r4] */
/* @0x2b4468 str r3, [r2, #0x1c] */
/* @0x2b446c ldr r3, [r4] */
/* @0x2b4470 ldr r3, [r3, #0x4] */
/* @0x2b4474 blx r3 */
/* @0x2b4478 b 0x2b43c0 <jinit_input_controller+0x4e0> */
/* @0x2b447c ldrb r2, [r1, #0x3] */
/* @0x2b4480 cmp r2, #70 */
/* @0x2b4484 bne 0x2b439c <jinit_input_controller+0x4bc> */
/* @0x2b4488 ldrb r2, [r1, #0x4] */
/* @0x2b448c cmp r2, #0 */
/* @0x2b4490 bne 0x2b439c <jinit_input_controller+0x4bc> */
/* @0x2b4494 mov r2, #1 */
/* @0x2b4498 strb r2, [r0, #0x100] */
/* @0x2b449c ldrb r2, [r1, #0x5] */
/* @0x2b44a0 mov r12, #260 */
/* @0x2b44a4 movw r1, #0x106 */
/* @0x2b44a8 cmp r2, #1 */
/* @0x2b44ac strb r2, [r0, #0x101] */
/* @0x2b44b0 ldrb r2, [r5, #0x6] */
/* @0x2b44b4 strb r2, [r0, #0x102] */
/* @0x2b44b8 ldrb r2, [r5, #0x7] */
/* @0x2b44bc strb r2, [r0, #0x103] */
/* @0x2b44c0 ldrb lr, [r5, #0x8] */
/* @0x2b44c4 ldrb r2, [r5, #0x9] */
/* @0x2b44c8 add r2, r2, lr, lsl #8 */
/* @0x2b44cc strh r2, [r0, r12] */
/* @0x2b44d0 ldrb r12, [r5, #0xa] */
/* @0x2b44d4 ldrb r2, [r5, #0xb] */
/* @0x2b44d8 add r2, r2, r12, lsl #8 */
/* @0x2b44dc strh r2, [r0, r1] */
/* @0x2b44e0 beq 0x2b451c <jinit_input_controller+0x63c> */
/* @0x2b44e4 ldr r2, [r0] */
/* @0x2b44e8 mov r12, #119 */
/* @0x2b44ec mvn r1, #0 */
/* @0x2b44f0 str r12, [r2, #0x14] */
/* @0x2b44f4 ldrb r12, [r0, #0x101] */
/* @0x2b44f8 str r12, [r2, #0x18] */
/* @0x2b44fc ldr r2, [r0] */
/* @0x2b4500 ldrb r12, [r0, #0x102] */
/* @0x2b4504 str r12, [r2, #0x1c] */
/* @0x2b4508 ldr r2, [r0] */
/* @0x2b450c ldr r2, [r2, #0x4] */
/* @0x2b4510 str r3, [sp, #0x4] */
/* @0x2b4514 blx r2 */
/* @0x2b4518 ldr r3, [sp, #0x4] */
/* @0x2b451c ldr r2, [r4] */
/* @0x2b4520 mov r12, #260 */
/* @0x2b4524 ldrb r1, [r4, #0x101] */
/* @0x2b4528 movw r0, #0x106 */
/* @0x2b452c ldrh lr, [r4, r0] */
/* @0x2b4530 mov r6, #87 */
/* @0x2b4534 ldrh r7, [r4, r12] */
/* @0x2b4538 mov r0, r4 */
/* @0x2b453c str r1, [r2, #0x18] */
/* @0x2b4540 mov r1, #1 */
/* @0x2b4544 ldrb r12, [r4, #0x102] */
/* @0x2b4548 str r7, [r2, #0x20] */
/* @0x2b454c str lr, [r2, #0x24] */
/* @0x2b4550 str r12, [r2, #0x1c] */
/* @0x2b4554 ldrb lr, [r4, #0x103] */
/* @0x2b4558 ldr r12, [r2, #0x4] */
/* @0x2b455c str r6, [r2, #0x14] */
/* @0x2b4560 str lr, [r2, #0x28] */
/* @0x2b4564 str r3, [sp, #0x4] */
/* @0x2b4568 blx r12 */
/* @0x2b456c ldrb r1, [r5, #0xd] */
/* @0x2b4570 ldrb r2, [r5, #0xc] */
/* @0x2b4574 ldr r3, [sp, #0x4] */
/* @0x2b4578 orrs r2, r1, r2 */
/* @0x2b457c moveq r1, r2 */
/* @0x2b4580 bne 0x2b45bc <jinit_input_controller+0x6dc> */
/* @0x2b4584 smulbb r2, r1, r2 */
/* @0x2b4588 sub r3, r3, #14 */
/* @0x2b458c add r2, r2, r2, lsl #1 */
/* @0x2b4590 cmp r2, r3 */
/* @0x2b4594 ldrne r2, [r4] */
/* @0x2b4598 movne r12, #88 */
/* @0x2b459c bne 0x2b43a4 <jinit_input_controller+0x4c4> */
/* @0x2b45a0 b 0x2b43c0 <jinit_input_controller+0x4e0> */
/* @0x2b45a4 ldr r2, [r4] */
/* @0x2b45a8 mov r12, #110 */
/* @0x2b45ac b 0x2b43a4 <jinit_input_controller+0x4c4> */
/* @0x2b45b0 ldr r2, [r4] */
/* @0x2b45b4 mov r12, #109 */
/* @0x2b45b8 b 0x2b43a4 <jinit_input_controller+0x4c4> */
/* @0x2b45bc ldr r2, [r4] */
/* @0x2b45c0 mov r12, #90 */
/* @0x2b45c4 mov r1, #1 */
/* @0x2b45c8 mov r0, r4 */
/* @0x2b45cc str r12, [r2, #0x14] */
/* @0x2b45d0 ldrb r12, [r5, #0xc] */
/* @0x2b45d4 str r12, [r2, #0x18] */
/* @0x2b45d8 ldr r2, [r4] */
/* @0x2b45dc ldrb r12, [r5, #0xd] */
/* @0x2b45e0 str r12, [r2, #0x1c] */
/* @0x2b45e4 ldr r2, [r4] */
/* @0x2b45e8 ldr r2, [r2, #0x4] */
/* @0x2b45ec str r3, [sp, #0x4] */
/* @0x2b45f0 blx r2 */
/* @0x2b45f4 ldrb r1, [r5, #0xc] */
/* @0x2b45f8 ldrb r2, [r5, #0xd] */
/* @0x2b45fc ldr r3, [sp, #0x4] */
/* @0x2b4600 b 0x2b4584 <jinit_input_controller+0x6a4> */
/* @0x2b4604 push {r4, r5, r6, r7, r8, lr} */
/* @0x2b4608 mov r4, r0 */
/* @0x2b460c ldr r5, [r0, #0x18] */
/* @0x2b4610 ldr r3, [r5, #0x4] */
/* @0x2b4614 ldr r6, [r5] */
/* @0x2b4618 cmp r3, #0 */
/* @0x2b461c beq 0x2b46c0 <jinit_input_controller+0x7e0> */
/* @0x2b4620 ldrb r7, [r6] */
/* @0x2b4624 subs r8, r3, #1 */
/* @0x2b4628 addne r6, r6, #1 */
/* @0x2b462c lsl r7, r7, #8 */
/* @0x2b4630 bne 0x2b464c <jinit_input_controller+0x76c> */
/* @0x2b4634 ldr r3, [r5, #0xc] */
/* @0x2b4638 mov r0, r4 */
/* @0x2b463c blx r3 */
/* @0x2b4640 cmp r0, #0 */
/* @0x2b4644 beq 0x2b46d8 <jinit_input_controller+0x7f8> */
/* @0x2b4648 ldm r5, {r6, r8} */
/* @0x2b464c ldr r2, [r4] */
/* @0x2b4650 mov r1, #91 */
/* @0x2b4654 ldr r12, [r4, #0x17c] */
/* @0x2b4658 mov r0, r4 */
/* @0x2b465c ldrb r3, [r6], #1 */
/* @0x2b4660 sub r8, r8, #1 */
/* @0x2b4664 str r1, [r2, #0x14] */
/* @0x2b4668 mov r1, #1 */
/* @0x2b466c str r12, [r2, #0x18] */
/* @0x2b4670 add r7, r3, r7 */
/* @0x2b4674 ldr r3, [r4] */
/* @0x2b4678 sub r7, r7, #2 */
/* @0x2b467c str r7, [r3, #0x1c] */
/* @0x2b4680 ldr r3, [r4] */
/* @0x2b4684 ldr r3, [r3, #0x4] */
/* @0x2b4688 blx r3 */
/* @0x2b468c cmp r7, #0 */
/* @0x2b4690 str r6, [r5] */
/* @0x2b4694 str r8, [r5, #0x4] */
/* @0x2b4698 ble 0x2b46b8 <jinit_input_controller+0x7d8> */
/* @0x2b469c ldr r3, [r4, #0x18] */
/* @0x2b46a0 mov r0, r4 */
/* @0x2b46a4 mov r1, r7 */
/* @0x2b46a8 ldr r3, [r3, #0x10] */
/* @0x2b46ac blx r3 */
/* @0x2b46b0 mov r0, #1 */
/* @0x2b46b4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2b46b8 mov r0, #1 */
/* @0x2b46bc pop {r4, r5, r6, r7, r8, pc} */
/* @0x2b46c0 ldr r3, [r5, #0xc] */
/* @0x2b46c4 blx r3 */
/* @0x2b46c8 cmp r0, #0 */
/* @0x2b46cc ldrne r6, [r5] */
/* @0x2b46d0 ldrne r3, [r5, #0x4] */
/* @0x2b46d4 bne 0x2b4620 <jinit_input_controller+0x740> */
/* @0x2b46d8 mov r0, #0 */
/* @0x2b46dc pop {r4, r5, r6, r7, r8, pc} */
/* @0x2b46e0 push {r4, r5, r6, r7, r8, lr} */
/* @0x2b46e4 mov r8, r0 */
/* @0x2b46e8 ldr r5, [r0, #0x18] */
/* @0x2b46ec ldr r4, [r5, #0x4] */
/* @0x2b46f0 ldr r6, [r5] */
/* @0x2b46f4 cmp r4, #0 */
/* @0x2b46f8 beq 0x2b47c8 <jinit_input_controller+0x8e8> */
/* @0x2b46fc ldrb r3, [r6] */
/* @0x2b4700 sub r4, r4, #1 */
/* @0x2b4704 add r2, r6, #1 */
/* @0x2b4708 cmp r3, #255 */
/* @0x2b470c bne 0x2b472c <jinit_input_controller+0x84c> */
/* @0x2b4710 b 0x2b47ec <jinit_input_controller+0x90c> */
/* @0x2b4714 ldrb r1, [r2] */
/* @0x2b4718 add r3, r2, #1 */
/* @0x2b471c sub r4, r4, #1 */
/* @0x2b4720 cmp r1, #255 */
/* @0x2b4724 mov r2, r3 */
/* @0x2b4728 beq 0x2b4794 <jinit_input_controller+0x8b4> */
/* @0x2b472c ldr r3, [r8, #0x194] */
/* @0x2b4730 cmp r4, #0 */
/* @0x2b4734 ldr r1, [r3, #0x14] */
/* @0x2b4738 add r1, r1, #1 */
/* @0x2b473c str r1, [r3, #0x14] */
/* @0x2b4740 stm r5, {r2, r4} */
/* @0x2b4744 bne 0x2b4714 <jinit_input_controller+0x834> */
/* @0x2b4748 ldr r3, [r5, #0xc] */
/* @0x2b474c mov r0, r8 */
/* @0x2b4750 blx r3 */
/* @0x2b4754 cmp r0, #0 */
/* @0x2b4758 beq 0x2b47e4 <jinit_input_controller+0x904> */
/* @0x2b475c ldm r5, {r2, r4} */
/* @0x2b4760 b 0x2b4714 <jinit_input_controller+0x834> */
/* @0x2b4764 ldr r3, [r5, #0xc] */
/* @0x2b4768 mov r0, r8 */
/* @0x2b476c blx r3 */
/* @0x2b4770 cmp r0, #0 */
/* @0x2b4774 beq 0x2b47e4 <jinit_input_controller+0x904> */
/* @0x2b4778 ldm r5, {r3, r4} */
/* @0x2b477c ldrb r7, [r3] */
/* @0x2b4780 add r6, r3, #1 */
/* @0x2b4784 sub r4, r4, #1 */
/* @0x2b4788 cmp r7, #255 */
/* @0x2b478c mov r3, r6 */
/* @0x2b4790 bne 0x2b47a0 <jinit_input_controller+0x8c0> */
/* @0x2b4794 cmp r4, #0 */
/* @0x2b4798 bne 0x2b477c <jinit_input_controller+0x89c> */
/* @0x2b479c b 0x2b4764 <jinit_input_controller+0x884> */
/* @0x2b47a0 cmp r7, #0 */
/* @0x2b47a4 ldr r3, [r8, #0x194] */
/* @0x2b47a8 bne 0x2b47f4 <jinit_input_controller+0x914> */
/* @0x2b47ac ldr r2, [r3, #0x14] */
/* @0x2b47b0 cmp r4, #0 */
/* @0x2b47b4 add r2, r2, #2 */
/* @0x2b47b8 str r2, [r3, #0x14] */
/* @0x2b47bc str r6, [r5] */
/* @0x2b47c0 str r4, [r5, #0x4] */
/* @0x2b47c4 bne 0x2b46fc <jinit_input_controller+0x81c> */
/* @0x2b47c8 ldr r3, [r5, #0xc] */
/* @0x2b47cc mov r0, r8 */
/* @0x2b47d0 blx r3 */
/* @0x2b47d4 cmp r0, #0 */
/* @0x2b47d8 ldrne r6, [r5] */
/* @0x2b47dc ldrne r4, [r5, #0x4] */
/* @0x2b47e0 bne 0x2b46fc <jinit_input_controller+0x81c> */
/* @0x2b47e4 mov r0, #0 */
/* @0x2b47e8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2b47ec mov r3, r2 */
/* @0x2b47f0 b 0x2b4794 <jinit_input_controller+0x8b4> */
/* @0x2b47f4 ldr r3, [r3, #0x14] */
/* @0x2b47f8 cmp r3, #0 */
/* @0x2b47fc bne 0x2b4814 <jinit_input_controller+0x934> */
/* @0x2b4800 str r7, [r8, #0x17c] */
/* @0x2b4804 mov r0, #1 */
/* @0x2b4808 str r6, [r5] */
/* @0x2b480c str r4, [r5, #0x4] */
/* @0x2b4810 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2b4814 ldr r2, [r8] */
/* @0x2b4818 mov r12, #116 */
/* @0x2b481c mov r0, r8 */
/* @0x2b4820 mvn r1, #0 */
/* @0x2b4824 str r3, [r2, #0x18] */
/* @0x2b4828 ldr r3, [r8] */
/* @0x2b482c str r12, [r2, #0x14] */
/* @0x2b4830 str r7, [r3, #0x1c] */
/* @0x2b4834 ldr r3, [r8] */
/* @0x2b4838 ldr r3, [r3, #0x4] */
/* @0x2b483c blx r3 */
/* @0x2b4840 ldr r3, [r8, #0x194] */
/* @0x2b4844 mov r2, #0 */
/* @0x2b4848 str r2, [r3, #0x14] */
/* @0x2b484c b 0x2b4800 <jinit_input_controller+0x920> */
/* @0x2b4850 ldr r2, [r0, #0x194] */
/* @0x2b4854 mov r3, #0 */
/* @0x2b4858 str r3, [r0, #0xc4] */
/* @0x2b485c str r3, [r0, #0x7c] */
/* @0x2b4860 str r3, [r0, #0x17c] */
/* @0x2b4864 strb r3, [r2, #0xc] */
/* @0x2b4868 strb r3, [r2, #0xd] */
/* @0x2b486c str r3, [r2, #0x14] */
/* @0x2b4870 str r3, [r2, #0xa0] */
/* @0x2b4874 bx lr */
/* @0x2b4878 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b487c sub sp, sp, #308 */
/* @0x2b4880 ldr r11, [r0, #0x18] */
/* @0x2b4884 mov r7, r0 */
/* @0x2b4888 ldr r12, [pc, #0x3b8] */
/* @0x2b488c ldr r12, [pc, r12] */
/* @0x2b4890 ldr r4, [r11, #0x4] */
/* @0x2b4894 str r12, [sp, #0x8] */
/* @0x2b4898 ldr r3, [r12] */
/* @0x2b489c cmp r4, #0 */
/* @0x2b48a0 ldr r5, [r11] */
/* @0x2b48a4 str r3, [sp, #0x12c] */
/* @0x2b48a8 beq 0x2b4b74 <jinit_input_controller+0xc94> */
/* @0x2b48ac ldrb r3, [r5] */
/* @0x2b48b0 subs r4, r4, #1 */
/* @0x2b48b4 addne r5, r5, #1 */
/* @0x2b48b8 lsl r6, r3, #8 */
/* @0x2b48bc beq 0x2b4be8 <jinit_input_controller+0xd08> */
/* @0x2b48c0 ldrb r9, [r5] */
/* @0x2b48c4 sub r4, r4, #1 */
/* @0x2b48c8 add r5, r5, #1 */
/* @0x2b48cc add r9, r9, r6 */
/* @0x2b48d0 sub r9, r9, #2 */
/* @0x2b48d4 str r9, [sp] */
/* @0x2b48d8 cmp r9, #16 */
/* @0x2b48dc ble 0x2b4b58 <jinit_input_controller+0xc78> */
/* @0x2b48e0 add r9, sp, #40 */
/* @0x2b48e4 add r12, sp, #24 */
/* @0x2b48e8 str r12, [sp, #0x14] */
/* @0x2b48ec cmp r4, #0 */
/* @0x2b48f0 bne 0x2b4910 <jinit_input_controller+0xa30> */
/* @0x2b48f4 ldr r3, [r11, #0xc] */
/* @0x2b48f8 mov r0, r7 */
/* @0x2b48fc blx r3 */
/* @0x2b4900 cmp r0, #0 */
/* @0x2b4904 beq 0x2b4b84 <jinit_input_controller+0xca4> */
/* @0x2b4908 ldr r5, [r11] */
/* @0x2b490c ldr r4, [r11, #0x4] */
/* @0x2b4910 ldrb r2, [r5] */
/* @0x2b4914 mov r1, #1 */
/* @0x2b4918 ldr r3, [r7] */
/* @0x2b491c mov r12, #80 */
/* @0x2b4920 mov r0, r7 */
/* @0x2b4924 sub r4, r4, #1 */
/* @0x2b4928 str r2, [sp, #0x4] */
/* @0x2b492c add r5, r5, #1 */
/* @0x2b4930 str r2, [r3, #0x18] */
/* @0x2b4934 add r10, sp, #24 */
/* @0x2b4938 str r2, [sp, #0x10] */
/* @0x2b493c mov r8, #0 */
/* @0x2b4940 ldr r2, [r7] */
/* @0x2b4944 str r12, [r3, #0x14] */
/* @0x2b4948 ldr r3, [r2, #0x4] */
/* @0x2b494c blx r3 */
/* @0x2b4950 mov r1, #0 */
/* @0x2b4954 strb r1, [sp, #0x18] */
/* @0x2b4958 b 0x2b4978 <jinit_input_controller+0xa98> */
/* @0x2b495c ldrb r3, [r5] */
/* @0x2b4960 sub r4, r4, #1 */
/* @0x2b4964 add r5, r5, #1 */
/* @0x2b4968 add r8, r8, r3 */
/* @0x2b496c strb r3, [r10, #0x1]! */
/* @0x2b4970 cmp r10, r9 */
/* @0x2b4974 beq 0x2b49a0 <jinit_input_controller+0xac0> */
/* @0x2b4978 cmp r4, #0 */
/* @0x2b497c bne 0x2b495c <jinit_input_controller+0xa7c> */
/* @0x2b4980 ldr r3, [r11, #0xc] */
/* @0x2b4984 mov r0, r7 */
/* @0x2b4988 blx r3 */
/* @0x2b498c cmp r0, #0 */
/* @0x2b4990 beq 0x2b4b84 <jinit_input_controller+0xca4> */
/* @0x2b4994 ldr r5, [r11] */
/* @0x2b4998 ldr r4, [r11, #0x4] */
/* @0x2b499c b 0x2b495c <jinit_input_controller+0xa7c> */
/* @0x2b49a0 ldr r2, [r7] */
/* @0x2b49a4 mov r0, r7 */
/* @0x2b49a8 ldrb r12, [sp, #0x1a] */
/* @0x2b49ac mov r1, #2 */
/* @0x2b49b0 ldrb lr, [sp, #0x19] */
/* @0x2b49b4 ldrb r10, [sp, #0x1b] */
/* @0x2b49b8 str r12, [r2, #0x1c] */
/* @0x2b49bc ldrb r12, [sp, #0x1c] */
/* @0x2b49c0 str lr, [r2, #0x18] */
/* @0x2b49c4 ldrb lr, [sp, #0x1d] */
/* @0x2b49c8 str r12, [r2, #0x24] */
/* @0x2b49cc ldrb r12, [sp, #0x1e] */
/* @0x2b49d0 str lr, [r2, #0x28] */
/* @0x2b49d4 ldrb lr, [sp, #0x1f] */
/* @0x2b49d8 str r12, [r2, #0x2c] */
/* @0x2b49dc ldrb r12, [sp, #0x20] */
/* @0x2b49e0 ldr r3, [sp] */
/* @0x2b49e4 str r10, [r2, #0x20] */
/* @0x2b49e8 str lr, [r2, #0x30] */
/* @0x2b49ec sub r3, r3, #17 */
/* @0x2b49f0 str r12, [r2, #0x34] */
/* @0x2b49f4 str r3, [sp] */
/* @0x2b49f8 mov r3, #86 */
/* @0x2b49fc str r3, [r2, #0x14] */
/* @0x2b4a00 ldr r2, [r2, #0x4] */
/* @0x2b4a04 blx r2 */
/* @0x2b4a08 ldr r2, [r7] */
/* @0x2b4a0c ldrb lr, [sp, #0x22] */
/* @0x2b4a10 mov r3, #86 */
/* @0x2b4a14 ldrb r12, [sp, #0x23] */
/* @0x2b4a18 mov r0, r7 */
/* @0x2b4a1c ldrb r10, [sp, #0x21] */
/* @0x2b4a20 mov r1, #2 */
/* @0x2b4a24 str lr, [r2, #0x1c] */
/* @0x2b4a28 ldrb lr, [sp, #0x24] */
/* @0x2b4a2c str r12, [r2, #0x20] */
/* @0x2b4a30 ldrb r12, [sp, #0x25] */
/* @0x2b4a34 str lr, [r2, #0x24] */
/* @0x2b4a38 ldrb lr, [sp, #0x26] */
/* @0x2b4a3c str r12, [r2, #0x28] */
/* @0x2b4a40 ldrb r12, [sp, #0x27] */
/* @0x2b4a44 str lr, [r2, #0x2c] */
/* @0x2b4a48 ldrb lr, [sp, #0x28] */
/* @0x2b4a4c str r12, [r2, #0x30] */
/* @0x2b4a50 str r3, [r2, #0x14] */
/* @0x2b4a54 str r10, [r2, #0x18] */
/* @0x2b4a58 str lr, [r2, #0x34] */
/* @0x2b4a5c ldr r2, [r2, #0x4] */
/* @0x2b4a60 blx r2 */
/* @0x2b4a64 ldr r12, [sp] */
/* @0x2b4a68 cmp r8, #256 */
/* @0x2b4a6c cmple r8, r12 */
/* @0x2b4a70 bgt 0x2b4ba4 <jinit_input_controller+0xcc4> */
/* @0x2b4a74 cmp r8, #0 */
/* @0x2b4a78 add r12, sp, #44 */
/* @0x2b4a7c str r12, [sp, #0xc] */
/* @0x2b4a80 beq 0x2b4ad0 <jinit_input_controller+0xbf0> */
/* @0x2b4a84 add r6, sp, #43 */
/* @0x2b4a88 add r10, r6, r8 */
/* @0x2b4a8c b 0x2b4aa8 <jinit_input_controller+0xbc8> */
/* @0x2b4a90 ldrb r3, [r5] */
/* @0x2b4a94 sub r4, r4, #1 */
/* @0x2b4a98 add r5, r5, #1 */
/* @0x2b4a9c strb r3, [r6, #0x1]! */
/* @0x2b4aa0 cmp r6, r10 */
/* @0x2b4aa4 beq 0x2b4ad0 <jinit_input_controller+0xbf0> */
/* @0x2b4aa8 cmp r4, #0 */
/* @0x2b4aac bne 0x2b4a90 <jinit_input_controller+0xbb0> */
/* @0x2b4ab0 ldr r3, [r11, #0xc] */
/* @0x2b4ab4 mov r0, r7 */
/* @0x2b4ab8 blx r3 */
/* @0x2b4abc cmp r0, #0 */
/* @0x2b4ac0 beq 0x2b4b84 <jinit_input_controller+0xca4> */
/* @0x2b4ac4 ldr r5, [r11] */
/* @0x2b4ac8 ldr r4, [r11, #0x4] */
/* @0x2b4acc b 0x2b4a90 <jinit_input_controller+0xbb0> */
/* @0x2b4ad0 ldr r2, [sp, #0x4] */
/* @0x2b4ad4 ldr r3, [sp] */
/* @0x2b4ad8 tst r2, #16 */
/* @0x2b4adc rsb r8, r8, r3 */
/* @0x2b4ae0 addne r3, r2, #28 */
/* @0x2b4ae4 ldreq r2, [sp, #0x4] */
/* @0x2b4ae8 subne r12, r2, #16 */
/* @0x2b4aec addne r6, r7, r3, lsl #2 */
/* @0x2b4af0 strne r12, [sp, #0x10] */
/* @0x2b4af4 addeq r6, r2, #40 */
/* @0x2b4af8 ldr r3, [sp, #0x10] */
/* @0x2b4afc str r8, [sp] */
/* @0x2b4b00 addeq r6, r7, r6, lsl #2 */
/* @0x2b4b04 cmp r3, #3 */
/* @0x2b4b08 bhi 0x2b4bc0 <jinit_input_controller+0xce0> */
/* @0x2b4b0c ldr lr, [r6] */
/* @0x2b4b10 cmp lr, #0 */
/* @0x2b4b14 beq 0x2b4c14 <jinit_input_controller+0xd34> */
/* @0x2b4b18 add r12, sp, #24 */
/* @0x2b4b1c ldm r12!, {r0, r1, r2, r3} */
/* @0x2b4b20 ldrb r12, [r12] */
/* @0x2b4b24 str r1, [lr, #0x4] */
/* @0x2b4b28 str r2, [lr, #0x8] */
/* @0x2b4b2c mov r2, #256 */
/* @0x2b4b30 strb r12, [lr, #0x10] */
/* @0x2b4b34 str r0, [lr] */
/* @0x2b4b38 str r3, [lr, #0xc] */
/* @0x2b4b3c ldr r0, [r6] */
/* @0x2b4b40 ldr r1, [sp, #0xc] */
/* @0x2b4b44 add r0, r0, #17 */
/* @0x2b4b48 bl 0xb65bc <memcpy@plt> */
/* @0x2b4b4c ldr r12, [sp] */
/* @0x2b4b50 cmp r12, #16 */
/* @0x2b4b54 bgt 0x2b48ec <jinit_input_controller+0xa0c> */
/* @0x2b4b58 ldr r12, [sp] */
/* @0x2b4b5c cmp r12, #0 */
/* @0x2b4b60 bne 0x2b4c28 <jinit_input_controller+0xd48> */
/* @0x2b4b64 mov r0, #1 */
/* @0x2b4b68 str r5, [r11] */
/* @0x2b4b6c str r4, [r11, #0x4] */
/* @0x2b4b70 b 0x2b4b88 <jinit_input_controller+0xca8> */
/* @0x2b4b74 ldr r3, [r11, #0xc] */
/* @0x2b4b78 blx r3 */
/* @0x2b4b7c cmp r0, #0 */
/* @0x2b4b80 bne 0x2b4c08 <jinit_input_controller+0xd28> */
/* @0x2b4b84 mov r0, #0 */
/* @0x2b4b88 ldr r12, [sp, #0x8] */
/* @0x2b4b8c ldr r2, [sp, #0x12c] */
/* @0x2b4b90 ldr r3, [r12] */
/* @0x2b4b94 cmp r2, r3 */
/* @0x2b4b98 bne 0x2b4c44 <jinit_input_controller+0xd64> */
/* @0x2b4b9c add sp, sp, #308 */
/* @0x2b4ba0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b4ba4 ldr r2, [r7] */
/* @0x2b4ba8 mov r1, #8 */
/* @0x2b4bac mov r0, r7 */
/* @0x2b4bb0 str r1, [r2, #0x14] */
/* @0x2b4bb4 ldr r2, [r2] */
/* @0x2b4bb8 blx r2 */
/* @0x2b4bbc b 0x2b4a74 <jinit_input_controller+0xb94> */
/* @0x2b4bc0 ldr r3, [r7] */
/* @0x2b4bc4 mov r1, #30 */
/* @0x2b4bc8 ldr r12, [sp, #0x10] */
/* @0x2b4bcc mov r0, r7 */
/* @0x2b4bd0 str r12, [r3, #0x18] */
/* @0x2b4bd4 ldr r2, [r7] */
/* @0x2b4bd8 str r1, [r3, #0x14] */
/* @0x2b4bdc ldr r3, [r2] */
/* @0x2b4be0 blx r3 */
/* @0x2b4be4 b 0x2b4b0c <jinit_input_controller+0xc2c> */
/* @0x2b4be8 ldr r3, [r11, #0xc] */
/* @0x2b4bec mov r0, r7 */
/* @0x2b4bf0 blx r3 */
/* @0x2b4bf4 cmp r0, #0 */
/* @0x2b4bf8 beq 0x2b4b84 <jinit_input_controller+0xca4> */
/* @0x2b4bfc ldr r5, [r11] */
/* @0x2b4c00 ldr r4, [r11, #0x4] */
/* @0x2b4c04 b 0x2b48c0 <jinit_input_controller+0x9e0> */
/* @0x2b4c08 ldr r5, [r11] */
/* @0x2b4c0c ldr r4, [r11, #0x4] */
/* @0x2b4c10 b 0x2b48ac <jinit_input_controller+0x9cc> */
/* @0x2b4c14 mov r0, r7 */
/* @0x2b4c18 bl 0x2bc908 <jpeg_alloc_huff_table> */
/* @0x2b4c1c mov lr, r0 */
/* @0x2b4c20 str r0, [r6] */
/* @0x2b4c24 b 0x2b4b18 <jinit_input_controller+0xc38> */
/* @0x2b4c28 ldr r3, [r7] */
/* @0x2b4c2c mov r1, #11 */
/* @0x2b4c30 mov r0, r7 */
/* @0x2b4c34 ldr r2, [r3] */
/* @0x2b4c38 str r1, [r3, #0x14] */
/* @0x2b4c3c blx r2 */
/* @0x2b4c40 b 0x2b4b64 <jinit_input_controller+0xc84> */
/* @0x2b4c44 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b4c48 andseq r9, r3, r4, asr #1 */
/* @0x2b4c4c ldr r3, [r0, #0x17c] */
/* @0x2b4c50 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b4c54 cmp r3, #0 */
/* @0x2b4c58 sub sp, sp, #12 */
/* @0x2b4c5c mov r11, r0 */
/* @0x2b4c60 bne 0x2b4cc0 <jinit_input_controller+0xde0> */
/* @0x2b4c64 ldr r3, [r11, #0x194] */
/* @0x2b4c68 ldrb r3, [r3, #0xc] */
/* @0x2b4c6c cmp r3, #0 */
/* @0x2b4c70 bne 0x2b4e14 <jinit_input_controller+0xf34> */
/* @0x2b4c74 ldr r4, [r11, #0x18] */
/* @0x2b4c78 ldr r3, [r4, #0x4] */
/* @0x2b4c7c ldr r7, [r4] */
/* @0x2b4c80 cmp r3, #0 */
/* @0x2b4c84 beq 0x2b50c8 <jinit_input_controller+0x11e8> */
/* @0x2b4c88 subs r3, r3, #1 */
/* @0x2b4c8c ldrb r9, [r7] */
/* @0x2b4c90 addne r7, r7, #1 */
/* @0x2b4c94 beq 0x2b5178 <jinit_input_controller+0x1298> */
/* @0x2b4c98 ldrb r5, [r7] */
/* @0x2b4c9c sub r6, r3, #1 */
/* @0x2b4ca0 add r7, r7, #1 */
/* @0x2b4ca4 cmp r9, #255 */
/* @0x2b4ca8 cmpeq r5, #216 */
/* @0x2b4cac bne 0x2b55e4 <jinit_input_controller+0x1704> */
/* @0x2b4cb0 mov r3, r5 */
/* @0x2b4cb4 str r5, [r11, #0x17c] */
/* @0x2b4cb8 str r7, [r4] */
/* @0x2b4cbc str r6, [r4, #0x4] */
/* @0x2b4cc0 cmp r3, #207 */
/* @0x2b4cc4 ble 0x2b4db8 <jinit_input_controller+0xed8> */
/* @0x2b4cc8 cmp r3, #219 */
/* @0x2b4ccc beq 0x2b52a8 <jinit_input_controller+0x13c8> */
/* @0x2b4cd0 ble 0x2b4e2c <jinit_input_controller+0xf4c> */
/* @0x2b4cd4 cmp r3, #239 */
/* @0x2b4cd8 bgt 0x2b5210 <jinit_input_controller+0x1330> */
/* @0x2b4cdc cmp r3, #224 */
/* @0x2b4ce0 bge 0x2b5234 <jinit_input_controller+0x1354> */
/* @0x2b4ce4 cmp r3, #220 */
/* @0x2b4ce8 beq 0x2b5128 <jinit_input_controller+0x1248> */
/* @0x2b4cec cmp r3, #221 */
/* @0x2b4cf0 bne 0x2b51a8 <jinit_input_controller+0x12c8> */
/* @0x2b4cf4 ldr r4, [r11, #0x18] */
/* @0x2b4cf8 ldm r4, {r2, r3} */
/* @0x2b4cfc cmp r3, #0 */
/* @0x2b4d00 beq 0x2b56ac <jinit_input_controller+0x17cc> */
/* @0x2b4d04 ldrb r6, [r2] */
/* @0x2b4d08 subs r3, r3, #1 */
/* @0x2b4d0c addne r5, r2, #1 */
/* @0x2b4d10 lsl r6, r6, #8 */
/* @0x2b4d14 beq 0x2b5708 <jinit_input_controller+0x1828> */
/* @0x2b4d18 ldrb r2, [r5] */
/* @0x2b4d1c sub r7, r3, #1 */
/* @0x2b4d20 add r6, r6, r2 */
/* @0x2b4d24 cmp r6, #4 */
/* @0x2b4d28 beq 0x2b4d44 <jinit_input_controller+0xe64> */
/* @0x2b4d2c ldr r3, [r11] */
/* @0x2b4d30 mov lr, #11 */
/* @0x2b4d34 mov r0, r11 */
/* @0x2b4d38 str lr, [r3, #0x14] */
/* @0x2b4d3c ldr r3, [r3] */
/* @0x2b4d40 blx r3 */
/* @0x2b4d44 cmp r7, #0 */
/* @0x2b4d48 addne r5, r5, #1 */
/* @0x2b4d4c beq 0x2b5744 <jinit_input_controller+0x1864> */
/* @0x2b4d50 ldrb r6, [r5] */
/* @0x2b4d54 subs r7, r7, #1 */
/* @0x2b4d58 addne r5, r5, #1 */
/* @0x2b4d5c lsl r6, r6, #8 */
/* @0x2b4d60 bne 0x2b4d7c <jinit_input_controller+0xe9c> */
/* @0x2b4d64 ldr r3, [r4, #0xc] */
/* @0x2b4d68 mov r0, r11 */
/* @0x2b4d6c blx r3 */
/* @0x2b4d70 cmp r0, #0 */
/* @0x2b4d74 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b4d78 ldm r4, {r5, r7} */
/* @0x2b4d7c ldr r3, [r11] */
/* @0x2b4d80 mov r1, #82 */
/* @0x2b4d84 ldrb r2, [r5], #1 */
/* @0x2b4d88 mov r0, r11 */
/* @0x2b4d8c sub r7, r7, #1 */
/* @0x2b4d90 add r6, r2, r6 */
/* @0x2b4d94 str r6, [r3, #0x18] */
/* @0x2b4d98 ldr r2, [r11] */
/* @0x2b4d9c str r1, [r3, #0x14] */
/* @0x2b4da0 mov r1, #1 */
/* @0x2b4da4 ldr r3, [r2, #0x4] */
/* @0x2b4da8 blx r3 */
/* @0x2b4dac str r6, [r11, #0xfc] */
/* @0x2b4db0 stm r4, {r5, r7} */
/* @0x2b4db4 b 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b4db8 cmp r3, #205 */
/* @0x2b4dbc bge 0x2b5254 <jinit_input_controller+0x1374> */
/* @0x2b4dc0 cmp r3, #196 */
/* @0x2b4dc4 beq 0x2b5294 <jinit_input_controller+0x13b4> */
/* @0x2b4dc8 ble 0x2b50e8 <jinit_input_controller+0x1208> */
/* @0x2b4dcc cmp r3, #201 */
/* @0x2b4dd0 beq 0x2b5278 <jinit_input_controller+0x1398> */
/* @0x2b4dd4 blt 0x2b5254 <jinit_input_controller+0x1374> */
/* @0x2b4dd8 cmp r3, #203 */
/* @0x2b4ddc beq 0x2b5254 <jinit_input_controller+0x1374> */
/* @0x2b4de0 movle r1, #1 */
/* @0x2b4de4 bgt 0x2b5128 <jinit_input_controller+0x1248> */
/* @0x2b4de8 mov r0, r11 */
/* @0x2b4dec mov r2, r1 */
/* @0x2b4df0 bl 0x2b3f58 <jinit_input_controller+0x78> */
/* @0x2b4df4 cmp r0, #0 */
/* @0x2b4df8 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b4dfc mov r3, #0 */
/* @0x2b4e00 str r3, [r11, #0x17c] */
/* @0x2b4e04 ldr r3, [r11, #0x194] */
/* @0x2b4e08 ldrb r3, [r3, #0xc] */
/* @0x2b4e0c cmp r3, #0 */
/* @0x2b4e10 beq 0x2b4c74 <jinit_input_controller+0xd94> */
/* @0x2b4e14 mov r0, r11 */
/* @0x2b4e18 bl 0x2b46e0 <jinit_input_controller+0x800> */
/* @0x2b4e1c cmp r0, #0 */
/* @0x2b4e20 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b4e24 ldr r3, [r11, #0x17c] */
/* @0x2b4e28 b 0x2b4cc0 <jinit_input_controller+0xde0> */
/* @0x2b4e2c cmp r3, #216 */
/* @0x2b4e30 beq 0x2b5514 <jinit_input_controller+0x1634> */
/* @0x2b4e34 blt 0x2b5100 <jinit_input_controller+0x1220> */
/* @0x2b4e38 cmp r3, #217 */
/* @0x2b4e3c beq 0x2b55b4 <jinit_input_controller+0x16d4> */
/* @0x2b4e40 cmp r3, #218 */
/* @0x2b4e44 bne 0x2b51a8 <jinit_input_controller+0x12c8> */
/* @0x2b4e48 ldr r3, [r11, #0x194] */
/* @0x2b4e4c ldr r8, [r11, #0x18] */
/* @0x2b4e50 ldrb r3, [r3, #0xd] */
/* @0x2b4e54 ldr r5, [r8] */
/* @0x2b4e58 cmp r3, #0 */
/* @0x2b4e5c ldr r4, [r8, #0x4] */
/* @0x2b4e60 beq 0x2b5674 <jinit_input_controller+0x1794> */
/* @0x2b4e64 cmp r4, #0 */
/* @0x2b4e68 beq 0x2b5654 <jinit_input_controller+0x1774> */
/* @0x2b4e6c ldrb r3, [r5] */
/* @0x2b4e70 subs r4, r4, #1 */
/* @0x2b4e74 addne r5, r5, #1 */
/* @0x2b4e78 lsl r6, r3, #8 */
/* @0x2b4e7c beq 0x2b56e8 <jinit_input_controller+0x1808> */
/* @0x2b4e80 ldrb r3, [r5] */
/* @0x2b4e84 subs r12, r4, #1 */
/* @0x2b4e88 addne r5, r5, #1 */
/* @0x2b4e8c add r6, r6, r3 */
/* @0x2b4e90 bne 0x2b4eac <jinit_input_controller+0xfcc> */
/* @0x2b4e94 ldr r3, [r8, #0xc] */
/* @0x2b4e98 mov r0, r11 */
/* @0x2b4e9c blx r3 */
/* @0x2b4ea0 cmp r0, #0 */
/* @0x2b4ea4 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b4ea8 ldm r8, {r5, r12} */
/* @0x2b4eac ldrb r10, [r5] */
/* @0x2b4eb0 mov lr, #103 */
/* @0x2b4eb4 ldr r3, [r11] */
/* @0x2b4eb8 mov r1, #1 */
/* @0x2b4ebc mov r0, r11 */
/* @0x2b4ec0 sub r9, r12, #1 */
/* @0x2b4ec4 add r5, r5, r1 */
/* @0x2b4ec8 str r10, [r3, #0x18] */
/* @0x2b4ecc ldr r2, [r11] */
/* @0x2b4ed0 str lr, [r3, #0x14] */
/* @0x2b4ed4 ldr r3, [r2, #0x4] */
/* @0x2b4ed8 blx r3 */
/* @0x2b4edc add r3, r10, #3 */
/* @0x2b4ee0 cmp r6, r3, lsl #1 */
/* @0x2b4ee4 beq 0x2b5644 <jinit_input_controller+0x1764> */
/* @0x2b4ee8 ldr r3, [r11] */
/* @0x2b4eec mov r2, #11 */
/* @0x2b4ef0 mov r0, r11 */
/* @0x2b4ef4 str r2, [r3, #0x14] */
/* @0x2b4ef8 ldr r3, [r3] */
/* @0x2b4efc blx r3 */
/* @0x2b4f00 cmp r10, #0 */
/* @0x2b4f04 str r10, [r11, #0x124] */
/* @0x2b4f08 beq 0x2b5000 <jinit_input_controller+0x1120> */
/* @0x2b4f0c mov r7, r11 */
/* @0x2b4f10 mov r6, #1 */
/* @0x2b4f14 add r10, r10, #1 */
/* @0x2b4f18 str r10, [sp, #0x4] */
/* @0x2b4f1c cmp r9, #0 */
/* @0x2b4f20 beq 0x2b51cc <jinit_input_controller+0x12ec> */
/* @0x2b4f24 subs r9, r9, #1 */
/* @0x2b4f28 ldrb r10, [r5] */
/* @0x2b4f2c addne r3, r5, #1 */
/* @0x2b4f30 beq 0x2b51f4 <jinit_input_controller+0x1314> */
/* @0x2b4f34 ldr r0, [r11, #0x24] */
/* @0x2b4f38 sub r9, r9, #1 */
/* @0x2b4f3c add r5, r3, #1 */
/* @0x2b4f40 ldrb r1, [r3] */
/* @0x2b4f44 cmp r0, #0 */
/* @0x2b4f48 ldr r4, [r11, #0xc4] */
/* @0x2b4f4c ble 0x2b4f80 <jinit_input_controller+0x10a0> */
/* @0x2b4f50 ldr r3, [r4] */
/* @0x2b4f54 cmp r10, r3 */
/* @0x2b4f58 beq 0x2b4fa8 <jinit_input_controller+0x10c8> */
/* @0x2b4f5c mov r3, #0 */
/* @0x2b4f60 b 0x2b4f70 <jinit_input_controller+0x1090> */
/* @0x2b4f64 ldr r2, [r4] */
/* @0x2b4f68 cmp r10, r2 */
/* @0x2b4f6c beq 0x2b4fa8 <jinit_input_controller+0x10c8> */
/* @0x2b4f70 add r3, r3, #1 */
/* @0x2b4f74 add r4, r4, #84 */
/* @0x2b4f78 cmp r3, r0 */
/* @0x2b4f7c bne 0x2b4f64 <jinit_input_controller+0x1084> */
/* @0x2b4f80 ldr r3, [r11] */
/* @0x2b4f84 mov r12, #5 */
/* @0x2b4f88 mov r0, r11 */
/* @0x2b4f8c str r10, [r3, #0x18] */
/* @0x2b4f90 ldr r2, [r11] */
/* @0x2b4f94 str r12, [r3, #0x14] */
/* @0x2b4f98 ldr r3, [r2] */
/* @0x2b4f9c str r1, [sp] */
/* @0x2b4fa0 blx r3 */
/* @0x2b4fa4 ldr r1, [sp] */
/* @0x2b4fa8 str r4, [r7, #0x128] */
/* @0x2b4fac asr r2, r1, #4 */
/* @0x2b4fb0 ldr r3, [r11] */
/* @0x2b4fb4 and r1, r1, #15 */
/* @0x2b4fb8 str r2, [r4, #0x14] */
/* @0x2b4fbc mov r12, #104 */
/* @0x2b4fc0 str r1, [r4, #0x18] */
/* @0x2b4fc4 mov r0, r11 */
/* @0x2b4fc8 str r10, [r3, #0x18] */
/* @0x2b4fcc mov r1, #1 */
/* @0x2b4fd0 ldr lr, [r4, #0x14] */
/* @0x2b4fd4 add r6, r6, #1 */
/* @0x2b4fd8 ldr r2, [r3, #0x4] */
/* @0x2b4fdc add r7, r7, #4 */
/* @0x2b4fe0 str lr, [r3, #0x1c] */
/* @0x2b4fe4 ldr lr, [r4, #0x18] */
/* @0x2b4fe8 str r12, [r3, #0x14] */
/* @0x2b4fec str lr, [r3, #0x20] */
/* @0x2b4ff0 blx r2 */
/* @0x2b4ff4 ldr r2, [sp, #0x4] */
/* @0x2b4ff8 cmp r6, r2 */
/* @0x2b4ffc bne 0x2b4f1c <jinit_input_controller+0x103c> */
/* @0x2b5000 cmp r9, #0 */
/* @0x2b5004 beq 0x2b5774 <jinit_input_controller+0x1894> */
/* @0x2b5008 ldrb r3, [r5] */
/* @0x2b500c subs r12, r9, #1 */
/* @0x2b5010 addne r5, r5, #1 */
/* @0x2b5014 str r3, [r11, #0x16c] */
/* @0x2b5018 beq 0x2b5790 <jinit_input_controller+0x18b0> */
/* @0x2b501c ldrb r3, [r5] */
/* @0x2b5020 subs r6, r12, #1 */
/* @0x2b5024 addne r4, r5, #1 */
/* @0x2b5028 str r3, [r11, #0x170] */
/* @0x2b502c bne 0x2b5048 <jinit_input_controller+0x1168> */
/* @0x2b5030 ldr r3, [r8, #0xc] */
/* @0x2b5034 mov r0, r11 */
/* @0x2b5038 blx r3 */
/* @0x2b503c cmp r0, #0 */
/* @0x2b5040 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5044 ldm r8, {r4, r6} */
/* @0x2b5048 ldrb r2, [r4], #1 */
/* @0x2b504c mov lr, #105 */
/* @0x2b5050 ldr r3, [r11] */
/* @0x2b5054 mov r0, r11 */
/* @0x2b5058 ldr r1, [r11, #0x16c] */
/* @0x2b505c and r12, r2, #15 */
/* @0x2b5060 asr r2, r2, #4 */
/* @0x2b5064 str r12, [r11, #0x178] */
/* @0x2b5068 str r2, [r11, #0x174] */
/* @0x2b506c sub r6, r6, #1 */
/* @0x2b5070 str r1, [r3, #0x18] */
/* @0x2b5074 mov r1, #1 */
/* @0x2b5078 ldr r12, [r11, #0x170] */
/* @0x2b507c ldr r2, [r3, #0x4] */
/* @0x2b5080 str r12, [r3, #0x1c] */
/* @0x2b5084 ldr r12, [r11, #0x174] */
/* @0x2b5088 str r12, [r3, #0x20] */
/* @0x2b508c ldr r12, [r11, #0x178] */
/* @0x2b5090 str lr, [r3, #0x14] */
/* @0x2b5094 str r12, [r3, #0x24] */
/* @0x2b5098 blx r2 */
/* @0x2b509c ldr r1, [r11, #0x194] */
/* @0x2b50a0 ldr r2, [r11, #0x7c] */
/* @0x2b50a4 mov r3, #0 */
/* @0x2b50a8 mov r0, #1 */
/* @0x2b50ac str r3, [r1, #0x10] */
/* @0x2b50b0 add r2, r2, r0 */
/* @0x2b50b4 str r2, [r11, #0x7c] */
/* @0x2b50b8 stm r8, {r4, r6} */
/* @0x2b50bc str r3, [r11, #0x17c] */
/* @0x2b50c0 add sp, sp, #12 */
/* @0x2b50c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b50c8 ldr r3, [r4, #0xc] */
/* @0x2b50cc mov r0, r11 */
/* @0x2b50d0 blx r3 */
/* @0x2b50d4 cmp r0, #0 */
/* @0x2b50d8 bne 0x2b5160 <jinit_input_controller+0x1280> */
/* @0x2b50dc mov r0, #0 */
/* @0x2b50e0 add sp, sp, #12 */
/* @0x2b50e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b50e8 cmp r3, #193 */
/* @0x2b50ec bgt 0x2b513c <jinit_input_controller+0x125c> */
/* @0x2b50f0 cmp r3, #192 */
/* @0x2b50f4 bge 0x2b5198 <jinit_input_controller+0x12b8> */
/* @0x2b50f8 cmp r3, #1 */
/* @0x2b50fc bne 0x2b51a8 <jinit_input_controller+0x12c8> */
/* @0x2b5100 ldr r2, [r11] */
/* @0x2b5104 mov r12, #92 */
/* @0x2b5108 mov r0, r11 */
/* @0x2b510c mov r1, #1 */
/* @0x2b5110 str r3, [r2, #0x18] */
/* @0x2b5114 ldr r3, [r11] */
/* @0x2b5118 str r12, [r2, #0x14] */
/* @0x2b511c ldr r3, [r3, #0x4] */
/* @0x2b5120 blx r3 */
/* @0x2b5124 b 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5128 mov r0, r11 */
/* @0x2b512c bl 0x2b4604 <jinit_input_controller+0x724> */
/* @0x2b5130 cmp r0, #0 */
/* @0x2b5134 bne 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5138 b 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b513c cmp r3, #194 */
/* @0x2b5140 bne 0x2b51a0 <jinit_input_controller+0x12c0> */
/* @0x2b5144 mov r0, r11 */
/* @0x2b5148 mov r1, #1 */
/* @0x2b514c mov r2, #0 */
/* @0x2b5150 bl 0x2b3f58 <jinit_input_controller+0x78> */
/* @0x2b5154 cmp r0, #0 */
/* @0x2b5158 bne 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b515c b 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5160 ldr r3, [r4, #0x4] */
/* @0x2b5164 ldr r7, [r4] */
/* @0x2b5168 subs r3, r3, #1 */
/* @0x2b516c ldrb r9, [r7] */
/* @0x2b5170 addne r7, r7, #1 */
/* @0x2b5174 bne 0x2b4c98 <jinit_input_controller+0xdb8> */
/* @0x2b5178 ldr r3, [r4, #0xc] */
/* @0x2b517c mov r0, r11 */
/* @0x2b5180 blx r3 */
/* @0x2b5184 cmp r0, #0 */
/* @0x2b5188 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b518c ldr r7, [r4] */
/* @0x2b5190 ldr r3, [r4, #0x4] */
/* @0x2b5194 b 0x2b4c98 <jinit_input_controller+0xdb8> */
/* @0x2b5198 mov r1, #0 */
/* @0x2b519c b 0x2b4de8 <jinit_input_controller+0xf08> */
/* @0x2b51a0 cmp r3, #195 */
/* @0x2b51a4 beq 0x2b5254 <jinit_input_controller+0x1374> */
/* @0x2b51a8 ldr r2, [r11] */
/* @0x2b51ac mov lr, #68 */
/* @0x2b51b0 mov r0, r11 */
/* @0x2b51b4 str r3, [r2, #0x18] */
/* @0x2b51b8 ldr r3, [r11] */
/* @0x2b51bc str lr, [r2, #0x14] */
/* @0x2b51c0 ldr r3, [r3] */
/* @0x2b51c4 blx r3 */
/* @0x2b51c8 b 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b51cc ldr r3, [r8, #0xc] */
/* @0x2b51d0 mov r0, r11 */
/* @0x2b51d4 blx r3 */
/* @0x2b51d8 cmp r0, #0 */
/* @0x2b51dc beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b51e0 ldm r8, {r5, r9} */
/* @0x2b51e4 subs r9, r9, #1 */
/* @0x2b51e8 ldrb r10, [r5] */
/* @0x2b51ec addne r3, r5, #1 */
/* @0x2b51f0 bne 0x2b4f34 <jinit_input_controller+0x1054> */
/* @0x2b51f4 ldr r3, [r8, #0xc] */
/* @0x2b51f8 mov r0, r11 */
/* @0x2b51fc blx r3 */
/* @0x2b5200 cmp r0, #0 */
/* @0x2b5204 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5208 ldm r8, {r3, r9} */
/* @0x2b520c b 0x2b4f34 <jinit_input_controller+0x1054> */
/* @0x2b5210 cmp r3, #254 */
/* @0x2b5214 bne 0x2b51a8 <jinit_input_controller+0x12c8> */
/* @0x2b5218 ldr r3, [r11, #0x194] */
/* @0x2b521c mov r0, r11 */
/* @0x2b5220 ldr r3, [r3, #0x18] */
/* @0x2b5224 blx r3 */
/* @0x2b5228 cmp r0, #0 */
/* @0x2b522c bne 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5230 b 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5234 ldr r2, [r11, #0x194] */
/* @0x2b5238 mov r0, r11 */
/* @0x2b523c add r3, r2, r3, lsl #2 */
/* @0x2b5240 ldr r3, [r3, #-0x364] */
/* @0x2b5244 blx r3 */
/* @0x2b5248 cmp r0, #0 */
/* @0x2b524c bne 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5250 b 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5254 ldr r2, [r11] */
/* @0x2b5258 mov r1, #60 */
/* @0x2b525c mov r0, r11 */
/* @0x2b5260 str r3, [r2, #0x18] */
/* @0x2b5264 ldr r3, [r11] */
/* @0x2b5268 str r1, [r2, #0x14] */
/* @0x2b526c ldr r3, [r3] */
/* @0x2b5270 blx r3 */
/* @0x2b5274 b 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5278 mov r0, r11 */
/* @0x2b527c mov r1, #0 */
/* @0x2b5280 mov r2, #1 */
/* @0x2b5284 bl 0x2b3f58 <jinit_input_controller+0x78> */
/* @0x2b5288 cmp r0, #0 */
/* @0x2b528c bne 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5290 b 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5294 mov r0, r11 */
/* @0x2b5298 bl 0x2b4878 <jinit_input_controller+0x998> */
/* @0x2b529c cmp r0, #0 */
/* @0x2b52a0 bne 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b52a4 b 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b52a8 ldr r6, [r11, #0x18] */
/* @0x2b52ac ldm r6, {r2, r3} */
/* @0x2b52b0 cmp r3, #0 */
/* @0x2b52b4 beq 0x2b5690 <jinit_input_controller+0x17b0> */
/* @0x2b52b8 ldrb r7, [r2] */
/* @0x2b52bc subs r3, r3, #1 */
/* @0x2b52c0 addne r2, r2, #1 */
/* @0x2b52c4 lsl r7, r7, #8 */
/* @0x2b52c8 beq 0x2b5728 <jinit_input_controller+0x1848> */
/* @0x2b52cc ldrb r1, [r2] */
/* @0x2b52d0 sub r4, r3, #1 */
/* @0x2b52d4 add r5, r2, #1 */
/* @0x2b52d8 add r7, r7, r1 */
/* @0x2b52dc sub r7, r7, #2 */
/* @0x2b52e0 str r7, [sp, #0x4] */
/* @0x2b52e4 cmp r7, #0 */
/* @0x2b52e8 ble 0x2b54e4 <jinit_input_controller+0x1604> */
/* @0x2b52ec cmp r4, #0 */
/* @0x2b52f0 bne 0x2b5310 <jinit_input_controller+0x1430> */
/* @0x2b52f4 ldr r3, [r6, #0xc] */
/* @0x2b52f8 mov r0, r11 */
/* @0x2b52fc blx r3 */
/* @0x2b5300 cmp r0, #0 */
/* @0x2b5304 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5308 ldr r5, [r6] */
/* @0x2b530c ldr r4, [r6, #0x4] */
/* @0x2b5310 ldr r3, [r11] */
/* @0x2b5314 mov r12, #81 */
/* @0x2b5318 ldrb r8, [r5] */
/* @0x2b531c mov r1, #1 */
/* @0x2b5320 mov r0, r11 */
/* @0x2b5324 add r5, r5, r1 */
/* @0x2b5328 and r7, r8, #15 */
/* @0x2b532c str r7, [r3, #0x18] */
/* @0x2b5330 ldr r2, [r11] */
/* @0x2b5334 asr r8, r8, #4 */
/* @0x2b5338 str r12, [r3, #0x14] */
/* @0x2b533c sub r4, r4, #1 */
/* @0x2b5340 str r8, [r2, #0x1c] */
/* @0x2b5344 ldr r3, [r11] */
/* @0x2b5348 ldr r3, [r3, #0x4] */
/* @0x2b534c blx r3 */
/* @0x2b5350 cmp r7, #3 */
/* @0x2b5354 bgt 0x2b5620 <jinit_input_controller+0x1740> */
/* @0x2b5358 add r7, r11, r7, lsl #2 */
/* @0x2b535c ldr r10, [r7, #0x90] */
/* @0x2b5360 cmp r10, #0 */
/* @0x2b5364 beq 0x2b5760 <jinit_input_controller+0x1880> */
/* @0x2b5368 ldr r1, [pc, #0x43c] */
/* @0x2b536c ldr r1, [pc, r1] */
/* @0x2b5370 sub r7, r1, #4 */
/* @0x2b5374 add r9, r1, #252 */
/* @0x2b5378 b 0x2b53bc <jinit_input_controller+0x14dc> */
/* @0x2b537c cmp r4, #0 */
/* @0x2b5380 beq 0x2b53dc <jinit_input_controller+0x14fc> */
/* @0x2b5384 ldrb r2, [r5] */
/* @0x2b5388 subs r4, r4, #1 */
/* @0x2b538c addne r5, r5, #1 */
/* @0x2b5390 lsl r2, r2, #8 */
/* @0x2b5394 beq 0x2b541c <jinit_input_controller+0x153c> */
/* @0x2b5398 ldrb r3, [r5] */
/* @0x2b539c sub r4, r4, #1 */
/* @0x2b53a0 add r5, r5, #1 */
/* @0x2b53a4 add r2, r3, r2 */
/* @0x2b53a8 ldr r3, [r7, #0x4]! */
/* @0x2b53ac cmp r7, r9 */
/* @0x2b53b0 lsl r3, r3, #1 */
/* @0x2b53b4 strh r2, [r10, r3] */
/* @0x2b53b8 beq 0x2b5444 <jinit_input_controller+0x1564> */
/* @0x2b53bc cmp r8, #0 */
/* @0x2b53c0 bne 0x2b537c <jinit_input_controller+0x149c> */
/* @0x2b53c4 cmp r4, #0 */
/* @0x2b53c8 beq 0x2b53fc <jinit_input_controller+0x151c> */
/* @0x2b53cc ldrb r2, [r5] */
/* @0x2b53d0 sub r4, r4, #1 */
/* @0x2b53d4 add r5, r5, #1 */
/* @0x2b53d8 b 0x2b53a8 <jinit_input_controller+0x14c8> */
/* @0x2b53dc ldr r3, [r6, #0xc] */
/* @0x2b53e0 mov r0, r11 */
/* @0x2b53e4 blx r3 */
/* @0x2b53e8 cmp r0, #0 */
/* @0x2b53ec beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b53f0 ldr r5, [r6] */
/* @0x2b53f4 ldr r4, [r6, #0x4] */
/* @0x2b53f8 b 0x2b5384 <jinit_input_controller+0x14a4> */
/* @0x2b53fc ldr r3, [r6, #0xc] */
/* @0x2b5400 mov r0, r11 */
/* @0x2b5404 blx r3 */
/* @0x2b5408 cmp r0, #0 */
/* @0x2b540c beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5410 ldr r5, [r6] */
/* @0x2b5414 ldr r4, [r6, #0x4] */
/* @0x2b5418 b 0x2b53cc <jinit_input_controller+0x14ec> */
/* @0x2b541c ldr r3, [r6, #0xc] */
/* @0x2b5420 mov r0, r11 */
/* @0x2b5424 str r2, [sp] */
/* @0x2b5428 blx r3 */
/* @0x2b542c ldr r2, [sp] */
/* @0x2b5430 cmp r0, #0 */
/* @0x2b5434 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5438 ldr r5, [r6] */
/* @0x2b543c ldr r4, [r6, #0x4] */
/* @0x2b5440 b 0x2b5398 <jinit_input_controller+0x14b8> */
/* @0x2b5444 ldr r3, [r11] */
/* @0x2b5448 ldr r2, [r3, #0x68] */
/* @0x2b544c cmp r2, #1 */
/* @0x2b5450 movgt r7, #8 */
/* @0x2b5454 bgt 0x2b5460 <jinit_input_controller+0x1580> */
/* @0x2b5458 b 0x2b54c4 <jinit_input_controller+0x15e4> */
/* @0x2b545c ldr r3, [r11] */
/* @0x2b5460 ldrh r12, [r10] */
/* @0x2b5464 mov lr, #93 */
/* @0x2b5468 mov r0, r11 */
/* @0x2b546c ldr r2, [r3, #0x4] */
/* @0x2b5470 mov r1, #2 */
/* @0x2b5474 add r10, r10, #16 */
/* @0x2b5478 str r12, [r3, #0x18] */
/* @0x2b547c ldrh r12, [r10, #-14] */
/* @0x2b5480 str r12, [r3, #0x1c] */
/* @0x2b5484 ldrh r12, [r10, #-12] */
/* @0x2b5488 str r12, [r3, #0x20] */
/* @0x2b548c ldrh r12, [r10, #-10] */
/* @0x2b5490 str r12, [r3, #0x24] */
/* @0x2b5494 ldrh r12, [r10, #-8] */
/* @0x2b5498 str r12, [r3, #0x28] */
/* @0x2b549c ldrh r12, [r10, #-6] */
/* @0x2b54a0 str r12, [r3, #0x2c] */
/* @0x2b54a4 ldrh r12, [r10, #-4] */
/* @0x2b54a8 str r12, [r3, #0x30] */
/* @0x2b54ac ldrh r12, [r10, #-2] */
/* @0x2b54b0 str lr, [r3, #0x14] */
/* @0x2b54b4 str r12, [r3, #0x34] */
/* @0x2b54b8 blx r2 */
/* @0x2b54bc subs r7, r7, #1 */
/* @0x2b54c0 bne 0x2b545c <jinit_input_controller+0x157c> */
/* @0x2b54c4 cmp r8, #0 */
/* @0x2b54c8 beq 0x2b5610 <jinit_input_controller+0x1730> */
/* @0x2b54cc ldr r3, [sp, #0x4] */
/* @0x2b54d0 sub r3, r3, #129 */
/* @0x2b54d4 str r3, [sp, #0x4] */
/* @0x2b54d8 ldr r12, [sp, #0x4] */
/* @0x2b54dc cmp r12, #0 */
/* @0x2b54e0 bgt 0x2b52ec <jinit_input_controller+0x140c> */
/* @0x2b54e4 ldr r2, [sp, #0x4] */
/* @0x2b54e8 cmp r2, #0 */
/* @0x2b54ec beq 0x2b5508 <jinit_input_controller+0x1628> */
/* @0x2b54f0 ldr r3, [r11] */
/* @0x2b54f4 mov r12, #11 */
/* @0x2b54f8 mov r0, r11 */
/* @0x2b54fc str r12, [r3, #0x14] */
/* @0x2b5500 ldr r3, [r3] */
/* @0x2b5504 blx r3 */
/* @0x2b5508 str r5, [r6] */
/* @0x2b550c str r4, [r6, #0x4] */
/* @0x2b5510 b 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5514 ldr r3, [r11] */
/* @0x2b5518 mov r2, #102 */
/* @0x2b551c mov r0, r11 */
/* @0x2b5520 mov r1, #1 */
/* @0x2b5524 str r2, [r3, #0x14] */
/* @0x2b5528 ldr r3, [r3, #0x4] */
/* @0x2b552c blx r3 */
/* @0x2b5530 ldr r4, [r11, #0x194] */
/* @0x2b5534 ldrb r3, [r4, #0xc] */
/* @0x2b5538 cmp r3, #0 */
/* @0x2b553c bne 0x2b56c8 <jinit_input_controller+0x17e8> */
/* @0x2b5540 mov r2, #0 */
/* @0x2b5544 mov r3, r11 */
/* @0x2b5548 mov lr, r2 */
/* @0x2b554c mov r12, #5 */
/* @0x2b5550 add r2, r2, #1 */
/* @0x2b5554 mov r1, #1 */
/* @0x2b5558 cmp r2, #16 */
/* @0x2b555c strb r1, [r3, #0xda] */
/* @0x2b5560 strb lr, [r3, #0xca] */
/* @0x2b5564 mov r1, #0 */
/* @0x2b5568 strb r12, [r3, #0xea] */
/* @0x2b556c mov r0, #1 */
/* @0x2b5570 add r3, r3, #1 */
/* @0x2b5574 bne 0x2b5550 <jinit_input_controller+0x1670> */
/* @0x2b5578 mov r2, #260 */
/* @0x2b557c movw r3, #0x106 */
/* @0x2b5580 str r1, [r11, #0xfc] */
/* @0x2b5584 str r1, [r11, #0x28] */
/* @0x2b5588 strb r1, [r11, #0x10a] */
/* @0x2b558c strb r1, [r11, #0x100] */
/* @0x2b5590 strb r0, [r11, #0x101] */
/* @0x2b5594 strb r0, [r11, #0x102] */
/* @0x2b5598 strb r1, [r11, #0x103] */
/* @0x2b559c strb r1, [r11, #0x108] */
/* @0x2b55a0 strb r1, [r11, #0x109] */
/* @0x2b55a4 strh r0, [r11, r2] */
/* @0x2b55a8 strh r0, [r11, r3] */
/* @0x2b55ac strb r0, [r4, #0xc] */
/* @0x2b55b0 b 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b55b4 ldr r3, [r11] */
/* @0x2b55b8 mov r2, #85 */
/* @0x2b55bc mov r0, r11 */
/* @0x2b55c0 mov r1, #1 */
/* @0x2b55c4 str r2, [r3, #0x14] */
/* @0x2b55c8 ldr r3, [r3, #0x4] */
/* @0x2b55cc blx r3 */
/* @0x2b55d0 mov r3, #0 */
/* @0x2b55d4 mov r0, #2 */
/* @0x2b55d8 str r3, [r11, #0x17c] */
/* @0x2b55dc add sp, sp, #12 */
/* @0x2b55e0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b55e4 ldr r3, [r11] */
/* @0x2b55e8 mov r1, #53 */
/* @0x2b55ec mov r0, r11 */
/* @0x2b55f0 str r9, [r3, #0x18] */
/* @0x2b55f4 ldr r2, [r11] */
/* @0x2b55f8 str r1, [r3, #0x14] */
/* @0x2b55fc str r5, [r2, #0x1c] */
/* @0x2b5600 ldr r3, [r11] */
/* @0x2b5604 ldr r3, [r3] */
/* @0x2b5608 blx r3 */
/* @0x2b560c b 0x2b4cb0 <jinit_input_controller+0xdd0> */
/* @0x2b5610 ldr r2, [sp, #0x4] */
/* @0x2b5614 sub r2, r2, #65 */
/* @0x2b5618 str r2, [sp, #0x4] */
/* @0x2b561c b 0x2b54d8 <jinit_input_controller+0x15f8> */
/* @0x2b5620 ldr r3, [r11] */
/* @0x2b5624 mov lr, #31 */
/* @0x2b5628 mov r0, r11 */
/* @0x2b562c str r7, [r3, #0x18] */
/* @0x2b5630 ldr r2, [r11] */
/* @0x2b5634 str lr, [r3, #0x14] */
/* @0x2b5638 ldr r3, [r2] */
/* @0x2b563c blx r3 */
/* @0x2b5640 b 0x2b5358 <jinit_input_controller+0x1478> */
/* @0x2b5644 sub r3, r10, #1 */
/* @0x2b5648 cmp r3, #3 */
/* @0x2b564c bls 0x2b4f00 <jinit_input_controller+0x1020> */
/* @0x2b5650 b 0x2b4ee8 <jinit_input_controller+0x1008> */
/* @0x2b5654 ldr r3, [r8, #0xc] */
/* @0x2b5658 mov r0, r11 */
/* @0x2b565c blx r3 */
/* @0x2b5660 cmp r0, #0 */
/* @0x2b5664 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5668 ldr r5, [r8] */
/* @0x2b566c ldr r4, [r8, #0x4] */
/* @0x2b5670 b 0x2b4e6c <jinit_input_controller+0xf8c> */
/* @0x2b5674 ldr r3, [r11] */
/* @0x2b5678 mov r2, #62 */
/* @0x2b567c mov r0, r11 */
/* @0x2b5680 str r2, [r3, #0x14] */
/* @0x2b5684 ldr r3, [r3] */
/* @0x2b5688 blx r3 */
/* @0x2b568c b 0x2b4e64 <jinit_input_controller+0xf84> */
/* @0x2b5690 ldr r3, [r6, #0xc] */
/* @0x2b5694 mov r0, r11 */
/* @0x2b5698 blx r3 */
/* @0x2b569c cmp r0, #0 */
/* @0x2b56a0 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b56a4 ldm r6, {r2, r3} */
/* @0x2b56a8 b 0x2b52b8 <jinit_input_controller+0x13d8> */
/* @0x2b56ac ldr r3, [r4, #0xc] */
/* @0x2b56b0 mov r0, r11 */
/* @0x2b56b4 blx r3 */
/* @0x2b56b8 cmp r0, #0 */
/* @0x2b56bc beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b56c0 ldm r4, {r2, r3} */
/* @0x2b56c4 b 0x2b4d04 <jinit_input_controller+0xe24> */
/* @0x2b56c8 ldr r3, [r11] */
/* @0x2b56cc mov r2, #61 */
/* @0x2b56d0 mov r0, r11 */
/* @0x2b56d4 str r2, [r3, #0x14] */
/* @0x2b56d8 ldr r3, [r3] */
/* @0x2b56dc blx r3 */
/* @0x2b56e0 ldr r4, [r11, #0x194] */
/* @0x2b56e4 b 0x2b5540 <jinit_input_controller+0x1660> */
/* @0x2b56e8 ldr r3, [r8, #0xc] */
/* @0x2b56ec mov r0, r11 */
/* @0x2b56f0 blx r3 */
/* @0x2b56f4 cmp r0, #0 */
/* @0x2b56f8 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b56fc ldr r5, [r8] */
/* @0x2b5700 ldr r4, [r8, #0x4] */
/* @0x2b5704 b 0x2b4e80 <jinit_input_controller+0xfa0> */
/* @0x2b5708 ldr r3, [r4, #0xc] */
/* @0x2b570c mov r0, r11 */
/* @0x2b5710 blx r3 */
/* @0x2b5714 cmp r0, #0 */
/* @0x2b5718 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b571c ldr r5, [r4] */
/* @0x2b5720 ldr r3, [r4, #0x4] */
/* @0x2b5724 b 0x2b4d18 <jinit_input_controller+0xe38> */
/* @0x2b5728 ldr r3, [r6, #0xc] */
/* @0x2b572c mov r0, r11 */
/* @0x2b5730 blx r3 */
/* @0x2b5734 cmp r0, #0 */
/* @0x2b5738 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b573c ldm r6, {r2, r3} */
/* @0x2b5740 b 0x2b52cc <jinit_input_controller+0x13ec> */
/* @0x2b5744 ldr r3, [r4, #0xc] */
/* @0x2b5748 mov r0, r11 */
/* @0x2b574c blx r3 */
/* @0x2b5750 cmp r0, #0 */
/* @0x2b5754 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5758 ldm r4, {r5, r7} */
/* @0x2b575c b 0x2b4d50 <jinit_input_controller+0xe70> */
/* @0x2b5760 mov r0, r11 */
/* @0x2b5764 bl 0x2bc8e4 <jpeg_alloc_quant_table> */
/* @0x2b5768 mov r10, r0 */
/* @0x2b576c str r0, [r7, #0x90] */
/* @0x2b5770 b 0x2b5368 <jinit_input_controller+0x1488> */
/* @0x2b5774 ldr r3, [r8, #0xc] */
/* @0x2b5778 mov r0, r11 */
/* @0x2b577c blx r3 */
/* @0x2b5780 cmp r0, #0 */
/* @0x2b5784 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5788 ldm r8, {r5, r9} */
/* @0x2b578c b 0x2b5008 <jinit_input_controller+0x1128> */
/* @0x2b5790 ldr r3, [r8, #0xc] */
/* @0x2b5794 mov r0, r11 */
/* @0x2b5798 blx r3 */
/* @0x2b579c cmp r0, #0 */
/* @0x2b57a0 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b57a4 ldm r8, {r5, r12} */
/* @0x2b57a8 b 0x2b501c <jinit_input_controller+0x113c> */
/* @0x2b57ac andseq r12, r3, r12, lsr r7 */
/* @0x2b57b0 cmp r2, #11 */
/* @0x2b57b4 mov r12, r1 */
/* @0x2b57b8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2b57bc mov r4, r0 */
/* @0x2b57c0 bls 0x2b57d0 <jinit_input_controller+0x18f0> */
/* @0x2b57c4 ldrb r1, [r1] */
/* @0x2b57c8 cmp r1, #65 */
/* @0x2b57cc beq 0x2b57fc <jinit_input_controller+0x191c> */
/* @0x2b57d0 ldr r12, [r4] */
/* @0x2b57d4 add r2, r2, r3 */
/* @0x2b57d8 mov lr, #78 */
/* @0x2b57dc mov r0, r4 */
/* @0x2b57e0 mov r1, #1 */
/* @0x2b57e4 str r2, [r12, #0x18] */
/* @0x2b57e8 ldr r3, [r4] */
/* @0x2b57ec str lr, [r12, #0x14] */
/* @0x2b57f0 ldr r3, [r3, #0x4] */
/* @0x2b57f4 blx r3 */
/* @0x2b57f8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2b57fc ldrb r1, [r12, #0x1] */
/* @0x2b5800 cmp r1, #100 */
/* @0x2b5804 bne 0x2b57d0 <jinit_input_controller+0x18f0> */
/* @0x2b5808 ldrb r1, [r12, #0x2] */
/* @0x2b580c cmp r1, #111 */
/* @0x2b5810 bne 0x2b57d0 <jinit_input_controller+0x18f0> */
/* @0x2b5814 ldrb r1, [r12, #0x3] */
/* @0x2b5818 cmp r1, #98 */
/* @0x2b581c bne 0x2b57d0 <jinit_input_controller+0x18f0> */
/* @0x2b5820 ldrb r1, [r12, #0x4] */
/* @0x2b5824 cmp r1, #101 */
/* @0x2b5828 bne 0x2b57d0 <jinit_input_controller+0x18f0> */
/* @0x2b582c ldrb r9, [r12, #0x7] */
/* @0x2b5830 mov r2, #76 */
/* @0x2b5834 ldrb r8, [r12, #0x9] */
/* @0x2b5838 mov r1, #1 */
/* @0x2b583c ldrb r6, [r12, #0x5] */
/* @0x2b5840 ldrb r5, [r12, #0xb] */
/* @0x2b5844 ldr r3, [r0] */
/* @0x2b5848 ldrb r7, [r12, #0x8] */
/* @0x2b584c ldrb lr, [r12, #0xa] */
/* @0x2b5850 ldrb r12, [r12, #0x6] */
/* @0x2b5854 add r7, r7, r9, lsl #8 */
/* @0x2b5858 add lr, lr, r8, lsl #8 */
/* @0x2b585c str r7, [r3, #0x1c] */
/* @0x2b5860 add r12, r12, r6, lsl #8 */
/* @0x2b5864 str lr, [r3, #0x20] */
/* @0x2b5868 str r12, [r3, #0x18] */
/* @0x2b586c str r5, [r3, #0x24] */
/* @0x2b5870 str r2, [r3, #0x14] */
/* @0x2b5874 ldr r3, [r3, #0x4] */
/* @0x2b5878 blx r3 */
/* @0x2b587c mov r3, #1 */
/* @0x2b5880 strb r5, [r4, #0x109] */
/* @0x2b5884 strb r3, [r4, #0x108] */
/* @0x2b5888 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2b588c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b5890 sub sp, sp, #28 */
/* @0x2b5894 ldr r9, [r0, #0x18] */
/* @0x2b5898 mov r6, r0 */
/* @0x2b589c ldr r7, [pc, #0x1b4] */
/* @0x2b58a0 ldr r7, [pc, r7] */
/* @0x2b58a4 ldr r5, [r9, #0x4] */
/* @0x2b58a8 ldr r12, [r9] */
/* @0x2b58ac ldr r3, [r7] */
/* @0x2b58b0 cmp r5, #0 */
/* @0x2b58b4 str r3, [sp, #0x14] */
/* @0x2b58b8 beq 0x2b59ec <jinit_input_controller+0x1b0c> */
/* @0x2b58bc ldrb r8, [r12] */
/* @0x2b58c0 subs r5, r5, #1 */
/* @0x2b58c4 addne r12, r12, #1 */
/* @0x2b58c8 lsl r8, r8, #8 */
/* @0x2b58cc beq 0x2b5a04 <jinit_input_controller+0x1b24> */
/* @0x2b58d0 ldrb r3, [r12] */
/* @0x2b58d4 sub r5, r5, #1 */
/* @0x2b58d8 add r12, r12, #1 */
/* @0x2b58dc add r8, r3, r8 */
/* @0x2b58e0 sub r8, r8, #2 */
/* @0x2b58e4 cmp r8, #13 */
/* @0x2b58e8 ble 0x2b5944 <jinit_input_controller+0x1a64> */
/* @0x2b58ec mov r10, #14 */
/* @0x2b58f0 mov r4, #0 */
/* @0x2b58f4 b 0x2b591c <jinit_input_controller+0x1a3c> */
/* @0x2b58f8 ldrb r1, [r12] */
/* @0x2b58fc add r3, sp, #4 */
/* @0x2b5900 sub r5, r5, #1 */
/* @0x2b5904 add r11, r12, #1 */
/* @0x2b5908 strb r1, [r4, r3] */
/* @0x2b590c add r4, r4, #1 */
/* @0x2b5910 cmp r4, r10 */
/* @0x2b5914 bhs 0x2b597c <jinit_input_controller+0x1a9c> */
/* @0x2b5918 mov r12, r11 */
/* @0x2b591c cmp r5, #0 */
/* @0x2b5920 bne 0x2b58f8 <jinit_input_controller+0x1a18> */
/* @0x2b5924 ldr r3, [r9, #0xc] */
/* @0x2b5928 mov r0, r6 */
/* @0x2b592c blx r3 */
/* @0x2b5930 cmp r0, #0 */
/* @0x2b5934 beq 0x2b59fc <jinit_input_controller+0x1b1c> */
/* @0x2b5938 ldr r12, [r9] */
/* @0x2b593c ldr r5, [r9, #0x4] */
/* @0x2b5940 b 0x2b58f8 <jinit_input_controller+0x1a18> */
/* @0x2b5944 cmp r8, #0 */
/* @0x2b5948 movgt r10, r8 */
/* @0x2b594c bgt 0x2b58f0 <jinit_input_controller+0x1a10> */
/* @0x2b5950 ldr r3, [r6, #0x17c] */
/* @0x2b5954 mov r11, r12 */
/* @0x2b5958 mov r10, #0 */
/* @0x2b595c cmp r3, #224 */
/* @0x2b5960 bne 0x2b598c <jinit_input_controller+0x1aac> */
/* @0x2b5964 mov r2, r10 */
/* @0x2b5968 mov r0, r6 */
/* @0x2b596c add r1, sp, #4 */
/* @0x2b5970 mov r3, r8 */
/* @0x2b5974 bl 0x2b4374 <jinit_input_controller+0x494> */
/* @0x2b5978 b 0x2b59a8 <jinit_input_controller+0x1ac8> */
/* @0x2b597c ldr r3, [r6, #0x17c] */
/* @0x2b5980 rsb r8, r10, r8 */
/* @0x2b5984 cmp r3, #224 */
/* @0x2b5988 beq 0x2b5964 <jinit_input_controller+0x1a84> */
/* @0x2b598c cmp r3, #238 */
/* @0x2b5990 bne 0x2b5a24 <jinit_input_controller+0x1b44> */
/* @0x2b5994 mov r2, r10 */
/* @0x2b5998 mov r0, r6 */
/* @0x2b599c add r1, sp, #4 */
/* @0x2b59a0 mov r3, r8 */
/* @0x2b59a4 bl 0x2b57b0 <jinit_input_controller+0x18d0> */
/* @0x2b59a8 cmp r8, #0 */
/* @0x2b59ac str r11, [r9] */
/* @0x2b59b0 str r5, [r9, #0x4] */
/* @0x2b59b4 movle r0, #1 */
/* @0x2b59b8 ble 0x2b59d4 <jinit_input_controller+0x1af4> */
/* @0x2b59bc ldr r3, [r6, #0x18] */
/* @0x2b59c0 mov r0, r6 */
/* @0x2b59c4 mov r1, r8 */
/* @0x2b59c8 ldr r3, [r3, #0x10] */
/* @0x2b59cc blx r3 */
/* @0x2b59d0 mov r0, #1 */
/* @0x2b59d4 ldr r2, [sp, #0x14] */
/* @0x2b59d8 ldr r3, [r7] */
/* @0x2b59dc cmp r2, r3 */
/* @0x2b59e0 bne 0x2b5a54 <jinit_input_controller+0x1b74> */
/* @0x2b59e4 add sp, sp, #28 */
/* @0x2b59e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b59ec ldr r3, [r9, #0xc] */
/* @0x2b59f0 blx r3 */
/* @0x2b59f4 cmp r0, #0 */
/* @0x2b59f8 bne 0x2b5a48 <jinit_input_controller+0x1b68> */
/* @0x2b59fc mov r0, #0 */
/* @0x2b5a00 b 0x2b59d4 <jinit_input_controller+0x1af4> */
/* @0x2b5a04 ldr r3, [r9, #0xc] */
/* @0x2b5a08 mov r0, r6 */
/* @0x2b5a0c blx r3 */
/* @0x2b5a10 cmp r0, #0 */
/* @0x2b5a14 beq 0x2b59fc <jinit_input_controller+0x1b1c> */
/* @0x2b5a18 ldr r12, [r9] */
/* @0x2b5a1c ldr r5, [r9, #0x4] */
/* @0x2b5a20 b 0x2b58d0 <jinit_input_controller+0x19f0> */
/* @0x2b5a24 ldr r2, [r6] */
/* @0x2b5a28 mov r1, #68 */
/* @0x2b5a2c mov r0, r6 */
/* @0x2b5a30 str r3, [r2, #0x18] */
/* @0x2b5a34 ldr r3, [r6] */
/* @0x2b5a38 str r1, [r2, #0x14] */
/* @0x2b5a3c ldr r3, [r3] */
/* @0x2b5a40 blx r3 */
/* @0x2b5a44 b 0x2b59a8 <jinit_input_controller+0x1ac8> */
/* @0x2b5a48 ldr r12, [r9] */
/* @0x2b5a4c ldr r5, [r9, #0x4] */
/* @0x2b5a50 b 0x2b58bc <jinit_input_controller+0x19dc> */
/* @0x2b5a54 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b5a58 ldrheq r8, [r3], -r0 */
/* @0x2b5a5c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b5a60 sub sp, sp, #12 */
/* @0x2b5a64 ldr r10, [r0, #0x194] */
/* @0x2b5a68 mov r11, r0 */
/* @0x2b5a6c ldr r9, [r0, #0x18] */
/* @0x2b5a70 ldr r1, [r10, #0xa0] */
/* @0x2b5a74 ldr r6, [r9] */
/* @0x2b5a78 cmp r1, #0 */
/* @0x2b5a7c ldr r4, [r9, #0x4] */
/* @0x2b5a80 str r1, [sp, #0x4] */
/* @0x2b5a84 beq 0x2b5c14 <jinit_input_controller+0x1d34> */
/* @0x2b5a88 ldr r2, [sp, #0x4] */
/* @0x2b5a8c ldr r5, [r10, #0xa4] */
/* @0x2b5a90 ldr r7, [r2, #0x10] */
/* @0x2b5a94 ldr r8, [r2, #0xc] */
/* @0x2b5a98 add r7, r7, r5 */
/* @0x2b5a9c cmp r8, r5 */
/* @0x2b5aa0 bls 0x2b5af8 <jinit_input_controller+0x1c18> */
/* @0x2b5aa4 cmp r4, #0 */
/* @0x2b5aa8 str r6, [r9] */
/* @0x2b5aac str r4, [r9, #0x4] */
/* @0x2b5ab0 str r5, [r10, #0xa4] */
/* @0x2b5ab4 beq 0x2b5bb0 <jinit_input_controller+0x1cd0> */
/* @0x2b5ab8 cmp r4, #0 */
/* @0x2b5abc cmpne r8, r5 */
/* @0x2b5ac0 bls 0x2b5af0 <jinit_input_controller+0x1c10> */
/* @0x2b5ac4 subs r4, r4, #1 */
/* @0x2b5ac8 add r5, r5, #1 */
/* @0x2b5acc ldrb r3, [r6], #1 */
/* @0x2b5ad0 moveq r2, #0 */
/* @0x2b5ad4 movne r2, #1 */
/* @0x2b5ad8 cmp r5, r8 */
/* @0x2b5adc movhs r2, #0 */
/* @0x2b5ae0 andlo r2, r2, #1 */
/* @0x2b5ae4 cmp r2, #0 */
/* @0x2b5ae8 strb r3, [r7], #1 */
/* @0x2b5aec bne 0x2b5ac4 <jinit_input_controller+0x1be4> */
/* @0x2b5af0 cmp r5, r8 */
/* @0x2b5af4 blo 0x2b5aa4 <jinit_input_controller+0x1bc4> */
/* @0x2b5af8 ldr r2, [r11, #0x10c] */
/* @0x2b5afc cmp r2, #0 */
/* @0x2b5b00 bne 0x2b5b0c <jinit_input_controller+0x1c2c> */
/* @0x2b5b04 b 0x2b5cb0 <jinit_input_controller+0x1dd0> */
/* @0x2b5b08 mov r2, r3 */
/* @0x2b5b0c ldr r3, [r2] */
/* @0x2b5b10 cmp r3, #0 */
/* @0x2b5b14 bne 0x2b5b08 <jinit_input_controller+0x1c28> */
/* @0x2b5b18 ldr r1, [sp, #0x4] */
/* @0x2b5b1c str r1, [r2] */
/* @0x2b5b20 ldr r2, [sp, #0x4] */
/* @0x2b5b24 ldr r5, [r2, #0x8] */
/* @0x2b5b28 ldr r1, [r2, #0x10] */
/* @0x2b5b2c rsb r5, r8, r5 */
/* @0x2b5b30 ldr r3, [r11, #0x17c] */
/* @0x2b5b34 mov r2, #0 */
/* @0x2b5b38 str r2, [r10, #0xa0] */
/* @0x2b5b3c cmp r3, #224 */
/* @0x2b5b40 beq 0x2b5be4 <jinit_input_controller+0x1d04> */
/* @0x2b5b44 cmp r3, #238 */
/* @0x2b5b48 beq 0x2b5bd0 <jinit_input_controller+0x1cf0> */
/* @0x2b5b4c ldr r2, [r11] */
/* @0x2b5b50 add r8, r5, r8 */
/* @0x2b5b54 mov r12, #91 */
/* @0x2b5b58 mov r0, r11 */
/* @0x2b5b5c mov r1, #1 */
/* @0x2b5b60 str r3, [r2, #0x18] */
/* @0x2b5b64 ldr r3, [r11] */
/* @0x2b5b68 str r12, [r2, #0x14] */
/* @0x2b5b6c str r8, [r3, #0x1c] */
/* @0x2b5b70 ldr r3, [r11] */
/* @0x2b5b74 ldr r3, [r3, #0x4] */
/* @0x2b5b78 blx r3 */
/* @0x2b5b7c cmp r5, #0 */
/* @0x2b5b80 str r6, [r9] */
/* @0x2b5b84 str r4, [r9, #0x4] */
/* @0x2b5b88 movle r0, #1 */
/* @0x2b5b8c ble 0x2b5ba8 <jinit_input_controller+0x1cc8> */
/* @0x2b5b90 ldr r3, [r11, #0x18] */
/* @0x2b5b94 mov r0, r11 */
/* @0x2b5b98 mov r1, r5 */
/* @0x2b5b9c ldr r3, [r3, #0x10] */
/* @0x2b5ba0 blx r3 */
/* @0x2b5ba4 mov r0, #1 */
/* @0x2b5ba8 add sp, sp, #12 */
/* @0x2b5bac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b5bb0 ldr r3, [r9, #0xc] */
/* @0x2b5bb4 mov r0, r11 */
/* @0x2b5bb8 blx r3 */
/* @0x2b5bbc cmp r0, #0 */
/* @0x2b5bc0 beq 0x2b5c08 <jinit_input_controller+0x1d28> */
/* @0x2b5bc4 ldr r6, [r9] */
/* @0x2b5bc8 ldr r4, [r9, #0x4] */
/* @0x2b5bcc b 0x2b5ab8 <jinit_input_controller+0x1bd8> */
/* @0x2b5bd0 mov r2, r8 */
/* @0x2b5bd4 mov r0, r11 */
/* @0x2b5bd8 mov r3, r5 */
/* @0x2b5bdc bl 0x2b57b0 <jinit_input_controller+0x18d0> */
/* @0x2b5be0 b 0x2b5b7c <jinit_input_controller+0x1c9c> */
/* @0x2b5be4 mov r2, r8 */
/* @0x2b5be8 mov r0, r11 */
/* @0x2b5bec mov r3, r5 */
/* @0x2b5bf0 bl 0x2b4374 <jinit_input_controller+0x494> */
/* @0x2b5bf4 b 0x2b5b7c <jinit_input_controller+0x1c9c> */
/* @0x2b5bf8 ldr r3, [r9, #0xc] */
/* @0x2b5bfc blx r3 */
/* @0x2b5c00 cmp r0, #0 */
/* @0x2b5c04 bne 0x2b5ce8 <jinit_input_controller+0x1e08> */
/* @0x2b5c08 mov r0, #0 */
/* @0x2b5c0c add sp, sp, #12 */
/* @0x2b5c10 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b5c14 cmp r4, #0 */
/* @0x2b5c18 beq 0x2b5bf8 <jinit_input_controller+0x1d18> */
/* @0x2b5c1c ldrb r5, [r6] */
/* @0x2b5c20 subs r4, r4, #1 */
/* @0x2b5c24 add r6, r6, #1 */
/* @0x2b5c28 lsl r5, r5, #8 */
/* @0x2b5c2c beq 0x2b5cc8 <jinit_input_controller+0x1de8> */
/* @0x2b5c30 ldrb r3, [r6] */
/* @0x2b5c34 sub r4, r4, #1 */
/* @0x2b5c38 add r6, r6, #1 */
/* @0x2b5c3c add r5, r3, r5 */
/* @0x2b5c40 subs r5, r5, #2 */
/* @0x2b5c44 bmi 0x2b5cbc <jinit_input_controller+0x1ddc> */
/* @0x2b5c48 ldr r3, [r11, #0x17c] */
/* @0x2b5c4c mov r0, r11 */
/* @0x2b5c50 mov r1, #1 */
/* @0x2b5c54 cmp r3, #254 */
/* @0x2b5c58 subne r3, r3, #200 */
/* @0x2b5c5c ldreq r8, [r10, #0x5c] */
/* @0x2b5c60 ldrne r8, [r10, r3, lsl #2] */
/* @0x2b5c64 ldr r3, [r11, #0x4] */
/* @0x2b5c68 cmp r8, r5 */
/* @0x2b5c6c movhs r8, r5 */
/* @0x2b5c70 add r2, r8, #20 */
/* @0x2b5c74 ldr r3, [r3, #0x4] */
/* @0x2b5c78 blx r3 */
/* @0x2b5c7c ldr r2, [r11, #0x17c] */
/* @0x2b5c80 mov r3, #0 */
/* @0x2b5c84 str r5, [r0, #0x8] */
/* @0x2b5c88 add r7, r0, #20 */
/* @0x2b5c8c str r8, [r0, #0xc] */
/* @0x2b5c90 mov r5, r3 */
/* @0x2b5c94 strb r2, [r0, #0x4] */
/* @0x2b5c98 str r7, [r0, #0x10] */
/* @0x2b5c9c str r3, [r0] */
/* @0x2b5ca0 str r0, [sp, #0x4] */
/* @0x2b5ca4 str r0, [r10, #0xa0] */
/* @0x2b5ca8 str r3, [r10, #0xa4] */
/* @0x2b5cac b 0x2b5a9c <jinit_input_controller+0x1bbc> */
/* @0x2b5cb0 ldr r3, [sp, #0x4] */
/* @0x2b5cb4 str r3, [r11, #0x10c] */
/* @0x2b5cb8 b 0x2b5b20 <jinit_input_controller+0x1c40> */
/* @0x2b5cbc mov r8, #0 */
/* @0x2b5cc0 mov r1, r8 */
/* @0x2b5cc4 b 0x2b5b30 <jinit_input_controller+0x1c50> */
/* @0x2b5cc8 ldr r3, [r9, #0xc] */
/* @0x2b5ccc mov r0, r11 */
/* @0x2b5cd0 blx r3 */
/* @0x2b5cd4 cmp r0, #0 */
/* @0x2b5cd8 beq 0x2b5c08 <jinit_input_controller+0x1d28> */
/* @0x2b5cdc ldr r6, [r9] */
/* @0x2b5ce0 ldr r4, [r9, #0x4] */
/* @0x2b5ce4 b 0x2b5c30 <jinit_input_controller+0x1d50> */
/* @0x2b5ce8 ldr r6, [r9] */
/* @0x2b5cec ldr r4, [r9, #0x4] */
/* @0x2b5cf0 b 0x2b5c1c <jinit_input_controller+0x1d3c> */
/* @0x2b5cf4 ldr r3, [r0, #0x17c] */
/* @0x2b5cf8 push {r4, lr} */
/* @0x2b5cfc cmp r3, #0 */
/* @0x2b5d00 mov r4, r0 */
/* @0x2b5d04 beq 0x2b5d54 <jinit_input_controller+0x1e74> */
/* @0x2b5d08 ldr r2, [r4, #0x194] */
/* @0x2b5d0c ldr r2, [r2, #0x10] */
/* @0x2b5d10 add r1, r2, #208 */
/* @0x2b5d14 cmp r1, r3 */
/* @0x2b5d18 beq 0x2b5d68 <jinit_input_controller+0x1e88> */
/* @0x2b5d1c ldr r3, [r4, #0x18] */
/* @0x2b5d20 mov r1, r2 */
/* @0x2b5d24 mov r0, r4 */
/* @0x2b5d28 ldr r3, [r3, #0x14] */
/* @0x2b5d2c blx r3 */
/* @0x2b5d30 cmp r0, #0 */
/* @0x2b5d34 beq 0x2b5d60 <jinit_input_controller+0x1e80> */
/* @0x2b5d38 ldr r3, [r4, #0x194] */
/* @0x2b5d3c mov r0, #1 */
/* @0x2b5d40 ldr r2, [r3, #0x10] */
/* @0x2b5d44 add r2, r2, r0 */
/* @0x2b5d48 and r2, r2, #7 */
/* @0x2b5d4c str r2, [r3, #0x10] */
/* @0x2b5d50 pop {r4, pc} */
/* @0x2b5d54 bl 0x2b46e0 <jinit_input_controller+0x800> */
/* @0x2b5d58 cmp r0, #0 */
/* @0x2b5d5c bne 0x2b5d98 <jinit_input_controller+0x1eb8> */
/* @0x2b5d60 mov r0, #0 */
/* @0x2b5d64 pop {r4, pc} */
/* @0x2b5d68 ldr r3, [r4] */
/* @0x2b5d6c mov r12, #98 */
/* @0x2b5d70 mov r0, r4 */
/* @0x2b5d74 mov r1, #3 */
/* @0x2b5d78 str r2, [r3, #0x18] */
/* @0x2b5d7c ldr r2, [r4] */
/* @0x2b5d80 str r12, [r3, #0x14] */
/* @0x2b5d84 ldr r3, [r2, #0x4] */
/* @0x2b5d88 blx r3 */
/* @0x2b5d8c mov r3, #0 */
/* @0x2b5d90 str r3, [r4, #0x17c] */
/* @0x2b5d94 b 0x2b5d38 <jinit_input_controller+0x1e58> */
/* @0x2b5d98 ldr r3, [r4, #0x17c] */
/* @0x2b5d9c b 0x2b5d08 <jinit_input_controller+0x1e28> */

/* ── FUNC 0x2b5da0 · jpeg_resync_to_restart · size=348 · insn=87 */
/* @0x2b5da0 push {r4, r5, r6, r7, r8, lr} */
/* @0x2b5da4 mov r12, #121 */
/* @0x2b5da8 ldr r3, [r0] */
/* @0x2b5dac mov r6, r1 */
/* @0x2b5db0 ldr r5, [r0, #0x17c] */
/* @0x2b5db4 mvn r1, #0 */
/* @0x2b5db8 mov r4, r0 */
/* @0x2b5dbc add r7, r6, #1 */
/* @0x2b5dc0 add r8, r6, #2 */
/* @0x2b5dc4 and r7, r7, #7 */
/* @0x2b5dc8 str r5, [r3, #0x18] */
/* @0x2b5dcc and r8, r8, #7 */
/* @0x2b5dd0 ldr r2, [r0] */
/* @0x2b5dd4 add r7, r7, #208 */
/* @0x2b5dd8 str r12, [r3, #0x14] */
/* @0x2b5ddc add r8, r8, #208 */
/* @0x2b5de0 str r6, [r2, #0x1c] */
/* @0x2b5de4 ldr r3, [r0] */
/* @0x2b5de8 ldr r3, [r3, #0x4] */
/* @0x2b5dec blx r3 */
/* @0x2b5df0 cmp r5, #191 */
/* @0x2b5df4 sub r3, r5, #208 */
/* @0x2b5df8 ble 0x2b5eb4 <jpeg_resync_to_restart+0x114> */
/* @0x2b5dfc cmp r3, #7 */
/* @0x2b5e00 bhi 0x2b5e7c <jpeg_resync_to_restart+0xdc> */
/* @0x2b5e04 sub r3, r6, #1 */
/* @0x2b5e08 cmp r7, r5 */
/* @0x2b5e0c and r3, r3, #7 */
/* @0x2b5e10 add r3, r3, #208 */
/* @0x2b5e14 beq 0x2b5e7c <jpeg_resync_to_restart+0xdc> */
/* @0x2b5e18 sub r2, r6, #2 */
/* @0x2b5e1c cmp r8, r5 */
/* @0x2b5e20 and r2, r2, #7 */
/* @0x2b5e24 add r2, r2, #208 */
/* @0x2b5e28 beq 0x2b5e7c <jpeg_resync_to_restart+0xdc> */
/* @0x2b5e2c cmp r3, r5 */
/* @0x2b5e30 beq 0x2b5eb4 <jpeg_resync_to_restart+0x114> */
/* @0x2b5e34 cmp r2, r5 */
/* @0x2b5e38 beq 0x2b5eb4 <jpeg_resync_to_restart+0x114> */
/* @0x2b5e3c ldr r3, [r4] */
/* @0x2b5e40 mov r12, #97 */
/* @0x2b5e44 mov r6, #1 */
/* @0x2b5e48 mov r0, r4 */
/* @0x2b5e4c mov r1, #4 */
/* @0x2b5e50 str r5, [r3, #0x18] */
/* @0x2b5e54 ldr r2, [r4] */
/* @0x2b5e58 str r12, [r3, #0x14] */
/* @0x2b5e5c str r6, [r2, #0x1c] */
/* @0x2b5e60 ldr r3, [r4] */
/* @0x2b5e64 ldr r3, [r3, #0x4] */
/* @0x2b5e68 blx r3 */
/* @0x2b5e6c mov r3, #0 */
/* @0x2b5e70 mov r0, r6 */
/* @0x2b5e74 str r3, [r4, #0x17c] */
/* @0x2b5e78 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2b5e7c ldr r3, [r4] */
/* @0x2b5e80 mov lr, #97 */
/* @0x2b5e84 mov r12, #3 */
/* @0x2b5e88 mov r0, r4 */
/* @0x2b5e8c mov r1, #4 */
/* @0x2b5e90 str r5, [r3, #0x18] */
/* @0x2b5e94 ldr r2, [r4] */
/* @0x2b5e98 str lr, [r3, #0x14] */
/* @0x2b5e9c str r12, [r2, #0x1c] */
/* @0x2b5ea0 ldr r3, [r4] */
/* @0x2b5ea4 ldr r3, [r3, #0x4] */
/* @0x2b5ea8 blx r3 */
/* @0x2b5eac mov r0, #1 */
/* @0x2b5eb0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2b5eb4 ldr r3, [r4] */
/* @0x2b5eb8 mov lr, #97 */
/* @0x2b5ebc mov r12, #2 */
/* @0x2b5ec0 mov r0, r4 */
/* @0x2b5ec4 mov r1, #4 */
/* @0x2b5ec8 str r5, [r3, #0x18] */
/* @0x2b5ecc ldr r2, [r4] */
/* @0x2b5ed0 str lr, [r3, #0x14] */
/* @0x2b5ed4 str r12, [r2, #0x1c] */
/* @0x2b5ed8 ldr r3, [r4] */
/* @0x2b5edc ldr r3, [r3, #0x4] */
/* @0x2b5ee0 blx r3 */
/* @0x2b5ee4 mov r0, r4 */
/* @0x2b5ee8 bl 0x2b46e0 <jinit_input_controller+0x800> */
/* @0x2b5eec cmp r0, #0 */
/* @0x2b5ef0 ldrne r5, [r4, #0x17c] */
/* @0x2b5ef4 bne 0x2b5df0 <jpeg_resync_to_restart+0x50> */
/* @0x2b5ef8 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2b5efc · jinit_marker_reader · size=192 · insn=48 */
/* @0x2b5efc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2b5f00 mov r1, #0 */
/* @0x2b5f04 ldr r3, [r0, #0x4] */
/* @0x2b5f08 mov r2, #168 */
/* @0x2b5f0c mov r4, r0 */
/* @0x2b5f10 ldr r6, [pc, #0x90] */
/* @0x2b5f14 mov r5, #0 */
/* @0x2b5f18 ldr r9, [pc, #0x8c] */
/* @0x2b5f1c ldr r3, [r3] */
/* @0x2b5f20 add r6, pc, r6 */
/* @0x2b5f24 blx r3 */
/* @0x2b5f28 ldr r8, [pc, #0x80] */
/* @0x2b5f2c ldr r7, [pc, #0x80] */
/* @0x2b5f30 mov r12, r5 */
/* @0x2b5f34 mov r1, r6 */
/* @0x2b5f38 mov r2, #16 */
/* @0x2b5f3c add r9, pc, r9 */
/* @0x2b5f40 add r8, pc, r8 */
/* @0x2b5f44 add r7, pc, r7 */
/* @0x2b5f48 mov r3, r0 */
/* @0x2b5f4c str r0, [r4, #0x194] */
/* @0x2b5f50 str r9, [r0] */
/* @0x2b5f54 str r8, [r0, #0x4] */
/* @0x2b5f58 str r7, [r0, #0x8] */
/* @0x2b5f5c str r6, [r0, #0x18] */
/* @0x2b5f60 str r5, [r0, #0x5c] */
/* @0x2b5f64 subs r2, r2, #1 */
/* @0x2b5f68 str r1, [r3, #0x1c] */
/* @0x2b5f6c str r12, [r3, #0x60] */
/* @0x2b5f70 add r3, r3, #4 */
/* @0x2b5f74 bne 0x2b5f64 <jinit_marker_reader+0x68> */
/* @0x2b5f78 ldr r3, [pc, #0x38] */
/* @0x2b5f7c add r3, pc, r3 */
/* @0x2b5f80 str r3, [r0, #0x1c] */
/* @0x2b5f84 str r3, [r0, #0x54] */
/* @0x2b5f88 str r2, [r4, #0xc4] */
/* @0x2b5f8c str r2, [r4, #0x7c] */
/* @0x2b5f90 str r2, [r4, #0x17c] */
/* @0x2b5f94 strb r2, [r0, #0xc] */
/* @0x2b5f98 strb r2, [r0, #0xd] */
/* @0x2b5f9c str r2, [r0, #0x14] */
/* @0x2b5fa0 str r2, [r0, #0xa0] */
/* @0x2b5fa4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2b5fa8 .word 0xffffe6dc */
/* @0x2b5fac .word 0xffffe90c */
/* @0x2b5fb0 .word 0xffffed04 */
/* @0x2b5fb4 .word 0xfffffda8 */
/* @0x2b5fb8 .word 0xfffff908 */

/* ── FUNC 0x2b5fbc · jpeg_save_markers · size=232 · insn=58 */
/* @0x2b5fbc ldr r3, [r0, #0x4] */
/* @0x2b5fc0 mov r12, r0 */
/* @0x2b5fc4 push {r4, lr} */
/* @0x2b5fc8 ldr r3, [r3, #0x30] */
/* @0x2b5fcc ldr r0, [r0, #0x194] */
/* @0x2b5fd0 sub r3, r3, #20 */
/* @0x2b5fd4 cmp r3, r2 */
/* @0x2b5fd8 movge r3, r2 */
/* @0x2b5fdc cmp r3, #0 */
/* @0x2b5fe0 beq 0x2b6018 <jpeg_save_markers+0x5c> */
/* @0x2b5fe4 cmp r3, #13 */
/* @0x2b5fe8 cmpls r1, #224 */
/* @0x2b5fec bne 0x2b6078 <jpeg_save_markers+0xbc> */
/* @0x2b5ff0 mov r3, #14 */
/* @0x2b5ff4 sub r2, r1, #224 */
/* @0x2b5ff8 ldr r4, [pc, #0x94] */
/* @0x2b5ffc cmp r2, #15 */
/* @0x2b6000 add r4, pc, r4 */
/* @0x2b6004 bhi 0x2b6048 <jpeg_save_markers+0x8c> */
/* @0x2b6008 add r2, r0, r2, lsl #2 */
/* @0x2b600c str r4, [r2, #0x1c] */
/* @0x2b6010 str r3, [r2, #0x60] */
/* @0x2b6014 pop {r4, pc} */
/* @0x2b6018 ldr r4, [pc, #0x78] */
/* @0x2b601c cmp r1, #224 */
/* @0x2b6020 cmpne r1, #238 */
/* @0x2b6024 add r4, pc, r4 */
/* @0x2b6028 beq 0x2b606c <jpeg_save_markers+0xb0> */
/* @0x2b602c cmp r1, #254 */
/* @0x2b6030 streq r4, [r0, #0x18] */
/* @0x2b6034 streq r3, [r0, #0x5c] */
/* @0x2b6038 popeq {r4, pc} */
/* @0x2b603c sub r2, r1, #224 */
/* @0x2b6040 cmp r2, #15 */
/* @0x2b6044 bls 0x2b6008 <jpeg_save_markers+0x4c> */
/* @0x2b6048 ldr r3, [r12] */
/* @0x2b604c mov lr, #68 */
/* @0x2b6050 mov r0, r12 */
/* @0x2b6054 str r1, [r3, #0x18] */
/* @0x2b6058 ldr r2, [r12] */
/* @0x2b605c str lr, [r3, #0x14] */
/* @0x2b6060 ldr r3, [r2] */
/* @0x2b6064 blx r3 */
/* @0x2b6068 pop {r4, pc} */
/* @0x2b606c ldr r4, [pc, #0x28] */
/* @0x2b6070 add r4, pc, r4 */
/* @0x2b6074 b 0x2b602c <jpeg_save_markers+0x70> */
/* @0x2b6078 ldr r4, [pc, #0x20] */
/* @0x2b607c cmp r3, #11 */
/* @0x2b6080 cmpls r1, #238 */
/* @0x2b6084 add r4, pc, r4 */
/* @0x2b6088 bne 0x2b602c <jpeg_save_markers+0x70> */
/* @0x2b608c mov r3, #12 */
/* @0x2b6090 b 0x2b5ff4 <jpeg_save_markers+0x38> */
/* @0x2b6094 .word 0xfffffa54 */
/* @0x2b6098 .word 0xffffe5d8 */
/* @0x2b609c .word 0xfffff814 */
/* @0x2b60a0 .word 0xfffff9d0 */

/* ── FUNC 0x2b60a4 · jpeg_set_marker_processor · size=72 · insn=18 */
/* @0x2b60a4 ldr r12, [r0, #0x194] */
/* @0x2b60a8 cmp r1, #254 */
/* @0x2b60ac push {r4, lr} */
/* @0x2b60b0 streq r2, [r12, #0x18] */
/* @0x2b60b4 popeq {r4, pc} */
/* @0x2b60b8 sub r4, r1, #224 */
/* @0x2b60bc cmp r4, #15 */
/* @0x2b60c0 addls r1, r12, r1, lsl #2 */
/* @0x2b60c4 strls r2, [r1, #-0x364] */
/* @0x2b60c8 popls {r4, pc} */
/* @0x2b60cc ldr r2, [r0] */
/* @0x2b60d0 mov r12, #68 */
/* @0x2b60d4 str r1, [r2, #0x18] */
/* @0x2b60d8 ldr r3, [r0] */
/* @0x2b60dc str r12, [r2, #0x14] */
/* @0x2b60e0 ldr r3, [r3] */
/* @0x2b60e4 blx r3 */
/* @0x2b60e8 pop {r4, pc} */

/* ── FUNC 0x2b60ec · anon_2b60ec · size=748 · insn=188 */
/* @0x2b60ec push {r3, r4, r5, lr} */
/* @0x2b60f0 mov r4, r0 */
/* @0x2b60f4 ldr r5, [r0, #0x180] */
/* @0x2b60f8 ldrb r3, [r5, #0x8] */
/* @0x2b60fc cmp r3, #0 */
/* @0x2b6100 bne 0x2b6208 <jpeg_set_marker_processor+0x164> */
/* @0x2b6104 ldrb r3, [r0, #0x4a] */
/* @0x2b6108 cmp r3, #0 */
/* @0x2b610c beq 0x2b611c <jpeg_set_marker_processor+0x78> */
/* @0x2b6110 ldr r3, [r0, #0x74] */
/* @0x2b6114 cmp r3, #0 */
/* @0x2b6118 beq 0x2b6248 <jpeg_set_marker_processor+0x1a4> */
/* @0x2b611c ldr r3, [r4, #0x19c] */
/* @0x2b6120 mov r0, r4 */
/* @0x2b6124 ldr r3, [r3] */
/* @0x2b6128 blx r3 */
/* @0x2b612c ldr r3, [r4, #0x188] */
/* @0x2b6130 mov r0, r4 */
/* @0x2b6134 ldr r3, [r3, #0x8] */
/* @0x2b6138 blx r3 */
/* @0x2b613c ldrb r3, [r4, #0x41] */
/* @0x2b6140 cmp r3, #0 */
/* @0x2b6144 bne 0x2b61a4 <jpeg_set_marker_processor+0x100> */
/* @0x2b6148 ldrb r3, [r5, #0x10] */
/* @0x2b614c cmp r3, #0 */
/* @0x2b6150 beq 0x2b628c <jpeg_set_marker_processor+0x1e8> */
/* @0x2b6154 ldr r3, [r4, #0x1a0] */
/* @0x2b6158 mov r0, r4 */
/* @0x2b615c ldr r3, [r3] */
/* @0x2b6160 blx r3 */
/* @0x2b6164 ldrb r3, [r4, #0x4a] */
/* @0x2b6168 cmp r3, #0 */
/* @0x2b616c bne 0x2b6274 <jpeg_set_marker_processor+0x1d0> */
/* @0x2b6170 ldrb r1, [r5, #0x8] */
/* @0x2b6174 mov r0, r4 */
/* @0x2b6178 ldr r3, [r4, #0x18c] */
/* @0x2b617c cmp r1, #0 */
/* @0x2b6180 ldr r3, [r3] */
/* @0x2b6184 movne r1, #3 */
/* @0x2b6188 moveq r1, #0 */
/* @0x2b618c blx r3 */
/* @0x2b6190 ldr r3, [r4, #0x184] */
/* @0x2b6194 mov r0, r4 */
/* @0x2b6198 mov r1, #0 */
/* @0x2b619c ldr r3, [r3] */
/* @0x2b61a0 blx r3 */
/* @0x2b61a4 ldr r3, [r4, #0x8] */
/* @0x2b61a8 cmp r3, #0 */
/* @0x2b61ac popeq {r3, r4, r5, pc} */
/* @0x2b61b0 ldr r2, [r5, #0xc] */
/* @0x2b61b4 str r2, [r3, #0xc] */
/* @0x2b61b8 ldrb r1, [r5, #0x8] */
/* @0x2b61bc cmp r1, #0 */
/* @0x2b61c0 moveq r1, #1 */
/* @0x2b61c4 movne r1, #2 */
/* @0x2b61c8 add r2, r1, r2 */
/* @0x2b61cc str r2, [r3, #0x10] */
/* @0x2b61d0 ldrb r1, [r4, #0x40] */
/* @0x2b61d4 cmp r1, #0 */
/* @0x2b61d8 popeq {r3, r4, r5, pc} */
/* @0x2b61dc ldr r1, [r4, #0x190] */
/* @0x2b61e0 ldrb r1, [r1, #0x11] */
/* @0x2b61e4 cmp r1, #0 */
/* @0x2b61e8 popne {r3, r4, r5, pc} */
/* @0x2b61ec ldrb r1, [r4, #0x5a] */
/* @0x2b61f0 cmp r1, #0 */
/* @0x2b61f4 moveq r1, #1 */
/* @0x2b61f8 movne r1, #2 */
/* @0x2b61fc add r2, r1, r2 */
/* @0x2b6200 str r2, [r3, #0x10] */
/* @0x2b6204 pop {r3, r4, r5, pc} */
/* @0x2b6208 mov r1, #0 */
/* @0x2b620c strb r1, [r5, #0x8] */
/* @0x2b6210 ldr r3, [r0, #0x1a8] */
/* @0x2b6214 ldr r3, [r3] */
/* @0x2b6218 blx r3 */
/* @0x2b621c ldr r3, [r4, #0x18c] */
/* @0x2b6220 mov r0, r4 */
/* @0x2b6224 mov r1, #2 */
/* @0x2b6228 ldr r3, [r3] */
/* @0x2b622c blx r3 */
/* @0x2b6230 ldr r3, [r4, #0x184] */
/* @0x2b6234 mov r0, r4 */
/* @0x2b6238 mov r1, #2 */
/* @0x2b623c ldr r3, [r3] */
/* @0x2b6240 blx r3 */
/* @0x2b6244 b 0x2b61a4 <jpeg_set_marker_processor+0x100> */
/* @0x2b6248 ldrb r3, [r0, #0x50] */
/* @0x2b624c cmp r3, #0 */
/* @0x2b6250 beq 0x2b62a0 <jpeg_set_marker_processor+0x1fc> */
/* @0x2b6254 ldrb r3, [r0, #0x5a] */
/* @0x2b6258 cmp r3, #0 */
/* @0x2b625c beq 0x2b62a0 <jpeg_set_marker_processor+0x1fc> */
/* @0x2b6260 ldr r2, [r5, #0x18] */
/* @0x2b6264 mov r3, #1 */
/* @0x2b6268 str r2, [r0, #0x1a8] */
/* @0x2b626c strb r3, [r5, #0x8] */
/* @0x2b6270 b 0x2b611c <jpeg_set_marker_processor+0x78> */
/* @0x2b6274 ldr r3, [r4, #0x1a8] */
/* @0x2b6278 mov r0, r4 */
/* @0x2b627c ldrb r1, [r5, #0x8] */
/* @0x2b6280 ldr r3, [r3] */
/* @0x2b6284 blx r3 */
/* @0x2b6288 b 0x2b6170 <jpeg_set_marker_processor+0xcc> */
/* @0x2b628c ldr r3, [r4, #0x1a4] */
/* @0x2b6290 mov r0, r4 */
/* @0x2b6294 ldr r3, [r3] */
/* @0x2b6298 blx r3 */
/* @0x2b629c b 0x2b6154 <jpeg_set_marker_processor+0xb0> */
/* @0x2b62a0 ldrb r3, [r4, #0x58] */
/* @0x2b62a4 cmp r3, #0 */
/* @0x2b62a8 ldrne r3, [r5, #0x14] */
/* @0x2b62ac strne r3, [r4, #0x1a8] */
/* @0x2b62b0 bne 0x2b611c <jpeg_set_marker_processor+0x78> */
/* @0x2b62b4 ldr r3, [r4] */
/* @0x2b62b8 mov r2, #46 */
/* @0x2b62bc mov r0, r4 */
/* @0x2b62c0 str r2, [r3, #0x14] */
/* @0x2b62c4 ldr r3, [r3] */
/* @0x2b62c8 blx r3 */
/* @0x2b62cc b 0x2b611c <jpeg_set_marker_processor+0x78> */
/* @0x2b62d0 ldrb r2, [r0, #0x4a] */
/* @0x2b62d4 push {r4, lr} */
/* @0x2b62d8 cmp r2, #0 */
/* @0x2b62dc ldr r4, [r0, #0x180] */
/* @0x2b62e0 beq 0x2b62f0 <jpeg_set_marker_processor+0x24c> */
/* @0x2b62e4 ldr r3, [r0, #0x1a8] */
/* @0x2b62e8 ldr r3, [r3, #0x8] */
/* @0x2b62ec blx r3 */
/* @0x2b62f0 ldr r3, [r4, #0xc] */
/* @0x2b62f4 add r3, r3, #1 */
/* @0x2b62f8 str r3, [r4, #0xc] */
/* @0x2b62fc pop {r4, pc} */
/* @0x2b6300 ldrb r3, [r0, #0x48] */
/* @0x2b6304 cmp r3, #0 */
/* @0x2b6308 bne 0x2b6334 <jpeg_set_marker_processor+0x290> */
/* @0x2b630c ldrb r2, [r0, #0x10a] */
/* @0x2b6310 cmp r2, #0 */
/* @0x2b6314 bne 0x2b632c <jpeg_set_marker_processor+0x288> */
/* @0x2b6318 ldr r3, [r0, #0x28] */
/* @0x2b631c cmp r3, #3 */
/* @0x2b6320 beq 0x2b633c <jpeg_set_marker_processor+0x298> */
/* @0x2b6324 mov r0, r2 */
/* @0x2b6328 bx lr */
/* @0x2b632c mov r0, r3 */
/* @0x2b6330 bx lr */
/* @0x2b6334 mov r0, #0 */
/* @0x2b6338 bx lr */
/* @0x2b633c ldr r3, [r0, #0x24] */
/* @0x2b6340 cmp r3, #3 */
/* @0x2b6344 bne 0x2b6324 <jpeg_set_marker_processor+0x280> */
/* @0x2b6348 ldr r3, [r0, #0x2c] */
/* @0x2b634c cmp r3, #2 */
/* @0x2b6350 bne 0x2b6324 <jpeg_set_marker_processor+0x280> */
/* @0x2b6354 ldr r3, [r0, #0x64] */
/* @0x2b6358 cmp r3, #3 */
/* @0x2b635c bne 0x2b6324 <jpeg_set_marker_processor+0x280> */
/* @0x2b6360 ldr r3, [r0, #0xc4] */
/* @0x2b6364 ldr r1, [r3, #0x8] */
/* @0x2b6368 cmp r1, #2 */
/* @0x2b636c bne 0x2b6324 <jpeg_set_marker_processor+0x280> */
/* @0x2b6370 ldr r1, [r3, #0x5c] */
/* @0x2b6374 cmp r1, #1 */
/* @0x2b6378 bne 0x2b6324 <jpeg_set_marker_processor+0x280> */
/* @0x2b637c ldr r1, [r3, #0xb0] */
/* @0x2b6380 cmp r1, #1 */
/* @0x2b6384 bne 0x2b6324 <jpeg_set_marker_processor+0x280> */
/* @0x2b6388 ldr r2, [r3, #0xc] */
/* @0x2b638c cmp r2, #2 */
/* @0x2b6390 bgt 0x2b6334 <jpeg_set_marker_processor+0x290> */
/* @0x2b6394 ldr r2, [r3, #0x60] */
/* @0x2b6398 cmp r2, #1 */
/* @0x2b639c bne 0x2b6334 <jpeg_set_marker_processor+0x290> */
/* @0x2b63a0 ldr r2, [r3, #0xb4] */
/* @0x2b63a4 cmp r2, #1 */
/* @0x2b63a8 bne 0x2b6334 <jpeg_set_marker_processor+0x290> */
/* @0x2b63ac ldr r1, [r0, #0x118] */
/* @0x2b63b0 ldr r2, [r3, #0x24] */
/* @0x2b63b4 cmp r2, r1 */
/* @0x2b63b8 bne 0x2b6334 <jpeg_set_marker_processor+0x290> */
/* @0x2b63bc ldr r1, [r3, #0x78] */
/* @0x2b63c0 cmp r2, r1 */
/* @0x2b63c4 bne 0x2b6334 <jpeg_set_marker_processor+0x290> */
/* @0x2b63c8 ldr r0, [r3, #0xcc] */
/* @0x2b63cc subs r3, r2, r0 */
/* @0x2b63d0 rsbs r0, r3, #0 */
/* @0x2b63d4 adcs r0, r0, r3 */
/* @0x2b63d8 bx lr */

/* ── FUNC 0x2b63dc · jpeg_calc_output_dimensions · size=616 · insn=154 */
/* @0x2b63dc ldr r3, [r0, #0x14] */
/* @0x2b63e0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b63e4 cmp r3, #202 */
/* @0x2b63e8 mov r6, r0 */
/* @0x2b63ec beq 0x2b640c <jpeg_calc_output_dimensions+0x30> */
/* @0x2b63f0 ldr r2, [r0] */
/* @0x2b63f4 mov r1, #20 */
/* @0x2b63f8 str r3, [r2, #0x18] */
/* @0x2b63fc ldr r3, [r0] */
/* @0x2b6400 str r1, [r2, #0x14] */
/* @0x2b6404 ldr r3, [r3] */
/* @0x2b6408 blx r3 */
/* @0x2b640c ldr r2, [r6, #0x30] */
/* @0x2b6410 ldr r3, [r6, #0x34] */
/* @0x2b6414 cmp r3, r2, lsl #3 */
/* @0x2b6418 bhs 0x2b65b8 <jpeg_calc_output_dimensions+0x1dc> */
/* @0x2b641c cmp r3, r2, lsl #2 */
/* @0x2b6420 bhs 0x2b65ec <jpeg_calc_output_dimensions+0x210> */
/* @0x2b6424 cmp r3, r2, lsl #1 */
/* @0x2b6428 bhs 0x2b6618 <jpeg_calc_output_dimensions+0x23c> */
/* @0x2b642c ldr r2, [r6, #0x1c] */
/* @0x2b6430 mov r1, #8 */
/* @0x2b6434 ldr r3, [r6, #0x20] */
/* @0x2b6438 str r1, [r6, #0x118] */
/* @0x2b643c str r2, [r6, #0x5c] */
/* @0x2b6440 str r3, [r6, #0x60] */
/* @0x2b6444 ldr r9, [r6, #0x24] */
/* @0x2b6448 ldr r7, [r6, #0xc4] */
/* @0x2b644c cmp r9, #0 */
/* @0x2b6450 ble 0x2b6538 <jpeg_calc_output_dimensions+0x15c> */
/* @0x2b6454 ldr r0, [r6, #0x118] */
/* @0x2b6458 mov r8, r7 */
/* @0x2b645c mov r10, #0 */
/* @0x2b6460 cmp r0, #7 */
/* @0x2b6464 bgt 0x2b65b0 <jpeg_calc_output_dimensions+0x1d4> */
/* @0x2b6468 ldr r12, [r8, #0x8] */
/* @0x2b646c ldr lr, [r6, #0x110] */
/* @0x2b6470 mul r3, r12, r0 */
/* @0x2b6474 mul lr, lr, r0 */
/* @0x2b6478 cmp lr, r3, lsl #1 */
/* @0x2b647c blt 0x2b65b0 <jpeg_calc_output_dimensions+0x1d4> */
/* @0x2b6480 ldr r4, [r8, #0xc] */
/* @0x2b6484 ldr r5, [r6, #0x114] */
/* @0x2b6488 mul r3, r4, r0 */
/* @0x2b648c mul r5, r5, r0 */
/* @0x2b6490 cmp r5, r3, lsl #1 */
/* @0x2b6494 mov r3, r0 */
/* @0x2b6498 bge 0x2b64b4 <jpeg_calc_output_dimensions+0xd8> */
/* @0x2b649c b 0x2b64c4 <jpeg_calc_output_dimensions+0xe8> */
/* @0x2b64a0 cmp lr, r2, lsl #1 */
/* @0x2b64a4 mul r1, r4, r3 */
/* @0x2b64a8 blt 0x2b64c4 <jpeg_calc_output_dimensions+0xe8> */
/* @0x2b64ac cmp r5, r1, lsl #1 */
/* @0x2b64b0 blt 0x2b64c4 <jpeg_calc_output_dimensions+0xe8> */
/* @0x2b64b4 lsl r3, r3, #1 */
/* @0x2b64b8 cmp r3, #7 */
/* @0x2b64bc mul r2, r12, r3 */
/* @0x2b64c0 ble 0x2b64a0 <jpeg_calc_output_dimensions+0xc4> */
/* @0x2b64c4 add r10, r10, #1 */
/* @0x2b64c8 str r3, [r8, #0x24] */
/* @0x2b64cc cmp r10, r9 */
/* @0x2b64d0 add r8, r8, #84 */
/* @0x2b64d4 bne 0x2b6460 <jpeg_calc_output_dimensions+0x84> */
/* @0x2b64d8 mov r4, #0 */
/* @0x2b64dc ldr r2, [r7, #0x24] */
/* @0x2b64e0 add r4, r4, #1 */
/* @0x2b64e4 ldr r3, [r7, #0x8] */
/* @0x2b64e8 add r7, r7, #84 */
/* @0x2b64ec ldr r0, [r6, #0x1c] */
/* @0x2b64f0 ldr r1, [r6, #0x110] */
/* @0x2b64f4 mul r3, r2, r3 */
/* @0x2b64f8 lsl r1, r1, #3 */
/* @0x2b64fc mul r0, r0, r3 */
/* @0x2b6500 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b6504 ldr r3, [r7, #-0x48] */
/* @0x2b6508 ldr r2, [r7, #-0x30] */
/* @0x2b650c mul r3, r2, r3 */
/* @0x2b6510 str r0, [r7, #-0x2c] */
/* @0x2b6514 ldr r0, [r6, #0x20] */
/* @0x2b6518 ldr r1, [r6, #0x114] */
/* @0x2b651c mul r0, r0, r3 */
/* @0x2b6520 lsl r1, r1, #3 */
/* @0x2b6524 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b6528 str r0, [r7, #-0x28] */
/* @0x2b652c ldr r9, [r6, #0x24] */
/* @0x2b6530 cmp r9, r4 */
/* @0x2b6534 bgt 0x2b64dc <jpeg_calc_output_dimensions+0x100> */
/* @0x2b6538 ldr r3, [r6, #0x2c] */
/* @0x2b653c sub r3, r3, #1 */
/* @0x2b6540 cmp r3, #4 */
/* @0x2b6544 addls pc, pc, r3, lsl #2 */
/* @0x2b6548 b 0x2b65e4 <jpeg_calc_output_dimensions+0x208> */
/* @0x2b654c b 0x2b65a4 <jpeg_calc_output_dimensions+0x1c8> */
/* @0x2b6550 b 0x2b6598 <jpeg_calc_output_dimensions+0x1bc> */
/* @0x2b6554 b 0x2b6598 <jpeg_calc_output_dimensions+0x1bc> */
/* @0x2b6558 b 0x2b6560 <jpeg_calc_output_dimensions+0x184> */
/* @0x2b655c b 0x2b6560 <jpeg_calc_output_dimensions+0x184> */
/* @0x2b6560 mov r3, #4 */
/* @0x2b6564 str r3, [r6, #0x64] */
/* @0x2b6568 ldrb r3, [r6, #0x4a] */
/* @0x2b656c mov r0, r6 */
/* @0x2b6570 cmp r3, #0 */
/* @0x2b6574 ldreq r3, [r6, #0x64] */
/* @0x2b6578 movne r3, #1 */
/* @0x2b657c str r3, [r6, #0x68] */
/* @0x2b6580 bl 0x2b6300 <jpeg_set_marker_processor+0x25c> */
/* @0x2b6584 cmp r0, #0 */
/* @0x2b6588 ldrne r3, [r6, #0x114] */
/* @0x2b658c moveq r3, #1 */
/* @0x2b6590 str r3, [r6, #0x6c] */
/* @0x2b6594 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b6598 mov r3, #3 */
/* @0x2b659c str r3, [r6, #0x64] */
/* @0x2b65a0 b 0x2b6568 <jpeg_calc_output_dimensions+0x18c> */
/* @0x2b65a4 mov r3, #1 */
/* @0x2b65a8 str r3, [r6, #0x64] */
/* @0x2b65ac b 0x2b6568 <jpeg_calc_output_dimensions+0x18c> */
/* @0x2b65b0 mov r3, r0 */
/* @0x2b65b4 b 0x2b64c4 <jpeg_calc_output_dimensions+0xe8> */
/* @0x2b65b8 mov r1, #8 */
/* @0x2b65bc ldr r0, [r6, #0x1c] */
/* @0x2b65c0 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b65c4 mov r1, #8 */
/* @0x2b65c8 str r0, [r6, #0x5c] */
/* @0x2b65cc ldr r0, [r6, #0x20] */
/* @0x2b65d0 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b65d4 mov r3, #1 */
/* @0x2b65d8 str r3, [r6, #0x118] */
/* @0x2b65dc str r0, [r6, #0x60] */
/* @0x2b65e0 b 0x2b6444 <jpeg_calc_output_dimensions+0x68> */
/* @0x2b65e4 str r9, [r6, #0x64] */
/* @0x2b65e8 b 0x2b6568 <jpeg_calc_output_dimensions+0x18c> */
/* @0x2b65ec mov r1, #4 */
/* @0x2b65f0 ldr r0, [r6, #0x1c] */
/* @0x2b65f4 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b65f8 mov r1, #4 */
/* @0x2b65fc str r0, [r6, #0x5c] */
/* @0x2b6600 ldr r0, [r6, #0x20] */
/* @0x2b6604 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b6608 mov r3, #2 */
/* @0x2b660c str r3, [r6, #0x118] */
/* @0x2b6610 str r0, [r6, #0x60] */
/* @0x2b6614 b 0x2b6444 <jpeg_calc_output_dimensions+0x68> */
/* @0x2b6618 mov r1, #2 */
/* @0x2b661c ldr r0, [r6, #0x1c] */
/* @0x2b6620 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b6624 mov r1, #2 */
/* @0x2b6628 str r0, [r6, #0x5c] */
/* @0x2b662c ldr r0, [r6, #0x20] */
/* @0x2b6630 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b6634 mov r3, #4 */
/* @0x2b6638 str r3, [r6, #0x118] */
/* @0x2b663c str r0, [r6, #0x60] */
/* @0x2b6640 b 0x2b6444 <jpeg_calc_output_dimensions+0x68> */

/* ── FUNC 0x2b6644 · jpeg_new_colormap · size=148 · insn=37 */
/* @0x2b6644 push {r3, r4, r5, lr} */
/* @0x2b6648 mov r4, r0 */
/* @0x2b664c ldr r3, [r0, #0x14] */
/* @0x2b6650 ldr r5, [r0, #0x180] */
/* @0x2b6654 cmp r3, #207 */
/* @0x2b6658 beq 0x2b6678 <jpeg_new_colormap+0x34> */
/* @0x2b665c ldr r2, [r0] */
/* @0x2b6660 mov r1, #20 */
/* @0x2b6664 str r3, [r2, #0x18] */
/* @0x2b6668 ldr r3, [r0] */
/* @0x2b666c str r1, [r2, #0x14] */
/* @0x2b6670 ldr r3, [r3] */
/* @0x2b6674 blx r3 */
/* @0x2b6678 ldrb r3, [r4, #0x4a] */
/* @0x2b667c cmp r3, #0 */
/* @0x2b6680 beq 0x2b66bc <jpeg_new_colormap+0x78> */
/* @0x2b6684 ldrb r3, [r4, #0x59] */
/* @0x2b6688 cmp r3, #0 */
/* @0x2b668c beq 0x2b66bc <jpeg_new_colormap+0x78> */
/* @0x2b6690 ldr r3, [r4, #0x74] */
/* @0x2b6694 cmp r3, #0 */
/* @0x2b6698 beq 0x2b66bc <jpeg_new_colormap+0x78> */
/* @0x2b669c ldr r3, [r5, #0x18] */
/* @0x2b66a0 mov r0, r4 */
/* @0x2b66a4 str r3, [r4, #0x1a8] */
/* @0x2b66a8 ldr r3, [r3, #0xc] */
/* @0x2b66ac blx r3 */
/* @0x2b66b0 mov r3, #0 */
/* @0x2b66b4 strb r3, [r5, #0x8] */
/* @0x2b66b8 pop {r3, r4, r5, pc} */
/* @0x2b66bc ldr r3, [r4] */
/* @0x2b66c0 mov r1, #46 */
/* @0x2b66c4 mov r0, r4 */
/* @0x2b66c8 ldr r2, [r3] */
/* @0x2b66cc str r1, [r3, #0x14] */
/* @0x2b66d0 blx r2 */
/* @0x2b66d4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2b66d8 · jinit_master_decompress · size=864 · insn=216 */
/* @0x2b66d8 push {r3, r4, r5, r6, r7, lr} */
/* @0x2b66dc mov r1, #1 */
/* @0x2b66e0 ldr r3, [r0, #0x4] */
/* @0x2b66e4 mov r2, #28 */
/* @0x2b66e8 mov r4, r0 */
/* @0x2b66ec mov r7, #0 */
/* @0x2b66f0 ldr r3, [r3] */
/* @0x2b66f4 blx r3 */
/* @0x2b66f8 ldr r1, [pc, #0x330] */
/* @0x2b66fc ldr r2, [pc, #0x330] */
/* @0x2b6700 add r1, pc, r1 */
/* @0x2b6704 add r2, pc, r2 */
/* @0x2b6708 mov r3, r0 */
/* @0x2b670c mov r0, r4 */
/* @0x2b6710 str r3, [r4, #0x180] */
/* @0x2b6714 stm r3, {r1, r2} */
/* @0x2b6718 strb r7, [r3, #0x8] */
/* @0x2b671c ldr r5, [r4, #0x180] */
/* @0x2b6720 bl 0x2b63dc <jpeg_calc_output_dimensions> */
/* @0x2b6724 ldr r3, [r4, #0x4] */
/* @0x2b6728 mov r1, #1 */
/* @0x2b672c mov r2, #1408 */
/* @0x2b6730 mov r0, r4 */
/* @0x2b6734 ldr r3, [r3] */
/* @0x2b6738 blx r3 */
/* @0x2b673c mov r1, r7 */
/* @0x2b6740 mov r2, #256 */
/* @0x2b6744 add r3, r0, #256 */
/* @0x2b6748 str r3, [r4, #0x120] */
/* @0x2b674c mov r6, r0 */
/* @0x2b6750 bl 0xb65b0 <memset@plt> */
/* @0x2b6754 add r3, r6, #255 */
/* @0x2b6758 mov r1, r7 */
/* @0x2b675c strb r1, [r3, #0x1]! */
/* @0x2b6760 add r1, r1, #1 */
/* @0x2b6764 cmp r1, #256 */
/* @0x2b6768 bne 0x2b675c <jinit_master_decompress+0x84> */
/* @0x2b676c add r1, r6, #384 */
/* @0x2b6770 mov r3, #128 */
/* @0x2b6774 mvn r2, #0 */
/* @0x2b6778 strb r2, [r1, r3] */
/* @0x2b677c add r3, r3, #1 */
/* @0x2b6780 cmp r3, #512 */
/* @0x2b6784 bne 0x2b6778 <jinit_master_decompress+0xa0> */
/* @0x2b6788 mov r1, #0 */
/* @0x2b678c mov r2, #384 */
/* @0x2b6790 add r0, r6, #896 */
/* @0x2b6794 mov r7, r1 */
/* @0x2b6798 bl 0xb65b0 <memset@plt> */
/* @0x2b679c ldr r1, [r4, #0x120] */
/* @0x2b67a0 mov r2, #128 */
/* @0x2b67a4 add r0, r6, #1280 */
/* @0x2b67a8 bl 0xb65bc <memcpy@plt> */
/* @0x2b67ac str r7, [r5, #0xc] */
/* @0x2b67b0 mov r0, r4 */
/* @0x2b67b4 bl 0x2b6300 <jpeg_set_marker_processor+0x25c> */
/* @0x2b67b8 str r7, [r5, #0x14] */
/* @0x2b67bc str r7, [r5, #0x18] */
/* @0x2b67c0 strb r0, [r5, #0x10] */
/* @0x2b67c4 ldrb r3, [r4, #0x4a] */
/* @0x2b67c8 cmp r3, r7 */
/* @0x2b67cc beq 0x2b6948 <jinit_master_decompress+0x270> */
/* @0x2b67d0 ldrb r3, [r4, #0x40] */
/* @0x2b67d4 cmp r3, r7 */
/* @0x2b67d8 strbeq r3, [r4, #0x58] */
/* @0x2b67dc strbeq r3, [r4, #0x59] */
/* @0x2b67e0 strbeq r3, [r4, #0x5a] */
/* @0x2b67e4 ldrb r3, [r4, #0x41] */
/* @0x2b67e8 cmp r3, #0 */
/* @0x2b67ec bne 0x2b69c4 <jinit_master_decompress+0x2ec> */
/* @0x2b67f0 ldr r3, [r4, #0x64] */
/* @0x2b67f4 cmp r3, #3 */
/* @0x2b67f8 beq 0x2b69e8 <jinit_master_decompress+0x310> */
/* @0x2b67fc mov r3, #0 */
/* @0x2b6800 mov r2, #1 */
/* @0x2b6804 strb r3, [r4, #0x59] */
/* @0x2b6808 strb r2, [r4, #0x58] */
/* @0x2b680c strb r3, [r4, #0x5a] */
/* @0x2b6810 str r3, [r4, #0x74] */
/* @0x2b6814 mov r0, r4 */
/* @0x2b6818 bl 0x2bad30 <jinit_1pass_quantizer> */
/* @0x2b681c ldr r3, [r4, #0x1a8] */
/* @0x2b6820 str r3, [r5, #0x14] */
/* @0x2b6824 ldr r3, [r4, #0x58] */
/* @0x2b6828 bic r3, r3, #-16777216 */
/* @0x2b682c bic r3, r3, #255 */
/* @0x2b6830 cmp r3, #0 */
/* @0x2b6834 beq 0x2b6954 <jinit_master_decompress+0x27c> */
/* @0x2b6838 mov r0, r4 */
/* @0x2b683c bl 0x2bc654 <jinit_2pass_quantizer> */
/* @0x2b6840 ldr r3, [r4, #0x1a8] */
/* @0x2b6844 str r3, [r5, #0x18] */
/* @0x2b6848 ldrb r3, [r4, #0x41] */
/* @0x2b684c cmp r3, #0 */
/* @0x2b6850 beq 0x2b6960 <jinit_master_decompress+0x288> */
/* @0x2b6854 mov r0, r4 */
/* @0x2b6858 bl 0x2be47c <jinit_inverse_dct> */
/* @0x2b685c ldrb r3, [r4, #0xc9] */
/* @0x2b6860 cmp r3, #0 */
/* @0x2b6864 bne 0x2b69a8 <jinit_master_decompress+0x2d0> */
/* @0x2b6868 ldrb r3, [r4, #0xc8] */
/* @0x2b686c mov r0, r4 */
/* @0x2b6870 cmp r3, #0 */
/* @0x2b6874 bne 0x2b698c <jinit_master_decompress+0x2b4> */
/* @0x2b6878 bl 0x2bf19c <jinit_huff_decoder> */
/* @0x2b687c ldr r3, [r4, #0x190] */
/* @0x2b6880 ldrb r3, [r3, #0x10] */
/* @0x2b6884 cmp r3, #0 */
/* @0x2b6888 movne r1, #1 */
/* @0x2b688c bne 0x2b689c <jinit_master_decompress+0x1c4> */
/* @0x2b6890 ldrb r1, [r4, #0x40] */
/* @0x2b6894 adds r1, r1, #0 */
/* @0x2b6898 movne r1, #1 */
/* @0x2b689c mov r0, r4 */
/* @0x2b68a0 bl 0x2bd9a0 <jinit_d_coef_controller> */
/* @0x2b68a4 ldrb r1, [r4, #0x41] */
/* @0x2b68a8 cmp r1, #0 */
/* @0x2b68ac beq 0x2b699c <jinit_master_decompress+0x2c4> */
/* @0x2b68b0 ldr r3, [r4, #0x4] */
/* @0x2b68b4 mov r0, r4 */
/* @0x2b68b8 ldr r3, [r3, #0x18] */
/* @0x2b68bc blx r3 */
/* @0x2b68c0 ldr r3, [r4, #0x190] */
/* @0x2b68c4 mov r0, r4 */
/* @0x2b68c8 ldr r3, [r3, #0x8] */
/* @0x2b68cc blx r3 */
/* @0x2b68d0 ldr r3, [r4, #0x8] */
/* @0x2b68d4 cmp r3, #0 */
/* @0x2b68d8 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x2b68dc ldrb r2, [r4, #0x40] */
/* @0x2b68e0 cmp r2, #0 */
/* @0x2b68e4 popne {r3, r4, r5, r6, r7, pc} */
/* @0x2b68e8 ldr r2, [r4, #0x190] */
/* @0x2b68ec ldrb r2, [r2, #0x10] */
/* @0x2b68f0 cmp r2, #0 */
/* @0x2b68f4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x2b68f8 ldr r12, [r4, #0x24] */
/* @0x2b68fc ldrb r2, [r4, #0xc8] */
/* @0x2b6900 ldr r1, [r4, #0x11c] */
/* @0x2b6904 cmp r2, #0 */
/* @0x2b6908 ldr r0, [r5, #0xc] */
/* @0x2b690c addne r12, r12, r12, lsl #1 */
/* @0x2b6910 mov r2, #0 */
/* @0x2b6914 addne r12, r12, #2 */
/* @0x2b6918 str r2, [r3, #0x4] */
/* @0x2b691c str r2, [r3, #0xc] */
/* @0x2b6920 add r2, r0, #1 */
/* @0x2b6924 mul r1, r12, r1 */
/* @0x2b6928 str r1, [r3, #0x8] */
/* @0x2b692c ldrb r1, [r4, #0x5a] */
/* @0x2b6930 cmp r1, #0 */
/* @0x2b6934 moveq r1, #2 */
/* @0x2b6938 movne r1, #3 */
/* @0x2b693c str r1, [r3, #0x10] */
/* @0x2b6940 str r2, [r5, #0xc] */
/* @0x2b6944 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2b6948 strb r3, [r4, #0x58] */
/* @0x2b694c strb r3, [r4, #0x59] */
/* @0x2b6950 strb r3, [r4, #0x5a] */
/* @0x2b6954 ldrb r3, [r4, #0x41] */
/* @0x2b6958 cmp r3, #0 */
/* @0x2b695c bne 0x2b6854 <jinit_master_decompress+0x17c> */
/* @0x2b6960 ldrb r3, [r5, #0x10] */
/* @0x2b6964 mov r0, r4 */
/* @0x2b6968 cmp r3, #0 */
/* @0x2b696c bne 0x2b6994 <jinit_master_decompress+0x2bc> */
/* @0x2b6970 bl 0x2bdf68 <jinit_color_deconverter> */
/* @0x2b6974 mov r0, r4 */
/* @0x2b6978 bl 0x2b8ad0 <jinit_upsampler> */
/* @0x2b697c mov r0, r4 */
/* @0x2b6980 ldrb r1, [r4, #0x5a] */
/* @0x2b6984 bl 0x2b840c <jinit_d_post_controller> */
/* @0x2b6988 b 0x2b6854 <jinit_master_decompress+0x17c> */
/* @0x2b698c bl 0x2b7fdc <jinit_phuff_decoder> */
/* @0x2b6990 b 0x2b687c <jinit_master_decompress+0x1a4> */
/* @0x2b6994 bl 0x2b6f9c <jinit_merged_upsampler> */
/* @0x2b6998 b 0x2b697c <jinit_master_decompress+0x2a4> */
/* @0x2b699c mov r0, r4 */
/* @0x2b69a0 bl 0x2bf814 <jinit_d_main_controller> */
/* @0x2b69a4 b 0x2b68b0 <jinit_master_decompress+0x1d8> */
/* @0x2b69a8 ldr r3, [r4] */
/* @0x2b69ac mov r2, #1 */
/* @0x2b69b0 mov r0, r4 */
/* @0x2b69b4 str r2, [r3, #0x14] */
/* @0x2b69b8 ldr r3, [r3] */
/* @0x2b69bc blx r3 */
/* @0x2b69c0 b 0x2b687c <jinit_master_decompress+0x1a4> */
/* @0x2b69c4 ldr r3, [r4] */
/* @0x2b69c8 mov r2, #47 */
/* @0x2b69cc mov r0, r4 */
/* @0x2b69d0 str r2, [r3, #0x14] */
/* @0x2b69d4 ldr r3, [r3] */
/* @0x2b69d8 blx r3 */
/* @0x2b69dc ldr r3, [r4, #0x64] */
/* @0x2b69e0 cmp r3, #3 */
/* @0x2b69e4 bne 0x2b67fc <jinit_master_decompress+0x124> */
/* @0x2b69e8 ldr r3, [r4, #0x74] */
/* @0x2b69ec cmp r3, #0 */
/* @0x2b69f0 beq 0x2b6a0c <jinit_master_decompress+0x334> */
/* @0x2b69f4 ldrb r3, [r4, #0x58] */
/* @0x2b69f8 mov r2, #1 */
/* @0x2b69fc strb r2, [r4, #0x59] */
/* @0x2b6a00 cmp r3, #0 */
/* @0x2b6a04 beq 0x2b6824 <jinit_master_decompress+0x14c> */
/* @0x2b6a08 b 0x2b6814 <jinit_master_decompress+0x13c> */
/* @0x2b6a0c ldrb r3, [r4, #0x50] */
/* @0x2b6a10 cmp r3, #0 */
/* @0x2b6a14 movne r2, #1 */
/* @0x2b6a18 ldrbne r3, [r4, #0x58] */
/* @0x2b6a1c strbne r2, [r4, #0x5a] */
/* @0x2b6a20 bne 0x2b6a00 <jinit_master_decompress+0x328> */
/* @0x2b6a24 mov r3, #1 */
/* @0x2b6a28 strb r3, [r4, #0x58] */
/* @0x2b6a2c b 0x2b6814 <jinit_master_decompress+0x13c> */
/* @0x2b6a30 .word 0xfffff9e4 */
/* @0x2b6a34 .word 0xfffffbc4 */

/* ── FUNC 0x2b6a38 · anon_2b6a38 · size=1376 · insn=345 */
/* @0x2b6a38 ldr r3, [r0, #0x1a0] */
/* @0x2b6a3c mov r2, #0 */
/* @0x2b6a40 strb r2, [r3, #0x24] */
/* @0x2b6a44 ldr r2, [r0, #0x60] */
/* @0x2b6a48 str r2, [r3, #0x2c] */
/* @0x2b6a4c bx lr */
/* @0x2b6a50 push {r3, r4, r5, lr} */
/* @0x2b6a54 mov r4, r2 */
/* @0x2b6a58 ldr r5, [sp, #0x14] */
/* @0x2b6a5c ldr r12, [r0, #0x1a0] */
/* @0x2b6a60 ldr r3, [sp, #0x10] */
/* @0x2b6a64 ldr lr, [r5] */
/* @0x2b6a68 ldr r2, [r2] */
/* @0x2b6a6c ldr r12, [r12, #0xc] */
/* @0x2b6a70 add r3, r3, lr, lsl #2 */
/* @0x2b6a74 blx r12 */
/* @0x2b6a78 ldr r3, [r5] */
/* @0x2b6a7c add r3, r3, #1 */
/* @0x2b6a80 str r3, [r5] */
/* @0x2b6a84 ldr r3, [r4] */
/* @0x2b6a88 add r3, r3, #1 */
/* @0x2b6a8c str r3, [r4] */
/* @0x2b6a90 pop {r3, r4, r5, pc} */
/* @0x2b6a94 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2b6a98 sub sp, sp, #32 */
/* @0x2b6a9c ldr r5, [r0, #0x1a0] */
/* @0x2b6aa0 str r0, [sp, #0x10] */
/* @0x2b6aa4 ldr r4, [r0, #0x5c] */
/* @0x2b6aa8 ldr r12, [r1] */
/* @0x2b6aac ldr r0, [r1, #0x4] */
/* @0x2b6ab0 ldr r1, [r1, #0x8] */
/* @0x2b6ab4 lsrs r6, r4, #1 */
/* @0x2b6ab8 ldr r12, [r12, r2, lsl #2] */
/* @0x2b6abc str r6, [sp, #0x14] */
/* @0x2b6ac0 ldr r3, [r3] */
/* @0x2b6ac4 ldr r7, [r5, #0x14] */
/* @0x2b6ac8 ldr r1, [r1, r2, lsl #2] */
/* @0x2b6acc ldr r6, [sp, #0x10] */
/* @0x2b6ad0 str r12, [sp, #0x18] */
/* @0x2b6ad4 str r3, [sp, #0xc] */
/* @0x2b6ad8 ldr r12, [r0, r2, lsl #2] */
/* @0x2b6adc ldr r10, [r5, #0x10] */
/* @0x2b6ae0 str r7, [sp, #0x4] */
/* @0x2b6ae4 ldr r11, [r5, #0x18] */
/* @0x2b6ae8 ldr r9, [r5, #0x1c] */
/* @0x2b6aec str r1, [sp, #0x1c] */
/* @0x2b6af0 ldr r0, [r6, #0x120] */
/* @0x2b6af4 beq 0x2b6c34 <jinit_master_decompress+0x55c> */
/* @0x2b6af8 ldr r2, [sp, #0x18] */
/* @0x2b6afc mov r8, r1 */
/* @0x2b6b00 ldr r7, [sp, #0x14] */
/* @0x2b6b04 str r9, [sp] */
/* @0x2b6b08 add r7, r12, r7 */
/* @0x2b6b0c str r7, [sp, #0x8] */
/* @0x2b6b10 ldrb r4, [r12], #1 */
/* @0x2b6b14 add r2, r2, #2 */
/* @0x2b6b18 ldr r9, [sp, #0x8] */
/* @0x2b6b1c add r3, r3, #6 */
/* @0x2b6b20 ldrb r5, [r8], #1 */
/* @0x2b6b24 cmp r12, r9 */
/* @0x2b6b28 ldr r9, [sp] */
/* @0x2b6b2c ldrb r1, [r2, #-0x2] */
/* @0x2b6b30 ldr r6, [r10, r5, lsl #2] */
/* @0x2b6b34 ldr r7, [r9, r4, lsl #2] */
/* @0x2b6b38 ldr r5, [r11, r5, lsl #2] */
/* @0x2b6b3c add r6, r0, r6 */
/* @0x2b6b40 ldr r9, [sp, #0x4] */
/* @0x2b6b44 add r5, r7, r5 */
/* @0x2b6b48 ldrb r7, [r6, r1] */
/* @0x2b6b4c add r5, r0, r5, asr #16 */
/* @0x2b6b50 ldr r4, [r9, r4, lsl #2] */
/* @0x2b6b54 strb r7, [r3, #-0x6] */
/* @0x2b6b58 ldrb r7, [r5, r1] */
/* @0x2b6b5c add r4, r0, r4 */
/* @0x2b6b60 strb r7, [r3, #-0x5] */
/* @0x2b6b64 ldrb r1, [r4, r1] */
/* @0x2b6b68 strb r1, [r3, #-0x4] */
/* @0x2b6b6c ldrb r1, [r2, #-0x1] */
/* @0x2b6b70 ldrb r6, [r6, r1] */
/* @0x2b6b74 strb r6, [r3, #-0x3] */
/* @0x2b6b78 ldrb r5, [r5, r1] */
/* @0x2b6b7c strb r5, [r3, #-0x2] */
/* @0x2b6b80 ldrb r1, [r4, r1] */
/* @0x2b6b84 strb r1, [r3, #-0x1] */
/* @0x2b6b88 bne 0x2b6b10 <jinit_master_decompress+0x438> */
/* @0x2b6b8c ldr r12, [sp, #0x14] */
/* @0x2b6b90 ldr r6, [sp, #0x10] */
/* @0x2b6b94 ldr r1, [sp, #0x1c] */
/* @0x2b6b98 lsl r3, r12, #1 */
/* @0x2b6b9c ldr r9, [sp] */
/* @0x2b6ba0 ldr r4, [r6, #0x5c] */
/* @0x2b6ba4 add r1, r1, r12 */
/* @0x2b6ba8 add r2, r3, r12 */
/* @0x2b6bac ldr r7, [sp, #0x18] */
/* @0x2b6bb0 ldr r12, [sp, #0xc] */
/* @0x2b6bb4 add r7, r7, r3 */
/* @0x2b6bb8 str r1, [sp, #0x1c] */
/* @0x2b6bbc add r12, r12, r2, lsl #1 */
/* @0x2b6bc0 str r7, [sp, #0x18] */
/* @0x2b6bc4 str r12, [sp, #0xc] */
/* @0x2b6bc8 tst r4, #1 */
/* @0x2b6bcc beq 0x2b6c28 <jinit_master_decompress+0x550> */
/* @0x2b6bd0 ldr r2, [sp, #0x1c] */
/* @0x2b6bd4 ldr r3, [sp, #0x8] */
/* @0x2b6bd8 ldr r6, [sp, #0x18] */
/* @0x2b6bdc ldrb r1, [r2] */
/* @0x2b6be0 ldrb r2, [r3] */
/* @0x2b6be4 ldr r7, [sp, #0x4] */
/* @0x2b6be8 ldrb r3, [r6] */
/* @0x2b6bec ldr r5, [r9, r2, lsl #2] */
/* @0x2b6bf0 ldr r12, [r11, r1, lsl #2] */
/* @0x2b6bf4 add r4, r0, r3 */
/* @0x2b6bf8 ldr r1, [r10, r1, lsl #2] */
/* @0x2b6bfc ldr r2, [r7, r2, lsl #2] */
/* @0x2b6c00 add r12, r5, r12 */
/* @0x2b6c04 ldr r9, [sp, #0xc] */
/* @0x2b6c08 ldrb r1, [r4, r1] */
/* @0x2b6c0c add r2, r0, r2 */
/* @0x2b6c10 add r0, r0, r12, asr #16 */
/* @0x2b6c14 strb r1, [r9] */
/* @0x2b6c18 ldrb r1, [r0, r3] */
/* @0x2b6c1c strb r1, [r9, #0x1] */
/* @0x2b6c20 ldrb r3, [r2, r3] */
/* @0x2b6c24 strb r3, [r9, #0x2] */
/* @0x2b6c28 add sp, sp, #32 */
/* @0x2b6c2c pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2b6c30 bx lr */
/* @0x2b6c34 str r12, [sp, #0x8] */
/* @0x2b6c38 b 0x2b6bc8 <jinit_master_decompress+0x4f0> */
/* @0x2b6c3c push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2b6c40 sub sp, sp, #48 */
/* @0x2b6c44 ldr r5, [r1] */
/* @0x2b6c48 str r0, [sp, #0x1c] */
/* @0x2b6c4c ldr r7, [sp, #0x1c] */
/* @0x2b6c50 add r6, r5, r2, lsl #3 */
/* @0x2b6c54 ldr r12, [r1, #0x4] */
/* @0x2b6c58 ldr r5, [r5, r2, lsl #3] */
/* @0x2b6c5c ldr r4, [r7, #0x1a0] */
/* @0x2b6c60 ldr r0, [r0, #0x5c] */
/* @0x2b6c64 ldr r1, [r1, #0x8] */
/* @0x2b6c68 ldr r11, [r4, #0x10] */
/* @0x2b6c6c lsrs r10, r0, #1 */
/* @0x2b6c70 ldr r6, [r6, #0x4] */
/* @0x2b6c74 str r10, [sp, #0x20] */
/* @0x2b6c78 str r5, [sp, #0x24] */
/* @0x2b6c7c str r11, [sp, #0x4] */
/* @0x2b6c80 ldr r5, [r4, #0x18] */
/* @0x2b6c84 ldr r11, [r3] */
/* @0x2b6c88 ldr r10, [r4, #0x14] */
/* @0x2b6c8c ldr r1, [r1, r2, lsl #2] */
/* @0x2b6c90 ldr r4, [r4, #0x1c] */
/* @0x2b6c94 ldr r3, [r3, #0x4] */
/* @0x2b6c98 str r6, [sp, #0x28] */
/* @0x2b6c9c str r5, [sp, #0x8] */
/* @0x2b6ca0 str r4, [sp, #0xc] */
/* @0x2b6ca4 ldr r8, [r12, r2, lsl #2] */
/* @0x2b6ca8 str r1, [sp, #0x2c] */
/* @0x2b6cac ldr r7, [r7, #0x120] */
/* @0x2b6cb0 str r11, [sp, #0x14] */
/* @0x2b6cb4 str r3, [sp, #0x18] */
/* @0x2b6cb8 beq 0x2b6e90 <jinit_master_decompress+0x7b8> */
/* @0x2b6cbc ldr r5, [sp, #0x24] */
/* @0x2b6cc0 mov r2, r3 */
/* @0x2b6cc4 ldr r12, [sp, #0x20] */
/* @0x2b6cc8 mov r4, r6 */
/* @0x2b6ccc mov r9, r1 */
/* @0x2b6cd0 mov r3, r11 */
/* @0x2b6cd4 add r12, r8, r12 */
/* @0x2b6cd8 str r10, [sp] */
/* @0x2b6cdc str r12, [sp, #0x10] */
/* @0x2b6ce0 ldrb r0, [r9], #1 */
/* @0x2b6ce4 add r5, r5, #2 */
/* @0x2b6ce8 ldr r10, [sp, #0x4] */
/* @0x2b6cec add r3, r3, #6 */
/* @0x2b6cf0 ldrb r1, [r8], #1 */
/* @0x2b6cf4 add r4, r4, #2 */
/* @0x2b6cf8 ldr r11, [sp, #0x10] */
/* @0x2b6cfc add r2, r2, #6 */
/* @0x2b6d00 ldr r12, [r10, r0, lsl #2] */
/* @0x2b6d04 ldr r10, [sp, #0x8] */
/* @0x2b6d08 cmp r8, r11 */
/* @0x2b6d0c ldrb r6, [r5, #-0x2] */
/* @0x2b6d10 add r12, r7, r12 */
/* @0x2b6d14 ldr r0, [r10, r0, lsl #2] */
/* @0x2b6d18 ldr r10, [sp, #0xc] */
/* @0x2b6d1c ldr r11, [r10, r1, lsl #2] */
/* @0x2b6d20 ldr r10, [sp] */
/* @0x2b6d24 add r0, r11, r0 */
/* @0x2b6d28 ldrb r11, [r12, r6] */
/* @0x2b6d2c add r0, r7, r0, asr #16 */
/* @0x2b6d30 ldr r1, [r10, r1, lsl #2] */
/* @0x2b6d34 strb r11, [r3, #-0x6] */
/* @0x2b6d38 ldrb r11, [r0, r6] */
/* @0x2b6d3c add r1, r7, r1 */
/* @0x2b6d40 strb r11, [r3, #-0x5] */
/* @0x2b6d44 ldrb r6, [r1, r6] */
/* @0x2b6d48 strb r6, [r3, #-0x4] */
/* @0x2b6d4c ldrb r6, [r5, #-0x1] */
/* @0x2b6d50 ldrb r11, [r12, r6] */
/* @0x2b6d54 strb r11, [r3, #-0x3] */
/* @0x2b6d58 ldrb r11, [r0, r6] */
/* @0x2b6d5c strb r11, [r3, #-0x2] */
/* @0x2b6d60 ldrb r6, [r1, r6] */
/* @0x2b6d64 strb r6, [r3, #-0x1] */
/* @0x2b6d68 ldrb r6, [r4, #-0x2] */
/* @0x2b6d6c ldrb r11, [r12, r6] */
/* @0x2b6d70 strb r11, [r2, #-0x6] */
/* @0x2b6d74 ldrb r11, [r0, r6] */
/* @0x2b6d78 strb r11, [r2, #-0x5] */
/* @0x2b6d7c ldrb r6, [r1, r6] */
/* @0x2b6d80 strb r6, [r2, #-0x4] */
/* @0x2b6d84 ldrb r6, [r4, #-0x1] */
/* @0x2b6d88 ldrb r12, [r12, r6] */
/* @0x2b6d8c strb r12, [r2, #-0x3] */
/* @0x2b6d90 ldrb r0, [r0, r6] */
/* @0x2b6d94 strb r0, [r2, #-0x2] */
/* @0x2b6d98 ldrb r1, [r1, r6] */
/* @0x2b6d9c strb r1, [r2, #-0x1] */
/* @0x2b6da0 bne 0x2b6ce0 <jinit_master_decompress+0x608> */
/* @0x2b6da4 ldr r11, [sp, #0x20] */
/* @0x2b6da8 ldr r4, [sp, #0x1c] */
/* @0x2b6dac ldr r12, [sp, #0x2c] */
/* @0x2b6db0 lsl r3, r11, #1 */
/* @0x2b6db4 ldr r5, [sp, #0x24] */
/* @0x2b6db8 add r2, r3, r11 */
/* @0x2b6dbc ldr r0, [r4, #0x5c] */
/* @0x2b6dc0 add r12, r12, r11 */
/* @0x2b6dc4 ldr r1, [sp, #0x18] */
/* @0x2b6dc8 ldr r11, [sp, #0x28] */
/* @0x2b6dcc lsl r2, r2, #1 */
/* @0x2b6dd0 str r12, [sp, #0x2c] */
/* @0x2b6dd4 add r5, r5, r3 */
/* @0x2b6dd8 ldr r12, [sp, #0x14] */
/* @0x2b6ddc add r11, r11, r3 */
/* @0x2b6de0 add r1, r1, r2 */
/* @0x2b6de4 str r5, [sp, #0x24] */
/* @0x2b6de8 add r12, r12, r2 */
/* @0x2b6dec str r11, [sp, #0x28] */
/* @0x2b6df0 str r12, [sp, #0x14] */
/* @0x2b6df4 str r1, [sp, #0x18] */
/* @0x2b6df8 tst r0, #1 */
/* @0x2b6dfc beq 0x2b6e84 <jinit_master_decompress+0x7ac> */
/* @0x2b6e00 ldr r2, [sp, #0x2c] */
/* @0x2b6e04 ldr r3, [sp, #0x10] */
/* @0x2b6e08 ldr r4, [sp, #0x24] */
/* @0x2b6e0c ldrb r0, [r2] */
/* @0x2b6e10 ldr r5, [sp, #0x4] */
/* @0x2b6e14 ldrb r2, [r3] */
/* @0x2b6e18 ldr r11, [sp, #0x8] */
/* @0x2b6e1c ldrb r3, [r4] */
/* @0x2b6e20 ldr r4, [sp, #0xc] */
/* @0x2b6e24 ldr r1, [r5, r0, lsl #2] */
/* @0x2b6e28 ldr r0, [r11, r0, lsl #2] */
/* @0x2b6e2c ldr r12, [r4, r2, lsl #2] */
/* @0x2b6e30 add r1, r7, r1 */
/* @0x2b6e34 ldr r2, [r10, r2, lsl #2] */
/* @0x2b6e38 add r12, r12, r0 */
/* @0x2b6e3c ldr r5, [sp, #0x14] */
/* @0x2b6e40 ldrb r0, [r1, r3] */
/* @0x2b6e44 add r2, r7, r2 */
/* @0x2b6e48 add r7, r7, r12, asr #16 */
/* @0x2b6e4c ldr r10, [sp, #0x28] */
/* @0x2b6e50 ldr r11, [sp, #0x18] */
/* @0x2b6e54 strb r0, [r5] */
/* @0x2b6e58 ldrb r0, [r7, r3] */
/* @0x2b6e5c strb r0, [r5, #0x1] */
/* @0x2b6e60 ldrb r3, [r2, r3] */
/* @0x2b6e64 strb r3, [r5, #0x2] */
/* @0x2b6e68 ldrb r3, [r10] */
/* @0x2b6e6c ldrb r1, [r1, r3] */
/* @0x2b6e70 strb r1, [r11] */
/* @0x2b6e74 ldrb r1, [r7, r3] */
/* @0x2b6e78 strb r1, [r11, #0x1] */
/* @0x2b6e7c ldrb r3, [r2, r3] */
/* @0x2b6e80 strb r3, [r11, #0x2] */
/* @0x2b6e84 add sp, sp, #48 */
/* @0x2b6e88 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2b6e8c bx lr */
/* @0x2b6e90 str r8, [sp, #0x10] */
/* @0x2b6e94 b 0x2b6df8 <jinit_master_decompress+0x720> */
/* @0x2b6e98 push {r4, r5, r6, r7, lr} */
/* @0x2b6e9c sub sp, sp, #20 */
/* @0x2b6ea0 ldr r4, [r0, #0x1a0] */
/* @0x2b6ea4 mov r7, r2 */
/* @0x2b6ea8 ldr r6, [sp, #0x2c] */
/* @0x2b6eac ldr r2, [sp, #0x28] */
/* @0x2b6eb0 ldrb r3, [r4, #0x24] */
/* @0x2b6eb4 cmp r3, #0 */
/* @0x2b6eb8 bne 0x2b6f60 <jinit_master_decompress+0x888> */
/* @0x2b6ebc ldr r5, [r4, #0x2c] */
/* @0x2b6ec0 ldr r3, [r6] */
/* @0x2b6ec4 ldr lr, [sp, #0x30] */
/* @0x2b6ec8 cmp r5, #2 */
/* @0x2b6ecc movhs r5, #2 */
/* @0x2b6ed0 rsb r12, r3, lr */
/* @0x2b6ed4 cmp r5, r12 */
/* @0x2b6ed8 bhi 0x2b6f40 <jinit_master_decompress+0x868> */
/* @0x2b6edc ldr r12, [r2, r3, lsl #2] */
/* @0x2b6ee0 cmp r5, #2 */
/* @0x2b6ee4 lsl r3, r3, #2 */
/* @0x2b6ee8 str r12, [sp, #0x8] */
/* @0x2b6eec bne 0x2b6f94 <jinit_master_decompress+0x8bc> */
/* @0x2b6ef0 add r2, r2, r3 */
/* @0x2b6ef4 ldr r3, [r2, #0x4] */
/* @0x2b6ef8 str r3, [sp, #0xc] */
/* @0x2b6efc ldr r12, [r4, #0xc] */
/* @0x2b6f00 add r3, sp, #8 */
/* @0x2b6f04 ldr r2, [r7] */
/* @0x2b6f08 blx r12 */
/* @0x2b6f0c ldr r3, [r6] */
/* @0x2b6f10 add r3, r3, r5 */
/* @0x2b6f14 str r3, [r6] */
/* @0x2b6f18 ldrb r2, [r4, #0x24] */
/* @0x2b6f1c ldr r3, [r4, #0x2c] */
/* @0x2b6f20 cmp r2, #0 */
/* @0x2b6f24 rsb r5, r5, r3 */
/* @0x2b6f28 str r5, [r4, #0x2c] */
/* @0x2b6f2c ldreq r3, [r7] */
/* @0x2b6f30 addeq r3, r3, #1 */
/* @0x2b6f34 streq r3, [r7] */
/* @0x2b6f38 add sp, sp, #20 */
/* @0x2b6f3c pop {r4, r5, r6, r7, pc} */
/* @0x2b6f40 ldr r3, [r2, r3, lsl #2] */
/* @0x2b6f44 str r3, [sp, #0x8] */
/* @0x2b6f48 ldr r3, [r4, #0x20] */
/* @0x2b6f4c mov r2, #1 */
/* @0x2b6f50 mov r5, r12 */
/* @0x2b6f54 strb r2, [r4, #0x24] */
/* @0x2b6f58 str r3, [sp, #0xc] */
/* @0x2b6f5c b 0x2b6efc <jinit_master_decompress+0x824> */
/* @0x2b6f60 ldr r0, [r6] */
/* @0x2b6f64 mov r5, #1 */
/* @0x2b6f68 str r5, [sp] */
/* @0x2b6f6c mov r1, #0 */
/* @0x2b6f70 ldr r12, [r4, #0x28] */
/* @0x2b6f74 mov r3, r1 */
/* @0x2b6f78 add r2, r2, r0, lsl #2 */
/* @0x2b6f7c add r0, r4, #32 */
/* @0x2b6f80 str r12, [sp, #0x4] */
/* @0x2b6f84 bl 0x2bc81c <jcopy_sample_rows> */
/* @0x2b6f88 mov r3, #0 */
/* @0x2b6f8c strb r3, [r4, #0x24] */
/* @0x2b6f90 b 0x2b6f0c <jinit_master_decompress+0x834> */
/* @0x2b6f94 mov r12, r5 */
/* @0x2b6f98 b 0x2b6f48 <jinit_master_decompress+0x870> */

/* ── FUNC 0x2b6f9c · jinit_merged_upsampler · size=428 · insn=107 */
/* @0x2b6f9c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2b6fa0 mov r1, #1 */
/* @0x2b6fa4 ldr r3, [r0, #0x4] */
/* @0x2b6fa8 mov r2, #48 */
/* @0x2b6fac mov r4, r0 */
/* @0x2b6fb0 ldr r3, [r3] */
/* @0x2b6fb4 blx r3 */
/* @0x2b6fb8 mov r3, #0 */
/* @0x2b6fbc ldr r1, [pc, #0x170] */
/* @0x2b6fc0 add r1, pc, r1 */
/* @0x2b6fc4 str r0, [r4, #0x1a0] */
/* @0x2b6fc8 mov r5, r0 */
/* @0x2b6fcc strb r3, [r0, #0x8] */
/* @0x2b6fd0 ldr r2, [r4, #0x64] */
/* @0x2b6fd4 ldr r12, [r4, #0x5c] */
/* @0x2b6fd8 ldr r0, [r4, #0x114] */
/* @0x2b6fdc str r1, [r5] */
/* @0x2b6fe0 mul r2, r12, r2 */
/* @0x2b6fe4 cmp r0, #2 */
/* @0x2b6fe8 str r2, [r5, #0x28] */
/* @0x2b6fec beq 0x2b7100 <jinit_merged_upsampler+0x164> */
/* @0x2b6ff0 ldr r1, [pc, #0x140] */
/* @0x2b6ff4 ldr r2, [pc, #0x140] */
/* @0x2b6ff8 add r1, pc, r1 */
/* @0x2b6ffc str r3, [r5, #0x20] */
/* @0x2b7000 add r2, pc, r2 */
/* @0x2b7004 str r1, [r5, #0x4] */
/* @0x2b7008 str r2, [r5, #0xc] */
/* @0x2b700c ldr r3, [r4, #0x4] */
/* @0x2b7010 mov r0, r4 */
/* @0x2b7014 mov r1, #1 */
/* @0x2b7018 mov r2, #1024 */
/* @0x2b701c ldr r5, [r4, #0x1a0] */
/* @0x2b7020 ldr r3, [r3] */
/* @0x2b7024 blx r3 */
/* @0x2b7028 ldr r3, [r4, #0x4] */
/* @0x2b702c mov r1, #1 */
/* @0x2b7030 mov r2, #1024 */
/* @0x2b7034 ldr r3, [r3] */
/* @0x2b7038 str r0, [r5, #0x10] */
/* @0x2b703c mov r0, r4 */
/* @0x2b7040 blx r3 */
/* @0x2b7044 ldr r3, [r4, #0x4] */
/* @0x2b7048 mov r1, #1 */
/* @0x2b704c mov r2, #1024 */
/* @0x2b7050 ldr r3, [r3] */
/* @0x2b7054 str r0, [r5, #0x14] */
/* @0x2b7058 mov r0, r4 */
/* @0x2b705c blx r3 */
/* @0x2b7060 ldr r3, [r4, #0x4] */
/* @0x2b7064 mov r1, #1 */
/* @0x2b7068 mov r2, #1024 */
/* @0x2b706c ldr r3, [r3] */
/* @0x2b7070 str r0, [r5, #0x18] */
/* @0x2b7074 mov r0, r4 */
/* @0x2b7078 blx r3 */
/* @0x2b707c ldr r9, [r5, #0x10] */
/* @0x2b7080 ldr r8, [r5, #0x14] */
/* @0x2b7084 mov r4, #36096 */
/* @0x2b7088 ldr r7, [r5, #0x18] */
/* @0x2b708c mov r12, #26880 */
/* @0x2b7090 mov r2, #44800 */
/* @0x2b7094 mov r3, #2944 */
/* @0x2b7098 movt r4, #0x2c */
/* @0x2b709c movt r12, #0x5b */
/* @0x2b70a0 movt r2, #0xff1d */
/* @0x2b70a4 movt r3, #0xff4d */
/* @0x2b70a8 mov r1, #0 */
/* @0x2b70ac str r0, [r5, #0x1c] */
/* @0x2b70b0 asr r6, r3, #16 */
/* @0x2b70b4 asr r5, r2, #16 */
/* @0x2b70b8 str r6, [r9, r1] */
/* @0x2b70bc add r3, r3, #91136 */
/* @0x2b70c0 str r5, [r8, r1] */
/* @0x2b70c4 add r2, r2, #115712 */
/* @0x2b70c8 str r12, [r7, r1] */
/* @0x2b70cc add r3, r3, #744 */
/* @0x2b70d0 str r4, [r0, r1] */
/* @0x2b70d4 add r1, r1, #4 */
/* @0x2b70d8 cmp r1, #1024 */
/* @0x2b70dc add r2, r2, #416 */
/* @0x2b70e0 sub r12, r12, #46592 */
/* @0x2b70e4 sub r4, r4, #22528 */
/* @0x2b70e8 add r3, r3, #1 */
/* @0x2b70ec add r2, r2, #2 */
/* @0x2b70f0 sub r12, r12, #210 */
/* @0x2b70f4 sub r4, r4, #26 */
/* @0x2b70f8 bne 0x2b70b0 <jinit_merged_upsampler+0x114> */
/* @0x2b70fc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2b7100 ldr r3, [r4, #0x4] */
/* @0x2b7104 mov r0, r4 */
/* @0x2b7108 ldr lr, [pc, #0x30] */
/* @0x2b710c mov r1, #1 */
/* @0x2b7110 ldr r12, [pc, #0x2c] */
/* @0x2b7114 add lr, pc, lr */
/* @0x2b7118 ldr r3, [r3, #0x4] */
/* @0x2b711c add r12, pc, r12 */
/* @0x2b7120 str lr, [r5, #0x4] */
/* @0x2b7124 str r12, [r5, #0xc] */
/* @0x2b7128 blx r3 */
/* @0x2b712c str r0, [r5, #0x20] */
/* @0x2b7130 b 0x2b700c <jinit_merged_upsampler+0x70> */
/* @0x2b7134 .word 0xfffffa70 */
/* @0x2b7138 .word 0xfffffa50 */
/* @0x2b713c .word 0xfffffa8c */
/* @0x2b7140 .word 0xfffffd7c */
/* @0x2b7144 .word 0xfffffb18 */

/* ── FUNC 0x2b7148 · anon_2b7148 · size=3728 · insn=933 */
/* @0x2b7148 push {r4, r5, r6, lr} */
/* @0x2b714c mov r6, #0 */
/* @0x2b7150 ldr r4, [r0, #0x198] */
/* @0x2b7154 mov r5, r0 */
/* @0x2b7158 ldr r3, [r0, #0x194] */
/* @0x2b715c ldr r2, [r4, #0x10] */
/* @0x2b7160 ldr r12, [r3, #0x14] */
/* @0x2b7164 cmp r2, r6 */
/* @0x2b7168 add lr, r2, #7 */
/* @0x2b716c ldr r1, [r3, #0x8] */
/* @0x2b7170 movlt r2, lr */
/* @0x2b7174 add r2, r12, r2, asr #3 */
/* @0x2b7178 str r2, [r3, #0x14] */
/* @0x2b717c str r6, [r4, #0x10] */
/* @0x2b7180 blx r1 */
/* @0x2b7184 cmp r0, #0 */
/* @0x2b7188 popeq {r4, r5, r6, pc} */
/* @0x2b718c ldr r1, [r5, #0x124] */
/* @0x2b7190 cmp r1, r6 */
/* @0x2b7194 addgt r1, r4, r1, lsl #2 */
/* @0x2b7198 movgt r2, r6 */
/* @0x2b719c movgt r3, r4 */
/* @0x2b71a0 ble 0x2b71b4 <jinit_merged_upsampler+0x218> */
/* @0x2b71a4 str r2, [r3, #0x18] */
/* @0x2b71a8 add r3, r3, #4 */
/* @0x2b71ac cmp r3, r1 */
/* @0x2b71b0 bne 0x2b71a4 <jinit_merged_upsampler+0x208> */
/* @0x2b71b4 ldr r3, [r5, #0x17c] */
/* @0x2b71b8 mov r1, #0 */
/* @0x2b71bc ldr r2, [r5, #0xfc] */
/* @0x2b71c0 mov r0, #1 */
/* @0x2b71c4 cmp r3, r1 */
/* @0x2b71c8 str r1, [r4, #0x14] */
/* @0x2b71cc strbeq r3, [r4, #0x8] */
/* @0x2b71d0 str r2, [r4, #0x28] */
/* @0x2b71d4 pop {r4, r5, r6, pc} */
/* @0x2b71d8 ldr r3, [r0, #0x16c] */
/* @0x2b71dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b71e0 rsbs r2, r3, #1 */
/* @0x2b71e4 sub sp, sp, #12 */
/* @0x2b71e8 mov r4, r0 */
/* @0x2b71ec movlo r2, #0 */
/* @0x2b71f0 cmp r2, #0 */
/* @0x2b71f4 ldr r10, [r0, #0x198] */
/* @0x2b71f8 str r2, [sp, #0x4] */
/* @0x2b71fc ldr r0, [r0, #0x170] */
/* @0x2b7200 beq 0x2b7358 <jinit_merged_upsampler+0x3bc> */
/* @0x2b7204 adds r0, r0, #0 */
/* @0x2b7208 movne r0, #1 */
/* @0x2b720c ldr r1, [r4, #0x174] */
/* @0x2b7210 ldr r2, [r4, #0x178] */
/* @0x2b7214 cmp r1, #0 */
/* @0x2b7218 beq 0x2b7228 <jinit_merged_upsampler+0x28c> */
/* @0x2b721c sub r1, r1, #1 */
/* @0x2b7220 cmp r2, r1 */
/* @0x2b7224 bne 0x2b7230 <jinit_merged_upsampler+0x294> */
/* @0x2b7228 cmp r2, #13 */
/* @0x2b722c ble 0x2b73d0 <jinit_merged_upsampler+0x434> */
/* @0x2b7230 ldr r2, [r4] */
/* @0x2b7234 mov r12, #16 */
/* @0x2b7238 mov r0, r4 */
/* @0x2b723c str r3, [r2, #0x18] */
/* @0x2b7240 ldr r3, [r4] */
/* @0x2b7244 ldr r1, [r4, #0x170] */
/* @0x2b7248 str r12, [r2, #0x14] */
/* @0x2b724c str r1, [r3, #0x1c] */
/* @0x2b7250 ldr r3, [r4] */
/* @0x2b7254 ldr r2, [r4, #0x174] */
/* @0x2b7258 str r2, [r3, #0x20] */
/* @0x2b725c ldr r3, [r4] */
/* @0x2b7260 ldr r2, [r4, #0x178] */
/* @0x2b7264 str r2, [r3, #0x24] */
/* @0x2b7268 ldr r3, [r4] */
/* @0x2b726c ldr r3, [r3] */
/* @0x2b7270 blx r3 */
/* @0x2b7274 ldr r3, [r4, #0x124] */
/* @0x2b7278 cmp r3, #0 */
/* @0x2b727c ble 0x2b7330 <jinit_merged_upsampler+0x394> */
/* @0x2b7280 mov r9, r4 */
/* @0x2b7284 mov r8, #0 */
/* @0x2b7288 mov r7, #115 */
/* @0x2b728c ldr r3, [r9, #0x128] */
/* @0x2b7290 ldr r2, [sp, #0x4] */
/* @0x2b7294 ldr r6, [r3, #0x4] */
/* @0x2b7298 cmp r2, #0 */
/* @0x2b729c ldr r2, [r4, #0x8c] */
/* @0x2b72a0 add r11, r2, r6, lsl #8 */
/* @0x2b72a4 bne 0x2b72b4 <jinit_merged_upsampler+0x318> */
/* @0x2b72a8 ldr r2, [r2, r6, lsl #8] */
/* @0x2b72ac cmp r2, #0 */
/* @0x2b72b0 blt 0x2b74b0 <jinit_merged_upsampler+0x514> */
/* @0x2b72b4 ldr r5, [r4, #0x16c] */
/* @0x2b72b8 ldr r2, [r4, #0x170] */
/* @0x2b72bc cmp r5, r2 */
/* @0x2b72c0 addle r11, r11, r5, lsl #2 */
/* @0x2b72c4 bgt 0x2b731c <jinit_merged_upsampler+0x380> */
/* @0x2b72c8 ldr r2, [r11], #4 */
/* @0x2b72cc mov r0, r4 */
/* @0x2b72d0 ldr r12, [r4, #0x174] */
/* @0x2b72d4 mvn r1, #0 */
/* @0x2b72d8 bic r2, r2, r2, asr #31 */
/* @0x2b72dc cmp r12, r2 */
/* @0x2b72e0 beq 0x2b7304 <jinit_merged_upsampler+0x368> */
/* @0x2b72e4 ldr r2, [r4] */
/* @0x2b72e8 str r6, [r2, #0x18] */
/* @0x2b72ec ldr r12, [r4] */
/* @0x2b72f0 str r7, [r2, #0x14] */
/* @0x2b72f4 str r5, [r12, #0x1c] */
/* @0x2b72f8 ldr r2, [r4] */
/* @0x2b72fc ldr r2, [r2, #0x4] */
/* @0x2b7300 blx r2 */
/* @0x2b7304 ldr r2, [r4, #0x178] */
/* @0x2b7308 add r5, r5, #1 */
/* @0x2b730c str r2, [r11, #-0x4] */
/* @0x2b7310 ldr r2, [r4, #0x170] */
/* @0x2b7314 cmp r2, r5 */
/* @0x2b7318 bge 0x2b72c8 <jinit_merged_upsampler+0x32c> */
/* @0x2b731c ldr r3, [r4, #0x124] */
/* @0x2b7320 add r8, r8, #1 */
/* @0x2b7324 add r9, r9, #4 */
/* @0x2b7328 cmp r3, r8 */
/* @0x2b732c bgt 0x2b728c <jinit_merged_upsampler+0x2f0> */
/* @0x2b7330 ldr r2, [r4, #0x174] */
/* @0x2b7334 ldr r1, [sp, #0x4] */
/* @0x2b7338 cmp r2, #0 */
/* @0x2b733c bne 0x2b7374 <jinit_merged_upsampler+0x3d8> */
/* @0x2b7340 cmp r1, #0 */
/* @0x2b7344 beq 0x2b7484 <jinit_merged_upsampler+0x4e8> */
/* @0x2b7348 ldr r1, [pc, #0x190] */
/* @0x2b734c add r1, pc, r1 */
/* @0x2b7350 str r1, [r10, #0x4] */
/* @0x2b7354 b 0x2b7388 <jinit_merged_upsampler+0x3ec> */
/* @0x2b7358 cmp r3, r0 */
/* @0x2b735c movgt r0, #1 */
/* @0x2b7360 ble 0x2b7468 <jinit_merged_upsampler+0x4cc> */
/* @0x2b7364 ldr r2, [r4, #0x124] */
/* @0x2b7368 cmp r2, #1 */
/* @0x2b736c movne r0, #1 */
/* @0x2b7370 b 0x2b720c <jinit_merged_upsampler+0x270> */
/* @0x2b7374 cmp r1, #0 */
/* @0x2b7378 beq 0x2b73dc <jinit_merged_upsampler+0x440> */
/* @0x2b737c ldr r1, [pc, #0x160] */
/* @0x2b7380 add r1, pc, r1 */
/* @0x2b7384 str r1, [r10, #0x4] */
/* @0x2b7388 cmp r3, #0 */
/* @0x2b738c ble 0x2b7444 <jinit_merged_upsampler+0x4a8> */
/* @0x2b7390 mov r5, #0 */
/* @0x2b7394 mov r7, r4 */
/* @0x2b7398 mov r8, r5 */
/* @0x2b739c mov r6, r10 */
/* @0x2b73a0 cmp r2, #0 */
/* @0x2b73a4 ldr r3, [r7, #0x128] */
/* @0x2b73a8 add r5, r5, #1 */
/* @0x2b73ac add r7, r7, #4 */
/* @0x2b73b0 beq 0x2b7494 <jinit_merged_upsampler+0x4f8> */
/* @0x2b73b4 str r8, [r6, #0x18] */
/* @0x2b73b8 add r6, r6, #4 */
/* @0x2b73bc ldr r3, [r4, #0x124] */
/* @0x2b73c0 cmp r3, r5 */
/* @0x2b73c4 ble 0x2b7444 <jinit_merged_upsampler+0x4a8> */
/* @0x2b73c8 ldr r2, [r4, #0x174] */
/* @0x2b73cc b 0x2b73a0 <jinit_merged_upsampler+0x404> */
/* @0x2b73d0 cmp r0, #0 */
/* @0x2b73d4 beq 0x2b7274 <jinit_merged_upsampler+0x2d8> */
/* @0x2b73d8 b 0x2b7230 <jinit_merged_upsampler+0x294> */
/* @0x2b73dc ldr r2, [pc, #0x104] */
/* @0x2b73e0 add r2, pc, r2 */
/* @0x2b73e4 str r2, [r10, #0x4] */
/* @0x2b73e8 cmp r3, #0 */
/* @0x2b73ec ble 0x2b7444 <jinit_merged_upsampler+0x4a8> */
/* @0x2b73f0 mov r5, #0 */
/* @0x2b73f4 mov r7, r4 */
/* @0x2b73f8 mov r9, r5 */
/* @0x2b73fc mov r6, r10 */
/* @0x2b7400 ldr r3, [r7, #0x128] */
/* @0x2b7404 mov r0, r4 */
/* @0x2b7408 mov r1, #0 */
/* @0x2b740c add r5, r5, #1 */
/* @0x2b7410 add r7, r7, #4 */
/* @0x2b7414 add r6, r6, #4 */
/* @0x2b7418 ldr r2, [r3, #0x18] */
/* @0x2b741c add r8, r2, #10 */
/* @0x2b7420 add r8, r10, r8, lsl #2 */
/* @0x2b7424 add r3, r8, #4 */
/* @0x2b7428 bl 0x2be510 <jpeg_make_d_derived_tbl> */
/* @0x2b742c ldr r3, [r8, #0x4] */
/* @0x2b7430 str r3, [r10, #0x3c] */
/* @0x2b7434 str r9, [r6, #0x14] */
/* @0x2b7438 ldr r3, [r4, #0x124] */
/* @0x2b743c cmp r3, r5 */
/* @0x2b7440 bgt 0x2b7400 <jinit_merged_upsampler+0x464> */
/* @0x2b7444 mov r3, #0 */
/* @0x2b7448 strb r3, [r10, #0x8] */
/* @0x2b744c ldr r2, [r4, #0xfc] */
/* @0x2b7450 str r3, [r10, #0x10] */
/* @0x2b7454 str r3, [r10, #0xc] */
/* @0x2b7458 str r2, [r10, #0x28] */
/* @0x2b745c str r3, [r10, #0x14] */
/* @0x2b7460 add sp, sp, #12 */
/* @0x2b7464 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7468 cmp r0, #63 */
/* @0x2b746c ldr r2, [r4, #0x124] */
/* @0x2b7470 movle r0, #0 */
/* @0x2b7474 movgt r0, #1 */
/* @0x2b7478 cmp r2, #1 */
/* @0x2b747c movne r0, #1 */
/* @0x2b7480 b 0x2b720c <jinit_merged_upsampler+0x270> */
/* @0x2b7484 ldr r2, [pc, #0x60] */
/* @0x2b7488 add r2, pc, r2 */
/* @0x2b748c str r2, [r10, #0x4] */
/* @0x2b7490 b 0x2b73e8 <jinit_merged_upsampler+0x44c> */
/* @0x2b7494 ldr r2, [r3, #0x14] */
/* @0x2b7498 mov r0, r4 */
/* @0x2b749c mov r1, #1 */
/* @0x2b74a0 add r3, r10, r2, lsl #2 */
/* @0x2b74a4 add r3, r3, #44 */
/* @0x2b74a8 bl 0x2be510 <jpeg_make_d_derived_tbl> */
/* @0x2b74ac b 0x2b73b4 <jinit_merged_upsampler+0x418> */
/* @0x2b74b0 ldr r2, [r4] */
/* @0x2b74b4 mov r0, r4 */
/* @0x2b74b8 ldr r3, [sp, #0x4] */
/* @0x2b74bc mvn r1, #0 */
/* @0x2b74c0 str r6, [r2, #0x18] */
/* @0x2b74c4 ldr r12, [r4] */
/* @0x2b74c8 str r7, [r2, #0x14] */
/* @0x2b74cc str r3, [r12, #0x1c] */
/* @0x2b74d0 ldr r2, [r4] */
/* @0x2b74d4 ldr r2, [r2, #0x4] */
/* @0x2b74d8 blx r2 */
/* @0x2b74dc b 0x2b72b4 <jinit_merged_upsampler+0x318> */
/* @0x2b74e0 strdeq r0, r1, [r0], -r12 */
/* @0x2b74e4 andeq r0, r0, r8, ror #2 */
/* @0x2b74e8 andeq r0, r0, r12, lsl r2 */
/* @0x2b74ec andeq r0, r0, r12, lsr #12 */
/* @0x2b74f0 ldr r2, [r0, #0xfc] */
/* @0x2b74f4 mov r3, #1 */
/* @0x2b74f8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b74fc cmp r2, #0 */
/* @0x2b7500 ldr r7, [r0, #0x178] */
/* @0x2b7504 sub sp, sp, #24 */
/* @0x2b7508 mov r8, r0 */
/* @0x2b750c mov r5, r1 */
/* @0x2b7510 ldr r10, [r0, #0x198] */
/* @0x2b7514 lsl r7, r3, r7 */
/* @0x2b7518 beq 0x2b7528 <jinit_merged_upsampler+0x58c> */
/* @0x2b751c ldr r3, [r10, #0x28] */
/* @0x2b7520 cmp r3, #0 */
/* @0x2b7524 beq 0x2b75ec <jinit_merged_upsampler+0x650> */
/* @0x2b7528 ldr r3, [r8, #0x18] */
/* @0x2b752c ldr r0, [r8, #0x140] */
/* @0x2b7530 str r8, [sp, #0x14] */
/* @0x2b7534 ldr r12, [r3] */
/* @0x2b7538 cmp r0, #0 */
/* @0x2b753c ldr r4, [r3, #0x4] */
/* @0x2b7540 subgt r5, r5, #4 */
/* @0x2b7544 ldr r1, [r10, #0xc] */
/* @0x2b7548 addgt r9, sp, #4 */
/* @0x2b754c str r12, [sp, #0x4] */
/* @0x2b7550 str r4, [sp, #0x8] */
/* @0x2b7554 movgt r4, #0 */
/* @0x2b7558 ldr r2, [r10, #0x10] */
/* @0x2b755c bgt 0x2b7584 <jinit_merged_upsampler+0x5e8> */
/* @0x2b7560 b 0x2b75c4 <jinit_merged_upsampler+0x628> */
/* @0x2b7564 sub r2, r2, #1 */
/* @0x2b7568 asr r3, r1, r2 */
/* @0x2b756c tst r3, #1 */
/* @0x2b7570 ldrhne r3, [r6] */
/* @0x2b7574 orrne r3, r7, r3 */
/* @0x2b7578 strhne r3, [r6] */
/* @0x2b757c cmp r0, r4 */
/* @0x2b7580 ble 0x2b75b8 <jinit_merged_upsampler+0x61c> */
/* @0x2b7584 cmp r2, #0 */
/* @0x2b7588 add r4, r4, #1 */
/* @0x2b758c ldr r6, [r5, #0x4]! */
/* @0x2b7590 bgt 0x2b7564 <jinit_merged_upsampler+0x5c8> */
/* @0x2b7594 mov r0, r9 */
/* @0x2b7598 mov r3, #1 */
/* @0x2b759c bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b75a0 cmp r0, #0 */
/* @0x2b75a4 beq 0x2b75f8 <jinit_merged_upsampler+0x65c> */
/* @0x2b75a8 ldr r1, [sp, #0xc] */
/* @0x2b75ac ldr r2, [sp, #0x10] */
/* @0x2b75b0 ldr r0, [r8, #0x140] */
/* @0x2b75b4 b 0x2b7564 <jinit_merged_upsampler+0x5c8> */
/* @0x2b75b8 ldr r3, [r8, #0x18] */
/* @0x2b75bc ldr r12, [sp, #0x4] */
/* @0x2b75c0 ldr r4, [sp, #0x8] */
/* @0x2b75c4 ldr r5, [r10, #0x28] */
/* @0x2b75c8 mov r0, #1 */
/* @0x2b75cc str r12, [r3] */
/* @0x2b75d0 str r4, [r3, #0x4] */
/* @0x2b75d4 sub r3, r5, #1 */
/* @0x2b75d8 str r1, [r10, #0xc] */
/* @0x2b75dc str r2, [r10, #0x10] */
/* @0x2b75e0 str r3, [r10, #0x28] */
/* @0x2b75e4 add sp, sp, #24 */
/* @0x2b75e8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b75ec bl 0x2b7148 <jinit_merged_upsampler+0x1ac> */
/* @0x2b75f0 cmp r0, #0 */
/* @0x2b75f4 bne 0x2b7528 <jinit_merged_upsampler+0x58c> */
/* @0x2b75f8 mov r0, #0 */
/* @0x2b75fc add sp, sp, #24 */
/* @0x2b7600 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b7604 ldr r3, [r0, #0xfc] */
/* @0x2b7608 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b760c cmp r3, #0 */
/* @0x2b7610 ldr r5, [r0, #0x198] */
/* @0x2b7614 sub sp, sp, #332 */
/* @0x2b7618 ldr r9, [r0, #0x170] */
/* @0x2b761c str r0, [sp, #0x14] */
/* @0x2b7620 str r5, [sp, #0x18] */
/* @0x2b7624 ldr r4, [r0, #0x178] */
/* @0x2b7628 beq 0x2b763c <jinit_merged_upsampler+0x6a0> */
/* @0x2b762c ldr r12, [sp, #0x18] */
/* @0x2b7630 ldr r3, [r12, #0x28] */
/* @0x2b7634 cmp r3, #0 */
/* @0x2b7638 beq 0x2b7a54 <jinit_merged_upsampler+0xab8> */
/* @0x2b763c ldr r6, [sp, #0x18] */
/* @0x2b7640 ldrb r12, [r6, #0x8] */
/* @0x2b7644 cmp r12, #0 */
/* @0x2b7648 bne 0x2b7854 <jinit_merged_upsampler+0x8b8> */
/* @0x2b764c ldr r5, [sp, #0x14] */
/* @0x2b7650 mov r2, #1 */
/* @0x2b7654 ldr r6, [sp, #0x18] */
/* @0x2b7658 mvn r3, #0 */
/* @0x2b765c ldr r7, [r1] */
/* @0x2b7660 lsl r3, r3, r4 */
/* @0x2b7664 ldr r1, [sp, #0x18] */
/* @0x2b7668 lsl r11, r2, r4 */
/* @0x2b766c ldr r6, [r6, #0x14] */
/* @0x2b7670 ldr r0, [r5, #0x18] */
/* @0x2b7674 str r3, [sp, #0x28] */
/* @0x2b7678 cmp r6, #0 */
/* @0x2b767c ldr r3, [r1, #0xc] */
/* @0x2b7680 ldr r2, [r1, #0x10] */
/* @0x2b7684 ldr r1, [r1, #0x3c] */
/* @0x2b7688 str r6, [sp, #0x2c] */
/* @0x2b768c str r5, [sp, #0x44] */
/* @0x2b7690 ldr r6, [r0, #0x4] */
/* @0x2b7694 ldr r5, [r0] */
/* @0x2b7698 str r1, [sp, #0x1c] */
/* @0x2b769c ldr r1, [sp, #0x14] */
/* @0x2b76a0 str r5, [sp, #0x34] */
/* @0x2b76a4 str r6, [sp, #0x38] */
/* @0x2b76a8 ldr r4, [r1, #0x16c] */
/* @0x2b76ac bne 0x2b7870 <jinit_merged_upsampler+0x8d4> */
/* @0x2b76b0 cmp r9, r4 */
/* @0x2b76b4 blt 0x2b783c <jinit_merged_upsampler+0x8a0> */
/* @0x2b76b8 ldr r5, [sp, #0x2c] */
/* @0x2b76bc str r5, [sp, #0x24] */
/* @0x2b76c0 cmp r2, #7 */
/* @0x2b76c4 ble 0x2b79c4 <jinit_merged_upsampler+0xa28> */
/* @0x2b76c8 sub r0, r2, #8 */
/* @0x2b76cc ldr r6, [sp, #0x1c] */
/* @0x2b76d0 asr r0, r3, r0 */
/* @0x2b76d4 uxtb r0, r0 */
/* @0x2b76d8 add r1, r0, #36 */
/* @0x2b76dc ldr r1, [r6, r1, lsl #2] */
/* @0x2b76e0 cmp r1, #0 */
/* @0x2b76e4 beq 0x2b7994 <jinit_merged_upsampler+0x9f8> */
/* @0x2b76e8 add r0, r6, r0 */
/* @0x2b76ec rsb r2, r1, r2 */
/* @0x2b76f0 ldrb r0, [r0, #0x490] */
/* @0x2b76f4 ands r10, r0, #15 */
/* @0x2b76f8 asr r8, r0, #4 */
/* @0x2b76fc beq 0x2b7938 <jinit_merged_upsampler+0x99c> */
/* @0x2b7700 cmp r10, #1 */
/* @0x2b7704 beq 0x2b7738 <jinit_merged_upsampler+0x79c> */
/* @0x2b7708 ldr r5, [sp, #0x14] */
/* @0x2b770c mvn r1, #0 */
/* @0x2b7710 mov r6, #118 */
/* @0x2b7714 ldr r12, [r5] */
/* @0x2b7718 mov r0, r5 */
/* @0x2b771c str r6, [r12, #0x14] */
/* @0x2b7720 ldr r12, [r12, #0x4] */
/* @0x2b7724 str r2, [sp, #0x8] */
/* @0x2b7728 str r3, [sp, #0xc] */
/* @0x2b772c blx r12 */
/* @0x2b7730 ldr r3, [sp, #0xc] */
/* @0x2b7734 ldr r2, [sp, #0x8] */
/* @0x2b7738 cmp r2, #0 */
/* @0x2b773c ble 0x2b79f8 <jinit_merged_upsampler+0xa5c> */
/* @0x2b7740 sub r2, r2, #1 */
/* @0x2b7744 ldr r10, [sp, #0x28] */
/* @0x2b7748 asr r1, r3, r2 */
/* @0x2b774c tst r1, #1 */
/* @0x2b7750 movne r10, r11 */
/* @0x2b7754 ldr r12, [pc, #0x358] */
/* @0x2b7758 add r6, sp, #52 */
/* @0x2b775c str r6, [sp, #0x10] */
/* @0x2b7760 mov r1, r3 */
/* @0x2b7764 ldr r12, [pc, r12] */
/* @0x2b7768 str r10, [sp, #0x20] */
/* @0x2b776c add r6, r12, r4, lsl #2 */
/* @0x2b7770 mov r10, r11 */
/* @0x2b7774 sub r6, r6, #4 */
/* @0x2b7778 mov r11, r12 */
/* @0x2b777c b 0x2b77c8 <jinit_merged_upsampler+0x82c> */
/* @0x2b7780 cmp r2, #0 */
/* @0x2b7784 ble 0x2b7918 <jinit_merged_upsampler+0x97c> */
/* @0x2b7788 sub r2, r2, #1 */
/* @0x2b778c asr r3, r1, r2 */
/* @0x2b7790 tst r3, #1 */
/* @0x2b7794 beq 0x2b77bc <jinit_merged_upsampler+0x820> */
/* @0x2b7798 ldrh r0, [r7, r5] */
/* @0x2b779c sxth r3, r0 */
/* @0x2b77a0 tst r3, r10 */
/* @0x2b77a4 bne 0x2b77bc <jinit_merged_upsampler+0x820> */
/* @0x2b77a8 cmp r3, #0 */
/* @0x2b77ac addge r0, r0, r10 */
/* @0x2b77b0 ldrlt r12, [sp, #0x28] */
/* @0x2b77b4 addlt r0, r0, r12 */
/* @0x2b77b8 strh r0, [r7, r5] */
/* @0x2b77bc add r4, r4, #1 */
/* @0x2b77c0 cmp r9, r4 */
/* @0x2b77c4 blt 0x2b77e4 <jinit_merged_upsampler+0x848> */
/* @0x2b77c8 ldr r5, [r6, #0x4]! */
/* @0x2b77cc lsl r5, r5, #1 */
/* @0x2b77d0 ldrsh r0, [r7, r5] */
/* @0x2b77d4 cmp r0, #0 */
/* @0x2b77d8 bne 0x2b7780 <jinit_merged_upsampler+0x7e4> */
/* @0x2b77dc subs r8, r8, #1 */
/* @0x2b77e0 bhs 0x2b77bc <jinit_merged_upsampler+0x820> */
/* @0x2b77e4 mov r12, r11 */
/* @0x2b77e8 mov r11, r10 */
/* @0x2b77ec ldr r10, [sp, #0x20] */
/* @0x2b77f0 mov r3, r1 */
/* @0x2b77f4 cmp r10, #0 */
/* @0x2b77f8 beq 0x2b7820 <jinit_merged_upsampler+0x884> */
/* @0x2b77fc ldr r1, [r12, r4, lsl #2] */
/* @0x2b7800 add r6, sp, #328 */
/* @0x2b7804 ldr r5, [sp, #0x24] */
/* @0x2b7808 lsl r0, r1, #1 */
/* @0x2b780c add r12, r6, r5, lsl #2 */
/* @0x2b7810 add r5, r5, #1 */
/* @0x2b7814 strh r10, [r7, r0] */
/* @0x2b7818 str r1, [r12, #-0x100] */
/* @0x2b781c str r5, [sp, #0x24] */
/* @0x2b7820 add r4, r4, #1 */
/* @0x2b7824 cmp r9, r4 */
/* @0x2b7828 bge 0x2b76c0 <jinit_merged_upsampler+0x724> */
/* @0x2b782c ldr r12, [sp, #0x14] */
/* @0x2b7830 ldr r5, [sp, #0x34] */
/* @0x2b7834 ldr r6, [sp, #0x38] */
/* @0x2b7838 ldr r0, [r12, #0x18] */
/* @0x2b783c stm r0, {r5, r6} */
/* @0x2b7840 ldr r12, [sp, #0x18] */
/* @0x2b7844 ldr r5, [sp, #0x2c] */
/* @0x2b7848 str r3, [r12, #0xc] */
/* @0x2b784c str r2, [r12, #0x10] */
/* @0x2b7850 str r5, [r12, #0x14] */
/* @0x2b7854 ldr r6, [sp, #0x18] */
/* @0x2b7858 mov r0, #1 */
/* @0x2b785c ldr r3, [r6, #0x28] */
/* @0x2b7860 sub r3, r3, #1 */
/* @0x2b7864 str r3, [r6, #0x28] */
/* @0x2b7868 add sp, sp, #332 */
/* @0x2b786c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7870 str r12, [sp, #0x24] */
/* @0x2b7874 cmp r9, r4 */
/* @0x2b7878 blt 0x2b7a70 <jinit_merged_upsampler+0xad4> */
/* @0x2b787c ldr r1, [pc, #0x234] */
/* @0x2b7880 add r8, sp, #52 */
/* @0x2b7884 ldr r1, [pc, r1] */
/* @0x2b7888 add r1, r1, r4, lsl #2 */
/* @0x2b788c sub r6, r1, #4 */
/* @0x2b7890 mov r1, r3 */
/* @0x2b7894 b 0x2b78dc <jinit_merged_upsampler+0x940> */
/* @0x2b7898 sub r2, r2, #1 */
/* @0x2b789c asr r0, r1, r2 */
/* @0x2b78a0 tst r0, #1 */
/* @0x2b78a4 beq 0x2b78d0 <jinit_merged_upsampler+0x934> */
/* @0x2b78a8 ldrh r0, [r7, r5] */
/* @0x2b78ac sxth r3, r0 */
/* @0x2b78b0 tst r3, r11 */
/* @0x2b78b4 bne 0x2b78d0 <jinit_merged_upsampler+0x934> */
/* @0x2b78b8 cmp r3, #0 */
/* @0x2b78bc add r3, r0, r11 */
/* @0x2b78c0 strhge r3, [r7, r5] */
/* @0x2b78c4 ldrlt r12, [sp, #0x28] */
/* @0x2b78c8 addlt r0, r0, r12 */
/* @0x2b78cc strhlt r0, [r7, r5] */
/* @0x2b78d0 add r4, r4, #1 */
/* @0x2b78d4 cmp r9, r4 */
/* @0x2b78d8 blt 0x2b7a6c <jinit_merged_upsampler+0xad0> */
/* @0x2b78dc ldr r5, [r6, #0x4]! */
/* @0x2b78e0 lsl r5, r5, #1 */
/* @0x2b78e4 ldrsh r12, [r7, r5] */
/* @0x2b78e8 cmp r12, #0 */
/* @0x2b78ec beq 0x2b78d0 <jinit_merged_upsampler+0x934> */
/* @0x2b78f0 cmp r2, #0 */
/* @0x2b78f4 bgt 0x2b7898 <jinit_merged_upsampler+0x8fc> */
/* @0x2b78f8 mov r0, r8 */
/* @0x2b78fc mov r3, #1 */
/* @0x2b7900 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7904 cmp r0, #0 */
/* @0x2b7908 beq 0x2b7a18 <jinit_merged_upsampler+0xa7c> */
/* @0x2b790c ldr r1, [sp, #0x3c] */
/* @0x2b7910 ldr r2, [sp, #0x40] */
/* @0x2b7914 b 0x2b7898 <jinit_merged_upsampler+0x8fc> */
/* @0x2b7918 add r0, sp, #52 */
/* @0x2b791c mov r3, #1 */
/* @0x2b7920 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7924 cmp r0, #0 */
/* @0x2b7928 beq 0x2b7a18 <jinit_merged_upsampler+0xa7c> */
/* @0x2b792c ldr r1, [sp, #0x3c] */
/* @0x2b7930 ldr r2, [sp, #0x40] */
/* @0x2b7934 b 0x2b7788 <jinit_merged_upsampler+0x7ec> */
/* @0x2b7938 cmp r8, #15 */
/* @0x2b793c beq 0x2b7754 <jinit_merged_upsampler+0x7b8> */
/* @0x2b7940 cmp r8, #0 */
/* @0x2b7944 mov r1, #1 */
/* @0x2b7948 lsl r1, r1, r8 */
/* @0x2b794c str r1, [sp, #0x2c] */
/* @0x2b7950 beq 0x2b7974 <jinit_merged_upsampler+0x9d8> */
/* @0x2b7954 cmp r8, r2 */
/* @0x2b7958 bgt 0x2b7a90 <jinit_merged_upsampler+0xaf4> */
/* @0x2b795c ldr r5, [sp, #0x2c] */
/* @0x2b7960 rsb r2, r8, r2 */
/* @0x2b7964 sub r1, r5, #1 */
/* @0x2b7968 and r1, r1, r3, asr r2 */
/* @0x2b796c add r5, r5, r1 */
/* @0x2b7970 str r5, [sp, #0x2c] */
/* @0x2b7974 ldr r5, [sp, #0x2c] */
/* @0x2b7978 cmp r5, #0 */
/* @0x2b797c bne 0x2b7874 <jinit_merged_upsampler+0x8d8> */
/* @0x2b7980 ldr r6, [sp, #0x14] */
/* @0x2b7984 ldr r5, [sp, #0x34] */
/* @0x2b7988 ldr r0, [r6, #0x18] */
/* @0x2b798c ldr r6, [sp, #0x38] */
/* @0x2b7990 b 0x2b783c <jinit_merged_upsampler+0x8a0> */
/* @0x2b7994 add r5, sp, #52 */
/* @0x2b7998 mov r1, #9 */
/* @0x2b799c str r1, [sp] */
/* @0x2b79a0 mov r0, r5 */
/* @0x2b79a4 mov r1, r3 */
/* @0x2b79a8 ldr r3, [sp, #0x1c] */
/* @0x2b79ac bl 0x2beb8c <jpeg_huff_decode> */
/* @0x2b79b0 cmp r0, #0 */
/* @0x2b79b4 blt 0x2b7a18 <jinit_merged_upsampler+0xa7c> */
/* @0x2b79b8 ldr r3, [sp, #0x3c] */
/* @0x2b79bc ldr r2, [sp, #0x40] */
/* @0x2b79c0 b 0x2b76f4 <jinit_merged_upsampler+0x758> */
/* @0x2b79c4 add r5, sp, #52 */
/* @0x2b79c8 mov r1, r3 */
/* @0x2b79cc mov r3, #0 */
/* @0x2b79d0 mov r0, r5 */
/* @0x2b79d4 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b79d8 cmp r0, #0 */
/* @0x2b79dc beq 0x2b7a18 <jinit_merged_upsampler+0xa7c> */
/* @0x2b79e0 ldr r2, [sp, #0x40] */
/* @0x2b79e4 ldr r3, [sp, #0x3c] */
/* @0x2b79e8 cmp r2, #7 */
/* @0x2b79ec bgt 0x2b76c8 <jinit_merged_upsampler+0x72c> */
/* @0x2b79f0 mov r1, #1 */
/* @0x2b79f4 b 0x2b799c <jinit_merged_upsampler+0xa00> */
/* @0x2b79f8 mov r1, r3 */
/* @0x2b79fc add r0, sp, #52 */
/* @0x2b7a00 mov r3, #1 */
/* @0x2b7a04 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7a08 cmp r0, #0 */
/* @0x2b7a0c ldrne r3, [sp, #0x3c] */
/* @0x2b7a10 ldrne r2, [sp, #0x40] */
/* @0x2b7a14 bne 0x2b7740 <jinit_merged_upsampler+0x7a4> */
/* @0x2b7a18 ldr r12, [sp, #0x24] */
/* @0x2b7a1c cmp r12, #0 */
/* @0x2b7a20 beq 0x2b7a48 <jinit_merged_upsampler+0xaac> */
/* @0x2b7a24 ldr r12, [sp, #0x24] */
/* @0x2b7a28 add r1, sp, #72 */
/* @0x2b7a2c mov r0, #0 */
/* @0x2b7a30 add r3, r1, r12, lsl #2 */
/* @0x2b7a34 ldr r2, [r3, #-0x4]! */
/* @0x2b7a38 cmp r3, r1 */
/* @0x2b7a3c lsl r2, r2, #1 */
/* @0x2b7a40 strh r0, [r7, r2] */
/* @0x2b7a44 bne 0x2b7a34 <jinit_merged_upsampler+0xa98> */
/* @0x2b7a48 mov r0, #0 */
/* @0x2b7a4c add sp, sp, #332 */
/* @0x2b7a50 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7a54 str r1, [sp, #0xc] */
/* @0x2b7a58 bl 0x2b7148 <jinit_merged_upsampler+0x1ac> */
/* @0x2b7a5c ldr r1, [sp, #0xc] */
/* @0x2b7a60 cmp r0, #0 */
/* @0x2b7a64 bne 0x2b763c <jinit_merged_upsampler+0x6a0> */
/* @0x2b7a68 b 0x2b7a48 <jinit_merged_upsampler+0xaac> */
/* @0x2b7a6c mov r3, r1 */
/* @0x2b7a70 ldr r5, [sp, #0x14] */
/* @0x2b7a74 ldr r6, [sp, #0x2c] */
/* @0x2b7a78 ldr r0, [r5, #0x18] */
/* @0x2b7a7c sub r6, r6, #1 */
/* @0x2b7a80 ldr r5, [sp, #0x34] */
/* @0x2b7a84 str r6, [sp, #0x2c] */
/* @0x2b7a88 ldr r6, [sp, #0x38] */
/* @0x2b7a8c b 0x2b783c <jinit_merged_upsampler+0x8a0> */
/* @0x2b7a90 mov r1, r3 */
/* @0x2b7a94 add r0, sp, #52 */
/* @0x2b7a98 mov r3, r8 */
/* @0x2b7a9c bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7aa0 cmp r0, #0 */
/* @0x2b7aa4 beq 0x2b7a18 <jinit_merged_upsampler+0xa7c> */
/* @0x2b7aa8 ldr r3, [sp, #0x3c] */
/* @0x2b7aac ldr r2, [sp, #0x40] */
/* @0x2b7ab0 b 0x2b795c <jinit_merged_upsampler+0x9c0> */
/* @0x2b7ab4 andseq r10, r3, r4, asr #6 */
/* @0x2b7ab8 andseq r10, r3, r4, lsr #4 */
/* @0x2b7abc ldr r3, [r0, #0xfc] */
/* @0x2b7ac0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b7ac4 cmp r3, #0 */
/* @0x2b7ac8 sub sp, sp, #52 */
/* @0x2b7acc mov r8, r0 */
/* @0x2b7ad0 ldr r7, [r0, #0x198] */
/* @0x2b7ad4 ldr r9, [r0, #0x170] */
/* @0x2b7ad8 ldr r11, [r0, #0x178] */
/* @0x2b7adc beq 0x2b7aec <jinit_merged_upsampler+0xb50> */
/* @0x2b7ae0 ldr r3, [r7, #0x28] */
/* @0x2b7ae4 cmp r3, #0 */
/* @0x2b7ae8 beq 0x2b7cec <jinit_merged_upsampler+0xd50> */
/* @0x2b7aec ldrb r3, [r7, #0x8] */
/* @0x2b7af0 cmp r3, #0 */
/* @0x2b7af4 bne 0x2b7c58 <jinit_merged_upsampler+0xcbc> */
/* @0x2b7af8 ldr r3, [r7, #0x14] */
/* @0x2b7afc cmp r3, #0 */
/* @0x2b7b00 str r3, [sp, #0x10] */
/* @0x2b7b04 subne r3, r3, #1 */
/* @0x2b7b08 strne r3, [sp, #0x10] */
/* @0x2b7b0c bne 0x2b7c50 <jinit_merged_upsampler+0xcb4> */
/* @0x2b7b10 ldr r3, [r8, #0x18] */
/* @0x2b7b14 ldr r5, [r8, #0x16c] */
/* @0x2b7b18 ldr r4, [r1] */
/* @0x2b7b1c ldr r0, [r3] */
/* @0x2b7b20 cmp r9, r5 */
/* @0x2b7b24 ldr r12, [r3, #0x4] */
/* @0x2b7b28 str r8, [sp, #0x2c] */
/* @0x2b7b2c str r0, [sp, #0x1c] */
/* @0x2b7b30 str r12, [sp, #0x20] */
/* @0x2b7b34 ldr r1, [r7, #0xc] */
/* @0x2b7b38 ldr r2, [r7, #0x10] */
/* @0x2b7b3c ldr r6, [r7, #0x3c] */
/* @0x2b7b40 blt 0x2b7c44 <jinit_merged_upsampler+0xca8> */
/* @0x2b7b44 ldr r10, [pc, #0x1fc] */
/* @0x2b7b48 str r7, [sp, #0x14] */
/* @0x2b7b4c mov r7, r5 */
/* @0x2b7b50 add r10, pc, r10 */
/* @0x2b7b54 mov r5, r4 */
/* @0x2b7b58 b 0x2b7bb4 <jinit_merged_upsampler+0xc18> */
/* @0x2b7b5c cmp r2, r4 */
/* @0x2b7b60 add r7, r7, r0 */
/* @0x2b7b64 blt 0x2b7ccc <jinit_merged_upsampler+0xd30> */
/* @0x2b7b68 mov r3, #1 */
/* @0x2b7b6c rsb r2, r4, r2 */
/* @0x2b7b70 lsl r0, r3, r4 */
/* @0x2b7b74 ldr r3, [r10, r4, lsl #2] */
/* @0x2b7b78 sub r0, r0, #1 */
/* @0x2b7b7c and r0, r0, r1, asr r2 */
/* @0x2b7b80 cmp r0, r3 */
/* @0x2b7b84 addlt r4, r10, r4, lsl #2 */
/* @0x2b7b88 ldrlt r3, [r4, #0x40] */
/* @0x2b7b8c addlt r0, r0, r3 */
/* @0x2b7b90 ldr r3, [pc, #0x1b4] */
/* @0x2b7b94 ldr r3, [pc, r3] */
/* @0x2b7b98 lsl r0, r0, r11 */
/* @0x2b7b9c ldr r3, [r3, r7, lsl #2] */
/* @0x2b7ba0 lsl r3, r3, #1 */
/* @0x2b7ba4 strh r0, [r5, r3] */
/* @0x2b7ba8 add r7, r7, #1 */
/* @0x2b7bac cmp r9, r7 */
/* @0x2b7bb0 blt 0x2b7d0c <jinit_merged_upsampler+0xd70> */
/* @0x2b7bb4 cmp r2, #7 */
/* @0x2b7bb8 ble 0x2b7c9c <jinit_merged_upsampler+0xd00> */
/* @0x2b7bbc sub r0, r2, #8 */
/* @0x2b7bc0 asr r0, r1, r0 */
/* @0x2b7bc4 uxtb r0, r0 */
/* @0x2b7bc8 add r3, r0, #36 */
/* @0x2b7bcc ldr r3, [r6, r3, lsl #2] */
/* @0x2b7bd0 cmp r3, #0 */
/* @0x2b7bd4 beq 0x2b7c70 <jinit_merged_upsampler+0xcd4> */
/* @0x2b7bd8 add r0, r6, r0 */
/* @0x2b7bdc rsb r2, r3, r2 */
/* @0x2b7be0 ldrb r0, [r0, #0x490] */
/* @0x2b7be4 ands r4, r0, #15 */
/* @0x2b7be8 asr r0, r0, #4 */
/* @0x2b7bec bne 0x2b7b5c <jinit_merged_upsampler+0xbc0> */
/* @0x2b7bf0 cmp r0, #15 */
/* @0x2b7bf4 addeq r7, r7, #15 */
/* @0x2b7bf8 beq 0x2b7ba8 <jinit_merged_upsampler+0xc0c> */
/* @0x2b7bfc mov r4, #1 */
/* @0x2b7c00 cmp r0, #0 */
/* @0x2b7c04 lsl r4, r4, r0 */
/* @0x2b7c08 ldr r7, [sp, #0x14] */
/* @0x2b7c0c mov r12, r0 */
/* @0x2b7c10 mov r3, r4 */
/* @0x2b7c14 beq 0x2b7c30 <jinit_merged_upsampler+0xc94> */
/* @0x2b7c18 cmp r0, r2 */
/* @0x2b7c1c bgt 0x2b7d20 <jinit_merged_upsampler+0xd84> */
/* @0x2b7c20 rsb r2, r12, r2 */
/* @0x2b7c24 sub r3, r4, #1 */
/* @0x2b7c28 and r3, r3, r1, asr r2 */
/* @0x2b7c2c add r3, r4, r3 */
/* @0x2b7c30 sub r3, r3, #1 */
/* @0x2b7c34 ldr r0, [sp, #0x1c] */
/* @0x2b7c38 str r3, [sp, #0x10] */
/* @0x2b7c3c ldr r12, [sp, #0x20] */
/* @0x2b7c40 ldr r3, [r8, #0x18] */
/* @0x2b7c44 stm r3, {r0, r12} */
/* @0x2b7c48 str r1, [r7, #0xc] */
/* @0x2b7c4c str r2, [r7, #0x10] */
/* @0x2b7c50 ldr r3, [sp, #0x10] */
/* @0x2b7c54 str r3, [r7, #0x14] */
/* @0x2b7c58 ldr r3, [r7, #0x28] */
/* @0x2b7c5c mov r0, #1 */
/* @0x2b7c60 sub r3, r3, #1 */
/* @0x2b7c64 str r3, [r7, #0x28] */
/* @0x2b7c68 add sp, sp, #52 */
/* @0x2b7c6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7c70 add r4, sp, #28 */
/* @0x2b7c74 mov r3, #9 */
/* @0x2b7c78 str r3, [sp] */
/* @0x2b7c7c mov r0, r4 */
/* @0x2b7c80 mov r3, r6 */
/* @0x2b7c84 bl 0x2beb8c <jpeg_huff_decode> */
/* @0x2b7c88 cmp r0, #0 */
/* @0x2b7c8c blt 0x2b7d00 <jinit_merged_upsampler+0xd64> */
/* @0x2b7c90 ldr r1, [sp, #0x24] */
/* @0x2b7c94 ldr r2, [sp, #0x28] */
/* @0x2b7c98 b 0x2b7be4 <jinit_merged_upsampler+0xc48> */
/* @0x2b7c9c add r4, sp, #28 */
/* @0x2b7ca0 mov r3, #0 */
/* @0x2b7ca4 mov r0, r4 */
/* @0x2b7ca8 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7cac cmp r0, #0 */
/* @0x2b7cb0 beq 0x2b7d00 <jinit_merged_upsampler+0xd64> */
/* @0x2b7cb4 ldr r2, [sp, #0x28] */
/* @0x2b7cb8 ldr r1, [sp, #0x24] */
/* @0x2b7cbc cmp r2, #7 */
/* @0x2b7cc0 bgt 0x2b7bbc <jinit_merged_upsampler+0xc20> */
/* @0x2b7cc4 mov r3, #1 */
/* @0x2b7cc8 b 0x2b7c78 <jinit_merged_upsampler+0xcdc> */
/* @0x2b7ccc add r0, sp, #28 */
/* @0x2b7cd0 mov r3, r4 */
/* @0x2b7cd4 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7cd8 cmp r0, #0 */
/* @0x2b7cdc beq 0x2b7d00 <jinit_merged_upsampler+0xd64> */
/* @0x2b7ce0 ldr r1, [sp, #0x24] */
/* @0x2b7ce4 ldr r2, [sp, #0x28] */
/* @0x2b7ce8 b 0x2b7b68 <jinit_merged_upsampler+0xbcc> */
/* @0x2b7cec str r1, [sp, #0xc] */
/* @0x2b7cf0 bl 0x2b7148 <jinit_merged_upsampler+0x1ac> */
/* @0x2b7cf4 ldr r1, [sp, #0xc] */
/* @0x2b7cf8 cmp r0, #0 */
/* @0x2b7cfc bne 0x2b7aec <jinit_merged_upsampler+0xb50> */
/* @0x2b7d00 mov r0, #0 */
/* @0x2b7d04 add sp, sp, #52 */
/* @0x2b7d08 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7d0c ldr r7, [sp, #0x14] */
/* @0x2b7d10 ldr r3, [r8, #0x18] */
/* @0x2b7d14 ldr r0, [sp, #0x1c] */
/* @0x2b7d18 ldr r12, [sp, #0x20] */
/* @0x2b7d1c b 0x2b7c44 <jinit_merged_upsampler+0xca8> */
/* @0x2b7d20 mov r3, r12 */
/* @0x2b7d24 add r0, sp, #28 */
/* @0x2b7d28 str r12, [sp, #0xc] */
/* @0x2b7d2c bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7d30 ldr r12, [sp, #0xc] */
/* @0x2b7d34 cmp r0, #0 */
/* @0x2b7d38 beq 0x2b7d00 <jinit_merged_upsampler+0xd64> */
/* @0x2b7d3c ldr r1, [sp, #0x24] */
/* @0x2b7d40 ldr r2, [sp, #0x28] */
/* @0x2b7d44 b 0x2b7c20 <jinit_merged_upsampler+0xc84> */
/* @0x2b7d48 strdeq r8, r9, [sp], -r0 */
/* @0x2b7d4c andseq r9, r3, r4, lsl pc */
/* @0x2b7d50 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b7d54 sub sp, sp, #76 */
/* @0x2b7d58 ldr r5, [r0, #0x198] */
/* @0x2b7d5c mov r9, r0 */
/* @0x2b7d60 ldr r3, [r0, #0xfc] */
/* @0x2b7d64 mov r6, r1 */
/* @0x2b7d68 str r5, [sp, #0x10] */
/* @0x2b7d6c cmp r3, #0 */
/* @0x2b7d70 ldr r5, [r0, #0x178] */
/* @0x2b7d74 str r5, [sp, #0x14] */
/* @0x2b7d78 beq 0x2b7d8c <jinit_merged_upsampler+0xdf0> */
/* @0x2b7d7c ldr r5, [sp, #0x10] */
/* @0x2b7d80 ldr r3, [r5, #0x28] */
/* @0x2b7d84 cmp r3, #0 */
/* @0x2b7d88 beq 0x2b7fb8 <jinit_merged_upsampler+0x101c> */
/* @0x2b7d8c ldr r5, [sp, #0x10] */
/* @0x2b7d90 ldrb r7, [r5, #0x8] */
/* @0x2b7d94 cmp r7, #0 */
/* @0x2b7d98 bne 0x2b7f44 <jinit_merged_upsampler+0xfa8> */
/* @0x2b7d9c ldr r5, [sp, #0x10] */
/* @0x2b7da0 ldr r8, [r9, #0x140] */
/* @0x2b7da4 add r5, r5, #20 */
/* @0x2b7da8 str r5, [sp, #0x18] */
/* @0x2b7dac ldr r4, [sp, #0x18] */
/* @0x2b7db0 add r5, sp, #52 */
/* @0x2b7db4 str r5, [sp, #0x1c] */
/* @0x2b7db8 cmp r8, #0 */
/* @0x2b7dbc mov r12, r5 */
/* @0x2b7dc0 ldr r5, [r9, #0x18] */
/* @0x2b7dc4 ldm r4!, {r0, r1, r2, r3} */
/* @0x2b7dc8 ldr r8, [r5] */
/* @0x2b7dcc str r9, [sp, #0x30] */
/* @0x2b7dd0 stm r12!, {r0, r1, r2, r3} */
/* @0x2b7dd4 ldr r4, [r4] */
/* @0x2b7dd8 ldr r0, [sp, #0x10] */
/* @0x2b7ddc ldr r3, [r5, #0x4] */
/* @0x2b7de0 str r4, [r12] */
/* @0x2b7de4 str r8, [sp, #0x20] */
/* @0x2b7de8 str r3, [sp, #0x24] */
/* @0x2b7dec ldr r4, [r0, #0xc] */
/* @0x2b7df0 ldr r12, [r0, #0x10] */
/* @0x2b7df4 ble 0x2b7fd0 <jinit_merged_upsampler+0x1034> */
/* @0x2b7df8 ldr r8, [pc, #0x1d8] */
/* @0x2b7dfc mov r1, r4 */
/* @0x2b7e00 sub r11, r6, #4 */
/* @0x2b7e04 mov r5, r9 */
/* @0x2b7e08 add r8, pc, r8 */
/* @0x2b7e0c mov r2, r12 */
/* @0x2b7e10 mov r4, r8 */
/* @0x2b7e14 b 0x2b7e94 <jinit_merged_upsampler+0xef8> */
/* @0x2b7e18 add r8, r8, r0 */
/* @0x2b7e1c rsb r2, r3, r2 */
/* @0x2b7e20 ldrb r8, [r8, #0x490] */
/* @0x2b7e24 cmp r8, #0 */
/* @0x2b7e28 beq 0x2b7e60 <jinit_merged_upsampler+0xec4> */
/* @0x2b7e2c cmp r8, r2 */
/* @0x2b7e30 bgt 0x2b7f98 <jinit_merged_upsampler+0xffc> */
/* @0x2b7e34 mov r0, #1 */
/* @0x2b7e38 rsb r2, r8, r2 */
/* @0x2b7e3c lsl r3, r0, r8 */
/* @0x2b7e40 ldr r0, [r4, r8, lsl #2] */
/* @0x2b7e44 sub r3, r3, #1 */
/* @0x2b7e48 and r3, r3, r1, asr r2 */
/* @0x2b7e4c cmp r3, r0 */
/* @0x2b7e50 addlt r8, r4, r8, lsl #2 */
/* @0x2b7e54 movge r8, r3 */
/* @0x2b7e58 ldrlt r8, [r8, #0x40] */
/* @0x2b7e5c addlt r8, r8, r3 */
/* @0x2b7e60 add r3, sp, #72 */
/* @0x2b7e64 ldr r0, [r9, #0x140] */
/* @0x2b7e68 add r6, r3, r6, lsl #2 */
/* @0x2b7e6c add r7, r7, #1 */
/* @0x2b7e70 cmp r0, r7 */
/* @0x2b7e74 ldr r0, [sp, #0x14] */
/* @0x2b7e78 ldr r3, [r6, #-0x10] */
/* @0x2b7e7c add r5, r5, #4 */
/* @0x2b7e80 add r8, r8, r3 */
/* @0x2b7e84 str r8, [r6, #-0x10] */
/* @0x2b7e88 lsl r8, r8, r0 */
/* @0x2b7e8c strh r8, [r10] */
/* @0x2b7e90 ble 0x2b7f04 <jinit_merged_upsampler+0xf68> */
/* @0x2b7e94 ldr r6, [r5, #0x144] */
/* @0x2b7e98 cmp r2, #7 */
/* @0x2b7e9c ldr r0, [sp, #0x10] */
/* @0x2b7ea0 add r3, r6, #74 */
/* @0x2b7ea4 ldr r10, [r11, #0x4]! */
/* @0x2b7ea8 ldr r3, [r9, r3, lsl #2] */
/* @0x2b7eac ldr r3, [r3, #0x14] */
/* @0x2b7eb0 add r3, r0, r3, lsl #2 */
/* @0x2b7eb4 ldr r8, [r3, #0x2c] */
/* @0x2b7eb8 ble 0x2b7f60 <jinit_merged_upsampler+0xfc4> */
/* @0x2b7ebc sub r0, r2, #8 */
/* @0x2b7ec0 asr r0, r1, r0 */
/* @0x2b7ec4 uxtb r0, r0 */
/* @0x2b7ec8 add r3, r0, #36 */
/* @0x2b7ecc ldr r3, [r8, r3, lsl #2] */
/* @0x2b7ed0 cmp r3, #0 */
/* @0x2b7ed4 bne 0x2b7e18 <jinit_merged_upsampler+0xe7c> */
/* @0x2b7ed8 add r12, sp, #32 */
/* @0x2b7edc mov r3, #9 */
/* @0x2b7ee0 str r3, [sp] */
/* @0x2b7ee4 mov r0, r12 */
/* @0x2b7ee8 mov r3, r8 */
/* @0x2b7eec bl 0x2beb8c <jpeg_huff_decode> */
/* @0x2b7ef0 subs r8, r0, #0 */
/* @0x2b7ef4 blt 0x2b7fc4 <jinit_merged_upsampler+0x1028> */
/* @0x2b7ef8 ldr r1, [sp, #0x28] */
/* @0x2b7efc ldr r2, [sp, #0x2c] */
/* @0x2b7f00 b 0x2b7e24 <jinit_merged_upsampler+0xe88> */
/* @0x2b7f04 ldr r5, [r9, #0x18] */
/* @0x2b7f08 mov r4, r1 */
/* @0x2b7f0c ldr r8, [sp, #0x20] */
/* @0x2b7f10 mov r12, r2 */
/* @0x2b7f14 ldr r7, [sp, #0x24] */
/* @0x2b7f18 add r9, sp, #52 */
/* @0x2b7f1c str r8, [r5] */
/* @0x2b7f20 str r7, [r5, #0x4] */
/* @0x2b7f24 ldm r9!, {r0, r1, r2, r3} */
/* @0x2b7f28 ldr r5, [sp, #0x10] */
/* @0x2b7f2c ldr r6, [sp, #0x18] */
/* @0x2b7f30 str r4, [r5, #0xc] */
/* @0x2b7f34 ldr r4, [r9] */
/* @0x2b7f38 str r12, [r5, #0x10] */
/* @0x2b7f3c stm r6!, {r0, r1, r2, r3} */
/* @0x2b7f40 str r4, [r6] */
/* @0x2b7f44 ldr r5, [sp, #0x10] */
/* @0x2b7f48 mov r0, #1 */
/* @0x2b7f4c ldr r3, [r5, #0x28] */
/* @0x2b7f50 sub r3, r3, #1 */
/* @0x2b7f54 str r3, [r5, #0x28] */
/* @0x2b7f58 add sp, sp, #76 */
/* @0x2b7f5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7f60 add r12, sp, #32 */
/* @0x2b7f64 mov r3, #0 */
/* @0x2b7f68 str r12, [sp, #0xc] */
/* @0x2b7f6c mov r0, r12 */
/* @0x2b7f70 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7f74 ldr r12, [sp, #0xc] */
/* @0x2b7f78 cmp r0, #0 */
/* @0x2b7f7c beq 0x2b7fc4 <jinit_merged_upsampler+0x1028> */
/* @0x2b7f80 ldr r2, [sp, #0x2c] */
/* @0x2b7f84 ldr r1, [sp, #0x28] */
/* @0x2b7f88 cmp r2, #7 */
/* @0x2b7f8c bgt 0x2b7ebc <jinit_merged_upsampler+0xf20> */
/* @0x2b7f90 mov r3, #1 */
/* @0x2b7f94 b 0x2b7ee0 <jinit_merged_upsampler+0xf44> */
/* @0x2b7f98 add r0, sp, #32 */
/* @0x2b7f9c mov r3, r8 */
/* @0x2b7fa0 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7fa4 cmp r0, #0 */
/* @0x2b7fa8 beq 0x2b7fc4 <jinit_merged_upsampler+0x1028> */
/* @0x2b7fac ldr r1, [sp, #0x28] */
/* @0x2b7fb0 ldr r2, [sp, #0x2c] */
/* @0x2b7fb4 b 0x2b7e34 <jinit_merged_upsampler+0xe98> */
/* @0x2b7fb8 bl 0x2b7148 <jinit_merged_upsampler+0x1ac> */
/* @0x2b7fbc cmp r0, #0 */
/* @0x2b7fc0 bne 0x2b7d8c <jinit_merged_upsampler+0xdf0> */
/* @0x2b7fc4 mov r0, #0 */
/* @0x2b7fc8 add sp, sp, #76 */
/* @0x2b7fcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7fd0 mov r7, r3 */
/* @0x2b7fd4 b 0x2b7f18 <jinit_merged_upsampler+0xf7c> */
/* @0x2b7fd8 andeq r8, sp, r8, lsr r0 */

/* ── FUNC 0x2b7fdc · jinit_phuff_decoder · size=168 · insn=42 */
/* @0x2b7fdc push {r3, r4, r5, lr} */
/* @0x2b7fe0 mov r1, #1 */
/* @0x2b7fe4 ldr r3, [r0, #0x4] */
/* @0x2b7fe8 mov r2, #64 */
/* @0x2b7fec mov r5, r0 */
/* @0x2b7ff0 mov r4, #0 */
/* @0x2b7ff4 ldr r3, [r3] */
/* @0x2b7ff8 blx r3 */
/* @0x2b7ffc ldr r12, [r5, #0x4] */
/* @0x2b8000 ldr r2, [r5, #0x24] */
/* @0x2b8004 mov r1, #1 */
/* @0x2b8008 ldr lr, [pc, #0x70] */
/* @0x2b800c ldr r12, [r12] */
/* @0x2b8010 add lr, pc, lr */
/* @0x2b8014 lsl r2, r2, #8 */
/* @0x2b8018 mov r3, r0 */
/* @0x2b801c mov r0, r5 */
/* @0x2b8020 str r3, [r5, #0x198] */
/* @0x2b8024 str lr, [r3] */
/* @0x2b8028 str r4, [r3, #0x2c] */
/* @0x2b802c str r4, [r3, #0x30] */
/* @0x2b8030 str r4, [r3, #0x34] */
/* @0x2b8034 str r4, [r3, #0x38] */
/* @0x2b8038 blx r12 */
/* @0x2b803c ldr r2, [r5, #0x24] */
/* @0x2b8040 cmp r2, r4 */
/* @0x2b8044 mov r3, r0 */
/* @0x2b8048 str r0, [r5, #0x8c] */
/* @0x2b804c pople {r3, r4, r5, pc} */
/* @0x2b8050 mov r12, r4 */
/* @0x2b8054 mvn r1, #0 */
/* @0x2b8058 add r2, r3, #256 */
/* @0x2b805c str r1, [r3], #4 */
/* @0x2b8060 cmp r2, r3 */
/* @0x2b8064 bne 0x2b805c <jinit_phuff_decoder+0x80> */
/* @0x2b8068 ldr r4, [r5, #0x24] */
/* @0x2b806c add r12, r12, #1 */
/* @0x2b8070 mov r3, r2 */
/* @0x2b8074 cmp r4, r12 */
/* @0x2b8078 bgt 0x2b8058 <jinit_phuff_decoder+0x7c> */
/* @0x2b807c pop {r3, r4, r5, pc} */
/* @0x2b8080 .word 0xfffff1c0 */

/* ── FUNC 0x2b8084 · anon_2b8084 · size=900 · insn=226 */
/* @0x2b8084 cmp r1, #2 */
/* @0x2b8088 push {r4, lr} */
/* @0x2b808c sub sp, sp, #8 */
/* @0x2b8090 ldr r4, [r0, #0x18c] */
/* @0x2b8094 beq 0x2b8134 <jinit_phuff_decoder+0x158> */
/* @0x2b8098 cmp r1, #3 */
/* @0x2b809c beq 0x2b8118 <jinit_phuff_decoder+0x13c> */
/* @0x2b80a0 cmp r1, #0 */
/* @0x2b80a4 beq 0x2b80d0 <jinit_phuff_decoder+0xf4> */
/* @0x2b80a8 ldr r3, [r0] */
/* @0x2b80ac mov r1, #4 */
/* @0x2b80b0 ldr r2, [r3] */
/* @0x2b80b4 str r1, [r3, #0x14] */
/* @0x2b80b8 blx r2 */
/* @0x2b80bc mov r3, #0 */
/* @0x2b80c0 str r3, [r4, #0x18] */
/* @0x2b80c4 str r3, [r4, #0x14] */
/* @0x2b80c8 add sp, sp, #8 */
/* @0x2b80cc pop {r4, pc} */
/* @0x2b80d0 ldrb r2, [r0, #0x4a] */
/* @0x2b80d4 cmp r2, #0 */
/* @0x2b80d8 beq 0x2b8150 <jinit_phuff_decoder+0x174> */
/* @0x2b80dc ldr r2, [r4, #0xc] */
/* @0x2b80e0 ldr r1, [pc, #0xa8] */
/* @0x2b80e4 cmp r2, #0 */
/* @0x2b80e8 add r1, pc, r1 */
/* @0x2b80ec str r1, [r4, #0x4] */
/* @0x2b80f0 bne 0x2b80bc <jinit_phuff_decoder+0xe0> */
/* @0x2b80f4 ldr r12, [r0, #0x4] */
/* @0x2b80f8 mov lr, #1 */
/* @0x2b80fc ldr r1, [r4, #0x8] */
/* @0x2b8100 ldr r3, [r4, #0x10] */
/* @0x2b8104 str lr, [sp] */
/* @0x2b8108 ldr r12, [r12, #0x1c] */
/* @0x2b810c blx r12 */
/* @0x2b8110 str r0, [r4, #0xc] */
/* @0x2b8114 b 0x2b80bc <jinit_phuff_decoder+0xe0> */
/* @0x2b8118 ldr r2, [r4, #0x8] */
/* @0x2b811c cmp r2, #0 */
/* @0x2b8120 beq 0x2b8160 <jinit_phuff_decoder+0x184> */
/* @0x2b8124 ldr r3, [pc, #0x68] */
/* @0x2b8128 add r3, pc, r3 */
/* @0x2b812c str r3, [r4, #0x4] */
/* @0x2b8130 b 0x2b80bc <jinit_phuff_decoder+0xe0> */
/* @0x2b8134 ldr r2, [r4, #0x8] */
/* @0x2b8138 cmp r2, #0 */
/* @0x2b813c beq 0x2b8178 <jinit_phuff_decoder+0x19c> */
/* @0x2b8140 ldr r3, [pc, #0x50] */
/* @0x2b8144 add r3, pc, r3 */
/* @0x2b8148 str r3, [r4, #0x4] */
/* @0x2b814c b 0x2b80bc <jinit_phuff_decoder+0xe0> */
/* @0x2b8150 ldr r3, [r0, #0x1a0] */
/* @0x2b8154 ldr r3, [r3, #0x4] */
/* @0x2b8158 str r3, [r4, #0x4] */
/* @0x2b815c b 0x2b80bc <jinit_phuff_decoder+0xe0> */
/* @0x2b8160 ldr r3, [r0] */
/* @0x2b8164 mov r1, #4 */
/* @0x2b8168 ldr r2, [r3] */
/* @0x2b816c str r1, [r3, #0x14] */
/* @0x2b8170 blx r2 */
/* @0x2b8174 b 0x2b8124 <jinit_phuff_decoder+0x148> */
/* @0x2b8178 ldr r3, [r0] */
/* @0x2b817c mov r1, #4 */
/* @0x2b8180 ldr r2, [r3] */
/* @0x2b8184 str r1, [r3, #0x14] */
/* @0x2b8188 blx r2 */
/* @0x2b818c b 0x2b8140 <jinit_phuff_decoder+0x164> */
/* @0x2b8190 andeq r0, r0, r12, lsr #1 */
/* @0x2b8194 strdeq r0, r1, [r0], -r12 */
/* @0x2b8198 ldrdeq r0, r1, [r0], -r12 */
/* @0x2b819c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b81a0 sub sp, sp, #28 */
/* @0x2b81a4 ldr r6, [r0, #0x18c] */
/* @0x2b81a8 add r12, sp, #24 */
/* @0x2b81ac ldr r4, [sp, #0x44] */
/* @0x2b81b0 mov r5, r0 */
/* @0x2b81b4 ldr lr, [r0, #0x1a0] */
/* @0x2b81b8 mov r11, #0 */
/* @0x2b81bc ldr r7, [r6, #0x10] */
/* @0x2b81c0 ldr r10, [r6, #0xc] */
/* @0x2b81c4 ldr r8, [r4] */
/* @0x2b81c8 ldr r9, [sp, #0x48] */
/* @0x2b81cc str r11, [r12, #-0x4]! */
/* @0x2b81d0 rsb r8, r8, r9 */
/* @0x2b81d4 str r10, [sp] */
/* @0x2b81d8 cmp r8, r7 */
/* @0x2b81dc strls r8, [sp, #0x8] */
/* @0x2b81e0 strhi r7, [sp, #0x8] */
/* @0x2b81e4 str r12, [sp, #0x4] */
/* @0x2b81e8 ldr r12, [lr, #0x4] */
/* @0x2b81ec ldr r7, [sp, #0x40] */
/* @0x2b81f0 blx r12 */
/* @0x2b81f4 ldr r2, [r4] */
/* @0x2b81f8 mov r0, r5 */
/* @0x2b81fc ldr r12, [r5, #0x1a8] */
/* @0x2b8200 ldr r3, [sp, #0x14] */
/* @0x2b8204 add r2, r7, r2, lsl #2 */
/* @0x2b8208 ldr r1, [r6, #0xc] */
/* @0x2b820c ldr r12, [r12, #0x4] */
/* @0x2b8210 blx r12 */
/* @0x2b8214 ldr r2, [r4] */
/* @0x2b8218 ldr r3, [sp, #0x14] */
/* @0x2b821c add r3, r2, r3 */
/* @0x2b8220 str r3, [r4] */
/* @0x2b8224 add sp, sp, #28 */
/* @0x2b8228 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b822c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2b8230 mov r5, r0 */
/* @0x2b8234 ldr r4, [r0, #0x18c] */
/* @0x2b8238 sub sp, sp, #20 */
/* @0x2b823c mov r9, r1 */
/* @0x2b8240 mov r8, r2 */
/* @0x2b8244 mov r7, r3 */
/* @0x2b8248 ldr r12, [r4, #0x18] */
/* @0x2b824c cmp r12, #0 */
/* @0x2b8250 beq 0x2b82bc <jinit_phuff_decoder+0x2e0> */
/* @0x2b8254 ldr r3, [r4, #0xc] */
/* @0x2b8258 mov r6, r12 */
/* @0x2b825c str r3, [sp] */
/* @0x2b8260 add r3, r4, #24 */
/* @0x2b8264 ldr r12, [r5, #0x1a0] */
/* @0x2b8268 mov r1, r9 */
/* @0x2b826c str r3, [sp, #0x4] */
/* @0x2b8270 mov r2, r8 */
/* @0x2b8274 ldr lr, [r4, #0x10] */
/* @0x2b8278 mov r3, r7 */
/* @0x2b827c mov r0, r5 */
/* @0x2b8280 str lr, [sp, #0x8] */
/* @0x2b8284 ldr r12, [r12, #0x4] */
/* @0x2b8288 blx r12 */
/* @0x2b828c ldr r3, [r4, #0x18] */
/* @0x2b8290 cmp r3, r6 */
/* @0x2b8294 bhi 0x2b82ec <jinit_phuff_decoder+0x310> */
/* @0x2b8298 ldr r2, [r4, #0x10] */
/* @0x2b829c cmp r2, r3 */
/* @0x2b82a0 ldrls r3, [r4, #0x14] */
/* @0x2b82a4 movls r1, #0 */
/* @0x2b82a8 strls r1, [r4, #0x18] */
/* @0x2b82ac addls r2, r3, r2 */
/* @0x2b82b0 strls r2, [r4, #0x14] */
/* @0x2b82b4 add sp, sp, #20 */
/* @0x2b82b8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2b82bc ldr r12, [r0, #0x4] */
/* @0x2b82c0 mov lr, #1 */
/* @0x2b82c4 ldr r3, [r4, #0x10] */
/* @0x2b82c8 ldr r1, [r4, #0x8] */
/* @0x2b82cc ldr r2, [r4, #0x14] */
/* @0x2b82d0 str lr, [sp] */
/* @0x2b82d4 ldr r12, [r12, #0x1c] */
/* @0x2b82d8 blx r12 */
/* @0x2b82dc ldr r6, [r4, #0x18] */
/* @0x2b82e0 mov r3, r0 */
/* @0x2b82e4 str r0, [r4, #0xc] */
/* @0x2b82e8 b 0x2b825c <jinit_phuff_decoder+0x280> */
/* @0x2b82ec ldr r12, [r5, #0x1a8] */
/* @0x2b82f0 rsb r7, r6, r3 */
/* @0x2b82f4 ldr r1, [r4, #0xc] */
/* @0x2b82f8 mov r2, #0 */
/* @0x2b82fc mov r3, r7 */
/* @0x2b8300 mov r0, r5 */
/* @0x2b8304 ldr r12, [r12, #0x4] */
/* @0x2b8308 add r1, r1, r6, lsl #2 */
/* @0x2b830c blx r12 */
/* @0x2b8310 ldr r2, [sp, #0x34] */
/* @0x2b8314 ldr r3, [r2] */
/* @0x2b8318 add r7, r3, r7 */
/* @0x2b831c str r7, [r2] */
/* @0x2b8320 ldr r3, [r4, #0x18] */
/* @0x2b8324 b 0x2b8298 <jinit_phuff_decoder+0x2bc> */
/* @0x2b8328 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2b832c sub sp, sp, #12 */
/* @0x2b8330 ldr r4, [r0, #0x18c] */
/* @0x2b8334 mov r5, r0 */
/* @0x2b8338 ldr r7, [sp, #0x28] */
/* @0x2b833c ldr r6, [sp, #0x2c] */
/* @0x2b8340 ldr r3, [r4, #0x18] */
/* @0x2b8344 ldr r8, [sp, #0x30] */
/* @0x2b8348 cmp r3, #0 */
/* @0x2b834c beq 0x2b83dc <jinit_phuff_decoder+0x400> */
/* @0x2b8350 ldr r1, [r4, #0xc] */
/* @0x2b8354 ldr r2, [r6] */
/* @0x2b8358 add r1, r1, r3, lsl #2 */
/* @0x2b835c ldr r9, [r5, #0x60] */
/* @0x2b8360 mov r0, r5 */
/* @0x2b8364 ldr r12, [r4, #0x14] */
/* @0x2b8368 rsb r8, r2, r8 */
/* @0x2b836c ldr lr, [r4, #0x10] */
/* @0x2b8370 add r2, r7, r2, lsl #2 */
/* @0x2b8374 rsb r7, r12, r9 */
/* @0x2b8378 ldr r12, [r5, #0x1a8] */
/* @0x2b837c rsb r3, r3, lr */
/* @0x2b8380 cmp r8, r7 */
/* @0x2b8384 movlo r5, r8 */
/* @0x2b8388 movhs r5, r7 */
/* @0x2b838c cmp r5, r3 */
/* @0x2b8390 movhs r5, r3 */
/* @0x2b8394 ldr r12, [r12, #0x4] */
/* @0x2b8398 mov r3, r5 */
/* @0x2b839c blx r12 */
/* @0x2b83a0 ldr r3, [r6] */
/* @0x2b83a4 add r3, r3, r5 */
/* @0x2b83a8 str r3, [r6] */
/* @0x2b83ac ldr r2, [r4, #0x18] */
/* @0x2b83b0 ldr r3, [r4, #0x10] */
/* @0x2b83b4 add r5, r5, r2 */
/* @0x2b83b8 str r5, [r4, #0x18] */
/* @0x2b83bc cmp r5, r3 */
/* @0x2b83c0 ldrhs r2, [r4, #0x14] */
/* @0x2b83c4 movhs r1, #0 */
/* @0x2b83c8 addhs r3, r2, r3 */
/* @0x2b83cc strhs r3, [r4, #0x14] */
/* @0x2b83d0 strhs r1, [r4, #0x18] */
/* @0x2b83d4 add sp, sp, #12 */
/* @0x2b83d8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2b83dc ldr lr, [r4, #0x10] */
/* @0x2b83e0 ldr r12, [r0, #0x4] */
/* @0x2b83e4 ldr r1, [r4, #0x8] */
/* @0x2b83e8 ldr r2, [r4, #0x14] */
/* @0x2b83ec str r3, [sp] */
/* @0x2b83f0 mov r3, lr */
/* @0x2b83f4 ldr r12, [r12, #0x1c] */
/* @0x2b83f8 blx r12 */
/* @0x2b83fc ldr r3, [r4, #0x18] */
/* @0x2b8400 mov r1, r0 */
/* @0x2b8404 str r0, [r4, #0xc] */
/* @0x2b8408 b 0x2b8354 <jinit_phuff_decoder+0x378> */

/* ── FUNC 0x2b840c · jinit_d_post_controller · size=220 · insn=55 */
/* @0x2b840c ldr r3, [r0, #0x4] */
/* @0x2b8410 mov r2, #28 */
/* @0x2b8414 push {r4, r5, r6, r7, r8, lr} */
/* @0x2b8418 mov r7, r1 */
/* @0x2b841c ldr r3, [r3] */
/* @0x2b8420 sub sp, sp, #8 */
/* @0x2b8424 mov r1, #1 */
/* @0x2b8428 mov r4, r0 */
/* @0x2b842c blx r3 */
/* @0x2b8430 ldr r3, [pc, #0xac] */
/* @0x2b8434 mov r6, #0 */
/* @0x2b8438 add r3, pc, r3 */
/* @0x2b843c str r0, [r4, #0x18c] */
/* @0x2b8440 mov r5, r0 */
/* @0x2b8444 str r6, [r0, #0x8] */
/* @0x2b8448 str r3, [r0] */
/* @0x2b844c str r6, [r0, #0xc] */
/* @0x2b8450 ldrb r3, [r4, #0x4a] */
/* @0x2b8454 cmp r3, r6 */
/* @0x2b8458 beq 0x2b8490 <jinit_d_post_controller+0x84> */
/* @0x2b845c ldr r3, [r4, #0x114] */
/* @0x2b8460 cmp r7, r6 */
/* @0x2b8464 str r3, [r0, #0x10] */
/* @0x2b8468 bne 0x2b8498 <jinit_d_post_controller+0x8c> */
/* @0x2b846c ldr r12, [r4, #0x4] */
/* @0x2b8470 mov r0, r4 */
/* @0x2b8474 ldr r2, [r4, #0x64] */
/* @0x2b8478 mov r1, #1 */
/* @0x2b847c ldr lr, [r4, #0x5c] */
/* @0x2b8480 ldr r12, [r12, #0x8] */
/* @0x2b8484 mul r2, lr, r2 */
/* @0x2b8488 blx r12 */
/* @0x2b848c str r0, [r5, #0xc] */
/* @0x2b8490 add sp, sp, #8 */
/* @0x2b8494 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2b8498 ldr r2, [r4, #0x4] */
/* @0x2b849c mov r1, r3 */
/* @0x2b84a0 ldr r8, [r4, #0x5c] */
/* @0x2b84a4 ldr r3, [r4, #0x64] */
/* @0x2b84a8 ldr r0, [r4, #0x60] */
/* @0x2b84ac ldr r7, [r2, #0x10] */
/* @0x2b84b0 mul r8, r8, r3 */
/* @0x2b84b4 bl 0x2bc800 <jround_up> */
/* @0x2b84b8 mov r2, r6 */
/* @0x2b84bc mov r1, #1 */
/* @0x2b84c0 mov r3, r8 */
/* @0x2b84c4 str r0, [sp] */
/* @0x2b84c8 mov r0, r4 */
/* @0x2b84cc ldr r12, [r5, #0x10] */
/* @0x2b84d0 str r12, [sp, #0x4] */
/* @0x2b84d4 blx r7 */
/* @0x2b84d8 str r0, [r5, #0x8] */
/* @0x2b84dc add sp, sp, #8 */
/* @0x2b84e0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2b84e4 .word 0xfffffc44 */

/* ── FUNC 0x2b84e8 · anon_2b84e8 · size=1508 · insn=378 */
/* @0x2b84e8 ldr r3, [r0, #0x1a0] */
/* @0x2b84ec ldr r1, [r0, #0x114] */
/* @0x2b84f0 ldr r2, [r0, #0x60] */
/* @0x2b84f4 str r1, [r3, #0x5c] */
/* @0x2b84f8 str r2, [r3, #0x60] */
/* @0x2b84fc bx lr */
/* @0x2b8500 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b8504 mov r5, r0 */
/* @0x2b8508 ldr r9, [r0, #0x1a0] */
/* @0x2b850c sub sp, sp, #20 */
/* @0x2b8510 ldr r4, [r0, #0x114] */
/* @0x2b8514 mov r11, r2 */
/* @0x2b8518 ldr r10, [sp, #0x3c] */
/* @0x2b851c ldr r0, [r9, #0x5c] */
/* @0x2b8520 cmp r0, r4 */
/* @0x2b8524 bge 0x2b85b8 <jinit_d_post_controller+0x1ac> */
/* @0x2b8528 mov r2, r0 */
/* @0x2b852c add r6, r9, #12 */
/* @0x2b8530 str r6, [sp, #0xc] */
/* @0x2b8534 ldr r3, [r10] */
/* @0x2b8538 rsb r0, r0, r4 */
/* @0x2b853c ldr r6, [sp, #0x40] */
/* @0x2b8540 ldr lr, [r9, #0x60] */
/* @0x2b8544 ldr r12, [r5, #0x1a4] */
/* @0x2b8548 rsb r4, r3, r6 */
/* @0x2b854c ldr r6, [sp, #0x38] */
/* @0x2b8550 cmp r4, lr */
/* @0x2b8554 movhs r4, lr */
/* @0x2b8558 cmp r4, r0 */
/* @0x2b855c movhs r4, r0 */
/* @0x2b8560 ldr r1, [sp, #0xc] */
/* @0x2b8564 str r4, [sp] */
/* @0x2b8568 add r3, r6, r3, lsl #2 */
/* @0x2b856c mov r0, r5 */
/* @0x2b8570 ldr r12, [r12, #0x4] */
/* @0x2b8574 blx r12 */
/* @0x2b8578 ldr r3, [r10] */
/* @0x2b857c add r3, r3, r4 */
/* @0x2b8580 str r3, [r10] */
/* @0x2b8584 ldr r3, [r9, #0x5c] */
/* @0x2b8588 ldr r1, [r5, #0x114] */
/* @0x2b858c add r3, r4, r3 */
/* @0x2b8590 ldr r2, [r9, #0x60] */
/* @0x2b8594 cmp r3, r1 */
/* @0x2b8598 str r3, [r9, #0x5c] */
/* @0x2b859c rsb r4, r4, r2 */
/* @0x2b85a0 str r4, [r9, #0x60] */
/* @0x2b85a4 ldrge r3, [r11] */
/* @0x2b85a8 addge r3, r3, #1 */
/* @0x2b85ac strge r3, [r11] */
/* @0x2b85b0 add sp, sp, #20 */
/* @0x2b85b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b85b8 ldr r3, [r5, #0x24] */
/* @0x2b85bc ldr r6, [r5, #0xc4] */
/* @0x2b85c0 cmp r3, #0 */
/* @0x2b85c4 ble 0x2b8630 <jinit_d_post_controller+0x224> */
/* @0x2b85c8 add lr, r9, #12 */
/* @0x2b85cc sub r8, r1, #4 */
/* @0x2b85d0 mov r7, #0 */
/* @0x2b85d4 str lr, [sp, #0xc] */
/* @0x2b85d8 mov r4, lr */
/* @0x2b85dc ldr r2, [r11] */
/* @0x2b85e0 mov r1, r6 */
/* @0x2b85e4 ldr lr, [r4, #0x58] */
/* @0x2b85e8 mov r0, r5 */
/* @0x2b85ec ldr r3, [r8, #0x4]! */
/* @0x2b85f0 add r7, r7, #1 */
/* @0x2b85f4 lsl r2, r2, #2 */
/* @0x2b85f8 ldr r12, [r4, #0x28] */
/* @0x2b85fc add r6, r6, #84 */
/* @0x2b8600 mla r2, lr, r2, r3 */
/* @0x2b8604 mov r3, r4 */
/* @0x2b8608 blx r12 */
/* @0x2b860c ldr r3, [r5, #0x24] */
/* @0x2b8610 add r4, r4, #4 */
/* @0x2b8614 cmp r3, r7 */
/* @0x2b8618 bgt 0x2b85dc <jinit_d_post_controller+0x1d0> */
/* @0x2b861c ldr r4, [r5, #0x114] */
/* @0x2b8620 mov r2, #0 */
/* @0x2b8624 str r2, [r9, #0x5c] */
/* @0x2b8628 mov r0, r2 */
/* @0x2b862c b 0x2b8534 <jinit_d_post_controller+0x128> */
/* @0x2b8630 add r6, r9, #12 */
/* @0x2b8634 str r6, [sp, #0xc] */
/* @0x2b8638 b 0x2b8620 <jinit_d_post_controller+0x214> */
/* @0x2b863c str r2, [r3] */
/* @0x2b8640 bx lr */
/* @0x2b8644 mov r2, #0 */
/* @0x2b8648 str r2, [r3] */
/* @0x2b864c bx lr */
/* @0x2b8650 ldr r1, [r0, #0x114] */
/* @0x2b8654 push {r4, r5, r6, r7} */
/* @0x2b8658 cmp r1, #0 */
/* @0x2b865c ldr r7, [r3] */
/* @0x2b8660 ble 0x2b86b0 <jinit_d_post_controller+0x2a4> */
/* @0x2b8664 mov r5, #0 */
/* @0x2b8668 mov r6, r5 */
/* @0x2b866c ldr r3, [r7, r5] */
/* @0x2b8670 ldr r4, [r0, #0x5c] */
/* @0x2b8674 ldr r12, [r2, r5] */
/* @0x2b8678 add r4, r3, r4 */
/* @0x2b867c cmp r3, r4 */
/* @0x2b8680 bhs 0x2b86a0 <jinit_d_post_controller+0x294> */
/* @0x2b8684 ldrb r1, [r12], #1 */
/* @0x2b8688 add r3, r3, #2 */
/* @0x2b868c strb r1, [r3, #-0x2] */
/* @0x2b8690 strb r1, [r3, #-0x1] */
/* @0x2b8694 cmp r4, r3 */
/* @0x2b8698 bhi 0x2b8684 <jinit_d_post_controller+0x278> */
/* @0x2b869c ldr r1, [r0, #0x114] */
/* @0x2b86a0 add r6, r6, #1 */
/* @0x2b86a4 add r5, r5, #4 */
/* @0x2b86a8 cmp r1, r6 */
/* @0x2b86ac bgt 0x2b866c <jinit_d_post_controller+0x260> */
/* @0x2b86b0 pop {r4, r5, r6, r7} */
/* @0x2b86b4 bx lr */
/* @0x2b86b8 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2b86bc sub sp, sp, #16 */
/* @0x2b86c0 ldr r3, [r3] */
/* @0x2b86c4 mov r11, r0 */
/* @0x2b86c8 str r1, [sp, #0x8] */
/* @0x2b86cc ldr r1, [r0, #0x114] */
/* @0x2b86d0 str r2, [sp, #0xc] */
/* @0x2b86d4 cmp r1, #0 */
/* @0x2b86d8 str r3, [sp, #0x4] */
/* @0x2b86dc ble 0x2b87bc <jinit_d_post_controller+0x3b0> */
/* @0x2b86e0 mov r9, #0 */
/* @0x2b86e4 mov r0, #3 */
/* @0x2b86e8 mov r10, r9 */
/* @0x2b86ec ldr r2, [sp, #0xc] */
/* @0x2b86f0 ldr r12, [r2, r9] */
/* @0x2b86f4 ldr r2, [sp, #0x4] */
/* @0x2b86f8 add r7, r12, #1 */
/* @0x2b86fc ldr r3, [r2, r9] */
/* @0x2b8700 ldrb r2, [r12] */
/* @0x2b8704 mov r6, r3 */
/* @0x2b8708 strb r2, [r6], #2 */
/* @0x2b870c ldrb r1, [r12, #0x1] */
/* @0x2b8710 smlabb r2, r0, r2, r1 */
/* @0x2b8714 add r2, r2, #2 */
/* @0x2b8718 asr r2, r2, #2 */
/* @0x2b871c strb r2, [r3, #0x1] */
/* @0x2b8720 ldr r3, [sp, #0x8] */
/* @0x2b8724 ldr r8, [r3, #0x28] */
/* @0x2b8728 subs r2, r8, #2 */
/* @0x2b872c str r2, [sp] */
/* @0x2b8730 beq 0x2b878c <jinit_d_post_controller+0x380> */
/* @0x2b8734 sub r5, r8, #1 */
/* @0x2b8738 mov r2, r7 */
/* @0x2b873c add r5, r12, r5 */
/* @0x2b8740 mov r3, r6 */
/* @0x2b8744 ldrb r1, [r12, #0x1]! */
/* @0x2b8748 add r3, r3, #2 */
/* @0x2b874c ldrb r4, [r2, #-0x1] */
/* @0x2b8750 smlabb r4, r0, r1, r4 */
/* @0x2b8754 add r4, r4, #1 */
/* @0x2b8758 asr r4, r4, #2 */
/* @0x2b875c strb r4, [r3, #-0x2] */
/* @0x2b8760 ldrb r4, [r2, #0x1]! */
/* @0x2b8764 cmp r2, r5 */
/* @0x2b8768 smlabb r1, r0, r1, r4 */
/* @0x2b876c add r1, r1, #2 */
/* @0x2b8770 asr r1, r1, #2 */
/* @0x2b8774 strb r1, [r3, #-0x1] */
/* @0x2b8778 bne 0x2b8744 <jinit_d_post_controller+0x338> */
/* @0x2b877c sub r8, r8, #-2147483646 */
/* @0x2b8780 ldr r3, [sp] */
/* @0x2b8784 add r6, r6, r8, lsl #1 */
/* @0x2b8788 add r7, r7, r3 */
/* @0x2b878c ldrb r3, [r7] */
/* @0x2b8790 add r10, r10, #1 */
/* @0x2b8794 ldrb r2, [r7, #-0x1] */
/* @0x2b8798 add r9, r9, #4 */
/* @0x2b879c strb r3, [r6, #0x1] */
/* @0x2b87a0 smlabb r3, r0, r3, r2 */
/* @0x2b87a4 add r3, r3, #1 */
/* @0x2b87a8 asr r3, r3, #2 */
/* @0x2b87ac strb r3, [r6] */
/* @0x2b87b0 ldr r3, [r11, #0x114] */
/* @0x2b87b4 cmp r3, r10 */
/* @0x2b87b8 bgt 0x2b86ec <jinit_d_post_controller+0x2e0> */
/* @0x2b87bc add sp, sp, #16 */
/* @0x2b87c0 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2b87c4 bx lr */
/* @0x2b87c8 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2b87cc sub sp, sp, #32 */
/* @0x2b87d0 ldr r3, [r3] */
/* @0x2b87d4 str r1, [sp, #0x18] */
/* @0x2b87d8 ldr r1, [r0, #0x114] */
/* @0x2b87dc str r0, [sp, #0x1c] */
/* @0x2b87e0 cmp r1, #0 */
/* @0x2b87e4 ble 0x2b8954 <jinit_d_post_controller+0x548> */
/* @0x2b87e8 mov r10, #3 */
/* @0x2b87ec sub r2, r2, #4 */
/* @0x2b87f0 sub r3, r3, #4 */
/* @0x2b87f4 mov r0, #0 */
/* @0x2b87f8 str r2, [sp, #0x8] */
/* @0x2b87fc str r3, [sp, #0x10] */
/* @0x2b8800 str r0, [sp, #0x14] */
/* @0x2b8804 ldr r3, [sp, #0x10] */
/* @0x2b8808 mov r5, #0 */
/* @0x2b880c str r5, [sp, #0x4] */
/* @0x2b8810 str r3, [sp, #0xc] */
/* @0x2b8814 ldr r1, [sp, #0x4] */
/* @0x2b8818 ldr r2, [sp, #0x8] */
/* @0x2b881c cmp r1, #0 */
/* @0x2b8820 ldrne r5, [sp, #0x8] */
/* @0x2b8824 ldr r3, [r2, #0x4] */
/* @0x2b8828 ldreq r2, [r2] */
/* @0x2b882c ldrne r2, [r5, #0x8] */
/* @0x2b8830 mov r1, r3 */
/* @0x2b8834 ldrb r0, [r3, #0x1] */
/* @0x2b8838 ldrb r5, [r1], #2 */
/* @0x2b883c mov r4, r2 */
/* @0x2b8840 ldrb r3, [r2, #0x1] */
/* @0x2b8844 ldrb r12, [r4], #2 */
/* @0x2b8848 smlabb r3, r10, r0, r3 */
/* @0x2b884c smlabb r12, r10, r5, r12 */
/* @0x2b8850 ldr r5, [sp, #0xc] */
/* @0x2b8854 ldr r2, [r5, #0x4]! */
/* @0x2b8858 add r0, r12, r12, lsl #1 */
/* @0x2b885c add r0, r0, r3 */
/* @0x2b8860 str r5, [sp, #0xc] */
/* @0x2b8864 add r0, r0, #7 */
/* @0x2b8868 add r5, r12, #2 */
/* @0x2b886c mov r9, r2 */
/* @0x2b8870 asr r0, r0, #4 */
/* @0x2b8874 lsr r5, r5, #2 */
/* @0x2b8878 strb r5, [r9], #2 */
/* @0x2b887c strb r0, [r2, #0x1] */
/* @0x2b8880 ldr r0, [sp, #0x18] */
/* @0x2b8884 ldr r11, [r0, #0x28] */
/* @0x2b8888 subs r8, r11, #2 */
/* @0x2b888c beq 0x2b8960 <jinit_d_post_controller+0x554> */
/* @0x2b8890 add r8, r1, r8 */
/* @0x2b8894 mov r2, r9 */
/* @0x2b8898 b 0x2b88a0 <jinit_d_post_controller+0x494> */
/* @0x2b889c mov r3, r6 */
/* @0x2b88a0 ldrb r7, [r1], #1 */
/* @0x2b88a4 add r0, r3, r3, lsl #1 */
/* @0x2b88a8 ldrb r6, [r4], #1 */
/* @0x2b88ac add r5, r0, r12 */
/* @0x2b88b0 add r5, r5, #8 */
/* @0x2b88b4 cmp r1, r8 */
/* @0x2b88b8 mov r12, r3 */
/* @0x2b88bc add r2, r2, #2 */
/* @0x2b88c0 smlabb r6, r10, r7, r6 */
/* @0x2b88c4 asr r5, r5, #4 */
/* @0x2b88c8 strb r5, [r2, #-0x2] */
/* @0x2b88cc add r0, r6, r0 */
/* @0x2b88d0 add r0, r0, #7 */
/* @0x2b88d4 asr r0, r0, #4 */
/* @0x2b88d8 strb r0, [r2, #-0x1] */
/* @0x2b88dc bne 0x2b889c <jinit_d_post_controller+0x490> */
/* @0x2b88e0 sub r11, r11, #-2147483646 */
/* @0x2b88e4 add r9, r9, r11, lsl #1 */
/* @0x2b88e8 ldr r1, [sp, #0x4] */
/* @0x2b88ec add r2, r6, r6, lsl #1 */
/* @0x2b88f0 add r3, r2, r3 */
/* @0x2b88f4 lsl r6, r6, #2 */
/* @0x2b88f8 add r1, r1, #1 */
/* @0x2b88fc add r3, r3, #8 */
/* @0x2b8900 add r6, r6, #7 */
/* @0x2b8904 cmp r1, #2 */
/* @0x2b8908 asr r3, r3, #4 */
/* @0x2b890c str r1, [sp, #0x4] */
/* @0x2b8910 asr r6, r6, #4 */
/* @0x2b8914 strb r3, [r9] */
/* @0x2b8918 strb r6, [r9, #0x1] */
/* @0x2b891c bne 0x2b8814 <jinit_d_post_controller+0x408> */
/* @0x2b8920 ldr r5, [sp, #0x1c] */
/* @0x2b8924 ldr r0, [sp, #0x14] */
/* @0x2b8928 ldr r1, [sp, #0x8] */
/* @0x2b892c ldr r3, [r5, #0x114] */
/* @0x2b8930 add r0, r0, #2 */
/* @0x2b8934 ldr r2, [sp, #0x10] */
/* @0x2b8938 add r1, r1, #4 */
/* @0x2b893c cmp r3, r0 */
/* @0x2b8940 str r0, [sp, #0x14] */
/* @0x2b8944 add r2, r2, #8 */
/* @0x2b8948 str r1, [sp, #0x8] */
/* @0x2b894c str r2, [sp, #0x10] */
/* @0x2b8950 bgt 0x2b8804 <jinit_d_post_controller+0x3f8> */
/* @0x2b8954 add sp, sp, #32 */
/* @0x2b8958 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2b895c bx lr */
/* @0x2b8960 mov r6, r3 */
/* @0x2b8964 mov r3, r12 */
/* @0x2b8968 b 0x2b88e8 <jinit_d_post_controller+0x4dc> */
/* @0x2b896c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b8970 mov r6, r0 */
/* @0x2b8974 ldr r1, [r1, #0x4] */
/* @0x2b8978 sub sp, sp, #8 */
/* @0x2b897c ldr r0, [r0, #0x1a0] */
/* @0x2b8980 ldr r12, [r6, #0x114] */
/* @0x2b8984 add r1, r0, r1 */
/* @0x2b8988 ldr r10, [r3] */
/* @0x2b898c cmp r12, #0 */
/* @0x2b8990 ldrb r4, [r1, #0x8c] */
/* @0x2b8994 ldrb r7, [r1, #0x96] */
/* @0x2b8998 ble 0x2b8a38 <jinit_d_post_controller+0x62c> */
/* @0x2b899c sub r8, r2, #4 */
/* @0x2b89a0 sub r9, r7, #1 */
/* @0x2b89a4 mov r5, #0 */
/* @0x2b89a8 ldr r3, [r10, r5, lsl #2] */
/* @0x2b89ac ldr r0, [r6, #0x5c] */
/* @0x2b89b0 ldr r1, [r8, #0x4]! */
/* @0x2b89b4 add r0, r3, r0 */
/* @0x2b89b8 cmp r3, r0 */
/* @0x2b89bc bhs 0x2b8a00 <jinit_d_post_controller+0x5f4> */
/* @0x2b89c0 cmp r4, #0 */
/* @0x2b89c4 ldrb r2, [r1], #1 */
/* @0x2b89c8 beq 0x2b89f4 <jinit_d_post_controller+0x5e8> */
/* @0x2b89cc add r12, r3, r4 */
/* @0x2b89d0 strb r2, [r3], #1 */
/* @0x2b89d4 cmp r3, r12 */
/* @0x2b89d8 bne 0x2b89d0 <jinit_d_post_controller+0x5c4> */
/* @0x2b89dc cmp r0, r12 */
/* @0x2b89e0 bls 0x2b8a00 <jinit_d_post_controller+0x5f4> */
/* @0x2b89e4 cmp r4, #0 */
/* @0x2b89e8 mov r3, r12 */
/* @0x2b89ec ldrb r2, [r1], #1 */
/* @0x2b89f0 bne 0x2b89cc <jinit_d_post_controller+0x5c0> */
/* @0x2b89f4 mov r12, r3 */
/* @0x2b89f8 cmp r0, r12 */
/* @0x2b89fc bhi 0x2b89e4 <jinit_d_post_controller+0x5d8> */
/* @0x2b8a00 cmp r7, #1 */
/* @0x2b8a04 ble 0x2b8a28 <jinit_d_post_controller+0x61c> */
/* @0x2b8a08 ldr r12, [r6, #0x5c] */
/* @0x2b8a0c mov r0, r10 */
/* @0x2b8a10 str r9, [sp] */
/* @0x2b8a14 mov r1, r5 */
/* @0x2b8a18 mov r2, r10 */
/* @0x2b8a1c add r3, r5, #1 */
/* @0x2b8a20 str r12, [sp, #0x4] */
/* @0x2b8a24 bl 0x2bc81c <jcopy_sample_rows> */
/* @0x2b8a28 ldr r3, [r6, #0x114] */
/* @0x2b8a2c add r5, r5, r7 */
/* @0x2b8a30 cmp r3, r5 */
/* @0x2b8a34 bgt 0x2b89a8 <jinit_d_post_controller+0x59c> */
/* @0x2b8a38 add sp, sp, #8 */
/* @0x2b8a3c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b8a40 ldr r1, [r0, #0x114] */
/* @0x2b8a44 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2b8a48 cmp r1, #0 */
/* @0x2b8a4c sub sp, sp, #12 */
/* @0x2b8a50 mov r7, r0 */
/* @0x2b8a54 ldr r6, [r3] */
/* @0x2b8a58 ble 0x2b8ac8 <jinit_d_post_controller+0x6bc> */
/* @0x2b8a5c sub r9, r2, #4 */
/* @0x2b8a60 mov r5, #0 */
/* @0x2b8a64 mov r8, #1 */
/* @0x2b8a68 ldr r3, [r6, r5, lsl #2] */
/* @0x2b8a6c ldr r2, [r7, #0x5c] */
/* @0x2b8a70 ldr lr, [r9, #0x4]! */
/* @0x2b8a74 add r4, r3, r2 */
/* @0x2b8a78 cmp r3, r4 */
/* @0x2b8a7c bhs 0x2b8a9c <jinit_d_post_controller+0x690> */
/* @0x2b8a80 ldrb r12, [lr], #1 */
/* @0x2b8a84 add r3, r3, #2 */
/* @0x2b8a88 strb r12, [r3, #-0x2] */
/* @0x2b8a8c strb r12, [r3, #-0x1] */
/* @0x2b8a90 cmp r4, r3 */
/* @0x2b8a94 bhi 0x2b8a80 <jinit_d_post_controller+0x674> */
/* @0x2b8a98 ldr r2, [r7, #0x5c] */
/* @0x2b8a9c add r3, r5, #1 */
/* @0x2b8aa0 str r2, [sp, #0x4] */
/* @0x2b8aa4 mov r1, r5 */
/* @0x2b8aa8 str r8, [sp] */
/* @0x2b8aac mov r0, r6 */
/* @0x2b8ab0 mov r2, r6 */
/* @0x2b8ab4 bl 0x2bc81c <jcopy_sample_rows> */
/* @0x2b8ab8 ldr r3, [r7, #0x114] */
/* @0x2b8abc add r5, r5, #2 */
/* @0x2b8ac0 cmp r3, r5 */
/* @0x2b8ac4 bgt 0x2b8a68 <jinit_d_post_controller+0x65c> */
/* @0x2b8ac8 add sp, sp, #12 */
/* @0x2b8acc pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2b8ad0 · jinit_upsampler · size=752 · insn=188 */
/* @0x2b8ad0 ldr r3, [r0, #0x4] */
/* @0x2b8ad4 mov r1, #1 */
/* @0x2b8ad8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b8adc mov r2, #160 */
/* @0x2b8ae0 sub sp, sp, #44 */
/* @0x2b8ae4 ldr r3, [r3] */
/* @0x2b8ae8 mov r4, r0 */
/* @0x2b8aec blx r3 */
/* @0x2b8af0 ldr r1, [pc, #0x2a4] */
/* @0x2b8af4 mov r3, #0 */
/* @0x2b8af8 ldr r2, [pc, #0x2a0] */
/* @0x2b8afc add r1, pc, r1 */
/* @0x2b8b00 add r2, pc, r2 */
/* @0x2b8b04 str r0, [r4, #0x1a0] */
/* @0x2b8b08 stm r0, {r1, r2} */
/* @0x2b8b0c strb r3, [r0, #0x8] */
/* @0x2b8b10 ldrb r3, [r4, #0x10a] */
/* @0x2b8b14 str r0, [sp, #0x8] */
/* @0x2b8b18 cmp r3, #0 */
/* @0x2b8b1c bne 0x2b8d48 <jinit_upsampler+0x278> */
/* @0x2b8b20 ldrb r3, [r4, #0x48] */
/* @0x2b8b24 cmp r3, #0 */
/* @0x2b8b28 streq r3, [sp, #0x14] */
/* @0x2b8b2c beq 0x2b8b44 <jinit_upsampler+0x74> */
/* @0x2b8b30 ldr r3, [r4, #0x118] */
/* @0x2b8b34 cmp r3, #1 */
/* @0x2b8b38 movle r3, #0 */
/* @0x2b8b3c movgt r3, #1 */
/* @0x2b8b40 str r3, [sp, #0x14] */
/* @0x2b8b44 ldr r3, [r4, #0x24] */
/* @0x2b8b48 ldr r5, [r4, #0xc4] */
/* @0x2b8b4c cmp r3, #0 */
/* @0x2b8b50 ble 0x2b8d00 <jinit_upsampler+0x230> */
/* @0x2b8b54 ldr r0, [pc, #0x248] */
/* @0x2b8b58 mov r8, #0 */
/* @0x2b8b5c ldr r1, [pc, #0x244] */
/* @0x2b8b60 ldr r6, [sp, #0x8] */
/* @0x2b8b64 add r0, pc, r0 */
/* @0x2b8b68 add r1, pc, r1 */
/* @0x2b8b6c str r0, [sp, #0x10] */
/* @0x2b8b70 str r1, [sp, #0x1c] */
/* @0x2b8b74 ldr r2, [pc, #0x230] */
/* @0x2b8b78 mov r10, r6 */
/* @0x2b8b7c ldr r3, [pc, #0x22c] */
/* @0x2b8b80 ldr r0, [pc, #0x22c] */
/* @0x2b8b84 add r2, pc, r2 */
/* @0x2b8b88 ldr r1, [pc, #0x228] */
/* @0x2b8b8c add r3, pc, r3 */
/* @0x2b8b90 add r0, pc, r0 */
/* @0x2b8b94 str r2, [sp, #0x20] */
/* @0x2b8b98 add r1, pc, r1 */
/* @0x2b8b9c str r3, [sp, #0x18] */
/* @0x2b8ba0 str r0, [sp, #0x24] */
/* @0x2b8ba4 str r1, [sp, #0xc] */
/* @0x2b8ba8 b 0x2b8bd4 <jinit_upsampler+0x104> */
/* @0x2b8bac ldr r3, [pc, #0x208] */
/* @0x2b8bb0 add r3, pc, r3 */
/* @0x2b8bb4 str r3, [r6, #0x34] */
/* @0x2b8bb8 ldr r3, [r4, #0x24] */
/* @0x2b8bbc add r8, r8, #1 */
/* @0x2b8bc0 add r5, r5, #84 */
/* @0x2b8bc4 add r6, r6, #4 */
/* @0x2b8bc8 cmp r3, r8 */
/* @0x2b8bcc add r10, r10, #1 */
/* @0x2b8bd0 ble 0x2b8d00 <jinit_upsampler+0x230> */
/* @0x2b8bd4 ldr r3, [r5, #0x24] */
/* @0x2b8bd8 ldr r0, [r5, #0xc] */
/* @0x2b8bdc ldr r9, [r4, #0x118] */
/* @0x2b8be0 ldr r2, [r5, #0x8] */
/* @0x2b8be4 mul r0, r0, r3 */
/* @0x2b8be8 mov r1, r9 */
/* @0x2b8bec str r3, [sp] */
/* @0x2b8bf0 str r2, [sp, #0x4] */
/* @0x2b8bf4 bl 0x318d10 <__divsi3> */
/* @0x2b8bf8 ldr r12, [r4, #0x110] */
/* @0x2b8bfc ldr r11, [r4, #0x114] */
/* @0x2b8c00 str r0, [r6, #0x64] */
/* @0x2b8c04 mov r7, r0 */
/* @0x2b8c08 ldrb r1, [r5, #0x30] */
/* @0x2b8c0c ldr r3, [sp] */
/* @0x2b8c10 cmp r1, #0 */
/* @0x2b8c14 beq 0x2b8bac <jinit_upsampler+0xdc> */
/* @0x2b8c18 ldr r2, [sp, #0x4] */
/* @0x2b8c1c mov r1, r9 */
/* @0x2b8c20 str r12, [sp] */
/* @0x2b8c24 mul r0, r3, r2 */
/* @0x2b8c28 bl 0x318d10 <__divsi3> */
/* @0x2b8c2c subs r2, r7, r11 */
/* @0x2b8c30 ldr r12, [sp] */
/* @0x2b8c34 rsbs r3, r2, #0 */
/* @0x2b8c38 adcs r3, r3, r2 */
/* @0x2b8c3c cmp r0, r12 */
/* @0x2b8c40 cmpeq r7, r11 */
/* @0x2b8c44 mov r9, r0 */
/* @0x2b8c48 ldreq r3, [sp, #0xc] */
/* @0x2b8c4c streq r3, [r6, #0x34] */
/* @0x2b8c50 beq 0x2b8bb8 <jinit_upsampler+0xe8> */
/* @0x2b8c54 cmp r12, r0, lsl #1 */
/* @0x2b8c58 beq 0x2b8d08 <jinit_upsampler+0x238> */
/* @0x2b8c5c mov r0, r12 */
/* @0x2b8c60 mov r1, r9 */
/* @0x2b8c64 str r12, [sp] */
/* @0x2b8c68 bl 0x318dec <__aeabi_idivmod> */
/* @0x2b8c6c cmp r1, #0 */
/* @0x2b8c70 bne 0x2b8ce4 <jinit_upsampler+0x214> */
/* @0x2b8c74 mov r0, r11 */
/* @0x2b8c78 mov r1, r7 */
/* @0x2b8c7c bl 0x318dec <__aeabi_idivmod> */
/* @0x2b8c80 ldr r12, [sp] */
/* @0x2b8c84 cmp r1, #0 */
/* @0x2b8c88 bne 0x2b8ce4 <jinit_upsampler+0x214> */
/* @0x2b8c8c ldr r3, [sp, #0x10] */
/* @0x2b8c90 mov r0, r12 */
/* @0x2b8c94 mov r1, r9 */
/* @0x2b8c98 str r3, [r6, #0x34] */
/* @0x2b8c9c bl 0x318d10 <__divsi3> */
/* @0x2b8ca0 mov r1, r7 */
/* @0x2b8ca4 strb r0, [r10, #0x8c] */
/* @0x2b8ca8 mov r0, r11 */
/* @0x2b8cac bl 0x318d10 <__divsi3> */
/* @0x2b8cb0 strb r0, [r10, #0x96] */
/* @0x2b8cb4 ldr r3, [r4, #0x4] */
/* @0x2b8cb8 ldr r1, [r4, #0x110] */
/* @0x2b8cbc ldr r0, [r4, #0x5c] */
/* @0x2b8cc0 ldr r7, [r3, #0x8] */
/* @0x2b8cc4 bl 0x2bc800 <jround_up> */
/* @0x2b8cc8 mov r1, #1 */
/* @0x2b8ccc ldr r3, [r4, #0x114] */
/* @0x2b8cd0 mov r2, r0 */
/* @0x2b8cd4 mov r0, r4 */
/* @0x2b8cd8 blx r7 */
/* @0x2b8cdc str r0, [r6, #0xc] */
/* @0x2b8ce0 b 0x2b8bb8 <jinit_upsampler+0xe8> */
/* @0x2b8ce4 ldr r3, [r4] */
/* @0x2b8ce8 mov r2, #38 */
/* @0x2b8cec mov r0, r4 */
/* @0x2b8cf0 str r2, [r3, #0x14] */
/* @0x2b8cf4 ldr r3, [r3] */
/* @0x2b8cf8 blx r3 */
/* @0x2b8cfc b 0x2b8cb4 <jinit_upsampler+0x1e4> */
/* @0x2b8d00 add sp, sp, #44 */
/* @0x2b8d04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b8d08 cmp r3, #0 */
/* @0x2b8d0c bne 0x2b8d70 <jinit_upsampler+0x2a0> */
/* @0x2b8d10 cmp r11, r7, lsl #1 */
/* @0x2b8d14 bne 0x2b8c5c <jinit_upsampler+0x18c> */
/* @0x2b8d18 ldr r3, [sp, #0x14] */
/* @0x2b8d1c cmp r3, #0 */
/* @0x2b8d20 beq 0x2b8d64 <jinit_upsampler+0x294> */
/* @0x2b8d24 ldr r3, [r5, #0x28] */
/* @0x2b8d28 cmp r3, #2 */
/* @0x2b8d2c bls 0x2b8d64 <jinit_upsampler+0x294> */
/* @0x2b8d30 ldr r0, [sp, #0x20] */
/* @0x2b8d34 mov r3, #1 */
/* @0x2b8d38 ldr r1, [sp, #0x8] */
/* @0x2b8d3c str r0, [r6, #0x34] */
/* @0x2b8d40 strb r3, [r1, #0x8] */
/* @0x2b8d44 b 0x2b8cb4 <jinit_upsampler+0x1e4> */
/* @0x2b8d48 ldr r3, [r4] */
/* @0x2b8d4c mov r2, #25 */
/* @0x2b8d50 mov r0, r4 */
/* @0x2b8d54 str r2, [r3, #0x14] */
/* @0x2b8d58 ldr r3, [r3] */
/* @0x2b8d5c blx r3 */
/* @0x2b8d60 b 0x2b8b20 <jinit_upsampler+0x50> */
/* @0x2b8d64 ldr r2, [sp, #0x1c] */
/* @0x2b8d68 str r2, [r6, #0x34] */
/* @0x2b8d6c b 0x2b8cb4 <jinit_upsampler+0x1e4> */
/* @0x2b8d70 ldr r0, [sp, #0x14] */
/* @0x2b8d74 cmp r0, #0 */
/* @0x2b8d78 beq 0x2b8d90 <jinit_upsampler+0x2c0> */
/* @0x2b8d7c ldr r3, [r5, #0x28] */
/* @0x2b8d80 cmp r3, #2 */
/* @0x2b8d84 ldrhi r1, [sp, #0x24] */
/* @0x2b8d88 strhi r1, [r6, #0x34] */
/* @0x2b8d8c bhi 0x2b8cb4 <jinit_upsampler+0x1e4> */
/* @0x2b8d90 ldr r2, [sp, #0x18] */
/* @0x2b8d94 str r2, [r6, #0x34] */
/* @0x2b8d98 b 0x2b8cb4 <jinit_upsampler+0x1e4> */
/* @0x2b8d9c .word 0xfffff9e4 */
/* @0x2b8da0 .word 0xfffff9f8 */
/* @0x2b8da4 .word 0xfffffe00 */
/* @0x2b8da8 .word 0xfffffed0 */
/* @0x2b8dac .word 0xfffffc3c */
/* @0x2b8db0 .word 0xfffffabc */
/* @0x2b8db4 .word 0xfffffb20 */
/* @0x2b8db8 .word 0xfffffa9c */
/* @0x2b8dbc .word 0xfffffa8c */

/* ── FUNC 0x2b8dc0 · anon_2b8dc0 · size=508 · insn=128 */
/* @0x2b8dc0 cmp r1, #0 */
/* @0x2b8dc4 mov r3, r0 */
/* @0x2b8dc8 push {r4, lr} */
/* @0x2b8dcc ldr r4, [r0] */
/* @0x2b8dd0 blt 0x2b8dec <jinit_upsampler+0x31c> */
/* @0x2b8dd4 ldr r3, [r4, #0x68] */
/* @0x2b8dd8 cmp r1, r3 */
/* @0x2b8ddc popgt {r4, pc} */
/* @0x2b8de0 ldr r3, [r4, #0x8] */
/* @0x2b8de4 blx r3 */
/* @0x2b8de8 pop {r4, pc} */
/* @0x2b8dec ldr r2, [r4, #0x6c] */
/* @0x2b8df0 cmp r2, #0 */
/* @0x2b8df4 beq 0x2b8e04 <jinit_upsampler+0x334> */
/* @0x2b8df8 ldr r1, [r4, #0x68] */
/* @0x2b8dfc cmp r1, #2 */
/* @0x2b8e00 ble 0x2b8e14 <jinit_upsampler+0x344> */
/* @0x2b8e04 mov r0, r3 */
/* @0x2b8e08 ldr r3, [r4, #0x8] */
/* @0x2b8e0c blx r3 */
/* @0x2b8e10 ldr r2, [r4, #0x6c] */
/* @0x2b8e14 add r2, r2, #1 */
/* @0x2b8e18 str r2, [r4, #0x6c] */
/* @0x2b8e1c pop {r4, pc} */
/* @0x2b8e20 ldr r3, [r0] */
/* @0x2b8e24 mov r2, #0 */
/* @0x2b8e28 str r2, [r3, #0x6c] */
/* @0x2b8e2c str r2, [r3, #0x14] */
/* @0x2b8e30 bx lr */
/* @0x2b8e34 push {r4, r5, lr} */
/* @0x2b8e38 sub sp, sp, #28 */
/* @0x2b8e3c ldr r5, [r0] */
/* @0x2b8e40 mov r0, r1 */
/* @0x2b8e44 ldr r3, [r5, #0x14] */
/* @0x2b8e48 cmp r3, #0 */
/* @0x2b8e4c ble 0x2b8ed0 <jinit_upsampler+0x400> */
/* @0x2b8e50 ldr r2, [r5, #0x74] */
/* @0x2b8e54 cmp r3, r2 */
/* @0x2b8e58 bgt 0x2b8ed0 <jinit_upsampler+0x400> */
/* @0x2b8e5c ldr r2, [r5, #0x70] */
/* @0x2b8e60 ldr r1, [r2, r3, lsl #2] */
/* @0x2b8e64 cmp r1, #0 */
/* @0x2b8e68 beq 0x2b8f1c <jinit_upsampler+0x44c> */
/* @0x2b8e6c mov r4, r1 */
/* @0x2b8e70 b 0x2b8e80 <jinit_upsampler+0x3b0> */
/* @0x2b8e74 cmp r12, #37 */
/* @0x2b8e78 beq 0x2b8f00 <jinit_upsampler+0x430> */
/* @0x2b8e7c mov r4, r3 */
/* @0x2b8e80 mov r3, r4 */
/* @0x2b8e84 ldrb r12, [r3], #1 */
/* @0x2b8e88 cmp r12, #0 */
/* @0x2b8e8c bne 0x2b8e74 <jinit_upsampler+0x3a4> */
/* @0x2b8e90 add r2, r5, #24 */
/* @0x2b8e94 ldm r2, {r2, r3, r12} */
/* @0x2b8e98 str r12, [sp] */
/* @0x2b8e9c ldr r12, [r5, #0x24] */
/* @0x2b8ea0 str r12, [sp, #0x4] */
/* @0x2b8ea4 ldr r12, [r5, #0x28] */
/* @0x2b8ea8 str r12, [sp, #0x8] */
/* @0x2b8eac ldr r12, [r5, #0x2c] */
/* @0x2b8eb0 str r12, [sp, #0xc] */
/* @0x2b8eb4 ldr r12, [r5, #0x30] */
/* @0x2b8eb8 str r12, [sp, #0x10] */
/* @0x2b8ebc ldr r12, [r5, #0x34] */
/* @0x2b8ec0 str r12, [sp, #0x14] */
/* @0x2b8ec4 bl 0xb6550 <sprintf@plt> */
/* @0x2b8ec8 add sp, sp, #28 */
/* @0x2b8ecc pop {r4, r5, pc} */
/* @0x2b8ed0 ldr r2, [r5, #0x78] */
/* @0x2b8ed4 cmp r2, #0 */
/* @0x2b8ed8 beq 0x2b8f1c <jinit_upsampler+0x44c> */
/* @0x2b8edc ldr r1, [r5, #0x7c] */
/* @0x2b8ee0 cmp r3, r1 */
/* @0x2b8ee4 blt 0x2b8f1c <jinit_upsampler+0x44c> */
/* @0x2b8ee8 ldr r12, [r5, #0x80] */
/* @0x2b8eec cmp r3, r12 */
/* @0x2b8ef0 bgt 0x2b8f1c <jinit_upsampler+0x44c> */
/* @0x2b8ef4 rsb r1, r1, r3 */
/* @0x2b8ef8 ldr r1, [r2, r1, lsl #2] */
/* @0x2b8efc b 0x2b8e64 <jinit_upsampler+0x394> */
/* @0x2b8f00 ldrb r3, [r4, #0x1] */
/* @0x2b8f04 cmp r3, #115 */
/* @0x2b8f08 bne 0x2b8e90 <jinit_upsampler+0x3c0> */
/* @0x2b8f0c add r2, r5, #24 */
/* @0x2b8f10 add sp, sp, #28 */
/* @0x2b8f14 pop {r4, r5, lr} */
/* @0x2b8f18 b 0xb6550 <sprintf@plt> */
/* @0x2b8f1c ldr r2, [r5, #0x70] */
/* @0x2b8f20 str r3, [r5, #0x18] */
/* @0x2b8f24 ldr r1, [r2] */
/* @0x2b8f28 b 0x2b8e6c <jinit_upsampler+0x39c> */
/* @0x2b8f2c push {r4, r5, lr} */
/* @0x2b8f30 sub sp, sp, #212 */
/* @0x2b8f34 ldr r4, [pc, #0x54] */
/* @0x2b8f38 add r5, sp, #4 */
/* @0x2b8f3c ldr r3, [r0] */
/* @0x2b8f40 ldr r4, [pc, r4] */
/* @0x2b8f44 mov r1, r5 */
/* @0x2b8f48 ldr r2, [r4] */
/* @0x2b8f4c ldr r3, [r3, #0xc] */
/* @0x2b8f50 str r2, [sp, #0xcc] */
/* @0x2b8f54 blx r3 */
/* @0x2b8f58 ldr r0, [pc, #0x34] */
/* @0x2b8f5c mov r2, r5 */
/* @0x2b8f60 ldr r1, [pc, #0x30] */
/* @0x2b8f64 ldr r0, [pc, r0] */
/* @0x2b8f68 add r1, pc, r1 */
/* @0x2b8f6c add r0, r0, #168 */
/* @0x2b8f70 bl 0xb68a4 <fprintf@plt> */
/* @0x2b8f74 ldr r2, [sp, #0xcc] */
/* @0x2b8f78 ldr r3, [r4] */
/* @0x2b8f7c cmp r2, r3 */
/* @0x2b8f80 bne 0x2b8f8c <jinit_upsampler+0x4bc> */
/* @0x2b8f84 add sp, sp, #212 */
/* @0x2b8f88 pop {r4, r5, pc} */
/* @0x2b8f8c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2b8f90 andseq r4, r3, r0, lsl r10 */
/* @0x2b8f94 andseq r8, r3, r0, ror #9 */
/* @0x2b8f98 andeq r11, r7, r12, lsr sp */
/* @0x2b8f9c push {r3, lr} */
/* @0x2b8fa0 mov r4, r0 */
/* @0x2b8fa4 ldr r3, [r0] */
/* @0x2b8fa8 ldr r3, [r3, #0x8] */
/* @0x2b8fac blx r3 */
/* @0x2b8fb0 mov r0, r4 */
/* @0x2b8fb4 bl 0x2bc8b8 <jpeg_destroy> */
/* @0x2b8fb8 mov r0, #1 */
/* @0x2b8fbc bl 0xb6688 <exit@plt> */

/* ── FUNC 0x2b8fc0 · jpeg_std_error · size=148 · insn=37 */
/* @0x2b8fc0 push {r4, r5, r6, r7, r8} */
/* @0x2b8fc4 mov r3, r0 */
/* @0x2b8fc8 ldr r8, [pc, #0x6c] */
/* @0x2b8fcc mov r2, #0 */
/* @0x2b8fd0 ldr r7, [pc, #0x68] */
/* @0x2b8fd4 mov r12, #123 */
/* @0x2b8fd8 ldr r6, [pc, #0x64] */
/* @0x2b8fdc add r8, pc, r8 */
/* @0x2b8fe0 ldr r5, [pc, #0x60] */
/* @0x2b8fe4 add r7, pc, r7 */
/* @0x2b8fe8 ldr r4, [pc, #0x5c] */
/* @0x2b8fec add r6, pc, r6 */
/* @0x2b8ff0 ldr r1, [pc, #0x58] */
/* @0x2b8ff4 add r5, pc, r5 */
/* @0x2b8ff8 str r8, [r0] */
/* @0x2b8ffc add r4, pc, r4 */
/* @0x2b9000 str r7, [r0, #0x4] */
/* @0x2b9004 ldr r1, [pc, r1] */
/* @0x2b9008 str r1, [r0, #0x70] */
/* @0x2b900c str r6, [r3, #0x8] */
/* @0x2b9010 str r5, [r3, #0xc] */
/* @0x2b9014 str r4, [r3, #0x10] */
/* @0x2b9018 str r12, [r0, #0x74] */
/* @0x2b901c str r2, [r0, #0x68] */
/* @0x2b9020 str r2, [r0, #0x6c] */
/* @0x2b9024 str r2, [r0, #0x14] */
/* @0x2b9028 str r2, [r0, #0x78] */
/* @0x2b902c str r2, [r0, #0x7c] */
/* @0x2b9030 str r2, [r0, #0x80] */
/* @0x2b9034 pop {r4, r5, r6, r7, r8} */
/* @0x2b9038 bx lr */
/* @0x2b903c .word 0xffffffb8 */
/* @0x2b9040 .word 0xfffffdd4 */
/* @0x2b9044 .word 0xffffff38 */
/* @0x2b9048 .word 0xfffffe38 */
/* @0x2b904c .word 0xfffffe1c */
/* @0x2b9050 andseq r8, r3, r8, lsr #21 */

/* ── FUNC 0x2b9054 · anon_2b9054 · size=4188 · insn=1048 */
/* @0x2b9054 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b9058 mov r8, r0 */
/* @0x2b905c ldr r7, [r1, #0x8] */
/* @0x2b9060 mov r4, r1 */
/* @0x2b9064 ldr r0, [r1, #0x10] */
/* @0x2b9068 sub sp, sp, #8 */
/* @0x2b906c ldr r1, [r1, #0x18] */
/* @0x2b9070 lsl r7, r7, #7 */
/* @0x2b9074 cmp r0, #0 */
/* @0x2b9078 mul r5, r1, r7 */
/* @0x2b907c ble 0x2b9148 <jpeg_std_error+0x188> */
/* @0x2b9080 ldr r6, [r4, #0x14] */
/* @0x2b9084 ldr r3, [r4, #0x1c] */
/* @0x2b9088 ldr r12, [r4, #0x4] */
/* @0x2b908c cmp r0, r6 */
/* @0x2b9090 movge r0, r6 */
/* @0x2b9094 rsb r3, r1, r3 */
/* @0x2b9098 cmp r3, r0 */
/* @0x2b909c movge r3, r0 */
/* @0x2b90a0 rsb r1, r1, r12 */
/* @0x2b90a4 cmp r3, r1 */
/* @0x2b90a8 movge r3, r1 */
/* @0x2b90ac cmp r3, #0 */
/* @0x2b90b0 ble 0x2b9148 <jpeg_std_error+0x188> */
/* @0x2b90b4 cmp r2, #0 */
/* @0x2b90b8 addne r9, r4, #40 */
/* @0x2b90bc movne r6, #0 */
/* @0x2b90c0 bne 0x2b9188 <jpeg_std_error+0x1c8> */
/* @0x2b90c4 add r9, r4, #40 */
/* @0x2b90c8 mov r6, r2 */
/* @0x2b90cc b 0x2b9108 <jpeg_std_error+0x148> */
/* @0x2b90d0 ldr r2, [r4, #0x18] */
/* @0x2b90d4 cmp r3, r1 */
/* @0x2b90d8 movge r3, r1 */
/* @0x2b90dc ldr r12, [r4, #0x1c] */
/* @0x2b90e0 add r2, r6, r2 */
/* @0x2b90e4 ldr r0, [r4, #0x4] */
/* @0x2b90e8 rsb r12, r2, r12 */
/* @0x2b90ec cmp r3, r12 */
/* @0x2b90f0 movge r3, r12 */
/* @0x2b90f4 rsb r2, r2, r0 */
/* @0x2b90f8 cmp r3, r2 */
/* @0x2b90fc movge r3, r2 */
/* @0x2b9100 cmp r3, #0 */
/* @0x2b9104 ble 0x2b9148 <jpeg_std_error+0x188> */
/* @0x2b9108 mul r12, r7, r3 */
/* @0x2b910c ldr r2, [r4] */
/* @0x2b9110 mov r3, r5 */
/* @0x2b9114 ldr r10, [r4, #0x28] */
/* @0x2b9118 mov r1, r9 */
/* @0x2b911c mov r0, r8 */
/* @0x2b9120 ldr r2, [r2, r6, lsl #2] */
/* @0x2b9124 add r5, r5, r12 */
/* @0x2b9128 str r12, [sp] */
/* @0x2b912c blx r10 */
/* @0x2b9130 ldr r1, [r4, #0x14] */
/* @0x2b9134 ldr r2, [r4, #0x10] */
/* @0x2b9138 add r6, r1, r6 */
/* @0x2b913c cmp r6, r2 */
/* @0x2b9140 rsb r3, r6, r2 */
/* @0x2b9144 blt 0x2b90d0 <jpeg_std_error+0x110> */
/* @0x2b9148 add sp, sp, #8 */
/* @0x2b914c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b9150 ldr r2, [r4, #0x18] */
/* @0x2b9154 cmp r3, r1 */
/* @0x2b9158 movge r3, r1 */
/* @0x2b915c ldr r12, [r4, #0x1c] */
/* @0x2b9160 add r2, r6, r2 */
/* @0x2b9164 ldr r0, [r4, #0x4] */
/* @0x2b9168 rsb r12, r2, r12 */
/* @0x2b916c cmp r3, r12 */
/* @0x2b9170 movge r3, r12 */
/* @0x2b9174 rsb r2, r2, r0 */
/* @0x2b9178 cmp r3, r2 */
/* @0x2b917c movge r3, r2 */
/* @0x2b9180 cmp r3, #0 */
/* @0x2b9184 ble 0x2b9148 <jpeg_std_error+0x188> */
/* @0x2b9188 mul r12, r7, r3 */
/* @0x2b918c ldr r2, [r4] */
/* @0x2b9190 mov r3, r5 */
/* @0x2b9194 ldr r10, [r4, #0x2c] */
/* @0x2b9198 mov r1, r9 */
/* @0x2b919c mov r0, r8 */
/* @0x2b91a0 ldr r2, [r2, r6, lsl #2] */
/* @0x2b91a4 add r5, r5, r12 */
/* @0x2b91a8 str r12, [sp] */
/* @0x2b91ac blx r10 */
/* @0x2b91b0 ldr r1, [r4, #0x14] */
/* @0x2b91b4 ldr r2, [r4, #0x10] */
/* @0x2b91b8 add r6, r1, r6 */
/* @0x2b91bc cmp r2, r6 */
/* @0x2b91c0 rsb r3, r6, r2 */
/* @0x2b91c4 bgt 0x2b9150 <jpeg_std_error+0x190> */
/* @0x2b91c8 add sp, sp, #8 */
/* @0x2b91cc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b91d0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b91d4 movw r3, #0xc9f0 */
/* @0x2b91d8 movt r3, #0x3b9a */
/* @0x2b91dc mov r5, r2 */
/* @0x2b91e0 cmp r2, r3 */
/* @0x2b91e4 mov r10, r0 */
/* @0x2b91e8 mov r9, r1 */
/* @0x2b91ec ldr r7, [r0, #0x4] */
/* @0x2b91f0 bhi 0x2b92f8 <jpeg_std_error+0x338> */
/* @0x2b91f4 ands r3, r5, #7 */
/* @0x2b91f8 addne r5, r5, #8 */
/* @0x2b91fc rsbne r5, r3, r5 */
/* @0x2b9200 cmp r9, #1 */
/* @0x2b9204 bls 0x2b9228 <jpeg_std_error+0x268> */
/* @0x2b9208 ldr r3, [r10] */
/* @0x2b920c mov r12, #14 */
/* @0x2b9210 mov r0, r10 */
/* @0x2b9214 str r9, [r3, #0x18] */
/* @0x2b9218 ldr r1, [r10] */
/* @0x2b921c str r12, [r3, #0x14] */
/* @0x2b9220 ldr r3, [r1] */
/* @0x2b9224 blx r3 */
/* @0x2b9228 lsl r3, r9, #2 */
/* @0x2b922c add r8, r7, r3 */
/* @0x2b9230 ldr r4, [r8, #0x34] */
/* @0x2b9234 cmp r4, #0 */
/* @0x2b9238 beq 0x2b9358 <jpeg_std_error+0x398> */
/* @0x2b923c ldr r12, [r4, #0x8] */
/* @0x2b9240 cmp r5, r12 */
/* @0x2b9244 bhi 0x2b925c <jpeg_std_error+0x29c> */
/* @0x2b9248 b 0x2b92d8 <jpeg_std_error+0x318> */
/* @0x2b924c ldr r12, [r3, #0x8] */
/* @0x2b9250 mov r4, r3 */
/* @0x2b9254 cmp r5, r12 */
/* @0x2b9258 bls 0x2b92dc <jpeg_std_error+0x31c> */
/* @0x2b925c ldr r3, [r4] */
/* @0x2b9260 cmp r3, #0 */
/* @0x2b9264 bne 0x2b924c <jpeg_std_error+0x28c> */
/* @0x2b9268 ldr r3, [pc, #0x100] */
/* @0x2b926c add r6, r5, #16 */
/* @0x2b9270 add r3, pc, r3 */
/* @0x2b9274 ldr r11, [r3, r9, lsl #2] */
/* @0x2b9278 movw r3, #0xc9f0 */
/* @0x2b927c movt r3, #0x3b9a */
/* @0x2b9280 rsb r3, r5, r3 */
/* @0x2b9284 cmp r11, r3 */
/* @0x2b9288 movhs r11, r3 */
/* @0x2b928c add r9, r11, r6 */
/* @0x2b9290 mov r0, r10 */
/* @0x2b9294 mov r1, r9 */
/* @0x2b9298 bl 0x2c137c <jpeg_get_small> */
/* @0x2b929c subs r3, r0, #0 */
/* @0x2b92a0 bne 0x2b931c <jpeg_std_error+0x35c> */
/* @0x2b92a4 lsr r11, r11, #1 */
/* @0x2b92a8 cmp r11, #49 */
/* @0x2b92ac bhi 0x2b928c <jpeg_std_error+0x2cc> */
/* @0x2b92b0 ldr r3, [r10] */
/* @0x2b92b4 mov r2, #2 */
/* @0x2b92b8 mov r0, r10 */
/* @0x2b92bc str r2, [r3, #0x18] */
/* @0x2b92c0 mov r2, #54 */
/* @0x2b92c4 ldr r1, [r10] */
/* @0x2b92c8 str r2, [r3, #0x14] */
/* @0x2b92cc ldr r3, [r1] */
/* @0x2b92d0 blx r3 */
/* @0x2b92d4 b 0x2b928c <jpeg_std_error+0x2cc> */
/* @0x2b92d8 mov r3, r4 */
/* @0x2b92dc ldr r0, [r3, #0x4] */
/* @0x2b92e0 add r2, r3, #16 */
/* @0x2b92e4 rsb r12, r5, r12 */
/* @0x2b92e8 add r5, r0, r5 */
/* @0x2b92ec add r0, r2, r0 */
/* @0x2b92f0 stmib r3, {r5, r12} */
/* @0x2b92f4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b92f8 ldr r3, [r0] */
/* @0x2b92fc mov r1, #1 */
/* @0x2b9300 mov r12, #54 */
/* @0x2b9304 str r1, [r3, #0x18] */
/* @0x2b9308 ldr r1, [r0] */
/* @0x2b930c str r12, [r3, #0x14] */
/* @0x2b9310 ldr r3, [r1] */
/* @0x2b9314 blx r3 */
/* @0x2b9318 b 0x2b91f4 <jpeg_std_error+0x234> */
/* @0x2b931c ldr r2, [r7, #0x4c] */
/* @0x2b9320 cmp r4, #0 */
/* @0x2b9324 add r11, r11, r5 */
/* @0x2b9328 mov r0, #0 */
/* @0x2b932c add r12, r2, r9 */
/* @0x2b9330 str r12, [r7, #0x4c] */
/* @0x2b9334 str r0, [r3] */
/* @0x2b9338 moveq r12, r11 */
/* @0x2b933c str r0, [r3, #0x4] */
/* @0x2b9340 movne r12, r11 */
/* @0x2b9344 str r11, [r3, #0x8] */
/* @0x2b9348 moveq r0, r4 */
/* @0x2b934c streq r3, [r8, #0x34] */
/* @0x2b9350 strne r3, [r4] */
/* @0x2b9354 b 0x2b92e0 <jpeg_std_error+0x320> */
/* @0x2b9358 ldr r1, [pc, #0x14] */
/* @0x2b935c add r6, r5, #16 */
/* @0x2b9360 add r1, pc, r1 */
/* @0x2b9364 add r3, r1, r3 */
/* @0x2b9368 ldr r11, [r3, #0x8] */
/* @0x2b936c b 0x2b9278 <jpeg_std_error+0x2b8> */
/* @0x2b9370 andeq r6, sp, r0, asr r12 */
/* @0x2b9374 andeq r6, sp, r0, ror #22 */
/* @0x2b9378 cmp r1, #1 */
/* @0x2b937c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b9380 mov r5, r1 */
/* @0x2b9384 mov r4, r0 */
/* @0x2b9388 mov r10, r2 */
/* @0x2b938c mov r8, r3 */
/* @0x2b9390 ldr r6, [r0, #0x4] */
/* @0x2b9394 ldr r9, [sp, #0x20] */
/* @0x2b9398 ldr r7, [sp, #0x24] */
/* @0x2b939c beq 0x2b93bc <jpeg_std_error+0x3fc> */
/* @0x2b93a0 ldr r3, [r0] */
/* @0x2b93a4 mov r1, #14 */
/* @0x2b93a8 str r5, [r3, #0x18] */
/* @0x2b93ac ldr r2, [r0] */
/* @0x2b93b0 str r1, [r3, #0x14] */
/* @0x2b93b4 ldr r3, [r2] */
/* @0x2b93b8 blx r3 */
/* @0x2b93bc mov r0, r4 */
/* @0x2b93c0 mov r1, r5 */
/* @0x2b93c4 mov r2, #120 */
/* @0x2b93c8 bl 0x2b91d0 <jpeg_std_error+0x210> */
/* @0x2b93cc mov r2, #0 */
/* @0x2b93d0 strb r10, [r0, #0x20] */
/* @0x2b93d4 strb r2, [r0, #0x22] */
/* @0x2b93d8 ldr r3, [r6, #0x48] */
/* @0x2b93dc str r9, [r0, #0x4] */
/* @0x2b93e0 str r8, [r0, #0x8] */
/* @0x2b93e4 str r7, [r0, #0xc] */
/* @0x2b93e8 str r2, [r0] */
/* @0x2b93ec str r3, [r0, #0x24] */
/* @0x2b93f0 str r0, [r6, #0x48] */
/* @0x2b93f4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b93f8 cmp r1, #1 */
/* @0x2b93fc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b9400 mov r5, r1 */
/* @0x2b9404 mov r4, r0 */
/* @0x2b9408 mov r10, r2 */
/* @0x2b940c mov r8, r3 */
/* @0x2b9410 ldr r6, [r0, #0x4] */
/* @0x2b9414 ldr r9, [sp, #0x20] */
/* @0x2b9418 ldr r7, [sp, #0x24] */
/* @0x2b941c beq 0x2b943c <jpeg_std_error+0x47c> */
/* @0x2b9420 ldr r3, [r0] */
/* @0x2b9424 mov r1, #14 */
/* @0x2b9428 str r5, [r3, #0x18] */
/* @0x2b942c ldr r2, [r0] */
/* @0x2b9430 str r1, [r3, #0x14] */
/* @0x2b9434 ldr r3, [r2] */
/* @0x2b9438 blx r3 */
/* @0x2b943c mov r0, r4 */
/* @0x2b9440 mov r1, r5 */
/* @0x2b9444 mov r2, #120 */
/* @0x2b9448 bl 0x2b91d0 <jpeg_std_error+0x210> */
/* @0x2b944c mov r2, #0 */
/* @0x2b9450 strb r10, [r0, #0x20] */
/* @0x2b9454 strb r2, [r0, #0x22] */
/* @0x2b9458 ldr r3, [r6, #0x44] */
/* @0x2b945c str r9, [r0, #0x4] */
/* @0x2b9460 str r8, [r0, #0x8] */
/* @0x2b9464 str r7, [r0, #0xc] */
/* @0x2b9468 str r2, [r0] */
/* @0x2b946c str r3, [r0, #0x24] */
/* @0x2b9470 str r0, [r6, #0x44] */
/* @0x2b9474 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b9478 cmp r1, #1 */
/* @0x2b947c push {r4, r5, r6, r7, r8, lr} */
/* @0x2b9480 mov r8, r1 */
/* @0x2b9484 mov r7, r0 */
/* @0x2b9488 ldr r4, [r0, #0x4] */
/* @0x2b948c bls 0x2b9554 <jpeg_std_error+0x594> */
/* @0x2b9490 ldr r3, [r0] */
/* @0x2b9494 mov r1, #14 */
/* @0x2b9498 str r8, [r3, #0x18] */
/* @0x2b949c ldr r2, [r0] */
/* @0x2b94a0 str r1, [r3, #0x14] */
/* @0x2b94a4 ldr r3, [r2] */
/* @0x2b94a8 blx r3 */
/* @0x2b94ac add r8, r4, r8, lsl #2 */
/* @0x2b94b0 mov r2, #0 */
/* @0x2b94b4 ldr r3, [r8, #0x3c] */
/* @0x2b94b8 str r2, [r8, #0x3c] */
/* @0x2b94bc cmp r3, r2 */
/* @0x2b94c0 beq 0x2b9500 <jpeg_std_error+0x540> */
/* @0x2b94c4 ldr r2, [r3, #0x8] */
/* @0x2b94c8 mov r1, r3 */
/* @0x2b94cc ldr r5, [r3, #0x4] */
/* @0x2b94d0 mov r0, r7 */
/* @0x2b94d4 ldr r6, [r3] */
/* @0x2b94d8 add r5, r5, r2 */
/* @0x2b94dc add r5, r5, #16 */
/* @0x2b94e0 mov r2, r5 */
/* @0x2b94e4 bl 0x2c1394 <jpeg_free_large> */
/* @0x2b94e8 ldr r2, [r4, #0x4c] */
/* @0x2b94ec cmp r6, #0 */
/* @0x2b94f0 mov r3, r6 */
/* @0x2b94f4 rsb r5, r5, r2 */
/* @0x2b94f8 str r5, [r4, #0x4c] */
/* @0x2b94fc bne 0x2b94c4 <jpeg_std_error+0x504> */
/* @0x2b9500 ldr r3, [r8, #0x34] */
/* @0x2b9504 mov r2, #0 */
/* @0x2b9508 str r2, [r8, #0x34] */
/* @0x2b950c cmp r3, r2 */
/* @0x2b9510 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x2b9514 ldr r2, [r3, #0x8] */
/* @0x2b9518 mov r1, r3 */
/* @0x2b951c ldr r5, [r3, #0x4] */
/* @0x2b9520 mov r0, r7 */
/* @0x2b9524 ldr r6, [r3] */
/* @0x2b9528 add r5, r5, r2 */
/* @0x2b952c add r5, r5, #16 */
/* @0x2b9530 mov r2, r5 */
/* @0x2b9534 bl 0x2c1384 <jpeg_free_small> */
/* @0x2b9538 ldr r2, [r4, #0x4c] */
/* @0x2b953c cmp r6, #0 */
/* @0x2b9540 mov r3, r6 */
/* @0x2b9544 rsb r5, r5, r2 */
/* @0x2b9548 str r5, [r4, #0x4c] */
/* @0x2b954c bne 0x2b9514 <jpeg_std_error+0x554> */
/* @0x2b9550 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2b9554 bne 0x2b94ac <jpeg_std_error+0x4ec> */
/* @0x2b9558 ldr r5, [r4, #0x44] */
/* @0x2b955c cmp r5, #0 */
/* @0x2b9560 movne r6, #0 */
/* @0x2b9564 bne 0x2b9578 <jpeg_std_error+0x5b8> */
/* @0x2b9568 b 0x2b95a4 <jpeg_std_error+0x5e4> */
/* @0x2b956c ldr r5, [r5, #0x24] */
/* @0x2b9570 cmp r5, #0 */
/* @0x2b9574 beq 0x2b95a4 <jpeg_std_error+0x5e4> */
/* @0x2b9578 ldrb r3, [r5, #0x22] */
/* @0x2b957c cmp r3, #0 */
/* @0x2b9580 beq 0x2b956c <jpeg_std_error+0x5ac> */
/* @0x2b9584 strb r6, [r5, #0x22] */
/* @0x2b9588 add r1, r5, #40 */
/* @0x2b958c ldr r3, [r5, #0x30] */
/* @0x2b9590 mov r0, r7 */
/* @0x2b9594 blx r3 */
/* @0x2b9598 ldr r5, [r5, #0x24] */
/* @0x2b959c cmp r5, #0 */
/* @0x2b95a0 bne 0x2b9578 <jpeg_std_error+0x5b8> */
/* @0x2b95a4 ldr r5, [r4, #0x48] */
/* @0x2b95a8 mov r6, #0 */
/* @0x2b95ac str r6, [r4, #0x44] */
/* @0x2b95b0 cmp r5, r6 */
/* @0x2b95b4 bne 0x2b95c8 <jpeg_std_error+0x608> */
/* @0x2b95b8 b 0x2b95f4 <jpeg_std_error+0x634> */
/* @0x2b95bc ldr r5, [r5, #0x24] */
/* @0x2b95c0 cmp r5, #0 */
/* @0x2b95c4 beq 0x2b95f4 <jpeg_std_error+0x634> */
/* @0x2b95c8 ldrb r3, [r5, #0x22] */
/* @0x2b95cc cmp r3, #0 */
/* @0x2b95d0 beq 0x2b95bc <jpeg_std_error+0x5fc> */
/* @0x2b95d4 strb r6, [r5, #0x22] */
/* @0x2b95d8 add r1, r5, #40 */
/* @0x2b95dc ldr r3, [r5, #0x30] */
/* @0x2b95e0 mov r0, r7 */
/* @0x2b95e4 blx r3 */
/* @0x2b95e8 ldr r5, [r5, #0x24] */
/* @0x2b95ec cmp r5, #0 */
/* @0x2b95f0 bne 0x2b95c8 <jpeg_std_error+0x608> */
/* @0x2b95f4 mov r3, #0 */
/* @0x2b95f8 str r3, [r4, #0x48] */
/* @0x2b95fc b 0x2b94ac <jpeg_std_error+0x4ec> */
/* @0x2b9600 push {r4, lr} */
/* @0x2b9604 mov r1, #1 */
/* @0x2b9608 mov r4, r0 */
/* @0x2b960c bl 0x2b9478 <jpeg_std_error+0x4b8> */
/* @0x2b9610 mov r0, r4 */
/* @0x2b9614 mov r1, #0 */
/* @0x2b9618 bl 0x2b9478 <jpeg_std_error+0x4b8> */
/* @0x2b961c mov r0, r4 */
/* @0x2b9620 ldr r1, [r4, #0x4] */
/* @0x2b9624 mov r2, #84 */
/* @0x2b9628 bl 0x2c1384 <jpeg_free_small> */
/* @0x2b962c mov r3, #0 */
/* @0x2b9630 mov r0, r4 */
/* @0x2b9634 str r3, [r4, #0x4] */
/* @0x2b9638 pop {r4, lr} */
/* @0x2b963c b 0x2c1438 <jpeg_mem_term> */
/* @0x2b9640 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b9644 mov r7, r2 */
/* @0x2b9648 ldr r2, [r1, #0x4] */
/* @0x2b964c add r6, r7, r3 */
/* @0x2b9650 mov r4, r1 */
/* @0x2b9654 mov r8, r0 */
/* @0x2b9658 cmp r6, r2 */
/* @0x2b965c ldrb r9, [sp, #0x20] */
/* @0x2b9660 bhi 0x2b9670 <jpeg_std_error+0x6b0> */
/* @0x2b9664 ldr r2, [r1, #0xc] */
/* @0x2b9668 cmp r3, r2 */
/* @0x2b966c bls 0x2b97c4 <jpeg_std_error+0x804> */
/* @0x2b9670 ldr r3, [r8] */
/* @0x2b9674 mov r2, #22 */
/* @0x2b9678 mov r0, r8 */
/* @0x2b967c str r2, [r3, #0x14] */
/* @0x2b9680 ldr r3, [r3] */
/* @0x2b9684 blx r3 */
/* @0x2b9688 ldr r3, [r4, #0x18] */
/* @0x2b968c cmp r7, r3 */
/* @0x2b9690 blo 0x2b96a4 <jpeg_std_error+0x6e4> */
/* @0x2b9694 ldr r2, [r4, #0x10] */
/* @0x2b9698 add r3, r3, r2 */
/* @0x2b969c cmp r6, r3 */
/* @0x2b96a0 bls 0x2b96e8 <jpeg_std_error+0x728> */
/* @0x2b96a4 ldrb r3, [r4, #0x22] */
/* @0x2b96a8 cmp r3, #0 */
/* @0x2b96ac beq 0x2b97fc <jpeg_std_error+0x83c> */
/* @0x2b96b0 ldrb r3, [r4, #0x21] */
/* @0x2b96b4 cmp r3, #0 */
/* @0x2b96b8 bne 0x2b97e0 <jpeg_std_error+0x820> */
/* @0x2b96bc ldr r3, [r4, #0x18] */
/* @0x2b96c0 mov r0, r8 */
/* @0x2b96c4 mov r1, r4 */
/* @0x2b96c8 mov r2, #0 */
/* @0x2b96cc cmp r7, r3 */
/* @0x2b96d0 strhi r7, [r4, #0x18] */
/* @0x2b96d4 ldrls r3, [r4, #0x10] */
/* @0x2b96d8 rsbls r3, r3, r6 */
/* @0x2b96dc bicls r3, r3, r3, asr #31 */
/* @0x2b96e0 strls r3, [r4, #0x18] */
/* @0x2b96e4 bl 0x2b9054 <jpeg_std_error+0x94> */
/* @0x2b96e8 ldr r5, [r4, #0x1c] */
/* @0x2b96ec cmp r6, r5 */
/* @0x2b96f0 bls 0x2b97a0 <jpeg_std_error+0x7e0> */
/* @0x2b96f4 cmp r7, r5 */
/* @0x2b96f8 bls 0x2b97d4 <jpeg_std_error+0x814> */
/* @0x2b96fc cmp r9, #0 */
/* @0x2b9700 moveq r5, r7 */
/* @0x2b9704 bne 0x2b9734 <jpeg_std_error+0x774> */
/* @0x2b9708 ldrb r3, [r4, #0x20] */
/* @0x2b970c cmp r3, #0 */
/* @0x2b9710 bne 0x2b9760 <jpeg_std_error+0x7a0> */
/* @0x2b9714 ldr r3, [r8] */
/* @0x2b9718 mov r0, r8 */
/* @0x2b971c mov r1, #22 */
/* @0x2b9720 ldr r2, [r3] */
/* @0x2b9724 str r1, [r3, #0x14] */
/* @0x2b9728 blx r2 */
/* @0x2b972c ldr r0, [r4, #0x18] */
/* @0x2b9730 b 0x2b97b4 <jpeg_std_error+0x7f4> */
/* @0x2b9734 ldr r3, [r8] */
/* @0x2b9738 mov r1, #22 */
/* @0x2b973c mov r0, r8 */
/* @0x2b9740 mov r5, r7 */
/* @0x2b9744 ldr r2, [r3] */
/* @0x2b9748 str r1, [r3, #0x14] */
/* @0x2b974c blx r2 */
/* @0x2b9750 ldrb r3, [r4, #0x20] */
/* @0x2b9754 str r6, [r4, #0x1c] */
/* @0x2b9758 cmp r3, #0 */
/* @0x2b975c beq 0x2b9818 <jpeg_std_error+0x858> */
/* @0x2b9760 ldr r0, [r4, #0x18] */
/* @0x2b9764 ldr r10, [r4, #0x8] */
/* @0x2b9768 rsb r5, r0, r5 */
/* @0x2b976c rsb r8, r0, r6 */
/* @0x2b9770 cmp r5, r8 */
/* @0x2b9774 lsl r10, r10, #7 */
/* @0x2b9778 bhs 0x2b97a4 <jpeg_std_error+0x7e4> */
/* @0x2b977c lsl r6, r5, #2 */
/* @0x2b9780 ldr r3, [r4] */
/* @0x2b9784 add r5, r5, #1 */
/* @0x2b9788 mov r1, r10 */
/* @0x2b978c ldr r0, [r3, r6] */
/* @0x2b9790 add r6, r6, #4 */
/* @0x2b9794 bl 0x2bc868 <jzero_far> */
/* @0x2b9798 cmp r8, r5 */
/* @0x2b979c bhi 0x2b9780 <jpeg_std_error+0x7c0> */
/* @0x2b97a0 ldr r0, [r4, #0x18] */
/* @0x2b97a4 cmp r9, #0 */
/* @0x2b97a8 beq 0x2b97b4 <jpeg_std_error+0x7f4> */
/* @0x2b97ac mov r3, #1 */
/* @0x2b97b0 strb r3, [r4, #0x21] */
/* @0x2b97b4 rsb r7, r0, r7 */
/* @0x2b97b8 ldr r3, [r4] */
/* @0x2b97bc add r0, r3, r7, lsl #2 */
/* @0x2b97c0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b97c4 ldr r3, [r1] */
/* @0x2b97c8 cmp r3, #0 */
/* @0x2b97cc bne 0x2b9688 <jpeg_std_error+0x6c8> */
/* @0x2b97d0 b 0x2b9670 <jpeg_std_error+0x6b0> */
/* @0x2b97d4 cmp r9, #0 */
/* @0x2b97d8 bne 0x2b9750 <jpeg_std_error+0x790> */
/* @0x2b97dc b 0x2b9708 <jpeg_std_error+0x748> */
/* @0x2b97e0 mov r0, r8 */
/* @0x2b97e4 mov r1, r4 */
/* @0x2b97e8 mov r2, #1 */
/* @0x2b97ec bl 0x2b9054 <jpeg_std_error+0x94> */
/* @0x2b97f0 mov r3, #0 */
/* @0x2b97f4 strb r3, [r4, #0x21] */
/* @0x2b97f8 b 0x2b96bc <jpeg_std_error+0x6fc> */
/* @0x2b97fc ldr r3, [r8] */
/* @0x2b9800 mov r2, #69 */
/* @0x2b9804 mov r0, r8 */
/* @0x2b9808 str r2, [r3, #0x14] */
/* @0x2b980c ldr r3, [r3] */
/* @0x2b9810 blx r3 */
/* @0x2b9814 b 0x2b96b0 <jpeg_std_error+0x6f0> */
/* @0x2b9818 ldr r0, [r4, #0x18] */
/* @0x2b981c b 0x2b97ac <jpeg_std_error+0x7ec> */
/* @0x2b9820 movw r3, #0xc9f0 */
/* @0x2b9824 movt r3, #0x3b9a */
/* @0x2b9828 cmp r2, r3 */
/* @0x2b982c push {r4, r5, r6, r7, r8, lr} */
/* @0x2b9830 mov r4, r2 */
/* @0x2b9834 mov r6, r0 */
/* @0x2b9838 mov r8, r1 */
/* @0x2b983c ldr r7, [r0, #0x4] */
/* @0x2b9840 bhi 0x2b98c0 <jpeg_std_error+0x900> */
/* @0x2b9844 ands r3, r4, #7 */
/* @0x2b9848 addne r4, r4, #8 */
/* @0x2b984c rsbne r4, r3, r4 */
/* @0x2b9850 cmp r8, #1 */
/* @0x2b9854 bls 0x2b9878 <jpeg_std_error+0x8b8> */
/* @0x2b9858 ldr r3, [r6] */
/* @0x2b985c mov r1, #14 */
/* @0x2b9860 mov r0, r6 */
/* @0x2b9864 str r8, [r3, #0x18] */
/* @0x2b9868 ldr r2, [r6] */
/* @0x2b986c str r1, [r3, #0x14] */
/* @0x2b9870 ldr r3, [r2] */
/* @0x2b9874 blx r3 */
/* @0x2b9878 mov r0, r6 */
/* @0x2b987c add r1, r4, #16 */
/* @0x2b9880 bl 0x2c138c <jpeg_get_large> */
/* @0x2b9884 subs r5, r0, #0 */
/* @0x2b9888 beq 0x2b98e4 <jpeg_std_error+0x924> */
/* @0x2b988c ldr r3, [r7, #0x4c] */
/* @0x2b9890 add r8, r7, r8, lsl #2 */
/* @0x2b9894 mov r2, #0 */
/* @0x2b9898 add r0, r5, #16 */
/* @0x2b989c add r3, r3, #16 */
/* @0x2b98a0 add r3, r3, r4 */
/* @0x2b98a4 str r3, [r7, #0x4c] */
/* @0x2b98a8 ldr r3, [r8, #0x3c] */
/* @0x2b98ac str r4, [r5, #0x4] */
/* @0x2b98b0 str r2, [r5, #0x8] */
/* @0x2b98b4 str r3, [r5] */
/* @0x2b98b8 str r5, [r8, #0x3c] */
/* @0x2b98bc pop {r4, r5, r6, r7, r8, pc} */
/* @0x2b98c0 ldr r3, [r0] */
/* @0x2b98c4 mov r2, #3 */
/* @0x2b98c8 mov r1, #54 */
/* @0x2b98cc str r2, [r3, #0x18] */
/* @0x2b98d0 ldr r2, [r0] */
/* @0x2b98d4 str r1, [r3, #0x14] */
/* @0x2b98d8 ldr r3, [r2] */
/* @0x2b98dc blx r3 */
/* @0x2b98e0 b 0x2b9844 <jpeg_std_error+0x884> */
/* @0x2b98e4 ldr r3, [r6] */
/* @0x2b98e8 mov r2, #4 */
/* @0x2b98ec mov r1, #54 */
/* @0x2b98f0 mov r0, r6 */
/* @0x2b98f4 str r2, [r3, #0x18] */
/* @0x2b98f8 ldr r2, [r6] */
/* @0x2b98fc str r1, [r3, #0x14] */
/* @0x2b9900 ldr r3, [r2] */
/* @0x2b9904 blx r3 */
/* @0x2b9908 b 0x2b988c <jpeg_std_error+0x8cc> */
/* @0x2b990c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b9910 lsl r4, r2, #7 */
/* @0x2b9914 mov r7, r0 */
/* @0x2b9918 mov r8, r1 */
/* @0x2b991c movw r0, #0xc9f0 */
/* @0x2b9920 mov r1, r4 */
/* @0x2b9924 movt r0, #0x3b9a */
/* @0x2b9928 mov r9, r3 */
/* @0x2b992c bl 0x318c48 <__udivsi3> */
/* @0x2b9930 ldr r5, [r7, #0x4] */
/* @0x2b9934 subs r6, r0, #0 */
/* @0x2b9938 beq 0x2b99b8 <jpeg_std_error+0x9f8> */
/* @0x2b993c cmp r6, r9 */
/* @0x2b9940 movge r6, r9 */
/* @0x2b9944 mov r0, r7 */
/* @0x2b9948 str r6, [r5, #0x50] */
/* @0x2b994c mov r1, r8 */
/* @0x2b9950 lsl r2, r9, #2 */
/* @0x2b9954 bl 0x2b91d0 <jpeg_std_error+0x210> */
/* @0x2b9958 cmp r9, #0 */
/* @0x2b995c mov r10, r0 */
/* @0x2b9960 beq 0x2b99b0 <jpeg_std_error+0x9f0> */
/* @0x2b9964 mov r5, #0 */
/* @0x2b9968 rsb r3, r5, r9 */
/* @0x2b996c mov r0, r7 */
/* @0x2b9970 cmp r6, r3 */
/* @0x2b9974 movhs r6, r3 */
/* @0x2b9978 mov r1, r8 */
/* @0x2b997c mul r2, r4, r6 */
/* @0x2b9980 bl 0x2b9820 <jpeg_std_error+0x860> */
/* @0x2b9984 cmp r6, #0 */
/* @0x2b9988 beq 0x2b99a8 <jpeg_std_error+0x9e8> */
/* @0x2b998c add r12, r10, r5, lsl #2 */
/* @0x2b9990 add r5, r5, r6 */
/* @0x2b9994 add r2, r10, r5, lsl #2 */
/* @0x2b9998 str r0, [r12], #4 */
/* @0x2b999c cmp r12, r2 */
/* @0x2b99a0 add r0, r0, r4 */
/* @0x2b99a4 bne 0x2b9998 <jpeg_std_error+0x9d8> */
/* @0x2b99a8 cmp r9, r5 */
/* @0x2b99ac bhi 0x2b9968 <jpeg_std_error+0x9a8> */
/* @0x2b99b0 mov r0, r10 */
/* @0x2b99b4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b99b8 ldr r3, [r7] */
/* @0x2b99bc mov r2, #70 */
/* @0x2b99c0 mov r0, r7 */
/* @0x2b99c4 str r2, [r3, #0x14] */
/* @0x2b99c8 ldr r3, [r3] */
/* @0x2b99cc blx r3 */
/* @0x2b99d0 b 0x2b993c <jpeg_std_error+0x97c> */
/* @0x2b99d4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2b99d8 mov r7, r0 */
/* @0x2b99dc mov r8, r1 */
/* @0x2b99e0 movw r0, #0xc9f0 */
/* @0x2b99e4 mov r1, r2 */
/* @0x2b99e8 movt r0, #0x3b9a */
/* @0x2b99ec mov r4, r2 */
/* @0x2b99f0 mov r9, r3 */
/* @0x2b99f4 bl 0x318c48 <__udivsi3> */
/* @0x2b99f8 ldr r5, [r7, #0x4] */
/* @0x2b99fc subs r6, r0, #0 */
/* @0x2b9a00 beq 0x2b9a80 <jpeg_std_error+0xac0> */
/* @0x2b9a04 cmp r6, r9 */
/* @0x2b9a08 movge r6, r9 */
/* @0x2b9a0c mov r0, r7 */
/* @0x2b9a10 str r6, [r5, #0x50] */
/* @0x2b9a14 mov r1, r8 */
/* @0x2b9a18 lsl r2, r9, #2 */
/* @0x2b9a1c bl 0x2b91d0 <jpeg_std_error+0x210> */
/* @0x2b9a20 cmp r9, #0 */
/* @0x2b9a24 mov r10, r0 */
/* @0x2b9a28 beq 0x2b9a78 <jpeg_std_error+0xab8> */
/* @0x2b9a2c mov r5, #0 */
/* @0x2b9a30 rsb r3, r5, r9 */
/* @0x2b9a34 mov r0, r7 */
/* @0x2b9a38 cmp r6, r3 */
/* @0x2b9a3c movhs r6, r3 */
/* @0x2b9a40 mov r1, r8 */
/* @0x2b9a44 mul r2, r4, r6 */
/* @0x2b9a48 bl 0x2b9820 <jpeg_std_error+0x860> */
/* @0x2b9a4c cmp r6, #0 */
/* @0x2b9a50 beq 0x2b9a70 <jpeg_std_error+0xab0> */
/* @0x2b9a54 add r12, r10, r5, lsl #2 */
/* @0x2b9a58 add r5, r5, r6 */
/* @0x2b9a5c add r2, r10, r5, lsl #2 */
/* @0x2b9a60 str r0, [r12], #4 */
/* @0x2b9a64 cmp r12, r2 */
/* @0x2b9a68 add r0, r0, r4 */
/* @0x2b9a6c bne 0x2b9a60 <jpeg_std_error+0xaa0> */
/* @0x2b9a70 cmp r9, r5 */
/* @0x2b9a74 bhi 0x2b9a30 <jpeg_std_error+0xa70> */
/* @0x2b9a78 mov r0, r10 */
/* @0x2b9a7c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b9a80 ldr r3, [r7] */
/* @0x2b9a84 mov r2, #70 */
/* @0x2b9a88 mov r0, r7 */
/* @0x2b9a8c str r2, [r3, #0x14] */
/* @0x2b9a90 ldr r3, [r3] */
/* @0x2b9a94 blx r3 */
/* @0x2b9a98 b 0x2b9a04 <jpeg_std_error+0xa44> */
/* @0x2b9a9c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b9aa0 mov r6, r0 */
/* @0x2b9aa4 ldr r5, [r0, #0x4] */
/* @0x2b9aa8 ldr r3, [r5, #0x44] */
/* @0x2b9aac cmp r3, #0 */
/* @0x2b9ab0 beq 0x2b9ce8 <jpeg_std_error+0xd28> */
/* @0x2b9ab4 mov r4, #0 */
/* @0x2b9ab8 mov r7, r4 */
/* @0x2b9abc ldr r12, [r3] */
/* @0x2b9ac0 cmp r12, #0 */
/* @0x2b9ac4 ldreq r2, [r3, #0x8] */
/* @0x2b9ac8 ldreq r0, [r3, #0xc] */
/* @0x2b9acc ldreq r1, [r3, #0x4] */
/* @0x2b9ad0 ldr r3, [r3, #0x24] */
/* @0x2b9ad4 mlaeq r7, r0, r2, r7 */
/* @0x2b9ad8 mlaeq r4, r1, r2, r4 */
/* @0x2b9adc cmp r3, #0 */
/* @0x2b9ae0 bne 0x2b9abc <jpeg_std_error+0xafc> */
/* @0x2b9ae4 ldr r3, [r5, #0x48] */
/* @0x2b9ae8 cmp r3, #0 */
/* @0x2b9aec bne 0x2b9b00 <jpeg_std_error+0xb40> */
/* @0x2b9af0 b 0x2b9b34 <jpeg_std_error+0xb74> */
/* @0x2b9af4 ldr r3, [r3, #0x24] */
/* @0x2b9af8 cmp r3, #0 */
/* @0x2b9afc beq 0x2b9b34 <jpeg_std_error+0xb74> */
/* @0x2b9b00 ldr r12, [r3] */
/* @0x2b9b04 cmp r12, #0 */
/* @0x2b9b08 bne 0x2b9af4 <jpeg_std_error+0xb34> */
/* @0x2b9b0c ldr r2, [r3, #0x8] */
/* @0x2b9b10 ldr r1, [r3, #0xc] */
/* @0x2b9b14 ldr r0, [r3, #0x4] */
/* @0x2b9b18 ldr r3, [r3, #0x24] */
/* @0x2b9b1c mul r1, r1, r2 */
/* @0x2b9b20 cmp r3, #0 */
/* @0x2b9b24 mul r2, r0, r2 */
/* @0x2b9b28 add r7, r7, r1, lsl #7 */
/* @0x2b9b2c add r4, r4, r2, lsl #7 */
/* @0x2b9b30 bne 0x2b9b00 <jpeg_std_error+0xb40> */
/* @0x2b9b34 cmp r7, #0 */
/* @0x2b9b38 pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b9b3c mov r0, r6 */
/* @0x2b9b40 mov r1, r7 */
/* @0x2b9b44 mov r2, r4 */
/* @0x2b9b48 ldr r3, [r5, #0x4c] */
/* @0x2b9b4c bl 0x2c139c <jpeg_mem_available> */
/* @0x2b9b50 cmp r0, r4 */
/* @0x2b9b54 movge r8, #51712 */
/* @0x2b9b58 movtge r8, #0x3b9a */
/* @0x2b9b5c blt 0x2b9c7c <jpeg_std_error+0xcbc> */
/* @0x2b9b60 ldr r4, [r5, #0x44] */
/* @0x2b9b64 cmp r4, #0 */
/* @0x2b9b68 movne r10, #1 */
/* @0x2b9b6c movne r9, #0 */
/* @0x2b9b70 bne 0x2b9b84 <jpeg_std_error+0xbc4> */
/* @0x2b9b74 b 0x2b9bec <jpeg_std_error+0xc2c> */
/* @0x2b9b78 ldr r4, [r4, #0x24] */
/* @0x2b9b7c cmp r4, #0 */
/* @0x2b9b80 beq 0x2b9bec <jpeg_std_error+0xc2c> */
/* @0x2b9b84 ldr r3, [r4] */
/* @0x2b9b88 cmp r3, #0 */
/* @0x2b9b8c bne 0x2b9b78 <jpeg_std_error+0xbb8> */
/* @0x2b9b90 ldr r11, [r4, #0xc] */
/* @0x2b9b94 ldr r7, [r4, #0x4] */
/* @0x2b9b98 mov r1, r11 */
/* @0x2b9b9c sub r0, r7, #1 */
/* @0x2b9ba0 bl 0x318c48 <__udivsi3> */
/* @0x2b9ba4 mov r3, r7 */
/* @0x2b9ba8 add r0, r0, #1 */
/* @0x2b9bac cmp r8, r0 */
/* @0x2b9bb0 strge r7, [r4, #0x10] */
/* @0x2b9bb4 blt 0x2b9cc0 <jpeg_std_error+0xd00> */
/* @0x2b9bb8 ldr r2, [r4, #0x8] */
/* @0x2b9bbc mov r1, #1 */
/* @0x2b9bc0 mov r0, r6 */
/* @0x2b9bc4 bl 0x2b99d4 <jpeg_std_error+0xa14> */
/* @0x2b9bc8 ldr r3, [r5, #0x50] */
/* @0x2b9bcc str r9, [r4, #0x18] */
/* @0x2b9bd0 str r9, [r4, #0x1c] */
/* @0x2b9bd4 str r3, [r4, #0x14] */
/* @0x2b9bd8 strb r9, [r4, #0x21] */
/* @0x2b9bdc str r0, [r4] */
/* @0x2b9be0 ldr r4, [r4, #0x24] */
/* @0x2b9be4 cmp r4, #0 */
/* @0x2b9be8 bne 0x2b9b84 <jpeg_std_error+0xbc4> */
/* @0x2b9bec ldr r4, [r5, #0x48] */
/* @0x2b9bf0 cmp r4, #0 */
/* @0x2b9bf4 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b9bf8 mov r10, #1 */
/* @0x2b9bfc mov r9, #0 */
/* @0x2b9c00 b 0x2b9c10 <jpeg_std_error+0xc50> */
/* @0x2b9c04 ldr r4, [r4, #0x24] */
/* @0x2b9c08 cmp r4, #0 */
/* @0x2b9c0c beq 0x2b9c78 <jpeg_std_error+0xcb8> */
/* @0x2b9c10 ldr r3, [r4] */
/* @0x2b9c14 cmp r3, #0 */
/* @0x2b9c18 bne 0x2b9c04 <jpeg_std_error+0xc44> */
/* @0x2b9c1c ldr r11, [r4, #0xc] */
/* @0x2b9c20 ldr r7, [r4, #0x4] */
/* @0x2b9c24 mov r1, r11 */
/* @0x2b9c28 sub r0, r7, #1 */
/* @0x2b9c2c bl 0x318c48 <__udivsi3> */
/* @0x2b9c30 mov r3, r7 */
/* @0x2b9c34 add r0, r0, #1 */
/* @0x2b9c38 cmp r8, r0 */
/* @0x2b9c3c strge r7, [r4, #0x10] */
/* @0x2b9c40 blt 0x2b9c94 <jpeg_std_error+0xcd4> */
/* @0x2b9c44 ldr r2, [r4, #0x8] */
/* @0x2b9c48 mov r1, #1 */
/* @0x2b9c4c mov r0, r6 */
/* @0x2b9c50 bl 0x2b990c <jpeg_std_error+0x94c> */
/* @0x2b9c54 ldr r3, [r5, #0x50] */
/* @0x2b9c58 str r9, [r4, #0x18] */
/* @0x2b9c5c str r9, [r4, #0x1c] */
/* @0x2b9c60 str r3, [r4, #0x14] */
/* @0x2b9c64 strb r9, [r4, #0x21] */
/* @0x2b9c68 str r0, [r4] */
/* @0x2b9c6c ldr r4, [r4, #0x24] */
/* @0x2b9c70 cmp r4, #0 */
/* @0x2b9c74 bne 0x2b9c10 <jpeg_std_error+0xc50> */
/* @0x2b9c78 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b9c7c mov r1, r7 */
/* @0x2b9c80 bl 0x318d10 <__divsi3> */
/* @0x2b9c84 cmp r0, #1 */
/* @0x2b9c88 movge r8, r0 */
/* @0x2b9c8c movlt r8, #1 */
/* @0x2b9c90 b 0x2b9b60 <jpeg_std_error+0xba0> */
/* @0x2b9c94 ldr r2, [r4, #0x8] */
/* @0x2b9c98 mov r0, r6 */
/* @0x2b9c9c mul r11, r11, r8 */
/* @0x2b9ca0 add r1, r4, #40 */
/* @0x2b9ca4 mul r2, r2, r7 */
/* @0x2b9ca8 str r11, [r4, #0x10] */
/* @0x2b9cac lsl r2, r2, #7 */
/* @0x2b9cb0 bl 0x2c13ac <jpeg_open_backing_store> */
/* @0x2b9cb4 ldr r3, [r4, #0x10] */
/* @0x2b9cb8 strb r10, [r4, #0x22] */
/* @0x2b9cbc b 0x2b9c44 <jpeg_std_error+0xc84> */
/* @0x2b9cc0 mul r11, r11, r8 */
/* @0x2b9cc4 ldr r2, [r4, #0x8] */
/* @0x2b9cc8 mov r0, r6 */
/* @0x2b9ccc add r1, r4, #40 */
/* @0x2b9cd0 mul r2, r2, r7 */
/* @0x2b9cd4 str r11, [r4, #0x10] */
/* @0x2b9cd8 bl 0x2c13ac <jpeg_open_backing_store> */
/* @0x2b9cdc ldr r3, [r4, #0x10] */
/* @0x2b9ce0 strb r10, [r4, #0x22] */
/* @0x2b9ce4 b 0x2b9bb8 <jpeg_std_error+0xbf8> */
/* @0x2b9ce8 mov r4, r3 */
/* @0x2b9cec mov r7, r3 */
/* @0x2b9cf0 b 0x2b9ae4 <jpeg_std_error+0xb24> */
/* @0x2b9cf4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2b9cf8 sub sp, sp, #28 */
/* @0x2b9cfc mov r8, r2 */
/* @0x2b9d00 ldr r2, [r1, #0x4] */
/* @0x2b9d04 add r9, r8, r3 */
/* @0x2b9d08 ldrb r11, [sp, #0x40] */
/* @0x2b9d0c cmp r9, r2 */
/* @0x2b9d10 mov r4, r1 */
/* @0x2b9d14 mov r6, r0 */
/* @0x2b9d18 str r11, [sp, #0x10] */
/* @0x2b9d1c bhi 0x2b9d2c <jpeg_std_error+0xd6c> */
/* @0x2b9d20 ldr r2, [r1, #0xc] */
/* @0x2b9d24 cmp r3, r2 */
/* @0x2b9d28 bls 0x2b9f44 <jpeg_std_error+0xf84> */
/* @0x2b9d2c ldr r3, [r6] */
/* @0x2b9d30 mov r2, #22 */
/* @0x2b9d34 mov r0, r6 */
/* @0x2b9d38 str r2, [r3, #0x14] */
/* @0x2b9d3c ldr r3, [r3] */
/* @0x2b9d40 blx r3 */
/* @0x2b9d44 ldr r2, [r4, #0x18] */
/* @0x2b9d48 cmp r8, r2 */
/* @0x2b9d4c blo 0x2b9d60 <jpeg_std_error+0xda0> */
/* @0x2b9d50 ldr r3, [r4, #0x10] */
/* @0x2b9d54 add r3, r2, r3 */
/* @0x2b9d58 cmp r9, r3 */
/* @0x2b9d5c bls 0x2b9e60 <jpeg_std_error+0xea0> */
/* @0x2b9d60 ldrb r3, [r4, #0x22] */
/* @0x2b9d64 cmp r3, #0 */
/* @0x2b9d68 beq 0x2ba068 <jpeg_std_error+0x10a8> */
/* @0x2b9d6c ldrb r3, [r4, #0x21] */
/* @0x2b9d70 cmp r3, #0 */
/* @0x2b9d74 bne 0x2b9f64 <jpeg_std_error+0xfa4> */
/* @0x2b9d78 ldr r7, [r4, #0x8] */
/* @0x2b9d7c ldr r1, [r4, #0x10] */
/* @0x2b9d80 ldr r0, [r4, #0x1c] */
/* @0x2b9d84 mov r10, r7 */
/* @0x2b9d88 cmp r8, r2 */
/* @0x2b9d8c strhi r8, [r4, #0x18] */
/* @0x2b9d90 rsbls r11, r1, r9 */
/* @0x2b9d94 bicls r11, r11, r11, asr #31 */
/* @0x2b9d98 movhi r11, r8 */
/* @0x2b9d9c strls r11, [r4, #0x18] */
/* @0x2b9da0 cmp r1, #0 */
/* @0x2b9da4 mul r7, r7, r11 */
/* @0x2b9da8 ble 0x2b9e64 <jpeg_std_error+0xea4> */
/* @0x2b9dac ldr r12, [r4, #0x14] */
/* @0x2b9db0 rsb r3, r11, r0 */
/* @0x2b9db4 ldr r2, [r4, #0x4] */
/* @0x2b9db8 cmp r1, r12 */
/* @0x2b9dbc movge r1, r12 */
/* @0x2b9dc0 rsb r11, r11, r2 */
/* @0x2b9dc4 cmp r1, r11 */
/* @0x2b9dc8 movge r1, r11 */
/* @0x2b9dcc cmp r1, r3 */
/* @0x2b9dd0 movge r1, r3 */
/* @0x2b9dd4 cmp r1, #0 */
/* @0x2b9dd8 ble 0x2b9e64 <jpeg_std_error+0xea4> */
/* @0x2b9ddc add r11, r4, #40 */
/* @0x2b9de0 mov r5, #0 */
/* @0x2b9de4 b 0x2b9e20 <jpeg_std_error+0xe60> */
/* @0x2b9de8 ldr r3, [r4, #0x18] */
/* @0x2b9dec cmp r2, r1 */
/* @0x2b9df0 movge r2, r1 */
/* @0x2b9df4 ldr r0, [r4, #0x1c] */
/* @0x2b9df8 add r3, r5, r3 */
/* @0x2b9dfc ldr r12, [r4, #0x4] */
/* @0x2b9e00 rsb r1, r3, r0 */
/* @0x2b9e04 cmp r1, r2 */
/* @0x2b9e08 movge r1, r2 */
/* @0x2b9e0c rsb r3, r3, r12 */
/* @0x2b9e10 cmp r1, r3 */
/* @0x2b9e14 movge r1, r3 */
/* @0x2b9e18 cmp r1, #0 */
/* @0x2b9e1c ble 0x2b9e64 <jpeg_std_error+0xea4> */
/* @0x2b9e20 mul lr, r10, r1 */
/* @0x2b9e24 ldr r2, [r4] */
/* @0x2b9e28 mov r3, r7 */
/* @0x2b9e2c ldr r12, [r4, #0x28] */
/* @0x2b9e30 mov r1, r11 */
/* @0x2b9e34 mov r0, r6 */
/* @0x2b9e38 ldr r2, [r2, r5, lsl #2] */
/* @0x2b9e3c add r7, r7, lr */
/* @0x2b9e40 str lr, [sp] */
/* @0x2b9e44 blx r12 */
/* @0x2b9e48 ldr r2, [r4, #0x14] */
/* @0x2b9e4c ldr r3, [r4, #0x10] */
/* @0x2b9e50 add r5, r2, r5 */
/* @0x2b9e54 cmp r3, r5 */
/* @0x2b9e58 rsb r1, r5, r3 */
/* @0x2b9e5c bgt 0x2b9de8 <jpeg_std_error+0xe28> */
/* @0x2b9e60 ldr r0, [r4, #0x1c] */
/* @0x2b9e64 cmp r9, r0 */
/* @0x2b9e68 bls 0x2b9f18 <jpeg_std_error+0xf58> */
/* @0x2b9e6c cmp r8, r0 */
/* @0x2b9e70 bls 0x2b9f54 <jpeg_std_error+0xf94> */
/* @0x2b9e74 ldr r12, [sp, #0x10] */
/* @0x2b9e78 cmp r12, #0 */
/* @0x2b9e7c moveq r0, r8 */
/* @0x2b9e80 bne 0x2b9eb0 <jpeg_std_error+0xef0> */
/* @0x2b9e84 ldrb r3, [r4, #0x20] */
/* @0x2b9e88 cmp r3, #0 */
/* @0x2b9e8c bne 0x2b9edc <jpeg_std_error+0xf1c> */
/* @0x2b9e90 ldr r3, [r6] */
/* @0x2b9e94 mov r0, r6 */
/* @0x2b9e98 mov r1, #22 */
/* @0x2b9e9c ldr r2, [r3] */
/* @0x2b9ea0 str r1, [r3, #0x14] */
/* @0x2b9ea4 blx r2 */
/* @0x2b9ea8 ldr r0, [r4, #0x18] */
/* @0x2b9eac b 0x2b9f30 <jpeg_std_error+0xf70> */
/* @0x2b9eb0 ldr r3, [r6] */
/* @0x2b9eb4 mov r0, r6 */
/* @0x2b9eb8 mov r1, #22 */
/* @0x2b9ebc ldr r2, [r3] */
/* @0x2b9ec0 str r1, [r3, #0x14] */
/* @0x2b9ec4 blx r2 */
/* @0x2b9ec8 mov r0, r8 */
/* @0x2b9ecc ldrb r3, [r4, #0x20] */
/* @0x2b9ed0 str r9, [r4, #0x1c] */
/* @0x2b9ed4 cmp r3, #0 */
/* @0x2b9ed8 beq 0x2ba088 <jpeg_std_error+0x10c8> */
/* @0x2b9edc ldr r3, [r4, #0x18] */
/* @0x2b9ee0 ldr r7, [r4, #0x8] */
/* @0x2b9ee4 rsb r5, r3, r0 */
/* @0x2b9ee8 rsb r9, r3, r9 */
/* @0x2b9eec cmp r5, r9 */
/* @0x2b9ef0 bhs 0x2ba0ac <jpeg_std_error+0x10ec> */
/* @0x2b9ef4 lsl r6, r5, #2 */
/* @0x2b9ef8 ldr r3, [r4] */
/* @0x2b9efc add r5, r5, #1 */
/* @0x2b9f00 mov r1, r7 */
/* @0x2b9f04 ldr r0, [r3, r6] */
/* @0x2b9f08 add r6, r6, #4 */
/* @0x2b9f0c bl 0x2bc868 <jzero_far> */
/* @0x2b9f10 cmp r9, r5 */
/* @0x2b9f14 bhi 0x2b9ef8 <jpeg_std_error+0xf38> */
/* @0x2b9f18 ldr r0, [r4, #0x18] */
/* @0x2b9f1c ldr r12, [sp, #0x10] */
/* @0x2b9f20 cmp r12, #0 */
/* @0x2b9f24 beq 0x2b9f30 <jpeg_std_error+0xf70> */
/* @0x2b9f28 mov r3, #1 */
/* @0x2b9f2c strb r3, [r4, #0x21] */
/* @0x2b9f30 rsb r8, r0, r8 */
/* @0x2b9f34 ldr r3, [r4] */
/* @0x2b9f38 add r0, r3, r8, lsl #2 */
/* @0x2b9f3c add sp, sp, #28 */
/* @0x2b9f40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b9f44 ldr r3, [r1] */
/* @0x2b9f48 cmp r3, #0 */
/* @0x2b9f4c bne 0x2b9d44 <jpeg_std_error+0xd84> */
/* @0x2b9f50 b 0x2b9d2c <jpeg_std_error+0xd6c> */
/* @0x2b9f54 ldr r11, [sp, #0x10] */
/* @0x2b9f58 cmp r11, #0 */
/* @0x2b9f5c bne 0x2b9ecc <jpeg_std_error+0xf0c> */
/* @0x2b9f60 b 0x2b9e84 <jpeg_std_error+0xec4> */
/* @0x2b9f64 ldr r1, [r4, #0x10] */
/* @0x2b9f68 ldr r10, [r4, #0x8] */
/* @0x2b9f6c cmp r1, #0 */
/* @0x2b9f70 mul r7, r10, r2 */
/* @0x2b9f74 ldrle r0, [r4, #0x1c] */
/* @0x2b9f78 movle r7, r10 */
/* @0x2b9f7c ble 0x2ba05c <jpeg_std_error+0x109c> */
/* @0x2b9f80 ldr r12, [r4, #0x14] */
/* @0x2b9f84 ldr r3, [r4, #0x4] */
/* @0x2b9f88 ldr r0, [r4, #0x1c] */
/* @0x2b9f8c cmp r12, r1 */
/* @0x2b9f90 movge r12, r1 */
/* @0x2b9f94 rsb r3, r2, r3 */
/* @0x2b9f98 cmp r12, r3 */
/* @0x2b9f9c movge r12, r3 */
/* @0x2b9fa0 rsb r3, r2, r0 */
/* @0x2b9fa4 cmp r12, r3 */
/* @0x2b9fa8 movge r12, r3 */
/* @0x2b9fac cmp r12, #0 */
/* @0x2b9fb0 ble 0x2ba0a4 <jpeg_std_error+0x10e4> */
/* @0x2b9fb4 add r2, r4, #40 */
/* @0x2b9fb8 str r9, [sp, #0x14] */
/* @0x2b9fbc str r2, [sp, #0xc] */
/* @0x2b9fc0 mov r5, #0 */
/* @0x2b9fc4 mov r9, r2 */
/* @0x2b9fc8 b 0x2ba004 <jpeg_std_error+0x1044> */
/* @0x2b9fcc ldr r2, [r4, #0x18] */
/* @0x2b9fd0 cmp r11, r1 */
/* @0x2b9fd4 movge r11, r1 */
/* @0x2b9fd8 ldr r0, [r4, #0x1c] */
/* @0x2b9fdc add r1, r2, r5 */
/* @0x2b9fe0 rsb r12, r1, r0 */
/* @0x2b9fe4 cmp r12, r11 */
/* @0x2b9fe8 movge r12, r11 */
/* @0x2b9fec ldr r11, [r4, #0x4] */
/* @0x2b9ff0 rsb r1, r1, r11 */
/* @0x2b9ff4 cmp r12, r1 */
/* @0x2b9ff8 movge r12, r1 */
/* @0x2b9ffc cmp r12, #0 */
/* @0x2ba000 ble 0x2ba090 <jpeg_std_error+0x10d0> */
/* @0x2ba004 mul r12, r12, r10 */
/* @0x2ba008 ldr r2, [r4] */
/* @0x2ba00c ldr r11, [r4, #0x2c] */
/* @0x2ba010 mov r3, r7 */
/* @0x2ba014 mov r1, r9 */
/* @0x2ba018 mov r0, r6 */
/* @0x2ba01c ldr r2, [r2, r5, lsl #2] */
/* @0x2ba020 add r7, r7, r12 */
/* @0x2ba024 str r12, [sp] */
/* @0x2ba028 blx r11 */
/* @0x2ba02c ldr r1, [r4, #0x14] */
/* @0x2ba030 ldr r3, [r4, #0x10] */
/* @0x2ba034 add r5, r1, r5 */
/* @0x2ba038 cmp r3, r5 */
/* @0x2ba03c rsb r11, r5, r3 */
/* @0x2ba040 bgt 0x2b9fcc <jpeg_std_error+0x100c> */
/* @0x2ba044 ldr r7, [r4, #0x8] */
/* @0x2ba048 mov r1, r3 */
/* @0x2ba04c ldr r9, [sp, #0x14] */
/* @0x2ba050 ldr r2, [r4, #0x18] */
/* @0x2ba054 ldr r0, [r4, #0x1c] */
/* @0x2ba058 mov r10, r7 */
/* @0x2ba05c mov r3, #0 */
/* @0x2ba060 strb r3, [r4, #0x21] */
/* @0x2ba064 b 0x2b9d88 <jpeg_std_error+0xdc8> */
/* @0x2ba068 ldr r3, [r6] */
/* @0x2ba06c mov r2, #69 */
/* @0x2ba070 mov r0, r6 */
/* @0x2ba074 str r2, [r3, #0x14] */
/* @0x2ba078 ldr r3, [r3] */
/* @0x2ba07c blx r3 */
/* @0x2ba080 ldr r2, [r4, #0x18] */
/* @0x2ba084 b 0x2b9d6c <jpeg_std_error+0xdac> */
/* @0x2ba088 ldr r0, [r4, #0x18] */
/* @0x2ba08c b 0x2b9f28 <jpeg_std_error+0xf68> */
/* @0x2ba090 ldr r7, [r4, #0x8] */
/* @0x2ba094 mov r1, r3 */
/* @0x2ba098 ldr r9, [sp, #0x14] */
/* @0x2ba09c mov r10, r7 */
/* @0x2ba0a0 b 0x2ba05c <jpeg_std_error+0x109c> */
/* @0x2ba0a4 mov r7, r10 */
/* @0x2ba0a8 b 0x2ba05c <jpeg_std_error+0x109c> */
/* @0x2ba0ac mov r0, r3 */
/* @0x2ba0b0 b 0x2b9f1c <jpeg_std_error+0xf5c> */

/* ── FUNC 0x2ba0b4 · jinit_memory_mgr · size=436 · insn=109 */
/* @0x2ba0b4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ba0b8 mov r3, #0 */
/* @0x2ba0bc sub sp, sp, #12 */
/* @0x2ba0c0 str r3, [r0, #0x4] */
/* @0x2ba0c4 mov r5, r0 */
/* @0x2ba0c8 bl 0x2c142c <jpeg_mem_init> */
/* @0x2ba0cc mov r1, #84 */
/* @0x2ba0d0 str r0, [sp, #0x4] */
/* @0x2ba0d4 mov r0, r5 */
/* @0x2ba0d8 bl 0x2c137c <jpeg_get_small> */
/* @0x2ba0dc subs r4, r0, #0 */
/* @0x2ba0e0 beq 0x2ba208 <jinit_memory_mgr+0x154> */
/* @0x2ba0e4 ldr r11, [pc, #0x148] */
/* @0x2ba0e8 mov r2, #51712 */
/* @0x2ba0ec ldr r0, [pc, #0x144] */
/* @0x2ba0f0 movt r2, #0x3b9a */
/* @0x2ba0f4 add r11, pc, r11 */
/* @0x2ba0f8 str r11, [r4] */
/* @0x2ba0fc ldr r11, [sp, #0x4] */
/* @0x2ba100 add r0, pc, r0 */
/* @0x2ba104 str r2, [r4, #0x30] */
/* @0x2ba108 mov r3, #0 */
/* @0x2ba10c str r0, [r4, #0x20] */
/* @0x2ba110 ldr r10, [pc, #0x124] */
/* @0x2ba114 ldr r9, [pc, #0x124] */
/* @0x2ba118 ldr r8, [pc, #0x124] */
/* @0x2ba11c add r10, pc, r10 */
/* @0x2ba120 ldr r7, [pc, #0x120] */
/* @0x2ba124 add r9, pc, r9 */
/* @0x2ba128 ldr r6, [pc, #0x11c] */
/* @0x2ba12c add r8, pc, r8 */
/* @0x2ba130 ldr lr, [pc, #0x118] */
/* @0x2ba134 add r7, pc, r7 */
/* @0x2ba138 ldr r12, [pc, #0x114] */
/* @0x2ba13c add r6, pc, r6 */
/* @0x2ba140 ldr r1, [pc, #0x110] */
/* @0x2ba144 add lr, pc, lr */
/* @0x2ba148 ldr r2, [pc, #0x10c] */
/* @0x2ba14c add r12, pc, r12 */
/* @0x2ba150 ldr r0, [pc, #0x108] */
/* @0x2ba154 add r1, pc, r1 */
/* @0x2ba158 str r3, [r4, #0x38] */
/* @0x2ba15c add r2, pc, r2 */
/* @0x2ba160 str r3, [r4, #0x40] */
/* @0x2ba164 add r0, pc, r0 */
/* @0x2ba168 str r3, [r4, #0x34] */
/* @0x2ba16c str r3, [r4, #0x3c] */
/* @0x2ba170 str r3, [r4, #0x44] */
/* @0x2ba174 str r3, [r4, #0x48] */
/* @0x2ba178 mov r3, #84 */
/* @0x2ba17c str r10, [r4, #0x4] */
/* @0x2ba180 str r9, [r4, #0x8] */
/* @0x2ba184 str r8, [r4, #0xc] */
/* @0x2ba188 str r7, [r4, #0x10] */
/* @0x2ba18c str r6, [r4, #0x14] */
/* @0x2ba190 str lr, [r4, #0x18] */
/* @0x2ba194 str r12, [r4, #0x1c] */
/* @0x2ba198 str r1, [r4, #0x24] */
/* @0x2ba19c str r2, [r4, #0x28] */
/* @0x2ba1a0 str r11, [r4, #0x2c] */
/* @0x2ba1a4 str r3, [r4, #0x4c] */
/* @0x2ba1a8 str r4, [r5, #0x4] */
/* @0x2ba1ac bl 0xb6a24 <getenv@plt> */
/* @0x2ba1b0 cmp r0, #0 */
/* @0x2ba1b4 beq 0x2ba200 <jinit_memory_mgr+0x14c> */
/* @0x2ba1b8 ldr r1, [pc, #0xa4] */
/* @0x2ba1bc add r2, sp, #4 */
/* @0x2ba1c0 add r3, sp, #3 */
/* @0x2ba1c4 mov r12, #120 */
/* @0x2ba1c8 add r1, pc, r1 */
/* @0x2ba1cc strb r12, [sp, #0x3] */
/* @0x2ba1d0 bl 0xb68f8 <sscanf@plt> */
/* @0x2ba1d4 cmp r0, #0 */
/* @0x2ba1d8 ble 0x2ba200 <jinit_memory_mgr+0x14c> */
/* @0x2ba1dc ldrb r3, [sp, #0x3] */
/* @0x2ba1e0 and r3, r3, #223 */
/* @0x2ba1e4 cmp r3, #77 */
/* @0x2ba1e8 ldr r3, [sp, #0x4] */
/* @0x2ba1ec moveq r2, #1000 */
/* @0x2ba1f0 muleq r3, r2, r3 */
/* @0x2ba1f4 mov r2, #1000 */
/* @0x2ba1f8 mul r3, r2, r3 */
/* @0x2ba1fc str r3, [r4, #0x2c] */
/* @0x2ba200 add sp, sp, #12 */
/* @0x2ba204 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ba208 mov r0, r5 */
/* @0x2ba20c bl 0x2c1438 <jpeg_mem_term> */
/* @0x2ba210 ldr r3, [r5] */
/* @0x2ba214 mov r1, #54 */
/* @0x2ba218 mov r0, r5 */
/* @0x2ba21c str r4, [r3, #0x18] */
/* @0x2ba220 ldr r2, [r5] */
/* @0x2ba224 str r1, [r3, #0x14] */
/* @0x2ba228 ldr r3, [r2] */
/* @0x2ba22c blx r3 */
/* @0x2ba230 b 0x2ba0e4 <jinit_memory_mgr+0x30> */
/* @0x2ba234 .word 0xfffff0d4 */
/* @0x2ba238 .word 0xfffff538 */
/* @0x2ba23c .word 0xfffff6fc */
/* @0x2ba240 .word 0xfffff8a8 */
/* @0x2ba244 .word 0xfffff7d8 */
/* @0x2ba248 .word 0xfffff2bc */
/* @0x2ba24c .word 0xfffff234 */
/* @0x2ba250 .word 0xfffff950 */
/* @0x2ba254 .word 0xfffffba0 */
/* @0x2ba258 .word 0xfffff31c */
/* @0x2ba25c .word 0xfffff49c */
/* @0x2ba260 andeq r1, r10, r4, asr #11 */
/* @0x2ba264 andeq r1, r10, r8, ror #10 */

/* ── FUNC 0x2ba268 · anon_2ba268 · size=2756 · insn=690 */
/* @0x2ba268 ldr r3, [r0, #0x4c] */
/* @0x2ba26c ldr r1, [r0, #0x1a8] */
/* @0x2ba270 cmp r3, #1 */
/* @0x2ba274 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ba278 sub sp, sp, #36 */
/* @0x2ba27c strbeq r3, [r1, #0x1c] */
/* @0x2ba280 movne r3, #0 */
/* @0x2ba284 str r1, [sp, #0x4] */
/* @0x2ba288 mov r10, r0 */
/* @0x2ba28c ldrne r1, [sp, #0x4] */
/* @0x2ba290 movweq r3, #0x1fe */
/* @0x2ba294 movweq r2, #0x2fe */
/* @0x2ba298 streq r3, [sp, #0xc] */
/* @0x2ba29c movne r2, #256 */
/* @0x2ba2a0 strne r3, [sp, #0xc] */
/* @0x2ba2a4 strbne r3, [r1, #0x1c] */
/* @0x2ba2a8 mov r1, #1 */
/* @0x2ba2ac ldr r12, [r0, #0x4] */
/* @0x2ba2b0 ldr r3, [r10, #0x64] */
/* @0x2ba2b4 ldr r12, [r12, #0x8] */
/* @0x2ba2b8 blx r12 */
/* @0x2ba2bc ldr r2, [sp, #0x4] */
/* @0x2ba2c0 ldr r3, [r10, #0x64] */
/* @0x2ba2c4 cmp r3, #0 */
/* @0x2ba2c8 ldr r3, [r2, #0x14] */
/* @0x2ba2cc str r3, [sp, #0x10] */
/* @0x2ba2d0 str r0, [r2, #0x18] */
/* @0x2ba2d4 ble 0x2ba41c <jinit_memory_mgr+0x368> */
/* @0x2ba2d8 ldr r3, [sp, #0x4] */
/* @0x2ba2dc mov r5, r0 */
/* @0x2ba2e0 mov r2, #0 */
/* @0x2ba2e4 str r10, [sp, #0x1c] */
/* @0x2ba2e8 str r2, [sp, #0x8] */
/* @0x2ba2ec str r2, [sp, #0x18] */
/* @0x2ba2f0 str r3, [sp, #0x14] */
/* @0x2ba2f4 ldr r2, [sp, #0x14] */
/* @0x2ba2f8 ldr r0, [sp, #0x10] */
/* @0x2ba2fc ldr r4, [r2, #0x20] */
/* @0x2ba300 mov r1, r4 */
/* @0x2ba304 bl 0x318d10 <__divsi3> */
/* @0x2ba308 ldr r3, [sp, #0xc] */
/* @0x2ba30c cmp r3, #0 */
/* @0x2ba310 str r0, [sp, #0x10] */
/* @0x2ba314 beq 0x2ba330 <jinit_memory_mgr+0x27c> */
/* @0x2ba318 ldr r2, [sp, #0x8] */
/* @0x2ba31c ldr r3, [r5, r2] */
/* @0x2ba320 add r3, r3, #255 */
/* @0x2ba324 str r3, [r5, r2] */
/* @0x2ba328 ldr r3, [sp, #0x4] */
/* @0x2ba32c ldr r5, [r3, #0x18] */
/* @0x2ba330 ldr r2, [sp, #0x8] */
/* @0x2ba334 sub r8, r4, #1 */
/* @0x2ba338 ldr r3, [sp, #0x10] */
/* @0x2ba33c add r0, r4, #254 */
/* @0x2ba340 mov r4, #0 */
/* @0x2ba344 ldr r6, [r5, r2] */
/* @0x2ba348 lsl r5, r8, #1 */
/* @0x2ba34c mov r11, r4 */
/* @0x2ba350 uxtb r7, r3 */
/* @0x2ba354 mov r1, r5 */
/* @0x2ba358 bl 0x318d10 <__divsi3> */
/* @0x2ba35c cmp r0, r4 */
/* @0x2ba360 bge 0x2ba398 <jinit_memory_mgr+0x2e4> */
/* @0x2ba364 add r10, r11, #1 */
/* @0x2ba368 rsb r9, r10, r10, lsl #8 */
/* @0x2ba36c add r9, r8, r9, lsl #1 */
/* @0x2ba370 add r9, r9, #255 */
/* @0x2ba374 mov r0, r9 */
/* @0x2ba378 mov r1, r5 */
/* @0x2ba37c bl 0x318d10 <__divsi3> */
/* @0x2ba380 add r9, r9, #508 */
/* @0x2ba384 mov r11, r10 */
/* @0x2ba388 add r9, r9, #2 */
/* @0x2ba38c add r10, r10, #1 */
/* @0x2ba390 cmp r0, r4 */
/* @0x2ba394 blt 0x2ba374 <jinit_memory_mgr+0x2c0> */
/* @0x2ba398 mul r3, r11, r7 */
/* @0x2ba39c strb r3, [r6, r4] */
/* @0x2ba3a0 add r4, r4, #1 */
/* @0x2ba3a4 cmp r4, #256 */
/* @0x2ba3a8 bne 0x2ba35c <jinit_memory_mgr+0x2a8> */
/* @0x2ba3ac ldr r1, [sp, #0xc] */
/* @0x2ba3b0 cmp r1, #0 */
/* @0x2ba3b4 beq 0x2ba3dc <jinit_memory_mgr+0x328> */
/* @0x2ba3b8 add r2, r6, #255 */
/* @0x2ba3bc sub r0, r6, #255 */
/* @0x2ba3c0 mov r3, r6 */
/* @0x2ba3c4 ldrb r1, [r6] */
/* @0x2ba3c8 strb r1, [r3, #-0x1]! */
/* @0x2ba3cc cmp r3, r0 */
/* @0x2ba3d0 ldrb r1, [r6, #0xff] */
/* @0x2ba3d4 strb r1, [r2, #0x1]! */
/* @0x2ba3d8 bne 0x2ba3c4 <jinit_memory_mgr+0x310> */
/* @0x2ba3dc ldr r2, [sp, #0x1c] */
/* @0x2ba3e0 ldr r3, [r2, #0x64] */
/* @0x2ba3e4 ldr r2, [sp, #0x18] */
/* @0x2ba3e8 add r2, r2, #1 */
/* @0x2ba3ec str r2, [sp, #0x18] */
/* @0x2ba3f0 ldr r2, [sp, #0x8] */
/* @0x2ba3f4 add r2, r2, #4 */
/* @0x2ba3f8 str r2, [sp, #0x8] */
/* @0x2ba3fc ldr r2, [sp, #0x14] */
/* @0x2ba400 add r2, r2, #4 */
/* @0x2ba404 str r2, [sp, #0x14] */
/* @0x2ba408 ldr r2, [sp, #0x18] */
/* @0x2ba40c cmp r3, r2 */
/* @0x2ba410 ldrgt r3, [sp, #0x4] */
/* @0x2ba414 ldrgt r5, [r3, #0x18] */
/* @0x2ba418 bgt 0x2ba2f4 <jinit_memory_mgr+0x240> */
/* @0x2ba41c add sp, sp, #36 */
/* @0x2ba420 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ba424 ldr r12, [r0, #0x1a8] */
/* @0x2ba428 cmp r3, #0 */
/* @0x2ba42c push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2ba430 sub sp, sp, #8 */
/* @0x2ba434 ldr r11, [r0, #0x5c] */
/* @0x2ba438 str r1, [sp, #0x4] */
/* @0x2ba43c ldr r7, [r0, #0x64] */
/* @0x2ba440 ldr r9, [r12, #0x18] */
/* @0x2ba444 ble 0x2ba4b8 <jinit_memory_mgr+0x404> */
/* @0x2ba448 mov r10, #0 */
/* @0x2ba44c lsl r3, r3, #2 */
/* @0x2ba450 str r3, [sp] */
/* @0x2ba454 ldr r1, [sp, #0x4] */
/* @0x2ba458 cmp r11, #0 */
/* @0x2ba45c ldr r6, [r2, r10] */
/* @0x2ba460 ldr r3, [r1, r10] */
/* @0x2ba464 beq 0x2ba4a8 <jinit_memory_mgr+0x3f4> */
/* @0x2ba468 add r8, r6, r11 */
/* @0x2ba46c cmp r7, #0 */
/* @0x2ba470 ble 0x2ba4c4 <jinit_memory_mgr+0x410> */
/* @0x2ba474 sub r0, r9, #4 */
/* @0x2ba478 add r4, r3, r7 */
/* @0x2ba47c mov r1, #0 */
/* @0x2ba480 ldrb r12, [r3], #1 */
/* @0x2ba484 ldr r5, [r0, #0x4]! */
/* @0x2ba488 cmp r3, r4 */
/* @0x2ba48c ldrb r12, [r5, r12] */
/* @0x2ba490 add r1, r1, r12 */
/* @0x2ba494 bne 0x2ba480 <jinit_memory_mgr+0x3cc> */
/* @0x2ba498 uxtb r1, r1 */
/* @0x2ba49c strb r1, [r6], #1 */
/* @0x2ba4a0 cmp r6, r8 */
/* @0x2ba4a4 bne 0x2ba46c <jinit_memory_mgr+0x3b8> */
/* @0x2ba4a8 ldr r3, [sp] */
/* @0x2ba4ac add r10, r10, #4 */
/* @0x2ba4b0 cmp r10, r3 */
/* @0x2ba4b4 bne 0x2ba454 <jinit_memory_mgr+0x3a0> */
/* @0x2ba4b8 add sp, sp, #8 */
/* @0x2ba4bc pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2ba4c0 bx lr */
/* @0x2ba4c4 mov r1, #0 */
/* @0x2ba4c8 b 0x2ba49c <jinit_memory_mgr+0x3e8> */
/* @0x2ba4cc ldr r12, [r0, #0x1a8] */
/* @0x2ba4d0 cmp r3, #0 */
/* @0x2ba4d4 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2ba4d8 sub sp, sp, #8 */
/* @0x2ba4dc ldr r11, [r0, #0x5c] */
/* @0x2ba4e0 ldr r0, [r12, #0x18] */
/* @0x2ba4e4 ldm r0, {r7, r8, r9} */
/* @0x2ba4e8 ble 0x2ba54c <jinit_memory_mgr+0x498> */
/* @0x2ba4ec mov r10, #0 */
/* @0x2ba4f0 lsl r3, r3, #2 */
/* @0x2ba4f4 str r3, [sp, #0x4] */
/* @0x2ba4f8 cmp r11, #0 */
/* @0x2ba4fc ldr r0, [r2, r10] */
/* @0x2ba500 ldr r3, [r1, r10] */
/* @0x2ba504 addne r6, r0, r11 */
/* @0x2ba508 beq 0x2ba53c <jinit_memory_mgr+0x488> */
/* @0x2ba50c ldrb r12, [r3] */
/* @0x2ba510 add r3, r3, #3 */
/* @0x2ba514 ldrb r5, [r3, #-0x2] */
/* @0x2ba518 ldrb r4, [r3, #-0x1] */
/* @0x2ba51c ldrb r12, [r7, r12] */
/* @0x2ba520 ldrb r5, [r8, r5] */
/* @0x2ba524 ldrb r4, [r9, r4] */
/* @0x2ba528 add r12, r5, r12 */
/* @0x2ba52c add r12, r4, r12 */
/* @0x2ba530 strb r12, [r0], #1 */
/* @0x2ba534 cmp r0, r6 */
/* @0x2ba538 bne 0x2ba50c <jinit_memory_mgr+0x458> */
/* @0x2ba53c ldr r3, [sp, #0x4] */
/* @0x2ba540 add r10, r10, #4 */
/* @0x2ba544 cmp r10, r3 */
/* @0x2ba548 bne 0x2ba4f8 <jinit_memory_mgr+0x444> */
/* @0x2ba54c add sp, sp, #8 */
/* @0x2ba550 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2ba554 bx lr */
/* @0x2ba558 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2ba55c sub sp, sp, #40 */
/* @0x2ba560 ldr r4, [r0, #0x1a8] */
/* @0x2ba564 cmp r3, #0 */
/* @0x2ba568 ldr r0, [r0, #0x5c] */
/* @0x2ba56c str r2, [sp, #0x24] */
/* @0x2ba570 ldr r2, [r4, #0x18] */
/* @0x2ba574 str r0, [sp, #0x18] */
/* @0x2ba578 str r4, [sp, #0x10] */
/* @0x2ba57c ldr r12, [r2] */
/* @0x2ba580 ldr r0, [r2, #0x4] */
/* @0x2ba584 ldr r2, [r2, #0x8] */
/* @0x2ba588 str r1, [sp, #0x20] */
/* @0x2ba58c str r12, [sp] */
/* @0x2ba590 str r0, [sp, #0x4] */
/* @0x2ba594 str r2, [sp, #0x8] */
/* @0x2ba598 ble 0x2ba690 <jinit_memory_mgr+0x5dc> */
/* @0x2ba59c ldr r1, [r4, #0x30] */
/* @0x2ba5a0 lsl r3, r3, #2 */
/* @0x2ba5a4 mov r2, #0 */
/* @0x2ba5a8 str r3, [sp, #0x1c] */
/* @0x2ba5ac str r2, [sp, #0xc] */
/* @0x2ba5b0 str r1, [sp, #0x14] */
/* @0x2ba5b4 ldr r4, [sp, #0x10] */
/* @0x2ba5b8 ldr r3, [sp, #0x18] */
/* @0x2ba5bc ldr r12, [sp, #0x14] */
/* @0x2ba5c0 cmp r3, #0 */
/* @0x2ba5c4 ldr r8, [r4, #0x34] */
/* @0x2ba5c8 ldr r3, [r4, #0x3c] */
/* @0x2ba5cc ldr r9, [r4, #0x38] */
/* @0x2ba5d0 lsl r10, r12, #6 */
/* @0x2ba5d4 ldr r1, [sp, #0x20] */
/* @0x2ba5d8 add r8, r8, r10 */
/* @0x2ba5dc ldr r0, [sp, #0xc] */
/* @0x2ba5e0 add r9, r9, r10 */
/* @0x2ba5e4 add r10, r3, r10 */
/* @0x2ba5e8 ldr r3, [sp, #0x24] */
/* @0x2ba5ec ldr r2, [r1, r0] */
/* @0x2ba5f0 ldr r1, [r3, r0] */
/* @0x2ba5f4 beq 0x2ba660 <jinit_memory_mgr+0x5ac> */
/* @0x2ba5f8 ldr r12, [sp, #0x18] */
/* @0x2ba5fc mov r3, #0 */
/* @0x2ba600 add r11, r1, r12 */
/* @0x2ba604 ldrb r4, [r2, #0x1] */
/* @0x2ba608 add r7, r3, #1 */
/* @0x2ba60c ldr r12, [sp, #0x4] */
/* @0x2ba610 add r2, r2, #3 */
/* @0x2ba614 ldrb r6, [r2, #-0x3] */
/* @0x2ba618 ldr r0, [sp] */
/* @0x2ba61c add r4, r12, r4 */
/* @0x2ba620 ldr r5, [r8, r3, lsl #2] */
/* @0x2ba624 ldr r12, [r9, r3, lsl #2] */
/* @0x2ba628 add r6, r0, r6 */
/* @0x2ba62c ldr r0, [r10, r3, lsl #2] */
/* @0x2ba630 and r3, r7, #15 */
/* @0x2ba634 ldrb r5, [r6, r5] */
/* @0x2ba638 ldrb r12, [r4, r12] */
/* @0x2ba63c ldrb r6, [r2, #-0x1] */
/* @0x2ba640 ldr r4, [sp, #0x8] */
/* @0x2ba644 add r5, r12, r5 */
/* @0x2ba648 add r6, r4, r6 */
/* @0x2ba64c ldrb r12, [r6, r0] */
/* @0x2ba650 add r12, r12, r5 */
/* @0x2ba654 strb r12, [r1], #1 */
/* @0x2ba658 cmp r1, r11 */
/* @0x2ba65c bne 0x2ba604 <jinit_memory_mgr+0x550> */
/* @0x2ba660 ldr r4, [sp, #0xc] */
/* @0x2ba664 ldr r0, [sp, #0x1c] */
/* @0x2ba668 add r4, r4, #4 */
/* @0x2ba66c ldr r12, [sp, #0x14] */
/* @0x2ba670 str r4, [sp, #0xc] */
/* @0x2ba674 cmp r4, r0 */
/* @0x2ba678 ldr r4, [sp, #0x10] */
/* @0x2ba67c add r3, r12, #1 */
/* @0x2ba680 and r3, r3, #15 */
/* @0x2ba684 str r3, [r4, #0x30] */
/* @0x2ba688 strne r3, [sp, #0x14] */
/* @0x2ba68c bne 0x2ba5b4 <jinit_memory_mgr+0x500> */
/* @0x2ba690 add sp, sp, #40 */
/* @0x2ba694 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2ba698 bx lr */
/* @0x2ba69c push {r3, r4, r5, r6, r7, lr} */
/* @0x2ba6a0 mov r4, r0 */
/* @0x2ba6a4 ldr r7, [r0, #0x5c] */
/* @0x2ba6a8 ldr r3, [r0, #0x64] */
/* @0x2ba6ac add r7, r7, #2 */
/* @0x2ba6b0 ldr r6, [r0, #0x1a8] */
/* @0x2ba6b4 cmp r3, #0 */
/* @0x2ba6b8 lsl r7, r7, #1 */
/* @0x2ba6bc pople {r3, r4, r5, r6, r7, pc} */
/* @0x2ba6c0 mov r5, #0 */
/* @0x2ba6c4 ldr r3, [r4, #0x4] */
/* @0x2ba6c8 mov r1, #1 */
/* @0x2ba6cc mov r0, r4 */
/* @0x2ba6d0 mov r2, r7 */
/* @0x2ba6d4 add r5, r5, r1 */
/* @0x2ba6d8 add r6, r6, #4 */
/* @0x2ba6dc ldr r3, [r3, #0x4] */
/* @0x2ba6e0 blx r3 */
/* @0x2ba6e4 str r0, [r6, #0x40] */
/* @0x2ba6e8 ldr r3, [r4, #0x64] */
/* @0x2ba6ec cmp r3, r5 */
/* @0x2ba6f0 bgt 0x2ba6c4 <jinit_memory_mgr+0x610> */
/* @0x2ba6f4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2ba6f8 bx lr */
/* @0x2ba6fc push {r3, lr} */
/* @0x2ba700 mov r1, #46 */
/* @0x2ba704 ldr r3, [r0] */
/* @0x2ba708 ldr r2, [r3] */
/* @0x2ba70c str r1, [r3, #0x14] */
/* @0x2ba710 blx r2 */
/* @0x2ba714 pop {r3, pc} */
/* @0x2ba718 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ba71c sub sp, sp, #84 */
/* @0x2ba720 cmp r3, #0 */
/* @0x2ba724 ldr r4, [r0, #0x64] */
/* @0x2ba728 ldr r12, [r0, #0x5c] */
/* @0x2ba72c str r3, [sp, #0x4c] */
/* @0x2ba730 ldr r3, [r0, #0x1a8] */
/* @0x2ba734 ldr r0, [r0, #0x120] */
/* @0x2ba738 str r1, [sp, #0x34] */
/* @0x2ba73c str r3, [sp, #0x1c] */
/* @0x2ba740 str r4, [sp, #0x28] */
/* @0x2ba744 str r12, [sp, #0x24] */
/* @0x2ba748 str r0, [sp, #0x10] */
/* @0x2ba74c ble 0x2ba954 <jinit_memory_mgr+0x8a0> */
/* @0x2ba750 sub r3, r12, #1 */
/* @0x2ba754 str r3, [sp, #0x38] */
/* @0x2ba758 str r2, [sp, #0x2c] */
/* @0x2ba75c add r3, r12, #1 */
/* @0x2ba760 ldr r2, [sp, #0x28] */
/* @0x2ba764 rsb r4, r4, #0 */
/* @0x2ba768 ldr r12, [sp, #0x38] */
/* @0x2ba76c lsl r3, r3, #1 */
/* @0x2ba770 str r4, [sp, #0x44] */
/* @0x2ba774 str r3, [sp, #0x40] */
/* @0x2ba778 mov r3, #0 */
/* @0x2ba77c mul r12, r12, r2 */
/* @0x2ba780 str r3, [sp, #0x48] */
/* @0x2ba784 str r12, [sp, #0x3c] */
/* @0x2ba788 ldr r4, [sp, #0x2c] */
/* @0x2ba78c ldr r1, [sp, #0x24] */
/* @0x2ba790 ldr r0, [r4], #4 */
/* @0x2ba794 str r4, [sp, #0x2c] */
/* @0x2ba798 bl 0x2bc868 <jzero_far> */
/* @0x2ba79c ldr r12, [sp, #0x28] */
/* @0x2ba7a0 cmp r12, #0 */
/* @0x2ba7a4 ble 0x2ba928 <jinit_memory_mgr+0x874> */
/* @0x2ba7a8 ldr r0, [sp, #0x48] */
/* @0x2ba7ac mov r3, #0 */
/* @0x2ba7b0 ldr r2, [sp, #0x1c] */
/* @0x2ba7b4 str r3, [sp, #0x14] */
/* @0x2ba7b8 lsl r0, r0, #2 */
/* @0x2ba7bc str r0, [sp, #0x30] */
/* @0x2ba7c0 str r2, [sp, #0x20] */
/* @0x2ba7c4 ldr r4, [sp, #0x1c] */
/* @0x2ba7c8 ldr r12, [sp, #0x30] */
/* @0x2ba7cc ldr r0, [sp, #0x14] */
/* @0x2ba7d0 ldrb r3, [r4, #0x54] */
/* @0x2ba7d4 ldr r4, [sp, #0x34] */
/* @0x2ba7d8 cmp r3, #0 */
/* @0x2ba7dc ldr r1, [r4, r12] */
/* @0x2ba7e0 ldr r12, [sp, #0x2c] */
/* @0x2ba7e4 add r11, r1, r0 */
/* @0x2ba7e8 ldr r2, [r12, #-0x4] */
/* @0x2ba7ec beq 0x2ba95c <jinit_memory_mgr+0x8a8> */
/* @0x2ba7f0 ldr r1, [sp, #0x20] */
/* @0x2ba7f4 ldr r4, [sp, #0x3c] */
/* @0x2ba7f8 ldr r10, [sp, #0x44] */
/* @0x2ba7fc ldr r12, [sp, #0x38] */
/* @0x2ba800 add r11, r11, r4 */
/* @0x2ba804 ldr r3, [r1, #0x44] */
/* @0x2ba808 ldr r4, [sp, #0x40] */
/* @0x2ba80c add r2, r2, r12 */
/* @0x2ba810 mvn r12, #0 */
/* @0x2ba814 str r12, [sp, #0x4] */
/* @0x2ba818 add r3, r3, r4 */
/* @0x2ba81c str r3, [sp, #0x18] */
/* @0x2ba820 ldr r4, [sp, #0x1c] */
/* @0x2ba824 ldr r0, [sp, #0x14] */
/* @0x2ba828 ldr r12, [sp, #0x24] */
/* @0x2ba82c ldr r3, [r4, #0x18] */
/* @0x2ba830 ldr r1, [r4, #0x10] */
/* @0x2ba834 cmp r12, #0 */
/* @0x2ba838 ldr r3, [r3, r0, lsl #2] */
/* @0x2ba83c ldr r1, [r1, r0, lsl #2] */
/* @0x2ba840 str r3, [sp, #0x8] */
/* @0x2ba844 str r1, [sp, #0xc] */
/* @0x2ba848 beq 0x2ba978 <jinit_memory_mgr+0x8c4> */
/* @0x2ba84c ldr r1, [sp, #0x4] */
/* @0x2ba850 mov r5, #0 */
/* @0x2ba854 ldr r3, [sp, #0x18] */
/* @0x2ba858 mov r7, r5 */
/* @0x2ba85c add r2, r2, r1 */
/* @0x2ba860 rsb r8, r1, #0 */
/* @0x2ba864 lsl r6, r1, #1 */
/* @0x2ba868 mov r9, r12 */
/* @0x2ba86c mov r1, r5 */
/* @0x2ba870 ldrsh r12, [r3, r6] */
/* @0x2ba874 add r4, r3, r6 */
/* @0x2ba878 str r4, [sp] */
/* @0x2ba87c subs r9, r9, #1 */
/* @0x2ba880 add r1, r12, r1 */
/* @0x2ba884 ldr r4, [sp, #0x10] */
/* @0x2ba888 add r1, r1, #8 */
/* @0x2ba88c ldrb r0, [r11], r10 */
/* @0x2ba890 ldrb r12, [r2, r8] */
/* @0x2ba894 add r1, r4, r1, asr #4 */
/* @0x2ba898 ldr r4, [sp, #0x8] */
/* @0x2ba89c ldrb r1, [r1, r0] */
/* @0x2ba8a0 ldrb r0, [r4, r1] */
/* @0x2ba8a4 ldr r4, [sp, #0x4] */
/* @0x2ba8a8 add r12, r0, r12 */
/* @0x2ba8ac strb r12, [r2, r8] */
/* @0x2ba8b0 ldr r12, [sp, #0xc] */
/* @0x2ba8b4 add r2, r2, r4 */
/* @0x2ba8b8 ldrb r0, [r12, r0] */
/* @0x2ba8bc rsb r0, r0, r1 */
/* @0x2ba8c0 lsl r1, r0, #1 */
/* @0x2ba8c4 add r12, r0, r1 */
/* @0x2ba8c8 add r5, r12, r5 */
/* @0x2ba8cc add r12, r12, r1 */
/* @0x2ba8d0 strh r5, [r3] */
/* @0x2ba8d4 add r1, r12, r1 */
/* @0x2ba8d8 add r5, r7, r12 */
/* @0x2ba8dc ldr r3, [sp] */
/* @0x2ba8e0 mov r7, r0 */
/* @0x2ba8e4 bne 0x2ba870 <jinit_memory_mgr+0x7bc> */
/* @0x2ba8e8 ldr r0, [sp, #0x18] */
/* @0x2ba8ec uxth r5, r5 */
/* @0x2ba8f0 ldr r12, [sp, #0x24] */
/* @0x2ba8f4 mla r0, r12, r6, r0 */
/* @0x2ba8f8 str r0, [sp, #0x18] */
/* @0x2ba8fc ldr r1, [sp, #0x14] */
/* @0x2ba900 ldr r3, [sp, #0x28] */
/* @0x2ba904 add r1, r1, #1 */
/* @0x2ba908 ldr r2, [sp, #0x18] */
/* @0x2ba90c ldr r4, [sp, #0x20] */
/* @0x2ba910 cmp r1, r3 */
/* @0x2ba914 str r1, [sp, #0x14] */
/* @0x2ba918 add r4, r4, #4 */
/* @0x2ba91c strh r5, [r2] */
/* @0x2ba920 str r4, [sp, #0x20] */
/* @0x2ba924 bne 0x2ba7c4 <jinit_memory_mgr+0x710> */
/* @0x2ba928 ldr r2, [sp, #0x1c] */
/* @0x2ba92c ldr r4, [sp, #0x48] */
/* @0x2ba930 ldr r12, [sp, #0x4c] */
/* @0x2ba934 ldrb r3, [r2, #0x54] */
/* @0x2ba938 add r4, r4, #1 */
/* @0x2ba93c str r4, [sp, #0x48] */
/* @0x2ba940 rsbs r3, r3, #1 */
/* @0x2ba944 movlo r3, #0 */
/* @0x2ba948 cmp r4, r12 */
/* @0x2ba94c strb r3, [r2, #0x54] */
/* @0x2ba950 bne 0x2ba788 <jinit_memory_mgr+0x6d4> */
/* @0x2ba954 add sp, sp, #84 */
/* @0x2ba958 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ba95c ldr r0, [sp, #0x20] */
/* @0x2ba960 mov r1, #1 */
/* @0x2ba964 ldr r10, [sp, #0x28] */
/* @0x2ba968 str r1, [sp, #0x4] */
/* @0x2ba96c ldr r0, [r0, #0x44] */
/* @0x2ba970 str r0, [sp, #0x18] */
/* @0x2ba974 b 0x2ba820 <jinit_memory_mgr+0x76c> */
/* @0x2ba978 ldr r5, [sp, #0x24] */
/* @0x2ba97c b 0x2ba8fc <jinit_memory_mgr+0x848> */
/* @0x2ba980 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ba984 cmp r3, #0 */
/* @0x2ba988 ldr r11, [r0, #0x1a8] */
/* @0x2ba98c sub sp, sp, #36 */
/* @0x2ba990 ldr r10, [r0, #0x64] */
/* @0x2ba994 ldr r0, [r0, #0x5c] */
/* @0x2ba998 str r3, [sp, #0x1c] */
/* @0x2ba99c str r1, [sp, #0x10] */
/* @0x2ba9a0 str r0, [sp] */
/* @0x2ba9a4 ble 0x2baaa0 <jinit_memory_mgr+0x9ec> */
/* @0x2ba9a8 str r2, [sp, #0x4] */
/* @0x2ba9ac mov r2, #0 */
/* @0x2ba9b0 str r2, [sp, #0x14] */
/* @0x2ba9b4 ldr r3, [sp, #0x4] */
/* @0x2ba9b8 ldr r1, [sp] */
/* @0x2ba9bc ldr r0, [r3], #4 */
/* @0x2ba9c0 str r3, [sp, #0x4] */
/* @0x2ba9c4 bl 0x2bc868 <jzero_far> */
/* @0x2ba9c8 ldr r0, [r11, #0x30] */
/* @0x2ba9cc cmp r10, #0 */
/* @0x2ba9d0 str r0, [sp, #0x18] */
/* @0x2ba9d4 ble 0x2baa78 <jinit_memory_mgr+0x9c4> */
/* @0x2ba9d8 ldr r2, [sp, #0x18] */
/* @0x2ba9dc mov r9, r11 */
/* @0x2ba9e0 ldr r3, [sp, #0x14] */
/* @0x2ba9e4 mov r8, #0 */
/* @0x2ba9e8 lsl r2, r2, #6 */
/* @0x2ba9ec str r2, [sp, #0xc] */
/* @0x2ba9f0 lsl r3, r3, #2 */
/* @0x2ba9f4 str r3, [sp, #0x8] */
/* @0x2ba9f8 ldr r2, [sp] */
/* @0x2ba9fc ldr r0, [sp, #0x8] */
/* @0x2baa00 cmp r2, #0 */
/* @0x2baa04 ldr r2, [sp, #0x10] */
/* @0x2baa08 ldr r3, [r11, #0x18] */
/* @0x2baa0c ldr r6, [r9, #0x34] */
/* @0x2baa10 ldr r1, [r2, r0] */
/* @0x2baa14 ldr r2, [sp, #0x4] */
/* @0x2baa18 ldr r5, [r3, r8, lsl #2] */
/* @0x2baa1c add r1, r1, r8 */
/* @0x2baa20 ldr r3, [sp, #0xc] */
/* @0x2baa24 add r6, r6, r3 */
/* @0x2baa28 ldr r3, [r2, #-0x4] */
/* @0x2baa2c beq 0x2baa68 <jinit_memory_mgr+0x9b4> */
/* @0x2baa30 ldr r2, [sp] */
/* @0x2baa34 add r7, r3, r2 */
/* @0x2baa38 mov r2, #0 */
/* @0x2baa3c ldrb r4, [r1], r10 */
/* @0x2baa40 add r12, r2, #1 */
/* @0x2baa44 ldr r0, [r6, r2, lsl #2] */
/* @0x2baa48 and r2, r12, #15 */
/* @0x2baa4c add r4, r5, r4 */
/* @0x2baa50 ldrb r12, [r3] */
/* @0x2baa54 ldrb r0, [r4, r0] */
/* @0x2baa58 add r0, r12, r0 */
/* @0x2baa5c strb r0, [r3], #1 */
/* @0x2baa60 cmp r3, r7 */
/* @0x2baa64 bne 0x2baa3c <jinit_memory_mgr+0x988> */
/* @0x2baa68 add r8, r8, #1 */
/* @0x2baa6c add r9, r9, #4 */
/* @0x2baa70 cmp r8, r10 */
/* @0x2baa74 bne 0x2ba9f8 <jinit_memory_mgr+0x944> */
/* @0x2baa78 ldr r2, [sp, #0x14] */
/* @0x2baa7c ldr r1, [sp, #0x1c] */
/* @0x2baa80 add r2, r2, #1 */
/* @0x2baa84 ldr r0, [sp, #0x18] */
/* @0x2baa88 cmp r2, r1 */
/* @0x2baa8c str r2, [sp, #0x14] */
/* @0x2baa90 add r3, r0, #1 */
/* @0x2baa94 and r3, r3, #15 */
/* @0x2baa98 str r3, [r11, #0x30] */
/* @0x2baa9c bne 0x2ba9b4 <jinit_memory_mgr+0x900> */
/* @0x2baaa0 add sp, sp, #36 */
/* @0x2baaa4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2baaa8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2baaac mov r11, r0 */
/* @0x2baab0 ldr r4, [r0, #0x1a8] */
/* @0x2baab4 sub sp, sp, #28 */
/* @0x2baab8 ldr r2, [r0, #0x4c] */
/* @0x2baabc ldr r12, [r4, #0x10] */
/* @0x2baac0 cmp r2, #1 */
/* @0x2baac4 ldr r1, [r4, #0x14] */
/* @0x2baac8 str r12, [r0, #0x74] */
/* @0x2baacc str r1, [r0, #0x70] */
/* @0x2baad0 beq 0x2bab80 <jinit_memory_mgr+0xacc> */
/* @0x2baad4 blo 0x2bab60 <jinit_memory_mgr+0xaac> */
/* @0x2baad8 cmp r2, #2 */
/* @0x2baadc bne 0x2bab44 <jinit_memory_mgr+0xa90> */
/* @0x2baae0 ldr r12, [r4, #0x44] */
/* @0x2baae4 mov r1, #0 */
/* @0x2baae8 ldr r2, [pc, #0x228] */
/* @0x2baaec cmp r12, r1 */
/* @0x2baaf0 strb r1, [r4, #0x54] */
/* @0x2baaf4 add r2, pc, r2 */
/* @0x2baaf8 str r2, [r4, #0x4] */
/* @0x2baafc beq 0x2bad10 <jinit_memory_mgr+0xc5c> */
/* @0x2bab00 ldr r6, [r11, #0x5c] */
/* @0x2bab04 ldr r2, [r11, #0x64] */
/* @0x2bab08 add r6, r6, #2 */
/* @0x2bab0c cmp r2, #0 */
/* @0x2bab10 lsl r6, r6, #1 */
/* @0x2bab14 ble 0x2bab58 <jinit_memory_mgr+0xaa4> */
/* @0x2bab18 mov r5, #0 */
/* @0x2bab1c ldr r0, [r4, #0x44] */
/* @0x2bab20 mov r1, r6 */
/* @0x2bab24 bl 0x2bc868 <jzero_far> */
/* @0x2bab28 ldr r3, [r11, #0x64] */
/* @0x2bab2c add r5, r5, #1 */
/* @0x2bab30 add r4, r4, #4 */
/* @0x2bab34 cmp r3, r5 */
/* @0x2bab38 bgt 0x2bab1c <jinit_memory_mgr+0xa68> */
/* @0x2bab3c add sp, sp, #28 */
/* @0x2bab40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bab44 ldr r3, [r0] */
/* @0x2bab48 mov r1, #48 */
/* @0x2bab4c ldr r2, [r3] */
/* @0x2bab50 str r1, [r3, #0x14] */
/* @0x2bab54 blx r2 */
/* @0x2bab58 add sp, sp, #28 */
/* @0x2bab5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bab60 ldr r3, [r0, #0x64] */
/* @0x2bab64 cmp r3, #3 */
/* @0x2bab68 beq 0x2bacc8 <jinit_memory_mgr+0xc14> */
/* @0x2bab6c ldr r3, [pc, #0x1a8] */
/* @0x2bab70 add r3, pc, r3 */
/* @0x2bab74 str r3, [r4, #0x4] */
/* @0x2bab78 add sp, sp, #28 */
/* @0x2bab7c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bab80 ldr r2, [r0, #0x64] */
/* @0x2bab84 cmp r2, #3 */
/* @0x2bab88 beq 0x2bacd8 <jinit_memory_mgr+0xc24> */
/* @0x2bab8c ldr r2, [pc, #0x18c] */
/* @0x2bab90 add r2, pc, r2 */
/* @0x2bab94 str r2, [r4, #0x4] */
/* @0x2bab98 ldrb r2, [r4, #0x1c] */
/* @0x2bab9c mov r1, #0 */
/* @0x2baba0 str r1, [r4, #0x30] */
/* @0x2baba4 cmp r2, r1 */
/* @0x2baba8 beq 0x2bace8 <jinit_memory_mgr+0xc34> */
/* @0x2babac ldr r6, [r4, #0x34] */
/* @0x2babb0 cmp r6, #0 */
/* @0x2babb4 bne 0x2bab58 <jinit_memory_mgr+0xaa4> */
/* @0x2babb8 ldr r2, [r11, #0x64] */
/* @0x2babbc ldr r9, [r11, #0x1a8] */
/* @0x2babc0 cmp r2, #0 */
/* @0x2babc4 ble 0x2bab58 <jinit_memory_mgr+0xaa4> */
/* @0x2babc8 ldr r3, [pc, #0x154] */
/* @0x2babcc mov r7, r9 */
/* @0x2babd0 str r11, [sp, #0x8] */
/* @0x2babd4 add r3, pc, r3 */
/* @0x2babd8 str r3, [sp, #0xc] */
/* @0x2babdc add r3, r3, #256 */
/* @0x2babe0 str r3, [sp, #0x10] */
/* @0x2babe4 cmp r6, #0 */
/* @0x2babe8 ldr r5, [r7, #0x20] */
/* @0x2babec beq 0x2bac24 <jinit_memory_mgr+0xb70> */
/* @0x2babf0 ldr r3, [r9, #0x20] */
/* @0x2babf4 cmp r5, r3 */
/* @0x2babf8 movne r2, r9 */
/* @0x2babfc movne r3, #0 */
/* @0x2bac00 bne 0x2bac14 <jinit_memory_mgr+0xb60> */
/* @0x2bac04 b 0x2bacf4 <jinit_memory_mgr+0xc40> */
/* @0x2bac08 ldr r1, [r2, #0x20] */
/* @0x2bac0c cmp r5, r1 */
/* @0x2bac10 beq 0x2bacf8 <jinit_memory_mgr+0xc44> */
/* @0x2bac14 add r3, r3, #1 */
/* @0x2bac18 add r2, r2, #4 */
/* @0x2bac1c cmp r3, r6 */
/* @0x2bac20 bne 0x2bac08 <jinit_memory_mgr+0xb54> */
/* @0x2bac24 ldr r2, [sp, #0x8] */
/* @0x2bac28 mov r1, #1 */
/* @0x2bac2c ldr r4, [sp, #0xc] */
/* @0x2bac30 sub r5, r5, #1 */
/* @0x2bac34 ldr r3, [r2, #0x4] */
/* @0x2bac38 mov r0, r2 */
/* @0x2bac3c mov r2, #1024 */
/* @0x2bac40 lsl r5, r5, #9 */
/* @0x2bac44 ldr r3, [r3] */
/* @0x2bac48 blx r3 */
/* @0x2bac4c ldr r11, [sp, #0x10] */
/* @0x2bac50 str r6, [sp, #0x14] */
/* @0x2bac54 sub r8, r0, #4 */
/* @0x2bac58 str r0, [sp, #0x4] */
/* @0x2bac5c mov r6, r8 */
/* @0x2bac60 mov r10, #0 */
/* @0x2bac64 ldrb r3, [r4, r10] */
/* @0x2bac68 mov r1, r5 */
/* @0x2bac6c add r10, r10, #1 */
/* @0x2bac70 sub r3, r3, r3, lsl #8 */
/* @0x2bac74 lsl r0, r3, #1 */
/* @0x2bac78 add r0, r0, #65024 */
/* @0x2bac7c add r0, r0, #1 */
/* @0x2bac80 bl 0x318d10 <__divsi3> */
/* @0x2bac84 cmp r10, #16 */
/* @0x2bac88 str r0, [r6, #0x4]! */
/* @0x2bac8c bne 0x2bac64 <jinit_memory_mgr+0xbb0> */
/* @0x2bac90 add r4, r4, #16 */
/* @0x2bac94 add r8, r8, #64 */
/* @0x2bac98 cmp r4, r11 */
/* @0x2bac9c bne 0x2bac5c <jinit_memory_mgr+0xba8> */
/* @0x2baca0 ldr r6, [sp, #0x14] */
/* @0x2baca4 ldr r3, [sp, #0x4] */
/* @0x2baca8 add r6, r6, #1 */
/* @0x2bacac ldr r2, [sp, #0x8] */
/* @0x2bacb0 add r7, r7, #4 */
/* @0x2bacb4 str r3, [r7, #0x30] */
/* @0x2bacb8 ldr r3, [r2, #0x64] */
/* @0x2bacbc cmp r6, r3 */
/* @0x2bacc0 blt 0x2babe4 <jinit_memory_mgr+0xb30> */
/* @0x2bacc4 b 0x2bab58 <jinit_memory_mgr+0xaa4> */
/* @0x2bacc8 ldr r3, [pc, #0x58] */
/* @0x2baccc add r3, pc, r3 */
/* @0x2bacd0 str r3, [r4, #0x4] */
/* @0x2bacd4 b 0x2bab58 <jinit_memory_mgr+0xaa4> */
/* @0x2bacd8 ldr r2, [pc, #0x4c] */
/* @0x2bacdc add r2, pc, r2 */
/* @0x2bace0 str r2, [r4, #0x4] */
/* @0x2bace4 b 0x2bab98 <jinit_memory_mgr+0xae4> */
/* @0x2bace8 mov r0, r11 */
/* @0x2bacec bl 0x2ba268 <jinit_memory_mgr+0x1b4> */
/* @0x2bacf0 b 0x2babac <jinit_memory_mgr+0xaf8> */
/* @0x2bacf4 mov r3, #0 */
/* @0x2bacf8 add r3, r9, r3, lsl #2 */
/* @0x2bacfc ldr r3, [r3, #0x34] */
/* @0x2bad00 cmp r3, #0 */
/* @0x2bad04 str r3, [sp, #0x4] */
/* @0x2bad08 bne 0x2baca4 <jinit_memory_mgr+0xbf0> */
/* @0x2bad0c b 0x2bac24 <jinit_memory_mgr+0xb70> */
/* @0x2bad10 bl 0x2ba69c <jinit_memory_mgr+0x5e8> */
/* @0x2bad14 b 0x2bab00 <jinit_memory_mgr+0xa4c> */
/* @0x2bad18 .word 0xfffffc1c */
/* @0x2bad1c .word 0xfffff8ac */
/* @0x2bad20 .word 0xfffffde8 */
/* @0x2bad24 strdeq r5, r6, [sp], -r12 */
/* @0x2bad28 .word 0xfffff7f8 */
/* @0x2bad2c .word 0xfffff874 */

/* ── FUNC 0x2bad30 · jinit_1pass_quantizer · size=968 · insn=242 */
/* @0x2bad30 ldr r3, [r0, #0x4] */
/* @0x2bad34 mov r1, #1 */
/* @0x2bad38 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bad3c mov r2, #88 */
/* @0x2bad40 ldr r3, [r3] */
/* @0x2bad44 sub sp, sp, #36 */
/* @0x2bad48 mov r8, r0 */
/* @0x2bad4c blx r3 */
/* @0x2bad50 ldr r2, [r8, #0x64] */
/* @0x2bad54 mov r3, #0 */
/* @0x2bad58 ldr r12, [pc, #0x388] */
/* @0x2bad5c ldr r1, [pc, #0x388] */
/* @0x2bad60 cmp r2, #4 */
/* @0x2bad64 ldr r2, [pc, #0x384] */
/* @0x2bad68 add r12, pc, r12 */
/* @0x2bad6c add r1, pc, r1 */
/* @0x2bad70 add r2, pc, r2 */
/* @0x2bad74 str r0, [r8, #0x1a8] */
/* @0x2bad78 str r12, [r0] */
/* @0x2bad7c str r1, [r0, #0x8] */
/* @0x2bad80 str r2, [r0, #0xc] */
/* @0x2bad84 str r3, [r0, #0x44] */
/* @0x2bad88 str r3, [r0, #0x34] */
/* @0x2bad8c ble 0x2badb4 <jinit_1pass_quantizer+0x84> */
/* @0x2bad90 ldr r3, [r8] */
/* @0x2bad94 mov r2, #4 */
/* @0x2bad98 mov r1, #55 */
/* @0x2bad9c mov r0, r8 */
/* @0x2bada0 str r2, [r3, #0x18] */
/* @0x2bada4 ldr r2, [r8] */
/* @0x2bada8 str r1, [r3, #0x14] */
/* @0x2badac ldr r3, [r2] */
/* @0x2badb0 blx r3 */
/* @0x2badb4 ldr r6, [r8, #0x54] */
/* @0x2badb8 cmp r6, #256 */
/* @0x2badbc ble 0x2bade8 <jinit_1pass_quantizer+0xb8> */
/* @0x2badc0 ldr r3, [r8] */
/* @0x2badc4 mov r2, #256 */
/* @0x2badc8 mov r1, #57 */
/* @0x2badcc mov r0, r8 */
/* @0x2badd0 str r2, [r3, #0x18] */
/* @0x2badd4 ldr r2, [r8] */
/* @0x2badd8 str r1, [r3, #0x14] */
/* @0x2baddc ldr r3, [r2] */
/* @0x2bade0 blx r3 */
/* @0x2bade4 ldr r6, [r8, #0x54] */
/* @0x2bade8 ldr r4, [r8, #0x1a8] */
/* @0x2badec mov r5, #1 */
/* @0x2badf0 str r4, [sp, #0x10] */
/* @0x2badf4 ldr r2, [sp, #0x10] */
/* @0x2badf8 ldr r4, [r8, #0x64] */
/* @0x2badfc add r12, r2, #32 */
/* @0x2bae00 add r1, r5, #1 */
/* @0x2bae04 cmp r4, #1 */
/* @0x2bae08 mov r2, r1 */
/* @0x2bae0c ble 0x2bae24 <jinit_1pass_quantizer+0xf4> */
/* @0x2bae10 mov r3, #1 */
/* @0x2bae14 add r3, r3, #1 */
/* @0x2bae18 cmp r3, r4 */
/* @0x2bae1c mul r2, r1, r2 */
/* @0x2bae20 bne 0x2bae14 <jinit_1pass_quantizer+0xe4> */
/* @0x2bae24 cmp r2, r6 */
/* @0x2bae28 movle r5, r1 */
/* @0x2bae2c ble 0x2bae00 <jinit_1pass_quantizer+0xd0> */
/* @0x2bae30 cmp r5, #1 */
/* @0x2bae34 beq 0x2bb0a0 <jinit_1pass_quantizer+0x370> */
/* @0x2bae38 cmp r4, #0 */
/* @0x2bae3c ble 0x2bb0d0 <jinit_1pass_quantizer+0x3a0> */
/* @0x2bae40 add r2, r12, r4, lsl #2 */
/* @0x2bae44 mov r3, r12 */
/* @0x2bae48 mov r7, #1 */
/* @0x2bae4c str r5, [r3], #4 */
/* @0x2bae50 cmp r3, r2 */
/* @0x2bae54 mul r7, r5, r7 */
/* @0x2bae58 bne 0x2bae4c <jinit_1pass_quantizer+0x11c> */
/* @0x2bae5c ldr r3, [pc, #0x290] */
/* @0x2bae60 mov r9, #0 */
/* @0x2bae64 mov r2, r8 */
/* @0x2bae68 mov r5, r9 */
/* @0x2bae6c add r3, pc, r3 */
/* @0x2bae70 mov r8, r6 */
/* @0x2bae74 mov r6, r12 */
/* @0x2bae78 cmp r4, r5 */
/* @0x2bae7c ble 0x2baedc <jinit_1pass_quantizer+0x1ac> */
/* @0x2bae80 ldr r1, [r2, #0x2c] */
/* @0x2bae84 mov r10, r5 */
/* @0x2bae88 mov r0, r7 */
/* @0x2bae8c cmp r1, #2 */
/* @0x2bae90 addeq r1, r3, r5, lsl #2 */
/* @0x2bae94 add r5, r5, #1 */
/* @0x2bae98 ldreq r10, [r1, #0x100] */
/* @0x2bae9c ldr r11, [r6, r10, lsl #2] */
/* @0x2baea0 str r2, [sp, #0x8] */
/* @0x2baea4 str r3, [sp, #0x4] */
/* @0x2baea8 mov r1, r11 */
/* @0x2baeac add r11, r11, #1 */
/* @0x2baeb0 bl 0x318d10 <__divsi3> */
/* @0x2baeb4 ldr r2, [sp, #0x8] */
/* @0x2baeb8 ldr r3, [sp, #0x4] */
/* @0x2baebc mul r0, r11, r0 */
/* @0x2baec0 cmp r0, r8 */
/* @0x2baec4 bgt 0x2baedc <jinit_1pass_quantizer+0x1ac> */
/* @0x2baec8 cmp r4, r5 */
/* @0x2baecc str r11, [r6, r10, lsl #2] */
/* @0x2baed0 mov r7, r0 */
/* @0x2baed4 mov r9, #1 */
/* @0x2baed8 bgt 0x2bae80 <jinit_1pass_quantizer+0x150> */
/* @0x2baedc cmp r9, #0 */
/* @0x2baee0 mov r9, #0 */
/* @0x2baee4 mov r5, r9 */
/* @0x2baee8 bne 0x2bae78 <jinit_1pass_quantizer+0x148> */
/* @0x2baeec ldr r3, [r2, #0x64] */
/* @0x2baef0 mov r8, r2 */
/* @0x2baef4 mov r10, r7 */
/* @0x2baef8 cmp r3, #3 */
/* @0x2baefc ldr r3, [r2] */
/* @0x2baf00 beq 0x2bb064 <jinit_1pass_quantizer+0x334> */
/* @0x2baf04 str r7, [r3, #0x18] */
/* @0x2baf08 mov r0, r2 */
/* @0x2baf0c ldr r2, [r2] */
/* @0x2baf10 mov r12, #95 */
/* @0x2baf14 mov r1, #1 */
/* @0x2baf18 str r12, [r3, #0x14] */
/* @0x2baf1c ldr r3, [r2, #0x4] */
/* @0x2baf20 blx r3 */
/* @0x2baf24 ldr r12, [r8, #0x4] */
/* @0x2baf28 mov r0, r8 */
/* @0x2baf2c mov r1, #1 */
/* @0x2baf30 mov r2, r7 */
/* @0x2baf34 ldr r3, [r8, #0x64] */
/* @0x2baf38 ldr r12, [r12, #0x8] */
/* @0x2baf3c blx r12 */
/* @0x2baf40 ldr r5, [r8, #0x64] */
/* @0x2baf44 cmp r5, #0 */
/* @0x2baf48 mov r4, r0 */
/* @0x2baf4c ble 0x2bb03c <jinit_1pass_quantizer+0x30c> */
/* @0x2baf50 ldr r3, [sp, #0x10] */
/* @0x2baf54 mov r2, #0 */
/* @0x2baf58 str r8, [sp, #0x1c] */
/* @0x2baf5c str r2, [sp, #0x14] */
/* @0x2baf60 str r3, [sp, #0x18] */
/* @0x2baf64 ldr r3, [sp, #0x18] */
/* @0x2baf68 mov r0, r7 */
/* @0x2baf6c ldr r9, [r3, #0x20] */
/* @0x2baf70 mov r1, r9 */
/* @0x2baf74 bl 0x318d10 <__divsi3> */
/* @0x2baf78 cmp r9, #0 */
/* @0x2baf7c mov r6, r0 */
/* @0x2baf80 ble 0x2bb014 <jinit_1pass_quantizer+0x2e4> */
/* @0x2baf84 sub r2, r9, #1 */
/* @0x2baf88 ldr r3, [sp, #0x14] */
/* @0x2baf8c mov r8, #0 */
/* @0x2baf90 rsb r9, r9, r9, lsl #8 */
/* @0x2baf94 asr r11, r2, #1 */
/* @0x2baf98 str r2, [sp, #0xc] */
/* @0x2baf9c lsl r5, r3, #2 */
/* @0x2bafa0 add r9, r9, r11 */
/* @0x2bafa4 mov r3, r8 */
/* @0x2bafa8 mov r8, r7 */
/* @0x2bafac mov r7, r3 */
/* @0x2bafb0 mov r0, r11 */
/* @0x2bafb4 ldr r1, [sp, #0xc] */
/* @0x2bafb8 bl 0x318d10 <__divsi3> */
/* @0x2bafbc cmp r7, r10 */
/* @0x2bafc0 mov lr, r7 */
/* @0x2bafc4 bge 0x2baffc <jinit_1pass_quantizer+0x2cc> */
/* @0x2bafc8 uxtb r0, r0 */
/* @0x2bafcc cmp r6, #0 */
/* @0x2bafd0 ble 0x2baff0 <jinit_1pass_quantizer+0x2c0> */
/* @0x2bafd4 add r1, lr, r6 */
/* @0x2bafd8 mov r3, lr */
/* @0x2bafdc ldr r2, [r4, r5] */
/* @0x2bafe0 strb r0, [r2, r3] */
/* @0x2bafe4 add r3, r3, #1 */
/* @0x2bafe8 cmp r3, r1 */
/* @0x2bafec bne 0x2bafdc <jinit_1pass_quantizer+0x2ac> */
/* @0x2baff0 add lr, lr, r8 */
/* @0x2baff4 cmp lr, r10 */
/* @0x2baff8 blt 0x2bafcc <jinit_1pass_quantizer+0x29c> */
/* @0x2baffc add r11, r11, #255 */
/* @0x2bb000 add r7, r7, r6 */
/* @0x2bb004 cmp r11, r9 */
/* @0x2bb008 bne 0x2bafb0 <jinit_1pass_quantizer+0x280> */
/* @0x2bb00c ldr r2, [sp, #0x1c] */
/* @0x2bb010 ldr r5, [r2, #0x64] */
/* @0x2bb014 ldr r2, [sp, #0x14] */
/* @0x2bb018 ldr r3, [sp, #0x18] */
/* @0x2bb01c add r2, r2, #1 */
/* @0x2bb020 str r2, [sp, #0x14] */
/* @0x2bb024 cmp r2, r5 */
/* @0x2bb028 add r3, r3, #4 */
/* @0x2bb02c str r3, [sp, #0x18] */
/* @0x2bb030 movlt r7, r6 */
/* @0x2bb034 blt 0x2baf64 <jinit_1pass_quantizer+0x234> */
/* @0x2bb038 ldr r8, [sp, #0x1c] */
/* @0x2bb03c ldr r2, [sp, #0x10] */
/* @0x2bb040 mov r0, r8 */
/* @0x2bb044 str r4, [r2, #0x10] */
/* @0x2bb048 str r10, [r2, #0x14] */
/* @0x2bb04c bl 0x2ba268 <jinit_memory_mgr+0x1b4> */
/* @0x2bb050 ldr r3, [r8, #0x4c] */
/* @0x2bb054 cmp r3, #2 */
/* @0x2bb058 beq 0x2bb0d8 <jinit_1pass_quantizer+0x3a8> */
/* @0x2bb05c add sp, sp, #36 */
/* @0x2bb060 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bb064 ldr r4, [sp, #0x10] */
/* @0x2bb068 mov lr, #94 */
/* @0x2bb06c str r7, [r3, #0x18] */
/* @0x2bb070 mov r0, r2 */
/* @0x2bb074 mov r1, #1 */
/* @0x2bb078 ldr r2, [r3, #0x4] */
/* @0x2bb07c ldr r12, [r4, #0x20] */
/* @0x2bb080 str r12, [r3, #0x1c] */
/* @0x2bb084 ldr r12, [r4, #0x24] */
/* @0x2bb088 str r12, [r3, #0x20] */
/* @0x2bb08c ldr r12, [r4, #0x28] */
/* @0x2bb090 str lr, [r3, #0x14] */
/* @0x2bb094 str r12, [r3, #0x24] */
/* @0x2bb098 blx r2 */
/* @0x2bb09c b 0x2baf24 <jinit_1pass_quantizer+0x1f4> */
/* @0x2bb0a0 ldr r3, [r8] */
/* @0x2bb0a4 mov r1, #56 */
/* @0x2bb0a8 mov r0, r8 */
/* @0x2bb0ac str r2, [r3, #0x18] */
/* @0x2bb0b0 ldr r2, [r8] */
/* @0x2bb0b4 str r1, [r3, #0x14] */
/* @0x2bb0b8 ldr r3, [r2] */
/* @0x2bb0bc str r12, [sp, #0x8] */
/* @0x2bb0c0 blx r3 */
/* @0x2bb0c4 cmp r4, #0 */
/* @0x2bb0c8 ldr r12, [sp, #0x8] */
/* @0x2bb0cc bgt 0x2bae40 <jinit_1pass_quantizer+0x110> */
/* @0x2bb0d0 mov r7, #1 */
/* @0x2bb0d4 b 0x2bae5c <jinit_1pass_quantizer+0x12c> */
/* @0x2bb0d8 mov r0, r8 */
/* @0x2bb0dc add sp, sp, #36 */
/* @0x2bb0e0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bb0e4 b 0x2ba69c <jinit_memory_mgr+0x5e8> */
/* @0x2bb0e8 .word 0xfffffd38 */
/* @0x2bb0ec .word 0xfffff984 */
/* @0x2bb0f0 .word 0xfffff984 */
/* @0x2bb0f4 andeq r5, sp, r4, rrx */

/* ── FUNC 0x2bb0f8 · anon_2bb0f8 · size=5464 · insn=1367 */
/* @0x2bb0f8 ldr r2, [r0, #0x1a8] */
/* @0x2bb0fc cmp r3, #0 */
/* @0x2bb100 push {r4, r5, r6, r7, r8} */
/* @0x2bb104 ldr r6, [r0, #0x5c] */
/* @0x2bb108 ldr r5, [r2, #0x18] */
/* @0x2bb10c ble 0x2bb174 <jinit_1pass_quantizer+0x444> */
/* @0x2bb110 add r8, r6, r6, lsl #1 */
/* @0x2bb114 add r7, r1, r3, lsl #2 */
/* @0x2bb118 cmp r6, #0 */
/* @0x2bb11c ldr r3, [r1], #4 */
/* @0x2bb120 addne r4, r3, r8 */
/* @0x2bb124 beq 0x2bb16c <jinit_1pass_quantizer+0x43c> */
/* @0x2bb128 ldrb r12, [r3] */
/* @0x2bb12c add r3, r3, #3 */
/* @0x2bb130 ldrb r0, [r3, #-0x2] */
/* @0x2bb134 ldrb r2, [r3, #-0x1] */
/* @0x2bb138 lsr r12, r12, #3 */
/* @0x2bb13c lsr r0, r0, #2 */
/* @0x2bb140 ldr r12, [r5, r12, lsl #2] */
/* @0x2bb144 lsr r2, r2, #3 */
/* @0x2bb148 add r0, r12, r0, lsl #6 */
/* @0x2bb14c lsl r2, r2, #1 */
/* @0x2bb150 ldrh r12, [r0, r2] */
/* @0x2bb154 add r12, r12, #1 */
/* @0x2bb158 uxth r12, r12 */
/* @0x2bb15c cmp r12, #0 */
/* @0x2bb160 strhne r12, [r0, r2] */
/* @0x2bb164 cmp r3, r4 */
/* @0x2bb168 bne 0x2bb128 <jinit_1pass_quantizer+0x3f8> */
/* @0x2bb16c cmp r1, r7 */
/* @0x2bb170 bne 0x2bb118 <jinit_1pass_quantizer+0x3e8> */
/* @0x2bb174 pop {r4, r5, r6, r7, r8} */
/* @0x2bb178 bx lr */
/* @0x2bb17c ldr r12, [r0, #0x4] */
/* @0x2bb180 mov r1, #1 */
/* @0x2bb184 push {r3, r4, r5, lr} */
/* @0x2bb188 movw r2, #0x7fc */
/* @0x2bb18c ldr r3, [r12] */
/* @0x2bb190 ldr r4, [r0, #0x1a8] */
/* @0x2bb194 blx r3 */
/* @0x2bb198 mov r3, #0 */
/* @0x2bb19c add r1, r0, #1016 */
/* @0x2bb1a0 add r2, r0, #1024 */
/* @0x2bb1a4 add r12, r0, #1020 */
/* @0x2bb1a8 str r12, [r4, #0x28] */
/* @0x2bb1ac str r3, [r1, #0x4]! */
/* @0x2bb1b0 rsb r12, r3, #0 */
/* @0x2bb1b4 add r3, r3, #1 */
/* @0x2bb1b8 str r12, [r2, #-0x4]! */
/* @0x2bb1bc cmp r3, #16 */
/* @0x2bb1c0 bne 0x2bb1ac <jinit_1pass_quantizer+0x47c> */
/* @0x2bb1c4 add r1, r0, #1072 */
/* @0x2bb1c8 add r12, r0, #960 */
/* @0x2bb1cc add r1, r1, #8 */
/* @0x2bb1d0 mov r2, r3 */
/* @0x2bb1d4 add r3, r3, #1 */
/* @0x2bb1d8 str r2, [r1, #0x4]! */
/* @0x2bb1dc and r5, r3, #1 */
/* @0x2bb1e0 cmp r3, #48 */
/* @0x2bb1e4 eor r5, r5, #1 */
/* @0x2bb1e8 rsb r4, r2, #0 */
/* @0x2bb1ec add r2, r2, r5 */
/* @0x2bb1f0 str r4, [r12, #-0x4]! */
/* @0x2bb1f4 bne 0x2bb1d4 <jinit_1pass_quantizer+0x4a4> */
/* @0x2bb1f8 add r3, r0, #1200 */
/* @0x2bb1fc add r12, r0, #2032 */
/* @0x2bb200 add r1, r0, #832 */
/* @0x2bb204 add r3, r3, #8 */
/* @0x2bb208 add r12, r12, #8 */
/* @0x2bb20c rsb r0, r2, #0 */
/* @0x2bb210 str r2, [r3, #0x4]! */
/* @0x2bb214 cmp r3, r12 */
/* @0x2bb218 str r0, [r1, #-0x4]! */
/* @0x2bb21c bne 0x2bb210 <jinit_1pass_quantizer+0x4e0> */
/* @0x2bb220 pop {r3, r4, r5, pc} */
/* @0x2bb224 bx lr */
/* @0x2bb228 ldr r3, [r0, #0x1a8] */
/* @0x2bb22c mov r2, #1 */
/* @0x2bb230 strb r2, [r3, #0x1c] */
/* @0x2bb234 bx lr */
/* @0x2bb238 push {r3, r4, r5, r6, r7, lr} */
/* @0x2bb23c mov r4, r0 */
/* @0x2bb240 ldr r3, [r0, #0x4c] */
/* @0x2bb244 ldr r6, [r0, #0x1a8] */
/* @0x2bb248 cmp r3, #0 */
/* @0x2bb24c ldr r5, [r6, #0x18] */
/* @0x2bb250 movne r3, #2 */
/* @0x2bb254 strne r3, [r0, #0x4c] */
/* @0x2bb258 cmp r1, #0 */
/* @0x2bb25c beq 0x2bb2a4 <jinit_1pass_quantizer+0x574> */
/* @0x2bb260 ldr r2, [pc, #0x148] */
/* @0x2bb264 mov r1, #1 */
/* @0x2bb268 ldr r3, [pc, #0x144] */
/* @0x2bb26c add r2, pc, r2 */
/* @0x2bb270 strb r1, [r6, #0x1c] */
/* @0x2bb274 add r3, pc, r3 */
/* @0x2bb278 stmib r6, {r2, r3} */
/* @0x2bb27c mov r4, #0 */
/* @0x2bb280 ldr r0, [r5, r4] */
/* @0x2bb284 mov r1, #4096 */
/* @0x2bb288 add r4, r4, #4 */
/* @0x2bb28c bl 0x2bc868 <jzero_far> */
/* @0x2bb290 cmp r4, #128 */
/* @0x2bb294 bne 0x2bb280 <jinit_1pass_quantizer+0x550> */
/* @0x2bb298 mov r3, #0 */
/* @0x2bb29c strb r3, [r6, #0x1c] */
/* @0x2bb2a0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2bb2a4 ldr r2, [r0, #0x4c] */
/* @0x2bb2a8 cmp r2, #2 */
/* @0x2bb2ac beq 0x2bb2f4 <jinit_1pass_quantizer+0x5c4> */
/* @0x2bb2b0 ldr r3, [pc, #0x100] */
/* @0x2bb2b4 add r3, pc, r3 */
/* @0x2bb2b8 str r3, [r6, #0x4] */
/* @0x2bb2bc ldr r3, [r4, #0x70] */
/* @0x2bb2c0 ldr r1, [pc, #0xf4] */
/* @0x2bb2c4 cmp r3, #0 */
/* @0x2bb2c8 add r1, pc, r1 */
/* @0x2bb2cc str r1, [r6, #0x8] */
/* @0x2bb2d0 ble 0x2bb370 <jinit_1pass_quantizer+0x640> */
/* @0x2bb2d4 cmp r3, #256 */
/* @0x2bb2d8 bgt 0x2bb304 <jinit_1pass_quantizer+0x5d4> */
/* @0x2bb2dc cmp r2, #2 */
/* @0x2bb2e0 beq 0x2bb334 <jinit_1pass_quantizer+0x604> */
/* @0x2bb2e4 ldrb r3, [r6, #0x1c] */
/* @0x2bb2e8 cmp r3, #0 */
/* @0x2bb2ec popeq {r3, r4, r5, r6, r7, pc} */
/* @0x2bb2f0 b 0x2bb27c <jinit_1pass_quantizer+0x54c> */
/* @0x2bb2f4 ldr r3, [pc, #0xc4] */
/* @0x2bb2f8 add r3, pc, r3 */
/* @0x2bb2fc str r3, [r6, #0x4] */
/* @0x2bb300 b 0x2bb2bc <jinit_1pass_quantizer+0x58c> */
/* @0x2bb304 ldr r3, [r4] */
/* @0x2bb308 mov r2, #256 */
/* @0x2bb30c mov r1, #57 */
/* @0x2bb310 str r2, [r3, #0x18] */
/* @0x2bb314 mov r0, r4 */
/* @0x2bb318 ldr r2, [r4] */
/* @0x2bb31c str r1, [r3, #0x14] */
/* @0x2bb320 ldr r3, [r2] */
/* @0x2bb324 blx r3 */
/* @0x2bb328 ldr r2, [r4, #0x4c] */
/* @0x2bb32c cmp r2, #2 */
/* @0x2bb330 bne 0x2bb2e4 <jinit_1pass_quantizer+0x5b4> */
/* @0x2bb334 ldr r3, [r4, #0x5c] */
/* @0x2bb338 ldr r0, [r6, #0x20] */
/* @0x2bb33c add r3, r3, r3, lsl #1 */
/* @0x2bb340 cmp r0, #0 */
/* @0x2bb344 lsl r7, r3, #1 */
/* @0x2bb348 add r7, r7, #12 */
/* @0x2bb34c beq 0x2bb380 <jinit_1pass_quantizer+0x650> */
/* @0x2bb350 mov r1, r7 */
/* @0x2bb354 bl 0x2bc868 <jzero_far> */
/* @0x2bb358 ldr r3, [r6, #0x28] */
/* @0x2bb35c cmp r3, #0 */
/* @0x2bb360 beq 0x2bb3a4 <jinit_1pass_quantizer+0x674> */
/* @0x2bb364 mov r3, #0 */
/* @0x2bb368 strb r3, [r6, #0x24] */
/* @0x2bb36c b 0x2bb2e4 <jinit_1pass_quantizer+0x5b4> */
/* @0x2bb370 ldr r3, [r4] */
/* @0x2bb374 mov r2, #1 */
/* @0x2bb378 mov r1, #56 */
/* @0x2bb37c b 0x2bb310 <jinit_1pass_quantizer+0x5e0> */
/* @0x2bb380 ldr r3, [r4, #0x4] */
/* @0x2bb384 mov r0, r4 */
/* @0x2bb388 mov r1, #1 */
/* @0x2bb38c mov r2, r7 */
/* @0x2bb390 ldr r3, [r3, #0x4] */
/* @0x2bb394 blx r3 */
/* @0x2bb398 mov r3, r0 */
/* @0x2bb39c str r3, [r6, #0x20] */
/* @0x2bb3a0 b 0x2bb350 <jinit_1pass_quantizer+0x620> */
/* @0x2bb3a4 mov r0, r4 */
/* @0x2bb3a8 bl 0x2bb17c <jinit_1pass_quantizer+0x44c> */
/* @0x2bb3ac b 0x2bb364 <jinit_1pass_quantizer+0x634> */
/* @0x2bb3b0 .word 0xfffffe84 */
/* @0x2bb3b4 andeq r0, r0, r4, ror pc */
/* @0x2bb3b8 ldrdeq r0, r1, [r0], -r8 */
/* @0x2bb3bc .word 0xffffff54 */
/* @0x2bb3c0 andeq r0, r0, r12, ror #22 */
/* @0x2bb3c4 ldr r0, [r0, #0x18] */
/* @0x2bb3c8 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2bb3cc sub sp, sp, #16 */
/* @0x2bb3d0 ldr r10, [r1] */
/* @0x2bb3d4 ldr r2, [r1, #0x4] */
/* @0x2bb3d8 str r0, [sp, #0xc] */
/* @0x2bb3dc ldr r0, [r1, #0x8] */
/* @0x2bb3e0 cmp r10, r2 */
/* @0x2bb3e4 str r1, [sp, #0x8] */
/* @0x2bb3e8 ldr r11, [r1, #0xc] */
/* @0x2bb3ec str r0, [sp] */
/* @0x2bb3f0 ldr r5, [r1, #0x10] */
/* @0x2bb3f4 ldr r6, [r1, #0x14] */
/* @0x2bb3f8 bge 0x2bb4a4 <jinit_1pass_quantizer+0x774> */
/* @0x2bb3fc ldr r1, [sp, #0xc] */
/* @0x2bb400 add r3, r5, r0, lsl #5 */
/* @0x2bb404 mov r12, r10 */
/* @0x2bb408 mov r7, #0 */
/* @0x2bb40c add r9, r1, r10, lsl #2 */
/* @0x2bb410 lsl r3, r3, #1 */
/* @0x2bb414 str r3, [sp, #0x4] */
/* @0x2bb418 ldr r0, [sp] */
/* @0x2bb41c cmp r0, r11 */
/* @0x2bb420 bgt 0x2bb47c <jinit_1pass_quantizer+0x74c> */
/* @0x2bb424 ldr r4, [r9, r7] */
/* @0x2bb428 mov r8, r0 */
/* @0x2bb42c ldr r1, [sp, #0x4] */
/* @0x2bb430 add r4, r4, r1 */
/* @0x2bb434 cmp r5, r6 */
/* @0x2bb438 bgt 0x2bb46c <jinit_1pass_quantizer+0x73c> */
/* @0x2bb43c ldrh r3, [r4] */
/* @0x2bb440 cmp r3, #0 */
/* @0x2bb444 bne 0x2bb778 <jinit_1pass_quantizer+0xa48> */
/* @0x2bb448 mov r1, r4 */
/* @0x2bb44c mov r3, r5 */
/* @0x2bb450 b 0x2bb460 <jinit_1pass_quantizer+0x730> */
/* @0x2bb454 ldrh r0, [r1, #2]! */
/* @0x2bb458 cmp r0, #0 */
/* @0x2bb45c bne 0x2bb778 <jinit_1pass_quantizer+0xa48> */
/* @0x2bb460 add r3, r3, #1 */
/* @0x2bb464 cmp r6, r3 */
/* @0x2bb468 bge 0x2bb454 <jinit_1pass_quantizer+0x724> */
/* @0x2bb46c add r8, r8, #1 */
/* @0x2bb470 add r4, r4, #64 */
/* @0x2bb474 cmp r11, r8 */
/* @0x2bb478 bge 0x2bb434 <jinit_1pass_quantizer+0x704> */
/* @0x2bb47c add r12, r12, #1 */
/* @0x2bb480 add r7, r7, #4 */
/* @0x2bb484 cmp r2, r12 */
/* @0x2bb488 bge 0x2bb418 <jinit_1pass_quantizer+0x6e8> */
/* @0x2bb48c mov r12, r10 */
/* @0x2bb490 b 0x2bb788 <jinit_1pass_quantizer+0xa58> */
/* @0x2bb494 ldr r1, [sp, #0x8] */
/* @0x2bb498 mov r10, r12 */
/* @0x2bb49c mov r2, r4 */
/* @0x2bb4a0 str r4, [r1, #0x4] */
/* @0x2bb4a4 ldr r1, [sp] */
/* @0x2bb4a8 cmp r1, r11 */
/* @0x2bb4ac bge 0x2bb550 <jinit_1pass_quantizer+0x820> */
/* @0x2bb4b0 sub r3, r10, #-1073741823 */
/* @0x2bb4b4 ldr r0, [sp, #0xc] */
/* @0x2bb4b8 lsl r8, r1, #6 */
/* @0x2bb4bc lsl r9, r5, #1 */
/* @0x2bb4c0 mov r12, r1 */
/* @0x2bb4c4 add r3, r0, r3, lsl #2 */
/* @0x2bb4c8 str r3, [sp, #0x4] */
/* @0x2bb4cc cmp r2, r10 */
/* @0x2bb4d0 blt 0x2bb528 <jinit_1pass_quantizer+0x7f8> */
/* @0x2bb4d4 ldr r7, [sp, #0x4] */
/* @0x2bb4d8 mov r4, r10 */
/* @0x2bb4dc ldr r3, [r7, #0x4]! */
/* @0x2bb4e0 cmp r5, r6 */
/* @0x2bb4e4 add r3, r3, r8 */
/* @0x2bb4e8 add r1, r3, r9 */
/* @0x2bb4ec bgt 0x2bb51c <jinit_1pass_quantizer+0x7ec> */
/* @0x2bb4f0 ldrh r3, [r3, r9] */
/* @0x2bb4f4 cmp r3, #0 */
/* @0x2bb4f8 bne 0x2bb814 <jinit_1pass_quantizer+0xae4> */
/* @0x2bb4fc mov r3, r5 */
/* @0x2bb500 b 0x2bb510 <jinit_1pass_quantizer+0x7e0> */
/* @0x2bb504 ldrh r0, [r1, #2]! */
/* @0x2bb508 cmp r0, #0 */
/* @0x2bb50c bne 0x2bb814 <jinit_1pass_quantizer+0xae4> */
/* @0x2bb510 add r3, r3, #1 */
/* @0x2bb514 cmp r6, r3 */
/* @0x2bb518 bge 0x2bb504 <jinit_1pass_quantizer+0x7d4> */
/* @0x2bb51c add r4, r4, #1 */
/* @0x2bb520 cmp r4, r2 */
/* @0x2bb524 ble 0x2bb4dc <jinit_1pass_quantizer+0x7ac> */
/* @0x2bb528 add r12, r12, #1 */
/* @0x2bb52c add r8, r8, #64 */
/* @0x2bb530 cmp r11, r12 */
/* @0x2bb534 bge 0x2bb4cc <jinit_1pass_quantizer+0x79c> */
/* @0x2bb538 ldr r12, [sp] */
/* @0x2bb53c b 0x2bb824 <jinit_1pass_quantizer+0xaf4> */
/* @0x2bb540 ldr r1, [sp, #0x8] */
/* @0x2bb544 mov r11, r4 */
/* @0x2bb548 str r12, [sp] */
/* @0x2bb54c str r4, [r1, #0xc] */
/* @0x2bb550 cmp r5, r6 */
/* @0x2bb554 bge 0x2bb5fc <jinit_1pass_quantizer+0x8cc> */
/* @0x2bb558 ldr r0, [sp] */
/* @0x2bb55c sub r3, r10, #-1073741823 */
/* @0x2bb560 ldr r1, [sp, #0xc] */
/* @0x2bb564 mov r12, r5 */
/* @0x2bb568 lsl r9, r0, #6 */
/* @0x2bb56c add r3, r1, r3, lsl #2 */
/* @0x2bb570 str r3, [sp, #0x4] */
/* @0x2bb574 cmp r2, r10 */
/* @0x2bb578 blt 0x2bb5d8 <jinit_1pass_quantizer+0x8a8> */
/* @0x2bb57c ldr r8, [sp, #0x4] */
/* @0x2bb580 lsl r7, r12, #1 */
/* @0x2bb584 mov r4, r10 */
/* @0x2bb588 ldr r0, [sp] */
/* @0x2bb58c ldr r3, [r8, #0x4]! */
/* @0x2bb590 cmp r11, r0 */
/* @0x2bb594 add r3, r3, r9 */
/* @0x2bb598 add r1, r3, r7 */
/* @0x2bb59c blt 0x2bb5cc <jinit_1pass_quantizer+0x89c> */
/* @0x2bb5a0 ldrh r3, [r3, r7] */
/* @0x2bb5a4 cmp r3, #0 */
/* @0x2bb5a8 bne 0x2bb6ec <jinit_1pass_quantizer+0x9bc> */
/* @0x2bb5ac ldr r3, [sp] */
/* @0x2bb5b0 b 0x2bb5c0 <jinit_1pass_quantizer+0x890> */
/* @0x2bb5b4 ldrh r0, [r1, #64]! */
/* @0x2bb5b8 cmp r0, #0 */
/* @0x2bb5bc bne 0x2bb6ec <jinit_1pass_quantizer+0x9bc> */
/* @0x2bb5c0 add r3, r3, #1 */
/* @0x2bb5c4 cmp r3, r11 */
/* @0x2bb5c8 ble 0x2bb5b4 <jinit_1pass_quantizer+0x884> */
/* @0x2bb5cc add r4, r4, #1 */
/* @0x2bb5d0 cmp r2, r4 */
/* @0x2bb5d4 bge 0x2bb588 <jinit_1pass_quantizer+0x858> */
/* @0x2bb5d8 add r12, r12, #1 */
/* @0x2bb5dc cmp r6, r12 */
/* @0x2bb5e0 bge 0x2bb574 <jinit_1pass_quantizer+0x844> */
/* @0x2bb5e4 mov r12, r5 */
/* @0x2bb5e8 b 0x2bb6fc <jinit_1pass_quantizer+0x9cc> */
/* @0x2bb5ec ldr r1, [sp, #0x8] */
/* @0x2bb5f0 mov r5, r12 */
/* @0x2bb5f4 mov r6, r4 */
/* @0x2bb5f8 str r4, [r1, #0x14] */
/* @0x2bb5fc ldr r0, [sp] */
/* @0x2bb600 rsb r1, r10, r2 */
/* @0x2bb604 rsb r12, r5, r6 */
/* @0x2bb608 cmp r2, r10 */
/* @0x2bb60c rsb r3, r0, r11 */
/* @0x2bb610 lsl r1, r1, #4 */
/* @0x2bb614 lsl r0, r3, #3 */
/* @0x2bb618 add r0, r0, r3, lsl #2 */
/* @0x2bb61c lsl r3, r12, #3 */
/* @0x2bb620 mul r0, r0, r0 */
/* @0x2bb624 mla r1, r1, r1, r0 */
/* @0x2bb628 mla r3, r3, r3, r1 */
/* @0x2bb62c ldr r1, [sp, #0x8] */
/* @0x2bb630 str r3, [r1, #0x18] */
/* @0x2bb634 blt 0x2bb8ac <jinit_1pass_quantizer+0xb7c> */
/* @0x2bb638 ldr r3, [sp] */
/* @0x2bb63c add r2, r2, #1 */
/* @0x2bb640 ldr r0, [sp, #0xc] */
/* @0x2bb644 mov r8, #0 */
/* @0x2bb648 add r12, r6, #1 */
/* @0x2bb64c rsb r2, r10, r2 */
/* @0x2bb650 add r9, r5, r3, lsl #5 */
/* @0x2bb654 add r3, r5, r11, lsl #5 */
/* @0x2bb658 sub r9, r9, #-2147483647 */
/* @0x2bb65c add r10, r0, r10, lsl #2 */
/* @0x2bb660 lsl r3, r3, #1 */
/* @0x2bb664 mov r0, r8 */
/* @0x2bb668 lsl r9, r9, #1 */
/* @0x2bb66c add r3, r3, #62 */
/* @0x2bb670 str r2, [sp, #0x4] */
/* @0x2bb674 str r3, [sp, #0xc] */
/* @0x2bb678 ldr r2, [sp] */
/* @0x2bb67c cmp r11, r2 */
/* @0x2bb680 blt 0x2bb6c8 <jinit_1pass_quantizer+0x998> */
/* @0x2bb684 ldr r7, [r10, r8, lsl #2] */
/* @0x2bb688 ldr r3, [sp, #0xc] */
/* @0x2bb68c add r4, r7, r9 */
/* @0x2bb690 add r7, r7, r3 */
/* @0x2bb694 cmp r6, r5 */
/* @0x2bb698 blt 0x2bb6bc <jinit_1pass_quantizer+0x98c> */
/* @0x2bb69c mov r2, r4 */
/* @0x2bb6a0 mov r3, r5 */
/* @0x2bb6a4 ldrh r1, [r2, #2]! */
/* @0x2bb6a8 add r3, r3, #1 */
/* @0x2bb6ac cmp r1, #0 */
/* @0x2bb6b0 addne r0, r0, #1 */
/* @0x2bb6b4 cmp r3, r12 */
/* @0x2bb6b8 bne 0x2bb6a4 <jinit_1pass_quantizer+0x974> */
/* @0x2bb6bc add r4, r4, #64 */
/* @0x2bb6c0 cmp r4, r7 */
/* @0x2bb6c4 bne 0x2bb694 <jinit_1pass_quantizer+0x964> */
/* @0x2bb6c8 ldr r1, [sp, #0x4] */
/* @0x2bb6cc add r8, r8, #1 */
/* @0x2bb6d0 cmp r8, r1 */
/* @0x2bb6d4 bne 0x2bb678 <jinit_1pass_quantizer+0x948> */
/* @0x2bb6d8 ldr r1, [sp, #0x8] */
/* @0x2bb6dc str r0, [r1, #0x1c] */
/* @0x2bb6e0 add sp, sp, #16 */
/* @0x2bb6e4 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2bb6e8 bx lr */
/* @0x2bb6ec ldr r1, [sp, #0x8] */
/* @0x2bb6f0 cmp r6, r12 */
/* @0x2bb6f4 str r12, [r1, #0x10] */
/* @0x2bb6f8 ble 0x2bb770 <jinit_1pass_quantizer+0xa40> */
/* @0x2bb6fc mov r4, r6 */
/* @0x2bb700 cmp r2, r10 */
/* @0x2bb704 blt 0x2bb764 <jinit_1pass_quantizer+0xa34> */
/* @0x2bb708 ldr r8, [sp, #0x4] */
/* @0x2bb70c lsl r7, r4, #1 */
/* @0x2bb710 mov r5, r10 */
/* @0x2bb714 ldr r0, [sp] */
/* @0x2bb718 ldr r3, [r8, #0x4]! */
/* @0x2bb71c cmp r11, r0 */
/* @0x2bb720 add r3, r3, r9 */
/* @0x2bb724 add r1, r3, r7 */
/* @0x2bb728 blt 0x2bb758 <jinit_1pass_quantizer+0xa28> */
/* @0x2bb72c ldrh r3, [r3, r7] */
/* @0x2bb730 cmp r3, #0 */
/* @0x2bb734 bne 0x2bb5ec <jinit_1pass_quantizer+0x8bc> */
/* @0x2bb738 ldr r3, [sp] */
/* @0x2bb73c b 0x2bb74c <jinit_1pass_quantizer+0xa1c> */
/* @0x2bb740 ldrh r0, [r1, #64]! */
/* @0x2bb744 cmp r0, #0 */
/* @0x2bb748 bne 0x2bb5ec <jinit_1pass_quantizer+0x8bc> */
/* @0x2bb74c add r3, r3, #1 */
/* @0x2bb750 cmp r11, r3 */
/* @0x2bb754 bge 0x2bb740 <jinit_1pass_quantizer+0xa10> */
/* @0x2bb758 add r5, r5, #1 */
/* @0x2bb75c cmp r2, r5 */
/* @0x2bb760 bge 0x2bb714 <jinit_1pass_quantizer+0x9e4> */
/* @0x2bb764 sub r4, r4, #1 */
/* @0x2bb768 cmp r4, r12 */
/* @0x2bb76c bge 0x2bb700 <jinit_1pass_quantizer+0x9d0> */
/* @0x2bb770 mov r5, r12 */
/* @0x2bb774 b 0x2bb5fc <jinit_1pass_quantizer+0x8cc> */
/* @0x2bb778 ldr r3, [sp, #0x8] */
/* @0x2bb77c cmp r2, r12 */
/* @0x2bb780 str r12, [r3] */
/* @0x2bb784 ble 0x2bb80c <jinit_1pass_quantizer+0xadc> */
/* @0x2bb788 ldr r3, [sp, #0xc] */
/* @0x2bb78c mov r4, r2 */
/* @0x2bb790 mov r8, #0 */
/* @0x2bb794 add r10, r3, r2, lsl #2 */
/* @0x2bb798 ldr r3, [sp] */
/* @0x2bb79c cmp r3, r11 */
/* @0x2bb7a0 bgt 0x2bb7fc <jinit_1pass_quantizer+0xacc> */
/* @0x2bb7a4 ldr r7, [r10, r8] */
/* @0x2bb7a8 mov r9, r3 */
/* @0x2bb7ac ldr r0, [sp, #0x4] */
/* @0x2bb7b0 add r7, r7, r0 */
/* @0x2bb7b4 cmp r5, r6 */
/* @0x2bb7b8 bgt 0x2bb7ec <jinit_1pass_quantizer+0xabc> */
/* @0x2bb7bc ldrh r3, [r7] */
/* @0x2bb7c0 cmp r3, #0 */
/* @0x2bb7c4 bne 0x2bb494 <jinit_1pass_quantizer+0x764> */
/* @0x2bb7c8 mov r1, r7 */
/* @0x2bb7cc mov r3, r5 */
/* @0x2bb7d0 b 0x2bb7e0 <jinit_1pass_quantizer+0xab0> */
/* @0x2bb7d4 ldrh r0, [r1, #2]! */
/* @0x2bb7d8 cmp r0, #0 */
/* @0x2bb7dc bne 0x2bb494 <jinit_1pass_quantizer+0x764> */
/* @0x2bb7e0 add r3, r3, #1 */
/* @0x2bb7e4 cmp r6, r3 */
/* @0x2bb7e8 bge 0x2bb7d4 <jinit_1pass_quantizer+0xaa4> */
/* @0x2bb7ec add r9, r9, #1 */
/* @0x2bb7f0 add r7, r7, #64 */
/* @0x2bb7f4 cmp r11, r9 */
/* @0x2bb7f8 bge 0x2bb7b4 <jinit_1pass_quantizer+0xa84> */
/* @0x2bb7fc sub r4, r4, #1 */
/* @0x2bb800 sub r8, r8, #4 */
/* @0x2bb804 cmp r4, r12 */
/* @0x2bb808 bge 0x2bb798 <jinit_1pass_quantizer+0xa68> */
/* @0x2bb80c mov r10, r12 */
/* @0x2bb810 b 0x2bb4a4 <jinit_1pass_quantizer+0x774> */
/* @0x2bb814 ldr r1, [sp, #0x8] */
/* @0x2bb818 cmp r11, r12 */
/* @0x2bb81c str r12, [r1, #0x8] */
/* @0x2bb820 ble 0x2bb8a4 <jinit_1pass_quantizer+0xb74> */
/* @0x2bb824 lsl r9, r11, #6 */
/* @0x2bb828 mov r4, r11 */
/* @0x2bb82c lsl r3, r5, #1 */
/* @0x2bb830 str r3, [sp] */
/* @0x2bb834 cmp r2, r10 */
/* @0x2bb838 blt 0x2bb894 <jinit_1pass_quantizer+0xb64> */
/* @0x2bb83c ldr r8, [sp, #0x4] */
/* @0x2bb840 mov r7, r10 */
/* @0x2bb844 ldr r3, [r8, #0x4]! */
/* @0x2bb848 cmp r5, r6 */
/* @0x2bb84c ldr r0, [sp] */
/* @0x2bb850 add r3, r3, r9 */
/* @0x2bb854 add r1, r3, r0 */
/* @0x2bb858 bgt 0x2bb888 <jinit_1pass_quantizer+0xb58> */
/* @0x2bb85c ldrh r3, [r3, r0] */
/* @0x2bb860 cmp r3, #0 */
/* @0x2bb864 bne 0x2bb540 <jinit_1pass_quantizer+0x810> */
/* @0x2bb868 mov r3, r5 */
/* @0x2bb86c b 0x2bb87c <jinit_1pass_quantizer+0xb4c> */
/* @0x2bb870 ldrh r0, [r1, #2]! */
/* @0x2bb874 cmp r0, #0 */
/* @0x2bb878 bne 0x2bb540 <jinit_1pass_quantizer+0x810> */
/* @0x2bb87c add r3, r3, #1 */
/* @0x2bb880 cmp r6, r3 */
/* @0x2bb884 bge 0x2bb870 <jinit_1pass_quantizer+0xb40> */
/* @0x2bb888 add r7, r7, #1 */
/* @0x2bb88c cmp r2, r7 */
/* @0x2bb890 bge 0x2bb844 <jinit_1pass_quantizer+0xb14> */
/* @0x2bb894 sub r4, r4, #1 */
/* @0x2bb898 sub r9, r9, #64 */
/* @0x2bb89c cmp r4, r12 */
/* @0x2bb8a0 bge 0x2bb834 <jinit_1pass_quantizer+0xb04> */
/* @0x2bb8a4 str r12, [sp] */
/* @0x2bb8a8 b 0x2bb550 <jinit_1pass_quantizer+0x820> */
/* @0x2bb8ac mov r0, #0 */
/* @0x2bb8b0 b 0x2bb6d8 <jinit_1pass_quantizer+0x9a8> */
/* @0x2bb8b4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bb8b8 sub sp, sp, #1504 */
/* @0x2bb8bc sub sp, sp, #4 */
/* @0x2bb8c0 asr r3, r3, #2 */
/* @0x2bb8c4 asr r1, r1, #2 */
/* @0x2bb8c8 ldr r5, [pc, #0x4c0] */
/* @0x2bb8cc lsl r7, r3, #5 */
/* @0x2bb8d0 str r0, [sp, #0x20] */
/* @0x2bb8d4 ldr r5, [pc, r5] */
/* @0x2bb8d8 str r1, [sp, #0x48] */
/* @0x2bb8dc str r5, [sp, #0x44] */
/* @0x2bb8e0 lsl r5, r1, #5 */
/* @0x2bb8e4 add r1, r7, #4 */
/* @0x2bb8e8 str r1, [sp, #0x2c] */
/* @0x2bb8ec ldr r1, [sp, #0x20] */
/* @0x2bb8f0 asr r2, r2, #3 */
/* @0x2bb8f4 add r8, r5, #4 */
/* @0x2bb8f8 str r8, [sp, #0x24] */
/* @0x2bb8fc ldr r8, [sp, #0x44] */
/* @0x2bb900 lsl r6, r2, #5 */
/* @0x2bb904 ldr r4, [r1, #0x1a8] */
/* @0x2bb908 add r10, r6, #2 */
/* @0x2bb90c str r10, [sp, #0x28] */
/* @0x2bb910 add r5, r5, #28 */
/* @0x2bb914 ldr r12, [r0, #0x70] */
/* @0x2bb918 add r6, r6, #30 */
/* @0x2bb91c str r2, [sp, #0x4c] */
/* @0x2bb920 add r7, r7, #28 */
/* @0x2bb924 ldr r2, [sp, #0x28] */
/* @0x2bb928 cmp r12, #0 */
/* @0x2bb92c str r3, [sp, #0x50] */
/* @0x2bb930 ldr r10, [sp, #0x24] */
/* @0x2bb934 add r1, r2, r6 */
/* @0x2bb938 ldr r3, [r8] */
/* @0x2bb93c ldr r8, [sp, #0x2c] */
/* @0x2bb940 add r0, r10, r5 */
/* @0x2bb944 ldr r4, [r4, #0x18] */
/* @0x2bb948 asr r1, r1, #1 */
/* @0x2bb94c add r2, r8, r7 */
/* @0x2bb950 asr r0, r0, #1 */
/* @0x2bb954 str r1, [sp, #0x18] */
/* @0x2bb958 asr r2, r2, #1 */
/* @0x2bb95c str r0, [sp, #0x10] */
/* @0x2bb960 str r2, [sp, #0x1c] */
/* @0x2bb964 str r3, [sp, #0x5dc] */
/* @0x2bb968 str r4, [sp, #0x54] */
/* @0x2bb96c ble 0x2bbd7c <jinit_1pass_quantizer+0x104c> */
/* @0x2bb970 ldr r10, [sp, #0x20] */
/* @0x2bb974 add r4, sp, #36 */
/* @0x2bb978 add r1, sp, #92 */
/* @0x2bb97c mvn r0, #-2147483648 */
/* @0x2bb980 str r1, [sp, #0x14] */
/* @0x2bb984 mov r3, #0 */
/* @0x2bb988 ldr r2, [r10, #0x74] */
/* @0x2bb98c ldm r4, {r4, r8, r9} */
/* @0x2bb990 ldm r2, {r10, r11} */
/* @0x2bb994 ldr r2, [r2, #0x8] */
/* @0x2bb998 str r12, [sp, #0x4] */
/* @0x2bb99c str r10, [sp, #0xc] */
/* @0x2bb9a0 str r2, [sp, #0x8] */
/* @0x2bb9a4 b 0x2bba24 <jinit_1pass_quantizer+0xcf4> */
/* @0x2bb9a8 rsb r2, r4, r1 */
/* @0x2bb9ac rsb r10, r5, r1 */
/* @0x2bb9b0 lsl r2, r2, #1 */
/* @0x2bb9b4 lsl r10, r10, #1 */
/* @0x2bb9b8 mul r2, r2, r2 */
/* @0x2bb9bc mul r10, r10, r10 */
/* @0x2bb9c0 ldrb r1, [r11, r3] */
/* @0x2bb9c4 cmp r8, r1 */
/* @0x2bb9c8 ble 0x2bba60 <jinit_1pass_quantizer+0xd30> */
/* @0x2bb9cc rsb r12, r8, r1 */
/* @0x2bb9d0 rsb r1, r6, r1 */
/* @0x2bb9d4 add r12, r12, r12, lsl #1 */
/* @0x2bb9d8 add r1, r1, r1, lsl #1 */
/* @0x2bb9dc mla r2, r12, r12, r2 */
/* @0x2bb9e0 mla r12, r1, r1, r10 */
/* @0x2bb9e4 ldr r10, [sp, #0x8] */
/* @0x2bb9e8 ldrb r1, [r10, r3] */
/* @0x2bb9ec cmp r9, r1 */
/* @0x2bb9f0 ble 0x2bba90 <jinit_1pass_quantizer+0xd60> */
/* @0x2bb9f4 rsb r10, r9, r1 */
/* @0x2bb9f8 rsb r1, r7, r1 */
/* @0x2bb9fc mla r2, r10, r10, r2 */
/* @0x2bba00 mla r1, r1, r1, r12 */
/* @0x2bba04 ldr r12, [sp, #0x14] */
/* @0x2bba08 cmp r0, r1 */
/* @0x2bba0c movge r0, r1 */
/* @0x2bba10 ldr r1, [sp, #0x4] */
/* @0x2bba14 str r2, [r12, r3, lsl #2] */
/* @0x2bba18 add r3, r3, #1 */
/* @0x2bba1c cmp r3, r1 */
/* @0x2bba20 beq 0x2bbb00 <jinit_1pass_quantizer+0xdd0> */
/* @0x2bba24 ldr r2, [sp, #0xc] */
/* @0x2bba28 ldrb r1, [r2, r3] */
/* @0x2bba2c cmp r4, r1 */
/* @0x2bba30 bgt 0x2bb9a8 <jinit_1pass_quantizer+0xc78> */
/* @0x2bba34 cmp r5, r1 */
/* @0x2bba38 bge 0x2bbaac <jinit_1pass_quantizer+0xd7c> */
/* @0x2bba3c rsb r2, r5, r1 */
/* @0x2bba40 rsb r1, r4, r1 */
/* @0x2bba44 lsl r10, r1, #1 */
/* @0x2bba48 ldrb r1, [r11, r3] */
/* @0x2bba4c lsl r2, r2, #1 */
/* @0x2bba50 cmp r8, r1 */
/* @0x2bba54 mul r2, r2, r2 */
/* @0x2bba58 mul r10, r10, r10 */
/* @0x2bba5c bgt 0x2bb9cc <jinit_1pass_quantizer+0xc9c> */
/* @0x2bba60 cmp r6, r1 */
/* @0x2bba64 bge 0x2bbae4 <jinit_1pass_quantizer+0xdb4> */
/* @0x2bba68 rsb r12, r6, r1 */
/* @0x2bba6c rsb r1, r8, r1 */
/* @0x2bba70 add r12, r12, r12, lsl #1 */
/* @0x2bba74 add r1, r1, r1, lsl #1 */
/* @0x2bba78 mla r2, r12, r12, r2 */
/* @0x2bba7c mla r12, r1, r1, r10 */
/* @0x2bba80 ldr r10, [sp, #0x8] */
/* @0x2bba84 ldrb r1, [r10, r3] */
/* @0x2bba88 cmp r9, r1 */
/* @0x2bba8c bgt 0x2bb9f4 <jinit_1pass_quantizer+0xcc4> */
/* @0x2bba90 cmp r7, r1 */
/* @0x2bba94 bge 0x2bbacc <jinit_1pass_quantizer+0xd9c> */
/* @0x2bba98 rsb r10, r7, r1 */
/* @0x2bba9c rsb r1, r9, r1 */
/* @0x2bbaa0 mla r2, r10, r10, r2 */
/* @0x2bbaa4 mla r1, r1, r1, r12 */
/* @0x2bbaa8 b 0x2bba04 <jinit_1pass_quantizer+0xcd4> */
/* @0x2bbaac ldr r10, [sp, #0x10] */
/* @0x2bbab0 mov r2, #0 */
/* @0x2bbab4 cmp r10, r1 */
/* @0x2bbab8 rsbge r1, r5, r1 */
/* @0x2bbabc rsblt r1, r4, r1 */
/* @0x2bbac0 lsl r10, r1, #1 */
/* @0x2bbac4 mul r10, r10, r10 */
/* @0x2bbac8 b 0x2bb9c0 <jinit_1pass_quantizer+0xc90> */
/* @0x2bbacc ldr r10, [sp, #0x1c] */
/* @0x2bbad0 cmp r10, r1 */
/* @0x2bbad4 rsbge r1, r7, r1 */
/* @0x2bbad8 rsblt r1, r9, r1 */
/* @0x2bbadc mla r1, r1, r1, r12 */
/* @0x2bbae0 b 0x2bba04 <jinit_1pass_quantizer+0xcd4> */
/* @0x2bbae4 ldr r12, [sp, #0x18] */
/* @0x2bbae8 cmp r12, r1 */
/* @0x2bbaec rsbge r12, r6, r1 */
/* @0x2bbaf0 rsblt r12, r8, r1 */
/* @0x2bbaf4 add r12, r12, r12, lsl #1 */
/* @0x2bbaf8 mla r12, r12, r12, r10 */
/* @0x2bbafc b 0x2bb9e4 <jinit_1pass_quantizer+0xcb4> */
/* @0x2bbb00 ldr r3, [sp, #0x14] */
/* @0x2bbb04 mov r12, r1 */
/* @0x2bbb08 mov r1, #0 */
/* @0x2bbb0c sub r2, r3, #4 */
/* @0x2bbb10 mov r3, r1 */
/* @0x2bbb14 ldr r4, [r2, #0x4]! */
/* @0x2bbb18 cmp r4, r0 */
/* @0x2bbb1c addle r5, sp, #1504 */
/* @0x2bbb20 addle r4, r5, r1 */
/* @0x2bbb24 addle r1, r1, #1 */
/* @0x2bbb28 strble r3, [r4, #-0x104] */
/* @0x2bbb2c add r3, r3, #1 */
/* @0x2bbb30 cmp r3, r12 */
/* @0x2bbb34 bne 0x2bbb14 <jinit_1pass_quantizer+0xde4> */
/* @0x2bbb38 ldr r3, [sp, #0x14] */
/* @0x2bbb3c add r0, sp, #604 */
/* @0x2bbb40 mvn r2, #-2147483648 */
/* @0x2bbb44 str r2, [r3], #4 */
/* @0x2bbb48 cmp r3, r0 */
/* @0x2bbb4c bne 0x2bbb44 <jinit_1pass_quantizer+0xe14> */
/* @0x2bbb50 cmp r1, #0 */
/* @0x2bbb54 beq 0x2bbce0 <jinit_1pass_quantizer+0xfb0> */
/* @0x2bbb58 ldr r5, [sp, #0x20] */
/* @0x2bbb5c add r8, sp, #1232 */
/* @0x2bbb60 add r8, r8, #11 */
/* @0x2bbb64 add r10, sp, #1104 */
/* @0x2bbb68 add r1, r8, r1 */
/* @0x2bbb6c str r1, [sp, #0x30] */
/* @0x2bbb70 ldr r3, [r5, #0x74] */
/* @0x2bbb74 add r10, r10, #12 */
/* @0x2bbb78 str r8, [sp, #0x20] */
/* @0x2bbb7c str r10, [sp, #0x40] */
/* @0x2bbb80 ldr r12, [r3] */
/* @0x2bbb84 ldr r1, [r3, #0x4] */
/* @0x2bbb88 ldr r3, [r3, #0x8] */
/* @0x2bbb8c str r12, [sp, #0x34] */
/* @0x2bbb90 str r1, [sp, #0x38] */
/* @0x2bbb94 str r3, [sp, #0x3c] */
/* @0x2bbb98 ldr r2, [sp, #0x20] */
/* @0x2bbb9c add r3, sp, #1104 */
/* @0x2bbba0 ldr r8, [sp, #0x38] */
/* @0x2bbba4 add r3, r3, #12 */
/* @0x2bbba8 ldr r5, [sp, #0x14] */
/* @0x2bbbac add r3, r3, #1 */
/* @0x2bbbb0 ldrb r9, [r2, #0x1]! */
/* @0x2bbbb4 ldr r10, [sp, #0x34] */
/* @0x2bbbb8 ldr r12, [sp, #0x28] */
/* @0x2bbbbc ldrb r11, [r8, r9] */
/* @0x2bbbc0 ldrb r1, [r10, r9] */
/* @0x2bbbc4 str r5, [sp, #0x10] */
/* @0x2bbbc8 rsb r11, r11, r12 */
/* @0x2bbbcc ldr r5, [sp, #0x24] */
/* @0x2bbbd0 str r2, [sp, #0x20] */
/* @0x2bbbd4 add r11, r11, r11, lsl #1 */
/* @0x2bbbd8 ldr r2, [sp, #0x3c] */
/* @0x2bbbdc rsb r1, r1, r5 */
/* @0x2bbbe0 str r3, [sp, #0x8] */
/* @0x2bbbe4 lsl r1, r1, #1 */
/* @0x2bbbe8 ldr r8, [sp, #0x2c] */
/* @0x2bbbec ldrb r3, [r2, r9] */
/* @0x2bbbf0 mul r2, r11, r11 */
/* @0x2bbbf4 rsb r3, r3, r8 */
/* @0x2bbbf8 mla r2, r1, r1, r2 */
/* @0x2bbbfc add r10, r3, #4 */
/* @0x2bbc00 add r11, r11, r11, lsl #1 */
/* @0x2bbc04 add r1, r1, #8 */
/* @0x2bbc08 lsl r10, r10, #4 */
/* @0x2bbc0c lsl r11, r11, #3 */
/* @0x2bbc10 add r5, r10, #512 */
/* @0x2bbc14 add r12, r11, #144 */
/* @0x2bbc18 add r11, r11, #2448 */
/* @0x2bbc1c mla r2, r3, r3, r2 */
/* @0x2bbc20 lsl r1, r1, #5 */
/* @0x2bbc24 str r12, [sp, #0x18] */
/* @0x2bbc28 str r1, [sp, #0x4] */
/* @0x2bbc2c add r1, r1, #2048 */
/* @0x2bbc30 str r1, [sp, #0x1c] */
/* @0x2bbc34 str r2, [sp, #0xc] */
/* @0x2bbc38 ldr r8, [sp, #0x8] */
/* @0x2bbc3c ldr r4, [sp, #0x18] */
/* @0x2bbc40 ldr r7, [sp, #0xc] */
/* @0x2bbc44 ldr r6, [sp, #0x10] */
/* @0x2bbc48 mov r0, r6 */
/* @0x2bbc4c mov r1, r8 */
/* @0x2bbc50 mov r3, r10 */
/* @0x2bbc54 mov r2, r7 */
/* @0x2bbc58 ldr r12, [r0], #4 */
/* @0x2bbc5c add r1, r1, #1 */
/* @0x2bbc60 cmp r12, r2 */
/* @0x2bbc64 strbgt r9, [r1, #-0x2] */
/* @0x2bbc68 strgt r2, [r0, #-0x4] */
/* @0x2bbc6c add r2, r2, r3 */
/* @0x2bbc70 add r3, r3, #128 */
/* @0x2bbc74 cmp r3, r5 */
/* @0x2bbc78 bne 0x2bbc58 <jinit_1pass_quantizer+0xf28> */
/* @0x2bbc7c add r7, r7, r4 */
/* @0x2bbc80 add r4, r4, #288 */
/* @0x2bbc84 cmp r4, r11 */
/* @0x2bbc88 add r6, r6, #16 */
/* @0x2bbc8c add r8, r8, #4 */
/* @0x2bbc90 bne 0x2bbc48 <jinit_1pass_quantizer+0xf18> */
/* @0x2bbc94 ldr r3, [sp, #0x4] */
/* @0x2bbc98 ldr r2, [sp, #0xc] */
/* @0x2bbc9c ldr r8, [sp, #0x1c] */
/* @0x2bbca0 add r2, r2, r3 */
/* @0x2bbca4 add r3, r3, #512 */
/* @0x2bbca8 ldr r12, [sp, #0x10] */
/* @0x2bbcac cmp r3, r8 */
/* @0x2bbcb0 ldr r1, [sp, #0x8] */
/* @0x2bbcb4 add r12, r12, #128 */
/* @0x2bbcb8 str r2, [sp, #0xc] */
/* @0x2bbcbc add r1, r1, #32 */
/* @0x2bbcc0 str r3, [sp, #0x4] */
/* @0x2bbcc4 str r12, [sp, #0x10] */
/* @0x2bbcc8 str r1, [sp, #0x8] */
/* @0x2bbccc bne 0x2bbc38 <jinit_1pass_quantizer+0xf08> */
/* @0x2bbcd0 ldr r2, [sp, #0x20] */
/* @0x2bbcd4 ldr r3, [sp, #0x30] */
/* @0x2bbcd8 cmp r2, r3 */
/* @0x2bbcdc bne 0x2bbb98 <jinit_1pass_quantizer+0xe68> */
/* @0x2bbce0 ldr r10, [sp, #0x50] */
/* @0x2bbce4 add r5, sp, #1136 */
/* @0x2bbce8 ldr r2, [sp, #0x4c] */
/* @0x2bbcec add r8, sp, #1264 */
/* @0x2bbcf0 ldr r1, [sp, #0x48] */
/* @0x2bbcf4 add r5, r5, #12 */
/* @0x2bbcf8 lsl r7, r10, #2 */
/* @0x2bbcfc ldr r12, [sp, #0x54] */
/* @0x2bbd00 add r7, r7, r2, lsl #8 */
/* @0x2bbd04 add r8, r8, #12 */
/* @0x2bbd08 add r6, r12, r1, lsl #4 */
/* @0x2bbd0c sub r6, r6, #4 */
/* @0x2bbd10 lsl r7, r7, #1 */
/* @0x2bbd14 ldr r4, [r6, #0x4]! */
/* @0x2bbd18 sub r12, r5, #32 */
/* @0x2bbd1c add r4, r4, r7 */
/* @0x2bbd20 add r0, r4, #8 */
/* @0x2bbd24 mov r3, r4 */
/* @0x2bbd28 mov r2, r12 */
/* @0x2bbd2c ldrb r1, [r2], #1 */
/* @0x2bbd30 add r1, r1, #1 */
/* @0x2bbd34 strh r1, [r3], #2 */
/* @0x2bbd38 cmp r3, r0 */
/* @0x2bbd3c bne 0x2bbd2c <jinit_1pass_quantizer+0xffc> */
/* @0x2bbd40 add r12, r12, #4 */
/* @0x2bbd44 add r4, r4, #64 */
/* @0x2bbd48 cmp r12, r5 */
/* @0x2bbd4c bne 0x2bbd20 <jinit_1pass_quantizer+0xff0> */
/* @0x2bbd50 add r5, r12, #32 */
/* @0x2bbd54 cmp r5, r8 */
/* @0x2bbd58 bne 0x2bbd14 <jinit_1pass_quantizer+0xfe4> */
/* @0x2bbd5c ldr r5, [sp, #0x44] */
/* @0x2bbd60 ldr r2, [sp, #0x5dc] */
/* @0x2bbd64 ldr r3, [r5] */
/* @0x2bbd68 cmp r2, r3 */
/* @0x2bbd6c bne 0x2bbd8c <jinit_1pass_quantizer+0x105c> */
/* @0x2bbd70 add sp, sp, #1504 */
/* @0x2bbd74 add sp, sp, #4 */
/* @0x2bbd78 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bbd7c add r8, sp, #92 */
/* @0x2bbd80 mov r1, #0 */
/* @0x2bbd84 str r8, [sp, #0x14] */
/* @0x2bbd88 b 0x2bbb38 <jinit_1pass_quantizer+0xe08> */
/* @0x2bbd8c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2bbd90 andseq r2, r3, r12, ror r0 */
/* @0x2bbd94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bbd98 sub sp, sp, #28 */
/* @0x2bbd9c cmp r3, #0 */
/* @0x2bbda0 str r2, [sp, #0x10] */
/* @0x2bbda4 str r3, [sp, #0x14] */
/* @0x2bbda8 ldr r2, [r0, #0x5c] */
/* @0x2bbdac ldr r3, [r0, #0x1a8] */
/* @0x2bbdb0 str r1, [sp, #0xc] */
/* @0x2bbdb4 str r2, [sp, #0x8] */
/* @0x2bbdb8 ldr r11, [r3, #0x18] */
/* @0x2bbdbc ble 0x2bbe64 <jinit_1pass_quantizer+0x1134> */
/* @0x2bbdc0 mov r10, r11 */
/* @0x2bbdc4 mov r11, r0 */
/* @0x2bbdc8 mov r9, #0 */
/* @0x2bbdcc str r9, [sp, #0x4] */
/* @0x2bbdd0 ldr r3, [sp, #0x8] */
/* @0x2bbdd4 ldr r2, [sp, #0xc] */
/* @0x2bbdd8 cmp r3, #0 */
/* @0x2bbddc ldr r3, [sp, #0x10] */
/* @0x2bbde0 ldr r4, [r2, r9] */
/* @0x2bbde4 ldr r8, [r3, r9] */
/* @0x2bbde8 ldrne r5, [sp, #0x8] */
/* @0x2bbdec bne 0x2bbe08 <jinit_1pass_quantizer+0x10d8> */
/* @0x2bbdf0 b 0x2bbe48 <jinit_1pass_quantizer+0x1118> */
/* @0x2bbdf4 subs r5, r5, #1 */
/* @0x2bbdf8 sub r12, r12, #1 */
/* @0x2bbdfc add r4, r4, #3 */
/* @0x2bbe00 strb r12, [r8], #1 */
/* @0x2bbe04 beq 0x2bbe48 <jinit_1pass_quantizer+0x1118> */
/* @0x2bbe08 ldrb r1, [r4] */
/* @0x2bbe0c ldrb r2, [r4, #0x1] */
/* @0x2bbe10 ldrb r3, [r4, #0x2] */
/* @0x2bbe14 lsr r1, r1, #3 */
/* @0x2bbe18 lsr r2, r2, #2 */
/* @0x2bbe1c ldr r7, [r10, r1, lsl #2] */
/* @0x2bbe20 lsr r3, r3, #3 */
/* @0x2bbe24 add r7, r7, r2, lsl #6 */
/* @0x2bbe28 lsl r6, r3, #1 */
/* @0x2bbe2c ldrh r12, [r7, r6] */
/* @0x2bbe30 cmp r12, #0 */
/* @0x2bbe34 bne 0x2bbdf4 <jinit_1pass_quantizer+0x10c4> */
/* @0x2bbe38 mov r0, r11 */
/* @0x2bbe3c bl 0x2bb8b4 <jinit_1pass_quantizer+0xb84> */
/* @0x2bbe40 ldrh r12, [r7, r6] */
/* @0x2bbe44 b 0x2bbdf4 <jinit_1pass_quantizer+0x10c4> */
/* @0x2bbe48 ldr r2, [sp, #0x4] */
/* @0x2bbe4c add r9, r9, #4 */
/* @0x2bbe50 ldr r3, [sp, #0x14] */
/* @0x2bbe54 add r2, r2, #1 */
/* @0x2bbe58 str r2, [sp, #0x4] */
/* @0x2bbe5c cmp r2, r3 */
/* @0x2bbe60 bne 0x2bbdd0 <jinit_1pass_quantizer+0x10a0> */
/* @0x2bbe64 add sp, sp, #28 */
/* @0x2bbe68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bbe6c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bbe70 sub sp, sp, #124 */
/* @0x2bbe74 ldr r4, [r0, #0x1a8] */
/* @0x2bbe78 cmp r3, #0 */
/* @0x2bbe7c ldr r8, [r0, #0x5c] */
/* @0x2bbe80 str r3, [sp, #0x60] */
/* @0x2bbe84 ldr r9, [r4, #0x18] */
/* @0x2bbe88 ldr r3, [r0, #0x74] */
/* @0x2bbe8c ldr r12, [r4, #0x28] */
/* @0x2bbe90 str r4, [sp, #0x50] */
/* @0x2bbe94 str r8, [sp, #0x48] */
/* @0x2bbe98 ldr r4, [r3] */
/* @0x2bbe9c ldr r8, [r3, #0x4] */
/* @0x2bbea0 str r9, [sp, #0x34] */
/* @0x2bbea4 ldr r3, [r3, #0x8] */
/* @0x2bbea8 ldr r9, [r0, #0x120] */
/* @0x2bbeac str r0, [sp, #0x4c] */
/* @0x2bbeb0 str r12, [sp, #0x68] */
/* @0x2bbeb4 str r4, [sp, #0x38] */
/* @0x2bbeb8 str r8, [sp, #0x3c] */
/* @0x2bbebc str r3, [sp, #0x40] */
/* @0x2bbec0 str r9, [sp, #0xc] */
/* @0x2bbec4 ble 0x2bc1a4 <jinit_1pass_quantizer+0x1474> */
/* @0x2bbec8 ldr r11, [sp, #0x48] */
/* @0x2bbecc sub r2, r2, #4 */
/* @0x2bbed0 sub r1, r1, #4 */
/* @0x2bbed4 str r2, [sp, #0x5c] */
/* @0x2bbed8 add r3, r11, #1 */
/* @0x2bbedc mov r12, #0 */
/* @0x2bbee0 add r0, r11, r11, lsl #1 */
/* @0x2bbee4 sub r4, r11, #1 */
/* @0x2bbee8 add r3, r3, r3, lsl #1 */
/* @0x2bbeec sub r2, r0, #3 */
/* @0x2bbef0 str r1, [sp, #0x58] */
/* @0x2bbef4 lsl r3, r3, #1 */
/* @0x2bbef8 str r2, [sp, #0x6c] */
/* @0x2bbefc str r12, [sp, #0x54] */
/* @0x2bbf00 str r4, [sp, #0x74] */
/* @0x2bbf04 str r3, [sp, #0x70] */
/* @0x2bbf08 ldr r8, [sp, #0x50] */
/* @0x2bbf0c ldr r9, [sp, #0x58] */
/* @0x2bbf10 ldr r12, [sp, #0x5c] */
/* @0x2bbf14 ldrb r3, [r8, #0x24] */
/* @0x2bbf18 ldr r5, [r9, #0x4]! */
/* @0x2bbf1c ldr r11, [r12, #0x4]! */
/* @0x2bbf20 cmp r3, #0 */
/* @0x2bbf24 str r9, [sp, #0x58] */
/* @0x2bbf28 str r12, [sp, #0x5c] */
/* @0x2bbf2c str r11, [sp, #0x10] */
/* @0x2bbf30 beq 0x2bc1ac <jinit_1pass_quantizer+0x147c> */
/* @0x2bbf34 ldr r3, [r8, #0x20] */
/* @0x2bbf38 mov r9, #0 */
/* @0x2bbf3c ldr r8, [sp, #0x74] */
/* @0x2bbf40 ldr r4, [sp, #0x6c] */
/* @0x2bbf44 add r11, r11, r8 */
/* @0x2bbf48 mvn r8, #0 */
/* @0x2bbf4c str r8, [sp, #0x64] */
/* @0x2bbf50 add r5, r5, r4 */
/* @0x2bbf54 ldr r8, [sp, #0x48] */
/* @0x2bbf58 mvn r4, #2 */
/* @0x2bbf5c str r11, [sp, #0x10] */
/* @0x2bbf60 ldr r11, [sp, #0x50] */
/* @0x2bbf64 cmp r8, #0 */
/* @0x2bbf68 ldr r12, [sp, #0x70] */
/* @0x2bbf6c str r4, [sp, #0x30] */
/* @0x2bbf70 add r3, r3, r12 */
/* @0x2bbf74 strb r9, [r11, #0x24] */
/* @0x2bbf78 str r3, [sp, #0x44] */
/* @0x2bbf7c beq 0x2bc1e0 <jinit_1pass_quantizer+0x14b0> */
/* @0x2bbf80 ldr r9, [sp, #0x30] */
/* @0x2bbf84 mov r7, #0 */
/* @0x2bbf88 mov r2, r7 */
/* @0x2bbf8c str r7, [sp, #0x18] */
/* @0x2bbf90 str r7, [sp, #0x14] */
/* @0x2bbf94 mov r12, r7 */
/* @0x2bbf98 lsl r9, r9, #1 */
/* @0x2bbf9c str r7, [sp, #0x2c] */
/* @0x2bbfa0 str r9, [sp, #0x1c] */
/* @0x2bbfa4 mov r9, r7 */
/* @0x2bbfa8 str r7, [sp, #0x28] */
/* @0x2bbfac str r7, [sp, #0x24] */
/* @0x2bbfb0 str r7, [sp, #0x20] */
/* @0x2bbfb4 str r8, [sp, #0x8] */
/* @0x2bbfb8 ldr r4, [sp, #0x44] */
/* @0x2bbfbc ldr r7, [sp, #0x68] */
/* @0x2bbfc0 b 0x2bc0a4 <jinit_1pass_quantizer+0x1374> */
/* @0x2bbfc4 ldr r11, [sp, #0x10] */
/* @0x2bbfc8 sub r3, r0, #1 */
/* @0x2bbfcc ldr r12, [sp, #0x64] */
/* @0x2bbfd0 strb r3, [r11], r12 */
/* @0x2bbfd4 ldr r12, [sp, #0x8] */
/* @0x2bbfd8 str r11, [sp, #0x10] */
/* @0x2bbfdc subs r12, r12, #1 */
/* @0x2bbfe0 str r12, [sp, #0x8] */
/* @0x2bbfe4 ldr r12, [sp, #0x38] */
/* @0x2bbfe8 ldr r11, [sp, #0x30] */
/* @0x2bbfec ldrb r2, [r12, r3] */
/* @0x2bbff0 add r5, r5, r11 */
/* @0x2bbff4 ldr r11, [sp, #0x3c] */
/* @0x2bbff8 ldr r12, [sp, #0x40] */
/* @0x2bbffc rsb r8, r2, r8 */
/* @0x2bc000 ldrb r0, [r11, r3] */
/* @0x2bc004 ldrb r3, [r12, r3] */
/* @0x2bc008 lsl r12, r8, #1 */
/* @0x2bc00c ldr r11, [sp, #0x14] */
/* @0x2bc010 rsb r0, r0, r10 */
/* @0x2bc014 add r10, r8, r12 */
/* @0x2bc018 rsb r3, r3, r9 */
/* @0x2bc01c add r11, r10, r11 */
/* @0x2bc020 str r11, [sp] */
/* @0x2bc024 ldr r11, [sp, #0x24] */
/* @0x2bc028 add r10, r10, r12 */
/* @0x2bc02c lsl r1, r0, #1 */
/* @0x2bc030 str r8, [sp, #0x24] */
/* @0x2bc034 add r11, r11, r10 */
/* @0x2bc038 ldr r8, [sp] */
/* @0x2bc03c str r11, [sp, #0x14] */
/* @0x2bc040 add r9, r0, r1 */
/* @0x2bc044 ldr r11, [sp, #0x18] */
/* @0x2bc048 lsl r2, r3, #1 */
/* @0x2bc04c add r12, r10, r12 */
/* @0x2bc050 strh r8, [r4] */
/* @0x2bc054 add r10, r9, r11 */
/* @0x2bc058 ldr r11, [sp, #0x28] */
/* @0x2bc05c str r0, [sp, #0x28] */
/* @0x2bc060 add r8, r3, r2 */
/* @0x2bc064 ldr r0, [sp, #0x20] */
/* @0x2bc068 add r9, r9, r1 */
/* @0x2bc06c strh r10, [r4, #2] */
/* @0x2bc070 add r10, r8, r2 */
/* @0x2bc074 add r8, r8, r0 */
/* @0x2bc078 strh r8, [r4, #4] */
/* @0x2bc07c ldr r8, [sp, #0x2c] */
/* @0x2bc080 add r11, r11, r9 */
/* @0x2bc084 add r2, r10, r2 */
/* @0x2bc088 str r11, [sp, #0x18] */
/* @0x2bc08c add r10, r8, r10 */
/* @0x2bc090 add r9, r9, r1 */
/* @0x2bc094 mov r4, r6 */
/* @0x2bc098 str r10, [sp, #0x20] */
/* @0x2bc09c str r3, [sp, #0x2c] */
/* @0x2bc0a0 beq 0x2bc150 <jinit_1pass_quantizer+0x1420> */
/* @0x2bc0a4 ldr r11, [sp, #0x1c] */
/* @0x2bc0a8 ldrb r8, [r5] */
/* @0x2bc0ac add r6, r4, r11 */
/* @0x2bc0b0 ldrb r0, [r5, #0x2] */
/* @0x2bc0b4 ldrsh r10, [r4, r11] */
/* @0x2bc0b8 ldrsh r3, [r6, #4] */
/* @0x2bc0bc ldrsh r1, [r6, #2] */
/* @0x2bc0c0 add r12, r10, r12 */
/* @0x2bc0c4 add r2, r3, r2 */
/* @0x2bc0c8 add r12, r12, #8 */
/* @0x2bc0cc add r9, r1, r9 */
/* @0x2bc0d0 add r2, r2, #8 */
/* @0x2bc0d4 add r9, r9, #8 */
/* @0x2bc0d8 asr r12, r12, #4 */
/* @0x2bc0dc asr r2, r2, #4 */
/* @0x2bc0e0 ldrb r3, [r5, #0x1] */
/* @0x2bc0e4 asr r9, r9, #4 */
/* @0x2bc0e8 ldr r12, [r7, r12, lsl #2] */
/* @0x2bc0ec ldr r1, [r7, r2, lsl #2] */
/* @0x2bc0f0 ldr r2, [r7, r9, lsl #2] */
/* @0x2bc0f4 ldr r9, [sp, #0xc] */
/* @0x2bc0f8 ldr r11, [sp, #0x34] */
/* @0x2bc0fc add r12, r9, r12 */
/* @0x2bc100 add r2, r9, r2 */
/* @0x2bc104 add r1, r9, r1 */
/* @0x2bc108 ldrb r8, [r12, r8] */
/* @0x2bc10c ldrb r9, [r1, r0] */
/* @0x2bc110 ldrb r10, [r2, r3] */
/* @0x2bc114 asr r1, r8, #3 */
/* @0x2bc118 asr r3, r9, #3 */
/* @0x2bc11c ldr r12, [r11, r1, lsl #2] */
/* @0x2bc120 asr r2, r10, #2 */
/* @0x2bc124 lsl r11, r3, #1 */
/* @0x2bc128 add r12, r12, r2, lsl #6 */
/* @0x2bc12c ldrh r0, [r12, r11] */
/* @0x2bc130 cmp r0, #0 */
/* @0x2bc134 bne 0x2bbfc4 <jinit_1pass_quantizer+0x1294> */
/* @0x2bc138 ldr r0, [sp, #0x4c] */
/* @0x2bc13c str r12, [sp, #0x4] */
/* @0x2bc140 bl 0x2bb8b4 <jinit_1pass_quantizer+0xb84> */
/* @0x2bc144 ldr r12, [sp, #0x4] */
/* @0x2bc148 ldrh r0, [r12, r11] */
/* @0x2bc14c b 0x2bbfc4 <jinit_1pass_quantizer+0x1294> */
/* @0x2bc150 ldr r12, [sp, #0x44] */
/* @0x2bc154 mov r7, r10 */
/* @0x2bc158 ldr r9, [sp, #0x1c] */
/* @0x2bc15c uxth r7, r7 */
/* @0x2bc160 ldr r11, [sp, #0x48] */
/* @0x2bc164 ldr r4, [sp, #0x14] */
/* @0x2bc168 ldr r8, [sp, #0x18] */
/* @0x2bc16c mla r12, r11, r9, r12 */
/* @0x2bc170 uxth r3, r4 */
/* @0x2bc174 uxth r10, r8 */
/* @0x2bc178 str r12, [sp, #0x44] */
/* @0x2bc17c ldr r9, [sp, #0x54] */
/* @0x2bc180 ldr r12, [sp, #0x60] */
/* @0x2bc184 ldr r11, [sp, #0x44] */
/* @0x2bc188 add r9, r9, #1 */
/* @0x2bc18c cmp r9, r12 */
/* @0x2bc190 str r9, [sp, #0x54] */
/* @0x2bc194 strh r3, [r11] */
/* @0x2bc198 strh r10, [r11, #2] */
/* @0x2bc19c strh r7, [r11, #4] */
/* @0x2bc1a0 bne 0x2bbf08 <jinit_1pass_quantizer+0x11d8> */
/* @0x2bc1a4 add sp, sp, #124 */
/* @0x2bc1a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bc1ac ldr r9, [sp, #0x50] */
/* @0x2bc1b0 mov r11, #3 */
/* @0x2bc1b4 ldr r8, [sp, #0x48] */
/* @0x2bc1b8 mov r12, #1 */
/* @0x2bc1bc ldr r4, [sp, #0x50] */
/* @0x2bc1c0 mov r0, #1 */
/* @0x2bc1c4 ldr r9, [r9, #0x20] */
/* @0x2bc1c8 cmp r8, #0 */
/* @0x2bc1cc str r11, [sp, #0x30] */
/* @0x2bc1d0 str r12, [sp, #0x64] */
/* @0x2bc1d4 str r9, [sp, #0x44] */
/* @0x2bc1d8 strb r0, [r4, #0x24] */
/* @0x2bc1dc bne 0x2bbf80 <jinit_1pass_quantizer+0x1250> */
/* @0x2bc1e0 ldr r7, [sp, #0x48] */
/* @0x2bc1e4 mov r10, r7 */
/* @0x2bc1e8 mov r3, r7 */
/* @0x2bc1ec b 0x2bc17c <jinit_1pass_quantizer+0x144c> */
/* @0x2bc1f0 ldr r3, [r0, #0x1a8] */
/* @0x2bc1f4 mov r1, #1 */
/* @0x2bc1f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2bc1fc sub sp, sp, #60 */
/* @0x2bc200 str r3, [sp, #0x34] */
/* @0x2bc204 ldr r12, [sp, #0x34] */
/* @0x2bc208 ldr r3, [r0, #0x4] */
/* @0x2bc20c str r0, [sp, #0x14] */
/* @0x2bc210 ldr r5, [r12, #0x14] */
/* @0x2bc214 ldr r2, [r12, #0x10] */
/* @0x2bc218 ldr r3, [r3] */
/* @0x2bc21c str r2, [r0, #0x74] */
/* @0x2bc220 lsl r2, r5, #5 */
/* @0x2bc224 blx r3 */
/* @0x2bc228 mov r3, #0 */
/* @0x2bc22c mov r2, #63 */
/* @0x2bc230 str r3, [r0] */
/* @0x2bc234 mov r1, r0 */
/* @0x2bc238 str r3, [r0, #0x8] */
/* @0x2bc23c mov r4, r0 */
/* @0x2bc240 str r3, [r0, #0x10] */
/* @0x2bc244 ldr r3, [sp, #0x14] */
/* @0x2bc248 str r2, [r0, #0xc] */
/* @0x2bc24c mov r2, #31 */
/* @0x2bc250 str r2, [r0, #0x4] */
/* @0x2bc254 str r2, [r0, #0x14] */
/* @0x2bc258 ldr r0, [r3, #0x1a8] */
/* @0x2bc25c bl 0x2bb3c4 <jinit_1pass_quantizer+0x694> */
/* @0x2bc260 cmp r5, #1 */
/* @0x2bc264 movle r12, #1 */
/* @0x2bc268 strle r12, [sp, #0x2c] */
/* @0x2bc26c ble 0x2bc3d4 <jinit_1pass_quantizer+0x16a4> */
/* @0x2bc270 mov r3, #1 */
/* @0x2bc274 mov r2, r4 */
/* @0x2bc278 mov r6, r3 */
/* @0x2bc27c str r3, [sp, #0x2c] */
/* @0x2bc280 cmp r5, r6, lsl #1 */
/* @0x2bc284 mov r1, #0 */
/* @0x2bc288 mov r3, r4 */
/* @0x2bc28c blt 0x2bc39c <jinit_1pass_quantizer+0x166c> */
/* @0x2bc290 mov r0, r1 */
/* @0x2bc294 mov lr, r1 */
/* @0x2bc298 ldr r12, [r3, #0x1c] */
/* @0x2bc29c add r0, r0, #1 */
/* @0x2bc2a0 cmp r12, lr */
/* @0x2bc2a4 ble 0x2bc2b8 <jinit_1pass_quantizer+0x1588> */
/* @0x2bc2a8 ldr r7, [r3, #0x18] */
/* @0x2bc2ac cmp r7, #0 */
/* @0x2bc2b0 movgt r1, r3 */
/* @0x2bc2b4 movgt lr, r12 */
/* @0x2bc2b8 cmp r0, r6 */
/* @0x2bc2bc add r3, r3, #32 */
/* @0x2bc2c0 blt 0x2bc298 <jinit_1pass_quantizer+0x1568> */
/* @0x2bc2c4 cmp r1, #0 */
/* @0x2bc2c8 beq 0x2bc3d0 <jinit_1pass_quantizer+0x16a0> */
/* @0x2bc2cc ldr r3, [r1, #0x4] */
/* @0x2bc2d0 add r7, r2, #32 */
/* @0x2bc2d4 str r3, [r2, #0x24] */
/* @0x2bc2d8 ldr r3, [r1, #0xc] */
/* @0x2bc2dc str r3, [r2, #0x2c] */
/* @0x2bc2e0 ldr r3, [r1, #0x14] */
/* @0x2bc2e4 str r3, [r2, #0x34] */
/* @0x2bc2e8 ldr r3, [r1] */
/* @0x2bc2ec str r3, [r2, #0x20] */
/* @0x2bc2f0 ldr r3, [r1, #0x8] */
/* @0x2bc2f4 str r3, [r2, #0x28] */
/* @0x2bc2f8 ldr r3, [r1, #0x10] */
/* @0x2bc2fc str r3, [r2, #0x30] */
/* @0x2bc300 ldr r12, [r1, #0xc] */
/* @0x2bc304 ldr r3, [r1, #0x8] */
/* @0x2bc308 ldr r9, [r1, #0x4] */
/* @0x2bc30c ldr r10, [r1] */
/* @0x2bc310 rsb r0, r3, r12 */
/* @0x2bc314 str r12, [sp] */
/* @0x2bc318 rsb r11, r10, r9 */
/* @0x2bc31c lsl r12, r0, #3 */
/* @0x2bc320 ldr lr, [r1, #0x14] */
/* @0x2bc324 add r12, r12, r0, lsl #2 */
/* @0x2bc328 ldr r8, [r1, #0x10] */
/* @0x2bc32c lsl r11, r11, #4 */
/* @0x2bc330 cmp r11, r12 */
/* @0x2bc334 rsb r0, r8, lr */
/* @0x2bc338 lsl r0, r0, #3 */
/* @0x2bc33c ble 0x2bc62c <jinit_1pass_quantizer+0x18fc> */
/* @0x2bc340 cmp r11, r0 */
/* @0x2bc344 bge 0x2bc5fc <jinit_1pass_quantizer+0x18cc> */
/* @0x2bc348 add lr, lr, r8 */
/* @0x2bc34c add lr, lr, lr, lsr #31 */
/* @0x2bc350 asr r3, lr, #1 */
/* @0x2bc354 str r3, [r1, #0x14] */
/* @0x2bc358 add r3, r3, #1 */
/* @0x2bc35c str r3, [r2, #0x30] */
/* @0x2bc360 ldr r3, [sp, #0x14] */
/* @0x2bc364 add r6, r6, #1 */
/* @0x2bc368 ldr r0, [r3, #0x1a8] */
/* @0x2bc36c bl 0x2bb3c4 <jinit_1pass_quantizer+0x694> */
/* @0x2bc370 ldr r12, [sp, #0x14] */
/* @0x2bc374 mov r1, r7 */
/* @0x2bc378 ldr r0, [r12, #0x1a8] */
/* @0x2bc37c bl 0x2bb3c4 <jinit_1pass_quantizer+0x694> */
/* @0x2bc380 cmp r6, r5 */
/* @0x2bc384 beq 0x2bc3d0 <jinit_1pass_quantizer+0x16a0> */
/* @0x2bc388 cmp r5, r6, lsl #1 */
/* @0x2bc38c mov r2, r7 */
/* @0x2bc390 mov r1, #0 */
/* @0x2bc394 mov r3, r4 */
/* @0x2bc398 bge 0x2bc290 <jinit_1pass_quantizer+0x1560> */
/* @0x2bc39c mov r12, r1 */
/* @0x2bc3a0 mov r0, r1 */
/* @0x2bc3a4 ldr lr, [r3, #0x18] */
/* @0x2bc3a8 add r12, r12, #1 */
/* @0x2bc3ac cmp lr, r0 */
/* @0x2bc3b0 movle lr, r0 */
/* @0x2bc3b4 movgt r1, r3 */
/* @0x2bc3b8 cmp r12, r6 */
/* @0x2bc3bc add r3, r3, #32 */
/* @0x2bc3c0 mov r0, lr */
/* @0x2bc3c4 blt 0x2bc3a4 <jinit_1pass_quantizer+0x1674> */
/* @0x2bc3c8 cmp r1, #0 */
/* @0x2bc3cc bne 0x2bc2cc <jinit_1pass_quantizer+0x159c> */
/* @0x2bc3d0 str r6, [sp, #0x2c] */
/* @0x2bc3d4 mov r2, #0 */
/* @0x2bc3d8 str r4, [sp, #0x28] */
/* @0x2bc3dc str r2, [sp, #0x30] */
/* @0x2bc3e0 ldr r2, [sp, #0x28] */
/* @0x2bc3e4 ldr r12, [sp, #0x14] */
/* @0x2bc3e8 ldr lr, [sp, #0x28] */
/* @0x2bc3ec ldr r3, [r2, #0x4] */
/* @0x2bc3f0 ldr r2, [r12, #0x1a8] */
/* @0x2bc3f4 ldr lr, [lr] */
/* @0x2bc3f8 ldr r0, [sp, #0x28] */
/* @0x2bc3fc cmp lr, r3 */
/* @0x2bc400 ldr r1, [r2, #0x18] */
/* @0x2bc404 str lr, [sp, #0x8] */
/* @0x2bc408 ldr r2, [sp, #0x28] */
/* @0x2bc40c ldr lr, [sp, #0x28] */
/* @0x2bc410 ldr r0, [r0, #0xc] */
/* @0x2bc414 ldr r12, [r2, #0x14] */
/* @0x2bc418 ldr lr, [lr, #0x8] */
/* @0x2bc41c str r0, [sp, #0x18] */
/* @0x2bc420 ldr r11, [r2, #0x10] */
/* @0x2bc424 str lr, [sp, #0x10] */
/* @0x2bc428 str r12, [sp] */
/* @0x2bc42c bgt 0x2bc618 <jinit_1pass_quantizer+0x18e8> */
/* @0x2bc430 add r2, r11, lr, lsl #5 */
/* @0x2bc434 ldr r0, [sp, #0x8] */
/* @0x2bc438 mov lr, #0 */
/* @0x2bc43c add r3, r3, #1 */
/* @0x2bc440 add r6, r12, #1 */
/* @0x2bc444 str r3, [sp, #0x24] */
/* @0x2bc448 lsl r3, r2, #1 */
/* @0x2bc44c ldr r2, [sp, #0x18] */
/* @0x2bc450 add r1, r1, r0, lsl #2 */
/* @0x2bc454 mov r5, lr */
/* @0x2bc458 str r1, [sp, #0x20] */
/* @0x2bc45c mov r4, lr */
/* @0x2bc460 mov r1, lr */
/* @0x2bc464 add r2, r2, #1 */
/* @0x2bc468 str lr, [sp, #0xc] */
/* @0x2bc46c str r3, [sp, #0x1c] */
/* @0x2bc470 str r2, [sp, #0x4] */
/* @0x2bc474 ldr r12, [sp, #0x10] */
/* @0x2bc478 ldr r0, [sp, #0x18] */
/* @0x2bc47c cmp r12, r0 */
/* @0x2bc480 bgt 0x2bc504 <jinit_1pass_quantizer+0x17d4> */
/* @0x2bc484 ldr r3, [sp, #0x20] */
/* @0x2bc488 ldr r2, [sp, #0xc] */
/* @0x2bc48c ldr r12, [sp, #0x8] */
/* @0x2bc490 ldr r0, [sp, #0x1c] */
/* @0x2bc494 ldr r10, [r3, r2] */
/* @0x2bc498 lsl r8, r12, #3 */
/* @0x2bc49c ldr r9, [sp, #0x10] */
/* @0x2bc4a0 add r8, r8, #4 */
/* @0x2bc4a4 add r10, r10, r0 */
/* @0x2bc4a8 ldr r3, [sp] */
/* @0x2bc4ac mov r0, r10 */
/* @0x2bc4b0 cmp r11, r3 */
/* @0x2bc4b4 bgt 0x2bc4f0 <jinit_1pass_quantizer+0x17c0> */
/* @0x2bc4b8 lsl r7, r9, #2 */
/* @0x2bc4bc mov r3, r11 */
/* @0x2bc4c0 add r7, r7, #2 */
/* @0x2bc4c4 ldrh r2, [r0], #2 */
/* @0x2bc4c8 lsl r12, r3, #3 */
/* @0x2bc4cc add r12, r12, #4 */
/* @0x2bc4d0 add r3, r3, #1 */
/* @0x2bc4d4 cmp r2, #0 */
/* @0x2bc4d8 addne r4, r4, r2 */
/* @0x2bc4dc mlane r5, r8, r2, r5 */
/* @0x2bc4e0 mlane lr, r7, r2, lr */
/* @0x2bc4e4 mlane r1, r12, r2, r1 */
/* @0x2bc4e8 cmp r3, r6 */
/* @0x2bc4ec bne 0x2bc4c4 <jinit_1pass_quantizer+0x1794> */
/* @0x2bc4f0 ldr r12, [sp, #0x4] */
/* @0x2bc4f4 add r9, r9, #1 */
/* @0x2bc4f8 add r10, r10, #64 */
/* @0x2bc4fc cmp r9, r12 */
/* @0x2bc500 bne 0x2bc4a8 <jinit_1pass_quantizer+0x1778> */
/* @0x2bc504 ldr r0, [sp, #0x8] */
/* @0x2bc508 ldr r3, [sp, #0x24] */
/* @0x2bc50c add r0, r0, #1 */
/* @0x2bc510 ldr r2, [sp, #0xc] */
/* @0x2bc514 cmp r0, r3 */
/* @0x2bc518 str r0, [sp, #0x8] */
/* @0x2bc51c add r2, r2, #4 */
/* @0x2bc520 str r2, [sp, #0xc] */
/* @0x2bc524 bne 0x2bc474 <jinit_1pass_quantizer+0x1744> */
/* @0x2bc528 asr r6, r4, #1 */
/* @0x2bc52c add r0, r5, r6 */
/* @0x2bc530 add r7, lr, r6 */
/* @0x2bc534 add r6, r1, r6 */
/* @0x2bc538 ldr r12, [sp, #0x14] */
/* @0x2bc53c mov r1, r4 */
/* @0x2bc540 ldr r2, [sp, #0x28] */
/* @0x2bc544 ldr r3, [r12, #0x74] */
/* @0x2bc548 add r2, r2, #32 */
/* @0x2bc54c str r2, [sp, #0x28] */
/* @0x2bc550 ldr r5, [r3] */
/* @0x2bc554 bl 0x318d10 <__divsi3> */
/* @0x2bc558 ldr r3, [sp, #0x30] */
/* @0x2bc55c mov r1, r4 */
/* @0x2bc560 ldr r12, [sp, #0x14] */
/* @0x2bc564 strb r0, [r5, r3] */
/* @0x2bc568 mov r0, r7 */
/* @0x2bc56c ldr r3, [r12, #0x74] */
/* @0x2bc570 ldr r5, [r3, #0x4] */
/* @0x2bc574 bl 0x318d10 <__divsi3> */
/* @0x2bc578 ldr r2, [sp, #0x30] */
/* @0x2bc57c mov r1, r4 */
/* @0x2bc580 ldr r12, [sp, #0x14] */
/* @0x2bc584 strb r0, [r5, r2] */
/* @0x2bc588 mov r0, r6 */
/* @0x2bc58c ldr r3, [r12, #0x74] */
/* @0x2bc590 ldr r4, [r3, #0x8] */
/* @0x2bc594 bl 0x318d10 <__divsi3> */
/* @0x2bc598 ldr r2, [sp, #0x30] */
/* @0x2bc59c ldr r3, [sp, #0x2c] */
/* @0x2bc5a0 strb r0, [r4, r2] */
/* @0x2bc5a4 add r2, r2, #1 */
/* @0x2bc5a8 cmp r2, r3 */
/* @0x2bc5ac str r2, [sp, #0x30] */
/* @0x2bc5b0 blt 0x2bc3e0 <jinit_1pass_quantizer+0x16b0> */
/* @0x2bc5b4 ldr r12, [sp, #0x14] */
/* @0x2bc5b8 mov r1, #1 */
/* @0x2bc5bc ldr r2, [sp, #0x2c] */
/* @0x2bc5c0 ldr lr, [sp, #0x14] */
/* @0x2bc5c4 ldr r3, [r12] */
/* @0x2bc5c8 mov r12, #96 */
/* @0x2bc5cc str r2, [lr, #0x70] */
/* @0x2bc5d0 mov r0, lr */
/* @0x2bc5d4 str r2, [r3, #0x18] */
/* @0x2bc5d8 ldr r2, [lr] */
/* @0x2bc5dc str r12, [r3, #0x14] */
/* @0x2bc5e0 ldr r3, [r2, #0x4] */
/* @0x2bc5e4 blx r3 */
/* @0x2bc5e8 ldr r12, [sp, #0x34] */
/* @0x2bc5ec mov r3, #1 */
/* @0x2bc5f0 strb r3, [r12, #0x1c] */
/* @0x2bc5f4 add sp, sp, #60 */
/* @0x2bc5f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2bc5fc add r9, r9, r10 */
/* @0x2bc600 add r9, r9, r9, lsr #31 */
/* @0x2bc604 asr r3, r9, #1 */
/* @0x2bc608 str r3, [r1, #0x4] */
/* @0x2bc60c add r3, r3, #1 */
/* @0x2bc610 str r3, [r2, #0x20] */
/* @0x2bc614 b 0x2bc360 <jinit_1pass_quantizer+0x1630> */
/* @0x2bc618 mov r6, #0 */
/* @0x2bc61c mov r7, r6 */
/* @0x2bc620 mov r0, r6 */
/* @0x2bc624 mov r4, r6 */
/* @0x2bc628 b 0x2bc538 <jinit_1pass_quantizer+0x1808> */
/* @0x2bc62c cmp r12, r0 */
/* @0x2bc630 blt 0x2bc348 <jinit_1pass_quantizer+0x1618> */
/* @0x2bc634 ldr lr, [sp] */
/* @0x2bc638 add r3, lr, r3 */
/* @0x2bc63c add r3, r3, r3, lsr #31 */
/* @0x2bc640 asr r3, r3, #1 */
/* @0x2bc644 str r3, [r1, #0xc] */
/* @0x2bc648 add r3, r3, #1 */
/* @0x2bc64c str r3, [r2, #0x28] */
/* @0x2bc650 b 0x2bc360 <jinit_1pass_quantizer+0x1630> */
