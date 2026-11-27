/* libyoyo.so 覆盖卡组 0113
 * 函数 0x1742bc..0x1772d0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1742bc · GR_Texture_Set_Priority(int, int) · size=60 · insn=15 */
/* @0x1742bc push {r3, r4, r5, lr} */
/* @0x1742c0 mov r5, r1 */
/* @0x1742c4 mov r4, r0 */
/* @0x1742c8 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1742cc cmp r0, #0 */
/* @0x1742d0 popeq {r3, r4, r5, pc} */
/* @0x1742d4 ldr r3, [pc, #0x18] */
/* @0x1742d8 mov r1, r5 */
/* @0x1742dc ldr r3, [pc, r3] */
/* @0x1742e0 ldr r3, [r3, #0x4] */
/* @0x1742e4 ldr r3, [r3, r4, lsl #2] */
/* @0x1742e8 ldr r0, [r3] */
/* @0x1742ec pop {r3, r4, r5, lr} */
/* @0x1742f0 b 0x1833c8 <_ZN8Graphics18SetTexturePriorityEPvi> */
/* @0x1742f4 eoreq r9, r7, r0, asr #12 */

/* ── FUNC 0x1742f8 · GR_Texture_Set(int) · size=100 · insn=25 */
/* @0x1742f8 push {r4, lr} */
/* @0x1742fc mov r4, r0 */
/* @0x174300 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x174304 ldr r3, [pc, #0x44] */
/* @0x174308 add r3, pc, r3 */
/* @0x17430c subs r1, r0, #0 */
/* @0x174310 bne 0x174328 <_Z14GR_Texture_Seti+0x30> */
/* @0x174314 ldr r2, [pc, #0x38] */
/* @0x174318 pop {r4, lr} */
/* @0x17431c ldr r3, [r3, r2] */
/* @0x174320 ldr r0, [r3] */
/* @0x174324 b 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x174328 ldr r1, [pc, #0x28] */
/* @0x17432c ldr r2, [pc, #0x20] */
/* @0x174330 ldr r1, [r3, r1] */
/* @0x174334 ldr r2, [r3, r2] */
/* @0x174338 ldr r3, [r1, #0x4] */
/* @0x17433c ldr r0, [r2] */
/* @0x174340 ldr r3, [r3, r4, lsl #2] */
/* @0x174344 pop {r4, lr} */
/* @0x174348 ldr r1, [r3] */
/* @0x17434c b 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x174350 eoreq sp, r7, r8, asr #18 */
/* @0x174354 .word 0xffffe4d4 */
/* @0x174358 .word 0xffffbccc */

/* ── FUNC 0x17435c · GR_Texture_Get_Surface(int) · size=48 · insn=12 */
/* @0x17435c push {r4, lr} */
/* @0x174360 mov r4, r0 */
/* @0x174364 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x174368 cmp r0, #0 */
/* @0x17436c popeq {r4, pc} */
/* @0x174370 ldr r3, [pc, #0x10] */
/* @0x174374 ldr r3, [pc, r3] */
/* @0x174378 ldr r3, [r3, #0x4] */
/* @0x17437c ldr r3, [r3, r4, lsl #2] */
/* @0x174380 ldr r0, [r3] */
/* @0x174384 pop {r4, pc} */
/* @0x174388 eoreq r9, r7, r8, lsr #11 */

/* ── FUNC 0x17438c · DrawIt_Color(void*, float, float, float, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int) · size=268 · insn=67 */
/* @0x17438c ldr r12, [pc, #0x100] */
/* @0x174390 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x174394 vpush {d8, d9, d10, d11, d12} */
/* @0x174398 ldr r12, [pc, r12] */
/* @0x17439c vldr s17, [sp, #100] */
/* @0x1743a0 mov r8, r1 */
/* @0x1743a4 mov r7, r2 */
/* @0x1743a8 mov r1, r0 */
/* @0x1743ac mov r11, r3 */
/* @0x1743b0 mov r0, #4 */
/* @0x1743b4 mov r2, #24 */
/* @0x1743b8 mov r3, #6 */
/* @0x1743bc ldr r4, [r12] */
/* @0x1743c0 vldr s16, [sp, #104] */
/* @0x1743c4 vldr s19, [sp, #108] */
/* @0x1743c8 vldr s18, [sp, #112] */
/* @0x1743cc ldr r5, [sp, #0x74] */
/* @0x1743d0 ldr r6, [sp, #0x7c] */
/* @0x1743d4 vldr s21, [sp, #84] */
/* @0x1743d8 vldr s20, [sp, #88] */
/* @0x1743dc ldr r10, [sp, #0x78] */
/* @0x1743e0 ldr r9, [sp, #0x80] */
/* @0x1743e4 vldr s24, [sp, #80] */
/* @0x1743e8 vldr s23, [sp, #92] */
/* @0x1743ec vldr s22, [sp, #96] */
/* @0x1743f0 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1743f4 mov r12, r0 */
/* @0x1743f8 vstr s17, [r12, #16] */
/* @0x1743fc vstr s16, [r12, #20] */
/* @0x174400 vstr s24, [r12, #28] */
/* @0x174404 vstr s19, [r12, #40] */
/* @0x174408 vstr s16, [r12, #44] */
/* @0x17440c vstr s21, [r12, #48] */
/* @0x174410 vstr s20, [r12, #52] */
/* @0x174414 vstr s19, [r12, #64] */
/* @0x174418 vstr s18, [r12, #68] */
/* @0x17441c vstr s21, [r12, #72] */
/* @0x174420 vstr s20, [r12, #76] */
/* @0x174424 vstr s19, [r12, #88] */
/* @0x174428 vstr s18, [r12, #92] */
/* @0x17442c vstr s23, [r12, #96] */
/* @0x174430 vstr s22, [r12, #100] */
/* @0x174434 vstr s17, [r12, #112] */
/* @0x174438 vstr s18, [r12, #116] */
/* @0x17443c str r4, [r12, #0x8] */
/* @0x174440 mov r0, #1 */
/* @0x174444 str r4, [r12, #0x20] */
/* @0x174448 str r4, [r12, #0x38] */
/* @0x17444c str r4, [r12, #0x50] */
/* @0x174450 str r4, [r12, #0x68] */
/* @0x174454 str r4, [r12, #0x80] */
/* @0x174458 str r8, [r12] */
/* @0x17445c str r7, [r12, #0x4] */
/* @0x174460 str r5, [r12, #0xc] */
/* @0x174464 str r11, [r12, #0x18] */
/* @0x174468 str r10, [r12, #0x24] */
/* @0x17446c str r6, [r12, #0x3c] */
/* @0x174470 str r6, [r12, #0x54] */
/* @0x174474 str r9, [r12, #0x6c] */
/* @0x174478 str r8, [r12, #0x78] */
/* @0x17447c str r7, [r12, #0x7c] */
/* @0x174480 str r5, [r12, #0x84] */
/* @0x174484 vstr s17, [r12, #136] */
/* @0x174488 vstr s16, [r12, #140] */
/* @0x17448c vpop {d8, d9, d10, d11, d12} */
/* @0x174490 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x174494 eoreq r9, r7, r8, lsl #11 */

/* ── FUNC 0x174498 · GR_Texture_Draw_Simple(int, float, float) · size=484 · insn=121 */
/* @0x174498 push {r3, r4, r5, r6, r7, lr} */
/* @0x17449c vpush {d8} */
/* @0x1744a0 mov r4, r0 */
/* @0x1744a4 vmov s17, r1 */
/* @0x1744a8 vmov s16, r2 */
/* @0x1744ac bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1744b0 subs r6, r0, #0 */
/* @0x1744b4 bne 0x1744c4 <_Z22GR_Texture_Draw_Simpleiff+0x2c> */
/* @0x1744b8 vpop {d8} */
/* @0x1744bc mov r0, r6 */
/* @0x1744c0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1744c4 ldr r1, [pc, #0x1a4] */
/* @0x1744c8 mov r2, #24 */
/* @0x1744cc mov r3, #6 */
/* @0x1744d0 mov r0, #4 */
/* @0x1744d4 ldr r1, [pc, r1] */
/* @0x1744d8 ldr r1, [r1, #0x4] */
/* @0x1744dc ldr r5, [r1, r4, lsl #2] */
/* @0x1744e0 ldr r1, [r5] */
/* @0x1744e4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1744e8 ldrsh r3, [r5, #4] */
/* @0x1744ec vmov s14, r3 */
/* @0x1744f0 ldrsh r3, [r5, #6] */
/* @0x1744f4 vcvt.f32.s32 s14, s14 */
/* @0x1744f8 vmov s15, r3 */
/* @0x1744fc vcvt.f32.s32 s15, s15 */
/* @0x174500 vstr s17, [r0] */
/* @0x174504 vstr s17, [r0, #120] */
/* @0x174508 vstr s17, [r0, #96] */
/* @0x17450c vstr s16, [r0, #28] */
/* @0x174510 vadd.f32 s17, s14, s17 */
/* @0x174514 vstr s16, [r0, #4] */
/* @0x174518 vstr s16, [r0, #124] */
/* @0x17451c mov r4, r0 */
/* @0x174520 vadd.f32 s16, s15, s16 */
/* @0x174524 vstr s17, [r0, #48] */
/* @0x174528 vstr s17, [r0, #72] */
/* @0x17452c vstr s17, [r0, #24] */
/* @0x174530 vstr s16, [r0, #100] */
/* @0x174534 vstr s16, [r0, #52] */
/* @0x174538 vstr s16, [r0, #76] */
/* @0x17453c bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x174540 vldr s15, [pc, #292] */
/* @0x174544 vmov s14, r0 */
/* @0x174548 vmul.f32 s15, s14, s15 */
/* @0x17454c vcvt.s32.f32 s15, s15 */
/* @0x174550 vmov r3, s15 */
/* @0x174554 cmp r3, #255 */
/* @0x174558 mvngt r0, #0 */
/* @0x17455c movgt r7, #-16777216 */
/* @0x174560 ble 0x174650 <_Z22GR_Texture_Draw_Simpleiff+0x1b8> */
/* @0x174564 ldr r3, [pc, #0x108] */
/* @0x174568 ldr r3, [pc, r3] */
/* @0x17456c ldrb r2, [r3] */
/* @0x174570 cmp r2, #0 */
/* @0x174574 bne 0x174628 <_Z22GR_Texture_Draw_Simpleiff+0x190> */
/* @0x174578 mov r2, r0 */
/* @0x17457c mov r12, r0 */
/* @0x174580 mov r1, r0 */
/* @0x174584 mov r3, #0 */
/* @0x174588 str r3, [r4, #0x70] */
/* @0x17458c str r3, [r4, #0x10] */
/* @0x174590 str r3, [r4, #0x88] */
/* @0x174594 str r3, [r4, #0x2c] */
/* @0x174598 str r3, [r4, #0x14] */
/* @0x17459c str r3, [r4, #0x8c] */
/* @0x1745a0 vldr s14, [r5, #8] */
/* @0x1745a4 ldrsh r3, [r5, #4] */
/* @0x1745a8 str r0, [r4, #0x6c] */
/* @0x1745ac mov r0, r6 */
/* @0x1745b0 str r1, [r4, #0xc] */
/* @0x1745b4 vmov s15, r3 */
/* @0x1745b8 ldr r3, [pc, #0xb8] */
/* @0x1745bc str r1, [r4, #0x84] */
/* @0x1745c0 vcvt.f32.s32 s15, s15 */
/* @0x1745c4 ldr r3, [pc, r3] */
/* @0x1745c8 str r12, [r4, #0x24] */
/* @0x1745cc ldr r3, [r3] */
/* @0x1745d0 str r2, [r4, #0x3c] */
/* @0x1745d4 str r2, [r4, #0x54] */
/* @0x1745d8 str r3, [r4, #0x80] */
/* @0x1745dc str r3, [r4, #0x68] */
/* @0x1745e0 vmul.f32 s15, s15, s14 */
/* @0x1745e4 str r3, [r4, #0x50] */
/* @0x1745e8 str r3, [r4, #0x38] */
/* @0x1745ec str r3, [r4, #0x20] */
/* @0x1745f0 str r3, [r4, #0x8] */
/* @0x1745f4 vstr s15, [r4, #64] */
/* @0x1745f8 vstr s15, [r4, #88] */
/* @0x1745fc vstr s15, [r4, #40] */
/* @0x174600 ldrsh r3, [r5, #6] */
/* @0x174604 vldr s14, [r5, #12] */
/* @0x174608 vmov s15, r3 */
/* @0x17460c vcvt.f32.s32 s15, s15 */
/* @0x174610 vmul.f32 s15, s15, s14 */
/* @0x174614 vstr s15, [r4, #116] */
/* @0x174618 vstr s15, [r4, #68] */
/* @0x17461c vstr s15, [r4, #92] */
/* @0x174620 vpop {d8} */
/* @0x174624 pop {r3, r4, r5, r6, r7, pc} */
/* @0x174628 movw r1, #0xfffe */
/* @0x17462c movw r12, #0xffff */
/* @0x174630 movt r1, #0xfe */
/* @0x174634 movt r12, #0xfe */
/* @0x174638 movw r2, #0xfffe */
/* @0x17463c movt r2, #0xff */
/* @0x174640 orr r1, r7, r1 */
/* @0x174644 orr r12, r7, r12 */
/* @0x174648 orr r2, r7, r2 */
/* @0x17464c b 0x174584 <_Z22GR_Texture_Draw_Simpleiff+0xec> */
/* @0x174650 cmp r3, #0 */
/* @0x174654 lslge r7, r3, #24 */
/* @0x174658 mvnlt r0, #-16777216 */
/* @0x17465c movlt r7, #0 */
/* @0x174660 mvnge r0, r7, lsr #24 */
/* @0x174664 mvnge r0, r0, lsl #24 */
/* @0x174668 b 0x174564 <_Z22GR_Texture_Draw_Simpleiff+0xcc> */
/* @0x17466c cmnmi pc, #0 */
/* @0x174670 eoreq r9, r7, r8, asr #8 */
/* @0x174674 eoreq r9, r7, r4, ror #17 */
/* @0x174678 eoreq r9, r7, r12, asr r3 */

/* ── FUNC 0x17467c · GR_Texture_Draw_Pos(YYTPageEntry*, float, float, float, float, float, float, float, float, unsigned int, float) · size=492 · insn=123 */
/* @0x17467c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x174680 subs r4, r0, #0 */
/* @0x174684 mov r7, r1 */
/* @0x174688 mov r6, r2 */
/* @0x17468c mov r8, r3 */
/* @0x174690 beq 0x1746a4 <_Z19GR_Texture_Draw_PosP12YYTPageEntryffffffffjf+0x28> */
/* @0x174694 ldrsh r0, [r4, #20] */
/* @0x174698 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x17469c subs r5, r0, #0 */
/* @0x1746a0 bne 0x1746b0 <_Z19GR_Texture_Draw_PosP12YYTPageEntryffffffffjf+0x34> */
/* @0x1746a4 mov r5, #0 */
/* @0x1746a8 mov r0, r5 */
/* @0x1746ac pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1746b0 ldr r1, [pc, #0x1a4] */
/* @0x1746b4 mov r0, #4 */
/* @0x1746b8 ldrsh r12, [r4, #20] */
/* @0x1746bc mov r2, #24 */
/* @0x1746c0 ldr r1, [pc, r1] */
/* @0x1746c4 mov r3, #6 */
/* @0x1746c8 ldr r1, [r1, #0x4] */
/* @0x1746cc ldr r9, [r1, r12, lsl #2] */
/* @0x1746d0 ldr r1, [r9] */
/* @0x1746d4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1746d8 vldr s15, [pc, #376] */
/* @0x1746dc vldr s14, [sp, #64] */
/* @0x1746e0 vmul.f32 s15, s14, s15 */
/* @0x1746e4 vcvt.s32.f32 s15, s15 */
/* @0x1746e8 mov r12, r0 */
/* @0x1746ec vmov r0, s15 */
/* @0x1746f0 cmp r0, #255 */
/* @0x1746f4 movgt r0, #-16777216 */
/* @0x1746f8 ble 0x174848 <_Z19GR_Texture_Draw_PosP12YYTPageEntryffffffffjf+0x1cc> */
/* @0x1746fc ldrsh r11, [r4] */
/* @0x174700 vldr s11, [r9, #8] */
/* @0x174704 ldr r3, [pc, #0x154] */
/* @0x174708 ldr r1, [sp, #0x3c] */
/* @0x17470c vmov s14, r11 */
/* @0x174710 ldr r3, [pc, r3] */
/* @0x174714 bic r2, r1, #-16777216 */
/* @0x174718 str r6, [r12, #0x4] */
/* @0x17471c vcvt.f32.s32 s15, s14 */
/* @0x174720 ldrb r3, [r3] */
/* @0x174724 orr r0, r0, r2 */
/* @0x174728 vldr s14, [sp, #40] */
/* @0x17472c cmp r3, #0 */
/* @0x174730 ldr r3, [pc, #0x12c] */
/* @0x174734 bicne r0, r0, #65536 */
/* @0x174738 vstr s14, [r12, #28] */
/* @0x17473c ldr r3, [pc, r3] */
/* @0x174740 bicne r0, r0, #1 */
/* @0x174744 orrne r2, r0, #65536 */
/* @0x174748 moveq r2, r0 */
/* @0x17474c ldr r3, [r3] */
/* @0x174750 vldr s14, [sp, #44] */
/* @0x174754 vmul.f32 s15, s15, s11 */
/* @0x174758 orrne r10, r0, #1 */
/* @0x17475c orrne r1, r2, #1 */
/* @0x174760 moveq r1, r0 */
/* @0x174764 moveq r10, r0 */
/* @0x174768 vstr s14, [r12, #48] */
/* @0x17476c str r0, [r12, #0xc] */
/* @0x174770 vldr s14, [sp, #48] */
/* @0x174774 str r0, [r12, #0x84] */
/* @0x174778 vstr s14, [r12, #52] */
/* @0x17477c str r2, [r12, #0x3c] */
/* @0x174780 vldr s14, [sp, #44] */
/* @0x174784 str r3, [r12, #0x68] */
/* @0x174788 vstr s14, [r12, #72] */
/* @0x17478c str r2, [r12, #0x54] */
/* @0x174790 vldr s14, [sp, #48] */
/* @0x174794 str r3, [r12, #0x38] */
/* @0x174798 vstr s14, [r12, #76] */
/* @0x17479c str r7, [r12] */
/* @0x1747a0 vldr s14, [sp, #52] */
/* @0x1747a4 str r8, [r12, #0x18] */
/* @0x1747a8 vstr s14, [r12, #96] */
/* @0x1747ac str r7, [r12, #0x78] */
/* @0x1747b0 vldr s14, [sp, #56] */
/* @0x1747b4 str r6, [r12, #0x7c] */
/* @0x1747b8 vstr s14, [r12, #100] */
/* @0x1747bc str r10, [r12, #0x24] */
/* @0x1747c0 mov r0, r5 */
/* @0x1747c4 str r1, [r12, #0x6c] */
/* @0x1747c8 vstr s15, [r12, #112] */
/* @0x1747cc vstr s15, [r12, #16] */
/* @0x1747d0 vstr s15, [r12, #136] */
/* @0x1747d4 str r3, [r12, #0x50] */
/* @0x1747d8 vldr s12, [r9, #12] */
/* @0x1747dc str r3, [r12, #0x20] */
/* @0x1747e0 str r3, [r12, #0x8] */
/* @0x1747e4 str r3, [r12, #0x80] */
/* @0x1747e8 ldrsh r3, [r4, #2] */
/* @0x1747ec vmov s15, r3 */
/* @0x1747f0 vcvt.f32.s32 s13, s15 */
/* @0x1747f4 vmul.f32 s13, s13, s12 */
/* @0x1747f8 vstr s13, [r12, #44] */
/* @0x1747fc vstr s13, [r12, #20] */
/* @0x174800 vstr s13, [r12, #140] */
/* @0x174804 ldrsh r2, [r4, #4] */
/* @0x174808 add r2, r11, r2 */
/* @0x17480c vmov s14, r2 */
/* @0x174810 vcvt.f32.s32 s14, s14 */
/* @0x174814 vmul.f32 s14, s11, s14 */
/* @0x174818 vstr s14, [r12, #64] */
/* @0x17481c vstr s14, [r12, #88] */
/* @0x174820 vstr s14, [r12, #40] */
/* @0x174824 ldrsh r2, [r4, #6] */
/* @0x174828 add r2, r3, r2 */
/* @0x17482c vmov s15, r2 */
/* @0x174830 vcvt.f32.s32 s15, s15 */
/* @0x174834 vmul.f32 s15, s12, s15 */
/* @0x174838 vstr s15, [r12, #116] */
/* @0x17483c vstr s15, [r12, #68] */
/* @0x174840 vstr s15, [r12, #92] */
/* @0x174844 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x174848 cmp r0, #0 */
/* @0x17484c lslge r0, r0, #24 */
/* @0x174850 movlt r0, #0 */
/* @0x174854 b 0x1746fc <_Z19GR_Texture_Draw_PosP12YYTPageEntryffffffffjf+0x80> */
/* @0x174858 cmnmi pc, #0 */
/* @0x17485c eoreq r9, r7, r12, asr r2 */
/* @0x174860 eoreq r9, r7, r12, lsr r7 */
/* @0x174864 eoreq r9, r7, r4, ror #3 */

