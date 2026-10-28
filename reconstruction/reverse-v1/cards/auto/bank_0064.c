/* libyoyo.so 覆盖卡组 0064
 * 函数 0x12fdc0..0x1337ac，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x12fdc0 · F_RoomSetCode(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x12fdc0 push {r3, r4, r5, lr} */
/* @0x12fdc4 mov r1, #0 */
/* @0x12fdc8 ldr r4, [sp, #0x10] */
/* @0x12fdcc mov r0, r4 */
/* @0x12fdd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12fdd4 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12fdd8 subs r5, r0, #0 */
/* @0x12fddc popeq {r3, r4, r5, pc} */
/* @0x12fde0 mov r0, r4 */
/* @0x12fde4 mov r1, #1 */
/* @0x12fde8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12fdec mov r4, r0 */
/* @0x12fdf0 ldr r0, [r5, #0x68] */
/* @0x12fdf4 cmp r0, #0 */
/* @0x12fdf8 beq 0x12fe00 <_Z13F_RoomSetCodeR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12fdfc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x12fe00 mov r0, r4 */
/* @0x12fe04 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x12fe08 str r0, [r5, #0x68] */
/* @0x12fe0c pop {r3, r4, r5, pc} */

/* ── FUNC 0x12fe10 · F_RoomGetViewport(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0x12fe10 push {r4, r5, r6, lr} */
/* @0x12fe14 sub sp, sp, #32 */
/* @0x12fe18 mov r1, #0 */
/* @0x12fe1c mov r5, r0 */
/* @0x12fe20 ldr r4, [sp, #0x30] */
/* @0x12fe24 mov r0, r4 */
/* @0x12fe28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12fe2c mov r1, #1 */
/* @0x12fe30 mov r6, r0 */
/* @0x12fe34 mov r0, r4 */
/* @0x12fe38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12fe3c mov r4, r0 */
/* @0x12fe40 mov r0, r6 */
/* @0x12fe44 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x12fe48 cmp r0, #0 */
/* @0x12fe4c beq 0x12febc <_Z17F_RoomGetViewportR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x12fe50 cmp r4, #7 */
/* @0x12fe54 bhi 0x12febc <_Z17F_RoomGetViewportR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x12fe58 add r4, r4, #18 */
/* @0x12fe5c ldr r12, [r0, r4, lsl #2] */
/* @0x12fe60 cmp r12, #0 */
/* @0x12fe64 beq 0x12febc <_Z17F_RoomGetViewportR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x12fe68 vldr s13, [r12, #20] */
/* @0x12fe6c vcvt.f64.s32 d7, s13 */
/* @0x12fe70 ldrb r2, [r12] */
/* @0x12fe74 mov r0, r5 */
/* @0x12fe78 mov r1, #5 */
/* @0x12fe7c vstr d7, [sp] */
/* @0x12fe80 vmov s15, r2 */
/* @0x12fe84 vldr s13, [r12, #24] */
/* @0x12fe88 vcvt.f64.u32 d7, s15 */
/* @0x12fe8c vmov r2, r3, d7 */
/* @0x12fe90 vcvt.f64.s32 d7, s13 */
/* @0x12fe94 vstr d7, [sp, #8] */
/* @0x12fe98 vldr s13, [r12, #28] */
/* @0x12fe9c vcvt.f64.s32 d7, s13 */
/* @0x12fea0 vstr d7, [sp, #16] */
/* @0x12fea4 vldr s14, [r12, #32] */
/* @0x12fea8 vcvt.f64.s32 d7, s14 */
/* @0x12feac vstr d7, [sp, #24] */
/* @0x12feb0 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x12feb4 add sp, sp, #32 */
/* @0x12feb8 pop {r4, r5, r6, pc} */
/* @0x12febc mov r2, #0 */
/* @0x12fec0 mov r3, #0 */
/* @0x12fec4 mov r0, r5 */
/* @0x12fec8 mov r1, #5 */
/* @0x12fecc strd r2, r3, [sp] */
/* @0x12fed0 strd r2, r3, [sp, #8] */
/* @0x12fed4 strd r2, r3, [sp, #16] */
/* @0x12fed8 strd r2, r3, [sp, #24] */
/* @0x12fedc bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x12fee0 add sp, sp, #32 */
/* @0x12fee4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x12fee8 · F_BackgroundSave(RValue&, CInstance*, CInstance*, int, RValue*) · size=308 · insn=77 */
/* @0x12fee8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x12feec sub sp, sp, #12 */
/* @0x12fef0 mov r1, #0 */
/* @0x12fef4 ldr r4, [sp, #0x28] */
/* @0x12fef8 mov r0, r4 */
/* @0x12fefc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ff00 mov r1, #1 */
/* @0x12ff04 mov r5, r0 */
/* @0x12ff08 mov r0, r4 */
/* @0x12ff0c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12ff10 mov r6, r0 */
/* @0x12ff14 mov r0, r5 */
/* @0x12ff18 bl 0xc3794 <_Z15Background_Datai> */
/* @0x12ff1c cmp r6, #0 */
/* @0x12ff20 cmpne r0, #0 */
/* @0x12ff24 mov r4, r0 */
/* @0x12ff28 moveq r1, #0 */
/* @0x12ff2c movne r1, #1 */
/* @0x12ff30 beq 0x12fffc <_Z16F_BackgroundSaveR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x12ff34 ldr r0, [r0, #0x10] */
/* @0x12ff38 cmp r0, #0 */
/* @0x12ff3c beq 0x12ffd4 <_Z16F_BackgroundSaveR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x12ff40 bl 0x167724 <_ZN9CBitmap3214CreateBitmap32Ev> */
/* @0x12ff44 subs r5, r0, #0 */
/* @0x12ff48 beq 0x12ffd4 <_Z16F_BackgroundSaveR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x12ff4c add r2, sp, #8 */
/* @0x12ff50 mov r3, #0 */
/* @0x12ff54 mov r1, r3 */
/* @0x12ff58 str r3, [r2, #-0x4]! */
/* @0x12ff5c ldr r12, [r5] */
/* @0x12ff60 str r3, [sp] */
/* @0x12ff64 mov r3, sp */
/* @0x12ff68 ldr r12, [r12, #0x24] */
/* @0x12ff6c blx r12 */
/* @0x12ff70 ldr r7, [sp, #0x4] */
/* @0x12ff74 cmp r7, #0 */
/* @0x12ff78 mov r8, r0 */
/* @0x12ff7c beq 0x12ffa8 <_Z16F_BackgroundSaveR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x12ff80 mov r0, r4 */
/* @0x12ff84 bl 0xc2d78 <_ZN11CBackground8GetWidthEv> */
/* @0x12ff88 mov r9, r0 */
/* @0x12ff8c mov r0, r4 */
/* @0x12ff90 bl 0xc2d80 <_ZN11CBackground9GetHeightEv> */
/* @0x12ff94 mov r1, r7 */
/* @0x12ff98 mov r2, r9 */
/* @0x12ff9c mov r3, r0 */
/* @0x12ffa0 mov r0, r6 */
/* @0x12ffa4 bl 0x16cc8c <_Z10WritePNG32PcPvii> */
/* @0x12ffa8 ldr r3, [r5] */
/* @0x12ffac mov r1, r8 */
/* @0x12ffb0 mov r0, r5 */
/* @0x12ffb4 ldr r3, [r3, #0x28] */
/* @0x12ffb8 blx r3 */
/* @0x12ffbc ldr r3, [r5] */
/* @0x12ffc0 mov r0, r5 */
/* @0x12ffc4 ldr r3, [r3, #0x4] */
/* @0x12ffc8 blx r3 */
/* @0x12ffcc add sp, sp, #12 */
/* @0x12ffd0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x12ffd4 ldr r3, [pc, #0x34] */
/* @0x12ffd8 ldr r1, [pc, #0x34] */
/* @0x12ffdc ldr r3, [pc, r3] */
/* @0x12ffe0 add r1, pc, r1 */
/* @0x12ffe4 ldr r0, [r3] */
/* @0x12ffe8 ldr r3, [r0] */
/* @0x12ffec ldr r3, [r3, #0xc] */
/* @0x12fff0 blx r3 */
/* @0x12fff4 add sp, sp, #12 */
/* @0x12fff8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x12fffc ldr r0, [pc, #0x14] */
/* @0x130000 add r0, pc, r0 */
/* @0x130004 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x130008 add sp, sp, #12 */
/* @0x13000c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x130010 eoreq sp, r11, r8, lsr r7 */
/* @0x130014 .word 0x0020dbd0 */
/* @0x130018 eoreq sp, r0, r8, ror #23 */

/* ── FUNC 0x13001c · F_SpriteDuplicate(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0x13001c push {r3, r4, r5, lr} */
/* @0x130020 mov r1, #0 */
/* @0x130024 mov r4, r0 */
/* @0x130028 ldr r0, [sp, #0x10] */
/* @0x13002c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130030 mov r5, r0 */
/* @0x130034 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x130038 cmp r0, #0 */
/* @0x13003c beq 0x13008c <_Z17F_SpriteDuplicateR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x130040 ldr r3, [r0, #0x74] */
/* @0x130044 cmp r3, #1 */
/* @0x130048 beq 0x13009c <_Z17F_SpriteDuplicateR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x13004c cmp r3, #2 */
/* @0x130050 beq 0x130078 <_Z17F_SpriteDuplicateR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x130054 mov r0, r5 */
/* @0x130058 bl 0x1f07f0 <_Z16Sprite_Duplicatei> */
/* @0x13005c vmov s15, r0 */
/* @0x130060 vcvt.f64.s32 d7, s15 */
/* @0x130064 vmov r2, r3, d7 */
/* @0x130068 mov r1, #0 */
/* @0x13006c stm r4, {r2, r3} */
/* @0x130070 str r1, [r4, #0xc] */
/* @0x130074 pop {r3, r4, r5, pc} */
/* @0x130078 ldr r0, [pc, #0x30] */
/* @0x13007c mov r1, #0 */
/* @0x130080 pop {r3, r4, r5, lr} */
/* @0x130084 add r0, pc, r0 */
/* @0x130088 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13008c mov r3, #0 */
/* @0x130090 mov r2, #0 */
/* @0x130094 movt r3, #0xbff0 */
/* @0x130098 b 0x130068 <_Z17F_SpriteDuplicateR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x13009c ldr r0, [pc, #0x10] */
/* @0x1300a0 mov r1, #0 */
/* @0x1300a4 pop {r3, r4, r5, lr} */
/* @0x1300a8 add r0, pc, r0 */
/* @0x1300ac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1300b0 eoreq sp, r0, r8, asr #23 */
/* @0x1300b4 eoreq sp, r0, r0, ror r11 */

/* ── FUNC 0x1300b8 · F_SpriteAssign(RValue&, CInstance*, CInstance*, int, RValue*) · size=276 · insn=69 */
/* @0x1300b8 push {r4, r5, r6, lr} */
/* @0x1300bc mov r1, #0 */
/* @0x1300c0 ldr r4, [sp, #0x10] */
/* @0x1300c4 mov r0, r4 */
/* @0x1300c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1300cc mov r1, #1 */
/* @0x1300d0 mov r6, r0 */
/* @0x1300d4 mov r0, r4 */
/* @0x1300d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1300dc mov r5, r0 */
/* @0x1300e0 mov r0, r6 */
/* @0x1300e4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1300e8 mov r4, r0 */
/* @0x1300ec mov r0, r5 */
/* @0x1300f0 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1300f4 cmp r0, #0 */
/* @0x1300f8 cmpne r4, #0 */
/* @0x1300fc moveq r1, #0 */
/* @0x130100 movne r1, #1 */
/* @0x130104 beq 0x130154 <_Z14F_SpriteAssignR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x130108 ldr r2, [r4, #0x74] */
/* @0x13010c cmp r2, #1 */
/* @0x130110 beq 0x130178 <_Z14F_SpriteAssignR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x130114 ldr r3, [r0, #0x74] */
/* @0x130118 cmp r3, #1 */
/* @0x13011c beq 0x13018c <_Z14F_SpriteAssignR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x130120 cmp r2, #2 */
/* @0x130124 beq 0x1301a0 <_Z14F_SpriteAssignR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x130128 cmp r3, #2 */
/* @0x13012c beq 0x130164 <_Z14F_SpriteAssignR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x130130 mov r1, r5 */
/* @0x130134 mov r0, r6 */
/* @0x130138 bl 0x1ef454 <_Z13Sprite_Assignii> */
/* @0x13013c subs r1, r0, #0 */
/* @0x130140 popne {r4, r5, r6, pc} */
/* @0x130144 ldr r0, [pc, #0x68] */
/* @0x130148 pop {r4, r5, r6, lr} */
/* @0x13014c add r0, pc, r0 */
/* @0x130150 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x130154 ldr r0, [pc, #0x5c] */
/* @0x130158 pop {r4, r5, r6, lr} */
/* @0x13015c add r0, pc, r0 */
/* @0x130160 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x130164 ldr r0, [pc, #0x50] */
/* @0x130168 mov r1, #0 */
/* @0x13016c pop {r4, r5, r6, lr} */
/* @0x130170 add r0, pc, r0 */
/* @0x130174 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x130178 ldr r0, [pc, #0x40] */
/* @0x13017c mov r1, #0 */
/* @0x130180 pop {r4, r5, r6, lr} */
/* @0x130184 add r0, pc, r0 */
/* @0x130188 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13018c ldr r0, [pc, #0x30] */
/* @0x130190 mov r1, #0 */
/* @0x130194 pop {r4, r5, r6, lr} */
/* @0x130198 add r0, pc, r0 */
/* @0x13019c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1301a0 ldr r0, [pc, #0x20] */
/* @0x1301a4 mov r1, #0 */
/* @0x1301a8 pop {r4, r5, r6, lr} */
/* @0x1301ac add r0, pc, r0 */
/* @0x1301b0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1301b4 eoreq sp, r0, r12, lsr #25 */
/* @0x1301b8 .word 0x0020dcb8 */
/* @0x1301bc eoreq sp, r0, r8, lsr #24 */
/* @0x1301c0 eoreq sp, r0, r4, lsl #22 */
/* @0x1301c4 eoreq sp, r0, r8, asr #22 */
/* @0x1301c8 eoreq sp, r0, r8, lsl #23 */

/* ── FUNC 0x1301cc · F_SpriteMerge(RValue&, CInstance*, CInstance*, int, RValue*) · size=256 · insn=64 */
/* @0x1301cc push {r4, r5, r6, lr} */
/* @0x1301d0 mov r1, #0 */
/* @0x1301d4 ldr r4, [sp, #0x10] */
/* @0x1301d8 mov r0, r4 */
/* @0x1301dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1301e0 mov r1, #1 */
/* @0x1301e4 mov r5, r0 */
/* @0x1301e8 mov r0, r4 */
/* @0x1301ec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1301f0 mov r6, r0 */
/* @0x1301f4 mov r0, r5 */
/* @0x1301f8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1301fc mov r4, r0 */
/* @0x130200 mov r0, r6 */
/* @0x130204 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x130208 cmp r0, #0 */
/* @0x13020c cmpne r4, #0 */
/* @0x130210 mov r1, r0 */
/* @0x130214 moveq r3, #0 */
/* @0x130218 movne r3, #1 */
/* @0x13021c beq 0x130254 <_Z13F_SpriteMergeR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x130220 ldr r3, [r4, #0x74] */
/* @0x130224 cmp r3, #1 */
/* @0x130228 beq 0x13027c <_Z13F_SpriteMergeR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x13022c ldr r2, [r0, #0x74] */
/* @0x130230 cmp r2, #1 */
/* @0x130234 beq 0x130290 <_Z13F_SpriteMergeR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x130238 cmp r3, #2 */
/* @0x13023c beq 0x1302a4 <_Z13F_SpriteMergeR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x130240 cmp r2, #2 */
/* @0x130244 beq 0x130268 <_Z13F_SpriteMergeR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x130248 mov r0, r4 */
/* @0x13024c pop {r4, r5, r6, lr} */
/* @0x130250 b 0x1e5b2c <_ZN7CSprite13AddFromSpriteEPS_> */
/* @0x130254 ldr r0, [pc, #0x5c] */
/* @0x130258 mov r1, r3 */
/* @0x13025c pop {r4, r5, r6, lr} */
/* @0x130260 add r0, pc, r0 */
/* @0x130264 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x130268 ldr r0, [pc, #0x4c] */
/* @0x13026c mov r1, #0 */
/* @0x130270 pop {r4, r5, r6, lr} */
/* @0x130274 add r0, pc, r0 */
/* @0x130278 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13027c ldr r0, [pc, #0x3c] */
/* @0x130280 mov r1, #0 */
/* @0x130284 pop {r4, r5, r6, lr} */
/* @0x130288 add r0, pc, r0 */
/* @0x13028c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x130290 ldr r0, [pc, #0x2c] */
/* @0x130294 mov r1, #0 */
/* @0x130298 pop {r4, r5, r6, lr} */
/* @0x13029c add r0, pc, r0 */
/* @0x1302a0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1302a4 ldr r0, [pc, #0x1c] */
/* @0x1302a8 mov r1, #0 */
/* @0x1302ac pop {r4, r5, r6, lr} */
/* @0x1302b0 add r0, pc, r0 */
/* @0x1302b4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1302b8 eoreq sp, r0, r0, asr sp */
/* @0x1302bc eoreq sp, r0, r0, ror #25 */
/* @0x1302c0 .word 0x0020dbbc */
/* @0x1302c4 eoreq sp, r0, r0, lsl #24 */
/* @0x1302c8 eoreq sp, r0, r0, asr #24 */

/* ── FUNC 0x1302cc · F_SpriteCollisionMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0x1302cc push {r4, r5, r6, r7, r8, lr} */
/* @0x1302d0 sub sp, sp, #24 */
/* @0x1302d4 mov r1, #0 */
/* @0x1302d8 ldr r4, [sp, #0x30] */
/* @0x1302dc mov r0, r4 */
/* @0x1302e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1302e4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1302e8 subs r5, r0, #0 */
/* @0x1302ec beq 0x1303b0 <_Z21F_SpriteCollisionMaskR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x1302f0 ldr r3, [r5, #0x18] */
/* @0x1302f4 cmp r3, #0 */
/* @0x1302f8 ble 0x1303b0 <_Z21F_SpriteCollisionMaskR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x1302fc ldr r3, [r5, #0x74] */
/* @0x130300 cmp r3, #0 */
/* @0x130304 bne 0x1303b8 <_Z21F_SpriteCollisionMaskR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x130308 mov r1, #1 */
/* @0x13030c mov r0, r4 */
/* @0x130310 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130314 mov r1, #2 */
/* @0x130318 mov r8, r0 */
/* @0x13031c mov r0, r4 */
/* @0x130320 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130324 mov r1, #3 */
/* @0x130328 mov r7, r0 */
/* @0x13032c mov r0, r4 */
/* @0x130330 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130334 mov r1, #4 */
/* @0x130338 str r0, [sp, #0x8] */
/* @0x13033c mov r0, r4 */
/* @0x130340 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130344 mov r1, #5 */
/* @0x130348 str r0, [sp, #0xc] */
/* @0x13034c mov r0, r4 */
/* @0x130350 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130354 mov r1, #6 */
/* @0x130358 str r0, [sp, #0x10] */
/* @0x13035c mov r0, r4 */
/* @0x130360 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130364 mov r1, #7 */
/* @0x130368 str r0, [sp, #0x14] */
/* @0x13036c mov r0, r4 */
/* @0x130370 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130374 mov r1, #8 */
/* @0x130378 mov r6, r0 */
/* @0x13037c mov r0, r4 */
/* @0x130380 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130384 cmp r8, #0 */
/* @0x130388 mov r12, #1 */
/* @0x13038c mov r2, r7 */
/* @0x130390 strb r12, [r5, #0x30] */
/* @0x130394 movle r1, #0 */
/* @0x130398 movgt r1, #1 */
/* @0x13039c add r3, sp, #8 */
/* @0x1303a0 str r6, [sp] */
/* @0x1303a4 str r0, [sp, #0x4] */
/* @0x1303a8 mov r0, r5 */
/* @0x1303ac bl 0x1e3d88 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii> */
/* @0x1303b0 add sp, sp, #24 */
/* @0x1303b4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1303b8 ldr r0, [pc, #0x10] */
/* @0x1303bc mov r1, #0 */
/* @0x1303c0 add r0, pc, r0 */
/* @0x1303c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1303c8 add sp, sp, #24 */
/* @0x1303cc pop {r4, r5, r6, r7, r8, pc} */
/* @0x1303d0 eoreq sp, r0, r12, lsl r12 */

/* ── FUNC 0x1303d4 · F_SpritePrefetchMulti(RValue&, CInstance*, CInstance*, int, RValue*) · size=524 · insn=131 */
/* @0x1303d4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1303d8 sub sp, sp, #12 */
/* @0x1303dc mov r6, #0 */
/* @0x1303e0 str r6, [r0, #0xc] */
/* @0x1303e4 ldr r2, [sp, #0x30] */
/* @0x1303e8 mov r3, r6 */
/* @0x1303ec ldr r7, [pc, #0x1cc] */
/* @0x1303f0 movt r3, #0xbff0 */
/* @0x1303f4 mov r9, r0 */
/* @0x1303f8 str r6, [r0] */
/* @0x1303fc ldr r1, [r2, #0xc] */
/* @0x130400 add r7, pc, r7 */
/* @0x130404 str r3, [r0, #0x4] */
/* @0x130408 cmp r1, #2 */
/* @0x13040c bne 0x13045c <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x130410 ldr r8, [r2] */
/* @0x130414 cmp r8, #0 */
/* @0x130418 beq 0x130434 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x13041c ldr r3, [r8, #0x4] */
/* @0x130420 cmp r3, #0 */
/* @0x130424 beq 0x130434 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x130428 ldr r2, [r8, #0x10] */
/* @0x13042c cmp r2, #1 */
/* @0x130430 beq 0x13046c <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x130434 ldr r1, [pc, #0x188] */
/* @0x130438 ldr r3, [pc, #0x188] */
/* @0x13043c add r1, pc, r1 */
/* @0x130440 ldr r3, [r7, r3] */
/* @0x130444 ldr r0, [r3] */
/* @0x130448 ldr r3, [r0] */
/* @0x13044c ldr r3, [r3, #0xc] */
/* @0x130450 blx r3 */
/* @0x130454 add sp, sp, #12 */
/* @0x130458 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13045c ldr r1, [pc, #0x168] */
/* @0x130460 ldr r3, [pc, #0x160] */
/* @0x130464 add r1, pc, r1 */
/* @0x130468 b 0x130440 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x13046c ldr r2, [r3] */
/* @0x130470 cmp r2, #0 */
/* @0x130474 ble 0x130584 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x130478 ldr r2, [pc, #0x150] */
/* @0x13047c add r2, pc, r2 */
/* @0x130480 str r2, [sp, #0x4] */
/* @0x130484 ldr r2, [pc, #0x148] */
/* @0x130488 add r2, pc, r2 */
/* @0x13048c str r2, [sp] */
/* @0x130490 b 0x1304c8 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x130494 ldr r3, [pc, #0x12c] */
/* @0x130498 mov r2, r6 */
/* @0x13049c ldr r1, [sp] */
/* @0x1304a0 ldr r3, [r7, r3] */
/* @0x1304a4 ldr r0, [r3] */
/* @0x1304a8 ldr r3, [r0] */
/* @0x1304ac ldr r3, [r3, #0xc] */
/* @0x1304b0 blx r3 */
/* @0x1304b4 ldr r3, [r8, #0x4] */
/* @0x1304b8 add r6, r6, #1 */
/* @0x1304bc ldr r2, [r3] */
/* @0x1304c0 cmp r2, r6 */
/* @0x1304c4 ble 0x130584 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x1304c8 ldr r0, [r3, #0x4] */
/* @0x1304cc add r0, r0, r6, lsl #4 */
/* @0x1304d0 ldr r1, [r0, #0xc] */
/* @0x1304d4 cmp r1, #0 */
/* @0x1304d8 bne 0x130494 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1304dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1304e0 mov r5, r0 */
/* @0x1304e4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1304e8 subs r4, r0, #0 */
/* @0x1304ec beq 0x130574 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x1304f0 ldr r3, [r4, #0x74] */
/* @0x1304f4 cmp r3, #0 */
/* @0x1304f8 bne 0x130598 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x1304fc ldr r5, [r4, #0x18] */
/* @0x130500 cmp r5, #0 */
/* @0x130504 ble 0x1304b4 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x130508 ldr r2, [pc, #0xc8] */
/* @0x13050c mov r10, r3 */
/* @0x130510 ldr r11, [r7, r2] */
/* @0x130514 b 0x130540 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x130518 cmn r0, #1 */
/* @0x13051c beq 0x130558 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x130520 ldrsh r0, [r0, #20] */
/* @0x130524 ldr r1, [r11, #0x4] */
/* @0x130528 ldr r1, [r1, r0, lsl #2] */
/* @0x13052c ldr r0, [r1] */
/* @0x130530 bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv> */
/* @0x130534 add r10, r10, #1 */
/* @0x130538 cmp r10, r5 */
/* @0x13053c beq 0x1304b4 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x130540 mov r1, r10 */
/* @0x130544 mov r0, r4 */
/* @0x130548 bl 0x1e57f4 <_ZN7CSprite10GetTextureEi> */
/* @0x13054c ldr r1, [r11] */
/* @0x130550 cmp r0, r1 */
/* @0x130554 bhi 0x130518 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x130558 ldr r1, [r11, #0x4] */
/* @0x13055c ldr r1, [r1, r0, lsl #2] */
/* @0x130560 cmp r1, #0 */
/* @0x130564 beq 0x130534 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x130568 ldr r0, [r1] */
/* @0x13056c bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv> */
/* @0x130570 b 0x130534 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x130574 ldr r3, [pc, #0x4c] */
/* @0x130578 mov r2, r5 */
/* @0x13057c ldr r1, [sp, #0x4] */
/* @0x130580 b 0x1304a0 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x130584 mov r3, #0 */
/* @0x130588 str r3, [r9] */
/* @0x13058c str r3, [r9, #0x4] */
/* @0x130590 add sp, sp, #12 */
/* @0x130594 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x130598 ldr r3, [pc, #0x28] */
/* @0x13059c mov r2, r5 */
/* @0x1305a0 ldr r1, [pc, #0x34] */
/* @0x1305a4 ldr r3, [r7, r3] */
/* @0x1305a8 add r1, pc, r1 */
/* @0x1305ac ldr r0, [r3] */
/* @0x1305b0 ldr r3, [r0] */
/* @0x1305b4 ldr r3, [r3, #0xc] */
/* @0x1305b8 blx r3 */
/* @0x1305bc b 0x130454 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1305c0 eoreq r1, r12, r0, asr r8 */
/* @0x1305c4 eoreq sp, r0, r12, lsl r12 */
/* @0x1305c8 .word 0xffffbac4 */
/* @0x1305cc .word 0x0020dbb0 */
/* @0x1305d0 eoreq sp, r0, r4, asr #24 */
/* @0x1305d4 eoreq sp, r0, r0, lsl #24 */
/* @0x1305d8 .word 0xffffbccc */
/* @0x1305dc eoreq sp, r0, r8, asr #22 */

