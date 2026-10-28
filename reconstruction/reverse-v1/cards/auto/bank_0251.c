/* libyoyo.so 覆盖卡组 0251
 * 函数 0x2a4584..0x2a5af4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a4584 · zip_fopen_index · size=488 · insn=213 */
/* @0x2a4584 push.w {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2a4588 subs r7, r1, #0x0 */
/* @0x2a458a mov r5, r0 */
/* @0x2a458c blt 0x2a4594 <zip_fopen_index+0x10> */
/* @0x2a458e ldr r3, [r0, #0x2c] */
/* @0x2a4590 cmp r7, r3 */
/* @0x2a4592 blt 0x2a45a4 <zip_fopen_index+0x20> */
/* @0x2a4594 add.w r0, r5, #0xc */
/* @0x2a4598 movs r1, #0x12 */
/* @0x2a459a movs r2, #0x0 */
/* @0x2a459c bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a45a0 movs r4, #0x0 */
/* @0x2a45a2 b 0x2a4762 <zip_fopen_index+0x1de> */
/* @0x2a45a4 ands r4, r2, #0x8 */
/* @0x2a45a8 bne 0x2a45be <zip_fopen_index+0x3a> */
/* @0x2a45aa movs r1, #0x14 */
/* @0x2a45ac ldr r3, [r0, #0x34] */
/* @0x2a45ae muls r1, r7, r1 */
/* @0x2a45b0 ldr r3, [r3, r1] */
/* @0x2a45b2 subs r3, #0x2 */
/* @0x2a45b4 cmp r3, #0x1 */
/* @0x2a45b6 bhi 0x2a45be <zip_fopen_index+0x3a> */
/* @0x2a45b8 adds r0, #0xc */
/* @0x2a45ba movs r1, #0xf */
/* @0x2a45bc b 0x2a45f8 <zip_fopen_index+0x74> */
/* @0x2a45be ldr r3, [r5, #0x20] */
/* @0x2a45c0 ldr r1, [r3, #0x4] */
/* @0x2a45c2 cmp r7, r1 */
/* @0x2a45c4 bge 0x2a4594 <zip_fopen_index+0x10> */
/* @0x2a45c6 mov.w r8, #0x3c */
/* @0x2a45c8 ldmdavs r11, {r2, r3, r4, r5, r11} */
/* @0x2a45ca ldr r3, [r3] */
/* @0x2a45cc mul r8, r8, r7 */
/* @0x2a45d0 add r3, r8 */
/* @0x2a45d2 ldrh r3, [r3, #0x6] */
/* @0x2a45d4 cbz r3, 0x2a4600 <zip_fopen_index+0x7c> */
/* @0x2a45d6 cmp r3, #0x8 */
/* @0x2a45d8 and r4, r2, #0x4 */
/* @0x2a45dc bne 0x2a45ec <zip_fopen_index+0x68> */
/* @0x2a45de cmp r4, #0x0 */
/* @0x2a45e0 ite eq */
/* @0x2a45e2 moveq.w r9, #0x6 */
/* @0x2a45e4 .word 0xf04f0906 */
/* @0x2a45e6 movne.w r9, #0x0 */
/* @0x2a45e8 and r0, r11, r0, lsl #18 */
/* @0x2a45ea b 0x2a4604 <zip_fopen_index+0x80> */
/* @0x2a45ec mov.w r9, #0x0 */
/* @0x2a45f0 cbnz r4, 0x2a4604 <zip_fopen_index+0x80> */
/* @0x2a45f2 add.w r0, r5, #0xc */
/* @0x2a45f4 tsths r0, r12 */
/* @0x2a45f6 movs r1, #0x10 */
/* @0x2a45f8 mov r2, r4 */
/* @0x2a45fa bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a45fc adcs pc, r0, sp, lsr #29 */
/* @0x2a45fe b 0x2a4762 <zip_fopen_index+0x1de> */
/* @0x2a4600 mov.w r9, #0x4 */
/* @0x2a4604 movs r0, #0x34 */
/* @0x2a4606 blx 0xb6544 <malloc@plt> */
/* @0x2a4608 .word 0x4604ef9e */
/* @0x2a460a mov r4, r0 */
/* @0x2a460c cbnz r0, 0x2a461c <zip_fopen_index+0x98> */
/* @0x2a460e add.w r0, r5, #0xc */
/* @0x2a4610 .word 0x210e000c */
/* @0x2a4612 movs r1, #0xe */
/* @0x2a4614 mov r2, r4 */
/* @0x2a4616 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a4618 mlas r7, pc, lr, pc */
/* @0x2a461a b 0x2a468c <zip_fopen_index+0x108> */
/* @0x2a461c ldr r3, [r5, #0x3c] */
/* @0x2a461e ldr r2, [r5, #0x38] */
/* @0x2a4620 subs r1, r3, #0x1 */
/* @0x2a4622 cmp r2, r1 */
/* @0x2a4624 blt 0x2a4654 <zip_fopen_index+0xd0> */
/* @0x2a4626 add.w r10, r3, #0xa */
/* @0x2a4628 .word 0x6c280a0a */
/* @0x2a462a ldr r0, [r5, #0x40] */
/* @0x2a462c lsl.w r1, r10, #0x2 */
/* @0x2a4630 blx 0xb6c28 <realloc@plt> */
/* @0x2a4634 mov r6, r0 */
/* @0x2a4636 cbnz r0, 0x2a464e <zip_fopen_index+0xca> */
/* @0x2a4638 add.w r0, r5, #0xc */
/* @0x2a463c movs r1, #0xe */
/* @0x2a463e mov r2, r6 */
/* @0x2a4640 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a4644 mov r0, r4 */
/* @0x2a4646 blx 0xb655c <free@plt> */
/* @0x2a4648 ldrtmi lr, [r4], -r10, lsl #31 */
/* @0x2a464a mov r4, r6 */
/* @0x2a464c b 0x2a468c <zip_fopen_index+0x108> */
/* @0x2a464e str.w r10, [r5, #0x3c] */
/* @0x2a4650 strtvs r10, [r8], #-60 */
/* @0x2a4652 str r0, [r5, #0x40] */
/* @0x2a4654 ldr r3, [r5, #0x38] */
/* @0x2a4656 mov r0, r4 */
/* @0x2a4658 ldr r2, [r5, #0x40] */
/* @0x2a465a movs r6, #0x0 */
/* @0x2a465c adds r1, r3, #0x1 */
/* @0x2a465e str r1, [r5, #0x38] */
/* @0x2a4660 str.w r4, [r2, r3, lsl #2] */
/* @0x2a4664 str r5, [r0], #4 */
/* @0x2a4668 bl 0x2a434e <_Z15_zip_error_initP9zip_error> */
/* @0x2a466c str r6, [r4, #0x10] */
/* @0x2a466e mov r0, r6 */
/* @0x2a4670 mov r1, r6 */
/* @0x2a4672 mov r2, r6 */
/* @0x2a4674 blx 0xb6ea4 <crc32@plt> */
/* @0x2a4678 mov.w r3, #0xffffffff */
/* @0x2a467c str r6, [r4, #0x28] */
/* @0x2a467e str r3, [r4, #0x14] */
/* @0x2a4680 str r6, [r4, #0x20] */
/* @0x2a4682 str r6, [r4, #0x1c] */
/* @0x2a4684 str r6, [r4, #0x18] */
/* @0x2a4686 str r6, [r4, #0x2c] */
/* @0x2a4688 str r6, [r4, #0x30] */
/* @0x2a468a str r0, [r4, #0x24] */
/* @0x2a468c str.w r9, [r4, #0x10] */
/* @0x2a4690 mov r0, r5 */
/* @0x2a4692 ldr r3, [r5, #0x20] */
/* @0x2a4694 mov r1, r7 */
/* @0x2a4696 ldr r3, [r3] */
/* @0x2a4698 add r3, r8 */
/* @0x2a469a ldrh r3, [r3, #0x6] */
/* @0x2a469c str r3, [r4, #0x14] */
/* @0x2a469e ldr r3, [r5, #0x20] */
/* @0x2a46a0 ldr r3, [r3] */
/* @0x2a46a2 add r3, r8 */
/* @0x2a46a4 ldr r3, [r3, #0x14] */
/* @0x2a46a6 str r3, [r4, #0x1c] */
/* @0x2a46a8 ldr r3, [r5, #0x20] */
/* @0x2a46aa ldr r3, [r3] */
/* @0x2a46ac add r3, r8 */
/* @0x2a46ae ldr r3, [r3, #0x10] */
/* @0x2a46b0 str r3, [r4, #0x20] */
/* @0x2a46b2 ldr r3, [r5, #0x20] */
/* @0x2a46b4 ldr r3, [r3] */
/* @0x2a46b6 add r3, r8 */
/* @0x2a46b8 ldr r3, [r3, #0xc] */
/* @0x2a46ba str r3, [r4, #0x28] */
/* @0x2a46bc bl 0x2a58ee <_Z20_zip_file_get_offsetP3zipi> */
/* @0x2a46c0 str r0, [r4, #0x18] */
/* @0x2a46c2 cbz r0, 0x2a4728 <zip_fopen_index+0x1a4> */
/* @0x2a46c4 ldr r3, [r4, #0x10] */
/* @0x2a46c6 lsls r3, r3, #0x1e */
/* @0x2a46c8 bmi 0x2a46d0 <zip_fopen_index+0x14c> */
/* @0x2a46ca ldr r3, [r4, #0x20] */
/* @0x2a46cc str r3, [r4, #0x1c] */
/* @0x2a46ce b 0x2a4762 <zip_fopen_index+0x1de> */
/* @0x2a46d0 mov.w r0, #0x2000 */
/* @0x2a46d4 blx 0xb6544 <malloc@plt> */
/* @0x2a46d8 mov r6, r0 */
/* @0x2a46da str r0, [r4, #0x2c] */
/* @0x2a46dc cbnz r0, 0x2a46f4 <zip_fopen_index+0x170> */
/* @0x2a46de add.w r0, r5, #0xc */
/* @0x2a46e0 .word 0x210e000c */
/* @0x2a46e2 movs r1, #0xe */
/* @0x2a46e4 mov r2, r6 */
/* @0x2a46e6 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a46e8 qasxmi pc, r0, r7 */
/* @0x2a46ea mov r0, r4 */
/* @0x2a46ec bl 0x2a4388 <zip_fclose> */
/* @0x2a46f0 mov r4, r6 */
/* @0x2a46f2 b 0x2a4762 <zip_fopen_index+0x1de> */
/* @0x2a46f4 mov.w r1, #0x2000 */
/* @0x2a46f8 mov r2, r4 */
/* @0x2a46fa bl 0x2a44d6 <_Z17_zip_file_fillbufPvjP8zip_file> */
/* @0x2a46fc .word 0xf1b0feec */
/* @0x2a46fe subs.w r8, r0, #0x0 */
/* @0x2a4700 .word 0xdc050800 */
/* @0x2a4702 bgt 0x2a4710 <zip_fopen_index+0x18c> */
/* @0x2a4704 add.w r0, r5, #0xc */
/* @0x2a4708 adds r1, r4, #0x4 */
/* @0x2a470a bl 0x2a4314 <_Z15_zip_error_copyP9zip_errorS0_> */
/* @0x2a470c and pc, r11, r3, lsl #28 */
/* @0x2a470e b 0x2a4728 <zip_fopen_index+0x1a4> */
/* @0x2a4710 movs r0, #0x38 */
/* @0x2a4712 blx 0xb6544 <malloc@plt> */
/* @0x2a4714 .word 0x4606ef18 */
/* @0x2a4716 mov r6, r0 */
/* @0x2a4718 str r0, [r4, #0x30] */
/* @0x2a471a cbnz r0, 0x2a4730 <zip_fopen_index+0x1ac> */
/* @0x2a471c add.w r0, r5, #0xc */
/* @0x2a4720 movs r1, #0xe */
/* @0x2a4722 mov r2, r6 */
/* @0x2a4724 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a4728 mov r0, r4 */
/* @0x2a472a bl 0x2a4388 <zip_fclose> */
/* @0x2a472c ldr pc, [r7, -sp, lsr #28]! */
/* @0x2a472e b 0x2a45a0 <zip_fopen_index+0x1c> */
/* @0x2a4730 ldr r3, [r4, #0x2c] */
/* @0x2a4732 movs r7, #0x0 */
/* @0x2a4734 ldr r2, [pc, #0x30] */
/* @0x2a4736 mvn r1, #0xe */
/* @0x2a4738 andvs r0, r7, #-2147483645 */
/* @0x2a473a str r7, [r0, #0x20] */
/* @0x2a473c stm.w r0, {r3, r8} */
/* @0x2a4740 add r2, pc */
/* @0x2a4742 str r7, [r0, #0x24] */
/* @0x2a4744 movs r3, #0x38 */
/* @0x2a4746 str r7, [r0, #0x28] */
/* @0x2a4748 blx 0xb6f10 <inflateInit2_@plt> */
/* @0x2a474c mov r2, r0 */
/* @0x2a474e cbz r0, 0x2a4762 <zip_fopen_index+0x1de> */
/* @0x2a4750 add.w r0, r5, #0xc */
/* @0x2a4754 movs r1, #0xd */
/* @0x2a4756 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a4758 qsub8mi pc, r0, pc */
/* @0x2a475a mov r0, r4 */
/* @0x2a475c bl 0x2a4388 <zip_fclose> */
/* @0x2a4760 mov r4, r7 */
/* @0x2a4762 mov r0, r4 */
/* @0x2a4764 pop.w {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2a4768 ldrb r0, [r1, #0x2] */
/* @0x2a476a movs r6, r1 */

