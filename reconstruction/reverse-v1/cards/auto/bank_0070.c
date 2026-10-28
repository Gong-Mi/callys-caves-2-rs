/* libyoyo.so 覆盖卡组 0070
 * 函数 0x139360..0x13aaac，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x139360 · F_FileTextClose(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x139360 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x139364 mov r1, #0 */
/* @0x139368 ldr r0, [sp, #0x20] */
/* @0x13936c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x139370 ldr r3, [pc, #0x7c] */
/* @0x139374 add r3, pc, r3 */
/* @0x139378 sub r2, r0, #1 */
/* @0x13937c mov r4, r0 */
/* @0x139380 cmp r2, #30 */
/* @0x139384 bhi 0x1393e0 <_Z15F_FileTextCloseR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x139388 ldr r2, [pc, #0x68] */
/* @0x13938c ldr r5, [r3, r2] */
/* @0x139390 ldr r2, [r5, r0, lsl #2] */
/* @0x139394 cmp r2, #1 */
/* @0x139398 beq 0x1393a4 <_Z15F_FileTextCloseR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x13939c cmp r2, #2 */
/* @0x1393a0 bne 0x1393d4 <_Z15F_FileTextCloseR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x1393a4 ldr r2, [pc, #0x50] */
/* @0x1393a8 add r6, r4, r4, lsl #1 */
/* @0x1393ac mov r9, #0 */
/* @0x1393b0 lsl r6, r6, #2 */
/* @0x1393b4 ldr r7, [r3, r2] */
/* @0x1393b8 add r8, r7, r6 */
/* @0x1393bc ldr r0, [r7, r6] */
/* @0x1393c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1393c4 ldr r0, [r8, #0x8] */
/* @0x1393c8 str r9, [r7, r6] */
/* @0x1393cc bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE> */
/* @0x1393d0 str r9, [r8, #0x8] */
/* @0x1393d4 mov r3, #0 */
/* @0x1393d8 str r3, [r5, r4, lsl #2] */
/* @0x1393dc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1393e0 ldr r0, [pc, #0x18] */
/* @0x1393e4 mov r1, #0 */
/* @0x1393e8 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1393ec add r0, pc, r0 */
/* @0x1393f0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1393f4 .word 0x002b88dc */
/* @0x1393f8 .word 0xffffd620 */
/* @0x1393fc .word 0xffffd624 */
/* @0x139400 eoreq r6, r0, r8, lsr sp */

/* ── FUNC 0x139404 · F_FileBinRewrite(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x139404 push {r4, r5, r6, lr} */
/* @0x139408 mov r1, #0 */
/* @0x13940c ldr r0, [sp, #0x10] */
/* @0x139410 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x139414 sub r3, r0, #1 */
/* @0x139418 cmp r3, #30 */
/* @0x13941c bhi 0x139490 <_Z16F_FileBinRewriteR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x139420 ldr r3, [pc, #0x7c] */
/* @0x139424 ldr r3, [pc, r3] */
/* @0x139428 ldrb r3, [r3, r0] */
/* @0x13942c cmp r3, #0 */
/* @0x139430 beq 0x139490 <_Z16F_FileBinRewriteR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x139434 add r0, r0, r0, lsl #1 */
/* @0x139438 ldr r4, [pc, #0x68] */
/* @0x13943c lsl r6, r0, #2 */
/* @0x139440 ldr r4, [pc, r4] */
/* @0x139444 add r5, r6, r4 */
/* @0x139448 ldr r0, [r5, #0x8] */
/* @0x13944c cmp r0, #0 */
/* @0x139450 beq 0x139458 <_Z16F_FileBinRewriteR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x139454 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE> */
/* @0x139458 ldr r1, [pc, #0x4c] */
/* @0x13945c ldr r0, [r4, r6] */
/* @0x139460 add r1, pc, r1 */
/* @0x139464 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x139468 mov r1, #0 */
/* @0x13946c mov r2, r1 */
/* @0x139470 str r0, [r5, #0x8] */
/* @0x139474 ldr r0, [r0] */
/* @0x139478 ldr r3, [r0] */
/* @0x13947c ldr r3, [r3, #0x10] */
/* @0x139480 blx r3 */
/* @0x139484 mov r3, #1 */
/* @0x139488 str r3, [r5, #0x4] */
/* @0x13948c pop {r4, r5, r6, pc} */
/* @0x139490 ldr r0, [pc, #0x18] */
/* @0x139494 mov r1, #0 */
/* @0x139498 pop {r4, r5, r6, lr} */
/* @0x13949c add r0, pc, r0 */
/* @0x1394a0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1394a4 eoreq r5, r11, r8, ror #28 */
/* @0x1394a8 eoreq r5, r11, r0, asr lr */
/* @0x1394ac eoreq r6, r0, r12, lsl sp */
/* @0x1394b0 .word 0x00206cbc */

/* ── FUNC 0x1394b4 · F_FileBinSeek(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x1394b4 push {r3, r4, r5, lr} */
/* @0x1394b8 mov r1, #0 */
/* @0x1394bc ldr r5, [sp, #0x10] */
/* @0x1394c0 mov r0, r5 */
/* @0x1394c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1394c8 mov r1, #1 */
/* @0x1394cc mov r4, r0 */
/* @0x1394d0 mov r0, r5 */
/* @0x1394d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1394d8 sub r3, r4, #1 */
/* @0x1394dc cmp r3, #30 */
/* @0x1394e0 bhi 0x13951c <_Z13F_FileBinSeekR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x1394e4 ldr r3, [pc, #0x44] */
/* @0x1394e8 ldr r3, [pc, r3] */
/* @0x1394ec ldrb r3, [r3, r4] */
/* @0x1394f0 cmp r3, #0 */
/* @0x1394f4 beq 0x13951c <_Z13F_FileBinSeekR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x1394f8 ldr r3, [pc, #0x34] */
/* @0x1394fc add r4, r4, r4, lsl #1 */
/* @0x139500 mov r1, r0 */
/* @0x139504 mov r2, #0 */
/* @0x139508 ldr r3, [pc, r3] */
/* @0x13950c add r3, r3, r4, lsl #2 */
/* @0x139510 ldr r0, [r3, #0x8] */
/* @0x139514 pop {r3, r4, r5, lr} */
/* @0x139518 b 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli> */
/* @0x13951c ldr r0, [pc, #0x14] */
/* @0x139520 mov r1, #0 */
/* @0x139524 pop {r3, r4, r5, lr} */
/* @0x139528 add r0, pc, r0 */
/* @0x13952c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139530 eoreq r5, r11, r4, lsr #27 */
/* @0x139534 eoreq r5, r11, r8, lsl #27 */
/* @0x139538 eoreq r6, r0, r8, asr r12 */

/* ── FUNC 0x13953c · F_FileBinSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0x13953c push {r3, r4, r5, r6, r7, lr} */
/* @0x139540 mov r1, #0 */
/* @0x139544 mov r6, r0 */
/* @0x139548 ldr r0, [sp, #0x18] */
/* @0x13954c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x139550 sub r3, r0, #1 */
/* @0x139554 cmp r3, #30 */
/* @0x139558 bhi 0x1395d8 <_Z13F_FileBinSizeR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x13955c ldr r3, [pc, #0x88] */
/* @0x139560 ldr r3, [pc, r3] */
/* @0x139564 ldrb r3, [r3, r0] */
/* @0x139568 cmp r3, #0 */
/* @0x13956c beq 0x1395d8 <_Z13F_FileBinSizeR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x139570 ldr r3, [pc, #0x78] */
/* @0x139574 add r0, r0, r0, lsl #1 */
/* @0x139578 mov r4, #0 */
/* @0x13957c str r4, [r6, #0xc] */
/* @0x139580 ldr r3, [pc, r3] */
/* @0x139584 add r7, r3, r0, lsl #2 */
/* @0x139588 ldr r0, [r7, #0x8] */
/* @0x13958c bl 0x18de24 <_ZN8LoadSave5ftellEP7_YYFILE> */
/* @0x139590 mov r1, r4 */
/* @0x139594 mov r2, #2 */
/* @0x139598 mov r5, r0 */
/* @0x13959c ldr r0, [r7, #0x8] */
/* @0x1395a0 bl 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli> */
/* @0x1395a4 ldr r0, [r7, #0x8] */
/* @0x1395a8 bl 0x18de24 <_ZN8LoadSave5ftellEP7_YYFILE> */
/* @0x1395ac mov r1, r5 */
/* @0x1395b0 mov r2, r4 */
/* @0x1395b4 vmov s15, r0 */
/* @0x1395b8 vcvt.f64.s32 d7, s15 */
/* @0x1395bc vmov r4, r5, d7 */
/* @0x1395c0 vmov r0, s14 */
/* @0x1395c4 mov r3, r5 */
/* @0x1395c8 stm r6, {r0, r3} */
/* @0x1395cc ldr r0, [r7, #0x8] */
/* @0x1395d0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1395d4 b 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli> */
/* @0x1395d8 ldr r0, [pc, #0x14] */
/* @0x1395dc mov r1, #0 */
/* @0x1395e0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1395e4 add r0, pc, r0 */
/* @0x1395e8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1395ec eoreq r5, r11, r12, lsr #26 */
/* @0x1395f0 eoreq r5, r11, r0, lsl sp */
/* @0x1395f4 mlaeq r0, r12, r11, r6 */

/* ── FUNC 0x1395f8 · F_FileBinPosition(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x1395f8 push {r4, lr} */
/* @0x1395fc mov r1, #0 */
/* @0x139600 mov r4, r0 */
/* @0x139604 ldr r0, [sp, #0x8] */
/* @0x139608 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13960c sub r3, r0, #1 */
/* @0x139610 cmp r3, #30 */
/* @0x139614 bhi 0x139668 <_Z17F_FileBinPositionR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x139618 ldr r3, [pc, #0x5c] */
/* @0x13961c ldr r3, [pc, r3] */
/* @0x139620 ldrb r3, [r3, r0] */
/* @0x139624 cmp r3, #0 */
/* @0x139628 beq 0x139668 <_Z17F_FileBinPositionR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x13962c ldr r3, [pc, #0x4c] */
/* @0x139630 add r0, r0, r0, lsl #1 */
/* @0x139634 mov r2, #0 */
/* @0x139638 str r2, [r4, #0xc] */
/* @0x13963c ldr r3, [pc, r3] */
/* @0x139640 add r3, r3, r0, lsl #2 */
/* @0x139644 ldr r0, [r3, #0x8] */
/* @0x139648 bl 0x18de24 <_ZN8LoadSave5ftellEP7_YYFILE> */
/* @0x13964c vmov s15, r0 */
/* @0x139650 vcvt.f64.s32 d7, s15 */
/* @0x139654 vmov r0, r1, d7 */
/* @0x139658 vmov r2, s14 */
/* @0x13965c mov r3, r1 */
/* @0x139660 stm r4, {r2, r3} */
/* @0x139664 pop {r4, pc} */
/* @0x139668 ldr r0, [pc, #0x14] */
/* @0x13966c mov r1, #0 */
/* @0x139670 pop {r4, lr} */
/* @0x139674 add r0, pc, r0 */
/* @0x139678 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13967c eoreq r5, r11, r0, ror r12 */
/* @0x139680 eoreq r5, r11, r4, asr r12 */
/* @0x139684 eoreq r6, r0, r12, lsl #22 */