/* ── FUNC 0x1305e0 · F_SpriteFlushMulti(RValue&, CInstance*, CInstance*, int, RValue*) · size=528 · insn=132 */
/* @0x1305e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1305e4 sub sp, sp, #12 */
/* @0x1305e8 mov r6, #0 */
/* @0x1305ec str r6, [r0, #0xc] */
/* @0x1305f0 ldr r2, [sp, #0x30] */
/* @0x1305f4 mov r3, r6 */
/* @0x1305f8 ldr r7, [pc, #0x1d0] */
/* @0x1305fc movt r3, #0xbff0 */
/* @0x130600 mov r8, r0 */
/* @0x130604 str r6, [r0] */
/* @0x130608 ldr r1, [r2, #0xc] */
/* @0x13060c add r7, pc, r7 */
/* @0x130610 str r3, [r0, #0x4] */
/* @0x130614 cmp r1, #2 */
/* @0x130618 bne 0x130668 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x13061c ldr r9, [r2] */
/* @0x130620 cmp r9, #0 */
/* @0x130624 beq 0x130640 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x130628 ldr r3, [r9, #0x4] */
/* @0x13062c cmp r3, #0 */
/* @0x130630 beq 0x130640 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x130634 ldr r3, [r9, #0x10] */
/* @0x130638 cmp r3, #1 */
/* @0x13063c beq 0x130678 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x130640 ldr r1, [pc, #0x18c] */
/* @0x130644 ldr r3, [pc, #0x18c] */
/* @0x130648 add r1, pc, r1 */
/* @0x13064c ldr r3, [r7, r3] */
/* @0x130650 ldr r0, [r3] */
/* @0x130654 ldr r3, [r0] */
/* @0x130658 ldr r3, [r3, #0xc] */
/* @0x13065c blx r3 */
/* @0x130660 add sp, sp, #12 */
/* @0x130664 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x130668 ldr r1, [pc, #0x16c] */
/* @0x13066c ldr r3, [pc, #0x164] */
/* @0x130670 add r1, pc, r1 */
/* @0x130674 b 0x13064c <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x130678 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x13067c ldr r3, [r9, #0x4] */
/* @0x130680 ldr r2, [r3] */
/* @0x130684 cmp r2, #0 */
/* @0x130688 ble 0x130798 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x13068c ldr r2, [pc, #0x14c] */
/* @0x130690 add r2, pc, r2 */
/* @0x130694 str r2, [sp, #0x4] */
/* @0x130698 ldr r2, [pc, #0x144] */
/* @0x13069c add r2, pc, r2 */
/* @0x1306a0 str r2, [sp] */
/* @0x1306a4 b 0x1306dc <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x1306a8 ldr r3, [pc, #0x128] */
/* @0x1306ac mov r2, r6 */
/* @0x1306b0 ldr r1, [sp] */
/* @0x1306b4 ldr r3, [r7, r3] */
/* @0x1306b8 ldr r0, [r3] */
/* @0x1306bc ldr r3, [r0] */
/* @0x1306c0 ldr r3, [r3, #0xc] */
/* @0x1306c4 blx r3 */
/* @0x1306c8 ldr r3, [r9, #0x4] */
/* @0x1306cc add r6, r6, #1 */
/* @0x1306d0 ldr r2, [r3] */
/* @0x1306d4 cmp r2, r6 */
/* @0x1306d8 ble 0x130798 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x1306dc ldr r0, [r3, #0x4] */
/* @0x1306e0 add r0, r0, r6, lsl #4 */
/* @0x1306e4 ldr r1, [r0, #0xc] */
/* @0x1306e8 cmp r1, #0 */
/* @0x1306ec bne 0x1306a8 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x1306f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1306f4 mov r5, r0 */
/* @0x1306f8 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1306fc subs r4, r0, #0 */
/* @0x130700 beq 0x130788 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x130704 ldr r3, [r4, #0x74] */
/* @0x130708 cmp r3, #0 */
/* @0x13070c bne 0x1307a8 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x130710 ldr r5, [r4, #0x18] */
/* @0x130714 cmp r5, #0 */
/* @0x130718 ble 0x1306c8 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x13071c ldr r2, [pc, #0xc4] */
/* @0x130720 mov r10, r3 */
/* @0x130724 ldr r11, [r7, r2] */
/* @0x130728 b 0x130754 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x13072c cmn r0, #1 */
/* @0x130730 beq 0x13076c <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x130734 ldrsh r0, [r0, #20] */
/* @0x130738 ldr r1, [r11, #0x4] */
/* @0x13073c ldr r1, [r1, r0, lsl #2] */
/* @0x130740 ldr r0, [r1] */
/* @0x130744 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv> */
/* @0x130748 add r10, r10, #1 */
/* @0x13074c cmp r10, r5 */
/* @0x130750 beq 0x1306c8 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x130754 mov r1, r10 */
/* @0x130758 mov r0, r4 */
/* @0x13075c bl 0x1e57f4 <_ZN7CSprite10GetTextureEi> */
/* @0x130760 ldr r1, [r11] */
/* @0x130764 cmp r0, r1 */
/* @0x130768 bhi 0x13072c <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x13076c ldr r1, [r11, #0x4] */
/* @0x130770 ldr r1, [r1, r0, lsl #2] */
/* @0x130774 cmp r1, #0 */
/* @0x130778 beq 0x130748 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x13077c ldr r0, [r1] */
/* @0x130780 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv> */
/* @0x130784 b 0x130748 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x130788 ldr r3, [pc, #0x48] */
/* @0x13078c mov r2, r5 */
/* @0x130790 ldr r1, [sp, #0x4] */
/* @0x130794 b 0x1306b4 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x130798 mov r3, #0 */
/* @0x13079c str r3, [r8] */
/* @0x1307a0 str r3, [r8, #0x4] */
/* @0x1307a4 b 0x130660 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1307a8 ldr r3, [pc, #0x28] */
/* @0x1307ac mov r2, r5 */
/* @0x1307b0 ldr r1, [pc, #0x34] */
/* @0x1307b4 ldr r3, [r7, r3] */
/* @0x1307b8 add r1, pc, r1 */
/* @0x1307bc ldr r0, [r3] */
/* @0x1307c0 ldr r3, [r0] */
/* @0x1307c4 ldr r3, [r3, #0xc] */
/* @0x1307c8 blx r3 */
/* @0x1307cc b 0x130660 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1307d0 eoreq r1, r12, r4, asr #12 */
/* @0x1307d4 eoreq sp, r0, r4, lsr r11 */
/* @0x1307d8 .word 0xffffbac4 */
/* @0x1307dc eoreq sp, r0, r8, asr #21 */
/* @0x1307e0 eoreq sp, r0, r0, asr r11 */
/* @0x1307e4 eoreq sp, r0, r0, lsl r11 */
/* @0x1307e8 .word 0xffffbccc */
/* @0x1307ec eoreq sp, r0, r4, asr r10 */

/* ── FUNC 0x1307f0 · F_SpriteSave(RValue&, CInstance*, CInstance*, int, RValue*) · size=284 · insn=71 */
/* @0x1307f0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1307f4 sub sp, sp, #8 */
/* @0x1307f8 mov r1, #0 */
/* @0x1307fc ldr r4, [sp, #0x20] */
/* @0x130800 mov r0, r4 */
/* @0x130804 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130808 mov r1, #1 */
/* @0x13080c mov r5, r0 */
/* @0x130810 mov r0, r4 */
/* @0x130814 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130818 mov r1, #2 */
/* @0x13081c mov r7, r0 */
/* @0x130820 mov r0, r4 */
/* @0x130824 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x130828 mov r8, r0 */
/* @0x13082c mov r0, r5 */
/* @0x130830 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x130834 subs r6, r0, #0 */
/* @0x130838 beq 0x1308bc <_Z12F_SpriteSaveR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x13083c ldr r4, [r6, #0x74] */
/* @0x130840 cmp r4, #0 */
/* @0x130844 bne 0x1308c4 <_Z12F_SpriteSaveR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x130848 mov r1, r7 */
/* @0x13084c bl 0x1e6398 <_ZN7CSprite11GetBitmap32Ei> */
/* @0x130850 subs r5, r0, #0 */
/* @0x130854 beq 0x1308dc <_Z12F_SpriteSaveR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x130858 add r2, sp, #8 */
/* @0x13085c mov r1, r4 */
/* @0x130860 str r4, [sp] */
/* @0x130864 mov r3, sp */
/* @0x130868 str r4, [r2, #-0x4]! */
/* @0x13086c ldr r12, [r5] */
/* @0x130870 ldr r12, [r12, #0x24] */
/* @0x130874 blx r12 */
/* @0x130878 ldr r1, [sp, #0x4] */
/* @0x13087c cmp r1, #0 */
/* @0x130880 mov r4, r0 */
/* @0x130884 beq 0x130898 <_Z12F_SpriteSaveR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x130888 mov r0, r8 */
/* @0x13088c ldr r2, [r6, #0x1c] */
/* @0x130890 ldr r3, [r6, #0x20] */
/* @0x130894 bl 0x16cc8c <_Z10WritePNG32PcPvii> */
/* @0x130898 ldr r3, [r5] */
/* @0x13089c mov r0, r5 */
/* @0x1308a0 mov r1, r4 */
/* @0x1308a4 ldr r3, [r3, #0x28] */
/* @0x1308a8 blx r3 */
/* @0x1308ac ldr r3, [r5] */
/* @0x1308b0 mov r0, r5 */
/* @0x1308b4 ldr r3, [r3, #0x4] */
/* @0x1308b8 blx r3 */
/* @0x1308bc add sp, sp, #8 */
/* @0x1308c0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1308c4 ldr r0, [pc, #0x34] */
/* @0x1308c8 mov r1, #0 */
/* @0x1308cc add r0, pc, r0 */
/* @0x1308d0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1308d4 add sp, sp, #8 */
/* @0x1308d8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1308dc ldr r3, [pc, #0x20] */
/* @0x1308e0 ldr r1, [pc, #0x20] */
/* @0x1308e4 ldr r3, [pc, r3] */
/* @0x1308e8 add r1, pc, r1 */
/* @0x1308ec ldr r0, [r3] */
/* @0x1308f0 ldr r3, [r0] */
/* @0x1308f4 ldr r3, [r3, #0xc] */
/* @0x1308f8 blx r3 */
/* @0x1308fc b 0x1308bc <_Z12F_SpriteSaveR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x130900 eoreq sp, r0, r8, lsl #19 */
/* @0x130904 eoreq r12, r11, r0, lsr lr */
/* @0x130908 mlaeq r0, r12, r9, sp */

/* ── FUNC 0x13090c · F_SpriteSaveStrip(RValue&, CInstance*, CInstance*, int, RValue*) · size=568 · insn=142 */
/* @0x13090c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x130910 sub sp, sp, #12 */
/* @0x130914 mov r1, #0 */
/* @0x130918 ldr r4, [sp, #0x30] */
/* @0x13091c mov r0, r4 */
/* @0x130920 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130924 mov r1, #1 */
/* @0x130928 mov r5, r0 */
/* @0x13092c mov r0, r4 */
/* @0x130930 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x130934 mov r11, r0 */
/* @0x130938 mov r0, r5 */
/* @0x13093c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x130940 cmp r11, #0 */
/* @0x130944 cmpne r0, #0 */
/* @0x130948 mov r10, r0 */
/* @0x13094c beq 0x130a84 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x130950 ldr r9, [r0, #0x74] */
/* @0x130954 cmp r9, #0 */
/* @0x130958 bne 0x130a8c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x13095c ldr r3, [r0, #0x18] */
/* @0x130960 cmp r3, #0 */
/* @0x130964 ble 0x130a84 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x130968 ldr r5, [r0, #0x1c] */
/* @0x13096c mov r0, #24 */
/* @0x130970 ldr r4, [r10, #0x20] */
/* @0x130974 mul r5, r5, r3 */
/* @0x130978 bl 0x27c524 <_Znwj> */
/* @0x13097c mov r3, #-16777216 */
/* @0x130980 mov r2, r4 */
/* @0x130984 mov r1, r5 */
/* @0x130988 mov r8, r0 */
/* @0x13098c bl 0x166140 <_ZN9CBitmap32C2Eiij> */
/* @0x130990 ldr r3, [r10, #0x18] */
/* @0x130994 cmp r3, #0 */
/* @0x130998 ble 0x130aa4 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x13099c ldr r3, [r10, #0x48] */
/* @0x1309a0 cmp r3, #0 */
/* @0x1309a4 beq 0x130a4c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1309a8 ldr r7, [r3] */
/* @0x1309ac cmp r7, #0 */
/* @0x1309b0 beq 0x130a4c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1309b4 mov r0, r8 */
/* @0x1309b8 mov r4, #0 */
/* @0x1309bc bl 0x167970 <_ZN9CBitmap327GetDataEv> */
/* @0x1309c0 ldr r6, [r10, #0x1c] */
/* @0x1309c4 mul r6, r6, r9 */
/* @0x1309c8 ldr r3, [r0, #0x4] */
/* @0x1309cc mov r0, r7 */
/* @0x1309d0 add r6, r3, r6, lsl #2 */
/* @0x1309d4 bl 0x167970 <_ZN9CBitmap327GetDataEv> */
/* @0x1309d8 ldr r5, [r0, #0x4] */
/* @0x1309dc b 0x130a0c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x1309e0 bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0x1309e4 mov r1, r5 */
/* @0x1309e8 lsl r2, r0, #2 */
/* @0x1309ec mov r0, r6 */
/* @0x1309f0 bl 0xb65bc <memcpy@plt> */
/* @0x1309f4 mov r0, r8 */
/* @0x1309f8 bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0x1309fc add r6, r6, r0, lsl #2 */
/* @0x130a00 mov r0, r7 */
/* @0x130a04 bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0x130a08 add r5, r5, r0, lsl #2 */
/* @0x130a0c mov r0, r8 */
/* @0x130a10 bl 0x167968 <_ZN9CBitmap329GetHeightEv> */
/* @0x130a14 cmp r4, r0 */
/* @0x130a18 mov r0, r7 */
/* @0x130a1c add r4, r4, #1 */
/* @0x130a20 blt 0x1309e0 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x130a24 ldr r3, [r10, #0x18] */
/* @0x130a28 add r9, r9, #1 */
/* @0x130a2c cmp r3, r9 */
/* @0x130a30 ble 0x130aa4 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x130a34 ldr r3, [r10, #0x48] */
/* @0x130a38 cmp r3, #0 */
/* @0x130a3c beq 0x130a4c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x130a40 ldr r7, [r3, r9, lsl #2] */
/* @0x130a44 cmp r7, #0 */
/* @0x130a48 bne 0x1309b4 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x130a4c ldr r3, [pc, #0xe4] */
/* @0x130a50 ldr r1, [pc, #0xe4] */
/* @0x130a54 ldr r3, [pc, r3] */
/* @0x130a58 add r1, pc, r1 */
/* @0x130a5c ldr r0, [r3] */
/* @0x130a60 ldr r3, [r0] */
/* @0x130a64 ldr r3, [r3, #0xc] */
/* @0x130a68 blx r3 */
/* @0x130a6c cmp r8, #0 */
/* @0x130a70 beq 0x130a84 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x130a74 ldr r3, [r8] */
/* @0x130a78 mov r0, r8 */
/* @0x130a7c ldr r3, [r3, #0x4] */
/* @0x130a80 blx r3 */
/* @0x130a84 add sp, sp, #12 */
/* @0x130a88 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x130a8c ldr r0, [pc, #0xac] */
/* @0x130a90 mov r1, #0 */
/* @0x130a94 add r0, pc, r0 */
/* @0x130a98 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x130a9c add sp, sp, #12 */
/* @0x130aa0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x130aa4 mov r0, r8 */
/* @0x130aa8 bl 0x167724 <_ZN9CBitmap3214CreateBitmap32Ev> */
/* @0x130aac subs r4, r0, #0 */
/* @0x130ab0 beq 0x130a6c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x130ab4 add r2, sp, #8 */
/* @0x130ab8 mov r3, #0 */
/* @0x130abc mov r1, r3 */
/* @0x130ac0 str r3, [r2, #-0x4]! */
/* @0x130ac4 ldr r12, [r4] */
/* @0x130ac8 str r3, [sp] */
/* @0x130acc mov r3, sp */
/* @0x130ad0 ldr r12, [r12, #0x24] */
/* @0x130ad4 blx r12 */
/* @0x130ad8 ldr r5, [sp, #0x4] */
/* @0x130adc cmp r5, #0 */
/* @0x130ae0 mov r6, r0 */
/* @0x130ae4 beq 0x130b10 <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x130ae8 mov r0, r8 */
/* @0x130aec bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0x130af0 mov r7, r0 */
/* @0x130af4 mov r0, r8 */
/* @0x130af8 bl 0x167968 <_ZN9CBitmap329GetHeightEv> */
/* @0x130afc mov r1, r5 */
/* @0x130b00 mov r2, r7 */
/* @0x130b04 mov r3, r0 */
/* @0x130b08 mov r0, r11 */
/* @0x130b0c bl 0x16cc8c <_Z10WritePNG32PcPvii> */
/* @0x130b10 ldr r3, [r4] */
/* @0x130b14 mov r0, r4 */
/* @0x130b18 mov r1, r6 */
/* @0x130b1c ldr r3, [r3, #0x28] */
/* @0x130b20 blx r3 */
/* @0x130b24 ldr r3, [r4] */
/* @0x130b28 mov r0, r4 */
/* @0x130b2c ldr r3, [r3, #0x4] */
/* @0x130b30 blx r3 */
/* @0x130b34 b 0x130a6c <_Z17F_SpriteSaveStripR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x130b38 eoreq r12, r11, r0, asr #25 */
/* @0x130b3c mlaeq r0, r4, r8, sp */
/* @0x130b40 eoreq sp, r0, r4, lsr #16 */

/* ── FUNC 0x130b44 · F_ObjectSetParent(RValue&, CInstance*, CInstance*, int, RValue*) · size=360 · insn=90 */
/* @0x130b44 push {r3, r4, r5, r6, r7, lr} */
/* @0x130b48 mov r1, #0 */
/* @0x130b4c ldr r4, [sp, #0x18] */
/* @0x130b50 mov r0, r4 */
/* @0x130b54 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130b58 mov r1, #1 */
/* @0x130b5c mov r5, r0 */
/* @0x130b60 mov r0, r4 */
/* @0x130b64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130b68 cmp r5, r0 */
/* @0x130b6c mov r4, r0 */
/* @0x130b70 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x130b74 ldr r6, [pc, #0x124] */
/* @0x130b78 ldr r6, [pc, r6] */
/* @0x130b7c ldr r3, [r6] */
/* @0x130b80 ldr r0, [r3, #0x4] */
/* @0x130b84 ldr r1, [r3] */
/* @0x130b88 and r3, r5, r0 */
/* @0x130b8c ldr r3, [r1, r3, lsl #3] */
/* @0x130b90 cmp r3, #0 */
/* @0x130b94 bne 0x130ba8 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x130b98 pop {r3, r4, r5, r6, r7, pc} */
/* @0x130b9c ldr r3, [r3, #0x4] */
/* @0x130ba0 cmp r3, #0 */
/* @0x130ba4 beq 0x130c74 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x130ba8 ldr r2, [r3, #0x8] */
/* @0x130bac cmp r5, r2 */
/* @0x130bb0 bne 0x130b9c <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x130bb4 ldr r7, [r3, #0xc] */
/* @0x130bb8 cmp r7, #0 */
/* @0x130bbc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x130bc0 cmp r4, #0 */
/* @0x130bc4 mvnlt r3, #0 */
/* @0x130bc8 strlt r3, [r7, #0xc] */
/* @0x130bcc poplt {r3, r4, r5, r6, r7, pc} */
/* @0x130bd0 and r0, r4, r0 */
/* @0x130bd4 ldr r3, [r1, r0, lsl #3] */
/* @0x130bd8 cmp r3, #0 */
/* @0x130bdc bne 0x130bf0 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x130be0 b 0x130c8c <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x130be4 ldr r3, [r3, #0x4] */
/* @0x130be8 cmp r3, #0 */
/* @0x130bec beq 0x130c8c <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x130bf0 ldr r2, [r3, #0x8] */
/* @0x130bf4 cmp r4, r2 */
/* @0x130bf8 bne 0x130be4 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x130bfc ldr r0, [r3, #0xc] */
/* @0x130c00 cmp r0, #0 */
/* @0x130c04 beq 0x130c8c <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x130c08 mov r1, r5 */
/* @0x130c0c bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi> */
/* @0x130c10 cmp r0, #0 */
/* @0x130c14 bne 0x130c78 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x130c18 movw r3, #0x423f */
/* @0x130c1c movt r3, #0xf */
/* @0x130c20 cmp r4, r3 */
/* @0x130c24 str r4, [r7, #0xc] */
/* @0x130c28 bhi 0x130c6c <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x130c2c ldr r3, [r6] */
/* @0x130c30 ldr r2, [r3, #0x4] */
/* @0x130c34 ldr r3, [r3] */
/* @0x130c38 and r2, r4, r2 */
/* @0x130c3c ldr r3, [r3, r2, lsl #3] */
/* @0x130c40 cmp r3, #0 */
/* @0x130c44 bne 0x130c58 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x130c48 b 0x130c68 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x130c4c ldr r3, [r3, #0x4] */
/* @0x130c50 cmp r3, #0 */
/* @0x130c54 beq 0x130c68 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x130c58 ldr r2, [r3, #0x8] */
/* @0x130c5c cmp r4, r2 */
/* @0x130c60 bne 0x130c4c <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x130c64 ldr r3, [r3, #0xc] */
/* @0x130c68 str r3, [r7, #0x48] */
/* @0x130c6c pop {r3, r4, r5, r6, r7, lr} */
/* @0x130c70 b 0x19e7dc <_Z19Create_Object_Listsv> */
/* @0x130c74 pop {r3, r4, r5, r6, r7, pc} */
/* @0x130c78 ldr r0, [pc, #0x24] */
/* @0x130c7c mov r1, #0 */
/* @0x130c80 pop {r3, r4, r5, r6, r7, lr} */
/* @0x130c84 add r0, pc, r0 */
/* @0x130c88 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x130c8c ldr r0, [pc, #0x14] */
/* @0x130c90 mov r1, #0 */
/* @0x130c94 pop {r3, r4, r5, r6, r7, lr} */
/* @0x130c98 add r0, pc, r0 */
/* @0x130c9c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x130ca0 eoreq sp, r11, r4, asr #1 */
/* @0x130ca4 .word 0x0020d6bc */
/* @0x130ca8 eoreq sp, r0, r8, lsl #13 */

