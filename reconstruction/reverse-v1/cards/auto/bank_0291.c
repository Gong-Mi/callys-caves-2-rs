/* libyoyo.so 覆盖卡组 0291
 * 函数 0x2e8376..0x2e9716，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e8376 · FT_CMap_New · size=148 · insn=66 */
/* @0x2e8376 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e837a sub sp, #0x14 */
/* @0x2e837c mov r8, r3 */
/* @0x2e837e mov r11, r1 */
/* @0x2e8380 movs r3, #0x0 */
/* @0x2e8382 mov r6, r2 */
/* @0x2e8384 str r3, [sp, #0xc] */
/* @0x2e8386 mov r7, r0 */
/* @0x2e8388 cmp r0, #0x0 */
/* @0x2e838a beq 0x2e8402 <FT_CMap_New+0x8c> */
/* @0x2e838c cmp r2, #0x0 */
/* @0x2e838e beq 0x2e8402 <FT_CMap_New+0x8c> */
/* @0x2e8390 ldr r5, [r2] */
/* @0x2e8392 cmp r5, #0x0 */
/* @0x2e8394 beq 0x2e8402 <FT_CMap_New+0x8c> */
/* @0x2e8396 ldr.w r9, [r5, #0x64] */
/* @0x2e839a add.w r10, sp, #0xc */
/* @0x2e839e ldr r1, [r7] */
/* @0x2e83a0 mov r2, r10 */
/* @0x2e83a2 mov r0, r9 */
/* @0x2e83a4 bl 0x2e7126 <ft_mem_alloc> */
/* @0x2e83a6 blls 0x3e7eaa <error_g0017+0x40b4e> */
/* @0x2e83a8 ldr r3, [sp, #0xc] */
/* @0x2e83aa mov r4, r0 */
/* @0x2e83ac cbnz r3, 0x2e83f4 <FT_CMap_New+0x7e> */
/* @0x2e83ae ldm.w r6, {r0, r1, r2} */
/* @0x2e83b2 str r7, [r4, #0xc] */
/* @0x2e83b4 stm.w r4, {r0, r1, r2} */
/* @0x2e83b6 ldmdavs r11!, {r0, r1, r2} ^ */
/* @0x2e83b8 ldr r3, [r7, #0x4] */
/* @0x2e83ba cbnz r3, 0x2e83e0 <FT_CMap_New+0x6a> */
/* @0x2e83bc ldr r3, [r5, #0x28] */
/* @0x2e83be mov r0, r9 */
/* @0x2e83c0 ldr r2, [r5, #0x24] */
/* @0x2e83c2 movs r1, #0x4 */
/* @0x2e83c4 stm.w sp, {r3, r10} */
/* @0x2e83c6 mrrcne p4, #0x0, r0, r3, c8 */
/* @0x2e83c8 adds r3, r2, #0x1 */
/* @0x2e83ca bl 0x2e808e <ft_mem_realloc> */
/* @0x2e83ce ldr r3, [sp, #0xc] */
/* @0x2e83d0 str r0, [r5, #0x28] */
/* @0x2e83d2 cbnz r3, 0x2e83ec <FT_CMap_New+0x76> */
/* @0x2e83d4 ldr r3, [r5, #0x24] */
/* @0x2e83d6 adds r2, r3, #0x1 */
/* @0x2e83d8 str r2, [r5, #0x24] */
/* @0x2e83da str.w r4, [r0, r3, lsl #2] */
/* @0x2e83de b 0x2e83f4 <FT_CMap_New+0x7e> */
/* @0x2e83e0 mov r0, r4 */
/* @0x2e83e2 mov r1, r11 */
/* @0x2e83e4 blx r3 */
/* @0x2e83e6 str r0, [sp, #0xc] */
/* @0x2e83e8 cmp r0, #0x0 */
/* @0x2e83ea beq 0x2e83bc <FT_CMap_New+0x46> */
/* @0x2e83ec mov r0, r4 */
/* @0x2e83ee movs r4, #0x0 */
/* @0x2e83f0 bl 0x2e7b5c <FT_Done_GlyphSlot+0x42> */
/* @0x2e83f2 .word 0xf1b8fbb4 */
/* @0x2e83f4 cmp.w r8, #0x0 */
/* @0x2e83f6 andle r0, r1, r0, lsl #30 */
/* @0x2e83f8 beq 0x2e83fe <FT_CMap_New+0x88> */
/* @0x2e83fa str.w r4, [r8] */
/* @0x2e83fe ldr r0, [sp, #0xc] */
/* @0x2e8400 b 0x2e8404 <FT_CMap_New+0x8e> */
/* @0x2e8402 movs r0, #0x6 */
/* @0x2e8404 add sp, #0x14 */
/* @0x2e8406 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2e840a · FT_Outline_New_Internal · size=156 · insn=68 */
/* @0x2e840a push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr} */
/* @0x2e840e mov r5, r0 */
/* @0x2e8410 mov r6, r1 */
/* @0x2e8412 mov r7, r2 */
/* @0x2e8414 mov r4, r3 */
/* @0x2e8416 cbnz r3, 0x2e841c <FT_Outline_New_Internal+0x12> */
/* @0x2e8418 movs r0, #0x6 */
/* @0x2e841a b 0x2e84a0 <FT_Outline_New_Internal+0x96> */
/* @0x2e841c cmp r0, #0x0 */
/* @0x2e841e beq 0x2e8418 <FT_Outline_New_Internal+0xe> */
/* @0x2e8420 mov r0, r3 */
/* @0x2e8422 movs r1, #0x0 */
/* @0x2e8424 movs r2, #0x14 */
/* @0x2e8426 blx 0xb65b0 <memset@plt> */
/* @0x2e842a cmp r7, #0x0 */
/* @0x2e842c blt 0x2e8418 <FT_Outline_New_Internal+0xe> */
/* @0x2e842e cmp r7, r6 */
/* @0x2e8430 bhi 0x2e8418 <FT_Outline_New_Internal+0xe> */
/* @0x2e8432 cmp.w r6, #0x8000 */
/* @0x2e8436 bhs 0x2e849e <FT_Outline_New_Internal+0x94> */
/* @0x2e8438 movs r2, #0x0 */
/* @0x2e843a add.w r8, sp, #0xc */
/* @0x2e843e str r2, [sp] */
/* @0x2e8440 mov r0, r5 */
/* @0x2e8442 str.w r8, [sp, #0x4] */
/* @0x2e8446 movs r1, #0x8 */
/* @0x2e8448 mov r3, r6 */
/* @0x2e844a bl 0x2e808e <ft_mem_realloc> */
/* @0x2e844e ldr r2, [sp, #0xc] */
/* @0x2e8450 str r0, [r4, #0x4] */
/* @0x2e8452 cbnz r2, 0x2e848a <FT_Outline_New_Internal+0x80> */
/* @0x2e8454 stm.w sp, {r2, r8} */
/* @0x2e8456 strtmi r0, [r8], -r4, lsl #2 */
/* @0x2e8458 mov r0, r5 */
/* @0x2e845a movs r1, #0x1 */
/* @0x2e845c mov r3, r6 */
/* @0x2e845e bl 0x2e808e <ft_mem_realloc> */
/* @0x2e8462 ldr r2, [sp, #0xc] */
/* @0x2e8464 str r0, [r4, #0x8] */
/* @0x2e8466 cbnz r2, 0x2e848a <FT_Outline_New_Internal+0x80> */
/* @0x2e8468 stm.w sp, {r2, r8} */
/* @0x2e846a strtmi r0, [r8], -r4, lsl #2 */
/* @0x2e846c mov r0, r5 */
/* @0x2e846e movs r1, #0x2 */
/* @0x2e8470 mov r3, r7 */
/* @0x2e8472 bl 0x2e808e <ft_mem_realloc> */
/* @0x2e8476 str r0, [r4, #0xc] */
/* @0x2e8478 ldr r0, [sp, #0xc] */
/* @0x2e847a cbnz r0, 0x2e848a <FT_Outline_New_Internal+0x80> */
/* @0x2e847c ldr r3, [r4, #0x10] */
/* @0x2e847e strh r6, [r4, #0x2] */
/* @0x2e8480 orr r3, r3, #0x1 */
/* @0x2e8482 eorhi r0, r7, r1, lsl #6 */
/* @0x2e8484 strh r7, [r4] */
/* @0x2e8486 str r3, [r4, #0x10] */
/* @0x2e8488 b 0x2e84a0 <FT_Outline_New_Internal+0x96> */
/* @0x2e848a ldr r3, [r4, #0x10] */
/* @0x2e848c mov r0, r5 */
/* @0x2e848e mov r1, r4 */
/* @0x2e8490 orr r3, r3, #0x1 */
/* @0x2e8492 .word 0x61230301 */
/* @0x2e8494 str r3, [r4, #0x10] */
/* @0x2e8496 bl 0x2e7dba <FT_Outline_Done_Internal> */
/* @0x2e849a ldr r0, [sp, #0xc] */
/* @0x2e849c b 0x2e84a0 <FT_Outline_New_Internal+0x96> */
/* @0x2e849e movs r0, #0xa */
/* @0x2e84a0 add sp, #0x10 */
/* @0x2e84a2 pop.w {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2e84a6 · FT_Outline_New · size=12 · insn=5 */
/* @0x2e84a6 cbz r0, 0x2e84ae <FT_Outline_New+0x8> */
/* @0x2e84a8 ldr r0, [r0] */
/* @0x2e84aa b.w 0x2e840a <FT_Outline_New_Internal> */
/* @0x2e84ae movs r0, #0x21 */
/* @0x2e84b0 bx lr */

/* ── FUNC 0x2e84b2 · anon_2e84b2 · size=0 · insn=1 */
/* @0x2e84b2 ldrlt r0, [pc, #-0x0] */

/* ── FUNC 0x2e84b4 · ft_hash_num_init · size=60 · insn=29 */
/* @0x2e84b4 push {r0, r1, r2, r3, r4, lr} */
/* @0x2e84b6 mov r4, r0 */
/* @0x2e84b8 movs r3, #0xf1 */
/* @0x2e84ba movs r2, #0x50 */
/* @0x2e84bc stm.w r0, {r2, r3} */
/* @0x2e84c0 movs r2, #0x0 */
/* @0x2e84c2 str r2, [r0, #0x8] */
/* @0x2e84c4 ldr r0, [pc, #0x20] */
/* @0x2e84c6 str r2, [sp] */
/* @0x2e84c8 add r0, pc */
/* @0x2e84ca str r0, [r4, #0xc] */
/* @0x2e84cc ldr r0, [pc, #0x1c] */
/* @0x2e84ce add r0, pc */
/* @0x2e84d0 str r0, [r4, #0x10] */
/* @0x2e84d2 add r0, sp, #0xc */
/* @0x2e84d4 str r0, [sp, #0x4] */
/* @0x2e84d6 mov r0, r1 */
/* @0x2e84d8 movs r1, #0x4 */
/* @0x2e84da bl 0x2e808e <ft_mem_realloc> */
/* @0x2e84dc .word 0x6160fdd8 */
/* @0x2e84de str r0, [r4, #0x14] */
/* @0x2e84e0 ldr r0, [sp, #0xc] */
/* @0x2e84e2 add sp, #0x10 */
/* @0x2e84e4 pop {r4, pc} */
/* @0x2e84e6 nop */
/* @0x2e84e8 stm r4!, {r0, r1, r2, r3, r4, r5, r7} */
/* @0x2e84ea .word 0xffff c4db */
/* @0x2e84ec .word 0xffffc4db */
/* @0x2e84ee vtbl.8 d30, {d15, d16}, d29 */

/* ── FUNC 0x2e84f0 · anon_2e84f0 · size=180 · insn=46 */
/* @0x2e84f0 ldrbmi lr, [pc, sp, lsr #18]! */
/* @0x2e84f4 ldrmi r4, [r1], -pc, lsl #12 */
/* @0x2e84f8 pkhbtmi r4, r1, lr, lsl #12 */
/* @0x2e84fc .word 0xf7fc4614 */
/* @0x2e8500 movwhs pc, #0xa5b */
/* @0x2e8504 stmdavs r3, {r1, r8, r9, r12, pc} */
/* @0x2e8508 blhs 0x2f9f10 <ps_hints_apply+0x8b10> */
/* @0x2e850c .word 0x2108d147 */
/* @0x2e8510 bl 0x639dd8 <g_SWFaavertbuff+0x66d10> */
/* @0x2e8514 .word 0xf7fe0201 */
/* @0x2e8518 stcls p14, c15, [r2, #-24] */
/* @0x2e851c teqle pc, r0, lsl #26 */
/* @0x2e8520 andeq pc, r0, r8, asr #17 */
/* @0x2e8524 andls pc, r0, r0, asr #17 */
/* @0x2e8528 stmvs r2!, {r0, r1, r2, r6, sp, lr} */
/* @0x2e852c addsmi r6, r10, #2293760 */
/* @0x2e8530 stmvs r3!, {r0, r1, r9, r12, lr, pc} */
/* @0x2e8534 adcvs r3, r3, r1, lsl #6 */
/* @0x2e8538 .word 0xf8d4e032 */
/* @0x2e853c .word 0xf10d9004 */
/* @0x2e8540 .word 0x21030a10 */
/* @0x2e8544 ldrsbhi pc, [r4], -r4 */
/* @0x2e8548 stcpl p8, c15, [r4, #-296] */
/* @0x2e854c strbeq lr, [r9, -pc, asr #20] */
/* @0x2e8550 ldrtmi r6, [r8], -r7, rrx */
/* @0x2e8554 bl 0x212461c <b2_toiTime+0x19cb178> */
/* @0x2e8558 strteq lr, [r0], #-2189 */
/* @0x2e855c .word 0x2104462a */
/* @0x2e8560 eorvs r4, r0, r11, lsr r6 */
/* @0x2e8564 .word 0xf7ff4630 */
/* @0x2e8568 stcls p13, c15, [r3, #-584] */
/* @0x2e856c ldmiblt r5, {r5, r6, r8, sp, lr} */
/* @0x2e8570 strbmi r4, [sp, #-0x647] */
/* @0x2e8574 .word 0xf857d00b */
/* @0x2e8578 teqlt r3, r4, lsl #22 */
/* @0x2e857c qadd16mi r6, r1, r8 */
/* @0x2e8580 blx 0x9a6578 <b2_toiTime+0x24d0d4> */
/* @0x2e8584 .word 0x3c04f857 */
/* @0x2e8588 strlo r6, [r1, #-0x3] */
/* @0x2e858c shsub8mi lr, r0, r1 */
/* @0x2e8590 .word 0xf7fe4641 */
/* @0x2e8594 blls 0x3e80dc <error_g0017+0x40d80> */
/* @0x2e8598 stmdblt r11, {r1, r8, r9, r12, pc} */
/* @0x2e859c subsvs lr, pc, r9, asr #15 */
/* @0x2e85a0 andlt r9, r4, r2, lsl #16 */
/* @0x2e85a4 .word 0x87f0e8bd */

