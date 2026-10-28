/* libyoyo.so 覆盖卡组 0251
 * 函数 0x2a4358..0x2a57f9，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a4358 · anon_2a4358 · size=384 · insn=96 */
/* @0x2a4358 stm r0, {r3, r8, r12, sp, pc} */
/* @0x2a435c ldrbmi r0, [r0, -r6]! */
/* @0x2a4360 blle 0x56e368 <g_SWFlineaavertbuff+0x1b2a0> */
/* @0x2a4364 ldrbtmi r4, [r11], #-2822 */
/* @0x2a4368 ldmdavs r11, {r0, r1, r3, r4, r11, sp, lr} */
/* @0x2a436c ble 0x3f4dd4 <PS_Common+0x160> */
/* @0x2a4370 ldrbtmi r4, [r11], #-2820 */
/* @0x2a4374 .word 0xf853681b */
/* @0x2a4378 ldrbmi r0, [r0, -r0, lsr #32]! */
/* @0x2a437c ldrbmi r2, [r0, -r0]! */
/* @0x2a4380 andseq sp, r4, lr, lsl r7 */
/* @0x2a4384 andseq sp, r4, r6, lsl r7 */
/* @0x2a4388 .word 0x4604b570 */
/* @0x2a438c .word 0xb1086b00 */
/* @0x2a4390 bl 0xd61be0 <b2_toiTime+0x60873c> */
/* @0x2a4394 .word 0xf6126ae0 */
/* @0x2a4398 blvs 0xade728 <b2_toiTime+0x385284> */
/* @0x2a439c ldm lr, {r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a43a0 movwhs r6, #0x820 */
/* @0x2a43a4 addmi r6, r11, #132096 */
/* @0x2a43a8 .word 0x6c02da13 */
/* @0x2a43ac streq lr, [r3], r2, lsl #22 */
/* @0x2a43b0 eorpl pc, r3, r2, asr r8 */
/* @0x2a43b4 smlatble r10, r5, r2, r4 */
/* @0x2a43b8 orrmi pc, r0, #1073741824 */
/* @0x2a43bc .word 0xf8523b01 */
/* @0x2a43c0 eorsvs r3, r3, r3, lsr #32 */
/* @0x2a43c4 blvs 0xfe93e458 <b2_toiTime+0xfffffffffe1e4fb4> */
/* @0x2a43c8 orrsvs r3, r10, #4096 */
/* @0x2a43cc movwlo lr, #0x1001 */
/* @0x2a43d0 stmdavs r5!, {r0, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x2a43d4 stmdbvs r3!, {r0, r2, r4, r6, r8, r11, r12, sp, pc} */
/* @0x2a43d8 movweq pc, #0x5003 */
/* @0x2a43dc .word 0xd1052b05 */
/* @0x2a43e0 bvs 0x1b7ee7c <b2_toiTime+0x14259d8> */
/* @0x2a43e4 svclt #0x14429d */
/* @0x2a43e8 strhs r2, [r0, #-0x507] */
/* @0x2a43ec .word 0xf6124620 */
/* @0x2a43f0 .word 0x4628e8b6 */
/* @0x2a43f4 andeq r11, r0, r0, ror sp */
/* @0x2a43f8 svcmi #0xf0e92d */
/* @0x2a43fc stcpl p5, c15, [r0, #-692] */
/* @0x2a4400 cdpmi p0, #0x2, c11, c12, c3, #0x4 */
/* @0x2a4404 .word 0xf50d4614 */
/* @0x2a4408 ldrbtmi r5, [lr], #-512 */
/* @0x2a440c eorslo r6, r0, #3538944 */
/* @0x2a4410 .word 0xf8d2461f */
/* @0x2a4414 ldmdavs r3!, {r12, pc} */
/* @0x2a4418 andpl pc, r0, #54525952 */
/* @0x2a441c strmi r3, [r0], r4, lsl #4 */
/* @0x2a4420 strmi r2, [sp], -r0 */
/* @0x2a4424 .word 0x46016013 */
/* @0x2a4428 ldrtmi r4, [r3], r2, lsl #12 */
/* @0x2a442c ldc p6, c15, [r10, #-72]! */
/* @0x2a4430 andhs r4, r0, #42991616 */
/* @0x2a4434 .word 0x46406038 */
/* @0x2a4438 stcl p6, c15, [r12, #-72] */
/* @0x2a443c ldmdblt r0, {r0, r2, r9, r10, lr} */
/* @0x2a4440 beq 0x3e087c <error_g0017+0x39520> */
/* @0x2a4444 .word 0xf612e00c */
/* @0x2a4448 ldrdhs lr, pc, [r4, -r8] */
/* @0x2a444c strbmi r6, [r8], -r2, lsl #16 */
/* @0x2a4450 ldmdavs r8!, {r0, r1, r3, r4, sp, lr, pc} */
/* @0x2a4454 shsaxmi r4, r2, r1 */
/* @0x2a4458 .word 0xf6121ba4 */
/* @0x2a445c eorsvs lr, r8, r4, lsr #26 */
/* @0x2a4460 ldcle p12, c2, [r6, #-0] */
/* @0x2a4464 qaddhs r4, r0, r1 */
/* @0x2a4468 svcpl #0xf5b4 */
/* @0x2a446c .word 0x4622bfb4 */
/* @0x2a4470 andpl pc, r0, #1325400064 */
/* @0x2a4474 .word 0xf6124643 */
/* @0x2a4478 strmi lr, [r6], -r8, lsr #20 */
/* @0x2a447c mvnle r2, r0, lsl #16 */
/* @0x2a4480 bl 0xff161cd0 <b2_toiTime+0xfffffffffea0882c> */
/* @0x2a4484 stmdavs r2, {r0, r2, r8, sp} */
/* @0x2a4488 .word 0xf7ff4648 */
/* @0x2a448c .word 0xf04fff65 */
/* @0x2a4490 .word 0xf50d35ff */
/* @0x2a4494 strtmi r5, [r8], -r0, lsl #6 */
/* @0x2a4498 ldmdavs r10, {r2, r8, r9, r12, sp} */
/* @0x2a449c .word 0x3000f8db */
/* @0x2a44a0 mulle r1, r10, r2 */
/* @0x2a44a4 ldm r6, {r1, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a44a8 stcpl p5, c15, [r0, #-52] */
/* @0x2a44ac pop {r0, r1, r12, sp, pc} */
/* @0x2a44b0 svclt #0x8ff0 */
/* @0x2a44b4 andseq r9, r4, r10, asr #10 */
/* @0x2a44b8 .word 0x4605b538 */
/* @0x2a44bc .word 0xf0004614 */
/* @0x2a44c0 vmlsne.f32 s30, s3, s22 */
/* @0x2a44c4 strtmi sp, [r8], -r5, lsl #22 */
/* @0x2a44c8 pop {r1, r5, r9, r10, lr} */
/* @0x2a44cc .word 0xf0004038 */
/* @0x2a44d0 andhs r11, r0, r9, asr r8 */
/* @0x2a44d4 push {r3, r4, r5, r8, r10, r11, r12, sp, pc} */

/* ── FUNC 0x2a4359 · _zip_error_set(zip_error*, int, int) · size=8 · insn=0 */

/* ── FUNC 0x2a4361 · zip_error_get_sys_type · size=40 · insn=0 */

/* ── FUNC 0x2a4389 · zip_fclose · size=110 · insn=0 */

/* ── FUNC 0x2a43f9 · _zip_filerange_crc(__sFILE*, long, long, unsigned long*, zip_error*) · size=192 · insn=0 */

/* ── FUNC 0x2a44b9 · zip_fopen · size=30 · insn=0 */

/* ── FUNC 0x2a44d6 · anon_2a44d6 · size=176 · insn=44 */
/* @0x2a44d6 .word 0x41b8e92d */
/* @0x2a44da ldmdavs r5, {r0, r1, r2, r9, r10, lr} ^ */
/* @0x2a44de ldrmi r4, [r4], -r8, lsl #13 */
/* @0x2a44e2 mrsle r2, spsr */
/* @0x2a44e6 bfieq r6, r3, #18, #10 */
/* @0x2a44ea bvs 0x799612 <b2_toiTime+0x4016e> */
/* @0x2a44ee suble r2, r5, r0, lsl #22 */
/* @0x2a44f2 suble r2, r3, r0, lsl #18 */
/* @0x2a44f6 ldmdavs r8, {r0, r1, r4, r11, sp, lr} ^ */
/* @0x2a44fa ldmibvs r1, {r3, r4, r6, r8, r12, sp, pc} */
/* @0x2a44fe .word 0xf612462a */
/* @0x2a4502 stmdahs r0, {r3, r5, r6, r7, r10, r11, sp, lr, pc} */
/* @0x2a4506 .word 0xf612da0c */
/* @0x2a450a .word 0x2104eb76 */
/* @0x2a450e stcne p8, c6, [r0, #-8]! */
/* @0x2a4512 ldmvs r8, {r0, r1, r2, r4, sp, lr, pc} */
/* @0x2a4516 stmdavs r3, {r5, r8, r12, sp, pc} */
/* @0x2a451a ldmibvs r2, {r0, r3, r5, r9, r10, lr} */
/* @0x2a451e .word 0x4798691b */
/* @0x2a4522 bvs 0xb7e5b2 <b2_toiTime+0x42510e> */
/* @0x2a4526 svclt #0x284598 */
/* @0x2a452a ldmdavs r3, {r3, r4, r7, r9, r10, lr} ^ */
/* @0x2a452e ldrtmi r11, [r8], -r3, ror #2 */
/* @0x2a4532 strbmi r2, [r2], -r1, lsl #2 */
/* @0x2a4536 stmib r8, {r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a453a .word 0xd10d1e05 */
/* @0x2a453e tsths r1, r0, lsr #26 */
/* @0x2a4542 .word 0xf7ff2200 */
/* @0x2a4546 ands pc, r7, r8, lsl #30 */
/* @0x2a454a .word 0xb1b86890 */
/* @0x2a454e andhs r4, r1, #59768832 */
/* @0x2a4552 .word 0xf6294643 */
/* @0x2a4556 strb lr, [pc, r2, lsr #23]! */
/* @0x2a455a .word 0xf612da07 */
/* @0x2a455e .word 0x2105eb4c */
/* @0x2a4562 stcne p8, c6, [r0, #-8]! */
/* @0x2a4566 mrc2 p7, #0x7, apsr_nzcv, c7, c15, #0x7 */
/* @0x2a456a stmibvs r3!, {r3, sp, lr, pc} */
/* @0x2a456e .word 0x61a3442b */
/* @0x2a4572 blne 0x197ee06 <b2_toiTime+0x1225962> */
/* @0x2a4576 and r6, r1, r3, lsr #4 */
/* @0x2a457a ldrblo pc, [pc, #0x4f]! */
/* @0x2a457e pop {r3, r5, r9, r10, lr} */
/* @0x2a4582 push {r3, r4, r5, r7, r8, pc} */