/* ── FUNC 0x130cac · MarkInstancesAsDirty(int) · size=168 · insn=42 */
/* @0x130cac push {r3, r4, r5, r6, r7, lr} */
/* @0x130cb0 mov r5, r0 */
/* @0x130cb4 ldr r6, [pc, #0x94] */
/* @0x130cb8 ldr r6, [pc, r6] */
/* @0x130cbc ldr r3, [r6] */
/* @0x130cc0 ldr r0, [r3, #0x80] */
/* @0x130cc4 cmp r0, #0 */
/* @0x130cc8 beq 0x130d08 <_Z20MarkInstancesAsDirtyi+0x5c> */
/* @0x130ccc mov r7, #1 */
/* @0x130cd0 b 0x130ce0 <_Z20MarkInstancesAsDirtyi+0x34> */
/* @0x130cd4 cmp r4, #0 */
/* @0x130cd8 mov r0, r4 */
/* @0x130cdc beq 0x130d04 <_Z20MarkInstancesAsDirtyi+0x58> */
/* @0x130ce0 ldr r3, [r0, #0x8c] */
/* @0x130ce4 ldr r4, [r0, #0x178] */
/* @0x130ce8 cmp r3, r5 */
/* @0x130cec bne 0x130cd4 <_Z20MarkInstancesAsDirtyi+0x28> */
/* @0x130cf0 strb r7, [r0, #0x64] */
/* @0x130cf4 bl 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* @0x130cf8 cmp r4, #0 */
/* @0x130cfc mov r0, r4 */
/* @0x130d00 bne 0x130ce0 <_Z20MarkInstancesAsDirtyi+0x34> */
/* @0x130d04 ldr r3, [r6] */
/* @0x130d08 ldr r0, [r3, #0x8c] */
/* @0x130d0c cmp r0, #0 */
/* @0x130d10 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x130d14 mov r6, #1 */
/* @0x130d18 b 0x130d28 <_Z20MarkInstancesAsDirtyi+0x7c> */
/* @0x130d1c cmp r4, #0 */
/* @0x130d20 mov r0, r4 */
/* @0x130d24 beq 0x130d4c <_Z20MarkInstancesAsDirtyi+0xa0> */
/* @0x130d28 ldr r3, [r0, #0x8c] */
/* @0x130d2c ldr r4, [r0, #0x178] */
/* @0x130d30 cmp r5, r3 */
/* @0x130d34 bne 0x130d1c <_Z20MarkInstancesAsDirtyi+0x70> */
/* @0x130d38 strb r6, [r0, #0x64] */
/* @0x130d3c bl 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* @0x130d40 cmp r4, #0 */
/* @0x130d44 mov r0, r4 */
/* @0x130d48 bne 0x130d28 <_Z20MarkInstancesAsDirtyi+0x7c> */
/* @0x130d4c pop {r3, r4, r5, r6, r7, pc} */
/* @0x130d50 eoreq r12, r11, r0, ror r12 */

/* ── FUNC 0x130d54 · F_SpriteSetOffset(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x130d54 push {r4, r5, r6, lr} */
/* @0x130d58 mov r1, #0 */
/* @0x130d5c ldr r4, [sp, #0x10] */
/* @0x130d60 mov r0, r4 */
/* @0x130d64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130d68 mov r6, r0 */
/* @0x130d6c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x130d70 subs r5, r0, #0 */
/* @0x130d74 popeq {r4, r5, r6, pc} */
/* @0x130d78 mov r0, r4 */
/* @0x130d7c mov r1, #1 */
/* @0x130d80 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130d84 mov r1, #2 */
/* @0x130d88 str r0, [r5, #0x24] */
/* @0x130d8c mov r0, r4 */
/* @0x130d90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130d94 str r0, [r5, #0x28] */
/* @0x130d98 mov r0, r6 */
/* @0x130d9c pop {r4, r5, r6, lr} */
/* @0x130da0 b 0x130cac <_Z20MarkInstancesAsDirtyi> */

/* ── FUNC 0x130da4 · F_SpriteSetBboxMode(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x130da4 push {r4, r5, r6, lr} */
/* @0x130da8 mov r1, #0 */
/* @0x130dac ldr r4, [sp, #0x10] */
/* @0x130db0 mov r0, r4 */
/* @0x130db4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130db8 mov r5, r0 */
/* @0x130dbc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x130dc0 subs r6, r0, #0 */
/* @0x130dc4 popeq {r4, r5, r6, pc} */
/* @0x130dc8 mov r0, r4 */
/* @0x130dcc mov r1, #1 */
/* @0x130dd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130dd4 mov r1, r0 */
/* @0x130dd8 mov r0, r6 */
/* @0x130ddc bl 0x1e35c8 <_ZN7CSprite18SetBoundingBoxModeEi> */
/* @0x130de0 mov r0, r5 */
/* @0x130de4 pop {r4, r5, r6, lr} */
/* @0x130de8 b 0x130cac <_Z20MarkInstancesAsDirtyi> */

/* ── FUNC 0x130dec · F_SpriteSetBbox(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x130dec push {r4, r5, r6, lr} */
/* @0x130df0 sub sp, sp, #16 */
/* @0x130df4 mov r1, #0 */
/* @0x130df8 ldr r4, [sp, #0x20] */
/* @0x130dfc mov r0, r4 */
/* @0x130e00 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130e04 mov r5, r0 */
/* @0x130e08 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x130e0c subs r6, r0, #0 */
/* @0x130e10 beq 0x130e68 <_Z15F_SpriteSetBboxR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x130e14 mov r1, #1 */
/* @0x130e18 mov r0, r4 */
/* @0x130e1c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130e20 mov r1, #2 */
/* @0x130e24 str r0, [sp] */
/* @0x130e28 mov r0, r4 */
/* @0x130e2c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130e30 mov r1, #3 */
/* @0x130e34 str r0, [sp, #0x4] */
/* @0x130e38 mov r0, r4 */
/* @0x130e3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130e40 mov r1, #4 */
/* @0x130e44 str r0, [sp, #0x8] */
/* @0x130e48 mov r0, r4 */
/* @0x130e4c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130e50 mov r1, sp */
/* @0x130e54 str r0, [sp, #0xc] */
/* @0x130e58 mov r0, r6 */
/* @0x130e5c bl 0x1e32e8 <_ZN7CSprite14SetBoundingBoxEP9tagYYRECT> */
/* @0x130e60 mov r0, r5 */
/* @0x130e64 bl 0x130cac <_Z20MarkInstancesAsDirtyi> */
/* @0x130e68 add sp, sp, #16 */
/* @0x130e6c pop {r4, r5, r6, pc} */

/* ── FUNC 0x130e70 · F_SpriteSetPrecise(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x130e70 push {r3, r4, r5, lr} */
/* @0x130e74 mov r1, #0 */
/* @0x130e78 ldr r4, [sp, #0x10] */
/* @0x130e7c mov r0, r4 */
/* @0x130e80 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130e84 mov r1, #0 */
/* @0x130e88 mov r5, r0 */
/* @0x130e8c mov r0, r4 */
/* @0x130e90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130e94 cmp r0, #0 */
/* @0x130e98 mov r0, r5 */
/* @0x130e9c movle r4, #0 */
/* @0x130ea0 movgt r4, #1 */
/* @0x130ea4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x130ea8 cmp r0, #0 */
/* @0x130eac popeq {r3, r4, r5, pc} */
/* @0x130eb0 cmp r4, #0 */
/* @0x130eb4 beq 0x130ed0 <_Z18F_SpriteSetPreciseR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x130eb8 ldr r3, [r0, #0x74] */
/* @0x130ebc cmp r3, #0 */
/* @0x130ec0 beq 0x130ed0 <_Z18F_SpriteSetPreciseR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x130ec4 ldr r1, [r0, #0x3c] */
/* @0x130ec8 cmp r1, #0 */
/* @0x130ecc beq 0x130ee4 <_Z18F_SpriteSetPreciseR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x130ed0 mov r1, r4 */
/* @0x130ed4 bl 0x1e3d68 <_ZN7CSprite20SetCollisionCheckingEb> */
/* @0x130ed8 mov r0, r5 */
/* @0x130edc pop {r3, r4, r5, lr} */
/* @0x130ee0 b 0x130cac <_Z20MarkInstancesAsDirtyi> */
/* @0x130ee4 ldr r0, [pc, #0x8] */
/* @0x130ee8 pop {r3, r4, r5, lr} */
/* @0x130eec add r0, pc, r0 */
/* @0x130ef0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x130ef4 eoreq sp, r0, r0, lsl #9 */

/* ── FUNC 0x130ef8 · F_FontReplace(RValue&, CInstance*, CInstance*, int, RValue*) · size=256 · insn=64 */
/* @0x130ef8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x130efc sub sp, sp, #20 */
/* @0x130f00 mov r1, #0 */
/* @0x130f04 mov r5, r0 */
/* @0x130f08 ldr r4, [sp, #0x38] */
/* @0x130f0c mov r0, r4 */
/* @0x130f10 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130f14 mov r7, r0 */
/* @0x130f18 bl 0xfa2a8 <_Z11Font_Existsi> */
/* @0x130f1c subs r6, r0, #0 */
/* @0x130f20 bne 0x130f50 <_Z13F_FontReplaceR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x130f24 ldr r0, [pc, #0xc8] */
/* @0x130f28 mov r1, r6 */
/* @0x130f2c add r0, pc, r0 */
/* @0x130f30 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x130f34 str r6, [r5, #0xc] */
/* @0x130f38 mov r3, #0 */
/* @0x130f3c str r3, [r5] */
/* @0x130f40 mov r2, r3 */
/* @0x130f44 str r2, [r5, #0x4] */
/* @0x130f48 add sp, sp, #20 */
/* @0x130f4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x130f50 mov r1, #1 */
/* @0x130f54 mov r0, r4 */
/* @0x130f58 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x130f5c mov r1, #2 */
/* @0x130f60 mov r9, r0 */
/* @0x130f64 mov r0, r4 */
/* @0x130f68 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130f6c mov r1, #3 */
/* @0x130f70 mov r8, r0 */
/* @0x130f74 mov r0, r4 */
/* @0x130f78 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x130f7c mov r1, #4 */
/* @0x130f80 mov r6, r0 */
/* @0x130f84 mov r0, r4 */
/* @0x130f88 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x130f8c mov r1, #5 */
/* @0x130f90 mov r11, r0 */
/* @0x130f94 mov r0, r4 */
/* @0x130f98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130f9c mov r1, #6 */
/* @0x130fa0 mov r10, r0 */
/* @0x130fa4 mov r0, r4 */
/* @0x130fa8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x130fac mov r2, r8 */
/* @0x130fb0 mov r3, r6 */
/* @0x130fb4 str r11, [sp] */
/* @0x130fb8 str r10, [sp, #0x4] */
/* @0x130fbc mov r1, r9 */
/* @0x130fc0 str r0, [sp, #0x8] */
/* @0x130fc4 mov r0, r7 */
/* @0x130fc8 bl 0xfa908 <_Z12Font_ReplaceiPKcibbii> */
/* @0x130fcc mov r3, #0 */
/* @0x130fd0 str r3, [r5, #0xc] */
/* @0x130fd4 cmp r0, r3 */
/* @0x130fd8 movne r2, #0 */
/* @0x130fdc movtne r2, #0x3ff0 */
/* @0x130fe0 beq 0x130f38 <_Z13F_FontReplaceR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x130fe4 str r3, [r5] */
/* @0x130fe8 str r2, [r5, #0x4] */
/* @0x130fec add sp, sp, #20 */
/* @0x130ff0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x130ff4 eoreq r12, r0, r4, asr #12 */

/* ── FUNC 0x130ff8 · YYGML_sprite_set_cache_size(int, int) · size=4 · insn=1 */
/* @0x130ff8 bx lr */