/* ── FUNC 0x2e85a8 · ft_hash_str_insert · size=8 · insn=4 */
/* @0x2e85a8 push {r3, lr} */
/* @0x2e85aa bl 0x2e84f0 <ft_hash_num_init+0x3c> */
/* @0x2e85ac stclt p15, c15, [r8, #-644] */
/* @0x2e85ae pop {r3, pc} */

/* ── FUNC 0x2e85b0 · ft_hash_num_insert · size=8 · insn=4 */
/* @0x2e85b0 push {r3, lr} */
/* @0x2e85b2 bl 0x2e84f0 <ft_hash_num_init+0x3c> */
/* @0x2e85b4 stclt p15, c15, [r8, #-628] */
/* @0x2e85b6 pop {r3, pc} */

/* ── FUNC 0x2e85b8 · FT_Raccess_Get_DataOffsets · size=396 · insn=175 */
/* @0x2e85b8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e85bc sub sp, #0x1c */
/* @0x2e85be ldr.w r8, [r0] */
/* @0x2e85c0 strmi r8, [r12], -r0 */
/* @0x2e85c2 mov r4, r1 */
/* @0x2e85c4 mov r0, r1 */
/* @0x2e85c6 mov r1, r2 */
/* @0x2e85c8 mov r10, r2 */
/* @0x2e85ca str r3, [sp, #0xc] */
/* @0x2e85cc ldr r6, [sp, #0x4c] */
/* @0x2e85ce bl 0x2e68a6 <FT_Stream_Seek> */
/* @0x2e85d0 andls pc, r5, r10, ror #18 */
/* @0x2e85d2 str r0, [sp, #0x14] */
/* @0x2e85d4 cmp r0, #0x0 */
/* @0x2e85d6 bne.w 0x2e873a <FT_Raccess_Get_DataOffsets+0x182> */
/* @0x2e85d8 stcge p0, c8, [r5, #-704] */
/* @0x2e85da add r5, sp, #0x14 */
/* @0x2e85dc mov r0, r4 */
/* @0x2e85de mov r1, r5 */
/* @0x2e85e0 bl 0x2e6b04 <FT_Stream_ReadUShort> */
/* @0x2e85e4 ldr r7, [sp, #0x14] */
/* @0x2e85e6 cmp r7, #0x0 */
/* @0x2e85e8 bne.w 0x2e8738 <FT_Raccess_Get_DataOffsets+0x180> */
/* @0x2e85ec sxth.w r9, r0 */
/* @0x2e85f0 add.w r9, r9, #0x1 */
/* @0x2e85f4 cmp.w r9, #0xff0 */
/* @0x2e85f8 blt 0x2e863e <FT_Raccess_Get_DataOffsets+0x86> */
/* @0x2e85fa movs r0, #0x8 */
/* @0x2e85fc b 0x2e873a <FT_Raccess_Get_DataOffsets+0x182> */
/* @0x2e85fe mov r0, r4 */
/* @0x2e8600 mov r1, r5 */
/* @0x2e8602 bl 0x2e6dc4 <FT_Stream_ReadULong> */
/* @0x2e8604 blls 0x467588 <g_RomDisk+0x6fd68> */
/* @0x2e8606 ldr r3, [sp, #0x14] */
/* @0x2e8608 mov r11, r0 */
/* @0x2e860a cmp r3, #0x0 */
/* @0x2e860c bne.w 0x2e8730 <FT_Raccess_Get_DataOffsets+0x178> */
/* @0x2e8610 mov r0, r4 */
/* @0x2e8612 mov r1, r5 */
/* @0x2e8614 bl 0x2e6b04 <FT_Stream_ReadUShort> */
/* @0x2e8618 ldr r2, [sp, #0x14] */
/* @0x2e861a mov r3, r0 */
/* @0x2e861c cmp r2, #0x0 */
/* @0x2e861e bne.w 0x2e8730 <FT_Raccess_Get_DataOffsets+0x178> */
/* @0x2e8620 strtmi r8, [r9], -r7, lsl #1 */
/* @0x2e8622 mov r1, r5 */
/* @0x2e8624 mov r0, r4 */
/* @0x2e8626 str r3, [sp, #0x8] */
/* @0x2e8628 bl 0x2e6b04 <FT_Stream_ReadUShort> */
/* @0x2e862c ldr r2, [sp, #0x14] */
/* @0x2e862e ldr r3, [sp, #0x8] */
/* @0x2e8630 mov r1, r0 */
/* @0x2e8632 cmp r2, #0x0 */
/* @0x2e8634 bne 0x2e8730 <FT_Raccess_Get_DataOffsets+0x178> */
/* @0x2e8636 ldr r2, [sp, #0x40] */
/* @0x2e8638 cmp r11, r2 */
/* @0x2e863a beq 0x2e8644 <FT_Raccess_Get_DataOffsets+0x8c> */
/* @0x2e863c adds r7, #0x1 */
/* @0x2e863e cmp r7, r9 */
/* @0x2e8640 blt 0x2e85fe <FT_Raccess_Get_DataOffsets+0x46> */
/* @0x2e8642 b 0x2e8734 <FT_Raccess_Get_DataOffsets+0x17c> */
/* @0x2e8644 sxth r3, r3 */
/* @0x2e8646 adds r2, r3, #0x1 */
/* @0x2e8648 str r2, [r6] */
/* @0x2e864a movw r2, #0xaa6 */
/* @0x2e864c addsmi r2, r3, #1610612746 */
/* @0x2e864e cmp r3, r2 */
/* @0x2e8650 bhi 0x2e85fa <FT_Raccess_Get_DataOffsets+0x42> */
/* @0x2e8652 mov r0, r4 */
/* @0x2e8654 sxtah r1, r10, r1 */
/* @0x2e8658 bl 0x2e68a6 <FT_Stream_Seek> */
/* @0x2e865c mov r2, r0 */
/* @0x2e865e str r0, [sp, #0x14] */
/* @0x2e8660 cmp r0, #0x0 */
/* @0x2e8662 bne 0x2e873a <FT_Raccess_Get_DataOffsets+0x182> */
/* @0x2e8664 stm.w sp, {r2, r5} */
/* @0x2e8668 mov r0, r8 */
/* @0x2e866a movs r1, #0x8 */
/* @0x2e866c ldr r3, [r6] */
/* @0x2e866e bl 0x2e808e <ft_mem_realloc> */
/* @0x2e8670 strmi pc, [r1], lr, lsl #26 */
/* @0x2e8672 mov r9, r0 */
/* @0x2e8674 ldr r0, [sp, #0x14] */
/* @0x2e8676 cmp r0, #0x0 */
/* @0x2e8678 bne 0x2e873a <FT_Raccess_Get_DataOffsets+0x182> */
/* @0x2e867a mov r7, r9 */
/* @0x2e867c mov r10, r0 */
/* @0x2e867e ldr r1, [r6] */
/* @0x2e8680 cmp r10, r1 */
/* @0x2e8682 bge 0x2e86e2 <FT_Raccess_Get_DataOffsets+0x12a> */
/* @0x2e8684 mov r0, r4 */
/* @0x2e8686 mov r1, r5 */
/* @0x2e8688 bl 0x2e6b04 <FT_Stream_ReadUShort> */
/* @0x2e868c strh r0, [r7] */
/* @0x2e868e ldr r3, [sp, #0x14] */
/* @0x2e8690 cmp r3, #0x0 */
/* @0x2e8692 bne 0x2e8728 <FT_Raccess_Get_DataOffsets+0x170> */
/* @0x2e8694 mov r0, r4 */
/* @0x2e8696 movs r1, #0x2 */
/* @0x2e8698 bl 0x2e6930 <FT_Stream_Skip> */
/* @0x2e869c str r0, [sp, #0x14] */
/* @0x2e869e cmp r0, #0x0 */
/* @0x2e86a0 bne 0x2e8728 <FT_Raccess_Get_DataOffsets+0x170> */
/* @0x2e86a2 mov r0, r4 */
/* @0x2e86a4 mov r1, r5 */
/* @0x2e86a6 bl 0x2e6dc4 <FT_Stream_ReadULong> */
/* @0x2e86a8 blls 0x4674e4 <g_RomDisk+0x6fcc4> */
/* @0x2e86aa ldr r3, [sp, #0x14] */
/* @0x2e86ac mov r11, r0 */
/* @0x2e86ae cmp r3, #0x0 */
/* @0x2e86b0 bne 0x2e8728 <FT_Raccess_Get_DataOffsets+0x170> */
/* @0x2e86b2 mov r0, r4 */
/* @0x2e86b4 movs r1, #0x4 */
/* @0x2e86b6 bl 0x2e6930 <FT_Stream_Skip> */
/* @0x2e86b8 andls pc, r5, r11, lsr r9 */
/* @0x2e86ba str r0, [sp, #0x14] */
/* @0x2e86bc cbnz r0, 0x2e8728 <FT_Raccess_Get_DataOffsets+0x170> */
/* @0x2e86be ldrsh.w r3, [r7] */
/* @0x2e86c0 blhs 0x2f46c8 <ps_hints_apply+0x32c8> */
/* @0x2e86c2 cmp r3, #0x0 */
/* @0x2e86c4 blt 0x2e86d0 <FT_Raccess_Get_DataOffsets+0x118> */
/* @0x2e86c6 cmp.w r11, #0x0 */
/* @0x2e86c8 .word 0xf1070f00 */
/* @0x2e86ca add.w r7, r7, #0x8 */
/* @0x2e86cc ble 0x32a2f4 */
/* @0x2e86ce bge 0x2e86d4 <FT_Raccess_Get_DataOffsets+0x11c> */
/* @0x2e86d0 movs r3, #0x8 */
/* @0x2e86d2 b 0x2e8726 <FT_Raccess_Get_DataOffsets+0x16e> */
/* @0x2e86d4 bic r3, r11, #0xff000000 */
/* @0x2e86d8 add.w r10, r10, #0x1 */
/* @0x2e86dc str r3, [r7, #-4] */
/* @0x2e86e0 b 0x2e867e <FT_Raccess_Get_DataOffsets+0xc6> */
/* @0x2e86e2 ldrb.w r3, [sp, #0x44] */
/* @0x2e86e4 .word 0xb12b3044 */
/* @0x2e86e6 cbz r3, 0x2e86f4 <FT_Raccess_Get_DataOffsets+0x13c> */
/* @0x2e86e8 ldr r3, [pc, #0x54] */
/* @0x2e86ea mov r0, r9 */
/* @0x2e86ec movs r2, #0x8 */
/* @0x2e86ee add r3, pc */
/* @0x2e86f0 blx 0xb66dc <qsort@plt> */
/* @0x2e86f4 movs r2, #0x0 */
/* @0x2e86f6 mov r0, r8 */
/* @0x2e86f8 stm.w sp, {r2, r5} */
/* @0x2e86fc movs r1, #0x4 */
/* @0x2e86fe ldr r3, [r6] */
/* @0x2e8700 bl 0x2e808e <ft_mem_realloc> */
/* @0x2e8704 ldr r3, [sp, #0x14] */
/* @0x2e8706 cbnz r3, 0x2e8728 <FT_Raccess_Get_DataOffsets+0x170> */
/* @0x2e8708 ldr r2, [r6] */
/* @0x2e870a cmp r3, r2 */
/* @0x2e870c bge 0x2e8720 <FT_Raccess_Get_DataOffsets+0x168> */
/* @0x2e870e add.w r2, r9, r3, lsl #3 */
/* @0x2e8710 stmdbls r3, {r0, r1, r6, r7, r9} */
/* @0x2e8712 ldr r1, [sp, #0xc] */
/* @0x2e8714 ldr r2, [r2, #0x4] */
/* @0x2e8716 add r2, r1 */
/* @0x2e8718 str.w r2, [r0, r3, lsl #2] */
/* @0x2e871c adds r3, #0x1 */
/* @0x2e871e b 0x2e8708 <FT_Raccess_Get_DataOffsets+0x150> */
/* @0x2e8720 ldr r3, [sp, #0x48] */
/* @0x2e8722 str r0, [r3] */
/* @0x2e8724 movs r3, #0x0 */
/* @0x2e8726 str r3, [sp, #0x14] */
/* @0x2e8728 mov r0, r8 */
/* @0x2e872a mov r1, r9 */
/* @0x2e872c bl 0x2e7336 <ft_mem_free> */
/* @0x2e8730 ldr r0, [sp, #0x14] */
/* @0x2e8732 b 0x2e873a <FT_Raccess_Get_DataOffsets+0x182> */
/* @0x2e8734 movs r0, #0x1 */
/* @0x2e8736 b 0x2e873a <FT_Raccess_Get_DataOffsets+0x182> */
/* @0x2e8738 mov r0, r7 */
/* @0x2e873a add sp, #0x1c */
/* @0x2e873c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e8740 stm r3!, {r0, r1, r2, r3, r4, r6} */
/* @0x2e8742 vtbl.8 d30, {d15, d16}, d29 */