/* ── FUNC 0x174868 · GR_Texture_Draw_Simple(YYTPageEntry*, float, float) · size=624 · insn=156 */
/* @0x174868 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x17486c vpush {d8} */
/* @0x174870 subs r5, r0, #0 */
/* @0x174874 vmov s17, r1 */
/* @0x174878 vmov s16, r2 */
/* @0x17487c beq 0x174890 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff+0x28> */
/* @0x174880 ldrsh r0, [r5, #20] */
/* @0x174884 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x174888 subs r6, r0, #0 */
/* @0x17488c bne 0x1748a0 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff+0x38> */
/* @0x174890 vpop {d8} */
/* @0x174894 mov r6, #0 */
/* @0x174898 mov r0, r6 */
/* @0x17489c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1748a0 ldr r1, [pc, #0x224] */
/* @0x1748a4 mov r3, #6 */
/* @0x1748a8 ldrsh r12, [r5, #20] */
/* @0x1748ac mov r2, #24 */
/* @0x1748b0 ldr r1, [pc, r1] */
/* @0x1748b4 mov r0, #4 */
/* @0x1748b8 ldr r1, [r1, #0x4] */
/* @0x1748bc ldr r7, [r1, r12, lsl #2] */
/* @0x1748c0 ldr r1, [r7] */
/* @0x1748c4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1748c8 mov r4, r0 */
/* @0x1748cc bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x1748d0 vldr s15, [pc, #496] */
/* @0x1748d4 vmov s14, r0 */
/* @0x1748d8 vmul.f32 s15, s14, s15 */
/* @0x1748dc vcvt.s32.f32 s15, s15 */
/* @0x1748e0 vmov r3, s15 */
/* @0x1748e4 cmp r3, #255 */
/* @0x1748e8 mvngt r1, #0 */
/* @0x1748ec movgt r0, #-16777216 */
/* @0x1748f0 ble 0x174aac <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff+0x244> */
/* @0x1748f4 ldr r3, [pc, #0x1d4] */
/* @0x1748f8 ldr r3, [pc, r3] */
/* @0x1748fc ldrb r2, [r3] */
/* @0x174900 cmp r2, #0 */
/* @0x174904 bne 0x174a84 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff+0x21c> */
/* @0x174908 mov r2, r1 */
/* @0x17490c mov r12, r1 */
/* @0x174910 mov r3, r1 */
/* @0x174914 ldrsh r8, [r5, #10] */
/* @0x174918 vldr s9, [r7, #8] */
/* @0x17491c ldrsh r9, [r5, #8] */
/* @0x174920 rsb r8, r8, #0 */
/* @0x174924 ldrh r0, [r5, #12] */
/* @0x174928 rsb r9, r9, #0 */
/* @0x17492c vmov s14, r8 */
/* @0x174930 ldrsh r8, [r5] */
/* @0x174934 vmov s15, r9 */
/* @0x174938 cmp r0, #0 */
/* @0x17493c vcvt.f32.s32 s8, s14 */
/* @0x174940 sxthne r0, r0 */
/* @0x174944 vmov s14, r8 */
/* @0x174948 moveq r0, #1 */
/* @0x17494c vmovne s11, r0 */
/* @0x174950 strheq r0, [r5, #12] */
/* @0x174954 ldrh r0, [r5, #14] */
/* @0x174958 vcvt.f32.s32 s7, s15 */
/* @0x17495c vcvt.f32.s32 s15, s14 */
/* @0x174960 vmul.f32 s15, s15, s9 */
/* @0x174964 vcvtne.f32.s32 s11, s11 */
/* @0x174968 vmoveq.f32 s11, #1.000000e+00 */
/* @0x17496c cmp r0, #0 */
/* @0x174970 sxthne r0, r0 */
/* @0x174974 moveq r0, #1 */
/* @0x174978 strheq r0, [r5, #14] */
/* @0x17497c vmovne s12, r0 */
/* @0x174980 ldr r0, [pc, #0x14c] */
/* @0x174984 str r3, [r4, #0xc] */
/* @0x174988 vstr s15, [r4, #112] */
/* @0x17498c ldr r0, [pc, r0] */
/* @0x174990 str r3, [r4, #0x84] */
/* @0x174994 vstr s15, [r4, #16] */
/* @0x174998 vstr s15, [r4, #136] */
/* @0x17499c ldr r3, [r0] */
/* @0x1749a0 vldr s10, [r7, #12] */
/* @0x1749a4 str r2, [r4, #0x3c] */
/* @0x1749a8 mov r0, r6 */
/* @0x1749ac str r2, [r4, #0x54] */
/* @0x1749b0 vmoveq.f32 s12, #1.000000e+00 */
/* @0x1749b4 str r3, [r4, #0x68] */
/* @0x1749b8 str r3, [r4, #0x38] */
/* @0x1749bc str r3, [r4, #0x50] */
/* @0x1749c0 str r3, [r4, #0x20] */
/* @0x1749c4 str r3, [r4, #0x8] */
/* @0x1749c8 str r3, [r4, #0x80] */
/* @0x1749cc ldrsh r3, [r5, #2] */
/* @0x1749d0 str r12, [r4, #0x24] */
/* @0x1749d4 str r1, [r4, #0x6c] */
/* @0x1749d8 vmov s15, r3 */
/* @0x1749dc vcvtne.f32.s32 s12, s12 */
/* @0x1749e0 vsub.f32 s11, s11, s7 */
/* @0x1749e4 vsub.f32 s12, s12, s8 */
/* @0x1749e8 vcvt.f32.s32 s13, s15 */
/* @0x1749ec vmul.f32 s13, s13, s10 */
/* @0x1749f0 vadd.f32 s11, s17, s11 */
/* @0x1749f4 vadd.f32 s12, s16, s12 */
/* @0x1749f8 vstr s11, [r4, #48] */
/* @0x1749fc vstr s11, [r4, #72] */
/* @0x174a00 vstr s11, [r4, #24] */
/* @0x174a04 vsub.f32 s17, s17, s7 */
/* @0x174a08 vstr s12, [r4, #100] */
/* @0x174a0c vstr s12, [r4, #52] */
/* @0x174a10 vstr s12, [r4, #76] */
/* @0x174a14 vstr s17, [r4] */
/* @0x174a18 vstr s13, [r4, #44] */
/* @0x174a1c vstr s13, [r4, #20] */
/* @0x174a20 vstr s13, [r4, #140] */
/* @0x174a24 ldrsh r2, [r5, #4] */
/* @0x174a28 vsub.f32 s16, s16, s8 */
/* @0x174a2c vstr s17, [r4, #120] */
/* @0x174a30 vstr s17, [r4, #96] */
/* @0x174a34 add r2, r8, r2 */
/* @0x174a38 vmov s14, r2 */
/* @0x174a3c vcvt.f32.s32 s14, s14 */
/* @0x174a40 vstr s16, [r4, #28] */
/* @0x174a44 vstr s16, [r4, #4] */
/* @0x174a48 vstr s16, [r4, #124] */
/* @0x174a4c vmul.f32 s14, s9, s14 */
/* @0x174a50 vstr s14, [r4, #64] */
/* @0x174a54 vstr s14, [r4, #88] */
/* @0x174a58 vstr s14, [r4, #40] */
/* @0x174a5c ldrsh r2, [r5, #6] */
/* @0x174a60 add r2, r3, r2 */
/* @0x174a64 vmov s15, r2 */
/* @0x174a68 vcvt.f32.s32 s15, s15 */
/* @0x174a6c vmul.f32 s15, s10, s15 */
/* @0x174a70 vstr s15, [r4, #116] */
/* @0x174a74 vstr s15, [r4, #68] */
/* @0x174a78 vstr s15, [r4, #92] */
/* @0x174a7c vpop {d8} */
/* @0x174a80 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x174a84 movw r3, #0xfffe */
/* @0x174a88 movw r12, #0xffff */
/* @0x174a8c movt r3, #0xfe */
/* @0x174a90 movt r12, #0xfe */
/* @0x174a94 movw r2, #0xfffe */
/* @0x174a98 movt r2, #0xff */
/* @0x174a9c orr r3, r0, r3 */
/* @0x174aa0 orr r12, r0, r12 */
/* @0x174aa4 orr r2, r0, r2 */
/* @0x174aa8 b 0x174914 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff+0xac> */
/* @0x174aac cmp r3, #0 */
/* @0x174ab0 lslge r0, r3, #24 */
/* @0x174ab4 mvnlt r1, #-16777216 */
/* @0x174ab8 movlt r0, #0 */
/* @0x174abc mvnge r1, r0, lsr #24 */
/* @0x174ac0 mvnge r1, r1, lsl #24 */
/* @0x174ac4 b 0x1748f4 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff+0x8c> */
/* @0x174ac8 cmnmi pc, #0 */
/* @0x174acc eoreq r9, r7, r12, rrx */
/* @0x174ad0 eoreq r9, r7, r4, asr r5 */
/* @0x174ad4 mlaeq r7, r4, pc, r8 */

/* ── FUNC 0x174ad8 · GR_Texture_Draw_Stretched(int, float, float, float, float, unsigned int, float) · size=360 · insn=90 */
/* @0x174ad8 push {r4, r5, r6, lr} */
/* @0x174adc vpush {d8, d9} */
/* @0x174ae0 mov r4, r0 */
/* @0x174ae4 vmov s17, r1 */
/* @0x174ae8 vmov s16, r2 */
/* @0x174aec vmov s18, r3 */
/* @0x174af0 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x174af4 subs r6, r0, #0 */
/* @0x174af8 beq 0x174c18 <_Z25GR_Texture_Draw_Stretchediffffjf+0x140> */
/* @0x174afc vldr s15, [pc, #304] */
/* @0x174b00 vldr s14, [sp, #40] */
/* @0x174b04 vmul.f32 s15, s14, s15 */
/* @0x174b08 vcvt.s32.f32 s15, s15 */
/* @0x174b0c vmov r5, s15 */
/* @0x174b10 cmp r5, #255 */
/* @0x174b14 movgt r5, #-16777216 */
/* @0x174b18 ble 0x174c24 <_Z25GR_Texture_Draw_Stretchediffffjf+0x14c> */
/* @0x174b1c ldr r1, [pc, #0x114] */
/* @0x174b20 mov r2, #24 */
/* @0x174b24 ldr r3, [sp, #0x24] */
/* @0x174b28 mov r0, #4 */
/* @0x174b2c ldr r1, [pc, r1] */
/* @0x174b30 bic r12, r3, #-16777216 */
/* @0x174b34 mov r3, #6 */
/* @0x174b38 ldr r1, [r1, #0x4] */
/* @0x174b3c orr r5, r5, r12 */
/* @0x174b40 ldr r4, [r1, r4, lsl #2] */
/* @0x174b44 ldr r1, [r4] */
/* @0x174b48 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x174b4c mov r2, #0 */
/* @0x174b50 vadd.f32 s14, s17, s18 */
/* @0x174b54 str r2, [r0, #0x88] */
/* @0x174b58 str r2, [r0, #0x70] */
/* @0x174b5c str r2, [r0, #0x10] */
/* @0x174b60 str r2, [r0, #0x8c] */
/* @0x174b64 str r2, [r0, #0x2c] */
/* @0x174b68 str r2, [r0, #0x14] */
/* @0x174b6c vldr s13, [r4, #8] */
/* @0x174b70 ldrsh r12, [r4, #4] */
/* @0x174b74 vstr s16, [r0, #124] */
/* @0x174b78 vstr s16, [r0, #28] */
/* @0x174b7c vstr s16, [r0, #4] */
/* @0x174b80 vstr s14, [r0, #72] */
/* @0x174b84 vstr s14, [r0, #48] */
/* @0x174b88 vmov s15, r12 */
/* @0x174b8c vstr s14, [r0, #24] */
/* @0x174b90 vldr s14, [sp, #32] */
/* @0x174b94 vadd.f32 s16, s16, s14 */
/* @0x174b98 ldr r2, [pc, #0x9c] */
/* @0x174b9c vstr s17, [r0, #120] */
/* @0x174ba0 str r5, [r0, #0x54] */
/* @0x174ba4 vstr s17, [r0, #96] */
/* @0x174ba8 ldr r2, [pc, r2] */
/* @0x174bac str r5, [r0, #0x3c] */
/* @0x174bb0 vstr s17, [r0] */
/* @0x174bb4 str r5, [r0, #0x24] */
/* @0x174bb8 ldr r2, [r2] */
/* @0x174bbc str r5, [r0, #0xc] */
/* @0x174bc0 str r2, [r0, #0x80] */
/* @0x174bc4 str r2, [r0, #0x68] */
/* @0x174bc8 vcvt.f32.s32 s15, s15 */
/* @0x174bcc str r2, [r0, #0x50] */
/* @0x174bd0 str r2, [r0, #0x38] */
/* @0x174bd4 vstr s16, [r0, #100] */
/* @0x174bd8 str r2, [r0, #0x20] */
/* @0x174bdc vstr s16, [r0, #76] */
/* @0x174be0 str r2, [r0, #0x8] */
/* @0x174be4 vmul.f32 s15, s15, s13 */
/* @0x174be8 vstr s15, [r0, #88] */
/* @0x174bec vstr s16, [r0, #52] */
/* @0x174bf0 vstr s15, [r0, #64] */
/* @0x174bf4 vstr s15, [r0, #40] */
/* @0x174bf8 ldrsh r3, [r4, #6] */
/* @0x174bfc vldr s14, [r4, #12] */
/* @0x174c00 vmov s15, r3 */
/* @0x174c04 vcvt.f32.s32 s15, s15 */
/* @0x174c08 vmul.f32 s15, s15, s14 */
/* @0x174c0c vstr s15, [r0, #116] */
/* @0x174c10 vstr s15, [r0, #92] */
/* @0x174c14 vstr s15, [r0, #68] */
/* @0x174c18 vpop {d8, d9} */
/* @0x174c1c mov r0, r6 */
/* @0x174c20 pop {r4, r5, r6, pc} */
/* @0x174c24 cmp r5, #0 */
/* @0x174c28 lslge r5, r5, #24 */
/* @0x174c2c movlt r5, #0 */
/* @0x174c30 b 0x174b1c <_Z25GR_Texture_Draw_Stretchediffffjf+0x44> */
/* @0x174c34 cmnmi pc, #0 */
/* @0x174c38 .word 0x00278df0 */
/* @0x174c3c eoreq r8, r7, r8, ror sp */

/* ── FUNC 0x174c40 · GR_Texture_Draw(int, float, float, float, float, float, float, float, unsigned int, float) · size=672 · insn=168 */
/* @0x174c40 push {r3, r4, r5, r6, r7, lr} */
/* @0x174c44 vpush {d8, d9, d10, d11} */
/* @0x174c48 mov r4, r0 */
/* @0x174c4c vldr s17, [sp, #56] */
/* @0x174c50 vmov s22, r1 */
/* @0x174c54 vldr s20, [sp, #60] */
/* @0x174c58 vmov s21, r2 */
/* @0x174c5c vldr s19, [sp, #64] */
/* @0x174c60 vmov s16, r3 */
/* @0x174c64 vldr s18, [sp, #68] */
/* @0x174c68 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x174c6c subs r7, r0, #0 */
/* @0x174c70 beq 0x174df8 <_Z15GR_Texture_Drawifffffffjf+0x1b8> */
/* @0x174c74 vldr s15, [pc, #596] */
/* @0x174c78 vldr s13, [sp, #76] */
/* @0x174c7c vmul.f32 s15, s13, s15 */
/* @0x174c80 vcvt.s32.f32 s15, s15 */
/* @0x174c84 vmov r6, s15 */
/* @0x174c88 cmp r6, #255 */
/* @0x174c8c movgt r6, #-16777216 */
/* @0x174c90 ble 0x174e04 <_Z15GR_Texture_Drawifffffffjf+0x1c4> */
/* @0x174c94 ldr r3, [pc, #0x23c] */
/* @0x174c98 ldr r1, [sp, #0x48] */
/* @0x174c9c ldr r3, [pc, r3] */
/* @0x174ca0 bic r2, r1, #-16777216 */
/* @0x174ca4 ldr r3, [r3, #0x4] */
/* @0x174ca8 orr r6, r6, r2 */
/* @0x174cac ldr r5, [r3, r4, lsl #2] */
/* @0x174cb0 ldrh r3, [r5, #6] */
/* @0x174cb4 cmp r3, #0 */
/* @0x174cb8 bne 0x174e14 <_Z15GR_Texture_Drawifffffffjf+0x1d4> */
/* @0x174cbc vmov.f32 s15, #8.000000e+00 */
/* @0x174cc0 mov r3, #8 */
/* @0x174cc4 strh r3, [r5, #4] */
/* @0x174cc8 strh r3, [r5, #6] */
/* @0x174ccc mov r3, #1040187392 */
/* @0x174cd0 str r3, [r5, #0xc] */
/* @0x174cd4 str r3, [r5, #0x8] */
/* @0x174cd8 vmov.f32 s14, s15 */
/* @0x174cdc mov r0, #4 */
/* @0x174ce0 ldr r1, [r5] */
/* @0x174ce4 mov r2, #24 */
/* @0x174ce8 mov r3, #6 */
/* @0x174cec vnmul.f32 s22, s20, s22 */
/* @0x174cf0 vnmul.f32 s21, s19, s21 */
/* @0x174cf4 vmov.f32 s23, s22 */
/* @0x174cf8 vmla.f32 s23, s20, s14 */
/* @0x174cfc vmov.f32 s20, s21 */
/* @0x174d00 vmla.f32 s20, s19, s15 */
/* @0x174d04 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x174d08 vldr s15, [pc, #452] */
/* @0x174d0c vabs.f32 s14, s18 */
/* @0x174d10 vcmpe.f32 s14, s15 */
/* @0x174d14 vmrs APSR_nzcv, fpscr */
/* @0x174d18 mov r4, r0 */
/* @0x174d1c bpl 0x174e3c <_Z15GR_Texture_Drawifffffffjf+0x1fc> */
/* @0x174d20 vadd.f32 s22, s16, s22 */
/* @0x174d24 vadd.f32 s21, s17, s21 */
/* @0x174d28 vstr s22, [r0] */
/* @0x174d2c vstr s22, [r0, #120] */
/* @0x174d30 vstr s22, [r0, #96] */
/* @0x174d34 vadd.f32 s16, s16, s23 */
/* @0x174d38 vstr s21, [r0, #28] */
/* @0x174d3c vstr s21, [r0, #4] */
/* @0x174d40 vstr s21, [r0, #124] */
/* @0x174d44 vadd.f32 s17, s17, s20 */
/* @0x174d48 vstr s16, [r0, #48] */
/* @0x174d4c vstr s16, [r0, #72] */
/* @0x174d50 vstr s16, [r0, #24] */
/* @0x174d54 vstr s17, [r0, #100] */
/* @0x174d58 vstr s17, [r0, #52] */
/* @0x174d5c vstr s17, [r0, #76] */
/* @0x174d60 mov r3, #0 */
/* @0x174d64 str r3, [r4, #0x70] */
/* @0x174d68 str r3, [r4, #0x10] */
/* @0x174d6c str r3, [r4, #0x88] */
/* @0x174d70 str r3, [r4, #0x2c] */
/* @0x174d74 str r3, [r4, #0x14] */
/* @0x174d78 str r3, [r4, #0x8c] */
/* @0x174d7c vldr s14, [r5, #8] */
/* @0x174d80 ldrsh r1, [r5, #4] */
/* @0x174d84 ldr r3, [pc, #0x150] */
/* @0x174d88 str r6, [r4, #0x84] */
/* @0x174d8c vmov s15, r1 */
/* @0x174d90 ldr r3, [pc, r3] */
/* @0x174d94 str r6, [r4, #0x6c] */
/* @0x174d98 vcvt.f32.s32 s15, s15 */
/* @0x174d9c ldr r3, [r3] */
/* @0x174da0 str r6, [r4, #0x54] */
/* @0x174da4 str r6, [r4, #0x3c] */
/* @0x174da8 str r3, [r4, #0x80] */
/* @0x174dac str r3, [r4, #0x68] */
/* @0x174db0 str r3, [r4, #0x50] */
/* @0x174db4 str r3, [r4, #0x38] */
/* @0x174db8 vmul.f32 s15, s15, s14 */
/* @0x174dbc str r3, [r4, #0x20] */
/* @0x174dc0 str r3, [r4, #0x8] */
/* @0x174dc4 str r6, [r4, #0x24] */
/* @0x174dc8 str r6, [r4, #0xc] */
/* @0x174dcc vstr s15, [r4, #64] */
/* @0x174dd0 vstr s15, [r4, #88] */
/* @0x174dd4 vstr s15, [r4, #40] */
/* @0x174dd8 ldrsh r3, [r5, #6] */
/* @0x174ddc vldr s14, [r5, #12] */
/* @0x174de0 vmov s15, r3 */
/* @0x174de4 vcvt.f32.s32 s15, s15 */
/* @0x174de8 vmul.f32 s15, s15, s14 */
/* @0x174dec vstr s15, [r4, #116] */
/* @0x174df0 vstr s15, [r4, #68] */
/* @0x174df4 vstr s15, [r4, #92] */
/* @0x174df8 vpop {d8, d9, d10, d11} */
/* @0x174dfc mov r0, r7 */
/* @0x174e00 pop {r3, r4, r5, r6, r7, pc} */
/* @0x174e04 cmp r6, #0 */
/* @0x174e08 lslge r6, r6, #24 */
/* @0x174e0c movlt r6, #0 */
/* @0x174e10 b 0x174c94 <_Z15GR_Texture_Drawifffffffjf+0x54> */
/* @0x174e14 ldrh r2, [r5, #4] */
/* @0x174e18 cmp r2, #0 */
/* @0x174e1c beq 0x174cbc <_Z15GR_Texture_Drawifffffffjf+0x7c> */
/* @0x174e20 sxth r2, r2 */
/* @0x174e24 sxth r3, r3 */
/* @0x174e28 vmov s13, r2 */
/* @0x174e2c vcvt.f32.s32 s14, s13 */
/* @0x174e30 vmov s13, r3 */
/* @0x174e34 vcvt.f32.s32 s15, s13 */
/* @0x174e38 b 0x174cdc <_Z15GR_Texture_Drawifffffffjf+0x9c> */
/* @0x174e3c vmov r0, s18 */
/* @0x174e40 bl 0xb6580 <sinf@plt> */
/* @0x174e44 vmov s19, r0 */
/* @0x174e48 vmov r0, s18 */
/* @0x174e4c bl 0xb658c <cosf@plt> */
/* @0x174e50 vmov.f32 s13, s17 */
/* @0x174e54 vmov.f32 s14, s16 */
/* @0x174e58 vmls.f32 s13, s22, s19 */
/* @0x174e5c vmls.f32 s17, s23, s19 */
/* @0x174e60 vmov s15, r0 */
/* @0x174e64 vmla.f32 s14, s22, s15 */
/* @0x174e68 vmla.f32 s16, s23, s15 */
/* @0x174e6c vmul.f32 s11, s21, s15 */
/* @0x174e70 vmul.f32 s21, s21, s19 */
/* @0x174e74 vmul.f32 s15, s20, s15 */
/* @0x174e78 vmul.f32 s19, s20, s19 */
/* @0x174e7c vadd.f32 s12, s13, s11 */
/* @0x174e80 vadd.f32 s11, s17, s11 */
/* @0x174e84 vstr s12, [r4, #4] */
/* @0x174e88 vstr s12, [r4, #124] */
/* @0x174e8c vadd.f32 s17, s15, s17 */
/* @0x174e90 vstr s11, [r4, #28] */
/* @0x174e94 vadd.f32 s15, s15, s13 */
/* @0x174e98 vstr s17, [r4, #52] */
/* @0x174e9c vstr s17, [r4, #76] */
/* @0x174ea0 vadd.f32 s13, s14, s21 */
/* @0x174ea4 vstr s15, [r4, #100] */
/* @0x174ea8 vadd.f32 s21, s16, s21 */
/* @0x174eac vstr s13, [r4] */
/* @0x174eb0 vstr s13, [r4, #120] */
/* @0x174eb4 vadd.f32 s16, s19, s16 */
/* @0x174eb8 vstr s21, [r4, #24] */
/* @0x174ebc vadd.f32 s19, s19, s14 */
/* @0x174ec0 vstr s16, [r4, #48] */
/* @0x174ec4 vstr s16, [r4, #72] */
/* @0x174ec8 vstr s19, [r4, #96] */
/* @0x174ecc b 0x174d60 <_Z15GR_Texture_Drawifffffffjf+0x120> */
/* @0x174ed0 cmnmi pc, #0 */
/* @0x174ed4 blo 0xfe239898 <b2_toiTime+0xfffffffffdae03f4> */
/* @0x174ed8 eoreq r8, r7, r0, lsl #25 */
/* @0x174edc mlaeq r7, r0, r11, r8 */