/* ── FUNC 0x139688 · F_FileBinReadByte(RValue&, CInstance*, CInstance*, int, RValue*) · size=292 · insn=73 */
/* @0x139688 push {r4, r5, lr} */
/* @0x13968c sub sp, sp, #12 */
/* @0x139690 mov r4, r0 */
/* @0x139694 mov r1, #0 */
/* @0x139698 ldr r0, [sp, #0x18] */
/* @0x13969c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1396a0 sub r2, r0, #1 */
/* @0x1396a4 cmp r2, #30 */
/* @0x1396a8 bhi 0x13975c <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x1396ac ldr r2, [pc, #0xe4] */
/* @0x1396b0 ldr r2, [pc, r2] */
/* @0x1396b4 ldrb r2, [r2, r0] */
/* @0x1396b8 cmp r2, #0 */
/* @0x1396bc beq 0x13975c <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x1396c0 add r3, r0, r0, lsl #1 */
/* @0x1396c4 ldr r2, [pc, #0xd0] */
/* @0x1396c8 mov r1, #0 */
/* @0x1396cc str r1, [r4, #0xc] */
/* @0x1396d0 ldr r2, [pc, r2] */
/* @0x1396d4 lsl r1, r3, #2 */
/* @0x1396d8 add r0, r1, r2 */
/* @0x1396dc ldr r3, [r0, #0x8] */
/* @0x1396e0 cmp r3, #0 */
/* @0x1396e4 beq 0x139774 <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x1396e8 ldr r2, [r1, r2] */
/* @0x1396ec cmp r2, #0 */
/* @0x1396f0 beq 0x139774 <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x1396f4 ldr r2, [r0, #0x4] */
/* @0x1396f8 cmp r2, #1 */
/* @0x1396fc beq 0x139774 <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x139700 cmp r2, #0 */
/* @0x139704 beq 0x139710 <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x139708 cmp r2, #2 */
/* @0x13970c bne 0x139724 <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x139710 mov r1, #1 */
/* @0x139714 add r0, sp, #7 */
/* @0x139718 mov r2, r1 */
/* @0x13971c bl 0x18e070 <_ZN8LoadSave5freadEPKvjjP7_YYFILE> */
/* @0x139720 mov r5, r0 */
/* @0x139724 ldrb r2, [sp, #0x7] */
/* @0x139728 cmp r5, #0 */
/* @0x13972c vmov s15, r2 */
/* @0x139730 vcvt.f64.u32 d7, s15 */
/* @0x139734 vmov r2, r3, d7 */
/* @0x139738 stm r4, {r2, r3} */
/* @0x13973c bne 0x13976c <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x139740 ldr r0, [pc, #0x58] */
/* @0x139744 mov r1, r5 */
/* @0x139748 add r0, pc, r0 */
/* @0x13974c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139750 str r5, [r4] */
/* @0x139754 str r5, [r4, #0x4] */
/* @0x139758 b 0x13976c <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x13975c ldr r0, [pc, #0x40] */
/* @0x139760 mov r1, #0 */
/* @0x139764 add r0, pc, r0 */
/* @0x139768 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13976c add sp, sp, #12 */
/* @0x139770 pop {r4, r5, pc} */
/* @0x139774 ldr r0, [pc, #0x2c] */
/* @0x139778 mov r1, #0 */
/* @0x13977c add r0, pc, r0 */
/* @0x139780 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139784 mov r3, #0 */
/* @0x139788 str r3, [r4] */
/* @0x13978c str r3, [r4, #0x4] */
/* @0x139790 add sp, sp, #12 */
/* @0x139794 pop {r4, r5, pc} */
/* @0x139798 .word 0x002b5bdc */
/* @0x13979c eoreq r5, r11, r0, asr #23 */
/* @0x1397a0 eoreq r6, r0, r12, asr #20 */
/* @0x1397a4 eoreq r6, r0, r12, lsl r10 */
/* @0x1397a8 eoreq r6, r0, r8, lsl r10 */

/* ── FUNC 0x1397ac · F_FileBinWriteByte(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x1397ac push {r4, r5, lr} */
/* @0x1397b0 sub sp, sp, #12 */
/* @0x1397b4 mov r1, #0 */
/* @0x1397b8 ldr r5, [sp, #0x18] */
/* @0x1397bc mov r0, r5 */
/* @0x1397c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1397c4 mov r1, #1 */
/* @0x1397c8 mov r4, r0 */
/* @0x1397cc mov r0, r5 */
/* @0x1397d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1397d4 sub r3, r4, #1 */
/* @0x1397d8 cmp r3, #30 */
/* @0x1397dc strb r0, [sp, #0x7] */
/* @0x1397e0 bhi 0x139834 <_Z18F_FileBinWriteByteR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1397e4 ldr r3, [pc, #0x60] */
/* @0x1397e8 ldr r3, [pc, r3] */
/* @0x1397ec ldrb r3, [r3, r4] */
/* @0x1397f0 cmp r3, #0 */
/* @0x1397f4 beq 0x139834 <_Z18F_FileBinWriteByteR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1397f8 ldr r3, [pc, #0x50] */
/* @0x1397fc add r4, r4, r4, lsl #1 */
/* @0x139800 ldr r3, [pc, r3] */
/* @0x139804 add r3, r3, r4, lsl #2 */
/* @0x139808 ldr r2, [r3, #0x4] */
/* @0x13980c sub r2, r2, #1 */
/* @0x139810 cmp r2, #1 */
/* @0x139814 bhi 0x139844 <_Z18F_FileBinWriteByteR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x139818 mov r1, #1 */
/* @0x13981c ldr r3, [r3, #0x8] */
/* @0x139820 mov r2, r1 */
/* @0x139824 add r0, sp, #7 */
/* @0x139828 bl 0x18e2b0 <_ZN8LoadSave6fwriteEPKvjjP7_YYFILE> */
/* @0x13982c add sp, sp, #12 */
/* @0x139830 pop {r4, r5, pc} */
/* @0x139834 ldr r0, [pc, #0x18] */
/* @0x139838 mov r1, #0 */
/* @0x13983c add r0, pc, r0 */
/* @0x139840 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139844 add sp, sp, #12 */
/* @0x139848 pop {r4, r5, pc} */
/* @0x13984c eoreq r5, r11, r4, lsr #21 */
/* @0x139850 mlaeq r11, r0, r10, r5 */
/* @0x139854 eoreq r6, r0, r4, asr #18 */

/* ── FUNC 0x139858 · F_FileClose(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x139858 push {r4, r5, r6, lr} */
/* @0x13985c ldr r4, [pc, #0x38] */
/* @0x139860 ldr r4, [pc, r4] */
/* @0x139864 ldr r3, [r4] */
/* @0x139868 cmp r3, #0 */
/* @0x13986c popeq {r4, r5, r6, pc} */
/* @0x139870 ldr r5, [pc, #0x28] */
/* @0x139874 mov r6, #0 */
/* @0x139878 ldr r5, [pc, r5] */
/* @0x13987c ldr r0, [r5, #0x8] */
/* @0x139880 bl 0xb6850 <fclose@plt> */
/* @0x139884 str r6, [r5, #0x8] */
/* @0x139888 ldr r0, [r5] */
/* @0x13988c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x139890 str r6, [r5] */
/* @0x139894 str r6, [r4] */
/* @0x139898 pop {r4, r5, r6, pc} */
/* @0x13989c eoreq r5, r11, r0, lsl r10 */
/* @0x1398a0 .word 0x002b59fc */

/* ── FUNC 0x1398a4 · F_FileOpenWrite(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x1398a4 push {r3, r4, r5, r6, r7, lr} */
/* @0x1398a8 mov r1, #0 */
/* @0x1398ac ldr r0, [sp, #0x18] */
/* @0x1398b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1398b4 ldr r3, [pc, #0x98] */
/* @0x1398b8 add r3, pc, r3 */
/* @0x1398bc subs r7, r0, #0 */
/* @0x1398c0 beq 0x139940 <_Z15F_FileOpenWriteR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x1398c4 ldr r2, [pc, #0x8c] */
/* @0x1398c8 ldr r5, [r3, r2] */
/* @0x1398cc ldr r2, [r5] */
/* @0x1398d0 cmp r2, #0 */
/* @0x1398d4 ldr r2, [pc, #0x80] */
/* @0x1398d8 bne 0x13991c <_Z15F_FileOpenWriteR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1398dc ldr r4, [r3, r2] */
/* @0x1398e0 ldr r0, [r4] */
/* @0x1398e4 mov r6, #0 */
/* @0x1398e8 str r6, [r5] */
/* @0x1398ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1398f0 str r6, [r4] */
/* @0x1398f4 mov r0, r7 */
/* @0x1398f8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1398fc ldr r1, [pc, #0x5c] */
/* @0x139900 add r1, pc, r1 */
/* @0x139904 str r0, [r4] */
/* @0x139908 bl 0xb6844 <fopen@plt> */
/* @0x13990c mov r3, #2 */
/* @0x139910 str r3, [r5] */
/* @0x139914 str r0, [r4, #0x8] */
/* @0x139918 pop {r3, r4, r5, r6, r7, pc} */
/* @0x13991c ldr r4, [r3, r2] */
/* @0x139920 mov r6, #0 */
/* @0x139924 ldr r0, [r4] */
/* @0x139928 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13992c str r6, [r4] */
/* @0x139930 ldr r0, [r4, #0x8] */
/* @0x139934 bl 0xb6850 <fclose@plt> */
/* @0x139938 str r6, [r4, #0x8] */
/* @0x13993c b 0x1398e0 <_Z15F_FileOpenWriteR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x139940 ldr r0, [pc, #0x1c] */
/* @0x139944 mov r1, r7 */
/* @0x139948 pop {r3, r4, r5, r6, r7, lr} */
/* @0x13994c add r0, pc, r0 */
/* @0x139950 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139954 mlaeq r11, r8, r3, r8 */
/* @0x139958 .word 0xffffd620 */
/* @0x13995c .word 0xffffd624 */
/* @0x139960 eoreq r6, r0, r8, asr #17 */
/* @0x139964 eoreq r6, r0, r12, asr r8 */