/* ── FUNC 0x2a44d7 · _zip_file_fillbuf(void*, unsigned int, zip_file*) · size=174 · insn=0 */

/* ── FUNC 0x2a4584 · anon_2a4584 · size=908 · insn=227 */
/* @0x2a4584 ldrbmi lr, [r0, sp, lsr #18]! */
/* @0x2a4588 strmi r1, [r5], -pc, lsl #28 */
/* @0x2a458c bvs 0xff39b19c <b2_toiTime+0xfffffffffec41cf8> */
/* @0x2a4590 blle 0x475014 <g_RomDisk+0x7d7f4> */
/* @0x2a4594 andeq pc, r12, r5, lsl #2 */
/* @0x2a4598 andhs r2, r0, #-2147483644 */
/* @0x2a459c mrc2 p7, #0x6, apsr_nzcv, c12, c15, #0x7 */
/* @0x2a45a0 sbcs r2, lr, r0, lsl #8 */
/* @0x2a45a4 streq pc, [r8], #-18 */
/* @0x2a45a8 tsths r4, r9, lsl #2 */
/* @0x2a45ac cmnmi r9, #68608 */
/* @0x2a45b0 bllo 0x33a724 */
/* @0x2a45b4 stmdale r2, {r0, r8, r9, r11, sp} */
/* @0x2a45b8 mrshs r3, apsr */
/* @0x2a45bc bvs 0xd9c634 <b2_toiTime+0x643190> */
/* @0x2a45c0 addmi r6, pc, #5832704 */
/* @0x2a45c4 .word 0xf04fdae6 */
/* @0x2a45c8 ldmdavs r11, {r2, r3, r4, r5, r11} */
/* @0x2a45cc .word 0xf807fb08 */
/* @0x2a45d0 ldmhi r11, {r0, r1, r6, r10, lr} ^ */
/* @0x2a45d4 blhs 0x4d0c68 <SrcVerts+0x2dcac> */
/* @0x2a45d8 streq pc, [r4], #-2 */
/* @0x2a45dc .word 0x2c00d106 */
/* @0x2a45e0 .word 0xf04fbf0c */
/* @0x2a45e4 .word 0xf04f0906 */
/* @0x2a45e8 and r0, r11, r0, lsl #18 */
/* @0x2a45ec stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2a45f0 .word 0xf105b944 */
/* @0x2a45f4 tsths r0, r12 */
/* @0x2a45f8 .word 0xf7ff4622 */
/* @0x2a45fc adcs pc, r0, sp, lsr #29 */
/* @0x2a4600 stmdbeq r4, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2a4604 .word 0xf6112034 */
/* @0x2a4608 .word 0x4604ef9e */
/* @0x2a460c .word 0xf105b930 */
/* @0x2a4610 .word 0x210e000c */
/* @0x2a4614 .word 0xf7ff4622 */
/* @0x2a4618 mlas r7, pc, lr, pc */
/* @0x2a461c blvs 0xfed3f5d0 <b2_toiTime+0xfffffffffe5e612c> */
/* @0x2a4620 addmi r1, r10, #1424 */
/* @0x2a4624 .word 0xf103db16 */
/* @0x2a4628 .word 0x6c280a0a */
/* @0x2a462c orreq lr, r10, pc, asr #20 */
/* @0x2a4630 b 0x161e80 <_Z29F_Steam_IsScreenshotRequestedR6RValueP9CInstanceS2_iPS_+0x14> */
/* @0x2a4634 ldmdblt r0, {r1, r2, r9, r10, lr} ^ */
/* @0x2a4638 andeq pc, r12, r5, lsl #2 */
/* @0x2a463c ldrtmi r2, [r2], -lr, lsl #2 */
/* @0x2a4640 mcr2 p7, #0x4, pc, c10, c15, #0x7 */
/* @0x2a4644 .word 0xf6114620 */
/* @0x2a4648 ldrtmi lr, [r4], -r10, lsl #31 */
/* @0x2a464c .word 0xf8c5e01e */
/* @0x2a4650 strtvs r10, [r8], #-60 */
/* @0x2a4654 strtmi r6, [r0], -r11, lsr #23 */
/* @0x2a4658 strhs r6, [r0], -r10, lsr #24 */
/* @0x2a465c .word 0x63a91c59 */
/* @0x2a4660 eormi pc, r3, r2, asr #16 */
/* @0x2a4664 blpl 0x3e276c <error_g0017+0x3b410> */
/* @0x2a4668 mrc2 p7, #0x3, apsr_nzcv, c1, c15, #0x7 */
/* @0x2a466c ldrtmi r6, [r0], -r6, lsr #2 */
/* @0x2a4670 shasxmi r4, r2, r1 */
/* @0x2a4674 .word 0xec16f612 */
/* @0x2a4678 .word 0x33fff04f */
/* @0x2a467c smultbvs r3, r6, r2 */
/* @0x2a4680 mvnvs r6, r6, lsr #4 */
/* @0x2a4684 rscvs r6, r6, #-2147483607 */
/* @0x2a4688 rsbvs r6, r0, #-1744830464 */
/* @0x2a468c andsls pc, r0, r4, asr #17 */
/* @0x2a4690 bvs 0xd75f38 <b2_toiTime+0x61ca94> */
/* @0x2a4694 ldmdavs r11, {r0, r3, r4, r5, r9, r10, lr} */
/* @0x2a4698 ldmhi r11, {r0, r1, r6, r10, lr} ^ */
/* @0x2a469c bvs 0xd7cc30 <b2_toiTime+0x62378c> */
/* @0x2a46a0 strbmi r6, [r3], #-2075 */
/* @0x2a46a4 mvnvs r6, r11, asr r9 */
/* @0x2a46a8 ldmdavs r11, {r0, r1, r3, r5, r9, r11, sp, lr} */
/* @0x2a46ac ldmdbvs r11, {r0, r1, r6, r10, lr} */
/* @0x2a46b0 bvs 0xd7cf44 <b2_toiTime+0x623aa0> */
/* @0x2a46b4 strbmi r6, [r3], #-2075 */
/* @0x2a46b8 adcvs r6, r3, #14352384 */
/* @0x2a46bc .word 0xf917f001 */
/* @0x2a46c0 orrlt r6, r8, #160, #2 */
/* @0x2a46c4 ldreq r6, [r11, r3, lsr #18] */
/* @0x2a46c8 bvs 0xb996d8 <b2_toiTime+0x440234> */
/* @0x2a46cc sub r6, r8, r3, ror #3 */
/* @0x2a46d0 andpl pc, r0, pc, asr #8 */
/* @0x2a46d4 svc #0x36f611 */
/* @0x2a46d8 rscvs r4, r0, #6291456 */
/* @0x2a46dc .word 0xf105b950 */
/* @0x2a46e0 .word 0x210e000c */
/* @0x2a46e4 .word 0xf7ff4632 */
/* @0x2a46e8 qasxmi pc, r0, r7 */
/* @0x2a46ec mcr2 p7, #0x2, pc, c12, c15, #0x7 */
/* @0x2a46f0 eors r4, r6, r4, lsr r6 */
/* @0x2a46f4 .word 0x5100f44f */
/* @0x2a46f8 .word 0xf7ff4622 */
/* @0x2a46fc .word 0xf1b0feec */
/* @0x2a4700 .word 0xdc050800 */
/* @0x2a4704 andeq pc, r12, r5, lsl #2 */
/* @0x2a4708 .word 0xf7ff1d21 */
/* @0x2a470c and pc, r11, r3, lsl #28 */
/* @0x2a4710 .word 0xf6112038 */
/* @0x2a4714 .word 0x4606ef18 */
/* @0x2a4718 stmdblt r8, {r5, r8, r9, sp, lr} ^ */
/* @0x2a471c andeq pc, r12, r5, lsl #2 */
/* @0x2a4720 ldrtmi r2, [r2], -lr, lsl #2 */
/* @0x2a4724 mrc2 p7, #0x0, apsr_nzcv, c8, c15, #0x7 */
/* @0x2a4728 .word 0xf7ff4620 */
/* @0x2a472c ldr pc, [r7, -sp, lsr #28]! */
/* @0x2a4730 strhs r6, [r0, -r3, ror #21] */
/* @0x2a4734 .word 0xf06f4a0c */
/* @0x2a4738 andvs r0, r7, #-2147483645 */
/* @0x2a473c smlabbeq r8, r0, r8, lr */
/* @0x2a4740 subvs r4, r7, #2046820352 */
/* @0x2a4744 addvs r2, r7, #56, #6 */
/* @0x2a4748 bl 0xffb61f98 <b2_toiTime+0xffffffffff408af4> */
/* @0x2a474c .word 0xb1404602 */
/* @0x2a4750 andeq pc, r12, r5, lsl #2 */
/* @0x2a4754 .word 0xf7ff210d */
/* @0x2a4758 qsub8mi pc, r0, pc */
/* @0x2a475c mrc2 p7, #0x0, apsr_nzcv, c4, c15, #0x7 */
/* @0x2a4760 qasxmi r4, r0, r12 */
/* @0x2a4764 .word 0x87f0e8bd */
/* @0x2a4768 andeq r7, lr, r8, lsl #17 */
/* @0x2a476c mvnsmi lr, sp, lsr #18 */
/* @0x2a4770 ldrmi r4, [r7], -lr, lsl #12 */
/* @0x2a4774 stmdahs r0, {r2, r9, r10, lr} */
/* @0x2a4778 stmdavs r3, {r0, r2, r3, r4, r5, r6, r12, lr, pc} ^ */
/* @0x2a477c cmnle r10, r0, lsl #22 */
/* @0x2a4780 ldrbeq r6, [r8, r3, lsl #18] */
/* @0x2a4784 andhs sp, r0, r2, lsl #10 */
/* @0x2a4788 ldrhhi lr, [r0, #141]! */
/* @0x2a478c rscsle r2, r10, r0, lsl #20 */
/* @0x2a4790 stmdblt r2!, {r1, r5, r6, r7, r8, r11, sp, lr} ^ */
/* @0x2a4794 .word 0xf0430759 */
/* @0x2a4798 .word 0x61220201 */
/* @0x2a479c bvs 0x1b59f70 <b2_toiTime+0x1400acc> */
/* @0x2a47a0 addsmi r6, r10, #667648 */
/* @0x2a47a4 stcne p0, c13, [r0, #-956]! */
/* @0x2a47a8 andhs r2, r0, #-1073741823 */
/* @0x2a47ac ldreq lr, [r10, r1, rrx] */
/* @0x2a47b0 strmi sp, [r8], -r7, lsl #8 */
/* @0x2a47b4 ldrtmi r4, [r9], -r2, lsr #12 */
/* @0x2a47b8 mcr2 p7, #0x4, pc, c13, c15, #0x7 */
/* @0x2a47bc ldcle p14, c1, [r0], #-20 */
/* @0x2a47c0 blvs 0xb9c93c <b2_toiTime+0x443498> */
/* @0x2a47c4 blvs 0xb7cb30 <b2_toiTime+0x42368c> */
/* @0x2a47c8 blvs 0xb7cc4c <b2_toiTime+0x4237a8> */
/* @0x2a47cc ldrsbhi pc, [r4], -r3 */
/* @0x2a47d0 .word 0x21026b20 */
/* @0x2a47d4 stmdb r2, {r1, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a47d8 strmi r1, [r2], -r3, asr #26 */
/* @0x2a47dc ldmle r7!, {r0, r1, r2, r8, r9, r11, sp} ^ */
/* @0x2a47e0 .word 0xf850a002 */
/* @0x2a47e4 strmi r1, [r8], #-35 */
/* @0x2a47e8 svclt #0x4700 */
/* @0x2a47ec andeq r0, r0, r9, asr r0 */
/* @0x2a47f0 andeq r0, r0, r3, lsl #1 */
/* @0x2a47f4 andeq r0, r0, r3, lsl #1 */
/* @0x2a47f8 andeq r0, r0, r3, lsl #1 */
/* @0x2a47fc .word 0xffffffe5 */
/* @0x2a4800 andeq r0, r0, r9, lsr #32 */
/* @0x2a4804 andeq r0, r0, r1, lsr #32 */
/* @0x2a4808 andeq r0, r0, r3, lsl #1 */
/* @0x2a480c ldmdbvs r11, {r0, r1, r5, r8, r9, r11, sp, lr} ^ */
/* @0x2a4810 sbcle r4, r4, r3, asr #10 */
/* @0x2a4814 ldmdbvs sp, {r0, r1, r5, r8, r9, r11, sp, lr} ^ */
/* @0x2a4818 bl 0xff4befac <b2_toiTime+0xfffffffffed65b08> */
/* @0x2a481c addsmi r0, sp, #20971520 */
/* @0x2a4820 stmdbvs r3!, {r0, r3, r8, r9, r12, lr, pc} */
/* @0x2a4824 strle r0, [r9, #-0x75b] */
/* @0x2a4828 ldrtmi r6, [r1], -r0, ror #20 */
/* @0x2a482c .word 0xf612462a */
/* @0x2a4830 rsbvs lr, r0, #59392 */
/* @0x2a4834 adcsmi lr, sp, #2 */
/* @0x2a4838 ldrb sp, [r2, r10, asr #7]! */
/* @0x2a483c blne 0x197efd0 <b2_toiTime+0x1225b2c> */
/* @0x2a4840 ands r6, r12, r3, ror #3 */
/* @0x2a4844 ldmdavs r11, {r0, r1, r5, r8, r9, r11, sp, lr} ^ */
/* @0x2a4848 strtmi r11, [r2], -r11, lsl #19 */
/* @0x2a484c vst1.64 {d22, d23}, [pc:128], r0 */
/* @0x2a4850 .word 0xf7ff5100 */
/* @0x2a4854 cdpne p14, #0x0, c15, c2, c0, #0x2 */
/* @0x2a4858 stcne p1, c13, [r0, #-8]! */
/* @0x2a485c and r2, r8, r5, lsl r1 */
/* @0x2a4860 blvs 0xb9b48c <b2_toiTime+0x441fe8> */
/* @0x2a4864 andsvs r6, r9, r1, ror #21 */
/* @0x2a4868 subsvs r6, r10, r3, lsr #22 */
/* @0x2a486c stcne p7, c14, [r0, #-704]! */
/* @0x2a4870 .word 0xf7ff210d */
/* @0x2a4874 .word 0xf04ffd71 */
/* @0x2a4878 pop {r0, r1, r2, r3, r4, r5, r6, r7, r12, sp} */
/* @0x2a487c qsub8mi r8, r8, r0 */
/* @0x2a4880 ldrhhi lr, [r0, #141]! */
/* @0x2a4884 .word 0x4604b570 */
/* @0x2a4888 eorsle r2, r6, r0, lsl #16 */
/* @0x2a488c .word 0xb1086800 */
/* @0x2a4890 mcr p6, #0x3, pc, c4, c1, #0x0 */
/* @0x2a4894 .word 0xb1086860 */
/* @0x2a4898 svc #0xdaf611 */
/* @0x2a489c .word 0xf7ff6a20 */
/* @0x2a48a0 blvs 0x1ba2f50 <b2_toiTime+0x1449aac> */
/* @0x2a48a4 strhs r11, [r0, #-0x16b] */
/* @0x2a48a8 bvs 0xffb6e100 <b2_toiTime+0xffffffffff414c5c> */
/* @0x2a48ac addsmi r6, sp, #96, #22 */
/* @0x2a48b0 blx 0x45b0ce <g_RomDisk+0x638ae> */
/* @0x2a48b4 .word 0xf0000005 */
/* @0x2a48b8 strlo pc, [r1, #-0xf58] */
/* @0x2a48bc .word 0xf611e7f5 */
/* @0x2a48c0 strhs lr, [r0, #-0xe4e] */
/* @0x2a48c4 addsmi r6, sp, #166912 */
/* @0x2a48c8 .word 0x6c23da0f */
/* @0x2a48cc eoreq pc, r5, r3, asr r8 */
/* @0x2a48d0 stmdblt r6, {r1, r2, r6, r11, sp, lr} ^ */
/* @0x2a48d4 .word 0x21083004 */
/* @0x2a48d8 .word 0xf7ff4632 */
/* @0x2a48dc stcvs p13, c15, [r3], #-244 */
/* @0x2a48e0 eorlo pc, r5, r3, asr r8 */
/* @0x2a48e4 strlo r6, [r1, #-0x1e] */
/* @0x2a48e8 stcvs p7, c14, [r0], #-944 */
/* @0x2a48ec mrc p6, #0x1, apsr_nzcv, c6, c1, #0x0 */
/* @0x2a48f0 pop {r5, r9, r10, lr} */
/* @0x2a48f4 .word 0xf0774070 */
/* @0x2a48f8 ldcllt p8, c11, [r0, #-900]! */
/* @0x2a48fc svclt #0x4c0713 */
/* @0x2a4900 stmibvs r3, {r0, r1, r7, r8, r11, sp, lr} ^ */
/* @0x2a4904 svclt #0xc420b */
/* @0x2a4908 andhs r2, r1, r0 */
/* @0x2a490c .word 0xb1084770 */