/* ── FUNC 0x2e8744 · FT_Get_Sfnt_Name · size=164 · insn=76 */
/* @0x2e8744 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2e8748 sub sp, #0x14 */
/* @0x2e874a movs r3, #0x6 */
/* @0x2e874c mov r5, r2 */
/* @0x2e874e str r3, [sp, #0xc] */
/* @0x2e8750 cmp r2, #0x0 */
/* @0x2e8752 beq 0x2e87e0 <FT_Get_Sfnt_Name+0x9c> */
/* @0x2e8754 cmp r0, #0x0 */
/* @0x2e8756 beq 0x2e87e0 <FT_Get_Sfnt_Name+0x9c> */
/* @0x2e8758 ldr r3, [r0, #0x8] */
/* @0x2e875a lsls r3, r3, #0x1c */
/* @0x2e875c bpl 0x2e87e0 <FT_Get_Sfnt_Name+0x9c> */
/* @0x2e875e ldrh.w r3, [r0, #0x154] */
/* @0x2e8760 addsmi r3, r9, #84, #2 */
/* @0x2e8762 cmp r1, r3 */
/* @0x2e8764 bhs 0x2e87e0 <FT_Get_Sfnt_Name+0x9c> */
/* @0x2e8766 movs r7, #0x14 */
/* @0x2e8768 ldr.w r8, [r0, #0x164] */
/* @0x2e876c muls r7, r1, r7 */
/* @0x2e876e add.w r4, r8, r7 */
/* @0x2e8770 stmdbhi r3!, {r0, r1, r2, r10} */
/* @0x2e8772 ldrh r3, [r4, #0x8] */
/* @0x2e8774 cbz r3, 0x2e87c2 <FT_Get_Sfnt_Name+0x7e> */
/* @0x2e8776 ldr r2, [r4, #0x10] */
/* @0x2e8778 cbnz r2, 0x2e87c2 <FT_Get_Sfnt_Name+0x7e> */
/* @0x2e877a ldr.w r9, [r0, #0x64] */
/* @0x2e877c stmdbge r3, {r2, r5, r6, r12, pc} */
/* @0x2e877e add r1, sp, #0xc */
/* @0x2e8780 ldr r6, [r0, #0x68] */
/* @0x2e8782 str r1, [sp, #0x4] */
/* @0x2e8784 movs r1, #0x1 */
/* @0x2e8786 str r2, [sp] */
/* @0x2e8788 mov r0, r9 */
/* @0x2e878a bl 0x2e808e <ft_mem_realloc> */
/* @0x2e878c blls 0x3e7994 <error_g0017+0x40638> */
/* @0x2e878e ldr r3, [sp, #0xc] */
/* @0x2e8790 str r0, [r4, #0x10] */
/* @0x2e8792 cbz r3, 0x2e87a4 <FT_Get_Sfnt_Name+0x60> */
/* @0x2e8794 mov r0, r9 */
/* @0x2e8796 ldr r1, [r4, #0x10] */
/* @0x2e8798 bl 0x2e7336 <ft_mem_free> */
/* @0x2e879c movs r3, #0x0 */
/* @0x2e879e str r3, [r4, #0x10] */
/* @0x2e87a0 strh r3, [r4, #0x8] */
/* @0x2e87a2 b 0x2e87c2 <FT_Get_Sfnt_Name+0x7e> */
/* @0x2e87a4 mov r0, r6 */
/* @0x2e87a6 ldr r1, [r4, #0xc] */
/* @0x2e87a8 bl 0x2e68a6 <FT_Stream_Seek> */
/* @0x2e87ac str r0, [sp, #0xc] */
/* @0x2e87ae cmp r0, #0x0 */
/* @0x2e87b0 bne 0x2e8794 <FT_Get_Sfnt_Name+0x50> */
/* @0x2e87b2 mov r0, r6 */
/* @0x2e87b4 ldr r1, [r4, #0x10] */
/* @0x2e87b6 ldrh r2, [r4, #0x8] */
/* @0x2e87b8 bl 0x2e698e <FT_Stream_Read> */
/* @0x2e87bc str r0, [sp, #0xc] */
/* @0x2e87be cmp r0, #0x0 */
/* @0x2e87c0 bne 0x2e8794 <FT_Get_Sfnt_Name+0x50> */
/* @0x2e87c2 ldrh.w r3, [r8, r7] */
/* @0x2e87c4 eorhi r3, r11, r7 */
/* @0x2e87c6 strh r3, [r5] */
/* @0x2e87c8 ldrh r3, [r4, #0x2] */
/* @0x2e87ca strh r3, [r5, #0x2] */
/* @0x2e87cc ldrh r3, [r4, #0x4] */
/* @0x2e87ce strh r3, [r5, #0x4] */
/* @0x2e87d0 ldrh r3, [r4, #0x6] */
/* @0x2e87d2 strh r3, [r5, #0x6] */
/* @0x2e87d4 ldr r3, [r4, #0x10] */
/* @0x2e87d6 str r3, [r5, #0x8] */
/* @0x2e87d8 ldrh r3, [r4, #0x8] */
/* @0x2e87da str r3, [r5, #0xc] */
/* @0x2e87dc movs r3, #0x0 */
/* @0x2e87de str r3, [sp, #0xc] */
/* @0x2e87e0 ldr r0, [sp, #0xc] */
/* @0x2e87e2 add sp, #0x14 */
/* @0x2e87e4 pop.w {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2e87e8 · FT_Get_Sfnt_LangTag · size=176 · insn=81 */
/* @0x2e87e8 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2e87ec sub sp, #0x14 */
/* @0x2e87ee mov r3, r1 */
/* @0x2e87f0 mov r5, r0 */
/* @0x2e87f2 movs r1, #0x6 */
/* @0x2e87f4 mov r8, r2 */
/* @0x2e87f6 str r1, [sp, #0xc] */
/* @0x2e87f8 cmp r2, #0x0 */
/* @0x2e87fa beq 0x2e888c <FT_Get_Sfnt_LangTag+0xa4> */
/* @0x2e87fc cmp r0, #0x0 */
/* @0x2e87fe beq 0x2e888c <FT_Get_Sfnt_LangTag+0xa4> */
/* @0x2e8800 ldr r2, [r0, #0x8] */
/* @0x2e8802 lsls r2, r2, #0x1c */
/* @0x2e8804 bpl 0x2e888c <FT_Get_Sfnt_LangTag+0xa4> */
/* @0x2e8806 ldrh.w r1, [r0, #0x158] */
/* @0x2e8808 stmdbhs r1, {r3, r4, r6, r8, r12} */
/* @0x2e880a cmp r1, #0x1 */
/* @0x2e880c bne 0x2e8890 <FT_Get_Sfnt_LangTag+0xa8> */
/* @0x2e880e cmp.w r3, #0x8000 */
/* @0x2e8810 ldmdble r11!, {r8, r9, r10, r11, lr} */
/* @0x2e8812 bls 0x2e888c <FT_Get_Sfnt_LangTag+0xa4> */
/* @0x2e8814 ldr.w r2, [r5, #0x168] */
/* @0x2e8818 sub.w r0, r3, #0x8000 */
/* @0x2e881c cmp r0, r2 */
/* @0x2e881e bhs 0x2e888c <FT_Get_Sfnt_LangTag+0xa4> */
/* @0x2e8820 movs r6, #0xc */
/* @0x2e8822 ldr.w r7, [r5, #0x16c] */
/* @0x2e8824 cmpmi lr, #108, #2 */
/* @0x2e8826 muls r6, r3, r6 */
/* @0x2e8828 sub.w r6, r6, #0x60000 */
/* @0x2e882c adds r4, r7, r6 */
/* @0x2e882e ldrh r3, [r7, r6] */
/* @0x2e8830 cbz r3, 0x2e887c <FT_Get_Sfnt_LangTag+0x94> */
/* @0x2e8832 ldr r2, [r4, #0x8] */
/* @0x2e8834 cbnz r2, 0x2e887c <FT_Get_Sfnt_LangTag+0x94> */
/* @0x2e8836 ldr.w r9, [r5, #0x64] */
/* @0x2e8838 stmdage r3, {r2, r5, r6, r12, pc} */
/* @0x2e883a add r0, sp, #0xc */
/* @0x2e883c ldr r5, [r5, #0x68] */
/* @0x2e883e str r0, [sp, #0x4] */
/* @0x2e8840 str r2, [sp] */
/* @0x2e8842 mov r0, r9 */
/* @0x2e8844 bl 0x2e808e <ft_mem_realloc> */
/* @0x2e8848 ldr r3, [sp, #0xc] */
/* @0x2e884a str r0, [r4, #0x8] */
/* @0x2e884c cbz r3, 0x2e885e <FT_Get_Sfnt_LangTag+0x76> */
/* @0x2e884e mov r0, r9 */
/* @0x2e8850 ldr r1, [r4, #0x8] */
/* @0x2e8852 bl 0x2e7336 <ft_mem_free> */
/* @0x2e8854 movwhs pc, #0xd70 */
/* @0x2e8856 movs r3, #0x0 */
/* @0x2e8858 str r3, [r4, #0x8] */
/* @0x2e885a strh r3, [r7, r6] */
/* @0x2e885c b 0x2e887c <FT_Get_Sfnt_LangTag+0x94> */
/* @0x2e885e mov r0, r5 */
/* @0x2e8860 ldr r1, [r4, #0x4] */
/* @0x2e8862 bl 0x2e68a6 <FT_Stream_Seek> */
/* @0x2e8864 andls pc, r3, r0, lsr #16 */
/* @0x2e8866 str r0, [sp, #0xc] */
/* @0x2e8868 cmp r0, #0x0 */
/* @0x2e886a bne 0x2e884e <FT_Get_Sfnt_LangTag+0x66> */
/* @0x2e886c mov r0, r5 */
/* @0x2e886e ldr r1, [r4, #0x8] */
/* @0x2e8870 ldrh r2, [r7, r6] */
/* @0x2e8872 bl 0x2e698e <FT_Stream_Read> */
/* @0x2e8874 andls pc, r3, r12, lsl #17 */
/* @0x2e8876 str r0, [sp, #0xc] */
/* @0x2e8878 cmp r0, #0x0 */
/* @0x2e887a bne 0x2e884e <FT_Get_Sfnt_LangTag+0x66> */
/* @0x2e887c ldr r3, [r4, #0x8] */
/* @0x2e887e str.w r3, [r8] */
/* @0x2e8880 blpl 0xff1b4888 <b2_toiTime+0xfffffffffea5b3e4> */
/* @0x2e8882 ldrh r3, [r7, r6] */
/* @0x2e8884 str.w r3, [r8, #0x4] */
/* @0x2e8888 movs r3, #0x0 */
/* @0x2e888a str r3, [sp, #0xc] */
/* @0x2e888c ldr r0, [sp, #0xc] */
/* @0x2e888e b 0x2e8892 <FT_Get_Sfnt_LangTag+0xaa> */
/* @0x2e8890 movs r0, #0x8 */
/* @0x2e8892 add sp, #0x14 */
/* @0x2e8894 pop.w {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2e8898 · ft_mem_dup · size=42 · insn=19 */
/* @0x2e8898 push {r0, r1, r2, r4, r5, r6, r7, lr} */
/* @0x2e889a mov r5, r1 */
/* @0x2e889c mov r4, r2 */
/* @0x2e889e mov r1, r2 */
/* @0x2e88a0 add r2, sp, #0x4 */
/* @0x2e88a2 mov r6, r3 */
/* @0x2e88a4 bl 0x2e7100 <ft_mem_qalloc> */
/* @0x2e88a8 ldr r2, [sp, #0x4] */
/* @0x2e88aa mov r7, r0 */
/* @0x2e88ac cbnz r2, 0x2e88b8 <ft_mem_dup+0x20> */
/* @0x2e88ae cbz r5, 0x2e88b8 <ft_mem_dup+0x20> */
/* @0x2e88b0 mov r1, r5 */
/* @0x2e88b2 mov r2, r4 */
/* @0x2e88b4 blx 0xb65bc <memcpy@plt> */
/* @0x2e88b8 ldr r3, [sp, #0x4] */
/* @0x2e88ba mov r0, r7 */
/* @0x2e88bc str r3, [r6] */
/* @0x2e88be add sp, #0xc */
/* @0x2e88c0 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e88c2 · ft_mem_strdup · size=36 · insn=15 */
/* @0x2e88c2 push {r4, r5, r6, lr} */
/* @0x2e88c4 mov r6, r0 */
/* @0x2e88c6 mov r5, r2 */
/* @0x2e88c8 mov r4, r1 */
/* @0x2e88ca cbz r1, 0x2e88d6 <ft_mem_strdup+0x14> */
/* @0x2e88cc mov r0, r1 */
/* @0x2e88ce blx 0xb6538 <strlen@plt> */
/* @0x2e88d2 adds r2, r0, #0x1 */
/* @0x2e88d4 b 0x2e88d8 <ft_mem_strdup+0x16> */
/* @0x2e88d6 mov r2, r1 */
/* @0x2e88d8 mov r0, r6 */
/* @0x2e88da mov r1, r4 */
/* @0x2e88dc mov r3, r5 */
/* @0x2e88de pop.w {r4, r5, r6, lr} */
/* @0x2e88e2 b.w 0x2e8898 <ft_mem_dup> */

/* ── FUNC 0x2e88e6 · ft_mem_strcpyn · size=40 · insn=20 */
/* @0x2e88e6 add r2, r0 */
/* @0x2e88e8 push {r4, lr} */
/* @0x2e88ea subs r3, r2, r0 */
/* @0x2e88ec mov r4, r1 */
/* @0x2e88ee cmp r3, #0x1 */
/* @0x2e88f0 bhi 0x2e8900 <ft_mem_strcpyn+0x1a> */
/* @0x2e88f2 movs r3, #0x0 */
/* @0x2e88f4 strb r3, [r0] */
/* @0x2e88f6 ldrb r0, [r4] */
/* @0x2e88f8 subs r0, r0, r3 */
/* @0x2e88fa it ne */
/* @0x2e88fc movne r0, #0x1 */
/* @0x2e88fe pop {r4, pc} */
/* @0x2e8900 ldrb r3, [r1], #1 */
/* @0x2e8902 blhs 0x2f750e <ps_hints_apply+0x610e> */
/* @0x2e8904 cmp r3, #0x0 */
/* @0x2e8906 beq 0x2e88f2 <ft_mem_strcpyn+0xc> */
/* @0x2e8908 strb r3, [r0], #1 */
/* @0x2e890a strb r3, [sp, r1, lsl #22]! */
/* @0x2e890c b 0x2e88ea <ft_mem_strcpyn+0x4> */

/* ── FUNC 0x2e890e · FT_List_Find · size=18 · insn=9 */
/* @0x2e890e cbz r0, 0x2e891e <FT_List_Find+0x10> */
/* @0x2e8910 ldr r0, [r0] */
/* @0x2e8912 cbz r0, 0x2e891e <FT_List_Find+0x10> */
/* @0x2e8914 ldr r3, [r0, #0x8] */
/* @0x2e8916 cmp r3, r1 */
/* @0x2e8918 beq 0x2e891e <FT_List_Find+0x10> */
/* @0x2e891a ldr r0, [r0, #0x4] */
/* @0x2e891c b 0x2e8912 <FT_List_Find+0x4> */
/* @0x2e891e bx lr */

/* ── FUNC 0x2e8920 · FT_List_Add · size=24 · insn=12 */
/* @0x2e8920 cbz r0, 0x2e8936 <FT_List_Add+0x16> */
/* @0x2e8922 cbz r1, 0x2e8936 <FT_List_Add+0x16> */
/* @0x2e8924 ldr r3, [r0, #0x4] */
/* @0x2e8926 movs r2, #0x0 */
/* @0x2e8928 str r2, [r1, #0x4] */
/* @0x2e892a str r3, [r1] */
/* @0x2e892c cbz r3, 0x2e8932 <FT_List_Add+0x12> */
/* @0x2e892e str r1, [r3, #0x4] */
/* @0x2e8930 b 0x2e8934 <FT_List_Add+0x14> */
/* @0x2e8932 str r1, [r0] */
/* @0x2e8934 str r1, [r0, #0x4] */
/* @0x2e8936 bx lr */