/* ── FUNC 0x139968 · F_FileOpenAppend(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x139968 push {r3, r4, r5, r6, r7, lr} */
/* @0x13996c mov r1, #0 */
/* @0x139970 ldr r0, [sp, #0x18] */
/* @0x139974 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x139978 ldr r3, [pc, #0x98] */
/* @0x13997c add r3, pc, r3 */
/* @0x139980 subs r7, r0, #0 */
/* @0x139984 beq 0x139a04 <_Z16F_FileOpenAppendR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x139988 ldr r2, [pc, #0x8c] */
/* @0x13998c ldr r5, [r3, r2] */
/* @0x139990 ldr r2, [r5] */
/* @0x139994 cmp r2, #0 */
/* @0x139998 ldr r2, [pc, #0x80] */
/* @0x13999c bne 0x1399e0 <_Z16F_FileOpenAppendR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1399a0 ldr r4, [r3, r2] */
/* @0x1399a4 ldr r0, [r4] */
/* @0x1399a8 mov r6, #0 */
/* @0x1399ac str r6, [r5] */
/* @0x1399b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1399b4 str r6, [r4] */
/* @0x1399b8 mov r0, r7 */
/* @0x1399bc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1399c0 ldr r1, [pc, #0x5c] */
/* @0x1399c4 add r1, pc, r1 */
/* @0x1399c8 str r0, [r4] */
/* @0x1399cc bl 0xb6844 <fopen@plt> */
/* @0x1399d0 mov r3, #2 */
/* @0x1399d4 str r3, [r5] */
/* @0x1399d8 str r0, [r4, #0x8] */
/* @0x1399dc pop {r3, r4, r5, r6, r7, pc} */
/* @0x1399e0 ldr r4, [r3, r2] */
/* @0x1399e4 mov r6, #0 */
/* @0x1399e8 ldr r0, [r4] */
/* @0x1399ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1399f0 str r6, [r4] */
/* @0x1399f4 ldr r0, [r4, #0x8] */
/* @0x1399f8 bl 0xb6850 <fclose@plt> */
/* @0x1399fc str r6, [r4, #0x8] */
/* @0x139a00 b 0x1399a4 <_Z16F_FileOpenAppendR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x139a04 ldr r0, [pc, #0x1c] */
/* @0x139a08 mov r1, r7 */
/* @0x139a0c pop {r3, r4, r5, r6, r7, lr} */
/* @0x139a10 add r0, pc, r0 */
/* @0x139a14 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139a18 .word 0x002b82d4 */
/* @0x139a1c .word 0xffffd620 */
/* @0x139a20 .word 0xffffd624 */
/* @0x139a24 eoreq r6, r0, r12, lsr #16 */
/* @0x139a28 .word 0x002067bc */

/* ── FUNC 0x139a2c · F_FileEof(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x139a2c push {r3, r4, r5, lr} */
/* @0x139a30 mov r4, r0 */
/* @0x139a34 ldr r3, [pc, #0x58] */
/* @0x139a38 ldr r3, [pc, r3] */
/* @0x139a3c ldr r3, [r3] */
/* @0x139a40 cmp r3, #1 */
/* @0x139a44 beq 0x139a5c <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x139a48 ldr r0, [pc, #0x48] */
/* @0x139a4c mov r1, #0 */
/* @0x139a50 pop {r3, r4, r5, lr} */
/* @0x139a54 add r0, pc, r0 */
/* @0x139a58 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139a5c ldr r3, [pc, #0x38] */
/* @0x139a60 mov r5, #0 */
/* @0x139a64 str r5, [r0, #0xc] */
/* @0x139a68 ldr r3, [pc, r3] */
/* @0x139a6c ldr r0, [r3, #0x8] */
/* @0x139a70 bl 0xb6874 <feof@plt> */
/* @0x139a74 cmp r0, #0 */
/* @0x139a78 moveq r5, r0 */
/* @0x139a7c movne r3, r5 */
/* @0x139a80 moveq r3, r5 */
/* @0x139a84 movtne r3, #0x3ff0 */
/* @0x139a88 str r5, [r4] */
/* @0x139a8c str r3, [r4, #0x4] */
/* @0x139a90 pop {r3, r4, r5, pc} */
/* @0x139a94 eoreq r5, r11, r8, lsr r8 */
/* @0x139a98 .word 0x002065dc */
/* @0x139a9c eoreq r5, r11, r12, lsl #16 */

/* ── FUNC 0x139aa0 · anon_139aa0 · size=180 · insn=46 */
/* @0x139aa0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x139aa4 sub sp, sp, #1024 */
/* @0x139aa8 ldr r5, [pc, #0xa0] */
/* @0x139aac sub sp, sp, #12 */
/* @0x139ab0 add r7, sp, #4 */
/* @0x139ab4 ldr r4, [pc, #0x98] */
/* @0x139ab8 ldr r5, [pc, r5] */
/* @0x139abc mov r8, r0 */
/* @0x139ac0 mov r1, #0 */
/* @0x139ac4 mov r0, r7 */
/* @0x139ac8 ldr r3, [r5] */
/* @0x139acc mov r2, #1024 */
/* @0x139ad0 add r9, sp, #1024 */
/* @0x139ad4 add r6, sp, #3 */
/* @0x139ad8 add r9, r9, #3 */
/* @0x139adc str r3, [sp, #0x404] */
/* @0x139ae0 bl 0xb65b0 <memset@plt> */
/* @0x139ae4 ldr r4, [pc, r4] */
/* @0x139ae8 ldr r0, [r4, #0x8] */
/* @0x139aec bl 0xb6880 <fgetc@plt> */
/* @0x139af0 uxtb r3, r0 */
/* @0x139af4 ldr r0, [r4, #0x8] */
/* @0x139af8 cmp r3, #13 */
/* @0x139afc cmpne r3, #10 */
/* @0x139b00 bne 0x139b30 <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x139b04 bl 0xb6874 <feof@plt> */
/* @0x139b08 mov r0, r8 */
/* @0x139b0c mov r1, r7 */
/* @0x139b10 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x139b14 ldr r2, [sp, #0x404] */
/* @0x139b18 ldr r3, [r5] */
/* @0x139b1c cmp r2, r3 */
/* @0x139b20 bne 0x139b4c <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x139b24 add sp, sp, #1024 */
/* @0x139b28 add sp, sp, #12 */
/* @0x139b2c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x139b30 strb r3, [r6, #0x1]! */
/* @0x139b34 bl 0xb6874 <feof@plt> */
/* @0x139b38 cmp r0, #0 */
/* @0x139b3c bne 0x139b08 <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x139b40 cmp r6, r9 */
/* @0x139b44 bne 0x139ae8 <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x139b48 b 0x139b08 <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x139b4c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x139b50 mlaeq r11, r8, lr, r3 */
/* @0x139b54 mlaeq r11, r0, r7, r5 */

/* ── FUNC 0x139b58 · F_FileReadString(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x139b58 ldr r3, [pc, #0x20] */
/* @0x139b5c ldr r3, [pc, r3] */
/* @0x139b60 ldr r3, [r3] */
/* @0x139b64 cmp r3, #1 */
/* @0x139b68 beq 0x139b7c <_Z16F_FileReadStringR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x139b6c ldr r0, [pc, #0x10] */
/* @0x139b70 mov r1, #0 */
/* @0x139b74 add r0, pc, r0 */
/* @0x139b78 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139b7c b 0x139aa0 <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x139b80 eoreq r5, r11, r4, lsl r7 */
/* @0x139b84 eoreq r6, r0, r0, lsl #13 */

/* ── FUNC 0x139b88 · anon_139b88 · size=180 · insn=46 */
/* @0x139b88 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x139b8c sub sp, sp, #1024 */
/* @0x139b90 ldr r8, [pc, #0xa0] */
/* @0x139b94 sub sp, sp, #8 */
/* @0x139b98 add r7, sp, #4 */
/* @0x139b9c ldr r6, [pc, #0x98] */
/* @0x139ba0 ldr r8, [pc, r8] */
/* @0x139ba4 mov r1, #0 */
/* @0x139ba8 mov r9, r0 */
/* @0x139bac mov r2, #1024 */
/* @0x139bb0 ldr r3, [r8] */
/* @0x139bb4 mov r0, r7 */
/* @0x139bb8 mov r4, r1 */
/* @0x139bbc movw r10, #0x3ff */
/* @0x139bc0 str r3, [sp, #0x404] */
/* @0x139bc4 bl 0xb65b0 <memset@plt> */
/* @0x139bc8 ldr r6, [pc, r6] */
/* @0x139bcc ldr r0, [r6, #0x8] */
/* @0x139bd0 bl 0xb6880 <fgetc@plt> */
/* @0x139bd4 uxtb r5, r0 */
/* @0x139bd8 ldr r0, [r6, #0x8] */
/* @0x139bdc strb r5, [r7, r4] */
/* @0x139be0 bl 0xb6874 <feof@plt> */
/* @0x139be4 cmp r0, #0 */
/* @0x139be8 bne 0x139c0c <_Z16F_FileReadStringR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x139bec add r4, r4, #1 */
/* @0x139bf0 cmp r4, r10 */
/* @0x139bf4 movgt r3, #0 */
/* @0x139bf8 movle r3, #1 */
/* @0x139bfc cmp r5, #10 */
/* @0x139c00 moveq r3, #0 */
/* @0x139c04 cmp r3, #0 */
/* @0x139c08 bne 0x139bcc <_Z16F_FileReadStringR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x139c0c mov r0, r9 */
/* @0x139c10 mov r1, r7 */
/* @0x139c14 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x139c18 ldr r2, [sp, #0x404] */
/* @0x139c1c ldr r3, [r8] */
/* @0x139c20 cmp r2, r3 */
/* @0x139c24 bne 0x139c34 <_Z16F_FileReadStringR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x139c28 add sp, sp, #1024 */
/* @0x139c2c add sp, sp, #8 */
/* @0x139c30 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x139c34 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x139c38 .word 0x002b3db0 */
/* @0x139c3c eoreq r5, r11, r12, lsr #13 */

