/* cally 逆向卡：Reach_10 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 31 个函数｜锚点 2063 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/31 CLayerManager::GetElementFromID  0x1bc2a0  size 280  70 条（0x1bc2a0..0x1bc3b8）
 * @func 0x1bc2a0 0x1bc3b8  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CHashMapCalculateHash(int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)+0xc4
 * 字段偏移 top8: 0x4×3 / 0x10c×2 / 0x8×2 / 0x100×1 / 0x108×1 / 0xf8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc2a0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1bc2a4 subs r9, r0, #0
 *   @0x1bc2a8 mov r10, r2
 *   @0x1bc2ac beq 0x1bc364 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xc4>
 *   @0x1bc2b0 ldr r0, [r9, #0x10c]
 *   @0x1bc2b4 cmp r0, #0
 *   @0x1bc2b8 beq 0x1bc2c8 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0x28>
 *   @0x1bc2bc ldr r3, [r0, #0x4]
 *   @0x1bc2c0 cmp r3, r1
 *   @0x1bc2c4 beq 0x1bc3a4 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0x104>
 *   @0x1bc2c8 mov r0, r1
 *   @0x1bc2cc bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1bc2d0 ldr r12, [r9, #0x100]
 *   @0x1bc2d4 ldr r8, [r9, #0x108]
 *   @0x1bc2d8 bic r0, r0, #-2147483648
 *   @0x1bc2dc and r3, r0, r12
 *   @0x1bc2e0 lsl r5, r3, #1
 *   @0x1bc2e4 add r2, r5, r3
 *   @0x1bc2e8 add r2, r8, r2, lsl #2
 *   @0x1bc2ec ldr r1, [r2, #0x8]
 *   @0x1bc2f0 cmp r1, #0
 *   @0x1bc2f4 beq 0x1bc364 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xc4>
 *   @0x1bc2f8 cmp r0, r1
 *   @0x1bc2fc beq 0x1bc374 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xd4>
 *   @0x1bc300 ldr r2, [r9, #0xf8]
 *   @0x1bc304 and r1, r12, r1
 *   @0x1bc308 add r4, r3, r2
 *   @0x1bc30c rsb r1, r1, r4
 *   @0x1bc310 tst r1, r12
 *   @0x1bc314 bmi 0x1bc364 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xc4>
 *   @0x1bc318 mov r4, #0
 *   @0x1bc31c b 0x1bc330 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0x90>
 *   @0x1bc320 cmp r0, r1
 *   @0x1bc324 beq 0x1bc36c <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xcc>
 *   @0x1bc328 cmp r6, r4
 *   @0x1bc32c blt 0x1bc364 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xc4>
 *   @0x1bc330 add r3, r3, #1
 *   @0x1bc334 add r4, r4, #1
 *   @0x1bc338 and r3, r12, r3
 *   @0x1bc33c add r7, r3, r2
 *   @0x1bc340 lsl r5, r3, #1
 *   @0x1bc344 add r1, r5, r3
 *   @0x1bc348 add r1, r8, r1, lsl #2
 *   @0x1bc34c ldr r1, [r1, #0x8]
 *   @0x1bc350 and r6, r12, r1
 *   @0x1bc354 cmp r1, #0
 *   @0x1bc358 rsb r6, r6, r7
 *   @0x1bc35c and r6, r6, r12
 *   @0x1bc360 bne 0x1bc320 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0x80>
 *   @0x1bc364 mov r0, #0
 *   @0x1bc368 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1bc36c cmn r3, #1
 *   @0x1bc370 beq 0x1bc364 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xc4>
 *   @0x1bc374 add r3, r5, r3
 *   @0x1bc378 add r8, r8, r3, lsl #2
 *   @0x1bc37c cmn r8, #4
 *   @0x1bc380 beq 0x1bc364 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer+0xc4>
 *   @0x1bc384 cmp r10, #0
 *   @0x1bc388 ldrne r3, [r8, #0x4]
 *   @0x1bc38c ldrne r3, [r3, #0x10]
 *   @0x1bc390 strne r3, [r10]
 *   @0x1bc394 ldr r3, [r8, #0x4]
 *   @0x1bc398 str r3, [r9, #0x10c]
 *   @0x1bc39c ldr r0, [r8, #0x4]
 *   @0x1bc3a0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1bc3a4 cmp r2, #0
 *   @0x1bc3a8 ldrne r3, [r0, #0x10]
 *   @0x1bc3ac strne r3, [r2]
 *   @0x1bc3b0 ldrne r0, [r9, #0x10c]
 *   @0x1bc3b4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §2/31 ProcessDebugPacket  0x29e50c  size 280  70 条（0x29e50c..0x29e624）
 * @func 0x29e50c 0x29e624  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x20×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29e50c push {r4, r5, r6, lr}
 *   @0x29e510 mov r5, r0
 *   @0x29e514 ldr r4, [r2, #0xc]
 *   @0x29e518 ldr r0, [r2, #0x10]
 *   @0x29e51c sub r12, r4, #1
 *   @0x29e520 cmp r12, #20
 *   @0x29e524 addls pc, pc, r12, lsl #2
 *   @0x29e528 b 0x29e5f4 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xe8>
 *   @0x29e52c b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80>
 *   @0x29e530 b 0x29e59c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x90>
 *   @0x29e534 b 0x29e5a8 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x9c>
 *   @0x29e538 b 0x29e5b4 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xa8>
 *   @0x29e53c b 0x29e5f4 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xe8>
 *   @0x29e540 b 0x29e5c0 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xb4>
 *   @0x29e544 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80>
 *   @0x29e548 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80>
 *   @0x29e54c b 0x29e5c8 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xbc>
 *   @0x29e550 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80>
 *   @0x29e554 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80>
 *   @0x29e558 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80>
 *   @0x29e55c b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80>
 *   @0x29e560 b 0x29e5d8 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xcc>
 *   @0x29e564 b 0x29e5e0 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xd4>
 *   @0x29e568 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80>
 *   @0x29e56c b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80>
 *   @0x29e570 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80>
 *   @0x29e574 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80>
 *   @0x29e578 b 0x29e5ec <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xe0>
 *   @0x29e57c b 0x29e580 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x74>
 *   @0x29e580 mov r0, r5
 *   @0x29e584 pop {r4, r5, r6, lr}
 *   @0x29e588 b 0x29fe4c <_Z17Debug_SendYYDebugP9DbgSocketP15Buffer_Standard>
 *   @0x29e58c mov r0, r4
 *   @0x29e590 mov r1, r5
 *   @0x29e594 pop {r4, r5, r6, lr}
 *   @0x29e598 b 0x29e22c <_Z13Debug_GetData15eNetworkCommandP9DbgSocketPhi>
 *   @0x29e59c mov r0, r5
 *   @0x29e5a0 pop {r4, r5, r6, lr}
 *   @0x29e5a4 b 0x29fb30 <_Z23Debug_SendGameStructureP9DbgSocketP15Buffer_Standard>
 *   @0x29e5a8 mov r0, #1
 *   @0x29e5ac pop {r4, r5, r6, lr}
 *   @0x29e5b0 b 0x29c648 <_Z21Debug_StartStopTargetb>
 *   @0x29e5b4 mov r0, #0
 *   @0x29e5b8 pop {r4, r5, r6, lr}
 *   @0x29e5bc b 0x29c648 <_Z21Debug_StartStopTargetb>
 *   @0x29e5c0 pop {r4, r5, r6, lr}
 *   @0x29e5c4 b 0x29c780 <_Z18Debug_DoSingleStepi>
 *   @0x29e5c8 mov r0, r2
 *   @0x29e5cc mov r1, r3
 *   @0x29e5d0 pop {r4, r5, r6, lr}
 *   @0x29e5d4 b 0x29c888 <_Z20Debug_SetBreakpointsPhi>
 *   @0x29e5d8 pop {r4, r5, r6, lr}
 *   @0x29e5dc b 0x29c6bc <_Z19Debug_RestartTargetv>
 *   @0x29e5e0 mov r0, r5
 *   @0x29e5e4 pop {r4, r5, r6, lr}
 *   @0x29e5e8 b 0x29d9bc <_Z25Debug_GetSelectedInstanceP9DbgSocket>
 *   @0x29e5ec pop {r4, r5, r6, lr}
 *   @0x29e5f0 b 0x29c6dc <_Z18Debug_QuitDebuggerv>
 *   @0x29e5f4 ldr r3, [pc, #0x20]
 *   @0x29e5f8 mov r2, r4
 *   @0x29e5fc ldr r1, [pc, #0x1c]
 *   @0x29e600 ldr r3, [pc, r3]
 *   @0x29e604 add r1, pc, r1
 *   @0x29e608 ldr r0, [r3]
 *   @0x29e60c ldr r3, [r0]
 *   @0x29e610 ldr r3, [r3, #0xc]
 *   @0x29e614 blx r3
 *   @0x29e618 pop {r4, r5, r6, pc}
 *   @0x29e61c andseq pc, r4, r0, asr #6
 *   @0x29e620 muleq r11, r0, r5
 *
 * ══ §3/31 b2DynamicTree::MoveProxy  0x2df660  size 280  70 条（0x2df660..0x2df778）
 * @func 0x2df660 0x2df778  size 280  70 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::MoveProxy(int, b2AABB const&, b2Vec2 const&)+0xdc / b2DynamicTree::RemoveLeaf(int) / b2DynamicTree::InsertLeaf(int)
 * 字段偏移 top8: 0x4×2
 * VFP 指令 42 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2df660 push {r4, r5, r6, r7, r8, lr}
 *   @0x2df664 vldr s15, [r2]
 *   @0x2df668 add r8, r1, r1, lsl #3
 *   @0x2df66c mov r5, r1
 *   @0x2df670 ldr r1, [r0, #0x4]
 *   @0x2df674 lsl r8, r8, #2
 *   @0x2df678 mov r4, r2
 *   @0x2df67c add r2, r1, r8
 *   @0x2df680 vldr s14, [r2]
 *   @0x2df684 vcmpe.f32 s14, s15
 *   @0x2df688 mov r6, r0
 *   @0x2df68c mov r7, r3
 *   @0x2df690 vmrs APSR_nzcv, fpscr
 *   @0x2df694 bhi 0x2df6ac <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2+0x4c>
 *   @0x2df698 vldr s14, [r2, #4]
 *   @0x2df69c vldr s15, [r4, #4]
 *   @0x2df6a0 vcmpe.f32 s14, s15
 *   @0x2df6a4 vmrs APSR_nzcv, fpscr
 *   @0x2df6a8 bls 0x2df73c <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2+0xdc>
 *   @0x2df6ac mov r0, r6
 *   @0x2df6b0 mov r1, r5
 *   @0x2df6b4 bl 0x2df4e8 <_ZN13b2DynamicTree10RemoveLeafEi>
 *   @0x2df6b8 vldr s15, [r7]
 *   @0x2df6bc vadd.f32 s14, s15, s15
 *   @0x2df6c0 vldr s12, [r4]
 *   @0x2df6c4 vldr s15, [pc, #168]
 *   @0x2df6c8 vldr s13, [r4, #8]
 *   @0x2df6cc vldr s10, [r4, #4]
 *   @0x2df6d0 vldr s9, [r4, #12]
 *   @0x2df6d4 vldr s11, [r7, #4]
 *   @0x2df6d8 vsub.f32 s12, s12, s15
 *   @0x2df6dc vadd.f32 s15, s13, s15
 *   @0x2df6e0 vcmpe.f32 s14, #0
 *   @0x2df6e4 vmrs APSR_nzcv, fpscr
 *   @0x2df6e8 vaddpl.f32 s15, s15, s14
 *   @0x2df6ec bmi 0x2df76c <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2+0x10c>
 *   @0x2df6f0 vldr s14, [pc, #124]
 *   @0x2df6f4 ldr r3, [r6, #0x4]
 *   @0x2df6f8 mov r0, r6
 *   @0x2df6fc mov r1, r5
 *   @0x2df700 add r8, r3, r8
 *   @0x2df704 vstr s12, [r8]
 *   @0x2df708 vstr s15, [r8, #8]
 *   @0x2df70c vadd.f32 s11, s11, s11
 *   @0x2df710 vsub.f32 s10, s10, s14
 *   @0x2df714 vadd.f32 s14, s9, s14
 *   @0x2df718 vcmpe.f32 s11, #0
 *   @0x2df71c vmrs APSR_nzcv, fpscr
 *   @0x2df720 vaddmi.f32 s10, s10, s11
 *   @0x2df724 vaddpl.f32 s14, s14, s11
 *   @0x2df728 vstr s10, [r8, #4]
 *   @0x2df72c vstr s14, [r8, #12]
 *   @0x2df730 bl 0x2defd0 <_ZN13b2DynamicTree10InsertLeafEi>
 *   @0x2df734 mov r0, #1
 *   @0x2df738 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2df73c vldr s14, [r4, #8]
 *   @0x2df740 vldr s15, [r2, #8]
 *   @0x2df744 vcmpe.f32 s14, s15
 *   @0x2df748 vmrs APSR_nzcv, fpscr
 *   @0x2df74c bhi 0x2df6ac <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2+0x4c>
 *   @0x2df750 vldr s14, [r4, #12]
 *   @0x2df754 vldr s15, [r2, #12]
 *   @0x2df758 vcmpe.f32 s14, s15
 *   @0x2df75c vmrs APSR_nzcv, fpscr
 *   @0x2df760 bhi 0x2df6ac <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2+0x4c>
 *   @0x2df764 mov r0, #0
 *   @0x2df768 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2df76c vadd.f32 s12, s12, s14
 *   @0x2df770 b 0x2df6f0 <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2+0x90>
 *   @0x2df774 stcllo p12, c12, [r12, #820]
 *
 * ══ §4/31 Shader_Set_Uniform_B  0x188b90  size 276  69 条（0x188b90..0x188ca4）
 * @func 0x188b90 0x188ca4  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Set_Uniform_B(int, int, double, double, double, double)+0x28 / Shader_Get(int) / Shader_Set_Uniform_B(int, int, double, double, double, double)+0xec / Shader_Set_Uniform_I(int, int, int, int*)
 * 字段偏移 top8: 0x4×3 / 0x104×1 / 0xc8×1 / 0x64×1 / 0x7c×1 / 0x78×1 / 0xc×1 / 0x14×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188b90 ldr r12, [pc, #0x104]
 *   @0x188b94 push {r4, lr}
 *   @0x188b98 vpush {d8}
 *   @0x188b9c ldr r12, [pc, r12]
 *   @0x188ba0 vmov d8, r2, r3
 *   @0x188ba4 sub sp, sp, #24
 *   @0x188ba8 ldr r3, [r12]
 *   @0x188bac mov r4, r0
 *   @0x188bb0 cmp r3, #1
 *   @0x188bb4 beq 0x188bc8 <_Z20Shader_Set_Uniform_Biidddd+0x38>
 *   @0x188bb8 mov r0, #0
 *   @0x188bbc add sp, sp, #24
 *   @0x188bc0 vpop {d8}
 *   @0x188bc4 pop {r4, pc}
 *   @0x188bc8 cmp r0, #0
 *   @0x188bcc blt 0x188bb8 <_Z20Shader_Set_Uniform_Biidddd+0x28>
 *   @0x188bd0 ldr r3, [pc, #0xc8]
 *   @0x188bd4 ldr r3, [pc, r3]
 *   @0x188bd8 ldr r3, [r3]
 *   @0x188bdc cmp r3, #0
 *   @0x188be0 beq 0x188bb8 <_Z20Shader_Set_Uniform_Biidddd+0x28>
 *   @0x188be4 ldr r0, [r3, #0x64]
 *   @0x188be8 str r1, [sp, #0x4]
 *   @0x188bec bl 0x187e70 <_Z10Shader_Geti>
 *   @0x188bf0 ldr r1, [sp, #0x4]
 *   @0x188bf4 cmp r0, #0
 *   @0x188bf8 beq 0x188bb8 <_Z20Shader_Set_Uniform_Biidddd+0x28>
 *   @0x188bfc ldr r3, [r0, #0x7c]
 *   @0x188c00 cmp r4, r3
 *   @0x188c04 bge 0x188bb8 <_Z20Shader_Set_Uniform_Biidddd+0x28>
 *   @0x188c08 ldr r3, [r0, #0x78]
 *   @0x188c0c rsb r4, r4, r4, lsl #3
 *   @0x188c10 adds r4, r3, r4, lsl #2
 *   @0x188c14 beq 0x188bb8 <_Z20Shader_Set_Uniform_Biidddd+0x28>
 *   @0x188c18 vcvt.s32.f64 s16, d8
 *   @0x188c1c ldr r2, [r4, #0xc]
 *   @0x188c20 mov r3, #0
 *   @0x188c24 str r3, [sp, #0x14]
 *   @0x188c28 cmp r1, r2
 *   @0x188c2c movge r1, r2
 *   @0x188c30 str r3, [sp, #0x10]
 *   @0x188c34 cmp r1, #1
 *   @0x188c38 strle r3, [sp, #0xc]
 *   @0x188c3c vstr s16, [sp, #8]
 *   @0x188c40 ble 0x188c7c <_Z20Shader_Set_Uniform_Biidddd+0xec>
 *   @0x188c44 vldr d7, [sp, #40]
 *   @0x188c48 vcvt.s32.f64 s15, d7
 *   @0x188c4c cmp r1, #2
 *   @0x188c50 vstr s15, [sp, #12]
 *   @0x188c54 beq 0x188c7c <_Z20Shader_Set_Uniform_Biidddd+0xec>
 *   @0x188c58 vldr d7, [sp, #48]
 *   @0x188c5c vcvt.s32.f64 s15, d7
 *   @0x188c60 cmp r1, #3
 *   @0x188c64 vmov r3, s15
 *   @0x188c68 vstr s15, [sp, #16]
 *   @0x188c6c vldrne d7, [sp, #56]
 *   @0x188c70 vcvtne.s32.f64 s15, d7
 *   @0x188c74 vmovne r3, s15
 *   @0x188c78 strne r3, [sp, #0x14]
 *   @0x188c7c ldr r0, [r4, #0x4]
 *   @0x188c80 mov r2, #1
 *   @0x188c84 add r3, sp, #8
 *   @0x188c88 bl 0x188200 <_Z20Shader_Set_Uniform_IiiiPi>
 *   @0x188c8c mov r0, #1
 *   @0x188c90 add sp, sp, #24
 *   @0x188c94 vpop {d8}
 *   @0x188c98 pop {r4, pc}
 *   @0x188c9c eoreq r7, r6, r12, ror #16
 *   @0x188ca0 eoreq r7, r6, r4, lsr #17
 *
 * ══ §5/31 JS_CanPut  0x241cac  size 276  69 条（0x241cac..0x241dc0）
 * @func 0x241cac 0x241dc0  size 276  69 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_IsAccessorDescriptor(RValue*)×2 / JS_GetOwnProperty(YYObjectBase*, RValue*, char const*) / JS_GetProperty(YYObjectBase*, RValue*, char const*) / YYObjectBase::IsExtensible() / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0xc×3 / 0x18×2 / 0x1c×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x241cac push {r4, r5, r6, lr}
 *   @0x241cb0 sub sp, sp, #32
 *   @0x241cb4 mov r2, r1
 *   @0x241cb8 mov r4, r1
 *   @0x241cbc mov r1, sp
 *   @0x241cc0 mov r3, #5
 *   @0x241cc4 mov r5, r0
 *   @0x241cc8 str r3, [sp, #0xc]
 *   @0x241ccc bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x241cd0 ldr r3, [sp, #0xc]
 *   @0x241cd4 bic r3, r3, #-16777216
 *   @0x241cd8 cmp r3, #5
 *   @0x241cdc beq 0x241d30 <_Z9JS_CanPutP12YYObjectBasePKc+0x84>
 *   @0x241ce0 mvn r2, #-16777216
 *   @0x241ce4 cmp r3, r2
 *   @0x241ce8 beq 0x241d30 <_Z9JS_CanPutP12YYObjectBasePKc+0x84>
 *   @0x241cec mov r0, sp
 *   @0x241cf0 bl 0x240828 <_Z23JS_IsAccessorDescriptorP6RValue>
 *   @0x241cf4 cmp r0, #0
 *   @0x241cf8 beq 0x241da4 <_Z9JS_CanPutP12YYObjectBasePKc+0xf8>
 *   @0x241cfc ldr r0, [sp]
 *   @0x241d00 ldr r3, [r0, #0x4]
 *   @0x241d04 cmp r3, #0
 *   @0x241d08 beq 0x241db4 <_Z9JS_CanPutP12YYObjectBasePKc+0x108>
 *   @0x241d0c add r0, r3, #16
 *   @0x241d10 ldr r0, [r0, #0xc]
 *   @0x241d14 mvn r3, #-16777216
 *   @0x241d18 cmp r0, r3
 *   @0x241d1c cmpne r0, #5
 *   @0x241d20 moveq r0, #0
 *   @0x241d24 movne r0, #1
 *   @0x241d28 add sp, sp, #32
 *   @0x241d2c pop {r4, r5, r6, pc}
 *   @0x241d30 ldr r3, [r5, #0x18]
 *   @0x241d34 cmp r3, #0
 *   @0x241d38 beq 0x241d94 <_Z9JS_CanPutP12YYObjectBasePKc+0xe8>
 *   @0x241d3c add r6, sp, #16
 *   @0x241d40 mov r2, r4
 *   @0x241d44 mov r0, r5
 *   @0x241d48 mov r3, #5
 *   @0x241d4c mov r1, r6
 *   @0x241d50 str r3, [sp, #0x1c]
 *   @0x241d54 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x241d58 ldr r3, [sp, #0x1c]
 *   @0x241d5c bic r3, r3, #-16777216
 *   @0x241d60 cmp r3, #5
 *   @0x241d64 beq 0x241d94 <_Z9JS_CanPutP12YYObjectBasePKc+0xe8>
 *   @0x241d68 mvn r2, #-16777216
 *   @0x241d6c cmp r3, r2
 *   @0x241d70 beq 0x241d94 <_Z9JS_CanPutP12YYObjectBasePKc+0xe8>
 *   @0x241d74 mov r0, r6
 *   @0x241d78 bl 0x240828 <_Z23JS_IsAccessorDescriptorP6RValue>
 *   @0x241d7c cmp r0, #0
 *   @0x241d80 bne 0x241d94 <_Z9JS_CanPutP12YYObjectBasePKc+0xe8>
 *   @0x241d84 ldr r0, [sp, #0x18]
 *   @0x241d88 ubfx r0, r0, #0x2, #0x1
 *   @0x241d8c add sp, sp, #32
 *   @0x241d90 pop {r4, r5, r6, pc}
 *   @0x241d94 mov r0, r5
 *   @0x241d98 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv>
 *   @0x241d9c add sp, sp, #32
 *   @0x241da0 pop {r4, r5, r6, pc}
 *   @0x241da4 ldr r0, [sp, #0x8]
 *   @0x241da8 ubfx r0, r0, #0x2, #0x1
 *   @0x241dac add sp, sp, #32
 *   @0x241db0 pop {r4, r5, r6, pc}
 *   @0x241db4 mov r1, #1
 *   @0x241db8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x241dbc b 0x241d10 <_Z9JS_CanPutP12YYObjectBasePKc+0x64>
 *
 * ══ §6/31 VM::DebugLine  0xec1a8  size 272  68 条（0xec1a8..0xec2b8）
 * @func 0xec1a8 0xec2b8  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_extract_char×2 / utf8_strlen / VM::DebugLine(VMDebugInfo*, char const*)+0xdc / utf8_add_char / VM::DebugLine(VMDebugInfo*, char const*)+0x84
 * 字段偏移 top8: 0x4×4 / 0x9c×1 / 0x84×1 / 0x44×1 / 0x30×1 / 0x24×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec1a8 push {r4, r5, r6, r7, lr}
 *   @0xec1ac subs r4, r0, #0
 *   @0xec1b0 sub sp, sp, #12
 *   @0xec1b4 mov r7, r1
 *   @0xec1b8 beq 0xec274 <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0xcc>
 *   @0xec1bc mov r0, r1
 *   @0xec1c0 bl 0x110648 <utf8_strlen>
 *   @0xec1c4 ldr r6, [r4, #0x4]
 *   @0xec1c8 str r7, [sp]
 *   @0xec1cc cmp r0, r6
 *   @0xec1d0 sublt r6, r0, #1
 *   @0xec1d4 cmp r6, #0
 *   @0xec1d8 ble 0xec284 <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0xdc>
 *   @0xec1dc mov r4, #0
 *   @0xec1e0 mov r0, sp
 *   @0xec1e4 add r4, r4, #1
 *   @0xec1e8 bl 0x10fb38 <utf8_extract_char>
 *   @0xec1ec cmp r0, #10
 *   @0xec1f0 ldreq r7, [sp]
 *   @0xec1f4 cmp r4, r6
 *   @0xec1f8 bne 0xec1e0 <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0x38>
 *   @0xec1fc ldr r3, [pc, #0x9c]
 *   @0xec200 str r7, [sp]
 *   @0xec204 add r3, pc, r3
 *   @0xec208 str r3, [sp, #0x4]
 *   @0xec20c ldrb r3, [r7]
 *   @0xec210 cmp r3, #10
 *   @0xec214 beq 0xec294 <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0xec>
 *   @0xec218 ldr r4, [pc, #0x84]
 *   @0xec21c add r6, sp, #4
 *   @0xec220 add r4, pc, r4
 *   @0xec224 add r4, r4, #255
 *   @0xec228 b 0xec23c <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0x94>
 *   @0xec22c ldr r2, [sp]
 *   @0xec230 ldrb r2, [r2]
 *   @0xec234 cmp r2, #10
 *   @0xec238 beq 0xec25c <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0xb4>
 *   @0xec23c mov r0, sp
 *   @0xec240 bl 0x10fb38 <utf8_extract_char>
 *   @0xec244 mov r1, r0
 *   @0xec248 mov r0, r6
 *   @0xec24c bl 0x10fe28 <utf8_add_char>
 *   @0xec250 ldr r3, [sp, #0x4]
 *   @0xec254 cmp r3, r4
 *   @0xec258 blo 0xec22c <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0x84>
 *   @0xec25c ldr r0, [pc, #0x44]
 *   @0xec260 mov r2, #0
 *   @0xec264 strb r2, [r3]
 *   @0xec268 add r0, pc, r0
 *   @0xec26c add sp, sp, #12
 *   @0xec270 pop {r4, r5, r6, r7, pc}
 *   @0xec274 ldr r0, [pc, #0x30]
 *   @0xec278 add r0, pc, r0
 *   @0xec27c add sp, sp, #12
 *   @0xec280 pop {r4, r5, r6, r7, pc}
 *   @0xec284 ldr r3, [pc, #0x24]
 *   @0xec288 add r3, pc, r3
 *   @0xec28c str r3, [sp, #0x4]
 *   @0xec290 b 0xec20c <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0x64>
 *   @0xec294 ldr r3, [pc, #0x18]
 *   @0xec298 add r3, pc, r3
 *   @0xec29c b 0xec25c <_ZN2VM9DebugLineEP11VMDebugInfoPKc+0xb4>
 *   @0xec2a0 mlaseq r9, r4, r0, r3
 *   @0xec2a4 eorseq r3, r9, r8, ror r0
 *   @0xec2a8 eorseq r3, r9, r0, lsr r0
 *   @0xec2ac .word 0x002488b8
 *   @0xec2b0 eorseq r3, r9, r0, lsl r0
 *   @0xec2b4 eorseq r3, r9, r0
 *
 * ══ §7/31 CCameraManager::DeSerialize  0x16f34c  size 272  68 条（0x16f34c..0x16f45c）
 * @func 0x16f34c 0x16f45c  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCamera::GetID()×2 / CCameraManager::DeSerialize(IBuffer*)+0x40 / CCameraManager::DestroyCamera(int) / YYGetInt32(RValue const*, int) / CCameraManager::DeSerialize(IBuffer*)+0x104 / YYGetBool(RValue const*, int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CCamera::CCamera()
 * 字段偏移 top8: 0xc×3 / 0x14×1 / 0x94×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f34c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x16f350 mov r6, r0
 *   @0x16f354 ldr r7, [r0, #0x14]
 *   @0x16f358 mov r5, r1
 *   @0x16f35c cmp r7, #0
 *   @0x16f360 movgt r4, #0
 *   @0x16f364 ble 0x16f38c <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x40>
 *   @0x16f368 ldr r3, [r6, #0xc]
 *   @0x16f36c add r4, r4, #1
 *   @0x16f370 ldr r0, [r3]
 *   @0x16f374 bl 0x16d12c <_ZN7CCamera5GetIDEv>
 *   @0x16f378 mov r1, r0
 *   @0x16f37c mov r0, r6
 *   @0x16f380 bl 0x16f2cc <_ZN14CCameraManager13DestroyCameraEi>
 *   @0x16f384 cmp r4, r7
 *   @0x16f388 bne 0x16f368 <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x1c>
 *   @0x16f38c ldr r3, [r5]
 *   @0x16f390 add r7, r5, #44
 *   @0x16f394 mov r1, #6
 *   @0x16f398 mov r0, r5
 *   @0x16f39c mov r2, r7
 *   @0x16f3a0 ldr r3, [r3, #0xc]
 *   @0x16f3a4 blx r3
 *   @0x16f3a8 mov r0, r7
 *   @0x16f3ac mov r1, #0
 *   @0x16f3b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f3b4 subs r8, r0, #0
 *   @0x16f3b8 ble 0x16f450 <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x104>
 *   @0x16f3bc ldr r9, [pc, #0x94]
 *   @0x16f3c0 mov r4, #0
 *   @0x16f3c4 add r9, pc, r9
 *   @0x16f3c8 b 0x16f3d4 <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x88>
 *   @0x16f3cc cmp r4, r8
 *   @0x16f3d0 beq 0x16f450 <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x104>
 *   @0x16f3d4 ldr r3, [r5]
 *   @0x16f3d8 mov r1, #6
 *   @0x16f3dc mov r2, r7
 *   @0x16f3e0 mov r0, r5
 *   @0x16f3e4 add r4, r4, #1
 *   @0x16f3e8 ldr r3, [r3, #0xc]
 *   @0x16f3ec blx r3
 *   @0x16f3f0 mov r0, r7
 *   @0x16f3f4 mov r1, #0
 *   @0x16f3f8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x16f3fc cmp r0, #0
 *   @0x16f400 beq 0x16f3cc <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x80>
 *   @0x16f404 mov r0, #444
 *   @0x16f408 mov r1, r9
 *   @0x16f40c movw r2, #0x7f5
 *   @0x16f410 mov r3, #1
 *   @0x16f414 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x16f418 subs r10, r0, #0
 *   @0x16f41c beq 0x16f424 <_ZN14CCameraManager11DeSerializeEP7IBuffer+0xd8>
 *   @0x16f420 bl 0x16cfc0 <_ZN7CCameraC2Ev>
 *   @0x16f424 mov r1, r5
 *   @0x16f428 mov r0, r10
 *   @0x16f42c bl 0x16e95c <_ZN7CCamera11DeSerializeEP7IBuffer>
 *   @0x16f430 mov r0, r10
 *   @0x16f434 bl 0x16d12c <_ZN7CCamera5GetIDEv>
 *   @0x16f438 mov r1, r10
 *   @0x16f43c mov r2, r0
 *   @0x16f440 mov r0, r6
 *   @0x16f444 bl 0x16ed1c <_ZN14CCameraManager15AddCameraToListEP7CCamerai>
 *   @0x16f448 cmp r4, r8
 *   @0x16f44c bne 0x16f3d4 <_ZN14CCameraManager11DeSerializeEP7IBuffer+0x88>
 *   @0x16f450 mov r0, #1
 *   @0x16f454 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x16f458 mulseq sp, r4, r4
 *
 * ══ §8/31 CInstance::RelinkObjectTypes  0x192bc4  size 272  68 条（0x192bc4..0x192cd4）
 * @func 0x192bc4 0x192cd4  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CObjectGM::RemoveInstance(CInstance*) / CObjectGM::AddInstance(CInstance*)
 * 字段偏移 top8: 0x17c×5 / 0x80×4 / 0x178×4 / 0x168×2 / 0x69×1 / 0xc8×1 / 0x180×1 / 0x84×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x192bc4 push {r4, lr}
 *   @0x192bc8 mov r4, r0
 *   @0x192bcc ldr r0, [r0, #0x168]
 *   @0x192bd0 cmp r0, #0
 *   @0x192bd4 beq 0x192be0 <_ZN9CInstance17RelinkObjectTypesEv+0x1c>
 *   @0x192bd8 mov r1, r4
 *   @0x192bdc bl 0x19e0fc <_ZN9CObjectGM14RemoveInstanceEP9CInstance>
 *   @0x192be0 mov r3, #0
 *   @0x192be4 ldr r0, [r4, #0x80]
 *   @0x192be8 str r3, [r4, #0x168]
 *   @0x192bec mov r1, r4
 *   @0x192bf0 bl 0x19e02c <_ZN9CObjectGM11AddInstanceEP9CInstance>
 *   @0x192bf4 ldrb r3, [r4, #0x69]
 *   @0x192bf8 cmp r3, #0
 *   @0x192bfc popne {r4, pc}
 *   @0x192c00 ldr r2, [pc, #0xc8]
 *   @0x192c04 ldr r3, [r4, #0x17c]
 *   @0x192c08 ldr r1, [r4, #0x178]
 *   @0x192c0c ldr r2, [pc, r2]
 *   @0x192c10 cmp r3, #0
 *   @0x192c14 ldr r2, [r2]
 *   @0x192c18 strne r1, [r3, #0x178]
 *   @0x192c1c ldrne r1, [r4, #0x178]
 *   @0x192c20 ldrne r3, [r4, #0x17c]
 *   @0x192c24 streq r1, [r2, #0x80]
 *   @0x192c28 cmp r1, #0
 *   @0x192c2c streq r3, [r2, #0x84]
 *   @0x192c30 strne r3, [r1, #0x17c]
 *   @0x192c34 mov r1, #0
 *   @0x192c38 ldrne r3, [r2, #0x84]
 *   @0x192c3c str r1, [r4, #0x178]
 *   @0x192c40 cmp r3, #0
 *   @0x192c44 str r1, [r4, #0x17c]
 *   @0x192c48 vldrne s14, [r4, #384]
 *   @0x192c4c beq 0x192cbc <_ZN9CInstance17RelinkObjectTypesEv+0xf8>
 *   @0x192c50 vldr s15, [r3, #388]
 *   @0x192c54 vcmpe.f32 s14, s15
 *   @0x192c58 vmrs APSR_nzcv, fpscr
 *   @0x192c5c bge 0x192c88 <_ZN9CInstance17RelinkObjectTypesEv+0xc4>
 *   @0x192c60 ldr r3, [r3, #0x17c]
 *   @0x192c64 cmp r3, #0
 *   @0x192c68 bne 0x192c50 <_ZN9CInstance17RelinkObjectTypesEv+0x8c>
 *   @0x192c6c ldr r1, [r2, #0x80]
 *   @0x192c70 vstr s14, [r4, #388]
 *   @0x192c74 str r4, [r1, #0x17c]
 *   @0x192c78 str r1, [r4, #0x178]
 *   @0x192c7c str r4, [r2, #0x80]
 *   @0x192c80 str r3, [r4, #0x17c]
 *   @0x192c84 pop {r4, pc}
 *   @0x192c88 ldr r1, [r3, #0x178]
 *   @0x192c8c cmp r1, #0
 *   @0x192c90 streq r3, [r4, #0x17c]
 *   @0x192c94 strne r1, [r4, #0x178]
 *   @0x192c98 ldrne r2, [r3, #0x178]
 *   @0x192c9c streq r4, [r3, #0x178]
 *   @0x192ca0 strne r3, [r4, #0x17c]
 *   @0x192ca4 streq r4, [r2, #0x84]
 *   @0x192ca8 strne r4, [r2, #0x17c]
 *   @0x192cac streq r1, [r4, #0x178]
 *   @0x192cb0 strne r4, [r3, #0x178]
 *   @0x192cb4 vstr s14, [r4, #388]
 *   @0x192cb8 pop {r4, pc}
 *   @0x192cbc ldr r3, [r4, #0x180]
 *   @0x192cc0 str r4, [r2, #0x84]
 *   @0x192cc4 str r4, [r2, #0x80]
 *   @0x192cc8 str r3, [r4, #0x184]
 *   @0x192ccc pop {r4, pc}
 *   @0x192cd0 eoreq r10, r5, r12, lsl sp
 *
 * ══ §9/31 CDS_Map::~CDS_Map  0x20d9e8  size 272  68 条（0x20d9e8..0x20daf8）
 * @func 0x20d9e8 0x20daf8  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×2 / operator delete(void*)×2 / MemoryManager::Free(void const*)×2 / CDS_Map::Clear() / CDS_Map::~CDS_Map()+0xec
 * 字段偏移 top8: 0x4×5 / 0xc×3 / 0x8×3 / 0x1c×2 / 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20d9e8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20d9ec sub sp, sp, #12
 *   @0x20d9f0 str r0, [sp, #0x4]
 *   @0x20d9f4 bl 0x20daf8 <_ZN7CDS_Map5ClearEv>
 *   @0x20d9f8 ldr r3, [sp, #0x4]
 *   @0x20d9fc ldr r11, [r3]
 *   @0x20da00 cmp r11, #0
 *   @0x20da04 beq 0x20dae0 <_ZN7CDS_MapD2Ev+0xf8>
 *   @0x20da08 ldm r11, {r0, r10}
 *   @0x20da0c cmp r10, #0
 *   @0x20da10 lslge r8, r10, #3
 *   @0x20da14 movge r7, #0
 *   @0x20da18 movge r9, #5
 *   @0x20da1c blt 0x20dad4 <_ZN7CDS_MapD2Ev+0xec>
 *   @0x20da20 ldr r4, [r0, r8]
 *   @0x20da24 add r2, r0, r8
 *   @0x20da28 str r7, [r0, r8]
 *   @0x20da2c cmp r4, #0
 *   @0x20da30 str r7, [r2, #0x4]
 *   @0x20da34 beq 0x20dac4 <_ZN7CDS_MapD2Ev+0xdc>
 *   @0x20da38 ldr r5, [r4, #0xc]
 *   @0x20da3c ldr r6, [r4, #0x4]
 *   @0x20da40 cmp r5, #0
 *   @0x20da44 beq 0x20daa0 <_ZN7CDS_MapD2Ev+0xb8>
 *   @0x20da48 ldr r2, [r5, #0xc]
 *   @0x20da4c sub r2, r2, #1
 *   @0x20da50 bic r2, r2, #-16777216
 *   @0x20da54 bic r2, r2, #3
 *   @0x20da58 cmp r2, #0
 *   @0x20da5c beq 0x20daec <_ZN7CDS_MapD2Ev+0x104>
 *   @0x20da60 ldr r2, [r5, #0x1c]
 *   @0x20da64 str r7, [r5, #0x8]
 *   @0x20da68 sub r2, r2, #1
 *   @0x20da6c str r9, [r5, #0xc]
 *   @0x20da70 bic r2, r2, #-16777216
 *   @0x20da74 str r7, [r5]
 *   @0x20da78 bic r2, r2, #3
 *   @0x20da7c cmp r2, #0
 *   @0x20da80 bne 0x20da8c <_ZN7CDS_MapD2Ev+0xa4>
 *   @0x20da84 add r0, r5, #16
 *   @0x20da88 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20da8c str r7, [r5, #0x18]
 *   @0x20da90 mov r0, r5
 *   @0x20da94 str r9, [r5, #0x1c]
 *   @0x20da98 str r7, [r5, #0x10]
 *   @0x20da9c bl 0x27d1d0 <_ZdlPv>
 *   @0x20daa0 mov r0, r4
 *   @0x20daa4 mov r4, r6
 *   @0x20daa8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x20daac ldr r2, [r11, #0x8]
 *   @0x20dab0 cmp r6, #0
 *   @0x20dab4 sub r2, r2, #1
 *   @0x20dab8 str r2, [r11, #0x8]
 *   @0x20dabc bne 0x20da38 <_ZN7CDS_MapD2Ev+0x50>
 *   @0x20dac0 ldr r0, [r11]
 *   @0x20dac4 sub r10, r10, #1
 *   @0x20dac8 sub r8, r8, #8
 *   @0x20dacc cmn r10, #1
 *   @0x20dad0 bne 0x20da20 <_ZN7CDS_MapD2Ev+0x38>
 *   @0x20dad4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x20dad8 mov r0, r11
 *   @0x20dadc bl 0x27d1d0 <_ZdlPv>
 *   @0x20dae0 ldr r0, [sp, #0x4]
 *   @0x20dae4 add sp, sp, #12
 *   @0x20dae8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20daec mov r0, r5
 *   @0x20daf0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20daf4 b 0x20da60 <_ZN7CDS_MapD2Ev+0x78>
 *
 * ══ §10/31 b2ParticleSystem::SolveSolid  0x2d6330  size 272  68 条（0x2d6330..0x2d6440）
 * @func 0x2d6330 0x2d6440  size 272  68 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / 0xb65b0
 * 字段偏移 top8: 0x50×2 / 0x2×2 / 0x28×2 / 0x74×1 / 0x7c×1 / 0x5c×1 / 0x-c×1 / 0x-8×1
 * VFP 指令 25 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d6330 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2d6334 mov r7, r0
 *   @0x2d6338 ldr r5, [r0, #0x50]
 *   @0x2d633c mov r4, r1
 *   @0x2d6340 cmp r5, #0
 *   @0x2d6344 beq 0x2d6418 <_ZN16b2ParticleSystem10SolveSolidERK10b2TimeStep+0xe8>
 *   @0x2d6348 ldr r8, [r7, #0x74]
 *   @0x2d634c vldr s9, [r4, #4]
 *   @0x2d6350 vldr s15, [r7, #204]
 *   @0x2d6354 str r5, [r7, #0x50]
 *   @0x2d6358 cmp r8, #0
 *   @0x2d635c vmul.f32 s9, s9, s15
 *   @0x2d6360 pople {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2d6364 ldr r3, [r7, #0x7c]
 *   @0x2d6368 add r8, r8, r8, lsl #1
 *   @0x2d636c ldr r6, [r7, #0x5c]
 *   @0x2d6370 add r8, r3, r8, lsl #3
 *   @0x2d6374 add r2, r3, #12
 *   @0x2d6378 ldr r12, [r2, #-0xc]
 *   @0x2d637c ldr r1, [r2, #-0x8]
 *   @0x2d6380 lsl r0, r12, #2
 *   @0x2d6384 ldr r4, [r6, r12, lsl #2]
 *   @0x2d6388 add r10, r5, r0
 *   @0x2d638c ldr r0, [r6, r1, lsl #2]
 *   @0x2d6390 lsl r9, r1, #2
 *   @0x2d6394 cmp r4, r0
 *   @0x2d6398 add r9, r5, r9
 *   @0x2d639c beq 0x2d6404 <_ZN16b2ParticleSystem10SolveSolidERK10b2TimeStep+0xd4>
 *   @0x2d63a0 vldr s14, [r10]
 *   @0x2d63a4 vldr s15, [r9]
 *   @0x2d63a8 vadd.f32 s15, s14, s15
 *   @0x2d63ac vldr s10, [r2]
 *   @0x2d63b0 vldr s14, [r3, #16]
 *   @0x2d63b4 vldr s11, [r3, #20]
 *   @0x2d63b8 ldr r4, [r7, #0x40]
 *   @0x2d63bc add r12, r4, r12, lsl #3
 *   @0x2d63c0 vldr s13, [r12]
 *   @0x2d63c4 vldr s12, [r12, #4]
 *   @0x2d63c8 add r1, r4, r1, lsl #3
 *   @0x2d63cc vmul.f32 s15, s9, s15
 *   @0x2d63d0 vmul.f32 s15, s15, s10
 *   @0x2d63d4 vmul.f32 s14, s15, s14
 *   @0x2d63d8 vmul.f32 s15, s15, s11
 *   @0x2d63dc vsub.f32 s13, s13, s14
 *   @0x2d63e0 vsub.f32 s12, s12, s15
 *   @0x2d63e4 vstr s13, [r12]
 *   @0x2d63e8 vldr s13, [r1]
 *   @0x2d63ec vstr s12, [r12, #4]
 *   @0x2d63f0 vadd.f32 s14, s13, s14
 *   @0x2d63f4 vldr s13, [r1, #4]
 *   @0x2d63f8 vadd.f32 s15, s13, s15
 *   @0x2d63fc vstr s14, [r1]
 *   @0x2d6400 vstr s15, [r1, #4]
 *   @0x2d6404 add r3, r3, #24
 *   @0x2d6408 add r2, r2, #24
 *   @0x2d640c cmp r3, r8
 *   @0x2d6410 bne 0x2d6378 <_ZN16b2ParticleSystem10SolveSolidERK10b2TimeStep+0x48>
 *   @0x2d6414 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2d6418 ldr r1, [r0, #0x28]
 *   @0x2d641c ldr r0, [r0, #0xd4]
 *   @0x2d6420 lsl r1, r1, #2
 *   @0x2d6424 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2d6428 ldr r2, [r7, #0x28]
 *   @0x2d642c mov r1, #0
 *   @0x2d6430 lsl r2, r2, #2
 *   @0x2d6434 mov r5, r0
 *   @0x2d6438 bl 0xb65b0 <memset@plt>
 *   @0x2d643c b 0x2d6348 <_ZN16b2ParticleSystem10SolveSolidERK10b2TimeStep+0x18>
 *
 * ══ §11/31 Perform_Event_TimeLine  0xf30ec  size 268  67 条（0xf30ec..0xf31f8）
 * @func 0xf30ec 0xf31f8  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xf30fc→0x542954, 0xf3148→0x54290c, 0xf3150→0x542908, 0xf3158→0x542904
 * 调用序列: TimeLine_Data(int) / CTimeLine::GetEvent(int) / CTimeLine::GetStep(int) / Script_Perform(int, CInstance*, CInstance*, int, RValue*, DynamicArrayOfRValue*) / CEvent::Execute(CInstance*, CInstance*)
 * 字段偏移 top8: 0xc×2 / 0xe8×1 / 0xe4×1 / 0x9c×1 / 0x98×1 / 0x94×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf30ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf30f0 mov r7, r0
 *   @0xf30f4 ldr r4, [pc, #0xe8]
 *   @0xf30f8 sub sp, sp, #36
 *   @0xf30fc ldr r12, [pc, #0xe4]
 *   @0xf3100 mov r6, r1
 *   @0xf3104 add r4, pc, r4
 *   @0xf3108 mov r5, r2
 *   @0xf310c mov r8, r3
 *   @0xf3110 ldr r12, [r4, r12]
 *   @0xf3114 ldr r12, [r12]
 *   @0xf3118 cmn r12, #1
 *   @0xf311c beq 0xf3128 <_Z22Perform_Event_TimeLineP9CInstanceS0_ii+0x3c>
 *   @0xf3120 add sp, sp, #36
 *   @0xf3124 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf3128 mov r0, r2
 *   @0xf312c bl 0x1f2c48 <_Z13TimeLine_Datai>
 *   @0xf3130 subs r9, r0, #0
 *   @0xf3134 beq 0xf3120 <_Z22Perform_Event_TimeLineP9CInstanceS0_ii+0x34>
 *   @0xf3138 mov r1, r8
 *   @0xf313c bl 0x1f1710 <_ZN9CTimeLine8GetEventEi>
 *   @0xf3140 subs r2, r0, #0
 *   @0xf3144 beq 0xf3120 <_Z22Perform_Event_TimeLineP9CInstanceS0_ii+0x34>
 *   @0xf3148 ldr r10, [pc, #0x9c]
 *   @0xf314c mov r0, r9
 *   @0xf3150 ldr lr, [pc, #0x98]
 *   @0xf3154 mov r1, r8
 *   @0xf3158 ldr r12, [pc, #0x94]
 *   @0xf315c movw r3, #0x86a0
 *   @0xf3160 ldr r9, [r4, r10]
 *   @0xf3164 movt r3, #0x1
 *   @0xf3168 ldr r8, [r4, lr]
 *   @0xf316c ldr r4, [r4, r12]
 *   @0xf3170 ldr r11, [r9]
 *   @0xf3174 ldr r10, [r8]
 *   @0xf3178 str r5, [r9]
 *   @0xf317c str r3, [r8]
 *   @0xf3180 ldr r5, [r4]
 *   @0xf3184 str r2, [sp, #0xc]
 *   @0xf3188 bl 0x1f1738 <_ZN9CTimeLine7GetStepEi>
 *   @0xf318c ldr r2, [sp, #0xc]
 *   @0xf3190 tst r2, #1
 *   @0xf3194 str r0, [r4]
 *   @0xf3198 beq 0xf31d0 <_Z22Perform_Event_TimeLineP9CInstanceS0_ii+0xe4>
 *   @0xf319c mov r3, #0
 *   @0xf31a0 asr r0, r2, #1
 *   @0xf31a4 add r12, sp, #16
 *   @0xf31a8 mov r1, r7
 *   @0xf31ac mov r2, r6
 *   @0xf31b0 str r3, [sp, #0x4]
 *   @0xf31b4 str r12, [sp]
 *   @0xf31b8 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue>
 *   @0xf31bc str r11, [r9]
 *   @0xf31c0 str r10, [r8]
 *   @0xf31c4 str r5, [r4]
 *   @0xf31c8 add sp, sp, #36
 *   @0xf31cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf31d0 mov r0, r2
 *   @0xf31d4 mov r1, r7
 *   @0xf31d8 mov r2, r6
 *   @0xf31dc bl 0xf2e34 <_ZN6CEvent7ExecuteEP9CInstanceS1_>
 *   @0xf31e0 b 0xf31bc <_Z22Perform_Event_TimeLineP9CInstanceS0_ii+0xd0>
 *   @0xf31e4 eoreq lr, pc, r12, asr #22
 *   @0xf31e8 .word 0xffffc154
 *   @0xf31ec .word 0xffffc168
 *   @0xf31f0 .word 0xffffc160
 *   @0xf31f4 .word 0xffffc164
 *
 * ══ §12/31 IO_Start_Step  0x18d37c  size 268  67 条（0x18d37c..0x18d488）
 * @func 0x18d37c 0x18d488  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18d38c→0x5346bc, 0x18d394→0x534ba0, 0x18d398→0x534ca0, 0x18d3c8→0x534af0, 0x18d3d0→0x534b10, 0x18d3d8→0x534ae4, 0x18d3dc→0x534ad8, 0x18d424→0x5346cc
 * 调用序列: IO_Playback_Update() / IO_Update()
 * 字段偏移 top8: 0xcc×2 / 0x98×2 / 0x-2×2 / 0x-1×2 / 0xd4×1 / 0xd0×1 / 0xa0×1 / 0x9c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18d37c push {r4, lr}
 *   @0x18d380 mov r3, #0
 *   @0x18d384 ldr r4, [pc, #0xd4]
 *   @0x18d388 mov r2, r3
 *   @0x18d38c ldr r1, [pc, #0xd0]
 *   @0x18d390 add r4, pc, r4
 *   @0x18d394 ldr r0, [pc, #0xcc]
 *   @0x18d398 ldr r12, [pc, #0xcc]
 *   @0x18d39c ldr r1, [r4, r1]
 *   @0x18d3a0 ldr lr, [r1]
 *   @0x18d3a4 add lr, lr, #1
 *   @0x18d3a8 str lr, [r1]
 *   @0x18d3ac ldr r0, [r4, r0]
 *   @0x18d3b0 ldr r1, [r4, r12]
 *   @0x18d3b4 strb r2, [r0, r3]
 *   @0x18d3b8 strb r2, [r1, r3]
 *   @0x18d3bc add r3, r3, #1
 *   @0x18d3c0 cmp r3, #256
 *   @0x18d3c4 bne 0x18d3b4 <_Z13IO_Start_Stepv+0x38>
 *   @0x18d3c8 ldr r0, [pc, #0xa0]
 *   @0x18d3cc mov r2, #0
 *   @0x18d3d0 ldr r1, [pc, #0x9c]
 *   @0x18d3d4 mov r3, r2
 *   @0x18d3d8 ldr lr, [pc, #0x98]
 *   @0x18d3dc ldr r12, [pc, #0x98]
 *   @0x18d3e0 ldr r0, [r4, r0]
 *   @0x18d3e4 ldr r1, [r4, r1]
 *   @0x18d3e8 ldr lr, [r4, lr]
 *   @0x18d3ec ldr r12, [r4, r12]
 *   @0x18d3f0 strb r3, [lr, r2]
 *   @0x18d3f4 add r0, r0, #3
 *   @0x18d3f8 strb r3, [r12, r2]
 *   @0x18d3fc add r2, r2, #1
 *   @0x18d400 cmp r2, #10
 *   @0x18d404 strb r3, [r0, #-0x3]
 *   @0x18d408 strb r3, [r1]
 *   @0x18d40c add r1, r1, #3
 *   @0x18d410 strb r3, [r0, #-0x2]
 *   @0x18d414 strb r3, [r1, #-0x2]
 *   @0x18d418 strb r3, [r0, #-0x1]
 *   @0x18d41c strb r3, [r1, #-0x1]
 *   @0x18d420 bne 0x18d3f0 <_Z13IO_Start_Stepv+0x74>
 *   @0x18d424 ldr r3, [pc, #0x54]
 *   @0x18d428 ldr r3, [r4, r3]
 *   @0x18d42c ldrb r3, [r3]
 *   @0x18d430 cmp r3, #0
 *   @0x18d434 beq 0x18d458 <_Z13IO_Start_Stepv+0xdc>
 *   @0x18d438 bl 0x18b8ec <_Z18IO_Playback_Updatev>
 *   @0x18d43c ldr r3, [pc, #0x40]
 *   @0x18d440 ldr r3, [r4, r3]
 *   @0x18d444 ldrb r3, [r3]
 *   @0x18d448 cmp r3, #0
 *   @0x18d44c popeq {r4, pc}
 *   @0x18d450 pop {r4, lr}
 *   @0x18d454 b 0x18bb00 <_Z9IO_Recordv>
 *   @0x18d458 bl 0x18d288 <_Z9IO_Updatev>
 *   @0x18d45c b 0x18d43c <_Z13IO_Start_Stepv+0xc0>
 *   @0x18d460 eoreq r4, r6, r0, asr #17
 *   @0x18d464 .word 0xffffe9e4
 *   @0x18d468 .word 0xffffe998
 *   @0x18d46c .word 0xffffe994
 *   @0x18d470 .word 0xffffe9ac
 *   @0x18d474 .word 0xffffe9a8
 *   @0x18d478 .word 0xffffe9b0
 *   @0x18d47c .word 0xffffe9b4
 *   @0x18d480 .word 0xffffe9cc
 *   @0x18d484 .word 0xffffe9c8
 *
 * ══ §13/31 WithObjIterator::Next  0x19d1c8  size 268  67 条（0x19d1c8..0x19d2d4）
 * @func 0x19d1c8 0x19d2d4  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: WithObjIterator::Next()+0xf8×2
 * 字段偏移 top8: 0x1c×6 / 0x8×5 / 0x18×4 / 0x178×1 / 0x4×1 / 0x10×1 / 0x5c×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19d1c8 ldr r3, [r0, #0x18]
 *   @0x19d1cc add r3, r3, #2
 *   @0x19d1d0 cmp r3, #5
 *   @0x19d1d4 addls pc, pc, r3, lsl #2
 *   @0x19d1d8 b 0x19d208 <_ZN15WithObjIterator4NextEv+0x40>
 *   @0x19d1dc b 0x19d20c <_ZN15WithObjIterator4NextEv+0x44>
 *   @0x19d1e0 b 0x19d220 <_ZN15WithObjIterator4NextEv+0x58>
 *   @0x19d1e4 b 0x19d22c <_ZN15WithObjIterator4NextEv+0x64>
 *   @0x19d1e8 b 0x19d268 <_ZN15WithObjIterator4NextEv+0xa0>
 *   @0x19d1ec b 0x19d294 <_ZN15WithObjIterator4NextEv+0xcc>
 *   @0x19d1f0 b 0x19d1f4 <_ZN15WithObjIterator4NextEv+0x2c>
 *   @0x19d1f4 ldr r3, [r0, #0x8]
 *   @0x19d1f8 cmp r3, #0
 *   @0x19d1fc bxeq lr
 *   @0x19d200 ldr r3, [r3, #0x178]
 *   @0x19d204 str r3, [r0, #0x8]
 *   @0x19d208 bx lr
 *   @0x19d20c ldr r3, [r0, #0x4]
 *   @0x19d210 cmp r3, #0
 *   @0x19d214 ldrne r3, [r3, #0x178]
 *   @0x19d218 strne r3, [r0, #0x4]
 *   @0x19d21c bx lr
 *   @0x19d220 mov r3, #0
 *   @0x19d224 str r3, [r0, #0x10]
 *   @0x19d228 bx lr
 *   @0x19d22c ldr r3, [r0]
 *   @0x19d230 cmp r3, #0
 *   @0x19d234 beq 0x19d254 <_ZN15WithObjIterator4NextEv+0x8c>
 *   @0x19d238 ldr r3, [r3]
 *   @0x19d23c cmp r3, #0
 *   @0x19d240 str r3, [r0]
 *   @0x19d244 beq 0x19d254 <_ZN15WithObjIterator4NextEv+0x8c>
 *   @0x19d248 ldr r3, [r3, #0x8]
 *   @0x19d24c cmp r3, #0
 *   @0x19d250 bxne lr
 *   @0x19d254 mov r2, #1
 *   @0x19d258 mov r3, #0
 *   @0x19d25c str r2, [r0, #0x18]
 *   @0x19d260 str r3, [r0, #0x1c]
 *   @0x19d264 bx lr
 *   @0x19d268 ldr r3, [pc, #0x5c]
 *   @0x19d26c ldr r2, [r0, #0x1c]
 *   @0x19d270 ldr r3, [pc, r3]
 *   @0x19d274 ldr r3, [r3, #0x8]
 *   @0x19d278 cmp r2, r3
 *   @0x19d27c blt 0x19d2c0 <_ZN15WithObjIterator4NextEv+0xf8>
 *   @0x19d280 mov r2, #2
 *   @0x19d284 mov r3, #0
 *   @0x19d288 str r2, [r0, #0x18]
 *   @0x19d28c str r3, [r0, #0x1c]
 *   @0x19d290 bx lr
 *   @0x19d294 ldr r3, [pc, #0x34]
 *   @0x19d298 ldr r2, [r0, #0x1c]
 *   @0x19d29c ldr r3, [pc, r3]
 *   @0x19d2a0 ldr r3, [r3, #0x8]
 *   @0x19d2a4 cmp r2, r3
 *   @0x19d2a8 blt 0x19d2c0 <_ZN15WithObjIterator4NextEv+0xf8>
 *   @0x19d2ac mov r2, #3
 *   @0x19d2b0 mov r3, #0
 *   @0x19d2b4 str r2, [r0, #0x18]
 *   @0x19d2b8 str r3, [r0, #0x1c]
 *   @0x19d2bc bx lr
 *   @0x19d2c0 add r2, r2, #1
 *   @0x19d2c4 str r2, [r0, #0x1c]
 *   @0x19d2c8 bx lr
 *   @0x19d2cc .word 0x002509d0
 *   @0x19d2d0 eoreq r0, r5, r12, lsr #19
 *
 * ══ §14/31 b2ParticleSystem::b2ParticleSystem  0x2d4fbc  size 268  67 条（0x2d4fbc..0x2d50c8）
 * @func 0x2d4fbc 0x2d50c8  size 268  67 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0x34×1 / 0x38×1 / 0x3c×1 / 0x40×1 / 0x44×1 / 0x54×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4fbc mov r2, #0
 *   @0x2d4fc0 mov r1, #1065353216
 *   @0x2d4fc4 push {r4, r5, r6, r7}
 *   @0x2d4fc8 mov r4, #1048576000
 *   @0x2d4fcc mov r12, #1056964608
 *   @0x2d4fd0 movw r7, #0xcccd
 *   @0x2d4fd4 str r2, [r0, #0x30]
 *   @0x2d4fd8 movt r7, #0x3d4c
 *   @0x2d4fdc movw r6, #0xcccd
 *   @0x2d4fe0 str r2, [r0, #0x34]
 *   @0x2d4fe4 movt r6, #0x3dcc
 *   @0x2d4fe8 movw r5, #0xcccd
 *   @0x2d4fec str r2, [r0, #0x38]
 *   @0x2d4ff0 movt r5, #0x3e4c
 *   @0x2d4ff4 str r2, [r0, #0x3c]
 *   @0x2d4ff8 str r2, [r0, #0x40]
 *   @0x2d4ffc str r2, [r0, #0x44]
 *   @0x2d5000 str r2, [r0, #0x54]
 *   @0x2d5004 str r2, [r0, #0x58]
 *   @0x2d5008 str r1, [r0, #0xc]
 *   @0x2d500c str r1, [r0, #0x10]
 *   @0x2d5010 str r1, [r0, #0x14]
 *   @0x2d5014 str r1, [r0, #0x18]
 *   @0x2d5018 str r1, [r0, #0x1c]
 *   @0x2d501c str r1, [r0, #0x20]
 *   @0x2d5020 str r2, [r0, #0x60]
 *   @0x2d5024 str r2, [r0, #0x64]
 *   @0x2d5028 str r2, [r0]
 *   @0x2d502c str r2, [r0, #0x4]
 *   @0x2d5030 str r2, [r0, #0x8]
 *   @0x2d5034 str r2, [r0, #0x24]
 *   @0x2d5038 str r2, [r0, #0x28]
 *   @0x2d503c str r2, [r0, #0x2c]
 *   @0x2d5040 str r2, [r0, #0x48]
 *   @0x2d5044 str r2, [r0, #0x4c]
 *   @0x2d5048 str r2, [r0, #0x50]
 *   @0x2d504c str r2, [r0, #0x5c]
 *   @0x2d5050 str r2, [r0, #0x68]
 *   @0x2d5054 str r2, [r0, #0x6c]
 *   @0x2d5058 str r2, [r0, #0x70]
 *   @0x2d505c str r2, [r0, #0x74]
 *   @0x2d5060 str r2, [r0, #0x78]
 *   @0x2d5064 str r2, [r0, #0x7c]
 *   @0x2d5068 str r2, [r0, #0x80]
 *   @0x2d506c str r7, [r0, #0xac]
 *   @0x2d5070 str r6, [r0, #0xc0]
 *   @0x2d5074 str r5, [r0, #0xc4]
 *   @0x2d5078 str r4, [r0, #0xb4]
 *   @0x2d507c str r4, [r0, #0xb8]
 *   @0x2d5080 str r4, [r0, #0xbc]
 *   @0x2d5084 str r2, [r0, #0x84]
 *   @0x2d5088 str r1, [r0, #0xb0]
 *   @0x2d508c str r2, [r0, #0x88]
 *   @0x2d5090 str r2, [r0, #0x8c]
 *   @0x2d5094 str r2, [r0, #0x90]
 *   @0x2d5098 str r2, [r0, #0x94]
 *   @0x2d509c str r2, [r0, #0x98]
 *   @0x2d50a0 str r2, [r0, #0x9c]
 *   @0x2d50a4 str r2, [r0, #0xa0]
 *   @0x2d50a8 str r12, [r0, #0xc8]
 *   @0x2d50ac str r2, [r0, #0xa4]
 *   @0x2d50b0 str r12, [r0, #0xcc]
 *   @0x2d50b4 str r2, [r0, #0xa8]
 *   @0x2d50b8 str r12, [r0, #0xd0]
 *   @0x2d50bc str r2, [r0, #0xd4]
 *   @0x2d50c0 pop {r4, r5, r6, r7}
 *   @0x2d50c4 bx lr
 *
 * ══ §15/31 YYGetBool  0xce768  size 264  66 条（0xce768..0xce870）
 * @func 0xce768 0xce870  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: KindName(RValue const*) / YYError(char const*, ...)
 * 字段偏移 top8: 0x4×7 / 0xc×1 / 0x2c×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce768 add r2, r0, r1, lsl #4
 *   @0xce76c push {r4, r5, r6, lr}
 *   @0xce770 mov r6, r1
 *   @0xce774 ldr r3, [r2, #0xc]
 *   @0xce778 bic r3, r3, #-16777216
 *   @0xce77c cmp r3, #13
 *   @0xce780 addls pc, pc, r3, lsl #2
 *   @0xce784 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc>
 *   @0xce788 b 0xce810 <_Z9YYGetBoolPK6RValuei+0xa8>
 *   @0xce78c b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc>
 *   @0xce790 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc>
 *   @0xce794 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc>
 *   @0xce798 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc>
 *   @0xce79c b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc>
 *   @0xce7a0 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc>
 *   @0xce7a4 b 0xce7fc <_Z9YYGetBoolPK6RValuei+0x94>
 *   @0xce7a8 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc>
 *   @0xce7ac b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc>
 *   @0xce7b0 b 0xce7e0 <_Z9YYGetBoolPK6RValuei+0x78>
 *   @0xce7b4 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc>
 *   @0xce7b8 b 0xce834 <_Z9YYGetBoolPK6RValuei+0xcc>
 *   @0xce7bc b 0xce7c0 <_Z9YYGetBoolPK6RValuei+0x58>
 *   @0xce7c0 ldr r4, [r0, r1, lsl #4]
 *   @0xce7c4 ldr r5, [r2, #0x4]
 *   @0xce7c8 vmov d6, r4, r5
 *   @0xce7cc vcmp.f64 d6, #0
 *   @0xce7d0 vmrs APSR_nzcv, fpscr
 *   @0xce7d4 moveq r0, #0
 *   @0xce7d8 movne r0, #1
 *   @0xce7dc pop {r4, r5, r6, pc}
 *   @0xce7e0 ldr r4, [r0, r1, lsl #4]
 *   @0xce7e4 ldr r5, [r2, #0x4]
 *   @0xce7e8 cmp r4, #1
 *   @0xce7ec sbcs r3, r5, #0
 *   @0xce7f0 movlt r0, #0
 *   @0xce7f4 movge r0, #1
 *   @0xce7f8 pop {r4, r5, r6, pc}
 *   @0xce7fc ldr r0, [r0, r1, lsl #4]
 *   @0xce800 cmp r0, #0
 *   @0xce804 movle r0, #0
 *   @0xce808 movgt r0, #1
 *   @0xce80c pop {r4, r5, r6, pc}
 *   @0xce810 vmov.f64 d7, #5.000000e-01
 *   @0xce814 ldr r4, [r0, r1, lsl #4]
 *   @0xce818 ldr r5, [r2, #0x4]
 *   @0xce81c vmov d6, r4, r5
 *   @0xce820 vcmpe.f64 d6, d7
 *   @0xce824 vmrs APSR_nzcv, fpscr
 *   @0xce828 movle r0, #0
 *   @0xce82c movgt r0, #1
 *   @0xce830 pop {r4, r5, r6, pc}
 *   @0xce834 ldr r3, [pc, #0x2c]
 *   @0xce838 mov r0, r2
 *   @0xce83c ldr r3, [pc, r3]
 *   @0xce840 ldr r4, [r3]
 *   @0xce844 bl 0xce54c <_Z8KindNamePK6RValue>
 *   @0xce848 add r2, r6, #1
 *   @0xce84c mov r1, r4
 *   @0xce850 mov r3, r0
 *   @0xce854 ldr r0, [pc, #0x10]
 *   @0xce858 add r0, pc, r0
 *   @0xce85c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xce860 mov r0, #0
 *   @0xce864 pop {r4, r5, r6, pc}
 *   @0xce868 ldrshteq pc, [r1], -r4
 *   @0xce86c eoreq r3, r6, r4, lsr #21
 *
 * ══ §16/31 F_DsQueueCreate  0xfad10  size 264  66 条（0xfad10..0xfae18）
 * @func 0xfad10 0xfae18  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xfad1c→0x4836c4, 0xfad28→0x4836c8
 * 调用序列: F_DsQueueCreate(RValue&, CInstance*, CInstance*, int, RValue*)+0x60 / operator new(unsigned int) / CDS_Queue::CDS_Queue() / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×3 / 0xe8×2 / 0xe0×1 / 0xc×1 / 0x44×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfad10 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xfad14 mov r7, r0
 *   @0xfad18 ldr r3, [pc, #0xe8]
 *   @0xfad1c ldr r2, [pc, #0xe8]
 *   @0xfad20 add r3, pc, r3
 *   @0xfad24 ldr r9, [r3, r2]
 *   @0xfad28 ldr r2, [pc, #0xe0]
 *   @0xfad2c ldr r5, [r9]
 *   @0xfad30 ldr r8, [r3, r2]
 *   @0xfad34 cmp r5, #0
 *   @0xfad38 ble 0xfad70 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xfad3c ldr r3, [r8, #0x4]
 *   @0xfad40 ldr r6, [r3]
 *   @0xfad44 cmp r6, #0
 *   @0xfad48 beq 0xfae00 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0xfad4c mov r4, #0
 *   @0xfad50 b 0xfad60 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0xfad54 ldr r2, [r3, #0x4]!
 *   @0xfad58 cmp r2, #0
 *   @0xfad5c beq 0xfad90 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfad60 add r4, r4, #1
 *   @0xfad64 cmp r4, r5
 *   @0xfad68 lsl r6, r4, #2
 *   @0xfad6c bne 0xfad54 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0xfad70 ldr r3, [r8]
 *   @0xfad74 cmp r5, r3
 *   @0xfad78 movlt r3, r5
 *   @0xfad7c bge 0xfadc4 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xfad80 lsl r6, r5, #2
 *   @0xfad84 mov r4, r5
 *   @0xfad88 add r3, r3, #1
 *   @0xfad8c str r3, [r9]
 *   @0xfad90 mov r0, #20
 *   @0xfad94 bl 0x27c524 <_Znwj>
 *   @0xfad98 mov r5, r0
 *   @0xfad9c bl 0x20ed58 <_ZN9CDS_QueueC2Ev>
 *   @0xfada0 vmov s15, r4
 *   @0xfada4 ldr r0, [r8, #0x4]
 *   @0xfada8 mov r1, #0
 *   @0xfadac vcvt.f64.s32 d7, s15
 *   @0xfadb0 str r5, [r0, r6]
 *   @0xfadb4 str r1, [r7, #0xc]
 *   @0xfadb8 vmov r2, r3, d7
 *   @0xfadbc stm r7, {r2, r3}
 *   @0xfadc0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xfadc4 add r1, r5, #16
 *   @0xfadc8 ldr r2, [pc, #0x44]
 *   @0xfadcc movw r3, #0x182
 *   @0xfadd0 add r0, r8, #4
 *   @0xfadd4 add r2, pc, r2
 *   @0xfadd8 lsl r1, r1, #2
 *   @0xfaddc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xfade0 ldr r3, [r9]
 *   @0xfade4 lsl r6, r5, #2
 *   @0xfade8 mov r4, r5
 *   @0xfadec add r2, r3, #16
 *   @0xfadf0 add r3, r3, #1
 *   @0xfadf4 str r2, [r8]
 *   @0xfadf8 str r3, [r9]
 *   @0xfadfc b 0xfad90 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfae00 mov r4, r6
 *   @0xfae04 b 0xfad90 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfae08 eoreq r6, pc, r0, lsr pc
 *   @0xfae0c .word 0xffffc21c
 *   @0xfae10 .word 0xffffc220
 *   @0xfae14 eoreq r12, r3, r8, asr #27
 *
 * ══ §17/31 Run_Start  0x1d4ed8  size 264  66 条（0x1d4ed8..0x1d4fe0）
 * @func 0x1d4ed8 0x1d4fe0  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d4ee0→0x54297a, 0x1d4ef8→0x542979, 0x1d4f14→0x544c38, 0x1d4f28→0x7590b8, 0x1d4f3c→0x7590b4, 0x1d4f40→0x757e80, 0x1d4f54→0x757e72, 0x1d4f68→0x3eb708
 * 调用序列: CProfiler::Init(char const*, int)×2 / MainLoop_Init() / StartGame()
 * 字段偏移 top8: 0xd4×2 / 0x88×2 / 0xc0×1 / 0xa8×1 / 0x98×1 / 0x78×1 / 0x68×1 / 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d4ed8 push {r3, r4, r5, lr}
 *   @0x1d4edc ldr r4, [pc, #0xd4]
 *   @0x1d4ee0 ldr r3, [pc, #0xd4]
 *   @0x1d4ee4 add r4, pc, r4
 *   @0x1d4ee8 ldr r5, [r4, r3]
 *   @0x1d4eec ldrb r3, [r5]
 *   @0x1d4ef0 cmp r3, #0
 *   @0x1d4ef4 beq 0x1d4f94 <_Z9Run_Startv+0xbc>
 *   @0x1d4ef8 ldr r2, [pc, #0xc0]
 *   @0x1d4efc mov r3, #1
 *   @0x1d4f00 strb r3, [r5]
 *   @0x1d4f04 mov r3, #0
 *   @0x1d4f08 ldr r5, [r4, r2]
 *   @0x1d4f0c strb r3, [r5]
 *   @0x1d4f10 bl 0x1d3658 <_Z13MainLoop_Initv>
 *   @0x1d4f14 ldr r3, [pc, #0xa8]
 *   @0x1d4f18 ldr r3, [r4, r3]
 *   @0x1d4f1c ldr r3, [r3]
 *   @0x1d4f20 cmp r3, #0
 *   @0x1d4f24 bne 0x1d4f54 <_Z9Run_Startv+0x7c>
 *   @0x1d4f28 ldr r3, [pc, #0x98]
 *   @0x1d4f2c ldr r3, [r4, r3]
 *   @0x1d4f30 ldr r1, [r3]
 *   @0x1d4f34 cmp r1, #0
 *   @0x1d4f38 beq 0x1d4fa4 <_Z9Run_Startv+0xcc>
 *   @0x1d4f3c ldr r3, [pc, #0x88]
 *   @0x1d4f40 ldr r2, [pc, #0x88]
 *   @0x1d4f44 ldr r3, [r4, r3]
 *   @0x1d4f48 ldr r0, [r4, r2]
 *   @0x1d4f4c ldr r2, [r3]
 *   @0x1d4f50 bl 0x2a00b0 <_ZN9CProfiler4InitEPKci>
 *   @0x1d4f54 ldr r3, [pc, #0x78]
 *   @0x1d4f58 ldr r3, [r4, r3]
 *   @0x1d4f5c ldrb r3, [r3]
 *   @0x1d4f60 cmp r3, #0
 *   @0x1d4f64 popeq {r3, r4, r5, pc}
 *   @0x1d4f68 ldr r3, [pc, #0x68]
 *   @0x1d4f6c mov r2, #1
 *   @0x1d4f70 strb r2, [r5]
 *   @0x1d4f74 ldr r1, [pc, #0x60]
 *   @0x1d4f78 ldr r3, [r4, r3]
 *   @0x1d4f7c add r1, pc, r1
 *   @0x1d4f80 ldr r0, [r3]
 *   @0x1d4f84 ldr r3, [r0]
 *   @0x1d4f88 ldr r3, [r3, #0xc]
 *   @0x1d4f8c blx r3
 *   @0x1d4f90 pop {r3, r4, r5, pc}
 *   @0x1d4f94 mov r3, #1
 *   @0x1d4f98 strb r3, [r5]
 *   @0x1d4f9c bl 0x1d44fc <_Z9StartGamev>
 *   @0x1d4fa0 b 0x1d4ef8 <_Z9Run_Startv+0x20>
 *   @0x1d4fa4 ldr r3, [pc, #0x24]
 *   @0x1d4fa8 mov r2, r1
 *   @0x1d4fac ldr r0, [r4, r3]
 *   @0x1d4fb0 bl 0x2a00b0 <_ZN9CProfiler4InitEPKci>
 *   @0x1d4fb4 b 0x1d4f54 <_Z9Run_Startv+0x7c>
 *   @0x1d4fb8 eoreq r12, r1, r12, ror #26
 *   @0x1d4fbc .word 0xffffeebc
 *   @0x1d4fc0 .word 0xffffdfa0
 *   @0x1d4fc4 .word 0xffffc7d0
 *   @0x1d4fc8 .word 0xffffef64
 *   @0x1d4fcc .word 0xffffef68
 *   @0x1d4fd0 .word 0xffffbf1c
 *   @0x1d4fd4 .word 0xffffdf9c
 *   @0x1d4fd8 .word 0xffffbcf0
 *   @0x1d4fdc andseq r12, r7, r0, asr #3
 *
 * ══ §18/31 oggpack_read  0x233b28  size 264  66 条（0x233b28..0x233c30）
 * @func 0x233b28 0x233c30  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_read+0xb4×4 / oggpack_read+0x54
 * 字段偏移 top8: 0x4×3 / 0xc×3 / 0x2×2 / 0x10×1 / 0xe0×1 / 0x1×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233b28 cmp r1, #32
 *   @0x233b2c mov r3, r0
 *   @0x233b30 push {r4, r5, r6, r7, r8}
 *   @0x233b34 ldr r12, [r0, #0x10]
 *   @0x233b38 bhi 0x233c10 <oggpack_read+0xe8>
 *   @0x233b3c ldr r4, [r0]
 *   @0x233b40 sub r2, r12, #4
 *   @0x233b44 ldr r0, [pc, #0xe0]
 *   @0x233b48 cmp r4, r2
 *   @0x233b4c ldr r2, [r3, #0x4]
 *   @0x233b50 add r0, pc, r0
 *   @0x233b54 ldr r6, [r0, r1, lsl #2]
 *   @0x233b58 add r1, r2, r1
 *   @0x233b5c add r5, r1, #7
 *   @0x233b60 blt 0x233b7c <oggpack_read+0x54>
 *   @0x233b64 sub r0, r12, r5, asr #3
 *   @0x233b68 cmp r4, r0
 *   @0x233b6c bgt 0x233c10 <oggpack_read+0xe8>
 *   @0x233b70 cmp r1, #0
 *   @0x233b74 moveq r0, r1
 *   @0x233b78 beq 0x233c08 <oggpack_read+0xe0>
 *   @0x233b7c ldr r12, [r3, #0xc]
 *   @0x233b80 cmp r1, #8
 *   @0x233b84 ldrb r0, [r12]
 *   @0x233b88 asr r0, r0, r2
 *   @0x233b8c ble 0x233bdc <oggpack_read+0xb4>
 *   @0x233b90 ldrb r8, [r12, #0x1]
 *   @0x233b94 cmp r1, #16
 *   @0x233b98 rsb r7, r2, #8
 *   @0x233b9c orr r0, r0, r8, lsl r7
 *   @0x233ba0 ble 0x233bdc <oggpack_read+0xb4>
 *   @0x233ba4 ldrb r8, [r12, #0x2]
 *   @0x233ba8 cmp r1, #24
 *   @0x233bac rsb r7, r2, #16
 *   @0x233bb0 orr r0, r0, r8, lsl r7
 *   @0x233bb4 ble 0x233bdc <oggpack_read+0xb4>
 *   @0x233bb8 ldrb r8, [r12, #0x3]
 *   @0x233bbc cmp r1, #32
 *   @0x233bc0 rsb r7, r2, #24
 *   @0x233bc4 orr r0, r0, r8, lsl r7
 *   @0x233bc8 ble 0x233bdc <oggpack_read+0xb4>
 *   @0x233bcc cmp r2, #0
 *   @0x233bd0 rsbne r2, r2, #32
 *   @0x233bd4 ldrbne r7, [r12, #0x4]
 *   @0x233bd8 orrne r0, r0, r7, lsl r2
 *   @0x233bdc cmp r1, #0
 *   @0x233be0 and r0, r0, r6
 *   @0x233be4 movge r2, r1
 *   @0x233be8 movlt r2, r5
 *   @0x233bec asr r2, r2, #3
 *   @0x233bf0 and r1, r1, #7
 *   @0x233bf4 add r12, r12, r2
 *   @0x233bf8 add r4, r4, r2
 *   @0x233bfc str r1, [r3, #0x4]
 *   @0x233c00 str r12, [r3, #0xc]
 *   @0x233c04 str r4, [r3]
 *   @0x233c08 pop {r4, r5, r6, r7, r8}
 *   @0x233c0c bx lr
 *   @0x233c10 mov r1, #0
 *   @0x233c14 mov r2, #1
 *   @0x233c18 str r12, [r3]
 *   @0x233c1c mvn r0, #0
 *   @0x233c20 str r1, [r3, #0xc]
 *   @0x233c24 str r2, [r3, #0x4]
 *   @0x233c28 b 0x233c08 <oggpack_read+0xe0>
 *   @0x233c2c andseq r4, r3, r8, ror #29
 *
 * ══ §19/31 b2Body::SetTransform  0x2c71c4  size 264  66 条（0x2c71c4..0x2c72cc）
 * @func 0x2c71c4 0x2c72cc  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c / b2Fixture::Synchronize(b2BroadPhase*, b2Transform const&, b2Transform const&)
 * 字段偏移 top8: 0x68×2 / 0x74×1 / 0x48×1 / 0x44×1 / 0x4×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c71c4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2c71c8 vpush {d8}
 *   @0x2c71cc movw r3, #0x91d4
 *   @0x2c71d0 ldr r7, [r0, #0x68]
 *   @0x2c71d4 movt r3, #0x1
 *   @0x2c71d8 mov r6, r0
 *   @0x2c71dc mov r4, r1
 *   @0x2c71e0 mov r8, r2
 *   @0x2c71e4 ldr r3, [r7, r3]
 *   @0x2c71e8 tst r3, #2
 *   @0x2c71ec beq 0x2c71f8 <_ZN6b2Body12SetTransformERK6b2Vec2f+0x34>
 *   @0x2c71f0 vpop {d8}
 *   @0x2c71f4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2c71f8 mov r0, r2
 *   @0x2c71fc add r5, r6, #12
 *   @0x2c7200 bl 0xb6580 <sinf@plt>
 *   @0x2c7204 add r10, r6, #60
 *   @0x2c7208 add r9, r6, #52
 *   @0x2c720c add r7, r7, #102400
 *   @0x2c7210 add r7, r7, #472
 *   @0x2c7214 vmov s16, r0
 *   @0x2c7218 mov r0, r8
 *   @0x2c721c vstr s16, [r6, #20]
 *   @0x2c7220 bl 0xb658c <cosf@plt>
 *   @0x2c7224 add r12, r6, #28
 *   @0x2c7228 vmov s13, r0
 *   @0x2c722c ldm r4, {r0, r1}
 *   @0x2c7230 vstr s13, [r6, #24]
 *   @0x2c7234 ldr r4, [r6, #0x74]
 *   @0x2c7238 stm r5, {r0, r1}
 *   @0x2c723c cmp r4, #0
 *   @0x2c7240 ldm r5, {r0, r1, r2, r3}
 *   @0x2c7244 stm r12, {r0, r1, r2, r3}
 *   @0x2c7248 vldr s15, [r6, #48]
 *   @0x2c724c vmul.f32 s14, s15, s13
 *   @0x2c7250 vldr s12, [r6, #44]
 *   @0x2c7254 vldr s10, [r6, #16]
 *   @0x2c7258 vldr s11, [r6, #12]
 *   @0x2c725c str r8, [r6, #0x48]
 *   @0x2c7260 vmul.f32 s15, s15, s16
 *   @0x2c7264 vmla.f32 s14, s12, s16
 *   @0x2c7268 vnmls.f32 s15, s12, s13
 *   @0x2c726c vadd.f32 s14, s14, s10
 *   @0x2c7270 vadd.f32 s15, s15, s11
 *   @0x2c7274 vstr s14, [r6, #64]
 *   @0x2c7278 vstr s15, [r6, #60]
 *   @0x2c727c ldm r10, {r0, r1}
 *   @0x2c7280 stm r9, {r0, r1}
 *   @0x2c7284 str r8, [r6, #0x44]
 *   @0x2c7288 beq 0x2c72c4 <_ZN6b2Body12SetTransformERK6b2Vec2f+0x100>
 *   @0x2c728c mov r0, r4
 *   @0x2c7290 mov r1, r7
 *   @0x2c7294 mov r2, r5
 *   @0x2c7298 mov r3, r5
 *   @0x2c729c bl 0x2c87cc <_ZN9b2Fixture11SynchronizeEP12b2BroadPhaseRK11b2TransformS4_>
 *   @0x2c72a0 ldr r4, [r4, #0x4]
 *   @0x2c72a4 cmp r4, #0
 *   @0x2c72a8 bne 0x2c728c <_ZN6b2Body12SetTransformERK6b2Vec2f+0xc8>
 *   @0x2c72ac ldr r0, [r6, #0x68]
 *   @0x2c72b0 add r0, r0, #102400
 *   @0x2c72b4 add r0, r0, #472
 *   @0x2c72b8 vpop {d8}
 *   @0x2c72bc pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2c72c0 b 0x2c84d8 <_ZN16b2ContactManager15FindNewContactsEv>
 *   @0x2c72c4 mov r0, r7
 *   @0x2c72c8 b 0x2c72b8 <_ZN6b2Body12SetTransformERK6b2Vec2f+0xf4>
 *
 * ══ §20/31 YYGetString  0xd04d0  size 260  65 条（0xd04d0..0xd05d4）
 * @func 0xd04d0 0xd05d4  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / KindName(RValue const*) / YYError(char const*, ...)
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x10×2 / 0x88×1 / 0x-4×1 / 0x3c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd04d0 push {r4, r5, r7, lr}
 *   @0xd04d4 add r7, r0, r1, lsl #4
 *   @0xd04d8 sub sp, sp, #24
 *   @0xd04dc ldr r4, [r7, #0xc]
 *   @0xd04e0 bic r4, r4, #-16777216
 *   @0xd04e4 cmp r4, #13
 *   @0xd04e8 bhi 0xd0588 <_Z11YYGetStringPK6RValuei+0xb8>
 *   @0xd04ec mov r3, #1
 *   @0xd04f0 movw r12, #0x24c1
 *   @0xd04f4 lsl r5, r3, r4
 *   @0xd04f8 and r12, r5, r12
 *   @0xd04fc cmp r12, #0
 *   @0xd0500 bne 0xd0538 <_Z11YYGetStringPK6RValuei+0x68>
 *   @0xd0504 tst r5, #2
 *   @0xd0508 beq 0xd0588 <_Z11YYGetStringPK6RValuei+0xb8>
 *   @0xd050c cmp r4, r3
 *   @0xd0510 movne r0, r12
 *   @0xd0514 beq 0xd0520 <_Z11YYGetStringPK6RValuei+0x50>
 *   @0xd0518 add sp, sp, #24
 *   @0xd051c pop {r4, r5, r7, pc}
 *   @0xd0520 ldr r0, [r0, r1, lsl #4]
 *   @0xd0524 cmp r0, #0
 *   @0xd0528 beq 0xd0518 <_Z11YYGetStringPK6RValuei+0x48>
 *   @0xd052c ldr r0, [r0]
 *   @0xd0530 add sp, sp, #24
 *   @0xd0534 pop {r4, r5, r7, pc}
 *   @0xd0538 ldr r1, [pc, #0x88]
 *   @0xd053c mov r12, #16
 *   @0xd0540 mov r0, r12
 *   @0xd0544 movw r2, #0x1ad
 *   @0xd0548 add r1, pc, r1
 *   @0xd054c str r12, [sp, #0xc]
 *   @0xd0550 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd0554 mov r3, r7
 *   @0xd0558 mov r1, #0
 *   @0xd055c mov r2, r0
 *   @0xd0560 add r0, sp, #24
 *   @0xd0564 str r2, [sp, #0x10]
 *   @0xd0568 str r2, [r0, #-0x4]!
 *   @0xd056c strb r1, [r2]
 *   @0xd0570 add r1, sp, #16
 *   @0xd0574 add r2, sp, #12
 *   @0xd0578 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0xd057c ldr r0, [sp, #0x10]
 *   @0xd0580 add sp, sp, #24
 *   @0xd0584 pop {r4, r5, r7, pc}
 *   @0xd0588 ldr r3, [pc, #0x3c]
 *   @0xd058c mov r0, r7
 *   @0xd0590 ldr r3, [pc, r3]
 *   @0xd0594 ldr r4, [r3]
 *   @0xd0598 str r1, [sp, #0x4]
 *   @0xd059c bl 0xce54c <_Z8KindNamePK6RValue>
 *   @0xd05a0 ldr r1, [sp, #0x4]
 *   @0xd05a4 add r2, r1, #1
 *   @0xd05a8 mov r1, r4
 *   @0xd05ac mov r3, r0
 *   @0xd05b0 ldr r0, [pc, #0x18]
 *   @0xd05b4 add r0, pc, r0
 *   @0xd05b8 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd05bc mov r0, #0
 *   @0xd05c0 add sp, sp, #24
 *   @0xd05c4 pop {r4, r5, r7, pc}
 *   @0xd05c8 .word 0x00261cb4
 *   @0xd05cc eorseq sp, r1, r0, lsr #11
 *   @0xd05d0 mlaeq r6, r8, pc, r1
 *
 * ══ §21/31 Graphics::SetSamplerState  0x1804b0  size 260  65 条（0x1804b0..0x1805b4）
 * @func 0x1804b0 0x1805b4  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1804f0→0x3f286c, 0x180500→0x3f27ac, 0x180510→0x3f284c, 0x180520→0x3f280c, 0x180530→0x3f27ec, 0x180540→0x3f282c, 0x180550→0x4a23d0, 0x180564→0x3f27cc
 * 调用序列: 无
 * 字段偏移 top8: 0x2×6 / 0xd0×1 / 0x98×1 / 0x8c×1 / 0x80×1 / 0x74×1 / 0x68×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1804b0 cmp r0, #8
 *   @0x1804b4 ldr r3, [pc, #0xd0]
 *   @0x1804b8 add r3, pc, r3
 *   @0x1804bc bxhi lr
 *   @0x1804c0 cmp r1, #8
 *   @0x1804c4 addls pc, pc, r1, lsl #2
 *   @0x1804c8 b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c>
 *   @0x1804cc b 0x1804f0 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x40>
 *   @0x1804d0 b 0x180510 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x60>
 *   @0x1804d4 b 0x180520 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x70>
 *   @0x1804d8 b 0x180530 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x80>
 *   @0x1804dc b 0x180540 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x90>
 *   @0x1804e0 b 0x180550 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0xa0>
 *   @0x1804e4 b 0x180564 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0xb4>
 *   @0x1804e8 b 0x180578 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0xc8>
 *   @0x1804ec b 0x180500 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x50>
 *   @0x1804f0 ldr r1, [pc, #0x98]
 *   @0x1804f4 ldr r3, [r3, r1]
 *   @0x1804f8 str r2, [r3, r0, lsl #2]
 *   @0x1804fc b 0x180ed4 <_Z28UpdateCurrentTextureSettingsi>
 *   @0x180500 ldr r1, [pc, #0x8c]
 *   @0x180504 ldr r3, [r3, r1]
 *   @0x180508 str r2, [r3, r0, lsl #2]
 *   @0x18050c b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c>
 *   @0x180510 ldr r1, [pc, #0x80]
 *   @0x180514 ldr r3, [r3, r1]
 *   @0x180518 str r2, [r3, r0, lsl #2]
 *   @0x18051c b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c>
 *   @0x180520 ldr r1, [pc, #0x74]
 *   @0x180524 ldr r3, [r3, r1]
 *   @0x180528 str r2, [r3, r0, lsl #2]
 *   @0x18052c b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c>
 *   @0x180530 ldr r1, [pc, #0x68]
 *   @0x180534 ldr r3, [r3, r1]
 *   @0x180538 str r2, [r3, r0, lsl #2]
 *   @0x18053c b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c>
 *   @0x180540 ldr r1, [pc, #0x5c]
 *   @0x180544 ldr r3, [r3, r1]
 *   @0x180548 str r2, [r3, r0, lsl #2]
 *   @0x18054c b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c>
 *   @0x180550 ldr r1, [pc, #0x50]
 *   @0x180554 ldr r3, [r3, r1]
 *   @0x180558 add r3, r3, r0, lsl #2
 *   @0x18055c str r2, [r3]
 *   @0x180560 b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c>
 *   @0x180564 ldr r1, [pc, #0x40]
 *   @0x180568 ldr r3, [r3, r1]
 *   @0x18056c add r3, r3, r0, lsl #2
 *   @0x180570 str r2, [r3]
 *   @0x180574 b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c>
 *   @0x180578 ldr r1, [pc, #0x30]
 *   @0x18057c ldr r3, [r3, r1]
 *   @0x180580 add r3, r3, r0, lsl #2
 *   @0x180584 str r2, [r3]
 *   @0x180588 b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c>
 *   @0x18058c mlaeq r7, r8, r7, r1
 *   @0x180590 .word 0xffffe8bc
 *   @0x180594 .word 0xffffe8c0
 *   @0x180598 .word 0xffffe8c4
 *   @0x18059c .word 0xffffe8c8
 *   @0x1805a0 .word 0xffffe8cc
 *   @0x1805a4 .word 0xffffe8d0
 *   @0x1805a8 .word 0xffffe8d4
 *   @0x1805ac .word 0xffffe8d8
 *   @0x1805b0 .word 0xffffe8dc
 *
 * ══ §22/31 _InvalidateTextureState  0x182598  size 260  65 条（0x182598..0x18269c）
 * @func 0x182598 0x18269c  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1825a0→0x3f26dc, 0x1825c0→0x4a2f20, 0x1825c4→0x4a2f54, 0x1825c8→0x4a2f28, 0x1825ec→0x4a2100, 0x182618→0x479bbc, 0x18263c→0x4a2f28, 0x182644→0x4a2f24
 * 调用序列: _CreateTextureIfInvalid(Texture*, bool, eMipEnable)
 * 字段偏移 top8: 0xb8×3 / 0xd4×2 / 0x2×2 / 0x48×2 / 0x98×1 / 0x70×1 / 0x14×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x182598 push {r3, r4, r5, lr}
 *   @0x18259c ldr r4, [pc, #0xd4]
 *   @0x1825a0 ldr r3, [pc, #0xd4]
 *   @0x1825a4 add r4, pc, r4
 *   @0x1825a8 ldr r5, [r4, r3]
 *   @0x1825ac ldr r3, [r5]
 *   @0x1825b0 cmp r3, #0
 *   @0x1825b4 beq 0x18263c <_Z23_InvalidateTextureStatev+0xa4>
 *   @0x1825b8 cmp r3, #1
 *   @0x1825bc popne {r3, r4, r5, pc}
 *   @0x1825c0 ldr r2, [pc, #0xb8]
 *   @0x1825c4 ldr r1, [pc, #0xb8]
 *   @0x1825c8 ldr r3, [pc, #0xb8]
 *   @0x1825cc ldr r2, [r4, r2]
 *   @0x1825d0 ldr r5, [r4, r1]
 *   @0x1825d4 ldr r3, [r4, r3]
 *   @0x1825d8 ldr r2, [r2]
 *   @0x1825dc ldr r0, [r5]
 *   @0x1825e0 ldr r1, [r3, r2, lsl #2]
 *   @0x1825e4 cmp r1, r0
 *   @0x1825e8 beq 0x182600 <_Z23_InvalidateTextureStatev+0x68>
 *   @0x1825ec ldr r1, [pc, #0x98]
 *   @0x1825f0 ldr r1, [r4, r1]
 *   @0x1825f4 ldr r12, [r1]
 *   @0x1825f8 add r12, r12, #1
 *   @0x1825fc str r12, [r1]
 *   @0x182600 cmp r0, #0
 *   @0x182604 mov r1, #0
 *   @0x182608 str r1, [r3, r2, lsl #2]
 *   @0x18260c popeq {r3, r4, r5, pc}
 *   @0x182610 mvn r2, #0
 *   @0x182614 bl 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable>
 *   @0x182618 ldr r3, [pc, #0x70]
 *   @0x18261c ldr r2, [r5]
 *   @0x182620 movw r0, #0xde1
 *   @0x182624 ldr r3, [r4, r3]
 *   @0x182628 ldr r1, [r2, #0x14]
 *   @0x18262c ldr r3, [r3]
 *   @0x182630 blx r3
 *   @0x182634 pop {r3, r4, r5, lr}
 *   @0x182638 b 0x180b28 <_Z26_SetCurrentTextureSettingsv>
 *   @0x18263c ldr r12, [pc, #0x44]
 *   @0x182640 movw r0, #0xde1
 *   @0x182644 ldr r1, [pc, #0x48]
 *   @0x182648 ldr r2, [pc, #0x48]
 *   @0x18264c ldr r12, [r4, r12]
 *   @0x182650 str r3, [r12]
 *   @0x182654 ldr r1, [r4, r1]
 *   @0x182658 str r3, [r1]
 *   @0x18265c ldr r3, [r4, r2]
 *   @0x182660 ldr r3, [r3]
 *   @0x182664 blx r3
 *   @0x182668 ldr r3, [r5]
 *   @0x18266c cmp r3, #1
 *   @0x182670 popne {r3, r4, r5, pc}
 *   @0x182674 b 0x1825c0 <_Z23_InvalidateTextureStatev+0x28>
 *   @0x182678 eoreq pc, r6, r12, lsr #13
 *   @0x18267c .word 0xffffe7b8
 *   @0x182680 .word 0xffffe808
 *   @0x182684 .word 0xffffe8fc
 *   @0x182688 .word 0xffffe8e8
 *   @0x18268c .word 0xffffe740
 *   @0x182690 .word 0xffffbb20
 *   @0x182694 .word 0xffffe8f4
 *   @0x182698 .word 0xffffbad0
 *
 * ══ §23/31 PatchParents  0x19e978  size 260  65 条（0x19e978..0x19ea7c）
 * @func 0x19e978 0x19ea7c  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: PatchParents()+0xd8
 * 字段偏移 top8: 0x4×5 / 0xc×4 / 0x3×2 / 0x8×2 / 0xf8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19e978 ldr r3, [pc, #0xf8]
 *   @0x19e97c mov r12, #0
 *   @0x19e980 push {r4, r5, r6}
 *   @0x19e984 ldr r3, [pc, r3]
 *   @0x19e988 ldr r5, [r3]
 *   @0x19e98c ldr r1, [r5]
 *   @0x19e990 b 0x19e9a4 <_Z12PatchParentsv+0x2c>
 *   @0x19e994 ldr r3, [r5, #0x4]
 *   @0x19e998 add r12, r12, #1
 *   @0x19e99c cmp r12, r3
 *   @0x19e9a0 bgt 0x19ea30 <_Z12PatchParentsv+0xb8>
 *   @0x19e9a4 ldr r2, [r1, r12, lsl #3]
 *   @0x19e9a8 cmp r2, #0
 *   @0x19e9ac beq 0x19e994 <_Z12PatchParentsv+0x1c>
 *   @0x19e9b0 ldr r4, [r2, #0xc]
 *   @0x19e9b4 cmp r4, #0
 *   @0x19e9b8 beq 0x19ea30 <_Z12PatchParentsv+0xb8>
 *   @0x19e9bc movw r6, #0x869f
 *   @0x19e9c0 movt r6, #0x1
 *   @0x19e9c4 ldr r0, [r4, #0xc]
 *   @0x19e9c8 cmp r0, r6
 *   @0x19e9cc bhi 0x19ea10 <_Z12PatchParentsv+0x98>
 *   @0x19e9d0 ldr r1, [r5, #0x4]
 *   @0x19e9d4 ldr r3, [r5]
 *   @0x19e9d8 and r1, r0, r1
 *   @0x19e9dc ldr r3, [r3, r1, lsl #3]
 *   @0x19e9e0 cmp r3, #0
 *   @0x19e9e4 bne 0x19e9f8 <_Z12PatchParentsv+0x80>
 *   @0x19e9e8 b 0x19ea10 <_Z12PatchParentsv+0x98>
 *   @0x19e9ec ldr r3, [r3, #0x4]
 *   @0x19e9f0 cmp r3, #0
 *   @0x19e9f4 beq 0x19ea10 <_Z12PatchParentsv+0x98>
 *   @0x19e9f8 ldr r1, [r3, #0x8]
 *   @0x19e9fc cmp r0, r1
 *   @0x19ea00 bne 0x19e9ec <_Z12PatchParentsv+0x74>
 *   @0x19ea04 ldr r3, [r3, #0xc]
 *   @0x19ea08 cmp r3, #0
 *   @0x19ea0c strne r3, [r4, #0x48]
 *   @0x19ea10 cmp r2, #0
 *   @0x19ea14 beq 0x19ea30 <_Z12PatchParentsv+0xb8>
 *   @0x19ea18 ldr r2, [r2, #0x4]
 *   @0x19ea1c cmp r2, #0
 *   @0x19ea20 beq 0x19ea38 <_Z12PatchParentsv+0xc0>
 *   @0x19ea24 ldr r4, [r2, #0xc]
 *   @0x19ea28 cmp r4, #0
 *   @0x19ea2c bne 0x19e9c4 <_Z12PatchParentsv+0x4c>
 *   @0x19ea30 pop {r4, r5, r6}
 *   @0x19ea34 bx lr
 *   @0x19ea38 ldr r0, [r5, #0x4]
 *   @0x19ea3c add r3, r12, #1
 *   @0x19ea40 cmp r3, r0
 *   @0x19ea44 bgt 0x19ea30 <_Z12PatchParentsv+0xb8>
 *   @0x19ea48 ldr r1, [r5]
 *   @0x19ea4c add r1, r1, r12, lsl #3
 *   @0x19ea50 ldr r2, [r1, #0x8]
 *   @0x19ea54 mov r12, r3
 *   @0x19ea58 add r1, r1, #8
 *   @0x19ea5c add r3, r3, #1
 *   @0x19ea60 cmp r2, #0
 *   @0x19ea64 bne 0x19ea24 <_Z12PatchParentsv+0xac>
 *   @0x19ea68 cmp r3, r0
 *   @0x19ea6c ble 0x19ea50 <_Z12PatchParentsv+0xd8>
 *   @0x19ea70 pop {r4, r5, r6}
 *   @0x19ea74 bx lr
 *   @0x19ea78 .word 0x0024f2b8
 *
 * ══ §24/31 CLayerManager::GetNewBackgroundElement  0x1c0bd8  size 260  65 条（0x1c0bd8..0x1c0cdc）
 * @func 0x1c0bd8 0x1c0cdc  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetNewBackgroundElement()+0xbc / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CLayerManager::GetNewBackgroundElement()+0x38
 * 字段偏移 top8: 0x8×6 / 0x10×4 / 0x14×2 / 0x18×2 / 0xf0×1 / 0xd4×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c0bd8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1c0bdc ldr r4, [pc, #0xf0]
 *   @0x1c0be0 ldr r4, [pc, r4]
 *   @0x1c0be4 ldr r6, [r4, #0x8]
 *   @0x1c0be8 cmp r6, #0
 *   @0x1c0bec bne 0x1c0c9c <_ZN13CLayerManager23GetNewBackgroundElementEv+0xc4>
 *   @0x1c0bf0 ldr r3, [r4, #0x10]
 *   @0x1c0bf4 cmp r3, #0
 *   @0x1c0bf8 ble 0x1c0c94 <_ZN13CLayerManager23GetNewBackgroundElementEv+0xbc>
 *   @0x1c0bfc ldr r7, [pc, #0xd4]
 *   @0x1c0c00 mov r5, r6
 *   @0x1c0c04 mov r9, #1
 *   @0x1c0c08 mvn r8, #0
 *   @0x1c0c0c add r7, pc, r7
 *   @0x1c0c10 mov r0, #32
 *   @0x1c0c14 mov r1, r7
 *   @0x1c0c18 mov r2, #63
 *   @0x1c0c1c mov r3, #1
 *   @0x1c0c20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c0c24 cmp r0, #0
 *   @0x1c0c28 beq 0x1c0c4c <_ZN13CLayerManager23GetNewBackgroundElementEv+0x74>
 *   @0x1c0c2c strb r5, [r0, #0x8]
 *   @0x1c0c30 str r5, [r0, #0xc]
 *   @0x1c0c34 str r5, [r0, #0x10]
 *   @0x1c0c38 str r5, [r0, #0x14]
 *   @0x1c0c3c str r5, [r0, #0x18]
 *   @0x1c0c40 str r8, [r0, #0x4]
 *   @0x1c0c44 str r5, [r0, #0x1c]
 *   @0x1c0c48 str r9, [r0]
 *   @0x1c0c4c ldr r3, [r4]
 *   @0x1c0c50 add r6, r6, #1
 *   @0x1c0c54 ldr r2, [r4, #0x8]
 *   @0x1c0c58 cmp r3, #0
 *   @0x1c0c5c streq r0, [r4, #0x4]
 *   @0x1c0c60 strne r0, [r3, #0x18]
 *   @0x1c0c64 add r2, r2, #1
 *   @0x1c0c68 streq r3, [r0, #0x18]
 *   @0x1c0c6c streq r3, [r0, #0x14]
 *   @0x1c0c70 strne r3, [r0, #0x14]
 *   @0x1c0c74 ldr r3, [r4, #0x10]
 *   @0x1c0c78 streq r0, [r4]
 *   @0x1c0c7c strne r0, [r4]
 *   @0x1c0c80 strne r5, [r0, #0x18]
 *   @0x1c0c84 cmp r6, r3
 *   @0x1c0c88 str r2, [r4, #0x8]
 *   @0x1c0c8c blt 0x1c0c10 <_ZN13CLayerManager23GetNewBackgroundElementEv+0x38>
 *   @0x1c0c90 ldr r6, [r4, #0x8]
 *   @0x1c0c94 lsl r3, r3, #1
 *   @0x1c0c98 str r3, [r4, #0x10]
 *   @0x1c0c9c ldr r0, [r4]
 *   @0x1c0ca0 sub r6, r6, #1
 *   @0x1c0ca4 str r6, [r4, #0x8]
 *   @0x1c0ca8 ldr r3, [r0, #0x18]
 *   @0x1c0cac ldr r2, [r0, #0x14]
 *   @0x1c0cb0 cmp r3, #0
 *   @0x1c0cb4 strne r2, [r3, #0x14]
 *   @0x1c0cb8 ldrne r2, [r0, #0x14]
 *   @0x1c0cbc ldrne r3, [r0, #0x18]
 *   @0x1c0cc0 streq r2, [r4]
 *   @0x1c0cc4 cmp r2, #0
 *   @0x1c0cc8 streq r3, [r4, #0x4]
 *   @0x1c0ccc strne r3, [r2, #0x18]
 *   @0x1c0cd0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1c0cd4 eoreq pc, r2, r0, lsl #25
 *   @0x1c0cd8 andseq r12, r8, r8, lsl #21
 *
 * ══ §25/31 CLayerManager::GetNewParticleElement  0x1c115c  size 260  65 条（0x1c115c..0x1c1260）
 * @func 0x1c115c 0x1c1260  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetNewParticleElement()+0xbc / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CLayerManager::GetNewParticleElement()+0x34
 * 字段偏移 top8: 0x8×6 / 0x10×4 / 0x14×2 / 0x18×2 / 0xf0×1 / 0xd4×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c115c push {r4, r5, r6, r7, r8, lr}
 *   @0x1c1160 ldr r4, [pc, #0xf0]
 *   @0x1c1164 ldr r4, [pc, r4]
 *   @0x1c1168 ldr r6, [r4, #0x8]
 *   @0x1c116c cmp r6, #0
 *   @0x1c1170 bne 0x1c1220 <_ZN13CLayerManager21GetNewParticleElementEv+0xc4>
 *   @0x1c1174 ldr r3, [r4, #0x10]
 *   @0x1c1178 cmp r3, #0
 *   @0x1c117c ble 0x1c1218 <_ZN13CLayerManager21GetNewParticleElementEv+0xbc>
 *   @0x1c1180 ldr r8, [pc, #0xd4]
 *   @0x1c1184 mov r5, r6
 *   @0x1c1188 mvn r7, #0
 *   @0x1c118c add r8, pc, r8
 *   @0x1c1190 mov r3, #1
 *   @0x1c1194 mov r0, #32
 *   @0x1c1198 mov r1, r8
 *   @0x1c119c mov r2, #63
 *   @0x1c11a0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c11a4 mov r3, #6
 *   @0x1c11a8 cmp r0, #0
 *   @0x1c11ac beq 0x1c11d0 <_ZN13CLayerManager21GetNewParticleElementEv+0x74>
 *   @0x1c11b0 strb r5, [r0, #0x8]
 *   @0x1c11b4 str r5, [r0, #0xc]
 *   @0x1c11b8 str r5, [r0, #0x10]
 *   @0x1c11bc str r5, [r0, #0x14]
 *   @0x1c11c0 str r5, [r0, #0x18]
 *   @0x1c11c4 str r7, [r0, #0x4]
 *   @0x1c11c8 str r7, [r0, #0x1c]
 *   @0x1c11cc str r3, [r0]
 *   @0x1c11d0 ldr r3, [r4]
 *   @0x1c11d4 add r6, r6, #1
 *   @0x1c11d8 ldr r2, [r4, #0x8]
 *   @0x1c11dc cmp r3, #0
 *   @0x1c11e0 streq r0, [r4, #0x4]
 *   @0x1c11e4 strne r0, [r3, #0x18]
 *   @0x1c11e8 add r2, r2, #1
 *   @0x1c11ec streq r3, [r0, #0x18]
 *   @0x1c11f0 streq r3, [r0, #0x14]
 *   @0x1c11f4 strne r3, [r0, #0x14]
 *   @0x1c11f8 ldr r3, [r4, #0x10]
 *   @0x1c11fc streq r0, [r4]
 *   @0x1c1200 strne r0, [r4]
 *   @0x1c1204 strne r5, [r0, #0x18]
 *   @0x1c1208 cmp r6, r3
 *   @0x1c120c str r2, [r4, #0x8]
 *   @0x1c1210 blt 0x1c1190 <_ZN13CLayerManager21GetNewParticleElementEv+0x34>
 *   @0x1c1214 ldr r6, [r4, #0x8]
 *   @0x1c1218 lsl r3, r3, #1
 *   @0x1c121c str r3, [r4, #0x10]
 *   @0x1c1220 ldr r0, [r4]
 *   @0x1c1224 sub r6, r6, #1
 *   @0x1c1228 str r6, [r4, #0x8]
 *   @0x1c122c ldr r3, [r0, #0x18]
 *   @0x1c1230 ldr r2, [r0, #0x14]
 *   @0x1c1234 cmp r3, #0
 *   @0x1c1238 strne r2, [r3, #0x14]
 *   @0x1c123c ldrne r2, [r0, #0x14]
 *   @0x1c1240 ldrne r3, [r0, #0x18]
 *   @0x1c1244 streq r2, [r4]
 *   @0x1c1248 cmp r2, #0
 *   @0x1c124c streq r3, [r4, #0x4]
 *   @0x1c1250 strne r3, [r2, #0x18]
 *   @0x1c1254 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c1258 eoreq pc, r2, r0, lsl r7
 *   @0x1c125c andseq r12, r8, r8, lsl #10
 *
 * ══ §26/31 CPhysicsWorld::CPhysicsWorld  0x237d90  size 260  65 条（0x237d90..0x237e94）
 * @func 0x237d90 0x237e94  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / operator new(unsigned int) / b2World::b2World(b2Vec2 const&) / CPhysicsWorld::Init()
 * 字段偏移 top8: 0xb8×2 / 0x10×2 / 0x60×2 / 0x5c×2 / 0x58×2 / 0xe8×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237d90 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x237d94 mov r6, r1
 *   @0x237d98 ldr r1, [pc, #0xe8]
 *   @0x237d9c mov r4, r0
 *   @0x237da0 sub sp, sp, #12
 *   @0x237da4 mov r5, #0
 *   @0x237da8 mov r3, #10
 *   @0x237dac mov r2, #55
 *   @0x237db0 str r3, [r0, #0x8]
 *   @0x237db4 add r1, pc, r1
 *   @0x237db8 str r5, [r4, #0x4]
 *   @0x237dbc mov r3, #1
 *   @0x237dc0 movw r0, #0x1bf8
 *   @0x237dc4 add r8, r4, #28
 *   @0x237dc8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x237dcc ldr r3, [pc, #0xb8]
 *   @0x237dd0 ldr r12, [pc, #0xb8]
 *   @0x237dd4 add r7, r4, #40
 *   @0x237dd8 ldr r3, [pc, r3]
 *   @0x237ddc str r5, [r4, #0x14]
 *   @0x237de0 ldr r12, [pc, r12]
 *   @0x237de4 str r5, [r4, #0x18]
 *   @0x237de8 mov r10, #0
 *   @0x237dec mov r2, #1
 *   @0x237df0 movw lr, #0x9238
 *   @0x237df4 bfi lr, r2, #16, #16
 *   @0x237df8 lsl r9, r2, #16
 *   @0x237dfc mov r11, #1065353216
 *   @0x237e00 str r0, [r4]
 *   @0x237e04 ldm r3, {r0, r1}
 *   @0x237e08 stm r8, {r0, r1}
 *   @0x237e0c str r10, [r4, #0x24]
 *   @0x237e10 stm r7, {r0, r1}
 *   @0x237e14 ldr r0, [r12]
 *   @0x237e18 str r10, [r4, #0x30]
 *   @0x237e1c str r11, [r4, #0x38]
 *   @0x237e20 str r0, [r4, #0x34]
 *   @0x237e24 ldr r3, [r6, #0x10]
 *   @0x237e28 ldr r1, [r6, #0x60]
 *   @0x237e2c add lr, r3, lr
 *   @0x237e30 ldr r12, [r6, #0x5c]
 *   @0x237e34 ldr r3, [r6, #0x58]
 *   @0x237e38 str r1, [r4, #0x60]
 *   @0x237e3c ldm lr, {r0, r1}
 *   @0x237e40 strb r2, [r4, #0x40]
 *   @0x237e44 str r12, [r4, #0x5c]
 *   @0x237e48 stm sp, {r0, r1}
 *   @0x237e4c orr r0, r9, #37632
 *   @0x237e50 str r3, [r4, #0x58]
 *   @0x237e54 orr r0, r0, #84
 *   @0x237e58 str r5, [r4, #0x3c]
 *   @0x237e5c str r5, [r4, #0x44]
 *   @0x237e60 bl 0x27c524 <_Znwj>
 *   @0x237e64 mov r1, sp
 *   @0x237e68 mov r6, r0
 *   @0x237e6c bl 0x2c8e10 <_ZN7b2WorldC2ERK6b2Vec2>
 *   @0x237e70 mov r0, r4
 *   @0x237e74 str r6, [r4, #0x10]
 *   @0x237e78 bl 0x237bf8 <_ZN13CPhysicsWorld4InitEv>
 *   @0x237e7c mov r0, r4
 *   @0x237e80 add sp, sp, #12
 *   @0x237e84 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x237e88 andseq sp, r1, r0, asr r4
 *   @0x237e8c andseq r9, r11, r0, lsl #14
 *   @0x237e90 ldrsheq r9, [r11], -r12
 *
 * ══ §27/31 spAnimationState_update  0x2837fc  size 260  65 条（0x2837fc..0x283900）
 * @func 0x2837fc 0x283900  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spAnimationState_update+0xfc×2 / spAnimationState_update+0x50×2 / _spAnimationState_setCurrent / spAnimationState_clearTrack
 * 字段偏移 top8: 0xc×3 / 0x10×2 / 0x2×1 / 0x8×1 / 0x4×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2837fc push {r4, r5, r6, lr}
 *   @0x283800 vpush {d8}
 *   @0x283804 vmov s15, r1
 *   @0x283808 vldr s16, [r0, #4]
 *   @0x28380c ldr r6, [r0, #0xc]
 *   @0x283810 mov r5, r0
 *   @0x283814 vmul.f32 s16, s15, s16
 *   @0x283818 cmp r6, #0
 *   @0x28381c ble 0x2838f8 <spAnimationState_update+0xfc>
 *   @0x283820 mov r4, #0
 *   @0x283824 b 0x283858 <spAnimationState_update+0x5c>
 *   @0x283828 vldr s14, [r3, #28]
 *   @0x28382c vldr s15, [r12, #20]
 *   @0x283830 vsub.f32 s15, s14, s15
 *   @0x283834 vcmpe.f32 s15, #0
 *   @0x283838 vstr s15, [r12, #24]
 *   @0x28383c vmrs APSR_nzcv, fpscr
 *   @0x283840 blt 0x28384c <spAnimationState_update+0x50>
 *   @0x283844 bl 0x283698 <_spAnimationState_setCurrent>
 *   @0x283848 ldr r6, [r5, #0xc]
 *   @0x28384c add r4, r4, #1
 *   @0x283850 cmp r6, r4
 *   @0x283854 ble 0x2838f8 <spAnimationState_update+0xfc>
 *   @0x283858 ldr r3, [r5, #0x10]
 *   @0x28385c ldr r3, [r3, r4, lsl #2]
 *   @0x283860 cmp r3, #0
 *   @0x283864 beq 0x28384c <spAnimationState_update+0x50>
 *   @0x283868 vldr s15, [r3, #24]
 *   @0x28386c vldr s14, [r3, #36]
 *   @0x283870 vmla.f32 s15, s16, s14
 *   @0x283874 ldr r2, [r3, #0x8]
 *   @0x283878 mov r0, r5
 *   @0x28387c mov r1, r4
 *   @0x283880 cmp r2, #0
 *   @0x283884 vstr s15, [r3, #24]
 *   @0x283888 beq 0x2838ac <spAnimationState_update+0xb0>
 *   @0x28388c vldr s15, [r2, #36]
 *   @0x283890 vmul.f32 s15, s16, s15
 *   @0x283894 vldr s14, [r2, #24]
 *   @0x283898 vldr s13, [r3, #44]
 *   @0x28389c vadd.f32 s14, s14, s15
 *   @0x2838a0 vadd.f32 s15, s13, s15
 *   @0x2838a4 vstr s14, [r2, #24]
 *   @0x2838a8 vstr s15, [r3, #44]
 *   @0x2838ac ldr r12, [r3, #0x4]
 *   @0x2838b0 cmp r12, #0
 *   @0x2838b4 mov r2, r12
 *   @0x2838b8 bne 0x283828 <spAnimationState_update+0x2c>
 *   @0x2838bc ldr r2, [r3, #0x10]
 *   @0x2838c0 cmp r2, #0
 *   @0x2838c4 bne 0x28384c <spAnimationState_update+0x50>
 *   @0x2838c8 vldr s14, [r3, #28]
 *   @0x2838cc vldr s15, [r3, #32]
 *   @0x2838d0 vcmpe.f32 s14, s15
 *   @0x2838d4 vmrs APSR_nzcv, fpscr
 *   @0x2838d8 blt 0x28384c <spAnimationState_update+0x50>
 *   @0x2838dc mov r1, r4
 *   @0x2838e0 mov r0, r5
 *   @0x2838e4 bl 0x283558 <spAnimationState_clearTrack>
 *   @0x2838e8 ldr r6, [r5, #0xc]
 *   @0x2838ec add r4, r4, #1
 *   @0x2838f0 cmp r6, r4
 *   @0x2838f4 bgt 0x283858 <spAnimationState_update+0x5c>
 *   @0x2838f8 vpop {d8}
 *   @0x2838fc pop {r4, r5, r6, pc}
 *
 * ══ §28/31 spPathConstraint_create  0x28796c  size 260  65 条（0x28796c..0x287a70）
 * @func 0x28796c 0x287a70  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / _malloc / spPathConstraint_create+0x94 / spSkeleton_findBone / spSkeleton_findSlot
 * 字段偏移 top8: 0x4×6 / 0x8×3 / 0x2×2 / 0xc×2 / 0x20×2 / 0x24×2 / 0x28×2 / 0x2c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28796c push {r4, r5, r6, r7, r8, lr}
 *   @0x287970 mov r3, #42
 *   @0x287974 ldr r5, [pc, #0xf0]
 *   @0x287978 mov r8, r0
 *   @0x28797c mov r7, r1
 *   @0x287980 mov r0, #1
 *   @0x287984 add r5, pc, r5
 *   @0x287988 mov r1, #112
 *   @0x28798c mov r2, r5
 *   @0x287990 bl 0x285c4c <_calloc>
 *   @0x287994 mov r1, r5
 *   @0x287998 mov r2, #45
 *   @0x28799c mov r4, r0
 *   @0x2879a0 ldr r0, [r8, #0x4]
 *   @0x2879a4 str r8, [r4]
 *   @0x2879a8 str r0, [r4, #0x4]
 *   @0x2879ac lsl r0, r0, #2
 *   @0x2879b0 bl 0x285c10 <_malloc>
 *   @0x2879b4 ldr r3, [r4, #0x4]
 *   @0x2879b8 cmp r3, #0
 *   @0x2879bc str r0, [r4, #0x8]
 *   @0x2879c0 ble 0x287a00 <spPathConstraint_create+0x94>
 *   @0x2879c4 mov r6, r0
 *   @0x2879c8 mov r5, #0
 *   @0x2879cc b 0x2879d4 <spPathConstraint_create+0x68>
 *   @0x2879d0 ldr r6, [r4, #0x8]
 *   @0x2879d4 ldr r3, [r4]
 *   @0x2879d8 mov r0, r7
 *   @0x2879dc ldr r3, [r3, #0x8]
 *   @0x2879e0 ldr r3, [r3, r5, lsl #2]
 *   @0x2879e4 ldr r1, [r3, #0x4]
 *   @0x2879e8 bl 0x28a0c8 <spSkeleton_findBone>
 *   @0x2879ec ldr r3, [r4, #0x4]
 *   @0x2879f0 str r0, [r6, r5, lsl #2]
 *   @0x2879f4 add r5, r5, #1
 *   @0x2879f8 cmp r3, r5
 *   @0x2879fc bgt 0x2879d0 <spPathConstraint_create+0x64>
 *   @0x287a00 ldr r3, [r4]
 *   @0x287a04 mov r0, r7
 *   @0x287a08 ldr r3, [r3, #0xc]
 *   @0x287a0c ldr r1, [r3, #0x4]
 *   @0x287a10 bl 0x28a18c <spSkeleton_findSlot>
 *   @0x287a14 ldr r2, [r8, #0x20]
 *   @0x287a18 ldr r3, [r8, #0x24]
 *   @0x287a1c str r2, [r4, #0x10]
 *   @0x287a20 str r3, [r4, #0x14]
 *   @0x287a24 ldr r2, [r8, #0x28]
 *   @0x287a28 ldr r3, [r8, #0x2c]
 *   @0x287a2c str r2, [r4, #0x18]
 *   @0x287a30 str r3, [r4, #0x1c]
 *   @0x287a34 mov r3, #0
 *   @0x287a38 str r3, [r4, #0x20]
 *   @0x287a3c str r3, [r4, #0x24]
 *   @0x287a40 str r3, [r4, #0x28]
 *   @0x287a44 str r3, [r4, #0x2c]
 *   @0x287a48 str r3, [r4, #0x30]
 *   @0x287a4c str r3, [r4, #0x34]
 *   @0x287a50 str r3, [r4, #0x38]
 *   @0x287a54 str r3, [r4, #0x3c]
 *   @0x287a58 str r3, [r4, #0x40]
 *   @0x287a5c str r3, [r4, #0x44]
 *   @0x287a60 str r0, [r4, #0xc]
 *   @0x287a64 mov r0, r4
 *   @0x287a68 pop {r4, r5, r6, r7, r8, pc}
 *   @0x287a6c .word 0x000cfff4
 *
 * ══ §29/31 CSkeletonSprite::DrawMesh  0xbdf54  size 256  64 条（0xbdf54..0xbe054）
 * @func 0xbdf54 0xbe054  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / spMeshAttachment_computeWorldVertices / Graphics::AllocVerts(ePrimType, void*, int, int) / CSkeletonSprite::DrawMesh(spSlot*, unsigned int)+0xe8
 * 字段偏移 top8: 0x18×2 / 0x60×2 / 0x2×2 / 0xdc×1 / 0x24×1 / 0xac×1 / 0x48×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbdf54 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xbdf58 mov r7, r1
 *   @0xbdf5c ldr r4, [r1, #0x18]
 *   @0xbdf60 mov r3, #1
 *   @0xbdf64 ldr r1, [pc, #0xdc]
 *   @0xbdf68 mov r6, r2
 *   @0xbdf6c movw r2, #0x275
 *   @0xbdf70 ldr r0, [r4, #0x18]
 *   @0xbdf74 add r1, pc, r1
 *   @0xbdf78 lsl r0, r0, #2
 *   @0xbdf7c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xbdf80 mov r1, r7
 *   @0xbdf84 mov r5, r0
 *   @0xbdf88 mov r0, r4
 *   @0xbdf8c mov r2, r5
 *   @0xbdf90 bl 0x287650 <spMeshAttachment_computeWorldVertices>
 *   @0xbdf94 ldr r12, [r4, #0x24]
 *   @0xbdf98 ldr r1, [pc, #0xac]
 *   @0xbdf9c mov r0, #4
 *   @0xbdfa0 ldr r3, [r4, #0x60]
 *   @0xbdfa4 mov r2, #24
 *   @0xbdfa8 ldr r12, [r12, #0x48]
 *   @0xbdfac ldr r1, [pc, r1]
 *   @0xbdfb0 ldr r1, [r1, #0x4]
 *   @0xbdfb4 ldr r12, [r12, #0x1c]
 *   @0xbdfb8 ldr r1, [r1, r12, lsl #2]
 *   @0xbdfbc ldr r1, [r1]
 *   @0xbdfc0 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0xbdfc4 ldr r7, [r4, #0x60]
 *   @0xbdfc8 cmp r7, #0
 *   @0xbdfcc ble 0xbe03c <_ZN15CSkeletonSprite8DrawMeshEP6spSlotj+0xe8>
 *   @0xbdfd0 ldr r2, [pc, #0x78]
 *   @0xbdfd4 add r3, r0, #24
 *   @0xbdfd8 ldr r12, [r4, #0x64]
 *   @0xbdfdc ldr r2, [pc, r2]
 *   @0xbdfe0 ldr r0, [r4, #0x5c]
 *   @0xbdfe4 add r7, r12, r7, lsl #1
 *   @0xbdfe8 ldr r9, [r2]
 *   @0xbdfec ldrh r1, [r12], #2
 *   @0xbdff0 add r3, r3, #24
 *   @0xbdff4 cmp r12, r7
 *   @0xbdff8 lsl r1, r1, #3
 *   @0xbdffc add r2, r5, r1
 *   @0xbe000 add r4, r1, #4
 *   @0xbe004 add r1, r0, r1
 *   @0xbe008 ldr r8, [r2]
 *   @0xbe00c add r2, r5, r4
 *   @0xbe010 add r4, r0, r4
 *   @0xbe014 str r8, [r3, #-0x30]
 *   @0xbe018 ldr r2, [r2]
 *   @0xbe01c str r2, [r3, #-0x2c]
 *   @0xbe020 ldr r2, [r1]
 *   @0xbe024 str r2, [r3, #-0x20]
 *   @0xbe028 ldr r2, [r4]
 *   @0xbe02c str r9, [r3, #-0x28]
 *   @0xbe030 str r6, [r3, #-0x24]
 *   @0xbe034 str r2, [r3, #-0x1c]
 *   @0xbe038 bne 0xbdfec <_ZN15CSkeletonSprite8DrawMeshEP6spSlotj+0x98>
 *   @0xbe03c mov r0, r5
 *   @0xbe040 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xbe044 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xbe048 eoreq r2, r7, r12, asr #16
 *   @0xbe04c eorseq pc, r2, r0, ror r9
 *   @0xbe050 eorseq pc, r2, r4, asr #18
 *
 * ══ §30/31 YYObjectBase::YYObjectBase  0x19188c  size 256  64 条（0x19188c..0x19198c）
 * @func 0x19188c 0x19198c  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1918a0→0x3ebad8, 0x1918c0→0x536d88, 0x1918dc→0x536f08, 0x191910→0x47b23b
 * 调用序列: MemoryManager::GetStackTrace() / vmGetCallStack()
 * 字段偏移 top8: 0xd4×2 / 0x4×2 / 0xe0×1 / 0xb8×1 / 0x8×1 / 0xc×1 / 0xa0×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19188c ldr r12, [pc, #0xe0]
 *   @0x191890 push {r4, r5, r6, lr}
 *   @0x191894 add r12, pc, r12
 *   @0x191898 mov r4, r0
 *   @0x19189c ldr r0, [pc, #0xd4]
 *   @0x1918a0 ldr r5, [pc, #0xd4]
 *   @0x1918a4 add r0, pc, r0
 *   @0x1918a8 ldrb r3, [r12]
 *   @0x1918ac ldr r5, [r0, r5]
 *   @0x1918b0 cmp r3, #0
 *   @0x1918b4 add r5, r5, #8
 *   @0x1918b8 str r5, [r4]
 *   @0x1918bc bne 0x1918dc <_ZN12YYObjectBaseC2Eii+0x50>
 *   @0x1918c0 ldr r5, [pc, #0xb8]
 *   @0x1918c4 mov r6, #1
 *   @0x1918c8 ldr r5, [r0, r5]
 *   @0x1918cc strb r6, [r12]
 *   @0x1918d0 str r3, [r5, #0x4]
 *   @0x1918d4 str r3, [r5, #0x8]
 *   @0x1918d8 str r3, [r5, #0xc]
 *   @0x1918dc ldr r12, [pc, #0xa0]
 *   @0x1918e0 mov r3, #0
 *   @0x1918e4 str r3, [r4, #0x18]
 *   @0x1918e8 mvn r5, #0
 *   @0x1918ec str r3, [r4, #0x20]
 *   @0x1918f0 str r3, [r4, #0x1c]
 *   @0x1918f4 str r3, [r4, #0x30]
 *   @0x1918f8 ldr r12, [r0, r12]
 *   @0x1918fc str r3, [r4, #0x38]
 *   @0x191900 str r3, [r4, #0x48]
 *   @0x191904 ldr r12, [r12]
 *   @0x191908 str r3, [r4, #0x4]
 *   @0x19190c str r3, [r4, #0x60]
 *   @0x191910 ldr r3, [pc, #0x70]
 *   @0x191914 str r1, [r4, #0x24]
 *   @0x191918 str r1, [r4, #0x2c]
 *   @0x19191c mov r1, #1
 *   @0x191920 str r2, [r4, #0x58]
 *   @0x191924 mov r2, #0
 *   @0x191928 str r12, [r4, #0x34]
 *   @0x19192c str r12, [r4, #0x3c]
 *   @0x191930 str r5, [r4, #0x44]
 *   @0x191934 str r1, [r4, #0x28]
 *   @0x191938 str r2, [r4, #0x4c]
 *   @0x19193c ldr r3, [r0, r3]
 *   @0x191940 ldrb r3, [r3]
 *   @0x191944 cmp r3, r2
 *   @0x191948 streq r3, [r4, #0x10]
 *   @0x19194c streq r3, [r4, #0x14]
 *   @0x191950 bne 0x19195c <_ZN12YYObjectBaseC2Eii+0xd0>
 *   @0x191954 mov r0, r4
 *   @0x191958 pop {r4, r5, r6, pc}
 *   @0x19195c bl 0x27d258 <_ZN13MemoryManager13GetStackTraceEv>
 *   @0x191960 str r0, [r4, #0x10]
 *   @0x191964 bl 0xdb934 <_Z14vmGetCallStackv>
 *   @0x191968 str r0, [r4, #0x14]
 *   @0x19196c mov r0, r4
 *   @0x191970 pop {r4, r5, r6, pc}
 *   @0x191974 ldrsbteq r5, [r10], -r12
 *   @0x191978 eoreq r0, r6, r12, lsr #7
 *   @0x19197c .word 0xffffea28
 *   @0x191980 .word 0xffffea20
 *   @0x191984 .word 0xffffbffc
 *   @0x191988 .word 0xffffc7cc
 *
 * ══ §31/31 RebuildTree  0x1cdb1c  size 256  64 条（0x1cdb1c..0x1cdc1c）
 * @func 0x1cdb1c 0x1cdc1c  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / RTree<CInstance*, int, float, 6, 2>::RTree(int) / RTree<CInstance*, int, float, 6, 2>::InsertRect(RTree<CInstance*, int, float, 6, 2>::Branch const&, RTree<CInstance*, int, float, 6, 2>::Node**, int) / CInstance::Compute_BoundingBox(bool)
 * 字段偏移 top8: 0x80×2 / 0xe4×1 / 0xd4×1 / 0x68×1 / 0x178×1 / 0x69×1 / 0x64×1 / 0xe8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cdb1c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1cdb20 mov r0, #24
 *   @0x1cdb24 sub sp, sp, #28
 *   @0x1cdb28 ldr r5, [pc, #0xe4]
 *   @0x1cdb2c bl 0x27c524 <_Znwj>
 *   @0x1cdb30 mov r1, #1024
 *   @0x1cdb34 mov r4, r0
 *   @0x1cdb38 bl 0x1cc320 <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei>
 *   @0x1cdb3c ldr r3, [pc, #0xd4]
 *   @0x1cdb40 ldr r5, [pc, r5]
 *   @0x1cdb44 ldr r3, [pc, r3]
 *   @0x1cdb48 str r4, [r5]
 *   @0x1cdb4c ldr r3, [r3]
 *   @0x1cdb50 ldr r2, [r3, #0x80]
 *   @0x1cdb54 cmp r2, #0
 *   @0x1cdb58 beq 0x1cdbfc <_Z11RebuildTreev+0xe0>
 *   @0x1cdb5c ldrb r3, [r2, #0x68]
 *   @0x1cdb60 ldr r4, [r2, #0x178]
 *   @0x1cdb64 cmp r3, #0
 *   @0x1cdb68 bne 0x1cdbf0 <_Z11RebuildTreev+0xd4>
 *   @0x1cdb6c ldrb r3, [r2, #0x69]
 *   @0x1cdb70 cmp r3, #0
 *   @0x1cdb74 bne 0x1cdbf0 <_Z11RebuildTreev+0xd4>
 *   @0x1cdb78 ldr r3, [r2, #0x80]
 *   @0x1cdb7c ldr r3, [r3]
 *   @0x1cdb80 tst r3, #16
 *   @0x1cdb84 beq 0x1cdbf0 <_Z11RebuildTreev+0xd4>
 *   @0x1cdb88 ldrb r12, [r2, #0x64]
 *   @0x1cdb8c mov r1, sp
 *   @0x1cdb90 cmp r12, #0
 *   @0x1cdb94 mov r3, r12
 *   @0x1cdb98 bne 0x1cdc04 <_Z11RebuildTreev+0xe8>
 *   @0x1cdb9c ldr r8, [r2, #0xe8]
 *   @0x1cdba0 ldr r9, [r2, #0xf0]
 *   @0x1cdba4 ldr lr, [r2, #0xec]
 *   @0x1cdba8 ldr r7, [r2, #0xf4]
 *   @0x1cdbac ldr r0, [r5]
 *   @0x1cdbb0 str r2, [sp, #0x14]
 *   @0x1cdbb4 add r2, r0, #16
 *   @0x1cdbb8 str r12, [sp, #0x10]
 *   @0x1cdbbc cmp r9, r8
 *   @0x1cdbc0 strle r9, [sp]
 *   @0x1cdbc4 strgt r8, [sp]
 *   @0x1cdbc8 cmp r9, r8
 *   @0x1cdbcc strge r9, [sp, #0x8]
 *   @0x1cdbd0 strlt r8, [sp, #0x8]
 *   @0x1cdbd4 cmp r7, lr
 *   @0x1cdbd8 strle r7, [sp, #0x4]
 *   @0x1cdbdc strgt lr, [sp, #0x4]
 *   @0x1cdbe0 cmp r7, lr
 *   @0x1cdbe4 strge r7, [sp, #0xc]
 *   @0x1cdbe8 strlt lr, [sp, #0xc]
 *   @0x1cdbec bl 0x1cd700 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi>
 *   @0x1cdbf0 cmp r4, #0
 *   @0x1cdbf4 mov r2, r4
 *   @0x1cdbf8 bne 0x1cdb5c <_Z11RebuildTreev+0x40>
 *   @0x1cdbfc add sp, sp, #28
 *   @0x1cdc00 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1cdc04 mov r1, #1
 *   @0x1cdc08 mov r0, r2
 *   @0x1cdc0c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x1cdc10 b 0x1cdbf0 <_Z11RebuildTreev+0xd4>
 *   @0x1cdc14 eoreq r0, r2, r4, lsl #14
 *   @0x1cdc18 eoreq pc, r1, r4, ror #27
 */