/* ── FUNC 0x2e8938 · FT_New_Size · size=162 · insn=77 */
/* @0x2e8938 push.w {r0, r1, r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2e893c mov r8, r1 */
/* @0x2e893e mov r5, r0 */
/* @0x2e8940 cmp r0, #0x0 */
/* @0x2e8942 beq 0x2e89ca <FT_New_Size+0x92> */
/* @0x2e8944 cmp r1, #0x0 */
/* @0x2e8946 beq 0x2e89ce <FT_New_Size+0x96> */
/* @0x2e8948 ldr r3, [r0, #0x60] */
/* @0x2e894a cmp r3, #0x0 */
/* @0x2e894c beq 0x2e89d2 <FT_New_Size+0x9a> */
/* @0x2e894e movs r7, #0x0 */
/* @0x2e8950 str r7, [r1] */
/* @0x2e8952 ldr r3, [r0, #0x60] */
/* @0x2e8954 add.w r9, sp, #0x4 */
/* @0x2e8958 ldr r6, [r0, #0x64] */
/* @0x2e895a mov r2, r9 */
/* @0x2e895c ldr.w r10, [r3, #0xc] */
/* @0x2e8960 mov r0, r6 */
/* @0x2e8962 ldr.w r1, [r10, #0x28] */
/* @0x2e8964 .word 0xf7fe1028 */
/* @0x2e8966 bl 0x2e7126 <ft_mem_alloc> */
/* @0x2e8968 blls 0x3678e8 <_ZTS12CDS_Priority+0x9940> */
/* @0x2e896a ldr r3, [sp, #0x4] */
/* @0x2e896c mov r4, r0 */
/* @0x2e896e cbnz r3, 0x2e89b2 <FT_New_Size+0x7a> */
/* @0x2e8970 mov r0, r6 */
/* @0x2e8972 movs r1, #0xc */
/* @0x2e8974 mov r2, r9 */
/* @0x2e8976 bl 0x2e7126 <ft_mem_alloc> */
/* @0x2e8978 blls 0x3678d8 <_ZTS12CDS_Priority+0x9930> */
/* @0x2e897a ldr r3, [sp, #0x4] */
/* @0x2e897c mov r7, r0 */
/* @0x2e897e cbnz r3, 0x2e89b2 <FT_New_Size+0x7a> */
/* @0x2e8980 str r5, [r4] */
/* @0x2e8982 mov r0, r6 */
/* @0x2e8984 movs r1, #0x24 */
/* @0x2e8986 mov r2, r9 */
/* @0x2e8988 bl 0x2e7126 <ft_mem_alloc> */
/* @0x2e898c ldr r3, [sp, #0x4] */
/* @0x2e898e cbnz r3, 0x2e89b2 <FT_New_Size+0x7a> */
/* @0x2e8990 str r0, [r4, #0x28] */
/* @0x2e8992 ldr.w r3, [r10, #0x38] */
/* @0x2e8994 tstlt r3, r8, lsr r0 */
/* @0x2e8996 cbz r3, 0x2e899e <FT_New_Size+0x66> */
/* @0x2e8998 mov r0, r4 */
/* @0x2e899a blx r3 */
/* @0x2e899c str r0, [sp, #0x4] */
/* @0x2e899e ldr r3, [sp, #0x4] */
/* @0x2e89a0 cbnz r3, 0x2e89b2 <FT_New_Size+0x7a> */
/* @0x2e89a2 str.w r4, [r8] */
/* @0x2e89a4 .word 0xf1054000 */
/* @0x2e89a6 add.w r0, r5, #0x6c */
/* @0x2e89a8 adcsvs r0, r12, r12, rrx */
/* @0x2e89aa str r4, [r7, #0x8] */
/* @0x2e89ac mov r1, r7 */
/* @0x2e89ae bl 0x2e8920 <FT_List_Add> */
/* @0x2e89b0 blls 0x368894 <_ZTS12CDS_Priority+0xa8ec> */
/* @0x2e89b2 ldr r3, [sp, #0x4] */
/* @0x2e89b4 cbz r3, 0x2e89c6 <FT_New_Size+0x8e> */
/* @0x2e89b6 mov r0, r6 */
/* @0x2e89b8 mov r1, r7 */
/* @0x2e89ba bl 0x2e7336 <ft_mem_free> */
/* @0x2e89bc .word 0x4630fcbc */
/* @0x2e89be mov r0, r6 */
/* @0x2e89c0 mov r1, r4 */
/* @0x2e89c2 bl 0x2e7336 <ft_mem_free> */
/* @0x2e89c4 stmdals r1, {r3, r4, r5, r7, r10, r11, r12, sp, lr, pc} */
/* @0x2e89c6 ldr r0, [sp, #0x4] */
/* @0x2e89c8 b 0x2e89d4 <FT_New_Size+0x9c> */
/* @0x2e89ca movs r0, #0x23 */
/* @0x2e89cc b 0x2e89d4 <FT_New_Size+0x9c> */
/* @0x2e89ce movs r0, #0x6 */
/* @0x2e89d0 b 0x2e89d4 <FT_New_Size+0x9c> */
/* @0x2e89d2 movs r0, #0x22 */
/* @0x2e89d4 add sp, #0x8 */
/* @0x2e89d6 pop.w {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2e89d8 strdlt r8, r9, [r8, #-112] */

/* ── FUNC 0x2e89da · FT_List_Insert · size=24 · insn=12 */
/* @0x2e89da cbz r0, 0x2e89f0 <FT_List_Insert+0x16> */
/* @0x2e89dc cbz r1, 0x2e89f0 <FT_List_Insert+0x16> */
/* @0x2e89de ldr r3, [r0] */
/* @0x2e89e0 movs r2, #0x0 */
/* @0x2e89e2 str r2, [r1] */
/* @0x2e89e4 str r3, [r1, #0x4] */
/* @0x2e89e6 cbnz r3, 0x2e89ec <FT_List_Insert+0x12> */
/* @0x2e89e8 str r1, [r0, #0x4] */
/* @0x2e89ea b 0x2e89ee <FT_List_Insert+0x14> */
/* @0x2e89ec str r1, [r3] */
/* @0x2e89ee str r1, [r0] */
/* @0x2e89f0 bx lr */

/* ── FUNC 0x2e89f2 · FT_List_Remove · size=26 · insn=13 */
/* @0x2e89f2 cbz r0, 0x2e8a0a <FT_List_Remove+0x18> */
/* @0x2e89f4 cbz r1, 0x2e8a0a <FT_List_Remove+0x18> */
/* @0x2e89f6 ldr r3, [r1] */
/* @0x2e89f8 ldr r2, [r1, #0x4] */
/* @0x2e89fa cbz r3, 0x2e8a00 <FT_List_Remove+0xe> */
/* @0x2e89fc str r2, [r3, #0x4] */
/* @0x2e89fe b 0x2e8a02 <FT_List_Remove+0x10> */
/* @0x2e8a00 str r2, [r0] */
/* @0x2e8a02 cbz r2, 0x2e8a08 <FT_List_Remove+0x16> */
/* @0x2e8a04 str r3, [r2] */
/* @0x2e8a06 bx lr */
/* @0x2e8a08 str r3, [r0, #0x4] */
/* @0x2e8a0a bx lr */

/* ── FUNC 0x2e8a0c · FT_Done_Size · size=106 · insn=47 */
/* @0x2e8a0c push.w {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2e8a10 mov r5, r0 */
/* @0x2e8a12 cbnz r0, 0x2e8a1a <FT_Done_Size+0xe> */
/* @0x2e8a14 movs r0, #0x24 */
/* @0x2e8a16 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2e8a18 stmdavs r4, {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2e8a1a ldr r4, [r0] */
/* @0x2e8a1c cbz r4, 0x2e8a6a <FT_Done_Size+0x5e> */
/* @0x2e8a1e ldr r6, [r4, #0x60] */
/* @0x2e8a20 cbz r6, 0x2e8a70 <FT_Done_Size+0x64> */
/* @0x2e8a22 add.w r9, r4, #0x6c */
/* @0x2e8a24 strtmi r0, [r9], -r12, ror #18 */
/* @0x2e8a26 mov r1, r5 */
/* @0x2e8a28 ldr.w r8, [r6, #0x8] */
/* @0x2e8a2c mov r0, r9 */
/* @0x2e8a2e bl 0x2e890e <FT_List_Find> */
/* @0x2e8a30 strmi pc, [r7], -lr, ror #30 */
/* @0x2e8a32 mov r7, r0 */
/* @0x2e8a34 cmp r0, #0x0 */
/* @0x2e8a36 beq 0x2e8a14 <FT_Done_Size+0x8> */
/* @0x2e8a38 mov r0, r9 */
/* @0x2e8a3a mov r1, r7 */
/* @0x2e8a3c bl 0x2e89f2 <FT_List_Remove> */
/* @0x2e8a40 mov r0, r8 */
/* @0x2e8a42 mov r1, r7 */
/* @0x2e8a44 bl 0x2e7336 <ft_mem_free> */
/* @0x2e8a48 ldr r3, [r4, #0x58] */
/* @0x2e8a4a cmp r3, r5 */
/* @0x2e8a4c bne 0x2e8a5a <FT_Done_Size+0x4e> */
/* @0x2e8a4e movs r3, #0x0 */
/* @0x2e8a50 str r3, [r4, #0x58] */
/* @0x2e8a52 ldr r3, [r4, #0x6c] */
/* @0x2e8a54 cbz r3, 0x2e8a5a <FT_Done_Size+0x4e> */
/* @0x2e8a56 ldr r3, [r3, #0x8] */
/* @0x2e8a58 str r3, [r4, #0x58] */
/* @0x2e8a5a mov r0, r8 */
/* @0x2e8a5c mov r1, r5 */
/* @0x2e8a5e mov r2, r6 */
/* @0x2e8a60 bl 0x2e7d88 <FT_Done_GlyphSlot+0x26e> */
/* @0x2e8a64 movs r0, #0x0 */
/* @0x2e8a66 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2e8a68 .word 0x202383f8 */
/* @0x2e8a6a movs r0, #0x23 */
/* @0x2e8a6c pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2e8a70 movs r0, #0x22 */
/* @0x2e8a72 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2e8a74 ldrshlt r8, [r8, #-56]! */

/* ── FUNC 0x2e8a76 · FT_List_Up · size=36 · insn=18 */
/* @0x2e8a76 cbz r0, 0x2e8a98 <FT_List_Up+0x22> */
/* @0x2e8a78 cbz r1, 0x2e8a98 <FT_List_Up+0x22> */
/* @0x2e8a7a ldr r3, [r1] */
/* @0x2e8a7c ldr r2, [r1, #0x4] */
/* @0x2e8a7e cbz r3, 0x2e8a98 <FT_List_Up+0x22> */
/* @0x2e8a80 str r2, [r3, #0x4] */
/* @0x2e8a82 cbz r2, 0x2e8a88 <FT_List_Up+0x12> */
/* @0x2e8a84 str r3, [r2] */
/* @0x2e8a86 b 0x2e8a8a <FT_List_Up+0x14> */
/* @0x2e8a88 str r3, [r0, #0x4] */
/* @0x2e8a8a movs r3, #0x0 */
/* @0x2e8a8c str r3, [r1] */
/* @0x2e8a8e ldr r3, [r0] */
/* @0x2e8a90 str r3, [r1, #0x4] */
/* @0x2e8a92 ldr r3, [r0] */
/* @0x2e8a94 str r1, [r3] */
/* @0x2e8a96 str r1, [r0] */
/* @0x2e8a98 bx lr */

/* ── FUNC 0x2e8a9a · anon_2e8a9a · size=0 · insn=1 */
/* @0x2e8a9a .word 0xe92d0000 */

/* ── FUNC 0x2e8a9c · FT_Set_Renderer · size=104 · insn=47 */
/* @0x2e8a9c push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2e8aa0 mov r4, r1 */
/* @0x2e8aa2 mov r5, r2 */
/* @0x2e8aa4 mov r6, r3 */
/* @0x2e8aa6 mov r7, r0 */
/* @0x2e8aa8 cbz r0, 0x2e8afa <FT_Set_Renderer+0x5e> */
/* @0x2e8aaa cbnz r1, 0x2e8ab2 <FT_Set_Renderer+0x16> */
/* @0x2e8aac movs r0, #0x6 */
/* @0x2e8aae pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e8ab0 strdlt r8, r9, [r10, -r0] */
/* @0x2e8ab2 cbz r2, 0x2e8ab8 <FT_Set_Renderer+0x1c> */
/* @0x2e8ab4 cmp r3, #0x0 */
/* @0x2e8ab6 beq 0x2e8aac <FT_Set_Renderer+0x10> */
/* @0x2e8ab8 add.w r8, r7, #0x94 */
/* @0x2e8abc mov r1, r4 */
/* @0x2e8abe mov r0, r8 */
/* @0x2e8ac0 bl 0x2e890e <FT_List_Find> */
/* @0x2e8ac4 mov r1, r0 */
/* @0x2e8ac6 cmp r0, #0x0 */
/* @0x2e8ac8 beq 0x2e8aac <FT_Set_Renderer+0x10> */
/* @0x2e8aca mov r0, r8 */
/* @0x2e8acc adds r6, #0x8 */
/* @0x2e8ace bl 0x2e8a76 <FT_List_Up> */
/* @0x2e8ad0 stmdbvs r3!, {r1, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e8ad2 ldr r3, [r4, #0x10] */
/* @0x2e8ad4 ldr r2, [pc, #0x28] */
/* @0x2e8ad6 cmp r3, r2 */
/* @0x2e8ad8 it eq */
/* @0x2e8ada streq.w r4, [r7, #0x9c] */
/* @0x2e8adc stmvs r3!, {r2, r3, r4, r7, lr} ^ */
/* @0x2e8ade ldr r3, [r4, #0xc] */
/* @0x2e8ae0 ldr r7, [r3, #0x34] */
/* @0x2e8ae2 cbz r5, 0x2e8af4 <FT_Set_Renderer+0x58> */
/* @0x2e8ae4 ldmdb r6, {r1, r2} */
/* @0x2e8ae8 mov r0, r4 */
/* @0x2e8aea blx r7 */
/* @0x2e8aec adds r6, #0x8 */
/* @0x2e8aee cbnz r0, 0x2e8afc <FT_Set_Renderer+0x60> */
/* @0x2e8af0 subs r5, #0x1 */
/* @0x2e8af2 b 0x2e8ae2 <FT_Set_Renderer+0x46> */
/* @0x2e8af4 mov r0, r5 */
/* @0x2e8af6 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e8af8 .word 0x202181f0 */
/* @0x2e8afa movs r0, #0x21 */
/* @0x2e8afc pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e8b00 strb r4, [r5, #0x11] */
/* @0x2e8b02 ldr r5, [r6, #0x74] */