/* ── FUNC 0x139c40 · F_FileReadLn(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x139c40 ldr r3, [pc, #0x20] */
/* @0x139c44 ldr r3, [pc, r3] */
/* @0x139c48 ldr r3, [r3] */
/* @0x139c4c cmp r3, #1 */
/* @0x139c50 beq 0x139c64 <_Z12F_FileReadLnR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x139c54 ldr r0, [pc, #0x10] */
/* @0x139c58 mov r1, #0 */
/* @0x139c5c add r0, pc, r0 */
/* @0x139c60 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139c64 b 0x139b88 <_Z16F_FileReadStringR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x139c68 eoreq r5, r11, r12, lsr #12 */
/* @0x139c6c mlaeq r0, r8, r5, r6 */

/* ── FUNC 0x139c70 · F_FileReadReal(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x139c70 ldr r3, [pc, #0x40] */
/* @0x139c74 ldr r3, [pc, r3] */
/* @0x139c78 ldr r3, [r3] */
/* @0x139c7c cmp r3, #1 */
/* @0x139c80 beq 0x139c94 <_Z14F_FileReadRealR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x139c84 ldr r0, [pc, #0x30] */
/* @0x139c88 mov r1, #0 */
/* @0x139c8c add r0, pc, r0 */
/* @0x139c90 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139c94 ldr r3, [pc, #0x24] */
/* @0x139c98 mov r1, #0 */
/* @0x139c9c str r1, [r0, #0xc] */
/* @0x139ca0 mov r2, r0 */
/* @0x139ca4 ldr r3, [pc, r3] */
/* @0x139ca8 ldr r1, [pc, #0x14] */
/* @0x139cac ldr r0, [r3, #0x8] */
/* @0x139cb0 add r1, pc, r1 */
/* @0x139cb4 b 0xb688c <fscanf@plt> */
/* @0x139cb8 .word 0x002b55fc */
/* @0x139cbc eoreq r6, r0, r8, ror #10 */
/* @0x139cc0 .word 0x002b55d0 */
/* @0x139cc4 eoreq r6, r0, r4, ror #10 */

/* ── FUNC 0x139cc8 · F_FileWriteString(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x139cc8 push {r3, lr} */
/* @0x139ccc mov r1, #0 */
/* @0x139cd0 ldr r0, [sp, #0x8] */
/* @0x139cd4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x139cd8 ldr r3, [pc, #0x3c] */
/* @0x139cdc ldr r3, [pc, r3] */
/* @0x139ce0 ldr r3, [r3] */
/* @0x139ce4 cmp r3, #2 */
/* @0x139ce8 bne 0x139d08 <_Z17F_FileWriteStringR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x139cec cmp r0, #0 */
/* @0x139cf0 popeq {r3, pc} */
/* @0x139cf4 ldr r3, [pc, #0x24] */
/* @0x139cf8 ldr r3, [pc, r3] */
/* @0x139cfc ldr r1, [r3, #0x8] */
/* @0x139d00 pop {r3, lr} */
/* @0x139d04 b 0xb6898 <fputs@plt> */
/* @0x139d08 ldr r0, [pc, #0x14] */
/* @0x139d0c mov r1, #0 */
/* @0x139d10 pop {r3, lr} */
/* @0x139d14 add r0, pc, r0 */
/* @0x139d18 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139d1c mlaeq r11, r4, r5, r5 */
/* @0x139d20 eoreq r5, r11, r12, ror r5 */
/* @0x139d24 eoreq r6, r0, r8, ror r3 */

/* ── FUNC 0x139d28 · F_FileWriteReal(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x139d28 push {r4, lr} */
/* @0x139d2c mov r1, #0 */
/* @0x139d30 ldr r0, [sp, #0x8] */
/* @0x139d34 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x139d38 ldr r3, [pc, #0x44] */
/* @0x139d3c ldr r3, [pc, r3] */
/* @0x139d40 ldr r3, [r3] */
/* @0x139d44 cmp r3, #2 */
/* @0x139d48 beq 0x139d60 <_Z15F_FileWriteRealR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x139d4c ldr r0, [pc, #0x34] */
/* @0x139d50 mov r1, #0 */
/* @0x139d54 pop {r4, lr} */
/* @0x139d58 add r0, pc, r0 */
/* @0x139d5c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139d60 ldr r12, [pc, #0x24] */
/* @0x139d64 mov r3, r1 */
/* @0x139d68 ldr r1, [pc, #0x20] */
/* @0x139d6c mov r2, r0 */
/* @0x139d70 ldr r12, [pc, r12] */
/* @0x139d74 add r1, pc, r1 */
/* @0x139d78 ldr r0, [r12, #0x8] */
/* @0x139d7c pop {r4, lr} */
/* @0x139d80 b 0xb68a4 <fprintf@plt> */
/* @0x139d84 eoreq r5, r11, r4, lsr r5 */
/* @0x139d88 eoreq r6, r0, r4, lsr r3 */
/* @0x139d8c eoreq r5, r11, r4, lsl #10 */
/* @0x139d90 eoreq r6, r0, r4, lsr #9 */

/* ── FUNC 0x139d94 · F_FileWriteLn(RValue&, CInstance*, CInstance*, int, RValue*) · size=68 · insn=17 */
/* @0x139d94 ldr r3, [pc, #0x30] */
/* @0x139d98 ldr r3, [pc, r3] */
/* @0x139d9c ldr r3, [r3] */
/* @0x139da0 cmp r3, #2 */
/* @0x139da4 beq 0x139db8 <_Z13F_FileWriteLnR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x139da8 ldr r0, [pc, #0x20] */
/* @0x139dac mov r1, #0 */
/* @0x139db0 add r0, pc, r0 */
/* @0x139db4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139db8 ldr r3, [pc, #0x14] */
/* @0x139dbc mov r0, #10 */
/* @0x139dc0 ldr r3, [pc, r3] */
/* @0x139dc4 ldr r1, [r3, #0x8] */
/* @0x139dc8 b 0xb68b0 <fputc@plt> */
/* @0x139dcc .word 0x002b54d8 */
/* @0x139dd0 .word 0x002062dc */
/* @0x139dd4 .word 0x002b54b4 */

/* ── FUNC 0x139dd8 · F_FilenameDir(RValue&, CInstance*, CInstance*, int, RValue*) · size=296 · insn=74 */
/* @0x139dd8 push {r4, r5, r6, r7, lr} */
/* @0x139ddc sub sp, sp, #1024 */
/* @0x139de0 ldr r4, [pc, #0x110] */
/* @0x139de4 sub sp, sp, #12 */
/* @0x139de8 mov r5, r0 */
/* @0x139dec mov r1, #0 */
/* @0x139df0 ldr r4, [pc, r4] */
/* @0x139df4 ldr r0, [sp, #0x420] */
/* @0x139df8 ldr r3, [r4] */
/* @0x139dfc str r3, [sp, #0x404] */
/* @0x139e00 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x139e04 mov r3, #0 */
/* @0x139e08 mov r1, #1 */
/* @0x139e0c str r3, [r5] */
/* @0x139e10 str r1, [r5, #0xc] */
/* @0x139e14 subs r7, r0, #0 */
/* @0x139e18 beq 0x139ebc <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x139e1c bl 0x214f5c <_Z15ExtractFilePathPKc> */
/* @0x139e20 subs r6, r0, #0 */
/* @0x139e24 beq 0x139e64 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x139e28 bl 0xb6538 <strlen@plt> */
/* @0x139e2c subs r0, r0, #1 */
/* @0x139e30 blo 0x139e80 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x139e34 cmp r0, #0 */
/* @0x139e38 ble 0x139e50 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x139e3c ldrb r2, [r6, r0] */
/* @0x139e40 cmp r2, #92 */
/* @0x139e44 cmpne r2, #47 */
/* @0x139e48 moveq r2, #0 */
/* @0x139e4c strbeq r2, [r6, r0] */
/* @0x139e50 mov r0, r5 */
/* @0x139e54 mov r1, r6 */
/* @0x139e58 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x139e5c mov r0, r6 */
/* @0x139e60 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x139e64 ldr r2, [sp, #0x404] */
/* @0x139e68 ldr r3, [r4] */
/* @0x139e6c cmp r2, r3 */
/* @0x139e70 bne 0x139ef4 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x139e74 add sp, sp, #1024 */
/* @0x139e78 add sp, sp, #12 */
/* @0x139e7c pop {r4, r5, r6, r7, pc} */
/* @0x139e80 mov r0, r7 */
/* @0x139e84 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x139e88 cmp r0, #0 */
/* @0x139e8c beq 0x139ecc <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x139e90 add r6, sp, #4 */
/* @0x139e94 mov r2, r7 */
/* @0x139e98 mov r1, #1024 */
/* @0x139e9c mov r0, r6 */
/* @0x139ea0 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x139ea4 mov r0, r6 */
/* @0x139ea8 bl 0x214f5c <_Z15ExtractFilePathPKc> */
/* @0x139eac mov r6, r0 */
/* @0x139eb0 bl 0xb6538 <strlen@plt> */
/* @0x139eb4 sub r0, r0, #1 */
/* @0x139eb8 b 0x139e34 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x139ebc ldr r0, [pc, #0x38] */
/* @0x139ec0 add r0, pc, r0 */
/* @0x139ec4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x139ec8 b 0x139e64 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x139ecc mov r0, r7 */
/* @0x139ed0 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x139ed4 cmp r0, #0 */
/* @0x139ed8 beq 0x139e50 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x139edc add r6, sp, #4 */
/* @0x139ee0 mov r2, r7 */
/* @0x139ee4 mov r1, #1024 */
/* @0x139ee8 mov r0, r6 */
/* @0x139eec bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x139ef0 b 0x139ea4 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x139ef4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x139ef8 eoreq r3, r11, r0, ror #22 */
/* @0x139efc eoreq r6, r0, r0, ror #6 */

