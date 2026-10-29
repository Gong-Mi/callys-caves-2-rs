/* cally 逆向卡：All_50 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 110 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/110 Graphics::SceneBegin()  0x17dd58  size 284  71 条（0x17dd58..0x17de74）
 * @func 0x17dd58 0x17de74  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17dd64→0x4a2138, 0x17dd7c→0x4a22b1, 0x17dd98→0x4a2134, 0x17dda0→0x4a213c, 0x17dda4→0x4a2130, 0x17ddd8→0x3f26c8, 0x17dddc→0x3f26dc, 0x17de04→0x479c74
 * 调用序列: GraphicsPerf::BeginFrame() / _InvalidateTextureState()
 * 字段偏移 top8: 0xe4×2 / 0xb4×2 / 0x84×2 / 0xd0×1 / 0xb8×1 / 0x60×1 / 0x50×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dd58 push {r4, r5, lr}
 *   @0x17dd5c sub sp, sp, #20
 *   @0x17dd60 ldr r4, [pc, #0xe4]
 *   @0x17dd64 ldr r3, [pc, #0xe4]
 *   @0x17dd68 add r4, pc, r4
 *   @0x17dd6c ldr r3, [r4, r3]
 *   @0x17dd70 ldr r5, [r3]
 *   @0x17dd74 cmp r5, #0
 *   @0x17dd78 bne 0x17dd90 <_ZN8Graphics10SceneBeginEv+0x38>
 *   @0x17dd7c ldr r2, [pc, #0xd0]
 *   @0x17dd80 ldr r2, [r4, r2]
 *   @0x17dd84 ldrb r2, [r2]
 *   @0x17dd88 cmp r2, #0
 *   @0x17dd8c bne 0x17dd98 <_ZN8Graphics10SceneBeginEv+0x40>
 *   @0x17dd90 add sp, sp, #20
 *   @0x17dd94 pop {r4, r5, pc}
 *   @0x17dd98 ldr r2, [pc, #0xb8]
 *   @0x17dd9c mov r1, #1
 *   @0x17dda0 ldr r12, [pc, #0xb4]
 *   @0x17dda4 ldr r0, [pc, #0xb4]
 *   @0x17dda8 ldr r2, [r4, r2]
 *   @0x17ddac ldr lr, [r2]
 *   @0x17ddb0 add lr, lr, r1
 *   @0x17ddb4 str lr, [r2]
 *   @0x17ddb8 ldr r2, [r4, r12]
 *   @0x17ddbc ldr r12, [r2]
 *   @0x17ddc0 eor r12, r12, r1
 *   @0x17ddc4 str r12, [r2]
 *   @0x17ddc8 ldr r2, [r4, r0]
 *   @0x17ddcc str r1, [r3]
 *   @0x17ddd0 str r5, [r2]
 *   @0x17ddd4 bl 0x17b9a0 <_ZN12GraphicsPerf10BeginFrameEv>
 *   @0x17ddd8 ldr r2, [pc, #0x84]
 *   @0x17dddc ldr r3, [pc, #0x84]
 *   @0x17dde0 ldr r2, [r4, r2]
 *   @0x17dde4 strb r5, [r2]
 *   @0x17dde8 ldr r3, [r4, r3]
 *   @0x17ddec ldr r3, [r3]
 *   @0x17ddf0 cmp r3, #0
 *   @0x17ddf4 beq 0x17de04 <_ZN8Graphics10SceneBeginEv+0xac>
 *   @0x17ddf8 bl 0x182598 <_Z23_InvalidateTextureStatev>
 *   @0x17ddfc add sp, sp, #20
 *   @0x17de00 pop {r4, r5, pc}
 *   @0x17de04 ldr r3, [pc, #0x60]
 *   @0x17de08 movw r0, #0xb57
 *   @0x17de0c ldr r3, [r4, r3]
 *   @0x17de10 ldr r3, [r3]
 *   @0x17de14 blx r3
 *   @0x17de18 ldr r2, [pc, #0x50]
 *   @0x17de1c mov r3, #0
 *   @0x17de20 mov r12, #1065353216
 *   @0x17de24 str r3, [sp]
 *   @0x17de28 movw r0, #0xb53
 *   @0x17de2c str r3, [sp, #0x4]
 *   @0x17de30 mov r1, sp
 *   @0x17de34 str r3, [sp, #0x8]
 *   @0x17de38 str r12, [sp, #0xc]
 *   @0x17de3c ldr r3, [r4, r2]
 *   @0x17de40 ldr r3, [r3]
 *   @0x17de44 blx r3
 *   @0x17de48 b 0x17ddf8 <_ZN8Graphics10SceneBeginEv+0xa0>
 *   @0x17de4c eoreq r3, r7, r8, ror #29
 *   @0x17de50 .word 0xffffe7f4
 *   @0x17de54 .word 0xffffe4d0
 *   @0x17de58 .word 0xffffe7f8
 *   @0x17de5c .word 0xffffe7fc
 *   @0x17de60 .word 0xffffe800
 *   @0x17de64 .word 0xffffe804
 *   @0x17de68 .word 0xffffe7b8
 *   @0x17de6c .word 0xffffbad8
 *   @0x17de70 .word 0xffffbc70
 *
 * ══ §2/110 LoadSave::_ReadFile(char const*, int*)  0x18f594  size 284  71 条（0x18f594..0x18f6b0）
 * @func 0x18f594 0x18f6b0  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: zip_fopen / zip_stat / MemoryManager::Alloc(unsigned int, char const*, int, bool) / zip_fread / 0xb6964 / zip_fclose
 * 字段偏移 top8: 0xf8×1 / 0xbc×1 / 0xac×1 / 0x14×1 / 0x30×1 / 0x2c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f594 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18f598 mov r2, #1
 *   @0x18f59c ldr r4, [pc, #0xf8]
 *   @0x18f5a0 sub sp, sp, #36
 *   @0x18f5a4 mov r5, r0
 *   @0x18f5a8 mov r6, r1
 *   @0x18f5ac ldr r4, [pc, r4]
 *   @0x18f5b0 mov r1, r0
 *   @0x18f5b4 ldr r0, [r4]
 *   @0x18f5b8 blx 0x2a44b8 <zip_fopen>
 *   @0x18f5bc subs r7, r0, #0
 *   @0x18f5c0 beq 0x18f670 <_ZN8LoadSave9_ReadFileEPKcPi+0xdc>
 *   @0x18f5c4 add r3, sp, #4
 *   @0x18f5c8 mov r1, r5
 *   @0x18f5cc mov r2, #1
 *   @0x18f5d0 ldr r0, [r4]
 *   @0x18f5d4 blx 0x2a5670 <zip_stat>
 *   @0x18f5d8 cmp r6, #0
 *   @0x18f5dc ldr r1, [pc, #0xbc]
 *   @0x18f5e0 mov r2, #191
 *   @0x18f5e4 ldrne r3, [sp, #0x14]
 *   @0x18f5e8 ldreq r0, [sp, #0x14]
 *   @0x18f5ec add r1, pc, r1
 *   @0x18f5f0 ldr r8, [pc, #0xac]
 *   @0x18f5f4 add r8, pc, r8
 *   @0x18f5f8 strne r3, [r6]
 *   @0x18f5fc movne r0, r3
 *   @0x18f600 cmp r0, #0
 *   @0x18f604 mov r3, #1
 *   @0x18f608 moveq r0, #1
 *   @0x18f60c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18f610 ldr r5, [sp, #0x14]
 *   @0x18f614 cmp r5, #0
 *   @0x18f618 mov r9, r0
 *   @0x18f61c mov r6, r0
 *   @0x18f620 beq 0x18f65c <_ZN8LoadSave9_ReadFileEPKcPi+0xc8>
 *   @0x18f624 mov r1, r6
 *   @0x18f628 mov r0, r7
 *   @0x18f62c mov r2, r5
 *   @0x18f630 blx 0x2a476c <zip_fread>
 *   @0x18f634 mov r4, r0
 *   @0x18f638 cmp r4, r5
 *   @0x18f63c mov r0, r8
 *   @0x18f640 add r6, r6, r4
 *   @0x18f644 beq 0x18f65c <_ZN8LoadSave9_ReadFileEPKcPi+0xc8>
 *   @0x18f648 bl 0xb6964 <printf@plt>
 *   @0x18f64c cmp r4, #0
 *   @0x18f650 beq 0x18f65c <_ZN8LoadSave9_ReadFileEPKcPi+0xc8>
 *   @0x18f654 subs r5, r5, r4
 *   @0x18f658 bne 0x18f624 <_ZN8LoadSave9_ReadFileEPKcPi+0x90>
 *   @0x18f65c mov r0, r7
 *   @0x18f660 blx 0x2a4388 <zip_fclose>
 *   @0x18f664 mov r0, r9
 *   @0x18f668 add sp, sp, #36
 *   @0x18f66c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18f670 ldr r3, [pc, #0x30]
 *   @0x18f674 mov r2, r5
 *   @0x18f678 ldr r1, [pc, #0x2c]
 *   @0x18f67c mov r9, r7
 *   @0x18f680 ldr r3, [pc, r3]
 *   @0x18f684 add r1, pc, r1
 *   @0x18f688 ldr r0, [r3]
 *   @0x18f68c ldr r3, [r0]
 *   @0x18f690 ldr r3, [r3, #0xc]
 *   @0x18f694 blx r3
 *   @0x18f698 b 0x18f664 <_ZN8LoadSave9_ReadFileEPKcPi+0xd0>
 *   @0x18f69c eoreq r0, r6, r8, ror #18
 *   @0x18f6a0 andseq r12, r11, r8, ror #28
 *   @0x18f6a4 mulseq r11, r8, lr
 *   @0x18f6a8 mlaeq r5, r4, r0, lr
 *   @0x18f6ac andseq r12, r11, r0, lsr #28
 *
 * ══ §3/110 CObjectGM::Clear()  0x19d3d8  size 284  71 条（0x19d3d8..0x19d4f4）
 * @func 0x19d3d8 0x19d4f4  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×4 / CObjectGM::Clear()+0x98
 * 字段偏移 top8: 0x50×4 / 0x14×2 / 0x4×2 / 0x4c×2 / 0x2×2 / 0xc4×2 / 0xd0×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19d3d8 push {r4, r5, r6, r7, r8, lr}
 *   @0x19d3dc mov r8, r0
 *   @0x19d3e0 ldr r0, [r0, #0x14]
 *   @0x19d3e4 mov r4, #0
 *   @0x19d3e8 mvn r3, #0
 *   @0x19d3ec mov r2, #18
 *   @0x19d3f0 cmp r0, r4
 *   @0x19d3f4 str r2, [r8]
 *   @0x19d3f8 str r3, [r8, #0x4]
 *   @0x19d3fc str r3, [r8, #0xc]
 *   @0x19d400 str r3, [r8, #0x10]
 *   @0x19d404 str r4, [r8, #0x8]
 *   @0x19d408 str r4, [r8, #0x48]
 *   @0x19d40c beq 0x19d418 <_ZN9CObjectGM5ClearEv+0x40>
 *   @0x19d410 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19d414 str r4, [r8, #0x14]
 *   @0x19d418 mov r7, #0
 *   @0x19d41c mov r5, r8
 *   @0x19d420 mov r6, r7
 *   @0x19d424 ldr r2, [r5, #0x4c]
 *   @0x19d428 ldr r1, [r5, #0x50]
 *   @0x19d42c cmp r2, #0
 *   @0x19d430 movgt r4, #0
 *   @0x19d434 ble 0x19d470 <_ZN9CObjectGM5ClearEv+0x98>
 *   @0x19d438 ldr r3, [r1, r4, lsl #2]
 *   @0x19d43c cmp r3, #0
 *   @0x19d440 mov r0, r3
 *   @0x19d444 beq 0x19d464 <_ZN9CObjectGM5ClearEv+0x8c>
 *   @0x19d448 ldr r3, [r3]
 *   @0x19d44c ldr r3, [r3, #0x4]
 *   @0x19d450 blx r3
 *   @0x19d454 ldr r3, [r5, #0x50]
 *   @0x19d458 str r6, [r3, r4, lsl #2]
 *   @0x19d45c ldr r1, [r5, #0x50]
 *   @0x19d460 ldr r2, [r5, #0x4c]
 *   @0x19d464 add r4, r4, #1
 *   @0x19d468 cmp r2, r4
 *   @0x19d46c bgt 0x19d438 <_ZN9CObjectGM5ClearEv+0x60>
 *   @0x19d470 mov r0, r1
 *   @0x19d474 add r7, r7, #1
 *   @0x19d478 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19d47c cmp r7, #15
 *   @0x19d480 str r6, [r5, #0x50]
 *   @0x19d484 add r5, r5, #8
 *   @0x19d488 str r6, [r5, #0x44]
 *   @0x19d48c bne 0x19d424 <_ZN9CObjectGM5ClearEv+0x4c>
 *   @0x19d490 ldr r0, [r8, #0xc4]
 *   @0x19d494 cmp r0, #0
 *   @0x19d498 beq 0x19d4b0 <_ZN9CObjectGM5ClearEv+0xd8>
 *   @0x19d49c ldr r4, [r0]
 *   @0x19d4a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19d4a4 cmp r4, #0
 *   @0x19d4a8 mov r0, r4
 *   @0x19d4ac bne 0x19d49c <_ZN9CObjectGM5ClearEv+0xc4>
 *   @0x19d4b0 ldr r0, [r8, #0xd0]
 *   @0x19d4b4 mov r3, #0
 *   @0x19d4b8 str r3, [r8, #0xcc]
 *   @0x19d4bc cmp r0, r3
 *   @0x19d4c0 str r3, [r8, #0xc8]
 *   @0x19d4c4 str r3, [r8, #0xc4]
 *   @0x19d4c8 beq 0x19d4e0 <_ZN9CObjectGM5ClearEv+0x108>
 *   @0x19d4cc ldr r4, [r0]
 *   @0x19d4d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19d4d4 cmp r4, #0
 *   @0x19d4d8 mov r0, r4
 *   @0x19d4dc bne 0x19d4cc <_ZN9CObjectGM5ClearEv+0xf4>
 *   @0x19d4e0 mov r3, #0
 *   @0x19d4e4 str r3, [r8, #0xd8]
 *   @0x19d4e8 str r3, [r8, #0xd4]
 *   @0x19d4ec str r3, [r8, #0xd0]
 *   @0x19d4f0 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §4/110 F_TilemapClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bee70  size 284  71 条（0x1bee70..0x1bef8c）
 * @func 0x1bee70 0x1bef8c  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show(char const*, bool)×2 / YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / F_TilemapClear(RValue&, CInstance*, CInstance*, int, RValue*)+0x38 / F_TilemapClear(RValue&, CInstance*, CInstance*, int, RValue*)+0xf4
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x18×2 / 0x34×2 / 0x2c×2 / 0x28×2 / 0xe4×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bee70 cmp r3, #2
 *   @0x1bee74 mov r3, #0
 *   @0x1bee78 push {r4, r5, r6, lr}
 *   @0x1bee7c mov r5, r3
 *   @0x1bee80 sub sp, sp, #8
 *   @0x1bee84 movt r3, #0xbff0
 *   @0x1bee88 str r5, [r0, #0xc]
 *   @0x1bee8c str r3, [r0, #0x4]
 *   @0x1bee90 str r5, [r0]
 *   @0x1bee94 beq 0x1beeb0 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bee98 ldr r0, [pc, #0xe4]
 *   @0x1bee9c mov r1, r5
 *   @0x1beea0 add r0, pc, r0
 *   @0x1beea4 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1beea8 add sp, sp, #8
 *   @0x1beeac pop {r4, r5, r6, pc}
 *   @0x1beeb0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1beeb4 add r4, sp, #8
 *   @0x1beeb8 mov r1, r5
 *   @0x1beebc str r5, [r4, #-0x4]!
 *   @0x1beec0 mov r6, r0
 *   @0x1beec4 ldr r0, [sp, #0x18]
 *   @0x1beec8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1beecc mov r2, r4
 *   @0x1beed0 mov r1, r0
 *   @0x1beed4 mov r0, r6
 *   @0x1beed8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1beedc subs r4, r0, #0
 *   @0x1beee0 beq 0x1beea8 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1beee4 ldr r3, [r4]
 *   @0x1beee8 cmp r3, #5
 *   @0x1beeec bne 0x1beea8 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1beef0 ldr r3, [sp, #0x4]
 *   @0x1beef4 cmp r3, #0
 *   @0x1beef8 beq 0x1beea8 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1beefc ldr r1, [r4, #0x34]
 *   @0x1bef00 cmp r1, #0
 *   @0x1bef04 beq 0x1bef74 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x1bef08 ldr r0, [sp, #0x18]
 *   @0x1bef0c mov r1, #1
 *   @0x1bef10 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bef14 ldr r3, [r4, #0x2c]
 *   @0x1bef18 cmp r3, #0
 *   @0x1bef1c ble 0x1beea8 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1bef20 ldr r2, [r4, #0x28]
 *   @0x1bef24 mov r1, r5
 *   @0x1bef28 mov r6, r5
 *   @0x1bef2c cmp r2, #0
 *   @0x1bef30 ble 0x1bef64 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x1bef34 ldr r2, [r4, #0x34]
 *   @0x1bef38 sub r12, r6, #-1073741823
 *   @0x1bef3c mov r5, r6
 *   @0x1bef40 mov r3, #0
 *   @0x1bef44 add r12, r2, r12, lsl #2
 *   @0x1bef48 str r0, [r12, #0x4]!
 *   @0x1bef4c add r3, r3, #1
 *   @0x1bef50 ldr r2, [r4, #0x28]
 *   @0x1bef54 add r6, r3, r5
 *   @0x1bef58 cmp r2, r3
 *   @0x1bef5c bgt 0x1bef48 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x1bef60 ldr r3, [r4, #0x2c]
 *   @0x1bef64 add r1, r1, #1
 *   @0x1bef68 cmp r3, r1
 *   @0x1bef6c bgt 0x1bef2c <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x1bef70 b 0x1beea8 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1bef74 ldr r0, [pc, #0xc]
 *   @0x1bef78 add r0, pc, r0
 *   @0x1bef7c bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bef80 b 0x1beea8 <_Z14F_TilemapClearR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1bef84 mulseq r9, r8, r0
 *   @0x1bef88 andseq pc, r8, r12, ror #31
 *
 * ══ §5/110 F_DrawTilemap(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bef8c  size 284  71 条（0x1bef8c..0x1bf0a8）
 * @func 0x1bef8c 0x1bf0a8  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / DrawLayerTilemapElement(tagYYRECT*, CLayer*, CLayerTilemapElement*, float, float, float)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x84×2 / 0x20×1 / 0xd0×1 / 0x34×1 / 0x3c×1 / 0x180×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bef8c push {r4, r5, r6, r7, r8, lr}
 *   @0x1bef90 cmp r3, #3
 *   @0x1bef94 sub sp, sp, #8
 *   @0x1bef98 mov r3, #0
 *   @0x1bef9c mov r4, r3
 *   @0x1befa0 mov r6, r1
 *   @0x1befa4 movt r3, #0xbff0
 *   @0x1befa8 str r4, [r0, #0xc]
 *   @0x1befac str r3, [r0, #0x4]
 *   @0x1befb0 str r4, [r0]
 *   @0x1befb4 ldr r5, [sp, #0x20]
 *   @0x1befb8 beq 0x1befd4 <_Z13F_DrawTilemapR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1befbc ldr r0, [pc, #0xd0]
 *   @0x1befc0 mov r1, r4
 *   @0x1befc4 add r0, pc, r0
 *   @0x1befc8 add sp, sp, #8
 *   @0x1befcc pop {r4, r5, r6, r7, r8, lr}
 *   @0x1befd0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1befd4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1befd8 mov r1, r4
 *   @0x1befdc mov r7, r0
 *   @0x1befe0 mov r0, r5
 *   @0x1befe4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1befe8 mov r2, r4
 *   @0x1befec mov r1, r0
 *   @0x1beff0 mov r0, r7
 *   @0x1beff4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1beff8 subs r7, r0, #0
 *   @0x1beffc beq 0x1bf00c <_Z13F_DrawTilemapR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1bf000 ldr r3, [r7]
 *   @0x1bf004 cmp r3, #5
 *   @0x1bf008 beq 0x1bf034 <_Z13F_DrawTilemapR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x1bf00c ldr r3, [pc, #0x84]
 *   @0x1bf010 ldr r1, [pc, #0x84]
 *   @0x1bf014 ldr r3, [pc, r3]
 *   @0x1bf018 add r1, pc, r1
 *   @0x1bf01c ldr r0, [r3]
 *   @0x1bf020 ldr r3, [r0]
 *   @0x1bf024 ldr r3, [r3, #0xc]
 *   @0x1bf028 blx r3
 *   @0x1bf02c add sp, sp, #8
 *   @0x1bf030 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1bf034 ldr r1, [r7, #0x34]
 *   @0x1bf038 cmp r1, #0
 *   @0x1bf03c beq 0x1bf088 <_Z13F_DrawTilemapR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x1bf040 mov r0, r5
 *   @0x1bf044 mov r1, #1
 *   @0x1bf048 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bf04c mov r1, #2
 *   @0x1bf050 mov r8, r0
 *   @0x1bf054 mov r0, r5
 *   @0x1bf058 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bf05c ldr r12, [pc, #0x3c]
 *   @0x1bf060 ldr r2, [r6, #0x180]
 *   @0x1bf064 mov r3, r8
 *   @0x1bf068 ldr r12, [pc, r12]
 *   @0x1bf06c mov r1, r4
 *   @0x1bf070 str r2, [sp, #0x4]
 *   @0x1bf074 mov r2, r7
 *   @0x1bf078 str r0, [sp]
 *   @0x1bf07c mov r0, r12
 *   @0x1bf080 bl 0x1b2124 <_Z23DrawLayerTilemapElementP9tagYYRECTP6CLayerP20CLayerTilemapElementfff>
 *   @0x1bf084 b 0x1bf02c <_Z13F_DrawTilemapR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1bf088 ldr r0, [pc, #0x14]
 *   @0x1bf08c add r0, pc, r0
 *   @0x1bf090 b 0x1befc8 <_Z13F_DrawTilemapR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bf094 andseq pc, r8, r12, asr #31
 *   @0x1bf098 eoreq lr, r2, r0, lsl #14
 *   @0x1bf09c ldrsbeq pc, [r8], -r0
 *   @0x1bf0a0 eoreq r1, r3, r4, ror #1
 *   @0x1bf0a4 andseq pc, r8, r0, lsr pc
 *
 * ══ §6/110 CLayerManager::GetNewOldTilemapElement()  0x1c0de4  size 284  71 条（0x1c0de4..0x1c0f00）
 * @func 0x1c0de4 0x1c0f00  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetNewOldTilemapElement()+0xd4 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CLayerManager::GetNewOldTilemapElement()+0x38
 * 字段偏移 top8: 0x8×6 / 0x10×4 / 0x14×2 / 0x18×2 / 0x108×1 / 0xec×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c0de4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1c0de8 ldr r5, [pc, #0x108]
 *   @0x1c0dec ldr r5, [pc, r5]
 *   @0x1c0df0 ldr r6, [r5, #0x8]
 *   @0x1c0df4 cmp r6, #0
 *   @0x1c0df8 bne 0x1c0ec0 <_ZN13CLayerManager23GetNewOldTilemapElementEv+0xdc>
 *   @0x1c0dfc ldr r3, [r5, #0x10]
 *   @0x1c0e00 cmp r3, #0
 *   @0x1c0e04 ble 0x1c0eb8 <_ZN13CLayerManager23GetNewOldTilemapElementEv+0xd4>
 *   @0x1c0e08 ldr r7, [pc, #0xec]
 *   @0x1c0e0c mov r4, r6
 *   @0x1c0e10 mov r9, #1
 *   @0x1c0e14 mvn r8, #0
 *   @0x1c0e18 add r7, pc, r7
 *   @0x1c0e1c mov r3, #1
 *   @0x1c0e20 mov r0, #52
 *   @0x1c0e24 mov r1, r7
 *   @0x1c0e28 mov r2, #63
 *   @0x1c0e2c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c0e30 mov r3, #3
 *   @0x1c0e34 cmp r0, #0
 *   @0x1c0e38 beq 0x1c0e70 <_ZN13CLayerManager23GetNewOldTilemapElementEv+0x8c>
 *   @0x1c0e3c strb r4, [r0, #0x8]
 *   @0x1c0e40 str r4, [r0, #0xc]
 *   @0x1c0e44 str r4, [r0, #0x10]
 *   @0x1c0e48 str r4, [r0, #0x14]
 *   @0x1c0e4c str r4, [r0, #0x18]
 *   @0x1c0e50 str r8, [r0, #0x4]
 *   @0x1c0e54 str r4, [r0, #0x1c]
 *   @0x1c0e58 str r4, [r0, #0x20]
 *   @0x1c0e5c str r4, [r0, #0x28]
 *   @0x1c0e60 str r4, [r0, #0x24]
 *   @0x1c0e64 str r4, [r0, #0x2c]
 *   @0x1c0e68 str r9, [r0, #0x30]
 *   @0x1c0e6c str r3, [r0]
 *   @0x1c0e70 ldr r3, [r5]
 *   @0x1c0e74 add r6, r6, #1
 *   @0x1c0e78 ldr r2, [r5, #0x8]
 *   @0x1c0e7c cmp r3, #0
 *   @0x1c0e80 streq r0, [r5, #0x4]
 *   @0x1c0e84 strne r0, [r3, #0x18]
 *   @0x1c0e88 add r2, r2, #1
 *   @0x1c0e8c streq r3, [r0, #0x18]
 *   @0x1c0e90 streq r3, [r0, #0x14]
 *   @0x1c0e94 strne r3, [r0, #0x14]
 *   @0x1c0e98 ldr r3, [r5, #0x10]
 *   @0x1c0e9c streq r0, [r5]
 *   @0x1c0ea0 strne r0, [r5]
 *   @0x1c0ea4 strne r4, [r0, #0x18]
 *   @0x1c0ea8 cmp r6, r3
 *   @0x1c0eac str r2, [r5, #0x8]
 *   @0x1c0eb0 blt 0x1c0e1c <_ZN13CLayerManager23GetNewOldTilemapElementEv+0x38>
 *   @0x1c0eb4 ldr r6, [r5, #0x8]
 *   @0x1c0eb8 lsl r3, r3, #1
 *   @0x1c0ebc str r3, [r5, #0x10]
 *   @0x1c0ec0 ldr r0, [r5]
 *   @0x1c0ec4 sub r6, r6, #1
 *   @0x1c0ec8 str r6, [r5, #0x8]
 *   @0x1c0ecc ldr r3, [r0, #0x18]
 *   @0x1c0ed0 ldr r2, [r0, #0x14]
 *   @0x1c0ed4 cmp r3, #0
 *   @0x1c0ed8 strne r2, [r3, #0x14]
 *   @0x1c0edc ldrne r2, [r0, #0x14]
 *   @0x1c0ee0 ldrne r3, [r0, #0x18]
 *   @0x1c0ee4 streq r2, [r5]
 *   @0x1c0ee8 cmp r2, #0
 *   @0x1c0eec streq r3, [r5, #0x4]
 *   @0x1c0ef0 strne r3, [r2, #0x18]
 *   @0x1c0ef4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1c0ef8 eoreq pc, r2, r12, ror r10
 *   @0x1c0efc andseq r12, r8, r12, ror r8
 *
 * ══ §7/110 CAudioGroupMan::Update()  0x21e268  size 284  71 条（0x21e268..0x21e384）
 * @func 0x21e268 0x21e384  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CAudioGroupMan::Update()+0xc8×2 / CAudioGroup::SetLoadState(CAudioGroup::eLoadState)×2 / CreateDsMap(int, ...) / CreateAsynEventWithDSMap(int, int) / Audio_AllGroupSoundsStopped(int) / CAudioGroup::FreeBuffers() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×5 / 0xec×2 / 0x18×2 / 0xf0×1 / 0x2×1 / 0x20×1 / 0x9×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e268 ldr r2, [r0, #0x4]
 *   @0x21e26c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x21e270 cmp r2, #1
 *   @0x21e274 sub sp, sp, #24
 *   @0x21e278 mov r6, r0
 *   @0x21e27c ble 0x21e330 <_ZN14CAudioGroupMan6UpdateEv+0xc8>
 *   @0x21e280 ldr r9, [pc, #0xf0]
 *   @0x21e284 mov r4, #1
 *   @0x21e288 ldr r8, [pc, #0xec]
 *   @0x21e28c ldr r7, [pc, #0xec]
 *   @0x21e290 add r9, pc, r9
 *   @0x21e294 add r8, pc, r8
 *   @0x21e298 add r7, pc, r7
 *   @0x21e29c b 0x21e2ac <_ZN14CAudioGroupMan6UpdateEv+0x44>
 *   @0x21e2a0 add r4, r4, #1
 *   @0x21e2a4 cmp r2, r4
 *   @0x21e2a8 ble 0x21e330 <_ZN14CAudioGroupMan6UpdateEv+0xc8>
 *   @0x21e2ac ldr r3, [r6]
 *   @0x21e2b0 ldr r5, [r3, r4, lsl #2]
 *   @0x21e2b4 ldr r3, [r5]
 *   @0x21e2b8 cmp r3, #3
 *   @0x21e2bc beq 0x21e338 <_ZN14CAudioGroupMan6UpdateEv+0xd0>
 *   @0x21e2c0 cmp r3, #1
 *   @0x21e2c4 bne 0x21e2a0 <_ZN14CAudioGroupMan6UpdateEv+0x38>
 *   @0x21e2c8 ldr r3, [r5, #0x20]
 *   @0x21e2cc mov r0, r5
 *   @0x21e2d0 mov r1, #2
 *   @0x21e2d4 cmp r3, #0
 *   @0x21e2d8 beq 0x21e2a0 <_ZN14CAudioGroupMan6UpdateEv+0x38>
 *   @0x21e2dc ldrb r3, [r3, #0x9]
 *   @0x21e2e0 ands r10, r3, #255
 *   @0x21e2e4 bne 0x21e2a0 <_ZN14CAudioGroupMan6UpdateEv+0x38>
 *   @0x21e2e8 bl 0x21dd48 <_ZN11CAudioGroup12SetLoadStateENS_10eLoadStateE>
 *   @0x21e2ec str r8, [sp]
 *   @0x21e2f0 str r7, [sp, #0x4]
 *   @0x21e2f4 vldr s14, [r5, #4]
 *   @0x21e2f8 vcvt.f64.s32 d7, s14
 *   @0x21e2fc mov r2, #0
 *   @0x21e300 mov r1, r9
 *   @0x21e304 mov r3, #0
 *   @0x21e308 mov r0, #2
 *   @0x21e30c str r10, [sp, #0x10]
 *   @0x21e310 add r4, r4, #1
 *   @0x21e314 vstr d7, [sp, #8]
 *   @0x21e318 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x21e31c mov r1, #72
 *   @0x21e320 bl 0x18da04 <_Z24CreateAsynEventWithDSMapii>
 *   @0x21e324 ldr r2, [r6, #0x4]
 *   @0x21e328 cmp r2, r4
 *   @0x21e32c bgt 0x21e2ac <_ZN14CAudioGroupMan6UpdateEv+0x44>
 *   @0x21e330 add sp, sp, #24
 *   @0x21e334 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x21e338 ldr r0, [r5, #0x4]
 *   @0x21e33c bl 0x218ae0 <_Z27Audio_AllGroupSoundsStoppedi>
 *   @0x21e340 cmp r0, #0
 *   @0x21e344 bne 0x21e350 <_ZN14CAudioGroupMan6UpdateEv+0xe8>
 *   @0x21e348 ldr r2, [r6, #0x4]
 *   @0x21e34c b 0x21e2a0 <_ZN14CAudioGroupMan6UpdateEv+0x38>
 *   @0x21e350 mov r0, r5
 *   @0x21e354 bl 0x21dc80 <_ZN11CAudioGroup11FreeBuffersEv>
 *   @0x21e358 ldr r0, [r5, #0x18]
 *   @0x21e35c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21e360 mov r3, #0
 *   @0x21e364 mov r1, r3
 *   @0x21e368 str r3, [r5, #0x18]
 *   @0x21e36c mov r0, r5
 *   @0x21e370 bl 0x21dd48 <_ZN11CAudioGroup12SetLoadStateENS_10eLoadStateE>
 *   @0x21e374 b 0x21e348 <_ZN14CAudioGroupMan6UpdateEv+0xe0>
 *   @0x21e378 mulseq r2, r8, lr
 *   @0x21e37c andseq r6, r3, r0, asr #8
 *   @0x21e380 andseq r6, r3, r12, asr #8
 *
 * ══ §8/110 JSThrowSyntaxError(char const*)  0x253d88  size 284  71 条（0x253d88..0x253ea4）
 * @func 0x253d88 0x253ea4  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×3 / YYCreateString(RValue*, char const*) / F_JSSyntaxErrorCall(RValue&, CInstance*, CInstance*, int, RValue*) / F_JSThrow(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x14×3 / 0x24×3 / 0x8×2 / 0x10×2 / 0x18×2 / 0x20×2 / 0x34×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x253d88 push {r4, r5, r6, r7, lr}
 *   @0x253d8c sub sp, sp, #60
 *   @0x253d90 add r6, sp, #8
 *   @0x253d94 add r5, sp, #24
 *   @0x253d98 mov r4, #0
 *   @0x253d9c mov r1, r0
 *   @0x253da0 add r7, sp, #40
 *   @0x253da4 mov r0, r6
 *   @0x253da8 str r4, [sp, #0x8]
 *   @0x253dac str r4, [sp, #0xc]
 *   @0x253db0 str r4, [sp, #0x10]
 *   @0x253db4 str r4, [sp, #0x14]
 *   @0x253db8 str r4, [sp, #0x18]
 *   @0x253dbc str r4, [sp, #0x1c]
 *   @0x253dc0 str r4, [sp, #0x20]
 *   @0x253dc4 str r4, [sp, #0x24]
 *   @0x253dc8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x253dcc mov r1, r4
 *   @0x253dd0 mov r2, r4
 *   @0x253dd4 mov r0, r5
 *   @0x253dd8 mov r3, #1
 *   @0x253ddc str r6, [sp]
 *   @0x253de0 bl 0x2440e4 <_Z19F_JSSyntaxErrorCallR6RValueP9CInstanceS2_iPS_>
 *   @0x253de4 mov r3, #1
 *   @0x253de8 mov r1, r4
 *   @0x253dec str r5, [sp]
 *   @0x253df0 mov r2, r4
 *   @0x253df4 mov r0, r7
 *   @0x253df8 str r4, [sp, #0x28]
 *   @0x253dfc str r4, [sp, #0x2c]
 *   @0x253e00 str r4, [sp, #0x30]
 *   @0x253e04 str r4, [sp, #0x34]
 *   @0x253e08 bl 0x24e33c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_>
 *   @0x253e0c ldr r3, [sp, #0x14]
 *   @0x253e10 sub r3, r3, #1
 *   @0x253e14 bic r3, r3, #-16777216
 *   @0x253e18 bic r3, r3, #3
 *   @0x253e1c cmp r3, r4
 *   @0x253e20 beq 0x253e98 <_Z18JSThrowSyntaxErrorPKc+0x110>
 *   @0x253e24 ldr r1, [sp, #0x24]
 *   @0x253e28 mov r3, #0
 *   @0x253e2c str r3, [sp, #0x10]
 *   @0x253e30 mov r2, #5
 *   @0x253e34 sub r1, r1, #1
 *   @0x253e38 str r3, [sp, #0x8]
 *   @0x253e3c bic r3, r1, #-16777216
 *   @0x253e40 str r2, [sp, #0x14]
 *   @0x253e44 bic r3, r3, #3
 *   @0x253e48 cmp r3, #0
 *   @0x253e4c beq 0x253e8c <_Z18JSThrowSyntaxErrorPKc+0x104>
 *   @0x253e50 ldr r1, [sp, #0x34]
 *   @0x253e54 mov r3, #0
 *   @0x253e58 str r3, [sp, #0x20]
 *   @0x253e5c mov r2, #5
 *   @0x253e60 sub r1, r1, #1
 *   @0x253e64 str r3, [sp, #0x18]
 *   @0x253e68 bic r3, r1, #-16777216
 *   @0x253e6c str r2, [sp, #0x24]
 *   @0x253e70 bic r3, r3, #3
 *   @0x253e74 cmp r3, #0
 *   @0x253e78 bne 0x253e84 <_Z18JSThrowSyntaxErrorPKc+0xfc>
 *   @0x253e7c mov r0, r7
 *   @0x253e80 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253e84 add sp, sp, #60
 *   @0x253e88 pop {r4, r5, r6, r7, pc}
 *   @0x253e8c mov r0, r5
 *   @0x253e90 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253e94 b 0x253e50 <_Z18JSThrowSyntaxErrorPKc+0xc8>
 *   @0x253e98 mov r0, r6
 *   @0x253e9c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253ea0 b 0x253e24 <_Z18JSThrowSyntaxErrorPKc+0x9c>
 *
 * ══ §9/110 JSThrowRangeError(char const*)  0x253ea4  size 284  71 条（0x253ea4..0x253fc0）
 * @func 0x253ea4 0x253fc0  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×3 / YYCreateString(RValue*, char const*) / F_JSRangeErrorCall(RValue&, CInstance*, CInstance*, int, RValue*) / F_JSThrow(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x14×3 / 0x24×3 / 0x8×2 / 0x10×2 / 0x18×2 / 0x20×2 / 0x34×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x253ea4 push {r4, r5, r6, r7, lr}
 *   @0x253ea8 sub sp, sp, #60
 *   @0x253eac add r6, sp, #8
 *   @0x253eb0 add r5, sp, #24
 *   @0x253eb4 mov r4, #0
 *   @0x253eb8 mov r1, r0
 *   @0x253ebc add r7, sp, #40
 *   @0x253ec0 mov r0, r6
 *   @0x253ec4 str r4, [sp, #0x8]
 *   @0x253ec8 str r4, [sp, #0xc]
 *   @0x253ecc str r4, [sp, #0x10]
 *   @0x253ed0 str r4, [sp, #0x14]
 *   @0x253ed4 str r4, [sp, #0x18]
 *   @0x253ed8 str r4, [sp, #0x1c]
 *   @0x253edc str r4, [sp, #0x20]
 *   @0x253ee0 str r4, [sp, #0x24]
 *   @0x253ee4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x253ee8 mov r1, r4
 *   @0x253eec mov r2, r4
 *   @0x253ef0 mov r0, r5
 *   @0x253ef4 mov r3, #1
 *   @0x253ef8 str r6, [sp]
 *   @0x253efc bl 0x244044 <_Z18F_JSRangeErrorCallR6RValueP9CInstanceS2_iPS_>
 *   @0x253f00 mov r3, #1
 *   @0x253f04 mov r1, r4
 *   @0x253f08 str r5, [sp]
 *   @0x253f0c mov r2, r4
 *   @0x253f10 mov r0, r7
 *   @0x253f14 str r4, [sp, #0x28]
 *   @0x253f18 str r4, [sp, #0x2c]
 *   @0x253f1c str r4, [sp, #0x30]
 *   @0x253f20 str r4, [sp, #0x34]
 *   @0x253f24 bl 0x24e33c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_>
 *   @0x253f28 ldr r3, [sp, #0x14]
 *   @0x253f2c sub r3, r3, #1
 *   @0x253f30 bic r3, r3, #-16777216
 *   @0x253f34 bic r3, r3, #3
 *   @0x253f38 cmp r3, r4
 *   @0x253f3c beq 0x253fb4 <_Z17JSThrowRangeErrorPKc+0x110>
 *   @0x253f40 ldr r1, [sp, #0x24]
 *   @0x253f44 mov r3, #0
 *   @0x253f48 str r3, [sp, #0x10]
 *   @0x253f4c mov r2, #5
 *   @0x253f50 sub r1, r1, #1
 *   @0x253f54 str r3, [sp, #0x8]
 *   @0x253f58 bic r3, r1, #-16777216
 *   @0x253f5c str r2, [sp, #0x14]
 *   @0x253f60 bic r3, r3, #3
 *   @0x253f64 cmp r3, #0
 *   @0x253f68 beq 0x253fa8 <_Z17JSThrowRangeErrorPKc+0x104>
 *   @0x253f6c ldr r1, [sp, #0x34]
 *   @0x253f70 mov r3, #0
 *   @0x253f74 str r3, [sp, #0x20]
 *   @0x253f78 mov r2, #5
 *   @0x253f7c sub r1, r1, #1
 *   @0x253f80 str r3, [sp, #0x18]
 *   @0x253f84 bic r3, r1, #-16777216
 *   @0x253f88 str r2, [sp, #0x24]
 *   @0x253f8c bic r3, r3, #3
 *   @0x253f90 cmp r3, #0
 *   @0x253f94 bne 0x253fa0 <_Z17JSThrowRangeErrorPKc+0xfc>
 *   @0x253f98 mov r0, r7
 *   @0x253f9c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253fa0 add sp, sp, #60
 *   @0x253fa4 pop {r4, r5, r6, r7, pc}
 *   @0x253fa8 mov r0, r5
 *   @0x253fac bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253fb0 b 0x253f6c <_Z17JSThrowRangeErrorPKc+0xc8>
 *   @0x253fb4 mov r0, r6
 *   @0x253fb8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253fbc b 0x253f40 <_Z17JSThrowRangeErrorPKc+0x9c>
 *
 * ══ §10/110 F_JSInstanceOf(RValue&, CInstance*, CInstance*, int, RValue*)  0x254c30  size 284  71 条（0x254c30..0x254d4c）
 * @func 0x254c30 0x254d4c  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×3 / 0x1c×2 / 0x4×2 / 0x10×1 / 0x48×1 / 0x90×1 / 0x58×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x254c30 push {r3, r4, r5, lr}
 *   @0x254c34 mvn r3, #-16777216
 *   @0x254c38 ldr r1, [sp, #0x10]
 *   @0x254c3c mov r4, r0
 *   @0x254c40 ldr r2, [r1, #0x1c]
 *   @0x254c44 and r2, r2, r3
 *   @0x254c48 cmp r2, r3
 *   @0x254c4c beq 0x254cf4 <_Z14F_JSInstanceOfR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x254c50 ldr r2, [r1, #0xc]
 *   @0x254c54 bic r2, r2, #-16777216
 *   @0x254c58 cmp r2, r3
 *   @0x254c5c beq 0x254d04 <_Z14F_JSInstanceOfR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x254c60 mov r3, #13
 *   @0x254c64 str r3, [r0, #0xc]
 *   @0x254c68 ldr r3, [r1, #0xc]
 *   @0x254c6c mov r5, #0
 *   @0x254c70 str r5, [r0]
 *   @0x254c74 bic r3, r3, #-16777216
 *   @0x254c78 str r5, [r0, #0x4]
 *   @0x254c7c cmp r3, #6
 *   @0x254c80 bne 0x254cd4 <_Z14F_JSInstanceOfR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x254c84 ldr r0, [r1]
 *   @0x254c88 cmp r0, #0
 *   @0x254c8c popeq {r3, r4, r5, pc}
 *   @0x254c90 ldr r3, [r0, #0x48]
 *   @0x254c94 cmp r3, #3
 *   @0x254c98 bne 0x254ce4 <_Z14F_JSInstanceOfR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x254c9c ldr r3, [r0, #0x90]
 *   @0x254ca0 cmp r3, #0
 *   @0x254ca4 beq 0x254d14 <_Z14F_JSInstanceOfR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x254ca8 add r1, r1, #16
 *   @0x254cac blx r3
 *   @0x254cb0 cmp r0, #2
 *   @0x254cb4 beq 0x254d24 <_Z14F_JSInstanceOfR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x254cb8 cmp r0, #1
 *   @0x254cbc str r5, [r4]
 *   @0x254cc0 moveq r3, #0
 *   @0x254cc4 movne r3, r5
 *   @0x254cc8 movteq r3, #0x3ff0
 *   @0x254ccc str r3, [r4, #0x4]
 *   @0x254cd0 pop {r3, r4, r5, pc}
 *   @0x254cd4 ldr r0, [pc, #0x58]
 *   @0x254cd8 pop {r3, r4, r5, lr}
 *   @0x254cdc add r0, pc, r0
 *   @0x254ce0 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x254ce4 ldr r0, [pc, #0x4c]
 *   @0x254ce8 pop {r3, r4, r5, lr}
 *   @0x254cec add r0, pc, r0
 *   @0x254cf0 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x254cf4 ldr r0, [pc, #0x40]
 *   @0x254cf8 pop {r3, r4, r5, lr}
 *   @0x254cfc add r0, pc, r0
 *   @0x254d00 b 0x254b04 <_Z21JSThrowReferenceErrorPKc>
 *   @0x254d04 ldr r0, [pc, #0x34]
 *   @0x254d08 pop {r3, r4, r5, lr}
 *   @0x254d0c add r0, pc, r0
 *   @0x254d10 b 0x254b04 <_Z21JSThrowReferenceErrorPKc>
 *   @0x254d14 ldr r0, [pc, #0x28]
 *   @0x254d18 pop {r3, r4, r5, lr}
 *   @0x254d1c add r0, pc, r0
 *   @0x254d20 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x254d24 ldr r0, [pc, #0x1c]
 *   @0x254d28 pop {r3, r4, r5, lr}
 *   @0x254d2c add r0, pc, r0
 *   @0x254d30 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x254d34 andseq r1, r0, r4, lsl #21
 *   @0x254d38 andseq r1, r0, r8, lsr #22
 *   @0x254d3c andseq r1, r0, r12, lsl r10
 *   @0x254d40 andseq r1, r0, r0, lsr r10
 *   @0x254d44 ldrheq r1, [r0], -r4
 *   @0x254d48 andseq r1, r0, r4, ror r10
 *
 * ══ §11/110 _spIkConstraintTimeline_apply  0x28242c  size 284  71 条（0x28242c..0x282548）
 * @func 0x28242c 0x282548  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spIkConstraintTimeline_apply+0x78 / anon_280ed0 / spCurveTimeline_getCurvePercent
 * 字段偏移 top8: 0x10×2 / 0xc×1 / 0x20×1 / 0x14×1 / 0x2×1
 * VFP 指令 41 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28242c push {r3, r4, r5, r6, r7, lr}
 *   @0x282430 vpush {d8}
 *   @0x282434 vmov s16, r3
 *   @0x282438 ldr r5, [r0, #0x10]
 *   @0x28243c vldr s15, [r5]
 *   @0x282440 vcmpe.f32 s15, s16
 *   @0x282444 mov r4, r0
 *   @0x282448 vmrs APSR_nzcv, fpscr
 *   @0x28244c bgt 0x28249c <_spIkConstraintTimeline_apply+0x70>
 *   @0x282450 ldr r2, [r0, #0xc]
 *   @0x282454 ldr r1, [r1, #0x20]
 *   @0x282458 sub r3, r2, #3
 *   @0x28245c ldr r0, [r0, #0x14]
 *   @0x282460 add r3, r5, r3, lsl #2
 *   @0x282464 vldr s15, [r3]
 *   @0x282468 vcmpe.f32 s16, s15
 *   @0x28246c ldr r6, [r1, r0, lsl #2]
 *   @0x282470 vmrs APSR_nzcv, fpscr
 *   @0x282474 blt 0x2824a4 <_spIkConstraintTimeline_apply+0x78>
 *   @0x282478 vldr s15, [r6, #20]
 *   @0x28247c vldr s14, [r3, #4]
 *   @0x282480 vsub.f32 s14, s14, s15
 *   @0x282484 vldr s13, [sp, #40]
 *   @0x282488 vmla.f32 s15, s14, s13
 *   @0x28248c vstr s15, [r6, #20]
 *   @0x282490 vldr s15, [r3, #8]
 *   @0x282494 vcvt.s32.f32 s15, s15
 *   @0x282498 vstr s15, [r6, #16]
 *   @0x28249c vpop {d8}
 *   @0x2824a0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2824a4 mov r1, r2
 *   @0x2824a8 vmov.f32 s0, s16
 *   @0x2824ac mov r0, r5
 *   @0x2824b0 mov r2, #3
 *   @0x2824b4 bl 0x280ed0 <printbuf_free+0x20>
 *   @0x2824b8 movw r2, #0x5556
 *   @0x2824bc movt r2, #0x5555
 *   @0x2824c0 vmov.f32 s14, #1.000000e+00
 *   @0x2824c4 sub r7, r0, #2
 *   @0x2824c8 mov r3, r0
 *   @0x2824cc smull r1, r2, r2, r3
 *   @0x2824d0 lsl r7, r7, #2
 *   @0x2824d4 add r5, r5, r7
 *   @0x2824d8 vldr s15, [r5, #8]
 *   @0x2824dc vldr s13, [r5, #-4]
 *   @0x2824e0 vsub.f32 s16, s16, s15
 *   @0x2824e4 mov r0, r4
 *   @0x2824e8 vldr s17, [r5]
 *   @0x2824ec sub r1, r2, r3, asr #31
 *   @0x2824f0 sub r1, r1, #1
 *   @0x2824f4 vsub.f32 s15, s13, s15
 *   @0x2824f8 vdiv.f32 s15, s16, s15
 *   @0x2824fc vsub.f32 s14, s14, s15
 *   @0x282500 vmov r2, s14
 *   @0x282504 bl 0x2818e0 <spCurveTimeline_getCurvePercent>
 *   @0x282508 ldr r3, [r4, #0x10]
 *   @0x28250c vldr s15, [r6, #20]
 *   @0x282510 add r7, r3, r7
 *   @0x282514 vldr s14, [r7, #12]
 *   @0x282518 vsub.f32 s14, s14, s17
 *   @0x28251c vmov s13, r0
 *   @0x282520 vmla.f32 s17, s14, s13
 *   @0x282524 vldr s14, [sp, #40]
 *   @0x282528 vsub.f32 s17, s17, s15
 *   @0x28252c vmla.f32 s15, s17, s14
 *   @0x282530 vpop {d8}
 *   @0x282534 vstr s15, [r6, #20]
 *   @0x282538 vldr s15, [r7, #4]
 *   @0x28253c vcvt.s32.f32 s15, s15
 *   @0x282540 vstr s15, [r6, #16]
 *   @0x282544 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §12/110 png_write_end  0x2b002c  size 284  71 条（0x2b002c..0x2b0148）
 * @func 0x2b002c 0x2b0148  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_tIME / 0xfedadcbc / png_write_iTXt / png_write_zTXt / png_write_tEXt / 0x47c3f6 / png_write_chunk
 * 字段偏移 top8: 0x8×4 / 0x4×2 / 0x38×2 / 0x30×1 / 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b002c push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b0030 mov r5, r1
 *   @0x2b0034 cmp r0, #0x0
 *   @0x2b0038 .word 0xf8d08081
 *   @0x2b003c ldrbeq r3, [pc, -r12, lsr #2]
 *   @0x2b0040 bmi 0x2b004a <png_write_end+0x1e>
 *   @0x2b0044 add r1, pc
 *   @0x2b0048 ldmdblt sp, {r0, r4, r5, r6, r7, r8, r11, r12, sp, lr, pc} ^
 *   @0x2b004c ldr.w r3, [r4, #0x12c]
 *   @0x2b0050 mov r0, r4
 *   @0x2b0054 .word 0xf8c40308
 *   @0x2b0058 andlt r3, r3, r12, lsr #2
 *   @0x2b005c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b0060 b.w 0x2b178c <png_write_IEND>
 *   @0x2b0064 ldr r3, [r5, #0x8]
 *   @0x2b0068 bpl 0x2b007c <png_write_end+0x50>
 *   @0x2b006c ldreq r3, [r8, #0x12c]
 *   @0x2b0070 bmi 0x2b007c <png_write_end+0x50>
 *   @0x2b0074 add.w r1, r5, #0x3c
 *   @0x2b0078 bl 0x2b2490 <png_write_tIME>
 *   @0x2b007c mov.w r8, #0x0
 *   @0x2b0080 mov.w r10, #0x1c
 *   @0x2b0084 mvn r9, #0x2
 *   @0x2b0088 mvn r11, #0x1
 *   @0x2b008c ldr r3, [r5, #0x30]
 *   @0x2b0090 bge 0x2b00e8 <png_write_end+0xbc>
 *   @0x2b0094 blvs 0xfedadcbc <b2_toiTime+0xfffffffffe654818>
 *   @0x2b0098 adds r6, r3, r7
 *   @0x2b009c cmp r3, #0x0
 *   @0x2b00a0 ldr r2, [r6, #0x18]
 *   @0x2b00a4 mov r0, r4
 *   @0x2b00a8 ldr r2, [r6, #0x8]
 *   @0x2b00ac ldr r2, [r6, #0x4]
 *   @0x2b00b0 bl 0x2b20b8 <png_write_iTXt>
 *   @0x2b00b4 b 0x2b00dc <png_write_end+0xb0>
 *   @0x2b00b8 str r3, [sp]
 *   @0x2b00bc ldr r1, [r6, #0x4]
 *   @0x2b00c0 bl 0x2b2004 <png_write_zTXt>
 *   @0x2b00c4 ldr r3, [r5, #0x38]
 *   @0x2b00c8 and r11, r10, r7
 *   @0x2b00cc adds r3, #0x1
 *   @0x2b00d0 mov r0, r4
 *   @0x2b00d4 ldr r2, [r6, #0x8]
 *   @0x2b00d8 bl 0x2b1f94 <png_write_tEXt>
 *   @0x2b00dc ldr r3, [r5, #0x38]
 *   @0x2b00e0 .word 0xf1089007
 *   @0x2b00e4 ldrb r0, [r1, r1, lsl #16]
 *   @0x2b00e8 ldr.w r3, [r5, #0xc0]
 *   @0x2b00ec cmp r3, #0x0
 *   @0x2b00f0 ldr.w r6, [r5, #0xbc]
 *   @0x2b00f4 movs r7, #0x14
 *   @0x2b00f8 .word 0xf8d520c0
 *   @0x2b00fc blx 0x47c3f6 <targetStr+0x11b6>
 *   @0x2b0100 addsmi r3, lr, #134217728
 *   @0x2b0104 bhs 0x2b004c <png_write_end+0x20>
 *   @0x2b0108 mov r1, r6
 *   @0x2b010c stmdahs r1, {r0, r1, r3, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2b0110 beq 0x2b0138 <png_write_end+0x10c>
 *   @0x2b0114 cbz r3, 0x2b0138 <png_write_end+0x10c>
 *   @0x2b0118 bpl 0x2b0138 <png_write_end+0x10c>
 *   @0x2b011c lsls r2, r3, #0x1a
 *   @0x2b0120 cmp r0, #0x3
 *   @0x2b0124 ldr.w r3, [r4, #0x130]
 *   @0x2b0128 lsls r3, r3, #0xf
 *   @0x2b012c mov r0, r4
 *   @0x2b0130 ldr r2, [r6, #0x8]
 *   @0x2b0134 bl 0x2b12bc <png_write_chunk>
 *   @0x2b0138 adds r6, #0x14
 *   @0x2b013c add sp, #0xc
 *   @0x2b0140 svclt #0x8ff0
 *   @0x2b0144 udf #0xe9
 *
 * ══ §13/110 b2MotorJoint::Dump()  0x2ce048  size 284  71 条（0x2ce048..0x2ce164）
 * @func 0x2ce048 0x2ce164  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×9
 * 字段偏移 top8: 0x34×2 / 0x8×2 / 0x30×1 / 0xd8×1 / 0xc8×1 / 0xbc×1 / 0xb0×1 / 0x3d×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce048 push {r4, r5, r6, lr}
 *   @0x2ce04c mov r4, r0
 *   @0x2ce050 ldr r2, [r4, #0x30]
 *   @0x2ce054 sub sp, sp, #8
 *   @0x2ce058 ldr r3, [r4, #0x34]
 *   @0x2ce05c ldr r0, [pc, #0xd8]
 *   @0x2ce060 ldr r6, [r2, #0x8]
 *   @0x2ce064 add r0, pc, r0
 *   @0x2ce068 ldr r5, [r3, #0x8]
 *   @0x2ce06c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ce070 ldr r0, [pc, #0xc8]
 *   @0x2ce074 mov r1, r6
 *   @0x2ce078 add r0, pc, r0
 *   @0x2ce07c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ce080 ldr r0, [pc, #0xbc]
 *   @0x2ce084 mov r1, r5
 *   @0x2ce088 add r0, pc, r0
 *   @0x2ce08c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ce090 ldr r0, [pc, #0xb0]
 *   @0x2ce094 ldrb r1, [r4, #0x3d]
 *   @0x2ce098 add r0, pc, r0
 *   @0x2ce09c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ce0a0 vldr s14, [r4, #72]
 *   @0x2ce0a4 vcvt.f64.f32 d7, s14
 *   @0x2ce0a8 vldr s13, [r4, #68]
 *   @0x2ce0ac ldr r0, [pc, #0x98]
 *   @0x2ce0b0 add r0, pc, r0
 *   @0x2ce0b4 vstr d7, [sp]
 *   @0x2ce0b8 vcvt.f64.f32 d7, s13
 *   @0x2ce0bc vmov r2, r3, d7
 *   @0x2ce0c0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ce0c4 vldr s15, [r4, #76]
 *   @0x2ce0c8 vcvt.f64.f32 d6, s15
 *   @0x2ce0cc ldr r0, [pc, #0x7c]
 *   @0x2ce0d0 add r0, pc, r0
 *   @0x2ce0d4 vmov r2, r3, d6
 *   @0x2ce0d8 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ce0dc vldr s15, [r4, #92]
 *   @0x2ce0e0 vcvt.f64.f32 d6, s15
 *   @0x2ce0e4 ldr r0, [pc, #0x68]
 *   @0x2ce0e8 add r0, pc, r0
 *   @0x2ce0ec vmov r2, r3, d6
 *   @0x2ce0f0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ce0f4 vldr s15, [r4, #96]
 *   @0x2ce0f8 vcvt.f64.f32 d6, s15
 *   @0x2ce0fc ldr r0, [pc, #0x54]
 *   @0x2ce100 add r0, pc, r0
 *   @0x2ce104 vmov r2, r3, d6
 *   @0x2ce108 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ce10c vldr s15, [r4, #100]
 *   @0x2ce110 vcvt.f64.f32 d6, s15
 *   @0x2ce114 ldr r0, [pc, #0x40]
 *   @0x2ce118 add r0, pc, r0
 *   @0x2ce11c vmov r2, r3, d6
 *   @0x2ce120 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ce124 ldr r0, [pc, #0x34]
 *   @0x2ce128 ldr r1, [r4, #0x38]
 *   @0x2ce12c add r0, pc, r0
 *   @0x2ce130 add sp, sp, #8
 *   @0x2ce134 pop {r4, r5, r6, lr}
 *   @0x2ce138 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ce13c ldrdeq sp, lr, [r8], -r4
 *   @0x2ce140 andeq sp, r8, r4, lsr lr
 *   @0x2ce144 andeq sp, r8, r0, asr #28
 *   @0x2ce148 andeq sp, r8, r12, asr #28
 *   @0x2ce14c andeq sp, r8, r0, lsr #31
 *   @0x2ce150 andeq sp, r8, r12, lsr #31
 *   @0x2ce154 andeq sp, r8, r8, lsl pc
 *   @0x2ce158 andeq sp, r8, r12, lsl pc
 *   @0x2ce15c andeq sp, r8, r4, lsl #31
 *   @0x2ce160 andeq sp, r8, r12, lsl #29
 *
 * ══ §14/110 Init_Vertex_Write(RValue&, int, RValue*, int)  0xc9188  size 280  70 条（0xc9188..0xc92a0）
 * @func 0xc9188 0xc92a0  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×3 / YYGetInt32(RValue const*, int) / GetBufferVertex(int) / GetVertexFormat(int) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x18×2 / 0x20×1 / 0x24×1 / 0x94×1 / 0x14×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9188 cmp r1, r3
 *   @0xc918c push {r4, r5, lr}
 *   @0xc9190 mov r4, #0
 *   @0xc9194 sub sp, sp, #12
 *   @0xc9198 str r4, [r0, #0xc]
 *   @0xc919c str r4, [r0]
 *   @0xc91a0 str r4, [r0, #0x4]
 *   @0xc91a4 bne 0xc91f4 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x6c>
 *   @0xc91a8 mov r0, r2
 *   @0xc91ac mov r1, r4
 *   @0xc91b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc91b4 bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xc91b8 subs r5, r0, #0
 *   @0xc91bc beq 0xc9264 <_Z17Init_Vertex_WriteR6RValueiPS_i+0xdc>
 *   @0xc91c0 ldrb r4, [r5, #0x20]
 *   @0xc91c4 cmp r4, #0
 *   @0xc91c8 bne 0xc9264 <_Z17Init_Vertex_WriteR6RValueiPS_i+0xdc>
 *   @0xc91cc ldr r0, [r5, #0x24]
 *   @0xc91d0 cmn r0, #1
 *   @0xc91d4 beq 0xc927c <_Z17Init_Vertex_WriteR6RValueiPS_i+0xf4>
 *   @0xc91d8 ldr r4, [r5, #0x18]
 *   @0xc91dc cmp r4, #0
 *   @0xc91e0 beq 0xc9210 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x88>
 *   @0xc91e4 mov r4, r5
 *   @0xc91e8 mov r0, r4
 *   @0xc91ec add sp, sp, #12
 *   @0xc91f0 pop {r4, r5, pc}
 *   @0xc91f4 ldr r0, [pc, #0x94]
 *   @0xc91f8 mov r1, #1
 *   @0xc91fc add r0, pc, r0
 *   @0xc9200 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc9204 mov r0, r4
 *   @0xc9208 add sp, sp, #12
 *   @0xc920c pop {r4, r5, pc}
 *   @0xc9210 bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0xc9214 cmp r0, #0
 *   @0xc9218 beq 0xc91e4 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x5c>
 *   @0xc921c ldr r2, [r0, #0x14]
 *   @0xc9220 ldr r1, [r5, #0xc]
 *   @0xc9224 ldr r3, [r5, #0x4]
 *   @0xc9228 add r1, r2, r1
 *   @0xc922c cmp r3, r1
 *   @0xc9230 bhs 0xc91e4 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x5c>
 *   @0xc9234 add r2, r2, r3
 *   @0xc9238 ldr r0, [r5]
 *   @0xc923c add r1, r2, r3, lsr #1
 *   @0xc9240 ldr r2, [pc, #0x4c]
 *   @0xc9244 str r1, [r5, #0x4]
 *   @0xc9248 mov r3, #74
 *   @0xc924c str r4, [sp]
 *   @0xc9250 add r2, pc, r2
 *   @0xc9254 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc9258 mov r4, r5
 *   @0xc925c str r0, [r5]
 *   @0xc9260 b 0xc91e8 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x60>
 *   @0xc9264 ldr r0, [pc, #0x2c]
 *   @0xc9268 mov r1, #1
 *   @0xc926c mov r4, #0
 *   @0xc9270 add r0, pc, r0
 *   @0xc9274 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc9278 b 0xc91e8 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x60>
 *   @0xc927c ldr r0, [pc, #0x18]
 *   @0xc9280 mov r1, #1
 *   @0xc9284 add r0, pc, r0
 *   @0xc9288 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc928c b 0xc91e8 <_Z17Init_Vertex_WriteR6RValueiPS_i+0x60>
 *   @0xc9290 eoreq r8, r6, r4, ror #22
 *   @0xc9294 eoreq r7, r6, r0, ror #27
 *   @0xc9298 eoreq r8, r6, r8, lsl r11
 *   @0xc929c eoreq r8, r6, r8, lsr r11
 *
 * ══ §15/110 CFontGM::GetGlyph(int)  0xf6d60  size 280  70 条（0xf6d60..0xf6e78）
 * @func 0xf6d60 0xf6e78  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::GetGlyph(int)+0x34 / CFontGM::GetGlyph(int) / YYFTGlyphCache::GetLRUSlot(YYGlyph2*, int, bool)
 * 字段偏移 top8: 0x2×3 / 0x8c×2 / 0x40×1 / 0x44×1 / 0x14×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf6d60 ldr r12, [r0, #0x40]
 *   @0xf6d64 push {r4, r5, r6, r7, r8, lr}
 *   @0xf6d68 subs r12, r12, #1
 *   @0xf6d6c mov r6, r0
 *   @0xf6d70 bmi 0xf6e68 <_ZN7CFontGM8GetGlyphEi+0x108>
 *   @0xf6d74 ldr r0, [r0, #0x44]
 *   @0xf6d78 asr r4, r12, #1
 *   @0xf6d7c ldr r5, [r0, r4, lsl #2]
 *   @0xf6d80 ldrh r2, [r5]
 *   @0xf6d84 cmp r2, r1
 *   @0xf6d88 beq 0xf6de4 <_ZN7CFontGM8GetGlyphEi+0x84>
 *   @0xf6d8c mov r3, #0
 *   @0xf6d90 b 0xf6da8 <_ZN7CFontGM8GetGlyphEi+0x48>
 *   @0xf6d94 add r4, r3, r2, asr #1
 *   @0xf6d98 ldr r5, [r0, r4, lsl #2]
 *   @0xf6d9c ldrh r2, [r5]
 *   @0xf6da0 cmp r2, r1
 *   @0xf6da4 beq 0xf6de4 <_ZN7CFontGM8GetGlyphEi+0x84>
 *   @0xf6da8 cmp r1, r2
 *   @0xf6dac sublt r12, r4, #1
 *   @0xf6db0 addge r3, r4, #1
 *   @0xf6db4 rsb r2, r3, r12
 *   @0xf6db8 cmp r3, r12
 *   @0xf6dbc add r2, r2, r2, lsr #31
 *   @0xf6dc0 ble 0xf6d94 <_ZN7CFontGM8GetGlyphEi+0x34>
 *   @0xf6dc4 movw r3, #0x25af
 *   @0xf6dc8 cmp r1, r3
 *   @0xf6dcc moveq r5, #0
 *   @0xf6dd0 beq 0xf6e20 <_ZN7CFontGM8GetGlyphEi+0xc0>
 *   @0xf6dd4 mov r1, r3
 *   @0xf6dd8 mov r0, r6
 *   @0xf6ddc bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi>
 *   @0xf6de0 mov r5, r0
 *   @0xf6de4 cmp r5, #0
 *   @0xf6de8 beq 0xf6e20 <_ZN7CFontGM8GetGlyphEi+0xc0>
 *   @0xf6dec ldr r7, [r6, #0x8c]
 *   @0xf6df0 cmp r7, #0
 *   @0xf6df4 beq 0xf6e20 <_ZN7CFontGM8GetGlyphEi+0xc0>
 *   @0xf6df8 ldrsh r3, [r5, #2]
 *   @0xf6dfc cmn r3, #1
 *   @0xf6e00 beq 0xf6e28 <_ZN7CFontGM8GetGlyphEi+0xc8>
 *   @0xf6e04 lsl r8, r4, #2
 *   @0xf6e08 ldr r2, [r7, r8]
 *   @0xf6e0c cmp r2, #0
 *   @0xf6e10 ldrne r3, [pc, #0x58]
 *   @0xf6e14 ldrne r3, [pc, r3]
 *   @0xf6e18 ldrne r3, [r3]
 *   @0xf6e1c strne r3, [r2, #0x14]
 *   @0xf6e20 mov r0, r5
 *   @0xf6e24 pop {r4, r5, r6, r7, r8, pc}
 *   @0xf6e28 ldrsh r3, [r5, #4]
 *   @0xf6e2c cmn r3, #1
 *   @0xf6e30 bne 0xf6e04 <_ZN7CFontGM8GetGlyphEi+0xa4>
 *   @0xf6e34 ldr r3, [r6, #0x14]
 *   @0xf6e38 add r0, r6, #92
 *   @0xf6e3c ldr r2, [pc, #0x30]
 *   @0xf6e40 mov r1, r5
 *   @0xf6e44 adds r3, r3, #0
 *   @0xf6e48 lsl r8, r4, #2
 *   @0xf6e4c ldr r2, [pc, r2]
 *   @0xf6e50 movne r3, #1
 *   @0xf6e54 ldr r2, [r2]
 *   @0xf6e58 bl 0xf68c8 <_ZN14YYFTGlyphCache10GetLRUSlotEP8YYGlyph2ib>
 *   @0xf6e5c str r0, [r7, r4, lsl #2]
 *   @0xf6e60 ldr r7, [r6, #0x8c]
 *   @0xf6e64 b 0xf6e08 <_ZN7CFontGM8GetGlyphEi+0xa8>
 *   @0xf6e68 mov r4, #0
 *   @0xf6e6c b 0xf6dc4 <_ZN7CFontGM8GetGlyphEi+0x64>
 *   @0xf6e70 eoreq r7, pc, r0, lsr r0
 *   @0xf6e74 .word 0x002f6ff8
 *
 * ══ §16/110 F_SpriteAddFromSurface(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f3a8  size 280  70 条（0x12f3a8..0x12f4c0）
 * @func 0x12f3a8 0x12f4c0  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×8 / Sprite_Data(int) / GR_Surface_Screenshot_Part(int, int, int, int, int) / CSprite::AddFromBitmap(IBitmap*, bool, bool, bool)
 * 字段偏移 top8: 0x28×1 / 0x74×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f3a8 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x12f3ac sub sp, sp, #12
 *   @0x12f3b0 mov r1, #0
 *   @0x12f3b4 ldr r4, [sp, #0x28]
 *   @0x12f3b8 mov r0, r4
 *   @0x12f3bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f3c0 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12f3c4 subs r5, r0, #0
 *   @0x12f3c8 beq 0x12f49c <_Z22F_SpriteAddFromSurfaceR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x12f3cc ldr r3, [r5, #0x74]
 *   @0x12f3d0 cmp r3, #0
 *   @0x12f3d4 bne 0x12f4a4 <_Z22F_SpriteAddFromSurfaceR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x12f3d8 mov r1, #1
 *   @0x12f3dc mov r0, r4
 *   @0x12f3e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f3e4 mov r1, #2
 *   @0x12f3e8 mov r6, r0
 *   @0x12f3ec mov r0, r4
 *   @0x12f3f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f3f4 mov r1, #3
 *   @0x12f3f8 mov r9, r0
 *   @0x12f3fc mov r0, r4
 *   @0x12f400 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f404 mov r1, #4
 *   @0x12f408 mov r8, r0
 *   @0x12f40c mov r0, r4
 *   @0x12f410 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f414 mov r1, #5
 *   @0x12f418 mov r7, r0
 *   @0x12f41c mov r0, r4
 *   @0x12f420 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f424 mov r1, r9
 *   @0x12f428 mov r2, r8
 *   @0x12f42c mov r3, r7
 *   @0x12f430 str r0, [sp]
 *   @0x12f434 mov r0, r6
 *   @0x12f438 bl 0x1720e4 <_Z26GR_Surface_Screenshot_Partiiiii>
 *   @0x12f43c subs r6, r0, #0
 *   @0x12f440 beq 0x12f49c <_Z22F_SpriteAddFromSurfaceR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x12f444 mov r1, #6
 *   @0x12f448 mov r0, r4
 *   @0x12f44c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f450 mov r1, #7
 *   @0x12f454 cmp r0, #0
 *   @0x12f458 mov r0, r4
 *   @0x12f45c movle r7, #0
 *   @0x12f460 movgt r7, #1
 *   @0x12f464 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f468 eor r3, r7, #1
 *   @0x12f46c mov r2, r7
 *   @0x12f470 str r3, [sp]
 *   @0x12f474 mov r1, r6
 *   @0x12f478 cmp r0, #0
 *   @0x12f47c mov r0, r5
 *   @0x12f480 movle r3, #0
 *   @0x12f484 movgt r3, #1
 *   @0x12f488 bl 0x1e5988 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb>
 *   @0x12f48c ldr r3, [r6]
 *   @0x12f490 mov r0, r6
 *   @0x12f494 ldr r3, [r3, #0x4]
 *   @0x12f498 blx r3
 *   @0x12f49c add sp, sp, #12
 *   @0x12f4a0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x12f4a4 ldr r0, [pc, #0x10]
 *   @0x12f4a8 mov r1, #0
 *   @0x12f4ac add r0, pc, r0
 *   @0x12f4b0 add sp, sp, #12
 *   @0x12f4b4 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x12f4b8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12f4bc eoreq lr, r0, r8, lsr r4
 *
 * ══ §17/110 F_FilenameChangeExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x1388cc  size 280  70 条（0x1388cc..0x1389e4）
 * @func 0x1388cc 0x1389e4  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×3 / YYGetString(RValue const*, int)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb6868 / 0xb6568
 * 字段偏移 top8: 0x18×2 / 0xc×1 / 0xa4×1 / 0x54×1 / 0x20×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1388cc push {r4, r5, r6, r7, r8, lr}
 *   @0x1388d0 mov r1, #0
 *   @0x1388d4 ldr r6, [sp, #0x18]
 *   @0x1388d8 mov r5, #1
 *   @0x1388dc str r1, [r0]
 *   @0x1388e0 str r5, [r0, #0xc]
 *   @0x1388e4 mov r0, r6
 *   @0x1388e8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1388ec mov r1, r5
 *   @0x1388f0 mov r4, r0
 *   @0x1388f4 mov r0, r6
 *   @0x1388f8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1388fc cmp r4, #0
 *   @0x138900 mov r6, r0
 *   @0x138904 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x138908 mov r0, r4
 *   @0x13890c mov r1, #46
 *   @0x138910 bl 0xb6868 <strrchr@plt>
 *   @0x138914 subs r7, r0, #0
 *   @0x138918 beq 0x138964 <_Z19F_FilenameChangeExtR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x13891c mov r0, r6
 *   @0x138920 rsb r7, r4, r7
 *   @0x138924 bl 0xb6538 <strlen@plt>
 *   @0x138928 ldr r1, [pc, #0xa4]
 *   @0x13892c add r12, r7, #2
 *   @0x138930 mov r3, r5
 *   @0x138934 add r1, pc, r1
 *   @0x138938 movw r2, #0x6a5
 *   @0x13893c add r0, r12, r0
 *   @0x138940 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x138944 mov r1, r4
 *   @0x138948 mov r2, r7
 *   @0x13894c mov r5, r0
 *   @0x138950 bl 0xb6568 <strncpy@plt>
 *   @0x138954 mov r0, r5
 *   @0x138958 mov r1, r6
 *   @0x13895c pop {r4, r5, r6, r7, r8, lr}
 *   @0x138960 b 0xb6628 <strcat@plt>
 *   @0x138964 mov r0, r4
 *   @0x138968 bl 0xb6538 <strlen@plt>
 *   @0x13896c mov r7, r0
 *   @0x138970 mov r0, r6
 *   @0x138974 bl 0xb6538 <strlen@plt>
 *   @0x138978 mov r3, r5
 *   @0x13897c ldr r1, [pc, #0x54]
 *   @0x138980 movw r2, #0x6ab
 *   @0x138984 add r1, pc, r1
 *   @0x138988 add r0, r7, r0
 *   @0x13898c add r5, r0, #2
 *   @0x138990 mov r0, r5
 *   @0x138994 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x138998 ldrb r3, [r6]
 *   @0x13899c mov r1, r5
 *   @0x1389a0 str r6, [sp, #0x18]
 *   @0x1389a4 cmp r3, #46
 *   @0x1389a8 cmpne r3, #0
 *   @0x1389ac mov r3, r4
 *   @0x1389b0 beq 0x1389c4 <_Z19F_FilenameChangeExtR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x1389b4 ldr r2, [pc, #0x20]
 *   @0x1389b8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1389bc add r2, pc, r2
 *   @0x1389c0 b 0xb65c8 <snprintf@plt>
 *   @0x1389c4 ldr r2, [pc, #0x14]
 *   @0x1389c8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1389cc add r2, pc, r2
 *   @0x1389d0 b 0xb65c8 <snprintf@plt>
 *   @0x1389d4 eoreq r7, r0, r12, lsl r7
 *   @0x1389d8 eoreq r7, r0, r12, asr #13
 *   @0x1389dc .word 0x002076f4
 *   @0x1389e0 andseq r12, pc, r8, lsl #4
 *
 * ══ §18/110 F_FileFindFirst(RValue&, CInstance*, CInstance*, int, RValue*)  0x13ab10  size 280  70 条（0x13ab10..0x13ac28）
 * @func 0x13ab10 0x13ac28  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYGetReal(RValue const*, int) / yyFindData::Reset() / LoadSave::_GetSaveFileName(char*, int, char const*) / LoadSave::_GetBundleFileName(char*, int, char const*) / CreateFindData(yyFindData*, char const*, char const*, double) / YYCreateString(RValue*, char const*) / 0xb65d4
 * 字段偏移 top8: 0xc×3 / 0x8×3 / 0x814×2 / 0xfc×1 / 0xf8×1 / 0x840×1 / 0xbc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ab10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13ab14 sub sp, sp, #2064
 *   @0x13ab18 ldr r7, [pc, #0xfc]
 *   @0x13ab1c sub sp, sp, #12
 *   @0x13ab20 ldr r8, [pc, #0xf8]
 *   @0x13ab24 mov r3, #0
 *   @0x13ab28 ldr r7, [pc, r7]
 *   @0x13ab2c ldr r4, [sp, #0x840]
 *   @0x13ab30 mov r10, r0
 *   @0x13ab34 ldr r8, [pc, r8]
 *   @0x13ab38 ldr r2, [r7]
 *   @0x13ab3c mov r1, r3
 *   @0x13ab40 str r3, [r0]
 *   @0x13ab44 mov r9, #1
 *   @0x13ab48 mov r0, r4
 *   @0x13ab4c str r9, [r10, #0xc]
 *   @0x13ab50 strb r3, [r8]
 *   @0x13ab54 str r2, [sp, #0x814]
 *   @0x13ab58 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13ab5c mov r1, r9
 *   @0x13ab60 ldr r6, [pc, #0xbc]
 *   @0x13ab64 mov r11, r0
 *   @0x13ab68 mov r0, r4
 *   @0x13ab6c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13ab70 ldr r6, [pc, r6]
 *   @0x13ab74 mov r4, r0
 *   @0x13ab78 mov r0, r6
 *   @0x13ab7c mov r5, r1
 *   @0x13ab80 bl 0x13aac0 <_ZN10yyFindData5ResetEv>
 *   @0x13ab84 add r12, sp, #20
 *   @0x13ab88 mov r2, r11
 *   @0x13ab8c mov r1, #1024
 *   @0x13ab90 str r12, [sp, #0x8]
 *   @0x13ab94 mov r0, r12
 *   @0x13ab98 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x13ab9c add r3, sp, #1040
 *   @0x13aba0 add r3, r3, #8
 *   @0x13aba4 mov r2, r11
 *   @0x13aba8 sub r3, r3, #4
 *   @0x13abac mov r1, #1024
 *   @0x13abb0 str r3, [sp, #0xc]
 *   @0x13abb4 mov r0, r3
 *   @0x13abb8 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x13abbc ldr r3, [sp, #0xc]
 *   @0x13abc0 ldr r12, [sp, #0x8]
 *   @0x13abc4 mov r0, r6
 *   @0x13abc8 strd r4, r5, [sp]
 *   @0x13abcc mov r2, r3
 *   @0x13abd0 mov r1, r12
 *   @0x13abd4 bl 0x160818 <_Z14CreateFindDataP10yyFindDataPKcS2_d>
 *   @0x13abd8 ldr r3, [r6]
 *   @0x13abdc ldr r2, [r6, #0x4]
 *   @0x13abe0 cmp r3, r2
 *   @0x13abe4 bge 0x13abfc <_Z15F_FileFindFirstR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x13abe8 ldr r2, [r6, #0x8]
 *   @0x13abec mov r0, r10
 *   @0x13abf0 strb r9, [r8]
 *   @0x13abf4 ldr r1, [r2, r3, lsl #2]
 *   @0x13abf8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x13abfc ldr r2, [sp, #0x814]
 *   @0x13ac00 ldr r3, [r7]
 *   @0x13ac04 cmp r2, r3
 *   @0x13ac08 bne 0x13ac18 <_Z15F_FileFindFirstR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x13ac0c add sp, sp, #2064
 *   @0x13ac10 add sp, sp, #12
 *   @0x13ac14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13ac18 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13ac1c eoreq r2, r11, r8, lsr #28
 *   @0x13ac20 eoreq r4, r11, r0, asr r7
 *   @0x13ac24 eoreq r4, r11, r8, lsl r7
 *
 * ══ §19/110 F_ActionDrawTextTransformed(RValue&, CInstance*, CInstance*, int, RValue*)  0x140270  size 280  70 条（0x140270..0x140388）
 * @func 0x140270 0x140388  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / GR_Text_Draw_Transformed(float, float, char const*, int, int, float, float, float) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x18×4 / 0xfc×1 / 0x14×1 / 0x40×1 / 0x-4×1 / 0x5c×1 / 0x4×1 / 0x8×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140270 push {r4, r5, r6, r7, lr}
 *   @0x140274 vpush {d8}
 *   @0x140278 mov r7, r1
 *   @0x14027c ldr r1, [pc, #0xfc]
 *   @0x140280 sub sp, sp, #36
 *   @0x140284 mov r12, #16
 *   @0x140288 movw r2, #0x811
 *   @0x14028c mov r0, r12
 *   @0x140290 add r1, pc, r1
 *   @0x140294 mov r3, #1
 *   @0x140298 str r12, [sp, #0x14]
 *   @0x14029c ldr r4, [sp, #0x40]
 *   @0x1402a0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1402a4 add r1, sp, #24
 *   @0x1402a8 mov r2, #0
 *   @0x1402ac mov r3, r0
 *   @0x1402b0 add r0, sp, #32
 *   @0x1402b4 str r3, [sp, #0x18]
 *   @0x1402b8 str r3, [r0, #-0x4]!
 *   @0x1402bc strb r2, [r3]
 *   @0x1402c0 mov r3, r4
 *   @0x1402c4 add r2, sp, #20
 *   @0x1402c8 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x1402cc ldr r0, [sp, #0x18]
 *   @0x1402d0 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x1402d4 mov r0, r4
 *   @0x1402d8 mov r1, #1
 *   @0x1402dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1402e0 mov r1, #2
 *   @0x1402e4 vmov s17, r0
 *   @0x1402e8 mov r0, r4
 *   @0x1402ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1402f0 mov r1, #3
 *   @0x1402f4 vmov s16, r0
 *   @0x1402f8 mov r0, r4
 *   @0x1402fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140300 mov r1, #4
 *   @0x140304 mov r6, r0
 *   @0x140308 mov r0, r4
 *   @0x14030c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140310 mov r1, #5
 *   @0x140314 mov r5, r0
 *   @0x140318 mov r0, r4
 *   @0x14031c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140320 ldr r3, [pc, #0x5c]
 *   @0x140324 ldr r2, [sp, #0x18]
 *   @0x140328 ldr r3, [pc, r3]
 *   @0x14032c ldrb r3, [r3]
 *   @0x140330 str r6, [sp, #0x4]
 *   @0x140334 cmp r3, #0
 *   @0x140338 str r5, [sp, #0x8]
 *   @0x14033c mvn r3, #0
 *   @0x140340 str r3, [sp]
 *   @0x140344 vmoveq r1, s16
 *   @0x140348 str r0, [sp, #0xc]
 *   @0x14034c vldrne s14, [r7, #180]
 *   @0x140350 vldrne s15, [r7, #184]
 *   @0x140354 vaddne.f32 s14, s17, s14
 *   @0x140358 vmoveq r0, s17
 *   @0x14035c vaddne.f32 s15, s16, s15
 *   @0x140360 vmovne r0, s14
 *   @0x140364 vmovne r1, s15
 *   @0x140368 bl 0x173068 <_Z24GR_Text_Draw_TransformedffPKciifff>
 *   @0x14036c ldr r0, [sp, #0x18]
 *   @0x140370 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x140374 add sp, sp, #36
 *   @0x140378 vpop {d8}
 *   @0x14037c pop {r4, r5, r6, r7, pc}
 *   @0x140380 eoreq r0, r0, r12, asr r6
 *   @0x140384 eoreq sp, r10, r4, lsl r8
 *
 * ══ §20/110 GR_Texture_End()  0x1740e0  size 280  70 条（0x1740e0..0x1741f8）
 * @func 0x1740e0 0x1741f8  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / GR_Texture_End()+0x34 / GR_Texture_Free(int) / GR_Texture_End()+0x80 / operator delete(void*)
 * 字段偏移 top8: 0x4×7 / 0x2×2 / 0x8×2 / 0x100×1 / 0xd4×1 / 0x80×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1740e0 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1740e4 ldr r7, [pc, #0x100]
 *   @0x1740e8 ldr r7, [pc, r7]
 *   @0x1740ec ldr r3, [r7]
 *   @0x1740f0 cmp r3, #0
 *   @0x1740f4 movgt r4, #0
 *   @0x1740f8 ble 0x174114 <_Z14GR_Texture_Endv+0x34>
 *   @0x1740fc mov r0, r4
 *   @0x174100 add r4, r4, #1
 *   @0x174104 bl 0x173f84 <_Z15GR_Texture_Freei>
 *   @0x174108 ldr r3, [r7]
 *   @0x17410c cmp r3, r4
 *   @0x174110 bgt 0x1740fc <_Z14GR_Texture_Endv+0x1c>
 *   @0x174114 ldr r5, [pc, #0xd4]
 *   @0x174118 ldr r5, [pc, r5]
 *   @0x17411c ldr r0, [r5, #0x4]
 *   @0x174120 cmp r0, #0
 *   @0x174124 beq 0x17416c <_Z14GR_Texture_Endv+0x8c>
 *   @0x174128 ldr r3, [r5]
 *   @0x17412c cmp r3, #0
 *   @0x174130 ble 0x174160 <_Z14GR_Texture_Endv+0x80>
 *   @0x174134 mov r4, #0
 *   @0x174138 mov r6, r4
 *   @0x17413c ldr r0, [r0, r4, lsl #2]
 *   @0x174140 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x174144 ldr r2, [r5, #0x4]
 *   @0x174148 ldr r3, [r5]
 *   @0x17414c str r6, [r2, r4, lsl #2]
 *   @0x174150 add r4, r4, #1
 *   @0x174154 cmp r3, r4
 *   @0x174158 ldr r0, [r5, #0x4]
 *   @0x17415c bgt 0x17413c <_Z14GR_Texture_Endv+0x5c>
 *   @0x174160 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x174164 mov r3, #0
 *   @0x174168 str r3, [r5, #0x4]
 *   @0x17416c ldr r6, [pc, #0x80]
 *   @0x174170 mov r9, #0
 *   @0x174174 str r9, [r5]
 *   @0x174178 ldr r6, [pc, r6]
 *   @0x17417c str r9, [r7]
 *   @0x174180 ldr r8, [r6, #0x4]
 *   @0x174184 cmp r8, r9
 *   @0x174188 poplt {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x17418c lsl r7, r8, #3
 *   @0x174190 ldr r3, [r6]
 *   @0x174194 add r2, r3, r7
 *   @0x174198 ldr r4, [r3, r7]
 *   @0x17419c str r9, [r3, r7]
 *   @0x1741a0 cmp r4, #0
 *   @0x1741a4 str r9, [r2, #0x4]
 *   @0x1741a8 beq 0x1741d8 <_Z14GR_Texture_Endv+0xf8>
 *   @0x1741ac ldr r5, [r4, #0x4]
 *   @0x1741b0 ldr r0, [r4, #0xc]
 *   @0x1741b4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1741b8 mov r0, r4
 *   @0x1741bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1741c0 ldr r3, [r6, #0x8]
 *   @0x1741c4 cmp r5, #0
 *   @0x1741c8 mov r4, r5
 *   @0x1741cc sub r3, r3, #1
 *   @0x1741d0 str r3, [r6, #0x8]
 *   @0x1741d4 bne 0x1741ac <_Z14GR_Texture_Endv+0xcc>
 *   @0x1741d8 sub r8, r8, #1
 *   @0x1741dc sub r7, r7, #8
 *   @0x1741e0 cmn r8, #1
 *   @0x1741e4 bne 0x174190 <_Z14GR_Texture_Endv+0xb0>
 *   @0x1741e8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1741ec eoreq r12, r7, r8, asr #3
 *   @0x1741f0 eoreq r9, r7, r4, lsl #16
 *   @0x1741f4 mlaeq r7, r8, r9, r9
 *
 * ══ §21/110 GraphicsPerf::GenerateMemoryPerf()  0x17bf18  size 280  70 条（0x17bf18..0x17c030）
 * @func 0x17bf18 0x17c030  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17bf20→0x756758, 0x17bf24→0x3f26b8, 0x17bf58→0x4a2044, 0x17bf60→0x4a2040, 0x17bf8c→0x544b70, 0x17bfac→0x756748, 0x17bfd0→0x756754
 * 调用序列: GraphicsPerf::AddMemoryBar(int, unsigned int, void*)×3 / GraphicsPerf::GenerateMemoryPerf()+0x2c / Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0xec×3 / 0xbc×1 / 0xb8×1 / 0x90×1 / 0x74×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17bf18 push {r3, r4, r5, r6, r7, lr}
 *   @0x17bf1c ldr r4, [pc, #0xec]
 *   @0x17bf20 ldr r3, [pc, #0xec]
 *   @0x17bf24 ldr r2, [pc, #0xec]
 *   @0x17bf28 add r4, pc, r4
 *   @0x17bf2c ldr r6, [r4, r3]
 *   @0x17bf30 ldr r0, [r4, r2]
 *   @0x17bf34 ldr r1, [r6]
 *   @0x17bf38 ldr r3, [r0]
 *   @0x17bf3c cmp r3, r1
 *   @0x17bf40 bhs 0x17bf58 <_ZN12GraphicsPerf18GenerateMemoryPerfEv+0x40>
 *   @0x17bf44 add r2, r3, r3, lsl #1
 *   @0x17bf48 cmp r2, r1
 *   @0x17bf4c mov r3, r2
 *   @0x17bf50 blo 0x17bf44 <_ZN12GraphicsPerf18GenerateMemoryPerfEv+0x2c>
 *   @0x17bf54 str r2, [r0]
 *   @0x17bf58 ldr r0, [pc, #0xbc]
 *   @0x17bf5c mov r12, #0
 *   @0x17bf60 ldr lr, [pc, #0xb8]
 *   @0x17bf64 mov r1, r12
 *   @0x17bf68 mov r2, #24
 *   @0x17bf6c mov r7, #0
 *   @0x17bf70 ldr r5, [r4, r0]
 *   @0x17bf74 mov r3, r2
 *   @0x17bf78 mov r0, #4
 *   @0x17bf7c str r12, [r5]
 *   @0x17bf80 ldr r12, [r4, lr]
 *   @0x17bf84 str r7, [r12]
 *   @0x17bf88 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x17bf8c ldr r3, [pc, #0x90]
 *   @0x17bf90 mov r1, #0
 *   @0x17bf94 movt r1, #0xffff
 *   @0x17bf98 ldr r7, [r4, r3]
 *   @0x17bf9c mov r5, r0
 *   @0x17bfa0 mov r2, r0
 *   @0x17bfa4 ldr r0, [r7]
 *   @0x17bfa8 bl 0x17bdf4 <_ZN12GraphicsPerf12AddMemoryBarEijPv>
 *   @0x17bfac ldr r0, [pc, #0x74]
 *   @0x17bfb0 ldr r3, [r7]
 *   @0x17bfb4 add r2, r5, #144
 *   @0x17bfb8 mov r1, #65280
 *   @0x17bfbc movt r1, #0xff00
 *   @0x17bfc0 ldr r7, [r4, r0]
 *   @0x17bfc4 ldr r0, [r7]
 *   @0x17bfc8 rsb r0, r3, r0
 *   @0x17bfcc bl 0x17bdf4 <_ZN12GraphicsPerf12AddMemoryBarEijPv>
 *   @0x17bfd0 ldr r0, [pc, #0x54]
 *   @0x17bfd4 ldr r3, [r7]
 *   @0x17bfd8 add r2, r5, #288
 *   @0x17bfdc mvn r1, #255
 *   @0x17bfe0 ldr r4, [r4, r0]
 *   @0x17bfe4 ldr r0, [r4]
 *   @0x17bfe8 rsb r0, r3, r0
 *   @0x17bfec bl 0x17bdf4 <_ZN12GraphicsPerf12AddMemoryBarEijPv>
 *   @0x17bff0 ldr r3, [r4]
 *   @0x17bff4 ldr r0, [r6]
 *   @0x17bff8 add r2, r5, #432
 *   @0x17bffc movw r1, #0x8080
 *   @0x17c000 movt r1, #0xff80
 *   @0x17c004 rsb r0, r3, r0
 *   @0x17c008 pop {r3, r4, r5, r6, r7, lr}
 *   @0x17c00c b 0x17bdf4 <_ZN12GraphicsPerf12AddMemoryBarEijPv>
 *   @0x17c010 eoreq r5, r7, r8, lsr #26
 *   @0x17c014 .word 0xffffe788
 *   @0x17c018 .word 0xffffe77c
 *   @0x17c01c .word 0xffffe784
 *   @0x17c020 .word 0xffffe780
 *   @0x17c024 .word 0xffffe78c
 *   @0x17c028 .word 0xffffe790
 *   @0x17c02c .word 0xffffe794
 *
 * ══ §22/110 Graphics::Surface_GrabRect(void*, int, int, int, int)  0x17e594  size 280  70 条（0x17e594..0x17e6ac）
 * @func 0x17e594 0x17e6ac  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DBG_BIND_FRAMEBUFFER(int)×2 / Graphics::Flush() / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×3 / 0x38×2 / 0xe8×1 / 0xd4×1 / 0xc8×1 / 0xb8×1 / 0xa8×1 / 0x90×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17e594 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17e598 sub sp, sp, #20
 *   @0x17e59c ldr r4, [pc, #0xe8]
 *   @0x17e5a0 mov r11, r2
 *   @0x17e5a4 mov r8, r3
 *   @0x17e5a8 mov r5, r0
 *   @0x17e5ac mov r7, r1
 *   @0x17e5b0 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17e5b4 ldr r3, [pc, #0xd4]
 *   @0x17e5b8 add r4, pc, r4
 *   @0x17e5bc movw r0, #0xd05
 *   @0x17e5c0 mov r1, #4
 *   @0x17e5c4 ldr r9, [pc, #0xc8]
 *   @0x17e5c8 ldr r3, [r4, r3]
 *   @0x17e5cc add r9, pc, r9
 *   @0x17e5d0 ldr r3, [r3]
 *   @0x17e5d4 blx r3
 *   @0x17e5d8 ldr r3, [pc, #0xb8]
 *   @0x17e5dc ldr r10, [r4, r3]
 *   @0x17e5e0 ldr r3, [r10]
 *   @0x17e5e4 blx r3
 *   @0x17e5e8 ldr r3, [sp, #0x38]
 *   @0x17e5ec ldr r1, [pc, #0xa8]
 *   @0x17e5f0 mov r2, #70
 *   @0x17e5f4 mul r0, r3, r8
 *   @0x17e5f8 add r1, pc, r1
 *   @0x17e5fc mov r3, #1
 *   @0x17e600 lsl r0, r0, #2
 *   @0x17e604 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x17e608 ldr r2, [pc, #0x90]
 *   @0x17e60c movw r3, #0x133
 *   @0x17e610 mov r6, r0
 *   @0x17e614 ldr r0, [r5, #0x18]
 *   @0x17e618 ldr r5, [r4, r2]
 *   @0x17e61c str r3, [r5, #0x4]
 *   @0x17e620 str r9, [r5]
 *   @0x17e624 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi>
 *   @0x17e628 ldr r3, [r10]
 *   @0x17e62c blx r3
 *   @0x17e630 ldr lr, [pc, #0x6c]
 *   @0x17e634 mov r0, r7
 *   @0x17e638 mov r1, r11
 *   @0x17e63c mov r2, r8
 *   @0x17e640 ldr r3, [sp, #0x38]
 *   @0x17e644 ldr r12, [r4, lr]
 *   @0x17e648 movw r7, #0x1908
 *   @0x17e64c movw lr, #0x1401
 *   @0x17e650 str r6, [sp, #0x8]
 *   @0x17e654 str r7, [sp]
 *   @0x17e658 ldr r12, [r12]
 *   @0x17e65c str lr, [sp, #0x4]
 *   @0x17e660 blx r12
 *   @0x17e664 ldr r3, [pc, #0x3c]
 *   @0x17e668 str r9, [r5]
 *   @0x17e66c mov r2, #316
 *   @0x17e670 str r2, [r5, #0x4]
 *   @0x17e674 ldr r3, [r4, r3]
 *   @0x17e678 ldr r0, [r3]
 *   @0x17e67c bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi>
 *   @0x17e680 mov r0, r6
 *   @0x17e684 add sp, sp, #20
 *   @0x17e688 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17e68c mlaeq r7, r8, r6, r3
 *   @0x17e690 .word 0xffffbaf8
 *   @0x17e694 andseq sp, r12, r12, ror r3
 *   @0x17e698 .word 0xffffbafc
 *   @0x17e69c andseq r2, r11, r8, lsr r10
 *   @0x17e6a0 .word 0xffffe81c
 *   @0x17e6a4 .word 0xffffbaf4
 *   @0x17e6a8 .word 0xffffe820
 *
 * ══ §23/110 ScaleTexture(int, int, unsigned int*, int, int, unsigned int*)  0x181388  size 280  70 条（0x181388..0x1814a0）
 * @func 0x181388 0x1814a0  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×2 / ScaleTexture(int, int, unsigned int*, int, int, unsigned int*)+0xf4 / ScaleTexture(int, int, unsigned int*, int, int, unsigned int*)+0xdc
 * 字段偏移 top8: 0x1c×5 / 0x4c×2 / 0xc×2 / 0x14×2 / 0x18×2 / 0x108×1 / 0x48×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x181388 ldr r12, [pc, #0x108]
 *   @0x18138c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x181390 ldr r12, [pc, r12]
 *   @0x181394 mov r9, r0
 *   @0x181398 sub sp, sp, #36
 *   @0x18139c ldr r0, [r12]
 *   @0x1813a0 mov r10, r3
 *   @0x1813a4 ldr r5, [sp, #0x48]
 *   @0x1813a8 mov r3, r1
 *   @0x1813ac ldr lr, [sp, #0x4c]
 *   @0x1813b0 mov r4, r2
 *   @0x1813b4 ldr r12, [r0]
 *   @0x1813b8 mov r2, r9
 *   @0x1813bc str r1, [sp, #0x1c]
 *   @0x1813c0 ldr r1, [pc, #0xd4]
 *   @0x1813c4 str lr, [sp, #0xc]
 *   @0x1813c8 add r1, pc, r1
 *   @0x1813cc stm sp, {r4, r10}
 *   @0x1813d0 str r5, [sp, #0x8]
 *   @0x1813d4 ldr r12, [r12, #0xc]
 *   @0x1813d8 blx r12
 *   @0x1813dc lsl r0, r5, #16
 *   @0x1813e0 ldr r1, [sp, #0x1c]
 *   @0x1813e4 bl 0x318d10 <__divsi3>
 *   @0x1813e8 ldr r12, [sp, #0x1c]
 *   @0x1813ec cmp r12, #0
 *   @0x1813f0 str r0, [sp, #0x14]
 *   @0x1813f4 ble 0x18147c <_Z12ScaleTextureiiPjiiS_+0xf4>
 *   @0x1813f8 mov r1, r9
 *   @0x1813fc lsl r0, r10, #16
 *   @0x181400 bl 0x318d10 <__divsi3>
 *   @0x181404 ldr r1, [sp, #0x1c]
 *   @0x181408 mov r3, #0
 *   @0x18140c lsl r11, r9, #2
 *   @0x181410 mov r2, r4
 *   @0x181414 mov r8, r3
 *   @0x181418 mul r1, r1, r9
 *   @0x18141c str r1, [sp, #0x18]
 *   @0x181420 mov r1, r3
 *   @0x181424 asr r6, r8, #16
 *   @0x181428 ldr r12, [sp, #0x4c]
 *   @0x18142c cmp r9, #0
 *   @0x181430 mul r6, r10, r6
 *   @0x181434 add r6, r12, r6, lsl #2
 *   @0x181438 ble 0x181464 <_Z12ScaleTextureiiPjiiS_+0xdc>
 *   @0x18143c add r7, r11, r2
 *   @0x181440 mov r4, r2
 *   @0x181444 mov r12, #0
 *   @0x181448 asr r5, r12, #16
 *   @0x18144c add r12, r12, r0
 *   @0x181450 ldr r5, [r6, r5, lsl #2]
 *   @0x181454 str r5, [r4], #4
 *   @0x181458 cmp r7, r4
 *   @0x18145c bne 0x181448 <_Z12ScaleTextureiiPjiiS_+0xc0>
 *   @0x181460 add r3, r3, r9
 *   @0x181464 ldr r12, [sp, #0x18]
 *   @0x181468 add r1, r1, #1
 *   @0x18146c cmp r12, r3
 *   @0x181470 ldr r12, [sp, #0x14]
 *   @0x181474 add r8, r8, r12
 *   @0x181478 bge 0x181484 <_Z12ScaleTextureiiPjiiS_+0xfc>
 *   @0x18147c add sp, sp, #36
 *   @0x181480 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x181484 ldr r12, [sp, #0x1c]
 *   @0x181488 add r2, r2, r11
 *   @0x18148c cmp r12, r1
 *   @0x181490 bgt 0x181424 <_Z12ScaleTextureiiPjiiS_+0x9c>
 *   @0x181494 b 0x18147c <_Z12ScaleTextureiiPjiiS_+0xf4>
 *   @0x181498 eoreq r12, r6, r4, lsl #7
 *   @0x18149c andseq r10, r12, r12, lsr r6
 *
 * ══ §24/110 F_LayerDestroyInstances(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c01b4  size 280  70 条（0x1c01b4..0x1c02cc）
 * @func 0x1c01b4 0x1c02cc  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::RemoveElement(CRoom*, int, bool, bool) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x20×2 / 0x10×1 / 0xdc×1 / 0x58×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c01b4 cmp r3, #1
 *   @0x1c01b8 mov r3, #0
 *   @0x1c01bc push {r4, r5, r6, lr}
 *   @0x1c01c0 mov r4, r3
 *   @0x1c01c4 ldr r5, [sp, #0x10]
 *   @0x1c01c8 movt r3, #0xbff0
 *   @0x1c01cc str r4, [r0, #0xc]
 *   @0x1c01d0 str r3, [r0, #0x4]
 *   @0x1c01d4 str r4, [r0]
 *   @0x1c01d8 beq 0x1c01f0 <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1c01dc ldr r0, [pc, #0xdc]
 *   @0x1c01e0 mov r1, r4
 *   @0x1c01e4 pop {r4, r5, r6, lr}
 *   @0x1c01e8 add r0, pc, r0
 *   @0x1c01ec b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c01f0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c01f4 subs r6, r0, #0
 *   @0x1c01f8 popeq {r4, r5, r6, pc}
 *   @0x1c01fc ldr r3, [r5, #0xc]
 *   @0x1c0200 mov r0, r5
 *   @0x1c0204 mov r1, r4
 *   @0x1c0208 bic r3, r3, #-16777216
 *   @0x1c020c cmp r3, #1
 *   @0x1c0210 beq 0x1c0284 <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x1c0214 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0218 mov r1, r0
 *   @0x1c021c mov r0, r6
 *   @0x1c0220 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c0224 mov r5, r0
 *   @0x1c0228 cmp r5, #0
 *   @0x1c022c beq 0x1c029c <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x1c0230 ldr r3, [r5, #0x58]
 *   @0x1c0234 cmp r3, #0
 *   @0x1c0238 popeq {r4, r5, r6, pc}
 *   @0x1c023c ldr r2, [r3]
 *   @0x1c0240 cmp r2, #2
 *   @0x1c0244 ldrne r3, [r3, #0x14]
 *   @0x1c0248 beq 0x1c0258 <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x1c024c cmp r3, #0
 *   @0x1c0250 bne 0x1c023c <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1c0254 pop {r4, r5, r6, pc}
 *   @0x1c0258 ldr r4, [r3, #0x18]
 *   @0x1c025c mov r0, r6
 *   @0x1c0260 ldr r1, [r3, #0x4]
 *   @0x1c0264 mov r2, #0
 *   @0x1c0268 mov r3, #1
 *   @0x1c026c bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb>
 *   @0x1c0270 cmp r4, #0
 *   @0x1c0274 mov r3, r4
 *   @0x1c0278 ldreq r3, [r5, #0x58]
 *   @0x1c027c bne 0x1c023c <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1c0280 b 0x1c024c <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1c0284 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c0288 mov r1, r0
 *   @0x1c028c mov r0, r6
 *   @0x1c0290 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c0294 mov r5, r0
 *   @0x1c0298 b 0x1c0228 <_Z23F_LayerDestroyInstancesR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1c029c ldr r3, [pc, #0x20]
 *   @0x1c02a0 ldr r1, [pc, #0x20]
 *   @0x1c02a4 ldr r3, [pc, r3]
 *   @0x1c02a8 add r1, pc, r1
 *   @0x1c02ac ldr r0, [r3]
 *   @0x1c02b0 ldr r3, [r0]
 *   @0x1c02b4 ldr r3, [r3, #0xc]
 *   @0x1c02b8 blx r3
 *   @0x1c02bc pop {r4, r5, r6, pc}
 *   @0x1c02c0 andseq pc, r8, r0, ror #10
 *   @0x1c02c4 eoreq sp, r2, r0, ror r4
 *   @0x1c02c8 ldrsbeq pc, [r8], -r0
 *
 * ══ §25/110 CDS_Grid::Value_X(RValue&, int, int, int, int, RValue*)  0x20489c  size 280  70 条（0x20489c..0x2049b4）
 * @func 0x20489c 0x2049b4  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCompareVal(RValue const&, RValue const&, double) / CDS_Grid::Value_X(RValue&, int, int, int, int, RValue*)+0xac
 * 字段偏移 top8: 0x4×3 / 0x2c×2 / 0x28×1 / 0x30×1 / 0xc×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20489c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2048a0 mov r8, r1
 *   @0x2048a4 ldr r12, [sp, #0x28]
 *   @0x2048a8 mov r5, r0
 *   @0x2048ac mov r0, #0
 *   @0x2048b0 ldr r7, [sp, #0x30]
 *   @0x2048b4 cmp r2, r12
 *   @0x2048b8 mov r1, r0
 *   @0x2048bc movt r0, #0xbff0
 *   @0x2048c0 str r0, [r8, #0x4]
 *   @0x2048c4 lsrlt r0, r2, #31
 *   @0x2048c8 lsrge r0, r12, #31
 *   @0x2048cc str r1, [r8]
 *   @0x2048d0 cmp r2, r12
 *   @0x2048d4 movlt r6, r2
 *   @0x2048d8 movge r6, r12
 *   @0x2048dc str r1, [r8, #0xc]
 *   @0x2048e0 cmp r0, #0
 *   @0x2048e4 ldr r1, [sp, #0x2c]
 *   @0x2048e8 movne r6, #0
 *   @0x2048ec cmp r3, r1
 *   @0x2048f0 movlt r0, r3
 *   @0x2048f4 movge r0, r1
 *   @0x2048f8 cmp r3, r1
 *   @0x2048fc lsrlt r10, r3, #31
 *   @0x204900 lsrge r10, r1, #31
 *   @0x204904 cmp r2, r12
 *   @0x204908 movge r9, r2
 *   @0x20490c movlt r9, r12
 *   @0x204910 cmp r10, #0
 *   @0x204914 ldr r2, [r5, #0x4]
 *   @0x204918 moveq r10, r0
 *   @0x20491c movne r10, #0
 *   @0x204920 cmp r3, r1
 *   @0x204924 movge r11, r3
 *   @0x204928 movlt r11, r1
 *   @0x20492c cmp r9, r2
 *   @0x204930 subge r3, r2, #1
 *   @0x204934 movlt r3, r9
 *   @0x204938 cmp r6, r3
 *   @0x20493c bgt 0x204998 <_ZN8CDS_Grid7Value_XER6RValueiiiiPS0_+0xfc>
 *   @0x204940 mov r4, r10
 *   @0x204944 b 0x204968 <_ZN8CDS_Grid7Value_XER6RValueiiiiPS0_+0xcc>
 *   @0x204948 ldr r12, [pc, r12]
 *   @0x20494c ldr lr, [r5]
 *   @0x204950 ldrd r2, r3, [r12]
 *   @0x204954 add r0, lr, r0, lsl #4
 *   @0x204958 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x20495c cmp r0, #0
 *   @0x204960 beq 0x20499c <_ZN8CDS_Grid7Value_XER6RValueiiiiPS0_+0x100>
 *   @0x204964 ldr r2, [r5, #0x4]
 *   @0x204968 ldr r1, [r5, #0x8]
 *   @0x20496c mov r3, r11
 *   @0x204970 mla r0, r2, r4, r6
 *   @0x204974 cmp r1, r11
 *   @0x204978 suble r3, r1, #1
 *   @0x20497c ldr r12, [pc, #0x2c]
 *   @0x204980 cmp r4, r3
 *   @0x204984 mov r1, r7
 *   @0x204988 add r4, r4, #1
 *   @0x20498c ble 0x204948 <_ZN8CDS_Grid7Value_XER6RValueiiiiPS0_+0xac>
 *   @0x204990 add r6, r6, #1
 *   @0x204994 b 0x20492c <_ZN8CDS_Grid7Value_XER6RValueiiiiPS0_+0x90>
 *   @0x204998 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20499c vmov s15, r6
 *   @0x2049a0 vcvt.f64.s32 d7, s15
 *   @0x2049a4 vmov r2, r3, d7
 *   @0x2049a8 stm r8, {r2, r3}
 *   @0x2049ac pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2049b0 andseq r12, lr, r12, lsr r10
 *
 * ══ §26/110 CDS_Grid::Value_Y(RValue&, int, int, int, int, RValue*)  0x2049b4  size 280  70 条（0x2049b4..0x204acc）
 * @func 0x2049b4 0x204acc  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCompareVal(RValue const&, RValue const&, double) / CDS_Grid::Value_Y(RValue&, int, int, int, int, RValue*)+0xac
 * 字段偏移 top8: 0x4×3 / 0x28×1 / 0x30×1 / 0xc×1 / 0x2c×1 / 0x8×1 / 0x34×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2049b4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2049b8 mov r8, r1
 *   @0x2049bc ldr r12, [sp, #0x28]
 *   @0x2049c0 mov r5, r0
 *   @0x2049c4 mov r0, #0
 *   @0x2049c8 ldr r7, [sp, #0x30]
 *   @0x2049cc cmp r2, r12
 *   @0x2049d0 mov r1, r0
 *   @0x2049d4 movt r0, #0xbff0
 *   @0x2049d8 str r0, [r8, #0x4]
 *   @0x2049dc lsrlt r0, r2, #31
 *   @0x2049e0 lsrge r0, r12, #31
 *   @0x2049e4 str r1, [r8]
 *   @0x2049e8 cmp r2, r12
 *   @0x2049ec movlt r6, r2
 *   @0x2049f0 movge r6, r12
 *   @0x2049f4 str r1, [r8, #0xc]
 *   @0x2049f8 cmp r0, #0
 *   @0x2049fc ldr r1, [sp, #0x2c]
 *   @0x204a00 movne r6, #0
 *   @0x204a04 cmp r3, r1
 *   @0x204a08 movlt r0, r3
 *   @0x204a0c movge r0, r1
 *   @0x204a10 cmp r3, r1
 *   @0x204a14 lsrlt r10, r3, #31
 *   @0x204a18 lsrge r10, r1, #31
 *   @0x204a1c cmp r2, r12
 *   @0x204a20 movge r9, r2
 *   @0x204a24 movlt r9, r12
 *   @0x204a28 cmp r10, #0
 *   @0x204a2c ldr r2, [r5, #0x4]
 *   @0x204a30 moveq r10, r0
 *   @0x204a34 movne r10, #0
 *   @0x204a38 cmp r3, r1
 *   @0x204a3c movge r11, r3
 *   @0x204a40 movlt r11, r1
 *   @0x204a44 cmp r9, r2
 *   @0x204a48 subge r3, r2, #1
 *   @0x204a4c movlt r3, r9
 *   @0x204a50 cmp r6, r3
 *   @0x204a54 bgt 0x204ab0 <_ZN8CDS_Grid7Value_YER6RValueiiiiPS0_+0xfc>
 *   @0x204a58 mov r4, r10
 *   @0x204a5c b 0x204a84 <_ZN8CDS_Grid7Value_YER6RValueiiiiPS0_+0xd0>
 *   @0x204a60 ldr r12, [pc, r12]
 *   @0x204a64 ldr lr, [r5]
 *   @0x204a68 ldrd r2, r3, [r12]
 *   @0x204a6c add r0, lr, r0, lsl #4
 *   @0x204a70 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x204a74 cmp r0, #0
 *   @0x204a78 beq 0x204ab4 <_ZN8CDS_Grid7Value_YER6RValueiiiiPS0_+0x100>
 *   @0x204a7c ldr r2, [r5, #0x4]
 *   @0x204a80 add r4, r4, #1
 *   @0x204a84 ldr r1, [r5, #0x8]
 *   @0x204a88 mov r3, r11
 *   @0x204a8c ldr r12, [pc, #0x34]
 *   @0x204a90 cmp r1, r11
 *   @0x204a94 suble r3, r1, #1
 *   @0x204a98 mov r1, r7
 *   @0x204a9c cmp r4, r3
 *   @0x204aa0 mla r0, r2, r4, r6
 *   @0x204aa4 ble 0x204a60 <_ZN8CDS_Grid7Value_YER6RValueiiiiPS0_+0xac>
 *   @0x204aa8 add r6, r6, #1
 *   @0x204aac b 0x204a44 <_ZN8CDS_Grid7Value_YER6RValueiiiiPS0_+0x90>
 *   @0x204ab0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x204ab4 vmov s15, r4
 *   @0x204ab8 vcvt.f64.s32 d7, s15
 *   @0x204abc vmov r2, r3, d7
 *   @0x204ac0 stm r8, {r2, r3}
 *   @0x204ac4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x204ac8 andseq r12, lr, r4, lsr #18
 *
 * ══ §27/110 CDS_Queue::ReadFromString(char const*, bool)  0x20f104  size 280  70 条（0x20f104..0x20f21c）
 * @func 0x20f104 0x20f21c  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×4 / CStream::~CStream()×2 / operator delete(void*)×2 / operator new(unsigned int) / CStream::CStream(int) / CStream::ConvertFromString(char const*) / CDS_Queue::ReadFromString(char const*, bool)+0x60 / CDS_Queue::Clear()
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0x78×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20f104 push {r4, r5, r6, r7, r8, lr}
 *   @0x20f108 mov r6, r0
 *   @0x20f10c mov r0, #32
 *   @0x20f110 mov r7, r2
 *   @0x20f114 mov r4, r1
 *   @0x20f118 bl 0x27c524 <_Znwj>
 *   @0x20f11c mov r1, #0
 *   @0x20f120 mov r5, r0
 *   @0x20f124 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x20f128 mov r0, r5
 *   @0x20f12c mov r1, r4
 *   @0x20f130 bl 0x2025b0 <_ZN7CStream17ConvertFromStringEPKc>
 *   @0x20f134 mov r0, r5
 *   @0x20f138 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20f13c sub r3, r0, #201
 *   @0x20f140 cmp r3, #1
 *   @0x20f144 bls 0x20f164 <_ZN9CDS_Queue14ReadFromStringEPKcb+0x60>
 *   @0x20f148 subs r0, r5, #0
 *   @0x20f14c beq 0x20f204 <_ZN9CDS_Queue14ReadFromStringEPKcb+0x100>
 *   @0x20f150 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x20f154 mov r0, r5
 *   @0x20f158 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f15c mov r0, #0
 *   @0x20f160 pop {r4, r5, r6, r7, r8, pc}
 *   @0x20f164 cmp r7, #0
 *   @0x20f168 movne r8, #1
 *   @0x20f16c beq 0x20f208 <_ZN9CDS_Queue14ReadFromStringEPKcb+0x104>
 *   @0x20f170 mov r0, r6
 *   @0x20f174 bl 0x20eacc <_ZN9CDS_Queue5ClearEv>
 *   @0x20f178 mov r0, r5
 *   @0x20f17c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20f180 str r0, [r6, #0x4]
 *   @0x20f184 mov r0, r5
 *   @0x20f188 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20f18c str r0, [r6, #0x8]
 *   @0x20f190 mov r0, r5
 *   @0x20f194 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20f198 ldr r2, [pc, #0x78]
 *   @0x20f19c movw r3, #0x35d
 *   @0x20f1a0 add r2, pc, r2
 *   @0x20f1a4 mov r7, r0
 *   @0x20f1a8 lsl r1, r0, #4
 *   @0x20f1ac add r0, r6, #16
 *   @0x20f1b0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x20f1b4 cmp r7, #0
 *   @0x20f1b8 str r7, [r6, #0xc]
 *   @0x20f1bc movgt r4, #0
 *   @0x20f1c0 ble 0x20f1e4 <_ZN9CDS_Queue14ReadFromStringEPKcb+0xe0>
 *   @0x20f1c4 ldr r0, [r6, #0x10]
 *   @0x20f1c8 mov r1, r5
 *   @0x20f1cc mov r2, r8
 *   @0x20f1d0 add r0, r0, r4, lsl #4
 *   @0x20f1d4 add r4, r4, #1
 *   @0x20f1d8 bl 0x208638 <_Z9ReadValueR6RValueR7CStreami>
 *   @0x20f1dc cmp r4, r7
 *   @0x20f1e0 bne 0x20f1c4 <_ZN9CDS_Queue14ReadFromStringEPKcb+0xc0>
 *   @0x20f1e4 cmp r5, #0
 *   @0x20f1e8 beq 0x20f1fc <_ZN9CDS_Queue14ReadFromStringEPKcb+0xf8>
 *   @0x20f1ec mov r0, r5
 *   @0x20f1f0 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x20f1f4 mov r0, r5
 *   @0x20f1f8 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f1fc mov r0, #1
 *   @0x20f200 pop {r4, r5, r6, r7, r8, pc}
 *   @0x20f204 pop {r4, r5, r6, r7, r8, pc}
 *   @0x20f208 cmp r0, #201
 *   @0x20f20c moveq r8, #2
 *   @0x20f210 movne r8, #0
 *   @0x20f214 b 0x20f170 <_ZN9CDS_Queue14ReadFromStringEPKcb+0x6c>
 *   @0x20f218 andseq r4, r4, r12, asr #12
 *
 * ══ §28/110 Audio_DestroyStream(int)  0x21d9a8  size 280  70 条（0x21d9a8..0x21dac0）
 * @func 0x21d9a8 0x21dac0  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_DestroyStream(int)+0x2c / Audio_DestroyStream(int)+0x58 / Audio_DestroyStream(int)+0xf0 / Audio_StopSoundNoise(CNoise*, bool)
 * 字段偏移 top8: 0x38×2 / 0xdc×1 / 0xcc×1 / 0xc8×1 / 0xc×1 / 0xa8×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d9a8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x21d9ac movw r3, #0x93df
 *   @0x21d9b0 movt r3, #0x4
 *   @0x21d9b4 mov r5, r0
 *   @0x21d9b8 cmp r0, r3
 *   @0x21d9bc ble 0x21d9d4 <_Z19Audio_DestroyStreami+0x2c>
 *   @0x21d9c0 ldr r3, [pc, #0xdc]
 *   @0x21d9c4 ldr r3, [pc, r3]
 *   @0x21d9c8 ldr r3, [r3]
 *   @0x21d9cc cmp r0, r3
 *   @0x21d9d0 blt 0x21da00 <_Z19Audio_DestroyStreami+0x58>
 *   @0x21d9d4 ldr r3, [pc, #0xcc]
 *   @0x21d9d8 mov r2, r5
 *   @0x21d9dc ldr r1, [pc, #0xc8]
 *   @0x21d9e0 ldr r3, [pc, r3]
 *   @0x21d9e4 add r1, pc, r1
 *   @0x21d9e8 ldr r0, [r3]
 *   @0x21d9ec ldr r3, [r0]
 *   @0x21d9f0 ldr r3, [r3, #0xc]
 *   @0x21d9f4 blx r3
 *   @0x21d9f8 mvn r0, #0
 *   @0x21d9fc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21da00 ldr r3, [pc, #0xa8]
 *   @0x21da04 sub r2, r0, #299008
 *   @0x21da08 sub r2, r2, #992
 *   @0x21da0c ldr r3, [pc, r3]
 *   @0x21da10 ldr r1, [r3]
 *   @0x21da14 cmp r2, r1
 *   @0x21da18 bge 0x21d9f8 <_Z19Audio_DestroyStreami+0x50>
 *   @0x21da1c ldr r3, [r3, #0x4]
 *   @0x21da20 ldr r7, [r3, r2, lsl #2]
 *   @0x21da24 cmp r7, #0
 *   @0x21da28 beq 0x21d9f8 <_Z19Audio_DestroyStreami+0x50>
 *   @0x21da2c ldr r3, [pc, #0x80]
 *   @0x21da30 add r3, pc, r3
 *   @0x21da34 ldr r6, [r3, #0x38]
 *   @0x21da38 cmp r6, #0
 *   @0x21da3c ble 0x21da98 <_Z19Audio_DestroyStreami+0xf0>
 *   @0x21da40 ldr r9, [pc, #0x70]
 *   @0x21da44 mov r3, r6
 *   @0x21da48 ldr r8, [pc, #0x6c]
 *   @0x21da4c mov r4, #0
 *   @0x21da50 add r9, pc, r9
 *   @0x21da54 add r8, pc, r8
 *   @0x21da58 b 0x21da68 <_Z19Audio_DestroyStreami+0xc0>
 *   @0x21da5c cmp r4, r6
 *   @0x21da60 beq 0x21da98 <_Z19Audio_DestroyStreami+0xf0>
 *   @0x21da64 ldr r3, [r8, #0x38]
 *   @0x21da68 cmp r4, r3
 *   @0x21da6c mov r0, #0
 *   @0x21da70 ldrlt r3, [r9, #0x3c]
 *   @0x21da74 ldrlt r0, [r3, r4, lsl #2]
 *   @0x21da78 add r4, r4, #1
 *   @0x21da7c ldr r3, [r0, #0x18]
 *   @0x21da80 cmp r3, r5
 *   @0x21da84 bne 0x21da5c <_Z19Audio_DestroyStreami+0xb4>
 *   @0x21da88 mov r1, #1
 *   @0x21da8c bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb>
 *   @0x21da90 cmp r4, r6
 *   @0x21da94 bne 0x21da64 <_Z19Audio_DestroyStreami+0xbc>
 *   @0x21da98 mov r0, #1
 *   @0x21da9c strb r0, [r7, #0x27]
 *   @0x21daa0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21daa4 andseq r3, sp, r0, lsr #20
 *   @0x21daa8 andseq pc, r12, r4, lsr sp
 *   @0x21daac andseq r6, r3, r12, lsr #24
 *   @0x21dab0 andseq r3, sp, r12, asr #19
 *   @0x21dab4 subseq r7, r3, r4, ror #16
 *   @0x21dab8 subseq r7, r3, r4, asr #16
 *   @0x21dabc subseq r7, r3, r0, asr #16
 *
 * ══ §29/110 yyMatrix::PerspectiveFovLH(yyMatrix*, float, float, float, float)  0x27b068  size 280  70 条（0x27b068..0x27b180）
 * @func 0x27b068 0x27b180  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6748
 * 字段偏移 top8: 0xc×2 / 0x8×2 / 0x4×2 / 0x1c×2 / 0x18×2 / 0x10×2 / 0x24×2 / 0x20×2
 * VFP 指令 29 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b068 vmov s15, r1
 *   @0x27b06c push {r4, lr}
 *   @0x27b070 vpush {d8, d9}
 *   @0x27b074 vcmp.f32 s15, #0
 *   @0x27b078 vldr s16, [sp, #24]
 *   @0x27b07c vmov s17, r2
 *   @0x27b080 mov r4, r0
 *   @0x27b084 vmov s18, r3
 *   @0x27b088 vmrs APSR_nzcv, fpscr
 *   @0x27b08c vcmp.f32 s17, #0
 *   @0x27b090 movne r3, #0
 *   @0x27b094 moveq r3, #1
 *   @0x27b098 vmrs APSR_nzcv, fpscr
 *   @0x27b09c orreq r3, r3, #1
 *   @0x27b0a0 cmp r3, #0
 *   @0x27b0a4 bne 0x27b130 <_ZN8yyMatrix16PerspectiveFovLHEPS_ffff+0xc8>
 *   @0x27b0a8 vcmp.f32 s18, s16
 *   @0x27b0ac vmrs APSR_nzcv, fpscr
 *   @0x27b0b0 beq 0x27b130 <_ZN8yyMatrix16PerspectiveFovLHEPS_ffff+0xc8>
 *   @0x27b0b4 vmov.f32 s14, #5.000000e-01
 *   @0x27b0b8 vmul.f32 s14, s15, s14
 *   @0x27b0bc vmov r0, s14
 *   @0x27b0c0 bl 0xb6748 <tanf@plt>
 *   @0x27b0c4 vmov.f32 s15, #1.000000e+00
 *   @0x27b0c8 mov r3, #0
 *   @0x27b0cc str r3, [r4, #0xc]
 *   @0x27b0d0 str r3, [r4, #0x8]
 *   @0x27b0d4 str r3, [r4, #0x4]
 *   @0x27b0d8 str r3, [r4, #0x1c]
 *   @0x27b0dc str r3, [r4, #0x18]
 *   @0x27b0e0 str r3, [r4, #0x10]
 *   @0x27b0e4 str r3, [r4, #0x24]
 *   @0x27b0e8 str r3, [r4, #0x20]
 *   @0x27b0ec str r3, [r4, #0x3c]
 *   @0x27b0f0 vstr s15, [r4, #44]
 *   @0x27b0f4 vnmul.f32 s14, s18, s16
 *   @0x27b0f8 str r3, [r4, #0x34]
 *   @0x27b0fc str r3, [r4, #0x30]
 *   @0x27b100 vsub.f32 s18, s16, s18
 *   @0x27b104 vmov s13, r0
 *   @0x27b108 vdiv.f32 s16, s16, s18
 *   @0x27b10c vdiv.f32 s15, s15, s13
 *   @0x27b110 vstr s16, [r4, #40]
 *   @0x27b114 vdiv.f32 s17, s15, s17
 *   @0x27b118 vstr s15, [r4, #20]
 *   @0x27b11c vdiv.f32 s18, s14, s18
 *   @0x27b120 vstr s17, [r4]
 *   @0x27b124 vstr s18, [r4, #56]
 *   @0x27b128 vpop {d8, d9}
 *   @0x27b12c pop {r4, pc}
 *   @0x27b130 mov r3, #0
 *   @0x27b134 mov r2, #1065353216
 *   @0x27b138 str r3, [r4, #0x38]
 *   @0x27b13c str r3, [r4, #0x34]
 *   @0x27b140 str r3, [r4, #0x30]
 *   @0x27b144 str r3, [r4, #0x2c]
 *   @0x27b148 str r3, [r4, #0x24]
 *   @0x27b14c str r3, [r4, #0x20]
 *   @0x27b150 str r3, [r4, #0x1c]
 *   @0x27b154 str r3, [r4, #0x18]
 *   @0x27b158 str r3, [r4, #0x10]
 *   @0x27b15c str r3, [r4, #0xc]
 *   @0x27b160 str r3, [r4, #0x8]
 *   @0x27b164 str r3, [r4, #0x4]
 *   @0x27b168 str r2, [r4, #0x3c]
 *   @0x27b16c str r2, [r4, #0x28]
 *   @0x27b170 str r2, [r4, #0x14]
 *   @0x27b174 str r2, [r4]
 *   @0x27b178 vpop {d8, d9}
 *   @0x27b17c pop {r4, pc}
 *
 * ══ §30/110 spMeshAttachment_updateUVs  0x287538  size 280  70 条（0x287538..0x287650）
 * @func 0x287538 0x287650  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spMeshAttachment_updateUVs+0xac×2 / _free / _malloc
 * 字段偏移 top8: 0x5c×2 / 0x58×2 / 0x8×2 / 0x20×1 / 0xdc×1 / 0x50×1
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x287538 push {r3, r4, r5, lr}
 *   @0x28753c vldr s15, [r0, #64]
 *   @0x287540 mov r4, r0
 *   @0x287544 vpush {d8}
 *   @0x287548 ldr r5, [r0, #0x20]
 *   @0x28754c vldr s17, [r0, #72]
 *   @0x287550 ldr r0, [r0, #0x5c]
 *   @0x287554 vldr s16, [r4, #76]
 *   @0x287558 vsub.f32 s17, s17, s15
 *   @0x28755c vldr s15, [r4, #68]
 *   @0x287560 vsub.f32 s16, s16, s15
 *   @0x287564 bl 0x285c80 <_free>
 *   @0x287568 ldr r1, [pc, #0xdc]
 *   @0x28756c lsl r0, r5, #2
 *   @0x287570 mov r2, #64
 *   @0x287574 add r1, pc, r1
 *   @0x287578 bl 0x285c10 <_malloc>
 *   @0x28757c ldr r3, [r4, #0x50]
 *   @0x287580 cmp r3, #0
 *   @0x287584 str r0, [r4, #0x5c]
 *   @0x287588 bne 0x2875ec <spMeshAttachment_updateUVs+0xb4>
 *   @0x28758c cmp r5, #0
 *   @0x287590 ble 0x2875e4 <spMeshAttachment_updateUVs+0xac>
 *   @0x287594 sub r2, r5, #1
 *   @0x287598 ldr r3, [r4, #0x58]
 *   @0x28759c add r0, r0, #4
 *   @0x2875a0 lsr r2, r2, #1
 *   @0x2875a4 add r1, r3, #12
 *   @0x2875a8 add r3, r3, #4
 *   @0x2875ac add r2, r1, r2, lsl #3
 *   @0x2875b0 vldr s14, [r3, #-4]
 *   @0x2875b4 vldr s15, [r4, #64]
 *   @0x2875b8 vmla.f32 s15, s17, s14
 *   @0x2875bc mov r1, r3
 *   @0x2875c0 add r3, r3, #8
 *   @0x2875c4 cmp r3, r2
 *   @0x2875c8 vstr s15, [r0, #-4]
 *   @0x2875cc vldr s14, [r1]
 *   @0x2875d0 vldr s15, [r4, #68]
 *   @0x2875d4 vmla.f32 s15, s16, s14
 *   @0x2875d8 vmov r1, s15
 *   @0x2875dc str r1, [r0], #8
 *   @0x2875e0 bne 0x2875b0 <spMeshAttachment_updateUVs+0x78>
 *   @0x2875e4 vpop {d8}
 *   @0x2875e8 pop {r3, r4, r5, pc}
 *   @0x2875ec cmp r5, #0
 *   @0x2875f0 ble 0x2875e4 <spMeshAttachment_updateUVs+0xac>
 *   @0x2875f4 sub r2, r5, #1
 *   @0x2875f8 ldr r3, [r4, #0x58]
 *   @0x2875fc add r0, r0, #4
 *   @0x287600 lsr r2, r2, #1
 *   @0x287604 add r1, r3, #12
 *   @0x287608 add r3, r3, #4
 *   @0x28760c add r2, r1, r2, lsl #3
 *   @0x287610 vldr s14, [r3]
 *   @0x287614 vldr s15, [r4, #64]
 *   @0x287618 vmla.f32 s15, s17, s14
 *   @0x28761c add r3, r3, #8
 *   @0x287620 vstr s15, [r0, #-4]
 *   @0x287624 vldr s15, [r4, #68]
 *   @0x287628 vadd.f32 s15, s16, s15
 *   @0x28762c vldr s14, [r3, #-12]
 *   @0x287630 cmp r3, r2
 *   @0x287634 vmls.f32 s15, s16, s14
 *   @0x287638 vmov r1, s15
 *   @0x28763c str r1, [r0], #8
 *   @0x287640 bne 0x287610 <spMeshAttachment_updateUVs+0xd8>
 *   @0x287644 vpop {d8}
 *   @0x287648 pop {r3, r4, r5, pc}
 *   @0x28764c andeq r0, sp, r12, lsl #7
 *
 * ══ §31/110 zip_fread  0x2a476c  size 280  70 条（0x2a476c..0x2a4884）
 * @func 0x2a476c 0x2a4884  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _zip_file_fillbuf(void*, unsigned int, zip_file*) / 0xb69dc / zip_fread+0xca / zip_fread+0x64 / zip_fread+0x10a
 * 字段偏移 top8: 0x30×5 / 0x1c×4 / 0x10×2 / 0x2c×2 / 0x28×1 / 0xc×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a476c push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2a4770 mov r6, r1
 *   @0x2a4774 mov r4, r0
 *   @0x2a4778 beq 0x2a4876 <zip_fread+0x10a>
 *   @0x2a477c cmp r3, #0x0
 *   @0x2a4780 ldr r3, [r0, #0x10]
 *   @0x2a4784 bpl 0x2a478c <zip_fread+0x20>
 *   @0x2a4788 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2a478c cmp r2, #0x0
 *   @0x2a4790 ldr r2, [r4, #0x1c]
 *   @0x2a4794 lsls r1, r3, #0x1d
 *   @0x2a4798 .word 0x61220201
 *   @0x2a479c bpl 0x2a4786 <zip_fread+0x1a>
 *   @0x2a47a0 ldr r3, [r4, #0x28]
 *   @0x2a47a4 beq 0x2a4786 <zip_fread+0x1a>
 *   @0x2a47a8 movs r1, #0x7
 *   @0x2a47ac b 0x2a4872 <zip_fread+0x106>
 *   @0x2a47b0 bmi 0x2a47c2 <zip_fread+0x56>
 *   @0x2a47b4 mov r2, r4
 *   @0x2a47b8 bl 0x2a44d6 <_Z17_zip_file_fillbufPvjP8zip_file>
 *   @0x2a47bc subs r5, r0, #0x0
 *   @0x2a47c0 b 0x2a487e <zip_fread+0x112>
 *   @0x2a47c4 str r1, [r3, #0xc]
 *   @0x2a47c8 str r7, [r3, #0x10]
 *   @0x2a47cc ldr.w r8, [r3, #0x14]
 *   @0x2a47d0 ldr r0, [r4, #0x30]
 *   @0x2a47d4 blx 0xb69dc <inflate@plt>
 *   @0x2a47d8 adds r3, r0, #0x5
 *   @0x2a47dc cmp r3, #0x7
 *   @0x2a47e0 adr r0, #8 <zip_fread+0x7a>
 *   @0x2a47e4 strmi r1, [r8], #-35
 *   @0x2a47e8 bx r0
 *   @0x2a47ec lsls r1, r3, #0x1
 *   @0x2a47f0 lsls r3, r0, #0x2
 *   @0x2a47f4 lsls r3, r0, #0x2
 *   @0x2a47f8 lsls r3, r0, #0x2
 *   @0x2a47fc .word 0xffe5 ffff
 *   @0x2a4800 movs r1, r5
 *   @0x2a4804 movs r1, r4
 *   @0x2a4808 lsls r3, r0, #0x2
 *   @0x2a480c ldr r3, [r4, #0x30]
 *   @0x2a4810 cmp r3, r8
 *   @0x2a4814 ldr r3, [r4, #0x30]
 *   @0x2a4818 ldr r3, [r4, #0x1c]
 *   @0x2a481c addsmi r0, sp, #20971520
 *   @0x2a4820 blo 0x2a4836 <zip_fread+0xca>
 *   @0x2a4824 lsls r3, r3, #0x1d
 *   @0x2a4828 ldr r0, [r4, #0x24]
 *   @0x2a482c mov r2, r5
 *   @0x2a4830 rsbvs lr, r0, #59392
 *   @0x2a4834 b 0x2a483c <zip_fread+0xd0>
 *   @0x2a4838 blo 0x2a47d0 <zip_fread+0x64>
 *   @0x2a483c ldr r3, [r4, #0x1c]
 *   @0x2a4840 str r3, [r4, #0x1c]
 *   @0x2a4844 ldr r3, [r4, #0x30]
 *   @0x2a4848 cbnz r3, 0x2a486e <zip_fread+0x102>
 *   @0x2a484c ldr r0, [r4, #0x2c]
 *   @0x2a4850 .word 0xf7ff5100
 *   @0x2a4854 cdpne p14, #0x0, c15, c2, c0, #0x2
 *   @0x2a4858 bne 0x2a4860 <zip_fread+0xf4>
 *   @0x2a485c movs r1, #0x15
 *   @0x2a4860 blt 0x2a4876 <zip_fread+0x10a>
 *   @0x2a4864 ldr r1, [r4, #0x2c]
 *   @0x2a4868 ldr r3, [r4, #0x30]
 *   @0x2a486c b 0x2a47d0 <zip_fread+0x64>
 *   @0x2a4870 movs r1, #0xd
 *   @0x2a4874 .word 0xf04ffd71
 *   @0x2a4878 pop {r0, r1, r2, r3, r4, r5, r6, r7, r12, sp}
 *   @0x2a487c qsub8mi r8, r8, r0
 *   @0x2a4880 pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ §32/110 png_set_cHRM_fixed  0x2ae7e0  size 280  70 条（0x2ae7e0..0x2ae8f8）
 * @func 0x2ae7e0 0x2ae8f8  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x74d4f8
 * 字段偏移 top8: 0x8×2 / 0x3c×1 / 0x44×1 / 0xc×1 / 0x4c×1 / 0x20×1
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ae7e0 push.w {r4, r5, r6, r7, r9, r10, r11, lr}
 *   @0x2ae7e4 sub sp, #0x18
 *   @0x2ae7e8 mov r11, r2
 *   @0x2ae7ec ldr.w r9, [sp, #0x38]
 *   @0x2ae7f0 ldr r7, [sp, #0x3c]
 *   @0x2ae7f4 ldr r5, [sp, #0x44]
 *   @0x2ae7f8 beq 0x2ae8ea <png_set_cHRM_fixed+0x10a>
 *   @0x2ae7fc beq 0x2ae8ea <png_set_cHRM_fixed+0x10a>
 *   @0x2ae800 mov r1, r2
 *   @0x2ae804 mov r2, r10
 *   @0x2ae808 str r3, [sp, #0xc]
 *   @0x2ae80c str r5, [sp, #0x8]
 *   @0x2ae810 mov r3, r9
 *   @0x2ae814 stmdahs r0, {r0, r3, r5, r10, r11, r12, sp, lr, pc}
 *   @0x2ae818 beq 0x2ae8ea <png_set_cHRM_fixed+0x10a>
 *   @0x2ae81c vldr s22, [pc, #576]
 *   @0x2ae820 blls 0x74d4f8 <g_SWFvertbuff+0x7a430>
 *   @0x2ae824 vcvt.f64.s32 d6, s11
 *   @0x2ae828 str.w r11, [r4, #0x100]
 *   @0x2ae82c vmov s11, r10
 *   @0x2ae830 str.w r10, [r4, #0x104]
 *   @0x2ae834 str.w r3, [r4, #0x118]
 *   @0x2ae838 ldr r3, [sp, #0x4c]
 *   @0x2ae83c .word 0xf8c49108
 *   @0x2ae840 .word 0xf8c4710c
 *   @0x2ae844 mcr p1, #0x4, r3, c6, c12, #0x0
 *   @0x2ae848 .word 0xf8c46b07
 *   @0x2ae84c .word 0xf8c46110
 *   @0x2ae850 mrc p1, #0x5, r5, c7, c4, #0x0
 *   @0x2ae854 vstr d6, [r4, #792]
 *   @0x2ae858 .word 0xeeb86a20
 *   @0x2ae85c vmls.f64 d6, d21, d21
 *   @0x2ae860 .word 0xee869a90
 *   @0x2ae864 vmov.f64 d6, #1.437500e+00
 *   @0x2ae868 vstr d6, [r4, #792]
 *   @0x2ae86c .word 0xeeb86a21
 *   @0x2ae870 vmls.f64 d6, d21, d21
 *   @0x2ae874 .word 0xee867a90
 *   @0x2ae878 vmov.f64 d6, #1.437500e+00
 *   @0x2ae87c vstr d6, [r4, #792]
 *   @0x2ae880 .word 0xeeb86a22
 *   @0x2ae884 vmls.f64 d6, d21, d21
 *   @0x2ae888 .word 0xee866a90
 *   @0x2ae88c vmov.f64 d6, #1.437500e+00
 *   @0x2ae890 vstr d6, [r4, #792]
 *   @0x2ae894 .word 0xeeb86a23
 *   @0x2ae898 vmls.f64 d6, d21, d21
 *   @0x2ae89c .word 0xee865a90
 *   @0x2ae8a0 vmov.f64 d6, #1.437500e+00
 *   @0x2ae8a4 vstr d6, [r4, #792]
 *   @0x2ae8a8 .word 0xeeb86a24
 *   @0x2ae8ac vldr d22, [sp, #916]
 *   @0x2ae8b0 .word 0xee865a12
 *   @0x2ae8b4 vmov.f64 d6, #1.437500e+00
 *   @0x2ae8b8 vstr d6, [r4, #792]
 *   @0x2ae8bc .word 0xeeb86a25
 *   @0x2ae8c0 vmls.f64 d6, d21, d21
 *   @0x2ae8c4 stmvs r3!, {r4, r7, r9, r11, r12, sp}
 *   @0x2ae8c8 orr r3, r3, #0x4
 *   @0x2ae8cc str r3, [r4, #0x8]
 *   @0x2ae8d0 vmov.f64 d6, #1.437500e+00
 *   @0x2ae8d4 vstr d6, [r4, #792]
 *   @0x2ae8d8 .word 0xeeb86a26
 *   @0x2ae8dc .word 0xee866be5
 *   @0x2ae8e0 vmov.f64 d7, #1.437500e+00
 *   @0x2ae8e4 vstr d7, [r4, #796]
 *   @0x2ae8e8 andlt r7, r6, r7, lsr #20
 *   @0x2ae8ec pop.w {r4, r5, r6, r7, r9, r10, r11, pc}
 *   @0x2ae8f0 movs r0, r0
 *   @0x2ae8f4 ldr r0, [r0, #0x20]
 *
 * ══ §33/110 jpeg_start_decompress  0x2b34a8  size 280  70 条（0x2b34a8..0x2b35c0）
 * @func 0x2b34a8 0x2b35c0  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_start_decompress+0x60 / jinit_master_decompress
 * 字段偏移 top8: 0x8×4 / 0x14×3 / 0x190×2 / 0x4×2 / 0x18×1 / 0x10×1 / 0x11c×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b34a8 ldr r3, [r0, #0x14]
 *   @0x2b34ac push {r4, lr}
 *   @0x2b34b0 cmp r3, #202
 *   @0x2b34b4 mov r4, r0
 *   @0x2b34b8 beq 0x2b3598 <jpeg_start_decompress+0xf0>
 *   @0x2b34bc cmp r3, #203
 *   @0x2b34c0 beq 0x2b34f4 <jpeg_start_decompress+0x4c>
 *   @0x2b34c4 cmp r3, #204
 *   @0x2b34c8 beq 0x2b34e8 <jpeg_start_decompress+0x40>
 *   @0x2b34cc ldr r2, [r0]
 *   @0x2b34d0 mov r1, #20
 *   @0x2b34d4 str r3, [r2, #0x18]
 *   @0x2b34d8 ldr r3, [r0]
 *   @0x2b34dc str r1, [r2, #0x14]
 *   @0x2b34e0 ldr r3, [r3]
 *   @0x2b34e4 blx r3
 *   @0x2b34e8 mov r0, r4
 *   @0x2b34ec pop {r4, lr}
 *   @0x2b34f0 b 0x2b33a4 <jpeg_finish_decompress+0xe4>
 *   @0x2b34f4 ldr r3, [r4, #0x190]
 *   @0x2b34f8 ldrb r3, [r3, #0x10]
 *   @0x2b34fc cmp r3, #0
 *   @0x2b3500 beq 0x2b3584 <jpeg_start_decompress+0xdc>
 *   @0x2b3504 ldr r3, [r4, #0x8]
 *   @0x2b3508 cmp r3, #0
 *   @0x2b350c beq 0x2b351c <jpeg_start_decompress+0x74>
 *   @0x2b3510 ldr r3, [r3]
 *   @0x2b3514 mov r0, r4
 *   @0x2b3518 blx r3
 *   @0x2b351c ldr r3, [r4, #0x190]
 *   @0x2b3520 mov r0, r4
 *   @0x2b3524 ldr r3, [r3]
 *   @0x2b3528 blx r3
 *   @0x2b352c cmp r0, #0
 *   @0x2b3530 popeq {r4, pc}
 *   @0x2b3534 cmp r0, #2
 *   @0x2b3538 beq 0x2b3584 <jpeg_start_decompress+0xdc>
 *   @0x2b353c ldr r3, [r4, #0x8]
 *   @0x2b3540 cmp r3, #0
 *   @0x2b3544 beq 0x2b351c <jpeg_start_decompress+0x74>
 *   @0x2b3548 bic r0, r0, #2
 *   @0x2b354c cmp r0, #1
 *   @0x2b3550 bne 0x2b3508 <jpeg_start_decompress+0x60>
 *   @0x2b3554 ldr r2, [r3, #0x4]
 *   @0x2b3558 ldr r1, [r3, #0x8]
 *   @0x2b355c add r2, r2, #1
 *   @0x2b3560 str r2, [r3, #0x4]
 *   @0x2b3564 cmp r2, r1
 *   @0x2b3568 blt 0x2b3508 <jpeg_start_decompress+0x60>
 *   @0x2b356c ldr r2, [r4, #0x11c]
 *   @0x2b3570 cmp r3, #0
 *   @0x2b3574 add r1, r1, r2
 *   @0x2b3578 str r1, [r3, #0x8]
 *   @0x2b357c bne 0x2b3510 <jpeg_start_decompress+0x68>
 *   @0x2b3580 b 0x2b351c <jpeg_start_decompress+0x74>
 *   @0x2b3584 ldr r3, [r4, #0x7c]
 *   @0x2b3588 mov r0, r4
 *   @0x2b358c str r3, [r4, #0x84]
 *   @0x2b3590 pop {r4, lr}
 *   @0x2b3594 b 0x2b33a4 <jpeg_finish_decompress+0xe4>
 *   @0x2b3598 bl 0x2b66d8 <jinit_master_decompress>
 *   @0x2b359c ldrb r3, [r4, #0x40]
 *   @0x2b35a0 cmp r3, #0
 *   @0x2b35a4 moveq r3, #203
 *   @0x2b35a8 streq r3, [r4, #0x14]
 *   @0x2b35ac beq 0x2b34f4 <jpeg_start_decompress+0x4c>
 *   @0x2b35b0 mov r3, #207
 *   @0x2b35b4 mov r0, #1
 *   @0x2b35b8 str r3, [r4, #0x14]
 *   @0x2b35bc pop {r4, pc}
 *
 * ══ §34/110 b2PolygonShape::SetAsBox(float, float, b2Vec2 const&, float)  0x2c5f10  size 280  70 条（0x2c5f10..0x2c6028）
 * @func 0x2c5f10 0x2c6028  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c
 * 字段偏移 top8: 0x94×2 / 0x8×2 / 0x1c×1 / 0x24×1 / 0x28×1 / 0x30×1 / 0x58×1 / 0x6c×1
 * VFP 指令 32 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5f10 vmov s14, r1
 *   @0x2c5f14 mov r12, #0
 *   @0x2c5f18 vmov s15, r2
 *   @0x2c5f1c movt r12, #0xbf80
 *   @0x2c5f20 vneg.f32 s14, s14
 *   @0x2c5f24 push {r3, r4, r5, lr}
 *   @0x2c5f28 vpush {d8, d9}
 *   @0x2c5f2c mov r4, r0
 *   @0x2c5f30 str r1, [r4, #0x1c]
 *   @0x2c5f34 vneg.f32 s15, s15
 *   @0x2c5f38 str r1, [r4, #0x24]
 *   @0x2c5f3c str r2, [r4, #0x28]
 *   @0x2c5f40 mov r1, #4
 *   @0x2c5f44 str r2, [r4, #0x30]
 *   @0x2c5f48 vstr s14, [r0, #20]
 *   @0x2c5f4c str r12, [r0, #0x58]
 *   @0x2c5f50 vstr s14, [r0, #44]
 *   @0x2c5f54 vstr s15, [r0, #24]
 *   @0x2c5f58 vstr s15, [r0, #32]
 *   @0x2c5f5c str r12, [r0, #0x6c]
 *   @0x2c5f60 mov r2, #0
 *   @0x2c5f64 str r1, [r0, #0x94]
 *   @0x2c5f68 mov r1, #1065353216
 *   @0x2c5f6c str r2, [r0, #0x54]
 *   @0x2c5f70 str r2, [r0, #0x60]
 *   @0x2c5f74 str r2, [r0, #0x64]
 *   @0x2c5f78 str r2, [r0, #0x70]
 *   @0x2c5f7c add r2, r0, #12
 *   @0x2c5f80 str r1, [r0, #0x5c]
 *   @0x2c5f84 str r1, [r0, #0x68]
 *   @0x2c5f88 ldr r5, [sp, #0x20]
 *   @0x2c5f8c ldm r3, {r0, r1}
 *   @0x2c5f90 stm r2, {r0, r1}
 *   @0x2c5f94 mov r0, r5
 *   @0x2c5f98 vldr s18, [r3]
 *   @0x2c5f9c vldr s17, [r3, #4]
 *   @0x2c5fa0 bl 0xb6580 <sinf@plt>
 *   @0x2c5fa4 vmov s16, r0
 *   @0x2c5fa8 mov r0, r5
 *   @0x2c5fac bl 0xb658c <cosf@plt>
 *   @0x2c5fb0 add r3, r4, #84
 *   @0x2c5fb4 add r1, r4, #88
 *   @0x2c5fb8 mov r2, #0
 *   @0x2c5fbc vmov s15, r0
 *   @0x2c5fc0 vldr s14, [r3, #-60]
 *   @0x2c5fc4 vmul.f32 s13, s14, s16
 *   @0x2c5fc8 vldr s12, [r3, #-64]
 *   @0x2c5fcc add r2, r2, #1
 *   @0x2c5fd0 vmul.f32 s14, s14, s15
 *   @0x2c5fd4 vnmls.f32 s13, s12, s15
 *   @0x2c5fd8 vmla.f32 s14, s12, s16
 *   @0x2c5fdc vadd.f32 s13, s18, s13
 *   @0x2c5fe0 vadd.f32 s14, s17, s14
 *   @0x2c5fe4 vstr s13, [r3, #-64]
 *   @0x2c5fe8 vstr s14, [r1, #-64]
 *   @0x2c5fec vldr s14, [r3, #4]
 *   @0x2c5ff0 vmul.f32 s13, s14, s16
 *   @0x2c5ff4 vldr s12, [r3]
 *   @0x2c5ff8 vnmls.f32 s13, s12, s15
 *   @0x2c5ffc vmul.f32 s14, s14, s15
 *   @0x2c6000 vmov r0, s13
 *   @0x2c6004 vmla.f32 s14, s12, s16
 *   @0x2c6008 str r0, [r3], #8
 *   @0x2c600c vmov r0, s14
 *   @0x2c6010 str r0, [r1], #8
 *   @0x2c6014 ldr r0, [r4, #0x94]
 *   @0x2c6018 cmp r0, r2
 *   @0x2c601c bgt 0x2c5fc0 <_ZN14b2PolygonShape8SetAsBoxEffRK6b2Vec2f+0xb0>
 *   @0x2c6020 vpop {d8, d9}
 *   @0x2c6024 pop {r3, r4, r5, pc}
 *
 * ══ §35/110 Background_Replace_Alpha(int, char const*, bool)  0xc3e60  size 276  69 条（0xc3e60..0xc3f74）
 * @func 0xc3e60 0xc3f74  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Background_Replace_Alpha(int, char const*, bool)+0x40 / Background_Replace_Alpha(int, char const*, bool)+0x60 / LoadSave::SaveFileExists(char const*) / LoadSave::BundleFileExists(char const*) / LoadSave::_GetBundleFileName(char*, int, char const*) / CBackground::LoadFromFile(char const*, bool, bool, bool, bool) / LoadSave::_GetSaveFileName(char*, int, char const*) / operator new(unsigned int)
 * 字段偏移 top8: 0x4×4 / 0x2×3 / 0x40c×2 / 0xf8×1 / 0xd8×1 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc3e60 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xc3e64 sub sp, sp, #1040
 *   @0xc3e68 ldr r4, [pc, #0xf8]
 *   @0xc3e6c sub sp, sp, #4
 *   @0xc3e70 subs r5, r0, #0
 *   @0xc3e74 mov r6, r1
 *   @0xc3e78 ldr r4, [pc, r4]
 *   @0xc3e7c mov r7, r2
 *   @0xc3e80 ldr r3, [r4]
 *   @0xc3e84 str r3, [sp, #0x40c]
 *   @0xc3e88 blt 0xc3ea0 <_Z24Background_Replace_AlphaiPKcb+0x40>
 *   @0xc3e8c ldr r3, [pc, #0xd8]
 *   @0xc3e90 ldr r3, [pc, r3]
 *   @0xc3e94 ldr r3, [r3]
 *   @0xc3e98 cmp r5, r3
 *   @0xc3e9c blt 0xc3ec0 <_Z24Background_Replace_AlphaiPKcb+0x60>
 *   @0xc3ea0 mov r0, #0
 *   @0xc3ea4 ldr r2, [sp, #0x40c]
 *   @0xc3ea8 ldr r3, [r4]
 *   @0xc3eac cmp r2, r3
 *   @0xc3eb0 bne 0xc3f64 <_Z24Background_Replace_AlphaiPKcb+0x104>
 *   @0xc3eb4 add sp, sp, #1040
 *   @0xc3eb8 add sp, sp, #4
 *   @0xc3ebc pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xc3ec0 mov r0, r1
 *   @0xc3ec4 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xc3ec8 cmp r0, #0
 *   @0xc3ecc bne 0xc3f28 <_Z24Background_Replace_AlphaiPKcb+0xc8>
 *   @0xc3ed0 mov r0, r6
 *   @0xc3ed4 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0xc3ed8 cmp r0, #0
 *   @0xc3edc beq 0xc3ea0 <_Z24Background_Replace_AlphaiPKcb+0x40>
 *   @0xc3ee0 mov r2, r6
 *   @0xc3ee4 add r6, sp, #12
 *   @0xc3ee8 mov r1, #1024
 *   @0xc3eec mov r0, r6
 *   @0xc3ef0 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0xc3ef4 ldr r8, [pc, #0x74]
 *   @0xc3ef8 add r8, pc, r8
 *   @0xc3efc ldr r3, [r8, #0x4]
 *   @0xc3f00 ldr r0, [r3, r5, lsl #2]
 *   @0xc3f04 cmp r0, #0
 *   @0xc3f08 beq 0xc3f40 <_Z24Background_Replace_AlphaiPKcb+0xe0>
 *   @0xc3f0c mov r2, #1
 *   @0xc3f10 str r7, [sp]
 *   @0xc3f14 mov r1, r6
 *   @0xc3f18 str r2, [sp, #0x4]
 *   @0xc3f1c mov r3, #0
 *   @0xc3f20 bl 0xc2984 <_ZN11CBackground12LoadFromFileEPKcbbbb>
 *   @0xc3f24 b 0xc3ea4 <_Z24Background_Replace_AlphaiPKcb+0x44>
 *   @0xc3f28 mov r2, r6
 *   @0xc3f2c add r6, sp, #12
 *   @0xc3f30 mov r1, #1024
 *   @0xc3f34 mov r0, r6
 *   @0xc3f38 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0xc3f3c b 0xc3ef4 <_Z24Background_Replace_AlphaiPKcb+0x94>
 *   @0xc3f40 mov r0, #72
 *   @0xc3f44 bl 0x27c524 <_Znwj>
 *   @0xc3f48 mov r9, r0
 *   @0xc3f4c bl 0xc2b58 <_ZN11CBackgroundC2Ev>
 *   @0xc3f50 ldr r3, [r8, #0x4]
 *   @0xc3f54 str r9, [r3, r5, lsl #2]
 *   @0xc3f58 ldr r3, [r8, #0x4]
 *   @0xc3f5c ldr r0, [r3, r5, lsl #2]
 *   @0xc3f60 b 0xc3f0c <_Z24Background_Replace_AlphaiPKcb+0xac>
 *   @0xc3f64 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xc3f68 ldrsbteq r9, [r2], -r8
 *   @0xc3f6c ldrhteq r9, [r2], -r8
 *   @0xc3f70 ldrhteq r5, [r11], -r0
 *
 * ══ §36/110 Buffer_Vertex::FindNextUsage(yyVertexUsage, yyVertexType)  0xc8648  size 276  69 条（0xc8648..0xc875c）
 * @func 0xc8648 0xc875c  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×3 / GetVertexFormat(int) / Buffer_Vertex::FindNextUsage(yyVertexUsage, yyVertexType)+0xd8
 * 字段偏移 top8: 0x18×4 / 0xc×3 / 0x4×2 / 0x8×2 / 0x1c×2 / 0x24×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8648 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xc864c mov r7, r0
 *   @0xc8650 ldr r0, [r0, #0x24]
 *   @0xc8654 mov r5, r1
 *   @0xc8658 mov r6, r2
 *   @0xc865c bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0xc8660 subs r9, r0, #0
 *   @0xc8664 beq 0xc8738 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0xf0>
 *   @0xc8668 ldr r4, [r9, #0x4]
 *   @0xc866c ldr r3, [r9, #0x8]
 *   @0xc8670 cmp r4, #0
 *   @0xc8674 ble 0xc8720 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0xd8>
 *   @0xc8678 mov r8, #0
 *   @0xc867c b 0xc868c <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0x44>
 *   @0xc8680 subs r4, r4, #1
 *   @0xc8684 add r3, r3, #16
 *   @0xc8688 beq 0xc8700 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0xb8>
 *   @0xc868c ldr r12, [r3, #0x8]
 *   @0xc8690 cmp r12, r5
 *   @0xc8694 bne 0xc8680 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0x38>
 *   @0xc8698 ldr r1, [r3, #0x4]
 *   @0xc869c cmp r1, r6
 *   @0xc86a0 bne 0xc8680 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0x38>
 *   @0xc86a4 ldr r1, [r3, #0xc]
 *   @0xc86a8 mov r8, #1
 *   @0xc86ac ldr r2, [r7, #0x18]
 *   @0xc86b0 ands r12, r1, r2
 *   @0xc86b4 bne 0xc8680 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0x38>
 *   @0xc86b8 ldr r0, [r9, #0x10]
 *   @0xc86bc orr r2, r1, r2
 *   @0xc86c0 ldr r1, [r3]
 *   @0xc86c4 ldr r3, [r7, #0xc]
 *   @0xc86c8 cmp r2, r0
 *   @0xc86cc ldr r0, [r7]
 *   @0xc86d0 add r1, r3, r1
 *   @0xc86d4 str r2, [r7, #0x18]
 *   @0xc86d8 add r0, r0, r1
 *   @0xc86dc popne {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xc86e0 ldr r1, [r9, #0x14]
 *   @0xc86e4 ldr r2, [r7, #0x1c]
 *   @0xc86e8 add r3, r1, r3
 *   @0xc86ec str r12, [r7, #0x18]
 *   @0xc86f0 str r3, [r7, #0xc]
 *   @0xc86f4 add r3, r2, r8
 *   @0xc86f8 str r3, [r7, #0x1c]
 *   @0xc86fc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xc8700 cmp r8, #0
 *   @0xc8704 beq 0xc8720 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType+0xd8>
 *   @0xc8708 ldr r0, [pc, #0x40]
 *   @0xc870c mov r1, #1
 *   @0xc8710 add r0, pc, r0
 *   @0xc8714 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc8718 mov r0, r4
 *   @0xc871c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xc8720 ldr r0, [pc, #0x2c]
 *   @0xc8724 mov r1, #1
 *   @0xc8728 add r0, pc, r0
 *   @0xc872c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc8730 mov r0, #0
 *   @0xc8734 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xc8738 ldr r0, [pc, #0x18]
 *   @0xc873c mov r1, #1
 *   @0xc8740 add r0, pc, r0
 *   @0xc8744 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc8748 mov r0, r9
 *   @0xc874c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xc8750 .word 0x002691b0
 *   @0xc8754 eoreq r9, r6, r8, ror #3
 *   @0xc8758 eoreq r9, r6, r8, asr r1
 *
 * ══ §37/110 IBuffer::GetSurface(int, int, int, int)  0xcc728  size 276  69 条（0xcc728..0xcc83c）
 * @func 0xcc728 0xcc83c  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_Exists(int) / GR_Surface_Get_Width(int) / GR_Surface_Get_Height(int) / IBuffer::GetSurface(int, int, int, int)+0x28 / GR_Texture_Get_Surface(int) / Graphics::Surface_GrabRect(void*, int, int, int, int) / IBuffer::GetSurface(int, int, int, int)+0x100 / 0xb65bc
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x30×1 / 0x10×1 / 0xac×1 / 0x3×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcc728 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xcc72c sub sp, sp, #16
 *   @0xcc730 mov r10, r0
 *   @0xcc734 mov r0, r1
 *   @0xcc738 mov r4, r1
 *   @0xcc73c mov r5, r3
 *   @0xcc740 ldr r8, [sp, #0x30]
 *   @0xcc744 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0xcc748 cmp r0, #0
 *   @0xcc74c bne 0xcc758 <_ZN7IBuffer10GetSurfaceEiiii+0x30>
 *   @0xcc750 add sp, sp, #16
 *   @0xcc754 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcc758 mov r0, r4
 *   @0xcc75c bl 0x1714d4 <_Z20GR_Surface_Get_Widthi>
 *   @0xcc760 mov r6, r0
 *   @0xcc764 mov r0, r4
 *   @0xcc768 bl 0x171518 <_Z21GR_Surface_Get_Heighti>
 *   @0xcc76c ldr r2, [r10, #0x10]
 *   @0xcc770 mul r3, r0, r6
 *   @0xcc774 mov r7, r0
 *   @0xcc778 add r3, r5, r3, lsl #2
 *   @0xcc77c cmp r2, r3
 *   @0xcc780 blt 0xcc750 <_ZN7IBuffer10GetSurfaceEiiii+0x28>
 *   @0xcc784 ldr r3, [pc, #0xac]
 *   @0xcc788 ldr r3, [pc, r3]
 *   @0xcc78c ldr r2, [r3, #0x4]
 *   @0xcc790 ldr r3, [r3]
 *   @0xcc794 and r2, r4, r2
 *   @0xcc798 ldr r12, [r3, r2, lsl #3]
 *   @0xcc79c cmp r12, #0
 *   @0xcc7a0 bne 0xcc7b4 <_ZN7IBuffer10GetSurfaceEiiii+0x8c>
 *   @0xcc7a4 b 0xcc7c4 <_ZN7IBuffer10GetSurfaceEiiii+0x9c>
 *   @0xcc7a8 ldr r12, [r12, #0x4]
 *   @0xcc7ac cmp r12, #0
 *   @0xcc7b0 beq 0xcc7c4 <_ZN7IBuffer10GetSurfaceEiiii+0x9c>
 *   @0xcc7b4 ldr r3, [r12, #0x8]
 *   @0xcc7b8 cmp r4, r3
 *   @0xcc7bc bne 0xcc7a8 <_ZN7IBuffer10GetSurfaceEiiii+0x80>
 *   @0xcc7c0 ldr r12, [r12, #0xc]
 *   @0xcc7c4 ldr r0, [r12, #0x4]
 *   @0xcc7c8 bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0xcc7cc mov r1, #0
 *   @0xcc7d0 mov r3, r6
 *   @0xcc7d4 str r7, [sp]
 *   @0xcc7d8 mov r2, r1
 *   @0xcc7dc bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii>
 *   @0xcc7e0 cmp r7, #0
 *   @0xcc7e4 ldr r12, [r10, #0xc]
 *   @0xcc7e8 lslgt r6, r6, #2
 *   @0xcc7ec addgt r8, r8, r6
 *   @0xcc7f0 movgt r4, #0
 *   @0xcc7f4 add r12, r12, r5
 *   @0xcc7f8 mov r9, r0
 *   @0xcc7fc movgt r5, r0
 *   @0xcc800 ble 0xcc828 <_ZN7IBuffer10GetSurfaceEiiii+0x100>
 *   @0xcc804 mov r0, r12
 *   @0xcc808 mov r1, r5
 *   @0xcc80c mov r2, r6
 *   @0xcc810 add r4, r4, #1
 *   @0xcc814 bl 0xb65bc <memcpy@plt>
 *   @0xcc818 cmp r4, r7
 *   @0xcc81c add r5, r5, r6
 *   @0xcc820 add r12, r0, r8
 *   @0xcc824 bne 0xcc804 <_ZN7IBuffer10GetSurfaceEiiii+0xdc>
 *   @0xcc828 mov r0, r9
 *   @0xcc82c add sp, sp, #16
 *   @0xcc830 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xcc834 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcc838 eorseq r1, r2, r8, lsl #7
 *
 * ══ §38/110 F_DateGetHourOfYear(RValue&, CInstance*, CInstance*, int, RValue*)  0x1183e8  size 276  69 条（0x1183e8..0x1184fc）
 * @func 0x1183e8 0x1184fc  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / GetSecondOfYear(int, int, int, int, int, int) / 0xb682c / 0x8291a4
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x18×1 / 0xac×1 / 0x14×1 / 0x10×1 / 0x8×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1183e8 push {r4, lr}
 *   @0x1183ec sub sp, sp, #16
 *   @0x1183f0 mov r3, #0
 *   @0x1183f4 mov r4, r0
 *   @0x1183f8 str r3, [r0, #0xc]
 *   @0x1183fc mov r1, r3
 *   @0x118400 str r3, [r0]
 *   @0x118404 str r3, [r0, #0x4]
 *   @0x118408 ldr r0, [sp, #0x18]
 *   @0x11840c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x118410 vldr d7, [pc, #200]
 *   @0x118414 vldr d5, [pc, #204]
 *   @0x118418 vmov d6, r0, r1
 *   @0x11841c vsub.f64 d7, d6, d7
 *   @0x118420 vabs.f64 d4, d7
 *   @0x118424 vcmpe.f64 d4, d5
 *   @0x118428 vmrs APSR_nzcv, fpscr
 *   @0x11842c vldrls d7, [pc, #188]
 *   @0x118430 vldrhi d6, [pc, #184]
 *   @0x118434 vmul.f64 d5, d7, d6
 *   @0x118438 vmov r0, r1, d5
 *   @0x11843c bl 0x3194a0 <__fixdfdi>
 *   @0x118440 mov r3, r1
 *   @0x118444 ldr r1, [pc, #0xac]
 *   @0x118448 mov r2, r0
 *   @0x11844c strd r2, r3, [sp, #8]
 *   @0x118450 add r1, pc, r1
 *   @0x118454 add r0, sp, #8
 *   @0x118458 ldrb r3, [r1]
 *   @0x11845c cmp r3, #0
 *   @0x118460 bne 0x1184d4 <_Z19F_DateGetHourOfYearR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x118464 bl 0xb6820 <gmtime64@plt>
 *   @0x118468 mov r12, r0
 *   @0x11846c cmp r12, #0
 *   @0x118470 beq 0x1184cc <_Z19F_DateGetHourOfYearR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x118474 ldr lr, [r12, #0x4]
 *   @0x118478 ldr r2, [r12, #0xc]
 *   @0x11847c ldr r0, [r12, #0x14]
 *   @0x118480 ldr r1, [r12, #0x10]
 *   @0x118484 ldr r3, [r12, #0x8]
 *   @0x118488 add r0, r0, #1888
 *   @0x11848c str lr, [sp]
 *   @0x118490 add r1, r1, #1
 *   @0x118494 ldr r12, [r12]
 *   @0x118498 add r0, r0, #12
 *   @0x11849c str r12, [sp, #0x4]
 *   @0x1184a0 bl 0x1180c0 <_Z15GetSecondOfYeariiiiii>
 *   @0x1184a4 movw r3, #0xb3c5
 *   @0x1184a8 movt r3, #0x91a2
 *   @0x1184ac smull r2, r3, r3, r0
 *   @0x1184b0 asr r1, r0, #31
 *   @0x1184b4 add r0, r3, r0
 *   @0x1184b8 rsb r0, r1, r0, asr #11
 *   @0x1184bc vmov s11, r0
 *   @0x1184c0 vcvt.f64.s32 d5, s11
 *   @0x1184c4 vmov r2, r3, d5
 *   @0x1184c8 stm r4, {r2, r3}
 *   @0x1184cc add sp, sp, #16
 *   @0x1184d0 pop {r4, pc}
 *   @0x1184d4 bl 0xb682c <localtime64@plt>
 *   @0x1184d8 mov r12, r0
 *   @0x1184dc b 0x11846c <_Z19F_DateGetHourOfYearR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1184e0 andeq r0, r0, r0
 *   @0x1184e4 sbcsmi pc, r8, r0, asr #16
 *   @0x1184e8 bl 0x8291a4 <b2_toiTime+0xcfd00>
 *   @0x1184ec svclo #0x1a36e2
 *   @0x1184f0 andeq r0, r0, r0
 *   @0x1184f4 rscsmi r1, r5, r0, lsl #16
 *   @0x1184f8 eoreq r9, sp, r8, ror #25
 *
 * ══ §39/110 F_DateGetMinuteOfYear(RValue&, CInstance*, CInstance*, int, RValue*)  0x118500  size 276  69 条（0x118500..0x118614）
 * @func 0x118500 0x118614  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / GetSecondOfYear(int, int, int, int, int, int) / 0xb682c / 0x8292bc
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x18×1 / 0xac×1 / 0x14×1 / 0x10×1 / 0x8×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x118500 push {r4, lr}
 *   @0x118504 sub sp, sp, #16
 *   @0x118508 mov r3, #0
 *   @0x11850c mov r4, r0
 *   @0x118510 str r3, [r0, #0xc]
 *   @0x118514 mov r1, r3
 *   @0x118518 str r3, [r0]
 *   @0x11851c str r3, [r0, #0x4]
 *   @0x118520 ldr r0, [sp, #0x18]
 *   @0x118524 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x118528 vldr d7, [pc, #200]
 *   @0x11852c vldr d5, [pc, #204]
 *   @0x118530 vmov d6, r0, r1
 *   @0x118534 vsub.f64 d7, d6, d7
 *   @0x118538 vabs.f64 d4, d7
 *   @0x11853c vcmpe.f64 d4, d5
 *   @0x118540 vmrs APSR_nzcv, fpscr
 *   @0x118544 vldrls d7, [pc, #188]
 *   @0x118548 vldrhi d6, [pc, #184]
 *   @0x11854c vmul.f64 d5, d7, d6
 *   @0x118550 vmov r0, r1, d5
 *   @0x118554 bl 0x3194a0 <__fixdfdi>
 *   @0x118558 mov r3, r1
 *   @0x11855c ldr r1, [pc, #0xac]
 *   @0x118560 mov r2, r0
 *   @0x118564 strd r2, r3, [sp, #8]
 *   @0x118568 add r1, pc, r1
 *   @0x11856c add r0, sp, #8
 *   @0x118570 ldrb r3, [r1]
 *   @0x118574 cmp r3, #0
 *   @0x118578 bne 0x1185ec <_Z21F_DateGetMinuteOfYearR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x11857c bl 0xb6820 <gmtime64@plt>
 *   @0x118580 mov r12, r0
 *   @0x118584 cmp r12, #0
 *   @0x118588 beq 0x1185e4 <_Z21F_DateGetMinuteOfYearR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x11858c ldr lr, [r12, #0x4]
 *   @0x118590 ldr r2, [r12, #0xc]
 *   @0x118594 ldr r0, [r12, #0x14]
 *   @0x118598 ldr r1, [r12, #0x10]
 *   @0x11859c ldr r3, [r12, #0x8]
 *   @0x1185a0 add r0, r0, #1888
 *   @0x1185a4 str lr, [sp]
 *   @0x1185a8 add r1, r1, #1
 *   @0x1185ac ldr r12, [r12]
 *   @0x1185b0 add r0, r0, #12
 *   @0x1185b4 str r12, [sp, #0x4]
 *   @0x1185b8 bl 0x1180c0 <_Z15GetSecondOfYeariiiiii>
 *   @0x1185bc movw r3, #0x8889
 *   @0x1185c0 movt r3, #0x8888
 *   @0x1185c4 smull r2, r3, r3, r0
 *   @0x1185c8 asr r1, r0, #31
 *   @0x1185cc add r0, r3, r0
 *   @0x1185d0 rsb r0, r1, r0, asr #5
 *   @0x1185d4 vmov s11, r0
 *   @0x1185d8 vcvt.f64.s32 d5, s11
 *   @0x1185dc vmov r2, r3, d5
 *   @0x1185e0 stm r4, {r2, r3}
 *   @0x1185e4 add sp, sp, #16
 *   @0x1185e8 pop {r4, pc}
 *   @0x1185ec bl 0xb682c <localtime64@plt>
 *   @0x1185f0 mov r12, r0
 *   @0x1185f4 b 0x118584 <_Z21F_DateGetMinuteOfYearR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1185f8 andeq r0, r0, r0
 *   @0x1185fc sbcsmi pc, r8, r0, asr #16
 *   @0x118600 bl 0x8292bc <b2_toiTime+0xcfe18>
 *   @0x118604 svclo #0x1a36e2
 *   @0x118608 andeq r0, r0, r0
 *   @0x11860c rscsmi r1, r5, r0, lsl #16
 *   @0x118610 .word 0x002d9bd0
 *
 * ══ §40/110 F_DrawSpriteTiledExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x122f74  size 276  69 条（0x122f74..0x123088）
 * @func 0x122f74 0x123088  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / GetSpriteIndices(CInstance*, RValue*, int&, int&) / Sprite_Data(int) / YYGetInt32(RValue const*, int) / CSprite::DrawTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x60×1 / 0x28×1 / 0x2c×1 / 0x84×1 / 0x4×1 / 0x20×1 / 0x8×1 / 0xc×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x122f74 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x122f78 vpush {d8}
 *   @0x122f7c sub sp, sp, #52
 *   @0x122f80 mov r0, r1
 *   @0x122f84 add r2, sp, #40
 *   @0x122f88 ldr r4, [sp, #0x60]
 *   @0x122f8c add r3, sp, #44
 *   @0x122f90 mov r1, r4
 *   @0x122f94 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_>
 *   @0x122f98 cmp r0, #0
 *   @0x122f9c bne 0x122fac <_Z20F_DrawSpriteTiledExtR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x122fa0 add sp, sp, #52
 *   @0x122fa4 vpop {d8}
 *   @0x122fa8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x122fac ldr r0, [sp, #0x28]
 *   @0x122fb0 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x122fb4 mov r1, #2
 *   @0x122fb8 ldr r8, [sp, #0x2c]
 *   @0x122fbc mov r5, r0
 *   @0x122fc0 mov r0, r4
 *   @0x122fc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122fc8 mov r1, #3
 *   @0x122fcc mov r7, r0
 *   @0x122fd0 mov r0, r4
 *   @0x122fd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122fd8 mov r1, #4
 *   @0x122fdc mov r6, r0
 *   @0x122fe0 mov r0, r4
 *   @0x122fe4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122fe8 mov r1, #5
 *   @0x122fec mov r11, r0
 *   @0x122ff0 mov r0, r4
 *   @0x122ff4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122ff8 ldr r12, [pc, #0x84]
 *   @0x122ffc mov r1, #6
 *   @0x123000 ldr r12, [pc, r12]
 *   @0x123004 ldr r12, [r12]
 *   @0x123008 vldr s17, [r12, #16]
 *   @0x12300c vldr s16, [r12, #20]
 *   @0x123010 vcvt.f32.s32 s17, s17
 *   @0x123014 vcvt.f32.s32 s16, s16
 *   @0x123018 mov r10, r0
 *   @0x12301c mov r0, r4
 *   @0x123020 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x123024 mov r1, #7
 *   @0x123028 mov r9, r0
 *   @0x12302c mov r0, r4
 *   @0x123030 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x123034 mov r12, #1
 *   @0x123038 mov lr, #0
 *   @0x12303c str r11, [sp]
 *   @0x123040 vstr s17, [sp, #24]
 *   @0x123044 str r10, [sp, #0x4]
 *   @0x123048 str r9, [sp, #0x20]
 *   @0x12304c mov r1, r8
 *   @0x123050 mov r2, r7
 *   @0x123054 vstr s16, [sp, #28]
 *   @0x123058 mov r3, r6
 *   @0x12305c str r12, [sp, #0x8]
 *   @0x123060 str r12, [sp, #0xc]
 *   @0x123064 str lr, [sp, #0x10]
 *   @0x123068 str lr, [sp, #0x14]
 *   @0x12306c str r0, [sp, #0x24]
 *   @0x123070 mov r0, r5
 *   @0x123074 bl 0x1ed1dc <_ZN7CSprite9DrawTiledEiffffbbffffjf>
 *   @0x123078 add sp, sp, #52
 *   @0x12307c vpop {d8}
 *   @0x123080 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x123084 eoreq r10, r12, r8, lsr #18
 *
 * ══ §41/110 F_SpriteAssign(RValue&, CInstance*, CInstance*, int, RValue*)  0x1300b8  size 276  69 条（0x1300b8..0x1301cc）
 * @func 0x1300b8 0x1301cc  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sprite_Data(int)×2 / Sprite_Assign(int, int)
 * 字段偏移 top8: 0x74×2 / 0x10×1 / 0x68×1 / 0x5c×1 / 0x50×1 / 0x40×1 / 0x30×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1300b8 push {r4, r5, r6, lr}
 *   @0x1300bc mov r1, #0
 *   @0x1300c0 ldr r4, [sp, #0x10]
 *   @0x1300c4 mov r0, r4
 *   @0x1300c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1300cc mov r1, #1
 *   @0x1300d0 mov r6, r0
 *   @0x1300d4 mov r0, r4
 *   @0x1300d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1300dc mov r5, r0
 *   @0x1300e0 mov r0, r6
 *   @0x1300e4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1300e8 mov r4, r0
 *   @0x1300ec mov r0, r5
 *   @0x1300f0 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1300f4 cmp r0, #0
 *   @0x1300f8 cmpne r4, #0
 *   @0x1300fc moveq r1, #0
 *   @0x130100 movne r1, #1
 *   @0x130104 beq 0x130154 <_Z14F_SpriteAssignR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x130108 ldr r2, [r4, #0x74]
 *   @0x13010c cmp r2, #1
 *   @0x130110 beq 0x130178 <_Z14F_SpriteAssignR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x130114 ldr r3, [r0, #0x74]
 *   @0x130118 cmp r3, #1
 *   @0x13011c beq 0x13018c <_Z14F_SpriteAssignR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x130120 cmp r2, #2
 *   @0x130124 beq 0x1301a0 <_Z14F_SpriteAssignR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x130128 cmp r3, #2
 *   @0x13012c beq 0x130164 <_Z14F_SpriteAssignR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x130130 mov r1, r5
 *   @0x130134 mov r0, r6
 *   @0x130138 bl 0x1ef454 <_Z13Sprite_Assignii>
 *   @0x13013c subs r1, r0, #0
 *   @0x130140 popne {r4, r5, r6, pc}
 *   @0x130144 ldr r0, [pc, #0x68]
 *   @0x130148 pop {r4, r5, r6, lr}
 *   @0x13014c add r0, pc, r0
 *   @0x130150 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x130154 ldr r0, [pc, #0x5c]
 *   @0x130158 pop {r4, r5, r6, lr}
 *   @0x13015c add r0, pc, r0
 *   @0x130160 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x130164 ldr r0, [pc, #0x50]
 *   @0x130168 mov r1, #0
 *   @0x13016c pop {r4, r5, r6, lr}
 *   @0x130170 add r0, pc, r0
 *   @0x130174 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x130178 ldr r0, [pc, #0x40]
 *   @0x13017c mov r1, #0
 *   @0x130180 pop {r4, r5, r6, lr}
 *   @0x130184 add r0, pc, r0
 *   @0x130188 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13018c ldr r0, [pc, #0x30]
 *   @0x130190 mov r1, #0
 *   @0x130194 pop {r4, r5, r6, lr}
 *   @0x130198 add r0, pc, r0
 *   @0x13019c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1301a0 ldr r0, [pc, #0x20]
 *   @0x1301a4 mov r1, #0
 *   @0x1301a8 pop {r4, r5, r6, lr}
 *   @0x1301ac add r0, pc, r0
 *   @0x1301b0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1301b4 eoreq sp, r0, r12, lsr #25
 *   @0x1301b8 .word 0x0020dcb8
 *   @0x1301bc eoreq sp, r0, r8, lsr #24
 *   @0x1301c0 eoreq sp, r0, r4, lsl #22
 *   @0x1301c4 eoreq sp, r0, r8, asr #22
 *   @0x1301c8 eoreq sp, r0, r8, lsl #23
 *
 * ══ §42/110 F_YoYo_SetGUIMaximise(RValue&, CInstance*, CInstance*, int, RValue*)  0x1577f4  size 276  69 条（0x1577f4..0x157908）
 * @func 0x1577f4 0x157908  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x157804→0x5425a5, 0x157810→0x3f50c8, 0x157814→0x3f50c4, 0x157824→0x3f50c0, 0x157828→0x3f50bc, 0x157834→0x3f50d0, 0x157838→0x3f50cc, 0x1578c8→0x5425a4
 * 调用序列: YYGetFloat(RValue const*, int)×4 / F_YoYo_SetGUIMaximise(RValue&, CInstance*, CInstance*, int, RValue*)+0xd4
 * 字段偏移 top8: 0xd4×2 / 0xc8×2 / 0xc0×2 / 0xe0×1 / 0xdc×1 / 0x28×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1577f4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1577f8 mov r11, #1
 *   @0x1577fc ldr r4, [pc, #0xe0]
 *   @0x157800 mov r1, #1325400064
 *   @0x157804 ldr r5, [pc, #0xdc]
 *   @0x157808 mov r0, #1065353216
 *   @0x15780c add r4, pc, r4
 *   @0x157810 ldr r8, [pc, #0xd4]
 *   @0x157814 ldr r12, [pc, #0xd4]
 *   @0x157818 subs r7, r3, #0
 *   @0x15781c ldr r9, [r4, r5]
 *   @0x157820 mvn r2, #0
 *   @0x157824 ldr r6, [pc, #0xc8]
 *   @0x157828 ldr r5, [pc, #0xc8]
 *   @0x15782c strb r11, [r9]
 *   @0x157830 ldr r9, [r4, r8]
 *   @0x157834 ldr r10, [pc, #0xc0]
 *   @0x157838 ldr r3, [pc, #0xc0]
 *   @0x15783c str r1, [r9]
 *   @0x157840 ldr r8, [r4, r12]
 *   @0x157844 str r1, [r8]
 *   @0x157848 ldr r6, [r4, r6]
 *   @0x15784c str r0, [r6]
 *   @0x157850 ldr r5, [r4, r5]
 *   @0x157854 str r0, [r5]
 *   @0x157858 ldr r1, [r4, r10]
 *   @0x15785c ldr r10, [sp, #0x28]
 *   @0x157860 str r2, [r1]
 *   @0x157864 ldr r3, [r4, r3]
 *   @0x157868 str r2, [r3]
 *   @0x15786c ble 0x1578c8 <_Z21F_YoYo_SetGUIMaximiseR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x157870 mov r0, r10
 *   @0x157874 mov r1, #0
 *   @0x157878 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x15787c cmp r7, r11
 *   @0x157880 str r0, [r6]
 *   @0x157884 beq 0x1578c8 <_Z21F_YoYo_SetGUIMaximiseR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x157888 mov r1, r11
 *   @0x15788c mov r0, r10
 *   @0x157890 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x157894 cmp r7, #2
 *   @0x157898 str r0, [r5]
 *   @0x15789c beq 0x1578c8 <_Z21F_YoYo_SetGUIMaximiseR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x1578a0 mov r0, r10
 *   @0x1578a4 mov r1, #2
 *   @0x1578a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1578ac cmp r7, #3
 *   @0x1578b0 str r0, [r9]
 *   @0x1578b4 beq 0x1578c8 <_Z21F_YoYo_SetGUIMaximiseR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x1578b8 mov r0, r10
 *   @0x1578bc mov r1, #3
 *   @0x1578c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1578c4 str r0, [r8]
 *   @0x1578c8 ldr r3, [pc, #0x34]
 *   @0x1578cc ldr r3, [r4, r3]
 *   @0x1578d0 ldrb r3, [r3]
 *   @0x1578d4 cmp r3, #0
 *   @0x1578d8 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1578dc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1578e0 b 0x1b3204 <_Z14Calc_GUI_Scalev>
 *   @0x1578e4 eoreq r10, r9, r4, asr #8
 *   @0x1578e8 .word 0xffffdf14
 *   @0x1578ec .word 0xffffdf1c
 *   @0x1578f0 .word 0xffffdf20
 *   @0x1578f4 .word 0xffffdf28
 *   @0x1578f8 .word 0xffffdf2c
 *   @0x1578fc .word 0xffffdf18
 *   @0x157900 .word 0xffffdf24
 *   @0x157904 .word 0xffffdf30
 *
 * ══ §43/110 GR_D3D_Settings_Init()  0x168a50  size 276  69 条（0x168a50..0x168b64）
 * @func 0x168a50 0x168b64  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x168a58→0x4a22b1, 0x168a70→0x48ffe4, 0x168a84→0x4859c8, 0x168a9c→0x3f23bc, 0x168aac→0x489788, 0x168ab0→0x3f23b8, 0x168ab4→0x489790, 0x168adc→0x48978c
 * 调用序列: Graphics::ResetBlends() / RenderStateManager::SetRenderState(eRenderState, unsigned int) / SetZBuffer(bool) / GR_D3D_Set_Fog(bool, unsigned int, short, short) / Graphics::SetTexture(int, void*) / GR_D3D_Set_Texture_Interpolation(bool) / GR_D3D_Set_Texture_Blending(bool) / GR_D3D_Set_Texture_Repeat(bool)
 * 字段偏移 top8: 0x98×3 / 0xdc×2 / 0xc8×1 / 0xb8×1 / 0xa4×1 / 0x74×1 / 0x50×1 / 0x3c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168a50 push {r3, r4, r5, r6, r7, lr}
 *   @0x168a54 ldr r4, [pc, #0xdc]
 *   @0x168a58 ldr r3, [pc, #0xdc]
 *   @0x168a5c add r4, pc, r4
 *   @0x168a60 ldr r3, [r4, r3]
 *   @0x168a64 ldrb r3, [r3]
 *   @0x168a68 cmp r3, #0
 *   @0x168a6c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x168a70 ldr r3, [pc, #0xc8]
 *   @0x168a74 mov r7, #0
 *   @0x168a78 ldr r6, [r4, r3]
 *   @0x168a7c str r7, [r6]
 *   @0x168a80 bl 0x1804ac <_ZN8Graphics11ResetBlendsEv>
 *   @0x168a84 ldr r3, [pc, #0xb8]
 *   @0x168a88 mov r1, #12
 *   @0x168a8c mov r2, #1
 *   @0x168a90 ldr r5, [r4, r3]
 *   @0x168a94 mov r0, r5
 *   @0x168a98 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168a9c ldr r3, [pc, #0xa4]
 *   @0x168aa0 ldr r3, [r4, r3]
 *   @0x168aa4 ldrb r0, [r3]
 *   @0x168aa8 bl 0x16841c <_Z10SetZBufferb>
 *   @0x168aac ldr r1, [pc, #0x98]
 *   @0x168ab0 ldr r2, [pc, #0x98]
 *   @0x168ab4 ldr r3, [pc, #0x98]
 *   @0x168ab8 ldr r1, [r4, r1]
 *   @0x168abc vldr s15, [r1]
 *   @0x168ac0 vcvt.s32.f32 s15, s15
 *   @0x168ac4 ldr r1, [r4, r2]
 *   @0x168ac8 ldr r3, [r4, r3]
 *   @0x168acc ldrb r0, [r3]
 *   @0x168ad0 vmov r2, s15
 *   @0x168ad4 vldr s15, [r1]
 *   @0x168ad8 vcvt.s32.f32 s15, s15
 *   @0x168adc ldr r1, [pc, #0x74]
 *   @0x168ae0 ldr r1, [r4, r1]
 *   @0x168ae4 ldr r1, [r1]
 *   @0x168ae8 vmov r3, s15
 *   @0x168aec sxth r2, r2
 *   @0x168af0 sxth r3, r3
 *   @0x168af4 bl 0x168520 <_Z14GR_D3D_Set_Fogbjss>
 *   @0x168af8 mov r1, r7
 *   @0x168afc ldr r0, [r6]
 *   @0x168b00 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x168b04 ldr r3, [pc, #0x50]
 *   @0x168b08 ldr r3, [r4, r3]
 *   @0x168b0c ldrb r0, [r3]
 *   @0x168b10 bl 0x168710 <_Z32GR_D3D_Set_Texture_Interpolationb>
 *   @0x168b14 mov r0, #1
 *   @0x168b18 bl 0x1689c8 <_Z27GR_D3D_Set_Texture_Blendingb>
 *   @0x168b1c ldr r3, [pc, #0x3c]
 *   @0x168b20 ldr r3, [r4, r3]
 *   @0x168b24 ldrb r0, [r3]
 *   @0x168b28 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x168b2c mov r0, r5
 *   @0x168b30 pop {r3, r4, r5, r6, r7, lr}
 *   @0x168b34 b 0x168294 <_ZN18RenderStateManager5ForceEv>
 *   @0x168b38 .word 0x002891f4
 *   @0x168b3c .word 0xffffe4d0
 *   @0x168b40 .word 0xffffe4d4
 *   @0x168b44 .word 0xffffc0a8
 *   @0x168b48 .word 0xffffe4b4
 *   @0x168b4c .word 0xffffe4c8
 *   @0x168b50 .word 0xffffe4cc
 *   @0x168b54 .word 0xffffe4c0
 *   @0x168b58 .word 0xffffe4c4
 *   @0x168b5c .word 0xffffe4d8
 *   @0x168b60 .word 0xffffe4bc
 *
 * ══ §44/110 GR_Draw_Vertex_Texture(float, float, float, float)  0x16bb70  size 276  69 条（0x16bb70..0x16bc84）
 * @func 0x16bb70 0x16bc84  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16bb80→0x4899b0, 0x16bba0→0x4899b4, 0x16bba8→0x4859ac, 0x16bbac→0x3f23d0, 0x16bbb4→0x490000, 0x16bc00→0x48fffc, 0x16bc20→0x48fff8
 * 调用序列: GR_Draw_Vertex_Texture(float, float, float, float)+0x30
 * 字段偏移 top8: 0xc0×2 / 0xec×1 / 0xe0×1 / 0xc4×1 / 0xbc×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16bb70 ldr r12, [pc, #0xec]
 *   @0x16bb74 vmov s13, r3
 *   @0x16bb78 push {r4, r5, r6, r7, r8}
 *   @0x16bb7c add r12, pc, r12
 *   @0x16bb80 ldr r4, [pc, #0xe0]
 *   @0x16bb84 vmov s12, r2
 *   @0x16bb88 ldr r4, [r12, r4]
 *   @0x16bb8c ldr r3, [r4]
 *   @0x16bb90 cmp r3, #1000
 *   @0x16bb94 ble 0x16bba0 <_Z22GR_Draw_Vertex_Textureffff+0x30>
 *   @0x16bb98 pop {r4, r5, r6, r7, r8}
 *   @0x16bb9c bx lr
 *   @0x16bba0 ldr r5, [pc, #0xc4]
 *   @0x16bba4 add r2, r3, r3, lsl #1
 *   @0x16bba8 ldr r7, [pc, #0xc0]
 *   @0x16bbac ldr r6, [pc, #0xc0]
 *   @0x16bbb0 ldr r8, [r12, r5]
 *   @0x16bbb4 ldr r5, [pc, #0xbc]
 *   @0x16bbb8 add r2, r8, r2, lsl #3
 *   @0x16bbbc str r0, [r2]
 *   @0x16bbc0 str r1, [r2, #0x4]
 *   @0x16bbc4 ldr r1, [r12, r7]
 *   @0x16bbc8 ldr r1, [r1]
 *   @0x16bbcc str r1, [r2, #0x8]
 *   @0x16bbd0 ldr r1, [r12, r6]
 *   @0x16bbd4 ldr r1, [r1]
 *   @0x16bbd8 str r1, [r2, #0xc]
 *   @0x16bbdc ldr r1, [r12, r5]
 *   @0x16bbe0 ldr r1, [r1]
 *   @0x16bbe4 cmp r1, #0
 *   @0x16bbe8 vstreq s12, [r2, #16]
 *   @0x16bbec vstreq s13, [r2, #20]
 *   @0x16bbf0 beq 0x16bc54 <_Z22GR_Draw_Vertex_Textureffff+0xe4>
 *   @0x16bbf4 ldrsh r0, [r1]
 *   @0x16bbf8 ldrsh r5, [r1, #12]
 *   @0x16bbfc vmov s14, r0
 *   @0x16bc00 ldr r0, [pc, #0x74]
 *   @0x16bc04 vmov s10, r5
 *   @0x16bc08 ldrsh r5, [r1, #2]
 *   @0x16bc0c vcvt.f32.s32 s14, s14
 *   @0x16bc10 vmov s15, r5
 *   @0x16bc14 ldrsh r5, [r1, #14]
 *   @0x16bc18 ldr r1, [r12, r0]
 *   @0x16bc1c vldr s11, [r1]
 *   @0x16bc20 ldr r1, [pc, #0x58]
 *   @0x16bc24 vcvt.f32.s32 s10, s10
 *   @0x16bc28 vmla.f32 s14, s12, s10
 *   @0x16bc2c vdiv.f32 s14, s14, s11
 *   @0x16bc30 vmov s11, r5
 *   @0x16bc34 vcvt.f32.s32 s15, s15
 *   @0x16bc38 vstr s14, [r2, #16]
 *   @0x16bc3c ldr r1, [r12, r1]
 *   @0x16bc40 vldr s14, [r1]
 *   @0x16bc44 vcvt.f32.s32 s12, s11
 *   @0x16bc48 vmla.f32 s15, s13, s12
 *   @0x16bc4c vdiv.f32 s15, s15, s14
 *   @0x16bc50 vstr s15, [r2, #20]
 *   @0x16bc54 add r3, r3, #1
 *   @0x16bc58 str r3, [r4]
 *   @0x16bc5c pop {r4, r5, r6, r7, r8}
 *   @0x16bc60 bx lr
 *   @0x16bc64 .word 0x002860d4
 *   @0x16bc68 .word 0xffffe534
 *   @0x16bc6c .word 0xffffe54c
 *   @0x16bc70 .word 0xffffbcd0
 *   @0x16bc74 .word 0xffffc0ac
 *   @0x16bc78 .word 0xffffe540
 *   @0x16bc7c .word 0xffffe544
 *   @0x16bc80 .word 0xffffe548
 *
 * ══ §45/110 GR_Draw_Button(float, float, float, float, bool)  0x16bfc4  size 276  69 条（0x16bfc4..0x16c0d8）
 * @func 0x16bfc4 0x16c0d8  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Draw_Triangle_Ext(float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, bool)×4
 * 字段偏移 top8: 0x14×4 / 0x8×4 / 0xc×4 / 0x10×4 / 0x30×2 / 0x4×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16bfc4 push {r4, lr}
 *   @0x16bfc8 vpush {d8, d9}
 *   @0x16bfcc sub sp, sp, #24
 *   @0x16bfd0 vmov s19, r0
 *   @0x16bfd4 ldrb r4, [sp, #0x30]
 *   @0x16bfd8 vmov s18, r1
 *   @0x16bfdc str r0, [sp]
 *   @0x16bfe0 vmov s17, r2
 *   @0x16bfe4 cmp r4, #0
 *   @0x16bfe8 vmov s16, r3
 *   @0x16bfec str r3, [sp, #0x4]
 *   @0x16bff0 bne 0x16c080 <_Z14GR_Draw_Buttonffffb+0xbc>
 *   @0x16bff4 mov r3, r1
 *   @0x16bff8 str r4, [sp, #0x14]
 *   @0x16bffc movw r12, #0x8080
 *   @0x16c000 movt r12, #0x80
 *   @0x16c004 str r12, [sp, #0x8]
 *   @0x16c008 str r12, [sp, #0xc]
 *   @0x16c00c str r12, [sp, #0x10]
 *   @0x16c010 bl 0x16a85c <_Z20GR_Draw_Triangle_Extffffffjjjb>
 *   @0x16c014 mvn r3, #-16777216
 *   @0x16c018 vstr s17, [sp]
 *   @0x16c01c str r3, [sp, #0x8]
 *   @0x16c020 str r3, [sp, #0xc]
 *   @0x16c024 vstr s16, [sp, #4]
 *   @0x16c028 str r3, [sp, #0x10]
 *   @0x16c02c str r4, [sp, #0x14]
 *   @0x16c030 vmov r0, s19
 *   @0x16c034 vmov r1, s16
 *   @0x16c038 vmov r2, s17
 *   @0x16c03c vmov r3, s18
 *   @0x16c040 bl 0x16a85c <_Z20GR_Draw_Triangle_Extffffffjjjb>
 *   @0x16c044 vmov.f32 s15, #2.000000e+00
 *   @0x16c048 mov r3, #0
 *   @0x16c04c str r3, [sp, #0x30]
 *   @0x16c050 vadd.f32 s19, s19, s15
 *   @0x16c054 vadd.f32 s18, s18, s15
 *   @0x16c058 vmov r0, s19
 *   @0x16c05c vsub.f32 s17, s17, s15
 *   @0x16c060 vmov r1, s18
 *   @0x16c064 vsub.f32 s15, s16, s15
 *   @0x16c068 vmov r2, s17
 *   @0x16c06c vmov r3, s15
 *   @0x16c070 add sp, sp, #24
 *   @0x16c074 vpop {d8, d9}
 *   @0x16c078 pop {r4, lr}
 *   @0x16c07c b 0x16aa1c <_Z20YYGML_draw_rectangleffffb>
 *   @0x16c080 mvn r3, #-16777216
 *   @0x16c084 mov r4, #0
 *   @0x16c088 str r3, [sp, #0x8]
 *   @0x16c08c str r3, [sp, #0xc]
 *   @0x16c090 str r3, [sp, #0x10]
 *   @0x16c094 mov r3, r1
 *   @0x16c098 str r4, [sp, #0x14]
 *   @0x16c09c bl 0x16a85c <_Z20GR_Draw_Triangle_Extffffffjjjb>
 *   @0x16c0a0 str r4, [sp, #0x14]
 *   @0x16c0a4 vstr s17, [sp]
 *   @0x16c0a8 vstr s16, [sp, #4]
 *   @0x16c0ac movw r3, #0x8080
 *   @0x16c0b0 vmov r0, s19
 *   @0x16c0b4 movt r3, #0x80
 *   @0x16c0b8 vmov r1, s16
 *   @0x16c0bc str r3, [sp, #0x8]
 *   @0x16c0c0 str r3, [sp, #0xc]
 *   @0x16c0c4 str r3, [sp, #0x10]
 *   @0x16c0c8 vmov r2, s17
 *   @0x16c0cc vmov r3, s18
 *   @0x16c0d0 bl 0x16a85c <_Z20GR_Draw_Triangle_Extffffffjjjb>
 *   @0x16c0d4 b 0x16c044 <_Z14GR_Draw_Buttonffffb+0x80>
 *
 * ══ §46/110 Shader_Set_Uniform_I(int, int, double, double, double, double)  0x188680  size 276  69 条（0x188680..0x188794）
 * @func 0x188680 0x188794  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Set_Uniform_I(int, int, double, double, double, double)+0x28 / Shader_Get(int) / Shader_Set_Uniform_I(int, int, double, double, double, double)+0xec / Shader_Set_Uniform_I(int, int, int, int*)
 * 字段偏移 top8: 0x4×3 / 0x104×1 / 0xc8×1 / 0x64×1 / 0x7c×1 / 0x78×1 / 0xc×1 / 0x14×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188680 ldr r12, [pc, #0x104]
 *   @0x188684 push {r4, lr}
 *   @0x188688 vpush {d8}
 *   @0x18868c ldr r12, [pc, r12]
 *   @0x188690 vmov d8, r2, r3
 *   @0x188694 sub sp, sp, #24
 *   @0x188698 ldr r3, [r12]
 *   @0x18869c mov r4, r0
 *   @0x1886a0 cmp r3, #1
 *   @0x1886a4 beq 0x1886b8 <_Z20Shader_Set_Uniform_Iiidddd+0x38>
 *   @0x1886a8 mov r0, #0
 *   @0x1886ac add sp, sp, #24
 *   @0x1886b0 vpop {d8}
 *   @0x1886b4 pop {r4, pc}
 *   @0x1886b8 cmp r0, #0
 *   @0x1886bc blt 0x1886a8 <_Z20Shader_Set_Uniform_Iiidddd+0x28>
 *   @0x1886c0 ldr r3, [pc, #0xc8]
 *   @0x1886c4 ldr r3, [pc, r3]
 *   @0x1886c8 ldr r3, [r3]
 *   @0x1886cc cmp r3, #0
 *   @0x1886d0 beq 0x1886a8 <_Z20Shader_Set_Uniform_Iiidddd+0x28>
 *   @0x1886d4 ldr r0, [r3, #0x64]
 *   @0x1886d8 str r1, [sp, #0x4]
 *   @0x1886dc bl 0x187e70 <_Z10Shader_Geti>
 *   @0x1886e0 ldr r1, [sp, #0x4]
 *   @0x1886e4 cmp r0, #0
 *   @0x1886e8 beq 0x1886a8 <_Z20Shader_Set_Uniform_Iiidddd+0x28>
 *   @0x1886ec ldr r3, [r0, #0x7c]
 *   @0x1886f0 cmp r4, r3
 *   @0x1886f4 bge 0x1886a8 <_Z20Shader_Set_Uniform_Iiidddd+0x28>
 *   @0x1886f8 ldr r3, [r0, #0x78]
 *   @0x1886fc rsb r4, r4, r4, lsl #3
 *   @0x188700 adds r4, r3, r4, lsl #2
 *   @0x188704 beq 0x1886a8 <_Z20Shader_Set_Uniform_Iiidddd+0x28>
 *   @0x188708 vcvt.s32.f64 s16, d8
 *   @0x18870c ldr r2, [r4, #0xc]
 *   @0x188710 mov r3, #0
 *   @0x188714 str r3, [sp, #0x14]
 *   @0x188718 cmp r1, r2
 *   @0x18871c movge r1, r2
 *   @0x188720 str r3, [sp, #0x10]
 *   @0x188724 cmp r1, #1
 *   @0x188728 strle r3, [sp, #0xc]
 *   @0x18872c vstr s16, [sp, #8]
 *   @0x188730 ble 0x18876c <_Z20Shader_Set_Uniform_Iiidddd+0xec>
 *   @0x188734 vldr d7, [sp, #40]
 *   @0x188738 vcvt.s32.f64 s15, d7
 *   @0x18873c cmp r1, #2
 *   @0x188740 vstr s15, [sp, #12]
 *   @0x188744 beq 0x18876c <_Z20Shader_Set_Uniform_Iiidddd+0xec>
 *   @0x188748 vldr d7, [sp, #48]
 *   @0x18874c vcvt.s32.f64 s15, d7
 *   @0x188750 cmp r1, #3
 *   @0x188754 vmov r3, s15
 *   @0x188758 vstr s15, [sp, #16]
 *   @0x18875c vldrne d7, [sp, #56]
 *   @0x188760 vcvtne.s32.f64 s15, d7
 *   @0x188764 vmovne r3, s15
 *   @0x188768 strne r3, [sp, #0x14]
 *   @0x18876c ldr r0, [r4, #0x4]
 *   @0x188770 mov r2, #1
 *   @0x188774 add r3, sp, #8
 *   @0x188778 bl 0x188200 <_Z20Shader_Set_Uniform_IiiiPi>
 *   @0x18877c mov r0, #1
 *   @0x188780 add sp, sp, #24
 *   @0x188784 vpop {d8}
 *   @0x188788 pop {r4, pc}
 *   @0x18878c eoreq r7, r6, r12, ror sp
 *   @0x188790 .word 0x00267db4
 *
 * ══ §47/110 F_LayerElementMove(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c0028  size 276  69 条（0x1c0028..0x1c013c）
 * @func 0x1c0028 0x1c013c  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Error_Show(char const*, bool) / CLayerManager::GetTargetRoomObj() / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::MoveElement(CRoom*, CLayerElementBase*, CLayer*)
 * 字段偏移 top8: 0x20×3 / 0xc×2 / 0x48×2 / 0xec×1 / 0x4×1 / 0xc8×1 / 0x-4×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c0028 push {r4, r5, r6, r7, lr}
 *   @0x1c002c cmp r3, #2
 *   @0x1c0030 ldr r5, [pc, #0xec]
 *   @0x1c0034 mov r3, #0
 *   @0x1c0038 mov r4, r3
 *   @0x1c003c sub sp, sp, #12
 *   @0x1c0040 movt r3, #0xbff0
 *   @0x1c0044 str r4, [r0, #0xc]
 *   @0x1c0048 str r3, [r0, #0x4]
 *   @0x1c004c add r5, pc, r5
 *   @0x1c0050 str r4, [r0]
 *   @0x1c0054 beq 0x1c0070 <_Z18F_LayerElementMoveR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1c0058 ldr r0, [pc, #0xc8]
 *   @0x1c005c mov r1, r4
 *   @0x1c0060 add r0, pc, r0
 *   @0x1c0064 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c0068 add sp, sp, #12
 *   @0x1c006c pop {r4, r5, r6, r7, pc}
 *   @0x1c0070 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c0074 subs r7, r0, #0
 *   @0x1c0078 beq 0x1c0104 <_Z18F_LayerElementMoveR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x1c007c add r6, sp, #8
 *   @0x1c0080 mov r1, r4
 *   @0x1c0084 ldr r0, [sp, #0x20]
 *   @0x1c0088 str r4, [r6, #-0x4]!
 *   @0x1c008c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0090 mov r2, r6
 *   @0x1c0094 mov r1, r0
 *   @0x1c0098 mov r0, r7
 *   @0x1c009c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1c00a0 subs r4, r0, #0
 *   @0x1c00a4 beq 0x1c0114 <_Z18F_LayerElementMoveR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x1c00a8 mov r1, #1
 *   @0x1c00ac ldr r0, [sp, #0x20]
 *   @0x1c00b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c00b4 mov r1, r0
 *   @0x1c00b8 mov r0, r7
 *   @0x1c00bc bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c00c0 subs r2, r0, #0
 *   @0x1c00c4 beq 0x1c00dc <_Z18F_LayerElementMoveR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x1c00c8 mov r0, r7
 *   @0x1c00cc mov r1, r4
 *   @0x1c00d0 bl 0x1bc1b4 <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer>
 *   @0x1c00d4 add sp, sp, #12
 *   @0x1c00d8 pop {r4, r5, r6, r7, pc}
 *   @0x1c00dc ldr r1, [pc, #0x48]
 *   @0x1c00e0 ldr r3, [pc, #0x48]
 *   @0x1c00e4 add r1, pc, r1
 *   @0x1c00e8 ldr r3, [r5, r3]
 *   @0x1c00ec ldr r0, [r3]
 *   @0x1c00f0 ldr r3, [r0]
 *   @0x1c00f4 ldr r3, [r3, #0xc]
 *   @0x1c00f8 blx r3
 *   @0x1c00fc add sp, sp, #12
 *   @0x1c0100 pop {r4, r5, r6, r7, pc}
 *   @0x1c0104 ldr r1, [pc, #0x28]
 *   @0x1c0108 ldr r3, [pc, #0x20]
 *   @0x1c010c add r1, pc, r1
 *   @0x1c0110 b 0x1c00e8 <_Z18F_LayerElementMoveR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1c0114 ldr r1, [pc, #0x1c]
 *   @0x1c0118 ldr r3, [pc, #0x10]
 *   @0x1c011c add r1, pc, r1
 *   @0x1c0120 b 0x1c00e8 <_Z18F_LayerElementMoveR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1c0124 eoreq r1, r3, r4, lsl #24
 *   @0x1c0128 andseq pc, r8, r12, lsr #12
 *   @0x1c012c ldrsbeq pc, [r8], -r4
 *   @0x1c0130 .word 0xffffbac4
 *   @0x1c0134 andseq pc, r8, r4, lsl r6
 *   @0x1c0138 andseq pc, r8, r12, asr #11
 *
 * ══ §48/110 FINALIZE_Run_Main()  0x1d37cc  size 276  69 条（0x1d37cc..0x1d38e0）
 * @func 0x1d37cc 0x1d38e0  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / FINALIZE_Run_Main()+0xd8
 * 字段偏移 top8: 0x4×7 / 0xfc×2 / 0xcc×1 / 0x44×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d37cc push {r4, r5, r6, r7, r8, lr}
 *   @0x1d37d0 ldr r6, [pc, #0xfc]
 *   @0x1d37d4 ldr r7, [pc, #0xfc]
 *   @0x1d37d8 ldr r6, [pc, r6]
 *   @0x1d37dc ldr r7, [pc, r7]
 *   @0x1d37e0 ldr r2, [r6]
 *   @0x1d37e4 cmp r2, #0
 *   @0x1d37e8 str r2, [r7]
 *   @0x1d37ec movgt r4, #0
 *   @0x1d37f0 movgt r5, r4
 *   @0x1d37f4 movgt r8, r4
 *   @0x1d37f8 bgt 0x1d3804 <_Z17FINALIZE_Run_Mainv+0x38>
 *   @0x1d37fc b 0x1d3870 <_Z17FINALIZE_Run_Mainv+0xa4>
 *   @0x1d3800 ldr r2, [r6]
 *   @0x1d3804 cmp r5, r2
 *   @0x1d3808 ldr r3, [pc, #0xcc]
 *   @0x1d380c bge 0x1d3850 <_Z17FINALIZE_Run_Mainv+0x84>
 *   @0x1d3810 ldr r1, [r6, #0x4]
 *   @0x1d3814 add r2, r1, r4
 *   @0x1d3818 ldr r1, [r1, r4]
 *   @0x1d381c cmp r1, #0
 *   @0x1d3820 mov r0, r1
 *   @0x1d3824 beq 0x1d3858 <_Z17FINALIZE_Run_Mainv+0x8c>
 *   @0x1d3828 ldr r3, [pc, r3]
 *   @0x1d382c ldrb r3, [r3]
 *   @0x1d3830 cmp r3, #0
 *   @0x1d3834 beq 0x1d3844 <_Z17FINALIZE_Run_Mainv+0x78>
 *   @0x1d3838 ldr r3, [r1, #0x44]
 *   @0x1d383c cmn r3, #1
 *   @0x1d3840 beq 0x1d3858 <_Z17FINALIZE_Run_Mainv+0x8c>
 *   @0x1d3844 ldr r3, [r1]
 *   @0x1d3848 ldr r3, [r3, #0x4]
 *   @0x1d384c blx r3
 *   @0x1d3850 ldr r2, [r6, #0x4]
 *   @0x1d3854 add r2, r2, r4
 *   @0x1d3858 ldr r3, [r7]
 *   @0x1d385c add r5, r5, #1
 *   @0x1d3860 add r4, r4, #4
 *   @0x1d3864 str r8, [r2]
 *   @0x1d3868 cmp r3, r5
 *   @0x1d386c bgt 0x1d3800 <_Z17FINALIZE_Run_Mainv+0x34>
 *   @0x1d3870 ldr r4, [r6, #0x4]
 *   @0x1d3874 cmp r4, #0
 *   @0x1d3878 beq 0x1d38c4 <_Z17FINALIZE_Run_Mainv+0xf8>
 *   @0x1d387c ldr r2, [r6]
 *   @0x1d3880 cmp r2, #0
 *   @0x1d3884 ble 0x1d38a4 <_Z17FINALIZE_Run_Mainv+0xd8>
 *   @0x1d3888 mov r3, #0
 *   @0x1d388c mov r1, r3
 *   @0x1d3890 str r1, [r4, r3, lsl #2]
 *   @0x1d3894 add r3, r3, #1
 *   @0x1d3898 cmp r3, r2
 *   @0x1d389c ldr r4, [r6, #0x4]
 *   @0x1d38a0 bne 0x1d3890 <_Z17FINALIZE_Run_Mainv+0xc4>
 *   @0x1d38a4 mov r0, r4
 *   @0x1d38a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d38ac mov r3, #0
 *   @0x1d38b0 str r3, [r6, #0x4]
 *   @0x1d38b4 mov r3, #0
 *   @0x1d38b8 str r3, [r6]
 *   @0x1d38bc str r3, [r7]
 *   @0x1d38c0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1d38c4 mov r0, r4
 *   @0x1d38c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d38cc str r4, [r6, #0x4]
 *   @0x1d38d0 b 0x1d38b4 <_Z17FINALIZE_Run_Mainv+0xe8>
 *   @0x1d38d4 eoreq sp, r1, r0, ror r3
 *   @0x1d38d8 eoreq sp, r1, r8, ror #6
 *   @0x1d38dc mlaeq r1, r0, r3, r10
 *
 * ══ §49/110 CDS_Map::FindPrevious(RValue*)  0x203a80  size 276  69 条（0x203a80..0x203b94）
 * @func 0x203a80 0x203b94  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCompareVal(RValue const&, RValue const&, double) / CDS_Map::FindPrevious(RValue*)+0xc0
 * 字段偏移 top8: 0x4×4 / 0xc×3 / 0x8×2 / 0x3×1 / 0xb0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203a80 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x203a84 mov r8, r1
 *   @0x203a88 ldr r9, [r0]
 *   @0x203a8c sub sp, sp, #16
 *   @0x203a90 mov r5, #0
 *   @0x203a94 ldr r2, [r9]
 *   @0x203a98 b 0x203aac <_ZN7CDS_Map12FindPreviousEP6RValue+0x2c>
 *   @0x203a9c ldr r3, [r9, #0x4]
 *   @0x203aa0 add r5, r5, #1
 *   @0x203aa4 cmp r5, r3
 *   @0x203aa8 bgt 0x203b74 <_ZN7CDS_Map12FindPreviousEP6RValue+0xf4>
 *   @0x203aac ldr r4, [r2, r5, lsl #3]
 *   @0x203ab0 cmp r4, #0
 *   @0x203ab4 beq 0x203a9c <_ZN7CDS_Map12FindPreviousEP6RValue+0x1c>
 *   @0x203ab8 mov r10, #0
 *   @0x203abc b 0x203ac4 <_ZN7CDS_Map12FindPreviousEP6RValue+0x44>
 *   @0x203ac0 mov r10, r6
 *   @0x203ac4 cmp r4, #0
 *   @0x203ac8 beq 0x203b68 <_ZN7CDS_Map12FindPreviousEP6RValue+0xe8>
 *   @0x203acc ldr r6, [r4, #0xc]
 *   @0x203ad0 cmp r6, #0
 *   @0x203ad4 beq 0x203b88 <_ZN7CDS_Map12FindPreviousEP6RValue+0x108>
 *   @0x203ad8 ldr lr, [pc, #0xb0]
 *   @0x203adc mov r12, sp
 *   @0x203ae0 ldr r3, [r6, #0xc]
 *   @0x203ae4 ldr r0, [r6]
 *   @0x203ae8 ldr lr, [pc, lr]
 *   @0x203aec ldr r1, [r6, #0x4]
 *   @0x203af0 ldr r2, [r6, #0x8]
 *   @0x203af4 stm r12!, {r0, r1, r2, r3}
 *   @0x203af8 mov r12, r3
 *   @0x203afc mov r0, r8
 *   @0x203b00 mov r1, sp
 *   @0x203b04 ldrd r2, r3, [lr]
 *   @0x203b08 bic r12, r12, #-16777216
 *   @0x203b0c str r12, [sp, #0xc]
 *   @0x203b10 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x203b14 cmp r0, #0
 *   @0x203b18 beq 0x203b7c <_ZN7CDS_Map12FindPreviousEP6RValue+0xfc>
 *   @0x203b1c ldr r4, [r4, #0x4]
 *   @0x203b20 cmp r4, #0
 *   @0x203b24 bne 0x203ac0 <_ZN7CDS_Map12FindPreviousEP6RValue+0x40>
 *   @0x203b28 ldr r1, [r9, #0x4]
 *   @0x203b2c add r2, r5, #1
 *   @0x203b30 cmp r2, r1
 *   @0x203b34 bgt 0x203b60 <_ZN7CDS_Map12FindPreviousEP6RValue+0xe0>
 *   @0x203b38 ldr r3, [r9]
 *   @0x203b3c add r3, r3, r5, lsl #3
 *   @0x203b40 ldr r4, [r3, #0x8]
 *   @0x203b44 mov r5, r2
 *   @0x203b48 add r3, r3, #8
 *   @0x203b4c add r2, r2, #1
 *   @0x203b50 cmp r4, #0
 *   @0x203b54 bne 0x203ac0 <_ZN7CDS_Map12FindPreviousEP6RValue+0x40>
 *   @0x203b58 cmp r2, r1
 *   @0x203b5c ble 0x203b40 <_ZN7CDS_Map12FindPreviousEP6RValue+0xc0>
 *   @0x203b60 mvn r5, #0
 *   @0x203b64 b 0x203ac0 <_ZN7CDS_Map12FindPreviousEP6RValue+0x40>
 *   @0x203b68 mov r0, r4
 *   @0x203b6c add sp, sp, #16
 *   @0x203b70 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x203b74 mvn r5, #0
 *   @0x203b78 b 0x203ab8 <_ZN7CDS_Map12FindPreviousEP6RValue+0x38>
 *   @0x203b7c mov r0, r10
 *   @0x203b80 add sp, sp, #16
 *   @0x203b84 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x203b88 mov r0, r6
 *   @0x203b8c b 0x203b6c <_ZN7CDS_Map12FindPreviousEP6RValue+0xec>
 *   @0x203b90 mulseq lr, r12, r8
 *
 * ══ §50/110 Audio_WAVs(unsigned char*, unsigned int, unsigned char*, int)  0x219680  size 276  69 条（0x219680..0x219794）
 * @func 0x219680 0x219794  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_WAVs(unsigned char*, unsigned int, unsigned char*, int)+0x9c / Audio_WAVs(unsigned char*, unsigned int, unsigned char*, int)+0xa4
 * 字段偏移 top8: 0x4×5 / 0x4c×4 / 0xc×3 / 0x14×2 / 0x2×2 / 0xfc×1 / 0xe4×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x219680 ldr r12, [pc, #0xfc]
 *   @0x219684 push {r3, r4, r5, r6, r7, lr}
 *   @0x219688 ldr r12, [pc, r12]
 *   @0x21968c mov r4, r0
 *   @0x219690 mov r7, r2
 *   @0x219694 ldr r0, [r12]
 *   @0x219698 mov r6, r3
 *   @0x21969c ldr r1, [pc, #0xe4]
 *   @0x2196a0 ldr r2, [r0]
 *   @0x2196a4 add r1, pc, r1
 *   @0x2196a8 ldr r3, [r2, #0xc]
 *   @0x2196ac blx r3
 *   @0x2196b0 ldr r2, [pc, #0xd4]
 *   @0x2196b4 add r0, r4, #4
 *   @0x2196b8 add r2, pc, r2
 *   @0x2196bc ldr r5, [r2, #0x20]
 *   @0x2196c0 cmp r5, #0
 *   @0x2196c4 ble 0x21971c <_Z10Audio_WAVsPhjS_i+0x9c>
 *   @0x2196c8 ldr r3, [pc, #0xc0]
 *   @0x2196cc ldr r1, [r2, #0x24]
 *   @0x2196d0 ldr r3, [pc, r3]
 *   @0x2196d4 ldr r3, [r3, #0x4]
 *   @0x2196d8 cmp r3, #0
 *   @0x2196dc ble 0x219724 <_Z10Audio_WAVsPhjS_i+0xa4>
 *   @0x2196e0 add r5, r1, r5, lsl #2
 *   @0x2196e4 ldr r12, [r1], #4
 *   @0x2196e8 cmp r12, #0
 *   @0x2196ec beq 0x219714 <_Z10Audio_WAVsPhjS_i+0x94>
 *   @0x2196f0 ldr r4, [r12, #0x4c]
 *   @0x2196f4 cmp r6, r4
 *   @0x2196f8 bne 0x219714 <_Z10Audio_WAVsPhjS_i+0x94>
 *   @0x2196fc ldr r3, [r12, #0x14]
 *   @0x219700 ldr r4, [r0, r3, lsl #2]
 *   @0x219704 cmp r4, #0
 *   @0x219708 add r3, r7, r4
 *   @0x21970c moveq r3, r4
 *   @0x219710 str r3, [r12, #0xc]
 *   @0x219714 cmp r1, r5
 *   @0x219718 bne 0x2196e4 <_Z10Audio_WAVsPhjS_i+0x64>
 *   @0x21971c mov r0, #1
 *   @0x219720 pop {r3, r4, r5, r6, r7, pc}
 *   @0x219724 cmp r6, #0
 *   @0x219728 mov r2, #0
 *   @0x21972c add r5, r1, r5, lsl #2
 *   @0x219730 beq 0x219758 <_Z10Audio_WAVsPhjS_i+0xd8>
 *   @0x219734 ldr r3, [r1], #4
 *   @0x219738 cmp r1, r5
 *   @0x21973c str r2, [r3, #0x4c]
 *   @0x219740 beq 0x21971c <_Z10Audio_WAVsPhjS_i+0x9c>
 *   @0x219744 ldr r3, [r1], #4
 *   @0x219748 cmp r1, r5
 *   @0x21974c str r2, [r3, #0x4c]
 *   @0x219750 bne 0x219734 <_Z10Audio_WAVsPhjS_i+0xb4>
 *   @0x219754 b 0x21971c <_Z10Audio_WAVsPhjS_i+0x9c>
 *   @0x219758 ldr r3, [r1], #4
 *   @0x21975c ldr r12, [r3, #0x14]
 *   @0x219760 str r2, [r3, #0x4c]
 *   @0x219764 ldr r12, [r0, r12, lsl #2]
 *   @0x219768 cmp r12, #0
 *   @0x21976c mov r4, r12
 *   @0x219770 addne r4, r7, r12
 *   @0x219774 cmp r1, r5
 *   @0x219778 str r4, [r3, #0xc]
 *   @0x21977c bne 0x219758 <_Z10Audio_WAVsPhjS_i+0xd8>
 *   @0x219780 b 0x21971c <_Z10Audio_WAVsPhjS_i+0x9c>
 *   @0x219784 mulseq sp, r4, r4
 *   @0x219788 andseq r10, r3, r8, lsr #14
 *   @0x21978c ldrsbeq r11, [r3], #-188
 *   @0x219790 andseq r5, sp, r0, lsl #19
 *
 * ══ §51/110 DrawTimingEvents(COggSyncThread*)  0x224cdc  size 276  69 条（0x224cdc..0x224df0）
 * @func 0x224cdc 0x224df0  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Get_Width()×2 / anon_319414×2 / __floatdisf×2 / COggSyncThread::Lock() / Timing_Time / GR_Window_Get_Height() / GraphicsPerf::RenderRectangle(float, float, float, float, unsigned int)
 * 字段偏移 top8: 0xcc×2 / 0x18×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224cdc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x224ce0 vpush {d8, d9}
 *   @0x224ce4 sub sp, sp, #12
 *   @0x224ce8 mov r6, r0
 *   @0x224cec bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x224cf0 bl 0x215148 <Timing_Time>
 *   @0x224cf4 mov r9, r1
 *   @0x224cf8 mov r8, r0
 *   @0x224cfc bl 0x17af50 <_Z19GR_Window_Get_Widthv>
 *   @0x224d00 vldr s15, [pc, #220]
 *   @0x224d04 vmov s14, r0
 *   @0x224d08 vcvt.f32.s32 s16, s14
 *   @0x224d0c vdiv.f32 s16, s16, s15
 *   @0x224d10 bl 0x17af64 <_Z20GR_Window_Get_Heightv>
 *   @0x224d14 ldr r3, [pc, #0xcc]
 *   @0x224d18 ldr r2, [pc, #0xcc]
 *   @0x224d1c ldr r3, [pc, r3]
 *   @0x224d20 ldr r2, [pc, r2]
 *   @0x224d24 ldr r7, [r3]
 *   @0x224d28 ldr r11, [r2]
 *   @0x224d2c cmp r7, #0
 *   @0x224d30 sub r0, r0, #50
 *   @0x224d34 vmov s15, r0
 *   @0x224d38 vcvt.f32.s32 s15, s15
 *   @0x224d3c vmov r10, s15
 *   @0x224d40 beq 0x224dd0 <_Z16DrawTimingEventsP14COggSyncThread+0xf4>
 *   @0x224d44 ldrd r4, r5, [r7, #8]
 *   @0x224d48 mov r2, #2000
 *   @0x224d4c mov r3, #0
 *   @0x224d50 mov r0, r8
 *   @0x224d54 mov r1, r9
 *   @0x224d58 subs r0, r0, r4
 *   @0x224d5c sbc r1, r1, r5
 *   @0x224d60 bl 0x319414 <__aeabi_ldivmod>
 *   @0x224d64 bl 0x319398 <__floatdisf>
 *   @0x224d68 mov r2, #2000
 *   @0x224d6c mov r3, #0
 *   @0x224d70 vmov s14, r0
 *   @0x224d74 ldrd r0, r1, [r7, #16]
 *   @0x224d78 subs r0, r0, r4
 *   @0x224d7c sbc r1, r1, r5
 *   @0x224d80 vmul.f32 s17, s14, s16
 *   @0x224d84 bl 0x319414 <__aeabi_ldivmod>
 *   @0x224d88 bl 0x319398 <__floatdisf>
 *   @0x224d8c vmov s15, r0
 *   @0x224d90 vmul.f32 s18, s15, s16
 *   @0x224d94 bl 0x17af50 <_Z19GR_Window_Get_Widthv>
 *   @0x224d98 ldr r2, [r7]
 *   @0x224d9c mov r1, r10
 *   @0x224da0 mov r3, r11
 *   @0x224da4 str r2, [sp]
 *   @0x224da8 vmov r2, s18
 *   @0x224dac sub r0, r0, #10
 *   @0x224db0 vmov s14, r0
 *   @0x224db4 vcvt.f32.s32 s15, s14
 *   @0x224db8 vsub.f32 s15, s15, s17
 *   @0x224dbc vmov r0, s15
 *   @0x224dc0 bl 0x17b83c <_ZN12GraphicsPerf15RenderRectangleEffffj>
 *   @0x224dc4 ldr r7, [r7, #0x18]
 *   @0x224dc8 cmp r7, #0
 *   @0x224dcc bne 0x224d44 <_Z16DrawTimingEventsP14COggSyncThread+0x68>
 *   @0x224dd0 mov r0, r6
 *   @0x224dd4 add sp, sp, #12
 *   @0x224dd8 vpop {d8, d9}
 *   @0x224ddc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x224de0 b 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x224de4 ldrbtmi r0, [r10], #-0
 *   @0x224de8 andseq r12, r12, r0, ror #14
 *   @0x224dec andseq r11, r12, r4, lsl r6
 *
 * ══ §52/110 CPhysicsWorld::CreateRevoluteJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, bool, float, float, bool, bool)  0x239050  size 276  69 条（0x239050..0x239164）
 * @func 0x239050 0x239164  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2RevoluteJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&) / CPhysicsJointFactory::CreateJoint(CPhysicsWorld*, b2JointDef const&)
 * 字段偏移 top8: 0x4×2 / 0x18×2 / 0x30×2 / 0x3c×2 / 0x8×2 / 0x38×2 / 0x44×2 / 0x40×2
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239050 vmov s14, r3
 *   @0x239054 ldr r1, [r1]
 *   @0x239058 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x23905c vpush {d8}
 *   @0x239060 mov r4, r0
 *   @0x239064 vldr s15, [r4, #96]
 *   @0x239068 sub sp, sp, #76
 *   @0x23906c vmul.f32 s14, s15, s14
 *   @0x239070 vldr s13, [sp, #120]
 *   @0x239074 ldrh r3, [r1, #4]
 *   @0x239078 ldr r2, [r2]
 *   @0x23907c add r5, sp, #8
 *   @0x239080 tst r3, #2
 *   @0x239084 ldr r11, [sp, #0x80]
 *   @0x239088 orreq r3, r3, #2
 *   @0x23908c strheq r3, [r1, #4]
 *   @0x239090 ldrh r3, [r2, #4]
 *   @0x239094 moveq r0, #0
 *   @0x239098 streq r0, [r1, #0xa0]
 *   @0x23909c mov r12, #0
 *   @0x2390a0 tst r3, #2
 *   @0x2390a4 ldrb r8, [sp, #0x84]
 *   @0x2390a8 ldr r10, [sp, #0x88]
 *   @0x2390ac orreq r3, r3, #2
 *   @0x2390b0 ldr r9, [sp, #0x8c]
 *   @0x2390b4 moveq r0, #0
 *   @0x2390b8 ldrb r7, [sp, #0x90]
 *   @0x2390bc vldr s16, [sp, #124]
 *   @0x2390c0 ldrb r6, [sp, #0x94]
 *   @0x2390c4 vmul.f32 s15, s15, s13
 *   @0x2390c8 strheq r3, [r2, #4]
 *   @0x2390cc streq r0, [r2, #0xa0]
 *   @0x2390d0 mov r3, sp
 *   @0x2390d4 mov r0, r5
 *   @0x2390d8 vstr s14, [sp]
 *   @0x2390dc str r12, [sp, #0xc]
 *   @0x2390e0 str r12, [sp, #0x10]
 *   @0x2390e4 str r12, [sp, #0x14]
 *   @0x2390e8 strb r12, [sp, #0x18]
 *   @0x2390ec strb r12, [sp, #0x30]
 *   @0x2390f0 strb r12, [sp, #0x3c]
 *   @0x2390f4 mov r12, #1
 *   @0x2390f8 str r12, [sp, #0x8]
 *   @0x2390fc mov r12, #0
 *   @0x239100 str r12, [sp, #0x1c]
 *   @0x239104 str r12, [sp, #0x20]
 *   @0x239108 str r12, [sp, #0x24]
 *   @0x23910c str r12, [sp, #0x28]
 *   @0x239110 str r12, [sp, #0x2c]
 *   @0x239114 str r12, [sp, #0x34]
 *   @0x239118 str r12, [sp, #0x38]
 *   @0x23911c vstr s15, [sp, #4]
 *   @0x239120 str r12, [sp, #0x44]
 *   @0x239124 str r12, [sp, #0x40]
 *   @0x239128 bl 0x2d1fd8 <_ZN18b2RevoluteJointDef10InitializeEP6b2BodyS1_RK6b2Vec2>
 *   @0x23912c mov r1, r5
 *   @0x239130 mov r0, r4
 *   @0x239134 vstr s16, [sp, #52]
 *   @0x239138 str r11, [sp, #0x38]
 *   @0x23913c strb r8, [sp, #0x30]
 *   @0x239140 str r10, [sp, #0x44]
 *   @0x239144 str r9, [sp, #0x40]
 *   @0x239148 strb r7, [sp, #0x3c]
 *   @0x23914c strb r6, [sp, #0x18]
 *   @0x239150 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef>
 *   @0x239154 ldr r0, [r0, #0x8]
 *   @0x239158 add sp, sp, #76
 *   @0x23915c vpop {d8}
 *   @0x239160 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §53/110 zip_source_zip  0x2a555c  size 276  69 条（0x2a555c..0x2a5670）
 * @func 0x2a555c 0x2a5670  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _zip_error_copy(zip_error*, zip_error*)×3 / zip_source_zip+0x2a×2 / 0x329184 / zip_source_zip+0x38 / 0xb6544 / _zip_error_set(zip_error*, int, int) / zip_stat_index / 0xb655c
 * 字段偏移 top8: 0x38×1 / 0x2c×1 / 0x24×1 / 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a555c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a5560 sub sp, #0x14
 *   @0x2a5564 mov r9, r2
 *   @0x2a5568 mov r6, r0
 *   @0x2a556c beq 0x2a5648 <zip_source_zip+0xec>
 *   @0x2a5570 ldr r2, [sp, #0x38]
 *   @0x2a5574 blt 0x2a5586 <zip_source_zip+0x2a>
 *   @0x2a5578 blt 0x2a5586 <zip_source_zip+0x2a>
 *   @0x2a557c blle 0x329184
 *   @0x2a5580 ldr r2, [r1, #0x2c]
 *   @0x2a5584 blt 0x2a5594 <zip_source_zip+0x38>
 *   @0x2a5588 tsths r2, r12
 *   @0x2a558c movs r2, #0x0
 *   @0x2a5590 rsb pc, r7, r3, ror #29
 *   @0x2a5594 ands r4, r3, #0x8
 *   @0x2a5598 bne 0x2a55b2 <zip_source_zip+0x56>
 *   @0x2a559c movs r1, #0x14
 *   @0x2a55a0 ldmdapl r2, {r0, r3, r8, r12, sp, lr, pc} ^
 *   @0x2a55a4 subs r2, #0x2
 *   @0x2a55a8 bhi 0x2a55b2 <zip_source_zip+0x56>
 *   @0x2a55ac mrshs r0, apsr
 *   @0x2a55b0 b 0x2a55e6 <zip_source_zip+0x8a>
 *   @0x2a55b4 cbz r5, 0x2a55ca <zip_source_zip+0x6e>
 *   @0x2a55b8 adds r1, r5, #0x1
 *   @0x2a55bc lsls r2, r3, #0x1b
 *   @0x2a55c0 orr r8, r3, #0x4
 *   @0x2a55c4 mov.w r5, #0xffffffff
 *   @0x2a55c8 b 0x2a55d6 <zip_source_zip+0x7a>
 *   @0x2a55cc beq 0x2a55bc <zip_source_zip+0x60>
 *   @0x2a55d0 .word 0xf02335ff
 *   @0x2a55d4 eorhs r0, r8, r4, lsl #16
 *   @0x2a55d8 blx 0xb6544 <malloc@plt>
 *   @0x2a55dc mov r4, r0
 *   @0x2a55e0 add.w r0, r6, #0xc
 *   @0x2a55e4 movs r1, #0xe
 *   @0x2a55e8 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a55ec mov r0, r4
 *   @0x2a55f0 add.w r10, r7, #0xc
 *   @0x2a55f4 add.w r11, sp, #0x4
 *   @0x2a55f8 mov r1, r10
 *   @0x2a55fc bl 0x2a4314 <_Z15_zip_error_copyP9zip_errorS0_>
 *   @0x2a5600 mov r0, r7
 *   @0x2a5604 mov r2, r8
 *   @0x2a5608 bl 0x2a5694 <zip_stat_index>
 *   @0x2a560c cmp r0, #0x0
 *   @0x2a5610 mov r0, r7
 *   @0x2a5614 mov r2, r8
 *   @0x2a5618 .word 0x6020ffb5
 *   @0x2a561c cbz r0, 0x2a564c <zip_source_zip+0xf0>
 *   @0x2a5620 str r5, [r4, #0x24]
 *   @0x2a5624 ands r3, r8, #0x4
 *   @0x2a5628 bne 0x2a5632 <zip_source_zip+0xd6>
 *   @0x2a562c str r5, [r4, #0x14]
 *   @0x2a5630 str r3, [r4, #0xc]
 *   @0x2a5634 mov r0, r6
 *   @0x2a5638 add r1, pc
 *   @0x2a563c strmi pc, [r6], -r6, asr #19
 *   @0x2a5640 cbnz r0, 0x2a5648 <zip_source_zip+0xec>
 *   @0x2a5644 blx 0xb655c <free@plt>
 *   @0x2a5648 mov r0, r6
 *   @0x2a564c mov r0, r4
 *   @0x2a5650 .word 0xf106ef86
 *   @0x2a5654 ldrbmi r0, [r1], -r12
 *   @0x2a5658 bl 0x2a4314 <_Z15_zip_error_copyP9zip_errorS0_>
 *   @0x2a565c mov r0, r10
 *   @0x2a5660 bl 0x2a4314 <_Z15_zip_error_copyP9zip_errorS0_>
 *   @0x2a5664 movs r0, #0x0
 *   @0x2a5668 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2a566c mrc2 p15, #0x1, apsr_nzcv, c13, c15, #0x7
 *
 * ══ §54/110 png_handle_IHDR  0x2abe50  size 276  69 条（0x2abe50..0x2abf64）
 * @func 0x2abe50 0x2abf64  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_error / png_crc_read / png_crc_finish / png_get_uint_31 / png_handle_IHDR+0xd4 / png_set_IHDR
 * 字段偏移 top8: 0x104×1 / 0x2c×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2abe50 ldr r3, [pc, #0x104]
 *   @0x2abe54 ldrbtmi r4, [r11], #-1008
 *   @0x2abe58 ldr r3, [r3]
 *   @0x2abe5c ldr.w r1, [r0, #0x12c]
 *   @0x2abe60 mov r5, r2
 *   @0x2abe64 sub sp, #0x34
 *   @0x2abe68 strmi r0, [r4], -r1, lsl #30
 *   @0x2abe6c mov r9, r3
 *   @0x2abe70 beq 0x2abe7a <png_handle_IHDR+0x2a>
 *   @0x2abe74 add r1, pc
 *   @0x2abe78 vstrhs s30, [sp, #-868]
 *   @0x2abe7c beq 0x2abe88 <png_handle_IHDR+0x38>
 *   @0x2abe80 mov r0, r4
 *   @0x2abe84 bl 0x2a642c <png_error>
 *   @0x2abe88 ldr.w r3, [r4, #0x12c]
 *   @0x2abe8c add r6, sp, #0x1c
 *   @0x2abe90 mov r0, r4
 *   @0x2abe94 ldrtmi r0, [r1], -r1, lsl #6
 *   @0x2abe98 str.w r3, [r4, #0x12c]
 *   @0x2abe9c bl 0x2abc0c <png_crc_read>
 *   @0x2abea0 movs r1, #0x0
 *   @0x2abea4 bl 0x2abc94 <png_crc_finish>
 *   @0x2abea8 mov r1, r6
 *   @0x2abeac bl 0x2abb6c <png_get_uint_31>
 *   @0x2abeb0 adds r1, r6, #0x4
 *   @0x2abeb4 mov r0, r4
 *   @0x2abeb8 .word 0xf89dfe59
 *   @0x2abebc .word 0xf89d7024
 *   @0x2abec0 .word 0xf89d2025
 *   @0x2abec4 .word 0xf89d1027
 *   @0x2abec8 .word 0xf8c4e028
 *   @0x2abecc .word 0xf884518c
 *   @0x2abed0 .word 0xf88471eb
 *   @0x2abed4 .word 0xf884e1e7
 *   @0x2abed8 .word 0xf88421ea
 *   @0x2abedc strmi r1, [r3], -r4, ror #5
 *   @0x2abee0 ldrb.w r0, [sp, #0x26]
 *   @0x2abee4 str.w r3, [r4, #0x190]
 *   @0x2abee8 strb.w r0, [r4, #0x304]
 *   @0x2abeec cmp r2, #0x6
 *   @0x2abef0 tbb [pc, r2]
 *   @0x2abef4 lsrs r4, r0, #0x14
 *   @0x2abef8 lsrs r0, r1, #0x14
 *   @0x2abefc movs r6, #0x1
 *   @0x2abf00 movs r6, #0x3
 *   @0x2abf04 movs r6, #0x2
 *   @0x2abf08 movs r6, #0x4
 *   @0x2abf0c .word 0xf89461ee
 *   @0x2abf10 cmnmi lr, #-2147483589
 *   @0x2abf14 uxtb r6, r6
 *   @0x2abf18 cdphs p1, #0x0, c6, c7, c13, #0x7
 *   @0x2abf1c bls 0x2abf24 <png_handle_IHDR+0xd4>
 *   @0x2abf20 muls r6, r5, r6
 *   @0x2abf24 muls r6, r5, r6
 *   @0x2abf28 lsrs r6, r6, #0x3
 *   @0x2abf2c mov r2, r5
 *   @0x2abf30 mov r0, r4
 *   @0x2abf34 mov r1, r8
 *   @0x2abf38 .word 0x9700619c
 *   @0x2abf3c str.w lr, [sp, #0x8]
 *   @0x2abf40 bl 0x2aea84 <png_set_IHDR>
 *   @0x2abf44 ldr r2, [sp, #0x2c]
 *   @0x2abf48 addsmi r3, r10, #0
 *   @0x2abf4c beq 0x2abf52 <png_handle_IHDR+0x102>
 *   @0x2abf50 andlt lr, sp, r2, asr #22
 *   @0x2abf54 pop.w {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2abf58 subs r6, r7, r3
 *   @0x2abf5c lsrs r2, r0, #0x18
 *   @0x2abf60 lsrs r6, r0, #0x18
 *
 * ══ §55/110 png_read_filter_row  0x2ae148  size 276  69 条（0x2ae148..0x2ae25c）
 * @func 0x2ae148 0x2ae25c  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0xb×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ae148 push.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ae14c mov r4, r2
 *   @0x2ae150 cmp r2, #0x4
 *   @0x2ae154 tbb [pc, r2]
 *   @0x2ae158 lsls r5, r7, #0xd
 *   @0x2ae15c lsls r0, r0, #0x1
 *   @0x2ae160 ldr r0, [r1, #0x4]
 *   @0x2ae164 asrs r3, r3, #0x3
 *   @0x2ae168 rsbs r1, r3, #0
 *   @0x2ae16c add r4, r1
 *   @0x2ae170 bhs 0x2ae17e <png_read_filter_row+0x36>
 *   @0x2ae174 ldrb r1, [r2, r3]
 *   @0x2ae178 strb r1, [r2, r3]
 *   @0x2ae17c b 0x2ae16e <png_read_filter_row+0x26>
 *   @0x2ae180 stmdavs r9, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} ^
 *   @0x2ae184 movs r2, #0x0
 *   @0x2ae188 beq 0x2ae196 <png_read_filter_row+0x4e>
 *   @0x2ae18c ldrb r0, [r4, r2]
 *   @0x2ae190 strb r0, [r4, r2]
 *   @0x2ae194 b 0x2ae186 <png_read_filter_row+0x3e>
 *   @0x2ae198 bvc 0xff4d2180 <b2_toiTime+0xfffffffffed78cdc>
 *   @0x2ae19c movs r2, #0x0
 *   @0x2ae1a0 adds r0, #0x7
 *   @0x2ae1a4 subs r5, r5, r0
 *   @0x2ae1a8 beq 0x2ae1b8 <png_read_filter_row+0x70>
 *   @0x2ae1ac ldrb r1, [r4, r2]
 *   @0x2ae1b0 strtpl r0, [r1], #342
 *   @0x2ae1b4 adds r2, #0x1
 *   @0x2ae1b8 adds r0, r4, r2
 *   @0x2ae1bc movs r1, #0x0
 *   @0x2ae1c0 beq 0x2ae1d4 <png_read_filter_row+0x8c>
 *   @0x2ae1c4 ldrb r3, [r4, r1]
 *   @0x2ae1c8 ldrb r6, [r0, r1]
 *   @0x2ae1cc strbpl r0, [r3], #-851
 *   @0x2ae1d0 adds r1, #0x1
 *   @0x2ae1d4 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ae1d8 ldrb r0, [r1, #0xb]
 *   @0x2ae1dc adds r0, #0x7
 *   @0x2ae1e0 rsb r9, r0, r2
 *   @0x2ae1e4 movs r2, #0x0
 *   @0x2ae1e8 beq 0x2ae1f6 <png_read_filter_row+0xae>
 *   @0x2ae1ec ldrb r1, [r4, r2]
 *   @0x2ae1f0 strb r1, [r4, r2]
 *   @0x2ae1f4 b 0x2ae1e6 <png_read_filter_row+0x9e>
 *   @0x2ae1f8 add.w r10, r3, r2
 *   @0x2ae1fc movs r2, #0x0
 *   @0x2ae200 beq 0x2ae242 <png_read_filter_row+0xfa>
 *   @0x2ae204 ldrb r1, [r4, r2]
 *   @0x2ae208 bne 0x686218 <g_SWFlinevertbuff+0x33150>
 *   @0x2ae20c rsb r11, r0, r6
 *   @0x2ae210 eor.w r12, r7, r7, asr #31
 *   @0x2ae214 sub.w r12, r12, r7, asr #31
 *   @0x2ae218 eor.w r8, r11, r11, asr #31
 *   @0x2ae21c sub.w r8, r8, r11, asr #31
 *   @0x2ae220 add r7, r11
 *   @0x2ae224 it lt
 *   @0x2ae228 cmp r8, r12
 *   @0x2ae22c cmp r8, r7
 *   @0x2ae230 cmp r12, r7
 *   @0x2ae234 movgt r1, r0
 *   @0x2ae238 ldrb r0, [r5, r2]
 *   @0x2ae23c strb r1, [r5, r2]
 *   @0x2ae240 b 0x2ae1fe <png_read_filter_row+0xb6>
 *   @0x2ae244 stmdbmi r4, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ae248 add r1, pc
 *   @0x2ae24c movwhs pc, #0x913
 *   @0x2ae250 strb r3, [r4]
 *   @0x2ae254 svclt #0x8ff8
 *   @0x2ae258 .word 0xf7b4 000d
 *
 * ══ §56/110 b2PulleyJoint::SolveVelocityConstraints(b2SolverData const&)  0x2d0510  size 276  69 条（0x2d0510..0x2d0624）
 * @func 0x2d0510 0x2d0624  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x78×1 / 0x7c×1 / 0x1c×1
 * VFP 指令 61 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d0510 ldr r2, [r0, #0x78]
 *   @0x2d0514 vpush {d8, d9, d10, d11, d12}
 *   @0x2d0518 ldr r3, [r0, #0x7c]
 *   @0x2d051c vldr s16, [r0, #152]
 *   @0x2d0520 ldr r1, [r1, #0x1c]
 *   @0x2d0524 vldr s0, [r0, #144]
 *   @0x2d0528 add r2, r2, r2, lsl #1
 *   @0x2d052c vldr s11, [r0, #148]
 *   @0x2d0530 add r3, r3, r3, lsl #1
 *   @0x2d0534 vldr s13, [r0, #156]
 *   @0x2d0538 add r2, r1, r2, lsl #2
 *   @0x2d053c vldr s5, [r2, #4]
 *   @0x2d0540 add r3, r1, r3, lsl #2
 *   @0x2d0544 vmov.f32 s15, s5
 *   @0x2d0548 vldr s9, [r3, #4]
 *   @0x2d054c vldr s12, [r2, #8]
 *   @0x2d0550 vldr s14, [r3, #8]
 *   @0x2d0554 vldr s2, [r2]
 *   @0x2d0558 vldr s7, [r3]
 *   @0x2d055c vldr s18, [r0, #140]
 *   @0x2d0560 vmov.f32 s10, s9
 *   @0x2d0564 vldr s4, [r0, #132]
 *   @0x2d0568 vldr s1, [r0, #128]
 *   @0x2d056c vldr s6, [r0, #136]
 *   @0x2d0570 vldr s17, [r0, #112]
 *   @0x2d0574 vldr s22, [r0, #192]
 *   @0x2d0578 vldr s21, [r0, #184]
 *   @0x2d057c vldr s3, [r0, #176]
 *   @0x2d0580 vmla.f32 s10, s14, s16
 *   @0x2d0584 vldr s8, [r0, #180]
 *   @0x2d0588 vldr s20, [r0, #188]
 *   @0x2d058c vldr s19, [r0, #116]
 *   @0x2d0590 vmla.f32 s15, s12, s0
 *   @0x2d0594 vmov.f32 s24, s2
 *   @0x2d0598 vmov.f32 s23, s7
 *   @0x2d059c vmls.f32 s24, s12, s11
 *   @0x2d05a0 vmls.f32 s23, s14, s13
 *   @0x2d05a4 vmul.f32 s15, s15, s4
 *   @0x2d05a8 vmul.f32 s10, s10, s18
 *   @0x2d05ac vmla.f32 s15, s24, s1
 *   @0x2d05b0 vmla.f32 s10, s23, s6
 *   @0x2d05b4 vnmla.f32 s15, s17, s10
 *   @0x2d05b8 vnmul.f32 s15, s22, s15
 *   @0x2d05bc vnmul.f32 s10, s17, s15
 *   @0x2d05c0 vneg.f32 s17, s15
 *   @0x2d05c4 vmul.f32 s6, s10, s6
 *   @0x2d05c8 vmul.f32 s1, s17, s1
 *   @0x2d05cc vmul.f32 s10, s10, s18
 *   @0x2d05d0 vmul.f32 s4, s17, s4
 *   @0x2d05d4 vmul.f32 s13, s13, s6
 *   @0x2d05d8 vmul.f32 s11, s11, s1
 *   @0x2d05dc vnmls.f32 s13, s16, s10
 *   @0x2d05e0 vnmls.f32 s11, s0, s4
 *   @0x2d05e4 vmla.f32 s14, s13, s20
 *   @0x2d05e8 vmla.f32 s12, s11, s21
 *   @0x2d05ec vmla.f32 s2, s3, s1
 *   @0x2d05f0 vmla.f32 s5, s3, s4
 *   @0x2d05f4 vmla.f32 s7, s8, s6
 *   @0x2d05f8 vmla.f32 s9, s8, s10
 *   @0x2d05fc vadd.f32 s15, s19, s15
 *   @0x2d0600 vpop {d8, d9, d10, d11, d12}
 *   @0x2d0604 vstr s15, [r0, #116]
 *   @0x2d0608 vstr s12, [r2, #8]
 *   @0x2d060c vstr s2, [r2]
 *   @0x2d0610 vstr s5, [r2, #4]
 *   @0x2d0614 vstr s14, [r3, #8]
 *   @0x2d0618 vstr s7, [r3]
 *   @0x2d061c vstr s9, [r3, #4]
 *   @0x2d0620 bx lr
 *
 * ══ §57/110 F_DateCreateTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x115250  size 272  68 条（0x115250..0x115360）
 * @func 0x115250 0x115360  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / 0xb6808 / 0xb6814 / YYError(char const*, ...)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x8×2 / 0x1c×2 / 0x24×2 / 0x40×1 / 0x10×1 / 0x14×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115250 push {r4, r5, r6, lr}
 *   @0x115254 sub sp, sp, #48
 *   @0x115258 mov r3, #0
 *   @0x11525c mov r4, r0
 *   @0x115260 ldr r5, [sp, #0x40]
 *   @0x115264 mov r1, r3
 *   @0x115268 str r3, [r0, #0xc]
 *   @0x11526c add r6, sp, #4
 *   @0x115270 str r3, [sp, #0x4]
 *   @0x115274 mov r0, r5
 *   @0x115278 str r3, [sp, #0x8]
 *   @0x11527c str r3, [sp, #0xc]
 *   @0x115280 str r3, [sp, #0x10]
 *   @0x115284 str r3, [sp, #0x14]
 *   @0x115288 str r3, [sp, #0x18]
 *   @0x11528c str r3, [sp, #0x1c]
 *   @0x115290 str r3, [sp, #0x20]
 *   @0x115294 str r3, [sp, #0x24]
 *   @0x115298 str r3, [sp, #0x28]
 *   @0x11529c str r3, [sp, #0x2c]
 *   @0x1152a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1152a4 mov r1, #1
 *   @0x1152a8 str r0, [sp, #0xc]
 *   @0x1152ac mov r0, r5
 *   @0x1152b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1152b4 mov r1, #2
 *   @0x1152b8 str r0, [sp, #0x8]
 *   @0x1152bc mov r0, r5
 *   @0x1152c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1152c4 ldr r3, [pc, #0x8c]
 *   @0x1152c8 mvn r2, #0
 *   @0x1152cc str r2, [sp, #0x24]
 *   @0x1152d0 add r3, pc, r3
 *   @0x1152d4 ldrb r3, [r3]
 *   @0x1152d8 cmp r3, #0
 *   @0x1152dc str r0, [sp, #0x4]
 *   @0x1152e0 mov r0, r6
 *   @0x1152e4 beq 0x115328 <_Z16F_DateCreateTimeR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x1152e8 bl 0xb6808 <mktime64@plt>
 *   @0x1152ec mov r5, r0
 *   @0x1152f0 cmn r5, #1
 *   @0x1152f4 beq 0x115338 <_Z16F_DateCreateTimeR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x1152f8 vmov.f64 d4, #5.000000e-01
 *   @0x1152fc vldr d5, [pc, #68]
 *   @0x115300 vmov s7, r5
 *   @0x115304 vldr d7, [pc, #68]
 *   @0x115308 vcvt.f64.s32 d6, s7
 *   @0x11530c vadd.f64 d6, d6, d4
 *   @0x115310 vdiv.f64 d6, d6, d5
 *   @0x115314 vadd.f64 d5, d6, d7
 *   @0x115318 vmov r2, r3, d5
 *   @0x11531c stm r4, {r2, r3}
 *   @0x115320 add sp, sp, #48
 *   @0x115324 pop {r4, r5, r6, pc}
 *   @0x115328 bl 0xb6814 <timegm64@plt>
 *   @0x11532c mov r5, r0
 *   @0x115330 cmn r5, #1
 *   @0x115334 bne 0x1152f8 <_Z16F_DateCreateTimeR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x115338 ldr r0, [pc, #0x1c]
 *   @0x11533c add r0, pc, r0
 *   @0x115340 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x115344 b 0x1152f8 <_Z16F_DateCreateTimeR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x115348 andeq r0, r0, r0
 *   @0x11534c rscsmi r1, r5, r0, lsl #16
 *   @0x115350 andeq r0, r0, r0
 *   @0x115354 sbcsmi pc, r8, r0, asr #16
 *   @0x115358 eoreq r12, sp, r8, ror #28
 *   @0x11535c eoreq r4, r2, r0, lsr #8
 *
 * ══ §58/110 F_DrawSurfaceTiledExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11f928  size 272  68 条（0x11f928..0x11fa38）
 * @func 0x11f928 0x11fa38  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetInt32(RValue const*, int)×2 / GR_Surface_Exists(int) / GR_Surface_DrawTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x50×1 / 0x98×1 / 0x1c×1 / 0x4×1 / 0xc×1 / 0x8×1 / 0x10×1 / 0x20×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11f928 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11f92c vpush {d8}
 *   @0x11f930 sub sp, sp, #40
 *   @0x11f934 mov r1, #0
 *   @0x11f938 ldr r4, [sp, #0x50]
 *   @0x11f93c mov r0, r4
 *   @0x11f940 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f944 mov r5, r0
 *   @0x11f948 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11f94c subs r1, r0, #0
 *   @0x11f950 beq 0x11fa18 <_Z21F_DrawSurfaceTiledExtR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x11f954 mov r0, r4
 *   @0x11f958 mov r1, #1
 *   @0x11f95c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f960 mov r1, #2
 *   @0x11f964 mov r8, r0
 *   @0x11f968 mov r0, r4
 *   @0x11f96c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f970 mov r1, #3
 *   @0x11f974 mov r7, r0
 *   @0x11f978 mov r0, r4
 *   @0x11f97c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f980 mov r1, #4
 *   @0x11f984 mov r6, r0
 *   @0x11f988 mov r0, r4
 *   @0x11f98c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f990 ldr r12, [pc, #0x98]
 *   @0x11f994 mov r1, #5
 *   @0x11f998 ldr r12, [pc, r12]
 *   @0x11f99c ldr r12, [r12]
 *   @0x11f9a0 vldr s17, [r12, #16]
 *   @0x11f9a4 vldr s16, [r12, #20]
 *   @0x11f9a8 vcvt.f32.s32 s17, s17
 *   @0x11f9ac vcvt.f32.s32 s16, s16
 *   @0x11f9b0 mov r10, r0
 *   @0x11f9b4 mov r0, r4
 *   @0x11f9b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f9bc mov r1, #6
 *   @0x11f9c0 mov r9, r0
 *   @0x11f9c4 mov r0, r4
 *   @0x11f9c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f9cc mov r12, #1
 *   @0x11f9d0 mov lr, #0
 *   @0x11f9d4 str r10, [sp]
 *   @0x11f9d8 vstr s17, [sp, #20]
 *   @0x11f9dc str r9, [sp, #0x1c]
 *   @0x11f9e0 mov r1, r8
 *   @0x11f9e4 mov r2, r7
 *   @0x11f9e8 vstr s16, [sp, #24]
 *   @0x11f9ec mov r3, r6
 *   @0x11f9f0 str r12, [sp, #0x4]
 *   @0x11f9f4 str lr, [sp, #0xc]
 *   @0x11f9f8 str r12, [sp, #0x8]
 *   @0x11f9fc str lr, [sp, #0x10]
 *   @0x11fa00 str r0, [sp, #0x20]
 *   @0x11fa04 mov r0, r5
 *   @0x11fa08 bl 0x172058 <_Z20GR_Surface_DrawTilediffffbbffffjf>
 *   @0x11fa0c add sp, sp, #40
 *   @0x11fa10 vpop {d8}
 *   @0x11fa14 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11fa18 ldr r0, [pc, #0x14]
 *   @0x11fa1c add r0, pc, r0
 *   @0x11fa20 add sp, sp, #40
 *   @0x11fa24 vpop {d8}
 *   @0x11fa28 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11fa2c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11fa30 mlaeq r12, r0, pc, sp
 *   @0x11fa34 eoreq r10, r1, r12, asr #16
 *
 * ══ §59/110 F_GetInteger(RValue&, CInstance*, CInstance*, int, RValue*)  0x12723c  size 272  68 条（0x12723c..0x12734c）
 * @func 0x12723c 0x12734c  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: InputQuery::Input(char const*, char const*, char const*, char*&)×2 / MemoryManager::Free(void const*)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / YYGetString(RValue const*, int) / DebuggerIsConnected() / DebuggerRunBackgroundMessageLoop()
 * 字段偏移 top8: 0x4×5 / 0xc×4 / 0x20×2 / 0xfc×1 / 0x-8×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12723c ldr r1, [pc, #0xfc]
 *   @0x127240 mov r12, #16
 *   @0x127244 push {r4, r5, r6, lr}
 *   @0x127248 sub sp, sp, #16
 *   @0x12724c add r1, pc, r1
 *   @0x127250 mov r2, #1520
 *   @0x127254 mov r3, #1
 *   @0x127258 mov r5, r0
 *   @0x12725c mov r0, r12
 *   @0x127260 str r12, [sp]
 *   @0x127264 ldr r6, [sp, #0x20]
 *   @0x127268 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x12726c mov r4, #0
 *   @0x127270 mov r2, sp
 *   @0x127274 add r1, sp, #4
 *   @0x127278 mov r3, r0
 *   @0x12727c add r0, sp, #16
 *   @0x127280 str r3, [sp, #0x4]
 *   @0x127284 str r3, [r0, #-0x8]!
 *   @0x127288 strb r4, [r3]
 *   @0x12728c add r3, r6, #16
 *   @0x127290 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x127294 ldr r0, [sp, #0x4]
 *   @0x127298 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x12729c mov r0, r6
 *   @0x1272a0 mov r1, r4
 *   @0x1272a4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1272a8 str r4, [sp, #0xc]
 *   @0x1272ac mov r6, r0
 *   @0x1272b0 bl 0x29cb74 <_Z19DebuggerIsConnectedv>
 *   @0x1272b4 cmp r0, r4
 *   @0x1272b8 beq 0x127320 <_Z12F_GetIntegerR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x1272bc bl 0x29cb88 <_Z32DebuggerRunBackgroundMessageLoopv>
 *   @0x1272c0 ldr r0, [pc, #0x7c]
 *   @0x1272c4 mov r1, r6
 *   @0x1272c8 ldr r2, [sp, #0x4]
 *   @0x1272cc ldr r0, [pc, r0]
 *   @0x1272d0 add r3, sp, #12
 *   @0x1272d4 ldr r0, [r0]
 *   @0x1272d8 bl 0xf28b0 <_ZN10InputQuery5InputEPKcS1_S1_RPc>
 *   @0x1272dc bl 0x29cc30 <_Z33DebuggerStopBackgroundMessageLoopv>
 *   @0x1272e0 ldr r0, [sp, #0xc]
 *   @0x1272e4 cmp r0, #0
 *   @0x1272e8 moveq r3, r0
 *   @0x1272ec beq 0x127304 <_Z12F_GetIntegerR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x1272f0 mov r1, #0
 *   @0x1272f4 str r1, [r5, #0xc]
 *   @0x1272f8 bl 0xb6658 <strtod@plt>
 *   @0x1272fc ldr r3, [sp, #0xc]
 *   @0x127300 stm r5, {r0, r1}
 *   @0x127304 mov r0, r3
 *   @0x127308 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x12730c ldr r0, [sp, #0x4]
 *   @0x127310 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x127314 bl 0x18c2c8 <_Z8IO_Clearv>
 *   @0x127318 add sp, sp, #16
 *   @0x12731c pop {r4, r5, r6, pc}
 *   @0x127320 ldr r0, [pc, #0x20]
 *   @0x127324 mov r1, r6
 *   @0x127328 ldr r2, [sp, #0x4]
 *   @0x12732c add r3, sp, #12
 *   @0x127330 ldr r0, [pc, r0]
 *   @0x127334 ldr r0, [r0]
 *   @0x127338 bl 0xf28b0 <_ZN10InputQuery5InputEPKcS1_S1_RPc>
 *   @0x12733c b 0x1272e0 <_Z12F_GetIntegerR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x127340 eoreq r4, r1, r8, ror #31
 *   @0x127344 .word 0x002c77b4
 *   @0x127348 eoreq r7, r12, r0, asr r7
 *
 * ══ §60/110 HttpGetFileCallback(HTTP_REQ_CONTEXT*, void*, int*)  0x138e70  size 272  66 条（0x138e70..0x138f80）
 * @func 0x138e70 0x138f80  size 272  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::WriteFile(char const*, char const*, int) / CreateDsMap(int, ...) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x1c×3 / 0x34×2 / 0x24×2 / 0x20×2 / 0xa8×2 / 0x8c×2 / 0x3c×1 / 0x98×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x138e70 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x138e74 mov r4, r0
 *   @0x138e78 sub sp, sp, #92
 *   @0x138e7c mov r5, r2
 *   @0x138e80 ldr r1, [r4, #0x34]
 *   @0x138e84 ldr r2, [r4, #0x3c]
 *   @0x138e88 ldr r0, [r0, #0x1c]
 *   @0x138e8c bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i>
 *   @0x138e90 vldr s10, [r4, #44]
 *   @0x138e94 vcvt.f64.s32 d5, s10
 *   @0x138e98 vldr s8, [r4, #40]
 *   @0x138e9c vldr d7, [pc, #188]
 *   @0x138ea0 vstr d7, [sp, #8]
 *   @0x138ea4 ldr r2, [r4, #0x24]
 *   @0x138ea8 vstr d7, [sp, #24]
 *   @0x138eac ldr r9, [r4, #0x20]
 *   @0x138eb0 mov r3, #0
 *   @0x138eb4 ldr r8, [r4, #0x1c]
 *   @0x138eb8 ldr r1, [pc, #0xa8]
 *   @0x138ebc ldr r7, [pc, #0xa8]
 *   @0x138ec0 vmov.f64 d6, #-1.000000e+00
 *   @0x138ec4 vstr d5, [sp, #56]
 *   @0x138ec8 vmov s11, r2
 *   @0x138ecc add r1, pc, r1
 *   @0x138ed0 ldr r6, [pc, #0x98]
 *   @0x138ed4 add r7, pc, r7
 *   @0x138ed8 str r1, [sp, #0x44]
 *   @0x138edc ldr lr, [pc, #0x90]
 *   @0x138ee0 add r6, pc, r6
 *   @0x138ee4 ldr r12, [pc, #0x8c]
 *   @0x138ee8 ldr r1, [pc, #0x8c]
 *   @0x138eec add lr, pc, lr
 *   @0x138ef0 add r12, pc, r12
 *   @0x138ef4 str lr, [sp, #0x24]
 *   @0x138ef8 str r12, [sp, #0x34]
 *   @0x138efc add r1, pc, r1
 *   @0x138f00 str r3, [sp]
 *   @0x138f04 vcvt.f64.s32 d4, s8
 *   @0x138f08 str r3, [sp, #0x30]
 *   @0x138f0c str r3, [sp, #0x40]
 *   @0x138f10 str r3, [sp, #0x50]
 *   @0x138f14 str r9, [sp, #0x10]
 *   @0x138f18 str r8, [sp, #0x20]
 *   @0x138f1c str r7, [sp, #0x4]
 *   @0x138f20 str r6, [sp, #0x14]
 *   @0x138f24 vcvt.f64.s32 d5, s11
 *   @0x138f28 vstr d4, [sp, #40]
 *   @0x138f2c cmp r0, #0
 *   @0x138f30 vmov r2, r3, d5
 *   @0x138f34 mov r0, #6
 *   @0x138f38 vmoveq.f64 d7, d6
 *   @0x138f3c vstr d7, [sp, #72]
 *   @0x138f40 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x138f44 str r0, [r5]
 *   @0x138f48 ldr r0, [r4, #0x1c]
 *   @0x138f4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x138f50 mov r0, #62
 *   @0x138f54 add sp, sp, #92
 *   @0x138f58 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x138f5c nop
 *   @0x138f68 andseq r7, pc, r4, lsl #23
 *   @0x138f6c .word 0x002071f8
 *   @0x138f70 andseq lr, pc, r8, ror r0
 *   @0x138f74 andseq r7, pc, r8, asr r11
 *   @0x138f78 eoreq r7, r0, r0, ror #3
 *   @0x138f7c andseq r7, pc, r4, asr #22
 *
 * ══ §61/110 F_D3DMatrixStackSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x1495b4  size 272  68 条（0x1495b4..0x1496c4）
 * @func 0x1495b4 0x1496c4  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0xe8×1 / 0x58×1 / 0x9c×1 / 0x40×1 / 0x34×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1495b4 cmp r3, #1
 *   @0x1495b8 push {r4, r5, r6, r7, lr}
 *   @0x1495bc sub sp, sp, #68
 *   @0x1495c0 beq 0x1495dc <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x1495c4 ldr r0, [pc, #0xe8]
 *   @0x1495c8 mov r1, #0
 *   @0x1495cc add r0, pc, r0
 *   @0x1495d0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1495d4 add sp, sp, #68
 *   @0x1495d8 pop {r4, r5, r6, r7, pc}
 *   @0x1495dc ldr r2, [sp, #0x58]
 *   @0x1495e0 ldr r3, [r2, #0xc]
 *   @0x1495e4 bic r3, r3, #-16777216
 *   @0x1495e8 cmp r3, #2
 *   @0x1495ec bne 0x1495c4 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x10>
 *   @0x1495f0 ldr r3, [r2]
 *   @0x1495f4 cmp r3, #0
 *   @0x1495f8 beq 0x149614 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x1495fc ldr r3, [r3, #0x4]
 *   @0x149600 cmp r3, #0
 *   @0x149604 beq 0x149614 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x149608 ldr r2, [r3]
 *   @0x14960c cmp r2, #16
 *   @0x149610 beq 0x14962c <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x149614 ldr r0, [pc, #0x9c]
 *   @0x149618 mov r1, #1
 *   @0x14961c add r0, pc, r0
 *   @0x149620 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x149624 add sp, sp, #68
 *   @0x149628 pop {r4, r5, r6, r7, pc}
 *   @0x14962c ldr r4, [r3, #0x4]
 *   @0x149630 add r6, sp, #64
 *   @0x149634 mov r5, sp
 *   @0x149638 b 0x149658 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x14963c ldm r4, {r0, r1}
 *   @0x149640 vmov d6, r0, r1
 *   @0x149644 add r4, r4, #16
 *   @0x149648 vcvt.f32.f64 s15, d6
 *   @0x14964c vstmia r5!, {s15}
 *   @0x149650 cmp r5, r6
 *   @0x149654 beq 0x149674 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x149658 ldr r3, [r4, #0xc]
 *   @0x14965c bic r3, r3, #-16777216
 *   @0x149660 cmp r3, #0
 *   @0x149664 beq 0x14963c <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x149668 mov r0, r4
 *   @0x14966c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x149670 b 0x149640 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x149674 ldr r5, [pc, #0x40]
 *   @0x149678 mov r4, sp
 *   @0x14967c ldm r4!, {r0, r1, r2, r3}
 *   @0x149680 ldr r5, [pc, r5]
 *   @0x149684 ldr r12, [pc, #0x34]
 *   @0x149688 ldr r5, [r5]
 *   @0x14968c ldr r12, [pc, r12]
 *   @0x149690 add r12, r12, r5, lsl #6
 *   @0x149694 stm r12!, {r0, r1, r2, r3}
 *   @0x149698 ldm r4!, {r0, r1, r2, r3}
 *   @0x14969c stm r12!, {r0, r1, r2, r3}
 *   @0x1496a0 ldm r4!, {r0, r1, r2, r3}
 *   @0x1496a4 stm r12!, {r0, r1, r2, r3}
 *   @0x1496a8 ldm r4, {r0, r1, r2, r3}
 *   @0x1496ac stm r12, {r0, r1, r2, r3}
 *   @0x1496b0 b 0x1495d4 <_Z19F_D3DMatrixStackSetR6RValueP9CInstanceS2_iPS_+0x20>
 *   @0x1496b4 andseq r9, pc, r4, lsl r3
 *   @0x1496b8 andseq r9, pc, r8, ror #5
 *   @0x1496bc eoreq r5, r10, r4, lsl #31
 *   @0x1496c0 eoreq r5, r10, r12, ror pc
 *
 * ══ §62/110 F_IAP_EnumerateProducts(RValue&, CInstance*, CInstance*, int, RValue*)  0x155724  size 272  68 条（0x155724..0x155834）
 * @func 0x155724 0x155834  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x155748→0x4836b8, 0x15575c→0x4836bc, 0x155778→0x484a58, 0x15578c→0x484a5c
 * 调用序列: F_IAP_EnumerateProducts(RValue&, CInstance*, CInstance*, int, RValue*)+0xd8×2 / YYGetInt32(RValue const*, int) / F_IAP_EnumerateProducts(RValue&, CInstance*, CInstance*, int, RValue*)+0xe0 / YYSetString(RValue*, char const*) / CDS_List::Add(RValue*) / FREE_RValue__Pre(RValue*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x30×1 / 0xdc×1 / 0xd0×1 / 0xc0×1 / 0xa8×1 / 0x98×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x155724 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x155728 sub sp, sp, #20
 *   @0x15572c mov r1, #0
 *   @0x155730 ldr r0, [sp, #0x30]
 *   @0x155734 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x155738 ldr r3, [pc, #0xdc]
 *   @0x15573c add r3, pc, r3
 *   @0x155740 cmp r0, #0
 *   @0x155744 blt 0x155804 <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x155748 ldr r2, [pc, #0xd0]
 *   @0x15574c ldr r2, [r3, r2]
 *   @0x155750 ldr r2, [r2]
 *   @0x155754 cmp r0, r2
 *   @0x155758 bge 0x155804 <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x15575c ldr r2, [pc, #0xc0]
 *   @0x155760 lsl r8, r0, #2
 *   @0x155764 ldr r6, [r3, r2]
 *   @0x155768 ldr r2, [r6, #0x4]
 *   @0x15576c ldr r2, [r2, r0, lsl #2]
 *   @0x155770 cmp r2, #0
 *   @0x155774 beq 0x155804 <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x155778 ldr r2, [pc, #0xa8]
 *   @0x15577c ldr r7, [r3, r2]
 *   @0x155780 ldr r2, [r7]
 *   @0x155784 cmp r2, #0
 *   @0x155788 ble 0x1557fc <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x15578c ldr r2, [pc, #0x98]
 *   @0x155790 mov r4, #0
 *   @0x155794 ldr r9, [r3, r2]
 *   @0x155798 b 0x1557a8 <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x15579c ldr r3, [r7]
 *   @0x1557a0 cmp r3, r4
 *   @0x1557a4 ble 0x1557fc <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x1557a8 ldr r3, [r9, #0x4]
 *   @0x1557ac mov r0, sp
 *   @0x1557b0 ldr r3, [r3, r4, lsl #2]
 *   @0x1557b4 add r4, r4, #1
 *   @0x1557b8 ldr r1, [r3]
 *   @0x1557bc bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x1557c0 ldr r3, [r6, #0x4]
 *   @0x1557c4 mov r1, sp
 *   @0x1557c8 ldr r0, [r3, r8]
 *   @0x1557cc bl 0x205d18 <_ZN8CDS_List3AddEP6RValue>
 *   @0x1557d0 ldr r3, [sp, #0xc]
 *   @0x1557d4 sub r3, r3, #1
 *   @0x1557d8 bic r3, r3, #-16777216
 *   @0x1557dc bic r3, r3, #3
 *   @0x1557e0 cmp r3, #0
 *   @0x1557e4 bne 0x15579c <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1557e8 mov r0, sp
 *   @0x1557ec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1557f0 ldr r3, [r7]
 *   @0x1557f4 cmp r3, r4
 *   @0x1557f8 bgt 0x1557a8 <_Z23F_IAP_EnumerateProductsR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1557fc add sp, sp, #20
 *   @0x155800 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x155804 ldr r0, [pc, #0x24]
 *   @0x155808 mov r1, #0
 *   @0x15580c add r0, pc, r0
 *   @0x155810 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x155814 add sp, sp, #20
 *   @0x155818 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x15581c eoreq r12, r9, r4, lsl r5
 *   @0x155820 .word 0xffffc02c
 *   @0x155824 .word 0xffffc030
 *   @0x155828 .word 0xffffde80
 *   @0x15582c .word 0xffffde84
 *   @0x155830 ldrsheq r2, [lr], -r0
 *
 * ══ §63/110 GMLCallback(int, int, RValue*)  0x159f9c  size 272  68 条（0x159f9c..0x15a0ac）
 * @func 0x159f9c 0x15a0ac  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f2360
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DsQueueEnqueue(int, int, ...)×3 / Mutex::Lock() / DsQueueCreate()
 * 字段偏移 top8: 0xf8×1 / 0xf0×1 / 0xb0×1 / 0xc×1 / 0x4×1 / 0x28×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159f9c ldr r3, [pc, #0xf8]
 *   @0x159fa0 push {r4, r5, r6, r7, r8, lr}
 *   @0x159fa4 add r3, pc, r3
 *   @0x159fa8 ldr r5, [pc, #0xf0]
 *   @0x159fac sub sp, sp, #8
 *   @0x159fb0 mov r8, r0
 *   @0x159fb4 ldr r0, [r3]
 *   @0x159fb8 add r5, pc, r5
 *   @0x159fbc mov r6, r1
 *   @0x159fc0 mov r4, r2
 *   @0x159fc4 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x159fc8 ldr r3, [r5]
 *   @0x159fcc cmn r3, #1
 *   @0x159fd0 movne r0, r3
 *   @0x159fd4 beq 0x15a08c <_Z11GMLCallbackiiP6RValue+0xf0>
 *   @0x159fd8 vmov s15, r8
 *   @0x159fdc mov r5, #0
 *   @0x159fe0 mov r1, #1
 *   @0x159fe4 str r5, [sp]
 *   @0x159fe8 vcvt.f64.s32 d7, s15
 *   @0x159fec ldr r7, [pc, #0xb0]
 *   @0x159ff0 add r7, pc, r7
 *   @0x159ff4 vmov r2, r3, d7
 *   @0x159ff8 bl 0x2053f0 <_Z14DsQueueEnqueueiiz>
 *   @0x159ffc ldr r0, [r7]
 *   @0x15a000 vmov s15, r6
 *   @0x15a004 str r5, [sp]
 *   @0x15a008 mov r1, #1
 *   @0x15a00c vcvt.f64.s32 d7, s15
 *   @0x15a010 vmov r2, r3, d7
 *   @0x15a014 bl 0x2053f0 <_Z14DsQueueEnqueueiiz>
 *   @0x15a018 cmp r6, r5
 *   @0x15a01c bgt 0x15a048 <_Z11GMLCallbackiiP6RValue+0xac>
 *   @0x15a020 b 0x15a078 <_Z11GMLCallbackiiP6RValue+0xdc>
 *   @0x15a024 mov r3, r1
 *   @0x15a028 mov r2, r12
 *   @0x15a02c str lr, [sp]
 *   @0x15a030 add r5, r5, #1
 *   @0x15a034 mov r1, #1
 *   @0x15a038 add r4, r4, #16
 *   @0x15a03c bl 0x2053f0 <_Z14DsQueueEnqueueiiz>
 *   @0x15a040 cmp r5, r6
 *   @0x15a044 beq 0x15a078 <_Z11GMLCallbackiiP6RValue+0xdc>
 *   @0x15a048 ldr r3, [r4, #0xc]
 *   @0x15a04c mov lr, #0
 *   @0x15a050 ldr r0, [r7]
 *   @0x15a054 bic r3, r3, #-16777216
 *   @0x15a058 ldr r12, [r4]
 *   @0x15a05c cmp r3, #1
 *   @0x15a060 ldr r1, [r4, #0x4]
 *   @0x15a064 bne 0x15a024 <_Z11GMLCallbackiiP6RValue+0x88>
 *   @0x15a068 cmp r12, lr
 *   @0x15a06c ldrne lr, [r12]
 *   @0x15a070 moveq lr, r12
 *   @0x15a074 b 0x15a024 <_Z11GMLCallbackiiP6RValue+0x88>
 *   @0x15a078 ldr r3, [pc, #0x28]
 *   @0x15a07c ldr r0, [pc, r3]
 *   @0x15a080 add sp, sp, #8
 *   @0x15a084 pop {r4, r5, r6, r7, r8, lr}
 *   @0x15a088 b 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x15a08c bl 0x2053bc <_Z13DsQueueCreatev>
 *   @0x15a090 mov r3, r0
 *   @0x15a094 str r3, [r5]
 *   @0x15a098 b 0x159fd8 <_Z11GMLCallbackiiP6RValue+0x3c>
 *   @0x15a09c eorseq r10, r2, r4, asr #21
 *   @0x15a0a0 eoreq r8, r9, r0, lsr #7
 *   @0x15a0a4 eoreq r8, r9, r8, ror #6
 *   @0x15a0a8 eorseq r10, r2, r12, ror #19
 *
 * ══ §64/110 InitShaderVariations(int*, char*, char*, bool)  0x183b70  size 272  68 条（0x183b70..0x183c80）
 * @func 0x183b70 0x183c80  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x183ba0→0x3f4554, 0x183bb0→0x3f335c, 0x183bc8→0x3f4fd8, 0x183bcc→0x3f4c74
 * 调用序列: GenerateShaderVariation(int, char*, char*, char*, bool)×2 / MemoryManager::Free(void const*)×2 / Shader_Add(char*, char*, char**, bool*, int, char**) / InitShaderVariations(int*, char*, char*, bool)+0x7c
 * 字段偏移 top8: 0xc×2 / 0xa8×2 / 0x10×2 / 0x18×2 / 0x14×2 / 0x1c×2 / 0x4×2 / 0xe4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183b70 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x183b74 mov r9, r1
 *   @0x183b78 ldr r1, [r0]
 *   @0x183b7c mov r6, r3
 *   @0x183b80 ldr r3, [pc, #0xe4]
 *   @0x183b84 sub sp, sp, #36
 *   @0x183b88 cmn r1, #1
 *   @0x183b8c mov r10, r2
 *   @0x183b90 add r3, pc, r3
 *   @0x183b94 beq 0x183ba0 <_Z20InitShaderVariationsPiPcS0_b+0x30>
 *   @0x183b98 add sp, sp, #36
 *   @0x183b9c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x183ba0 ldr r12, [pc, #0xc8]
 *   @0x183ba4 mov r4, #0
 *   @0x183ba8 cmp r6, r4
 *   @0x183bac sub r8, r0, #4
 *   @0x183bb0 ldr r0, [pc, #0xbc]
 *   @0x183bb4 mov r7, r4
 *   @0x183bb8 moveq r2, #4
 *   @0x183bbc movne r2, #16
 *   @0x183bc0 str r2, [sp, #0xc]
 *   @0x183bc4 ldr r12, [r3, r12]
 *   @0x183bc8 ldr r1, [pc, #0xa8]
 *   @0x183bcc ldr r2, [pc, #0xa8]
 *   @0x183bd0 str r12, [sp, #0x10]
 *   @0x183bd4 ldr r0, [r3, r0]
 *   @0x183bd8 str r0, [sp, #0x18]
 *   @0x183bdc ldr r1, [r3, r1]
 *   @0x183be0 str r1, [sp, #0x14]
 *   @0x183be4 ldr r2, [r3, r2]
 *   @0x183be8 str r2, [sp, #0x1c]
 *   @0x183bec mov r0, r4
 *   @0x183bf0 ldr r1, [sp, #0x10]
 *   @0x183bf4 ldr r2, [sp, #0x18]
 *   @0x183bf8 mov r3, r9
 *   @0x183bfc str r6, [sp]
 *   @0x183c00 bl 0x1839b0 <_Z23GenerateShaderVariationiPcS_S_b>
 *   @0x183c04 ldr r1, [sp, #0x14]
 *   @0x183c08 ldr r2, [sp, #0x1c]
 *   @0x183c0c mov r3, r10
 *   @0x183c10 str r6, [sp]
 *   @0x183c14 mov r5, r0
 *   @0x183c18 mov r0, r4
 *   @0x183c1c bl 0x1839b0 <_Z23GenerateShaderVariationiPcS_S_b>
 *   @0x183c20 mov r2, #0
 *   @0x183c24 mov r3, r2
 *   @0x183c28 str r7, [sp]
 *   @0x183c2c str r7, [sp, #0x4]
 *   @0x183c30 add r4, r4, #1
 *   @0x183c34 mov r11, r0
 *   @0x183c38 mov r0, r5
 *   @0x183c3c mov r1, r11
 *   @0x183c40 bl 0x187b7c <_Z10Shader_AddPcS_PS_PbiS0_>
 *   @0x183c44 str r0, [r8, #0x4]!
 *   @0x183c48 mov r0, r5
 *   @0x183c4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x183c50 mov r0, r11
 *   @0x183c54 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x183c58 ldr r3, [sp, #0xc]
 *   @0x183c5c cmp r4, r3
 *   @0x183c60 blt 0x183bec <_Z20InitShaderVariationsPiPcS0_b+0x7c>
 *   @0x183c64 add sp, sp, #36
 *   @0x183c68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x183c6c eoreq lr, r6, r0, asr #1
 *   @0x183c70 .word 0xffffe910
 *   @0x183c74 .word 0xffffe914
 *   @0x183c78 .word 0xffffe918
 *   @0x183c7c .word 0xffffe91c
 *
 * ══ §65/110 F_LayerTileExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c0ac8  size 272  68 条（0x1c0ac8..0x1c0bd8）
 * @func 0x1c0ac8 0x1c0bd8  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_LayerTileExists(RValue&, CInstance*, CInstance*, int, RValue*)+0x40 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::GetElementFromID(CLayer*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0xd8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c0ac8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c0acc mov r6, r3
 *   @0x1c0ad0 sub r3, r3, #1
 *   @0x1c0ad4 mov r4, #0
 *   @0x1c0ad8 cmp r3, #1
 *   @0x1c0adc mov r5, r0
 *   @0x1c0ae0 ldr r7, [sp, #0x18]
 *   @0x1c0ae4 str r4, [r0, #0xc]
 *   @0x1c0ae8 str r4, [r0]
 *   @0x1c0aec str r4, [r0, #0x4]
 *   @0x1c0af0 bls 0x1c0b08 <_Z17F_LayerTileExistsR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1c0af4 ldr r0, [pc, #0xd8]
 *   @0x1c0af8 mov r1, r4
 *   @0x1c0afc pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c0b00 add r0, pc, r0
 *   @0x1c0b04 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c0b08 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c0b0c cmp r6, #1
 *   @0x1c0b10 mov r8, r0
 *   @0x1c0b14 beq 0x1c0b88 <_Z17F_LayerTileExistsR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1c0b18 ldr r3, [r7, #0xc]
 *   @0x1c0b1c mov r1, r4
 *   @0x1c0b20 mov r0, r7
 *   @0x1c0b24 bic r3, r3, #-16777216
 *   @0x1c0b28 cmp r3, #1
 *   @0x1c0b2c beq 0x1c0bbc <_Z17F_LayerTileExistsR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x1c0b30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0b34 mov r1, r0
 *   @0x1c0b38 mov r0, r8
 *   @0x1c0b3c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c0b40 mov r4, r0
 *   @0x1c0b44 cmp r4, #0
 *   @0x1c0b48 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1c0b4c mov r1, #1
 *   @0x1c0b50 mov r0, r7
 *   @0x1c0b54 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0b58 mov r1, r0
 *   @0x1c0b5c mov r0, r4
 *   @0x1c0b60 bl 0x1c07e4 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri>
 *   @0x1c0b64 cmp r0, #0
 *   @0x1c0b68 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1c0b6c ldr r3, [r0]
 *   @0x1c0b70 cmp r3, #7
 *   @0x1c0b74 moveq r3, #0
 *   @0x1c0b78 moveq r2, r3
 *   @0x1c0b7c movteq r3, #0x3ff0
 *   @0x1c0b80 stmeq r5, {r2, r3}
 *   @0x1c0b84 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c0b88 mov r1, r4
 *   @0x1c0b8c mov r0, r7
 *   @0x1c0b90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0b94 mov r2, r4
 *   @0x1c0b98 mov r1, r0
 *   @0x1c0b9c mov r0, r8
 *   @0x1c0ba0 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1c0ba4 cmp r0, #0
 *   @0x1c0ba8 movne r3, #0
 *   @0x1c0bac strne r4, [r5]
 *   @0x1c0bb0 movtne r3, #0x3ff0
 *   @0x1c0bb4 strne r3, [r5, #0x4]
 *   @0x1c0bb8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c0bbc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c0bc0 mov r1, r0
 *   @0x1c0bc4 mov r0, r8
 *   @0x1c0bc8 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c0bcc mov r4, r0
 *   @0x1c0bd0 b 0x1c0b44 <_Z17F_LayerTileExistsR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x1c0bd4 andseq lr, r8, r4, lsr pc
 *
 * ══ §66/110 F_Shader_Set_Uniform_I_Array(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e1848  size 272  68 条（0x1e1848..0x1e1958）
 * @func 0x1e1848 0x1e1958  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / YYGetInt32(RValue const*, int)×2 / Graphics::Flush() / F_Shader_Set_Uniform_I_Array(RValue&, CInstance*, CInstance*, int, RValue*)+0xc4 / Shader_Set_Uniform_IA(int, int, int*) / FlushShader() / 0xb65d4
 * 字段偏移 top8: 0x4×4 / 0x-28×2 / 0xec×1 / 0x1c×1 / 0xd0×1 / 0xa8×1 / 0x10×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1848 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e184c add r11, sp, #32
 *   @0x1e1850 sub sp, sp, #12
 *   @0x1e1854 ldr r6, [pc, #0xec]
 *   @0x1e1858 ldr r9, [r11, #0x4]
 *   @0x1e185c ldr r6, [pc, r6]
 *   @0x1e1860 ldr r3, [r6]
 *   @0x1e1864 ldr r2, [r9, #0x1c]
 *   @0x1e1868 cmp r2, #2
 *   @0x1e186c str r3, [r11, #-0x28]
 *   @0x1e1870 beq 0x1e189c <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1e1874 ldr r0, [pc, #0xd0]
 *   @0x1e1878 mov r1, #0
 *   @0x1e187c add r0, pc, r0
 *   @0x1e1880 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e1884 ldr r2, [r11, #-0x28]
 *   @0x1e1888 ldr r3, [r6]
 *   @0x1e188c cmp r2, r3
 *   @0x1e1890 bne 0x1e1944 <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x1e1894 sub sp, r11, #32
 *   @0x1e1898 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e189c bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1e18a0 ldr r3, [pc, #0xa8]
 *   @0x1e18a4 ldr r3, [pc, r3]
 *   @0x1e18a8 ldrb r3, [r3]
 *   @0x1e18ac cmp r3, #0
 *   @0x1e18b0 bne 0x1e193c <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x1e18b4 ldr r3, [r9, #0x10]
 *   @0x1e18b8 ldr r3, [r3, #0x4]
 *   @0x1e18bc ldr r8, [r3]
 *   @0x1e18c0 cmp r8, #0
 *   @0x1e18c4 beq 0x1e1928 <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x1e18c8 lsl r2, r8, #2
 *   @0x1e18cc ldr r4, [r3, #0x4]
 *   @0x1e18d0 add r3, r2, #14
 *   @0x1e18d4 movgt r5, #0
 *   @0x1e18d8 bic r3, r3, #7
 *   @0x1e18dc sub sp, sp, r3
 *   @0x1e18e0 subgt r7, sp, #4
 *   @0x1e18e4 mov r10, sp
 *   @0x1e18e8 ble 0x1e190c <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x1e18ec mov r0, r4
 *   @0x1e18f0 mov r1, #0
 *   @0x1e18f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e18f8 add r5, r5, #1
 *   @0x1e18fc cmp r5, r8
 *   @0x1e1900 add r4, r4, #16
 *   @0x1e1904 str r0, [r7, #0x4]!
 *   @0x1e1908 bne 0x1e18ec <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x1e190c mov r0, r9
 *   @0x1e1910 mov r1, #0
 *   @0x1e1914 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e1918 mov r1, r8
 *   @0x1e191c mov r2, r10
 *   @0x1e1920 bl 0x188794 <_Z21Shader_Set_Uniform_IAiiPi>
 *   @0x1e1924 b 0x1e1884 <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1e1928 ldr r0, [pc, #0x24]
 *   @0x1e192c mov r1, r8
 *   @0x1e1930 add r0, pc, r0
 *   @0x1e1934 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e1938 b 0x1e1884 <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1e193c bl 0x1e1520 <_Z11FlushShaderv>
 *   @0x1e1940 b 0x1e18b4 <_Z28F_Shader_Set_Uniform_I_ArrayR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1e1944 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1e1948 .word 0x0020c0f4
 *   @0x1e194c andseq r1, r6, r0, lsr r1
 *   @0x1e1950 eoreq pc, r0, r8, lsr #9
 *   @0x1e1954 andseq r0, r7, r12, asr r4
 *
 * ══ §67/110 F_Shader_Set_Uniform_F_Array(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e1a60  size 272  68 条（0x1e1a60..0x1e1b70）
 * @func 0x1e1a60 0x1e1b70  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / Graphics::Flush() / F_Shader_Set_Uniform_F_Array(RValue&, CInstance*, CInstance*, int, RValue*)+0xc4 / YYGetFloat(RValue const*, int) / YYGetInt32(RValue const*, int) / Shader_Set_Uniform_FA(int, int, float*) / FlushShader() / 0xb65d4
 * 字段偏移 top8: 0x4×4 / 0x-28×2 / 0xec×1 / 0x1c×1 / 0xd0×1 / 0xa8×1 / 0x10×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1a60 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e1a64 add r11, sp, #32
 *   @0x1e1a68 sub sp, sp, #12
 *   @0x1e1a6c ldr r6, [pc, #0xec]
 *   @0x1e1a70 ldr r9, [r11, #0x4]
 *   @0x1e1a74 ldr r6, [pc, r6]
 *   @0x1e1a78 ldr r3, [r6]
 *   @0x1e1a7c ldr r2, [r9, #0x1c]
 *   @0x1e1a80 cmp r2, #2
 *   @0x1e1a84 str r3, [r11, #-0x28]
 *   @0x1e1a88 beq 0x1e1ab4 <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1e1a8c ldr r0, [pc, #0xd0]
 *   @0x1e1a90 mov r1, #0
 *   @0x1e1a94 add r0, pc, r0
 *   @0x1e1a98 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e1a9c ldr r2, [r11, #-0x28]
 *   @0x1e1aa0 ldr r3, [r6]
 *   @0x1e1aa4 cmp r2, r3
 *   @0x1e1aa8 bne 0x1e1b5c <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x1e1aac sub sp, r11, #32
 *   @0x1e1ab0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e1ab4 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1e1ab8 ldr r3, [pc, #0xa8]
 *   @0x1e1abc ldr r3, [pc, r3]
 *   @0x1e1ac0 ldrb r3, [r3]
 *   @0x1e1ac4 cmp r3, #0
 *   @0x1e1ac8 bne 0x1e1b54 <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x1e1acc ldr r3, [r9, #0x10]
 *   @0x1e1ad0 ldr r3, [r3, #0x4]
 *   @0x1e1ad4 ldr r8, [r3]
 *   @0x1e1ad8 cmp r8, #0
 *   @0x1e1adc beq 0x1e1b40 <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x1e1ae0 lsl r2, r8, #2
 *   @0x1e1ae4 ldr r4, [r3, #0x4]
 *   @0x1e1ae8 add r3, r2, #14
 *   @0x1e1aec movgt r5, #0
 *   @0x1e1af0 bic r3, r3, #7
 *   @0x1e1af4 sub sp, sp, r3
 *   @0x1e1af8 mov r10, sp
 *   @0x1e1afc movgt r7, sp
 *   @0x1e1b00 ble 0x1e1b24 <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x1e1b04 mov r0, r4
 *   @0x1e1b08 mov r1, #0
 *   @0x1e1b0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1e1b10 add r5, r5, #1
 *   @0x1e1b14 cmp r5, r8
 *   @0x1e1b18 add r4, r4, #16
 *   @0x1e1b1c str r0, [r7], #4
 *   @0x1e1b20 bne 0x1e1b04 <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x1e1b24 mov r0, r9
 *   @0x1e1b28 mov r1, #0
 *   @0x1e1b2c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e1b30 mov r1, r8
 *   @0x1e1b34 mov r2, r10
 *   @0x1e1b38 bl 0x188a9c <_Z21Shader_Set_Uniform_FAiiPf>
 *   @0x1e1b3c b 0x1e1a9c <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1e1b40 ldr r0, [pc, #0x24]
 *   @0x1e1b44 mov r1, r8
 *   @0x1e1b48 add r0, pc, r0
 *   @0x1e1b4c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e1b50 b 0x1e1a9c <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1e1b54 bl 0x1e1520 <_Z11FlushShaderv>
 *   @0x1e1b58 b 0x1e1acc <_Z28F_Shader_Set_Uniform_F_ArrayR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1e1b5c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1e1b60 .word 0x0020bedc
 *   @0x1e1b64 andseq r0, r6, r8, lsl pc
 *   @0x1e1b68 mlaeq r0, r0, r2, pc
 *   @0x1e1b6c andseq r0, r7, r4, asr #4
 *
 * ══ §68/110 F_Shader_Set_Uniform_Matrix_Array(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e1bc8  size 272  68 条（0x1e1bc8..0x1e1cd8）
 * @func 0x1e1bc8 0x1e1cd8  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / Graphics::Flush() / F_Shader_Set_Uniform_Matrix_Array(RValue&, CInstance*, CInstance*, int, RValue*)+0xc4 / YYGetFloat(RValue const*, int) / YYGetInt32(RValue const*, int) / Shader_Set_Uniform_Matrix_N(int, int, float*) / FlushShader() / 0xb65d4
 * 字段偏移 top8: 0x4×4 / 0x-28×2 / 0xec×1 / 0x1c×1 / 0xd0×1 / 0xa8×1 / 0x10×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1bc8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e1bcc add r11, sp, #32
 *   @0x1e1bd0 sub sp, sp, #12
 *   @0x1e1bd4 ldr r6, [pc, #0xec]
 *   @0x1e1bd8 ldr r9, [r11, #0x4]
 *   @0x1e1bdc ldr r6, [pc, r6]
 *   @0x1e1be0 ldr r3, [r6]
 *   @0x1e1be4 ldr r2, [r9, #0x1c]
 *   @0x1e1be8 cmp r2, #2
 *   @0x1e1bec str r3, [r11, #-0x28]
 *   @0x1e1bf0 beq 0x1e1c1c <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1e1bf4 ldr r0, [pc, #0xd0]
 *   @0x1e1bf8 mov r1, #0
 *   @0x1e1bfc add r0, pc, r0
 *   @0x1e1c00 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e1c04 ldr r2, [r11, #-0x28]
 *   @0x1e1c08 ldr r3, [r6]
 *   @0x1e1c0c cmp r2, r3
 *   @0x1e1c10 bne 0x1e1cc4 <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x1e1c14 sub sp, r11, #32
 *   @0x1e1c18 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e1c1c bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1e1c20 ldr r3, [pc, #0xa8]
 *   @0x1e1c24 ldr r3, [pc, r3]
 *   @0x1e1c28 ldrb r3, [r3]
 *   @0x1e1c2c cmp r3, #0
 *   @0x1e1c30 bne 0x1e1cbc <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x1e1c34 ldr r3, [r9, #0x10]
 *   @0x1e1c38 ldr r3, [r3, #0x4]
 *   @0x1e1c3c ldr r8, [r3]
 *   @0x1e1c40 bic r8, r8, #15
 *   @0x1e1c44 cmp r8, #0
 *   @0x1e1c48 beq 0x1e1ca8 <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x1e1c4c lsl r2, r8, #2
 *   @0x1e1c50 ldr r4, [r3, #0x4]
 *   @0x1e1c54 add r3, r2, #8
 *   @0x1e1c58 movgt r5, #0
 *   @0x1e1c5c sub sp, sp, r3
 *   @0x1e1c60 mov r10, sp
 *   @0x1e1c64 movgt r7, sp
 *   @0x1e1c68 ble 0x1e1c8c <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x1e1c6c mov r0, r4
 *   @0x1e1c70 mov r1, #0
 *   @0x1e1c74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1e1c78 add r5, r5, #1
 *   @0x1e1c7c cmp r5, r8
 *   @0x1e1c80 add r4, r4, #16
 *   @0x1e1c84 str r0, [r7], #4
 *   @0x1e1c88 bne 0x1e1c6c <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x1e1c8c mov r0, r9
 *   @0x1e1c90 mov r1, #0
 *   @0x1e1c94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1e1c98 asr r1, r8, #4
 *   @0x1e1c9c mov r2, r10
 *   @0x1e1ca0 bl 0x1889fc <_Z27Shader_Set_Uniform_Matrix_NiiPf>
 *   @0x1e1ca4 b 0x1e1c04 <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1e1ca8 ldr r0, [pc, #0x24]
 *   @0x1e1cac mov r1, r8
 *   @0x1e1cb0 add r0, pc, r0
 *   @0x1e1cb4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e1cb8 b 0x1e1c04 <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1e1cbc bl 0x1e1520 <_Z11FlushShaderv>
 *   @0x1e1cc0 b 0x1e1c34 <_Z33F_Shader_Set_Uniform_Matrix_ArrayR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1e1cc4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1e1cc8 eoreq r11, r0, r4, ror sp
 *   @0x1e1ccc ldrheq r0, [r6], -r0
 *   @0x1e1cd0 eoreq pc, r0, r8, lsr #2
 *   @0x1e1cd4 ldrsbeq r0, [r7], -r12
 *
 * ══ §69/110 CVariableList::DeSerialise(IBuffer*)  0x1f669c  size 272  68 条（0x1f669c..0x1f67ac）
 * @func 0x1f669c 0x1f67ac  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RValue::DeSerialise(IBuffer*)×2 / CVariableList::Clear() / YYGetInt32(RValue const*, int) / CVariableList::DeSerialise(IBuffer*)+0x100 / CVariableList::Alloc(int) / CVariableList::Add(RVariable*) / MemoryManager::Free(void const*) / IBuffer::ReadString()
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0xbc×1 / 0x28×1 / 0x54×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f669c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f66a0 mov r6, r1
 *   @0x1f66a4 sub sp, sp, #28
 *   @0x1f66a8 mov r9, r0
 *   @0x1f66ac bl 0x1f662c <_ZN13CVariableList5ClearEv>
 *   @0x1f66b0 ldr r3, [r6]
 *   @0x1f66b4 add r4, r6, #44
 *   @0x1f66b8 mov r1, #6
 *   @0x1f66bc mov r0, r6
 *   @0x1f66c0 ldr r3, [r3, #0xc]
 *   @0x1f66c4 mov r2, r4
 *   @0x1f66c8 blx r3
 *   @0x1f66cc mov r0, r4
 *   @0x1f66d0 mov r1, #0
 *   @0x1f66d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1f66d8 subs r8, r0, #0
 *   @0x1f66dc ble 0x1f679c <_ZN13CVariableList11DeSerialiseEP7IBuffer+0x100>
 *   @0x1f66e0 ldr r3, [pc, #0xbc]
 *   @0x1f66e4 add r10, sp, #8
 *   @0x1f66e8 mov r4, #0
 *   @0x1f66ec add r3, pc, r3
 *   @0x1f66f0 str r3, [sp, #0x4]
 *   @0x1f66f4 b 0x1f6730 <_ZN13CVariableList11DeSerialiseEP7IBuffer+0x94>
 *   @0x1f66f8 bl 0x1f50cc <_ZN13CVariableList5AllocEi>
 *   @0x1f66fc mov r1, r6
 *   @0x1f6700 str r11, [r0, #0x28]
 *   @0x1f6704 mov r5, r0
 *   @0x1f6708 add r0, r0, #24
 *   @0x1f670c bl 0xcf6e4 <_ZN6RValue11DeSerialiseEP7IBuffer>
 *   @0x1f6710 mov r0, r9
 *   @0x1f6714 mov r1, r5
 *   @0x1f6718 bl 0x1f51e8 <_ZN13CVariableList3AddEP9RVariable>
 *   @0x1f671c add r4, r4, #1
 *   @0x1f6720 mov r0, r7
 *   @0x1f6724 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f6728 cmp r4, r8
 *   @0x1f672c beq 0x1f679c <_ZN13CVariableList11DeSerialiseEP7IBuffer+0x100>
 *   @0x1f6730 mov r0, r6
 *   @0x1f6734 bl 0xcde74 <_ZN7IBuffer10ReadStringEv>
 *   @0x1f6738 mov r7, r0
 *   @0x1f673c bl 0xd1c94 <_Z24Variable_FindNameNoAllocPKc>
 *   @0x1f6740 cmn r0, #1
 *   @0x1f6744 mov r11, r0
 *   @0x1f6748 bne 0x1f66f8 <_ZN13CVariableList11DeSerialiseEP7IBuffer+0x5c>
 *   @0x1f674c ldr r3, [pc, #0x54]
 *   @0x1f6750 mov r2, r7
 *   @0x1f6754 ldr r1, [sp, #0x4]
 *   @0x1f6758 ldr r3, [pc, r3]
 *   @0x1f675c ldr r0, [r3]
 *   @0x1f6760 ldr r3, [r0]
 *   @0x1f6764 ldr r3, [r3, #0xc]
 *   @0x1f6768 blx r3
 *   @0x1f676c mov r0, r10
 *   @0x1f6770 mov r1, r6
 *   @0x1f6774 bl 0xcf6e4 <_ZN6RValue11DeSerialiseEP7IBuffer>
 *   @0x1f6778 ldr r3, [sp, #0x14]
 *   @0x1f677c sub r3, r3, #1
 *   @0x1f6780 bic r3, r3, #-16777216
 *   @0x1f6784 bic r3, r3, #3
 *   @0x1f6788 cmp r3, #0
 *   @0x1f678c bne 0x1f671c <_ZN13CVariableList11DeSerialiseEP7IBuffer+0x80>
 *   @0x1f6790 mov r0, r10
 *   @0x1f6794 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f6798 b 0x1f671c <_ZN13CVariableList11DeSerialiseEP7IBuffer+0x80>
 *   @0x1f679c add sp, sp, #28
 *   @0x1f67a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f67a4 andseq r12, r5, r8, ror #3
 *   @0x1f67a8 ldrheq r6, [pc], -r12
 *
 * ══ §70/110 SV_PhysicsSpeedX(CInstance*, int, RValue*)  0x1fe8dc  size 272  68 条（0x1fe8dc..0x1fe9ec）
 * @func 0x1fe8dc 0x1fe9ec  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)×2 / CheckPhysicsError(CInstance*, bool, bool) / CPhysicsObject::SetLinearVelocity(float, float) / CTimingSource::GetFPS()
 * 字段偏移 top8: 0xb4×2 / 0xd8×1 / 0x84×1 / 0xc×1 / 0x54×1 / 0x44×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fe8dc mov r1, #1
 *   @0x1fe8e0 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1fe8e4 vpush {d8}
 *   @0x1fe8e8 mov r9, r2
 *   @0x1fe8ec mov r2, r1
 *   @0x1fe8f0 mov r5, r0
 *   @0x1fe8f4 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1fe8f8 subs r6, r0, #0
 *   @0x1fe8fc beq 0x1fe980 <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0xa4>
 *   @0x1fe900 ldr r4, [pc, #0xd8]
 *   @0x1fe904 ldr r7, [r5, #0x84]
 *   @0x1fe908 ldr r4, [pc, r4]
 *   @0x1fe90c ldr r2, [r4]
 *   @0x1fe910 ldr r8, [r2, #0xb4]
 *   @0x1fe914 cmp r7, #0
 *   @0x1fe918 cmpne r8, #0
 *   @0x1fe91c moveq r6, #0
 *   @0x1fe920 movne r6, #1
 *   @0x1fe924 beq 0x1fe980 <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0xa4>
 *   @0x1fe928 ldr r3, [pc, #0xb4]
 *   @0x1fe92c ldr r3, [pc, r3]
 *   @0x1fe930 ldrb r3, [r3]
 *   @0x1fe934 cmp r3, #0
 *   @0x1fe938 ldr r3, [r9, #0xc]
 *   @0x1fe93c bic r3, r3, #-16777216
 *   @0x1fe940 bne 0x1fe98c <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0xb0>
 *   @0x1fe944 cmp r3, #0
 *   @0x1fe948 bne 0x1fe9c4 <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0xe8>
 *   @0x1fe94c ldm r9, {r0, r1}
 *   @0x1fe950 vmov d7, r0, r1
 *   @0x1fe954 vldr s13, [r8, #96]
 *   @0x1fe958 vcvt.f32.f64 s12, d7
 *   @0x1fe95c vldr s14, [r2, #12]
 *   @0x1fe960 vmul.f32 s13, s12, s13
 *   @0x1fe964 vcvt.f32.s32 s14, s14
 *   @0x1fe968 vmul.f32 s15, s13, s14
 *   @0x1fe96c ldr r3, [r7]
 *   @0x1fe970 mov r0, r7
 *   @0x1fe974 vmov r1, s15
 *   @0x1fe978 ldr r2, [r3, #0x54]
 *   @0x1fe97c bl 0x236e9c <_ZN14CPhysicsObject17SetLinearVelocityEff>
 *   @0x1fe980 vpop {d8}
 *   @0x1fe984 mov r0, r6
 *   @0x1fe988 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1fe98c cmp r3, #0
 *   @0x1fe990 bne 0x1fe9d4 <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0xf8>
 *   @0x1fe994 ldm r9, {r0, r1}
 *   @0x1fe998 vmov d6, r0, r1
 *   @0x1fe99c ldr r0, [pc, #0x44]
 *   @0x1fe9a0 vldr s15, [r8, #96]
 *   @0x1fe9a4 vcvt.f32.f64 s16, d6
 *   @0x1fe9a8 ldr r0, [pc, r0]
 *   @0x1fe9ac vmul.f32 s16, s16, s15
 *   @0x1fe9b0 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x1fe9b4 vmov d6, r0, r1
 *   @0x1fe9b8 vcvt.f32.f64 s15, d6
 *   @0x1fe9bc vmul.f32 s15, s16, s15
 *   @0x1fe9c0 b 0x1fe96c <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0x90>
 *   @0x1fe9c4 mov r0, r9
 *   @0x1fe9c8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fe9cc ldr r2, [r4]
 *   @0x1fe9d0 b 0x1fe950 <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0x74>
 *   @0x1fe9d4 mov r0, r9
 *   @0x1fe9d8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fe9dc b 0x1fe998 <_Z16SV_PhysicsSpeedXP9CInstanceiP6RValue+0xbc>
 *   @0x1fe9e0 andseq pc, lr, r0, lsr #32
 *   @0x1fe9e4 ldrsheq lr, [lr], -r8
 *   @0x1fe9e8 andseq lr, lr, r4, lsl #31
 *
 * ══ §71/110 SV_PhysicsSpeedY(CInstance*, int, RValue*)  0x1fe9ec  size 272  68 条（0x1fe9ec..0x1feafc）
 * @func 0x1fe9ec 0x1feafc  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: REAL_RValue_Ex(RValue const*)×2 / CheckPhysicsError(CInstance*, bool, bool) / CPhysicsObject::SetLinearVelocity(float, float) / CTimingSource::GetFPS()
 * 字段偏移 top8: 0xb4×2 / 0xd8×1 / 0x84×1 / 0xc×1 / 0x50×1 / 0x44×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fe9ec mov r1, #1
 *   @0x1fe9f0 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1fe9f4 vpush {d8}
 *   @0x1fe9f8 mov r9, r2
 *   @0x1fe9fc mov r2, r1
 *   @0x1fea00 mov r5, r0
 *   @0x1fea04 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1fea08 subs r6, r0, #0
 *   @0x1fea0c beq 0x1fea90 <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0xa4>
 *   @0x1fea10 ldr r4, [pc, #0xd8]
 *   @0x1fea14 ldr r7, [r5, #0x84]
 *   @0x1fea18 ldr r4, [pc, r4]
 *   @0x1fea1c ldr r2, [r4]
 *   @0x1fea20 ldr r8, [r2, #0xb4]
 *   @0x1fea24 cmp r7, #0
 *   @0x1fea28 cmpne r8, #0
 *   @0x1fea2c moveq r6, #0
 *   @0x1fea30 movne r6, #1
 *   @0x1fea34 beq 0x1fea90 <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0xa4>
 *   @0x1fea38 ldr r3, [pc, #0xb4]
 *   @0x1fea3c ldr r3, [pc, r3]
 *   @0x1fea40 ldrb r3, [r3]
 *   @0x1fea44 cmp r3, #0
 *   @0x1fea48 ldr r3, [r9, #0xc]
 *   @0x1fea4c bic r3, r3, #-16777216
 *   @0x1fea50 bne 0x1fea9c <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0xb0>
 *   @0x1fea54 cmp r3, #0
 *   @0x1fea58 bne 0x1fead4 <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0xe8>
 *   @0x1fea5c ldm r9, {r0, r1}
 *   @0x1fea60 vmov d7, r0, r1
 *   @0x1fea64 vldr s13, [r8, #96]
 *   @0x1fea68 vcvt.f32.f64 s12, d7
 *   @0x1fea6c vldr s14, [r2, #12]
 *   @0x1fea70 vmul.f32 s13, s12, s13
 *   @0x1fea74 vcvt.f32.s32 s14, s14
 *   @0x1fea78 vmul.f32 s15, s13, s14
 *   @0x1fea7c ldr r3, [r7]
 *   @0x1fea80 mov r0, r7
 *   @0x1fea84 vmov r2, s15
 *   @0x1fea88 ldr r1, [r3, #0x50]
 *   @0x1fea8c bl 0x236e9c <_ZN14CPhysicsObject17SetLinearVelocityEff>
 *   @0x1fea90 vpop {d8}
 *   @0x1fea94 mov r0, r6
 *   @0x1fea98 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1fea9c cmp r3, #0
 *   @0x1feaa0 bne 0x1feae4 <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0xf8>
 *   @0x1feaa4 ldm r9, {r0, r1}
 *   @0x1feaa8 vmov d6, r0, r1
 *   @0x1feaac ldr r0, [pc, #0x44]
 *   @0x1feab0 vldr s15, [r8, #96]
 *   @0x1feab4 vcvt.f32.f64 s16, d6
 *   @0x1feab8 ldr r0, [pc, r0]
 *   @0x1feabc vmul.f32 s16, s16, s15
 *   @0x1feac0 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x1feac4 vmov d6, r0, r1
 *   @0x1feac8 vcvt.f32.f64 s15, d6
 *   @0x1feacc vmul.f32 s15, s16, s15
 *   @0x1fead0 b 0x1fea7c <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0x90>
 *   @0x1fead4 mov r0, r9
 *   @0x1fead8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1feadc ldr r2, [r4]
 *   @0x1feae0 b 0x1fea60 <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0x74>
 *   @0x1feae4 mov r0, r9
 *   @0x1feae8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1feaec b 0x1feaa8 <_Z16SV_PhysicsSpeedYP9CInstanceiP6RValue+0xbc>
 *   @0x1feaf0 andseq lr, lr, r0, lsl pc
 *   @0x1feaf4 andseq lr, lr, r8, ror #29
 *   @0x1feaf8 andseq lr, lr, r4, ror lr
 *
 * ══ §72/110 CDS_Map::WriteToString(char const*&)  0x203948  size 272  68 条（0x203948..0x203a58）
 * @func 0x203948 0x203a58  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::WriteInteger(int)×2 / WriteValue(CStream&, RValue&)×2 / operator new(unsigned int) / CStream::CStream(int) / CStream::ConvertToString(char const*&) / CStream::~CStream()
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x3×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203948 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x20394c mov r4, r0
 *   @0x203950 mov r0, #32
 *   @0x203954 mov r8, r1
 *   @0x203958 bl 0x27c524 <_Znwj>
 *   @0x20395c mov r1, #0
 *   @0x203960 mov r5, r1
 *   @0x203964 mov r7, r0
 *   @0x203968 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x20396c mov r0, r7
 *   @0x203970 movw r1, #0x192
 *   @0x203974 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x203978 ldr r3, [r4]
 *   @0x20397c mov r0, r7
 *   @0x203980 ldr r1, [r3, #0x8]
 *   @0x203984 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x203988 ldr r9, [r4]
 *   @0x20398c ldr r2, [r9]
 *   @0x203990 b 0x2039a4 <_ZN7CDS_Map13WriteToStringERPKc+0x5c>
 *   @0x203994 ldr r3, [r9, #0x4]
 *   @0x203998 add r5, r5, #1
 *   @0x20399c cmp r5, r3
 *   @0x2039a0 bgt 0x203a50 <_ZN7CDS_Map13WriteToStringERPKc+0x108>
 *   @0x2039a4 ldr r4, [r2, r5, lsl #3]
 *   @0x2039a8 cmp r4, #0
 *   @0x2039ac beq 0x203994 <_ZN7CDS_Map13WriteToStringERPKc+0x4c>
 *   @0x2039b0 cmp r4, #0
 *   @0x2039b4 beq 0x203a28 <_ZN7CDS_Map13WriteToStringERPKc+0xe0>
 *   @0x2039b8 ldr r6, [r4, #0xc]
 *   @0x2039bc cmp r6, #0
 *   @0x2039c0 beq 0x203a28 <_ZN7CDS_Map13WriteToStringERPKc+0xe0>
 *   @0x2039c4 mov r0, r7
 *   @0x2039c8 mov r1, r6
 *   @0x2039cc bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue>
 *   @0x2039d0 mov r0, r7
 *   @0x2039d4 add r1, r6, #16
 *   @0x2039d8 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue>
 *   @0x2039dc ldr r4, [r4, #0x4]
 *   @0x2039e0 cmp r4, #0
 *   @0x2039e4 bne 0x2039b0 <_ZN7CDS_Map13WriteToStringERPKc+0x68>
 *   @0x2039e8 ldr r12, [r9, #0x4]
 *   @0x2039ec add r3, r5, #1
 *   @0x2039f0 cmp r3, r12
 *   @0x2039f4 bgt 0x203a28 <_ZN7CDS_Map13WriteToStringERPKc+0xe0>
 *   @0x2039f8 ldr r2, [r9]
 *   @0x2039fc add r2, r2, r5, lsl #3
 *   @0x203a00 b 0x203a0c <_ZN7CDS_Map13WriteToStringERPKc+0xc4>
 *   @0x203a04 cmp r3, r12
 *   @0x203a08 bgt 0x203a28 <_ZN7CDS_Map13WriteToStringERPKc+0xe0>
 *   @0x203a0c ldr r4, [r2, #0x8]
 *   @0x203a10 mov r5, r3
 *   @0x203a14 add r2, r2, #8
 *   @0x203a18 add r3, r3, #1
 *   @0x203a1c cmp r4, #0
 *   @0x203a20 beq 0x203a04 <_ZN7CDS_Map13WriteToStringERPKc+0xbc>
 *   @0x203a24 b 0x2039b0 <_ZN7CDS_Map13WriteToStringERPKc+0x68>
 *   @0x203a28 mov r1, r8
 *   @0x203a2c mov r0, r7
 *   @0x203a30 bl 0x2024b0 <_ZN7CStream15ConvertToStringERPKc>
 *   @0x203a34 cmp r7, #0
 *   @0x203a38 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x203a3c mov r0, r7
 *   @0x203a40 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x203a44 mov r0, r7
 *   @0x203a48 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x203a4c b 0x27d1d0 <_ZdlPv>
 *   @0x203a50 mvn r5, #0
 *   @0x203a54 b 0x2039b0 <_ZN7CDS_Map13WriteToStringERPKc+0x68>
 *
 * ══ §73/110 CDS_Grid::Value_Exists(RValue&, int, int, int, int, RValue*)  0x20478c  size 272  68 条（0x20478c..0x20489c）
 * @func 0x20478c 0x20489c  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCompareVal(RValue const&, RValue const&, double) / CDS_Grid::Value_Exists(RValue&, int, int, int, int, RValue*)+0xa4
 * 字段偏移 top8: 0x4×4 / 0x2c×2 / 0x28×1 / 0xc×1 / 0x30×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20478c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x204790 mov r8, r1
 *   @0x204794 ldr r12, [sp, #0x28]
 *   @0x204798 mov r5, r0
 *   @0x20479c mov r0, #0
 *   @0x2047a0 str r0, [r8]
 *   @0x2047a4 cmp r2, r12
 *   @0x2047a8 str r0, [r8, #0x4]
 *   @0x2047ac str r0, [r8, #0xc]
 *   @0x2047b0 lsrlt r0, r2, #31
 *   @0x2047b4 lsrge r0, r12, #31
 *   @0x2047b8 ldr r1, [sp, #0x2c]
 *   @0x2047bc cmp r2, r12
 *   @0x2047c0 movlt r6, r2
 *   @0x2047c4 movge r6, r12
 *   @0x2047c8 cmp r0, #0
 *   @0x2047cc ldr r7, [sp, #0x30]
 *   @0x2047d0 movne r6, #0
 *   @0x2047d4 cmp r3, r1
 *   @0x2047d8 movlt r0, r3
 *   @0x2047dc movge r0, r1
 *   @0x2047e0 cmp r3, r1
 *   @0x2047e4 lsrlt r10, r3, #31
 *   @0x2047e8 lsrge r10, r1, #31
 *   @0x2047ec cmp r2, r12
 *   @0x2047f0 movge r9, r2
 *   @0x2047f4 movlt r9, r12
 *   @0x2047f8 cmp r10, #0
 *   @0x2047fc ldr r2, [r5, #0x4]
 *   @0x204800 moveq r10, r0
 *   @0x204804 movne r10, #0
 *   @0x204808 cmp r3, r1
 *   @0x20480c movge r11, r3
 *   @0x204810 movlt r11, r1
 *   @0x204814 cmp r9, r2
 *   @0x204818 subge r3, r2, #1
 *   @0x20481c movlt r3, r9
 *   @0x204820 cmp r6, r3
 *   @0x204824 bgt 0x204880 <_ZN8CDS_Grid12Value_ExistsER6RValueiiiiPS0_+0xf4>
 *   @0x204828 mov r4, r10
 *   @0x20482c b 0x204850 <_ZN8CDS_Grid12Value_ExistsER6RValueiiiiPS0_+0xc4>
 *   @0x204830 ldr r12, [pc, r12]
 *   @0x204834 ldr lr, [r5]
 *   @0x204838 ldrd r2, r3, [r12]
 *   @0x20483c add r0, lr, r0, lsl #4
 *   @0x204840 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x204844 cmp r0, #0
 *   @0x204848 beq 0x204884 <_ZN8CDS_Grid12Value_ExistsER6RValueiiiiPS0_+0xf8>
 *   @0x20484c ldr r2, [r5, #0x4]
 *   @0x204850 ldr r1, [r5, #0x8]
 *   @0x204854 mov r3, r11
 *   @0x204858 mla r0, r2, r4, r6
 *   @0x20485c cmp r1, r11
 *   @0x204860 suble r3, r1, #1
 *   @0x204864 ldr r12, [pc, #0x2c]
 *   @0x204868 cmp r4, r3
 *   @0x20486c mov r1, r7
 *   @0x204870 add r4, r4, #1
 *   @0x204874 ble 0x204830 <_ZN8CDS_Grid12Value_ExistsER6RValueiiiiPS0_+0xa4>
 *   @0x204878 add r6, r6, #1
 *   @0x20487c b 0x204814 <_ZN8CDS_Grid12Value_ExistsER6RValueiiiiPS0_+0x88>
 *   @0x204880 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x204884 mov r3, #0
 *   @0x204888 str r0, [r8]
 *   @0x20488c movt r3, #0x3ff0
 *   @0x204890 str r3, [r8, #0x4]
 *   @0x204894 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x204898 andseq r12, lr, r4, asr r11
 *
 * ══ §74/110 CDS_Grid::SetSize(int, int)  0x20affc  size 272  68 条（0x20affc..0x20b10c）
 * @func 0x20affc 0x20b10c  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Grid::SetSize(int, int)+0x84 / FREE_RValue__Pre(RValue*) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / CDS_Grid::SetSize(int, int)+0xe8 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×3 / 0xc×3 / 0x68×1 / 0x-10×1 / 0x-c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20affc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20b000 mov r9, r0
 *   @0x20b004 ldr r0, [r0]
 *   @0x20b008 sub sp, sp, #12
 *   @0x20b00c ldmib r9, {r3, r10}
 *   @0x20b010 mov r8, r1
 *   @0x20b014 cmp r0, #0
 *   @0x20b018 mov r7, r2
 *   @0x20b01c mul r10, r10, r3
 *   @0x20b020 beq 0x20b080 <_ZN8CDS_Grid7SetSizeEii+0x84>
 *   @0x20b024 cmp r10, #0
 *   @0x20b028 ble 0x20b080 <_ZN8CDS_Grid7SetSizeEii+0x84>
 *   @0x20b02c mov r5, #0
 *   @0x20b030 mov r11, #5
 *   @0x20b034 mov r6, r5
 *   @0x20b038 b 0x20b050 <_ZN8CDS_Grid7SetSizeEii+0x54>
 *   @0x20b03c cmp r5, r10
 *   @0x20b040 str r6, [r4, #0x8]
 *   @0x20b044 str r11, [r4, #0xc]
 *   @0x20b048 str r6, [r4]
 *   @0x20b04c beq 0x20b080 <_ZN8CDS_Grid7SetSizeEii+0x84>
 *   @0x20b050 add r4, r0, r5, lsl #4
 *   @0x20b054 add r5, r5, #1
 *   @0x20b058 ldr r3, [r4, #0xc]
 *   @0x20b05c sub r3, r3, #1
 *   @0x20b060 bic r3, r3, #-16777216
 *   @0x20b064 bic r3, r3, #3
 *   @0x20b068 cmp r3, #0
 *   @0x20b06c bne 0x20b03c <_ZN8CDS_Grid7SetSizeEii+0x40>
 *   @0x20b070 mov r0, r4
 *   @0x20b074 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20b078 ldr r0, [r9]
 *   @0x20b07c b 0x20b03c <_ZN8CDS_Grid7SetSizeEii+0x40>
 *   @0x20b080 cmp r7, #0
 *   @0x20b084 cmpne r8, #0
 *   @0x20b088 movne r4, #0
 *   @0x20b08c moveq r4, #1
 *   @0x20b090 beq 0x20b0ec <_ZN8CDS_Grid7SetSizeEii+0xf0>
 *   @0x20b094 mul r5, r7, r8
 *   @0x20b098 ldr r2, [pc, #0x68]
 *   @0x20b09c str r4, [sp]
 *   @0x20b0a0 mov r3, #74
 *   @0x20b0a4 add r2, pc, r2
 *   @0x20b0a8 lsl r6, r5, #4
 *   @0x20b0ac mov r1, r6
 *   @0x20b0b0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x20b0b4 cmp r5, #0
 *   @0x20b0b8 str r7, [r9, #0x8]
 *   @0x20b0bc stm r9, {r0, r8}
 *   @0x20b0c0 ble 0x20b0e4 <_ZN8CDS_Grid7SetSizeEii+0xe8>
 *   @0x20b0c4 add r1, r0, r6
 *   @0x20b0c8 mov r3, r4
 *   @0x20b0cc str r3, [r0, #0xc]
 *   @0x20b0d0 add r0, r0, #16
 *   @0x20b0d4 str r3, [r0, #-0x10]
 *   @0x20b0d8 str r3, [r0, #-0xc]
 *   @0x20b0dc cmp r0, r1
 *   @0x20b0e0 bne 0x20b0cc <_ZN8CDS_Grid7SetSizeEii+0xd0>
 *   @0x20b0e4 add sp, sp, #12
 *   @0x20b0e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20b0ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x20b0f0 mov r3, #0
 *   @0x20b0f4 str r8, [r9, #0x4]
 *   @0x20b0f8 str r7, [r9, #0x8]
 *   @0x20b0fc str r3, [r9]
 *   @0x20b100 add sp, sp, #12
 *   @0x20b104 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20b108 andseq r5, r2, r12, lsl #31
 *
 * ══ §75/110 CDS_List::ReadFromString(char const*, bool)  0x20e968  size 272  68 条（0x20e968..0x20ea78）
 * @func 0x20e968 0x20ea78  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×2 / CStream::~CStream()×2 / operator delete(void*)×2 / operator new(unsigned int) / CStream::CStream(int) / CStream::ConvertFromString(char const*) / CDS_List::ReadFromString(char const*, bool)+0x64 / CDS_List::Clear()
 * 字段偏移 top8: 0x4×3 / 0x84×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20e968 push {r3, r4, r5, r6, r7, lr}
 *   @0x20e96c mov r6, r0
 *   @0x20e970 mov r0, #32
 *   @0x20e974 mov r7, r2
 *   @0x20e978 mov r4, r1
 *   @0x20e97c bl 0x27c524 <_Znwj>
 *   @0x20e980 mov r1, #0
 *   @0x20e984 mov r5, r0
 *   @0x20e988 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x20e98c mov r0, r5
 *   @0x20e990 mov r1, r4
 *   @0x20e994 bl 0x2025b0 <_ZN7CStream17ConvertFromStringEPKc>
 *   @0x20e998 mov r0, r5
 *   @0x20e99c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20e9a0 sub r3, r0, #300
 *   @0x20e9a4 sub r3, r3, #1
 *   @0x20e9a8 cmp r3, #1
 *   @0x20e9ac bls 0x20e9cc <_ZN8CDS_List14ReadFromStringEPKcb+0x64>
 *   @0x20e9b0 subs r0, r5, #0
 *   @0x20e9b4 beq 0x20ea5c <_ZN8CDS_List14ReadFromStringEPKcb+0xf4>
 *   @0x20e9b8 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x20e9bc mov r0, r5
 *   @0x20e9c0 bl 0x27d1d0 <_ZdlPv>
 *   @0x20e9c4 mov r0, #0
 *   @0x20e9c8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x20e9cc cmp r7, #0
 *   @0x20e9d0 movne r7, #1
 *   @0x20e9d4 beq 0x20ea60 <_ZN8CDS_List14ReadFromStringEPKcb+0xf8>
 *   @0x20e9d8 mov r0, r6
 *   @0x20e9dc bl 0x20e478 <_ZN8CDS_List5ClearEv>
 *   @0x20e9e0 mov r0, r5
 *   @0x20e9e4 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20e9e8 ldr r2, [pc, #0x84]
 *   @0x20e9ec movw r3, #0x48f
 *   @0x20e9f0 add r2, pc, r2
 *   @0x20e9f4 lsl r1, r0, #4
 *   @0x20e9f8 str r0, [r6, #0x4]
 *   @0x20e9fc add r0, r6, #12
 *   @0x20ea00 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x20ea04 ldr r3, [r6, #0x4]
 *   @0x20ea08 cmp r3, #0
 *   @0x20ea0c str r3, [r6, #0x8]
 *   @0x20ea10 movgt r4, #0
 *   @0x20ea14 ble 0x20ea3c <_ZN8CDS_List14ReadFromStringEPKcb+0xd4>
 *   @0x20ea18 ldr r0, [r6, #0xc]
 *   @0x20ea1c mov r1, r5
 *   @0x20ea20 mov r2, r7
 *   @0x20ea24 add r0, r0, r4, lsl #4
 *   @0x20ea28 add r4, r4, #1
 *   @0x20ea2c bl 0x208638 <_Z9ReadValueR6RValueR7CStreami>
 *   @0x20ea30 ldr r3, [r6, #0x4]
 *   @0x20ea34 cmp r3, r4
 *   @0x20ea38 bgt 0x20ea18 <_ZN8CDS_List14ReadFromStringEPKcb+0xb0>
 *   @0x20ea3c cmp r5, #0
 *   @0x20ea40 beq 0x20ea54 <_ZN8CDS_List14ReadFromStringEPKcb+0xec>
 *   @0x20ea44 mov r0, r5
 *   @0x20ea48 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x20ea4c mov r0, r5
 *   @0x20ea50 bl 0x27d1d0 <_ZdlPv>
 *   @0x20ea54 mov r0, #1
 *   @0x20ea58 pop {r3, r4, r5, r6, r7, pc}
 *   @0x20ea5c pop {r3, r4, r5, r6, r7, pc}
 *   @0x20ea60 movw r7, #0x12d
 *   @0x20ea64 cmp r0, r7
 *   @0x20ea68 moveq r7, #2
 *   @0x20ea6c movne r7, #0
 *   @0x20ea70 b 0x20e9d8 <_ZN8CDS_List14ReadFromStringEPKcb+0x70>
 *   @0x20ea74 ldrsheq r4, [r4], -r12
 *
 * ══ §76/110 iffLogAddName(char const*, int*)  0x27d8c8  size 272  68 条（0x27d8c8..0x27d9d8）
 * @func 0x27d8c8 0x27d9d8  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: unsigned int CHashMapCalculateHash<char const*>(char const*) / iffLogAddName(char const*, int*)+0xac / CHashMap<char const*, int, 3>::Insert(char const*, int)
 * 字段偏移 top8: 0x8×3 / 0xf0×1 / 0x10×1 / 0x58×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d8c8 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x27d8cc mov r7, r1
 *   @0x27d8d0 mov r8, r0
 *   @0x27d8d4 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x27d8d8 ldr r10, [pc, #0xf0]
 *   @0x27d8dc ldr r10, [pc, r10]
 *   @0x27d8e0 ldr r12, [r10, #0x8]
 *   @0x27d8e4 ldr r9, [r10, #0x10]
 *   @0x27d8e8 bic r0, r0, #-2147483648
 *   @0x27d8ec and r3, r0, r12
 *   @0x27d8f0 lsl r5, r3, #1
 *   @0x27d8f4 add r2, r5, r3
 *   @0x27d8f8 add r2, r9, r2, lsl #2
 *   @0x27d8fc ldr r2, [r2, #0x8]
 *   @0x27d900 cmp r2, #0
 *   @0x27d904 beq 0x27d974 <_Z13iffLogAddNamePKcPi+0xac>
 *   @0x27d908 cmp r0, r2
 *   @0x27d90c beq 0x27d9b0 <_Z13iffLogAddNamePKcPi+0xe8>
 *   @0x27d910 ldr r11, [r10]
 *   @0x27d914 and r2, r12, r2
 *   @0x27d918 add r1, r3, r11
 *   @0x27d91c rsb r2, r2, r1
 *   @0x27d920 tst r2, r12
 *   @0x27d924 bmi 0x27d974 <_Z13iffLogAddNamePKcPi+0xac>
 *   @0x27d928 mov r4, #0
 *   @0x27d92c b 0x27d940 <_Z13iffLogAddNamePKcPi+0x78>
 *   @0x27d930 cmp r0, r2
 *   @0x27d934 beq 0x27d9a8 <_Z13iffLogAddNamePKcPi+0xe0>
 *   @0x27d938 cmp r6, r4
 *   @0x27d93c blt 0x27d974 <_Z13iffLogAddNamePKcPi+0xac>
 *   @0x27d940 add r3, r3, #1
 *   @0x27d944 add r4, r4, #1
 *   @0x27d948 and r3, r3, r12
 *   @0x27d94c add r6, r3, r11
 *   @0x27d950 lsl r5, r3, #1
 *   @0x27d954 add r2, r5, r3
 *   @0x27d958 add r2, r9, r2, lsl #2
 *   @0x27d95c ldr r2, [r2, #0x8]
 *   @0x27d960 and r1, r12, r2
 *   @0x27d964 cmp r2, #0
 *   @0x27d968 rsb r6, r1, r6
 *   @0x27d96c and r6, r6, r12
 *   @0x27d970 bne 0x27d930 <_Z13iffLogAddNamePKcPi+0x68>
 *   @0x27d974 ldr r4, [pc, #0x58]
 *   @0x27d978 mov r0, r10
 *   @0x27d97c mov r1, r8
 *   @0x27d980 ldr r4, [pc, r4]
 *   @0x27d984 ldr r5, [r4]
 *   @0x27d988 mov r2, r5
 *   @0x27d98c bl 0x27d260 <_ZN8CHashMapIPKciLi3EE6InsertES1_i>
 *   @0x27d990 ldr r3, [r4]
 *   @0x27d994 mov r0, #1
 *   @0x27d998 add r3, r3, r0
 *   @0x27d99c str r3, [r4]
 *   @0x27d9a0 str r5, [r7]
 *   @0x27d9a4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27d9a8 cmn r3, #1
 *   @0x27d9ac beq 0x27d974 <_Z13iffLogAddNamePKcPi+0xac>
 *   @0x27d9b0 add r3, r5, r3
 *   @0x27d9b4 add r9, r9, r3, lsl #2
 *   @0x27d9b8 cmn r9, #4
 *   @0x27d9bc beq 0x27d974 <_Z13iffLogAddNamePKcPi+0xac>
 *   @0x27d9c0 ldr r3, [r9, #0x4]
 *   @0x27d9c4 mov r0, #0
 *   @0x27d9c8 str r3, [r7]
 *   @0x27d9cc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27d9d0 andseq r3, r7, r4, asr #30
 *   @0x27d9d4 andseq r3, r7, r0, ror #29
 *
 * ══ §77/110 Debug_ReadCommand(eNetworkCommand, Buffer_Standard*, Buffer_Standard*)  0x29e11c  size 272  68 条（0x29e11c..0x29e22c）
 * @func 0x29e11c 0x29e22c  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x1c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29e11c push {r3, lr}
 *   @0x29e120 sub r3, r0, #1
 *   @0x29e124 cmp r3, #17
 *   @0x29e128 addls pc, pc, r3, lsl #2
 *   @0x29e12c b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0>
 *   @0x29e130 b 0x29e184 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0x68>
 *   @0x29e134 b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0>
 *   @0x29e138 b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0>
 *   @0x29e13c b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0>
 *   @0x29e140 b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0>
 *   @0x29e144 b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0>
 *   @0x29e148 b 0x29e190 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0x74>
 *   @0x29e14c b 0x29e19c <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0x80>
 *   @0x29e150 b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0>
 *   @0x29e154 b 0x29e1a8 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0x8c>
 *   @0x29e158 b 0x29e1b4 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0x98>
 *   @0x29e15c b 0x29e1c0 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xa4>
 *   @0x29e160 b 0x29e1cc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xb0>
 *   @0x29e164 b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0>
 *   @0x29e168 b 0x29e1d8 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xbc>
 *   @0x29e16c b 0x29e1e4 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xc8>
 *   @0x29e170 b 0x29e1f0 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xd4>
 *   @0x29e174 b 0x29e178 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0x5c>
 *   @0x29e178 mov r0, r2
 *   @0x29e17c pop {r3, lr}
 *   @0x29e180 b 0x29ad38 <_Z17Debug_GetTexturesP15Buffer_StandardS0_>
 *   @0x29e184 mov r0, r2
 *   @0x29e188 pop {r3, lr}
 *   @0x29e18c b 0x29d078 <_Z13Debug_GetPingP15Buffer_StandardS0_>
 *   @0x29e190 mov r0, r2
 *   @0x29e194 pop {r3, lr}
 *   @0x29e198 b 0x29ab8c <_Z18Debug_GetInstancesP15Buffer_StandardS0_>
 *   @0x29e19c mov r0, r2
 *   @0x29e1a0 pop {r3, lr}
 *   @0x29e1a4 b 0x29aa44 <_Z20Debug_GetJSInstancesP15Buffer_StandardS0_>
 *   @0x29e1a8 mov r0, r2
 *   @0x29e1ac pop {r3, lr}
 *   @0x29e1b0 b 0x29dafc <_Z16Debug_GetWatchesP15Buffer_StandardS0_>
 *   @0x29e1b4 mov r0, r2
 *   @0x29e1b8 pop {r3, lr}
 *   @0x29e1bc b 0x29d4d4 <_Z15Debug_GetUpdateP15Buffer_StandardS0_>
 *   @0x29e1c0 mov r0, r2
 *   @0x29e1c4 pop {r3, lr}
 *   @0x29e1c8 b 0x29b3c0 <_Z15Debug_GetArraysP15Buffer_StandardS0_>
 *   @0x29e1cc mov r0, r2
 *   @0x29e1d0 pop {r3, lr}
 *   @0x29e1d4 b 0x29bd84 <_Z19Debug_GetStructuresP15Buffer_StandardS0_>
 *   @0x29e1d8 mov r0, r2
 *   @0x29e1dc pop {r3, lr}
 *   @0x29e1e0 b 0x29c608 <_Z25Debug_GetSelectedInstanceP15Buffer_StandardS0_>
 *   @0x29e1e4 mov r0, r2
 *   @0x29e1e8 pop {r3, lr}
 *   @0x29e1ec b 0x29b098 <_Z16Debug_GetBuffersP15Buffer_StandardS0_>
 *   @0x29e1f0 mov r0, r2
 *   @0x29e1f4 pop {r3, lr}
 *   @0x29e1f8 b 0x29bb78 <_Z19Debug_PokeStructureP15Buffer_StandardS0_>
 *   @0x29e1fc ldr r3, [pc, #0x20]
 *   @0x29e200 mov r2, r0
 *   @0x29e204 ldr r1, [pc, #0x1c]
 *   @0x29e208 ldr r3, [pc, r3]
 *   @0x29e20c add r1, pc, r1
 *   @0x29e210 ldr r0, [r3]
 *   @0x29e214 ldr r3, [r0]
 *   @0x29e218 ldr r3, [r3, #0xc]
 *   @0x29e21c blx r3
 *   @0x29e220 pop {r3, pc}
 *   @0x29e224 andseq pc, r4, r12, lsl #10
 *   @0x29e228 andeq r11, r11, r0, ror #18
 *
 * ══ §78/110 b2Contact::InitializeRegisters()  0x2cbeac  size 272  68 条（0x2cbeac..0x2cbfbc）
 * @func 0x2cbeac 0x2cbfbc  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Contact::AddType(b2Contact* (*)(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*), void (*)(b2Contact*, b2BlockAllocator*), b2Shape::Type, b2Shape::Type)×6
 * 字段偏移 top8: 0xc0×2 / 0xb0×2 / 0x9c×2 / 0x88×2 / 0x74×2 / 0x60×2 / 0x4c×2 / 0xc4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cbeac push {r4, lr}
 *   @0x2cbeb0 mov r2, #0
 *   @0x2cbeb4 ldr r4, [pc, #0xc4]
 *   @0x2cbeb8 mov r3, r2
 *   @0x2cbebc ldr r0, [pc, #0xc0]
 *   @0x2cbec0 ldr r1, [pc, #0xc0]
 *   @0x2cbec4 add r4, pc, r4
 *   @0x2cbec8 ldr r0, [r4, r0]
 *   @0x2cbecc ldr r1, [r4, r1]
 *   @0x2cbed0 bl 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_>
 *   @0x2cbed4 ldr r0, [pc, #0xb0]
 *   @0x2cbed8 ldr r1, [pc, #0xb0]
 *   @0x2cbedc mov r2, #2
 *   @0x2cbee0 mov r3, #0
 *   @0x2cbee4 ldr r0, [r4, r0]
 *   @0x2cbee8 ldr r1, [r4, r1]
 *   @0x2cbeec bl 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_>
 *   @0x2cbef0 ldr r0, [pc, #0x9c]
 *   @0x2cbef4 ldr r1, [pc, #0x9c]
 *   @0x2cbef8 mov r2, #2
 *   @0x2cbefc mov r3, r2
 *   @0x2cbf00 ldr r0, [r4, r0]
 *   @0x2cbf04 ldr r1, [r4, r1]
 *   @0x2cbf08 bl 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_>
 *   @0x2cbf0c ldr r0, [pc, #0x88]
 *   @0x2cbf10 ldr r1, [pc, #0x88]
 *   @0x2cbf14 mov r2, #1
 *   @0x2cbf18 mov r3, #0
 *   @0x2cbf1c ldr r0, [r4, r0]
 *   @0x2cbf20 ldr r1, [r4, r1]
 *   @0x2cbf24 bl 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_>
 *   @0x2cbf28 ldr r0, [pc, #0x74]
 *   @0x2cbf2c ldr r1, [pc, #0x74]
 *   @0x2cbf30 mov r2, #1
 *   @0x2cbf34 mov r3, #2
 *   @0x2cbf38 ldr r0, [r4, r0]
 *   @0x2cbf3c ldr r1, [r4, r1]
 *   @0x2cbf40 bl 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_>
 *   @0x2cbf44 ldr r0, [pc, #0x60]
 *   @0x2cbf48 ldr r1, [pc, #0x60]
 *   @0x2cbf4c mov r2, #3
 *   @0x2cbf50 mov r3, #0
 *   @0x2cbf54 ldr r0, [r4, r0]
 *   @0x2cbf58 ldr r1, [r4, r1]
 *   @0x2cbf5c bl 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_>
 *   @0x2cbf60 ldr r0, [pc, #0x4c]
 *   @0x2cbf64 ldr r1, [pc, #0x4c]
 *   @0x2cbf68 mov r2, #3
 *   @0x2cbf6c mov r3, #2
 *   @0x2cbf70 ldr r0, [r4, r0]
 *   @0x2cbf74 ldr r1, [r4, r1]
 *   @0x2cbf78 pop {r4, lr}
 *   @0x2cbf7c b 0x2cbe4c <_ZN9b2Contact7AddTypeEPFPS_P9b2FixtureiS2_iP16b2BlockAllocatorEPFvS0_S4_EN7b2Shape4TypeESA_>
 *   @0x2cbf80 andseq r5, r2, r12, lsl #27
 *   @0x2cbf84 .word 0xfffffeb8
 *   @0x2cbf88 .word 0xfffffebc
 *   @0x2cbf8c .word 0xfffffec0
 *   @0x2cbf90 .word 0xfffffec4
 *   @0x2cbf94 .word 0xfffffec8
 *   @0x2cbf98 .word 0xfffffecc
 *   @0x2cbf9c .word 0xfffffed0
 *   @0x2cbfa0 .word 0xfffffed4
 *   @0x2cbfa4 .word 0xfffffed8
 *   @0x2cbfa8 .word 0xfffffedc
 *   @0x2cbfac .word 0xfffffee0
 *   @0x2cbfb0 .word 0xfffffee4
 *   @0x2cbfb4 .word 0xfffffee8
 *   @0x2cbfb8 .word 0xfffffeec
 *
 * ══ §79/110 INT64_RValue(RValue const*)  0xd10a4  size 268  67 条（0xd10a4..0xd11b0）
 * @func 0xd10a4 0xd11b0  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYError(char const*, ...)×2 / __fixdfdi / ARRAY_LVAL_RValue(YYRValue*, int)
 * 字段偏移 top8: 0xc×1 / 0x38×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd10a4 push {r3, lr}
 *   @0xd10a8 ldr r1, [r0, #0xc]
 *   @0xd10ac bic r1, r1, #-16777216
 *   @0xd10b0 cmp r1, #13
 *   @0xd10b4 addls pc, pc, r1, lsl #2
 *   @0xd10b8 b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8>
 *   @0xd10bc b 0xd112c <_Z12INT64_RValuePK6RValue+0x88>
 *   @0xd10c0 b 0xd1108 <_Z12INT64_RValuePK6RValue+0x64>
 *   @0xd10c4 b 0xd1148 <_Z12INT64_RValuePK6RValue+0xa4>
 *   @0xd10c8 b 0xd10f4 <_Z12INT64_RValuePK6RValue+0x50>
 *   @0xd10cc b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8>
 *   @0xd10d0 b 0xd1120 <_Z12INT64_RValuePK6RValue+0x7c>
 *   @0xd10d4 b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8>
 *   @0xd10d8 b 0xd10f4 <_Z12INT64_RValuePK6RValue+0x50>
 *   @0xd10dc b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8>
 *   @0xd10e0 b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8>
 *   @0xd10e4 b 0xd1154 <_Z12INT64_RValuePK6RValue+0xb0>
 *   @0xd10e8 b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8>
 *   @0xd10ec b 0xd115c <_Z12INT64_RValuePK6RValue+0xb8>
 *   @0xd10f0 b 0xd112c <_Z12INT64_RValuePK6RValue+0x88>
 *   @0xd10f4 ldr r2, [r0]
 *   @0xd10f8 asr r3, r2, #31
 *   @0xd10fc mov r0, r2
 *   @0xd1100 mov r1, r3
 *   @0xd1104 pop {r3, pc}
 *   @0xd1108 ldr r3, [r0]
 *   @0xd110c cmp r3, #0
 *   @0xd1110 beq 0xd1120 <_Z12INT64_RValuePK6RValue+0x7c>
 *   @0xd1114 ldr r0, [r3]
 *   @0xd1118 cmp r0, #0
 *   @0xd111c bne 0xd1180 <_Z12INT64_RValuePK6RValue+0xdc>
 *   @0xd1120 mov r2, #0
 *   @0xd1124 mov r3, #0
 *   @0xd1128 b 0xd10fc <_Z12INT64_RValuePK6RValue+0x58>
 *   @0xd112c ldm r0, {r2, r3}
 *   @0xd1130 mov r0, r2
 *   @0xd1134 mov r1, r3
 *   @0xd1138 bl 0x3194a0 <__fixdfdi>
 *   @0xd113c mov r2, r0
 *   @0xd1140 mov r3, r1
 *   @0xd1144 b 0xd10fc <_Z12INT64_RValuePK6RValue+0x58>
 *   @0xd1148 mov r1, #0
 *   @0xd114c bl 0xd0d38 <_Z17ARRAY_LVAL_RValueP8YYRValuei>
 *   @0xd1150 b 0xd10a8 <_Z12INT64_RValuePK6RValue+0x4>
 *   @0xd1154 ldm r0, {r2, r3}
 *   @0xd1158 b 0xd10fc <_Z12INT64_RValuePK6RValue+0x58>
 *   @0xd115c mvn r3, #-16777216
 *   @0xd1160 cmp r1, r3
 *   @0xd1164 beq 0xd1190 <_Z12INT64_RValuePK6RValue+0xec>
 *   @0xd1168 ldr r0, [pc, #0x38]
 *   @0xd116c add r0, pc, r0
 *   @0xd1170 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd1174 mov r2, #0
 *   @0xd1178 mov r3, #0
 *   @0xd117c b 0xd10fc <_Z12INT64_RValuePK6RValue+0x58>
 *   @0xd1180 mov r1, #0
 *   @0xd1184 mov r2, #10
 *   @0xd1188 pop {r3, lr}
 *   @0xd118c b 0xb6664 <strtoll@plt>
 *   @0xd1190 ldr r0, [pc, #0x14]
 *   @0xd1194 add r0, pc, r0
 *   @0xd1198 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd119c mov r2, #0
 *   @0xd11a0 mov r3, #0
 *   @0xd11a4 b 0xd10fc <_Z12INT64_RValuePK6RValue+0x58>
 *   @0xd11a8 .word 0x002614b0
 *   @0xd11ac eoreq r1, r6, r0, ror r4
 *
 * ══ §80/110 F_VariableInstanceGet(RValue&, CInstance*, CInstance*, int, RValue*)  0x1169a4  size 268  67 条（0x1169a4..0x116ab0）
 * @func 0x1169a4 0x116ab0  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int) / F_VariableInstanceGet(RValue&, CInstance*, CInstance*, int, RValue*)+0x7c / Variable_BuiltIn_Find(char const*) / F_VariableInstanceGet(RValue&, CInstance*, CInstance*, int, RValue*)+0xe8 / Variable_GetValue_Direct(YYObjectBase*, int, int, RValue*) / Code_Variable_Find_Slot_From_Name(YYObjectBase*, char const*)
 * 字段偏移 top8: 0x8×4 / 0xc×4 / 0x4×2 / 0x10×1 / 0xcc×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1169a4 push {r4, r5, r6, lr}
 *   @0x1169a8 mov r1, #0
 *   @0x1169ac ldr r6, [sp, #0x10]
 *   @0x1169b0 mov r5, r0
 *   @0x1169b4 mov r0, r6
 *   @0x1169b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1169bc mov r1, #1
 *   @0x1169c0 mov r4, r0
 *   @0x1169c4 mov r0, r6
 *   @0x1169c8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1169cc cmp r4, #0
 *   @0x1169d0 mov r6, r0
 *   @0x1169d4 blt 0x116a20 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x1169d8 ldr r3, [pc, #0xcc]
 *   @0x1169dc ldr r3, [pc, r3]
 *   @0x1169e0 ldr r2, [r3, #0x4]
 *   @0x1169e4 ldr r3, [r3]
 *   @0x1169e8 and r2, r4, r2
 *   @0x1169ec ldr r2, [r3, r2, lsl #3]
 *   @0x1169f0 cmp r2, #0
 *   @0x1169f4 beq 0x116a20 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x1169f8 ldr r3, [r2, #0x8]
 *   @0x1169fc cmp r4, r3
 *   @0x116a00 bne 0x116a14 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x116a04 b 0x116a38 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x116a08 ldr r12, [r2, #0x8]
 *   @0x116a0c cmp r4, r12
 *   @0x116a10 beq 0x116a38 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x116a14 ldr r2, [r2, #0x4]
 *   @0x116a18 cmp r2, #0
 *   @0x116a1c bne 0x116a08 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x116a20 mov r3, #0
 *   @0x116a24 str r3, [r5]
 *   @0x116a28 str r3, [r5, #0x8]
 *   @0x116a2c mov r3, #5
 *   @0x116a30 str r3, [r5, #0xc]
 *   @0x116a34 pop {r4, r5, r6, pc}
 *   @0x116a38 ldr r4, [r2, #0xc]
 *   @0x116a3c mov r3, #0
 *   @0x116a40 mvn r2, #-16777216
 *   @0x116a44 str r3, [r5]
 *   @0x116a48 cmp r4, r3
 *   @0x116a4c str r2, [r5, #0xc]
 *   @0x116a50 str r3, [r5, #0x8]
 *   @0x116a54 beq 0x116a2c <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x116a58 mov r0, r6
 *   @0x116a5c bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc>
 *   @0x116a60 subs r1, r0, #0
 *   @0x116a64 blt 0x116a8c <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x116a68 mov r0, r4
 *   @0x116a6c mov r2, #-2147483648
 *   @0x116a70 mov r3, r5
 *   @0x116a74 bl 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue>
 *   @0x116a78 ldr r3, [r5, #0xc]
 *   @0x116a7c mvn r2, #-16777216
 *   @0x116a80 cmp r3, r2
 *   @0x116a84 popne {r4, r5, r6, pc}
 *   @0x116a88 b 0x116a2c <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x116a8c mov r1, r6
 *   @0x116a90 mov r0, r4
 *   @0x116a94 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc>
 *   @0x116a98 cmp r0, #0
 *   @0x116a9c addge r1, r0, #99328
 *   @0x116aa0 addge r1, r1, #672
 *   @0x116aa4 bge 0x116a68 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x116aa8 b 0x116a78 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x116aac eoreq r7, sp, r8, ror #4
 *
 * ══ §81/110 F_HighscoreShowExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x1276ec  size 268  67 条（0x1276ec..0x1277f8）
 * @func 0x1276ec 0x1277f8  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x127708→0x3f51d0, 0x127720→0x3f51c0, 0x127738→0x3f51c8, 0x127750→0x544b14, 0x127754→0x544b10, 0x1277b8→0x3f51c4
 * 调用序列: YYGetInt32(RValue const*, int)×5 / YYGetBool(RValue const*, int) / YYGetString(RValue const*, int) / operator new(unsigned int) / 0xb6538 / YYStrDup(char const*) / HighScore_Show(int)
 * 字段偏移 top8: 0x94×2 / 0x18×1 / 0xdc×1 / 0xd0×1 / 0xbc×1 / 0xa8×1 / 0x8×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1276ec push {r4, r5, r6, r7, r8, lr}
 *   @0x1276f0 mov r1, #1
 *   @0x1276f4 ldr r4, [sp, #0x18]
 *   @0x1276f8 ldr r5, [pc, #0xdc]
 *   @0x1276fc mov r0, r4
 *   @0x127700 add r5, pc, r5
 *   @0x127704 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x127708 ldr r3, [pc, #0xd0]
 *   @0x12770c mov r1, #2
 *   @0x127710 ldr r3, [r5, r3]
 *   @0x127714 str r0, [r3]
 *   @0x127718 mov r0, r4
 *   @0x12771c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x127720 ldr r3, [pc, #0xbc]
 *   @0x127724 mov r1, #3
 *   @0x127728 ldr r3, [r5, r3]
 *   @0x12772c strb r0, [r3]
 *   @0x127730 mov r0, r4
 *   @0x127734 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x127738 ldr r3, [pc, #0xa8]
 *   @0x12773c mov r1, #4
 *   @0x127740 ldr r3, [r5, r3]
 *   @0x127744 str r0, [r3]
 *   @0x127748 mov r0, r4
 *   @0x12774c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x127750 ldr r12, [pc, #0x94]
 *   @0x127754 ldr r2, [pc, #0x94]
 *   @0x127758 mov r1, #5
 *   @0x12775c mov r3, #0
 *   @0x127760 ldr r12, [r5, r12]
 *   @0x127764 str r0, [r12]
 *   @0x127768 mov r0, r4
 *   @0x12776c ldr r8, [r5, r2]
 *   @0x127770 str r3, [r8]
 *   @0x127774 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x127778 mov r7, r0
 *   @0x12777c mov r0, #12
 *   @0x127780 bl 0x27c524 <_Znwj>
 *   @0x127784 mov r6, r0
 *   @0x127788 subs r0, r7, #0
 *   @0x12778c beq 0x127794 <_Z18F_HighscoreShowExtR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x127790 bl 0xb6538 <strlen@plt>
 *   @0x127794 str r0, [r6, #0x8]
 *   @0x127798 mov r0, r7
 *   @0x12779c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1277a0 mov r3, #1
 *   @0x1277a4 mov r1, #6
 *   @0x1277a8 stm r6, {r0, r3}
 *   @0x1277ac mov r0, r4
 *   @0x1277b0 str r6, [r8]
 *   @0x1277b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1277b8 ldr r3, [pc, #0x34]
 *   @0x1277bc mov r1, #0
 *   @0x1277c0 ldr r3, [r5, r3]
 *   @0x1277c4 str r0, [r3]
 *   @0x1277c8 mov r0, r4
 *   @0x1277cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1277d0 bl 0x1dc2d4 <_Z14HighScore_Showi>
 *   @0x1277d4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1277d8 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x1277dc eoreq r10, r12, r0, asr r5
 *   @0x1277e0 .word 0xffffce28
 *   @0x1277e4 .word 0xffffce08
 *   @0x1277e8 .word 0xffffce20
 *   @0x1277ec .word 0xffffce24
 *   @0x1277f0 .word 0xffffce3c
 *   @0x1277f4 .word 0xffffce40
 *
 * ══ §82/110 F_ActionDrawGradientHor(RValue&, CInstance*, CInstance*, int, RValue*)  0x14045c  size 268  67 条（0x14045c..0x140568）
 * @func 0x14045c 0x140568  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / GR_Draw_Rectangle_Ext(float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, bool)×2
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0x10×2 / 0xc×2 / 0x38×1 / 0x90×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14045c push {r4, r5, r6, lr}
 *   @0x140460 vpush {d8, d9}
 *   @0x140464 sub sp, sp, #24
 *   @0x140468 mov r6, r1
 *   @0x14046c mov r1, #0
 *   @0x140470 ldr r4, [sp, #0x38]
 *   @0x140474 mov r0, r4
 *   @0x140478 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14047c mov r1, #1
 *   @0x140480 vmov s19, r0
 *   @0x140484 mov r0, r4
 *   @0x140488 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14048c mov r1, #2
 *   @0x140490 vmov s18, r0
 *   @0x140494 mov r0, r4
 *   @0x140498 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14049c mov r1, #3
 *   @0x1404a0 vmov s17, r0
 *   @0x1404a4 mov r0, r4
 *   @0x1404a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1404ac mov r1, #4
 *   @0x1404b0 vmov s16, r0
 *   @0x1404b4 mov r0, r4
 *   @0x1404b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1404bc mov r1, #5
 *   @0x1404c0 mov r5, r0
 *   @0x1404c4 mov r0, r4
 *   @0x1404c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1404cc ldr r3, [pc, #0x90]
 *   @0x1404d0 ldr r3, [pc, r3]
 *   @0x1404d4 ldrb r3, [r3]
 *   @0x1404d8 str r5, [sp]
 *   @0x1404dc cmp r3, #0
 *   @0x1404e0 mov r2, r0
 *   @0x1404e4 bne 0x140518 <_Z23F_ActionDrawGradientHorR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x1404e8 str r0, [sp, #0x4]
 *   @0x1404ec str r0, [sp, #0x8]
 *   @0x1404f0 str r3, [sp, #0x10]
 *   @0x1404f4 str r5, [sp, #0xc]
 *   @0x1404f8 vmov r0, s19
 *   @0x1404fc vmov r1, s18
 *   @0x140500 vmov r2, s17
 *   @0x140504 vmov r3, s16
 *   @0x140508 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb>
 *   @0x14050c add sp, sp, #24
 *   @0x140510 vpop {d8, d9}
 *   @0x140514 pop {r4, r5, r6, pc}
 *   @0x140518 vldr s14, [r6, #180]
 *   @0x14051c str r0, [sp, #0x4]
 *   @0x140520 str r2, [sp, #0x8]
 *   @0x140524 vadd.f32 s19, s19, s14
 *   @0x140528 vldr s15, [r6, #184]
 *   @0x14052c mov r3, #0
 *   @0x140530 str r5, [sp, #0xc]
 *   @0x140534 str r3, [sp, #0x10]
 *   @0x140538 vadd.f32 s14, s17, s14
 *   @0x14053c vmov r0, s19
 *   @0x140540 vadd.f32 s18, s18, s15
 *   @0x140544 vmov r2, s14
 *   @0x140548 vadd.f32 s15, s16, s15
 *   @0x14054c vmov r1, s18
 *   @0x140550 vmov r3, s15
 *   @0x140554 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb>
 *   @0x140558 add sp, sp, #24
 *   @0x14055c vpop {d8, d9}
 *   @0x140560 pop {r4, r5, r6, pc}
 *   @0x140564 eoreq sp, r10, r12, ror #12
 *
 * ══ §83/110 F_ActionDrawGradientVert(RValue&, CInstance*, CInstance*, int, RValue*)  0x140568  size 268  67 条（0x140568..0x140674）
 * @func 0x140568 0x140674  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / GR_Draw_Rectangle_Ext(float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, bool)×2
 * 字段偏移 top8: 0x8×2 / 0xc×2 / 0x10×2 / 0x4×2 / 0x38×1 / 0x90×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140568 push {r4, r5, r6, lr}
 *   @0x14056c vpush {d8, d9}
 *   @0x140570 sub sp, sp, #24
 *   @0x140574 mov r6, r1
 *   @0x140578 mov r1, #0
 *   @0x14057c ldr r4, [sp, #0x38]
 *   @0x140580 mov r0, r4
 *   @0x140584 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140588 mov r1, #1
 *   @0x14058c vmov s19, r0
 *   @0x140590 mov r0, r4
 *   @0x140594 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140598 mov r1, #2
 *   @0x14059c vmov s18, r0
 *   @0x1405a0 mov r0, r4
 *   @0x1405a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1405a8 mov r1, #3
 *   @0x1405ac vmov s17, r0
 *   @0x1405b0 mov r0, r4
 *   @0x1405b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1405b8 mov r1, #4
 *   @0x1405bc vmov s16, r0
 *   @0x1405c0 mov r0, r4
 *   @0x1405c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1405c8 mov r1, #5
 *   @0x1405cc mov r5, r0
 *   @0x1405d0 mov r0, r4
 *   @0x1405d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1405d8 ldr r3, [pc, #0x90]
 *   @0x1405dc ldr r3, [pc, r3]
 *   @0x1405e0 ldrb r3, [r3]
 *   @0x1405e4 str r5, [sp]
 *   @0x1405e8 cmp r3, #0
 *   @0x1405ec mov r2, r0
 *   @0x1405f0 bne 0x140624 <_Z24F_ActionDrawGradientVertR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x1405f4 str r0, [sp, #0x8]
 *   @0x1405f8 str r0, [sp, #0xc]
 *   @0x1405fc str r3, [sp, #0x10]
 *   @0x140600 str r5, [sp, #0x4]
 *   @0x140604 vmov r0, s19
 *   @0x140608 vmov r1, s18
 *   @0x14060c vmov r2, s17
 *   @0x140610 vmov r3, s16
 *   @0x140614 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb>
 *   @0x140618 add sp, sp, #24
 *   @0x14061c vpop {d8, d9}
 *   @0x140620 pop {r4, r5, r6, pc}
 *   @0x140624 vldr s14, [r6, #180]
 *   @0x140628 str r2, [sp, #0x8]
 *   @0x14062c str r5, [sp, #0x4]
 *   @0x140630 vadd.f32 s19, s19, s14
 *   @0x140634 vldr s15, [r6, #184]
 *   @0x140638 mov r3, #0
 *   @0x14063c str r2, [sp, #0xc]
 *   @0x140640 str r3, [sp, #0x10]
 *   @0x140644 vadd.f32 s14, s17, s14
 *   @0x140648 vmov r0, s19
 *   @0x14064c vadd.f32 s18, s18, s15
 *   @0x140650 vmov r2, s14
 *   @0x140654 vadd.f32 s15, s16, s15
 *   @0x140658 vmov r1, s18
 *   @0x14065c vmov r3, s15
 *   @0x140660 bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb>
 *   @0x140664 add sp, sp, #24
 *   @0x140668 vpop {d8, d9}
 *   @0x14066c pop {r4, r5, r6, pc}
 *   @0x140670 eoreq sp, r10, r0, ror #10
 *
 * ══ §84/110 F_D3DSetMatrix(RValue&, CInstance*, CInstance*, int, RValue*)  0x149a34  size 268  67 条（0x149a34..0x149b40）
 * @func 0x149a34 0x149b40  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / YYGetInt32(RValue const*, int) / REAL_RValue_Ex(RValue const*) / Graphics::SetMatrix(eMatrix, float*)
 * 字段偏移 top8: 0x4×3 / 0x10×2 / 0x58×1 / 0xc×1 / 0x5c×1 / 0x48×1 / 0x1c×1 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x149a34 push {r4, r5, r6, r7, r8, lr}
 *   @0x149a38 sub sp, sp, #64
 *   @0x149a3c mov r1, #0
 *   @0x149a40 mov r5, r3
 *   @0x149a44 ldr r4, [sp, #0x58]
 *   @0x149a48 mov r0, r4
 *   @0x149a4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149a50 cmp r0, #2
 *   @0x149a54 mov r6, r0
 *   @0x149a58 bhi 0x149ad0 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x149a5c cmp r5, #2
 *   @0x149a60 beq 0x149afc <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x149a64 ldr r3, [r4, #0x10]
 *   @0x149a68 ldr r3, [r3, #0x4]
 *   @0x149a6c ldr r4, [r3, #0x4]
 *   @0x149a70 add r8, sp, #64
 *   @0x149a74 mov r5, sp
 *   @0x149a78 b 0x149a98 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x149a7c ldm r4, {r0, r1}
 *   @0x149a80 vmov d6, r0, r1
 *   @0x149a84 add r4, r4, #16
 *   @0x149a88 vcvt.f32.f64 s15, d6
 *   @0x149a8c vstmia r5!, {s15}
 *   @0x149a90 cmp r5, r8
 *   @0x149a94 beq 0x149ab4 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x149a98 ldr r3, [r4, #0xc]
 *   @0x149a9c bic r3, r3, #-16777216
 *   @0x149aa0 cmp r3, #0
 *   @0x149aa4 beq 0x149a7c <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x149aa8 mov r0, r4
 *   @0x149aac bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x149ab0 b 0x149a80 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x149ab4 cmp r6, #2
 *   @0x149ab8 beq 0x149ae8 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x149abc mov r0, r6
 *   @0x149ac0 mov r1, sp
 *   @0x149ac4 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x149ac8 add sp, sp, #64
 *   @0x149acc pop {r4, r5, r6, r7, r8, pc}
 *   @0x149ad0 ldr r0, [pc, #0x5c]
 *   @0x149ad4 mov r1, #1
 *   @0x149ad8 add r0, pc, r0
 *   @0x149adc bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x149ae0 add sp, sp, #64
 *   @0x149ae4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x149ae8 ldr r3, [pc, #0x48]
 *   @0x149aec mov r2, #1
 *   @0x149af0 ldr r3, [pc, r3]
 *   @0x149af4 strb r2, [r3]
 *   @0x149af8 b 0x149abc <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x149afc ldr r3, [r4, #0x1c]
 *   @0x149b00 bic r3, r3, #-16777216
 *   @0x149b04 cmp r3, #2
 *   @0x149b08 bne 0x149a64 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x149b0c ldr r3, [r4, #0x10]
 *   @0x149b10 ldr r3, [r3, #0x4]
 *   @0x149b14 ldr r2, [r3]
 *   @0x149b18 cmp r2, #16
 *   @0x149b1c beq 0x149a6c <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x149b20 ldr r0, [pc, #0x14]
 *   @0x149b24 mov r1, #1
 *   @0x149b28 add r0, pc, r0
 *   @0x149b2c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x149b30 b 0x149ac8 <_Z14F_D3DSetMatrixR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x149b34 andseq r7, pc, r4, lsl #28
 *   @0x149b38 eoreq r5, r10, r0, asr #22
 *   @0x149b3c mulseq pc, r12, lr
 *
 * ══ §85/110 DrawIt_Color(void*, float, float, float, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int)  0x17438c  size 268  67 条（0x17438c..0x174498）
 * @func 0x17438c 0x174498  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0x7c×2 / 0x78×2 / 0x80×2 / 0x100×1 / 0x74×1 / 0x8×1 / 0x20×1 / 0x38×1
 * VFP 指令 30 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17438c ldr r12, [pc, #0x100]
 *   @0x174390 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x174394 vpush {d8, d9, d10, d11, d12}
 *   @0x174398 ldr r12, [pc, r12]
 *   @0x17439c vldr s17, [sp, #100]
 *   @0x1743a0 mov r8, r1
 *   @0x1743a4 mov r7, r2
 *   @0x1743a8 mov r1, r0
 *   @0x1743ac mov r11, r3
 *   @0x1743b0 mov r0, #4
 *   @0x1743b4 mov r2, #24
 *   @0x1743b8 mov r3, #6
 *   @0x1743bc ldr r4, [r12]
 *   @0x1743c0 vldr s16, [sp, #104]
 *   @0x1743c4 vldr s19, [sp, #108]
 *   @0x1743c8 vldr s18, [sp, #112]
 *   @0x1743cc ldr r5, [sp, #0x74]
 *   @0x1743d0 ldr r6, [sp, #0x7c]
 *   @0x1743d4 vldr s21, [sp, #84]
 *   @0x1743d8 vldr s20, [sp, #88]
 *   @0x1743dc ldr r10, [sp, #0x78]
 *   @0x1743e0 ldr r9, [sp, #0x80]
 *   @0x1743e4 vldr s24, [sp, #80]
 *   @0x1743e8 vldr s23, [sp, #92]
 *   @0x1743ec vldr s22, [sp, #96]
 *   @0x1743f0 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1743f4 mov r12, r0
 *   @0x1743f8 vstr s17, [r12, #16]
 *   @0x1743fc vstr s16, [r12, #20]
 *   @0x174400 vstr s24, [r12, #28]
 *   @0x174404 vstr s19, [r12, #40]
 *   @0x174408 vstr s16, [r12, #44]
 *   @0x17440c vstr s21, [r12, #48]
 *   @0x174410 vstr s20, [r12, #52]
 *   @0x174414 vstr s19, [r12, #64]
 *   @0x174418 vstr s18, [r12, #68]
 *   @0x17441c vstr s21, [r12, #72]
 *   @0x174420 vstr s20, [r12, #76]
 *   @0x174424 vstr s19, [r12, #88]
 *   @0x174428 vstr s18, [r12, #92]
 *   @0x17442c vstr s23, [r12, #96]
 *   @0x174430 vstr s22, [r12, #100]
 *   @0x174434 vstr s17, [r12, #112]
 *   @0x174438 vstr s18, [r12, #116]
 *   @0x17443c str r4, [r12, #0x8]
 *   @0x174440 mov r0, #1
 *   @0x174444 str r4, [r12, #0x20]
 *   @0x174448 str r4, [r12, #0x38]
 *   @0x17444c str r4, [r12, #0x50]
 *   @0x174450 str r4, [r12, #0x68]
 *   @0x174454 str r4, [r12, #0x80]
 *   @0x174458 str r8, [r12]
 *   @0x17445c str r7, [r12, #0x4]
 *   @0x174460 str r5, [r12, #0xc]
 *   @0x174464 str r11, [r12, #0x18]
 *   @0x174468 str r10, [r12, #0x24]
 *   @0x17446c str r6, [r12, #0x3c]
 *   @0x174470 str r6, [r12, #0x54]
 *   @0x174474 str r9, [r12, #0x6c]
 *   @0x174478 str r8, [r12, #0x78]
 *   @0x17447c str r7, [r12, #0x7c]
 *   @0x174480 str r5, [r12, #0x84]
 *   @0x174484 vstr s17, [r12, #136]
 *   @0x174488 vstr s16, [r12, #140]
 *   @0x17448c vpop {d8, d9, d10, d11, d12}
 *   @0x174490 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x174494 eoreq r9, r7, r8, lsl #11
 *
 * ══ §86/110 Shader_Set_Uniform_F(int, int, double, double, double, double)  0x1888f0  size 268  67 条（0x1888f0..0x1889fc）
 * @func 0x1888f0 0x1889fc  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Set_Uniform_F(int, int, double, double, double, double)+0x28 / Shader_Get(int) / Shader_Set_Uniform_F(int, int, double, double, double, double)+0xe4 / Shader_Set_Uniform_F(int, int, int, float*)
 * 字段偏移 top8: 0x4×3 / 0xfc×1 / 0xc0×1 / 0x64×1 / 0x7c×1 / 0x78×1 / 0xc×1 / 0x14×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1888f0 ldr r12, [pc, #0xfc]
 *   @0x1888f4 push {r4, lr}
 *   @0x1888f8 vpush {d8}
 *   @0x1888fc ldr r12, [pc, r12]
 *   @0x188900 vmov d8, r2, r3
 *   @0x188904 sub sp, sp, #24
 *   @0x188908 ldr r3, [r12]
 *   @0x18890c mov r4, r0
 *   @0x188910 cmp r3, #1
 *   @0x188914 beq 0x188928 <_Z20Shader_Set_Uniform_Fiidddd+0x38>
 *   @0x188918 mov r0, #0
 *   @0x18891c add sp, sp, #24
 *   @0x188920 vpop {d8}
 *   @0x188924 pop {r4, pc}
 *   @0x188928 cmp r0, #0
 *   @0x18892c blt 0x188918 <_Z20Shader_Set_Uniform_Fiidddd+0x28>
 *   @0x188930 ldr r3, [pc, #0xc0]
 *   @0x188934 ldr r3, [pc, r3]
 *   @0x188938 ldr r3, [r3]
 *   @0x18893c cmp r3, #0
 *   @0x188940 beq 0x188918 <_Z20Shader_Set_Uniform_Fiidddd+0x28>
 *   @0x188944 ldr r0, [r3, #0x64]
 *   @0x188948 str r1, [sp, #0x4]
 *   @0x18894c bl 0x187e70 <_Z10Shader_Geti>
 *   @0x188950 ldr r1, [sp, #0x4]
 *   @0x188954 cmp r0, #0
 *   @0x188958 beq 0x188918 <_Z20Shader_Set_Uniform_Fiidddd+0x28>
 *   @0x18895c ldr r3, [r0, #0x7c]
 *   @0x188960 cmp r4, r3
 *   @0x188964 bge 0x188918 <_Z20Shader_Set_Uniform_Fiidddd+0x28>
 *   @0x188968 ldr r3, [r0, #0x78]
 *   @0x18896c rsb r4, r4, r4, lsl #3
 *   @0x188970 adds r4, r3, r4, lsl #2
 *   @0x188974 beq 0x188918 <_Z20Shader_Set_Uniform_Fiidddd+0x28>
 *   @0x188978 vcvt.f32.f64 s16, d8
 *   @0x18897c ldr r2, [r4, #0xc]
 *   @0x188980 mov r3, #0
 *   @0x188984 str r3, [sp, #0x14]
 *   @0x188988 cmp r1, r2
 *   @0x18898c movge r1, r2
 *   @0x188990 str r3, [sp, #0x10]
 *   @0x188994 cmp r1, #1
 *   @0x188998 strle r3, [sp, #0xc]
 *   @0x18899c vstr s16, [sp, #8]
 *   @0x1889a0 ble 0x1889d4 <_Z20Shader_Set_Uniform_Fiidddd+0xe4>
 *   @0x1889a4 vldr d6, [sp, #40]
 *   @0x1889a8 vcvt.f32.f64 s15, d6
 *   @0x1889ac cmp r1, #2
 *   @0x1889b0 vstr s15, [sp, #12]
 *   @0x1889b4 beq 0x1889d4 <_Z20Shader_Set_Uniform_Fiidddd+0xe4>
 *   @0x1889b8 vldr d6, [sp, #48]
 *   @0x1889bc vcvt.f32.f64 s15, d6
 *   @0x1889c0 cmp r1, #3
 *   @0x1889c4 vldrne d6, [sp, #56]
 *   @0x1889c8 vstr s15, [sp, #16]
 *   @0x1889cc vcvtne.f32.f64 s15, d6
 *   @0x1889d0 vstrne s15, [sp, #20]
 *   @0x1889d4 ldr r0, [r4, #0x4]
 *   @0x1889d8 mov r2, #1
 *   @0x1889dc add r3, sp, #8
 *   @0x1889e0 bl 0x188164 <_Z20Shader_Set_Uniform_FiiiPf>
 *   @0x1889e4 mov r0, #1
 *   @0x1889e8 add sp, sp, #24
 *   @0x1889ec vpop {d8}
 *   @0x1889f0 pop {r4, pc}
 *   @0x1889f4 eoreq r7, r6, r12, lsl #22
 *   @0x1889f8 eoreq r7, r6, r4, asr #22
 *
 * ══ §87/110 CGCGeneration::CGCGeneration()  0x190f58  size 268  67 条（0x190f58..0x191064）
 * @func 0x190f58 0x191064  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0 / CGCGeneration::CGCGeneration()+0x9c
 * 字段偏移 top8: 0x8×3 / 0x10×3 / 0x4×2 / 0xe8×1 / 0x64×1 / 0xc×1 / 0x20×1 / 0x2c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190f58 push {r4, r5, r6, lr}
 *   @0x190f5c mov r4, r0
 *   @0x190f60 mov r0, #20
 *   @0x190f64 mov r6, #0
 *   @0x190f68 bl 0x27c524 <_Znwj>
 *   @0x190f6c ldr r1, [pc, #0xe8]
 *   @0x190f70 mov r2, #16
 *   @0x190f74 mov r3, #15
 *   @0x190f78 add r1, pc, r1
 *   @0x190f7c mov r5, r0
 *   @0x190f80 str r2, [r0]
 *   @0x190f84 str r3, [r0, #0x8]
 *   @0x190f88 mov r2, #70
 *   @0x190f8c mov r3, #1
 *   @0x190f90 mov r0, #192
 *   @0x190f94 str r6, [r5, #0x10]
 *   @0x190f98 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x190f9c mov r2, #192
 *   @0x190fa0 mov r1, r6
 *   @0x190fa4 str r0, [r5, #0x10]
 *   @0x190fa8 bl 0xb65b0 <memset@plt>
 *   @0x190fac ldr r2, [r5]
 *   @0x190fb0 vldr s15, [pc, #160]
 *   @0x190fb4 str r6, [r5, #0x4]
 *   @0x190fb8 cmp r2, r6
 *   @0x190fbc vmov s13, r2
 *   @0x190fc0 vcvt.f32.s32 s14, s13
 *   @0x190fc4 vmul.f32 s15, s14, s15
 *   @0x190fc8 vcvt.s32.f32 s15, s15
 *   @0x190fcc vstr s15, [r5, #12]
 *   @0x190fd0 ble 0x190ff4 <_ZN13CGCGenerationC2Ev+0x9c>
 *   @0x190fd4 add r2, r2, r2, lsl #1
 *   @0x190fd8 ldr r3, [r5, #0x10]
 *   @0x190fdc mov r1, r6
 *   @0x190fe0 add r2, r3, r2, lsl #2
 *   @0x190fe4 str r1, [r3, #0x8]
 *   @0x190fe8 add r3, r3, #12
 *   @0x190fec cmp r3, r2
 *   @0x190ff0 bne 0x190fe4 <_ZN13CGCGenerationC2Ev+0x8c>
 *   @0x190ff4 ldr r2, [pc, #0x64]
 *   @0x190ff8 mov r3, #0
 *   @0x190ffc mvn r1, #0
 *   @0x191000 str r5, [r4]
 *   @0x191004 ldr r2, [pc, r2]
 *   @0x191008 str r3, [r4, #0x4]
 *   @0x19100c str r3, [r4, #0xc]
 *   @0x191010 mov r0, r4
 *   @0x191014 ldr r2, [r2]
 *   @0x191018 str r3, [r4, #0x8]
 *   @0x19101c str r3, [r4, #0x20]
 *   @0x191020 str r2, [r4, #0x2c]
 *   @0x191024 mvn r2, #-2147483648
 *   @0x191028 str r3, [r4, #0x24]
 *   @0x19102c str r3, [r4, #0x28]
 *   @0x191030 str r3, [r4, #0x30]
 *   @0x191034 str r3, [r4, #0x34]
 *   @0x191038 str r3, [r4, #0x38]
 *   @0x19103c str r3, [r4, #0x48]
 *   @0x191040 str r3, [r4, #0x4c]
 *   @0x191044 str r3, [r4, #0x50]
 *   @0x191048 str r1, [r4, #0x1c]
 *   @0x19104c str r1, [r4, #0x18]
 *   @0x191050 str r2, [r4, #0x14]
 *   @0x191054 pop {r4, r5, r6, pc}
 *   @0x191058 svclo #0x19999a
 *   @0x19105c ldrheq r0, [r10], -r8
 *   @0x191060 eoreq r12, r5, r12, lsl #25
 *
 * ══ §88/110 Room_Init()  0x1b4bc4  size 268  67 条（0x1b4bc4..0x1b4cd0）
 * @func 0x1b4bc4 0x1b4cd0  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1b4bdc→0x3f50d8, 0x1b4be4→0x3f50d4, 0x1b4c0c→0x5425ac, 0x1b4c10→0x5425a8, 0x1b4c1c→0x5425a5, 0x1b4c20→0x3f50c8, 0x1b4c2c→0x3f50d0, 0x1b4c30→0x3f50cc
 * 调用序列: 无
 * 字段偏移 top8: 0x94×2 / 0x8c×2 / 0x84×2 / 0x6c×2 / 0xcc×1 / 0xc8×1 / 0xbc×1 / 0xb8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b4bc4 ldr r1, [pc, #0xcc]
 *   @0x1b4bc8 mov r2, #0
 *   @0x1b4bcc ldr r3, [pc, #0xc8]
 *   @0x1b4bd0 mov r0, #1065353216
 *   @0x1b4bd4 push {r4, r5, r6, r7, r8, r9, r10}
 *   @0x1b4bd8 add r3, pc, r3
 *   @0x1b4bdc ldr r8, [pc, #0xbc]
 *   @0x1b4be0 add r1, pc, r1
 *   @0x1b4be4 ldr r7, [pc, #0xb8]
 *   @0x1b4be8 mvn r12, #0
 *   @0x1b4bec str r2, [r1]
 *   @0x1b4bf0 mov r4, #1325400064
 *   @0x1b4bf4 str r2, [r1, #0x4]
 *   @0x1b4bf8 str r2, [r1, #0x8]
 *   @0x1b4bfc str r2, [r1, #0xc]
 *   @0x1b4c00 str r2, [r1, #0x10]
 *   @0x1b4c04 str r2, [r1, #0x14]
 *   @0x1b4c08 ldr r1, [r3, r8]
 *   @0x1b4c0c ldr r5, [pc, #0x94]
 *   @0x1b4c10 ldr r6, [pc, #0x94]
 *   @0x1b4c14 str r0, [r1]
 *   @0x1b4c18 ldr r1, [r3, r7]
 *   @0x1b4c1c ldr r9, [pc, #0x8c]
 *   @0x1b4c20 ldr r8, [pc, #0x8c]
 *   @0x1b4c24 str r0, [r1]
 *   @0x1b4c28 ldr r7, [r3, r5]
 *   @0x1b4c2c ldr r5, [pc, #0x84]
 *   @0x1b4c30 ldr r1, [pc, #0x84]
 *   @0x1b4c34 str r2, [r7]
 *   @0x1b4c38 ldr r6, [r3, r6]
 *   @0x1b4c3c ldr r7, [pc, #0x7c]
 *   @0x1b4c40 str r2, [r6]
 *   @0x1b4c44 ldr r5, [r3, r5]
 *   @0x1b4c48 ldr r6, [pc, #0x74]
 *   @0x1b4c4c str r12, [r5]
 *   @0x1b4c50 ldr r10, [r3, r1]
 *   @0x1b4c54 ldr r5, [pc, #0x6c]
 *   @0x1b4c58 ldr r1, [pc, #0x6c]
 *   @0x1b4c5c str r12, [r10]
 *   @0x1b4c60 ldr r12, [r3, r9]
 *   @0x1b4c64 strb r2, [r12]
 *   @0x1b4c68 ldr r12, [r3, r8]
 *   @0x1b4c6c str r4, [r12]
 *   @0x1b4c70 ldr r12, [r3, r7]
 *   @0x1b4c74 str r4, [r12]
 *   @0x1b4c78 ldr r12, [r3, r6]
 *   @0x1b4c7c str r0, [r12]
 *   @0x1b4c80 ldr r12, [r3, r5]
 *   @0x1b4c84 pop {r4, r5, r6, r7, r8, r9, r10}
 *   @0x1b4c88 str r0, [r12]
 *   @0x1b4c8c ldr r3, [r3, r1]
 *   @0x1b4c90 strb r2, [r3]
 *   @0x1b4c94 bx lr
 *   @0x1b4c98 eorseq sp, r8, r8, ror #19
 *   @0x1b4c9c eoreq sp, r3, r8, ror r0
 *   @0x1b4ca0 .word 0xffffe6bc
 *   @0x1b4ca4 .word 0xffffe6c4
 *   @0x1b4ca8 .word 0xffffe6a8
 *   @0x1b4cac .word 0xffffe6ac
 *   @0x1b4cb0 .word 0xffffdf14
 *   @0x1b4cb4 .word 0xffffdf1c
 *   @0x1b4cb8 .word 0xffffdf18
 *   @0x1b4cbc .word 0xffffdf24
 *   @0x1b4cc0 .word 0xffffdf20
 *   @0x1b4cc4 .word 0xffffdf28
 *   @0x1b4cc8 .word 0xffffdf2c
 *   @0x1b4ccc .word 0xffffdf30
 *
 * ══ §89/110 CSprite::LoadMaskFromStream(int, CStream*)  0x1e64cc  size 268  67 条（0x1e64cc..0x1e65d8）
 * @func 0x1e64cc 0x1e65d8  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×7 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CSprite::LoadMaskFromStream(int, CStream*)+0xf4 / CSprite::LoadMaskFromStream(int, CStream*)+0xe0 / CStream::ReadBoolean()
 * 字段偏移 top8: 0x4×5 / 0x40×3 / 0x88×1 / 0x3×1 / 0x31×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e64cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e64d0 mov r7, r0
 *   @0x1e64d4 sub sp, sp, #12
 *   @0x1e64d8 mov r0, r2
 *   @0x1e64dc mov r6, r2
 *   @0x1e64e0 mov r4, r1
 *   @0x1e64e4 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e64e8 cmp r0, #800
 *   @0x1e64ec beq 0x1e64fc <_ZN7CSprite18LoadMaskFromStreamEiP7CStream+0x30>
 *   @0x1e64f0 mov r0, #1
 *   @0x1e64f4 add sp, sp, #12
 *   @0x1e64f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e64fc mov r0, r6
 *   @0x1e6500 lsl r8, r4, #3
 *   @0x1e6504 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e6508 mov r10, r0
 *   @0x1e650c mov r0, r6
 *   @0x1e6510 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e6514 str r0, [sp, #0x4]
 *   @0x1e6518 mov r0, r6
 *   @0x1e651c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e6520 ldr r2, [sp, #0x4]
 *   @0x1e6524 mov r0, r6
 *   @0x1e6528 mul r5, r2, r10
 *   @0x1e652c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e6530 mov r0, r6
 *   @0x1e6534 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e6538 mov r0, r6
 *   @0x1e653c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e6540 ldr r0, [r7, #0x40]
 *   @0x1e6544 ldr r2, [pc, #0x88]
 *   @0x1e6548 movw r3, #0xb4f
 *   @0x1e654c add r0, r0, r8
 *   @0x1e6550 add r2, pc, r2
 *   @0x1e6554 mov r1, r5
 *   @0x1e6558 add r0, r0, #4
 *   @0x1e655c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e6560 ldr r2, [sp, #0x4]
 *   @0x1e6564 ldr r3, [r7, #0x40]
 *   @0x1e6568 cmp r2, #0
 *   @0x1e656c str r5, [r3, r4, lsl #3]
 *   @0x1e6570 ble 0x1e65c0 <_ZN7CSprite18LoadMaskFromStreamEiP7CStream+0xf4>
 *   @0x1e6574 mov r4, #0
 *   @0x1e6578 mov r9, r4
 *   @0x1e657c cmp r10, #0
 *   @0x1e6580 add r5, r10, r4
 *   @0x1e6584 ble 0x1e65ac <_ZN7CSprite18LoadMaskFromStreamEiP7CStream+0xe0>
 *   @0x1e6588 ldr r3, [r7, #0x40]
 *   @0x1e658c mov r0, r6
 *   @0x1e6590 add r3, r3, r8
 *   @0x1e6594 ldr r11, [r3, #0x4]
 *   @0x1e6598 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x1e659c strb r0, [r11, r4]
 *   @0x1e65a0 add r4, r4, #1
 *   @0x1e65a4 cmp r5, r4
 *   @0x1e65a8 bne 0x1e6588 <_ZN7CSprite18LoadMaskFromStreamEiP7CStream+0xbc>
 *   @0x1e65ac ldr r3, [sp, #0x4]
 *   @0x1e65b0 add r9, r9, #1
 *   @0x1e65b4 mov r4, r5
 *   @0x1e65b8 cmp r9, r3
 *   @0x1e65bc bne 0x1e657c <_ZN7CSprite18LoadMaskFromStreamEiP7CStream+0xb0>
 *   @0x1e65c0 mov r3, #1
 *   @0x1e65c4 mov r0, #1
 *   @0x1e65c8 strb r3, [r7, #0x31]
 *   @0x1e65cc add sp, sp, #12
 *   @0x1e65d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e65d4 ldrsbeq r11, [r6], -r4
 *
 * ══ §90/110 OpenAL_Setup(IniFile*)  0x2232e8  size 268  67 条（0x2232e8..0x2233f4）
 * @func 0x2232e8 0x2233f4  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::GetKey(char const*, char const*) / android_getCpuFamily / android_getCpuFeatures
 * 字段偏移 top8: 0xc×5 / 0xd8×2 / 0xbc×2 / 0x9c×1 / 0x74×1 / 0x44×1 / 0x34×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2232e8 push {r3, r4, r5, r6, r7, lr}
 *   @0x2232ec mov r4, r0
 *   @0x2232f0 ldr r3, [pc, #0xd8]
 *   @0x2232f4 ldr r1, [pc, #0xd8]
 *   @0x2232f8 ldr r3, [pc, r3]
 *   @0x2232fc add r1, pc, r1
 *   @0x223300 ldr r6, [r3]
 *   @0x223304 ldr r3, [r6]
 *   @0x223308 mov r0, r6
 *   @0x22330c ldr r3, [r3, #0xc]
 *   @0x223310 blx r3
 *   @0x223314 ldr r1, [pc, #0xbc]
 *   @0x223318 ldr r2, [pc, #0xbc]
 *   @0x22331c mov r0, r4
 *   @0x223320 add r1, pc, r1
 *   @0x223324 add r2, pc, r2
 *   @0x223328 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x22332c cmp r0, #0
 *   @0x223330 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x223334 bl 0x2a2e90 <android_getCpuFamily>
 *   @0x223338 ldr r3, [r6]
 *   @0x22333c ldr r1, [pc, #0x9c]
 *   @0x223340 ldr r3, [r3, #0xc]
 *   @0x223344 add r1, pc, r1
 *   @0x223348 mov r7, r0
 *   @0x22334c mov r2, r0
 *   @0x223350 mov r0, r6
 *   @0x223354 blx r3
 *   @0x223358 cmp r7, #1
 *   @0x22335c popne {r3, r4, r5, r6, r7, pc}
 *   @0x223360 ldr r3, [r6]
 *   @0x223364 mov r0, r6
 *   @0x223368 ldr r1, [pc, #0x74]
 *   @0x22336c mov r4, #1
 *   @0x223370 mov r5, #0
 *   @0x223374 ldr r3, [r3, #0xc]
 *   @0x223378 add r1, pc, r1
 *   @0x22337c blx r3
 *   @0x223380 bl 0x2a2ebc <android_getCpuFeatures>
 *   @0x223384 and r0, r0, r4
 *   @0x223388 and r1, r1, r5
 *   @0x22338c orrs r3, r0, r1
 *   @0x223390 ldr r3, [r6]
 *   @0x223394 mov r0, r6
 *   @0x223398 beq 0x2233b0 <_Z12OpenAL_SetupP7IniFile+0xc8>
 *   @0x22339c ldr r1, [pc, #0x44]
 *   @0x2233a0 ldr r3, [r3, #0xc]
 *   @0x2233a4 add r1, pc, r1
 *   @0x2233a8 blx r3
 *   @0x2233ac pop {r3, r4, r5, r6, r7, pc}
 *   @0x2233b0 ldr r1, [pc, #0x34]
 *   @0x2233b4 ldr r3, [r3, #0xc]
 *   @0x2233b8 add r1, pc, r1
 *   @0x2233bc blx r3
 *   @0x2233c0 ldr r3, [pc, #0x28]
 *   @0x2233c4 ldr r3, [pc, r3]
 *   @0x2233c8 strb r7, [r3]
 *   @0x2233cc pop {r3, r4, r5, r6, r7, pc}
 *   @0x2233d0 andseq r10, r12, r12, lsl r4
 *   @0x2233d4 andseq r1, r3, r8, lsr #18
 *   @0x2233d8 andseq r1, r3, r4, lsl r9
 *   @0x2233dc andseq r1, r3, r0, lsr #18
 *   @0x2233e0 andseq r1, r3, r0, lsl r9
 *   @0x2233e4 andseq r1, r3, r4, lsl #18
 *   @0x2233e8 andseq r1, r3, r0, lsl r9
 *   @0x2233ec andseq r1, r3, r4, ror #17
 *   @0x2233f0 andseq lr, r12, r0, ror r0
 *
 * ══ §91/110 oggpackB_read  0x233c30  size 268  67 条（0x233c30..0x233d3c）
 * @func 0x233c30 0x233d3c  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpackB_read+0xa8×4 / oggpackB_read+0x48
 * 字段偏移 top8: 0x4×3 / 0xc×3 / 0x10×2 / 0x1×1 / 0x2×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233c30 push {r4, r5, r6, r7, r8, r9}
 *   @0x233c34 rsb r6, r1, #32
 *   @0x233c38 cmp r6, #32
 *   @0x233c3c mov r3, r0
 *   @0x233c40 bhi 0x233d1c <oggpackB_read+0xec>
 *   @0x233c44 ldr r5, [r0]
 *   @0x233c48 ldr r12, [r0, #0x10]
 *   @0x233c4c ldr r2, [r3, #0x4]
 *   @0x233c50 add r0, r5, #4
 *   @0x233c54 cmp r0, r12
 *   @0x233c58 add r0, r2, r1
 *   @0x233c5c add r7, r0, #7
 *   @0x233c60 blt 0x233c78 <oggpackB_read+0x48>
 *   @0x233c64 sub r4, r12, r7, asr #3
 *   @0x233c68 cmp r5, r4
 *   @0x233c6c bgt 0x233d20 <oggpackB_read+0xf0>
 *   @0x233c70 cmp r0, #0
 *   @0x233c74 beq 0x233d14 <oggpackB_read+0xe4>
 *   @0x233c78 ldr r4, [r3, #0xc]
 *   @0x233c7c cmp r0, #8
 *   @0x233c80 add r12, r2, #24
 *   @0x233c84 ldrb r8, [r4]
 *   @0x233c88 lsl r12, r8, r12
 *   @0x233c8c ble 0x233cd8 <oggpackB_read+0xa8>
 *   @0x233c90 ldrb r9, [r4, #0x1]
 *   @0x233c94 cmp r0, #16
 *   @0x233c98 add r8, r2, #16
 *   @0x233c9c orr r12, r12, r9, lsl r8
 *   @0x233ca0 ble 0x233cd8 <oggpackB_read+0xa8>
 *   @0x233ca4 ldrb r9, [r4, #0x2]
 *   @0x233ca8 cmp r0, #24
 *   @0x233cac add r8, r2, #8
 *   @0x233cb0 orr r12, r12, r9, lsl r8
 *   @0x233cb4 ble 0x233cd8 <oggpackB_read+0xa8>
 *   @0x233cb8 ldrb r8, [r4, #0x3]
 *   @0x233cbc cmp r0, #32
 *   @0x233cc0 orr r12, r12, r8, lsl r2
 *   @0x233cc4 ble 0x233cd8 <oggpackB_read+0xa8>
 *   @0x233cc8 cmp r2, #0
 *   @0x233ccc rsbne r2, r2, #8
 *   @0x233cd0 ldrbne r8, [r4, #0x4]
 *   @0x233cd4 orrne r12, r12, r8, asr r2
 *   @0x233cd8 asr r6, r6, #1
 *   @0x233cdc rsb r1, r1, #33
 *   @0x233ce0 cmp r0, #0
 *   @0x233ce4 lsr r12, r12, r6
 *   @0x233ce8 asr r1, r1, #1
 *   @0x233cec movge r2, r0
 *   @0x233cf0 movlt r2, r7
 *   @0x233cf4 and r7, r0, #7
 *   @0x233cf8 lsr r0, r12, r1
 *   @0x233cfc asr r2, r2, #3
 *   @0x233d00 str r7, [r3, #0x4]
 *   @0x233d04 add r4, r4, r2
 *   @0x233d08 add r5, r5, r2
 *   @0x233d0c str r4, [r3, #0xc]
 *   @0x233d10 str r5, [r3]
 *   @0x233d14 pop {r4, r5, r6, r7, r8, r9}
 *   @0x233d18 bx lr
 *   @0x233d1c ldr r12, [r0, #0x10]
 *   @0x233d20 mov r1, #0
 *   @0x233d24 mov r2, #1
 *   @0x233d28 str r12, [r3]
 *   @0x233d2c mvn r0, #0
 *   @0x233d30 str r1, [r3, #0xc]
 *   @0x233d34 str r2, [r3, #0x4]
 *   @0x233d38 b 0x233d14 <oggpackB_read+0xe4>
 *
 * ══ §92/110 anon_233e64  0x233e64  size 268  67 条（0x233e64..0x233f70）
 * @func 0x233e64 0x233f70  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x24×3 / 0x4×2 / 0x20×1 / 0x10×1 / 0x2×1 / 0x14×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233e64 ldr r12, [r0, #0x24]
 *   @0x233e68 ldr r3, [r0, #0x20]
 *   @0x233e6c push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x233e70 cmp r12, r3
 *   @0x233e74 movge r1, #0
 *   @0x233e78 bge 0x233f44 <oggpackB_get_buffer+0xe4>
 *   @0x233e7c ldr r3, [r0, #0x10]
 *   @0x233e80 add r4, r3, r12, lsl #2
 *   @0x233e84 ldr r8, [r3, r12, lsl #2]
 *   @0x233e88 tst r8, #1024
 *   @0x233e8c bne 0x233f50 <oggpackB_get_buffer+0xf0>
 *   @0x233e90 cmp r1, #0
 *   @0x233e94 cmpeq r2, #0
 *   @0x233e98 beq 0x233f40 <oggpackB_get_buffer+0xe0>
 *   @0x233e9c uxtb r6, r8
 *   @0x233ea0 and r7, r8, #512
 *   @0x233ea4 cmp r6, #255
 *   @0x233ea8 and r8, r8, #256
 *   @0x233eac bne 0x233ed0 <oggpackB_get_buffer+0x70>
 *   @0x233eb0 ldr r3, [r4, #0x4]!
 *   @0x233eb4 add r12, r12, #1
 *   @0x233eb8 tst r3, #512
 *   @0x233ebc uxtb r3, r3
 *   @0x233ec0 movne r7, #512
 *   @0x233ec4 cmp r3, #255
 *   @0x233ec8 add r6, r6, r3
 *   @0x233ecc beq 0x233eb0 <oggpackB_get_buffer+0x50>
 *   @0x233ed0 cmp r1, #0
 *   @0x233ed4 beq 0x233f10 <oggpackB_get_buffer+0xb0>
 *   @0x233ed8 mov r3, #344
 *   @0x233edc ldr r10, [r0, #0x14]
 *   @0x233ee0 ldrd r4, r5, [r0, r3]
 *   @0x233ee4 lsl r11, r12, #3
 *   @0x233ee8 ldr r9, [r0]
 *   @0x233eec ldr r3, [r0, #0xc]
 *   @0x233ef0 strd r4, r5, [r1, #24]
 *   @0x233ef4 ldrd r4, r5, [r10, r11]
 *   @0x233ef8 add r3, r9, r3
 *   @0x233efc str r7, [r1, #0xc]
 *   @0x233f00 str r8, [r1, #0x8]
 *   @0x233f04 str r3, [r1]
 *   @0x233f08 strd r4, r5, [r1, #16]
 *   @0x233f0c str r6, [r1, #0x4]
 *   @0x233f10 cmp r2, #0
 *   @0x233f14 beq 0x233f40 <oggpackB_get_buffer+0xe0>
 *   @0x233f18 mov r1, #344
 *   @0x233f1c ldr r4, [r0, #0xc]
 *   @0x233f20 ldrd r2, r3, [r0, r1]
 *   @0x233f24 add r12, r12, #1
 *   @0x233f28 add r6, r4, r6
 *   @0x233f2c str r12, [r0, #0x24]
 *   @0x233f30 adds r2, r2, #1
 *   @0x233f34 str r6, [r0, #0xc]
 *   @0x233f38 adc r3, r3, #0
 *   @0x233f3c strd r2, r3, [r0, r1]
 *   @0x233f40 mov r1, #1
 *   @0x233f44 mov r0, r1
 *   @0x233f48 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x233f4c bx lr
 *   @0x233f50 mov r4, #344
 *   @0x233f54 add r12, r12, #1
 *   @0x233f58 ldrd r2, r3, [r0, r4]
 *   @0x233f5c mvn r1, #0
 *   @0x233f60 str r12, [r0, #0x24]
 *   @0x233f64 adds r2, r2, #1
 *   @0x233f68 adc r3, r3, #0
 *   @0x233f6c strd r2, r3, [r0, r4]
 *
 * ══ §93/110 IniFile::IniFile(char*, bool)  0x2362b8  size 268  67 条（0x2362b8..0x2363c4）
 * @func 0x2362b8 0x2363c4  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb6538 / 0xb65a4 / IniFile::ReadIniFile() / LoadSave::SaveFileExists(char const*) / LoadSave::ReadBundleFile(char const*, int*) / 0xb6568 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x10×4 / 0x4×1 / 0x8×1 / 0x14×1 / 0x18×1 / 0xc4×1 / 0x7c×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2362b8 push {r4, r5, r6, lr}
 *   @0x2362bc mov r4, r0
 *   @0x2362c0 mov r3, #0
 *   @0x2362c4 mov r0, r1
 *   @0x2362c8 str r3, [r4, #0x4]
 *   @0x2362cc mov r5, r1
 *   @0x2362d0 str r3, [r4, #0x8]
 *   @0x2362d4 mov r6, r2
 *   @0x2362d8 str r3, [r4, #0x10]
 *   @0x2362dc str r3, [r4, #0x14]
 *   @0x2362e0 strb r3, [r4, #0x18]
 *   @0x2362e4 bl 0xb6538 <strlen@plt>
 *   @0x2362e8 ldr r1, [pc, #0xc4]
 *   @0x2362ec mov r3, #1
 *   @0x2362f0 mov r2, #129
 *   @0x2362f4 add r1, pc, r1
 *   @0x2362f8 add r0, r0, r3
 *   @0x2362fc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x236300 mov r1, r5
 *   @0x236304 str r0, [r4]
 *   @0x236308 bl 0xb65a4 <strcpy@plt>
 *   @0x23630c cmp r6, #0
 *   @0x236310 bne 0x236324 <_ZN7IniFileC2EPcb+0x6c>
 *   @0x236314 mov r0, r4
 *   @0x236318 bl 0x236120 <_ZN7IniFile11ReadIniFileEv>
 *   @0x23631c mov r0, r4
 *   @0x236320 pop {r4, r5, r6, pc}
 *   @0x236324 ldr r0, [r4]
 *   @0x236328 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x23632c cmp r0, #0
 *   @0x236330 bne 0x236398 <_ZN7IniFileC2EPcb+0xe0>
 *   @0x236334 ldr r5, [pc, #0x7c]
 *   @0x236338 ldr r0, [r4]
 *   @0x23633c ldr r5, [pc, r5]
 *   @0x236340 mov r1, r5
 *   @0x236344 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x236348 str r0, [r4, #0x10]
 *   @0x23634c cmp r0, #0
 *   @0x236350 beq 0x236314 <_ZN7IniFileC2EPcb+0x5c>
 *   @0x236354 ldr r0, [r5]
 *   @0x236358 mov r3, #1
 *   @0x23635c ldr r1, [pc, #0x58]
 *   @0x236360 mov r2, #143
 *   @0x236364 add r0, r0, r3
 *   @0x236368 add r1, pc, r1
 *   @0x23636c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x236370 ldr r2, [r5]
 *   @0x236374 ldr r1, [r4, #0x10]
 *   @0x236378 mov r6, r0
 *   @0x23637c bl 0xb6568 <strncpy@plt>
 *   @0x236380 ldr r3, [r5]
 *   @0x236384 mov r2, #0
 *   @0x236388 mov r0, r6
 *   @0x23638c strb r2, [r6, r3]
 *   @0x236390 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x236394 b 0x236314 <_ZN7IniFileC2EPcb+0x5c>
 *   @0x236398 ldr r5, [pc, #0x20]
 *   @0x23639c ldr r0, [r4]
 *   @0x2363a0 ldr r5, [pc, r5]
 *   @0x2363a4 mov r1, r5
 *   @0x2363a8 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0x2363ac str r0, [r4, #0x10]
 *   @0x2363b0 b 0x23634c <_ZN7IniFileC2EPcb+0x94>
 *   @0x2363b4 ldrsheq lr, [r1], -r0
 *   @0x2363b8 andseq r11, r11, r0, ror #2
 *   @0x2363bc andseq lr, r1, r12, ror sp
 *   @0x2363c0 ldrsheq r11, [r11], -r12
 *
 * ══ §94/110 CPhysicsObject::RemoveFixture(int)  0x2377c4  size 268  67 条（0x2377c4..0x2378d0）
 * @func 0x2377c4 0x2378d0  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::InvalidateFixture(b2Fixture*) / b2Body::DestroyFixture(b2Fixture*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×4 / 0x8×4 / 0x1c×2 / 0x3×2 / 0xc×1 / 0xb0×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2377c4 ldr r3, [r0, #0x1c]
 *   @0x2377c8 push {r4, r5, r6, lr}
 *   @0x2377cc mov r5, r0
 *   @0x2377d0 ldr r2, [r3, #0x4]
 *   @0x2377d4 mov r4, r1
 *   @0x2377d8 ldr r3, [r3]
 *   @0x2377dc and r2, r1, r2
 *   @0x2377e0 ldr r3, [r3, r2, lsl #3]
 *   @0x2377e4 cmp r3, #0
 *   @0x2377e8 bne 0x2377fc <_ZN14CPhysicsObject13RemoveFixtureEi+0x38>
 *   @0x2377ec b 0x2378b4 <_ZN14CPhysicsObject13RemoveFixtureEi+0xf0>
 *   @0x2377f0 ldr r3, [r3, #0x4]
 *   @0x2377f4 cmp r3, #0
 *   @0x2377f8 beq 0x2378b4 <_ZN14CPhysicsObject13RemoveFixtureEi+0xf0>
 *   @0x2377fc ldr r2, [r3, #0x8]
 *   @0x237800 cmp r4, r2
 *   @0x237804 bne 0x2377f0 <_ZN14CPhysicsObject13RemoveFixtureEi+0x2c>
 *   @0x237808 ldr r6, [r3, #0xc]
 *   @0x23780c cmp r6, #0
 *   @0x237810 beq 0x2378c4 <_ZN14CPhysicsObject13RemoveFixtureEi+0x100>
 *   @0x237814 ldr r3, [pc, #0xb0]
 *   @0x237818 mov r1, r6
 *   @0x23781c ldr r3, [pc, r3]
 *   @0x237820 ldr r3, [r3]
 *   @0x237824 ldr r0, [r3, #0xb4]
 *   @0x237828 bl 0x2383e0 <_ZN13CPhysicsWorld17InvalidateFixtureEP9b2Fixture>
 *   @0x23782c mov r1, r6
 *   @0x237830 ldr r0, [r5]
 *   @0x237834 bl 0x2c6f24 <_ZN6b2Body14DestroyFixtureEP9b2Fixture>
 *   @0x237838 ldr r5, [r5, #0x1c]
 *   @0x23783c ldr r1, [r5, #0x4]
 *   @0x237840 ldr r2, [r5]
 *   @0x237844 and r1, r4, r1
 *   @0x237848 ldr r0, [r2, r1, lsl #3]
 *   @0x23784c add r6, r2, r1, lsl #3
 *   @0x237850 cmp r0, #0
 *   @0x237854 bne 0x237868 <_ZN14CPhysicsObject13RemoveFixtureEi+0xa4>
 *   @0x237858 b 0x2378bc <_ZN14CPhysicsObject13RemoveFixtureEi+0xf8>
 *   @0x23785c ldr r0, [r0, #0x4]
 *   @0x237860 cmp r0, #0
 *   @0x237864 beq 0x2378bc <_ZN14CPhysicsObject13RemoveFixtureEi+0xf8>
 *   @0x237868 ldr r3, [r0, #0x8]
 *   @0x23786c cmp r4, r3
 *   @0x237870 bne 0x23785c <_ZN14CPhysicsObject13RemoveFixtureEi+0x98>
 *   @0x237874 ldr r3, [r0]
 *   @0x237878 cmp r3, #0
 *   @0x23787c ldrne r2, [r0, #0x4]
 *   @0x237880 ldreq r12, [r0, #0x4]
 *   @0x237884 strne r2, [r3, #0x4]
 *   @0x237888 ldrne r12, [r0, #0x4]
 *   @0x23788c streq r12, [r2, r1, lsl #3]
 *   @0x237890 cmp r12, #0
 *   @0x237894 streq r3, [r6, #0x4]
 *   @0x237898 strne r3, [r12]
 *   @0x23789c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2378a0 ldr r3, [r5, #0x8]
 *   @0x2378a4 mov r0, #1
 *   @0x2378a8 sub r3, r3, #1
 *   @0x2378ac str r3, [r5, #0x8]
 *   @0x2378b0 pop {r4, r5, r6, pc}
 *   @0x2378b4 mov r0, r3
 *   @0x2378b8 pop {r4, r5, r6, pc}
 *   @0x2378bc mov r0, #1
 *   @0x2378c0 pop {r4, r5, r6, pc}
 *   @0x2378c4 mov r0, r6
 *   @0x2378c8 pop {r4, r5, r6, pc}
 *   @0x2378cc andseq r6, r11, r12, lsl #2
 *
 * ══ §95/110 MakeDay(double, double, double)  0x245370  size 268  67 条（0x245370..0x24547c）
 * @func 0x245370 0x24547c  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598×4 / myisinf(double)×3 / CalcTimeFromYear(double) / Day(double)
 * 字段偏移 top8: 0xd8×1 / 0x4c×1
 * VFP 指令 22 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x245370 push {r3, r4, r5, r6, r7, lr}
 *   @0x245374 vpush {d8, d9, d10}
 *   @0x245378 mov r4, r2
 *   @0x24537c mov r5, r3
 *   @0x245380 mov r6, r0
 *   @0x245384 mov r7, r1
 *   @0x245388 bl 0x24364c <_Z7myisinfd>
 *   @0x24538c cmp r0, #0
 *   @0x245390 beq 0x2453a8 <_Z7MakeDayddd+0x38>
 *   @0x245394 ldr r3, [pc, #0xd8]
 *   @0x245398 ldr r3, [pc, r3]
 *   @0x24539c ldrd r0, r1, [r3]
 *   @0x2453a0 vpop {d8, d9, d10}
 *   @0x2453a4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2453a8 mov r0, r4
 *   @0x2453ac mov r1, r5
 *   @0x2453b0 bl 0x24364c <_Z7myisinfd>
 *   @0x2453b4 cmp r0, #0
 *   @0x2453b8 bne 0x245394 <_Z7MakeDayddd+0x24>
 *   @0x2453bc ldrd r0, r1, [sp, #48]
 *   @0x2453c0 bl 0x24364c <_Z7myisinfd>
 *   @0x2453c4 cmp r0, #0
 *   @0x2453c8 bne 0x245394 <_Z7MakeDayddd+0x24>
 *   @0x2453cc mov r0, r6
 *   @0x2453d0 mov r1, r7
 *   @0x2453d4 bl 0xb6598 <floor@plt>
 *   @0x2453d8 vmov d10, r0, r1
 *   @0x2453dc mov r0, r4
 *   @0x2453e0 mov r1, r5
 *   @0x2453e4 bl 0xb6598 <floor@plt>
 *   @0x2453e8 vmov d8, r0, r1
 *   @0x2453ec ldrd r0, r1, [sp, #48]
 *   @0x2453f0 bl 0xb6598 <floor@plt>
 *   @0x2453f4 vmov.f64 d7, #1.200000e+01
 *   @0x2453f8 vdiv.f64 d6, d8, d7
 *   @0x2453fc vmov d9, r0, r1
 *   @0x245400 vmov r0, r1, d6
 *   @0x245404 bl 0xb6598 <floor@plt>
 *   @0x245408 vmov d7, r0, r1
 *   @0x24540c vadd.f64 d7, d10, d7
 *   @0x245410 vmov r0, r1, d7
 *   @0x245414 bl 0x2452c0 <_Z16CalcTimeFromYeard>
 *   @0x245418 movw r12, #0xaaab
 *   @0x24541c vcvt.s32.f64 s15, d8
 *   @0x245420 movt r12, #0x2aaa
 *   @0x245424 ldr r3, [pc, #0x4c]
 *   @0x245428 ldr r3, [pc, r3]
 *   @0x24542c vmov r2, s15
 *   @0x245430 smull lr, r12, r12, r2
 *   @0x245434 asr lr, r2, #31
 *   @0x245438 vmov d6, r0, r1
 *   @0x24543c rsb r12, lr, r12, asr #1
 *   @0x245440 add r12, r12, r12, lsl #1
 *   @0x245444 sub r2, r2, r12, lsl #2
 *   @0x245448 add r3, r3, r2, lsl #3
 *   @0x24544c vldr d7, [r3]
 *   @0x245450 vadd.f64 d6, d6, d7
 *   @0x245454 vmov r0, r1, d6
 *   @0x245458 bl 0x2449d8 <_Z3Dayd>
 *   @0x24545c vmov.f64 d7, #1.000000e+00
 *   @0x245460 vmov d6, r0, r1
 *   @0x245464 vadd.f64 d9, d9, d6
 *   @0x245468 vsub.f64 d6, d9, d7
 *   @0x24546c vmov r0, r1, d6
 *   @0x245470 b 0x2453a0 <_Z7MakeDayddd+0x30>
 *   @0x245474 mulseq r10, r0, r3
 *   @0x245478 andseq r12, r10, r4, lsl #6
 *
 * ══ §96/110 Java_com_yoyogames_runner_RunnerJNILib_CloudResultString  0x2942e0  size 268  67 条（0x2942e0..0x2943ec）
 * @func 0x2942e0 0x2943ec  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×2 / setJNIEnv / 0xb65a4 / MemoryManager::Free(void const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x34×4 / 0x20×2 / 0x24×2 / 0x38×2 / 0x2a4×1 / 0xc4×1 / 0x4×1 / 0x2a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2942e0 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2942e4 mov r6, r0
 *   @0x2942e8 mov r7, r2
 *   @0x2942ec mov r9, r3
 *   @0x2942f0 ldr r5, [sp, #0x20]
 *   @0x2942f4 bl 0x290614 <setJNIEnv>
 *   @0x2942f8 ldr r3, [r6]
 *   @0x2942fc mov r1, r7
 *   @0x294300 mov r2, #0
 *   @0x294304 mov r0, r6
 *   @0x294308 ldr r3, [r3, #0x2a4]
 *   @0x29430c blx r3
 *   @0x294310 mov r8, r0
 *   @0x294314 bl 0xb6538 <strlen@plt>
 *   @0x294318 ldr r12, [pc, #0xc4]
 *   @0x29431c ldr r12, [pc, r12]
 *   @0x294320 ldr r4, [r12]
 *   @0x294324 cmp r4, #0
 *   @0x294328 beq 0x294354 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0x74>
 *   @0x29432c ldr r3, [r4, #0x24]
 *   @0x294330 cmp r3, r5
 *   @0x294334 bne 0x294348 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0x68>
 *   @0x294338 b 0x29437c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0x9c>
 *   @0x29433c ldr r12, [r4, #0x24]
 *   @0x294340 cmp r12, r5
 *   @0x294344 beq 0x29437c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0x9c>
 *   @0x294348 ldr r4, [r4, #0x4]
 *   @0x29434c cmp r4, #0
 *   @0x294350 bne 0x29433c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0x5c>
 *   @0x294354 cmp r8, #0
 *   @0x294358 cmpne r7, #0
 *   @0x29435c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x294360 ldr r3, [r6]
 *   @0x294364 mov r1, r7
 *   @0x294368 mov r2, r8
 *   @0x29436c mov r0, r6
 *   @0x294370 ldr r3, [r3, #0x2a8]
 *   @0x294374 blx r3
 *   @0x294378 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x29437c ldr r3, [r4, #0x38]
 *   @0x294380 cmp r0, r3
 *   @0x294384 bgt 0x2943b4 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0xd4>
 *   @0x294388 ldr r0, [r4, #0x34]
 *   @0x29438c mov r3, #7
 *   @0x294390 mov r1, r8
 *   @0x294394 str r3, [r4, #0xc]
 *   @0x294398 str r9, [r4, #0x28]
 *   @0x29439c bl 0xb65a4 <strcpy@plt>
 *   @0x2943a0 ldr r0, [r4, #0x34]
 *   @0x2943a4 bl 0xb6538 <strlen@plt>
 *   @0x2943a8 add r0, r0, #1
 *   @0x2943ac str r0, [r4, #0x3c]
 *   @0x2943b0 b 0x294354 <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0x74>
 *   @0x2943b4 add r5, r0, #1
 *   @0x2943b8 ldr r0, [r4, #0x34]
 *   @0x2943bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2943c0 ldr r1, [pc, #0x20]
 *   @0x2943c4 mov r0, r5
 *   @0x2943c8 mov r2, #70
 *   @0x2943cc add r1, pc, r1
 *   @0x2943d0 mov r3, #1
 *   @0x2943d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2943d8 str r5, [r4, #0x38]
 *   @0x2943dc str r0, [r4, #0x34]
 *   @0x2943e0 b 0x29438c <Java_com_yoyogames_runner_RunnerJNILib_CloudResultString+0xac>
 *   @0x2943e4 ldrsbeq r9, [r5], -r12
 *   @0x2943e8 andeq r12, r9, r4, ror #24
 *
 * ══ §97/110 b2Body::DestroyFixture(b2Fixture*)  0x2c6f24  size 268  67 条（0x2c6f24..0x2c7030）
 * @func 0x2c6f24 0x2c7030  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ContactManager::Destroy(b2Contact*) / b2Fixture::Destroy(b2BlockAllocator*) / b2BlockAllocator::Free(void*, int) / b2Fixture::DestroyProxies(b2BroadPhase*)
 * 字段偏移 top8: 0x4×5 / 0x68×3 / 0x78×2 / 0x74×1 / 0x80×1 / 0xc×1 / 0x34×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6f24 push {r3, r4, r5, r6, r7, lr}
 *   @0x2c6f28 movw r3, #0x91d4
 *   @0x2c6f2c ldr r7, [r0, #0x68]
 *   @0x2c6f30 movt r3, #0x1
 *   @0x2c6f34 mov r6, r0
 *   @0x2c6f38 mov r5, r1
 *   @0x2c6f3c ldr r3, [r7, r3]
 *   @0x2c6f40 tst r3, #2
 *   @0x2c6f44 popne {r3, r4, r5, r6, r7, pc}
 *   @0x2c6f48 ldr r2, [r0, #0x74]
 *   @0x2c6f4c cmp r2, #0
 *   @0x2c6f50 beq 0x2c6f7c <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x58>
 *   @0x2c6f54 cmp r2, r1
 *   @0x2c6f58 addeq r2, r0, #116
 *   @0x2c6f5c bne 0x2c6f70 <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x4c>
 *   @0x2c6f60 b 0x2c700c <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0xe8>
 *   @0x2c6f64 cmp r3, r5
 *   @0x2c6f68 beq 0x2c7008 <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0xe4>
 *   @0x2c6f6c mov r2, r3
 *   @0x2c6f70 ldr r3, [r2, #0x4]
 *   @0x2c6f74 cmp r3, #0
 *   @0x2c6f78 bne 0x2c6f64 <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x40>
 *   @0x2c6f7c ldr r4, [r6, #0x80]
 *   @0x2c6f80 cmp r4, #0
 *   @0x2c6f84 beq 0x2c6fbc <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x98>
 *   @0x2c6f88 ldr r1, [r4, #0x4]
 *   @0x2c6f8c ldr r4, [r4, #0xc]
 *   @0x2c6f90 ldr r2, [r1, #0x34]
 *   @0x2c6f94 ldr r3, [r1, #0x30]
 *   @0x2c6f98 cmp r5, r3
 *   @0x2c6f9c cmpne r5, r2
 *   @0x2c6fa0 bne 0x2c6f80 <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x5c>
 *   @0x2c6fa4 add r0, r7, #102400
 *   @0x2c6fa8 add r0, r0, #472
 *   @0x2c6fac bl 0x2c7894 <_ZN16b2ContactManager7DestroyEP9b2Contact>
 *   @0x2c6fb0 cmp r4, #0
 *   @0x2c6fb4 ldr r7, [r6, #0x68]
 *   @0x2c6fb8 bne 0x2c6f88 <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x64>
 *   @0x2c6fbc ldrh r3, [r6, #4]
 *   @0x2c6fc0 tst r3, #32
 *   @0x2c6fc4 bne 0x2c701c <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0xf8>
 *   @0x2c6fc8 mov r0, r5
 *   @0x2c6fcc mov r1, r7
 *   @0x2c6fd0 bl 0x2c85f0 <_ZN9b2Fixture7DestroyEP16b2BlockAllocator>
 *   @0x2c6fd4 mov r3, #0
 *   @0x2c6fd8 mov r0, r7
 *   @0x2c6fdc str r3, [r5, #0x8]
 *   @0x2c6fe0 str r3, [r5, #0x4]
 *   @0x2c6fe4 mov r1, r5
 *   @0x2c6fe8 mov r2, #52
 *   @0x2c6fec bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2c6ff0 ldr r3, [r6, #0x78]
 *   @0x2c6ff4 mov r0, r6
 *   @0x2c6ff8 sub r3, r3, #1
 *   @0x2c6ffc str r3, [r6, #0x78]
 *   @0x2c7000 pop {r3, r4, r5, r6, r7, lr}
 *   @0x2c7004 b 0x2c6c00 <_ZN6b2Body13ResetMassDataEv>
 *   @0x2c7008 add r2, r2, #4
 *   @0x2c700c ldr r3, [r5, #0x4]
 *   @0x2c7010 str r3, [r2]
 *   @0x2c7014 ldr r7, [r6, #0x68]
 *   @0x2c7018 b 0x2c6f7c <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0x58>
 *   @0x2c701c add r1, r7, #102400
 *   @0x2c7020 mov r0, r5
 *   @0x2c7024 add r1, r1, #472
 *   @0x2c7028 bl 0x2c8770 <_ZN9b2Fixture14DestroyProxiesEP12b2BroadPhase>
 *   @0x2c702c b 0x2c6fc8 <_ZN6b2Body14DestroyFixtureEP9b2Fixture+0xa4>
 *
 * ══ §98/110 b2FrictionJoint::Dump()  0x2cd3f4  size 268  67 条（0x2cd3f4..0x2cd500）
 * @func 0x2cd3f4 0x2cd500  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×8
 * 字段偏移 top8: 0x30×2 / 0x8×2 / 0x34×1 / 0xcc×1 / 0xbc×1 / 0xb0×1 / 0xa4×1 / 0x3d×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd3f4 push {r4, r5, r6, lr}
 *   @0x2cd3f8 mov r4, r0
 *   @0x2cd3fc ldr r2, [r4, #0x30]
 *   @0x2cd400 sub sp, sp, #8
 *   @0x2cd404 ldr r3, [r4, #0x34]
 *   @0x2cd408 ldr r0, [pc, #0xcc]
 *   @0x2cd40c ldr r6, [r2, #0x8]
 *   @0x2cd410 add r0, pc, r0
 *   @0x2cd414 ldr r5, [r3, #0x8]
 *   @0x2cd418 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cd41c ldr r0, [pc, #0xbc]
 *   @0x2cd420 mov r1, r6
 *   @0x2cd424 add r0, pc, r0
 *   @0x2cd428 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cd42c ldr r0, [pc, #0xb0]
 *   @0x2cd430 mov r1, r5
 *   @0x2cd434 add r0, pc, r0
 *   @0x2cd438 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cd43c ldr r0, [pc, #0xa4]
 *   @0x2cd440 ldrb r1, [r4, #0x3d]
 *   @0x2cd444 add r0, pc, r0
 *   @0x2cd448 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cd44c vldr s13, [r4, #68]
 *   @0x2cd450 vldr s14, [r4, #72]
 *   @0x2cd454 vcvt.f64.f32 d5, s13
 *   @0x2cd458 ldr r0, [pc, #0x8c]
 *   @0x2cd45c add r0, pc, r0
 *   @0x2cd460 vcvt.f64.f32 d7, s14
 *   @0x2cd464 vmov r2, r3, d5
 *   @0x2cd468 vstr d7, [sp]
 *   @0x2cd46c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cd470 vldr s13, [r4, #76]
 *   @0x2cd474 vldr s14, [r4, #80]
 *   @0x2cd478 vcvt.f64.f32 d5, s13
 *   @0x2cd47c ldr r0, [pc, #0x6c]
 *   @0x2cd480 add r0, pc, r0
 *   @0x2cd484 vcvt.f64.f32 d7, s14
 *   @0x2cd488 vmov r2, r3, d5
 *   @0x2cd48c vstr d7, [sp]
 *   @0x2cd490 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cd494 vldr s15, [r4, #96]
 *   @0x2cd498 vcvt.f64.f32 d6, s15
 *   @0x2cd49c ldr r0, [pc, #0x50]
 *   @0x2cd4a0 add r0, pc, r0
 *   @0x2cd4a4 vmov r2, r3, d6
 *   @0x2cd4a8 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cd4ac vldr s15, [r4, #100]
 *   @0x2cd4b0 vcvt.f64.f32 d5, s15
 *   @0x2cd4b4 ldr r0, [pc, #0x3c]
 *   @0x2cd4b8 add r0, pc, r0
 *   @0x2cd4bc vmov r2, r3, d5
 *   @0x2cd4c0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cd4c4 ldr r0, [pc, #0x30]
 *   @0x2cd4c8 ldr r1, [r4, #0x38]
 *   @0x2cd4cc add r0, pc, r0
 *   @0x2cd4d0 add sp, sp, #8
 *   @0x2cd4d4 pop {r4, r5, r6, lr}
 *   @0x2cd4d8 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cd4dc ldrdeq lr, pc, [r8], -r4
 *   @0x2cd4e0 andeq lr, r8, r8, lsl #21
 *   @0x2cd4e4 muleq r8, r4, r10
 *   @0x2cd4e8 andeq lr, r8, r0, lsr #21
 *   @0x2cd4ec andeq lr, r8, r12, lsr #21
 *   @0x2cd4f0 strheq lr, [r8], -r4
 *   @0x2cd4f4 andeq lr, r8, r0, ror #22
 *   @0x2cd4f8 andeq lr, r8, r4, ror #22
 *   @0x2cd4fc andeq lr, r8, r12, ror #21
 *
 * ══ §99/110 F_Vertex_Float4_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xc7bac  size 264  66 条（0xc7bac..0xc7cb4）
 * @func 0xc7bac 0xc7cb4  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int) / F_Vertex_Float4_release(RValue&, CInstance*, CInstance*, int, RValue*)+0xc8 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×5 / 0x4×3 / 0x18×2 / 0x14×2 / 0x10×2 / 0xf0×1 / 0x2×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc7bac push {r4, r5, r6, lr}
 *   @0xc7bb0 sub sp, sp, #8
 *   @0xc7bb4 ldr r3, [pc, #0xf0]
 *   @0xc7bb8 mov r1, #0
 *   @0xc7bbc ldr r5, [sp, #0x18]
 *   @0xc7bc0 add r3, pc, r3
 *   @0xc7bc4 mov r0, r5
 *   @0xc7bc8 ldr r4, [r3]
 *   @0xc7bcc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc7bd0 ldr r4, [r4, r0, lsl #2]
 *   @0xc7bd4 ldr r1, [r4, #0x2c]
 *   @0xc7bd8 ldr r3, [r4, #0xc]
 *   @0xc7bdc ldr r2, [r4, #0x4]
 *   @0xc7be0 ldr r1, [r1, #0x14]
 *   @0xc7be4 add r0, r1, r3
 *   @0xc7be8 cmp r2, r0
 *   @0xc7bec blo 0xc7c74 <_Z23F_Vertex_Float4_releaseR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0xc7bf0 ldr r6, [r4]
 *   @0xc7bf4 mov r0, r5
 *   @0xc7bf8 mov r1, #1
 *   @0xc7bfc add r6, r6, r3
 *   @0xc7c00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc7c04 mov r1, #2
 *   @0xc7c08 str r0, [r6]
 *   @0xc7c0c mov r0, r5
 *   @0xc7c10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc7c14 mov r1, #3
 *   @0xc7c18 str r0, [r6, #0x4]
 *   @0xc7c1c mov r0, r5
 *   @0xc7c20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc7c24 mov r1, #4
 *   @0xc7c28 str r0, [r6, #0x8]
 *   @0xc7c2c mov r0, r5
 *   @0xc7c30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc7c34 ldr r3, [r4, #0x10]
 *   @0xc7c38 ldr r1, [r4, #0x14]
 *   @0xc7c3c add r3, r3, #1
 *   @0xc7c40 ldr r2, [r4, #0xc]
 *   @0xc7c44 cmp r3, r1
 *   @0xc7c48 add r2, r2, #16
 *   @0xc7c4c str r0, [r6, #0xc]
 *   @0xc7c50 str r3, [r4, #0x10]
 *   @0xc7c54 ldrhs r3, [r4, #0x1c]
 *   @0xc7c58 str r2, [r4, #0xc]
 *   @0xc7c5c movhs r2, #0
 *   @0xc7c60 addhs r3, r3, #1
 *   @0xc7c64 strhs r2, [r4, #0x10]
 *   @0xc7c68 strhs r3, [r4, #0x1c]
 *   @0xc7c6c add sp, sp, #8
 *   @0xc7c70 pop {r4, r5, r6, pc}
 *   @0xc7c74 add r1, r1, r2
 *   @0xc7c78 ldr r0, [r4]
 *   @0xc7c7c add r1, r1, r2, lsr #1
 *   @0xc7c80 mov r2, #0
 *   @0xc7c84 str r1, [r4, #0x4]
 *   @0xc7c88 mov r3, #74
 *   @0xc7c8c str r2, [sp]
 *   @0xc7c90 ldr r2, [pc, #0x18]
 *   @0xc7c94 add r2, pc, r2
 *   @0xc7c98 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc7c9c ldr r3, [r4, #0xc]
 *   @0xc7ca0 mov r6, r0
 *   @0xc7ca4 str r0, [r4]
 *   @0xc7ca8 b 0xc7bf4 <_Z23F_Vertex_Float4_releaseR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0xc7cac eorseq r2, r11, r4, ror r5
 *   @0xc7cb0 mlaeq r6, r12, r3, r9
 *
 * ══ §100/110 F_Vertex_ubyte4_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8540  size 264  66 条（0xc8540..0xc8648）
 * @func 0xc8540 0xc8648  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int)×4 / YYGetInt32(RValue const*, int) / F_Vertex_ubyte4_release(RValue&, CInstance*, CInstance*, int, RValue*)+0xc8 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×4 / 0x2×2 / 0x4×2 / 0x14×2 / 0x10×2 / 0xf0×1 / 0x20×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8540 push {r4, r5, r6, r7, r8, lr}
 *   @0xc8544 sub sp, sp, #8
 *   @0xc8548 ldr r3, [pc, #0xf0]
 *   @0xc854c mov r1, #0
 *   @0xc8550 ldr r5, [sp, #0x20]
 *   @0xc8554 add r3, pc, r3
 *   @0xc8558 mov r0, r5
 *   @0xc855c ldr r4, [r3]
 *   @0xc8560 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc8564 ldr r4, [r4, r0, lsl #2]
 *   @0xc8568 ldr r2, [r4, #0x2c]
 *   @0xc856c ldr r6, [r4, #0xc]
 *   @0xc8570 ldr r3, [r4, #0x4]
 *   @0xc8574 ldr r2, [r2, #0x14]
 *   @0xc8578 add r1, r2, r6
 *   @0xc857c cmp r3, r1
 *   @0xc8580 blo 0xc8608 <_Z23F_Vertex_ubyte4_releaseR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0xc8584 ldr r8, [r4]
 *   @0xc8588 mov r0, r5
 *   @0xc858c mov r1, #1
 *   @0xc8590 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc8594 mov r1, #2
 *   @0xc8598 add r7, r8, r6
 *   @0xc859c strb r0, [r8, r6]
 *   @0xc85a0 mov r0, r5
 *   @0xc85a4 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc85a8 mov r1, #3
 *   @0xc85ac strb r0, [r7, #0x1]
 *   @0xc85b0 mov r0, r5
 *   @0xc85b4 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc85b8 mov r1, #4
 *   @0xc85bc strb r0, [r7, #0x2]
 *   @0xc85c0 mov r0, r5
 *   @0xc85c4 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc85c8 strb r0, [r7, #0x3]
 *   @0xc85cc ldr r3, [r4, #0x10]
 *   @0xc85d0 ldr r1, [r4, #0x14]
 *   @0xc85d4 add r3, r3, #1
 *   @0xc85d8 ldr r2, [r4, #0xc]
 *   @0xc85dc cmp r3, r1
 *   @0xc85e0 str r3, [r4, #0x10]
 *   @0xc85e4 add r3, r2, #4
 *   @0xc85e8 str r3, [r4, #0xc]
 *   @0xc85ec ldrhs r3, [r4, #0x1c]
 *   @0xc85f0 movhs r2, #0
 *   @0xc85f4 strhs r2, [r4, #0x10]
 *   @0xc85f8 addhs r3, r3, #1
 *   @0xc85fc strhs r3, [r4, #0x1c]
 *   @0xc8600 add sp, sp, #8
 *   @0xc8604 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc8608 add r2, r2, r3
 *   @0xc860c ldr r0, [r4]
 *   @0xc8610 add r1, r2, r3, lsr #1
 *   @0xc8614 mov r2, #0
 *   @0xc8618 str r1, [r4, #0x4]
 *   @0xc861c mov r3, #74
 *   @0xc8620 str r2, [sp]
 *   @0xc8624 ldr r2, [pc, #0x18]
 *   @0xc8628 add r2, pc, r2
 *   @0xc862c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc8630 ldr r6, [r4, #0xc]
 *   @0xc8634 mov r8, r0
 *   @0xc8638 str r0, [r4]
 *   @0xc863c b 0xc8588 <_Z23F_Vertex_ubyte4_releaseR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0xc8640 eorseq r1, r11, r0, ror #23
 *   @0xc8644 eoreq r8, r6, r8, lsl #20
 *
 * ══ §101/110 IBuffer::GetBufferFileHeader(char const*, BufferFileHeader&)  0xccf38  size 264  66 条（0xccf38..0xcd040）
 * @func 0xccf38 0xcd040  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65e0×2 / MemoryManager::Free(void const*)×2 / LoadSave::SaveFileExists(char const*) / LoadSave::ReadSaveFile(char const*, int*) / LoadSave::BundleFileExists(char const*) / LoadSave::ReadBundleFile(char const*, int*)
 * 字段偏移 top8: 0x4×2 / 0xf0×1 / 0xd0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xccf38 push {r4, r5, lr}
 *   @0xccf3c mov r4, r0
 *   @0xccf40 ldr r0, [pc, #0xf0]
 *   @0xccf44 sub sp, sp, #12
 *   @0xccf48 mov r5, r1
 *   @0xccf4c mov r2, #7
 *   @0xccf50 add r0, pc, r0
 *   @0xccf54 mov r1, r4
 *   @0xccf58 bl 0xb65e0 <strncmp@plt>
 *   @0xccf5c cmp r0, #0
 *   @0xccf60 beq 0xccf80 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0x48>
 *   @0xccf64 ldr r0, [pc, #0xd0]
 *   @0xccf68 mov r1, r4
 *   @0xccf6c mov r2, #8
 *   @0xccf70 add r0, pc, r0
 *   @0xccf74 bl 0xb65e0 <strncmp@plt>
 *   @0xccf78 cmp r0, #0
 *   @0xccf7c bne 0xccf88 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0x50>
 *   @0xccf80 add sp, sp, #12
 *   @0xccf84 pop {r4, r5, pc}
 *   @0xccf88 mov r0, r4
 *   @0xccf8c mov r3, #0
 *   @0xccf90 str r3, [sp, #0x4]
 *   @0xccf94 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xccf98 cmp r0, #0
 *   @0xccf9c mov r0, r4
 *   @0xccfa0 beq 0xccfec <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0xb4>
 *   @0xccfa4 add r1, sp, #4
 *   @0xccfa8 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0xccfac mov r12, r0
 *   @0xccfb0 cmp r12, #0
 *   @0xccfb4 beq 0xccff8 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0xc0>
 *   @0xccfb8 ldr r2, [r12]
 *   @0xccfbc movw r3, #0x5542
 *   @0xccfc0 movt r3, #0x4646
 *   @0xccfc4 cmp r2, r3
 *   @0xccfc8 bne 0xccfd8 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0xa0>
 *   @0xccfcc ldr r4, [r12, #0x4]
 *   @0xccfd0 cmp r4, #1
 *   @0xccfd4 beq 0xcd014 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0xdc>
 *   @0xccfd8 mov r0, r12
 *   @0xccfdc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xccfe0 mov r0, #0
 *   @0xccfe4 add sp, sp, #12
 *   @0xccfe8 pop {r4, r5, pc}
 *   @0xccfec bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0xccff0 cmp r0, #0
 *   @0xccff4 bne 0xcd000 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0xc8>
 *   @0xccff8 mov r0, #0
 *   @0xccffc b 0xccf80 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0x48>
 *   @0xcd000 mov r0, r4
 *   @0xcd004 add r1, sp, #4
 *   @0xcd008 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0xcd00c mov r12, r0
 *   @0xcd010 b 0xccfb0 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0x78>
 *   @0xcd014 mov lr, r12
 *   @0xcd018 ldm lr!, {r0, r1, r2, r3}
 *   @0xcd01c stm r5!, {r0, r1, r2, r3}
 *   @0xcd020 mov r0, r12
 *   @0xcd024 ldr r3, [lr]
 *   @0xcd028 str r3, [r5]
 *   @0xcd02c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcd030 mov r0, r4
 *   @0xcd034 b 0xccf80 <_ZN7IBuffer19GetBufferFileHeaderEPKcR16BufferFileHeader+0x48>
 *   @0xcd038 mlaeq r6, r0, r11, r3
 *   @0xcd03c eoreq r3, r6, r8, ror r11
 *
 * ══ §102/110 F_DsPriorityCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0xfb6dc  size 264  66 条（0xfb6dc..0xfb7e4）
 * @func 0xfb6dc 0xfb7e4  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xfb6e8→0x4836a0, 0xfb6f4→0x4836a4
 * 调用序列: F_DsPriorityCreate(RValue&, CInstance*, CInstance*, int, RValue*)+0x60 / operator new(unsigned int) / CDS_Priority::CDS_Priority() / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×3 / 0xe8×2 / 0xe0×1 / 0xc×1 / 0x44×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfb6dc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xfb6e0 mov r7, r0
 *   @0xfb6e4 ldr r3, [pc, #0xe8]
 *   @0xfb6e8 ldr r2, [pc, #0xe8]
 *   @0xfb6ec add r3, pc, r3
 *   @0xfb6f0 ldr r9, [r3, r2]
 *   @0xfb6f4 ldr r2, [pc, #0xe0]
 *   @0xfb6f8 ldr r5, [r9]
 *   @0xfb6fc ldr r8, [r3, r2]
 *   @0xfb700 cmp r5, #0
 *   @0xfb704 ble 0xfb73c <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfb708 ldr r3, [r8, #0x4]
 *   @0xfb70c ldr r6, [r3]
 *   @0xfb710 cmp r6, #0
 *   @0xfb714 beq 0xfb7cc <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0xfb718 mov r4, #0
 *   @0xfb71c b 0xfb72c <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0xfb720 ldr r2, [r3, #0x4]!
 *   @0xfb724 cmp r2, #0
 *   @0xfb728 beq 0xfb75c <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfb72c add r4, r4, #1
 *   @0xfb730 cmp r4, r5
 *   @0xfb734 lsl r6, r4, #2
 *   @0xfb738 bne 0xfb720 <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0xfb73c ldr r3, [r8]
 *   @0xfb740 cmp r5, r3
 *   @0xfb744 movlt r3, r5
 *   @0xfb748 bge 0xfb790 <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfb74c lsl r6, r5, #2
 *   @0xfb750 mov r4, r5
 *   @0xfb754 add r3, r3, #1
 *   @0xfb758 str r3, [r9]
 *   @0xfb75c mov r0, #24
 *   @0xfb760 bl 0x27c524 <_Znwj>
 *   @0xfb764 mov r5, r0
 *   @0xfb768 bl 0x209864 <_ZN12CDS_PriorityC2Ev>
 *   @0xfb76c vmov s15, r4
 *   @0xfb770 ldr r0, [r8, #0x4]
 *   @0xfb774 mov r1, #0
 *   @0xfb778 vcvt.f64.s32 d7, s15
 *   @0xfb77c str r5, [r0, r6]
 *   @0xfb780 str r1, [r7, #0xc]
 *   @0xfb784 vmov r2, r3, d7
 *   @0xfb788 stm r7, {r2, r3}
 *   @0xfb78c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xfb790 add r1, r5, #16
 *   @0xfb794 ldr r2, [pc, #0x44]
 *   @0xfb798 movw r3, #0x7cc
 *   @0xfb79c add r0, r8, #4
 *   @0xfb7a0 add r2, pc, r2
 *   @0xfb7a4 lsl r1, r1, #2
 *   @0xfb7a8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xfb7ac ldr r3, [r9]
 *   @0xfb7b0 lsl r6, r5, #2
 *   @0xfb7b4 mov r4, r5
 *   @0xfb7b8 add r2, r3, #16
 *   @0xfb7bc add r3, r3, #1
 *   @0xfb7c0 str r2, [r8]
 *   @0xfb7c4 str r3, [r9]
 *   @0xfb7c8 b 0xfb75c <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfb7cc mov r4, r6
 *   @0xfb7d0 b 0xfb75c <_Z18F_DsPriorityCreateR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfb7d4 eoreq r6, pc, r4, ror #10
 *   @0xfb7d8 .word 0xffffc224
 *   @0xfb7dc .word 0xffffc228
 *   @0xfb7e0 .word 0x0023c3fc
 *
 * ══ §103/110 F_InstanceCreateLayer(RValue&, CInstance*, CInstance*, int, RValue*)  0x1096e4  size 264  66 条（0x1096e4..0x1097ec）
 * @func 0x1096e4 0x1097ec  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×3 / Command_Create_Layer(int, float, float, int) / YYGetString(RValue const*, int) / Command_Create_Layer(int, float, float, char const*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x2c×1 / 0x94×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1096e4 push {r4, r5, r6, r7, r8, lr}
 *   @0x1096e8 mov r1, #3
 *   @0x1096ec ldr r4, [sp, #0x18]
 *   @0x1096f0 mov r5, r0
 *   @0x1096f4 ldr r6, [r4, #0x2c]
 *   @0x1096f8 mov r0, r4
 *   @0x1096fc cmp r6, #1
 *   @0x109700 beq 0x10979c <_Z21F_InstanceCreateLayerR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x109704 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109708 mov r1, #0
 *   @0x10970c mov r8, r0
 *   @0x109710 mov r0, r4
 *   @0x109714 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109718 mov r1, #1
 *   @0x10971c mov r7, r0
 *   @0x109720 mov r0, r4
 *   @0x109724 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109728 mov r1, #2
 *   @0x10972c mov r6, r0
 *   @0x109730 mov r0, r4
 *   @0x109734 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109738 mov r1, r7
 *   @0x10973c mov r2, r6
 *   @0x109740 mov r3, r0
 *   @0x109744 mov r0, r8
 *   @0x109748 bl 0x1c9980 <_Z20Command_Create_Layeriffi>
 *   @0x10974c ldr r3, [pc, #0x94]
 *   @0x109750 ldr r3, [pc, r3]
 *   @0x109754 ldrb r3, [r3]
 *   @0x109758 cmp r3, #0
 *   @0x10975c bne 0x10978c <_Z21F_InstanceCreateLayerR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x109760 cmp r0, #0
 *   @0x109764 str r3, [r5, #0xc]
 *   @0x109768 ldrne r2, [r0, #0x78]
 *   @0x10976c moveq r3, #0
 *   @0x109770 moveq r2, #0
 *   @0x109774 movteq r3, #0xc010
 *   @0x109778 vmovne s15, r2
 *   @0x10977c vcvtne.f64.s32 d7, s15
 *   @0x109780 vmovne r2, r3, d7
 *   @0x109784 stm r5, {r2, r3}
 *   @0x109788 pop {r4, r5, r6, r7, r8, pc}
 *   @0x10978c mov r3, #6
 *   @0x109790 str r0, [r5]
 *   @0x109794 str r3, [r5, #0xc]
 *   @0x109798 pop {r4, r5, r6, r7, r8, pc}
 *   @0x10979c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1097a0 mov r1, #0
 *   @0x1097a4 mov r8, r0
 *   @0x1097a8 mov r0, r4
 *   @0x1097ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1097b0 mov r1, r6
 *   @0x1097b4 mov r7, r0
 *   @0x1097b8 mov r0, r4
 *   @0x1097bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1097c0 mov r1, #2
 *   @0x1097c4 mov r6, r0
 *   @0x1097c8 mov r0, r4
 *   @0x1097cc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1097d0 mov r1, r7
 *   @0x1097d4 mov r2, r6
 *   @0x1097d8 mov r3, r0
 *   @0x1097dc mov r0, r8
 *   @0x1097e0 bl 0x1c9a74 <_Z20Command_Create_LayeriffPKc>
 *   @0x1097e4 b 0x10974c <_Z21F_InstanceCreateLayerR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x1097e8 eoreq r4, lr, r8, ror #8
 *
 * ══ §104/110 collisionResultPM(CInstance*, void*)  0x10a138  size 264  66 条（0x10a138..0x10a240）
 * @func 0x10a138 0x10a240  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Collision_Point(float, float, bool)×2 / CollisionIsRemoved(CInstance*) / CObjectGM::IsDecendentOf(int)
 * 字段偏移 top8: 0x80×2 / 0x68×1 / 0x69×1 / 0x48×1 / 0x18×1 / 0x78×1 / 0x38×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10a138 push {r3, r4, r5, r6, r7, lr}
 *   @0x10a13c mov r6, r1
 *   @0x10a140 mov r5, r0
 *   @0x10a144 bl 0x1cc244 <_Z18CollisionIsRemovedP9CInstance>
 *   @0x10a148 cmp r0, #0
 *   @0x10a14c bne 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24>
 *   @0x10a150 ldrb r3, [r5, #0x68]
 *   @0x10a154 cmp r3, #0
 *   @0x10a158 beq 0x10a168 <_Z17collisionResultPMP9CInstancePv+0x30>
 *   @0x10a15c mov r4, #1
 *   @0x10a160 mov r0, r4
 *   @0x10a164 pop {r3, r4, r5, r6, r7, pc}
 *   @0x10a168 ldrb r4, [r5, #0x69]
 *   @0x10a16c cmp r4, #0
 *   @0x10a170 bne 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24>
 *   @0x10a174 ldr r7, [r5, #0x48]
 *   @0x10a178 cmp r7, #1
 *   @0x10a17c bne 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24>
 *   @0x10a180 movw r2, #0x869f
 *   @0x10a184 movt r2, #0x1
 *   @0x10a188 cmp r6, r2
 *   @0x10a18c bgt 0x10a1f0 <_Z17collisionResultPMP9CInstancePv+0xb8>
 *   @0x10a190 ldr r0, [r5, #0x80]
 *   @0x10a194 ldr r3, [r0, #0x18]
 *   @0x10a198 cmp r6, r3
 *   @0x10a19c beq 0x10a1b0 <_Z17collisionResultPMP9CInstancePv+0x78>
 *   @0x10a1a0 mov r1, r6
 *   @0x10a1a4 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi>
 *   @0x10a1a8 cmp r0, #0
 *   @0x10a1ac beq 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24>
 *   @0x10a1b0 ldr r6, [pc, #0x80]
 *   @0x10a1b4 mov r3, #1
 *   @0x10a1b8 mov r0, r5
 *   @0x10a1bc add r6, pc, r6
 *   @0x10a1c0 vldr s15, [r6, #4]
 *   @0x10a1c4 vcvt.f32.s32 s15, s15
 *   @0x10a1c8 vmov r1, s15
 *   @0x10a1cc vldr s15, [r6, #8]
 *   @0x10a1d0 vcvt.f32.s32 s15, s15
 *   @0x10a1d4 vmov r2, s15
 *   @0x10a1d8 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb>
 *   @0x10a1dc cmp r0, #0
 *   @0x10a1e0 movne r3, #1
 *   @0x10a1e4 strbne r3, [r6]
 *   @0x10a1e8 bne 0x10a160 <_Z17collisionResultPMP9CInstancePv+0x28>
 *   @0x10a1ec b 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24>
 *   @0x10a1f0 ldr r3, [r5, #0x78]
 *   @0x10a1f4 cmp r3, r6
 *   @0x10a1f8 bne 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24>
 *   @0x10a1fc ldr r6, [pc, #0x38]
 *   @0x10a200 mov r0, r5
 *   @0x10a204 mov r3, r7
 *   @0x10a208 add r6, pc, r6
 *   @0x10a20c vldr s15, [r6, #4]
 *   @0x10a210 vcvt.f32.s32 s15, s15
 *   @0x10a214 vmov r1, s15
 *   @0x10a218 vldr s15, [r6, #8]
 *   @0x10a21c vcvt.f32.s32 s15, s15
 *   @0x10a220 vmov r2, s15
 *   @0x10a224 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb>
 *   @0x10a228 cmp r0, #0
 *   @0x10a22c strbne r7, [r6]
 *   @0x10a230 bne 0x10a160 <_Z17collisionResultPMP9CInstancePv+0x28>
 *   @0x10a234 b 0x10a15c <_Z17collisionResultPMP9CInstancePv+0x24>
 *   @0x10a238 eorseq r9, r7, r12, lsl r5
 *   @0x10a23c ldrsbteq r9, [r7], -r0
 *
 * ══ §105/110 F_SpriteAddFromScreen(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f2a0  size 264  66 条（0x12f2a0..0x12f3a8）
 * @func 0x12f2a0 0x12f3a8  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×7 / Sprite_Data(int) / GR_D3D_Screenshot_Part(int, int, int, int) / CSprite::AddFromBitmap(IBitmap*, bool, bool, bool)
 * 字段偏移 top8: 0x20×1 / 0x74×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f2a0 push {r4, r5, r6, r7, r8, lr}
 *   @0x12f2a4 sub sp, sp, #8
 *   @0x12f2a8 mov r1, #0
 *   @0x12f2ac ldr r4, [sp, #0x20]
 *   @0x12f2b0 mov r0, r4
 *   @0x12f2b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f2b8 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12f2bc subs r6, r0, #0
 *   @0x12f2c0 beq 0x12f384 <_Z21F_SpriteAddFromScreenR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x12f2c4 ldr r3, [r6, #0x74]
 *   @0x12f2c8 cmp r3, #0
 *   @0x12f2cc bne 0x12f38c <_Z21F_SpriteAddFromScreenR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x12f2d0 mov r1, #1
 *   @0x12f2d4 mov r0, r4
 *   @0x12f2d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f2dc mov r1, #2
 *   @0x12f2e0 mov r8, r0
 *   @0x12f2e4 mov r0, r4
 *   @0x12f2e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f2ec mov r1, #3
 *   @0x12f2f0 mov r7, r0
 *   @0x12f2f4 mov r0, r4
 *   @0x12f2f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f2fc mov r1, #4
 *   @0x12f300 mov r5, r0
 *   @0x12f304 mov r0, r4
 *   @0x12f308 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f30c mov r2, r5
 *   @0x12f310 mov r1, r7
 *   @0x12f314 mov r3, r0
 *   @0x12f318 mov r0, r8
 *   @0x12f31c bl 0x169b34 <_Z22GR_D3D_Screenshot_Partiiii>
 *   @0x12f320 mov r1, #5
 *   @0x12f324 mov r5, r0
 *   @0x12f328 mov r0, r4
 *   @0x12f32c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f330 mov r1, #6
 *   @0x12f334 cmp r0, #0
 *   @0x12f338 mov r0, r4
 *   @0x12f33c movle r7, #0
 *   @0x12f340 movgt r7, #1
 *   @0x12f344 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f348 eor r3, r7, #1
 *   @0x12f34c mov r2, r7
 *   @0x12f350 str r3, [sp]
 *   @0x12f354 mov r1, r5
 *   @0x12f358 cmp r0, #0
 *   @0x12f35c mov r0, r6
 *   @0x12f360 movle r3, #0
 *   @0x12f364 movgt r3, #1
 *   @0x12f368 bl 0x1e5988 <_ZN7CSprite13AddFromBitmapEP7IBitmapbbb>
 *   @0x12f36c cmp r5, #0
 *   @0x12f370 beq 0x12f384 <_Z21F_SpriteAddFromScreenR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x12f374 ldr r3, [r5]
 *   @0x12f378 mov r0, r5
 *   @0x12f37c ldr r3, [r3, #0x4]
 *   @0x12f380 blx r3
 *   @0x12f384 add sp, sp, #8
 *   @0x12f388 pop {r4, r5, r6, r7, r8, pc}
 *   @0x12f38c ldr r0, [pc, #0x10]
 *   @0x12f390 mov r1, #0
 *   @0x12f394 add r0, pc, r0
 *   @0x12f398 add sp, sp, #8
 *   @0x12f39c pop {r4, r5, r6, r7, r8, lr}
 *   @0x12f3a0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12f3a4 eoreq lr, r0, r4, lsl r5
 *
 * ══ §106/110 F_SpriteCollisionMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x1302cc  size 264  66 条（0x1302cc..0x1303d4）
 * @func 0x1302cc 0x1303d4  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×9 / Sprite_Data(int) / F_SpriteCollisionMask(RValue&, CInstance*, CInstance*, int, RValue*)+0xe4 / CSprite::ComputeMask(bool, int, tagYYRECT const&, int, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x30×2 / 0x10×2 / 0x18×1 / 0x74×1 / 0x8×1 / 0xc×1 / 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1302cc push {r4, r5, r6, r7, r8, lr}
 *   @0x1302d0 sub sp, sp, #24
 *   @0x1302d4 mov r1, #0
 *   @0x1302d8 ldr r4, [sp, #0x30]
 *   @0x1302dc mov r0, r4
 *   @0x1302e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1302e4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1302e8 subs r5, r0, #0
 *   @0x1302ec beq 0x1303b0 <_Z21F_SpriteCollisionMaskR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x1302f0 ldr r3, [r5, #0x18]
 *   @0x1302f4 cmp r3, #0
 *   @0x1302f8 ble 0x1303b0 <_Z21F_SpriteCollisionMaskR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x1302fc ldr r3, [r5, #0x74]
 *   @0x130300 cmp r3, #0
 *   @0x130304 bne 0x1303b8 <_Z21F_SpriteCollisionMaskR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x130308 mov r1, #1
 *   @0x13030c mov r0, r4
 *   @0x130310 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130314 mov r1, #2
 *   @0x130318 mov r8, r0
 *   @0x13031c mov r0, r4
 *   @0x130320 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130324 mov r1, #3
 *   @0x130328 mov r7, r0
 *   @0x13032c mov r0, r4
 *   @0x130330 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130334 mov r1, #4
 *   @0x130338 str r0, [sp, #0x8]
 *   @0x13033c mov r0, r4
 *   @0x130340 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130344 mov r1, #5
 *   @0x130348 str r0, [sp, #0xc]
 *   @0x13034c mov r0, r4
 *   @0x130350 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130354 mov r1, #6
 *   @0x130358 str r0, [sp, #0x10]
 *   @0x13035c mov r0, r4
 *   @0x130360 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130364 mov r1, #7
 *   @0x130368 str r0, [sp, #0x14]
 *   @0x13036c mov r0, r4
 *   @0x130370 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130374 mov r1, #8
 *   @0x130378 mov r6, r0
 *   @0x13037c mov r0, r4
 *   @0x130380 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130384 cmp r8, #0
 *   @0x130388 mov r12, #1
 *   @0x13038c mov r2, r7
 *   @0x130390 strb r12, [r5, #0x30]
 *   @0x130394 movle r1, #0
 *   @0x130398 movgt r1, #1
 *   @0x13039c add r3, sp, #8
 *   @0x1303a0 str r6, [sp]
 *   @0x1303a4 str r0, [sp, #0x4]
 *   @0x1303a8 mov r0, r5
 *   @0x1303ac bl 0x1e3d88 <_ZN7CSprite11ComputeMaskEbiRK9tagYYRECTii>
 *   @0x1303b0 add sp, sp, #24
 *   @0x1303b4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1303b8 ldr r0, [pc, #0x10]
 *   @0x1303bc mov r1, #0
 *   @0x1303c0 add r0, pc, r0
 *   @0x1303c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1303c8 add sp, sp, #24
 *   @0x1303cc pop {r4, r5, r6, r7, r8, pc}
 *   @0x1303d0 eoreq sp, r0, r12, lsl r12
 *
 * ══ §107/110 F_ActionPartTypeCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x13faa0  size 264  66 条（0x13faa0..0x13fba8）
 * @func 0x13faa0 0x13fba8  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetFloat(RValue const*, int)×3 / F_ActionPartTypeCreate(RValue&, CInstance*, CInstance*, int, RValue*)+0xec / F_ActionPartTypeCreate(RValue&, CInstance*, CInstance*, int, RValue*)+0xdc / ParticleType_Shape(int, int) / ParticleType_Sprite(int, int, bool, bool, bool) / ParticleType_Create() / ParticleSystem_Create(int, bool)
 * 字段偏移 top8: 0x30×2 / 0x2×2 / 0xec×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13faa0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13faa4 sub sp, sp, #12
 *   @0x13faa8 mov r1, #0
 *   @0x13faac ldr r5, [pc, #0xec]
 *   @0x13fab0 ldr r4, [sp, #0x30]
 *   @0x13fab4 mov r0, r4
 *   @0x13fab8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fabc mov r1, #1
 *   @0x13fac0 mov r6, r0
 *   @0x13fac4 mov r0, r4
 *   @0x13fac8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13facc mov r1, #2
 *   @0x13fad0 mov r10, r0
 *   @0x13fad4 mov r0, r4
 *   @0x13fad8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fadc mov r1, #3
 *   @0x13fae0 mov r9, r0
 *   @0x13fae4 mov r0, r4
 *   @0x13fae8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13faec mov r1, #4
 *   @0x13faf0 mov r8, r0
 *   @0x13faf4 mov r0, r4
 *   @0x13faf8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13fafc mov r1, #5
 *   @0x13fb00 mov r7, r0
 *   @0x13fb04 mov r0, r4
 *   @0x13fb08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13fb0c ldr r5, [pc, r5]
 *   @0x13fb10 ldr r3, [r5]
 *   @0x13fb14 cmp r3, #0
 *   @0x13fb18 mov r11, r0
 *   @0x13fb1c blt 0x13fb8c <_Z22F_ActionPartTypeCreateR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x13fb20 ldr r5, [pc, #0x7c]
 *   @0x13fb24 ldr r5, [pc, r5]
 *   @0x13fb28 ldr r4, [r5, r6, lsl #2]
 *   @0x13fb2c cmp r4, #0
 *   @0x13fb30 blt 0x13fb7c <_Z22F_ActionPartTypeCreateR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x13fb34 mov r1, r10
 *   @0x13fb38 mov r0, r4
 *   @0x13fb3c bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x13fb40 mov r3, #0
 *   @0x13fb44 mov r1, r9
 *   @0x13fb48 str r3, [sp]
 *   @0x13fb4c mov r0, r4
 *   @0x13fb50 mov r2, #1
 *   @0x13fb54 bl 0x1a31e0 <_Z19ParticleType_Spriteiibbb>
 *   @0x13fb58 mov r12, #0
 *   @0x13fb5c mov r0, r4
 *   @0x13fb60 mov r1, r8
 *   @0x13fb64 mov r2, r7
 *   @0x13fb68 mov r3, r11
 *   @0x13fb6c str r12, [sp, #0x30]
 *   @0x13fb70 add sp, sp, #12
 *   @0x13fb74 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13fb78 b 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x13fb7c bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x13fb80 mov r4, r0
 *   @0x13fb84 str r0, [r5, r6, lsl #2]
 *   @0x13fb88 b 0x13fb34 <_Z22F_ActionPartTypeCreateR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x13fb8c mvn r0, #0
 *   @0x13fb90 mov r1, #1
 *   @0x13fb94 bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x13fb98 str r0, [r5]
 *   @0x13fb9c b 0x13fb20 <_Z22F_ActionPartTypeCreateR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x13fba0 .word 0x002af8d0
 *   @0x13fba4 .word 0x002af8bc
 *
 * ══ §108/110 F_D3DDrawCylinder(RValue&, CInstance*, CInstance*, int, RValue*)  0x144204  size 264  66 条（0x144204..0x14430c）
 * @func 0x144204 0x14430c  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetPtrOrInt(RValue const*, int) / YYGetBool(RValue const*, int) / YYGetInt32(RValue const*, int) / GR_3D_Draw_Cylinder(float, float, float, float, float, float, int, float, float, bool, int)
 * 字段偏移 top8: 0x24×2 / 0x28×2 / 0x2c×2 / 0x58×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144204 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x144208 sub sp, sp, #52
 *   @0x14420c mov r1, #0
 *   @0x144210 ldr r4, [sp, #0x58]
 *   @0x144214 mov r0, r4
 *   @0x144218 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14421c mov r1, #1
 *   @0x144220 mov r5, r0
 *   @0x144224 mov r0, r4
 *   @0x144228 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14422c mov r1, #2
 *   @0x144230 mov r8, r0
 *   @0x144234 mov r0, r4
 *   @0x144238 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14423c mov r1, #3
 *   @0x144240 mov r7, r0
 *   @0x144244 mov r0, r4
 *   @0x144248 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14424c mov r1, #4
 *   @0x144250 mov r6, r0
 *   @0x144254 mov r0, r4
 *   @0x144258 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14425c mov r1, #5
 *   @0x144260 mov r12, r0
 *   @0x144264 mov r0, r4
 *   @0x144268 str r12, [sp, #0x24]
 *   @0x14426c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144270 mov r1, #6
 *   @0x144274 mov r2, r0
 *   @0x144278 mov r0, r4
 *   @0x14427c str r2, [sp, #0x28]
 *   @0x144280 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x144284 mov r1, #7
 *   @0x144288 mov r3, r0
 *   @0x14428c mov r0, r4
 *   @0x144290 str r3, [sp, #0x2c]
 *   @0x144294 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144298 mov r1, #8
 *   @0x14429c mov r11, r0
 *   @0x1442a0 mov r0, r4
 *   @0x1442a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1442a8 mov r1, #9
 *   @0x1442ac mov r10, r0
 *   @0x1442b0 mov r0, r4
 *   @0x1442b4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1442b8 mov r1, #10
 *   @0x1442bc mov r9, r0
 *   @0x1442c0 mov r0, r4
 *   @0x1442c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1442c8 ldr r2, [sp, #0x28]
 *   @0x1442cc ldr r3, [sp, #0x2c]
 *   @0x1442d0 mov r1, r8
 *   @0x1442d4 ldr r12, [sp, #0x24]
 *   @0x1442d8 str r2, [sp, #0x4]
 *   @0x1442dc mov r2, r7
 *   @0x1442e0 str r3, [sp, #0x8]
 *   @0x1442e4 mov r3, r6
 *   @0x1442e8 str r12, [sp]
 *   @0x1442ec str r11, [sp, #0xc]
 *   @0x1442f0 str r10, [sp, #0x10]
 *   @0x1442f4 str r9, [sp, #0x14]
 *   @0x1442f8 str r0, [sp, #0x18]
 *   @0x1442fc mov r0, r5
 *   @0x144300 bl 0x178d44 <_Z19GR_3D_Draw_Cylinderffffffiffbi>
 *   @0x144304 add sp, sp, #52
 *   @0x144308 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §109/110 F_D3DDrawCone(RValue&, CInstance*, CInstance*, int, RValue*)  0x14430c  size 264  66 条（0x14430c..0x144414）
 * @func 0x14430c 0x144414  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetPtrOrInt(RValue const*, int) / YYGetBool(RValue const*, int) / YYGetInt32(RValue const*, int) / GR_3D_Draw_Cone(float, float, float, float, float, float, int, float, float, bool, int)
 * 字段偏移 top8: 0x24×2 / 0x28×2 / 0x2c×2 / 0x58×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14430c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x144310 sub sp, sp, #52
 *   @0x144314 mov r1, #0
 *   @0x144318 ldr r4, [sp, #0x58]
 *   @0x14431c mov r0, r4
 *   @0x144320 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144324 mov r1, #1
 *   @0x144328 mov r5, r0
 *   @0x14432c mov r0, r4
 *   @0x144330 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144334 mov r1, #2
 *   @0x144338 mov r8, r0
 *   @0x14433c mov r0, r4
 *   @0x144340 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144344 mov r1, #3
 *   @0x144348 mov r7, r0
 *   @0x14434c mov r0, r4
 *   @0x144350 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144354 mov r1, #4
 *   @0x144358 mov r6, r0
 *   @0x14435c mov r0, r4
 *   @0x144360 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144364 mov r1, #5
 *   @0x144368 mov r12, r0
 *   @0x14436c mov r0, r4
 *   @0x144370 str r12, [sp, #0x24]
 *   @0x144374 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144378 mov r1, #6
 *   @0x14437c mov r2, r0
 *   @0x144380 mov r0, r4
 *   @0x144384 str r2, [sp, #0x28]
 *   @0x144388 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x14438c mov r1, #7
 *   @0x144390 mov r3, r0
 *   @0x144394 mov r0, r4
 *   @0x144398 str r3, [sp, #0x2c]
 *   @0x14439c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1443a0 mov r1, #8
 *   @0x1443a4 mov r11, r0
 *   @0x1443a8 mov r0, r4
 *   @0x1443ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1443b0 mov r1, #9
 *   @0x1443b4 mov r10, r0
 *   @0x1443b8 mov r0, r4
 *   @0x1443bc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1443c0 mov r1, #10
 *   @0x1443c4 mov r9, r0
 *   @0x1443c8 mov r0, r4
 *   @0x1443cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1443d0 ldr r2, [sp, #0x28]
 *   @0x1443d4 ldr r3, [sp, #0x2c]
 *   @0x1443d8 mov r1, r8
 *   @0x1443dc ldr r12, [sp, #0x24]
 *   @0x1443e0 str r2, [sp, #0x4]
 *   @0x1443e4 mov r2, r7
 *   @0x1443e8 str r3, [sp, #0x8]
 *   @0x1443ec mov r3, r6
 *   @0x1443f0 str r12, [sp]
 *   @0x1443f4 str r11, [sp, #0xc]
 *   @0x1443f8 str r10, [sp, #0x10]
 *   @0x1443fc str r9, [sp, #0x14]
 *   @0x144400 str r0, [sp, #0x18]
 *   @0x144404 mov r0, r5
 *   @0x144408 bl 0x179094 <_Z15GR_3D_Draw_Coneffffffiffbi>
 *   @0x14440c add sp, sp, #52
 *   @0x144410 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §110/110 InitRandom(unsigned int)  0xc4438  size 116  29 条（0xc4438..0xc44ac）
 * @func 0xc4438 0xc44ac  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x58×1 / 0x54×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4438 str r4, [sp, #-0x4]!
 *   @0xc443c movw r12, #0x43fd
 *   @0xc4440 ldr r4, [pc, #0x58]
 *   @0xc4444 movt r12, #0x3
 *   @0xc4448 ldr r1, [pc, #0x54]
 *   @0xc444c mov r3, r0
 *   @0xc4450 ldr r4, [pc, r4]
 *   @0xc4454 ldr r1, [pc, r1]
 *   @0xc4458 sub r2, r4, #4
 *   @0xc445c add r4, r4, #60
 *   @0xc4460 str r0, [r1]
 *   @0xc4464 mul r1, r12, r3
 *   @0xc4468 movw r3, #0x9ec3
 *   @0xc446c movt r3, #0x26
 *   @0xc4470 add r3, r1, r3
 *   @0xc4474 asr r3, r3, #16
 *   @0xc4478 bic r3, r3, #-2147483648
 *   @0xc447c str r3, [r2, #0x4]!
 *   @0xc4480 cmp r2, r4
 *   @0xc4484 bne 0xc4464 <_Z10InitRandomj+0x2c>
 *   @0xc4488 ldr r3, [pc, #0x18]
 *   @0xc448c mov r2, #0
 *   @0xc4490 ldr r4, [sp], #4
 *   @0xc4494 ldr r3, [pc, r3]
 *   @0xc4498 str r2, [r3]
 *   @0xc449c bx lr
 *   @0xc44a0 eorseq r9, r2, r4, lsl r5
 *   @0xc44a4 eorseq r9, r2, r4, lsl r5
 *   @0xc44a8 ldrsbteq r9, [r2], -r8
 */