/* ── FUNC 0x2e8b04 · FT_List_Iterate · size=32 · insn=16 */
/* @0x2e8b04 push {r4, r5, r6, lr} */
/* @0x2e8b06 mov r4, r1 */
/* @0x2e8b08 mov r6, r2 */
/* @0x2e8b0a cbz r0, 0x2e8b20 <FT_List_Iterate+0x1c> */
/* @0x2e8b0c cbz r1, 0x2e8b20 <FT_List_Iterate+0x1c> */
/* @0x2e8b0e ldr r0, [r0] */
/* @0x2e8b10 cbz r0, 0x2e8b1e <FT_List_Iterate+0x1a> */
/* @0x2e8b12 mov r1, r6 */
/* @0x2e8b14 ldr r5, [r0, #0x4] */
/* @0x2e8b16 blx r4 */
/* @0x2e8b18 cbnz r0, 0x2e8b22 <FT_List_Iterate+0x1e> */
/* @0x2e8b1a mov r0, r5 */
/* @0x2e8b1c b 0x2e8b10 <FT_List_Iterate+0xc> */
/* @0x2e8b1e pop {r4, r5, r6, pc} */
/* @0x2e8b20 movs r0, #0x6 */
/* @0x2e8b22 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e8b24 · FT_List_Finalize · size=54 · insn=25 */
/* @0x2e8b24 push.w {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2e8b28 mov r7, r1 */
/* @0x2e8b2a mov r6, r2 */
/* @0x2e8b2c mov r8, r3 */
/* @0x2e8b2e mov r5, r0 */
/* @0x2e8b30 cbz r0, 0x2e8b56 <FT_List_Finalize+0x32> */
/* @0x2e8b32 cbz r2, 0x2e8b56 <FT_List_Finalize+0x32> */
/* @0x2e8b34 ldr r4, [r0] */
/* @0x2e8b36 cbz r4, 0x2e8b52 <FT_List_Finalize+0x2e> */
/* @0x2e8b38 ldr.w r9, [r4, #0x4] */
/* @0x2e8b3c ldr r1, [r4, #0x8] */
/* @0x2e8b3e cbz r7, 0x2e8b46 <FT_List_Finalize+0x22> */
/* @0x2e8b40 mov r0, r6 */
/* @0x2e8b42 mov r2, r8 */
/* @0x2e8b44 blx r7 */
/* @0x2e8b46 mov r1, r4 */
/* @0x2e8b48 mov r0, r6 */
/* @0x2e8b4a bl 0x2e7336 <ft_mem_free> */
/* @0x2e8b4c .word 0x464cfbf4 */
/* @0x2e8b4e mov r4, r9 */
/* @0x2e8b50 b 0x2e8b36 <FT_List_Finalize+0x12> */
/* @0x2e8b52 str r4, [r5] */
/* @0x2e8b54 str r4, [r5, #0x4] */
/* @0x2e8b56 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2e8b58 strdeq r8, r9, [r0], -r8 */

/* ── FUNC 0x2e8b5c · anon_2e8b5c · size=124 · insn=32 */
/* @0x2e8b5c mvnsmi lr, sp, lsr #18 */
/* @0x2e8b60 svcvs #0x8b4605 */
/* @0x2e8b64 ldrmi r4, [r7], -r12, lsl #12 */
/* @0x2e8b68 .word 0x800cf8d2 */
/* @0x2e8b6c svcvs #0x48b10b */
/* @0x2e8b70 stclvs p7, c4, [r6, #-608]! */
/* @0x2e8b74 shadd16mi r11, r0, lr */
/* @0x2e8b78 .word 0xffcff7fe */
/* @0x2e8b7c ldmdbmi r6, {r0, r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2e8b80 .word 0xf104463b */
/* @0x2e8b84 strtmi r0, [r10], -r12, rrx */
/* @0x2e8b88 .word 0xf7ff4479 */
/* @0x2e8b8c blvs 0xbe8ac0 <b2_toiTime+0x48f61c> */
/* @0x2e8b90 smlatblt r11, r6, r5, r6 */
/* @0x2e8b94 ldrmi r4, [r8, r0, lsr #12] */
/* @0x2e8b98 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2e8b9c .word 0xffecf7fe */
/* @0x2e8ba0 ldrsbtlo pc, [r4], -r8 */
/* @0x2e8ba4 strtmi r11, [r0], -r11, lsl #2 */
/* @0x2e8ba8 stmvs r1!, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x2e8bac cdpvs p6, #0xa, c2, c0, c0, #0x0 */
/* @0x2e8bb0 orrhs pc, r0, r1, asr #7 */
/* @0x2e8bb4 mrrc2 p7, #0xf, pc, r3, c14 */
/* @0x2e8bb8 .word 0x1080f8d4 */
/* @0x2e8bbc smulwblt r1, r6, r6 */
/* @0x2e8bc0 .word 0xf7fe4628 */
/* @0x2e8bc4 .word 0xf8c4fbb8 */
/* @0x2e8bc8 strtmi r6, [r8], -r0, lsl #1 */
/* @0x2e8bcc pop {r0, r5, r9, r10, lr} */
/* @0x2e8bd0 .word 0xf7fe41f0 */
/* @0x2e8bd4 svclt #0xbbb0 */
/* @0x2e8bd8 .word 0xfffff1fd */