/* ── FUNC 0x174ee0 · GR_Texture_Draw(YYTPageEntry*, float, float, float, float, float, float, float, unsigned int, float) · size=808 · insn=202 */
/* @0x174ee0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x174ee4 vpush {d8, d9, d10} */
/* @0x174ee8 subs r5, r0, #0 */
/* @0x174eec vmov s20, r1 */
/* @0x174ef0 vmov s19, r2 */
/* @0x174ef4 vmov s16, r3 */
/* @0x174ef8 beq 0x17514c <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf+0x26c> */
/* @0x174efc ldrsh r0, [r5, #20] */
/* @0x174f00 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x174f04 subs r7, r0, #0 */
/* @0x174f08 beq 0x17514c <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf+0x26c> */
/* @0x174f0c vldr s15, [pc, #736] */
/* @0x174f10 vldr s13, [sp, #84] */
/* @0x174f14 vmul.f32 s15, s13, s15 */
/* @0x174f18 vcvt.s32.f32 s15, s15 */
/* @0x174f1c vmov r6, s15 */
/* @0x174f20 cmp r6, #255 */
/* @0x174f24 movgt r6, #-16777216 */
/* @0x174f28 bgt 0x174f38 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf+0x58> */
/* @0x174f2c cmp r6, #0 */
/* @0x174f30 lslge r6, r6, #24 */
/* @0x174f34 movlt r6, #0 */
/* @0x174f38 ldr r3, [pc, #0x2bc] */
/* @0x174f3c vldr s14, [sp, #72] */
/* @0x174f40 ldr r1, [sp, #0x50] */
/* @0x174f44 vldr s13, [sp, #68] */
/* @0x174f48 ldr r3, [pc, r3] */
/* @0x174f4c mov r0, #4 */
/* @0x174f50 bic r2, r1, #-16777216 */
/* @0x174f54 ldrsh r1, [r5, #10] */
/* @0x174f58 ldrb r3, [r3] */
/* @0x174f5c orr r6, r6, r2 */
/* @0x174f60 ldrh r2, [r5, #12] */
/* @0x174f64 cmp r3, #0 */
/* @0x174f68 ldrsh r3, [r5, #8] */
/* @0x174f6c vmov s17, r1 */
/* @0x174f70 bicne r6, r6, #65536 */
/* @0x174f74 bicne r6, r6, #1 */
/* @0x174f78 ldrsh r1, [r5, #20] */
/* @0x174f7c vmov s18, r3 */
/* @0x174f80 ldr r3, [pc, #0x278] */
/* @0x174f84 vcvt.f32.s32 s17, s17 */
/* @0x174f88 orrne r9, r6, #65536 */
/* @0x174f8c ldr r3, [pc, r3] */
/* @0x174f90 orrne r11, r6, #1 */
/* @0x174f94 orrne r10, r9, #1 */
/* @0x174f98 moveq r10, r6 */
/* @0x174f9c ldr r3, [r3, #0x4] */
/* @0x174fa0 moveq r9, r6 */
/* @0x174fa4 moveq r11, r6 */
/* @0x174fa8 cmp r2, #0 */
/* @0x174fac sxthne r2, r2 */
/* @0x174fb0 ldr r8, [r3, r1, lsl #2] */
/* @0x174fb4 moveq r3, #1 */
/* @0x174fb8 vcvt.f32.s32 s18, s18 */
/* @0x174fbc strheq r3, [r5, #12] */
/* @0x174fc0 vmovne s15, r2 */
/* @0x174fc4 ldrh r3, [r5, #14] */
/* @0x174fc8 ldr r1, [r8] */
/* @0x174fcc mov r2, #24 */
/* @0x174fd0 vsub.f32 s18, s20, s18 */
/* @0x174fd4 vsub.f32 s17, s19, s17 */
/* @0x174fd8 vnmul.f32 s18, s13, s18 */
/* @0x174fdc vnmul.f32 s17, s14, s17 */
/* @0x174fe0 vcvtne.f32.s32 s14, s15 */
/* @0x174fe4 vmoveq.f32 s14, #1.000000e+00 */
/* @0x174fe8 cmp r3, #0 */
/* @0x174fec sxthne r3, r3 */
/* @0x174ff0 moveq r3, #1 */
/* @0x174ff4 strheq r3, [r5, #14] */
/* @0x174ff8 vmovne s13, r3 */
/* @0x174ffc mov r3, #6 */
/* @0x175000 vmoveq.f32 s15, #1.000000e+00 */
/* @0x175004 vcvtne.f32.s32 s15, s13 */
/* @0x175008 vldr s13, [sp, #68] */
/* @0x17500c vmov.f32 s21, s18 */
/* @0x175010 vmov.f32 s20, s17 */
/* @0x175014 vmla.f32 s21, s13, s14 */
/* @0x175018 vldr s14, [sp, #72] */
/* @0x17501c vmla.f32 s20, s14, s15 */
/* @0x175020 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x175024 vldr s13, [sp, #76] */
/* @0x175028 vldr s15, [pc, #456] */
/* @0x17502c vabs.f32 s14, s13 */
/* @0x175030 vcmpe.f32 s14, s15 */
/* @0x175034 vmrs APSR_nzcv, fpscr */
/* @0x175038 mov r4, r0 */
/* @0x17503c bpl 0x17515c <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf+0x27c> */
/* @0x175040 vadd.f32 s18, s16, s18 */
/* @0x175044 vldr s14, [sp, #64] */
/* @0x175048 vadd.f32 s16, s16, s21 */
/* @0x17504c vstr s18, [r0] */
/* @0x175050 vstr s18, [r0, #120] */
/* @0x175054 vstr s18, [r0, #96] */
/* @0x175058 vadd.f32 s17, s14, s17 */
/* @0x17505c vstr s16, [r0, #48] */
/* @0x175060 vstr s16, [r0, #72] */
/* @0x175064 vstr s16, [r0, #24] */
/* @0x175068 vadd.f32 s20, s14, s20 */
/* @0x17506c vstr s17, [r0, #28] */
/* @0x175070 vstr s17, [r0, #4] */
/* @0x175074 vstr s17, [r0, #124] */
/* @0x175078 vstr s20, [r0, #100] */
/* @0x17507c vstr s20, [r0, #52] */
/* @0x175080 vstr s20, [r0, #76] */
/* @0x175084 ldrsh r2, [r5] */
/* @0x175088 vldr s11, [r8, #8] */
/* @0x17508c ldr r3, [pc, #0x170] */
/* @0x175090 mov r0, r7 */
/* @0x175094 str r6, [r4, #0xc] */
/* @0x175098 vmov s13, r2 */
/* @0x17509c ldr r3, [pc, r3] */
/* @0x1750a0 str r6, [r4, #0x84] */
/* @0x1750a4 vcvt.f32.s32 s15, s13 */
/* @0x1750a8 ldr r3, [r3] */
/* @0x1750ac str r11, [r4, #0x24] */
/* @0x1750b0 str r9, [r4, #0x3c] */
/* @0x1750b4 str r3, [r4, #0x68] */
/* @0x1750b8 str r3, [r4, #0x38] */
/* @0x1750bc str r3, [r4, #0x50] */
/* @0x1750c0 str r3, [r4, #0x20] */
/* @0x1750c4 vmul.f32 s15, s15, s11 */
/* @0x1750c8 str r3, [r4, #0x8] */
/* @0x1750cc str r3, [r4, #0x80] */
/* @0x1750d0 str r9, [r4, #0x54] */
/* @0x1750d4 str r10, [r4, #0x6c] */
/* @0x1750d8 vstr s15, [r4, #112] */
/* @0x1750dc vstr s15, [r4, #16] */
/* @0x1750e0 vstr s15, [r4, #136] */
/* @0x1750e4 ldrsh r3, [r5, #2] */
/* @0x1750e8 vldr s12, [r8, #12] */
/* @0x1750ec vmov s14, r3 */
/* @0x1750f0 vcvt.f32.s32 s13, s14 */
/* @0x1750f4 vmul.f32 s13, s13, s12 */
/* @0x1750f8 vstr s13, [r4, #44] */
/* @0x1750fc vstr s13, [r4, #20] */
/* @0x175100 vstr s13, [r4, #140] */
/* @0x175104 ldrsh r1, [r5, #4] */
/* @0x175108 add r1, r2, r1 */
/* @0x17510c vmov s14, r1 */
/* @0x175110 vcvt.f32.s32 s14, s14 */
/* @0x175114 vmul.f32 s14, s11, s14 */
/* @0x175118 vstr s14, [r4, #64] */
/* @0x17511c vstr s14, [r4, #88] */
/* @0x175120 vstr s14, [r4, #40] */
/* @0x175124 ldrsh r2, [r5, #6] */
/* @0x175128 add r2, r3, r2 */
/* @0x17512c vmov s15, r2 */
/* @0x175130 vcvt.f32.s32 s15, s15 */
/* @0x175134 vmul.f32 s15, s12, s15 */
/* @0x175138 vstr s15, [r4, #116] */
/* @0x17513c vstr s15, [r4, #68] */
/* @0x175140 vstr s15, [r4, #92] */
/* @0x175144 vpop {d8, d9, d10} */
/* @0x175148 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17514c vpop {d8, d9, d10} */
/* @0x175150 mov r7, #0 */
/* @0x175154 mov r0, r7 */
/* @0x175158 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17515c ldr r0, [sp, #0x4c] */
/* @0x175160 bl 0xb6580 <sinf@plt> */
/* @0x175164 vmov s19, r0 */
/* @0x175168 ldr r0, [sp, #0x4c] */
/* @0x17516c bl 0xb658c <cosf@plt> */
/* @0x175170 vldr s12, [sp, #64] */
/* @0x175174 vldr s13, [sp, #64] */
/* @0x175178 vmls.f32 s12, s18, s19 */
/* @0x17517c vmls.f32 s13, s21, s19 */
/* @0x175180 vmov s15, r0 */
/* @0x175184 vmov.f32 s14, s16 */
/* @0x175188 vmul.f32 s10, s17, s15 */
/* @0x17518c vmla.f32 s14, s18, s15 */
/* @0x175190 vmla.f32 s16, s21, s15 */
/* @0x175194 vmul.f32 s15, s20, s15 */
/* @0x175198 vmul.f32 s17, s17, s19 */
/* @0x17519c vmul.f32 s19, s20, s19 */
/* @0x1751a0 vadd.f32 s11, s12, s10 */
/* @0x1751a4 vadd.f32 s10, s13, s10 */
/* @0x1751a8 vstr s11, [r4, #4] */
/* @0x1751ac vstr s11, [r4, #124] */
/* @0x1751b0 vadd.f32 s13, s15, s13 */
/* @0x1751b4 vstr s10, [r4, #28] */
/* @0x1751b8 vadd.f32 s15, s15, s12 */
/* @0x1751bc vstr s13, [r4, #52] */
/* @0x1751c0 vstr s13, [r4, #76] */
/* @0x1751c4 vadd.f32 s13, s14, s17 */
/* @0x1751c8 vstr s15, [r4, #100] */
/* @0x1751cc vadd.f32 s17, s16, s17 */
/* @0x1751d0 vstr s13, [r4] */
/* @0x1751d4 vstr s13, [r4, #120] */
/* @0x1751d8 vadd.f32 s16, s19, s16 */
/* @0x1751dc vstr s17, [r4, #24] */
/* @0x1751e0 vadd.f32 s19, s19, s14 */
/* @0x1751e4 vstr s16, [r4, #48] */
/* @0x1751e8 vstr s16, [r4, #72] */
/* @0x1751ec vstr s19, [r4, #96] */
/* @0x1751f0 b 0x175084 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf+0x1a4> */
/* @0x1751f4 cmnmi pc, #0 */
/* @0x1751f8 blo 0xfe239bbc <b2_toiTime+0xfffffffffdae0718> */
/* @0x1751fc eoreq r8, r7, r4, lsl #30 */
/* @0x175200 mlaeq r7, r0, r9, r8 */
/* @0x175204 eoreq r8, r7, r4, lsl #17 */

/* ── FUNC 0x175208 · GR_Texture_Draw_Part(int, float, float, float, float, float, float, float, float, float, unsigned int, float) · size=584 · insn=146 */
/* @0x175208 push {r3, r4, r5, r6, r7, lr} */
/* @0x17520c vpush {d8, d9, d10, d11, d12, d13} */
/* @0x175210 mov r4, r0 */
/* @0x175214 vldr s18, [sp, #72] */
/* @0x175218 vmov s20, r1 */
/* @0x17521c vldr s21, [sp, #76] */
/* @0x175220 vmov s17, r2 */
/* @0x175224 vldr s22, [sp, #80] */
/* @0x175228 vmov s19, r3 */
/* @0x17522c vldr s23, [sp, #92] */
/* @0x175230 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x175234 subs r7, r0, #0 */
/* @0x175238 beq 0x1753dc <_Z20GR_Texture_Draw_Partifffffffffjf+0x1d4> */
/* @0x17523c vldr s15, [pc, #504] */
/* @0x175240 vldr s14, [sp, #100] */
/* @0x175244 vmul.f32 s15, s14, s15 */
/* @0x175248 vcvt.s32.f32 s15, s15 */
/* @0x17524c vmov r5, s15 */
/* @0x175250 cmp r5, #255 */
/* @0x175254 movgt r5, #-16777216 */
/* @0x175258 ble 0x17542c <_Z20GR_Texture_Draw_Partifffffffffjf+0x224> */
/* @0x17525c ldr r1, [pc, #0x1e4] */
/* @0x175260 vldr s16, [pc, #472] */
/* @0x175264 vmov.f32 s25, s16 */
/* @0x175268 ldr r3, [sp, #0x60] */
/* @0x17526c ldr r1, [pc, r1] */
/* @0x175270 mov r0, #4 */
/* @0x175274 bic r12, r3, #-16777216 */
/* @0x175278 mov r2, #24 */
/* @0x17527c ldr r1, [r1, #0x4] */
/* @0x175280 mov r3, #6 */
/* @0x175284 vldr s14, [sp, #84] */
/* @0x175288 orr r5, r5, r12 */
/* @0x17528c vmla.f32 s25, s14, s19 */
/* @0x175290 ldr r6, [r1, r4, lsl #2] */
/* @0x175294 ldr r1, [r6] */
/* @0x175298 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x17529c vldr s15, [pc, #416] */
/* @0x1752a0 vabs.f32 s14, s23 */
/* @0x1752a4 vmov.f32 s24, s16 */
/* @0x1752a8 vcmpe.f32 s14, s15 */
/* @0x1752ac vldr s15, [sp, #88] */
/* @0x1752b0 vmrs APSR_nzcv, fpscr */
/* @0x1752b4 vmla.f32 s24, s15, s18 */
/* @0x1752b8 mov r4, r0 */
/* @0x1752bc bmi 0x1753e8 <_Z20GR_Texture_Draw_Partifffffffffjf+0x1e0> */
/* @0x1752c0 vmov r0, s23 */
/* @0x1752c4 bl 0xb6580 <sinf@plt> */
/* @0x1752c8 vmov s26, r0 */
/* @0x1752cc vmov r0, s23 */
/* @0x1752d0 bl 0xb658c <cosf@plt> */
/* @0x1752d4 vmov.f32 s12, s22 */
/* @0x1752d8 vmov.f32 s13, s21 */
/* @0x1752dc vmul.f32 s15, s26, s16 */
/* @0x1752e0 vmls.f32 s12, s25, s26 */
/* @0x1752e4 vmov s14, r0 */
/* @0x1752e8 vmul.f32 s16, s14, s16 */
/* @0x1752ec vmla.f32 s13, s25, s14 */
/* @0x1752f0 vmul.f32 s26, s24, s26 */
/* @0x1752f4 vmul.f32 s14, s24, s14 */
/* @0x1752f8 vsub.f32 s22, s22, s15 */
/* @0x1752fc vadd.f32 s21, s21, s16 */
/* @0x175300 vadd.f32 s11, s16, s22 */
/* @0x175304 vadd.f32 s22, s14, s22 */
/* @0x175308 vstr s11, [r4, #4] */
/* @0x17530c vstr s11, [r4, #124] */
/* @0x175310 vadd.f32 s14, s14, s12 */
/* @0x175314 vstr s22, [r4, #100] */
/* @0x175318 vadd.f32 s16, s16, s12 */
/* @0x17531c vstr s14, [r4, #52] */
/* @0x175320 vstr s14, [r4, #76] */
/* @0x175324 vadd.f32 s12, s15, s21 */
/* @0x175328 vstr s16, [r4, #28] */
/* @0x17532c vadd.f32 s21, s26, s21 */
/* @0x175330 vstr s12, [r4] */
/* @0x175334 vstr s12, [r4, #120] */
/* @0x175338 vadd.f32 s26, s26, s13 */
/* @0x17533c vstr s21, [r4, #96] */
/* @0x175340 vadd.f32 s15, s15, s13 */
/* @0x175344 vstr s26, [r4, #48] */
/* @0x175348 vstr s26, [r4, #72] */
/* @0x17534c vstr s15, [r4, #24] */
/* @0x175350 vldr s14, [r6, #8] */
/* @0x175354 vmul.f32 s12, s14, s20 */
/* @0x175358 ldr r3, [pc, #0xec] */
/* @0x17535c str r5, [r4, #0x84] */
/* @0x175360 ldr r3, [pc, r3] */
/* @0x175364 str r5, [r4, #0x6c] */
/* @0x175368 str r5, [r4, #0x54] */
/* @0x17536c ldr r3, [r3] */
/* @0x175370 str r5, [r4, #0x3c] */
/* @0x175374 str r5, [r4, #0x24] */
/* @0x175378 str r3, [r4, #0x80] */
/* @0x17537c str r3, [r4, #0x68] */
/* @0x175380 str r5, [r4, #0xc] */
/* @0x175384 str r3, [r4, #0x50] */
/* @0x175388 vadd.f32 s13, s20, s19 */
/* @0x17538c vstr s12, [r4, #136] */
/* @0x175390 vstr s12, [r4, #112] */
/* @0x175394 vstr s12, [r4, #16] */
/* @0x175398 vldr s12, [r6, #12] */
/* @0x17539c str r3, [r4, #0x38] */
/* @0x1753a0 str r3, [r4, #0x20] */
/* @0x1753a4 str r3, [r4, #0x8] */
/* @0x1753a8 vadd.f32 s15, s17, s18 */
/* @0x1753ac vmul.f32 s13, s14, s13 */
/* @0x1753b0 vmul.f32 s15, s12, s15 */
/* @0x1753b4 vstr s13, [r4, #88] */
/* @0x1753b8 vstr s13, [r4, #64] */
/* @0x1753bc vstr s13, [r4, #40] */
/* @0x1753c0 vmul.f32 s14, s12, s17 */
/* @0x1753c4 vstr s15, [r4, #116] */
/* @0x1753c8 vstr s15, [r4, #92] */
/* @0x1753cc vstr s15, [r4, #68] */
/* @0x1753d0 vstr s14, [r4, #140] */
/* @0x1753d4 vstr s14, [r4, #44] */
/* @0x1753d8 vstr s14, [r4, #20] */
/* @0x1753dc vpop {d8, d9, d10, d11, d12, d13} */
/* @0x1753e0 mov r0, r7 */
/* @0x1753e4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1753e8 vadd.f32 s25, s21, s25 */
/* @0x1753ec vadd.f32 s21, s21, s16 */
/* @0x1753f0 vstr s25, [r0, #48] */
/* @0x1753f4 vstr s25, [r0, #72] */
/* @0x1753f8 vstr s25, [r0, #24] */
/* @0x1753fc vadd.f32 s16, s22, s16 */
/* @0x175400 vstr s21, [r0] */
/* @0x175404 vstr s21, [r0, #120] */
/* @0x175408 vstr s21, [r0, #96] */
/* @0x17540c vadd.f32 s22, s22, s24 */
/* @0x175410 vstr s16, [r0, #28] */
/* @0x175414 vstr s16, [r0, #4] */
/* @0x175418 vstr s16, [r0, #124] */
/* @0x17541c vstr s22, [r0, #100] */
/* @0x175420 vstr s22, [r0, #52] */
/* @0x175424 vstr s22, [r0, #76] */
/* @0x175428 b 0x175350 <_Z20GR_Texture_Draw_Partifffffffffjf+0x148> */
/* @0x17542c cmp r5, #0 */
/* @0x175430 lslge r5, r5, #24 */
/* @0x175434 movlt r5, #0 */
/* @0x175438 b 0x17525c <_Z20GR_Texture_Draw_Partifffffffffjf+0x54> */
/* @0x17543c cmnmi pc, #0 */
/* @0x175440 andeq r0, r0, r0 */
/* @0x175444 blo 0xfe239e08 <b2_toiTime+0xfffffffffdae0964> */
/* @0x175448 .word 0x002786b0 */
/* @0x17544c eoreq r8, r7, r0, asr #11 */