/* ── FUNC 0x2a4585 · zip_fopen_index · size=488 · insn=0 */

/* ── FUNC 0x2a476d · zip_fread · size=280 · insn=0 */

/* ── FUNC 0x2a4885 · _zip_free(zip*) · size=120 · insn=0 */

/* ── FUNC 0x2a48fd · zip_get_archive_flag · size=18 · insn=0 */

/* ── FUNC 0x2a490e · anon_2a490e · size=100 · insn=25 */
/* @0x2a490e bvs 0xff2d0d36 <b2_toiTime+0xfffffffffeb77892> */
/* @0x2a4912 .word 0xf04f4770 */
/* @0x2a4916 .word 0x477030ff */
/* @0x2a491a ldrblt r2, [r0, #-0x900]! */
/* @0x2a491e ldrmi r4, [r8], -r4, lsl #12 */
/* @0x2a4922 bvs 0xffb9b532 <b2_toiTime+0xffffffffff44208e> */
/* @0x2a4926 blle 0x3f5392 <g_MP3UpdateVolume+0xb6> */
/* @0x2a492a andhs r2, r0, #-2147483644 */
/* @0x2a492e ldc2 p7, c15, [r3, #-1020] */
/* @0x2a4932 ldcllt p0, c2, [r0, #-0]! */
/* @0x2a4936 streq pc, [r8, #-0x12] */
/* @0x2a493a tsths r4, #-1073741822 */
/* @0x2a493e movtmi r6, #0xbb62 */
/* @0x2a4942 ldmpl r3, {r1, r2, r4, r6, r7, r11, r12} ^ */
/* @0x2a4946 .word 0xd1022b01 */
/* @0x2a494a qadd16mi r2, r10, r7 */
/* @0x2a494e ldmvs r3!, {r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2a4952 bvs 0xb52ec6 <b2_toiTime+0x3f9a22> */
/* @0x2a4956 rscle r2, r7, r0, lsl #20 */
/* @0x2a495a addsmi r6, r9, #5439488 */
/* @0x2a495e ldmdavs r3, {r2, r5, r6, r7, r9, r11, r12, lr, pc} */
/* @0x2a4962 blx 0x32d25c */
/* @0x2a4966 stmibvs r8, {r0, r8, r12, sp} */
/* @0x2a496a ssub16mi r11, r8, r0 */
/* @0x2a496e .word 0xf100bd70 */

/* ── FUNC 0x2a490f · zip_get_num_files · size=12 · insn=0 */

/* ── FUNC 0x2a491b · _zip_get_name(zip*, int, int, zip_error*) · size=86 · insn=0 */