/* ── FUNC 0x2e8bdc · FT_Done_Face · size=92 · insn=39 */
/* @0x2e8bdc push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2e8be0 mov r4, r0 */
/* @0x2e8be2 cbz r0, 0x2e8c2c <FT_Done_Face+0x50> */
/* @0x2e8be4 ldr r3, [r0, #0x60] */
/* @0x2e8be6 cbz r3, 0x2e8c2c <FT_Done_Face+0x50> */
/* @0x2e8be8 ldr.w r3, [r0, #0x80] */
/* @0x2e8bec ldr r2, [r3, #0x40] */
/* @0x2e8bee subs r2, #0x1 */
/* @0x2e8bf0 str r2, [r3, #0x40] */
/* @0x2e8bf2 ldr.w r3, [r0, #0x80] */
/* @0x2e8bf4 .word 0x6c1b3080 */
/* @0x2e8bf6 ldr r3, [r3, #0x40] */
/* @0x2e8bf8 cmp r3, #0x0 */
/* @0x2e8bfa bgt 0x2e8c32 <FT_Done_Face+0x56> */
/* @0x2e8bfc ldr r5, [r0, #0x60] */
/* @0x2e8bfe mov r1, r4 */
/* @0x2e8c00 add.w r8, r5, #0x10 */
/* @0x2e8c04 ldr r7, [r5, #0x8] */
/* @0x2e8c06 mov r0, r8 */
/* @0x2e8c08 bl 0x2e890e <FT_List_Find> */
/* @0x2e8c0c mov r6, r0 */
/* @0x2e8c0e cbz r0, 0x2e8c2c <FT_Done_Face+0x50> */
/* @0x2e8c10 mov r0, r8 */
/* @0x2e8c12 mov r1, r6 */
/* @0x2e8c14 bl 0x2e89f2 <FT_List_Remove> */
/* @0x2e8c18 mov r0, r7 */
/* @0x2e8c1a mov r1, r6 */
/* @0x2e8c1c bl 0x2e7336 <ft_mem_free> */
/* @0x2e8c20 mov r0, r7 */
/* @0x2e8c22 mov r1, r4 */
/* @0x2e8c24 mov r2, r5 */
/* @0x2e8c26 bl 0x2e8b5c <FT_List_Finalize+0x38> */
/* @0x2e8c28 mul r2, r9, pc */
/* @0x2e8c2a b 0x2e8c32 <FT_Done_Face+0x56> */
/* @0x2e8c2c movs r0, #0x23 */
/* @0x2e8c2e pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e8c30 strdhs r8, r9, [r0], -r0 */
/* @0x2e8c32 movs r0, #0x0 */
/* @0x2e8c34 pop.w {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2e8c38 · anon_2e8c38 · size=1180 · insn=296 */
/* @0x2e8c38 svcmi #0xf0e92d */
/* @0x2e8c3c .word 0x4617b0d7 */
/* @0x2e8c40 strhs pc, [r8], #2271 */
/* @0x2e8c44 .word 0xf89d460c */
/* @0x2e8c48 ldrbtmi r1, [r10], #-384 */
/* @0x2e8c4c .word 0xf10d6812 */
/* @0x2e8c50 .word 0xf10d083c */
/* @0x2e8c54 strmi r0, [r5], -r0, asr #18 */
/* @0x2e8c58 ldmdavs r1, {r0, r1, r2, r8, r12, pc} */
/* @0x2e8c5c andls r9, r12, #335544320 */
/* @0x2e8c60 qaddhs r9, r5, r0 */
/* @0x2e8c64 andne pc, r0, r8, asr #17 */
/* @0x2e8c68 andne pc, r0, r9, asr #17 */
/* @0x2e8c6c addmi r11, pc, #311296 */
/* @0x2e8c70 eorhi pc, r0, #128, #4 */
/* @0x2e8c74 .word 0xf0002c00 */
/* @0x2e8c78 stmdavs r3!, {r0, r2, r3, r4, r9, pc} */
/* @0x2e8c7c movweq pc, #0x2013 */
/* @0x2e8c80 stmdbvs r3!, {r1, r2, r12, lr, pc} */
/* @0x2e8c84 bleq 0x3250d8 */
/* @0x2e8c88 .word 0xf04fbf18 */
/* @0x2e8c8c and r0, r0, r1, lsl #22 */
/* @0x2e8c90 qadd8mi r4, r8, r11 */
/* @0x2e8c94 strbmi r4, [r2], -r1, lsr #12 */
/* @0x2e8c98 blx 0xfeb26c9a <b2_toiTime+0xfffffffffe3cd7f6> */
/* @0x2e8c9c andsvs r10, r8, lr, lsl #22 */
/* @0x2e8ca0 .word 0xf0402800 */
/* @0x2e8ca4 blx 0x1ac8ec4 <b2_toiTime+0x136fa20> */
/* @0x2e8ca8 andls pc, r6, #-1342177272 */
/* @0x2e8cac stmdavs r9!, {r1, r5, r11, sp, lr} */
/* @0x2e8cb0 .word 0x91080716 */
/* @0x2e8cb4 stmdbvs r6!, {r0, r2, r3, r4, r8, r10, r12, lr, pc} ^ */
/* @0x2e8cb8 ldmdavs r1!, {r1, r2, r3, r4, r6, r7, r8, r12, sp, pc} */
/* @0x2e8cbc strbeq r6, [sp, r9, lsl #16] */
/* @0x2e8cc0 .word 0xf012d512 */
/* @0x2e8cc4 shadd16mi r0, r0, r0 */
/* @0x2e8cc8 svclt #0x164641 */
/* @0x2e8ccc ldrmi r6, [r10], -r2, lsr #19 */
/* @0x2e8cd0 stm sp, {r0, r1, r5, r6, r7, r8, r11, sp, lr} */
/* @0x2e8cd4 ldrtmi r0, [r11], -r12, lsl #4 */
/* @0x2e8cd8 .word 0xf7fe9a06 */
/* @0x2e8cdc andls pc, lr, r9, ror #30 */
/* @0x2e8ce0 .word 0xf0002800 */
/* @0x2e8ce4 and r8, r1, r1, ror #2 */
/* @0x2e8ce8 andsvs r2, r10, r0, lsr #4 */
/* @0x2e8cec .word 0x0000f8d8 */
/* @0x2e8cf0 andhs lr, r11, #-2147483627 */
/* @0x2e8cf4 stmdbvs r11!, {r1, r3, r4, sp, lr} */
/* @0x2e8cf8 ldmdaeq r4, {r0, r2, r8, r12, sp, lr, pc} */
/* @0x2e8cfc .word 0xf10d49f4 */
/* @0x2e8d00 bge 0x6eb1f8 <g_SWFvertbuff+0x18130> */
/* @0x2e8d04 bl 0x50d534 <SrcVerts+0x6a578> */
/* @0x2e8d08 movwls r0, #0x9383 */
/* @0x2e8d0c ldrbtmi r2, [r9], #-768 */
/* @0x2e8d10 bls 0x54d144 <gp_ActiveMaskObjects+0x847c> */
/* @0x2e8d14 suble r4, lr, #144, #10 */
/* @0x2e8d18 blvs 0x426e80 <g_RomDisk+0x2f660> */
/* @0x2e8d1c ldmdavs r2, {r1, r4, r5, r11, sp, lr} */
/* @0x2e8d20 ldrble r0, [r6, #0x7d0]! */
/* @0x2e8d24 ldrtmi r6, [r0], -r3, lsr #16 */
/* @0x2e8d28 .word 0xf10d4649 */
/* @0x2e8d2c .word 0xf0130a38 */
/* @0x2e8d30 svclt #0x160310 */
/* @0x2e8d34 ldrmi r6, [r10], -r2, lsr #19 */
/* @0x2e8d38 stm sp, {r0, r1, r5, r6, r7, r8, r11, sp, lr} */
/* @0x2e8d3c bge 0x6e8d74 <g_SWFvertbuff+0x15cac> */
/* @0x2e8d40 andls r4, r2, #61865984 */
/* @0x2e8d44 .word 0xf7fe9a06 */
/* @0x2e8d48 .word 0x4603ff33 */
/* @0x2e8d4c stmdahs r0, {r1, r2, r3, r12, pc} */
/* @0x2e8d50 msrhi CPSR_fx, r0 */
/* @0x2e8d54 teqlt r1, #114688 */
/* @0x2e8d58 .word 0x2c04f858 */
/* @0x2e8d5c ldmdavs r2, {r0, r1, r3, r8, r11, r12, pc} */
/* @0x2e8d60 movwls r6, #0x4890 */
/* @0x2e8d64 .word 0xec06f5cd */
/* @0x2e8d68 strmi r9, [r1], -r4, lsl #22 */
/* @0x2e8d6c sbcslt r11, r11, #216, #18 */
/* @0x2e8d70 tstle r8, lr, lsl #23 */
/* @0x2e8d74 .word 0x0000f8d9 */
/* @0x2e8d78 ldc2 p7, c15, [r5, #1012] */
/* @0x2e8d7c andeq pc, r0, r10, asr #17 */
/* @0x2e8d80 .word 0x4628b9d0 */
/* @0x2e8d84 .word 0x1000f8d9 */
/* @0x2e8d88 blls 0x43a678 <g_RomDisk+0x42e58> */
/* @0x2e8d8c blx 0x5a4d94 <g_SWFlineaavertbuff+0x51ccc> */
/* @0x2e8d90 andeq pc, r0, r10, asr #17 */
/* @0x2e8d94 .word 0xf8d9b938 */
/* @0x2e8d98 ldrbmi r0, [r9], -r0 */
/* @0x2e8d9c blx 0x1ae6d9e <b2_toiTime+0x138d8fa> */
/* @0x2e8da0 .word 0x0000f8da */
/* @0x2e8da4 .word 0xf89de187 */
/* @0x2e8da8 blhs 0x374e90 <_ZTS13C_UTF16String+0xbf3c> */
/* @0x2e8dac ldrtmi sp, [r3], -r4, lsl #2 */
/* @0x2e8db0 movwhs lr, #0x7af */
/* @0x2e8db4 ldrmi r9, [lr], -r8, lsl #6 */
/* @0x2e8db8 .word 0xf0039b0e */
/* @0x2e8dbc bhs 0x17299b0 <b2_toiTime+0xfd050c> */
/* @0x2e8dc0 sbcslt sp, r11, #3 */
/* @0x2e8dc4 .word 0xf0402b02 */
/* @0x2e8dc8 stmdbls r7, {r1, r3, r5, r6, r7, pc} */
/* @0x2e8dcc .word 0xf0002900 */
/* @0x2e8dd0 .word 0xf8dd80e1 */
/* @0x2e8dd4 .word 0xf1b9903c */
/* @0x2e8dd8 suble r0, r0, r0, lsl #30 */
/* @0x2e8ddc .word 0x21004648 */
/* @0x2e8de0 stc2l p7, c15, [r1, #-1012]! */
/* @0x2e8de4 stmdahs r0, {r0, r1, r9, r10, lr} */
/* @0x2e8de8 .word 0x4648d13c */
/* @0x2e8dec addhs r10, r0, #868352 */
/* @0x2e8df0 stc2l p7, c15, [sp, #1012] */
/* @0x2e8df4 bllt 0xfecfa608 <b2_toiTime+0xfffffffffe5a1164> */
/* @0x2e8df8 smullslo pc, r4, sp, r8 */
/* @0x2e8dfc .word 0xf89dbb8b */
/* @0x2e8e00 bllt 0x1fb5280 <b2_toiTime+0x185bddc> */
/* @0x2e8e04 .word 0x3126f89d */
/* @0x2e8e08 .word 0xf89dbb5b */
/* @0x2e8e0c mrcne p0, #0x2, r3, c10, c5, #0x6 */
/* @0x2e8e10 stmdale r6!, {r5, r9, r11, sp} */
/* @0x2e8e14 .word 0x2113f89d */
/* @0x2e8e18 bge 0x1897a88 <b2_toiTime+0x113e5e4> */
/* @0x2e8e1c .word 0xf8134413 */
/* @0x2e8e20 ldmiblt r3!, {r1, r7, r10, r11, r12, sp} ^ */
/* @0x2e8e24 .word 0x3127f89d */
/* @0x2e8e28 ldrle r0, [r10], #-1561 */
/* @0x2e8e2c .word 0x2128f89d */
/* @0x2e8e30 .word 0xf89d4628 */
/* @0x2e8e34 ldreq r1, [r2], #-298 */
/* @0x2e8e38 movwvs lr, #0x3a42 */
/* @0x2e8e3c .word 0x2129f89d */
/* @0x2e8e40 strbmi r4, [r9], -r11, lsl #6 */
/* @0x2e8e44 andhs lr, r2, #274432 */
/* @0x2e8e48 rsbslo r9, pc, #5120 */
/* @0x2e8e4c rsbseq pc, pc, #34 */
/* @0x2e8e50 addlo r9, r0, #0, #6 */
/* @0x2e8e54 .word 0xf000463b */
/* @0x2e8e58 strmi pc, [r3], -r1, lsl #21 */
/* @0x2e8e5c cmphs r5, #2 */
/* @0x2e8e60 movwhs lr, #0x2000 */
/* @0x2e8e64 bhs 0x3959d4 <ft_adobe_glyph_list+0x50b0> */
/* @0x2e8e68 stmdbls r5, {r3, r8, r12, lr, pc} */
/* @0x2e8e6c qasxmi r4, r8, r11 */
/* @0x2e8e70 .word 0x91002200 */
/* @0x2e8e74 .word 0xf0004649 */
/* @0x2e8e78 .word 0x4603fa71 */
/* @0x2e8e7c bhs 0x3959ec <ft_adobe_glyph_list+0x50c8> */
/* @0x2e8e80 bhs 0x185ce8c <b2_toiTime+0x11039e8> */
/* @0x2e8e84 stmdavs r2!, {r0, r2, r3, r4, r5, r6, r8, r12, lr, pc} */
/* @0x2e8e88 ldrble r0, [r10, #-0x752]! */
/* @0x2e8e8c .word 0xf10d682a */
/* @0x2e8e90 blge 0xbab838 <b2_toiTime+0x452394> */
/* @0x2e8e94 movwls r10, #0x92c */
/* @0x2e8e98 .word 0x91014628 */
/* @0x2e8e9c stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2e8ea0 movwls r9, #0x920b */
/* @0x2e8ea4 qaddls r4, r3, r10 */
/* @0x2e8ea8 stmvs r2!, {r0, r3, r6, r9, r10, lr} ^ */
/* @0x2e8eac .word 0xf8cd46c1 */
/* @0x2e8eb0 .word 0xf7fd8044 */
/* @0x2e8eb4 bmi 0xfe4e82e8 <b2_toiTime+0xfffffffffdd8ee44> */
/* @0x2e8eb8 ldmdbge r2, {r1, r8, r9, sp} */
/* @0x2e8ebc ldrbtmi r9, [r10], #-263 */
/* @0x2e8ec0 stmdbls sp, {r0, r2, r3, r9, r12, pc} */
/* @0x2e8ec4 subeq lr, r8, #1024 */
/* @0x2e8ec8 blo 0x3c3018 <error_g0017+0x1bcbc> */
/* @0x2e8ecc stmdale r5, {r0, r9, r11, sp} */
/* @0x2e8ed0 svceq #0xf1b9 */
/* @0x2e8ed4 andhs sp, r1, #-1073741810 */
/* @0x2e8ed8 and r9, r1, r6, lsl #4 */
/* @0x2e8edc .word 0x91062100 */
/* @0x2e8ee0 .word 0xf851a92c */
/* @0x2e8ee4 bhs 0x2f0f0c <FT_Done_Memory+0x7298> */
/* @0x2e8ee8 movwhs sp, #0x4133 */
/* @0x2e8eec .word 0xf85a9312 */
/* @0x2e8ef0 stmdblt r3, {r3, r12, sp} */
/* @0x2e8ef4 bge 0x743288 <g_SWFvertbuff+0x701c0> */
/* @0x2e8ef8 ldmdbge r2, {r3, r5, r9, r10, lr} */
/* @0x2e8efc .word 0xf7fe9315 */
/* @0x2e8f00 bls 0x4a78bc <SrcVerts+0x4900> */
/* @0x2e8f04 tstlt r2, r3, lsl #12 */
/* @0x2e8f08 bhs 0x1755a18 <b2_toiTime+0xffc574> */
/* @0x2e8f0c bllt 0x3dcf90 <error_g0017+0x35c34> */
/* @0x2e8f10 strtmi r9, [r8], -r5, lsl #22 */
/* @0x2e8f14 .word 0xf10d9911 */
/* @0x2e8f18 movwls r0, #0xc44 */
/* @0x2e8f1c .word 0xf853ab23 */
/* @0x2e8f20 ldrtmi r2, [r11], -r8 */
/* @0x2e8f24 andsgt pc, r0, sp, asr #17 */
/* @0x2e8f28 blx 0x924f30 <b2_toiTime+0x1cba8c> */
/* @0x2e8f2c ldrsbgt pc, [r0], -sp */
/* @0x2e8f30 strmi r2, [r3], -r0, lsl #2 */
/* @0x2e8f34 .word 0x0000f8dc */
/* @0x2e8f38 .word 0xf7fe9304 */
/* @0x2e8f3c blls 0x427984 <g_RomDisk+0x30164> */
/* @0x2e8f40 stmdbls r6, {r0, r1, r5, r6, r8, r12, sp, pc} */
/* @0x2e8f44 svclt #0x182900 */
/* @0x2e8f48 stmdbeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2e8f4c .word 0xf04fe001 */
/* @0x2e8f50 .word 0xf1080901 */
/* @0x2e8f54 .word 0xf1b80804 */
/* @0x2e8f58 .word 0xd1b20f24 */
/* @0x2e8f5c strtmi r2, [r5], -r0, lsl #8 */
/* @0x2e8f60 andne pc, r4, r10, asr r8 */
/* @0x2e8f64 stmdals r11, {r0, r4, r5, r8, r12, sp, pc} */
/* @0x2e8f68 .word 0xf7fe9304 */
/* @0x2e8f6c .word 0xf84af9e4 */
/* @0x2e8f70 blls 0x3fcf88 <g_RomDisk+0x5768> */
/* @0x2e8f74 stchs p4, c3, [r4], #-16 */
/* @0x2e8f78 blhs 0x31d748 */
/* @0x2e8f7c movwhs r11, #0x2f14 */
/* @0x2e8f80 .word 0xac0e2300 */
/* @0x2e8f84 stmdblt r11!, {r1, r2, r3, r8, r9, r12, pc} */
/* @0x2e8f88 ldrbmi r9, [r9], -pc, lsl #16 */
/* @0x2e8f8c blx 0x1ce6f8c <b2_toiTime+0x158dae8> */
/* @0x2e8f90 adds r6, r0, r0, lsr #16 */
/* @0x2e8f94 mlashs r8, sp, r8, pc */
/* @0x2e8f98 svclt #0x82a02 */
/* @0x2e8f9c stmdals pc, {r1, r2, r3, r9, r12, pc} */
/* @0x2e8fa0 .word 0xf7fe4659 */
/* @0x2e8fa4 rsbs pc, sp, r12, asr r10 */
/* @0x2e8fa8 .word 0x210cad0e */
/* @0x2e8fac .word 0xac109808 */
/* @0x2e8fb0 .word 0xf7fe462a */
/* @0x2e8fb4 .word 0xf8d5f8b8 */
/* @0x2e8fb8 strmi r8, [r1], -r0 */
/* @0x2e8fbc svceq #0xf1b8 */
/* @0x2e8fc0 stmdavs r2!, {r0, r1, r3, r5, r6, r8, r12, lr, pc} */
/* @0x2e8fc4 cdpvs p0, #0x1, c6, c0, c2, #0x4 */
/* @0x2e8fc8 .word 0xf7ff3010 */
/* @0x2e8fcc svchs #0xfca9 */
/* @0x2e8fd0 stmdavs r0!, {r4, r8, r9, r11, r12, lr, pc} */
/* @0x2e8fd4 .word 0xf7fe4641 */
/* @0x2e8fd8 eorvs pc, r8, r11, asr #26 */
/* @0x2e8fdc cmple sp, r0, lsl #16 */
/* @0x2e8fe0 stmdbge r12!, {r5, r11, sp, lr} */
/* @0x2e8fe4 stc2 p7, c15, [r8], #1020 */
/* @0x2e8fe8 stmdahs r0, {r3, r5, sp, lr} */
/* @0x2e8fec stmdavs r3!, {r1, r2, r4, r6, r8, r12, lr, pc} */
/* @0x2e8ff0 ldrvs r9, [r10, #0xa2c] */
/* @0x2e8ff4 ldmvs r10, {r0, r1, r5, r11, sp, lr} */
/* @0x2e8ff8 strle r0, [r12, #-0x7d5] */
/* @0x2e8ffc strhne pc, [r10], #-131 */
/* @0x2e9000 svclt #0x440408 */
/* @0x2e9004 .word 0xf8a34249 */
/* @0x2e9008 ldreq r1, [r1], r10, asr #32 */
/* @0x2e900c rfeia r3! */
/* @0x2e9010 .word 0xf8a3104a */
/* @0x2e9014 ldreq r1, [r3, lr, asr #32] */
/* @0x2e9018 stmdavs r3!, {r0, r1, r2, r4, r10, r12, lr, pc} */
/* @0x2e901c vst1.8 {d18, d19, d20, d21}, [pc], r0 */
/* @0x2e9020 .word 0xf8d33180 */
/* @0x2e9024 stm r3, {r7, r12, sp} */
/* @0x2e9028 addsvs r0, r10, r6 */
/* @0x2e902c cmpvs r10, r10, lsl r1 */
/* @0x2e9030 ldrvs r2, [r10], #-513 */
/* @0x2e9034 .word 0xf88322ff */
/* @0x2e9038 bls 0x431120 <g_RomDisk+0x39900> */
/* @0x2e903c bhs 0x3013a8 <TT_New_Context+0x11a0> */
/* @0x2e9040 stmdavs r3!, {r2, r3, r5, r12, lr, pc} */
/* @0x2e9044 andvs r9, r11, r5, lsl #18 */
/* @0x2e9048 andhs lr, r0, #50 */
/* @0x2e904c stmdavs r3!, {r0, r4, r9, r10, lr} */
/* @0x2e9050 addmi r6, r2, #216, #18 */
/* @0x2e9054 bvs 0xa9fbe0 <b2_toiTime+0x34673c> */
/* @0x2e9058 ldmdane r3!, {r4, r8} */
/* @0x2e905c strteq r5, [pc], #-2613 */
/* @0x2e9060 rsbmi r11, sp, #68, #30 */
/* @0x2e9064 ldmvs sp, {r0, r2, r4, r5, r9, r12, lr} */
/* @0x2e9068 svclt #0xbc2d00 */
/* @0x2e906c addsvs r4, sp, sp, ror #4 */
/* @0x2e9070 stchs p8, c6, [r0, #-884] */
/* @0x2e9074 rsbmi r11, sp, #188, #30 */
/* @0x2e9078 mrcpl p0, #0x1, r6, c5, c13, #0x6 */
/* @0x2e907c blle 0x434484 <g_RomDisk+0x3cc64> */
/* @0x2e9080 stchs p8, c6, [r0, #-628] */
/* @0x2e9084 ldmvs sp, {r1, r8, r9, r11, r12, lr, pc} ^ */
/* @0x2e9088 ble 0x3f4490 <VS_Common+0x1134> */
/* @0x2e908c eorspl r8, r1, #89 */
/* @0x2e9090 addsvs r6, r9, r9, asr r0 */
/* @0x2e9094 andlo r6, r1, #217 */
/* @0x2e9098 ldrsblt lr, [r8, -r9] */
/* @0x2e909c .word 0xf7ff6820 */
/* @0x2e90a0 mul r5, sp, sp */
/* @0x2e90a4 tstlt r9, r0, lsl r9 */
/* @0x2e90a8 ldrtmi r9, [r2], -r8, lsl #16 */
/* @0x2e90ac ldc2l p7, c15, [r6, #-1020] */
/* @0x2e90b0 and r9, r0, lr, lsl #16 */
/* @0x2e90b4 stmdbls r12, {r1, r2, sp} */
/* @0x2e90b8 stmdavs r11, {r0, r2, r4, r6, r9, r11, r12, pc} */
/* @0x2e90bc mulle r1, r10, r2 */
/* @0x2e90c0 b 0xfe5267fc <b2_toiTime+0xfffffffffddcd358> */
/* @0x2e90c4 pop {r0, r1, r2, r4, r6, r12, sp, pc} */
/* @0x2e90c8 svclt #0x8ff0 */
/* @0x2e90cc andseq r4, r0, r10, lsl #26 */
/* @0x2e90d0 andeq r5, r10, r2, lsl r10 */
/* @0x2e90d4 andeq pc, pc, r6, lsr #21 */

/* ── FUNC 0x2e90d8 · FT_New_Face · size=34 · insn=17 */
/* @0x2e90d8 push {r4, lr} */
/* @0x2e90da sub sp, #0x28 */
/* @0x2e90dc cbz r1, 0x2e90f4 <FT_New_Face+0x1c> */
/* @0x2e90de str r1, [sp, #0x14] */
/* @0x2e90e0 movs r1, #0x0 */
/* @0x2e90e2 str r1, [sp, #0x18] */
/* @0x2e90e4 movs r1, #0x1 */
/* @0x2e90e6 str r1, [sp] */
/* @0x2e90e8 add r1, sp, #0x8 */
/* @0x2e90ea movs r4, #0x4 */
/* @0x2e90ec str r4, [sp, #0x8] */
/* @0x2e90ee bl 0x2e8c38 <FT_Done_Face+0x5c> */
/* @0x2e90f0 and pc, r0, r3, lsr #27 */
/* @0x2e90f2 b 0x2e90f6 <FT_New_Face+0x1e> */
/* @0x2e90f4 movs r0, #0x6 */
/* @0x2e90f6 add sp, #0x28 */
/* @0x2e90f8 pop {r4, pc} */