/* ── FUNC 0x175450 · GR_Texture_Draw_Part(YYTPageEntry*, float, float, float, float, float, float, float, float, float, unsigned int, float) · size=996 · insn=249 */
/* @0x175450 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x175454 vpush {d8, d9, d10, d11, d12} */
/* @0x175458 subs r4, r0, #0 */
/* @0x17545c vldr s17, [sp, #72] */
/* @0x175460 vmov s22, r1 */
/* @0x175464 vldr s19, [sp, #76] */
/* @0x175468 vmov s21, r2 */
/* @0x17546c vldr s18, [sp, #80] */
/* @0x175470 vmov s16, r3 */
/* @0x175474 vldr s20, [sp, #92] */
/* @0x175478 beq 0x1757c8 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x378> */
/* @0x17547c ldrsh r0, [r4, #20] */
/* @0x175480 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x175484 subs r6, r0, #0 */
/* @0x175488 beq 0x1757c8 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x378> */
/* @0x17548c vldr s15, [pc, #904] */
/* @0x175490 vldr s10, [sp, #100] */
/* @0x175494 vmul.f32 s15, s10, s15 */
/* @0x175498 vcvt.s32.f32 s15, s15 */
/* @0x17549c vmov r5, s15 */
/* @0x1754a0 cmp r5, #255 */
/* @0x1754a4 movgt r5, #-16777216 */
/* @0x1754a8 bgt 0x1754b8 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x68> */
/* @0x1754ac cmp r5, #0 */
/* @0x1754b0 lslge r5, r5, #24 */
/* @0x1754b4 movlt r5, #0 */
/* @0x1754b8 ldr r3, [pc, #0x368] */
/* @0x1754bc ldr r1, [sp, #0x60] */
/* @0x1754c0 ldr r3, [pc, r3] */
/* @0x1754c4 vmov r0, s20 */
/* @0x1754c8 bic r2, r1, #-16777216 */
/* @0x1754cc ldrb r3, [r3] */
/* @0x1754d0 orr r5, r5, r2 */
/* @0x1754d4 ldrsh r2, [r4, #20] */
/* @0x1754d8 cmp r3, #0 */
/* @0x1754dc ldr r3, [pc, #0x348] */
/* @0x1754e0 bicne r5, r5, #65536 */
/* @0x1754e4 ldr r3, [pc, r3] */
/* @0x1754e8 bicne r5, r5, #1 */
/* @0x1754ec orrne r7, r5, #65536 */
/* @0x1754f0 orrne r9, r5, #1 */
/* @0x1754f4 ldr r3, [r3, #0x4] */
/* @0x1754f8 orrne r8, r7, #1 */
/* @0x1754fc moveq r8, r5 */
/* @0x175500 moveq r7, r5 */
/* @0x175504 moveq r9, r5 */
/* @0x175508 ldr r10, [r3, r2, lsl #2] */
/* @0x17550c bl 0xb6580 <sinf@plt> */
/* @0x175510 vmov s23, r0 */
/* @0x175514 vmov r0, s20 */
/* @0x175518 bl 0xb658c <cosf@plt> */
/* @0x17551c ldrsh r3, [r4, #8] */
/* @0x175520 vmov s15, r3 */
/* @0x175524 vcvt.f32.s32 s15, s15 */
/* @0x175528 vcmpe.f32 s15, s22 */
/* @0x17552c vmrs APSR_nzcv, fpscr */
/* @0x175530 vsuble.f32 s22, s22, s15 */
/* @0x175534 vmov s24, r0 */
/* @0x175538 ble 0x175578 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x128> */
/* @0x17553c vsub.f32 s15, s15, s22 */
/* @0x175540 vldr s10, [sp, #84] */
/* @0x175544 vldr s11, [sp, #88] */
/* @0x175548 vldr s22, [pc, #720] */
/* @0x17554c vmul.f32 s13, s24, s15 */
/* @0x175550 vmul.f32 s14, s23, s15 */
/* @0x175554 vmul.f32 s13, s13, s10 */
/* @0x175558 vmul.f32 s14, s14, s11 */
/* @0x17555c vcvt.s32.f32 s13, s13 */
/* @0x175560 vcvt.s32.f32 s14, s14 */
/* @0x175564 vcvt.f32.s32 s13, s13 */
/* @0x175568 vcvt.f32.s32 s14, s14 */
/* @0x17556c vsub.f32 s16, s16, s15 */
/* @0x175570 vadd.f32 s19, s19, s13 */
/* @0x175574 vsub.f32 s18, s18, s14 */
/* @0x175578 ldrsh r1, [r4, #10] */
/* @0x17557c vmov s15, r1 */
/* @0x175580 vcvt.f32.s32 s15, s15 */
/* @0x175584 vcmpe.f32 s15, s21 */
/* @0x175588 vmrs APSR_nzcv, fpscr */
/* @0x17558c vsuble.f32 s21, s21, s15 */
/* @0x175590 ble 0x1755d0 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x180> */
/* @0x175594 vldr s10, [sp, #84] */
/* @0x175598 vldr s11, [sp, #88] */
/* @0x17559c vsub.f32 s15, s15, s21 */
/* @0x1755a0 vldr s21, [pc, #632] */
/* @0x1755a4 vmul.f32 s13, s23, s15 */
/* @0x1755a8 vmul.f32 s14, s24, s15 */
/* @0x1755ac vmul.f32 s13, s13, s10 */
/* @0x1755b0 vmul.f32 s14, s14, s11 */
/* @0x1755b4 vcvt.s32.f32 s13, s13 */
/* @0x1755b8 vcvt.s32.f32 s14, s14 */
/* @0x1755bc vcvt.f32.s32 s13, s13 */
/* @0x1755c0 vcvt.f32.s32 s14, s14 */
/* @0x1755c4 vsub.f32 s17, s17, s15 */
/* @0x1755c8 vadd.f32 s19, s19, s13 */
/* @0x1755cc vadd.f32 s18, s18, s14 */
/* @0x1755d0 ldrsh r1, [r4, #12] */
/* @0x1755d4 vldr s25, [pc, #580] */
/* @0x1755d8 ldrsh r3, [r4, #14] */
/* @0x1755dc vmov s15, r1 */
/* @0x1755e0 vadd.f32 s14, s22, s16 */
/* @0x1755e4 vcvt.f32.s32 s15, s15 */
/* @0x1755e8 vcmpe.f32 s14, s15 */
/* @0x1755ec vadd.f32 s14, s21, s17 */
/* @0x1755f0 vmrs APSR_nzcv, fpscr */
/* @0x1755f4 vsubgt.f32 s16, s15, s22 */
/* @0x1755f8 vmov s15, r3 */
/* @0x1755fc vcvt.f32.s32 s15, s15 */
/* @0x175600 vcmpe.f32 s14, s15 */
/* @0x175604 vmrs APSR_nzcv, fpscr */
/* @0x175608 vcmpe.f32 s16, s25 */
/* @0x17560c vsubgt.f32 s17, s15, s21 */
/* @0x175610 vmrs APSR_nzcv, fpscr */
/* @0x175614 bls 0x1757cc <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x37c> */
/* @0x175618 vcmpe.f32 s17, s25 */
/* @0x17561c vmrs APSR_nzcv, fpscr */
/* @0x175620 bls 0x1757cc <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x37c> */
/* @0x175624 vabs.f32 s20, s20 */
/* @0x175628 mov r0, #4 */
/* @0x17562c ldr r1, [r10] */
/* @0x175630 mov r2, #24 */
/* @0x175634 mov r3, #6 */
/* @0x175638 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x17563c vldr s15, [pc, #480] */
/* @0x175640 vcmpe.f32 s20, s15 */
/* @0x175644 vldr s10, [sp, #84] */
/* @0x175648 vldr s11, [sp, #88] */
/* @0x17564c vmul.f32 s14, s10, s16 */
/* @0x175650 vmrs APSR_nzcv, fpscr */
/* @0x175654 vmul.f32 s15, s11, s17 */
/* @0x175658 bmi 0x1757d8 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x388> */
/* @0x17565c vmov.f32 s12, s19 */
/* @0x175660 vmov.f32 s10, s18 */
/* @0x175664 vmul.f32 s13, s24, s25 */
/* @0x175668 vmul.f32 s25, s23, s25 */
/* @0x17566c vmla.f32 s12, s14, s24 */
/* @0x175670 vmls.f32 s10, s14, s23 */
/* @0x175674 vmul.f32 s24, s15, s24 */
/* @0x175678 vmul.f32 s23, s15, s23 */
/* @0x17567c vadd.f32 s19, s19, s13 */
/* @0x175680 vsub.f32 s18, s18, s25 */
/* @0x175684 vadd.f32 s15, s25, s19 */
/* @0x175688 vadd.f32 s11, s13, s18 */
/* @0x17568c vstr s15, [r0] */
/* @0x175690 vadd.f32 s19, s23, s19 */
/* @0x175694 vstr s11, [r0, #4] */
/* @0x175698 vadd.f32 s18, s24, s18 */
/* @0x17569c vstr s19, [r0, #120] */
/* @0x1756a0 vstr s19, [r0, #48] */
/* @0x1756a4 vadd.f32 s25, s25, s12 */
/* @0x1756a8 vstr s18, [r0, #124] */
/* @0x1756ac vstr s18, [r0, #52] */
/* @0x1756b0 vadd.f32 s13, s13, s10 */
/* @0x1756b4 vstr s25, [r0, #24] */
/* @0x1756b8 vstr s25, [r0, #72] */
/* @0x1756bc vadd.f32 s23, s23, s12 */
/* @0x1756c0 vstr s13, [r0, #28] */
/* @0x1756c4 vstr s13, [r0, #76] */
/* @0x1756c8 vadd.f32 s24, s24, s10 */
/* @0x1756cc vstr s23, [r0, #96] */
/* @0x1756d0 vstr s24, [r0, #100] */
/* @0x1756d4 ldrsh r1, [r4, #4] */
/* @0x1756d8 vldr s11, [r10, #8] */
/* @0x1756dc ldrsh r3, [r4, #12] */
/* @0x1756e0 ldr r2, [pc, #0x148] */
/* @0x1756e4 vmov s9, r1 */
/* @0x1756e8 ldrsh r1, [r4] */
/* @0x1756ec vmov s12, r3 */
/* @0x1756f0 ldrsh r3, [r4, #6] */
/* @0x1756f4 vcvt.f32.s32 s9, s9 */
/* @0x1756f8 ldr r2, [pc, r2] */
/* @0x1756fc vmov s14, r1 */
/* @0x175700 ldrsh r1, [r4, #14] */
/* @0x175704 vmov s10, r3 */
/* @0x175708 ldr r2, [r2] */
/* @0x17570c str r5, [r0, #0xc] */
/* @0x175710 vmov s15, r1 */
/* @0x175714 str r5, [r0, #0x84] */
/* @0x175718 str r9, [r0, #0x24] */
/* @0x17571c str r7, [r0, #0x3c] */
/* @0x175720 vcvt.f32.s32 s12, s12 */
/* @0x175724 str r2, [r0, #0x80] */
/* @0x175728 str r7, [r0, #0x54] */
/* @0x17572c str r8, [r0, #0x6c] */
/* @0x175730 str r2, [r0, #0x68] */
/* @0x175734 str r2, [r0, #0x50] */
/* @0x175738 str r2, [r0, #0x38] */
/* @0x17573c str r2, [r0, #0x20] */
/* @0x175740 vdiv.f32 s12, s9, s12 */
/* @0x175744 str r2, [r0, #0x8] */
/* @0x175748 vcvt.f32.s32 s14, s14 */
/* @0x17574c vmla.f32 s14, s22, s12 */
/* @0x175750 vcvt.f32.s32 s10, s10 */
/* @0x175754 vcvt.f32.s32 s15, s15 */
/* @0x175758 vdiv.f32 s13, s10, s15 */
/* @0x17575c vmul.f32 s15, s14, s11 */
/* @0x175760 vstr s15, [r0, #136] */
/* @0x175764 vstr s15, [r0, #64] */
/* @0x175768 vstr s15, [r0, #16] */
/* @0x17576c ldrsh r4, [r4, #2] */
/* @0x175770 vmla.f32 s14, s16, s12 */
/* @0x175774 vldr s12, [r10, #12] */
/* @0x175778 vmov s15, r4 */
/* @0x17577c vcvt.f32.s32 s15, s15 */
/* @0x175780 vmla.f32 s15, s21, s13 */
/* @0x175784 vmov.f32 s10, s15 */
/* @0x175788 vmla.f32 s10, s17, s13 */
/* @0x17578c vmul.f32 s14, s11, s14 */
/* @0x175790 vmul.f32 s13, s12, s10 */
/* @0x175794 vstr s14, [r0, #112] */
/* @0x175798 vstr s14, [r0, #40] */
/* @0x17579c vstr s14, [r0, #88] */
/* @0x1757a0 vmul.f32 s15, s15, s12 */
/* @0x1757a4 vstr s13, [r0, #140] */
/* @0x1757a8 vstr s13, [r0, #68] */
/* @0x1757ac vstr s15, [r0, #44] */
/* @0x1757b0 vstr s15, [r0, #92] */
/* @0x1757b4 vstr s15, [r0, #20] */
/* @0x1757b8 vstr s13, [r0, #116] */
/* @0x1757bc vpop {d8, d9, d10, d11, d12} */
/* @0x1757c0 mov r0, r6 */
/* @0x1757c4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1757c8 mov r6, #0 */
/* @0x1757cc vpop {d8, d9, d10, d11, d12} */
/* @0x1757d0 mov r0, r6 */
/* @0x1757d4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1757d8 vadd.f32 s14, s19, s14 */
/* @0x1757dc vadd.f32 s19, s19, s25 */
/* @0x1757e0 vstr s14, [r0, #96] */
/* @0x1757e4 vstr s14, [r0, #24] */
/* @0x1757e8 vstr s14, [r0, #72] */
/* @0x1757ec vadd.f32 s25, s18, s25 */
/* @0x1757f0 vstr s19, [r0] */
/* @0x1757f4 vstr s19, [r0, #120] */
/* @0x1757f8 vstr s19, [r0, #48] */
/* @0x1757fc vadd.f32 s18, s18, s15 */
/* @0x175800 vstr s25, [r0, #28] */
/* @0x175804 vstr s25, [r0, #76] */
/* @0x175808 vstr s25, [r0, #4] */
/* @0x17580c vstr s18, [r0, #124] */
/* @0x175810 vstr s18, [r0, #52] */
/* @0x175814 vstr s18, [r0, #100] */
/* @0x175818 b 0x1756d4 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x284> */
/* @0x17581c cmnmi pc, #0 */
/* @0x175820 andeq r0, r0, r0 */
/* @0x175824 blo 0xfe23a1e8 <b2_toiTime+0xfffffffffdae0d44> */
/* @0x175828 eoreq r8, r7, r12, lsl #19 */
/* @0x17582c eoreq r8, r7, r8, lsr r4 */
/* @0x175830 eoreq r8, r7, r8, lsr #4 */

/* ── FUNC 0x175834 · GR_Texture_Draw_Part_Color(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float) · size=600 · insn=150 */
/* @0x175834 push {r4, r5, r6, r7, r8, lr} */
/* @0x175838 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x17583c mov r4, r0 */
/* @0x175840 vldr s18, [sp, #72] */
/* @0x175844 vmov s20, r1 */
/* @0x175848 vldr s21, [sp, #76] */
/* @0x17584c vmov s17, r2 */
/* @0x175850 vldr s22, [sp, #80] */
/* @0x175854 vmov s19, r3 */
/* @0x175858 vldr s23, [sp, #92] */
/* @0x17585c bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x175860 subs r6, r0, #0 */
/* @0x175864 beq 0x175a28 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf+0x1f4> */
/* @0x175868 vldr s14, [sp, #112] */
/* @0x17586c vldr s15, [pc, #516] */
/* @0x175870 vmul.f32 s15, s14, s15 */
/* @0x175874 ldr r1, [pc, #0x208] */
/* @0x175878 mov r0, #4 */
/* @0x17587c mov r2, #24 */
/* @0x175880 ldr r1, [pc, r1] */
/* @0x175884 mov r3, #6 */
/* @0x175888 vldr s16, [pc, #492] */
/* @0x17588c ldr r1, [r1, #0x4] */
/* @0x175890 ldr r5, [r1, r4, lsl #2] */
/* @0x175894 ldr r1, [r5] */
/* @0x175898 vcvt.s32.f32 s15, s15 */
/* @0x17589c vmov r7, s15 */
/* @0x1758a0 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1758a4 vabs.f32 s14, s23 */
/* @0x1758a8 vldr s15, [pc, #464] */
/* @0x1758ac vmov.f32 s25, s16 */
/* @0x1758b0 vcmpe.f32 s14, s15 */
/* @0x1758b4 vldr s15, [sp, #84] */
/* @0x1758b8 vldr s14, [sp, #88] */
/* @0x1758bc vmov.f32 s24, s16 */
/* @0x1758c0 vmrs APSR_nzcv, fpscr */
/* @0x1758c4 vmla.f32 s25, s15, s19 */
/* @0x1758c8 usat r7, #0x8, r7 */
/* @0x1758cc mov r4, r0 */
/* @0x1758d0 vmla.f32 s24, s14, s18 */
/* @0x1758d4 bmi 0x175a34 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf+0x200> */
/* @0x1758d8 vmov r0, s23 */
/* @0x1758dc bl 0xb6580 <sinf@plt> */
/* @0x1758e0 vmov s26, r0 */
/* @0x1758e4 vmov r0, s23 */
/* @0x1758e8 bl 0xb658c <cosf@plt> */
/* @0x1758ec vmov.f32 s12, s22 */
/* @0x1758f0 vmov.f32 s13, s21 */
/* @0x1758f4 vmul.f32 s15, s26, s16 */
/* @0x1758f8 vmls.f32 s12, s25, s26 */
/* @0x1758fc vmov s14, r0 */
/* @0x175900 vmul.f32 s16, s14, s16 */
/* @0x175904 vmla.f32 s13, s25, s14 */
/* @0x175908 vmul.f32 s26, s24, s26 */
/* @0x17590c vmul.f32 s14, s24, s14 */
/* @0x175910 vsub.f32 s22, s22, s15 */
/* @0x175914 vadd.f32 s21, s21, s16 */
/* @0x175918 vadd.f32 s11, s16, s22 */
/* @0x17591c vadd.f32 s22, s14, s22 */
/* @0x175920 vstr s11, [r4, #4] */
/* @0x175924 vstr s11, [r4, #124] */
/* @0x175928 vadd.f32 s14, s14, s12 */
/* @0x17592c vstr s22, [r4, #100] */
/* @0x175930 vadd.f32 s16, s16, s12 */
/* @0x175934 vstr s14, [r4, #52] */
/* @0x175938 vstr s14, [r4, #76] */
/* @0x17593c vadd.f32 s12, s15, s21 */
/* @0x175940 vstr s16, [r4, #28] */
/* @0x175944 vadd.f32 s21, s26, s21 */
/* @0x175948 vstr s12, [r4] */
/* @0x17594c vstr s12, [r4, #120] */
/* @0x175950 vadd.f32 s26, s26, s13 */
/* @0x175954 vstr s21, [r4, #96] */
/* @0x175958 vadd.f32 s15, s15, s13 */
/* @0x17595c vstr s26, [r4, #48] */
/* @0x175960 vstr s26, [r4, #72] */
/* @0x175964 vstr s15, [r4, #24] */
/* @0x175968 vldr s14, [r5, #8] */
/* @0x17596c vmul.f32 s12, s14, s20 */
/* @0x175970 ldr r3, [pc, #0x110] */
/* @0x175974 lsl r2, r7, #24 */
/* @0x175978 ldr r0, [sp, #0x60] */
/* @0x17597c ldr r8, [sp, #0x64] */
/* @0x175980 ldr r3, [pc, r3] */
/* @0x175984 bic r1, r0, #-16777216 */
/* @0x175988 ldr r0, [sp, #0x68] */
/* @0x17598c ldr r3, [r3] */
/* @0x175990 bic r7, r8, #-16777216 */
/* @0x175994 ldr r8, [sp, #0x6c] */
/* @0x175998 bic r12, r0, #-16777216 */
/* @0x17599c orr r1, r2, r1 */
/* @0x1759a0 str r1, [r4, #0x84] */
/* @0x1759a4 bic r0, r8, #-16777216 */
/* @0x1759a8 str r3, [r4, #0x80] */
/* @0x1759ac str r3, [r4, #0x68] */
/* @0x1759b0 str r3, [r4, #0x50] */
/* @0x1759b4 str r3, [r4, #0x38] */
/* @0x1759b8 vadd.f32 s13, s20, s19 */
/* @0x1759bc vstr s12, [r4, #136] */
/* @0x1759c0 vstr s12, [r4, #112] */
/* @0x1759c4 vstr s12, [r4, #16] */
/* @0x1759c8 vldr s12, [r5, #12] */
/* @0x1759cc str r3, [r4, #0x20] */
/* @0x1759d0 str r3, [r4, #0x8] */
/* @0x1759d4 orr r3, r2, r12 */
/* @0x1759d8 str r1, [r4, #0xc] */
/* @0x1759dc orr r1, r2, r7 */
/* @0x1759e0 str r3, [r4, #0x54] */
/* @0x1759e4 orr r2, r2, r0 */
/* @0x1759e8 str r1, [r4, #0x24] */
/* @0x1759ec str r3, [r4, #0x3c] */
/* @0x1759f0 str r2, [r4, #0x6c] */
/* @0x1759f4 vadd.f32 s15, s17, s18 */
/* @0x1759f8 vmul.f32 s13, s14, s13 */
/* @0x1759fc vmul.f32 s15, s12, s15 */
/* @0x175a00 vstr s13, [r4, #88] */
/* @0x175a04 vstr s13, [r4, #64] */
/* @0x175a08 vstr s13, [r4, #40] */
/* @0x175a0c vmul.f32 s14, s12, s17 */
/* @0x175a10 vstr s15, [r4, #116] */
/* @0x175a14 vstr s15, [r4, #92] */
/* @0x175a18 vstr s15, [r4, #68] */
/* @0x175a1c vstr s14, [r4, #140] */
/* @0x175a20 vstr s14, [r4, #44] */
/* @0x175a24 vstr s14, [r4, #20] */
/* @0x175a28 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x175a2c mov r0, r6 */
/* @0x175a30 pop {r4, r5, r6, r7, r8, pc} */
/* @0x175a34 vadd.f32 s25, s21, s25 */
/* @0x175a38 vadd.f32 s21, s21, s16 */
/* @0x175a3c vstr s25, [r0, #48] */
/* @0x175a40 vstr s25, [r0, #72] */
/* @0x175a44 vstr s25, [r0, #24] */
/* @0x175a48 vadd.f32 s16, s22, s16 */
/* @0x175a4c vstr s21, [r0] */
/* @0x175a50 vstr s21, [r0, #120] */
/* @0x175a54 vstr s21, [r0, #96] */
/* @0x175a58 vadd.f32 s22, s22, s24 */
/* @0x175a5c vstr s16, [r0, #28] */
/* @0x175a60 vstr s16, [r0, #4] */
/* @0x175a64 vstr s16, [r0, #124] */
/* @0x175a68 vstr s22, [r0, #100] */
/* @0x175a6c vstr s22, [r0, #52] */
/* @0x175a70 vstr s22, [r0, #76] */
/* @0x175a74 b 0x175968 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf+0x134> */
/* @0x175a78 cmnmi pc, #0 */
/* @0x175a7c andeq r0, r0, r0 */
/* @0x175a80 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x175a84 mlaeq r7, r12, r0, r8 */
/* @0x175a88 eoreq r7, r7, r0, lsr #31 */

/* ── FUNC 0x175a8c · anon_175a8c · size=0 · insn=1 */
/* @0x175a8c andeq r0, r0, r0 */