/* ── FUNC 0x2a4970 · anon_2a4970 · size=3580 · insn=895 */
/* @0x2a4970 movweq pc, #0xc100 */
/* @0x2a4974 svclt #0xd1f7ff */
/* @0x2a4978 .word 0x4606b5f8 */
/* @0x2a497c strmi r4, [sp], -r8, lsl #12 */
/* @0x2a4980 .word 0xf6114617 */
/* @0x2a4984 strmi lr, [r4], -r0, ror #27 */
/* @0x2a4988 ldrtmi r11, [r8], -r8, lsr #18 */
/* @0x2a498c strtmi r2, [r2], -lr, lsl #2 */
/* @0x2a4990 stc2l p7, c15, [r2], #1020 */
/* @0x2a4994 ldrtmi lr, [r1], -r3 */
/* @0x2a4998 .word 0xf611462a */
/* @0x2a499c qadd16mi lr, r0, r0 */
/* @0x2a49a0 strdeq r11, r12, [r0], -r8 */
/* @0x2a49a4 svcmi #0xf0e92d */
/* @0x2a49a8 addlt r4, r5, r3, lsl #13 */
/* @0x2a49ac sadd16mi r4, pc, r6 */
/* @0x2a49b0 ldmdblt r9, {r3, r7, r9, r10, lr} */
/* @0x2a49b4 tsths r2, r8, lsl r6 */
/* @0x2a49b8 eors r4, pc, r2, asr #12 */
/* @0x2a49bc strle r0, [r3, #-0x7d3] */
/* @0x2a49c0 ldrbtmi r4, [sp], #-3363 */
/* @0x2a49c4 and r6, r2, sp, lsr #16 */
/* @0x2a49c8 ldrbtmi r4, [sp], #-3362 */
/* @0x2a49cc .word 0xf016682d */
/* @0x2a49d0 .word 0xf04f0208 */
/* @0x2a49d4 .word 0xf04f0400 */
/* @0x2a49d8 andls r0, r2, #60, #20 */
/* @0x2a49dc .word 0xf8dbbf16 */
/* @0x2a49e0 .word 0xf8db3020 */
/* @0x2a49e4 .word 0xf8d3902c */
/* @0x2a49e8 .word 0xf0069004 */
/* @0x2a49ec movwls r0, #0x3302 */
/* @0x2a49f0 ble 0xab5f28 <b2_toiTime+0x35ca84> */
/* @0x2a49f4 teqlt r2, r2, lsl #20 */
/* @0x2a49f8 .word 0x3020f8db */
/* @0x2a49fc blx 0x53ea72 <obj_has_event+0x3f02> */
/* @0x2a4a00 ldmibvs r11, {r2, r8, r9, r12, sp} */
/* @0x2a4a04 ldrtmi lr, [r11], -r6 */
/* @0x2a4a08 qsaxmi r4, r1, r8 */
/* @0x2a4a0c .word 0xf7ff4632 */
/* @0x2a4a10 strmi pc, [r3], -r4, lsl #31 */
/* @0x2a4a14 bls 0x390fc8 <ft_adobe_glyph_list+0x6a4> */
/* @0x2a4a18 sasxmi r11, r8, r10 */
/* @0x2a4a1c movwls r2, #0x112f */
/* @0x2a4a20 svc #0x22f611 */
/* @0x2a4a24 .word 0xb1009b01 */
/* @0x2a4a28 strbmi r1, [r0], -r3, asr #24 */
/* @0x2a4a2c .word 0x47a84619 */
/* @0x2a4a30 strlo r11, [r1], #-328 */
/* @0x2a4a34 .word 0x4638e7dc */
/* @0x2a4a38 andhs r2, r0, #1073741826 */
/* @0x2a4a3c stc2 p7, c15, [r12], {255} */
/* @0x2a4a40 rscslo pc, pc, pc, asr #32 */
/* @0x2a4a44 strtmi lr, [r0], -r0 */
/* @0x2a4a48 pop {r0, r2, r12, sp, pc} */
/* @0x2a4a4c svclt #0x8ff0 */
/* @0x2a4a50 andseq sp, r4, r10, asr #1 */
/* @0x2a4a54 andseq sp, r4, r6, asr #1 */
/* @0x2a4a58 movweq pc, #0xc100 */
/* @0x2a4a5c svclt #0xa2f7ff */
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
/* @0x2a4de0 svcmi #0xf0e92d */
/* @0x2a4de4 ldrmi r11, [r5], -r9, lsr #1 */
/* @0x2a4de8 andls r9, r6, r4, lsl #2 */
/* @0x2a4dec bhs 0x2d3254 <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x258> */
/* @0x2a4df0 tsths r2, #107 */
/* @0x2a4df4 svcge #0xee012 */
/* @0x2a4df8 .word 0xf6114639 */
/* @0x2a4dfc ldrshlt lr, [r0, -r12]! */
/* @0x2a4e00 ldrbeq r9, [r1, r4, lsl #20] */
/* @0x2a4e04 stchs p4, c13, [r0, #-48] */
/* @0x2a4e08 movwhs sp, #0xb05f */
/* @0x2a4e0c blls 0x3dce2c <error_g0017+0x35ad0> */
/* @0x2a4e10 streq pc, [r2], #-19 */
/* @0x2a4e14 stchs p0, c13, [r0, #-36] */
/* @0x2a4e18 movwhs sp, #0xa057 */
/* @0x2a4e1c subs r6, r4, r11, lsr #32 */
/* @0x2a4e20 strtmi r9, [r9], -r6, lsl #16 */
/* @0x2a4e24 .word 0xff49f7ff */
/* @0x2a4e28 stmibmi r6!, {r0, r1, r2, r4, r5, r7, r8, sp, lr, pc} */
/* @0x2a4e2c ldrbtmi r9, [r9], #-2054 */
/* @0x2a4e30 stc p6, c15, [r8, #-68] */
/* @0x2a4e34 stmdblt r0!, {r1, r2, r9, r10, lr} */
/* @0x2a4e38 suble r2, r8, r0, lsl #26 */
/* @0x2a4e3c eorvs r2, r11, r11, lsl #6 */
/* @0x2a4e40 strtmi lr, [r1], -r11, lsr #3 */
/* @0x2a4e44 .word 0xf6122202 */
/* @0x2a4e48 ldrtmi lr, [r0], -r6, asr #16 */
/* @0x2a4e4c stmda r8, {r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a4e50 stmdals r6, {r3, r4, r5, r8, r11, r12, sp, pc} */
/* @0x2a4e54 .word 0xf7ff4629 */
/* @0x2a4e58 .word 0x4604ff30 */
/* @0x2a4e5c subvs r11, r6, r0, lsl #6 */
/* @0x2a4e60 ldmibmi r7, {r1, r2, r5, sp, lr, pc} */
/* @0x2a4e64 addmi r2, r8, #536870912 */
/* @0x2a4e68 .word 0x4601bfb8 */
/* @0x2a4e6c submi r4, r9, #48, #12 */
/* @0x2a4e70 ldmda r0!, {r1, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a4e74 tstle sp, r1 */
/* @0x2a4e78 mrc p6, #0x5, apsr_nzcv, c14, c1, #0x0 */
/* @0x2a4e7c blhs 0x97ee90 <b2_toiTime+0x2259ec> */
/* @0x2a4e80 ands sp, r7, r7, lsr #2 */
/* @0x2a4e84 svceq #0xf1b8 */
/* @0x2a4e88 stmdals r6, {r2, r3, r4, r12, lr, pc} */
/* @0x2a4e8c .word 0xf7ff4629 */
/* @0x2a4e90 .word 0x4604ff14 */
/* @0x2a4e94 .word 0xf0402800 */
/* @0x2a4e98 strbmi r8, [r0], -r0, ror #2 */
/* @0x2a4e9c mcr2 p7, #0x5, pc, c11, c14, #0x7 */
/* @0x2a4ea0 .word 0xf6114630 */
/* @0x2a4ea4 ldrd lr, pc, [r3], -r6 */
/* @0x2a4ea8 ldc2l p7, c15, [r2, #1020]! */
/* @0x2a4eac mvnvs r6, r3, lsr #19 */
/* @0x2a4eb0 cmn r2, r0, lsr #12 */
/* @0x2a4eb4 .word 0xf6114882 */
/* @0x2a4eb8 strmi lr, [r3], r6, asr #22 */
/* @0x2a4ebc .word 0xb10db968 */
/* @0x2a4ec0 eorvs r2, r11, lr, lsl #6 */
/* @0x2a4ec4 .word 0xf6114630 */
/* @0x2a4ec8 andhs lr, r0, r4, asr #25 */
/* @0x2a4ecc strtmi lr, [r8], -r5, ror #2 */
/* @0x2a4ed0 movwhs lr, #0x4163 */
/* @0x2a4ed4 mvnsle r2, r0, lsl #26 */
/* @0x2a4ed8 shsub8mi lr, r0, r4 */
/* @0x2a4edc ldmda lr, {r1, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a4ee0 qaddhs r4, r8, r1 */
/* @0x2a4ee4 shsub16mi r4, r3, r6 */
/* @0x2a4ee8 stcl p6, c15, [lr], #68 */
/* @0x2a4eec strhhi pc, [r12], -r6 */
/* @0x2a4ef0 stmdaeq r0, {r3, r12, sp, lr, pc} ^ */
/* @0x2a4ef4 .word 0xf488fa1f */
/* @0x2a4ef8 teqlt r4, r8 */
/* @0x2a4efc movwhs r11, #0x510d */
/* @0x2a4f00 ldrbmi r6, [r8], -r11, lsr #32 */
/* @0x2a4f04 bl 0xd62750 <b2_toiTime+0x6092ac> */
/* @0x2a4f08 .word 0x4622e7dc */
/* @0x2a4f0c tsths r3, r8, lsr r6 */
/* @0x2a4f10 .word 0xf7ff46a0 */
/* @0x2a4f14 .word 0xf04ffa21 */
/* @0x2a4f18 blmi 0x1d71b1c <b2_toiTime+0x1618678> */
/* @0x2a4f1c bmi 0x1d8972c <b2_toiTime+0x1630288> */
/* @0x2a4f20 .word 0xf8cd447b */
/* @0x2a4f24 movwls r11, #0xa01c */
/* @0x2a4f28 blge 0x5b6118 <g_SWFlineaavertbuff+0x63050> */
/* @0x2a4f2c movwls r9, #0x320b */
/* @0x2a4f30 blls 0x4cb754 <SrcVerts+0x28798> */
/* @0x2a4f34 smlabteq r11, r2, r11, lr */
/* @0x2a4f38 sadd16mi r4, r0, r9 */
/* @0x2a4f3c .word 0xf7ff3912 */
/* @0x2a4f40 strmi pc, [r1], r3, lsl #28 */
/* @0x2a4f44 .word 0xf0002800 */
/* @0x2a4f48 blls 0x4c5330 <SrcVerts+0x22374> */
/* @0x2a4f4c andeq pc, r1, #1073741826 */
/* @0x2a4f50 ldrbmi r9, [r11], #-519 */
/* @0x2a4f54 movweq lr, #0x3bc9 */
/* @0x2a4f58 movwls r3, #0x5b16 */
/* @0x2a4f5c ldrtmi sp, [r8], -r3, lsl #10 */
/* @0x2a4f60 andhs r2, r0, #-1073741820 */
/* @0x2a4f64 stmdbls r10, {r0, r4, sp, lr, pc} */
/* @0x2a4f68 .word 0xf6112204 */
/* @0x2a4f6c strmi lr, [r4], -r10, ror #28 */
/* @0x2a4f70 mvnsle r2, r0, lsl #16 */
/* @0x2a4f74 andeq pc, r4, r9, lsl #2 */
/* @0x2a4f78 andhs r9, r4, #180224 */
/* @0x2a4f7c mcr p6, #0x3, pc, c0, c1, #0x0 */
/* @0x2a4f80 smlawblt r8, r2, r6, r4 */
/* @0x2a4f84 .word 0x21014638 */
/* @0x2a4f88 .word 0xf7ff4622 */
/* @0x2a4f8c sbc pc, lr, r5, ror #19 */
/* @0x2a4f90 .word 0xf109a80c */
/* @0x2a4f94 movwls r0, #0xc308 */
/* @0x2a4f98 .word 0xff92f7fe */
/* @0x2a4f9c stmdage r12, {r0, r3, r12, pc} */
/* @0x2a4fa0 .word 0xff8ef7fe */
/* @0x2a4fa4 .word 0xf7fe4639 */
/* @0x2a4fa8 strmi pc, [r4], -pc, ror #27 */
/* @0x2a4fac .word 0xf0002800 */
/* @0x2a4fb0 stmdage r12, {r1, r2, r3, r4, r5, r7, pc} */
/* @0x2a4fb4 .word 0xff8df7fe */
/* @0x2a4fb8 stmdage r12, {r5, r7, sp, lr} */
/* @0x2a4fbc .word 0xff89f7fe */
/* @0x2a4fc0 andsge pc, r0, r4, asr #17 */
/* @0x2a4fc4 stmdage r12, {r5, r6, r7, sp, lr} */
/* @0x2a4fc8 .word 0xff7af7fe */
/* @0x2a4fcc addmi r9, r3, #5120 */
/* @0x2a4fd0 adchi r4, r0, #1048576 */
/* @0x2a4fd4 stmdavs r3!, {r0, r1, r8, r9, r11, r12, lr, pc} ^ */
/* @0x2a4fd8 addsmi r9, r3, #36864 */
/* @0x2a4fdc ldrtmi sp, [r8], -r3 */
/* @0x2a4fe0 andhs r2, r0, #-1073741820 */
/* @0x2a4fe4 blls 0x3dd0f8 <error_g0017+0x35d9c> */
/* @0x2a4fe8 strle r0, [r6, #-0x75a] */
/* @0x2a4fec addmi r9, r3, #5120 */
/* @0x2a4ff0 ldrtmi sp, [r8], -r3 */
/* @0x2a4ff4 uadd16mi r2, r2, r5 */
/* @0x2a4ff8 teqlt r9, r9, lsr r0 */
/* @0x2a4ffc andseq pc, r6, r9, lsl #2 */
/* @0x2a5000 .word 0xf7ff463a */
/* @0x2a5004 strhvs pc, [r0, -r9]! */
/* @0x2a5008 eorsle r2, r2, r0, lsl #16 */
/* @0x2a500c bl 0xff57f2a0 <b2_toiTime+0xfffffffffee25dfc> */
/* @0x2a5010 addsmi r0, r3, #-1879048192 */
/* @0x2a5014 bl 0xff399830 <b2_toiTime+0xfffffffffec4038c> */
/* @0x2a5018 bge 0x5a5c44 <g_SWFlineaavertbuff+0x52b7c> */
/* @0x2a501c andls r9, r5, #12, #6 */
/* @0x2a5020 ldrtmi lr, [r0], -r11, lsr #32 */
/* @0x2a5024 svc #0x7af611 */
/* @0x2a5028 stmvs r1!, {r4, r5, r9, r10, lr} ^ */
/* @0x2a502c .word 0xf6112200 */
/* @0x2a5030 rfeia r6! */
/* @0x2a5034 .word 0xf00aa00c */
/* @0x2a5038 blx 0xa67940 <b2_toiTime+0x30e49c> */
/* @0x2a503c .word 0xf1bafa8a */
/* @0x2a5040 .word 0xd1080f00 */
/* @0x2a5044 .word 0xf6114630 */
/* @0x2a5048 stmvs r3!, {r2, r3, r6, r8, r9, r10, r11, sp, lr, pc} ^ */
/* @0x2a504c swple r4, r8, [r2] */
/* @0x2a5050 andsge pc, r4, sp, asr #17 */
/* @0x2a5054 ldmibhi r2!, {r0, r4, sp, lr, pc} */
/* @0x2a5058 subeq pc, r0, #2 */
/* @0x2a505c bhs 0x2d1aac <_ZN15b2RevoluteJoint23InitVelocityConstraintsERK12b2SolverData+0x1e0> */
/* @0x2a5060 addshi pc, r8, r0 */
/* @0x2a5064 stcl p6, c15, [r8, #68] */
/* @0x2a5068 stmdavs r2, {r2, r8, sp} */
/* @0x2a506c .word 0xf7ff4638 */
/* @0x2a5070 qsub16mi pc, r0, r3 */
/* @0x2a5074 b 0x1f628c0 <b2_toiTime+0x180941c> */
/* @0x2a5078 stmvs r3!, {r0, r3, r4, r6, sp, lr, pc} */
/* @0x2a507c stmibeq r0!, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x2a5080 beq 0x2e11c4 <_ZN8b2IslandC2EiiiP16b2StackAllocatorP17b2ContactListener+0x94> */
/* @0x2a5084 stcllo p8, c15, [r12, #-292]! */
/* @0x2a5088 ldrmi r6, [r10, #0x863] */
/* @0x2a508c blls 0x6194b0 <g_SWFaavertbuff+0x463e8> */
/* @0x2a5090 strtmi r11, [r0], -r11, lsr #2 */
/* @0x2a5094 orrlo pc, r0, r10, lsl #10 */
/* @0x2a5098 .word 0xf7fe463a */
/* @0x2a509c stmdavs r0!, {r3, r4, r6, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2a50a0 movwhs r2, #0x23c */
/* @0x2a50a4 stm sp, {r0, r4, r5, r9, r10, lr} */
/* @0x2a50a8 strbmi r0, [r11], -r8, lsl #1 */
/* @0x2a50ac andeq pc, r10, r2, lsl #22 */
/* @0x2a50b0 .word 0xf7fe9a05 */
/* @0x2a50b4 stmdahs r0, {r0, r2, r3, r4, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a50b8 .word 0xf8c4da0a */
/* @0x2a50bc eor r10, r8, r4 */
/* @0x2a50c0 andeq r0, r1, r6, lsl r0 */
/* @0x2a50c4 andeq r7, lr, sp, asr #3 */
/* @0x2a50c8 andeq r7, lr, r8, ror #1 */
/* @0x2a50cc andeq r10, lr, lr, lsr #18 */
/* @0x2a50d0 .word 0xf10a6863 */
/* @0x2a50d4 ldrmi r0, [r10, #0xa01] */
/* @0x2a50d8 movtlt sp, #0x4bd6 */
/* @0x2a50dc svceq #0xf1b8 */
/* @0x2a50e0 blls 0x359154 */
/* @0x2a50e4 .word 0xdc052b00 */
/* @0x2a50e8 .word 0x46414630 */
/* @0x2a50ec .word 0xf7ff463a */
/* @0x2a50f0 andls pc, r2, r6, lsl #28 */
/* @0x2a50f4 shasxmi r4, r0, r10 */
/* @0x2a50f8 .word 0xf7ff4621 */
/* @0x2a50fc bls 0x364904 <_ZTS12CDS_Priority+0x695c> */
/* @0x2a5100 strmi r4, [r1], r2, lsl #5 */
/* @0x2a5104 strbmi sp, [r0], -r5, lsl #20 */
/* @0x2a5108 ldc2l p7, c15, [r5, #-1016]! */
/* @0x2a510c andls pc, r8, sp, asr #17 */
/* @0x2a5110 qadd16mi lr, r0, r1 */
/* @0x2a5114 stc2l p7, c15, [pc, #-1016]! */
/* @0x2a5118 blls 0x3dd144 <error_g0017+0x35de8> */
/* @0x2a511c strle r0, [r8, #-0x75b] */
/* @0x2a5120 qasxmi r4, r1, r0 */
/* @0x2a5124 .word 0xf7ff463a */
/* @0x2a5128 andls pc, r2, r10, ror #27 */
/* @0x2a512c strbmi lr, [r4], -r3 */
/* @0x2a5130 .word 0xf8cde001 */
/* @0x2a5134 strtmi r8, [r0], r8 */
/* @0x2a5138 usub8mi lr, r8, r10 */
/* @0x2a513c b 0x662988 <g_SWFlinevertbuff+0xf8c0> */
/* @0x2a5140 bhs 0x2cb950 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x70> */
/* @0x2a5144 mrcge p6, #0x4, apsr_nzcv, c14, c15, #0x5 */
/* @0x2a5148 ldrtmi r4, [r9], -r8, lsr #12 */
/* @0x2a514c .word 0xf7ff464a */
/* @0x2a5150 strbmi pc, [r0], -r7, lsl #25 */
/* @0x2a5154 stc2l p7, c15, [pc, #-1016] */
/* @0x2a5158 .word 0xf8c0e6b4 */
/* @0x2a515c subvs r8, r6, r0, lsr #32 */
/* @0x2a5160 .word 0xf8d82014 */
/* @0x2a5164 cmpmi r8, #4 */
/* @0x2a5168 stmib r12!, {r0, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a516c ldmdblt r0!, {r5, r6, r8, r9, sp, lr} */
/* @0x2a5170 movwhs r11, #0xe10d */
/* @0x2a5174 strtmi r6, [r0], -r11, lsr #32 */
/* @0x2a5178 blx 0xfe3e317e <b2_toiTime+0xfffffffffdc89cda> */
/* @0x2a517c .word 0xf8d8e6a5 */
/* @0x2a5180 strtmi r3, [r0], -r4 */
/* @0x2a5184 .word 0xf6bf4599 */
/* @0x2a5188 .word 0xf000ae8f */
/* @0x2a518c .word 0xf109fb01 */
/* @0x2a5190 ldrb r0, [r4, r1, lsl #18]! */
/* @0x2a5194 tsths r3, r8, lsr r6 */
/* @0x2a5198 eorlt lr, r9, r9, ror #14 */
/* @0x2a519c svchi #0xf0e8bd */
/* @0x2a51a0 svcmi #0xf0e92d */
/* @0x2a51a4 .word 0x4606b093 */
/* @0x2a51a8 bvs 0x3499bc */
/* @0x2a51ac stmdblt r10, {r0, r3, r8, r12, pc} ^ */
/* @0x2a51b0 stmdbls r3, {r3, r5, r7, r11, lr} */
/* @0x2a51b4 .word 0xf7ff4478 */
/* @0x2a51b8 stmdahs r0, {r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2a51bc cmphi r9, r0 */
/* @0x2a51c0 cmp r6, r6, lsl #1 */
/* @0x2a51c4 .word 0x21026803 */
/* @0x2a51c8 ldmdbvs r11, {r0, r5, r7, r10, r11, lr} */
/* @0x2a51cc svclt #0xa842a2 */
/* @0x2a51d0 ldrmi r4, [r8, r2, lsr #12] */
/* @0x2a51d4 .word 0xf6114620 */
/* @0x2a51d8 selmi lr, r1, r6 */
/* @0x2a51dc bls 0x3936a4 <ft_adobe_glyph_list+0x2d80> */
/* @0x2a51e0 .word 0xf0002a00 */
/* @0x2a51e4 movwhs r8, #0xe145 */
/* @0x2a51e8 .word 0xe1416013 */
/* @0x2a51ec strbmi r4, [r9], -r3, lsr #12 */
/* @0x2a51f0 ldrtmi r2, [r0], -r1, lsl #4 */
/* @0x2a51f4 ldcl p6, c15, [r2, #-160] */
/* @0x2a51f8 andhs r10, r0, #960 */
/* @0x2a51fc .word 0xf04f2113 */
/* @0x2a5200 strhs r3, [r0], #-2303 */
/* @0x2a5204 strtmi r9, [r8], -r7 */
/* @0x2a5208 .word 0xf8a6f7ff */
/* @0x2a520c bmi 0xfe77805c <b2_toiTime+0xfffffffffe01ebb8> */
/* @0x2a5210 .word 0xf8cd447b */
/* @0x2a5214 movwls r9, #0xa018 */
/* @0x2a5218 blge 0x5f6408 <g_SWFaavertbuff+0x23340> */
/* @0x2a521c movwls r9, #0x420b */
/* @0x2a5220 bls 0x48be40 <prim_v+0x248c> */
/* @0x2a5224 smlabteq r9, r3, r11, lr */
/* @0x2a5228 sadd16mi r4, r8, r1 */
/* @0x2a522c .word 0xf7ff3912 */
/* @0x2a5230 strmi pc, [r7], -r11, lsl #25 */
/* @0x2a5234 .word 0xf0002800 */
/* @0x2a5238 blls 0x485590 <mstack+0x8a4> */
/* @0x2a523c andls r1, r6, #31232 */
/* @0x2a5240 blne 0xff976374 <b2_toiTime+0xffffffffff21ced0> */
/* @0x2a5244 movwls r3, #0x8b16 */
/* @0x2a5248 strtmi sp, [r8], -r3, lsl #10 */
/* @0x2a524c andhs r2, r0, #-1073741820 */
/* @0x2a5250 stmdbls r10, {r4, sp, lr, pc} */
/* @0x2a5254 .word 0xf6112204 */
/* @0x2a5258 .word 0x4683ecf4 */
/* @0x2a525c mvnsle r2, r0, lsl #16 */
/* @0x2a5260 stmdbls r11, {r3, r4, r5, r8, r10, r11, r12} */
/* @0x2a5264 .word 0xf6112204 */
/* @0x2a5268 andls lr, r5, r12, ror #25 */
/* @0x2a526c strtmi r11, [r8], -r8, lsr #2 */
/* @0x2a5270 ldrbmi r2, [r10], -r1, lsl #2 */
/* @0x2a5274 .word 0xf870f7ff */
/* @0x2a5278 stmdage sp, {r1, r2, r3, r5, r7, sp, lr, pc} */
/* @0x2a527c movweq pc, #0x8107 */
/* @0x2a5280 .word 0xf7fe930d */
/* @0x2a5284 pkhbtmi pc, r3, sp, lsl #28 */
/* @0x2a5288 .word 0xf7fea80d */
/* @0x2a528c qadd16mi pc, r9, r9 */
/* @0x2a5290 ldc2l p7, c15, [r10], #-1016 */
/* @0x2a5294 stmdahs r0, {r1, r7, r9, r10, lr} */
/* @0x2a5298 addshi pc, lr, r0 */
/* @0x2a529c .word 0xf7fea80d */
/* @0x2a52a0 .word 0xf8cafe18 */
/* @0x2a52a4 stmdage sp, {r3} */
/* @0x2a52a8 mrc2 p7, #0x0, apsr_nzcv, c3, c14, #0x7 */
/* @0x2a52ac .word 0xf8ca9b05 */
/* @0x2a52b0 .word 0xf8ca3010 */
/* @0x2a52b4 stmdage sp, {r2, r3} */
/* @0x2a52b8 mcr2 p7, #0x0, pc, c2, c14, #0x7 */
/* @0x2a52bc addmi r9, r3, #8, #22 */
/* @0x2a52c0 .word 0xf8aa4601 */
/* @0x2a52c4 blle 0x36531c <_ZTS12CDS_Priority+0x7374> */
/* @0x2a52c8 .word 0x3004f8da */
/* @0x2a52cc andle r4, r3, r11, asr r5 */
/* @0x2a52d0 tsths r3, r8, lsr #12 */
/* @0x2a52d4 and r2, r8, r0, lsl #4 */
/* @0x2a52d8 ldrbeq r9, [r2, -r9, lsl #20] */
/* @0x2a52dc blls 0x4da704 <SrcVerts+0x37748> */
/* @0x2a52e0 andle r4, r5, r3, lsl #5 */
/* @0x2a52e4 strtmi r9, [r8], -r5, lsl #20 */
/* @0x2a52e8 .word 0xf7ff2115 */
/* @0x2a52ec and pc, r8, r5, lsr r8 */
/* @0x2a52f0 .word 0xf107b159 */
/* @0x2a52f4 qadd16mi r0, r10, r6 */
/* @0x2a52f8 blx 0x12632fe <b2_toiTime+0xb09e5a> */
/* @0x2a52fc andseq pc, r0, r10, asr #17 */
/* @0x2a5300 uadd16mi r11, r0, r8 */
/* @0x2a5304 stmdb r10!, {r0, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a5308 .word 0xf8dae066 */
/* @0x2a530c bl 0xff4f1334 <b2_toiTime+0xfffffffffed97e90> */
/* @0x2a5310 addsmi r0, r3, #1879048192 */
/* @0x2a5314 bne 0x299b2c <_Z13RelyAddPacketiPKciji+0x30> */
/* @0x2a5318 strls r10, [sp, -sp, lsl #20] */
/* @0x2a531c and r9, r8, r5, lsl #4 */
/* @0x2a5320 shasxmi r6, r0, r3 */
/* @0x2a5324 .word 0xf8da2100 */
/* @0x2a5328 ldmdbvs r11, {r2, r3, sp} */
/* @0x2a532c movwhs r4, #0x798 */
/* @0x2a5330 .word 0xf8da9305 */
/* @0x2a5334 svcge #0x123008 */
/* @0x2a5338 bleq 0x2e147c <_ZN8b2Island8SolveTOIERK10b2TimeStepii+0x1b8> */
/* @0x2a533c ldclo p8, c15, [r0, #-284] */
/* @0x2a5340 .word 0x3004f8da */
/* @0x2a5344 swple r4, r11, [r7] */
/* @0x2a5348 .word 0xb12b9b0e */
/* @0x2a534c .word 0xf50b4650 */
/* @0x2a5350 strtmi r3, [r10], -r0, lsl #3 */
/* @0x2a5354 blx 0x1a3356 <_Z18ParticleType_Deathiii+0x2a> */
/* @0x2a5358 .word 0x0000f8da */
/* @0x2a535c andhs r2, r0, #60, #6 */
/* @0x2a5360 stm sp, {r0, r4, r5, r9, r10, lr} */
/* @0x2a5364 blx 0x3653fe <_ZTS12CDS_Priority+0x7456> */
/* @0x2a5368 bls 0x3e539c <error_g0017+0x3e040> */
/* @0x2a536c .word 0xf7fe463b */
/* @0x2a5370 stmdahs r0, {r0, r1, r3, r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a5374 .word 0xf8cada02 */
/* @0x2a5378 ands r11, pc, r4 */
/* @0x2a537c .word 0x3004f8da */
/* @0x2a5380 bleq 0x3217b4 */
/* @0x2a5384 blle 0xff9769f8 <b2_toiTime+0xffffffffff21d554> */
/* @0x2a5388 svceq #0xf1ba */
/* @0x2a538c biclt sp, r12, r4, lsr #32 */
/* @0x2a5390 svceq #0xf1b8 */
/* @0x2a5394 ldrtmi sp, [r0], -r5, lsl #24 */
/* @0x2a5398 strtmi r4, [r10], -r1, lsr #12 */
/* @0x2a539c .word 0xfc1df7ff */
/* @0x2a53a0 ldrtmi r4, [r0], -r0, lsl #13 */
/* @0x2a53a4 qsaxmi r4, r10, r1 */
/* @0x2a53a8 .word 0xfc17f7ff */
/* @0x2a53ac strmi r4, [r7], -r0, lsl #11 */
/* @0x2a53b0 strtmi sp, [r0], -r4, lsl #20 */
/* @0x2a53b4 .word 0xf7fe46b8 */
/* @0x2a53b8 ands pc, r0, lr, lsl r12 */
/* @0x2a53bc .word 0xf7fe4650 */
/* @0x2a53c0 and pc, r9, r10, lsl r12 */
/* @0x2a53c4 ldrbeq r9, [r3, -r9, lsl #20] */
/* @0x2a53c8 ldrtmi sp, [r0], -r8, lsl #10 */
/* @0x2a53cc qsaxmi r4, r10, r1 */
/* @0x2a53d0 .word 0xfc03f7ff */
/* @0x2a53d4 and r4, r2, r0, lsl #13 */
/* @0x2a53d8 and r4, r0, r2, lsr #13 */
/* @0x2a53dc ldrbmi r4, [r4], -r0, lsr #13 */
/* @0x2a53e0 .word 0x4648e71e */
/* @0x2a53e4 ldm r10!, {r0, r4, r9, r10, r12, sp, lr, pc} */
/* @0x2a53e8 svceq #0xf1b8 */
/* @0x2a53ec stmdals r3, {r3, r9, r11, r12, lr, pc} */
/* @0x2a53f0 ldrtmi r4, [r10], -r9, lsr #12 */
/* @0x2a53f4 blx 0xfe33fa <b2_toiTime+0x889f56> */
/* @0x2a53f8 .word 0xf7fe4620 */
/* @0x2a53fc ldrsht pc, [r7], -r12 */
/* @0x2a5400 eorsle r2, r5, r0, lsl #24 */
/* @0x2a5404 stmdbls r3, {r1, r2, r4, r11, lr} */
/* @0x2a5408 .word 0xf7ff4478 */
/* @0x2a540c .word 0x4605fc56 */
/* @0x2a5410 qadd16mi r11, r0, r8 */
/* @0x2a5414 blx 0xffea3416 <b2_toiTime+0xffffffffff749f72> */
/* @0x2a5418 andvs lr, r4, #40 */
/* @0x2a541c addvs r6, r6, r7, asr #32 */
/* @0x2a5420 stmdavs r3!, {r2, r4, sp} ^ */
/* @0x2a5424 .word 0xf6114358 */
/* @0x2a5428 .word 0x6368e88e */
/* @0x2a542c blls 0x393934 <ft_adobe_glyph_list+0x3010> */
/* @0x2a5430 bls 0x391884 <ft_adobe_glyph_list+0xf60> */
/* @0x2a5434 andsvs r2, r3, lr, lsl #6 */
/* @0x2a5438 .word 0xf7ff4628 */
/* @0x2a543c ands pc, r7, r3, lsr #20 */
/* @0x2a5440 strtmi r6, [r8], -r3, ror #16 */
/* @0x2a5444 ble 0x5f5ec8 <g_SWFaavertbuff+0x22e00> */
/* @0x2a5448 .word 0xf9a2f000 */
/* @0x2a544c ldrb r3, [r7, r1, lsl #14]! */
/* @0x2a5450 andeq r0, r1, r6, lsl r0 */
/* @0x2a5454 andeq r6, lr, r8, ror #28 */
/* @0x2a5458 strdeq r6, r7, [lr], -r8 */
/* @0x2a545c andeq r10, lr, lr, lsr r6 */
/* @0x2a5460 andeq r6, lr, r4, lsl r12 */
/* @0x2a5464 blx 0x7e346a <b2_toiTime+0x89fc6> */
/* @0x2a5468 mvnvs r6, r11, lsr #19 */
/* @0x2a546c and r4, r0, r8, lsr #12 */
/* @0x2a5470 andslt r2, r3, r0 */
/* @0x2a5474 svchi #0xf0e8bd */
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
/* @0x2a555c svcmi #0xf0e92d */
/* @0x2a5560 strmi r11, [pc], -r5, lsl #1 */
/* @0x2a5564 stcls p6, c4, [pc, #-580] */
/* @0x2a5568 stmdahs r0, {r1, r2, r9, r10, lr} */
/* @0x2a556c cmplt r1, r12, rrx */
/* @0x2a5570 bhs 0x2cbdb0 <_ZNK7b2World7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x68> */
/* @0x2a5574 .word 0x1c68db07 */
/* @0x2a5578 .word 0xf1b9db05 */
/* @0x2a557c blle 0x329184 */
/* @0x2a5580 ldrmi r6, [r1, #0xaca] */
/* @0x2a5584 .word 0xf106db06 */
/* @0x2a5588 tsths r2, r12 */
/* @0x2a558c .word 0xf7fe2200 */
/* @0x2a5590 rsb pc, r7, r3, ror #29 */
/* @0x2a5594 streq pc, [r8], #-19 */
/* @0x2a5598 blvs 0x15599cc <b2_toiTime+0xe00528> */
/* @0x2a559c blx 0x2ed9f6 <FT_Done_Memory+0x3d82> */
/* @0x2a55a0 ldmdapl r2, {r0, r3, r8, r12, sp, lr, pc} ^ */
/* @0x2a55a4 bhs 0x2f3db4 <ps_hints_apply+0x29b4> */
/* @0x2a55a8 .word 0xf106d803 */
/* @0x2a55ac mrshs r0, apsr */
/* @0x2a55b0 bls 0x65d61c <g_SWFlinevertbuff+0xa554> */
/* @0x2a55b4 stmdblt r2!, {r0, r2, r3, r6, r8, r12, sp, pc} ^ */
/* @0x2a55b8 .word 0xd10a1c69 */
/* @0x2a55bc strle r0, [r6], #-1754 */
/* @0x2a55c0 stmdaeq r4, {r0, r1, r6, r12, sp, lr, pc} */
/* @0x2a55c4 ldrblo pc, [pc, #0x4f]! */
/* @0x2a55c8 bhs 0x2dd5e4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x284> */
/* @0x2a55cc .word 0xf04fd0f6 */
/* @0x2a55d0 .word 0xf02335ff */
/* @0x2a55d4 eorhs r0, r8, r4, lsl #16 */
/* @0x2a55d8 svc #0xb4f610 */
/* @0x2a55dc ldmdblt r8!, {r2, r9, r10, lr} */
/* @0x2a55e0 andeq pc, r12, r6, lsl #2 */
/* @0x2a55e4 strtmi r2, [r2], -lr, lsl #2 */
/* @0x2a55e8 mrc2 p7, #0x5, apsr_nzcv, c6, c14, #0x7 */
/* @0x2a55ec eors r4, r10, r0, lsr #12 */
/* @0x2a55f0 beq 0x5e1a14 <g_SWFaavertbuff+0xe94c> */
/* @0x2a55f4 bleq 0x3e1a30 <error_g0017+0x3a6d4> */
/* @0x2a55f8 usaxmi r4, r8, r1 */
/* @0x2a55fc mcr2 p7, #0x4, pc, c10, c14, #0x7 */
/* @0x2a5600 .word 0x46494638 */
/* @0x2a5604 stcne p6, c4, [r3, #-264]! */
/* @0x2a5608 .word 0xf844f000 */
/* @0x2a560c blle 0x9ef614 <b2_toiTime+0x296170> */
/* @0x2a5610 .word 0x46494638 */
/* @0x2a5614 .word 0xf7fe4642 */
/* @0x2a5618 .word 0x6020ffb5 */
/* @0x2a561c blls 0x651ce4 <g_SWFaavertbuff+0x7ec1c> */
/* @0x2a5620 eorvs r6, r3, #1342177286 */
/* @0x2a5624 movweq pc, #0x4018 */
/* @0x2a5628 .word 0x61a5d103 */
/* @0x2a562c .word 0x83a36165 */
/* @0x2a5630 stmdbmi lr, {r0, r1, r5, r6, r7, sp, lr} */
/* @0x2a5634 qasxmi r4, r2, r0 */
/* @0x2a5638 .word 0xf0004479 */
/* @0x2a563c strmi pc, [r6], -r6, asr #19 */
/* @0x2a5640 qadd16mi r11, r0, r0 */
/* @0x2a5644 svc #0x8af610 */
/* @0x2a5648 and r4, r12, r0, lsr r6 */
/* @0x2a564c .word 0xf6104620 */
/* @0x2a5650 .word 0xf106ef86 */
/* @0x2a5654 ldrbmi r0, [r1], -r12 */
/* @0x2a5658 mrc2 p7, #0x2, apsr_nzcv, c12, c14, #0x7 */
/* @0x2a565c usaxmi r4, r9, r0 */
/* @0x2a5660 mrc2 p7, #0x2, apsr_nzcv, c8, c14, #0x7 */
/* @0x2a5664 andlt r2, r5, r0 */
/* @0x2a5668 svchi #0xf0e8bd */
/* @0x2a566c .word 0xfffffe3d */
/* @0x2a5670 .word 0x4605b570 */
/* @0x2a5674 sadd16mi r4, lr, r4 */
/* @0x2a5678 .word 0xf9eef7ff */
/* @0x2a567c blle 0x42ce88 <g_RomDisk+0x35668> */
/* @0x2a5680 strtmi r4, [r2], -r8, lsr #12 */
/* @0x2a5684 pop {r0, r1, r4, r5, r9, r10, lr} */
/* @0x2a5688 .word 0xf0004070 */
/* @0x2a568c .word 0xf04fb803 */
/* @0x2a5690 ldcllt p0, c3, [r0, #-1020]! */
/* @0x2a5694 mvnsmi lr, sp, lsr #18 */
/* @0x2a5698 strmi r1, [r5], -lr, lsl #28 */
/* @0x2a569c sadd8mi r4, r12, r0 */
/* @0x2a56a0 .word 0xf105da04 */
/* @0x2a56a4 tsths r2, r12 */
/* @0x2a56a8 eor r2, r0, r0, lsl #4 */
/* @0x2a56ac addsmi r6, lr, #798720 */
/* @0x2a56b0 .word 0xf7ffdaf7 */
/* @0x2a56b4 .word 0x4607f95d */
/* @0x2a56b8 suble r2, pc, r0, lsl #16 */
/* @0x2a56bc stmdaeq r8, {r3, r4, r12, sp, lr, pc} */
/* @0x2a56c0 tsths r4, #24, #2 */
/* @0x2a56c4 cmnmi r3, #107520 */
/* @0x2a56c8 stmpl r11, {r1, r3, r6, r7, r11, r12} ^ */
/* @0x2a56cc blhs 0x2f42dc <ps_hints_apply+0x2edc> */
/* @0x2a56d0 ldmdavs r3, {r4, r11, r12, lr, pc} ^ */
/* @0x2a56d4 andshs r4, r12, #34603008 */
/* @0x2a56d8 .word 0xc000f8d3 */
/* @0x2a56dc movwhs r6, #0x3858 */
/* @0x2a56e0 stmdahs r0, {r5, r6, r7, r8, r9, r10, lr} */
/* @0x2a56e4 .word 0xf105da35 */
/* @0x2a56e8 mrshs r0, apsr */
/* @0x2a56ec .word 0xf7fe4642 */
/* @0x2a56f0 eors pc, r3, r3, lsr lr */
/* @0x2a56f4 bhs 0x2bffa4 <jpeg_idct_ifast+0x150> */
/* @0x2a56f8 ldmdavs r3, {r0, r1, r4, r6, r7, r12, lr, pc} ^ */
/* @0x2a56fc ble 0xff6b617c <b2_toiTime+0xfffffffffef5ccd8> */
/* @0x2a5700 ldmdavs r2, {r2, r3, r4, r5, r8, r9, sp} */
/* @0x2a5704 ldrmi r4, [r10], #-883 */
/* @0x2a5708 .word 0x60a268d2 */
/* @0x2a570c ldmdavs r2, {r1, r3, r5, r9, r11, sp, lr} */
/* @0x2a5710 ldmdbvs r2, {r1, r3, r4, r10, lr} ^ */
/* @0x2a5714 bvs 0xd3dba4 <b2_toiTime+0x5e4700> */
/* @0x2a5718 ldrmi r6, [r10], #-2066 */
/* @0x2a571c smlalvs r6, r2, r2, r8 */
/* @0x2a5720 ldmdavs r2, {r1, r3, r5, r9, r11, sp, lr} */
/* @0x2a5724 ldmdbvs r2, {r1, r3, r4, r10, lr} */
/* @0x2a5728 bvs 0xd3dcb8 <b2_toiTime+0x5e4814> */
/* @0x2a572c ldrmi r6, [r10], #-2066 */
/* @0x2a5730 .word 0x832288d2 */
/* @0x2a5734 ldmdavs r2, {r1, r3, r5, r9, r11, sp, lr} */
/* @0x2a5738 ldmhi r11, {r0, r1, r4, r10, lr} */
/* @0x2a573c andeq pc, r1, #19 */
/* @0x2a5740 ldrbeq sp, [r11], -r6 */
/* @0x2a5744 .word 0xf64fbf4c */
/* @0x2a5748 movwhs r7, #0x13ff */
/* @0x2a574c and r8, r0, r3, ror #6 */
/* @0x2a5750 rsbvs r8, r6, r2, ror #6 */
/* @0x2a5754 eorvs r2, r7, r0 */
/* @0x2a5758 ldrhhi lr, [r0, #141]! */
/* @0x2a575c rscslo pc, pc, pc, asr #32 */
/* @0x2a5760 ldrhhi lr, [r0, #141]! */
/* @0x2a5764 .word 0xf000300c */
/* @0x2a5768 ldrlt r11, [r8, #-0x847]! */