/* ── FUNC 0x2a476c · zip_fread · size=280 · insn=133 */
/* @0x2a476c push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2a4770 mov r6, r1 */
/* @0x2a4772 mov r7, r2 */
/* @0x2a4774 mov r4, r0 */
/* @0x2a4776 cmp r0, #0x0 */
/* @0x2a4778 beq 0x2a4876 <zip_fread+0x10a> */
/* @0x2a477a ldr r3, [r0, #0x4] */
/* @0x2a477c cmp r3, #0x0 */
/* @0x2a477e bne 0x2a4876 <zip_fread+0x10a> */
/* @0x2a4780 ldr r3, [r0, #0x10] */
/* @0x2a4782 lsls r0, r3, #0x1f */
/* @0x2a4784 bpl 0x2a478c <zip_fread+0x20> */
/* @0x2a4786 movs r0, #0x0 */
/* @0x2a4788 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2a478c cmp r2, #0x0 */
/* @0x2a478e beq 0x2a4786 <zip_fread+0x1a> */
/* @0x2a4790 ldr r2, [r4, #0x1c] */
/* @0x2a4792 cbnz r2, 0x2a47ae <zip_fread+0x42> */
/* @0x2a4794 lsls r1, r3, #0x1d */
/* @0x2a4796 orr r2, r3, #0x1 */
/* @0x2a4798 .word 0x61220201 */
/* @0x2a479a str r2, [r4, #0x10] */
/* @0x2a479c bpl 0x2a4786 <zip_fread+0x1a> */
/* @0x2a479e ldr r2, [r4, #0x24] */
/* @0x2a47a0 ldr r3, [r4, #0x28] */
/* @0x2a47a2 cmp r2, r3 */
/* @0x2a47a4 beq 0x2a4786 <zip_fread+0x1a> */
/* @0x2a47a6 adds r0, r4, #0x4 */
/* @0x2a47a8 movs r1, #0x7 */
/* @0x2a47aa movs r2, #0x0 */
/* @0x2a47ac b 0x2a4872 <zip_fread+0x106> */
/* @0x2a47ae lsls r2, r3, #0x1e */
/* @0x2a47b0 bmi 0x2a47c2 <zip_fread+0x56> */
/* @0x2a47b2 mov r0, r1 */
/* @0x2a47b4 mov r2, r4 */
/* @0x2a47b6 mov r1, r7 */
/* @0x2a47b8 bl 0x2a44d6 <_Z17_zip_file_fillbufPvjP8zip_file> */
/* @0x2a47bc subs r5, r0, #0x0 */
/* @0x2a47be bgt 0x2a4822 <zip_fread+0xb6> */
/* @0x2a47c0 b 0x2a487e <zip_fread+0x112> */
/* @0x2a47c2 ldr r3, [r4, #0x30] */
/* @0x2a47c4 str r1, [r3, #0xc] */
/* @0x2a47c6 ldr r3, [r4, #0x30] */
/* @0x2a47c8 str r7, [r3, #0x10] */
/* @0x2a47ca ldr r3, [r4, #0x30] */
/* @0x2a47cc ldr.w r8, [r3, #0x14] */
/* @0x2a47d0 ldr r0, [r4, #0x30] */
/* @0x2a47d2 movs r1, #0x2 */
/* @0x2a47d4 blx 0xb69dc <inflate@plt> */
/* @0x2a47d8 adds r3, r0, #0x5 */
/* @0x2a47da mov r2, r0 */
/* @0x2a47dc cmp r3, #0x7 */
/* @0x2a47de bhi 0x2a47d0 <zip_fread+0x64> */
/* @0x2a47e0 adr r0, #8 <zip_fread+0x7a> */
/* @0x2a47e2 ldr.w r1, [r0, r3, lsl #2] */
/* @0x2a47e4 strmi r1, [r8], #-35 */
/* @0x2a47e6 add r0, r1 */
/* @0x2a47e8 bx r0 */
/* @0x2a47ea nop */
/* @0x2a47ec lsls r1, r3, #0x1 */
/* @0x2a47ee movs r0, r0 */
/* @0x2a47f0 lsls r3, r0, #0x2 */
/* @0x2a47f2 movs r0, r0 */
/* @0x2a47f4 lsls r3, r0, #0x2 */
/* @0x2a47f6 movs r0, r0 */
/* @0x2a47f8 lsls r3, r0, #0x2 */
/* @0x2a47fa movs r0, r0 */
/* @0x2a47fc .word 0xffe5 ffff */
/* @0x2a4800 movs r1, r5 */
/* @0x2a4802 movs r0, r0 */
/* @0x2a4804 movs r1, r4 */
/* @0x2a4806 movs r0, r0 */
/* @0x2a4808 lsls r3, r0, #0x2 */
/* @0x2a480a movs r0, r0 */
/* @0x2a480c ldr r3, [r4, #0x30] */
/* @0x2a480e ldr r3, [r3, #0x14] */
/* @0x2a4810 cmp r3, r8 */
/* @0x2a4812 beq 0x2a479e <zip_fread+0x32> */
/* @0x2a4814 ldr r3, [r4, #0x30] */
/* @0x2a4816 ldr r5, [r3, #0x14] */
/* @0x2a4818 ldr r3, [r4, #0x1c] */
/* @0x2a481a rsb r5, r8, r5 */
/* @0x2a481c addsmi r0, sp, #20971520 */
/* @0x2a481e cmp r5, r3 */
/* @0x2a4820 blo 0x2a4836 <zip_fread+0xca> */
/* @0x2a4822 ldr r3, [r4, #0x10] */
/* @0x2a4824 lsls r3, r3, #0x1d */
/* @0x2a4826 bpl 0x2a483c <zip_fread+0xd0> */
/* @0x2a4828 ldr r0, [r4, #0x24] */
/* @0x2a482a mov r1, r6 */
/* @0x2a482c mov r2, r5 */
/* @0x2a482e blx 0xb6ea4 <crc32@plt> */
/* @0x2a4830 rsbvs lr, r0, #59392 */
/* @0x2a4832 str r0, [r4, #0x24] */
/* @0x2a4834 b 0x2a483c <zip_fread+0xd0> */
/* @0x2a4836 cmp r5, r7 */
/* @0x2a4838 blo 0x2a47d0 <zip_fread+0x64> */
/* @0x2a483a b 0x2a4822 <zip_fread+0xb6> */
/* @0x2a483c ldr r3, [r4, #0x1c] */
/* @0x2a483e subs r3, r3, r5 */
/* @0x2a4840 str r3, [r4, #0x1c] */
/* @0x2a4842 b 0x2a487e <zip_fread+0x112> */
/* @0x2a4844 ldr r3, [r4, #0x30] */
/* @0x2a4846 ldr r3, [r3, #0x4] */
/* @0x2a4848 cbnz r3, 0x2a486e <zip_fread+0x102> */
/* @0x2a484a mov r2, r4 */
/* @0x2a484c ldr r0, [r4, #0x2c] */
/* @0x2a484e mov.w r1, #0x2000 */
/* @0x2a4850 .word 0xf7ff5100 */
/* @0x2a4852 bl 0x2a44d6 <_Z17_zip_file_fillbufPvjP8zip_file> */
/* @0x2a4854 cdpne p14, #0x0, c15, c2, c0, #0x2 */
/* @0x2a4856 subs r2, r0, #0x0 */
/* @0x2a4858 bne 0x2a4860 <zip_fread+0xf4> */
/* @0x2a485a adds r0, r4, #0x4 */
/* @0x2a485c movs r1, #0x15 */
/* @0x2a485e b 0x2a4872 <zip_fread+0x106> */
/* @0x2a4860 blt 0x2a4876 <zip_fread+0x10a> */
/* @0x2a4862 ldr r3, [r4, #0x30] */
/* @0x2a4864 ldr r1, [r4, #0x2c] */
/* @0x2a4866 str r1, [r3] */
/* @0x2a4868 ldr r3, [r4, #0x30] */
/* @0x2a486a str r2, [r3, #0x4] */
/* @0x2a486c b 0x2a47d0 <zip_fread+0x64> */
/* @0x2a486e adds r0, r4, #0x4 */
/* @0x2a4870 movs r1, #0xd */
/* @0x2a4872 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a4874 .word 0xf04ffd71 */
/* @0x2a4876 mov.w r0, #0xffffffff */
/* @0x2a4878 pop {r0, r1, r2, r3, r4, r5, r6, r7, r12, sp} */
/* @0x2a487a pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2a487c qsub8mi r8, r8, r0 */
/* @0x2a487e mov r0, r5 */
/* @0x2a4880 pop.w {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2a4884 · _zip_free(zip*) · size=120 · insn=55 */
/* @0x2a4884 push {r4, r5, r6, lr} */
/* @0x2a4886 mov r4, r0 */
/* @0x2a4888 cmp r0, #0x0 */
/* @0x2a488a beq 0x2a48fa <_Z9_zip_freeP3zip+0x76> */
/* @0x2a488c ldr r0, [r0] */
/* @0x2a488e cbz r0, 0x2a4894 <_Z9_zip_freeP3zip+0x10> */
/* @0x2a4890 blx 0xb655c <free@plt> */
/* @0x2a4894 ldr r0, [r4, #0x4] */
/* @0x2a4896 cbz r0, 0x2a489c <_Z9_zip_freeP3zip+0x18> */
/* @0x2a4898 blx 0xb6850 <fclose@plt> */
/* @0x2a489c ldr r0, [r4, #0x20] */
/* @0x2a489e bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir> */
/* @0x2a48a0 blvs 0x1ba2f50 <b2_toiTime+0x1449aac> */
/* @0x2a48a2 ldr r3, [r4, #0x34] */
/* @0x2a48a4 cbz r3, 0x2a48c2 <_Z9_zip_freeP3zip+0x3e> */
/* @0x2a48a6 movs r5, #0x0 */
/* @0x2a48a8 movs r6, #0x14 */
/* @0x2a48aa ldr r3, [r4, #0x2c] */
/* @0x2a48ac ldr r0, [r4, #0x34] */
/* @0x2a48ae cmp r5, r3 */
/* @0x2a48b0 bge 0x2a48be <_Z9_zip_freeP3zip+0x3a> */
/* @0x2a48b2 mla r0, r6, r5, r0 */
/* @0x2a48b4 .word 0xf0000005 */
/* @0x2a48b6 bl 0x2a576a <_Z15_zip_entry_freeP9zip_entry> */
/* @0x2a48b8 strlo pc, [r1, #-0xf58] */
/* @0x2a48ba adds r5, #0x1 */
/* @0x2a48bc b 0x2a48aa <_Z9_zip_freeP3zip+0x26> */
/* @0x2a48be blx 0xb655c <free@plt> */
/* @0x2a48c0 strhs lr, [r0, #-0xe4e] */
/* @0x2a48c2 movs r5, #0x0 */
/* @0x2a48c4 ldr r3, [r4, #0x38] */
/* @0x2a48c6 cmp r5, r3 */
/* @0x2a48c8 bge 0x2a48ea <_Z9_zip_freeP3zip+0x66> */
/* @0x2a48ca ldr r3, [r4, #0x40] */
/* @0x2a48cc ldr.w r0, [r3, r5, lsl #2] */
/* @0x2a48d0 ldr r6, [r0, #0x4] */
/* @0x2a48d2 cbnz r6, 0x2a48e6 <_Z9_zip_freeP3zip+0x62> */
/* @0x2a48d4 adds r0, #0x4 */
/* @0x2a48d6 movs r1, #0x8 */
/* @0x2a48d8 mov r2, r6 */
/* @0x2a48da bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a48dc stcvs p13, c15, [r3], #-244 */
/* @0x2a48de ldr r3, [r4, #0x40] */
/* @0x2a48e0 ldr.w r3, [r3, r5, lsl #2] */
/* @0x2a48e4 str r6, [r3] */
/* @0x2a48e6 adds r5, #0x1 */
/* @0x2a48e8 b 0x2a48c4 <_Z9_zip_freeP3zip+0x40> */
/* @0x2a48ea ldr r0, [r4, #0x40] */
/* @0x2a48ec blx 0xb655c <free@plt> */
/* @0x2a48f0 mov r0, r4 */
/* @0x2a48f2 pop.w {r4, r5, r6, lr} */
/* @0x2a48f4 .word 0xf0774070 */
/* @0x2a48f6 b.w 0x31babc <__udivdi3+0x424> */
/* @0x2a48f8 ldcllt p8, c11, [r0, #-900]! */
/* @0x2a48fa pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a48fc · zip_get_archive_flag · size=18 · insn=9 */
/* @0x2a48fc lsls r3, r2, #0x1c */
/* @0x2a48fe ite mi */
/* @0x2a4900 ldrmi r3, [r0, #0x18] */
/* @0x2a4902 ldrpl r3, [r0, #0x1c] */
/* @0x2a4904 tst r3, r1 */
/* @0x2a4906 ite eq */
/* @0x2a4908 moveq r0, #0x0 */
/* @0x2a490a movne r0, #0x1 */
/* @0x2a490c bx lr */

/* ── FUNC 0x2a490e · zip_get_num_files · size=12 · insn=6 */
/* @0x2a490e cbz r0, 0x2a4914 <zip_get_num_files+0x6> */
/* @0x2a4910 ldr r0, [r0, #0x2c] */
/* @0x2a4912 bx lr */
/* @0x2a4914 mov.w r0, #0xffffffff */
/* @0x2a4916 .word 0x477030ff */
/* @0x2a4918 bx lr */

/* ── FUNC 0x2a491a · _zip_get_name(zip*, int, int, zip_error*) · size=86 · insn=41 */
/* @0x2a491a cmp r1, #0x0 */
/* @0x2a491c push {r4, r5, r6, lr} */
/* @0x2a491e mov r4, r0 */
/* @0x2a4920 mov r0, r3 */
/* @0x2a4922 blt 0x2a492a <_Z13_zip_get_nameP3zipiiP9zip_error+0x10> */
/* @0x2a4924 ldr r3, [r4, #0x2c] */
/* @0x2a4926 cmp r1, r3 */
/* @0x2a4928 blt 0x2a4936 <_Z13_zip_get_nameP3zipiiP9zip_error+0x1c> */
/* @0x2a492a movs r1, #0x12 */
/* @0x2a492c movs r2, #0x0 */
/* @0x2a492e bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a4932 movs r0, #0x0 */
/* @0x2a4934 pop {r4, r5, r6, pc} */
/* @0x2a4936 ands r5, r2, #0x8 */
/* @0x2a493a bne 0x2a4954 <_Z13_zip_get_nameP3zipiiP9zip_error+0x3a> */
/* @0x2a493c movs r3, #0x14 */
/* @0x2a493e ldr r2, [r4, #0x34] */
/* @0x2a4940 muls r3, r1, r3 */
/* @0x2a4942 adds r6, r2, r3 */
/* @0x2a4944 ldr r3, [r2, r3] */
/* @0x2a4946 cmp r3, #0x1 */
/* @0x2a4948 bne 0x2a4950 <_Z13_zip_get_nameP3zipiiP9zip_error+0x36> */
/* @0x2a494a movs r1, #0x17 */
/* @0x2a494c mov r2, r5 */
/* @0x2a494e b 0x2a492e <_Z13_zip_get_nameP3zipiiP9zip_error+0x14> */
/* @0x2a4950 ldr r3, [r6, #0x8] */
/* @0x2a4952 cbnz r3, 0x2a496c <_Z13_zip_get_nameP3zipiiP9zip_error+0x52> */
/* @0x2a4954 ldr r2, [r4, #0x20] */
/* @0x2a4956 cmp r2, #0x0 */
/* @0x2a4958 beq 0x2a492a <_Z13_zip_get_nameP3zipiiP9zip_error+0x10> */
/* @0x2a495a ldr r3, [r2, #0x4] */
/* @0x2a495c cmp r1, r3 */
/* @0x2a495e bge 0x2a492a <_Z13_zip_get_nameP3zipiiP9zip_error+0x10> */
/* @0x2a4960 ldr r3, [r2] */
/* @0x2a4962 movs r2, #0x3c */
/* @0x2a4964 mla r1, r2, r1, r3 */
/* @0x2a4966 stmibvs r8, {r0, r8, r12, sp} */
/* @0x2a4968 ldr r0, [r1, #0x18] */
/* @0x2a496a pop {r4, r5, r6, pc} */
/* @0x2a496c mov r0, r3 */
/* @0x2a496e pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a4970 · zip_get_name · size=8 · insn=2 */
/* @0x2a4970 add.w r3, r0, #0xc */
/* @0x2a4974 b.w 0x2a491a <_Z13_zip_get_nameP3zipiiP9zip_error> */

/* ── FUNC 0x2a4978 · _zip_memdup(void const*, unsigned int, zip_error*) · size=42 · insn=20 */
/* @0x2a4978 push {r3, r4, r5, r6, r7, lr} */
/* @0x2a497a mov r6, r0 */
/* @0x2a497c mov r0, r1 */
/* @0x2a497e mov r5, r1 */
/* @0x2a4980 mov r7, r2 */
/* @0x2a4982 blx 0xb6544 <malloc@plt> */
/* @0x2a4984 strmi lr, [r4], -r0, ror #27 */
/* @0x2a4986 mov r4, r0 */
/* @0x2a4988 cbnz r0, 0x2a4996 <_Z11_zip_memdupPKvjP9zip_error+0x1e> */
/* @0x2a498a mov r0, r7 */
/* @0x2a498c movs r1, #0xe */
/* @0x2a498e mov r2, r4 */
/* @0x2a4990 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a4994 b 0x2a499e <_Z11_zip_memdupPKvjP9zip_error+0x26> */
/* @0x2a4996 mov r1, r6 */
/* @0x2a4998 mov r2, r5 */
/* @0x2a499a blx 0xb65bc <memcpy@plt> */
/* @0x2a499c qadd16mi lr, r0, r0 */
/* @0x2a499e mov r0, r4 */
/* @0x2a49a0 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2a49a4 · _zip_name_locate(zip*, char const*, int, zip_error*) · size=180 · insn=85 */
/* @0x2a49a4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a49a8 mov r11, r0 */
/* @0x2a49aa sub sp, #0x14 */
/* @0x2a49ac mov r6, r2 */
/* @0x2a49ae mov r7, r3 */
/* @0x2a49b0 mov r8, r1 */
/* @0x2a49b2 cbnz r1, 0x2a49bc <_Z16_zip_name_locateP3zipPKciP9zip_error+0x18> */
/* @0x2a49b4 mov r0, r3 */
/* @0x2a49b6 movs r1, #0x12 */
/* @0x2a49b8 mov r2, r8 */
/* @0x2a49ba b 0x2a4a3c <_Z16_zip_name_locateP3zipPKciP9zip_error+0x98> */
/* @0x2a49bc lsls r3, r2, #0x1f */
/* @0x2a49be bpl 0x2a49c8 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x24> */
/* @0x2a49c0 ldr r5, [pc, #0x8c] */
/* @0x2a49c2 add r5, pc */
/* @0x2a49c4 ldr r5, [r5] */
/* @0x2a49c6 b 0x2a49ce <_Z16_zip_name_locateP3zipPKciP9zip_error+0x2a> */
/* @0x2a49c8 ldr r5, [pc, #0x88] */
/* @0x2a49ca add r5, pc */
/* @0x2a49cc ldr r5, [r5] */
/* @0x2a49ce ands r2, r6, #0x8 */
/* @0x2a49d0 .word 0xf04f0208 */
/* @0x2a49d2 mov.w r4, #0x0 */
/* @0x2a49d4 .word 0xf04f0400 */
/* @0x2a49d6 mov.w r10, #0x3c */
/* @0x2a49d8 andls r0, r2, #60, #20 */
/* @0x2a49da str r2, [sp, #0x8] */
/* @0x2a49dc itet ne */
/* @0x2a49de ldrne.w r3, [r11, #0x20] */
/* @0x2a49e0 .word 0xf8db3020 */
/* @0x2a49e2 ldreq.w r9, [r11, #0x2c] */
/* @0x2a49e4 .word 0xf8d3902c */
/* @0x2a49e6 ldrne.w r9, [r3, #0x4] */
/* @0x2a49e8 .word 0xf0069004 */
/* @0x2a49ea and r3, r6, #0x2 */
/* @0x2a49ec movwls r0, #0x3302 */
/* @0x2a49ee str r3, [sp, #0xc] */
/* @0x2a49f0 cmp r4, r9 */
/* @0x2a49f2 bge 0x2a4a36 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x92> */
/* @0x2a49f4 ldr r2, [sp, #0x8] */
/* @0x2a49f6 cbz r2, 0x2a4a06 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x62> */
/* @0x2a49f8 ldr.w r3, [r11, #0x20] */
/* @0x2a49fc ldr r3, [r3] */
/* @0x2a49fe mla r3, r10, r4, r3 */
/* @0x2a4a00 ldmibvs r11, {r2, r8, r9, r12, sp} */
/* @0x2a4a02 ldr r3, [r3, #0x18] */
/* @0x2a4a04 b 0x2a4a14 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x70> */
/* @0x2a4a06 mov r3, r7 */
/* @0x2a4a08 mov r0, r11 */
/* @0x2a4a0a mov r1, r4 */
/* @0x2a4a0c mov r2, r6 */
/* @0x2a4a0e bl 0x2a491a <_Z13_zip_get_nameP3zipiiP9zip_error> */
/* @0x2a4a10 strmi pc, [r3], -r4, lsl #31 */
/* @0x2a4a12 mov r3, r0 */
/* @0x2a4a14 cbz r3, 0x2a4a32 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x8e> */
/* @0x2a4a16 ldr r2, [sp, #0xc] */
/* @0x2a4a18 cbz r2, 0x2a4a2a <_Z16_zip_name_locateP3zipPKciP9zip_error+0x86> */
/* @0x2a4a1a mov r0, r3 */
/* @0x2a4a1c movs r1, #0x2f */
/* @0x2a4a1e str r3, [sp, #0x4] */
/* @0x2a4a20 blx 0xb6868 <strrchr@plt> */
/* @0x2a4a24 ldr r3, [sp, #0x4] */
/* @0x2a4a26 cbz r0, 0x2a4a2a <_Z16_zip_name_locateP3zipPKciP9zip_error+0x86> */
/* @0x2a4a28 adds r3, r0, #0x1 */
/* @0x2a4a2a mov r0, r8 */
/* @0x2a4a2c mov r1, r3 */
/* @0x2a4a2e blx r5 */
/* @0x2a4a30 cbz r0, 0x2a4a46 <_Z16_zip_name_locateP3zipPKciP9zip_error+0xa2> */
/* @0x2a4a32 adds r4, #0x1 */
/* @0x2a4a34 b 0x2a49f0 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x4c> */
/* @0x2a4a36 mov r0, r7 */
/* @0x2a4a38 movs r1, #0x9 */
/* @0x2a4a3a movs r2, #0x0 */
/* @0x2a4a3c bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a4a40 mov.w r0, #0xffffffff */
/* @0x2a4a44 b 0x2a4a48 <_Z16_zip_name_locateP3zipPKciP9zip_error+0xa4> */
/* @0x2a4a46 mov r0, r4 */
/* @0x2a4a48 add sp, #0x14 */
/* @0x2a4a4a pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a4a4c svclt #0x8ff0 */
/* @0x2a4a4e nop */
/* @0x2a4a50 beq 0x2a49e8 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x44> */
/* @0x2a4a52 movs r4, r2 */
/* @0x2a4a54 beq 0x2a49e4 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x40> */
/* @0x2a4a56 movs r4, r2 */

/* ── FUNC 0x2a4a58 · zip_name_locate · size=8 · insn=2 */
/* @0x2a4a58 add.w r3, r0, #0xc */
/* @0x2a4a5c b.w 0x2a49a4 <_Z16_zip_name_locateP3zipPKciP9zip_error> */