/* ── FUNC 0x175a90 · GR_Texture_Draw_Part_Color(YYTPageEntry*, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float) · size=1020 · insn=253 */
/* @0x175a90 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x175a94 vpush {d8, d9, d10, d11} */
/* @0x175a98 subs r4, r0, #0 */
/* @0x175a9c sub sp, sp, #60 */
/* @0x175aa0 vmov s22, r1 */
/* @0x175aa4 vmov s21, r2 */
/* @0x175aa8 vldr s18, [sp, #120] */
/* @0x175aac vmov s19, r3 */
/* @0x175ab0 vldr s17, [sp, #124] */
/* @0x175ab4 vldr s16, [sp, #128] */
/* @0x175ab8 vldr s20, [sp, #140] */
/* @0x175abc beq 0x175d8c <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x2fc> */
/* @0x175ac0 ldrsh r0, [r4, #20] */
/* @0x175ac4 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x175ac8 subs r5, r0, #0 */
/* @0x175acc beq 0x175d8c <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x2fc> */
/* @0x175ad0 vldr s15, [pc, #928] */
/* @0x175ad4 vldr s5, [sp, #160] */
/* @0x175ad8 vmul.f32 s14, s5, s15 */
/* @0x175adc vcmpe.f32 s14, #0 */
/* @0x175ae0 vmrs APSR_nzcv, fpscr */
/* @0x175ae4 bmi 0x175e48 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x3b8> */
/* @0x175ae8 vcmpe.f32 s14, s15 */
/* @0x175aec vmrs APSR_nzcv, fpscr */
/* @0x175af0 ble 0x175e50 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x3c0> */
/* @0x175af4 vldr d7, [pc, #876] */
/* @0x175af8 vmov r0, r1, d7 */
/* @0x175afc bl 0xb66e8 <lrint@plt> */
/* @0x175b00 ldr r3, [sp, #0x94] */
/* @0x175b04 ldr r2, [pc, #0x378] */
/* @0x175b08 bic r8, r3, #-16777216 */
/* @0x175b0c ldr r3, [sp, #0x9c] */
/* @0x175b10 ldr r2, [pc, r2] */
/* @0x175b14 ldr r1, [sp, #0x90] */
/* @0x175b18 bic r6, r3, #-16777216 */
/* @0x175b1c ldrb r3, [r2] */
/* @0x175b20 bic r9, r1, #-16777216 */
/* @0x175b24 ldr r1, [sp, #0x98] */
/* @0x175b28 cmp r3, #0 */
/* @0x175b2c bic r7, r1, #-16777216 */
/* @0x175b30 lsl r0, r0, #24 */
/* @0x175b34 orr r9, r0, r9 */
/* @0x175b38 orr r8, r0, r8 */
/* @0x175b3c orr r7, r0, r7 */
/* @0x175b40 orr r6, r0, r6 */
/* @0x175b44 beq 0x175b70 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0xe0> */
/* @0x175b48 bic r8, r8, #65536 */
/* @0x175b4c bic r7, r7, #65536 */
/* @0x175b50 bic r8, r8, #1 */
/* @0x175b54 bic r7, r7, #1 */
/* @0x175b58 bic r9, r9, #65536 */
/* @0x175b5c orr r6, r6, #65536 */
/* @0x175b60 orr r8, r8, #1 */
/* @0x175b64 orr r7, r7, #65536 */
/* @0x175b68 bic r9, r9, #1 */
/* @0x175b6c orr r6, r6, #1 */
/* @0x175b70 vmov r0, s20 */
/* @0x175b74 bl 0xb6580 <sinf@plt> */
/* @0x175b78 vmov s23, r0 */
/* @0x175b7c vmov r0, s20 */
/* @0x175b80 bl 0xb658c <cosf@plt> */
/* @0x175b84 ldrsh r1, [r4, #8] */
/* @0x175b88 vmov s15, r1 */
/* @0x175b8c vcvt.f32.s32 s15, s15 */
/* @0x175b90 vcmpe.f32 s15, s22 */
/* @0x175b94 vmrs APSR_nzcv, fpscr */
/* @0x175b98 vsuble.f32 s22, s22, s15 */
/* @0x175b9c vmov s12, r0 */
/* @0x175ba0 ble 0x175be0 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x150> */
/* @0x175ba4 vsub.f32 s14, s15, s22 */
/* @0x175ba8 vldr s5, [sp, #132] */
/* @0x175bac vldr s9, [sp, #136] */
/* @0x175bb0 vldr s22, [pc, #708] */
/* @0x175bb4 vmul.f32 s13, s12, s14 */
/* @0x175bb8 vmul.f32 s15, s23, s14 */
/* @0x175bbc vmul.f32 s13, s13, s5 */
/* @0x175bc0 vmul.f32 s15, s15, s9 */
/* @0x175bc4 vcvt.s32.f32 s13, s13 */
/* @0x175bc8 vcvt.s32.f32 s15, s15 */
/* @0x175bcc vcvt.f32.s32 s13, s13 */
/* @0x175bd0 vcvt.f32.s32 s15, s15 */
/* @0x175bd4 vsub.f32 s19, s19, s14 */
/* @0x175bd8 vadd.f32 s17, s17, s13 */
/* @0x175bdc vsub.f32 s16, s16, s15 */
/* @0x175be0 ldrsh r1, [r4, #10] */
/* @0x175be4 vmov s15, r1 */
/* @0x175be8 vcvt.f32.s32 s15, s15 */
/* @0x175bec vcmpe.f32 s15, s21 */
/* @0x175bf0 vmrs APSR_nzcv, fpscr */
/* @0x175bf4 vsuble.f32 s21, s21, s15 */
/* @0x175bf8 ble 0x175c38 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x1a8> */
/* @0x175bfc vldr s5, [sp, #132] */
/* @0x175c00 vldr s9, [sp, #136] */
/* @0x175c04 vsub.f32 s14, s15, s21 */
/* @0x175c08 vldr s21, [pc, #620] */
/* @0x175c0c vmul.f32 s13, s23, s14 */
/* @0x175c10 vmul.f32 s15, s12, s14 */
/* @0x175c14 vmul.f32 s13, s13, s5 */
/* @0x175c18 vmul.f32 s15, s15, s9 */
/* @0x175c1c vcvt.s32.f32 s13, s13 */
/* @0x175c20 vcvt.s32.f32 s15, s15 */
/* @0x175c24 vcvt.f32.s32 s13, s13 */
/* @0x175c28 vcvt.f32.s32 s15, s15 */
/* @0x175c2c vsub.f32 s18, s18, s14 */
/* @0x175c30 vadd.f32 s17, s17, s13 */
/* @0x175c34 vadd.f32 s16, s16, s15 */
/* @0x175c38 ldrsh r1, [r4, #12] */
/* @0x175c3c vldr s11, [pc, #572] */
/* @0x175c40 ldrsh r2, [r4, #14] */
/* @0x175c44 vldr s13, [pc, #560] */
/* @0x175c48 vldr s5, [sp, #132] */
/* @0x175c4c vldr s9, [sp, #136] */
/* @0x175c50 vmov s14, r1 */
/* @0x175c54 ldrsh r1, [r4, #20] */
/* @0x175c58 vmov s15, r2 */
/* @0x175c5c ldr r2, [pc, #0x224] */
/* @0x175c60 ldr r2, [pc, r2] */
/* @0x175c64 vcvt.f32.s32 s14, s14 */
/* @0x175c68 ldr r3, [r2, #0x4] */
/* @0x175c6c ldr r3, [r3, r1, lsl #2] */
/* @0x175c70 vcvt.f32.s32 s15, s15 */
/* @0x175c74 vcmpe.f32 s19, s14 */
/* @0x175c78 vabs.f32 s20, s20 */
/* @0x175c7c vmrs APSR_nzcv, fpscr */
/* @0x175c80 vcmpe.f32 s18, s15 */
/* @0x175c84 vmovle.f32 s14, s19 */
/* @0x175c88 vmrs APSR_nzcv, fpscr */
/* @0x175c8c vmov.f32 s10, s13 */
/* @0x175c90 vcmpe.f32 s20, s11 */
/* @0x175c94 vmovle.f32 s15, s18 */
/* @0x175c98 vmrs APSR_nzcv, fpscr */
/* @0x175c9c vmov.f32 s11, s13 */
/* @0x175ca0 vmla.f32 s10, s5, s14 */
/* @0x175ca4 vmla.f32 s11, s9, s15 */
/* @0x175ca8 bmi 0x175da0 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x310> */
/* @0x175cac ldrsh r2, [r4] */
/* @0x175cb0 vldr s6, [r3, #8] */
/* @0x175cb4 ldrsh r4, [r4, #2] */
/* @0x175cb8 vldr s7, [r3, #12] */
/* @0x175cbc ldr r0, [r3] */
/* @0x175cc0 vmov s5, r2 */
/* @0x175cc4 str r9, [sp, #0x24] */
/* @0x175cc8 vmov s8, r4 */
/* @0x175ccc str r8, [sp, #0x28] */
/* @0x175cd0 str r7, [sp, #0x2c] */
/* @0x175cd4 str r6, [sp, #0x30] */
/* @0x175cd8 vcvt.f32.s32 s5, s5 */
/* @0x175cdc vcvt.f32.s32 s8, s8 */
/* @0x175ce0 vadd.f32 s22, s5, s22 */
/* @0x175ce4 vadd.f32 s21, s8, s21 */
/* @0x175ce8 vmov.f32 s5, s16 */
/* @0x175cec vmov.f32 s8, s17 */
/* @0x175cf0 vmul.f32 s9, s12, s13 */
/* @0x175cf4 vadd.f32 s14, s14, s22 */
/* @0x175cf8 vmul.f32 s13, s23, s13 */
/* @0x175cfc vadd.f32 s15, s15, s21 */
/* @0x175d00 vmls.f32 s5, s10, s23 */
/* @0x175d04 vmla.f32 s8, s10, s12 */
/* @0x175d08 vmul.f32 s23, s11, s23 */
/* @0x175d0c vmul.f32 s12, s11, s12 */
/* @0x175d10 vmul.f32 s14, s6, s14 */
/* @0x175d14 vmul.f32 s15, s7, s15 */
/* @0x175d18 vstr s14, [sp, #28] */
/* @0x175d1c vadd.f32 s17, s9, s17 */
/* @0x175d20 vstr s15, [sp, #32] */
/* @0x175d24 vsub.f32 s16, s16, s13 */
/* @0x175d28 vmul.f32 s22, s22, s6 */
/* @0x175d2c vmul.f32 s21, s21, s7 */
/* @0x175d30 vstr s22, [sp, #20] */
/* @0x175d34 vadd.f32 s14, s17, s23 */
/* @0x175d38 vstr s21, [sp, #24] */
/* @0x175d3c vadd.f32 s15, s16, s12 */
/* @0x175d40 vstr s14, [sp, #12] */
/* @0x175d44 vadd.f32 s23, s8, s23 */
/* @0x175d48 vstr s15, [sp, #16] */
/* @0x175d4c vadd.f32 s12, s5, s12 */
/* @0x175d50 vstr s23, [sp, #4] */
/* @0x175d54 vadd.f32 s10, s9, s5 */
/* @0x175d58 vstr s12, [sp, #8] */
/* @0x175d5c vadd.f32 s17, s17, s13 */
/* @0x175d60 vstr s10, [sp] */
/* @0x175d64 vadd.f32 s16, s9, s16 */
/* @0x175d68 vmov r1, s17 */
/* @0x175d6c vadd.f32 s8, s13, s8 */
/* @0x175d70 vmov r2, s16 */
/* @0x175d74 vmov r3, s8 */
/* @0x175d78 bl 0x17438c <_Z12DrawIt_ColorPvffffffffffffjjjj> */
/* @0x175d7c mov r0, r5 */
/* @0x175d80 add sp, sp, #60 */
/* @0x175d84 vpop {d8, d9, d10, d11} */
/* @0x175d88 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x175d8c mov r5, #0 */
/* @0x175d90 mov r0, r5 */
/* @0x175d94 add sp, sp, #60 */
/* @0x175d98 vpop {d8, d9, d10, d11} */
/* @0x175d9c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x175da0 ldrsh r1, [r4] */
/* @0x175da4 vldr s9, [r3, #8] */
/* @0x175da8 ldrsh r4, [r4, #2] */
/* @0x175dac vldr s12, [r3, #12] */
/* @0x175db0 vadd.f32 s10, s17, s10 */
/* @0x175db4 ldr r0, [r3] */
/* @0x175db8 vmov s7, r1 */
/* @0x175dbc str r9, [sp, #0x24] */
/* @0x175dc0 vmov s8, r4 */
/* @0x175dc4 str r8, [sp, #0x28] */
/* @0x175dc8 str r7, [sp, #0x2c] */
/* @0x175dcc str r6, [sp, #0x30] */
/* @0x175dd0 vcvt.f32.s32 s7, s7 */
/* @0x175dd4 vstr s10, [sp, #4] */
/* @0x175dd8 vmov r3, s10 */
/* @0x175ddc vcvt.f32.s32 s8, s8 */
/* @0x175de0 vadd.f32 s22, s7, s22 */
/* @0x175de4 vadd.f32 s21, s8, s21 */
/* @0x175de8 vadd.f32 s14, s14, s22 */
/* @0x175dec vadd.f32 s15, s15, s21 */
/* @0x175df0 vmul.f32 s14, s9, s14 */
/* @0x175df4 vmul.f32 s22, s22, s9 */
/* @0x175df8 vstr s14, [sp, #28] */
/* @0x175dfc vmul.f32 s15, s12, s15 */
/* @0x175e00 vstr s22, [sp, #20] */
/* @0x175e04 vmul.f32 s21, s21, s12 */
/* @0x175e08 vstr s15, [sp, #32] */
/* @0x175e0c vadd.f32 s17, s17, s13 */
/* @0x175e10 vstr s21, [sp, #24] */
/* @0x175e14 vadd.f32 s13, s16, s13 */
/* @0x175e18 vstr s17, [sp, #12] */
/* @0x175e1c vmov r1, s17 */
/* @0x175e20 vadd.f32 s16, s16, s11 */
/* @0x175e24 vstr s13, [sp] */
/* @0x175e28 vmov r2, s13 */
/* @0x175e2c vstr s16, [sp, #8] */
/* @0x175e30 vstr s16, [sp, #16] */
/* @0x175e34 bl 0x17438c <_Z12DrawIt_ColorPvffffffffffffjjjj> */
/* @0x175e38 mov r0, r5 */
/* @0x175e3c add sp, sp, #60 */
/* @0x175e40 vpop {d8, d9, d10, d11} */
/* @0x175e44 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x175e48 vldr d7, [pc, #32] */
/* @0x175e4c b 0x175af8 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x68> */
/* @0x175e50 vcmpe.f32 s14, #0 */
/* @0x175e54 vmrs APSR_nzcv, fpscr */
/* @0x175e58 bmi 0x175e48 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x3b8> */
/* @0x175e5c vcvt.f64.f32 d7, s14 */
/* @0x175e60 b 0x175af8 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x68> */
/* @0x175e64 nop */
/* @0x175e68 andeq r0, r0, r0 */
/* @0x175e6c rsbmi lr, pc, r0 */
/* @0x175e78 cmnmi pc, #0 */
/* @0x175e7c andeq r0, r0, r0 */
/* @0x175e80 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x175e84 eoreq r8, r7, r12, lsr r3 */
/* @0x175e88 .word 0x00277cbc */

/* ── FUNC 0x175e8c · anon_175e8c · size=0 · insn=1 */
/* @0x175e8c nop */

/* ── FUNC 0x175e90 · GR_Texture_Draw_Tiled(int, float, float, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float) · size=1052 · insn=261 */
/* @0x175e90 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x175e94 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x175e98 sub sp, sp, #28 */
/* @0x175e9c vldr s17, [sp, #116] */
/* @0x175ea0 vmov s21, r2 */
/* @0x175ea4 mov r5, r0 */
/* @0x175ea8 ldrb r2, [sp, #0x7c] */
/* @0x175eac vmov s18, r3 */
/* @0x175eb0 ldrb r3, [sp, #0x80] */
/* @0x175eb4 vmov s25, r1 */
/* @0x175eb8 vldr s16, [sp, #120] */
/* @0x175ebc vldr s27, [sp, #132] */
/* @0x175ec0 str r2, [sp, #0xc] */
/* @0x175ec4 vldr s24, [sp, #136] */
/* @0x175ec8 str r3, [sp, #0x10] */
/* @0x175ecc ldr r4, [sp, #0x94] */
/* @0x175ed0 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x175ed4 ldr r8, [pc, #0x3c4] */
/* @0x175ed8 add r8, pc, r8 */
/* @0x175edc cmp r0, #0 */
/* @0x175ee0 str r0, [sp, #0x14] */
/* @0x175ee4 beq 0x176140 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2b0> */
/* @0x175ee8 ldr r3, [pc, #0x3b4] */
/* @0x175eec ldr r7, [r8, r3] */
/* @0x175ef0 ldr r3, [r7, #0x4] */
/* @0x175ef4 ldr r3, [r3, r5, lsl #2] */
/* @0x175ef8 ldrsh r2, [r3, #4] */
/* @0x175efc ldrsh r3, [r3, #6] */
/* @0x175f00 vmov s14, r2 */
/* @0x175f04 vmov s15, r3 */
/* @0x175f08 vcvt.f32.s32 s14, s14 */
/* @0x175f0c vcvt.f32.s32 s15, s15 */
/* @0x175f10 vmul.f32 s14, s14, s17 */
/* @0x175f14 vmul.f32 s15, s15, s16 */
/* @0x175f18 vcvt.s32.f32 s14, s14 */
/* @0x175f1c vcvt.s32.f32 s15, s15 */
/* @0x175f20 vmov r9, s14 */
/* @0x175f24 vmov r6, s15 */
/* @0x175f28 cmp r6, #0 */
/* @0x175f2c cmpgt r9, #0 */
/* @0x175f30 movle r2, #0 */
/* @0x175f34 strle r2, [sp, #0x14] */
/* @0x175f38 ble 0x176140 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2b0> */
/* @0x175f3c vldr s15, [pc, #852] */
/* @0x175f40 vldr s12, [sp, #152] */
/* @0x175f44 vmul.f32 s14, s12, s15 */
/* @0x175f48 vcmpe.f32 s14, #0 */
/* @0x175f4c vmrs APSR_nzcv, fpscr */
/* @0x175f50 bmi 0x17627c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x3ec> */
/* @0x175f54 vcmpe.f32 s14, s15 */
/* @0x175f58 vmrs APSR_nzcv, fpscr */
/* @0x175f5c ble 0x176150 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2c0> */
/* @0x175f60 vldr d7, [pc, #800] */
/* @0x175f64 vmov r0, r1, d7 */
/* @0x175f68 bl 0xb66e8 <lrint@plt> */
/* @0x175f6c ldr r12, [r7, #0x4] */
/* @0x175f70 vnmul.f32 s25, s17, s25 */
/* @0x175f74 uxtb r1, r4 */
/* @0x175f78 ubfx r2, r4, #0x10, #0x8 */
/* @0x175f7c and r3, r4, #65280 */
/* @0x175f80 ldr r4, [r12, r5, lsl #2] */
/* @0x175f84 orr r5, r2, r1, lsl #16 */
/* @0x175f88 orr r5, r5, r3 */
/* @0x175f8c ldrsh r2, [r4, #4] */
/* @0x175f90 ldrsh r3, [r4, #6] */
/* @0x175f94 vmov s14, r2 */
/* @0x175f98 vmov s15, r3 */
/* @0x175f9c vnmul.f32 s21, s16, s21 */
/* @0x175fa0 vcvt.f64.f32 d6, s18 */
/* @0x175fa4 vcvt.f32.s32 s14, s14 */
/* @0x175fa8 orr r5, r5, r0, lsl #24 */
/* @0x175fac vmov r0, r1, d6 */
/* @0x175fb0 vcvt.f32.s32 s15, s15 */
/* @0x175fb4 vmov.f32 s26, s25 */
/* @0x175fb8 vmov.f32 s22, s21 */
/* @0x175fbc vmla.f32 s26, s14, s17 */
/* @0x175fc0 vmla.f32 s22, s15, s16 */
/* @0x175fc4 bl 0xb66e8 <lrint@plt> */
/* @0x175fc8 ldr r2, [sp, #0xc] */
/* @0x175fcc cmp r2, #0 */
/* @0x175fd0 mov r7, r0 */
/* @0x175fd4 beq 0x176008 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x178> */
/* @0x175fd8 mov r1, r9 */
/* @0x175fdc bl 0x318dec <__aeabi_idivmod> */
/* @0x175fe0 subs r7, r1, #0 */
/* @0x175fe4 rsbgt r7, r9, r7 */
/* @0x175fe8 b 0x175ff0 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x160> */
/* @0x175fec mov r7, r3 */
/* @0x175ff0 add r3, r7, r9 */
/* @0x175ff4 vmov s14, r3 */
/* @0x175ff8 vcvt.f32.s32 s15, s14 */
/* @0x175ffc vcmpe.f32 s15, s27 */
/* @0x176000 vmrs APSR_nzcv, fpscr */
/* @0x176004 bmi 0x175fec <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x15c> */
/* @0x176008 vldr s12, [sp, #140] */
/* @0x17600c vadd.f32 s27, s27, s12 */
/* @0x176010 vmov s13, r7 */
/* @0x176014 vcvt.f32.s32 s19, s13 */
/* @0x176018 vcmpe.f32 s19, s27 */
/* @0x17601c vmrs APSR_nzcv, fpscr */
/* @0x176020 bpl 0x176140 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2b0> */
/* @0x176024 vldr s15, [sp, #144] */
/* @0x176028 vadd.f32 s23, s24, s15 */
/* @0x17602c vldr s13, [sp, #112] */
/* @0x176030 vldr s17, [pc, #612] */
/* @0x176034 vcvt.f64.f32 d6, s13 */
/* @0x176038 vstr d6, [sp] */
/* @0x17603c ldrd r0, r1, [sp] */
/* @0x176040 bl 0xb66e8 <lrint@plt> */
/* @0x176044 ldr r2, [sp, #0x10] */
/* @0x176048 cmp r2, #0 */
/* @0x17604c bne 0x176164 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2d4> */
/* @0x176050 vmov s12, r0 */
/* @0x176054 vcvt.f32.s32 s16, s12 */
/* @0x176058 vcmpe.f32 s16, s23 */
/* @0x17605c vmrs APSR_nzcv, fpscr */
/* @0x176060 bpl 0x17611c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x28c> */
/* @0x176064 mov r2, #24 */
/* @0x176068 mov r3, #4 */
/* @0x17606c mov r0, #6 */
/* @0x176070 ldr r1, [r4] */
/* @0x176074 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x176078 ldr r3, [pc, #0x228] */
/* @0x17607c vadd.f32 s14, s25, s19 */
/* @0x176080 ldr r11, [r8, r3] */
/* @0x176084 ldr r3, [r11] */
/* @0x176088 vadd.f32 s19, s26, s19 */
/* @0x17608c vstr s17, [r0, #16] */
/* @0x176090 vstr s17, [r0, #20] */
/* @0x176094 ldrsh r2, [r4, #4] */
/* @0x176098 vldr s15, [r4, #8] */
/* @0x17609c vstr s17, [r0, #44] */
/* @0x1760a0 str r5, [r0, #0xc] */
/* @0x1760a4 str r3, [r0, #0x8] */
/* @0x1760a8 vmov s13, r2 */
/* @0x1760ac str r3, [r0, #0x20] */
/* @0x1760b0 str r5, [r0, #0x24] */
/* @0x1760b4 vcvt.f32.s32 s13, s13 */
/* @0x1760b8 str r3, [r0, #0x38] */
/* @0x1760bc str r5, [r0, #0x3c] */
/* @0x1760c0 vmul.f32 s13, s13, s15 */
/* @0x1760c4 vstr s13, [r0, #40] */
/* @0x1760c8 vstr s13, [r0, #64] */
/* @0x1760cc ldrsh r2, [r4, #6] */
/* @0x1760d0 vldr s15, [r4, #12] */
/* @0x1760d4 vstr s14, [r0] */
/* @0x1760d8 vstr s14, [r0, #72] */
/* @0x1760dc vadd.f32 s14, s21, s16 */
/* @0x1760e0 str r3, [r0, #0x50] */
/* @0x1760e4 vmov s13, r2 */
/* @0x1760e8 str r5, [r0, #0x54] */
/* @0x1760ec vstr s17, [r0, #88] */
/* @0x1760f0 vstr s19, [r0, #24] */
/* @0x1760f4 vstr s19, [r0, #48] */
/* @0x1760f8 vcvt.f32.s32 s13, s13 */
/* @0x1760fc vstr s14, [r0, #4] */
/* @0x176100 vstr s14, [r0, #28] */
/* @0x176104 vmul.f32 s13, s13, s15 */
/* @0x176108 vadd.f32 s15, s22, s16 */
/* @0x17610c vstr s13, [r0, #68] */
/* @0x176110 vstr s13, [r0, #92] */
/* @0x176114 vstr s15, [r0, #52] */
/* @0x176118 vstr s15, [r0, #76] */
/* @0x17611c ldr r3, [sp, #0xc] */
/* @0x176120 cmp r3, #0 */
/* @0x176124 beq 0x176140 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2b0> */
/* @0x176128 add r7, r7, r9 */
/* @0x17612c vmov s13, r7 */
/* @0x176130 vcvt.f32.s32 s19, s13 */
/* @0x176134 vcmpe.f32 s19, s27 */
/* @0x176138 vmrs APSR_nzcv, fpscr */
/* @0x17613c bmi 0x17603c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x1ac> */
/* @0x176140 ldr r0, [sp, #0x14] */
/* @0x176144 add sp, sp, #28 */
/* @0x176148 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x17614c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x176150 vcmpe.f32 s14, #0 */
/* @0x176154 vmrs APSR_nzcv, fpscr */
/* @0x176158 bmi 0x17627c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x3ec> */
/* @0x17615c vcvt.f64.f32 d7, s14 */
/* @0x176160 b 0x175f64 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0xd4> */
/* @0x176164 mov r1, r6 */
/* @0x176168 bl 0x318dec <__aeabi_idivmod> */
/* @0x17616c cmp r1, #0 */
/* @0x176170 rsbgt r1, r6, r1 */
/* @0x176174 b 0x17617c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2ec> */
/* @0x176178 mov r1, r10 */
/* @0x17617c add r10, r1, r6 */
/* @0x176180 vmov s12, r10 */
/* @0x176184 vcvt.f32.s32 s15, s12 */
/* @0x176188 vcmpe.f32 s15, s24 */
/* @0x17618c vmrs APSR_nzcv, fpscr */
/* @0x176190 bmi 0x176178 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2e8> */
/* @0x176194 vmov s13, r1 */
/* @0x176198 vcvt.f32.s32 s18, s13 */
/* @0x17619c vcmpe.f32 s18, s23 */
/* @0x1761a0 vmrs APSR_nzcv, fpscr */
/* @0x1761a4 bpl 0x17611c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x28c> */
/* @0x1761a8 vadd.f32 s20, s25, s19 */
/* @0x1761ac ldr r3, [pc, #0xf4] */
/* @0x1761b0 ldr r11, [r8, r3] */
/* @0x1761b4 vadd.f32 s19, s26, s19 */
/* @0x1761b8 mov r2, #24 */
/* @0x1761bc mov r3, #4 */
/* @0x1761c0 mov r0, #6 */
/* @0x1761c4 ldr r1, [r4] */
/* @0x1761c8 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1761cc vmov s12, r10 */
/* @0x1761d0 add r10, r10, r6 */
/* @0x1761d4 vadd.f32 s14, s21, s18 */
/* @0x1761d8 vadd.f32 s18, s22, s18 */
/* @0x1761dc vstr s17, [r0, #16] */
/* @0x1761e0 vstr s17, [r0, #20] */
/* @0x1761e4 ldrsh r3, [r4, #4] */
/* @0x1761e8 vldr s13, [r4, #8] */
/* @0x1761ec vstr s17, [r0, #44] */
/* @0x1761f0 str r5, [r0, #0xc] */
/* @0x1761f4 str r5, [r0, #0x24] */
/* @0x1761f8 vmov s15, r3 */
/* @0x1761fc ldr r3, [r11] */
/* @0x176200 str r5, [r0, #0x3c] */
/* @0x176204 vcvt.f32.s32 s15, s15 */
/* @0x176208 str r3, [r0, #0x8] */
/* @0x17620c str r3, [r0, #0x20] */
/* @0x176210 str r3, [r0, #0x38] */
/* @0x176214 vmul.f32 s15, s15, s13 */
/* @0x176218 vstr s15, [r0, #40] */
/* @0x17621c vstr s15, [r0, #64] */
/* @0x176220 ldrsh r2, [r4, #6] */
/* @0x176224 vldr s13, [r4, #12] */
/* @0x176228 vstr s18, [r0, #52] */
/* @0x17622c vstr s18, [r0, #76] */
/* @0x176230 vcvt.f32.s32 s18, s12 */
/* @0x176234 str r5, [r0, #0x54] */
/* @0x176238 vmov s15, r2 */
/* @0x17623c vstr s17, [r0, #88] */
/* @0x176240 vstr s19, [r0, #24] */
/* @0x176244 vstr s19, [r0, #48] */
/* @0x176248 vstr s20, [r0, #72] */
/* @0x17624c vstr s14, [r0, #4] */
/* @0x176250 vstr s14, [r0, #28] */
/* @0x176254 str r3, [r0, #0x50] */
/* @0x176258 vstr s20, [r0] */
/* @0x17625c vcvt.f32.s32 s15, s15 */
/* @0x176260 vmul.f32 s15, s15, s13 */
/* @0x176264 vcmpe.f32 s18, s23 */
/* @0x176268 vstr s15, [r0, #68] */
/* @0x17626c vstr s15, [r0, #92] */
/* @0x176270 vmrs APSR_nzcv, fpscr */
/* @0x176274 bmi 0x1761b8 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x328> */
/* @0x176278 b 0x17611c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x28c> */
/* @0x17627c vldr d7, [pc, #12] */
/* @0x176280 b 0x175f64 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0xd4> */
/* @0x176284 nop */
/* @0x176288 andeq r0, r0, r0 */
/* @0x17628c rsbmi lr, pc, r0 */
/* @0x176298 cmnmi pc, #0 */
/* @0x17629c andeq r0, r0, r0 */
/* @0x1762a0 eoreq r11, r7, r8, ror sp */
/* @0x1762a4 .word 0xffffbccc */
/* @0x1762a8 .word 0xffffbcd0 */