/* ── FUNC 0x130ffc · InitResourceFunctions() · size=8052 · insn=2013 */
/* @0x130ffc push {r4, r5, r6, r7, r8, lr} */
/* @0x131000 mov r2, #1 */
/* @0x131004 ldr r4, [pc, #0xff4] */
/* @0x131008 mov r3, #0 */
/* @0x13100c ldr r1, [pc, #0xff0] */
/* @0x131010 add r4, pc, r4 */
/* @0x131014 ldr r0, [pc, #0xfec] */
/* @0x131018 ldr r5, [r4, r1] */
/* @0x13101c add r0, pc, r0 */
/* @0x131020 mov r1, r5 */
/* @0x131024 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131028 ldr r1, [pc, #0xfdc] */
/* @0x13102c ldr r0, [pc, #0xfdc] */
/* @0x131030 mov r2, #1 */
/* @0x131034 mov r3, #0 */
/* @0x131038 add r0, pc, r0 */
/* @0x13103c ldr r1, [r4, r1] */
/* @0x131040 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131044 ldr r0, [pc, #0xfc8] */
/* @0x131048 mov r1, r5 */
/* @0x13104c mov r2, #1 */
/* @0x131050 add r0, pc, r0 */
/* @0x131054 mov r3, #0 */
/* @0x131058 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13105c ldr r1, [pc, #0xfb4] */
/* @0x131060 ldr r0, [pc, #0xfb4] */
/* @0x131064 mov r2, #1 */
/* @0x131068 mov r3, #0 */
/* @0x13106c add r0, pc, r0 */
/* @0x131070 ldr r1, [r4, r1] */
/* @0x131074 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131078 ldr r1, [pc, #0xfa0] */
/* @0x13107c ldr r0, [pc, #0xfa0] */
/* @0x131080 mov r2, #1 */
/* @0x131084 mov r3, #0 */
/* @0x131088 add r0, pc, r0 */
/* @0x13108c ldr r1, [r4, r1] */
/* @0x131090 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131094 ldr r1, [pc, #0xf8c] */
/* @0x131098 ldr r0, [pc, #0xf8c] */
/* @0x13109c mov r2, #1 */
/* @0x1310a0 mov r3, #0 */
/* @0x1310a4 add r0, pc, r0 */
/* @0x1310a8 ldr r1, [r4, r1] */
/* @0x1310ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1310b0 ldr r1, [pc, #0xf78] */
/* @0x1310b4 ldr r0, [pc, #0xf78] */
/* @0x1310b8 mov r2, #1 */
/* @0x1310bc mov r3, #0 */
/* @0x1310c0 add r0, pc, r0 */
/* @0x1310c4 ldr r1, [r4, r1] */
/* @0x1310c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1310cc ldr r1, [pc, #0xf64] */
/* @0x1310d0 ldr r0, [pc, #0xf64] */
/* @0x1310d4 mov r2, #1 */
/* @0x1310d8 mov r3, #0 */
/* @0x1310dc add r0, pc, r0 */
/* @0x1310e0 ldr r1, [r4, r1] */
/* @0x1310e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1310e8 ldr r1, [pc, #0xf50] */
/* @0x1310ec ldr r0, [pc, #0xf50] */
/* @0x1310f0 mov r2, #1 */
/* @0x1310f4 mov r3, #0 */
/* @0x1310f8 add r0, pc, r0 */
/* @0x1310fc ldr r1, [r4, r1] */
/* @0x131100 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131104 ldr r1, [pc, #0xf3c] */
/* @0x131108 ldr r0, [pc, #0xf3c] */
/* @0x13110c mov r2, #1 */
/* @0x131110 mov r3, #0 */
/* @0x131114 add r0, pc, r0 */
/* @0x131118 ldr r1, [r4, r1] */
/* @0x13111c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131120 ldr r1, [pc, #0xf28] */
/* @0x131124 ldr r0, [pc, #0xf28] */
/* @0x131128 mov r2, #1 */
/* @0x13112c mov r3, #0 */
/* @0x131130 add r0, pc, r0 */
/* @0x131134 ldr r1, [r4, r1] */
/* @0x131138 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13113c ldr r1, [pc, #0xf14] */
/* @0x131140 ldr r0, [pc, #0xf14] */
/* @0x131144 mov r2, #1 */
/* @0x131148 mov r3, #0 */
/* @0x13114c add r0, pc, r0 */
/* @0x131150 ldr r1, [r4, r1] */
/* @0x131154 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131158 ldr r1, [pc, #0xf00] */
/* @0x13115c ldr r0, [pc, #0xf00] */
/* @0x131160 mov r2, #1 */
/* @0x131164 mov r3, #0 */
/* @0x131168 add r0, pc, r0 */
/* @0x13116c ldr r1, [r4, r1] */
/* @0x131170 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131174 ldr r1, [pc, #0xeec] */
/* @0x131178 ldr r0, [pc, #0xeec] */
/* @0x13117c mov r2, #1 */
/* @0x131180 mov r3, #0 */
/* @0x131184 add r0, pc, r0 */
/* @0x131188 ldr r1, [r4, r1] */
/* @0x13118c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131190 ldr r1, [pc, #0xed8] */
/* @0x131194 ldr r0, [pc, #0xed8] */
/* @0x131198 mov r2, #1 */
/* @0x13119c mov r3, #0 */
/* @0x1311a0 add r0, pc, r0 */
/* @0x1311a4 ldr r1, [r4, r1] */
/* @0x1311a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1311ac ldr r1, [pc, #0xec4] */
/* @0x1311b0 ldr r0, [pc, #0xec4] */
/* @0x1311b4 mov r2, #1 */
/* @0x1311b8 mov r3, #0 */
/* @0x1311bc add r0, pc, r0 */
/* @0x1311c0 ldr r1, [r4, r1] */
/* @0x1311c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1311c8 ldr r1, [pc, #0xeb0] */
/* @0x1311cc ldr r0, [pc, #0xeb0] */
/* @0x1311d0 mov r2, #1 */
/* @0x1311d4 mov r3, #0 */
/* @0x1311d8 add r0, pc, r0 */
/* @0x1311dc ldr r1, [r4, r1] */
/* @0x1311e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1311e4 ldr r1, [pc, #0xe9c] */
/* @0x1311e8 ldr r0, [pc, #0xe9c] */
/* @0x1311ec mov r2, #9 */
/* @0x1311f0 mov r3, #0 */
/* @0x1311f4 add r0, pc, r0 */
/* @0x1311f8 ldr r1, [r4, r1] */
/* @0x1311fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131200 ldr r1, [pc, #0xe88] */
/* @0x131204 ldr r0, [pc, #0xe88] */
/* @0x131208 mov r2, #2 */
/* @0x13120c mov r3, #0 */
/* @0x131210 add r0, pc, r0 */
/* @0x131214 ldr r1, [r4, r1] */
/* @0x131218 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13121c ldr r1, [pc, #0xe74] */
/* @0x131220 ldr r0, [pc, #0xe74] */
/* @0x131224 mov r2, #3 */
/* @0x131228 mov r3, #0 */
/* @0x13122c add r0, pc, r0 */
/* @0x131230 ldr r1, [r4, r1] */
/* @0x131234 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131238 ldr r1, [pc, #0xe60] */
/* @0x13123c ldr r0, [pc, #0xe60] */
/* @0x131240 mov r2, #2 */
/* @0x131244 mov r3, #0 */
/* @0x131248 add r0, pc, r0 */
/* @0x13124c ldr r1, [r4, r1] */
/* @0x131250 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131254 ldr r1, [pc, #0xe4c] */
/* @0x131258 ldr r0, [pc, #0xe4c] */
/* @0x13125c mov r2, #2 */
/* @0x131260 mov r3, #0 */
/* @0x131264 add r0, pc, r0 */
/* @0x131268 ldr r1, [r4, r1] */
/* @0x13126c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131270 ldr r1, [pc, #0xe38] */
/* @0x131274 ldr r0, [pc, #0xe38] */
/* @0x131278 mov r2, #3 */
/* @0x13127c mov r3, #1 */
/* @0x131280 add r0, pc, r0 */
/* @0x131284 ldr r1, [r4, r1] */
/* @0x131288 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13128c ldr r1, [pc, #0xe24] */
/* @0x131290 ldr r0, [pc, #0xe24] */
/* @0x131294 mov r2, #2 */
/* @0x131298 mov r3, #1 */
/* @0x13129c add r0, pc, r0 */
/* @0x1312a0 ldr r1, [r4, r1] */
/* @0x1312a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1312a8 ldr r1, [pc, #0xe10] */
/* @0x1312ac ldr r0, [pc, #0xe10] */
/* @0x1312b0 mov r2, #5 */
/* @0x1312b4 mov r3, #1 */
/* @0x1312b8 add r0, pc, r0 */
/* @0x1312bc ldr r1, [r4, r1] */
/* @0x1312c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1312c4 ldr r1, [pc, #0xdfc] */
/* @0x1312c8 ldr r0, [pc, #0xdfc] */
/* @0x1312cc mov r2, #2 */
/* @0x1312d0 mov r3, #1 */
/* @0x1312d4 add r0, pc, r0 */
/* @0x1312d8 ldr r1, [r4, r1] */
/* @0x1312dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1312e0 ldr r1, [pc, #0xde8] */
/* @0x1312e4 ldr r0, [pc, #0xde8] */
/* @0x1312e8 mov r3, #1 */
/* @0x1312ec mov r2, #2 */
/* @0x1312f0 ldr r1, [r4, r1] */
/* @0x1312f4 add r0, pc, r0 */
/* @0x1312f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1312fc ldr r3, [pc, #0xdd4] */
/* @0x131300 ldr r1, [pc, #0xdd4] */
/* @0x131304 ldr r6, [r4, r3] */
/* @0x131308 ldr r3, [r6] */
/* @0x13130c cmp r3, #800 */
/* @0x131310 blt 0x132cd8 <_Z21InitResourceFunctionsv+0x1cdc> */
/* @0x131314 ldr r0, [pc, #0xdc4] */
/* @0x131318 mov r2, #6 */
/* @0x13131c mov r3, #1 */
/* @0x131320 ldr r1, [r4, r1] */
/* @0x131324 add r0, pc, r0 */
/* @0x131328 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13132c ldr r1, [pc, #0xdb0] */
/* @0x131330 ldr r0, [pc, #0xdb0] */
/* @0x131334 mov r2, #8 */
/* @0x131338 mov r3, #1 */
/* @0x13133c add r0, pc, r0 */
/* @0x131340 ldr r1, [r4, r1] */
/* @0x131344 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131348 ldr r1, [pc, #0xd9c] */
/* @0x13134c ldr r0, [pc, #0xd9c] */
/* @0x131350 mov r2, #7 */
/* @0x131354 mov r3, #1 */
/* @0x131358 add r0, pc, r0 */
/* @0x13135c ldr r1, [r4, r1] */
/* @0x131360 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131364 ldr r1, [pc, #0xd88] */
/* @0x131368 ldr r0, [pc, #0xd88] */
/* @0x13136c mov r2, #9 */
/* @0x131370 mov r3, #1 */
/* @0x131374 add r0, pc, r0 */
/* @0x131378 ldr r1, [r4, r1] */
/* @0x13137c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131380 ldr r1, [pc, #0xd74] */
/* @0x131384 ldr r0, [pc, #0xd74] */
/* @0x131388 mov r2, #8 */
/* @0x13138c mov r3, #1 */
/* @0x131390 add r0, pc, r0 */
/* @0x131394 ldr r1, [r4, r1] */
/* @0x131398 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13139c ldr r1, [pc, #0xd60] */
/* @0x1313a0 ldr r0, [pc, #0xd60] */
/* @0x1313a4 mov r2, #7 */
/* @0x1313a8 mov r3, #1 */
/* @0x1313ac add r0, pc, r0 */
/* @0x1313b0 ldr r1, [r4, r1] */
/* @0x1313b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1313b8 ldr r1, [pc, #0xd4c] */
/* @0x1313bc ldr r0, [pc, #0xd4c] */
/* @0x1313c0 mov r2, #1 */
/* @0x1313c4 mov r3, r2 */
/* @0x1313c8 add r0, pc, r0 */
/* @0x1313cc ldr r1, [r4, r1] */
/* @0x1313d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1313d4 ldr r1, [pc, #0xd38] */
/* @0x1313d8 ldr r0, [pc, #0xd38] */
/* @0x1313dc mov r2, #2 */
/* @0x1313e0 mov r3, #1 */
/* @0x1313e4 add r0, pc, r0 */
/* @0x1313e8 ldr r1, [r4, r1] */
/* @0x1313ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1313f0 ldr r1, [pc, #0xd24] */
/* @0x1313f4 ldr r0, [pc, #0xd24] */
/* @0x1313f8 mov r2, #2 */
/* @0x1313fc mov r3, #1 */
/* @0x131400 add r0, pc, r0 */
/* @0x131404 ldr r1, [r4, r1] */
/* @0x131408 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13140c ldr r1, [pc, #0xd10] */
/* @0x131410 mov r2, #1 */
/* @0x131414 ldr r0, [pc, #0xd0c] */
/* @0x131418 mov r3, r2 */
/* @0x13141c add r0, pc, r0 */
/* @0x131420 ldr r1, [r4, r1] */
/* @0x131424 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131428 ldr r1, [pc, #0xcfc] */
/* @0x13142c ldr r0, [pc, #0xcfc] */
/* @0x131430 mov r2, #1 */
/* @0x131434 mov r3, r2 */
/* @0x131438 add r0, pc, r0 */
/* @0x13143c ldr r1, [r4, r1] */
/* @0x131440 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131444 ldr r1, [pc, #0xce8] */
/* @0x131448 ldr r0, [pc, #0xce8] */
/* @0x13144c mov r2, #2 */
/* @0x131450 mov r3, #1 */
/* @0x131454 add r0, pc, r0 */
/* @0x131458 ldr r1, [r4, r1] */
/* @0x13145c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131460 ldr r1, [pc, #0xcd4] */
/* @0x131464 ldr r0, [pc, #0xcd4] */
/* @0x131468 mov r2, #2 */
/* @0x13146c mov r3, #1 */
/* @0x131470 add r0, pc, r0 */
/* @0x131474 ldr r1, [r4, r1] */
/* @0x131478 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13147c ldr r1, [pc, #0xcc0] */
/* @0x131480 ldr r0, [pc, #0xcc0] */
/* @0x131484 mov r2, #3 */
/* @0x131488 mov r3, #1 */
/* @0x13148c add r0, pc, r0 */
/* @0x131490 ldr r1, [r4, r1] */
/* @0x131494 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131498 ldr r1, [pc, #0xcac] */
/* @0x13149c ldr r0, [pc, #0xcac] */
/* @0x1314a0 mov r2, #1 */
/* @0x1314a4 mov r3, r2 */
/* @0x1314a8 add r0, pc, r0 */
/* @0x1314ac ldr r1, [r4, r1] */
/* @0x1314b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1314b4 ldr r1, [pc, #0xc98] */
/* @0x1314b8 ldr r0, [pc, #0xc98] */
/* @0x1314bc mov r2, #1 */
/* @0x1314c0 mov r3, r2 */
/* @0x1314c4 add r0, pc, r0 */
/* @0x1314c8 ldr r1, [r4, r1] */
/* @0x1314cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1314d0 ldr r1, [pc, #0xc84] */
/* @0x1314d4 ldr r0, [pc, #0xc84] */
/* @0x1314d8 mov r2, #1 */
/* @0x1314dc mov r3, r2 */
/* @0x1314e0 add r0, pc, r0 */
/* @0x1314e4 ldr r1, [r4, r1] */
/* @0x1314e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1314ec ldr r1, [pc, #0xc70] */
/* @0x1314f0 ldr r0, [pc, #0xc70] */
/* @0x1314f4 mov r2, #1 */
/* @0x1314f8 mov r3, r2 */
/* @0x1314fc add r0, pc, r0 */
/* @0x131500 ldr r1, [r4, r1] */
/* @0x131504 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131508 ldr r3, [pc, #0xc5c] */
/* @0x13150c ldr r5, [r4, r3] */
/* @0x131510 ldrb r3, [r5] */
/* @0x131514 cmp r3, #0 */
/* @0x131518 bne 0x132f18 <_Z21InitResourceFunctionsv+0x1f1c> */
/* @0x13151c ldr r1, [pc, #0xc4c] */
/* @0x131520 mov r2, #1 */
/* @0x131524 ldr r0, [pc, #0xc48] */
/* @0x131528 mov r3, #0 */
/* @0x13152c ldr r7, [r4, r1] */
/* @0x131530 add r0, pc, r0 */
/* @0x131534 mov r1, r7 */
/* @0x131538 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13153c ldr r1, [pc, #0xc34] */
/* @0x131540 ldr r0, [pc, #0xc34] */
/* @0x131544 mov r2, #1 */
/* @0x131548 mov r3, #0 */
/* @0x13154c add r0, pc, r0 */
/* @0x131550 ldr r1, [r4, r1] */
/* @0x131554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131558 ldr r0, [pc, #0xc20] */
/* @0x13155c mov r1, r7 */
/* @0x131560 mov r2, #1 */
/* @0x131564 add r0, pc, r0 */
/* @0x131568 mov r3, #0 */
/* @0x13156c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131570 ldr r1, [pc, #0xc0c] */
/* @0x131574 ldr r0, [pc, #0xc0c] */
/* @0x131578 mov r2, #1 */
/* @0x13157c mov r3, #0 */
/* @0x131580 add r0, pc, r0 */
/* @0x131584 ldr r1, [r4, r1] */
/* @0x131588 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13158c ldr r1, [pc, #0xbf8] */
/* @0x131590 ldr r0, [pc, #0xbf8] */
/* @0x131594 mov r2, #1 */
/* @0x131598 mov r3, #0 */
/* @0x13159c add r0, pc, r0 */
/* @0x1315a0 ldr r1, [r4, r1] */
/* @0x1315a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1315a8 ldr r1, [pc, #0xbe4] */
/* @0x1315ac ldr r0, [pc, #0xbe4] */
/* @0x1315b0 mov r2, #1 */
/* @0x1315b4 mov r3, #0 */
/* @0x1315b8 add r0, pc, r0 */
/* @0x1315bc ldr r1, [r4, r1] */
/* @0x1315c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1315c4 ldr r1, [pc, #0xbd0] */
/* @0x1315c8 ldr r0, [pc, #0xbd0] */
/* @0x1315cc mov r2, #1 */
/* @0x1315d0 mov r3, #0 */
/* @0x1315d4 add r0, pc, r0 */
/* @0x1315d8 ldr r1, [r4, r1] */
/* @0x1315dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1315e0 ldr r1, [pc, #0xbbc] */
/* @0x1315e4 ldr r0, [pc, #0xbbc] */
/* @0x1315e8 mov r2, #1 */
/* @0x1315ec mov r3, #0 */
/* @0x1315f0 add r0, pc, r0 */
/* @0x1315f4 ldr r1, [r4, r1] */
/* @0x1315f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1315fc ldr r1, [pc, #0xba8] */
/* @0x131600 ldr r0, [pc, #0xba8] */
/* @0x131604 mov r3, #1 */
/* @0x131608 mov r2, #2 */
/* @0x13160c ldr r1, [r4, r1] */
/* @0x131610 add r0, pc, r0 */
/* @0x131614 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131618 ldr r3, [r6] */
/* @0x13161c ldr r1, [pc, #0xb90] */
/* @0x131620 cmp r3, #800 */
/* @0x131624 blt 0x132db8 <_Z21InitResourceFunctionsv+0x1dbc> */
/* @0x131628 ldr r6, [r4, r1] */
/* @0x13162c mov r2, #3 */
/* @0x131630 ldr r0, [pc, #0xb80] */
/* @0x131634 mov r3, #1 */
/* @0x131638 add r0, pc, r0 */
/* @0x13163c mov r1, r6 */
/* @0x131640 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131644 ldr r0, [pc, #0xb70] */
/* @0x131648 mov r1, r6 */
/* @0x13164c mov r2, #3 */
/* @0x131650 add r0, pc, r0 */
/* @0x131654 mov r3, #1 */
/* @0x131658 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13165c ldr r1, [pc, #0xfe0] */
/* @0x131660 ldr r0, [pc, #0xb58] */
/* @0x131664 mov r2, #4 */
/* @0x131668 mov r3, #1 */
/* @0x13166c add r0, pc, r0 */
/* @0x131670 ldr r1, [r4, r1] */
/* @0x131674 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131678 ldr r1, [pc, #0xfcc] */
/* @0x13167c ldr r0, [pc, #0xb40] */
/* @0x131680 mov r2, #6 */
/* @0x131684 mov r3, #1 */
/* @0x131688 add r0, pc, r0 */
/* @0x13168c ldr r1, [r4, r1] */
/* @0x131690 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131694 ldr r1, [pc, #0xfb8] */
/* @0x131698 ldr r0, [pc, #0xb28] */
/* @0x13169c mov r2, #7 */
/* @0x1316a0 mov r3, #1 */
/* @0x1316a4 add r0, pc, r0 */
/* @0x1316a8 ldr r1, [r4, r1] */
/* @0x1316ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1316b0 ldr r1, [pc, #0xfa4] */
/* @0x1316b4 ldr r0, [pc, #0xb10] */
/* @0x1316b8 mov r2, #5 */
/* @0x1316bc mov r3, #1 */
/* @0x1316c0 add r0, pc, r0 */
/* @0x1316c4 ldr r1, [r4, r1] */
/* @0x1316c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1316cc ldr r1, [pc, #0xf90] */
/* @0x1316d0 ldr r0, [pc, #0xaf8] */
/* @0x1316d4 mov r2, #3 */
/* @0x1316d8 mov r3, #1 */
/* @0x1316dc add r0, pc, r0 */
/* @0x1316e0 ldr r1, [r4, r1] */
/* @0x1316e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1316e8 ldr r1, [pc, #0xae4] */
/* @0x1316ec ldr r0, [pc, #0xae4] */
/* @0x1316f0 mov r2, #1 */
/* @0x1316f4 mov r3, r2 */
/* @0x1316f8 add r0, pc, r0 */
/* @0x1316fc ldr r1, [r4, r1] */
/* @0x131700 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131704 ldr r1, [pc, #0xad0] */
/* @0x131708 ldr r0, [pc, #0xad0] */
/* @0x13170c mov r2, #2 */
/* @0x131710 mov r3, #1 */
/* @0x131714 add r0, pc, r0 */
/* @0x131718 ldr r1, [r4, r1] */
/* @0x13171c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131720 ldr r1, [pc, #0xabc] */
/* @0x131724 mov r2, #1 */
/* @0x131728 ldr r0, [pc, #0xab8] */
/* @0x13172c mov r3, r2 */
/* @0x131730 add r0, pc, r0 */
/* @0x131734 ldr r1, [r4, r1] */
/* @0x131738 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13173c ldr r1, [pc, #0xaa8] */
/* @0x131740 ldr r0, [pc, #0xaa8] */
/* @0x131744 mov r2, #1 */
/* @0x131748 mov r3, r2 */
/* @0x13174c add r0, pc, r0 */
/* @0x131750 ldr r1, [r4, r1] */
/* @0x131754 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131758 ldr r1, [pc, #0xa94] */
/* @0x13175c ldr r0, [pc, #0xa94] */
/* @0x131760 mov r2, #2 */
/* @0x131764 mov r3, #1 */
/* @0x131768 add r0, pc, r0 */
/* @0x13176c ldr r1, [r4, r1] */
/* @0x131770 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131774 ldr r1, [pc, #0xa80] */
/* @0x131778 ldr r0, [pc, #0xa80] */
/* @0x13177c mov r2, #2 */
/* @0x131780 mov r3, #1 */
/* @0x131784 add r0, pc, r0 */
/* @0x131788 ldr r1, [r4, r1] */
/* @0x13178c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131790 ldr r1, [pc, #0xa6c] */
/* @0x131794 ldr r0, [pc, #0xa6c] */
/* @0x131798 mov r2, #1 */
/* @0x13179c mov r3, r2 */
/* @0x1317a0 add r0, pc, r0 */
/* @0x1317a4 ldr r1, [r4, r1] */
/* @0x1317a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1317ac ldr r1, [pc, #0xa58] */
/* @0x1317b0 ldr r0, [pc, #0xa58] */
/* @0x1317b4 mov r2, #1 */
/* @0x1317b8 mov r3, r2 */
/* @0x1317bc add r0, pc, r0 */
/* @0x1317c0 ldr r1, [r4, r1] */
/* @0x1317c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1317c8 ldr r1, [pc, #0xa44] */
/* @0x1317cc ldr r0, [pc, #0xa44] */
/* @0x1317d0 mov r2, #1 */
/* @0x1317d4 mov r3, r2 */
/* @0x1317d8 add r0, pc, r0 */
/* @0x1317dc ldr r1, [r4, r1] */
/* @0x1317e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1317e4 ldr r1, [pc, #0xa30] */
/* @0x1317e8 ldr r0, [pc, #0xa30] */
/* @0x1317ec mov r2, #1 */
/* @0x1317f0 mov r3, r2 */
/* @0x1317f4 add r0, pc, r0 */
/* @0x1317f8 ldr r1, [r4, r1] */
/* @0x1317fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131800 ldr r1, [pc, #0xa1c] */
/* @0x131804 ldr r0, [pc, #0xa1c] */
/* @0x131808 mov r2, #1 */
/* @0x13180c mov r3, #0 */
/* @0x131810 ldr r6, [r4, r1] */
/* @0x131814 add r0, pc, r0 */
/* @0x131818 mov r1, r6 */
/* @0x13181c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131820 ldr r1, [pc, #0xa04] */
/* @0x131824 ldr r0, [pc, #0xa04] */
/* @0x131828 mov r2, #1 */
/* @0x13182c mov r3, #0 */
/* @0x131830 add r0, pc, r0 */
/* @0x131834 ldr r1, [r4, r1] */
/* @0x131838 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13183c ldr r0, [pc, #0x9f0] */
/* @0x131840 mov r1, r6 */
/* @0x131844 mov r2, #1 */
/* @0x131848 add r0, pc, r0 */
/* @0x13184c mov r3, #0 */
/* @0x131850 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131854 ldr r1, [pc, #0x9dc] */
/* @0x131858 ldr r0, [pc, #0x9dc] */
/* @0x13185c mov r2, #1 */
/* @0x131860 mov r3, #0 */
/* @0x131864 add r0, pc, r0 */
/* @0x131868 ldr r1, [r4, r1] */
/* @0x13186c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131870 ldr r1, [pc, #0x9c8] */
/* @0x131874 ldr r0, [pc, #0x9c8] */
/* @0x131878 mov r2, #1 */
/* @0x13187c mov r3, #0 */
/* @0x131880 add r0, pc, r0 */
/* @0x131884 ldr r1, [r4, r1] */
/* @0x131888 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13188c ldr r1, [pc, #0x9b4] */
/* @0x131890 ldr r0, [pc, #0x9b4] */
/* @0x131894 mov r2, #1 */
/* @0x131898 mov r3, #0 */
/* @0x13189c add r0, pc, r0 */
/* @0x1318a0 ldr r1, [r4, r1] */
/* @0x1318a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1318a8 ldr r1, [pc, #0x9a0] */
/* @0x1318ac ldr r0, [pc, #0x9a0] */
/* @0x1318b0 mov r2, #1 */
/* @0x1318b4 mov r3, #0 */
/* @0x1318b8 add r0, pc, r0 */
/* @0x1318bc ldr r1, [r4, r1] */
/* @0x1318c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1318c4 ldr r1, [pc, #0x98c] */
/* @0x1318c8 ldr r0, [pc, #0x98c] */
/* @0x1318cc mov r2, #3 */
/* @0x1318d0 mov r3, #1 */
/* @0x1318d4 add r0, pc, r0 */
/* @0x1318d8 ldr r1, [r4, r1] */
/* @0x1318dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1318e0 ldr r1, [pc, #0x978] */
/* @0x1318e4 ldr r0, [pc, #0x978] */
/* @0x1318e8 mov r2, #4 */
/* @0x1318ec mov r3, #1 */
/* @0x1318f0 add r0, pc, r0 */
/* @0x1318f4 ldr r1, [r4, r1] */
/* @0x1318f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1318fc ldr r1, [pc, #0x964] */
/* @0x131900 ldr r0, [pc, #0x964] */
/* @0x131904 mov r2, #1 */
/* @0x131908 mov r3, r2 */
/* @0x13190c ldr r6, [r4, r1] */
/* @0x131910 add r0, pc, r0 */
/* @0x131914 mov r1, r6 */
/* @0x131918 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13191c ldr r0, [pc, #0x94c] */
/* @0x131920 mov r2, #1 */
/* @0x131924 mov r1, r6 */
/* @0x131928 mov r3, r2 */
/* @0x13192c add r0, pc, r0 */
/* @0x131930 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131934 ldr r1, [pc, #0x938] */
/* @0x131938 ldr r0, [pc, #0x938] */
/* @0x13193c mov r2, #1 */
/* @0x131940 mov r3, #0 */
/* @0x131944 ldr r6, [r4, r1] */
/* @0x131948 add r0, pc, r0 */
/* @0x13194c mov r1, r6 */
/* @0x131950 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131954 ldr r1, [pc, #0x920] */
/* @0x131958 ldr r0, [pc, #0x920] */
/* @0x13195c mov r2, #1 */
/* @0x131960 mov r3, #0 */
/* @0x131964 add r0, pc, r0 */
/* @0x131968 ldr r1, [r4, r1] */
/* @0x13196c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131970 ldr r0, [pc, #0x90c] */
/* @0x131974 mov r1, r6 */
/* @0x131978 mov r2, #1 */
/* @0x13197c add r0, pc, r0 */
/* @0x131980 mov r3, #0 */
/* @0x131984 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131988 ldr r1, [pc, #0x8f8] */
/* @0x13198c ldr r0, [pc, #0x8f8] */
/* @0x131990 mov r2, #1 */
/* @0x131994 mov r3, #0 */
/* @0x131998 add r0, pc, r0 */
/* @0x13199c ldr r1, [r4, r1] */
/* @0x1319a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1319a4 ldr r1, [pc, #0x8e4] */
/* @0x1319a8 ldr r0, [pc, #0x8e4] */
/* @0x1319ac mov r2, #1 */
/* @0x1319b0 mov r3, #0 */
/* @0x1319b4 add r0, pc, r0 */
/* @0x1319b8 ldr r1, [r4, r1] */
/* @0x1319bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1319c0 ldr r1, [pc, #0x8d0] */
/* @0x1319c4 ldr r0, [pc, #0x8d0] */
/* @0x1319c8 mov r2, #1 */
/* @0x1319cc mov r3, #0 */
/* @0x1319d0 add r0, pc, r0 */
/* @0x1319d4 ldr r1, [r4, r1] */
/* @0x1319d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1319dc ldr r1, [pc, #0x8bc] */
/* @0x1319e0 ldr r0, [pc, #0x8bc] */
/* @0x1319e4 mov r2, #1 */
/* @0x1319e8 mov r3, #0 */
/* @0x1319ec add r0, pc, r0 */
/* @0x1319f0 ldr r1, [r4, r1] */
/* @0x1319f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1319f8 ldr r1, [pc, #0x8a8] */
/* @0x1319fc ldr r0, [pc, #0x8a8] */
/* @0x131a00 mov r2, #1 */
/* @0x131a04 mov r3, #0 */
/* @0x131a08 add r0, pc, r0 */
/* @0x131a0c ldr r1, [r4, r1] */
/* @0x131a10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131a14 ldr r1, [pc, #0x894] */
/* @0x131a18 ldr r0, [pc, #0x894] */
/* @0x131a1c mov r2, #1 */
/* @0x131a20 mov r3, #0 */
/* @0x131a24 add r0, pc, r0 */
/* @0x131a28 ldr r1, [r4, r1] */
/* @0x131a2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131a30 ldr r1, [pc, #0x880] */
/* @0x131a34 ldr r0, [pc, #0x880] */
/* @0x131a38 mov r2, #1 */
/* @0x131a3c mov r3, r2 */
/* @0x131a40 add r0, pc, r0 */
/* @0x131a44 ldr r1, [r4, r1] */
/* @0x131a48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131a4c ldr r1, [pc, #0x86c] */
/* @0x131a50 ldr r0, [pc, #0x86c] */
/* @0x131a54 mov r2, #0 */
/* @0x131a58 mov r3, #1 */
/* @0x131a5c add r0, pc, r0 */
/* @0x131a60 ldr r1, [r4, r1] */
/* @0x131a64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131a68 ldr r1, [pc, #0x858] */
/* @0x131a6c ldr r0, [pc, #0x858] */
/* @0x131a70 mov r2, #6 */
/* @0x131a74 mov r3, #1 */
/* @0x131a78 add r0, pc, r0 */
/* @0x131a7c ldr r1, [r4, r1] */
/* @0x131a80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131a84 ldr r1, [pc, #0x844] */
/* @0x131a88 ldr r0, [pc, #0x844] */
/* @0x131a8c mov r2, #4 */
/* @0x131a90 mov r3, #1 */
/* @0x131a94 add r0, pc, r0 */
/* @0x131a98 ldr r1, [r4, r1] */
/* @0x131a9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131aa0 ldr r1, [pc, #0x830] */
/* @0x131aa4 ldr r0, [pc, #0x830] */
/* @0x131aa8 mov r2, #4 */
/* @0x131aac mov r3, #1 */
/* @0x131ab0 add r0, pc, r0 */
/* @0x131ab4 ldr r1, [r4, r1] */
/* @0x131ab8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131abc ldr r1, [pc, #0x81c] */
/* @0x131ac0 ldr r0, [pc, #0x81c] */
/* @0x131ac4 mov r2, #5 */
/* @0x131ac8 mov r3, #1 */
/* @0x131acc add r0, pc, r0 */
/* @0x131ad0 ldr r1, [r4, r1] */
/* @0x131ad4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131ad8 ldr r1, [pc, #0x808] */
/* @0x131adc ldr r0, [pc, #0x808] */
/* @0x131ae0 mov r2, #5 */
/* @0x131ae4 mov r3, #1 */
/* @0x131ae8 add r0, pc, r0 */
/* @0x131aec ldr r1, [r4, r1] */
/* @0x131af0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131af4 ldr r1, [pc, #0x7f4] */
/* @0x131af8 ldr r0, [pc, #0x7f4] */
/* @0x131afc mov r2, #1 */
/* @0x131b00 mov r3, r2 */
/* @0x131b04 add r0, pc, r0 */
/* @0x131b08 ldr r1, [r4, r1] */
/* @0x131b0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131b10 ldr r1, [pc, #0x7e0] */
/* @0x131b14 ldr r0, [pc, #0x7e0] */
/* @0x131b18 mov r2, #1 */
/* @0x131b1c mov r3, r2 */
/* @0x131b20 add r0, pc, r0 */
/* @0x131b24 ldr r1, [r4, r1] */
/* @0x131b28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131b2c ldr r1, [pc, #0x7cc] */
/* @0x131b30 ldr r0, [pc, #0x7cc] */
/* @0x131b34 mov r2, #0 */
/* @0x131b38 mov r3, #1 */
/* @0x131b3c add r0, pc, r0 */
/* @0x131b40 ldr r1, [r4, r1] */
/* @0x131b44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131b48 ldr r1, [pc, #0x7b8] */
/* @0x131b4c ldr r0, [pc, #0x7b8] */
/* @0x131b50 mov r2, #1 */
/* @0x131b54 mov r3, #0 */
/* @0x131b58 ldr r6, [r4, r1] */
/* @0x131b5c add r0, pc, r0 */
/* @0x131b60 mov r1, r6 */
/* @0x131b64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131b68 ldr r1, [pc, #0x7a0] */
/* @0x131b6c ldr r0, [pc, #0x7a0] */
/* @0x131b70 mov r2, #1 */
/* @0x131b74 mov r3, #0 */
/* @0x131b78 add r0, pc, r0 */
/* @0x131b7c ldr r1, [r4, r1] */
/* @0x131b80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131b84 ldr r0, [pc, #0x78c] */
/* @0x131b88 mov r1, r6 */
/* @0x131b8c mov r2, #1 */
/* @0x131b90 add r0, pc, r0 */
/* @0x131b94 mov r3, #0 */
/* @0x131b98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131b9c ldr r1, [pc, #0x778] */
/* @0x131ba0 ldr r0, [pc, #0x778] */
/* @0x131ba4 mov r2, #1 */
/* @0x131ba8 mov r3, #0 */
/* @0x131bac add r0, pc, r0 */
/* @0x131bb0 ldr r1, [r4, r1] */
/* @0x131bb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131bb8 ldr r1, [pc, #0x764] */
/* @0x131bbc ldr r0, [pc, #0x764] */
/* @0x131bc0 mvn r2, #0 */
/* @0x131bc4 mov r3, #0 */
/* @0x131bc8 add r0, pc, r0 */
/* @0x131bcc ldr r1, [r4, r1] */
/* @0x131bd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131bd4 ldr r1, [pc, #0x750] */
/* @0x131bd8 ldr r0, [pc, #0x750] */
/* @0x131bdc mov r2, #1 */
/* @0x131be0 mov r3, #0 */
/* @0x131be4 ldr r6, [r4, r1] */
/* @0x131be8 add r0, pc, r0 */
/* @0x131bec mov r1, r6 */
/* @0x131bf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131bf4 ldr r1, [pc, #0x738] */
/* @0x131bf8 ldr r0, [pc, #0x738] */
/* @0x131bfc mov r2, #1 */
/* @0x131c00 mov r3, #0 */
/* @0x131c04 add r0, pc, r0 */
/* @0x131c08 ldr r1, [r4, r1] */
/* @0x131c0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131c10 ldr r0, [pc, #0x724] */
/* @0x131c14 mov r1, r6 */
/* @0x131c18 mov r2, #1 */
/* @0x131c1c add r0, pc, r0 */
/* @0x131c20 mov r3, #0 */
/* @0x131c24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131c28 ldr r1, [pc, #0x710] */
/* @0x131c2c ldr r0, [pc, #0x710] */
/* @0x131c30 mov r2, #1 */
/* @0x131c34 mov r3, #0 */
/* @0x131c38 add r0, pc, r0 */
/* @0x131c3c ldr r1, [r4, r1] */
/* @0x131c40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131c44 ldr r1, [pc, #0x6fc] */
/* @0x131c48 ldr r0, [pc, #0x6fc] */
/* @0x131c4c mov r2, #2 */
/* @0x131c50 mov r3, #0 */
/* @0x131c54 add r0, pc, r0 */
/* @0x131c58 ldr r1, [r4, r1] */
/* @0x131c5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131c60 ldr r1, [pc, #0x6e8] */
/* @0x131c64 ldr r0, [pc, #0x6e8] */
/* @0x131c68 mov r2, #1 */
/* @0x131c6c mov r3, #0 */
/* @0x131c70 add r0, pc, r0 */
/* @0x131c74 ldr r1, [r4, r1] */
/* @0x131c78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131c7c ldr r1, [pc, #0x6d4] */
/* @0x131c80 ldr r0, [pc, #0x6d4] */
/* @0x131c84 mov r2, #1 */
/* @0x131c88 mov r3, #0 */
/* @0x131c8c add r0, pc, r0 */
/* @0x131c90 ldr r1, [r4, r1] */
/* @0x131c94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131c98 ldr r1, [pc, #0x6c0] */
/* @0x131c9c ldr r0, [pc, #0x6c0] */
/* @0x131ca0 mov r2, #1 */
/* @0x131ca4 mov r3, #0 */
/* @0x131ca8 add r0, pc, r0 */
/* @0x131cac ldr r1, [r4, r1] */
/* @0x131cb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131cb4 ldr r1, [pc, #0x6ac] */
/* @0x131cb8 ldr r0, [pc, #0x6ac] */
/* @0x131cbc mov r2, #1 */
/* @0x131cc0 mov r3, #0 */
/* @0x131cc4 add r0, pc, r0 */
/* @0x131cc8 ldr r1, [r4, r1] */
/* @0x131ccc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131cd0 ldr r1, [pc, #0x698] */
/* @0x131cd4 ldr r0, [pc, #0x698] */
/* @0x131cd8 mov r2, #2 */
/* @0x131cdc mov r3, #0 */
/* @0x131ce0 add r0, pc, r0 */
/* @0x131ce4 ldr r1, [r4, r1] */
/* @0x131ce8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131cec ldr r1, [pc, #0x684] */
/* @0x131cf0 ldr r0, [pc, #0x684] */
/* @0x131cf4 mov r2, #2 */
/* @0x131cf8 mov r3, #0 */
/* @0x131cfc add r0, pc, r0 */
/* @0x131d00 ldr r1, [r4, r1] */
/* @0x131d04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131d08 ldr r1, [pc, #0x670] */
/* @0x131d0c ldr r0, [pc, #0x670] */
/* @0x131d10 mov r2, #2 */
/* @0x131d14 mov r3, #0 */
/* @0x131d18 add r0, pc, r0 */
/* @0x131d1c ldr r1, [r4, r1] */
/* @0x131d20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131d24 ldr r1, [pc, #0x65c] */
/* @0x131d28 ldr r0, [pc, #0x65c] */
/* @0x131d2c mov r2, #2 */
/* @0x131d30 mov r3, #0 */
/* @0x131d34 add r0, pc, r0 */
/* @0x131d38 ldr r1, [r4, r1] */
/* @0x131d3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131d40 ldr r1, [pc, #0x648] */
/* @0x131d44 ldr r0, [pc, #0x648] */
/* @0x131d48 mov r2, #2 */
/* @0x131d4c mov r3, #0 */
/* @0x131d50 add r0, pc, r0 */
/* @0x131d54 ldr r1, [r4, r1] */
/* @0x131d58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131d5c ldr r1, [pc, #0x634] */
/* @0x131d60 ldr r0, [pc, #0x634] */
/* @0x131d64 mov r2, #2 */
/* @0x131d68 mov r3, #0 */
/* @0x131d6c add r0, pc, r0 */
/* @0x131d70 ldr r1, [r4, r1] */
/* @0x131d74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131d78 ldr r1, [pc, #0x620] */
/* @0x131d7c ldr r0, [pc, #0x620] */
/* @0x131d80 mov r2, #2 */
/* @0x131d84 mov r3, #1 */
/* @0x131d88 add r0, pc, r0 */
/* @0x131d8c ldr r1, [r4, r1] */
/* @0x131d90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131d94 ldr r1, [pc, #0x60c] */
/* @0x131d98 ldr r0, [pc, #0x60c] */
/* @0x131d9c mov r2, #2 */
/* @0x131da0 mov r3, #1 */
/* @0x131da4 add r0, pc, r0 */
/* @0x131da8 ldr r1, [r4, r1] */
/* @0x131dac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131db0 ldr r1, [pc, #0x5f8] */
/* @0x131db4 ldr r0, [pc, #0x5f8] */
/* @0x131db8 mov r2, #2 */
/* @0x131dbc mov r3, #1 */
/* @0x131dc0 add r0, pc, r0 */
/* @0x131dc4 ldr r1, [r4, r1] */
/* @0x131dc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131dcc ldr r1, [pc, #0x5e4] */
/* @0x131dd0 ldr r0, [pc, #0x5e4] */
/* @0x131dd4 mov r2, #0 */
/* @0x131dd8 mov r3, #1 */
/* @0x131ddc add r0, pc, r0 */
/* @0x131de0 ldr r1, [r4, r1] */
/* @0x131de4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131de8 ldr r1, [pc, #0x5d0] */
/* @0x131dec ldr r0, [pc, #0x5d0] */
/* @0x131df0 mov r2, #1 */
/* @0x131df4 mov r3, r2 */
/* @0x131df8 add r0, pc, r0 */
/* @0x131dfc ldr r1, [r4, r1] */
/* @0x131e00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131e04 ldr r1, [pc, #0x5bc] */
/* @0x131e08 ldr r0, [pc, #0x5bc] */
/* @0x131e0c mov r2, #2 */
/* @0x131e10 mov r3, #1 */
/* @0x131e14 add r0, pc, r0 */
/* @0x131e18 ldr r1, [r4, r1] */
/* @0x131e1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131e20 ldr r1, [pc, #0x5a8] */
/* @0x131e24 ldr r0, [pc, #0x5a8] */
/* @0x131e28 mov r2, #2 */
/* @0x131e2c mov r3, #1 */
/* @0x131e30 add r0, pc, r0 */
/* @0x131e34 ldr r1, [r4, r1] */
/* @0x131e38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131e3c ldr r1, [pc, #0x594] */
/* @0x131e40 ldr r0, [pc, #0x594] */
/* @0x131e44 mov r2, #1 */
/* @0x131e48 mov r3, r2 */
/* @0x131e4c add r0, pc, r0 */
/* @0x131e50 ldr r1, [r4, r1] */
/* @0x131e54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131e58 ldr r1, [pc, #0x580] */
/* @0x131e5c ldr r0, [pc, #0x580] */
/* @0x131e60 mov r2, #4 */
/* @0x131e64 mov r3, #1 */
/* @0x131e68 add r0, pc, r0 */
/* @0x131e6c ldr r1, [r4, r1] */
/* @0x131e70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131e74 ldr r1, [pc, #0x56c] */
/* @0x131e78 ldr r0, [pc, #0x56c] */
/* @0x131e7c mov r2, #5 */
/* @0x131e80 mov r3, #1 */
/* @0x131e84 add r0, pc, r0 */
/* @0x131e88 ldr r1, [r4, r1] */
/* @0x131e8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131e90 ldr r1, [pc, #0x558] */
/* @0x131e94 ldr r0, [pc, #0x558] */
/* @0x131e98 mov r2, #5 */
/* @0x131e9c mov r3, #1 */
/* @0x131ea0 add r0, pc, r0 */
/* @0x131ea4 ldr r1, [r4, r1] */
/* @0x131ea8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131eac ldr r1, [pc, #0x544] */
/* @0x131eb0 ldr r0, [pc, #0x544] */
/* @0x131eb4 mov r2, #2 */
/* @0x131eb8 mov r3, #1 */
/* @0x131ebc add r0, pc, r0 */
/* @0x131ec0 ldr r1, [r4, r1] */
/* @0x131ec4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131ec8 ldr r1, [pc, #0x530] */
/* @0x131ecc ldr r0, [pc, #0x530] */
/* @0x131ed0 mov r2, #1 */
/* @0x131ed4 mov r3, r2 */
/* @0x131ed8 add r0, pc, r0 */
/* @0x131edc ldr r1, [r4, r1] */
/* @0x131ee0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131ee4 ldr r1, [pc, #0x51c] */
/* @0x131ee8 ldr r0, [pc, #0x51c] */
/* @0x131eec mov r2, #1 */
/* @0x131ef0 mov r3, r2 */
/* @0x131ef4 add r0, pc, r0 */
/* @0x131ef8 ldr r1, [r4, r1] */
/* @0x131efc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131f00 ldr r1, [pc, #0x508] */
/* @0x131f04 ldr r0, [pc, #0x508] */
/* @0x131f08 mov r2, #1 */
/* @0x131f0c mov r3, r2 */
/* @0x131f10 add r0, pc, r0 */
/* @0x131f14 ldr r1, [r4, r1] */
/* @0x131f18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131f1c ldr r1, [pc, #0x4f4] */
/* @0x131f20 ldr r0, [pc, #0x4f4] */
/* @0x131f24 mov r2, #1 */
/* @0x131f28 mov r3, r2 */
/* @0x131f2c add r0, pc, r0 */
/* @0x131f30 ldr r1, [r4, r1] */
/* @0x131f34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131f38 ldr r1, [pc, #0x4e0] */
/* @0x131f3c ldr r0, [pc, #0x4e0] */
/* @0x131f40 mov r2, #2 */
/* @0x131f44 mov r3, #1 */
/* @0x131f48 add r0, pc, r0 */
/* @0x131f4c ldr r1, [r4, r1] */
/* @0x131f50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131f54 ldr r1, [pc, #0x4cc] */
/* @0x131f58 ldr r0, [pc, #0x4cc] */
/* @0x131f5c mov r2, #3 */
/* @0x131f60 mov r3, #1 */
/* @0x131f64 add r0, pc, r0 */
/* @0x131f68 ldr r1, [r4, r1] */
/* @0x131f6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131f70 ldr r1, [pc, #0x4b8] */
/* @0x131f74 ldr r0, [pc, #0x4b8] */
/* @0x131f78 mov r2, #3 */
/* @0x131f7c mov r3, #1 */
/* @0x131f80 add r0, pc, r0 */
/* @0x131f84 ldr r1, [r4, r1] */
/* @0x131f88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131f8c ldr r1, [pc, #0x4a4] */
/* @0x131f90 ldr r0, [pc, #0x4a4] */
/* @0x131f94 mov r2, #1 */
/* @0x131f98 mov r3, #0 */
/* @0x131f9c ldr r6, [r4, r1] */
/* @0x131fa0 add r0, pc, r0 */
/* @0x131fa4 mov r1, r6 */
/* @0x131fa8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131fac ldr r1, [pc, #0x48c] */
/* @0x131fb0 ldr r0, [pc, #0x48c] */
/* @0x131fb4 mov r2, #1 */
/* @0x131fb8 mov r3, #0 */
/* @0x131fbc add r0, pc, r0 */
/* @0x131fc0 ldr r1, [r4, r1] */
/* @0x131fc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131fc8 ldr r0, [pc, #0x478] */
/* @0x131fcc mov r1, r6 */
/* @0x131fd0 mov r2, #1 */
/* @0x131fd4 add r0, pc, r0 */
/* @0x131fd8 mov r3, #0 */
/* @0x131fdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131fe0 ldr r1, [pc, #0x464] */
/* @0x131fe4 ldr r0, [pc, #0x464] */
/* @0x131fe8 mov r2, #0 */
/* @0x131fec mov r3, #1 */
/* @0x131ff0 add r0, pc, r0 */
/* @0x131ff4 ldr r1, [r4, r1] */
/* @0x131ff8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x131ffc b 0x1326ac <_Z21InitResourceFunctionsv+0x16b0> */
/* @0x132000 eoreq r0, r12, r0, asr #24 */
/* @0x132004 .word 0xffffd0e4 */
/* @0x132008 .word 0x0020d3b4 */
/* @0x13200c .word 0xffffd0e8 */
/* @0x132010 eoreq sp, r0, r4, lsr #7 */
/* @0x132014 mlaeq r0, r12, r3, sp */
/* @0x132018 .word 0xffffd0ec */
/* @0x13201c mlaeq r0, r0, r3, sp */
/* @0x132020 .word 0xffffd0f0 */
/* @0x132024 eoreq sp, r0, r8, lsl #7 */
/* @0x132028 .word 0xffffd0f4 */
/* @0x13202c eoreq sp, r0, r0, lsl #7 */
/* @0x132030 .word 0xffffd0f8 */
/* @0x132034 eoreq sp, r0, r8, ror r3 */
/* @0x132038 .word 0xffffd0fc */
/* @0x13203c eoreq sp, r0, r4, ror r3 */
/* @0x132040 .word 0xffffd100 */
/* @0x132044 eoreq sp, r0, r12, ror #6 */
/* @0x132048 .word 0xffffd104 */
/* @0x13204c eoreq sp, r0, r4, ror #6 */
/* @0x132050 .word 0xffffd108 */
/* @0x132054 eoreq sp, r0, r12, asr r3 */
/* @0x132058 .word 0xffffd10c */
/* @0x13205c eoreq sp, r0, r4, asr r3 */
/* @0x132060 .word 0xffffd110 */
/* @0x132064 eoreq sp, r0, r0, asr r3 */
/* @0x132068 .word 0xffffd114 */
/* @0x13206c eoreq sp, r0, r12, asr #6 */
/* @0x132070 .word 0xffffd118 */
/* @0x132074 eoreq sp, r0, r8, asr #6 */
/* @0x132078 .word 0xffffd11c */
/* @0x13207c eoreq sp, r0, r0, asr #6 */
/* @0x132080 .word 0xffffd120 */
/* @0x132084 eoreq sp, r0, r12, lsr r3 */
/* @0x132088 .word 0xffffd124 */
/* @0x13208c eoreq sp, r0, r4, lsr r3 */
/* @0x132090 .word 0xffffd128 */
/* @0x132094 eoreq sp, r0, r0, lsr r3 */
/* @0x132098 .word 0xffffd12c */
/* @0x13209c eoreq sp, r0, r12, lsr #6 */
/* @0x1320a0 .word 0xffffd130 */
/* @0x1320a4 eoreq sp, r0, r12, lsr #6 */
/* @0x1320a8 .word 0xffffd134 */
/* @0x1320ac eoreq sp, r0, r4, lsr #6 */
/* @0x1320b0 .word 0xffffd138 */
/* @0x1320b4 eoreq sp, r0, r8, lsl r3 */
/* @0x1320b8 .word 0xffffd13c */
/* @0x1320bc eoreq sp, r0, r0, lsl r3 */
/* @0x1320c0 .word 0xffffd140 */
/* @0x1320c4 eoreq sp, r0, r12, lsl #6 */
/* @0x1320c8 .word 0xffffd144 */
/* @0x1320cc eoreq sp, r0, r0, lsl #6 */
/* @0x1320d0 .word 0xffffd148 */
/* @0x1320d4 .word 0x0020d2f4 */
/* @0x1320d8 .word 0xffffd14c */
/* @0x1320dc .word 0xffffd150 */
/* @0x1320e0 eoreq sp, r0, r4, ror #5 */
/* @0x1320e4 .word 0xffffd154 */
/* @0x1320e8 .word 0x0020d2d8 */
/* @0x1320ec .word 0xffffd158 */
/* @0x1320f0 .word 0x0020d2d8 */
/* @0x1320f4 .word 0xffffd15c */
/* @0x1320f8 .word 0x0020d2d4 */
/* @0x1320fc .word 0xffffd160 */
/* @0x132100 .word 0x0020d2d4 */
/* @0x132104 .word 0xffffd164 */
/* @0x132108 .word 0x0020d2d0 */
/* @0x13210c .word 0xffffd168 */
/* @0x132110 eoreq sp, r0, r4, asr #5 */
/* @0x132114 .word 0xffffd16c */
/* @0x132118 .word 0x0020d2bc */
/* @0x13211c .word 0xffffd170 */
/* @0x132120 .word 0x0020d2b8 */
/* @0x132124 .word 0xffffd174 */
/* @0x132128 .word 0x0020d2dc */
/* @0x13212c .word 0xffffd178 */
/* @0x132130 .word 0x0020d2d0 */
/* @0x132134 .word 0xffffd17c */
/* @0x132138 eoreq sp, r0, r8, asr #5 */
/* @0x13213c .word 0xffffd180 */
/* @0x132140 .word 0x0020d2bc */
/* @0x132144 .word 0xffffd184 */
/* @0x132148 .word 0x0020d2b0 */
/* @0x13214c .word 0xffffd188 */
/* @0x132150 eoreq sp, r0, r0, lsr #5 */
/* @0x132154 .word 0xffffd18c */
/* @0x132158 mlaeq r0, r4, r2, sp */
/* @0x13215c .word 0xffffd190 */
/* @0x132160 mlaeq r0, r0, r2, sp */
/* @0x132164 .word 0xffffd194 */
/* @0x132168 eoreq sp, r0, r4, lsl #5 */
/* @0x13216c .word 0xffffbcd4 */
/* @0x132170 .word 0xffffd198 */
/* @0x132174 eoreq sp, r0, r4, lsr #5 */
/* @0x132178 .word 0xffffd19c */
/* @0x13217c mlaeq r0, r8, r2, sp */
/* @0x132180 mlaeq r0, r4, r2, sp */
/* @0x132184 .word 0xffffd1a0 */
/* @0x132188 eoreq sp, r0, r12, lsl #5 */
/* @0x13218c .word 0xffffd1a4 */
/* @0x132190 eoreq sp, r0, r8, lsl #5 */
/* @0x132194 .word 0xffffd1a8 */
/* @0x132198 eoreq sp, r0, r4, lsl #5 */
/* @0x13219c .word 0xffffd1ac */
/* @0x1321a0 eoreq sp, r0, r4, lsl #5 */
/* @0x1321a4 .word 0xffffd1b0 */
/* @0x1321a8 eoreq sp, r0, r0, lsl #5 */
/* @0x1321ac .word 0xffffd1b4 */
/* @0x1321b0 eoreq sp, r0, r8, ror r2 */
/* @0x1321b4 .word 0xffffd1b8 */
/* @0x1321b8 eoreq sp, r0, r8, ror r2 */
/* @0x1321bc eoreq sp, r0, r8, ror r2 */
/* @0x1321c0 eoreq sp, r0, r8, ror r2 */
/* @0x1321c4 eoreq sp, r0, r0, ror r2 */
/* @0x1321c8 eoreq sp, r0, r4, ror r2 */
/* @0x1321cc eoreq sp, r0, r8, ror r2 */
/* @0x1321d0 eoreq sp, r0, r8, ror r2 */
/* @0x1321d4 .word 0xffffd1bc */
/* @0x1321d8 eoreq sp, r0, r12, ror #4 */
/* @0x1321dc .word 0xffffd1c0 */
/* @0x1321e0 eoreq sp, r0, r12, ror #4 */
/* @0x1321e4 .word 0xffffd1c4 */
/* @0x1321e8 eoreq sp, r0, r4, lsr #5 */
/* @0x1321ec .word 0xffffd1c8 */
/* @0x1321f0 mlaeq r0, r12, r2, sp */
/* @0x1321f4 .word 0xffffd1cc */
/* @0x1321f8 mlaeq r0, r8, r2, sp */
/* @0x1321fc .word 0xffffd1d0 */
/* @0x132200 mlaeq r0, r0, r2, sp */
/* @0x132204 .word 0xffffd1d4 */
/* @0x132208 eoreq sp, r0, r4, lsl #5 */
/* @0x13220c .word 0xffffd1d8 */
/* @0x132210 eoreq sp, r0, r12, ror r2 */
/* @0x132214 .word 0xffffd1dc */
/* @0x132218 eoreq sp, r0, r12, ror r2 */
/* @0x13221c .word 0xffffd1e0 */
/* @0x132220 eoreq sp, r0, r4, ror r2 */
/* @0x132224 .word 0xffffd1e4 */
/* @0x132228 eoreq sp, r0, r12, ror #4 */
/* @0x13222c .word 0xffffd1e8 */
/* @0x132230 eoreq sp, r0, r12, asr r2 */
/* @0x132234 eoreq sp, r0, r4, asr r2 */
/* @0x132238 .word 0xffffd1ec */
/* @0x13223c eoreq sp, r0, r8, asr #4 */
/* @0x132240 .word 0xffffd1f0 */
/* @0x132244 eoreq sp, r0, r12, lsr r2 */
/* @0x132248 .word 0xffffd1f4 */
/* @0x13224c eoreq sp, r0, r4, lsr r2 */
/* @0x132250 .word 0xffffd1f8 */
/* @0x132254 eoreq sp, r0, r8, lsr #4 */
/* @0x132258 .word 0xffffd1fc */
/* @0x13225c eoreq sp, r0, r12, lsl r2 */
/* @0x132260 .word 0xffffd200 */
/* @0x132264 eoreq sp, r0, r12, lsl #4 */
/* @0x132268 .word 0xffffd204 */
/* @0x13226c .word 0x0020d1fc */
/* @0x132270 .word 0x0020d1f0 */
/* @0x132274 .word 0xffffd208 */
/* @0x132278 eoreq sp, r0, r4, ror #3 */
/* @0x13227c .word 0xffffd20c */
/* @0x132280 .word 0x0020d1d4 */
/* @0x132284 eoreq sp, r0, r8, asr #3 */
/* @0x132288 .word 0xffffd210 */
/* @0x13228c .word 0x0020d1bc */
/* @0x132290 .word 0xffffd214 */
/* @0x132294 .word 0x0020d1b4 */
/* @0x132298 .word 0xffffd218 */
/* @0x13229c eoreq sp, r0, r8, lsr #3 */
/* @0x1322a0 .word 0xffffd21c */
/* @0x1322a4 mlaeq r0, r12, r1, sp */
/* @0x1322a8 .word 0xffffd220 */
/* @0x1322ac mlaeq r0, r0, r1, sp */
/* @0x1322b0 .word 0xffffd224 */
/* @0x1322b4 eoreq sp, r0, r4, lsl #3 */
/* @0x1322b8 .word 0xffffd228 */
/* @0x1322bc eoreq sp, r0, r8, ror r1 */
/* @0x1322c0 .word 0xffffd22c */
/* @0x1322c4 eoreq sp, r0, r0, ror r1 */
/* @0x1322c8 .word 0xffffd230 */
/* @0x1322cc eoreq sp, r0, r12, ror #2 */
/* @0x1322d0 .word 0xffffd234 */
/* @0x1322d4 eoreq sp, r0, r12, asr r1 */
/* @0x1322d8 .word 0xffffd238 */
/* @0x1322dc eoreq sp, r0, r0, asr r1 */
/* @0x1322e0 .word 0xffffd23c */
/* @0x1322e4 eoreq sp, r0, r8, asr #2 */
/* @0x1322e8 .word 0xffffd240 */
/* @0x1322ec eoreq sp, r0, r0, asr #2 */
/* @0x1322f0 .word 0xffffd244 */
/* @0x1322f4 eoreq sp, r0, r12, lsr r1 */
/* @0x1322f8 .word 0xffffd248 */
/* @0x1322fc eoreq sp, r0, r12, lsr #2 */
/* @0x132300 .word 0xffffd24c */
/* @0x132304 eoreq sp, r0, r0, lsr r1 */
/* @0x132308 .word 0xffffd250 */
/* @0x13230c eoreq sp, r0, r0, lsr r1 */
/* @0x132310 .word 0xffffd254 */
/* @0x132314 eoreq sp, r0, r0, lsr #2 */
/* @0x132318 eoreq sp, r0, r8, lsl r1 */
/* @0x13231c .word 0xffffd258 */
/* @0x132320 eoreq sp, r0, r12, lsl #2 */
/* @0x132324 .word 0xffffd25c */
/* @0x132328 eoreq r0, r0, r4, lsr #12 */
/* @0x13232c .word 0xffffd260 */
/* @0x132330 eoreq sp, r0, r0, ror #1 */
/* @0x132334 .word 0xffffd264 */
/* @0x132338 .word 0x0020d0d0 */
/* @0x13233c eoreq sp, r0, r4, asr #1 */
/* @0x132340 .word 0xffffd268 */
/* @0x132344 strhteq sp, [r0], -r8 */
/* @0x132348 .word 0xffffd26c */
/* @0x13234c eoreq sp, r0, r12, lsr #1 */
/* @0x132350 .word 0xffffd270 */
/* @0x132354 eoreq sp, r0, r0, lsr #1 */
/* @0x132358 .word 0xffffd274 */
/* @0x13235c mlaeq r0, r4, r0, sp */
/* @0x132360 .word 0xffffd278 */
/* @0x132364 eoreq sp, r0, r8, lsl #1 */
/* @0x132368 .word 0xffffd27c */
/* @0x13236c eoreq sp, r0, r0, lsl #1 */
/* @0x132370 .word 0xffffd280 */
/* @0x132374 eoreq sp, r0, r4, ror r0 */
/* @0x132378 .word 0xffffd284 */
/* @0x13237c eoreq sp, r0, r12, rrx */
/* @0x132380 .word 0xffffd288 */
/* @0x132384 eoreq sp, r0, r4, rrx */
/* @0x132388 .word 0xffffd28c */
/* @0x13238c eoreq sp, r0, r0, rrx */
/* @0x132390 .word 0xffffd290 */
/* @0x132394 eoreq sp, r0, r0, asr r0 */
/* @0x132398 .word 0xffffd294 */
/* @0x13239c eoreq sp, r0, r0, asr #32 */
/* @0x1323a0 .word 0xffffd298 */
/* @0x1323a4 eoreq sp, r0, r4, lsr r0 */
/* @0x1323a8 .word 0xffffd29c */
/* @0x1323ac eoreq sp, r0, r8, lsr #32 */
/* @0x1323b0 .word 0xffffd2a0 */
/* @0x1323b4 eoreq sp, r0, r12, lsl r0 */
/* @0x1323b8 .word 0xffffd2a4 */
/* @0x1323bc eoreq sp, r0, r4, lsl r0 */
/* @0x1323c0 .word 0xffffd2a8 */
/* @0x1323c4 eoreq sp, r0, r4 */
/* @0x1323c8 .word 0xffffd2ac */
/* @0x1323cc .word 0x0020cff8 */
/* @0x1323d0 .word 0xffffd2b0 */
/* @0x1323d4 eoreq r12, r0, r8, ror #31 */
/* @0x1323d8 .word 0xffffd2b4 */
/* @0x1323dc .word 0x0020cfd8 */
/* @0x1323e0 .word 0xffffd2b8 */
/* @0x1323e4 eoreq r12, r0, r8, asr #31 */
/* @0x1323e8 .word 0xffffd2bc */
/* @0x1323ec .word 0x0020cfbc */
/* @0x1323f0 .word 0xffffd2c0 */
/* @0x1323f4 .word 0x0020cfb4 */
/* @0x1323f8 .word 0xffffd2c4 */
/* @0x1323fc eoreq r12, r0, r12, lsr #31 */
/* @0x132400 .word 0xffffd2c8 */
/* @0x132404 eoreq r12, r0, r4, lsr #31 */
/* @0x132408 .word 0xffffd2cc */
/* @0x13240c mlaeq r0, r12, pc, r12 */
/* @0x132410 .word 0xffffd2d0 */
/* @0x132414 mlaeq r0, r0, pc, r12 */
/* @0x132418 .word 0xffffd2d4 */
/* @0x13241c eoreq r12, r0, r0, lsl #31 */
/* @0x132420 .word 0xffffd2d8 */
/* @0x132424 eoreq r12, r0, r0, ror pc */
/* @0x132428 .word 0xffffd2dc */
/* @0x13242c eoreq r12, r0, r0, ror #30 */
/* @0x132430 .word 0xffffd2e0 */
/* @0x132434 eoreq r12, r0, r4, asr pc */
/* @0x132438 .word 0xffffd2e4 */
/* @0x13243c eoreq r12, r0, r0, asr #30 */
/* @0x132440 .word 0xffffd2e8 */
/* @0x132444 eoreq r12, r0, r4, lsr pc */
/* @0x132448 eoreq r12, r0, r12, lsr #30 */
/* @0x13244c .word 0xffffd2ec */
/* @0x132450 eoreq r12, r0, r4, lsr #30 */
/* @0x132454 .word 0xffffd2f0 */
/* @0x132458 eoreq r12, r0, r8, ror #16 */
/* @0x13245c .word 0xffffd2f4 */
/* @0x132460 eoreq r12, r0, r12, asr r8 */
/* @0x132464 .word 0xffffd2f8 */
/* @0x132468 eoreq r12, r0, r8, asr r8 */
/* @0x13246c .word 0xffffd2fc */
/* @0x132470 eoreq r12, r0, r12, asr #16 */
/* @0x132474 .word 0xffffd300 */
/* @0x132478 eoreq r12, r0, r4, asr #16 */
/* @0x13247c .word 0xffffd304 */
/* @0x132480 eoreq r12, r0, r4, asr #16 */
/* @0x132484 .word 0xffffd308 */
/* @0x132488 eoreq r12, r0, r8, lsr r8 */
/* @0x13248c .word 0xffffd30c */
/* @0x132490 eoreq r12, r0, r12, lsr #16 */
/* @0x132494 .word 0xffffd310 */
/* @0x132498 eoreq r12, r0, r12, lsl r8 */
/* @0x13249c eoreq r12, r0, r4, lsl r8 */
/* @0x1324a0 .word 0xffffd314 */
/* @0x1324a4 eoreq r12, r0, r8, lsl #16 */
/* @0x1324a8 .word 0xffffd318 */
/* @0x1324ac eoreq r12, r0, r0, lsl #16 */
/* @0x1324b0 .word 0xffffd31c */
/* @0x1324b4 .word 0x0020c7f8 */
/* @0x1324b8 .word 0xffffd320 */
/* @0x1324bc eoreq r12, r0, r12, lsl #16 */
/* @0x1324c0 .word 0xffffd324 */
/* @0x1324c4 eoreq r12, r0, r8, lsl #16 */
/* @0x1324c8 .word 0xffffd328 */
/* @0x1324cc .word 0x0020c7fc */
/* @0x1324d0 .word 0xffffd32c */
/* @0x1324d4 .word 0x0020c7f4 */
/* @0x1324d8 .word 0xffffd330 */
/* @0x1324dc eoreq r12, r0, r12, ror #15 */
/* @0x1324e0 .word 0xffffd334 */
/* @0x1324e4 eoreq r12, r0, r4, ror #15 */
/* @0x1324e8 .word 0xffffd338 */
/* @0x1324ec .word 0x0020c7dc */
/* @0x1324f0 .word 0xffffd33c */
/* @0x1324f4 .word 0x0020c7d4 */
/* @0x1324f8 .word 0xffffd340 */
/* @0x1324fc eoreq r12, r0, r12, asr #15 */
/* @0x132500 .word 0xffffd344 */
/* @0x132504 eoreq r12, r0, r8, asr #15 */
/* @0x132508 .word 0xffffd348 */
/* @0x13250c .word 0x0020c7bc */
/* @0x132510 .word 0xffffd34c */
/* @0x132514 .word 0x0020c7b4 */
/* @0x132518 .word 0xffffd350 */
/* @0x13251c .word 0x0020c7b0 */
/* @0x132520 .word 0xffffd354 */
/* @0x132524 eoreq r12, r0, r0, lsr #15 */
/* @0x132528 .word 0xffffd358 */
/* @0x13252c mlaeq r0, r4, r7, r12 */
/* @0x132530 .word 0xffffd35c */
/* @0x132534 eoreq r12, r0, r12, lsl #15 */
/* @0x132538 .word 0xffffd360 */
/* @0x13253c eoreq r12, r0, r0, lsl #15 */
/* @0x132540 .word 0xffffd364 */
/* @0x132544 eoreq r12, r0, r0, ror r7 */
/* @0x132548 eoreq r12, r0, r4, ror #14 */
/* @0x13254c .word 0xffffd368 */
/* @0x132550 eoreq r12, r0, r8, asr r7 */
/* @0x132554 .word 0xffffd36c */
/* @0x132558 eoreq r12, r0, r12, asr #14 */
/* @0x13255c .word 0xffffd370 */
/* @0x132560 eoreq r12, r0, r0, asr #14 */
/* @0x132564 .word 0xffffd374 */
/* @0x132568 eoreq r12, r0, r8, lsr r7 */
/* @0x13256c .word 0xffffd378 */
/* @0x132570 eoreq r12, r0, r0, lsr r7 */
/* @0x132574 .word 0xffffd37c */
/* @0x132578 eoreq r12, r0, r0, lsr #14 */
/* @0x13257c eoreq r12, r0, r4, lsr #14 */
/* @0x132580 .word 0xffffd380 */
/* @0x132584 eoreq r12, r0, r4, lsr #14 */
/* @0x132588 .word 0xffffd384 */
/* @0x13258c eoreq r12, r0, r0, lsl r7 */
/* @0x132590 .word 0xffffd388 */
/* @0x132594 eoreq r12, r0, r8, lsl #14 */
/* @0x132598 .word 0xffffd38c */
/* @0x13259c eoreq r12, r0, r0, lsl r7 */
/* @0x1325a0 .word 0xffffd390 */
/* @0x1325a4 eoreq r12, r0, r12, lsl #14 */
/* @0x1325a8 .word 0xffffd394 */
/* @0x1325ac .word 0x0020c6fc */
/* @0x1325b0 .word 0xffffd398 */
/* @0x1325b4 .word 0x0020c6f0 */
/* @0x1325b8 .word 0xffffd39c */
/* @0x1325bc eoreq r12, r0, r0, ror #13 */
/* @0x1325c0 .word 0xffffd3a0 */
/* @0x1325c4 .word 0x0020c6d8 */
/* @0x1325c8 .word 0xffffd3a4 */
/* @0x1325cc .word 0x0020c6d0 */
/* @0x1325d0 .word 0xffffd3a8 */
/* @0x1325d4 eoreq r12, r0, r4, asr #13 */
/* @0x1325d8 .word 0xffffd3ac */
/* @0x1325dc .word 0x0020c6bc */
/* @0x1325e0 .word 0xffffd3b0 */
/* @0x1325e4 eoreq r12, r0, r4, lsr #13 */
/* @0x1325e8 .word 0xffffd3b4 */
/* @0x1325ec mlaeq r0, r8, r6, r12 */
/* @0x1325f0 .word 0xffffd3b8 */
/* @0x1325f4 eoreq r12, r0, r8, lsl #13 */
/* @0x1325f8 .word 0xffffd3bc */
/* @0x1325fc eoreq r12, r0, r12, ror r6 */
/* @0x132600 eoreq r11, r0, r0, lsr #18 */
/* @0x132604 .word 0xffffd154 */
/* @0x132608 eoreq r11, r0, r0, lsl r9 */
/* @0x13260c .word 0xffffd158 */
/* @0x132610 eoreq r11, r0, r0, lsl r9 */
/* @0x132614 .word 0xffffd15c */
/* @0x132618 eoreq r11, r0, r12, lsl #18 */
/* @0x13261c .word 0xffffd160 */
/* @0x132620 eoreq r11, r0, r12, lsl #18 */
/* @0x132624 .word 0xffffd164 */
/* @0x132628 eoreq r11, r0, r8, lsl #18 */
/* @0x13262c .word 0xffffd3c0 */
/* @0x132630 eoreq r11, r0, r12, lsr r9 */
/* @0x132634 .word 0xffffd3c4 */
/* @0x132638 eoreq r11, r0, r8, lsr r9 */
/* @0x13263c eoreq r11, r0, r4, ror #21 */
/* @0x132640 eoreq r11, r0, r8, ror #21 */
/* @0x132644 .word 0xffffd3c8 */
/* @0x132648 eoreq r11, r0, r4, ror #21 */
/* @0x13264c .word 0xffffd3cc */
/* @0x132650 .word 0x0020badc */
/* @0x132654 .word 0xffffd3d0 */
/* @0x132658 eoreq r11, r0, r0, ror #21 */
/* @0x13265c .word 0xffffd3d4 */
/* @0x132660 eoreq r11, r0, r4, ror #21 */
/* @0x132664 .word 0xffffd3d8 */
/* @0x132668 eoreq r11, r0, r4, ror #21 */
/* @0x13266c .word 0xffffd3dc */
/* @0x132670 eoreq r11, r0, r4, lsl r11 */
/* @0x132674 .word 0xffffd3e0 */
/* @0x132678 eoreq r11, r0, r4, lsl r11 */
/* @0x13267c .word 0xffffd3e4 */
/* @0x132680 eoreq r12, r0, r8, lsr #7 */
/* @0x132684 .word 0xffffd3e8 */
/* @0x132688 eoreq r12, r0, r8, lsr #2 */
/* @0x13268c .word 0xffffd3ec */
/* @0x132690 eoreq r12, r0, r4, lsr #2 */
/* @0x132694 .word 0xffffd3f0 */
/* @0x132698 eoreq r11, r0, r8, ror #16 */
/* @0x13269c .word 0xffffd3f4 */
/* @0x1326a0 eoreq r11, r0, r0, ror #16 */
/* @0x1326a4 .word 0xffffd3f8 */
/* @0x1326a8 eoreq r11, r0, r0, ror #16 */
/* @0x1326ac ldr r1, [pc, #-0x260] */
/* @0x1326b0 ldr r0, [pc, #-0x260] */
/* @0x1326b4 mov r2, #1 */
/* @0x1326b8 mov r3, r2 */
/* @0x1326bc add r0, pc, r0 */
/* @0x1326c0 ldr r1, [r4, r1] */
/* @0x1326c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1326c8 ldr r1, [pc, #-0x274] */
/* @0x1326cc ldr r0, [pc, #-0x274] */
/* @0x1326d0 mov r2, #2 */
/* @0x1326d4 mov r3, #1 */
/* @0x1326d8 add r0, pc, r0 */
/* @0x1326dc ldr r1, [r4, r1] */
/* @0x1326e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1326e4 ldr r1, [pc, #-0x288] */
/* @0x1326e8 ldr r0, [pc, #-0x288] */
/* @0x1326ec mov r2, #1 */
/* @0x1326f0 mov r3, r2 */
/* @0x1326f4 add r0, pc, r0 */
/* @0x1326f8 ldr r1, [r4, r1] */
/* @0x1326fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132700 ldr r1, [pc, #-0x29c] */
/* @0x132704 ldr r0, [pc, #-0x29c] */
/* @0x132708 mov r2, #3 */
/* @0x13270c mov r3, #1 */
/* @0x132710 add r0, pc, r0 */
/* @0x132714 ldr r1, [r4, r1] */
/* @0x132718 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13271c ldr r1, [pc, #-0x2b0] */
/* @0x132720 ldr r0, [pc, #-0x2b0] */
/* @0x132724 mov r2, #3 */
/* @0x132728 mov r3, #1 */
/* @0x13272c add r0, pc, r0 */
/* @0x132730 ldr r1, [r4, r1] */
/* @0x132734 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132738 ldr r1, [pc, #-0x2c4] */
/* @0x13273c ldr r0, [pc, #-0x2c4] */
/* @0x132740 mov r2, #1 */
/* @0x132744 mov r3, r2 */
/* @0x132748 add r0, pc, r0 */
/* @0x13274c ldr r1, [r4, r1] */
/* @0x132750 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132754 ldr r1, [pc, #-0x2d8] */
/* @0x132758 ldr r0, [pc, #-0x2d8] */
/* @0x13275c mov r2, #1 */
/* @0x132760 mov r3, r2 */
/* @0x132764 add r0, pc, r0 */
/* @0x132768 ldr r1, [r4, r1] */
/* @0x13276c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132770 ldr r1, [pc, #-0x2ec] */
/* @0x132774 ldr r0, [pc, #-0x2ec] */
/* @0x132778 mov r2, #1 */
/* @0x13277c mov r3, #0 */
/* @0x132780 ldr r6, [r4, r1] */
/* @0x132784 add r0, pc, r0 */
/* @0x132788 mov r1, r6 */
/* @0x13278c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132790 ldr r1, [pc, #-0x304] */
/* @0x132794 ldr r0, [pc, #-0x304] */
/* @0x132798 mov r2, #1 */
/* @0x13279c mov r3, #0 */
/* @0x1327a0 add r0, pc, r0 */
/* @0x1327a4 ldr r1, [r4, r1] */
/* @0x1327a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1327ac ldr r0, [pc, #-0x318] */
/* @0x1327b0 mov r1, r6 */
/* @0x1327b4 mov r2, #1 */
/* @0x1327b8 add r0, pc, r0 */
/* @0x1327bc mov r3, #0 */
/* @0x1327c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1327c4 ldr r1, [pc, #-0x32c] */
/* @0x1327c8 ldr r0, [pc, #-0x32c] */
/* @0x1327cc mov r2, #1 */
/* @0x1327d0 mov r3, #0 */
/* @0x1327d4 add r0, pc, r0 */
/* @0x1327d8 ldr r1, [r4, r1] */
/* @0x1327dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1327e0 ldr r1, [pc, #-0x340] */
/* @0x1327e4 ldr r0, [pc, #-0x340] */
/* @0x1327e8 mov r2, #1 */
/* @0x1327ec mov r3, #0 */
/* @0x1327f0 add r0, pc, r0 */
/* @0x1327f4 ldr r1, [r4, r1] */
/* @0x1327f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1327fc ldr r1, [pc, #-0x354] */
/* @0x132800 ldr r0, [pc, #-0x354] */
/* @0x132804 mov r3, #0 */
/* @0x132808 mov r2, #1 */
/* @0x13280c add r0, pc, r0 */
/* @0x132810 ldr r1, [r4, r1] */
/* @0x132814 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132818 ldrb r3, [r5] */
/* @0x13281c cmp r3, #0 */
/* @0x132820 beq 0x132ee0 <_Z21InitResourceFunctionsv+0x1ee4> */
/* @0x132824 ldr r1, [pc, #-0x374] */
/* @0x132828 mov r2, #1 */
/* @0x13282c ldr r0, [pc, #-0x378] */
/* @0x132830 mov r3, #0 */
/* @0x132834 add r0, pc, r0 */
/* @0x132838 ldr r1, [r4, r1] */
/* @0x13283c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132840 ldr r1, [pc, #-0x388] */
/* @0x132844 ldr r0, [pc, #-0x388] */
/* @0x132848 mov r2, #1 */
/* @0x13284c mov r3, #0 */
/* @0x132850 add r0, pc, r0 */
/* @0x132854 ldr r1, [r4, r1] */
/* @0x132858 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13285c ldr r1, [pc, #-0x39c] */
/* @0x132860 ldr r0, [pc, #-0x39c] */
/* @0x132864 mov r2, #1 */
/* @0x132868 mov r3, #0 */
/* @0x13286c add r0, pc, r0 */
/* @0x132870 ldr r1, [r4, r1] */
/* @0x132874 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132878 ldr r1, [pc, #-0x3b0] */
/* @0x13287c ldr r0, [pc, #-0x3b0] */
/* @0x132880 mov r2, #1 */
/* @0x132884 mov r3, #0 */
/* @0x132888 add r0, pc, r0 */
/* @0x13288c ldr r1, [r4, r1] */
/* @0x132890 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132894 ldr r1, [pc, #-0x3c4] */
/* @0x132898 ldr r0, [pc, #-0x3c4] */
/* @0x13289c mov r2, #2 */
/* @0x1328a0 mov r3, #0 */
/* @0x1328a4 add r0, pc, r0 */
/* @0x1328a8 ldr r1, [r4, r1] */
/* @0x1328ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1328b0 ldr r1, [pc, #-0x3d8] */
/* @0x1328b4 ldr r0, [pc, #-0x3d8] */
/* @0x1328b8 mov r2, #2 */
/* @0x1328bc mov r3, #1 */
/* @0x1328c0 add r0, pc, r0 */
/* @0x1328c4 ldr r1, [r4, r1] */
/* @0x1328c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1328cc ldr r1, [pc, #-0x3ec] */
/* @0x1328d0 ldr r0, [pc, #-0x3ec] */
/* @0x1328d4 mov r2, #2 */
/* @0x1328d8 mov r3, #1 */
/* @0x1328dc add r0, pc, r0 */
/* @0x1328e0 ldr r1, [r4, r1] */
/* @0x1328e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1328e8 ldr r1, [pc, #-0x400] */
/* @0x1328ec ldr r0, [pc, #-0x400] */
/* @0x1328f0 mov r2, #2 */
/* @0x1328f4 mov r3, #1 */
/* @0x1328f8 add r0, pc, r0 */
/* @0x1328fc ldr r1, [r4, r1] */
/* @0x132900 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132904 ldr r1, [pc, #-0x414] */
/* @0x132908 ldr r0, [pc, #-0x414] */
/* @0x13290c mov r2, #2 */
/* @0x132910 mov r3, #1 */
/* @0x132914 add r0, pc, r0 */
/* @0x132918 ldr r1, [r4, r1] */
/* @0x13291c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132920 ldr r1, [pc, #-0x428] */
/* @0x132924 ldr r0, [pc, #-0x428] */
/* @0x132928 mov r2, #2 */
/* @0x13292c mov r3, #1 */
/* @0x132930 add r0, pc, r0 */
/* @0x132934 ldr r1, [r4, r1] */
/* @0x132938 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x13293c ldr r1, [pc, #-0x43c] */
/* @0x132940 ldr r0, [pc, #-0x43c] */
/* @0x132944 mov r2, #2 */
/* @0x132948 mov r3, #1 */
/* @0x13294c add r0, pc, r0 */
/* @0x132950 ldr r1, [r4, r1] */
/* @0x132954 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132958 ldr r1, [pc, #-0x450] */
/* @0x13295c ldr r0, [pc, #-0x450] */
/* @0x132960 mov r2, #2 */
/* @0x132964 mov r3, #1 */
/* @0x132968 add r0, pc, r0 */
/* @0x13296c ldr r1, [r4, r1] */
/* @0x132970 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132974 ldr r1, [pc, #-0x464] */
/* @0x132978 ldr r0, [pc, #-0x464] */
/* @0x13297c mov r2, #0 */
/* @0x132980 mov r3, #1 */
/* @0x132984 add r0, pc, r0 */
/* @0x132988 ldr r1, [r4, r1] */
/* @0x13298c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132990 ldr r1, [pc, #-0x478] */
/* @0x132994 ldr r0, [pc, #-0x478] */
/* @0x132998 mov r2, #1 */
/* @0x13299c mov r3, r2 */
/* @0x1329a0 add r0, pc, r0 */
/* @0x1329a4 ldr r1, [r4, r1] */
/* @0x1329a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1329ac ldr r1, [pc, #-0x48c] */
/* @0x1329b0 ldr r0, [pc, #-0x48c] */
/* @0x1329b4 mov r2, #3 */
/* @0x1329b8 mov r3, #1 */
/* @0x1329bc add r0, pc, r0 */
/* @0x1329c0 ldr r1, [r4, r1] */
/* @0x1329c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1329c8 ldr r1, [pc, #-0x4a0] */
/* @0x1329cc ldr r0, [pc, #-0x4a0] */
/* @0x1329d0 mov r2, #4 */
/* @0x1329d4 mov r3, #1 */
/* @0x1329d8 add r0, pc, r0 */
/* @0x1329dc ldr r1, [r4, r1] */
/* @0x1329e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1329e4 ldr r1, [pc, #-0x4b4] */
/* @0x1329e8 ldr r0, [pc, #-0x4b4] */
/* @0x1329ec mov r2, #1 */
/* @0x1329f0 mov r3, #0 */
/* @0x1329f4 ldr r6, [r4, r1] */
/* @0x1329f8 add r0, pc, r0 */
/* @0x1329fc mov r1, r6 */
/* @0x132a00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132a04 ldr r1, [pc, #-0x4cc] */
/* @0x132a08 ldr r0, [pc, #-0x4cc] */
/* @0x132a0c mov r2, #1 */
/* @0x132a10 mov r3, #0 */
/* @0x132a14 add r0, pc, r0 */
/* @0x132a18 ldr r1, [r4, r1] */
/* @0x132a1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132a20 ldr r0, [pc, #-0x4e0] */
/* @0x132a24 mov r1, r6 */
/* @0x132a28 mov r2, #1 */
/* @0x132a2c add r0, pc, r0 */
/* @0x132a30 mov r3, #0 */
/* @0x132a34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132a38 ldr r1, [pc, #-0x4f4] */
/* @0x132a3c ldr r0, [pc, #-0x4f4] */
/* @0x132a40 mov r2, #2 */
/* @0x132a44 mov r3, #1 */
/* @0x132a48 add r0, pc, r0 */
/* @0x132a4c ldr r1, [r4, r1] */
/* @0x132a50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132a54 ldr r1, [pc, #-0x508] */
/* @0x132a58 ldr r0, [pc, #-0x508] */
/* @0x132a5c mov r2, #2 */
/* @0x132a60 mov r3, #1 */
/* @0x132a64 add r0, pc, r0 */
/* @0x132a68 ldr r1, [r4, r1] */
/* @0x132a6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132a70 ldr r1, [pc, #-0x51c] */
/* @0x132a74 ldr r0, [pc, #-0x51c] */
/* @0x132a78 mov r2, #2 */
/* @0x132a7c mov r3, #1 */
/* @0x132a80 add r0, pc, r0 */
/* @0x132a84 ldr r1, [r4, r1] */
/* @0x132a88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132a8c ldr r1, [pc, #-0x530] */
/* @0x132a90 ldr r0, [pc, #-0x530] */
/* @0x132a94 mov r2, #2 */
/* @0x132a98 mov r3, #1 */
/* @0x132a9c add r0, pc, r0 */
/* @0x132aa0 ldr r1, [r4, r1] */
/* @0x132aa4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132aa8 ldr r1, [pc, #-0x544] */
/* @0x132aac ldr r0, [pc, #-0x544] */
/* @0x132ab0 mov r2, #2 */
/* @0x132ab4 mov r3, #1 */
/* @0x132ab8 add r0, pc, r0 */
/* @0x132abc ldr r1, [r4, r1] */
/* @0x132ac0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132ac4 ldr r1, [pc, #-0x558] */
/* @0x132ac8 ldr r0, [pc, #-0x558] */
/* @0x132acc mov r2, #3 */
/* @0x132ad0 mov r3, #1 */
/* @0x132ad4 ldr r6, [r4, r1] */
/* @0x132ad8 add r0, pc, r0 */
/* @0x132adc mov r1, r6 */
/* @0x132ae0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132ae4 ldr r0, [pc, #-0x570] */
/* @0x132ae8 mov r1, r6 */
/* @0x132aec mov r2, #3 */
/* @0x132af0 add r0, pc, r0 */
/* @0x132af4 mov r3, #1 */
/* @0x132af8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132afc ldr r1, [pc, #-0x584] */
/* @0x132b00 ldr r0, [pc, #-0x584] */
/* @0x132b04 mov r3, #1 */
/* @0x132b08 mov r2, #12 */
/* @0x132b0c add r0, pc, r0 */
/* @0x132b10 ldr r1, [r4, r1] */
/* @0x132b14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132b18 ldrb r3, [r5] */
/* @0x132b1c cmp r3, #0 */
/* @0x132b20 beq 0x132eb4 <_Z21InitResourceFunctionsv+0x1eb8> */
/* @0x132b24 ldr r1, [pc, #-0x5a4] */
/* @0x132b28 mov r2, #7 */
/* @0x132b2c ldr r0, [pc, #-0x5a8] */
/* @0x132b30 mov r3, #1 */
/* @0x132b34 add r0, pc, r0 */
/* @0x132b38 ldr r1, [r4, r1] */
/* @0x132b3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132b40 ldr r1, [pc, #-0x5b8] */
/* @0x132b44 ldr r0, [pc, #-0x5b8] */
/* @0x132b48 mov r2, #2 */
/* @0x132b4c mov r3, #1 */
/* @0x132b50 add r0, pc, r0 */
/* @0x132b54 ldr r1, [r4, r1] */
/* @0x132b58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132b5c ldr r1, [pc, #-0x5cc] */
/* @0x132b60 mov r2, #2 */
/* @0x132b64 ldr r0, [pc, #-0x5d0] */
/* @0x132b68 mov r3, #1 */
/* @0x132b6c add r0, pc, r0 */
/* @0x132b70 ldr r1, [r4, r1] */
/* @0x132b74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132b78 ldr r1, [pc, #-0x5e0] */
/* @0x132b7c ldr r0, [pc, #-0x5e0] */
/* @0x132b80 mov r2, #0 */
/* @0x132b84 mov r3, #1 */
/* @0x132b88 add r0, pc, r0 */
/* @0x132b8c ldr r1, [r4, r1] */
/* @0x132b90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132b94 ldr r1, [pc, #-0x5f4] */
/* @0x132b98 ldr r0, [pc, #-0x5f4] */
/* @0x132b9c mov r2, #1 */
/* @0x132ba0 mov r3, r2 */
/* @0x132ba4 add r0, pc, r0 */
/* @0x132ba8 ldr r1, [r4, r1] */
/* @0x132bac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132bb0 ldr r1, [pc, #-0x608] */
/* @0x132bb4 ldr r0, [pc, #-0x608] */
/* @0x132bb8 mov r2, #2 */
/* @0x132bbc mov r3, #1 */
/* @0x132bc0 add r0, pc, r0 */
/* @0x132bc4 ldr r1, [r4, r1] */
/* @0x132bc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132bcc ldr r1, [pc, #-0x61c] */
/* @0x132bd0 ldr r0, [pc, #-0x61c] */
/* @0x132bd4 mov r2, #4 */
/* @0x132bd8 mov r3, #1 */
/* @0x132bdc add r0, pc, r0 */
/* @0x132be0 ldr r1, [r4, r1] */
/* @0x132be4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132be8 ldr r1, [pc, #-0x630] */
/* @0x132bec ldr r0, [pc, #-0x630] */
/* @0x132bf0 mov r2, #1 */
/* @0x132bf4 mov r3, r2 */
/* @0x132bf8 add r0, pc, r0 */
/* @0x132bfc ldr r1, [r4, r1] */
/* @0x132c00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132c04 ldr r1, [pc, #-0x644] */
/* @0x132c08 ldr r0, [pc, #-0x644] */
/* @0x132c0c mov r2, #9 */
/* @0x132c10 mov r3, #1 */
/* @0x132c14 add r0, pc, r0 */
/* @0x132c18 ldr r1, [r4, r1] */
/* @0x132c1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132c20 ldr r1, [pc, #-0x658] */
/* @0x132c24 ldr r0, [pc, #-0x658] */
/* @0x132c28 mov r2, #12 */
/* @0x132c2c mov r3, #1 */
/* @0x132c30 add r0, pc, r0 */
/* @0x132c34 ldr r1, [r4, r1] */
/* @0x132c38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132c3c ldr r1, [pc, #-0x66c] */
/* @0x132c40 ldr r0, [pc, #-0x66c] */
/* @0x132c44 mov r2, #1 */
/* @0x132c48 mov r3, r2 */
/* @0x132c4c add r0, pc, r0 */
/* @0x132c50 ldr r1, [r4, r1] */
/* @0x132c54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132c58 ldrb r3, [r5] */
/* @0x132c5c cmp r3, #0 */
/* @0x132c60 beq 0x132c9c <_Z21InitResourceFunctionsv+0x1ca0> */
/* @0x132c64 ldr r1, [pc, #-0x68c] */
/* @0x132c68 mov r2, #2 */
/* @0x132c6c ldr r0, [pc, #-0x690] */
/* @0x132c70 mov r3, #1 */
/* @0x132c74 add r0, pc, r0 */
/* @0x132c78 ldr r1, [r4, r1] */
/* @0x132c7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132c80 ldr r1, [pc, #-0x6a0] */
/* @0x132c84 ldr r0, [pc, #-0x6a0] */
/* @0x132c88 mov r2, #3 */
/* @0x132c8c mov r3, #1 */
/* @0x132c90 add r0, pc, r0 */
/* @0x132c94 ldr r1, [r4, r1] */
/* @0x132c98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132c9c ldr r1, [pc, #-0x6b4] */
/* @0x132ca0 mov r2, #1 */
/* @0x132ca4 ldr r0, [pc, #-0x6b8] */
/* @0x132ca8 mov r3, r2 */
/* @0x132cac ldr r1, [r4, r1] */
/* @0x132cb0 add r0, pc, r0 */
/* @0x132cb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132cb8 ldr r1, [pc, #-0x6c8] */
/* @0x132cbc ldr r0, [pc, #-0x6c8] */
/* @0x132cc0 mov r2, #1 */
/* @0x132cc4 mov r3, r2 */
/* @0x132cc8 ldr r1, [r4, r1] */
/* @0x132ccc add r0, pc, r0 */
/* @0x132cd0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x132cd4 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132cd8 ldr r0, [pc, #-0x6e0] */
/* @0x132cdc mov r2, #8 */
/* @0x132ce0 ldr r1, [r4, r1] */
/* @0x132ce4 mov r3, #1 */
/* @0x132ce8 add r0, pc, r0 */
/* @0x132cec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132cf0 ldr r1, [pc, #-0x6f4] */
/* @0x132cf4 ldr r0, [pc, #-0x6f4] */
/* @0x132cf8 mov r2, #10 */
/* @0x132cfc mov r3, #1 */
/* @0x132d00 ldr r1, [r4, r1] */
/* @0x132d04 add r0, pc, r0 */
/* @0x132d08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132d0c ldr r1, [pc, #-0x708] */
/* @0x132d10 ldr r0, [pc, #-0x708] */
/* @0x132d14 mov r2, #5 */
/* @0x132d18 mov r3, #1 */
/* @0x132d1c ldr r1, [r4, r1] */
/* @0x132d20 add r0, pc, r0 */
/* @0x132d24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132d28 ldr r1, [pc, #-0x71c] */
/* @0x132d2c ldr r0, [pc, #-0x71c] */
/* @0x132d30 mov r2, #11 */
/* @0x132d34 mov r3, #1 */
/* @0x132d38 ldr r1, [r4, r1] */
/* @0x132d3c add r0, pc, r0 */
/* @0x132d40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132d44 ldr r1, [pc, #-0x730] */
/* @0x132d48 ldr r0, [pc, #-0x730] */
/* @0x132d4c mov r2, #6 */
/* @0x132d50 mov r3, #1 */
/* @0x132d54 ldr r1, [r4, r1] */
/* @0x132d58 add r0, pc, r0 */
/* @0x132d5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132d60 ldr r1, [pc, #-0x744] */
/* @0x132d64 ldr r0, [pc, #-0x744] */
/* @0x132d68 mov r2, #9 */
/* @0x132d6c mov r3, #1 */
/* @0x132d70 ldr r1, [r4, r1] */
/* @0x132d74 add r0, pc, r0 */
/* @0x132d78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132d7c ldr r1, [pc, #-0x758] */
/* @0x132d80 ldr r0, [pc, #-0x758] */
/* @0x132d84 mov r2, #6 */
/* @0x132d88 mov r3, #1 */
/* @0x132d8c ldr r1, [r4, r1] */
/* @0x132d90 add r0, pc, r0 */
/* @0x132d94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132d98 ldr r1, [pc, #-0x76c] */
/* @0x132d9c ldr r0, [pc, #-0x76c] */
/* @0x132da0 mov r2, #7 */
/* @0x132da4 mov r3, #1 */
/* @0x132da8 add r0, pc, r0 */
/* @0x132dac ldr r1, [r4, r1] */
/* @0x132db0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132db4 b 0x13140c <_Z21InitResourceFunctionsv+0x410> */
/* @0x132db8 ldr r6, [r4, r1] */
/* @0x132dbc mov r2, #4 */
/* @0x132dc0 ldr r0, [pc, #-0x78c] */
/* @0x132dc4 mov r3, #1 */
/* @0x132dc8 mov r1, r6 */
/* @0x132dcc add r0, pc, r0 */
/* @0x132dd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132dd4 ldr r0, [pc, #-0x79c] */
/* @0x132dd8 mov r1, r6 */
/* @0x132ddc mov r2, #4 */
/* @0x132de0 add r0, pc, r0 */
/* @0x132de4 mov r3, #1 */
/* @0x132de8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132dec ldr r1, [pc, #-0x7b0] */
/* @0x132df0 ldr r0, [pc, #-0x7b0] */
/* @0x132df4 mov r2, #5 */
/* @0x132df8 mov r3, #1 */
/* @0x132dfc ldr r1, [r4, r1] */
/* @0x132e00 add r0, pc, r0 */
/* @0x132e04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132e08 ldr r1, [pc, #-0x7c4] */
/* @0x132e0c ldr r0, [pc, #-0x7c4] */
/* @0x132e10 mov r2, #7 */
/* @0x132e14 mov r3, #1 */
/* @0x132e18 ldr r1, [r4, r1] */
/* @0x132e1c add r0, pc, r0 */
/* @0x132e20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132e24 ldr r1, [pc, #-0x7d8] */
/* @0x132e28 ldr r0, [pc, #-0x7d8] */
/* @0x132e2c mov r2, #8 */
/* @0x132e30 mov r3, #1 */
/* @0x132e34 ldr r1, [r4, r1] */
/* @0x132e38 add r0, pc, r0 */
/* @0x132e3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132e40 ldr r1, [pc, #-0x7ec] */
/* @0x132e44 ldr r0, [pc, #-0x7ec] */
/* @0x132e48 mov r2, #6 */
/* @0x132e4c mov r3, #1 */
/* @0x132e50 ldr r1, [r4, r1] */
/* @0x132e54 add r0, pc, r0 */
/* @0x132e58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132e5c ldr r1, [pc, #-0x800] */
/* @0x132e60 ldr r0, [pc, #-0x800] */
/* @0x132e64 mov r2, #4 */
/* @0x132e68 mov r3, #1 */
/* @0x132e6c ldr r1, [r4, r1] */
/* @0x132e70 add r0, pc, r0 */
/* @0x132e74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132e78 ldr r1, [pc, #-0x814] */
/* @0x132e7c ldr r0, [pc, #-0x814] */
/* @0x132e80 mov r2, #2 */
/* @0x132e84 mov r3, #1 */
/* @0x132e88 ldr r1, [r4, r1] */
/* @0x132e8c add r0, pc, r0 */
/* @0x132e90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132e94 ldr r1, [pc, #-0x828] */
/* @0x132e98 ldr r0, [pc, #-0x828] */
/* @0x132e9c mov r2, #3 */
/* @0x132ea0 mov r3, #1 */
/* @0x132ea4 add r0, pc, r0 */
/* @0x132ea8 ldr r1, [r4, r1] */
/* @0x132eac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132eb0 b 0x131720 <_Z21InitResourceFunctionsv+0x724> */
/* @0x132eb4 ldr r1, [pc, #-0x840] */
/* @0x132eb8 mov r3, #1 */
/* @0x132ebc ldr r0, [pc, #-0x844] */
/* @0x132ec0 mov r2, #16 */
/* @0x132ec4 add r0, pc, r0 */
/* @0x132ec8 ldr r1, [r4, r1] */
/* @0x132ecc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132ed0 ldrb r3, [r5] */
/* @0x132ed4 cmp r3, #0 */
/* @0x132ed8 beq 0x132b5c <_Z21InitResourceFunctionsv+0x1b60> */
/* @0x132edc b 0x132b24 <_Z21InitResourceFunctionsv+0x1b28> */
/* @0x132ee0 ldr r1, [pc, #-0x864] */
/* @0x132ee4 mov r2, #1 */
/* @0x132ee8 ldr r0, [pc, #-0x868] */
/* @0x132eec ldr r1, [r4, r1] */
/* @0x132ef0 add r0, pc, r0 */
/* @0x132ef4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132ef8 ldr r1, [pc, #-0x874] */
/* @0x132efc ldr r0, [pc, #-0x874] */
/* @0x132f00 mov r2, #2 */
/* @0x132f04 mov r3, #1 */
/* @0x132f08 add r0, pc, r0 */
/* @0x132f0c ldr r1, [r4, r1] */
/* @0x132f10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132f14 b 0x132824 <_Z21InitResourceFunctionsv+0x1828> */
/* @0x132f18 ldr r1, [pc, #-0x88c] */
/* @0x132f1c mov r2, #3 */
/* @0x132f20 ldr r0, [pc, #-0x890] */
/* @0x132f24 mov r3, #1 */
/* @0x132f28 ldr r1, [r4, r1] */
/* @0x132f2c add r0, pc, r0 */
/* @0x132f30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132f34 ldr r1, [pc, #-0x8a0] */
/* @0x132f38 ldr r0, [pc, #-0x8a0] */
/* @0x132f3c mov r2, #1 */
/* @0x132f40 mov r3, r2 */
/* @0x132f44 ldr r1, [r4, r1] */
/* @0x132f48 add r0, pc, r0 */
/* @0x132f4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132f50 ldr r1, [pc, #-0x8b4] */
/* @0x132f54 ldr r0, [pc, #-0x8b4] */
/* @0x132f58 mov r2, #1 */
/* @0x132f5c mov r3, r2 */
/* @0x132f60 add r0, pc, r0 */
/* @0x132f64 ldr r1, [r4, r1] */
/* @0x132f68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x132f6c b 0x13151c <_Z21InitResourceFunctionsv+0x520> */