/* ── FUNC 0x139f00 · F_FilenamePath(RValue&, CInstance*, CInstance*, int, RValue*) · size=344 · insn=86 */
/* @0x139f00 push {r4, r5, r6, r7, r8, lr} */
/* @0x139f04 sub sp, sp, #1024 */
/* @0x139f08 ldr r4, [pc, #0x13c] */
/* @0x139f0c sub sp, sp, #8 */
/* @0x139f10 mov r5, r0 */
/* @0x139f14 mov r1, #0 */
/* @0x139f18 ldr r4, [pc, r4] */
/* @0x139f1c ldr r0, [sp, #0x420] */
/* @0x139f20 ldr r3, [r4] */
/* @0x139f24 str r3, [sp, #0x404] */
/* @0x139f28 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x139f2c mov r3, #0 */
/* @0x139f30 mov r1, #1 */
/* @0x139f34 str r3, [r5] */
/* @0x139f38 str r1, [r5, #0xc] */
/* @0x139f3c subs r8, r0, #0 */
/* @0x139f40 beq 0x13a038 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x139f44 bl 0x214f5c <_Z15ExtractFilePathPKc> */
/* @0x139f48 mov r7, r0 */
/* @0x139f4c bl 0xb6538 <strlen@plt> */
/* @0x139f50 subs r6, r0, #0 */
/* @0x139f54 beq 0x139fcc <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x139f58 cmp r6, #0 */
/* @0x139f5c ble 0x139fb0 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x139f60 ldr r1, [pc, #0xe8] */
/* @0x139f64 mov r3, #1 */
/* @0x139f68 movw r2, #0x64e */
/* @0x139f6c add r0, r6, #2 */
/* @0x139f70 add r1, pc, r1 */
/* @0x139f74 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x139f78 mov r1, r7 */
/* @0x139f7c mov r2, r6 */
/* @0x139f80 mov r8, r0 */
/* @0x139f84 bl 0xb6568 <strncpy@plt> */
/* @0x139f88 mov r3, r8 */
/* @0x139f8c mov r1, #47 */
/* @0x139f90 mov r0, r7 */
/* @0x139f94 strb r1, [r3, r6]! */
/* @0x139f98 mov r2, #0 */
/* @0x139f9c strb r2, [r3, #0x1] */
/* @0x139fa0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x139fa4 mov r0, r5 */
/* @0x139fa8 mov r1, r8 */
/* @0x139fac bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x139fb0 ldr r2, [sp, #0x404] */
/* @0x139fb4 ldr r3, [r4] */
/* @0x139fb8 cmp r2, r3 */
/* @0x139fbc bne 0x13a048 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x139fc0 add sp, sp, #1024 */
/* @0x139fc4 add sp, sp, #8 */
/* @0x139fc8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x139fcc mov r0, r7 */
/* @0x139fd0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x139fd4 mov r0, r8 */
/* @0x139fd8 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x139fdc cmp r0, #0 */
/* @0x139fe0 beq 0x13a010 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x139fe4 add r6, sp, #4 */
/* @0x139fe8 mov r2, r8 */
/* @0x139fec mov r1, #1024 */
/* @0x139ff0 mov r0, r6 */
/* @0x139ff4 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x139ff8 mov r0, r6 */
/* @0x139ffc bl 0x214f5c <_Z15ExtractFilePathPKc> */
/* @0x13a000 mov r7, r0 */
/* @0x13a004 bl 0xb6538 <strlen@plt> */
/* @0x13a008 mov r6, r0 */
/* @0x13a00c b 0x139f58 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x13a010 mov r0, r8 */
/* @0x13a014 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x13a018 cmp r0, #0 */
/* @0x13a01c beq 0x139fb0 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x13a020 add r6, sp, #4 */
/* @0x13a024 mov r2, r8 */
/* @0x13a028 mov r1, #1024 */
/* @0x13a02c mov r0, r6 */
/* @0x13a030 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x13a034 b 0x139ff8 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x13a038 ldr r0, [pc, #0x14] */
/* @0x13a03c add r0, pc, r0 */
/* @0x13a040 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13a044 b 0x139fb0 <_Z14F_FilenamePathR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x13a048 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13a04c eoreq r3, r11, r8, lsr r10 */
/* @0x13a050 eoreq r6, r0, r0, ror #1 */
/* @0x13a054 eoreq r6, r0, r8, lsl #4 */

/* ── FUNC 0x13a058 · F_IniKeyExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x13a058 push {r4, r5, r6, lr} */
/* @0x13a05c mov r1, #0 */
/* @0x13a060 ldr r5, [sp, #0x10] */
/* @0x13a064 mov r4, r0 */
/* @0x13a068 mov r0, r5 */
/* @0x13a06c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a070 mov r1, #1 */
/* @0x13a074 mov r6, r0 */
/* @0x13a078 mov r0, r5 */
/* @0x13a07c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a080 ldr r3, [pc, #0x54] */
/* @0x13a084 ldr r3, [pc, r3] */
/* @0x13a088 mov r2, r0 */
/* @0x13a08c ldr r0, [r3] */
/* @0x13a090 cmp r0, #0 */
/* @0x13a094 beq 0x13a0c8 <_Z14F_IniKeyExistsR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x13a098 mov r1, r6 */
/* @0x13a09c bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x13a0a0 mov r3, #0 */
/* @0x13a0a4 str r3, [r4, #0xc] */
/* @0x13a0a8 cmp r0, #0 */
/* @0x13a0ac moveq r3, r0 */
/* @0x13a0b0 movne r2, r3 */
/* @0x13a0b4 moveq r2, r3 */
/* @0x13a0b8 movtne r2, #0x3ff0 */
/* @0x13a0bc str r3, [r4] */
/* @0x13a0c0 str r2, [r4, #0x4] */
/* @0x13a0c4 pop {r4, r5, r6, pc} */
/* @0x13a0c8 mov r1, r0 */
/* @0x13a0cc ldr r0, [pc, #0xc] */
/* @0x13a0d0 pop {r4, r5, r6, lr} */
/* @0x13a0d4 add r0, pc, r0 */
/* @0x13a0d8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13a0dc eoreq r5, r11, r0, lsl r2 */
/* @0x13a0e0 mlaeq r0, r4, r1, r6 */

/* ── FUNC 0x13a0e4 · F_IniReadString(RValue&, CInstance*, CInstance*, int, RValue*) · size=236 · insn=59 */
/* @0x13a0e4 push {r4, r5, r6, r7, lr} */
/* @0x13a0e8 sub sp, sp, #20 */
/* @0x13a0ec ldr r4, [pc, #0xd0] */
/* @0x13a0f0 mov r6, r0 */
/* @0x13a0f4 ldr r5, [sp, #0x28] */
/* @0x13a0f8 ldr r4, [pc, r4] */
/* @0x13a0fc ldr r1, [r4] */
/* @0x13a100 cmp r1, #0 */
/* @0x13a104 beq 0x13a1b0 <_Z15F_IniReadStringR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x13a108 mov r1, #0 */
/* @0x13a10c mov r0, r5 */
/* @0x13a110 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a114 mov r1, #1 */
/* @0x13a118 mov r7, r0 */
/* @0x13a11c mov r0, r5 */
/* @0x13a120 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a124 mov r1, r7 */
/* @0x13a128 mov r2, r0 */
/* @0x13a12c ldr r0, [r4] */
/* @0x13a130 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x13a134 subs r4, r0, #0 */
/* @0x13a138 beq 0x13a150 <_Z15F_IniReadStringR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x13a13c mov r0, r6 */
/* @0x13a140 ldr r1, [r4, #0x8] */
/* @0x13a144 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x13a148 add sp, sp, #20 */
/* @0x13a14c pop {r4, r5, r6, r7, pc} */
/* @0x13a150 ldr r1, [pc, #0x70] */
/* @0x13a154 mov r12, #16 */
/* @0x13a158 mov r0, r12 */
/* @0x13a15c movw r2, #0x7bf */
/* @0x13a160 add r1, pc, r1 */
/* @0x13a164 mov r3, #1 */
/* @0x13a168 str r12, [sp, #0x4] */
/* @0x13a16c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13a170 add r2, sp, #16 */
/* @0x13a174 add r3, r5, #32 */
/* @0x13a178 add r1, sp, #8 */
/* @0x13a17c str r0, [sp, #0x8] */
/* @0x13a180 str r0, [r2, #-0x4]! */
/* @0x13a184 strb r4, [r0] */
/* @0x13a188 mov r0, r2 */
/* @0x13a18c add r2, sp, #4 */
/* @0x13a190 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x13a194 mov r0, r6 */
/* @0x13a198 ldr r1, [sp, #0x8] */
/* @0x13a19c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x13a1a0 ldr r0, [sp, #0x8] */
/* @0x13a1a4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x13a1a8 add sp, sp, #20 */
/* @0x13a1ac pop {r4, r5, r6, r7, pc} */
/* @0x13a1b0 ldr r0, [pc, #0x14] */
/* @0x13a1b4 add r0, pc, r0 */
/* @0x13a1b8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13a1bc add sp, sp, #20 */
/* @0x13a1c0 pop {r4, r5, r6, r7, pc} */
/* @0x13a1c4 mlaeq r11, r12, r1, r5 */
/* @0x13a1c8 .word 0x00205ef0 */
/* @0x13a1cc strhteq r6, [r0], -r4 */

/* ── FUNC 0x13a1d0 · F_IniWriteString(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x13a1d0 push {r4, r5, r6, lr} */
/* @0x13a1d4 mov r1, #0 */
/* @0x13a1d8 ldr r4, [sp, #0x10] */
/* @0x13a1dc mov r0, r4 */
/* @0x13a1e0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a1e4 mov r1, #1 */
/* @0x13a1e8 mov r5, r0 */
/* @0x13a1ec mov r0, r4 */
/* @0x13a1f0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a1f4 mov r1, #2 */
/* @0x13a1f8 mov r6, r0 */
/* @0x13a1fc mov r0, r4 */
/* @0x13a200 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a204 ldr r12, [pc, #0x34] */
/* @0x13a208 ldr r12, [pc, r12] */
/* @0x13a20c mov r3, r0 */
/* @0x13a210 ldr r0, [r12] */
/* @0x13a214 cmp r0, #0 */
/* @0x13a218 beq 0x13a22c <_Z16F_IniWriteStringR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x13a21c mov r1, r5 */
/* @0x13a220 mov r2, r6 */
/* @0x13a224 pop {r4, r5, r6, lr} */
/* @0x13a228 b 0x235edc <_ZN7IniFile6SetKeyEPKcS1_S1_> */
/* @0x13a22c mov r1, r0 */
/* @0x13a230 ldr r0, [pc, #0xc] */
/* @0x13a234 pop {r4, r5, r6, lr} */
/* @0x13a238 add r0, pc, r0 */
/* @0x13a23c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13a240 eoreq r5, r11, r12, lsl #1 */
/* @0x13a244 eoreq r6, r0, r0, lsr r0 */