/* ── FUNC 0x1762ac · anon_1762ac · size=0 · insn=1 */
/* @0x1762ac nop */

/* ── FUNC 0x1762b0 · GR_Texture_Draw_Tiled(YYTPageEntry*, float, float, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float) · size=1308 · insn=327 */
/* @0x1762b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1762b4 vpush {d8, d9, d10, d11, d12, d13} */
/* @0x1762b8 subs r9, r0, #0 */
/* @0x1762bc sub sp, sp, #68 */
/* @0x1762c0 ldr r12, [pc, #0x3d4] */
/* @0x1762c4 mov r6, r1 */
/* @0x1762c8 mov r7, r2 */
/* @0x1762cc add r12, pc, r12 */
/* @0x1762d0 vmov s26, r3 */
/* @0x1762d4 str r12, [sp, #0x34] */
/* @0x1762d8 vldr s23, [sp, #156] */
/* @0x1762dc vldr s25, [sp, #160] */
/* @0x1762e0 ldrb r5, [sp, #0xa4] */
/* @0x1762e4 ldrb r4, [sp, #0xa8] */
/* @0x1762e8 beq 0x176308 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x58> */
/* @0x1762ec vldr s15, [pc, #928] */
/* @0x1762f0 vcmpe.f32 s23, s15 */
/* @0x1762f4 vmrs APSR_nzcv, fpscr */
/* @0x1762f8 bmi 0x176308 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x58> */
/* @0x1762fc vcmpe.f32 s25, s15 */
/* @0x176300 vmrs APSR_nzcv, fpscr */
/* @0x176304 bpl 0x176320 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x70> */
/* @0x176308 mov r12, #0 */
/* @0x17630c str r12, [sp, #0x38] */
/* @0x176310 ldr r0, [sp, #0x38] */
/* @0x176314 add sp, sp, #68 */
/* @0x176318 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x17631c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x176320 ldrsh r0, [r9, #20] */
/* @0x176324 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x176328 cmp r0, #0 */
/* @0x17632c str r0, [sp, #0x38] */
/* @0x176330 beq 0x176308 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x58> */
/* @0x176334 ldr r3, [pc, #0x364] */
/* @0x176338 ldr r12, [sp, #0x34] */
/* @0x17633c ldr r3, [r12, r3] */
/* @0x176340 ldrb r3, [r3] */
/* @0x176344 cmp r3, #0 */
/* @0x176348 bne 0x1766b8 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x408> */
/* @0x17634c eor r2, r5, #1 */
/* @0x176350 eor r3, r4, #1 */
/* @0x176354 tst r2, r3 */
/* @0x176358 bne 0x1766e4 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x434> */
/* @0x17635c ldrsh r1, [r9, #16] */
/* @0x176360 cmp r5, #0 */
/* @0x176364 ldrsh r2, [r9, #18] */
/* @0x176368 ldr r3, [pc, #0x334] */
/* @0x17636c vmov s17, r1 */
/* @0x176370 ldr r12, [sp, #0x34] */
/* @0x176374 vmov s16, r2 */
/* @0x176378 vcvt.f32.s32 s17, s17 */
/* @0x17637c ldr r3, [r12, r3] */
/* @0x176380 ldm r3, {r2, r5} */
/* @0x176384 ldr r1, [r3, #0x8] */
/* @0x176388 ldr r6, [r3, #0xc] */
/* @0x17638c vmul.f32 s17, s17, s23 */
/* @0x176390 vcvt.f32.s32 s16, s16 */
/* @0x176394 vmoveq.f32 s19, s17 */
/* @0x176398 vmul.f32 s16, s16, s25 */
/* @0x17639c bne 0x176724 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x474> */
/* @0x1763a0 cmp r4, #0 */
/* @0x1763a4 vmoveq.f32 s18, s16 */
/* @0x1763a8 bne 0x176774 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x4c4> */
/* @0x1763ac vldr s15, [pc, #740] */
/* @0x1763b0 vldr s12, [sp, #192] */
/* @0x1763b4 vmul.f32 s15, s12, s15 */
/* @0x1763b8 vcvt.s32.f32 s15, s15 */
/* @0x1763bc vmov r6, s15 */
/* @0x1763c0 cmp r6, #255 */
/* @0x1763c4 movgt r6, #-16777216 */
/* @0x1763c8 bgt 0x1763d8 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x128> */
/* @0x1763cc cmp r6, #0 */
/* @0x1763d0 lslge r6, r6, #24 */
/* @0x1763d4 movlt r6, #0 */
/* @0x1763d8 vdiv.f32 s16, s18, s16 */
/* @0x1763dc ldr r12, [sp, #0x34] */
/* @0x1763e0 ldr r3, [pc, #0x2c0] */
/* @0x1763e4 ldr r1, [sp, #0xbc] */
/* @0x1763e8 ldrsh r0, [r9, #6] */
/* @0x1763ec ldr r3, [r12, r3] */
/* @0x1763f0 bic r2, r1, #-16777216 */
/* @0x1763f4 orr r6, r6, r2 */
/* @0x1763f8 ldrsh r1, [r9, #4] */
/* @0x1763fc ldrsh r2, [r9] */
/* @0x176400 ldrb r3, [r3] */
/* @0x176404 add r1, r2, r1 */
/* @0x176408 cmp r3, #0 */
/* @0x17640c ldrsh r3, [r9, #2] */
/* @0x176410 bicne r6, r6, #65536 */
/* @0x176414 vmov s20, r1 */
/* @0x176418 bicne r6, r6, #1 */
/* @0x17641c ldrsh r1, [r9, #14] */
/* @0x176420 orrne r12, r6, #1 */
/* @0x176424 strne r12, [sp, #0x20] */
/* @0x176428 ldrsh r12, [r9, #12] */
/* @0x17642c add r0, r3, r0 */
/* @0x176430 vmov s27, r1 */
/* @0x176434 ldr r1, [pc, #0x270] */
/* @0x176438 vmov s12, r2 */
/* @0x17643c streq r6, [sp, #0x20] */
/* @0x176440 vmov s24, r12 */
/* @0x176444 ldr r12, [sp, #0x34] */
/* @0x176448 vmov s22, r0 */
/* @0x17644c ldrsh r0, [r9, #20] */
/* @0x176450 orrne r7, r6, #65536 */
/* @0x176454 moveq r11, r6 */
/* @0x176458 ldr r1, [r12, r1] */
/* @0x17645c orrne r11, r7, #1 */
/* @0x176460 moveq r7, r6 */
/* @0x176464 ldr r1, [r1, #0x4] */
/* @0x176468 ldr r1, [r1, r0, lsl #2] */
/* @0x17646c vldr s15, [r1, #12] */
/* @0x176470 vldr s14, [r1, #8] */
/* @0x176474 str r1, [sp, #0x24] */
/* @0x176478 vdiv.f32 s17, s19, s17 */
/* @0x17647c vcvt.f32.s32 s13, s12 */
/* @0x176480 vmov s12, r3 */
/* @0x176484 vcvt.f32.s32 s20, s20 */
/* @0x176488 vcvt.f32.s32 s21, s12 */
/* @0x17648c vcvt.f32.s32 s22, s22 */
/* @0x176490 vcvt.s32.f32 s16, s16 */
/* @0x176494 vmul.f32 s21, s21, s15 */
/* @0x176498 vstr s16, [sp, #60] */
/* @0x17649c vmul.f32 s22, s15, s22 */
/* @0x1764a0 vmul.f32 s19, s13, s14 */
/* @0x1764a4 vmul.f32 s20, s14, s20 */
/* @0x1764a8 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv> */
/* @0x1764ac ldrsh r1, [r9, #10] */
/* @0x1764b0 ldr r12, [sp, #0x3c] */
/* @0x1764b4 vmov s15, r1 */
/* @0x1764b8 cmp r12, #0 */
/* @0x1764bc vcvt.s32.f32 s17, s17 */
/* @0x1764c0 vmov r10, s17 */
/* @0x1764c4 vldr s17, [sp, #152] */
/* @0x1764c8 vcvt.f32.s32 s27, s27 */
/* @0x1764cc vcvt.f32.s32 s24, s24 */
/* @0x1764d0 str r0, [sp, #0x2c] */
/* @0x1764d4 vcvt.f32.s32 s15, s15 */
/* @0x1764d8 add r8, r10, r10, lsl #1 */
/* @0x1764dc lsl r8, r8, #1 */
/* @0x1764e0 vmul.f32 s27, s27, s25 */
/* @0x1764e4 mul r8, r12, r8 */
/* @0x1764e8 vmul.f32 s24, s24, s23 */
/* @0x1764ec vmla.f32 s17, s15, s25 */
/* @0x1764f0 ble 0x176310 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x60> */
/* @0x1764f4 mov r3, #0 */
/* @0x1764f8 mov r12, #0 */
/* @0x1764fc mov r4, r3 */
/* @0x176500 str r12, [sp, #0x30] */
/* @0x176504 movw r12, #0xaaab */
/* @0x176508 movt r12, #0x2aaa */
/* @0x17650c str r12, [sp, #0x28] */
/* @0x176510 mov r12, r11 */
/* @0x176514 ldrsh r1, [r9, #8] */
/* @0x176518 cmp r10, #0 */
/* @0x17651c vmov s15, r1 */
/* @0x176520 vcvt.f32.s32 s15, s15 */
/* @0x176524 vmov.f32 s16, s26 */
/* @0x176528 vmla.f32 s16, s15, s23 */
/* @0x17652c ble 0x176668 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x3b8> */
/* @0x176530 ldr r2, [pc, #0x178] */
/* @0x176534 mov r5, #0 */
/* @0x176538 ldr r1, [sp, #0x34] */
/* @0x17653c ldr r11, [r1, r2] */
/* @0x176540 mov r2, r11 */
/* @0x176544 mov r11, r12 */
/* @0x176548 mov r12, r2 */
/* @0x17654c vadd.f32 s18, s17, s27 */
/* @0x176550 cmp r4, #0 */
/* @0x176554 add r5, r5, #1 */
/* @0x176558 mov r0, #4 */
/* @0x17655c mov r2, #24 */
/* @0x176560 bne 0x1765a8 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x2f8> */
/* @0x176564 ldr r4, [sp, #0x2c] */
/* @0x176568 ldr r1, [sp, #0x28] */
/* @0x17656c cmp r4, r8 */
/* @0x176570 movge r4, r8 */
/* @0x176574 cmp r4, #6 */
/* @0x176578 smull r1, r3, r1, r4 */
/* @0x17657c subgt r4, r3, r4, asr #31 */
/* @0x176580 ldr r3, [sp, #0x24] */
/* @0x176584 addgt r4, r4, r4, lsl #1 */
/* @0x176588 ldr r1, [r3] */
/* @0x17658c lslgt r4, r4, #1 */
/* @0x176590 str r12, [sp, #0x1c] */
/* @0x176594 rsb r8, r4, r8 */
/* @0x176598 mov r3, r4 */
/* @0x17659c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1765a0 ldr r12, [sp, #0x1c] */
/* @0x1765a4 mov r3, r0 */
/* @0x1765a8 vadd.f32 s15, s16, s24 */
/* @0x1765ac ldr r2, [r12] */
/* @0x1765b0 ldr r1, [sp, #0x20] */
/* @0x1765b4 vstr s16, [r3, #24] */
/* @0x1765b8 vstr s16, [r3] */
/* @0x1765bc str r6, [r3, #0x84] */
/* @0x1765c0 str r2, [r3, #0x80] */
/* @0x1765c4 vstr s18, [r3, #4] */
/* @0x1765c8 str r2, [r3, #0x68] */
/* @0x1765cc vstr s19, [r3, #16] */
/* @0x1765d0 str r2, [r3, #0x50] */
/* @0x1765d4 vstr s22, [r3, #20] */
/* @0x1765d8 str r2, [r3, #0x38] */
/* @0x1765dc vstr s17, [r3, #28] */
/* @0x1765e0 str r2, [r3, #0x20] */
/* @0x1765e4 vstr s19, [r3, #40] */
/* @0x1765e8 str r6, [r3, #0xc] */
/* @0x1765ec vstr s21, [r3, #44] */
/* @0x1765f0 str r1, [r3, #0x24] */
/* @0x1765f4 vstr s17, [r3, #52] */
/* @0x1765f8 vstr s15, [r3, #48] */
/* @0x1765fc vstr s15, [r3, #72] */
/* @0x176600 vstr s15, [r3, #96] */
/* @0x176604 str r7, [r3, #0x54] */
/* @0x176608 str r7, [r3, #0x3c] */
/* @0x17660c vstr s20, [r3, #64] */
/* @0x176610 str r11, [r3, #0x6c] */
/* @0x176614 vstr s21, [r3, #68] */
/* @0x176618 vstr s17, [r3, #76] */
/* @0x17661c vstr s20, [r3, #88] */
/* @0x176620 vstr s21, [r3, #92] */
/* @0x176624 vstr s18, [r3, #100] */
/* @0x176628 vstr s20, [r3, #112] */
/* @0x17662c vstr s22, [r3, #116] */
/* @0x176630 str r2, [r3, #0x8] */
/* @0x176634 vstr s19, [r3, #136] */
/* @0x176638 vstr s22, [r3, #140] */
/* @0x17663c ldrsh r2, [r9, #16] */
/* @0x176640 cmp r5, r10 */
/* @0x176644 vstr s16, [r3, #120] */
/* @0x176648 vstr s18, [r3, #124] */
/* @0x17664c sub r4, r4, #6 */
/* @0x176650 vmov s15, r2 */
/* @0x176654 add r3, r3, #144 */
/* @0x176658 vcvt.f32.s32 s15, s15 */
/* @0x17665c vmla.f32 s16, s15, s23 */
/* @0x176660 bne 0x176550 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x2a0> */
/* @0x176664 mov r12, r11 */
/* @0x176668 ldrsh r1, [r9, #18] */
/* @0x17666c ldr r2, [sp, #0x30] */
/* @0x176670 vmov s15, r1 */
/* @0x176674 ldr r1, [sp, #0x3c] */
/* @0x176678 add r2, r2, #1 */
/* @0x17667c str r2, [sp, #0x30] */
/* @0x176680 vcvt.f32.s32 s15, s15 */
/* @0x176684 cmp r2, r1 */
/* @0x176688 vmla.f32 s17, s15, s25 */
/* @0x17668c bne 0x176514 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x264> */
/* @0x176690 b 0x176310 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x60> */
/* @0x176694 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x176698 cmnmi pc, #0 */
/* @0x17669c eoreq r11, r7, r4, lsl #19 */
/* @0x1766a0 .word 0xffffbcd4 */
/* @0x1766a4 .word 0xffffe4fc */
/* @0x1766a8 .word 0xffffc1fc */
/* @0x1766ac .word 0xffffbccc */
/* @0x1766b0 .word 0xffffbcd0 */
/* @0x1766b4 .word 0xffffc024 */
/* @0x1766b8 ldr r3, [pc, #-0xc] */
/* @0x1766bc ldr r8, [r12, r3] */
/* @0x1766c0 mov r0, r8 */
/* @0x1766c4 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1766c8 cmp r0, #0 */
/* @0x1766cc beq 0x17634c <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x9c> */
/* @0x1766d0 mov r0, r8 */
/* @0x1766d4 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv> */
/* @0x1766d8 bl 0x16d398 <_ZN7CCamera4Is2DEv> */
/* @0x1766dc cmp r0, #0 */
/* @0x1766e0 bne 0x17634c <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x9c> */
/* @0x1766e4 ldr r1, [sp, #0xbc] */
/* @0x1766e8 vldr s12, [sp, #152] */
/* @0x1766ec mov r3, #0 */
/* @0x1766f0 vstr s12, [sp] */
/* @0x1766f4 str r3, [sp, #0xc] */
/* @0x1766f8 vldr s12, [sp, #192] */
/* @0x1766fc str r1, [sp, #0x10] */
/* @0x176700 vstr s23, [sp, #4] */
/* @0x176704 vstr s25, [sp, #8] */
/* @0x176708 vstr s12, [sp, #20] */
/* @0x17670c mov r0, r9 */
/* @0x176710 mov r1, r6 */
/* @0x176714 mov r2, r7 */
/* @0x176718 vmov r3, s26 */
/* @0x17671c bl 0x174ee0 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf> */
/* @0x176720 b 0x176310 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x60> */
/* @0x176724 vmov.f32 s14, #1.000000e+00 */
/* @0x176728 rsb r1, r2, r1 */
/* @0x17672c vmov s12, r2 */
/* @0x176730 vmov s15, r1 */
/* @0x176734 vmov r1, s17 */
/* @0x176738 vsub.f32 s14, s17, s14 */
/* @0x17673c vcvt.f32.s32 s15, s15 */
/* @0x176740 vadd.f32 s19, s14, s15 */
/* @0x176744 vdiv.f32 s19, s19, s17 */
/* @0x176748 vcvt.f32.s32 s18, s12 */
/* @0x17674c vsub.f32 s26, s26, s18 */
/* @0x176750 vmov.f32 s15, #2.000000e+00 */
/* @0x176754 vmov r0, s26 */
/* @0x176758 vadd.f32 s19, s19, s15 */
/* @0x17675c bl 0xb6790 <fmodf@plt> */
/* @0x176760 vmul.f32 s19, s19, s17 */
/* @0x176764 vmov s13, r0 */
/* @0x176768 vadd.f32 s18, s13, s18 */
/* @0x17676c vsub.f32 s26, s18, s17 */
/* @0x176770 b 0x1763a0 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0xf0> */
/* @0x176774 vmov.f32 s14, #1.000000e+00 */
/* @0x176778 rsb r6, r5, r6 */
/* @0x17677c vmov s13, r5 */
/* @0x176780 vmov s12, r6 */
/* @0x176784 vmov r1, s16 */
/* @0x176788 vsub.f32 s14, s16, s14 */
/* @0x17678c vcvt.f32.s32 s15, s12 */
/* @0x176790 vadd.f32 s18, s14, s15 */
/* @0x176794 vldr s14, [sp, #152] */
/* @0x176798 vdiv.f32 s18, s18, s16 */
/* @0x17679c vcvt.f32.s32 s20, s13 */
/* @0x1767a0 vsub.f32 s14, s14, s20 */
/* @0x1767a4 vmov.f32 s15, #2.000000e+00 */
/* @0x1767a8 vmov r0, s14 */
/* @0x1767ac vadd.f32 s18, s18, s15 */
/* @0x1767b0 bl 0xb6790 <fmodf@plt> */
/* @0x1767b4 vmul.f32 s18, s18, s16 */
/* @0x1767b8 vmov s15, r0 */
/* @0x1767bc vadd.f32 s20, s15, s20 */
/* @0x1767c0 vsub.f32 s20, s20, s16 */
/* @0x1767c4 vstr s20, [sp, #152] */
/* @0x1767c8 b 0x1763ac <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0xfc> */