/* ── FUNC 0x2a4a60 · anon_2a4a60 · size=892 · insn=224 */
/* @0x2a4a60 .word 0x4604b51f */
/* @0x2a4a64 .word 0xb1699201 */
/* @0x2a4a68 bge 0x376290 <_ZTS13C_UTF16String+0xd33c> */
/* @0x2a4a6c .word 0xf7ffa901 */
/* @0x2a4a70 stmdals r1, {r1, r2, r3, r4, r6, r10, r11, r12, sp, lr, pc} */
/* @0x2a4a74 ldc2l p7, c15, [r4], #-1020 */
/* @0x2a4a78 mrsle r2, apsr */
/* @0x2a4a7c ldm r12!, {r1, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a4a80 andvs r9, r3, r3, lsl #22 */
/* @0x2a4a84 blls 0x310ebc <af_shaper_get_elem+0x672a> */
/* @0x2a4a88 andlt r6, r4, r3, lsr #32 */
/* @0x2a4a8c andeq r11, r0, r0, lsl sp */
/* @0x2a4a90 ldrblt r4, [r0, #0xb2b]! */
/* @0x2a4a94 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x2a4a98 strmi r11, [r4], -r9, lsl #1 */
/* @0x2a4a9c sadd16mi r6, pc, r10 */
/* @0x2a4aa0 stmdavs r2, {r0, r1, r2, r9, r12, pc} ^ */
/* @0x2a4aa4 suble r2, r2, r0, lsl #20 */
/* @0x2a4aa8 blhs 0x2becbc <jpeg_huff_decode+0x130> */
/* @0x2a4aac bvs 0x358bb0 */
/* @0x2a4ab0 eorsle r2, r12, r0, lsl #20 */
/* @0x2a4ab4 blhs 0x847508 <b2_toiTime+0xee064> */
/* @0x2a4ab8 ldmdbvs r6, {r0, r3, r4, r5, r8, r12, lr, pc} */
/* @0x2a4abc stmdbmi r1!, {r1, r2, r3, r9, sp} */
/* @0x2a4ac0 ldrbtmi r4, [r9], #-1584 */
/* @0x2a4ac4 stc p6, c15, [r12, #68] */
/* @0x2a4ac8 stmdahs r0, {r0, r2, r9, r10, lr} */
/* @0x2a4acc ldrtmi sp, [r2], -pc, lsr #2 */
/* @0x2a4ad0 .word 0xf852ae04 */
/* @0x2a4ad4 ldrtmi r0, [r3], -lr, lsl #30 */
/* @0x2a4ad8 movwgt r6, #0x3851 */
/* @0x2a4adc andspl pc, r8, sp, lsl #17 */
/* @0x2a4ae0 stm r10, {r1, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a4ae4 andshs r10, r0, #49152 */
/* @0x2a4ae8 ldrtmi r6, [r0], -r5 */
/* @0x2a4aec svc #0x46f611 */
/* @0x2a4af0 strmi r1, [r5], -r3, asr #24 */
/* @0x2a4af4 blls 0x398b04 <ft_adobe_glyph_list+0x81e0> */
/* @0x2a4af8 and r11, r6, r11, lsr #18 */
/* @0x2a4afc ldmda r12!, {r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a4b00 stmiblt r3!, {r0, r1, r11, sp, lr} */
/* @0x2a4b04 ldmdavc r11, {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2a4b08 bvs 0xb9313c <b2_toiTime+0x439c98> */
/* @0x2a4b0c stmdavs r0!, {r9, sp} ^ */
/* @0x2a4b10 ldmvs r9, {r9, r12, pc} ^ */
/* @0x2a4b14 blge 0x33ed84 */
/* @0x2a4b18 stc2l p7, c15, [lr], #-1020 */
/* @0x2a4b1c blle 0x42eb24 <g_RomDisk+0x37304> */
/* @0x2a4b20 adcmi r9, r11, #2048 */
/* @0x2a4b24 stmibvs r3!, {r0, r1, r8, r12, lr, pc} */
/* @0x2a4b28 movweq pc, #0x1043 */
/* @0x2a4b2c bls 0x47d1c0 <targetStr+0x1f80> */
/* @0x2a4b30 addsmi r6, r10, #3866624 */
/* @0x2a4b34 .word 0xf611d001 */
/* @0x2a4b38 andlt lr, r9, lr, asr #26 */
/* @0x2a4b3c svclt #0xbdf0 */
/* @0x2a4b40 andseq r8, r4, r0, asr #29 */
/* @0x2a4b44 andeq r7, lr, r11, asr #10 */
/* @0x2a4b48 ldrblt r2, [r8, #0x903]! */
/* @0x2a4b4c strmi r4, [sp], -r6, lsl #12 */
/* @0x2a4b50 svcmi #0xcdd14 */
/* @0x2a4b54 ldrbtmi r1, [pc], #-3652 */
/* @0x2a4b58 stclne p7, c3, [r0], #-4 */
/* @0x2a4b5c bne 0xf2d0a4 <b2_toiTime+0x7d3c00> */
/* @0x2a4b60 blo 0x375c10 <_ZTS13C_UTF16String+0xccbc> */
/* @0x2a4b64 ldc p6, c15, [r12, #68] */
/* @0x2a4b68 .word 0xb1484604 */
/* @0x2a4b6c ldrtmi r1, [r9], -r0, ror #24 */
/* @0x2a4b70 .word 0xf6122203 */
/* @0x2a4b74 stmdahs r0, {r1, r2, r5, r6, r11, sp, lr, pc} */
/* @0x2a4b78 and sp, r1, pc, ror #3 */
/* @0x2a4b7c ldcllt p0, c2, [r8, #0]! */
/* @0x2a4b80 ldcllt p6, c4, [r8, #128]! */
/* @0x2a4b84 strheq r7, [lr], -r2 */
/* @0x2a4b88 .word 0x4605b538 */
/* @0x2a4b8c strmi r6, [r12], -r0, lsl #19 */
/* @0x2a4b90 stmibvs r9, {r8, r9, r12, sp, pc} */
/* @0x2a4b94 .word 0xf611b1f1 */
/* @0x2a4b98 ldmiblt r8, {r1, r2, r3, r5, r6, r7, r10, r11, sp, lr, pc} ^ */
/* @0x2a4b9c .word 0xf01388a3 */
/* @0x2a4ba0 stmvs r3!, {r3, r8, r9, r10, r11} ^ */
/* @0x2a4ba4 stmiblt r11!, {r3, r12, lr, pc} */
/* @0x2a4ba8 ldmiblt r11, {r0, r1, r5, r8, r11, sp, lr} */
/* @0x2a4bac stmdalo r0, {r5, r6, r8, r11, sp, lr} */
/* @0x2a4bb0 .word 0xf06fbf18 */
/* @0x2a4bb4 ldclt p0, c0, [r8, #-0]! */
/* @0x2a4bb8 addsmi r6, r10, #15335424 */
/* @0x2a4bbc stmdbvs r10!, {r1, r3, r8, r12, lr, pc} */
/* @0x2a4bc0 addsmi r6, r10, #573440 */
/* @0x2a4bc4 stmdbvs r8!, {r1, r2, r8, r12, lr, pc} ^ */
/* @0x2a4bc8 bne 0xff2bf15c <b2_toiTime+0xfffffffffeb65cb8> */
/* @0x2a4bcc .word 0xf06fbf18 */
/* @0x2a4bd0 ldclt p0, c0, [r8, #-0]! */
/* @0x2a4bd4 rscslo pc, pc, pc, asr #32 */
/* @0x2a4bd8 push {r3, r4, r5, r8, r10, r11, r12, sp, pc} */
/* @0x2a4bdc .word 0x46814ff0 */
/* @0x2a4be0 addslt r6, r5, r12, asr #16 */
/* @0x2a4be4 ldrmi r4, [r2], sp, lsl #12 */
/* @0x2a4be8 stmdavs r11, {r2, r3, r8, r12, sp, pc} */
/* @0x2a4bec .word 0xf10d6b9c */
/* @0x2a4bf0 qadd16mi r0, r6, r4 */
/* @0x2a4bf4 .word 0xf04f2700 */
/* @0x2a4bf8 stmdavs r11!, {r2, r3, r4, r5, r8, r9, r11} ^ */
/* @0x2a4bfc ble 0x18b5680 <b2_toiTime+0x115c1dc> */
/* @0x2a4c00 .word 0xfc07fb0b */
/* @0x2a4c04 stmvs r9!, {r0, r1, r3, r5, r11, sp, lr} ^ */
/* @0x2a4c08 blvs 0xfe935d9c <b2_toiTime+0xfffffffffe1dc8f8> */
/* @0x2a4c0c svclt #0x284294 */
/* @0x2a4c10 addmi r4, r12, #20, #12 */
/* @0x2a4c14 ldrbmi sp, [r0], -r5, lsl #18 */
/* @0x2a4c18 andhs r2, r0, #-1073741820 */
/* @0x2a4c1c blx 0xfe9e2c22 <b2_toiTime+0xfffffffffe28977e> */
/* @0x2a4c20 ldmdbvs r8, {r0, r1, r2, r3, r4, r5, sp, lr, pc} */
/* @0x2a4c24 ldrmi r8, [r0], #-2971 */
/* @0x2a4c28 ldrmi r3, [r8], #-30 */
/* @0x2a4c2c svclt #0x384286 */
/* @0x2a4c30 addmi r4, lr, #6291456 */
/* @0x2a4c34 .word 0xf8d9d8ef */
/* @0x2a4c38 .word 0x21003000 */
/* @0x2a4c3c ldmdbvs r11, {r3, r6, r9, r10, lr} */
/* @0x2a4c40 andgt pc, r12, sp, asr #17 */
/* @0x2a4c44 andhs r4, r0, #152, #14 */
/* @0x2a4c48 strbmi r2, [r0], -r1, lsl #6 */
/* @0x2a4c4c streq lr, [r8], #-2189 */
/* @0x2a4c50 ldrmi r4, [r3], -r9, asr #12 */
/* @0x2a4c54 blx 0x18e2c58 <b2_toiTime+0x11897b4> */
/* @0x2a4c58 .word 0xc00cf8dd */
/* @0x2a4c5c eorle r1, r9, r3, asr #24 */
/* @0x2a4c60 rfeia sp! */
/* @0x2a4c64 strbtmi r3, [r0], #-22 */
/* @0x2a4c68 addsmi r8, r10, #4325376 */
/* @0x2a4c6c stmhi r2, {r0, r4, r8, r12, lr, pc} ^ */
/* @0x2a4c70 ldrhlo pc, [r10], -sp */
/* @0x2a4c74 swple r4, r10, [r12] */
/* @0x2a4c78 blls 0x47ee88 <targetStr+0x3c48> */
/* @0x2a4c7c swple r4, r10, [r8] */
/* @0x2a4c80 rfeia sp! */
/* @0x2a4c84 addsmi r3, r10, #48 */
/* @0x2a4c88 strbmi sp, [r1], -r3, lsl #2 */
/* @0x2a4c8c .word 0xff7cf7ff */
/* @0x2a4c90 usaxmi r11, r0, r0 */
/* @0x2a4c94 andhs r2, r0, #1073741829 */
/* @0x2a4c98 blx 0x1a62c9e <b2_toiTime+0x13097fa> */
/* @0x2a4c9c .word 0xf7fe4640 */
/* @0x2a4ca0 .word 0xf04fff9a */
/* @0x2a4ca4 strd r3, r4, [r5], -pc */
/* @0x2a4ca8 strlo r4, [r1, -r0, asr #12] */
/* @0x2a4cac .word 0xff93f7fe */
/* @0x2a4cb0 blne 0xedeb44 <b2_toiTime+0x7856a0> */
/* @0x2a4cb4 pop {r0, r2, r4, r12, sp, pc} */
/* @0x2a4cb8 ldrblt r8, [r0, #0xff0]! */
/* @0x2a4cbc cdpge p0, #0x0, c11, c1, c5, #0x4 */
/* @0x2a4cc0 strmi r4, [sp], -r7, lsl #12 */
/* @0x2a4cc4 .word 0xf0004630 */
/* @0x2a4cc8 .word 0x4604fe5a */
/* @0x2a4ccc qasxmi r11, r8, r0 */
/* @0x2a4cd0 qasxmi r4, r2, r1 */
/* @0x2a4cd4 mcr2 p7, #0x6, pc, c4, c15, #0x7 */
/* @0x2a4cd8 and r4, lr, r0, lsr #12 */
/* @0x2a4cdc .word 0xf6114638 */
/* @0x2a4ce0 .word 0x4606ecb0 */
/* @0x2a4ce4 strtmi r6, [r0], -r0, lsr #32 */
/* @0x2a4ce8 .word 0xf7ffb93e */
/* @0x2a4cec tstlt sp, r11, asr #27 */
/* @0x2a4cf0 ldrtmi r2, [r0], -lr, lsl #6 */
/* @0x2a4cf4 and r6, r0, r11, lsr #32 */
/* @0x2a4cf8 andlt r4, r5, r8, lsr #12 */
/* @0x2a4cfc push {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */
/* @0x2a4d00 .word 0x46814ff0 */
/* @0x2a4d04 addslt r6, r3, r12, asr #16 */
/* @0x2a4d08 ldrmi r4, [r7], -r11, lsl #13 */
/* @0x2a4d0c stmdavs r11, {r2, r3, r8, r12, sp, pc} */
/* @0x2a4d10 .word 0xf10d6b9c */
/* @0x2a4d14 strtmi r0, [r5], -r12, lsl #16 */
/* @0x2a4d18 .word 0xf8db2600 */
/* @0x2a4d1c addsmi r3, lr, #4 */
/* @0x2a4d20 teqhs r12, #368640 */
/* @0x2a4d24 .word 0x200cf8db */
/* @0x2a4d28 blx 0x46393c <g_RomDisk+0x6c11c> */
/* @0x2a4d2c .word 0x3000f8db */
/* @0x2a4d30 blvs 0xfe8f5e84 <b2_toiTime+0xfffffffffe19c9e0> */
/* @0x2a4d34 svclt #0x28428c */
/* @0x2a4d38 addsmi r4, r4, #12, #12 */
/* @0x2a4d3c ldrtmi sp, [r8], -r2, lsl #18 */
/* @0x2a4d40 ands r2, r1, r3, lsl r1 */
/* @0x2a4d44 blhi 0xfe97f1ac <b2_toiTime+0xfffffffffe225d08> */
/* @0x2a4d48 andslo r4, lr, r8, lsl #8 */
/* @0x2a4d4c addmi r4, r5, #24, #8 */
/* @0x2a4d50 .word 0x4605bf38 */
/* @0x2a4d54 ldmle r2!, {r0, r2, r4, r7, r9, lr} ^ */
/* @0x2a4d58 strbmi r2, [r8], -r0, lsl #4 */
/* @0x2a4d5c ldm r10!, {r1, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a4d60 .word 0xb1284602 */
/* @0x2a4d64 .word 0x21044638 */
/* @0x2a4d68 .word 0xf7ff2200 */
/* @0x2a4d6c .word 0xe02bfaf5 */
/* @0x2a4d70 strbmi r2, [r0], -r1, lsl #6 */
/* @0x2a4d74 addeq lr, r8, sp, lsl #17 */
/* @0x2a4d78 ldrmi r4, [r3], -r9, asr #12 */
/* @0x2a4d7c rfeia r8! */
/* @0x2a4d80 eorle r1, r10, r3, asr #24 */
/* @0x2a4d84 .word 0x0000f8db */
/* @0x2a4d88 strhlo pc, [lr], -sp */
/* @0x2a4d8c stmdahi r2, {r4, r6, r10, lr} ^ */
/* @0x2a4d90 .word 0xd111429a */
/* @0x2a4d94 rfeia sp! */
/* @0x2a4d98 addsmi r3, r10, #18 */
/* @0x2a4d9c stmvs r2, {r2, r3, r8, r12, lr, pc} */
/* @0x2a4da0 addsmi r9, r10, #5120 */
/* @0x2a4da4 blhi 0xfe3591cc <b2_toiTime+0xfffffffffdbffd28> */
/* @0x2a4da8 .word 0x3028f8bd */
/* @0x2a4dac swple r4, r10, [r3] */
/* @0x2a4db0 .word 0xf7ff4641 */
/* @0x2a4db4 cmplt r0, r9, ror #29 */
/* @0x2a4db8 tsths r5, r8, lsr r6 */
/* @0x2a4dbc .word 0xf7ff2200 */
/* @0x2a4dc0 strbmi pc, [r0], -r11, asr #21 */
/* @0x2a4dc4 .word 0xff07f7fe */
/* @0x2a4dc8 rscslo pc, pc, pc, asr #32 */
/* @0x2a4dcc strbmi lr, [r0], -r5 */
/* @0x2a4dd0 .word 0xf7fe3601 */
/* @0x2a4dd4 str pc, [r0, r0, lsl #30]! */
/* @0x2a4dd8 andslt r1, r3, r8, lsr #22 */
/* @0x2a4ddc svchi #0xf0e8bd */