/* ── FUNC 0x132f70 · F_ScriptExecute(RValue&, CInstance*, CInstance*, int, RValue*) · size=1720 · insn=430 */
/* @0x132f70 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x132f74 sub sp, sp, #316 */
/* @0x132f78 add r12, sp, #56 */
/* @0x132f7c ldr r10, [pc, #0x68c] */
/* @0x132f80 str r0, [sp, #0xc] */
/* @0x132f84 mov r5, r3 */
/* @0x132f88 str r1, [sp, #0x14] */
/* @0x132f8c mov r0, r12 */
/* @0x132f90 str r2, [sp, #0x18] */
/* @0x132f94 mov r1, #0 */
/* @0x132f98 mov r2, #256 */
/* @0x132f9c str r12, [sp, #0x10] */
/* @0x132fa0 bl 0xb65b0 <memset@plt> */
/* @0x132fa4 ldr r3, [pc, #0x668] */
/* @0x132fa8 add r10, pc, r10 */
/* @0x132fac mov r1, #0 */
/* @0x132fb0 str r1, [sp, #0x28] */
/* @0x132fb4 str r1, [sp, #0x2c] */
/* @0x132fb8 str r1, [sp, #0x30] */
/* @0x132fbc str r1, [sp, #0x34] */
/* @0x132fc0 ldr r3, [r10, r3] */
/* @0x132fc4 ldrb r3, [r3] */
/* @0x132fc8 cmp r3, r1 */
/* @0x132fcc beq 0x132fe4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x132fd0 ldr r12, [sp, #0x160] */
/* @0x132fd4 ldr r3, [r12, #0xc] */
/* @0x132fd8 bic r3, r3, #-16777216 */
/* @0x132fdc cmp r3, #6 */
/* @0x132fe0 beq 0x133320 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x3b0> */
/* @0x132fe4 mov r1, #0 */
/* @0x132fe8 ldr r0, [sp, #0x160] */
/* @0x132fec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x132ff0 bl 0x1e0544 <_Z13Script_Existsi> */
/* @0x132ff4 subs r1, r0, #0 */
/* @0x132ff8 beq 0x1333a0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x430> */
/* @0x132ffc cmp r5, #1 */
/* @0x133000 suble r5, r5, #1 */
/* @0x133004 ble 0x1330d4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x133008 cmp r5, #16 */
/* @0x13300c movge r5, #16 */
/* @0x133010 mov r11, #0 */
/* @0x133014 sub r8, r5, #1 */
/* @0x133018 ldr r5, [sp, #0x160] */
/* @0x13301c add r6, sp, #68 */
/* @0x133020 add r4, sp, #56 */
/* @0x133024 mov r7, r11 */
/* @0x133028 str r10, [sp, #0x1c] */
/* @0x13302c ldr r2, [r4, #0xc] */
/* @0x133030 add r9, r5, #16 */
/* @0x133034 bic r3, r2, #-16777216 */
/* @0x133038 cmp r3, #1 */
/* @0x13303c beq 0x1332f0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x380> */
/* @0x133040 cmp r3, #2 */
/* @0x133044 bne 0x133068 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x133048 sub r2, r2, #1 */
/* @0x13304c bic r2, r2, #-16777216 */
/* @0x133050 bic r2, r2, #3 */
/* @0x133054 cmp r2, #0 */
/* @0x133058 beq 0x133394 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x424> */
/* @0x13305c mov r0, #5 */
/* @0x133060 str r7, [r4, #0x8] */
/* @0x133064 str r0, [r4, #0xc] */
/* @0x133068 str r7, [r6, #-0xc] */
/* @0x13306c ldr r3, [r5, #0x1c] */
/* @0x133070 str r3, [r4, #0xc] */
/* @0x133074 ldr r3, [r5, #0x18] */
/* @0x133078 str r3, [r4, #0x8] */
/* @0x13307c ldr r3, [r5, #0x1c] */
/* @0x133080 bic r3, r3, #-16777216 */
/* @0x133084 cmp r3, #14 */
/* @0x133088 addls pc, pc, r3, lsl #2 */
/* @0x13308c b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x133090 b 0x1331f8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x288> */
/* @0x133094 b 0x133230 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x2c0> */
/* @0x133098 b 0x133204 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x13309c b 0x1331d4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x1330a0 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x1330a4 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x1330a8 b 0x133248 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x2d8> */
/* @0x1330ac b 0x1331d4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x1330b0 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x1330b4 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x1330b8 b 0x1331f8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x288> */
/* @0x1330bc b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x1330c0 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x1330c4 b 0x1331f8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x288> */
/* @0x1330c8 b 0x1331d4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x1330cc ldr r10, [sp, #0x1c] */
/* @0x1330d0 mov r5, r11 */
/* @0x1330d4 ldr r3, [pc, #0x53c] */
/* @0x1330d8 add r2, sp, #56 */
/* @0x1330dc str r5, [sp, #0x20] */
/* @0x1330e0 mov r1, #0 */
/* @0x1330e4 str r2, [sp, #0x24] */
/* @0x1330e8 add r4, sp, #40 */
/* @0x1330ec ldr r6, [r10, r3] */
/* @0x1330f0 ldr r0, [sp, #0x160] */
/* @0x1330f4 ldr r7, [r6] */
/* @0x1330f8 str r5, [r6] */
/* @0x1330fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x133100 mov r3, r5 */
/* @0x133104 add r12, sp, #32 */
/* @0x133108 ldr r1, [sp, #0x14] */
/* @0x13310c ldr r2, [sp, #0x18] */
/* @0x133110 str r4, [sp] */
/* @0x133114 str r12, [sp, #0x4] */
/* @0x133118 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue> */
/* @0x13311c ldr r3, [pc, #0x4f8] */
/* @0x133120 str r7, [r6] */
/* @0x133124 ldr r3, [r10, r3] */
/* @0x133128 ldrb r3, [r3] */
/* @0x13312c cmp r3, #0 */
/* @0x133130 bne 0x1333f0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x480> */
/* @0x133134 ldr r12, [sp, #0xc] */
/* @0x133138 ldr r2, [r12, #0xc] */
/* @0x13313c bic r3, r2, #-16777216 */
/* @0x133140 cmp r3, #1 */
/* @0x133144 beq 0x1333b4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x444> */
/* @0x133148 cmp r3, #2 */
/* @0x13314c bne 0x13316c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x133150 sub r3, r2, #1 */
/* @0x133154 bic r3, r3, #-16777216 */
/* @0x133158 bic r3, r3, #3 */
/* @0x13315c cmp r3, #0 */
/* @0x133160 bne 0x13316c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x133164 ldr r0, [sp, #0xc] */
/* @0x133168 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x13316c ldr r12, [sp, #0xc] */
/* @0x133170 mov r0, #0 */
/* @0x133174 ldr r3, [sp, #0x34] */
/* @0x133178 ldr r1, [sp, #0x30] */
/* @0x13317c bic r2, r3, #-16777216 */
/* @0x133180 str r0, [r12] */
/* @0x133184 str r3, [r12, #0xc] */
/* @0x133188 str r1, [r12, #0x8] */
/* @0x13318c cmp r2, #14 */
/* @0x133190 addls pc, pc, r2, lsl #2 */
/* @0x133194 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x133198 b 0x13340c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x49c> */
/* @0x13319c b 0x133478 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x508> */
/* @0x1331a0 b 0x133448 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x4d8> */
/* @0x1331a4 b 0x13326c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x1331a8 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x1331ac b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x1331b0 b 0x133420 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x4b0> */
/* @0x1331b4 b 0x13326c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x1331b8 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x1331bc b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x1331c0 b 0x13340c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x49c> */
/* @0x1331c4 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x1331c8 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x1331cc b 0x13340c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x49c> */
/* @0x1331d0 b 0x13326c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x1331d4 ldr r3, [r5, #0x10] */
/* @0x1331d8 str r3, [r6, #-0xc] */
/* @0x1331dc add r11, r11, #1 */
/* @0x1331e0 add r6, r6, #16 */
/* @0x1331e4 cmp r11, r8 */
/* @0x1331e8 add r4, r4, #16 */
/* @0x1331ec beq 0x1330cc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x1331f0 mov r5, r9 */
/* @0x1331f4 b 0x13302c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x1331f8 ldm r9, {r2, r3} */
/* @0x1331fc stm r4, {r2, r3} */
/* @0x133200 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x133204 ldr r3, [r5, #0x10] */
/* @0x133208 cmp r3, #0 */
/* @0x13320c str r3, [r6, #-0xc] */
/* @0x133210 beq 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x133214 ldr r1, [r3, #0x8] */
/* @0x133218 ldr r2, [r3] */
/* @0x13321c cmp r1, #0 */
/* @0x133220 streq r4, [r3, #0x8] */
/* @0x133224 add r2, r2, #1 */
/* @0x133228 str r2, [r3] */
/* @0x13322c b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x133230 ldr r3, [r5, #0x10] */
/* @0x133234 cmp r3, #0 */
/* @0x133238 ldrne r2, [r3, #0x4] */
/* @0x13323c addne r2, r2, #1 */
/* @0x133240 strne r2, [r3, #0x4] */
/* @0x133244 b 0x1331d8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x268> */
/* @0x133248 ldr r3, [r5, #0x10] */
/* @0x13324c str r3, [r6, #-0xc] */
/* @0x133250 ldr r3, [r5, #0x10] */
/* @0x133254 cmp r3, #0 */
/* @0x133258 beq 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x13325c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x133260 ldr r1, [r5, #0x10] */
/* @0x133264 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x133268 b 0x1331dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x13326c ldr r2, [sp, #0x28] */
/* @0x133270 ldr r12, [sp, #0xc] */
/* @0x133274 str r2, [r12] */
/* @0x133278 sub r3, r3, #1 */
/* @0x13327c bic r3, r3, #-16777216 */
/* @0x133280 bic r3, r3, #3 */
/* @0x133284 cmp r3, #0 */
/* @0x133288 beq 0x133494 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x524> */
/* @0x13328c cmp r5, #0 */
/* @0x133290 mov r4, #0 */
/* @0x133294 mov r7, #5 */
/* @0x133298 str r4, [sp, #0x30] */
/* @0x13329c str r4, [sp, #0x28] */
/* @0x1332a0 str r7, [sp, #0x34] */
/* @0x1332a4 ble 0x13334c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x3dc> */
/* @0x1332a8 add r11, sp, #56 */
/* @0x1332ac mov r6, r4 */
/* @0x1332b0 b 0x1332c8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x358> */
/* @0x1332b4 cmp r4, r5 */
/* @0x1332b8 str r6, [r11, #0x8] */
/* @0x1332bc str r7, [r11, #0xc] */
/* @0x1332c0 str r6, [r11], #16 */
/* @0x1332c4 beq 0x13334c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x3dc> */
/* @0x1332c8 ldr r3, [r11, #0xc] */
/* @0x1332cc add r4, r4, #1 */
/* @0x1332d0 sub r3, r3, #1 */
/* @0x1332d4 bic r3, r3, #-16777216 */
/* @0x1332d8 bic r3, r3, #3 */
/* @0x1332dc cmp r3, #0 */
/* @0x1332e0 bne 0x1332b4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x344> */
/* @0x1332e4 mov r0, r11 */
/* @0x1332e8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1332ec b 0x1332b4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x344> */
/* @0x1332f0 ldr r10, [r6, #-0xc] */
/* @0x1332f4 cmp r10, #0 */
/* @0x1332f8 beq 0x133318 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x3a8> */
/* @0x1332fc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x133300 ldr r2, [r10, #0x4] */
/* @0x133304 sub r2, r2, #1 */
/* @0x133308 str r2, [r10, #0x4] */
/* @0x13330c cmp r2, #0 */
/* @0x133310 beq 0x133354 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x3e4> */
/* @0x133314 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x133318 str r7, [r6, #-0xc] */
/* @0x13331c b 0x133068 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x133320 ldr r0, [r12] */
/* @0x133324 bl 0x240758 <_Z20JS_IsCallable_ObjectP12YYObjectBase> */
/* @0x133328 cmp r0, #0 */
/* @0x13332c beq 0x132fe4 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x133330 ldr r2, [sp, #0x160] */
/* @0x133334 sub r3, r5, #1 */
/* @0x133338 ldr r0, [sp, #0x14] */
/* @0x13333c add r12, r2, #16 */
/* @0x133340 ldr r1, [sp, #0xc] */
/* @0x133344 str r12, [sp] */
/* @0x133348 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x13334c add sp, sp, #316 */
/* @0x133350 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x133354 ldr r0, [r10] */
/* @0x133358 str r2, [sp, #0x8] */
/* @0x13335c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x133360 ldr r2, [sp, #0x8] */
/* @0x133364 str r2, [r10] */
/* @0x133368 str r2, [r10, #0x8] */
/* @0x13336c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x133370 ldr r2, [r10, #0x4] */
/* @0x133374 sub r2, r2, #1 */
/* @0x133378 str r2, [r10, #0x4] */
/* @0x13337c cmp r2, #0 */
/* @0x133380 beq 0x1334a0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x530> */
/* @0x133384 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x133388 mov r0, r10 */
/* @0x13338c bl 0x27d1d0 <_ZdlPv> */
/* @0x133390 b 0x133314 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x3a4> */
/* @0x133394 mov r0, r4 */
/* @0x133398 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x13339c b 0x13305c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x1333a0 ldr r0, [pc, #0x278] */
/* @0x1333a4 add r0, pc, r0 */
/* @0x1333a8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1333ac add sp, sp, #316 */
/* @0x1333b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1333b4 ldr r12, [sp, #0xc] */
/* @0x1333b8 ldr r6, [r12] */
/* @0x1333bc cmp r6, #0 */
/* @0x1333c0 beq 0x1333e0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x470> */
/* @0x1333c4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1333c8 ldr r7, [r6, #0x4] */
/* @0x1333cc sub r7, r7, #1 */
/* @0x1333d0 str r7, [r6, #0x4] */
/* @0x1333d4 cmp r7, #0 */
/* @0x1333d8 beq 0x1334e0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x570> */
/* @0x1333dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1333e0 ldr r12, [sp, #0xc] */
/* @0x1333e4 mov r3, #0 */
/* @0x1333e8 str r3, [r12] */
/* @0x1333ec b 0x13316c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x1333f0 ldr r3, [pc, #0x22c] */
/* @0x1333f4 mov r1, #0 */
/* @0x1333f8 ldr r3, [r10, r3] */
/* @0x1333fc ldr r3, [r3] */
/* @0x133400 ldr r0, [r3] */
/* @0x133404 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x133408 b 0x133134 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x13340c ldr r1, [sp, #0x28] */
/* @0x133410 ldr r2, [sp, #0x2c] */
/* @0x133414 ldr r12, [sp, #0xc] */
/* @0x133418 stm r12, {r1, r2} */
/* @0x13341c b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x133420 ldr r2, [sp, #0x28] */
/* @0x133424 ldr r12, [sp, #0xc] */
/* @0x133428 cmp r2, #0 */
/* @0x13342c str r2, [r12] */
/* @0x133430 beq 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x133434 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x133438 ldr r1, [sp, #0x28] */
/* @0x13343c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x133440 ldr r3, [sp, #0x34] */
/* @0x133444 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x133448 ldr r2, [sp, #0x28] */
/* @0x13344c ldr r12, [sp, #0xc] */
/* @0x133450 cmp r2, #0 */
/* @0x133454 str r2, [r12] */
/* @0x133458 beq 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x13345c ldr r0, [r2, #0x8] */
/* @0x133460 ldr r1, [r2] */
/* @0x133464 cmp r0, #0 */
/* @0x133468 streq r12, [r2, #0x8] */
/* @0x13346c add r1, r1, #1 */
/* @0x133470 str r1, [r2] */
/* @0x133474 b 0x133278 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x133478 ldr r2, [sp, #0x28] */
/* @0x13347c cmp r2, #0 */
/* @0x133480 ldrne r3, [r2, #0x4] */
/* @0x133484 addne r3, r3, #1 */
/* @0x133488 strne r3, [r2, #0x4] */
/* @0x13348c ldrne r3, [sp, #0x34] */
/* @0x133490 b 0x133270 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x300> */
/* @0x133494 mov r0, r4 */
/* @0x133498 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x13349c b 0x13328c <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x31c> */
/* @0x1334a0 ldr r0, [r10] */
/* @0x1334a4 str r2, [sp, #0x8] */
/* @0x1334a8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1334ac ldr r2, [sp, #0x8] */
/* @0x1334b0 str r2, [r10] */
/* @0x1334b4 str r2, [r10, #0x8] */
/* @0x1334b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1334bc ldr r2, [r10, #0x4] */
/* @0x1334c0 sub r2, r2, #1 */
/* @0x1334c4 str r2, [r10, #0x4] */
/* @0x1334c8 cmp r2, #0 */
/* @0x1334cc beq 0x133550 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x5e0> */
/* @0x1334d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1334d4 mov r0, r10 */
/* @0x1334d8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1334dc b 0x133384 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x414> */
/* @0x1334e0 ldr r0, [r6] */
/* @0x1334e4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1334e8 str r7, [r6] */
/* @0x1334ec str r7, [r6, #0x8] */
/* @0x1334f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1334f4 ldr r7, [r6, #0x4] */
/* @0x1334f8 sub r7, r7, #1 */
/* @0x1334fc str r7, [r6, #0x4] */
/* @0x133500 cmp r7, #0 */
/* @0x133504 beq 0x133518 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x5a8> */
/* @0x133508 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x13350c mov r0, r6 */
/* @0x133510 bl 0x27d1d0 <_ZdlPv> */
/* @0x133514 b 0x1333dc <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x46c> */
/* @0x133518 ldr r0, [r6] */
/* @0x13351c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x133520 str r7, [r6] */
/* @0x133524 str r7, [r6, #0x8] */
/* @0x133528 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x13352c ldr r7, [r6, #0x4] */
/* @0x133530 sub r7, r7, #1 */
/* @0x133534 str r7, [r6, #0x4] */
/* @0x133538 cmp r7, #0 */
/* @0x13353c beq 0x1335b8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x648> */
/* @0x133540 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x133544 mov r0, r6 */
/* @0x133548 bl 0x27d1d0 <_ZdlPv> */
/* @0x13354c b 0x133508 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x598> */
/* @0x133550 ldr r0, [r10] */
/* @0x133554 str r2, [sp, #0x8] */
/* @0x133558 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x13355c ldr r2, [sp, #0x8] */
/* @0x133560 str r2, [r10] */
/* @0x133564 str r2, [r10, #0x8] */
/* @0x133568 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x13356c ldr r2, [r10, #0x4] */
/* @0x133570 sub r2, r2, #1 */
/* @0x133574 str r2, [r10, #0x4] */
/* @0x133578 cmp r2, #0 */
/* @0x13357c bne 0x1335a8 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x638> */
/* @0x133580 ldr r0, [r10] */
/* @0x133584 str r2, [sp, #0x8] */
/* @0x133588 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x13358c ldr r2, [sp, #0x8] */
/* @0x133590 mov r0, r10 */
/* @0x133594 str r2, [r10] */
/* @0x133598 str r2, [r10, #0x8] */
/* @0x13359c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1335a0 mov r0, r10 */
/* @0x1335a4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1335a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1335ac mov r0, r10 */
/* @0x1335b0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1335b4 b 0x1334d0 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x560> */
/* @0x1335b8 ldr r0, [r6] */
/* @0x1335bc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1335c0 str r7, [r6] */
/* @0x1335c4 str r7, [r6, #0x8] */
/* @0x1335c8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1335cc ldr r7, [r6, #0x4] */
/* @0x1335d0 sub r7, r7, #1 */
/* @0x1335d4 str r7, [r6, #0x4] */
/* @0x1335d8 cmp r7, #0 */
/* @0x1335dc bne 0x133600 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x690> */
/* @0x1335e0 ldr r0, [r6] */
/* @0x1335e4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1335e8 mov r0, r6 */
/* @0x1335ec str r7, [r6] */
/* @0x1335f0 str r7, [r6, #0x8] */
/* @0x1335f4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1335f8 mov r0, r6 */
/* @0x1335fc bl 0x27d1d0 <_ZdlPv> */
/* @0x133600 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x133604 mov r0, r6 */
/* @0x133608 bl 0x27d1d0 <_ZdlPv> */
/* @0x13360c b 0x133540 <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x5d0> */
/* @0x133610 eoreq lr, r11, r8, lsr #25 */
/* @0x133614 .word 0xffffbf68 */
/* @0x133618 .word 0xffffc0bc */
/* @0x13361c .word 0xffffbf14 */
/* @0x133620 .word 0x0020bfb4 */
/* @0x133624 .word 0xffffbf20 */