/* ── FUNC 0x13a248 · F_IniSectionExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x13a248 push {r4, lr} */
/* @0x13a24c mov r1, #0 */
/* @0x13a250 mov r4, r0 */
/* @0x13a254 ldr r0, [sp, #0x8] */
/* @0x13a258 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a25c ldr r3, [pc, #0x50] */
/* @0x13a260 ldr r3, [pc, r3] */
/* @0x13a264 mov r1, r0 */
/* @0x13a268 ldr r0, [r3] */
/* @0x13a26c cmp r0, #0 */
/* @0x13a270 beq 0x13a2a0 <_Z18F_IniSectionExistsR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x13a274 bl 0x235a90 <_ZN7IniFile10GetSectionEPKc> */
/* @0x13a278 mov r3, #0 */
/* @0x13a27c str r3, [r4, #0xc] */
/* @0x13a280 cmp r0, #0 */
/* @0x13a284 moveq r3, r0 */
/* @0x13a288 movne r2, r3 */
/* @0x13a28c moveq r2, r3 */
/* @0x13a290 movtne r2, #0x3ff0 */
/* @0x13a294 str r3, [r4] */
/* @0x13a298 str r2, [r4, #0x4] */
/* @0x13a29c pop {r4, pc} */
/* @0x13a2a0 mov r1, r0 */
/* @0x13a2a4 ldr r0, [pc, #0xc] */
/* @0x13a2a8 pop {r4, lr} */
/* @0x13a2ac add r0, pc, r0 */
/* @0x13a2b0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13a2b4 eoreq r5, r11, r4, lsr r0 */
/* @0x13a2b8 .word 0x00205fbc */

/* ── FUNC 0x13a2bc · F_IniKeyDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x13a2bc push {r3, r4, r5, lr} */
/* @0x13a2c0 mov r1, #0 */
/* @0x13a2c4 ldr r4, [sp, #0x10] */
/* @0x13a2c8 mov r0, r4 */
/* @0x13a2cc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a2d0 mov r1, #1 */
/* @0x13a2d4 mov r5, r0 */
/* @0x13a2d8 mov r0, r4 */
/* @0x13a2dc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a2e0 ldr r3, [pc, #0x30] */
/* @0x13a2e4 ldr r3, [pc, r3] */
/* @0x13a2e8 mov r2, r0 */
/* @0x13a2ec ldr r0, [r3] */
/* @0x13a2f0 cmp r0, #0 */
/* @0x13a2f4 beq 0x13a304 <_Z14F_IniKeyDeleteR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x13a2f8 mov r1, r5 */
/* @0x13a2fc pop {r3, r4, r5, lr} */
/* @0x13a300 b 0x235b94 <_ZN7IniFile9DeleteKeyEPKcS1_> */
/* @0x13a304 mov r1, r0 */
/* @0x13a308 ldr r0, [pc, #0xc] */
/* @0x13a30c pop {r3, r4, r5, lr} */
/* @0x13a310 add r0, pc, r0 */
/* @0x13a314 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13a318 .word 0x002b4fb0 */
/* @0x13a31c eoreq r5, r0, r0, lsl #31 */

/* ── FUNC 0x13a320 · F_IniSectionDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x13a320 push {r3, lr} */
/* @0x13a324 mov r1, #0 */
/* @0x13a328 ldr r0, [sp, #0x8] */
/* @0x13a32c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a330 ldr r3, [pc, #0x2c] */
/* @0x13a334 ldr r3, [pc, r3] */
/* @0x13a338 mov r1, r0 */
/* @0x13a33c ldr r0, [r3] */
/* @0x13a340 cmp r0, #0 */
/* @0x13a344 beq 0x13a350 <_Z18F_IniSectionDeleteR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x13a348 pop {r3, lr} */
/* @0x13a34c b 0x235c2c <_ZN7IniFile13DeleteSectionEPKc> */
/* @0x13a350 mov r1, r0 */
/* @0x13a354 ldr r0, [pc, #0xc] */
/* @0x13a358 pop {r3, lr} */
/* @0x13a35c add r0, pc, r0 */
/* @0x13a360 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13a364 eoreq r4, r11, r0, ror #30 */
/* @0x13a368 eoreq r5, r0, r4, lsr pc */

/* ── FUNC 0x13a36c · F_LoadCSV(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x13a36c push {r4, lr} */
/* @0x13a370 mov r3, #0 */
/* @0x13a374 ldr r2, [sp, #0x8] */
/* @0x13a378 mov r1, r3 */
/* @0x13a37c movt r3, #0xbff0 */
/* @0x13a380 str r1, [r0, #0xc] */
/* @0x13a384 stm r0, {r1, r3} */
/* @0x13a388 mov r4, r0 */
/* @0x13a38c ldr r3, [r2, #0xc] */
/* @0x13a390 bic r3, r3, #-16777216 */
/* @0x13a394 cmp r3, #1 */
/* @0x13a398 beq 0x13a3ac <_Z9F_LoadCSVR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x13a39c ldr r0, [pc, #0x30] */
/* @0x13a3a0 pop {r4, lr} */
/* @0x13a3a4 add r0, pc, r0 */
/* @0x13a3a8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13a3ac mov r0, r2 */
/* @0x13a3b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a3b4 bl 0x213528 <_Z7LoadCSVPc> */
/* @0x13a3b8 vmov s15, r0 */
/* @0x13a3bc vcvt.f64.s32 d7, s15 */
/* @0x13a3c0 vmov r0, r1, d7 */
/* @0x13a3c4 vmov r2, s14 */
/* @0x13a3c8 mov r3, r1 */
/* @0x13a3cc stm r4, {r2, r3} */
/* @0x13a3d0 pop {r4, pc} */
/* @0x13a3d4 eoreq r5, r0, r0, lsl pc */

/* ── FUNC 0x13a3d8 · F_FileTextSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=484 · insn=121 */
/* @0x13a3d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13a3dc sub sp, sp, #20 */
/* @0x13a3e0 mov r1, #0 */
/* @0x13a3e4 mov r5, r0 */
/* @0x13a3e8 ldr r7, [sp, #0x38] */
/* @0x13a3ec mov r3, r1 */
/* @0x13a3f0 str r1, [r0, #0xc] */
/* @0x13a3f4 movt r3, #0xbff0 */
/* @0x13a3f8 stm r0, {r1, r3} */
/* @0x13a3fc mov r4, #1 */
/* @0x13a400 mov r0, r7 */
/* @0x13a404 ldr r6, [pc, #0x18c] */
/* @0x13a408 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a40c ldr r3, [pc, #0x188] */
/* @0x13a410 add r6, pc, r6 */
/* @0x13a414 ldr r3, [r6, r3] */
/* @0x13a418 str r3, [sp, #0x8] */
/* @0x13a41c mov r9, r0 */
/* @0x13a420 b 0x13a430 <_Z13F_FileTextSetR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x13a424 add r4, r4, #1 */
/* @0x13a428 cmp r4, #32 */
/* @0x13a42c beq 0x13a580 <_Z13F_FileTextSetR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x13a430 ldr r11, [r3, #0x4]! */
/* @0x13a434 cmp r11, #0 */
/* @0x13a438 bne 0x13a424 <_Z13F_FileTextSetR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x13a43c ldr r2, [pc, #0x15c] */
/* @0x13a440 lsl r10, r4, #1 */
/* @0x13a444 add r3, r10, r4 */
/* @0x13a448 ldr r8, [r6, r2] */
/* @0x13a44c lsl r3, r3, #2 */
/* @0x13a450 ldr r0, [r8, r3] */
/* @0x13a454 cmp r0, #0 */
/* @0x13a458 beq 0x13a46c <_Z13F_FileTextSetR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x13a45c str r3, [sp, #0x4] */
/* @0x13a460 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13a464 ldr r3, [sp, #0x4] */
/* @0x13a468 str r11, [r8, r3] */
/* @0x13a46c ldr r7, [r7, #0xc] */
/* @0x13a470 cmp r7, #1 */
/* @0x13a474 beq 0x13a4a0 <_Z13F_FileTextSetR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x13a478 ldr r3, [pc, #0x124] */
/* @0x13a47c ldr r1, [pc, #0x124] */
/* @0x13a480 ldr r3, [r6, r3] */
/* @0x13a484 add r1, pc, r1 */
/* @0x13a488 ldr r0, [r3] */
/* @0x13a48c ldr r3, [r0] */
/* @0x13a490 ldr r3, [r3, #0xc] */
/* @0x13a494 blx r3 */
/* @0x13a498 add sp, sp, #20 */
/* @0x13a49c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13a4a0 mov r0, #16 */
/* @0x13a4a4 bl 0x27c524 <_Znwj> */
/* @0x13a4a8 mov r11, r0 */
/* @0x13a4ac mov r0, r9 */
/* @0x13a4b0 bl 0xb6538 <strlen@plt> */
/* @0x13a4b4 str r0, [sp, #0xc] */
/* @0x13a4b8 mov r0, #64 */
/* @0x13a4bc bl 0x27c524 <_Znwj> */
/* @0x13a4c0 ldr r1, [sp, #0xc] */
/* @0x13a4c4 mov r2, r7 */
/* @0x13a4c8 mov r3, r7 */
/* @0x13a4cc str r0, [sp, #0x4] */
/* @0x13a4d0 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati> */
/* @0x13a4d4 ldr r3, [pc, #0xd0] */
/* @0x13a4d8 mov r1, r9 */
/* @0x13a4dc ldr r12, [sp, #0x4] */
/* @0x13a4e0 ldr r2, [sp, #0xc] */
/* @0x13a4e4 ldr r3, [r6, r3] */
/* @0x13a4e8 add r6, r10, r4 */
/* @0x13a4ec ldr r0, [r12, #0xc] */
/* @0x13a4f0 add r3, r3, #8 */
/* @0x13a4f4 lsl r6, r6, #2 */
/* @0x13a4f8 str r3, [r12] */
/* @0x13a4fc str r12, [r11] */
/* @0x13a500 bl 0xb65bc <memcpy@plt> */
/* @0x13a504 add r12, r8, r6 */
/* @0x13a508 ldr r1, [pc, #0xa0] */
/* @0x13a50c mov r3, #0 */
/* @0x13a510 movw r2, #0x2ee */
/* @0x13a514 str r3, [r11, #0x8] */
/* @0x13a518 add r1, pc, r1 */
/* @0x13a51c mov r3, r7 */
/* @0x13a520 str r11, [r12, #0x8] */
/* @0x13a524 mov r0, #15 */
/* @0x13a528 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13a52c vmov s15, r4 */
/* @0x13a530 ldr r3, [pc, #0x7c] */
/* @0x13a534 vcvt.f64.s32 d7, s15 */
/* @0x13a538 add r3, pc, r3 */
/* @0x13a53c vmov r10, r11, d7 */
/* @0x13a540 str r0, [r8, r6] */
/* @0x13a544 mov r12, r0 */
/* @0x13a548 ldm r3!, {r0, r1, r2} */
/* @0x13a54c ldrh r9, [r3] */
/* @0x13a550 ldrb r3, [r3, #0x2] */
/* @0x13a554 str r0, [r12] */
/* @0x13a558 str r1, [r12, #0x4] */
/* @0x13a55c strb r3, [r12, #0xe] */
/* @0x13a560 ldr r3, [sp, #0x8] */
/* @0x13a564 str r2, [r12, #0x8] */
/* @0x13a568 strh r9, [r12, #12] */
/* @0x13a56c str r7, [r3, r4, lsl #2] */
/* @0x13a570 vstr s14, [r5] */
/* @0x13a574 str r11, [r5, #0x4] */
/* @0x13a578 add sp, sp, #20 */
/* @0x13a57c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13a580 ldr r0, [pc, #0x30] */
/* @0x13a584 mov r1, #0 */
/* @0x13a588 add r0, pc, r0 */
/* @0x13a58c add sp, sp, #20 */
/* @0x13a590 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13a594 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13a598 eoreq r7, r11, r0, asr #16 */
/* @0x13a59c .word 0xffffd620 */
/* @0x13a5a0 .word 0xffffd624 */
/* @0x13a5a4 .word 0xffffbac4 */
/* @0x13a5a8 eoreq r5, r0, r12, asr lr */
/* @0x13a5ac .word 0xffffbd60 */
/* @0x13a5b0 eoreq r5, r0, r8, lsr r11 */
/* @0x13a5b4 .word 0x00205dd0 */
/* @0x13a5b8 eoreq r5, r0, r8, ror r10 */