/* ── FUNC 0x2e90fc · anon_2e90fc · size=1520 · insn=381 */
/* @0x2e90fc svcmi #0xf0e92d */
/* @0x2e9100 strmi r11, [r7], -r11, lsl #1 */
/* @0x2e9104 .word 0x469b4615 */
/* @0x2e9108 ldrsbge pc, [r0], #-141 */
/* @0x2e910c strmi r6, [r8], r6, lsl #16 */
/* @0x2e9110 .word 0xf10db1a9 */
/* @0x2e9114 ldrtmi r0, [r0], -r8, lsl #18 */
/* @0x2e9118 strbmi r2, [r10], -r8, lsr #2 */
/* @0x2e911c .word 0xf803f7fe */
/* @0x2e9120 strmi r9, [r4], -r2, lsl #20 */
/* @0x2e9124 qasxmi r11, r10, r10 */
/* @0x2e9128 .word 0xf7fd4641 */
/* @0x2e912c bmi 0xa27fec <b2_toiTime+0x2ceb48> */
/* @0x2e9130 .word 0x61a2447a */
/* @0x2e9134 strhs lr, [r0], #-0 */
/* @0x2e9138 teqlt r5, r2, lsl #26 */
/* @0x2e913c strhs lr, [r6, #-0x0] */
/* @0x2e9140 .word 0x46414630 */
/* @0x2e9144 .word 0xf8f7f7fe */
/* @0x2e9148 movwhs lr, #0x2025 */
/* @0x2e914c movwls r9, #0x2406 */
/* @0x2e9150 svceq #0xf1ba */
/* @0x2e9154 ldrtmi sp, [r8], -r6 */
/* @0x2e9158 movwhs r4, #0xa651 */
/* @0x2e915c .word 0xf7fc9302 */
/* @0x2e9160 andls pc, r7, r7, asr #29 */
/* @0x2e9164 ldrtmi r2, [r8], -r0, lsl #6 */
/* @0x2e9168 strbmi r9, [r9], -r0, lsl #6 */
/* @0x2e916c blls 0x83aadc <b2_toiTime+0xe1638> */
/* @0x2e9170 stc2l p7, c15, [r2, #-1020]! */
/* @0x2e9174 ldmdblt r0!, {r0, r1, r2, r9, r10, lr} */
/* @0x2e9178 ldmdavs r3, {r0, r2, r4, r9, r11, r12, pc} */
/* @0x2e917c vld2.32 {d6, d7}, [r2:64], r10 */
/* @0x2e9180 addsvs r6, r10, r0, lsl #5 */
/* @0x2e9184 strtmi lr, [r0], -r7 */
/* @0x2e9188 .word 0xf7fd463d */
/* @0x2e918c ldrtmi pc, [r0], -r6, lsl #23 */
/* @0x2e9190 .word 0xf7fe4621 */
/* @0x2e9194 .word 0x4628f8d0 */
/* @0x2e9198 pop {r0, r1, r3, r12, sp, pc} */
/* @0x2e919c svclt #0x8ff0 */
/* @0x2e91a0 .word 0xffffeb7d */
/* @0x2e91a4 svcmi #0xf0e92d */
/* @0x2e91a8 cdpne p0, #0x1, c11, c5, c11, #0x4 */
/* @0x2e91ac movwls r4, #0x760c */
/* @0x2e91b0 adclt r11, sp, #200, #30 */
/* @0x2e91b4 cdpge p8, #0x0, c6, c9, c3, #0x0 */
/* @0x2e91b8 strmi r9, [r8], -r5 */
/* @0x2e91bc .word 0xf7fd9302 */
/* @0x2e91c0 .word 0x4631fbbf */
/* @0x2e91c4 strtmi r9, [r0], -r3 */
/* @0x2e91c8 ldc2l p7, c15, [r12, #1012]! */
/* @0x2e91cc svchs #0x9f09 */
/* @0x2e91d0 blmi 0x1a5d754 <b2_toiTime+0x13042b0> */
/* @0x2e91d4 .word 0xd1624298 */
/* @0x2e91d8 ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2e91dc ldc2 p7, c15, [r2], {253} */
/* @0x2e91e0 .word 0x8024f8dd */
/* @0x2e91e4 .word 0xf1b89006 */
/* @0x2e91e8 cmple sp, r0, lsl #30 */
/* @0x2e91ec .word 0x21064620 */
/* @0x2e91f0 blx 0xfeaa71ee <b2_toiTime+0xfffffffffe34dd4a> */
/* @0x2e91f4 stmdahs r0, {r0, r3, r12, pc} */
/* @0x2e91f8 strmi sp, [r1], r12, asr #2 */
/* @0x2e91fc strmi r4, [r3], r2, lsl #13 */
/* @0x2e9200 .word 0xf04f4680 */
/* @0x2e9204 bls 0x477208 <g_RomDisk+0x7f9e8> */
/* @0x2e9208 ble 0x12fa850 <b2_toiTime+0xba13ac> */
/* @0x2e920c qasxmi r4, r0, r1 */
/* @0x2e9210 ldc2l p7, c15, [r8, #1012] */
/* @0x2e9214 andls r9, r4, r9, lsl #18 */
/* @0x2e9218 qadd8mi r11, r0, r9 */
/* @0x2e921c .word 0xf7fd2104 */
/* @0x2e9220 andls pc, r9, r7, lsl #23 */
/* @0x2e9224 ldrtmi r11, [r1], -r8, ror #18 */
/* @0x2e9228 .word 0xf7fd4620 */
/* @0x2e922c stmdbls r9, {r0, r1, r3, r6, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2e9230 ldmdblt r1!, {r0, r1, r7, r9, r10, lr} */
/* @0x2e9234 ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2e9238 stc2l p7, c15, [r4, #1012] */
/* @0x2e923c stmdals r9, {r1, r7, r9, r10, lr} */
/* @0x2e9240 stmdals r9, {r3, r8, r12, sp, pc} */
/* @0x2e9244 bls 0x42131c <g_RomDisk+0x29afc> */
/* @0x2e9248 addsmi r4, r10, #64, #22 */
/* @0x2e924c stchs p1, c13, [r0, #-40] */
/* @0x2e9250 streq pc, [r1, -r7, lsl #2] */
/* @0x2e9254 bleq 0x8a5688 <b2_toiTime+0x14c1e4> */
/* @0x2e9258 beq 0x8a5908 <b2_toiTime+0x14c464> */
/* @0x2e925c stmdbeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2e9260 eor sp, r5, r0, lsl r10 */
/* @0x2e9264 blmi 0x118fa7c <b2_toiTime+0xa365d8> */
/* @0x2e9268 swple r4, r10, [r9] */
/* @0x2e926c .word 0xf1072d00 */
/* @0x2e9270 .word 0xf10b0701 */
/* @0x2e9274 .word 0xf1aa0b18 */
/* @0x2e9278 pkhbtmi r0, r1, r8, lsl #20 */
/* @0x2e927c ands sp, r5, r2, lsl #20 */
/* @0x2e9280 blle 0x334688 */
/* @0x2e9284 andsle r4, r2, pc, lsr #5 */
/* @0x2e9288 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x2e928c strhhs lr, [lr], r11 */
/* @0x2e9290 ldrtmi lr, [r8], -lr */
/* @0x2e9294 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2e9298 strbmi r4, [r11], r10, asr #13 */
/* @0x2e929c ldrtmi lr, [r9], r8 */
/* @0x2e92a0 .word 0x46bb46ba */
/* @0x2e92a4 and r2, r3, r2 */
/* @0x2e92a8 ldrb r4, [r3, r0, asr #12]! */
/* @0x2e92ac andhs lr, r0, r0 */
/* @0x2e92b0 stmdahs r0, {r0, r3, r12, pc} */
/* @0x2e92b4 stmdavs r1!, {r3, r4, r5, r8, r12, lr, pc} ^ */
/* @0x2e92b8 stmdble r2, {r0, r1, r3, r7, r8, r10, lr} */
/* @0x2e92bc movwls r2, #0x9308 */
/* @0x2e92c0 bl 0xff5e1390 <b2_toiTime+0xfffffffffee87eec> */
/* @0x2e92c4 strmi r0, [r10, #0x101] */
/* @0x2e92c8 stmdbls r3, {r3, r4, r5, r6, r7, r11, r12, lr, pc} */
/* @0x2e92cc ldrbmi r4, [r9], #-1568 */
/* @0x2e92d0 blx 0xffd672cc <b2_toiTime+0xffffffffff60de28> */
/* @0x2e92d4 bllt 0x110d300 <b2_toiTime+0x9b3e5c> */
/* @0x2e92d8 stmdals r2, {r1, r4, r5, r9, r10, lr} */
/* @0x2e92dc .word 0xf7fd4651 */
/* @0x2e92e0 bls 0x568f70 <g_SWFlineaavertbuff+0x15ea8> */
/* @0x2e92e4 ldmiblt r10!, {r1, r2, r9, r10, lr} ^ */
/* @0x2e92e8 ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2e92ec .word 0xf7fd4652 */
/* @0x2e92f0 andls pc, r9, lr, asr #22 */
/* @0x2e92f4 stmdals r2, {r5, r8, r12, sp, pc} */
/* @0x2e92f8 .word 0xf7fe4631 */
/* @0x2e92fc ands pc, r3, r12, lsl r8 */
/* @0x2e9300 strbvc lr, [r5, #0xa05]! */
/* @0x2e9304 svceq #0xf1b9 */
/* @0x2e9308 bmi 0x79d318 <b2_toiTime+0x43e74> */
/* @0x2e930c and r4, r1, r10, ror r4 */
/* @0x2e9310 ldrbtmi r4, [r10], #-2577 */
/* @0x2e9314 ldrtmi r9, [r1], -r7, lsl #22 */
/* @0x2e9318 ldrbmi r9, [r2], -r0, lsl #4 */
/* @0x2e931c movwls r9, #0x1805 */
/* @0x2e9320 .word 0xf7ff462b */
/* @0x2e9324 andls pc, r9, r11, ror #29 */
/* @0x2e9328 mlalo r4, sp, r8, pc */
/* @0x2e932c andle r2, r1, r2, lsl #22 */
/* @0x2e9330 and r9, r5, r9, lsl #16 */
/* @0x2e9334 stmdbls r3, {r5, r9, r10, lr} */
/* @0x2e9338 blx 0xff067334 <b2_toiTime+0xfffffffffe90de90> */
/* @0x2e933c rscsle r2, r7, r0, lsl #16 */
/* @0x2e9340 pop {r0, r1, r3, r12, sp, pc} */
/* @0x2e9344 svclt #0x8ff0 */
/* @0x2e9348 ldrbtvc r7, [r9], #-49 */
/* @0x2e934c movtmi r4, #0x9420 */
/* @0x2e9350 ldrbpl r5, [r9], #-49 */
/* @0x2e9354 andeq r5, r10, r1, ror r4 */
/* @0x2e9358 andeq r5, r10, pc, ror #8 */
/* @0x2e935c svcmi #0xf0e92d */
/* @0x2e9360 stmdavs r3, {r1, r2, r3, r4, r9, r10, lr} */
/* @0x2e9364 pkhbtmi r11, r0, r3, lsl #1 */
/* @0x2e9368 movwls r4, #0x860d */
/* @0x2e936c movwls r10, #0xb0e */
/* @0x2e9370 .word 0xf7fdab0d */
/* @0x2e9374 strmi pc, [r7], -sp, ror #23 */
/* @0x2e9378 .word 0xf0402800 */
/* @0x2e937c blmi 0xfea89a28 <b2_toiTime+0xfffffffffe330584> */
/* @0x2e9380 .word 0xf10d2401 */
/* @0x2e9384 .word 0xf10d0b3c */
/* @0x2e9388 .word 0xf8cd0a40 */
/* @0x2e938c strbmi r11, [r0], -r8 */
/* @0x2e9390 andseq lr, r8, sp, lsl #17 */
/* @0x2e9394 .word 0xf8cd4629 */
/* @0x2e9398 bls 0x6513d0 <g_SWFaavertbuff+0x7e308> */
/* @0x2e939c .word 0xf7ff9b0e */
/* @0x2e93a0 stmdahs r0, {r0, r1, r3, r8, r11, r12, sp, lr, pc} */
/* @0x2e93a4 .word 0x810af040 */
/* @0x2e93a8 strtmi r9, [r6], #-2831 */
/* @0x2e93ac ldrls r4, [r1], #-678 */
/* @0x2e93b0 blls 0x70dfdc <g_SWFvertbuff+0x3af14> */
/* @0x2e93b4 .word 0xf8d8930a */
/* @0x2e93b8 movwls r3, #0xb000 */
/* @0x2e93bc rscshi pc, r2, r0, lsl #4 */
/* @0x2e93c0 pkhbtmi r10, r1, r1, lsl #24 */
/* @0x2e93c4 blls 0x57abe4 <g_SWFlineaavertbuff+0x27b1c> */
/* @0x2e93c8 ble 0xb79e48 <b2_toiTime+0x4209a4> */
/* @0x2e93cc strtmi r9, [r8], -r9, lsl #22 */
/* @0x2e93d0 eorne pc, r6, r3, asr r8 */
/* @0x2e93d4 blx 0x1ce73d0 <b2_toiTime+0x158df2c> */
/* @0x2e93d8 stmdahs r0, {r0, r4, r12, pc} */
/* @0x2e93dc rschi pc, r1, r0, asr #32 */
/* @0x2e93e0 strtmi r4, [r1], -r8, lsr #12 */
/* @0x2e93e4 stc2l p7, c15, [lr], #1012 */
/* @0x2e93e8 blhs 0x310034 <af_shaper_get_elem+0x58a2> */
/* @0x2e93ec sbcshi pc, r9, r0, asr #32 */
/* @0x2e93f0 svcvc #0x80f1b0 */
/* @0x2e93f4 .word 0xf1c0d207 */
/* @0x2e93f8 .word 0xf10913ff */
/* @0x2e93fc .word 0xf5030206 */
/* @0x2e9400 addsmi r4, r3, #-67108863 */
/* @0x2e9404 movwhs sp, #0x9201 */
/* @0x2e9408 andlo lr, r6, r9 */
/* @0x2e940c strmi r3, [r1], #1537 */
/* @0x2e9410 .word 0xf109e7d9 */
/* @0x2e9414 movwls r0, #0x5302 */
/* @0x2e9418 stmdale r2, {r0, r2, r8, r9, r11, sp} */
/* @0x2e941c tstls r1, #671088640 */
/* @0x2e9420 blge 0x761724 <b2_toiTime+0x8280> */
/* @0x2e9424 stmdbls r5, {r0, r1, r3, r11, r12, pc} */
/* @0x2e9428 movwls r4, #0x761a */
/* @0x2e942c mrc2 p7, #0x3, apsr_nzcv, c11, c13, #0x7 */
/* @0x2e9430 .word 0x46049e11 */
/* @0x2e9434 .word 0xf0402e00 */
/* @0x2e9438 .word 0xf04f80b4 */
/* @0x2e943c .word 0xf04f0b01 */
/* @0x2e9440 .word 0xf8800a02 */
/* @0x2e9444 strhs r11, [r6, -r1] */
/* @0x2e9448 andslt pc, r8, sp, asr #17 */
/* @0x2e944c addhs r4, r0, #187695104 */
/* @0x2e9450 andvc r7, r2, r6, lsl #1 */
/* @0x2e9454 smlabtvc r6, r6, r0, r7 */
/* @0x2e9458 blls 0x585978 <g_SWFlineaavertbuff+0x328b0> */
/* @0x2e945c ble 0x14baad0 <b2_toiTime+0xd6162c> */
/* @0x2e9460 strtmi r9, [r8], -r9, lsl #22 */
/* @0x2e9464 eorne pc, r11, r3, asr r8 */
/* @0x2e9468 blx 0xa67464 <b2_toiTime+0x30dfc0> */
/* @0x2e946c stmdahs r0, {r0, r4, r12, pc} */
/* @0x2e9470 addhi pc, pc, r0, asr #32 */
/* @0x2e9474 qadd16mi r10, r8, r1 */
/* @0x2e9478 stc2 p7, c15, [r4], #1012 */
/* @0x2e947c .word 0x46029911 */
/* @0x2e9480 .word 0xf0402900 */
/* @0x2e9484 stmdahs r0, {r1, r2, r7, pc} */
/* @0x2e9488 movwhs sp, #0x9a02 */
/* @0x2e948c add r9, r0, r1, lsl r3 */
/* @0x2e9490 qadd16mi r10, r8, r1 */
/* @0x2e9494 .word 0xf7fd9204 */
/* @0x2e9498 ldmdbls r1, {r0, r2, r4, r5, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2e949c stmdbhs r0, {r2, r9, r11, r12, pc} */
/* @0x2e94a0 b 0x1adda84 <b2_toiTime+0x13845e0> */
/* @0x2e94a4 .word 0xf04f2c20 */
/* @0x2e94a8 tstls r1, #671088640 */
/* @0x2e94ac bhs 0x39d5e0 <ft_adobe_glyph_list+0xccbc> */
/* @0x2e94b0 svclt #0x8c9b06 */
/* @0x2e94b4 strmi r3, [r10], -r2, lsl #20 */
/* @0x2e94b8 swple r4, r12, [r2] */
/* @0x2e94bc shadd16mi r4, r9, r6 */
/* @0x2e94c0 blls 0x46158c <g_RomDisk+0x69d6c> */
/* @0x2e94c4 mrseq pc, apsr */
/* @0x2e94c8 stmdale r2!, {r0, r3, r4, r7, r9, lr} ^ */
/* @0x2e94cc andeq lr, r10, r4, lsl #22 */
/* @0x2e94d0 svceq #0x5f1bc */
/* @0x2e94d4 andvs pc, r10, r4, lsl #16 */
/* @0x2e94d8 vnmlahs.f32 s28, s12, s30 */
/* @0x2e94dc and pc, r1, r0, lsl #17 */
/* @0x2e94e0 vnmlami.f32 s28, s12, s30 */
/* @0x2e94e4 and pc, r2, r0, lsl #17 */
/* @0x2e94e8 andsvs lr, r6, pc, asr #20 */
/* @0x2e94ec .word 0xd1065460 */
/* @0x2e94f0 andhs r9, r10, #5120 */
/* @0x2e94f4 ldcne p2, c9, [r10], #68 */
/* @0x2e94f8 stmdale r10, {r1, r3, r4, r7, r9, lr} ^ */
/* @0x2e94fc blls 0x4615ac <g_RomDisk+0x69d8c> */
/* @0x2e9500 addsmi r1, r9, #11840 */
/* @0x2e9504 .word 0xf06fd845 */
/* @0x2e9508 .word 0xf107037f */
/* @0x2e950c strbpl r0, [r3, #0xa02]! */
/* @0x2e9510 ldrmi r4, [r6], -r7, lsr #8 */
/* @0x2e9514 movweq pc, #0x4f */
/* @0x2e9518 andgt pc, r1, r7, lsl #17 */
/* @0x2e951c andlo pc, r10, r4, lsl #16 */
/* @0x2e9520 ldrshvc r7, [r11, -r11]! */
/* @0x2e9524 strbmi r7, [r9, #-0x17b] */
/* @0x2e9528 stmne pc, {r0, r1, r4, r5, r11, r12, lr, pc} */
/* @0x2e952c ldmdale r0!, {r0, r1, r2, r3, r6, r8, r10, lr} */
/* @0x2e9530 strtmi r4, [r1], #-1576 */
/* @0x2e9534 andsgt pc, r0, sp, asr #17 */
/* @0x2e9538 blx 0xd67534 <b2_toiTime+0x60e090> */
/* @0x2e953c ldrsbgt pc, [r0], -sp */
/* @0x2e9540 tstlt r0, r1, lsl r0 */
/* @0x2e9544 .word 0xf8dde025 */
/* @0x2e9548 .word 0xf10bc018 */
/* @0x2e954c .word 0xf8cd0b01 */
/* @0x2e9550 usada8 r2, r8, r0, r12 */
/* @0x2e9554 strbpl r2, [r1, #0x180]! */
/* @0x2e9558 blls 0x43a5fc <g_RomDisk+0x42ddc> */
/* @0x2e955c rsbsvc r2, r9, r3, lsl #2 */
/* @0x2e9560 addsmi r4, r9, #1358954496 */
/* @0x2e9564 bl 0x41f5c0 <g_RomDisk+0x27da0> */
/* @0x2e9568 .word 0xf804030a */
/* @0x2e956c beq 0xf0159c <b2_toiTime+0x7a80f8> */
/* @0x2e9570 ldceq p0, c7, [r0], #-352 */
/* @0x2e9574 mrceq p0, #0x1, r7, c6, c8, #0x4 */
/* @0x2e9578 strbmi r4, [r0], -r1, lsr #22 */
/* @0x2e957c strtmi r5, [r1], -r6, ror #8 */
/* @0x2e9580 movwls r4, #0x47b */
/* @0x2e9584 movwls r9, #0x1b1c */
/* @0x2e9588 .word 0xf7ff2300 */
/* @0x2e958c .word 0x4604fdb7 */
/* @0x2e9590 blls 0x7615b8 <b2_toiTime+0x8114> */
/* @0x2e9594 movwhs r11, #0x110b */
/* @0x2e9598 stmdals r11, {r0, r4, r8, r9, r12, pc} */
/* @0x2e959c .word 0xf7fd4621 */
/* @0x2e95a0 .word 0x9c11feca */
/* @0x2e95a4 stmdbls pc, {r3, r11, r12, pc} */
/* @0x2e95a8 mcr2 p7, #0x6, pc, c5, c13, #0x7 */
/* @0x2e95ac .word 0xf0402c00 */
/* @0x2e95b0 bls 0xa09800 <b2_toiTime+0x2b035c> */
/* @0x2e95b4 andhs r6, r1, #1245184 */
/* @0x2e95b8 add r6, r12, r10, lsl r0 */
/* @0x2e95bc strbmi r4, [r0], -pc, lsl #22 */
/* @0x2e95c0 andge pc, r12, sp, asr #17 */
/* @0x2e95c4 bls 0x63ae70 <g_SWFaavertbuff+0x67da8> */
/* @0x2e95c8 stmeq r8, {r0, r2, r3, r7, r11, sp, lr, pc} */
/* @0x2e95cc .word 0xf7fe9b0e */
/* @0x2e95d0 stmdahs r0, {r0, r1, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e95d4 svcls #0x10d17e */
/* @0x2e95d8 shasxmi r4, r9, r0 */
/* @0x2e95dc .word 0xec06f02f */
/* @0x2e95e0 .word 0xf8d89b0f */
/* @0x2e95e4 b 0x1eb95ec <b2_toiTime+0x1760148> */
/* @0x2e95e8 strmi r0, [r10, #0xa01] */
/* @0x2e95ec selmi r11, r10, r8 */
/* @0x2e95f0 blle 0x4bace0 <SrcVerts+0x17d24> */
/* @0x2e95f4 rsb r2, r1, r1, lsl #8 */
/* @0x2e95f8 subpl r5, pc, r4, asr r3 */
/* @0x2e95fc .word 0x73666e74 */
/* @0x2e9600 andeq r5, r10, r1, lsl #4 */
/* @0x2e9604 eorls pc, r10, r3, asr r8 */
/* @0x2e9608 strbmi r4, [r9], -r8, lsr #12 */
/* @0x2e960c .word 0xf94bf7fd */
/* @0x2e9610 stmdahs r0, {r0, r4, r12, pc} */
/* @0x2e9614 svcge #0x11d14d */
/* @0x2e9618 ldrtmi r4, [r9], -r8, lsr #12 */
/* @0x2e961c blx 0xff7a761a <b2_toiTime+0xffffffffff04e176> */
/* @0x2e9620 .word 0x46069b11 */
/* @0x2e9624 .word 0xd1442b00 */
/* @0x2e9628 stclle p8, c2, [r3, #0]! */
/* @0x2e962c svcvc #0x80f1b0 */
/* @0x2e9630 strbmi sp, [r0], -r1, asr #4 */
/* @0x2e9634 ldrbmi r4, [r2], -r9, lsr #12 */
/* @0x2e9638 .word 0xf7ff9b1c */
/* @0x2e963c ldrhls pc, [r1], -r3 */
/* @0x2e9640 eorsle r2, r6, r0, lsl #16 */
/* @0x2e9644 .word 0xf1094628 */
/* @0x2e9648 .word 0xf7fd0104 */
/* @0x2e964c andsls pc, r1, r12, lsr #18 */
/* @0x2e9650 .word 0xd12e2800 */
/* @0x2e9654 qasxmi r4, r0, r10 */
/* @0x2e9658 .word 0xf7fd4631 */
/* @0x2e965c blls 0x768bf4 <b2_toiTime+0xf750> */
/* @0x2e9660 bllt 0x17bae84 <b2_toiTime+0x10619e0> */
/* @0x2e9664 ldrtmi r4, [r9], -r8, lsr #12 */
/* @0x2e9668 .word 0xf7fd4632 */
/* @0x2e966c mulsls r1, r0, r9 */
/* @0x2e9670 strtmi r11, [r0], -r0, lsr #2 */
/* @0x2e9674 .word 0xf7fd4639 */
/* @0x2e9678 ands pc, r10, lr, asr lr */
/* @0x2e967c stcle p14, c2, [r9, #-16] */
/* @0x2e9680 shadd16mi r4, r8, r7 */
/* @0x2e9684 ldrbtmi r2, [r9], #-516 */
/* @0x2e9688 b 0xff9a6dc4 <b2_toiTime+0xffffffffff24d920> */
/* @0x2e968c blmi 0x855b34 <b2_toiTime+0xfc690> */
/* @0x2e9690 and r4, r4, r11, ror r4 */
/* @0x2e9694 ldrbtmi r4, [r11], #-2836 */
/* @0x2e9698 blmi 0x8216a4 <b2_toiTime+0xc8200> */
/* @0x2e969c movwls r4, #0x47b */
/* @0x2e96a0 blls 0x9fafa8 <b2_toiTime+0x2a1b04> */
/* @0x2e96a4 shasxmi r4, r2, r9 */
/* @0x2e96a8 movwhs r9, #0x301 */
/* @0x2e96ac stc2 p7, c15, [r6, #-1020]! */
/* @0x2e96b0 .word 0x9c119011 */
/* @0x2e96b4 strhs lr, [r9], #-2 */
/* @0x2e96b8 ldrmi lr, [r12], -r0 */
/* @0x2e96bc stmdbls pc, {r3, r11, r12, pc} */
/* @0x2e96c0 mrc2 p7, #0x1, apsr_nzcv, c9, c13, #0x7 */
/* @0x2e96c4 blls 0xa17bbc <b2_toiTime+0x2be718> */
/* @0x2e96c8 blls 0x703738 <g_SWFvertbuff+0x30670> */
/* @0x2e96cc and r6, r2, r3, lsl r0 */
/* @0x2e96d0 and r4, r0, r4, lsl #12 */
/* @0x2e96d4 strtmi r4, [r0], -r4, lsl #12 */
/* @0x2e96d8 pop {r0, r1, r4, r12, sp, pc} */
/* @0x2e96dc svclt #0x8ff0 */
/* @0x2e96e0 andeq r5, r10, r5, lsl #2 */
/* @0x2e96e4 muleq r10, r0, r0 */
/* @0x2e96e8 andeq r5, r10, r10, lsl #1 */
/* @0x2e96ec andeq r5, r10, r11, ror #1 */