/* ── FUNC 0x2a4971 · zip_get_name · size=8 · insn=0 */

/* ── FUNC 0x2a4979 · _zip_memdup(void const*, unsigned int, zip_error*) · size=42 · insn=0 */

/* ── FUNC 0x2a49a5 · _zip_name_locate(zip*, char const*, int, zip_error*) · size=180 · insn=0 */

/* ── FUNC 0x2a4a59 · zip_name_locate · size=8 · insn=0 */

/* ── FUNC 0x2a4de1 · zip_open · size=960 · insn=0 */

/* ── FUNC 0x2a51a1 · zip_open_buff · size=728 · insn=0 */

/* ── FUNC 0x2a555d · zip_source_zip · size=276 · insn=0 */

/* ── FUNC 0x2a5671 · zip_stat · size=36 · insn=0 */

/* ── FUNC 0x2a5695 · zip_stat_index · size=208 · insn=0 */

/* ── FUNC 0x2a5765 · zip_strerror · size=6 · insn=0 */

/* ── FUNC 0x2a576a · anon_2a576a · size=40 · insn=10 */
/* @0x2a576a .word 0x4604b538 */
/* @0x2a576e strhs r6, [r0, #-0x880] */
/* @0x2a5772 mrc p6, #0x7, apsr_nzcv, c4, c0, #0x0 */
/* @0x2a5776 adcvs r6, r5, r0, ror #17 */
/* @0x2a577a mrc p6, #0x7, apsr_nzcv, c0, c0, #0x0 */
/* @0x2a577e .word 0x33fff04f */
/* @0x2a5782 strtmi r6, [r0], -r5, ror #1 */
/* @0x2a5786 pop {r0, r1, r5, r8, sp, lr} */
/* @0x2a578a .word 0xf0004038 */
/* @0x2a578e ldrlt r11, [r8, #-0x933]! */