/* ── FUNC 0x2a4de0 · zip_open · size=960 · insn=431 */
/* @0x2a4de0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a4de4 sub sp, #0xa4 */
/* @0x2a4de6 mov r5, r2 */
/* @0x2a4de8 str r1, [sp, #0x10] */
/* @0x2a4dea str r0, [sp, #0x18] */
/* @0x2a4dec cbnz r0, 0x2a4df6 <zip_open+0x16> */
/* @0x2a4dee cmp r2, #0x0 */
/* @0x2a4df0 beq 0x2a4eca <zip_open+0xea> */
/* @0x2a4df2 movs r3, #0x12 */
/* @0x2a4df4 b 0x2a4e1c <zip_open+0x3c> */
/* @0x2a4df6 add r7, sp, #0x38 */
/* @0x2a4df8 mov r1, r7 */
/* @0x2a4dfa blx 0xb69f4 <stat@plt> */
/* @0x2a4dfc ldrshlt lr, [r0, -r12]! */
/* @0x2a4dfe cbz r0, 0x2a4e0e <zip_open+0x2e> */
/* @0x2a4e00 ldr r2, [sp, #0x10] */
/* @0x2a4e02 lsls r1, r2, #0x1f */
/* @0x2a4e04 bmi 0x2a4e20 <zip_open+0x40> */
/* @0x2a4e06 cmp r5, #0x0 */
/* @0x2a4e08 beq 0x2a4eca <zip_open+0xea> */
/* @0x2a4e0a movs r3, #0xb */
/* @0x2a4e0c b 0x2a4e1c <zip_open+0x3c> */
/* @0x2a4e0e ldr r3, [sp, #0x10] */
/* @0x2a4e10 ands r4, r3, #0x2 */
/* @0x2a4e14 beq 0x2a4e2a <zip_open+0x4a> */
/* @0x2a4e16 cmp r5, #0x0 */
/* @0x2a4e18 beq 0x2a4eca <zip_open+0xea> */
/* @0x2a4e1a movs r3, #0xa */
/* @0x2a4e1c str r3, [r5] */
/* @0x2a4e1e b 0x2a4eca <zip_open+0xea> */
/* @0x2a4e20 ldr r0, [sp, #0x18] */
/* @0x2a4e22 mov r1, r5 */
/* @0x2a4e24 bl 0x2a4cba <zip_name_locate+0x262> */
/* @0x2a4e28 b 0x2a519a <zip_open+0x3ba> */
/* @0x2a4e2a ldr r1, [pc, #0x298] */
/* @0x2a4e2c ldr r0, [sp, #0x18] */
/* @0x2a4e2e add r1, pc */
/* @0x2a4e30 blx 0xb6844 <fopen@plt> */
/* @0x2a4e34 mov r6, r0 */
/* @0x2a4e36 cbnz r0, 0x2a4e42 <zip_open+0x62> */
/* @0x2a4e38 cmp r5, #0x0 */
/* @0x2a4e3a beq 0x2a4ece <zip_open+0xee> */
/* @0x2a4e3c movs r3, #0xb */
/* @0x2a4e3e str r3, [r5] */
/* @0x2a4e40 b 0x2a519a <zip_open+0x3ba> */
/* @0x2a4e42 mov r1, r4 */
/* @0x2a4e44 movs r2, #0x2 */
/* @0x2a4e46 blx 0xb6ed4 <fseeko@plt> */
/* @0x2a4e48 ldrtmi lr, [r0], -r6, asr #16 */
/* @0x2a4e4a mov r0, r6 */
/* @0x2a4e4c blx 0xb6ee0 <ftello@plt> */
/* @0x2a4e50 cbnz r0, 0x2a4e62 <zip_open+0x82> */
/* @0x2a4e52 ldr r0, [sp, #0x18] */
/* @0x2a4e54 mov r1, r5 */
/* @0x2a4e56 bl 0x2a4cba <zip_name_locate+0x262> */
/* @0x2a4e58 .word 0x4604ff30 */
/* @0x2a4e5a mov r4, r0 */
/* @0x2a4e5c cbz r0, 0x2a4ea0 <zip_open+0xc0> */
/* @0x2a4e5e str r6, [r0, #0x4] */
/* @0x2a4e60 b 0x2a4eb0 <zip_open+0xd0> */
/* @0x2a4e62 ldr r1, [pc, #0x25c] */
/* @0x2a4e64 movs r2, #0x2 */
/* @0x2a4e66 cmp r0, r1 */
/* @0x2a4e68 it lt */
/* @0x2a4e6a movlt r1, r0 */
/* @0x2a4e6c mov r0, r6 */
/* @0x2a4e6e rsbs r1, r1, #0 */
/* @0x2a4e70 blx 0xb6ed4 <fseeko@plt> */
/* @0x2a4e74 adds r0, #0x1 */
/* @0x2a4e76 bne 0x2a4eb4 <zip_open+0xd4> */
/* @0x2a4e78 blx 0xb6bf8 <__errno@plt> */
/* @0x2a4e7c ldr r3, [r0] */
/* @0x2a4e7e cmp r3, #0x1b */
/* @0x2a4e80 bne 0x2a4ed2 <zip_open+0xf2> */
/* @0x2a4e82 b 0x2a4eb4 <zip_open+0xd4> */
/* @0x2a4e84 cmp.w r8, #0x0 */
/* @0x2a4e88 beq 0x2a4ec4 <zip_open+0xe4> */
/* @0x2a4e8a ldr r0, [sp, #0x18] */
/* @0x2a4e8c mov r1, r5 */
/* @0x2a4e8e bl 0x2a4cba <zip_name_locate+0x262> */
/* @0x2a4e90 .word 0x4604ff14 */
/* @0x2a4e92 mov r4, r0 */
/* @0x2a4e94 cmp r0, #0x0 */
/* @0x2a4e96 bne.w 0x2a515a <zip_open+0x37a> */
/* @0x2a4e98 strbmi r8, [r0], -r0, ror #2 */
/* @0x2a4e9a mov r0, r8 */
/* @0x2a4e9c bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir> */
/* @0x2a4ea0 mov r0, r6 */
/* @0x2a4ea2 blx 0xb6850 <fclose@plt> */
/* @0x2a4ea4 ldrd lr, pc, [r3], -r6 */
/* @0x2a4ea6 b 0x2a4eb0 <zip_open+0xd0> */
/* @0x2a4ea8 bl 0x2a4a90 <zip_name_locate+0x38> */
/* @0x2a4eac ldr r3, [r4, #0x18] */
/* @0x2a4eae str r3, [r4, #0x1c] */
/* @0x2a4eb0 mov r0, r4 */
/* @0x2a4eb2 b 0x2a519a <zip_open+0x3ba> */
/* @0x2a4eb4 ldr r0, [pc, #0x208] */
/* @0x2a4eb6 blx 0xb6544 <malloc@plt> */
/* @0x2a4eb8 strmi lr, [r3], r6, asr #22 */
/* @0x2a4eba mov r11, r0 */
/* @0x2a4ebc cbnz r0, 0x2a4eda <zip_open+0xfa> */
/* @0x2a4ebe cbz r5, 0x2a4ec4 <zip_open+0xe4> */
/* @0x2a4ec0 movs r3, #0xe */
/* @0x2a4ec2 str r3, [r5] */
/* @0x2a4ec4 mov r0, r6 */
/* @0x2a4ec6 blx 0xb6850 <fclose@plt> */
/* @0x2a4ec8 andhs lr, r0, r4, asr #25 */
/* @0x2a4eca movs r0, #0x0 */
/* @0x2a4ecc b 0x2a519a <zip_open+0x3ba> */
/* @0x2a4ece mov r0, r5 */
/* @0x2a4ed0 b 0x2a519a <zip_open+0x3ba> */
/* @0x2a4ed2 movs r3, #0x4 */
/* @0x2a4ed4 cmp r5, #0x0 */
/* @0x2a4ed6 bne 0x2a4ec2 <zip_open+0xe2> */
/* @0x2a4ed8 b 0x2a4ec4 <zip_open+0xe4> */
/* @0x2a4eda mov r0, r6 */
/* @0x2a4edc blx 0xb6f1c <clearerr@plt> */
/* @0x2a4ee0 mov r0, r11 */
/* @0x2a4ee2 movs r1, #0x1 */
/* @0x2a4ee4 ldr r2, [pc, #0x1d8] */
/* @0x2a4ee6 mov r3, r6 */
/* @0x2a4ee8 blx 0xb68c8 <fread@plt> */
/* @0x2a4eec ldrh.w r8, [r6, #0xc] */
/* @0x2a4ef0 and r8, r8, #0x40 */
/* @0x2a4ef4 uxth.w r4, r8 */
/* @0x2a4ef8 str r0, [sp, #0x20] */
/* @0x2a4efa cbz r4, 0x2a4f0a <zip_open+0x12a> */
/* @0x2a4efc cbz r5, 0x2a4f02 <zip_open+0x122> */
/* @0x2a4efe movs r3, #0x5 */
/* @0x2a4f00 str r3, [r5] */
/* @0x2a4f02 mov r0, r11 */
/* @0x2a4f04 blx 0xb655c <free@plt> */
/* @0x2a4f08 b 0x2a4ec4 <zip_open+0xe4> */
/* @0x2a4f0a mov r2, r4 */
/* @0x2a4f0c mov r0, r7 */
/* @0x2a4f0e movs r1, #0x13 */
/* @0x2a4f10 mov r8, r4 */
/* @0x2a4f12 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a4f14 .word 0xf04ffa21 */
/* @0x2a4f16 mov.w r2, #0xffffffff */
/* @0x2a4f18 blmi 0x1d71b1c <b2_toiTime+0x1618678> */
/* @0x2a4f1a ldr r3, [pc, #0x1ac] */
/* @0x2a4f1c str r2, [sp, #0x8] */
/* @0x2a4f1e ldr r2, [pc, #0x1ac] */
/* @0x2a4f20 add r3, pc */
/* @0x2a4f22 str.w r11, [sp, #0x1c] */
/* @0x2a4f24 movwls r11, #0xa01c */
/* @0x2a4f26 str r3, [sp, #0x28] */
/* @0x2a4f28 add r2, pc */
/* @0x2a4f2a add r3, sp, #0x30 */
/* @0x2a4f2c str r2, [sp, #0x2c] */
/* @0x2a4f2e str r3, [sp, #0xc] */
/* @0x2a4f30 ldr r2, [sp, #0x1c] */
/* @0x2a4f32 ldr r3, [sp, #0x20] */
/* @0x2a4f34 rsb r1, r2, r11 */
/* @0x2a4f38 add r1, r3 */
/* @0x2a4f3a mov r0, r2 */
/* @0x2a4f3c subs r1, #0x12 */
/* @0x2a4f3e bl 0x2a4b48 <zip_name_locate+0xf0> */
/* @0x2a4f40 strmi pc, [r1], r3, lsl #28 */
/* @0x2a4f42 mov r9, r0 */
/* @0x2a4f44 cmp r0, #0x0 */
/* @0x2a4f46 beq.w 0x2a513a <zip_open+0x35a> */
/* @0x2a4f48 blls 0x4c5330 <SrcVerts+0x22374> */
/* @0x2a4f4a ldr r3, [sp, #0x20] */
/* @0x2a4f4c add.w r2, r9, #0x1 */
/* @0x2a4f50 str r2, [sp, #0x1c] */
/* @0x2a4f52 add r3, r11 */
/* @0x2a4f54 rsb r3, r9, r3 */
/* @0x2a4f58 subs r3, #0x16 */
/* @0x2a4f5a str r3, [sp, #0x14] */
/* @0x2a4f5c bpl 0x2a4f66 <zip_open+0x186> */
/* @0x2a4f5e mov r0, r7 */
/* @0x2a4f60 movs r1, #0x13 */
/* @0x2a4f62 movs r2, #0x0 */
/* @0x2a4f64 b 0x2a4f8a <zip_open+0x1aa> */
/* @0x2a4f66 ldr r1, [sp, #0x28] */
/* @0x2a4f68 movs r2, #0x4 */
/* @0x2a4f6a blx 0xb6c40 <memcmp@plt> */
/* @0x2a4f6c strmi lr, [r4], -r10, ror #28 */
/* @0x2a4f6e mov r4, r0 */
/* @0x2a4f70 cmp r0, #0x0 */
/* @0x2a4f72 bne 0x2a4f5e <zip_open+0x17e> */
/* @0x2a4f74 add.w r0, r9, #0x4 */
/* @0x2a4f78 ldr r1, [sp, #0x2c] */
/* @0x2a4f7a movs r2, #0x4 */
/* @0x2a4f7c blx 0xb6c40 <memcmp@plt> */
/* @0x2a4f80 mov r10, r0 */
/* @0x2a4f82 cbz r0, 0x2a4f90 <zip_open+0x1b0> */
/* @0x2a4f84 mov r0, r7 */
/* @0x2a4f86 movs r1, #0x1 */
/* @0x2a4f88 mov r2, r4 */
/* @0x2a4f8a bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a4f8c sbc pc, lr, r5, ror #19 */
/* @0x2a4f8e b 0x2a512e <zip_open+0x34e> */
/* @0x2a4f90 add r0, sp, #0x30 */
/* @0x2a4f92 add.w r3, r9, #0x8 */
/* @0x2a4f94 movwls r0, #0xc308 */
/* @0x2a4f96 str r3, [sp, #0x30] */
/* @0x2a4f98 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a4f9c str r0, [sp, #0x24] */
/* @0x2a4f9e add r0, sp, #0x30 */
/* @0x2a4fa0 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a4fa4 mov r1, r7 */
/* @0x2a4fa6 bl 0x2a3b88 <_Z13_zip_cdir_newiP9zip_error> */
/* @0x2a4fa8 strmi pc, [r4], -pc, ror #27 */
/* @0x2a4faa mov r4, r0 */
/* @0x2a4fac cmp r0, #0x0 */
/* @0x2a4fae beq.w 0x2a512e <zip_open+0x34e> */
/* @0x2a4fb0 stmdage r12, {r1, r2, r3, r4, r5, r7, pc} */
/* @0x2a4fb2 add r0, sp, #0x30 */
/* @0x2a4fb4 bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a4fb8 str r0, [r4, #0x8] */
/* @0x2a4fba add r0, sp, #0x30 */
/* @0x2a4fbc bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a4fc0 str.w r10, [r4, #0x10] */
/* @0x2a4fc4 str r0, [r4, #0xc] */
/* @0x2a4fc6 add r0, sp, #0x30 */
/* @0x2a4fc8 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a4fcc ldr r3, [sp, #0x14] */
/* @0x2a4fce cmp r3, r0 */
/* @0x2a4fd0 mov r1, r0 */
/* @0x2a4fd2 strh r0, [r4, #0x14] */
/* @0x2a4fd4 blt 0x2a4fde <zip_open+0x1fe> */
/* @0x2a4fd6 ldr r3, [r4, #0x4] */
/* @0x2a4fd8 ldr r2, [sp, #0x24] */
/* @0x2a4fda cmp r3, r2 */
/* @0x2a4fdc beq 0x2a4fe6 <zip_open+0x206> */
/* @0x2a4fde mov r0, r7 */
/* @0x2a4fe0 movs r1, #0x13 */
/* @0x2a4fe2 movs r2, #0x0 */
/* @0x2a4fe4 b 0x2a506e <zip_open+0x28e> */
/* @0x2a4fe6 ldr r3, [sp, #0x10] */
/* @0x2a4fe8 lsls r2, r3, #0x1d */
/* @0x2a4fea bpl 0x2a4ffa <zip_open+0x21a> */
/* @0x2a4fec ldr r3, [sp, #0x14] */
/* @0x2a4fee cmp r3, r0 */
/* @0x2a4ff0 beq 0x2a4ffa <zip_open+0x21a> */
/* @0x2a4ff2 mov r0, r7 */
/* @0x2a4ff4 movs r1, #0x15 */
/* @0x2a4ff6 mov r2, r10 */
/* @0x2a4ff8 b 0x2a506e <zip_open+0x28e> */
/* @0x2a4ffa cbz r1, 0x2a500c <zip_open+0x22c> */
/* @0x2a4ffc add.w r0, r9, #0x16 */
/* @0x2a5000 mov r2, r7 */
/* @0x2a5002 bl 0x2a4978 <_Z11_zip_memdupPKvjP9zip_error> */
/* @0x2a5004 strhvs pc, [r0, -r9]! */
/* @0x2a5006 str r0, [r4, #0x10] */
/* @0x2a5008 cmp r0, #0x0 */
/* @0x2a500a beq 0x2a5072 <zip_open+0x292> */
/* @0x2a500c ldr r3, [r4, #0x8] */
/* @0x2a500e rsb r2, r11, r9 */
/* @0x2a5010 addsmi r0, r3, #-1879048192 */
/* @0x2a5012 cmp r3, r2 */
/* @0x2a5014 bhs 0x2a5022 <zip_open+0x242> */
/* @0x2a5016 rsb r3, r3, r9 */
/* @0x2a5018 bge 0x5a5c44 <g_SWFlineaavertbuff+0x52b7c> */
/* @0x2a501a add r2, sp, #0x30 */
/* @0x2a501c str r3, [sp, #0x30] */
/* @0x2a501e str r2, [sp, #0x14] */
/* @0x2a5020 b 0x2a507a <zip_open+0x29a> */
/* @0x2a5022 mov r0, r6 */
/* @0x2a5024 blx 0xb6f1c <clearerr@plt> */
/* @0x2a5028 mov r0, r6 */
/* @0x2a502a ldr r1, [r4, #0xc] */
/* @0x2a502c movs r2, #0x0 */
/* @0x2a502e blx 0xb6ed4 <fseeko@plt> */
/* @0x2a5030 rfeia r6! */
/* @0x2a5032 ldrh.w r10, [r6, #0xc] */
/* @0x2a5034 .word 0xf00aa00c */
/* @0x2a5036 and r10, r10, #0x40 */
/* @0x2a5038 blx 0xa67940 <b2_toiTime+0x30e49c> */
/* @0x2a503a uxth.w r10, r10 */
/* @0x2a503c .word 0xf1bafa8a */
/* @0x2a503e cmp.w r10, #0x0 */
/* @0x2a5040 .word 0xd1080f00 */
/* @0x2a5042 bne 0x2a5056 <zip_open+0x276> */
/* @0x2a5044 mov r0, r6 */
/* @0x2a5046 blx 0xb6ee0 <ftello@plt> */
/* @0x2a5048 stmvs r3!, {r2, r3, r6, r8, r9, r10, r11, sp, lr, pc} ^ */
/* @0x2a504a ldr r3, [r4, #0xc] */
/* @0x2a504c cmp r0, r3 */
/* @0x2a504e bne 0x2a5056 <zip_open+0x276> */
/* @0x2a5050 str.w r10, [sp, #0x14] */
/* @0x2a5054 b 0x2a507a <zip_open+0x29a> */
/* @0x2a5056 ldrh r2, [r6, #0xc] */
/* @0x2a5058 and r2, r2, #0x40 */
/* @0x2a505c uxth r2, r2 */
/* @0x2a505e cmp r2, #0x0 */
/* @0x2a5060 beq.w 0x2a5194 <zip_open+0x3b4> */
/* @0x2a5064 blx 0xb6bf8 <__errno@plt> */
/* @0x2a5068 movs r1, #0x4 */
/* @0x2a506a ldr r2, [r0] */
/* @0x2a506c mov r0, r7 */
/* @0x2a506e bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a5070 qsub16mi pc, r0, r3 */
/* @0x2a5072 mov r0, r4 */
/* @0x2a5074 blx 0xb655c <free@plt> */
/* @0x2a5078 b 0x2a512e <zip_open+0x34e> */
/* @0x2a507a ldr r3, [r4, #0x8] */
/* @0x2a507c add.w r9, sp, #0xa0 */
/* @0x2a5080 mov.w r10, #0x0 */
/* @0x2a5084 str r3, [r9, #-108]! */
/* @0x2a5088 ldr r3, [r4, #0x4] */
/* @0x2a508a cmp r10, r3 */
/* @0x2a508c bne 0x2a509e <zip_open+0x2be> */
/* @0x2a508e ldr r3, [sp, #0x34] */
/* @0x2a5090 cbz r3, 0x2a509e <zip_open+0x2be> */
/* @0x2a5092 mov r0, r4 */
/* @0x2a5094 add.w r1, r10, #0x10000 */
/* @0x2a5098 mov r2, r7 */
/* @0x2a509a bl 0x2a3b4e <_Z14_zip_cdir_growP8zip_cdiriP9zip_error> */
/* @0x2a509c stmdavs r0!, {r3, r4, r6, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2a509e ldr r0, [r4] */
/* @0x2a50a0 movs r2, #0x3c */
/* @0x2a50a2 movs r3, #0x0 */
/* @0x2a50a4 mov r1, r6 */
/* @0x2a50a6 stm.w sp, {r3, r7} */
/* @0x2a50a8 strbmi r0, [r11], -r8, lsl #1 */
/* @0x2a50aa mov r3, r9 */
/* @0x2a50ac mla r0, r2, r10, r0 */
/* @0x2a50b0 ldr r2, [sp, #0x14] */
/* @0x2a50b2 bl 0x2a3ef0 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error> */
/* @0x2a50b4 stmdahs r0, {r0, r2, r3, r4, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a50b6 cmp r0, #0x0 */
/* @0x2a50b8 bge 0x2a50d0 <zip_open+0x2f0> */
/* @0x2a50ba str.w r10, [r4, #0x4] */
/* @0x2a50bc eor r10, r8, r4 */
/* @0x2a50be b 0x2a5112 <zip_open+0x332> */
/* @0x2a50c0 movs r6, r2 */
/* @0x2a50c2 movs r1, r0 */
/* @0x2a50c4 strb r5, [r1, #0x7] */
/* @0x2a50c6 movs r6, r1 */
/* @0x2a50c8 strb r0, [r5, #0x3] */
/* @0x2a50ca movs r6, r1 */
/* @0x2a50cc add r1, sp, #0xb8 */
/* @0x2a50ce movs r6, r1 */
/* @0x2a50d0 ldr r3, [r4, #0x4] */
/* @0x2a50d2 add.w r10, r10, #0x1 */
/* @0x2a50d4 ldrmi r0, [r10, #0xa01] */
/* @0x2a50d6 cmp r10, r3 */
/* @0x2a50d8 blt 0x2a5088 <zip_open+0x2a8> */
/* @0x2a50da cbz r4, 0x2a512e <zip_open+0x34e> */
/* @0x2a50dc cmp.w r8, #0x0 */
/* @0x2a50e0 beq 0x2a511a <zip_open+0x33a> */
/* @0x2a50e2 ldr r3, [sp, #0x8] */
/* @0x2a50e4 cmp r3, #0x0 */
/* @0x2a50e6 bgt 0x2a50f4 <zip_open+0x314> */
/* @0x2a50e8 mov r0, r6 */
/* @0x2a50ea mov r1, r8 */
/* @0x2a50ec mov r2, r7 */
/* @0x2a50ee bl 0x2a4cfe <zip_name_locate+0x2a6> */
/* @0x2a50f0 andls pc, r2, r6, lsl #28 */
/* @0x2a50f2 str r0, [sp, #0x8] */
/* @0x2a50f4 mov r2, r7 */
/* @0x2a50f6 mov r0, r6 */
/* @0x2a50f8 mov r1, r4 */
/* @0x2a50fa bl 0x2a4cfe <zip_name_locate+0x2a6> */
/* @0x2a50fc bls 0x364904 <_ZTS12CDS_Priority+0x695c> */
/* @0x2a50fe ldr r2, [sp, #0x8] */
/* @0x2a5100 cmp r2, r0 */
/* @0x2a5102 mov r9, r0 */
/* @0x2a5104 bge 0x2a5112 <zip_open+0x332> */
/* @0x2a5106 mov r0, r8 */
/* @0x2a5108 bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir> */
/* @0x2a510c str.w r9, [sp, #0x8] */
/* @0x2a5110 b 0x2a5136 <zip_open+0x356> */
/* @0x2a5112 mov r0, r4 */
/* @0x2a5114 bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir> */
/* @0x2a5118 b 0x2a512e <zip_open+0x34e> */
/* @0x2a511a ldr r3, [sp, #0x10] */
/* @0x2a511c lsls r3, r3, #0x1d */
/* @0x2a511e bpl 0x2a5132 <zip_open+0x352> */
/* @0x2a5120 mov r0, r6 */
/* @0x2a5122 mov r1, r4 */
/* @0x2a5124 mov r2, r7 */
/* @0x2a5126 bl 0x2a4cfe <zip_name_locate+0x2a6> */
/* @0x2a5128 andls pc, r2, r10, ror #27 */
/* @0x2a512a str r0, [sp, #0x8] */
/* @0x2a512c b 0x2a5136 <zip_open+0x356> */
/* @0x2a512e mov r4, r8 */
/* @0x2a5130 b 0x2a5136 <zip_open+0x356> */
/* @0x2a5132 str.w r8, [sp, #0x8] */
/* @0x2a5134 strtmi r8, [r0], r8 */
/* @0x2a5136 mov r8, r4 */
/* @0x2a5138 b 0x2a4f30 <zip_open+0x150> */
/* @0x2a513a mov r0, r11 */
/* @0x2a513c blx 0xb655c <free@plt> */
/* @0x2a5140 ldr r2, [sp, #0x8] */
/* @0x2a5142 cmp r2, #0x0 */
/* @0x2a5144 bge.w 0x2a4e84 <zip_open+0xa4> */
/* @0x2a5148 mov r0, r5 */
/* @0x2a514a mov r1, r7 */
/* @0x2a514c mov r2, r9 */
/* @0x2a514e bl 0x2a4a60 <zip_name_locate+0x8> */
/* @0x2a5150 strbmi pc, [r0], -r7, lsl #25 */
/* @0x2a5152 mov r0, r8 */
/* @0x2a5154 bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir> */
/* @0x2a5158 b 0x2a4ec4 <zip_open+0xe4> */
/* @0x2a515a str.w r8, [r0, #0x20] */
/* @0x2a515c subvs r8, r6, r0, lsr #32 */
/* @0x2a515e str r6, [r0, #0x4] */
/* @0x2a5160 movs r0, #0x14 */
/* @0x2a5162 ldr.w r3, [r8, #0x4] */
/* @0x2a5164 cmpmi r8, #4 */
/* @0x2a5166 muls r0, r3, r0 */
/* @0x2a5168 blx 0xb6544 <malloc@plt> */
/* @0x2a516c str r0, [r4, #0x34] */
/* @0x2a516e cbnz r0, 0x2a517e <zip_open+0x39e> */
/* @0x2a5170 cbz r5, 0x2a5176 <zip_open+0x396> */
/* @0x2a5172 movs r3, #0xe */
/* @0x2a5174 str r3, [r5] */
/* @0x2a5176 mov r0, r4 */
/* @0x2a5178 bl 0x2a4884 <_Z9_zip_freeP3zip> */
/* @0x2a517c b 0x2a4eca <zip_open+0xea> */
/* @0x2a517e ldr.w r3, [r8, #0x4] */
/* @0x2a5180 strtmi r3, [r0], -r4 */
/* @0x2a5182 mov r0, r4 */
/* @0x2a5184 cmp r9, r3 */
/* @0x2a5186 bge.w 0x2a4ea8 <zip_open+0xc8> */
/* @0x2a5188 .word 0xf000ae8f */
/* @0x2a518a bl 0x2a5790 <_Z14_zip_entry_newP3zip> */
/* @0x2a518c .word 0xf109fb01 */
/* @0x2a518e add.w r9, r9, #0x1 */
/* @0x2a5190 ldrb r0, [r4, r1, lsl #18]! */
/* @0x2a5192 b 0x2a517e <zip_open+0x39e> */
/* @0x2a5194 mov r0, r7 */
/* @0x2a5196 movs r1, #0x13 */
/* @0x2a5198 b 0x2a506e <zip_open+0x28e> */
/* @0x2a519a add sp, #0xa4 */
/* @0x2a519c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2a51a0 · zip_open_buff · size=728 · insn=330 */
/* @0x2a51a0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a51a4 sub sp, #0x4c */
/* @0x2a51a6 mov r6, r0 */
/* @0x2a51a8 str r2, [sp, #0xc] */
/* @0x2a51aa ldr r2, [r0, #0x20] */
/* @0x2a51ac str r1, [sp, #0x24] */
/* @0x2a51ae cbnz r2, 0x2a51c4 <zip_open_buff+0x24> */
/* @0x2a51b0 ldr r0, [pc, #0x2a0] */
/* @0x2a51b2 ldr r1, [sp, #0xc] */
/* @0x2a51b4 add r0, pc */
/* @0x2a51b6 bl 0x2a4cba <zip_name_locate+0x262> */
/* @0x2a51b8 stmdahs r0, {r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2a51ba cmp r0, #0x0 */
/* @0x2a51bc beq.w 0x2a5472 <zip_open_buff+0x2d2> */
/* @0x2a51c0 str r6, [r0, #0x8] */
/* @0x2a51c2 b 0x2a5472 <zip_open_buff+0x2d2> */
/* @0x2a51c4 ldr r3, [r0] */
/* @0x2a51c6 movs r1, #0x2 */
/* @0x2a51c8 ldr r4, [pc, #0x284] */
/* @0x2a51ca ldr r3, [r3, #0x10] */
/* @0x2a51cc cmp r2, r4 */
/* @0x2a51ce it ge */
/* @0x2a51d0 movge r2, r4 */
/* @0x2a51d2 blx r3 */
/* @0x2a51d4 mov r0, r4 */
/* @0x2a51d6 blx 0xb6544 <malloc@plt> */
/* @0x2a51d8 selmi lr, r1, r6 */
/* @0x2a51da mov r9, r0 */
/* @0x2a51dc cbnz r0, 0x2a51ec <zip_open_buff+0x4c> */
/* @0x2a51de ldr r2, [sp, #0xc] */
/* @0x2a51e0 cmp r2, #0x0 */
/* @0x2a51e2 beq.w 0x2a5470 <zip_open_buff+0x2d0> */
/* @0x2a51e4 movwhs r8, #0xe145 */
/* @0x2a51e6 movs r3, #0xe */
/* @0x2a51e8 str r3, [r2] */
/* @0x2a51ea b 0x2a5470 <zip_open_buff+0x2d0> */
/* @0x2a51ec mov r3, r4 */
/* @0x2a51ee mov r1, r9 */
/* @0x2a51f0 movs r2, #0x1 */
/* @0x2a51f2 mov r0, r6 */
/* @0x2a51f4 blx 0xcdc9c <_ZN7IBuffer4ReadEPKvjj> */
/* @0x2a51f8 add r5, sp, #0x3c */
/* @0x2a51fa movs r2, #0x0 */
/* @0x2a51fc movs r1, #0x13 */
/* @0x2a51fe mov.w r8, #0xffffffff */
/* @0x2a5200 strhs r3, [r0], #-2303 */
/* @0x2a5202 movs r4, #0x0 */
/* @0x2a5204 str r0, [sp, #0x1c] */
/* @0x2a5206 mov r0, r5 */
/* @0x2a5208 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a520c ldr r3, [pc, #0x248] */
/* @0x2a520e ldr r2, [pc, #0x24c] */
/* @0x2a5210 add r3, pc */
/* @0x2a5212 str.w r9, [sp, #0x18] */
/* @0x2a5214 movwls r9, #0xa018 */
/* @0x2a5216 str r3, [sp, #0x28] */
/* @0x2a5218 add r2, pc */
/* @0x2a521a add r3, sp, #0x34 */
/* @0x2a521c str r2, [sp, #0x2c] */
/* @0x2a521e str r3, [sp, #0x10] */
/* @0x2a5220 ldr r3, [sp, #0x18] */
/* @0x2a5222 ldr r2, [sp, #0x1c] */
/* @0x2a5224 rsb r1, r3, r9 */
/* @0x2a5228 add r1, r2 */
/* @0x2a522a mov r0, r3 */
/* @0x2a522c subs r1, #0x12 */
/* @0x2a522e bl 0x2a4b48 <zip_name_locate+0xf0> */
/* @0x2a5230 strmi pc, [r7], -r11, lsl #25 */
/* @0x2a5232 mov r7, r0 */
/* @0x2a5234 cmp r0, #0x0 */
/* @0x2a5236 beq.w 0x2a53e2 <zip_open_buff+0x242> */
/* @0x2a5238 blls 0x485590 <mstack+0x8a4> */
/* @0x2a523a ldr r3, [sp, #0x1c] */
/* @0x2a523c adds r2, r7, #0x1 */
/* @0x2a523e str r2, [sp, #0x18] */
/* @0x2a5240 add r3, r9 */
/* @0x2a5242 subs r3, r3, r7 */
/* @0x2a5244 subs r3, #0x16 */
/* @0x2a5246 str r3, [sp, #0x20] */
/* @0x2a5248 bpl 0x2a5252 <zip_open_buff+0xb2> */
/* @0x2a524a mov r0, r5 */
/* @0x2a524c movs r1, #0x13 */
/* @0x2a524e movs r2, #0x0 */
/* @0x2a5250 b 0x2a5274 <zip_open_buff+0xd4> */
/* @0x2a5252 ldr r1, [sp, #0x28] */
/* @0x2a5254 movs r2, #0x4 */
/* @0x2a5256 blx 0xb6c40 <memcmp@plt> */
/* @0x2a5258 .word 0x4683ecf4 */
/* @0x2a525a mov r11, r0 */
/* @0x2a525c cmp r0, #0x0 */
/* @0x2a525e bne 0x2a524a <zip_open_buff+0xaa> */
/* @0x2a5260 adds r0, r7, #0x4 */
/* @0x2a5262 ldr r1, [sp, #0x2c] */
/* @0x2a5264 movs r2, #0x4 */
/* @0x2a5266 blx 0xb6c40 <memcmp@plt> */
/* @0x2a5268 andls lr, r5, r12, ror #25 */
/* @0x2a526a str r0, [sp, #0x14] */
/* @0x2a526c cbz r0, 0x2a527a <zip_open_buff+0xda> */
/* @0x2a526e mov r0, r5 */
/* @0x2a5270 movs r1, #0x1 */
/* @0x2a5272 mov r2, r11 */
/* @0x2a5274 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a5278 b 0x2a53d8 <zip_open_buff+0x238> */
/* @0x2a527a add r0, sp, #0x34 */
/* @0x2a527c add.w r3, r7, #0x8 */
/* @0x2a5280 str r3, [sp, #0x34] */
/* @0x2a5282 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a5284 pkhbtmi pc, r3, sp, lsl #28 */
/* @0x2a5286 mov r11, r0 */
/* @0x2a5288 add r0, sp, #0x34 */
/* @0x2a528a bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a528c qadd16mi pc, r9, r9 */
/* @0x2a528e mov r1, r5 */
/* @0x2a5290 bl 0x2a3b88 <_Z13_zip_cdir_newiP9zip_error> */
/* @0x2a5294 mov r10, r0 */
/* @0x2a5296 cmp r0, #0x0 */
/* @0x2a5298 beq.w 0x2a53d8 <zip_open_buff+0x238> */
/* @0x2a529c add r0, sp, #0x34 */
/* @0x2a529e bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a52a0 .word 0xf8cafe18 */
/* @0x2a52a2 str.w r0, [r10, #0x8] */
/* @0x2a52a4 stmdage sp, {r3} */
/* @0x2a52a6 add r0, sp, #0x34 */
/* @0x2a52a8 bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a52ac ldr r3, [sp, #0x14] */
/* @0x2a52ae str.w r3, [r10, #0x10] */
/* @0x2a52b0 .word 0xf8ca3010 */
/* @0x2a52b2 str.w r0, [r10, #0xc] */
/* @0x2a52b4 stmdage sp, {r2, r3} */
/* @0x2a52b6 add r0, sp, #0x34 */
/* @0x2a52b8 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a52bc ldr r3, [sp, #0x20] */
/* @0x2a52be cmp r3, r0 */
/* @0x2a52c0 mov r1, r0 */
/* @0x2a52c2 strh.w r0, [r10, #0x14] */
/* @0x2a52c4 blle 0x36531c <_ZTS12CDS_Priority+0x7374> */
/* @0x2a52c6 blt 0x2a52d0 <zip_open_buff+0x130> */
/* @0x2a52c8 ldr.w r3, [r10, #0x4] */
/* @0x2a52cc cmp r3, r11 */
/* @0x2a52ce beq 0x2a52d8 <zip_open_buff+0x138> */
/* @0x2a52d0 mov r0, r5 */
/* @0x2a52d2 movs r1, #0x13 */
/* @0x2a52d4 movs r2, #0x0 */
/* @0x2a52d6 b 0x2a52ea <zip_open_buff+0x14a> */
/* @0x2a52d8 ldr r2, [sp, #0x24] */
/* @0x2a52da lsls r2, r2, #0x1d */
/* @0x2a52dc bpl 0x2a52f0 <zip_open_buff+0x150> */
/* @0x2a52de ldr r3, [sp, #0x20] */
/* @0x2a52e0 cmp r3, r0 */
/* @0x2a52e2 beq 0x2a52f0 <zip_open_buff+0x150> */
/* @0x2a52e4 ldr r2, [sp, #0x14] */
/* @0x2a52e6 mov r0, r5 */
/* @0x2a52e8 movs r1, #0x15 */
/* @0x2a52ea bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a52ec and pc, r8, r5, lsr r8 */
/* @0x2a52ee b 0x2a5302 <zip_open_buff+0x162> */
/* @0x2a52f0 cbz r1, 0x2a530a <zip_open_buff+0x16a> */
/* @0x2a52f2 add.w r0, r7, #0x16 */
/* @0x2a52f4 qadd16mi r0, r10, r6 */
/* @0x2a52f6 mov r2, r5 */
/* @0x2a52f8 bl 0x2a4978 <_Z11_zip_memdupPKvjP9zip_error> */
/* @0x2a52fc str.w r0, [r10, #0x10] */
/* @0x2a5300 cbnz r0, 0x2a530a <zip_open_buff+0x16a> */
/* @0x2a5302 mov r0, r10 */
/* @0x2a5304 blx 0xb655c <free@plt> */
/* @0x2a5308 b 0x2a53d8 <zip_open_buff+0x238> */
/* @0x2a530a ldr.w r3, [r10, #0x8] */
/* @0x2a530c bl 0xff4f1334 <b2_toiTime+0xfffffffffed97e90> */
/* @0x2a530e rsb r2, r9, r7 */
/* @0x2a5310 addsmi r0, r3, #1879048192 */
/* @0x2a5312 cmp r3, r2 */
/* @0x2a5314 bhs 0x2a5320 <zip_open_buff+0x180> */
/* @0x2a5316 subs r7, r7, r3 */
/* @0x2a5318 add r2, sp, #0x34 */
/* @0x2a531a str r7, [sp, #0x34] */
/* @0x2a531c str r2, [sp, #0x14] */
/* @0x2a531e b 0x2a5332 <zip_open_buff+0x192> */
/* @0x2a5320 ldr r3, [r6] */
/* @0x2a5322 mov r0, r6 */
/* @0x2a5324 movs r1, #0x0 */
/* @0x2a5326 ldr.w r2, [r10, #0xc] */
/* @0x2a5328 ldmdbvs r11, {r2, r3, sp} */
/* @0x2a532a ldr r3, [r3, #0x10] */
/* @0x2a532c blx r3 */
/* @0x2a532e movs r3, #0x0 */
/* @0x2a5330 str r3, [sp, #0x14] */
/* @0x2a5332 ldr.w r3, [r10, #0x8] */
/* @0x2a5334 svcge #0x123008 */
/* @0x2a5336 add r7, sp, #0x48 */
/* @0x2a5338 mov.w r11, #0x0 */
/* @0x2a533c str r3, [r7, #-16]! */
/* @0x2a5340 ldr.w r3, [r10, #0x4] */
/* @0x2a5344 cmp r11, r3 */
/* @0x2a5346 bne 0x2a5358 <zip_open_buff+0x1b8> */
/* @0x2a5348 ldr r3, [sp, #0x38] */
/* @0x2a534a cbz r3, 0x2a5358 <zip_open_buff+0x1b8> */
/* @0x2a534c mov r0, r10 */
/* @0x2a534e add.w r1, r11, #0x10000 */
/* @0x2a5350 strtmi r3, [r10], -r0, lsl #3 */
/* @0x2a5352 mov r2, r5 */
/* @0x2a5354 bl 0x2a3b4e <_Z14_zip_cdir_growP8zip_cdiriP9zip_error> */
/* @0x2a5358 ldr.w r0, [r10] */
/* @0x2a535c movs r3, #0x3c */
/* @0x2a535e movs r2, #0x0 */
/* @0x2a5360 mov r1, r6 */
/* @0x2a5362 stm.w sp, {r2, r5} */
/* @0x2a5364 blx 0x3653fe <_ZTS12CDS_Priority+0x7456> */
/* @0x2a5366 mla r0, r3, r11, r0 */
/* @0x2a5368 bls 0x3e539c <error_g0017+0x3e040> */
/* @0x2a536a ldr r2, [sp, #0x14] */
/* @0x2a536c mov r3, r7 */
/* @0x2a536e bl 0x2a4108 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error> */
/* @0x2a5370 stmdahs r0, {r0, r1, r3, r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a5372 cmp r0, #0x0 */
/* @0x2a5374 bge 0x2a537c <zip_open_buff+0x1dc> */
/* @0x2a5376 str.w r11, [r10, #0x4] */
/* @0x2a5378 ands r11, pc, r4 */
/* @0x2a537a b 0x2a53bc <zip_open_buff+0x21c> */
/* @0x2a537c ldr.w r3, [r10, #0x4] */
/* @0x2a5380 add.w r11, r11, #0x1 */
/* @0x2a5384 cmp r11, r3 */
/* @0x2a5386 blt 0x2a5340 <zip_open_buff+0x1a0> */
/* @0x2a5388 cmp.w r10, #0x0 */
/* @0x2a538c beq 0x2a53d8 <zip_open_buff+0x238> */
/* @0x2a538e cbz r4, 0x2a53c4 <zip_open_buff+0x224> */
/* @0x2a5390 cmp.w r8, #0x0 */
/* @0x2a5394 bgt 0x2a53a2 <zip_open_buff+0x202> */
/* @0x2a5396 mov r0, r6 */
/* @0x2a5398 mov r1, r4 */
/* @0x2a539a mov r2, r5 */
/* @0x2a539c bl 0x2a4bda <zip_name_locate+0x182> */
/* @0x2a53a0 mov r8, r0 */
/* @0x2a53a2 mov r0, r6 */
/* @0x2a53a4 mov r1, r10 */
/* @0x2a53a6 mov r2, r5 */
/* @0x2a53a8 bl 0x2a4bda <zip_name_locate+0x182> */
/* @0x2a53ac cmp r8, r0 */
/* @0x2a53ae mov r7, r0 */
/* @0x2a53b0 bge 0x2a53bc <zip_open_buff+0x21c> */
/* @0x2a53b2 mov r0, r4 */
/* @0x2a53b4 mov r8, r7 */
/* @0x2a53b6 bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir> */
/* @0x2a53b8 ands pc, r0, lr, lsl r12 */
/* @0x2a53ba b 0x2a53de <zip_open_buff+0x23e> */
/* @0x2a53bc mov r0, r10 */
/* @0x2a53be bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir> */
/* @0x2a53c0 and pc, r9, r10, lsl r12 */
/* @0x2a53c2 b 0x2a53d8 <zip_open_buff+0x238> */
/* @0x2a53c4 ldr r2, [sp, #0x24] */
/* @0x2a53c6 lsls r3, r2, #0x1d */
/* @0x2a53c8 bpl 0x2a53dc <zip_open_buff+0x23c> */
/* @0x2a53ca mov r0, r6 */
/* @0x2a53cc mov r1, r10 */
/* @0x2a53ce mov r2, r5 */
/* @0x2a53d0 bl 0x2a4bda <zip_name_locate+0x182> */
/* @0x2a53d4 mov r8, r0 */
/* @0x2a53d6 b 0x2a53de <zip_open_buff+0x23e> */
/* @0x2a53d8 mov r10, r4 */
/* @0x2a53da b 0x2a53de <zip_open_buff+0x23e> */
/* @0x2a53dc mov r8, r4 */
/* @0x2a53de mov r4, r10 */
/* @0x2a53e0 b 0x2a5220 <zip_open_buff+0x80> */
/* @0x2a53e2 mov r0, r9 */
/* @0x2a53e4 blx 0xb655c <free@plt> */
/* @0x2a53e8 cmp.w r8, #0x0 */
/* @0x2a53ec bge 0x2a5400 <zip_open_buff+0x260> */
/* @0x2a53ee ldr r0, [sp, #0xc] */
/* @0x2a53f0 mov r1, r5 */
/* @0x2a53f2 mov r2, r7 */
/* @0x2a53f4 bl 0x2a4a60 <zip_name_locate+0x8> */
/* @0x2a53f8 mov r0, r4 */
/* @0x2a53fa bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir> */
/* @0x2a53fc ldrsht pc, [r7], -r12 */
/* @0x2a53fe b 0x2a5470 <zip_open_buff+0x2d0> */
/* @0x2a5400 cmp r4, #0x0 */
/* @0x2a5402 beq 0x2a5470 <zip_open_buff+0x2d0> */
/* @0x2a5404 ldr r0, [pc, #0x58] */
/* @0x2a5406 ldr r1, [sp, #0xc] */
/* @0x2a5408 add r0, pc */
/* @0x2a540a bl 0x2a4cba <zip_name_locate+0x262> */
/* @0x2a540c .word 0x4605fc56 */
/* @0x2a540e mov r5, r0 */
/* @0x2a5410 cbnz r0, 0x2a541a <zip_open_buff+0x27a> */
/* @0x2a5412 mov r0, r4 */
/* @0x2a5414 bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir> */
/* @0x2a5418 b 0x2a546c <zip_open_buff+0x2cc> */
/* @0x2a541a str r4, [r0, #0x20] */
/* @0x2a541c str r7, [r0, #0x4] */
/* @0x2a541e str r6, [r0, #0x8] */
/* @0x2a5420 movs r0, #0x14 */
/* @0x2a5422 ldr r3, [r4, #0x4] */
/* @0x2a5424 muls r0, r3, r0 */
/* @0x2a5426 blx 0xb6544 <malloc@plt> */
/* @0x2a5428 .word 0x6368e88e */
/* @0x2a542a str r0, [r5, #0x34] */
/* @0x2a542c cbnz r0, 0x2a5440 <zip_open_buff+0x2a0> */
/* @0x2a542e ldr r3, [sp, #0xc] */
/* @0x2a5430 cbz r3, 0x2a5438 <zip_open_buff+0x298> */
/* @0x2a5432 ldr r2, [sp, #0xc] */
/* @0x2a5434 movs r3, #0xe */
/* @0x2a5436 str r3, [r2] */
/* @0x2a5438 mov r0, r5 */
/* @0x2a543a bl 0x2a4884 <_Z9_zip_freeP3zip> */
/* @0x2a543c ands pc, r7, r3, lsr #20 */
/* @0x2a543e b 0x2a5470 <zip_open_buff+0x2d0> */
/* @0x2a5440 ldr r3, [r4, #0x4] */
/* @0x2a5442 mov r0, r5 */
/* @0x2a5444 cmp r7, r3 */
/* @0x2a5446 bge 0x2a5464 <zip_open_buff+0x2c4> */
/* @0x2a5448 bl 0x2a5790 <_Z14_zip_entry_newP3zip> */
/* @0x2a544c adds r7, #0x1 */
/* @0x2a544e b 0x2a5440 <zip_open_buff+0x2a0> */
/* @0x2a5450 movs r6, r2 */
/* @0x2a5452 movs r1, r0 */
/* @0x2a5454 ldr r0, [r5, #0x64] */
/* @0x2a5456 movs r6, r1 */
/* @0x2a5458 ldr r0, [r7, #0x5c] */
/* @0x2a545a movs r6, r1 */
/* @0x2a545c adr r6, #248 <zip_open_buff+0x2fe> */
/* @0x2a545e movs r6, r1 */
/* @0x2a5460 ldr r4, [r2, #0x40] */
/* @0x2a5462 movs r6, r1 */
/* @0x2a5464 bl 0x2a4a90 <zip_name_locate+0x38> */
/* @0x2a5468 ldr r3, [r5, #0x18] */
/* @0x2a546a str r3, [r5, #0x1c] */
/* @0x2a546c mov r0, r5 */
/* @0x2a546e b 0x2a5472 <zip_open_buff+0x2d2> */
/* @0x2a5470 movs r0, #0x0 */
/* @0x2a5472 add sp, #0x4c */
/* @0x2a5474 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2a5478 · anon_2a5478 · size=224 · insn=57 */
/* @0x2a5478 mvnsmi lr, sp, lsr #18 */
/* @0x2a547c ldmdami r6!, {r2, r9, r10, lr} */
/* @0x2a5480 stcpl p5, c15, [r0, #-692] */
/* @0x2a5484 ldrbtmi r11, [r8], #-130 */
/* @0x2a5488 .word 0xf50d6800 */
/* @0x2a548c strlo r5, [r4], -r0, lsl #12 */
/* @0x2a5490 eorsvs r6, r5, r5, lsl #16 */
/* @0x2a5494 blhs 0x3f6cb4 <g_MP3UpdateVolume+0x19d8> */
/* @0x2a5498 ldm pc, {r0, r2, r3, r6, r11, r12, lr, pc} ^ */
/* @0x2a549c cdpne p0, #0x0, c15, c3, c3, #0x0 */
/* @0x2a54a0 ldrtmi r3, [r12], #-74 */
/* @0x2a54a4 stmdaeq r4, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x2a54a8 vrshl.s8 d18, d0, d2 */
/* @0x2a54ac bvs 0xb270b8 <b2_toiTime+0x3cdc14> */
/* @0x2a54b0 ble 0x1235f0c <b2_toiTime+0xadca68> */
/* @0x2a54b4 stmdavs r0!, {r1, r4, r6, r8, r9, r11, r12} */
/* @0x2a54b8 svclt #0x2842ba */
/* @0x2a54bc andpl pc, r0, #1325400064 */
/* @0x2a54c0 .word 0xf7ff4641 */
/* @0x2a54c4 stmdahs r0, {r0, r1, r4, r6, r8, r11, r12, sp, lr, pc} */
/* @0x2a54c8 stmdavs r0!, {r0, r2, r9, r11, r12, lr, pc} */
/* @0x2a54cc .word 0xff5cf7fe */
/* @0x2a54d0 eorvs r2, r3, r0, lsl #6 */
/* @0x2a54d4 strmi lr, [r5], #-47 */
/* @0x2a54d8 bvs 0x1b9f484 <b2_toiTime+0x1445fe0> */
/* @0x2a54dc andle r1, r1, r8, asr r12 */
/* @0x2a54e0 stmdale r0, {r1, r3, r4, r7, r9, lr} */
/* @0x2a54e4 stmdavs r0!, {r0, r1, r4, r9, r10, lr} */
/* @0x2a54e8 .word 0xf7ff461a */
/* @0x2a54ec stmdahs r0, {r0, r1, r2, r3, r4, r5, r8, r11, r12, sp, lr, pc} */
/* @0x2a54f0 bvs 0x1b9c17c <b2_toiTime+0x1442cd8> */
/* @0x2a54f4 eorle r1, r0, r10, asr r12 */
/* @0x2a54f8 rsbvs r1, r3, #110592 */
/* @0x2a54fc bhs 0x9dd578 <b2_toiTime+0x2840d4> */
/* @0x2a5500 stcne p3, c13, [r3, #-100]! */
/* @0x2a5504 .word 0xf8533420 */
/* @0x2a5508 adcmi r2, r3, #4, #22 */
/* @0x2a550c blhs 0x3e3618 <error_g0017+0x3c2bc> */
/* @0x2a5510 ldrshhs sp, [r12], -r9 */
/* @0x2a5514 bhs 0x49d560 <TimingData+0x3548> */
/* @0x2a5518 stmdavs r0!, {r0, r2, r3, r8, r11, r12, lr, pc} */
/* @0x2a551c .word 0xf0001d0a */
/* @0x2a5520 andhs pc, r8, r3, ror #19 */
/* @0x2a5524 stmdavs r0!, {r0, r3, sp, lr, pc} */
/* @0x2a5528 .word 0xff2ef7fe */
/* @0x2a552c .word 0xf6114620 */
/* @0x2a5530 andhs lr, r0, r6, lsl r8 */
/* @0x2a5534 .word 0xf04fe001 */
/* @0x2a5538 .word 0xf50d30ff */
/* @0x2a553c movwlo r5, #0x4300 */
/* @0x2a5540 ldmdavs r3!, {r1, r3, r4, r11, sp, lr} */
/* @0x2a5544 mulle r1, r10, r2 */
/* @0x2a5548 stmda r4, {r0, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a554c stcpl p5, c15, [r0, #-52] */
/* @0x2a5550 pop {r1, r12, sp, pc} */
/* @0x2a5554 svclt #0x81f0 */
/* @0x2a5558 andseq r8, r4, lr, asr #9 */

