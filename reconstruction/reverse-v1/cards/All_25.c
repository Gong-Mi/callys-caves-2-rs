/* cally 逆向卡：All_25 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 16 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/16 GraphicsRecorder::Draw(float, float, float)  0x185a24  size 2424  606 条（0x185a24..0x18639c）
 * @func 0x185a24 0x18639c  size 2424  606 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::SetTexture(int, void*)×6 / Graphics::SetMatrix(eMatrix, float*)×2 / DirtyRoomExtents()×2 / GR_D3D_Set_Texture_Repeat(bool)×2 / Graphics::Flush()×2 / Graphics::AllocVerts(ePrimType, void*, int, int)×2 / 0xb65bc×2 / StartShaderBlock(int)×2
 * 字段偏移 top8: 0x1c×15 / 0x10×9 / 0x18×9 / 0x8×8 / 0xc×8 / 0x4×8 / 0x14×7 / 0x24×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x185a24 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x185a28 sub sp, sp, #228
 *   @0x185a2c add r5, sp, #32
 *   @0x185a30 mov r7, r1
 *   @0x185a34 str r5, [sp, #0x10]
 *   @0x185a38 mov r4, r0
 *   @0x185a3c mov r1, r5
 *   @0x185a40 add r5, sp, #160
 *   @0x185a44 mov r0, #2
 *   @0x185a48 mov r8, r3
 *   @0x185a4c mov r6, r2
 *   @0x185a50 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x185a54 add r2, sp, #32
 *   @0x185a58 mov r0, r5
 *   @0x185a5c add r1, sp, #96
 *   @0x185a60 mov r12, #0
 *   @0x185a64 mov lr, #1065353216
 *   @0x185a68 str r12, [sp, #0x8c]
 *   @0x185a6c str r12, [sp, #0x84]
 *   @0x185a70 str r12, [sp, #0x80]
 *   @0x185a74 str r12, [sp, #0x7c]
 *   @0x185a78 str r12, [sp, #0x78]
 *   @0x185a7c str lr, [sp, #0x9c]
 *   @0x185a80 str lr, [sp, #0x88]
 *   @0x185a84 str lr, [sp, #0x74]
 *   @0x185a88 str lr, [sp, #0x60]
 *   @0x185a8c str r12, [sp, #0x70]
 *   @0x185a90 str r12, [sp, #0x6c]
 *   @0x185a94 str r12, [sp, #0x68]
 *   @0x185a98 str r12, [sp, #0x64]
 *   @0x185a9c str r7, [sp, #0x90]
 *   @0x185aa0 str r6, [sp, #0x94]
 *   @0x185aa4 str r8, [sp, #0x98]
 *   @0x185aa8 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x185aac mov r1, r5
 *   @0x185ab0 mov r0, #2
 *   @0x185ab4 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x185ab8 ldr r5, [pc, #0x8a4]
 *   @0x185abc bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x185ac0 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv>
 *   @0x185ac4 add r5, pc, r5
 *   @0x185ac8 str r0, [sp, #0x14]
 *   @0x185acc mov r0, #1
 *   @0x185ad0 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x185ad4 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x185ad8 ldr r1, [r4, #0x14]
 *   @0x185adc cmp r1, #0
 *   @0x185ae0 beq 0x185b54 <_ZN16GraphicsRecorder4DrawEfff+0x130>
 *   @0x185ae4 ldr r3, [pc, #0x87c]
 *   @0x185ae8 ldr r3, [r5, r3]
 *   @0x185aec ldrb r3, [r3]
 *   @0x185af0 cmp r3, #0
 *   @0x185af4 beq 0x185c5c <_ZN16GraphicsRecorder4DrawEfff+0x238>
 *   @0x185af8 ldr r3, [r4, #0x18]
 *   @0x185afc cmp r3, #0
 *   @0x185b00 beq 0x1862d4 <_ZN16GraphicsRecorder4DrawEfff+0x8b0>
 *   @0x185b04 ldr r1, [pc, #0x860]
 *   @0x185b08 ldr r2, [r3, #0x8]
 *   @0x185b0c ldr r3, [r5, r1]
 *   @0x185b10 ldr r3, [r3]
 *   @0x185b14 cmp r2, r3
 *   @0x185b18 beq 0x185b30 <_ZN16GraphicsRecorder4DrawEfff+0x10c>
 *   @0x185b1c mov r0, r4
 *   @0x185b20 bl 0x1857d8 <_ZN16GraphicsRecorder15DeleteHWBuffersEv>
 *   @0x185b24 ldr r3, [r4, #0x18]
 *   @0x185b28 cmp r3, #0
 *   @0x185b2c beq 0x1862d0 <_ZN16GraphicsRecorder4DrawEfff+0x8ac>
 *   @0x185b30 ldr r3, [pc, #0x838]
 *   @0x185b34 ldr r3, [r5, r3]
 *   @0x185b38 str r3, [sp, #0x8]
 *   @0x185b3c ldr r3, [r3]
 *   @0x185b40 cmp r3, #1
 *   @0x185b44 movne r6, r3
 *   @0x185b48 beq 0x185fd4 <_ZN16GraphicsRecorder4DrawEfff+0x5b0>
 *   @0x185b4c cmp r6, #0
 *   @0x185b50 beq 0x185e28 <_ZN16GraphicsRecorder4DrawEfff+0x404>
 *   @0x185b54 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv>
 *   @0x185b58 ldr r3, [r4, #0x24]
 *   @0x185b5c cmp r3, #0
 *   @0x185b60 mov r7, r0
 *   @0x185b64 beq 0x185bd4 <_ZN16GraphicsRecorder4DrawEfff+0x1b0>
 *   @0x185b68 ldr r5, [r4, #0x2c]
 *   @0x185b6c cmp r5, #0
 *   @0x185b70 ble 0x185bd4 <_ZN16GraphicsRecorder4DrawEfff+0x1b0>
 *   @0x185b74 cmp r5, r7
 *   @0x185b78 movlt r3, r5
 *   @0x185b7c movge r3, r7
 *   @0x185b80 ldr r1, [r4, #0x10]
 *   @0x185b84 mov r2, #36
 *   @0x185b88 mov r0, #2
 *   @0x185b8c lsr r12, r3, #31
 *   @0x185b90 add r6, r3, r12
 *   @0x185b94 and r6, r6, #1
 *   @0x185b98 rsb r6, r12, r6
 *   @0x185b9c rsb r6, r6, r3
 *   @0x185ba0 mov r3, r6
 *   @0x185ba4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x185ba8 ldr r3, [r4, #0x2c]
 *   @0x185bac ldr r1, [r4, #0x24]
 *   @0x185bb0 add r2, r6, r6, lsl #3
 *   @0x185bb4 rsb r3, r5, r3
 *   @0x185bb8 rsb r5, r6, r5
 *   @0x185bbc lsl r2, r2, #2
 *   @0x185bc0 add r3, r3, r3, lsl #3
 *   @0x185bc4 add r1, r1, r3, lsl #2
 *   @0x185bc8 bl 0xb65bc <memcpy@plt>
 *   @0x185bcc cmp r5, #0
 *   @0x185bd0 bgt 0x185b74 <_ZN16GraphicsRecorder4DrawEfff+0x150>
 *   @0x185bd4 ldr r3, [r4, #0x34]
 *   @0x185bd8 cmp r3, #0
 *   @0x185bdc beq 0x185c38 <_ZN16GraphicsRecorder4DrawEfff+0x214>
 *   @0x185be0 ldr r5, [r4, #0x3c]
 *   @0x185be4 cmp r5, #0
 *   @0x185be8 ble 0x185c38 <_ZN16GraphicsRecorder4DrawEfff+0x214>
 *   @0x185bec cmp r5, r7
 *   @0x185bf0 movlt r6, r5
 *   @0x185bf4 movge r6, r7
 *   @0x185bf8 ldr r1, [r4, #0x10]
 *   @0x185bfc mov r2, #36
 *   @0x185c00 mov r0, #1
 *   @0x185c04 mov r3, r6
 *   @0x185c08 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x185c0c ldr r3, [r4, #0x3c]
 *   @0x185c10 ldr r1, [r4, #0x34]
 *   @0x185c14 add r2, r6, r6, lsl #3
 *   @0x185c18 rsb r3, r5, r3
 *   @0x185c1c rsb r5, r6, r5
 *   @0x185c20 lsl r2, r2, #2
 *   @0x185c24 add r3, r3, r3, lsl #3
 *   @0x185c28 add r1, r1, r3, lsl #2
 *   @0x185c2c bl 0xb65bc <memcpy@plt>
 *   @0x185c30 cmp r5, #0
 *   @0x185c34 bgt 0x185bec <_ZN16GraphicsRecorder4DrawEfff+0x1c8>
 *   @0x185c38 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x185c3c ldr r0, [sp, #0x14]
 *   @0x185c40 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x185c44 add r1, sp, #32
 *   @0x185c48 mov r0, #2
 *   @0x185c4c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x185c50 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x185c54 add sp, sp, #228
 *   @0x185c58 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x185c5c ldr r3, [pc, #0x70c]
 *   @0x185c60 ldr r3, [r5, r3]
 *   @0x185c64 str r3, [sp, #0x8]
 *   @0x185c68 ldr r3, [r3]
 *   @0x185c6c cmp r3, #1
 *   @0x185c70 movne r6, r3
 *   @0x185c74 beq 0x186150 <_ZN16GraphicsRecorder4DrawEfff+0x72c>
 *   @0x185c78 cmp r6, #0
 *   @0x185c7c bne 0x185b54 <_ZN16GraphicsRecorder4DrawEfff+0x130>
 *   @0x185c80 ldr r3, [pc, #0x6ec]
 *   @0x185c84 movw r0, #0x8074
 *   @0x185c88 ldr r7, [r5, r3]
 *   @0x185c8c ldr r3, [r7]
 *   @0x185c90 blx r3
 *   @0x185c94 ldr r3, [r7]
 *   @0x185c98 movw r0, #0x8075
 *   @0x185c9c blx r3
 *   @0x185ca0 ldr r3, [r7]
 *   @0x185ca4 movw r0, #0x8076
 *   @0x185ca8 blx r3
 *   @0x185cac ldr r1, [r4, #0x10]
 *   @0x185cb0 ldr r3, [pc, #0x6c0]
 *   @0x185cb4 cmp r1, #0
 *   @0x185cb8 beq 0x18632c <_ZN16GraphicsRecorder4DrawEfff+0x908>
 *   @0x185cbc ldr r3, [r5, r3]
 *   @0x185cc0 ldr r0, [r3]
 *   @0x185cc4 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x185cc8 ldr r3, [r7]
 *   @0x185ccc movw r0, #0x8078
 *   @0x185cd0 blx r3
 *   @0x185cd4 ldr r3, [pc, #0x6a0]
 *   @0x185cd8 ldr r3, [r5, r3]
 *   @0x185cdc str r3, [sp, #0x1c]
 *   @0x185ce0 ldr r6, [r4, #0x1c]
 *   @0x185ce4 cmp r6, #0
 *   @0x185ce8 ble 0x185df0 <_ZN16GraphicsRecorder4DrawEfff+0x3cc>
 *   @0x185cec ldr r0, [pc, #0x68c]
 *   @0x185cf0 movw lr, #0x5556
 *   @0x185cf4 ldr r12, [pc, #0x688]
 *   @0x185cf8 movt lr, #0x5555
 *   @0x185cfc ldr r1, [pc, #0x684]
 *   @0x185d00 mov r3, r6
 *   @0x185d04 str lr, [sp, #0xc]
 *   @0x185d08 ldr r2, [pc, #0x67c]
 *   @0x185d0c ldr r0, [r5, r0]
 *   @0x185d10 ldr r11, [r5, r12]
 *   @0x185d14 mov r8, r0
 *   @0x185d18 str r0, [sp, #0x8]
 *   @0x185d1c ldr r10, [r5, r1]
 *   @0x185d20 ldr r9, [r5, r2]
 *   @0x185d24 str r5, [sp, #0x18]
 *   @0x185d28 b 0x185d30 <_ZN16GraphicsRecorder4DrawEfff+0x30c>
 *   @0x185d2c ldr r3, [r4, #0x1c]
 *   @0x185d30 ldr r5, [sp, #0xc]
 *   @0x185d34 movw r12, #0xffff
 *   @0x185d38 cmp r12, r6
 *   @0x185d3c movge r12, r6
 *   @0x185d40 rsb r3, r6, r3
 *   @0x185d44 ldr r2, [r4, #0x14]
 *   @0x185d48 mov r0, #3
 *   @0x185d4c smull r5, r7, r5, r12
 *   @0x185d50 add r3, r3, r3, lsl #3
 *   @0x185d54 movw r1, #0x1406
 *   @0x185d58 add r5, r2, r3, lsl #2
 *   @0x185d5c mov r2, #36
 *   @0x185d60 mov r3, r5
 *   @0x185d64 sub r7, r7, r12, asr #31
 *   @0x185d68 ldr r12, [r8]
 *   @0x185d6c blx r12
 *   @0x185d70 add r2, r5, #12
 *   @0x185d74 ldr r3, [r10]
 *   @0x185d78 movw r0, #0x1406
 *   @0x185d7c mov r1, #36
 *   @0x185d80 add r7, r7, r7, lsl #1
 *   @0x185d84 blx r3
 *   @0x185d88 add r3, r5, #24
 *   @0x185d8c ldr r12, [r9]
 *   @0x185d90 mov r0, #4
 *   @0x185d94 movw r1, #0x1401
 *   @0x185d98 mov r2, #36
 *   @0x185d9c blx r12
 *   @0x185da0 ldr r12, [r4, #0x10]
 *   @0x185da4 ldr lr, [pc, #0x5e4]
 *   @0x185da8 add r3, r5, #28
 *   @0x185dac cmp r12, #0
 *   @0x185db0 mov r0, #2
 *   @0x185db4 movw r1, #0x1406
 *   @0x185db8 mov r2, #36
 *   @0x185dbc rsb r6, r7, r6
 *   @0x185dc0 beq 0x185dd4 <_ZN16GraphicsRecorder4DrawEfff+0x3b0>
 *   @0x185dc4 ldr r5, [sp, #0x18]
 *   @0x185dc8 ldr r12, [r5, lr]
 *   @0x185dcc ldr r12, [r12]
 *   @0x185dd0 blx r12
 *   @0x185dd4 mov r2, r7
 *   @0x185dd8 ldr r3, [r11]
 *   @0x185ddc mov r0, #4
 *   @0x185de0 mov r1, #0
 *   @0x185de4 blx r3
 *   @0x185de8 cmp r6, #0
 *   @0x185dec bgt 0x185d2c <_ZN16GraphicsRecorder4DrawEfff+0x308>
 *   @0x185df0 ldr r5, [sp, #0x1c]
 *   @0x185df4 movw r0, #0x8074
 *   @0x185df8 ldr r3, [r5]
 *   @0x185dfc blx r3
 *   @0x185e00 ldr r3, [r5]
 *   @0x185e04 movw r0, #0x8075
 *   @0x185e08 blx r3
 *   @0x185e0c ldr r3, [r5]
 *   @0x185e10 movw r0, #0x8076
 *   @0x185e14 blx r3
 *   @0x185e18 ldr r3, [r5]
 *   @0x185e1c movw r0, #0x8078
 *   @0x185e20 blx r3
 *   @0x185e24 b 0x185b54 <_ZN16GraphicsRecorder4DrawEfff+0x130>
 *   @0x185e28 ldr r3, [pc, #0x544]
 *   @0x185e2c movw r0, #0x8074
 *   @0x185e30 ldr r7, [r5, r3]
 *   @0x185e34 ldr r3, [r7]
 *   @0x185e38 blx r3
 *   @0x185e3c ldr r3, [r7]
 *   @0x185e40 movw r0, #0x8075
 *   @0x185e44 blx r3
 *   @0x185e48 ldr r3, [r7]
 *   @0x185e4c movw r0, #0x8076
 *   @0x185e50 blx r3
 *   @0x185e54 ldr r1, [r4, #0x10]
 *   @0x185e58 ldr r3, [pc, #0x518]
 *   @0x185e5c cmp r1, #0
 *   @0x185e60 beq 0x186300 <_ZN16GraphicsRecorder4DrawEfff+0x8dc>
 *   @0x185e64 ldr r3, [r5, r3]
 *   @0x185e68 ldr r0, [r3]
 *   @0x185e6c bl 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x185e70 ldr r3, [r7]
 *   @0x185e74 movw r0, #0x8078
 *   @0x185e78 blx r3
 *   @0x185e7c ldr r3, [pc, #0x4f8]
 *   @0x185e80 ldr r3, [r5, r3]
 *   @0x185e84 str r3, [sp, #0x1c]
 *   @0x185e88 ldr r7, [r4, #0x18]
 *   @0x185e8c cmp r7, #0
 *   @0x185e90 beq 0x1862c4 <_ZN16GraphicsRecorder4DrawEfff+0x8a0>
 *   @0x185e94 ldr r12, [r7, #0x4]
 *   @0x185e98 cmp r12, #0
 *   @0x185e9c str r12, [sp, #0xc]
 *   @0x185ea0 ble 0x1862c4 <_ZN16GraphicsRecorder4DrawEfff+0x8a0>
 *   @0x185ea4 ldr r1, [pc, #0x4d4]
 *   @0x185ea8 mov r6, #0
 *   @0x185eac ldr r12, [pc, #0x4e0]
 *   @0x185eb0 ldr r0, [pc, #0x4cc]
 *   @0x185eb4 ldr r1, [r5, r1]
 *   @0x185eb8 ldr r2, [pc, #0x4c8]
 *   @0x185ebc ldr r3, [pc, #0x4c8]
 *   @0x185ec0 ldr r8, [r5, r12]
 *   @0x185ec4 ldr r11, [r5, r0]
 *   @0x185ec8 str r1, [sp, #0x8]
 *   @0x185ecc ldr r10, [r5, r2]
 *   @0x185ed0 ldr r9, [r5, r3]
 *   @0x185ed4 str r5, [sp, #0x18]
 *   @0x185ed8 ldr r3, [r7]
 *   @0x185edc movw r0, #0x8892
 *   @0x185ee0 ldr r2, [r8]
 *   @0x185ee4 add r5, r3, r6, lsl #3
 *   @0x185ee8 ldr r1, [r3, r6, lsl #3]
 *   @0x185eec add r6, r6, #1
 *   @0x185ef0 blx r2
 *   @0x185ef4 ldr lr, [sp, #0x8]
 *   @0x185ef8 mov r0, #3
 *   @0x185efc movw r1, #0x1406
 *   @0x185f00 mov r2, #36
 *   @0x185f04 mov r3, #0
 *   @0x185f08 ldr r12, [lr]
 *   @0x185f0c blx r12
 *   @0x185f10 ldr r3, [r10]
 *   @0x185f14 movw r0, #0x1406
 *   @0x185f18 mov r1, #36
 *   @0x185f1c mov r2, #12
 *   @0x185f20 blx r3
 *   @0x185f24 ldr r12, [r9]
 *   @0x185f28 mov r0, #4
 *   @0x185f2c movw r1, #0x1401
 *   @0x185f30 mov r2, #36
 *   @0x185f34 mov r3, #24
 *   @0x185f38 blx r12
 *   @0x185f3c ldr r12, [r4, #0x10]
 *   @0x185f40 ldr lr, [pc, #0x448]
 *   @0x185f44 mov r0, #2
 *   @0x185f48 cmp r12, #0
 *   @0x185f4c movw r1, #0x1406
 *   @0x185f50 mov r2, #36
 *   @0x185f54 mov r3, #28
 *   @0x185f58 beq 0x185f6c <_ZN16GraphicsRecorder4DrawEfff+0x548>
 *   @0x185f5c ldr r12, [sp, #0x18]
 *   @0x185f60 ldr lr, [r12, lr]
 *   @0x185f64 ldr r12, [lr]
 *   @0x185f68 blx r12
 *   @0x185f6c ldr r2, [r5, #0x4]
 *   @0x185f70 mov r0, #4
 *   @0x185f74 ldr r3, [r11]
 *   @0x185f78 mov r1, #0
 *   @0x185f7c blx r3
 *   @0x185f80 ldr r5, [sp, #0xc]
 *   @0x185f84 cmp r6, r5
 *   @0x185f88 bne 0x185ed8 <_ZN16GraphicsRecorder4DrawEfff+0x4b4>
 *   @0x185f8c ldr r5, [sp, #0x1c]
 *   @0x185f90 movw r0, #0x8074
 *   @0x185f94 ldr r3, [r5]
 *   @0x185f98 blx r3
 *   @0x185f9c ldr r3, [r5]
 *   @0x185fa0 movw r0, #0x8075
 *   @0x185fa4 blx r3
 *   @0x185fa8 ldr r3, [r5]
 *   @0x185fac movw r0, #0x8076
 *   @0x185fb0 blx r3
 *   @0x185fb4 ldr r3, [r5]
 *   @0x185fb8 movw r0, #0x8078
 *   @0x185fbc blx r3
 *   @0x185fc0 ldr r3, [r8]
 *   @0x185fc4 movw r0, #0x8892
 *   @0x185fc8 mov r1, #0
 *   @0x185fcc blx r3
 *   @0x185fd0 b 0x185b54 <_ZN16GraphicsRecorder4DrawEfff+0x130>
 *   @0x185fd4 mov r0, #36
 *   @0x185fd8 bl 0x18426c <_Z16StartShaderBlocki>
 *   @0x185fdc ldr r3, [pc, #0x394]
 *   @0x185fe0 ldr r1, [r4, #0x10]
 *   @0x185fe4 ldr r3, [r5, r3]
 *   @0x185fe8 mov r7, r0
 *   @0x185fec ldr r0, [r3]
 *   @0x185ff0 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x185ff4 ldr r9, [r4, #0x18]
 *   @0x185ff8 cmp r9, #0
 *   @0x185ffc beq 0x186358 <_ZN16GraphicsRecorder4DrawEfff+0x934>
 *   @0x186000 ldr r12, [r9, #0x4]
 *   @0x186004 cmp r12, #0
 *   @0x186008 str r12, [sp, #0xc]
 *   @0x18600c ble 0x186358 <_ZN16GraphicsRecorder4DrawEfff+0x934>
 *   @0x186010 ldr r2, [pc, #0x37c]
 *   @0x186014 mov r6, #0
 *   @0x186018 ldr r3, [pc, #0x364]
 *   @0x18601c mov r10, #36
 *   @0x186020 ldr r8, [r5, r2]
 *   @0x186024 ldr r11, [r5, r3]
 *   @0x186028 str r4, [sp, #0x1c]
 *   @0x18602c ldr r3, [r9]
 *   @0x186030 movw r0, #0x8892
 *   @0x186034 ldr r2, [r8]
 *   @0x186038 add r4, r3, r6, lsl #3
 *   @0x18603c ldr r1, [r3, r6, lsl #3]
 *   @0x186040 add r6, r6, #1
 *   @0x186044 blx r2
 *   @0x186048 ldr r0, [r7, #0x1c]
 *   @0x18604c ldr r12, [pc, #0x344]
 *   @0x186050 mov r1, #3
 *   @0x186054 cmn r0, #1
 *   @0x186058 movw r2, #0x1406
 *   @0x18605c mov r3, #0
 *   @0x186060 beq 0x186078 <_ZN16GraphicsRecorder4DrawEfff+0x654>
 *   @0x186064 ldr r12, [r5, r12]
 *   @0x186068 str r10, [sp]
 *   @0x18606c str r3, [sp, #0x4]
 *   @0x186070 ldr r12, [r12]
 *   @0x186074 blx r12
 *   @0x186078 ldr r0, [r7, #0x20]
 *   @0x18607c mov r1, #3
 *   @0x186080 ldr r12, [pc, #0x310]
 *   @0x186084 movw r2, #0x1406
 *   @0x186088 cmn r0, #1
 *   @0x18608c mov r3, #0
 *   @0x186090 beq 0x1860ac <_ZN16GraphicsRecorder4DrawEfff+0x688>
 *   @0x186094 ldr r12, [r5, r12]
 *   @0x186098 mov lr, #12
 *   @0x18609c str r10, [sp]
 *   @0x1860a0 str lr, [sp, #0x4]
 *   @0x1860a4 ldr r12, [r12]
 *   @0x1860a8 blx r12
 *   @0x1860ac ldr r0, [r7, #0x28]
 *   @0x1860b0 mov r1, #4
 *   @0x1860b4 ldr lr, [pc, #0x2dc]
 *   @0x1860b8 movw r2, #0x1401
 *   @0x1860bc cmn r0, #1
 *   @0x1860c0 mov r3, #1
 *   @0x1860c4 mov r12, #24
 *   @0x1860c8 beq 0x1860dc <_ZN16GraphicsRecorder4DrawEfff+0x6b8>
 *   @0x1860cc ldr lr, [r5, lr]
 *   @0x1860d0 stm sp, {r10, r12}
 *   @0x1860d4 ldr r12, [lr]
 *   @0x1860d8 blx r12
 *   @0x1860dc ldr r0, [r7, #0x24]
 *   @0x1860e0 mov r12, #28
 *   @0x1860e4 ldr lr, [pc, #0x2ac]
 *   @0x1860e8 mov r1, #2
 *   @0x1860ec cmn r0, #1
 *   @0x1860f0 movw r2, #0x1406
 *   @0x1860f4 mov r3, #0
 *   @0x1860f8 beq 0x18610c <_ZN16GraphicsRecorder4DrawEfff+0x6e8>
 *   @0x1860fc ldr lr, [r5, lr]
 *   @0x186100 stm sp, {r10, r12}
 *   @0x186104 ldr r12, [lr]
 *   @0x186108 blx r12
 *   @0x18610c ldr r2, [r4, #0x4]
 *   @0x186110 mov r0, #4
 *   @0x186114 ldr r3, [r11]
 *   @0x186118 mov r1, #0
 *   @0x18611c blx r3
 *   @0x186120 ldr r12, [sp, #0xc]
 *   @0x186124 cmp r6, r12
 *   @0x186128 bne 0x18602c <_ZN16GraphicsRecorder4DrawEfff+0x608>
 *   @0x18612c ldr r4, [sp, #0x1c]
 *   @0x186130 bl 0x1847f8 <_Z14EndShaderBlockv>
 *   @0x186134 ldr r3, [r8]
 *   @0x186138 movw r0, #0x8892
 *   @0x18613c mov r1, #0
 *   @0x186140 blx r3
 *   @0x186144 ldr r12, [sp, #0x8]
 *   @0x186148 ldr r6, [r12]
 *   @0x18614c b 0x185b4c <_ZN16GraphicsRecorder4DrawEfff+0x128>
 *   @0x186150 mov r0, #36
 *   @0x186154 bl 0x18426c <_Z16StartShaderBlocki>
 *   @0x186158 subs r8, r0, #0
 *   @0x18615c beq 0x185c3c <_ZN16GraphicsRecorder4DrawEfff+0x218>
 *   @0x186160 ldr r3, [pc, #0x210]
 *   @0x186164 ldr r1, [r4, #0x10]
 *   @0x186168 ldr r3, [r5, r3]
 *   @0x18616c ldr r0, [r3]
 *   @0x186170 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x186174 ldr r6, [r4, #0x1c]
 *   @0x186178 cmp r6, #0
 *   @0x18617c ble 0x1862b4 <_ZN16GraphicsRecorder4DrawEfff+0x890>
 *   @0x186180 ldr r3, [pc, #0x1fc]
 *   @0x186184 movw r12, #0x5556
 *   @0x186188 mov r7, r6
 *   @0x18618c movt r12, #0x5555
 *   @0x186190 mov r10, #36
 *   @0x186194 str r12, [sp, #0xc]
 *   @0x186198 ldr r11, [r5, r3]
 *   @0x18619c b 0x1861a4 <_ZN16GraphicsRecorder4DrawEfff+0x780>
 *   @0x1861a0 ldr r7, [r4, #0x1c]
 *   @0x1861a4 ldr r0, [sp, #0xc]
 *   @0x1861a8 movw r12, #0xffff
 *   @0x1861ac cmp r12, r6
 *   @0x1861b0 movge r12, r6
 *   @0x1861b4 rsb r7, r6, r7
 *   @0x1861b8 ldr lr, [pc, #0x1d8]
 *   @0x1861bc mov r3, #0
 *   @0x1861c0 smull r0, r9, r0, r12
 *   @0x1861c4 add r7, r7, r7, lsl #3
 *   @0x1861c8 ldr r0, [r4, #0x14]
 *   @0x1861cc mov r1, #3
 *   @0x1861d0 movw r2, #0x1406
 *   @0x1861d4 add r7, r0, r7, lsl #2
 *   @0x1861d8 ldr r0, [r8, #0x1c]
 *   @0x1861dc sub r9, r9, r12, asr #31
 *   @0x1861e0 cmn r0, #1
 *   @0x1861e4 add r9, r9, r9, lsl #1
 *   @0x1861e8 beq 0x186200 <_ZN16GraphicsRecorder4DrawEfff+0x7dc>
 *   @0x1861ec ldr r12, [r5, lr]
 *   @0x1861f0 str r10, [sp]
 *   @0x1861f4 str r7, [sp, #0x4]
 *   @0x1861f8 ldr r12, [r12]
 *   @0x1861fc blx r12
 *   @0x186200 ldr r0, [r8, #0x20]
 *   @0x186204 mov r3, #0
 *   @0x186208 ldr lr, [pc, #0x188]
 *   @0x18620c mov r1, #3
 *   @0x186210 cmn r0, #1
 *   @0x186214 movw r2, #0x1406
 *   @0x186218 add r12, r7, #12
 *   @0x18621c rsb r6, r9, r6
 *   @0x186220 beq 0x186234 <_ZN16GraphicsRecorder4DrawEfff+0x810>
 *   @0x186224 ldr lr, [r5, lr]
 *   @0x186228 stm sp, {r10, r12}
 *   @0x18622c ldr r12, [lr]
 *   @0x186230 blx r12
 *   @0x186234 ldr r0, [r8, #0x28]
 *   @0x186238 mov r3, #1
 *   @0x18623c ldr lr, [pc, #0x154]
 *   @0x186240 add r12, r7, #24
 *   @0x186244 cmn r0, #1
 *   @0x186248 mov r1, #4
 *   @0x18624c movw r2, #0x1401
 *   @0x186250 beq 0x186264 <_ZN16GraphicsRecorder4DrawEfff+0x840>
 *   @0x186254 ldr lr, [r5, lr]
 *   @0x186258 stm sp, {r10, r12}
 *   @0x18625c ldr r12, [lr]
 *   @0x186260 blx r12
 *   @0x186264 ldr r0, [r8, #0x24]
 *   @0x186268 add r7, r7, #28
 *   @0x18626c ldr r12, [pc, #0x124]
 *   @0x186270 mov r3, #0
 *   @0x186274 cmn r0, #1
 *   @0x186278 mov r1, #2
 *   @0x18627c movw r2, #0x1406
 *   @0x186280 beq 0x186298 <_ZN16GraphicsRecorder4DrawEfff+0x874>
 *   @0x186284 ldr r12, [r5, r12]
 *   @0x186288 str r10, [sp]
 *   @0x18628c str r7, [sp, #0x4]
 *   @0x186290 ldr r12, [r12]
 *   @0x186294 blx r12
 *   @0x186298 ldr r3, [r11]
 *   @0x18629c mov r0, #4
 *   @0x1862a0 mov r2, r9
 *   @0x1862a4 mov r1, #0
 *   @0x1862a8 blx r3
 *   @0x1862ac cmp r6, #0
 *   @0x1862b0 bgt 0x1861a0 <_ZN16GraphicsRecorder4DrawEfff+0x77c>
 *   @0x1862b4 bl 0x1847f8 <_Z14EndShaderBlockv>
 *   @0x1862b8 ldr r12, [sp, #0x8]
 *   @0x1862bc ldr r6, [r12]
 *   @0x1862c0 b 0x185c78 <_ZN16GraphicsRecorder4DrawEfff+0x254>
 *   @0x1862c4 ldr r3, [pc, #0xc8]
 *   @0x1862c8 ldr r8, [r5, r3]
 *   @0x1862cc b 0x185f8c <_ZN16GraphicsRecorder4DrawEfff+0x568>
 *   @0x1862d0 ldr r1, [r4, #0x14]
 *   @0x1862d4 mvn r3, #0
 *   @0x1862d8 add r2, r4, #32
 *   @0x1862dc str r3, [sp]
 *   @0x1862e0 mov r0, r4
 *   @0x1862e4 add r3, r4, #28
 *   @0x1862e8 bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i>
 *   @0x1862ec ldr r1, [r4, #0x1c]
 *   @0x1862f0 str r0, [r4, #0x14]
 *   @0x1862f4 bl 0x18585c <_Z18CreateVertexBufferPvi>
 *   @0x1862f8 str r0, [r4, #0x18]
 *   @0x1862fc b 0x185b30 <_ZN16GraphicsRecorder4DrawEfff+0x10c>
 *   @0x186300 ldr r3, [r5, r3]
 *   @0x186304 mov r1, r6
 *   @0x186308 ldr r0, [r3]
 *   @0x18630c bl 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x186310 ldr r3, [pc, #0x64]
 *   @0x186314 movw r0, #0x8078
 *   @0x186318 ldr r3, [r5, r3]
 *   @0x18631c str r3, [sp, #0x1c]
 *   @0x186320 ldr r3, [r3]
 *   @0x186324 blx r3
 *   @0x186328 b 0x185e88 <_ZN16GraphicsRecorder4DrawEfff+0x464>
 *   @0x18632c ldr r3, [r5, r3]
 *   @0x186330 mov r1, r6
 *   @0x186334 ldr r0, [r3]
 *   @0x186338 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x18633c ldr r3, [pc, #0x38]
 *   @0x186340 movw r0, #0x8078
 *   @0x186344 ldr r3, [r5, r3]
 *   @0x186348 str r3, [sp, #0x1c]
 *   @0x18634c ldr r3, [r3]
 *   @0x186350 blx r3
 *   @0x186354 b 0x185ce0 <_ZN16GraphicsRecorder4DrawEfff+0x2bc>
 *   @0x186358 ldr r3, [pc, #0x34]
 *   @0x18635c ldr r8, [r5, r3]
 *   @0x186360 b 0x186130 <_ZN16GraphicsRecorder4DrawEfff+0x70c>
 *   @0x186364 eoreq r12, r6, r12, lsl #3
 *   @0x186368 .word 0xffffe7e0
 *   @0x18636c .word 0xffffe90c
 *   @0x186370 .word 0xffffe7b8
 *   @0x186374 .word 0xffffbc30
 *   @0x186378 .word 0xffffe4d4
 *   @0x18637c .word 0xffffbc2c
 *   @0x186380 .word 0xffffbc6c
 *   @0x186384 .word 0xffffbad4
 *   @0x186388 .word 0xffffbc50
 *   @0x18638c .word 0xffffbc28
 *   @0x186390 .word 0xffffbca8
 *   @0x186394 .word 0xffffbb3c
 *   @0x186398 .word 0xffffbb90
 *
 * ══ §2/16 anon_22b618  0x22b618  size 2400  600 条（0x22b618..0x22bf78）
 * @func 0x22b618 0x22bf78  size 2400  600 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_read×11 / 0xb6c34×6 / anon_22b618+0x89c×6 / 0xb65b0×4 / 0xb655c×4 / anon_22b618+0x45c×3 / anon_22b618+0x8ac×2 / anon_22b618+0x95c×2
 * 字段偏移 top8: 0x4×38 / 0x2×26 / 0x-30×17 / 0x10×10 / 0xc×9 / 0x-34×8 / 0x8×8 / 0x14×8
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22b618 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22b61c add r11, sp, #32
 *   @0x22b620 sub sp, sp, #68
 *   @0x22b624 mov r5, r0
 *   @0x22b628 ldr r0, [pc, #0x4b4]
 *   @0x22b62c mov r8, r1
 *   @0x22b630 ldr r3, [r5, #0x40]
 *   @0x22b634 ldr r0, [pc, r0]
 *   @0x22b638 str r0, [r11, #-0x40]
 *   @0x22b63c ldr r0, [r0]
 *   @0x22b640 ldr r10, [r3, #0x4]
 *   @0x22b644 ldr r3, [r3, #0x48]
 *   @0x22b648 ldr r1, [r5, #0x1c]
 *   @0x22b64c ldr r2, [r10, #0x4]
 *   @0x22b650 str r3, [r11, #-0x48]
 *   @0x22b654 ldr r3, [r10, #0x1c]
 *   @0x22b658 cmp r2, #0
 *   @0x22b65c str r0, [r11, #-0x28]
 *   @0x22b660 ldr r4, [r8, #0x4]
 *   @0x22b664 str r3, [r11, #-0x44]
 *   @0x22b668 lsl r3, r2, #2
 *   @0x22b66c ldr r0, [r11, #-0x44]
 *   @0x22b670 add r3, r3, #14
 *   @0x22b674 bic r3, r3, #7
 *   @0x22b678 sub sp, sp, r3
 *   @0x22b67c ldr r1, [r0, r1, lsl #2]
 *   @0x22b680 str r1, [r11, #-0x3c]
 *   @0x22b684 add r1, sp, #8
 *   @0x22b688 sub sp, sp, r3
 *   @0x22b68c str r1, [r11, #-0x38]
 *   @0x22b690 add r0, sp, #8
 *   @0x22b694 sub sp, sp, r3
 *   @0x22b698 add r6, sp, #8
 *   @0x22b69c sub sp, sp, r3
 *   @0x22b6a0 ldr r3, [r11, #-0x3c]
 *   @0x22b6a4 add r1, sp, #8
 *   @0x22b6a8 str r0, [r11, #-0x50]
 *   @0x22b6ac str r1, [r11, #-0x4c]
 *   @0x22b6b0 str r3, [r5, #0x24]
 *   @0x22b6b4 ble 0x22b740 <vorbis_synthesis_headerin+0x7dc>
 *   @0x22b6b8 ldr r1, [r11, #-0x3c]
 *   @0x22b6bc mov r7, #0
 *   @0x22b6c0 ldr r3, [r11, #-0x4c]
 *   @0x22b6c4 str r4, [r11, #-0x54]
 *   @0x22b6c8 lsl r2, r1, #2
 *   @0x22b6cc sub r9, r3, #4
 *   @0x22b6d0 str r6, [r11, #-0x30]
 *   @0x22b6d4 lsr r2, r2, #1
 *   @0x22b6d8 str r2, [r11, #-0x34]
 *   @0x22b6dc ldr r1, [r4, #0x4]!
 *   @0x22b6e0 mov r0, r5
 *   @0x22b6e4 ldr r12, [r8, #0x10]
 *   @0x22b6e8 lsl r6, r7, #2
 *   @0x22b6ec ldr lr, [r8, #0x8]
 *   @0x22b6f0 ldr r12, [r12, r1, lsl #2]
 *   @0x22b6f4 ldr r1, [lr, r1, lsl #2]
 *   @0x22b6f8 ldr r12, [r12, #0x10]
 *   @0x22b6fc blx r12
 *   @0x22b700 ldr r12, [r5]
 *   @0x22b704 ldr r3, [r11, #-0x30]
 *   @0x22b708 mov r1, #0
 *   @0x22b70c ldr r2, [r11, #-0x34]
 *   @0x22b710 cmp r0, #0
 *   @0x22b714 str r0, [r9, #0x4]!
 *   @0x22b718 movne r0, #1
 *   @0x22b71c str r0, [r3, r7, lsl #2]
 *   @0x22b720 ldr r0, [r12, r6]
 *   @0x22b724 add r7, r7, #1
 *   @0x22b728 bl 0xb65b0 <memset@plt>
 *   @0x22b72c ldr r2, [r10, #0x4]
 *   @0x22b730 cmp r2, r7
 *   @0x22b734 bgt 0x22b6dc <vorbis_synthesis_headerin+0x778>
 *   @0x22b738 ldr r4, [r11, #-0x54]
 *   @0x22b73c ldr r6, [r11, #-0x30]
 *   @0x22b740 ldr r0, [r4, #0x48c]
 *   @0x22b744 cmp r0, #0
 *   @0x22b748 str r0, [r11, #-0x30]
 *   @0x22b74c ble 0x22b79c <vorbis_synthesis_headerin+0x838>
 *   @0x22b750 ldr r0, [r11, #-0x30]
 *   @0x22b754 add r3, r4, #1152
 *   @0x22b758 add r3, r3, #12
 *   @0x22b75c mov r12, #1
 *   @0x22b760 add r7, r3, r0, lsl #2
 *   @0x22b764 ldr r1, [r3, #0x4]!
 *   @0x22b768 ldr r0, [r6, r1, lsl #2]
 *   @0x22b76c cmp r0, #0
 *   @0x22b770 ldr r0, [r3, #0x400]
 *   @0x22b774 addne r0, r6, r0, lsl #2
 *   @0x22b778 bne 0x22b78c <vorbis_synthesis_headerin+0x828>
 *   @0x22b77c ldr r9, [r6, r0, lsl #2]
 *   @0x22b780 add r0, r6, r0, lsl #2
 *   @0x22b784 cmp r9, #0
 *   @0x22b788 beq 0x22b794 <vorbis_synthesis_headerin+0x830>
 *   @0x22b78c str r12, [r6, r1, lsl #2]
 *   @0x22b790 str r12, [r0]
 *   @0x22b794 cmp r3, r7
 *   @0x22b798 bne 0x22b764 <vorbis_synthesis_headerin+0x800>
 *   @0x22b79c ldr r3, [r4]
 *   @0x22b7a0 cmp r3, #0
 *   @0x22b7a4 ble 0x22b8a4 <vorbis_synthesis_headerin+0x940>
 *   @0x22b7a8 cmp r2, #0
 *   @0x22b7ac str r6, [r11, #-0x30]
 *   @0x22b7b0 str r8, [r11, #-0x34]
 *   @0x22b7b4 mov r7, #0
 *   @0x22b7b8 mov r9, #1
 *   @0x22b7bc ldr r6, [r11, #-0x38]
 *   @0x22b7c0 ldr r8, [r11, #-0x50]
 *   @0x22b7c4 ble 0x22b88c <vorbis_synthesis_headerin+0x928>
 *   @0x22b7c8 mov r1, #0
 *   @0x22b7cc mov r12, r1
 *   @0x22b7d0 mov r3, r1
 *   @0x22b7d4 b 0x22b7e8 <vorbis_synthesis_headerin+0x884>
 *   @0x22b7d8 add r3, r3, #1
 *   @0x22b7dc add r1, r1, #4
 *   @0x22b7e0 cmp r2, r3
 *   @0x22b7e4 ble 0x22b838 <vorbis_synthesis_headerin+0x8d4>
 *   @0x22b7e8 add r0, r4, r1
 *   @0x22b7ec ldr r0, [r0, #0x4]
 *   @0x22b7f0 cmp r0, r7
 *   @0x22b7f4 bne 0x22b7d8 <vorbis_synthesis_headerin+0x874>
 *   @0x22b7f8 ldr lr, [r11, #-0x30]
 *   @0x22b7fc add r3, r3, #1
 *   @0x22b800 ldr r2, [lr, r1]
 *   @0x22b804 ldr lr, [r5]
 *   @0x22b808 cmp r2, #0
 *   @0x22b80c strne r9, [r8, r12, lsl #2]
 *   @0x22b810 streq r2, [r8, r12, lsl #2]
 *   @0x22b814 lslne r0, r12, #2
 *   @0x22b818 ldr r2, [r10, #0x4]
 *   @0x22b81c lsleq r0, r12, #2
 *   @0x22b820 ldr lr, [lr, r1]
 *   @0x22b824 add r12, r12, #1
 *   @0x22b828 cmp r2, r3
 *   @0x22b82c add r1, r1, #4
 *   @0x22b830 str lr, [r6, r0]
 *   @0x22b834 bgt 0x22b7e8 <vorbis_synthesis_headerin+0x884>
 *   @0x22b838 ldr r0, [r11, #-0x34]
 *   @0x22b83c mov r3, r8
 *   @0x22b840 ldr lr, [r11, #-0x34]
 *   @0x22b844 mov r2, r6
 *   @0x22b848 ldr r1, [r0, #0x14]
 *   @0x22b84c mov r0, r5
 *   @0x22b850 ldr lr, [lr, #0xc]
 *   @0x22b854 ldr r1, [r1, r7, lsl #2]
 *   @0x22b858 str r1, [r11, #-0x38]
 *   @0x22b85c ldr r1, [lr, r7, lsl #2]
 *   @0x22b860 add r7, r7, #1
 *   @0x22b864 ldr lr, [r11, #-0x38]
 *   @0x22b868 str r12, [sp]
 *   @0x22b86c ldr r12, [lr, #0x10]
 *   @0x22b870 blx r12
 *   @0x22b874 ldr r3, [r4]
 *   @0x22b878 cmp r3, r7
 *   @0x22b87c ble 0x22b894 <vorbis_synthesis_headerin+0x930>
 *   @0x22b880 ldr r2, [r10, #0x4]
 *   @0x22b884 cmp r2, #0
 *   @0x22b888 bgt 0x22b7c8 <vorbis_synthesis_headerin+0x864>
 *   @0x22b88c mov r12, #0
 *   @0x22b890 b 0x22b838 <vorbis_synthesis_headerin+0x8d4>
 *   @0x22b894 ldr r0, [r4, #0x48c]
 *   @0x22b898 ldr r8, [r11, #-0x34]
 *   @0x22b89c ldr r6, [r11, #-0x30]
 *   @0x22b8a0 str r0, [r11, #-0x30]
 *   @0x22b8a4 ldr r1, [r11, #-0x30]
 *   @0x22b8a8 subs r9, r1, #1
 *   @0x22b8ac bmi 0x22b96c <vorbis_synthesis_headerin+0xa08>
 *   @0x22b8b0 ldr r2, [r11, #-0x3c]
 *   @0x22b8b4 ldr r0, [r11, #-0x30]
 *   @0x22b8b8 ldr r1, [r5]
 *   @0x22b8bc add r3, r2, r2, lsr #31
 *   @0x22b8c0 add r7, r0, #292
 *   @0x22b8c4 str r10, [r11, #-0x30]
 *   @0x22b8c8 asr r2, r3, #1
 *   @0x22b8cc add r7, r4, r7, lsl #2
 *   @0x22b8d0 str r4, [r11, #-0x34]
 *   @0x22b8d4 mov r4, r1
 *   @0x22b8d8 lsl r3, r2, #2
 *   @0x22b8dc str r6, [r11, #-0x38]
 *   @0x22b8e0 mov r6, r2
 *   @0x22b8e4 mov r10, r3
 *   @0x22b8e8 ldr r3, [r7, #-0x4]!
 *   @0x22b8ec cmp r6, #0
 *   @0x22b8f0 ldr r2, [r7, #0x400]
 *   @0x22b8f4 ldr r3, [r4, r3, lsl #2]
 *   @0x22b8f8 ldr r1, [r4, r2, lsl #2]
 *   @0x22b8fc addgt r12, r3, r10
 *   @0x22b900 bgt 0x22b928 <vorbis_synthesis_headerin+0x9c4>
 *   @0x22b904 b 0x22b958 <vorbis_synthesis_headerin+0x9f4>
 *   @0x22b908 cmp r0, #0
 *   @0x22b90c strle r2, [r1, #-0x4]
 *   @0x22b910 rsbgt r2, r0, r2
 *   @0x22b914 addle r2, r2, r0
 *   @0x22b918 strgt r2, [r1, #-0x4]
 *   @0x22b91c strle r2, [r3, #-0x4]
 *   @0x22b920 cmp r3, r12
 *   @0x22b924 beq 0x22b958 <vorbis_synthesis_headerin+0x9f4>
 *   @0x22b928 ldr r2, [r3], #4
 *   @0x22b92c ldr r0, [r1], #4
 *   @0x22b930 cmp r2, #0
 *   @0x22b934 bgt 0x22b908 <vorbis_synthesis_headerin+0x9a4>
 *   @0x22b938 cmp r0, #0
 *   @0x22b93c strle r2, [r1, #-0x4]
 *   @0x22b940 addgt r2, r2, r0
 *   @0x22b944 rsble r2, r0, r2
 *   @0x22b948 strgt r2, [r1, #-0x4]
 *   @0x22b94c strle r2, [r3, #-0x4]
 *   @0x22b950 cmp r3, r12
 *   @0x22b954 bne 0x22b928 <vorbis_synthesis_headerin+0x9c4>
 *   @0x22b958 subs r9, r9, #1
 *   @0x22b95c bhs 0x22b8e8 <vorbis_synthesis_headerin+0x984>
 *   @0x22b960 ldr r10, [r11, #-0x30]
 *   @0x22b964 ldr r4, [r11, #-0x34]
 *   @0x22b968 ldr r6, [r11, #-0x38]
 *   @0x22b96c ldr r3, [r10, #0x4]
 *   @0x22b970 cmp r3, #0
 *   @0x22b974 ble 0x22ba74 <vorbis_synthesis_headerin+0xb10>
 *   @0x22b978 str r6, [r11, #-0x30]
 *   @0x22b97c mov r7, #0
 *   @0x22b980 ldr r6, [r11, #-0x4c]
 *   @0x22b984 mov r9, r7
 *   @0x22b988 add r3, r4, r7
 *   @0x22b98c ldr r12, [r8, #0x10]
 *   @0x22b990 ldr r1, [r8, #0x8]
 *   @0x22b994 mov r0, r5
 *   @0x22b998 ldr r3, [r3, #0x4]
 *   @0x22b99c add r9, r9, #1
 *   @0x22b9a0 ldr lr, [r5]
 *   @0x22b9a4 ldr r2, [r6, r7]
 *   @0x22b9a8 ldr r12, [r12, r3, lsl #2]
 *   @0x22b9ac ldr r1, [r1, r3, lsl #2]
 *   @0x22b9b0 ldr r3, [lr, r7]
 *   @0x22b9b4 add r7, r7, #4
 *   @0x22b9b8 ldr r12, [r12, #0x14]
 *   @0x22b9bc blx r12
 *   @0x22b9c0 ldr r3, [r10, #0x4]
 *   @0x22b9c4 cmp r3, r9
 *   @0x22b9c8 bgt 0x22b988 <vorbis_synthesis_headerin+0xa24>
 *   @0x22b9cc cmp r3, #0
 *   @0x22b9d0 ldr r6, [r11, #-0x30]
 *   @0x22b9d4 ble 0x22ba74 <vorbis_synthesis_headerin+0xb10>
 *   @0x22b9d8 ldr r7, [r11, #-0x3c]
 *   @0x22b9dc mov r4, #0
 *   @0x22b9e0 ldr r3, [r5]
 *   @0x22b9e4 mov r0, r7
 *   @0x22b9e8 ldr r1, [r3, r4, lsl #2]
 *   @0x22b9ec add r4, r4, #1
 *   @0x22b9f0 mov r2, r1
 *   @0x22b9f4 bl 0x22bf7c <mdct_backward>
 *   @0x22b9f8 ldr r2, [r10, #0x4]
 *   @0x22b9fc cmp r2, r4
 *   @0x22ba00 mov r3, r2
 *   @0x22ba04 bgt 0x22b9e0 <vorbis_synthesis_headerin+0xa7c>
 *   @0x22ba08 cmp r2, #0
 *   @0x22ba0c ble 0x22ba74 <vorbis_synthesis_headerin+0xb10>
 *   @0x22ba10 ldr r1, [r11, #-0x3c]
 *   @0x22ba14 mov r7, #0
 *   @0x22ba18 mov r8, r7
 *   @0x22ba1c mov r4, r7
 *   @0x22ba20 lsl r9, r1, #2
 *   @0x22ba24 mov r12, r9
 *   @0x22ba28 mov r9, r1
 *   @0x22ba2c ldr r1, [r6, r7]
 *   @0x22ba30 ldr r3, [r5]
 *   @0x22ba34 cmp r1, #0
 *   @0x22ba38 ldr r0, [r3, r7]
 *   @0x22ba3c bne 0x22baa8 <vorbis_synthesis_headerin+0xb44>
 *   @0x22ba40 cmp r9, #0
 *   @0x22ba44 movgt r3, r0
 *   @0x22ba48 addgt r2, r3, r12
 *   @0x22ba4c ble 0x22ba60 <vorbis_synthesis_headerin+0xafc>
 *   @0x22ba50 str r4, [r3], #4
 *   @0x22ba54 cmp r3, r2
 *   @0x22ba58 bne 0x22ba50 <vorbis_synthesis_headerin+0xaec>
 *   @0x22ba5c ldr r2, [r10, #0x4]
 *   @0x22ba60 add r8, r8, #1
 *   @0x22ba64 add r7, r7, #4
 *   @0x22ba68 cmp r2, r8
 *   @0x22ba6c mov r3, r2
 *   @0x22ba70 bgt 0x22ba2c <vorbis_synthesis_headerin+0xac8>
 *   @0x22ba74 ldr r1, [r11, #-0x40]
 *   @0x22ba78 mov r0, #0
 *   @0x22ba7c ldr r2, [pc, #0x64]
 *   @0x22ba80 ldr r4, [r11, #-0x28]
 *   @0x22ba84 add r2, pc, r2
 *   @0x22ba88 ldr r12, [r1]
 *   @0x22ba8c ldr r1, [r2]
 *   @0x22ba90 cmp r4, r12
 *   @0x22ba94 add r3, r3, r1
 *   @0x22ba98 str r3, [r2]
 *   @0x22ba9c bne 0x22bae0 <vorbis_synthesis_headerin+0xb7c>
 *   @0x22baa0 sub sp, r11, #32
 *   @0x22baa4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22baa8 ldr lr, [r5, #0x20]
 *   @0x22baac ldr r3, [r5, #0x18]
 *   @0x22bab0 ldr r2, [r11, #-0x44]
 *   @0x22bab4 str lr, [r11, #-0x30]
 *   @0x22bab8 ldr lr, [r5, #0x1c]
 *   @0x22babc ldr r1, [r11, #-0x48]
 *   @0x22bac0 str r12, [r11, #-0x5c]
 *   @0x22bac4 str lr, [sp]
 *   @0x22bac8 ldr lr, [r11, #-0x30]
 *   @0x22bacc str lr, [sp, #0x4]
 *   @0x22bad0 bl 0x23311c <_vorbis_apply_window>
 *   @0x22bad4 ldr r2, [r10, #0x4]
 *   @0x22bad8 ldr r12, [r11, #-0x5c]
 *   @0x22badc b 0x22ba60 <vorbis_synthesis_headerin+0xafc>
 *   @0x22bae0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x22bae4 andseq r2, r12, r12, lsl r3
 *   @0x22bae8 ldrsheq r9, [r2], #-212
 *   @0x22baec push {r3, r4, r5, lr}
 *   @0x22baf0 subs r5, r0, #0
 *   @0x22baf4 popeq {r3, r4, r5, pc}
 *   @0x22baf8 ldr r3, [r5, #0x4]
 *   @0x22bafc ldr r3, [r3]
 *   @0x22bb00 cmp r3, #0
 *   @0x22bb04 movgt r4, #0
 *   @0x22bb08 ble 0x22bb50 <vorbis_synthesis_headerin+0xbec>
 *   @0x22bb0c ldr r3, [r5, #0x10]
 *   @0x22bb10 ldr r2, [r5, #0x8]
 *   @0x22bb14 ldr r3, [r3, r4, lsl #2]
 *   @0x22bb18 ldr r0, [r2, r4, lsl #2]
 *   @0x22bb1c ldr r3, [r3, #0xc]
 *   @0x22bb20 blx r3
 *   @0x22bb24 ldr r3, [r5, #0x14]
 *   @0x22bb28 ldr r2, [r5, #0xc]
 *   @0x22bb2c ldr r3, [r3, r4, lsl #2]
 *   @0x22bb30 ldr r0, [r2, r4, lsl #2]
 *   @0x22bb34 add r4, r4, #1
 *   @0x22bb38 ldr r3, [r3, #0xc]
 *   @0x22bb3c blx r3
 *   @0x22bb40 ldr r3, [r5, #0x4]
 *   @0x22bb44 ldr r3, [r3]
 *   @0x22bb48 cmp r3, r4
 *   @0x22bb4c bgt 0x22bb0c <vorbis_synthesis_headerin+0xba8>
 *   @0x22bb50 ldr r0, [r5, #0x10]
 *   @0x22bb54 bl 0xb655c <free@plt>
 *   @0x22bb58 ldr r0, [r5, #0x14]
 *   @0x22bb5c bl 0xb655c <free@plt>
 *   @0x22bb60 ldr r0, [r5, #0x8]
 *   @0x22bb64 bl 0xb655c <free@plt>
 *   @0x22bb68 ldr r0, [r5, #0xc]
 *   @0x22bb6c bl 0xb655c <free@plt>
 *   @0x22bb70 mov r0, r5
 *   @0x22bb74 mov r1, #0
 *   @0x22bb78 mov r2, #32
 *   @0x22bb7c bl 0xb65b0 <memset@plt>
 *   @0x22bb80 mov r0, r5
 *   @0x22bb84 pop {r3, r4, r5, lr}
 *   @0x22bb88 b 0xb655c <free@plt>
 *   @0x22bb8c push {r4, lr}
 *   @0x22bb90 subs r4, r0, #0
 *   @0x22bb94 popeq {r4, pc}
 *   @0x22bb98 mov r1, #0
 *   @0x22bb9c mov r2, #3216
 *   @0x22bba0 bl 0xb65b0 <memset@plt>
 *   @0x22bba4 mov r0, r4
 *   @0x22bba8 pop {r4, lr}
 *   @0x22bbac b 0xb655c <free@plt>
 *   @0x22bbb0 ldr r3, [r0, #0x4]
 *   @0x22bbb4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22bbb8 sub sp, sp, #20
 *   @0x22bbbc mov r8, r1
 *   @0x22bbc0 mov r7, r0
 *   @0x22bbc4 mov r1, #32
 *   @0x22bbc8 mov r0, #1
 *   @0x22bbcc str r2, [sp, #0x4]
 *   @0x22bbd0 str r3, [sp, #0xc]
 *   @0x22bbd4 ldr r9, [r3, #0x1c]
 *   @0x22bbd8 bl 0xb6c34 <calloc@plt>
 *   @0x22bbdc ldr r3, [sp, #0x4]
 *   @0x22bbe0 mov r1, #4
 *   @0x22bbe4 ldr r4, [r3]
 *   @0x22bbe8 mov r5, r0
 *   @0x22bbec str r3, [r0, #0x4]
 *   @0x22bbf0 str r8, [r0]
 *   @0x22bbf4 mov r0, r4
 *   @0x22bbf8 bl 0xb6c34 <calloc@plt>
 *   @0x22bbfc mov r1, #4
 *   @0x22bc00 str r0, [r5, #0x8]
 *   @0x22bc04 mov r0, r4
 *   @0x22bc08 bl 0xb6c34 <calloc@plt>
 *   @0x22bc0c mov r1, #4
 *   @0x22bc10 str r0, [r5, #0xc]
 *   @0x22bc14 mov r0, r4
 *   @0x22bc18 bl 0xb6c34 <calloc@plt>
 *   @0x22bc1c mov r1, #4
 *   @0x22bc20 mov r6, r0
 *   @0x22bc24 mov r0, r4
 *   @0x22bc28 str r6, [r5, #0x10]
 *   @0x22bc2c bl 0xb6c34 <calloc@plt>
 *   @0x22bc30 cmp r4, #0
 *   @0x22bc34 str r0, [r5, #0x14]
 *   @0x22bc38 ble 0x22bcfc <vorbis_synthesis_headerin+0xd98>
 *   @0x22bc3c ldr r12, [pc, #0xd0]
 *   @0x22bc40 mov lr, r6
 *   @0x22bc44 ldr r3, [pc, #0xcc]
 *   @0x22bc48 mov r4, #0
 *   @0x22bc4c ldr r6, [sp, #0x4]
 *   @0x22bc50 ldr r12, [pc, r12]
 *   @0x22bc54 ldr r3, [pc, r3]
 *   @0x22bc58 str r3, [sp, #0x8]
 *   @0x22bc5c b 0x22bc64 <vorbis_synthesis_headerin+0xd00>
 *   @0x22bc60 ldr lr, [r5, #0x10]
 *   @0x22bc64 ldr r3, [r6, #0x404]
 *   @0x22bc68 mov r1, r8
 *   @0x22bc6c ldr r11, [r6, #0x444]
 *   @0x22bc70 mov r0, r7
 *   @0x22bc74 add r6, r6, #4
 *   @0x22bc78 add r3, r9, r3, lsl #2
 *   @0x22bc7c add r11, r9, r11, lsl #2
 *   @0x22bc80 ldr r2, [r3, #0x420]
 *   @0x22bc84 ldr r2, [r12, r2, lsl #2]
 *   @0x22bc88 str r2, [lr, r4, lsl #2]
 *   @0x22bc8c ldr lr, [r5, #0x10]
 *   @0x22bc90 ldr r2, [r3, #0x520]
 *   @0x22bc94 ldr r10, [r5, #0x8]
 *   @0x22bc98 ldr r3, [lr, r4, lsl #2]
 *   @0x22bc9c ldr r3, [r3, #0x4]
 *   @0x22bca0 str r12, [sp]
 *   @0x22bca4 blx r3
 *   @0x22bca8 ldr lr, [sp, #0x8]
 *   @0x22bcac mov r1, r8
 *   @0x22bcb0 str r0, [r10, r4, lsl #2]
 *   @0x22bcb4 mov r0, r7
 *   @0x22bcb8 ldr r2, [r11, #0x620]
 *   @0x22bcbc ldr r3, [r5, #0x14]
 *   @0x22bcc0 ldr r2, [lr, r2, lsl #2]
 *   @0x22bcc4 str r2, [r3, r4, lsl #2]
 *   @0x22bcc8 ldr r3, [r5, #0x14]
 *   @0x22bccc ldr r2, [r11, #0x720]
 *   @0x22bcd0 ldr r10, [r5, #0xc]
 *   @0x22bcd4 ldr r3, [r3, r4, lsl #2]
 *   @0x22bcd8 ldr r3, [r3, #0x4]
 *   @0x22bcdc blx r3
 *   @0x22bce0 ldr r2, [sp, #0x4]
 *   @0x22bce4 ldr r12, [sp]
 *   @0x22bce8 ldr r3, [r2]
 *   @0x22bcec str r0, [r10, r4, lsl #2]
 *   @0x22bcf0 add r4, r4, #1
 *   @0x22bcf4 cmp r3, r4
 *   @0x22bcf8 bgt 0x22bc60 <vorbis_synthesis_headerin+0xcfc>
 *   @0x22bcfc ldr r2, [sp, #0xc]
 *   @0x22bd00 mov r0, r5
 *   @0x22bd04 ldr r3, [r2, #0x4]
 *   @0x22bd08 str r3, [r5, #0x18]
 *   @0x22bd0c add sp, sp, #20
 *   @0x22bd10 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22bd14 andseq r5, r12, r4, lsr r8
 *   @0x22bd18 andseq r5, r12, r4, lsr r8
 *   @0x22bd1c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x22bd20 mov r5, r0
 *   @0x22bd24 mov r4, r1
 *   @0x22bd28 mov r0, #1
 *   @0x22bd2c mov r1, #3216
 *   @0x22bd30 bl 0xb6c34 <calloc@plt>
 *   @0x22bd34 mov r1, #0
 *   @0x22bd38 mov r2, #3216
 *   @0x22bd3c ldr r9, [r5, #0x1c]
 *   @0x22bd40 mov r6, r0
 *   @0x22bd44 bl 0xb65b0 <memset@plt>
 *   @0x22bd48 mov r0, r4
 *   @0x22bd4c mov r1, #1
 *   @0x22bd50 bl 0x233b28 <oggpack_read>
 *   @0x22bd54 cmp r0, #0
 *   @0x22bd58 blt 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22bd5c moveq r3, #1
 *   @0x22bd60 streq r3, [r6]
 *   @0x22bd64 bne 0x22bf54 <vorbis_synthesis_headerin+0xff0>
 *   @0x22bd68 mov r0, r4
 *   @0x22bd6c mov r1, #1
 *   @0x22bd70 bl 0x233b28 <oggpack_read>
 *   @0x22bd74 cmp r0, #0
 *   @0x22bd78 blt 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22bd7c beq 0x22be48 <vorbis_synthesis_headerin+0xee4>
 *   @0x22bd80 mov r0, r4
 *   @0x22bd84 mov r1, #8
 *   @0x22bd88 bl 0x233b28 <oggpack_read>
 *   @0x22bd8c add r0, r0, #1
 *   @0x22bd90 str r0, [r6, #0x48c]
 *   @0x22bd94 cmp r0, #0
 *   @0x22bd98 ble 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22bd9c add r7, r6, #2176
 *   @0x22bda0 ldr r1, [r5, #0x4]
 *   @0x22bda4 add r7, r7, #12
 *   @0x22bda8 mov r8, #0
 *   @0x22bdac cmp r1, #0
 *   @0x22bdb0 beq 0x22bdd0 <vorbis_synthesis_headerin+0xe6c>
 *   @0x22bdb4 subs r3, r1, #1
 *   @0x22bdb8 moveq r1, r3
 *   @0x22bdbc beq 0x22bdd0 <vorbis_synthesis_headerin+0xe6c>
 *   @0x22bdc0 mov r1, #0
 *   @0x22bdc4 lsrs r3, r3, #1
 *   @0x22bdc8 add r1, r1, #1
 *   @0x22bdcc bne 0x22bdc4 <vorbis_synthesis_headerin+0xe60>
 *   @0x22bdd0 mov r0, r4
 *   @0x22bdd4 bl 0x233b28 <oggpack_read>
 *   @0x22bdd8 ldr r1, [r5, #0x4]
 *   @0x22bddc cmp r1, #0
 *   @0x22bde0 mov r10, r0
 *   @0x22bde4 str r0, [r7, #-0x3fc]
 *   @0x22bde8 beq 0x22be08 <vorbis_synthesis_headerin+0xea4>
 *   @0x22bdec subs r3, r1, #1
 *   @0x22bdf0 moveq r1, r3
 *   @0x22bdf4 beq 0x22be08 <vorbis_synthesis_headerin+0xea4>
 *   @0x22bdf8 mov r1, #0
 *   @0x22bdfc lsrs r3, r3, #1
 *   @0x22be00 add r1, r1, #1
 *   @0x22be04 bne 0x22bdfc <vorbis_synthesis_headerin+0xe98>
 *   @0x22be08 mov r0, r4
 *   @0x22be0c bl 0x233b28 <oggpack_read>
 *   @0x22be10 orrs r3, r10, r0
 *   @0x22be14 str r0, [r7, #0x4]!
 *   @0x22be18 bmi 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22be1c cmp r10, r0
 *   @0x22be20 beq 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22be24 ldr r1, [r5, #0x4]
 *   @0x22be28 cmp r10, r1
 *   @0x22be2c bge 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22be30 cmp r0, r1
 *   @0x22be34 bge 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22be38 ldr r3, [r6, #0x48c]
 *   @0x22be3c add r8, r8, #1
 *   @0x22be40 cmp r3, r8
 *   @0x22be44 bgt 0x22bdac <vorbis_synthesis_headerin+0xe48>
 *   @0x22be48 mov r0, r4
 *   @0x22be4c mov r1, #2
 *   @0x22be50 bl 0x233b28 <oggpack_read>
 *   @0x22be54 cmp r0, #0
 *   @0x22be58 bne 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22be5c ldr r3, [r6]
 *   @0x22be60 cmp r3, #1
 *   @0x22be64 ble 0x22bec4 <vorbis_synthesis_headerin+0xf60>
 *   @0x22be68 ldr r3, [r5, #0x4]
 *   @0x22be6c cmp r3, #0
 *   @0x22be70 movgt r7, r0
 *   @0x22be74 movgt r8, r6
 *   @0x22be78 bgt 0x22be94 <vorbis_synthesis_headerin+0xf30>
 *   @0x22be7c b 0x22becc <vorbis_synthesis_headerin+0xf68>
 *   @0x22be80 cmp r0, #0
 *   @0x22be84 blt 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22be88 ldr r2, [r5, #0x4]
 *   @0x22be8c cmp r2, r7
 *   @0x22be90 ble 0x22bec4 <vorbis_synthesis_headerin+0xf60>
 *   @0x22be94 mov r0, r4
 *   @0x22be98 mov r1, #4
 *   @0x22be9c bl 0x233b28 <oggpack_read>
 *   @0x22bea0 add r7, r7, #1
 *   @0x22bea4 str r0, [r8, #0x4]!
 *   @0x22bea8 ldr r3, [r6]
 *   @0x22beac cmp r0, r3
 *   @0x22beb0 blt 0x22be80 <vorbis_synthesis_headerin+0xf1c>
 *   @0x22beb4 mov r0, r6
 *   @0x22beb8 bl 0x22bb8c <vorbis_synthesis_headerin+0xc28>
 *   @0x22bebc mov r0, #0
 *   @0x22bec0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x22bec4 cmp r3, #0
 *   @0x22bec8 ble 0x22bf74 <vorbis_synthesis_headerin+0x1010>
 *   @0x22becc mov r5, r6
 *   @0x22bed0 mov r7, #0
 *   @0x22bed4 b 0x22bf2c <vorbis_synthesis_headerin+0xfc8>
 *   @0x22bed8 bl 0x233b28 <oggpack_read>
 *   @0x22bedc ldr r2, [r9, #0x14]
 *   @0x22bee0 mov r1, #8
 *   @0x22bee4 mov r3, r0
 *   @0x22bee8 cmp r3, r2
 *   @0x22beec mov r0, r4
 *   @0x22bef0 str r3, [r5, #0x404]
 *   @0x22bef4 bge 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22bef8 cmp r3, #0
 *   @0x22befc blt 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22bf00 bl 0x233b28 <oggpack_read>
 *   @0x22bf04 ldr r3, [r9, #0x18]
 *   @0x22bf08 add r5, r5, #4
 *   @0x22bf0c cmp r0, r3
 *   @0x22bf10 str r0, [r5, #0x440]
 *   @0x22bf14 bge 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22bf18 cmp r0, #0
 *   @0x22bf1c blt 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22bf20 ldr r3, [r6]
 *   @0x22bf24 cmp r3, r7
 *   @0x22bf28 ble 0x22bf74 <vorbis_synthesis_headerin+0x1010>
 *   @0x22bf2c mov r1, #8
 *   @0x22bf30 mov r0, r4
 *   @0x22bf34 bl 0x233b28 <oggpack_read>
 *   @0x22bf38 ldr r3, [r9, #0x10]
 *   @0x22bf3c mov r1, #8
 *   @0x22bf40 add r7, r7, #1
 *   @0x22bf44 cmp r0, r3
 *   @0x22bf48 mov r0, r4
 *   @0x22bf4c blt 0x22bed8 <vorbis_synthesis_headerin+0xf74>
 *   @0x22bf50 b 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22bf54 mov r0, r4
 *   @0x22bf58 mov r1, #4
 *   @0x22bf5c bl 0x233b28 <oggpack_read>
 *   @0x22bf60 add r0, r0, #1
 *   @0x22bf64 str r0, [r6]
 *   @0x22bf68 cmp r0, #0
 *   @0x22bf6c bgt 0x22bd68 <vorbis_synthesis_headerin+0xe04>
 *   @0x22bf70 b 0x22beb4 <vorbis_synthesis_headerin+0xf50>
 *   @0x22bf74 mov r0, r6
 *
 * ══ §3/16 CGestureTap::Update(long long)  0x1d8fac  size 2232  558 条（0x1d8fac..0x1d9864）
 * @func 0x1d8fac 0x1d9864  size 2232  558 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×7 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×5 / AddToDsMap(int, char*, double)×4 / ConvertGestureEventToGMEvent(int, bool)×4 / GetInstanceListWithEventType(int, int, float, float, int**, int*, bool)×4 / IO_Button_Down(int, int)×3 / CalcDistInches(int, int)×3 / CGesture::CGesture()×3
 * 字段偏移 top8: 0x8×30 / 0x4×17 / 0x30×15 / 0x34×15 / 0x28×12 / 0xc×12 / 0x14×9 / 0x44×7
 * VFP 指令 42 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d8fac ldr r1, [r0]
 *   @0x1d8fb0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d8fb4 sub sp, sp, #28
 *   @0x1d8fb8 ldr r7, [pc, #0x850]
 *   @0x1d8fbc mov r5, r3
 *   @0x1d8fc0 ldr r1, [r1, #0x18]
 *   @0x1d8fc4 mov r6, r0
 *   @0x1d8fc8 mov r4, r2
 *   @0x1d8fcc blx r1
 *   @0x1d8fd0 ldr r3, [pc, #0x83c]
 *   @0x1d8fd4 add r7, pc, r7
 *   @0x1d8fd8 ldr r3, [r7, r3]
 *   @0x1d8fdc ldrb r8, [r3]
 *   @0x1d8fe0 cmp r8, #0
 *   @0x1d8fe4 beq 0x1d900c <_ZN11CGestureTap6UpdateEx+0x60>
 *   @0x1d8fe8 ldr r10, [r6, #0x14]
 *   @0x1d8fec cmp r10, #0
 *   @0x1d8ff0 beq 0x1d9268 <_ZN11CGestureTap6UpdateEx+0x2bc>
 *   @0x1d8ff4 cmp r10, #1
 *   @0x1d8ff8 beq 0x1d9388 <_ZN11CGestureTap6UpdateEx+0x3dc>
 *   @0x1d8ffc cmp r10, #2
 *   @0x1d9000 beq 0x1d94fc <_ZN11CGestureTap6UpdateEx+0x550>
 *   @0x1d9004 add sp, sp, #28
 *   @0x1d9008 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d900c ldr r1, [pc, #0x804]
 *   @0x1d9010 ldrd r2, r3, [r6, #24]
 *   @0x1d9014 ldr r1, [r7, r1]
 *   @0x1d9018 subs r2, r4, r2
 *   @0x1d901c sbc r3, r5, r3
 *   @0x1d9020 ldrd r0, r1, [r1]
 *   @0x1d9024 cmp r0, r2
 *   @0x1d9028 sbcs r12, r1, r3
 *   @0x1d902c blt 0x1d9154 <_ZN11CGestureTap6UpdateEx+0x1a8>
 *   @0x1d9030 mov r0, #1
 *   @0x1d9034 ldr r1, [r6, #0x28]
 *   @0x1d9038 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x1d903c cmp r0, #0
 *   @0x1d9040 beq 0x1d9004 <_ZN11CGestureTap6UpdateEx+0x58>
 *   @0x1d9044 ldr r3, [r6, #0x44]
 *   @0x1d9048 ldr r0, [r6, #0x30]
 *   @0x1d904c ldr r2, [r6, #0x40]
 *   @0x1d9050 ldr r1, [r6, #0x34]
 *   @0x1d9054 rsb r0, r2, r0
 *   @0x1d9058 rsb r1, r3, r1
 *   @0x1d905c bl 0x1d6708 <_Z14CalcDistInchesii>
 *   @0x1d9060 ldr r3, [pc, #0x7b4]
 *   @0x1d9064 ldr r3, [r7, r3]
 *   @0x1d9068 vldr s15, [r3]
 *   @0x1d906c vmov s14, r0
 *   @0x1d9070 vcmpe.f32 s14, s15
 *   @0x1d9074 vmrs APSR_nzcv, fpscr
 *   @0x1d9078 bmi 0x1d9764 <_ZN11CGestureTap6UpdateEx+0x7b8>
 *   @0x1d907c mov r0, #16
 *   @0x1d9080 mvn r10, #0
 *   @0x1d9084 bl 0x27c524 <_Znwj>
 *   @0x1d9088 ldr lr, [r6, #0x3c]
 *   @0x1d908c ldr r12, [r6]
 *   @0x1d9090 add r1, r6, #48
 *   @0x1d9094 ldm r1, {r1, r2, r3}
 *   @0x1d9098 mov r9, r0
 *   @0x1d909c mov r0, r6
 *   @0x1d90a0 str r8, [r9, #0x8]
 *   @0x1d90a4 str r8, [r9, #0xc]
 *   @0x1d90a8 stm r9, {r8, r10}
 *   @0x1d90ac str lr, [sp]
 *   @0x1d90b0 strd r4, r5, [sp, #8]
 *   @0x1d90b4 ldr r12, [r12, #0x1c]
 *   @0x1d90b8 blx r12
 *   @0x1d90bc ldr r1, [pc, #0x75c]
 *   @0x1d90c0 mov r2, #0
 *   @0x1d90c4 mov r3, #0
 *   @0x1d90c8 add r1, pc, r1
 *   @0x1d90cc movt r3, #0x3ff0
 *   @0x1d90d0 str r0, [r9, #0x4]
 *   @0x1d90d4 bl 0x20bf40 <_Z10AddToDsMapiPcd>
 *   @0x1d90d8 mov r1, r8
 *   @0x1d90dc ldr r0, [r9]
 *   @0x1d90e0 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d90e4 ldr r2, [r6, #0x30]
 *   @0x1d90e8 ldr r3, [r6, #0x34]
 *   @0x1d90ec add r12, r6, #12
 *   @0x1d90f0 str r8, [sp, #0x8]
 *   @0x1d90f4 vmov s14, r2
 *   @0x1d90f8 str r12, [sp]
 *   @0x1d90fc vmov s15, r3
 *   @0x1d9100 vcvt.f32.s32 s14, s14
 *   @0x1d9104 vcvt.f32.s32 s15, s15
 *   @0x1d9108 vmov r2, s14
 *   @0x1d910c vmov r3, s15
 *   @0x1d9110 mov r1, r0
 *   @0x1d9114 add r0, r6, #16
 *   @0x1d9118 str r0, [sp, #0x4]
 *   @0x1d911c mov r0, #13
 *   @0x1d9120 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d9124 ldr r3, [r6, #0xc]
 *   @0x1d9128 ldr r12, [r6, #0x10]
 *   @0x1d912c mov r0, #12
 *   @0x1d9130 ldr r1, [pc, #0x6ec]
 *   @0x1d9134 mov r2, #143
 *   @0x1d9138 str r3, [r9, #0x8]
 *   @0x1d913c mov r3, #1
 *   @0x1d9140 str r12, [r9, #0xc]
 *   @0x1d9144 ldr r4, [r7, r1]
 *   @0x1d9148 ldr r1, [pc, #0x6d8]
 *   @0x1d914c add r1, pc, r1
 *   @0x1d9150 b 0x1d9228 <_ZN11CGestureTap6UpdateEx+0x27c>
 *   @0x1d9154 mov r0, #16
 *   @0x1d9158 mvn r10, #0
 *   @0x1d915c bl 0x27c524 <_Znwj>
 *   @0x1d9160 ldr lr, [r6, #0x3c]
 *   @0x1d9164 ldr r12, [r6]
 *   @0x1d9168 add r1, r6, #48
 *   @0x1d916c ldm r1, {r1, r2, r3}
 *   @0x1d9170 mov r9, r0
 *   @0x1d9174 mov r0, r6
 *   @0x1d9178 str r8, [r9, #0x8]
 *   @0x1d917c str r8, [r9, #0xc]
 *   @0x1d9180 stm r9, {r8, r10}
 *   @0x1d9184 str lr, [sp]
 *   @0x1d9188 strd r4, r5, [sp, #8]
 *   @0x1d918c ldr r12, [r12, #0x1c]
 *   @0x1d9190 blx r12
 *   @0x1d9194 ldr r1, [pc, #0x690]
 *   @0x1d9198 mov r2, #0
 *   @0x1d919c mov r3, #0
 *   @0x1d91a0 add r1, pc, r1
 *   @0x1d91a4 movt r3, #0x3ff0
 *   @0x1d91a8 str r0, [r9, #0x4]
 *   @0x1d91ac bl 0x20bf40 <_Z10AddToDsMapiPcd>
 *   @0x1d91b0 mov r1, r8
 *   @0x1d91b4 ldr r0, [r9]
 *   @0x1d91b8 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d91bc ldr r2, [r6, #0x30]
 *   @0x1d91c0 ldr r3, [r6, #0x34]
 *   @0x1d91c4 add r12, r6, #12
 *   @0x1d91c8 str r8, [sp, #0x8]
 *   @0x1d91cc vmov s14, r2
 *   @0x1d91d0 str r12, [sp]
 *   @0x1d91d4 vmov s15, r3
 *   @0x1d91d8 vcvt.f32.s32 s14, s14
 *   @0x1d91dc vcvt.f32.s32 s15, s15
 *   @0x1d91e0 vmov r2, s14
 *   @0x1d91e4 vmov r3, s15
 *   @0x1d91e8 mov r1, r0
 *   @0x1d91ec add r0, r6, #16
 *   @0x1d91f0 str r0, [sp, #0x4]
 *   @0x1d91f4 mov r0, #13
 *   @0x1d91f8 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d91fc ldr r3, [r6, #0xc]
 *   @0x1d9200 ldr r12, [r6, #0x10]
 *   @0x1d9204 mov r0, #12
 *   @0x1d9208 ldr r1, [pc, #0x614]
 *   @0x1d920c mov r2, #143
 *   @0x1d9210 str r3, [r9, #0x8]
 *   @0x1d9214 mov r3, #1
 *   @0x1d9218 str r12, [r9, #0xc]
 *   @0x1d921c ldr r4, [r7, r1]
 *   @0x1d9220 ldr r1, [pc, #0x608]
 *   @0x1d9224 add r1, pc, r1
 *   @0x1d9228 ldr r12, [r4, #0x8]
 *   @0x1d922c add r12, r12, r3
 *   @0x1d9230 str r12, [r4, #0x8]
 *   @0x1d9234 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d9238 ldr r3, [r4, #0x4]
 *   @0x1d923c cmp r3, #0
 *   @0x1d9240 str r9, [r0, #0x8]
 *   @0x1d9244 strne r0, [r3]
 *   @0x1d9248 strne r3, [r0, #0x4]
 *   @0x1d924c strne r0, [r4, #0x4]
 *   @0x1d9250 strne r8, [r0]
 *   @0x1d9254 beq 0x1d962c <_ZN11CGestureTap6UpdateEx+0x680>
 *   @0x1d9258 mvn r3, #0
 *   @0x1d925c str r3, [r6, #0x14]
 *   @0x1d9260 add sp, sp, #28
 *   @0x1d9264 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d9268 mov r9, #1
 *   @0x1d926c mov r0, #16
 *   @0x1d9270 str r9, [r6, #0x5c]
 *   @0x1d9274 mvn r11, #0
 *   @0x1d9278 bl 0x27c524 <_Znwj>
 *   @0x1d927c ldr lr, [r6, #0x3c]
 *   @0x1d9280 ldr r12, [r6]
 *   @0x1d9284 add r1, r6, #48
 *   @0x1d9288 ldm r1, {r1, r2, r3}
 *   @0x1d928c mov r8, r0
 *   @0x1d9290 mov r0, r6
 *   @0x1d9294 str r10, [r8, #0x8]
 *   @0x1d9298 str r10, [r8, #0xc]
 *   @0x1d929c stm r8, {r10, r11}
 *   @0x1d92a0 str lr, [sp]
 *   @0x1d92a4 strd r4, r5, [sp, #8]
 *   @0x1d92a8 ldr r12, [r12, #0x1c]
 *   @0x1d92ac blx r12
 *   @0x1d92b0 vldr s15, [r6, #92]
 *   @0x1d92b4 vcvt.f64.s32 d7, s15
 *   @0x1d92b8 ldr r1, [pc, #0x574]
 *   @0x1d92bc add r1, pc, r1
 *   @0x1d92c0 vmov r2, r3, d7
 *   @0x1d92c4 str r0, [r8, #0x4]
 *   @0x1d92c8 bl 0x20bf40 <_Z10AddToDsMapiPcd>
 *   @0x1d92cc mov r1, r10
 *   @0x1d92d0 ldr r0, [r8]
 *   @0x1d92d4 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d92d8 ldr r2, [r6, #0x30]
 *   @0x1d92dc ldr r3, [r6, #0x34]
 *   @0x1d92e0 add r12, r6, #12
 *   @0x1d92e4 str r10, [sp, #0x8]
 *   @0x1d92e8 vmov s14, r2
 *   @0x1d92ec str r12, [sp]
 *   @0x1d92f0 vmov s15, r3
 *   @0x1d92f4 vcvt.f32.s32 s14, s14
 *   @0x1d92f8 vcvt.f32.s32 s15, s15
 *   @0x1d92fc vmov r2, s14
 *   @0x1d9300 vmov r3, s15
 *   @0x1d9304 mov r1, r0
 *   @0x1d9308 add r0, r6, #16
 *   @0x1d930c str r0, [sp, #0x4]
 *   @0x1d9310 mov r0, #13
 *   @0x1d9314 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d9318 ldr r2, [r6, #0xc]
 *   @0x1d931c ldr r12, [r6, #0x10]
 *   @0x1d9320 mov r3, r9
 *   @0x1d9324 ldr r1, [pc, #0x4f8]
 *   @0x1d9328 mov r0, #12
 *   @0x1d932c str r2, [r8, #0x8]
 *   @0x1d9330 mov r2, #143
 *   @0x1d9334 str r12, [r8, #0xc]
 *   @0x1d9338 ldr r7, [r7, r1]
 *   @0x1d933c ldr r1, [pc, #0x4f4]
 *   @0x1d9340 ldr r12, [r7, #0x8]
 *   @0x1d9344 add r1, pc, r1
 *   @0x1d9348 add r12, r12, r9
 *   @0x1d934c str r12, [r7, #0x8]
 *   @0x1d9350 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d9354 ldr r3, [r7, #0x4]
 *   @0x1d9358 cmp r3, #0
 *   @0x1d935c str r8, [r0, #0x8]
 *   @0x1d9360 strne r0, [r3]
 *   @0x1d9364 strne r3, [r0, #0x4]
 *   @0x1d9368 strne r0, [r7, #0x4]
 *   @0x1d936c strne r10, [r0]
 *   @0x1d9370 beq 0x1d9750 <_ZN11CGestureTap6UpdateEx+0x7a4>
 *   @0x1d9374 mov r3, #1
 *   @0x1d9378 strd r4, r5, [r6, #24]
 *   @0x1d937c str r3, [r6, #0x14]
 *   @0x1d9380 add sp, sp, #28
 *   @0x1d9384 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d9388 ldr r1, [pc, #0x488]
 *   @0x1d938c ldrd r2, r3, [r6, #24]
 *   @0x1d9390 ldr r1, [r7, r1]
 *   @0x1d9394 subs r2, r4, r2
 *   @0x1d9398 sbc r3, r5, r3
 *   @0x1d939c ldrd r8, r9, [r1]
 *   @0x1d93a0 cmp r8, r2
 *   @0x1d93a4 sbcs r1, r9, r3
 *   @0x1d93a8 blt 0x1d9258 <_ZN11CGestureTap6UpdateEx+0x2ac>
 *   @0x1d93ac mov r0, r10
 *   @0x1d93b0 ldr r1, [r6, #0x28]
 *   @0x1d93b4 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x1d93b8 cmp r0, #0
 *   @0x1d93bc beq 0x1d9004 <_ZN11CGestureTap6UpdateEx+0x58>
 *   @0x1d93c0 ldr r3, [r6, #0x44]
 *   @0x1d93c4 ldr r0, [r6, #0x30]
 *   @0x1d93c8 ldr r2, [r6, #0x40]
 *   @0x1d93cc ldr r1, [r6, #0x34]
 *   @0x1d93d0 rsb r0, r2, r0
 *   @0x1d93d4 rsb r1, r3, r1
 *   @0x1d93d8 bl 0x1d6708 <_Z14CalcDistInchesii>
 *   @0x1d93dc ldr r3, [pc, #0x438]
 *   @0x1d93e0 ldr r3, [r7, r3]
 *   @0x1d93e4 vldr s15, [r3]
 *   @0x1d93e8 vmov s14, r0
 *   @0x1d93ec vcmpe.f32 s14, s15
 *   @0x1d93f0 vmrs APSR_nzcv, fpscr
 *   @0x1d93f4 bpl 0x1d9258 <_ZN11CGestureTap6UpdateEx+0x2ac>
 *   @0x1d93f8 ldr r3, [r6, #0x5c]
 *   @0x1d93fc mov r9, #2
 *   @0x1d9400 strd r4, r5, [r6, #24]
 *   @0x1d9404 cmp r3, #1
 *   @0x1d9408 str r9, [r6, #0x14]
 *   @0x1d940c bne 0x1d9004 <_ZN11CGestureTap6UpdateEx+0x58>
 *   @0x1d9410 mov r0, #96
 *   @0x1d9414 str r3, [sp, #0x14]
 *   @0x1d9418 bl 0x27c524 <_Znwj>
 *   @0x1d941c ldr r11, [pc, #0x418]
 *   @0x1d9420 mov r10, #0
 *   @0x1d9424 mov r8, r0
 *   @0x1d9428 bl 0x1d7c0c <_ZN8CGestureC2Ev>
 *   @0x1d942c ldr r3, [sp, #0x14]
 *   @0x1d9430 mvn r1, #0
 *   @0x1d9434 str r10, [r8, #0x30]
 *   @0x1d9438 mov r2, #0
 *   @0x1d943c ldr lr, [r6, #0x30]
 *   @0x1d9440 mov r0, #12
 *   @0x1d9444 str r10, [r8, #0x34]
 *   @0x1d9448 str r2, [r8, #0x58]
 *   @0x1d944c mov r2, #143
 *   @0x1d9450 ldr r12, [r6, #0x34]
 *   @0x1d9454 str r1, [r8, #0x28]
 *   @0x1d9458 str r10, [r8, #0x38]
 *   @0x1d945c str r10, [r8, #0x3c]
 *   @0x1d9460 str r10, [r8, #0x48]
 *   @0x1d9464 str r10, [r8, #0x4c]
 *   @0x1d9468 str r10, [r8, #0x5c]
 *   @0x1d946c str r1, [r8, #0x2c]
 *   @0x1d9470 ldr r1, [r7, r11]
 *   @0x1d9474 ldr r11, [r6, #0x28]
 *   @0x1d9478 str lr, [r8, #0x30]
 *   @0x1d947c add lr, r1, #8
 *   @0x1d9480 str r12, [r8, #0x34]
 *   @0x1d9484 ldr r1, [pc, #0x3b4]
 *   @0x1d9488 ldr r12, [r6, #0x30]
 *   @0x1d948c ldr r6, [r6, #0x34]
 *   @0x1d9490 str lr, [r8]
 *   @0x1d9494 str r9, [r8, #0x8]
 *   @0x1d9498 str r12, [r8, #0x40]
 *   @0x1d949c str r11, [r8, #0x28]
 *   @0x1d94a0 str r10, [r8, #0x14]
 *   @0x1d94a4 strd r4, r5, [r8, #24]
 *   @0x1d94a8 strd r4, r5, [r8, #32]
 *   @0x1d94ac str r6, [r8, #0x44]
 *   @0x1d94b0 ldr r4, [r7, r1]
 *   @0x1d94b4 ldr r1, [pc, #0x388]
 *   @0x1d94b8 ldr r12, [r4, #0x8]
 *   @0x1d94bc add r1, pc, r1
 *   @0x1d94c0 add r12, r12, #1
 *   @0x1d94c4 str r12, [r4, #0x8]
 *   @0x1d94c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d94cc ldr r3, [r4, #0x4]
 *   @0x1d94d0 cmp r3, r10
 *   @0x1d94d4 str r8, [r0, #0x8]
 *   @0x1d94d8 streq r0, [r4, #0x4]
 *   @0x1d94dc strne r0, [r3]
 *   @0x1d94e0 streq r0, [r4]
 *   @0x1d94e4 strne r3, [r0, #0x4]
 *   @0x1d94e8 streq r3, [r0, #0x4]
 *   @0x1d94ec strne r0, [r4, #0x4]
 *   @0x1d94f0 streq r3, [r0]
 *   @0x1d94f4 strne r10, [r0]
 *   @0x1d94f8 b 0x1d9004 <_ZN11CGestureTap6UpdateEx+0x58>
 *   @0x1d94fc mov r0, #1
 *   @0x1d9500 ldr r1, [r6, #0x28]
 *   @0x1d9504 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x1d9508 subs r9, r0, #0
 *   @0x1d950c beq 0x1d9640 <_ZN11CGestureTap6UpdateEx+0x694>
 *   @0x1d9510 ldr r1, [r6, #0x4c]
 *   @0x1d9514 ldr r0, [r6, #0x48]
 *   @0x1d9518 bl 0x1d6708 <_Z14CalcDistInchesii>
 *   @0x1d951c ldr r1, [pc, #0x324]
 *   @0x1d9520 ldrd r2, r3, [r6, #24]
 *   @0x1d9524 ldr r1, [r7, r1]
 *   @0x1d9528 subs r2, r4, r2
 *   @0x1d952c sbc r3, r5, r3
 *   @0x1d9530 vmov s15, r0
 *   @0x1d9534 ldrd r0, r1, [r1]
 *   @0x1d9538 cmp r0, r2
 *   @0x1d953c sbcs r12, r1, r3
 *   @0x1d9540 blt 0x1d955c <_ZN11CGestureTap6UpdateEx+0x5b0>
 *   @0x1d9544 ldr r3, [pc, #0x300]
 *   @0x1d9548 ldr r3, [r7, r3]
 *   @0x1d954c vldr s14, [r3]
 *   @0x1d9550 vcmpe.f32 s15, s14
 *   @0x1d9554 vmrs APSR_nzcv, fpscr
 *   @0x1d9558 ble 0x1d9004 <_ZN11CGestureTap6UpdateEx+0x58>
 *   @0x1d955c mov r0, #96
 *   @0x1d9560 mov r9, #0
 *   @0x1d9564 bl 0x27c524 <_Znwj>
 *   @0x1d9568 ldr r10, [pc, #0x2e0]
 *   @0x1d956c mov r11, #3
 *   @0x1d9570 mov r8, r0
 *   @0x1d9574 bl 0x1d7c0c <_ZN8CGestureC2Ev>
 *   @0x1d9578 str r9, [r8, #0x44]
 *   @0x1d957c mvn r3, #0
 *   @0x1d9580 ldr r1, [r6, #0x44]
 *   @0x1d9584 mov r2, #0
 *   @0x1d9588 str r3, [r8, #0x28]
 *   @0x1d958c mov r0, #12
 *   @0x1d9590 ldr lr, [r6, #0x28]
 *   @0x1d9594 str r9, [r8, #0x40]
 *   @0x1d9598 str r2, [r8, #0x58]
 *   @0x1d959c mov r2, #143
 *   @0x1d95a0 ldr r12, [r6, #0x40]
 *   @0x1d95a4 str r3, [r8, #0x2c]
 *   @0x1d95a8 mov r3, #1
 *   @0x1d95ac str r9, [r8, #0x38]
 *   @0x1d95b0 str r9, [r8, #0x3c]
 *   @0x1d95b4 str r9, [r8, #0x48]
 *   @0x1d95b8 str r9, [r8, #0x4c]
 *   @0x1d95bc ldr r10, [r7, r10]
 *   @0x1d95c0 str r1, [r8, #0x34]
 *   @0x1d95c4 str r1, [r8, #0x44]
 *   @0x1d95c8 add r10, r10, #8
 *   @0x1d95cc ldr r1, [pc, #0x26c]
 *   @0x1d95d0 str r11, [r8, #0x8]
 *   @0x1d95d4 str r10, [r8]
 *   @0x1d95d8 str r12, [r8, #0x30]
 *   @0x1d95dc str r12, [r8, #0x40]
 *   @0x1d95e0 str lr, [r8, #0x28]
 *   @0x1d95e4 str r9, [r8, #0x14]
 *   @0x1d95e8 strd r4, r5, [r8, #24]
 *   @0x1d95ec strd r4, r5, [r8, #32]
 *   @0x1d95f0 ldr r4, [r7, r1]
 *   @0x1d95f4 ldr r1, [pc, #0x258]
 *   @0x1d95f8 ldr r12, [r4, #0x8]
 *   @0x1d95fc add r1, pc, r1
 *   @0x1d9600 add r12, r12, r3
 *   @0x1d9604 str r12, [r4, #0x8]
 *   @0x1d9608 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d960c ldr r3, [r4, #0x4]
 *   @0x1d9610 cmp r3, r9
 *   @0x1d9614 str r8, [r0, #0x8]
 *   @0x1d9618 strne r0, [r3]
 *   @0x1d961c strne r3, [r0, #0x4]
 *   @0x1d9620 strne r0, [r4, #0x4]
 *   @0x1d9624 strne r9, [r0]
 *   @0x1d9628 bne 0x1d9258 <_ZN11CGestureTap6UpdateEx+0x2ac>
 *   @0x1d962c str r0, [r4, #0x4]
 *   @0x1d9630 str r0, [r4]
 *   @0x1d9634 str r3, [r0, #0x4]
 *   @0x1d9638 str r3, [r0]
 *   @0x1d963c b 0x1d9258 <_ZN11CGestureTap6UpdateEx+0x2ac>
 *   @0x1d9640 ldr r3, [r6, #0x5c]
 *   @0x1d9644 mov r0, #16
 *   @0x1d9648 mvn r10, #0
 *   @0x1d964c add r3, r3, #1
 *   @0x1d9650 str r3, [r6, #0x5c]
 *   @0x1d9654 bl 0x27c524 <_Znwj>
 *   @0x1d9658 ldr lr, [r6, #0x3c]
 *   @0x1d965c ldr r12, [r6]
 *   @0x1d9660 add r1, r6, #48
 *   @0x1d9664 ldm r1, {r1, r2, r3}
 *   @0x1d9668 mov r8, r0
 *   @0x1d966c mov r0, r6
 *   @0x1d9670 str r9, [r8, #0x8]
 *   @0x1d9674 str r9, [r8, #0xc]
 *   @0x1d9678 stm r8, {r9, r10}
 *   @0x1d967c str lr, [sp]
 *   @0x1d9680 strd r4, r5, [sp, #8]
 *   @0x1d9684 ldr r12, [r12, #0x1c]
 *   @0x1d9688 blx r12
 *   @0x1d968c vldr s15, [r6, #92]
 *   @0x1d9690 vcvt.f64.s32 d7, s15
 *   @0x1d9694 ldr r1, [pc, #0x1bc]
 *   @0x1d9698 add r1, pc, r1
 *   @0x1d969c vmov r2, r3, d7
 *   @0x1d96a0 str r0, [r8, #0x4]
 *   @0x1d96a4 bl 0x20bf40 <_Z10AddToDsMapiPcd>
 *   @0x1d96a8 mov r1, r9
 *   @0x1d96ac ldr r0, [r8]
 *   @0x1d96b0 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d96b4 ldr r2, [r6, #0x30]
 *   @0x1d96b8 ldr r3, [r6, #0x34]
 *   @0x1d96bc add r12, r6, #12
 *   @0x1d96c0 str r9, [sp, #0x8]
 *   @0x1d96c4 vmov s14, r2
 *   @0x1d96c8 str r12, [sp]
 *   @0x1d96cc vmov s15, r3
 *   @0x1d96d0 vcvt.f32.s32 s14, s14
 *   @0x1d96d4 vcvt.f32.s32 s15, s15
 *   @0x1d96d8 vmov r2, s14
 *   @0x1d96dc vmov r3, s15
 *   @0x1d96e0 mov r1, r0
 *   @0x1d96e4 add r0, r6, #16
 *   @0x1d96e8 str r0, [sp, #0x4]
 *   @0x1d96ec mov r0, #13
 *   @0x1d96f0 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d96f4 ldr r3, [r6, #0xc]
 *   @0x1d96f8 ldr r12, [r6, #0x10]
 *   @0x1d96fc mov r0, #12
 *   @0x1d9700 ldr r1, [pc, #0x11c]
 *   @0x1d9704 mov r2, #143
 *   @0x1d9708 str r3, [r8, #0x8]
 *   @0x1d970c mov r3, #1
 *   @0x1d9710 str r12, [r8, #0xc]
 *   @0x1d9714 ldr r7, [r7, r1]
 *   @0x1d9718 ldr r1, [pc, #0x13c]
 *   @0x1d971c ldr r12, [r7, #0x8]
 *   @0x1d9720 add r1, pc, r1
 *   @0x1d9724 add r12, r12, r3
 *   @0x1d9728 str r12, [r7, #0x8]
 *   @0x1d972c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d9730 ldr r3, [r7, #0x4]
 *   @0x1d9734 cmp r3, #0
 *   @0x1d9738 str r8, [r0, #0x8]
 *   @0x1d973c strne r0, [r3]
 *   @0x1d9740 strne r3, [r0, #0x4]
 *   @0x1d9744 strne r0, [r7, #0x4]
 *   @0x1d9748 strne r9, [r0]
 *   @0x1d974c bne 0x1d9374 <_ZN11CGestureTap6UpdateEx+0x3c8>
 *   @0x1d9750 str r0, [r7, #0x4]
 *   @0x1d9754 str r0, [r7]
 *   @0x1d9758 str r3, [r0, #0x4]
 *   @0x1d975c str r3, [r0]
 *   @0x1d9760 b 0x1d9374 <_ZN11CGestureTap6UpdateEx+0x3c8>
 *   @0x1d9764 mov r0, #96
 *   @0x1d9768 ldr r10, [pc, #0xcc]
 *   @0x1d976c bl 0x27c524 <_Znwj>
 *   @0x1d9770 mov r9, r0
 *   @0x1d9774 bl 0x1d7c0c <_ZN8CGestureC2Ev>
 *   @0x1d9778 str r8, [r9, #0x30]
 *   @0x1d977c mvn r1, #0
 *   @0x1d9780 ldr r11, [r6, #0x30]
 *   @0x1d9784 mov r3, #0
 *   @0x1d9788 str r8, [r9, #0x34]
 *   @0x1d978c mov lr, #2
 *   @0x1d9790 ldr r12, [r6, #0x34]
 *   @0x1d9794 mov r0, #12
 *   @0x1d9798 str r1, [r9, #0x28]
 *   @0x1d979c mov r2, #143
 *   @0x1d97a0 str r3, [r9, #0x58]
 *   @0x1d97a4 mov r3, #1
 *   @0x1d97a8 str r8, [r9, #0x38]
 *   @0x1d97ac str r8, [r9, #0x3c]
 *   @0x1d97b0 str r8, [r9, #0x48]
 *   @0x1d97b4 str r8, [r9, #0x4c]
 *   @0x1d97b8 str r8, [r9, #0x5c]
 *   @0x1d97bc str r1, [r9, #0x2c]
 *   @0x1d97c0 ldr r1, [r7, r10]
 *   @0x1d97c4 ldr r10, [r6, #0x28]
 *   @0x1d97c8 str r11, [r9, #0x30]
 *   @0x1d97cc add r11, r1, #8
 *   @0x1d97d0 str r12, [r9, #0x34]
 *   @0x1d97d4 ldr r1, [r6, #0x34]
 *   @0x1d97d8 ldr r12, [r6, #0x30]
 *   @0x1d97dc str r11, [r9]
 *   @0x1d97e0 str r1, [r9, #0x44]
 *   @0x1d97e4 ldr r1, [pc, #0x54]
 *   @0x1d97e8 str r10, [r9, #0x28]
 *   @0x1d97ec str r8, [r9, #0x14]
 *   @0x1d97f0 strd r4, r5, [r9, #24]
 *   @0x1d97f4 strd r4, r5, [r9, #32]
 *   @0x1d97f8 str lr, [r9, #0x8]
 *   @0x1d97fc str r12, [r9, #0x40]
 *   @0x1d9800 ldr r4, [r7, r1]
 *   @0x1d9804 ldr r1, [pc, #0x54]
 *   @0x1d9808 add r1, pc, r1
 *   @0x1d980c b 0x1d9228 <_ZN11CGestureTap6UpdateEx+0x27c>
 *   @0x1d9810 eoreq r8, r1, r12, ror r12
 *   @0x1d9814 .word 0xffffef9c
 *   @0x1d9818 .word 0xffffef80
 *   @0x1d981c .word 0xffffef84
 *   @0x1d9820 andseq r8, r7, r4, lsr #1
 *   @0x1d9824 .word 0xffffefb0
 *   @0x1d9828 andseq r3, r7, r4, ror #25
 *   @0x1d982c andseq r7, r7, r12, asr #31
 *   @0x1d9830 andseq r3, r7, r12, lsl #24
 *   @0x1d9834 ldrheq r7, [r7], -r0
 *   @0x1d9838 andseq r3, r7, r12, ror #21
 *   @0x1d983c .word 0xffffefd4
 *   @0x1d9840 .word 0xffffefc4
 *   @0x1d9844 andseq r3, r7, r4, ror r9
 *   @0x1d9848 .word 0xffffef74
 *   @0x1d984c .word 0xffffef78
 *   @0x1d9850 .word 0xffffefc8
 *   @0x1d9854 andseq r3, r7, r4, lsr r8
 *   @0x1d9858 ldrsbeq r7, [r7], -r4
 *   @0x1d985c andseq r3, r7, r0, lsl r7
 *   @0x1d9860 andseq r3, r7, r8, lsr #12
 *
 * ══ §4/16 png_init_read_transformations  0x2ab178  size 2172  543 条（0x2ab178..0x2ab9f4）
 * @func 0x2ab178 0x2ab9f4  size 2172  543 条
 * 部分覆盖: 本节 543/922 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6784×4 / anon_2e9c78+0x1d48 / 0x36eeac / png_build_gamma_table / png_init_read_transformations+0x7d2 / 0x5a7576 / anon_2e9c78+0x2106 / 0x5a79a6
 * 字段偏移 top8: 0x2×6 / 0x-1×3 / 0x358×1 / 0x1×1 / 0x268×1 / 0x264×1 / 0x388×1 / 0x-3×1
 * VFP 指令 115 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ab178 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ab17c vpush {d8, d9, d10, d11}
 *   @0x2ab180 mov r4, r0
 *   @0x2ab184 addlt r3, r3, r4, lsr r1
 *   @0x2ab188 ldrb.w r10, [r0, #0x1ea]
 *   @0x2ab18c lsls r5, r3, #0x17
 *   @0x2ab190 tst.w r10, #0x2
 *   @0x2ab194 bne 0x2ab1a4 <png_init_read_transformations+0x2c>
 *   @0x2ab198 vst4.8 {d18, d20, d22, d24}, [r2:128], r12
 *   @0x2ab19c .word 0xf8c06200
 *   @0x2ab1a0 ands r2, r6, r12, lsr #2
 *   @0x2ab1a4 and r2, r3, #0x4180
 *   @0x2ab1a8 cmp.w r2, #0x4080
 *   @0x2ab1ac bne 0x2ab1d2 <png_init_read_transformations+0x5a>
 *   @0x2ab1b0 rfeia r4!
 *   @0x2ab1b4 addsmi r1, r1, #0, #4
 *   @0x2ab1b8 bne 0x2ab1d2 <png_init_read_transformations+0x5a>
 *   @0x2ab1bc addmi r2, r10, #536870912
 *   @0x2ab1c0 bne 0x2ab1d2 <png_init_read_transformations+0x5a>
 *   @0x2ab1c4 .word 0xf8a4112c
 *   @0x2ab1c8 vst1.8 {d18, d19, d20, d21}, [r1], r4
 *   @0x2ab1cc .word 0xf8c46100
 *   @0x2ab1d0 vst4.8 {d1, d3, d5, d7}, [r3:128], r12
 *   @0x2ab1d4 .word 0xf5b25288
 *   @0x2ab1d8 cmple r10, r8, lsl #31
 *   @0x2ab1dc tst.w r10, #0x2
 *   @0x2ab1e0 bne 0x2ab24c <png_init_read_transformations+0xd4>
 *   @0x2ab1e4 bhs 0x333998
 *   @0x2ab1e8 beq 0x2ab1fa <png_init_read_transformations+0x82>
 *   @0x2ab1ec beq 0x2ab202 <png_init_read_transformations+0x8a>
 *   @0x2ab1f0 bne 0x2ab23a <png_init_read_transformations+0xc2>
 *   @0x2ab1f4 mvnshs r2, r4, lsl #4
 *   @0x2ab1f8 b 0x2ab208 <png_init_read_transformations+0x90>
 *   @0x2ab1fc cmphs r5, r4, lsl #4
 *   @0x2ab200 b 0x2ab208 <png_init_read_transformations+0x90>
 *   @0x2ab204 tsths r1, r4, lsl #4
 *   @0x2ab208 muls r2, r1, r2
 *   @0x2ab20c uxth r2, r2
 *   @0x2ab210 .word 0xf8a42204
 *   @0x2ab214 .word 0xf8a42202
 *   @0x2ab218 .word 0xf8a42200
 *   @0x2ab21c ldrtle r2, [r8], #-510
 *   @0x2ab220 ldrh.w r3, [r4, #0x258]
 *   @0x2ab224 muls r3, r1, r3
 *   @0x2ab228 strh.w r3, [r4, #0x258]
 *   @0x2ab22c strh.w r3, [r4, #0x256]
 *   @0x2ab230 strh.w r3, [r4, #0x254]
 *   @0x2ab234 strh.w r3, [r4, #0x252]
 *   @0x2ab238 b 0x2ab292 <png_init_read_transformations+0x11a>
 *   @0x2ab23c .word 0xf8a43204
 *   @0x2ab240 .word 0xf8a43202
 *   @0x2ab244 .word 0xf8a43200
 *   @0x2ab248 .word 0xe02231fe
 *   @0x2ab24c cmp.w r10, #0x3
 *   @0x2ab250 bne 0x2ab292 <png_init_read_transformations+0x11a>
 *   @0x2ab254 .word 0xf8d411fc
 *   @0x2ab258 bl 0x2eb9c0 <FT_Done_Memory+0x1d4c>
 *   @0x2ab25c stmdane r2, {r0, r6, r8} ^
 *   @0x2ab260 ldrb r1, [r0, r1]
 *   @0x2ab264 ldmdavc r1, {r1, r2, r3, r4, r5, r6, r7, r8, r12} ^
 *   @0x2ab268 strh.w r1, [r4, #0x200]
 *   @0x2ab26c ldrb r2, [r2, #0x2]
 *   @0x2ab270 tsteq r10, #536870912
 *   @0x2ab274 bpl 0x2ab292 <png_init_read_transformations+0x11a>
 *   @0x2ab278 .word 0xd10a7300
 *   @0x2ab27c ldrh.w r1, [r4, #0x1de]
 *   @0x2ab280 cmp r3, r1
 *   @0x2ab284 ldr.w r2, [r4, #0x24c]
 *   @0x2ab288 ldrb r0, [r2, r3]
 *   @0x2ab28c strb r0, [r2, r3]
 *   @0x2ab290 b 0x2ab280 <png_init_read_transformations+0x108>
 *   @0x2ab294 .word 0xf1ba73fe
 *   @0x2ab298 blgt 0x36eeac <_ZTS13C_UTF16String+0x5f58>
 *   @0x2ab29c str.w r0, [r4, #0x206]
 *   @0x2ab2a0 str.w r1, [r4, #0x20a]
 *   @0x2ab2a4 ldrh r3, [r3]
 *   @0x2ab2a8 .word 0xd129320e
 *   @0x2ab2ac ldrh.w r2, [r4, #0x1de]
 *   @0x2ab2b0 cbz r2, 0x2ab300 <png_init_read_transformations+0x188>
 *   @0x2ab2b4 vldr s14, [r4, #544]
 *   @0x2ab2b8 vmul.f32 s12, s13, s18
 *   @0x2ab2bc .word 0xeeb76a27
 *   @0x2ab2c0 vmov.f64 d7, #1.000000e+00
 *   @0x2ab2c4 vsub.f32 s12, s13, s12
 *   @0x2ab2c8 vldr d6, [pc, #284]
 *   @0x2ab2cc vabs.f64 d7, d17
 *   @0x2ab2d0 vcmpe.f64 d6, d6
 *   @0x2ab2d4 vsqrt.f64 d22, d7
 *   @0x2ab2d8 ldrle pc, [r1, #-0xa10]
 *   @0x2ab2dc movs r3, #0x0
 *   @0x2ab2e0 bge 0x2ab2f4 <png_init_read_transformations+0x17c>
 *   @0x2ab2e4 stclpl p2, c1, [r9], {76}
 *   @0x2ab2e8 subs r1, #0x1
 *   @0x2ab2ec cmp r1, #0xfd
 *   @0x2ab2f0 adds r3, #0x1
 *   @0x2ab2f4 ldr.w r3, [r4, #0x134]
 *   @0x2ab2f8 bic r3, r3, #0x2000
 *   @0x2ab2fc str.w r3, [r4, #0x134]
 *   @0x2ab300 ldr.w r2, [r4, #0x134]
 *   @0x2ab304 ldr r3, [pc, #0x358]
 *   @0x2ab308 cmp r3, #0x0
 *   @0x2ab30c ldcl p2, c8, [r4, #792]
 *   @0x2ab310 .word 0xeef57a88
 *   @0x2ab314 vneg.f32 s15, s0
 *   @0x2ab318 .word 0xf000fa10
 *   @0x2ab31c .word 0x462082be
 *   @0x2ab320 ldrb.w r1, [r4, #0x1eb]
 *   @0x2ab324 bl 0x2aaca0 <png_build_gamma_table>
 *   @0x2ab328 ldr.w r2, [r4, #0x134]
 *   @0x2ab32c ands r2, r2, #0x80
 *   @0x2ab330 beq.w 0x2ab846 <png_init_read_transformations+0x6ce>
 *   @0x2ab334 cmp.w r10, #0x3
 *   @0x2ab338 ldrb.w r3, [r4, #0x1f4]
 *   @0x2ab33c bne.w 0x2ab5f8 <png_init_read_transformations+0x480>
 *   @0x2ab340 ldrh.w r1, [r4, #0x1dc]
 *   @0x2ab344 cmp r3, #0x2
 *   @0x2ab348 rfeia r4!
 *   @0x2ab34c strdls r2, r3, [r1, -lr]
 *   @0x2ab350 bne 0x2ab376 <png_init_read_transformations+0x1fe>
 *   @0x2ab354 rfeia r4!
 *   @0x2ab358 rfeia r4!
 *   @0x2ab35c ldcpl p2, c1, [pc], {2}
 *   @0x2ab360 ldrb r6, [r3, r0]
 *   @0x2ab364 ldr.w r3, [r4, #0x230]
 *   @0x2ab368 ldrb.w r9, [r3, r2]
 *   @0x2ab36c ldrb.w r8, [r3, r0]
 *   @0x2ab370 ldrb.w r12, [r3, r1]
 *   @0x2ab374 b 0x2ab50c <png_init_read_transformations+0x394>
 *   @0x2ab378 vmov.f64 d7, #1.000000e+00
 *   @0x2ab37c beq 0x2ab3a0 <png_init_read_transformations+0x228>
 *   @0x2ab380 bne 0x2ab3ae <png_init_read_transformations+0x236>
 *   @0x2ab384 vldr s12, [r4, #504]
 *   @0x2ab388 vmul.f32 s20, s13, s18
 *   @0x2ab38c .word 0xeeb7aa8a
 *   @0x2ab390 vcvt.f64.f32 d11, s13
 *   @0x2ab394 .word 0xee87aaca
 *   @0x2ab398 vdiv.f64 d11, d7, d11
 *   @0x2ab39c and r10, r10, r10, lsl #22
 *   @0x2ab3a0 vldr s22, [r4, #548]
 *   @0x2ab3a4 vmov.f64 d10, d7
 *   @0x2ab3a8 vcvt.f64.f32 d11, s22
 *   @0x2ab3ac b 0x2ab3b6 <png_init_read_transformations+0x23e>
 *   @0x2ab3b0 vmov.f64 d10, d7
 *   @0x2ab3b4 vldr d11, [pc, #284]
 *   @0x2ab3b8 vldr d6, [pc, #664]
 *   @0x2ab3bc vadd.f64 d8, d26, d23
 *   @0x2ab3c0 vmov.f64 d7, d7
 *   @0x2ab3c4 vcmpe.f64 d7, d7
 *   @0x2ab3c8 .word 0xeeb67bc6
 *   @0x2ab3cc vmov.f64 d25, #4.000000e+00
 *   @0x2ab3d0 strle pc, [r6, #-0xa10]
 *   @0x2ab3d4 ldrb.w r7, [r4, #0x1fe]
 *   @0x2ab3d8 ldrb.w r6, [r4, #0x200]
 *   @0x2ab3dc ldrb.w r5, [r4, #0x202]
 *   @0x2ab3e0 b 0x2ab474 <png_init_read_transformations+0x2fc>
 *   @0x2ab3e4 vmov r2, r3, s0, s1
 *   @0x2ab3e8 .word 0xeeb82b1a
 *   @0x2ab3ec .word 0xee877b46
 *   @0x2ab3f0 .word 0xec516b08
 *   @0x2ab3f4 .word 0xf60b0b16
 *   @0x2ab3f8 cdp p9, #0xb, c14, c0, c6, #0x6
 *   @0x2ab3fc .word 0xec537b49
 *   @0x2ab400 vmov d10, r2, r1
 *   @0x2ab404 rfeia r4!
 *   @0x2ab408 cdp p2, #0x0, c1, c6, c0, #0x0
 *   @0x2ab40c vmov.f64 d23, #-1.875000e-01
 *   @0x2ab410 vmls.f64 d6, d23, d7
 *   @0x2ab414 .word 0xeeb81a10
 *   @0x2ab418 vnmla.f64 d7, d6, d7
 *   @0x2ab41c .word 0xee877a90
 *   @0x2ab420 rscslt r6, pc, #8, #22
 *   @0x2ab424 vmov r0, r1, d6
 *   @0x2ab428 blx 0xb6784 <pow@plt>
 *   @0x2ab42c vmov.f64 d7, d9
 *   @0x2ab430 vmov r2, r3, d10
 *   @0x2ab434 vmov d6, r0, r1
 *   @0x2ab438 ldrh.w r1, [r4, #0x202]
 *   @0x2ab43c vmla.f64 d7, d6, d8
 *   @0x2ab440 vcvt.u32.f64 s13, d7
 *   @0x2ab444 vmov s14, r1
 *   @0x2ab448 vcvt.f64.u32 d7, s14
 *   @0x2ab44c vmov r6, s13
 *   @0x2ab450 vdiv.f64 d6, d7, d8
 *   @0x2ab454 uxtb r6, r6
 *   @0x2ab458 .word 0xf60b0b16
 *   @0x2ab45c mrc p9, #0x5, lr, c0, c4, #0x4
 *   @0x2ab460 .word 0xec417b49
 *   @0x2ab464 .word 0xee060b16
 *   @0x2ab468 vmov.f64 d23, #-1.875000e-01
 *   @0x2ab46c vnmla.f64 d6, d22, d7
 *   @0x2ab470 rsclt r5, sp, #144, #20
 *   @0x2ab474 ldrh.w r1, [r4, #0x1fe]
 *   @0x2ab478 vmov r2, r3, d11
 *   @0x2ab47c vmov s14, r1
 *   @0x2ab480 vcvt.f64.u32 d7, s14
 *   @0x2ab484 vdiv.f64 d6, d7, d8
 *   @0x2ab488 vmov r0, r1, d6
 *   @0x2ab48c blx 0xb6784 <pow@plt>
 *   @0x2ab490 vmov.f64 d7, d9
 *   @0x2ab494 vmov r2, r3, d11
 *   @0x2ab498 vmov d6, r0, r1
 *   @0x2ab49c ldrh.w r1, [r4, #0x200]
 *   @0x2ab4a0 vmla.f64 d7, d6, d8
 *   @0x2ab4a4 vcvt.u32.f64 s13, d7
 *   @0x2ab4a8 vmov s14, r1
 *   @0x2ab4ac vcvt.f64.u32 d7, s14
 *   @0x2ab4b0 vmov r9, s13
 *   @0x2ab4b4 vdiv.f64 d6, d7, d8
 *   @0x2ab4b8 uxtb.w r9, r9
 *   @0x2ab4bc vmov r0, r1, d6
 *   @0x2ab4c0 blx 0xb6784 <pow@plt>
 *   @0x2ab4c4 vmov.f64 d7, d9
 *   @0x2ab4c8 vmov r2, r3, d11
 *   @0x2ab4cc vmov d6, r0, r1
 *   @0x2ab4d0 ldrh.w r1, [r4, #0x202]
 *   @0x2ab4d4 vmla.f64 d7, d6, d8
 *   @0x2ab4d8 vcvt.u32.f64 s13, d7
 *   @0x2ab4dc vmov s14, r1
 *   @0x2ab4e0 vcvt.f64.u32 d7, s14
 *   @0x2ab4e4 vmov r8, s13
 *   @0x2ab4e8 vdiv.f64 d6, d7, d8
 *   @0x2ab4ec uxtb.w r8, r8
 *   @0x2ab4f0 vmov r0, r1, d6
 *   @0x2ab4f4 blx 0xb6784 <pow@plt>
 *   @0x2ab4f8 vmov d7, r0, r1
 *   @0x2ab4fc vmla.f64 d9, d7, d8
 *   @0x2ab500 vcvt.u32.f64 s15, d9
 *   @0x2ab504 vmov r12, s15
 *   @0x2ab508 uxtb.w r12, r12
 *   @0x2ab50c add.w r3, r11, #0x1
 *   @0x2ab510 movs r2, #0x0
 *   @0x2ab514 cmp r2, r1
 *   @0x2ab518 ldrh.w r1, [r4, #0x1de]
 *   @0x2ab51c cmp r2, r1
 *   @0x2ab520 ldr.w r1, [r4, #0x24c]
 *   @0x2ab524 ldrb r1, [r1, r2]
 *   @0x2ab528 beq 0x2ab5c6 <png_init_read_transformations+0x44e>
 *   @0x2ab52c strb r7, [r3, #-1]
 *   @0x2ab530 strb r6, [r3]
 *   @0x2ab534 b 0x2ab5e8 <png_init_read_transformations+0x470>
 *   @0x2ab538 .word 0xf8130230
 *   @0x2ab53c .word 0xf810bc01
 *   @0x2ab540 .word 0xf1c1b00b
 *   @0x2ab544 blx 0x2ab94a <png_init_read_transformations+0x7d2>
 *   @0x2ab548 blx 0x5a7576 <g_SWFlineaavertbuff+0x544ae>
 *   @0x2ab54c .word 0xf8d40101
 *   @0x2ab550 .word 0xf893022c
 *   @0x2ab554 orrlo r11, r0, r0
 *   @0x2ab558 uxth r1, r1
 *   @0x2ab55c vorr.i32 d18, #0x91
 *   @0x2ab560 mcrrpl p1, #0x0, r2, r1, c7
 *   @0x2ab564 strb r1, [r3, #-1]
 *   @0x2ab568 ldr.w r1, [r4, #0x24c]
 *   @0x2ab56c ldrb r0, [r1, r2]
 *   @0x2ab570 .word 0xf8111230
 *   @0x2ab574 .word 0xf1c0b00b
 *   @0x2ab578 blx 0x2ebd7e <FT_Done_Memory+0x210a>
 *   @0x2ab57c blx 0x5a79a6 <g_SWFlineaavertbuff+0x548de>
 *   @0x2ab580 .word 0xf8d41100
 *   @0x2ab584 .word 0xf893022c
 *   @0x2ab588 orrlo r11, r0, r1
 *   @0x2ab58c uxth r1, r1
 *   @0x2ab590 vorr.i32 d18, #0x91
 *   @0x2ab594 mcrrpl p1, #0x0, r2, r1, c7
 *   @0x2ab598 strb r1, [r3]
 *   @0x2ab59c stcpl p2, c1, [r8], {76}
 *   @0x2ab5a0 ldr.w r1, [r4, #0x230]
 *   @0x2ab5a4 ldrb.w r11, [r1, r11]
 *   @0x2ab5a8 rsb.w r1, r0, #0xff
 *   @0x2ab5ac mul r1, r1, r12
 *   @0x2ab5b0 mla r1, r11, r0, r1
 *   @0x2ab5b4 ldr.w r0, [r4, #0x22c]
 *   @0x2ab5b8 adds r1, #0x80
 *   @0x2ab5bc add.w r1, r1, r1, lsr #8
 *   @0x2ab5c0 ubfx r1, r1, #0x8, #0x8
 *   @0x2ab5c4 b 0x2ab5e4 <png_init_read_transformations+0x46c>
 *   @0x2ab5c8 .word 0xf8d40c01
 *   @0x2ab5cc .word 0x5c091228
 *   @0x2ab5d0 ldrb r0, [r3]
 *   @0x2ab5d4 .word 0xf8d41c01
 *   @0x2ab5d8 .word 0x5c091228
 *   @0x2ab5dc ldrb r0, [r3, #0x1]
 *   @0x2ab5e0 ldr.w r1, [r4, #0x228]
 *   @0x2ab5e4 ldrb r1, [r1, r0]
 *   @0x2ab5e8 adds r2, #0x1
 *   @0x2ab5ec b 0x2ab512 <png_init_read_transformations+0x39a>
 *   @0x2ab5f0 vld4.8 {d3, d5, d7, d9}, [r3:256], r4
 *   @0x2ab5f4 .word 0xe1a75302
 *   @0x2ab5f8 ldrb.w r2, [r4, #0x1eb]
 *   @0x2ab5fc movs r1, #0x1
 *   @0x2ab600 vmov.f64 d9, #1.000000e+00
 *   @0x2ab604 lsl.w r2, r1, r2
 *   @0x2ab608 add.w r2, r2, #0xffffffff
 *   @0x2ab60c vmov s12, r2
 *   @0x2ab610 vcvt.f64.u32 d8, s12
 *   @0x2ab614 beq 0x2ab628 <png_init_read_transformations+0x4b0>
 *   @0x2ab618 beq 0x2ab62e <png_init_read_transformations+0x4b6>
 *   @0x2ab61c bne 0x2ab664 <png_init_read_transformations+0x4ec>
 *   @0x2ab620 .word 0xeeb7aa89
 *   @0x2ab624 eor r10, r4, r10, asr #21
 *   @0x2ab628 vldr s15, [r4, #544]
 *   @0x2ab62c b 0x2ab632 <png_init_read_transformations+0x4ba>
 *   @0x2ab630 vldr s14, [r4, #504]
 *   @0x2ab634 vmul.f32 s14, s15, s18
 *   @0x2ab638 .word 0xeeb77a87
 *   @0x2ab63c vcvt.f64.f32 d10, s15
 *   @0x2ab640 .word 0xee897ac7
 *   @0x2ab644 vdiv.f64 d10, d9, d10
 *   @0x2ab648 ands r9, r2, r7, lsl #22
 *   @0x2ab64c nop.w
 *   @0x2ab650 ldr r1, [sp, #0x268]
 *   @0x2ab654 ldr r1, [sp, #0x264]
 *   @0x2ab658 movs r0, r0
 *   @0x2ab65c b 0x2ab660 <png_init_read_transformations+0x4e8>
 *   @0x2ab660 movs r0, #0x0
 *   @0x2ab664 ldr r1, [pc, #0x388]
 *   @0x2ab668 vmov.f64 d10, d9
 *   @0x2ab66c add r1, pc
 *   @0x2ab670 rfeia r4!
 *   @0x2ab674 cdp p2, #0xb, c1, c6, c4, #0x0
 *   @0x2ab678 .word 0xec53bb00
 *   @0x2ab67c .word 0xee072b1a
 *   @0x2ab680 .word 0xeeb81a10
 *   @0x2ab684 .word 0xee877b47
 *   @0x2ab688 .word 0xec516b08
 *   @0x2ab68c .word 0xf60b0b16
 *   @0x2ab690 mrc p8, #0x5, lr, c0, c10, #0x3
 *   @0x2ab694 .word 0xec417b4b
 *   @0x2ab698 rfeia r4!
 *   @0x2ab69c cdp p2, #0x0, c1, c6, c4, #0x0
 *   @0x2ab6a0 vmov.f64 d23, #-1.875000e-01
 *   @0x2ab6a4 vmls.f64 d6, d23, d7
 *   @0x2ab6a8 .word 0xeeb81a10
 *   @0x2ab6ac vnmla.f64 d7, d6, d7
 *   @0x2ab6b0 .word 0xee873a90
 *   @0x2ab6b4 .word 0xf8a46b08
 *   @0x2ab6b8 mrrc p2, #0x0, r3, r3, c14
 *   @0x2ab6bc vmov r2, r1, d9
 *   @0x2ab6c0 .word 0xf60b0b16
 *   @0x2ab6c4 cdp p8, #0xb, c14, c0, c0, #0x3
 *   @0x2ab6c8 .word 0xec417b4b
 *   @0x2ab6cc rfeia r4!
 *   @0x2ab6d0 rfeia r4!
 *   @0x2ab6d4 cdp p2, #0x0, c1, c6, c0, #0x0
 *   @0x2ab6d8 addmi r7, r1, #8, #22
 *   @0x2ab6dc vcvt.u32.f64 s13, d7
 *   @0x2ab6e0 vmov r2, s13
 *   @0x2ab6e4 uxth r2, r2
 *   @0x2ab6e8 .word 0xd1062204
 *   @0x2ab6ec ldrh.w r3, [r4, #0x202]
 *   @0x2ab6f0 cmp r3, r1
 *   @0x2ab6f4 cmp r3, r2
 *   @0x2ab6f8 mcr p0, #0x0, r8, c6, c9, #0x4
 *   @0x2ab6fc vmov r0, r3, s0, s1
 *   @0x2ab700 .word 0xeeb82b1a
 *   @0x2ab704 .word 0xee877b46
 *   @0x2ab708 .word 0xec516b08
 *   @0x2ab70c .word 0xf60b0b16
 *   @0x2ab710 mrc p8, #0x5, lr, c0, c10, #0x1
 *   @0x2ab714 .word 0xec417b4b
 *   @0x2ab718 rfeia r4!
 *   @0x2ab71c cdp p2, #0x0, c1, c6, c0, #0x0
 *   @0x2ab720 vmov.f64 d23, #-1.875000e-01
 *   @0x2ab724 vmls.f64 d6, d23, d7
 *   @0x2ab728 .word 0xeeb81a10
 *   @0x2ab72c vnmla.f64 d7, d6, d7
 *   @0x2ab730 .word 0xee873a90
 *   @0x2ab734 .word 0xf8a46b08
 *   @0x2ab738 mrrc p2, #0x0, r3, r3, c8
 *   @0x2ab73c vmov r2, r1, d10
 *   @0x2ab740 .word 0xf60b0b16
 *   @0x2ab744 cdp p8, #0xb, c14, c0, c0, #0x1
 *   @0x2ab748 .word 0xec417b4b
 *   @0x2ab74c rfeia r4!
 *   @0x2ab750 cdp p2, #0x0, c1, c6, c2, #0x0
 *   @0x2ab754 vmov.f64 d23, #-1.875000e-01
 *   @0x2ab758 vmls.f64 d6, d23, d7
 *   @0x2ab75c .word 0xeeb81a10
 *   @0x2ab760 vnmla.f64 d7, d6, d7
 *   @0x2ab764 .word 0xee873a90
 *   @0x2ab768 .word 0xf8a46b08
 *   @0x2ab76c mrrc p2, #0x0, r3, r3, c10
 *   @0x2ab770 vmov r2, r1, d10
 *   @0x2ab774 .word 0xf60b0b16
 *   @0x2ab778 cdp p8, #0xb, c14, c0, c6, #0x0
 *   @0x2ab77c .word 0xec417b4b
 *   @0x2ab780 rfeia r4!
 *   @0x2ab784 mcr p1, #0x0, r1, c6, c14, #0x7
 *   @0x2ab788 vmov.f64 d23, #-1.875000e-01
 *   @0x2ab78c vmls.f64 d6, d23, d7
 *   @0x2ab790 .word 0xeeb81a10
 *   @0x2ab794 vnmla.f64 d7, d6, d7
 *   @0x2ab798 .word 0xee873a90
 *   @0x2ab79c .word 0xf8a46b08
 *   @0x2ab7a0 mrrc p2, #0x0, r3, r3, c12
 *   @0x2ab7a4 vmov r2, r1, d9
 *   @0x2ab7a8 .word 0xf60a0b16
 *   @0x2ab7ac cdp p15, #0xb, c14, c0, c12, #0x7
 *   @0x2ab7b0 .word 0xec417b4b
 *   @0x2ab7b4 rfeia r4!
 *   @0x2ab7b8 cdp p2, #0x0, c1, c6, c0, #0x0
 *   @0x2ab7bc vmov.f64 d23, #-1.875000e-01
 *   @0x2ab7c0 vmls.f64 d6, d23, d7
 *   @0x2ab7c4 .word 0xeeb81a10
 *   @0x2ab7c8 vnmla.f64 d7, d6, d7
 *   @0x2ab7cc .word 0xee873a90
 *   @0x2ab7d0 .word 0xf8a46b08
 *   @0x2ab7d4 mrrc p1, #0xf, r3, r3, c14
 *   @0x2ab7d8 vmov r2, r1, d9
 *   @0x2ab7dc .word 0xf60a0b16
 *   @0x2ab7e0 mrc p15, #0x5, lr, c0, c2, #0x6
 *   @0x2ab7e4 .word 0xec417b4b
 *   @0x2ab7e8 rfeia r4!
 *   @0x2ab7ec cdp p2, #0x0, c1, c6, c2, #0x0
 *   @0x2ab7f0 vmov.f64 d23, #-1.875000e-01
 *   @0x2ab7f4 vmls.f64 d6, d23, d7
 *   @0x2ab7f8 .word 0xeeb81a10
 *   @0x2ab7fc vnmla.f64 d7, d6, d7
 *   @0x2ab800 .word 0xee873a90
 *   @0x2ab804 .word 0xf8a46b08
 *   @0x2ab808 mrrc p2, #0x0, r3, r3, c0
 *   @0x2ab80c vmov r2, r1, d9
 *   @0x2ab810 .word 0xf60a0b16
 *   @0x2ab814 mcrr p15, #0xb, lr, r1, c8
 *   @0x2ab818 .word 0xee070b17
 *   @0x2ab81c vmov.f64 d27, #-1.875000e-01
 *   @0x2ab820 vnmla.f64 d7, d23, d11
 *   @0x2ab824 .word 0xf8a43a90
 *   @0x2ab828 adds r3, r5, r2, lsl #4
 *   @0x2ab82c ldrh.w r2, [r4, #0x20e]
 *   @0x2ab830 strh.w r3, [r4, #0x202]
 *   @0x2ab834 strh.w r3, [r4, #0x200]
 *   @0x2ab838 strh.w r2, [r4, #0x20c]
 *   @0x2ab83c strh.w r2, [r4, #0x20a]
 *   @0x2ab840 strh.w r2, [r4, #0x208]
 *   @0x2ab844 b 0x2ab958 <png_init_read_transformations+0x7e0>
 *   @0x2ab848 .word 0xf0400f03
 *   @0x2ab84c rfeia r4!
 *   @0x2ab850 .word 0xf8d401dc
 *   @0x2ab854 addmi r3, r2, #216, #2
 *   @0x2ab858 add.w r3, r3, #0x3
 *   @0x2ab85c bge 0x2ab88c <png_init_read_transformations+0x714>
 *   @0x2ab860 andlo r1, r1, #40, #4
 *   @0x2ab864 ldrb r5, [r3, #-3]
 *   @0x2ab868 ldrb r1, [r1, r5]
 *   @0x2ab86c .word 0xf8035c02
 *   @0x2ab870 .word 0xf8d41c03
 *   @0x2ab874 stclpl p2, c1, [r9, #-160]
 *   @0x2ab878 ldrb r5, [r3, #-1]
 *   @0x2ab87c strb r1, [r3, #-2]
 *   @0x2ab880 ldr.w r1, [r4, #0x228]
 *   @0x2ab884 ldrb r1, [r1, r5]
 *   @0x2ab888 strb r1, [r4, r1, lsl #24]!
 *   @0x2ab88c ldr.w r3, [r4, #0x134]
 *   @0x2ab890 bic r3, r3, #0x2000
 *   @0x2ab894 str.w r3, [r4, #0x134]
 *   @0x2ab898 b 0x2ab958 <png_init_read_transformations+0x7e0>
 *   @0x2ab89c bpl 0x2ab958 <png_init_read_transformations+0x7e0>
 *   @0x2ab8a0 cmple r9, r3, lsl #30
 *   @0x2ab8a4 ldrb.w r1, [r4, #0x1fe]
 *   @0x2ab8a8 movs r2, #0x0
 *   @0x2ab8ac .word 0xf8940200
 *   @0x2ab8b0 rfeia r4!
 *   @0x2ab8b4 pkhtbmi r7, r12, lr, asr #3
 *   @0x2ab8b8 ldr.w r3, [r4, #0x1d8]
 *   @0x2ab8bc mov r8, r0
 *   @0x2ab8c0 cmp r2, r7
 *   @0x2ab8c4 ldr.w r6, [r4, #0x24c]
 *   @0x2ab8c8 ldrb r6, [r6, r2]
 *   @0x2ab8cc strb r1, [r3]
 *   @0x2ab8d0 strb r5, [r3, #0x2]
 *   @0x2ab8d4 cmp r6, #0xff
 *   @0x2ab8d8 ldrb.w r11, [r3]
 *   @0x2ab8dc mul r11, r11, r6
 *   @0x2ab8e0 rsb.w r6, r6, #0xff
 *   @0x2ab8e4 add.w r11, r11, #0x80
 *   @0x2ab8e8 mla r6, r6, r12, r11
 *   @0x2ab8ec uxth r6, r6
 *   @0x2ab8f0 eorsne r2, r6, #23068672
 *   @0x2ab8f4 strb r6, [r3]
 *   @0x2ab8f8 .word 0xf816624c
 *   @0x2ab8fc ldmdavc lr, {r1, r12, sp, pc} ^
 *   @0x2ab900 mul r6, r6, r11
 *   @0x2ab904 rsb.w r11, r11, #0xff
 *   @0x2ab908 adds r6, #0x80
 *   @0x2ab90c adcslt r6, r6, #8, #12
 *   @0x2ab910 add.w r6, r6, r6, lsr #8
 *   @0x2ab914 asrs r6, r6, #0x8
 *   @0x2ab918 ldr.w r6, [r4, #0x24c]
 *   @0x2ab91c ldrb.w r11, [r6, r2]
 *   @0x2ab920 ldrb r6, [r3, #0x2]
 *   @0x2ab924 .word 0xf1cbf60b
 *   @0x2ab928 .word 0x36800bff
 *   @0x2ab92c mla r6, r11, r9, r6
 *   @0x2ab930 uxth r6, r6
 *   @0x2ab934 eorsne r2, r6, #23068672
 *   @0x2ab938 strb r6, [r3, #0x2]
 *   @0x2ab93c adds r3, #0x3
 *   @0x2ab940 ldr.w r3, [r4, #0x134]
 *   @0x2ab944 bic r3, r3, #0x80
 *   @0x2ab948 str.w r3, [r4, #0x134]
 *   @0x2ab94c ldr.w r3, [r4, #0x130]
 *   @0x2ab950 orr r3, r3, #0x400000
 *   @0x2ab954 str.w r3, [r4, #0x130]
 *   @0x2ab958 ldr.w r2, [r4, #0x134]
 *   @0x2ab95c movw r3, #0x1008
 *   @0x2ab960 ands r3, r2
 *   @0x2ab964 bne 0x2ab9e4 <png_init_read_transformations+0x86c>
 *   @0x2ab968 teqle r11, r3, lsl #30
 *   @0x2ab96c ldrb.w r2, [r4, #0x240]
 *   @0x2ab970 movs r3, #0x0
 *   @0x2ab974 .word 0xf8941241
 *   @0x2ab978 .word 0xf1c20242
 *   @0x2ab97c .word 0xf1c10208
 *   @0x2ab980 rfeia r4!
 *   @0x2ab984 .word 0xf1c071dc
 *   @0x2ab988 bhs 0x4ab9b0 <SrcVerts+0x89f4>
 *   @0x2ab98c it hi
 *   @0x2ab990 cmp r1, #0x8
 *   @0x2ab994 movhi r1, #0x0
 *   @0x2ab998 it hi
 *   @0x2ab99c uxth r5, r3
 *   @0x2ab9a0 bhs 0x2ab9d8 <png_init_read_transformations+0x860>
 *   @0x2ab9a4 .word 0xf8d4f503
 *   @0x2ab9a8 movwlo r6, #0x11d8
 *   @0x2ab9ac ldrb.w r12, [r6, r5]
 *   @0x2ab9b0 asr.w r12, r12, r2
 *   @0x2ab9b4 strb.w r12, [r6, r5]
 *   @0x2ab9b8 ldr.w r6, [r4, #0x1d8]
 *   @0x2ab9bc add r6, r5
 *   @0x2ab9c0 blx 0x15db9cc <b2_toiTime+0xe82528>
 *   @0x2ab9c4 .word 0xf886fc01
 *   @0x2ab9c8 .word 0xf8d4c001
 *   @0x2ab9cc ldrtmi r6, [r5], #-472
 *   @0x2ab9d0 ldrb r6, [r5, #0x2]
 *   @0x2ab9d4 strb r6, [r5, #0x2]
 *   @0x2ab9d8 ldr.w r3, [r4, #0x134]
 *   @0x2ab9dc bic r3, r3, #0x8
 *   @0x2ab9e0 str.w r3, [r4, #0x134]
 *   @0x2ab9e4 add sp, #0xc
 *   @0x2ab9e8 pop {r3, r8, r9, r11, pc}
 *   @0x2ab9ec svclt #0x8ff0
 *   @0x2ab9f0 asrs r0, r5, #0x11
 *
 * ══ §5/16 ov_pcm_seek_page  0x231ed4  size 2080  520 条（0x231ed4..0x2326f4）
 * @func 0x231ed4 0x2326f4  size 2080  520 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_22fd0c+0x2d4×7 / anon_22fd0c×4 / ov_pcm_total×2 / ogg_page_serialno×2 / vorbis_dsp_clear×2 / vorbis_block_clear×2 / ogg_page_granulepos×2 / ov_pcm_seek_page+0x27c×2
 * 字段偏移 top8: 0x34×9 / 0x48×8 / 0x4c×8 / 0x10×7 / 0x58×4 / 0x60×3 / 0x5c×3 / 0x44×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231ed4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x231ed8 sub sp, sp, #156
 *   @0x231edc mvn r1, #0
 *   @0x231ee0 mov r8, r0
 *   @0x231ee4 strd r2, r3, [sp, #40]
 *   @0x231ee8 bl 0x23138c <ov_pcm_total>
 *   @0x231eec ldr r3, [r8, #0x58]
 *   @0x231ef0 cmp r3, #1
 *   @0x231ef4 strd r0, r1, [sp, #32]
 *   @0x231ef8 ble 0x232314 <ov_pcm_seek_page+0x440>
 *   @0x231efc ldr r3, [r8, #0x4]
 *   @0x231f00 cmp r3, #0
 *   @0x231f04 beq 0x232538 <ov_pcm_seek_page+0x664>
 *   @0x231f08 ldrd r4, r5, [sp, #40]
 *   @0x231f0c ldr r6, [sp, #0x2c]
 *   @0x231f10 cmp r0, r4
 *   @0x231f14 sbcs r5, r1, r5
 *   @0x231f18 movge r3, #0
 *   @0x231f1c movlt r3, #1
 *   @0x231f20 orrs r3, r3, r6, lsr #31
 *   @0x231f24 bne 0x232314 <ov_pcm_seek_page+0x440>
 *   @0x231f28 ldr r3, [r8, #0x34]
 *   @0x231f2c subs r3, r3, #1
 *   @0x231f30 str r3, [sp, #0x34]
 *   @0x231f34 ldr r3, [r8, #0x44]
 *   @0x231f38 bmi 0x232524 <ov_pcm_seek_page+0x650>
 *   @0x231f3c ldr r10, [sp, #0x34]
 *   @0x231f40 ldrd r4, r5, [sp, #32]
 *   @0x231f44 ldrd r6, r7, [sp, #40]
 *   @0x231f48 lsl r2, r10, #4
 *   @0x231f4c add r1, r3, r2
 *   @0x231f50 ldrd r0, r1, [r1, #8]
 *   @0x231f54 subs r4, r4, r0
 *   @0x231f58 sbc r5, r5, r1
 *   @0x231f5c strd r4, r5, [sp, #32]
 *   @0x231f60 cmp r6, r4
 *   @0x231f64 sbcs r7, r7, r5
 *   @0x231f68 bge 0x231fc8 <ov_pcm_seek_page+0xf4>
 *   @0x231f6c add r2, r2, #16
 *   @0x231f70 movw r12, #0xffe0
 *   @0x231f74 movt r12, #0xffff
 *   @0x231f78 add r2, r3, r2
 *   @0x231f7c rsb r12, r3, r12
 *   @0x231f80 mov r9, r10
 *   @0x231f84 ldrd r6, r7, [sp, #40]
 *   @0x231f88 b 0x231fa8 <ov_pcm_seek_page+0xd4>
 *   @0x231f8c ldrd r0, r1, [r2, #-24]
 *   @0x231f90 sub r2, r2, #16
 *   @0x231f94 subs r4, r4, r0
 *   @0x231f98 sbc r5, r5, r1
 *   @0x231f9c cmp r6, r4
 *   @0x231fa0 sbcs r10, r7, r5
 *   @0x231fa4 bge 0x232304 <ov_pcm_seek_page+0x430>
 *   @0x231fa8 sub r9, r9, #1
 *   @0x231fac add lr, r12, r2
 *   @0x231fb0 cmn r9, #1
 *   @0x231fb4 bne 0x231f8c <ov_pcm_seek_page+0xb8>
 *   @0x231fb8 ldrd r0, r1, [r3, #-8]
 *   @0x231fbc mvn r2, #15
 *   @0x231fc0 str r9, [sp, #0x34]
 *   @0x231fc4 strd r4, r5, [sp, #32]
 *   @0x231fc8 ldr r12, [sp, #0x34]
 *   @0x231fcc ldrd r4, r5, [r3, r2]
 *   @0x231fd0 add lr, r12, #1
 *   @0x231fd4 ldrd r6, r7, [sp, #32]
 *   @0x231fd8 ldr r12, [r8, #0x38]
 *   @0x231fdc ldrd r2, r3, [sp, #40]
 *   @0x231fe0 lsl lr, lr, #3
 *   @0x231fe4 strd r4, r5, [sp, #56]
 *   @0x231fe8 subs r2, r2, r6
 *   @0x231fec sbc r3, r3, r7
 *   @0x231ff0 adds r4, r4, r0
 *   @0x231ff4 adc r5, r5, r1
 *   @0x231ff8 ldrd r6, r7, [r12, lr]!
 *   @0x231ffc strd r4, r5, [sp, #80]
 *   @0x232000 ldrd r4, r5, [sp, #56]
 *   @0x232004 adds r4, r4, r2
 *   @0x232008 adc r5, r5, r3
 *   @0x23200c strd r4, r5, [sp, #64]
 *   @0x232010 ldrd r4, r5, [r12, #-8]
 *   @0x232014 strd r4, r5, [sp, #16]
 *   @0x232018 cmp r4, r6
 *   @0x23201c sbcs r5, r5, r7
 *   @0x232020 bge 0x23254c <ov_pcm_seek_page+0x678>
 *   @0x232024 ldr r10, [sp, #0x34]
 *   @0x232028 add r9, sp, #88
 *   @0x23202c ldr r12, [sp, #0x10]
 *   @0x232030 ldr r4, [sp, #0x14]
 *   @0x232034 lsl r10, r10, #2
 *   @0x232038 str r10, [sp, #0x18]
 *   @0x23203c str r12, [sp, #0x48]
 *   @0x232040 str r4, [sp, #0x4c]
 *   @0x232044 ldrd r2, r3, [sp, #16]
 *   @0x232048 movw r0, #0x7fff
 *   @0x23204c mov r1, #0
 *   @0x232050 subs r2, r6, r2
 *   @0x232054 sbc r3, r7, r3
 *   @0x232058 cmp r0, r2
 *   @0x23205c sbcs r1, r1, r3
 *   @0x232060 blt 0x2322a8 <ov_pcm_seek_page+0x3d4>
 *   @0x232064 ldrd r4, r5, [sp, #16]
 *   @0x232068 ldrd r2, r3, [r8, #8]
 *   @0x23206c cmp r3, r5
 *   @0x232070 cmpeq r2, r4
 *   @0x232074 moveq r2, r4
 *   @0x232078 moveq r3, r5
 *   @0x23207c beq 0x2320d0 <ov_pcm_seek_page+0x1fc>
 *   @0x232080 mov r0, r8
 *   @0x232084 mov r2, r4
 *   @0x232088 mov r3, r5
 *   @0x23208c bl 0x22ffe0 <vorbis_packet_blocksize+0x364>
 *   @0x232090 asr r1, r0, #31
 *   @0x232094 orrs r12, r0, r1
 *   @0x232098 beq 0x2320cc <ov_pcm_seek_page+0x1f8>
 *   @0x23209c b 0x2321c0 <ov_pcm_seek_page+0x2ec>
 *   @0x2320a0 mov r0, r9
 *   @0x2320a4 bl 0x23409c <ogg_page_serialno>
 *   @0x2320a8 ldr r3, [r8, #0x40]
 *   @0x2320ac ldr r12, [sp, #0x18]
 *   @0x2320b0 ldr r3, [r3, r12]
 *   @0x2320b4 cmp r0, r3
 *   @0x2320b8 beq 0x2321d0 <ov_pcm_seek_page+0x2fc>
 *   @0x2320bc ldrd r0, r1, [sp, #16]
 *   @0x2320c0 cmp r0, r6
 *   @0x2320c4 sbcs r1, r1, r7
 *   @0x2320c8 bge 0x232124 <ov_pcm_seek_page+0x250>
 *   @0x2320cc ldrd r2, r3, [r8, #8]
 *   @0x2320d0 subs r2, r6, r2
 *   @0x2320d4 sbc r3, r7, r3
 *   @0x2320d8 mov r0, r8
 *   @0x2320dc mov r1, r9
 *   @0x2320e0 bl 0x22fd0c <vorbis_packet_blocksize+0x90>
 *   @0x2320e4 mov r10, r0
 *   @0x2320e8 mov r11, r1
 *   @0x2320ec mvn r0, #127
 *   @0x2320f0 mvn r1, #0
 *   @0x2320f4 cmp r11, r1
 *   @0x2320f8 cmpeq r10, r0
 *   @0x2320fc beq 0x2322a0 <ov_pcm_seek_page+0x3cc>
 *   @0x232100 cmp r10, #0
 *   @0x232104 sbcs r1, r11, #0
 *   @0x232108 bge 0x2320a0 <ov_pcm_seek_page+0x1cc>
 *   @0x23210c ldrd r2, r3, [sp, #16]
 *   @0x232110 adds r2, r2, #1
 *   @0x232114 adc r3, r3, #0
 *   @0x232118 cmp r2, r4
 *   @0x23211c sbcs r12, r3, r5
 *   @0x232120 blt 0x232180 <ov_pcm_seek_page+0x2ac>
 *   @0x232124 ldr r2, [sp, #0x48]
 *   @0x232128 mov r0, r8
 *   @0x23212c ldr r3, [sp, #0x4c]
 *   @0x232130 bl 0x22ffe0 <vorbis_packet_blocksize+0x364>
 *   @0x232134 mvn r2, #0
 *   @0x232138 mvn r3, #0
 *   @0x23213c strd r2, r3, [r8, #80]
 *   @0x232140 subs r10, r0, #0
 *   @0x232144 beq 0x23231c <ov_pcm_seek_page+0x448>
 *   @0x232148 add r6, r8, #480
 *   @0x23214c str r6, [sp, #0x10]
 *   @0x232150 mvn r3, #0
 *   @0x232154 mvn r2, #0
 *   @0x232158 ldr r0, [sp, #0x10]
 *   @0x23215c strd r2, r3, [r8, #80]
 *   @0x232160 bl 0x2272ac <vorbis_dsp_clear>
 *   @0x232164 add r0, r8, #560
 *   @0x232168 bl 0x227208 <vorbis_block_clear>
 *   @0x23216c mov r3, #2
 *   @0x232170 str r3, [r8, #0x58]
 *   @0x232174 mov r0, r10
 *   @0x232178 add sp, sp, #156
 *   @0x23217c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x232180 orrs r0, r4, r5
 *   @0x232184 beq 0x2321c4 <ov_pcm_seek_page+0x2f0>
 *   @0x232188 subs r4, r4, #32768
 *   @0x23218c ldrd r0, r1, [sp, #16]
 *   @0x232190 sbc r5, r5, #0
 *   @0x232194 cmp r0, r4
 *   @0x232198 sbcs r1, r1, r5
 *   @0x23219c mov r0, r8
 *   @0x2321a0 movge r4, r2
 *   @0x2321a4 movge r5, r3
 *   @0x2321a8 mov r2, r4
 *   @0x2321ac mov r3, r5
 *   @0x2321b0 bl 0x22ffe0 <vorbis_packet_blocksize+0x364>
 *   @0x2321b4 asr r1, r0, #31
 *   @0x2321b8 orrs r2, r0, r1
 *   @0x2321bc beq 0x2320bc <ov_pcm_seek_page+0x1e8>
 *   @0x2321c0 mov r10, r0
 *   @0x2321c4 add r4, r8, #480
 *   @0x2321c8 str r4, [sp, #0x10]
 *   @0x2321cc b 0x232150 <ov_pcm_seek_page+0x27c>
 *   @0x2321d0 mov r0, r9
 *   @0x2321d4 bl 0x233fb0 <ogg_page_granulepos>
 *   @0x2321d8 mvn r2, #0
 *   @0x2321dc mvn r3, #0
 *   @0x2321e0 cmp r1, r3
 *   @0x2321e4 cmpeq r0, r2
 *   @0x2321e8 beq 0x2320bc <ov_pcm_seek_page+0x1e8>
 *   @0x2321ec ldrd r2, r3, [sp, #64]
 *   @0x2321f0 cmp r0, r2
 *   @0x2321f4 sbcs r3, r1, r3
 *   @0x2321f8 bge 0x232234 <ov_pcm_seek_page+0x360>
 *   @0x2321fc ldrd r2, r3, [sp, #64]
 *   @0x232200 movw r4, #0xac44
 *   @0x232204 mov r5, #0
 *   @0x232208 subs r2, r2, r0
 *   @0x23220c sbc r3, r3, r1
 *   @0x232210 cmp r4, r2
 *   @0x232214 sbcs r5, r5, r3
 *   @0x232218 ldrd r4, r5, [r8, #8]
 *   @0x23221c blt 0x23257c <ov_pcm_seek_page+0x6a8>
 *   @0x232220 strd r0, r1, [sp, #56]
 *   @0x232224 str r10, [sp, #0x48]
 *   @0x232228 str r11, [sp, #0x4c]
 *   @0x23222c strd r4, r5, [sp, #16]
 *   @0x232230 b 0x2320bc <ov_pcm_seek_page+0x1e8>
 *   @0x232234 ldrd r2, r3, [sp, #16]
 *   @0x232238 adds r2, r2, #1
 *   @0x23223c adc r3, r3, #0
 *   @0x232240 strd r2, r3, [sp, #8]
 *   @0x232244 cmp r2, r4
 *   @0x232248 sbcs r3, r3, r5
 *   @0x23224c bge 0x232124 <ov_pcm_seek_page+0x250>
 *   @0x232250 ldrd r2, r3, [r8, #8]
 *   @0x232254 cmp r3, r7
 *   @0x232258 cmpeq r2, r6
 *   @0x23225c bne 0x232560 <ov_pcm_seek_page+0x68c>
 *   @0x232260 subs r4, r4, #32768
 *   @0x232264 ldrd r6, r7, [sp, #16]
 *   @0x232268 sbc r5, r5, #0
 *   @0x23226c mov r0, r8
 *   @0x232270 cmp r6, r4
 *   @0x232274 sbcs r7, r7, r5
 *   @0x232278 ldrdge r4, r5, [sp, #8]
 *   @0x23227c mov r2, r4
 *   @0x232280 mov r3, r5
 *   @0x232284 bl 0x22ffe0 <vorbis_packet_blocksize+0x364>
 *   @0x232288 asr r1, r0, #31
 *   @0x23228c orrs r12, r0, r1
 *   @0x232290 bne 0x2321c0 <ov_pcm_seek_page+0x2ec>
 *   @0x232294 mov r6, r10
 *   @0x232298 mov r7, r11
 *   @0x23229c b 0x2320bc <ov_pcm_seek_page+0x1e8>
 *   @0x2322a0 mvn r10, #127
 *   @0x2322a4 b 0x232148 <ov_pcm_seek_page+0x274>
 *   @0x2322a8 ldrd r4, r5, [sp, #56]
 *   @0x2322ac strd r2, r3, [sp]
 *   @0x2322b0 ldrd r0, r1, [sp, #64]
 *   @0x2322b4 ldrd r2, r3, [sp, #80]
 *   @0x2322b8 subs r0, r0, r4
 *   @0x2322bc sbc r1, r1, r5
 *   @0x2322c0 subs r2, r2, r4
 *   @0x2322c4 sbc r3, r3, r5
 *   @0x2322c8 movw r4, #0x7fff
 *   @0x2322cc bl 0x231dfc <rescale64>
 *   @0x2322d0 ldrd r2, r3, [sp, #16]
 *   @0x2322d4 mov r5, #0
 *   @0x2322d8 adds r2, r2, r4
 *   @0x2322dc adc r3, r3, r5
 *   @0x2322e0 ldrd r4, r5, [sp, #16]
 *   @0x2322e4 adds r0, r0, r4
 *   @0x2322e8 adc r1, r1, r5
 *   @0x2322ec subs r4, r0, #32768
 *   @0x2322f0 sbc r5, r1, #0
 *   @0x2322f4 cmp r2, r4
 *   @0x2322f8 sbcs r10, r3, r5
 *   @0x2322fc bge 0x232064 <ov_pcm_seek_page+0x190>
 *   @0x232300 b 0x232068 <ov_pcm_seek_page+0x194>
 *   @0x232304 str r9, [sp, #0x34]
 *   @0x232308 mov r2, lr
 *   @0x23230c strd r4, r5, [sp, #32]
 *   @0x232310 b 0x231fc8 <ov_pcm_seek_page+0xf4>
 *   @0x232314 mvn r10, #130
 *   @0x232318 b 0x232174 <ov_pcm_seek_page+0x2a0>
 *   @0x23231c add r5, sp, #104
 *   @0x232320 mov r0, r8
 *   @0x232324 mov r1, r5
 *   @0x232328 bl 0x22fd0c <vorbis_packet_blocksize+0x90>
 *   @0x23232c cmp r0, #0
 *   @0x232330 sbcs r7, r1, #0
 *   @0x232334 addlt r12, r8, #480
 *   @0x232338 strlt r12, [sp, #0x10]
 *   @0x23233c movlt r10, r0
 *   @0x232340 blt 0x232150 <ov_pcm_seek_page+0x27c>
 *   @0x232344 ldr r3, [r8, #0x60]
 *   @0x232348 ldr r4, [sp, #0x34]
 *   @0x23234c cmp r3, r4
 *   @0x232350 beq 0x2325d8 <ov_pcm_seek_page+0x704>
 *   @0x232354 add r6, r8, #480
 *   @0x232358 str r6, [sp, #0x10]
 *   @0x23235c mov r0, r6
 *   @0x232360 bl 0x2272ac <vorbis_dsp_clear>
 *   @0x232364 add r0, r8, #560
 *   @0x232368 bl 0x227208 <vorbis_block_clear>
 *   @0x23236c ldr r2, [r8, #0x40]
 *   @0x232370 mov r3, #2
 *   @0x232374 str r4, [r8, #0x60]
 *   @0x232378 str r3, [r8, #0x58]
 *   @0x23237c mov r3, #3
 *   @0x232380 ldr r1, [r2, r4, lsl #2]
 *   @0x232384 str r3, [r8, #0x58]
 *   @0x232388 str r1, [r8, #0x5c]
 *   @0x23238c add r4, r8, #120
 *   @0x232390 add r6, sp, #120
 *   @0x232394 mov r0, r4
 *   @0x232398 bl 0x2352f4 <ogg_stream_reset_serialno>
 *   @0x23239c mov r0, r4
 *   @0x2323a0 mov r1, r5
 *   @0x2323a4 bl 0x234eac <ogg_stream_pagein>
 *   @0x2323a8 b 0x2323d4 <ov_pcm_seek_page+0x500>
 *   @0x2323ac cmp r2, #0
 *   @0x2323b0 sbcs r7, r3, #0
 *   @0x2323b4 blt 0x232650 <ov_pcm_seek_page+0x77c>
 *   @0x2323b8 ldrd r10, r11, [sp, #136]
 *   @0x2323bc mvn r2, #0
 *   @0x2323c0 mvn r3, #0
 *   @0x2323c4 cmp r11, r3
 *   @0x2323c8 cmpeq r10, r2
 *   @0x2323cc bne 0x2325f0 <ov_pcm_seek_page+0x71c>
 *   @0x2323d0 bl 0x235328 <ogg_stream_packetout>
 *   @0x2323d4 mov r1, r6
 *   @0x2323d8 mov r0, r4
 *   @0x2323dc bl 0x23535c <ogg_stream_packetpeek>
 *   @0x2323e0 mov r1, #0
 *   @0x2323e4 asr r3, r0, #31
 *   @0x2323e8 mov r2, r0
 *   @0x2323ec orrs r10, r2, r3
 *   @0x2323f0 mov r0, r4
 *   @0x2323f4 bne 0x2323ac <ov_pcm_seek_page+0x4d8>
 *   @0x2323f8 ldr r2, [sp, #0x48]
 *   @0x2323fc mov r0, r8
 *   @0x232400 ldr r3, [sp, #0x4c]
 *   @0x232404 bl 0x22ffe0 <vorbis_packet_blocksize+0x364>
 *   @0x232408 subs r10, r0, #0
 *   @0x23240c blt 0x232150 <ov_pcm_seek_page+0x27c>
 *   @0x232410 ldrd r10, r11, [r8, #8]
 *   @0x232414 mov r9, #0
 *   @0x232418 mov r4, r8
 *   @0x23241c mov r8, r5
 *   @0x232420 strd r10, r11, [sp, #24]
 *   @0x232424 ldrd r6, r7, [sp, #24]
 *   @0x232428 mov r0, r4
 *   @0x23242c subs r6, r6, #32768
 *   @0x232430 sbc r7, r7, #0
 *   @0x232434 strd r6, r7, [sp, #24]
 *   @0x232438 cmp r6, #0
 *   @0x23243c sbcs r7, r7, #0
 *   @0x232440 movlt r6, #0
 *   @0x232444 movlt r7, #0
 *   @0x232448 strdlt r6, r7, [sp, #24]
 *   @0x23244c ldrd r2, r3, [sp, #24]
 *   @0x232450 bl 0x22ffe0 <vorbis_packet_blocksize+0x364>
 *   @0x232454 asr r7, r0, #31
 *   @0x232458 mov r6, r0
 *   @0x23245c orrs r12, r6, r7
 *   @0x232460 bne 0x232658 <ov_pcm_seek_page+0x784>
 *   @0x232464 mvn r6, #0
 *   @0x232468 mvn r7, #0
 *   @0x23246c b 0x2324b4 <ov_pcm_seek_page+0x5e0>
 *   @0x232470 subs r2, r10, r2
 *   @0x232474 sbc r3, r11, r3
 *   @0x232478 str r9, [r8]
 *   @0x23247c str r9, [sp, #0x6c]
 *   @0x232480 str r9, [sp, #0x70]
 *   @0x232484 str r9, [sp, #0x74]
 *   @0x232488 bl 0x22fd0c <vorbis_packet_blocksize+0x90>
 *   @0x23248c mvn r2, #127
 *   @0x232490 mvn r3, #0
 *   @0x232494 cmp r1, r3
 *   @0x232498 cmpeq r0, r2
 *   @0x23249c beq 0x232540 <ov_pcm_seek_page+0x66c>
 *   @0x2324a0 cmp r0, #0
 *   @0x2324a4 sbcs r3, r1, #0
 *   @0x2324a8 blt 0x2324cc <ov_pcm_seek_page+0x5f8>
 *   @0x2324ac mov r6, r0
 *   @0x2324b0 mov r7, r1
 *   @0x2324b4 ldrd r2, r3, [r4, #8]
 *   @0x2324b8 mov r0, r4
 *   @0x2324bc mov r1, r8
 *   @0x2324c0 cmp r2, r10
 *   @0x2324c4 sbcs r5, r3, r11
 *   @0x2324c8 blt 0x232470 <ov_pcm_seek_page+0x59c>
 *   @0x2324cc mvn r0, #0
 *   @0x2324d0 mvn r1, #0
 *   @0x2324d4 cmp r7, r1
 *   @0x2324d8 cmpeq r6, r0
 *   @0x2324dc beq 0x232424 <ov_pcm_seek_page+0x550>
 *   @0x2324e0 ldr r3, [sp, #0x6c]
 *   @0x2324e4 mov r5, r8
 *   @0x2324e8 mov r8, r4
 *   @0x2324ec cmp r3, #0
 *   @0x2324f0 beq 0x2326ac <ov_pcm_seek_page+0x7d8>
 *   @0x2324f4 cmp r6, #0
 *   @0x2324f8 sbcs r0, r7, #0
 *   @0x2324fc blt 0x2326a4 <ov_pcm_seek_page+0x7d0>
 *   @0x232500 mov r0, r5
 *   @0x232504 bl 0x23409c <ogg_page_serialno>
 *   @0x232508 ldr r3, [r8, #0x5c]
 *   @0x23250c cmp r0, r3
 *   @0x232510 beq 0x23259c <ov_pcm_seek_page+0x6c8>
 *   @0x232514 strd r6, r7, [r8, #8]
 *   @0x232518 mov r10, r6
 *   @0x23251c mov r11, r7
 *   @0x232520 b 0x232418 <ov_pcm_seek_page+0x544>
 *   @0x232524 ldr r7, [sp, #0x34]
 *   @0x232528 lsl r2, r7, #4
 *   @0x23252c add r1, r3, r2
 *   @0x232530 ldrd r0, r1, [r1, #8]
 *   @0x232534 b 0x231fc8 <ov_pcm_seek_page+0xf4>
 *   @0x232538 mvn r10, #137
 *   @0x23253c b 0x232174 <ov_pcm_seek_page+0x2a0>
 *   @0x232540 mov r8, r4
 *   @0x232544 mvn r10, #127
 *   @0x232548 b 0x232150 <ov_pcm_seek_page+0x27c>
 *   @0x23254c ldr r4, [sp, #0x10]
 *   @0x232550 ldr r5, [sp, #0x14]
 *   @0x232554 str r4, [sp, #0x48]
 *   @0x232558 str r5, [sp, #0x4c]
 *   @0x23255c b 0x232124 <ov_pcm_seek_page+0x250>
 *   @0x232560 strd r0, r1, [sp, #80]
 *   @0x232564 mov r6, r4
 *   @0x232568 mov r7, r5
 *   @0x23256c ldr r10, [sp, #0x48]
 *   @0x232570 ldrd r0, r1, [sp, #56]
 *   @0x232574 ldrd r4, r5, [sp, #16]
 *   @0x232578 ldr r11, [sp, #0x4c]
 *   @0x23257c cmp r4, r6
 *   @0x232580 sbcs r2, r5, r7
 *   @0x232584 bge 0x232698 <ov_pcm_seek_page+0x7c4>
 *   @0x232588 strd r0, r1, [sp, #56]
 *   @0x23258c strd r4, r5, [sp, #16]
 *   @0x232590 str r10, [sp, #0x48]
 *   @0x232594 str r11, [sp, #0x4c]
 *   @0x232598 b 0x232044 <ov_pcm_seek_page+0x170>
 *   @0x23259c mov r0, r5
 *   @0x2325a0 bl 0x233fb0 <ogg_page_granulepos>
 *   @0x2325a4 cmp r0, #0
 *   @0x2325a8 sbcs r2, r1, #0
 *   @0x2325ac bge 0x2325c0 <ov_pcm_seek_page+0x6ec>
 *   @0x2325b0 mov r0, r5
 *   @0x2325b4 bl 0x233f80 <ogg_page_continued>
 *   @0x2325b8 cmp r0, #0
 *   @0x2325bc bne 0x232514 <ov_pcm_seek_page+0x640>
 *   @0x2325c0 mov r0, r8
 *   @0x2325c4 mov r2, r6
 *   @0x2325c8 mov r3, r7
 *   @0x2325cc bl 0x231618 <ov_raw_seek>
 *   @0x2325d0 mov r10, r0
 *   @0x2325d4 b 0x232174 <ov_pcm_seek_page+0x2a0>
 *   @0x2325d8 add r7, r8, #480
 *   @0x2325dc str r7, [sp, #0x10]
 *   @0x2325e0 mov r0, r7
 *   @0x2325e4 bl 0x22723c <vorbis_synthesis_restart>
 *   @0x2325e8 ldr r1, [r8, #0x5c]
 *   @0x2325ec b 0x23238c <ov_pcm_seek_page+0x4b8>
 *   @0x2325f0 ldr r1, [r8, #0x60]
 *   @0x2325f4 mov r2, #0
 *   @0x2325f8 ldr r0, [r8, #0x44]
 *   @0x2325fc mov r3, #0
 *   @0x232600 ldrd r6, r7, [sp, #32]
 *   @0x232604 lsl r1, r1, #4
 *   @0x232608 add r0, r0, r1
 *   @0x23260c ldrd r0, r1, [r0]
 *   @0x232610 subs r0, r10, r0
 *   @0x232614 sbc r1, r11, r1
 *   @0x232618 strd r0, r1, [r8, #80]
 *   @0x23261c cmp r2, r0
 *   @0x232620 sbcs r4, r3, r1
 *   @0x232624 ldrd r4, r5, [sp, #40]
 *   @0x232628 movlt r3, r1
 *   @0x23262c movlt r2, r0
 *   @0x232630 adds r2, r2, r6
 *   @0x232634 adc r3, r3, r7
 *   @0x232638 strd r2, r3, [r8, #80]
 *   @0x23263c cmp r4, r2
 *   @0x232640 sbcs r5, r5, r3
 *   @0x232644 bge 0x232664 <ov_pcm_seek_page+0x790>
 *   @0x232648 mvn r10, #128
 *   @0x23264c b 0x232150 <ov_pcm_seek_page+0x27c>
 *   @0x232650 mvn r10, #135
 *   @0x232654 b 0x232150 <ov_pcm_seek_page+0x27c>
 *   @0x232658 mov r5, r8
 *   @0x23265c mov r8, r4
 *   @0x232660 b 0x2324f4 <ov_pcm_seek_page+0x620>
 *   @0x232664 mov r0, r8
 *   @0x232668 mvn r1, #0
 *   @0x23266c bl 0x23138c <ov_pcm_total>
 *   @0x232670 ldrd r4, r5, [sp, #40]
 *   @0x232674 cmp r0, r4
 *   @0x232678 sbcs r5, r1, r5
 *   @0x23267c blt 0x232648 <ov_pcm_seek_page+0x774>
 *   @0x232680 mov r2, #0
 *   @0x232684 mov r3, #0
 *   @0x232688 mov r10, #0
 *   @0x23268c strd r2, r3, [r8, #104]
 *   @0x232690 strd r2, r3, [r8, #112]
 *   @0x232694 b 0x232174 <ov_pcm_seek_page+0x2a0>
 *   @0x232698 str r10, [sp, #0x48]
 *   @0x23269c str r11, [sp, #0x4c]
 *   @0x2326a0 b 0x232124 <ov_pcm_seek_page+0x250>
 *   @0x2326a4 mov r10, r6
 *   @0x2326a8 b 0x232150 <ov_pcm_seek_page+0x27c>
 *   @0x2326ac mov r2, r6
 *   @0x2326b0 mov r3, r7
 *   @0x2326b4 mov r0, r4
 *   @0x2326b8 bl 0x22ffe0 <vorbis_packet_blocksize+0x364>
 *   @0x2326bc asr r1, r0, #31
 *   @0x2326c0 orrs r10, r0, r1
 *   @0x2326c4 movne r6, r0
 *   @0x2326c8 movne r7, r1
 *   @0x2326cc bne 0x2324f4 <ov_pcm_seek_page+0x620>
 *   @0x2326d0 mov r0, r4
 *   @0x2326d4 mov r1, r5
 *   @0x2326d8 mov r2, #32768
 *   @0x2326dc mov r3, #0
 *   @0x2326e0 bl 0x22fd0c <vorbis_packet_blocksize+0x90>
 *   @0x2326e4 cmp r0, #0
 *   @0x2326e8 sbcs r12, r1, #0
 *   @0x2326ec bge 0x2324f4 <ov_pcm_seek_page+0x620>
 *   @0x2326f0 b 0x232648 <ov_pcm_seek_page+0x774>
 *
 * ══ §6/16 anon_2f929c  0x2f929c  size 2072  518 条（0x2f929c..0x2f9ab4）
 * @func 0x2f929c 0x2f9ab4  size 2072  518 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3c8304 / anon_30a7b2+0x8fc6 / 0xff37f4d8 / 0x3f13fc / 0x431418 / 0xfe3898d6 / 0xff40204e / 0xcf14c4
 * 字段偏移 top8: 无
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2f929c andlo pc, r0, #132096
 *   @0x2f92a0 rscvc lr, r2, pc, asr #20
 *   @0x2f92a4 andpl pc, r0, r0, lsl #10
 *   @0x2f92a8 .word 0xf142181b
 *   @0x2f92ac b 0x16b9ab4 <b2_toiTime+0xf60610>
 *   @0x2f92b0 b 0x1305504 <b2_toiTime+0xbac060>
 *   @0x2f92b4 ldrbmi r4, [r0, -r2, lsl #1]!
 *   @0x2f92b8 strheq pc, [r0, -r0]
 *   @0x2f92bc .word 0xf8d04770
 *   @0x2f92c0 .word 0xf8533184
 *   @0x2f92c4 ldrbmi r0, [r0, -r1, lsr #32]!
 *   @0x2f92c8 .word 0x3184f8d0
 *   @0x2f92cc eorhs pc, r1, r3, asr #16
 *   @0x2f92d0 .word 0xf8d04770
 *   @0x2f92d4 .word 0xf8533184
 *   @0x2f92d8 strmi r0, [r2], #-33
 *   @0x2f92dc eorhs pc, r1, r3, asr #16
 *   @0x2f92e0 .word 0xf8d04770
 *   @0x2f92e4 .word 0xf8d0316c
 *   @0x2f92e8 movwlo r2, #0x2168
 *   @0x2f92ec smulbtlo r12, r0, r8
 *   @0x2f92f0 .word 0xf8134413
 *   @0x2f92f4 .word 0xf8130c02
 *   @0x2f92f8 bl 0x3c8304 <error_g0017+0x20fa8>
 *   @0x2f92fc andlt r2, r0, #0
 *   @0x2f9300 ldrlt r4, [r0, #-0x770]!
 *   @0x2f9304 cdpvs p8, #0x2, c6, c12, c5, #0x0
 *   @0x2f9308 stchs p12, c6, [r8], #-144
 *   @0x2f930c .word 0xf890d109
 *   @0x2f9310 stmdblt r0, {r0, r1, r2, r5, r6, r9} ^
 *   @0x2f9314 .word 0xf8506908
 *   @0x2f9318 ldrmi r4, [r12], #-50
 *   @0x2f931c eorsmi pc, r2, r0, asr #16
 *   @0x2f9320 stchs p0, c14, [r3], #-4
 *   @0x2f9324 stmibvs r11, {r1, r2, r4, r5, r6, r7, r12, lr, pc}
 *   @0x2f9328 .word 0xf0415c99
 *   @0x2f932c ldrpl r0, [r9], #264
 *   @0x2f9330 ldrlt r11, [r0, #-0xd30]!
 *   @0x2f9334 cdpvs p8, #0x2, c6, c12, c5, #0x0
 *   @0x2f9338 stchs p12, c6, [r8], #-144
 *   @0x2f933c .word 0xf890d108
 *   @0x2f9340 .word 0xb12c4267
 *   @0x2f9344 rsbmi pc, r8, #144, #16
 *   @0x2f9348 .word 0xf890b114
 *   @0x2f934c stmdblt r8!, {r0, r3, r5, r6, r9}
 *   @0x2f9350 bl 0x313778 <af_shaper_get_elem+0x8fe6>
 *   @0x2f9354 stmdavs r4, {r1, r6, r7} ^
 *   @0x2f9358 subvs r4, r4, r12, lsl r4
 *   @0x2f935c ldcpl p9, c6, [r9], {139}
 *   @0x2f9360 tsteq r0, r1, asr #32
 *   @0x2f9364 ldclt p4, c5, [r0, #-612]!
 *   @0x2f9368 .word 0xf85168c9
 *   @0x2f936c strmi r0, [r3], #-50
 *   @0x2f9370 eorslo pc, r2, r1, asr #16
 *   @0x2f9374 stmvs r9, {r4, r5, r6, r8, r9, r10, lr} ^
 *   @0x2f9378 sbceq lr, r2, #1024
 *   @0x2f937c strmi r6, [r11], #-2129
 *   @0x2f9380 .word 0x47706053
 *   @0x2f9384 svclt #0xab2900
 *   @0x2f9388 bl 0xff37f4d8 <b2_toiTime+0xfffffffffec26034>
 *   @0x2f938c b 0xb79b98 <b2_toiTime+0x4206f4>
 *   @0x2f9390 b 0x395720 <ft_adobe_glyph_list+0x4dfc>
 *   @0x2f9394 ldrbmi r7, [r0, -r2, ror #1]!
 *   @0x2f9398 biceq pc, r0, #2
 *   @0x2f939c andle r2, r11, r0, asr #22
 *   @0x2f93a0 ldmdblt r11, {r2, r10, r11, r12, lr, pc} ^
 *   @0x2f93a4 bicsvc lr, r1, r1, lsl #22
 *   @0x2f93a8 and r1, r5, r9, asr #32
 *   @0x2f93ac andle r2, r2, r0, lsl #23
 *   @0x2f93b0 andle r2, r1, r0, asr #23
 *   @0x2f93b4 subeq lr, r9, r2
 *   @0x2f93b8 mvnne pc, r0, asr #17
 *   @0x2f93bc teqeq r0, r2
 *   @0x2f93c0 .word 0x31e0f8d0
 *   @0x2f93c4 andle r2, r11, r0, lsl r9
 *   @0x2f93c8 orrslt sp, r9, r1, lsl #24
 *   @0x2f93cc stmdbhs r0!, {r2, r4, sp, lr, pc}
 *   @0x2f93d0 ldmdbhs r0!, {r0, r1, r3, r12, lr, pc}
 *   @0x2f93d4 .word 0x2103d110
 *   @0x2f93d8 svclt #0x484359
 *   @0x2f93dc and r3, r8, r3, lsl #2
 *   @0x2f93e0 ldrmi r2, [r9], -r0, lsl #22
 *   @0x2f93e4 vldmiane r9, {s27, s28, s29, s30, s31}
 *   @0x2f93e8 bl 0x3f13fc
 *   @0x2f93ec ldrdne r7, r8, [r9], #-19
 *   @0x2f93f0 addne lr, r9, r0
 *   @0x2f93f4 mvnne pc, r0, asr #17
 *   @0x2f93f8 andeq pc, pc, #18
 *   @0x2f93fc cdpne p1, #0x5, c13, c10, c1, #0x0
 *   @0x2f9400 blo 0x431418 <g_RomDisk+0x39bf8>
 *   @0x2f9404 svclt #0x48435a
 *   @0x2f9408 sbcsne r3, r2, r7, lsl #4
 *   @0x2f940c .word 0xf8c0121b
 *   @0x2f9410 .word 0xf8d031e0
 *   @0x2f9414 .word 0xf8c031e4
 *   @0x2f9418 andsne r2, r11, #232, #2
 *   @0x2f941c mvnlo pc, r0, asr #17
 *   @0x2f9420 .word 0x31e8f8d0
 *   @0x2f9424 .word 0xf8c0121b
 *   @0x2f9428 ldrbmi r3, [r0, -r8, ror #3]!
 *   @0x2f942c rfeib r0!
 *   @0x2f9430 rfeib r0!
 *   @0x2f9434 blx 0xfe3898d6 <b2_toiTime+0xfffffffffdc30432>
 *   @0x2f9438 blx 0xff40204e <b2_toiTime+0xfffffffffeca8baa>
 *   @0x2f943c ldrbne r2, [r8, r1, lsl #6]
 *   @0x2f9440 .word 0xf5104601
 *   @0x2f9444 .word 0xf1415000
 *   @0x2f9448 ldmdane r2, {r8}
 *   @0x2f944c movweq lr, #0x1b43
 *   @0x2f9450 b 0x12fc298 <b2_toiTime+0xba2df4>
 *   @0x2f9454 ldclt p0, c4, [r0, #-524]
 *   @0x2f9458 ldrbmi r4, [r0, -r8, lsl #12]!
 *   @0x2f945c .word 0x47704610
 *   @0x2f9460 strhne pc, [lr, -r0]!
 *   @0x2f9464 andlt r11, r10, #112, #10
 *   @0x2f9468 strhlo pc, [r10, -r0]!
 *   @0x2f946c svcmi #0x80f5b2
 *   @0x2f9470 .word 0xf8c0d102
 *   @0x2f9474 ands r3, r2, r8, lsr r2
 *   @0x2f9478 ldrhmi pc, [r0, -r0]!
 *   @0x2f947c svcmi #0x80f5b4
 *   @0x2f9480 rfeib r0!
 *   @0x2f9484 and r1, r8, r12, lsr #2
 *   @0x2f9488 strhvs pc, [r12, -r0]!
 *   @0x2f948c strhpl pc, [r10, -r0]!
 *   @0x2f9490 .word 0xf404fb16
 *   @0x2f9494 .word 0x4101fb15
 *   @0x2f9498 .word 0xf8c01389
 *   @0x2f949c .word 0xf5b31238
 *   @0x2f94a0 smlabble r2, r0, pc, r4
 *   @0x2f94a4 ldrbtmi r4, [r11], #-2858
 *   @0x2f94a8 rfeib r0!
 *   @0x2f94ac .word 0xf5b3312c
 *   @0x2f94b0 smlabble r2, r0, pc, r4
 *   @0x2f94b4 ldrbtmi r4, [r11], #-2855
 *   @0x2f94b8 blmi 0xcf14c4 <b2_toiTime+0x598020>
 *   @0x2f94bc .word 0xf8c0447b
 *   @0x2f94c0 rfeib r0!
 *   @0x2f94c4 .word 0xf5b33126
 *   @0x2f94c8 smlabble r2, r0, pc, r4
 *   @0x2f94cc ldrbtmi r4, [r11], #-2851
 *   @0x2f94d0 rfeib r0!
 *   @0x2f94d4 .word 0xf5b33128
 *   @0x2f94d8 smlabble r2, r0, pc, r4
 *   @0x2f94dc ldrbtmi r4, [r11], #-2848
 *   @0x2f94e0 blmi 0xb314ec <b2_toiTime+0x3d8048>
 *   @0x2f94e4 .word 0xf8c0447b
 *   @0x2f94e8 blmi 0xac5e00 <b2_toiTime+0x36c95c>
 *   @0x2f94ec .word 0xf8c0447b
 *   @0x2f94f0 blmi 0xa85e28 <b2_toiTime+0x32c984>
 *   @0x2f94f4 .word 0xf8c0447b
 *   @0x2f94f8 .word 0xf8d03250
 *   @0x2f94fc .word 0xf5b33238
 *   @0x2f9500 tstle r6, r0, lsl #31
 *   @0x2f9504 svcmi #0x80f5b2
 *   @0x2f9508 bmi 0x96d928 <b2_toiTime+0x214484>
 *   @0x2f950c .word 0xf8c0447a
 *   @0x2f9510 bmi 0x901e48 <b2_toiTime+0x1a89a4>
 *   @0x2f9514 and r4, r10, r10, ror r4
 *   @0x2f9518 ldrhhs pc, [r0, -r0]!
 *   @0x2f951c svcmi #0x80f5b2
 *   @0x2f9520 bmi 0x86d944 <b2_toiTime+0x1144a0>
 *   @0x2f9524 .word 0xf8c0447a
 *   @0x2f9528 bmi 0x801e60 <b2_toiTime+0xa89bc>
 *   @0x2f952c .word 0xf8c0447a
 *   @0x2f9530 .word 0xf2032250
 *   @0x2f9534 .word 0xf24033ff
 *   @0x2f9538 addsmi r7, r3, #-536870897
 *   @0x2f953c .word 0xf44fbf9c
 *   @0x2f9540 .word 0xf8c04380
 *   @0x2f9544 movwhs r3, #0x238
 *   @0x2f9548 smlabtlo r4, r0, r8, pc
 *   @0x2f954c svclt #0xbd70
 *   @0x2f9550 .word 0xffffffaf
 *   @0x2f9554 .word 0xffffffa3
 *   @0x2f9558 andeq r5, r0, r11, lsl #20
 *   @0x2f955c .word 0xffffff87
 *   @0x2f9560 .word 0xffffff7b
 *   @0x2f9564 .word 0xffffff45
 *   @0x2f9568 andeq r0, r0, r11, lsl #19
 *   @0x2f956c andeq r0, r0, r9, lsr r9
 *   @0x2f9570 .word 0xfffffdf3
 *   @0x2f9574 .word 0xfffffe51
 *   @0x2f9578 .word 0xfffffe0b
 *   @0x2f957c .word 0xfffffe47
 *   @0x2f9580 .word 0xf8d0b530
 *   @0x2f9584 .word 0xf8d0216c
 *   @0x2f9588 ldrmi r3, [r3], #-376
 *   @0x2f958c ldrsbhs pc, [r0, #-128]!
 *   @0x2f9590 smulbtlo r12, r0, r8
 *   @0x2f9594 blle 0x3c9fe8 <error_g0017+0x22c8c>
 *   @0x2f9598 sbcvs r2, r3, r3, lsl #7
 *   @0x2f959c ldclt p0, c2, [r0, #-4]!
 *   @0x2f95a0 .word 0x4168f8d0
 *   @0x2f95a4 stclpl p13, c4, [r1], #52
 *   @0x2f95a8 .word 0xf880447d
 *   @0x2f95ac uqsub16pl r1, r9, r4
 *   @0x2f95b0 .word 0xf8c02900
 *   @0x2f95b4 ble 0x57db9c <g_SWFlineaavertbuff+0x2aad4>
 *   @0x2f95b8 addsmi r1, r5, #23808
 *   @0x2f95bc ldrmi sp, [r12], #-2796
 *   @0x2f95c0 blx 0x75775a <g_SplashHeight+0x2>
 *   @0x2f95c4 .word 0xf1c1f104
 *   @0x2f95c8 .word 0xf8c00102
 *   @0x2f95cc .word 0xf8d01178
 *   @0x2f95d0 strmi r1, [r11], #-376
 *   @0x2f95d4 ldclle p2, c4, [pc], {147}
 *   @0x2f95d8 ldclt p0, c2, [r0, #-0]!
 *   @0x2f95dc andeq r6, r10, r12, asr r9
 *   @0x2f95e0 .word 0x4604b570
 *   @0x2f95e4 .word 0x0164f8d0
 *   @0x2f95e8 mrsle r2, apsr
 *   @0x2f95ec mlas r12, r12, r3, r2
 *   @0x2f95f0 ldrsbpl pc, [r8, r4]
 *   @0x2f95f4 .word 0xf8d42618
 *   @0x2f95f8 stmdavs r11, {r4, r7, r8, sp}
 *   @0x2f95fc strpl pc, [r2], -r6, lsl #22
 *   @0x2f9600 andle r4, r2, #1342177291
 *   @0x2f9604 addsmi r6, r9, #15269888
 *   @0x2f9608 adcsmi sp, r5, #-2147483648
 *   @0x2f960c and sp, r1, r9, lsl #2
 *   @0x2f9610 .word 0xe7f53518
 *   @0x2f9614 ldrsbne pc, [r4, r4]
 *   @0x2f9618 andle r4, r5, #-1610612728
 *   @0x2f961c .word 0xf8c43201
 *   @0x2f9620 .word 0xf5b32190
 *   @0x2f9624 movwle r3, #0x1f80
 *   @0x2f9628 ands r2, lr, r12, lsl #7
 *   @0x2f962c rscvs r6, r11, r8, lsr #32
 *   @0x2f9630 .word 0x216cf8d4
 *   @0x2f9634 rsbvs r3, r10, r1, lsl #4
 *   @0x2f9638 strtvc r2, [r10], #-513
 *   @0x2f963c strbtvc r2, [r10], #-512
 *   @0x2f9640 .word 0xf8d4616a
 *   @0x2f9644 addsmi r2, r3, #168, #2
 *   @0x2f9648 .word 0xf8c4d904
 *   @0x2f964c and r3, r1, r8, lsr #3
 *   @0x2f9650 andle r2, r9, r12, lsr #22
 *   @0x2f9654 .word 0xf7ff4620
 *   @0x2f9658 stmdblt r0!, {r0, r1, r4, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2f965c .word 0x3174f894
 *   @0x2f9660 andle r2, r4, sp, lsr #22
 *   @0x2f9664 mvnsle r2, r9, lsl #23
 *   @0x2f9668 rscvs r2, r3, r9, lsl #7
 *   @0x2f966c .word 0xf8d4bd70
 *   @0x2f9670 adcvs r3, r11, r12, ror #2
 *   @0x2f9674 ldcllt p13, c11, [r0, #-448]!
 *   @0x2f9678 .word 0x4604b570
 *   @0x2f967c .word 0x3164f8d0
 *   @0x2f9680 .word 0xd1012b03
 *   @0x2f9684 mlas sp, r12, r3, r2
 *   @0x2f9688 .word 0x51a4f8d0
 *   @0x2f968c .word 0xf8d02218
 *   @0x2f9690 blx 0x385d0a <_ZTS13C_UTF16String+0x1cdb6>
 *   @0x2f9694 addsmi r5, r5, #805306368
 *   @0x2f9698 stmvs lr!, {r0, r1, r9, r12, lr, pc} ^
 *   @0x2f969c addmi r6, r6, #8, #16
 *   @0x2f96a0 addsmi sp, r5, #-2147483648
 *   @0x2f96a4 and sp, r1, r9, lsl #2
 *   @0x2f96a8 .word 0xe7f43518
 *   @0x2f96ac .word 0x21a0f8d4
 *   @0x2f96b0 andle r4, r5, #805306377
 *   @0x2f96b4 .word 0xf8c43301
 *   @0x2f96b8 stmdavs r11, {r2, r3, r4, r7, r8, r12, sp}
 *   @0x2f96bc stmdble r1, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r11, sp}
 *   @0x2f96c0 ands r2, pc, sp, lsl #7
 *   @0x2f96c4 .word 0xf8d460eb
 *   @0x2f96c8 movwlo r3, #0x116c
 *   @0x2f96cc .word 0xf8d4606b
 *   @0x2f96d0 eorvs r3, r11, r4, ror #2
 *   @0x2f96d4 strtvc r2, [r11], #-769
 *   @0x2f96d8 .word 0xf8d4680b
 *   @0x2f96dc addsmi r2, r3, #172, #2
 *   @0x2f96e0 sbcslt sp, r11, #81920
 *   @0x2f96e4 .word 0x31acf8c4
 *   @0x2f96e8 blhs 0xe316f4 <b2_toiTime+0x6d8250>
 *   @0x2f96ec strtmi sp, [r0], -r9
 *   @0x2f96f0 .word 0xff46f7ff
 *   @0x2f96f4 .word 0xf894b960
 *   @0x2f96f8 blhs 0xe45cd0 <b2_toiTime+0x6ec82c>
 *   @0x2f96fc blhs 0xfe56d714 <b2_toiTime+0xfffffffffde14270>
 *   @0x2f9700 orrhs sp, r9, #-1073741764
 *   @0x2f9704 ldcllt p0, c6, [r0, #-908]!
 *   @0x2f9708 .word 0x316cf8d4
 *   @0x2f970c ldcllt p0, c6, [r0, #-684]!
 *   @0x2f9710 ldrblt r11, [r8, #0xd70]!
 *   @0x2f9714 stmdahi sp, {r2, r9, r10, lr}
 *   @0x2f9718 rfeia r0!
 *   @0x2f971c adcmi r3, r11, #116
 *   @0x2f9720 .word 0xf890d805
 *   @0x2f9724 mvnslt r3, r5, lsr r2
 *   @0x2f9728 sbcvs r2, r3, r6, lsl #7
 *   @0x2f972c svcvs #0xc2bdf8
 *   @0x2f9730 ldmibne r3, {r1, r2, r3, r5, r6, r7}
 *   @0x2f9734 eorsne pc, r5, r2, asr r8
 *   @0x2f9738 .word 0xf8d0685a
 *   @0x2f973c ldrmi r3, [r8, r0, asr #4]
 *   @0x2f9740 .word 0xf104687b
 *   @0x2f9744 .word 0xf8d4016c
 *   @0x2f9748 strtmi r7, [r10], -r12, asr #4
 *   @0x2f974c qadd16mi r1, r0, r11
 *   @0x2f9750 rfeia r4!
 *   @0x2f9754 ldmdblt r11!, {r5, r6, r8, r12, sp}
 *   @0x2f9758 svcvs #0xe26fa3
 *   @0x2f975c ldrmi r4, [r6], #-1075
 *   @0x2f9760 muleq r3, r6, r8
 *   @0x2f9764 andeq lr, r3, r3, lsl #17
 *   @0x2f9768 push {r3, r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x2f976c .word 0x460d43f8
 *   @0x2f9770 strmi r6, [r4], -r11, asr #16
 *   @0x2f9774 stmdahi r10!, {r0, r7, r8, r10, r11, pc}
 *   @0x2f9778 stmdble r4, {r0, r4, r7, r9, lr}
 *   @0x2f977c ldrhne pc, [r0], #-128
 *   @0x2f9780 addsmi r11, r9, #-1342177271
 *   @0x2f9784 .word 0xf894d807
 *   @0x2f9788 stmdahs r0, {r0, r2, r4, r5, r9}
 *   @0x2f978c orrhs sp, r6, #100
 *   @0x2f9790 rscvs r2, r3, r0
 *   @0x2f9794 .word 0xf890e060
 *   @0x2f9798 .word 0x07c91174
 *   @0x2f979c blvs 0x136ebe4 <b2_toiTime+0xc15740>
 *   @0x2f97a0 bl 0x354dc0
 *   @0x2f97a4 bl 0x47cab4 <targetStr+0x1874>
 *   @0x2f97a8 .word 0xf8510ec3
 *   @0x2f97ac .word 0xf8567032
 *   @0x2f97b0 .word 0xf8de1033
 *   @0x2f97b4 .word 0xf8dc2004
 *   @0x2f97b8 .word 0xf8d06004
 *   @0x2f97bc ands r3, r5, r0, asr #4
 *   @0x2f97c0 ldrhne pc, [r12, #-128]
 *   @0x2f97c4 rfeia r0!
 *   @0x2f97c8 ldmiblt r1, {r1, r2, r3, r4, r6, r8, r12}
 *   @0x2f97cc .word 0x6d606b21
 *   @0x2f97d0 strbeq lr, [r2], r1, lsl #22
 *   @0x2f97d4 vdiveq.f64 d30, d3, d0
 *   @0x2f97d8 eorsvc pc, r2, r1, asr r8
 *   @0x2f97dc .word 0xf8506876
 *   @0x2f97e0 qasxmi r1, r0, r3
 *   @0x2f97e4 .word 0x2004f8de
 *   @0x2f97e8 sublo pc, r4, #212, #16
 *   @0x2f97ec bne 0xfef801d8 <b2_toiTime+0xfffffffffe826d34>
 *   @0x2f97f0 .word 0xf8d0e031
 *   @0x2f97f4 .word 0xf8d010e0
 *   @0x2f97f8 .word 0xf8d060e4
 *   @0x2f97fc .word 0xf8d0c038
 *   @0x2f9800 adcsmi lr, r1, #92
 *   @0x2f9804 strbeq lr, [r2, r12, lsl #22]
 *   @0x2f9808 stmibeq r3, {r1, r2, r3, r8, r9, r11, sp, lr, pc} ^
 *   @0x2f980c eorshs pc, r2, r12, asr r8
 *   @0x2f9810 eorslo pc, r3, lr, asr r8
 *   @0x2f9814 .word 0xf8d7d10e
 *   @0x2f9818 bne 0xff771830 <b2_toiTime+0xffffffffff01838c>
 *   @0x2f981c .word 0x7004f8d9
 *   @0x2f9820 subvs pc, r4, #208, #16
 *   @0x2f9824 andeq lr, lr, #203776
 *   @0x2f9828 .word 0xf8d447b0
 *   @0x2f982c .word 0xf7ff10e0
 *   @0x2f9830 ands pc, r1, r12, ror #21
 *   @0x2f9834 .word 0xf7ff1ad0
 *   @0x2f9838 .word 0xf8d9fae8
 *   @0x2f983c .word 0xf8d43004
 *   @0x2f9840 strmi r1, [r0], r4, ror #1
 *   @0x2f9844 bne 0xff313a2c <b2_toiTime+0xfffffffffebba588>
 *   @0x2f9848 blx 0xffaf784c <b2_toiTime+0xffffffffff39e3a8>
 *   @0x2f984c sublo pc, r4, #212, #16
 *   @0x2f9850 strmi r4, [r2], -r1, asr #12
 *   @0x2f9854 ldrmi r4, [r8, r0, lsr #12]
 *   @0x2f9858 pop {r3, r5, sp, lr}
 *   @0x2f985c stmdavs r10, {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2f9860 blhs 0x2e63b4 <FT_Outline_Copy+0x48>
 *   @0x2f9864 movwhs sp, #0x1101
 *   @0x2f9868 blhs 0x331948
 *   @0x2f986c ldrbeq sp, [r2, #0x34]
 *   @0x2f9870 rfeia r0!
 *   @0x2f9874 addsmi r2, r10, #0, #2
 *   @0x2f9878 andhs r11, r1, #220, #30
 *   @0x2f987c cmphs r5, r0, lsl #17
 *   @0x2f9880 ldreq r6, [r2, #0x80a]
 *   @0x2f9884 .word 0xf890d505
 *   @0x2f9888 tstlt r2, sp, lsl r1
 *   @0x2f988c .word 0xf8802201
 *   @0x2f9890 stmdavs r10, {r0, r2, r4, r6, r8, sp}
 *   @0x2f9894 strle r0, [r5, #-0x552]
 *   @0x2f9898 .word 0x211ef890
 *   @0x2f989c andhs r11, r1, #-2147483644
 *   @0x2f98a0 cmphs r5, r0, lsl #17
 *   @0x2f98a4 ldreq r6, [r2, #-0x80a]
 *   @0x2f98a8 rfeia r0!
 *   @0x2f98ac addsmi r2, r10, #0, #2
 *   @0x2f98b0 movwhs r11, #0xfc4
 *   @0x2f98b4 cmplo r5, r0, lsl #17
 *   @0x2f98b8 ldrbeq r6, [r10], #2059
 *   @0x2f98bc .word 0xf890d505
 *   @0x2f98c0 tstlt r3, sp, lsl r1
 *   @0x2f98c4 .word 0xf8802300
 *   @0x2f98c8 stmdavs r11, {r0, r2, r4, r6, r8, r12, sp}
 *   @0x2f98cc strle r0, [r5, #-0x49b]
 *   @0x2f98d0 .word 0x311ef890
 *   @0x2f98d4 movwhs r11, #0x113
 *   @0x2f98d8 cmplo r5, r0, lsl #17
 *   @0x2f98dc stmdavs r3, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2f98e0 .word 0x6c1b6e1b
 *   @0x2f98e4 .word 0xd1082b28
 *   @0x2f98e8 rsblo pc, r7, #144, #16
 *   @0x2f98ec .word 0xf890b12b
 *   @0x2f98f0 tstlt r3, r8, ror #4
 *   @0x2f98f4 rsblo pc, r9, #144, #16
 *   @0x2f98f8 stmdbvs r2, {r0, r1, r3, r4, r6, r8, r9, r11, r12, sp, pc}
 *   @0x2f98fc ldrsblo pc, [r4, -r0]!
 *   @0x2f9900 ble 0x98a370 <b2_toiTime+0x230ecc>
 *   @0x2f9904 eorslo pc, r5, #144, #16
 *   @0x2f9908 orrhs r11, r1, #1811939328
 *   @0x2f990c eor r6, r0, r3, asr #1
 *   @0x2f9910 stmibvs r2, {r0, r1, r6, r7, r8, r11, sp, lr}
 *   @0x2f9914 rfeia r0!
 *   @0x2f9918 .word 0x61c31098
 *   @0x2f991c eorlo pc, r3, r2, lsr r8
 *   @0x2f9920 stmdble pc, {r0, r3, r4, r7, r9, lr}
 *   @0x2f9924 .word 0x20a8f8d0
 *   @0x2f9928 .word 0xf0815cd1
 *   @0x2f992c ldrbpl r0, [r1], #257
 *   @0x2f9930 ldrsblo pc, [r4, -r0]!
 *   @0x2f9934 .word 0xf8c03b01
 *   @0x2f9938 .word 0xf8d03134
 *   @0x2f993c blhs 0x305e14 <TT_New_Context+0x5c0c>
 *   @0x2f9940 and sp, r6, r6, ror #25
 *   @0x2f9944 eorslo pc, r5, #144, #16
 *   @0x2f9948 rscsle r2, r1, r0, lsl #22
 *   @0x2f994c sbcvs r2, r3, r6, lsl #7
 *   @0x2f9950 movwhs r4, #0x1770
 *   @0x2f9954 teqlo r4, r0, asr #17
 *   @0x2f9958 andvs r6, r3, #3194880
 *   @0x2f995c ldrblt r4, [r0, #0x770]!
 *   @0x2f9960 strhpl pc, [lr, -r0]!
 *   @0x2f9964 mulsmi r4, sp, r8
 *   @0x2f9968 stmdavs r7, {r0, r2, r5, r7, r8, r12, sp, pc}
 *   @0x2f996c stcvs p14, c6, [sp], #-244
 *   @0x2f9970 .word 0xd1022d28
 *   @0x2f9974 rsbpl pc, r7, #144, #16
 *   @0x2f9978 svcvs #0xc5b92d
 *   @0x2f997c eorsvs pc, r1, r5, asr r8
 *   @0x2f9980 .word 0xf8454416
 *   @0x2f9984 .word 0xb12c6031
 *   @0x2f9988 .word 0x2084f8d0
 *   @0x2f998c .word 0xf0455c55
 *   @0x2f9990 ldrbpl r0, [r5], #-1288
 *   @0x2f9994 ldrhhs pc, [r0, -r0]!
 *   @0x2f9998 stmdavs r2, {r1, r4, r6, r7, r8, r12, sp, pc}
 *   @0x2f999c .word 0x6c126e12
 *   @0x2f99a0 .word 0xd1082a28
 *   @0x2f99a4 rsbhs pc, r7, #144, #16
 *   @0x2f99a8 .word 0xf890b12a
 *   @0x2f99ac tstlt r2, r8, ror #4
 *   @0x2f99b0 rsbhs pc, r9, #144, #16
 *   @0x2f99b4 svcvs #0xc2b92a
 *   @0x2f99b8 sbceq lr, r1, #2048
 *   @0x2f99bc ldrmi r6, [sp], #-2133
 *   @0x2f99c0 qsublt r6, r5, r12
 *   @0x2f99c4 .word 0x3084f8d0
 *   @0x2f99c8 .word 0xf0425c5a
 *   @0x2f99cc ldrbpl r0, [r10], #-528
 *   @0x2f99d0 push {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x2f99d4 .word 0x460441f3
 *   @0x2f99d8 ldrhlo pc, [r12, #-128]
 *   @0x2f99dc .word 0xb14b460e
 *   @0x2f99e0 ldrhlo pc, [lr, #-128]
 *   @0x2f99e4 rfeia r0!
 *   @0x2f99e8 .word 0xf1d55160
 *   @0x2f99ec svclt #0x380501
 *   @0x2f99f0 and r2, r0, r0, lsl #10
 *   @0x2f99f4 .word 0xf8d42501
 *   @0x2f99f8 stmdbvs r3!, {r2, r4, r5, r8, sp}
 *   @0x2f99fc blle 0x48a46c <prim_v+0xab8>
 *   @0x2f9a00 eorslo pc, r5, #148, #16
 *   @0x2f9a04 suble r2, lr, r0, lsl #22
 *   @0x2f9a08 rscvs r2, r3, r6, lsl #7
 *   @0x2f9a0c ldmdavs r0!, {r0, r1, r3, r6, sp, lr, pc}
 *   @0x2f9a10 rfeib r4!
 *   @0x2f9a14 strhs r1, [r1, -lr, lsr #2]
 *   @0x2f9a18 mcrr2 p7, #0xf, pc, r0, c15
 *   @0x2f9a1c ldrhne pc, [r0, -r4]!
 *   @0x2f9a20 ldmdavs r0!, {r7, r9, r10, lr}
 *   @0x2f9a24 ldc2 p7, c15, [r10], #-1020
 *   @0x2f9a28 .word 0xf8d44606
 *   @0x2f9a2c blhs 0x305f04 <TT_New_Context+0x5cfc>
 *   @0x2f9a30 stmibvs r3!, {r0, r3, r4, r5, r8, r10, r11, r12, lr, pc} ^
 *   @0x2f9a34 bllo 0x3540c4
 *   @0x2f9a38 rfeda r2!
 *   @0x2f9a3c rfeia r4!
 *   @0x2f9a40 addmi r3, r11, #116
 *   @0x2f9a44 .word 0xf894d805
 *   @0x2f9a48 teqlt r3, #1342177283
 *   @0x2f9a4c rscvs r2, r3, r6, lsl #7
 *   @0x2f9a50 stmdavs r3!, {r1, r2, r3, r5, sp, lr, pc}
 *   @0x2f9a54 .word 0x6c1b6e1b
 *   @0x2f9a58 tstle r8, r8, lsr #22
 *   @0x2f9a5c rsblo pc, r7, #148, #16
 *   @0x2f9a60 stmiblt r5, {r0, r1, r3, r5, r7, r8, r12, sp, pc}
 *   @0x2f9a64 rsblo pc, r8, #148, #16
 *   @0x2f9a68 .word 0xf894b113
 *   @0x2f9a6c stmiblt r3!, {r0, r3, r5, r6, r9, r12, sp}
 *   @0x2f9a70 eorslo pc, r4, #148, #16
 *   @0x2f9a74 rfeib r4!
 *   @0x2f9a78 stmdblt r3!, {r4, r5, r8, r12, sp}
 *   @0x2f9a7c .word 0x3084f8d4
 *   @0x2f9a80 .word 0x06db5c5b
 *   @0x2f9a84 strls sp, [r0, -r9, lsl #10]
 *   @0x2f9a88 andhs r4, r0, #32, #12
 *   @0x2f9a8c strtmi lr, [r0], -r2
 *   @0x2f9a90 strls r4, [r0, -r2, asr #12]
 *   @0x2f9a94 .word 0xf7ff4633
 *   @0x2f9a98 .word 0xf8d4ff62
 *   @0x2f9a9c bllo 0x345f74
 *   @0x2f9aa0 teqlo r4, r4, asr #17
 *   @0x2f9aa4 movwhs lr, #0x17c1
 *   @0x2f9aa8 teqlo r4, r4, asr #17
 *   @0x2f9aac eorvs r6, r3, #3719168
 *   @0x2f9ab0 pop {r1, r12, sp, pc}
 *
 * ══ §7/16 CFontGM::Draw_String_Transformed(float, float, unsigned short*, float, float, float, unsigned int, float)  0xf830c  size 2040  510 条（0xf830c..0xf8b04）
 * @func 0xf830c 0xf8b04  size 2040  510 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::Draw_String_Transformed(float, float, unsigned short*, float, float, float, unsigned int, float)+0xd4×4 / CFontGM::GetGlyph(int)×4 / Sprite_Exists(int)×2 / Sprite_Data(int)×2 / CSprite::Draw(int, float, float, float, float, float, unsigned int, float)×2 / Graphics::AllocVerts(ePrimType, void*, int, int)×2 / yywcslen(unsigned short const*) / CFontGM::Draw_String_Transformed(float, float, unsigned short*, float, float, float, unsigned int, float)+0x1d0
 * 字段偏移 top8: 0x20×8 / 0x3c×6 / 0x4×6 / 0x2×6 / 0x24×6 / 0x38×6 / 0xc×4 / 0x84×3
 * VFP 指令 242 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf830c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf8310 vpush {d8, d9, d10, d11, d12}
 *   @0xf8314 sub sp, sp, #44
 *   @0xf8318 vldr s25, [sp, #136]
 *   @0xf831c mov r6, r0
 *   @0xf8320 mov r0, r3
 *   @0xf8324 mov r5, r3
 *   @0xf8328 vmov s16, r1
 *   @0xf832c vldr s18, [sp, #120]
 *   @0xf8330 vmov s17, r2
 *   @0xf8334 vldr s19, [sp, #124]
 *   @0xf8338 vldr s24, [sp, #128]
 *   @0xf833c ldr r11, [sp, #0x84]
 *   @0xf8340 bl 0xf6c78 <_Z8yywcslenPKt>
 *   @0xf8344 vldr s15, [pc, #996]
 *   @0xf8348 vmul.f32 s15, s25, s15
 *   @0xf834c ldr r8, [pc, #0x3e8]
 *   @0xf8350 add r8, pc, r8
 *   @0xf8354 vcvt.s32.f32 s15, s15
 *   @0xf8358 vmov r7, s15
 *   @0xf835c mov r4, r0
 *   @0xf8360 cmp r7, #255
 *   @0xf8364 movgt r7, #-16777216
 *   @0xf8368 bgt 0xf8378 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x6c>
 *   @0xf836c cmp r7, #0
 *   @0xf8370 lslge r7, r7, #24
 *   @0xf8374 movlt r7, #0
 *   @0xf8378 ldr r3, [pc, #0x3c0]
 *   @0xf837c vabs.f32 s14, s24
 *   @0xf8380 orr r7, r7, r11
 *   @0xf8384 vldr s15, [pc, #936]
 *   @0xf8388 ldr r3, [r8, r3]
 *   @0xf838c vcmpe.f32 s14, s15
 *   @0xf8390 ldrb r3, [r3]
 *   @0xf8394 cmp r3, #0
 *   @0xf8398 streq r7, [sp, #0x20]
 *   @0xf839c bicne r7, r7, #65536
 *   @0xf83a0 streq r7, [sp, #0x1c]
 *   @0xf83a4 bicne r7, r7, #1
 *   @0xf83a8 moveq r9, r7
 *   @0xf83ac orrne r9, r7, #65536
 *   @0xf83b0 orrne r12, r7, #1
 *   @0xf83b4 strne r12, [sp, #0x1c]
 *   @0xf83b8 orrne r12, r9, #1
 *   @0xf83bc strne r12, [sp, #0x20]
 *   @0xf83c0 vmrs APSR_nzcv, fpscr
 *   @0xf83c4 bpl 0xf83ec <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xe0>
 *   @0xf83c8 ldr r0, [r6, #0x20]
 *   @0xf83cc cmp r0, #0
 *   @0xf83d0 blt 0xf84dc <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x1d0>
 *   @0xf83d4 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0xf83d8 cmp r0, #0
 *   @0xf83dc bne 0xf8960 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x654>
 *   @0xf83e0 add sp, sp, #44
 *   @0xf83e4 vpop {d8, d9, d10, d11, d12}
 *   @0xf83e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf83ec vldr s21, [pc, #836]
 *   @0xf83f0 vmul.f32 s21, s24, s21
 *   @0xf83f4 vmov r0, s21
 *   @0xf83f8 bl 0xb6580 <sinf@plt>
 *   @0xf83fc vmov s20, r0
 *   @0xf8400 vmov r0, s21
 *   @0xf8404 bl 0xb658c <cosf@plt>
 *   @0xf8408 vmul.f32 s22, s20, s18
 *   @0xf840c vmov s21, r0
 *   @0xf8410 ldr r0, [r6, #0x20]
 *   @0xf8414 cmp r0, #0
 *   @0xf8418 vmul.f32 s23, s21, s18
 *   @0xf841c blt 0xf86f0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x3e4>
 *   @0xf8420 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0xf8424 cmp r0, #0
 *   @0xf8428 beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4>
 *   @0xf842c ldr r0, [r6, #0x20]
 *   @0xf8430 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0xf8434 cmp r4, #0
 *   @0xf8438 mov r9, r0
 *   @0xf843c ble 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4>
 *   @0xf8440 lsl r4, r4, #1
 *   @0xf8444 mov r7, #0
 *   @0xf8448 b 0xf8458 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x14c>
 *   @0xf844c add r7, r7, #2
 *   @0xf8450 cmp r7, r4
 *   @0xf8454 beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4>
 *   @0xf8458 ldrh r8, [r5, r7]
 *   @0xf845c cmp r8, #0
 *   @0xf8460 beq 0xf844c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x140>
 *   @0xf8464 mov r0, r6
 *   @0xf8468 mov r1, r8
 *   @0xf846c bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi>
 *   @0xf8470 subs r10, r0, #0
 *   @0xf8474 mov r0, r9
 *   @0xf8478 beq 0xf844c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x140>
 *   @0xf847c cmp r8, #32
 *   @0xf8480 beq 0xf84c4 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x1b8>
 *   @0xf8484 ldrsh r12, [r10, #12]
 *   @0xf8488 vmov.f32 s8, s16
 *   @0xf848c ldrsh r1, [r10, #6]
 *   @0xf8490 vstr s18, [sp]
 *   @0xf8494 vstr s19, [sp, #4]
 *   @0xf8498 vstr s24, [sp, #8]
 *   @0xf849c vmov s15, r12
 *   @0xf84a0 str r11, [sp, #0xc]
 *   @0xf84a4 vmov.f32 s14, s17
 *   @0xf84a8 vstr s25, [sp, #16]
 *   @0xf84ac vcvt.f32.s32 s15, s15
 *   @0xf84b0 vmla.f32 s8, s15, s23
 *   @0xf84b4 vmls.f32 s14, s22, s15
 *   @0xf84b8 vmov r2, s8
 *   @0xf84bc vmov r3, s14
 *   @0xf84c0 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf>
 *   @0xf84c4 ldrsh r10, [r10, #10]
 *   @0xf84c8 vmov s15, r10
 *   @0xf84cc vcvt.f32.s32 s15, s15
 *   @0xf84d0 vmla.f32 s16, s15, s23
 *   @0xf84d4 vmls.f32 s17, s22, s15
 *   @0xf84d8 b 0xf844c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x140>
 *   @0xf84dc ldr r3, [r6, #0x3c]
 *   @0xf84e0 cmp r3, #0
 *   @0xf84e4 beq 0xf8aec <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x7e0>
 *   @0xf84e8 ldr r1, [pc, #0x258]
 *   @0xf84ec ldrsh r2, [r3, #20]
 *   @0xf84f0 mov r3, r1
 *   @0xf84f4 ldr r3, [r8, r3]
 *   @0xf84f8 ldr r3, [r3, #0x4]
 *   @0xf84fc ldr r3, [r3, r2, lsl #2]
 *   @0xf8500 ldr r3, [r3]
 *   @0xf8504 str r3, [sp, #0x24]
 *   @0xf8508 cmp r4, #0
 *   @0xf850c ble 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4>
 *   @0xf8510 lsl r10, r4, #1
 *   @0xf8514 mov r4, #0
 *   @0xf8518 b 0xf8528 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x21c>
 *   @0xf851c add r4, r4, #2
 *   @0xf8520 cmp r4, r10
 *   @0xf8524 beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4>
 *   @0xf8528 ldrh r1, [r5, r4]
 *   @0xf852c cmp r1, #0
 *   @0xf8530 beq 0xf851c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x210>
 *   @0xf8534 mov r0, r6
 *   @0xf8538 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi>
 *   @0xf853c subs r11, r0, #0
 *   @0xf8540 beq 0xf851c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x210>
 *   @0xf8544 mov r0, #4
 *   @0xf8548 ldr r1, [sp, #0x24]
 *   @0xf854c mov r2, #24
 *   @0xf8550 mov r3, #6
 *   @0xf8554 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0xf8558 cmp r0, #0
 *   @0xf855c beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4>
 *   @0xf8560 ldrsh r2, [r11, #12]
 *   @0xf8564 vmov.f32 s13, s16
 *   @0xf8568 vldr s15, [r6, #80]
 *   @0xf856c ldrsh r3, [r11, #6]
 *   @0xf8570 ldrsh r12, [r11, #8]
 *   @0xf8574 vmov s12, r2
 *   @0xf8578 ldrsh r1, [r11, #2]
 *   @0xf857c vsub.f32 s14, s17, s15
 *   @0xf8580 ldr r2, [r6, #0x3c]
 *   @0xf8584 vmov s10, r3
 *   @0xf8588 ldr r3, [pc, #0x1b4]
 *   @0xf858c vmov s11, r12
 *   @0xf8590 ldrsh r12, [r11, #4]
 *   @0xf8594 vmov s8, r1
 *   @0xf8598 cmp r2, #0
 *   @0xf859c vcvt.f32.s32 s12, s12
 *   @0xf85a0 vstr s14, [r0, #124]
 *   @0xf85a4 vstr s14, [r0, #4]
 *   @0xf85a8 vstr s14, [r0, #28]
 *   @0xf85ac vmla.f32 s13, s12, s18
 *   @0xf85b0 vcvt.f32.s32 s10, s10
 *   @0xf85b4 vcvt.f32.s32 s11, s11
 *   @0xf85b8 vmov.f32 s9, s13
 *   @0xf85bc vmov.f32 s14, s17
 *   @0xf85c0 vmla.f32 s9, s10, s18
 *   @0xf85c4 vmla.f32 s14, s11, s19
 *   @0xf85c8 vadd.f32 s12, s15, s9
 *   @0xf85cc vmov s9, r12
 *   @0xf85d0 ldr r12, [sp, #0x1c]
 *   @0xf85d4 vadd.f32 s14, s15, s14
 *   @0xf85d8 vstr s12, [r0, #24]
 *   @0xf85dc vstr s12, [r0, #72]
 *   @0xf85e0 vstr s12, [r0, #48]
 *   @0xf85e4 vsub.f32 s13, s13, s15
 *   @0xf85e8 vstr s14, [r0, #76]
 *   @0xf85ec vstr s14, [r0, #52]
 *   @0xf85f0 vstr s14, [r0, #100]
 *   @0xf85f4 vstr s13, [r0, #120]
 *   @0xf85f8 vstr s13, [r0]
 *   @0xf85fc vstr s13, [r0, #96]
 *   @0xf8600 ldr r3, [r8, r3]
 *   @0xf8604 str r12, [r0, #0x24]
 *   @0xf8608 vcvt.f32.s32 s12, s8
 *   @0xf860c ldr r12, [sp, #0x20]
 *   @0xf8610 ldr r3, [r3]
 *   @0xf8614 str r7, [r0, #0xc]
 *   @0xf8618 str r7, [r0, #0x84]
 *   @0xf861c str r3, [r0, #0x80]
 *   @0xf8620 str r3, [r0, #0x68]
 *   @0xf8624 str r3, [r0, #0x50]
 *   @0xf8628 vcvt.f32.s32 s14, s9
 *   @0xf862c str r3, [r0, #0x38]
 *   @0xf8630 str r3, [r0, #0x20]
 *   @0xf8634 str r3, [r0, #0x8]
 *   @0xf8638 str r9, [r0, #0x3c]
 *   @0xf863c str r9, [r0, #0x54]
 *   @0xf8640 str r12, [r0, #0x6c]
 *   @0xf8644 beq 0xf8a6c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x760>
 *   @0xf8648 ldrsh r3, [r2]
 *   @0xf864c ldrsh r1, [r2, #20]
 *   @0xf8650 vmov s13, r3
 *   @0xf8654 ldr r3, [pc, #0xec]
 *   @0xf8658 vcvt.f32.s32 s13, s13
 *   @0xf865c ldr r3, [r8, r3]
 *   @0xf8660 ldr r3, [r3, #0x4]
 *   @0xf8664 vadd.f32 s13, s13, s12
 *   @0xf8668 ldr r3, [r3, r1, lsl #2]
 *   @0xf866c vldr s9, [r3, #8]
 *   @0xf8670 vsub.f32 s12, s13, s15
 *   @0xf8674 vmul.f32 s12, s12, s9
 *   @0xf8678 vstr s12, [r0, #16]
 *   @0xf867c vstr s12, [r0, #112]
 *   @0xf8680 vstr s12, [r0, #136]
 *   @0xf8684 ldrsh r2, [r2, #2]
 *   @0xf8688 vadd.f32 s13, s10, s13
 *   @0xf868c vldr s12, [r3, #12]
 *   @0xf8690 vmov s8, r2
 *   @0xf8694 vcvt.f32.s32 s8, s8
 *   @0xf8698 vadd.f32 s8, s8, s14
 *   @0xf869c vadd.f32 s14, s11, s8
 *   @0xf86a0 vadd.f32 s13, s15, s13
 *   @0xf86a4 vadd.f32 s14, s15, s14
 *   @0xf86a8 vsub.f32 s15, s8, s15
 *   @0xf86ac vmul.f32 s13, s9, s13
 *   @0xf86b0 vmul.f32 s14, s12, s14
 *   @0xf86b4 vstr s13, [r0, #40]
 *   @0xf86b8 vstr s13, [r0, #64]
 *   @0xf86bc vstr s13, [r0, #88]
 *   @0xf86c0 vmul.f32 s15, s15, s12
 *   @0xf86c4 vstr s14, [r0, #68]
 *   @0xf86c8 vstr s14, [r0, #92]
 *   @0xf86cc vstr s14, [r0, #116]
 *   @0xf86d0 vstr s15, [r0, #20]
 *   @0xf86d4 vstr s15, [r0, #44]
 *   @0xf86d8 vstr s15, [r0, #140]
 *   @0xf86dc ldrsh r11, [r11, #10]
 *   @0xf86e0 vmov s15, r11
 *   @0xf86e4 vcvt.f32.s32 s15, s15
 *   @0xf86e8 vmla.f32 s16, s15, s18
 *   @0xf86ec b 0xf851c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x210>
 *   @0xf86f0 ldr r3, [r6, #0x3c]
 *   @0xf86f4 cmp r3, #0
 *   @0xf86f8 beq 0xf8ad4 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x7c8>
 *   @0xf86fc ldr r1, [pc, #0x44]
 *   @0xf8700 ldrsh r2, [r3, #20]
 *   @0xf8704 mov r3, r1
 *   @0xf8708 ldr r3, [r8, r3]
 *   @0xf870c ldr r3, [r3, #0x4]
 *   @0xf8710 ldr r3, [r3, r2, lsl #2]
 *   @0xf8714 ldr r3, [r3]
 *   @0xf8718 str r3, [sp, #0x24]
 *   @0xf871c cmp r4, #0
 *   @0xf8720 ble 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4>
 *   @0xf8724 lsl r10, r4, #1
 *   @0xf8728 mov r4, #0
 *   @0xf872c b 0xf8758 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x44c>
 *   @0xf8730 cmnmi pc, #0
 *   @0xf8734 blo 0xfe1bd0f8 <b2_toiTime+0xfffffffffda63c54>
 *   @0xf8738 vstmialo lr, {s30, s31}
 *   @0xf873c eoreq r9, pc, r0, lsl #18
 *   @0xf8740 .word 0xffffc1fc
 *   @0xf8744 .word 0xffffbcd0
 *   @0xf8748 .word 0xffffbccc
 *   @0xf874c add r4, r4, #2
 *   @0xf8750 cmp r4, r10
 *   @0xf8754 beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4>
 *   @0xf8758 ldrh r1, [r5, r4]
 *   @0xf875c cmp r1, #0
 *   @0xf8760 beq 0xf874c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x440>
 *   @0xf8764 mov r0, r6
 *   @0xf8768 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi>
 *   @0xf876c subs r11, r0, #0
 *   @0xf8770 beq 0xf874c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x440>
 *   @0xf8774 mov r0, #4
 *   @0xf8778 ldr r1, [sp, #0x24]
 *   @0xf877c mov r2, #24
 *   @0xf8780 mov r3, #6
 *   @0xf8784 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0xf8788 cmp r0, #0
 *   @0xf878c beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4>
 *   @0xf8790 ldrsh r2, [r11, #12]
 *   @0xf8794 vmov.f32 s14, s17
 *   @0xf8798 ldrsh r3, [r11, #6]
 *   @0xf879c vldr s15, [r6, #80]
 *   @0xf87a0 ldrsh r12, [r11, #8]
 *   @0xf87a4 vmov s12, r2
 *   @0xf87a8 ldrsh r1, [r11, #2]
 *   @0xf87ac vmov.f32 s13, s16
 *   @0xf87b0 ldr r2, [r6, #0x3c]
 *   @0xf87b4 vmov s10, r3
 *   @0xf87b8 ldr r3, [pc, #-0x7c]
 *   @0xf87bc vmov s11, r12
 *   @0xf87c0 ldrsh r12, [r11, #4]
 *   @0xf87c4 cmp r2, #0
 *   @0xf87c8 vcvt.f32.s32 s12, s12
 *   @0xf87cc vmls.f32 s14, s22, s12
 *   @0xf87d0 vmla.f32 s13, s12, s23
 *   @0xf87d4 vcvt.f32.s32 s10, s10
 *   @0xf87d8 vmul.f32 s12, s18, s10
 *   @0xf87dc vcvt.f32.s32 s11, s11
 *   @0xf87e0 vmov.f32 s8, s14
 *   @0xf87e4 vmov.f32 s9, s13
 *   @0xf87e8 vmls.f32 s8, s20, s12
 *   @0xf87ec vmul.f32 s7, s19, s11
 *   @0xf87f0 vmla.f32 s9, s12, s21
 *   @0xf87f4 vmul.f32 s6, s20, s7
 *   @0xf87f8 vmul.f32 s7, s7, s21
 *   @0xf87fc vmov.f32 s12, s8
 *   @0xf8800 vadd.f32 s8, s6, s9
 *   @0xf8804 vadd.f32 s5, s7, s12
 *   @0xf8808 vadd.f32 s6, s13, s6
 *   @0xf880c vadd.f32 s7, s14, s7
 *   @0xf8810 vsub.f32 s13, s13, s15
 *   @0xf8814 vsub.f32 s9, s9, s15
 *   @0xf8818 vstr s13, [r0, #120]
 *   @0xf881c vstr s13, [r0]
 *   @0xf8820 vadd.f32 s8, s15, s8
 *   @0xf8824 vstr s9, [r0, #24]
 *   @0xf8828 vadd.f32 s13, s15, s5
 *   @0xf882c vstr s8, [r0, #72]
 *   @0xf8830 vstr s8, [r0, #48]
 *   @0xf8834 vmov s8, r1
 *   @0xf8838 vsub.f32 s14, s14, s15
 *   @0xf883c vstr s13, [r0, #76]
 *   @0xf8840 vstr s13, [r0, #52]
 *   @0xf8844 vmov s13, r12
 *   @0xf8848 ldr r12, [sp, #0x1c]
 *   @0xf884c vsub.f32 s9, s12, s15
 *   @0xf8850 vstr s14, [r0, #124]
 *   @0xf8854 vstr s14, [r0, #4]
 *   @0xf8858 vadd.f32 s6, s15, s6
 *   @0xf885c vstr s9, [r0, #28]
 *   @0xf8860 vadd.f32 s7, s15, s7
 *   @0xf8864 vstr s6, [r0, #96]
 *   @0xf8868 vstr s7, [r0, #100]
 *   @0xf886c ldr r3, [r8, r3]
 *   @0xf8870 str r12, [r0, #0x24]
 *   @0xf8874 vcvt.f32.s32 s12, s8
 *   @0xf8878 ldr r12, [sp, #0x20]
 *   @0xf887c ldr r3, [r3]
 *   @0xf8880 str r7, [r0, #0xc]
 *   @0xf8884 str r7, [r0, #0x84]
 *   @0xf8888 str r3, [r0, #0x80]
 *   @0xf888c str r3, [r0, #0x68]
 *   @0xf8890 str r3, [r0, #0x50]
 *   @0xf8894 vcvt.f32.s32 s14, s13
 *   @0xf8898 str r3, [r0, #0x38]
 *   @0xf889c str r3, [r0, #0x20]
 *   @0xf88a0 str r3, [r0, #0x8]
 *   @0xf88a4 str r9, [r0, #0x3c]
 *   @0xf88a8 str r9, [r0, #0x54]
 *   @0xf88ac str r12, [r0, #0x6c]
 *   @0xf88b0 beq 0xf8a04 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x6f8>
 *   @0xf88b4 ldrsh r3, [r2]
 *   @0xf88b8 ldrsh r1, [r2, #20]
 *   @0xf88bc vmov s13, r3
 *   @0xf88c0 ldr r3, [pc, #-0x180]
 *   @0xf88c4 vcvt.f32.s32 s13, s13
 *   @0xf88c8 ldr r3, [r8, r3]
 *   @0xf88cc ldr r3, [r3, #0x4]
 *   @0xf88d0 vadd.f32 s13, s13, s12
 *   @0xf88d4 ldr r3, [r3, r1, lsl #2]
 *   @0xf88d8 vldr s9, [r3, #8]
 *   @0xf88dc vsub.f32 s12, s13, s15
 *   @0xf88e0 vmul.f32 s12, s12, s9
 *   @0xf88e4 vstr s12, [r0, #16]
 *   @0xf88e8 vstr s12, [r0, #112]
 *   @0xf88ec vstr s12, [r0, #136]
 *   @0xf88f0 ldrsh r2, [r2, #2]
 *   @0xf88f4 vadd.f32 s13, s10, s13
 *   @0xf88f8 vldr s12, [r3, #12]
 *   @0xf88fc vmov s8, r2
 *   @0xf8900 vcvt.f32.s32 s8, s8
 *   @0xf8904 vadd.f32 s8, s8, s14
 *   @0xf8908 vadd.f32 s14, s11, s8
 *   @0xf890c vadd.f32 s13, s15, s13
 *   @0xf8910 vadd.f32 s14, s15, s14
 *   @0xf8914 vsub.f32 s15, s8, s15
 *   @0xf8918 vmul.f32 s13, s9, s13
 *   @0xf891c vmul.f32 s14, s12, s14
 *   @0xf8920 vstr s13, [r0, #40]
 *   @0xf8924 vstr s13, [r0, #64]
 *   @0xf8928 vstr s13, [r0, #88]
 *   @0xf892c vmul.f32 s15, s15, s12
 *   @0xf8930 vstr s14, [r0, #68]
 *   @0xf8934 vstr s14, [r0, #92]
 *   @0xf8938 vstr s14, [r0, #116]
 *   @0xf893c vstr s15, [r0, #20]
 *   @0xf8940 vstr s15, [r0, #44]
 *   @0xf8944 vstr s15, [r0, #140]
 *   @0xf8948 ldrsh r11, [r11, #10]
 *   @0xf894c vmov s15, r11
 *   @0xf8950 vcvt.f32.s32 s15, s15
 *   @0xf8954 vmla.f32 s16, s15, s23
 *   @0xf8958 vmls.f32 s17, s22, s15
 *   @0xf895c b 0xf874c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x440>
 *   @0xf8960 ldr r0, [r6, #0x20]
 *   @0xf8964 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0xf8968 cmp r4, #0
 *   @0xf896c mov r9, r0
 *   @0xf8970 ble 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4>
 *   @0xf8974 lsl r4, r4, #1
 *   @0xf8978 mov r7, #0
 *   @0xf897c b 0xf898c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x680>
 *   @0xf8980 add r7, r7, #2
 *   @0xf8984 cmp r7, r4
 *   @0xf8988 beq 0xf83e0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0xd4>
 *   @0xf898c ldrh r8, [r5, r7]
 *   @0xf8990 cmp r8, #0
 *   @0xf8994 beq 0xf8980 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x674>
 *   @0xf8998 mov r0, r6
 *   @0xf899c mov r1, r8
 *   @0xf89a0 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi>
 *   @0xf89a4 vmov r3, s17
 *   @0xf89a8 subs r10, r0, #0
 *   @0xf89ac mov r0, r9
 *   @0xf89b0 beq 0xf8980 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x674>
 *   @0xf89b4 cmp r8, #32
 *   @0xf89b8 beq 0xf89f0 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x6e4>
 *   @0xf89bc ldrsh r2, [r10, #12]
 *   @0xf89c0 vmov.f32 s8, s16
 *   @0xf89c4 ldrsh r1, [r10, #6]
 *   @0xf89c8 vstr s18, [sp]
 *   @0xf89cc vstr s19, [sp, #4]
 *   @0xf89d0 vstr s24, [sp, #8]
 *   @0xf89d4 vmov s15, r2
 *   @0xf89d8 str r11, [sp, #0xc]
 *   @0xf89dc vstr s25, [sp, #16]
 *   @0xf89e0 vcvt.f32.s32 s15, s15
 *   @0xf89e4 vmla.f32 s8, s15, s18
 *   @0xf89e8 vmov r2, s8
 *   @0xf89ec bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf>
 *   @0xf89f0 ldrsh r10, [r10, #10]
 *   @0xf89f4 vmov s15, r10
 *   @0xf89f8 vcvt.f32.s32 s15, s15
 *   @0xf89fc vmla.f32 s16, s15, s18
 *   @0xf8a00 b 0xf8980 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x674>
 *   @0xf8a04 ldr r3, [pc, #-0x2c4]
 *   @0xf8a08 vadd.f32 s10, s12, s10
 *   @0xf8a0c ldr r2, [r6, #0x38]
 *   @0xf8a10 ldr r3, [r8, r3]
 *   @0xf8a14 ldr r3, [r3, #0x4]
 *   @0xf8a18 ldr r3, [r3, r2, lsl #2]
 *   @0xf8a1c vldr s13, [r3, #8]
 *   @0xf8a20 vmul.f32 s12, s13, s12
 *   @0xf8a24 vadd.f32 s11, s14, s11
 *   @0xf8a28 vstr s12, [r0, #16]
 *   @0xf8a2c vstr s12, [r0, #112]
 *   @0xf8a30 vstr s12, [r0, #136]
 *   @0xf8a34 vldr s15, [r3, #12]
 *   @0xf8a38 vmul.f32 s10, s13, s10
 *   @0xf8a3c vmul.f32 s14, s15, s14
 *   @0xf8a40 vstr s10, [r0, #40]
 *   @0xf8a44 vstr s10, [r0, #64]
 *   @0xf8a48 vstr s10, [r0, #88]
 *   @0xf8a4c vmul.f32 s11, s15, s11
 *   @0xf8a50 vstr s14, [r0, #20]
 *   @0xf8a54 vstr s14, [r0, #44]
 *   @0xf8a58 vstr s14, [r0, #140]
 *   @0xf8a5c vstr s11, [r0, #68]
 *   @0xf8a60 vstr s11, [r0, #92]
 *   @0xf8a64 vstr s11, [r0, #116]
 *   @0xf8a68 b 0xf8948 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x63c>
 *   @0xf8a6c ldr r3, [pc, #-0x32c]
 *   @0xf8a70 vadd.f32 s10, s10, s12
 *   @0xf8a74 ldr r2, [r6, #0x38]
 *   @0xf8a78 ldr r3, [r8, r3]
 *   @0xf8a7c ldr r3, [r3, #0x4]
 *   @0xf8a80 ldr r3, [r3, r2, lsl #2]
 *   @0xf8a84 vldr s13, [r3, #8]
 *   @0xf8a88 vmul.f32 s12, s13, s12
 *   @0xf8a8c vadd.f32 s11, s11, s14
 *   @0xf8a90 vstr s12, [r0, #16]
 *   @0xf8a94 vstr s12, [r0, #112]
 *   @0xf8a98 vstr s12, [r0, #136]
 *   @0xf8a9c vldr s15, [r3, #12]
 *   @0xf8aa0 vmul.f32 s10, s13, s10
 *   @0xf8aa4 vmul.f32 s14, s15, s14
 *   @0xf8aa8 vstr s10, [r0, #40]
 *   @0xf8aac vstr s10, [r0, #64]
 *   @0xf8ab0 vstr s10, [r0, #88]
 *   @0xf8ab4 vmul.f32 s11, s15, s11
 *   @0xf8ab8 vstr s14, [r0, #20]
 *   @0xf8abc vstr s14, [r0, #44]
 *   @0xf8ac0 vstr s14, [r0, #140]
 *   @0xf8ac4 vstr s11, [r0, #68]
 *   @0xf8ac8 vstr s11, [r0, #92]
 *   @0xf8acc vstr s11, [r0, #116]
 *   @0xf8ad0 b 0xf86dc <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x3d0>
 *   @0xf8ad4 ldr r2, [r6, #0x38]
 *   @0xf8ad8 cmp r2, #0
 *   @0xf8adc strlt r3, [sp, #0x24]
 *   @0xf8ae0 blt 0xf871c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x410>
 *   @0xf8ae4 ldr r3, [pc, #-0x3a4]
 *   @0xf8ae8 b 0xf8708 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x3fc>
 *   @0xf8aec ldr r2, [r6, #0x38]
 *   @0xf8af0 cmp r2, #0
 *   @0xf8af4 strlt r3, [sp, #0x24]
 *   @0xf8af8 blt 0xf8508 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x1fc>
 *   @0xf8afc ldr r3, [pc, #-0x3bc]
 *   @0xf8b00 b 0xf84f4 <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf+0x1e8>
 *
 * ══ §8/16 zip_close  0x2a31ec  size 1968  492 条（0x2a31ec..0x2a399c）
 * @func 0x2a31ec 0x2a399c  size 1968  492 条
 * 部分覆盖: 本节 492/877 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _zip_error_set(zip_error*, int, int)×4 / zip_get_archive_flag×3 / 0xb6ee0×3 / 0xb655c×3 / _zip_free(zip*)×2 / 0xb6544×2 / _zip_memdup(void const*, unsigned int, zip_error*)×2 / 0xb6bf8×2
 * 字段偏移 top8: 0x10×12 / 0x1c×10 / 0x18×7 / 0x4×7 / 0x8×7 / 0x34×7 / 0x14×6 / 0x20×5
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a31ec ldr.w r3, [pc, #0x78c]
 *   @0x2a31f0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a31f4 add r3, pc
 *   @0x2a31f8 sub sp, #0xa4
 *   @0x2a31fc ldr r2, [r3]
 *   @0x2a3200 str r2, [sp, #0x9c]
 *   @0x2a3204 beq.w 0x2a38e2 <zip_close+0x6f6>
 *   @0x2a3208 ldr r3, [r0, #0x28]
 *   @0x2a320c bne 0x2a321a <zip_close+0x2e>
 *   @0x2a3210 ldr r3, [r0, #0x18]
 *   @0x2a3214 it ne
 *   @0x2a3218 b 0x2a321c <zip_close+0x30>
 *   @0x2a321c ldr r5, [r4, #0x2c]
 *   @0x2a3220 mov r2, r1
 *   @0x2a3224 str r1, [sp, #0x1c]
 *   @0x2a3228 bge 0x2a3256 <zip_close+0x6a>
 *   @0x2a322c blvs 0x1adf63c <b2_toiTime+0x1386198>
 *   @0x2a3230 adds r7, r0, r1
 *   @0x2a3234 cbnz r1, 0x2a3242 <zip_close+0x56>
 *   @0x2a3238 cmp.w r1, #0xffffffff
 *   @0x2a323c it ne
 *   @0x2a3240 b 0x2a3248 <zip_close+0x5c>
 *   @0x2a3244 beq 0x2a3250 <zip_close+0x64>
 *   @0x2a3248 ldr r1, [sp, #0x1c]
 *   @0x2a324c str r1, [sp, #0x1c]
 *   @0x2a3250 mov r3, r1
 *   @0x2a3254 b 0x2a3226 <zip_close+0x3a>
 *   @0x2a3258 mov r0, r4
 *   @0x2a325c bl 0x2a4884 <_Z9_zip_freeP3zip>
 *   @0x2a3260 b 0x2a393e <zip_close+0x752>
 *   @0x2a3264 cbnz r2, 0x2a3290 <zip_close+0xa4>
 *   @0x2a3268 cmp r0, #0x0
 *   @0x2a326c ldr r3, [r4, #0x4]
 *   @0x2a3270 ldr r3, [r4, #0x8]
 *   @0x2a3274 beq 0x2a3258 <zip_close+0x6c>
 *   @0x2a3278 stmdahs r0, {r2, r3, r4, r5, r6, r8, r9, r11, sp, lr, pc}
 *   @0x2a327c beq 0x2a3258 <zip_close+0x6c>
 *   @0x2a3280 ldrhhs lr, [r6, -r12]
 *   @0x2a3284 ldr r2, [r0]
 *   @0x2a3288 .word 0xf001000c
 *   @0x2a328c msr APSR_nzcvq, #6619136
 *   @0x2a3290 ldr r3, [sp, #0x1c]
 *   @0x2a3294 blx 0xb6544 <malloc@plt>
 *   @0x2a3298 str r0, [sp, #0x10]
 *   @0x2a329c beq.w 0x2a38e2 <zip_close+0x6f6>
 *   @0x2a32a0 add.w r6, r4, #0xc
 *   @0x2a32a4 ldr r0, [sp, #0x1c]
 *   @0x2a32a8 bl 0x2a3b88 <_Z13_zip_cdir_newiP9zip_error>
 *   @0x2a32ac mov r5, r0
 *   @0x2a32b0 beq.w 0x2a3970 <zip_close+0x784>
 *   @0x2a32b4 movs r7, #0x0
 *   @0x2a32b8 stmdavs r8!, {r2, r3, r4, r5, r11}
 *   @0x2a32bc mla r0, r8, r7, r0
 *   @0x2a32c0 bl 0x2a3c2c <_Z16_zip_dirent_initP10zip_dirent>
 *   @0x2a32c4 ldr r1, [sp, #0x1c]
 *   @0x2a32c8 cmp r7, r1
 *   @0x2a32cc mov r0, r4
 *   @0x2a32d0 movs r2, #0x0
 *   @0x2a32d4 cmplt r0, r3, lsl r11
 *   @0x2a32d8 ldr.w r0, [pc, #0x6a4]
 *   @0x2a32dc movs r1, #0x16
 *   @0x2a32e0 add r0, pc
 *   @0x2a32e4 tsths r6, #74752
 *   @0x2a32e8 str r0, [r5, #0x10]
 *   @0x2a32ec b 0x2a396a <zip_close+0x77e>
 *   @0x2a32f0 movs r1, #0x1
 *   @0x2a32f4 bl 0x2a48fc <zip_get_archive_flag>
 *   @0x2a32f8 cbnz r0, 0x2a3332 <zip_close+0x146>
 *   @0x2a32fc adds r0, r1, #0x1
 *   @0x2a3300 ldr r0, [r4, #0x24]
 *   @0x2a3304 bl 0x2a4978 <_Z11_zip_memdupPKvjP9zip_error>
 *   @0x2a3308 str r0, [r5, #0x10]
 *   @0x2a330c beq.w 0x2a396a <zip_close+0x77e>
 *   @0x2a3310 ldr r3, [r4, #0x28]
 *   @0x2a3314 ldr r3, [r4, #0x20]
 *   @0x2a3318 ldr r0, [r3, #0x10]
 *   @0x2a331c ldrh r1, [r3, #0x14]
 *   @0x2a3320 bl 0x2a4978 <_Z11_zip_memdupPKvjP9zip_error>
 *   @0x2a3324 str r0, [r5, #0x10]
 *   @0x2a3328 beq.w 0x2a396a <zip_close+0x77e>
 *   @0x2a332c ldr r3, [r4, #0x20]
 *   @0x2a3330 strh r3, [r5, #0x14]
 *   @0x2a3334 mov r0, r7
 *   @0x2a3338 andlo lr, r8, r0, lsl #18
 *   @0x2a333c blx 0xb6544 <malloc@plt>
 *   @0x2a3340 mov r11, r0
 *   @0x2a3344 mov r0, r6
 *   @0x2a3348 mov r2, r11
 *   @0x2a334c movw pc, #0xc805
 *   @0x2a3350 ldr.w r1, [pc, #0x630]
 *   @0x2a3354 mov r2, r7
 *   @0x2a3358 blx 0xb6550 <sprintf@plt>
 *   @0x2a335c mov r0, r11
 *   @0x2a3360 mcrrne p13, #0xa, lr, r1, c14
 *   @0x2a3364 bne 0x2a3376 <zip_close+0x18a>
 *   @0x2a3368 .word 0x210cec48
 *   @0x2a336c ldr r2, [r0]
 *   @0x2a3370 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a3374 b 0x2a33a4 <zip_close+0x1b8>
 *   @0x2a3378 ldrbtmi r1, [r9], #-1552
 *   @0x2a337c blx 0xb6ec8 <fdopen@plt>
 *   @0x2a3380 mov r7, r0
 *   @0x2a3384 mov.w r9, #0x0
 *   @0x2a3388 mov.w r10, #0x14
 *   @0x2a338c mov r8, r9
 *   @0x2a3390 blx 0xb6bf8 <__errno@plt>
 *   @0x2a3394 movs r1, #0xc
 *   @0x2a3398 mov r0, r6
 *   @0x2a339c .word 0x4658ffdd
 *   @0x2a33a0 blx 0xb6970 <remove@plt>
 *   @0x2a33a4 mov r0, r11
 *   @0x2a33a8 sbcs lr, lr, #14286848
 *   @0x2a33ac mul r2, r10, r8
 *   @0x2a33b0 ldr r3, [r4, #0x34]
 *   @0x2a33b4 cmp r3, #0x1
 *   @0x2a33b8 ldr r2, [sp, #0x10]
 *   @0x2a33bc mov r1, r8
 *   @0x2a33c0 .word 0xf84203c9
 *   @0x2a33c4 andhs r8, r0, #57
 *   @0x2a33c8 str r3, [sp, #0x8]
 *   @0x2a33cc blls 0x361f18 <_ZTS12CDS_Priority+0x3f70>
 *   @0x2a33d0 add.w r9, r9, #0x1
 *   @0x2a33d4 str r0, [r3, #0x4]
 *   @0x2a33d8 bvs 0xffb653e4 <b2_toiTime+0xffffffffff40bf40>
 *   @0x2a33dc cmp r8, r3
 *   @0x2a33e0 mov r0, r4
 *   @0x2a33e4 movs r2, #0x0
 *   @0x2a33e8 teqlt r8, r9, lsl #21
 *   @0x2a33ec ldr.w r3, [pc, #0x59c]
 *   @0x2a33f0 movs r2, #0x8
 *   @0x2a33f4 ldr r1, [sp, #0x1c]
 *   @0x2a33f8 blx 0xb66dc <qsort@plt>
 *   @0x2a33fc movs r1, #0x1
 *   @0x2a3400 movs r2, #0x0
 *   @0x2a3404 stmdahs r1, {r0, r1, r3, r4, r5, r6, r9, r11, r12, sp, lr, pc}
 *   @0x2a3408 mov r1, r0
 *   @0x2a340c mov r0, r4
 *   @0x2a3410 bl 0x2a48fc <zip_get_archive_flag>
 *   @0x2a3414 rsbs.w r0, r0, #0x1
 *   @0x2a3418 it lo
 *   @0x2a341c str r0, [sp, #0x14]
 *   @0x2a3420 movs r3, #0x0
 *   @0x2a3424 ldr.w r2, [pc, #0x568]
 *   @0x2a3428 add r3, sp, #0x38
 *   @0x2a342c str r3, [sp, #0x24]
 *   @0x2a3430 add r2, pc
 *   @0x2a3434 andls r0, r10, #20, #2
 *   @0x2a3438 str r1, [sp, #0x34]
 *   @0x2a343c mov.w r8, #0x14
 *   @0x2a3440 ldr r2, [sp, #0x10]
 *   @0x2a3444 blvs 0x1b8b518 <b2_toiTime+0x1432074>
 *   @0x2a3448 mul r8, r8, r10
 *   @0x2a344c ldr.w r3, [r3, r8]
 *   @0x2a3450 subs r3, #0x2
 *   @0x2a3454 bls 0x2a345c <zip_close+0x270>
 *   @0x2a3458 cmp r1, #0x0
 *   @0x2a345c add.w r12, sp, #0x54
 *   @0x2a3460 str.w r12, [sp, #0xc]
 *   @0x2a3464 mov r0, r12
 *   @0x2a3468 strtmi pc, [r0], -r1, ror #23
 *   @0x2a346c movs r1, #0x1
 *   @0x2a3470 bl 0x2a48fc <zip_get_archive_flag>
 *   @0x2a3474 ldr.w r12, [sp, #0xc]
 *   @0x2a3478 cbz r0, 0x2a3484 <zip_close+0x298>
 *   @0x2a347c bl 0x2a3c58 <_Z29_zip_dirent_torrent_normalizeP10zip_dirent>
 *   @0x2a3480 ldr.w r12, [sp, #0xc]
 *   @0x2a3484 ldr r2, [sp, #0x18]
 *   @0x2a3488 stmdavs r11!, {r2, r3, r4, r5, r8, r11}
 *   @0x2a348c mul r9, r9, r2
 *   @0x2a3490 mov r2, r12
 *   @0x2a3494 strbmi r0, [r11], #-3128
 *   @0x2a3498 mov lr, r2
 *   @0x2a349c ldm.w lr!, {r0, r1}
 *   @0x2a34a0 cmp lr, r12
 *   @0x2a34a4 ldrbtmi r0, [r2], -r8, lsl #24
 *   @0x2a34a8 str r1, [r3, #-4]
 *   @0x2a34ac bne 0x2a3498 <zip_close+0x2ac>
 *   @0x2a34b0 str r0, [r3]
 *   @0x2a34b4 add.w r2, r3, r8
 *   @0x2a34b8 ldr r2, [r2, #0x8]
 *   @0x2a34bc bne 0x2a35b2 <zip_close+0x3c6>
 *   @0x2a34c0 blhs 0x36f4e8 <_ZTS13C_UTF16String+0x6594>
 *   @0x2a34c4 bne 0x2a34e4 <zip_close+0x2f8>
 *   @0x2a34c8 blx 0xb6640 <strdup@plt>
 *   @0x2a34cc movs r3, #0x1
 *   @0x2a34d0 stmdbls r10, {r4, r5, r6, r12, sp}
 *   @0x2a34d4 str r0, [sp, #0x6c]
 *   @0x2a34d8 add r2, r9
 *   @0x2a34dc ldr r2, [r5]
 *   @0x2a34e0 strh r3, [r2, #0x1c]
 *   @0x2a34e4 ldr r3, [r4, #0x20]
 *   @0x2a34e8 mul r1, r2, r10
 *   @0x2a34ec ldr r2, [r3]
 *   @0x2a34f0 ldr r0, [r2, #0x18]
 *   @0x2a34f4 str r3, [sp, #0x8]
 *   @0x2a34f8 andsls lr, r11, r4, lsr #17
 *   @0x2a34fc blx 0xb6538 <strlen@plt>
 *   @0x2a3500 ldr r3, [sp, #0x8]
 *   @0x2a3504 strh.w r0, [sp, #0x70]
 *   @0x2a3508 ldr r3, [r3]
 *   @0x2a350c ldr r2, [r3, #0x18]
 *   @0x2a3510 add r3, r9
 *   @0x2a3514 ldr r3, [r5]
 *   @0x2a3518 strbmi r2, [r11], #-112
 *   @0x2a351c strh r2, [r3, #0x1c]
 *   @0x2a3520 ldr r0, [r4, #0x4]
 *   @0x2a3524 beq 0x2a361c <zip_close+0x430>
 *   @0x2a3528 movs r2, #0x3c
 *   @0x2a352c mla r3, r2, r10, r3
 *   @0x2a3530 ldr r2, [sp, #0x14]
 *   @0x2a3534 blx 0xb6ed4 <fseeko@plt>
 *   @0x2a3538 cmp r0, #0x0
 *   @0x2a353c bls 0x4039bc <g_RomDisk+0xc19c>
 *   @0x2a3540 movs r3, #0x1
 *   @0x2a3544 stm.w sp, {r3, r6}
 *   @0x2a3548 ldr r1, [r4, #0x4]
 *   @0x2a354c bl 0x2a3ef0 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error>
 *   @0x2a3550 cmp r0, #0x0
 *   @0x2a3554 ldr r2, [sp, #0x18]
 *   @0x2a3558 ldr r0, [r5]
 *   @0x2a355c bvs 0xb5f96c <b2_toiTime+0x4064c8>
 *   @0x2a3560 mul r3, r3, r10
 *   @0x2a3564 ldr r2, [r2]
 *   @0x2a3568 add r2, r3
 *   @0x2a356c .word 0xf8520e3c
 *   @0x2a3570 ldrbmi r12, [r2, #-0xb04]!
 *   @0x2a3574 str r12, [r0], #4
 *   @0x2a3578 bne 0x2a356e <zip_close+0x382>
 *   @0x2a357c .word 0xf01ee058
 *   @0x2a3580 andsle r0, r6, r8, lsl #30
 *   @0x2a3584 ldr r2, [r4, #0x20]
 *   @0x2a3588 ldmdavs r0, {r3, r9, r10, r11}
 *   @0x2a358c add r0, r3
 *   @0x2a3590 str r0, [sp, #0x60]
 *   @0x2a3594 add r0, r3
 *   @0x2a3598 str r0, [sp, #0x64]
 *   @0x2a359c strh.w lr, [sp, #0x58]
 *   @0x2a35a0 add r3, r2
 *   @0x2a35a4 str r3, [sp, #0x68]
 *   @0x2a35a8 add r1, r3
 *   @0x2a35ac bic r3, r3, #0x8
 *   @0x2a35b0 strh r3, [r1, #0x4]
 *   @0x2a35b4 add r3, r8
 *   @0x2a35b8 cmp r3, #0x0
 *   @0x2a35bc mov r0, r4
 *   @0x2a35c0 movs r2, #0x0
 *   @0x2a35c4 stmdahs r0, {r0, r1, r3, r4, r7, r8, r11, r12, sp, lr, pc}
 *   @0x2a35c8 beq 0x2a3688 <zip_close+0x49c>
 *   @0x2a35cc movs r3, #0x3c
 *   @0x2a35d0 muls r3, r2, r3
 *   @0x2a35d4 ldr.w r9, [sp, #0x20]
 *   @0x2a35d8 ldr r3, [r5]
 *   @0x2a35dc blx 0xb6ee0 <ftello@plt>
 *   @0x2a35e0 str.w r0, [r9, #0x38]
 *   @0x2a35e4 ldr r3, [r4, #0x34]
 *   @0x2a35e8 .word 0xf8530208
 *   @0x2a35ec bllo 0x32f614
 *   @0x2a35f0 cmp r3, #0x1
 *   @0x2a35f4 ldr r3, [sp, #0x14]
 *   @0x2a35f8 beq.w 0x2a37c0 <zip_close+0x5d4>
 *   @0x2a35fc movs r2, #0x0
 *   @0x2a3600 qsub8mi r3, r0, pc
 *   @0x2a3604 stm.w sp, {r2, r3}
 *   @0x2a3608 mov r1, r4
 *   @0x2a360c movs r3, #0x10
 *   @0x2a3610 stmdahs r0, {r0, r2, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2a3614 bne 0x2a3698 <zip_close+0x4ac>
 *   @0x2a3618 rscs r0, r2, r1, lsl #16
 *   @0x2a361c ldr r0, [r4, #0x8]
 *   @0x2a3620 beq 0x2a3554 <zip_close+0x368>
 *   @0x2a3624 movs r1, #0x3c
 *   @0x2a3628 ldr r2, [r2]
 *   @0x2a362c mla r2, r1, r10, r2
 *   @0x2a3630 ldr r1, [sp, #0x14]
 *   @0x2a3634 blx r3
 *   @0x2a3638 movs r3, #0x1
 *   @0x2a363c stm.w sp, {r3, r6}
 *   @0x2a3640 mov r3, r2
 *   @0x2a3644 bl 0x2a4108 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error>
 *   @0x2a3648 b 0x2a3550 <zip_close+0x364>
 *   @0x2a364c blx 0xb655c <free@plt>
 *   @0x2a3650 ldr r3, [r4, #0x34]
 *   @0x2a3654 .word 0xf8d90908
 *   @0x2a3658 .word 0xf6120008
 *   @0x2a365c ldrshls lr, [r11], -r2
 *   @0x2a3660 cmp r0, #0x0
 *   @0x2a3664 blx 0xb6538 <strlen@plt>
 *   @0x2a3668 ldr r1, [sp, #0x18]
 *   @0x2a366c muls r3, r1, r3
 *   @0x2a3670 stmdavs r10!, {r4, r5, r6}
 *   @0x2a3674 ldr.w r1, [r9, #0x8]
 *   @0x2a3678 add r2, r3
 *   @0x2a367c ldr r2, [r5]
 *   @0x2a3680 ldrmi r1, [r3], #-112
 *   @0x2a3684 strh r1, [r3, #0x1c]
 *   @0x2a3688 ldr r2, [r4, #0x34]
 *   @0x2a368c ldr r3, [r2, #0x10]
 *   @0x2a3690 bne.w 0x2a394e <zip_close+0x762>
 *   @0x2a3694 b 0x2a35ca <zip_close+0x3de>
 *   @0x2a3698 ldr.w r8, [r0, #0x4]
 *   @0x2a369c add r1, sp, #0x38
 *   @0x2a36a0 andshs r9, r12, #0
 *   @0x2a36a4 movs r3, #0x3
 *   @0x2a36a8 blx r9
 *   @0x2a36ac ble 0x2a370e <zip_close+0x522>
 *   @0x2a36b0 mov r0, r8
 *   @0x2a36b4 mov r3, r1
 *   @0x2a36b8 cmp r0, #0x0
 *   @0x2a36bc mov r0, r7
 *   @0x2a36c0 .word 0xf6130a54
 *   @0x2a36c4 ldrtmi lr, [r9], -lr, lsl #24
 *   @0x2a36c8 movs r2, #0x1
 *   @0x2a36cc str r0, [sp, #0x2c]
 *   @0x2a36d0 bl 0x2a3ce0 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error>
 *   @0x2a36d4 cmp r0, #0x0
 *   @0x2a36d8 ldrh.w r3, [sp, #0x50]
 *   @0x2a36dc cbz r3, 0x2a36ee <zip_close+0x502>
 *   @0x2a36e0 mov r0, r9
 *   @0x2a36e4 ldr r2, [sp, #0x34]
 *   @0x2a36e8 bl 0x2a314c <android_getCpuFeatures+0x290>
 *   @0x2a36ec b 0x2a36fc <zip_close+0x510>
 *   @0x2a36f0 mov r0, r4
 *   @0x2a36f4 mov r2, r8
 *   @0x2a36f8 bl 0x2a2f18 <android_getCpuFeatures+0x5c>
 *   @0x2a36fc cmp r0, #0x0
 *   @0x2a3700 movs r1, #0x0
 *   @0x2a3704 mov r2, r1
 *   @0x2a3708 blx r9
 *   @0x2a370c bge 0x2a371a <zip_close+0x52e>
 *   @0x2a3710 mov r1, r9
 *   @0x2a3714 bl 0x2a2ee8 <android_getCpuFeatures+0x2c>
 *   @0x2a3718 b 0x2a3616 <zip_close+0x42a>
 *   @0x2a371c blx 0xb6ee0 <ftello@plt>
 *   @0x2a3720 ldr r1, [sp, #0x2c]
 *   @0x2a3724 mov r8, r0
 *   @0x2a3728 blx 0xb6ed4 <fseeko@plt>
 *   @0x2a372c cmp r0, #0x0
 *   @0x2a3730 ldr r3, [sp, #0x44]
 *   @0x2a3734 movs r1, #0x1
 *   @0x2a3738 str r3, [sp, #0x5c]
 *   @0x2a373c .word 0xf8ad3050
 *   @0x2a3740 blls 0x6af8b0 <g_SWFlinevertbuff+0x5c7e8>
 *   @0x2a3744 str r3, [sp, #0x60]
 *   @0x2a3748 str r3, [sp, #0x68]
 *   @0x2a374c str r3, [sp, #0x64]
 *   @0x2a3750 ldrsblt pc, [r0, -r5]
 *   @0x2a3754 mov r0, r10
 *   @0x2a3758 usub16mi pc, r0, pc
 *   @0x2a375c mov r1, r7
 *   @0x2a3760 mov r3, r6
 *   @0x2a3764 stmdahs r0, {r0, r2, r3, r4, r5, r7, r9, r11, r12, sp, lr, pc}
 *   @0x2a3768 blt.w 0x2a3616 <zip_close+0x42a>
 *   @0x2a376c mov r0, r7
 *   @0x2a3770 movs r2, #0x0
 *   @0x2a3774 stmdahs r0, {r4, r5, r7, r8, r9, r11, sp, lr, pc}
 *   @0x2a3778 bge 0x2a378a <zip_close+0x59e>
 *   @0x2a377c .word 0x2104ea3e
 *   @0x2a3780 ldr r2, [r0]
 *   @0x2a3784 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a3788 b 0x2a3616 <zip_close+0x42a>
 *   @0x2a378c ldr r2, [sp, #0x20]
 *   @0x2a3790 add r2, r3
 *   @0x2a3794 str r3, [r2, #0x8]
 *   @0x2a3798 ldrh.w r2, [sp, #0x5a]
 *   @0x2a379c add r3, r1
 *   @0x2a37a0 mov r2, r1
 *   @0x2a37a4 add r2, r3
 *   @0x2a37a8 str r3, [r2, #0x10]
 *   @0x2a37ac ldr r3, [r5]
 *   @0x2a37b0 ldr r3, [sp, #0x68]
 *   @0x2a37b4 mov r2, r1
 *   @0x2a37b8 add r2, r3
 *   @0x2a37bc str r3, [r2, #0xc]
 *   @0x2a37c0 add r0, sp, #0x54
 *   @0x2a37c4 movs r2, #0x1
 *   @0x2a37c8 bl 0x2a3ce0 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error>
 *   @0x2a37cc cmp r0, #0x0
 *   @0x2a37d0 bls 0x4cf460 <SrcVerts+0x2c4a4>
 *   @0x2a37d4 ldr r3, [r5]
 *   @0x2a37d8 add r3, r2
 *   @0x2a37dc ldr r1, [r3, #0x10]
 *   @0x2a37e0 bl 0x2a30a4 <android_getCpuFeatures+0x1e8>
 *   @0x2a37e4 cmp r0, #0x0
 *   @0x2a37e8 ldmdage r5, {r1, r2, r4, r8, r9, r10, r11, sp, pc}
 *   @0x2a37ec bl 0x2a3bd6 <_Z20_zip_dirent_finalizeP10zip_dirent>
 *   @0x2a37f0 ldr r3, [sp, #0x18]
 *   @0x2a37f4 adds r3, #0x1
 *   @0x2a37f8 cmp r3, r1
 *   @0x2a37fc .word 0xf04fae1e
 *   @0x2a3800 stmdals r4, {r11}
 *   @0x2a3804 blx 0xb655c <free@plt>
 *   @0x2a3808 cmp.w r8, #0x0
 *   @0x2a380c bne 0x2a389e <zip_close+0x6b2>
 *   @0x2a3810 mov r1, r7
 *   @0x2a3814 bl 0x2a3e10 <_Z15_zip_cdir_writeP8zip_cdirP7__sFILEP9zip_error>
 *   @0x2a3818 cmp r0, #0x0
 *   @0x2a381c mov r0, r4
 *   @0x2a3820 mov r2, r8
 *   @0x2a3824 ldmdblt r0, {r0, r1, r3, r5, r6, r11, r12, sp, lr, pc}
 *   @0x2a3828 mov.w r8, #0x0
 *   @0x2a382c b 0x2a3898 <zip_close+0x6ac>
 *   @0x2a3830 blx 0xb6ee0 <ftello@plt>
 *   @0x2a3834 str r6, [sp]
 *   @0x2a3838 ldr r1, [r5, #0xc]
 *   @0x2a383c mov r9, r0
 *   @0x2a3840 bl 0x2a43f8 <_Z18_zip_filerange_crcP7__sFILEllPmP9zip_error>
 *   @0x2a3844 cmp r0, #0x0
 *   @0x2a3848 add.w r10, sp, #0x90
 *   @0x2a384c ldr r2, [pc, #0x144]
 *   @0x2a3850 ldr r3, [sp, #0x38]
 *   @0x2a3854 mov r0, r10
 *   @0x2a3858 .word 0x4638eeb8
 *   @0x2a385c sub.w r1, r9, #0x8
 *   @0x2a3860 mov r2, r8
 *   @0x2a3864 stmdahs r0, {r3, r4, r5, r8, r9, r11, sp, lr, pc}
 *   @0x2a3868 bge 0x2a3876 <zip_close+0x68a>
 *   @0x2a386c smlabths r4, r6, r9, lr
 *   @0x2a3870 ldr r2, [r0]
 *   @0x2a3874 b 0x2a3890 <zip_close+0x6a4>
 *   @0x2a3878 movs r1, #0x8
 *   @0x2a387c mov r3, r7
 *   @0x2a3880 stmdahs r1, {r1, r2, r3, r4, r11, sp, lr, pc}
 *   @0x2a3884 beq 0x2a3828 <zip_close+0x63c>
 *   @0x2a3888 strhhs lr, [r6, -r8]
 *   @0x2a388c ldr r2, [r0]
 *   @0x2a3890 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a3894 mov.w r8, #0xffffffff
 *   @0x2a3898 rsb.w r8, r8, #0x0
 *   @0x2a389c b 0x2a38a2 <zip_close+0x6b6>
 *   @0x2a38a0 movwhs r0, #0x801
 *   @0x2a38a4 mov r0, r5
 *   @0x2a38a8 bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir>
 *   @0x2a38ac cmp.w r8, #0x0
 *   @0x2a38b0 beq 0x2a38c0 <zip_close+0x6d4>
 *   @0x2a38b4 bl 0x2a3bd6 <_Z20_zip_dirent_finalizeP10zip_dirent>
 *   @0x2a38b8 mov r0, r7
 *   @0x2a38bc and lr, r10, r10, asr #31
 *   @0x2a38c0 mov r0, r7
 *   @0x2a38c4 cmnlt r8, r6, asr #31
 *   @0x2a38c8 blx 0xb6bf8 <__errno@plt>
 *   @0x2a38cc movs r1, #0x3
 *   @0x2a38d0 mov r0, r6
 *   @0x2a38d4 ldrbmi pc, [r8], -r1, asr #26
 *   @0x2a38d8 blx 0xb6970 <remove@plt>
 *   @0x2a38dc mov r0, r11
 *   @0x2a38e0 .word 0xf04fee3e
 *   @0x2a38e4 .word 0xe02a35ff
 *   @0x2a38e8 ldr r0, [r4, #0x4]
 *   @0x2a38ec blx 0xb6850 <fclose@plt>
 *   @0x2a38f0 movs r7, #0x1
 *   @0x2a38f4 and r8, r0, r4
 *   @0x2a38f8 mov r7, r8
 *   @0x2a38fc ldr r1, [r4]
 *   @0x2a3900 strmi lr, [r5], -lr, lsr #31
 *   @0x2a3904 cbz r0, 0x2a3932 <zip_close+0x746>
 *   @0x2a3908 .word 0x2102e978
 *   @0x2a390c ldr r2, [r0]
 *   @0x2a3910 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a3914 mov r0, r11
 *   @0x2a3918 ldrbmi lr, [r8], -r12, lsr #16
 *   @0x2a391c blx 0xb655c <free@plt>
 *   @0x2a3920 cmp r7, #0x0
 *   @0x2a3924 ldr r1, [pc, #0x70]
 *   @0x2a3928 add r1, pc
 *   @0x2a392c rsbvs lr, r0, r12, lsl #31
 *   @0x2a3930 b 0x2a38e2 <zip_close+0x6f6>
 *   @0x2a3934 bl 0x2a4884 <_Z9_zip_freeP3zip>
 *   @0x2a3938 mov r0, r11
 *   @0x2a393c stmdbls r12, {r4, r9, r10, r11, sp, lr, pc}
 *   @0x2a3940 mov r0, r5
 *   @0x2a3944 ldr r3, [r1]
 *   @0x2a3948 beq 0x2a3974 <zip_close+0x788>
 *   @0x2a394c stmdbls r6, {r2, r6, r9, r10, r11, sp, lr, pc}
 *   @0x2a3950 movs r3, #0x3c
 *   @0x2a3954 ldr r1, [r2, #0xc]
 *   @0x2a3958 add r2, r3
 *   @0x2a395c ldr r2, [r5]
 *   @0x2a3960 ldr r2, [r4, #0x34]
 *   @0x2a3964 ldr r2, [r2, #0x10]
 *   @0x2a3968 b 0x2a35ca <zip_close+0x3de>
 *   @0x2a396c bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir>
 *   @0x2a3970 ldr r0, [sp, #0x10]
 *   @0x2a3974 add sp, #0xa4
 *   @0x2a3978 svclt #0x8ff0
 *   @0x2a397c adr r7, #384 <zip_close+0x7f4>
 *   @0x2a3980 ldrh r6, [r5, #0x26]
 *   @0x2a3984 ldrh r7, [r1, #0x24]
 *   @0x2a3988 ldrh r5, [r6, #0x22]
 *   @0x2a398c .word 0xfb17 ffff
 *   @0x2a3990 ldrh r3, [r0, #0x1e]
 *   @0x2a3994 strh r3, [r4, #0x3c]
 *   @0x2a3998 strh r3, [r2, #0x36]
 *
 * ══ §9/16 CFontGM::CreateIt()  0xf9660  size 1960  490 条（0xf9660..0xf9e08）
 * @func 0xf9660 0xf9e08  size 1960  490 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×6 / FT_Get_First_Char×3 / FT_Get_Next_Char×3 / 0xb65b0×2 / FT_Load_Glyph×2 / operator new(unsigned int)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / LoadSave::SaveFileExists(char const*)
 * 字段偏移 top8: 0x-238×14 / 0x4×12 / 0x-240×7 / 0x8×7 / 0x2×7 / 0xc×6 / 0x-234×6 / 0x40×6
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9660 ldr r12, [pc, #0x768]
 *   @0xf9664 mov r3, #0
 *   @0xf9668 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf966c add r11, sp, #32
 *   @0xf9670 ldr r2, [pc, #0x75c]
 *   @0xf9674 sub sp, sp, #596
 *   @0xf9678 add r12, pc, r12
 *   @0xf967c str r12, [r11, #-0x240]
 *   @0xf9680 mov r5, r0
 *   @0xf9684 ldr r2, [r12, r2]
 *   @0xf9688 ldr r0, [r0, #0x4]
 *   @0xf968c str r3, [r5, #0x54]
 *   @0xf9690 ldr r3, [r2]
 *   @0xf9694 str r2, [r11, #-0x248]
 *   @0xf9698 str r3, [r11, #-0x28]
 *   @0xf969c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xf96a0 cmp r0, #0
 *   @0xf96a4 ldr r0, [r5, #0x4]
 *   @0xf96a8 beq 0xf9738 <_ZN7CFontGM8CreateItEv+0xd8>
 *   @0xf96ac add r1, r5, #88
 *   @0xf96b0 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0xf96b4 mov r1, r0
 *   @0xf96b8 str r0, [r5, #0x54]
 *   @0xf96bc ldr r12, [r11, #-0x240]
 *   @0xf96c0 mov r3, #0
 *   @0xf96c4 ldr r0, [pc, #0x70c]
 *   @0xf96c8 ldr r2, [r5, #0x58]
 *   @0xf96cc ldr r0, [r12, r0]
 *   @0xf96d0 sub r12, r11, #568
 *   @0xf96d4 str r12, [sp]
 *   @0xf96d8 ldr r0, [r0]
 *   @0xf96dc blx 0x2e96f0 <FT_New_Memory_Face>
 *   @0xf96e0 subs r1, r0, #0
 *   @0xf96e4 beq 0xf975c <_ZN7CFontGM8CreateItEv+0xfc>
 *   @0xf96e8 mov r2, r1
 *   @0xf96ec mov r3, r1
 *   @0xf96f0 ldr r1, [pc, #0x6e4]
 *   @0xf96f4 ldr r0, [pc, #0x6e4]
 *   @0xf96f8 ldr lr, [r5, #0x4]
 *   @0xf96fc add r1, pc, r1
 *   @0xf9700 ldr r12, [r11, #-0x240]
 *   @0xf9704 ldr r0, [r12, r0]
 *   @0xf9708 ldr r0, [r0]
 *   @0xf970c ldr r12, [r0]
 *   @0xf9710 str lr, [sp]
 *   @0xf9714 ldr r12, [r12, #0xc]
 *   @0xf9718 blx r12
 *   @0xf971c ldr r12, [r11, #-0x248]
 *   @0xf9720 ldr r2, [r11, #-0x28]
 *   @0xf9724 ldr r3, [r12]
 *   @0xf9728 cmp r2, r3
 *   @0xf972c bne 0xf9dcc <_ZN7CFontGM8CreateItEv+0x76c>
 *   @0xf9730 sub sp, r11, #32
 *   @0xf9734 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf9738 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0xf973c cmp r0, #0
 *   @0xf9740 beq 0xf97c0 <_ZN7CFontGM8CreateItEv+0x160>
 *   @0xf9744 add r1, r5, #88
 *   @0xf9748 ldr r0, [r5, #0x4]
 *   @0xf974c bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0xf9750 mov r1, r0
 *   @0xf9754 str r0, [r5, #0x54]
 *   @0xf9758 b 0xf96bc <_ZN7CFontGM8CreateItEv+0x5c>
 *   @0xf975c ldr r2, [r5, #0x8]
 *   @0xf9760 mov r3, #96
 *   @0xf9764 ldr r0, [r11, #-0x238]
 *   @0xf9768 str r3, [sp]
 *   @0xf976c lsl r2, r2, #6
 *   @0xf9770 blx 0x2e578c <FT_Set_Char_Size>
 *   @0xf9774 subs r2, r0, #0
 *   @0xf9778 bne 0xf97ec <_ZN7CFontGM8CreateItEv+0x18c>
 *   @0xf977c movw r1, #0x6963
 *   @0xf9780 ldr r0, [r11, #-0x238]
 *   @0xf9784 movt r1, #0x756e
 *   @0xf9788 blx 0x2e58f4 <FT_Select_Charmap>
 *   @0xf978c subs r2, r0, #0
 *   @0xf9790 beq 0xf9804 <_ZN7CFontGM8CreateItEv+0x1a4>
 *   @0xf9794 ldr r12, [r11, #-0x240]
 *   @0xf9798 mov r3, r2
 *   @0xf979c ldr r0, [pc, #0x63c]
 *   @0xf97a0 ldr r1, [pc, #0x63c]
 *   @0xf97a4 ldr r0, [r12, r0]
 *   @0xf97a8 add r1, pc, r1
 *   @0xf97ac ldr r0, [r0]
 *   @0xf97b0 ldr r12, [r0]
 *   @0xf97b4 ldr r12, [r12, #0xc]
 *   @0xf97b8 blx r12
 *   @0xf97bc b 0xf971c <_ZN7CFontGM8CreateItEv+0xbc>
 *   @0xf97c0 ldr r12, [r11, #-0x240]
 *   @0xf97c4 ldr r3, [pc, #0x614]
 *   @0xf97c8 ldr r1, [pc, #0x618]
 *   @0xf97cc ldr r2, [r5, #0x4]
 *   @0xf97d0 ldr r3, [r12, r3]
 *   @0xf97d4 add r1, pc, r1
 *   @0xf97d8 ldr r0, [r3]
 *   @0xf97dc ldr r3, [r0]
 *   @0xf97e0 ldr r3, [r3, #0xc]
 *   @0xf97e4 blx r3
 *   @0xf97e8 b 0xf971c <_ZN7CFontGM8CreateItEv+0xbc>
 *   @0xf97ec ldr r1, [pc, #0x5f8]
 *   @0xf97f0 mov r3, r2
 *   @0xf97f4 ldr r0, [pc, #0x5e4]
 *   @0xf97f8 ldr lr, [r5, #0x8]
 *   @0xf97fc add r1, pc, r1
 *   @0xf9800 b 0xf9700 <_ZN7CFontGM8CreateItEv+0xa0>
 *   @0xf9804 ldr r0, [r11, #-0x238]
 *   @0xf9808 sub r12, r11, #564
 *   @0xf980c str r12, [r11, #-0x250]
 *   @0xf9810 mov r1, r12
 *   @0xf9814 ldr r3, [r0, #0x58]
 *   @0xf9818 ldr r3, [r3, #0x18]
 *   @0xf981c str r3, [r11, #-0x258]
 *   @0xf9820 blx 0x2e59bc <FT_Get_First_Char>
 *   @0xf9824 ldr r3, [r11, #-0x234]
 *   @0xf9828 cmp r3, #0
 *   @0xf982c beq 0xf9db0 <_ZN7CFontGM8CreateItEv+0x750>
 *   @0xf9830 sub r6, r11, #564
 *   @0xf9834 mov r4, #1
 *   @0xf9838 mov r1, r0
 *   @0xf983c mov r2, r6
 *   @0xf9840 ldr r0, [r11, #-0x238]
 *   @0xf9844 add r4, r4, #1
 *   @0xf9848 blx 0x2e597e <FT_Get_Next_Char>
 *   @0xf984c ldr r3, [r11, #-0x234]
 *   @0xf9850 cmp r3, #0
 *   @0xf9854 bne 0xf9838 <_ZN7CFontGM8CreateItEv+0x1d8>
 *   @0xf9858 cmp r4, #532676608
 *   @0xf985c str r4, [r5, #0x40]
 *   @0xf9860 lsl r4, r4, #2
 *   @0xf9864 mvnhi r0, #0
 *   @0xf9868 bls 0xf9dbc <_ZN7CFontGM8CreateItEv+0x75c>
 *   @0xf986c bl 0x27d14c <_Znaj>
 *   @0xf9870 ldr r2, [r5, #0x40]
 *   @0xf9874 mov r1, #0
 *   @0xf9878 lsl r2, r2, #2
 *   @0xf987c str r0, [r5, #0x44]
 *   @0xf9880 bl 0xb65b0 <memset@plt>
 *   @0xf9884 mov r1, #32
 *   @0xf9888 ldr r0, [r11, #-0x238]
 *   @0xf988c blx 0x2e5960 <FT_Get_Char_Index>
 *   @0xf9890 mov r2, #0
 *   @0xf9894 mov r1, r0
 *   @0xf9898 ldr r0, [r11, #-0x238]
 *   @0xf989c blx 0x2e7564 <FT_Load_Glyph>
 *   @0xf98a0 mov r0, #16
 *   @0xf98a4 bl 0x27c524 <_Znwj>
 *   @0xf98a8 ldr r1, [r5, #0x44]
 *   @0xf98ac mov r12, #32
 *   @0xf98b0 add r2, r4, #14
 *   @0xf98b4 bic r2, r2, #7
 *   @0xf98b8 sub sp, sp, r2
 *   @0xf98bc mov r2, #0
 *   @0xf98c0 add lr, sp, #8
 *   @0xf98c4 str lr, [r11, #-0x264]
 *   @0xf98c8 str r0, [r1]
 *   @0xf98cc mov r3, r0
 *   @0xf98d0 ldr r0, [r11, #-0x238]
 *   @0xf98d4 sub r1, r11, #564
 *   @0xf98d8 strh r12, [r3]
 *   @0xf98dc strh r2, [r3, #14]
 *   @0xf98e0 ldr r12, [r0, #0x54]
 *   @0xf98e4 strh r2, [r3, #2]
 *   @0xf98e8 strh r2, [r3, #4]
 *   @0xf98ec ldr r12, [r12, #0x28]
 *   @0xf98f0 strh r2, [r3, #6]
 *   @0xf98f4 add r12, r12, #63
 *   @0xf98f8 strh r2, [r3, #8]
 *   @0xf98fc strh r2, [r3, #12]
 *   @0xf9900 asr r2, r12, #6
 *   @0xf9904 strh r2, [r3, #10]
 *   @0xf9908 blx 0x2e59bc <FT_Get_First_Char>
 *   @0xf990c ldr r2, [r11, #-0x234]
 *   @0xf9910 cmp r2, #0
 *   @0xf9914 mov r3, r0
 *   @0xf9918 beq 0xf994c <_ZN7CFontGM8CreateItEv+0x2ec>
 *   @0xf991c ldr r12, [r11, #-0x264]
 *   @0xf9920 sub r6, r11, #564
 *   @0xf9924 sub r4, r12, #4
 *   @0xf9928 mov r1, r3
 *   @0xf992c str r3, [r4, #0x4]!
 *   @0xf9930 ldr r0, [r11, #-0x238]
 *   @0xf9934 mov r2, r6
 *   @0xf9938 blx 0x2e597e <FT_Get_Next_Char>
 *   @0xf993c ldr r1, [r11, #-0x234]
 *   @0xf9940 cmp r1, #0
 *   @0xf9944 mov r3, r0
 *   @0xf9948 bne 0xf9928 <_ZN7CFontGM8CreateItEv+0x2c8>
 *   @0xf994c ldr r0, [r11, #-0x238]
 *   @0xf9950 sub r1, r11, #564
 *   @0xf9954 ldr r3, [r0, #0x8]
 *   @0xf9958 and r3, r3, #64
 *   @0xf995c str r3, [r11, #-0x24c]
 *   @0xf9960 blx 0x2e59bc <FT_Get_First_Char>
 *   @0xf9964 ldr r1, [r11, #-0x234]
 *   @0xf9968 cmp r1, #0
 *   @0xf996c mov r7, r0
 *   @0xf9970 beq 0xf9b0c <_ZN7CFontGM8CreateItEv+0x4ac>
 *   @0xf9974 ldr r12, [pc, #0x474]
 *   @0xf9978 mov r9, #1
 *   @0xf997c str r5, [r11, #-0x254]
 *   @0xf9980 add r12, pc, r12
 *   @0xf9984 str r12, [r11, #-0x25c]
 *   @0xf9988 sub r12, r11, #552
 *   @0xf998c str r12, [r11, #-0x244]
 *   @0xf9990 sub r12, r11, #560
 *   @0xf9994 str r12, [r11, #-0x268]
 *   @0xf9998 ldr r0, [r11, #-0x238]
 *   @0xf999c mov r2, #0
 *   @0xf99a0 blx 0x2e7564 <FT_Load_Glyph>
 *   @0xf99a4 ldr r12, [r11, #-0x24c]
 *   @0xf99a8 ldr r3, [r11, #-0x238]
 *   @0xf99ac cmp r12, #0
 *   @0xf99b0 ldr r10, [r3, #0x54]
 *   @0xf99b4 beq 0xf9d90 <_ZN7CFontGM8CreateItEv+0x730>
 *   @0xf99b8 ldr r12, [r11, #-0x264]
 *   @0xf99bc mov r4, #0
 *   @0xf99c0 sub r8, r11, #560
 *   @0xf99c4 str r10, [r11, #-0x260]
 *   @0xf99c8 sub r6, r12, #4
 *   @0xf99cc mov r10, r9
 *   @0xf99d0 mov r9, r4
 *   @0xf99d4 ldr r5, [r6, #0x4]!
 *   @0xf99d8 cmp r7, r5
 *   @0xf99dc beq 0xf9a2c <_ZN7CFontGM8CreateItEv+0x3cc>
 *   @0xf99e0 ldr r0, [r11, #-0x238]
 *   @0xf99e4 mov r1, r5
 *   @0xf99e8 str r8, [sp]
 *   @0xf99ec mov r2, r7
 *   @0xf99f0 mov r3, #0
 *   @0xf99f4 blx 0x2e581c <FT_Get_Kerning>
 *   @0xf99f8 cmp r0, #0
 *   @0xf99fc bne 0xf9a2c <_ZN7CFontGM8CreateItEv+0x3cc>
 *   @0xf9a00 ldr r3, [r11, #-0x230]
 *   @0xf9a04 cmp r3, #0
 *   @0xf9a08 beq 0xf9a2c <_ZN7CFontGM8CreateItEv+0x3cc>
 *   @0xf9a0c lsl r2, r9, #2
 *   @0xf9a10 sub lr, r11, #552
 *   @0xf9a14 add r3, r3, #63
 *   @0xf9a18 add r1, lr, r2
 *   @0xf9a1c add r9, r9, #1
 *   @0xf9a20 strh r5, [lr, r2]
 *   @0xf9a24 asr r3, r3, #6
 *   @0xf9a28 strh r3, [r1, #2]
 *   @0xf9a2c add r4, r4, #1
 *   @0xf9a30 cmp r4, r10
 *   @0xf9a34 blt 0xf99d4 <_ZN7CFontGM8CreateItEv+0x374>
 *   @0xf9a38 mov r8, r9
 *   @0xf9a3c mov r9, r10
 *   @0xf9a40 lsl r4, r8, #2
 *   @0xf9a44 ldr r10, [r11, #-0x260]
 *   @0xf9a48 uxth r8, r8
 *   @0xf9a4c add r0, r4, #16
 *   @0xf9a50 ldr r1, [r11, #-0x25c]
 *   @0xf9a54 movw r2, #0x85e
 *   @0xf9a58 mov r3, #1
 *   @0xf9a5c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf9a60 ldr r1, [r10, #0x24]
 *   @0xf9a64 ldr r12, [r11, #-0x258]
 *   @0xf9a68 mov r2, r4
 *   @0xf9a6c ldr r4, [r10, #0x18]
 *   @0xf9a70 mvn lr, #0
 *   @0xf9a74 rsb r1, r1, r12
 *   @0xf9a78 ldr r12, [r11, #-0x254]
 *   @0xf9a7c add r4, r4, #63
 *   @0xf9a80 ldr r5, [r12, #0x44]
 *   @0xf9a84 asr r4, r4, #6
 *   @0xf9a88 ldr r12, [r10, #0x20]
 *   @0xf9a8c add r12, r12, #63
 *   @0xf9a90 asr r12, r12, #6
 *   @0xf9a94 mov r3, r0
 *   @0xf9a98 ldr r0, [r10, #0x1c]
 *   @0xf9a9c add r1, r1, r0
 *   @0xf9aa0 ldr r0, [r10, #0x28]
 *   @0xf9aa4 add r1, r1, #63
 *   @0xf9aa8 str r3, [r5, r9, lsl #2]
 *   @0xf9aac add r0, r0, #63
 *   @0xf9ab0 strh r7, [r3]
 *   @0xf9ab4 asr r1, r1, #6
 *   @0xf9ab8 strh r4, [r3, #6]
 *   @0xf9abc strh r1, [r3, #8]
 *   @0xf9ac0 asr r0, r0, #6
 *   @0xf9ac4 strh r12, [r3, #12]
 *   @0xf9ac8 sub r1, r11, #552
 *   @0xf9acc strh r0, [r3, #10]
 *   @0xf9ad0 add r0, r3, #16
 *   @0xf9ad4 strh r8, [r3, #14]
 *   @0xf9ad8 add r9, r9, #1
 *   @0xf9adc strh lr, [r3, #2]
 *   @0xf9ae0 strh lr, [r3, #4]
 *   @0xf9ae4 bl 0xb65bc <memcpy@plt>
 *   @0xf9ae8 mov r1, r7
 *   @0xf9aec ldr r0, [r11, #-0x238]
 *   @0xf9af0 sub r2, r11, #564
 *   @0xf9af4 blx 0x2e597e <FT_Get_Next_Char>
 *   @0xf9af8 ldr r1, [r11, #-0x234]
 *   @0xf9afc cmp r1, #0
 *   @0xf9b00 mov r7, r0
 *   @0xf9b04 bne 0xf9998 <_ZN7CFontGM8CreateItEv+0x338>
 *   @0xf9b08 ldr r5, [r11, #-0x254]
 *   @0xf9b0c ldr r3, [pc, #0x2e0]
 *   @0xf9b10 mov r2, #4
 *   @0xf9b14 ldr r0, [r5, #0x44]
 *   @0xf9b18 ldr r1, [r5, #0x40]
 *   @0xf9b1c add r3, pc, r3
 *   @0xf9b20 bl 0xb66dc <qsort@plt>
 *   @0xf9b24 ldr r4, [r11, #-0x238]
 *   @0xf9b28 ldr r2, [pc, #0x2c8]
 *   @0xf9b2c ldr r12, [r11, #-0x240]
 *   @0xf9b30 ldr r3, [r4, #0x58]
 *   @0xf9b34 ldr r9, [r3, #0x20]
 *   @0xf9b38 ldr r8, [r3, #0x24]
 *   @0xf9b3c add r9, r9, #63
 *   @0xf9b40 add r8, r8, #63
 *   @0xf9b44 asr r9, r9, #6
 *   @0xf9b48 str r9, [r5, #0x2c]
 *   @0xf9b4c ldr r3, [r12, r2]
 *   @0xf9b50 asr r8, r8, #6
 *   @0xf9b54 add r8, r8, #4
 *   @0xf9b58 add r9, r9, #4
 *   @0xf9b5c ldr r6, [r3]
 *   @0xf9b60 mov r1, r8
 *   @0xf9b64 mul r8, r9, r8
 *   @0xf9b68 mov r0, r6
 *   @0xf9b6c bl 0x318d10 <__divsi3>
 *   @0xf9b70 mov r1, r9
 *   @0xf9b74 mov r7, r0
 *   @0xf9b78 mov r0, r6
 *   @0xf9b7c bl 0x318d10 <__divsi3>
 *   @0xf9b80 mov r1, r8
 *   @0xf9b84 mul r7, r0, r7
 *   @0xf9b88 mul r0, r6, r6
 *   @0xf9b8c bl 0x318d10 <__divsi3>
 *   @0xf9b90 cmp r7, r0
 *   @0xf9b94 ble 0xf9bb0 <_ZN7CFontGM8CreateItEv+0x550>
 *   @0xf9b98 lsl r6, r6, #1
 *   @0xf9b9c mov r1, r8
 *   @0xf9ba0 mul r0, r6, r6
 *   @0xf9ba4 bl 0x318d10 <__divsi3>
 *   @0xf9ba8 cmp r7, r0
 *   @0xf9bac bgt 0xf9b98 <_ZN7CFontGM8CreateItEv+0x538>
 *   @0xf9bb0 mov r2, #0
 *   @0xf9bb4 mov r12, #4
 *   @0xf9bb8 mov r3, r2
 *   @0xf9bbc mov r0, r6
 *   @0xf9bc0 mov r1, r6
 *   @0xf9bc4 str r12, [sp]
 *   @0xf9bc8 bl 0x173a24 <_Z23GR_Texture_Create_Emptyiibbi>
 *   @0xf9bcc ldr r3, [pc, #0x228]
 *   @0xf9bd0 ldr r12, [r11, #-0x240]
 *   @0xf9bd4 str r0, [r5, #0x68]
 *   @0xf9bd8 ldr r3, [r12, r3]
 *   @0xf9bdc ldr r3, [r3, #0x4]
 *   @0xf9be0 ldr r3, [r3, r0, lsl #2]
 *   @0xf9be4 ldr r3, [r3]
 *   @0xf9be8 str r4, [r5, #0x70]
 *   @0xf9bec ldr r2, [r3]
 *   @0xf9bf0 ldr r6, [r3, #0x4]
 *   @0xf9bf4 sub r2, r2, #6
 *   @0xf9bf8 str r3, [r5, #0x64]
 *   @0xf9bfc cmp r2, #5
 *   @0xf9c00 ldr r7, [r3, #0x8]
 *   @0xf9c04 movhi r8, #1
 *   @0xf9c08 bls 0xf9da0 <_ZN7CFontGM8CreateItEv+0x740>
 *   @0xf9c0c cmp r7, #0
 *   @0xf9c10 ldr r0, [r3, #0x28]
 *   @0xf9c14 mul r8, r8, r6
 *   @0xf9c18 ble 0xf9c68 <_ZN7CFontGM8CreateItEv+0x608>
 *   @0xf9c1c mov lr, #0
 *   @0xf9c20 mvn r1, #0
 *   @0xf9c24 mov r12, lr
 *   @0xf9c28 cmp r6, #0
 *   @0xf9c2c ble 0xf9c58 <_ZN7CFontGM8CreateItEv+0x5f8>
 *   @0xf9c30 mov r3, r0
 *   @0xf9c34 mov r2, #0
 *   @0xf9c38 add r2, r2, #1
 *   @0xf9c3c strb r1, [r3]
 *   @0xf9c40 cmp r2, r6
 *   @0xf9c44 strb r1, [r3, #0x1]
 *   @0xf9c48 strb r1, [r3, #0x2]
 *   @0xf9c4c add r3, r3, #4
 *   @0xf9c50 strb r12, [r3, #-0x1]
 *   @0xf9c54 bne 0xf9c38 <_ZN7CFontGM8CreateItEv+0x5d8>
 *   @0xf9c58 add lr, lr, #1
 *   @0xf9c5c add r0, r0, r8
 *   @0xf9c60 cmp lr, r7
 *   @0xf9c64 bne 0xf9c28 <_ZN7CFontGM8CreateItEv+0x5c8>
 *   @0xf9c68 ldr r3, [r4, #0x58]
 *   @0xf9c6c mov r9, #2
 *   @0xf9c70 sub r0, r6, #4
 *   @0xf9c74 str r9, [r5, #0x84]
 *   @0xf9c78 str r9, [r5, #0x88]
 *   @0xf9c7c ldr r1, [r3, #0x24]
 *   @0xf9c80 ldr r4, [r3, #0x20]
 *   @0xf9c84 add r1, r1, #63
 *   @0xf9c88 str r6, [r5, #0x7c]
 *   @0xf9c8c add r4, r4, #63
 *   @0xf9c90 str r7, [r5, #0x80]
 *   @0xf9c94 asr r1, r1, #6
 *   @0xf9c98 str r1, [r5, #0x74]
 *   @0xf9c9c asr r4, r4, #6
 *   @0xf9ca0 add r1, r1, r9
 *   @0xf9ca4 str r4, [r5, #0x78]
 *   @0xf9ca8 bl 0x318d10 <__divsi3>
 *   @0xf9cac add r1, r4, r9
 *   @0xf9cb0 mov r8, r0
 *   @0xf9cb4 sub r0, r7, #4
 *   @0xf9cb8 bl 0x318d10 <__divsi3>
 *   @0xf9cbc mul r0, r0, r8
 *   @0xf9cc0 cmp r0, #0
 *   @0xf9cc4 str r0, [r5, #0x6c]
 *   @0xf9cc8 ble 0xf9dc4 <_ZN7CFontGM8CreateItEv+0x764>
 *   @0xf9ccc mov r8, #0
 *   @0xf9cd0 mov r4, r9
 *   @0xf9cd4 mov r7, r8
 *   @0xf9cd8 mov r10, r8
 *   @0xf9cdc b 0xf9ce4 <_ZN7CFontGM8CreateItEv+0x684>
 *   @0xf9ce0 mov r7, r0
 *   @0xf9ce4 mov r0, #24
 *   @0xf9ce8 add r8, r8, #1
 *   @0xf9cec bl 0x27c524 <_Znwj>
 *   @0xf9cf0 ldr r3, [r5, #0x74]
 *   @0xf9cf4 ldr r2, [r5, #0x84]
 *   @0xf9cf8 rsb r1, r3, r6
 *   @0xf9cfc add r3, r3, r2
 *   @0xf9d00 str r4, [r0, #0xc]
 *   @0xf9d04 add r4, r4, r3
 *   @0xf9d08 cmp r4, r1
 *   @0xf9d0c str r9, [r0, #0x10]
 *   @0xf9d10 str r10, [r0]
 *   @0xf9d14 ldrgt r3, [r5, #0x88]
 *   @0xf9d18 movgt r4, r2
 *   @0xf9d1c ldrgt r1, [r5, #0x78]
 *   @0xf9d20 str r7, [r0, #0x4]
 *   @0xf9d24 addgt r3, r1, r3
 *   @0xf9d28 str r10, [r0, #0x8]
 *   @0xf9d2c addgt r9, r9, r3
 *   @0xf9d30 ldr r3, [r5, #0x6c]
 *   @0xf9d34 cmp r7, #0
 *   @0xf9d38 strne r0, [r7]
 *   @0xf9d3c streq r0, [r5, #0x5c]
 *   @0xf9d40 cmp r8, r3
 *   @0xf9d44 blt 0xf9ce0 <_ZN7CFontGM8CreateItEv+0x680>
 *   @0xf9d48 ldr r12, [r5, #0x40]
 *   @0xf9d4c mov r3, #1
 *   @0xf9d50 ldr r1, [pc, #0xa8]
 *   @0xf9d54 mov r2, #2176
 *   @0xf9d58 str r0, [r5, #0x60]
 *   @0xf9d5c add r1, pc, r1
 *   @0xf9d60 lsl r0, r12, #2
 *   @0xf9d64 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf9d68 ldr r2, [r5, #0x40]
 *   @0xf9d6c mov r1, #0
 *   @0xf9d70 lsl r2, r2, #2
 *   @0xf9d74 str r0, [r5, #0x8c]
 *   @0xf9d78 bl 0xb65b0 <memset@plt>
 *   @0xf9d7c ldr r3, [r5, #0x68]
 *   @0xf9d80 mov r2, #0
 *   @0xf9d84 str r2, [r5, #0x50]
 *   @0xf9d88 str r3, [r5, #0x38]
 *   @0xf9d8c b 0xf971c <_ZN7CFontGM8CreateItEv+0xbc>
 *   @0xf9d90 ldr r8, [r11, #-0x24c]
 *   @0xf9d94 mov r0, #16
 *   @0xf9d98 mov r4, r8
 *   @0xf9d9c b 0xf9a50 <_ZN7CFontGM8CreateItEv+0x3f0>
 *   @0xf9da0 ldr r1, [pc, #0x5c]
 *   @0xf9da4 add r1, pc, r1
 *   @0xf9da8 ldr r8, [r1, r2, lsl #2]
 *   @0xf9dac b 0xf9c0c <_ZN7CFontGM8CreateItEv+0x5ac>
 *   @0xf9db0 mov r4, #4
 *   @0xf9db4 mov r3, #1
 *   @0xf9db8 str r3, [r5, #0x40]
 *   @0xf9dbc mov r0, r4
 *   @0xf9dc0 b 0xf986c <_ZN7CFontGM8CreateItEv+0x20c>
 *   @0xf9dc4 mov r0, #0
 *   @0xf9dc8 b 0xf9d48 <_ZN7CFontGM8CreateItEv+0x6e8>
 *   @0xf9dcc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xf9dd0 .word 0x002f85d8
 *   @0xf9dd4 .word 0xffffbd00
 *   @0xf9dd8 .word 0xffffc200
 *   @0xf9ddc eoreq lr, r3, r8, ror #6
 *   @0xf9de0 .word 0xffffbac4
 *   @0xf9de4 eoreq lr, r3, r12, lsr r3
 *   @0xf9de8 eoreq lr, r3, r4, ror #4
 *   @0xf9dec eoreq lr, r3, r8, lsr #5
 *   @0xf9df0 eoreq lr, r3, r4, lsl #1
 *   @0xf9df4 .word 0xffffcd8c
 *   @0xf9df8 .word 0xffffc204
 *   @0xf9dfc .word 0xffffbccc
 *   @0xf9e00 eoreq sp, r3, r8, lsr #25
 *   @0xf9e04 eoreq r2, r6, r4, ror r11
 *
 * ══ §10/16 jpeg_idct_islow  0x2c03b8  size 1900  475 条（0x2c03b8..0x2c0b24）
 * @func 0x2c03b8 0x2c0b24  size 1900  475 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×22 / 0x18×17 / 0x1c×16 / 0x20×14 / 0x10×14 / 0x14×10 / 0x40×8 / 0x60×8
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c03b8 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2c03bc sub sp, sp, #328
 *   @0x2c03c0 ldr r1, [r1, #0x50]
 *   @0x2c03c4 add r4, sp, #72
 *   @0x2c03c8 str r2, [sp, #0xc]
 *   @0x2c03cc movw r7, #0xc4df
 *   @0x2c03d0 ldr r0, [r0, #0x120]
 *   @0x2c03d4 add r2, r2, #2
 *   @0x2c03d8 ldr r5, [sp, #0xc]
 *   @0x2c03dc add r6, r1, #4
 *   @0x2c03e0 add r0, r0, #128
 *   @0x2c03e4 movw r8, #0xe333
 *   @0x2c03e8 add r5, r5, #16
 *   @0x2c03ec movt r7, #0xffff
 *   @0x2c03f0 movt r8, #0xffff
 *   @0x2c03f4 movw r9, #0xadfd
 *   @0x2c03f8 movw r10, #0xc13b
 *   @0x2c03fc movt r9, #0xffff
 *   @0x2c0400 movt r10, #0xffff
 *   @0x2c0404 movw r11, #0xf384
 *   @0x2c0408 str r3, [sp, #0x40]
 *   @0x2c040c movt r11, #0xffff
 *   @0x2c0410 str r4, [sp, #0x44]
 *   @0x2c0414 mov r3, r1
 *   @0x2c0418 str r0, [sp, #0x14]
 *   @0x2c041c str r2, [sp, #0x1c]
 *   @0x2c0420 str r5, [sp, #0x3c]
 *   @0x2c0424 str r6, [sp, #0x20]
 *   @0x2c0428 str r7, [sp, #0x28]
 *   @0x2c042c str r8, [sp, #0x2c]
 *   @0x2c0430 str r9, [sp, #0x30]
 *   @0x2c0434 str r10, [sp, #0x34]
 *   @0x2c0438 str r11, [sp, #0x38]
 *   @0x2c043c str r4, [sp, #0x10]
 *   @0x2c0440 b 0x2c0664 <jpeg_idct_islow+0x2ac>
 *   @0x2c0444 ldrh r6, [r0, #32]
 *   @0x2c0448 cmp r6, #0
 *   @0x2c044c beq 0x2c0698 <jpeg_idct_islow+0x2e0>
 *   @0x2c0450 ldr r4, [sp, #0xc]
 *   @0x2c0454 ldrh r5, [r0, #96]
 *   @0x2c0458 ldrh r12, [r0, #64]
 *   @0x2c045c ldrh r2, [r4, #80]
 *   @0x2c0460 ldrh r0, [r0, #112]
 *   @0x2c0464 ldrh r4, [r4, #48]
 *   @0x2c0468 ldr r8, [r3, #0x60]
 *   @0x2c046c sxth r4, r4
 *   @0x2c0470 ldr r10, [r3, #0xe0]
 *   @0x2c0474 sxth r0, r0
 *   @0x2c0478 ldr r7, [r3, #0xa0]
 *   @0x2c047c sxth r2, r2
 *   @0x2c0480 ldr r9, [r3, #0x20]
 *   @0x2c0484 sxth r1, r1
 *   @0x2c0488 mul r8, r8, r4
 *   @0x2c048c ldr r11, [r3, #0x40]
 *   @0x2c0490 mul r2, r7, r2
 *   @0x2c0494 sxth r6, r6
 *   @0x2c0498 mul r1, r9, r1
 *   @0x2c049c sxth r5, r5
 *   @0x2c04a0 mul r0, r10, r0
 *   @0x2c04a4 str r8, [sp, #0x18]
 *   @0x2c04a8 add r4, r2, r1
 *   @0x2c04ac ldr r10, [r3, #0xc0]
 *   @0x2c04b0 mul r6, r11, r6
 *   @0x2c04b4 add r7, r0, r8
 *   @0x2c04b8 add r9, r7, r4
 *   @0x2c04bc ldr r11, [sp, #0x18]
 *   @0x2c04c0 movw r8, #0x25a1
 *   @0x2c04c4 sxth r12, r12
 *   @0x2c04c8 mul r9, r8, r9
 *   @0x2c04cc add r8, r2, r11
 *   @0x2c04d0 ldr r11, [sp, #0x34]
 *   @0x2c04d4 mul r5, r10, r5
 *   @0x2c04d8 add r10, r0, r1
 *   @0x2c04dc mla r7, r11, r7, r9
 *   @0x2c04e0 ldr r11, [sp, #0x38]
 *   @0x2c04e4 mla r9, r11, r4, r9
 *   @0x2c04e8 ldr r4, [sp, #0x1c]
 *   @0x2c04ec ldr r11, [sp, #0x2c]
 *   @0x2c04f0 ldrsh r4, [r4, #-2]
 *   @0x2c04f4 mul r10, r11, r10
 *   @0x2c04f8 ldr r11, [sp, #0x30]
 *   @0x2c04fc str r4, [sp, #0x24]
 *   @0x2c0500 ldr r4, [sp, #0x20]
 *   @0x2c0504 mul r8, r11, r8
 *   @0x2c0508 add r11, r10, r7
 *   @0x2c050c ldr r4, [r4, #-0x4]
 *   @0x2c0510 add r10, r10, r9
 *   @0x2c0514 str r11, [sp, #0x4]
 *   @0x2c0518 ldr r11, [sp, #0x24]
 *   @0x2c051c add r9, r8, r9
 *   @0x2c0520 str r4, [sp, #0x8]
 *   @0x2c0524 add r7, r8, r7
 *   @0x2c0528 ldr r4, [r3, #0x80]
 *   @0x2c052c add r8, r6, r5
 *   @0x2c0530 mul r12, r4, r12
 *   @0x2c0534 ldr r4, [sp, #0x8]
 *   @0x2c0538 mul r4, r4, r11
 *   @0x2c053c ldr r11, [sp, #0x4]
 *   @0x2c0540 str r4, [sp, #0x24]
 *   @0x2c0544 movw r4, #0x98e
 *   @0x2c0548 mla r0, r4, r0, r11
 *   @0x2c054c movw r4, #0x1151
 *   @0x2c0550 mul r8, r4, r8
 *   @0x2c0554 ldr r4, [sp, #0x28]
 *   @0x2c0558 movw r11, #0x187e
 *   @0x2c055c mla r6, r11, r6, r8
 *   @0x2c0560 mla r5, r4, r5, r8
 *   @0x2c0564 ldr r8, [sp, #0x24]
 *   @0x2c0568 movw r4, #0x300b
 *   @0x2c056c mla r10, r4, r1, r10
 *   @0x2c0570 ldr r1, [sp, #0x18]
 *   @0x2c0574 add r11, r8, r12
 *   @0x2c0578 rsb r12, r12, r8
 *   @0x2c057c movw r8, #0x41b3
 *   @0x2c0580 mla r9, r8, r2, r9
 *   @0x2c0584 movw r2, #0x6254
 *   @0x2c0588 mla r7, r2, r1, r7
 *   @0x2c058c lsl r11, r11, #13
 *   @0x2c0590 lsl r12, r12, #13
 *   @0x2c0594 add r1, r11, r6
 *   @0x2c0598 rsb r6, r6, r11
 *   @0x2c059c add r11, r12, r5
 *   @0x2c05a0 rsb r5, r5, r12
 *   @0x2c05a4 add r2, r11, r7
 *   @0x2c05a8 add r4, r1, r10
 *   @0x2c05ac add r8, r6, r0
 *   @0x2c05b0 rsb r7, r7, r11
 *   @0x2c05b4 rsb r10, r10, r1
 *   @0x2c05b8 add r11, r5, r9
 *   @0x2c05bc rsb r0, r0, r6
 *   @0x2c05c0 rsb r9, r9, r5
 *   @0x2c05c4 ldr r5, [sp, #0x10]
 *   @0x2c05c8 add r4, r4, #1024
 *   @0x2c05cc add r10, r10, #1024
 *   @0x2c05d0 add r8, r8, #1024
 *   @0x2c05d4 add r0, r0, #1024
 *   @0x2c05d8 add r2, r2, #1024
 *   @0x2c05dc add r7, r7, #1024
 *   @0x2c05e0 add r11, r11, #1024
 *   @0x2c05e4 add r9, r9, #1024
 *   @0x2c05e8 asr r4, r4, #11
 *   @0x2c05ec asr r10, r10, #11
 *   @0x2c05f0 str r4, [r5]
 *   @0x2c05f4 asr r8, r8, #11
 *   @0x2c05f8 str r10, [r5, #0xe0]
 *   @0x2c05fc asr r0, r0, #11
 *   @0x2c0600 str r8, [r5, #0x60]
 *   @0x2c0604 asr r2, r2, #11
 *   @0x2c0608 str r0, [r5, #0x80]
 *   @0x2c060c asr r7, r7, #11
 *   @0x2c0610 str r2, [r5, #0x20]
 *   @0x2c0614 asr r11, r11, #11
 *   @0x2c0618 str r7, [r5, #0xc0]
 *   @0x2c061c asr r9, r9, #11
 *   @0x2c0620 str r11, [r5, #0x40]
 *   @0x2c0624 add r5, r5, #4
 *   @0x2c0628 str r9, [r5, #0x9c]
 *   @0x2c062c str r5, [sp, #0x10]
 *   @0x2c0630 ldr r6, [sp, #0xc]
 *   @0x2c0634 add r3, r3, #4
 *   @0x2c0638 ldr r8, [sp, #0x3c]
 *   @0x2c063c add r6, r6, #2
 *   @0x2c0640 ldr r7, [sp, #0x1c]
 *   @0x2c0644 ldr r9, [sp, #0x20]
 *   @0x2c0648 cmp r6, r8
 *   @0x2c064c add r7, r7, #2
 *   @0x2c0650 str r6, [sp, #0xc]
 *   @0x2c0654 add r9, r9, #4
 *   @0x2c0658 str r7, [sp, #0x1c]
 *   @0x2c065c str r9, [sp, #0x20]
 *   @0x2c0660 beq 0x2c06cc <jpeg_idct_islow+0x314>
 *   @0x2c0664 ldr r0, [sp, #0xc]
 *   @0x2c0668 ldrh r1, [r0, #16]
 *   @0x2c066c cmp r1, #0
 *   @0x2c0670 beq 0x2c0444 <jpeg_idct_islow+0x8c>
 *   @0x2c0674 ldr r2, [sp, #0xc]
 *   @0x2c0678 ldr r7, [sp, #0xc]
 *   @0x2c067c ldrh r6, [r2, #32]
 *   @0x2c0680 ldrh r5, [r2, #96]
 *   @0x2c0684 ldrh r12, [r2, #64]
 *   @0x2c0688 ldrh r0, [r2, #112]
 *   @0x2c068c ldrh r4, [r7, #48]
 *   @0x2c0690 ldrh r2, [r2, #80]
 *   @0x2c0694 b 0x2c0468 <jpeg_idct_islow+0xb0>
 *   @0x2c0698 ldr r5, [sp, #0xc]
 *   @0x2c069c ldrh r2, [r5, #48]
 *   @0x2c06a0 cmp r2, #0
 *   @0x2c06a4 beq 0x2c0960 <jpeg_idct_islow+0x5a8>
 *   @0x2c06a8 ldr r6, [sp, #0xc]
 *   @0x2c06ac mov r4, r2
 *   @0x2c06b0 ldr r7, [sp, #0xc]
 *   @0x2c06b4 ldrh r5, [r5, #96]
 *   @0x2c06b8 ldrh r12, [r6, #64]
 *   @0x2c06bc mov r6, r1
 *   @0x2c06c0 ldrh r0, [r7, #112]
 *   @0x2c06c4 ldrh r2, [r7, #80]
 *   @0x2c06c8 b 0x2c0468 <jpeg_idct_islow+0xb0>
 *   @0x2c06cc movw r12, #0xadfd
 *   @0x2c06d0 movt r12, #0xffff
 *   @0x2c06d4 str r12, [sp, #0x2c]
 *   @0x2c06d8 add r12, sp, #72
 *   @0x2c06dc movw r10, #0xc4df
 *   @0x2c06e0 movw r11, #0xe333
 *   @0x2c06e4 movt r10, #0xffff
 *   @0x2c06e8 movt r11, #0xffff
 *   @0x2c06ec movw r0, #0xc13b
 *   @0x2c06f0 movw r1, #0xf384
 *   @0x2c06f4 movt r0, #0xffff
 *   @0x2c06f8 movt r1, #0xffff
 *   @0x2c06fc mov r2, #0
 *   @0x2c0700 str r10, [sp, #0x24]
 *   @0x2c0704 str r11, [sp, #0x28]
 *   @0x2c0708 mov r4, r12
 *   @0x2c070c str r0, [sp, #0x30]
 *   @0x2c0710 str r1, [sp, #0x34]
 *   @0x2c0714 str r2, [sp, #0x10]
 *   @0x2c0718 b 0x2c08f4 <jpeg_idct_islow+0x53c>
 *   @0x2c071c cmp r1, #0
 *   @0x2c0720 beq 0x2c093c <jpeg_idct_islow+0x584>
 *   @0x2c0724 ldr r7, [r4, #0x1c]
 *   @0x2c0728 ldr r11, [r4, #0x18]
 *   @0x2c072c ldr r6, [r4, #0x10]
 *   @0x2c0730 ldr r2, [r4, #0x14]
 *   @0x2c0734 ldr r3, [r4, #0xc]
 *   @0x2c0738 str r7, [sp, #0x18]
 *   @0x2c073c ldr r10, [sp, #0x18]
 *   @0x2c0740 add r7, r0, r2
 *   @0x2c0744 add r5, r1, r11
 *   @0x2c0748 add r9, r10, r3
 *   @0x2c074c add r8, r0, r10
 *   @0x2c0750 add r12, r9, r7
 *   @0x2c0754 movw r10, #0x25a1
 *   @0x2c0758 mul r12, r10, r12
 *   @0x2c075c ldr r10, [sp, #0x34]
 *   @0x2c0760 mla r7, r10, r7, r12
 *   @0x2c0764 ldr r10, [sp, #0x28]
 *   @0x2c0768 mul r8, r10, r8
 *   @0x2c076c ldr r10, [r4], #32
 *   @0x2c0770 str r8, [sp, #0x20]
 *   @0x2c0774 movw r8, #0x1151
 *   @0x2c0778 mul r5, r8, r5
 *   @0x2c077c add r8, r2, r3
 *   @0x2c0780 str r8, [sp, #0x3c]
 *   @0x2c0784 movw r8, #0x187e
 *   @0x2c0788 mla r1, r8, r1, r5
 *   @0x2c078c ldr r8, [sp, #0x20]
 *   @0x2c0790 add r8, r8, r7
 *   @0x2c0794 str r8, [sp, #0x44]
 *   @0x2c0798 str r1, [sp, #0x38]
 *   @0x2c079c ldr r1, [sp, #0x30]
 *   @0x2c07a0 mla r12, r1, r9, r12
 *   @0x2c07a4 ldr r9, [sp, #0x2c]
 *   @0x2c07a8 movw r1, #0x300b
 *   @0x2c07ac str r12, [sp, #0x4]
 *   @0x2c07b0 ldr r12, [sp, #0x3c]
 *   @0x2c07b4 mul r8, r9, r12
 *   @0x2c07b8 ldr r12, [sp, #0x44]
 *   @0x2c07bc mla r9, r1, r0, r12
 *   @0x2c07c0 add r0, r10, r6
 *   @0x2c07c4 ldr r1, [sp, #0x24]
 *   @0x2c07c8 rsb r6, r6, r10
 *   @0x2c07cc ldr r10, [sp, #0x38]
 *   @0x2c07d0 lsl r0, r0, #13
 *   @0x2c07d4 ldr r12, [sp, #0x4]
 *   @0x2c07d8 lsl r6, r6, #13
 *   @0x2c07dc mla r5, r1, r11, r5
 *   @0x2c07e0 add r11, r0, r10
 *   @0x2c07e4 add r10, r11, r9
 *   @0x2c07e8 rsb r9, r9, r11
 *   @0x2c07ec add r11, r8, r12
 *   @0x2c07f0 movw r1, #0x6254
 *   @0x2c07f4 add r10, r10, #131072
 *   @0x2c07f8 ldr r12, [sp, #0x168]
 *   @0x2c07fc mla r3, r1, r3, r11
 *   @0x2c0800 ldr r11, [sp, #0x14]
 *   @0x2c0804 ubfx r10, r10, #0x12, #0xa
 *   @0x2c0808 ldr r1, [sp, #0x1c]
 *   @0x2c080c add r9, r9, #131072
 *   @0x2c0810 add r7, r8, r7
 *   @0x2c0814 ldrb r10, [r11, r10]
 *   @0x2c0818 ubfx r9, r9, #0x12, #0xa
 *   @0x2c081c add r11, r6, r5
 *   @0x2c0820 rsb r5, r5, r6
 *   @0x2c0824 add r8, r11, r3
 *   @0x2c0828 rsb r3, r3, r11
 *   @0x2c082c strb r10, [r1, r12]
 *   @0x2c0830 add r8, r8, #131072
 *   @0x2c0834 ldr r10, [sp, #0x14]
 *   @0x2c0838 movw r12, #0x41b3
 *   @0x2c083c ldr r1, [sp, #0xc]
 *   @0x2c0840 ubfx r8, r8, #0x12, #0xa
 *   @0x2c0844 mla r7, r12, r2, r7
 *   @0x2c0848 ldrb r9, [r10, r9]
 *   @0x2c084c ldr r2, [sp, #0x20]
 *   @0x2c0850 add r3, r3, #131072
 *   @0x2c0854 ldr r6, [sp, #0x4]
 *   @0x2c0858 ubfx r3, r3, #0x12, #0xa
 *   @0x2c085c strb r9, [r1, #0x7]
 *   @0x2c0860 ldrb r9, [r10, r8]
 *   @0x2c0864 add r12, r2, r6
 *   @0x2c0868 add r2, r5, r7
 *   @0x2c086c ldr r8, [sp, #0x18]
 *   @0x2c0870 add r2, r2, #131072
 *   @0x2c0874 ldr r11, [sp, #0xc]
 *   @0x2c0878 strb r9, [r1, #0x1]
 *   @0x2c087c ubfx r2, r2, #0x12, #0xa
 *   @0x2c0880 ldrb r3, [r10, r3]
 *   @0x2c0884 movw r9, #0x98e
 *   @0x2c0888 mla r12, r9, r8, r12
 *   @0x2c088c rsb r7, r7, r5
 *   @0x2c0890 strb r3, [r1, #0x6]
 *   @0x2c0894 add r7, r7, #131072
 *   @0x2c0898 ldrb r3, [r10, r2]
 *   @0x2c089c ubfx r7, r7, #0x12, #0xa
 *   @0x2c08a0 ldr r10, [sp, #0x38]
 *   @0x2c08a4 strb r3, [r11, #0x2]
 *   @0x2c08a8 rsb r1, r10, r0
 *   @0x2c08ac ldr r0, [sp, #0x14]
 *   @0x2c08b0 add r2, r1, r12
 *   @0x2c08b4 add r2, r2, #131072
 *   @0x2c08b8 rsb r12, r12, r1
 *   @0x2c08bc ubfx r2, r2, #0x12, #0xa
 *   @0x2c08c0 add r12, r12, #131072
 *   @0x2c08c4 ldrb r3, [r0, r7]
 *   @0x2c08c8 ubfx r12, r12, #0x12, #0xa
 *   @0x2c08cc strb r3, [r11, #0x5]
 *   @0x2c08d0 ldrb r3, [r0, r2]
 *   @0x2c08d4 strb r3, [r11, #0x3]
 *   @0x2c08d8 ldrb r3, [r0, r12]
 *   @0x2c08dc strb r3, [r11, #0x4]
 *   @0x2c08e0 ldr r1, [sp, #0x10]
 *   @0x2c08e4 add r1, r1, #4
 *   @0x2c08e8 str r1, [sp, #0x10]
 *   @0x2c08ec cmp r1, #32
 *   @0x2c08f0 beq 0x2c0988 <jpeg_idct_islow+0x5d0>
 *   @0x2c08f4 ldr r5, [sp, #0x40]
 *   @0x2c08f8 ldr r3, [sp, #0x10]
 *   @0x2c08fc ldr r0, [r4, #0x4]
 *   @0x2c0900 ldr r6, [sp, #0x168]
 *   @0x2c0904 ldr r3, [r5, r3]
 *   @0x2c0908 cmp r0, #0
 *   @0x2c090c ldr r1, [r4, #0x8]
 *   @0x2c0910 add r6, r3, r6
 *   @0x2c0914 str r6, [sp, #0xc]
 *   @0x2c0918 str r3, [sp, #0x1c]
 *   @0x2c091c beq 0x2c071c <jpeg_idct_islow+0x364>
 *   @0x2c0920 ldr r8, [r4, #0x1c]
 *   @0x2c0924 ldr r11, [r4, #0x18]
 *   @0x2c0928 ldr r6, [r4, #0x10]
 *   @0x2c092c str r8, [sp, #0x18]
 *   @0x2c0930 ldr r2, [r4, #0x14]
 *   @0x2c0934 ldr r3, [r4, #0xc]
 *   @0x2c0938 b 0x2c073c <jpeg_idct_islow+0x384>
 *   @0x2c093c ldr r3, [r4, #0xc]
 *   @0x2c0940 cmp r3, #0
 *   @0x2c0944 beq 0x2c0994 <jpeg_idct_islow+0x5dc>
 *   @0x2c0948 ldr r8, [r4, #0x1c]
 *   @0x2c094c ldr r11, [r4, #0x18]
 *   @0x2c0950 ldr r6, [r4, #0x10]
 *   @0x2c0954 str r8, [sp, #0x18]
 *   @0x2c0958 ldr r2, [r4, #0x14]
 *   @0x2c095c b 0x2c073c <jpeg_idct_islow+0x384>
 *   @0x2c0960 ldr r8, [sp, #0xc]
 *   @0x2c0964 ldrh r12, [r8, #64]
 *   @0x2c0968 cmp r12, #0
 *   @0x2c096c beq 0x2c09b8 <jpeg_idct_islow+0x600>
 *   @0x2c0970 ldrh r5, [r8, #96]
 *   @0x2c0974 mov r4, r1
 *   @0x2c0978 ldrh r0, [r8, #112]
 *   @0x2c097c mov r6, r1
 *   @0x2c0980 ldrh r2, [r8, #80]
 *   @0x2c0984 b 0x2c0468 <jpeg_idct_islow+0xb0>
 *   @0x2c0988 add sp, sp, #328
 *   @0x2c098c pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2c0990 bx lr
 *   @0x2c0994 ldr r6, [r4, #0x10]
 *   @0x2c0998 cmp r6, #0
 *   @0x2c099c beq 0x2c0a30 <jpeg_idct_islow+0x678>
 *   @0x2c09a0 ldr r9, [r4, #0x1c]
 *   @0x2c09a4 mov r1, r3
 *   @0x2c09a8 ldr r11, [r4, #0x18]
 *   @0x2c09ac ldr r2, [r4, #0x14]
 *   @0x2c09b0 str r9, [sp, #0x18]
 *   @0x2c09b4 b 0x2c073c <jpeg_idct_islow+0x384>
 *   @0x2c09b8 ldr r9, [sp, #0xc]
 *   @0x2c09bc ldrh r2, [r9, #80]
 *   @0x2c09c0 cmp r2, #0
 *   @0x2c09c4 bne 0x2c0ab0 <jpeg_idct_islow+0x6f8>
 *   @0x2c09c8 ldr r10, [sp, #0xc]
 *   @0x2c09cc ldrh r5, [r10, #96]
 *   @0x2c09d0 cmp r5, #0
 *   @0x2c09d4 bne 0x2c0ac8 <jpeg_idct_islow+0x710>
 *   @0x2c09d8 ldr r11, [sp, #0xc]
 *   @0x2c09dc ldrh r0, [r11, #112]
 *   @0x2c09e0 cmp r0, #0
 *   @0x2c09e4 bne 0x2c0af8 <jpeg_idct_islow+0x740>
 *   @0x2c09e8 ldr r12, [sp, #0x1c]
 *   @0x2c09ec ldr r0, [sp, #0x20]
 *   @0x2c09f0 ldrsh r2, [r12, #-2]
 *   @0x2c09f4 ldr r1, [r0, #-0x4]
 *   @0x2c09f8 mul r2, r1, r2
 *   @0x2c09fc ldr r1, [sp, #0x10]
 *   @0x2c0a00 add r1, r1, #4
 *   @0x2c0a04 lsl r2, r2, #2
 *   @0x2c0a08 str r2, [r1, #-0x4]
 *   @0x2c0a0c str r2, [r1, #0x1c]
 *   @0x2c0a10 str r2, [r1, #0x3c]
 *   @0x2c0a14 str r2, [r1, #0x5c]
 *   @0x2c0a18 str r2, [r1, #0x7c]
 *   @0x2c0a1c str r2, [r1, #0x9c]
 *   @0x2c0a20 str r2, [r1, #0xbc]
 *   @0x2c0a24 str r2, [r1, #0xdc]
 *   @0x2c0a28 str r1, [sp, #0x10]
 *   @0x2c0a2c b 0x2c0630 <jpeg_idct_islow+0x278>
 *   @0x2c0a30 ldr r2, [r4, #0x14]
 *   @0x2c0a34 ldr r11, [r4, #0x18]
 *   @0x2c0a38 cmp r2, #0
 *   @0x2c0a3c bne 0x2c0a9c <jpeg_idct_islow+0x6e4>
 *   @0x2c0a40 cmp r11, #0
 *   @0x2c0a44 bne 0x2c0ae0 <jpeg_idct_islow+0x728>
 *   @0x2c0a48 ldr r1, [r4, #0x1c]
 *   @0x2c0a4c cmp r1, #0
 *   @0x2c0a50 str r1, [sp, #0x18]
 *   @0x2c0a54 bne 0x2c0b10 <jpeg_idct_islow+0x758>
 *   @0x2c0a58 ldr r3, [r4], #32
 *   @0x2c0a5c ldr r2, [sp, #0x14]
 *   @0x2c0a60 add r3, r3, #16
 *   @0x2c0a64 ldr r7, [sp, #0xc]
 *   @0x2c0a68 ubfx r3, r3, #0x5, #0xa
 *   @0x2c0a6c ldr r6, [sp, #0x1c]
 *   @0x2c0a70 ldr r5, [sp, #0x168]
 *   @0x2c0a74 ldrb r3, [r2, r3]
 *   @0x2c0a78 strb r3, [r6, r5]
 *   @0x2c0a7c strb r3, [r7, #0x1]
 *   @0x2c0a80 strb r3, [r7, #0x2]
 *   @0x2c0a84 strb r3, [r7, #0x3]
 *   @0x2c0a88 strb r3, [r7, #0x4]
 *   @0x2c0a8c strb r3, [r7, #0x5]
 *   @0x2c0a90 strb r3, [r7, #0x6]
 *   @0x2c0a94 strb r3, [r7, #0x7]
 *   @0x2c0a98 b 0x2c08e0 <jpeg_idct_islow+0x528>
 *   @0x2c0a9c ldr r10, [r4, #0x1c]
 *   @0x2c0aa0 mov r3, r6
 *   @0x2c0aa4 mov r1, r6
 *   @0x2c0aa8 str r10, [sp, #0x18]
 *   @0x2c0aac b 0x2c073c <jpeg_idct_islow+0x384>
 *   @0x2c0ab0 ldrh r5, [r9, #96]
 *   @0x2c0ab4 mov r4, r1
 *   @0x2c0ab8 ldrh r0, [r9, #112]
 *   @0x2c0abc mov r12, r1
 *   @0x2c0ac0 mov r6, r1
 *   @0x2c0ac4 b 0x2c0468 <jpeg_idct_islow+0xb0>
 *   @0x2c0ac8 ldrh r0, [r10, #112]
 *   @0x2c0acc mov r4, r1
 *   @0x2c0ad0 mov r2, r1
 *   @0x2c0ad4 mov r12, r1
 *   @0x2c0ad8 mov r6, r1
 *   @0x2c0adc b 0x2c0468 <jpeg_idct_islow+0xb0>
 *   @0x2c0ae0 ldr r12, [r4, #0x1c]
 *   @0x2c0ae4 mov r3, r2
 *   @0x2c0ae8 mov r6, r2
 *   @0x2c0aec mov r1, r2
 *   @0x2c0af0 str r12, [sp, #0x18]
 *   @0x2c0af4 b 0x2c073c <jpeg_idct_islow+0x384>
 *   @0x2c0af8 mov r4, r1
 *   @0x2c0afc mov r2, r1
 *   @0x2c0b00 mov r12, r1
 *   @0x2c0b04 mov r5, r1
 *   @0x2c0b08 mov r6, r1
 *   @0x2c0b0c b 0x2c0468 <jpeg_idct_islow+0xb0>
 *   @0x2c0b10 mov r3, r11
 *   @0x2c0b14 mov r2, r11
 *   @0x2c0b18 mov r6, r11
 *   @0x2c0b1c mov r1, r11
 *   @0x2c0b20 b 0x2c073c <jpeg_idct_islow+0x384>
 *
 * ══ §11/16 IncrementalMarkAndSweep()  0xd6fec  size 1872  468 条（0xd6fec..0xd773c）
 * @func 0xd6fec 0xd773c  size 1872  468 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd6ff8→0x47f295, 0xd7010→0x536f0c, 0xd7020→0x3f2078, 0xd70ac→0x47a230, 0xd70b8→0x3f207c, 0xd70c4→0x47a22c, 0xd71c8→0x536f08, 0xd7260→0x47a228
 * 调用序列: YYObjectBase::MarkThisOnly4GC(unsigned int*, int)×5 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / YYObjectBase::Free(YYObjectBase*) / IncrementalMarkAndSweep()+0x2d8 / YYObjectBase::MarkOnlyChildren4GC(unsigned int*, int) / 0xb65b0 / DS_AutoMutex::DS_AutoMutex() / IncrementalMarkAndSweep()+0x484
 * 字段偏移 top8: 0x10×19 / 0x4×9 / 0xc×9 / 0x18×6 / 0x2c×5 / 0x20×4 / 0x28×4 / 0x30×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd6fec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd6ff0 sub sp, sp, #100
 *   @0xd6ff4 ldr r6, [pc, #0x6b0]
 *   @0xd6ff8 ldr r3, [pc, #0x6b0]
 *   @0xd6ffc add r6, pc, r6
 *   @0xd7000 ldr r3, [r6, r3]
 *   @0xd7004 ldrb r3, [r3]
 *   @0xd7008 cmp r3, #0
 *   @0xd700c beq 0xd7258 <_Z23IncrementalMarkAndSweepv+0x26c>
 *   @0xd7010 ldr r2, [pc, #0x69c]
 *   @0xd7014 mov r7, #10
 *   @0xd7018 str r7, [sp, #0x18]
 *   @0xd701c ldr r7, [pc, #0x694]
 *   @0xd7020 ldr r3, [pc, #0x694]
 *   @0xd7024 add r7, pc, r7
 *   @0xd7028 str r7, [sp, #0x24]
 *   @0xd702c ldr r2, [r6, r2]
 *   @0xd7030 ldr r7, [pc, #0x688]
 *   @0xd7034 str r2, [sp, #0x20]
 *   @0xd7038 add r7, pc, r7
 *   @0xd703c ldr r3, [r6, r3]
 *   @0xd7040 str r7, [sp, #0x38]
 *   @0xd7044 ldr r7, [pc, #0x678]
 *   @0xd7048 str r3, [sp, #0x2c]
 *   @0xd704c add r7, pc, r7
 *   @0xd7050 str r7, [sp, #0x34]
 *   @0xd7054 ldr r7, [pc, #0x66c]
 *   @0xd7058 add r7, pc, r7
 *   @0xd705c str r7, [sp, #0x3c]
 *   @0xd7060 ldr r7, [pc, #0x664]
 *   @0xd7064 add r7, pc, r7
 *   @0xd7068 str r7, [sp, #0x40]
 *   @0xd706c ldr r7, [pc, #0x65c]
 *   @0xd7070 add r7, pc, r7
 *   @0xd7074 str r7, [sp, #0x44]
 *   @0xd7078 ldr r7, [sp, #0x20]
 *   @0xd707c ldr r5, [r7, #0x4]
 *   @0xd7080 ldr r7, [sp, #0x24]
 *   @0xd7084 adds r12, r5, #31
 *   @0xd7088 addmi r12, r5, #62
 *   @0xd708c ldr r3, [r7, #0xc]
 *   @0xd7090 asr r12, r12, #5
 *   @0xd7094 cmp r12, r3
 *   @0xd7098 bhi 0xd72e4 <_Z23IncrementalMarkAndSweepv+0x2f8>
 *   @0xd709c ldr r7, [sp, #0x2c]
 *   @0xd70a0 ldrb r3, [r7]
 *   @0xd70a4 cmp r3, #0
 *   @0xd70a8 bne 0xd7260 <_Z23IncrementalMarkAndSweepv+0x274>
 *   @0xd70ac ldr r3, [pc, #0x620]
 *   @0xd70b0 ldr r3, [r6, r3]
 *   @0xd70b4 str r3, [sp, #0x28]
 *   @0xd70b8 ldr r2, [pc, #0x618]
 *   @0xd70bc ldr r1, [sp, #0x28]
 *   @0xd70c0 ldr r7, [sp, #0x20]
 *   @0xd70c4 ldr r3, [pc, #0x610]
 *   @0xd70c8 ldr r4, [r1]
 *   @0xd70cc ldr r7, [r7]
 *   @0xd70d0 ldr r1, [r6, r2]
 *   @0xd70d4 ldr r2, [pc, #0x604]
 *   @0xd70d8 str r7, [sp, #0x14]
 *   @0xd70dc str r4, [r1]
 *   @0xd70e0 add r2, pc, r2
 *   @0xd70e4 ldr r3, [r6, r3]
 *   @0xd70e8 str r3, [sp, #0x30]
 *   @0xd70ec ldr r1, [sp, #0x30]
 *   @0xd70f0 ldr r3, [r2, #0x10]
 *   @0xd70f4 ldr r0, [r1]
 *   @0xd70f8 cmp r0, #0
 *   @0xd70fc add r7, r4, r0
 *   @0xd7100 asr r1, r0, #31
 *   @0xd7104 add r12, r0, #31
 *   @0xd7108 movge r12, r0
 *   @0xd710c cmp r7, r4
 *   @0xd7110 movge r7, r4
 *   @0xd7114 adds r4, r7, #31
 *   @0xd7118 lsr r1, r1, #27
 *   @0xd711c asr r9, r12, #5
 *   @0xd7120 add r0, r0, r1
 *   @0xd7124 addmi r12, r7, #62
 *   @0xd7128 movpl r12, r4
 *   @0xd712c tst r5, #31
 *   @0xd7130 and r4, r0, #31
 *   @0xd7134 str r7, [sp, #0x1c]
 *   @0xd7138 asr r12, r12, #5
 *   @0xd713c rsb r4, r1, r4
 *   @0xd7140 str r12, [sp, #0x10]
 *   @0xd7144 add r8, r3, r9, lsl #2
 *   @0xd7148 beq 0xd7178 <_Z23IncrementalMarkAndSweepv+0x18c>
 *   @0xd714c asr r1, r5, #31
 *   @0xd7150 ldr r2, [r2, #0xc]
 *   @0xd7154 mvn r0, #0
 *   @0xd7158 sub r2, r2, #-1073741823
 *   @0xd715c lsr r1, r1, #27
 *   @0xd7160 add r5, r5, r1
 *   @0xd7164 ldr r7, [r3, r2, lsl #2]
 *   @0xd7168 and r5, r5, #31
 *   @0xd716c rsb r1, r1, r5
 *   @0xd7170 orr r1, r7, r0, lsl r1
 *   @0xd7174 str r1, [r3, r2, lsl #2]
 *   @0xd7178 ldr r1, [sp, #0x10]
 *   @0xd717c cmp r9, r1
 *   @0xd7180 bge 0xd7224 <_Z23IncrementalMarkAndSweepv+0x238>
 *   @0xd7184 lsl r7, r9, #5
 *   @0xd7188 mov r11, #1
 *   @0xd718c mov r10, r6
 *   @0xd7190 sub r8, r8, #4
 *   @0xd7194 str r8, [sp, #0xc]
 *   @0xd7198 ldr r1, [sp, #0xc]
 *   @0xd719c ldr r6, [r1, #0x4]!
 *   @0xd71a0 cmn r6, #1
 *   @0xd71a4 str r1, [sp, #0xc]
 *   @0xd71a8 beq 0xd7208 <_Z23IncrementalMarkAndSweepv+0x21c>
 *   @0xd71ac cmp r4, #31
 *   @0xd71b0 bhi 0xd7208 <_Z23IncrementalMarkAndSweepv+0x21c>
 *   @0xd71b4 add r1, r7, r4
 *   @0xd71b8 ldr r3, [sp, #0x14]
 *   @0xd71bc mov r5, #0
 *   @0xd71c0 add r8, r3, r1, lsl #2
 *   @0xd71c4 ands r0, r6, r11, lsl r4
 *   @0xd71c8 ldr r2, [pc, #0x514]
 *   @0xd71cc add r4, r4, #1
 *   @0xd71d0 bne 0xd71fc <_Z23IncrementalMarkAndSweepv+0x210>
 *   @0xd71d4 ldr r3, [r8, r5]
 *   @0xd71d8 cmp r3, #0
 *   @0xd71dc mov r0, r3
 *   @0xd71e0 beq 0xd71fc <_Z23IncrementalMarkAndSweepv+0x210>
 *   @0xd71e4 ldr r1, [r10, r2]
 *   @0xd71e8 ldr r2, [r3, #0x34]
 *   @0xd71ec ldr r3, [r1]
 *   @0xd71f0 cmp r2, r3
 *   @0xd71f4 beq 0xd71fc <_Z23IncrementalMarkAndSweepv+0x210>
 *   @0xd71f8 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_>
 *   @0xd71fc cmp r4, #32
 *   @0xd7200 add r5, r5, #4
 *   @0xd7204 bne 0xd71c4 <_Z23IncrementalMarkAndSweepv+0x1d8>
 *   @0xd7208 ldr r2, [sp, #0x10]
 *   @0xd720c add r9, r9, #1
 *   @0xd7210 add r7, r7, #32
 *   @0xd7214 cmp r9, r2
 *   @0xd7218 movne r4, #0
 *   @0xd721c bne 0xd7198 <_Z23IncrementalMarkAndSweepv+0x1ac>
 *   @0xd7220 mov r6, r10
 *   @0xd7224 ldr r2, [sp, #0x28]
 *   @0xd7228 ldr r7, [sp, #0x1c]
 *   @0xd722c ldr r3, [r2]
 *   @0xd7230 cmp r7, r3
 *   @0xd7234 beq 0xd7628 <_Z23IncrementalMarkAndSweepv+0x63c>
 *   @0xd7238 ldr r1, [sp, #0x1c]
 *   @0xd723c ldr r2, [sp, #0x30]
 *   @0xd7240 str r1, [r2]
 *   @0xd7244 ldr r7, [sp, #0x18]
 *   @0xd7248 sub r7, r7, #1
 *   @0xd724c str r7, [sp, #0x18]
 *   @0xd7250 cmn r7, #1
 *   @0xd7254 bne 0xd7078 <_Z23IncrementalMarkAndSweepv+0x8c>
 *   @0xd7258 add sp, sp, #100
 *   @0xd725c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd7260 ldr r3, [pc, #0x480]
 *   @0xd7264 ldr r10, [r6, r3]
 *   @0xd7268 ldr r1, [r10]
 *   @0xd726c cmp r1, #0
 *   @0xd7270 movne r7, r1
 *   @0xd7274 beq 0xd730c <_Z23IncrementalMarkAndSweepv+0x320>
 *   @0xd7278 add r4, r5, r7
 *   @0xd727c ldr r0, [sp, #0x20]
 *   @0xd7280 cmp r4, r5
 *   @0xd7284 movge r4, r5
 *   @0xd7288 cmp r4, r7
 *   @0xd728c ldr r3, [r0]
 *   @0xd7290 ble 0xd72c4 <_Z23IncrementalMarkAndSweepv+0x2d8>
 *   @0xd7294 sub r8, r7, #-1073741823
 *   @0xd7298 ldr r9, [sp, #0x34]
 *   @0xd729c add r8, r3, r8, lsl #2
 *   @0xd72a0 ldr r0, [r8, #0x4]!
 *   @0xd72a4 mov r2, r5
 *   @0xd72a8 add r7, r7, #1
 *   @0xd72ac cmp r0, #0
 *   @0xd72b0 beq 0xd72bc <_Z23IncrementalMarkAndSweepv+0x2d0>
 *   @0xd72b4 ldr r1, [r9, #0x10]
 *   @0xd72b8 bl 0x191f84 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji>
 *   @0xd72bc cmp r7, r4
 *   @0xd72c0 bne 0xd72a0 <_Z23IncrementalMarkAndSweepv+0x2b4>
 *   @0xd72c4 cmp r5, r4
 *   @0xd72c8 str r4, [r10]
 *   @0xd72cc beq 0xd7604 <_Z23IncrementalMarkAndSweepv+0x618>
 *   @0xd72d0 ldr r7, [sp, #0x2c]
 *   @0xd72d4 ldrb r3, [r7]
 *   @0xd72d8 cmp r3, #0
 *   @0xd72dc bne 0xd7244 <_Z23IncrementalMarkAndSweepv+0x258>
 *   @0xd72e0 b 0xd70ac <_Z23IncrementalMarkAndSweepv+0xc0>
 *   @0xd72e4 ldr r0, [r7, #0x10]
 *   @0xd72e8 mov r3, #0
 *   @0xd72ec lsl r1, r12, #2
 *   @0xd72f0 str r3, [sp]
 *   @0xd72f4 ldr r2, [sp, #0x38]
 *   @0xd72f8 mov r3, #752
 *   @0xd72fc str r12, [r7, #0xc]
 *   @0xd7300 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xd7304 str r0, [r7, #0x10]
 *   @0xd7308 b 0xd709c <_Z23IncrementalMarkAndSweepv+0xb0>
 *   @0xd730c ldr r3, [pc, #0x3d0]
 *   @0xd7310 ldr r7, [sp, #0x3c]
 *   @0xd7314 ldr r3, [r6, r3]
 *   @0xd7318 ldr r4, [r7, #0x10]
 *   @0xd731c ldr r2, [r7, #0xc]
 *   @0xd7320 ldr r12, [r3]
 *   @0xd7324 mov r0, r4
 *   @0xd7328 lsl r2, r2, #2
 *   @0xd732c add r12, r12, #1
 *   @0xd7330 str r12, [r3]
 *   @0xd7334 bl 0xb65b0 <memset@plt>
 *   @0xd7338 ldr r3, [pc, #0x3ac]
 *   @0xd733c mov r1, r4
 *   @0xd7340 mov r2, r5
 *   @0xd7344 ldr r3, [r6, r3]
 *   @0xd7348 ldr r0, [r3]
 *   @0xd734c bl 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji>
 *   @0xd7350 ldr r3, [pc, #0x398]
 *   @0xd7354 ldr r7, [r6, r3]
 *   @0xd7358 ldr r3, [r7]
 *   @0xd735c cmp r3, #0
 *   @0xd7360 beq 0xd75fc <_Z23IncrementalMarkAndSweepv+0x610>
 *   @0xd7364 ldr r0, [r3, #0x80]
 *   @0xd7368 cmp r0, #0
 *   @0xd736c beq 0xd7398 <_Z23IncrementalMarkAndSweepv+0x3ac>
 *   @0xd7370 ldr r4, [pc, #0x37c]
 *   @0xd7374 add r4, pc, r4
 *   @0xd7378 ldr r8, [r0, #0x178]
 *   @0xd737c mov r2, r5
 *   @0xd7380 ldr r1, [r4, #0x10]
 *   @0xd7384 bl 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji>
 *   @0xd7388 cmp r8, #0
 *   @0xd738c mov r0, r8
 *   @0xd7390 bne 0xd7378 <_Z23IncrementalMarkAndSweepv+0x38c>
 *   @0xd7394 ldr r3, [r7]
 *   @0xd7398 ldr r0, [r3, #0x8c]
 *   @0xd739c cmp r0, #0
 *   @0xd73a0 ldrne r7, [sp, #0x40]
 *   @0xd73a4 beq 0xd73c4 <_Z23IncrementalMarkAndSweepv+0x3d8>
 *   @0xd73a8 ldr r4, [r0, #0x178]
 *   @0xd73ac mov r2, r5
 *   @0xd73b0 ldr r1, [r7, #0x10]
 *   @0xd73b4 bl 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji>
 *   @0xd73b8 cmp r4, #0
 *   @0xd73bc mov r0, r4
 *   @0xd73c0 bne 0xd73a8 <_Z23IncrementalMarkAndSweepv+0x3bc>
 *   @0xd73c4 ldr r3, [pc, #0x32c]
 *   @0xd73c8 ldr r3, [r6, r3]
 *   @0xd73cc ldr r0, [r3]
 *   @0xd73d0 cmp r0, #0
 *   @0xd73d4 beq 0xd73ec <_Z23IncrementalMarkAndSweepv+0x400>
 *   @0xd73d8 ldr r3, [pc, #0x31c]
 *   @0xd73dc mov r2, r5
 *   @0xd73e0 add r3, pc, r3
 *   @0xd73e4 ldr r1, [r3, #0x10]
 *   @0xd73e8 bl 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji>
 *   @0xd73ec ldr r3, [pc, #0x30c]
 *   @0xd73f0 ldr r3, [r6, r3]
 *   @0xd73f4 ldr r0, [r3, #0x8]
 *   @0xd73f8 cmp r0, #0
 *   @0xd73fc beq 0xd7414 <_Z23IncrementalMarkAndSweepv+0x428>
 *   @0xd7400 ldr r3, [pc, #0x2fc]
 *   @0xd7404 mov r2, r5
 *   @0xd7408 add r3, pc, r3
 *   @0xd740c ldr r1, [r3, #0x10]
 *   @0xd7410 bl 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji>
 *   @0xd7414 add r11, sp, #76
 *   @0xd7418 mov r0, r11
 *   @0xd741c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xd7420 ldr r3, [pc, #0x2e0]
 *   @0xd7424 ldr r7, [r6, r3]
 *   @0xd7428 ldr r3, [r7]
 *   @0xd742c cmp r3, #0
 *   @0xd7430 ble 0xd7470 <_Z23IncrementalMarkAndSweepv+0x484>
 *   @0xd7434 ldr r3, [pc, #0x2d0]
 *   @0xd7438 mov r4, #0
 *   @0xd743c ldr r9, [sp, #0x44]
 *   @0xd7440 ldr r8, [r6, r3]
 *   @0xd7444 ldr r3, [r8, #0x4]
 *   @0xd7448 mov r2, r5
 *   @0xd744c ldr r0, [r3, r4, lsl #2]
 *   @0xd7450 add r4, r4, #1
 *   @0xd7454 cmp r0, #0
 *   @0xd7458 beq 0xd7464 <_Z23IncrementalMarkAndSweepv+0x478>
 *   @0xd745c ldr r1, [r9, #0x10]
 *   @0xd7460 bl 0x203878 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji>
 *   @0xd7464 ldr r3, [r7]
 *   @0xd7468 cmp r3, r4
 *   @0xd746c bgt 0xd7444 <_Z23IncrementalMarkAndSweepv+0x458>
 *   @0xd7470 ldr r3, [pc, #0x298]
 *   @0xd7474 ldr r8, [r6, r3]
 *   @0xd7478 ldr r3, [r8]
 *   @0xd747c cmp r3, #0
 *   @0xd7480 ble 0xd74c4 <_Z23IncrementalMarkAndSweepv+0x4d8>
 *   @0xd7484 ldr r3, [pc, #0x288]
 *   @0xd7488 mov r4, #0
 *   @0xd748c ldr r7, [pc, #0x284]
 *   @0xd7490 ldr r9, [r6, r3]
 *   @0xd7494 add r7, pc, r7
 *   @0xd7498 ldr r3, [r9, #0x4]
 *   @0xd749c mov r2, r5
 *   @0xd74a0 ldr r0, [r3, r4, lsl #2]
 *   @0xd74a4 add r4, r4, #1
 *   @0xd74a8 cmp r0, #0
 *   @0xd74ac beq 0xd74b8 <_Z23IncrementalMarkAndSweepv+0x4cc>
 *   @0xd74b0 ldr r1, [r7, #0x10]
 *   @0xd74b4 bl 0x203134 <_ZN8CDS_List19MarkOnlyChildren4GCEPji>
 *   @0xd74b8 ldr r3, [r8]
 *   @0xd74bc cmp r3, r4
 *   @0xd74c0 bgt 0xd7498 <_Z23IncrementalMarkAndSweepv+0x4ac>
 *   @0xd74c4 add r0, sp, #80
 *   @0xd74c8 ldr r4, [pc, #0x24c]
 *   @0xd74cc bl 0xffc9c <_Z12GetTheStacksRi>
 *   @0xd74d0 ldr r3, [sp, #0x50]
 *   @0xd74d4 add r4, pc, r4
 *   @0xd74d8 mov r7, #0
 *   @0xd74dc cmp r3, #0
 *   @0xd74e0 sub r8, r0, #4
 *   @0xd74e4 ble 0xd7510 <_Z23IncrementalMarkAndSweepv+0x524>
 *   @0xd74e8 ldr r0, [r8, #0x4]!
 *   @0xd74ec mov r2, r5
 *   @0xd74f0 add r7, r7, #1
 *   @0xd74f4 cmp r0, #0
 *   @0xd74f8 beq 0xd7508 <_Z23IncrementalMarkAndSweepv+0x51c>
 *   @0xd74fc ldr r1, [r4, #0x10]
 *   @0xd7500 bl 0x202dd8 <_ZN9CDS_Stack19MarkOnlyChildren4GCEPji>
 *   @0xd7504 ldr r3, [sp, #0x50]
 *   @0xd7508 cmp r3, r7
 *   @0xd750c bgt 0xd74e8 <_Z23IncrementalMarkAndSweepv+0x4fc>
 *   @0xd7510 add r0, sp, #84
 *   @0xd7514 ldr r4, [pc, #0x204]
 *   @0xd7518 bl 0xffee8 <_Z12GetTheQueuesRi>
 *   @0xd751c ldr r3, [sp, #0x54]
 *   @0xd7520 add r4, pc, r4
 *   @0xd7524 mov r7, #0
 *   @0xd7528 cmp r3, #0
 *   @0xd752c sub r8, r0, #4
 *   @0xd7530 ble 0xd755c <_Z23IncrementalMarkAndSweepv+0x570>
 *   @0xd7534 ldr r0, [r8, #0x4]!
 *   @0xd7538 mov r2, r5
 *   @0xd753c add r7, r7, #1
 *   @0xd7540 cmp r0, #0
 *   @0xd7544 beq 0xd7554 <_Z23IncrementalMarkAndSweepv+0x568>
 *   @0xd7548 ldr r1, [r4, #0x10]
 *   @0xd754c bl 0x202f60 <_ZN9CDS_Queue19MarkOnlyChildren4GCEPji>
 *   @0xd7550 ldr r3, [sp, #0x54]
 *   @0xd7554 cmp r3, r7
 *   @0xd7558 bgt 0xd7534 <_Z23IncrementalMarkAndSweepv+0x548>
 *   @0xd755c add r0, sp, #88
 *   @0xd7560 ldr r4, [pc, #0x1bc]
 *   @0xd7564 bl 0x10026c <_Z11GetTheGridsRi>
 *   @0xd7568 ldr r3, [sp, #0x58]
 *   @0xd756c add r4, pc, r4
 *   @0xd7570 mov r7, #0
 *   @0xd7574 cmp r3, #0
 *   @0xd7578 sub r8, r0, #4
 *   @0xd757c ble 0xd75a8 <_Z23IncrementalMarkAndSweepv+0x5bc>
 *   @0xd7580 ldr r0, [r8, #0x4]!
 *   @0xd7584 mov r2, r5
 *   @0xd7588 add r7, r7, #1
 *   @0xd758c cmp r0, #0
 *   @0xd7590 beq 0xd75a0 <_Z23IncrementalMarkAndSweepv+0x5b4>
 *   @0xd7594 ldr r1, [r4, #0x10]
 *   @0xd7598 bl 0x205240 <_ZN8CDS_Grid19MarkOnlyChildren4GCEPji>
 *   @0xd759c ldr r3, [sp, #0x58]
 *   @0xd75a0 cmp r3, r7
 *   @0xd75a4 bgt 0xd7580 <_Z23IncrementalMarkAndSweepv+0x594>
 *   @0xd75a8 add r0, sp, #92
 *   @0xd75ac ldr r4, [pc, #0x174]
 *   @0xd75b0 bl 0x100244 <_Z20GetThePriorityQueuesRi>
 *   @0xd75b4 ldr r3, [sp, #0x5c]
 *   @0xd75b8 add r4, pc, r4
 *   @0xd75bc mov r7, #0
 *   @0xd75c0 cmp r3, #0
 *   @0xd75c4 sub r8, r0, #4
 *   @0xd75c8 ble 0xd75f4 <_Z23IncrementalMarkAndSweepv+0x608>
 *   @0xd75cc ldr r0, [r8, #0x4]!
 *   @0xd75d0 mov r2, r5
 *   @0xd75d4 add r7, r7, #1
 *   @0xd75d8 cmp r0, #0
 *   @0xd75dc beq 0xd75ec <_Z23IncrementalMarkAndSweepv+0x600>
 *   @0xd75e0 ldr r1, [r4, #0x10]
 *   @0xd75e4 bl 0x203f14 <_ZN12CDS_Priority19MarkOnlyChildren4GCEPji>
 *   @0xd75e8 ldr r3, [sp, #0x5c]
 *   @0xd75ec cmp r3, r7
 *   @0xd75f0 bgt 0xd75cc <_Z23IncrementalMarkAndSweepv+0x5e0>
 *   @0xd75f4 mov r0, r11
 *   @0xd75f8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xd75fc ldr r7, [r10]
 *   @0xd7600 b 0xd7278 <_Z23IncrementalMarkAndSweepv+0x28c>
 *   @0xd7604 ldr r2, [pc, #0xc8]
 *   @0xd7608 mov r3, #0
 *   @0xd760c ldr r7, [sp, #0x2c]
 *   @0xd7610 strb r3, [r7]
 *   @0xd7614 ldr r2, [r6, r2]
 *   @0xd7618 str r3, [r10]
 *   @0xd761c str r2, [sp, #0x28]
 *   @0xd7620 str r5, [r2]
 *   @0xd7624 b 0xd70b8 <_Z23IncrementalMarkAndSweepv+0xcc>
 *   @0xd7628 ldr r7, [sp, #0x18]
 *   @0xd762c mov r3, #0
 *   @0xd7630 ldr r1, [sp, #0x30]
 *   @0xd7634 cmp r7, #0
 *   @0xd7638 ldr r7, [sp, #0x2c]
 *   @0xd763c str r3, [r1]
 *   @0xd7640 mov r3, #1
 *   @0xd7644 strb r3, [r7]
 *   @0xd7648 bne 0xd7244 <_Z23IncrementalMarkAndSweepv+0x258>
 *   @0xd764c ldr r4, [pc, #0xd8]
 *   @0xd7650 mov r3, #74
 *   @0xd7654 ldr r1, [pc, #0xd4]
 *   @0xd7658 add r4, pc, r4
 *   @0xd765c ldr r7, [sp, #0x18]
 *   @0xd7660 ldr r2, [pc, #0xcc]
 *   @0xd7664 ldr r5, [r6, r1]
 *   @0xd7668 ldr r1, [r4, #0xc]
 *   @0xd766c add r2, pc, r2
 *   @0xd7670 str r7, [sp]
 *   @0xd7674 ldr r0, [r5]
 *   @0xd7678 lsl r1, r1, #2
 *   @0xd767c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xd7680 ldr r12, [pc, #0xb0]
 *   @0xd7684 ldr r3, [r4, #0xc]
 *   @0xd7688 ldr r1, [r4, #0x10]
 *   @0xd768c lsl r2, r3, #2
 *   @0xd7690 str r0, [r5]
 *   @0xd7694 ldr r12, [r6, r12]
 *   @0xd7698 str r3, [r12]
 *   @0xd769c bl 0xb65bc <memcpy@plt>
 *   @0xd76a0 ldr r0, [sp, #0x18]
 *   @0xd76a4 bl 0xd6aac <_Z12MarkAndSweepP12YYObjectBase>
 *   @0xd76a8 b 0xd7258 <_Z23IncrementalMarkAndSweepv+0x26c>
 *   @0xd76ac eorseq r10, r1, r4, asr r12
 *   @0xd76b0 .word 0xffffbf68
 *   @0xd76b4 .word 0xffffc014
 *   @0xd76b8 mlaseq r10, r0, r1, r3
 *   @0xd76bc .word 0xffffc084
 *   @0xd76c0 eoreq r11, r5, r4, asr #14
 *   @0xd76c4 eorseq r3, r10, r8, ror #2
 *   @0xd76c8 eorseq r3, r10, r12, asr r1
 *   @0xd76cc eorseq r3, r10, r0, asr r1
 *   @0xd76d0 eorseq r3, r10, r4, asr #2
 *   @0xd76d4 .word 0xffffc080
 *   @0xd76d8 .word 0xffffc07c
 *   @0xd76dc .word 0xffffc078
 *   @0xd76e0 ldrsbteq r3, [r10], -r4
 *   @0xd76e4 .word 0xffffbffc
 *   @0xd76e8 .word 0xffffc088
 *   @0xd76ec .word 0xffffbf64
 *   @0xd76f0 .word 0xffffbcd8
 *   @0xd76f4 eorseq r2, r10, r0, asr #28
 *   @0xd76f8 .word 0xffffc020
 *   @0xd76fc ldrsbteq r2, [r10], -r4
 *   @0xd7700 .word 0xffffc024
 *   @0xd7704 eorseq r2, r10, r12, lsr #27
 *   @0xd7708 .word 0xffffc028
 *   @0xd770c .word 0xffffbcec
 *   @0xd7710 .word 0xffffc02c
 *   @0xd7714 .word 0xffffc030
 *   @0xd7718 eorseq r2, r10, r0, lsr #26
 *   @0xd771c eorseq r2, r10, r0, ror #25
 *   @0xd7720 mlaseq r10, r4, r12, r2
 *   @0xd7724 eorseq r2, r10, r8, asr #24
 *   @0xd7728 ldrshteq r2, [r10], -r12
 *   @0xd772c eorseq r2, r10, r12, asr r11
 *   @0xd7730 .word 0xffffc08c
 *   @0xd7734 eoreq r9, r5, r4, asr #19
 *   @0xd7738 .word 0xffffc090
 *
 * ══ §12/16 Java_com_yoyogames_runner_RunnerJNILib_RenderSplash  0x291e40  size 1864  466 条（0x291e40..0x292588）
 * @func 0x291e40 0x292588  size 1864  466 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x291e74→0x3f26dc, 0x291eac→0x3f26c0, 0x291eb8→0x3f26bc, 0x291ec8→0x479bf4, 0x291eec→0x479c90, 0x291f10→0x3f77b8, 0x291f3c→0x479c54, 0x291f50→0x479c60
 * 调用序列: 0xb65bc×2 / LoadShader(unsigned int, char const*, char**)×2 / ImportGLLibrary() / setJNIEnv / yyMatrix::OrthoLH(yyMatrix*, float, float, float, float) / Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x724 / 0xb6544 / 0xb655c
 * 字段偏移 top8: 0x8×14 / 0x4×8 / 0xc×6 / 0x23c×2 / 0x268×2 / 0x26c×2 / 0x14×2 / 0x18×2
 * VFP 指令 72 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x291e40 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x291e44 vpush {d8}
 *   @0x291e48 sub sp, sp, #576
 *   @0x291e4c ldr r4, [pc, #0x34c]
 *   @0x291e50 mov r5, r0
 *   @0x291e54 ldr r3, [pc, #0x348]
 *   @0x291e58 add r4, pc, r4
 *   @0x291e5c ldr r6, [r4, r3]
 *   @0x291e60 ldr r3, [r6]
 *   @0x291e64 str r3, [sp, #0x23c]
 *   @0x291e68 bl 0x28fce4 <_Z15ImportGLLibraryv>
 *   @0x291e6c mov r0, r5
 *   @0x291e70 bl 0x290614 <setJNIEnv>
 *   @0x291e74 ldr r3, [pc, #0x32c]
 *   @0x291e78 ldr r7, [r4, r3]
 *   @0x291e7c ldr r5, [r7]
 *   @0x291e80 cmp r5, #1
 *   @0x291e84 beq 0x29212c <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x2ec>
 *   @0x291e88 cmp r5, #0
 *   @0x291e8c beq 0x291eac <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x6c>
 *   @0x291e90 ldr r2, [sp, #0x23c]
 *   @0x291e94 ldr r3, [r6]
 *   @0x291e98 cmp r2, r3
 *   @0x291e9c bne 0x292584 <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x744>
 *   @0x291ea0 add sp, sp, #576
 *   @0x291ea4 vpop {d8}
 *   @0x291ea8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x291eac ldr r2, [pc, #0x368]
 *   @0x291eb0 mov r0, #1065353216
 *   @0x291eb4 ldr r7, [sp, #0x268]
 *   @0x291eb8 ldr r3, [pc, #0x360]
 *   @0x291ebc ldr r1, [r4, r2]
 *   @0x291ec0 mov r2, #0
 *   @0x291ec4 ldr r10, [sp, #0x26c]
 *   @0x291ec8 ldr r12, [pc, #0x2dc]
 *   @0x291ecc str r7, [r1]
 *   @0x291ed0 mov r1, r0
 *   @0x291ed4 ldr lr, [r4, r3]
 *   @0x291ed8 mov r3, r0
 *   @0x291edc str r10, [lr]
 *   @0x291ee0 ldr r12, [r4, r12]
 *   @0x291ee4 ldr r12, [r12]
 *   @0x291ee8 blx r12
 *   @0x291eec ldr r3, [pc, #0x2bc]
 *   @0x291ef0 mov r0, #16384
 *   @0x291ef4 ldr r3, [r4, r3]
 *   @0x291ef8 ldr r3, [r3]
 *   @0x291efc blx r3
 *   @0x291f00 rsb r2, r10, #0
 *   @0x291f04 vldr s8, [sp, #616]
 *   @0x291f08 vcvt.f32.s32 s16, s8
 *   @0x291f0c vmov s11, r2
 *   @0x291f10 ldr r1, [pc, #0x29c]
 *   @0x291f14 mov r3, #1065353216
 *   @0x291f18 mov r0, #0
 *   @0x291f1c movt r0, #0x46fa
 *   @0x291f20 ldr r9, [r4, r1]
 *   @0x291f24 str r0, [sp]
 *   @0x291f28 vcvt.f32.s32 s11, s11
 *   @0x291f2c mov r0, r9
 *   @0x291f30 vmov r1, s16
 *   @0x291f34 vmov r2, s11
 *   @0x291f38 bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff>
 *   @0x291f3c ldr r3, [pc, #0x274]
 *   @0x291f40 movw r0, #0x1701
 *   @0x291f44 ldr r8, [r4, r3]
 *   @0x291f48 ldr r3, [r8]
 *   @0x291f4c blx r3
 *   @0x291f50 ldr r3, [pc, #0x264]
 *   @0x291f54 ldr r7, [r4, r3]
 *   @0x291f58 ldr r3, [r7]
 *   @0x291f5c blx r3
 *   @0x291f60 ldr r3, [pc, #0x258]
 *   @0x291f64 mov r0, r9
 *   @0x291f68 ldr r9, [pc, #0x254]
 *   @0x291f6c ldr r3, [r4, r3]
 *   @0x291f70 ldr r3, [r3]
 *   @0x291f74 blx r3
 *   @0x291f78 ldr r3, [r8]
 *   @0x291f7c mov r0, #5888
 *   @0x291f80 blx r3
 *   @0x291f84 ldr r3, [r7]
 *   @0x291f88 blx r3
 *   @0x291f8c vmov.f32 s14, #1.000000e+00
 *   @0x291f90 vldr s12, [sp, #624]
 *   @0x291f94 vldr s13, [sp, #628]
 *   @0x291f98 vldr s8, [sp, #632]
 *   @0x291f9c vldr s15, [pc, #504]
 *   @0x291fa0 mvn r12, #0
 *   @0x291fa4 str r5, [sp, #0x14]
 *   @0x291fa8 str r5, [sp, #0x18]
 *   @0x291fac movw r1, #0x140c
 *   @0x291fb0 str r5, [sp, #0x2c]
 *   @0x291fb4 mov r2, #20
 *   @0x291fb8 str r5, [sp, #0x3c]
 *   @0x291fbc add r3, sp, #12
 *   @0x291fc0 str r12, [sp, #0x1c]
 *   @0x291fc4 mov r0, #2
 *   @0x291fc8 str r12, [sp, #0x30]
 *   @0x291fcc str r12, [sp, #0x44]
 *   @0x291fd0 vcvt.f32.s32 s10, s12
 *   @0x291fd4 str r12, [sp, #0x58]
 *   @0x291fd8 vcvt.f32.s32 s11, s13
 *   @0x291fdc vldr s13, [sp, #636]
 *   @0x291fe0 vdiv.f32 s10, s14, s10
 *   @0x291fe4 vdiv.f32 s11, s14, s11
 *   @0x291fe8 vmov.f32 s14, #5.000000e-01
 *   @0x291fec vcvt.f32.s32 s9, s8
 *   @0x291ff0 vldr s8, [sp, #620]
 *   @0x291ff4 vcvt.f32.s32 s12, s13
 *   @0x291ff8 vcvt.f32.s32 s13, s8
 *   @0x291ffc vmul.f32 s10, s9, s10
 *   @0x292000 vmul.f32 s16, s16, s14
 *   @0x292004 vmul.f32 s11, s12, s11
 *   @0x292008 vmul.f32 s14, s13, s14
 *   @0x29200c vnmul.f32 s12, s16, s15
 *   @0x292010 vnmul.f32 s13, s14, s15
 *   @0x292014 vmul.f32 s10, s10, s15
 *   @0x292018 vmul.f32 s11, s11, s15
 *   @0x29201c vmul.f32 s16, s16, s15
 *   @0x292020 vmul.f32 s15, s14, s15
 *   @0x292024 vcvt.s32.f32 s10, s10
 *   @0x292028 vcvt.s32.f32 s11, s11
 *   @0x29202c vstr s10, [sp, #40]
 *   @0x292030 vstr s10, [sp, #80]
 *   @0x292034 vcvt.s32.f32 s12, s12
 *   @0x292038 vstr s11, [sp, #64]
 *   @0x29203c vstr s11, [sp, #84]
 *   @0x292040 vcvt.s32.f32 s13, s13
 *   @0x292044 vstr s12, [sp, #12]
 *   @0x292048 vstr s12, [sp, #52]
 *   @0x29204c vcvt.s32.f32 s15, s15
 *   @0x292050 vstr s13, [sp, #16]
 *   @0x292054 vstr s13, [sp, #36]
 *   @0x292058 vcvt.s32.f32 s16, s16
 *   @0x29205c vstr s15, [sp, #56]
 *   @0x292060 vstr s15, [sp, #76]
 *   @0x292064 vstr s16, [sp, #32]
 *   @0x292068 vstr s16, [sp, #72]
 *   @0x29206c ldr r12, [r4, r9]
 *   @0x292070 ldr r12, [r12]
 *   @0x292074 blx r12
 *   @0x292078 ldr r3, [pc, #0x148]
 *   @0x29207c movw r0, #0x8074
 *   @0x292080 ldr r9, [r4, r3]
 *   @0x292084 ldr r3, [r9]
 *   @0x292088 blx r3
 *   @0x29208c ldr r12, [pc, #0x138]
 *   @0x292090 mov r2, #20
 *   @0x292094 movw r1, #0x140c
 *   @0x292098 add r3, sp, r2
 *   @0x29209c mov r0, #2
 *   @0x2920a0 ldr r12, [r4, r12]
 *   @0x2920a4 ldr r12, [r12]
 *   @0x2920a8 blx r12
 *   @0x2920ac ldr r3, [r9]
 *   @0x2920b0 movw r0, #0x8078
 *   @0x2920b4 blx r3
 *   @0x2920b8 ldr r12, [pc, #0x110]
 *   @0x2920bc movw r1, #0x1401
 *   @0x2920c0 mov r2, #20
 *   @0x2920c4 add r3, sp, #28
 *   @0x2920c8 mov r0, #4
 *   @0x2920cc ldr r12, [r4, r12]
 *   @0x2920d0 ldr r12, [r12]
 *   @0x2920d4 blx r12
 *   @0x2920d8 ldr r3, [r9]
 *   @0x2920dc movw r0, #0x8076
 *   @0x2920e0 blx r3
 *   @0x2920e4 ldr r3, [r8]
 *   @0x2920e8 movw r0, #0x1702
 *   @0x2920ec blx r3
 *   @0x2920f0 ldr r3, [r7]
 *   @0x2920f4 blx r3
 *   @0x2920f8 ldr r3, [pc, #0xd4]
 *   @0x2920fc movw r0, #0xde1
 *   @0x292100 ldr r3, [r4, r3]
 *   @0x292104 ldr r3, [r3]
 *   @0x292108 blx r3
 *   @0x29210c ldr r3, [pc, #0x120]
 *   @0x292110 mov r1, r5
 *   @0x292114 mov r0, #5
 *   @0x292118 mov r2, #4
 *   @0x29211c ldr r3, [r4, r3]
 *   @0x292120 ldr r3, [r3]
 *   @0x292124 blx r3
 *   @0x292128 b 0x291e90 <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x50>
 *   @0x29212c add r5, sp, #316
 *   @0x292130 ldr r1, [pc, #0xa0]
 *   @0x292134 mov r2, #254
 *   @0x292138 add r8, sp, #92
 *   @0x29213c add r1, pc, r1
 *   @0x292140 mov r0, r5
 *   @0x292144 bl 0xb65bc <memcpy@plt>
 *   @0x292148 ldr r1, [pc, #0x8c]
 *   @0x29214c mov r2, #224
 *   @0x292150 mov r0, r8
 *   @0x292154 add r1, pc, r1
 *   @0x292158 bl 0xb65bc <memcpy@plt>
 *   @0x29215c ldr r3, [pc, #0x7c]
 *   @0x292160 add r3, pc, r3
 *   @0x292164 ldr r2, [r3]
 *   @0x292168 cmp r2, #0
 *   @0x29216c beq 0x29224c <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x40c>
 *   @0x292170 ldr r2, [r3, #0x4]
 *   @0x292174 cmp r2, #0
 *   @0x292178 beq 0x29224c <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x40c>
 *   @0x29217c ldr r0, [r3, #0x8]
 *   @0x292180 cmp r0, #0
 *   @0x292184 beq 0x29224c <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x40c>
 *   @0x292188 ldr r3, [r3, #0xc]
 *   @0x29218c cmp r3, #0
 *   @0x292190 beq 0x29224c <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x40c>
 *   @0x292194 mov r2, r0
 *   @0x292198 b 0x29235c <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x51c>
 *   @0x29219c strmi r0, [r0, r0]
 *   @0x2921a0 ldrsheq pc, [r5], -r8
 *   @0x2921a4 .word 0xffffbd00
 *   @0x2921a8 .word 0xffffe7b8
 *   @0x2921ac .word 0xffffbb00
 *   @0x2921b0 .word 0xffffbacc
 *   @0x2921b4 .word 0xfffffd14
 *   @0x2921b8 .word 0xffffbc48
 *   @0x2921bc .word 0xffffbc3c
 *   @0x2921c0 .word 0xffffbcac
 *   @0x2921c4 .word 0xffffbc6c
 *   @0x2921c8 .word 0xffffbc30
 *   @0x2921cc .word 0xffffbca8
 *   @0x2921d0 .word 0xffffbc28
 *   @0x2921d4 .word 0xffffbad8
 *   @0x2921d8 andeq r6, r12, r4, lsr r12
 *   @0x2921dc andeq r6, r12, r12, lsl sp
 *   @0x2921e0 subeq r4, r12, r8, ror #20
 *   @0x2921e4 subeq r4, r12, r4, ror #18
 *   @0x2921e8 .word 0xffffbba8
 *   @0x2921ec .word 0xffffbbac
 *   @0x2921f0 .word 0xffffbbb0
 *   @0x2921f4 .word 0xffffbbb4
 *   @0x2921f8 .word 0xffffbbbc
 *   @0x2921fc andeq r6, r12, r0, asr #20
 *   @0x292200 andseq r5, r6, r12, ror r4
 *   @0x292204 andeq r6, r12, r0, lsr r10
 *   @0x292208 .word 0xffffbbc0
 *   @0x29220c andeq r6, r12, r4, lsr #20
 *   @0x292210 .word 0xffffbb80
 *   @0x292214 .word 0xffffbadc
 *   @0x292218 subeq r4, r12, r12, lsr r8
 *   @0x29221c .word 0xffffe24c
 *   @0x292220 .word 0xffffe250
 *   @0x292224 .word 0xffffbb90
 *   @0x292228 ldrheq r5, [r6], -r12
 *   @0x29222c .word 0xffffbb88
 *   @0x292230 .word 0xffffbb84
 *   @0x292234 .word 0xffffbad4
 *   @0x292238 .word 0xffffbbb8
 *   @0x29223c .word 0xffffbac4
 *   @0x292240 andeq r9, r11, r4, asr #20
 *   @0x292244 .word 0xffffbb78
 *   @0x292248 subeq r4, r12, r8, asr r6
 *   @0x29224c mov r1, r5
 *   @0x292250 mov r2, #0
 *   @0x292254 movw r0, #0x8b31
 *   @0x292258 ldr r5, [pc, #-0x7c]
 *   @0x29225c bl 0x1865bc <_Z10LoadShaderjPKcPPc>
 *   @0x292260 mov r1, r8
 *   @0x292264 add r5, pc, r5
 *   @0x292268 mov r2, #0
 *   @0x29226c str r0, [r5]
 *   @0x292270 movw r0, #0x8b30
 *   @0x292274 bl 0x1865bc <_Z10LoadShaderjPKcPPc>
 *   @0x292278 ldr r3, [pc, #-0x98]
 *   @0x29227c str r0, [r5, #0x4]
 *   @0x292280 ldr r3, [r4, r3]
 *   @0x292284 ldr r3, [r3]
 *   @0x292288 blx r3
 *   @0x29228c cmp r0, #0
 *   @0x292290 str r0, [r5, #0x8]
 *   @0x292294 beq 0x291e90 <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x50>
 *   @0x292298 ldr r3, [pc, #-0xb4]
 *   @0x29229c ldr r1, [r5]
 *   @0x2922a0 ldr r8, [r4, r3]
 *   @0x2922a4 ldr r3, [r8]
 *   @0x2922a8 blx r3
 *   @0x2922ac ldr r3, [r8]
 *   @0x2922b0 ldr r1, [r5, #0x4]
 *   @0x2922b4 ldr r0, [r5, #0x8]
 *   @0x2922b8 blx r3
 *   @0x2922bc ldr r3, [pc, #-0xd4]
 *   @0x2922c0 ldr r0, [r5, #0x8]
 *   @0x2922c4 ldr r3, [r4, r3]
 *   @0x2922c8 ldr r3, [r3]
 *   @0x2922cc blx r3
 *   @0x2922d0 ldr r3, [pc, #-0xe4]
 *   @0x2922d4 ldr r0, [r5, #0x8]
 *   @0x2922d8 movw r1, #0x8b82
 *   @0x2922dc add r2, r5, #12
 *   @0x2922e0 ldr r9, [r4, r3]
 *   @0x2922e4 ldr r3, [r9]
 *   @0x2922e8 blx r3
 *   @0x2922ec ldr r8, [r5, #0xc]
 *   @0x2922f0 cmp r8, #0
 *   @0x2922f4 beq 0x2924ec <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x6ac>
 *   @0x2922f8 ldr r3, [pc, #-0x108]
 *   @0x2922fc ldr r1, [pc, #-0x108]
 *   @0x292300 ldr r0, [r5, #0x8]
 *   @0x292304 ldr r9, [r4, r3]
 *   @0x292308 add r1, pc, r1
 *   @0x29230c ldr r8, [pc, #-0x114]
 *   @0x292310 ldr r3, [r9]
 *   @0x292314 add r8, pc, r8
 *   @0x292318 blx r3
 *   @0x29231c ldr r1, [pc, #-0x120]
 *   @0x292320 ldr r3, [r9]
 *   @0x292324 add r1, pc, r1
 *   @0x292328 str r0, [r8]
 *   @0x29232c ldr r0, [r5, #0x8]
 *   @0x292330 blx r3
 *   @0x292334 ldr r3, [pc, #-0x134]
 *   @0x292338 ldr r1, [pc, #-0x134]
 *   @0x29233c add r1, pc, r1
 *   @0x292340 str r0, [r8, #0x4]
 *   @0x292344 ldr r3, [r4, r3]
 *   @0x292348 ldr r0, [r5, #0x8]
 *   @0x29234c ldr r3, [r3]
 *   @0x292350 blx r3
 *   @0x292354 ldr r2, [r5, #0x8]
 *   @0x292358 str r0, [r8, #0x8]
 *   @0x29235c ldr r3, [pc, #-0x154]
 *   @0x292360 mov r0, r2
 *   @0x292364 ldr r3, [r4, r3]
 *   @0x292368 ldr r3, [r3]
 *   @0x29236c blx r3
 *   @0x292370 ldr r3, [pc, #-0x164]
 *   @0x292374 ldr r3, [r4, r3]
 *   @0x292378 ldr r3, [r3]
 *   @0x29237c blx r3
 *   @0x292380 cmp r0, #0
 *   @0x292384 ldrne r3, [pc, #-0x174]
 *   @0x292388 movne r2, #0
 *   @0x29238c addne r3, pc, r3
 *   @0x292390 strne r2, [r3, #0x8]
 *   @0x292394 vmov.f32 s15, #1.000000e+00
 *   @0x292398 vldr s8, [sp, #624]
 *   @0x29239c ldr r3, [pc, #-0x188]
 *   @0x2923a0 vldr s11, [sp, #632]
 *   @0x2923a4 ldr r10, [sp, #0x268]
 *   @0x2923a8 mov r12, #0
 *   @0x2923ac ldr r0, [pc, #-0x194]
 *   @0x2923b0 mov r8, #16
 *   @0x2923b4 ldr r9, [r4, r3]
 *   @0x2923b8 mov r1, #2
 *   @0x2923bc ldr lr, [pc, #-0x1a0]
 *   @0x2923c0 movw r2, #0x1406
 *   @0x2923c4 ldr r5, [pc, #-0x1a4]
 *   @0x2923c8 mov r3, #0
 *   @0x2923cc str r10, [r9]
 *   @0x2923d0 ldr r9, [r4, r0]
 *   @0x2923d4 add r5, pc, r5
 *   @0x2923d8 ldr r10, [sp, #0x26c]
 *   @0x2923dc vcvt.f32.s32 s14, s8
 *   @0x2923e0 vldr s8, [sp, #628]
 *   @0x2923e4 vstr s15, [sp, #16]
 *   @0x2923e8 vstr s15, [sp, #28]
 *   @0x2923ec vstr s15, [sp, #32]
 *   @0x2923f0 vstr s15, [sp, #60]
 *   @0x2923f4 str r10, [r9]
 *   @0x2923f8 str r12, [sp, #0x14]
 *   @0x2923fc str r12, [sp, #0x18]
 *   @0x292400 str r12, [sp, #0x28]
 *   @0x292404 vcvt.f32.s32 s13, s8
 *   @0x292408 vldr s8, [sp, #636]
 *   @0x29240c str r12, [sp, #0x34]
 *   @0x292410 mov r12, #0
 *   @0x292414 movt r12, #0xbf80
 *   @0x292418 str r12, [sp, #0xc]
 *   @0x29241c str r12, [sp, #0x2c]
 *   @0x292420 str r12, [sp, #0x30]
 *   @0x292424 str r12, [sp, #0x40]
 *   @0x292428 add r12, sp, #12
 *   @0x29242c ldr r0, [r5]
 *   @0x292430 vdiv.f32 s14, s15, s14
 *   @0x292434 vdiv.f32 s15, s15, s13
 *   @0x292438 vcvt.f32.s32 s12, s11
 *   @0x29243c vcvt.f32.s32 s13, s8
 *   @0x292440 vmul.f32 s14, s12, s14
 *   @0x292444 vmul.f32 s15, s13, s15
 *   @0x292448 vstr s14, [sp, #36]
 *   @0x29244c vstr s14, [sp, #68]
 *   @0x292450 vstr s15, [sp, #56]
 *   @0x292454 vstr s15, [sp, #72]
 *   @0x292458 ldr r9, [r4, lr]
 *   @0x29245c str r8, [sp]
 *   @0x292460 str r12, [sp, #0x4]
 *   @0x292464 ldr r12, [r9]
 *   @0x292468 blx r12
 *   @0x29246c ldr r12, [r9]
 *   @0x292470 ldr r0, [r5, #0x4]
 *   @0x292474 movw r2, #0x1406
 *   @0x292478 mov r1, #2
 *   @0x29247c str r8, [sp]
 *   @0x292480 add r3, sp, #20
 *   @0x292484 str r3, [sp, #0x4]
 *   @0x292488 mov r3, #0
 *   @0x29248c blx r12
 *   @0x292490 ldr r3, [pc, #-0x26c]
 *   @0x292494 ldr r0, [r5]
 *   @0x292498 ldr r8, [r4, r3]
 *   @0x29249c ldr r3, [r8]
 *   @0x2924a0 blx r3
 *   @0x2924a4 ldr r0, [r5, #0x4]
 *   @0x2924a8 ldr r3, [r8]
 *   @0x2924ac blx r3
 *   @0x2924b0 ldr r3, [pc, #-0x288]
 *   @0x2924b4 ldr r0, [r5, #0x8]
 *   @0x2924b8 mov r1, #0
 *   @0x2924bc ldr r3, [r4, r3]
 *   @0x2924c0 ldr r3, [r3]
 *   @0x2924c4 blx r3
 *   @0x2924c8 ldr r3, [pc, #-0x29c]
 *   @0x2924cc mov r0, #5
 *   @0x2924d0 mov r1, #0
 *   @0x2924d4 mov r2, #4
 *   @0x2924d8 ldr r3, [r4, r3]
 *   @0x2924dc ldr r3, [r3]
 *   @0x2924e0 blx r3
 *   @0x2924e4 ldr r5, [r7]
 *   @0x2924e8 b 0x291e88 <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x48>
 *   @0x2924ec add r2, sp, #576
 *   @0x2924f0 ldr r0, [r5, #0x8]
 *   @0x2924f4 ldr r3, [r9]
 *   @0x2924f8 movw r1, #0x8b84
 *   @0x2924fc str r8, [r2, #-0x234]!
 *   @0x292500 blx r3
 *   @0x292504 ldr r0, [sp, #0xc]
 *   @0x292508 cmp r0, #1
 *   @0x29250c ble 0x292564 <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x724>
 *   @0x292510 bl 0xb6544 <malloc@plt>
 *   @0x292514 ldr r12, [pc, #-0x2e4]
 *   @0x292518 mov r2, r8
 *   @0x29251c ldr r1, [sp, #0xc]
 *   @0x292520 ldr r12, [r4, r12]
 *   @0x292524 ldr r12, [r12]
 *   @0x292528 mov r7, r0
 *   @0x29252c ldr r0, [r5, #0x8]
 *   @0x292530 mov r3, r7
 *   @0x292534 blx r12
 *   @0x292538 ldr r3, [pc, #-0x304]
 *   @0x29253c ldr r1, [pc, #-0x304]
 *   @0x292540 mov r2, r7
 *   @0x292544 ldr r3, [r4, r3]
 *   @0x292548 add r1, pc, r1
 *   @0x29254c ldr r0, [r3]
 *   @0x292550 ldr r3, [r0]
 *   @0x292554 ldr r3, [r3, #0xc]
 *   @0x292558 blx r3
 *   @0x29255c mov r0, r7
 *   @0x292560 bl 0xb655c <free@plt>
 *   @0x292564 ldr r3, [pc, #-0x328]
 *   @0x292568 ldr r2, [pc, #-0x328]
 *   @0x29256c ldr r3, [r4, r3]
 *   @0x292570 add r2, pc, r2
 *   @0x292574 ldr r0, [r2, #0x8]
 *   @0x292578 ldr r3, [r3]
 *   @0x29257c blx r3
 *   @0x292580 b 0x291e90 <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x50>
 *   @0x292584 bl 0xb65d4 <__stack_chk_fail@plt>
 *
 * ══ §13/16 spAtlas_create  0x284174  size 1824  456 条（0x284174..0x284894）
 * @func 0x284174 0x284894  size 1824  456 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6670×19 / anon_283d14+0x1bc×9 / spAtlas_dispose×4 / anon_283d14+0x168×3 / 0xb65e0×3 / _malloc×3 / anon_283d14+0x2fc×3 / 0xb6538×2
 * 字段偏移 top8: 0x4×22 / 0x8×13 / 0xc×8 / 0x40×8 / 0x48×8 / 0x44×7 / 0x50×7 / 0x20×5
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284174 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x284178 sub sp, sp, #108
 *   @0x28417c add r5, r0, r1
 *   @0x284180 mov r4, r3
 *   @0x284184 str r0, [sp, #0x3c]
 *   @0x284188 mov r0, r2
 *   @0x28418c str r2, [sp, #0xc]
 *   @0x284190 bl 0xb6538 <strlen@plt>
 *   @0x284194 cmp r0, #0
 *   @0x284198 str r0, [sp, #0x14]
 *   @0x28419c ble 0x2844bc <spAtlas_create+0x348>
 *   @0x2841a0 ldr r12, [sp, #0xc]
 *   @0x2841a4 add r3, r12, r0
 *   @0x2841a8 ldrb r3, [r3, #-0x1]
 *   @0x2841ac cmp r3, #47
 *   @0x2841b0 beq 0x2844bc <spAtlas_create+0x348>
 *   @0x2841b4 subs r3, r3, #92
 *   @0x2841b8 movne r3, #1
 *   @0x2841bc str r3, [sp, #0x20]
 *   @0x2841c0 ldr r2, [pc, #0x6b0]
 *   @0x2841c4 mov r3, #182
 *   @0x2841c8 ldr r12, [pc, #0x6ac]
 *   @0x2841cc mov r0, #1
 *   @0x2841d0 mov r1, #12
 *   @0x2841d4 add r2, pc, r2
 *   @0x2841d8 add r12, pc, r12
 *   @0x2841dc str r12, [sp, #0x10]
 *   @0x2841e0 bl 0x285c4c <_calloc>
 *   @0x2841e4 ldr r3, [sp, #0x10]
 *   @0x2841e8 ldr r12, [pc, #0x690]
 *   @0x2841ec mov r8, #0
 *   @0x2841f0 add r3, r3, #32
 *   @0x2841f4 str r3, [sp, #0x28]
 *   @0x2841f8 ldr r3, [pc, #0x684]
 *   @0x2841fc add r12, pc, r12
 *   @0x284200 str r12, [sp, #0x18]
 *   @0x284204 mov r11, r8
 *   @0x284208 add r3, pc, r3
 *   @0x28420c ldr r12, [pc, #0x674]
 *   @0x284210 str r3, [sp, #0x24]
 *   @0x284214 add r10, sp, #64
 *   @0x284218 ldr r3, [pc, #0x66c]
 *   @0x28421c add r12, pc, r12
 *   @0x284220 str r8, [sp, #0x1c]
 *   @0x284224 add r3, pc, r3
 *   @0x284228 str r12, [sp, #0x2c]
 *   @0x28422c str r3, [sp, #0x30]
 *   @0x284230 str r4, [r0, #0x8]
 *   @0x284234 add r4, sp, #60
 *   @0x284238 str r0, [sp, #0x8]
 *   @0x28423c b 0x284254 <spAtlas_create+0xe0>
 *   @0x284240 ldr r2, [sp, #0x44]
 *   @0x284244 ldr r3, [sp, #0x40]
 *   @0x284248 cmp r2, r3
 *   @0x28424c bne 0x284278 <spAtlas_create+0x104>
 *   @0x284250 mov r11, #0
 *   @0x284254 mov r0, r4
 *   @0x284258 mov r1, r5
 *   @0x28425c mov r2, r10
 *   @0x284260 bl 0x283de8 <spAnimationStateData_getMix+0x140>
 *   @0x284264 cmp r0, #0
 *   @0x284268 bne 0x284240 <spAtlas_create+0xcc>
 *   @0x28426c ldr r0, [sp, #0x8]
 *   @0x284270 add sp, sp, #108
 *   @0x284274 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x284278 cmp r11, #0
 *   @0x28427c beq 0x284654 <spAtlas_create+0x4e0>
 *   @0x284280 bl 0x2840d8 <spAtlasRegion_create>
 *   @0x284284 cmp r8, #0
 *   @0x284288 ldreq r3, [sp, #0x8]
 *   @0x28428c strne r0, [r8, #0x4c]
 *   @0x284290 mov r6, r0
 *   @0x284294 streq r0, [r3, #0x4]
 *   @0x284298 str r11, [r0, #0x48]
 *   @0x28429c mov r0, r10
 *   @0x2842a0 bl 0x283fc8 <spAnimationStateData_getMix+0x320>
 *   @0x2842a4 mov r1, r5
 *   @0x2842a8 mov r2, r10
 *   @0x2842ac str r0, [r6]
 *   @0x2842b0 mov r0, r4
 *   @0x2842b4 bl 0x283e7c <spAnimationStateData_getMix+0x1d4>
 *   @0x2842b8 cmp r0, #0
 *   @0x2842bc beq 0x284830 <spAtlas_create+0x6bc>
 *   @0x2842c0 ldr r1, [sp, #0x40]
 *   @0x2842c4 add r7, sp, #72
 *   @0x2842c8 ldr r2, [sp, #0x44]
 *   @0x2842cc ldr r0, [sp, #0x18]
 *   @0x2842d0 rsb r2, r1, r2
 *   @0x2842d4 bl 0xb65e0 <strncmp@plt>
 *   @0x2842d8 mov r2, r7
 *   @0x2842dc mov r1, r5
 *   @0x2842e0 rsbs r0, r0, #1
 *   @0x2842e4 movlo r0, #0
 *   @0x2842e8 str r0, [r6, #0x38]
 *   @0x2842ec mov r0, r4
 *   @0x2842f0 bl 0x283ed0 <spAnimationStateData_getMix+0x228>
 *   @0x2842f4 cmp r0, #2
 *   @0x2842f8 bne 0x284844 <spAtlas_create+0x6d0>
 *   @0x2842fc add r9, sp, #76
 *   @0x284300 mov r2, #10
 *   @0x284304 ldr r0, [sp, #0x48]
 *   @0x284308 add r8, sp, #84
 *   @0x28430c mov r1, r9
 *   @0x284310 bl 0xb6670 <strtol@plt>
 *   @0x284314 mov r1, r8
 *   @0x284318 mov r2, #10
 *   @0x28431c str r0, [r6, #0x4]
 *   @0x284320 ldr r0, [sp, #0x50]
 *   @0x284324 bl 0xb6670 <strtol@plt>
 *   @0x284328 mov r1, r5
 *   @0x28432c mov r2, r7
 *   @0x284330 str r0, [r6, #0x8]
 *   @0x284334 mov r0, r4
 *   @0x284338 bl 0x283ed0 <spAnimationStateData_getMix+0x228>
 *   @0x28433c cmp r0, #2
 *   @0x284340 bne 0x284844 <spAtlas_create+0x6d0>
 *   @0x284344 mov r1, r9
 *   @0x284348 mov r2, #10
 *   @0x28434c ldr r0, [sp, #0x48]
 *   @0x284350 bl 0xb6670 <strtol@plt>
 *   @0x284354 mov r1, r8
 *   @0x284358 mov r2, #10
 *   @0x28435c str r0, [r6, #0xc]
 *   @0x284360 ldr r0, [sp, #0x50]
 *   @0x284364 bl 0xb6670 <strtol@plt>
 *   @0x284368 ldr r3, [r6, #0x4]
 *   @0x28436c ldr r2, [r6, #0x8]
 *   @0x284370 vldr s15, [r11, #32]
 *   @0x284374 vldr s14, [r11, #36]
 *   @0x284378 vcvt.f32.s32 s15, s15
 *   @0x28437c vmov s11, r3
 *   @0x284380 ldr r1, [r6, #0x38]
 *   @0x284384 cmp r1, #0
 *   @0x284388 ldr r1, [r6, #0xc]
 *   @0x28438c vcvt.f32.s32 s12, s11
 *   @0x284390 vmov s11, r2
 *   @0x284394 vcvt.f32.s32 s14, s14
 *   @0x284398 vcvt.f32.s32 s13, s11
 *   @0x28439c vdiv.f32 s12, s12, s15
 *   @0x2843a0 str r0, [r6, #0x10]
 *   @0x2843a4 vdiv.f32 s13, s13, s14
 *   @0x2843a8 vstr s12, [r6, #20]
 *   @0x2843ac vstr s13, [r6, #24]
 *   @0x2843b0 bne 0x284490 <spAtlas_create+0x31c>
 *   @0x2843b4 add r0, r2, r0
 *   @0x2843b8 add r3, r3, r1
 *   @0x2843bc vmov s13, r0
 *   @0x2843c0 vmov s11, r3
 *   @0x2843c4 vcvt.f32.s32 s12, s13
 *   @0x2843c8 vcvt.f32.s32 s13, s11
 *   @0x2843cc vdiv.f32 s14, s12, s14
 *   @0x2843d0 vdiv.f32 s15, s13, s15
 *   @0x2843d4 vstr s14, [r6, #32]
 *   @0x2843d8 vstr s15, [r6, #28]
 *   @0x2843dc mov r0, r4
 *   @0x2843e0 mov r1, r5
 *   @0x2843e4 mov r2, r7
 *   @0x2843e8 bl 0x283ed0 <spAnimationStateData_getMix+0x228>
 *   @0x2843ec cmp r0, #0
 *   @0x2843f0 beq 0x284638 <spAtlas_create+0x4c4>
 *   @0x2843f4 cmp r0, #4
 *   @0x2843f8 beq 0x2844c8 <spAtlas_create+0x354>
 *   @0x2843fc mov r1, r9
 *   @0x284400 mov r2, #10
 *   @0x284404 ldr r0, [sp, #0x48]
 *   @0x284408 bl 0xb6670 <strtol@plt>
 *   @0x28440c mov r1, r8
 *   @0x284410 mov r2, #10
 *   @0x284414 str r0, [r6, #0x2c]
 *   @0x284418 ldr r0, [sp, #0x50]
 *   @0x28441c bl 0xb6670 <strtol@plt>
 *   @0x284420 mov r2, r7
 *   @0x284424 mov r1, r5
 *   @0x284428 str r0, [r6, #0x30]
 *   @0x28442c mov r0, r4
 *   @0x284430 bl 0x283ed0 <spAnimationStateData_getMix+0x228>
 *   @0x284434 mov r1, r9
 *   @0x284438 mov r2, #10
 *   @0x28443c ldr r0, [sp, #0x48]
 *   @0x284440 bl 0xb6670 <strtol@plt>
 *   @0x284444 mov r1, r8
 *   @0x284448 mov r2, #10
 *   @0x28444c str r0, [r6, #0x24]
 *   @0x284450 ldr r0, [sp, #0x50]
 *   @0x284454 bl 0xb6670 <strtol@plt>
 *   @0x284458 mov r1, r5
 *   @0x28445c mov r2, r10
 *   @0x284460 str r0, [r6, #0x28]
 *   @0x284464 mov r0, r4
 *   @0x284468 bl 0x283e7c <spAnimationStateData_getMix+0x1d4>
 *   @0x28446c cmp r0, #0
 *   @0x284470 beq 0x284830 <spAtlas_create+0x6bc>
 *   @0x284474 ldr r0, [sp, #0x40]
 *   @0x284478 add r1, sp, #68
 *   @0x28447c mov r2, #10
 *   @0x284480 mov r8, r6
 *   @0x284484 bl 0xb6670 <strtol@plt>
 *   @0x284488 str r0, [r6, #0x34]
 *   @0x28448c b 0x284254 <spAtlas_create+0xe0>
 *   @0x284490 add r0, r3, r0
 *   @0x284494 add r2, r2, r1
 *   @0x284498 vmov s13, r0
 *   @0x28449c vmov s11, r2
 *   @0x2844a0 vcvt.f32.s32 s12, s13
 *   @0x2844a4 vcvt.f32.s32 s13, s11
 *   @0x2844a8 vdiv.f32 s15, s12, s15
 *   @0x2844ac vdiv.f32 s14, s13, s14
 *   @0x2844b0 vstr s15, [r6, #28]
 *   @0x2844b4 vstr s14, [r6, #32]
 *   @0x2844b8 b 0x2843dc <spAtlas_create+0x268>
 *   @0x2844bc mov r12, #0
 *   @0x2844c0 str r12, [sp, #0x20]
 *   @0x2844c4 b 0x2841c0 <spAtlas_create+0x4c>
 *   @0x2844c8 ldr r1, [sp, #0x24]
 *   @0x2844cc movw r2, #0x10d
 *   @0x2844d0 mov r0, #16
 *   @0x2844d4 add r3, sp, #92
 *   @0x2844d8 str r3, [sp, #0x34]
 *   @0x2844dc bl 0x285c10 <_malloc>
 *   @0x2844e0 mov r1, r9
 *   @0x2844e4 mov r2, #10
 *   @0x2844e8 mov r3, r0
 *   @0x2844ec str r0, [r6, #0x40]
 *   @0x2844f0 ldr r0, [sp, #0x48]
 *   @0x2844f4 str r3, [sp, #0x4]
 *   @0x2844f8 bl 0xb6670 <strtol@plt>
 *   @0x2844fc ldr r3, [sp, #0x4]
 *   @0x284500 mov r1, r8
 *   @0x284504 ldr r12, [r6, #0x40]
 *   @0x284508 mov r2, #10
 *   @0x28450c add lr, sp, #100
 *   @0x284510 str lr, [sp, #0x38]
 *   @0x284514 str r0, [r3]
 *   @0x284518 ldr r0, [sp, #0x50]
 *   @0x28451c str r12, [sp, #0x4]
 *   @0x284520 bl 0xb6670 <strtol@plt>
 *   @0x284524 ldr r12, [sp, #0x4]
 *   @0x284528 add r1, sp, #92
 *   @0x28452c ldr r3, [r6, #0x40]
 *   @0x284530 mov r2, #10
 *   @0x284534 str r0, [r12, #0x4]
 *   @0x284538 ldr r0, [sp, #0x58]
 *   @0x28453c str r3, [sp, #0x4]
 *   @0x284540 bl 0xb6670 <strtol@plt>
 *   @0x284544 ldr r3, [sp, #0x4]
 *   @0x284548 add r1, sp, #100
 *   @0x28454c ldr r12, [r6, #0x40]
 *   @0x284550 mov r2, #10
 *   @0x284554 str r0, [r3, #0x8]
 *   @0x284558 ldr r0, [sp, #0x60]
 *   @0x28455c str r12, [sp, #0x4]
 *   @0x284560 bl 0xb6670 <strtol@plt>
 *   @0x284564 ldr r12, [sp, #0x4]
 *   @0x284568 mov r1, r5
 *   @0x28456c mov r2, r7
 *   @0x284570 str r0, [r12, #0xc]
 *   @0x284574 mov r0, r4
 *   @0x284578 bl 0x283ed0 <spAnimationStateData_getMix+0x228>
 *   @0x28457c cmp r0, #0
 *   @0x284580 beq 0x284638 <spAtlas_create+0x4c4>
 *   @0x284584 cmp r0, #4
 *   @0x284588 bne 0x2843fc <spAtlas_create+0x288>
 *   @0x28458c ldr r1, [sp, #0x24]
 *   @0x284590 movw r2, #0x115
 *   @0x284594 mov r0, #16
 *   @0x284598 bl 0x285c10 <_malloc>
 *   @0x28459c mov r1, r9
 *   @0x2845a0 mov r2, #10
 *   @0x2845a4 mov r3, r0
 *   @0x2845a8 str r0, [r6, #0x44]
 *   @0x2845ac ldr r0, [sp, #0x48]
 *   @0x2845b0 str r3, [sp, #0x4]
 *   @0x2845b4 bl 0xb6670 <strtol@plt>
 *   @0x2845b8 ldr r3, [sp, #0x4]
 *   @0x2845bc mov r1, r8
 *   @0x2845c0 ldr r12, [r6, #0x44]
 *   @0x2845c4 mov r2, #10
 *   @0x2845c8 str r0, [r3]
 *   @0x2845cc ldr r0, [sp, #0x50]
 *   @0x2845d0 str r12, [sp, #0x4]
 *   @0x2845d4 bl 0xb6670 <strtol@plt>
 *   @0x2845d8 ldr r12, [sp, #0x4]
 *   @0x2845dc add r1, sp, #92
 *   @0x2845e0 ldr r3, [r6, #0x44]
 *   @0x2845e4 mov r2, #10
 *   @0x2845e8 str r0, [r12, #0x4]
 *   @0x2845ec ldr r0, [sp, #0x58]
 *   @0x2845f0 str r3, [sp, #0x4]
 *   @0x2845f4 bl 0xb6670 <strtol@plt>
 *   @0x2845f8 ldr r3, [sp, #0x4]
 *   @0x2845fc add r1, sp, #100
 *   @0x284600 ldr r12, [r6, #0x44]
 *   @0x284604 mov r2, #10
 *   @0x284608 str r0, [r3, #0x8]
 *   @0x28460c ldr r0, [sp, #0x60]
 *   @0x284610 str r12, [sp, #0x4]
 *   @0x284614 bl 0xb6670 <strtol@plt>
 *   @0x284618 ldr r12, [sp, #0x4]
 *   @0x28461c mov r1, r5
 *   @0x284620 mov r2, r7
 *   @0x284624 str r0, [r12, #0xc]
 *   @0x284628 mov r0, r4
 *   @0x28462c bl 0x283ed0 <spAnimationStateData_getMix+0x228>
 *   @0x284630 cmp r0, #0
 *   @0x284634 bne 0x2843fc <spAtlas_create+0x288>
 *   @0x284638 mov r3, r0
 *   @0x28463c ldr r0, [sp, #0x8]
 *   @0x284640 str r3, [sp, #0x4]
 *   @0x284644 bl 0x284120 <spAtlas_dispose>
 *   @0x284648 ldr r3, [sp, #0x4]
 *   @0x28464c mov r0, r3
 *   @0x284650 b 0x284270 <spAtlas_create+0xfc>
 *   @0x284654 ldr lr, [sp, #0x14]
 *   @0x284658 mov r0, r10
 *   @0x28465c ldr r12, [sp, #0x20]
 *   @0x284660 add r7, r12, lr
 *   @0x284664 bl 0x283fc8 <spAnimationStateData_getMix+0x320>
 *   @0x284668 mov r6, r0
 *   @0x28466c bl 0xb6538 <strlen@plt>
 *   @0x284670 add r3, r7, #1
 *   @0x284674 ldr r1, [sp, #0x2c]
 *   @0x284678 mov r2, #190
 *   @0x28467c add r0, r3, r0
 *   @0x284680 bl 0x285c10 <_malloc>
 *   @0x284684 ldr r2, [sp, #0x14]
 *   @0x284688 ldr r1, [sp, #0xc]
 *   @0x28468c mov r9, r0
 *   @0x284690 bl 0xb65bc <memcpy@plt>
 *   @0x284694 ldr r12, [sp, #0x20]
 *   @0x284698 add r0, r9, r7
 *   @0x28469c mov r1, r6
 *   @0x2846a0 add r7, sp, #72
 *   @0x2846a4 cmp r12, #0
 *   @0x2846a8 ldrne r12, [sp, #0x14]
 *   @0x2846ac movne r3, #47
 *   @0x2846b0 strbne r3, [r9, r12]
 *   @0x2846b4 bl 0xb65a4 <strcpy@plt>
 *   @0x2846b8 mov r1, r6
 *   @0x2846bc ldr r0, [sp, #0x8]
 *   @0x2846c0 bl 0x284058 <spAtlasPage_create>
 *   @0x2846c4 mov r11, r0
 *   @0x2846c8 mov r0, r6
 *   @0x2846cc bl 0x285c80 <_free>
 *   @0x2846d0 ldr r3, [sp, #0x1c]
 *   @0x2846d4 mov r0, r4
 *   @0x2846d8 mov r1, r5
 *   @0x2846dc cmp r3, #0
 *   @0x2846e0 mov r2, r7
 *   @0x2846e4 strne r11, [r3, #0x28]
 *   @0x2846e8 ldreq r12, [sp, #0x8]
 *   @0x2846ec streq r11, [r12]
 *   @0x2846f0 bl 0x283ed0 <spAnimationStateData_getMix+0x228>
 *   @0x2846f4 cmp r0, #0
 *   @0x2846f8 beq 0x28481c <spAtlas_create+0x6a8>
 *   @0x2846fc cmp r0, #2
 *   @0x284700 beq 0x2847dc <spAtlas_create+0x668>
 *   @0x284704 ldr r0, [sp, #0x10]
 *   @0x284708 mov r1, r7
 *   @0x28470c bl 0x284010 <spAnimationStateData_getMix+0x368>
 *   @0x284710 mov r1, r5
 *   @0x284714 mov r2, r7
 *   @0x284718 str r0, [r11, #0x8]
 *   @0x28471c mov r0, r4
 *   @0x284720 bl 0x283ed0 <spAnimationStateData_getMix+0x228>
 *   @0x284724 cmp r0, #0
 *   @0x284728 beq 0x28481c <spAtlas_create+0x6a8>
 *   @0x28472c mov r1, r7
 *   @0x284730 ldr r0, [sp, #0x28]
 *   @0x284734 bl 0x284010 <spAnimationStateData_getMix+0x368>
 *   @0x284738 add r1, sp, #80
 *   @0x28473c str r0, [r11, #0xc]
 *   @0x284740 ldr r0, [sp, #0x28]
 *   @0x284744 bl 0x284010 <spAnimationStateData_getMix+0x368>
 *   @0x284748 mov r1, r5
 *   @0x28474c mov r2, r10
 *   @0x284750 str r0, [r11, #0x10]
 *   @0x284754 mov r0, r4
 *   @0x284758 bl 0x283e7c <spAnimationStateData_getMix+0x1d4>
 *   @0x28475c cmp r0, #0
 *   @0x284760 beq 0x284830 <spAtlas_create+0x6bc>
 *   @0x284764 ldr r6, [sp, #0x40]
 *   @0x284768 mov r3, #1
 *   @0x28476c ldr r7, [sp, #0x44]
 *   @0x284770 ldr r0, [sp, #0x30]
 *   @0x284774 rsb r7, r6, r7
 *   @0x284778 str r3, [r11, #0x14]
 *   @0x28477c mov r1, r6
 *   @0x284780 str r3, [r11, #0x18]
 *   @0x284784 mov r2, r7
 *   @0x284788 bl 0xb65e0 <strncmp@plt>
 *   @0x28478c cmp r0, #0
 *   @0x284790 beq 0x2847c0 <spAtlas_create+0x64c>
 *   @0x284794 cmp r7, #1
 *   @0x284798 beq 0x284854 <spAtlas_create+0x6e0>
 *   @0x28479c ldr r0, [pc, #0xec]
 *   @0x2847a0 mov r1, r6
 *   @0x2847a4 mov r2, r7
 *   @0x2847a8 add r0, pc, r0
 *   @0x2847ac bl 0xb65e0 <strncmp@plt>
 *   @0x2847b0 cmp r0, #0
 *   @0x2847b4 moveq r3, #2
 *   @0x2847b8 streq r3, [r11, #0x14]
 *   @0x2847bc streq r3, [r11, #0x18]
 *   @0x2847c0 mov r0, r11
 *   @0x2847c4 mov r1, r9
 *   @0x2847c8 bl 0xbd6e4 <_spAtlasPage_createTexture>
 *   @0x2847cc mov r0, r9
 *   @0x2847d0 bl 0x285c80 <_free>
 *   @0x2847d4 str r11, [sp, #0x1c]
 *   @0x2847d8 b 0x284254 <spAtlas_create+0xe0>
 *   @0x2847dc add r1, sp, #76
 *   @0x2847e0 mov r2, #10
 *   @0x2847e4 ldr r0, [sp, #0x48]
 *   @0x2847e8 bl 0xb6670 <strtol@plt>
 *   @0x2847ec add r1, sp, #84
 *   @0x2847f0 mov r2, #10
 *   @0x2847f4 str r0, [r11, #0x20]
 *   @0x2847f8 ldr r0, [sp, #0x50]
 *   @0x2847fc bl 0xb6670 <strtol@plt>
 *   @0x284800 mov r1, r5
 *   @0x284804 mov r2, r7
 *   @0x284808 str r0, [r11, #0x24]
 *   @0x28480c mov r0, r4
 *   @0x284810 bl 0x283ed0 <spAnimationStateData_getMix+0x228>
 *   @0x284814 cmp r0, #0
 *   @0x284818 bne 0x284704 <spAtlas_create+0x590>
 *   @0x28481c mov r9, r0
 *   @0x284820 ldr r0, [sp, #0x8]
 *   @0x284824 bl 0x284120 <spAtlas_dispose>
 *   @0x284828 mov r0, r9
 *   @0x28482c b 0x284270 <spAtlas_create+0xfc>
 *   @0x284830 mov r7, r0
 *   @0x284834 ldr r0, [sp, #0x8]
 *   @0x284838 bl 0x284120 <spAtlas_dispose>
 *   @0x28483c mov r0, r7
 *   @0x284840 b 0x284270 <spAtlas_create+0xfc>
 *   @0x284844 ldr r0, [sp, #0x8]
 *   @0x284848 bl 0x284120 <spAtlas_dispose>
 *   @0x28484c mov r0, #0
 *   @0x284850 b 0x284270 <spAtlas_create+0xfc>
 *   @0x284854 ldrb r3, [r6]
 *   @0x284858 cmp r3, #120
 *   @0x28485c moveq r3, #2
 *   @0x284860 streq r3, [r11, #0x14]
 *   @0x284864 beq 0x2847c0 <spAtlas_create+0x64c>
 *   @0x284868 cmp r3, #121
 *   @0x28486c moveq r3, #2
 *   @0x284870 streq r3, [r11, #0x18]
 *   @0x284874 b 0x2847c0 <spAtlas_create+0x64c>
 *   @0x284878 andeq r3, sp, r0, lsr r3
 *   @0x28487c andseq r3, r7, r0, ror r5
 *   @0x284880 andeq r0, r11, r4, lsr #16
 *   @0x284884 strdeq r3, r4, [sp], -r12
 *   @0x284888 andeq r3, sp, r8, ror #5
 *   @0x28488c andeq r3, sp, r4, lsl r3
 *   @0x284890 muleq sp, r8, sp
 *
 * ══ §14/16 CBitmap32::CBitmap32(int, int, unsigned int, unsigned int, int)  0x166768  size 1796  447 条（0x166768..0x166e6c）
 * @func 0x166768 0x166e6c  size 1796  447 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::CBitmap32(int, int, unsigned int, unsigned int, int)+0x2e0×6 / Graphics_Bitmap32::Color_Merge(unsigned int, unsigned int, double)×6 / IBitmap::Create() / CBitmap32::CBitmap32(int, int, unsigned int, unsigned int, int)+0x160 / CBitmap32::CBitmap32(int, int, unsigned int, unsigned int, int)+0x144 / CBitmap32::CBitmap32(int, int, unsigned int, unsigned int, int)+0x2c4 / CBitmap32::CBitmap32(int, int, unsigned int, unsigned int, int)+0x2a4 / operator new(unsigned int)
 * 字段偏移 top8: 0x34×17 / 0x18×8 / 0x30×8 / 0xc×7 / 0x14×7 / 0x10×6 / 0x78×6 / 0x28×5
 * VFP 指令 88 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x166768 ldr r12, [pc, #0x540]
 *   @0x16676c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x166770 vpush {d8, d9, d10}
 *   @0x166774 ldr r12, [pc, r12]
 *   @0x166778 sub sp, sp, #60
 *   @0x16677c mov r6, #0
 *   @0x166780 add r12, r12, #8
 *   @0x166784 strb r6, [r0, #0x4]
 *   @0x166788 str r12, [r0]
 *   @0x16678c mov r11, r2
 *   @0x166790 str r6, [r0, #0x8]
 *   @0x166794 mov r4, r1
 *   @0x166798 str r6, [r0, #0xc]
 *   @0x16679c mov r10, r3
 *   @0x1667a0 str r6, [r0, #0x10]
 *   @0x1667a4 str r6, [r0, #0x14]
 *   @0x1667a8 str r0, [sp, #0x1c]
 *   @0x1667ac ldr r5, [sp, #0x7c]
 *   @0x1667b0 bl 0x1a912c <_ZN7IBitmap6CreateEv>
 *   @0x1667b4 mov r1, #6
 *   @0x1667b8 ldr r3, [r0]
 *   @0x1667bc str r0, [sp, #0x18]
 *   @0x1667c0 ldr r3, [r3, #0x1c]
 *   @0x1667c4 blx r3
 *   @0x1667c8 ldr r0, [sp, #0x18]
 *   @0x1667cc cmp r4, #1
 *   @0x1667d0 movge r1, r4
 *   @0x1667d4 movlt r1, #1
 *   @0x1667d8 ldr r3, [r0]
 *   @0x1667dc ldr r3, [r3, #0xc]
 *   @0x1667e0 blx r3
 *   @0x1667e4 ldr r1, [sp, #0x18]
 *   @0x1667e8 ldr r3, [r1]
 *   @0x1667ec mov r0, r1
 *   @0x1667f0 cmp r11, #1
 *   @0x1667f4 movge r1, r11
 *   @0x1667f8 movlt r1, #1
 *   @0x1667fc ldr r3, [r3, #0x14]
 *   @0x166800 blx r3
 *   @0x166804 ldr r3, [sp, #0x18]
 *   @0x166808 add r2, sp, #56
 *   @0x16680c mov r1, r6
 *   @0x166810 str r6, [r2, #-0x4]!
 *   @0x166814 mov r0, r3
 *   @0x166818 ldr r12, [r3]
 *   @0x16681c add r3, sp, #48
 *   @0x166820 str r6, [sp, #0x30]
 *   @0x166824 ldr r12, [r12, #0x24]
 *   @0x166828 blx r12
 *   @0x16682c str r0, [sp, #0x24]
 *   @0x166830 cmp r5, #5
 *   @0x166834 addls pc, pc, r5, lsl #2
 *   @0x166838 b 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0>
 *   @0x16683c b 0x166b88 <_ZN9CBitmap32C2Eiijji+0x420>
 *   @0x166840 b 0x166c1c <_ZN9CBitmap32C2Eiijji+0x4b4>
 *   @0x166844 b 0x166cb4 <_ZN9CBitmap32C2Eiijji+0x54c>
 *   @0x166848 b 0x166854 <_ZN9CBitmap32C2Eiijji+0xec>
 *   @0x16684c b 0x166dbc <_ZN9CBitmap32C2Eiijji+0x654>
 *   @0x166850 b 0x166ac8 <_ZN9CBitmap32C2Eiijji+0x360>
 *   @0x166854 ldr r0, [sp, #0x34]
 *   @0x166858 cmp r11, #0
 *   @0x16685c str r0, [sp, #0x28]
 *   @0x166860 ble 0x1668c8 <_ZN9CBitmap32C2Eiijji+0x160>
 *   @0x166864 ldr r1, [sp, #0x28]
 *   @0x166868 ubfx r12, r10, #0x10, #0x8
 *   @0x16686c ldr r6, [sp, #0x30]
 *   @0x166870 ubfx r0, r10, #0x8, #0x8
 *   @0x166874 add lr, r1, #3
 *   @0x166878 add r7, r4, r4, lsl #1
 *   @0x16687c uxtb r1, r10
 *   @0x166880 mov r5, #0
 *   @0x166884 cmp r4, #0
 *   @0x166888 addgt r2, r7, lr
 *   @0x16688c movgt r3, lr
 *   @0x166890 ble 0x1668ac <_ZN9CBitmap32C2Eiijji+0x144>
 *   @0x166894 strb r12, [r3, #-0x1]
 *   @0x166898 add r3, r3, #3
 *   @0x16689c strb r1, [r3, #-0x6]
 *   @0x1668a0 strb r0, [r3, #-0x5]
 *   @0x1668a4 cmp r3, r2
 *   @0x1668a8 bne 0x166894 <_ZN9CBitmap32C2Eiijji+0x12c>
 *   @0x1668ac add r5, r5, #1
 *   @0x1668b0 add lr, lr, r6
 *   @0x1668b4 cmp r5, r11
 *   @0x1668b8 bne 0x166884 <_ZN9CBitmap32C2Eiijji+0x11c>
 *   @0x1668bc ldr r2, [sp, #0x28]
 *   @0x1668c0 mla r6, r6, r11, r2
 *   @0x1668c4 str r6, [sp, #0x34]
 *   @0x1668c8 cmp r4, r11
 *   @0x1668cc bge 0x166e60 <_ZN9CBitmap32C2Eiijji+0x6f8>
 *   @0x1668d0 vmov d10, r4, r4
 *   @0x1668d4 vcvt.f64.s32 d10, d10, #1
 *   @0x1668d8 vcmpe.f64 d10, #0
 *   @0x1668dc vmrs APSR_nzcv, fpscr
 *   @0x1668e0 ble 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0>
 *   @0x1668e4 vmov.f64 d9, #5.000000e-01
 *   @0x1668e8 add r5, r4, r4, lsl #1
 *   @0x1668ec mov r9, #0
 *   @0x1668f0 vldr d7, [pc, #944]
 *   @0x1668f4 str r4, [sp, #0x10]
 *   @0x1668f8 str r11, [sp, #0x14]
 *   @0x1668fc str r10, [sp, #0x2c]
 *   @0x166900 vmov.f64 d8, #1.000000e+00
 *   @0x166904 ldr r1, [sp, #0x78]
 *   @0x166908 add r11, r9, #1
 *   @0x16690c ldr r0, [sp, #0x2c]
 *   @0x166910 vdiv.f64 d6, d7, d10
 *   @0x166914 vmov r2, r3, d6
 *   @0x166918 bl 0x165ce8 <_ZN17Graphics_Bitmap3211Color_MergeEjjd>
 *   @0x16691c ldr r7, [sp, #0x30]
 *   @0x166920 ldr r2, [sp, #0x28]
 *   @0x166924 ldr r1, [sp, #0x14]
 *   @0x166928 mla r2, r9, r7, r2
 *   @0x16692c rsb r8, r9, r1
 *   @0x166930 cmp r8, r9
 *   @0x166934 str r2, [sp, #0x20]
 *   @0x166938 str r2, [sp, #0x34]
 *   @0x16693c ble 0x166a2c <_ZN9CBitmap32C2Eiijji+0x2c4>
 *   @0x166940 ldr r1, [sp, #0x14]
 *   @0x166944 lsl r3, r9, #1
 *   @0x166948 ldr r2, [sp, #0x10]
 *   @0x16694c add lr, r11, r11, lsl #1
 *   @0x166950 rsb r1, r3, r1
 *   @0x166954 ubfx r6, r0, #0x10, #0x8
 *   @0x166958 rsb r2, r3, r2
 *   @0x16695c ldr r3, [sp, #0x10]
 *   @0x166960 vmov s7, r1
 *   @0x166964 ldr r1, [sp, #0x20]
 *   @0x166968 vmov s6, r2
 *   @0x16696c rsb r10, r9, r3
 *   @0x166970 add lr, r1, lr
 *   @0x166974 ubfx r4, r0, #0x8, #0x8
 *   @0x166978 mov r12, r9
 *   @0x16697c cmp r10, r9
 *   @0x166980 ble 0x166a0c <_ZN9CBitmap32C2Eiijji+0x2a4>
 *   @0x166984 vmov s5, r12
 *   @0x166988 vldr s11, [sp, #20]
 *   @0x16698c vcvt.f64.s32 d6, s11
 *   @0x166990 add r1, r5, lr
 *   @0x166994 mov r3, lr
 *   @0x166998 mov r2, r9
 *   @0x16699c vcvt.f64.s32 d7, s5
 *   @0x1669a0 vmls.f64 d7, d6, d9
 *   @0x1669a4 vcvt.f64.s32 d6, s7
 *   @0x1669a8 vmul.f64 d6, d6, d9
 *   @0x1669ac vmul.f64 d7, d7, d7
 *   @0x1669b0 vmul.f64 d6, d6, d6
 *   @0x1669b4 vcvt.f64.s32 d5, s6
 *   @0x1669b8 vmul.f64 d5, d5, d9
 *   @0x1669bc vdiv.f64 d4, d7, d6
 *   @0x1669c0 vldr s15, [sp, #16]
 *   @0x1669c4 vcvt.f64.s32 d6, s15
 *   @0x1669c8 vmul.f64 d5, d5, d5
 *   @0x1669cc vmul.f64 d6, d6, d9
 *   @0x1669d0 vmov s5, r2
 *   @0x1669d4 add r3, r3, #3
 *   @0x1669d8 add r2, r2, #1
 *   @0x1669dc vcvt.f64.s32 d7, s5
 *   @0x1669e0 vsub.f64 d7, d7, d6
 *   @0x1669e4 vmul.f64 d7, d7, d7
 *   @0x1669e8 vdiv.f64 d7, d7, d5
 *   @0x1669ec vadd.f64 d7, d7, d4
 *   @0x1669f0 vcmpe.f64 d7, d8
 *   @0x1669f4 vmrs APSR_nzcv, fpscr
 *   @0x1669f8 strbls r6, [r3, #-0x4]
 *   @0x1669fc strbls r0, [r3, #-0x6]
 *   @0x166a00 strbls r4, [r3, #-0x5]
 *   @0x166a04 cmp r3, r1
 *   @0x166a08 bne 0x1669d0 <_ZN9CBitmap32C2Eiijji+0x268>
 *   @0x166a0c add r12, r12, #1
 *   @0x166a10 add lr, lr, r7
 *   @0x166a14 cmp r8, r12
 *   @0x166a18 bne 0x16697c <_ZN9CBitmap32C2Eiijji+0x214>
 *   @0x166a1c vmov r0, s7
 *   @0x166a20 ldr r1, [sp, #0x20]
 *   @0x166a24 mla r7, r7, r0, r1
 *   @0x166a28 str r7, [sp, #0x34]
 *   @0x166a2c vmov s5, r11
 *   @0x166a30 mov r9, r11
 *   @0x166a34 sub r5, r5, #6
 *   @0x166a38 vcvt.f64.s32 d7, s5
 *   @0x166a3c vcmpe.f64 d10, d7
 *   @0x166a40 vmrs APSR_nzcv, fpscr
 *   @0x166a44 bgt 0x166904 <_ZN9CBitmap32C2Eiijji+0x19c>
 *   @0x166a48 ldr r1, [sp, #0x18]
 *   @0x166a4c ldr r0, [sp, #0x18]
 *   @0x166a50 ldr r3, [r1]
 *   @0x166a54 ldr r1, [sp, #0x24]
 *   @0x166a58 ldr r3, [r3, #0x28]
 *   @0x166a5c blx r3
 *   @0x166a60 mov r0, #24
 *   @0x166a64 bl 0x27c524 <_Znwj>
 *   @0x166a68 mov r3, #0
 *   @0x166a6c mov r1, r3
 *   @0x166a70 ldr r2, [sp, #0x18]
 *   @0x166a74 str r3, [sp]
 *   @0x166a78 mov r4, r0
 *   @0x166a7c bl 0x166488 <_ZN9CBitmap32C2EiP7IBitmapbb>
 *   @0x166a80 ldr r0, [sp, #0x1c]
 *   @0x166a84 mov r1, r4
 *   @0x166a88 bl 0x165dac <_ZN9CBitmap326AssignEPS_>
 *   @0x166a8c cmp r4, #0
 *   @0x166a90 beq 0x166aa4 <_ZN9CBitmap32C2Eiijji+0x33c>
 *   @0x166a94 ldr r3, [r4]
 *   @0x166a98 mov r0, r4
 *   @0x166a9c ldr r3, [r3, #0x4]
 *   @0x166aa0 blx r3
 *   @0x166aa4 ldr r2, [sp, #0x18]
 *   @0x166aa8 ldr r3, [r2]
 *   @0x166aac mov r0, r2
 *   @0x166ab0 ldr r3, [r3, #0x4]
 *   @0x166ab4 blx r3
 *   @0x166ab8 ldr r0, [sp, #0x1c]
 *   @0x166abc add sp, sp, #60
 *   @0x166ac0 vpop {d8, d9, d10}
 *   @0x166ac4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x166ac8 cmp r11, #0
 *   @0x166acc ble 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0>
 *   @0x166ad0 vmov d8, r11, r11
 *   @0x166ad4 vcvt.f64.s32 d8, d8, #1
 *   @0x166ad8 ldr r5, [sp, #0x34]
 *   @0x166adc ldr r9, [sp, #0x78]
 *   @0x166ae0 add r3, r4, r4, lsl #1
 *   @0x166ae4 mov r8, #0
 *   @0x166ae8 add r3, r3, #3
 *   @0x166aec sub r0, r11, #1
 *   @0x166af0 str r3, [sp, #0x10]
 *   @0x166af4 str r0, [sp, #0xc]
 *   @0x166af8 str r4, [sp, #0x14]
 *   @0x166afc ldr r1, [sp, #0xc]
 *   @0x166b00 ldr r2, [sp, #0x14]
 *   @0x166b04 rsb r3, r8, r1
 *   @0x166b08 cmp r3, r8
 *   @0x166b0c movge r3, r8
 *   @0x166b10 cmp r2, #0
 *   @0x166b14 vmov s5, r3
 *   @0x166b18 vcvt.f64.s32 d7, s5
 *   @0x166b1c vdiv.f64 d6, d7, d8
 *   @0x166b20 vmov r6, r7, d6
 *   @0x166b24 ble 0x166b6c <_ZN9CBitmap32C2Eiijji+0x404>
 *   @0x166b28 ldr r0, [sp, #0x10]
 *   @0x166b2c add r4, r5, #3
 *   @0x166b30 add r5, r5, r0
 *   @0x166b34 mov r3, r7
 *   @0x166b38 mov r0, r10
 *   @0x166b3c mov r1, r9
 *   @0x166b40 mov r2, r6
 *   @0x166b44 bl 0x165ce8 <_ZN17Graphics_Bitmap3211Color_MergeEjjd>
 *   @0x166b48 add r4, r4, #3
 *   @0x166b4c strb r0, [r4, #-0x6]
 *   @0x166b50 lsr r3, r0, #16
 *   @0x166b54 lsr r0, r0, #8
 *   @0x166b58 strb r3, [r4, #-0x4]
 *   @0x166b5c strb r0, [r4, #-0x5]
 *   @0x166b60 cmp r4, r5
 *   @0x166b64 bne 0x166b34 <_ZN9CBitmap32C2Eiijji+0x3cc>
 *   @0x166b68 ldr r5, [sp, #0x34]
 *   @0x166b6c add r8, r8, #1
 *   @0x166b70 ldr r3, [sp, #0x30]
 *   @0x166b74 cmp r8, r11
 *   @0x166b78 add r5, r5, r3
 *   @0x166b7c str r5, [sp, #0x34]
 *   @0x166b80 bne 0x166afc <_ZN9CBitmap32C2Eiijji+0x394>
 *   @0x166b84 b 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0>
 *   @0x166b88 cmp r4, #0
 *   @0x166b8c ble 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0>
 *   @0x166b90 vmov s5, r4
 *   @0x166b94 ldr r6, [sp, #0x78]
 *   @0x166b98 mov r5, #0
 *   @0x166b9c vcvt.f64.s32 d8, s5
 *   @0x166ba0 vmov s11, r5
 *   @0x166ba4 mov r0, r10
 *   @0x166ba8 mov r1, r6
 *   @0x166bac vcvt.f64.s32 d7, s11
 *   @0x166bb0 vdiv.f64 d6, d7, d8
 *   @0x166bb4 vmov r2, r3, d6
 *   @0x166bb8 bl 0x165ce8 <_ZN17Graphics_Bitmap3211Color_MergeEjjd>
 *   @0x166bbc cmp r11, #0
 *   @0x166bc0 ldr r9, [sp, #0x34]
 *   @0x166bc4 ble 0x166c04 <_ZN9CBitmap32C2Eiijji+0x49c>
 *   @0x166bc8 ldr r1, [sp, #0x30]
 *   @0x166bcc ubfx r8, r0, #0x10, #0x8
 *   @0x166bd0 uxtb r7, r0
 *   @0x166bd4 ubfx r0, r0, #0x8, #0x8
 *   @0x166bd8 add r3, r9, r1
 *   @0x166bdc rsb lr, r1, #0
 *   @0x166be0 mov r2, #0
 *   @0x166be4 add r2, r2, #1
 *   @0x166be8 add r12, r3, lr
 *   @0x166bec cmp r2, r11
 *   @0x166bf0 strb r8, [r12, #0x2]
 *   @0x166bf4 strb r7, [r3, lr]
 *   @0x166bf8 add r3, r3, r1
 *   @0x166bfc strb r0, [r12, #0x1]
 *   @0x166c00 bne 0x166be4 <_ZN9CBitmap32C2Eiijji+0x47c>
 *   @0x166c04 add r5, r5, #1
 *   @0x166c08 add r9, r9, #3
 *   @0x166c0c cmp r5, r4
 *   @0x166c10 str r9, [sp, #0x34]
 *   @0x166c14 bne 0x166ba0 <_ZN9CBitmap32C2Eiijji+0x438>
 *   @0x166c18 b 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0>
 *   @0x166c1c cmp r11, #0
 *   @0x166c20 ble 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0>
 *   @0x166c24 vmov s13, r11
 *   @0x166c28 ldr r7, [sp, #0x78]
 *   @0x166c2c add r5, r4, r4, lsl #1
 *   @0x166c30 mov r6, #0
 *   @0x166c34 vcvt.f64.s32 d8, s13
 *   @0x166c38 vmov s5, r6
 *   @0x166c3c mov r0, r10
 *   @0x166c40 mov r1, r7
 *   @0x166c44 vcvt.f64.s32 d7, s5
 *   @0x166c48 vdiv.f64 d6, d7, d8
 *   @0x166c4c vmov r2, r3, d6
 *   @0x166c50 bl 0x165ce8 <_ZN17Graphics_Bitmap3211Color_MergeEjjd>
 *   @0x166c54 cmp r4, #0
 *   @0x166c58 ldr r8, [sp, #0x34]
 *   @0x166c5c ble 0x166c8c <_ZN9CBitmap32C2Eiijji+0x524>
 *   @0x166c60 add r3, r8, #3
 *   @0x166c64 ubfx lr, r0, #0x10, #0x8
 *   @0x166c68 add r1, r3, r5
 *   @0x166c6c uxtb r12, r0
 *   @0x166c70 ubfx r2, r0, #0x8, #0x8
 *   @0x166c74 strb lr, [r3, #-0x1]
 *   @0x166c78 add r3, r3, #3
 *   @0x166c7c strb r12, [r3, #-0x6]
 *   @0x166c80 strb r2, [r3, #-0x5]
 *   @0x166c84 cmp r3, r1
 *   @0x166c88 bne 0x166c74 <_ZN9CBitmap32C2Eiijji+0x50c>
 *   @0x166c8c add r6, r6, #1
 *   @0x166c90 ldr r3, [sp, #0x30]
 *   @0x166c94 cmp r6, r11
 *   @0x166c98 add r8, r8, r3
 *   @0x166c9c str r8, [sp, #0x34]
 *   @0x166ca0 bne 0x166c38 <_ZN9CBitmap32C2Eiijji+0x4d0>
 *   @0x166ca4 b 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0>
 *   @0x166cb0 eoreq r9, r8, r4, lsl #19
 *   @0x166cb4 cmp r11, #0
 *   @0x166cb8 ble 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0>
 *   @0x166cbc ldr r8, [sp, #0x34]
 *   @0x166cc0 cmp r4, r11
 *   @0x166cc4 sub r0, r11, #1
 *   @0x166cc8 vmov.f64 d10, #5.000000e-01
 *   @0x166ccc str r0, [sp, #0xc]
 *   @0x166cd0 sub r6, r4, #1
 *   @0x166cd4 mov r7, #0
 *   @0x166cd8 mov r12, r8
 *   @0x166cdc ldr r9, [sp, #0x78]
 *   @0x166ce0 bge 0x166d94 <_ZN9CBitmap32C2Eiijji+0x62c>
 *   @0x166ce4 vmov s5, r4
 *   @0x166ce8 ldr r1, [sp, #0xc]
 *   @0x166cec rsb r3, r7, r1
 *   @0x166cf0 cmp r3, r7
 *   @0x166cf4 movge r3, r7
 *   @0x166cf8 cmp r4, #0
 *   @0x166cfc vcvt.f64.s32 d9, s5
 *   @0x166d00 vmov s11, r3
 *   @0x166d04 vmul.f64 d9, d9, d10
 *   @0x166d08 vcvt.f64.s32 d8, s11
 *   @0x166d0c ble 0x166d74 <_ZN9CBitmap32C2Eiijji+0x60c>
 *   @0x166d10 add r8, r12, #3
 *   @0x166d14 mov r5, #0
 *   @0x166d18 rsb r3, r5, r6
 *   @0x166d1c mov r0, r10
 *   @0x166d20 cmp r3, r5
 *   @0x166d24 movge r3, r5
 *   @0x166d28 mov r1, r9
 *   @0x166d2c add r5, r5, #1
 *   @0x166d30 add r8, r8, #3
 *   @0x166d34 vmov s11, r3
 *   @0x166d38 vcvt.f64.s32 d7, s11
 *   @0x166d3c vcmpe.f64 d7, d8
 *   @0x166d40 vmrs APSR_nzcv, fpscr
 *   @0x166d44 vmovpl.f64 d7, d8
 *   @0x166d48 vdiv.f64 d6, d7, d9
 *   @0x166d4c vmov r2, r3, d6
 *   @0x166d50 bl 0x165ce8 <_ZN17Graphics_Bitmap3211Color_MergeEjjd>
 *   @0x166d54 cmp r5, r4
 *   @0x166d58 strb r0, [r8, #-0x6]
 *   @0x166d5c lsr r3, r0, #16
 *   @0x166d60 lsr r0, r0, #8
 *   @0x166d64 strb r3, [r8, #-0x4]
 *   @0x166d68 strb r0, [r8, #-0x5]
 *   @0x166d6c bne 0x166d18 <_ZN9CBitmap32C2Eiijji+0x5b0>
 *   @0x166d70 ldr r12, [sp, #0x34]
 *   @0x166d74 add r7, r7, #1
 *   @0x166d78 ldr r3, [sp, #0x30]
 *   @0x166d7c cmp r7, r11
 *   @0x166d80 add r12, r12, r3
 *   @0x166d84 str r12, [sp, #0x34]
 *   @0x166d88 beq 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0>
 *   @0x166d8c cmp r4, r11
 *   @0x166d90 blt 0x166ce4 <_ZN9CBitmap32C2Eiijji+0x57c>
 *   @0x166d94 vmov s12, r11
 *   @0x166d98 ldr r0, [sp, #0xc]
 *   @0x166d9c vcvt.f64.s32 d9, s12
 *   @0x166da0 rsb r3, r7, r0
 *   @0x166da4 cmp r3, r7
 *   @0x166da8 movge r3, r7
 *   @0x166dac vmov s5, r3
 *   @0x166db0 vmul.f64 d9, d9, d10
 *   @0x166db4 vcvt.f64.s32 d8, s5
 *   @0x166db8 b 0x166d10 <_ZN9CBitmap32C2Eiijji+0x5a8>
 *   @0x166dbc cmp r11, #0
 *   @0x166dc0 ble 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0>
 *   @0x166dc4 vmov.f64 d9, #5.000000e-01
 *   @0x166dc8 ldr r8, [sp, #0x34]
 *   @0x166dcc ldr r9, [sp, #0x78]
 *   @0x166dd0 sub r6, r4, #1
 *   @0x166dd4 mov r7, #0
 *   @0x166dd8 cmp r4, #0
 *   @0x166ddc ble 0x166e44 <_ZN9CBitmap32C2Eiijji+0x6dc>
 *   @0x166de0 vmov s5, r4
 *   @0x166de4 add r8, r8, #3
 *   @0x166de8 mov r5, #0
 *   @0x166dec vcvt.f64.s32 d8, s5
 *   @0x166df0 vmul.f64 d8, d8, d9
 *   @0x166df4 rsb r3, r5, r6
 *   @0x166df8 mov r0, r10
 *   @0x166dfc cmp r3, r5
 *   @0x166e00 movge r3, r5
 *   @0x166e04 mov r1, r9
 *   @0x166e08 add r5, r5, #1
 *   @0x166e0c add r8, r8, #3
 *   @0x166e10 vmov s11, r3
 *   @0x166e14 vcvt.f64.s32 d7, s11
 *   @0x166e18 vdiv.f64 d6, d7, d8
 *   @0x166e1c vmov r2, r3, d6
 *   @0x166e20 bl 0x165ce8 <_ZN17Graphics_Bitmap3211Color_MergeEjjd>
 *   @0x166e24 cmp r5, r4
 *   @0x166e28 strb r0, [r8, #-0x6]
 *   @0x166e2c lsr r3, r0, #16
 *   @0x166e30 lsr r0, r0, #8
 *   @0x166e34 strb r3, [r8, #-0x4]
 *   @0x166e38 strb r0, [r8, #-0x5]
 *   @0x166e3c bne 0x166df4 <_ZN9CBitmap32C2Eiijji+0x68c>
 *   @0x166e40 ldr r8, [sp, #0x34]
 *   @0x166e44 add r7, r7, #1
 *   @0x166e48 ldr r3, [sp, #0x30]
 *   @0x166e4c cmp r7, r11
 *   @0x166e50 add r8, r8, r3
 *   @0x166e54 str r8, [sp, #0x34]
 *   @0x166e58 bne 0x166dd8 <_ZN9CBitmap32C2Eiijji+0x670>
 *   @0x166e5c b 0x166a48 <_ZN9CBitmap32C2Eiijji+0x2e0>
 *   @0x166e60 vmov d10, r11, r11
 *   @0x166e64 vcvt.f64.s32 d10, d10, #1
 *   @0x166e68 b 0x1668d8 <_ZN9CBitmap32C2Eiijji+0x170>
 *
 * ══ §15/16 CDS_Priority::Delete(RValue*)  0x20a424  size 1400  350 条（0x20a424..0x20a99c）
 * @func 0x20a424 0x20a99c  size 1400  350 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×8 / UNLOCK_RVALUE_MUTEX()×8 / YYFree(void const*)×8 / operator delete(void*)×8 / FREE_RValue__Pre(RValue*)×4 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / _RefThing<char const*>::dec()×2
 * 字段偏移 top8: 0x4×40 / 0x8×18 / 0xc×17 / 0x14×2 / 0x554×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20a424 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20a428 mov r5, r0
 *   @0x20a42c ldr r3, [r0, #0x4]
 *   @0x20a430 mov r8, r1
 *   @0x20a434 cmp r3, #0
 *   @0x20a438 pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20a43c ldr r7, [pc, #0x554]
 *   @0x20a440 mov r4, #0
 *   @0x20a444 ldr r7, [pc, r7]
 *   @0x20a448 b 0x20a458 <_ZN12CDS_Priority6DeleteEP6RValue+0x34>
 *   @0x20a44c ldr r3, [r5, #0x4]
 *   @0x20a450 cmp r3, r4
 *   @0x20a454 ble 0x20a59c <_ZN12CDS_Priority6DeleteEP6RValue+0x178>
 *   @0x20a458 ldr r0, [r5, #0xc]
 *   @0x20a45c lsl r6, r4, #4
 *   @0x20a460 mov r1, r8
 *   @0x20a464 ldrd r2, r3, [r7]
 *   @0x20a468 add r0, r0, r6
 *   @0x20a46c add r4, r4, #1
 *   @0x20a470 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x20a474 cmp r0, #0
 *   @0x20a478 bne 0x20a44c <_ZN12CDS_Priority6DeleteEP6RValue+0x28>
 *   @0x20a47c ldr r7, [r5, #0xc]
 *   @0x20a480 add r4, r7, r6
 *   @0x20a484 ldr r3, [r4, #0xc]
 *   @0x20a488 sub r3, r3, #1
 *   @0x20a48c bic r3, r3, #-16777216
 *   @0x20a490 bic r3, r3, #3
 *   @0x20a494 cmp r3, #0
 *   @0x20a498 beq 0x20a7e4 <_ZN12CDS_Priority6DeleteEP6RValue+0x3c0>
 *   @0x20a49c mov r3, #0
 *   @0x20a4a0 mov r2, #5
 *   @0x20a4a4 str r3, [r4, #0x8]
 *   @0x20a4a8 str r2, [r4, #0xc]
 *   @0x20a4ac str r3, [r7, r6]
 *   @0x20a4b0 ldr r7, [r5, #0x14]
 *   @0x20a4b4 add r4, r7, r6
 *   @0x20a4b8 ldr r3, [r4, #0xc]
 *   @0x20a4bc sub r3, r3, #1
 *   @0x20a4c0 bic r3, r3, #-16777216
 *   @0x20a4c4 bic r3, r3, #3
 *   @0x20a4c8 cmp r3, #0
 *   @0x20a4cc beq 0x20a7d8 <_ZN12CDS_Priority6DeleteEP6RValue+0x3b4>
 *   @0x20a4d0 mov r3, #0
 *   @0x20a4d4 mov r2, #5
 *   @0x20a4d8 str r3, [r4, #0x8]
 *   @0x20a4dc str r2, [r4, #0xc]
 *   @0x20a4e0 str r3, [r7, r6]
 *   @0x20a4e4 ldr r4, [r5, #0xc]
 *   @0x20a4e8 ldr r9, [r5, #0x4]
 *   @0x20a4ec add r7, r4, r6
 *   @0x20a4f0 sub r9, r9, #-268435455
 *   @0x20a4f4 ldr r2, [r7, #0xc]
 *   @0x20a4f8 add r8, r4, r9, lsl #4
 *   @0x20a4fc bic r3, r2, #-16777216
 *   @0x20a500 cmp r3, #1
 *   @0x20a504 beq 0x20a7a4 <_ZN12CDS_Priority6DeleteEP6RValue+0x380>
 *   @0x20a508 cmp r3, #2
 *   @0x20a50c bne 0x20a534 <_ZN12CDS_Priority6DeleteEP6RValue+0x110>
 *   @0x20a510 sub r3, r2, #1
 *   @0x20a514 bic r3, r3, #-16777216
 *   @0x20a518 bic r3, r3, #3
 *   @0x20a51c cmp r3, #0
 *   @0x20a520 beq 0x20a8d0 <_ZN12CDS_Priority6DeleteEP6RValue+0x4ac>
 *   @0x20a524 mov r2, #0
 *   @0x20a528 mov r3, #5
 *   @0x20a52c str r2, [r7, #0x8]
 *   @0x20a530 str r3, [r7, #0xc]
 *   @0x20a534 ldr r3, [r8, #0xc]
 *   @0x20a538 mov r1, #0
 *   @0x20a53c ldr r2, [r8, #0x8]
 *   @0x20a540 str r1, [r4, r6]
 *   @0x20a544 str r3, [r7, #0xc]
 *   @0x20a548 ldr r3, [r8, #0xc]
 *   @0x20a54c str r2, [r7, #0x8]
 *   @0x20a550 bic r3, r3, #-16777216
 *   @0x20a554 cmp r3, #14
 *   @0x20a558 addls pc, pc, r3, lsl #2
 *   @0x20a55c b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184>
 *   @0x20a560 b 0x20a678 <_ZN12CDS_Priority6DeleteEP6RValue+0x254>
 *   @0x20a564 b 0x20a758 <_ZN12CDS_Priority6DeleteEP6RValue+0x334>
 *   @0x20a568 b 0x20a6c4 <_ZN12CDS_Priority6DeleteEP6RValue+0x2a0>
 *   @0x20a56c b 0x20a5a0 <_ZN12CDS_Priority6DeleteEP6RValue+0x17c>
 *   @0x20a570 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184>
 *   @0x20a574 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184>
 *   @0x20a578 b 0x20a6a0 <_ZN12CDS_Priority6DeleteEP6RValue+0x27c>
 *   @0x20a57c b 0x20a5a0 <_ZN12CDS_Priority6DeleteEP6RValue+0x17c>
 *   @0x20a580 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184>
 *   @0x20a584 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184>
 *   @0x20a588 b 0x20a678 <_ZN12CDS_Priority6DeleteEP6RValue+0x254>
 *   @0x20a58c b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184>
 *   @0x20a590 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184>
 *   @0x20a594 b 0x20a678 <_ZN12CDS_Priority6DeleteEP6RValue+0x254>
 *   @0x20a598 b 0x20a5a0 <_ZN12CDS_Priority6DeleteEP6RValue+0x17c>
 *   @0x20a59c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20a5a0 ldr r3, [r4, r9, lsl #4]
 *   @0x20a5a4 str r3, [r4, r6]
 *   @0x20a5a8 ldr r4, [r5, #0x14]
 *   @0x20a5ac ldr r9, [r5, #0x4]
 *   @0x20a5b0 add r7, r4, r6
 *   @0x20a5b4 sub r9, r9, #-268435455
 *   @0x20a5b8 ldr r2, [r7, #0xc]
 *   @0x20a5bc add r8, r4, r9, lsl #4
 *   @0x20a5c0 bic r3, r2, #-16777216
 *   @0x20a5c4 cmp r3, #1
 *   @0x20a5c8 beq 0x20a770 <_ZN12CDS_Priority6DeleteEP6RValue+0x34c>
 *   @0x20a5cc cmp r3, #2
 *   @0x20a5d0 bne 0x20a5f8 <_ZN12CDS_Priority6DeleteEP6RValue+0x1d4>
 *   @0x20a5d4 sub r3, r2, #1
 *   @0x20a5d8 bic r3, r3, #-16777216
 *   @0x20a5dc bic r3, r3, #3
 *   @0x20a5e0 cmp r3, #0
 *   @0x20a5e4 beq 0x20a8dc <_ZN12CDS_Priority6DeleteEP6RValue+0x4b8>
 *   @0x20a5e8 mov r2, #0
 *   @0x20a5ec mov r3, #5
 *   @0x20a5f0 str r2, [r7, #0x8]
 *   @0x20a5f4 str r3, [r7, #0xc]
 *   @0x20a5f8 ldr r3, [r8, #0xc]
 *   @0x20a5fc mov r1, #0
 *   @0x20a600 ldr r2, [r8, #0x8]
 *   @0x20a604 str r1, [r4, r6]
 *   @0x20a608 str r3, [r7, #0xc]
 *   @0x20a60c ldr r3, [r8, #0xc]
 *   @0x20a610 str r2, [r7, #0x8]
 *   @0x20a614 bic r3, r3, #-16777216
 *   @0x20a618 cmp r3, #14
 *   @0x20a61c addls pc, pc, r3, lsl #2
 *   @0x20a620 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244>
 *   @0x20a624 b 0x20a68c <_ZN12CDS_Priority6DeleteEP6RValue+0x268>
 *   @0x20a628 b 0x20a740 <_ZN12CDS_Priority6DeleteEP6RValue+0x31c>
 *   @0x20a62c b 0x20a714 <_ZN12CDS_Priority6DeleteEP6RValue+0x2f0>
 *   @0x20a630 b 0x20a660 <_ZN12CDS_Priority6DeleteEP6RValue+0x23c>
 *   @0x20a634 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244>
 *   @0x20a638 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244>
 *   @0x20a63c b 0x20a6f0 <_ZN12CDS_Priority6DeleteEP6RValue+0x2cc>
 *   @0x20a640 b 0x20a660 <_ZN12CDS_Priority6DeleteEP6RValue+0x23c>
 *   @0x20a644 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244>
 *   @0x20a648 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244>
 *   @0x20a64c b 0x20a68c <_ZN12CDS_Priority6DeleteEP6RValue+0x268>
 *   @0x20a650 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244>
 *   @0x20a654 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244>
 *   @0x20a658 b 0x20a68c <_ZN12CDS_Priority6DeleteEP6RValue+0x268>
 *   @0x20a65c b 0x20a660 <_ZN12CDS_Priority6DeleteEP6RValue+0x23c>
 *   @0x20a660 ldr r3, [r4, r9, lsl #4]
 *   @0x20a664 str r3, [r4, r6]
 *   @0x20a668 ldr r3, [r5, #0x4]
 *   @0x20a66c sub r3, r3, #1
 *   @0x20a670 str r3, [r5, #0x4]
 *   @0x20a674 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20a678 ldr r2, [r4, r9, lsl #4]
 *   @0x20a67c ldr r3, [r8, #0x4]
 *   @0x20a680 str r2, [r4, r6]
 *   @0x20a684 str r3, [r7, #0x4]
 *   @0x20a688 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184>
 *   @0x20a68c ldr r2, [r4, r9, lsl #4]
 *   @0x20a690 ldr r3, [r8, #0x4]
 *   @0x20a694 str r2, [r4, r6]
 *   @0x20a698 str r3, [r7, #0x4]
 *   @0x20a69c b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244>
 *   @0x20a6a0 ldr r3, [r4, r9, lsl #4]
 *   @0x20a6a4 str r3, [r4, r6]
 *   @0x20a6a8 ldr r3, [r4, r9, lsl #4]
 *   @0x20a6ac cmp r3, #0
 *   @0x20a6b0 beq 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184>
 *   @0x20a6b4 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20a6b8 ldr r1, [r4, r9, lsl #4]
 *   @0x20a6bc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20a6c0 b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184>
 *   @0x20a6c4 ldr r3, [r4, r9, lsl #4]
 *   @0x20a6c8 cmp r3, #0
 *   @0x20a6cc str r3, [r4, r6]
 *   @0x20a6d0 beq 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184>
 *   @0x20a6d4 ldr r1, [r3, #0x8]
 *   @0x20a6d8 ldr r2, [r3]
 *   @0x20a6dc cmp r1, #0
 *   @0x20a6e0 streq r7, [r3, #0x8]
 *   @0x20a6e4 add r2, r2, #1
 *   @0x20a6e8 str r2, [r3]
 *   @0x20a6ec b 0x20a5a8 <_ZN12CDS_Priority6DeleteEP6RValue+0x184>
 *   @0x20a6f0 ldr r3, [r4, r9, lsl #4]
 *   @0x20a6f4 str r3, [r4, r6]
 *   @0x20a6f8 ldr r3, [r4, r9, lsl #4]
 *   @0x20a6fc cmp r3, #0
 *   @0x20a700 beq 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244>
 *   @0x20a704 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20a708 ldr r1, [r4, r9, lsl #4]
 *   @0x20a70c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20a710 b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244>
 *   @0x20a714 ldr r3, [r4, r9, lsl #4]
 *   @0x20a718 cmp r3, #0
 *   @0x20a71c str r3, [r4, r6]
 *   @0x20a720 beq 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244>
 *   @0x20a724 ldr r1, [r3, #0x8]
 *   @0x20a728 ldr r2, [r3]
 *   @0x20a72c cmp r1, #0
 *   @0x20a730 streq r7, [r3, #0x8]
 *   @0x20a734 add r2, r2, #1
 *   @0x20a738 str r2, [r3]
 *   @0x20a73c b 0x20a668 <_ZN12CDS_Priority6DeleteEP6RValue+0x244>
 *   @0x20a740 ldr r3, [r4, r9, lsl #4]
 *   @0x20a744 cmp r3, #0
 *   @0x20a748 ldrne r2, [r3, #0x4]
 *   @0x20a74c addne r2, r2, #1
 *   @0x20a750 strne r2, [r3, #0x4]
 *   @0x20a754 b 0x20a664 <_ZN12CDS_Priority6DeleteEP6RValue+0x240>
 *   @0x20a758 ldr r3, [r4, r9, lsl #4]
 *   @0x20a75c cmp r3, #0
 *   @0x20a760 ldrne r2, [r3, #0x4]
 *   @0x20a764 addne r2, r2, #1
 *   @0x20a768 strne r2, [r3, #0x4]
 *   @0x20a76c b 0x20a5a4 <_ZN12CDS_Priority6DeleteEP6RValue+0x180>
 *   @0x20a770 ldr r10, [r4, r6]
 *   @0x20a774 cmp r10, #0
 *   @0x20a778 beq 0x20a798 <_ZN12CDS_Priority6DeleteEP6RValue+0x374>
 *   @0x20a77c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a780 ldr r11, [r10, #0x4]
 *   @0x20a784 sub r11, r11, #1
 *   @0x20a788 str r11, [r10, #0x4]
 *   @0x20a78c cmp r11, #0
 *   @0x20a790 beq 0x20a7f0 <_ZN12CDS_Priority6DeleteEP6RValue+0x3cc>
 *   @0x20a794 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a798 mov r3, #0
 *   @0x20a79c str r3, [r4, r6]
 *   @0x20a7a0 b 0x20a5f8 <_ZN12CDS_Priority6DeleteEP6RValue+0x1d4>
 *   @0x20a7a4 ldr r10, [r4, r6]
 *   @0x20a7a8 cmp r10, #0
 *   @0x20a7ac beq 0x20a7cc <_ZN12CDS_Priority6DeleteEP6RValue+0x3a8>
 *   @0x20a7b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a7b4 ldr r11, [r10, #0x4]
 *   @0x20a7b8 sub r11, r11, #1
 *   @0x20a7bc str r11, [r10, #0x4]
 *   @0x20a7c0 cmp r11, #0
 *   @0x20a7c4 beq 0x20a828 <_ZN12CDS_Priority6DeleteEP6RValue+0x404>
 *   @0x20a7c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a7cc mov r3, #0
 *   @0x20a7d0 str r3, [r4, r6]
 *   @0x20a7d4 b 0x20a534 <_ZN12CDS_Priority6DeleteEP6RValue+0x110>
 *   @0x20a7d8 mov r0, r4
 *   @0x20a7dc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20a7e0 b 0x20a4d0 <_ZN12CDS_Priority6DeleteEP6RValue+0xac>
 *   @0x20a7e4 mov r0, r4
 *   @0x20a7e8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20a7ec b 0x20a49c <_ZN12CDS_Priority6DeleteEP6RValue+0x78>
 *   @0x20a7f0 ldr r0, [r10]
 *   @0x20a7f4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a7f8 str r11, [r10]
 *   @0x20a7fc str r11, [r10, #0x8]
 *   @0x20a800 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a804 ldr r11, [r10, #0x4]
 *   @0x20a808 sub r11, r11, #1
 *   @0x20a80c str r11, [r10, #0x4]
 *   @0x20a810 cmp r11, #0
 *   @0x20a814 beq 0x20a898 <_ZN12CDS_Priority6DeleteEP6RValue+0x474>
 *   @0x20a818 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a81c mov r0, r10
 *   @0x20a820 bl 0x27d1d0 <_ZdlPv>
 *   @0x20a824 b 0x20a794 <_ZN12CDS_Priority6DeleteEP6RValue+0x370>
 *   @0x20a828 ldr r0, [r10]
 *   @0x20a82c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a830 str r11, [r10]
 *   @0x20a834 str r11, [r10, #0x8]
 *   @0x20a838 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a83c ldr r11, [r10, #0x4]
 *   @0x20a840 sub r11, r11, #1
 *   @0x20a844 str r11, [r10, #0x4]
 *   @0x20a848 cmp r11, #0
 *   @0x20a84c beq 0x20a860 <_ZN12CDS_Priority6DeleteEP6RValue+0x43c>
 *   @0x20a850 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a854 mov r0, r10
 *   @0x20a858 bl 0x27d1d0 <_ZdlPv>
 *   @0x20a85c b 0x20a7c8 <_ZN12CDS_Priority6DeleteEP6RValue+0x3a4>
 *   @0x20a860 ldr r0, [r10]
 *   @0x20a864 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a868 str r11, [r10]
 *   @0x20a86c str r11, [r10, #0x8]
 *   @0x20a870 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a874 ldr r11, [r10, #0x4]
 *   @0x20a878 sub r11, r11, #1
 *   @0x20a87c str r11, [r10, #0x4]
 *   @0x20a880 cmp r11, #0
 *   @0x20a884 beq 0x20a8e8 <_ZN12CDS_Priority6DeleteEP6RValue+0x4c4>
 *   @0x20a888 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a88c mov r0, r10
 *   @0x20a890 bl 0x27d1d0 <_ZdlPv>
 *   @0x20a894 b 0x20a850 <_ZN12CDS_Priority6DeleteEP6RValue+0x42c>
 *   @0x20a898 ldr r0, [r10]
 *   @0x20a89c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a8a0 str r11, [r10]
 *   @0x20a8a4 str r11, [r10, #0x8]
 *   @0x20a8a8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a8ac ldr r11, [r10, #0x4]
 *   @0x20a8b0 sub r11, r11, #1
 *   @0x20a8b4 str r11, [r10, #0x4]
 *   @0x20a8b8 cmp r11, #0
 *   @0x20a8bc beq 0x20a940 <_ZN12CDS_Priority6DeleteEP6RValue+0x51c>
 *   @0x20a8c0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a8c4 mov r0, r10
 *   @0x20a8c8 bl 0x27d1d0 <_ZdlPv>
 *   @0x20a8cc b 0x20a818 <_ZN12CDS_Priority6DeleteEP6RValue+0x3f4>
 *   @0x20a8d0 mov r0, r7
 *   @0x20a8d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20a8d8 b 0x20a524 <_ZN12CDS_Priority6DeleteEP6RValue+0x100>
 *   @0x20a8dc mov r0, r7
 *   @0x20a8e0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20a8e4 b 0x20a5e8 <_ZN12CDS_Priority6DeleteEP6RValue+0x1c4>
 *   @0x20a8e8 ldr r0, [r10]
 *   @0x20a8ec bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a8f0 str r11, [r10]
 *   @0x20a8f4 str r11, [r10, #0x8]
 *   @0x20a8f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a8fc ldr r11, [r10, #0x4]
 *   @0x20a900 sub r11, r11, #1
 *   @0x20a904 str r11, [r10, #0x4]
 *   @0x20a908 cmp r11, #0
 *   @0x20a90c bne 0x20a930 <_ZN12CDS_Priority6DeleteEP6RValue+0x50c>
 *   @0x20a910 ldr r0, [r10]
 *   @0x20a914 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a918 mov r0, r10
 *   @0x20a91c str r11, [r10]
 *   @0x20a920 str r11, [r10, #0x8]
 *   @0x20a924 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20a928 mov r0, r10
 *   @0x20a92c bl 0x27d1d0 <_ZdlPv>
 *   @0x20a930 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a934 mov r0, r10
 *   @0x20a938 bl 0x27d1d0 <_ZdlPv>
 *   @0x20a93c b 0x20a888 <_ZN12CDS_Priority6DeleteEP6RValue+0x464>
 *   @0x20a940 ldr r0, [r10]
 *   @0x20a944 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a948 str r11, [r10]
 *   @0x20a94c str r11, [r10, #0x8]
 *   @0x20a950 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20a954 ldr r11, [r10, #0x4]
 *   @0x20a958 sub r11, r11, #1
 *   @0x20a95c str r11, [r10, #0x4]
 *   @0x20a960 cmp r11, #0
 *   @0x20a964 bne 0x20a988 <_ZN12CDS_Priority6DeleteEP6RValue+0x564>
 *   @0x20a968 ldr r0, [r10]
 *   @0x20a96c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20a970 mov r0, r10
 *   @0x20a974 str r11, [r10]
 *   @0x20a978 str r11, [r10, #0x8]
 *   @0x20a97c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20a980 mov r0, r10
 *   @0x20a984 bl 0x27d1d0 <_ZdlPv>
 *   @0x20a988 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20a98c mov r0, r10
 *   @0x20a990 bl 0x27d1d0 <_ZdlPv>
 *   @0x20a994 b 0x20a8c0 <_ZN12CDS_Priority6DeleteEP6RValue+0x49c>
 *   @0x20a998 andseq r6, lr, r0, asr #30
 *
 * ══ §16/16 FINALIZE_All()  0xc47f8  size 4  1 条（0xc47f8..0xc47fc）
 * @func 0xc47f8 0xc47fc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc47f8 bx lr
 */