/* ── FUNC 0x2e96f0 · FT_New_Memory_Face · size=38 · insn=19 */
/* @0x2e96f0 push {r4, lr} */
/* @0x2e96f2 sub sp, #0x28 */
/* @0x2e96f4 cbz r1, 0x2e9710 <FT_New_Memory_Face+0x20> */
/* @0x2e96f6 movs r4, #0x1 */
/* @0x2e96f8 str r1, [sp, #0xc] */
/* @0x2e96fa str r2, [sp, #0x10] */
/* @0x2e96fc add r1, sp, #0x8 */
/* @0x2e96fe movs r2, #0x0 */
/* @0x2e9700 str r4, [sp] */
/* @0x2e9702 str r2, [sp, #0x18] */
/* @0x2e9704 mov r2, r3 */
/* @0x2e9706 ldr r3, [sp, #0x30] */
/* @0x2e9708 str r4, [sp, #0x8] */
/* @0x2e970a bl 0x2e8c38 <FT_Done_Face+0x5c> */
/* @0x2e970c mul r0, r5, r10 */
/* @0x2e970e b 0x2e9712 <FT_New_Memory_Face+0x22> */
/* @0x2e9710 movs r0, #0x6 */
/* @0x2e9712 add sp, #0x28 */
/* @0x2e9714 pop {r4, pc} */

/* ── FUNC 0x2e9716 · FT_Open_Face · size=14 · insn=7 */
/* @0x2e9716 push {r0, r1, r4, lr} */
/* @0x2e9718 movs r4, #0x1 */
/* @0x2e971a str r4, [sp] */
/* @0x2e971c bl 0x2e8c38 <FT_Done_Face+0x5c> */
/* @0x2e971e andlt pc, r2, r12, lsl #21 */
/* @0x2e9720 add sp, #0x8 */
/* @0x2e9722 pop {r4, pc} */