/* ── FUNC 0x13a5bc · F_HttpRequest(RValue&, CInstance*, CInstance*, int, RValue*) · size=1264 · insn=316 */
/* @0x13a5bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13a5c0 sub sp, sp, #100 */
/* @0x13a5c4 ldr r7, [pc, #0x4ac] */
/* @0x13a5c8 mov r1, #0 */
/* @0x13a5cc ldr r3, [pc, #0x4a8] */
/* @0x13a5d0 mov r5, #1 */
/* @0x13a5d4 add r7, pc, r7 */
/* @0x13a5d8 ldr r4, [sp, #0x88] */
/* @0x13a5dc str r7, [sp, #0x1c] */
/* @0x13a5e0 str r0, [sp, #0x18] */
/* @0x13a5e4 ldr r3, [r7, r3] */
/* @0x13a5e8 mov r0, r4 */
/* @0x13a5ec strb r5, [r3] */
/* @0x13a5f0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a5f4 mov r1, r5 */
/* @0x13a5f8 str r0, [sp, #0x20] */
/* @0x13a5fc mov r0, r4 */
/* @0x13a600 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13a604 mov r1, #2 */
/* @0x13a608 str r0, [sp, #0x30] */
/* @0x13a60c mov r0, r4 */
/* @0x13a610 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13a614 ldr r3, [r4, #0x3c] */
/* @0x13a618 bic r3, r3, #-16777216 */
/* @0x13a61c cmp r3, r5 */
/* @0x13a620 mov r8, r0 */
/* @0x13a624 beq 0x13a9b0 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x3f4> */
/* @0x13a628 mov r0, r4 */
/* @0x13a62c mov r1, #3 */
/* @0x13a630 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13a634 mov r12, #0 */
/* @0x13a638 str r12, [sp, #0x2c] */
/* @0x13a63c str r0, [sp, #0x34] */
/* @0x13a640 add r12, sp, #56 */
/* @0x13a644 str r12, [sp, #0x24] */
/* @0x13a648 mov r2, #0 */
/* @0x13a64c add r7, sp, #60 */
/* @0x13a650 mov r0, r12 */
/* @0x13a654 ldr r12, [sp, #0x18] */
/* @0x13a658 mov r3, r2 */
/* @0x13a65c movt r2, #0xbff0 */
/* @0x13a660 str r7, [sp, #0x10] */
/* @0x13a664 lsl r10, r8, #2 */
/* @0x13a668 str r3, [r12, #0xc] */
/* @0x13a66c str r3, [r12] */
/* @0x13a670 str r2, [r12, #0x4] */
/* @0x13a674 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x13a678 add r0, sp, #60 */
/* @0x13a67c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x13a680 ldr r3, [pc, #0x3f8] */
/* @0x13a684 ldr r7, [sp, #0x1c] */
/* @0x13a688 ldr r6, [r7, r3] */
/* @0x13a68c ldr r3, [r6, #0x4] */
/* @0x13a690 ldr r0, [r3, r8, lsl #2] */
/* @0x13a694 bl 0x203c8c <_ZN7CDS_Map9FindFirstEv> */
/* @0x13a698 subs r3, r0, #0 */
/* @0x13a69c beq 0x13aa68 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x4ac> */
/* @0x13a6a0 ldr r9, [pc, #0x3dc] */
/* @0x13a6a4 mvn r12, #0 */
/* @0x13a6a8 add r4, sp, #64 */
/* @0x13a6ac add r7, sp, #80 */
/* @0x13a6b0 add r9, pc, r9 */
/* @0x13a6b4 mov r5, #1 */
/* @0x13a6b8 str r12, [sp, #0x28] */
/* @0x13a6bc str r8, [sp, #0x14] */
/* @0x13a6c0 b 0x13a710 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x13a6c4 cmp r3, #1 */
/* @0x13a6c8 movne r11, #0 */
/* @0x13a6cc beq 0x13a784 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x13a6d0 cmp lr, #1 */
/* @0x13a6d4 beq 0x13a798 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x13a6d8 mov r0, r8 */
/* @0x13a6dc bl 0xb6538 <strlen@plt> */
/* @0x13a6e0 mov r8, r0 */
/* @0x13a6e4 mov r0, r11 */
/* @0x13a6e8 bl 0xb6538 <strlen@plt> */
/* @0x13a6ec ldr r2, [r6, #0x4] */
/* @0x13a6f0 mov r1, r4 */
/* @0x13a6f4 add r3, r8, r0 */
/* @0x13a6f8 ldr r0, [r2, r10] */
/* @0x13a6fc add r3, r3, #4 */
/* @0x13a700 add r5, r5, r3 */
/* @0x13a704 bl 0x203b94 <_ZN7CDS_Map8FindNextEP6RValue> */
/* @0x13a708 subs r3, r0, #0 */
/* @0x13a70c beq 0x13a7bc <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x200> */
/* @0x13a710 ldr r0, [r3] */
/* @0x13a714 mov r11, r3 */
/* @0x13a718 ldr r1, [r3, #0x4] */
/* @0x13a71c mov lr, r4 */
/* @0x13a720 ldr r2, [r3, #0x8] */
/* @0x13a724 mov r12, r7 */
/* @0x13a728 ldr r3, [r3, #0xc] */
/* @0x13a72c stm lr!, {r0, r1, r2, r3} */
/* @0x13a730 ldr lr, [sp, #0x4c] */
/* @0x13a734 bic lr, lr, #-16777216 */
/* @0x13a738 str lr, [sp, #0x4c] */
/* @0x13a73c ldr r0, [r11, #0x10]! */
/* @0x13a740 cmp lr, #1 */
/* @0x13a744 movne r8, #0 */
/* @0x13a748 ldr r3, [r11, #0xc] */
/* @0x13a74c ldr r1, [r11, #0x4] */
/* @0x13a750 ldr r2, [r11, #0x8] */
/* @0x13a754 stm r12!, {r0, r1, r2, r3} */
/* @0x13a758 ldr r3, [sp, #0x5c] */
/* @0x13a75c bic r3, r3, #-16777216 */
/* @0x13a760 str r3, [sp, #0x5c] */
/* @0x13a764 bne 0x13a6c4 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x13a768 ldr r2, [sp, #0x40] */
/* @0x13a76c cmp r2, #0 */
/* @0x13a770 ldrne r8, [r2] */
/* @0x13a774 moveq r8, r2 */
/* @0x13a778 cmp r3, #1 */
/* @0x13a77c movne r11, #0 */
/* @0x13a780 bne 0x13a6d0 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x13a784 ldr r11, [sp, #0x50] */
/* @0x13a788 cmp r11, #0 */
/* @0x13a78c ldrne r11, [r11] */
/* @0x13a790 cmp lr, #1 */
/* @0x13a794 bne 0x13a6d8 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x13a798 mov r0, r9 */
/* @0x13a79c mov r1, r8 */
/* @0x13a7a0 bl 0xb6574 <strcmp@plt> */
/* @0x13a7a4 cmp r0, #0 */
/* @0x13a7a8 bne 0x13a6d8 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x13a7ac mov r0, r11 */
/* @0x13a7b0 bl 0xb66b8 <atoi@plt> */
/* @0x13a7b4 str r0, [sp, #0x28] */
/* @0x13a7b8 b 0x13a6d8 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x13a7bc ldr r8, [sp, #0x14] */
/* @0x13a7c0 add r0, sp, #60 */
/* @0x13a7c4 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x13a7c8 ldr r1, [pc, #0x2b8] */
/* @0x13a7cc mov r0, r5 */
/* @0x13a7d0 movw r2, #0x8c6 */
/* @0x13a7d4 add r1, pc, r1 */
/* @0x13a7d8 mov r3, #1 */
/* @0x13a7dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13a7e0 mov r3, #0 */
/* @0x13a7e4 strb r3, [r0] */
/* @0x13a7e8 mov r5, r0 */
/* @0x13a7ec ldr r3, [r6, #0x4] */
/* @0x13a7f0 ldr r0, [r3, r8, lsl #2] */
/* @0x13a7f4 bl 0x203c8c <_ZN7CDS_Map9FindFirstEv> */
/* @0x13a7f8 subs r3, r0, #0 */
/* @0x13a7fc beq 0x13a8fc <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x340> */
/* @0x13a800 ldr r8, [pc, #0x284] */
/* @0x13a804 add r4, sp, #64 */
/* @0x13a808 ldr r9, [pc, #0x280] */
/* @0x13a80c add r7, sp, #80 */
/* @0x13a810 ldr r12, [pc, #0x27c] */
/* @0x13a814 add r8, pc, r8 */
/* @0x13a818 add r9, pc, r9 */
/* @0x13a81c str r8, [sp, #0x10] */
/* @0x13a820 add r12, pc, r12 */
/* @0x13a824 str r12, [sp, #0x14] */
/* @0x13a828 b 0x13a878 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x2bc> */
/* @0x13a82c cmp r3, #1 */
/* @0x13a830 movne r11, #0 */
/* @0x13a834 beq 0x13a8ec <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x330> */
/* @0x13a838 mov r0, r5 */
/* @0x13a83c bl 0xb6538 <strlen@plt> */
/* @0x13a840 ldr r12, [sp, #0x14] */
/* @0x13a844 mov r2, r8 */
/* @0x13a848 ldr r1, [sp, #0x10] */
/* @0x13a84c mov r3, r9 */
/* @0x13a850 str r11, [sp] */
/* @0x13a854 str r12, [sp, #0x4] */
/* @0x13a858 add r0, r5, r0 */
/* @0x13a85c bl 0xb6550 <sprintf@plt> */
/* @0x13a860 ldr r3, [r6, #0x4] */
/* @0x13a864 mov r1, r4 */
/* @0x13a868 ldr r0, [r3, r10] */
/* @0x13a86c bl 0x203b94 <_ZN7CDS_Map8FindNextEP6RValue> */
/* @0x13a870 subs r3, r0, #0 */
/* @0x13a874 beq 0x13a8fc <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x340> */
/* @0x13a878 ldr r0, [r3] */
/* @0x13a87c mov r11, r3 */
/* @0x13a880 ldr r1, [r3, #0x4] */
/* @0x13a884 mov lr, r4 */
/* @0x13a888 ldr r2, [r3, #0x8] */
/* @0x13a88c mov r12, r7 */
/* @0x13a890 ldr r3, [r3, #0xc] */
/* @0x13a894 stm lr!, {r0, r1, r2, r3} */
/* @0x13a898 ldr r3, [sp, #0x4c] */
/* @0x13a89c bic r3, r3, #-16777216 */
/* @0x13a8a0 str r3, [sp, #0x4c] */
/* @0x13a8a4 ldr r0, [r11, #0x10]! */
/* @0x13a8a8 cmp r3, #1 */
/* @0x13a8ac movne r8, #0 */
/* @0x13a8b0 ldr r3, [r11, #0xc] */
/* @0x13a8b4 ldr r1, [r11, #0x4] */
/* @0x13a8b8 ldr r2, [r11, #0x8] */
/* @0x13a8bc stm r12!, {r0, r1, r2, r3} */
/* @0x13a8c0 ldr r3, [sp, #0x5c] */
/* @0x13a8c4 bic r3, r3, #-16777216 */
/* @0x13a8c8 str r3, [sp, #0x5c] */
/* @0x13a8cc bne 0x13a82c <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x270> */
/* @0x13a8d0 ldr r2, [sp, #0x40] */
/* @0x13a8d4 cmp r2, #0 */
/* @0x13a8d8 ldrne r8, [r2] */
/* @0x13a8dc moveq r8, r2 */
/* @0x13a8e0 cmp r3, #1 */
/* @0x13a8e4 movne r11, #0 */
/* @0x13a8e8 bne 0x13a838 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x27c> */
/* @0x13a8ec ldr r11, [sp, #0x50] */
/* @0x13a8f0 cmp r11, #0 */
/* @0x13a8f4 ldrne r11, [r11] */
/* @0x13a8f8 b 0x13a838 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x27c> */
/* @0x13a8fc add r0, sp, #56 */
/* @0x13a900 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x13a904 ldr r0, [pc, #0x18c] */
/* @0x13a908 ldr r1, [sp, #0x20] */
/* @0x13a90c mov r2, #7 */
/* @0x13a910 add r0, pc, r0 */
/* @0x13a914 bl 0xb65e0 <strncmp@plt> */
/* @0x13a918 cmp r0, #0 */
/* @0x13a91c beq 0x13a93c <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x380> */
/* @0x13a920 ldr r0, [pc, #0x174] */
/* @0x13a924 mov r2, #8 */
/* @0x13a928 ldr r1, [sp, #0x20] */
/* @0x13a92c add r0, pc, r0 */
/* @0x13a930 bl 0xb65e0 <strncmp@plt> */
/* @0x13a934 cmp r0, #0 */
/* @0x13a938 bne 0x13a9a8 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x3ec> */
/* @0x13a93c ldr r3, [pc, #0x15c] */
/* @0x13a940 ldr r8, [sp, #0x1c] */
/* @0x13a944 ldr r7, [sp, #0x2c] */
/* @0x13a948 ldr r3, [r8, r3] */
/* @0x13a94c cmp r7, #0 */
/* @0x13a950 ldr r4, [r3] */
/* @0x13a954 beq 0x13a9d8 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x41c> */
/* @0x13a958 ldr r2, [pc, #0x144] */
/* @0x13a95c mov r12, #0 */
/* @0x13a960 mvn lr, #0 */
/* @0x13a964 ldr r0, [sp, #0x20] */
/* @0x13a968 ldr r1, [sp, #0x30] */
/* @0x13a96c mov r3, r7 */
/* @0x13a970 ldr r6, [r8, r2] */
/* @0x13a974 mov r2, r5 */
/* @0x13a978 str r12, [sp, #0x4] */
/* @0x13a97c str r12, [sp, #0x8] */
/* @0x13a980 str r6, [sp] */
/* @0x13a984 str lr, [sp, #0xc] */
/* @0x13a988 bl 0x18fdb8 <_ZN8LoadSave12HTTP_RequestEPKcS1_S1_S1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_i> */
/* @0x13a98c mov r0, r5 */
/* @0x13a990 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13a994 vmov s15, r4 */
/* @0x13a998 ldr r7, [sp, #0x18] */
/* @0x13a99c vcvt.f64.s32 d7, s15 */
/* @0x13a9a0 vmov r2, r3, d7 */
/* @0x13a9a4 stm r7, {r2, r3} */
/* @0x13a9a8 add sp, sp, #100 */
/* @0x13a9ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13a9b0 ldr r3, [r4, #0x30] */
/* @0x13a9b4 cmp r3, #0 */
/* @0x13a9b8 beq 0x13a628 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x13a9bc ldr r3, [r3] */
/* @0x13a9c0 cmp r3, #0 */
/* @0x13a9c4 strne r3, [sp, #0x2c] */
/* @0x13a9c8 mvnne r7, #0 */
/* @0x13a9cc strne r7, [sp, #0x34] */
/* @0x13a9d0 bne 0x13a640 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x13a9d4 b 0x13a628 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x13a9d8 ldr r0, [sp, #0x34] */
/* @0x13a9dc bl 0xc6720 <_Z10GetIBufferi> */
/* @0x13a9e0 subs r12, r0, #0 */
/* @0x13a9e4 beq 0x13aa30 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x474> */
/* @0x13a9e8 ldr r3, [r12, #0x1c] */
/* @0x13a9ec cmp r3, #0 */
/* @0x13a9f0 beq 0x13aa30 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x474> */
/* @0x13a9f4 ldr r8, [sp, #0x1c] */
/* @0x13a9f8 mov r2, r5 */
/* @0x13a9fc ldr lr, [pc, #0xa0] */
/* @0x13aa00 ldr r3, [r12, #0xc] */
/* @0x13aa04 ldr r7, [sp, #0x2c] */
/* @0x13aa08 ldr r12, [r8, lr] */
/* @0x13aa0c ldr r8, [sp, #0x28] */
/* @0x13aa10 ldr r0, [sp, #0x20] */
/* @0x13aa14 ldr r1, [sp, #0x30] */
/* @0x13aa18 str r7, [sp, #0x4] */
/* @0x13aa1c str r7, [sp, #0x8] */
/* @0x13aa20 str r12, [sp] */
/* @0x13aa24 str r8, [sp, #0xc] */
/* @0x13aa28 bl 0x18fdb8 <_ZN8LoadSave12HTTP_RequestEPKcS1_S1_S1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_i> */
/* @0x13aa2c b 0x13a98c <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x3d0> */
/* @0x13aa30 ldr r2, [pc, #0x70] */
/* @0x13aa34 mov lr, #0 */
/* @0x13aa38 ldr r8, [sp, #0x1c] */
/* @0x13aa3c mvn r6, #0 */
/* @0x13aa40 ldr r0, [sp, #0x20] */
/* @0x13aa44 mov r3, lr */
/* @0x13aa48 ldr r1, [sp, #0x30] */
/* @0x13aa4c ldr r7, [r8, r2] */
/* @0x13aa50 mov r2, r5 */
/* @0x13aa54 str r12, [sp, #0x8] */
/* @0x13aa58 str r6, [sp, #0xc] */
/* @0x13aa5c stm sp, {r7, lr} */
/* @0x13aa60 bl 0x18fdb8 <_ZN8LoadSave12HTTP_RequestEPKcS1_S1_S1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_i> */
/* @0x13aa64 b 0x13a98c <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x3d0> */
/* @0x13aa68 mvn r7, #0 */
/* @0x13aa6c mov r5, #1 */
/* @0x13aa70 str r7, [sp, #0x28] */
/* @0x13aa74 b 0x13a7c0 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x13aa78 eoreq r7, r11, r12, ror r6 */
/* @0x13aa7c .word 0xffffbd04 */
/* @0x13aa80 .word 0xffffbcec */
/* @0x13aa84 eoreq r5, r0, r8, ror #24 */
/* @0x13aa88 eoreq r5, r0, r12, ror r8 */
/* @0x13aa8c eoreq r5, r0, r4, lsl r11 */
/* @0x13aa90 eoreq r5, r0, r12, lsl r11 */
/* @0x13aa94 eoreq r5, r0, r8, lsl r11 */
/* @0x13aa98 ldrsbeq r6, [pc], -r0 */
/* @0x13aa9c ldrheq r6, [pc], -r12 */
/* @0x13aaa0 .word 0xffffd628 */
/* @0x13aaa4 .word 0xffffd62c */
/* @0x13aaa8 .word 0xffffd648 */

/* ── FUNC 0x13aaac · yyFindData::yyFindData() · size=20 · insn=5 */
/* @0x13aaac mov r2, #0 */
/* @0x13aab0 str r2, [r0] */
/* @0x13aab4 str r2, [r0, #0x4] */
/* @0x13aab8 str r2, [r0, #0x8] */
/* @0x13aabc bx lr */

/* ── FUNC 0x13aaac · yyFindData::yyFindData() · alias of the symbol above · insn=0 */