/* ── FUNC 0x2a555c · zip_source_zip · size=276 · insn=121 */
/* @0x2a555c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a5560 sub sp, #0x14 */
/* @0x2a5562 mov r7, r1 */
/* @0x2a5564 mov r9, r2 */
/* @0x2a5566 ldr r5, [sp, #0x3c] */
/* @0x2a5568 mov r6, r0 */
/* @0x2a556a cmp r0, #0x0 */
/* @0x2a556c beq 0x2a5648 <zip_source_zip+0xec> */
/* @0x2a556e cbz r1, 0x2a5586 <zip_source_zip+0x2a> */
/* @0x2a5570 ldr r2, [sp, #0x38] */
/* @0x2a5572 cmp r2, #0x0 */
/* @0x2a5574 blt 0x2a5586 <zip_source_zip+0x2a> */
/* @0x2a5576 adds r0, r5, #0x1 */
/* @0x2a5578 blt 0x2a5586 <zip_source_zip+0x2a> */
/* @0x2a557a cmp.w r9, #0x0 */
/* @0x2a557c blle 0x329184 */
/* @0x2a557e blt 0x2a5586 <zip_source_zip+0x2a> */
/* @0x2a5580 ldr r2, [r1, #0x2c] */
/* @0x2a5582 cmp r9, r2 */
/* @0x2a5584 blt 0x2a5594 <zip_source_zip+0x38> */
/* @0x2a5586 add.w r0, r6, #0xc */
/* @0x2a5588 tsths r2, r12 */
/* @0x2a558a movs r1, #0x12 */
/* @0x2a558c movs r2, #0x0 */
/* @0x2a558e bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a5590 rsb pc, r7, r3, ror #29 */
/* @0x2a5592 b 0x2a5664 <zip_source_zip+0x108> */
/* @0x2a5594 ands r4, r3, #0x8 */
/* @0x2a5598 bne 0x2a55b2 <zip_source_zip+0x56> */
/* @0x2a559a ldr r2, [r1, #0x34] */
/* @0x2a559c movs r1, #0x14 */
/* @0x2a559e mul r1, r1, r9 */
/* @0x2a55a0 ldmdapl r2, {r0, r3, r8, r12, sp, lr, pc} ^ */
/* @0x2a55a2 ldr r2, [r2, r1] */
/* @0x2a55a4 subs r2, #0x2 */
/* @0x2a55a6 cmp r2, #0x1 */
/* @0x2a55a8 bhi 0x2a55b2 <zip_source_zip+0x56> */
/* @0x2a55aa add.w r0, r6, #0xc */
/* @0x2a55ac mrshs r0, apsr */
/* @0x2a55ae movs r1, #0xf */
/* @0x2a55b0 b 0x2a55e6 <zip_source_zip+0x8a> */
/* @0x2a55b2 ldr r2, [sp, #0x38] */
/* @0x2a55b4 cbz r5, 0x2a55ca <zip_source_zip+0x6e> */
/* @0x2a55b6 cbnz r2, 0x2a55d2 <zip_source_zip+0x76> */
/* @0x2a55b8 adds r1, r5, #0x1 */
/* @0x2a55ba bne 0x2a55d2 <zip_source_zip+0x76> */
/* @0x2a55bc lsls r2, r3, #0x1b */
/* @0x2a55be bmi 0x2a55ce <zip_source_zip+0x72> */
/* @0x2a55c0 orr r8, r3, #0x4 */
/* @0x2a55c4 mov.w r5, #0xffffffff */
/* @0x2a55c8 b 0x2a55d6 <zip_source_zip+0x7a> */
/* @0x2a55ca cmp r2, #0x0 */
/* @0x2a55cc beq 0x2a55bc <zip_source_zip+0x60> */
/* @0x2a55ce mov.w r5, #0xffffffff */
/* @0x2a55d0 .word 0xf02335ff */
/* @0x2a55d2 bic r8, r3, #0x4 */
/* @0x2a55d4 eorhs r0, r8, r4, lsl #16 */
/* @0x2a55d6 movs r0, #0x28 */
/* @0x2a55d8 blx 0xb6544 <malloc@plt> */
/* @0x2a55dc mov r4, r0 */
/* @0x2a55de cbnz r0, 0x2a55f0 <zip_source_zip+0x94> */
/* @0x2a55e0 add.w r0, r6, #0xc */
/* @0x2a55e4 movs r1, #0xe */
/* @0x2a55e6 mov r2, r4 */
/* @0x2a55e8 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a55ec mov r0, r4 */
/* @0x2a55ee b 0x2a5666 <zip_source_zip+0x10a> */
/* @0x2a55f0 add.w r10, r7, #0xc */
/* @0x2a55f4 add.w r11, sp, #0x4 */
/* @0x2a55f8 mov r1, r10 */
/* @0x2a55fa mov r0, r11 */
/* @0x2a55fc bl 0x2a4314 <_Z15_zip_error_copyP9zip_errorS0_> */
/* @0x2a5600 mov r0, r7 */
/* @0x2a5602 mov r1, r9 */
/* @0x2a5604 mov r2, r8 */
/* @0x2a5606 adds r3, r4, #0x4 */
/* @0x2a5608 bl 0x2a5694 <zip_stat_index> */
/* @0x2a560c cmp r0, #0x0 */
/* @0x2a560e blt 0x2a564c <zip_source_zip+0xf0> */
/* @0x2a5610 mov r0, r7 */
/* @0x2a5612 mov r1, r9 */
/* @0x2a5614 mov r2, r8 */
/* @0x2a5616 bl 0x2a4584 <zip_fopen_index> */
/* @0x2a5618 .word 0x6020ffb5 */
/* @0x2a561a str r0, [r4] */
/* @0x2a561c cbz r0, 0x2a564c <zip_source_zip+0xf0> */
/* @0x2a561e ldr r3, [sp, #0x38] */
/* @0x2a5620 str r5, [r4, #0x24] */
/* @0x2a5622 str r3, [r4, #0x20] */
/* @0x2a5624 ands r3, r8, #0x4 */
/* @0x2a5628 bne 0x2a5632 <zip_source_zip+0xd6> */
/* @0x2a562a str r5, [r4, #0x18] */
/* @0x2a562c str r5, [r4, #0x14] */
/* @0x2a562e strh r3, [r4, #0x1c] */
/* @0x2a5630 str r3, [r4, #0xc] */
/* @0x2a5632 ldr r1, [pc, #0x38] */
/* @0x2a5634 mov r0, r6 */
/* @0x2a5636 mov r2, r4 */
/* @0x2a5638 add r1, pc */
/* @0x2a563a bl 0x2a59ca <zip_source_function> */
/* @0x2a563c strmi pc, [r6], -r6, asr #19 */
/* @0x2a563e mov r6, r0 */
/* @0x2a5640 cbnz r0, 0x2a5648 <zip_source_zip+0xec> */
/* @0x2a5642 mov r0, r4 */
/* @0x2a5644 blx 0xb655c <free@plt> */
/* @0x2a5648 mov r0, r6 */
/* @0x2a564a b 0x2a5666 <zip_source_zip+0x10a> */
/* @0x2a564c mov r0, r4 */
/* @0x2a564e blx 0xb655c <free@plt> */
/* @0x2a5650 .word 0xf106ef86 */
/* @0x2a5652 add.w r0, r6, #0xc */
/* @0x2a5654 ldrbmi r0, [r1], -r12 */
/* @0x2a5656 mov r1, r10 */
/* @0x2a5658 bl 0x2a4314 <_Z15_zip_error_copyP9zip_errorS0_> */
/* @0x2a565c mov r0, r10 */
/* @0x2a565e mov r1, r11 */
/* @0x2a5660 bl 0x2a4314 <_Z15_zip_error_copyP9zip_errorS0_> */
/* @0x2a5664 movs r0, #0x0 */
/* @0x2a5666 add sp, #0x14 */
/* @0x2a5668 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a566c mrc2 p15, #0x1, apsr_nzcv, c13, c15, #0x7 */