/* ── FUNC 0x133628 · F_AudioPauseAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x133628 ldr r3, [pc, #0x10] */
/* @0x13362c ldr r3, [pc, r3] */
/* @0x133630 ldrb r3, [r3] */
/* @0x133634 cmp r3, #0 */
/* @0x133638 bxne lr */
/* @0x13363c b 0x217c48 <_Z14Audio_PauseAllv> */
/* @0x133640 eoreq r11, r11, r0, lsr #20 */

/* ── FUNC 0x133644 · F_AudioResumeAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x133644 ldr r3, [pc, #0x10] */
/* @0x133648 ldr r3, [pc, r3] */
/* @0x13364c ldrb r3, [r3] */
/* @0x133650 cmp r3, #0 */
/* @0x133654 bxne lr */
/* @0x133658 b 0x217df4 <_Z15Audio_ResumeAllv> */
/* @0x13365c eoreq r11, r11, r4, lsl #20 */

/* ── FUNC 0x133660 · F_AudioStopAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x133660 ldr r3, [pc, #0x10] */
/* @0x133664 ldr r3, [pc, r3] */
/* @0x133668 ldrb r0, [r3] */
/* @0x13366c cmp r0, #0 */
/* @0x133670 bxne lr */
/* @0x133674 b 0x21a3bc <_Z13Audio_StopAllb> */
/* @0x133678 eoreq r11, r11, r8, ror #19 */

