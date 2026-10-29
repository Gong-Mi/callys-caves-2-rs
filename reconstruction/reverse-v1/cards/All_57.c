/* cally 逆向卡：All_57 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 181 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/181 F_TileLayerFind(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c52c  size 172  43 条（0x11c52c..0x11c5d8）
 * @func 0x11c52c 0x11c5d8  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / CRoom::FindTileAtDepth(float, float, float)
 * 字段偏移 top8: 0x20×2 / 0x90×1 / 0xc×1 / 0x4×1 / 0xb8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c52c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11c530 mov r6, #0
 *   @0x11c534 ldr r7, [sp, #0x20]
 *   @0x11c538 mov r1, r6
 *   @0x11c53c ldr r5, [pc, #0x90]
 *   @0x11c540 mov r4, r0
 *   @0x11c544 str r6, [r0]
 *   @0x11c548 mov r3, r6
 *   @0x11c54c ldr r5, [pc, r5]
 *   @0x11c550 movt r3, #0xbff0
 *   @0x11c554 str r6, [r0, #0xc]
 *   @0x11c558 str r3, [r0, #0x4]
 *   @0x11c55c mov r0, r7
 *   @0x11c560 ldr r10, [r5]
 *   @0x11c564 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c568 mov r1, #1
 *   @0x11c56c mov r9, r0
 *   @0x11c570 mov r0, r7
 *   @0x11c574 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c578 mov r1, #2
 *   @0x11c57c mov r8, r0
 *   @0x11c580 mov r0, r7
 *   @0x11c584 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c588 mov r1, r9
 *   @0x11c58c mov r2, r8
 *   @0x11c590 mov r3, r0
 *   @0x11c594 mov r0, r10
 *   @0x11c598 bl 0x1af72c <_ZN5CRoom15FindTileAtDepthEfff>
 *   @0x11c59c cmp r0, #0
 *   @0x11c5a0 poplt {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11c5a4 ldr r3, [r5]
 *   @0x11c5a8 ldr r2, [r3, #0xb8]
 *   @0x11c5ac cmp r0, r2
 *   @0x11c5b0 rsblt r0, r0, r0, lsl #3
 *   @0x11c5b4 ldrlt r3, [r3, #0xc0]
 *   @0x11c5b8 addlt r6, r3, r0, lsl #3
 *   @0x11c5bc ldr r2, [r6, #0x20]
 *   @0x11c5c0 vmov s15, r2
 *   @0x11c5c4 vcvt.f64.s32 d7, s15
 *   @0x11c5c8 vmov r2, r3, d7
 *   @0x11c5cc stm r4, {r2, r3}
 *   @0x11c5d0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11c5d4 .word 0x002d13dc
 *
 * ══ §2/181 YYGML_draw_self(CInstance*)  0x123088  size 172  43 条（0x123088..0x123134）
 * @func 0x123088 0x123134  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Data(int) / 0xb6598 / CSprite::Draw(int, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x8c×1 / 0x78×1 / 0xa8×1 / 0x98×1 / 0xb8×1 / 0xb4×1 / 0xc×1 / 0xa0×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x123088 push {r4, r5, r6, lr}
 *   @0x12308c mov r4, r0
 *   @0x123090 sub sp, sp, #24
 *   @0x123094 ldr r0, [r0, #0x8c]
 *   @0x123098 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12309c subs r6, r0, #0
 *   @0x1230a0 beq 0x123114 <_Z15YYGML_draw_selfP9CInstance+0x8c>
 *   @0x1230a4 vldr s15, [r4, #144]
 *   @0x1230a8 vcvt.f64.f32 d6, s15
 *   @0x1230ac ldr r5, [pc, #0x78]
 *   @0x1230b0 ldr r5, [pc, r5]
 *   @0x1230b4 str r4, [r5]
 *   @0x1230b8 vmov r0, r1, d6
 *   @0x1230bc bl 0xb6598 <floor@plt>
 *   @0x1230c0 ldr r12, [r4, #0xa8]
 *   @0x1230c4 ldr lr, [r4, #0x98]
 *   @0x1230c8 ldr r3, [r4, #0xb8]
 *   @0x1230cc ldr r2, [r4, #0xb4]
 *   @0x1230d0 str r12, [sp, #0xc]
 *   @0x1230d4 str lr, [sp]
 *   @0x1230d8 ldr r12, [r4, #0xa0]
 *   @0x1230dc ldr lr, [r4, #0x9c]
 *   @0x1230e0 str r12, [sp, #0x8]
 *   @0x1230e4 str lr, [sp, #0x4]
 *   @0x1230e8 ldr r12, [r4, #0xa4]
 *   @0x1230ec str r12, [sp, #0x10]
 *   @0x1230f0 vmov d7, r0, r1
 *   @0x1230f4 mov r0, r6
 *   @0x1230f8 vcvt.s32.f64 s15, d7
 *   @0x1230fc vmov r1, s15
 *   @0x123100 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf>
 *   @0x123104 mov r3, #0
 *   @0x123108 str r3, [r5]
 *   @0x12310c add sp, sp, #24
 *   @0x123110 pop {r4, r5, r6, pc}
 *   @0x123114 ldr r0, [pc, #0x14]
 *   @0x123118 mov r1, r6
 *   @0x12311c add r0, pc, r0
 *   @0x123120 add sp, sp, #24
 *   @0x123124 pop {r4, r5, r6, lr}
 *   @0x123128 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12312c eoreq r10, r12, r4, lsl #17
 *   @0x123130 mlaeq r1, r8, lr, r6
 *
 * ══ §3/181 F_ShowQuestionASync(RValue&, CInstance*, CInstance*, int, RValue*)  0x1267c4  size 172  43 条（0x1267c4..0x126870）
 * @func 0x1267c4 0x126870  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / InputQuery::QuestionAsync(char const*, char const*) / IO_Clear() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×4 / 0x9c×1 / 0x4×1 / 0x20×1 / 0x-4×1 / 0x40×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1267c4 ldr r1, [pc, #0x9c]
 *   @0x1267c8 mov r12, #16
 *   @0x1267cc push {r4, r5, lr}
 *   @0x1267d0 sub sp, sp, #20
 *   @0x1267d4 mov r4, r0
 *   @0x1267d8 add r1, pc, r1
 *   @0x1267dc mov r0, r12
 *   @0x1267e0 mov r2, #604
 *   @0x1267e4 mov r3, #1
 *   @0x1267e8 str r12, [sp, #0x4]
 *   @0x1267ec ldr r5, [sp, #0x20]
 *   @0x1267f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1267f4 add r1, sp, #8
 *   @0x1267f8 mov r3, r5
 *   @0x1267fc mov r5, #0
 *   @0x126800 mov r2, r0
 *   @0x126804 add r0, sp, #16
 *   @0x126808 str r2, [sp, #0x8]
 *   @0x12680c str r2, [r0, #-0x4]!
 *   @0x126810 strb r5, [r2]
 *   @0x126814 add r2, sp, #4
 *   @0x126818 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x12681c ldr r0, [sp, #0x8]
 *   @0x126820 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x126824 ldr r3, [pc, #0x40]
 *   @0x126828 ldr r1, [sp, #0x8]
 *   @0x12682c ldr r3, [pc, r3]
 *   @0x126830 str r5, [r4, #0xc]
 *   @0x126834 ldr r0, [r3]
 *   @0x126838 bl 0xf26ec <_ZN10InputQuery13QuestionAsyncEPKcS1_>
 *   @0x12683c vmov s15, r0
 *   @0x126840 vcvt.f64.s32 d7, s15
 *   @0x126844 vmov r0, r1, d7
 *   @0x126848 vmov r2, s14
 *   @0x12684c mov r3, r1
 *   @0x126850 stm r4, {r2, r3}
 *   @0x126854 bl 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126858 ldr r0, [sp, #0x8]
 *   @0x12685c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x126860 add sp, sp, #20
 *   @0x126864 pop {r4, r5, pc}
 *   @0x126868 eoreq r5, r1, r12, asr r10
 *   @0x12686c eoreq r8, r12, r4, asr r2
 *
 * ══ §4/181 F_ShowMessageASync(RValue&, CInstance*, CInstance*, int, RValue*)  0x126f44  size 172  43 条（0x126f44..0x126ff0）
 * @func 0x126f44 0x126ff0  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / InputQuery::ShowMessageASync(char const*, char const*) / IO_Clear() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×4 / 0x9c×1 / 0x4×1 / 0x20×1 / 0x-4×1 / 0x40×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126f44 ldr r1, [pc, #0x9c]
 *   @0x126f48 mov r12, #16
 *   @0x126f4c push {r4, r5, lr}
 *   @0x126f50 sub sp, sp, #20
 *   @0x126f54 mov r4, r0
 *   @0x126f58 add r1, pc, r1
 *   @0x126f5c mov r0, r12
 *   @0x126f60 movw r2, #0x59c
 *   @0x126f64 mov r3, #1
 *   @0x126f68 str r12, [sp, #0x4]
 *   @0x126f6c ldr r5, [sp, #0x20]
 *   @0x126f70 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x126f74 add r1, sp, #8
 *   @0x126f78 mov r3, r5
 *   @0x126f7c mov r5, #0
 *   @0x126f80 mov r2, r0
 *   @0x126f84 add r0, sp, #16
 *   @0x126f88 str r2, [sp, #0x8]
 *   @0x126f8c str r2, [r0, #-0x4]!
 *   @0x126f90 strb r5, [r2]
 *   @0x126f94 add r2, sp, #4
 *   @0x126f98 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x126f9c ldr r0, [sp, #0x8]
 *   @0x126fa0 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x126fa4 ldr r3, [pc, #0x40]
 *   @0x126fa8 ldr r1, [sp, #0x8]
 *   @0x126fac ldr r3, [pc, r3]
 *   @0x126fb0 str r5, [r4, #0xc]
 *   @0x126fb4 ldr r0, [r3]
 *   @0x126fb8 bl 0xf270c <_ZN10InputQuery16ShowMessageASyncEPKcS1_>
 *   @0x126fbc vmov s15, r0
 *   @0x126fc0 vcvt.f64.s32 d7, s15
 *   @0x126fc4 vmov r0, r1, d7
 *   @0x126fc8 vmov r2, s14
 *   @0x126fcc mov r3, r1
 *   @0x126fd0 stm r4, {r2, r3}
 *   @0x126fd4 bl 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126fd8 ldr r0, [sp, #0x8]
 *   @0x126fdc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x126fe0 add sp, sp, #20
 *   @0x126fe4 pop {r4, r5, pc}
 *   @0x126fe8 .word 0x002152dc
 *   @0x126fec .word 0x002c7ad4
 *
 * ══ §5/181 F_FontAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x12cf28  size 172  43 条（0x12cf28..0x12cfd4）
 * @func 0x12cf28 0x12cfd4  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetBool(RValue const*, int)×2 / YYGetString(RValue const*, int) / Font_Add(char const*, int, bool, bool, int, int)
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12cf28 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x12cf2c sub sp, sp, #8
 *   @0x12cf30 mov r5, r0
 *   @0x12cf34 mov r1, #0
 *   @0x12cf38 ldr r4, [sp, #0x28]
 *   @0x12cf3c str r1, [r0, #0xc]
 *   @0x12cf40 mov r0, r4
 *   @0x12cf44 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12cf48 mov r1, #1
 *   @0x12cf4c mov r6, r0
 *   @0x12cf50 mov r0, r4
 *   @0x12cf54 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cf58 mov r1, #2
 *   @0x12cf5c mov r9, r0
 *   @0x12cf60 mov r0, r4
 *   @0x12cf64 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12cf68 mov r1, #3
 *   @0x12cf6c mov r8, r0
 *   @0x12cf70 mov r0, r4
 *   @0x12cf74 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12cf78 mov r1, #4
 *   @0x12cf7c mov r7, r0
 *   @0x12cf80 mov r0, r4
 *   @0x12cf84 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cf88 mov r1, #5
 *   @0x12cf8c mov r10, r0
 *   @0x12cf90 mov r0, r4
 *   @0x12cf94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cf98 mov r1, r9
 *   @0x12cf9c mov r2, r8
 *   @0x12cfa0 mov r3, r7
 *   @0x12cfa4 str r10, [sp]
 *   @0x12cfa8 str r0, [sp, #0x4]
 *   @0x12cfac mov r0, r6
 *   @0x12cfb0 bl 0xfa43c <_Z8Font_AddPKcibbii>
 *   @0x12cfb4 vmov s15, r0
 *   @0x12cfb8 vcvt.f64.s32 d7, s15
 *   @0x12cfbc vmov r0, r1, d7
 *   @0x12cfc0 vmov r2, s14
 *   @0x12cfc4 mov r3, r1
 *   @0x12cfc8 stm r5, {r2, r3}
 *   @0x12cfcc add sp, sp, #8
 *   @0x12cfd0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §6/181 F_FileBinWriteByte(RValue&, CInstance*, CInstance*, int, RValue*)  0x1397ac  size 172  43 条（0x1397ac..0x139858）
 * @func 0x1397ac 0x139858  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / LoadSave::fwrite(void const*, unsigned int, unsigned int, _YYFILE*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x18×2 / 0x7×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1397ac push {r4, r5, lr}
 *   @0x1397b0 sub sp, sp, #12
 *   @0x1397b4 mov r1, #0
 *   @0x1397b8 ldr r5, [sp, #0x18]
 *   @0x1397bc mov r0, r5
 *   @0x1397c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1397c4 mov r1, #1
 *   @0x1397c8 mov r4, r0
 *   @0x1397cc mov r0, r5
 *   @0x1397d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1397d4 sub r3, r4, #1
 *   @0x1397d8 cmp r3, #30
 *   @0x1397dc strb r0, [sp, #0x7]
 *   @0x1397e0 bhi 0x139834 <_Z18F_FileBinWriteByteR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1397e4 ldr r3, [pc, #0x60]
 *   @0x1397e8 ldr r3, [pc, r3]
 *   @0x1397ec ldrb r3, [r3, r4]
 *   @0x1397f0 cmp r3, #0
 *   @0x1397f4 beq 0x139834 <_Z18F_FileBinWriteByteR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1397f8 ldr r3, [pc, #0x50]
 *   @0x1397fc add r4, r4, r4, lsl #1
 *   @0x139800 ldr r3, [pc, r3]
 *   @0x139804 add r3, r3, r4, lsl #2
 *   @0x139808 ldr r2, [r3, #0x4]
 *   @0x13980c sub r2, r2, #1
 *   @0x139810 cmp r2, #1
 *   @0x139814 bhi 0x139844 <_Z18F_FileBinWriteByteR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x139818 mov r1, #1
 *   @0x13981c ldr r3, [r3, #0x8]
 *   @0x139820 mov r2, r1
 *   @0x139824 add r0, sp, #7
 *   @0x139828 bl 0x18e2b0 <_ZN8LoadSave6fwriteEPKvjjP7_YYFILE>
 *   @0x13982c add sp, sp, #12
 *   @0x139830 pop {r4, r5, pc}
 *   @0x139834 ldr r0, [pc, #0x18]
 *   @0x139838 mov r1, #0
 *   @0x13983c add r0, pc, r0
 *   @0x139840 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139844 add sp, sp, #12
 *   @0x139848 pop {r4, r5, pc}
 *   @0x13984c eoreq r5, r11, r4, lsr #21
 *   @0x139850 mlaeq r11, r0, r10, r5
 *   @0x139854 eoreq r6, r0, r4, asr #18
 *
 * ══ §7/181 F_ActionIfEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0x13ec84  size 172  43 条（0x13ec84..0x13ed30）
 * @func 0x13ec84 0x13ed30  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Command_IsEmpty(CInstance*, float, float) / Command_IsFree(CInstance*, float, float)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x58×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ec84 push {r4, r5, r6, lr}
 *   @0x13ec88 vpush {d8}
 *   @0x13ec8c mov r3, #0
 *   @0x13ec90 ldr r4, [sp, #0x18]
 *   @0x13ec94 mov r6, r1
 *   @0x13ec98 str r3, [r0, #0xc]
 *   @0x13ec9c mov r1, r3
 *   @0x13eca0 mov r5, r0
 *   @0x13eca4 mov r0, r4
 *   @0x13eca8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13ecac mov r1, #1
 *   @0x13ecb0 vmov s17, r0
 *   @0x13ecb4 mov r0, r4
 *   @0x13ecb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13ecbc mov r1, #2
 *   @0x13ecc0 vmov s16, r0
 *   @0x13ecc4 mov r0, r4
 *   @0x13ecc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13eccc ldr r3, [pc, #0x58]
 *   @0x13ecd0 ldr r3, [pc, r3]
 *   @0x13ecd4 ldrb r3, [r3]
 *   @0x13ecd8 cmp r3, #0
 *   @0x13ecdc vldrne s14, [r6, #180]
 *   @0x13ece0 vldrne s15, [r6, #184]
 *   @0x13ece4 vaddne.f32 s17, s17, s14
 *   @0x13ece8 vaddne.f32 s16, s16, s15
 *   @0x13ecec cmp r0, #0
 *   @0x13ecf0 vmov r1, s17
 *   @0x13ecf4 mov r0, r6
 *   @0x13ecf8 vmov r2, s16
 *   @0x13ecfc beq 0x13ed24 <_Z15F_ActionIfEmptyR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x13ed00 bl 0x1caa1c <_Z15Command_IsEmptyP9CInstanceff>
 *   @0x13ed04 vmov s15, r0
 *   @0x13ed08 vcvt.f64.u32 d7, s15
 *   @0x13ed0c vmov r0, r1, d7
 *   @0x13ed10 vmov r2, s14
 *   @0x13ed14 mov r3, r1
 *   @0x13ed18 stm r5, {r2, r3}
 *   @0x13ed1c vpop {d8}
 *   @0x13ed20 pop {r4, r5, r6, pc}
 *   @0x13ed24 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x13ed28 b 0x13ed04 <_Z15F_ActionIfEmptyR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x13ed2c eoreq lr, r10, r12, ror #28
 *
 * ══ §8/181 F_ActionDrawVariable(RValue&, CInstance*, CInstance*, int, RValue*)  0x13f02c  size 172  43 条（0x13f02c..0x13f0d8）
 * @func 0x13f02c 0x13f0d8  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / GR_Text_Draw(float, float, char const*, int, int)×2 / YYGML_string(RValue const&)
 * 字段偏移 top8: 0x20×1 / 0x64×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13f02c push {r4, r5, r6, lr}
 *   @0x13f030 vpush {d8}
 *   @0x13f034 sub sp, sp, #8
 *   @0x13f038 mov r6, r1
 *   @0x13f03c ldr r4, [sp, #0x20]
 *   @0x13f040 mov r0, r4
 *   @0x13f044 bl 0x111130 <_Z12YYGML_stringRK6RValue>
 *   @0x13f048 mov r1, #1
 *   @0x13f04c mov r5, r0
 *   @0x13f050 mov r0, r4
 *   @0x13f054 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f058 mov r1, #2
 *   @0x13f05c vmov s16, r0
 *   @0x13f060 mov r0, r4
 *   @0x13f064 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f068 ldr r3, [pc, #0x64]
 *   @0x13f06c ldr r3, [pc, r3]
 *   @0x13f070 ldrb r3, [r3]
 *   @0x13f074 cmp r3, #0
 *   @0x13f078 mvn r3, #0
 *   @0x13f07c vmov s15, r0
 *   @0x13f080 bne 0x13f0ac <_Z20F_ActionDrawVariableR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x13f084 vmov r0, s16
 *   @0x13f088 mov r2, r5
 *   @0x13f08c str r3, [sp]
 *   @0x13f090 vmov r1, s15
 *   @0x13f094 bl 0x172df8 <_Z12GR_Text_DrawffPKcii>
 *   @0x13f098 mov r0, r5
 *   @0x13f09c add sp, sp, #8
 *   @0x13f0a0 vpop {d8}
 *   @0x13f0a4 pop {r4, r5, r6, lr}
 *   @0x13f0a8 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13f0ac vldr s14, [r6, #180]
 *   @0x13f0b0 vadd.f32 s14, s16, s14
 *   @0x13f0b4 str r3, [sp]
 *   @0x13f0b8 mov r2, r5
 *   @0x13f0bc vmov r0, s14
 *   @0x13f0c0 vldr s14, [r6, #184]
 *   @0x13f0c4 vadd.f32 s14, s15, s14
 *   @0x13f0c8 vmov r1, s14
 *   @0x13f0cc bl 0x172df8 <_Z12GR_Text_DrawffPKcii>
 *   @0x13f0d0 b 0x13f098 <_Z20F_ActionDrawVariableR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x13f0d4 .word 0x002aead0
 *
 * ══ §9/181 Push_SendEvent(bool, ePushEventType, char const*)  0x155f84  size 172  43 条（0x155f84..0x156030）
 * @func 0x155f84 0x156030  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / SPushNotificationEvent::SPushNotificationEvent(int, ePushEventType, char const*) / Push_InitQueue() / Mutex::Lock()
 * 字段偏移 top8: 0x64×2 / 0x4×2 / 0x8×1 / 0xc×1 / 0x48×1 / 0x34×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x155f84 push {r3, r4, r5, r6, r7, lr}
 *   @0x155f88 mov r7, r0
 *   @0x155f8c mov r0, #16
 *   @0x155f90 mov r6, r1
 *   @0x155f94 mov r5, r2
 *   @0x155f98 bl 0x27c524 <_Znwj>
 *   @0x155f9c mov r1, r7
 *   @0x155fa0 mov r2, r6
 *   @0x155fa4 mov r3, r5
 *   @0x155fa8 mov r4, r0
 *   @0x155fac bl 0x155b50 <_ZN22SPushNotificationEventC2Ei14ePushEventTypePKc>
 *   @0x155fb0 ldr r3, [pc, #0x64]
 *   @0x155fb4 ldr r1, [pc, #0x64]
 *   @0x155fb8 ldr r3, [pc, r3]
 *   @0x155fbc ldr r2, [r4, #0x8]
 *   @0x155fc0 add r1, pc, r1
 *   @0x155fc4 ldr r0, [r3]
 *   @0x155fc8 ldr r3, [r0]
 *   @0x155fcc ldr r3, [r3, #0xc]
 *   @0x155fd0 blx r3
 *   @0x155fd4 ldr r3, [pc, #0x48]
 *   @0x155fd8 add r3, pc, r3
 *   @0x155fdc ldrb r3, [r3]
 *   @0x155fe0 cmp r3, #0
 *   @0x155fe4 bne 0x155fec <_Z14Push_SendEventb14ePushEventTypePKc+0x68>
 *   @0x155fe8 bl 0x155ba0 <_Z14Push_InitQueuev>
 *   @0x155fec ldr r5, [pc, #0x34]
 *   @0x155ff0 add r5, pc, r5
 *   @0x155ff4 ldr r0, [r5, #0x4]
 *   @0x155ff8 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x155ffc ldr r3, [pc, #0x28]
 *   @0x156000 ldr r0, [r5, #0x4]
 *   @0x156004 ldr r3, [pc, r3]
 *   @0x156008 ldr r2, [r3]
 *   @0x15600c str r2, [r4]
 *   @0x156010 str r4, [r3]
 *   @0x156014 pop {r3, r4, r5, r6, r7, lr}
 *   @0x156018 b 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x15601c eoreq r7, r9, r12, asr r7
 *   @0x156020 andseq r0, pc, r12, lsl r5
 *   @0x156024 eorseq lr, r2, r4, lsl #21
 *   @0x156028 eorseq lr, r2, r12, ror #20
 *   @0x15602c eoreq r9, r9, r0, lsl r11
 *
 * ══ §10/181 FacebookUserIdM()  0x15ef7c  size 172  43 条（0x15ef7c..0x15f028）
 * @func 0x15ef7c 0x15f028  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×4 / _JNIEnv::CallStaticObjectMethod(_jclass*, _jmethodID*, ...) / 0xb6568
 * 字段偏移 top8: 0x8c×2 / 0x2a4×1 / 0x50×1 / 0x2a8×1 / 0x5c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15ef7c push {r3, r4, r5, lr}
 *   @0x15ef80 bl 0x290274 <getJNIEnv>
 *   @0x15ef84 ldr r2, [pc, #0x8c]
 *   @0x15ef88 ldr r3, [pc, #0x8c]
 *   @0x15ef8c ldr r2, [pc, r2]
 *   @0x15ef90 ldr r3, [pc, r3]
 *   @0x15ef94 ldr r1, [r2]
 *   @0x15ef98 ldr r2, [r3]
 *   @0x15ef9c bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz>
 *   @0x15efa0 mov r4, r0
 *   @0x15efa4 bl 0x290274 <getJNIEnv>
 *   @0x15efa8 mov r1, r4
 *   @0x15efac mov r2, #0
 *   @0x15efb0 ldr r3, [r0]
 *   @0x15efb4 ldr r3, [r3, #0x2a4]
 *   @0x15efb8 blx r3
 *   @0x15efbc mov r2, #255
 *   @0x15efc0 mov r5, r0
 *   @0x15efc4 mov r1, r0
 *   @0x15efc8 ldr r0, [pc, #0x50]
 *   @0x15efcc add r0, pc, r0
 *   @0x15efd0 bl 0xb6568 <strncpy@plt>
 *   @0x15efd4 cmp r5, #0
 *   @0x15efd8 cmpne r4, #0
 *   @0x15efdc beq 0x15f00c <_Z15FacebookUserIdMv+0x90>
 *   @0x15efe0 bl 0x290274 <getJNIEnv>
 *   @0x15efe4 mov r1, r4
 *   @0x15efe8 mov r2, r5
 *   @0x15efec ldr r3, [r0]
 *   @0x15eff0 ldr r3, [r3, #0x2a8]
 *   @0x15eff4 blx r3
 *   @0x15eff8 bl 0x290274 <getJNIEnv>
 *   @0x15effc mov r1, r4
 *   @0x15f000 ldr r3, [r0]
 *   @0x15f004 ldr r3, [r3, #0x5c]
 *   @0x15f008 blx r3
 *   @0x15f00c ldr r0, [pc, #0x10]
 *   @0x15f010 add r0, pc, r0
 *   @0x15f014 pop {r3, r4, r5, pc}
 *   @0x15f018 eoreq lr, r8, r8, lsl r10
 *   @0x15f01c eoreq r0, r9, r0, lsr pc
 *   @0x15f020 eorseq r5, r2, r12, ror #21
 *   @0x15f024 eorseq r5, r2, r8, lsr #21
 *
 * ══ §11/181 CBitmap32::SaveToStream(CStream*)  0x167844  size 172  43 条（0x167844..0x1678f0）
 * @func 0x167844 0x1678f0  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::WriteInteger(int)×3 / CStream::WriteBoolean(bool) / operator new(unsigned int) / CStream::CStream(int) / CStream::WriteBuffer(void*, int) / CStream::WriteCompressedStream(CStream*) / CStream::~CStream() / operator delete(void*)
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×2 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167844 push {r4, r5, r6, lr}
 *   @0x167848 mov r5, r1
 *   @0x16784c mov r4, r0
 *   @0x167850 mov r1, #540
 *   @0x167854 mov r0, r5
 *   @0x167858 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x16785c mov r0, r5
 *   @0x167860 ldrb r1, [r4, #0x4]
 *   @0x167864 bl 0x201bb8 <_ZN7CStream12WriteBooleanEb>
 *   @0x167868 ldrb r3, [r4, #0x4]
 *   @0x16786c cmp r3, #0
 *   @0x167870 bne 0x16787c <_ZN9CBitmap3212SaveToStreamEP7CStream+0x38>
 *   @0x167874 mov r0, #1
 *   @0x167878 pop {r4, r5, r6, pc}
 *   @0x16787c mov r0, r5
 *   @0x167880 ldr r1, [r4, #0x8]
 *   @0x167884 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x167888 ldr r1, [r4, #0xc]
 *   @0x16788c mov r0, r5
 *   @0x167890 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x167894 mov r0, #32
 *   @0x167898 bl 0x27c524 <_Znwj>
 *   @0x16789c mov r1, #0
 *   @0x1678a0 mov r6, r0
 *   @0x1678a4 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x1678a8 ldr r3, [r4, #0x8]
 *   @0x1678ac mov r0, r6
 *   @0x1678b0 ldr r2, [r4, #0xc]
 *   @0x1678b4 ldr r1, [r4, #0x14]
 *   @0x1678b8 mul r2, r2, r3
 *   @0x1678bc lsl r2, r2, #2
 *   @0x1678c0 bl 0x201728 <_ZN7CStream11WriteBufferEPvi>
 *   @0x1678c4 mov r0, r5
 *   @0x1678c8 mov r1, r6
 *   @0x1678cc bl 0x2021fc <_ZN7CStream21WriteCompressedStreamEPS_>
 *   @0x1678d0 cmp r6, #0
 *   @0x1678d4 beq 0x167874 <_ZN9CBitmap3212SaveToStreamEP7CStream+0x30>
 *   @0x1678d8 mov r0, r6
 *   @0x1678dc bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x1678e0 mov r0, r6
 *   @0x1678e4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1678e8 mov r0, #1
 *   @0x1678ec pop {r4, r5, r6, pc}
 *
 * ══ §12/181 AddPerfBar(SVertex_Float*, float, float, unsigned int)  0x17bb50  size 172  43 条（0x17bb50..0x17bbfc）
 * @func 0x17bb50 0x17bbfc  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x60×1 / 0x78×1 / 0x84×1 / 0x18×1 / 0x30×1 / 0x48×1 / 0x6c×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17bb50 str r1, [r0]
 *   @0x17bb54 mov r12, #0
 *   @0x17bb58 str r1, [r0, #0x60]
 *   @0x17bb5c movt r12, #0x4120
 *   @0x17bb60 str r1, [r0, #0x78]
 *   @0x17bb64 mov r1, #0
 *   @0x17bb68 str r3, [r0, #0x84]
 *   @0x17bb6c movt r1, #0x41a0
 *   @0x17bb70 str r2, [r0, #0x18]
 *   @0x17bb74 str r2, [r0, #0x30]
 *   @0x17bb78 str r2, [r0, #0x48]
 *   @0x17bb7c mov r2, #0
 *   @0x17bb80 str r3, [r0, #0x6c]
 *   @0x17bb84 str r3, [r0, #0x54]
 *   @0x17bb88 str r3, [r0, #0x3c]
 *   @0x17bb8c str r3, [r0, #0x24]
 *   @0x17bb90 str r3, [r0, #0xc]
 *   @0x17bb94 mov r3, #1056964608
 *   @0x17bb98 str r2, [r0, #0x88]
 *   @0x17bb9c str r2, [r0, #0x70]
 *   @0x17bba0 str r2, [r0, #0x58]
 *   @0x17bba4 str r12, [r0, #0x4]
 *   @0x17bba8 str r12, [r0, #0x1c]
 *   @0x17bbac str r12, [r0, #0x7c]
 *   @0x17bbb0 str r2, [r0, #0x40]
 *   @0x17bbb4 str r2, [r0, #0x28]
 *   @0x17bbb8 str r2, [r0, #0x10]
 *   @0x17bbbc str r2, [r0, #0x8c]
 *   @0x17bbc0 str r2, [r0, #0x74]
 *   @0x17bbc4 str r2, [r0, #0x5c]
 *   @0x17bbc8 str r1, [r0, #0x34]
 *   @0x17bbcc str r1, [r0, #0x4c]
 *   @0x17bbd0 str r1, [r0, #0x64]
 *   @0x17bbd4 str r3, [r0, #0x80]
 *   @0x17bbd8 str r3, [r0, #0x68]
 *   @0x17bbdc str r3, [r0, #0x50]
 *   @0x17bbe0 str r3, [r0, #0x38]
 *   @0x17bbe4 str r3, [r0, #0x20]
 *   @0x17bbe8 str r3, [r0, #0x8]
 *   @0x17bbec str r2, [r0, #0x44]
 *   @0x17bbf0 str r2, [r0, #0x2c]
 *   @0x17bbf4 str r2, [r0, #0x14]
 *   @0x17bbf8 bx lr
 *
 * ══ §13/181 IO_String_Set(char const*)  0x18bdb4  size 172  43 条（0x18bdb4..0x18be60）
 * @func 0x18bdb4 0x18be60  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18bdd0→0x534ea8, 0x18be14→0x5346d4, 0x18be34→0x534ea8, 0x18be38→0x5346d4
 * 调用序列: utf8_strlen / IO_String_Set(char const*)+0x60 / utf8_extract_char
 * 字段偏移 top8: 0x1c×2 / 0x90×1 / 0x80×1 / 0x-4×1 / 0x2×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bdb4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18bdb8 subs r4, r0, #0
 *   @0x18bdbc ldr r8, [pc, #0x90]
 *   @0x18bdc0 sub sp, sp, #12
 *   @0x18bdc4 add r8, pc, r8
 *   @0x18bdc8 beq 0x18be34 <_Z13IO_String_SetPKc+0x80>
 *   @0x18bdcc bl 0x110648 <utf8_strlen>
 *   @0x18bdd0 ldr r3, [pc, #0x80]
 *   @0x18bdd4 subs r6, r0, #0
 *   @0x18bdd8 ldrle r9, [r8, r3]
 *   @0x18bddc ble 0x18be14 <_Z13IO_String_SetPKc+0x60>
 *   @0x18bde0 add r7, sp, #8
 *   @0x18bde4 cmp r6, #1024
 *   @0x18bde8 movge r6, #1024
 *   @0x18bdec str r4, [r7, #-0x4]!
 *   @0x18bdf0 mov r4, #0
 *   @0x18bdf4 ldr r9, [r8, r3]
 *   @0x18bdf8 sub r5, r9, #2
 *   @0x18bdfc mov r0, r7
 *   @0x18be00 add r4, r4, #1
 *   @0x18be04 bl 0x10fb38 <utf8_extract_char>
 *   @0x18be08 cmp r6, r4
 *   @0x18be0c strh r0, [r5, #2]!
 *   @0x18be10 bgt 0x18bdfc <_Z13IO_String_SetPKc+0x48>
 *   @0x18be14 ldr r3, [pc, #0x40]
 *   @0x18be18 lsl r2, r6, #1
 *   @0x18be1c mov r1, #0
 *   @0x18be20 strh r1, [r9, r2]
 *   @0x18be24 ldr r3, [r8, r3]
 *   @0x18be28 str r6, [r3]
 *   @0x18be2c add sp, sp, #12
 *   @0x18be30 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18be34 ldr r2, [pc, #0x1c]
 *   @0x18be38 ldr r3, [pc, #0x1c]
 *   @0x18be3c ldr r2, [r8, r2]
 *   @0x18be40 strh r4, [r2]
 *   @0x18be44 ldr r3, [r8, r3]
 *   @0x18be48 str r4, [r3]
 *   @0x18be4c add sp, sp, #12
 *   @0x18be50 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18be54 eoreq r5, r6, r12, lsl #29
 *   @0x18be58 .word 0xffffe984
 *   @0x18be5c .word 0xffffe9bc
 *
 * ══ §14/181 ComputeDir(float, float, float, float)  0x19c740  size 172  43 条（0x19c740..0x19c7ec）
 * @func 0x19c740 0x19c7ec  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ComputeDir(float, float, float, float)+0x40 / 0xb6778
 * 字段偏移 top8: 无
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19c740 vmov s12, r2
 *   @0x19c744 vmov s13, r0
 *   @0x19c748 push {r3, lr}
 *   @0x19c74c vsub.f32 s15, s12, s13
 *   @0x19c750 vmov s12, r3
 *   @0x19c754 vmov s13, r1
 *   @0x19c758 vcmp.f32 s15, #0
 *   @0x19c75c vsub.f32 s14, s12, s13
 *   @0x19c760 vmrs APSR_nzcv, fpscr
 *   @0x19c764 bne 0x19c790 <_Z10ComputeDirffff+0x50>
 *   @0x19c768 vcmpe.f32 s14, #0
 *   @0x19c76c vmrs APSR_nzcv, fpscr
 *   @0x19c770 ble 0x19c780 <_Z10ComputeDirffff+0x40>
 *   @0x19c774 vldr s15, [pc, #88]
 *   @0x19c778 vmov r0, s15
 *   @0x19c77c pop {r3, pc}
 *   @0x19c780 bmi 0x19c7cc <_Z10ComputeDirffff+0x8c>
 *   @0x19c784 vldr s15, [pc, #76]
 *   @0x19c788 vmov r0, s15
 *   @0x19c78c pop {r3, pc}
 *   @0x19c790 vmov r1, s15
 *   @0x19c794 vmov r0, s14
 *   @0x19c798 bl 0xb6778 <atan2f@plt>
 *   @0x19c79c vldr s15, [pc, #56]
 *   @0x19c7a0 vldr s14, [pc, #56]
 *   @0x19c7a4 vmov s12, r0
 *   @0x19c7a8 vmul.f32 s15, s12, s15
 *   @0x19c7ac vdiv.f32 s15, s15, s14
 *   @0x19c7b0 vcmpe.f32 s15, #0
 *   @0x19c7b4 vmrs APSR_nzcv, fpscr
 *   @0x19c7b8 vldrhi s14, [pc, #36]
 *   @0x19c7bc vsubhi.f32 s15, s14, s15
 *   @0x19c7c0 vnegls.f32 s15, s15
 *   @0x19c7c4 vmov r0, s15
 *   @0x19c7c8 pop {r3, pc}
 *   @0x19c7cc vldr s15, [pc, #20]
 *   @0x19c7d0 b 0x19c778 <_Z10ComputeDirffff+0x38>
 *   @0x19c7d4 orrmi r0, r7, #0
 *   @0x19c7d8 andeq r0, r0, r0
 *   @0x19c7dc teqmi r4, #0
 *   @0x19c7e0 ldrdmi r0, r1, [r9], #-251
 *   @0x19c7e4 .word 0x43b40000
 *   @0x19c7e8 adcsmi r0, r4, #0
 *
 * ══ §15/181 Object_Delete(int)  0x19f014  size 172  43 条（0x19f014..0x19f0c0）
 * @func 0x19f014 0x19f0c0  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CObjectGM::~CObjectGM() / operator delete(void*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×3 / 0x4×2 / 0xa0×1 / 0x3×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19f014 ldr r3, [pc, #0xa0]
 *   @0x19f018 push {r4, r5, r6, lr}
 *   @0x19f01c ldr r3, [pc, r3]
 *   @0x19f020 ldr r5, [r3]
 *   @0x19f024 ldr r1, [r5, #0x4]
 *   @0x19f028 ldr r2, [r5]
 *   @0x19f02c and r1, r0, r1
 *   @0x19f030 ldr r4, [r2, r1, lsl #3]
 *   @0x19f034 add r12, r2, r1, lsl #3
 *   @0x19f038 cmp r4, #0
 *   @0x19f03c bne 0x19f050 <_Z13Object_Deletei+0x3c>
 *   @0x19f040 b 0x19f0b4 <_Z13Object_Deletei+0xa0>
 *   @0x19f044 ldr r4, [r4, #0x4]
 *   @0x19f048 cmp r4, #0
 *   @0x19f04c beq 0x19f0b4 <_Z13Object_Deletei+0xa0>
 *   @0x19f050 ldr r3, [r4, #0x8]
 *   @0x19f054 cmp r0, r3
 *   @0x19f058 bne 0x19f044 <_Z13Object_Deletei+0x30>
 *   @0x19f05c ldr r3, [r4]
 *   @0x19f060 ldr r6, [r4, #0xc]
 *   @0x19f064 cmp r3, #0
 *   @0x19f068 ldrne r2, [r4, #0x4]
 *   @0x19f06c ldreq r0, [r4, #0x4]
 *   @0x19f070 strne r2, [r3, #0x4]
 *   @0x19f074 ldrne r0, [r4, #0x4]
 *   @0x19f078 streq r0, [r2, r1, lsl #3]
 *   @0x19f07c cmp r0, #0
 *   @0x19f080 streq r3, [r12, #0x4]
 *   @0x19f084 strne r3, [r0]
 *   @0x19f088 cmp r6, #0
 *   @0x19f08c beq 0x19f0a0 <_Z13Object_Deletei+0x8c>
 *   @0x19f090 mov r0, r6
 *   @0x19f094 bl 0x19d558 <_ZN9CObjectGMD2Ev>
 *   @0x19f098 mov r0, r6
 *   @0x19f09c bl 0x27d1d0 <_ZdlPv>
 *   @0x19f0a0 mov r0, r4
 *   @0x19f0a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19f0a8 ldr r3, [r5, #0x8]
 *   @0x19f0ac sub r3, r3, #1
 *   @0x19f0b0 str r3, [r5, #0x8]
 *   @0x19f0b4 mov r0, #1
 *   @0x19f0b8 pop {r4, r5, r6, pc}
 *   @0x19f0bc eoreq lr, r4, r0, lsr #24
 *
 * ══ §16/181 TBitmap::FromBitmap(IBitmap*)  0x1a9080  size 172  43 条（0x1a9080..0x1a912c）
 * @func 0x1a9080 0x1a912c  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / TBitmap::Setup()
 * 字段偏移 top8: 0x10×5 / 0x4×4 / 0x18×2 / 0x28×2 / 0x30×1 / 0x1c×1 / 0x48×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a9080 push {r3, r4, r5, lr}
 *   @0x1a9084 mov r5, r1
 *   @0x1a9088 ldr r3, [r0]
 *   @0x1a908c mov r4, r0
 *   @0x1a9090 ldr r3, [r3, #0x30]
 *   @0x1a9094 blx r3
 *   @0x1a9098 ldr r3, [r5]
 *   @0x1a909c mov r0, r5
 *   @0x1a90a0 ldr r3, [r3, #0x10]
 *   @0x1a90a4 blx r3
 *   @0x1a90a8 ldr r3, [r5]
 *   @0x1a90ac ldr r3, [r3, #0x18]
 *   @0x1a90b0 str r0, [r4, #0x18]
 *   @0x1a90b4 mov r0, r5
 *   @0x1a90b8 blx r3
 *   @0x1a90bc ldr r3, [r5, #0x4]
 *   @0x1a90c0 cmp r3, #0
 *   @0x1a90c4 streq r3, [r4, #0x4]
 *   @0x1a90c8 str r0, [r4, #0x1c]
 *   @0x1a90cc beq 0x1a9118 <_ZN7TBitmap10FromBitmapEP7IBitmap+0x98>
 *   @0x1a90d0 ldr r0, [r5, #0x10]
 *   @0x1a90d4 mov r3, #1
 *   @0x1a90d8 ldr r1, [pc, #0x48]
 *   @0x1a90dc movw r2, #0x116
 *   @0x1a90e0 add r1, pc, r1
 *   @0x1a90e4 str r0, [r4, #0x10]
 *   @0x1a90e8 ldr r0, [r5, #0x10]
 *   @0x1a90ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1a90f0 str r0, [r4, #0x4]
 *   @0x1a90f4 ldr r2, [r5, #0x10]
 *   @0x1a90f8 ldr r1, [r5, #0x4]
 *   @0x1a90fc bl 0xb65bc <memcpy@plt>
 *   @0x1a9100 ldr r3, [r4, #0x4]
 *   @0x1a9104 mov r0, r4
 *   @0x1a9108 ldr r2, [r3, #0x8]
 *   @0x1a910c add r3, r3, r2
 *   @0x1a9110 str r3, [r4, #0xc]
 *   @0x1a9114 bl 0x1a8d14 <_ZN7TBitmap5SetupEv>
 *   @0x1a9118 ldr r3, [r4, #0x28]
 *   @0x1a911c add r3, r3, #1
 *   @0x1a9120 str r3, [r4, #0x28]
 *   @0x1a9124 pop {r3, r4, r5, pc}
 *   @0x1a9128 mulseq r10, r4, r0
 *
 * ══ §17/181 BitmapLoader::BitmapLoader(void*, int, int)  0x1a916c  size 172  43 条（0x1a916c..0x1a9218）
 * @func 0x1a916c 0x1a9218  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc
 * 字段偏移 top8: 0x8×3 / 0x90×2 / 0xc×2 / 0x10×2 / 0x4×1 / 0x14×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a916c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a9170 mov r10, r1
 *   @0x1a9174 mul r9, r3, r2
 *   @0x1a9178 ldr r12, [pc, #0x90]
 *   @0x1a917c ldr r1, [pc, #0x90]
 *   @0x1a9180 mov r4, r0
 *   @0x1a9184 mov r5, #0
 *   @0x1a9188 ldr r12, [pc, r12]
 *   @0x1a918c str r5, [r0, #0xc]
 *   @0x1a9190 mov r6, #1
 *   @0x1a9194 str r5, [r0, #0x8]
 *   @0x1a9198 mov r8, r2
 *   @0x1a919c lsl r9, r9, #2
 *   @0x1a91a0 mov r7, r3
 *   @0x1a91a4 add r12, r12, #8
 *   @0x1a91a8 mov r3, r5
 *   @0x1a91ac str r12, [r0]
 *   @0x1a91b0 add r1, pc, r1
 *   @0x1a91b4 add r0, r9, #52
 *   @0x1a91b8 str r6, [r4, #0x10]
 *   @0x1a91bc movw r2, #0x169
 *   @0x1a91c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1a91c4 mov r3, #52
 *   @0x1a91c8 mov lr, #32
 *   @0x1a91cc mov r2, r9
 *   @0x1a91d0 mov r1, r10
 *   @0x1a91d4 mov r12, r0
 *   @0x1a91d8 str r0, [r4, #0x4]
 *   @0x1a91dc str r8, [r0, #0x10]
 *   @0x1a91e0 str r7, [r0, #0x14]
 *   @0x1a91e4 mov r0, #40
 *   @0x1a91e8 str r5, [r12, #0x1c]
 *   @0x1a91ec str r0, [r12, #0xc]
 *   @0x1a91f0 add r0, r12, r3
 *   @0x1a91f4 strh r6, [r12, #24]
 *   @0x1a91f8 strh lr, [r12, #26]
 *   @0x1a91fc str r3, [r12, #0x8]
 *   @0x1a9200 bl 0xb65bc <memcpy@plt>
 *   @0x1a9204 str r6, [r4, #0x8]
 *   @0x1a9208 mov r0, r4
 *   @0x1a920c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1a9210 eoreq r7, r4, r12, ror r6
 *   @0x1a9214 andseq r3, r10, r4, asr #31
 *
 * ══ §18/181 Room_Assign(int, int)  0x1b5af4  size 172  43 条（0x1b5af4..0x1b5ba0）
 * @func 0x1b5af4 0x1b5ba0  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_Data(int)×2 / operator new(unsigned int) / CRoom::CRoom() / Room_Assign(int, int)+0x8c / CRoom::Assign(CRoom*, bool)
 * 字段偏移 top8: 0x4×3 / 0x2×3 / 0x64×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5af4 push {r4, r5, r6, lr}
 *   @0x1b5af8 mov r5, r1
 *   @0x1b5afc mov r4, r0
 *   @0x1b5b00 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x1b5b04 cmp r0, #0
 *   @0x1b5b08 beq 0x1b5b78 <_Z11Room_Assignii+0x84>
 *   @0x1b5b0c mov r0, r5
 *   @0x1b5b10 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x1b5b14 cmp r0, #0
 *   @0x1b5b18 beq 0x1b5b78 <_Z11Room_Assignii+0x84>
 *   @0x1b5b1c mov r0, #292
 *   @0x1b5b20 bl 0x27c524 <_Znwj>
 *   @0x1b5b24 mov r6, r0
 *   @0x1b5b28 bl 0x1ad2cc <_ZN5CRoomC2Ev>
 *   @0x1b5b2c ldr r3, [pc, #0x64]
 *   @0x1b5b30 add r3, pc, r3
 *   @0x1b5b34 ldr r2, [r3]
 *   @0x1b5b38 ldr r1, [r3, #0x4]
 *   @0x1b5b3c cmp r4, r2
 *   @0x1b5b40 str r6, [r1, r4, lsl #2]
 *   @0x1b5b44 movge r0, #0
 *   @0x1b5b48 blt 0x1b5b80 <_Z11Room_Assignii+0x8c>
 *   @0x1b5b4c cmp r5, r2
 *   @0x1b5b50 movge r1, #0
 *   @0x1b5b54 bge 0x1b5b68 <_Z11Room_Assignii+0x74>
 *   @0x1b5b58 ldr r3, [pc, #0x3c]
 *   @0x1b5b5c add r3, pc, r3
 *   @0x1b5b60 ldr r3, [r3, #0x4]
 *   @0x1b5b64 ldr r1, [r3, r5, lsl #2]
 *   @0x1b5b68 mov r2, #1
 *   @0x1b5b6c bl 0x1ad70c <_ZN5CRoom6AssignEPS_b>
 *   @0x1b5b70 mov r0, #1
 *   @0x1b5b74 pop {r4, r5, r6, pc}
 *   @0x1b5b78 mov r0, #0
 *   @0x1b5b7c pop {r4, r5, r6, pc}
 *   @0x1b5b80 ldr r3, [r3, #0x4]
 *   @0x1b5b84 cmp r5, r2
 *   @0x1b5b88 movge r1, #0
 *   @0x1b5b8c ldr r0, [r3, r4, lsl #2]
 *   @0x1b5b90 bge 0x1b5b68 <_Z11Room_Assignii+0x74>
 *   @0x1b5b94 b 0x1b5b58 <_Z11Room_Assignii+0x64>
 *   @0x1b5b98 mlaseq r8, r8, r10, r12
 *   @0x1b5b9c eorseq r12, r8, r12, ror #20
 *
 * ══ §19/181 F_LayerBackgroundGetXscale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bcd5c  size 172  43 条（0x1bcd5c..0x1bce08）
 * @func 0x1bcd5c 0x1bce08  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x74×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bcd5c cmp r3, #1
 *   @0x1bcd60 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bcd64 mov r3, #0
 *   @0x1bcd68 mov r5, r3
 *   @0x1bcd6c mov r4, r0
 *   @0x1bcd70 movt r3, #0xbff0
 *   @0x1bcd74 str r5, [r0, #0xc]
 *   @0x1bcd78 str r3, [r0, #0x4]
 *   @0x1bcd7c str r5, [r0]
 *   @0x1bcd80 ldr r6, [sp, #0x18]
 *   @0x1bcd84 beq 0x1bcd9c <_Z26F_LayerBackgroundGetXscaleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bcd88 ldr r0, [pc, #0x74]
 *   @0x1bcd8c mov r1, r5
 *   @0x1bcd90 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bcd94 add r0, pc, r0
 *   @0x1bcd98 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bcd9c str r5, [r0]
 *   @0x1bcda0 mov r3, #0
 *   @0x1bcda4 movt r3, #0x3ff0
 *   @0x1bcda8 str r3, [r0, #0x4]
 *   @0x1bcdac bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bcdb0 mov r1, r5
 *   @0x1bcdb4 mov r7, r0
 *   @0x1bcdb8 mov r0, r6
 *   @0x1bcdbc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bcdc0 mov r2, r5
 *   @0x1bcdc4 mov r1, r0
 *   @0x1bcdc8 mov r0, r7
 *   @0x1bcdcc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bcdd0 cmp r0, #0
 *   @0x1bcdd4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcdd8 ldr r3, [r0]
 *   @0x1bcddc cmp r3, #1
 *   @0x1bcde0 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bcde4 ldr r3, [r0, #0x1c]
 *   @0x1bcde8 cmp r3, #0
 *   @0x1bcdec popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcdf0 vldr s15, [r3, #12]
 *   @0x1bcdf4 vcvt.f64.f32 d6, s15
 *   @0x1bcdf8 vmov r2, r3, d6
 *   @0x1bcdfc stm r4, {r2, r3}
 *   @0x1bce00 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bce04 andseq r1, r9, r4, asr r4
 *
 * ══ §20/181 F_LayerBackgroundGetYscale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bce08  size 172  43 条（0x1bce08..0x1bceb4）
 * @func 0x1bce08 0x1bceb4  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x74×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bce08 cmp r3, #1
 *   @0x1bce0c push {r3, r4, r5, r6, r7, lr}
 *   @0x1bce10 mov r3, #0
 *   @0x1bce14 mov r5, r3
 *   @0x1bce18 mov r4, r0
 *   @0x1bce1c movt r3, #0xbff0
 *   @0x1bce20 str r5, [r0, #0xc]
 *   @0x1bce24 str r3, [r0, #0x4]
 *   @0x1bce28 str r5, [r0]
 *   @0x1bce2c ldr r6, [sp, #0x18]
 *   @0x1bce30 beq 0x1bce48 <_Z26F_LayerBackgroundGetYscaleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bce34 ldr r0, [pc, #0x74]
 *   @0x1bce38 mov r1, r5
 *   @0x1bce3c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bce40 add r0, pc, r0
 *   @0x1bce44 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bce48 str r5, [r0]
 *   @0x1bce4c mov r3, #0
 *   @0x1bce50 movt r3, #0x3ff0
 *   @0x1bce54 str r3, [r0, #0x4]
 *   @0x1bce58 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bce5c mov r1, r5
 *   @0x1bce60 mov r7, r0
 *   @0x1bce64 mov r0, r6
 *   @0x1bce68 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bce6c mov r2, r5
 *   @0x1bce70 mov r1, r0
 *   @0x1bce74 mov r0, r7
 *   @0x1bce78 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bce7c cmp r0, #0
 *   @0x1bce80 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bce84 ldr r3, [r0]
 *   @0x1bce88 cmp r3, #1
 *   @0x1bce8c popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bce90 ldr r3, [r0, #0x1c]
 *   @0x1bce94 cmp r3, #0
 *   @0x1bce98 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bce9c vldr s15, [r3, #16]
 *   @0x1bcea0 vcvt.f64.f32 d6, s15
 *   @0x1bcea4 vmov r2, r3, d6
 *   @0x1bcea8 stm r4, {r2, r3}
 *   @0x1bceac pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bceb0 andseq r1, r9, r4, ror #7
 *
 * ══ §21/181 F_Shader_Set_Texture(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e11a8  size 172  43 条（0x1e11a8..0x1e1254）
 * @func 0x1e11a8 0x1e1254  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int)×2 / YYGetInt32(RValue const*, int)×2 / YYGetPtrOrInt(RValue const*, int) / Graphics::Flush()
 * 字段偏移 top8: 0x10×1 / 0x68×1 / 0x4×1 / 0x2×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e11a8 push {r4, r5, r6, lr}
 *   @0x1e11ac mov r1, #1
 *   @0x1e11b0 ldr r6, [sp, #0x10]
 *   @0x1e11b4 mov r0, r6
 *   @0x1e11b8 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x1e11bc mov r4, r0
 *   @0x1e11c0 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1e11c4 mov r0, r4
 *   @0x1e11c8 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x1e11cc cmp r0, #0
 *   @0x1e11d0 bne 0x1e1240 <_Z20F_Shader_Set_TextureR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1e11d4 cmn r4, #1
 *   @0x1e11d8 beq 0x1e11f0 <_Z20F_Shader_Set_TextureR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1e11dc ldr r5, [pc, #0x68]
 *   @0x1e11e0 ldr r5, [pc, r5]
 *   @0x1e11e4 ldr r3, [r5]
 *   @0x1e11e8 cmp r4, r3
 *   @0x1e11ec bhs 0x1e1208 <_Z20F_Shader_Set_TextureR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x1e11f0 mov r0, r6
 *   @0x1e11f4 mov r1, #0
 *   @0x1e11f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e11fc mov r1, #0
 *   @0x1e1200 pop {r4, r5, r6, lr}
 *   @0x1e1204 b 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x1e1208 ldrsh r4, [r4, #20]
 *   @0x1e120c mov r0, r4
 *   @0x1e1210 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x1e1214 cmp r0, #0
 *   @0x1e1218 popeq {r4, r5, r6, pc}
 *   @0x1e121c ldr r3, [r5, #0x4]
 *   @0x1e1220 mov r0, r6
 *   @0x1e1224 mov r1, #0
 *   @0x1e1228 ldr r3, [r3, r4, lsl #2]
 *   @0x1e122c ldr r4, [r3]
 *   @0x1e1230 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e1234 mov r1, r4
 *   @0x1e1238 pop {r4, r5, r6, lr}
 *   @0x1e123c b 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x1e1240 ldr r5, [pc, #0x8]
 *   @0x1e1244 ldr r5, [pc, r5]
 *   @0x1e1248 b 0x1e121c <_Z20F_Shader_Set_TextureR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1e124c eoreq r12, r0, r12, lsr r7
 *   @0x1e1250 .word 0x0020c6d8
 *
 * ══ §22/181 CSprite::InitTexture()  0x1e5748  size 172  43 条（0x1e5748..0x1e57f4）
 * @func 0x1e5748 0x1e57f4  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::FreeTexture() / MemoryManager::SetLength(void**, unsigned int, char const*, int) / GR_Texture_Create_Direct(CBitmap32*) / GR_Texture_Preload(int) / CSprite::InitTexture()+0x68
 * 字段偏移 top8: 0x18×4 / 0x2×3 / 0x50×2 / 0x54×1 / 0x36×1 / 0x74×1 / 0x4c×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e5748 push {r4, r5, r6, lr}
 *   @0x1e574c mov r5, r0
 *   @0x1e5750 bl 0x1e56fc <_ZN7CSprite11FreeTextureEv>
 *   @0x1e5754 ldr r3, [r5, #0x54]
 *   @0x1e5758 cmp r3, #0
 *   @0x1e575c beq 0x1e576c <_ZN7CSprite11InitTextureEv+0x24>
 *   @0x1e5760 ldrb r3, [r5, #0x36]
 *   @0x1e5764 cmp r3, #0
 *   @0x1e5768 popeq {r4, r5, r6, pc}
 *   @0x1e576c ldr r1, [r5, #0x18]
 *   @0x1e5770 movw r3, #0x705
 *   @0x1e5774 ldr r2, [pc, #0x74]
 *   @0x1e5778 add r0, r5, #80
 *   @0x1e577c add r2, pc, r2
 *   @0x1e5780 lsl r1, r1, #2
 *   @0x1e5784 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e5788 ldr r3, [r5, #0x18]
 *   @0x1e578c cmp r3, #0
 *   @0x1e5790 str r3, [r5, #0x4c]
 *   @0x1e5794 pople {r4, r5, r6, pc}
 *   @0x1e5798 mov r4, #0
 *   @0x1e579c b 0x1e57b0 <_ZN7CSprite11InitTextureEv+0x68>
 *   @0x1e57a0 ldr r3, [r5, #0x18]
 *   @0x1e57a4 add r4, r4, #1
 *   @0x1e57a8 cmp r4, r3
 *   @0x1e57ac bge 0x1e57ec <_ZN7CSprite11InitTextureEv+0xa4>
 *   @0x1e57b0 ldr r3, [r5, #0x48]
 *   @0x1e57b4 ldr r6, [r5, #0x50]
 *   @0x1e57b8 ldr r0, [r3, r4, lsl #2]
 *   @0x1e57bc bl 0x173e70 <_Z24GR_Texture_Create_DirectP9CBitmap32>
 *   @0x1e57c0 ldrb r3, [r5, #0x34]
 *   @0x1e57c4 cmp r3, #0
 *   @0x1e57c8 str r0, [r6, r4, lsl #2]
 *   @0x1e57cc beq 0x1e57a0 <_ZN7CSprite11InitTextureEv+0x58>
 *   @0x1e57d0 ldr r3, [r5, #0x50]
 *   @0x1e57d4 ldr r0, [r3, r4, lsl #2]
 *   @0x1e57d8 add r4, r4, #1
 *   @0x1e57dc bl 0x174288 <_Z18GR_Texture_Preloadi>
 *   @0x1e57e0 ldr r3, [r5, #0x18]
 *   @0x1e57e4 cmp r4, r3
 *   @0x1e57e8 blt 0x1e57b0 <_ZN7CSprite11InitTextureEv+0x68>
 *   @0x1e57ec pop {r4, r5, r6, pc}
 *   @0x1e57f0 andseq r12, r6, r8, lsr #25
 *
 * ══ §23/181 CPhysicsDebugRender::DrawTransform(b2Transform const&)  0x23c1c8  size 172  43 条（0x23c1c8..0x23c274）
 * @func 0x23c1c8 0x23c274  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_draw_set_colour(unsigned int)×2 / GR_Draw_Line(float, float, float, float)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 32 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c1c8 push {r4, lr}
 *   @0x23c1cc vpush {d8, d9, d10, d11}
 *   @0x23c1d0 vmov.f32 s16, #1.000000e+00
 *   @0x23c1d4 vldr s19, [r1]
 *   @0x23c1d8 ldr r3, [r0, #0x8]
 *   @0x23c1dc vldr s13, [r3, #96]
 *   @0x23c1e0 vldr s18, [r1, #4]
 *   @0x23c1e4 vldr s17, [pc, #132]
 *   @0x23c1e8 vldr s14, [r1, #12]
 *   @0x23c1ec vldr s15, [r1, #8]
 *   @0x23c1f0 mov r0, #255
 *   @0x23c1f4 mov r4, r1
 *   @0x23c1f8 vdiv.f32 s16, s16, s13
 *   @0x23c1fc vmov.f32 s23, s19
 *   @0x23c200 vmov.f32 s22, s18
 *   @0x23c204 vmla.f32 s23, s14, s17
 *   @0x23c208 vmla.f32 s22, s15, s17
 *   @0x23c20c bl 0x169d98 <_Z21YYGML_draw_set_colourj>
 *   @0x23c210 vmul.f32 s21, s16, s19
 *   @0x23c214 vmul.f32 s20, s16, s18
 *   @0x23c218 vmov r0, s21
 *   @0x23c21c vmul.f32 s23, s16, s23
 *   @0x23c220 vmov r1, s20
 *   @0x23c224 vmul.f32 s22, s16, s22
 *   @0x23c228 vmov r2, s23
 *   @0x23c22c vmov r3, s22
 *   @0x23c230 bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x23c234 vldr s14, [r4, #8]
 *   @0x23c238 vldr s15, [r4, #12]
 *   @0x23c23c vmls.f32 s19, s14, s17
 *   @0x23c240 mov r0, #16711680
 *   @0x23c244 vmla.f32 s18, s15, s17
 *   @0x23c248 bl 0x169d98 <_Z21YYGML_draw_set_colourj>
 *   @0x23c24c vmov r0, s21
 *   @0x23c250 vmov r1, s20
 *   @0x23c254 vmul.f32 s19, s16, s19
 *   @0x23c258 vmul.f32 s18, s16, s18
 *   @0x23c25c vmov r2, s19
 *   @0x23c260 vmov r3, s18
 *   @0x23c264 vpop {d8, d9, d10, d11}
 *   @0x23c268 pop {r4, lr}
 *   @0x23c26c b 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x23c270 cdplo p12, #0xc, c12, c12, c13, #0x6
 *
 * ══ §24/181 JS_Boolean_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*)  0x252be8  size 172  43 条（0x252be8..0x252c94）
 * @func 0x252be8 0x252c94  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574 / YYObjectBase::FindValue(char const*)
 * 字段偏移 top8: 0x84×1 / 0x40×1 / 0x6c×1 / 0x44×1 / 0x34×1 / 0x24×1 / 0x18×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252be8 push {r3, r4, r5, lr}
 *   @0x252bec mov r4, r1
 *   @0x252bf0 ldr r1, [pc, #0x84]
 *   @0x252bf4 mov r5, r0
 *   @0x252bf8 ldr r0, [r4, #0x40]
 *   @0x252bfc add r1, pc, r1
 *   @0x252c00 bl 0xb6574 <strcmp@plt>
 *   @0x252c04 cmp r0, #0
 *   @0x252c08 bne 0x252c60 <_Z29JS_Boolean_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x252c0c ldr r1, [pc, #0x6c]
 *   @0x252c10 mov r0, r4
 *   @0x252c14 add r1, pc, r1
 *   @0x252c18 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x252c1c cmp r0, #0
 *   @0x252c20 beq 0x252c70 <_Z29JS_Boolean_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x252c24 ldm r0, {r2, r3}
 *   @0x252c28 vmov d7, r2, r3
 *   @0x252c2c vcmp.f64 d7, #0
 *   @0x252c30 vmrs APSR_nzcv, fpscr
 *   @0x252c34 bne 0x252c4c <_Z29JS_Boolean_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x252c38 ldr r1, [pc, #0x44]
 *   @0x252c3c add r1, pc, r1
 *   @0x252c40 mov r0, r5
 *   @0x252c44 pop {r3, r4, r5, lr}
 *   @0x252c48 b 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x252c4c ldr r1, [pc, #0x34]
 *   @0x252c50 mov r0, r5
 *   @0x252c54 pop {r3, r4, r5, lr}
 *   @0x252c58 add r1, pc, r1
 *   @0x252c5c b 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x252c60 ldr r0, [pc, #0x24]
 *   @0x252c64 pop {r3, r4, r5, lr}
 *   @0x252c68 add r0, pc, r0
 *   @0x252c6c b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252c70 ldr r1, [pc, #0x18]
 *   @0x252c74 add r1, pc, r1
 *   @0x252c78 b 0x252c40 <_Z29JS_Boolean_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x252c7c andseq r2, r0, r12, lsl #18
 *   @0x252c80 ldrsheq r2, [r0], -r12
 *   @0x252c84 andeq r1, lr, r12, ror #27
 *   @0x252c88 andeq r1, lr, r8, asr #27
 *   @0x252c8c andseq r3, r0, r0, lsl r9
 *   @0x252c90 ldrsheq r3, [r0], -r4
 *
 * ══ §25/181 F_JS_Object_create(RValue&, CInstance*, CInstance*, int, RValue*)  0x25337c  size 172  43 条（0x25337c..0x253428）
 * @func 0x25337c 0x253428  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) / F_JS_Object_create(RValue&, CInstance*, CInstance*, int, RValue*)+0xa0
 * 字段偏移 top8: 0x20×2 / 0xc×1 / 0x64×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25337c push {r4, r5, r6, r7, r8, lr}
 *   @0x253380 subs r8, r3, #0
 *   @0x253384 sub sp, sp, #8
 *   @0x253388 mov r6, r1
 *   @0x25338c mov r7, r2
 *   @0x253390 mov r5, r0
 *   @0x253394 ldr r4, [sp, #0x20]
 *   @0x253398 beq 0x2533b8 <_Z18F_JS_Object_createR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x25339c ldr r12, [r4, #0xc]
 *   @0x2533a0 bic r12, r12, #-16777216
 *   @0x2533a4 cmp r12, #12
 *   @0x2533a8 cmpne r12, #6
 *   @0x2533ac moveq r12, #0
 *   @0x2533b0 movne r12, #1
 *   @0x2533b4 beq 0x2533cc <_Z18F_JS_Object_createR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x2533b8 ldr r0, [pc, #0x64]
 *   @0x2533bc add r0, pc, r0
 *   @0x2533c0 add sp, sp, #8
 *   @0x2533c4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x2533c8 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2533cc mov r1, r12
 *   @0x2533d0 mov r3, r12
 *   @0x2533d4 str r12, [sp]
 *   @0x2533d8 mov r2, r12
 *   @0x2533dc bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x2533e0 ldr r3, [r5]
 *   @0x2533e4 ldr r1, [r4]
 *   @0x2533e8 mov r0, r3
 *   @0x2533ec str r1, [r3, #0x18]
 *   @0x2533f0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2533f4 cmp r8, #1
 *   @0x2533f8 ble 0x25341c <_Z18F_JS_Object_createR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x2533fc str r4, [sp, #0x20]
 *   @0x253400 mov r0, r5
 *   @0x253404 mov r1, r6
 *   @0x253408 mov r2, r7
 *   @0x25340c mov r3, #2
 *   @0x253410 add sp, sp, #8
 *   @0x253414 pop {r4, r5, r6, r7, r8, lr}
 *   @0x253418 b 0x252db4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_>
 *   @0x25341c add sp, sp, #8
 *   @0x253420 pop {r4, r5, r6, r7, r8, pc}
 *   @0x253424 andseq r2, r0, r12, lsl #23
 *
 * ══ §26/181 Java_com_yoyogames_runner_RunnerJNILib_GetSaveFileName  0x292968  size 172  43 条（0x292968..0x292a14）
 * @func 0x292968 0x292a14  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / LoadSave::_GetSaveFileName(char*, int, char const*) / 0xb65d4
 * 字段偏移 top8: 0x204×2 / 0x98×1 / 0x2a4×1 / 0x2a8×1 / 0x29c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292968 push {r4, r5, r6, r7, r8, lr}
 *   @0x29296c sub sp, sp, #520
 *   @0x292970 ldr r5, [pc, #0x98]
 *   @0x292974 mov r4, r0
 *   @0x292978 mov r6, r2
 *   @0x29297c add r8, sp, #4
 *   @0x292980 ldr r5, [pc, r5]
 *   @0x292984 ldr r3, [r5]
 *   @0x292988 str r3, [sp, #0x204]
 *   @0x29298c bl 0x290614 <setJNIEnv>
 *   @0x292990 ldr r3, [r4]
 *   @0x292994 mov r1, r6
 *   @0x292998 mov r2, #0
 *   @0x29299c mov r0, r4
 *   @0x2929a0 ldr r3, [r3, #0x2a4]
 *   @0x2929a4 blx r3
 *   @0x2929a8 movw r1, #0x1ff
 *   @0x2929ac mov r7, r0
 *   @0x2929b0 mov r2, r0
 *   @0x2929b4 mov r0, r8
 *   @0x2929b8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x2929bc cmp r7, #0
 *   @0x2929c0 cmpne r6, #0
 *   @0x2929c4 beq 0x2929e0 <Java_com_yoyogames_runner_RunnerJNILib_GetSaveFileName+0x78>
 *   @0x2929c8 ldr r3, [r4]
 *   @0x2929cc mov r1, r6
 *   @0x2929d0 mov r2, r7
 *   @0x2929d4 mov r0, r4
 *   @0x2929d8 ldr r3, [r3, #0x2a8]
 *   @0x2929dc blx r3
 *   @0x2929e0 ldr r3, [r4]
 *   @0x2929e4 mov r1, r8
 *   @0x2929e8 mov r0, r4
 *   @0x2929ec ldr r3, [r3, #0x29c]
 *   @0x2929f0 blx r3
 *   @0x2929f4 ldr r2, [sp, #0x204]
 *   @0x2929f8 ldr r3, [r5]
 *   @0x2929fc cmp r2, r3
 *   @0x292a00 bne 0x292a0c <Java_com_yoyogames_runner_RunnerJNILib_GetSaveFileName+0xa4>
 *   @0x292a04 add sp, sp, #520
 *   @0x292a08 pop {r4, r5, r6, r7, r8, pc}
 *   @0x292a0c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x292a10 ldrsbeq r10, [r5], -r0
 *
 * ══ §27/181 F_NETWORK_Set_Timeout(RValue&, CInstance*, CInstance*, int, RValue*)  0x2980cc  size 172  43 条（0x2980cc..0x298178）
 * @func 0x2980cc 0x298178  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / yySocket::SetTimeout(int, int)
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0xc×1 / 0x48×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2980cc push {r3, r4, r5, r6, r7, lr}
 *   @0x2980d0 mov r3, #0
 *   @0x2980d4 ldr r5, [sp, #0x18]
 *   @0x2980d8 mov r1, r3
 *   @0x2980dc str r3, [r0, #0xc]
 *   @0x2980e0 mov r4, r0
 *   @0x2980e4 str r3, [r0]
 *   @0x2980e8 str r3, [r0, #0x4]
 *   @0x2980ec mov r0, r5
 *   @0x2980f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x2980f4 mov r1, #1
 *   @0x2980f8 mov r6, r0
 *   @0x2980fc mov r0, r5
 *   @0x298100 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298104 mov r1, #2
 *   @0x298108 mov r7, r0
 *   @0x29810c mov r0, r5
 *   @0x298110 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298114 cmp r6, #63
 *   @0x298118 mov r2, r0
 *   @0x29811c pophi {r3, r4, r5, r6, r7, pc}
 *   @0x298120 add r6, r6, r6, lsl #1
 *   @0x298124 ldr r3, [pc, #0x48]
 *   @0x298128 lsl r6, r6, #2
 *   @0x29812c ldr r3, [pc, r3]
 *   @0x298130 add r1, r3, r6
 *   @0x298134 ldrb r3, [r3, r6]
 *   @0x298138 cmp r3, #0
 *   @0x29813c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x298140 ldr r0, [r1, #0x4]
 *   @0x298144 cmp r0, #0
 *   @0x298148 ldreq r3, [r1, #0x8]
 *   @0x29814c mov r1, r7
 *   @0x298150 ldreq r0, [r3]
 *   @0x298154 bl 0x294ed4 <_ZN8yySocket10SetTimeoutEii>
 *   @0x298158 vmov s15, r0
 *   @0x29815c vcvt.f64.s32 d7, s15
 *   @0x298160 vmov r0, r1, d7
 *   @0x298164 vmov r2, s14
 *   @0x298168 mov r3, r1
 *   @0x29816c stm r4, {r2, r3}
 *   @0x298170 pop {r3, r4, r5, r6, r7, pc}
 *   @0x298174 andseq r9, r5, r8, ror r8
 *
 * ══ §28/181 jpeg_finish_output  0x2b37f0  size 172  43 条（0x2b37f0..0x2b389c）
 * @func 0x2b37f0 0x2b389c  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_finish_output+0x88 / jpeg_finish_output+0x44
 * 字段偏移 top8: 0x14×4 / 0x18×1 / 0x190×1 / 0x11×1 / 0x7c×1 / 0x84×1 / 0x40×1 / 0x180×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b37f0 ldr r3, [r0, #0x14]
 *   @0x2b37f4 push {r4, lr}
 *   @0x2b37f8 sub r2, r3, #205
 *   @0x2b37fc cmp r2, #1
 *   @0x2b3800 mov r4, r0
 *   @0x2b3804 bls 0x2b3878 <jpeg_finish_output+0x88>
 *   @0x2b3808 cmp r3, #208
 *   @0x2b380c beq 0x2b3854 <jpeg_finish_output+0x64>
 *   @0x2b3810 ldr r2, [r4]
 *   @0x2b3814 mov r1, #20
 *   @0x2b3818 mov r0, r4
 *   @0x2b381c str r3, [r2, #0x18]
 *   @0x2b3820 ldr r3, [r4]
 *   @0x2b3824 str r1, [r2, #0x14]
 *   @0x2b3828 ldr r3, [r3]
 *   @0x2b382c blx r3
 *   @0x2b3830 b 0x2b3854 <jpeg_finish_output+0x64>
 *   @0x2b3834 ldr r3, [r4, #0x190]
 *   @0x2b3838 ldrb r2, [r3, #0x11]
 *   @0x2b383c cmp r2, #0
 *   @0x2b3840 bne 0x2b3868 <jpeg_finish_output+0x78>
 *   @0x2b3844 ldr r3, [r3]
 *   @0x2b3848 blx r3
 *   @0x2b384c cmp r0, #0
 *   @0x2b3850 popeq {r4, pc}
 *   @0x2b3854 ldr r2, [r4, #0x7c]
 *   @0x2b3858 mov r0, r4
 *   @0x2b385c ldr r3, [r4, #0x84]
 *   @0x2b3860 cmp r2, r3
 *   @0x2b3864 ble 0x2b3834 <jpeg_finish_output+0x44>
 *   @0x2b3868 mov r3, #207
 *   @0x2b386c mov r0, #1
 *   @0x2b3870 str r3, [r4, #0x14]
 *   @0x2b3874 pop {r4, pc}
 *   @0x2b3878 ldrb r2, [r0, #0x40]
 *   @0x2b387c cmp r2, #0
 *   @0x2b3880 beq 0x2b3810 <jpeg_finish_output+0x20>
 *   @0x2b3884 ldr r3, [r0, #0x180]
 *   @0x2b3888 ldr r3, [r3, #0x4]
 *   @0x2b388c blx r3
 *   @0x2b3890 mov r3, #208
 *   @0x2b3894 str r3, [r4, #0x14]
 *   @0x2b3898 b 0x2b3854 <jpeg_finish_output+0x64>
 *
 * ══ §29/181 png_get_cHRM  0x2a6734  size 170  43 条（0x2a6734..0x2a67de）
 * @func 0x2a6734 0x2a67de  size 170  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x4967a4
 * 字段偏移 top8: 0x20×1 / 0x28×1 / 0x8×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6734 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2a6738 mov r8, r3
 *   @0x2a673c blls 0x4967a4 <g_prim_v+0x6798>
 *   @0x2a6740 ldr r7, [sp, #0x20]
 *   @0x2a6744 ldr r5, [sp, #0x28]
 *   @0x2a6748 cmp r0, #0x0
 *   @0x2a674c cmp r1, #0x0
 *   @0x2a6750 ldr r0, [r1, #0x8]
 *   @0x2a6754 suble r0, r0, r4
 *   @0x2a6758 cbz r2, 0x2a6766 <png_get_cHRM+0x32>
 *   @0x2a675c .word 0xeeb77a20
 *   @0x2a6760 vstr s14, [r2, #796]
 *   @0x2a6764 .word 0xf1b87b00
 *   @0x2a6768 andle r0, r5, r0, lsl #30
 *   @0x2a676c vldr s14, [r1, #132]
 *   @0x2a6770 vcvt.f64.f32 d7, s14
 *   @0x2a6774 vstr d7, [r8]
 *   @0x2a6778 cmp.w r12, #0x0
 *   @0x2a677c beq 0x2a678a <png_get_cHRM+0x56>
 *   @0x2a6780 .word 0xeeb77a22
 *   @0x2a6784 vstr s14, [r12, #796]
 *   @0x2a6788 .word 0xb12b7b00
 *   @0x2a678c vldr s14, [r1, #140]
 *   @0x2a6790 vcvt.f64.f32 d7, s14
 *   @0x2a6794 vstr d7, [r3]
 *   @0x2a6798 cbz r7, 0x2a67a6 <png_get_cHRM+0x72>
 *   @0x2a679c .word 0xeeb77a24
 *   @0x2a67a0 vstr s14, [r7, #796]
 *   @0x2a67a4 .word 0xb12e7b00
 *   @0x2a67a8 vldr s14, [r1, #148]
 *   @0x2a67ac vcvt.f64.f32 d7, s14
 *   @0x2a67b0 vstr d7, [r6]
 *   @0x2a67b4 cbz r5, 0x2a67c2 <png_get_cHRM+0x8e>
 *   @0x2a67b8 .word 0xeeb77a26
 *   @0x2a67bc vstr s14, [r5, #796]
 *   @0x2a67c0 .word 0xb14c7b00
 *   @0x2a67c4 vldr s14, [r1, #156]
 *   @0x2a67c8 vcvt.f64.f32 d7, s14
 *   @0x2a67cc vstr d7, [r4]
 *   @0x2a67d0 b 0x2a67d8 <png_get_cHRM+0xa4>
 *   @0x2a67d4 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2a67d8 movs r0, #0x4
 *   @0x2a67dc push {r4, r5, r6, r7, r8, pc}
 *
 * ══ §30/181 png_write_destroy  0x2b05e8  size 170  43 条（0x2b05e8..0x2b0692）
 * @func 0x2b05e8 0x2b0692  size 170  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_free×4 / 0xb69b8 / 0xb65bc
 * 字段偏移 top8: 无
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b05e8 push.w {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2b05ec mov r4, r0
 *   @0x2b05f0 add.w r0, r0, #0x138
 *   @0x2b05f4 blx 0xb69b8 <deflateEnd@plt>
 *   @0x2b05f8 mov r0, r4
 *   @0x2b05fc vst4.16 {d17, d19, d21, d23}, [pc:256], r0
 *   @0x2b0600 .word 0xf7f67580
 *   @0x2b0604 qsub16mi pc, r0, r11
 *   @0x2b0608 ldr.w r1, [r4, #0x1b0]
 *   @0x2b060c bl 0x2a6cfc <png_free>
 *   @0x2b0610 mov r0, r4
 *   @0x2b0614 .word 0xf7f611ac
 *   @0x2b0618 qsub16mi pc, r0, r1
 *   @0x2b061c ldr.w r1, [r4, #0x1b4]
 *   @0x2b0620 bl 0x2a6cfc <png_free>
 *   @0x2b0624 mov r0, r4
 *   @0x2b0628 .word 0xf7f611b8
 *   @0x2b062c strtmi pc, [r0], -r7, ror #22
 *   @0x2b0630 ldr.w r1, [r4, #0x1bc]
 *   @0x2b0634 bl 0x2a6cfc <png_free>
 *   @0x2b0638 mov r0, r4
 *   @0x2b063c .word 0xf7f611c0
 *   @0x2b0640 qsaxmi pc, r0, sp
 *   @0x2b0644 ldr.w r1, [r4, #0x2bc]
 *   @0x2b0648 bl 0x2a6cfc <png_free>
 *   @0x2b064c mov r1, r4
 *   @0x2b0650 mov r0, sp
 *   @0x2b0654 .word 0xf8d4efb4
 *   @0x2b0658 .word 0xf8d4a104
 *   @0x2b065c strtmi r9, [r0], -r8, lsl #2
 *   @0x2b0660 ldr.w r8, [r4, #0x10c]
 *   @0x2b0664 movs r1, #0x0
 *   @0x2b0668 vst1.64 {d23, d24, d25, d26}, [pc:256], r0
 *   @0x2b066c .word 0xf605724e
 *   @0x2b0670 .word 0xf8c4efa0
 *   @0x2b0674 .word 0xf8c4a104
 *   @0x2b0678 strtmi r9, [r0], -r8, lsl #2
 *   @0x2b067c str.w r8, [r4, #0x10c]
 *   @0x2b0680 mov r1, sp
 *   @0x2b0684 qsub8mi r7, r10, r0
 *   @0x2b0688 blx 0xb65bc <memcpy@plt>
 *   @0x2b068c add sp, #0x100
 *   @0x2b0690 push {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §31/181 FT_New_GlyphSlot  0x2e7a70  size 170  43 条（0x2e7a70..0x2e7b1a）
 * @func 0x2e7a70 0x2e7b1a  size 170  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3267c0 / ft_mem_alloc / FT_GlyphLoader_New
 * 字段偏移 top8: 0x4×3 / 0x54×2 / 0x60×1 / 0xc×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7a70 push.w {r0, r1, r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2e7a74 mov r6, r1
 *   @0x2e7a78 cmp r0, #0x0
 *   @0x2e7a7c ldr r3, [r0, #0x60]
 *   @0x2e7a80 beq 0x2e7b12 <FT_New_GlyphSlot+0xa2>
 *   @0x2e7a84 strbtmi r8, [r10], -r8
 *   @0x2e7a88 ldr r3, [r3, #0xc]
 *   @0x2e7a8c ldr r1, [r3, #0x2c]
 *   @0x2e7a90 blls 0x3267c0
 *   @0x2e7a94 mov r4, r0
 *   @0x2e7a98 bne 0x2e7b04 <FT_New_GlyphSlot+0x94>
 *   @0x2e7a9c add r2, sp, #0x8
 *   @0x2e7aa0 movs r1, #0x28
 *   @0x2e7aa4 .word 0xf8d73d04
 *   @0x2e7aa8 ldmdavs r11!, {r3, r12, pc} ^
 *   @0x2e7aac ldr.w r10, [r7, #0xc]
 *   @0x2e7ab0 str r3, [r0]
 *   @0x2e7ab4 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e7ab8 ldr r3, [sp, #0x4]
 *   @0x2e7abc cbnz r3, 0x2e7ae2 <FT_New_GlyphSlot+0x72>
 *   @0x2e7ac0 ldmdavs r11!, {r2, r3, r4, r7}
 *   @0x2e7ac4 ldr r3, [r3]
 *   @0x2e7ac8 bmi 0x2e7ad2 <FT_New_GlyphSlot+0x62>
 *   @0x2e7acc bl 0x2e714c <FT_GlyphLoader_New>
 *   @0x2e7ad0 str r0, [sp, #0x4]
 *   @0x2e7ad4 cbnz r3, 0x2e7ae2 <FT_New_GlyphSlot+0x72>
 *   @0x2e7ad8 tstlt r3, r0, asr #32
 *   @0x2e7adc mov r0, r4
 *   @0x2e7ae0 str r0, [sp, #0x4]
 *   @0x2e7ae4 str r3, [sp]
 *   @0x2e7ae8 mov r0, r4
 *   @0x2e7aec .word 0x4640ff9e
 *   @0x2e7af0 mov r1, r4
 *   @0x2e7af4 and pc, r8, r0, lsr #24
 *   @0x2e7af8 ldr r3, [r5, #0x54]
 *   @0x2e7afc str r4, [r5, #0x54]
 *   @0x2e7b00 str r4, [r6]
 *   @0x2e7b04 cbz r6, 0x2e7b0a <FT_New_GlyphSlot+0x9a>
 *   @0x2e7b08 str r3, [r6]
 *   @0x2e7b0c b 0x2e7b14 <FT_New_GlyphSlot+0xa4>
 *   @0x2e7b10 b 0x2e7b14 <FT_New_GlyphSlot+0xa4>
 *   @0x2e7b14 add sp, #0x8
 *   @0x2e7b18 ldrlt r8, [r8, #-0x7f0]!
 *
 * ══ §32/181 Background_Free()  0xc34d0  size 168  42 条（0xc34d0..0xc3578）
 * @func 0xc34d0 0xc3578  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Background_Free()+0x84 / CBackground::Free() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×5 / 0x2×2 / 0x88×1 / 0x78×1 / 0x74×1 / 0x30×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc34d0 push {r3, r4, r5, r6, r7, lr}
 *   @0xc34d4 ldr r5, [pc, #0x88]
 *   @0xc34d8 ldr r5, [pc, r5]
 *   @0xc34dc ldr r3, [r5]
 *   @0xc34e0 cmp r3, #0
 *   @0xc34e4 ble 0xc3554 <_Z15Background_Freev+0x84>
 *   @0xc34e8 ldr r3, [pc, #0x78]
 *   @0xc34ec mov r4, #0
 *   @0xc34f0 ldr r6, [pc, #0x74]
 *   @0xc34f4 mov r7, r4
 *   @0xc34f8 add r3, pc, r3
 *   @0xc34fc add r6, pc, r6
 *   @0xc3500 ldr r2, [r3, #0x4]
 *   @0xc3504 ldr r0, [r2, r4, lsl #2]
 *   @0xc3508 cmp r0, #0
 *   @0xc350c beq 0xc3520 <_Z15Background_Freev+0x50>
 *   @0xc3510 bl 0xc2d5c <_ZN11CBackground4FreeEv>
 *   @0xc3514 ldr r3, [r6, #0x4]
 *   @0xc3518 str r7, [r3, r4, lsl #2]
 *   @0xc351c ldr r2, [r6, #0x4]
 *   @0xc3520 ldr r3, [r5]
 *   @0xc3524 add r4, r4, #1
 *   @0xc3528 cmp r3, r4
 *   @0xc352c bgt 0xc3504 <_Z15Background_Freev+0x34>
 *   @0xc3530 mov r0, r2
 *   @0xc3534 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc3538 ldr r2, [pc, #0x30]
 *   @0xc353c mov r3, #0
 *   @0xc3540 str r3, [r5]
 *   @0xc3544 add r2, pc, r2
 *   @0xc3548 str r3, [r2, #0x4]
 *   @0xc354c str r3, [r2]
 *   @0xc3550 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc3554 ldr r3, [pc, #0x18]
 *   @0xc3558 add r3, pc, r3
 *   @0xc355c ldr r2, [r3, #0x4]
 *   @0xc3560 b 0xc3530 <_Z15Background_Freev+0x60>
 *   @0xc3564 eorseq r10, r2, r0, ror r4
 *   @0xc3568 ldrhteq r6, [r11], -r0
 *   @0xc356c eorseq r6, r11, r12, lsr #15
 *   @0xc3570 eorseq r6, r11, r4, ror #14
 *   @0xc3574 eorseq r6, r11, r0, asr r7
 *
 * ══ §33/181 Background_Assign(int, int)  0xc4148  size 168  42 条（0xc4148..0xc41f0）
 * @func 0xc4148 0xc41f0  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Background_Assign(int, int)+0x64×2 / CBackground::Assign(CBackground*) / operator new(unsigned int) / CBackground::CBackground()
 * 字段偏移 top8: 0x2×5 / 0x4×3 / 0x84×1 / 0x74×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4148 push {r4, r5, r6, lr}
 *   @0xc414c subs r4, r1, #0
 *   @0xc4150 mov r5, r0
 *   @0xc4154 blt 0xc41ac <_Z17Background_Assignii+0x64>
 *   @0xc4158 ldr r3, [pc, #0x84]
 *   @0xc415c ldr r3, [pc, r3]
 *   @0xc4160 ldr r3, [r3]
 *   @0xc4164 cmp r4, r3
 *   @0xc4168 bge 0xc41ac <_Z17Background_Assignii+0x64>
 *   @0xc416c ldr r2, [pc, #0x74]
 *   @0xc4170 add r2, pc, r2
 *   @0xc4174 ldr r2, [r2, #0x4]
 *   @0xc4178 ldr r1, [r2, r4, lsl #2]
 *   @0xc417c cmp r1, #0
 *   @0xc4180 beq 0xc419c <_Z17Background_Assignii+0x54>
 *   @0xc4184 ldr r0, [r2, r5, lsl #2]
 *   @0xc4188 cmp r0, #0
 *   @0xc418c beq 0xc41b4 <_Z17Background_Assignii+0x6c>
 *   @0xc4190 bl 0xc2b80 <_ZN11CBackground6AssignEPS_>
 *   @0xc4194 mov r0, #1
 *   @0xc4198 pop {r4, r5, r6, pc}
 *   @0xc419c cmp r0, #0
 *   @0xc41a0 blt 0xc41ac <_Z17Background_Assignii+0x64>
 *   @0xc41a4 cmp r3, r0
 *   @0xc41a8 bgt 0xc4184 <_Z17Background_Assignii+0x3c>
 *   @0xc41ac mov r0, #0
 *   @0xc41b0 pop {r4, r5, r6, pc}
 *   @0xc41b4 mov r0, #72
 *   @0xc41b8 bl 0x27c524 <_Znwj>
 *   @0xc41bc mov r6, r0
 *   @0xc41c0 bl 0xc2b58 <_ZN11CBackgroundC2Ev>
 *   @0xc41c4 ldr r3, [pc, #0x20]
 *   @0xc41c8 add r3, pc, r3
 *   @0xc41cc ldr r2, [r3, #0x4]
 *   @0xc41d0 str r6, [r2, r5, lsl #2]
 *   @0xc41d4 ldr r3, [r3, #0x4]
 *   @0xc41d8 ldr r0, [r3, r5, lsl #2]
 *   @0xc41dc ldr r1, [r3, r4, lsl #2]
 *   @0xc41e0 b 0xc4190 <_Z17Background_Assignii+0x48>
 *   @0xc41e4 eorseq r9, r2, r12, ror #15
 *   @0xc41e8 eorseq r5, r11, r8, lsr r11
 *   @0xc41ec eorseq r5, r11, r0, ror #21
 *
 * ══ §34/181 F_BUFFER_Save_Ext(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5b74  size 168  42 条（0xc5b74..0xc5c1c）
 * @func 0xc5b74 0xc5c1c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_BUFFER_Save_Ext(RValue&, CInstance*, CInstance*, int, RValue*)+0x8c / YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x18×1 / 0x7c×1 / 0x4×1 / 0x2×1 / 0x1c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5b74 push {r4, r5, r6, r7, r8, lr}
 *   @0xc5b78 mov r1, #0
 *   @0xc5b7c ldr r4, [sp, #0x18]
 *   @0xc5b80 mov r0, r4
 *   @0xc5b84 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5b88 cmp r0, #0
 *   @0xc5b8c blt 0xc5c00 <_Z17F_BUFFER_Save_ExtR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0xc5b90 ldr r3, [pc, #0x7c]
 *   @0xc5b94 add r3, pc, r3
 *   @0xc5b98 ldr r2, [r3]
 *   @0xc5b9c cmp r0, r2
 *   @0xc5ba0 bge 0xc5c00 <_Z17F_BUFFER_Save_ExtR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0xc5ba4 ldr r3, [r3, #0x4]
 *   @0xc5ba8 ldr r5, [r3, r0, lsl #2]
 *   @0xc5bac cmp r5, #0
 *   @0xc5bb0 beq 0xc5c00 <_Z17F_BUFFER_Save_ExtR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0xc5bb4 ldr r3, [r5]
 *   @0xc5bb8 mov r0, r4
 *   @0xc5bbc mov r1, #1
 *   @0xc5bc0 ldr r6, [r3, #0x1c]
 *   @0xc5bc4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc5bc8 mov r1, #2
 *   @0xc5bcc mov r8, r0
 *   @0xc5bd0 mov r0, r4
 *   @0xc5bd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5bd8 mov r1, #3
 *   @0xc5bdc mov r7, r0
 *   @0xc5be0 mov r0, r4
 *   @0xc5be4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5be8 mov r1, r8
 *   @0xc5bec mov r2, r7
 *   @0xc5bf0 mov r3, r0
 *   @0xc5bf4 mov r0, r5
 *   @0xc5bf8 blx r6
 *   @0xc5bfc pop {r4, r5, r6, r7, r8, pc}
 *   @0xc5c00 ldr r0, [pc, #0x10]
 *   @0xc5c04 mov r1, #0
 *   @0xc5c08 pop {r4, r5, r6, r7, r8, lr}
 *   @0xc5c0c add r0, pc, r0
 *   @0xc5c10 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc5c14 eorseq r4, r11, r0, lsl #11
 *   @0xc5c18 eoreq r10, r6, r8, lsr #31
 *
 * ══ §35/181 F_BUFFER_Load_Ext(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5c1c  size 168  42 条（0xc5c1c..0xc5cc4）
 * @func 0xc5c1c 0xc5cc4  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_BUFFER_Load_Ext(RValue&, CInstance*, CInstance*, int, RValue*)+0x88 / YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x20×2 / 0x78×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5c1c push {r4, r5, r6, r7, lr}
 *   @0xc5c20 sub sp, sp, #12
 *   @0xc5c24 mov r1, #0
 *   @0xc5c28 ldr r4, [sp, #0x20]
 *   @0xc5c2c mov r0, r4
 *   @0xc5c30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5c34 cmp r0, #0
 *   @0xc5c38 blt 0xc5ca4 <_Z17F_BUFFER_Load_ExtR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xc5c3c ldr r3, [pc, #0x78]
 *   @0xc5c40 add r3, pc, r3
 *   @0xc5c44 ldr r2, [r3]
 *   @0xc5c48 cmp r0, r2
 *   @0xc5c4c bge 0xc5ca4 <_Z17F_BUFFER_Load_ExtR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xc5c50 ldr r3, [r3, #0x4]
 *   @0xc5c54 ldr r5, [r3, r0, lsl #2]
 *   @0xc5c58 cmp r5, #0
 *   @0xc5c5c beq 0xc5ca4 <_Z17F_BUFFER_Load_ExtR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xc5c60 ldr r3, [r5]
 *   @0xc5c64 mov r0, r4
 *   @0xc5c68 mov r1, #1
 *   @0xc5c6c ldr r6, [r3, #0x20]
 *   @0xc5c70 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc5c74 mov r1, #2
 *   @0xc5c78 mov r7, r0
 *   @0xc5c7c mov r0, r4
 *   @0xc5c80 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5c84 mov r1, r7
 *   @0xc5c88 mov r2, #0
 *   @0xc5c8c mvn r3, #0
 *   @0xc5c90 str r0, [sp]
 *   @0xc5c94 mov r0, r5
 *   @0xc5c98 blx r6
 *   @0xc5c9c add sp, sp, #12
 *   @0xc5ca0 pop {r4, r5, r6, r7, pc}
 *   @0xc5ca4 ldr r0, [pc, #0x14]
 *   @0xc5ca8 mov r1, #0
 *   @0xc5cac add r0, pc, r0
 *   @0xc5cb0 add sp, sp, #12
 *   @0xc5cb4 pop {r4, r5, r6, r7, lr}
 *   @0xc5cb8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc5cbc ldrsbteq r4, [r11], -r4
 *   @0xc5cc0 eoreq r10, r6, r8, lsl #30
 *
 * ══ §36/181 YYGetPtrOrInt(RValue const*, int)  0xce6c0  size 168  42 条（0xce6c0..0xce768）
 * @func 0xce6c0 0xce768  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: KindName(RValue const*) / YYError(char const*, ...)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x2c×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce6c0 add r2, r0, r1, lsl #4
 *   @0xce6c4 push {r4, r5, r6, lr}
 *   @0xce6c8 mov r6, r1
 *   @0xce6cc ldr r3, [r2, #0xc]
 *   @0xce6d0 bic r3, r3, #-16777216
 *   @0xce6d4 cmp r3, #10
 *   @0xce6d8 addls pc, pc, r3, lsl #2
 *   @0xce6dc b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c>
 *   @0xce6e0 b 0xce714 <_Z13YYGetPtrOrIntPK6RValuei+0x54>
 *   @0xce6e4 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c>
 *   @0xce6e8 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c>
 *   @0xce6ec b 0xce70c <_Z13YYGetPtrOrIntPK6RValuei+0x4c>
 *   @0xce6f0 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c>
 *   @0xce6f4 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c>
 *   @0xce6f8 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c>
 *   @0xce6fc b 0xce70c <_Z13YYGetPtrOrIntPK6RValuei+0x4c>
 *   @0xce700 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c>
 *   @0xce704 b 0xce72c <_Z13YYGetPtrOrIntPK6RValuei+0x6c>
 *   @0xce708 b 0xce70c <_Z13YYGetPtrOrIntPK6RValuei+0x4c>
 *   @0xce70c ldr r0, [r0, r1, lsl #4]
 *   @0xce710 pop {r4, r5, r6, pc}
 *   @0xce714 ldr r4, [r0, r1, lsl #4]
 *   @0xce718 ldr r5, [r2, #0x4]
 *   @0xce71c vmov d7, r4, r5
 *   @0xce720 vcvt.s32.f64 s15, d7
 *   @0xce724 vmov r0, s15
 *   @0xce728 pop {r4, r5, r6, pc}
 *   @0xce72c ldr r3, [pc, #0x2c]
 *   @0xce730 mov r0, r2
 *   @0xce734 ldr r3, [pc, r3]
 *   @0xce738 ldr r4, [r3]
 *   @0xce73c bl 0xce54c <_Z8KindNamePK6RValue>
 *   @0xce740 add r2, r6, #1
 *   @0xce744 mov r1, r4
 *   @0xce748 mov r3, r0
 *   @0xce74c ldr r0, [pc, #0x10]
 *   @0xce750 add r0, pc, r0
 *   @0xce754 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xce758 mvn r0, #0
 *   @0xce75c pop {r4, r5, r6, pc}
 *   @0xce760 ldrshteq pc, [r1], -r12
 *   @0xce764 eoreq r3, r6, r8, ror #22
 *
 * ══ §37/181 CFontGM::CFontGM()  0xf71c8  size 168  42 条（0xf71c8..0xf7270）
 * @func 0xf71c8 0xf7270  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::Clear()
 * 字段偏移 top8: 0x9c×1 / 0x50×1 / 0x38×1 / 0x8×1 / 0xc×1 / 0xd×1 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf71c8 ldr r3, [pc, #0x9c]
 *   @0xf71cc mov r1, #1056964608
 *   @0xf71d0 push {r4, lr}
 *   @0xf71d4 ldr r3, [pc, r3]
 *   @0xf71d8 mov r4, r0
 *   @0xf71dc str r1, [r0, #0x50]
 *   @0xf71e0 mvn r2, #0
 *   @0xf71e4 str r2, [r0, #0x38]
 *   @0xf71e8 add r2, r3, #8
 *   @0xf71ec mov r3, #0
 *   @0xf71f0 stm r0, {r2, r3}
 *   @0xf71f4 str r3, [r0, #0x8]
 *   @0xf71f8 strb r3, [r0, #0xc]
 *   @0xf71fc strb r3, [r0, #0xd]
 *   @0xf7200 str r3, [r0, #0x18]
 *   @0xf7204 str r3, [r0, #0x1c]
 *   @0xf7208 str r3, [r0, #0x20]
 *   @0xf720c str r3, [r0, #0x24]
 *   @0xf7210 str r3, [r0, #0x28]
 *   @0xf7214 str r3, [r0, #0x2c]
 *   @0xf7218 str r3, [r0, #0x40]
 *   @0xf721c str r3, [r0, #0x44]
 *   @0xf7220 str r3, [r0, #0x5c]
 *   @0xf7224 str r3, [r0, #0x60]
 *   @0xf7228 str r3, [r0, #0x64]
 *   @0xf722c str r3, [r0, #0x6c]
 *   @0xf7230 str r3, [r0, #0x70]
 *   @0xf7234 str r3, [r0, #0x74]
 *   @0xf7238 str r3, [r0, #0x78]
 *   @0xf723c str r3, [r0, #0x7c]
 *   @0xf7240 str r3, [r0, #0x80]
 *   @0xf7244 str r3, [r0, #0x84]
 *   @0xf7248 str r3, [r0, #0x88]
 *   @0xf724c str r3, [r0, #0x3c]
 *   @0xf7250 str r3, [r0, #0x34]
 *   @0xf7254 str r3, [r0, #0x30]
 *   @0xf7258 str r3, [r0, #0x54]
 *   @0xf725c str r3, [r0, #0x8c]
 *   @0xf7260 bl 0xf70a0 <_ZN7CFontGM5ClearEv>
 *   @0xf7264 mov r0, r4
 *   @0xf7268 pop {r4, pc}
 *   @0xf726c eoreq r6, pc, r4, ror r12
 *
 * ══ §38/181 F_DsStackPush(RValue&, CInstance*, CInstance*, int, RValue*)  0xfbc18  size 168  42 条（0xfbc18..0xfbcc0）
 * @func 0xfbc18 0xfbcc0  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CDS_Stack::Push(RValue*)
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0x68×1 / 0x58×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfbc18 push {r4, r5, r6, r7, r8, lr}
 *   @0xfbc1c mov r1, #0
 *   @0xfbc20 ldr r5, [sp, #0x18]
 *   @0xfbc24 mov r6, r3
 *   @0xfbc28 mov r0, r5
 *   @0xfbc2c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfbc30 cmp r6, #1
 *   @0xfbc34 movgt r3, #0
 *   @0xfbc38 movle r3, #1
 *   @0xfbc3c orrs r3, r3, r0, lsr #31
 *   @0xfbc40 bne 0xfbca0 <_Z13F_DsStackPushR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xfbc44 ldr r3, [pc, #0x68]
 *   @0xfbc48 ldr r3, [pc, r3]
 *   @0xfbc4c ldr r3, [r3]
 *   @0xfbc50 cmp r0, r3
 *   @0xfbc54 bge 0xfbca0 <_Z13F_DsStackPushR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xfbc58 ldr r7, [pc, #0x58]
 *   @0xfbc5c lsl r8, r0, #2
 *   @0xfbc60 ldr r7, [pc, r7]
 *   @0xfbc64 ldr r3, [r7, #0x4]
 *   @0xfbc68 ldr r0, [r3, r0, lsl #2]
 *   @0xfbc6c cmp r0, #0
 *   @0xfbc70 addne r5, r5, #16
 *   @0xfbc74 movne r4, #1
 *   @0xfbc78 beq 0xfbca0 <_Z13F_DsStackPushR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xfbc7c mov r1, r5
 *   @0xfbc80 add r4, r4, #1
 *   @0xfbc84 bl 0x20566c <_ZN9CDS_Stack4PushEP6RValue>
 *   @0xfbc88 cmp r6, r4
 *   @0xfbc8c add r5, r5, #16
 *   @0xfbc90 pople {r4, r5, r6, r7, r8, pc}
 *   @0xfbc94 ldr r2, [r7, #0x4]
 *   @0xfbc98 ldr r0, [r2, r8]
 *   @0xfbc9c b 0xfbc7c <_Z13F_DsStackPushR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xfbca0 ldr r0, [pc, #0x14]
 *   @0xfbca4 mov r1, #0
 *   @0xfbca8 pop {r4, r5, r6, r7, r8, lr}
 *   @0xfbcac add r0, pc, r0
 *   @0xfbcb0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfbcb4 eoreq r2, pc, r4, lsr r2
 *   @0xfbcb8 eoreq r2, pc, r0, lsr #4
 *   @0xfbcbc eoreq r11, r3, r0, asr pc
 *
 * ══ §39/181 F_DsListAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc474  size 168  42 条（0xfc474..0xfc51c）
 * @func 0xfc474 0xfc51c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CDS_List::Add(RValue*)
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0x68×1 / 0x58×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc474 push {r4, r5, r6, r7, r8, lr}
 *   @0xfc478 mov r1, #0
 *   @0xfc47c ldr r5, [sp, #0x18]
 *   @0xfc480 mov r6, r3
 *   @0xfc484 mov r0, r5
 *   @0xfc488 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc48c cmp r6, #1
 *   @0xfc490 movgt r3, #0
 *   @0xfc494 movle r3, #1
 *   @0xfc498 orrs r3, r3, r0, lsr #31
 *   @0xfc49c bne 0xfc4fc <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xfc4a0 ldr r3, [pc, #0x68]
 *   @0xfc4a4 ldr r3, [pc, r3]
 *   @0xfc4a8 ldr r3, [r3]
 *   @0xfc4ac cmp r0, r3
 *   @0xfc4b0 bge 0xfc4fc <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xfc4b4 ldr r7, [pc, #0x58]
 *   @0xfc4b8 lsl r8, r0, #2
 *   @0xfc4bc ldr r7, [pc, r7]
 *   @0xfc4c0 ldr r3, [r7, #0x4]
 *   @0xfc4c4 ldr r0, [r3, r0, lsl #2]
 *   @0xfc4c8 cmp r0, #0
 *   @0xfc4cc addne r5, r5, #16
 *   @0xfc4d0 movne r4, #1
 *   @0xfc4d4 beq 0xfc4fc <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xfc4d8 mov r1, r5
 *   @0xfc4dc add r4, r4, #1
 *   @0xfc4e0 bl 0x205d18 <_ZN8CDS_List3AddEP6RValue>
 *   @0xfc4e4 cmp r6, r4
 *   @0xfc4e8 add r5, r5, #16
 *   @0xfc4ec pople {r4, r5, r6, r7, r8, pc}
 *   @0xfc4f0 ldr r2, [r7, #0x4]
 *   @0xfc4f4 ldr r0, [r2, r8]
 *   @0xfc4f8 b 0xfc4d8 <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0xfc4fc ldr r0, [pc, #0x14]
 *   @0xfc500 mov r1, #0
 *   @0xfc504 pop {r4, r5, r6, r7, r8, lr}
 *   @0xfc508 add r0, pc, r0
 *   @0xfc50c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc510 .word 0x002f17d8
 *   @0xfc514 eoreq r1, pc, r4, asr #15
 *   @0xfc518 .word 0x0023b6f4
 *
 * ══ §40/181 F_DsMapSetPost(RValue&, CInstance*, CInstance*, int, RValue*)  0xff180  size 168  42 条（0xff180..0xff228）
 * @func 0xff180 0xff228  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapSetPost(RValue&, CInstance*, CInstance*, int, RValue*)+0x7c / CDS_Map::Set(RValue*, RValue*, RValue*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x18×1 / 0x64×1 / 0x54×1 / 0x4×1 / 0x2×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xff180 push {r4, r5, r6, lr}
 *   @0xff184 sub sp, sp, #8
 *   @0xff188 add r4, sp, #4
 *   @0xff18c mov r6, r0
 *   @0xff190 ldr r5, [sp, #0x18]
 *   @0xff194 mov r0, r4
 *   @0xff198 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xff19c mov r1, #0
 *   @0xff1a0 mov r0, r5
 *   @0xff1a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xff1a8 cmp r0, #0
 *   @0xff1ac blt 0xff1fc <_Z14F_DsMapSetPostR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xff1b0 ldr r1, [pc, #0x64]
 *   @0xff1b4 ldr r1, [pc, r1]
 *   @0xff1b8 ldr r1, [r1]
 *   @0xff1bc cmp r0, r1
 *   @0xff1c0 bge 0xff1fc <_Z14F_DsMapSetPostR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xff1c4 ldr r1, [pc, #0x54]
 *   @0xff1c8 ldr r1, [pc, r1]
 *   @0xff1cc ldr r3, [r1, #0x4]
 *   @0xff1d0 ldr r0, [r3, r0, lsl #2]
 *   @0xff1d4 cmp r0, #0
 *   @0xff1d8 beq 0xff1fc <_Z14F_DsMapSetPostR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xff1dc mov r3, r6
 *   @0xff1e0 add r1, r5, #16
 *   @0xff1e4 add r2, r5, #32
 *   @0xff1e8 bl 0x208c3c <_ZN7CDS_Map3SetEP6RValueS1_S1_>
 *   @0xff1ec mov r0, r4
 *   @0xff1f0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff1f4 add sp, sp, #8
 *   @0xff1f8 pop {r4, r5, r6, pc}
 *   @0xff1fc ldr r0, [pc, #0x20]
 *   @0xff200 mov r1, #0
 *   @0xff204 add r0, pc, r0
 *   @0xff208 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff20c mov r0, r4
 *   @0xff210 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff214 add sp, sp, #8
 *   @0xff218 pop {r4, r5, r6, pc}
 *   @0xff21c eoreq lr, lr, r4, asr #21
 *   @0xff220 eoreq lr, lr, r4, ror r7
 *   @0xff224 .word 0x002389f8
 *
 * ══ §41/181 F_Chr(RValue&, CInstance*, CInstance*, int, RValue*)  0x10ed40  size 168  42 条（0x10ed40..0x10ede8）
 * @func 0x10ed40 0x10ede8  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_Chr(RValue&, CInstance*, CInstance*, int, RValue*)+0x94 / F_Chr(RValue&, CInstance*, CInstance*, int, RValue*)+0x70 / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x5×3 / 0x4×3 / 0x6×2 / 0x10×1 / 0xc×1 / 0x7×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ed40 push {r4, lr}
 *   @0x10ed44 sub sp, sp, #8
 *   @0x10ed48 mov r4, r0
 *   @0x10ed4c mov r3, #1
 *   @0x10ed50 ldr r0, [sp, #0x10]
 *   @0x10ed54 mov r1, #0
 *   @0x10ed58 str r3, [r4, #0xc]
 *   @0x10ed5c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10ed60 cmp r0, #127
 *   @0x10ed64 ble 0x10edd4 <_Z5F_ChrR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x10ed68 cmp r0, #2048
 *   @0x10ed6c blt 0x10edb0 <_Z5F_ChrR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x10ed70 ubfx r1, r0, #0xc, #0x4
 *   @0x10ed74 ubfx r2, r0, #0x6, #0x6
 *   @0x10ed78 and r3, r0, #63
 *   @0x10ed7c sub r2, r2, #128
 *   @0x10ed80 sub r1, r1, #32
 *   @0x10ed84 strb r2, [sp, #0x5]
 *   @0x10ed88 sub r3, r3, #128
 *   @0x10ed8c mov r2, #0
 *   @0x10ed90 strb r1, [sp, #0x4]
 *   @0x10ed94 strb r3, [sp, #0x6]
 *   @0x10ed98 strb r2, [sp, #0x7]
 *   @0x10ed9c mov r0, r4
 *   @0x10eda0 add r1, sp, #4
 *   @0x10eda4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x10eda8 add sp, sp, #8
 *   @0x10edac pop {r4, pc}
 *   @0x10edb0 asr r2, r0, #6
 *   @0x10edb4 and r3, r0, #63
 *   @0x10edb8 sub r2, r2, #64
 *   @0x10edbc sub r3, r3, #128
 *   @0x10edc0 strb r2, [sp, #0x4]
 *   @0x10edc4 mov r2, #0
 *   @0x10edc8 strb r3, [sp, #0x5]
 *   @0x10edcc strb r2, [sp, #0x6]
 *   @0x10edd0 b 0x10ed9c <_Z5F_ChrR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x10edd4 and r3, r0, #127
 *   @0x10edd8 mov r2, #0
 *   @0x10eddc strb r3, [sp, #0x4]
 *   @0x10ede0 strb r2, [sp, #0x5]
 *   @0x10ede4 b 0x10ed9c <_Z5F_ChrR6RValueP9CInstanceS2_iPS_+0x5c>
 *
 * ══ §42/181 F_StringRepeat(RValue&, CInstance*, CInstance*, int, RValue*)  0x10ef4c  size 168  42 条（0x10ef4c..0x10eff4）
 * @func 0x10ef4c 0x10eff4  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / F_StringRepeat(RValue&, CInstance*, CInstance*, int, RValue*)+0x8c / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6628 / YYCreateString(RValue*, char const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x18×1 / 0x5c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ef4c push {r4, r5, r6, r7, r8, lr}
 *   @0x10ef50 mov r1, #0
 *   @0x10ef54 ldr r4, [sp, #0x18]
 *   @0x10ef58 mov r8, r0
 *   @0x10ef5c mov r0, r4
 *   @0x10ef60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x10ef64 mov r1, #1
 *   @0x10ef68 mov r7, r0
 *   @0x10ef6c mov r0, r4
 *   @0x10ef70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10ef74 subs r6, r0, #0
 *   @0x10ef78 ble 0x10efd8 <_Z14F_StringRepeatR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x10ef7c mov r0, r7
 *   @0x10ef80 mov r4, #1
 *   @0x10ef84 bl 0xb6538 <strlen@plt>
 *   @0x10ef88 ldr r1, [pc, #0x5c]
 *   @0x10ef8c movw r2, #0x826
 *   @0x10ef90 mov r3, r4
 *   @0x10ef94 add r1, pc, r1
 *   @0x10ef98 mul r0, r6, r0
 *   @0x10ef9c add r0, r0, r4
 *   @0x10efa0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x10efa4 mov r5, r0
 *   @0x10efa8 add r4, r4, #1
 *   @0x10efac mov r0, r5
 *   @0x10efb0 mov r1, r7
 *   @0x10efb4 bl 0xb6628 <strcat@plt>
 *   @0x10efb8 cmp r6, r4
 *   @0x10efbc bge 0x10efa8 <_Z14F_StringRepeatR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x10efc0 mov r0, r8
 *   @0x10efc4 mov r1, r5
 *   @0x10efc8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x10efcc mov r0, r5
 *   @0x10efd0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x10efd4 b 0xcef90 <_Z6YYFreePKv>
 *   @0x10efd8 ldr r0, [pc, #0x10]
 *   @0x10efdc add r0, pc, r0
 *   @0x10efe0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x10efe4 mov r5, r0
 *   @0x10efe8 b 0x10efc0 <_Z14F_StringRepeatR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x10efec .word 0x00229eb0
 *   @0x10eff0 eoreq sp, r4, r0, ror #18
 *
 * ══ §43/181 F_ArraySet2DPost(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f644  size 168  42 条（0x10f644..0x10f6ec）
 * @func 0x10f644 0x10f6ec  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / GET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x78×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f644 cmp r3, #4
 *   @0x10f648 push {r3, r4, r5, r6, r7, lr}
 *   @0x10f64c mov r5, r0
 *   @0x10f650 ldr r4, [sp, #0x18]
 *   @0x10f654 beq 0x10f674 <_Z16F_ArraySet2DPostR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x10f658 ldr r3, [r4, #0xc]
 *   @0x10f65c cmp r3, #2
 *   @0x10f660 beq 0x10f68c <_Z16F_ArraySet2DPostR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x10f664 ldr r0, [pc, #0x78]
 *   @0x10f668 pop {r3, r4, r5, r6, r7, lr}
 *   @0x10f66c add r0, pc, r0
 *   @0x10f670 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10f674 ldr r6, [r4, #0xc]
 *   @0x10f678 cmp r6, #2
 *   @0x10f67c bne 0x10f664 <_Z16F_ArraySet2DPostR6RValueP9CInstanceS2_iPS_+0x20>
 *   @0x10f680 ldr r3, [r4]
 *   @0x10f684 cmp r3, #0
 *   @0x10f688 bne 0x10f69c <_Z16F_ArraySet2DPostR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x10f68c ldr r0, [pc, #0x54]
 *   @0x10f690 pop {r3, r4, r5, r6, r7, lr}
 *   @0x10f694 add r0, pc, r0
 *   @0x10f698 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10f69c mov r0, r4
 *   @0x10f6a0 mov r1, #1
 *   @0x10f6a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10f6a8 mov r1, r6
 *   @0x10f6ac mov r6, #32000
 *   @0x10f6b0 mov r7, r0
 *   @0x10f6b4 mov r0, r4
 *   @0x10f6b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10f6bc mov r1, r4
 *   @0x10f6c0 mla r6, r6, r7, r0
 *   @0x10f6c4 mov r0, r5
 *   @0x10f6c8 mov r2, r6
 *   @0x10f6cc bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x10f6d0 mov r0, r4
 *   @0x10f6d4 mov r2, r6
 *   @0x10f6d8 add r1, r4, #48
 *   @0x10f6dc pop {r3, r4, r5, r6, r7, lr}
 *   @0x10f6e0 b 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i>
 *   @0x10f6e4 .word 0x002298bc
 *   @0x10f6e8 eoreq r9, r2, r0, asr #17
 *
 * ══ §44/181 F_DrawPath(RValue&, CInstance*, CInstance*, int, RValue*)  0x11d9c0  size 168  42 条（0x11d9c0..0x11da68）
 * @func 0x11d9c0 0x11da68  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / Path_Data(int)×2 / YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int) / Path_Exists(int)
 * 字段偏移 top8: 0x18×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11d9c0 push {r4, r5, r6, r7, r8, lr}
 *   @0x11d9c4 mov r1, #0
 *   @0x11d9c8 ldr r4, [sp, #0x18]
 *   @0x11d9cc mov r0, r4
 *   @0x11d9d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d9d4 mov r1, #1
 *   @0x11d9d8 mov r5, r0
 *   @0x11d9dc mov r0, r4
 *   @0x11d9e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d9e4 mov r1, #2
 *   @0x11d9e8 mov r7, r0
 *   @0x11d9ec mov r0, r4
 *   @0x11d9f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d9f4 mov r1, #3
 *   @0x11d9f8 mov r6, r0
 *   @0x11d9fc mov r0, r4
 *   @0x11da00 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11da04 mov r4, r0
 *   @0x11da08 mov r0, r5
 *   @0x11da0c bl 0x1a8008 <_Z11Path_Existsi>
 *   @0x11da10 subs r1, r0, #0
 *   @0x11da14 beq 0x11da54 <_Z10F_DrawPathR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x11da18 cmp r4, #0
 *   @0x11da1c mov r0, r5
 *   @0x11da20 bne 0x11da3c <_Z10F_DrawPathR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x11da24 bl 0x1a815c <_Z9Path_Datai>
 *   @0x11da28 mov r1, r7
 *   @0x11da2c mov r2, r6
 *   @0x11da30 mov r3, r4
 *   @0x11da34 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11da38 b 0x1a7ac0 <_ZN5CPath4DrawEffb>
 *   @0x11da3c bl 0x1a815c <_Z9Path_Datai>
 *   @0x11da40 mov r1, #0
 *   @0x11da44 mov r3, #1
 *   @0x11da48 mov r2, r1
 *   @0x11da4c pop {r4, r5, r6, r7, r8, lr}
 *   @0x11da50 b 0x1a7ac0 <_ZN5CPath4DrawEffb>
 *   @0x11da54 ldr r0, [pc, #0x8]
 *   @0x11da58 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11da5c add r0, pc, r0
 *   @0x11da60 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11da64 .word 0x0021c6f0
 *
 * ══ §45/181 F_DrawTextTransformed(RValue&, CInstance*, CInstance*, int, RValue*)  0x121ddc  size 168  42 条（0x121ddc..0x121e84）
 * @func 0x121ddc 0x121e84  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / GetTextFromArg(RValue const*, int, char**) / GR_Text_Draw_Transformed(float, float, char const*, int, int, float, float, float) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x14×2 / 0x38×1 / 0x-4×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x121ddc push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x121de0 sub sp, sp, #28
 *   @0x121de4 add r2, sp, #24
 *   @0x121de8 mov r5, #0
 *   @0x121dec ldr r4, [sp, #0x38]
 *   @0x121df0 mov r1, #1024
 *   @0x121df4 str r5, [r2, #-0x4]!
 *   @0x121df8 add r0, r4, #32
 *   @0x121dfc bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc>
 *   @0x121e00 mov r1, r5
 *   @0x121e04 mov r0, r4
 *   @0x121e08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121e0c mov r1, #1
 *   @0x121e10 mov r5, r0
 *   @0x121e14 mov r0, r4
 *   @0x121e18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121e1c mov r1, #3
 *   @0x121e20 ldr r6, [sp, #0x14]
 *   @0x121e24 mov r7, r0
 *   @0x121e28 mov r0, r4
 *   @0x121e2c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121e30 mov r1, #4
 *   @0x121e34 mov r9, r0
 *   @0x121e38 mov r0, r4
 *   @0x121e3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121e40 mov r1, #5
 *   @0x121e44 mov r8, r0
 *   @0x121e48 mov r0, r4
 *   @0x121e4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121e50 mvn r3, #0
 *   @0x121e54 mov r1, r7
 *   @0x121e58 mov r2, r6
 *   @0x121e5c str r3, [sp]
 *   @0x121e60 str r9, [sp, #0x4]
 *   @0x121e64 str r8, [sp, #0x8]
 *   @0x121e68 str r0, [sp, #0xc]
 *   @0x121e6c mov r0, r5
 *   @0x121e70 bl 0x173068 <_Z24GR_Text_Draw_TransformedffPKciifff>
 *   @0x121e74 ldr r0, [sp, #0x14]
 *   @0x121e78 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x121e7c add sp, sp, #28
 *   @0x121e80 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §46/181 F_ObjectEventClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e1d8  size 168  42 条（0x12e1d8..0x12e280）
 * @func 0x12e1d8 0x12e280  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / CObjectGM::GetEventDirect(int, int) / CEvent::Clear()
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x88×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e1d8 push {r4, r5, r6, lr}
 *   @0x12e1dc mov r1, #0
 *   @0x12e1e0 ldr r4, [sp, #0x10]
 *   @0x12e1e4 mov r0, r4
 *   @0x12e1e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e1ec ldr r3, [pc, #0x88]
 *   @0x12e1f0 ldr r3, [pc, r3]
 *   @0x12e1f4 ldr r3, [r3]
 *   @0x12e1f8 ldr r2, [r3, #0x4]
 *   @0x12e1fc ldr r3, [r3]
 *   @0x12e200 and r2, r0, r2
 *   @0x12e204 ldr r3, [r3, r2, lsl #3]
 *   @0x12e208 cmp r3, #0
 *   @0x12e20c bne 0x12e220 <_Z18F_ObjectEventClearR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12e210 pop {r4, r5, r6, pc}
 *   @0x12e214 ldr r3, [r3, #0x4]
 *   @0x12e218 cmp r3, #0
 *   @0x12e21c beq 0x12e278 <_Z18F_ObjectEventClearR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x12e220 ldr r2, [r3, #0x8]
 *   @0x12e224 cmp r0, r2
 *   @0x12e228 bne 0x12e214 <_Z18F_ObjectEventClearR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12e22c ldr r5, [r3, #0xc]
 *   @0x12e230 cmp r5, #0
 *   @0x12e234 popeq {r4, r5, r6, pc}
 *   @0x12e238 mov r1, #1
 *   @0x12e23c mov r0, r4
 *   @0x12e240 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e244 mov r1, #2
 *   @0x12e248 mov r6, r0
 *   @0x12e24c mov r0, r4
 *   @0x12e250 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e254 mov r1, r6
 *   @0x12e258 mov r2, r0
 *   @0x12e25c mov r0, r5
 *   @0x12e260 bl 0x19da74 <_ZN9CObjectGM14GetEventDirectEii>
 *   @0x12e264 cmp r0, #0
 *   @0x12e268 popeq {r4, r5, r6, pc}
 *   @0x12e26c bl 0xf2d08 <_ZN6CEvent5ClearEv>
 *   @0x12e270 pop {r4, r5, r6, lr}
 *   @0x12e274 b 0x19e7dc <_Z19Create_Object_Listsv>
 *   @0x12e278 pop {r4, r5, r6, pc}
 *   @0x12e27c eoreq pc, r11, r12, asr #20
 *
 * ══ §47/181 MarkInstancesAsDirty(int)  0x130cac  size 168  42 条（0x130cac..0x130d54）
 * @func 0x130cac 0x130d54  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CollisionMarkDirty(CInstance*)×2
 * 字段偏移 top8: 0x8c×3 / 0x178×2 / 0x64×2 / 0x94×1 / 0x80×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x130cac push {r3, r4, r5, r6, r7, lr}
 *   @0x130cb0 mov r5, r0
 *   @0x130cb4 ldr r6, [pc, #0x94]
 *   @0x130cb8 ldr r6, [pc, r6]
 *   @0x130cbc ldr r3, [r6]
 *   @0x130cc0 ldr r0, [r3, #0x80]
 *   @0x130cc4 cmp r0, #0
 *   @0x130cc8 beq 0x130d08 <_Z20MarkInstancesAsDirtyi+0x5c>
 *   @0x130ccc mov r7, #1
 *   @0x130cd0 b 0x130ce0 <_Z20MarkInstancesAsDirtyi+0x34>
 *   @0x130cd4 cmp r4, #0
 *   @0x130cd8 mov r0, r4
 *   @0x130cdc beq 0x130d04 <_Z20MarkInstancesAsDirtyi+0x58>
 *   @0x130ce0 ldr r3, [r0, #0x8c]
 *   @0x130ce4 ldr r4, [r0, #0x178]
 *   @0x130ce8 cmp r3, r5
 *   @0x130cec bne 0x130cd4 <_Z20MarkInstancesAsDirtyi+0x28>
 *   @0x130cf0 strb r7, [r0, #0x64]
 *   @0x130cf4 bl 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance>
 *   @0x130cf8 cmp r4, #0
 *   @0x130cfc mov r0, r4
 *   @0x130d00 bne 0x130ce0 <_Z20MarkInstancesAsDirtyi+0x34>
 *   @0x130d04 ldr r3, [r6]
 *   @0x130d08 ldr r0, [r3, #0x8c]
 *   @0x130d0c cmp r0, #0
 *   @0x130d10 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x130d14 mov r6, #1
 *   @0x130d18 b 0x130d28 <_Z20MarkInstancesAsDirtyi+0x7c>
 *   @0x130d1c cmp r4, #0
 *   @0x130d20 mov r0, r4
 *   @0x130d24 beq 0x130d4c <_Z20MarkInstancesAsDirtyi+0xa0>
 *   @0x130d28 ldr r3, [r0, #0x8c]
 *   @0x130d2c ldr r4, [r0, #0x178]
 *   @0x130d30 cmp r5, r3
 *   @0x130d34 bne 0x130d1c <_Z20MarkInstancesAsDirtyi+0x70>
 *   @0x130d38 strb r6, [r0, #0x64]
 *   @0x130d3c bl 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance>
 *   @0x130d40 cmp r4, #0
 *   @0x130d44 mov r0, r4
 *   @0x130d48 bne 0x130d28 <_Z20MarkInstancesAsDirtyi+0x7c>
 *   @0x130d4c pop {r3, r4, r5, r6, r7, pc}
 *   @0x130d50 eoreq r12, r11, r0, ror r12
 *
 * ══ §48/181 F_SoundVolume(RValue&, CInstance*, CInstance*, int, RValue*)  0x133b48  size 168  42 条（0x133b48..0x133bf0）
 * @func 0x133b48 0x133bf0  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Sound_Data(int) / CSound::GetSoundId()
 * 字段偏移 top8: 0x10×2 / 0x94×1 / 0x7c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133b48 ldr r3, [pc, #0x94]
 *   @0x133b4c push {r4, r5, r6, lr}
 *   @0x133b50 ldr r3, [pc, r3]
 *   @0x133b54 ldr r4, [sp, #0x10]
 *   @0x133b58 ldrb r3, [r3]
 *   @0x133b5c cmp r3, #0
 *   @0x133b60 popne {r4, r5, r6, pc}
 *   @0x133b64 ldr r3, [pc, #0x7c]
 *   @0x133b68 ldr r3, [pc, r3]
 *   @0x133b6c ldrb r1, [r3]
 *   @0x133b70 cmp r1, #0
 *   @0x133b74 popne {r4, r5, r6, pc}
 *   @0x133b78 mov r0, r4
 *   @0x133b7c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x133b80 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x133b84 subs r5, r0, #0
 *   @0x133b88 beq 0x133bd0 <_Z13F_SoundVolumeR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x133b8c mov r0, r4
 *   @0x133b90 mov r1, #1
 *   @0x133b94 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x133b98 strd r0, r1, [r5, #32]
 *   @0x133b9c mov r0, r5
 *   @0x133ba0 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x133ba4 mov r1, #1
 *   @0x133ba8 mov r5, r0
 *   @0x133bac mov r0, r4
 *   @0x133bb0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x133bb4 mov r2, r0
 *   @0x133bb8 mov r3, r1
 *   @0x133bbc mov r0, r5
 *   @0x133bc0 mov r1, #1
 *   @0x133bc4 str r1, [sp, #0x10]
 *   @0x133bc8 pop {r4, r5, r6, lr}
 *   @0x133bcc b 0x21f07c <_Z14SND_Set_Volumeidi>
 *   @0x133bd0 ldr r0, [pc, #0x14]
 *   @0x133bd4 mov r1, r5
 *   @0x133bd8 pop {r4, r5, r6, lr}
 *   @0x133bdc add r0, pc, r0
 *   @0x133be0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x133be4 eoreq r11, r11, r0, ror #3
 *   @0x133be8 eoreq r11, r11, r4, ror #9
 *   @0x133bec .word 0x0020b8b0
 *
 * ══ §49/181 F_JsonEncode(RValue&, CInstance*, CInstance*, int, RValue*)  0x13c130  size 168  42 条（0x13c130..0x13c1d8）
 * @func 0x13c130 0x13c1d8  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_JsonEncode(RValue&, CInstance*, CInstance*, int, RValue*)+0x44 / F_JsonEncode(RValue&, CInstance*, CInstance*, int, RValue*)+0x4c / DS_AutoMutex::DS_AutoMutex() / EncodeDSMap(CDS_Map*) / json_object_to_json_string / YYCreateString(RValue*, char const*) / json_object_put
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x68×1 / 0x44×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13c130 push {r4, r5, r6, lr}
 *   @0x13c134 sub sp, sp, #8
 *   @0x13c138 mov r4, r0
 *   @0x13c13c mov r1, #0
 *   @0x13c140 ldr r0, [sp, #0x18]
 *   @0x13c144 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13c148 mov r2, #1
 *   @0x13c14c mov r3, #0
 *   @0x13c150 str r2, [r4, #0xc]
 *   @0x13c154 str r3, [r4]
 *   @0x13c158 subs r5, r0, #0
 *   @0x13c15c blt 0x13c174 <_Z12F_JsonEncodeR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x13c160 ldr r3, [pc, #0x68]
 *   @0x13c164 ldr r3, [pc, r3]
 *   @0x13c168 ldr r3, [r3]
 *   @0x13c16c cmp r5, r3
 *   @0x13c170 blt 0x13c17c <_Z12F_JsonEncodeR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x13c174 add sp, sp, #8
 *   @0x13c178 pop {r4, r5, r6, pc}
 *   @0x13c17c add r6, sp, #4
 *   @0x13c180 mov r0, r6
 *   @0x13c184 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x13c188 ldr r3, [pc, #0x44]
 *   @0x13c18c ldr r3, [pc, r3]
 *   @0x13c190 ldr r3, [r3, #0x4]
 *   @0x13c194 ldr r0, [r3, r5, lsl #2]
 *   @0x13c198 cmp r0, #0
 *   @0x13c19c beq 0x13c1c0 <_Z12F_JsonEncodeR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x13c1a0 bl 0x13bcec <_Z11EncodeDSMapP7CDS_Map>
 *   @0x13c1a4 mov r5, r0
 *   @0x13c1a8 bl 0x27e830 <json_object_to_json_string>
 *   @0x13c1ac mov r1, r0
 *   @0x13c1b0 mov r0, r4
 *   @0x13c1b4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x13c1b8 mov r0, r5
 *   @0x13c1bc bl 0x27e7c8 <json_object_put>
 *   @0x13c1c0 mov r0, r6
 *   @0x13c1c4 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x13c1c8 add sp, sp, #8
 *   @0x13c1cc pop {r4, r5, r6, pc}
 *   @0x13c1d0 eoreq r1, r11, r4, lsl r11
 *   @0x13c1d4 .word 0x002b17b0
 *
 * ══ §50/181 F_ActionSpriteTransform(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e590  size 168  42 条（0x13e590..0x13e638）
 * @func 0x13e590 0x13e638  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / CInstance::SetImageScaleX(float)×2 / YYGetInt32(RValue const*, int) / CInstance::SetImageScaleY(float) / CInstance::SetImageAngle(float)
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e590 push {r4, r5, r6, r7, r8, lr}
 *   @0x13e594 mov r5, r1
 *   @0x13e598 ldr r4, [sp, #0x18]
 *   @0x13e59c mov r1, #0
 *   @0x13e5a0 mov r0, r4
 *   @0x13e5a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e5a8 mov r1, #1
 *   @0x13e5ac mov r6, r0
 *   @0x13e5b0 mov r0, r4
 *   @0x13e5b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e5b8 mov r1, #2
 *   @0x13e5bc mov r7, r0
 *   @0x13e5c0 mov r0, r4
 *   @0x13e5c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e5c8 mov r1, #3
 *   @0x13e5cc mov r8, r0
 *   @0x13e5d0 mov r0, r4
 *   @0x13e5d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e5d8 mov r1, r6
 *   @0x13e5dc mov r4, r0
 *   @0x13e5e0 mov r0, r5
 *   @0x13e5e4 bl 0x192fec <_ZN9CInstance14SetImageScaleXEf>
 *   @0x13e5e8 mov r0, r5
 *   @0x13e5ec mov r1, r7
 *   @0x13e5f0 bl 0x193014 <_ZN9CInstance14SetImageScaleYEf>
 *   @0x13e5f4 mov r0, r5
 *   @0x13e5f8 mov r1, r8
 *   @0x13e5fc bl 0x19303c <_ZN9CInstance13SetImageAngleEf>
 *   @0x13e600 bic r3, r4, #2
 *   @0x13e604 cmp r3, #1
 *   @0x13e608 beq 0x13e628 <_Z23F_ActionSpriteTransformR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x13e60c sub r4, r4, #2
 *   @0x13e610 cmp r4, #1
 *   @0x13e614 pophi {r4, r5, r6, r7, r8, pc}
 *   @0x13e618 mov r0, r5
 *   @0x13e61c eor r1, r7, #-2147483648
 *   @0x13e620 pop {r4, r5, r6, r7, r8, lr}
 *   @0x13e624 b 0x193014 <_ZN9CInstance14SetImageScaleYEf>
 *   @0x13e628 eor r1, r6, #-2147483648
 *   @0x13e62c mov r0, r5
 *   @0x13e630 bl 0x192fec <_ZN9CInstance14SetImageScaleXEf>
 *   @0x13e634 b 0x13e60c <_Z23F_ActionSpriteTransformR6RValueP9CInstanceS2_iPS_+0x7c>
 *
 * ══ §51/181 F_ActionIfQuestion(RValue&, CInstance*, CInstance*, int, RValue*)  0x13ef84  size 168  42 条（0x13ef84..0x13f02c）
 * @func 0x13ef84 0x13f02c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / InputQuery::Question(char const*, char const*) / IO_Clear() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×4 / 0x98×1 / 0x4×1 / 0x20×1 / 0x-4×1 / 0x3c×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ef84 ldr r1, [pc, #0x98]
 *   @0x13ef88 mov r12, #16
 *   @0x13ef8c push {r4, r5, lr}
 *   @0x13ef90 sub sp, sp, #20
 *   @0x13ef94 mov r4, r0
 *   @0x13ef98 add r1, pc, r1
 *   @0x13ef9c mov r0, r12
 *   @0x13efa0 movw r2, #0x4d6
 *   @0x13efa4 mov r3, #1
 *   @0x13efa8 str r12, [sp, #0x4]
 *   @0x13efac ldr r5, [sp, #0x20]
 *   @0x13efb0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13efb4 add r1, sp, #8
 *   @0x13efb8 mov r3, r5
 *   @0x13efbc mov r5, #0
 *   @0x13efc0 mov r2, r0
 *   @0x13efc4 add r0, sp, #16
 *   @0x13efc8 str r2, [sp, #0x8]
 *   @0x13efcc str r2, [r0, #-0x4]!
 *   @0x13efd0 strb r5, [r2]
 *   @0x13efd4 add r2, sp, #4
 *   @0x13efd8 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x13efdc ldr r0, [sp, #0x8]
 *   @0x13efe0 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x13efe4 ldr r0, [pc, #0x3c]
 *   @0x13efe8 ldr r1, [sp, #0x8]
 *   @0x13efec str r5, [r4, #0xc]
 *   @0x13eff0 add r0, pc, r0
 *   @0x13eff4 bl 0xf29a4 <_ZN10InputQuery8QuestionEPKcS1_>
 *   @0x13eff8 vmov s15, r0
 *   @0x13effc vcvt.f64.s32 d7, s15
 *   @0x13f000 vmov r0, r1, d7
 *   @0x13f004 vmov r2, s14
 *   @0x13f008 mov r3, r1
 *   @0x13f00c stm r4, {r2, r3}
 *   @0x13f010 bl 0x18c2c8 <_Z8IO_Clearv>
 *   @0x13f014 ldr r0, [sp, #0x8]
 *   @0x13f018 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13f01c add sp, sp, #20
 *   @0x13f020 pop {r4, r5, pc}
 *   @0x13f024 eoreq r1, r0, r4, asr r9
 *   @0x13f028 andseq pc, lr, r6, asr #22
 *
 * ══ §52/181 F_ActionPartSystCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x13f8b4  size 168  42 条（0x13f8b4..0x13f95c）
 * @func 0x13f8b4 0x13f95c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_ActionPartSystCreate(RValue&, CInstance*, CInstance*, int, RValue*)+0x84 / ParticleSystem_Clear(int) / YYGetFloat(RValue const*, int) / ParticleSystem_Depth(int, float) / ParticleSystem_Create(int, bool)
 * 字段偏移 top8: 0x4×2 / 0x90×1 / 0x10×1 / 0x58×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13f8b4 push {r3, r4, r5, lr}
 *   @0x13f8b8 ldr r4, [pc, #0x90]
 *   @0x13f8bc ldr r5, [sp, #0x10]
 *   @0x13f8c0 ldr r4, [pc, r4]
 *   @0x13f8c4 ldr r3, [r4]
 *   @0x13f8c8 cmp r3, #0
 *   @0x13f8cc movge r0, r3
 *   @0x13f8d0 blt 0x13f938 <_Z22F_ActionPartSystCreateR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x13f8d4 bl 0x1a4180 <_Z20ParticleSystem_Cleari>
 *   @0x13f8d8 mov r1, #0
 *   @0x13f8dc mov r0, r5
 *   @0x13f8e0 ldr r4, [r4]
 *   @0x13f8e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f8e8 mov r1, r0
 *   @0x13f8ec mov r0, r4
 *   @0x13f8f0 bl 0x1a47d4 <_Z20ParticleSystem_Depthif>
 *   @0x13f8f4 ldr r2, [pc, #0x58]
 *   @0x13f8f8 mvn r1, #0
 *   @0x13f8fc ldr r2, [pc, r2]
 *   @0x13f900 sub r3, r2, #4
 *   @0x13f904 add r2, r2, #60
 *   @0x13f908 str r1, [r3, #0x4]!
 *   @0x13f90c cmp r3, r2
 *   @0x13f910 bne 0x13f908 <_Z22F_ActionPartSystCreateR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x13f914 ldr r2, [pc, #0x3c]
 *   @0x13f918 mvn r1, #0
 *   @0x13f91c ldr r2, [pc, r2]
 *   @0x13f920 sub r3, r2, #4
 *   @0x13f924 add r2, r2, #60
 *   @0x13f928 str r1, [r3, #0x4]!
 *   @0x13f92c cmp r3, r2
 *   @0x13f930 bne 0x13f928 <_Z22F_ActionPartSystCreateR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x13f934 pop {r3, r4, r5, pc}
 *   @0x13f938 mvn r0, #0
 *   @0x13f93c mov r1, #1
 *   @0x13f940 bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x13f944 mov r3, r0
 *   @0x13f948 str r3, [r4]
 *   @0x13f94c b 0x13f8d4 <_Z22F_ActionPartSystCreateR6RValueP9CInstanceS2_iPS_+0x20>
 *   @0x13f950 eoreq pc, r10, r12, lsl r11
 *   @0x13f954 eoreq pc, r10, r4, ror #21
 *   @0x13f958 eoreq pc, r10, r8, asr #21
 *
 * ══ §53/181 F_Push_GetFirstLocalNotification(RValue&, CInstance*, CInstance*, int, RValue*)  0x155834  size 168  42 条（0x155834..0x1558dc）
 * @func 0x155834 0x1558dc  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_Push_GetFirstLocalNotification(RValue&, CInstance*, CInstance*, int, RValue*)+0x68 / F_DsMapClear(RValue&, CInstance*, CInstance*, int, RValue*) / Push_GetLocalNotification(int, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x30×1 / 0x14×1 / 0x34×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x155834 push {r4, r5, r6, r8, r9, lr}
 *   @0x155838 sub sp, sp, #24
 *   @0x15583c mov r5, #0
 *   @0x155840 mov r4, r0
 *   @0x155844 str r5, [r0, #0xc]
 *   @0x155848 mov r3, r5
 *   @0x15584c str r5, [r0]
 *   @0x155850 movt r3, #0xbff0
 *   @0x155854 mov r1, r5
 *   @0x155858 str r3, [r0, #0x4]
 *   @0x15585c ldr r0, [sp, #0x30]
 *   @0x155860 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x155864 subs r6, r0, #0
 *   @0x155868 blt 0x15589c <_Z32F_Push_GetFirstLocalNotificationR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x15586c vmov s13, r6
 *   @0x155870 add r12, sp, #24
 *   @0x155874 mov r1, r5
 *   @0x155878 mov r2, r5
 *   @0x15587c vcvt.f64.s32 d7, s13
 *   @0x155880 mov r3, #1
 *   @0x155884 str r5, [sp, #0x14]
 *   @0x155888 vmov r8, r9, d7
 *   @0x15588c strd r8, r9, [r12, #-16]!
 *   @0x155890 mov r0, r12
 *   @0x155894 str r12, [sp]
 *   @0x155898 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_>
 *   @0x15589c ldr r2, [pc, #0x34]
 *   @0x1558a0 mov r3, #0
 *   @0x1558a4 mov r1, r6
 *   @0x1558a8 mov r0, r3
 *   @0x1558ac add r2, pc, r2
 *   @0x1558b0 str r3, [r2]
 *   @0x1558b4 bl 0x161c00 <_Z25Push_GetLocalNotificationii>
 *   @0x1558b8 vmov s15, r0
 *   @0x1558bc vcvt.f64.s32 d7, s15
 *   @0x1558c0 vmov r0, r1, d7
 *   @0x1558c4 vmov r2, s14
 *   @0x1558c8 mov r3, r1
 *   @0x1558cc stm r4, {r2, r3}
 *   @0x1558d0 add sp, sp, #24
 *   @0x1558d4 pop {r4, r5, r6, r8, r9, pc}
 *   @0x1558d8 eoreq r12, r9, r8, lsr #21
 *
 * ══ §54/181 F_Push_GetNextLocalNotification(RValue&, CInstance*, CInstance*, int, RValue*)  0x1558dc  size 168  42 条（0x1558dc..0x155984）
 * @func 0x1558dc 0x155984  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_Push_GetNextLocalNotification(RValue&, CInstance*, CInstance*, int, RValue*)+0x68 / F_DsMapClear(RValue&, CInstance*, CInstance*, int, RValue*) / Push_GetLocalNotification(int, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x30×1 / 0x14×1 / 0x34×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1558dc push {r4, r5, r6, r8, r9, lr}
 *   @0x1558e0 sub sp, sp, #24
 *   @0x1558e4 mov r5, #0
 *   @0x1558e8 mov r4, r0
 *   @0x1558ec str r5, [r0, #0xc]
 *   @0x1558f0 mov r3, r5
 *   @0x1558f4 str r5, [r0]
 *   @0x1558f8 movt r3, #0xbff0
 *   @0x1558fc mov r1, r5
 *   @0x155900 str r3, [r0, #0x4]
 *   @0x155904 ldr r0, [sp, #0x30]
 *   @0x155908 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15590c subs r6, r0, #0
 *   @0x155910 blt 0x155944 <_Z31F_Push_GetNextLocalNotificationR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x155914 vmov s13, r6
 *   @0x155918 add r12, sp, #24
 *   @0x15591c mov r1, r5
 *   @0x155920 mov r2, r5
 *   @0x155924 vcvt.f64.s32 d7, s13
 *   @0x155928 mov r3, #1
 *   @0x15592c str r5, [sp, #0x14]
 *   @0x155930 vmov r8, r9, d7
 *   @0x155934 strd r8, r9, [r12, #-16]!
 *   @0x155938 mov r0, r12
 *   @0x15593c str r12, [sp]
 *   @0x155940 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_>
 *   @0x155944 ldr r3, [pc, #0x34]
 *   @0x155948 mov r1, r6
 *   @0x15594c add r3, pc, r3
 *   @0x155950 ldr r0, [r3]
 *   @0x155954 add r0, r0, #1
 *   @0x155958 str r0, [r3]
 *   @0x15595c bl 0x161c00 <_Z25Push_GetLocalNotificationii>
 *   @0x155960 vmov s15, r0
 *   @0x155964 vcvt.f64.s32 d7, s15
 *   @0x155968 vmov r0, r1, d7
 *   @0x15596c vmov r2, s14
 *   @0x155970 mov r3, r1
 *   @0x155974 stm r4, {r2, r3}
 *   @0x155978 add sp, sp, #24
 *   @0x15597c pop {r4, r5, r6, r8, r9, pc}
 *   @0x155980 eoreq r12, r9, r8, lsl #20
 *
 * ══ §55/181 YYGML_draw_point(float, float)  0x16a0c0  size 168  42 条（0x16a0c0..0x16a168）
 * @func 0x16a0c0 0x16a168  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16a0d4→0x4859c0, 0x16a0f8→0x3f23d4, 0x16a0fc→0x3f23d8, 0x16a104→0x4859ac, 0x16a11c→0x3f23d0
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0x58×2 / 0x7c×1 / 0x78×1 / 0x54×1 / 0x40×1 / 0x8×1 / 0xc×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16a0c0 push {r4, lr}
 *   @0x16a0c4 vpush {d8}
 *   @0x16a0c8 vmov s17, r1
 *   @0x16a0cc ldr r4, [pc, #0x7c]
 *   @0x16a0d0 vmov s16, r0
 *   @0x16a0d4 ldr r12, [pc, #0x78]
 *   @0x16a0d8 mov r0, #1
 *   @0x16a0dc add r4, pc, r4
 *   @0x16a0e0 mov r3, r0
 *   @0x16a0e4 mov r2, #16
 *   @0x16a0e8 ldr r1, [r4, r12]
 *   @0x16a0ec ldr r1, [r1]
 *   @0x16a0f0 ldr r1, [r1]
 *   @0x16a0f4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16a0f8 ldr r1, [pc, #0x58]
 *   @0x16a0fc ldr r3, [pc, #0x58]
 *   @0x16a100 vldr s15, [pc, #68]
 *   @0x16a104 ldr r2, [pc, #0x54]
 *   @0x16a108 ldr r1, [r4, r1]
 *   @0x16a10c vldr s14, [r1]
 *   @0x16a110 ldr r3, [r4, r3]
 *   @0x16a114 vmla.f32 s17, s14, s15
 *   @0x16a118 vldr s14, [r3]
 *   @0x16a11c ldr r3, [pc, #0x40]
 *   @0x16a120 vmla.f32 s16, s14, s15
 *   @0x16a124 vstr s17, [r0, #4]
 *   @0x16a128 vstr s16, [r0]
 *   @0x16a12c ldr r2, [r4, r2]
 *   @0x16a130 vpop {d8}
 *   @0x16a134 ldr r2, [r2]
 *   @0x16a138 str r2, [r0, #0x8]
 *   @0x16a13c ldr r3, [r4, r3]
 *   @0x16a140 ldr r3, [r3]
 *   @0x16a144 str r3, [r0, #0xc]
 *   @0x16a148 pop {r4, pc}
 *   @0x16a14c stclo p7, c13, [r3], #-40
 *   @0x16a150 eoreq r7, r8, r4, ror r11
 *   @0x16a154 .word 0xffffe4e0
 *   @0x16a158 .word 0xffffe520
 *   @0x16a15c .word 0xffffe524
 *   @0x16a160 .word 0xffffbcd0
 *   @0x16a164 .word 0xffffc0ac
 *
 * ══ §56/181 CCamera::Update2D()  0x16d93c  size 168  42 条（0x16d93c..0x16d9e4）
 * @func 0x16d93c 0x16d9e4  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCamera::IsOrthoProj()
 * 字段偏移 top8: 0x1b8×1
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d93c push {r4, lr}
 *   @0x16d940 mov r4, r0
 *   @0x16d944 bl 0x16d380 <_ZN7CCamera11IsOrthoProjEv>
 *   @0x16d948 cmp r0, #0
 *   @0x16d94c beq 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c>
 *   @0x16d950 vldr s15, [r4, #20]
 *   @0x16d954 vcmp.f32 s15, #0
 *   @0x16d958 vmrs APSR_nzcv, fpscr
 *   @0x16d95c bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c>
 *   @0x16d960 vldr s15, [r4, #36]
 *   @0x16d964 vcmp.f32 s15, #0
 *   @0x16d968 vmrs APSR_nzcv, fpscr
 *   @0x16d96c bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c>
 *   @0x16d970 vldr s15, [r4, #8]
 *   @0x16d974 vcmp.f32 s15, #0
 *   @0x16d978 vmrs APSR_nzcv, fpscr
 *   @0x16d97c bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c>
 *   @0x16d980 vldr s15, [r4, #40]
 *   @0x16d984 vcmp.f32 s15, #0
 *   @0x16d988 vmrs APSR_nzcv, fpscr
 *   @0x16d98c bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c>
 *   @0x16d990 vldr s15, [r4, #12]
 *   @0x16d994 vcmp.f32 s15, #0
 *   @0x16d998 vmrs APSR_nzcv, fpscr
 *   @0x16d99c bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c>
 *   @0x16d9a0 vldr s15, [r4, #28]
 *   @0x16d9a4 vcmp.f32 s15, #0
 *   @0x16d9a8 vmrs APSR_nzcv, fpscr
 *   @0x16d9ac bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c>
 *   @0x16d9b0 vldr s15, [r4, #76]
 *   @0x16d9b4 vcmp.f32 s15, #0
 *   @0x16d9b8 vmrs APSR_nzcv, fpscr
 *   @0x16d9bc bne 0x16d9d8 <_ZN7CCamera8Update2DEv+0x9c>
 *   @0x16d9c0 vldr s15, [r4, #92]
 *   @0x16d9c4 vcmp.f32 s15, #0
 *   @0x16d9c8 vmrs APSR_nzcv, fpscr
 *   @0x16d9cc moveq r3, #1
 *   @0x16d9d0 strbeq r3, [r4, #0x1b8]
 *   @0x16d9d4 popeq {r4, pc}
 *   @0x16d9d8 mov r3, #0
 *   @0x16d9dc strb r3, [r4, #0x1b8]
 *   @0x16d9e0 pop {r4, pc}
 *
 * ══ §57/181 GR_3D_Vertex(float, float, float)  0x176e2c  size 168  42 条（0x176e2c..0x176ed4）
 * @func 0x176e2c 0x176ed4  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Vertex(float, float, float)+0x40 / HandleOverflow()
 * 字段偏移 top8: 0x84×1 / 0x80×1 / 0x7c×1 / 0x58×1 / 0x54×1 / 0x4×1 / 0x8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x176e2c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x176e30 mov r8, r1
 *   @0x176e34 ldr r4, [pc, #0x84]
 *   @0x176e38 mov r7, r0
 *   @0x176e3c ldr r3, [pc, #0x80]
 *   @0x176e40 mov r9, r2
 *   @0x176e44 ldr r1, [pc, #0x7c]
 *   @0x176e48 add r4, pc, r4
 *   @0x176e4c ldr r6, [r4, r3]
 *   @0x176e50 ldr r3, [r4, r1]
 *   @0x176e54 ldr r5, [r6]
 *   @0x176e58 ldr r3, [r3]
 *   @0x176e5c cmp r5, r3
 *   @0x176e60 blt 0x176e6c <_Z12GR_3D_Vertexfff+0x40>
 *   @0x176e64 bl 0x176bb0 <_Z14HandleOverflowv>
 *   @0x176e68 ldr r5, [r6]
 *   @0x176e6c ldr r3, [pc, #0x58]
 *   @0x176e70 add r1, r5, r5, lsl #3
 *   @0x176e74 ldr r2, [pc, #0x54]
 *   @0x176e78 mov r12, #0
 *   @0x176e7c add r5, r5, #1
 *   @0x176e80 ldr r3, [r4, r3]
 *   @0x176e84 add r3, r3, r1, lsl #2
 *   @0x176e88 str r7, [r3]
 *   @0x176e8c str r8, [r3, #0x4]
 *   @0x176e90 str r9, [r3, #0x8]
 *   @0x176e94 str r12, [r3, #0x14]
 *   @0x176e98 str r12, [r3, #0x10]
 *   @0x176e9c str r12, [r3, #0xc]
 *   @0x176ea0 ldr r2, [r4, r2]
 *   @0x176ea4 str r12, [r3, #0x1c]
 *   @0x176ea8 str r12, [r3, #0x20]
 *   @0x176eac ldr r2, [r2]
 *   @0x176eb0 str r5, [r6]
 *   @0x176eb4 bic r2, r2, #1
 *   @0x176eb8 str r2, [r3, #0x18]
 *   @0x176ebc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x176ec0 eoreq r10, r7, r8, lsl #28
 *   @0x176ec4 .word 0xffffe670
 *   @0x176ec8 .word 0xffffe67c
 *   @0x176ecc .word 0xffffe680
 *   @0x176ed0 .word 0xffffc0ac
 *
 * ══ §58/181 GR_3D_Vertex_Color(float, float, float, unsigned int, float)  0x176ed4  size 168  42 条（0x176ed4..0x176f7c）
 * @func 0x176ed4 0x176f7c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Vertex_Color(float, float, float, unsigned int, float)+0x3c / HandleOverflow() / ConvertAlpha(float) / GR_Color_To_D3DColor(unsigned int, unsigned int)
 * 字段偏移 top8: 0x20×2 / 0x8c×1 / 0x88×1 / 0x54×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x176ed4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x176ed8 mov r6, r2
 *   @0x176edc ldr r5, [pc, #0x8c]
 *   @0x176ee0 mov r9, r3
 *   @0x176ee4 ldr r12, [pc, #0x88]
 *   @0x176ee8 mov r8, r0
 *   @0x176eec ldr r5, [pc, r5]
 *   @0x176ef0 mov r7, r1
 *   @0x176ef4 ldr r12, [pc, r12]
 *   @0x176ef8 ldr r4, [sp, #0x20]
 *   @0x176efc ldr r2, [r5]
 *   @0x176f00 ldr r3, [r12]
 *   @0x176f04 cmp r2, r3
 *   @0x176f08 blt 0x176f10 <_Z18GR_3D_Vertex_Colorfffjf+0x3c>
 *   @0x176f0c bl 0x176bb0 <_Z14HandleOverflowv>
 *   @0x176f10 mov r0, r4
 *   @0x176f14 bl 0x16ca2c <_Z12ConvertAlphaf>
 *   @0x176f18 ldr r4, [r5]
 *   @0x176f1c ldr r12, [pc, #0x54]
 *   @0x176f20 add r4, r4, r4, lsl #3
 *   @0x176f24 ldr r12, [pc, r12]
 *   @0x176f28 add r4, r12, r4, lsl #2
 *   @0x176f2c str r8, [r4]
 *   @0x176f30 str r7, [r4, #0x4]
 *   @0x176f34 str r6, [r4, #0x8]
 *   @0x176f38 mov r1, r0
 *   @0x176f3c orr r0, r9, #1
 *   @0x176f40 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x176f44 ldr r2, [r5]
 *   @0x176f48 mov r3, #0
 *   @0x176f4c str r3, [r4, #0xc]
 *   @0x176f50 str r3, [r4, #0x10]
 *   @0x176f54 str r3, [r4, #0x14]
 *   @0x176f58 str r3, [r4, #0x1c]
 *   @0x176f5c str r3, [r4, #0x20]
 *   @0x176f60 add r3, r2, #1
 *   @0x176f64 str r3, [r5]
 *   @0x176f68 str r0, [r4, #0x18]
 *   @0x176f6c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x176f70 .word 0x002793d4
 *   @0x176f74 .word 0x002793d8
 *   @0x176f78 eoreq r9, r7, r12, lsr #7
 *
 * ══ §59/181 GraphicsPerf::Init()  0x17afa0  size 168  42 条（0x17afa0..0x17b048）
 * @func 0x17afa0 0x17b048  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17afb0→0x4a2020, 0x17afbc→0x499338, 0x17afc0→0x499330, 0x17afe4→0x49932c, 0x17afec→0x3f2484, 0x17aff0→0x3f26a8
 * 调用序列: RomDisk::LoadTexture(int)
 * 字段偏移 top8: 0x70×2 / 0x4c×2 / 0x7c×1 / 0x78×1 / 0x50×1 / 0x83×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17afa0 push {r3, r4, r5, lr}
 *   @0x17afa4 movw r12, #0x3555
 *   @0x17afa8 ldr r4, [pc, #0x7c]
 *   @0x17afac movt r12, #0x4782
 *   @0x17afb0 ldr r0, [pc, #0x78]
 *   @0x17afb4 mov r1, #0
 *   @0x17afb8 add r4, pc, r4
 *   @0x17afbc ldr r2, [pc, #0x70]
 *   @0x17afc0 ldr r3, [pc, #0x70]
 *   @0x17afc4 ldr r0, [r4, r0]
 *   @0x17afc8 str r12, [r0]
 *   @0x17afcc ldr r2, [r4, r2]
 *   @0x17afd0 str r1, [r2]
 *   @0x17afd4 ldr r5, [r4, r3]
 *   @0x17afd8 ldr r3, [r5]
 *   @0x17afdc cmp r3, r1
 *   @0x17afe0 beq 0x17b01c <_ZN12GraphicsPerf4InitEv+0x7c>
 *   @0x17afe4 ldr r1, [pc, #0x50]
 *   @0x17afe8 mov r0, #0
 *   @0x17afec ldr r2, [pc, #0x4c]
 *   @0x17aff0 ldr r3, [pc, #0x4c]
 *   @0x17aff4 ldr r1, [r4, r1]
 *   @0x17aff8 str r0, [r1]
 *   @0x17affc ldr r2, [r4, r2]
 *   @0x17b000 ldr r3, [r4, r3]
 *   @0x17b004 ldrb r2, [r2, #0x83]
 *   @0x17b008 add r2, r2, #2
 *   @0x17b00c vmov s14, r2
 *   @0x17b010 vcvt.f32.s32 s15, s14
 *   @0x17b014 vstr s15, [r3]
 *   @0x17b018 pop {r3, r4, r5, pc}
 *   @0x17b01c mov r0, #15
 *   @0x17b020 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi>
 *   @0x17b024 str r0, [r5]
 *   @0x17b028 b 0x17afe4 <_ZN12GraphicsPerf4InitEv+0x44>
 *   @0x17b02c mlaeq r7, r8, r12, r6
 *   @0x17b030 .word 0xffffe6d8
 *   @0x17b034 .word 0xffffe6dc
 *   @0x17b038 .word 0xffffe648
 *   @0x17b03c .word 0xffffe6e0
 *   @0x17b040 .word 0xffffe64c
 *   @0x17b044 .word 0xffffe6e4
 *
 * ══ §60/181 GetColumnsFromType(unsigned int)  0x186760  size 168  42 条（0x186760..0x186808）
 * @func 0x186760 0x186808  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetColumnsFromType(unsigned int)+0x38 / GetColumnsFromType(unsigned int)+0x80 / GetColumnsFromType(unsigned int)+0x78 / GetColumnsFromType(unsigned int)+0x60 / GetColumnsFromType(unsigned int)+0x30
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x186760 movw r3, #0x8b55
 *   @0x186764 cmp r0, r3
 *   @0x186768 beq 0x186790 <_Z18GetColumnsFromTypej+0x30>
 *   @0x18676c bls 0x186798 <_Z18GetColumnsFromTypej+0x38>
 *   @0x186770 movw r3, #0x8b59
 *   @0x186774 cmp r0, r3
 *   @0x186778 beq 0x186790 <_Z18GetColumnsFromTypej+0x30>
 *   @0x18677c bls 0x1867e0 <_Z18GetColumnsFromTypej+0x80>
 *   @0x186780 movw r3, #0x8b5b
 *   @0x186784 cmp r0, r3
 *   @0x186788 beq 0x1867b8 <_Z18GetColumnsFromTypej+0x58>
 *   @0x18678c blo 0x1867d8 <_Z18GetColumnsFromTypej+0x78>
 *   @0x186790 mov r0, #4
 *   @0x186794 bx lr
 *   @0x186798 movw r3, #0x8b51
 *   @0x18679c cmp r0, r3
 *   @0x1867a0 beq 0x1867b8 <_Z18GetColumnsFromTypej+0x58>
 *   @0x1867a4 bls 0x1867c0 <_Z18GetColumnsFromTypej+0x60>
 *   @0x1867a8 movw r3, #0x8b53
 *   @0x1867ac cmp r0, r3
 *   @0x1867b0 beq 0x1867d8 <_Z18GetColumnsFromTypej+0x78>
 *   @0x1867b4 bls 0x186790 <_Z18GetColumnsFromTypej+0x30>
 *   @0x1867b8 mov r0, #3
 *   @0x1867bc bx lr
 *   @0x1867c0 movw r3, #0x1406
 *   @0x1867c4 cmp r0, r3
 *   @0x1867c8 beq 0x1867f0 <_Z18GetColumnsFromTypej+0x90>
 *   @0x1867cc movw r3, #0x8b50
 *   @0x1867d0 cmp r0, r3
 *   @0x1867d4 bne 0x1867f8 <_Z18GetColumnsFromTypej+0x98>
 *   @0x1867d8 mov r0, #2
 *   @0x1867dc bx lr
 *   @0x1867e0 movw r3, #0x8b57
 *   @0x1867e4 cmp r0, r3
 *   @0x1867e8 beq 0x1867d8 <_Z18GetColumnsFromTypej+0x78>
 *   @0x1867ec bhi 0x1867b8 <_Z18GetColumnsFromTypej+0x58>
 *   @0x1867f0 mov r0, #1
 *   @0x1867f4 bx lr
 *   @0x1867f8 movw r3, #0x1404
 *   @0x1867fc cmp r0, r3
 *   @0x186800 bne 0x186790 <_Z18GetColumnsFromTypej+0x30>
 *   @0x186804 b 0x1867f0 <_Z18GetColumnsFromTypej+0x90>
 *
 * ══ §61/181 InEll(tagYYRECT*, int, int)  0x1949e8  size 168  42 条（0x1949e8..0x194a90）
 * @func 0x1949e8 0x194a90  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x-4×1 / 0x8×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1949e8 ldr r3, [r0, #0x4]
 *   @0x1949ec vmov s13, r2
 *   @0x1949f0 ldr r12, [r0, #0xc]
 *   @0x1949f4 vmov s15, r1
 *   @0x1949f8 str r4, [sp, #-0x4]!
 *   @0x1949fc add r4, r12, r3
 *   @0x194a00 vcvt.f64.s32 d0, s13
 *   @0x194a04 rsb r12, r3, r12
 *   @0x194a08 add r4, r4, r4, lsr #31
 *   @0x194a0c ldr r2, [r0, #0x8]
 *   @0x194a10 add r12, r12, r12, lsr #31
 *   @0x194a14 ldr r3, [r0]
 *   @0x194a18 asr r4, r4, #1
 *   @0x194a1c asr r12, r12, #1
 *   @0x194a20 add r0, r2, r3
 *   @0x194a24 vmov s13, r4
 *   @0x194a28 rsb r3, r3, r2
 *   @0x194a2c add r0, r0, r0, lsr #31
 *   @0x194a30 ldr r4, [sp], #4
 *   @0x194a34 vcvt.f64.s32 d1, s13
 *   @0x194a38 add r3, r3, r3, lsr #31
 *   @0x194a3c asr r0, r0, #1
 *   @0x194a40 asr r3, r3, #1
 *   @0x194a44 vmov s13, r0
 *   @0x194a48 vsub.f64 d1, d0, d1
 *   @0x194a4c vcvt.f64.s32 d3, s15
 *   @0x194a50 vmov s15, r12
 *   @0x194a54 vcvt.f64.s32 d2, s15
 *   @0x194a58 vcvt.f64.s32 d4, s13
 *   @0x194a5c vmov s13, r3
 *   @0x194a60 vdiv.f64 d7, d1, d2
 *   @0x194a64 vsub.f64 d4, d3, d4
 *   @0x194a68 vcvt.f64.s32 d5, s13
 *   @0x194a6c vdiv.f64 d6, d4, d5
 *   @0x194a70 vmul.f64 d7, d7, d7
 *   @0x194a74 vmla.f64 d7, d6, d6
 *   @0x194a78 vmov.f64 d6, #1.000000e+00
 *   @0x194a7c vcmpe.f64 d7, d6
 *   @0x194a80 vmrs APSR_nzcv, fpscr
 *   @0x194a84 movhi r0, #0
 *   @0x194a88 movls r0, #1
 *   @0x194a8c bx lr
 *
 * ══ §62/181 ObjectPool<CLayerBackgroundElement>::~ObjectPool()  0x1b5f44  size 168  42 条（0x1b5f44..0x1b5fec）
 * @func 0x1b5f44 0x1b5fec  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / operator delete(void*)
 * 字段偏移 top8: 0x14×4 / 0xc×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5f44 push {r3, r4, r5, lr}
 *   @0x1b5f48 mov r5, r0
 *   @0x1b5f4c ldr r3, [r0, #0xc]
 *   @0x1b5f50 cmp r3, #0
 *   @0x1b5f54 beq 0x1b5f8c <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x48>
 *   @0x1b5f58 ldr r0, [r0]
 *   @0x1b5f5c cmp r0, #0
 *   @0x1b5f60 beq 0x1b5f8c <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x48>
 *   @0x1b5f64 cmp r3, #2
 *   @0x1b5f68 beq 0x1b5fa4 <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x60>
 *   @0x1b5f6c cmp r3, #3
 *   @0x1b5f70 beq 0x1b5fbc <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x78>
 *   @0x1b5f74 cmp r3, #1
 *   @0x1b5f78 beq 0x1b5fd4 <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x90>
 *   @0x1b5f7c ldr r4, [r0, #0x14]
 *   @0x1b5f80 cmp r4, #0
 *   @0x1b5f84 mov r0, r4
 *   @0x1b5f88 bne 0x1b5f7c <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x38>
 *   @0x1b5f8c mov r3, #0
 *   @0x1b5f90 mov r0, r5
 *   @0x1b5f94 str r3, [r5, #0x8]
 *   @0x1b5f98 str r3, [r5, #0x4]
 *   @0x1b5f9c str r3, [r5]
 *   @0x1b5fa0 pop {r3, r4, r5, pc}
 *   @0x1b5fa4 ldr r4, [r0, #0x14]
 *   @0x1b5fa8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b5fac cmp r4, #0
 *   @0x1b5fb0 mov r0, r4
 *   @0x1b5fb4 bne 0x1b5fa4 <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x60>
 *   @0x1b5fb8 b 0x1b5f8c <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x48>
 *   @0x1b5fbc ldr r4, [r0, #0x14]
 *   @0x1b5fc0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b5fc4 cmp r4, #0
 *   @0x1b5fc8 mov r0, r4
 *   @0x1b5fcc bne 0x1b5fbc <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x78>
 *   @0x1b5fd0 b 0x1b5f8c <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x48>
 *   @0x1b5fd4 ldr r4, [r0, #0x14]
 *   @0x1b5fd8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b5fdc cmp r4, #0
 *   @0x1b5fe0 mov r0, r4
 *   @0x1b5fe4 bne 0x1b5fd4 <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x90>
 *   @0x1b5fe8 b 0x1b5f8c <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0x48>
 *
 * ══ §63/181 ObjectPool<CLayerInstanceElement>::~ObjectPool()  0x1b5fec  size 168  42 条（0x1b5fec..0x1b6094）
 * @func 0x1b5fec 0x1b6094  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / operator delete(void*)
 * 字段偏移 top8: 0x14×4 / 0xc×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5fec push {r3, r4, r5, lr}
 *   @0x1b5ff0 mov r5, r0
 *   @0x1b5ff4 ldr r3, [r0, #0xc]
 *   @0x1b5ff8 cmp r3, #0
 *   @0x1b5ffc beq 0x1b6034 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x48>
 *   @0x1b6000 ldr r0, [r0]
 *   @0x1b6004 cmp r0, #0
 *   @0x1b6008 beq 0x1b6034 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x48>
 *   @0x1b600c cmp r3, #2
 *   @0x1b6010 beq 0x1b604c <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x60>
 *   @0x1b6014 cmp r3, #3
 *   @0x1b6018 beq 0x1b6064 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x78>
 *   @0x1b601c cmp r3, #1
 *   @0x1b6020 beq 0x1b607c <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x90>
 *   @0x1b6024 ldr r4, [r0, #0x14]
 *   @0x1b6028 cmp r4, #0
 *   @0x1b602c mov r0, r4
 *   @0x1b6030 bne 0x1b6024 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x38>
 *   @0x1b6034 mov r3, #0
 *   @0x1b6038 mov r0, r5
 *   @0x1b603c str r3, [r5, #0x8]
 *   @0x1b6040 str r3, [r5, #0x4]
 *   @0x1b6044 str r3, [r5]
 *   @0x1b6048 pop {r3, r4, r5, pc}
 *   @0x1b604c ldr r4, [r0, #0x14]
 *   @0x1b6050 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6054 cmp r4, #0
 *   @0x1b6058 mov r0, r4
 *   @0x1b605c bne 0x1b604c <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x60>
 *   @0x1b6060 b 0x1b6034 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x48>
 *   @0x1b6064 ldr r4, [r0, #0x14]
 *   @0x1b6068 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b606c cmp r4, #0
 *   @0x1b6070 mov r0, r4
 *   @0x1b6074 bne 0x1b6064 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x78>
 *   @0x1b6078 b 0x1b6034 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x48>
 *   @0x1b607c ldr r4, [r0, #0x14]
 *   @0x1b6080 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b6084 cmp r4, #0
 *   @0x1b6088 mov r0, r4
 *   @0x1b608c bne 0x1b607c <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x90>
 *   @0x1b6090 b 0x1b6034 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x48>
 *
 * ══ §64/181 ObjectPool<CLayerSpriteElement>::~ObjectPool()  0x1b6094  size 168  42 条（0x1b6094..0x1b613c）
 * @func 0x1b6094 0x1b613c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / operator delete(void*)
 * 字段偏移 top8: 0x14×4 / 0xc×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b6094 push {r3, r4, r5, lr}
 *   @0x1b6098 mov r5, r0
 *   @0x1b609c ldr r3, [r0, #0xc]
 *   @0x1b60a0 cmp r3, #0
 *   @0x1b60a4 beq 0x1b60dc <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x48>
 *   @0x1b60a8 ldr r0, [r0]
 *   @0x1b60ac cmp r0, #0
 *   @0x1b60b0 beq 0x1b60dc <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x48>
 *   @0x1b60b4 cmp r3, #2
 *   @0x1b60b8 beq 0x1b60f4 <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x60>
 *   @0x1b60bc cmp r3, #3
 *   @0x1b60c0 beq 0x1b610c <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x78>
 *   @0x1b60c4 cmp r3, #1
 *   @0x1b60c8 beq 0x1b6124 <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x90>
 *   @0x1b60cc ldr r4, [r0, #0x14]
 *   @0x1b60d0 cmp r4, #0
 *   @0x1b60d4 mov r0, r4
 *   @0x1b60d8 bne 0x1b60cc <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x38>
 *   @0x1b60dc mov r3, #0
 *   @0x1b60e0 mov r0, r5
 *   @0x1b60e4 str r3, [r5, #0x8]
 *   @0x1b60e8 str r3, [r5, #0x4]
 *   @0x1b60ec str r3, [r5]
 *   @0x1b60f0 pop {r3, r4, r5, pc}
 *   @0x1b60f4 ldr r4, [r0, #0x14]
 *   @0x1b60f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b60fc cmp r4, #0
 *   @0x1b6100 mov r0, r4
 *   @0x1b6104 bne 0x1b60f4 <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x60>
 *   @0x1b6108 b 0x1b60dc <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x48>
 *   @0x1b610c ldr r4, [r0, #0x14]
 *   @0x1b6110 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6114 cmp r4, #0
 *   @0x1b6118 mov r0, r4
 *   @0x1b611c bne 0x1b610c <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x78>
 *   @0x1b6120 b 0x1b60dc <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x48>
 *   @0x1b6124 ldr r4, [r0, #0x14]
 *   @0x1b6128 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b612c cmp r4, #0
 *   @0x1b6130 mov r0, r4
 *   @0x1b6134 bne 0x1b6124 <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x90>
 *   @0x1b6138 b 0x1b60dc <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x48>
 *
 * ══ §65/181 ObjectPool<CLayerTilemapElement>::~ObjectPool()  0x1b613c  size 168  42 条（0x1b613c..0x1b61e4）
 * @func 0x1b613c 0x1b61e4  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / operator delete(void*)
 * 字段偏移 top8: 0x14×4 / 0xc×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b613c push {r3, r4, r5, lr}
 *   @0x1b6140 mov r5, r0
 *   @0x1b6144 ldr r3, [r0, #0xc]
 *   @0x1b6148 cmp r3, #0
 *   @0x1b614c beq 0x1b6184 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x48>
 *   @0x1b6150 ldr r0, [r0]
 *   @0x1b6154 cmp r0, #0
 *   @0x1b6158 beq 0x1b6184 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x48>
 *   @0x1b615c cmp r3, #2
 *   @0x1b6160 beq 0x1b619c <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x60>
 *   @0x1b6164 cmp r3, #3
 *   @0x1b6168 beq 0x1b61b4 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x78>
 *   @0x1b616c cmp r3, #1
 *   @0x1b6170 beq 0x1b61cc <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x90>
 *   @0x1b6174 ldr r4, [r0, #0x14]
 *   @0x1b6178 cmp r4, #0
 *   @0x1b617c mov r0, r4
 *   @0x1b6180 bne 0x1b6174 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x38>
 *   @0x1b6184 mov r3, #0
 *   @0x1b6188 mov r0, r5
 *   @0x1b618c str r3, [r5, #0x8]
 *   @0x1b6190 str r3, [r5, #0x4]
 *   @0x1b6194 str r3, [r5]
 *   @0x1b6198 pop {r3, r4, r5, pc}
 *   @0x1b619c ldr r4, [r0, #0x14]
 *   @0x1b61a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b61a4 cmp r4, #0
 *   @0x1b61a8 mov r0, r4
 *   @0x1b61ac bne 0x1b619c <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x60>
 *   @0x1b61b0 b 0x1b6184 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x48>
 *   @0x1b61b4 ldr r4, [r0, #0x14]
 *   @0x1b61b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b61bc cmp r4, #0
 *   @0x1b61c0 mov r0, r4
 *   @0x1b61c4 bne 0x1b61b4 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x78>
 *   @0x1b61c8 b 0x1b6184 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x48>
 *   @0x1b61cc ldr r4, [r0, #0x14]
 *   @0x1b61d0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b61d4 cmp r4, #0
 *   @0x1b61d8 mov r0, r4
 *   @0x1b61dc bne 0x1b61cc <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x90>
 *   @0x1b61e0 b 0x1b6184 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x48>
 *
 * ══ §66/181 ObjectPool<CLayerParticleElement>::~ObjectPool()  0x1b61e4  size 168  42 条（0x1b61e4..0x1b628c）
 * @func 0x1b61e4 0x1b628c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / operator delete(void*)
 * 字段偏移 top8: 0x14×4 / 0xc×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b61e4 push {r3, r4, r5, lr}
 *   @0x1b61e8 mov r5, r0
 *   @0x1b61ec ldr r3, [r0, #0xc]
 *   @0x1b61f0 cmp r3, #0
 *   @0x1b61f4 beq 0x1b622c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x48>
 *   @0x1b61f8 ldr r0, [r0]
 *   @0x1b61fc cmp r0, #0
 *   @0x1b6200 beq 0x1b622c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x48>
 *   @0x1b6204 cmp r3, #2
 *   @0x1b6208 beq 0x1b6244 <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x60>
 *   @0x1b620c cmp r3, #3
 *   @0x1b6210 beq 0x1b625c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x78>
 *   @0x1b6214 cmp r3, #1
 *   @0x1b6218 beq 0x1b6274 <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x90>
 *   @0x1b621c ldr r4, [r0, #0x14]
 *   @0x1b6220 cmp r4, #0
 *   @0x1b6224 mov r0, r4
 *   @0x1b6228 bne 0x1b621c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x38>
 *   @0x1b622c mov r3, #0
 *   @0x1b6230 mov r0, r5
 *   @0x1b6234 str r3, [r5, #0x8]
 *   @0x1b6238 str r3, [r5, #0x4]
 *   @0x1b623c str r3, [r5]
 *   @0x1b6240 pop {r3, r4, r5, pc}
 *   @0x1b6244 ldr r4, [r0, #0x14]
 *   @0x1b6248 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b624c cmp r4, #0
 *   @0x1b6250 mov r0, r4
 *   @0x1b6254 bne 0x1b6244 <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x60>
 *   @0x1b6258 b 0x1b622c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x48>
 *   @0x1b625c ldr r4, [r0, #0x14]
 *   @0x1b6260 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6264 cmp r4, #0
 *   @0x1b6268 mov r0, r4
 *   @0x1b626c bne 0x1b625c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x78>
 *   @0x1b6270 b 0x1b622c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x48>
 *   @0x1b6274 ldr r4, [r0, #0x14]
 *   @0x1b6278 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b627c cmp r4, #0
 *   @0x1b6280 mov r0, r4
 *   @0x1b6284 bne 0x1b6274 <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x90>
 *   @0x1b6288 b 0x1b622c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x48>
 *
 * ══ §67/181 ObjectPool<CLayerTileElement>::~ObjectPool()  0x1b628c  size 168  42 条（0x1b628c..0x1b6334）
 * @func 0x1b628c 0x1b6334  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / operator delete(void*)
 * 字段偏移 top8: 0x14×4 / 0xc×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b628c push {r3, r4, r5, lr}
 *   @0x1b6290 mov r5, r0
 *   @0x1b6294 ldr r3, [r0, #0xc]
 *   @0x1b6298 cmp r3, #0
 *   @0x1b629c beq 0x1b62d4 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x48>
 *   @0x1b62a0 ldr r0, [r0]
 *   @0x1b62a4 cmp r0, #0
 *   @0x1b62a8 beq 0x1b62d4 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x48>
 *   @0x1b62ac cmp r3, #2
 *   @0x1b62b0 beq 0x1b62ec <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x60>
 *   @0x1b62b4 cmp r3, #3
 *   @0x1b62b8 beq 0x1b6304 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x78>
 *   @0x1b62bc cmp r3, #1
 *   @0x1b62c0 beq 0x1b631c <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x90>
 *   @0x1b62c4 ldr r4, [r0, #0x14]
 *   @0x1b62c8 cmp r4, #0
 *   @0x1b62cc mov r0, r4
 *   @0x1b62d0 bne 0x1b62c4 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x38>
 *   @0x1b62d4 mov r3, #0
 *   @0x1b62d8 mov r0, r5
 *   @0x1b62dc str r3, [r5, #0x8]
 *   @0x1b62e0 str r3, [r5, #0x4]
 *   @0x1b62e4 str r3, [r5]
 *   @0x1b62e8 pop {r3, r4, r5, pc}
 *   @0x1b62ec ldr r4, [r0, #0x14]
 *   @0x1b62f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b62f4 cmp r4, #0
 *   @0x1b62f8 mov r0, r4
 *   @0x1b62fc bne 0x1b62ec <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x60>
 *   @0x1b6300 b 0x1b62d4 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x48>
 *   @0x1b6304 ldr r4, [r0, #0x14]
 *   @0x1b6308 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b630c cmp r4, #0
 *   @0x1b6310 mov r0, r4
 *   @0x1b6314 bne 0x1b6304 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x78>
 *   @0x1b6318 b 0x1b62d4 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x48>
 *   @0x1b631c ldr r4, [r0, #0x14]
 *   @0x1b6320 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b6324 cmp r4, #0
 *   @0x1b6328 mov r0, r4
 *   @0x1b632c bne 0x1b631c <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x90>
 *   @0x1b6330 b 0x1b62d4 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x48>
 *
 * ══ §68/181 ObjectPool<CTileSlab>::~ObjectPool()  0x1b69f4  size 168  42 条（0x1b69f4..0x1b6a9c）
 * @func 0x1b69f4 0x1b6a9c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / operator delete(void*)
 * 字段偏移 top8: 0x704×4 / 0xc×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b69f4 push {r3, r4, r5, lr}
 *   @0x1b69f8 mov r5, r0
 *   @0x1b69fc ldr r3, [r0, #0xc]
 *   @0x1b6a00 cmp r3, #0
 *   @0x1b6a04 beq 0x1b6a3c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x48>
 *   @0x1b6a08 ldr r0, [r0]
 *   @0x1b6a0c cmp r0, #0
 *   @0x1b6a10 beq 0x1b6a3c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x48>
 *   @0x1b6a14 cmp r3, #2
 *   @0x1b6a18 beq 0x1b6a54 <_ZN10ObjectPoolI9CTileSlabED2Ev+0x60>
 *   @0x1b6a1c cmp r3, #3
 *   @0x1b6a20 beq 0x1b6a6c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x78>
 *   @0x1b6a24 cmp r3, #1
 *   @0x1b6a28 beq 0x1b6a84 <_ZN10ObjectPoolI9CTileSlabED2Ev+0x90>
 *   @0x1b6a2c ldr r4, [r0, #0x704]
 *   @0x1b6a30 cmp r4, #0
 *   @0x1b6a34 mov r0, r4
 *   @0x1b6a38 bne 0x1b6a2c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x38>
 *   @0x1b6a3c mov r3, #0
 *   @0x1b6a40 mov r0, r5
 *   @0x1b6a44 str r3, [r5, #0x8]
 *   @0x1b6a48 str r3, [r5, #0x4]
 *   @0x1b6a4c str r3, [r5]
 *   @0x1b6a50 pop {r3, r4, r5, pc}
 *   @0x1b6a54 ldr r4, [r0, #0x704]
 *   @0x1b6a58 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6a5c cmp r4, #0
 *   @0x1b6a60 mov r0, r4
 *   @0x1b6a64 bne 0x1b6a54 <_ZN10ObjectPoolI9CTileSlabED2Ev+0x60>
 *   @0x1b6a68 b 0x1b6a3c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x48>
 *   @0x1b6a6c ldr r4, [r0, #0x704]
 *   @0x1b6a70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b6a74 cmp r4, #0
 *   @0x1b6a78 mov r0, r4
 *   @0x1b6a7c bne 0x1b6a6c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x78>
 *   @0x1b6a80 b 0x1b6a3c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x48>
 *   @0x1b6a84 ldr r4, [r0, #0x704]
 *   @0x1b6a88 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b6a8c cmp r4, #0
 *   @0x1b6a90 mov r0, r4
 *   @0x1b6a94 bne 0x1b6a84 <_ZN10ObjectPoolI9CTileSlabED2Ev+0x90>
 *   @0x1b6a98 b 0x1b6a3c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x48>
 *
 * ══ §69/181 F_LayerBackgroundGetHtiled(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bcb64  size 168  42 条（0x1bcb64..0x1bcc0c）
 * @func 0x1bcb64 0x1bcc0c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x70×1 / 0x1c×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bcb64 cmp r3, #1
 *   @0x1bcb68 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bcb6c mov r3, #0
 *   @0x1bcb70 mov r4, r3
 *   @0x1bcb74 mov r5, r0
 *   @0x1bcb78 movt r3, #0xbff0
 *   @0x1bcb7c str r4, [r0, #0xc]
 *   @0x1bcb80 str r3, [r0, #0x4]
 *   @0x1bcb84 str r4, [r0]
 *   @0x1bcb88 ldr r6, [sp, #0x18]
 *   @0x1bcb8c beq 0x1bcba4 <_Z26F_LayerBackgroundGetHtiledR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bcb90 ldr r0, [pc, #0x70]
 *   @0x1bcb94 mov r1, r4
 *   @0x1bcb98 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bcb9c add r0, pc, r0
 *   @0x1bcba0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bcba4 str r4, [r0]
 *   @0x1bcba8 str r4, [r0, #0x4]
 *   @0x1bcbac bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bcbb0 mov r1, r4
 *   @0x1bcbb4 mov r7, r0
 *   @0x1bcbb8 mov r0, r6
 *   @0x1bcbbc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bcbc0 mov r2, r4
 *   @0x1bcbc4 mov r1, r0
 *   @0x1bcbc8 mov r0, r7
 *   @0x1bcbcc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bcbd0 cmp r0, #0
 *   @0x1bcbd4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcbd8 ldr r3, [r0]
 *   @0x1bcbdc cmp r3, #1
 *   @0x1bcbe0 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bcbe4 ldr r3, [r0, #0x1c]
 *   @0x1bcbe8 cmp r3, #0
 *   @0x1bcbec popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcbf0 ldrb r2, [r3, #0x8]
 *   @0x1bcbf4 vmov s15, r2
 *   @0x1bcbf8 vcvt.f64.u32 d7, s15
 *   @0x1bcbfc vmov r2, r3, d7
 *   @0x1bcc00 stm r5, {r2, r3}
 *   @0x1bcc04 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bcc08 mulseq r9, r8, r5
 *
 * ══ §70/181 F_LayerBackgroundGetVtiled(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bcc0c  size 168  42 条（0x1bcc0c..0x1bccb4）
 * @func 0x1bcc0c 0x1bccb4  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x70×1 / 0x1c×1 / 0x9×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bcc0c cmp r3, #1
 *   @0x1bcc10 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bcc14 mov r3, #0
 *   @0x1bcc18 mov r4, r3
 *   @0x1bcc1c mov r5, r0
 *   @0x1bcc20 movt r3, #0xbff0
 *   @0x1bcc24 str r4, [r0, #0xc]
 *   @0x1bcc28 str r3, [r0, #0x4]
 *   @0x1bcc2c str r4, [r0]
 *   @0x1bcc30 ldr r6, [sp, #0x18]
 *   @0x1bcc34 beq 0x1bcc4c <_Z26F_LayerBackgroundGetVtiledR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bcc38 ldr r0, [pc, #0x70]
 *   @0x1bcc3c mov r1, r4
 *   @0x1bcc40 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bcc44 add r0, pc, r0
 *   @0x1bcc48 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bcc4c str r4, [r0]
 *   @0x1bcc50 str r4, [r0, #0x4]
 *   @0x1bcc54 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bcc58 mov r1, r4
 *   @0x1bcc5c mov r7, r0
 *   @0x1bcc60 mov r0, r6
 *   @0x1bcc64 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bcc68 mov r2, r4
 *   @0x1bcc6c mov r1, r0
 *   @0x1bcc70 mov r0, r7
 *   @0x1bcc74 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bcc78 cmp r0, #0
 *   @0x1bcc7c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcc80 ldr r3, [r0]
 *   @0x1bcc84 cmp r3, #1
 *   @0x1bcc88 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bcc8c ldr r3, [r0, #0x1c]
 *   @0x1bcc90 cmp r3, #0
 *   @0x1bcc94 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcc98 ldrb r2, [r3, #0x9]
 *   @0x1bcc9c vmov s15, r2
 *   @0x1bcca0 vcvt.f64.u32 d7, s15
 *   @0x1bcca4 vmov r2, r3, d7
 *   @0x1bcca8 stm r5, {r2, r3}
 *   @0x1bccac pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bccb0 andseq r1, r9, r12, lsr #10
 *
 * ══ §71/181 F_LayerBackgroundGetStretch(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bccb4  size 168  42 条（0x1bccb4..0x1bcd5c）
 * @func 0x1bccb4 0x1bcd5c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x70×1 / 0x1c×1 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bccb4 cmp r3, #1
 *   @0x1bccb8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bccbc mov r3, #0
 *   @0x1bccc0 mov r4, r3
 *   @0x1bccc4 mov r5, r0
 *   @0x1bccc8 movt r3, #0xbff0
 *   @0x1bcccc str r4, [r0, #0xc]
 *   @0x1bccd0 str r3, [r0, #0x4]
 *   @0x1bccd4 str r4, [r0]
 *   @0x1bccd8 ldr r6, [sp, #0x18]
 *   @0x1bccdc beq 0x1bccf4 <_Z27F_LayerBackgroundGetStretchR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bcce0 ldr r0, [pc, #0x70]
 *   @0x1bcce4 mov r1, r4
 *   @0x1bcce8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bccec add r0, pc, r0
 *   @0x1bccf0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bccf4 str r4, [r0]
 *   @0x1bccf8 str r4, [r0, #0x4]
 *   @0x1bccfc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bcd00 mov r1, r4
 *   @0x1bcd04 mov r7, r0
 *   @0x1bcd08 mov r0, r6
 *   @0x1bcd0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bcd10 mov r2, r4
 *   @0x1bcd14 mov r1, r0
 *   @0x1bcd18 mov r0, r7
 *   @0x1bcd1c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bcd20 cmp r0, #0
 *   @0x1bcd24 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcd28 ldr r3, [r0]
 *   @0x1bcd2c cmp r3, #1
 *   @0x1bcd30 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bcd34 ldr r3, [r0, #0x1c]
 *   @0x1bcd38 cmp r3, #0
 *   @0x1bcd3c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcd40 ldrb r2, [r3, #0x14]
 *   @0x1bcd44 vmov s15, r2
 *   @0x1bcd48 vcvt.f64.u32 d7, s15
 *   @0x1bcd4c vmov r2, r3, d7
 *   @0x1bcd50 stm r5, {r2, r3}
 *   @0x1bcd54 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bcd58 andseq r1, r9, r0, asr #9
 *
 * ══ §72/181 F_LayerBackgroundGetBlend(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bceb4  size 168  42 条（0x1bceb4..0x1bcf5c）
 * @func 0x1bceb4 0x1bcf5c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0x18×2 / 0xc×1 / 0x70×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bceb4 cmp r3, #1
 *   @0x1bceb8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bcebc mov r3, #0
 *   @0x1bcec0 mov r4, r3
 *   @0x1bcec4 mov r5, r0
 *   @0x1bcec8 movt r3, #0xbff0
 *   @0x1bcecc str r4, [r0, #0xc]
 *   @0x1bced0 str r3, [r0, #0x4]
 *   @0x1bced4 str r4, [r0]
 *   @0x1bced8 ldr r6, [sp, #0x18]
 *   @0x1bcedc beq 0x1bcef4 <_Z25F_LayerBackgroundGetBlendR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bcee0 ldr r0, [pc, #0x70]
 *   @0x1bcee4 mov r1, r4
 *   @0x1bcee8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bceec add r0, pc, r0
 *   @0x1bcef0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bcef4 str r4, [r0]
 *   @0x1bcef8 str r4, [r0, #0x4]
 *   @0x1bcefc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bcf00 mov r1, r4
 *   @0x1bcf04 mov r7, r0
 *   @0x1bcf08 mov r0, r6
 *   @0x1bcf0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bcf10 mov r2, r4
 *   @0x1bcf14 mov r1, r0
 *   @0x1bcf18 mov r0, r7
 *   @0x1bcf1c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bcf20 cmp r0, #0
 *   @0x1bcf24 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcf28 ldr r3, [r0]
 *   @0x1bcf2c cmp r3, #1
 *   @0x1bcf30 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bcf34 ldr r3, [r0, #0x1c]
 *   @0x1bcf38 cmp r3, #0
 *   @0x1bcf3c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcf40 ldr r2, [r3, #0x18]
 *   @0x1bcf44 vmov s15, r2
 *   @0x1bcf48 vcvt.f64.s32 d7, s15
 *   @0x1bcf4c vmov r2, r3, d7
 *   @0x1bcf50 stm r5, {r2, r3}
 *   @0x1bcf54 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bcf58 andseq r1, r9, r4, ror r3
 *
 * ══ §73/181 collisionResult(CInstance*, void*)  0x1cbf18  size 168  42 条（0x1cbf18..0x1cbfc0）
 * @func 0x1cbf18 0x1cbfc0  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CObjectGM::GetEventRecursive(int, int)×2 / push_back(SCollision)
 * 字段偏移 top8: 0x80×4 / 0x18×2 / 0x98×1 / 0x54×1 / 0x188×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cbf18 ldr r3, [pc, #0x98]
 *   @0x1cbf1c cmp r0, r1
 *   @0x1cbf20 push {r4, r5, lr}
 *   @0x1cbf24 ldr r3, [pc, r3]
 *   @0x1cbf28 sub sp, sp, #12
 *   @0x1cbf2c mov r4, r0
 *   @0x1cbf30 ldr r2, [r3]
 *   @0x1cbf34 mov r5, r1
 *   @0x1cbf38 add r2, r2, #1
 *   @0x1cbf3c str r2, [r3]
 *   @0x1cbf40 beq 0x1cbf8c <_Z15collisionResultP9CInstancePv+0x74>
 *   @0x1cbf44 ldr r3, [r0, #0x80]
 *   @0x1cbf48 mov r1, #4
 *   @0x1cbf4c ldr r0, [r5, #0x80]
 *   @0x1cbf50 ldr r2, [r3, #0x18]
 *   @0x1cbf54 bl 0x19daf4 <_ZN9CObjectGM17GetEventRecursiveEii>
 *   @0x1cbf58 cmp r0, #0
 *   @0x1cbf5c beq 0x1cbf98 <_Z15collisionResultP9CInstancePv+0x80>
 *   @0x1cbf60 ldr r3, [pc, #0x54]
 *   @0x1cbf64 ldr r2, [r4, #0x188]
 *   @0x1cbf68 add r3, pc, r3
 *   @0x1cbf6c ldr r3, [r3, #0xc]
 *   @0x1cbf70 cmp r2, r3
 *   @0x1cbf74 beq 0x1cbf8c <_Z15collisionResultP9CInstancePv+0x74>
 *   @0x1cbf78 add r3, sp, #8
 *   @0x1cbf7c str r5, [sp]
 *   @0x1cbf80 str r4, [sp, #0x4]
 *   @0x1cbf84 ldmdb r3, {r0, r1}
 *   @0x1cbf88 bl 0x1cbe74 <_Z9push_back10SCollision>
 *   @0x1cbf8c mov r0, #1
 *   @0x1cbf90 add sp, sp, #12
 *   @0x1cbf94 pop {r4, r5, pc}
 *   @0x1cbf98 ldr r3, [r5, #0x80]
 *   @0x1cbf9c mov r1, #4
 *   @0x1cbfa0 ldr r0, [r4, #0x80]
 *   @0x1cbfa4 ldr r2, [r3, #0x18]
 *   @0x1cbfa8 bl 0x19daf4 <_ZN9CObjectGM17GetEventRecursiveEii>
 *   @0x1cbfac cmp r0, #0
 *   @0x1cbfb0 bne 0x1cbf60 <_Z15collisionResultP9CInstancePv+0x48>
 *   @0x1cbfb4 b 0x1cbf8c <_Z15collisionResultP9CInstancePv+0x74>
 *   @0x1cbfb8 eoreq r4, r2, r12, lsl #24
 *   @0x1cbfbc eorseq r6, r7, r8, lsr #20
 *
 * ══ §74/181 ConvertRawPos(float, float, int, float&, float&, float&, float&)  0x1d9864  size 168  42 条（0x1d9864..0x1d990c）
 * @func 0x1d9864 0x1d990c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_View_Convert(int, int, int, int&, int&) / ConvertRawToGUI(float, float, float&, float&) / GR_Window_Views_Convert(int, int, int&, int&)
 * 字段偏移 top8: 0x30×1 / 0x34×1 / 0x38×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d9864 push {r4, r5, r6, r7, lr}
 *   @0x1d9868 vpush {d8}
 *   @0x1d986c cmn r2, #1
 *   @0x1d9870 sub sp, sp, #20
 *   @0x1d9874 mov r7, r3
 *   @0x1d9878 vmov s17, r0
 *   @0x1d987c vmov s16, r1
 *   @0x1d9880 ldr r4, [sp, #0x30]
 *   @0x1d9884 ldr r6, [sp, #0x34]
 *   @0x1d9888 ldr r5, [sp, #0x38]
 *   @0x1d988c beq 0x1d98ec <_Z13ConvertRawPosffiRfS_S_S_+0x88>
 *   @0x1d9890 vcvt.s32.f32 s13, s17
 *   @0x1d9894 add r3, sp, #12
 *   @0x1d9898 mov r0, r2
 *   @0x1d989c str r3, [sp]
 *   @0x1d98a0 add r3, sp, #8
 *   @0x1d98a4 vcvt.s32.f32 s15, s16
 *   @0x1d98a8 vmov r1, s13
 *   @0x1d98ac vmov r2, s15
 *   @0x1d98b0 bl 0x179d64 <_Z22GR_Window_View_ConvertiiiRiS_>
 *   @0x1d98b4 vldr s13, [sp, #8]
 *   @0x1d98b8 vcvt.f32.s32 s14, s13
 *   @0x1d98bc vldr s13, [sp, #12]
 *   @0x1d98c0 mov r2, r6
 *   @0x1d98c4 mov r3, r5
 *   @0x1d98c8 vmov r0, s17
 *   @0x1d98cc vmov r1, s16
 *   @0x1d98d0 vcvt.f32.s32 s15, s13
 *   @0x1d98d4 vstr s14, [r7]
 *   @0x1d98d8 vstr s15, [r4]
 *   @0x1d98dc bl 0x159f4c <_Z15ConvertRawToGUIffRfS_>
 *   @0x1d98e0 add sp, sp, #20
 *   @0x1d98e4 vpop {d8}
 *   @0x1d98e8 pop {r4, r5, r6, r7, pc}
 *   @0x1d98ec vcvt.s32.f32 s13, s17
 *   @0x1d98f0 add r2, sp, #8
 *   @0x1d98f4 add r3, sp, #12
 *   @0x1d98f8 vcvt.s32.f32 s15, s16
 *   @0x1d98fc vmov r0, s13
 *   @0x1d9900 vmov r1, s15
 *   @0x1d9904 bl 0x17a6a0 <_Z23GR_Window_Views_ConvertiiRiS_>
 *   @0x1d9908 b 0x1d98b4 <_Z13ConvertRawPosffiRfS_S_S_+0x50>
 *
 * ══ §75/181 F_Shader_Get_Uniform(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e1058  size 168  42 条（0x1e1058..0x1e1100）
 * @func 0x1e1058 0x1e1100  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_Shader_Get_Uniform(RValue&, CInstance*, CInstance*, int, RValue*)+0x44 / F_Shader_Get_Uniform(RValue&, CInstance*, CInstance*, int, RValue*)+0x58 / YYGetString(RValue const*, int) / Shader_Get_Uniform_Handle(Shader*, char const*)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x64×1 / 0x54×1 / 0x44×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1058 push {r3, r4, r5, lr}
 *   @0x1e105c mov r1, #0
 *   @0x1e1060 ldr r5, [sp, #0x10]
 *   @0x1e1064 mov r3, r1
 *   @0x1e1068 str r1, [r0, #0xc]
 *   @0x1e106c movt r3, #0xbff0
 *   @0x1e1070 mov r4, r0
 *   @0x1e1074 stm r0, {r1, r3}
 *   @0x1e1078 mov r0, r5
 *   @0x1e107c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e1080 subs r2, r0, #0
 *   @0x1e1084 blt 0x1e109c <_Z20F_Shader_Get_UniformR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1e1088 ldr r3, [pc, #0x64]
 *   @0x1e108c ldr r3, [pc, r3]
 *   @0x1e1090 ldr r3, [r3]
 *   @0x1e1094 cmp r2, r3
 *   @0x1e1098 blt 0x1e10b0 <_Z20F_Shader_Get_UniformR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x1e109c ldr r0, [pc, #0x54]
 *   @0x1e10a0 mov r1, #0
 *   @0x1e10a4 pop {r3, r4, r5, lr}
 *   @0x1e10a8 add r0, pc, r0
 *   @0x1e10ac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e10b0 ldr r3, [pc, #0x44]
 *   @0x1e10b4 mov r0, r5
 *   @0x1e10b8 mov r1, #1
 *   @0x1e10bc ldr r3, [pc, r3]
 *   @0x1e10c0 ldr r3, [r3]
 *   @0x1e10c4 ldr r5, [r3, r2, lsl #2]
 *   @0x1e10c8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1e10cc mov r1, r0
 *   @0x1e10d0 mov r0, r5
 *   @0x1e10d4 bl 0x1883b8 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc>
 *   @0x1e10d8 vmov s15, r0
 *   @0x1e10dc vcvt.f64.s32 d7, s15
 *   @0x1e10e0 vmov r0, r1, d7
 *   @0x1e10e4 vmov r2, s14
 *   @0x1e10e8 mov r3, r1
 *   @0x1e10ec stm r4, {r2, r3}
 *   @0x1e10f0 pop {r3, r4, r5, pc}
 *   @0x1e10f4 .word 0x0020fcb8
 *   @0x1e10f8 andseq r0, r7, r12, asr #25
 *   @0x1e10fc eoreq pc, r0, r12, lsl #25
 *
 * ══ §76/181 F_Shader_Get_Sampler_Index(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e1100  size 168  42 条（0x1e1100..0x1e11a8）
 * @func 0x1e1100 0x1e11a8  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_Shader_Get_Sampler_Index(RValue&, CInstance*, CInstance*, int, RValue*)+0x44 / F_Shader_Get_Sampler_Index(RValue&, CInstance*, CInstance*, int, RValue*)+0x58 / YYGetString(RValue const*, int) / Shader_Get_Sampler_Index(Shader*, char const*)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x64×1 / 0x54×1 / 0x44×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1100 push {r3, r4, r5, lr}
 *   @0x1e1104 mov r1, #0
 *   @0x1e1108 ldr r5, [sp, #0x10]
 *   @0x1e110c mov r3, r1
 *   @0x1e1110 str r1, [r0, #0xc]
 *   @0x1e1114 movt r3, #0xbff0
 *   @0x1e1118 mov r4, r0
 *   @0x1e111c stm r0, {r1, r3}
 *   @0x1e1120 mov r0, r5
 *   @0x1e1124 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e1128 subs r2, r0, #0
 *   @0x1e112c blt 0x1e1144 <_Z26F_Shader_Get_Sampler_IndexR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1e1130 ldr r3, [pc, #0x64]
 *   @0x1e1134 ldr r3, [pc, r3]
 *   @0x1e1138 ldr r3, [r3]
 *   @0x1e113c cmp r2, r3
 *   @0x1e1140 blt 0x1e1158 <_Z26F_Shader_Get_Sampler_IndexR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x1e1144 ldr r0, [pc, #0x54]
 *   @0x1e1148 mov r1, #0
 *   @0x1e114c pop {r3, r4, r5, lr}
 *   @0x1e1150 add r0, pc, r0
 *   @0x1e1154 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e1158 ldr r3, [pc, #0x44]
 *   @0x1e115c mov r0, r5
 *   @0x1e1160 mov r1, #1
 *   @0x1e1164 ldr r3, [pc, r3]
 *   @0x1e1168 ldr r3, [r3]
 *   @0x1e116c ldr r5, [r3, r2, lsl #2]
 *   @0x1e1170 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1e1174 mov r1, r0
 *   @0x1e1178 mov r0, r5
 *   @0x1e117c bl 0x188468 <_Z24Shader_Get_Sampler_IndexP6ShaderPKc>
 *   @0x1e1180 vmov s15, r0
 *   @0x1e1184 vcvt.f64.s32 d7, s15
 *   @0x1e1188 vmov r0, r1, d7
 *   @0x1e118c vmov r2, s14
 *   @0x1e1190 mov r3, r1
 *   @0x1e1194 stm r4, {r2, r3}
 *   @0x1e1198 pop {r3, r4, r5, pc}
 *   @0x1e119c eoreq pc, r0, r0, lsl r12
 *   @0x1e11a0 andseq r0, r7, r4, lsr #24
 *   @0x1e11a4 eoreq pc, r0, r4, ror #23
 *
 * ══ §77/181 F_VertexFormat_Add_Custom(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e2b08  size 168  42 条（0x1e2b08..0x1e2bb0）
 * @func 0x1e2b08 0x1e2bb0  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / VertexFormat::Add(yyVertexType, yyVertexUsage, unsigned int)
 * 字段偏移 top8: 0x10×1 / 0x54×1 / 0x50×1 / 0x28×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2b08 push {r3, r4, r5, lr}
 *   @0x1e2b0c mov r1, #0
 *   @0x1e2b10 ldr r4, [sp, #0x10]
 *   @0x1e2b14 mov r0, r4
 *   @0x1e2b18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e2b1c sub r3, r0, #1
 *   @0x1e2b20 mov r5, r0
 *   @0x1e2b24 cmp r3, #5
 *   @0x1e2b28 bhi 0x1e2b8c <_Z25F_VertexFormat_Add_CustomR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1e2b2c mov r0, r4
 *   @0x1e2b30 mov r1, #1
 *   @0x1e2b34 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e2b38 sub r3, r0, #1
 *   @0x1e2b3c cmp r3, #13
 *   @0x1e2b40 bhi 0x1e2b78 <_Z25F_VertexFormat_Add_CustomR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1e2b44 ldr r3, [pc, #0x54]
 *   @0x1e2b48 mov r2, r0
 *   @0x1e2b4c ldr r4, [pc, #0x50]
 *   @0x1e2b50 mov r1, r5
 *   @0x1e2b54 ldr r3, [pc, r3]
 *   @0x1e2b58 ldr r4, [pc, r4]
 *   @0x1e2b5c ldr r0, [r3]
 *   @0x1e2b60 ldr r3, [r4]
 *   @0x1e2b64 bl 0x1e2440 <_ZN12VertexFormat3AddE12yyVertexType13yyVertexUsagej>
 *   @0x1e2b68 ldr r3, [r4]
 *   @0x1e2b6c lsl r3, r3, #1
 *   @0x1e2b70 str r3, [r4]
 *   @0x1e2b74 pop {r3, r4, r5, pc}
 *   @0x1e2b78 ldr r0, [pc, #0x28]
 *   @0x1e2b7c mov r1, #0
 *   @0x1e2b80 pop {r3, r4, r5, lr}
 *   @0x1e2b84 add r0, pc, r0
 *   @0x1e2b88 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2b8c ldr r0, [pc, #0x18]
 *   @0x1e2b90 mov r1, #0
 *   @0x1e2b94 pop {r3, r4, r5, lr}
 *   @0x1e2b98 add r0, pc, r0
 *   @0x1e2b9c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2ba0 eoreq lr, r0, r12, lsr r2
 *   @0x1e2ba4 eoreq lr, r0, r12, lsr r2
 *   @0x1e2ba8 mulseq r6, r0, r6
 *   @0x1e2bac andseq pc, r6, r0, asr r6
 *
 * ══ §78/181 CSprite::LoadFromYYSFile(char const*, int, int)  0x1e9b68  size 168  42 条（0x1e9b68..0x1e9c10）
 * @func 0x1e9b68 0x1e9c10  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::SaveFileExists(char const*) / LoadSave::ReadSaveFile(char const*, int*) / CSprite::BuildSWFData(char*, int, int) / MemoryManager::Free(void const*) / LoadSave::BundleFileExists(char const*) / LoadSave::ReadBundleFile(char const*, int*)
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e9b68 push {r4, r5, r6, r7, r8, lr}
 *   @0x1e9b6c sub sp, sp, #8
 *   @0x1e9b70 mov r6, r0
 *   @0x1e9b74 mov r0, r1
 *   @0x1e9b78 mov r5, r1
 *   @0x1e9b7c mov r8, r2
 *   @0x1e9b80 mov r1, #0
 *   @0x1e9b84 mov r7, r3
 *   @0x1e9b88 str r1, [sp, #0x4]
 *   @0x1e9b8c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x1e9b90 cmp r0, #0
 *   @0x1e9b94 mov r0, r5
 *   @0x1e9b98 beq 0x1e9be8 <_ZN7CSprite15LoadFromYYSFileEPKcii+0x80>
 *   @0x1e9b9c add r1, sp, #4
 *   @0x1e9ba0 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0x1e9ba4 mov r4, r0
 *   @0x1e9ba8 cmp r4, #0
 *   @0x1e9bac moveq r5, r4
 *   @0x1e9bb0 beq 0x1e9bd4 <_ZN7CSprite15LoadFromYYSFileEPKcii+0x6c>
 *   @0x1e9bb4 mov r3, r7
 *   @0x1e9bb8 mov r2, r8
 *   @0x1e9bbc mov r0, r6
 *   @0x1e9bc0 mov r1, r4
 *   @0x1e9bc4 bl 0x1e838c <_ZN7CSprite12BuildSWFDataEPcii>
 *   @0x1e9bc8 subs r5, r0, #0
 *   @0x1e9bcc movne r3, #1
 *   @0x1e9bd0 strne r3, [r6, #0x74]
 *   @0x1e9bd4 mov r0, r4
 *   @0x1e9bd8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e9bdc mov r0, r5
 *   @0x1e9be0 add sp, sp, #8
 *   @0x1e9be4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1e9be8 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x1e9bec cmp r0, #0
 *   @0x1e9bf0 moveq r4, r0
 *   @0x1e9bf4 moveq r5, r4
 *   @0x1e9bf8 beq 0x1e9bd4 <_ZN7CSprite15LoadFromYYSFileEPKcii+0x6c>
 *   @0x1e9bfc mov r0, r5
 *   @0x1e9c00 add r1, sp, #4
 *   @0x1e9c04 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x1e9c08 mov r4, r0
 *   @0x1e9c0c b 0x1e9ba8 <_ZN7CSprite15LoadFromYYSFileEPKcii+0x40>
 *
 * ══ §79/181 CVariableList::Assign(CVariableList*)  0x1f7904  size 168  42 条（0x1f7904..0x1f79ac）
 * @func 0x1f7904 0x1f79ac  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CVariableList::Clear() / CVariableList::Alloc(RVariable const*) / CVariableList::Add(RVariable*)
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7904 push {r3, r4, r5, r6, r7, lr}
 *   @0x1f7908 mov r5, r1
 *   @0x1f790c mov r7, r0
 *   @0x1f7910 bl 0x1f662c <_ZN13CVariableList5ClearEv>
 *   @0x1f7914 adds r4, r5, #4
 *   @0x1f7918 addne r4, r5, #20
 *   @0x1f791c beq 0x1f7988 <_ZN13CVariableList6AssignEPS_+0x84>
 *   @0x1f7920 cmp r4, r5
 *   @0x1f7924 add r6, r5, #4
 *   @0x1f7928 beq 0x1f7934 <_ZN13CVariableList6AssignEPS_+0x30>
 *   @0x1f792c cmp r4, r6
 *   @0x1f7930 bne 0x1f7994 <_ZN13CVariableList6AssignEPS_+0x90>
 *   @0x1f7934 mov r6, r4
 *   @0x1f7938 mov r5, #0
 *   @0x1f793c cmp r5, #0
 *   @0x1f7940 beq 0x1f7984 <_ZN13CVariableList6AssignEPS_+0x80>
 *   @0x1f7944 mov r0, r5
 *   @0x1f7948 bl 0x1f7890 <_ZN13CVariableList5AllocEPK9RVariable>
 *   @0x1f794c mov r1, r0
 *   @0x1f7950 mov r0, r7
 *   @0x1f7954 bl 0x1f51e8 <_ZN13CVariableList3AddEP9RVariable>
 *   @0x1f7958 ldr r5, [r5]
 *   @0x1f795c cmp r5, #0
 *   @0x1f7960 add r3, r6, #4
 *   @0x1f7964 bne 0x1f793c <_ZN13CVariableList6AssignEPS_+0x38>
 *   @0x1f7968 cmp r4, r6
 *   @0x1f796c beq 0x1f79a8 <_ZN13CVariableList6AssignEPS_+0xa4>
 *   @0x1f7970 cmp r3, r4
 *   @0x1f7974 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1f7978 ldr r5, [r6, #0x4]
 *   @0x1f797c mov r6, r3
 *   @0x1f7980 b 0x1f795c <_ZN13CVariableList6AssignEPS_+0x58>
 *   @0x1f7984 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1f7988 mov r6, r4
 *   @0x1f798c mov r5, r4
 *   @0x1f7990 b 0x1f793c <_ZN13CVariableList6AssignEPS_+0x38>
 *   @0x1f7994 ldr r5, [r5, #0x4]
 *   @0x1f7998 cmp r5, #0
 *   @0x1f799c bne 0x1f793c <_ZN13CVariableList6AssignEPS_+0x38>
 *   @0x1f79a0 mov r5, r6
 *   @0x1f79a4 b 0x1f7920 <_ZN13CVariableList6AssignEPS_+0x1c>
 *   @0x1f79a8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §80/181 CDS_Queue::WriteToString(char const*&)  0x202e30  size 168  42 条（0x202e30..0x202ed8）
 * @func 0x202e30 0x202ed8  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::WriteInteger(int)×4 / operator new(unsigned int) / CStream::CStream(int) / CDS_Queue::WriteToString(char const*&)+0x80 / WriteValue(CStream&, RValue&) / CStream::ConvertToString(char const*&) / CStream::~CStream()
 * 字段偏移 top8: 0xc×3 / 0x4×1 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202e30 push {r3, r4, r5, r6, r7, lr}
 *   @0x202e34 mov r5, r0
 *   @0x202e38 mov r0, #32
 *   @0x202e3c mov r7, r1
 *   @0x202e40 bl 0x27c524 <_Znwj>
 *   @0x202e44 mov r1, #0
 *   @0x202e48 mov r6, r0
 *   @0x202e4c bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x202e50 mov r0, r6
 *   @0x202e54 mov r1, #202
 *   @0x202e58 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x202e5c mov r0, r6
 *   @0x202e60 ldr r1, [r5, #0x4]
 *   @0x202e64 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x202e68 mov r0, r6
 *   @0x202e6c ldr r1, [r5, #0x8]
 *   @0x202e70 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x202e74 mov r0, r6
 *   @0x202e78 ldr r1, [r5, #0xc]
 *   @0x202e7c bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x202e80 ldr r3, [r5, #0xc]
 *   @0x202e84 cmp r3, #0
 *   @0x202e88 movgt r4, #0
 *   @0x202e8c ble 0x202eb0 <_ZN9CDS_Queue13WriteToStringERPKc+0x80>
 *   @0x202e90 ldr r1, [r5, #0x10]
 *   @0x202e94 mov r0, r6
 *   @0x202e98 add r1, r1, r4, lsl #4
 *   @0x202e9c add r4, r4, #1
 *   @0x202ea0 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue>
 *   @0x202ea4 ldr r3, [r5, #0xc]
 *   @0x202ea8 cmp r3, r4
 *   @0x202eac bgt 0x202e90 <_ZN9CDS_Queue13WriteToStringERPKc+0x60>
 *   @0x202eb0 mov r1, r7
 *   @0x202eb4 mov r0, r6
 *   @0x202eb8 bl 0x2024b0 <_ZN7CStream15ConvertToStringERPKc>
 *   @0x202ebc cmp r6, #0
 *   @0x202ec0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x202ec4 mov r0, r6
 *   @0x202ec8 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x202ecc mov r0, r6
 *   @0x202ed0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x202ed4 b 0x27d1d0 <_ZdlPv>
 *
 * ══ §81/181 CDS_Map::FindLast()  0x203cc4  size 168  42 条（0x203cc4..0x203d6c）
 * @func 0x203cc4 0x203d6c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Map::FindLast()+0x70
 * 字段偏移 top8: 0x4×3 / 0x3×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203cc4 push {r4, r5, r6}
 *   @0x203cc8 mov r2, #0
 *   @0x203ccc ldr r5, [r0]
 *   @0x203cd0 ldr r6, [r5]
 *   @0x203cd4 b 0x203ce8 <_ZN7CDS_Map8FindLastEv+0x24>
 *   @0x203cd8 ldr r1, [r5, #0x4]
 *   @0x203cdc add r2, r2, #1
 *   @0x203ce0 cmp r2, r1
 *   @0x203ce4 bgt 0x203d64 <_ZN7CDS_Map8FindLastEv+0xa0>
 *   @0x203ce8 ldr r3, [r6, r2, lsl #3]
 *   @0x203cec cmp r3, #0
 *   @0x203cf0 beq 0x203cd8 <_ZN7CDS_Map8FindLastEv+0x14>
 *   @0x203cf4 mov r0, #0
 *   @0x203cf8 b 0x203d00 <_ZN7CDS_Map8FindLastEv+0x3c>
 *   @0x203cfc mov r0, r12
 *   @0x203d00 cmp r3, #0
 *   @0x203d04 beq 0x203d5c <_ZN7CDS_Map8FindLastEv+0x98>
 *   @0x203d08 ldr r12, [r3, #0xc]
 *   @0x203d0c cmp r12, #0
 *   @0x203d10 beq 0x203d5c <_ZN7CDS_Map8FindLastEv+0x98>
 *   @0x203d14 ldr r3, [r3, #0x4]
 *   @0x203d18 cmp r3, #0
 *   @0x203d1c bne 0x203cfc <_ZN7CDS_Map8FindLastEv+0x38>
 *   @0x203d20 ldr r4, [r5, #0x4]
 *   @0x203d24 add r0, r2, #1
 *   @0x203d28 cmp r0, r4
 *   @0x203d2c bgt 0x203d54 <_ZN7CDS_Map8FindLastEv+0x90>
 *   @0x203d30 add r1, r6, r2, lsl #3
 *   @0x203d34 ldr r3, [r1, #0x8]
 *   @0x203d38 mov r2, r0
 *   @0x203d3c add r1, r1, #8
 *   @0x203d40 add r0, r0, #1
 *   @0x203d44 cmp r3, #0
 *   @0x203d48 bne 0x203cfc <_ZN7CDS_Map8FindLastEv+0x38>
 *   @0x203d4c cmp r0, r4
 *   @0x203d50 ble 0x203d34 <_ZN7CDS_Map8FindLastEv+0x70>
 *   @0x203d54 mvn r2, #0
 *   @0x203d58 b 0x203cfc <_ZN7CDS_Map8FindLastEv+0x38>
 *   @0x203d5c pop {r4, r5, r6}
 *   @0x203d60 bx lr
 *   @0x203d64 mvn r2, #0
 *   @0x203d68 b 0x203cf4 <_ZN7CDS_Map8FindLastEv+0x30>
 *
 * ══ §82/181 CDS_List::Delete(int)  0x208b94  size 168  42 条（0x208b94..0x208c3c）
 * @func 0x208b94 0x208c3c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6694 / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×6 / 0x4×5 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x208b94 push {r3, r4, r5, r6, r7, lr}
 *   @0x208b98 subs r6, r1, #0
 *   @0x208b9c mov r4, r0
 *   @0x208ba0 poplt {r3, r4, r5, r6, r7, pc}
 *   @0x208ba4 ldr r3, [r0, #0x4]
 *   @0x208ba8 cmp r6, r3
 *   @0x208bac popge {r3, r4, r5, r6, r7, pc}
 *   @0x208bb0 ldr r12, [r0, #0xc]
 *   @0x208bb4 lsl r7, r6, #4
 *   @0x208bb8 add r5, r12, r7
 *   @0x208bbc ldr r2, [r5, #0xc]
 *   @0x208bc0 mov r0, r5
 *   @0x208bc4 sub r2, r2, #1
 *   @0x208bc8 bic r2, r2, #-16777216
 *   @0x208bcc bic r2, r2, #3
 *   @0x208bd0 cmp r2, #0
 *   @0x208bd4 beq 0x208c28 <_ZN8CDS_List6DeleteEi+0x94>
 *   @0x208bd8 sub r3, r3, #1
 *   @0x208bdc add r1, r7, #16
 *   @0x208be0 rsb r2, r6, r3
 *   @0x208be4 mov r7, #0
 *   @0x208be8 mov r3, #5
 *   @0x208bec add r1, r12, r1
 *   @0x208bf0 lsl r2, r2, #4
 *   @0x208bf4 str r3, [r5, #0xc]
 *   @0x208bf8 str r7, [r5, #0x8]
 *   @0x208bfc str r7, [r5]
 *   @0x208c00 bl 0xb6694 <memmove@plt>
 *   @0x208c04 ldr r1, [r4, #0x4]
 *   @0x208c08 ldr r3, [r4, #0xc]
 *   @0x208c0c sub r2, r1, #-268435455
 *   @0x208c10 sub r1, r1, #1
 *   @0x208c14 add r0, r3, r2, lsl #4
 *   @0x208c18 str r7, [r3, r2, lsl #4]
 *   @0x208c1c str r7, [r0, #0xc]
 *   @0x208c20 str r1, [r4, #0x4]
 *   @0x208c24 pop {r3, r4, r5, r6, r7, pc}
 *   @0x208c28 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x208c2c ldr r12, [r4, #0xc]
 *   @0x208c30 ldr r3, [r4, #0x4]
 *   @0x208c34 add r0, r12, r7
 *   @0x208c38 b 0x208bd8 <_ZN8CDS_List6DeleteEi+0x44>
 *
 * ══ §83/181 CSound::LoadFromChunk(YYSound*, unsigned char*)  0x215498  size 168  42 条（0x215498..0x215540）
 * @func 0x215498 0x215540  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*)×2 / CSound::Clear()
 * 字段偏移 top8: 0x8×2 / 0x4×2 / 0xc×2 / 0x1c×1 / 0x10×1 / 0x20×1 / 0x18×1 / 0x3c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215498 push {r4, r5, r6, lr}
 *   @0x21549c mov r5, r1
 *   @0x2154a0 mov r4, r0
 *   @0x2154a4 bl 0x21529c <_ZN6CSound5ClearEv>
 *   @0x2154a8 ldr r0, [r5, #0x8]
 *   @0x2154ac ldr r3, [r5, #0x4]
 *   @0x2154b0 cmp r0, #0
 *   @0x2154b4 str r3, [r4, #0x4]
 *   @0x2154b8 ldrne r3, [pc, #0x78]
 *   @0x2154bc ldrne r3, [pc, r3]
 *   @0x2154c0 ldrne r3, [r3]
 *   @0x2154c4 addne r0, r3, r0
 *   @0x2154c8 ldr r3, [r5, #0xc]
 *   @0x2154cc cmp r3, #0
 *   @0x2154d0 moveq r6, r3
 *   @0x2154d4 ldrne r2, [pc, #0x60]
 *   @0x2154d8 ldrne r2, [pc, r2]
 *   @0x2154dc ldrne r6, [r2]
 *   @0x2154e0 addne r6, r6, r3
 *   @0x2154e4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x2154e8 str r0, [r4, #0x8]
 *   @0x2154ec mov r0, r6
 *   @0x2154f0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x2154f4 vldr s12, [r5, #20]
 *   @0x2154f8 vldr s14, [r5, #24]
 *   @0x2154fc vcvt.f64.f32 d6, s12
 *   @0x215500 ldr r3, [r5, #0x1c]
 *   @0x215504 ldr r1, [r5, #0x10]
 *   @0x215508 ldr r2, [r5, #0x20]
 *   @0x21550c adds r3, r3, #0
 *   @0x215510 str r1, [r4, #0x18]
 *   @0x215514 movne r3, #1
 *   @0x215518 str r2, [r4, #0x3c]
 *   @0x21551c vcvt.f64.f32 d7, s14
 *   @0x215520 strb r3, [r4, #0x14]
 *   @0x215524 vstr d6, [r4, #32]
 *   @0x215528 vstr d7, [r4, #40]
 *   @0x21552c str r0, [r4, #0xc]
 *   @0x215530 mov r0, #1
 *   @0x215534 pop {r4, r5, r6, pc}
 *   @0x215538 andseq r8, sp, r8, lsl #9
 *   @0x21553c andseq r8, sp, r12, ror #8
 *
 * ══ §84/181 Audio_PauseAll()  0x217c48  size 168  42 条（0x217c48..0x217cf0）
 * @func 0x217c48 0x217cf0  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_PauseSoundNoise(CNoise*)
 * 字段偏移 top8: 0x38×2 / 0x88×1 / 0x78×1 / 0x68×1 / 0x58×1 / 0x54×1 / 0x3c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217c48 push {r3, r4, r5, r6, r7, lr}
 *   @0x217c4c ldr r3, [pc, #0x88]
 *   @0x217c50 ldr r3, [pc, r3]
 *   @0x217c54 ldrb r4, [r3]
 *   @0x217c58 cmp r4, #0
 *   @0x217c5c popne {r3, r4, r5, r6, r7, pc}
 *   @0x217c60 ldr r3, [pc, #0x78]
 *   @0x217c64 ldr r3, [pc, r3]
 *   @0x217c68 ldrb r3, [r3]
 *   @0x217c6c cmp r3, #0
 *   @0x217c70 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x217c74 ldr r3, [pc, #0x68]
 *   @0x217c78 add r3, pc, r3
 *   @0x217c7c ldr r5, [r3, #0x38]
 *   @0x217c80 cmp r5, #0
 *   @0x217c84 pople {r3, r4, r5, r6, r7, pc}
 *   @0x217c88 ldr r7, [pc, #0x58]
 *   @0x217c8c mov r3, r5
 *   @0x217c90 ldr r6, [pc, #0x54]
 *   @0x217c94 add r7, pc, r7
 *   @0x217c98 add r6, pc, r6
 *   @0x217c9c b 0x217cb0 <_Z14Audio_PauseAllv+0x68>
 *   @0x217ca0 add r4, r4, #1
 *   @0x217ca4 cmp r4, r5
 *   @0x217ca8 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x217cac ldr r3, [r6, #0x38]
 *   @0x217cb0 cmp r4, r3
 *   @0x217cb4 bge 0x217ca0 <_Z14Audio_PauseAllv+0x58>
 *   @0x217cb8 ldr r3, [r7, #0x3c]
 *   @0x217cbc ldr r0, [r3, r4, lsl #2]
 *   @0x217cc0 cmp r0, #0
 *   @0x217cc4 beq 0x217ca0 <_Z14Audio_PauseAllv+0x58>
 *   @0x217cc8 ldrb r3, [r0, #0x5]
 *   @0x217ccc cmp r3, #0
 *   @0x217cd0 beq 0x217ca0 <_Z14Audio_PauseAllv+0x58>
 *   @0x217cd4 bl 0x217b44 <_Z21Audio_PauseSoundNoiseP6CNoise>
 *   @0x217cd8 b 0x217ca0 <_Z14Audio_PauseAllv+0x58>
 *   @0x217cdc ldrsheq r7, [sp], -r12
 *   @0x217ce0 andseq r7, sp, r12, asr #1
 *   @0x217ce4 subseq sp, r3, r12, lsl r6
 *   @0x217ce8 subseq sp, r3, r0, lsl #12
 *   @0x217cec ldrsheq sp, [r3], #-92
 *
 * ══ §85/181 Audio_ResumeAll()  0x217df4  size 168  42 条（0x217df4..0x217e9c）
 * @func 0x217df4 0x217e9c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_ResumeSoundNoise(CNoise*)
 * 字段偏移 top8: 0x38×2 / 0x88×1 / 0x78×1 / 0x68×1 / 0x58×1 / 0x54×1 / 0x3c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217df4 push {r3, r4, r5, r6, r7, lr}
 *   @0x217df8 ldr r3, [pc, #0x88]
 *   @0x217dfc ldr r3, [pc, r3]
 *   @0x217e00 ldrb r4, [r3]
 *   @0x217e04 cmp r4, #0
 *   @0x217e08 popne {r3, r4, r5, r6, r7, pc}
 *   @0x217e0c ldr r3, [pc, #0x78]
 *   @0x217e10 ldr r3, [pc, r3]
 *   @0x217e14 ldrb r3, [r3]
 *   @0x217e18 cmp r3, #0
 *   @0x217e1c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x217e20 ldr r3, [pc, #0x68]
 *   @0x217e24 add r3, pc, r3
 *   @0x217e28 ldr r5, [r3, #0x38]
 *   @0x217e2c cmp r5, #0
 *   @0x217e30 pople {r3, r4, r5, r6, r7, pc}
 *   @0x217e34 ldr r7, [pc, #0x58]
 *   @0x217e38 mov r3, r5
 *   @0x217e3c ldr r6, [pc, #0x54]
 *   @0x217e40 add r7, pc, r7
 *   @0x217e44 add r6, pc, r6
 *   @0x217e48 b 0x217e5c <_Z15Audio_ResumeAllv+0x68>
 *   @0x217e4c add r4, r4, #1
 *   @0x217e50 cmp r4, r5
 *   @0x217e54 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x217e58 ldr r3, [r6, #0x38]
 *   @0x217e5c cmp r4, r3
 *   @0x217e60 bge 0x217e4c <_Z15Audio_ResumeAllv+0x58>
 *   @0x217e64 ldr r3, [r7, #0x3c]
 *   @0x217e68 ldr r0, [r3, r4, lsl #2]
 *   @0x217e6c cmp r0, #0
 *   @0x217e70 beq 0x217e4c <_Z15Audio_ResumeAllv+0x58>
 *   @0x217e74 ldrb r3, [r0, #0x5]
 *   @0x217e78 cmp r3, #0
 *   @0x217e7c beq 0x217e4c <_Z15Audio_ResumeAllv+0x58>
 *   @0x217e80 bl 0x217cf0 <_Z22Audio_ResumeSoundNoiseP6CNoise>
 *   @0x217e84 b 0x217e4c <_Z15Audio_ResumeAllv+0x58>
 *   @0x217e88 andseq r7, sp, r0, asr r2
 *   @0x217e8c andseq r6, sp, r0, lsr #30
 *   @0x217e90 subseq sp, r3, r0, ror r4
 *   @0x217e94 subseq sp, r3, r4, asr r4
 *   @0x217e98 subseq sp, r3, r0, asr r4
 *
 * ══ §86/181 alutSleep  0x2229f0  size 168  42 条（0x2229f0..0x222a98）
 * @func 0x2229f0 0x222a98  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6bf8 / 0xb6c04 / alutSleep+0x4c / _alutSetError
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2229f0 vmov s15, r0
 *   @0x2229f4 push {r4, r5, lr}
 *   @0x2229f8 vcmpe.f32 s15, #0
 *   @0x2229fc sub sp, sp, #20
 *   @0x222a00 vmrs APSR_nzcv, fpscr
 *   @0x222a04 bmi 0x222a84 <alutSleep+0x94>
 *   @0x222a08 vcvt.u32.f32 s14, s15
 *   @0x222a0c vldr s13, [pc, #128]
 *   @0x222a10 mov r2, #1000
 *   @0x222a14 add r4, sp, #8
 *   @0x222a18 vcvt.f32.u32 s12, s14
 *   @0x222a1c vstr s14, [sp]
 *   @0x222a20 vsub.f32 s15, s15, s12
 *   @0x222a24 vmul.f32 s15, s15, s13
 *   @0x222a28 vcvt.u32.f32 s15, s15
 *   @0x222a2c vmov r1, s15
 *   @0x222a30 mul r3, r2, r1
 *   @0x222a34 str r3, [sp, #0x4]
 *   @0x222a38 b 0x222a58 <alutSleep+0x68>
 *   @0x222a3c bl 0xb6bf8 <__errno@plt>
 *   @0x222a40 ldr r3, [r0]
 *   @0x222a44 cmp r3, #4
 *   @0x222a48 bne 0x222a78 <alutSleep+0x88>
 *   @0x222a4c ldr r2, [sp, #0x8]
 *   @0x222a50 ldr r3, [sp, #0xc]
 *   @0x222a54 stm sp, {r2, r3}
 *   @0x222a58 mov r0, sp
 *   @0x222a5c mov r1, r4
 *   @0x222a60 bl 0xb6c04 <nanosleep@plt>
 *   @0x222a64 cmp r0, #0
 *   @0x222a68 blt 0x222a3c <alutSleep+0x4c>
 *   @0x222a6c mov r0, #1
 *   @0x222a70 add sp, sp, #20
 *   @0x222a74 pop {r4, r5, pc}
 *   @0x222a78 mov r0, #0
 *   @0x222a7c add sp, sp, #20
 *   @0x222a80 pop {r4, r5, pc}
 *   @0x222a84 movw r0, #0x202
 *   @0x222a88 bl 0x221940 <_alutSetError>
 *   @0x222a8c mov r0, #0
 *   @0x222a90 b 0x222a70 <alutSleep+0x80>
 *   @0x222a94 ldmdbmi r4!, {r10, sp} ^
 *
 * ══ §87/181 UpdateTimingEvents(COggSyncThread*)  0x224c34  size 168  42 条（0x224c34..0x224cdc）
 * @func 0x224c34 0x224cdc  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock() / Timing_Time / operator delete(void*) / UpdateTimingEvents(COggSyncThread*)+0x40
 * 字段偏移 top8: 0x8c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224c34 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x224c38 mov r6, r0
 *   @0x224c3c bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x224c40 bl 0x215148 <Timing_Time>
 *   @0x224c44 ldr r8, [pc, #0x8c]
 *   @0x224c48 movw r4, #0x7b80
 *   @0x224c4c movt r4, #0xffe1
 *   @0x224c50 ldr r8, [pc, r8]
 *   @0x224c54 mvn r5, #0
 *   @0x224c58 ldr r12, [r8]
 *   @0x224c5c adds r4, r4, r0
 *   @0x224c60 adc r5, r5, r1
 *   @0x224c64 cmp r12, #0
 *   @0x224c68 movne r7, #0
 *   @0x224c6c bne 0x224cac <_Z18UpdateTimingEventsP14COggSyncThread+0x78>
 *   @0x224c70 b 0x224ccc <_Z18UpdateTimingEventsP14COggSyncThread+0x98>
 *   @0x224c74 cmp r7, #0
 *   @0x224c78 mov r0, r12
 *   @0x224c7c ldrne r3, [r12, #0x18]
 *   @0x224c80 strne r3, [r7, #0x18]
 *   @0x224c84 ldr r3, [r8]
 *   @0x224c88 cmp r12, r3
 *   @0x224c8c ldreq r3, [r12, #0x18]
 *   @0x224c90 ldrne r9, [r12, #0x18]
 *   @0x224c94 moveq r9, r3
 *   @0x224c98 streq r3, [r8]
 *   @0x224c9c bl 0x27d1d0 <_ZdlPv>
 *   @0x224ca0 mov r12, r9
 *   @0x224ca4 cmp r12, #0
 *   @0x224ca8 beq 0x224ccc <_Z18UpdateTimingEventsP14COggSyncThread+0x98>
 *   @0x224cac ldrd r2, r3, [r12, #16]
 *   @0x224cb0 cmp r2, r4
 *   @0x224cb4 sbcs r1, r3, r5
 *   @0x224cb8 blt 0x224c74 <_Z18UpdateTimingEventsP14COggSyncThread+0x40>
 *   @0x224cbc mov r7, r12
 *   @0x224cc0 ldr r12, [r12, #0x18]
 *   @0x224cc4 cmp r12, #0
 *   @0x224cc8 bne 0x224cac <_Z18UpdateTimingEventsP14COggSyncThread+0x78>
 *   @0x224ccc mov r0, r6
 *   @0x224cd0 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x224cd4 b 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x224cd8 andseq r12, r12, r12, lsr #16
 *
 * ══ §88/181 COggSyncThread::MixData(void*, int, int, int, float, float)  0x225188  size 168  42 条（0x225188..0x225230）
 * @func 0x225188 0x225230  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::MixData(void*, int, int, int, float, float)+0xa0
 * 字段偏移 top8: 0x870×1 / 0x85c×1 / 0x2×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x225188 add r3, r3, r3, lsr #31
 *   @0x22518c ldr r2, [r0, #0x870]
 *   @0x225190 push {r4, r5}
 *   @0x225194 asr r12, r3, #1
 *   @0x225198 vldr s12, [sp, #12]
 *   @0x22519c add r0, r0, r2, lsl #2
 *   @0x2251a0 cmp r12, #0
 *   @0x2251a4 vldr s11, [sp, #16]
 *   @0x2251a8 vsub.f32 s11, s11, s12
 *   @0x2251ac ldr r0, [r0, #0x85c]
 *   @0x2251b0 ble 0x225228 <_ZN14COggSyncThread7MixDataEPviiiff+0xa0>
 *   @0x2251b4 vmov s9, r12
 *   @0x2251b8 movw r4, #0x8001
 *   @0x2251bc sub r1, r1, #2
 *   @0x2251c0 movt r4, #0xffff
 *   @0x2251c4 mov r3, #0
 *   @0x2251c8 movw r5, #0x7fff
 *   @0x2251cc vcvt.f32.s32 s10, s9
 *   @0x2251d0 vmov s9, r3
 *   @0x2251d4 ldrsh r2, [r0]
 *   @0x2251d8 add r3, r3, #1
 *   @0x2251dc vmov s15, r2
 *   @0x2251e0 ldrsh r2, [r1, #2]!
 *   @0x2251e4 vcvt.f32.s32 s14, s9
 *   @0x2251e8 vmov s13, r2
 *   @0x2251ec vdiv.f32 s14, s14, s10
 *   @0x2251f0 vmov.f32 s9, s12
 *   @0x2251f4 vmla.f32 s9, s14, s11
 *   @0x2251f8 vcvt.f32.s32 s15, s15
 *   @0x2251fc vcvt.f32.s32 s13, s13
 *   @0x225200 vmla.f32 s15, s13, s9
 *   @0x225204 vcvt.s32.f32 s15, s15
 *   @0x225208 vmov r2, s15
 *   @0x22520c cmp r2, r4
 *   @0x225210 movlt r2, r4
 *   @0x225214 cmp r2, r5
 *   @0x225218 movge r2, r5
 *   @0x22521c cmp r3, r12
 *   @0x225220 strh r2, [r0], #2
 *   @0x225224 bne 0x2251d0 <_ZN14COggSyncThread7MixDataEPviiiff+0x48>
 *   @0x225228 pop {r4, r5}
 *   @0x22522c bx lr
 *
 * ══ §89/181 COggAudio::CalcSoundInfo(cAudio_Sound*)  0x22688c  size 168  42 条（0x22688c..0x226934）
 * @func 0x22688c 0x226934  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetStreamInfo(cAudio_Sound*) / LoadSave::_GetBundleFileName(char*, int, char const*) / LoadSave::BundleFileExists(char const*) / YYFree(void const*) / YYStrDup(char const*) / 0xb65d4
 * 字段偏移 top8: 0x30×3 / 0x404×2 / 0x94×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22688c push {r4, r5, r6, lr}
 *   @0x226890 sub sp, sp, #1024
 *   @0x226894 ldr r4, [pc, #0x94]
 *   @0x226898 sub sp, sp, #8
 *   @0x22689c ldrb r3, [r1, #0x24]
 *   @0x2268a0 mov r5, r1
 *   @0x2268a4 ldr r4, [pc, r4]
 *   @0x2268a8 cmp r3, #0
 *   @0x2268ac ldr r3, [r4]
 *   @0x2268b0 str r3, [sp, #0x404]
 *   @0x2268b4 beq 0x2268c4 <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound+0x38>
 *   @0x2268b8 ldr r3, [r1, #0x30]
 *   @0x2268bc cmp r3, #0
 *   @0x2268c0 beq 0x2268e8 <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound+0x5c>
 *   @0x2268c4 mov r0, r5
 *   @0x2268c8 bl 0x223eb0 <_Z13GetStreamInfoP12cAudio_Sound>
 *   @0x2268cc ldr r2, [sp, #0x404]
 *   @0x2268d0 ldr r3, [r4]
 *   @0x2268d4 cmp r2, r3
 *   @0x2268d8 bne 0x22692c <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound+0xa0>
 *   @0x2268dc add sp, sp, #1024
 *   @0x2268e0 add sp, sp, #8
 *   @0x2268e4 pop {r4, r5, r6, pc}
 *   @0x2268e8 add r6, sp, #4
 *   @0x2268ec mov r1, #1024
 *   @0x2268f0 ldr r2, [r5]
 *   @0x2268f4 mov r0, r6
 *   @0x2268f8 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x2268fc mov r0, r6
 *   @0x226900 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x226904 cmp r0, #0
 *   @0x226908 beq 0x2268c4 <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound+0x38>
 *   @0x22690c ldr r0, [r5, #0x30]
 *   @0x226910 cmp r0, #0
 *   @0x226914 beq 0x22691c <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound+0x90>
 *   @0x226918 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x22691c mov r0, r6
 *   @0x226920 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x226924 str r0, [r5, #0x30]
 *   @0x226928 b 0x2268c4 <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound+0x38>
 *   @0x22692c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x226930 andseq r7, r12, r12, lsr #1
 *
 * ══ §90/181 CPhysicsObject::SetLinearVelocity(float, float)  0x236e9c  size 168  42 条（0x236e9c..0x236f44）
 * @func 0x236e9c 0x236f44  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsObject::SetLinearVelocity(float, float)+0x90 / b2Body::SetType(b2BodyType)
 * 字段偏移 top8: 0x4×2
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236e9c push {r4, lr}
 *   @0x236ea0 vpush {d8}
 *   @0x236ea4 vmov s17, r2
 *   @0x236ea8 vmov s16, r1
 *   @0x236eac mov r4, r0
 *   @0x236eb0 vmul.f32 s15, s17, s17
 *   @0x236eb4 ldr r0, [r0]
 *   @0x236eb8 ldr r2, [r0]
 *   @0x236ebc vmla.f32 s15, s16, s16
 *   @0x236ec0 vcmpe.f32 s15, #0
 *   @0x236ec4 vmrs APSR_nzcv, fpscr
 *   @0x236ec8 ble 0x236f2c <_ZN14CPhysicsObject17SetLinearVelocityEff+0x90>
 *   @0x236ecc cmp r2, #0
 *   @0x236ed0 bne 0x236eec <_ZN14CPhysicsObject17SetLinearVelocityEff+0x50>
 *   @0x236ed4 mov r1, #1
 *   @0x236ed8 bl 0x2c7378 <_ZN6b2Body7SetTypeE10b2BodyType>
 *   @0x236edc ldr r0, [r4]
 *   @0x236ee0 ldr r2, [r0]
 *   @0x236ee4 cmp r2, #0
 *   @0x236ee8 beq 0x236f0c <_ZN14CPhysicsObject17SetLinearVelocityEff+0x70>
 *   @0x236eec ldrh r2, [r0, #4]
 *   @0x236ef0 tst r2, #2
 *   @0x236ef4 orreq r2, r2, #2
 *   @0x236ef8 strheq r2, [r0, #4]
 *   @0x236efc moveq r1, #0
 *   @0x236f00 streq r1, [r0, #0xa0]
 *   @0x236f04 vstr s16, [r0, #80]
 *   @0x236f08 vstr s17, [r0, #84]
 *   @0x236f0c ldrh r2, [r0, #4]
 *   @0x236f10 tst r2, #2
 *   @0x236f14 orreq r2, r2, #2
 *   @0x236f18 moveq r1, #0
 *   @0x236f1c strheq r2, [r0, #4]
 *   @0x236f20 streq r1, [r0, #0xa0]
 *   @0x236f24 vpop {d8}
 *   @0x236f28 pop {r4, pc}
 *   @0x236f2c cmp r2, #0
 *   @0x236f30 beq 0x236f0c <_ZN14CPhysicsObject17SetLinearVelocityEff+0x70>
 *   @0x236f34 vcmpe.f32 s15, #0
 *   @0x236f38 vmrs APSR_nzcv, fpscr
 *   @0x236f3c bgt 0x236eec <_ZN14CPhysicsObject17SetLinearVelocityEff+0x50>
 *   @0x236f40 b 0x236f04 <_ZN14CPhysicsObject17SetLinearVelocityEff+0x68>
 *
 * ══ §91/181 F_JS_Object_getOwnPropertyDescriptor(RValue&, CInstance*, CInstance*, int, RValue*)  0x255244  size 168  42 条（0x255244..0x2552ec）
 * @func 0x255244 0x2552ec  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JSThrowTypeError(char const*)×2 / F_JS_ToString(RValue&, RValue*) / JS_GetOwnProperty(YYObjectBase*, RValue*, char const*) / F_JS_FromPropertyDescriptor(RValue*, RValue*)
 * 字段偏移 top8: 0x30×3 / 0xc×2 / 0x70×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x255244 cmp r3, #0
 *   @0x255248 push {r4, r5, lr}
 *   @0x25524c mov r4, r0
 *   @0x255250 sub sp, sp, #36
 *   @0x255254 beq 0x25526c <_Z36F_JS_Object_getOwnPropertyDescriptorR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x255258 ldr r2, [sp, #0x30]
 *   @0x25525c ldr r3, [r2, #0xc]
 *   @0x255260 bic r3, r3, #-16777216
 *   @0x255264 cmp r3, #6
 *   @0x255268 beq 0x255280 <_Z36F_JS_Object_getOwnPropertyDescriptorR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x25526c ldr r0, [pc, #0x70]
 *   @0x255270 add r0, pc, r0
 *   @0x255274 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x255278 add sp, sp, #36
 *   @0x25527c pop {r4, r5, pc}
 *   @0x255280 ldr r3, [sp, #0x30]
 *   @0x255284 mov r0, sp
 *   @0x255288 add r1, r3, #16
 *   @0x25528c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x255290 cmp r0, #2
 *   @0x255294 beq 0x255278 <_Z36F_JS_Object_getOwnPropertyDescriptorR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x255298 cmp r0, #1
 *   @0x25529c beq 0x2552d4 <_Z36F_JS_Object_getOwnPropertyDescriptorR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x2552a0 ldr r2, [sp, #0x30]
 *   @0x2552a4 add r5, sp, #16
 *   @0x2552a8 ldr r3, [sp]
 *   @0x2552ac mov r1, r5
 *   @0x2552b0 ldr r0, [r2]
 *   @0x2552b4 mov r2, #5
 *   @0x2552b8 str r2, [sp, #0x1c]
 *   @0x2552bc ldr r2, [r3]
 *   @0x2552c0 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x2552c4 mov r0, r4
 *   @0x2552c8 mov r1, r5
 *   @0x2552cc bl 0x2483e0 <_Z27F_JS_FromPropertyDescriptorP6RValueS0_>
 *   @0x2552d0 b 0x255278 <_Z36F_JS_Object_getOwnPropertyDescriptorR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x2552d4 ldr r0, [pc, #0xc]
 *   @0x2552d8 add r0, pc, r0
 *   @0x2552dc bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2552e0 b 0x255278 <_Z36F_JS_Object_getOwnPropertyDescriptorR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x2552e4 ldrsbeq r0, [r0], -r8
 *   @0x2552e8 andseq r1, r0, r0, asr #13
 *
 * ══ §92/181 CLangMan::GetActiveLanguage(char const**, char const**)  0x27a810  size 168  42 条（0x27a810..0x27a8b8）
 * @func 0x27a810 0x27a8b8  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*)×2 / CLangMan::GetActiveLanguage(char const**, char const**)+0x40 / CLangMan::GetActiveLanguage(char const**, char const**)+0x54
 * 字段偏移 top8: 0x4×3 / 0x7c×1 / 0x6c×1 / 0x48×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27a810 cmp r1, #0
 *   @0x27a814 cmpne r0, #0
 *   @0x27a818 push {r4, r5, r6, lr}
 *   @0x27a81c mov r5, r0
 *   @0x27a820 sub sp, sp, #8
 *   @0x27a824 beq 0x27a85c <_ZN8CLangMan17GetActiveLanguageEPPKcS2_+0x4c>
 *   @0x27a828 ldr r4, [pc, #0x7c]
 *   @0x27a82c ldr r4, [pc, r4]
 *   @0x27a830 ldr r3, [r4]
 *   @0x27a834 cmp r3, #0
 *   @0x27a838 blt 0x27a850 <_ZN8CLangMan17GetActiveLanguageEPPKcS2_+0x40>
 *   @0x27a83c ldr r2, [pc, #0x6c]
 *   @0x27a840 ldr r2, [pc, r2]
 *   @0x27a844 ldr r2, [r2]
 *   @0x27a848 cmp r3, r2
 *   @0x27a84c blt 0x27a864 <_ZN8CLangMan17GetActiveLanguageEPPKcS2_+0x54>
 *   @0x27a850 mov r3, #0
 *   @0x27a854 str r3, [r5]
 *   @0x27a858 str r3, [r1]
 *   @0x27a85c add sp, sp, #8
 *   @0x27a860 pop {r4, r5, r6, pc}
 *   @0x27a864 ldr r6, [pc, #0x48]
 *   @0x27a868 add r3, r3, r3, lsl #1
 *   @0x27a86c ldr r6, [pc, r6]
 *   @0x27a870 ldr r2, [r6]
 *   @0x27a874 ldr r0, [r2, r3, lsl #2]
 *   @0x27a878 str r1, [sp, #0x4]
 *   @0x27a87c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x27a880 ldr r3, [r4]
 *   @0x27a884 add r3, r3, r3, lsl #1
 *   @0x27a888 str r0, [r5]
 *   @0x27a88c ldr r2, [r6]
 *   @0x27a890 add r3, r2, r3, lsl #2
 *   @0x27a894 ldr r0, [r3, #0x4]
 *   @0x27a898 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x27a89c ldr r1, [sp, #0x4]
 *   @0x27a8a0 str r0, [r1]
 *   @0x27a8a4 add sp, sp, #8
 *   @0x27a8a8 pop {r4, r5, r6, pc}
 *   @0x27a8ac andseq r6, r7, r12, ror #31
 *   @0x27a8b0 andseq r6, r7, r8, asr #31
 *   @0x27a8b4 andseq r6, r7, r4, lsr #31
 *
 * ══ §93/181 DebuggerRunBackgroundMessageLoop()  0x29cb88  size 168  42 条（0x29cb88..0x29cc30）
 * @func 0x29cb88 0x29cc30  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / CProfiler::Pause(bool) / Mutex::Mutex(char const*)
 * 字段偏移 top8: 0x84×2 / 0x214×2 / 0x6c×1 / 0x8×1 / 0x4×1 / 0x9×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29cb88 push {r4, r5, r6, r7, r8, lr}
 *   @0x29cb8c mov r1, #1
 *   @0x29cb90 ldr r5, [pc, #0x84]
 *   @0x29cb94 ldr r0, [pc, #0x84]
 *   @0x29cb98 add r5, pc, r5
 *   @0x29cb9c ldr r0, [pc, r0]
 *   @0x29cba0 bl 0x2a04b8 <_ZN9CProfiler5PauseEb>
 *   @0x29cba4 ldr r4, [r5, #0x214]
 *   @0x29cba8 cmp r4, #0
 *   @0x29cbac popne {r4, r5, r6, r7, r8, pc}
 *   @0x29cbb0 ldr r3, [pc, #0x6c]
 *   @0x29cbb4 mov r0, #24
 *   @0x29cbb8 ldr r3, [pc, r3]
 *   @0x29cbbc strb r4, [r3]
 *   @0x29cbc0 bl 0x27c524 <_Znwj>
 *   @0x29cbc4 mov r6, r0
 *   @0x29cbc8 mov r0, #8
 *   @0x29cbcc strb r4, [r6, #0x8]
 *   @0x29cbd0 str r4, [r6]
 *   @0x29cbd4 str r4, [r6, #0x4]
 *   @0x29cbd8 strb r4, [r6, #0x9]
 *   @0x29cbdc str r4, [r6, #0xc]
 *   @0x29cbe0 str r4, [r6, #0x10]
 *   @0x29cbe4 bl 0x27c524 <_Znwj>
 *   @0x29cbe8 ldr r1, [pc, #0x38]
 *   @0x29cbec add r1, pc, r1
 *   @0x29cbf0 mov r7, r0
 *   @0x29cbf4 bl 0x27e070 <_ZN5MutexC2EPKc>
 *   @0x29cbf8 ldr r1, [pc, #0x2c]
 *   @0x29cbfc mov r0, r6
 *   @0x29cc00 str r7, [r6, #0x14]
 *   @0x29cc04 mov r2, r4
 *   @0x29cc08 str r6, [r5, #0x214]
 *   @0x29cc0c add r1, pc, r1
 *   @0x29cc10 mov r3, #1
 *   @0x29cc14 pop {r4, r5, r6, r7, r8, lr}
 *   @0x29cc18 b 0x27e0c0 <_ZN7CThread5StartEPFPvS0_ES0_NS_9ePriorityE>
 *   @0x29cc1c subeq r11, r11, r0, ror r0
 *   @0x29cc20 ldrsbeq r0, [r5], -r0
 *   @0x29cc24 andseq r1, r5, r4, lsl #3
 *   @0x29cc28 andeq r5, r9, r8, asr #23
 *   @0x29cc2c andeq r0, r0, r12, lsl #22
 *
 * ══ §94/181 jinit_phuff_decoder  0x2b7fdc  size 168  42 条（0x2b7fdc..0x2b8084）
 * @func 0x2b7fdc 0x2b8084  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x24×3 / 0x70×1 / 0x198×1 / 0x2c×1 / 0x30×1 / 0x34×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b7fdc push {r3, r4, r5, lr}
 *   @0x2b7fe0 mov r1, #1
 *   @0x2b7fe4 ldr r3, [r0, #0x4]
 *   @0x2b7fe8 mov r2, #64
 *   @0x2b7fec mov r5, r0
 *   @0x2b7ff0 mov r4, #0
 *   @0x2b7ff4 ldr r3, [r3]
 *   @0x2b7ff8 blx r3
 *   @0x2b7ffc ldr r12, [r5, #0x4]
 *   @0x2b8000 ldr r2, [r5, #0x24]
 *   @0x2b8004 mov r1, #1
 *   @0x2b8008 ldr lr, [pc, #0x70]
 *   @0x2b800c ldr r12, [r12]
 *   @0x2b8010 add lr, pc, lr
 *   @0x2b8014 lsl r2, r2, #8
 *   @0x2b8018 mov r3, r0
 *   @0x2b801c mov r0, r5
 *   @0x2b8020 str r3, [r5, #0x198]
 *   @0x2b8024 str lr, [r3]
 *   @0x2b8028 str r4, [r3, #0x2c]
 *   @0x2b802c str r4, [r3, #0x30]
 *   @0x2b8030 str r4, [r3, #0x34]
 *   @0x2b8034 str r4, [r3, #0x38]
 *   @0x2b8038 blx r12
 *   @0x2b803c ldr r2, [r5, #0x24]
 *   @0x2b8040 cmp r2, r4
 *   @0x2b8044 mov r3, r0
 *   @0x2b8048 str r0, [r5, #0x8c]
 *   @0x2b804c pople {r3, r4, r5, pc}
 *   @0x2b8050 mov r12, r4
 *   @0x2b8054 mvn r1, #0
 *   @0x2b8058 add r2, r3, #256
 *   @0x2b805c str r1, [r3], #4
 *   @0x2b8060 cmp r2, r3
 *   @0x2b8064 bne 0x2b805c <jinit_phuff_decoder+0x80>
 *   @0x2b8068 ldr r4, [r5, #0x24]
 *   @0x2b806c add r12, r12, #1
 *   @0x2b8070 mov r3, r2
 *   @0x2b8074 cmp r4, r12
 *   @0x2b8078 bgt 0x2b8058 <jinit_phuff_decoder+0x7c>
 *   @0x2b807c pop {r3, r4, r5, pc}
 *   @0x2b8080 .word 0xfffff1c0
 *
 * ══ §95/181 DGifGetLine(GifFileType*, unsigned char*, int)  0x2c26a8  size 168  42 条（0x2c26a8..0x2c2750）
 * @func 0x2c26a8 0x2c2750  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DGifGetLine(GifFileType*, unsigned char*, int)+0x54 / anon_2c143c+0x25c / DGifGetCodeNext(GifFileType*, unsigned char**)
 * 字段偏移 top8: 0x34×3 / 0x48×1 / 0x40×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c26a8 push {r4, r5, lr}
 *   @0x2c26ac mov r4, r0
 *   @0x2c26b0 ldr r5, [r0, #0x48]
 *   @0x2c26b4 sub sp, sp, #12
 *   @0x2c26b8 ldr r0, [r5]
 *   @0x2c26bc ands r0, r0, #8
 *   @0x2c26c0 moveq r3, #111
 *   @0x2c26c4 streq r3, [r4, #0x40]
 *   @0x2c26c8 beq 0x2c26f4 <_Z11DGifGetLineP11GifFileTypePhi+0x4c>
 *   @0x2c26cc cmp r2, #0
 *   @0x2c26d0 ldr r3, [r5, #0x34]
 *   @0x2c26d4 ldreq r2, [r4, #0x24]
 *   @0x2c26d8 rsb r3, r2, r3
 *   @0x2c26dc str r3, [r5, #0x34]
 *   @0x2c26e0 cmn r3, #65536
 *   @0x2c26e4 bls 0x2c26fc <_Z11DGifGetLineP11GifFileTypePhi+0x54>
 *   @0x2c26e8 mov r0, #0
 *   @0x2c26ec mov r3, #108
 *   @0x2c26f0 str r3, [r4, #0x40]
 *   @0x2c26f4 add sp, sp, #12
 *   @0x2c26f8 pop {r4, r5, pc}
 *   @0x2c26fc mov r0, r4
 *   @0x2c2700 bl 0x2c1698 <jpeg_mem_term+0x260>
 *   @0x2c2704 cmp r0, #1
 *   @0x2c2708 movne r0, #0
 *   @0x2c270c bne 0x2c26f4 <_Z11DGifGetLineP11GifFileTypePhi+0x4c>
 *   @0x2c2710 ldr r3, [r5, #0x34]
 *   @0x2c2714 cmp r3, #0
 *   @0x2c2718 bne 0x2c26f4 <_Z11DGifGetLineP11GifFileTypePhi+0x4c>
 *   @0x2c271c add r5, sp, #4
 *   @0x2c2720 b 0x2c2730 <_Z11DGifGetLineP11GifFileTypePhi+0x88>
 *   @0x2c2724 ldr r3, [sp, #0x4]
 *   @0x2c2728 cmp r3, #0
 *   @0x2c272c beq 0x2c2748 <_Z11DGifGetLineP11GifFileTypePhi+0xa0>
 *   @0x2c2730 mov r0, r4
 *   @0x2c2734 mov r1, r5
 *   @0x2c2738 bl 0x2c25c0 <_Z15DGifGetCodeNextP11GifFileTypePPh>
 *   @0x2c273c cmp r0, #0
 *   @0x2c2740 bne 0x2c2724 <_Z11DGifGetLineP11GifFileTypePhi+0x7c>
 *   @0x2c2744 b 0x2c26f4 <_Z11DGifGetLineP11GifFileTypePhi+0x4c>
 *   @0x2c2748 mov r0, #1
 *   @0x2c274c b 0x2c26f4 <_Z11DGifGetLineP11GifFileTypePhi+0x4c>
 *
 * ══ §96/181 b2ChainShape::RayCast(b2RayCastOutput*, b2RayCastInput const&, b2Transform const&, int) const  0x2c49c0  size 168  42 条（0x2c49c0..0x2c4a68）
 * @func 0x2c49c0 0x2c4a68  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2EdgeShape::RayCast(b2RayCastOutput*, b2RayCastInput const&, b2Transform const&, int) const
 * 字段偏移 top8: 0x10×2 / 0xc×2 / 0x48×1 / 0x84×1 / 0x34×1 / 0x35×1 / 0x8×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c49c0 push {r4, r5, r6, lr}
 *   @0x2c49c4 sub sp, sp, #56
 *   @0x2c49c8 ldr lr, [r0, #0x10]
 *   @0x2c49cc mov r5, r1
 *   @0x2c49d0 ldr r4, [sp, #0x48]
 *   @0x2c49d4 movw r6, #0xd70a
 *   @0x2c49d8 ldr r12, [pc, #0x84]
 *   @0x2c49dc movt r6, #0x3c23
 *   @0x2c49e0 add r1, r4, #1
 *   @0x2c49e4 str r6, [sp, #0x10]
 *   @0x2c49e8 cmp lr, r1
 *   @0x2c49ec mov lr, #1
 *   @0x2c49f0 str lr, [sp, #0xc]
 *   @0x2c49f4 mov lr, #0
 *   @0x2c49f8 strb lr, [sp, #0x34]
 *   @0x2c49fc ldr r12, [pc, r12]
 *   @0x2c4a00 strb lr, [sp, #0x35]
 *   @0x2c4a04 lslne lr, r1, #3
 *   @0x2c4a08 ldr r1, [r0, #0xc]
 *   @0x2c4a0c add r12, r12, #8
 *   @0x2c4a10 str r12, [sp, #0x8]
 *   @0x2c4a14 mov r12, #0
 *   @0x2c4a18 add r4, r1, r4, lsl #3
 *   @0x2c4a1c str r12, [sp, #0x24]
 *   @0x2c4a20 str r12, [sp, #0x28]
 *   @0x2c4a24 add lr, r1, lr
 *   @0x2c4a28 str r12, [sp, #0x2c]
 *   @0x2c4a2c mov r6, #0
 *   @0x2c4a30 str r12, [sp, #0x30]
 *   @0x2c4a34 add r12, sp, #20
 *   @0x2c4a38 ldm r4, {r0, r1}
 *   @0x2c4a3c stm r12, {r0, r1}
 *   @0x2c4a40 add r12, sp, #28
 *   @0x2c4a44 ldm lr, {r0, r1}
 *   @0x2c4a48 str r6, [sp]
 *   @0x2c4a4c stm r12, {r0, r1}
 *   @0x2c4a50 mov r1, r5
 *   @0x2c4a54 add r0, sp, #8
 *   @0x2c4a58 bl 0x2c534c <_ZNK11b2EdgeShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi>
 *   @0x2c4a5c add sp, sp, #56
 *   @0x2c4a60 pop {r4, r5, r6, pc}
 *   @0x2c4a64 ldrheq r12, [r2], -r8
 *
 * ══ §97/181 b2World::DrawParticleSystem(b2ParticleSystem const&)  0x2cacf4  size 168  42 条（0x2cacf4..0x2cad9c）
 * @func 0x2cacf4 0x2cad9c  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::GetParticleRadius() const / b2ParticleSystem::GetParticlePositionBuffer() const / b2ParticleSystem::GetParticleColorBuffer() const
 * 字段偏移 top8: 0x18×2 / 0x24×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cacf4 push {r4, r5, r6, r7, r8, lr}
 *   @0x2cacf8 mov r4, r1
 *   @0x2cacfc ldr r5, [r1, #0x24]
 *   @0x2cad00 sub sp, sp, #8
 *   @0x2cad04 mov r6, r0
 *   @0x2cad08 cmp r5, #0
 *   @0x2cad0c bne 0x2cad18 <_ZN7b2World18DrawParticleSystemERK16b2ParticleSystem+0x24>
 *   @0x2cad10 add sp, sp, #8
 *   @0x2cad14 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2cad18 mov r0, r1
 *   @0x2cad1c bl 0x2d82d4 <_ZNK16b2ParticleSystem17GetParticleRadiusEv>
 *   @0x2cad20 mov r7, r0
 *   @0x2cad24 mov r0, r4
 *   @0x2cad28 bl 0x2d990c <_ZNK16b2ParticleSystem25GetParticlePositionBufferEv>
 *   @0x2cad2c ldr r3, [r4, #0x54]
 *   @0x2cad30 cmp r3, #0
 *   @0x2cad34 mov r8, r0
 *   @0x2cad38 beq 0x2cad74 <_ZN7b2World18DrawParticleSystemERK16b2ParticleSystem+0x80>
 *   @0x2cad3c mov r0, r4
 *   @0x2cad40 bl 0x2d991c <_ZNK16b2ParticleSystem22GetParticleColorBufferEv>
 *   @0x2cad44 movw r12, #0x9248
 *   @0x2cad48 movt r12, #0x1
 *   @0x2cad4c mov r1, r8
 *   @0x2cad50 mov r2, r7
 *   @0x2cad54 mov r3, r0
 *   @0x2cad58 ldr r0, [r6, r12]
 *   @0x2cad5c ldr lr, [r0]
 *   @0x2cad60 str r5, [sp]
 *   @0x2cad64 ldr r12, [lr, #0x18]
 *   @0x2cad68 blx r12
 *   @0x2cad6c add sp, sp, #8
 *   @0x2cad70 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2cad74 movw r0, #0x9248
 *   @0x2cad78 movt r0, #0x1
 *   @0x2cad7c mov r1, r8
 *   @0x2cad80 mov r2, r7
 *   @0x2cad84 ldr r0, [r6, r0]
 *   @0x2cad88 ldr r12, [r0]
 *   @0x2cad8c str r5, [sp]
 *   @0x2cad90 ldr r12, [r12, #0x18]
 *   @0x2cad94 blx r12
 *   @0x2cad98 b 0x2cad10 <_ZN7b2World18DrawParticleSystemERK16b2ParticleSystem+0x1c>
 *
 * ══ §98/181 b2ParticleSystem::ComputeParticleCollisionEnergy() const  0x2d9fe8  size 168  42 条（0x2d9fe8..0x2da090）
 * @func 0x2d9fe8 0x2da090  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::ComputeParticleCollisionEnergy() const+0x9c / b2ParticleSystem::GetParticleMass() const
 * 字段偏移 top8: 0x74×1 / 0x7c×1 / 0x40×1 / 0x-c×1 / 0x-10×1
 * VFP 指令 22 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9fe8 push {r3, lr}
 *   @0x2d9fec vpush {d8}
 *   @0x2d9ff0 ldr lr, [r0, #0x74]
 *   @0x2d9ff4 cmp lr, #0
 *   @0x2d9ff8 ble 0x2da084 <_ZNK16b2ParticleSystem30ComputeParticleCollisionEnergyEv+0x9c>
 *   @0x2d9ffc ldr r3, [r0, #0x7c]
 *   @0x2da000 add lr, lr, lr, lsl #1
 *   @0x2da004 ldr r12, [r0, #0x40]
 *   @0x2da008 vldr s16, [pc, #124]
 *   @0x2da00c add r3, r3, #16
 *   @0x2da010 add lr, r3, lr, lsl #3
 *   @0x2da014 ldr r1, [r3, #-0xc]
 *   @0x2da018 vldr s11, [r3, #4]
 *   @0x2da01c ldr r2, [r3, #-0x10]
 *   @0x2da020 vldr s14, [r3]
 *   @0x2da024 add r3, r3, #24
 *   @0x2da028 add r1, r12, r1, lsl #3
 *   @0x2da02c vldr s13, [r1, #4]
 *   @0x2da030 add r2, r12, r2, lsl #3
 *   @0x2da034 vldr s15, [r2, #4]
 *   @0x2da038 vsub.f32 s15, s13, s15
 *   @0x2da03c vldr s12, [r1]
 *   @0x2da040 vldr s13, [r2]
 *   @0x2da044 vmul.f32 s15, s15, s11
 *   @0x2da048 vsub.f32 s13, s12, s13
 *   @0x2da04c vmla.f32 s15, s13, s14
 *   @0x2da050 vcmpe.f32 s15, #0
 *   @0x2da054 vmrs APSR_nzcv, fpscr
 *   @0x2da058 vmlami.f32 s16, s15, s15
 *   @0x2da05c cmp r3, lr
 *   @0x2da060 bne 0x2da014 <_ZNK16b2ParticleSystem30ComputeParticleCollisionEnergyEv+0x2c>
 *   @0x2da064 bl 0x2d85bc <_ZNK16b2ParticleSystem15GetParticleMassEv>
 *   @0x2da068 vmov.f32 s15, #5.000000e-01
 *   @0x2da06c vmov s14, r0
 *   @0x2da070 vmul.f32 s15, s14, s15
 *   @0x2da074 vmul.f32 s15, s15, s16
 *   @0x2da078 vpop {d8}
 *   @0x2da07c vmov r0, s15
 *   @0x2da080 pop {r3, pc}
 *   @0x2da084 vldr s16, [pc]
 *   @0x2da088 b 0x2da064 <_ZNK16b2ParticleSystem30ComputeParticleCollisionEnergyEv+0x7c>
 *   @0x2da08c andeq r0, r0, r0
 *
 * ══ §99/181 FT_Face_Properties  0x2e59f8  size 168  42 条（0x2e59f8..0x2e5aa0）
 * @func 0x2e59f8 0x2e5aa0  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xffa31c7c
 * 字段偏移 top8: 0x8c×1 / 0x3c×1 / 0x44×1 / 0x54×1 / 0x9×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e59f8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e59fc cbnz r1, 0x2e5a18 <FT_Face_Properties+0x20>
 *   @0x2e5a00 ldr.w r11, [pc, #0x98]
 *   @0x2e5a04 ldr r6, [pc, #0x8c]
 *   @0x2e5a08 svcmi #0x233cff
 *   @0x2e5a0c movs r4, #0x0
 *   @0x2e5a10 .word 0xf04f08ff
 *   @0x2e5a14 ands r0, r10, r1, lsl #18
 *   @0x2e5a18 cmp r2, #0x0
 *   @0x2e5a1c movs r0, #0x6
 *   @0x2e5a20 .word 0xf8528ff0
 *   @0x2e5a24 ldrbmi r3, [r11, #-0xc08]
 *   @0x2e5a28 bne 0x2e5a5a <FT_Face_Properties+0x62>
 *   @0x2e5a2c .word 0xf8d0ac04
 *   @0x2e5a30 .word 0xf1ba3080
 *   @0x2e5a34 andle r0, sp, r0, lsl #30
 *   @0x2e5a38 ldrb.w r10, [r10]
 *   @0x2e5a3c cmp.w r10, #0x1
 *   @0x2e5a40 ite ne
 *   @0x2e5a44 moveq r10, r4
 *   @0x2e5a48 stmdblo r1, {r3, r4, r5, sp, pc}
 *   @0x2e5a4c adds r2, #0x8
 *   @0x2e5a50 bne 0x2e5a22 <FT_Face_Properties+0x2a>
 *   @0x2e5a54 strb.w r8, [r3, #0x38]
 *   @0x2e5a58 b 0x2e5a4a <FT_Face_Properties+0x52>
 *   @0x2e5a5c beq 0x2e5a8c <FT_Face_Properties+0x94>
 *   @0x2e5a60 bne 0x2e5a1c <FT_Face_Properties+0x24>
 *   @0x2e5a64 .word 0xf8d03c04
 *   @0x2e5a68 smlalbblt r10, r11, r0, r0
 *   @0x2e5a6c ldr r3, [r3]
 *   @0x2e5a70 .word 0xf8d0303c
 *   @0x2e5a74 blvs 0xffa31c7c <b2_toiTime+0xffffffffff2d87d8>
 *   @0x2e5a78 cmp r5, #0x0
 *   @0x2e5a7c str r4, [r3, #0x3c]
 *   @0x2e5a80 str.w r12, [r10, #0x3c]
 *   @0x2e5a84 b 0x2e5a4a <FT_Face_Properties+0x52>
 *   @0x2e5a88 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e5a8c movs r0, #0x7
 *   @0x2e5a90 svclt #0x8ff0
 *   @0x2e5a94 str r6, [r4, #0x44]
 *   @0x2e5a98 str r4, [r4, #0x54]
 *   @0x2e5a9c strb r3, [r5, #0x9]
 *
 * ══ §100/181 png_write_png  0x2b0958  size 166  42 条（0x2b0958..0x2b09fe）
 * @func 0x2b0958 0x2b09fe  size 166  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_info / png_set_packing / png_set_filler / png_set_swap / png_set_invert_alpha / png_write_image
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0958 push {r4, r5, r6, lr}
 *   @0x2b095c mov r5, r2
 *   @0x2b0960 cmp r0, #0x0
 *   @0x2b0964 cmp r1, #0x0
 *   @0x2b0968 bl 0x2afe14 <png_write_info>
 *   @0x2b096c lsls r1, r5, #0x1a
 *   @0x2b0970 mov r0, r4
 *   @0x2b0974 strbteq pc, [r10], -r10, ror #30
 *   @0x2b0978 bpl 0x2b098a <png_write_png+0x32>
 *   @0x2b097c lsls r3, r3, #0x1e
 *   @0x2b0980 mov r0, r4
 *   @0x2b0984 .word 0xf7fe0144
 *   @0x2b0988 strbeq pc, [r8, -r6, lsl #30]!
 *   @0x2b098c bpl 0x2b0994 <png_write_png+0x3c>
 *   @0x2b0990 bl 0x2af760 <png_set_packing>
 *   @0x2b0994 lsls r1, r5, #0x17
 *   @0x2b0998 mov r0, r4
 *   @0x2b099c .word 0xf415ff46
 *   @0x2b09a0 andle r5, r3, r0, lsl #3
 *   @0x2b09a4 mov r0, r4
 *   @0x2b09a8 movs r2, #0x1
 *   @0x2b09ac lsls r2, r5, #0x14
 *   @0x2b09b0 mov r0, r4
 *   @0x2b09b4 bl 0x2af7ce <png_set_filler>
 *   @0x2b09b8 lsls r3, r5, #0x18
 *   @0x2b09bc mov r0, r4
 *   @0x2b09c0 streq pc, [r8, #0xebb]!
 *   @0x2b09c4 bpl 0x2b09cc <png_write_png+0x74>
 *   @0x2b09c8 bl 0x2af748 <png_set_swap>
 *   @0x2b09cc lsls r1, r5, #0x1c
 *   @0x2b09d0 mov r0, r4
 *   @0x2b09d4 strbeq pc, [r10, #-0xed4]!
 *   @0x2b09d8 bpl 0x2b09e0 <png_write_png+0x88>
 *   @0x2b09dc bl 0x2af83a <png_set_invert_alpha>
 *   @0x2b09e0 ldr r3, [r6, #0x8]
 *   @0x2b09e4 bpl 0x2b09f0 <png_write_png+0x98>
 *   @0x2b09e8 ldr.w r1, [r6, #0xf8]
 *   @0x2b09ec bl 0x2b0510 <png_write_image>
 *   @0x2b09f0 mov r0, r4
 *   @0x2b09f4 pop.w {r4, r5, r6, lr}
 *   @0x2b09f8 b.w 0x2b002c <png_write_end>
 *   @0x2b09fc pop {r4, r5, r6, pc}
 *
 * ══ §101/181 CSkeletonSprite::CSkeletonSprite(char*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int)  0xbd86c  size 164  41 条（0xbd86c..0xbd910）
 * @func 0xbd86c 0xbd910  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonSprite::SimpleDecode(unsigned char*, int)×2 / spAtlas_create / spSkeletonJson_create / spSkeletonJson_readSkeletonData
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0x8c×1 / 0x28×1 / 0x2c×1 / 0x30×1 / 0xc×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbd86c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xbd870 add r8, r1, r2
 *   @0xbd874 ldr r12, [pc, #0x8c]
 *   @0xbd878 mov r4, r0
 *   @0xbd87c ldr r11, [sp, #0x28]
 *   @0xbd880 mov r7, r3
 *   @0xbd884 ldr r10, [sp, #0x2c]
 *   @0xbd888 add r12, pc, r12
 *   @0xbd88c ldr r9, [sp, #0x30]
 *   @0xbd890 mov r5, #0
 *   @0xbd894 add lr, r2, r3
 *   @0xbd898 str r5, [r0]
 *   @0xbd89c str r5, [r0, #0x4]
 *   @0xbd8a0 add lr, r1, lr
 *   @0xbd8a4 str r5, [r0, #0x8]
 *   @0xbd8a8 mov r6, r1
 *   @0xbd8ac str lr, [r12]
 *   @0xbd8b0 str r11, [r12, #0x4]
 *   @0xbd8b4 str r10, [r12, #0x8]
 *   @0xbd8b8 str r9, [r12, #0xc]
 *   @0xbd8bc bl 0xbd840 <_ZN15CSkeletonSprite12SimpleDecodeEPhi>
 *   @0xbd8c0 mov r1, r8
 *   @0xbd8c4 mov r0, r4
 *   @0xbd8c8 mov r2, r7
 *   @0xbd8cc bl 0xbd840 <_ZN15CSkeletonSprite12SimpleDecodeEPhi>
 *   @0xbd8d0 ldr r2, [pc, #0x34]
 *   @0xbd8d4 mov r1, r7
 *   @0xbd8d8 mov r3, r5
 *   @0xbd8dc add r2, pc, r2
 *   @0xbd8e0 mov r0, r8
 *   @0xbd8e4 bl 0x284174 <spAtlas_create>
 *   @0xbd8e8 str r0, [r4, #0x8]
 *   @0xbd8ec bl 0x28b734 <spSkeletonJson_create>
 *   @0xbd8f0 mov r1, r6
 *   @0xbd8f4 str r0, [r4]
 *   @0xbd8f8 bl 0x28b84c <spSkeletonJson_readSkeletonData>
 *   @0xbd8fc str r0, [r4, #0x4]
 *   @0xbd900 mov r0, r4
 *   @0xbd904 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xbd908 eorseq r12, r11, r8, lsl #8
 *   @0xbd90c eoreq r1, r7, r10, asr r2
 *
 * ══ §102/181 CSkeletonSprite::DrawCollision(char const*, int, float, float, float, float, float, unsigned int)  0xbe9fc  size 164  41 条（0xbe9fc..0xbeaa0）
 * @func 0xbe9fc 0xbeaa0  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spBone_setYDown / operator new(unsigned int) / CSkeletonInstance::CSkeletonInstance(CSkeletonSprite*) / CSkeletonInstance::SelectAnimation(char const*) / CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*) / CSkeletonSprite::DrawCollisionBounds(spSkeletonBounds*) / CSkeletonInstance::~CSkeletonInstance()
 * 字段偏移 top8: 0x40×1 / 0x48×1 / 0x4c×1 / 0xc×1 / 0x4×1 / 0x8×1 / 0x20×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe9fc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xbea00 vpush {d8}
 *   @0xbea04 sub sp, sp, #20
 *   @0xbea08 vldr s16, [sp, #68]
 *   @0xbea0c mov r5, r0
 *   @0xbea10 mov r0, #1
 *   @0xbea14 mov r8, r2
 *   @0xbea18 mov r9, r3
 *   @0xbea1c mov r6, r1
 *   @0xbea20 ldr r7, [sp, #0x40]
 *   @0xbea24 ldr r11, [sp, #0x48]
 *   @0xbea28 ldr r10, [sp, #0x4c]
 *   @0xbea2c bl 0x284ed8 <spBone_setYDown>
 *   @0xbea30 mov r0, #52
 *   @0xbea34 bl 0x27c524 <_Znwj>
 *   @0xbea38 mov r1, r5
 *   @0xbea3c mov r4, r0
 *   @0xbea40 bl 0xbe67c <_ZN17CSkeletonInstanceC2EP15CSkeletonSprite>
 *   @0xbea44 mov r0, r4
 *   @0xbea48 mov r1, r6
 *   @0xbea4c bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc>
 *   @0xbea50 mov r12, #0
 *   @0xbea54 mov r2, r9
 *   @0xbea58 mov r3, r7
 *   @0xbea5c str r12, [sp, #0xc]
 *   @0xbea60 mov r1, r8
 *   @0xbea64 mov r0, r4
 *   @0xbea68 vstr s16, [sp]
 *   @0xbea6c str r11, [sp, #0x4]
 *   @0xbea70 str r10, [sp, #0x8]
 *   @0xbea74 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xbea78 mov r0, r5
 *   @0xbea7c ldr r1, [r4, #0x20]
 *   @0xbea80 bl 0xbdd30 <_ZN15CSkeletonSprite19DrawCollisionBoundsEP16spSkeletonBounds>
 *   @0xbea84 mov r0, r4
 *   @0xbea88 bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev>
 *   @0xbea8c mov r0, r4
 *   @0xbea90 add sp, sp, #20
 *   @0xbea94 vpop {d8}
 *   @0xbea98 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xbea9c b 0x27d1d0 <_ZdlPv>
 *
 * ══ §103/181 IBuffer::Base64decode(char const*, int, int)  0xcda18  size 164  41 条（0xcda18..0xcdabc）
 * @func 0xcda18 0xcdabc  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / base64_decode(char const*, unsigned int, char*, bool) / IBuffer::LoadFromFileInMemory(char*, int, int, int, int) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x74×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcda18 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xcda1c subs r6, r1, #0
 *   @0xcda20 mov r8, r0
 *   @0xcda24 sub sp, sp, #12
 *   @0xcda28 mov r7, r2
 *   @0xcda2c mov r9, r3
 *   @0xcda30 mov r0, r6
 *   @0xcda34 beq 0xcdab0 <_ZN7IBuffer12Base64decodeEPKcii+0x98>
 *   @0xcda38 bl 0xb6538 <strlen@plt>
 *   @0xcda3c ldr r1, [pc, #0x74]
 *   @0xcda40 movw r2, #0x4bd
 *   @0xcda44 mov r3, #1
 *   @0xcda48 add r1, pc, r1
 *   @0xcda4c add r5, r0, r0, lsl #1
 *   @0xcda50 cmp r5, #0
 *   @0xcda54 add r0, r5, #3
 *   @0xcda58 movlt r5, r0
 *   @0xcda5c asr r5, r5, #2
 *   @0xcda60 add r5, r5, #4
 *   @0xcda64 mov r0, r5
 *   @0xcda68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xcda6c mov r1, r5
 *   @0xcda70 mov r3, #0
 *   @0xcda74 mov r4, r0
 *   @0xcda78 mov r0, r6
 *   @0xcda7c mov r2, r4
 *   @0xcda80 bl 0x1d1ff0 <_Z13base64_decodePKcjPcb>
 *   @0xcda84 mov r2, r5
 *   @0xcda88 mov r1, r4
 *   @0xcda8c mov r3, #0
 *   @0xcda90 str r9, [sp]
 *   @0xcda94 mov r0, r8
 *   @0xcda98 str r7, [sp, #0x4]
 *   @0xcda9c bl 0xcd8a0 <_ZN7IBuffer20LoadFromFileInMemoryEPciiii>
 *   @0xcdaa0 mov r6, r0
 *   @0xcdaa4 mov r0, r4
 *   @0xcdaa8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcdaac mov r0, r6
 *   @0xcdab0 add sp, sp, #12
 *   @0xcdab4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xcdab8 eoreq r4, r6, r8, lsr #14
 *
 * ══ §104/181 F_DsStackCopy(RValue&, CInstance*, CInstance*, int, RValue*)  0xfba50  size 164  41 条（0xfba50..0xfbaf4）
 * @func 0xfba50 0xfbaf4  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_DsStackCopy(RValue&, CInstance*, CInstance*, int, RValue*)+0x84×2
 * 字段偏移 top8: 0x2×3 / 0x4×2 / 0x18×1 / 0x74×1 / 0x64×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfba50 push {r3, r4, r5, r6, r7, lr}
 *   @0xfba54 mov r1, #0
 *   @0xfba58 ldr r7, [sp, #0x18]
 *   @0xfba5c mov r0, r7
 *   @0xfba60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfba64 subs r5, r0, #0
 *   @0xfba68 blt 0xfbad4 <_Z13F_DsStackCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfba6c ldr r4, [pc, #0x74]
 *   @0xfba70 ldr r4, [pc, r4]
 *   @0xfba74 ldr r3, [r4]
 *   @0xfba78 cmp r5, r3
 *   @0xfba7c bge 0xfbad4 <_Z13F_DsStackCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfba80 ldr r6, [pc, #0x64]
 *   @0xfba84 ldr r6, [pc, r6]
 *   @0xfba88 ldr r3, [r6, #0x4]
 *   @0xfba8c ldr r3, [r3, r5, lsl #2]
 *   @0xfba90 cmp r3, #0
 *   @0xfba94 beq 0xfbad4 <_Z13F_DsStackCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfba98 mov r0, r7
 *   @0xfba9c mov r1, #1
 *   @0xfbaa0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfbaa4 cmp r0, #0
 *   @0xfbaa8 blt 0xfbad4 <_Z13F_DsStackCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfbaac ldr r3, [r4]
 *   @0xfbab0 cmp r0, r3
 *   @0xfbab4 bge 0xfbad4 <_Z13F_DsStackCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfbab8 ldr r3, [r6, #0x4]
 *   @0xfbabc ldr r1, [r3, r0, lsl #2]
 *   @0xfbac0 cmp r1, #0
 *   @0xfbac4 beq 0xfbad4 <_Z13F_DsStackCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfbac8 ldr r0, [r3, r5, lsl #2]
 *   @0xfbacc pop {r3, r4, r5, r6, r7, lr}
 *   @0xfbad0 b 0x20f514 <_ZN9CDS_Stack6AssignEPS_>
 *   @0xfbad4 ldr r0, [pc, #0x14]
 *   @0xfbad8 mov r1, #0
 *   @0xfbadc pop {r3, r4, r5, r6, r7, lr}
 *   @0xfbae0 add r0, pc, r0
 *   @0xfbae4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfbae8 eoreq r2, pc, r12, lsl #8
 *   @0xfbaec .word 0x002f23fc
 *   @0xfbaf0 eoreq r12, r3, r12, lsl r1
 *
 * ══ §105/181 F_DsQueueCopy(RValue&, CInstance*, CInstance*, int, RValue*)  0xfbe80  size 164  41 条（0xfbe80..0xfbf24）
 * @func 0xfbe80 0xfbf24  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_DsQueueCopy(RValue&, CInstance*, CInstance*, int, RValue*)+0x84×2
 * 字段偏移 top8: 0x2×3 / 0x4×2 / 0x18×1 / 0x74×1 / 0x64×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfbe80 push {r3, r4, r5, r6, r7, lr}
 *   @0xfbe84 mov r1, #0
 *   @0xfbe88 ldr r7, [sp, #0x18]
 *   @0xfbe8c mov r0, r7
 *   @0xfbe90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfbe94 subs r5, r0, #0
 *   @0xfbe98 blt 0xfbf04 <_Z13F_DsQueueCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfbe9c ldr r4, [pc, #0x74]
 *   @0xfbea0 ldr r4, [pc, r4]
 *   @0xfbea4 ldr r3, [r4]
 *   @0xfbea8 cmp r5, r3
 *   @0xfbeac bge 0xfbf04 <_Z13F_DsQueueCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfbeb0 ldr r6, [pc, #0x64]
 *   @0xfbeb4 ldr r6, [pc, r6]
 *   @0xfbeb8 ldr r3, [r6, #0x4]
 *   @0xfbebc ldr r3, [r3, r5, lsl #2]
 *   @0xfbec0 cmp r3, #0
 *   @0xfbec4 beq 0xfbf04 <_Z13F_DsQueueCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfbec8 mov r0, r7
 *   @0xfbecc mov r1, #1
 *   @0xfbed0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfbed4 cmp r0, #0
 *   @0xfbed8 blt 0xfbf04 <_Z13F_DsQueueCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfbedc ldr r3, [r4]
 *   @0xfbee0 cmp r0, r3
 *   @0xfbee4 bge 0xfbf04 <_Z13F_DsQueueCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfbee8 ldr r3, [r6, #0x4]
 *   @0xfbeec ldr r1, [r3, r0, lsl #2]
 *   @0xfbef0 cmp r1, #0
 *   @0xfbef4 beq 0xfbf04 <_Z13F_DsQueueCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfbef8 ldr r0, [r3, r5, lsl #2]
 *   @0xfbefc pop {r3, r4, r5, r6, r7, lr}
 *   @0xfbf00 b 0x20edac <_ZN9CDS_Queue6AssignEPS_>
 *   @0xfbf04 ldr r0, [pc, #0x14]
 *   @0xfbf08 mov r1, #0
 *   @0xfbf0c pop {r3, r4, r5, r6, r7, lr}
 *   @0xfbf10 add r0, pc, r0
 *   @0xfbf14 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfbf18 eoreq r1, pc, r12, asr #31
 *   @0xfbf1c .word 0x002f1fbc
 *   @0xfbf20 eoreq r11, r3, r12, ror #25
 *
 * ══ §106/181 F_DsListCopy(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc2ac  size 164  41 条（0xfc2ac..0xfc350）
 * @func 0xfc2ac 0xfc350  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_DsListCopy(RValue&, CInstance*, CInstance*, int, RValue*)+0x84×2
 * 字段偏移 top8: 0x2×3 / 0x4×2 / 0x18×1 / 0x74×1 / 0x64×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc2ac push {r3, r4, r5, r6, r7, lr}
 *   @0xfc2b0 mov r1, #0
 *   @0xfc2b4 ldr r7, [sp, #0x18]
 *   @0xfc2b8 mov r0, r7
 *   @0xfc2bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc2c0 subs r5, r0, #0
 *   @0xfc2c4 blt 0xfc330 <_Z12F_DsListCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfc2c8 ldr r4, [pc, #0x74]
 *   @0xfc2cc ldr r4, [pc, r4]
 *   @0xfc2d0 ldr r3, [r4]
 *   @0xfc2d4 cmp r5, r3
 *   @0xfc2d8 bge 0xfc330 <_Z12F_DsListCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfc2dc ldr r6, [pc, #0x64]
 *   @0xfc2e0 ldr r6, [pc, r6]
 *   @0xfc2e4 ldr r3, [r6, #0x4]
 *   @0xfc2e8 ldr r3, [r3, r5, lsl #2]
 *   @0xfc2ec cmp r3, #0
 *   @0xfc2f0 beq 0xfc330 <_Z12F_DsListCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfc2f4 mov r0, r7
 *   @0xfc2f8 mov r1, #1
 *   @0xfc2fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc300 cmp r0, #0
 *   @0xfc304 blt 0xfc330 <_Z12F_DsListCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfc308 ldr r3, [r4]
 *   @0xfc30c cmp r0, r3
 *   @0xfc310 bge 0xfc330 <_Z12F_DsListCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfc314 ldr r3, [r6, #0x4]
 *   @0xfc318 ldr r1, [r3, r0, lsl #2]
 *   @0xfc31c cmp r1, #0
 *   @0xfc320 beq 0xfc330 <_Z12F_DsListCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfc324 ldr r0, [r3, r5, lsl #2]
 *   @0xfc328 pop {r3, r4, r5, r6, r7, lr}
 *   @0xfc32c b 0x20e61c <_ZN8CDS_List6AssignEPS_>
 *   @0xfc330 ldr r0, [pc, #0x14]
 *   @0xfc334 mov r1, #0
 *   @0xfc338 pop {r3, r4, r5, r6, r7, lr}
 *   @0xfc33c add r0, pc, r0
 *   @0xfc340 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc344 .word 0x002f19b0
 *   @0xfc348 eoreq r1, pc, r0, lsr #19
 *   @0xfc34c eoreq r11, r3, r0, asr #17
 *
 * ══ §107/181 F_DsPriorityCopy(RValue&, CInstance*, CInstance*, int, RValue*)  0xfcb1c  size 164  41 条（0xfcb1c..0xfcbc0）
 * @func 0xfcb1c 0xfcbc0  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_DsPriorityCopy(RValue&, CInstance*, CInstance*, int, RValue*)+0x84×2
 * 字段偏移 top8: 0x2×3 / 0x4×2 / 0x18×1 / 0x74×1 / 0x64×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfcb1c push {r3, r4, r5, r6, r7, lr}
 *   @0xfcb20 mov r1, #0
 *   @0xfcb24 ldr r7, [sp, #0x18]
 *   @0xfcb28 mov r0, r7
 *   @0xfcb2c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfcb30 subs r5, r0, #0
 *   @0xfcb34 blt 0xfcba0 <_Z16F_DsPriorityCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfcb38 ldr r4, [pc, #0x74]
 *   @0xfcb3c ldr r4, [pc, r4]
 *   @0xfcb40 ldr r3, [r4]
 *   @0xfcb44 cmp r5, r3
 *   @0xfcb48 bge 0xfcba0 <_Z16F_DsPriorityCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfcb4c ldr r6, [pc, #0x64]
 *   @0xfcb50 ldr r6, [pc, r6]
 *   @0xfcb54 ldr r3, [r6, #0x4]
 *   @0xfcb58 ldr r3, [r3, r5, lsl #2]
 *   @0xfcb5c cmp r3, #0
 *   @0xfcb60 beq 0xfcba0 <_Z16F_DsPriorityCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfcb64 mov r0, r7
 *   @0xfcb68 mov r1, #1
 *   @0xfcb6c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfcb70 cmp r0, #0
 *   @0xfcb74 blt 0xfcba0 <_Z16F_DsPriorityCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfcb78 ldr r3, [r4]
 *   @0xfcb7c cmp r0, r3
 *   @0xfcb80 bge 0xfcba0 <_Z16F_DsPriorityCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfcb84 ldr r3, [r6, #0x4]
 *   @0xfcb88 ldr r1, [r3, r0, lsl #2]
 *   @0xfcb8c cmp r1, #0
 *   @0xfcb90 beq 0xfcba0 <_Z16F_DsPriorityCopyR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfcb94 ldr r0, [r3, r5, lsl #2]
 *   @0xfcb98 pop {r3, r4, r5, r6, r7, lr}
 *   @0xfcb9c b 0x209a78 <_ZN12CDS_Priority6AssignEPS_>
 *   @0xfcba0 ldr r0, [pc, #0x14]
 *   @0xfcba4 mov r1, #0
 *   @0xfcba8 pop {r3, r4, r5, r6, r7, lr}
 *   @0xfcbac add r0, pc, r0
 *   @0xfcbb0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfcbb4 eoreq r1, pc, r8, lsr r3
 *   @0xfcbb8 eoreq r1, pc, r8, lsr #6
 *   @0xfcbbc eoreq r11, r3, r0, asr r0
 *
 * ══ §108/181 F_DsMapSet(RValue&, CInstance*, CInstance*, int, RValue*)  0xff0dc  size 164  41 条（0xff0dc..0xff180）
 * @func 0xff0dc 0xff180  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapSet(RValue&, CInstance*, CInstance*, int, RValue*)+0x78 / CDS_Map::Set(RValue*, RValue*, RValue*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x18×1 / 0x64×1 / 0x54×1 / 0x4×1 / 0x2×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xff0dc push {r4, r5, lr}
 *   @0xff0e0 sub sp, sp, #12
 *   @0xff0e4 add r4, sp, #4
 *   @0xff0e8 ldr r5, [sp, #0x18]
 *   @0xff0ec mov r0, r4
 *   @0xff0f0 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xff0f4 mov r1, #0
 *   @0xff0f8 mov r0, r5
 *   @0xff0fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xff100 cmp r0, #0
 *   @0xff104 blt 0xff154 <_Z10F_DsMapSetR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xff108 ldr r3, [pc, #0x64]
 *   @0xff10c ldr r3, [pc, r3]
 *   @0xff110 ldr r3, [r3]
 *   @0xff114 cmp r0, r3
 *   @0xff118 bge 0xff154 <_Z10F_DsMapSetR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xff11c ldr r3, [pc, #0x54]
 *   @0xff120 ldr r3, [pc, r3]
 *   @0xff124 ldr r3, [r3, #0x4]
 *   @0xff128 ldr r0, [r3, r0, lsl #2]
 *   @0xff12c cmp r0, #0
 *   @0xff130 beq 0xff154 <_Z10F_DsMapSetR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xff134 add r1, r5, #16
 *   @0xff138 add r2, r5, #32
 *   @0xff13c mov r3, #0
 *   @0xff140 bl 0x208c3c <_ZN7CDS_Map3SetEP6RValueS1_S1_>
 *   @0xff144 mov r0, r4
 *   @0xff148 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff14c add sp, sp, #12
 *   @0xff150 pop {r4, r5, pc}
 *   @0xff154 ldr r0, [pc, #0x20]
 *   @0xff158 mov r1, #0
 *   @0xff15c add r0, pc, r0
 *   @0xff160 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff164 mov r0, r4
 *   @0xff168 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff16c add sp, sp, #12
 *   @0xff170 pop {r4, r5, pc}
 *   @0xff174 eoreq lr, lr, r12, ror #22
 *   @0xff178 eoreq lr, lr, r12, lsl r8
 *   @0xff17c eoreq r8, r3, r0, lsr #21
 *
 * ══ §109/181 F_DArcSin(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e790  size 164  41 条（0x10e790..0x10e834）
 * @func 0x10e790 0x10e834  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / F_DArcSin(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / F_DArcSin(RValue&, CInstance*, CInstance*, int, RValue*)+0x54 / 0xb6754
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x58×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e790 push {r4, lr}
 *   @0x10e794 mov r1, #0
 *   @0x10e798 ldr r3, [sp, #0x8]
 *   @0x10e79c mov r4, r0
 *   @0x10e7a0 str r1, [r0, #0xc]
 *   @0x10e7a4 mov r0, r3
 *   @0x10e7a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10e7ac vmov.f32 s14, #-1.000000e+00
 *   @0x10e7b0 vmov s15, r0
 *   @0x10e7b4 vcmpe.f32 s15, s14
 *   @0x10e7b8 vmrs APSR_nzcv, fpscr
 *   @0x10e7bc blt 0x10e7d0 <_Z9F_DArcSinR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x10e7c0 vmov.f32 s14, #1.000000e+00
 *   @0x10e7c4 vcmpe.f32 s15, s14
 *   @0x10e7c8 vmrs APSR_nzcv, fpscr
 *   @0x10e7cc bls 0x10e7e4 <_Z9F_DArcSinR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x10e7d0 ldr r0, [pc, #0x58]
 *   @0x10e7d4 mov r1, #0
 *   @0x10e7d8 pop {r4, lr}
 *   @0x10e7dc add r0, pc, r0
 *   @0x10e7e0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x10e7e4 bl 0xb6754 <asinf@plt>
 *   @0x10e7e8 vldr s15, [pc, #52]
 *   @0x10e7ec vldr s13, [pc, #52]
 *   @0x10e7f0 vldr s14, [pc, #52]
 *   @0x10e7f4 vmov s12, r0
 *   @0x10e7f8 vmul.f32 s15, s12, s15
 *   @0x10e7fc vdiv.f32 s15, s15, s13
 *   @0x10e800 vabs.f32 s13, s15
 *   @0x10e804 vcmpe.f32 s13, s14
 *   @0x10e808 vmrs APSR_nzcv, fpscr
 *   @0x10e80c vcvtpl.f64.f32 d6, s15
 *   @0x10e810 movmi r2, #0
 *   @0x10e814 movmi r3, #0
 *   @0x10e818 vmovpl r2, r3, d6
 *   @0x10e81c stm r4, {r2, r3}
 *   @0x10e820 pop {r4, pc}
 *   @0x10e824 teqmi r4, #0
 *   @0x10e828 ldrdmi r0, r1, [r9], #-251
 *   @0x10e82c strlo r12, [r7, -r12, lsr #11]!
 *   @0x10e830 eoreq r10, r2, r0, lsr r6
 *
 * ══ §110/181 F_StringOrdAt(RValue&, CInstance*, CInstance*, int, RValue*)  0x1107b0  size 164  41 条（0x1107b0..0x110854）
 * @func 0x1107b0 0x110854  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_extract_char×2 / YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / utf8_strlen / F_StringOrdAt(RValue&, CInstance*, CInstance*, int, RValue*)+0x9c / F_StringOrdAt(RValue&, CInstance*, CInstance*, int, RValue*)+0x7c
 * 字段偏移 top8: 0x4×3 / 0x20×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1107b0 push {r4, r5, r6, r7, lr}
 *   @0x1107b4 sub sp, sp, #12
 *   @0x1107b8 mov r7, r0
 *   @0x1107bc mov r1, #0
 *   @0x1107c0 ldr r5, [sp, #0x20]
 *   @0x1107c4 mov r4, r1
 *   @0x1107c8 mov r0, r5
 *   @0x1107cc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1107d0 mov r1, #1
 *   @0x1107d4 str r0, [sp, #0x4]
 *   @0x1107d8 mov r0, r5
 *   @0x1107dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1107e0 mov r3, r4
 *   @0x1107e4 str r4, [r7, #0xc]
 *   @0x1107e8 movt r3, #0xbff0
 *   @0x1107ec str r4, [r7]
 *   @0x1107f0 str r3, [r7, #0x4]
 *   @0x1107f4 sub r5, r0, #1
 *   @0x1107f8 ldr r0, [sp, #0x4]
 *   @0x1107fc bl 0x110648 <utf8_strlen>
 *   @0x110800 bic r5, r5, r5, asr #31
 *   @0x110804 cmp r0, r5
 *   @0x110808 ble 0x11084c <_Z13F_StringOrdAtR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x11080c cmp r5, r4
 *   @0x110810 add r6, sp, #4
 *   @0x110814 ble 0x11082c <_Z13F_StringOrdAtR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x110818 add r4, r4, #1
 *   @0x11081c mov r0, r6
 *   @0x110820 bl 0x10fb38 <utf8_extract_char>
 *   @0x110824 cmp r4, r5
 *   @0x110828 bne 0x110818 <_Z13F_StringOrdAtR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x11082c mov r0, r6
 *   @0x110830 bl 0x10fb38 <utf8_extract_char>
 *   @0x110834 vmov s15, r0
 *   @0x110838 vcvt.f64.u32 d7, s15
 *   @0x11083c vmov r0, r1, d7
 *   @0x110840 vmov r2, s14
 *   @0x110844 mov r3, r1
 *   @0x110848 stm r7, {r2, r3}
 *   @0x11084c add sp, sp, #12
 *   @0x110850 pop {r4, r5, r6, r7, pc}
 *
 * ══ §111/181 F_FontAddSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x12cfd4  size 164  41 条（0x12cfd4..0x12d078）
 * @func 0x12cfd4 0x12d078  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / Sprite_Exists(int) / YYGetBool(RValue const*, int) / Font_AddSprite(int, int, bool, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12cfd4 push {r4, r5, r6, r7, r8, lr}
 *   @0x12cfd8 mov r1, #0
 *   @0x12cfdc ldr r5, [sp, #0x18]
 *   @0x12cfe0 mov r4, r0
 *   @0x12cfe4 mov r0, r5
 *   @0x12cfe8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cfec mov r6, r0
 *   @0x12cff0 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x12cff4 subs r1, r0, #0
 *   @0x12cff8 beq 0x12d058 <_Z15F_FontAddSpriteR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x12cffc mov r1, #1
 *   @0x12d000 mov r0, r5
 *   @0x12d004 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d008 mov r1, #2
 *   @0x12d00c mov r8, r0
 *   @0x12d010 mov r0, r5
 *   @0x12d014 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12d018 mov r1, #3
 *   @0x12d01c mov r7, r0
 *   @0x12d020 mov r0, r5
 *   @0x12d024 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d028 mov r2, r7
 *   @0x12d02c mov r1, r8
 *   @0x12d030 mov r3, r0
 *   @0x12d034 mov r0, r6
 *   @0x12d038 bl 0xfa5ac <_Z14Font_AddSpriteiibi>
 *   @0x12d03c vmov s15, r0
 *   @0x12d040 vcvt.f64.s32 d7, s15
 *   @0x12d044 vmov r2, r3, d7
 *   @0x12d048 mov r1, #0
 *   @0x12d04c stm r4, {r2, r3}
 *   @0x12d050 str r1, [r4, #0xc]
 *   @0x12d054 pop {r4, r5, r6, r7, r8, pc}
 *   @0x12d058 ldr r0, [pc, #0x14]
 *   @0x12d05c add r0, pc, r0
 *   @0x12d060 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12d064 mov r3, #0
 *   @0x12d068 mov r2, #0
 *   @0x12d06c movt r3, #0xbff0
 *   @0x12d070 b 0x12d048 <_Z15F_FontAddSpriteR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12d074 eoreq r0, r1, r4, ror #9
 *
 * ══ §112/181 F_FontAddSpriteExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d078  size 164  41 条（0x12d078..0x12d11c）
 * @func 0x12d078 0x12d11c  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sprite_Exists(int) / YYGetString(RValue const*, int) / YYGetBool(RValue const*, int) / Font_AddSpriteExt(int, char const*, bool, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d078 push {r4, r5, r6, r7, r8, lr}
 *   @0x12d07c mov r1, #0
 *   @0x12d080 ldr r5, [sp, #0x18]
 *   @0x12d084 mov r4, r0
 *   @0x12d088 mov r0, r5
 *   @0x12d08c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d090 mov r6, r0
 *   @0x12d094 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x12d098 subs r1, r0, #0
 *   @0x12d09c beq 0x12d0fc <_Z18F_FontAddSpriteExtR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x12d0a0 mov r1, #1
 *   @0x12d0a4 mov r0, r5
 *   @0x12d0a8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12d0ac mov r1, #2
 *   @0x12d0b0 mov r8, r0
 *   @0x12d0b4 mov r0, r5
 *   @0x12d0b8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12d0bc mov r1, #3
 *   @0x12d0c0 mov r7, r0
 *   @0x12d0c4 mov r0, r5
 *   @0x12d0c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d0cc mov r2, r7
 *   @0x12d0d0 mov r1, r8
 *   @0x12d0d4 mov r3, r0
 *   @0x12d0d8 mov r0, r6
 *   @0x12d0dc bl 0xfa7a8 <_Z17Font_AddSpriteExtiPKcbi>
 *   @0x12d0e0 vmov s15, r0
 *   @0x12d0e4 vcvt.f64.s32 d7, s15
 *   @0x12d0e8 vmov r2, r3, d7
 *   @0x12d0ec mov r1, #0
 *   @0x12d0f0 stm r4, {r2, r3}
 *   @0x12d0f4 str r1, [r4, #0xc]
 *   @0x12d0f8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x12d0fc ldr r0, [pc, #0x14]
 *   @0x12d100 add r0, pc, r0
 *   @0x12d104 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12d108 mov r3, #0
 *   @0x12d10c mov r2, #0
 *   @0x12d110 movt r3, #0xbff0
 *   @0x12d114 b 0x12d0ec <_Z18F_FontAddSpriteExtR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12d118 eoreq r0, r1, r0, asr #8
 *
 * ══ §113/181 F_RoomSetViewport(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e41c  size 164  41 条（0x12e41c..0x12e4c0）
 * @func 0x12e41c 0x12e4c0  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×6 / Room_Data(int) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x2×1 / 0x14×1 / 0x18×1 / 0x1c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e41c push {r4, r5, r6, lr}
 *   @0x12e420 mov r1, #0
 *   @0x12e424 ldr r4, [sp, #0x10]
 *   @0x12e428 mov r0, r4
 *   @0x12e42c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e430 mov r1, #1
 *   @0x12e434 mov r6, r0
 *   @0x12e438 mov r0, r4
 *   @0x12e43c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e440 mov r5, r0
 *   @0x12e444 mov r0, r6
 *   @0x12e448 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12e44c cmp r0, #0
 *   @0x12e450 popeq {r4, r5, r6, pc}
 *   @0x12e454 cmp r5, #7
 *   @0x12e458 pophi {r4, r5, r6, pc}
 *   @0x12e45c add r5, r5, #18
 *   @0x12e460 ldr r5, [r0, r5, lsl #2]
 *   @0x12e464 cmp r5, #0
 *   @0x12e468 popeq {r4, r5, r6, pc}
 *   @0x12e46c mov r1, #2
 *   @0x12e470 mov r0, r4
 *   @0x12e474 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12e478 mov r1, #3
 *   @0x12e47c strb r0, [r5]
 *   @0x12e480 mov r0, r4
 *   @0x12e484 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e488 mov r1, #4
 *   @0x12e48c str r0, [r5, #0x14]
 *   @0x12e490 mov r0, r4
 *   @0x12e494 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e498 mov r1, #5
 *   @0x12e49c str r0, [r5, #0x18]
 *   @0x12e4a0 mov r0, r4
 *   @0x12e4a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e4a8 mov r1, #6
 *   @0x12e4ac str r0, [r5, #0x1c]
 *   @0x12e4b0 mov r0, r4
 *   @0x12e4b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e4b8 str r0, [r5, #0x20]
 *   @0x12e4bc pop {r4, r5, r6, pc}
 *
 * ══ §114/181 F_FileTextClose(RValue&, CInstance*, CInstance*, int, RValue*)  0x139360  size 164  41 条（0x139360..0x139404）
 * @func 0x139360 0x139404  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x139388→0x483724, 0x1393a4→0x4837a4
 * 调用序列: YYGetInt32(RValue const*, int) / MemoryManager::Free(void const*) / LoadSave::fclose(_YYFILE*)
 * 字段偏移 top8: 0x2×2 / 0x8×2 / 0x20×1 / 0x7c×1 / 0x68×1 / 0x50×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139360 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x139364 mov r1, #0
 *   @0x139368 ldr r0, [sp, #0x20]
 *   @0x13936c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x139370 ldr r3, [pc, #0x7c]
 *   @0x139374 add r3, pc, r3
 *   @0x139378 sub r2, r0, #1
 *   @0x13937c mov r4, r0
 *   @0x139380 cmp r2, #30
 *   @0x139384 bhi 0x1393e0 <_Z15F_FileTextCloseR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x139388 ldr r2, [pc, #0x68]
 *   @0x13938c ldr r5, [r3, r2]
 *   @0x139390 ldr r2, [r5, r0, lsl #2]
 *   @0x139394 cmp r2, #1
 *   @0x139398 beq 0x1393a4 <_Z15F_FileTextCloseR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x13939c cmp r2, #2
 *   @0x1393a0 bne 0x1393d4 <_Z15F_FileTextCloseR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1393a4 ldr r2, [pc, #0x50]
 *   @0x1393a8 add r6, r4, r4, lsl #1
 *   @0x1393ac mov r9, #0
 *   @0x1393b0 lsl r6, r6, #2
 *   @0x1393b4 ldr r7, [r3, r2]
 *   @0x1393b8 add r8, r7, r6
 *   @0x1393bc ldr r0, [r7, r6]
 *   @0x1393c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1393c4 ldr r0, [r8, #0x8]
 *   @0x1393c8 str r9, [r7, r6]
 *   @0x1393cc bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE>
 *   @0x1393d0 str r9, [r8, #0x8]
 *   @0x1393d4 mov r3, #0
 *   @0x1393d8 str r3, [r5, r4, lsl #2]
 *   @0x1393dc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1393e0 ldr r0, [pc, #0x18]
 *   @0x1393e4 mov r1, #0
 *   @0x1393e8 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1393ec add r0, pc, r0
 *   @0x1393f0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1393f4 .word 0x002b88dc
 *   @0x1393f8 .word 0xffffd620
 *   @0x1393fc .word 0xffffd624
 *   @0x139400 eoreq r6, r0, r8, lsr sp
 *
 * ══ §115/181 F_ActionIfLife(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d6ac  size 164  41 条（0x13d6ac..0x13d750）
 * @func 0x13d6ac 0x13d750  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13d6dc→0x542940
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0x84×1 / 0x68×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d6ac push {r3, r4, r5, r6, r7, lr}
 *   @0x13d6b0 mov r1, #0
 *   @0x13d6b4 ldr r5, [sp, #0x18]
 *   @0x13d6b8 mov r4, r0
 *   @0x13d6bc ldr r6, [pc, #0x84]
 *   @0x13d6c0 mov r0, r5
 *   @0x13d6c4 add r6, pc, r6
 *   @0x13d6c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13d6cc mov r1, #1
 *   @0x13d6d0 mov r7, r0
 *   @0x13d6d4 mov r0, r5
 *   @0x13d6d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13d6dc ldr r3, [pc, #0x68]
 *   @0x13d6e0 ldr r3, [r6, r3]
 *   @0x13d6e4 cmp r0, #1
 *   @0x13d6e8 beq 0x13d724 <_Z14F_ActionIfLifeR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x13d6ec cmp r0, #2
 *   @0x13d6f0 ldr r0, [r3]
 *   @0x13d6f4 beq 0x13d738 <_Z14F_ActionIfLifeR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x13d6f8 subs r3, r0, r7
 *   @0x13d6fc rsbs r0, r3, #0
 *   @0x13d700 adcs r0, r0, r3
 *   @0x13d704 cmp r0, #0
 *   @0x13d708 mov r3, #0
 *   @0x13d70c str r3, [r4, #0xc]
 *   @0x13d710 movne r0, r3
 *   @0x13d714 moveq r3, r0
 *   @0x13d718 movtne r3, #0x3ff0
 *   @0x13d71c stm r4, {r0, r3}
 *   @0x13d720 pop {r3, r4, r5, r6, r7, pc}
 *   @0x13d724 ldr r0, [r3]
 *   @0x13d728 cmp r0, r7
 *   @0x13d72c movge r0, #0
 *   @0x13d730 movlt r0, #1
 *   @0x13d734 b 0x13d704 <_Z14F_ActionIfLifeR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x13d738 cmp r0, r7
 *   @0x13d73c movle r0, #0
 *   @0x13d740 movgt r0, #1
 *   @0x13d744 b 0x13d704 <_Z14F_ActionIfLifeR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x13d748 eoreq r4, r11, r12, lsl #11
 *   @0x13d74c .word 0xffffd780
 *
 * ══ §116/181 F_ActionPartTypeLife(RValue&, CInstance*, CInstance*, int, RValue*)  0x13fc98  size 164  41 条（0x13fc98..0x13fd3c）
 * @func 0x13fc98 0x13fd3c  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_ActionPartTypeLife(RValue&, CInstance*, CInstance*, int, RValue*)+0x88 / F_ActionPartTypeLife(RValue&, CInstance*, CInstance*, int, RValue*)+0x70 / ParticleType_Create() / ParticleSystem_Create(int, bool)
 * 字段偏移 top8: 0x2×2 / 0x18×1 / 0x88×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13fc98 push {r3, r4, r5, r6, r7, lr}
 *   @0x13fc9c mov r1, #0
 *   @0x13fca0 ldr r5, [sp, #0x18]
 *   @0x13fca4 ldr r4, [pc, #0x88]
 *   @0x13fca8 mov r0, r5
 *   @0x13fcac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fcb0 mov r1, #1
 *   @0x13fcb4 mov r6, r0
 *   @0x13fcb8 mov r0, r5
 *   @0x13fcbc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fcc0 mov r1, #2
 *   @0x13fcc4 mov r7, r0
 *   @0x13fcc8 mov r0, r5
 *   @0x13fccc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fcd0 ldr r4, [pc, r4]
 *   @0x13fcd4 ldr r3, [r4]
 *   @0x13fcd8 cmp r3, #0
 *   @0x13fcdc mov r5, r0
 *   @0x13fce0 blt 0x13fd20 <_Z20F_ActionPartTypeLifeR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x13fce4 ldr r4, [pc, #0x4c]
 *   @0x13fce8 ldr r4, [pc, r4]
 *   @0x13fcec ldr r0, [r4, r6, lsl #2]
 *   @0x13fcf0 cmp r0, #0
 *   @0x13fcf4 blt 0x13fd08 <_Z20F_ActionPartTypeLifeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x13fcf8 mov r1, r7
 *   @0x13fcfc mov r2, r5
 *   @0x13fd00 pop {r3, r4, r5, r6, r7, lr}
 *   @0x13fd04 b 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x13fd08 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x13fd0c mov r1, r7
 *   @0x13fd10 mov r2, r5
 *   @0x13fd14 str r0, [r4, r6, lsl #2]
 *   @0x13fd18 pop {r3, r4, r5, r6, r7, lr}
 *   @0x13fd1c b 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x13fd20 mvn r0, #0
 *   @0x13fd24 mov r1, #1
 *   @0x13fd28 bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x13fd2c str r0, [r4]
 *   @0x13fd30 b 0x13fce4 <_Z20F_ActionPartTypeLifeR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x13fd34 eoreq pc, r10, r12, lsl #14
 *   @0x13fd38 .word 0x002af6f8
 *
 * ══ §117/181 F_ActionPartTypeGravity(RValue&, CInstance*, CInstance*, int, RValue*)  0x13fe38  size 164  41 条（0x13fe38..0x13fedc）
 * @func 0x13fe38 0x13fedc  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / F_ActionPartTypeGravity(RValue&, CInstance*, CInstance*, int, RValue*)+0x88 / F_ActionPartTypeGravity(RValue&, CInstance*, CInstance*, int, RValue*)+0x70 / ParticleType_Create() / ParticleSystem_Create(int, bool)
 * 字段偏移 top8: 0x2×2 / 0x18×1 / 0x88×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13fe38 push {r3, r4, r5, r6, r7, lr}
 *   @0x13fe3c mov r1, #0
 *   @0x13fe40 ldr r5, [sp, #0x18]
 *   @0x13fe44 ldr r4, [pc, #0x88]
 *   @0x13fe48 mov r0, r5
 *   @0x13fe4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fe50 mov r1, #1
 *   @0x13fe54 mov r6, r0
 *   @0x13fe58 mov r0, r5
 *   @0x13fe5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13fe60 mov r1, #2
 *   @0x13fe64 mov r7, r0
 *   @0x13fe68 mov r0, r5
 *   @0x13fe6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13fe70 ldr r4, [pc, r4]
 *   @0x13fe74 ldr r3, [r4]
 *   @0x13fe78 cmp r3, #0
 *   @0x13fe7c mov r5, r0
 *   @0x13fe80 blt 0x13fec0 <_Z23F_ActionPartTypeGravityR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x13fe84 ldr r4, [pc, #0x4c]
 *   @0x13fe88 ldr r4, [pc, r4]
 *   @0x13fe8c ldr r0, [r4, r6, lsl #2]
 *   @0x13fe90 cmp r0, #0
 *   @0x13fe94 blt 0x13fea8 <_Z23F_ActionPartTypeGravityR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x13fe98 mov r1, r7
 *   @0x13fe9c mov r2, r5
 *   @0x13fea0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x13fea4 b 0x1a3454 <_Z20ParticleType_Gravityiff>
 *   @0x13fea8 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x13feac mov r1, r7
 *   @0x13feb0 mov r2, r5
 *   @0x13feb4 str r0, [r4, r6, lsl #2]
 *   @0x13feb8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x13febc b 0x1a3454 <_Z20ParticleType_Gravityiff>
 *   @0x13fec0 mvn r0, #0
 *   @0x13fec4 mov r1, #1
 *   @0x13fec8 bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x13fecc str r0, [r4]
 *   @0x13fed0 b 0x13fe84 <_Z23F_ActionPartTypeGravityR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x13fed4 eoreq pc, r10, r12, ror #10
 *   @0x13fed8 eoreq pc, r10, r8, asr r5
 *
 * ══ §118/181 F_GamepadSetButtonThreshold(RValue&, CInstance*, CInstance*, int, RValue*)  0x151974  size 164  41 条（0x151974..0x151a18）
 * @func 0x151974 0x151a18  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int) / F_GamepadSetButtonThreshold(RValue&, CInstance*, CInstance*, int, RValue*)+0x80
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x64×1 / 0x28×1 / 0x18×1 / 0x2×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x151974 push {r3, r4, r5, lr}
 *   @0x151978 mov r3, #0
 *   @0x15197c ldr r4, [sp, #0x10]
 *   @0x151980 mov r1, r3
 *   @0x151984 str r3, [r0, #0xc]
 *   @0x151988 str r3, [r0]
 *   @0x15198c str r3, [r0, #0x4]
 *   @0x151990 mov r0, r4
 *   @0x151994 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x151998 subs r5, r0, #0
 *   @0x15199c poplt {r3, r4, r5, pc}
 *   @0x1519a0 ldr r3, [pc, #0x64]
 *   @0x1519a4 ldr r3, [pc, r3]
 *   @0x1519a8 ldr r3, [r3]
 *   @0x1519ac cmp r5, r3
 *   @0x1519b0 popge {r3, r4, r5, pc}
 *   @0x1519b4 mov r0, r4
 *   @0x1519b8 mov r1, #1
 *   @0x1519bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1519c0 vmov s15, r0
 *   @0x1519c4 vcmpe.f32 s15, #0
 *   @0x1519c8 vmrs APSR_nzcv, fpscr
 *   @0x1519cc bmi 0x1519e0 <_Z27F_GamepadSetButtonThresholdR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1519d0 vmov.f32 s14, #1.000000e+00
 *   @0x1519d4 vcmpe.f32 s15, s14
 *   @0x1519d8 vmrs APSR_nzcv, fpscr
 *   @0x1519dc ble 0x1519f4 <_Z27F_GamepadSetButtonThresholdR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1519e0 ldr r0, [pc, #0x28]
 *   @0x1519e4 mov r1, #0
 *   @0x1519e8 pop {r3, r4, r5, lr}
 *   @0x1519ec add r0, pc, r0
 *   @0x1519f0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1519f4 ldr r3, [pc, #0x18]
 *   @0x1519f8 ldr r3, [pc, r3]
 *   @0x1519fc ldr r3, [r3]
 *   @0x151a00 ldr r3, [r3, r5, lsl #2]
 *   @0x151a04 vstr s15, [r3, #28]
 *   @0x151a08 pop {r3, r4, r5, pc}
 *   @0x151a0c strhteq lr, [r9], -r12
 *   @0x151a10 andseq r4, pc, r4, lsl #3
 *   @0x151a14 eoreq lr, r9, r12, rrx
 *
 * ══ §119/181 F_GamepadSetAxisDeadzone(RValue&, CInstance*, CInstance*, int, RValue*)  0x151a18  size 164  41 条（0x151a18..0x151abc）
 * @func 0x151a18 0x151abc  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int) / F_GamepadSetAxisDeadzone(RValue&, CInstance*, CInstance*, int, RValue*)+0x80
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x64×1 / 0x28×1 / 0x18×1 / 0x2×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x151a18 push {r3, r4, r5, lr}
 *   @0x151a1c mov r3, #0
 *   @0x151a20 ldr r4, [sp, #0x10]
 *   @0x151a24 mov r1, r3
 *   @0x151a28 str r3, [r0, #0xc]
 *   @0x151a2c str r3, [r0]
 *   @0x151a30 str r3, [r0, #0x4]
 *   @0x151a34 mov r0, r4
 *   @0x151a38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x151a3c subs r5, r0, #0
 *   @0x151a40 poplt {r3, r4, r5, pc}
 *   @0x151a44 ldr r3, [pc, #0x64]
 *   @0x151a48 ldr r3, [pc, r3]
 *   @0x151a4c ldr r3, [r3]
 *   @0x151a50 cmp r5, r3
 *   @0x151a54 popge {r3, r4, r5, pc}
 *   @0x151a58 mov r0, r4
 *   @0x151a5c mov r1, #1
 *   @0x151a60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x151a64 vmov s15, r0
 *   @0x151a68 vcmpe.f32 s15, #0
 *   @0x151a6c vmrs APSR_nzcv, fpscr
 *   @0x151a70 bmi 0x151a84 <_Z24F_GamepadSetAxisDeadzoneR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x151a74 vmov.f32 s14, #1.000000e+00
 *   @0x151a78 vcmpe.f32 s15, s14
 *   @0x151a7c vmrs APSR_nzcv, fpscr
 *   @0x151a80 ble 0x151a98 <_Z24F_GamepadSetAxisDeadzoneR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x151a84 ldr r0, [pc, #0x28]
 *   @0x151a88 mov r1, #0
 *   @0x151a8c pop {r3, r4, r5, lr}
 *   @0x151a90 add r0, pc, r0
 *   @0x151a94 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x151a98 ldr r3, [pc, #0x18]
 *   @0x151a9c ldr r3, [pc, r3]
 *   @0x151aa0 ldr r3, [r3]
 *   @0x151aa4 ldr r3, [r3, r5, lsl #2]
 *   @0x151aa8 vstr s15, [r3, #32]
 *   @0x151aac pop {r3, r4, r5, pc}
 *   @0x151ab0 eoreq lr, r9, r8, lsl r0
 *   @0x151ab4 andseq r4, pc, r0, lsl r1
 *   @0x151ab8 eoreq sp, r9, r8, asr #31
 *
 * ══ §120/181 F_YoYo_Base64Encode(RValue&, CInstance*, CInstance*, int, RValue*)  0x1579f0  size 164  41 条（0x1579f0..0x157a94）
 * @func 0x1579f0 0x157a94  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / 0xb6538 / 0xb65b0 / base64_encode(char const*, unsigned int, char*) / YYCreateString(RValue*, char const*) / 0xb65d4
 * 字段偏移 top8: 0x-20×2 / 0x90×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1579f0 push {r4, r5, r6, r7, r8, r11, lr}
 *   @0x1579f4 add r11, sp, #24
 *   @0x1579f8 ldr r4, [pc, #0x90]
 *   @0x1579fc sub sp, sp, #12
 *   @0x157a00 mov r1, #0
 *   @0x157a04 ldr r4, [pc, r4]
 *   @0x157a08 mov r7, r0
 *   @0x157a0c ldr r0, [r11, #0x4]
 *   @0x157a10 ldr r3, [r4]
 *   @0x157a14 str r3, [r11, #-0x20]
 *   @0x157a18 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157a1c mov r8, r0
 *   @0x157a20 bl 0xb6538 <strlen@plt>
 *   @0x157a24 movw r2, #0x5556
 *   @0x157a28 movt r2, #0x5555
 *   @0x157a2c mov r1, #0
 *   @0x157a30 lsl r3, r0, #2
 *   @0x157a34 mov r6, r0
 *   @0x157a38 smull r0, r2, r2, r3
 *   @0x157a3c sub r2, r2, r3, asr #31
 *   @0x157a40 add r3, r2, #18
 *   @0x157a44 add r2, r2, #4
 *   @0x157a48 bic r3, r3, #7
 *   @0x157a4c sub sp, sp, r3
 *   @0x157a50 mov r0, sp
 *   @0x157a54 bl 0xb65b0 <memset@plt>
 *   @0x157a58 mov r2, sp
 *   @0x157a5c mov r0, r8
 *   @0x157a60 mov r1, r6
 *   @0x157a64 bl 0x1d1e60 <_Z13base64_encodePKcjPc>
 *   @0x157a68 mov r0, r7
 *   @0x157a6c mov r1, sp
 *   @0x157a70 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x157a74 ldr r2, [r11, #-0x20]
 *   @0x157a78 ldr r3, [r4]
 *   @0x157a7c cmp r2, r3
 *   @0x157a80 bne 0x157a8c <_Z19F_YoYo_Base64EncodeR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x157a84 sub sp, r11, #24
 *   @0x157a88 pop {r4, r5, r6, r7, r8, r11, pc}
 *   @0x157a8c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x157a90 eoreq r5, r9, r12, asr #30
 *
 * ══ §121/181 C3D_Model::Clear()  0x163ce0  size 164  41 条（0x163ce0..0x163d84）
 * @func 0x163ce0 0x163d84  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)×2 / C3D_Model::Clear()+0x48 / MemoryManager::Free(void const*) / GraphicsRecorder::~GraphicsRecorder()
 * 字段偏移 top8: 0x8×3 / 0xc×2 / 0x2×1 / 0x4×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163ce0 ldr r3, [r0, #0x8]
 *   @0x163ce4 push {r4, r5, r6, lr}
 *   @0x163ce8 cmp r3, #0
 *   @0x163cec mov r6, r0
 *   @0x163cf0 beq 0x163d3c <_ZN9C3D_Model5ClearEv+0x5c>
 *   @0x163cf4 ldr r2, [r0]
 *   @0x163cf8 cmp r2, #0
 *   @0x163cfc ble 0x163d28 <_ZN9C3D_Model5ClearEv+0x48>
 *   @0x163d00 mov r4, #0
 *   @0x163d04 ldr r0, [r3, r4, lsl #2]
 *   @0x163d08 add r4, r4, #1
 *   @0x163d0c cmp r0, #0
 *   @0x163d10 beq 0x163d20 <_ZN9C3D_Model5ClearEv+0x40>
 *   @0x163d14 bl 0x27d1d0 <_ZdlPv>
 *   @0x163d18 ldr r3, [r6, #0x8]
 *   @0x163d1c ldr r2, [r6]
 *   @0x163d20 cmp r2, r4
 *   @0x163d24 bgt 0x163d04 <_ZN9C3D_Model5ClearEv+0x24>
 *   @0x163d28 mov r0, r3
 *   @0x163d2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x163d30 mov r3, #0
 *   @0x163d34 str r3, [r6, #0x8]
 *   @0x163d38 str r3, [r6, #0x4]
 *   @0x163d3c ldr r4, [r6, #0xc]
 *   @0x163d40 mov r3, #0
 *   @0x163d44 str r3, [r6]
 *   @0x163d48 cmp r4, r3
 *   @0x163d4c beq 0x163d70 <_ZN9C3D_Model5ClearEv+0x90>
 *   @0x163d50 ldr r5, [r4]
 *   @0x163d54 mov r0, r4
 *   @0x163d58 bl 0x188ca4 <_ZN16GraphicsRecorderD2Ev>
 *   @0x163d5c mov r0, r4
 *   @0x163d60 bl 0x27d1d0 <_ZdlPv>
 *   @0x163d64 cmp r5, #0
 *   @0x163d68 mov r4, r5
 *   @0x163d6c bne 0x163d50 <_ZN9C3D_Model5ClearEv+0x70>
 *   @0x163d70 mov r3, #0
 *   @0x163d74 str r3, [r6, #0x14]
 *   @0x163d78 str r3, [r6, #0x10]
 *   @0x163d7c str r3, [r6, #0xc]
 *   @0x163d80 pop {r4, r5, r6, pc}
 *
 * ══ §122/181 GraphicsPerf::RenderRectangle(float, float, float, float, unsigned int)  0x17b83c  size 164  41 条（0x17b83c..0x17b8e0）
 * @func 0x17b83c 0x17b8e0  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0x18×1 / 0x14×1 / 0x10×1 / 0x2c×1 / 0x28×1 / 0x44×1 / 0x40×1 / 0x5c×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b83c push {r4, lr}
 *   @0x17b840 vpush {d8, d9}
 *   @0x17b844 vmov s17, r1
 *   @0x17b848 vmov s16, r0
 *   @0x17b84c mov r1, #0
 *   @0x17b850 vmov s18, r2
 *   @0x17b854 mov r0, #5
 *   @0x17b858 vmov s19, r3
 *   @0x17b85c mov r2, #24
 *   @0x17b860 mov r3, #4
 *   @0x17b864 ldr r4, [sp, #0x18]
 *   @0x17b868 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x17b86c vadd.f32 s15, s17, s19
 *   @0x17b870 mov r3, #0
 *   @0x17b874 vstr s16, [r0]
 *   @0x17b878 vstr s16, [r0, #24]
 *   @0x17b87c vadd.f32 s16, s16, s18
 *   @0x17b880 vstr s17, [r0, #28]
 *   @0x17b884 vstr s17, [r0, #76]
 *   @0x17b888 str r3, [r0, #0x14]
 *   @0x17b88c str r3, [r0, #0x10]
 *   @0x17b890 vstr s15, [r0, #4]
 *   @0x17b894 str r3, [r0, #0x2c]
 *   @0x17b898 vstr s15, [r0, #52]
 *   @0x17b89c str r3, [r0, #0x28]
 *   @0x17b8a0 str r3, [r0, #0x44]
 *   @0x17b8a4 str r3, [r0, #0x40]
 *   @0x17b8a8 str r3, [r0, #0x5c]
 *   @0x17b8ac str r3, [r0, #0x58]
 *   @0x17b8b0 str r4, [r0, #0xc]
 *   @0x17b8b4 vstr s16, [r0, #48]
 *   @0x17b8b8 vstr s16, [r0, #72]
 *   @0x17b8bc vpop {d8, d9}
 *   @0x17b8c0 str r4, [r0, #0x24]
 *   @0x17b8c4 str r4, [r0, #0x3c]
 *   @0x17b8c8 str r4, [r0, #0x54]
 *   @0x17b8cc str r3, [r0, #0x8]
 *   @0x17b8d0 str r3, [r0, #0x20]
 *   @0x17b8d4 str r3, [r0, #0x38]
 *   @0x17b8d8 str r3, [r0, #0x50]
 *   @0x17b8dc pop {r4, pc}
 *
 * ══ §123/181 Graphics::DrawArrayFromVB(ePrimType, int, int, int, void*, VertexBuffer*)  0x185730  size 164  41 条（0x185730..0x1857d4）
 * @func 0x185730 0x1857d4  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::DrawArrayFromVB(ePrimType, int, int, int, void*, VertexBuffer*)+0x94 / Graphics::Flush() / Graphics::SetTexture(int, void*) / _DrawArray(ePrimType, int, void*, int, void*)
 * 字段偏移 top8: 0xc×2 / 0x2c×1 / 0x28×1 / 0x58×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x185730 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x185734 sub sp, sp, #12
 *   @0x185738 mov r8, r0
 *   @0x18573c mov r6, r1
 *   @0x185740 ldr r4, [sp, #0x2c]
 *   @0x185744 mov r9, r3
 *   @0x185748 ldr r7, [sp, #0x28]
 *   @0x18574c cmp r4, #0
 *   @0x185750 beq 0x1857c4 <_ZN8Graphics15DrawArrayFromVBE9ePrimTypeiiiPvP12VertexBuffer+0x94>
 *   @0x185754 cmp r1, #0
 *   @0x185758 ble 0x1857c4 <_ZN8Graphics15DrawArrayFromVBE9ePrimTypeiiiPvP12VertexBuffer+0x94>
 *   @0x18575c ldr r3, [r4, #0xc]
 *   @0x185760 cmp r3, #0
 *   @0x185764 beq 0x1857c4 <_ZN8Graphics15DrawArrayFromVBE9ePrimTypeiiiPvP12VertexBuffer+0x94>
 *   @0x185768 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x18576c ldr r2, [pc, #0x58]
 *   @0x185770 mov r1, r7
 *   @0x185774 ldr r5, [pc, #0x54]
 *   @0x185778 ldr r2, [pc, r2]
 *   @0x18577c ldr r0, [r2]
 *   @0x185780 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x185784 ldr r3, [r4, #0xc]
 *   @0x185788 ldr r5, [pc, r5]
 *   @0x18578c movw r0, #0x8892
 *   @0x185790 ldr r1, [r3]
 *   @0x185794 ldr r3, [r5]
 *   @0x185798 blx r3
 *   @0x18579c mov r0, r8
 *   @0x1857a0 mov r1, r6
 *   @0x1857a4 mov r3, r9
 *   @0x1857a8 str r7, [sp]
 *   @0x1857ac mov r2, #0
 *   @0x1857b0 bl 0x184868 <_Z10_DrawArray9ePrimTypeiPviS0_>
 *   @0x1857b4 ldr r3, [r5]
 *   @0x1857b8 movw r0, #0x8892
 *   @0x1857bc mov r1, #0
 *   @0x1857c0 blx r3
 *   @0x1857c4 add sp, sp, #12
 *   @0x1857c8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1857cc eoreq r10, r6, r12, lsr #19
 *   @0x1857d0 eoreq r8, r6, r4
 *
 * ══ §124/181 ParticleSystem_Emitter_Stream(int, int, int, int)  0x1a3ad4  size 164  41 条（0x1a3ad4..0x1a3b78）
 * @func 0x1a3ad4 0x1a3b78  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a3af8→0x3eb70c, 0x1a3b08→0x542460, 0x1a3b44→0x3eb70c
 * 调用序列: ParticleSystem_Exists(int) / ParticleSystem_Emitter_Stream(int, int, int, int)+0x6c
 * 字段偏移 top8: 0x70×2 / 0x4×2 / 0x2×2 / 0xc×2 / 0x20×2 / 0x6c×1 / 0x60×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3ad4 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a3ad8 mov r4, r1
 *   @0x1a3adc mov r7, r3
 *   @0x1a3ae0 mov r6, r2
 *   @0x1a3ae4 mov r5, r0
 *   @0x1a3ae8 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a3aec ldr r12, [pc, #0x70]
 *   @0x1a3af0 ldr r1, [pc, #0x70]
 *   @0x1a3af4 add r12, pc, r12
 *   @0x1a3af8 ldr r3, [pc, #0x6c]
 *   @0x1a3afc add r1, pc, r1
 *   @0x1a3b00 cmp r0, #0
 *   @0x1a3b04 beq 0x1a3b4c <_Z29ParticleSystem_Emitter_Streamiiii+0x78>
 *   @0x1a3b08 ldr r3, [pc, #0x60]
 *   @0x1a3b0c cmp r4, #0
 *   @0x1a3b10 ldr r1, [r12, r3]
 *   @0x1a3b14 ldr r1, [r1, #0x4]
 *   @0x1a3b18 ldr r1, [r1, r5, lsl #2]
 *   @0x1a3b1c blt 0x1a3b40 <_Z29ParticleSystem_Emitter_Streamiiii+0x6c>
 *   @0x1a3b20 ldr r3, [r1, #0xc]
 *   @0x1a3b24 cmp r4, r3
 *   @0x1a3b28 bge 0x1a3b40 <_Z29ParticleSystem_Emitter_Streamiiii+0x6c>
 *   @0x1a3b2c ldr r3, [r1, #0x10]
 *   @0x1a3b30 ldr r3, [r3, r4, lsl #2]
 *   @0x1a3b34 str r7, [r3, #0x4]
 *   @0x1a3b38 str r6, [r3, #0x20]
 *   @0x1a3b3c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a3b40 ldr r1, [pc, #0x2c]
 *   @0x1a3b44 ldr r3, [pc, #0x20]
 *   @0x1a3b48 add r1, pc, r1
 *   @0x1a3b4c ldr r3, [r12, r3]
 *   @0x1a3b50 ldr r0, [r3]
 *   @0x1a3b54 ldr r3, [r0]
 *   @0x1a3b58 ldr r3, [r3, #0xc]
 *   @0x1a3b5c blx r3
 *   @0x1a3b60 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a3b64 eoreq lr, r4, r12, asr r1
 *   @0x1a3b68 andseq r9, r10, r0, asr #9
 *   @0x1a3b6c .word 0xffffbac4
 *   @0x1a3b70 .word 0xffffeb68
 *   @0x1a3b74 andseq r9, r10, r12, lsr #9
 *
 * ══ §125/181 CPath::Center(float&, float&)  0x1a7610  size 164  41 条（0x1a7610..0x1a76b4）
 * @func 0x1a7610 0x1a76b4  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::Center(float&, float&)+0x8c
 * 字段偏移 top8: 0x10×1 / 0x4×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7610 ldr r12, [r0, #0x10]
 *   @0x1a7614 cmp r12, #0
 *   @0x1a7618 ble 0x1a769c <_ZN5CPath6CenterERfS0_+0x8c>
 *   @0x1a761c ldr r3, [r0, #0x4]
 *   @0x1a7620 add r12, r12, r12, lsl #1
 *   @0x1a7624 vldr s13, [pc, #124]
 *   @0x1a7628 vldr s12, [pc, #124]
 *   @0x1a762c vmov.f32 s11, s13
 *   @0x1a7630 add r0, r3, r12, lsl #2
 *   @0x1a7634 vmov.f32 s10, s12
 *   @0x1a7638 vldr s14, [r3]
 *   @0x1a763c vldr s15, [r3, #4]
 *   @0x1a7640 add r3, r3, #12
 *   @0x1a7644 vcmp.f32 s14, s10
 *   @0x1a7648 vmrs APSR_nzcv, fpscr
 *   @0x1a764c vcmp.f32 s14, s11
 *   @0x1a7650 vmovmi.f32 s10, s14
 *   @0x1a7654 vmrs APSR_nzcv, fpscr
 *   @0x1a7658 vcmp.f32 s15, s12
 *   @0x1a765c vmovgt.f32 s11, s14
 *   @0x1a7660 vmrs APSR_nzcv, fpscr
 *   @0x1a7664 vcmp.f32 s15, s13
 *   @0x1a7668 vmovmi.f32 s12, s15
 *   @0x1a766c vmrs APSR_nzcv, fpscr
 *   @0x1a7670 vmovgt.f32 s13, s15
 *   @0x1a7674 cmp r3, r0
 *   @0x1a7678 bne 0x1a7638 <_ZN5CPath6CenterERfS0_+0x28>
 *   @0x1a767c vmov.f32 s15, #5.000000e-01
 *   @0x1a7680 vadd.f32 s11, s10, s11
 *   @0x1a7684 vadd.f32 s13, s12, s13
 *   @0x1a7688 vmul.f32 s11, s11, s15
 *   @0x1a768c vmul.f32 s15, s13, s15
 *   @0x1a7690 vstr s11, [r1]
 *   @0x1a7694 vstr s15, [r2]
 *   @0x1a7698 bx lr
 *   @0x1a769c vldr s15, [pc, #12]
 *   @0x1a76a0 vmov.f32 s11, s15
 *   @0x1a76a4 b 0x1a7690 <_ZN5CPath6CenterERfS0_+0x80>
 *   @0x1a76a8 ldcgt p12, c11, [lr], #128
 *   @0x1a76ac ldcmi p12, c11, [lr], #128
 *   @0x1a76b0 andeq r0, r0, r0
 *
 * ══ §126/181 CLayerManager::RemoveParticleElement(CLayer*, CLayerParticleElement*)  0x1b7ec0  size 164  41 条（0x1b7ec0..0x1b7f64）
 * @func 0x1b7ec0 0x1b7f64  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x60×3 / 0x8×3 / 0x18×2 / 0x14×2 / 0x4×1 / 0xc×1 / 0x10×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b7ec0 ldr r3, [r1, #0x18]
 *   @0x1b7ec4 mvn r12, #0
 *   @0x1b7ec8 ldr r2, [r1, #0x14]
 *   @0x1b7ecc cmp r3, #0
 *   @0x1b7ed0 push {r4, r5}
 *   @0x1b7ed4 mov r5, #6
 *   @0x1b7ed8 strne r2, [r3, #0x14]
 *   @0x1b7edc ldrne r2, [r1, #0x14]
 *   @0x1b7ee0 ldrne r3, [r1, #0x18]
 *   @0x1b7ee4 streq r2, [r0, #0x58]
 *   @0x1b7ee8 cmp r2, #0
 *   @0x1b7eec streq r3, [r0, #0x5c]
 *   @0x1b7ef0 strne r3, [r2, #0x18]
 *   @0x1b7ef4 mov r2, #0
 *   @0x1b7ef8 ldr r3, [pc, #0x60]
 *   @0x1b7efc ldr r4, [r0, #0x60]
 *   @0x1b7f00 ldr r3, [pc, r3]
 *   @0x1b7f04 add r4, r4, r12
 *   @0x1b7f08 str r4, [r0, #0x60]
 *   @0x1b7f0c ldr r0, [r3]
 *   @0x1b7f10 ldr r4, [r3, #0x8]
 *   @0x1b7f14 cmp r0, r2
 *   @0x1b7f18 str r5, [r1]
 *   @0x1b7f1c str r12, [r1, #0x4]
 *   @0x1b7f20 add r4, r4, #1
 *   @0x1b7f24 strb r2, [r1, #0x8]
 *   @0x1b7f28 str r2, [r1, #0x14]
 *   @0x1b7f2c str r2, [r1, #0x18]
 *   @0x1b7f30 str r2, [r1, #0xc]
 *   @0x1b7f34 str r2, [r1, #0x10]
 *   @0x1b7f38 str r12, [r1, #0x1c]
 *   @0x1b7f3c str r4, [r3, #0x8]
 *   @0x1b7f40 strne r1, [r0, #0x18]
 *   @0x1b7f44 streq r1, [r3, #0x4]
 *   @0x1b7f48 streq r1, [r3]
 *   @0x1b7f4c strne r1, [r3]
 *   @0x1b7f50 strne r0, [r1, #0x14]
 *   @0x1b7f54 strne r2, [r1, #0x18]
 *   @0x1b7f58 pop {r4, r5}
 *   @0x1b7f5c bx lr
 *   @0x1b7f60 eoreq r8, r3, r4, ror r9
 *
 * ══ §127/181 F_LayerGetX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb188  size 164  41 条（0x1bb188..0x1bb22c）
 * @func 0x1bb188 0x1bb22c  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x74×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb188 cmp r3, #1
 *   @0x1bb18c push {r3, r4, r5, r6, r7, lr}
 *   @0x1bb190 mov r4, #0
 *   @0x1bb194 mov r5, r0
 *   @0x1bb198 ldr r6, [sp, #0x18]
 *   @0x1bb19c str r4, [r0, #0xc]
 *   @0x1bb1a0 str r4, [r0]
 *   @0x1bb1a4 str r4, [r0, #0x4]
 *   @0x1bb1a8 beq 0x1bb1c0 <_Z11F_LayerGetXR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1bb1ac ldr r0, [pc, #0x74]
 *   @0x1bb1b0 mov r1, r4
 *   @0x1bb1b4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bb1b8 add r0, pc, r0
 *   @0x1bb1bc b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb1c0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb1c4 ldr r3, [r6, #0xc]
 *   @0x1bb1c8 mov r1, r4
 *   @0x1bb1cc bic r3, r3, #-16777216
 *   @0x1bb1d0 cmp r3, #1
 *   @0x1bb1d4 mov r7, r0
 *   @0x1bb1d8 mov r0, r6
 *   @0x1bb1dc beq 0x1bb20c <_Z11F_LayerGetXR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1bb1e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb1e4 mov r1, r0
 *   @0x1bb1e8 mov r0, r7
 *   @0x1bb1ec bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb1f0 cmp r0, #0
 *   @0x1bb1f4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bb1f8 vldr s15, [r0, #8]
 *   @0x1bb1fc vcvt.f64.f32 d6, s15
 *   @0x1bb200 vmov r2, r3, d6
 *   @0x1bb204 stm r5, {r2, r3}
 *   @0x1bb208 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb20c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb210 mov r1, r0
 *   @0x1bb214 mov r0, r7
 *   @0x1bb218 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb21c cmp r0, #0
 *   @0x1bb220 bne 0x1bb1f8 <_Z11F_LayerGetXR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1bb224 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb228 andseq r2, r9, r4, lsr #17
 *
 * ══ §128/181 F_LayerGetY(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb22c  size 164  41 条（0x1bb22c..0x1bb2d0）
 * @func 0x1bb22c 0x1bb2d0  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x74×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb22c cmp r3, #1
 *   @0x1bb230 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bb234 mov r4, #0
 *   @0x1bb238 mov r5, r0
 *   @0x1bb23c ldr r6, [sp, #0x18]
 *   @0x1bb240 str r4, [r0, #0xc]
 *   @0x1bb244 str r4, [r0]
 *   @0x1bb248 str r4, [r0, #0x4]
 *   @0x1bb24c beq 0x1bb264 <_Z11F_LayerGetYR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1bb250 ldr r0, [pc, #0x74]
 *   @0x1bb254 mov r1, r4
 *   @0x1bb258 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bb25c add r0, pc, r0
 *   @0x1bb260 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb264 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb268 ldr r3, [r6, #0xc]
 *   @0x1bb26c mov r1, r4
 *   @0x1bb270 bic r3, r3, #-16777216
 *   @0x1bb274 cmp r3, #1
 *   @0x1bb278 mov r7, r0
 *   @0x1bb27c mov r0, r6
 *   @0x1bb280 beq 0x1bb2b0 <_Z11F_LayerGetYR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1bb284 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb288 mov r1, r0
 *   @0x1bb28c mov r0, r7
 *   @0x1bb290 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb294 cmp r0, #0
 *   @0x1bb298 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bb29c vldr s15, [r0, #12]
 *   @0x1bb2a0 vcvt.f64.f32 d6, s15
 *   @0x1bb2a4 vmov r2, r3, d6
 *   @0x1bb2a8 stm r5, {r2, r3}
 *   @0x1bb2ac pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb2b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb2b4 mov r1, r0
 *   @0x1bb2b8 mov r0, r7
 *   @0x1bb2bc bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb2c0 cmp r0, #0
 *   @0x1bb2c4 bne 0x1bb29c <_Z11F_LayerGetYR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1bb2c8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb2cc andseq r2, r9, r12, lsr #16
 *
 * ══ §129/181 F_LayerGetHspeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb430  size 164  41 条（0x1bb430..0x1bb4d4）
 * @func 0x1bb430 0x1bb4d4  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x74×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb430 cmp r3, #1
 *   @0x1bb434 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bb438 mov r4, #0
 *   @0x1bb43c mov r5, r0
 *   @0x1bb440 ldr r6, [sp, #0x18]
 *   @0x1bb444 str r4, [r0, #0xc]
 *   @0x1bb448 str r4, [r0]
 *   @0x1bb44c str r4, [r0, #0x4]
 *   @0x1bb450 beq 0x1bb468 <_Z16F_LayerGetHspeedR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1bb454 ldr r0, [pc, #0x74]
 *   @0x1bb458 mov r1, r4
 *   @0x1bb45c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bb460 add r0, pc, r0
 *   @0x1bb464 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb468 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb46c ldr r3, [r6, #0xc]
 *   @0x1bb470 mov r1, r4
 *   @0x1bb474 bic r3, r3, #-16777216
 *   @0x1bb478 cmp r3, #1
 *   @0x1bb47c mov r7, r0
 *   @0x1bb480 mov r0, r6
 *   @0x1bb484 beq 0x1bb4b4 <_Z16F_LayerGetHspeedR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1bb488 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb48c mov r1, r0
 *   @0x1bb490 mov r0, r7
 *   @0x1bb494 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb498 cmp r0, #0
 *   @0x1bb49c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bb4a0 vldr s15, [r0, #16]
 *   @0x1bb4a4 vcvt.f64.f32 d6, s15
 *   @0x1bb4a8 vmov r2, r3, d6
 *   @0x1bb4ac stm r5, {r2, r3}
 *   @0x1bb4b0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb4b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb4b8 mov r1, r0
 *   @0x1bb4bc mov r0, r7
 *   @0x1bb4c0 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb4c4 cmp r0, #0
 *   @0x1bb4c8 bne 0x1bb4a0 <_Z16F_LayerGetHspeedR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1bb4cc pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb4d0 andseq r2, r9, r12, lsr #13
 *
 * ══ §130/181 F_LayerGetVspeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb4d4  size 164  41 条（0x1bb4d4..0x1bb578）
 * @func 0x1bb4d4 0x1bb578  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x74×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb4d4 cmp r3, #1
 *   @0x1bb4d8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bb4dc mov r4, #0
 *   @0x1bb4e0 mov r5, r0
 *   @0x1bb4e4 ldr r6, [sp, #0x18]
 *   @0x1bb4e8 str r4, [r0, #0xc]
 *   @0x1bb4ec str r4, [r0]
 *   @0x1bb4f0 str r4, [r0, #0x4]
 *   @0x1bb4f4 beq 0x1bb50c <_Z16F_LayerGetVspeedR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1bb4f8 ldr r0, [pc, #0x74]
 *   @0x1bb4fc mov r1, r4
 *   @0x1bb500 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bb504 add r0, pc, r0
 *   @0x1bb508 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb50c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb510 ldr r3, [r6, #0xc]
 *   @0x1bb514 mov r1, r4
 *   @0x1bb518 bic r3, r3, #-16777216
 *   @0x1bb51c cmp r3, #1
 *   @0x1bb520 mov r7, r0
 *   @0x1bb524 mov r0, r6
 *   @0x1bb528 beq 0x1bb558 <_Z16F_LayerGetVspeedR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1bb52c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb530 mov r1, r0
 *   @0x1bb534 mov r0, r7
 *   @0x1bb538 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb53c cmp r0, #0
 *   @0x1bb540 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bb544 vldr s15, [r0, #20]
 *   @0x1bb548 vcvt.f64.f32 d6, s15
 *   @0x1bb54c vmov r2, r3, d6
 *   @0x1bb550 stm r5, {r2, r3}
 *   @0x1bb554 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb558 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb55c mov r1, r0
 *   @0x1bb560 mov r0, r7
 *   @0x1bb564 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb568 cmp r0, #0
 *   @0x1bb56c bne 0x1bb544 <_Z16F_LayerGetVspeedR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1bb570 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb574 andseq r2, r9, r8, lsr r6
 *
 * ══ §131/181 F_LayerBackgroundGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bcf5c  size 164  41 条（0x1bcf5c..0x1bd000）
 * @func 0x1bcf5c 0x1bd000  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x6c×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bcf5c cmp r3, #1
 *   @0x1bcf60 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bcf64 mov r3, #0
 *   @0x1bcf68 mov r4, r3
 *   @0x1bcf6c mov r5, r0
 *   @0x1bcf70 movt r3, #0xbff0
 *   @0x1bcf74 str r4, [r0, #0xc]
 *   @0x1bcf78 str r3, [r0, #0x4]
 *   @0x1bcf7c str r4, [r0]
 *   @0x1bcf80 ldr r6, [sp, #0x18]
 *   @0x1bcf84 beq 0x1bcf9c <_Z25F_LayerBackgroundGetAlphaR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bcf88 ldr r0, [pc, #0x6c]
 *   @0x1bcf8c mov r1, r4
 *   @0x1bcf90 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bcf94 add r0, pc, r0
 *   @0x1bcf98 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bcf9c str r4, [r0]
 *   @0x1bcfa0 str r4, [r0, #0x4]
 *   @0x1bcfa4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bcfa8 mov r1, r4
 *   @0x1bcfac mov r7, r0
 *   @0x1bcfb0 mov r0, r6
 *   @0x1bcfb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bcfb8 mov r2, r4
 *   @0x1bcfbc mov r1, r0
 *   @0x1bcfc0 mov r0, r7
 *   @0x1bcfc4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bcfc8 cmp r0, #0
 *   @0x1bcfcc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcfd0 ldr r3, [r0]
 *   @0x1bcfd4 cmp r3, #1
 *   @0x1bcfd8 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bcfdc ldr r3, [r0, #0x1c]
 *   @0x1bcfe0 cmp r3, #0
 *   @0x1bcfe4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcfe8 vldr s15, [r3, #28]
 *   @0x1bcfec vcvt.f64.f32 d6, s15
 *   @0x1bcff0 vmov r2, r3, d6
 *   @0x1bcff4 stm r5, {r2, r3}
 *   @0x1bcff8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bcffc andseq r1, r9, r8, lsl #6
 *
 * ══ §132/181 F_LayerBackgroundGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd09c  size 164  41 条（0x1bd09c..0x1bd140）
 * @func 0x1bd09c 0x1bd140  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x6c×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd09c cmp r3, #1
 *   @0x1bd0a0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bd0a4 mov r3, #0
 *   @0x1bd0a8 mov r4, r3
 *   @0x1bd0ac mov r5, r0
 *   @0x1bd0b0 movt r3, #0xbff0
 *   @0x1bd0b4 str r4, [r0, #0xc]
 *   @0x1bd0b8 str r3, [r0, #0x4]
 *   @0x1bd0bc str r4, [r0]
 *   @0x1bd0c0 ldr r6, [sp, #0x18]
 *   @0x1bd0c4 beq 0x1bd0dc <_Z25F_LayerBackgroundGetSpeedR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bd0c8 ldr r0, [pc, #0x6c]
 *   @0x1bd0cc mov r1, r4
 *   @0x1bd0d0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bd0d4 add r0, pc, r0
 *   @0x1bd0d8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd0dc str r4, [r0]
 *   @0x1bd0e0 str r4, [r0, #0x4]
 *   @0x1bd0e4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd0e8 mov r1, r4
 *   @0x1bd0ec mov r7, r0
 *   @0x1bd0f0 mov r0, r6
 *   @0x1bd0f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd0f8 mov r2, r4
 *   @0x1bd0fc mov r1, r0
 *   @0x1bd100 mov r0, r7
 *   @0x1bd104 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd108 cmp r0, #0
 *   @0x1bd10c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bd110 ldr r3, [r0]
 *   @0x1bd114 cmp r3, #1
 *   @0x1bd118 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bd11c ldr r3, [r0, #0x1c]
 *   @0x1bd120 cmp r3, #0
 *   @0x1bd124 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bd128 vldr s15, [r3, #36]
 *   @0x1bd12c vcvt.f64.f32 d6, s15
 *   @0x1bd130 vmov r2, r3, d6
 *   @0x1bd134 stm r5, {r2, r3}
 *   @0x1bd138 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bd13c andseq r1, r9, r0, asr #4
 *
 * ══ §133/181 push_back(SCollision)  0x1cbe74  size 164  41 条（0x1cbe74..0x1cbf18）
 * @func 0x1cbe74 0x1cbf18  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×3 / 0x4×2 / 0x88×1 / 0x68×1 / 0x3×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cbe74 push {r4, r5, r6, lr}
 *   @0x1cbe78 sub sp, sp, #16
 *   @0x1cbe7c ldr r4, [pc, #0x88]
 *   @0x1cbe80 add r5, sp, #8
 *   @0x1cbe84 add r4, pc, r4
 *   @0x1cbe88 stm r5, {r0, r1}
 *   @0x1cbe8c ldm r4, {r2, r3}
 *   @0x1cbe90 cmp r2, r3
 *   @0x1cbe94 bge 0x1cbec8 <_Z9push_back10SCollision+0x54>
 *   @0x1cbe98 ldr r12, [r4, #0x8]
 *   @0x1cbe9c mov r3, r5
 *   @0x1cbea0 ldr r4, [pc, #0x68]
 *   @0x1cbea4 ldm r3!, {r0, r1}
 *   @0x1cbea8 add r3, r12, r2, lsl #3
 *   @0x1cbeac add r4, pc, r4
 *   @0x1cbeb0 add r5, r2, #1
 *   @0x1cbeb4 str r0, [r12, r2, lsl #3]
 *   @0x1cbeb8 str r5, [r4]
 *   @0x1cbebc str r1, [r3, #0x4]
 *   @0x1cbec0 add sp, sp, #16
 *   @0x1cbec4 pop {r4, r5, r6, pc}
 *   @0x1cbec8 cmp r3, #32
 *   @0x1cbecc movge r12, r3
 *   @0x1cbed0 movlt r12, #32
 *   @0x1cbed4 ldr r2, [pc, #0x38]
 *   @0x1cbed8 ldr r0, [r4, #0x8]
 *   @0x1cbedc mov r3, #0
 *   @0x1cbee0 add r2, pc, r2
 *   @0x1cbee4 lsl r1, r12, #4
 *   @0x1cbee8 str r3, [sp]
 *   @0x1cbeec mov r3, #74
 *   @0x1cbef0 lsl r6, r12, #1
 *   @0x1cbef4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1cbef8 ldr r2, [r4]
 *   @0x1cbefc str r6, [r4, #0x4]
 *   @0x1cbf00 str r0, [r4, #0x8]
 *   @0x1cbf04 mov r12, r0
 *   @0x1cbf08 b 0x1cbe9c <_Z9push_back10SCollision+0x28>
 *   @0x1cbf0c eorseq r6, r7, r12, lsl #22
 *   @0x1cbf10 eorseq r6, r7, r4, ror #21
 *   @0x1cbf14 andseq r5, r6, r0, asr r1
 *
 * ══ §134/181 Audio_NoiseIsPlaying(CNoise*)  0x2164bc  size 164  41 条（0x2164bc..0x216560）
 * @func 0x2164bc 0x216560  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetSound(int) / 0xb6a9c
 * 字段偏移 top8: 0x5×1 / 0x18×1 / 0x24×1 / 0x25×1 / 0x50×1 / 0x10×1 / 0x2×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2164bc push {r4, r5, lr}
 *   @0x2164c0 subs r5, r0, #0
 *   @0x2164c4 sub sp, sp, #12
 *   @0x2164c8 beq 0x21654c <_Z20Audio_NoiseIsPlayingP6CNoise+0x90>
 *   @0x2164cc ldrb r4, [r5, #0x5]
 *   @0x2164d0 cmp r4, #0
 *   @0x2164d4 bne 0x2164e4 <_Z20Audio_NoiseIsPlayingP6CNoise+0x28>
 *   @0x2164d8 mov r0, r4
 *   @0x2164dc add sp, sp, #12
 *   @0x2164e0 pop {r4, r5, pc}
 *   @0x2164e4 ldr r0, [r5, #0x18]
 *   @0x2164e8 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x2164ec ldrb r3, [r0, #0x24]
 *   @0x2164f0 cmp r3, #0
 *   @0x2164f4 bne 0x21653c <_Z20Audio_NoiseIsPlayingP6CNoise+0x80>
 *   @0x2164f8 ldrb r3, [r0, #0x25]
 *   @0x2164fc cmp r3, #0
 *   @0x216500 bne 0x21653c <_Z20Audio_NoiseIsPlayingP6CNoise+0x80>
 *   @0x216504 ldr r3, [pc, #0x50]
 *   @0x216508 movw r1, #0x1010
 *   @0x21650c ldr r0, [r5, #0x10]
 *   @0x216510 add r2, sp, #4
 *   @0x216514 ldr r3, [pc, r3]
 *   @0x216518 ldr r3, [r3]
 *   @0x21651c ldr r0, [r3, r0, lsl #2]
 *   @0x216520 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x216524 ldr r3, [sp, #0x4]
 *   @0x216528 sub r3, r3, #4096
 *   @0x21652c sub r3, r3, #18
 *   @0x216530 cmp r3, #1
 *   @0x216534 movhi r4, #0
 *   @0x216538 b 0x2164d8 <_Z20Audio_NoiseIsPlayingP6CNoise+0x1c>
 *   @0x21653c mov r4, r3
 *   @0x216540 mov r0, r4
 *   @0x216544 add sp, sp, #12
 *   @0x216548 pop {r4, r5, pc}
 *   @0x21654c mov r4, r5
 *   @0x216550 mov r0, r4
 *   @0x216554 add sp, sp, #12
 *   @0x216558 pop {r4, r5, pc}
 *   @0x21655c ldrheq r10, [sp], -r8
 *
 * ══ §135/181 Audio_AllGroupSoundsStopped(int)  0x218ae0  size 164  41 条（0x218ae0..0x218b84）
 * @func 0x218ae0 0x218b84  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_AllGroupSoundsStopped(int)+0x90 / Audio_GetSound(int)
 * 字段偏移 top8: 0x38×2 / 0x90×1 / 0x78×1 / 0x74×1 / 0x3c×1 / 0x2×1 / 0x5×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218ae0 ldr r3, [pc, #0x90]
 *   @0x218ae4 push {r4, r5, r6, r7, r8, lr}
 *   @0x218ae8 add r3, pc, r3
 *   @0x218aec mov r7, r0
 *   @0x218af0 ldr r5, [r3, #0x38]
 *   @0x218af4 cmp r5, #0
 *   @0x218af8 ble 0x218b70 <_Z27Audio_AllGroupSoundsStoppedi+0x90>
 *   @0x218afc ldr r8, [pc, #0x78]
 *   @0x218b00 mov r3, r5
 *   @0x218b04 ldr r6, [pc, #0x74]
 *   @0x218b08 mov r4, #0
 *   @0x218b0c add r8, pc, r8
 *   @0x218b10 add r6, pc, r6
 *   @0x218b14 b 0x218b28 <_Z27Audio_AllGroupSoundsStoppedi+0x48>
 *   @0x218b18 add r4, r4, #1
 *   @0x218b1c cmp r4, r5
 *   @0x218b20 beq 0x218b70 <_Z27Audio_AllGroupSoundsStoppedi+0x90>
 *   @0x218b24 ldr r3, [r6, #0x38]
 *   @0x218b28 cmp r4, r3
 *   @0x218b2c bge 0x218b18 <_Z27Audio_AllGroupSoundsStoppedi+0x38>
 *   @0x218b30 ldr r3, [r8, #0x3c]
 *   @0x218b34 ldr r3, [r3, r4, lsl #2]
 *   @0x218b38 cmp r3, #0
 *   @0x218b3c beq 0x218b18 <_Z27Audio_AllGroupSoundsStoppedi+0x38>
 *   @0x218b40 ldrb r2, [r3, #0x5]
 *   @0x218b44 cmp r2, #0
 *   @0x218b48 beq 0x218b18 <_Z27Audio_AllGroupSoundsStoppedi+0x38>
 *   @0x218b4c ldr r0, [r3, #0x18]
 *   @0x218b50 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x218b54 cmp r0, #0
 *   @0x218b58 beq 0x218b18 <_Z27Audio_AllGroupSoundsStoppedi+0x38>
 *   @0x218b5c ldr r3, [r0, #0x4c]
 *   @0x218b60 cmp r3, r7
 *   @0x218b64 bne 0x218b18 <_Z27Audio_AllGroupSoundsStoppedi+0x38>
 *   @0x218b68 mov r0, #0
 *   @0x218b6c pop {r4, r5, r6, r7, r8, pc}
 *   @0x218b70 mov r0, #1
 *   @0x218b74 pop {r4, r5, r6, r7, r8, pc}
 *   @0x218b78 subseq r12, r3, r12, lsr #15
 *   @0x218b7c subseq r12, r3, r8, lsl #15
 *   @0x218b80 subseq r12, r3, r4, lsl #15
 *
 * ══ §136/181 SortCompareProvided(RValue*, RValue*, RValue*)  0x249928  size 164  41 条（0x249928..0x2499cc）
 * @func 0x249928 0x2499cc  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*) / SortCompareProvided(RValue*, RValue*, RValue*)+0x90 / translate(EJSRetVal)
 * 字段偏移 top8: 0x8×2 / 0xc×2 / 0x4×2 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x249928 push {r4, r5, r6, lr}
 *   @0x24992c mov r3, r1
 *   @0x249930 sub sp, sp, #56
 *   @0x249934 mov r4, r2
 *   @0x249938 add r5, sp, #24
 *   @0x24993c ldr r2, [r3, #0x8]
 *   @0x249940 mov r6, r0
 *   @0x249944 ldr r3, [r3, #0xc]
 *   @0x249948 ldr r0, [r1]
 *   @0x24994c mov lr, r5
 *   @0x249950 ldr r1, [r1, #0x4]
 *   @0x249954 add r12, sp, #40
 *   @0x249958 str r5, [sp]
 *   @0x24995c mov r5, #5
 *   @0x249960 str r5, [sp, #0x14]
 *   @0x249964 stm lr!, {r0, r1, r2, r3}
 *   @0x249968 ldr r0, [r4]
 *   @0x24996c ldr r1, [r4, #0x4]
 *   @0x249970 ldr r2, [r4, #0x8]
 *   @0x249974 ldr r3, [r4, #0xc]
 *   @0x249978 stm r12!, {r0, r1, r2, r3}
 *   @0x24997c mov r2, r6
 *   @0x249980 mov r0, #0
 *   @0x249984 add r1, sp, #8
 *   @0x249988 mov r3, #2
 *   @0x24998c bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x249990 cmp r0, #0
 *   @0x249994 bne 0x2499c0 <_Z19SortCompareProvidedP6RValueS0_S0_+0x98>
 *   @0x249998 vldr d7, [sp, #8]
 *   @0x24999c vcvt.s32.f64 s14, d7
 *   @0x2499a0 vmov r3, s14
 *   @0x2499a4 cmp r3, #0
 *   @0x2499a8 mvnlt r0, #0
 *   @0x2499ac blt 0x2499b8 <_Z19SortCompareProvidedP6RValueS0_S0_+0x90>
 *   @0x2499b0 moveq r0, #0
 *   @0x2499b4 movne r0, #1
 *   @0x2499b8 add sp, sp, #56
 *   @0x2499bc pop {r4, r5, r6, pc}
 *   @0x2499c0 bl 0x242ebc <_Z9translate9EJSRetVal>
 *   @0x2499c4 add sp, sp, #56
 *   @0x2499c8 pop {r4, r5, r6, pc}
 *
 * ══ §137/181 anon_25f37c  0x25f37c  size 164  41 条（0x25f37c..0x25f420）
 * @func 0x25f37c 0x25f420  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: pcre_get_stringtable_entries / anon_25f37c+0x80 / anon_25f37c+0x50 / pcre_get_stringnumber
 * 字段偏移 top8: 0x1×2 / 0x8×1 / 0xc×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f37c push {r4, r5, r6, r7, lr}
 *   @0x25f380 mov r7, r2
 *   @0x25f384 ldr r2, [r0, #0x8]
 *   @0x25f388 mov r6, r3
 *   @0x25f38c sub sp, sp, #12
 *   @0x25f390 mov r12, r0
 *   @0x25f394 tst r2, #524288
 *   @0x25f398 mov r3, r1
 *   @0x25f39c bne 0x25f3ac <pcre_get_stringtable_entries+0x190>
 *   @0x25f3a0 ldr r2, [r0, #0xc]
 *   @0x25f3a4 tst r2, #1024
 *   @0x25f3a8 beq 0x25f418 <pcre_get_stringtable_entries+0x1fc>
 *   @0x25f3ac mov r1, r3
 *   @0x25f3b0 mov r0, r12
 *   @0x25f3b4 mov r2, sp
 *   @0x25f3b8 add r3, sp, #4
 *   @0x25f3bc bl 0x25f21c <pcre_get_stringtable_entries>
 *   @0x25f3c0 cmp r0, #0
 *   @0x25f3c4 ble 0x25f3fc <pcre_get_stringtable_entries+0x1e0>
 *   @0x25f3c8 ldm sp, {r1, r5}
 *   @0x25f3cc cmp r1, r5
 *   @0x25f3d0 bhi 0x25f404 <pcre_get_stringtable_entries+0x1e8>
 *   @0x25f3d4 ldrb r12, [r1]
 *   @0x25f3d8 ldrb r4, [r1, #0x1]
 *   @0x25f3dc add r1, r1, r0
 *   @0x25f3e0 orr r12, r4, r12, lsl #8
 *   @0x25f3e4 cmp r12, r6
 *   @0x25f3e8 bge 0x25f3cc <pcre_get_stringtable_entries+0x1b0>
 *   @0x25f3ec ldr r3, [r7, r12, lsl #3]
 *   @0x25f3f0 cmp r3, #0
 *   @0x25f3f4 blt 0x25f3cc <pcre_get_stringtable_entries+0x1b0>
 *   @0x25f3f8 mov r0, r12
 *   @0x25f3fc add sp, sp, #12
 *   @0x25f400 pop {r4, r5, r6, r7, pc}
 *   @0x25f404 ldrb r0, [r1]
 *   @0x25f408 ldrb r3, [r1, #0x1]
 *   @0x25f40c orr r0, r3, r0, lsl #8
 *   @0x25f410 add sp, sp, #12
 *   @0x25f414 pop {r4, r5, r6, r7, pc}
 *   @0x25f418 bl 0x25f148 <pcre_get_stringnumber>
 *   @0x25f41c add sp, sp, #12
 *
 * ══ §138/181 Json_create  0x287320  size 164  41 条（0x287320..0x2873c4）
 * @func 0x287320 0x2873c4  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / Json_create+0x50 / anon_28677c+0x38c / Json_dispose
 * 字段偏移 top8: 0x8c×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x287320 push {r3, r4, r5, lr}
 *   @0x287324 subs r4, r0, #0
 *   @0x287328 ldr r3, [pc, #0x8c]
 *   @0x28732c mov r2, #0
 *   @0x287330 add r3, pc, r3
 *   @0x287334 str r2, [r3]
 *   @0x287338 beq 0x2873a4 <Json_create+0x84>
 *   @0x28733c ldr r2, [pc, #0x7c]
 *   @0x287340 mov r0, #1
 *   @0x287344 mov r1, #32
 *   @0x287348 mov r3, #77
 *   @0x28734c add r2, pc, r2
 *   @0x287350 bl 0x285c4c <_calloc>
 *   @0x287354 subs r5, r0, #0
 *   @0x287358 beq 0x2873a4 <Json_create+0x84>
 *   @0x28735c ldrb r3, [r4]
 *   @0x287360 sub r3, r3, #1
 *   @0x287364 cmp r3, #31
 *   @0x287368 bhi 0x287388 <Json_create+0x68>
 *   @0x28736c add r3, r4, #1
 *   @0x287370 mov r4, r3
 *   @0x287374 add r3, r3, #1
 *   @0x287378 ldrb r2, [r4]
 *   @0x28737c sub r2, r2, #1
 *   @0x287380 cmp r2, #31
 *   @0x287384 bls 0x287370 <Json_create+0x50>
 *   @0x287388 mov r1, r4
 *   @0x28738c mov r0, r5
 *   @0x287390 bl 0x286b08 <spIkConstraintData_dispose+0x3b0>
 *   @0x287394 subs r3, r0, #0
 *   @0x287398 beq 0x2873ac <Json_create+0x8c>
 *   @0x28739c mov r0, r5
 *   @0x2873a0 pop {r3, r4, r5, pc}
 *   @0x2873a4 mov r5, #0
 *   @0x2873a8 b 0x28739c <Json_create+0x7c>
 *   @0x2873ac mov r0, r5
 *   @0x2873b0 mov r5, r3
 *   @0x2873b4 bl 0x2872c8 <Json_dispose>
 *   @0x2873b8 b 0x28739c <Json_create+0x7c>
 *   @0x2873bc umaaleq pc, r12, r0, r8
 *   @0x2873c0 andeq r0, sp, r12, ror #10
 *
 * ══ §139/181 yySocket::InitSocket(eSocketType)  0x297008  size 164  41 条（0x297008..0x2970ac）
 * @func 0x297008 0x2970ac  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::DetectIPv6()
 * 字段偏移 top8: 0x98×1 / 0x8×1 / 0xc×1 / 0x4×1 / 0x10×1 / 0x14×1 / 0x28×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x297008 ldr r12, [pc, #0x98]
 *   @0x29700c mov r2, #0
 *   @0x297010 push {r3, r4, r5, lr}
 *   @0x297014 ldr r12, [pc, r12]
 *   @0x297018 mov r5, #0
 *   @0x29701c str r1, [r0, #0x8]
 *   @0x297020 mov r3, #0
 *   @0x297024 str r5, [r0, #0xc]
 *   @0x297028 strd r2, r3, [r0, #64]
 *   @0x29702c mvn r2, #0
 *   @0x297030 mov r3, #120
 *   @0x297034 str r2, [r0]
 *   @0x297038 str r2, [r0, #0x4]
 *   @0x29703c mov r4, r0
 *   @0x297040 str r5, [r0, #0x10]
 *   @0x297044 str r5, [r0, #0x14]
 *   @0x297048 str r5, [r0, #0x28]
 *   @0x29704c strb r5, [r0, #0x2c]
 *   @0x297050 str r5, [r0, #0x4c]
 *   @0x297054 str r5, [r0, #0x50]
 *   @0x297058 str r5, [r0, #0x54]
 *   @0x29705c str r5, [r0, #0x58]
 *   @0x297060 str r5, [r0, #0x5c]
 *   @0x297064 str r5, [r0, #0x60]
 *   @0x297068 str r5, [r0, #0x64]
 *   @0x29706c str r5, [r0, #0xbc]
 *   @0x297070 str r5, [r0, #0xc0]
 *   @0x297074 strb r5, [r0, #0x2d]
 *   @0x297078 strb r5, [r0, #0x2f]
 *   @0x29707c strb r5, [r0, #0x30]
 *   @0x297080 str r3, [r0, #0xb4]
 *   @0x297084 str r3, [r0, #0xb8]
 *   @0x297088 str r5, [r12]
 *   @0x29708c bl 0x297000 <_ZN8yySocket10DetectIPv6Ev>
 *   @0x297090 mov r1, r5
 *   @0x297094 mov r2, #64
 *   @0x297098 strb r0, [r4, #0xc4]
 *   @0x29709c add r0, r4, #108
 *   @0x2970a0 pop {r3, r4, r5, lr}
 *   @0x2970a4 b 0xb65b0 <memset@plt>
 *   @0x2970a8 andseq r10, r5, r12, ror r9
 *
 * ══ §140/181 b2WheelJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&, b2Vec2 const&)  0x2d4170  size 164  41 条（0x2d4170..0x2d4214）
 * @func 0x2d4170 0x2d4214  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 37 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4170 vldr s15, [r1, #16]
 *   @0x2d4174 vldr s12, [r3, #4]
 *   @0x2d4178 vsub.f32 s12, s12, s15
 *   @0x2d417c vldr s13, [r1, #20]
 *   @0x2d4180 vldr s15, [r1, #24]
 *   @0x2d4184 vldr s10, [r1, #12]
 *   @0x2d4188 vldr s7, [r3]
 *   @0x2d418c vldr s9, [r2, #20]
 *   @0x2d4190 vldr s8, [r2, #24]
 *   @0x2d4194 vldr s14, [r2, #16]
 *   @0x2d4198 vldr s6, [r2, #12]
 *   @0x2d419c ldr r12, [sp]
 *   @0x2d41a0 str r1, [r0, #0x8]
 *   @0x2d41a4 str r2, [r0, #0xc]
 *   @0x2d41a8 vmul.f32 s11, s12, s13
 *   @0x2d41ac vmul.f32 s12, s12, s15
 *   @0x2d41b0 vsub.f32 s7, s7, s10
 *   @0x2d41b4 vneg.f32 s10, s13
 *   @0x2d41b8 vmla.f32 s11, s7, s15
 *   @0x2d41bc vmla.f32 s12, s7, s10
 *   @0x2d41c0 vstr s11, [r0, #20]
 *   @0x2d41c4 vstr s12, [r0, #24]
 *   @0x2d41c8 vldr s12, [r3, #4]
 *   @0x2d41cc vsub.f32 s14, s12, s14
 *   @0x2d41d0 vldr s11, [r3]
 *   @0x2d41d4 vmul.f32 s12, s14, s9
 *   @0x2d41d8 vmul.f32 s14, s14, s8
 *   @0x2d41dc vsub.f32 s11, s11, s6
 *   @0x2d41e0 vmla.f32 s12, s11, s8
 *   @0x2d41e4 vmls.f32 s14, s9, s11
 *   @0x2d41e8 vstr s12, [r0, #28]
 *   @0x2d41ec vstr s14, [r0, #32]
 *   @0x2d41f0 vldr s14, [r12, #4]
 *   @0x2d41f4 vmul.f32 s13, s13, s14
 *   @0x2d41f8 vldr s12, [r12]
 *   @0x2d41fc vmul.f32 s14, s15, s14
 *   @0x2d4200 vmla.f32 s13, s15, s12
 *   @0x2d4204 vmla.f32 s14, s10, s12
 *   @0x2d4208 vstr s13, [r0, #36]
 *   @0x2d420c vstr s14, [r0, #40]
 *   @0x2d4210 bx lr
 *
 * ══ §141/181 FT_Get_Sfnt_Name  0x2e8744  size 164  41 条（0x2e8744..0x2e87e8）
 * @func 0x2e8744 0x2e87e8  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3e7994 / ft_mem_free / FT_Stream_Seek / FT_Stream_Read
 * 字段偏移 top8: 0x8×3 / 0x10×3 / 0xc×3 / 0x68×1 / 0x2×1 / 0x4×1 / 0x6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8744 push.w {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2e8748 sub sp, #0x14
 *   @0x2e874c mov r5, r2
 *   @0x2e8750 cmp r2, #0x0
 *   @0x2e8754 cmp r0, #0x0
 *   @0x2e8758 ldr r3, [r0, #0x8]
 *   @0x2e875c bpl 0x2e87e0 <FT_Get_Sfnt_Name+0x9c>
 *   @0x2e8760 addsmi r3, r9, #84, #2
 *   @0x2e8764 bhs 0x2e87e0 <FT_Get_Sfnt_Name+0x9c>
 *   @0x2e8768 ldr.w r8, [r0, #0x164]
 *   @0x2e876c muls r7, r1, r7
 *   @0x2e8770 stmdbhi r3!, {r0, r1, r2, r10}
 *   @0x2e8774 cbz r3, 0x2e87c2 <FT_Get_Sfnt_Name+0x7e>
 *   @0x2e8778 cbnz r2, 0x2e87c2 <FT_Get_Sfnt_Name+0x7e>
 *   @0x2e877c stmdbge r3, {r2, r5, r6, r12, pc}
 *   @0x2e8780 ldr r6, [r0, #0x68]
 *   @0x2e8784 movs r1, #0x1
 *   @0x2e8788 mov r0, r9
 *   @0x2e878c blls 0x3e7994 <error_g0017+0x40638>
 *   @0x2e8790 str r0, [r4, #0x10]
 *   @0x2e8794 mov r0, r9
 *   @0x2e8798 bl 0x2e7336 <ft_mem_free>
 *   @0x2e879c movs r3, #0x0
 *   @0x2e87a0 strh r3, [r4, #0x8]
 *   @0x2e87a4 mov r0, r6
 *   @0x2e87a8 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e87ac str r0, [sp, #0xc]
 *   @0x2e87b0 bne 0x2e8794 <FT_Get_Sfnt_Name+0x50>
 *   @0x2e87b4 ldr r1, [r4, #0x10]
 *   @0x2e87b8 bl 0x2e698e <FT_Stream_Read>
 *   @0x2e87bc str r0, [sp, #0xc]
 *   @0x2e87c0 bne 0x2e8794 <FT_Get_Sfnt_Name+0x50>
 *   @0x2e87c4 eorhi r3, r11, r7
 *   @0x2e87c8 ldrh r3, [r4, #0x2]
 *   @0x2e87cc ldrh r3, [r4, #0x4]
 *   @0x2e87d0 ldrh r3, [r4, #0x6]
 *   @0x2e87d4 ldr r3, [r4, #0x10]
 *   @0x2e87d8 ldrh r3, [r4, #0x8]
 *   @0x2e87dc movs r3, #0x0
 *   @0x2e87e0 ldr r0, [sp, #0xc]
 *   @0x2e87e4 pop.w {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §142/181 __gnu_Unwind_RaiseException  0x319a6c  size 164  41 条（0x319a6c..0x319b10）
 * @func 0x319a6c 0x319b10  size 164  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_319630+0x114 / anon_319630+0x220 / anon_319630+0x2ac
 * 字段偏移 top8: 0x40×2 / 0x3c×1 / 0x-1e0×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319a6c ldr r3, [r1, #0x3c]
 *   @0x319a70 push {r4, r5, r6, r7, lr}
 *   @0x319a74 add lr, r1, #4
 *   @0x319a78 str r3, [r1, #0x40]
 *   @0x319a7c mov r5, r0
 *   @0x319a80 mov r4, r1
 *   @0x319a84 sub sp, sp, #484
 *   @0x319a88 ldm lr!, {r0, r1, r2, r3}
 *   @0x319a8c add r12, sp, #4
 *   @0x319a90 add r6, sp, #480
 *   @0x319a94 stm r12!, {r0, r1, r2, r3}
 *   @0x319a98 ldm lr!, {r0, r1, r2, r3}
 *   @0x319a9c stm r12!, {r0, r1, r2, r3}
 *   @0x319aa0 ldm lr!, {r0, r1, r2, r3}
 *   @0x319aa4 stm r12!, {r0, r1, r2, r3}
 *   @0x319aa8 ldm lr, {r0, r1, r2, r3}
 *   @0x319aac stm r12, {r0, r1, r2, r3}
 *   @0x319ab0 mvn r3, #0
 *   @0x319ab4 str r3, [r6, #-0x1e0]!
 *   @0x319ab8 mov r0, r5
 *   @0x319abc ldr r1, [sp, #0x40]
 *   @0x319ac0 bl 0x319744 <__gnu_uldivmod_helper+0x150>
 *   @0x319ac4 cmp r0, #0
 *   @0x319ac8 bne 0x319b04 <__gnu_Unwind_RaiseException+0x98>
 *   @0x319acc ldr r3, [r5, #0x10]
 *   @0x319ad0 mov r1, r5
 *   @0x319ad4 mov r2, sp
 *   @0x319ad8 blx r3
 *   @0x319adc cmp r0, #8
 *   @0x319ae0 mov r7, r0
 *   @0x319ae4 beq 0x319ab8 <__gnu_Unwind_RaiseException+0x4c>
 *   @0x319ae8 mov r0, sp
 *   @0x319aec bl 0x319850 <__gnu_uldivmod_helper+0x25c>
 *   @0x319af0 cmp r7, #6
 *   @0x319af4 bne 0x319b04 <__gnu_Unwind_RaiseException+0x98>
 *   @0x319af8 mov r0, r5
 *   @0x319afc mov r1, r4
 *   @0x319b00 bl 0x3198dc <__gnu_uldivmod_helper+0x2e8>
 *   @0x319b04 mov r0, #9
 *   @0x319b08 add sp, sp, #484
 *   @0x319b0c pop {r4, r5, r6, r7, pc}
 *
 * ══ §143/181 FT_New_Size  0x2e8938  size 162  41 条（0x2e8938..0x2e89da）
 * @func 0x2e8938 0x2e89da  size 162  41 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3678e8 / 0x3678d8 / ft_mem_alloc / 0x368894
 * 字段偏移 top8: 0x4×2 / 0x60×1 / 0x64×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8938 push.w {r0, r1, r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2e893c mov r8, r1
 *   @0x2e8940 cmp r0, #0x0
 *   @0x2e8944 cmp r1, #0x0
 *   @0x2e8948 ldr r3, [r0, #0x60]
 *   @0x2e894c beq 0x2e89d2 <FT_New_Size+0x9a>
 *   @0x2e8950 str r7, [r1]
 *   @0x2e8954 add.w r9, sp, #0x4
 *   @0x2e8958 ldr r6, [r0, #0x64]
 *   @0x2e895c ldr.w r10, [r3, #0xc]
 *   @0x2e8960 mov r0, r6
 *   @0x2e8964 .word 0xf7fe1028
 *   @0x2e8968 blls 0x3678e8 <_ZTS12CDS_Priority+0x9940>
 *   @0x2e896c mov r4, r0
 *   @0x2e8970 mov r0, r6
 *   @0x2e8974 mov r2, r9
 *   @0x2e8978 blls 0x3678d8 <_ZTS12CDS_Priority+0x9930>
 *   @0x2e897c mov r7, r0
 *   @0x2e8980 str r5, [r4]
 *   @0x2e8984 movs r1, #0x24
 *   @0x2e8988 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e898c ldr r3, [sp, #0x4]
 *   @0x2e8990 str r0, [r4, #0x28]
 *   @0x2e8994 tstlt r3, r8, lsr r0
 *   @0x2e8998 mov r0, r4
 *   @0x2e899c str r0, [sp, #0x4]
 *   @0x2e89a0 cbnz r3, 0x2e89b2 <FT_New_Size+0x7a>
 *   @0x2e89a4 .word 0xf1054000
 *   @0x2e89a8 adcsvs r0, r12, r12, rrx
 *   @0x2e89ac mov r1, r7
 *   @0x2e89b0 blls 0x368894 <_ZTS12CDS_Priority+0xa8ec>
 *   @0x2e89b4 cbz r3, 0x2e89c6 <FT_New_Size+0x8e>
 *   @0x2e89b8 mov r1, r7
 *   @0x2e89bc .word 0x4630fcbc
 *   @0x2e89c0 mov r1, r4
 *   @0x2e89c4 stmdals r1, {r3, r4, r5, r7, r10, r11, r12, sp, lr, pc}
 *   @0x2e89c8 b 0x2e89d4 <FT_New_Size+0x9c>
 *   @0x2e89cc b 0x2e89d4 <FT_New_Size+0x9c>
 *   @0x2e89d0 b 0x2e89d4 <FT_New_Size+0x9c>
 *   @0x2e89d4 add sp, #0x8
 *   @0x2e89d8 strdlt r8, r9, [r8, #-112]
 *
 * ══ §144/181 FreeBufferVertex(int)  0xc8ee0  size 160  40 条（0xc8ee0..0xc8f80）
 * @func 0xc8ee0 0xc8f80  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)×2 / FreeBufferVertex(int)+0x90 / MemoryManager::Free(void const*) / VertexBuffer::~VertexBuffer()
 * 字段偏移 top8: 0x2×2 / 0x30×2 / 0x84×1 / 0x4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8ee0 push {r4, r5, r6, lr}
 *   @0xc8ee4 subs r4, r0, #0
 *   @0xc8ee8 blt 0xc8f70 <_Z16FreeBufferVertexi+0x90>
 *   @0xc8eec ldr r3, [pc, #0x84]
 *   @0xc8ef0 add r3, pc, r3
 *   @0xc8ef4 ldr r2, [r3, #0x4]
 *   @0xc8ef8 cmp r4, r2
 *   @0xc8efc bge 0xc8f70 <_Z16FreeBufferVertexi+0x90>
 *   @0xc8f00 ldr r3, [r3]
 *   @0xc8f04 ldr r5, [r3, r4, lsl #2]
 *   @0xc8f08 cmp r5, #0
 *   @0xc8f0c beq 0xc8f70 <_Z16FreeBufferVertexi+0x90>
 *   @0xc8f10 ldr r0, [r5]
 *   @0xc8f14 cmp r0, #0
 *   @0xc8f18 beq 0xc8f28 <_Z16FreeBufferVertexi+0x48>
 *   @0xc8f1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc8f20 mov r3, #0
 *   @0xc8f24 str r3, [r5]
 *   @0xc8f28 ldr r6, [r5, #0x30]
 *   @0xc8f2c cmp r6, #0
 *   @0xc8f30 beq 0xc8f4c <_Z16FreeBufferVertexi+0x6c>
 *   @0xc8f34 mov r0, r6
 *   @0xc8f38 bl 0x18373c <_ZN12VertexBufferD2Ev>
 *   @0xc8f3c mov r0, r6
 *   @0xc8f40 bl 0x27d1d0 <_ZdlPv>
 *   @0xc8f44 mov r3, #0
 *   @0xc8f48 str r3, [r5, #0x30]
 *   @0xc8f4c mov r0, r5
 *   @0xc8f50 bl 0x27d1d0 <_ZdlPv>
 *   @0xc8f54 ldr r3, [pc, #0x20]
 *   @0xc8f58 mov r2, #0
 *   @0xc8f5c mov r0, #1
 *   @0xc8f60 add r3, pc, r3
 *   @0xc8f64 ldr r3, [r3]
 *   @0xc8f68 str r2, [r3, r4, lsl #2]
 *   @0xc8f6c pop {r4, r5, r6, pc}
 *   @0xc8f70 mov r0, #0
 *   @0xc8f74 pop {r4, r5, r6, pc}
 *   @0xc8f78 eorseq r1, r11, r4, asr #4
 *   @0xc8f7c ldrsbteq r1, [r11], -r4
 *
 * ══ §145/181 F_Vertex_Freeze_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xca5d8  size 160  40 条（0xca5d8..0xca678）
 * @func 0xca5d8 0xca678  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GetBufferVertex(int)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x64×1 / 0x20×1 / 0x24×1 / 0x2c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xca5d8 cmp r3, #1
 *   @0xca5dc mov r2, #0
 *   @0xca5e0 push {r4, lr}
 *   @0xca5e4 mov r1, r2
 *   @0xca5e8 mov r4, r3
 *   @0xca5ec movt r2, #0xbff0
 *   @0xca5f0 str r1, [r0, #0xc]
 *   @0xca5f4 stm r0, {r1, r2}
 *   @0xca5f8 ldr r0, [sp, #0x8]
 *   @0xca5fc beq 0xca614 <_Z21F_Vertex_Freeze_debugR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0xca600 ldr r0, [pc, #0x64]
 *   @0xca604 mov r1, #1
 *   @0xca608 pop {r4, lr}
 *   @0xca60c add r0, pc, r0
 *   @0xca610 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xca614 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xca618 bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xca61c subs r3, r0, #0
 *   @0xca620 beq 0xca658 <_Z21F_Vertex_Freeze_debugR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xca624 ldrb r2, [r3, #0x20]
 *   @0xca628 cmp r2, #0
 *   @0xca62c bne 0xca658 <_Z21F_Vertex_Freeze_debugR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xca630 ldr r3, [r3, #0x24]
 *   @0xca634 cmn r3, #1
 *   @0xca638 beq 0xca650 <_Z21F_Vertex_Freeze_debugR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xca63c ldr r0, [pc, #0x2c]
 *   @0xca640 mov r1, r4
 *   @0xca644 pop {r4, lr}
 *   @0xca648 add r0, pc, r0
 *   @0xca64c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xca650 pop {r4, lr}
 *   @0xca654 b 0xca1a0 <_Z13_FreezeBufferP13Buffer_Vertex>
 *   @0xca658 ldr r0, [pc, #0x14]
 *   @0xca65c mov r1, #1
 *   @0xca660 pop {r4, lr}
 *   @0xca664 add r0, pc, r0
 *   @0xca668 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xca66c .word 0x002678dc
 *   @0xca670 .word 0x002678f8
 *   @0xca674 eoreq r7, r6, r12, lsr #17
 *
 * ══ §146/181 CheckInstances(int)  0xd4038  size 160  40 条（0xd4038..0xd40d8）
 * @func 0xd4038 0xd40d8  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x28×2 / 0x84×1 / 0x54×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd4038 ldr r12, [pc, #0x84]
 *   @0xd403c mov r2, #0
 *   @0xd4040 push {r3, lr}
 *   @0xd4044 add r12, pc, r12
 *   @0xd4048 ldr r3, [r12]
 *   @0xd404c cmp r3, r12
 *   @0xd4050 beq 0xd4064 <_Z14CheckInstancesi+0x2c>
 *   @0xd4054 ldr r3, [r3]
 *   @0xd4058 add r2, r2, #1
 *   @0xd405c cmp r3, r12
 *   @0xd4060 bne 0xd4054 <_Z14CheckInstancesi+0x1c>
 *   @0xd4064 cmp r2, r0
 *   @0xd4068 beq 0xd40a0 <_Z14CheckInstancesi+0x68>
 *   @0xd406c ldr r3, [pc, #0x54]
 *   @0xd4070 mov r2, r0
 *   @0xd4074 ldr r1, [pc, #0x50]
 *   @0xd4078 ldr r3, [pc, r3]
 *   @0xd407c add r1, pc, r1
 *   @0xd4080 ldr r0, [r3]
 *   @0xd4084 ldr r3, [r0]
 *   @0xd4088 ldr r3, [r3, #0xc]
 *   @0xd408c blx r3
 *   @0xd4090 mov r3, #0
 *   @0xd4094 mov r2, #42
 *   @0xd4098 str r2, [r3]
 *   @0xd409c pop {r3, pc}
 *   @0xd40a0 ldr r3, [pc, #0x28]
 *   @0xd40a4 ldr r1, [pc, #0x28]
 *   @0xd40a8 ldr r3, [pc, r3]
 *   @0xd40ac add r1, pc, r1
 *   @0xd40b0 ldr r0, [r3]
 *   @0xd40b4 ldr r3, [r0]
 *   @0xd40b8 ldr r3, [r3, #0xc]
 *   @0xd40bc blx r3
 *   @0xd40c0 pop {r3, pc}
 *   @0xd40c4 eorseq r6, r10, r0, ror r1
 *   @0xd40c8 mlaseq r1, r12, r6, r9
 *   @0xd40cc eoreq lr, r5, r4, asr #14
 *   @0xd40d0 eorseq r9, r1, r12, ror #12
 *   @0xd40d4 eoreq lr, r5, r0, lsr r7
 *
 * ══ §147/181 F_DsStackWrite(RValue&, CInstance*, CInstance*, int, RValue*)  0xfbcc0  size 160  40 条（0xfbcc0..0xfbd60）
 * @func 0xfbcc0 0xfbd60  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsStackWrite(RValue&, CInstance*, CInstance*, int, RValue*)+0x7c / CDS_Stack::WriteToString(char const*&) / YYCreateString(RValue*, char const*) / YYFree(void const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x10×1 / 0x6c×1 / 0x5c×1 / 0x-4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfbcc0 push {r4, lr}
 *   @0xfbcc4 sub sp, sp, #8
 *   @0xfbcc8 mov r4, r0
 *   @0xfbccc mov r1, #0
 *   @0xfbcd0 ldr r0, [sp, #0x10]
 *   @0xfbcd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfbcd8 subs r2, r0, #0
 *   @0xfbcdc blt 0xfbd3c <_Z14F_DsStackWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfbce0 ldr r3, [pc, #0x6c]
 *   @0xfbce4 ldr r3, [pc, r3]
 *   @0xfbce8 ldr r3, [r3]
 *   @0xfbcec cmp r2, r3
 *   @0xfbcf0 bge 0xfbd3c <_Z14F_DsStackWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfbcf4 ldr r3, [pc, #0x5c]
 *   @0xfbcf8 ldr r3, [pc, r3]
 *   @0xfbcfc ldr r3, [r3, #0x4]
 *   @0xfbd00 ldr r1, [r3, r2, lsl #2]
 *   @0xfbd04 cmp r1, #0
 *   @0xfbd08 beq 0xfbd3c <_Z14F_DsStackWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfbd0c add r1, sp, #8
 *   @0xfbd10 mov r0, #0
 *   @0xfbd14 str r0, [r1, #-0x4]!
 *   @0xfbd18 ldr r0, [r3, r2, lsl #2]
 *   @0xfbd1c bl 0x202c70 <_ZN9CDS_Stack13WriteToStringERPKc>
 *   @0xfbd20 mov r0, r4
 *   @0xfbd24 ldr r1, [sp, #0x4]
 *   @0xfbd28 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xfbd2c ldr r0, [sp, #0x4]
 *   @0xfbd30 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xfbd34 add sp, sp, #8
 *   @0xfbd38 pop {r4, pc}
 *   @0xfbd3c ldr r0, [pc, #0x18]
 *   @0xfbd40 mov r1, #0
 *   @0xfbd44 add r0, pc, r0
 *   @0xfbd48 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfbd4c add sp, sp, #8
 *   @0xfbd50 pop {r4, pc}
 *   @0xfbd54 mlaeq pc, r8, r1, r2
 *   @0xfbd58 eoreq r2, pc, r8, lsl #3
 *   @0xfbd5c .word 0x0023beb8
 *
 * ══ §148/181 F_DsQueueWrite(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc0ec  size 160  40 条（0xfc0ec..0xfc18c）
 * @func 0xfc0ec 0xfc18c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsQueueWrite(RValue&, CInstance*, CInstance*, int, RValue*)+0x7c / CDS_Queue::WriteToString(char const*&) / YYCreateString(RValue*, char const*) / YYFree(void const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x10×1 / 0x6c×1 / 0x5c×1 / 0x-4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc0ec push {r4, lr}
 *   @0xfc0f0 sub sp, sp, #8
 *   @0xfc0f4 mov r4, r0
 *   @0xfc0f8 mov r1, #0
 *   @0xfc0fc ldr r0, [sp, #0x10]
 *   @0xfc100 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc104 subs r2, r0, #0
 *   @0xfc108 blt 0xfc168 <_Z14F_DsQueueWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfc10c ldr r3, [pc, #0x6c]
 *   @0xfc110 ldr r3, [pc, r3]
 *   @0xfc114 ldr r3, [r3]
 *   @0xfc118 cmp r2, r3
 *   @0xfc11c bge 0xfc168 <_Z14F_DsQueueWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfc120 ldr r3, [pc, #0x5c]
 *   @0xfc124 ldr r3, [pc, r3]
 *   @0xfc128 ldr r3, [r3, #0x4]
 *   @0xfc12c ldr r1, [r3, r2, lsl #2]
 *   @0xfc130 cmp r1, #0
 *   @0xfc134 beq 0xfc168 <_Z14F_DsQueueWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfc138 add r1, sp, #8
 *   @0xfc13c mov r0, #0
 *   @0xfc140 str r0, [r1, #-0x4]!
 *   @0xfc144 ldr r0, [r3, r2, lsl #2]
 *   @0xfc148 bl 0x202e30 <_ZN9CDS_Queue13WriteToStringERPKc>
 *   @0xfc14c mov r0, r4
 *   @0xfc150 ldr r1, [sp, #0x4]
 *   @0xfc154 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xfc158 ldr r0, [sp, #0x4]
 *   @0xfc15c bl 0xcef90 <_Z6YYFreePKv>
 *   @0xfc160 add sp, sp, #8
 *   @0xfc164 pop {r4, pc}
 *   @0xfc168 ldr r0, [pc, #0x18]
 *   @0xfc16c mov r1, #0
 *   @0xfc170 add r0, pc, r0
 *   @0xfc174 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc178 add sp, sp, #8
 *   @0xfc17c pop {r4, pc}
 *   @0xfc180 eoreq r1, pc, r12, asr sp
 *   @0xfc184 eoreq r1, pc, r12, asr #26
 *   @0xfc188 eoreq r11, r3, r12, lsl #21
 *
 * ══ §149/181 F_DsListWrite(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc954  size 160  40 条（0xfc954..0xfc9f4）
 * @func 0xfc954 0xfc9f4  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsListWrite(RValue&, CInstance*, CInstance*, int, RValue*)+0x7c / CDS_List::WriteToString(char const*&) / YYCreateString(RValue*, char const*) / YYFree(void const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x10×1 / 0x6c×1 / 0x5c×1 / 0x-4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc954 push {r4, lr}
 *   @0xfc958 sub sp, sp, #8
 *   @0xfc95c mov r4, r0
 *   @0xfc960 mov r1, #0
 *   @0xfc964 ldr r0, [sp, #0x10]
 *   @0xfc968 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc96c subs r2, r0, #0
 *   @0xfc970 blt 0xfc9d0 <_Z13F_DsListWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfc974 ldr r3, [pc, #0x6c]
 *   @0xfc978 ldr r3, [pc, r3]
 *   @0xfc97c ldr r3, [r3]
 *   @0xfc980 cmp r2, r3
 *   @0xfc984 bge 0xfc9d0 <_Z13F_DsListWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfc988 ldr r3, [pc, #0x5c]
 *   @0xfc98c ldr r3, [pc, r3]
 *   @0xfc990 ldr r3, [r3, #0x4]
 *   @0xfc994 ldr r1, [r3, r2, lsl #2]
 *   @0xfc998 cmp r1, #0
 *   @0xfc99c beq 0xfc9d0 <_Z13F_DsListWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfc9a0 add r1, sp, #8
 *   @0xfc9a4 mov r0, #0
 *   @0xfc9a8 str r0, [r1, #-0x4]!
 *   @0xfc9ac ldr r0, [r3, r2, lsl #2]
 *   @0xfc9b0 bl 0x20301c <_ZN8CDS_List13WriteToStringERPKc>
 *   @0xfc9b4 mov r0, r4
 *   @0xfc9b8 ldr r1, [sp, #0x4]
 *   @0xfc9bc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xfc9c0 ldr r0, [sp, #0x4]
 *   @0xfc9c4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xfc9c8 add sp, sp, #8
 *   @0xfc9cc pop {r4, pc}
 *   @0xfc9d0 ldr r0, [pc, #0x18]
 *   @0xfc9d4 mov r1, #0
 *   @0xfc9d8 add r0, pc, r0
 *   @0xfc9dc bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc9e0 add sp, sp, #8
 *   @0xfc9e4 pop {r4, pc}
 *   @0xfc9e8 eoreq r1, pc, r4, lsl #6
 *   @0xfc9ec .word 0x002f12f4
 *   @0xfc9f0 eoreq r11, r3, r4, lsr #4
 *
 * ══ §150/181 F_DsPriorityWrite(RValue&, CInstance*, CInstance*, int, RValue*)  0xfcf30  size 160  40 条（0xfcf30..0xfcfd0）
 * @func 0xfcf30 0xfcfd0  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsPriorityWrite(RValue&, CInstance*, CInstance*, int, RValue*)+0x7c / CDS_Priority::WriteToString(char const*&) / YYCreateString(RValue*, char const*) / YYFree(void const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x10×1 / 0x6c×1 / 0x5c×1 / 0x-4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfcf30 push {r4, lr}
 *   @0xfcf34 sub sp, sp, #8
 *   @0xfcf38 mov r4, r0
 *   @0xfcf3c mov r1, #0
 *   @0xfcf40 ldr r0, [sp, #0x10]
 *   @0xfcf44 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfcf48 subs r2, r0, #0
 *   @0xfcf4c blt 0xfcfac <_Z17F_DsPriorityWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfcf50 ldr r3, [pc, #0x6c]
 *   @0xfcf54 ldr r3, [pc, r3]
 *   @0xfcf58 ldr r3, [r3]
 *   @0xfcf5c cmp r2, r3
 *   @0xfcf60 bge 0xfcfac <_Z17F_DsPriorityWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfcf64 ldr r3, [pc, #0x5c]
 *   @0xfcf68 ldr r3, [pc, r3]
 *   @0xfcf6c ldr r3, [r3, #0x4]
 *   @0xfcf70 ldr r1, [r3, r2, lsl #2]
 *   @0xfcf74 cmp r1, #0
 *   @0xfcf78 beq 0xfcfac <_Z17F_DsPriorityWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfcf7c add r1, sp, #8
 *   @0xfcf80 mov r0, #0
 *   @0xfcf84 str r0, [r1, #-0x4]!
 *   @0xfcf88 ldr r0, [r3, r2, lsl #2]
 *   @0xfcf8c bl 0x203d6c <_ZN12CDS_Priority13WriteToStringERPKc>
 *   @0xfcf90 mov r0, r4
 *   @0xfcf94 ldr r1, [sp, #0x4]
 *   @0xfcf98 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xfcf9c ldr r0, [sp, #0x4]
 *   @0xfcfa0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xfcfa4 add sp, sp, #8
 *   @0xfcfa8 pop {r4, pc}
 *   @0xfcfac ldr r0, [pc, #0x18]
 *   @0xfcfb0 mov r1, #0
 *   @0xfcfb4 add r0, pc, r0
 *   @0xfcfb8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfcfbc add sp, sp, #8
 *   @0xfcfc0 pop {r4, pc}
 *   @0xfcfc4 eoreq r0, pc, r0, lsr #30
 *   @0xfcfc8 eoreq r0, pc, r0, lsl pc
 *   @0xfcfcc eoreq r10, r3, r8, asr #24
 *
 * ══ §151/181 F_DsGridCopy(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd1bc  size 160  40 条（0xfd1bc..0xfd25c）
 * @func 0xfd1bc 0xfd25c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_DsGridCopy(RValue&, CInstance*, CInstance*, int, RValue*)+0x80×2
 * 字段偏移 top8: 0x2×2 / 0x10×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd1bc push {r3, r4, r5, lr}
 *   @0xfd1c0 mov r1, #0
 *   @0xfd1c4 ldr r5, [sp, #0x10]
 *   @0xfd1c8 mov r0, r5
 *   @0xfd1cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd1d0 mov r1, #1
 *   @0xfd1d4 mov r4, r0
 *   @0xfd1d8 mov r0, r5
 *   @0xfd1dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd1e0 cmp r4, #0
 *   @0xfd1e4 blt 0xfd23c <_Z12F_DsGridCopyR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfd1e8 ldr r3, [pc, #0x60]
 *   @0xfd1ec ldr r3, [pc, r3]
 *   @0xfd1f0 ldr r3, [r3]
 *   @0xfd1f4 cmp r4, r3
 *   @0xfd1f8 bge 0xfd23c <_Z12F_DsGridCopyR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfd1fc ldr r2, [pc, #0x50]
 *   @0xfd200 ldr r2, [pc, r2]
 *   @0xfd204 ldr r2, [r2, #0x4]
 *   @0xfd208 ldr r12, [r2, r4, lsl #2]
 *   @0xfd20c cmp r12, #0
 *   @0xfd210 beq 0xfd23c <_Z12F_DsGridCopyR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfd214 cmp r0, #0
 *   @0xfd218 blt 0xfd23c <_Z12F_DsGridCopyR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfd21c cmp r0, r3
 *   @0xfd220 bge 0xfd23c <_Z12F_DsGridCopyR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfd224 ldr r1, [r2, r0, lsl #2]
 *   @0xfd228 cmp r1, #0
 *   @0xfd22c beq 0xfd23c <_Z12F_DsGridCopyR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfd230 mov r0, r12
 *   @0xfd234 pop {r3, r4, r5, lr}
 *   @0xfd238 b 0x20b478 <_ZN8CDS_Grid6AssignEPS_>
 *   @0xfd23c ldr r0, [pc, #0x14]
 *   @0xfd240 mov r1, #0
 *   @0xfd244 pop {r3, r4, r5, lr}
 *   @0xfd248 add r0, pc, r0
 *   @0xfd24c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd250 mlaeq pc, r8, r12, r0
 *   @0xfd254 eoreq r0, pc, r8, lsl #25
 *   @0xfd258 .word 0x0023a9b4
 *
 * ══ §152/181 F_DsGridWrite(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe904  size 160  40 条（0xfe904..0xfe9a4）
 * @func 0xfe904 0xfe9a4  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsGridWrite(RValue&, CInstance*, CInstance*, int, RValue*)+0x7c / CDS_Grid::WriteToString(char const*&) / YYCreateString(RValue*, char const*) / YYFree(void const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x10×1 / 0x6c×1 / 0x5c×1 / 0x-4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe904 push {r4, lr}
 *   @0xfe908 sub sp, sp, #8
 *   @0xfe90c mov r4, r0
 *   @0xfe910 mov r1, #0
 *   @0xfe914 ldr r0, [sp, #0x10]
 *   @0xfe918 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe91c subs r2, r0, #0
 *   @0xfe920 blt 0xfe980 <_Z13F_DsGridWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfe924 ldr r3, [pc, #0x6c]
 *   @0xfe928 ldr r3, [pc, r3]
 *   @0xfe92c ldr r3, [r3]
 *   @0xfe930 cmp r2, r3
 *   @0xfe934 bge 0xfe980 <_Z13F_DsGridWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfe938 ldr r3, [pc, #0x5c]
 *   @0xfe93c ldr r3, [pc, r3]
 *   @0xfe940 ldr r3, [r3, #0x4]
 *   @0xfe944 ldr r1, [r3, r2, lsl #2]
 *   @0xfe948 cmp r1, #0
 *   @0xfe94c beq 0xfe980 <_Z13F_DsGridWriteR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xfe950 add r1, sp, #8
 *   @0xfe954 mov r0, #0
 *   @0xfe958 str r0, [r1, #-0x4]!
 *   @0xfe95c ldr r0, [r3, r2, lsl #2]
 *   @0xfe960 bl 0x204108 <_ZN8CDS_Grid13WriteToStringERPKc>
 *   @0xfe964 mov r0, r4
 *   @0xfe968 ldr r1, [sp, #0x4]
 *   @0xfe96c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xfe970 ldr r0, [sp, #0x4]
 *   @0xfe974 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xfe978 add sp, sp, #8
 *   @0xfe97c pop {r4, pc}
 *   @0xfe980 ldr r0, [pc, #0x18]
 *   @0xfe984 mov r1, #0
 *   @0xfe988 add r0, pc, r0
 *   @0xfe98c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe990 add sp, sp, #8
 *   @0xfe994 pop {r4, pc}
 *   @0xfe998 eoreq pc, lr, r12, asr r5
 *   @0xfe99c eoreq pc, lr, r12, asr #10
 *   @0xfe9a0 eoreq r9, r3, r4, ror r2
 *
 * ══ §153/181 F_DsGridSort(RValue&, CInstance*, CInstance*, int, RValue*)  0xfea58  size 160  40 条（0xfea58..0xfeaf8）
 * @func 0xfea58 0xfeaf8  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetBool(RValue const*, int) / F_DsGridSort(RValue&, CInstance*, CInstance*, int, RValue*)+0x80
 * 字段偏移 top8: 0x10×1 / 0x44×1 / 0x34×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfea58 push {r4, r5, r6, lr}
 *   @0xfea5c mov r1, #0
 *   @0xfea60 ldr r4, [sp, #0x10]
 *   @0xfea64 mov r0, r4
 *   @0xfea68 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfea6c mov r1, #1
 *   @0xfea70 mov r5, r0
 *   @0xfea74 mov r0, r4
 *   @0xfea78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfea7c mov r1, #2
 *   @0xfea80 mov r6, r0
 *   @0xfea84 mov r0, r4
 *   @0xfea88 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0xfea8c cmp r0, #0
 *   @0xfea90 mvneq r2, #0
 *   @0xfea94 movne r2, #1
 *   @0xfea98 cmp r5, #0
 *   @0xfea9c blt 0xfead8 <_Z12F_DsGridSortR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfeaa0 ldr r3, [pc, #0x44]
 *   @0xfeaa4 ldr r3, [pc, r3]
 *   @0xfeaa8 ldr r3, [r3]
 *   @0xfeaac cmp r5, r3
 *   @0xfeab0 bge 0xfead8 <_Z12F_DsGridSortR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfeab4 ldr r3, [pc, #0x34]
 *   @0xfeab8 ldr r3, [pc, r3]
 *   @0xfeabc ldr r3, [r3, #0x4]
 *   @0xfeac0 ldr r0, [r3, r5, lsl #2]
 *   @0xfeac4 cmp r0, #0
 *   @0xfeac8 beq 0xfead8 <_Z12F_DsGridSortR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfeacc mov r1, r6
 *   @0xfead0 pop {r4, r5, r6, lr}
 *   @0xfead4 b 0x204f6c <_ZN8CDS_Grid4SortEii>
 *   @0xfead8 ldr r0, [pc, #0x14]
 *   @0xfeadc mov r1, #0
 *   @0xfeae0 pop {r4, r5, r6, lr}
 *   @0xfeae4 add r0, pc, r0
 *   @0xfeae8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfeaec eoreq pc, lr, r0, ror #7
 *   @0xfeaf0 .word 0x002ef3d0
 *   @0xfeaf4 eoreq r9, r3, r8, lsl r1
 *
 * ══ §154/181 YYGML_ds_stack_push(int, YYRValue**)  0xffde4  size 160  40 条（0xffde4..0xffe84）
 * @func 0xffde4 0xffe84  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CDS_Stack::Push(RValue*)
 * 字段偏移 top8: 0x4×3 / 0x60×1 / 0x50×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xffde4 push {r4, r5, r6, r7, r8, lr}
 *   @0xffde8 mov r5, r1
 *   @0xffdec mov r6, r0
 *   @0xffdf0 mov r1, #0
 *   @0xffdf4 ldr r0, [r5]
 *   @0xffdf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xffdfc cmp r6, #1
 *   @0xffe00 movgt r3, #0
 *   @0xffe04 movle r3, #1
 *   @0xffe08 orrs r3, r3, r0, lsr #31
 *   @0xffe0c bne 0xffe64 <_Z19YYGML_ds_stack_pushiPP8YYRValue+0x80>
 *   @0xffe10 ldr r3, [pc, #0x60]
 *   @0xffe14 ldr r3, [pc, r3]
 *   @0xffe18 ldr r3, [r3]
 *   @0xffe1c cmp r0, r3
 *   @0xffe20 bge 0xffe64 <_Z19YYGML_ds_stack_pushiPP8YYRValue+0x80>
 *   @0xffe24 ldr r7, [pc, #0x50]
 *   @0xffe28 lsl r8, r0, #2
 *   @0xffe2c ldr r7, [pc, r7]
 *   @0xffe30 ldr r3, [r7, #0x4]
 *   @0xffe34 ldr r0, [r3, r0, lsl #2]
 *   @0xffe38 cmp r0, #0
 *   @0xffe3c movne r4, #1
 *   @0xffe40 beq 0xffe64 <_Z19YYGML_ds_stack_pushiPP8YYRValue+0x80>
 *   @0xffe44 add r4, r4, #1
 *   @0xffe48 ldr r1, [r5, #0x4]!
 *   @0xffe4c bl 0x20566c <_ZN9CDS_Stack4PushEP6RValue>
 *   @0xffe50 cmp r6, r4
 *   @0xffe54 pople {r4, r5, r6, r7, r8, pc}
 *   @0xffe58 ldr r3, [r7, #0x4]
 *   @0xffe5c ldr r0, [r3, r8]
 *   @0xffe60 b 0xffe44 <_Z19YYGML_ds_stack_pushiPP8YYRValue+0x60>
 *   @0xffe64 ldr r0, [pc, #0x14]
 *   @0xffe68 mov r1, #0
 *   @0xffe6c pop {r4, r5, r6, r7, r8, lr}
 *   @0xffe70 add r0, pc, r0
 *   @0xffe74 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xffe78 eoreq lr, lr, r8, rrx
 *   @0xffe7c eoreq lr, lr, r4, asr r0
 *   @0xffe80 eoreq r7, r3, r12, lsl #27
 *
 * ══ §155/181 F_MathSetEpsilon(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e180  size 160  40 条（0x10e180..0x10e220）
 * @func 0x10e180 0x10e220  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / F_MathSetEpsilon(RValue&, CInstance*, CInstance*, int, RValue*)+0x34
 * 字段偏移 top8: 0x20×1 / 0x54×1 / 0x4c×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e180 push {r4, r5, lr}
 *   @0x10e184 sub sp, sp, #20
 *   @0x10e188 mov r1, #0
 *   @0x10e18c ldr r0, [sp, #0x20]
 *   @0x10e190 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e194 vmov d7, r0, r1
 *   @0x10e198 vcmpe.f64 d7, #0
 *   @0x10e19c vmrs APSR_nzcv, fpscr
 *   @0x10e1a0 blt 0x10e1b4 <_Z16F_MathSetEpsilonR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x10e1a4 vmov.f64 d6, #1.000000e+00
 *   @0x10e1a8 vcmpe.f64 d7, d6
 *   @0x10e1ac vmrs APSR_nzcv, fpscr
 *   @0x10e1b0 bmi 0x10e1bc <_Z16F_MathSetEpsilonR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x10e1b4 add sp, sp, #20
 *   @0x10e1b8 pop {r4, r5, pc}
 *   @0x10e1bc ldr r2, [pc, #0x54]
 *   @0x10e1c0 vcmp.f64 d7, #0
 *   @0x10e1c4 vldr d6, [pc, #68]
 *   @0x10e1c8 ldr r3, [pc, #0x4c]
 *   @0x10e1cc ldr r2, [pc, r2]
 *   @0x10e1d0 ldr r3, [pc, r3]
 *   @0x10e1d4 ldr r2, [r2]
 *   @0x10e1d8 vmrs APSR_nzcv, fpscr
 *   @0x10e1dc vmoveq.f64 d7, d6
 *   @0x10e1e0 vstr d7, [r3]
 *   @0x10e1e4 cmp r2, #0
 *   @0x10e1e8 beq 0x10e1b4 <_Z16F_MathSetEpsilonR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x10e1ec vmov r4, r5, d7
 *   @0x10e1f0 add r1, sp, #16
 *   @0x10e1f4 mov r0, #1
 *   @0x10e1f8 strd r4, r5, [r1, #-16]!
 *   @0x10e1fc mov r1, sp
 *   @0x10e200 blx r2
 *   @0x10e204 add sp, sp, #20
 *   @0x10e208 pop {r4, r5, pc}
 *   @0x10e20c nop
 *   @0x10e210 .word 0xe1796495
 *   @0x10e214 stclo p13, c15, [r5, #508]!
 *   @0x10e218 eoreq r0, lr, r12, ror r0
 *   @0x10e21c eoreq pc, sp, r8, asr #22
 *
 * ══ §156/181 F_VariableGlobalGet(RValue&, CInstance*, CInstance*, int, RValue*)  0x114db0  size 160  40 条（0x114db0..0x114e50）
 * @func 0x114db0 0x114e50  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / Variable_BuiltIn_Find(char const*) / F_VariableGlobalGet(RValue&, CInstance*, CInstance*, int, RValue*)+0x70 / Code_Variable_Find_Slot_From_Name(YYObjectBase*, char const*)
 * 字段偏移 top8: 0x10×1 / 0x7c×1 / 0x64×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x114db0 push {r4, r5, r6, lr}
 *   @0x114db4 mov r1, #0
 *   @0x114db8 mov r4, r0
 *   @0x114dbc ldr r0, [sp, #0x10]
 *   @0x114dc0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x114dc4 ldr r12, [pc, #0x7c]
 *   @0x114dc8 ldr r12, [pc, r12]
 *   @0x114dcc ldr r5, [r12]
 *   @0x114dd0 mov r6, r0
 *   @0x114dd4 bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc>
 *   @0x114dd8 subs r1, r0, #0
 *   @0x114ddc blt 0x114e20 <_Z19F_VariableGlobalGetR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x114de0 ldr r12, [pc, #0x64]
 *   @0x114de4 ldr r12, [pc, r12]
 *   @0x114de8 ldr r3, [r12]
 *   @0x114dec cmp r1, r3
 *   @0x114df0 bge 0x114e0c <_Z19F_VariableGlobalGetR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x114df4 mov r3, #0
 *   @0x114df8 mov r2, #5
 *   @0x114dfc str r3, [r4, #0x8]
 *   @0x114e00 str r2, [r4, #0xc]
 *   @0x114e04 str r3, [r4]
 *   @0x114e08 pop {r4, r5, r6, pc}
 *   @0x114e0c mov r0, r5
 *   @0x114e10 mov r3, r4
 *   @0x114e14 mov r2, #-2147483648
 *   @0x114e18 pop {r4, r5, r6, lr}
 *   @0x114e1c b 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue>
 *   @0x114e20 mov r1, r6
 *   @0x114e24 mov r0, r5
 *   @0x114e28 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc>
 *   @0x114e2c mov r2, r4
 *   @0x114e30 mov r1, #-2147483648
 *   @0x114e34 pop {r4, r5, r6, lr}
 *   @0x114e38 cmp r0, #0
 *   @0x114e3c addge r0, r0, #99328
 *   @0x114e40 addge r0, r0, #672
 *   @0x114e44 b 0x1f3984 <_Z22Variable_Global_GetVariiP6RValue>
 *   @0x114e48 eoreq r8, sp, r12, ror #27
 *   @0x114e4c eoreq r9, sp, r4, asr #12
 *
 * ══ §157/181 F_DrawLineWidthExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b4bc  size 160  40 条（0x11b4bc..0x11b55c）
 * @func 0x11b4bc 0x11b55c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetInt32(RValue const*, int)×2 / GR_Draw_Line_Width_Ext(float, float, float, float, float, unsigned int, unsigned int)
 * 字段偏移 top8: 0x30×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b4bc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11b4c0 sub sp, sp, #16
 *   @0x11b4c4 mov r1, #0
 *   @0x11b4c8 ldr r4, [sp, #0x30]
 *   @0x11b4cc mov r0, r4
 *   @0x11b4d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b4d4 mov r1, #1
 *   @0x11b4d8 mov r5, r0
 *   @0x11b4dc mov r0, r4
 *   @0x11b4e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b4e4 mov r1, #2
 *   @0x11b4e8 mov r8, r0
 *   @0x11b4ec mov r0, r4
 *   @0x11b4f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b4f4 mov r1, #3
 *   @0x11b4f8 mov r7, r0
 *   @0x11b4fc mov r0, r4
 *   @0x11b500 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b504 mov r1, #4
 *   @0x11b508 mov r6, r0
 *   @0x11b50c mov r0, r4
 *   @0x11b510 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b514 mov r1, #5
 *   @0x11b518 mov r10, r0
 *   @0x11b51c mov r0, r4
 *   @0x11b520 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b524 mov r1, #6
 *   @0x11b528 mov r9, r0
 *   @0x11b52c mov r0, r4
 *   @0x11b530 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b534 str r10, [sp]
 *   @0x11b538 str r9, [sp, #0x4]
 *   @0x11b53c mov r1, r8
 *   @0x11b540 mov r2, r7
 *   @0x11b544 mov r3, r6
 *   @0x11b548 str r0, [sp, #0x8]
 *   @0x11b54c mov r0, r5
 *   @0x11b550 bl 0x16a550 <_Z22GR_Draw_Line_Width_Extfffffjj>
 *   @0x11b554 add sp, sp, #16
 *   @0x11b558 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §158/181 F_DrawEllipseExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b920  size 160  40 条（0x11b920..0x11b9c0）
 * @func 0x11b920 0x11b9c0  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / YYGetBool(RValue const*, int) / GR_Draw_Ellipse_Ext(float, float, float, float, unsigned int, unsigned int, bool)
 * 字段偏移 top8: 0x30×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b920 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11b924 sub sp, sp, #16
 *   @0x11b928 mov r1, #0
 *   @0x11b92c ldr r4, [sp, #0x30]
 *   @0x11b930 mov r0, r4
 *   @0x11b934 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b938 mov r1, #1
 *   @0x11b93c mov r5, r0
 *   @0x11b940 mov r0, r4
 *   @0x11b944 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b948 mov r1, #2
 *   @0x11b94c mov r8, r0
 *   @0x11b950 mov r0, r4
 *   @0x11b954 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b958 mov r1, #3
 *   @0x11b95c mov r7, r0
 *   @0x11b960 mov r0, r4
 *   @0x11b964 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b968 mov r1, #4
 *   @0x11b96c mov r6, r0
 *   @0x11b970 mov r0, r4
 *   @0x11b974 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b978 mov r1, #5
 *   @0x11b97c mov r10, r0
 *   @0x11b980 mov r0, r4
 *   @0x11b984 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b988 mov r1, #6
 *   @0x11b98c mov r9, r0
 *   @0x11b990 mov r0, r4
 *   @0x11b994 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11b998 str r10, [sp]
 *   @0x11b99c str r9, [sp, #0x4]
 *   @0x11b9a0 mov r1, r8
 *   @0x11b9a4 mov r2, r7
 *   @0x11b9a8 mov r3, r6
 *   @0x11b9ac str r0, [sp, #0x8]
 *   @0x11b9b0 mov r0, r5
 *   @0x11b9b4 bl 0x16b2ac <_Z19GR_Draw_Ellipse_Extffffjjb>
 *   @0x11b9b8 add sp, sp, #16
 *   @0x11b9bc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §159/181 F_ShowText(RValue&, CInstance*, CInstance*, int, RValue*)  0x12659c  size 160  40 条（0x12659c..0x12663c）
 * @func 0x12659c 0x12663c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetBool(RValue const*, int) / YYGetString(RValue const*, int) / Splash_Show_Text(char const*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x74×2 / 0x10×1 / 0x50×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12659c push {r3, r4, r5, lr}
 *   @0x1265a0 mov r1, #1
 *   @0x1265a4 ldr r4, [sp, #0x10]
 *   @0x1265a8 mov r0, r4
 *   @0x1265ac bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1265b0 ldr r2, [pc, #0x74]
 *   @0x1265b4 ldr r3, [pc, #0x74]
 *   @0x1265b8 mov r1, #2
 *   @0x1265bc ldr r2, [pc, r2]
 *   @0x1265c0 ldr r3, [pc, r3]
 *   @0x1265c4 mov r12, r0
 *   @0x1265c8 mov r0, r4
 *   @0x1265cc eor lr, r12, #1
 *   @0x1265d0 strb r12, [r2]
 *   @0x1265d4 strb lr, [r3]
 *   @0x1265d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1265dc ldr r3, [pc, #0x50]
 *   @0x1265e0 mov r1, #0
 *   @0x1265e4 ldr r3, [pc, r3]
 *   @0x1265e8 str r0, [r3]
 *   @0x1265ec mov r0, r4
 *   @0x1265f0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1265f4 mov r1, #3
 *   @0x1265f8 mov r5, r0
 *   @0x1265fc mov r0, r4
 *   @0x126600 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x126604 mov r1, r0
 *   @0x126608 mov r0, r5
 *   @0x12660c bl 0x1dc784 <_Z16Splash_Show_TextPKci>
 *   @0x126610 subs r1, r0, #0
 *   @0x126614 bne 0x126624 <_Z10F_ShowTextR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x126618 ldr r0, [pc, #0x18]
 *   @0x12661c add r0, pc, r0
 *   @0x126620 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x126624 pop {r3, r4, r5, lr}
 *   @0x126628 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x12662c eoreq r8, r12, r8, ror r4
 *   @0x126630 eoreq r8, r12, r4, lsl #9
 *   @0x126634 eoreq r8, r12, r4, lsl #9
 *   @0x126638 eoreq r5, r1, r0, lsl #24
 *
 * ══ §160/181 F_PartTypeColorRGB(RValue&, CInstance*, CInstance*, int, RValue*)  0x12940c  size 160  40 条（0x12940c..0x1294ac）
 * @func 0x12940c 0x1294ac  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×7 / ParticleType_Color_RGB(int, int, int, int, int, int, int)
 * 字段偏移 top8: 0x30×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12940c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x129410 sub sp, sp, #16
 *   @0x129414 mov r1, #0
 *   @0x129418 ldr r4, [sp, #0x30]
 *   @0x12941c mov r0, r4
 *   @0x129420 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129424 mov r1, #1
 *   @0x129428 mov r5, r0
 *   @0x12942c mov r0, r4
 *   @0x129430 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129434 mov r1, #2
 *   @0x129438 mov r8, r0
 *   @0x12943c mov r0, r4
 *   @0x129440 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129444 mov r1, #3
 *   @0x129448 mov r7, r0
 *   @0x12944c mov r0, r4
 *   @0x129450 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129454 mov r1, #4
 *   @0x129458 mov r6, r0
 *   @0x12945c mov r0, r4
 *   @0x129460 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129464 mov r1, #5
 *   @0x129468 mov r10, r0
 *   @0x12946c mov r0, r4
 *   @0x129470 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129474 mov r1, #6
 *   @0x129478 mov r9, r0
 *   @0x12947c mov r0, r4
 *   @0x129480 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129484 str r10, [sp]
 *   @0x129488 str r9, [sp, #0x4]
 *   @0x12948c mov r1, r8
 *   @0x129490 mov r2, r7
 *   @0x129494 mov r3, r6
 *   @0x129498 str r0, [sp, #0x8]
 *   @0x12949c mov r0, r5
 *   @0x1294a0 bl 0x1a3490 <_Z22ParticleType_Color_RGBiiiiiii>
 *   @0x1294a4 add sp, sp, #16
 *   @0x1294a8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §161/181 F_PartTypeColorHSV(RValue&, CInstance*, CInstance*, int, RValue*)  0x1294ac  size 160  40 条（0x1294ac..0x12954c）
 * @func 0x1294ac 0x12954c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×7 / ParticleType_Color_HSV(int, int, int, int, int, int, int)
 * 字段偏移 top8: 0x30×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1294ac push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1294b0 sub sp, sp, #16
 *   @0x1294b4 mov r1, #0
 *   @0x1294b8 ldr r4, [sp, #0x30]
 *   @0x1294bc mov r0, r4
 *   @0x1294c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1294c4 mov r1, #1
 *   @0x1294c8 mov r5, r0
 *   @0x1294cc mov r0, r4
 *   @0x1294d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1294d4 mov r1, #2
 *   @0x1294d8 mov r8, r0
 *   @0x1294dc mov r0, r4
 *   @0x1294e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1294e4 mov r1, #3
 *   @0x1294e8 mov r7, r0
 *   @0x1294ec mov r0, r4
 *   @0x1294f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1294f4 mov r1, #4
 *   @0x1294f8 mov r6, r0
 *   @0x1294fc mov r0, r4
 *   @0x129500 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129504 mov r1, #5
 *   @0x129508 mov r10, r0
 *   @0x12950c mov r0, r4
 *   @0x129510 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129514 mov r1, #6
 *   @0x129518 mov r9, r0
 *   @0x12951c mov r0, r4
 *   @0x129520 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129524 str r10, [sp]
 *   @0x129528 str r9, [sp, #0x4]
 *   @0x12952c mov r1, r8
 *   @0x129530 mov r2, r7
 *   @0x129534 mov r3, r6
 *   @0x129538 str r0, [sp, #0x8]
 *   @0x12953c mov r0, r5
 *   @0x129540 bl 0x1a3538 <_Z22ParticleType_Color_HSViiiiiii>
 *   @0x129544 add sp, sp, #16
 *   @0x129548 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §162/181 F_ObjectGetPhysics(RValue&, CInstance*, CInstance*, int, RValue*)  0x12aef8  size 160  40 条（0x12aef8..0x12af98）
 * @func 0x12aef8 0x12af98  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×3 / 0x8×2 / 0x4×2 / 0x80×1 / 0x3×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12aef8 push {r4, lr}
 *   @0x12aefc mov r1, #0
 *   @0x12af00 mov r4, r0
 *   @0x12af04 ldr r0, [sp, #0x8]
 *   @0x12af08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12af0c ldr r3, [pc, #0x80]
 *   @0x12af10 ldr r3, [pc, r3]
 *   @0x12af14 ldr r3, [r3]
 *   @0x12af18 ldr r2, [r3, #0x4]
 *   @0x12af1c ldr r3, [r3]
 *   @0x12af20 and r2, r0, r2
 *   @0x12af24 ldr r3, [r3, r2, lsl #3]
 *   @0x12af28 cmp r3, #0
 *   @0x12af2c bne 0x12af40 <_Z18F_ObjectGetPhysicsR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12af30 b 0x12af7c <_Z18F_ObjectGetPhysicsR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x12af34 ldr r3, [r3, #0x4]
 *   @0x12af38 cmp r3, #0
 *   @0x12af3c beq 0x12af7c <_Z18F_ObjectGetPhysicsR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x12af40 ldr r2, [r3, #0x8]
 *   @0x12af44 cmp r0, r2
 *   @0x12af48 bne 0x12af34 <_Z18F_ObjectGetPhysicsR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12af4c ldr r3, [r3, #0xc]
 *   @0x12af50 cmp r3, #0
 *   @0x12af54 beq 0x12af7c <_Z18F_ObjectGetPhysicsR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x12af58 ldrb r3, [r3, #0x1c]
 *   @0x12af5c mov r2, #0
 *   @0x12af60 str r2, [r4, #0xc]
 *   @0x12af64 cmp r3, r2
 *   @0x12af68 movne r3, #0
 *   @0x12af6c movtne r3, #0x3ff0
 *   @0x12af70 beq 0x12af84 <_Z18F_ObjectGetPhysicsR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x12af74 stm r4, {r2, r3}
 *   @0x12af78 pop {r4, pc}
 *   @0x12af7c mov r3, #0
 *   @0x12af80 str r3, [r4, #0xc]
 *   @0x12af84 mov r2, #0
 *   @0x12af88 mov r3, r2
 *   @0x12af8c stm r4, {r2, r3}
 *   @0x12af90 pop {r4, pc}
 *   @0x12af94 eoreq r2, r12, r12, lsr #26
 *
 * ══ §163/181 F_BackgroundReplaceAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ca28  size 160  40 条（0x12ca28..0x12cac8）
 * @func 0x12ca28 0x12cac8  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Background_Data(int) / YYGetString(RValue const*, int) / YYGetBool(RValue const*, int) / Background_Replace_Alpha(int, char const*, bool) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ca28 push {r3, r4, r5, r6, r7, lr}
 *   @0x12ca2c mov r1, #0
 *   @0x12ca30 ldr r5, [sp, #0x18]
 *   @0x12ca34 mov r4, r0
 *   @0x12ca38 mov r0, r5
 *   @0x12ca3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ca40 mov r6, r0
 *   @0x12ca44 bl 0xc3794 <_Z15Background_Datai>
 *   @0x12ca48 subs r7, r0, #0
 *   @0x12ca4c beq 0x12caac <_Z24F_BackgroundReplaceAlphaR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x12ca50 mov r1, #1
 *   @0x12ca54 mov r0, r5
 *   @0x12ca58 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12ca5c mov r1, #2
 *   @0x12ca60 mov r7, r0
 *   @0x12ca64 mov r0, r5
 *   @0x12ca68 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12ca6c mov r1, r7
 *   @0x12ca70 mov r2, r0
 *   @0x12ca74 mov r0, r6
 *   @0x12ca78 bl 0xc3e60 <_Z24Background_Replace_AlphaiPKcb>
 *   @0x12ca7c mov r3, #0
 *   @0x12ca80 str r3, [r4, #0xc]
 *   @0x12ca84 cmp r0, r3
 *   @0x12ca88 bne 0x12caa0 <_Z24F_BackgroundReplaceAlphaR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x12ca8c mov r3, #0
 *   @0x12ca90 mov r2, r3
 *   @0x12ca94 str r3, [r4]
 *   @0x12ca98 str r2, [r4, #0x4]
 *   @0x12ca9c pop {r3, r4, r5, r6, r7, pc}
 *   @0x12caa0 mov r2, #0
 *   @0x12caa4 movt r2, #0x3ff0
 *   @0x12caa8 b 0x12ca94 <_Z24F_BackgroundReplaceAlphaR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x12caac ldr r0, [pc, #0x10]
 *   @0x12cab0 mov r1, r7
 *   @0x12cab4 add r0, pc, r0
 *   @0x12cab8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12cabc str r7, [r4, #0xc]
 *   @0x12cac0 b 0x12ca8c <_Z24F_BackgroundReplaceAlphaR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x12cac4 eoreq r0, r1, r4, lsl #20
 *
 * ══ §164/181 F_SpriteSetAlphaFromSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f200  size 160  40 条（0x12f200..0x12f2a0）
 * @func 0x12f200 0x12f2a0  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sprite_Data(int)×2
 * 字段偏移 top8: 0x10×2 / 0x74×2 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f200 push {r4, r5, r6, lr}
 *   @0x12f204 mov r1, #0
 *   @0x12f208 ldr r4, [sp, #0x10]
 *   @0x12f20c mov r0, r4
 *   @0x12f210 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f214 mov r1, #1
 *   @0x12f218 mov r5, r0
 *   @0x12f21c mov r0, r4
 *   @0x12f220 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f224 mov r6, r0
 *   @0x12f228 mov r0, r5
 *   @0x12f22c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12f230 mov r4, r0
 *   @0x12f234 mov r0, r6
 *   @0x12f238 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12f23c cmp r0, #0
 *   @0x12f240 cmpne r4, #0
 *   @0x12f244 mov r1, r0
 *   @0x12f248 popeq {r4, r5, r6, pc}
 *   @0x12f24c ldr r3, [r4, #0x74]
 *   @0x12f250 cmp r3, #0
 *   @0x12f254 bne 0x12f270 <_Z26F_SpriteSetAlphaFromSpriteR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x12f258 ldr r2, [r0, #0x74]
 *   @0x12f25c cmp r2, #0
 *   @0x12f260 bne 0x12f284 <_Z26F_SpriteSetAlphaFromSpriteR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x12f264 mov r0, r4
 *   @0x12f268 pop {r4, r5, r6, lr}
 *   @0x12f26c b 0x1e5c90 <_ZN7CSprite18SetAlphaFromSpriteEPS_>
 *   @0x12f270 ldr r0, [pc, #0x20]
 *   @0x12f274 mov r1, #0
 *   @0x12f278 pop {r4, r5, r6, lr}
 *   @0x12f27c add r0, pc, r0
 *   @0x12f280 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12f284 ldr r0, [pc, #0x10]
 *   @0x12f288 mov r1, r3
 *   @0x12f28c pop {r4, r5, r6, lr}
 *   @0x12f290 add r0, pc, r0
 *   @0x12f294 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12f298 eoreq lr, r0, r12, asr #10
 *   @0x12f29c eoreq lr, r0, r0, lsr #11
 *
 * ══ §165/181 F_SoundFade(RValue&, CInstance*, CInstance*, int, RValue*)  0x133bf0  size 160  40 条（0x133bf0..0x133c90）
 * @func 0x133bf0 0x133c90  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sound_Data(int) / CSound::GetSoundId() / YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x18×2 / 0x8c×1 / 0x74×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133bf0 ldr r3, [pc, #0x8c]
 *   @0x133bf4 push {r4, r5, r6, r7, r8, lr}
 *   @0x133bf8 ldr r3, [pc, r3]
 *   @0x133bfc ldr r6, [sp, #0x18]
 *   @0x133c00 ldrb r3, [r3]
 *   @0x133c04 cmp r3, #0
 *   @0x133c08 popne {r4, r5, r6, r7, r8, pc}
 *   @0x133c0c ldr r3, [pc, #0x74]
 *   @0x133c10 ldr r3, [pc, r3]
 *   @0x133c14 ldrb r1, [r3]
 *   @0x133c18 cmp r1, #0
 *   @0x133c1c popne {r4, r5, r6, r7, r8, pc}
 *   @0x133c20 mov r0, r6
 *   @0x133c24 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x133c28 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x133c2c subs r1, r0, #0
 *   @0x133c30 beq 0x133c74 <_Z11F_SoundFadeR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x133c34 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x133c38 mov r1, #1
 *   @0x133c3c mov r7, r0
 *   @0x133c40 mov r0, r6
 *   @0x133c44 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x133c48 mov r4, r0
 *   @0x133c4c mov r5, r1
 *   @0x133c50 mov r0, r6
 *   @0x133c54 mov r1, #2
 *   @0x133c58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x133c5c mov r2, r4
 *   @0x133c60 mov r3, r5
 *   @0x133c64 str r0, [sp, #0x18]
 *   @0x133c68 mov r0, r7
 *   @0x133c6c pop {r4, r5, r6, r7, r8, lr}
 *   @0x133c70 b 0x21f07c <_Z14SND_Set_Volumeidi>
 *   @0x133c74 ldr r0, [pc, #0x10]
 *   @0x133c78 pop {r4, r5, r6, r7, r8, lr}
 *   @0x133c7c add r0, pc, r0
 *   @0x133c80 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x133c84 eoreq r11, r11, r8, lsr r1
 *   @0x133c88 eoreq r11, r11, r12, lsr r4
 *   @0x133c8c eoreq r11, r0, r0, lsl r8
 *
 * ══ §166/181 YYGML_sound_play(int)  0x1365f0  size 160  40 条（0x1365f0..0x136690）
 * @func 0x1365f0 0x136690  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSound::GetSoundId()×2 / Sound_Data(int) / SND_Play(char const*, int, bool) / SND_Set_Volume(int, double, int)
 * 字段偏移 top8: 0x8c×1 / 0x74×1 / 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1365f0 ldr r3, [pc, #0x8c]
 *   @0x1365f4 push {r4, r5, r6, lr}
 *   @0x1365f8 ldr r3, [pc, r3]
 *   @0x1365fc sub sp, sp, #8
 *   @0x136600 ldrb r3, [r3]
 *   @0x136604 cmp r3, #0
 *   @0x136608 bne 0x136620 <_Z16YYGML_sound_playi+0x30>
 *   @0x13660c ldr r3, [pc, #0x74]
 *   @0x136610 ldr r3, [pc, r3]
 *   @0x136614 ldrb r4, [r3]
 *   @0x136618 cmp r4, #0
 *   @0x13661c beq 0x136628 <_Z16YYGML_sound_playi+0x38>
 *   @0x136620 add sp, sp, #8
 *   @0x136624 pop {r4, r5, r6, pc}
 *   @0x136628 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x13662c subs r5, r0, #0
 *   @0x136630 beq 0x13666c <_Z16YYGML_sound_playi+0x7c>
 *   @0x136634 ldr r6, [r5, #0xc]
 *   @0x136638 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x13663c mov r2, r4
 *   @0x136640 mov r1, r0
 *   @0x136644 mov r0, r6
 *   @0x136648 bl 0x21eb7c <_Z8SND_PlayPKcib>
 *   @0x13664c mov r0, r5
 *   @0x136650 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x136654 ldrd r2, r3, [r5, #32]
 *   @0x136658 mov r1, #1
 *   @0x13665c str r1, [sp]
 *   @0x136660 bl 0x21f07c <_Z14SND_Set_Volumeidi>
 *   @0x136664 add sp, sp, #8
 *   @0x136668 pop {r4, r5, r6, pc}
 *   @0x13666c ldr r0, [pc, #0x18]
 *   @0x136670 mov r1, r5
 *   @0x136674 add r0, pc, r0
 *   @0x136678 add sp, sp, #8
 *   @0x13667c pop {r4, r5, r6, lr}
 *   @0x136680 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x136684 eoreq r8, r11, r8, lsr r7
 *   @0x136688 eoreq r8, r11, r12, lsr r10
 *   @0x13668c eoreq r8, r0, r8, lsl lr
 *
 * ══ §167/181 YYGML_ini_write_real(char const*, char const*, double)  0x13bc00  size 160  40 条（0x13bc00..0x13bca0）
 * @func 0x13bc00 0x13bca0  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65c8 / IniFile::SetKey(char const*, char const*, char const*) / Error_Show_Action(char const*, bool) / 0xb65d4
 * 字段偏移 top8: 0x10c×2 / 0x80×1 / 0x7c×1 / 0x54×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13bc00 push {r4, r5, r6, r7, r8, lr}
 *   @0x13bc04 mov r7, r1
 *   @0x13bc08 ldr r5, [pc, #0x80]
 *   @0x13bc0c sub sp, sp, #272
 *   @0x13bc10 ldr r4, [pc, #0x7c]
 *   @0x13bc14 mov r8, r0
 *   @0x13bc18 ldr r5, [pc, r5]
 *   @0x13bc1c ldr r4, [pc, r4]
 *   @0x13bc20 ldr r1, [r5]
 *   @0x13bc24 ldr lr, [r4]
 *   @0x13bc28 cmp r1, #0
 *   @0x13bc2c str lr, [sp, #0x10c]
 *   @0x13bc30 beq 0x13bc7c <_Z20YYGML_ini_write_realPKcS0_d+0x7c>
 *   @0x13bc34 strd r2, r3, [sp]
 *   @0x13bc38 add r6, sp, #12
 *   @0x13bc3c ldr r2, [pc, #0x54]
 *   @0x13bc40 mov r1, #256
 *   @0x13bc44 mov r0, r6
 *   @0x13bc48 add r2, pc, r2
 *   @0x13bc4c bl 0xb65c8 <snprintf@plt>
 *   @0x13bc50 mov r3, r6
 *   @0x13bc54 ldr r0, [r5]
 *   @0x13bc58 mov r1, r8
 *   @0x13bc5c mov r2, r7
 *   @0x13bc60 bl 0x235edc <_ZN7IniFile6SetKeyEPKcS1_S1_>
 *   @0x13bc64 ldr r2, [sp, #0x10c]
 *   @0x13bc68 ldr r3, [r4]
 *   @0x13bc6c cmp r2, r3
 *   @0x13bc70 bne 0x13bc8c <_Z20YYGML_ini_write_realPKcS0_d+0x8c>
 *   @0x13bc74 add sp, sp, #272
 *   @0x13bc78 pop {r4, r5, r6, r7, r8, pc}
 *   @0x13bc7c ldr r0, [pc, #0x18]
 *   @0x13bc80 add r0, pc, r0
 *   @0x13bc84 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13bc88 b 0x13bc64 <_Z20YYGML_ini_write_realPKcS0_d+0x64>
 *   @0x13bc8c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13bc90 eoreq r3, r11, r12, ror r6
 *   @0x13bc94 eoreq r1, r11, r4, lsr sp
 *   @0x13bc98 eoreq r4, r0, r12, ror #14
 *   @0x13bc9c eoreq r4, r0, r8, ror #11
 *
 * ══ §168/181 F_D3DVertexTextureColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x143db4  size 160  40 条（0x143db4..0x143e54）
 * @func 0x143db4 0x143e54  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / YYGetInt32(RValue const*, int) / GR_3D_Vertex_Texture_Color(float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x30×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143db4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x143db8 sub sp, sp, #16
 *   @0x143dbc mov r1, #0
 *   @0x143dc0 ldr r4, [sp, #0x30]
 *   @0x143dc4 mov r0, r4
 *   @0x143dc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143dcc mov r1, #1
 *   @0x143dd0 mov r5, r0
 *   @0x143dd4 mov r0, r4
 *   @0x143dd8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143ddc mov r1, #2
 *   @0x143de0 mov r8, r0
 *   @0x143de4 mov r0, r4
 *   @0x143de8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143dec mov r1, #3
 *   @0x143df0 mov r7, r0
 *   @0x143df4 mov r0, r4
 *   @0x143df8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143dfc mov r1, #4
 *   @0x143e00 mov r6, r0
 *   @0x143e04 mov r0, r4
 *   @0x143e08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143e0c mov r1, #5
 *   @0x143e10 mov r10, r0
 *   @0x143e14 mov r0, r4
 *   @0x143e18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x143e1c mov r1, #6
 *   @0x143e20 mov r9, r0
 *   @0x143e24 mov r0, r4
 *   @0x143e28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143e2c str r10, [sp]
 *   @0x143e30 str r9, [sp, #0x4]
 *   @0x143e34 mov r1, r8
 *   @0x143e38 mov r2, r7
 *   @0x143e3c mov r3, r6
 *   @0x143e40 str r0, [sp, #0x8]
 *   @0x143e44 mov r0, r5
 *   @0x143e48 bl 0x1770c8 <_Z26GR_3D_Vertex_Texture_Colorfffffjf>
 *   @0x143e4c add sp, sp, #16
 *   @0x143e50 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §169/181 F_D3DModelVertexNormal(RValue&, CInstance*, CInstance*, int, RValue*)  0x145724  size 160  40 条（0x145724..0x1457c4）
 * @func 0x145724 0x1457c4  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / YYGetInt32(RValue const*, int) / GR_3DM_Vertex_N(int, float, float, float, float, float, float)
 * 字段偏移 top8: 0x30×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145724 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x145728 sub sp, sp, #16
 *   @0x14572c mov r1, #0
 *   @0x145730 ldr r4, [sp, #0x30]
 *   @0x145734 mov r0, r4
 *   @0x145738 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14573c mov r1, #1
 *   @0x145740 mov r5, r0
 *   @0x145744 mov r0, r4
 *   @0x145748 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14574c mov r1, #2
 *   @0x145750 mov r8, r0
 *   @0x145754 mov r0, r4
 *   @0x145758 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14575c mov r1, #3
 *   @0x145760 mov r7, r0
 *   @0x145764 mov r0, r4
 *   @0x145768 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14576c mov r1, #4
 *   @0x145770 mov r6, r0
 *   @0x145774 mov r0, r4
 *   @0x145778 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14577c mov r1, #5
 *   @0x145780 mov r10, r0
 *   @0x145784 mov r0, r4
 *   @0x145788 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14578c mov r1, #6
 *   @0x145790 mov r9, r0
 *   @0x145794 mov r0, r4
 *   @0x145798 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14579c str r10, [sp]
 *   @0x1457a0 str r9, [sp, #0x4]
 *   @0x1457a4 mov r1, r8
 *   @0x1457a8 mov r2, r7
 *   @0x1457ac mov r3, r6
 *   @0x1457b0 str r0, [sp, #0x8]
 *   @0x1457b4 mov r0, r5
 *   @0x1457b8 bl 0x165674 <_Z15GR_3DM_Vertex_Niffffff>
 *   @0x1457bc add sp, sp, #16
 *   @0x1457c0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §170/181 GR_3D_TransformVertex(float&, float&, float&)  0x163c3c  size 160  40 条（0x163c3c..0x163cdc）
 * @func 0x163c3c 0x163cdc  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::GetMatrix(eMatrix, float*)
 * 字段偏移 top8: 无
 * VFP 指令 30 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163c3c push {r4, r5, r6, lr}
 *   @0x163c40 sub sp, sp, #64
 *   @0x163c44 mov r5, r0
 *   @0x163c48 mov r4, r1
 *   @0x163c4c mov r0, #2
 *   @0x163c50 mov r1, sp
 *   @0x163c54 mov r6, r2
 *   @0x163c58 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x163c5c vldr s10, [r4]
 *   @0x163c60 vldr s13, [sp, #16]
 *   @0x163c64 vldr s14, [sp, #20]
 *   @0x163c68 vldr s15, [sp, #24]
 *   @0x163c6c vmul.f32 s13, s10, s13
 *   @0x163c70 vldr s11, [r5]
 *   @0x163c74 vldr s1, [sp]
 *   @0x163c78 vldr s2, [sp, #4]
 *   @0x163c7c vldr s3, [sp, #8]
 *   @0x163c80 vldr s12, [r6]
 *   @0x163c84 vldr s4, [sp, #32]
 *   @0x163c88 vldr s5, [sp, #36]
 *   @0x163c8c vldr s6, [sp, #40]
 *   @0x163c90 vldr s7, [sp, #48]
 *   @0x163c94 vldr s8, [sp, #52]
 *   @0x163c98 vldr s9, [sp, #56]
 *   @0x163c9c vmul.f32 s14, s10, s14
 *   @0x163ca0 vmul.f32 s15, s10, s15
 *   @0x163ca4 vmla.f32 s13, s11, s1
 *   @0x163ca8 vmla.f32 s14, s11, s2
 *   @0x163cac vmla.f32 s15, s11, s3
 *   @0x163cb0 vmla.f32 s13, s12, s4
 *   @0x163cb4 vmla.f32 s14, s12, s5
 *   @0x163cb8 vmla.f32 s15, s12, s6
 *   @0x163cbc vadd.f32 s13, s13, s7
 *   @0x163cc0 vadd.f32 s14, s14, s8
 *   @0x163cc4 vstr s13, [r5]
 *   @0x163cc8 vadd.f32 s15, s15, s9
 *   @0x163ccc vstr s14, [r4]
 *   @0x163cd0 vstr s15, [r6]
 *   @0x163cd4 add sp, sp, #64
 *   @0x163cd8 pop {r4, r5, r6, pc}
 *
 * ══ §171/181 GraphicsPerf::printf(float, float, unsigned int, char const*, ...)  0x17c258  size 160  40 条（0x17c258..0x17c2f8）
 * @func 0x17c258 0x17c2f8  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb667c / GraphicsPerf::Print(float, float, float, float, unsigned int, char*, int) / 0xb65d4
 * 字段偏移 top8: 0x814×2 / 0x-4×1 / 0x88×1 / 0x834×1 / 0x10×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17c258 str r3, [sp, #-0x4]!
 *   @0x17c25c push {r4, r5, r6, r7, r8, lr}
 *   @0x17c260 sub sp, sp, #2064
 *   @0x17c264 ldr r4, [pc, #0x88]
 *   @0x17c268 sub sp, sp, #12
 *   @0x17c26c add r3, sp, #2096
 *   @0x17c270 add r5, sp, #20
 *   @0x17c274 ldr r4, [pc, r4]
 *   @0x17c278 ldr lr, [sp, #0x834]
 *   @0x17c27c add r3, r3, #8
 *   @0x17c280 mov r7, r0
 *   @0x17c284 ldr r12, [r4]
 *   @0x17c288 mov r8, r2
 *   @0x17c28c mov r6, r1
 *   @0x17c290 mov r2, r3
 *   @0x17c294 mov r1, lr
 *   @0x17c298 mov r0, r5
 *   @0x17c29c str r3, [sp, #0x10]
 *   @0x17c2a0 str r12, [sp, #0x814]
 *   @0x17c2a4 bl 0xb667c <vsprintf@plt>
 *   @0x17c2a8 mov r2, #1065353216
 *   @0x17c2ac mvn r12, #-2147483648
 *   @0x17c2b0 mov r3, r2
 *   @0x17c2b4 str r8, [sp]
 *   @0x17c2b8 str r5, [sp, #0x4]
 *   @0x17c2bc mov r0, r7
 *   @0x17c2c0 mov r1, r6
 *   @0x17c2c4 str r12, [sp, #0x8]
 *   @0x17c2c8 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17c2cc ldr r2, [sp, #0x814]
 *   @0x17c2d0 ldr r3, [r4]
 *   @0x17c2d4 cmp r2, r3
 *   @0x17c2d8 bne 0x17c2f0 <_ZN12GraphicsPerf6printfEffjPKcz+0x98>
 *   @0x17c2dc add sp, sp, #2064
 *   @0x17c2e0 add sp, sp, #12
 *   @0x17c2e4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x17c2e8 add sp, sp, #4
 *   @0x17c2ec bx lr
 *   @0x17c2f0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x17c2f4 .word 0x002716dc
 *
 * ══ §172/181 Graphics::SceneEnd()  0x17de74  size 160  40 条（0x17de74..0x17df14）
 * @func 0x17de74 0x17df14  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17de7c→0x4a2138, 0x17de98→0x4a22b1, 0x17deb4→0x3f26dc, 0x17ded4→0x4a2f20, 0x17dedc→0x479ac0
 * 调用序列: GraphicsPerf::EndFrame() / Graphics::Flush() / Graphics::ResetVBuffers()
 * 字段偏移 top8: 0x7c×2 / 0x64×1 / 0x4c×1 / 0x30×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17de74 push {r3, r4, r5, lr}
 *   @0x17de78 ldr r4, [pc, #0x7c]
 *   @0x17de7c ldr r3, [pc, #0x7c]
 *   @0x17de80 add r4, pc, r4
 *   @0x17de84 ldr r5, [r4, r3]
 *   @0x17de88 ldr r3, [r5]
 *   @0x17de8c cmp r3, #0
 *   @0x17de90 popeq {r3, r4, r5, pc}
 *   @0x17de94 bl 0x17c7e8 <_ZN12GraphicsPerf8EndFrameEv>
 *   @0x17de98 ldr r3, [pc, #0x64]
 *   @0x17de9c ldr r3, [r4, r3]
 *   @0x17dea0 ldrb r3, [r3]
 *   @0x17dea4 cmp r3, #0
 *   @0x17dea8 popeq {r3, r4, r5, pc}
 *   @0x17deac bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17deb0 bl 0x1851b8 <_ZN8Graphics13ResetVBuffersEv>
 *   @0x17deb4 ldr r3, [pc, #0x4c]
 *   @0x17deb8 ldr r3, [r4, r3]
 *   @0x17debc ldr r3, [r3]
 *   @0x17dec0 cmp r3, #1
 *   @0x17dec4 beq 0x17ded4 <_ZN8Graphics8SceneEndEv+0x60>
 *   @0x17dec8 mov r3, #0
 *   @0x17decc str r3, [r5]
 *   @0x17ded0 pop {r3, r4, r5, pc}
 *   @0x17ded4 ldr r2, [pc, #0x30]
 *   @0x17ded8 mov r1, #0
 *   @0x17dedc ldr r3, [pc, #0x2c]
 *   @0x17dee0 movw r0, #0x84c0
 *   @0x17dee4 ldr r2, [r4, r2]
 *   @0x17dee8 str r1, [r2]
 *   @0x17deec ldr r3, [r4, r3]
 *   @0x17def0 ldr r3, [r3]
 *   @0x17def4 blx r3
 *   @0x17def8 b 0x17dec8 <_ZN8Graphics8SceneEndEv+0x54>
 *   @0x17defc .word 0x00273dd0
 *   @0x17df00 .word 0xffffe7f4
 *   @0x17df04 .word 0xffffe4d0
 *   @0x17df08 .word 0xffffe7b8
 *   @0x17df0c .word 0xffffe808
 *   @0x17df10 .word 0xffffbbf0
 *
 * ══ §173/181 F_LayerExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x1baf88  size 160  40 条（0x1baf88..0x1bb028）
 * @func 0x1baf88 0x1bb028  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1baf88 cmp r3, #1
 *   @0x1baf8c push {r3, r4, r5, r6, r7, lr}
 *   @0x1baf90 mov r4, #0
 *   @0x1baf94 mov r5, r0
 *   @0x1baf98 ldr r6, [sp, #0x18]
 *   @0x1baf9c str r4, [r0, #0xc]
 *   @0x1bafa0 str r4, [r0]
 *   @0x1bafa4 str r4, [r0, #0x4]
 *   @0x1bafa8 beq 0x1bafc0 <_Z13F_LayerExistsR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1bafac ldr r0, [pc, #0x70]
 *   @0x1bafb0 mov r1, r4
 *   @0x1bafb4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bafb8 add r0, pc, r0
 *   @0x1bafbc b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bafc0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bafc4 ldr r3, [r6, #0xc]
 *   @0x1bafc8 mov r1, r4
 *   @0x1bafcc bic r3, r3, #-16777216
 *   @0x1bafd0 cmp r3, #1
 *   @0x1bafd4 mov r7, r0
 *   @0x1bafd8 mov r0, r6
 *   @0x1bafdc beq 0x1bb010 <_Z13F_LayerExistsR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1bafe0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bafe4 mov r1, r0
 *   @0x1bafe8 mov r0, r7
 *   @0x1bafec bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1baff0 cmp r0, #0
 *   @0x1baff4 streq r0, [r5]
 *   @0x1baff8 streq r0, [r5, #0x4]
 *   @0x1baffc movne r3, #0
 *   @0x1bb000 movne r2, r3
 *   @0x1bb004 movtne r3, #0x3ff0
 *   @0x1bb008 stmne r5, {r2, r3}
 *   @0x1bb00c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb010 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb014 mov r1, r0
 *   @0x1bb018 mov r0, r7
 *   @0x1bb01c bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb020 b 0x1baff0 <_Z13F_LayerExistsR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x1bb024 andseq r2, r9, r8, lsr #20
 *
 * ══ §174/181 F_LayerBackgroundGetSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bcac4  size 160  40 条（0x1bcac4..0x1bcb64）
 * @func 0x1bcac4 0x1bcb64  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x68×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bcac4 cmp r3, #1
 *   @0x1bcac8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bcacc mov r3, #0
 *   @0x1bcad0 mov r4, r3
 *   @0x1bcad4 mov r5, r0
 *   @0x1bcad8 movt r3, #0xbff0
 *   @0x1bcadc str r4, [r0, #0xc]
 *   @0x1bcae0 str r3, [r0, #0x4]
 *   @0x1bcae4 str r4, [r0]
 *   @0x1bcae8 ldr r6, [sp, #0x18]
 *   @0x1bcaec beq 0x1bcb04 <_Z26F_LayerBackgroundGetSpriteR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bcaf0 ldr r0, [pc, #0x68]
 *   @0x1bcaf4 mov r1, r4
 *   @0x1bcaf8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bcafc add r0, pc, r0
 *   @0x1bcb00 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bcb04 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bcb08 mov r1, r4
 *   @0x1bcb0c mov r7, r0
 *   @0x1bcb10 mov r0, r6
 *   @0x1bcb14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bcb18 mov r2, r4
 *   @0x1bcb1c mov r1, r0
 *   @0x1bcb20 mov r0, r7
 *   @0x1bcb24 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bcb28 cmp r0, #0
 *   @0x1bcb2c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcb30 ldr r3, [r0]
 *   @0x1bcb34 cmp r3, #1
 *   @0x1bcb38 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bcb3c ldr r3, [r0, #0x1c]
 *   @0x1bcb40 cmp r3, #0
 *   @0x1bcb44 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcb48 ldr r2, [r3, #0x4]
 *   @0x1bcb4c vmov s15, r2
 *   @0x1bcb50 vcvt.f64.s32 d7, s15
 *   @0x1bcb54 vmov r2, r3, d7
 *   @0x1bcb58 stm r5, {r2, r3}
 *   @0x1bcb5c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bcb60 ldrsheq r1, [r9], -r12
 *
 * ══ §175/181 F_LayerSpriteGetXScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd874  size 160  40 条（0x1bd874..0x1bd914）
 * @func 0x1bd874 0x1bd914  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x68×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd874 cmp r3, #1
 *   @0x1bd878 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bd87c mov r3, #0
 *   @0x1bd880 mov r5, r3
 *   @0x1bd884 mov r4, r0
 *   @0x1bd888 movt r3, #0xbff0
 *   @0x1bd88c str r5, [r0, #0xc]
 *   @0x1bd890 str r3, [r0, #0x4]
 *   @0x1bd894 str r5, [r0]
 *   @0x1bd898 ldr r6, [sp, #0x18]
 *   @0x1bd89c beq 0x1bd8b4 <_Z22F_LayerSpriteGetXScaleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bd8a0 ldr r0, [pc, #0x68]
 *   @0x1bd8a4 mov r1, r5
 *   @0x1bd8a8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bd8ac add r0, pc, r0
 *   @0x1bd8b0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd8b4 str r5, [r0]
 *   @0x1bd8b8 mov r3, #0
 *   @0x1bd8bc movt r3, #0x3ff0
 *   @0x1bd8c0 str r3, [r0, #0x4]
 *   @0x1bd8c4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd8c8 mov r1, r5
 *   @0x1bd8cc mov r7, r0
 *   @0x1bd8d0 mov r0, r6
 *   @0x1bd8d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd8d8 mov r2, r5
 *   @0x1bd8dc mov r1, r0
 *   @0x1bd8e0 mov r0, r7
 *   @0x1bd8e4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd8e8 cmp r0, #0
 *   @0x1bd8ec popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bd8f0 ldr r3, [r0]
 *   @0x1bd8f4 cmp r3, #4
 *   @0x1bd8f8 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bd8fc vldr s15, [r0, #44]
 *   @0x1bd900 vcvt.f64.f32 d6, s15
 *   @0x1bd904 vmov r2, r3, d6
 *   @0x1bd908 stm r4, {r2, r3}
 *   @0x1bd90c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bd910 andseq r0, r9, r12, asr #26
 *
 * ══ §176/181 F_LayerSpriteGetYScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd914  size 160  40 条（0x1bd914..0x1bd9b4）
 * @func 0x1bd914 0x1bd9b4  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x68×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd914 cmp r3, #1
 *   @0x1bd918 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bd91c mov r3, #0
 *   @0x1bd920 mov r5, r3
 *   @0x1bd924 mov r4, r0
 *   @0x1bd928 movt r3, #0xbff0
 *   @0x1bd92c str r5, [r0, #0xc]
 *   @0x1bd930 str r3, [r0, #0x4]
 *   @0x1bd934 str r5, [r0]
 *   @0x1bd938 ldr r6, [sp, #0x18]
 *   @0x1bd93c beq 0x1bd954 <_Z22F_LayerSpriteGetYScaleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bd940 ldr r0, [pc, #0x68]
 *   @0x1bd944 mov r1, r5
 *   @0x1bd948 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bd94c add r0, pc, r0
 *   @0x1bd950 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd954 str r5, [r0]
 *   @0x1bd958 mov r3, #0
 *   @0x1bd95c movt r3, #0x3ff0
 *   @0x1bd960 str r3, [r0, #0x4]
 *   @0x1bd964 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd968 mov r1, r5
 *   @0x1bd96c mov r7, r0
 *   @0x1bd970 mov r0, r6
 *   @0x1bd974 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd978 mov r2, r5
 *   @0x1bd97c mov r1, r0
 *   @0x1bd980 mov r0, r7
 *   @0x1bd984 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd988 cmp r0, #0
 *   @0x1bd98c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bd990 ldr r3, [r0]
 *   @0x1bd994 cmp r3, #4
 *   @0x1bd998 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bd99c vldr s15, [r0, #48]
 *   @0x1bd9a0 vcvt.f64.f32 d6, s15
 *   @0x1bd9a4 vmov r2, r3, d6
 *   @0x1bd9a8 stm r4, {r2, r3}
 *   @0x1bd9ac pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bd9b0 andseq r0, r9, r4, ror #25
 *
 * ══ §177/181 F_LayerTileVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf894  size 160  40 条（0x1bf894..0x1bf934）
 * @func 0x1bf894 0x1bf934  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x6c×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf894 cmp r3, #2
 *   @0x1bf898 mov r3, #0
 *   @0x1bf89c push {r4, r5, r6, lr}
 *   @0x1bf8a0 mov r4, r3
 *   @0x1bf8a4 ldr r5, [sp, #0x10]
 *   @0x1bf8a8 movt r3, #0xbff0
 *   @0x1bf8ac str r4, [r0, #0xc]
 *   @0x1bf8b0 str r3, [r0, #0x4]
 *   @0x1bf8b4 str r4, [r0]
 *   @0x1bf8b8 beq 0x1bf8d0 <_Z18F_LayerTileVisibleR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bf8bc ldr r0, [pc, #0x6c]
 *   @0x1bf8c0 mov r1, r4
 *   @0x1bf8c4 pop {r4, r5, r6, lr}
 *   @0x1bf8c8 add r0, pc, r0
 *   @0x1bf8cc b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf8d0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf8d4 mov r1, r4
 *   @0x1bf8d8 mov r6, r0
 *   @0x1bf8dc mov r0, r5
 *   @0x1bf8e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf8e4 mov r2, r4
 *   @0x1bf8e8 mov r1, r0
 *   @0x1bf8ec mov r0, r6
 *   @0x1bf8f0 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf8f4 subs r4, r0, #0
 *   @0x1bf8f8 popeq {r4, r5, r6, pc}
 *   @0x1bf8fc ldr r3, [r4]
 *   @0x1bf900 cmp r3, #7
 *   @0x1bf904 popne {r4, r5, r6, pc}
 *   @0x1bf908 mov r0, r5
 *   @0x1bf90c mov r1, #1
 *   @0x1bf910 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bf914 vmov s15, r0
 *   @0x1bf918 vcmp.f32 s15, #0
 *   @0x1bf91c vmrs APSR_nzcv, fpscr
 *   @0x1bf920 moveq r3, #0
 *   @0x1bf924 movne r3, #1
 *   @0x1bf928 strb r3, [r4, #0x1c]
 *   @0x1bf92c pop {r4, r5, r6, pc}
 *   @0x1bf930 andseq pc, r8, r8, lsr r11
 *
 * ══ §178/181 F_LayerTileGetXScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf9c8  size 160  40 条（0x1bf9c8..0x1bfa68）
 * @func 0x1bf9c8 0x1bfa68  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x68×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf9c8 cmp r3, #1
 *   @0x1bf9cc push {r3, r4, r5, r6, r7, lr}
 *   @0x1bf9d0 mov r3, #0
 *   @0x1bf9d4 mov r5, r3
 *   @0x1bf9d8 mov r4, r0
 *   @0x1bf9dc movt r3, #0xbff0
 *   @0x1bf9e0 str r5, [r0, #0xc]
 *   @0x1bf9e4 str r3, [r0, #0x4]
 *   @0x1bf9e8 str r5, [r0]
 *   @0x1bf9ec ldr r6, [sp, #0x18]
 *   @0x1bf9f0 beq 0x1bfa08 <_Z20F_LayerTileGetXScaleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bf9f4 ldr r0, [pc, #0x68]
 *   @0x1bf9f8 mov r1, r5
 *   @0x1bf9fc pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bfa00 add r0, pc, r0
 *   @0x1bfa04 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bfa08 str r5, [r0]
 *   @0x1bfa0c mov r3, #0
 *   @0x1bfa10 movt r3, #0x3ff0
 *   @0x1bfa14 str r3, [r0, #0x4]
 *   @0x1bfa18 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bfa1c mov r1, r5
 *   @0x1bfa20 mov r7, r0
 *   @0x1bfa24 mov r0, r6
 *   @0x1bfa28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bfa2c mov r2, r5
 *   @0x1bfa30 mov r1, r0
 *   @0x1bfa34 mov r0, r7
 *   @0x1bfa38 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bfa3c cmp r0, #0
 *   @0x1bfa40 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bfa44 ldr r3, [r0]
 *   @0x1bfa48 cmp r3, #7
 *   @0x1bfa4c popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bfa50 vldr s15, [r0, #52]
 *   @0x1bfa54 vcvt.f64.f32 d6, s15
 *   @0x1bfa58 vmov r2, r3, d6
 *   @0x1bfa5c stm r4, {r2, r3}
 *   @0x1bfa60 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bfa64 andseq pc, r8, r12, ror #20
 *
 * ══ §179/181 F_LayerTileGetYScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bfa68  size 160  40 条（0x1bfa68..0x1bfb08）
 * @func 0x1bfa68 0x1bfb08  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x68×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bfa68 cmp r3, #1
 *   @0x1bfa6c push {r3, r4, r5, r6, r7, lr}
 *   @0x1bfa70 mov r3, #0
 *   @0x1bfa74 mov r5, r3
 *   @0x1bfa78 mov r4, r0
 *   @0x1bfa7c movt r3, #0xbff0
 *   @0x1bfa80 str r5, [r0, #0xc]
 *   @0x1bfa84 str r3, [r0, #0x4]
 *   @0x1bfa88 str r5, [r0]
 *   @0x1bfa8c ldr r6, [sp, #0x18]
 *   @0x1bfa90 beq 0x1bfaa8 <_Z20F_LayerTileGetYScaleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bfa94 ldr r0, [pc, #0x68]
 *   @0x1bfa98 mov r1, r5
 *   @0x1bfa9c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bfaa0 add r0, pc, r0
 *   @0x1bfaa4 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bfaa8 str r5, [r0]
 *   @0x1bfaac mov r3, #0
 *   @0x1bfab0 movt r3, #0x3ff0
 *   @0x1bfab4 str r3, [r0, #0x4]
 *   @0x1bfab8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bfabc mov r1, r5
 *   @0x1bfac0 mov r7, r0
 *   @0x1bfac4 mov r0, r6
 *   @0x1bfac8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bfacc mov r2, r5
 *   @0x1bfad0 mov r1, r0
 *   @0x1bfad4 mov r0, r7
 *   @0x1bfad8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bfadc cmp r0, #0
 *   @0x1bfae0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bfae4 ldr r3, [r0]
 *   @0x1bfae8 cmp r3, #7
 *   @0x1bfaec popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bfaf0 vldr s15, [r0, #56]
 *   @0x1bfaf4 vcvt.f64.f32 d6, s15
 *   @0x1bfaf8 vmov r2, r3, d6
 *   @0x1bfafc stm r4, {r2, r3}
 *   @0x1bfb00 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bfb04 andseq pc, r8, r4, lsl #20
 *
 * ══ §180/181 HighScore_Add(char const*, int)  0x1dc318  size 160  40 条（0x1dc318..0x1dc3b8）
 * @func 0x1dc318 0x1dc3b8  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: HighScore_Add(char const*, int)+0x34 / YYStrDup(char const*)
 * 字段偏移 top8: 0x4×2 / 0x84×1 / 0x5c×1 / 0x44×1 / 0x48×1 / 0x54×1 / 0x50×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc318 push {r4, r5, r6, lr}
 *   @0x1dc31c mov r4, #0
 *   @0x1dc320 ldr r5, [pc, #0x84]
 *   @0x1dc324 ldr r5, [pc, r5]
 *   @0x1dc328 lsl r2, r4, #3
 *   @0x1dc32c add r3, r5, r2
 *   @0x1dc330 ldr r3, [r3, #0x4]
 *   @0x1dc334 cmp r3, r1
 *   @0x1dc338 blt 0x1dc34c <_Z13HighScore_AddPKci+0x34>
 *   @0x1dc33c add r4, r4, #1
 *   @0x1dc340 cmp r4, #10
 *   @0x1dc344 bne 0x1dc328 <_Z13HighScore_AddPKci+0x10>
 *   @0x1dc348 pop {r4, r5, r6, pc}
 *   @0x1dc34c ldr r3, [pc, #0x5c]
 *   @0x1dc350 cmp r4, #9
 *   @0x1dc354 subne r6, r5, #72
 *   @0x1dc358 ldr r3, [pc, r3]
 *   @0x1dc35c addne r6, r6, r2
 *   @0x1dc360 str r4, [r3]
 *   @0x1dc364 movne r3, r5
 *   @0x1dc368 beq 0x1dc388 <_Z13HighScore_AddPKci+0x70>
 *   @0x1dc36c ldr lr, [r3, #0x44]
 *   @0x1dc370 sub r3, r3, #8
 *   @0x1dc374 ldr r12, [r3, #0x48]
 *   @0x1dc378 str lr, [r3, #0x54]
 *   @0x1dc37c str r12, [r3, #0x50]
 *   @0x1dc380 cmp r3, r6
 *   @0x1dc384 bne 0x1dc36c <_Z13HighScore_AddPKci+0x54>
 *   @0x1dc388 add r2, r5, r2
 *   @0x1dc38c str r1, [r2, #0x4]
 *   @0x1dc390 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1dc394 ldr r3, [pc, #0x18]
 *   @0x1dc398 mov r2, #1
 *   @0x1dc39c ldr r3, [pc, r3]
 *   @0x1dc3a0 strb r2, [r3]
 *   @0x1dc3a4 str r0, [r5, r4, lsl #3]
 *   @0x1dc3a8 pop {r4, r5, r6, pc}
 *   @0x1dc3ac eoreq r4, r1, r8, ror #18
 *   @0x1dc3b0 eoreq r4, r1, r8, lsr r9
 *   @0x1dc3b4 .word 0x002148f8
 *
 * ══ §181/181 CSkeletonInstance::LineCollision(int, float, float, float, float, float, float, float, float, float)  0xbf3cc  size 104  26 条（0xbf3cc..0xbf434）
 * @func 0xbf3cc 0xbf434  size 104  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*) / spSkeletonBounds_intersectsSegment
 * 字段偏移 top8: 0x28×1 / 0x2c×1 / 0x34×1 / 0x30×1 / 0x4×1 / 0x38×1 / 0x3c×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbf3cc push {r4, r5, r6, r7, r8, lr}
 *   @0xbf3d0 sub sp, sp, #16
 *   @0xbf3d4 mov r12, #0
 *   @0xbf3d8 mov r7, r0
 *   @0xbf3dc ldr lr, [sp, #0x28]
 *   @0xbf3e0 ldr r4, [sp, #0x2c]
 *   @0xbf3e4 ldr r6, [sp, #0x34]
 *   @0xbf3e8 str lr, [sp]
 *   @0xbf3ec ldr lr, [sp, #0x30]
 *   @0xbf3f0 str r4, [sp, #0x4]
 *   @0xbf3f4 ldr r5, [sp, #0x38]
 *   @0xbf3f8 ldr r4, [sp, #0x3c]
 *   @0xbf3fc ldr r8, [sp, #0x40]
 *   @0xbf400 str lr, [sp, #0x8]
 *   @0xbf404 str r12, [sp, #0xc]
 *   @0xbf408 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xbf40c ldr r0, [r7, #0x20]
 *   @0xbf410 mov r1, r6
 *   @0xbf414 str r8, [sp]
 *   @0xbf418 mov r2, r5
 *   @0xbf41c mov r3, r4
 *   @0xbf420 bl 0x28acf4 <spSkeletonBounds_intersectsSegment>
 *   @0xbf424 adds r0, r0, #0
 *   @0xbf428 movne r0, #1
 *   @0xbf42c add sp, sp, #16
 *   @0xbf430 pop {r4, r5, r6, r7, r8, pc}
 */