/* ── FUNC 0x2a5670 · zip_stat · size=36 · insn=17 */
/* @0x2a5670 push {r4, r5, r6, lr} */
/* @0x2a5672 mov r5, r0 */
/* @0x2a5674 mov r4, r2 */
/* @0x2a5676 mov r6, r3 */
/* @0x2a5678 bl 0x2a4a58 <zip_name_locate> */
/* @0x2a567c subs r1, r0, #0x0 */
/* @0x2a567e blt 0x2a568e <zip_stat+0x1e> */
/* @0x2a5680 mov r0, r5 */
/* @0x2a5682 mov r2, r4 */
/* @0x2a5684 mov r3, r6 */
/* @0x2a5686 pop.w {r4, r5, r6, lr} */
/* @0x2a5688 .word 0xf0004070 */
/* @0x2a568a b.w 0x2a5694 <zip_stat_index> */
/* @0x2a568c .word 0xf04fb803 */
/* @0x2a568e mov.w r0, #0xffffffff */
/* @0x2a5690 ldcllt p0, c3, [r0, #-1020]! */
/* @0x2a5692 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a5694 · zip_stat_index · size=208 · insn=97 */
/* @0x2a5694 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2a5698 subs r6, r1, #0x0 */
/* @0x2a569a mov r5, r0 */
/* @0x2a569c mov r8, r2 */
/* @0x2a569e mov r4, r3 */
/* @0x2a56a0 bge 0x2a56ac <zip_stat_index+0x18> */
/* @0x2a56a2 add.w r0, r5, #0xc */
/* @0x2a56a4 tsths r2, r12 */
/* @0x2a56a6 movs r1, #0x12 */
/* @0x2a56a8 movs r2, #0x0 */
/* @0x2a56aa b 0x2a56ee <zip_stat_index+0x5a> */
/* @0x2a56ac ldr r3, [r0, #0x2c] */
/* @0x2a56ae cmp r6, r3 */
/* @0x2a56b0 bge 0x2a56a2 <zip_stat_index+0xe> */
/* @0x2a56b2 bl 0x2a4970 <zip_get_name> */
/* @0x2a56b4 .word 0x4607f95d */
/* @0x2a56b6 mov r7, r0 */
/* @0x2a56b8 cmp r0, #0x0 */
/* @0x2a56ba beq 0x2a575c <zip_stat_index+0xc8> */
/* @0x2a56bc ands r8, r8, #0x8 */
/* @0x2a56c0 bne 0x2a56f4 <zip_stat_index+0x60> */
/* @0x2a56c2 movs r3, #0x14 */
/* @0x2a56c4 ldr r1, [r5, #0x34] */
/* @0x2a56c6 muls r3, r6, r3 */
/* @0x2a56c8 adds r2, r1, r3 */
/* @0x2a56ca ldr r3, [r1, r3] */
/* @0x2a56cc subs r3, #0x2 */
/* @0x2a56ce cmp r3, #0x1 */
/* @0x2a56d0 bhi 0x2a56f4 <zip_stat_index+0x60> */
/* @0x2a56d2 ldr r3, [r2, #0x4] */
/* @0x2a56d4 mov r1, r4 */
/* @0x2a56d6 movs r2, #0x1c */
/* @0x2a56d8 ldr.w r12, [r3] */
/* @0x2a56dc ldr r0, [r3, #0x4] */
/* @0x2a56de movs r3, #0x3 */
/* @0x2a56e0 blx r12 */
/* @0x2a56e2 cmp r0, #0x0 */
/* @0x2a56e4 bge 0x2a5752 <zip_stat_index+0xbe> */
/* @0x2a56e6 add.w r0, r5, #0xc */
/* @0x2a56e8 mrshs r0, apsr */
/* @0x2a56ea movs r1, #0xf */
/* @0x2a56ec mov r2, r8 */
/* @0x2a56ee bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a56f0 eors pc, r3, r3, lsr lr */
/* @0x2a56f2 b 0x2a575c <zip_stat_index+0xc8> */
/* @0x2a56f4 ldr r2, [r5, #0x20] */
/* @0x2a56f6 cmp r2, #0x0 */
/* @0x2a56f8 beq 0x2a56a2 <zip_stat_index+0xe> */
/* @0x2a56fa ldr r3, [r2, #0x4] */
/* @0x2a56fc cmp r6, r3 */
/* @0x2a56fe bge 0x2a56a2 <zip_stat_index+0xe> */
/* @0x2a5700 movs r3, #0x3c */
/* @0x2a5702 ldr r2, [r2] */
/* @0x2a5704 muls r3, r6, r3 */
/* @0x2a5706 add r2, r3 */
/* @0x2a5708 ldr r2, [r2, #0xc] */
/* @0x2a570a str r2, [r4, #0x8] */
/* @0x2a570c ldr r2, [r5, #0x20] */
/* @0x2a570e ldr r2, [r2] */
/* @0x2a5710 add r2, r3 */
/* @0x2a5712 ldr r2, [r2, #0x14] */
/* @0x2a5714 str r2, [r4, #0x10] */
/* @0x2a5716 ldr r2, [r5, #0x20] */
/* @0x2a5718 ldr r2, [r2] */
/* @0x2a571a add r2, r3 */
/* @0x2a571c ldr r2, [r2, #0x8] */
/* @0x2a571e str r2, [r4, #0xc] */
/* @0x2a5720 ldr r2, [r5, #0x20] */
/* @0x2a5722 ldr r2, [r2] */
/* @0x2a5724 add r2, r3 */
/* @0x2a5726 ldr r2, [r2, #0x10] */
/* @0x2a5728 str r2, [r4, #0x14] */
/* @0x2a572a ldr r2, [r5, #0x20] */
/* @0x2a572c ldr r2, [r2] */
/* @0x2a572e add r2, r3 */
/* @0x2a5730 ldrh r2, [r2, #0x6] */
/* @0x2a5732 strh r2, [r4, #0x18] */
/* @0x2a5734 ldr r2, [r5, #0x20] */
/* @0x2a5736 ldr r2, [r2] */
/* @0x2a5738 add r3, r2 */
/* @0x2a573a ldrh r3, [r3, #0x4] */
/* @0x2a573c ands r2, r3, #0x1 */
/* @0x2a5740 beq 0x2a5750 <zip_stat_index+0xbc> */
/* @0x2a5742 lsls r3, r3, #0x19 */
/* @0x2a5744 ite mi */
/* @0x2a5746 movwmi r3, #0xffff */
/* @0x2a5748 movwhs r7, #0x13ff */
/* @0x2a574a movpl r3, #0x1 */
/* @0x2a574c strh r3, [r4, #0x1a] */
/* @0x2a574e b 0x2a5752 <zip_stat_index+0xbe> */
/* @0x2a5750 strh r2, [r4, #0x1a] */
/* @0x2a5752 str r6, [r4, #0x4] */
/* @0x2a5754 movs r0, #0x0 */
/* @0x2a5756 str r7, [r4] */
/* @0x2a5758 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2a575c mov.w r0, #0xffffffff */
/* @0x2a5760 pop.w {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2a5764 · zip_strerror · size=6 · insn=3 */
/* @0x2a5764 adds r0, #0xc */
/* @0x2a5766 b.w 0x2a57f8 <_Z19_zip_error_strerrorP9zip_error> */
/* @0x2a5768 ldrlt r11, [r8, #-0x847]! */