/* ── FUNC 0x2a576b · _zip_entry_free(zip_entry*) · size=38 · insn=0 */

/* ── FUNC 0x2a5790 · anon_2a5790 · size=352 · insn=88 */
/* @0x2a5790 .word 0x4604b538 */
/* @0x2a5794 andshs r11, r4, r0, lsr r9 */
/* @0x2a5798 mrc p6, #0x6, apsr_nzcv, c4, c0, #0x0 */
/* @0x2a579c andhs r4, r12, r5, lsl #12 */
/* @0x2a57a0 ldrsb r11, [r0], -sp */
/* @0x2a57a4 bvs 0xff3403b8 <b2_toiTime+0xfffffffffebe6f14> */
/* @0x2a57a8 addmi r1, r10, #1424 */
/* @0x2a57ac tstlo r0, #16, #22 */
/* @0x2a57b0 movwvs r2, #0x3114 */
/* @0x2a57b4 blvs 0x12b6520 <b2_toiTime+0xb5d07c> */
/* @0x2a57b8 b 0x1063004 <b2_toiTime+0x909b60> */
/* @0x2a57bc .word 0x63604605 */
/* @0x2a57c0 .word 0xf104b930 */
/* @0x2a57c4 .word 0x210e000c */
/* @0x2a57c8 .word 0xf7fe462a */
/* @0x2a57cc ands pc, r0, r5, asr #27 */
/* @0x2a57d0 ldrhs r6, [r4, #-0xae2] */
/* @0x2a57d4 blx 0x40056a <g_RomDisk+0x8d4a> */
/* @0x2a57d8 movwhs r3, #0x502 */
/* @0x2a57dc rscslo pc, pc, #79 */
/* @0x2a57e0 adcvs r6, r11, r11, lsr #32 */
/* @0x2a57e4 smulwtvs r10, r11, r0 */
/* @0x2a57e8 tstlt r4, r11, rrx */
/* @0x2a57ec movwlo r6, #0x1ae3 */
/* @0x2a57f0 strtmi r6, [r8], -r3, ror #5 */
/* @0x2a57f4 andeq r11, r0, r8, lsr sp */
/* @0x2a57f8 mvnsmi lr, #737280 */
/* @0x2a57fc ldcmi p0, c11, [r1, #-660]! */
/* @0x2a5800 blmi 0xef7024 <b2_toiTime+0x79db80> */
/* @0x2a5804 stmpl r12!, {r0, r2, r3, r4, r5, r6, r10, lr} ^ */
/* @0x2a5808 strtmi r6, [r1], r3, lsr #16 */
/* @0x2a580c .word 0xf7fe9323 */
/* @0x2a5810 ldmdavs r10!, {r1, r2, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2a5814 blle 0x3b001c <error_g0017+0x8cc0> */
/* @0x2a5818 stmpl r11!, {r2, r3, r5, r8, r9, r11, lr} ^ */
/* @0x2a581c addsmi r6, r10, #1769472 */
/* @0x2a5820 vmlage.f64 d13, d3, d7 */
/* @0x2a5824 strhs r4, [r0], #-2346 */
/* @0x2a5828 ldrbtmi r4, [r9], #-1584 */
/* @0x2a582c mrc p6, #0x4, apsr_nzcv, c0, c0, #0x0 */
/* @0x2a5830 blmi 0xcdd888 <b2_toiTime+0x5843e4> */
/* @0x2a5834 .word 0xf85358eb */
/* @0x2a5838 blmi 0xc758c8 <b2_toiTime+0x51c424> */
/* @0x2a583c .word 0xf85358eb */
/* @0x2a5840 blhs 0x2f18d0 <ps_hints_apply+0x4d0> */
/* @0x2a5844 blhs 0x359860 */
/* @0x2a5848 ldmdavs r8!, {r4, r5, r8, r12, lr, pc} ^ */
/* @0x2a584c bl 0x1de3098 <b2_toiTime+0x1689bf4> */
/* @0x2a5850 ldmdavs r8!, {r1, sp, lr, pc} ^ */
/* @0x2a5854 bl 0x1e630a0 <b2_toiTime+0x1709bfc> */
/* @0x2a5858 teqlt r8, #6291456 */
/* @0x2a585c .word 0xf6104630 */
/* @0x2a5860 strmi lr, [r0], r12, ror #28 */
/* @0x2a5864 strtmi r11, [r0], -r4, lsr #2 */
/* @0x2a5868 mcr p6, #0x3, pc, c6, c0, #0x0 */
/* @0x2a586c and r1, r0, r3, lsl #25 */
/* @0x2a5870 .word 0xf1084623 */
/* @0x2a5874 ldrmi r0, [r8], #-1 */
/* @0x2a5878 mcr p6, #0x3, pc, c4, c0, #0x0 */
/* @0x2a587c ldmdblt r8, {r7, r9, r10, lr} */
/* @0x2a5880 stmpl r11!, {r2, r4, r8, r9, r11, lr} ^ */
/* @0x2a5884 muls r2, r8, r11 */
/* @0x2a5888 bmi 0x7d3d00 <b2_toiTime+0x7a85c> */
/* @0x2a588c ssub16mi r4, r3, r10 */
/* @0x2a5890 blmi 0x79d8a0 <b2_toiTime+0x443fc> */
/* @0x2a5894 ldrbtmi r4, [r11], #-1570 */
/* @0x2a5898 .word 0x46404912 */
/* @0x2a589c ldrbtmi r9, [r9], #-1536 */
/* @0x2a58a0 mrc p6, #0x2, apsr_nzcv, c6, c0, #0x0 */
/* @0x2a58a4 andhi pc, r8, r7, asr #17 */
/* @0x2a58a8 and r4, r0, r0, asr #12 */
/* @0x2a58ac bls 0xb77134 <b2_toiTime+0x41dc90> */
/* @0x2a58b0 .word 0x3000f8d9 */
/* @0x2a58b4 mulle r1, r10, r2 */
/* @0x2a58b8 mcr p6, #0x4, pc, c12, c0, #0x0 */
/* @0x2a58bc pop {r0, r2, r5, r12, sp, pc} */
/* @0x2a58c0 svclt #0x83f0 */
/* @0x2a58c4 andseq r12, r4, r0, asr r4 */
/* @0x2a58c8 .word 0xffffbd00 */
/* @0x2a58cc .word 0xfffffe30 */
/* @0x2a58d0 ldrdeq r6, r7, [lr], -r8 */
/* @0x2a58d4 .word 0xfffffe40 */
/* @0x2a58d8 .word 0xfffffe34 */
/* @0x2a58dc andeq r6, lr, r5, ror r9 */
/* @0x2a58e0 andeq r6, lr, r8, ror #18 */
/* @0x2a58e4 andeq r6, lr, r5, ror r9 */
/* @0x2a58e8 .word 0xf7fe3004 */
/* @0x2a58ec ldrblt r11, [r0, #0xd20]! */

/* ── FUNC 0x2a5791 · _zip_entry_new(zip*) · size=102 · insn=0 */

/* ── FUNC 0x2a57f9 · _zip_error_strerror(zip_error*) · size=240 · insn=0 */