/* ── FUNC 0x13367c · F_Audio_StopRecording(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x13367c push {r4, lr} */
/* @0x133680 mov r3, #0 */
/* @0x133684 mov r1, r3 */
/* @0x133688 str r3, [r0, #0xc] */
/* @0x13368c mov r4, r0 */
/* @0x133690 ldr r0, [sp, #0x8] */
/* @0x133694 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x133698 bl 0x21caf8 <_Z19Audio_StopRecordingi> */
/* @0x13369c vmov s15, r0 */
/* @0x1336a0 vcvt.f64.s32 d7, s15 */
/* @0x1336a4 vmov r0, r1, d7 */
/* @0x1336a8 vmov r2, s14 */
/* @0x1336ac mov r3, r1 */
/* @0x1336b0 stm r4, {r2, r3} */
/* @0x1336b4 pop {r4, pc} */

/* ── FUNC 0x1336b8 · F_CDInit(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1336b8 b 0x214858 <_Z7CD_Initv> */

/* ── FUNC 0x1336bc · F_CDPresent(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1336bc push {r4, lr} */
/* @0x1336c0 mov r3, #0 */
/* @0x1336c4 str r3, [r0, #0xc] */
/* @0x1336c8 mov r4, r0 */
/* @0x1336cc bl 0x21485c <_Z10CD_Presentv> */
/* @0x1336d0 vmov s15, r0 */
/* @0x1336d4 vcvt.f64.u32 d7, s15 */
/* @0x1336d8 vmov r0, r1, d7 */
/* @0x1336dc vmov r2, s14 */
/* @0x1336e0 mov r3, r1 */
/* @0x1336e4 stm r4, {r2, r3} */
/* @0x1336e8 pop {r4, pc} */