/* ── FUNC 0x2a576a · _zip_entry_free(zip_entry*) · size=38 · insn=16 */
/* @0x2a576a push {r3, r4, r5, lr} */
/* @0x2a576c mov r4, r0 */
/* @0x2a576e ldr r0, [r0, #0x8] */
/* @0x2a5770 movs r5, #0x0 */
/* @0x2a5772 blx 0xb655c <free@plt> */
/* @0x2a5776 ldr r0, [r4, #0xc] */
/* @0x2a5778 str r5, [r4, #0x8] */
/* @0x2a577a blx 0xb655c <free@plt> */
/* @0x2a577e mov.w r3, #0xffffffff */
/* @0x2a5782 str r5, [r4, #0xc] */
/* @0x2a5784 mov r0, r4 */
/* @0x2a5786 str r3, [r4, #0x10] */
/* @0x2a5788 pop.w {r3, r4, r5, lr} */
/* @0x2a578a .word 0xf0004038 */
/* @0x2a578c b.w 0x2a59f6 <_Z18_zip_unchange_dataP9zip_entry> */
/* @0x2a578e ldrlt r11, [r8, #-0x933]! */

/* ── FUNC 0x2a5790 · _zip_entry_new(zip*) · size=102 · insn=48 */
/* @0x2a5790 push {r3, r4, r5, lr} */
/* @0x2a5792 mov r4, r0 */
/* @0x2a5794 cbnz r0, 0x2a57a4 <_Z14_zip_entry_newP3zip+0x14> */
/* @0x2a5796 movs r0, #0x14 */
/* @0x2a5798 blx 0xb6544 <malloc@plt> */
/* @0x2a579c mov r5, r0 */
/* @0x2a579e movs r0, #0xc */
/* @0x2a57a0 cbnz r5, 0x2a57da <_Z14_zip_entry_newP3zip+0x4a> */
/* @0x2a57a2 b 0x2a57c6 <_Z14_zip_entry_newP3zip+0x36> */
/* @0x2a57a4 ldr r3, [r0, #0x30] */
/* @0x2a57a6 ldr r2, [r0, #0x2c] */
/* @0x2a57a8 subs r1, r3, #0x1 */
/* @0x2a57aa cmp r2, r1 */
/* @0x2a57ac blt 0x2a57d0 <_Z14_zip_entry_newP3zip+0x40> */
/* @0x2a57ae adds r3, #0x10 */
/* @0x2a57b0 movs r1, #0x14 */
/* @0x2a57b2 str r3, [r0, #0x30] */
/* @0x2a57b4 muls r1, r3, r1 */
/* @0x2a57b6 ldr r0, [r0, #0x34] */
/* @0x2a57b8 blx 0xb6c28 <realloc@plt> */
/* @0x2a57bc mov r5, r0 */
/* @0x2a57be str r0, [r4, #0x34] */
/* @0x2a57c0 cbnz r0, 0x2a57d0 <_Z14_zip_entry_newP3zip+0x40> */
/* @0x2a57c2 add.w r0, r4, #0xc */
/* @0x2a57c4 .word 0x210e000c */
/* @0x2a57c6 movs r1, #0xe */
/* @0x2a57c8 mov r2, r5 */
/* @0x2a57ca bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a57cc ands pc, r0, r5, asr #27 */
/* @0x2a57ce b 0x2a57f2 <_Z14_zip_entry_newP3zip+0x62> */
/* @0x2a57d0 ldr r2, [r4, #0x2c] */
/* @0x2a57d2 movs r5, #0x14 */
/* @0x2a57d4 ldr r3, [r4, #0x34] */
/* @0x2a57d6 mla r5, r5, r2, r3 */
/* @0x2a57d8 movwhs r3, #0x502 */
/* @0x2a57da movs r3, #0x0 */
/* @0x2a57dc mov.w r2, #0xffffffff */
/* @0x2a57e0 str r3, [r5] */
/* @0x2a57e2 str r3, [r5, #0x8] */
/* @0x2a57e4 str r3, [r5, #0xc] */
/* @0x2a57e6 str r2, [r5, #0x10] */
/* @0x2a57e8 str r3, [r5, #0x4] */
/* @0x2a57ea cbz r4, 0x2a57f2 <_Z14_zip_entry_newP3zip+0x62> */
/* @0x2a57ec ldr r3, [r4, #0x2c] */
/* @0x2a57ee adds r3, #0x1 */
/* @0x2a57f0 str r3, [r4, #0x2c] */
/* @0x2a57f2 mov r0, r5 */
/* @0x2a57f4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2a57f8 · _zip_error_strerror(zip_error*) · size=240 · insn=108 */
/* @0x2a57f8 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2a57fc sub sp, #0x94 */
/* @0x2a57fe ldr r5, [pc, #0xc4] */
/* @0x2a5800 mov r7, r0 */
/* @0x2a5802 ldr r3, [pc, #0xc4] */
/* @0x2a5804 add r5, pc */
/* @0x2a5806 ldr r4, [r5, r3] */
/* @0x2a5808 ldr r3, [r4] */
/* @0x2a580a mov r9, r4 */
/* @0x2a580c str r3, [sp, #0x8c] */
/* @0x2a580e bl 0x2a431e <_Z15_zip_error_finiP9zip_error> */
/* @0x2a5810 ldmdavs r10!, {r1, r2, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2a5812 ldr r2, [r7] */
/* @0x2a5814 cmp r2, #0x0 */
/* @0x2a5816 blt 0x2a5822 <_Z19_zip_error_strerrorP9zip_error+0x2a> */
/* @0x2a5818 ldr r3, [pc, #0xb0] */
/* @0x2a581a ldr r3, [r5, r3] */
/* @0x2a581c ldr r3, [r3] */
/* @0x2a581e cmp r2, r3 */
/* @0x2a5820 blt 0x2a5832 <_Z19_zip_error_strerrorP9zip_error+0x3a> */
/* @0x2a5822 add r6, sp, #0xc */
/* @0x2a5824 ldr r1, [pc, #0xa8] */
/* @0x2a5826 movs r4, #0x0 */
/* @0x2a5828 mov r0, r6 */
/* @0x2a582a add r1, pc */
/* @0x2a582c blx 0xb6550 <sprintf@plt> */
/* @0x2a5830 b 0x2a585c <_Z19_zip_error_strerrorP9zip_error+0x64> */
/* @0x2a5832 ldr r3, [pc, #0xa0] */
/* @0x2a5834 ldr r3, [r5, r3] */
/* @0x2a5836 ldr.w r4, [r3, r2, lsl #2] */
/* @0x2a5838 blmi 0xc758c8 <b2_toiTime+0x51c424> */
/* @0x2a583a ldr r3, [pc, #0x9c] */
/* @0x2a583c ldr r3, [r5, r3] */
/* @0x2a583e ldr.w r3, [r3, r2, lsl #2] */
/* @0x2a5840 blhs 0x2f18d0 <ps_hints_apply+0x4d0> */
/* @0x2a5842 cmp r3, #0x1 */
/* @0x2a5844 beq 0x2a5852 <_Z19_zip_error_strerrorP9zip_error+0x5a> */
/* @0x2a5846 cmp r3, #0x2 */
/* @0x2a5848 bne 0x2a58ac <_Z19_zip_error_strerrorP9zip_error+0xb4> */
/* @0x2a584a ldr r0, [r7, #0x4] */
/* @0x2a584c blx 0xb6f28 <zError@plt> */
/* @0x2a5850 b 0x2a5858 <_Z19_zip_error_strerrorP9zip_error+0x60> */
/* @0x2a5852 ldr r0, [r7, #0x4] */
/* @0x2a5854 blx 0xb6f34 <strerror@plt> */
/* @0x2a5858 mov r6, r0 */
/* @0x2a585a cbz r0, 0x2a58ac <_Z19_zip_error_strerrorP9zip_error+0xb4> */
/* @0x2a585c mov r0, r6 */
/* @0x2a585e blx 0xb6538 <strlen@plt> */
/* @0x2a5860 strmi lr, [r0], r12, ror #28 */
/* @0x2a5862 mov r8, r0 */
/* @0x2a5864 cbz r4, 0x2a5870 <_Z19_zip_error_strerrorP9zip_error+0x78> */
/* @0x2a5866 mov r0, r4 */
/* @0x2a5868 blx 0xb6538 <strlen@plt> */
/* @0x2a586c adds r3, r0, #0x2 */
/* @0x2a586e b 0x2a5872 <_Z19_zip_error_strerrorP9zip_error+0x7a> */
/* @0x2a5870 mov r3, r4 */
/* @0x2a5872 add.w r0, r8, #0x1 */
/* @0x2a5874 ldrmi r0, [r8], #-1 */
/* @0x2a5876 add r0, r3 */
/* @0x2a5878 blx 0xb6544 <malloc@plt> */
/* @0x2a587c mov r8, r0 */
/* @0x2a587e cbnz r0, 0x2a5888 <_Z19_zip_error_strerrorP9zip_error+0x90> */
/* @0x2a5880 ldr r3, [pc, #0x50] */
/* @0x2a5882 ldr r3, [r5, r3] */
/* @0x2a5884 ldr r0, [r3, #0x38] */
/* @0x2a5886 b 0x2a58ae <_Z19_zip_error_strerrorP9zip_error+0xb6> */
/* @0x2a5888 cbnz r4, 0x2a5892 <_Z19_zip_error_strerrorP9zip_error+0x9a> */
/* @0x2a588a ldr r2, [pc, #0x50] */
/* @0x2a588c add r2, pc */
/* @0x2a588e mov r3, r2 */
/* @0x2a5890 b 0x2a5898 <_Z19_zip_error_strerrorP9zip_error+0xa0> */
/* @0x2a5892 ldr r3, [pc, #0x4c] */
/* @0x2a5894 mov r2, r4 */
/* @0x2a5896 add r3, pc */
/* @0x2a5898 ldr r1, [pc, #0x48] */
/* @0x2a589a mov r0, r8 */
/* @0x2a589c str r6, [sp] */
/* @0x2a589e add r1, pc */
/* @0x2a58a0 blx 0xb6550 <sprintf@plt> */
/* @0x2a58a4 str.w r8, [r7, #0x8] */
/* @0x2a58a8 mov r0, r8 */
/* @0x2a58aa b 0x2a58ae <_Z19_zip_error_strerrorP9zip_error+0xb6> */
/* @0x2a58ac mov r0, r4 */
/* @0x2a58ae ldr r2, [sp, #0x8c] */
/* @0x2a58b0 ldr.w r3, [r9] */
/* @0x2a58b4 cmp r2, r3 */
/* @0x2a58b6 beq 0x2a58bc <_Z19_zip_error_strerrorP9zip_error+0xc4> */
/* @0x2a58b8 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2a58bc add sp, #0x94 */
/* @0x2a58be pop.w {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2a58c0 svclt #0x83f0 */
/* @0x2a58c2 nop */
/* @0x2a58c4 stm r4!, {r4, r6} */
/* @0x2a58c6 movs r4, r2 */
/* @0x2a58c8 pop {pc} */
/* @0x2a58ca vcvt.f32.u32 d31, d16, #0x1 */
/* @0x2a58cc .word 0xfffffe30 */
/* @0x2a58ce .word 0xffff 69d8 */
/* @0x2a58d0 ldrdeq r6, r7, [lr], -r8 */
/* @0x2a58d2 movs r6, r1 */
/* @0x2a58d4 mcr2 p15, #0x2, pc, c0, c15, #0x7 */
/* @0x2a58d8 mrc2 p15, #0x1, apsr_nzcv, c4, c15, #0x7 */
/* @0x2a58dc ldr r5, [r6, #0x14] */
/* @0x2a58de movs r6, r1 */
/* @0x2a58e0 ldr r0, [r5, #0x14] */
/* @0x2a58e2 movs r6, r1 */
/* @0x2a58e4 ldr r5, [r6, #0x14] */
/* @0x2a58e6 movs r6, r1 */