/* ── FUNC 0x1767cc · FINALIZE_Graphics_Texture() · size=4 · insn=1 */
/* @0x1767cc b 0x1740e0 <_Z14GR_Texture_Endv> */

/* ── FUNC 0x1767d0 · Graphics::TextureFlush(bool) · size=96 · insn=24 */
/* @0x1767d0 ldr r3, [pc, #0x54] */
/* @0x1767d4 push {r4, lr} */
/* @0x1767d8 ldr r3, [pc, r3] */
/* @0x1767dc ldr r4, [r3] */
/* @0x1767e0 cmp r4, #0 */
/* @0x1767e4 popeq {r4, pc} */
/* @0x1767e8 cmp r0, #0 */
/* @0x1767ec bne 0x176814 <_ZN8Graphics12TextureFlushEb+0x44> */
/* @0x1767f0 ldr r3, [r4, #0x10] */
/* @0x1767f4 mov r0, r4 */
/* @0x1767f8 tst r3, #64 */
/* @0x1767fc bne 0x176804 <_ZN8Graphics12TextureFlushEb+0x34> */
/* @0x176800 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv> */
/* @0x176804 ldr r4, [r4, #0x34] */
/* @0x176808 cmp r4, #0 */
/* @0x17680c bne 0x1767f0 <_ZN8Graphics12TextureFlushEb+0x20> */
/* @0x176810 pop {r4, pc} */
/* @0x176814 mov r0, r4 */
/* @0x176818 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv> */
/* @0x17681c ldr r4, [r4, #0x34] */
/* @0x176820 cmp r4, #0 */
/* @0x176824 bne 0x176814 <_ZN8Graphics12TextureFlushEb+0x44> */
/* @0x176828 pop {r4, pc} */
/* @0x17682c .word 0x00279adc */

/* ── FUNC 0x176830 · EmbeddedImages_Load(unsigned char*, unsigned int, unsigned char*) · size=192 · insn=48 */
/* @0x176830 ldr r3, [r0] */
/* @0x176834 push {r5, r6, r7, lr} */
/* @0x176838 cmp r3, #1 */
/* @0x17683c mov r5, r0 */
/* @0x176840 beq 0x17684c <_Z19EmbeddedImages_LoadPhjS_+0x1c> */
/* @0x176844 mov r0, #0 */
/* @0x176848 pop {r5, r6, r7, pc} */
/* @0x17684c ldr r7, [r0, #0x4] */
/* @0x176850 mov r2, #70 */
/* @0x176854 ldr r1, [pc, #0x84] */
/* @0x176858 lsl r6, r7, #3 */
/* @0x17685c add r1, pc, r1 */
/* @0x176860 mov r0, r6 */
/* @0x176864 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x176868 ldr r2, [pc, #0x74] */
/* @0x17686c ldr r3, [pc, #0x74] */
/* @0x176870 cmp r7, #0 */
/* @0x176874 ldr r2, [pc, r2] */
/* @0x176878 ldr r3, [pc, r3] */
/* @0x17687c str r7, [r3] */
/* @0x176880 str r0, [r2] */
/* @0x176884 beq 0x1768d8 <_Z19EmbeddedImages_LoadPhjS_+0xa8> */
/* @0x176888 ldr r1, [pc, #0x5c] */
/* @0x17688c add r2, r5, #16 */
/* @0x176890 mov r3, #0 */
/* @0x176894 ldr r1, [pc, r1] */
/* @0x176898 ldr r5, [r1] */
/* @0x17689c ldr r1, [r2, #-0x8] */
/* @0x1768a0 add r2, r2, #8 */
/* @0x1768a4 cmp r1, #0 */
/* @0x1768a8 add r12, r1, r5 */
/* @0x1768ac moveq r12, r1 */
/* @0x1768b0 ldr r1, [r2, #-0xc] */
/* @0x1768b4 str r12, [r0, r3] */
/* @0x1768b8 cmp r1, #0 */
/* @0x1768bc add r12, r5, r1 */
/* @0x1768c0 moveq r12, r1 */
/* @0x1768c4 add r1, r0, r3 */
/* @0x1768c8 add r3, r3, #8 */
/* @0x1768cc cmp r6, r3 */
/* @0x1768d0 str r12, [r1, #0x4] */
/* @0x1768d4 bne 0x17689c <_Z19EmbeddedImages_LoadPhjS_+0x6c> */
/* @0x1768d8 mov r0, #1 */
/* @0x1768dc pop {r5, r6, r7, pc} */
/* @0x1768e0 ldrsbeq r10, [r11], -r4 */
/* @0x1768e4 eoreq r9, r7, r4, asr #20 */
/* @0x1768e8 eoreq r9, r7, r4, asr #20 */
/* @0x1768ec strhteq r7, [r7], -r0 */

/* ── FUNC 0x1768f0 · EmbeddedImage_Find(char*, bool) · size=236 · insn=59 */
/* @0x1768f0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1768f4 subs r6, r0, #0 */
/* @0x1768f8 ldr r3, [pc, #0xd0] */
/* @0x1768fc add r3, pc, r3 */
/* @0x176900 beq 0x1769c8 <_Z18EmbeddedImage_FindPcb+0xd8> */
/* @0x176904 ldr r2, [pc, #0xc8] */
/* @0x176908 cmp r1, #0 */
/* @0x17690c ldr r2, [r3, r2] */
/* @0x176910 ldr r7, [r2] */
/* @0x176914 beq 0x176964 <_Z18EmbeddedImage_FindPcb+0x74> */
/* @0x176918 cmp r7, #0 */
/* @0x17691c ble 0x1769b0 <_Z18EmbeddedImage_FindPcb+0xc0> */
/* @0x176920 ldr r2, [pc, #0xb0] */
/* @0x176924 mov r5, #0 */
/* @0x176928 ldr r3, [r3, r2] */
/* @0x17692c ldr r3, [r3] */
/* @0x176930 b 0x17693c <_Z18EmbeddedImage_FindPcb+0x4c> */
/* @0x176934 cmp r5, r7 */
/* @0x176938 beq 0x1769bc <_Z18EmbeddedImage_FindPcb+0xcc> */
/* @0x17693c ldr r0, [r3] */
/* @0x176940 mov r1, r6 */
/* @0x176944 mov r4, r3 */
/* @0x176948 bl 0xb6604 <strstr@plt> */
/* @0x17694c add r5, r5, #1 */
/* @0x176950 add r3, r4, #8 */
/* @0x176954 cmp r0, #0 */
/* @0x176958 beq 0x176934 <_Z18EmbeddedImage_FindPcb+0x44> */
/* @0x17695c mov r0, r4 */
/* @0x176960 pop {r3, r4, r5, r6, r7, pc} */
/* @0x176964 cmp r7, #0 */
/* @0x176968 movle r4, r1 */
/* @0x17696c ble 0x17695c <_Z18EmbeddedImage_FindPcb+0x6c> */
/* @0x176970 ldr r2, [pc, #0x60] */
/* @0x176974 mov r5, r1 */
/* @0x176978 ldr r3, [r3, r2] */
/* @0x17697c ldr r3, [r3] */
/* @0x176980 b 0x17698c <_Z18EmbeddedImage_FindPcb+0x9c> */
/* @0x176984 cmp r5, r7 */
/* @0x176988 beq 0x1769b0 <_Z18EmbeddedImage_FindPcb+0xc0> */
/* @0x17698c ldr r0, [r3] */
/* @0x176990 mov r1, r6 */
/* @0x176994 mov r4, r3 */
/* @0x176998 bl 0xb6574 <strcmp@plt> */
/* @0x17699c add r5, r5, #1 */
/* @0x1769a0 add r3, r4, #8 */
/* @0x1769a4 cmp r0, #0 */
/* @0x1769a8 bne 0x176984 <_Z18EmbeddedImage_FindPcb+0x94> */
/* @0x1769ac b 0x17695c <_Z18EmbeddedImage_FindPcb+0x6c> */
/* @0x1769b0 mov r4, #0 */
/* @0x1769b4 mov r0, r4 */
/* @0x1769b8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1769bc mov r4, r0 */
/* @0x1769c0 mov r0, r4 */
/* @0x1769c4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1769c8 mov r4, r6 */
/* @0x1769cc b 0x17695c <_Z18EmbeddedImage_FindPcb+0x6c> */
/* @0x1769d0 eoreq r11, r7, r4, asr r3 */
/* @0x1769d4 .word 0xffffe66c */
/* @0x1769d8 .word 0xffffe668 */

/* ── FUNC 0x1769dc · GR_3D_Primitive_Begin(int, int) · size=244 · insn=61 */
/* @0x1769dc push {r4, r5, r6, r7, r8, lr} */
/* @0x1769e0 mov r3, #0 */
/* @0x1769e4 ldr r4, [pc, #0xbc] */
/* @0x1769e8 mov r6, r0 */
/* @0x1769ec ldr r7, [pc, #0xb8] */
/* @0x1769f0 mov r5, r1 */
/* @0x1769f4 add r4, pc, r4 */
/* @0x1769f8 ldr lr, [pc, #0xb0] */
/* @0x1769fc ldr r12, [pc, #0xb0] */
/* @0x176a00 mov r0, r1 */
/* @0x176a04 ldr r7, [r4, r7] */
/* @0x176a08 mvn r2, #0 */
/* @0x176a0c ldr r1, [pc, #0xa4] */
/* @0x176a10 str r3, [r7] */
/* @0x176a14 ldr lr, [r4, lr] */
/* @0x176a18 str r6, [lr] */
/* @0x176a1c ldr r7, [r4, r12] */
/* @0x176a20 str r2, [r7] */
/* @0x176a24 ldr r8, [r4, r1] */
/* @0x176a28 str r3, [r8] */
/* @0x176a2c bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x176a30 cmp r0, #0 */
/* @0x176a34 strne r5, [r7] */
/* @0x176a38 bne 0x176a8c <_Z21GR_3D_Primitive_Beginii+0xb0> */
/* @0x176a3c cmn r5, #1 */
/* @0x176a40 beq 0x176a8c <_Z21GR_3D_Primitive_Beginii+0xb0> */
/* @0x176a44 ldrsh r3, [r5, #20] */
/* @0x176a48 ldr r2, [pc, #0x6c] */
/* @0x176a4c str r5, [r8] */
/* @0x176a50 str r3, [r7] */
/* @0x176a54 ldr r0, [r4, r2] */
/* @0x176a58 ldr r1, [pc, #0x60] */
/* @0x176a5c ldr r2, [pc, #0x60] */
/* @0x176a60 ldr r0, [r0, #0x4] */
/* @0x176a64 ldr r1, [r4, r1] */
/* @0x176a68 ldr r3, [r0, r3, lsl #2] */
/* @0x176a6c ldr r3, [r3] */
/* @0x176a70 vldr s14, [r3, #4] */
/* @0x176a74 vldr s15, [r3, #8] */
/* @0x176a78 vcvt.f32.s32 s14, s14 */
/* @0x176a7c vcvt.f32.s32 s15, s15 */
/* @0x176a80 vstr s14, [r1] */
/* @0x176a84 ldr r3, [r4, r2] */
/* @0x176a88 vstr s15, [r3] */
/* @0x176a8c ldr r2, [pc, #0x34] */
/* @0x176a90 ldr r3, [pc, #0x34] */
/* @0x176a94 add r2, pc, r2 */
/* @0x176a98 ldr r3, [r4, r3] */
/* @0x176a9c ldr r2, [r2, r6, lsl #2] */
/* @0x176aa0 str r2, [r3] */
/* @0x176aa4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x176aa8 eoreq r11, r7, r12, asr r2 */
/* @0x176aac .word 0xffffe670 */
/* @0x176ab0 .word 0xffffe674 */
/* @0x176ab4 .word 0xffffe678 */
/* @0x176ab8 .word 0xffffe540 */
/* @0x176abc .word 0xffffbccc */
/* @0x176ac0 .word 0xffffe544 */
/* @0x176ac4 .word 0xffffe548 */
/* @0x176ac8 andseq r7, lr, r8, lsl #1 */
/* @0x176acc .word 0xffffe67c */

/* ── FUNC 0x176ad0 · GR_3D_Primitive_End() · size=224 · insn=56 */
/* @0x176ad0 push {r4, r5, r6, lr} */
/* @0x176ad4 ldr r4, [pc, #0xb8] */
/* @0x176ad8 ldr r3, [pc, #0xb8] */
/* @0x176adc add r4, pc, r4 */
/* @0x176ae0 ldr r3, [r4, r3] */
/* @0x176ae4 ldr r3, [r3] */
/* @0x176ae8 sub r2, r3, #1 */
/* @0x176aec cmp r2, #5 */
/* @0x176af0 pophi {r4, r5, r6, pc} */
/* @0x176af4 sub r3, r3, #2 */
/* @0x176af8 cmp r3, #4 */
/* @0x176afc movhi r5, #1 */
/* @0x176b00 bls 0x176b38 <_Z19GR_3D_Primitive_Endv+0x68> */
/* @0x176b04 ldr r3, [pc, #0x90] */
/* @0x176b08 ldr r3, [r4, r3] */
/* @0x176b0c ldr r0, [r3] */
/* @0x176b10 cmp r0, #0 */
/* @0x176b14 beq 0x176b4c <_Z19GR_3D_Primitive_Endv+0x7c> */
/* @0x176b18 ldr r2, [pc, #0x80] */
/* @0x176b1c mov r1, r5 */
/* @0x176b20 ldr r3, [pc, #0x7c] */
/* @0x176b24 ldr r2, [r4, r2] */
/* @0x176b28 ldr r3, [r4, r3] */
/* @0x176b2c pop {r4, r5, r6, lr} */
/* @0x176b30 ldr r2, [r2] */
/* @0x176b34 b 0x188e28 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv> */
/* @0x176b38 ldr r2, [pc, #0x68] */
/* @0x176b3c add r2, pc, r2 */
/* @0x176b40 add r3, r2, r3, lsl #2 */
/* @0x176b44 ldr r5, [r3, #0x1c] */
/* @0x176b48 b 0x176b04 <_Z19GR_3D_Primitive_Endv+0x34> */
/* @0x176b4c ldr r3, [pc, #0x58] */
/* @0x176b50 ldr r3, [r4, r3] */
/* @0x176b54 ldr r0, [r3] */
/* @0x176b58 bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x176b5c ldr r3, [pc, #0x3c] */
/* @0x176b60 mov r2, #36 */
/* @0x176b64 mov r1, r0 */
/* @0x176b68 mov r0, r5 */
/* @0x176b6c ldr r5, [r4, r3] */
/* @0x176b70 ldr r3, [r5] */
/* @0x176b74 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x176b78 ldr r2, [pc, #0x24] */
/* @0x176b7c ldr r3, [r5] */
/* @0x176b80 ldr r1, [r4, r2] */
/* @0x176b84 add r2, r3, r3, lsl #3 */
/* @0x176b88 pop {r4, r5, r6, lr} */
/* @0x176b8c lsl r2, r2, #2 */
/* @0x176b90 b 0xb65bc <memcpy@plt> */
/* @0x176b94 eoreq r11, r7, r4, ror r1 */
/* @0x176b98 .word 0xffffe674 */
/* @0x176b9c .word 0xffffe49c */
/* @0x176ba0 .word 0xffffe670 */
/* @0x176ba4 .word 0xffffe680 */
/* @0x176ba8 andseq r6, lr, r0, ror #31 */
/* @0x176bac .word 0xffffe678 */

/* ── FUNC 0x176bb0 · HandleOverflow() · size=636 · insn=159 */
/* @0x176bb0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x176bb4 sub sp, sp, #72 */
/* @0x176bb8 ldr r4, [pc, #0x25c] */
/* @0x176bbc ldr r3, [pc, #0x25c] */
/* @0x176bc0 add r4, pc, r4 */
/* @0x176bc4 ldr r7, [r4, r3] */
/* @0x176bc8 ldr r3, [r7] */
/* @0x176bcc cmp r3, #5 */
/* @0x176bd0 beq 0x176d5c <_Z14HandleOverflowv+0x1ac> */
/* @0x176bd4 cmp r3, #6 */
/* @0x176bd8 beq 0x176cfc <_Z14HandleOverflowv+0x14c> */
/* @0x176bdc cmp r3, #3 */
/* @0x176be0 beq 0x176c24 <_Z14HandleOverflowv+0x74> */
/* @0x176be4 ldr r3, [pc, #0x238] */
/* @0x176be8 ldr r5, [r4, r3] */
/* @0x176bec ldr r6, [r5] */
/* @0x176bf0 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv> */
/* @0x176bf4 ldr r3, [r7] */
/* @0x176bf8 mov r2, #0 */
/* @0x176bfc str r2, [r5] */
/* @0x176c00 cmp r3, #5 */
/* @0x176c04 beq 0x176c64 <_Z14HandleOverflowv+0xb4> */
/* @0x176c08 cmp r3, #6 */
/* @0x176c0c beq 0x176c6c <_Z14HandleOverflowv+0xbc> */
/* @0x176c10 cmp r3, #3 */
/* @0x176c14 beq 0x176cc4 <_Z14HandleOverflowv+0x114> */
/* @0x176c18 mov r0, #1 */
/* @0x176c1c add sp, sp, #72 */
/* @0x176c20 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x176c24 ldr r2, [pc, #0x1f8] */
/* @0x176c28 mov r12, sp */
/* @0x176c2c ldr r3, [pc, #0x1f4] */
/* @0x176c30 ldr r5, [r4, r2] */
/* @0x176c34 ldr r2, [r4, r3] */
/* @0x176c38 ldr r6, [r5] */
/* @0x176c3c sub r3, r6, #1 */
/* @0x176c40 add r3, r3, r3, lsl #3 */
/* @0x176c44 add lr, r2, r3, lsl #2 */
/* @0x176c48 ldm lr!, {r0, r1, r2, r3} */
/* @0x176c4c stm r12!, {r0, r1, r2, r3} */
/* @0x176c50 ldm lr!, {r0, r1, r2, r3} */
/* @0x176c54 ldr lr, [lr] */
/* @0x176c58 stm r12!, {r0, r1, r2, r3} */
/* @0x176c5c str lr, [r12] */
/* @0x176c60 b 0x176bf0 <_Z14HandleOverflowv+0x40> */
/* @0x176c64 tst r6, #1 */
/* @0x176c68 bne 0x176dc4 <_Z14HandleOverflowv+0x214> */
/* @0x176c6c ldr r8, [pc, #0x1b4] */
/* @0x176c70 mov r7, sp */
/* @0x176c74 ldm r7!, {r0, r1, r2, r3} */
/* @0x176c78 mov r12, #2 */
/* @0x176c7c ldr r4, [r4, r8] */
/* @0x176c80 add r6, sp, #36 */
/* @0x176c84 str r12, [r5] */
/* @0x176c88 add r12, r4, #36 */
/* @0x176c8c stm r4!, {r0, r1, r2, r3} */
/* @0x176c90 ldm r7!, {r0, r1, r2, r3} */
/* @0x176c94 stm r4!, {r0, r1, r2, r3} */
/* @0x176c98 ldm r6!, {r0, r1, r2, r3} */
/* @0x176c9c ldr r5, [r7] */
/* @0x176ca0 stm r12!, {r0, r1, r2, r3} */
/* @0x176ca4 ldm r6!, {r0, r1, r2, r3} */
/* @0x176ca8 str r5, [r4] */
/* @0x176cac stm r12!, {r0, r1, r2, r3} */
/* @0x176cb0 mov r0, #1 */
/* @0x176cb4 ldr r3, [r6] */
/* @0x176cb8 str r3, [r12] */
/* @0x176cbc add sp, sp, #72 */
/* @0x176cc0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x176cc4 ldr r12, [pc, #0x15c] */
/* @0x176cc8 mov r6, sp */
/* @0x176ccc mov r3, #1 */
/* @0x176cd0 str r3, [r5] */
/* @0x176cd4 ldm r6!, {r0, r1, r2, r3} */
/* @0x176cd8 ldr r12, [r4, r12] */
/* @0x176cdc stm r12!, {r0, r1, r2, r3} */
/* @0x176ce0 ldm r6!, {r0, r1, r2, r3} */
/* @0x176ce4 ldr r4, [r6] */
/* @0x176ce8 stm r12!, {r0, r1, r2, r3} */
/* @0x176cec mov r0, #1 */
/* @0x176cf0 str r4, [r12] */
/* @0x176cf4 add sp, sp, #72 */
/* @0x176cf8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x176cfc ldr r3, [pc, #0x124] */
/* @0x176d00 mov r5, sp */
/* @0x176d04 ldr lr, [pc, #0x118] */
/* @0x176d08 add r12, sp, #36 */
/* @0x176d0c ldr r8, [r4, r3] */
/* @0x176d10 mov r6, r8 */
/* @0x176d14 ldm r6!, {r0, r1, r2, r3} */
/* @0x176d18 stm r5!, {r0, r1, r2, r3} */
/* @0x176d1c ldm r6!, {r0, r1, r2, r3} */
/* @0x176d20 ldr r6, [r6] */
/* @0x176d24 stm r5!, {r0, r1, r2, r3} */
/* @0x176d28 str r6, [r5] */
/* @0x176d2c ldr r5, [r4, lr] */
/* @0x176d30 ldr r6, [r5] */
/* @0x176d34 sub lr, r6, #1 */
/* @0x176d38 add lr, lr, lr, lsl #3 */
/* @0x176d3c add lr, r8, lr, lsl #2 */
/* @0x176d40 ldm lr!, {r0, r1, r2, r3} */
/* @0x176d44 stm r12!, {r0, r1, r2, r3} */
/* @0x176d48 ldm lr!, {r0, r1, r2, r3} */
/* @0x176d4c stm r12!, {r0, r1, r2, r3} */
/* @0x176d50 ldr r3, [lr] */
/* @0x176d54 str r3, [r12] */
/* @0x176d58 b 0x176bf0 <_Z14HandleOverflowv+0x40> */
/* @0x176d5c ldr r2, [pc, #0xc0] */
/* @0x176d60 mov r8, sp */
/* @0x176d64 ldr r3, [pc, #0xbc] */
/* @0x176d68 add r12, sp, #36 */
/* @0x176d6c ldr r5, [r4, r2] */
/* @0x176d70 ldr r3, [r4, r3] */
/* @0x176d74 ldr r6, [r5] */
/* @0x176d78 sub r9, r6, #2 */
/* @0x176d7c sub lr, r6, #1 */
/* @0x176d80 add r9, r9, r9, lsl #3 */
/* @0x176d84 add lr, lr, lr, lsl #3 */
/* @0x176d88 add r9, r3, r9, lsl #2 */
/* @0x176d8c add lr, r3, lr, lsl #2 */
/* @0x176d90 ldm r9!, {r0, r1, r2, r3} */
/* @0x176d94 stm r8!, {r0, r1, r2, r3} */
/* @0x176d98 ldm r9!, {r0, r1, r2, r3} */
/* @0x176d9c stm r8!, {r0, r1, r2, r3} */
/* @0x176da0 ldm lr!, {r0, r1, r2, r3} */
/* @0x176da4 ldr r9, [r9] */
/* @0x176da8 stm r12!, {r0, r1, r2, r3} */
/* @0x176dac ldm lr!, {r0, r1, r2, r3} */
/* @0x176db0 str r9, [r8] */
/* @0x176db4 stm r12!, {r0, r1, r2, r3} */
/* @0x176db8 ldr r3, [lr] */
/* @0x176dbc str r3, [r12] */
/* @0x176dc0 b 0x176bf0 <_Z14HandleOverflowv+0x40> */
/* @0x176dc4 ldr r12, [pc, #0x5c] */
/* @0x176dc8 mov r8, sp */
/* @0x176dcc ldm r8!, {r0, r1, r2, r3} */
/* @0x176dd0 mov r9, sp */
/* @0x176dd4 ldr r7, [r4, r12] */
/* @0x176dd8 add r6, sp, #36 */
/* @0x176ddc mov r10, #3 */
/* @0x176de0 add r4, r7, #36 */
/* @0x176de4 add r12, r7, #72 */
/* @0x176de8 stm r7!, {r0, r1, r2, r3} */
/* @0x176dec ldm r8!, {r0, r1, r2, r3} */
/* @0x176df0 stm r7!, {r0, r1, r2, r3} */
/* @0x176df4 ldm r9!, {r0, r1, r2, r3} */
/* @0x176df8 ldr r8, [r8] */
/* @0x176dfc stm r4!, {r0, r1, r2, r3} */
/* @0x176e00 ldm r9!, {r0, r1, r2, r3} */
/* @0x176e04 str r8, [r7] */
/* @0x176e08 stm r4!, {r0, r1, r2, r3} */
/* @0x176e0c ldm r6!, {r0, r1, r2, r3} */
/* @0x176e10 str r8, [r4] */
/* @0x176e14 str r10, [r5] */
/* @0x176e18 b 0x176cdc <_Z14HandleOverflowv+0x12c> */
/* @0x176e1c mlaeq r7, r0, r0, r11 */
/* @0x176e20 .word 0xffffe674 */
/* @0x176e24 .word 0xffffe670 */
/* @0x176e28 .word 0xffffe680 */