/* ── FUNC 0x1336ec · F_CDNumber(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1336ec push {r4, lr} */
/* @0x1336f0 mov r3, #0 */
/* @0x1336f4 str r3, [r0, #0xc] */
/* @0x1336f8 mov r4, r0 */
/* @0x1336fc bl 0x214864 <_Z17CD_NumberOfTracksv> */
/* @0x133700 vmov s15, r0 */
/* @0x133704 vcvt.f64.s32 d7, s15 */
/* @0x133708 vmov r0, r1, d7 */
/* @0x13370c vmov r2, s14 */
/* @0x133710 mov r3, r1 */
/* @0x133714 stm r4, {r2, r3} */
/* @0x133718 pop {r4, pc} */

/* ── FUNC 0x13371c · F_CDPlaying(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x13371c push {r4, lr} */
/* @0x133720 mov r3, #0 */
/* @0x133724 str r3, [r0, #0xc] */
/* @0x133728 mov r4, r0 */
/* @0x13372c bl 0x21486c <_Z10CD_Playingv> */
/* @0x133730 vmov s15, r0 */
/* @0x133734 vcvt.f64.u32 d7, s15 */
/* @0x133738 vmov r0, r1, d7 */
/* @0x13373c vmov r2, s14 */
/* @0x133740 mov r3, r1 */
/* @0x133744 stm r4, {r2, r3} */
/* @0x133748 pop {r4, pc} */

/* ── FUNC 0x13374c · F_CDPaused(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x13374c push {r4, lr} */
/* @0x133750 mov r3, #0 */
/* @0x133754 str r3, [r0, #0xc] */
/* @0x133758 mov r4, r0 */
/* @0x13375c bl 0x214874 <_Z9CD_Pausedv> */
/* @0x133760 vmov s15, r0 */
/* @0x133764 vcvt.f64.u32 d7, s15 */
/* @0x133768 vmov r0, r1, d7 */
/* @0x13376c vmov r2, s14 */
/* @0x133770 mov r3, r1 */
/* @0x133774 stm r4, {r2, r3} */
/* @0x133778 pop {r4, pc} */

/* ── FUNC 0x13377c · F_CDTrack(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x13377c push {r4, lr} */
/* @0x133780 mov r3, #0 */
/* @0x133784 str r3, [r0, #0xc] */
/* @0x133788 mov r4, r0 */
/* @0x13378c bl 0x21487c <_Z8CD_Trackv> */
/* @0x133790 vmov s15, r0 */
/* @0x133794 vcvt.f64.s32 d7, s15 */
/* @0x133798 vmov r0, r1, d7 */
/* @0x13379c vmov r2, s14 */
/* @0x1337a0 mov r3, r1 */
/* @0x1337a4 stm r4, {r2, r3} */
/* @0x1337a8 pop {r4, pc} */

/* ── FUNC 0x1337ac · F_CDLength(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1337ac push {r4, lr} */
/* @0x1337b0 mov r3, #0 */
/* @0x1337b4 str r3, [r0, #0xc] */
/* @0x1337b8 mov r4, r0 */
/* @0x1337bc bl 0x214884 <_Z9CD_Lengthv> */
/* @0x1337c0 vmov s15, r0 */
/* @0x1337c4 vcvt.f64.s32 d7, s15 */
/* @0x1337c8 vmov r0, r1, d7 */
/* @0x1337cc vmov r2, s14 */
/* @0x1337d0 mov r3, r1 */
/* @0x1337d4 stm r4, {r2, r3} */
/* @0x1337d8 pop {r4, pc} */