/* ── FUNC 0x2a58e8 · zip_file_error_get · size=6 · insn=3 */
/* @0x2a58e8 adds r0, #0x4 */
/* @0x2a58ea b.w 0x2a432e <_Z14_zip_error_getP9zip_errorPiS1_> */
/* @0x2a58ec ldrblt r11, [r0, #0xd20]! */

/* ── FUNC 0x2a58ee · _zip_file_get_offset(zip*, int) · size=144 · insn=66 */
/* @0x2a58ee push {r4, r5, r6, r7, lr} */
/* @0x2a58f0 movs r2, #0x3c */
/* @0x2a58f2 ldr r3, [r0, #0x20] */
/* @0x2a58f4 sub sp, #0x4c */
/* @0x2a58f6 ldr r5, [r0, #0x4] */
/* @0x2a58f8 mov r4, r0 */
/* @0x2a58fa add.w r7, r0, #0xc */
/* @0x2a58fe ldr r3, [r3] */
/* @0x2a5900 mla r1, r2, r1, r3 */
/* @0x2a5902 blvs 0xfe631d0e <b2_toiTime+0xfffffffffded886a> */
/* @0x2a5904 ldr r6, [r1, #0x38] */
/* @0x2a5906 cbz r5, 0x2a593c <_Z20_zip_file_get_offsetP3zipi+0x4e> */
/* @0x2a5908 mov r0, r5 */
/* @0x2a590a mov r1, r6 */
/* @0x2a590c movs r2, #0x0 */
/* @0x2a590e blx 0xb6ed4 <fseeko@plt> */
/* @0x2a5912 mov r5, r0 */
/* @0x2a5914 cbz r0, 0x2a5928 <_Z20_zip_file_get_offsetP3zipi+0x3a> */
/* @0x2a5916 blx 0xb6bf8 <__errno@plt> */
/* @0x2a591a movs r1, #0x4 */
/* @0x2a591c ldr r2, [r0] */
/* @0x2a591e mov r0, r7 */
/* @0x2a5920 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a5922 andhs pc, r0, r10, lsl sp */
/* @0x2a5924 movs r0, #0x0 */
/* @0x2a5926 b 0x2a597a <_Z20_zip_file_get_offsetP3zipi+0x8c> */
/* @0x2a5928 movs r3, #0x1 */
/* @0x2a592a add r0, sp, #0xc */
/* @0x2a592c stm.w sp, {r3, r7} */
/* @0x2a592e strtmi r0, [r10], -r8, lsl #1 */
/* @0x2a5930 mov r2, r5 */
/* @0x2a5932 ldr r1, [r4, #0x4] */
/* @0x2a5934 mov r3, r5 */
/* @0x2a5936 bl 0x2a3ef0 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error> */
/* @0x2a593a b 0x2a5962 <_Z20_zip_file_get_offsetP3zipi+0x74> */
/* @0x2a593c ldr r0, [r0, #0x8] */
/* @0x2a593e mov r1, r5 */
/* @0x2a5940 mov r2, r6 */
/* @0x2a5942 ldr r3, [r0] */
/* @0x2a5944 ldr r3, [r3, #0x10] */
/* @0x2a5946 blx r3 */
/* @0x2a5948 ldr r1, [r4, #0x8] */
/* @0x2a594a add r0, sp, #0xc */
/* @0x2a594c ldr r2, [r1, #0xc] */
/* @0x2a594e ldr r3, [r1, #0x1c] */
/* @0x2a5950 add r3, r2 */
/* @0x2a5952 add r2, sp, #0x8 */
/* @0x2a5954 str r3, [sp, #0x8] */
/* @0x2a5956 movs r3, #0x1 */
/* @0x2a5958 stm.w sp, {r3, r7} */
/* @0x2a595a strtmi r0, [r11], -r8, lsl #1 */
/* @0x2a595c mov r3, r5 */
/* @0x2a595e bl 0x2a4108 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error> */
/* @0x2a5962 cbnz r0, 0x2a5978 <_Z20_zip_file_get_offsetP3zipi+0x8a> */
/* @0x2a5964 ldrh.w r5, [sp, #0x28] */
/* @0x2a5966 stmdage r3, {r3, r5, r12, lr} */
/* @0x2a5968 add r0, sp, #0xc */
/* @0x2a596a ldrh.w r3, [sp, #0x30] */
/* @0x2a596e adds r5, #0x1e */
/* @0x2a5970 add r5, r3 */
/* @0x2a5972 add r5, r6 */
/* @0x2a5974 bl 0x2a3bd6 <_Z20_zip_dirent_finalizeP10zip_dirent> */
/* @0x2a5976 strtmi pc, [r8], -pc, lsr #18 */
/* @0x2a5978 mov r0, r5 */
/* @0x2a597a add sp, #0x4c */
/* @0x2a597c pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2a597e · _zip_new(zip_error*) · size=76 · insn=37 */
/* @0x2a597e push {r3, r4, r5, lr} */
/* @0x2a5980 mov r5, r0 */
/* @0x2a5982 movs r0, #0x44 */
/* @0x2a5984 blx 0xb6544 <malloc@plt> */
/* @0x2a5986 .word 0x4604edde */
/* @0x2a5988 mov r4, r0 */
/* @0x2a598a cbnz r0, 0x2a5998 <_Z8_zip_newP9zip_error+0x1a> */
/* @0x2a598c mov r0, r5 */
/* @0x2a598e movs r1, #0xe */
/* @0x2a5990 mov r2, r4 */
/* @0x2a5992 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a5996 b 0x2a59c6 <_Z8_zip_newP9zip_error+0x48> */
/* @0x2a5998 movs r5, #0x0 */
/* @0x2a599a adds r0, #0xc */
/* @0x2a599c str r5, [r0, #-12] */
/* @0x2a599e .word 0xf8405c0c */
/* @0x2a59a0 str r5, [r0, #-8] */
/* @0x2a59a2 .word 0xf8405c08 */
/* @0x2a59a4 str r5, [r0, #-4] */
/* @0x2a59a6 .word 0xf7fe5c04 */
/* @0x2a59a8 bl 0x2a434e <_Z15_zip_error_initP9zip_error> */
/* @0x2a59aa .word 0xf04ffcd1 */
/* @0x2a59ac mov.w r3, #0xffffffff */
/* @0x2a59ae eorvs r3, r5, #-67108861 */
/* @0x2a59b0 str r5, [r4, #0x20] */
/* @0x2a59b2 str r5, [r4, #0x24] */
/* @0x2a59b4 str r3, [r4, #0x28] */
/* @0x2a59b6 str r5, [r4, #0x30] */
/* @0x2a59b8 str r5, [r4, #0x2c] */
/* @0x2a59ba str r5, [r4, #0x34] */
/* @0x2a59bc str r5, [r4, #0x3c] */
/* @0x2a59be str r5, [r4, #0x38] */
/* @0x2a59c0 str r5, [r4, #0x40] */
/* @0x2a59c2 str r5, [r4, #0x1c] */
/* @0x2a59c4 str r5, [r4, #0x18] */
/* @0x2a59c6 mov r0, r4 */
/* @0x2a59c8 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2a59ca · zip_source_function · size=44 · insn=19 */
/* @0x2a59ca push {r3, r4, r5, r6, r7, lr} */
/* @0x2a59cc mov r6, r1 */
/* @0x2a59ce mov r7, r2 */
/* @0x2a59d0 mov r5, r0 */
/* @0x2a59d2 cbz r0, 0x2a59f4 <zip_source_function+0x2a> */
/* @0x2a59d4 movs r0, #0x8 */
/* @0x2a59d6 blx 0xb6544 <malloc@plt> */
/* @0x2a59da mov r4, r0 */
/* @0x2a59dc cbnz r0, 0x2a59ec <zip_source_function+0x22> */
/* @0x2a59de add.w r0, r5, #0xc */
/* @0x2a59e2 movs r1, #0xe */
/* @0x2a59e4 mov r2, r4 */
/* @0x2a59e6 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a59ea b 0x2a59f0 <zip_source_function+0x26> */
/* @0x2a59ec stm.w r0, {r6, r7} */
/* @0x2a59ee strtmi r0, [r0], -r0, asr #1 */
/* @0x2a59f0 mov r0, r4 */
/* @0x2a59f2 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2a59f4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2a59f6 · _zip_unchange_data(zip_entry*) · size=44 · insn=22 */
/* @0x2a59f6 push {r3, r4, r5, lr} */
/* @0x2a59f8 mov r4, r0 */
/* @0x2a59fa ldr r3, [r0, #0x4] */
/* @0x2a59fc cbz r3, 0x2a5a14 <_Z18_zip_unchange_dataP9zip_entry+0x1e> */
/* @0x2a59fe movs r1, #0x0 */
/* @0x2a5a00 ldr r5, [r3] */
/* @0x2a5a02 ldr r0, [r3, #0x4] */
/* @0x2a5a04 mov r2, r1 */
/* @0x2a5a06 movs r3, #0x5 */
/* @0x2a5a08 blx r5 */
/* @0x2a5a0a ldr r0, [r4, #0x4] */
/* @0x2a5a0c blx 0xb655c <free@plt> */
/* @0x2a5a0e movwhs lr, #0xda6 */
/* @0x2a5a10 movs r3, #0x0 */
/* @0x2a5a12 str r3, [r4, #0x4] */
/* @0x2a5a14 ldr r3, [r4, #0x8] */
/* @0x2a5a16 cmp r3, #0x0 */
/* @0x2a5a18 ite ne */
/* @0x2a5a1a movne r3, #0x4 */
/* @0x2a5a1c moveq r3, #0x0 */
/* @0x2a5a1e str r3, [r4] */
/* @0x2a5a20 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2a5a22 · anon_2a5a22 · size=0 · insn=1 */
/* @0x2a5a22 ldrlt r0, [r8, #-0x0]! */

/* ── FUNC 0x2a5a24 · png_set_sig_bytes · size=40 · insn=18 */
/* @0x2a5a24 push {r3, r4, r5, lr} */
/* @0x2a5a26 mov r5, r0 */
/* @0x2a5a28 cbz r0, 0x2a5a44 <png_set_sig_bytes+0x20> */
/* @0x2a5a2a cmp r1, #0x0 */
/* @0x2a5a2c blt 0x2a5a3e <png_set_sig_bytes+0x1a> */
/* @0x2a5a2e cmp r1, #0x8 */
/* @0x2a5a30 mov r4, r1 */
/* @0x2a5a32 bls 0x2a5a40 <png_set_sig_bytes+0x1c> */
/* @0x2a5a34 ldr r1, [pc, #0x10] */
/* @0x2a5a36 add r1, pc */
/* @0x2a5a38 bl 0x2a642c <png_error> */
/* @0x2a5a3c b 0x2a5a40 <png_set_sig_bytes+0x1c> */
/* @0x2a5a3e movs r4, #0x0 */
/* @0x2a5a40 strb.w r4, [r5, #0x1f0] */
/* @0x2a5a44 pop {r3, r4, r5, pc} */
/* @0x2a5a46 nop */
/* @0x2a5a48 str r4, [r4, #0x7c] */
/* @0x2a5a4a movs r6, r1 */

/* ── FUNC 0x2a5a4c · png_sig_cmp · size=92 · insn=43 */
/* @0x2a5a4c push {r0, r1, r2, r3, r4, r5, r6, lr} */
/* @0x2a5a4e mov r3, r1 */
/* @0x2a5a50 ldr r4, [pc, #0x4c] */
/* @0x2a5a52 mov r6, r0 */
/* @0x2a5a54 add r5, sp, #0x4 */
/* @0x2a5a56 cmp r2, #0x8 */
/* @0x2a5a58 add r4, pc */
/* @0x2a5a5a ldr r4, [r4] */
/* @0x2a5a5c ldr r1, [r4] */
/* @0x2a5a5e str r1, [sp, #0xc] */
/* @0x2a5a60 ldr r1, [pc, #0x40] */
/* @0x2a5a62 add r1, pc */
/* @0x2a5a64 ldr r0, [r1] */
/* @0x2a5a66 ldr r1, [r1, #0x4] */
/* @0x2a5a68 stm r5!, {r0, r1} */
/* @0x2a5a6a bhi 0x2a5a70 <png_sig_cmp+0x24> */
/* @0x2a5a6c cbnz r2, 0x2a5a72 <png_sig_cmp+0x26> */
/* @0x2a5a6e b 0x2a5a8c <png_sig_cmp+0x40> */
/* @0x2a5a70 movs r2, #0x8 */
/* @0x2a5a72 cmp r3, #0x7 */
/* @0x2a5a74 bhi 0x2a5a8c <png_sig_cmp+0x40> */
/* @0x2a5a76 adds r1, r2, r3 */
/* @0x2a5a78 adds r0, r6, r3 */
/* @0x2a5a7a cmp r1, #0x8 */
/* @0x2a5a7c add r1, sp, #0x4 */
/* @0x2a5a7e it hi */
/* @0x2a5a80 rsbhi.w r2, r3, #0x8 */
/* @0x2a5a84 add r1, r3 */
/* @0x2a5a86 blx 0xb6c40 <memcmp@plt> */
/* @0x2a5a88 ldrd lr, pc, [r1], -r12 */
/* @0x2a5a8a b 0x2a5a90 <png_sig_cmp+0x44> */
/* @0x2a5a8c mov.w r0, #0xffffffff */
/* @0x2a5a90 ldr r2, [sp, #0xc] */
/* @0x2a5a92 ldr r3, [r4] */
/* @0x2a5a94 cmp r2, r3 */
/* @0x2a5a96 beq 0x2a5a9c <png_sig_cmp+0x50> */
/* @0x2a5a98 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2a5a9c add sp, #0x10 */
/* @0x2a5a9e pop {r4, r5, r6, pc} */
/* @0x2a5aa0 ldrb r4, [r7, #0x1b] */
/* @0x2a5aa2 movs r4, r2 */
/* @0x2a5aa4 ldr r6, [sp, #0x178] */
/* @0x2a5aa6 movs r6, r1 */

/* ── FUNC 0x2a5aa8 · png_zalloc · size=72 · insn=30 */
/* @0x2a5aa8 push {r3, r4, r5, r6, r7, lr} */
/* @0x2a5aaa mov r6, r1 */
/* @0x2a5aac mov r7, r2 */
/* @0x2a5aae mov r4, r0 */
/* @0x2a5ab0 cbz r0, 0x2a5ace <png_zalloc+0x26> */
/* @0x2a5ab2 ldr.w r5, [r0, #0x130] */
/* @0x2a5ab4 sasxmi r5, r1, r0 */
/* @0x2a5ab6 mov r1, r2 */
/* @0x2a5ab8 mov.w r0, #0xffffffff */
/* @0x2a5abc blx 0x318c48 <__udivsi3> */
/* @0x2a5ac0 cmp r6, r0 */
/* @0x2a5ac2 bls 0x2a5ad2 <png_zalloc+0x2a> */
/* @0x2a5ac4 ldr r1, [pc, #0x24] */
/* @0x2a5ac6 mov r0, r4 */
/* @0x2a5ac8 add r1, pc */
/* @0x2a5aca bl 0x2a6474 <png_warning> */
/* @0x2a5acc .word 0x2000fcd3 */
/* @0x2a5ace movs r0, #0x0 */
/* @0x2a5ad0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2a5ad2 orr r3, r5, #0x100000 */
/* @0x2a5ad4 strtmi r1, [r0], -r0, lsl #7 */
/* @0x2a5ad6 mov r0, r4 */
/* @0x2a5ad8 str.w r3, [r4, #0x130] */
/* @0x2a5adc mul r1, r6, r7 */
/* @0x2a5ae0 bl 0x2a6ca0 <png_malloc> */
/* @0x2a5ae4 str.w r5, [r4, #0x130] */
/* @0x2a5ae8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2a5aea nop */
/* @0x2a5aec str r3, [r6, #0x74] */
/* @0x2a5aee movs r6, r1 */

/* ── FUNC 0x2a5af0 · png_zfree · size=4 · insn=1 */
/* @0x2a5af0 b.w 0x2a6cfc <png_free> */

/* ── FUNC 0x2a5af4 · png_reset_crc · size=20 · insn=10 */
/* @0x2a5af4 push {r4, lr} */
/* @0x2a5af6 mov r4, r0 */
/* @0x2a5af8 movs r0, #0x0 */
/* @0x2a5afa mov r1, r0 */
/* @0x2a5afc mov r2, r0 */
/* @0x2a5afe blx 0xb6ea4 <crc32@plt> */
/* @0x2a5b00 .word 0xf8c4e9d2 */
/* @0x2a5b02 str.w r0, [r4, #0x1d4] */
/* @0x2a5b04 ldclt p1, c0, [r0, #-848] */
/* @0x2a5b06 pop {r4, pc} */