/* ── FUNC 0x176e2c · GR_3D_Vertex(float, float, float) · size=168 · insn=42 */
/* @0x176e2c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x176e30 mov r8, r1 */
/* @0x176e34 ldr r4, [pc, #0x84] */
/* @0x176e38 mov r7, r0 */
/* @0x176e3c ldr r3, [pc, #0x80] */
/* @0x176e40 mov r9, r2 */
/* @0x176e44 ldr r1, [pc, #0x7c] */
/* @0x176e48 add r4, pc, r4 */
/* @0x176e4c ldr r6, [r4, r3] */
/* @0x176e50 ldr r3, [r4, r1] */
/* @0x176e54 ldr r5, [r6] */
/* @0x176e58 ldr r3, [r3] */
/* @0x176e5c cmp r5, r3 */
/* @0x176e60 blt 0x176e6c <_Z12GR_3D_Vertexfff+0x40> */
/* @0x176e64 bl 0x176bb0 <_Z14HandleOverflowv> */
/* @0x176e68 ldr r5, [r6] */
/* @0x176e6c ldr r3, [pc, #0x58] */
/* @0x176e70 add r1, r5, r5, lsl #3 */
/* @0x176e74 ldr r2, [pc, #0x54] */
/* @0x176e78 mov r12, #0 */
/* @0x176e7c add r5, r5, #1 */
/* @0x176e80 ldr r3, [r4, r3] */
/* @0x176e84 add r3, r3, r1, lsl #2 */
/* @0x176e88 str r7, [r3] */
/* @0x176e8c str r8, [r3, #0x4] */
/* @0x176e90 str r9, [r3, #0x8] */
/* @0x176e94 str r12, [r3, #0x14] */
/* @0x176e98 str r12, [r3, #0x10] */
/* @0x176e9c str r12, [r3, #0xc] */
/* @0x176ea0 ldr r2, [r4, r2] */
/* @0x176ea4 str r12, [r3, #0x1c] */
/* @0x176ea8 str r12, [r3, #0x20] */
/* @0x176eac ldr r2, [r2] */
/* @0x176eb0 str r5, [r6] */
/* @0x176eb4 bic r2, r2, #1 */
/* @0x176eb8 str r2, [r3, #0x18] */
/* @0x176ebc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x176ec0 eoreq r10, r7, r8, lsl #28 */
/* @0x176ec4 .word 0xffffe670 */
/* @0x176ec8 .word 0xffffe67c */
/* @0x176ecc .word 0xffffe680 */
/* @0x176ed0 .word 0xffffc0ac */

/* ── FUNC 0x176ed4 · GR_3D_Vertex_Color(float, float, float, unsigned int, float) · size=168 · insn=42 */
/* @0x176ed4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x176ed8 mov r6, r2 */
/* @0x176edc ldr r5, [pc, #0x8c] */
/* @0x176ee0 mov r9, r3 */
/* @0x176ee4 ldr r12, [pc, #0x88] */
/* @0x176ee8 mov r8, r0 */
/* @0x176eec ldr r5, [pc, r5] */
/* @0x176ef0 mov r7, r1 */
/* @0x176ef4 ldr r12, [pc, r12] */
/* @0x176ef8 ldr r4, [sp, #0x20] */
/* @0x176efc ldr r2, [r5] */
/* @0x176f00 ldr r3, [r12] */
/* @0x176f04 cmp r2, r3 */
/* @0x176f08 blt 0x176f10 <_Z18GR_3D_Vertex_Colorfffjf+0x3c> */
/* @0x176f0c bl 0x176bb0 <_Z14HandleOverflowv> */
/* @0x176f10 mov r0, r4 */
/* @0x176f14 bl 0x16ca2c <_Z12ConvertAlphaf> */
/* @0x176f18 ldr r4, [r5] */
/* @0x176f1c ldr r12, [pc, #0x54] */
/* @0x176f20 add r4, r4, r4, lsl #3 */
/* @0x176f24 ldr r12, [pc, r12] */
/* @0x176f28 add r4, r12, r4, lsl #2 */
/* @0x176f2c str r8, [r4] */
/* @0x176f30 str r7, [r4, #0x4] */
/* @0x176f34 str r6, [r4, #0x8] */
/* @0x176f38 mov r1, r0 */
/* @0x176f3c orr r0, r9, #1 */
/* @0x176f40 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x176f44 ldr r2, [r5] */
/* @0x176f48 mov r3, #0 */
/* @0x176f4c str r3, [r4, #0xc] */
/* @0x176f50 str r3, [r4, #0x10] */
/* @0x176f54 str r3, [r4, #0x14] */
/* @0x176f58 str r3, [r4, #0x1c] */
/* @0x176f5c str r3, [r4, #0x20] */
/* @0x176f60 add r3, r2, #1 */
/* @0x176f64 str r3, [r5] */
/* @0x176f68 str r0, [r4, #0x18] */
/* @0x176f6c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x176f70 .word 0x002793d4 */
/* @0x176f74 .word 0x002793d8 */
/* @0x176f78 eoreq r9, r7, r12, lsr #7 */

/* ── FUNC 0x176f7c · GR_3D_Vertex_Texture(float, float, float, float, float) · size=332 · insn=83 */
/* @0x176f7c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x176f80 vpush {d8} */
/* @0x176f84 mov r7, r0 */
/* @0x176f88 ldr r4, [pc, #0x118] */
/* @0x176f8c mov r8, r1 */
/* @0x176f90 ldr r0, [pc, #0x114] */
/* @0x176f94 vmov s16, r3 */
/* @0x176f98 ldr r1, [pc, #0x110] */
/* @0x176f9c add r4, pc, r4 */
/* @0x176fa0 mov r9, r2 */
/* @0x176fa4 ldr r6, [r4, r0] */
/* @0x176fa8 ldr r3, [r4, r1] */
/* @0x176fac ldr r5, [r6] */
/* @0x176fb0 ldr r3, [r3] */
/* @0x176fb4 cmp r5, r3 */
/* @0x176fb8 blt 0x176fc4 <_Z20GR_3D_Vertex_Texturefffff+0x48> */
/* @0x176fbc bl 0x176bb0 <_Z14HandleOverflowv> */
/* @0x176fc0 ldr r5, [r6] */
/* @0x176fc4 ldr r0, [pc, #0xe8] */
/* @0x176fc8 add r3, r5, r5, lsl #3 */
/* @0x176fcc ldr r1, [pc, #0xe4] */
/* @0x176fd0 mov r12, #0 */
/* @0x176fd4 ldr r2, [pc, #0xe0] */
/* @0x176fd8 ldr r0, [r4, r0] */
/* @0x176fdc add r3, r0, r3, lsl #2 */
/* @0x176fe0 str r7, [r3] */
/* @0x176fe4 str r8, [r3, #0x4] */
/* @0x176fe8 str r9, [r3, #0x8] */
/* @0x176fec str r12, [r3, #0x14] */
/* @0x176ff0 str r12, [r3, #0x10] */
/* @0x176ff4 str r12, [r3, #0xc] */
/* @0x176ff8 ldr r1, [r4, r1] */
/* @0x176ffc ldr r1, [r1] */
/* @0x177000 bic r1, r1, #1 */
/* @0x177004 str r1, [r3, #0x18] */
/* @0x177008 ldr r2, [r4, r2] */
/* @0x17700c ldr r2, [r2] */
/* @0x177010 cmp r2, #0 */
/* @0x177014 beq 0x17708c <_Z20GR_3D_Vertex_Texturefffff+0x110> */
/* @0x177018 ldrsh r0, [r2] */
/* @0x17701c add r5, r5, #1 */
/* @0x177020 ldrsh r1, [r2, #12] */
/* @0x177024 vmov s14, r0 */
/* @0x177028 ldrsh r0, [r2, #2] */
/* @0x17702c vmov s11, r1 */
/* @0x177030 ldrsh r2, [r2, #14] */
/* @0x177034 vcvt.f32.s32 s14, s14 */
/* @0x177038 ldr r1, [pc, #0x80] */
/* @0x17703c vmov s15, r0 */
/* @0x177040 vmov s13, r2 */
/* @0x177044 ldr r2, [r4, r1] */
/* @0x177048 vldr s12, [r2] */
/* @0x17704c ldr r2, [pc, #0x70] */
/* @0x177050 vcvt.f32.s32 s11, s11 */
/* @0x177054 vmla.f32 s14, s16, s11 */
/* @0x177058 vdiv.f32 s14, s14, s12 */
/* @0x17705c vldr s12, [sp, #40] */
/* @0x177060 vpop {d8} */
/* @0x177064 vcvt.f32.s32 s15, s15 */
/* @0x177068 vstr s14, [r3, #28] */
/* @0x17706c ldr r2, [r4, r2] */
/* @0x177070 vldr s14, [r2] */
/* @0x177074 str r5, [r6] */
/* @0x177078 vcvt.f32.s32 s13, s13 */
/* @0x17707c vmla.f32 s15, s12, s13 */
/* @0x177080 vdiv.f32 s15, s15, s14 */
/* @0x177084 vstr s15, [r3, #32] */
/* @0x177088 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x17708c vldr s12, [sp, #40] */
/* @0x177090 vstr s16, [r3, #28] */
/* @0x177094 vpop {d8} */
/* @0x177098 vstr s12, [r3, #32] */
/* @0x17709c add r5, r5, #1 */
/* @0x1770a0 str r5, [r6] */
/* @0x1770a4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1770a8 .word 0x0027acb4 */
/* @0x1770ac .word 0xffffe670 */
/* @0x1770b0 .word 0xffffe67c */
/* @0x1770b4 .word 0xffffe680 */
/* @0x1770b8 .word 0xffffc0ac */
/* @0x1770bc .word 0xffffe540 */
/* @0x1770c0 .word 0xffffe544 */
/* @0x1770c4 .word 0xffffe548 */

/* ── FUNC 0x1770c8 · GR_3D_Vertex_Texture_Color(float, float, float, float, float, unsigned int, float) · size=332 · insn=83 */
/* @0x1770c8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1770cc vpush {d8} */
/* @0x1770d0 mov r9, r0 */
/* @0x1770d4 ldr r5, [pc, #0x11c] */
/* @0x1770d8 mov r8, r1 */
/* @0x1770dc ldr r0, [pc, #0x118] */
/* @0x1770e0 vmov s16, r3 */
/* @0x1770e4 ldr r1, [pc, #0x114] */
/* @0x1770e8 add r5, pc, r5 */
/* @0x1770ec mov r7, r2 */
/* @0x1770f0 ldr r10, [sp, #0x2c] */
/* @0x1770f4 ldr r6, [r5, r0] */
/* @0x1770f8 ldr r3, [r5, r1] */
/* @0x1770fc ldr r4, [sp, #0x30] */
/* @0x177100 ldr r2, [r6] */
/* @0x177104 ldr r3, [r3] */
/* @0x177108 cmp r2, r3 */
/* @0x17710c blt 0x177114 <_Z26GR_3D_Vertex_Texture_Colorfffffjf+0x4c> */
/* @0x177110 bl 0x176bb0 <_Z14HandleOverflowv> */
/* @0x177114 mov r0, r4 */
/* @0x177118 bl 0x16ca2c <_Z12ConvertAlphaf> */
/* @0x17711c ldr r4, [r6] */
/* @0x177120 ldr r2, [pc, #0xdc] */
/* @0x177124 mov r3, #0 */
/* @0x177128 add r4, r4, r4, lsl #3 */
/* @0x17712c ldr r2, [r5, r2] */
/* @0x177130 add r4, r2, r4, lsl #2 */
/* @0x177134 str r3, [r4, #0x14] */
/* @0x177138 str r3, [r4, #0x10] */
/* @0x17713c str r3, [r4, #0xc] */
/* @0x177140 str r9, [r4] */
/* @0x177144 str r8, [r4, #0x4] */
/* @0x177148 str r7, [r4, #0x8] */
/* @0x17714c mov r1, r0 */
/* @0x177150 orr r0, r10, #1 */
/* @0x177154 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x177158 ldr r3, [pc, #0xa8] */
/* @0x17715c str r0, [r4, #0x18] */
/* @0x177160 ldr r3, [r5, r3] */
/* @0x177164 ldr r3, [r3] */
/* @0x177168 cmp r3, #0 */
/* @0x17716c beq 0x1771e8 <_Z26GR_3D_Vertex_Texture_Colorfffffjf+0x120> */
/* @0x177170 ldrsh r1, [r3] */
/* @0x177174 ldrsh r2, [r3, #12] */
/* @0x177178 vmov s14, r1 */
/* @0x17717c ldrsh r1, [r3, #2] */
/* @0x177180 vmov s11, r2 */
/* @0x177184 ldrsh r3, [r3, #14] */
/* @0x177188 vcvt.f32.s32 s14, s14 */
/* @0x17718c ldr r2, [pc, #0x78] */
/* @0x177190 vmov s15, r1 */
/* @0x177194 vmov s13, r3 */
/* @0x177198 ldr r3, [r5, r2] */
/* @0x17719c vldr s12, [r3] */
/* @0x1771a0 ldr r3, [pc, #0x68] */
/* @0x1771a4 vcvt.f32.s32 s11, s11 */
/* @0x1771a8 vmla.f32 s14, s16, s11 */
/* @0x1771ac vdiv.f32 s14, s14, s12 */
/* @0x1771b0 vldr s12, [sp, #40] */
/* @0x1771b4 vcvt.f32.s32 s15, s15 */
/* @0x1771b8 vstr s14, [r4, #28] */
/* @0x1771bc ldr r3, [r5, r3] */
/* @0x1771c0 vldr s14, [r3] */
/* @0x1771c4 vcvt.f32.s32 s13, s13 */
/* @0x1771c8 vmla.f32 s15, s12, s13 */
/* @0x1771cc vdiv.f32 s15, s15, s14 */
/* @0x1771d0 vstr s15, [r4, #32] */
/* @0x1771d4 vpop {d8} */
/* @0x1771d8 ldr r3, [r6] */
/* @0x1771dc add r3, r3, #1 */
/* @0x1771e0 str r3, [r6] */
/* @0x1771e4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1771e8 vldr s12, [sp, #40] */
/* @0x1771ec vstr s16, [r4, #28] */
/* @0x1771f0 vstr s12, [r4, #32] */
/* @0x1771f4 b 0x1771d4 <_Z26GR_3D_Vertex_Texture_Colorfffffjf+0x10c> */
/* @0x1771f8 eoreq r10, r7, r8, ror #22 */
/* @0x1771fc .word 0xffffe670 */
/* @0x177200 .word 0xffffe67c */
/* @0x177204 .word 0xffffe680 */
/* @0x177208 .word 0xffffe540 */
/* @0x17720c .word 0xffffe544 */
/* @0x177210 .word 0xffffe548 */

/* ── FUNC 0x177214 · GR_3D_Vertex_N(float, float, float, float, float, float) · size=188 · insn=47 */
/* @0x177214 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x177218 vpush {d8} */
/* @0x17721c mov r8, r0 */
/* @0x177220 vldr s17, [sp, #48] */
/* @0x177224 ldr r4, [pc, #0x90] */
/* @0x177228 mov r9, r1 */
/* @0x17722c ldr r0, [pc, #0x8c] */
/* @0x177230 mov r11, r3 */
/* @0x177234 ldr r1, [pc, #0x88] */
/* @0x177238 add r4, pc, r4 */
/* @0x17723c mov r10, r2 */
/* @0x177240 vldr s16, [sp, #52] */
/* @0x177244 ldr r6, [r4, r0] */
/* @0x177248 ldr r3, [r4, r1] */
/* @0x17724c ldr r5, [r6] */
/* @0x177250 ldr r3, [r3] */
/* @0x177254 cmp r5, r3 */
/* @0x177258 blt 0x177264 <_Z14GR_3D_Vertex_Nffffff+0x50> */
/* @0x17725c bl 0x176bb0 <_Z14HandleOverflowv> */
/* @0x177260 ldr r5, [r6] */
/* @0x177264 ldr r2, [pc, #0x5c] */
/* @0x177268 add r12, r5, r5, lsl #3 */
/* @0x17726c ldr r3, [pc, #0x58] */
/* @0x177270 mov r7, #0 */
/* @0x177274 add r5, r5, #1 */
/* @0x177278 ldr r2, [r4, r2] */
/* @0x17727c add r12, r2, r12, lsl #2 */
/* @0x177280 vstr s17, [r12, #16] */
/* @0x177284 vstr s16, [r12, #20] */
/* @0x177288 str r8, [r12] */
/* @0x17728c str r9, [r12, #0x4] */
/* @0x177290 str r10, [r12, #0x8] */
/* @0x177294 str r11, [r12, #0xc] */
/* @0x177298 ldr r3, [r4, r3] */
/* @0x17729c str r7, [r12, #0x1c] */
/* @0x1772a0 str r7, [r12, #0x20] */
/* @0x1772a4 vpop {d8} */
/* @0x1772a8 ldr r3, [r3] */
/* @0x1772ac str r5, [r6] */
/* @0x1772b0 bic r3, r3, #1 */
/* @0x1772b4 str r3, [r12, #0x18] */
/* @0x1772b8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1772bc eoreq r10, r7, r8, lsl r10 */
/* @0x1772c0 .word 0xffffe670 */
/* @0x1772c4 .word 0xffffe67c */
/* @0x1772c8 .word 0xffffe680 */
/* @0x1772cc .word 0xffffc0ac */

/* ── FUNC 0x1772d0 · GR_3D_Vertex_N_Color(float, float, float, float, float, float, unsigned int, float) · size=188 · insn=47 */
/* @0x1772d0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1772d4 vpush {d8} */
/* @0x1772d8 mov r7, r2 */
/* @0x1772dc vldr s16, [sp, #48] */
/* @0x1772e0 ldr r5, [pc, #0x98] */
/* @0x1772e4 mov r6, r3 */
/* @0x1772e8 ldr r12, [pc, #0x94] */
/* @0x1772ec mov r9, r0 */
/* @0x1772f0 ldr r5, [pc, r5] */
/* @0x1772f4 mov r8, r1 */
/* @0x1772f8 ldr r12, [pc, r12] */
/* @0x1772fc ldr r11, [sp, #0x34] */
/* @0x177300 ldr r2, [r5] */
/* @0x177304 ldr r3, [r12] */
/* @0x177308 ldr r10, [sp, #0x38] */
/* @0x17730c cmp r2, r3 */
/* @0x177310 ldr r4, [sp, #0x3c] */
/* @0x177314 blt 0x17731c <_Z20GR_3D_Vertex_N_Colorffffffjf+0x4c> */
/* @0x177318 bl 0x176bb0 <_Z14HandleOverflowv> */
/* @0x17731c mov r0, r4 */
/* @0x177320 bl 0x16ca2c <_Z12ConvertAlphaf> */
/* @0x177324 ldr r4, [r5] */
/* @0x177328 ldr r12, [pc, #0x58] */
/* @0x17732c add r4, r4, r4, lsl #3 */
/* @0x177330 ldr r12, [pc, r12] */
/* @0x177334 add r4, r12, r4, lsl #2 */
/* @0x177338 vstr s16, [r4, #16] */
/* @0x17733c str r9, [r4] */
/* @0x177340 str r8, [r4, #0x4] */
/* @0x177344 str r7, [r4, #0x8] */
/* @0x177348 str r6, [r4, #0xc] */
/* @0x17734c str r11, [r4, #0x14] */
/* @0x177350 mov r1, r0 */
/* @0x177354 orr r0, r10, #1 */
/* @0x177358 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj> */
/* @0x17735c mov r3, #0 */
/* @0x177360 str r3, [r4, #0x20] */
/* @0x177364 str r3, [r4, #0x1c] */
/* @0x177368 vpop {d8} */
/* @0x17736c ldr r2, [r5] */
/* @0x177370 add r3, r2, #1 */
/* @0x177374 str r3, [r5] */
/* @0x177378 str r0, [r4, #0x18] */
/* @0x17737c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x177380 .word 0x00278fd0 */
/* @0x177384 .word 0x00278fd4 */
/* @0x177388 eoreq r8, r7, r0, lsr #31 */
