/* cally 逆向卡：All_41 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 57 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/57 F_LayerHasInstance(RValue&, CInstance*, CInstance*, int, RValue*)  0x1baba8  size 556  139 条（0x1baba8..0x1badd4）
 * @func 0x1baba8 0x1badd4  size 556  139 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / CObjectGM::IsDecendentOf(int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×5 / 0x4×5 / 0x8×3 / 0x3×2 / 0x200×1 / 0x18×1 / 0x1d8×1 / 0x194×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1baba8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1babac cmp r3, #2
 *   @0x1babb0 ldr r6, [pc, #0x200]
 *   @0x1babb4 mov r3, #0
 *   @0x1babb8 mov r4, r3
 *   @0x1babbc mov r5, r0
 *   @0x1babc0 movt r3, #0xbff0
 *   @0x1babc4 add r6, pc, r6
 *   @0x1babc8 str r4, [r0, #0xc]
 *   @0x1babcc str r3, [r0, #0x4]
 *   @0x1babd0 str r4, [r0]
 *   @0x1babd4 ldr r7, [sp, #0x18]
 *   @0x1babd8 beq 0x1babf0 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1babdc ldr r0, [pc, #0x1d8]
 *   @0x1babe0 mov r1, r4
 *   @0x1babe4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1babe8 add r0, pc, r0
 *   @0x1babec b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1babf0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1babf4 ldr r3, [r7, #0xc]
 *   @0x1babf8 mov r1, r4
 *   @0x1babfc bic r3, r3, #-16777216
 *   @0x1bac00 cmp r3, #1
 *   @0x1bac04 mov r8, r0
 *   @0x1bac08 mov r0, r7
 *   @0x1bac0c beq 0x1bad04 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x1bac10 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bac14 mov r1, r0
 *   @0x1bac18 mov r0, r8
 *   @0x1bac1c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bac20 mov r4, r0
 *   @0x1bac24 ldr r1, [pc, #0x194]
 *   @0x1bac28 cmp r4, #0
 *   @0x1bac2c ldr r3, [pc, #0x190]
 *   @0x1bac30 mov r2, r4
 *   @0x1bac34 add r1, pc, r1
 *   @0x1bac38 beq 0x1bad74 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x1bac3c mov r0, r7
 *   @0x1bac40 mov r1, #1
 *   @0x1bac44 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bac48 movw r3, #0x869f
 *   @0x1bac4c movt r3, #0x1
 *   @0x1bac50 cmp r0, r3
 *   @0x1bac54 mov r7, r0
 *   @0x1bac58 bgt 0x1bad1c <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x1bac5c ldr r4, [r4, #0x58]
 *   @0x1bac60 cmp r4, #0
 *   @0x1bac64 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1bac68 ldr r3, [r4]
 *   @0x1bac6c cmp r3, #2
 *   @0x1bac70 beq 0x1bac84 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x1bac74 ldr r4, [r4, #0x14]
 *   @0x1bac78 cmp r4, #0
 *   @0x1bac7c bne 0x1bac68 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1bac80 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1bac84 ldr r3, [r4, #0x20]
 *   @0x1bac88 ldr r12, [r3, #0x7c]
 *   @0x1bac8c cmp r7, r12
 *   @0x1bac90 beq 0x1bace8 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1bac94 ldr r3, [pc, #0x12c]
 *   @0x1bac98 ldr r3, [r6, r3]
 *   @0x1bac9c ldr r3, [r3]
 *   @0x1baca0 ldr r2, [r3, #0x4]
 *   @0x1baca4 ldr r3, [r3]
 *   @0x1baca8 and r2, r12, r2
 *   @0x1bacac ldr r3, [r3, r2, lsl #3]
 *   @0x1bacb0 cmp r3, #0
 *   @0x1bacb4 bne 0x1bacc8 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x1bacb8 b 0x1bacfc <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x1bacbc ldr r3, [r3, #0x4]
 *   @0x1bacc0 cmp r3, #0
 *   @0x1bacc4 beq 0x1bacfc <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x1bacc8 ldr r2, [r3, #0x8]
 *   @0x1baccc cmp r12, r2
 *   @0x1bacd0 bne 0x1bacbc <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x1bacd4 ldr r0, [r3, #0xc]
 *   @0x1bacd8 mov r1, r7
 *   @0x1bacdc bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi>
 *   @0x1bace0 cmp r0, #0
 *   @0x1bace4 beq 0x1bac74 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x1bace8 mov r3, #0
 *   @0x1bacec mov r2, r3
 *   @0x1bacf0 movt r3, #0x3ff0
 *   @0x1bacf4 stm r5, {r2, r3}
 *   @0x1bacf8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1bacfc mov r0, r3
 *   @0x1bad00 b 0x1bacd8 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x1bad04 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bad08 mov r1, r0
 *   @0x1bad0c mov r0, r8
 *   @0x1bad10 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bad14 mov r4, r0
 *   @0x1bad18 b 0x1bac24 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x1bad1c ldr r3, [pc, #0xa8]
 *   @0x1bad20 ldr r3, [r6, r3]
 *   @0x1bad24 ldr r2, [r3, #0x4]
 *   @0x1bad28 ldr r3, [r3]
 *   @0x1bad2c and r2, r0, r2
 *   @0x1bad30 ldr r3, [r3, r2, lsl #3]
 *   @0x1bad34 cmp r3, #0
 *   @0x1bad38 beq 0x1bad64 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x1bad3c ldr r2, [r3, #0x8]
 *   @0x1bad40 cmp r0, r2
 *   @0x1bad44 bne 0x1bad58 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x1bad48 b 0x1bad8c <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x1bad4c ldr r1, [r3, #0x8]
 *   @0x1bad50 cmp r7, r1
 *   @0x1bad54 beq 0x1bad8c <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x1bad58 ldr r3, [r3, #0x4]
 *   @0x1bad5c cmp r3, #0
 *   @0x1bad60 bne 0x1bad4c <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x1bad64 ldr r1, [pc, #0x64]
 *   @0x1bad68 mov r2, #0
 *   @0x1bad6c ldr r3, [pc, #0x50]
 *   @0x1bad70 add r1, pc, r1
 *   @0x1bad74 ldr r3, [r6, r3]
 *   @0x1bad78 ldr r0, [r3]
 *   @0x1bad7c ldr r3, [r0]
 *   @0x1bad80 ldr r3, [r3, #0xc]
 *   @0x1bad84 blx r3
 *   @0x1bad88 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1bad8c ldr r3, [r3, #0xc]
 *   @0x1bad90 cmp r3, #0
 *   @0x1bad94 beq 0x1bad64 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x1bad98 ldrb r2, [r3, #0x174]
 *   @0x1bad9c cmp r2, #0
 *   @0x1bada0 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1bada4 ldr r2, [r3, #0x170]
 *   @0x1bada8 ldr r3, [r4]
 *   @0x1badac cmp r2, r3
 *   @0x1badb0 popne {r4, r5, r6, r7, r8, pc}
 *   @0x1badb4 b 0x1bace8 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1badb8 eoreq r7, r3, r12, lsl #1
 *   @0x1badbc andseq r2, r9, r0, asr r12
 *   @0x1badc0 andseq r2, r9, r8, lsr r12
 *   @0x1badc4 .word 0xffffbac4
 *   @0x1badc8 .word 0xffffbfec
 *   @0x1badcc .word 0xffffbff4
 *   @0x1badd0 andseq r2, r9, r4, asr #22
 *
 * ══ §2/57 jinit_color_deconverter  0x2bdf68  size 556  139 条（0x2bdf68..0x2be194）
 * @func 0x2bdf68 0x2be194  size 556  139 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2bdb14×2 / jinit_color_deconverter+0xbc
 * 字段偏移 top8: 0x4×8 / 0x24×7 / 0x64×4 / 0x2c×3 / 0x28×2 / 0x14×2 / 0x1e4×1 / 0x1a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bdf68 push {r3, r4, r5, lr}
 *   @0x2bdf6c mov r1, #1
 *   @0x2bdf70 ldr r3, [r0, #0x4]
 *   @0x2bdf74 mov r2, #24
 *   @0x2bdf78 mov r4, r0
 *   @0x2bdf7c ldr r3, [r3]
 *   @0x2bdf80 blx r3
 *   @0x2bdf84 ldr r2, [r4, #0x28]
 *   @0x2bdf88 ldr r1, [pc, #0x1e4]
 *   @0x2bdf8c sub r3, r2, #1
 *   @0x2bdf90 add r1, pc, r1
 *   @0x2bdf94 str r0, [r4, #0x1a4]
 *   @0x2bdf98 mov r5, r0
 *   @0x2bdf9c str r1, [r0]
 *   @0x2bdfa0 cmp r3, #4
 *   @0x2bdfa4 addls pc, pc, r3, lsl #2
 *   @0x2bdfa8 b 0x2be10c <jinit_color_deconverter+0x1a4>
 *   @0x2bdfac b 0x2be084 <jinit_color_deconverter+0x11c>
 *   @0x2bdfb0 b 0x2be03c <jinit_color_deconverter+0xd4>
 *   @0x2bdfb4 b 0x2be03c <jinit_color_deconverter+0xd4>
 *   @0x2bdfb8 b 0x2bdfc0 <jinit_color_deconverter+0x58>
 *   @0x2bdfbc b 0x2bdfc0 <jinit_color_deconverter+0x58>
 *   @0x2bdfc0 ldr r3, [r4, #0x24]
 *   @0x2bdfc4 cmp r3, #4
 *   @0x2bdfc8 beq 0x2bdfe8 <jinit_color_deconverter+0x80>
 *   @0x2bdfcc ldr r3, [r4]
 *   @0x2bdfd0 mov r2, #10
 *   @0x2bdfd4 mov r0, r4
 *   @0x2bdfd8 str r2, [r3, #0x14]
 *   @0x2bdfdc ldr r3, [r3]
 *   @0x2bdfe0 blx r3
 *   @0x2bdfe4 ldr r2, [r4, #0x28]
 *   @0x2bdfe8 ldr r3, [r4, #0x2c]
 *   @0x2bdfec cmp r3, #2
 *   @0x2bdff0 beq 0x2be054 <jinit_color_deconverter+0xec>
 *   @0x2bdff4 cmp r3, #4
 *   @0x2bdff8 beq 0x2be0e8 <jinit_color_deconverter+0x180>
 *   @0x2bdffc cmp r3, #1
 *   @0x2be000 beq 0x2be094 <jinit_color_deconverter+0x12c>
 *   @0x2be004 cmp r3, r2
 *   @0x2be008 beq 0x2be11c <jinit_color_deconverter+0x1b4>
 *   @0x2be00c ldr r3, [r4]
 *   @0x2be010 mov r2, #27
 *   @0x2be014 mov r0, r4
 *   @0x2be018 str r2, [r3, #0x14]
 *   @0x2be01c ldr r3, [r3]
 *   @0x2be020 blx r3
 *   @0x2be024 ldrb r3, [r4, #0x4a]
 *   @0x2be028 cmp r3, #0
 *   @0x2be02c ldreq r3, [r4, #0x64]
 *   @0x2be030 movne r3, #1
 *   @0x2be034 str r3, [r4, #0x68]
 *   @0x2be038 pop {r3, r4, r5, pc}
 *   @0x2be03c ldr r3, [r4, #0x24]
 *   @0x2be040 cmp r3, #3
 *   @0x2be044 bne 0x2bdfcc <jinit_color_deconverter+0x64>
 *   @0x2be048 ldr r3, [r4, #0x2c]
 *   @0x2be04c cmp r3, #2
 *   @0x2be050 bne 0x2bdff4 <jinit_color_deconverter+0x8c>
 *   @0x2be054 cmp r2, #3
 *   @0x2be058 mov r3, #3
 *   @0x2be05c str r3, [r4, #0x64]
 *   @0x2be060 beq 0x2be15c <jinit_color_deconverter+0x1f4>
 *   @0x2be064 cmp r2, #1
 *   @0x2be068 beq 0x2be134 <jinit_color_deconverter+0x1cc>
 *   @0x2be06c cmp r2, #2
 *   @0x2be070 bne 0x2be00c <jinit_color_deconverter+0xa4>
 *   @0x2be074 ldr r3, [pc, #0xfc]
 *   @0x2be078 add r3, pc, r3
 *   @0x2be07c str r3, [r5, #0x4]
 *   @0x2be080 b 0x2be024 <jinit_color_deconverter+0xbc>
 *   @0x2be084 ldr r2, [r4, #0x24]
 *   @0x2be088 cmp r2, #1
 *   @0x2be08c bne 0x2bdfcc <jinit_color_deconverter+0x64>
 *   @0x2be090 b 0x2bdfe8 <jinit_color_deconverter+0x80>
 *   @0x2be094 bic r2, r2, #2
 *   @0x2be098 str r3, [r4, #0x64]
 *   @0x2be09c cmp r2, #1
 *   @0x2be0a0 bne 0x2be00c <jinit_color_deconverter+0xa4>
 *   @0x2be0a4 ldr r1, [r4, #0x24]
 *   @0x2be0a8 ldr r3, [pc, #0xcc]
 *   @0x2be0ac cmp r1, #1
 *   @0x2be0b0 add r3, pc, r3
 *   @0x2be0b4 str r3, [r5, #0x4]
 *   @0x2be0b8 ble 0x2be024 <jinit_color_deconverter+0xbc>
 *   @0x2be0bc mov r3, #84
 *   @0x2be0c0 mov r0, #0
 *   @0x2be0c4 ldr r1, [r4, #0xc4]
 *   @0x2be0c8 add r2, r2, #1
 *   @0x2be0cc add r1, r1, r3
 *   @0x2be0d0 add r3, r3, #84
 *   @0x2be0d4 strb r0, [r1, #0x30]
 *   @0x2be0d8 ldr r1, [r4, #0x24]
 *   @0x2be0dc cmp r1, r2
 *   @0x2be0e0 bgt 0x2be0c4 <jinit_color_deconverter+0x15c>
 *   @0x2be0e4 b 0x2be024 <jinit_color_deconverter+0xbc>
 *   @0x2be0e8 cmp r2, #5
 *   @0x2be0ec str r3, [r4, #0x64]
 *   @0x2be0f0 beq 0x2be144 <jinit_color_deconverter+0x1dc>
 *   @0x2be0f4 cmp r2, #4
 *   @0x2be0f8 bne 0x2be00c <jinit_color_deconverter+0xa4>
 *   @0x2be0fc ldr r3, [pc, #0x7c]
 *   @0x2be100 add r3, pc, r3
 *   @0x2be104 str r3, [r5, #0x4]
 *   @0x2be108 b 0x2be024 <jinit_color_deconverter+0xbc>
 *   @0x2be10c ldr r3, [r4, #0x24]
 *   @0x2be110 cmp r3, #0
 *   @0x2be114 bgt 0x2bdfe8 <jinit_color_deconverter+0x80>
 *   @0x2be118 b 0x2bdfcc <jinit_color_deconverter+0x64>
 *   @0x2be11c ldr r2, [r4, #0x24]
 *   @0x2be120 ldr r3, [pc, #0x5c]
 *   @0x2be124 str r2, [r4, #0x64]
 *   @0x2be128 add r3, pc, r3
 *   @0x2be12c str r3, [r5, #0x4]
 *   @0x2be130 b 0x2be024 <jinit_color_deconverter+0xbc>
 *   @0x2be134 ldr r3, [pc, #0x4c]
 *   @0x2be138 add r3, pc, r3
 *   @0x2be13c str r3, [r5, #0x4]
 *   @0x2be140 b 0x2be024 <jinit_color_deconverter+0xbc>
 *   @0x2be144 ldr r3, [pc, #0x40]
 *   @0x2be148 mov r0, r4
 *   @0x2be14c add r3, pc, r3
 *   @0x2be150 str r3, [r5, #0x4]
 *   @0x2be154 bl 0x2bdb14 <jinit_d_coef_controller+0x174>
 *   @0x2be158 b 0x2be024 <jinit_color_deconverter+0xbc>
 *   @0x2be15c ldr r3, [pc, #0x2c]
 *   @0x2be160 mov r0, r4
 *   @0x2be164 add r3, pc, r3
 *   @0x2be168 str r3, [r5, #0x4]
 *   @0x2be16c bl 0x2bdb14 <jinit_d_coef_controller+0x174>
 *   @0x2be170 b 0x2be024 <jinit_color_deconverter+0xbc>
 *   @0x2be174 .word 0xffffff94
 *   @0x2be178 .word 0xfffffc9c
 *   @0x2be17c .word 0xfffffe78
 *   @0x2be180 .word 0xfffffc14
 *   @0x2be184 .word 0xfffffbec
 *   @0x2be188 .word 0xfffffc5c
 *   @0x2be18c .word 0xfffffca4
 *   @0x2be190 .word 0xfffffaa0
 *
 * ══ §3/57 Background_Replace(int, char const*, bool, bool, bool)  0xc3aa4  size 552  138 条（0xc3aa4..0xc3ccc）
 * @func 0xc3aa4 0xc3ccc  size 552  138 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xc3ae0→0x479cb8, 0xc3b54→0x533c54
 * 调用序列: operator new(unsigned int)×3 / 0xb65e0×2 / CBackground::CBackground()×2 / Background_Replace(int, char const*, bool, bool, bool)+0x10c / LoadSave::HTTP_Get(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*) / LoadSave::SaveFileExists(char const*) / LoadSave::BundleFileExists(char const*) / LoadSave::_GetBundleFileName(char*, int, char const*)
 * 字段偏移 top8: 0x4×6 / 0x2×5 / 0x414×2 / 0xc×2 / 0x1f0×1 / 0x1ec×1 / 0x440×1 / 0x1c4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc3aa4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc3aa8 subs r6, r0, #0
 *   @0xc3aac ldr r4, [pc, #0x1f0]
 *   @0xc3ab0 sub sp, sp, #1040
 *   @0xc3ab4 ldr r0, [pc, #0x1ec]
 *   @0xc3ab8 mov r9, r3
 *   @0xc3abc add r4, pc, r4
 *   @0xc3ac0 sub sp, sp, #12
 *   @0xc3ac4 mov r8, r2
 *   @0xc3ac8 mov r7, r1
 *   @0xc3acc ldr r5, [r4, r0]
 *   @0xc3ad0 ldrb r10, [sp, #0x440]
 *   @0xc3ad4 ldr r3, [r5]
 *   @0xc3ad8 str r3, [sp, #0x414]
 *   @0xc3adc blt 0xc3bb0 <_Z18Background_ReplaceiPKcbbb+0x10c>
 *   @0xc3ae0 ldr r3, [pc, #0x1c4]
 *   @0xc3ae4 ldr r3, [r4, r3]
 *   @0xc3ae8 ldr r3, [r3]
 *   @0xc3aec cmp r6, r3
 *   @0xc3af0 bge 0xc3bb0 <_Z18Background_ReplaceiPKcbbb+0x10c>
 *   @0xc3af4 cmp r1, #0
 *   @0xc3af8 beq 0xc3c3c <_Z18Background_ReplaceiPKcbbb+0x198>
 *   @0xc3afc ldr r0, [pc, #0x1ac]
 *   @0xc3b00 mov r2, #7
 *   @0xc3b04 add r0, pc, r0
 *   @0xc3b08 bl 0xb65e0 <strncmp@plt>
 *   @0xc3b0c cmp r0, #0
 *   @0xc3b10 beq 0xc3b30 <_Z18Background_ReplaceiPKcbbb+0x8c>
 *   @0xc3b14 ldr r0, [pc, #0x198]
 *   @0xc3b18 mov r1, r7
 *   @0xc3b1c mov r2, #8
 *   @0xc3b20 add r0, pc, r0
 *   @0xc3b24 bl 0xb65e0 <strncmp@plt>
 *   @0xc3b28 cmp r0, #0
 *   @0xc3b2c bne 0xc3bd0 <_Z18Background_ReplaceiPKcbbb+0x12c>
 *   @0xc3b30 ldr r11, [pc, #0x180]
 *   @0xc3b34 add r11, pc, r11
 *   @0xc3b38 ldr r3, [r11, #0x4]
 *   @0xc3b3c ldr r3, [r3, r6, lsl #2]
 *   @0xc3b40 cmp r3, #0
 *   @0xc3b44 beq 0xc3c5c <_Z18Background_ReplaceiPKcbbb+0x1b8>
 *   @0xc3b48 mov r0, #8
 *   @0xc3b4c bl 0x27c524 <_Znwj>
 *   @0xc3b50 cmp r9, #0
 *   @0xc3b54 ldr r3, [pc, #0x160]
 *   @0xc3b58 mov r1, #7
 *   @0xc3b5c movne r9, #2
 *   @0xc3b60 moveq r9, #0
 *   @0xc3b64 cmp r10, #0
 *   @0xc3b68 orr r8, r9, r8
 *   @0xc3b6c ldr r2, [pc, #0x14c]
 *   @0xc3b70 movne r10, #4
 *   @0xc3b74 moveq r10, #0
 *   @0xc3b78 orr r8, r8, r10
 *   @0xc3b7c stm r0, {r6, r8}
 *   @0xc3b80 mov r12, r0
 *   @0xc3b84 ldr lr, [r4, r3]
 *   @0xc3b88 mov r0, r7
 *   @0xc3b8c ldr r3, [pc, #0x130]
 *   @0xc3b90 mov r6, #1
 *   @0xc3b94 strb r6, [lr]
 *   @0xc3b98 ldr r2, [r4, r2]
 *   @0xc3b9c ldr r3, [r4, r3]
 *   @0xc3ba0 str r12, [sp]
 *   @0xc3ba4 bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_>
 *   @0xc3ba8 mov r0, #0
 *   @0xc3bac b 0xc3bb4 <_Z18Background_ReplaceiPKcbbb+0x110>
 *   @0xc3bb0 mov r0, #0
 *   @0xc3bb4 ldr r2, [sp, #0x414]
 *   @0xc3bb8 ldr r3, [r5]
 *   @0xc3bbc cmp r2, r3
 *   @0xc3bc0 bne 0xc3ca0 <_Z18Background_ReplaceiPKcbbb+0x1fc>
 *   @0xc3bc4 add sp, sp, #1040
 *   @0xc3bc8 add sp, sp, #12
 *   @0xc3bcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc3bd0 mov r0, r7
 *   @0xc3bd4 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xc3bd8 cmp r0, #0
 *   @0xc3bdc bne 0xc3c44 <_Z18Background_ReplaceiPKcbbb+0x1a0>
 *   @0xc3be0 mov r0, r7
 *   @0xc3be4 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0xc3be8 cmp r0, #0
 *   @0xc3bec beq 0xc3bb4 <_Z18Background_ReplaceiPKcbbb+0x110>
 *   @0xc3bf0 add r4, sp, #20
 *   @0xc3bf4 mov r2, r7
 *   @0xc3bf8 mov r1, #1024
 *   @0xc3bfc mov r0, r4
 *   @0xc3c00 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0xc3c04 ldr r7, [pc, #0xbc]
 *   @0xc3c08 add r7, pc, r7
 *   @0xc3c0c ldr r3, [r7, #0x4]
 *   @0xc3c10 ldr r0, [r3, r6, lsl #2]
 *   @0xc3c14 cmp r0, #0
 *   @0xc3c18 beq 0xc3c7c <_Z18Background_ReplaceiPKcbbb+0x1d8>
 *   @0xc3c1c eor r12, r8, #1
 *   @0xc3c20 str r10, [sp]
 *   @0xc3c24 mov r1, r4
 *   @0xc3c28 mov r3, r9
 *   @0xc3c2c mov r2, r8
 *   @0xc3c30 str r12, [sp, #0x4]
 *   @0xc3c34 bl 0xc2984 <_ZN11CBackground12LoadFromFileEPKcbbbb>
 *   @0xc3c38 b 0xc3bb4 <_Z18Background_ReplaceiPKcbbb+0x110>
 *   @0xc3c3c mov r0, r1
 *   @0xc3c40 b 0xc3bb4 <_Z18Background_ReplaceiPKcbbb+0x110>
 *   @0xc3c44 add r4, sp, #20
 *   @0xc3c48 mov r2, r7
 *   @0xc3c4c mov r1, #1024
 *   @0xc3c50 mov r0, r4
 *   @0xc3c54 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0xc3c58 b 0xc3c04 <_Z18Background_ReplaceiPKcbbb+0x160>
 *   @0xc3c5c mov r0, #72
 *   @0xc3c60 bl 0x27c524 <_Znwj>
 *   @0xc3c64 str r0, [sp, #0xc]
 *   @0xc3c68 bl 0xc2b58 <_ZN11CBackgroundC2Ev>
 *   @0xc3c6c ldr r2, [r11, #0x4]
 *   @0xc3c70 ldr r3, [sp, #0xc]
 *   @0xc3c74 str r3, [r2, r6, lsl #2]
 *   @0xc3c78 b 0xc3b48 <_Z18Background_ReplaceiPKcbbb+0xa4>
 *   @0xc3c7c mov r0, #72
 *   @0xc3c80 bl 0x27c524 <_Znwj>
 *   @0xc3c84 mov r11, r0
 *   @0xc3c88 bl 0xc2b58 <_ZN11CBackgroundC2Ev>
 *   @0xc3c8c ldr r3, [r7, #0x4]
 *   @0xc3c90 str r11, [r3, r6, lsl #2]
 *   @0xc3c94 ldr r3, [r7, #0x4]
 *   @0xc3c98 ldr r0, [r3, r6, lsl #2]
 *   @0xc3c9c b 0xc3c1c <_Z18Background_ReplaceiPKcbbb+0x178>
 *   @0xc3ca0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xc3ca4 mlaseq r2, r4, r1, lr
 *   @0xc3ca8 .word 0xffffbd00
 *   @0xc3cac .word 0xffffbcf8
 *   @0xc3cb0 .word 0x0026cfdc
 *   @0xc3cb4 eoreq r12, r6, r8, asr #31
 *   @0xc3cb8 eorseq r6, r11, r4, ror r1
 *   @0xc3cbc .word 0xffffbd04
 *   @0xc3cc0 .word 0xffffbd08
 *   @0xc3cc4 .word 0xffffbd0c
 *   @0xc3cc8 eorseq r6, r11, r0, lsr #1
 *
 * ══ §4/57 GraphicsPerf::Print(float, float, float, float, unsigned int, char*, int)  0x17c030  size 552  138 条（0x17c030..0x17c258）
 * @func 0x17c030 0x17c258  size 552  138 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / Graphics::AllocVerts(ePrimType, void*, int, int) / GraphicsPerf::Print(float, float, float, float, unsigned int, char*, int)+0x1e8 / Graphics::FreeVerts(int) / 0xfe17c244
 * 字段偏移 top8: 0x2×2 / 0x1×2 / 0x34×1 / 0x38×1 / 0x30×1 / 0x1e8×1 / 0x3×1 / 0x-10×1
 * VFP 指令 64 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17c030 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x17c034 vpush {d8, d9}
 *   @0x17c038 vmov s19, r0
 *   @0x17c03c ldr r4, [sp, #0x34]
 *   @0x17c040 vmov s16, r1
 *   @0x17c044 vmov s17, r2
 *   @0x17c048 ldr r7, [sp, #0x38]
 *   @0x17c04c vmov s18, r3
 *   @0x17c050 ldr r5, [sp, #0x30]
 *   @0x17c054 mov r0, r4
 *   @0x17c058 movw r6, #0x3333
 *   @0x17c05c bl 0xb6538 <strlen@plt>
 *   @0x17c060 ldr r3, [pc, #0x1e8]
 *   @0x17c064 mov r2, #24
 *   @0x17c068 movt r6, #0x3f33
 *   @0x17c06c ldr r3, [pc, r3]
 *   @0x17c070 ldr r1, [r3]
 *   @0x17c074 cmp r0, r7
 *   @0x17c078 movlt r3, r0
 *   @0x17c07c movge r3, r7
 *   @0x17c080 mov r0, #4
 *   @0x17c084 add r3, r3, r3, lsl #1
 *   @0x17c088 lsl r3, r3, #1
 *   @0x17c08c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x17c090 vcvt.s32.f32 s12, s16
 *   @0x17c094 mov r12, #0
 *   @0x17c098 vldr s8, [pc, #412]
 *   @0x17c09c mov r9, r12
 *   @0x17c0a0 vldr s9, [pc, #408]
 *   @0x17c0a4 vldr s5, [pc, #408]
 *   @0x17c0a8 vldr s6, [pc, #408]
 *   @0x17c0ac vldr s7, [pc, #408]
 *   @0x17c0b0 vcvt.s32.f32 s15, s19
 *   @0x17c0b4 vcvt.f32.s32 s12, s12
 *   @0x17c0b8 vcvt.f32.s32 s16, s15
 *   @0x17c0bc b 0x17c1d4 <_ZN12GraphicsPerf5PrintEffffjPci+0x1a4>
 *   @0x17c0c0 cmp r2, #104
 *   @0x17c0c4 ldr r1, [pc, r1]
 *   @0x17c0c8 add r3, r1, r2, lsl #2
 *   @0x17c0cc movgt r12, #0
 *   @0x17c0d0 movle r12, #1
 *   @0x17c0d4 cmp r2, #0
 *   @0x17c0d8 moveq r12, #0
 *   @0x17c0dc cmp r12, #0
 *   @0x17c0e0 ldrb r12, [r3, #0x2]
 *   @0x17c0e4 addeq r9, r9, #6
 *   @0x17c0e8 vmov s13, r12
 *   @0x17c0ec vcvt.f32.u32 s13, s13
 *   @0x17c0f0 vmul.f32 s11, s13, s17
 *   @0x17c0f4 vaddeq.f32 s16, s16, s11
 *   @0x17c0f8 beq 0x17c1d0 <_ZN12GraphicsPerf5PrintEffffjPci+0x1a0>
 *   @0x17c0fc ldrb r1, [r1, r2, lsl #2]
 *   @0x17c100 add r0, r0, #144
 *   @0x17c104 ldrb r2, [r3, #0x1]
 *   @0x17c108 ldrb r3, [r3, #0x3]
 *   @0x17c10c vstr s16, [r0, #-144]
 *   @0x17c110 vmov s14, r1
 *   @0x17c114 vstr s16, [r0, #-48]
 *   @0x17c118 vmov s15, r2
 *   @0x17c11c vstr s16, [r0, #-24]
 *   @0x17c120 vmov s10, r3
 *   @0x17c124 vstr s12, [r0, #-140]
 *   @0x17c128 vstr s12, [r0, #-116]
 *   @0x17c12c vstr s12, [r0, #-20]
 *   @0x17c130 str r6, [r0, #-0x10]
 *   @0x17c134 vcvt.f32.u32 s14, s14
 *   @0x17c138 str r6, [r0, #-0x28]
 *   @0x17c13c str r6, [r0, #-0x40]
 *   @0x17c140 str r6, [r0, #-0x58]
 *   @0x17c144 str r6, [r0, #-0x70]
 *   @0x17c148 str r6, [r0, #-0x88]
 *   @0x17c14c vmul.f32 s14, s14, s8
 *   @0x17c150 vstr s14, [r0, #-128]
 *   @0x17c154 vstr s14, [r0, #-32]
 *   @0x17c158 vstr s14, [r0, #-8]
 *   @0x17c15c vmla.f32 s14, s13, s8
 *   @0x17c160 vcvt.f32.u32 s15, s15
 *   @0x17c164 vstr s14, [r0, #-104]
 *   @0x17c168 vstr s14, [r0, #-80]
 *   @0x17c16c vstr s14, [r0, #-56]
 *   @0x17c170 vmul.f32 s15, s15, s9
 *   @0x17c174 vcvt.f32.u32 s10, s10
 *   @0x17c178 vstr s15, [r0, #-124]
 *   @0x17c17c vstr s15, [r0, #-100]
 *   @0x17c180 vstr s15, [r0, #-4]
 *   @0x17c184 vmov.f32 s14, s12
 *   @0x17c188 vmla.f32 s15, s10, s9
 *   @0x17c18c vmla.f32 s14, s10, s18
 *   @0x17c190 vstr s15, [r0, #-76]
 *   @0x17c194 vstr s15, [r0, #-52]
 *   @0x17c198 vstr s15, [r0, #-28]
 *   @0x17c19c vadd.f32 s16, s16, s11
 *   @0x17c1a0 vstr s14, [r0, #-92]
 *   @0x17c1a4 vstr s14, [r0, #-68]
 *   @0x17c1a8 vstr s14, [r0, #-44]
 *   @0x17c1ac vstr s16, [r0, #-120]
 *   @0x17c1b0 vstr s16, [r0, #-96]
 *   @0x17c1b4 vstr s16, [r0, #-72]
 *   @0x17c1b8 str r5, [r0, #-0xc]
 *   @0x17c1bc str r5, [r0, #-0x24]
 *   @0x17c1c0 str r5, [r0, #-0x3c]
 *   @0x17c1c4 str r5, [r0, #-0x54]
 *   @0x17c1c8 str r5, [r0, #-0x6c]
 *   @0x17c1cc str r5, [r0, #-0x84]
 *   @0x17c1d0 mov r12, r8
 *   @0x17c1d4 ldrb r3, [r4], #1
 *   @0x17c1d8 add r8, r12, #1
 *   @0x17c1dc ldr r1, [pc, #0x70]
 *   @0x17c1e0 cmp r3, #0
 *   @0x17c1e4 sub r2, r3, #32
 *   @0x17c1e8 beq 0x17c218 <_ZN12GraphicsPerf5PrintEffffjPci+0x1e8>
 *   @0x17c1ec cmp r7, r12
 *   @0x17c1f0 ble 0x17c218 <_ZN12GraphicsPerf5PrintEffffjPci+0x1e8>
 *   @0x17c1f4 cmp r3, #9
 *   @0x17c1f8 bne 0x17c0c0 <_ZN12GraphicsPerf5PrintEffffjPci+0x90>
 *   @0x17c1fc vadd.f32 s16, s16, s5
 *   @0x17c200 add r9, r9, #6
 *   @0x17c204 vmul.f32 s16, s16, s6
 *   @0x17c208 vcvt.s32.f32 s16, s16
 *   @0x17c20c vcvt.f32.s32 s16, s16
 *   @0x17c210 vmul.f32 s16, s16, s7
 *   @0x17c214 b 0x17c1d0 <_ZN12GraphicsPerf5PrintEffffjPci+0x1a0>
 *   @0x17c218 cmp r9, #0
 *   @0x17c21c beq 0x17c228 <_ZN12GraphicsPerf5PrintEffffjPci+0x1f8>
 *   @0x17c220 mov r0, r9
 *   @0x17c224 bl 0x185600 <_ZN8Graphics9FreeVertsEi>
 *   @0x17c228 vsub.f32 s16, s16, s19
 *   @0x17c22c vcvt.s32.f32 s16, s16
 *   @0x17c230 vmov r0, s16
 *   @0x17c234 vpop {d8, d9}
 *   @0x17c238 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x17c23c bllo 0xfe17c244 <b2_toiTime+0xfffffffffda22da0>
 *   @0x17c240 .word 0x3c000000
 *   @0x17c244 rsbsmi r0, r12, #0
 *   @0x17c248 stclo p0, c0, [r0], {0}
 *   @0x17c24c addmi r0, r0, #0
 *   @0x17c250 eoreq r4, r7, r12, lsr #4
 *   @0x17c254 .word 0x002741d8
 *
 * ══ §5/57 TBitmap::ReadDIB(CStream*, int)  0x1a8de4  size 552  138 条（0x1a8de4..0x1a900c）
 * @func 0x1a8de4 0x1a900c  size 552  138 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::GetSize()×3 / CStream::ReadBuffer(void*, int)×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / CStream::Seek(int, short) / TBitmap::Setup() / TBitmap::ReadDIB(CStream*, int)+0xf8 / TBitmap::ReadDIB(CStream*, int)+0xe8 / TBitmap::ReadDIB(CStream*, int)+0xb0
 * 字段偏移 top8: 0x4×7 / 0x1c×5 / 0xc×4 / 0x18×3 / 0x10×2 / 0x20×2 / 0x14×2 / 0x-c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8de4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a8de8 mov r5, r0
 *   @0x1a8dec mov r0, r1
 *   @0x1a8df0 mov r4, r1
 *   @0x1a8df4 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x1a8df8 ldr r1, [pc, #0x204]
 *   @0x1a8dfc mov r2, #129
 *   @0x1a8e00 mov r3, #1
 *   @0x1a8e04 add r1, pc, r1
 *   @0x1a8e08 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1a8e0c str r0, [r5, #0x4]
 *   @0x1a8e10 mov r0, r4
 *   @0x1a8e14 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x1a8e18 mov r1, #0
 *   @0x1a8e1c mov r2, r1
 *   @0x1a8e20 sub r3, r0, #2
 *   @0x1a8e24 mov r0, r4
 *   @0x1a8e28 str r3, [r5, #0x10]
 *   @0x1a8e2c bl 0x201284 <_ZN7CStream4SeekEis>
 *   @0x1a8e30 ldr r1, [r5, #0x4]
 *   @0x1a8e34 mov r2, #2
 *   @0x1a8e38 mov r0, r4
 *   @0x1a8e3c bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *   @0x1a8e40 mov r0, r4
 *   @0x1a8e44 ldr r6, [r5, #0x4]
 *   @0x1a8e48 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x1a8e4c mov r1, r6
 *   @0x1a8e50 sub r2, r0, #2
 *   @0x1a8e54 mov r0, r4
 *   @0x1a8e58 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *   @0x1a8e5c mov r0, r5
 *   @0x1a8e60 bl 0x1a8d14 <_ZN7TBitmap5SetupEv>
 *   @0x1a8e64 ldr r3, [r5, #0x20]
 *   @0x1a8e68 ldr r2, [r5, #0x1c]
 *   @0x1a8e6c mov r0, r4
 *   @0x1a8e70 ldr r1, [r5, #0xc]
 *   @0x1a8e74 mul r2, r2, r3
 *   @0x1a8e78 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *   @0x1a8e7c ldr r0, [r5, #0x1c]
 *   @0x1a8e80 sub r0, r0, #1
 *   @0x1a8e84 cmp r0, #0
 *   @0x1a8e88 ldrgt r2, [r5, #0x20]
 *   @0x1a8e8c movgt r6, #0
 *   @0x1a8e90 ble 0x1a8edc <_ZN7TBitmap7ReadDIBEP7CStreami+0xf8>
 *   @0x1a8e94 ldr r12, [r5, #0xc]
 *   @0x1a8e98 cmp r2, #0
 *   @0x1a8e9c movgt r3, #0
 *   @0x1a8ea0 mla r1, r6, r2, r12
 *   @0x1a8ea4 mla r12, r2, r0, r12
 *   @0x1a8ea8 ble 0x1a8ecc <_ZN7TBitmap7ReadDIBEP7CStreami+0xe8>
 *   @0x1a8eac ldrb r2, [r1, r3]
 *   @0x1a8eb0 ldrb r4, [r12, r3]
 *   @0x1a8eb4 strb r4, [r1, r3]
 *   @0x1a8eb8 strb r2, [r12, r3]
 *   @0x1a8ebc add r3, r3, #1
 *   @0x1a8ec0 ldr r2, [r5, #0x20]
 *   @0x1a8ec4 cmp r2, r3
 *   @0x1a8ec8 bgt 0x1a8eac <_ZN7TBitmap7ReadDIBEP7CStreami+0xc8>
 *   @0x1a8ecc add r6, r6, #1
 *   @0x1a8ed0 sub r0, r0, #1
 *   @0x1a8ed4 cmp r6, r0
 *   @0x1a8ed8 blt 0x1a8e94 <_ZN7TBitmap7ReadDIBEP7CStreami+0xb0>
 *   @0x1a8edc ldr r3, [r5, #0x14]
 *   @0x1a8ee0 cmp r3, #3
 *   @0x1a8ee4 popne {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a8ee8 ldr r0, [r5, #0x18]
 *   @0x1a8eec mov r2, #158
 *   @0x1a8ef0 ldr r12, [r5, #0x1c]
 *   @0x1a8ef4 mov r3, #1
 *   @0x1a8ef8 ldr r1, [pc, #0x108]
 *   @0x1a8efc mul r0, r12, r0
 *   @0x1a8f00 add r1, pc, r1
 *   @0x1a8f04 lsl r0, r0, #2
 *   @0x1a8f08 add r0, r0, #52
 *   @0x1a8f0c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1a8f10 ldr r3, [r5, #0x4]
 *   @0x1a8f14 add r1, r3, #48
 *   @0x1a8f18 mov r8, r0
 *   @0x1a8f1c mov r2, r0
 *   @0x1a8f20 ldr r4, [r3]
 *   @0x1a8f24 add r3, r3, #16
 *   @0x1a8f28 ldr lr, [r3, #-0xc]
 *   @0x1a8f2c add r2, r2, #16
 *   @0x1a8f30 ldr r12, [r3, #-0x8]
 *   @0x1a8f34 ldr r0, [r3, #-0x4]
 *   @0x1a8f38 cmp r3, r1
 *   @0x1a8f3c str r4, [r2, #-0x10]
 *   @0x1a8f40 str lr, [r2, #-0xc]
 *   @0x1a8f44 str r12, [r2, #-0x8]
 *   @0x1a8f48 str r0, [r2, #-0x4]
 *   @0x1a8f4c bne 0x1a8f20 <_ZN7TBitmap7ReadDIBEP7CStreami+0x13c>
 *   @0x1a8f50 ldr r0, [r3]
 *   @0x1a8f54 mov r1, #32
 *   @0x1a8f58 mov r3, #52
 *   @0x1a8f5c add r9, r8, r3
 *   @0x1a8f60 str r0, [r2]
 *   @0x1a8f64 ldr r2, [r5, #0x18]
 *   @0x1a8f68 ldr r6, [r5, #0x1c]
 *   @0x1a8f6c ldr r0, [r5, #0x4]
 *   @0x1a8f70 strh r1, [r8, #26]
 *   @0x1a8f74 mul r6, r6, r2
 *   @0x1a8f78 add r12, r0, r3
 *   @0x1a8f7c str r3, [r8, #0x8]
 *   @0x1a8f80 cmp r6, #0
 *   @0x1a8f84 ble 0x1a8fd4 <_ZN7TBitmap7ReadDIBEP7CStreami+0x1f0>
 *   @0x1a8f88 ldr r2, [r5, #0xc]
 *   @0x1a8f8c add lr, r8, #48
 *   @0x1a8f90 mov r1, #3
 *   @0x1a8f94 mov r7, #1
 *   @0x1a8f98 add r6, r2, r6
 *   @0x1a8f9c mov r4, #2
 *   @0x1a8fa0 ldrb r3, [r2], #1
 *   @0x1a8fa4 cmp r2, r6
 *   @0x1a8fa8 smlabb r11, r1, r3, r7
 *   @0x1a8fac smlabb r10, r1, r3, r4
 *   @0x1a8fb0 smulbb r3, r3, r1
 *   @0x1a8fb4 ldrb r11, [r12, r11]
 *   @0x1a8fb8 ldrb r10, [r12, r10]
 *   @0x1a8fbc ldrb r3, [r12, r3]
 *   @0x1a8fc0 orr r10, r11, r10
 *   @0x1a8fc4 orr r3, r10, r3
 *   @0x1a8fc8 orr r3, r3, #-16777216
 *   @0x1a8fcc str r3, [lr, #0x4]!
 *   @0x1a8fd0 bne 0x1a8fa0 <_ZN7TBitmap7ReadDIBEP7CStreami+0x1bc>
 *   @0x1a8fd4 str r9, [r5, #0xc]
 *   @0x1a8fd8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a8fdc ldr r3, [r5, #0x18]
 *   @0x1a8fe0 ldr r2, [r5, #0x1c]
 *   @0x1a8fe4 mov r1, #7
 *   @0x1a8fe8 str r8, [r5, #0x4]
 *   @0x1a8fec str r1, [r5, #0x14]
 *   @0x1a8ff0 mul r3, r2, r3
 *   @0x1a8ff4 lsl r3, r3, #2
 *   @0x1a8ff8 add r3, r3, #52
 *   @0x1a8ffc str r3, [r5, #0x10]
 *   @0x1a9000 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a9004 andseq r4, r10, r0, ror r3
 *   @0x1a9008 andseq r4, r10, r4, ror r2
 *
 * ══ §6/57 CDS_List::Add(RValue*)  0x205d18  size 552  138 条（0x205d18..0x205f40）
 * @func 0x205d18 0x205f40  size 552  138 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / CDS_List::Add(RValue*)+0x4c / MemoryManager::SetLength(void**, unsigned int, char const*, int) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x4×9 / 0x8×7 / 0xc×6 / 0x200×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x205d18 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x205d1c mov r5, r1
 *   @0x205d20 ldmib r0, {r1, r6}
 *   @0x205d24 mov r4, r0
 *   @0x205d28 cmp r1, r6
 *   @0x205d2c blt 0x205d64 <_ZN8CDS_List3AddEP6RValue+0x4c>
 *   @0x205d30 asr r6, r6, #3
 *   @0x205d34 ldr r2, [pc, #0x200]
 *   @0x205d38 cmp r6, #16
 *   @0x205d3c movlt r6, #16
 *   @0x205d40 add r0, r0, #12
 *   @0x205d44 add r1, r6, r1
 *   @0x205d48 add r2, pc, r2
 *   @0x205d4c movw r3, #0x4ef
 *   @0x205d50 lsl r1, r1, #4
 *   @0x205d54 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x205d58 ldr r1, [r4, #0x4]
 *   @0x205d5c add r6, r1, r6
 *   @0x205d60 str r6, [r4, #0x8]
 *   @0x205d64 ldr r7, [r4, #0xc]
 *   @0x205d68 lsl r8, r1, #4
 *   @0x205d6c add r6, r7, r8
 *   @0x205d70 ldr r2, [r6, #0xc]
 *   @0x205d74 bic r3, r2, #-16777216
 *   @0x205d78 cmp r3, #1
 *   @0x205d7c beq 0x205e3c <_ZN8CDS_List3AddEP6RValue+0x124>
 *   @0x205d80 cmp r3, #2
 *   @0x205d84 bne 0x205dac <_ZN8CDS_List3AddEP6RValue+0x94>
 *   @0x205d88 sub r2, r2, #1
 *   @0x205d8c bic r2, r2, #-16777216
 *   @0x205d90 bic r2, r2, #3
 *   @0x205d94 cmp r2, #0
 *   @0x205d98 beq 0x205f30 <_ZN8CDS_List3AddEP6RValue+0x218>
 *   @0x205d9c mov r2, #0
 *   @0x205da0 mov r3, #5
 *   @0x205da4 str r2, [r6, #0x8]
 *   @0x205da8 str r3, [r6, #0xc]
 *   @0x205dac ldr r3, [r5, #0xc]
 *   @0x205db0 mov r1, #0
 *   @0x205db4 ldr r2, [r5, #0x8]
 *   @0x205db8 str r1, [r7, r8]
 *   @0x205dbc str r3, [r6, #0xc]
 *   @0x205dc0 ldr r3, [r5, #0xc]
 *   @0x205dc4 str r2, [r6, #0x8]
 *   @0x205dc8 bic r3, r3, #-16777216
 *   @0x205dcc cmp r3, #14
 *   @0x205dd0 addls pc, pc, r3, lsl #2
 *   @0x205dd4 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104>
 *   @0x205dd8 b 0x205e2c <_ZN8CDS_List3AddEP6RValue+0x114>
 *   @0x205ddc b 0x205e94 <_ZN8CDS_List3AddEP6RValue+0x17c>
 *   @0x205de0 b 0x205eac <_ZN8CDS_List3AddEP6RValue+0x194>
 *   @0x205de4 b 0x205e14 <_ZN8CDS_List3AddEP6RValue+0xfc>
 *   @0x205de8 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104>
 *   @0x205dec b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104>
 *   @0x205df0 b 0x205e70 <_ZN8CDS_List3AddEP6RValue+0x158>
 *   @0x205df4 b 0x205e14 <_ZN8CDS_List3AddEP6RValue+0xfc>
 *   @0x205df8 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104>
 *   @0x205dfc b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104>
 *   @0x205e00 b 0x205e2c <_ZN8CDS_List3AddEP6RValue+0x114>
 *   @0x205e04 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104>
 *   @0x205e08 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104>
 *   @0x205e0c b 0x205e2c <_ZN8CDS_List3AddEP6RValue+0x114>
 *   @0x205e10 b 0x205e14 <_ZN8CDS_List3AddEP6RValue+0xfc>
 *   @0x205e14 ldr r3, [r5]
 *   @0x205e18 str r3, [r7, r8]
 *   @0x205e1c ldr r3, [r4, #0x4]
 *   @0x205e20 add r3, r3, #1
 *   @0x205e24 str r3, [r4, #0x4]
 *   @0x205e28 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x205e2c ldm r5, {r2, r3}
 *   @0x205e30 str r2, [r7, r8]
 *   @0x205e34 str r3, [r6, #0x4]
 *   @0x205e38 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104>
 *   @0x205e3c ldr r9, [r7, r1, lsl #4]
 *   @0x205e40 cmp r9, #0
 *   @0x205e44 beq 0x205e64 <_ZN8CDS_List3AddEP6RValue+0x14c>
 *   @0x205e48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x205e4c ldr r10, [r9, #0x4]
 *   @0x205e50 sub r10, r10, #1
 *   @0x205e54 str r10, [r9, #0x4]
 *   @0x205e58 cmp r10, #0
 *   @0x205e5c beq 0x205ed8 <_ZN8CDS_List3AddEP6RValue+0x1c0>
 *   @0x205e60 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x205e64 mov r3, #0
 *   @0x205e68 str r3, [r7, r8]
 *   @0x205e6c b 0x205dac <_ZN8CDS_List3AddEP6RValue+0x94>
 *   @0x205e70 ldr r3, [r5]
 *   @0x205e74 str r3, [r7, r8]
 *   @0x205e78 ldr r3, [r5]
 *   @0x205e7c cmp r3, #0
 *   @0x205e80 beq 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104>
 *   @0x205e84 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x205e88 ldr r1, [r5]
 *   @0x205e8c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x205e90 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104>
 *   @0x205e94 ldr r3, [r5]
 *   @0x205e98 cmp r3, #0
 *   @0x205e9c ldrne r2, [r3, #0x4]
 *   @0x205ea0 addne r2, r2, #1
 *   @0x205ea4 strne r2, [r3, #0x4]
 *   @0x205ea8 b 0x205e18 <_ZN8CDS_List3AddEP6RValue+0x100>
 *   @0x205eac ldr r3, [r5]
 *   @0x205eb0 cmp r3, #0
 *   @0x205eb4 str r3, [r7, r8]
 *   @0x205eb8 beq 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104>
 *   @0x205ebc ldr r1, [r3, #0x8]
 *   @0x205ec0 ldr r2, [r3]
 *   @0x205ec4 cmp r1, #0
 *   @0x205ec8 streq r6, [r3, #0x8]
 *   @0x205ecc add r2, r2, #1
 *   @0x205ed0 str r2, [r3]
 *   @0x205ed4 b 0x205e1c <_ZN8CDS_List3AddEP6RValue+0x104>
 *   @0x205ed8 ldr r0, [r9]
 *   @0x205edc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x205ee0 str r10, [r9]
 *   @0x205ee4 str r10, [r9, #0x8]
 *   @0x205ee8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x205eec ldr r10, [r9, #0x4]
 *   @0x205ef0 sub r10, r10, #1
 *   @0x205ef4 str r10, [r9, #0x4]
 *   @0x205ef8 cmp r10, #0
 *   @0x205efc bne 0x205f20 <_ZN8CDS_List3AddEP6RValue+0x208>
 *   @0x205f00 ldr r0, [r9]
 *   @0x205f04 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x205f08 mov r0, r9
 *   @0x205f0c str r10, [r9]
 *   @0x205f10 str r10, [r9, #0x8]
 *   @0x205f14 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x205f18 mov r0, r9
 *   @0x205f1c bl 0x27d1d0 <_ZdlPv>
 *   @0x205f20 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x205f24 mov r0, r9
 *   @0x205f28 bl 0x27d1d0 <_ZdlPv>
 *   @0x205f2c b 0x205e60 <_ZN8CDS_List3AddEP6RValue+0x148>
 *   @0x205f30 mov r0, r6
 *   @0x205f34 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x205f38 b 0x205d9c <_ZN8CDS_List3AddEP6RValue+0x84>
 *   @0x205f3c andseq sp, r4, r4, lsr #21
 *
 * ══ §7/57 png_handle_pCAL  0x2ad128  size 552  138 条（0x2ad128..0x2ad350）
 * @func 0x2ad128 0x2ad350  size 552  138 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_free×2 / png_error / png_crc_read / png_crc_finish / png_handle_pCAL+0xa6 / 0x5addf8 / png_warning / 0x4ac78c
 * 字段偏移 top8: 0x20×3 / 0x1ec×1 / 0x1a4×1 / 0x4×1 / 0x5×1 / 0x7×1 / 0xa×1 / 0xc0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ad128 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ad12c mov r8, r1
 *   @0x2ad130 addlt r3, r11, r12, lsr #2
 *   @0x2ad134 mov r4, r0
 *   @0x2ad138 lsls r1, r3, #0x1f
 *   @0x2ad13c ldr r1, [pc, #0x1ec]
 *   @0x2ad140 bl 0x2a642c <png_error>
 *   @0x2ad144 b 0x2ad174 <png_handle_pCAL+0x4c>
 *   @0x2ad148 bpl 0x2ad150 <png_handle_pCAL+0x28>
 *   @0x2ad14c add r1, pc
 *   @0x2ad150 cmp.w r8, #0x0
 *   @0x2ad154 beq 0x2ad174 <png_handle_pCAL+0x4c>
 *   @0x2ad158 ldrbeq r3, [r11, #-0x8]
 *   @0x2ad15c bpl 0x2ad174 <png_handle_pCAL+0x4c>
 *   @0x2ad160 add r1, pc
 *   @0x2ad164 strtmi pc, [r0], -r7, lsl #19
 *   @0x2ad168 mov r1, r6
 *   @0x2ad16c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ad170 b.w 0x2abc94 <png_crc_finish>
 *   @0x2ad174 mov r0, r4
 *   @0x2ad178 .word 0xf7f91330
 *   @0x2ad17c ldclne p13, c15, [r1], #-764
 *   @0x2ad180 mov r0, r4
 *   @0x2ad184 strmi pc, [r1], -r8, asr #27
 *   @0x2ad188 str.w r0, [r4, #0x330]
 *   @0x2ad18c mov r0, r4
 *   @0x2ad190 ldr r1, [pc, #0x1a4]
 *   @0x2ad194 b 0x2ad2c2 <png_handle_pCAL+0x19a>
 *   @0x2ad198 bl 0x2abc0c <png_crc_read>
 *   @0x2ad19c mov r0, r4
 *   @0x2ad1a0 bl 0x2abc94 <png_crc_finish>
 *   @0x2ad1a4 cmp r0, #0x0
 *   @0x2ad1a8 ldr.w r3, [r4, #0x330]
 *   @0x2ad1ac strb r0, [r3, r6]
 *   @0x2ad1b0 sasxmi r3, r10, r0
 *   @0x2ad1b4 mov r5, r2
 *   @0x2ad1b8 ldrb r1, [r5]
 *   @0x2ad1bc bne 0x2ad1b4 <png_handle_pCAL+0x8c>
 *   @0x2ad1c0 add.w r10, r3, r6
 *   @0x2ad1c4 bls 0x2ad1ce <png_handle_pCAL+0xa6>
 *   @0x2ad1c8 blhs 0x5addf8 <g_SWFlineaavertbuff+0x5ad30>
 *   @0x2ad1cc bgt 0x2ad1d6 <png_handle_pCAL+0xae>
 *   @0x2ad1d0 mov r0, r4
 *   @0x2ad1d4 b 0x2ad264 <png_handle_pCAL+0x13c>
 *   @0x2ad1d8 ldrb.w r9, [r5, #0x2]
 *   @0x2ad1dc tst.w r1, #0x80
 *   @0x2ad1e0 ldrb r2, [r5, #0x4]
 *   @0x2ad1e4 stmvc r11!, {r0, r8, sp, lr} ^
 *   @0x2ad1e8 add.w r9, r1, r9, lsl #16
 *   @0x2ad1ec add r9, r2
 *   @0x2ad1f0 andle r2, r5, r3, lsl #18
 *   @0x2ad1f4 rsb.w r9, r9, #0x0
 *   @0x2ad1f8 bic r9, r9, #0x80000000
 *   @0x2ad1fc rsb.w r9, r9, #0x0
 *   @0x2ad200 ldrb r1, [r5, #0x5]
 *   @0x2ad204 .word 0xf011b006
 *   @0x2ad208 bvc 0xd31010 <b2_toiTime+0x5d7b6c>
 *   @0x2ad20c lsl.w r1, r1, #0x18
 *   @0x2ad210 ldrb r3, [r5, #0x7]
 *   @0x2ad214 ldrmi r4, [r3], #2827
 *   @0x2ad218 beq 0x2ad22e <png_handle_pCAL+0x106>
 *   @0x2ad21c .word 0xf1cb2b03
 *   @0x2ad220 .word 0xf02b0b00
 *   @0x2ad224 .word 0xf1cb4b00
 *   @0x2ad228 andls r0, r9, #0, #4
 *   @0x2ad22c b 0x2ad234 <png_handle_pCAL+0x10c>
 *   @0x2ad230 movwls r2, #0x9303
 *   @0x2ad234 ldrb.w r11, [r5, #0x9]
 *   @0x2ad238 ldrb r6, [r5, #0xa]
 *   @0x2ad23c .word 0xd1010f00
 *   @0x2ad240 cmp r6, #0x2
 *   @0x2ad244 cmp.w r11, #0x1
 *   @0x2ad248 beq 0x2ad250 <png_handle_pCAL+0x128>
 *   @0x2ad24c .word 0xd1010f02
 *   @0x2ad250 cmp r6, #0x3
 *   @0x2ad254 cmp.w r11, #0x3
 *   @0x2ad258 bne 0x2ad27e <png_handle_pCAL+0x156>
 *   @0x2ad25c beq 0x2ad28a <png_handle_pCAL+0x162>
 *   @0x2ad260 mov r0, r4
 *   @0x2ad264 bl 0x2a6474 <png_warning>
 *   @0x2ad268 mov r0, r4
 *   @0x2ad26c .word 0xf7f91330
 *   @0x2ad270 movwhs pc, #0xd45
 *   @0x2ad274 str.w r3, [r4, #0x330]
 *   @0x2ad278 add sp, #0x2c
 *   @0x2ad27c stmdble r4, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ad280 ldr r1, [pc, #0xc0]
 *   @0x2ad284 add r1, pc
 *   @0x2ad288 .word 0xf105f8f5
 *   @0x2ad28c ldrmi r0, [r9], -r11, lsl #6
 *   @0x2ad290 mov r5, r1
 *   @0x2ad294 ldrb r2, [r5]
 *   @0x2ad298 bne 0x2ad290 <png_handle_pCAL+0x168>
 *   @0x2ad29c lsls r1, r6, #0x2
 *   @0x2ad2a0 str r3, [sp, #0x20]
 *   @0x2ad2a4 bls 0x4ac78c <SrcVerts+0x97d0>
 *   @0x2ad2a8 ldr r3, [sp, #0x20]
 *   @0x2ad2ac cbnz r0, 0x2ad2dc <png_handle_pCAL+0x1b4>
 *   @0x2ad2b0 ldr.w r1, [r4, #0x330]
 *   @0x2ad2b4 bl 0x2a6cfc <png_free>
 *   @0x2ad2b8 ldr r1, [pc, #0x8c]
 *   @0x2ad2bc str.w r7, [r4, #0x330]
 *   @0x2ad2c0 add r1, pc
 *   @0x2ad2c4 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ad2c8 b.w 0x2a6474 <png_warning>
 *   @0x2ad2cc cmp r1, r10
 *   @0x2ad2d0 bhi 0x2ad304 <png_handle_pCAL+0x1dc>
 *   @0x2ad2d4 adds r1, #0x1
 *   @0x2ad2d8 bne 0x2ad2cc <png_handle_pCAL+0x1a4>
 *   @0x2ad2dc cmp r2, r6
 *   @0x2ad2e0 adds r1, r5, #0x1
 *   @0x2ad2e4 ldrb r1, [r1, r2, lsr #32]!
 *   @0x2ad2e8 ldr r2, [sp, #0x24]
 *   @0x2ad2ec str r3, [sp, #0xc]
 *   @0x2ad2f0 str r6, [sp, #0x8]
 *   @0x2ad2f4 stm.w sp, {r2, r11}
 *   @0x2ad2f8 str r7, [sp, #0x10]
 *   @0x2ad2fc .word 0xf0012330
 *   @0x2ad300 and pc, r4, r1, lsl r12
 *   @0x2ad304 ldr r1, [pc, #0x44]
 *   @0x2ad308 add r1, pc
 *   @0x2ad30c .word 0x4620f8b3
 *   @0x2ad310 ldr.w r1, [r4, #0x330]
 *   @0x2ad314 bl 0x2a6cfc <png_free>
 *   @0x2ad318 movs r3, #0x0
 *   @0x2ad31c str.w r3, [r4, #0x330]
 *   @0x2ad320 mov r1, r7
 *   @0x2ad324 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ad328 b.w 0x2a6cfc <png_free>
 *   @0x2ad32c lsls r3, r1, #0xf
 *   @0x2ad330 lsls r6, r2, #0xf
 *   @0x2ad334 lsls r2, r3, #0xf
 *   @0x2ad338 lsls r5, r7, #0xe
 *   @0x2ad33c lsls r0, r3, #0xe
 *   @0x2ad340 lsls r2, r3, #0xc
 *   @0x2ad344 lsls r2, r4, #0xc
 *   @0x2ad348 lsls r0, r2, #0xc
 *   @0x2ad34c lsls r2, r4, #0x9
 *
 * ══ §8/57 YYCreateString(RValue*, _RefThing<char const*>*)  0xe7dac  size 548  129 条（0xe7dac..0xe7fd0）｜其中 8 条已由别的卡落锚，本节不再重复
 * @func 0xe7dac 0xe7fd0  size 548  129 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / UNLOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / YYFree(void const*)×2 / operator delete(void*)×2 / operator new(unsigned int) / YYCreateString(RValue*, _RefThing<char const*>*)+0x140 / YYCreateString(RValue*, _RefThing<char const*>*)+0x1d8
 * 字段偏移 top8: 0x4×14 / 0x8×6 / 0xc×4 / 0x10×3 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xe7dcc beq 0xe7e04 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x58>
 *   @0xe7dd0 mov r3, #0
 *   @0xe7dd4 mov r2, #1
 *   @0xe7dd8 str r3, [r5, #0x8]
 *   @0xe7ddc mov r0, #12
 *   @0xe7de0 str r3, [r5]
 *   @0xe7de4 str r2, [r5, #0xc]
 *   @0xe7de8 bl 0x27c524 <_Znwj>
 *   @0xe7dec mov r3, r0
 *   @0xe7df0 ldm r7, {r0, r1, r2}
 *   @0xe7df4 stm r3, {r0, r1, r2}
 *   @0xe7df8 str r3, [r5]
 *   @0xe7dfc add sp, sp, #12
 *   @0xe7e00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xe7e04 bic r2, r2, #-16777216
 *   @0xe7e08 cmp r2, #2
 *   @0xe7e0c beq 0xe7e7c <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0xd0>
 *   @0xe7e10 cmp r2, #3
 *   @0xe7e14 beq 0xe7e54 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0xa8>
 *   @0xe7e18 cmp r2, #1
 *   @0xe7e1c bne 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24>
 *   @0xe7e20 ldr r4, [r0]
 *   @0xe7e24 cmp r4, #0
 *   @0xe7e28 beq 0xe7e48 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x9c>
 *   @0xe7e2c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xe7e30 ldr r6, [r4, #0x4]
 *   @0xe7e34 sub r6, r6, #1
 *   @0xe7e38 str r6, [r4, #0x4]
 *   @0xe7e3c cmp r6, #0
 *   @0xe7e40 beq 0xe7eb4 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x108>
 *   @0xe7e44 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xe7e48 mov r3, #0
 *   @0xe7e4c str r3, [r5]
 *   @0xe7e50 b 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24>
 *   @0xe7e54 ldr r3, [r0, #0x8]
 *   @0xe7e58 tst r3, #8
 *   @0xe7e5c beq 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24>
 *   @0xe7e60 ldr r0, [r0]
 *   @0xe7e64 cmp r0, #0
 *   @0xe7e68 beq 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24>
 *   @0xe7e6c ldr r3, [r0]
 *   @0xe7e70 ldr r3, [r3, #0x4]
 *   @0xe7e74 blx r3
 *   @0xe7e78 b 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24>
 *   @0xe7e7c ldr r9, [r0]
 *   @0xe7e80 cmp r9, #0
 *   @0xe7e84 beq 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24>
 *   @0xe7e88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xe7e8c ldr r3, [r9]
 *   @0xe7e90 ldr r2, [r9, #0x8]
 *   @0xe7e94 sub r3, r3, #1
 *   @0xe7e98 str r3, [r9]
 *   @0xe7e9c cmp r5, r2
 *   @0xe7ea0 streq r4, [r9, #0x8]
 *   @0xe7ea4 cmp r3, #0
 *   @0xe7ea8 ble 0xe7eec <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x140>
 *   @0xe7eac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xe7eb0 b 0xe7dd0 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x24>
 *   @0xe7eb4 ldr r0, [r4]
 *   @0xe7eb8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe7ebc str r6, [r4]
 *   @0xe7ec0 str r6, [r4, #0x8]
 *   @0xe7ec4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xe7ec8 ldr r6, [r4, #0x4]
 *   @0xe7ecc sub r6, r6, #1
 *   @0xe7ed0 str r6, [r4, #0x4]
 *   @0xe7ed4 cmp r6, #0
 *   @0xe7ed8 beq 0xe7fac <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x200>
 *   @0xe7edc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xe7ee0 mov r0, r4
 *   @0xe7ee4 bl 0x27d1d0 <_ZdlPv>
 *   @0xe7ee8 b 0xe7e44 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x98>
 *   @0xe7eec ldr r3, [r9, #0x10]
 *   @0xe7ef0 cmp r3, #0
 *   @0xe7ef4 movgt r8, #0
 *   @0xe7ef8 movgt r10, #5
 *   @0xe7efc movgt r6, r8
 *   @0xe7f00 ble 0xe7f84 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x1d8>
 *   @0xe7f04 ldr r3, [r9, #0x4]
 *   @0xe7f08 add r2, r3, r8, lsl #3
 *   @0xe7f0c str r2, [sp, #0x4]
 *   @0xe7f10 ldr r11, [r3, r8, lsl #3]
 *   @0xe7f14 ldr r4, [r2, #0x4]
 *   @0xe7f18 add r11, r4, r11, lsl #4
 *   @0xe7f1c cmp r4, r11
 *   @0xe7f20 blo 0xe7f3c <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x190>
 *   @0xe7f24 b 0xe7fa4 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x1f8>
 *   @0xe7f28 str r6, [r4, #0x8]
 *   @0xe7f2c str r10, [r4, #0xc]
 *   @0xe7f30 str r6, [r4], #16
 *   @0xe7f34 cmp r11, r4
 *   @0xe7f38 bls 0xe7f60 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x1b4>
 *   @0xe7f3c ldr r3, [r4, #0xc]
 *   @0xe7f40 sub r3, r3, #1
 *   @0xe7f44 bic r3, r3, #-16777216
 *   @0xe7f48 bic r3, r3, #3
 *   @0xe7f4c cmp r3, #0
 *   @0xe7f50 bne 0xe7f28 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x17c>
 *   @0xe7f54 mov r0, r4
 *   @0xe7f58 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xe7f5c b 0xe7f28 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x17c>
 *   @0xe7f60 ldr r3, [sp, #0x4]
 *   @0xe7f64 ldr r0, [r3, #0x4]
 *   @0xe7f68 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0xe7f6c ldr r3, [r9, #0x10]
 *   @0xe7f70 add r8, r8, #1
 *   @0xe7f74 ldr r2, [sp, #0x4]
 *   @0xe7f78 cmp r8, r3
 *   @0xe7f7c str r6, [r2, #0x4]
 *   @0xe7f80 blt 0xe7f04 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x158>
 *   @0xe7f84 ldr r0, [r9, #0x4]
 *   @0xe7f88 mov r4, #0
 *   @0xe7f8c bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0xe7f90 str r4, [r9, #0x4]
 *   @0xe7f94 mov r0, r9
 *   @0xe7f98 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0xe7f9c str r4, [r5]
 *   @0xe7fa0 b 0xe7eac <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x100>
 *   @0xe7fa4 mov r0, r4
 *   @0xe7fa8 b 0xe7f68 <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x1bc>
 *   @0xe7fac ldr r0, [r4]
 *   @0xe7fb0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe7fb4 mov r0, r4
 *   @0xe7fb8 str r6, [r4]
 *   @0xe7fbc str r6, [r4, #0x8]
 *   @0xe7fc0 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xe7fc4 mov r0, r4
 *   @0xe7fc8 bl 0x27d1d0 <_ZdlPv>
 *   @0xe7fcc b 0xe7edc <_Z14YYCreateStringP6RValueP9_RefThingIPKcE+0x130>
 *
 * ══ §9/57 CFontGM::LoadFromStream(CStream*)  0xf79a0  size 548  137 条（0xf79a0..0xf7bc4）
 * @func 0xf79a0 0xf7bc4  size 548  137 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×12 / CStream::ReadBoolean()×2 / CStream::ReadBuffer(void*, int)×2 / CFontGM::Clear() / MemoryManager::Free(void const*) / CStream::ReadString(char const*&) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x24×5 / 0x28×4 / 0x4×3 / 0x2c×2 / 0x18×2 / 0x40×2 / 0x34×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf79a0 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xf79a4 mov r5, r1
 *   @0xf79a8 mov r9, r0
 *   @0xf79ac bl 0xf70a0 <_ZN7CFontGM5ClearEv>
 *   @0xf79b0 mov r0, r5
 *   @0xf79b4 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf79b8 cmp r0, #800
 *   @0xf79bc cmpne r0, #540
 *   @0xf79c0 mov r8, r0
 *   @0xf79c4 moveq r4, #0
 *   @0xf79c8 movne r4, #1
 *   @0xf79cc bne 0xf7b70 <_ZN7CFontGM14LoadFromStreamEP7CStream+0x1d0>
 *   @0xf79d0 ldr r0, [r9, #0x4]
 *   @0xf79d4 cmp r0, #0
 *   @0xf79d8 beq 0xf79e4 <_ZN7CFontGM14LoadFromStreamEP7CStream+0x44>
 *   @0xf79dc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf79e0 str r4, [r9, #0x4]
 *   @0xf79e4 add r1, r9, #4
 *   @0xf79e8 mov r0, r5
 *   @0xf79ec bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0xf79f0 mov r0, r5
 *   @0xf79f4 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf79f8 mov r6, #0
 *   @0xf79fc str r0, [r9, #0x8]
 *   @0xf7a00 mov r0, r5
 *   @0xf7a04 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0xf7a08 strb r0, [r9, #0xc]
 *   @0xf7a0c mov r0, r5
 *   @0xf7a10 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0xf7a14 strb r0, [r9, #0xd]
 *   @0xf7a18 mov r0, r5
 *   @0xf7a1c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf7a20 str r6, [r9, #0x2c]
 *   @0xf7a24 ubfx r3, r0, #0x10, #0x8
 *   @0xf7a28 str r0, [r9, #0x18]
 *   @0xf7a2c cmp r3, #0
 *   @0xf7a30 strne r3, [r9, #0x10]
 *   @0xf7a34 lsrs r3, r0, #24
 *   @0xf7a38 uxth r0, r0
 *   @0xf7a3c subne r3, r3, #1
 *   @0xf7a40 str r0, [r9, #0x18]
 *   @0xf7a44 strne r3, [r9, #0x14]
 *   @0xf7a48 mov r0, r5
 *   @0xf7a4c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf7a50 ldr r1, [pc, #0x164]
 *   @0xf7a54 mov r3, #256
 *   @0xf7a58 movw r2, #0x29d
 *   @0xf7a5c str r3, [r9, #0x40]
 *   @0xf7a60 add r1, pc, r1
 *   @0xf7a64 mov r3, #1
 *   @0xf7a68 str r0, [r9, #0x1c]
 *   @0xf7a6c mov r0, #5120
 *   @0xf7a70 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf7a74 ldr r3, [r9, #0x40]
 *   @0xf7a78 sub r7, r0, #4
 *   @0xf7a7c str r0, [r9, #0x44]
 *   @0xf7a80 add r0, r0, r3, lsl #2
 *   @0xf7a84 add r4, r0, #16
 *   @0xf7a88 sub r3, r4, #16
 *   @0xf7a8c mov r0, r5
 *   @0xf7a90 str r3, [r7, #0x4]!
 *   @0xf7a94 add r4, r4, #16
 *   @0xf7a98 strh r6, [r4, #-32]
 *   @0xf7a9c add r6, r6, #1
 *   @0xf7aa0 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf7aa4 strh r0, [r4, #-30]
 *   @0xf7aa8 mov r0, r5
 *   @0xf7aac bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf7ab0 strh r0, [r4, #-28]
 *   @0xf7ab4 mov r0, r5
 *   @0xf7ab8 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf7abc strh r0, [r4, #-26]
 *   @0xf7ac0 mov r0, r5
 *   @0xf7ac4 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf7ac8 strh r0, [r4, #-24]
 *   @0xf7acc mov r0, r5
 *   @0xf7ad0 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf7ad4 strh r0, [r4, #-22]
 *   @0xf7ad8 mov r0, r5
 *   @0xf7adc bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf7ae0 ldrsh r3, [r4, #-24]
 *   @0xf7ae4 ldr r2, [r9, #0x2c]
 *   @0xf7ae8 cmp r2, r3
 *   @0xf7aec strh r0, [r4, #-20]
 *   @0xf7af0 strlt r3, [r9, #0x2c]
 *   @0xf7af4 cmp r6, #256
 *   @0xf7af8 bne 0xf7a88 <_ZN7CFontGM14LoadFromStreamEP7CStream+0xe8>
 *   @0xf7afc mov r0, r5
 *   @0xf7b00 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf7b04 str r0, [r9, #0x24]
 *   @0xf7b08 mov r0, r5
 *   @0xf7b0c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf7b10 ldr r12, [r9, #0x24]
 *   @0xf7b14 ldr r2, [pc, #0xa4]
 *   @0xf7b18 mov r3, #688
 *   @0xf7b1c add r2, pc, r2
 *   @0xf7b20 mov r1, r0
 *   @0xf7b24 add r0, r9, #52
 *   @0xf7b28 str r1, [r9, #0x28]
 *   @0xf7b2c mul r1, r12, r1
 *   @0xf7b30 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xf7b34 ldr r3, [r9, #0x24]
 *   @0xf7b38 ldr r2, [r9, #0x28]
 *   @0xf7b3c cmp r8, #540
 *   @0xf7b40 mov r0, r5
 *   @0xf7b44 mul r3, r2, r3
 *   @0xf7b48 str r3, [r9, #0x30]
 *   @0xf7b4c beq 0xf7b78 <_ZN7CFontGM14LoadFromStreamEP7CStream+0x1d8>
 *   @0xf7b50 bl 0x2019c4 <_ZN7CStream10ReadStreamEv>
 *   @0xf7b54 ldr r3, [r9, #0x24]
 *   @0xf7b58 ldr r2, [r9, #0x28]
 *   @0xf7b5c ldr r1, [r9, #0x34]
 *   @0xf7b60 mul r2, r2, r3
 *   @0xf7b64 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *   @0xf7b68 mov r0, #1
 *   @0xf7b6c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xf7b70 mov r0, #0
 *   @0xf7b74 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xf7b78 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv>
 *   @0xf7b7c ldr r3, [r9, #0x24]
 *   @0xf7b80 ldr r2, [r9, #0x28]
 *   @0xf7b84 ldr r1, [r9, #0x34]
 *   @0xf7b88 mul r2, r2, r3
 *   @0xf7b8c mov r4, r0
 *   @0xf7b90 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *   @0xf7b94 cmp r4, #0
 *   @0xf7b98 beq 0xf7bb4 <_ZN7CFontGM14LoadFromStreamEP7CStream+0x214>
 *   @0xf7b9c mov r0, r4
 *   @0xf7ba0 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0xf7ba4 mov r0, r4
 *   @0xf7ba8 bl 0x27d1d0 <_ZdlPv>
 *   @0xf7bac mov r0, #1
 *   @0xf7bb0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xf7bb4 mov r0, #1
 *   @0xf7bb8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xf7bbc eoreq pc, r3, r4, lsr #31
 *   @0xf7bc0 eoreq pc, r3, r8, ror #29
 *
 * ══ §10/57 F_GPUGetState(RValue&, CInstance*, CInstance*, int, RValue*)  0x1460b0  size 548  137 条（0x1460b0..0x1462d4）
 * @func 0x1460b0 0x1462d4  size 548  137 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x146120→0x3f21c4, 0x146124→0x4859c8, 0x1461b8→0x3f214c
 * 调用序列: YYStrDup(char const*)×4 / CDS_Map::Add(char const*, double, char const*)×4 / DS_AutoMutex::DS_AutoMutex() / CreateDsMap(int, ...) / GetDsMap(int) / RenderStateManager::GetRenderState(eRenderState) / 0xb65c8 / RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×4 / 0x10×3 / 0x-8×3 / 0x11c×2 / 0x19c×2 / 0x-4×2 / 0x8×2 / 0x1f8×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1460b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1460b4 vpush {d8}
 *   @0x1460b8 sub sp, sp, #292
 *   @0x1460bc ldr r4, [pc, #0x1f8]
 *   @0x1460c0 add r1, sp, #24
 *   @0x1460c4 ldr r2, [pc, #0x1f4]
 *   @0x1460c8 mov r3, #0
 *   @0x1460cc add r4, pc, r4
 *   @0x1460d0 str r0, [sp, #0xc]
 *   @0x1460d4 str r1, [sp, #0x14]
 *   @0x1460d8 mov r0, r1
 *   @0x1460dc ldr r2, [r4, r2]
 *   @0x1460e0 mov r5, r3
 *   @0x1460e4 movt r3, #0xbff0
 *   @0x1460e8 mov r8, r5
 *   @0x1460ec str r2, [sp, #0x10]
 *   @0x1460f0 ldr r1, [sp, #0x10]
 *   @0x1460f4 ldr r2, [sp, #0xc]
 *   @0x1460f8 str r3, [r2, #0x4]
 *   @0x1460fc ldr r3, [r1]
 *   @0x146100 str r5, [r2, #0xc]
 *   @0x146104 str r5, [r2]
 *   @0x146108 str r3, [sp, #0x11c]
 *   @0x14610c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x146110 mov r0, r5
 *   @0x146114 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x146118 vmov s17, r0
 *   @0x14611c bl 0x2052d4 <_Z8GetDsMapi>
 *   @0x146120 ldr r1, [pc, #0x19c]
 *   @0x146124 ldr r3, [pc, #0x19c]
 *   @0x146128 ldr r5, [r4, r1]
 *   @0x14612c ldr r7, [r4, r3]
 *   @0x146130 add r9, r5, #8
 *   @0x146134 add r5, r5, #224
 *   @0x146138 mov r6, r0
 *   @0x14613c b 0x14616c <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x146140 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x146144 vmov s15, r11
 *   @0x146148 str r8, [sp]
 *   @0x14614c add r9, r9, #12
 *   @0x146150 vcvt.f64.f32 d7, s15
 *   @0x146154 vmov r2, r3, d7
 *   @0x146158 mov r1, r0
 *   @0x14615c mov r0, r6
 *   @0x146160 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x146164 cmp r9, r5
 *   @0x146168 beq 0x1461b8 <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x14616c mov r0, r7
 *   @0x146170 ldr r1, [r9, #-0x4]
 *   @0x146174 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x146178 ldrb r10, [r9]
 *   @0x14617c cmp r10, #0
 *   @0x146180 mov r11, r0
 *   @0x146184 ldr r0, [r9, #-0x8]
 *   @0x146188 bne 0x146140 <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x14618c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x146190 vmov s15, r11
 *   @0x146194 str r10, [sp]
 *   @0x146198 add r9, r9, #12
 *   @0x14619c vcvt.f64.u32 d7, s15
 *   @0x1461a0 vmov r2, r3, d7
 *   @0x1461a4 mov r1, r0
 *   @0x1461a8 mov r0, r6
 *   @0x1461ac bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x1461b0 cmp r9, r5
 *   @0x1461b4 bne 0x14616c <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x1461b8 ldr r3, [pc, #0x10c]
 *   @0x1461bc add r9, sp, #28
 *   @0x1461c0 ldr r8, [pc, #0x108]
 *   @0x1461c4 mov r10, #0
 *   @0x1461c8 ldr r11, [r4, r3]
 *   @0x1461cc add r8, pc, r8
 *   @0x1461d0 add r5, r11, #8
 *   @0x1461d4 add r11, r11, #128
 *   @0x1461d8 str r11, [sp, #0x8]
 *   @0x1461dc mov r4, #0
 *   @0x1461e0 b 0x14620c <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x1461e4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1461e8 vcvt.f64.f32 d7, s16
 *   @0x1461ec str r10, [sp]
 *   @0x1461f0 add r4, r4, #1
 *   @0x1461f4 vmov r2, r3, d7
 *   @0x1461f8 mov r1, r0
 *   @0x1461fc mov r0, r6
 *   @0x146200 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x146204 cmp r4, #8
 *   @0x146208 beq 0x146270 <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x1c0>
 *   @0x14620c ldr r3, [r5, #-0x8]
 *   @0x146210 mov r1, #255
 *   @0x146214 mov r2, r8
 *   @0x146218 mov r0, r9
 *   @0x14621c str r4, [sp]
 *   @0x146220 bl 0xb65c8 <snprintf@plt>
 *   @0x146224 mov r0, r7
 *   @0x146228 mov r1, r4
 *   @0x14622c ldr r2, [r5, #-0x4]
 *   @0x146230 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x146234 ldrb r11, [r5]
 *   @0x146238 cmp r11, #0
 *   @0x14623c vmov s16, r0
 *   @0x146240 ldr r0, [r5, #-0x8]
 *   @0x146244 bne 0x1461e4 <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x146248 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x14624c vcvt.f64.u32 d7, s16
 *   @0x146250 str r11, [sp]
 *   @0x146254 add r4, r4, #1
 *   @0x146258 vmov r2, r3, d7
 *   @0x14625c mov r1, r0
 *   @0x146260 mov r0, r6
 *   @0x146264 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x146268 cmp r4, #8
 *   @0x14626c bne 0x14620c <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x146270 ldr r1, [sp, #0x8]
 *   @0x146274 add r5, r5, #12
 *   @0x146278 cmp r5, r1
 *   @0x14627c bne 0x1461dc <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x146280 vcvt.f64.s32 d7, s17
 *   @0x146284 ldr r1, [sp, #0xc]
 *   @0x146288 add r0, sp, #24
 *   @0x14628c vmov r2, r3, d7
 *   @0x146290 stm r1, {r2, r3}
 *   @0x146294 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x146298 ldr r1, [sp, #0x10]
 *   @0x14629c ldr r2, [sp, #0x11c]
 *   @0x1462a0 ldr r3, [r1]
 *   @0x1462a4 cmp r2, r3
 *   @0x1462a8 bne 0x1462b8 <_Z13F_GPUGetStateR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x1462ac add sp, sp, #292
 *   @0x1462b0 vpop {d8}
 *   @0x1462b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1462b8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1462bc eoreq r11, r10, r4, lsl #23
 *   @0x1462c0 .word 0xffffbd00
 *   @0x1462c4 .word 0xffffd9c4
 *   @0x1462c8 .word 0xffffc0a8
 *   @0x1462cc .word 0xffffd9c8
 *   @0x1462d0 andseq r11, pc, r8, lsr #8
 *
 * ══ §11/57 F_D3DBuildMatrix(RValue&, CInstance*, CInstance*, int, RValue*)  0x148c4c  size 548  137 条（0x148c4c..0x148e70）
 * @func 0x148c4c 0x148e70  size 548  137 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×9 / 0xb6580×3 / 0xb658c×3 / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0xb8×1 / 0x1fc×1
 * VFP 指令 77 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148c4c push {r4, r5, lr}
 *   @0x148c50 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x148c54 cmp r3, #9
 *   @0x148c58 sub sp, sp, #124
 *   @0x148c5c mov r5, r0
 *   @0x148c60 ldr r4, [sp, #0xb8]
 *   @0x148c64 beq 0x148c84 <_Z16F_D3DBuildMatrixR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x148c68 ldr r0, [pc, #0x1fc]
 *   @0x148c6c mov r1, #1
 *   @0x148c70 add r0, pc, r0
 *   @0x148c74 add sp, sp, #124
 *   @0x148c78 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x148c7c pop {r4, r5, lr}
 *   @0x148c80 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148c84 mov r0, r4
 *   @0x148c88 mov r1, #0
 *   @0x148c8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x148c90 mov r1, #1
 *   @0x148c94 vldr s19, [pc, #460]
 *   @0x148c98 vmov s18, r0
 *   @0x148c9c mov r0, r4
 *   @0x148ca0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x148ca4 mov r1, #2
 *   @0x148ca8 vmov s17, r0
 *   @0x148cac mov r0, r4
 *   @0x148cb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x148cb4 mov r1, #3
 *   @0x148cb8 vmov s16, r0
 *   @0x148cbc mov r0, r4
 *   @0x148cc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x148cc4 mov r1, #4
 *   @0x148cc8 vmov s12, r0
 *   @0x148ccc mov r0, r4
 *   @0x148cd0 vnmul.f32 s20, s19, s12
 *   @0x148cd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x148cd8 mov r1, #5
 *   @0x148cdc vmov s13, r0
 *   @0x148ce0 mov r0, r4
 *   @0x148ce4 vnmul.f32 s21, s19, s13
 *   @0x148ce8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x148cec mov r1, #6
 *   @0x148cf0 vmov s15, r0
 *   @0x148cf4 mov r0, r4
 *   @0x148cf8 vnmul.f32 s27, s19, s15
 *   @0x148cfc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x148d00 mov r1, #7
 *   @0x148d04 vmov s22, r0
 *   @0x148d08 mov r0, r4
 *   @0x148d0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x148d10 mov r1, #8
 *   @0x148d14 vmov s24, r0
 *   @0x148d18 mov r0, r4
 *   @0x148d1c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x148d20 vmov s23, r0
 *   @0x148d24 vmov r0, s20
 *   @0x148d28 bl 0xb6580 <sinf@plt>
 *   @0x148d2c vmov s25, r0
 *   @0x148d30 vmov r0, s20
 *   @0x148d34 bl 0xb658c <cosf@plt>
 *   @0x148d38 vmov s20, r0
 *   @0x148d3c vmov r0, s21
 *   @0x148d40 bl 0xb6580 <sinf@plt>
 *   @0x148d44 vmov s26, r0
 *   @0x148d48 vmov r0, s21
 *   @0x148d4c bl 0xb658c <cosf@plt>
 *   @0x148d50 vmov s19, r0
 *   @0x148d54 vmov r0, s27
 *   @0x148d58 bl 0xb6580 <sinf@plt>
 *   @0x148d5c vmov s21, r0
 *   @0x148d60 vmov r0, s27
 *   @0x148d64 bl 0xb658c <cosf@plt>
 *   @0x148d68 vneg.f32 s14, s26
 *   @0x148d6c mov r2, #0
 *   @0x148d70 mov r3, #0
 *   @0x148d74 mov r1, #16
 *   @0x148d78 strd r2, r3, [sp, #16]
 *   @0x148d7c strd r2, r3, [sp, #48]
 *   @0x148d80 vmul.f32 s15, s25, s21
 *   @0x148d84 strd r2, r3, [sp, #80]
 *   @0x148d88 mov r2, #0
 *   @0x148d8c mov r3, #0
 *   @0x148d90 movt r3, #0x3ff0
 *   @0x148d94 strd r2, r3, [sp, #112]
 *   @0x148d98 vmul.f32 s0, s19, s15
 *   @0x148d9c vmul.f32 s15, s15, s14
 *   @0x148da0 vmov s4, r0
 *   @0x148da4 mov r0, r5
 *   @0x148da8 vnmul.f32 s12, s25, s4
 *   @0x148dac vmul.f32 s10, s12, s14
 *   @0x148db0 vmul.f32 s12, s19, s12
 *   @0x148db4 vmla.f32 s12, s26, s21
 *   @0x148db8 vmla.f32 s10, s19, s21
 *   @0x148dbc vmla.f32 s15, s19, s4
 *   @0x148dc0 vmla.f32 s0, s26, s4
 *   @0x148dc4 vmul.f32 s14, s20, s14
 *   @0x148dc8 vmul.f32 s12, s24, s12
 *   @0x148dcc vmul.f32 s4, s20, s4
 *   @0x148dd0 vnmul.f32 s2, s21, s20
 *   @0x148dd4 vmul.f32 s6, s20, s19
 *   @0x148dd8 vmul.f32 s10, s24, s10
 *   @0x148ddc vmul.f32 s14, s23, s14
 *   @0x148de0 vcvt.f64.f32 d6, s12
 *   @0x148de4 vmul.f32 s0, s22, s0
 *   @0x148de8 vstr d6, [sp, #64]
 *   @0x148dec vmul.f32 s8, s23, s25
 *   @0x148df0 vmul.f32 s4, s24, s4
 *   @0x148df4 vmul.f32 s2, s22, s2
 *   @0x148df8 vmul.f32 s6, s23, s6
 *   @0x148dfc vmul.f32 s22, s22, s15
 *   @0x148e00 vcvt.f64.f32 d6, s17
 *   @0x148e04 vcvt.f64.f32 d5, s10
 *   @0x148e08 vstr d6, [sp, #96]
 *   @0x148e0c vcvt.f64.f32 d7, s14
 *   @0x148e10 vstr d5, [sp]
 *   @0x148e14 vcvt.f64.f32 d0, s0
 *   @0x148e18 vstr d7, [sp, #8]
 *   @0x148e1c vcvt.f64.f32 d1, s2
 *   @0x148e20 vstr d0, [sp, #56]
 *   @0x148e24 vcvt.f64.f32 d2, s4
 *   @0x148e28 vstr d1, [sp, #24]
 *   @0x148e2c vcvt.f64.f32 d3, s6
 *   @0x148e30 vstr d2, [sp, #32]
 *   @0x148e34 vcvt.f64.f32 d4, s8
 *   @0x148e38 vstr d3, [sp, #72]
 *   @0x148e3c vcvt.f64.f32 d5, s18
 *   @0x148e40 vstr d4, [sp, #40]
 *   @0x148e44 vcvt.f64.f32 d7, s16
 *   @0x148e48 vstr d5, [sp, #88]
 *   @0x148e4c vcvt.f64.f32 d6, s22
 *   @0x148e50 vstr d7, [sp, #104]
 *   @0x148e54 vmov r2, r3, d6
 *   @0x148e58 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x148e5c add sp, sp, #124
 *   @0x148e60 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x148e64 pop {r4, r5, pc}
 *   @0x148e68 vstmialo lr, {s30, s31}
 *   @0x148e6c andseq r9, pc, r4, asr #19
 *
 * ══ §12/57 CSprite::DrawSWFTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)  0x1ecfb8  size 548  137 条（0x1ecfb8..0x1ed1dc）
 * @func 0x1ecfb8 0x1ed1dc  size 548  137 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: fwrap(float, float)×2 / 0xb6994×2 / CSprite::DrawSWFTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)+0x1f0 / CSprite::DrawSWF(int, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x78×1 / 0x7c×1 / 0x90×1 / 0x94×1 / 0x24×1 / 0x28×1 / 0x14×1 / 0x18×1
 * VFP 指令 88 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ecfb8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ecfbc vpush {d8, d9, d10, d11, d12}
 *   @0x1ecfc0 sub sp, sp, #36
 *   @0x1ecfc4 vldr s17, [sp, #112]
 *   @0x1ecfc8 vcmp.f32 s17, #0
 *   @0x1ecfcc vldr s18, [sp, #116]
 *   @0x1ecfd0 vmov s14, r3
 *   @0x1ecfd4 mov r5, r0
 *   @0x1ecfd8 mov r7, r1
 *   @0x1ecfdc vmov s13, r2
 *   @0x1ecfe0 ldrb r6, [sp, #0x78]
 *   @0x1ecfe4 vldr s21, [sp, #128]
 *   @0x1ecfe8 vmrs APSR_nzcv, fpscr
 *   @0x1ecfec vcmp.f32 s18, #0
 *   @0x1ecff0 movne r3, #0
 *   @0x1ecff4 moveq r3, #1
 *   @0x1ecff8 ldrb r4, [sp, #0x7c]
 *   @0x1ecffc vldr s16, [sp, #132]
 *   @0x1ed000 ldr r8, [sp, #0x90]
 *   @0x1ed004 ldr r11, [sp, #0x94]
 *   @0x1ed008 vmrs APSR_nzcv, fpscr
 *   @0x1ed00c orreq r3, r3, #1
 *   @0x1ed010 cmp r3, #0
 *   @0x1ed014 bne 0x1ed1b4 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x1fc>
 *   @0x1ed018 vldr s15, [r0, #36]
 *   @0x1ed01c vcvt.f32.s32 s25, s15
 *   @0x1ed020 vldr s15, [r0, #28]
 *   @0x1ed024 vcvt.f32.s32 s19, s15
 *   @0x1ed028 vldr s15, [r0, #32]
 *   @0x1ed02c vcvt.f32.s32 s22, s15
 *   @0x1ed030 vldr s15, [r0, #40]
 *   @0x1ed034 vcvt.f32.s32 s24, s15
 *   @0x1ed038 vmul.f32 s25, s25, s17
 *   @0x1ed03c vabs.f32 s12, s17
 *   @0x1ed040 vmul.f32 s24, s24, s18
 *   @0x1ed044 vabs.f32 s15, s18
 *   @0x1ed048 vmul.f32 s19, s19, s12
 *   @0x1ed04c vmul.f32 s22, s22, s15
 *   @0x1ed050 vldr s15, [pc, #384]
 *   @0x1ed054 vmov r1, s19
 *   @0x1ed058 vcmpe.f32 s25, #0
 *   @0x1ed05c vmrs APSR_nzcv, fpscr
 *   @0x1ed060 vcmpe.f32 s24, #0
 *   @0x1ed064 vaddmi.f32 s25, s25, s19
 *   @0x1ed068 vmrs APSR_nzcv, fpscr
 *   @0x1ed06c vaddmi.f32 s24, s24, s22
 *   @0x1ed070 cmp r6, #0
 *   @0x1ed074 vmoveq.f32 s21, s15
 *   @0x1ed078 cmp r4, #0
 *   @0x1ed07c vsub.f32 s13, s13, s21
 *   @0x1ed080 vmoveq.f32 s16, s15
 *   @0x1ed084 vsub.f32 s13, s13, s25
 *   @0x1ed088 vsub.f32 s14, s14, s16
 *   @0x1ed08c vmov r0, s13
 *   @0x1ed090 vsub.f32 s23, s14, s24
 *   @0x1ed094 bl 0x1e62fc <_Z5fwrapff>
 *   @0x1ed098 vmov r1, s22
 *   @0x1ed09c vmov s20, r0
 *   @0x1ed0a0 vmov r0, s23
 *   @0x1ed0a4 bl 0x1e62fc <_Z5fwrapff>
 *   @0x1ed0a8 vldr s14, [sp, #136]
 *   @0x1ed0ac vdiv.f32 s14, s14, s19
 *   @0x1ed0b0 vmov s15, r0
 *   @0x1ed0b4 vcmpe.f32 s20, #0
 *   @0x1ed0b8 vmov r0, s14
 *   @0x1ed0bc vmrs APSR_nzcv, fpscr
 *   @0x1ed0c0 vcmpe.f32 s15, #0
 *   @0x1ed0c4 vsubgt.f32 s20, s20, s19
 *   @0x1ed0c8 vmrs APSR_nzcv, fpscr
 *   @0x1ed0cc vadd.f32 s16, s24, s16
 *   @0x1ed0d0 vsubgt.f32 s15, s15, s22
 *   @0x1ed0d4 vadd.f32 s23, s16, s15
 *   @0x1ed0d8 bl 0xb6994 <ceilf@plt>
 *   @0x1ed0dc vldr s15, [sp, #140]
 *   @0x1ed0e0 vdiv.f32 s15, s15, s22
 *   @0x1ed0e4 vmov s16, r0
 *   @0x1ed0e8 vmov r0, s15
 *   @0x1ed0ec bl 0xb6994 <ceilf@plt>
 *   @0x1ed0f0 cmp r6, #0
 *   @0x1ed0f4 vadd.f32 s21, s25, s21
 *   @0x1ed0f8 moveq r6, #1
 *   @0x1ed0fc vcvtne.s32.f32 s16, s16
 *   @0x1ed100 vmovne r6, s16
 *   @0x1ed104 vadd.f32 s20, s21, s20
 *   @0x1ed108 vmov s15, r0
 *   @0x1ed10c addne r6, r6, #1
 *   @0x1ed110 cmp r4, #0
 *   @0x1ed114 bne 0x1ed1c0 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x208>
 *   @0x1ed118 mov r10, #1
 *   @0x1ed11c mov r9, #0
 *   @0x1ed120 vldr s21, [pc, #176]
 *   @0x1ed124 vmov s14, r9
 *   @0x1ed128 cmp r6, #0
 *   @0x1ed12c vmov.f32 s16, s23
 *   @0x1ed130 movgt r4, #0
 *   @0x1ed134 vcvt.f32.s32 s15, s14
 *   @0x1ed138 vmla.f32 s16, s15, s22
 *   @0x1ed13c ble 0x1ed1a8 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x1f0>
 *   @0x1ed140 vmov s14, r4
 *   @0x1ed144 ldr r2, [r5, #0x24]
 *   @0x1ed148 ldr r3, [r5, #0x28]
 *   @0x1ed14c add r4, r4, #1
 *   @0x1ed150 vstr s16, [sp, #4]
 *   @0x1ed154 vstr s17, [sp, #8]
 *   @0x1ed158 vstr s18, [sp, #12]
 *   @0x1ed15c vstr s21, [sp, #16]
 *   @0x1ed160 str r8, [sp, #0x14]
 *   @0x1ed164 mov r0, r5
 *   @0x1ed168 str r11, [sp, #0x18]
 *   @0x1ed16c mov r1, r7
 *   @0x1ed170 vcvt.f32.s32 s15, s14
 *   @0x1ed174 vmov.f32 s14, s20
 *   @0x1ed178 vmla.f32 s14, s15, s19
 *   @0x1ed17c vmov.f32 s15, s14
 *   @0x1ed180 vstr s15, [sp]
 *   @0x1ed184 vmov s14, r2
 *   @0x1ed188 vmov s15, r3
 *   @0x1ed18c vcvt.f32.s32 s14, s14
 *   @0x1ed190 vcvt.f32.s32 s15, s15
 *   @0x1ed194 vmov r2, s14
 *   @0x1ed198 vmov r3, s15
 *   @0x1ed19c bl 0x1ebf08 <_ZN7CSprite7DrawSWFEifffffffjf>
 *   @0x1ed1a0 cmp r4, r6
 *   @0x1ed1a4 bne 0x1ed140 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x188>
 *   @0x1ed1a8 add r9, r9, #1
 *   @0x1ed1ac cmp r10, r9
 *   @0x1ed1b0 bgt 0x1ed124 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x16c>
 *   @0x1ed1b4 add sp, sp, #36
 *   @0x1ed1b8 vpop {d8, d9, d10, d11, d12}
 *   @0x1ed1bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ed1c0 vcvt.s32.f32 s15, s15
 *   @0x1ed1c4 vmov r10, s15
 *   @0x1ed1c8 add r10, r10, #1
 *   @0x1ed1cc cmp r10, #0
 *   @0x1ed1d0 bgt 0x1ed11c <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x164>
 *   @0x1ed1d4 b 0x1ed1b4 <_ZN7CSprite12DrawSWFTiledEiffffbbffffjf+0x1fc>
 *   @0x1ed1d8 andeq r0, r0, r0
 *
 * ══ §13/57 GV_DebugMode(CInstance*, int, RValue*)  0x200ea4  size 548  137 条（0x200ea4..0x2010c8）
 * @func 0x200ea4 0x2010c8  size 548  137 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / UNLOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / YYFree(void const*)×2 / operator delete(void*)×2 / GV_DebugMode(CInstance*, int, RValue*)+0x148 / GV_DebugMode(CInstance*, int, RValue*)+0x1d4 / GV_DebugMode(CInstance*, int, RValue*)+0x194
 * 字段偏移 top8: 0x4×12 / 0x8×6 / 0xc×4 / 0x10×3 / 0x1fc×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200ea4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x200ea8 mov r5, r2
 *   @0x200eac ldr r2, [r2, #0xc]
 *   @0x200eb0 sub r3, r2, #1
 *   @0x200eb4 bic r3, r3, #-16777216
 *   @0x200eb8 bics r4, r3, #3
 *   @0x200ebc beq 0x200f04 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x60>
 *   @0x200ec0 ldr r2, [pc, #0x1fc]
 *   @0x200ec4 mov r3, #0
 *   @0x200ec8 str r3, [r5]
 *   @0x200ecc mov r0, #1
 *   @0x200ed0 ldr r2, [pc, r2]
 *   @0x200ed4 str r3, [r5, #0x8]
 *   @0x200ed8 str r3, [r5, #0xc]
 *   @0x200edc ldr r2, [r2]
 *   @0x200ee0 ldr r2, [r2]
 *   @0x200ee4 ands r2, r2, #1
 *   @0x200ee8 moveq r3, r2
 *   @0x200eec movne r2, r3
 *   @0x200ef0 moveq r2, #0
 *   @0x200ef4 str r3, [r5]
 *   @0x200ef8 movteq r2, #0x3ff0
 *   @0x200efc str r2, [r5, #0x4]
 *   @0x200f00 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x200f04 bic r2, r2, #-16777216
 *   @0x200f08 cmp r2, #2
 *   @0x200f0c beq 0x200f7c <_Z12GV_DebugModeP9CInstanceiP6RValue+0xd8>
 *   @0x200f10 cmp r2, #3
 *   @0x200f14 beq 0x200f54 <_Z12GV_DebugModeP9CInstanceiP6RValue+0xb0>
 *   @0x200f18 cmp r2, #1
 *   @0x200f1c bne 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c>
 *   @0x200f20 ldr r4, [r5]
 *   @0x200f24 cmp r4, #0
 *   @0x200f28 beq 0x200f48 <_Z12GV_DebugModeP9CInstanceiP6RValue+0xa4>
 *   @0x200f2c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200f30 ldr r6, [r4, #0x4]
 *   @0x200f34 sub r6, r6, #1
 *   @0x200f38 str r6, [r4, #0x4]
 *   @0x200f3c cmp r6, #0
 *   @0x200f40 beq 0x200fb4 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x110>
 *   @0x200f44 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x200f48 mov r3, #0
 *   @0x200f4c str r3, [r5]
 *   @0x200f50 b 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c>
 *   @0x200f54 ldr r3, [r5, #0x8]
 *   @0x200f58 tst r3, #8
 *   @0x200f5c beq 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c>
 *   @0x200f60 ldr r0, [r5]
 *   @0x200f64 cmp r0, #0
 *   @0x200f68 beq 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c>
 *   @0x200f6c ldr r3, [r0]
 *   @0x200f70 ldr r3, [r3, #0x4]
 *   @0x200f74 blx r3
 *   @0x200f78 b 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c>
 *   @0x200f7c ldr r8, [r5]
 *   @0x200f80 cmp r8, #0
 *   @0x200f84 beq 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c>
 *   @0x200f88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200f8c ldr r3, [r8]
 *   @0x200f90 ldr r2, [r8, #0x8]
 *   @0x200f94 sub r3, r3, #1
 *   @0x200f98 str r3, [r8]
 *   @0x200f9c cmp r5, r2
 *   @0x200fa0 streq r4, [r8, #0x8]
 *   @0x200fa4 cmp r3, #0
 *   @0x200fa8 ble 0x200fec <_Z12GV_DebugModeP9CInstanceiP6RValue+0x148>
 *   @0x200fac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x200fb0 b 0x200ec0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1c>
 *   @0x200fb4 ldr r0, [r4]
 *   @0x200fb8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x200fbc str r6, [r4]
 *   @0x200fc0 str r6, [r4, #0x8]
 *   @0x200fc4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200fc8 ldr r6, [r4, #0x4]
 *   @0x200fcc sub r6, r6, #1
 *   @0x200fd0 str r6, [r4, #0x4]
 *   @0x200fd4 cmp r6, #0
 *   @0x200fd8 beq 0x2010a0 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1fc>
 *   @0x200fdc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x200fe0 mov r0, r4
 *   @0x200fe4 bl 0x27d1d0 <_ZdlPv>
 *   @0x200fe8 b 0x200f44 <_Z12GV_DebugModeP9CInstanceiP6RValue+0xa0>
 *   @0x200fec ldr r3, [r8, #0x10]
 *   @0x200ff0 cmp r3, #0
 *   @0x200ff4 movgt r7, #0
 *   @0x200ff8 movgt r11, #5
 *   @0x200ffc movgt r6, r7
 *   @0x201000 ble 0x201078 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1d4>
 *   @0x201004 ldr r3, [r8, #0x4]
 *   @0x201008 add r9, r3, r7, lsl #3
 *   @0x20100c ldr r10, [r3, r7, lsl #3]
 *   @0x201010 ldr r4, [r9, #0x4]
 *   @0x201014 add r10, r4, r10, lsl #4
 *   @0x201018 cmp r4, r10
 *   @0x20101c blo 0x201038 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x194>
 *   @0x201020 b 0x201098 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1f4>
 *   @0x201024 str r6, [r4, #0x8]
 *   @0x201028 str r11, [r4, #0xc]
 *   @0x20102c str r6, [r4], #16
 *   @0x201030 cmp r10, r4
 *   @0x201034 bls 0x20105c <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1b8>
 *   @0x201038 ldr r3, [r4, #0xc]
 *   @0x20103c sub r3, r3, #1
 *   @0x201040 bic r3, r3, #-16777216
 *   @0x201044 bic r3, r3, #3
 *   @0x201048 cmp r3, #0
 *   @0x20104c bne 0x201024 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x180>
 *   @0x201050 mov r0, r4
 *   @0x201054 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x201058 b 0x201024 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x180>
 *   @0x20105c ldr r0, [r9, #0x4]
 *   @0x201060 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x201064 ldr r3, [r8, #0x10]
 *   @0x201068 add r7, r7, #1
 *   @0x20106c str r6, [r9, #0x4]
 *   @0x201070 cmp r7, r3
 *   @0x201074 blt 0x201004 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x160>
 *   @0x201078 ldr r0, [r8, #0x4]
 *   @0x20107c mov r4, #0
 *   @0x201080 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x201084 str r4, [r8, #0x4]
 *   @0x201088 mov r0, r8
 *   @0x20108c bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x201090 str r4, [r5]
 *   @0x201094 b 0x200fac <_Z12GV_DebugModeP9CInstanceiP6RValue+0x108>
 *   @0x201098 mov r0, r4
 *   @0x20109c b 0x201060 <_Z12GV_DebugModeP9CInstanceiP6RValue+0x1bc>
 *   @0x2010a0 ldr r0, [r4]
 *   @0x2010a4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2010a8 mov r0, r4
 *   @0x2010ac str r6, [r4]
 *   @0x2010b0 str r6, [r4, #0x8]
 *   @0x2010b4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x2010b8 mov r0, r4
 *   @0x2010bc bl 0x27d1d0 <_ZdlPv>
 *   @0x2010c0 b 0x200fdc <_Z12GV_DebugModeP9CInstanceiP6RValue+0x138>
 *   @0x2010c4 andseq pc, lr, r12, lsl r5
 *
 * ══ §14/57 JS_Function_prototype_apply(RValue&, CInstance*, CInstance*, int, RValue*)  0x24e84c  size 548  137 条（0x24e84c..0x24ea70）
 * @func 0x24e84c 0x24ea70  size 548  137 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JSThrowTypeError(char const*)×2 / Call_ScriptRef(YYObjectBase*, RValue*, CScriptRef*, int, RValue*)×2 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×2 / JS_IsCallable_Object(YYObjectBase*) / F_JS_IsPrimitive(RValue&) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / JS_Function_prototype_apply(RValue&, CInstance*, CInstance*, int, RValue*)+0x1bc / 0xb6550
 * 字段偏移 top8: 0x10×5 / 0xc×4 / 0x34×2 / 0x1c×2 / 0x14×2 / 0x1f8×1 / 0x60×1 / 0x1cc×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24e84c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24e850 sub sp, sp, #60
 *   @0x24e854 ldr r4, [pc, #0x1f8]
 *   @0x24e858 mov r8, r1
 *   @0x24e85c str r0, [sp, #0xc]
 *   @0x24e860 mov r0, r1
 *   @0x24e864 ldr r4, [pc, r4]
 *   @0x24e868 ldr r5, [sp, #0x60]
 *   @0x24e86c ldr r3, [r4]
 *   @0x24e870 str r3, [sp, #0x34]
 *   @0x24e874 bl 0x240758 <_Z20JS_IsCallable_ObjectP12YYObjectBase>
 *   @0x24e878 cmp r0, #0
 *   @0x24e87c beq 0x24e920 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x24e880 ldr r3, [r5, #0xc]
 *   @0x24e884 ldr r6, [pc, #0x1cc]
 *   @0x24e888 bic r3, r3, #-16777216
 *   @0x24e88c ldr r6, [pc, r6]
 *   @0x24e890 cmp r3, #6
 *   @0x24e894 ldr r9, [r6]
 *   @0x24e898 beq 0x24e8f0 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x24e89c mov r0, r5
 *   @0x24e8a0 bl 0x241dc0 <_Z16F_JS_IsPrimitiveR6RValue>
 *   @0x24e8a4 cmp r0, #0
 *   @0x24e8a8 bne 0x24ea34 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x24e8ac ldr r3, [r5, #0x1c]
 *   @0x24e8b0 bic r3, r3, #-16777216
 *   @0x24e8b4 cmp r3, #12
 *   @0x24e8b8 beq 0x24e904 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x24e8bc cmp r3, #5
 *   @0x24e8c0 beq 0x24e904 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x24e8c4 cmp r3, #6
 *   @0x24e8c8 beq 0x24e930 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x24e8cc ldr r0, [pc, #0x188]
 *   @0x24e8d0 add r0, pc, r0
 *   @0x24e8d4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x24e8d8 ldr r2, [sp, #0x34]
 *   @0x24e8dc ldr r3, [r4]
 *   @0x24e8e0 cmp r2, r3
 *   @0x24e8e4 bne 0x24ea50 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x24e8e8 add sp, sp, #60
 *   @0x24e8ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24e8f0 ldr r3, [r5, #0x1c]
 *   @0x24e8f4 ldr r9, [r5]
 *   @0x24e8f8 bic r3, r3, #-16777216
 *   @0x24e8fc cmp r3, #12
 *   @0x24e900 bne 0x24e8bc <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x24e904 mov r3, #0
 *   @0x24e908 mov r0, r9
 *   @0x24e90c ldr r1, [sp, #0xc]
 *   @0x24e910 mov r2, r8
 *   @0x24e914 str r3, [sp]
 *   @0x24e918 bl 0x249590 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_>
 *   @0x24e91c b 0x24e8d8 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x24e920 ldr r0, [pc, #0x138]
 *   @0x24e924 add r0, pc, r0
 *   @0x24e928 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x24e92c b 0x24e8d8 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x24e930 ldr r2, [pc, #0x12c]
 *   @0x24e934 add r1, sp, #24
 *   @0x24e938 ldr r0, [r5, #0x10]
 *   @0x24e93c mvn r3, #-16777216
 *   @0x24e940 add r2, pc, r2
 *   @0x24e944 str r3, [sp, #0x24]
 *   @0x24e948 mov r10, #0
 *   @0x24e94c mov r11, #0
 *   @0x24e950 mov r6, #0
 *   @0x24e954 strd r10, r11, [sp, #24]
 *   @0x24e958 str r6, [sp, #0x20]
 *   @0x24e95c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24e960 vmov.f64 d6, #1.600000e+01
 *   @0x24e964 vldr d7, [sp, #24]
 *   @0x24e968 ldr r1, [pc, #0xf8]
 *   @0x24e96c mov r2, #70
 *   @0x24e970 mov r3, #1
 *   @0x24e974 add r1, pc, r1
 *   @0x24e978 vmul.f64 d7, d7, d6
 *   @0x24e97c vcvt.s32.f64 s13, d7
 *   @0x24e980 vmov r0, s13
 *   @0x24e984 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x24e988 vldr d7, [sp, #24]
 *   @0x24e98c vcmpe.f64 d7, #0
 *   @0x24e990 vmrs APSR_nzcv, fpscr
 *   @0x24e994 str r0, [sp, #0x10]
 *   @0x24e998 ble 0x24ea08 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x24e99c ldr r3, [pc, #0xc8]
 *   @0x24e9a0 mov r10, r6
 *   @0x24e9a4 add r7, sp, #40
 *   @0x24e9a8 mov r11, r6
 *   @0x24e9ac add r3, pc, r3
 *   @0x24e9b0 str r4, [sp, #0x14]
 *   @0x24e9b4 mov r6, r0
 *   @0x24e9b8 mov r4, r10
 *   @0x24e9bc mov r10, r3
 *   @0x24e9c0 mov r2, r4
 *   @0x24e9c4 mov r1, r10
 *   @0x24e9c8 mov r0, r7
 *   @0x24e9cc add r4, r4, #1
 *   @0x24e9d0 strb r11, [sp, #0x28]
 *   @0x24e9d4 bl 0xb6550 <sprintf@plt>
 *   @0x24e9d8 mov r1, r6
 *   @0x24e9dc ldr r0, [r5, #0x10]
 *   @0x24e9e0 mov r2, r7
 *   @0x24e9e4 add r6, r6, #16
 *   @0x24e9e8 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24e9ec vmov s15, r4
 *   @0x24e9f0 vcvt.f64.s32 d6, s15
 *   @0x24e9f4 vldr d7, [sp, #24]
 *   @0x24e9f8 vcmpe.f64 d6, d7
 *   @0x24e9fc vmrs APSR_nzcv, fpscr
 *   @0x24ea00 bmi 0x24e9c0 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x24ea04 ldr r4, [sp, #0x14]
 *   @0x24ea08 vcvt.s32.f64 s13, d7
 *   @0x24ea0c ldr r3, [sp, #0x10]
 *   @0x24ea10 mov r0, r9
 *   @0x24ea14 ldr r1, [sp, #0xc]
 *   @0x24ea18 mov r2, r8
 *   @0x24ea1c str r3, [sp]
 *   @0x24ea20 vmov r3, s13
 *   @0x24ea24 bl 0x249590 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_>
 *   @0x24ea28 ldr r0, [sp, #0x10]
 *   @0x24ea2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x24ea30 b 0x24e8d8 <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x24ea34 add r0, sp, #24
 *   @0x24ea38 mov r1, r5
 *   @0x24ea3c bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_>
 *   @0x24ea40 cmp r0, #0
 *   @0x24ea44 ldrne r9, [r6]
 *   @0x24ea48 ldreq r9, [sp, #0x18]
 *   @0x24ea4c b 0x24e8ac <_Z27JS_Function_prototype_applyR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x24ea50 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x24ea54 andseq pc, r9, r12, ror #1
 *   @0x24ea58 andseq pc, r9, r12, lsl r4
 *   @0x24ea5c andseq r7, r0, r4, ror #13
 *   @0x24ea60 andseq r7, r0, r8, asr r6
 *   @0x24ea64 andeq r1, lr, r12, lsr #30
 *   @0x24ea68 strheq r2, [lr], -r12
 *   @0x24ea6c andeq r3, lr, r0, ror #22
 *
 * ══ §15/57 CProfiler::EndFrame()  0x2a1498  size 548  137 条（0x2a1498..0x2a16bc）
 * @func 0x2a1498 0x2a16bc  size 548  137 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CProfiler::EndFrame()+0x28×2 / Timing_Time / CProfiler::EndFrame()+0x184 / CProfiler::DumpProfileData() / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x7c×13 / 0x2×6 / 0x30×3 / 0xc×3 / 0x74×3 / 0x10×3 / 0x8×2 / 0x78×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a1498 ldr r3, [pc, #0x214]
 *   @0x2a149c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a14a0 ldr r3, [pc, r3]
 *   @0x2a14a4 mov r10, #0
 *   @0x2a14a8 sub sp, sp, #28
 *   @0x2a14ac ldrb r3, [r3]
 *   @0x2a14b0 mov r4, r0
 *   @0x2a14b4 strb r10, [r0, #0x13]
 *   @0x2a14b8 cmp r3, r10
 *   @0x2a14bc bne 0x2a14c8 <_ZN9CProfiler8EndFrameEv+0x30>
 *   @0x2a14c0 add sp, sp, #28
 *   @0x2a14c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2a14c8 ldr r3, [r0, #0x30]
 *   @0x2a14cc add r3, r3, #1
 *   @0x2a14d0 str r3, [r0, #0x30]
 *   @0x2a14d4 bl 0x215148 <Timing_Time>
 *   @0x2a14d8 ldrd r6, r7, [r4]
 *   @0x2a14dc ldrd r8, r9, [r4, #64]
 *   @0x2a14e0 ldrd r2, r3, [r4, #72]
 *   @0x2a14e4 strd r6, r7, [sp, #16]
 *   @0x2a14e8 adds r6, r6, r8
 *   @0x2a14ec adc r7, r7, r9
 *   @0x2a14f0 subs r2, r2, r6
 *   @0x2a14f4 sbc r3, r3, r7
 *   @0x2a14f8 str r0, [sp, #0x8]
 *   @0x2a14fc mov r5, r0
 *   @0x2a1500 str r1, [sp, #0xc]
 *   @0x2a1504 ldrd r6, r7, [sp, #8]
 *   @0x2a1508 ldrb r0, [r4, #0x14]
 *   @0x2a150c adds r2, r2, r6
 *   @0x2a1510 adc r3, r3, r7
 *   @0x2a1514 cmp r0, r10
 *   @0x2a1518 strd r2, r3, [r4, #72]
 *   @0x2a151c beq 0x2a161c <_ZN9CProfiler8EndFrameEv+0x184>
 *   @0x2a1520 ldr r2, [r4, #0xc]
 *   @0x2a1524 ldr r3, [r4, #0x7c]
 *   @0x2a1528 ldr r1, [r4, #0x78]
 *   @0x2a152c ldr r7, [r2, #0x4]
 *   @0x2a1530 add r2, r7, #1
 *   @0x2a1534 add r2, r2, r2, lsl #1
 *   @0x2a1538 add r2, r3, r2
 *   @0x2a153c cmp r2, r1
 *   @0x2a1540 bgt 0x2a1680 <_ZN9CProfiler8EndFrameEv+0x1e8>
 *   @0x2a1544 ldr r1, [r4, #0x74]
 *   @0x2a1548 ldr r0, [sp, #0x10]
 *   @0x2a154c rsb r5, r8, r5
 *   @0x2a1550 add r2, r3, #1
 *   @0x2a1554 str r2, [r4, #0x7c]
 *   @0x2a1558 rsb r5, r0, r5
 *   @0x2a155c ldr r2, [r4, #0x68]
 *   @0x2a1560 str r5, [r1, r3, lsl #2]
 *   @0x2a1564 cmp r7, #1
 *   @0x2a1568 ldr r3, [r4, #0x7c]
 *   @0x2a156c add r0, r3, #1
 *   @0x2a1570 str r0, [r4, #0x7c]
 *   @0x2a1574 str r2, [r1, r3, lsl #2]
 *   @0x2a1578 ldr r3, [r4, #0x7c]
 *   @0x2a157c add r2, r3, #1
 *   @0x2a1580 str r2, [r4, #0x7c]
 *   @0x2a1584 str r7, [r1, r3, lsl #2]
 *   @0x2a1588 ble 0x2a161c <_ZN9CProfiler8EndFrameEv+0x184>
 *   @0x2a158c ldr r11, [r4, #0xc]
 *   @0x2a1590 mov r2, #0
 *   @0x2a1594 movw r10, #0x86a0
 *   @0x2a1598 movt r10, #0x1
 *   @0x2a159c mov r0, r2
 *   @0x2a15a0 str r7, [sp, #0x10]
 *   @0x2a15a4 ldr r5, [r11, #0x8]
 *   @0x2a15a8 add r0, r0, #1
 *   @0x2a15ac ldr r3, [sp, #0x10]
 *   @0x2a15b0 mov r7, #0
 *   @0x2a15b4 ldr r12, [r4, #0x7c]
 *   @0x2a15b8 cmp r0, r3
 *   @0x2a15bc add r3, r5, r2
 *   @0x2a15c0 ldr r8, [r5, r2]
 *   @0x2a15c4 add r9, r12, #1
 *   @0x2a15c8 ldrb r6, [r3, #0x3]
 *   @0x2a15cc add r2, r2, #40
 *   @0x2a15d0 ubfx r8, r8, #0x0, #0x1c
 *   @0x2a15d4 ldr r5, [r3, #0x20]
 *   @0x2a15d8 str r7, [r3, #0x20]
 *   @0x2a15dc lsr r6, r6, #4
 *   @0x2a15e0 str r9, [r4, #0x7c]
 *   @0x2a15e4 mla r6, r10, r6, r8
 *   @0x2a15e8 str r6, [r1, r12, lsl #2]
 *   @0x2a15ec ldr r12, [r4, #0x7c]
 *   @0x2a15f0 add r6, r12, #1
 *   @0x2a15f4 str r6, [r4, #0x7c]
 *   @0x2a15f8 str r5, [r1, r12, lsl #2]
 *   @0x2a15fc ldrh r5, [r3, #28]
 *   @0x2a1600 ldr r12, [r4, #0x7c]
 *   @0x2a1604 ldrh r3, [r3, #24]
 *   @0x2a1608 add r6, r12, #1
 *   @0x2a160c str r6, [r4, #0x7c]
 *   @0x2a1610 orr r3, r3, r5, lsl #16
 *   @0x2a1614 str r3, [r1, r12, lsl #2]
 *   @0x2a1618 bne 0x2a15a4 <_ZN9CProfiler8EndFrameEv+0x10c>
 *   @0x2a161c ldrb r3, [r4, #0x15]
 *   @0x2a1620 cmp r3, #0
 *   @0x2a1624 beq 0x2a14c0 <_ZN9CProfiler8EndFrameEv+0x28>
 *   @0x2a1628 ldr r1, [r4, #0x2c]
 *   @0x2a162c cmp r1, #0
 *   @0x2a1630 ble 0x2a14c0 <_ZN9CProfiler8EndFrameEv+0x28>
 *   @0x2a1634 ldrd r2, r3, [r4, #32]
 *   @0x2a1638 orrs r0, r2, r3
 *   @0x2a163c ldrdeq r6, r7, [sp, #8]
 *   @0x2a1640 strdeq r6, r7, [r4, #32]
 *   @0x2a1644 beq 0x2a14c0 <_ZN9CProfiler8EndFrameEv+0x28>
 *   @0x2a1648 movw r0, #0x4240
 *   @0x2a164c movt r0, #0xf
 *   @0x2a1650 ldrd r6, r7, [sp, #8]
 *   @0x2a1654 mul r0, r0, r1
 *   @0x2a1658 subs r2, r6, r2
 *   @0x2a165c sbc r3, r7, r3
 *   @0x2a1660 asr r1, r0, #31
 *   @0x2a1664 cmp r3, r1
 *   @0x2a1668 cmpeq r2, r0
 *   @0x2a166c bls 0x2a14c0 <_ZN9CProfiler8EndFrameEv+0x28>
 *   @0x2a1670 mov r0, r4
 *   @0x2a1674 bl 0x2a0ea0 <_ZN9CProfiler15DumpProfileDataEv>
 *   @0x2a1678 strd r6, r7, [r4, #32]
 *   @0x2a167c b 0x2a14c0 <_ZN9CProfiler8EndFrameEv+0x28>
 *   @0x2a1680 ldr r2, [pc, #0x30]
 *   @0x2a1684 lsl r3, r1, #1
 *   @0x2a1688 ldr r0, [r4, #0x74]
 *   @0x2a168c lsl r1, r1, #3
 *   @0x2a1690 str r10, [sp]
 *   @0x2a1694 add r2, pc, r2
 *   @0x2a1698 str r3, [r4, #0x78]
 *   @0x2a169c mov r3, #237
 *   @0x2a16a0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x2a16a4 ldr r3, [r4, #0x7c]
 *   @0x2a16a8 mov r1, r0
 *   @0x2a16ac str r0, [r4, #0x74]
 *   @0x2a16b0 b 0x2a1548 <_ZN9CProfiler8EndFrameEv+0xb0>
 *   @0x2a16b4 andseq r12, r4, r8, asr #13
 *   @0x2a16b8 andeq r8, r11, r0, lsl r6
 *
 * ══ §16/57 F_D3DMatrixMultiply(RValue&, CInstance*, CInstance*, int, RValue*)  0x1496c4  size 544  136 条（0x1496c4..0x1498e4）
 * @func 0x1496c4 0x1498e4  size 544  136 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYError(char const*, ...)×3 / REAL_RValue_Ex(RValue const*)×2 / yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*) / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0x4×4 / 0x198×3 / 0xc×3 / 0x1f4×1 / 0x1c×1 / 0x1c0×1 / 0x194×1 / 0x10×1
 * VFP 指令 57 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1496c4 cmp r3, #2
 *   @0x1496c8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1496cc vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x1496d0 mov r6, r0
 *   @0x1496d4 sub sp, sp, #316
 *   @0x1496d8 beq 0x1496f8 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1496dc ldr r0, [pc, #0x1f4]
 *   @0x1496e0 mov r1, r3
 *   @0x1496e4 add r0, pc, r0
 *   @0x1496e8 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x1496ec add sp, sp, #316
 *   @0x1496f0 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x1496f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1496f8 ldr r1, [sp, #0x198]
 *   @0x1496fc ldr r3, [r1, #0xc]
 *   @0x149700 cmp r3, #2
 *   @0x149704 bne 0x149714 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x149708 ldr r3, [r1, #0x1c]
 *   @0x14970c cmp r3, #2
 *   @0x149710 beq 0x14972c <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x149714 ldr r0, [pc, #0x1c0]
 *   @0x149718 add r0, pc, r0
 *   @0x14971c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x149720 add sp, sp, #316
 *   @0x149724 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x149728 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14972c ldr r2, [sp, #0x198]
 *   @0x149730 ldr r3, [r2]
 *   @0x149734 ldr r3, [r3, #0x4]
 *   @0x149738 ldr r2, [r3]
 *   @0x14973c cmp r2, #16
 *   @0x149740 beq 0x149758 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x149744 ldr r0, [pc, #0x194]
 *   @0x149748 mov r1, #1
 *   @0x14974c add r0, pc, r0
 *   @0x149750 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x149754 b 0x1496ec <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x149758 ldr r1, [sp, #0x198]
 *   @0x14975c ldr r2, [r1, #0x10]
 *   @0x149760 ldr r2, [r2, #0x4]
 *   @0x149764 ldr r1, [r2]
 *   @0x149768 cmp r1, #16
 *   @0x14976c bne 0x149744 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x149770 add r4, sp, #184
 *   @0x149774 add r5, sp, #120
 *   @0x149778 ldr r8, [r3, #0x4]
 *   @0x14977c add r9, sp, #248
 *   @0x149780 ldr r7, [r2, #0x4]
 *   @0x149784 mov r10, r4
 *   @0x149788 mov r11, r5
 *   @0x14978c b 0x1497d0 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x149790 ldm r8, {r0, r1}
 *   @0x149794 vmov d6, r0, r1
 *   @0x149798 ldr r1, [r7, #0xc]
 *   @0x14979c vcvt.f32.f64 s15, d6
 *   @0x1497a0 bic r1, r1, #-16777216
 *   @0x1497a4 cmp r1, #0
 *   @0x1497a8 vstmia r11!, {s15}
 *   @0x1497ac bne 0x1497ec <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x1497b0 ldm r7, {r0, r1}
 *   @0x1497b4 vmov d6, r0, r1
 *   @0x1497b8 add r8, r8, #16
 *   @0x1497bc add r7, r7, #16
 *   @0x1497c0 vcvt.f32.f64 s15, d6
 *   @0x1497c4 vstmia r10!, {s15}
 *   @0x1497c8 cmp r10, r9
 *   @0x1497cc beq 0x1497f8 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1497d0 ldr r1, [r8, #0xc]
 *   @0x1497d4 bic r1, r1, #-16777216
 *   @0x1497d8 cmp r1, #0
 *   @0x1497dc beq 0x149790 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x1497e0 mov r0, r8
 *   @0x1497e4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1497e8 b 0x149794 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x1497ec mov r0, r7
 *   @0x1497f0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1497f4 b 0x1497b4 <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x1497f8 mov r0, r10
 *   @0x1497fc mov r1, r5
 *   @0x149800 mov r2, r4
 *   @0x149804 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x149808 vldr s14, [sp, #252]
 *   @0x14980c vcvt.f64.f32 d7, s14
 *   @0x149810 vldr s26, [sp, #256]
 *   @0x149814 vldr s24, [sp, #260]
 *   @0x149818 vldr s22, [sp, #264]
 *   @0x14981c vldr s20, [sp, #268]
 *   @0x149820 vldr s18, [sp, #272]
 *   @0x149824 vldr s16, [sp, #276]
 *   @0x149828 vldr s0, [sp, #280]
 *   @0x14982c vldr s2, [sp, #284]
 *   @0x149830 vldr s4, [sp, #288]
 *   @0x149834 vldr s6, [sp, #292]
 *   @0x149838 vldr s8, [sp, #296]
 *   @0x14983c vldr s10, [sp, #300]
 *   @0x149840 vldr s12, [sp, #304]
 *   @0x149844 vstr d7, [sp]
 *   @0x149848 vldr s14, [sp, #308]
 *   @0x14984c vcvt.f64.f32 d7, s14
 *   @0x149850 vldr s28, [sp, #248]
 *   @0x149854 mov r0, r6
 *   @0x149858 mov r1, #16
 *   @0x14985c vcvt.f64.f32 d13, s26
 *   @0x149860 vstr d7, [sp, #112]
 *   @0x149864 vcvt.f64.f32 d12, s24
 *   @0x149868 vstr d13, [sp, #8]
 *   @0x14986c vcvt.f64.f32 d11, s22
 *   @0x149870 vstr d12, [sp, #16]
 *   @0x149874 vcvt.f64.f32 d10, s20
 *   @0x149878 vstr d11, [sp, #24]
 *   @0x14987c vcvt.f64.f32 d9, s18
 *   @0x149880 vstr d10, [sp, #32]
 *   @0x149884 vcvt.f64.f32 d8, s16
 *   @0x149888 vstr d9, [sp, #40]
 *   @0x14988c vcvt.f64.f32 d0, s0
 *   @0x149890 vstr d8, [sp, #48]
 *   @0x149894 vcvt.f64.f32 d1, s2
 *   @0x149898 vstr d0, [sp, #56]
 *   @0x14989c vcvt.f64.f32 d2, s4
 *   @0x1498a0 vstr d1, [sp, #64]
 *   @0x1498a4 vcvt.f64.f32 d3, s6
 *   @0x1498a8 vstr d2, [sp, #72]
 *   @0x1498ac vcvt.f64.f32 d4, s8
 *   @0x1498b0 vstr d3, [sp, #80]
 *   @0x1498b4 vcvt.f64.f32 d5, s10
 *   @0x1498b8 vstr d4, [sp, #88]
 *   @0x1498bc vcvt.f64.f32 d6, s12
 *   @0x1498c0 vstr d5, [sp, #96]
 *   @0x1498c4 vcvt.f64.f32 d7, s28
 *   @0x1498c8 vstr d6, [sp, #104]
 *   @0x1498cc vmov r2, r3, d7
 *   @0x1498d0 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x1498d4 b 0x1496ec <_Z19F_D3DMatrixMultiplyR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x1498d8 andseq r9, pc, r4, asr #4
 *   @0x1498dc andseq r9, pc, r12, lsr r2
 *   @0x1498e0 andseq r9, pc, r0, lsr r2
 *
 * ══ §17/57 CDS_Stack::Push(RValue*)  0x20566c  size 544  136 条（0x20566c..0x20588c）
 * @func 0x20566c 0x20588c  size 544  136 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) / _RefThing<char const*>::dec()
 * 字段偏移 top8: 0x4×9 / 0x8×7 / 0xc×6 / 0xec×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20566c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x205670 mov r5, r1
 *   @0x205674 ldmib r0, {r1, r3}
 *   @0x205678 mov r4, r0
 *   @0x20567c cmp r1, r3
 *   @0x205680 bge 0x205790 <_ZN9CDS_Stack4PushEP6RValue+0x124>
 *   @0x205684 ldr r7, [r4, #0xc]
 *   @0x205688 lsl r8, r1, #4
 *   @0x20568c add r6, r7, r8
 *   @0x205690 ldr r2, [r6, #0xc]
 *   @0x205694 bic r3, r2, #-16777216
 *   @0x205698 cmp r3, #1
 *   @0x20569c beq 0x20575c <_ZN9CDS_Stack4PushEP6RValue+0xf0>
 *   @0x2056a0 cmp r3, #2
 *   @0x2056a4 bne 0x2056cc <_ZN9CDS_Stack4PushEP6RValue+0x60>
 *   @0x2056a8 sub r2, r2, #1
 *   @0x2056ac bic r2, r2, #-16777216
 *   @0x2056b0 bic r2, r2, #3
 *   @0x2056b4 cmp r2, #0
 *   @0x2056b8 beq 0x20587c <_ZN9CDS_Stack4PushEP6RValue+0x210>
 *   @0x2056bc mov r2, #0
 *   @0x2056c0 mov r3, #5
 *   @0x2056c4 str r2, [r6, #0x8]
 *   @0x2056c8 str r3, [r6, #0xc]
 *   @0x2056cc ldr r3, [r5, #0xc]
 *   @0x2056d0 mov r1, #0
 *   @0x2056d4 ldr r2, [r5, #0x8]
 *   @0x2056d8 str r1, [r7, r8]
 *   @0x2056dc str r3, [r6, #0xc]
 *   @0x2056e0 ldr r3, [r5, #0xc]
 *   @0x2056e4 str r2, [r6, #0x8]
 *   @0x2056e8 bic r3, r3, #-16777216
 *   @0x2056ec cmp r3, #14
 *   @0x2056f0 addls pc, pc, r3, lsl #2
 *   @0x2056f4 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0>
 *   @0x2056f8 b 0x20574c <_ZN9CDS_Stack4PushEP6RValue+0xe0>
 *   @0x2056fc b 0x2057e0 <_ZN9CDS_Stack4PushEP6RValue+0x174>
 *   @0x205700 b 0x2057f8 <_ZN9CDS_Stack4PushEP6RValue+0x18c>
 *   @0x205704 b 0x205734 <_ZN9CDS_Stack4PushEP6RValue+0xc8>
 *   @0x205708 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0>
 *   @0x20570c b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0>
 *   @0x205710 b 0x2057bc <_ZN9CDS_Stack4PushEP6RValue+0x150>
 *   @0x205714 b 0x205734 <_ZN9CDS_Stack4PushEP6RValue+0xc8>
 *   @0x205718 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0>
 *   @0x20571c b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0>
 *   @0x205720 b 0x20574c <_ZN9CDS_Stack4PushEP6RValue+0xe0>
 *   @0x205724 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0>
 *   @0x205728 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0>
 *   @0x20572c b 0x20574c <_ZN9CDS_Stack4PushEP6RValue+0xe0>
 *   @0x205730 b 0x205734 <_ZN9CDS_Stack4PushEP6RValue+0xc8>
 *   @0x205734 ldr r3, [r5]
 *   @0x205738 str r3, [r7, r8]
 *   @0x20573c ldr r3, [r4, #0x4]
 *   @0x205740 add r3, r3, #1
 *   @0x205744 str r3, [r4, #0x4]
 *   @0x205748 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x20574c ldm r5, {r2, r3}
 *   @0x205750 str r2, [r7, r8]
 *   @0x205754 str r3, [r6, #0x4]
 *   @0x205758 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0>
 *   @0x20575c ldr r9, [r7, r1, lsl #4]
 *   @0x205760 cmp r9, #0
 *   @0x205764 beq 0x205784 <_ZN9CDS_Stack4PushEP6RValue+0x118>
 *   @0x205768 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20576c ldr r10, [r9, #0x4]
 *   @0x205770 sub r10, r10, #1
 *   @0x205774 str r10, [r9, #0x4]
 *   @0x205778 cmp r10, #0
 *   @0x20577c beq 0x205824 <_ZN9CDS_Stack4PushEP6RValue+0x1b8>
 *   @0x205780 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x205784 mov r3, #0
 *   @0x205788 str r3, [r7, r8]
 *   @0x20578c b 0x2056cc <_ZN9CDS_Stack4PushEP6RValue+0x60>
 *   @0x205790 add r1, r1, #16
 *   @0x205794 ldr r2, [pc, #0xec]
 *   @0x205798 movw r3, #0x25e
 *   @0x20579c add r0, r0, #12
 *   @0x2057a0 lsl r1, r1, #4
 *   @0x2057a4 add r2, pc, r2
 *   @0x2057a8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x2057ac ldr r1, [r4, #0x4]
 *   @0x2057b0 add r3, r1, #16
 *   @0x2057b4 str r3, [r4, #0x8]
 *   @0x2057b8 b 0x205684 <_ZN9CDS_Stack4PushEP6RValue+0x18>
 *   @0x2057bc ldr r3, [r5]
 *   @0x2057c0 str r3, [r7, r8]
 *   @0x2057c4 ldr r3, [r5]
 *   @0x2057c8 cmp r3, #0
 *   @0x2057cc beq 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0>
 *   @0x2057d0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x2057d4 ldr r1, [r5]
 *   @0x2057d8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2057dc b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0>
 *   @0x2057e0 ldr r3, [r5]
 *   @0x2057e4 cmp r3, #0
 *   @0x2057e8 ldrne r2, [r3, #0x4]
 *   @0x2057ec addne r2, r2, #1
 *   @0x2057f0 strne r2, [r3, #0x4]
 *   @0x2057f4 b 0x205738 <_ZN9CDS_Stack4PushEP6RValue+0xcc>
 *   @0x2057f8 ldr r3, [r5]
 *   @0x2057fc cmp r3, #0
 *   @0x205800 str r3, [r7, r8]
 *   @0x205804 beq 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0>
 *   @0x205808 ldr r1, [r3, #0x8]
 *   @0x20580c ldr r2, [r3]
 *   @0x205810 cmp r1, #0
 *   @0x205814 streq r6, [r3, #0x8]
 *   @0x205818 add r2, r2, #1
 *   @0x20581c str r2, [r3]
 *   @0x205820 b 0x20573c <_ZN9CDS_Stack4PushEP6RValue+0xd0>
 *   @0x205824 ldr r0, [r9]
 *   @0x205828 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20582c str r10, [r9]
 *   @0x205830 str r10, [r9, #0x8]
 *   @0x205834 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x205838 ldr r10, [r9, #0x4]
 *   @0x20583c sub r10, r10, #1
 *   @0x205840 str r10, [r9, #0x4]
 *   @0x205844 cmp r10, #0
 *   @0x205848 bne 0x20586c <_ZN9CDS_Stack4PushEP6RValue+0x200>
 *   @0x20584c ldr r0, [r9]
 *   @0x205850 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x205854 mov r0, r9
 *   @0x205858 str r10, [r9]
 *   @0x20585c str r10, [r9, #0x8]
 *   @0x205860 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x205864 mov r0, r9
 *   @0x205868 bl 0x27d1d0 <_ZdlPv>
 *   @0x20586c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x205870 mov r0, r9
 *   @0x205874 bl 0x27d1d0 <_ZdlPv>
 *   @0x205878 b 0x205780 <_ZN9CDS_Stack4PushEP6RValue+0x114>
 *   @0x20587c mov r0, r6
 *   @0x205880 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x205884 b 0x2056bc <_ZN9CDS_Stack4PushEP6RValue+0x50>
 *   @0x205888 andseq lr, r4, r8, asr #32
 *
 * ══ §18/57 JS_RegExpObjectSetup()  0x246cc0  size 544  136 条（0x246cc0..0x246ee0）
 * @func 0x246cc0 0x246ee0  size 544  136 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x246ce8→0x756414, 0x246cfc→0x756450, 0x246e0c→0x544be0
 * 调用序列: YYObjectBase::Add(char const*, YYObjectBase*, int)×5 / JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×4 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x8×5 / 0x4×3 / 0x28×2 / 0x104×2 / 0xc×2 / 0x1bc×1 / 0x1b8×1 / 0x1b0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x246cc0 push {r4, r5, r6, r7, r8, lr}
 *   @0x246cc4 sub sp, sp, #24
 *   @0x246cc8 mov r5, #0
 *   @0x246ccc add r0, sp, #8
 *   @0x246cd0 mov r1, r5
 *   @0x246cd4 mov r2, r5
 *   @0x246cd8 mov r3, r5
 *   @0x246cdc str r5, [sp]
 *   @0x246ce0 ldr r6, [pc, #0x1bc]
 *   @0x246ce4 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x246ce8 ldr r3, [pc, #0x1b8]
 *   @0x246cec add r6, pc, r6
 *   @0x246cf0 ldr r4, [sp, #0x8]
 *   @0x246cf4 ldr r2, [pc, #0x1b0]
 *   @0x246cf8 ldr r8, [r6, r3]
 *   @0x246cfc ldr r3, [pc, #0x1ac]
 *   @0x246d00 add r2, pc, r2
 *   @0x246d04 str r2, [r4, #0x40]
 *   @0x246d08 mov r0, r4
 *   @0x246d0c str r4, [r8]
 *   @0x246d10 ldr r3, [r6, r3]
 *   @0x246d14 ldr r1, [r3]
 *   @0x246d18 str r1, [r4, #0x18]
 *   @0x246d1c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x246d20 ldr r3, [pc, #0x18c]
 *   @0x246d24 ldr r0, [r4, #0x28]
 *   @0x246d28 mov r1, r5
 *   @0x246d2c mov r2, r5
 *   @0x246d30 orr r0, r0, #1
 *   @0x246d34 str r0, [r4, #0x28]
 *   @0x246d38 ldr r0, [r6, r3]
 *   @0x246d3c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246d40 ldr r1, [pc, #0x170]
 *   @0x246d44 mov r3, #6
 *   @0x246d48 add r1, pc, r1
 *   @0x246d4c mov r2, r0
 *   @0x246d50 mov r0, r4
 *   @0x246d54 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246d58 ldr r3, [pc, #0x15c]
 *   @0x246d5c mov r2, r5
 *   @0x246d60 mov r1, #1
 *   @0x246d64 ldr r0, [r6, r3]
 *   @0x246d68 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246d6c ldr r1, [pc, #0x14c]
 *   @0x246d70 mov r3, #6
 *   @0x246d74 add r1, pc, r1
 *   @0x246d78 mov r2, r0
 *   @0x246d7c mov r0, r4
 *   @0x246d80 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246d84 ldr r3, [pc, #0x138]
 *   @0x246d88 mov r2, r5
 *   @0x246d8c mov r1, #1
 *   @0x246d90 ldr r0, [r6, r3]
 *   @0x246d94 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246d98 ldr r1, [pc, #0x128]
 *   @0x246d9c mov r3, #6
 *   @0x246da0 add r1, pc, r1
 *   @0x246da4 mov r2, r0
 *   @0x246da8 mov r0, r4
 *   @0x246dac bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246db0 ldr r3, [pc, #0x114]
 *   @0x246db4 mov r2, r5
 *   @0x246db8 mov r1, #2
 *   @0x246dbc ldr r0, [r6, r3]
 *   @0x246dc0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246dc4 ldr r12, [pc, #0x104]
 *   @0x246dc8 ldr r1, [pc, #0x104]
 *   @0x246dcc mov r3, r5
 *   @0x246dd0 ldr r12, [r6, r12]
 *   @0x246dd4 add r1, pc, r1
 *   @0x246dd8 mov r7, r0
 *   @0x246ddc mov r0, r4
 *   @0x246de0 mov r2, r7
 *   @0x246de4 str r12, [r7, #0x94]
 *   @0x246de8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246dec ldr r1, [r7, #0x4]
 *   @0x246df0 cmp r1, r5
 *   @0x246df4 beq 0x246e3c <_Z20JS_RegExpObjectSetupv+0x17c>
 *   @0x246df8 ldr r3, [r8]
 *   @0x246dfc mov r0, r1
 *   @0x246e00 str r3, [r1]
 *   @0x246e04 mov r3, #6
 *   @0x246e08 str r3, [r0, #0xc]
 *   @0x246e0c ldr r12, [pc, #0xc4]
 *   @0x246e10 mov r3, #6
 *   @0x246e14 str r3, [r0, #0x8]
 *   @0x246e18 mov r2, r7
 *   @0x246e1c ldr r1, [pc, #0xb8]
 *   @0x246e20 mov r3, #0
 *   @0x246e24 ldr r0, [r6, r12]
 *   @0x246e28 add r1, pc, r1
 *   @0x246e2c ldr r0, [r0]
 *   @0x246e30 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246e34 add sp, sp, #24
 *   @0x246e38 pop {r4, r5, r6, r7, r8, pc}
 *   @0x246e3c ldr r3, [r7]
 *   @0x246e40 mov r0, r7
 *   @0x246e44 ldr r3, [r3, #0x8]
 *   @0x246e48 blx r3
 *   @0x246e4c ldr r1, [r7, #0x4]
 *   @0x246e50 ldr r3, [r8]
 *   @0x246e54 cmp r1, r5
 *   @0x246e58 str r3, [r0]
 *   @0x246e5c bne 0x246e9c <_Z20JS_RegExpObjectSetupv+0x1dc>
 *   @0x246e60 ldr r3, [r7]
 *   @0x246e64 mov r0, r7
 *   @0x246e68 ldr r3, [r3, #0x8]
 *   @0x246e6c blx r3
 *   @0x246e70 ldr r1, [r7, #0x4]
 *   @0x246e74 mov r3, #6
 *   @0x246e78 cmp r1, r5
 *   @0x246e7c str r3, [r0, #0xc]
 *   @0x246e80 movne r0, r1
 *   @0x246e84 bne 0x246e0c <_Z20JS_RegExpObjectSetupv+0x14c>
 *   @0x246e88 ldr r3, [r7]
 *   @0x246e8c mov r0, r7
 *   @0x246e90 ldr r3, [r3, #0x8]
 *   @0x246e94 blx r3
 *   @0x246e98 b 0x246e0c <_Z20JS_RegExpObjectSetupv+0x14c>
 *   @0x246e9c mov r0, r1
 *   @0x246ea0 b 0x246e04 <_Z20JS_RegExpObjectSetupv+0x144>
 *   @0x246ea4 andseq r10, r10, r4, ror #30
 *   @0x246ea8 .word 0xfffffafc
 *   @0x246eac andseq lr, r0, r12, lsr #30
 *   @0x246eb0 .word 0xffffc050
 *   @0x246eb4 .word 0xfffffb00
 *   @0x246eb8 andeq r11, lr, r8, asr #15
 *   @0x246ebc .word 0xfffffb04
 *   @0x246ec0 andseq lr, r0, r0, asr #29
 *   @0x246ec4 .word 0xfffffb08
 *   @0x246ec8 mulseq r0, r12, lr
 *   @0x246ecc .word 0xfffffb0c
 *   @0x246ed0 .word 0xfffffb10
 *   @0x246ed4 andseq lr, r0, r0, asr r7
 *   @0x246ed8 .word 0xffffbf64
 *   @0x246edc andseq lr, r0, r4, lsl #28
 *
 * ══ §19/57 JS_Array_prototype_slice(RValue&, CInstance*, CInstance*, int, RValue*)  0x24bb00  size 544  136 条（0x24bb00..0x24bd20）
 * @func 0x24bb00 0x24bd20  size 544  136 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×2 / YYGetInt32(RValue const*, int)×2 / 0xb65c8×2 / F_JSNewArray_NoArguments(RValue&, CInstance*, CInstance*, int, RValue*) / YYGetUint32(RValue const*, int) / JS_Array_prototype_slice(RValue&, CInstance*, CInstance*, int, RValue*)+0xa8 / JS_Array_prototype_slice(RValue&, CInstance*, CInstance*, int, RValue*)+0xe0 / JS_Array_prototype_slice(RValue&, CInstance*, CInstance*, int, RValue*)+0x10c
 * 字段偏移 top8: 0x34×3 / 0x10×2 / 0x14×2 / 0x7c×2 / 0x38×2 / 0x20c×1 / 0xa8×1 / 0x1d0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24bb00 ldr r12, [pc, #0x20c]
 *   @0x24bb04 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24bb08 ldr r12, [pc, r12]
 *   @0x24bb0c sub sp, sp, #132
 *   @0x24bb10 mov r7, #0
 *   @0x24bb14 mov r4, r3
 *   @0x24bb18 mov r3, r7
 *   @0x24bb1c str r12, [sp, #0x10]
 *   @0x24bb20 mov r5, r1
 *   @0x24bb24 ldr r12, [r12]
 *   @0x24bb28 add r8, sp, #28
 *   @0x24bb2c str r7, [sp]
 *   @0x24bb30 str r0, [sp, #0x14]
 *   @0x24bb34 str r12, [sp, #0x7c]
 *   @0x24bb38 ldr r6, [sp, #0xa8]
 *   @0x24bb3c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x24bb40 ldr r2, [pc, #0x1d0]
 *   @0x24bb44 mov r0, r5
 *   @0x24bb48 mov r1, r8
 *   @0x24bb4c mvn r3, #-16777216
 *   @0x24bb50 add r2, pc, r2
 *   @0x24bb54 str r3, [sp, #0x28]
 *   @0x24bb58 str r7, [sp, #0x1c]
 *   @0x24bb5c str r7, [sp, #0x20]
 *   @0x24bb60 str r7, [sp, #0x24]
 *   @0x24bb64 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24bb68 mov r0, r8
 *   @0x24bb6c mov r1, r7
 *   @0x24bb70 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x24bb74 cmp r4, r7
 *   @0x24bb78 mov r9, r0
 *   @0x24bb7c ble 0x24bba8 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x24bb80 mov r1, r7
 *   @0x24bb84 mov r0, r6
 *   @0x24bb88 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x24bb8c cmp r0, #0
 *   @0x24bb90 movge r2, r0
 *   @0x24bb94 asrge r3, r2, #31
 *   @0x24bb98 bge 0x24bbb0 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x24bb9c add r7, r0, r9
 *   @0x24bba0 bic r7, r7, r7, asr #31
 *   @0x24bba4 b 0x24bbc8 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x24bba8 mov r2, #0
 *   @0x24bbac mov r3, #0
 *   @0x24bbb0 mov r10, r9
 *   @0x24bbb4 mov r11, #0
 *   @0x24bbb8 cmp r10, r2
 *   @0x24bbbc sbcs r1, r11, r3
 *   @0x24bbc0 movlt r2, r9
 *   @0x24bbc4 mov r7, r2
 *   @0x24bbc8 cmp r4, #1
 *   @0x24bbcc movle r0, r9
 *   @0x24bbd0 ble 0x24bbe0 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x24bbd4 mov r0, r6
 *   @0x24bbd8 mov r1, #1
 *   @0x24bbdc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x24bbe0 cmp r0, #0
 *   @0x24bbe4 addlt r8, r0, r9
 *   @0x24bbe8 biclt r8, r8, r8, asr #31
 *   @0x24bbec blt 0x24bc0c <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x24bbf0 mov r2, r9
 *   @0x24bbf4 asr r9, r0, #31
 *   @0x24bbf8 mov r8, r0
 *   @0x24bbfc mov r3, #0
 *   @0x24bc00 cmp r2, r8
 *   @0x24bc04 sbcs r12, r3, r9
 *   @0x24bc08 movlt r8, r2
 *   @0x24bc0c cmp r7, r8
 *   @0x24bc10 bhs 0x24bcf4 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x24bc14 ldr r6, [pc, #0x100]
 *   @0x24bc18 add r12, sp, #92
 *   @0x24bc1c add r4, sp, #60
 *   @0x24bc20 str r12, [sp, #0xc]
 *   @0x24bc24 add r6, pc, r6
 *   @0x24bc28 add r10, sp, #44
 *   @0x24bc2c mov r11, r7
 *   @0x24bc30 mov r9, #0
 *   @0x24bc34 b 0x24bc44 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x24bc38 add r11, r11, #1
 *   @0x24bc3c cmp r8, r11
 *   @0x24bc40 bls 0x24bcf4 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x24bc44 mov r3, r11
 *   @0x24bc48 mov r1, #32
 *   @0x24bc4c mov r2, r6
 *   @0x24bc50 mov r0, r4
 *   @0x24bc54 bl 0xb65c8 <snprintf@plt>
 *   @0x24bc58 mov r0, r5
 *   @0x24bc5c mov r1, r4
 *   @0x24bc60 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x24bc64 rsb r3, r7, r11
 *   @0x24bc68 cmp r0, #0
 *   @0x24bc6c beq 0x24bc38 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x24bc70 mov r1, #32
 *   @0x24bc74 mov r2, r6
 *   @0x24bc78 add r0, sp, #92
 *   @0x24bc7c bl 0xb65c8 <snprintf@plt>
 *   @0x24bc80 mov r0, r5
 *   @0x24bc84 mov r1, r10
 *   @0x24bc88 mov r2, r4
 *   @0x24bc8c mvn lr, #-16777216
 *   @0x24bc90 str r9, [sp, #0x2c]
 *   @0x24bc94 str lr, [sp, #0x38]
 *   @0x24bc98 str r9, [sp, #0x30]
 *   @0x24bc9c str r9, [sp, #0x34]
 *   @0x24bca0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24bca4 ldr r12, [sp, #0x14]
 *   @0x24bca8 mov r3, #0
 *   @0x24bcac ldr lr, [sp, #0x34]
 *   @0x24bcb0 add r1, sp, #92
 *   @0x24bcb4 mov r2, r10
 *   @0x24bcb8 ldr r0, [r12]
 *   @0x24bcbc orr lr, lr, #7
 *   @0x24bcc0 str lr, [sp, #0x34]
 *   @0x24bcc4 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x24bcc8 ldr r3, [sp, #0x38]
 *   @0x24bccc sub r3, r3, #1
 *   @0x24bcd0 bic r3, r3, #-16777216
 *   @0x24bcd4 bic r3, r3, #3
 *   @0x24bcd8 cmp r3, #0
 *   @0x24bcdc bne 0x24bc38 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x24bce0 mov r0, r10
 *   @0x24bce4 add r11, r11, #1
 *   @0x24bce8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24bcec cmp r8, r11
 *   @0x24bcf0 bhi 0x24bc44 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x24bcf4 ldr r12, [sp, #0x10]
 *   @0x24bcf8 ldr r2, [sp, #0x7c]
 *   @0x24bcfc ldr r3, [r12]
 *   @0x24bd00 cmp r2, r3
 *   @0x24bd04 bne 0x24bd10 <_Z24JS_Array_prototype_sliceR6RValueP9CInstanceS2_iPS_+0x210>
 *   @0x24bd08 add sp, sp, #132
 *   @0x24bd0c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24bd10 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x24bd14 andseq r1, r10, r8, asr #28
 *   @0x24bd18 andeq r4, lr, r12, lsl sp
 *   @0x24bd1c andseq r10, r0, r12, lsr r2
 *
 * ══ §20/57 png_read_start_row  0x2ae494  size 544  136 条（0x2ae494..0x2ae6b4）
 * @func 0x2ae494 0x2ae6b4  size 544  136 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_init_read_transformations / 0x33ac9c / 0x3bad54 / 0x73aa82 / png_calloc / 0xb65b0
 * 字段偏移 top8: 0x210×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ae494 push {r4, r5, r6, r7, lr}
 *   @0x2ae498 ldr r6, [pc, #0x210]
 *   @0x2ae49c add r6, pc
 *   @0x2ae4a0 add.w r7, r6, #0x24
 *   @0x2ae4a4 adds r6, #0x8
 *   @0x2ae4a8 stm r5!, {r0, r1, r2, r3}
 *   @0x2ae4ac stm r5, {r0, r1, r2}
 *   @0x2ae4b0 stcge p0, c0, [r7, #-28]
 *   @0x2ae4b4 ldm r6!, {r0, r1, r2, r3}
 *   @0x2ae4b8 movs r3, #0x0
 *   @0x2ae4bc .word 0xf8c40007
 *   @0x2ae4c0 stm r5, {r2, r3, r4, r5, r8, r12, sp}
 *   @0x2ae4c4 strtmi r0, [r0], -r7
 *   @0x2ae4c8 bl 0x2ab178 <png_init_read_transformations>
 *   @0x2ae4cc ldrb.w r2, [r4, #0x1e7]
 *   @0x2ae4d0 ldr.w r5, [r4, #0x134]
 *   @0x2ae4d4 ldr.w r3, [r4, #0x190]
 *   @0x2ae4d8 ldr.w r6, [r4, #0x18c]
 *   @0x2ae4dc cbz r2, 0x2ae510 <png_read_start_row+0x7c>
 *   @0x2ae4e0 add r2, sp, #0x38
 *   @0x2ae4e4 addpl r3, #0x7
 *   @0x2ae4e8 svclt #0x5830ff
 *   @0x2ae4ec lsrpl r3, r3, #0x3
 *   @0x2ae4f0 .word 0xf8943194
 *   @0x2ae4f4 bl 0x33ac9c
 *   @0x2ae4f8 .word 0xf8530383
 *   @0x2ae4fc .word 0xf8531c1c
 *   @0x2ae500 strmi r3, [r8], #-3128
 *   @0x2ae504 subs r0, r0, r3
 *   @0x2ae508 .word 0xf8c4eba0
 *   @0x2ae50c and r0, r3, r4, lsr #3
 *   @0x2ae510 str.w r3, [r4, #0x194]
 *   @0x2ae514 str.w r6, [r4, #0x1a4]
 *   @0x2ae518 lsls r7, r5, #0x1d
 *   @0x2ae51c strle r0, [r4, #-0x1ed]
 *   @0x2ae520 ldrb.w r3, [r4, #0x1eb]
 *   @0x2ae524 cmp r3, #0x7
 *   @0x2ae528 movls r0, #0x8
 *   @0x2ae52c andsle r5, r12, r0, lsl #15
 *   @0x2ae530 ldrb.w r3, [r4, #0x1ea]
 *   @0x2ae534 cmp r3, #0x3
 *   @0x2ae538 ldrh.w r0, [r4, #0x1de]
 *   @0x2ae53c cmp r0, #0x0
 *   @0x2ae540 moveq r0, #0x18
 *   @0x2ae544 b 0x2ae56a <png_read_start_row+0xd6>
 *   @0x2ae548 ldrh.w r3, [r4, #0x1de]
 *   @0x2ae54c cmp r0, #0x8
 *   @0x2ae550 movlt r0, #0x8
 *   @0x2ae554 lsls r0, r0, #0x1
 *   @0x2ae558 cmp r3, #0x2
 *   @0x2ae55c ldrh.w r3, [r4, #0x1de]
 *   @0x2ae560 cbz r3, 0x2ae56a <png_read_start_row+0xd6>
 *   @0x2ae564 movs r1, #0x3
 *   @0x2ae568 .word 0xf415ebd4
 *   @0x2ae56c andsle r4, r1, r0, lsl #4
 *   @0x2ae570 ldrb.w r3, [r4, #0x1ea]
 *   @0x2ae574 cmp r3, #0x3
 *   @0x2ae578 cbnz r3, 0x2ae584 <png_read_start_row+0xf0>
 *   @0x2ae57c ite gt
 *   @0x2ae580 movle r0, #0x10
 *   @0x2ae584 cmp r3, #0x2
 *   @0x2ae588 cmp r0, #0x20
 *   @0x2ae58c movgt r0, #0x40
 *   @0x2ae590 b 0x2ae594 <png_read_start_row+0x100>
 *   @0x2ae594 lsls r1, r5, #0x11
 *   @0x2ae598 ldrh.w r3, [r4, #0x1de]
 *   @0x2ae59c cbz r3, 0x2ae5a0 <png_read_start_row+0x10c>
 *   @0x2ae5a0 cbnz r2, 0x2ae5aa <png_read_start_row+0x116>
 *   @0x2ae5a4 blhs 0x3bad54 <error_g0017+0x139f8>
 *   @0x2ae5a8 bne 0x2ae5b4 <png_read_start_row+0x120>
 *   @0x2ae5ac ite gt
 *   @0x2ae5b0 movle r0, #0x20
 *   @0x2ae5b4 cmp r0, #0x8
 *   @0x2ae5b8 cmp r3, #0x6
 *   @0x2ae5bc movne r0, #0x18
 *   @0x2ae5c0 b 0x2ae5ca <png_read_start_row+0x136>
 *   @0x2ae5c4 ite ne
 *   @0x2ae5c8 moveq r0, #0x40
 *   @0x2ae5cc bpl 0x2ae5e0 <png_read_start_row+0x14c>
 *   @0x2ae5d0 .word 0xf8942128
 *   @0x2ae5d4 blx 0x73aa82 <g_SWFvertbuff+0x679ba>
 *   @0x2ae5d8 addsmi pc, r8, #201326592
 *   @0x2ae5dc it lt
 *   @0x2ae5e0 adds r6, #0x7
 *   @0x2ae5e4 bic r6, r6, #0x7
 *   @0x2ae5e8 it gt
 *   @0x2ae5ec ldr.w r3, [r4, #0x328]
 *   @0x2ae5f0 it le
 *   @0x2ae5f4 .word 0xf100f500
 *   @0x2ae5f8 svclt #0xcc0007
 *   @0x2ae5fc mulgt r5, r6, r5
 *   @0x2ae600 adds r5, #0x1
 *   @0x2ae604 ldrlo r0, [r0, #-0x5e0]!
 *   @0x2ae608 cmp r5, r3
 *   @0x2ae60c mov r0, r4
 *   @0x2ae610 .word 0xf7f812f4
 *   @0x2ae614 .word 0xf894fb73
 *   @0x2ae618 strtmi r3, [r0], -r7, ror #3
 *   @0x2ae61c mov r1, r5
 *   @0x2ae620 bl 0x2a6cd8 <png_calloc>
 *   @0x2ae624 b 0x2ae62a <png_read_start_row+0x196>
 *   @0x2ae628 .word 0xf8c4fb3b
 *   @0x2ae62c .word 0xf8d402f4
 *   @0x2ae630 .word 0xf8c432f4
 *   @0x2ae634 .word 0xf1035328
 *   @0x2ae638 .word 0xf002020f
 *   @0x2ae63c .word 0xf1c2020f
 *   @0x2ae640 ldrmi r0, [r3], #-544
 *   @0x2ae644 str.w r3, [r4, #0x1b0]
 *   @0x2ae648 ldr.w r3, [r4, #0x19c]
 *   @0x2ae64c adds r3, #0x1
 *   @0x2ae650 ldr r1, [pc, #0x5c]
 *   @0x2ae654 add r1, pc
 *   @0x2ae658 .word 0xf8d4fee9
 *   @0x2ae65c mrrcne p1, #0x9, r3, r10, c12
 *   @0x2ae660 ldr.w r3, [r4, #0x32c]
 *   @0x2ae664 cmp r2, r3
 *   @0x2ae668 mov r0, r4
 *   @0x2ae66c .word 0xf7f811ac
 *   @0x2ae670 .word 0xf8d4fb45
 *   @0x2ae674 qadd8mi r1, r0, r12
 *   @0x2ae678 adds r1, #0x1
 *   @0x2ae67c .word 0xf8d4fb11
 *   @0x2ae680 movwlo r3, #0x119c
 *   @0x2ae684 str.w r3, [r4, #0x32c]
 *   @0x2ae688 str.w r0, [r4, #0x1ac]
 *   @0x2ae68c ldr.w r2, [r4, #0x19c]
 *   @0x2ae690 movs r1, #0x0
 *   @0x2ae694 andlo r0, r1, #172, #2
 *   @0x2ae698 blx 0xb65b0 <memset@plt>
 *   @0x2ae69c ldr.w r3, [r4, #0x130]
 *   @0x2ae6a0 orr r3, r3, #0x40
 *   @0x2ae6a4 str.w r3, [r4, #0x130]
 *   @0x2ae6a8 add sp, #0x3c
 *   @0x2ae6ac asrs r4, r1, #0x15
 *   @0x2ae6b0 .word 0xf3f5 000d
 *
 * ══ §21/57 DGifGetScreenDesc(GifFileType*)  0x2c1a30  size 544  136 条（0x2c1a30..0x2c1c50）
 * @func 0x2c1a30 0x2c1c50  size 544  136 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2c143c×2 / 0xb68c8×2 / GifFreeMapObject(ColorMapObject*)×2 / GifMakeMapObject(int, GifColorType const*) / DGifGetScreenDesc(GifFileType*)+0xc4
 * 字段偏移 top8: 0x14×9 / 0xc×4 / 0x48×3 / 0x3c×2 / 0x4×2 / 0x5×2 / 0x6×2 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c1a30 ldr r3, [r0, #0x48]
 *   @0x2c1a34 push {r4, r5, r6, r7, lr}
 *   @0x2c1a38 mov r4, r0
 *   @0x2c1a3c ldr r3, [r3]
 *   @0x2c1a40 sub sp, sp, #12
 *   @0x2c1a44 ands r3, r3, #8
 *   @0x2c1a48 moveq r2, #111
 *   @0x2c1a4c streq r2, [r0, #0x40]
 *   @0x2c1a50 bne 0x2c1a60 <_Z17DGifGetScreenDescP11GifFileType+0x30>
 *   @0x2c1a54 mov r0, r3
 *   @0x2c1a58 add sp, sp, #12
 *   @0x2c1a5c pop {r4, r5, r6, r7, pc}
 *   @0x2c1a60 mov r1, r0
 *   @0x2c1a64 bl 0x2c143c <jpeg_mem_term+0x4>
 *   @0x2c1a68 cmp r0, #0
 *   @0x2c1a6c bne 0x2c1a80 <_Z17DGifGetScreenDescP11GifFileType+0x50>
 *   @0x2c1a70 mov r3, #0
 *   @0x2c1a74 mov r0, r3
 *   @0x2c1a78 add sp, sp, #12
 *   @0x2c1a7c pop {r4, r5, r6, r7, pc}
 *   @0x2c1a80 mov r0, r4
 *   @0x2c1a84 add r1, r4, #4
 *   @0x2c1a88 bl 0x2c143c <jpeg_mem_term+0x4>
 *   @0x2c1a8c cmp r0, #0
 *   @0x2c1a90 beq 0x2c1a70 <_Z17DGifGetScreenDescP11GifFileType+0x40>
 *   @0x2c1a94 ldr r2, [r4, #0x48]
 *   @0x2c1a98 ldr r3, [r2, #0x3c]
 *   @0x2c1a9c cmp r3, #0
 *   @0x2c1aa0 beq 0x2c1b04 <_Z17DGifGetScreenDescP11GifFileType+0xd4>
 *   @0x2c1aa4 add r6, sp, #4
 *   @0x2c1aa8 mov r0, r4
 *   @0x2c1aac mov r2, #3
 *   @0x2c1ab0 mov r1, r6
 *   @0x2c1ab4 blx r3
 *   @0x2c1ab8 subs r5, r0, #3
 *   @0x2c1abc movne r5, #1
 *   @0x2c1ac0 cmp r5, #0
 *   @0x2c1ac4 bne 0x2c1b28 <_Z17DGifGetScreenDescP11GifFileType+0xf8>
 *   @0x2c1ac8 ldrb r7, [sp, #0x4]
 *   @0x2c1acc ldrb r1, [sp, #0x5]
 *   @0x2c1ad0 ldrb r3, [sp, #0x6]
 *   @0x2c1ad4 tst r7, #128
 *   @0x2c1ad8 ubfx r2, r7, #0x4, #0x3
 *   @0x2c1adc streq r5, [r4, #0x14]
 *   @0x2c1ae0 add r2, r2, #1
 *   @0x2c1ae4 str r1, [r4, #0xc]
 *   @0x2c1ae8 str r2, [r4, #0x8]
 *   @0x2c1aec strb r3, [r4, #0x10]
 *   @0x2c1af0 bne 0x2c1b48 <_Z17DGifGetScreenDescP11GifFileType+0x118>
 *   @0x2c1af4 mov r3, #1
 *   @0x2c1af8 mov r0, r3
 *   @0x2c1afc add sp, sp, #12
 *   @0x2c1b00 pop {r4, r5, r6, r7, pc}
 *   @0x2c1b04 add r6, sp, #4
 *   @0x2c1b08 ldr r3, [r2, #0x38]
 *   @0x2c1b0c mov r1, #1
 *   @0x2c1b10 mov r2, #3
 *   @0x2c1b14 mov r0, r6
 *   @0x2c1b18 bl 0xb68c8 <fread@plt>
 *   @0x2c1b1c subs r5, r0, #3
 *   @0x2c1b20 movne r5, #1
 *   @0x2c1b24 b 0x2c1ac0 <_Z17DGifGetScreenDescP11GifFileType+0x90>
 *   @0x2c1b28 mov r3, #102
 *   @0x2c1b2c ldr r0, [r4, #0x14]
 *   @0x2c1b30 str r3, [r4, #0x40]
 *   @0x2c1b34 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject>
 *   @0x2c1b38 mov r2, #0
 *   @0x2c1b3c mov r3, r2
 *   @0x2c1b40 str r2, [r4, #0x14]
 *   @0x2c1b44 b 0x2c1a54 <_Z17DGifGetScreenDescP11GifFileType+0x24>
 *   @0x2c1b48 and r3, r7, #7
 *   @0x2c1b4c mov r0, #1
 *   @0x2c1b50 add r3, r3, r0
 *   @0x2c1b54 mov r1, r5
 *   @0x2c1b58 lsl r0, r0, r3
 *   @0x2c1b5c bl 0x2c2bb0 <_Z16GifMakeMapObjectiPK12GifColorType>
 *   @0x2c1b60 cmp r0, #0
 *   @0x2c1b64 str r0, [r4, #0x14]
 *   @0x2c1b68 moveq r2, #109
 *   @0x2c1b6c moveq r3, r5
 *   @0x2c1b70 streq r2, [r4, #0x40]
 *   @0x2c1b74 beq 0x2c1a54 <_Z17DGifGetScreenDescP11GifFileType+0x24>
 *   @0x2c1b78 ldr r3, [r0]
 *   @0x2c1b7c ubfx r7, r7, #0x3, #0x1
 *   @0x2c1b80 strb r7, [r0, #0x8]
 *   @0x2c1b84 cmp r3, #0
 *   @0x2c1b88 bgt 0x2c1bf4 <_Z17DGifGetScreenDescP11GifFileType+0x1c4>
 *   @0x2c1b8c b 0x2c1af4 <_Z17DGifGetScreenDescP11GifFileType+0xc4>
 *   @0x2c1b90 blx r3
 *   @0x2c1b94 subs r0, r0, #3
 *   @0x2c1b98 movne r0, #1
 *   @0x2c1b9c cmp r0, #0
 *   @0x2c1ba0 add r3, r5, r5, lsl #1
 *   @0x2c1ba4 add r5, r5, #1
 *   @0x2c1ba8 bne 0x2c1c30 <_Z17DGifGetScreenDescP11GifFileType+0x200>
 *   @0x2c1bac ldr r2, [r4, #0x14]
 *   @0x2c1bb0 ldrb r1, [sp, #0x4]
 *   @0x2c1bb4 ldr r2, [r2, #0xc]
 *   @0x2c1bb8 strb r1, [r2, r3]
 *   @0x2c1bbc ldr r2, [r4, #0x14]
 *   @0x2c1bc0 ldrb r1, [sp, #0x5]
 *   @0x2c1bc4 ldr r2, [r2, #0xc]
 *   @0x2c1bc8 add r2, r2, r3
 *   @0x2c1bcc strb r1, [r2, #0x1]
 *   @0x2c1bd0 ldr r1, [r4, #0x14]
 *   @0x2c1bd4 ldrb r2, [sp, #0x6]
 *   @0x2c1bd8 ldr r1, [r1, #0xc]
 *   @0x2c1bdc add r3, r1, r3
 *   @0x2c1be0 strb r2, [r3, #0x2]
 *   @0x2c1be4 ldr r3, [r4, #0x14]
 *   @0x2c1be8 ldr r3, [r3]
 *   @0x2c1bec cmp r3, r5
 *   @0x2c1bf0 ble 0x2c1af4 <_Z17DGifGetScreenDescP11GifFileType+0xc4>
 *   @0x2c1bf4 ldr r12, [r4, #0x48]
 *   @0x2c1bf8 mov r0, r4
 *   @0x2c1bfc mov r1, r6
 *   @0x2c1c00 mov r2, #3
 *   @0x2c1c04 ldr r3, [r12, #0x3c]
 *   @0x2c1c08 cmp r3, #0
 *   @0x2c1c0c bne 0x2c1b90 <_Z17DGifGetScreenDescP11GifFileType+0x160>
 *   @0x2c1c10 ldr r3, [r12, #0x38]
 *   @0x2c1c14 mov r0, r6
 *   @0x2c1c18 mov r1, #1
 *   @0x2c1c1c mov r2, #3
 *   @0x2c1c20 bl 0xb68c8 <fread@plt>
 *   @0x2c1c24 subs r0, r0, #3
 *   @0x2c1c28 movne r0, #1
 *   @0x2c1c2c b 0x2c1b9c <_Z17DGifGetScreenDescP11GifFileType+0x16c>
 *   @0x2c1c30 ldr r0, [r4, #0x14]
 *   @0x2c1c34 bl 0x2c2c48 <_Z16GifFreeMapObjectP14ColorMapObject>
 *   @0x2c1c38 mov r2, #0
 *   @0x2c1c3c mov r3, r2
 *   @0x2c1c40 str r2, [r4, #0x14]
 *   @0x2c1c44 mov r2, #102
 *   @0x2c1c48 str r2, [r4, #0x40]
 *   @0x2c1c4c b 0x2c1a54 <_Z17DGifGetScreenDescP11GifFileType+0x24>
 *
 * ══ §22/57 b2Body::Dump()  0x2c75b4  size 544  136 条（0x2c75b4..0x2c77d4）
 * @func 0x2c75b4 0x2c77d4  size 544  136 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×19 / b2Fixture::Dump(int)
 * 字段偏移 top8: 0x4×6 / 0x8×2 / 0x1b0×2 / 0x1c0×1 / 0x1b4×1 / 0x1a4×1 / 0x188×1 / 0x16c×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c75b4 push {r4, r5, r6, r7, lr}
 *   @0x2c75b8 mov r4, r0
 *   @0x2c75bc ldr r0, [pc, #0x1c0]
 *   @0x2c75c0 sub sp, sp, #12
 *   @0x2c75c4 ldr r5, [r4, #0x8]
 *   @0x2c75c8 add r0, pc, r0
 *   @0x2c75cc ldr r7, [pc, #0x1b4]
 *   @0x2c75d0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c75d4 ldr r0, [pc, #0x1b0]
 *   @0x2c75d8 ldr r6, [pc, #0x1b0]
 *   @0x2c75dc add r7, pc, r7
 *   @0x2c75e0 add r0, pc, r0
 *   @0x2c75e4 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c75e8 ldr r0, [pc, #0x1a4]
 *   @0x2c75ec ldr r1, [r4]
 *   @0x2c75f0 add r6, pc, r6
 *   @0x2c75f4 add r0, pc, r0
 *   @0x2c75f8 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c75fc vldr s13, [r4, #12]
 *   @0x2c7600 vldr s14, [r4, #16]
 *   @0x2c7604 vcvt.f64.f32 d5, s13
 *   @0x2c7608 ldr r0, [pc, #0x188]
 *   @0x2c760c add r0, pc, r0
 *   @0x2c7610 vcvt.f64.f32 d7, s14
 *   @0x2c7614 vmov r2, r3, d5
 *   @0x2c7618 vstr d7, [sp]
 *   @0x2c761c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c7620 vldr s15, [r4, #72]
 *   @0x2c7624 vcvt.f64.f32 d6, s15
 *   @0x2c7628 ldr r0, [pc, #0x16c]
 *   @0x2c762c add r0, pc, r0
 *   @0x2c7630 vmov r2, r3, d6
 *   @0x2c7634 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c7638 vldr s13, [r4, #80]
 *   @0x2c763c vldr s14, [r4, #84]
 *   @0x2c7640 vcvt.f64.f32 d5, s13
 *   @0x2c7644 ldr r0, [pc, #0x154]
 *   @0x2c7648 add r0, pc, r0
 *   @0x2c764c vcvt.f64.f32 d7, s14
 *   @0x2c7650 vmov r2, r3, d5
 *   @0x2c7654 vstr d7, [sp]
 *   @0x2c7658 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c765c vldr s15, [r4, #88]
 *   @0x2c7660 vcvt.f64.f32 d6, s15
 *   @0x2c7664 ldr r0, [pc, #0x138]
 *   @0x2c7668 add r0, pc, r0
 *   @0x2c766c vmov r2, r3, d6
 *   @0x2c7670 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c7674 vldr s15, [r4, #148]
 *   @0x2c7678 vcvt.f64.f32 d5, s15
 *   @0x2c767c ldr r0, [pc, #0x124]
 *   @0x2c7680 add r0, pc, r0
 *   @0x2c7684 vmov r2, r3, d5
 *   @0x2c7688 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c768c vldr s15, [r4, #152]
 *   @0x2c7690 vcvt.f64.f32 d6, s15
 *   @0x2c7694 ldr r0, [pc, #0x110]
 *   @0x2c7698 add r0, pc, r0
 *   @0x2c769c vmov r2, r3, d6
 *   @0x2c76a0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c76a4 ldrh r1, [r4, #4]
 *   @0x2c76a8 ldr r0, [pc, #0x100]
 *   @0x2c76ac and r1, r1, #4
 *   @0x2c76b0 add r0, pc, r0
 *   @0x2c76b4 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c76b8 ldrh r1, [r4, #4]
 *   @0x2c76bc ldr r0, [pc, #0xf0]
 *   @0x2c76c0 and r1, r1, #2
 *   @0x2c76c4 add r0, pc, r0
 *   @0x2c76c8 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c76cc ldrh r1, [r4, #4]
 *   @0x2c76d0 ldr r0, [pc, #0xe0]
 *   @0x2c76d4 and r1, r1, #16
 *   @0x2c76d8 add r0, pc, r0
 *   @0x2c76dc bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c76e0 ldrh r1, [r4, #4]
 *   @0x2c76e4 ldr r0, [pc, #0xd0]
 *   @0x2c76e8 and r1, r1, #8
 *   @0x2c76ec add r0, pc, r0
 *   @0x2c76f0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c76f4 ldrh r1, [r4, #4]
 *   @0x2c76f8 ldr r0, [pc, #0xc0]
 *   @0x2c76fc and r1, r1, #32
 *   @0x2c7700 add r0, pc, r0
 *   @0x2c7704 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c7708 vldr s15, [r4, #156]
 *   @0x2c770c vcvt.f64.f32 d5, s15
 *   @0x2c7710 ldr r0, [pc, #0xac]
 *   @0x2c7714 add r0, pc, r0
 *   @0x2c7718 vmov r2, r3, d5
 *   @0x2c771c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c7720 ldr r0, [pc, #0xa0]
 *   @0x2c7724 ldr r1, [r4, #0x8]
 *   @0x2c7728 add r0, pc, r0
 *   @0x2c772c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c7730 ldr r0, [pc, #0x94]
 *   @0x2c7734 add r0, pc, r0
 *   @0x2c7738 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c773c ldr r4, [r4, #0x74]
 *   @0x2c7740 cmp r4, #0
 *   @0x2c7744 beq 0x2c7770 <_ZN6b2Body4DumpEv+0x1bc>
 *   @0x2c7748 mov r0, r7
 *   @0x2c774c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c7750 mov r0, r4
 *   @0x2c7754 mov r1, r5
 *   @0x2c7758 bl 0x2c89f4 <_ZN9b2Fixture4DumpEi>
 *   @0x2c775c mov r0, r6
 *   @0x2c7760 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c7764 ldr r4, [r4, #0x4]
 *   @0x2c7768 cmp r4, #0
 *   @0x2c776c bne 0x2c7748 <_ZN6b2Body4DumpEv+0x194>
 *   @0x2c7770 ldr r0, [pc, #0x58]
 *   @0x2c7774 add r0, pc, r0
 *   @0x2c7778 add sp, sp, #12
 *   @0x2c777c pop {r4, r5, r6, r7, lr}
 *   @0x2c7780 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c7784 andeq r4, r9, r8, lsl #3
 *   @0x2c7788 andeq r4, r9, r12, asr r3
 *   @0x2c778c andeq r4, r9, r4, ror r1
 *   @0x2c7790 andeq r4, r9, r0, asr r3
 *   @0x2c7794 andeq r4, r9, r4, ror r1
 *   @0x2c7798 andeq r4, r9, r12, ror r1
 *   @0x2c779c andeq r4, r9, r4, lsl #3
 *   @0x2c77a0 andeq r4, r9, r0, lsl #3
 *   @0x2c77a4 andeq r4, r9, r12, lsl #3
 *   @0x2c77a8 muleq r9, r8, r1
 *   @0x2c77ac andeq r4, r9, r0, lsr #3
 *   @0x2c77b0 andeq r4, r9, r8, lsr #3
 *   @0x2c77b4 strheq r4, [r9], -r4
 *   @0x2c77b8 strheq r4, [r9], -r8
 *   @0x2c77bc andeq r4, r9, r4, asr #3
 *   @0x2c77c0 andeq r4, r9, r12, asr #3
 *   @0x2c77c4 ldrdeq r4, r5, [r9], -r4
 *   @0x2c77c8 andeq r4, r9, r0, ror #3
 *   @0x2c77cc andeq r11, r6, r4, ror #10
 *   @0x2c77d0 andeq r4, r9, r0, asr #3
 *
 * ══ §23/57 F_YoYo_CloudFileSave(RValue&, CInstance*, CInstance*, int, RValue*)  0x1568e8  size 540  135 条（0x1568e8..0x156b04）
 * @func 0x1568e8 0x156b04  size 540  135 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x156a38→0x5356b4, 0x156aa0→0x3eb70c, 0x156ac8→0x3eb70c
 * 调用序列: Error_Show_Action(char const*, bool)×2 / YYGetString(RValue const*, int)×2 / 0xb68d4×2 / LoadSave::SaveFileExists(char const*) / LoadSave::BundleFileExists(char const*) / LoadSave::_GetBundleFileName(char*, int, char const*) / 0xb6844 / 0xb68e0
 * 字段偏移 top8: 0xc×3 / 0x404×2 / 0x1e0×1 / 0x1dc×1 / 0x428×1 / 0x4×1 / 0x1ac×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1568e8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1568ec cmp r3, #2
 *   @0x1568f0 ldr r5, [pc, #0x1e0]
 *   @0x1568f4 sub sp, sp, #1024
 *   @0x1568f8 ldr r3, [pc, #0x1dc]
 *   @0x1568fc sub sp, sp, #8
 *   @0x156900 add r5, pc, r5
 *   @0x156904 mov r1, #0
 *   @0x156908 mov r4, r0
 *   @0x15690c ldr r7, [sp, #0x428]
 *   @0x156910 ldr r6, [r5, r3]
 *   @0x156914 str r1, [r0, #0xc]
 *   @0x156918 str r1, [r0, #0x4]
 *   @0x15691c ldr r3, [r6]
 *   @0x156920 str r1, [r0]
 *   @0x156924 str r3, [sp, #0x404]
 *   @0x156928 beq 0x156954 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x15692c ldr r0, [pc, #0x1ac]
 *   @0x156930 add r0, pc, r0
 *   @0x156934 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x156938 ldr r2, [sp, #0x404]
 *   @0x15693c ldr r3, [r6]
 *   @0x156940 cmp r2, r3
 *   @0x156944 bne 0x156ad4 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x1ec>
 *   @0x156948 add sp, sp, #1024
 *   @0x15694c add sp, sp, #8
 *   @0x156950 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x156954 ldr r3, [r7, #0xc]
 *   @0x156958 cmp r3, #1
 *   @0x15695c beq 0x15697c <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x156960 ldr r3, [r7, #0x1c]
 *   @0x156964 cmp r3, #1
 *   @0x156968 beq 0x15697c <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x15696c ldr r0, [pc, #0x170]
 *   @0x156970 add r0, pc, r0
 *   @0x156974 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x156978 b 0x156938 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x15697c mov r1, #0
 *   @0x156980 mov r0, r7
 *   @0x156984 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156988 mov r8, r0
 *   @0x15698c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x156990 cmp r0, #0
 *   @0x156994 bne 0x156a80 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x156998 mov r0, r8
 *   @0x15699c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x1569a0 cmp r0, #0
 *   @0x1569a4 beq 0x156a98 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x1569a8 add r9, sp, #4
 *   @0x1569ac mov r2, r8
 *   @0x1569b0 mov r1, #1024
 *   @0x1569b4 mov r0, r9
 *   @0x1569b8 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x1569bc ldr r1, [pc, #0x124]
 *   @0x1569c0 mov r0, r9
 *   @0x1569c4 add r1, pc, r1
 *   @0x1569c8 bl 0xb6844 <fopen@plt>
 *   @0x1569cc subs r8, r0, #0
 *   @0x1569d0 beq 0x156ac0 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x1569d4 mov r1, #0
 *   @0x1569d8 mov r2, #2
 *   @0x1569dc bl 0xb68d4 <fseek@plt>
 *   @0x1569e0 mov r0, r8
 *   @0x1569e4 bl 0xb68e0 <ftell@plt>
 *   @0x1569e8 mov r1, #0
 *   @0x1569ec mov r2, r1
 *   @0x1569f0 mov r10, r0
 *   @0x1569f4 mov r0, r8
 *   @0x1569f8 bl 0xb68d4 <fseek@plt>
 *   @0x1569fc ldr r1, [pc, #0xe8]
 *   @0x156a00 add r0, r10, #1
 *   @0x156a04 movw r2, #0x3f3
 *   @0x156a08 add r1, pc, r1
 *   @0x156a0c mov r3, #1
 *   @0x156a10 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x156a14 mov r2, r10
 *   @0x156a18 mov r1, #1
 *   @0x156a1c mov r3, r8
 *   @0x156a20 mov r9, r0
 *   @0x156a24 bl 0xb68c8 <fread@plt>
 *   @0x156a28 mov r3, #0
 *   @0x156a2c mov r0, r8
 *   @0x156a30 strb r3, [r9, r10]
 *   @0x156a34 bl 0xb6850 <fclose@plt>
 *   @0x156a38 ldr r3, [pc, #0xb0]
 *   @0x156a3c mov r0, r7
 *   @0x156a40 mov r1, #1
 *   @0x156a44 ldr r3, [r5, r3]
 *   @0x156a48 ldr r7, [r3]
 *   @0x156a4c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156a50 ldr r3, [pc, #0x9c]
 *   @0x156a54 ldr r2, [r5, r3]
 *   @0x156a58 mov r1, r0
 *   @0x156a5c mov r0, r9
 *   @0x156a60 bl 0x1612b0 <_Z17Cloud_String_SavePKcS0_PFiP16HTTP_REQ_CONTEXTPvPiE>
 *   @0x156a64 vmov s15, r7
 *   @0x156a68 mov r0, r9
 *   @0x156a6c vcvt.f64.s32 d7, s15
 *   @0x156a70 vmov r2, r3, d7
 *   @0x156a74 stm r4, {r2, r3}
 *   @0x156a78 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x156a7c b 0x156938 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x156a80 add r9, sp, #4
 *   @0x156a84 mov r2, r8
 *   @0x156a88 mov r1, #1024
 *   @0x156a8c mov r0, r9
 *   @0x156a90 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x156a94 b 0x1569bc <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x156a98 ldr r1, [pc, #0x58]
 *   @0x156a9c mov r2, r8
 *   @0x156aa0 ldr r3, [pc, #0x54]
 *   @0x156aa4 add r1, pc, r1
 *   @0x156aa8 ldr r3, [r5, r3]
 *   @0x156aac ldr r0, [r3]
 *   @0x156ab0 ldr r3, [r0]
 *   @0x156ab4 ldr r3, [r3, #0xc]
 *   @0x156ab8 blx r3
 *   @0x156abc b 0x156938 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x156ac0 ldr r1, [pc, #0x38]
 *   @0x156ac4 mov r2, r9
 *   @0x156ac8 ldr r3, [pc, #0x2c]
 *   @0x156acc add r1, pc, r1
 *   @0x156ad0 b 0x156aa8 <_Z20F_YoYo_CloudFileSaveR6RValueP9CInstanceS2_iPS_+0x1c0>
 *   @0x156ad4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x156ad8 eoreq r11, r9, r0, asr r3
 *   @0x156adc .word 0xffffbd00
 *   @0x156ae0 mulseq lr, r8, r12
 *   @0x156ae4 andseq r12, lr, r12, lsr r0
 *   @0x156ae8 andseq r1, lr, r4, lsr r2
 *   @0x156aec andseq pc, lr, r12, asr r11
 *   @0x156af0 .word 0xffffd628
 *   @0x156af4 .word 0xffffdf08
 *   @0x156af8 andseq r9, lr, r0, lsr r5
 *   @0x156afc .word 0xffffbac4
 *   @0x156b00 andseq r9, lr, r8, lsl #10
 *
 * ══ §24/57 RenderStateManager::Reset()  0x167c34  size 540  135 条（0x167c34..0x167e50）
 * @func 0x167c34 0x167e50  size 540  135 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x167c3c→0x3f23bd, 0x167c44→0x3f23bc, 0x167c58→0x3f23c0, 0x167c60→0x489794, 0x167c94→0x489790, 0x167c9c→0x48978c, 0x167ca4→0x489788, 0x167cb4→0x3f23b8
 * 调用序列: 无
 * 字段偏移 top8: 0x98×2 / 0x9c×2 / 0x80×2 / 0x84×2 / 0x88×2 / 0x94×2 / 0x8c×2 / 0x90×2
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167c34 ldr r3, [pc, #0x1f0]
 *   @0x167c38 mov r2, #1
 *   @0x167c3c ldr r12, [pc, #0x1ec]
 *   @0x167c40 add r3, pc, r3
 *   @0x167c44 ldr r1, [pc, #0x1e8]
 *   @0x167c48 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x167c4c mov r7, r2
 *   @0x167c50 ldr r8, [r3, r12]
 *   @0x167c54 mov r4, #0
 *   @0x167c58 ldr r6, [pc, #0x1d8]
 *   @0x167c5c mov r12, r4
 *   @0x167c60 ldr r5, [pc, #0x1d4]
 *   @0x167c64 strb r2, [r8]
 *   @0x167c68 ldr r1, [r3, r1]
 *   @0x167c6c strb r2, [r1]
 *   @0x167c70 ldr r1, [r3, r6]
 *   @0x167c74 ldr r2, [r3, r5]
 *   @0x167c78 strb r7, [r1, r4]
 *   @0x167c7c mov r6, #1
 *   @0x167c80 strb r12, [r2, r4]
 *   @0x167c84 add r4, r4, r6
 *   @0x167c88 cmp r4, #8
 *   @0x167c8c mov r5, #0
 *   @0x167c90 bne 0x167c78 <_ZN18RenderStateManager5ResetEv+0x44>
 *   @0x167c94 ldr r2, [pc, #0x1a4]
 *   @0x167c98 vldr s15, [pc, #392]
 *   @0x167c9c ldr r8, [pc, #0x1a0]
 *   @0x167ca0 add r12, r0, #12
 *   @0x167ca4 ldr r7, [pc, #0x19c]
 *   @0x167ca8 mov r1, #36
 *   @0x167cac ldr r10, [r3, r2]
 *   @0x167cb0 mov r9, #3
 *   @0x167cb4 ldr r2, [pc, #0x190]
 *   @0x167cb8 mov r11, #1065353216
 *   @0x167cbc strb r5, [r10]
 *   @0x167cc0 mov r10, #2
 *   @0x167cc4 ldr r8, [r3, r8]
 *   @0x167cc8 str r5, [r8]
 *   @0x167ccc mov r8, #6
 *   @0x167cd0 ldr r7, [r3, r7]
 *   @0x167cd4 vstr s15, [r7]
 *   @0x167cd8 ldr r3, [r3, r2]
 *   @0x167cdc mov r7, #5
 *   @0x167ce0 mvn r2, #0
 *   @0x167ce4 str r9, [r0, #0x18]
 *   @0x167ce8 str r9, [r0, #0x6c]
 *   @0x167cec mvn r9, #0
 *   @0x167cf0 str r11, [r3]
 *   @0x167cf4 mvn r3, #0
 *   @0x167cf8 str r5, [r0, #0x14]
 *   @0x167cfc mov r11, #4
 *   @0x167d00 strd r2, r3, [r0]
 *   @0x167d04 strd r2, r3, [r0, #8]
 *   @0x167d08 mov r2, #1065353216
 *   @0x167d0c str r6, [r0, #0x20]
 *   @0x167d10 mov r3, #15
 *   @0x167d14 str r5, [r0, #0x24]
 *   @0x167d18 str r5, [r0, #0x30]
 *   @0x167d1c str r5, [r0, #0x38]
 *   @0x167d20 str r6, [r0, #0x40]
 *   @0x167d24 str r5, [r0, #0x44]
 *   @0x167d28 str r5, [r0, #0x48]
 *   @0x167d2c str r5, [r0, #0x4c]
 *   @0x167d30 str r6, [r0, #0x50]
 *   @0x167d34 str r5, [r0, #0x54]
 *   @0x167d38 str r5, [r0, #0x5c]
 *   @0x167d3c str r5, [r0, #0x60]
 *   @0x167d40 str r5, [r0, #0x64]
 *   @0x167d44 str r5, [r0, #0x68]
 *   @0x167d48 str r10, [r0, #0x1c]
 *   @0x167d4c str r7, [r0, #0x28]
 *   @0x167d50 str r7, [r0, #0x3c]
 *   @0x167d54 str r8, [r0, #0x2c]
 *   @0x167d58 str r11, [r0, #0x34]
 *   @0x167d5c str r2, [r0, #0x58]
 *   @0x167d60 str r3, [r0, #0x70]
 *   @0x167d64 str r7, [r0, #0x98]
 *   @0x167d68 str r8, [r0, #0x9c]
 *   @0x167d6c str r5, [r0, #0x74]
 *   @0x167d70 str r6, [r0, #0x78]
 *   @0x167d74 str r6, [r0, #0x7c]
 *   @0x167d78 str r6, [r0, #0x80]
 *   @0x167d7c str r4, [r0, #0x84]
 *   @0x167d80 str r5, [r0, #0x88]
 *   @0x167d84 str r5, [r0, #0x94]
 *   @0x167d88 str r9, [r0, #0x8c]
 *   @0x167d8c str r9, [r0, #0x90]
 *   @0x167d90 ldr r3, [r12, #0x4]!
 *   @0x167d94 subs r1, r1, #1
 *   @0x167d98 str r3, [r12, #0x1d0]
 *   @0x167d9c bne 0x167d90 <_ZN18RenderStateManager5ResetEv+0x15c>
 *   @0x167da0 mov r4, #0
 *   @0x167da4 movt r4, #0x4180
 *   @0x167da8 mov r3, r0
 *   @0x167dac mov r12, #8
 *   @0x167db0 mov r2, #1
 *   @0x167db4 mov r6, #16
 *   @0x167db8 mov r5, #2
 *   @0x167dbc subs r12, r12, #1
 *   @0x167dc0 str r2, [r3, #0xa0]
 *   @0x167dc4 str r2, [r3, #0xa4]
 *   @0x167dc8 add r3, r3, #40
 *   @0x167dcc str r2, [r3, #0x88]
 *   @0x167dd0 str r1, [r3, #0x80]
 *   @0x167dd4 str r1, [r3, #0x84]
 *   @0x167dd8 str r1, [r3, #0x8c]
 *   @0x167ddc str r4, [r3, #0x90]
 *   @0x167de0 str r1, [r3, #0x94]
 *   @0x167de4 str r6, [r3, #0x98]
 *   @0x167de8 str r5, [r3, #0x9c]
 *   @0x167dec bne 0x167dbc <_ZN18RenderStateManager5ResetEv+0x188>
 *   @0x167df0 add r3, r0, #156
 *   @0x167df4 mov r1, #80
 *   @0x167df8 ldr r2, [r3, #0x4]!
 *   @0x167dfc subs r1, r1, #1
 *   @0x167e00 str r2, [r3, #0x1d0]
 *   @0x167e04 bne 0x167df8 <_ZN18RenderStateManager5ResetEv+0x1c4>
 *   @0x167e08 movw r4, #0x3db8
 *   @0x167e0c mov r12, #944
 *   @0x167e10 str r1, [r0, r4]
 *   @0x167e14 mvn r2, #0
 *   @0x167e18 mvn r3, #0
 *   @0x167e1c strd r2, r3, [r0, r12]
 *   @0x167e20 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x167e24 bx lr
 *   @0x167e28 andeq r0, r0, r0
 *   @0x167e2c eoreq r10, r8, r0, lsl r0
 *   @0x167e30 .word 0xffffe4b0
 *   @0x167e34 .word 0xffffe4b4
 *   @0x167e38 .word 0xffffe4b8
 *   @0x167e3c .word 0xffffe4bc
 *   @0x167e40 .word 0xffffe4c0
 *   @0x167e44 .word 0xffffe4c4
 *   @0x167e48 .word 0xffffe4c8
 *   @0x167e4c .word 0xffffe4cc
 *
 * ══ §25/57 CTimeLine::AddMomentScript(int, int)  0x1f1d80  size 540  135 条（0x1f1d80..0x1f1f9c）
 * @func 0x1f1d80 0x1f1f9c  size 540  135 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / CTimeLine::FindSmaller(double) / CTimeLine::AddMomentScript(int, int)+0x18c / CTimeLine::AddMomentScript(int, int)+0x13c / CTimeLine::AddMomentScript(int, int)+0xd4
 * 字段偏移 top8: 0xc×8 / 0x14×5 / 0x2×4 / 0x10×3 / 0x-4×3 / 0x8×3 / 0x1b8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f1d80 vmov s15, r1
 *   @0x1f1d84 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f1d88 vcvt.f64.s32 d7, s15
 *   @0x1f1d8c sub sp, sp, #12
 *   @0x1f1d90 mov r7, r2
 *   @0x1f1d94 mov r8, r1
 *   @0x1f1d98 mov r5, r0
 *   @0x1f1d9c vmov r2, r3, d7
 *   @0x1f1da0 bl 0x1f1d04 <_ZN9CTimeLine11FindSmallerEd>
 *   @0x1f1da4 cmn r0, #1
 *   @0x1f1da8 beq 0x1f1db8 <_ZN9CTimeLine15AddMomentScriptEii+0x38>
 *   @0x1f1dac ldr r4, [r5, #0x10]
 *   @0x1f1db0 cmp r0, r4
 *   @0x1f1db4 blt 0x1f1f0c <_ZN9CTimeLine15AddMomentScriptEii+0x18c>
 *   @0x1f1db8 ldr r4, [r5, #0x10]
 *   @0x1f1dbc add r6, r0, #1
 *   @0x1f1dc0 ldr r3, [r5, #0x14]
 *   @0x1f1dc4 adds r9, r4, #1
 *   @0x1f1dc8 beq 0x1f1f28 <_ZN9CTimeLine15AddMomentScriptEii+0x1a8>
 *   @0x1f1dcc lsls r1, r9, #2
 *   @0x1f1dd0 beq 0x1f1f74 <_ZN9CTimeLine15AddMomentScriptEii+0x1f4>
 *   @0x1f1dd4 ldr r2, [pc, #0x1b8]
 *   @0x1f1dd8 mov r0, r3
 *   @0x1f1ddc mov r3, #0
 *   @0x1f1de0 str r3, [sp]
 *   @0x1f1de4 add r2, pc, r2
 *   @0x1f1de8 mov r3, #106
 *   @0x1f1dec bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f1df0 mov r2, r0
 *   @0x1f1df4 str r0, [r5, #0x14]
 *   @0x1f1df8 cmp r6, r4
 *   @0x1f1dfc str r9, [r5, #0x10]
 *   @0x1f1e00 addlt r3, r2, r4, lsl #2
 *   @0x1f1e04 bge 0x1f1e1c <_ZN9CTimeLine15AddMomentScriptEii+0x9c>
 *   @0x1f1e08 sub r4, r4, #1
 *   @0x1f1e0c ldr r0, [r3, #-0x4]
 *   @0x1f1e10 cmp r4, r6
 *   @0x1f1e14 str r0, [r3], #-4
 *   @0x1f1e18 bne 0x1f1e08 <_ZN9CTimeLine15AddMomentScriptEii+0x88>
 *   @0x1f1e1c str r8, [r2, r6, lsl #2]
 *   @0x1f1e20 lsl r7, r7, #1
 *   @0x1f1e24 ldr r4, [r5, #0x8]
 *   @0x1f1e28 orr r7, r7, #1
 *   @0x1f1e2c adds r9, r4, #1
 *   @0x1f1e30 mov r12, r4
 *   @0x1f1e34 bne 0x1f1f44 <_ZN9CTimeLine15AddMomentScriptEii+0x1c4>
 *   @0x1f1e38 ldr r3, [r5, #0xc]
 *   @0x1f1e3c cmp r3, #0
 *   @0x1f1e40 beq 0x1f1ebc <_ZN9CTimeLine15AddMomentScriptEii+0x13c>
 *   @0x1f1e44 cmp r4, #0
 *   @0x1f1e48 ble 0x1f1ebc <_ZN9CTimeLine15AddMomentScriptEii+0x13c>
 *   @0x1f1e4c mov r8, r9
 *   @0x1f1e50 mov r11, r9
 *   @0x1f1e54 ldr r0, [r3]
 *   @0x1f1e58 movw r2, #0xfeee
 *   @0x1f1e5c movt r2, #0xfeee
 *   @0x1f1e60 movw r1, #0xfeee
 *   @0x1f1e64 cmp r0, r2
 *   @0x1f1e68 movt r1, #0xfeee
 *   @0x1f1e6c lsl r10, r8, #2
 *   @0x1f1e70 beq 0x1f1eb0 <_ZN9CTimeLine15AddMomentScriptEii+0x130>
 *   @0x1f1e74 ldr r2, [r3, r8, lsl #2]
 *   @0x1f1e78 add lr, r3, r10
 *   @0x1f1e7c cmp r2, #0
 *   @0x1f1e80 mov r0, r2
 *   @0x1f1e84 beq 0x1f1eb0 <_ZN9CTimeLine15AddMomentScriptEii+0x130>
 *   @0x1f1e88 ldr r3, [r2]
 *   @0x1f1e8c cmp r3, r1
 *   @0x1f1e90 beq 0x1f1ea8 <_ZN9CTimeLine15AddMomentScriptEii+0x128>
 *   @0x1f1e94 ldr r3, [r3, #0x4]
 *   @0x1f1e98 blx r3
 *   @0x1f1e9c ldr lr, [r5, #0xc]
 *   @0x1f1ea0 ldr r12, [r5, #0x8]
 *   @0x1f1ea4 add lr, lr, r10
 *   @0x1f1ea8 str r11, [lr]
 *   @0x1f1eac ldr r3, [r5, #0xc]
 *   @0x1f1eb0 add r8, r8, #1
 *   @0x1f1eb4 cmp r8, r12
 *   @0x1f1eb8 blt 0x1f1e54 <_ZN9CTimeLine15AddMomentScriptEii+0xd4>
 *   @0x1f1ebc mov r0, r3
 *   @0x1f1ec0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1ec4 mov r3, #0
 *   @0x1f1ec8 mov r1, r3
 *   @0x1f1ecc str r3, [r5, #0xc]
 *   @0x1f1ed0 cmp r6, r4
 *   @0x1f1ed4 str r9, [r5, #0x8]
 *   @0x1f1ed8 bge 0x1f1f00 <_ZN9CTimeLine15AddMomentScriptEii+0x180>
 *   @0x1f1edc lsl r3, r4, #2
 *   @0x1f1ee0 add r0, r1, r3
 *   @0x1f1ee4 sub r4, r4, #1
 *   @0x1f1ee8 cmp r4, r6
 *   @0x1f1eec ldr r0, [r0, #-0x4]
 *   @0x1f1ef0 str r0, [r1, r3]
 *   @0x1f1ef4 sub r3, r3, #4
 *   @0x1f1ef8 ldr r1, [r5, #0xc]
 *   @0x1f1efc bne 0x1f1ee0 <_ZN9CTimeLine15AddMomentScriptEii+0x160>
 *   @0x1f1f00 str r7, [r1, r6, lsl #2]
 *   @0x1f1f04 add sp, sp, #12
 *   @0x1f1f08 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f1f0c ldr r3, [r5, #0x14]
 *   @0x1f1f10 ldr r2, [r3, r0, lsl #2]
 *   @0x1f1f14 cmp r2, r8
 *   @0x1f1f18 beq 0x1f1f04 <_ZN9CTimeLine15AddMomentScriptEii+0x184>
 *   @0x1f1f1c adds r9, r4, #1
 *   @0x1f1f20 add r6, r0, #1
 *   @0x1f1f24 bne 0x1f1dcc <_ZN9CTimeLine15AddMomentScriptEii+0x4c>
 *   @0x1f1f28 cmp r3, #0
 *   @0x1f1f2c beq 0x1f1f74 <_ZN9CTimeLine15AddMomentScriptEii+0x1f4>
 *   @0x1f1f30 mov r0, r3
 *   @0x1f1f34 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1f38 str r9, [r5, #0x14]
 *   @0x1f1f3c mov r2, r9
 *   @0x1f1f40 b 0x1f1df8 <_ZN9CTimeLine15AddMomentScriptEii+0x78>
 *   @0x1f1f44 lsls r1, r9, #2
 *   @0x1f1f48 beq 0x1f1f8c <_ZN9CTimeLine15AddMomentScriptEii+0x20c>
 *   @0x1f1f4c ldr r2, [pc, #0x44]
 *   @0x1f1f50 mov r3, #0
 *   @0x1f1f54 ldr r0, [r5, #0xc]
 *   @0x1f1f58 add r2, pc, r2
 *   @0x1f1f5c str r3, [sp]
 *   @0x1f1f60 mov r3, #135
 *   @0x1f1f64 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f1f68 mov r1, r0
 *   @0x1f1f6c str r0, [r5, #0xc]
 *   @0x1f1f70 b 0x1f1ed0 <_ZN9CTimeLine15AddMomentScriptEii+0x150>
 *   @0x1f1f74 mov r0, r3
 *   @0x1f1f78 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1f7c mov r3, #0
 *   @0x1f1f80 mov r2, r3
 *   @0x1f1f84 str r3, [r5, #0x14]
 *   @0x1f1f88 b 0x1f1df8 <_ZN9CTimeLine15AddMomentScriptEii+0x78>
 *   @0x1f1f8c ldr r3, [r5, #0xc]
 *   @0x1f1f90 b 0x1f1ebc <_ZN9CTimeLine15AddMomentScriptEii+0x13c>
 *   @0x1f1f94 ldrsheq r0, [r6], -r0
 *   @0x1f1f98 andseq r0, r6, r8, lsr r7
 *
 * ══ §26/57 GV_ArgumentCount(CInstance*, int, RValue*)  0x200c88  size 540  135 条（0x200c88..0x200ea4）
 * @func 0x200c88 0x200ea4  size 540  135 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / UNLOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / YYFree(void const*)×2 / operator delete(void*)×2 / GV_ArgumentCount(CInstance*, int, RValue*)+0x140 / GV_ArgumentCount(CInstance*, int, RValue*)+0x1cc / GV_ArgumentCount(CInstance*, int, RValue*)+0x18c
 * 字段偏移 top8: 0x4×11 / 0x8×6 / 0xc×4 / 0x10×3 / 0x1f4×1 / 0x3×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x200c88 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x200c8c mov r6, r2
 *   @0x200c90 ldr r2, [r2, #0xc]
 *   @0x200c94 sub r3, r2, #1
 *   @0x200c98 bic r3, r3, #-16777216
 *   @0x200c9c bics r4, r3, #3
 *   @0x200ca0 beq 0x200ce0 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x58>
 *   @0x200ca4 ldr r3, [pc, #0x1f4]
 *   @0x200ca8 mov r2, #0
 *   @0x200cac str r2, [r6]
 *   @0x200cb0 mov r0, #1
 *   @0x200cb4 ldr r3, [pc, r3]
 *   @0x200cb8 str r2, [r6, #0x8]
 *   @0x200cbc str r2, [r6, #0xc]
 *   @0x200cc0 ldr r4, [r3]
 *   @0x200cc4 vmov s15, r4
 *   @0x200cc8 vcvt.f64.s32 d7, s15
 *   @0x200ccc vmov r4, r5, d7
 *   @0x200cd0 vmov r2, s14
 *   @0x200cd4 mov r3, r5
 *   @0x200cd8 stm r6, {r2, r3}
 *   @0x200cdc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x200ce0 bic r2, r2, #-16777216
 *   @0x200ce4 cmp r2, #2
 *   @0x200ce8 beq 0x200d58 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0xd0>
 *   @0x200cec cmp r2, #3
 *   @0x200cf0 beq 0x200d30 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0xa8>
 *   @0x200cf4 cmp r2, #1
 *   @0x200cf8 bne 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c>
 *   @0x200cfc ldr r4, [r6]
 *   @0x200d00 cmp r4, #0
 *   @0x200d04 beq 0x200d24 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x9c>
 *   @0x200d08 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200d0c ldr r5, [r4, #0x4]
 *   @0x200d10 sub r5, r5, #1
 *   @0x200d14 str r5, [r4, #0x4]
 *   @0x200d18 cmp r5, #0
 *   @0x200d1c beq 0x200d90 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x108>
 *   @0x200d20 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x200d24 mov r3, #0
 *   @0x200d28 str r3, [r6]
 *   @0x200d2c b 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c>
 *   @0x200d30 ldr r3, [r6, #0x8]
 *   @0x200d34 tst r3, #8
 *   @0x200d38 beq 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c>
 *   @0x200d3c ldr r0, [r6]
 *   @0x200d40 cmp r0, #0
 *   @0x200d44 beq 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c>
 *   @0x200d48 ldr r3, [r0]
 *   @0x200d4c ldr r3, [r3, #0x4]
 *   @0x200d50 blx r3
 *   @0x200d54 b 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c>
 *   @0x200d58 ldr r8, [r6]
 *   @0x200d5c cmp r8, #0
 *   @0x200d60 beq 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c>
 *   @0x200d64 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200d68 ldr r3, [r8]
 *   @0x200d6c ldr r2, [r8, #0x8]
 *   @0x200d70 sub r3, r3, #1
 *   @0x200d74 str r3, [r8]
 *   @0x200d78 cmp r6, r2
 *   @0x200d7c streq r4, [r8, #0x8]
 *   @0x200d80 cmp r3, #0
 *   @0x200d84 ble 0x200dc8 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x140>
 *   @0x200d88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x200d8c b 0x200ca4 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1c>
 *   @0x200d90 ldr r0, [r4]
 *   @0x200d94 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x200d98 str r5, [r4]
 *   @0x200d9c str r5, [r4, #0x8]
 *   @0x200da0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x200da4 ldr r5, [r4, #0x4]
 *   @0x200da8 sub r5, r5, #1
 *   @0x200dac str r5, [r4, #0x4]
 *   @0x200db0 cmp r5, #0
 *   @0x200db4 beq 0x200e7c <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1f4>
 *   @0x200db8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x200dbc mov r0, r4
 *   @0x200dc0 bl 0x27d1d0 <_ZdlPv>
 *   @0x200dc4 b 0x200d20 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x98>
 *   @0x200dc8 ldr r3, [r8, #0x10]
 *   @0x200dcc cmp r3, #0
 *   @0x200dd0 movgt r7, #0
 *   @0x200dd4 movgt r11, #5
 *   @0x200dd8 movgt r5, r7
 *   @0x200ddc ble 0x200e54 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1cc>
 *   @0x200de0 ldr r3, [r8, #0x4]
 *   @0x200de4 add r9, r3, r7, lsl #3
 *   @0x200de8 ldr r10, [r3, r7, lsl #3]
 *   @0x200dec ldr r4, [r9, #0x4]
 *   @0x200df0 add r10, r4, r10, lsl #4
 *   @0x200df4 cmp r4, r10
 *   @0x200df8 blo 0x200e14 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x18c>
 *   @0x200dfc b 0x200e74 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1ec>
 *   @0x200e00 str r5, [r4, #0x8]
 *   @0x200e04 str r11, [r4, #0xc]
 *   @0x200e08 str r5, [r4], #16
 *   @0x200e0c cmp r10, r4
 *   @0x200e10 bls 0x200e38 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1b0>
 *   @0x200e14 ldr r3, [r4, #0xc]
 *   @0x200e18 sub r3, r3, #1
 *   @0x200e1c bic r3, r3, #-16777216
 *   @0x200e20 bic r3, r3, #3
 *   @0x200e24 cmp r3, #0
 *   @0x200e28 bne 0x200e00 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x178>
 *   @0x200e2c mov r0, r4
 *   @0x200e30 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x200e34 b 0x200e00 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x178>
 *   @0x200e38 ldr r0, [r9, #0x4]
 *   @0x200e3c bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x200e40 ldr r3, [r8, #0x10]
 *   @0x200e44 add r7, r7, #1
 *   @0x200e48 str r5, [r9, #0x4]
 *   @0x200e4c cmp r7, r3
 *   @0x200e50 blt 0x200de0 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x158>
 *   @0x200e54 ldr r0, [r8, #0x4]
 *   @0x200e58 mov r4, #0
 *   @0x200e5c bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x200e60 str r4, [r8, #0x4]
 *   @0x200e64 mov r0, r8
 *   @0x200e68 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x200e6c str r4, [r6]
 *   @0x200e70 b 0x200d88 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x100>
 *   @0x200e74 mov r0, r4
 *   @0x200e78 b 0x200e3c <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x1b4>
 *   @0x200e7c ldr r0, [r4]
 *   @0x200e80 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x200e84 mov r0, r4
 *   @0x200e88 str r5, [r4]
 *   @0x200e8c str r5, [r4, #0x8]
 *   @0x200e90 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x200e94 mov r0, r4
 *   @0x200e98 bl 0x27d1d0 <_ZdlPv>
 *   @0x200e9c b 0x200db8 <_Z16GV_ArgumentCountP9CInstanceiP6RValue+0x130>
 *   @0x200ea0 andseq sp, lr, r8, asr r0
 *
 * ══ §27/57 JS_Date_constructor(RValue&, CInstance*, CInstance*, int, RValue*)  0x246108  size 540  132 条（0x246108..0x246324）
 * @func 0x246108 0x246324  size 540  132 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×8 / JS_Date_constructor(RValue&, CInstance*, CInstance*, int, RValue*)+0xa8 / MakeDay(double, double, double) / MakeTime(double, double, double, double) / MakeDate(double, double) / UTC(double) / TimeClip(double) / JS_Date_create(RValue&, CInstance*, CInstance*, int, RValue*, double)
 * 字段偏移 top8: 0x70×1 / 0x168×1 / 0xc×1
 * VFP 指令 30 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x246108 push {r4, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24610c vpush {d8}
 *   @0x246110 subs r4, r3, #0
 *   @0x246114 sub sp, sp, #72
 *   @0x246118 mov r9, r0
 *   @0x24611c mov r10, r1
 *   @0x246120 mov r11, r2
 *   @0x246124 ldr r8, [sp, #0x70]
 *   @0x246128 beq 0x246268 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24612c cmp r4, #1
 *   @0x246130 beq 0x24624c <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x246134 mov r0, r8
 *   @0x246138 mov r1, #0
 *   @0x24613c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x246140 vmov d8, r0, r1
 *   @0x246144 mov r0, r8
 *   @0x246148 mov r1, #1
 *   @0x24614c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x246150 cmp r4, #2
 *   @0x246154 vmovle.f64 d7, #1.000000e+00
 *   @0x246158 mov r6, r0
 *   @0x24615c mov r7, r1
 *   @0x246160 vstrle d7, [sp, #32]
 *   @0x246164 bgt 0x246270 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x246168 vldr d7, [pc, #408]
 *   @0x24616c vstr d7, [sp, #40]
 *   @0x246170 vldr d7, [pc, #400]
 *   @0x246174 vstr d7, [sp, #48]
 *   @0x246178 vldr d7, [pc, #392]
 *   @0x24617c vstr d7, [sp, #16]
 *   @0x246180 vstr d7, [sp, #24]
 *   @0x246184 vcmp.f64 d8, d8
 *   @0x246188 vmrs APSR_nzcv, fpscr
 *   @0x24618c bvs 0x2461b0 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x246190 vcmpe.f64 d8, #0
 *   @0x246194 vmrs APSR_nzcv, fpscr
 *   @0x246198 blt 0x2461b0 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x24619c vldr d7, [pc, #364]
 *   @0x2461a0 vcmpe.f64 d8, d7
 *   @0x2461a4 vmrs APSR_nzcv, fpscr
 *   @0x2461a8 vldrls d7, [pc, #360]
 *   @0x2461ac vaddls.f64 d8, d8, d7
 *   @0x2461b0 ldr r3, [pc, #0x168]
 *   @0x2461b4 ldr r3, [pc, r3]
 *   @0x2461b8 ldrb r3, [r3]
 *   @0x2461bc cmp r3, #0
 *   @0x2461c0 movne r0, #0
 *   @0x2461c4 movne r1, #0
 *   @0x2461c8 bne 0x246224 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x2461cc vldr d7, [sp, #32]
 *   @0x2461d0 mov r2, r6
 *   @0x2461d4 mov r3, r7
 *   @0x2461d8 vstr d7, [sp]
 *   @0x2461dc vmov r0, r1, d8
 *   @0x2461e0 bl 0x245370 <_Z7MakeDayddd>
 *   @0x2461e4 vldr d7, [sp, #16]
 *   @0x2461e8 ldrd r2, r3, [sp, #48]
 *   @0x2461ec vstr d7, [sp]
 *   @0x2461f0 vldr d7, [sp, #24]
 *   @0x2461f4 vstr d7, [sp, #8]
 *   @0x2461f8 mov r6, r0
 *   @0x2461fc mov r7, r1
 *   @0x246200 ldrd r0, r1, [sp, #40]
 *   @0x246204 bl 0x2451d8 <_Z8MakeTimedddd>
 *   @0x246208 mov r2, r0
 *   @0x24620c mov r3, r1
 *   @0x246210 mov r0, r6
 *   @0x246214 mov r1, r7
 *   @0x246218 bl 0x245480 <_Z8MakeDatedd>
 *   @0x24621c bl 0x245118 <_Z3UTCd>
 *   @0x246220 bl 0x245e78 <_Z8TimeClipd>
 *   @0x246224 strd r0, r1, [sp, #8]
 *   @0x246228 mov r2, r11
 *   @0x24622c str r8, [sp]
 *   @0x246230 mov r0, r9
 *   @0x246234 mov r1, r10
 *   @0x246238 mov r3, r4
 *   @0x24623c bl 0x246080 <_Z14JS_Date_createR6RValueP9CInstanceS2_iPS_d>
 *   @0x246240 add sp, sp, #72
 *   @0x246244 vpop {d8}
 *   @0x246248 pop {r4, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24624c ldr r0, [r8, #0xc]
 *   @0x246250 cmp r0, #1
 *   @0x246254 beq 0x2462e4 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x246258 mov r0, r8
 *   @0x24625c mov r1, #0
 *   @0x246260 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x246264 b 0x246224 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x246268 bl 0x244988 <_Z10DateGetNowv>
 *   @0x24626c b 0x246224 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x246270 mov r0, r8
 *   @0x246274 mov r1, #2
 *   @0x246278 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x24627c cmp r4, #3
 *   @0x246280 strd r0, r1, [sp, #32]
 *   @0x246284 beq 0x246168 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x246288 mov r0, r8
 *   @0x24628c mov r1, #3
 *   @0x246290 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x246294 cmp r4, #4
 *   @0x246298 strd r0, r1, [sp, #40]
 *   @0x24629c beq 0x246170 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x2462a0 mov r0, r8
 *   @0x2462a4 mov r1, #4
 *   @0x2462a8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x2462ac cmp r4, #5
 *   @0x2462b0 strd r0, r1, [sp, #48]
 *   @0x2462b4 beq 0x246178 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x2462b8 mov r0, r8
 *   @0x2462bc mov r1, #5
 *   @0x2462c0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x2462c4 cmp r4, #6
 *   @0x2462c8 strd r0, r1, [sp, #16]
 *   @0x2462cc beq 0x2462f8 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x2462d0 mov r0, r8
 *   @0x2462d4 mov r1, #6
 *   @0x2462d8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x2462dc strd r0, r1, [sp, #24]
 *   @0x2462e0 b 0x246184 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x2462e4 add r0, sp, #56
 *   @0x2462e8 str r8, [sp]
 *   @0x2462ec bl 0x2454f0 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_>
 *   @0x2462f0 ldrd r0, r1, [sp, #56]
 *   @0x2462f4 b 0x246224 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x2462f8 vldr d7, [pc, #8]
 *   @0x2462fc vstr d7, [sp, #24]
 *   @0x246300 b 0x246184 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x246304 nop
 *   @0x246314 subsmi r12, r8, r0
 *   @0x246318 andeq r0, r0, r0
 *   @0x24631c addsmi r11, sp, r0
 *   @0x246320 andseq r11, r10, r0, asr #6
 *
 * ══ §28/57 b2WeldJoint::SolveVelocityConstraints(b2SolverData const&)  0x2d2bc4  size 540  135 条（0x2d2bc4..0x2d2de0）
 * @func 0x2d2bc4 0x2d2de0  size 540  135 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2WeldJoint::SolveVelocityConstraints(b2SolverData const&)+0x140
 * 字段偏移 top8: 0x74×1 / 0x78×1 / 0x1c×1
 * VFP 指令 125 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2bc4 ldr r2, [r0, #0x74]
 *   @0x2d2bc8 vldr s15, [r0, #68]
 *   @0x2d2bcc ldr r12, [r0, #0x78]
 *   @0x2d2bd0 vcmpe.f32 s15, #0
 *   @0x2d2bd4 ldr r1, [r1, #0x1c]
 *   @0x2d2bd8 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x2d2bdc add r2, r2, r2, lsl #1
 *   @0x2d2be0 vldr s7, [r0, #156]
 *   @0x2d2be4 add r12, r12, r12, lsl #1
 *   @0x2d2be8 vldr s8, [r0, #160]
 *   @0x2d2bec add r2, r1, r2, lsl #2
 *   @0x2d2bf0 vldr s2, [r0, #164]
 *   @0x2d2bf4 add r3, r1, r12, lsl #2
 *   @0x2d2bf8 vmrs APSR_nzcv, fpscr
 *   @0x2d2bfc vldr s3, [r0, #168]
 *   @0x2d2c00 vldr s4, [r2]
 *   @0x2d2c04 vldr s6, [r2, #4]
 *   @0x2d2c08 vldr s14, [r2, #8]
 *   @0x2d2c0c vldr s5, [r3]
 *   @0x2d2c10 vldr s9, [r3, #4]
 *   @0x2d2c14 vldr s15, [r3, #8]
 *   @0x2d2c18 ble 0x2d2d04 <_ZN11b2WeldJoint24SolveVelocityConstraintsERK12b2SolverData+0x140>
 *   @0x2d2c1c vsub.f32 s24, s15, s14
 *   @0x2d2c20 vldr s13, [r0, #76]
 *   @0x2d2c24 vldr s17, [r0, #112]
 *   @0x2d2c28 vldr s12, [r0, #100]
 *   @0x2d2c2c vldr s16, [r0, #204]
 *   @0x2d2c30 vldr s18, [r0, #132]
 *   @0x2d2c34 vldr s1, [r0, #136]
 *   @0x2d2c38 vldr s19, [r0, #124]
 *   @0x2d2c3c vldr s0, [r0, #128]
 *   @0x2d2c40 vldr s10, [r0, #184]
 *   @0x2d2c44 vldr s23, [r0, #172]
 *   @0x2d2c48 vldr s11, [r0, #188]
 *   @0x2d2c4c vldr s22, [r0, #176]
 *   @0x2d2c50 vldr s21, [r0, #104]
 *   @0x2d2c54 vldr s20, [r0, #108]
 *   @0x2d2c58 vadd.f32 s13, s24, s13
 *   @0x2d2c5c vmla.f32 s13, s17, s12
 *   @0x2d2c60 vnmul.f32 s16, s16, s13
 *   @0x2d2c64 vmla.f32 s15, s3, s16
 *   @0x2d2c68 vmov.f32 s12, s9
 *   @0x2d2c6c vmla.f32 s12, s15, s18
 *   @0x2d2c70 vmov.f32 s13, s5
 *   @0x2d2c74 vmls.f32 s14, s2, s16
 *   @0x2d2c78 vmls.f32 s13, s15, s1
 *   @0x2d2c7c vsub.f32 s12, s12, s6
 *   @0x2d2c80 vmls.f32 s12, s14, s19
 *   @0x2d2c84 vsub.f32 s13, s13, s4
 *   @0x2d2c88 vmla.f32 s13, s14, s0
 *   @0x2d2c8c vmul.f32 s10, s12, s10
 *   @0x2d2c90 vmul.f32 s11, s12, s11
 *   @0x2d2c94 vmla.f32 s10, s13, s23
 *   @0x2d2c98 vmla.f32 s11, s13, s22
 *   @0x2d2c9c vneg.f32 s12, s10
 *   @0x2d2ca0 vmul.f32 s0, s0, s12
 *   @0x2d2ca4 vmul.f32 s1, s1, s12
 *   @0x2d2ca8 vneg.f32 s13, s11
 *   @0x2d2cac vnmls.f32 s0, s19, s13
 *   @0x2d2cb0 vnmls.f32 s1, s18, s13
 *   @0x2d2cb4 vmls.f32 s4, s7, s12
 *   @0x2d2cb8 vmla.f32 s5, s8, s12
 *   @0x2d2cbc vmls.f32 s14, s2, s0
 *   @0x2d2cc0 vmla.f32 s15, s3, s1
 *   @0x2d2cc4 vmls.f32 s6, s7, s13
 *   @0x2d2cc8 vmla.f32 s9, s8, s13
 *   @0x2d2ccc vadd.f32 s16, s17, s16
 *   @0x2d2cd0 vsub.f32 s10, s21, s10
 *   @0x2d2cd4 vstr s16, [r0, #112]
 *   @0x2d2cd8 vsub.f32 s11, s20, s11
 *   @0x2d2cdc vstr s10, [r0, #104]
 *   @0x2d2ce0 vstr s11, [r0, #108]
 *   @0x2d2ce4 vstr s4, [r2]
 *   @0x2d2ce8 vstr s6, [r2, #4]
 *   @0x2d2cec vstr s14, [r2, #8]
 *   @0x2d2cf0 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x2d2cf4 vstr s5, [r3]
 *   @0x2d2cf8 vstr s9, [r3, #4]
 *   @0x2d2cfc vstr s15, [r3, #8]
 *   @0x2d2d00 bx lr
 *   @0x2d2d04 vmov.f32 s1, s9
 *   @0x2d2d08 vldr s19, [r0, #132]
 *   @0x2d2d0c vldr s16, [r0, #136]
 *   @0x2d2d10 vldr s18, [r0, #124]
 *   @0x2d2d14 vldr s0, [r0, #128]
 *   @0x2d2d18 vldr s11, [r0, #184]
 *   @0x2d2d1c vldr s17, [r0, #172]
 *   @0x2d2d20 vldr s12, [r0, #188]
 *   @0x2d2d24 vmla.f32 s1, s15, s19
 *   @0x2d2d28 vldr s27, [r0, #176]
 *   @0x2d2d2c vldr s26, [r0, #196]
 *   @0x2d2d30 vldr s13, [r0, #192]
 *   @0x2d2d34 vldr s25, [r0, #200]
 *   @0x2d2d38 vldr s24, [r0, #180]
 *   @0x2d2d3c vldr s23, [r0, #204]
 *   @0x2d2d40 vldr s22, [r0, #104]
 *   @0x2d2d44 vldr s21, [r0, #108]
 *   @0x2d2d48 vldr s20, [r0, #112]
 *   @0x2d2d4c vmov.f32 s10, s5
 *   @0x2d2d50 vmls.f32 s10, s15, s16
 *   @0x2d2d54 vsub.f32 s1, s1, s6
 *   @0x2d2d58 vmls.f32 s1, s14, s18
 *   @0x2d2d5c vsub.f32 s10, s10, s4
 *   @0x2d2d60 vmla.f32 s10, s14, s0
 *   @0x2d2d64 vmul.f32 s11, s1, s11
 *   @0x2d2d68 vmul.f32 s12, s1, s12
 *   @0x2d2d6c vmla.f32 s11, s10, s17
 *   @0x2d2d70 vsub.f32 s17, s15, s14
 *   @0x2d2d74 vmla.f32 s12, s10, s27
 *   @0x2d2d78 vmla.f32 s11, s17, s26
 *   @0x2d2d7c vmul.f32 s13, s1, s13
 *   @0x2d2d80 vmla.f32 s12, s17, s25
 *   @0x2d2d84 vmla.f32 s13, s10, s24
 *   @0x2d2d88 vneg.f32 s1, s11
 *   @0x2d2d8c vmul.f32 s16, s16, s1
 *   @0x2d2d90 vmul.f32 s0, s0, s1
 *   @0x2d2d94 vneg.f32 s10, s12
 *   @0x2d2d98 vmla.f32 s13, s17, s23
 *   @0x2d2d9c vnmls.f32 s16, s19, s10
 *   @0x2d2da0 vnmls.f32 s0, s18, s10
 *   @0x2d2da4 vsub.f32 s16, s16, s13
 *   @0x2d2da8 vsub.f32 s0, s0, s13
 *   @0x2d2dac vsub.f32 s11, s22, s11
 *   @0x2d2db0 vsub.f32 s12, s21, s12
 *   @0x2d2db4 vstr s11, [r0, #104]
 *   @0x2d2db8 vsub.f32 s13, s20, s13
 *   @0x2d2dbc vstr s12, [r0, #108]
 *   @0x2d2dc0 vmls.f32 s4, s7, s1
 *   @0x2d2dc4 vstr s13, [r0, #112]
 *   @0x2d2dc8 vmla.f32 s5, s8, s1
 *   @0x2d2dcc vmls.f32 s6, s7, s10
 *   @0x2d2dd0 vmla.f32 s9, s8, s10
 *   @0x2d2dd4 vmls.f32 s14, s0, s2
 *   @0x2d2dd8 vmla.f32 s15, s16, s3
 *   @0x2d2ddc b 0x2d2ce4 <_ZN11b2WeldJoint24SolveVelocityConstraintsERK12b2SolverData+0x120>
 *
 * ══ §29/57 F_SpriteGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*)  0x120f9c  size 536  134 条（0x120f9c..0x1211b4）
 * @func 0x120f9c 0x1211b4  size 536  134 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CreateArray(RValue*, int, ...)×2 / F_SpriteGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*)+0xc0 / Sprite_Data(int) / CSprite::GetTexture(int) / F_SpriteGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*)+0x7c / 0xb6598
 * 字段偏移 top8: 0x50×1 / 0x74×1 / 0x1a8×1 / 0x128×1 / 0x4×1 / 0x2×1 / 0xc×1
 * VFP 指令 51 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120f9c push {r4, r5, r6, r7, lr}
 *   @0x120fa0 sub sp, sp, #60
 *   @0x120fa4 mov r6, r0
 *   @0x120fa8 mov r7, r1
 *   @0x120fac ldr r4, [sp, #0x50]
 *   @0x120fb0 mov r1, #0
 *   @0x120fb4 mov r0, r4
 *   @0x120fb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120fbc mov r1, #1
 *   @0x120fc0 mov r5, r0
 *   @0x120fc4 mov r0, r4
 *   @0x120fc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120fcc subs r4, r0, #0
 *   @0x120fd0 blt 0x12105c <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x120fd4 mov r0, r5
 *   @0x120fd8 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x120fdc subs r1, r0, #0
 *   @0x120fe0 beq 0x12119c <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0x200>
 *   @0x120fe4 ldr r3, [r1, #0x74]
 *   @0x120fe8 cmp r3, #0
 *   @0x120fec bne 0x12107c <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x120ff0 mov r1, r4
 *   @0x120ff4 bl 0x1e57f4 <_ZN7CSprite10GetTextureEi>
 *   @0x120ff8 ldr r3, [pc, #0x1a8]
 *   @0x120ffc ldr r3, [pc, r3]
 *   @0x121000 ldr r2, [r3]
 *   @0x121004 cmp r0, r2
 *   @0x121008 mov r12, r0
 *   @0x12100c bls 0x121018 <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x121010 cmn r0, #1
 *   @0x121014 bne 0x121094 <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x121018 mov r4, #0
 *   @0x12101c mov r2, #0
 *   @0x121020 mov r3, #0
 *   @0x121024 mov r0, r6
 *   @0x121028 mov r1, #8
 *   @0x12102c strd r2, r3, [sp]
 *   @0x121030 strd r2, r3, [sp, #24]
 *   @0x121034 mov r5, #0
 *   @0x121038 strd r2, r3, [sp, #32]
 *   @0x12103c movt r5, #0x3ff0
 *   @0x121040 strd r4, r5, [sp, #8]
 *   @0x121044 strd r4, r5, [sp, #16]
 *   @0x121048 strd r4, r5, [sp, #40]
 *   @0x12104c strd r4, r5, [sp, #48]
 *   @0x121050 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x121054 add sp, sp, #60
 *   @0x121058 pop {r4, r5, r6, r7, pc}
 *   @0x12105c vldr s15, [r7, #144]
 *   @0x121060 vcvt.f64.f32 d6, s15
 *   @0x121064 vmov r0, r1, d6
 *   @0x121068 bl 0xb6598 <floor@plt>
 *   @0x12106c vmov d7, r0, r1
 *   @0x121070 vcvt.s32.f64 s15, d7
 *   @0x121074 vmov r4, s15
 *   @0x121078 b 0x120fd4 <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x12107c ldr r0, [pc, #0x128]
 *   @0x121080 mov r1, #0
 *   @0x121084 add r0, pc, r0
 *   @0x121088 add sp, sp, #60
 *   @0x12108c pop {r4, r5, r6, r7, lr}
 *   @0x121090 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x121094 ldrsh r4, [r0, #20]
 *   @0x121098 vmov.f32 s13, #1.000000e+00
 *   @0x12109c ldr r3, [r3, #0x4]
 *   @0x1210a0 mov r0, r6
 *   @0x1210a4 ldrsh r2, [r12, #2]
 *   @0x1210a8 mov r1, #8
 *   @0x1210ac ldrsh lr, [r12]
 *   @0x1210b0 ldr r3, [r3, r4, lsl #2]
 *   @0x1210b4 vmov s12, r2
 *   @0x1210b8 ldr r3, [r3]
 *   @0x1210bc vldr s15, [r3, #8]
 *   @0x1210c0 vldr s9, [r3, #4]
 *   @0x1210c4 vcvt.f32.s32 s15, s15
 *   @0x1210c8 vdiv.f32 s15, s13, s15
 *   @0x1210cc vcvt.f32.s32 s9, s9
 *   @0x1210d0 vcvt.f32.s32 s10, s12
 *   @0x1210d4 vdiv.f32 s9, s13, s9
 *   @0x1210d8 vmov s13, lr
 *   @0x1210dc vmul.f32 s10, s10, s15
 *   @0x1210e0 vcvt.f64.f32 d5, s10
 *   @0x1210e4 vstr d5, [sp]
 *   @0x1210e8 ldrsh r3, [r12, #12]
 *   @0x1210ec vcvt.f32.s32 s14, s13
 *   @0x1210f0 add r3, lr, r3
 *   @0x1210f4 vmov s12, r3
 *   @0x1210f8 vcvt.f32.s32 s12, s12
 *   @0x1210fc vmul.f32 s12, s12, s9
 *   @0x121100 vcvt.f64.f32 d6, s12
 *   @0x121104 vstr d6, [sp, #8]
 *   @0x121108 ldrsh r3, [r12, #14]
 *   @0x12110c vmul.f32 s9, s14, s9
 *   @0x121110 add r3, r2, r3
 *   @0x121114 vmov s14, r3
 *   @0x121118 vcvt.f32.s32 s14, s14
 *   @0x12111c vmul.f32 s14, s14, s15
 *   @0x121120 vcvt.f64.f32 d7, s14
 *   @0x121124 vstr d7, [sp, #16]
 *   @0x121128 ldrsh r3, [r12, #8]
 *   @0x12112c vcvt.f64.f32 d6, s9
 *   @0x121130 vmov s14, r3
 *   @0x121134 vcvt.f64.s32 d7, s14
 *   @0x121138 vmov r2, r3, d6
 *   @0x12113c vstr d7, [sp, #24]
 *   @0x121140 ldrsh lr, [r12, #10]
 *   @0x121144 vmov s14, lr
 *   @0x121148 vcvt.f64.s32 d7, s14
 *   @0x12114c vstr d7, [sp, #32]
 *   @0x121150 ldrsh lr, [r12, #4]
 *   @0x121154 vmov s12, lr
 *   @0x121158 ldrsh lr, [r12, #16]
 *   @0x12115c vcvt.f64.s32 d6, s12
 *   @0x121160 vmov s14, lr
 *   @0x121164 vcvt.f64.s32 d7, s14
 *   @0x121168 vdiv.f64 d7, d6, d7
 *   @0x12116c vstr d7, [sp, #40]
 *   @0x121170 ldrsh lr, [r12, #6]
 *   @0x121174 ldrsh r12, [r12, #18]
 *   @0x121178 vmov s12, lr
 *   @0x12117c vmov s14, r12
 *   @0x121180 vcvt.f64.s32 d6, s12
 *   @0x121184 vcvt.f64.s32 d7, s14
 *   @0x121188 vdiv.f64 d7, d6, d7
 *   @0x12118c vstr d7, [sp, #48]
 *   @0x121190 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x121194 add sp, sp, #60
 *   @0x121198 pop {r4, r5, r6, r7, pc}
 *   @0x12119c ldr r0, [pc, #0xc]
 *   @0x1211a0 add r0, pc, r0
 *   @0x1211a4 b 0x121088 <_Z17F_SpriteGetBaseUVR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x1211a8 eoreq r12, r12, r0, lsr #18
 *   @0x1211ac .word 0x002193b0
 *   @0x1211b0 eoreq r9, r1, r12, ror #1
 *
 * ══ §30/57 GraphicsPerf::HandleInput()  0x17b624  size 536  134 条（0x17b624..0x17b83c）
 * @func 0x17b624 0x17b83c  size 536  134 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17b62c→0x54298c, 0x17b634→0x3f26c0, 0x17b638→0x3f26bc, 0x17b684→0x5346b8, 0x17b688→0x49931c, 0x17b6a0→0x5346b4, 0x17b6a4→0x499318, 0x17b6c4→0x4a2018
 * 调用序列: IO_Button_Released(int, int)×4 / CheckInRect(int, int, int, int)×3 / __divsi3×2 / CheckSequence(int*, int*, int)×2 / GR_Window_Get_Region_Width()
 * 字段偏移 top8: 0x1dc×2 / 0x1d8×2 / 0x190×2 / 0x17c×2 / 0x44×1 / 0x48×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b624 push {r3, r4, r5, r6, r7, lr}
 *   @0x17b628 ldr r4, [pc, #0x1dc]
 *   @0x17b62c ldr r3, [pc, #0x1dc]
 *   @0x17b630 add r4, pc, r4
 *   @0x17b634 ldr r1, [pc, #0x1d8]
 *   @0x17b638 ldr r2, [pc, #0x1d8]
 *   @0x17b63c ldr r3, [r4, r3]
 *   @0x17b640 ldr r1, [r4, r1]
 *   @0x17b644 ldr r2, [r4, r2]
 *   @0x17b648 ldr r3, [r3]
 *   @0x17b64c ldr r1, [r1]
 *   @0x17b650 cmp r3, #0
 *   @0x17b654 ldr r6, [r2]
 *   @0x17b658 beq 0x17b7d8 <_ZN12GraphicsPerf11HandleInputEv+0x1b4>
 *   @0x17b65c ldrb r2, [r3, #0x44]
 *   @0x17b660 ldr r0, [r3, #0x48]
 *   @0x17b664 cmp r2, #0
 *   @0x17b668 ldr r5, [r3, #0x14]
 *   @0x17b66c ldr r2, [r3, #0x10]
 *   @0x17b670 beq 0x17b684 <_ZN12GraphicsPerf11HandleInputEv+0x60>
 *   @0x17b674 ldrb r3, [r0]
 *   @0x17b678 cmp r3, #0
 *   @0x17b67c ldrne r2, [r0, #0x1c]
 *   @0x17b680 ldrne r5, [r0, #0x20]
 *   @0x17b684 ldr r3, [pc, #0x190]
 *   @0x17b688 ldr r0, [pc, #0x190]
 *   @0x17b68c ldr r3, [r4, r3]
 *   @0x17b690 ldr r7, [r4, r0]
 *   @0x17b694 ldr r0, [r3]
 *   @0x17b698 mul r0, r0, r2
 *   @0x17b69c bl 0x318d10 <__divsi3>
 *   @0x17b6a0 ldr r2, [pc, #0x17c]
 *   @0x17b6a4 ldr r3, [pc, #0x17c]
 *   @0x17b6a8 mov r1, r6
 *   @0x17b6ac str r0, [r7]
 *   @0x17b6b0 ldr r2, [r4, r2]
 *   @0x17b6b4 ldr r6, [r4, r3]
 *   @0x17b6b8 ldr r0, [r2]
 *   @0x17b6bc mul r0, r0, r5
 *   @0x17b6c0 bl 0x318d10 <__divsi3>
 *   @0x17b6c4 ldr r3, [pc, #0x160]
 *   @0x17b6c8 str r0, [r6]
 *   @0x17b6cc mov r0, #1
 *   @0x17b6d0 ldr r5, [r4, r3]
 *   @0x17b6d4 ldr r1, [r5]
 *   @0x17b6d8 ands r1, r1, #1
 *   @0x17b6dc bne 0x17b718 <_ZN12GraphicsPerf11HandleInputEv+0xf4>
 *   @0x17b6e0 bl 0x18c12c <_Z18IO_Button_Releasedii>
 *   @0x17b6e4 cmp r0, #0
 *   @0x17b6e8 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x17b6ec ldr r3, [pc, #0x13c]
 *   @0x17b6f0 mov r2, #7
 *   @0x17b6f4 ldr r1, [pc, #0x138]
 *   @0x17b6f8 ldr r0, [r4, r1]
 *   @0x17b6fc ldr r1, [r4, r3]
 *   @0x17b700 bl 0x17b4cc <_Z13CheckSequencePiS_i>
 *   @0x17b704 cmp r0, #0
 *   @0x17b708 ldrne r3, [r5]
 *   @0x17b70c orrne r3, r3, #1
 *   @0x17b710 strne r3, [r5]
 *   @0x17b714 pop {r3, r4, r5, r6, r7, pc}
 *   @0x17b718 mov r1, #0
 *   @0x17b71c bl 0x18c12c <_Z18IO_Button_Releasedii>
 *   @0x17b720 cmp r0, #0
 *   @0x17b724 bne 0x17b7ac <_ZN12GraphicsPerf11HandleInputEv+0x188>
 *   @0x17b728 ldr r1, [r5]
 *   @0x17b72c ands r1, r1, #8
 *   @0x17b730 mov r0, #1
 *   @0x17b734 bne 0x17b770 <_ZN12GraphicsPerf11HandleInputEv+0x14c>
 *   @0x17b738 bl 0x18c12c <_Z18IO_Button_Releasedii>
 *   @0x17b73c cmp r0, #0
 *   @0x17b740 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x17b744 ldr r3, [pc, #0xec]
 *   @0x17b748 mov r2, #8
 *   @0x17b74c ldr r1, [pc, #0xe0]
 *   @0x17b750 ldr r0, [r4, r1]
 *   @0x17b754 ldr r1, [r4, r3]
 *   @0x17b758 bl 0x17b4cc <_Z13CheckSequencePiS_i>
 *   @0x17b75c cmp r0, #0
 *   @0x17b760 ldrne r3, [r5]
 *   @0x17b764 orrne r3, r3, #8
 *   @0x17b768 strne r3, [r5]
 *   @0x17b76c pop {r3, r4, r5, r6, r7, pc}
 *   @0x17b770 mov r1, #0
 *   @0x17b774 bl 0x18c12c <_Z18IO_Button_Releasedii>
 *   @0x17b778 cmp r0, #0
 *   @0x17b77c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x17b780 mov r0, #10
 *   @0x17b784 mov r2, #64
 *   @0x17b788 mov r1, r0
 *   @0x17b78c mov r3, #16
 *   @0x17b790 bl 0x17b5cc <_Z11CheckInRectiiii>
 *   @0x17b794 cmp r0, #0
 *   @0x17b798 beq 0x17b7e4 <_ZN12GraphicsPerf11HandleInputEv+0x1c0>
 *   @0x17b79c ldr r3, [r5]
 *   @0x17b7a0 eor r3, r3, #2
 *   @0x17b7a4 str r3, [r5]
 *   @0x17b7a8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x17b7ac bl 0x179988 <_Z26GR_Window_Get_Region_Widthv>
 *   @0x17b7b0 mov r1, #80
 *   @0x17b7b4 mov r2, #64
 *   @0x17b7b8 mov r3, #16
 *   @0x17b7bc sub r0, r0, #80
 *   @0x17b7c0 bl 0x17b5cc <_Z11CheckInRectiiii>
 *   @0x17b7c4 ldr r1, [r5]
 *   @0x17b7c8 cmp r0, #0
 *   @0x17b7cc bicne r1, r1, #9
 *   @0x17b7d0 strne r1, [r5]
 *   @0x17b7d4 b 0x17b72c <_ZN12GraphicsPerf11HandleInputEv+0x108>
 *   @0x17b7d8 mov r5, r6
 *   @0x17b7dc mov r2, r1
 *   @0x17b7e0 b 0x17b684 <_ZN12GraphicsPerf11HandleInputEv+0x60>
 *   @0x17b7e4 mov r3, #16
 *   @0x17b7e8 mov r0, #10
 *   @0x17b7ec mov r1, #30
 *   @0x17b7f0 mov r2, #64
 *   @0x17b7f4 bl 0x17b5cc <_Z11CheckInRectiiii>
 *   @0x17b7f8 cmp r0, #0
 *   @0x17b7fc ldrne r3, [r5]
 *   @0x17b800 eorne r3, r3, #16
 *   @0x17b804 strne r3, [r5]
 *   @0x17b808 pop {r3, r4, r5, r6, r7, pc}
 *   @0x17b80c eoreq r6, r7, r0, lsr #12
 *   @0x17b810 .word 0xffffbcd8
 *   @0x17b814 .word 0xffffe24c
 *   @0x17b818 .word 0xffffe250
 *   @0x17b81c .word 0xffffe720
 *   @0x17b820 .word 0xffffe714
 *   @0x17b824 .word 0xffffe724
 *   @0x17b828 .word 0xffffe718
 *   @0x17b82c .word 0xffffc7dc
 *   @0x17b830 .word 0xffffe728
 *   @0x17b834 .word 0xffffe71c
 *   @0x17b838 .word 0xffffe72c
 *
 * ══ §31/57 SoundHardware::Load(void*, int, int)  0x22054c  size 536  127 条（0x22054c..0x220764）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x22054c 0x220764  size 536  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x22055c→0x755361, 0x220578→0x755363, 0x22058c→0x755362, 0x2205a0→0x755360, 0x2205d0→0x3eb70c, 0x2206a4→0x3eb70c, 0x2206d4→0x3eb70c, 0x220708→0x3eb70c
 * 调用序列: CheckALError()×2 / alutCreateBufferFromFileImage / alutGetError / alutGetErrorString / 0xb6a54 / operator new(unsigned int) / 0xb6a90 / 0xb6a6c
 * 字段偏移 top8: 0xc×4 / 0xa4×2 / 0x1dc×1 / 0x1d8×1 / 0x1c0×1 / 0x1b0×1 / 0x1a0×1 / 0x174×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22054c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x220550 mov r8, r1
 *   @0x220554 ldr r4, [pc, #0x1dc]
 *   @0x220558 sub sp, sp, #12
 *   @0x22055c ldr r3, [pc, #0x1d8]
 *   @0x220560 mov r7, r2
 *   @0x220564 add r4, pc, r4
 *   @0x220568 ldr r6, [r4, r3]
 *   @0x22056c ldrb r3, [r6]
 *   @0x22058c ldr r2, [pc, #0x1b0]
 *   @0x220590 ldr r2, [r4, r2]
 *   @0x220594 ldrb r2, [r2]
 *   @0x220598 cmp r2, #0
 *   @0x22059c bne 0x220698 <_ZN13SoundHardware4LoadEPvii+0x14c>
 *   @0x2205a0 ldr r3, [pc, #0x1a0]
 *   @0x2205a4 ldr r3, [r4, r3]
 *   @0x2205a8 ldrb r5, [r3]
 *   @0x2205ac cmp r5, #0
 *   @0x2205b0 bne 0x220698 <_ZN13SoundHardware4LoadEPvii+0x14c>
 *   @0x2205b4 mov r1, r7
 *   @0x2205b8 mov r0, r8
 *   @0x2205bc bl 0x222638 <alutCreateBufferFromFileImage>
 *   @0x2205c0 mov r8, r0
 *   @0x2205c4 bl 0x221714 <alutGetError>
 *   @0x2205c8 subs r7, r0, #0
 *   @0x2205cc beq 0x220610 <_ZN13SoundHardware4LoadEPvii+0xc4>
 *   @0x2205d0 ldr r3, [pc, #0x174]
 *   @0x2205d4 ldr r3, [r4, r3]
 *   @0x2205d8 ldr r4, [r3]
 *   @0x2205dc ldr r3, [r4]
 *   @0x2205e0 ldr r6, [r3, #0xc]
 *   @0x2205e4 bl 0x221730 <alutGetErrorString>
 *   @0x2205e8 ldr r1, [pc, #0x160]
 *   @0x2205ec mov r2, r7
 *   @0x2205f0 mov r3, r7
 *   @0x2205f4 add r1, pc, r1
 *   @0x2205f8 str r0, [sp]
 *   @0x2205fc mov r0, r4
 *   @0x220600 blx r6
 *   @0x220604 mov r0, r5
 *   @0x220608 add sp, sp, #12
 *   @0x22060c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x220610 bl 0xb6a54 <alGetError@plt>
 *   @0x220614 subs r9, r0, #0
 *   @0x220618 bne 0x2206d4 <_ZN13SoundHardware4LoadEPvii+0x188>
 *   @0x22061c mov r0, #36
 *   @0x220620 bl 0x27c524 <_Znwj>
 *   @0x220624 ldrb r3, [r6]
 *   @0x220628 mov r2, #1065353216
 *   @0x22062c mov r1, #0
 *   @0x220630 cmp r3, #0
 *   @0x220634 mov r5, r0
 *   @0x220638 str r9, [r0, #0x14]
 *   @0x22063c str r8, [r0]
 *   @0x220640 addeq r6, r0, #4
 *   @0x220644 str r9, [r0, #0x20]
 *   @0x220648 str r1, [r0, #0x1c]
 *   @0x22064c str r2, [r0, #0x18]
 *   @0x220650 bne 0x220708 <_ZN13SoundHardware4LoadEPvii+0x1bc>
 *   @0x220654 mov r1, r6
 *   @0x220658 mov r0, #4
 *   @0x22065c bl 0xb6a90 <alGenSources@plt>
 *   @0x220660 sub r4, r5, #4
 *   @0x220664 bl 0x220198 <_Z12CheckALErrorv>
 *   @0x220668 add r6, r5, #12
 *   @0x22066c add r4, r4, #4
 *   @0x220670 movw r1, #0x1009
 *   @0x220674 ldr r2, [r5]
 *   @0x220678 ldr r0, [r4, #0x4]
 *   @0x22067c bl 0xb6a6c <alSourcei@plt>
 *   @0x220680 bl 0x220198 <_Z12CheckALErrorv>
 *   @0x220684 cmp r4, r6
 *   @0x220688 bne 0x22066c <_ZN13SoundHardware4LoadEPvii+0x120>
 *   @0x22068c mov r0, r5
 *   @0x220690 add sp, sp, #12
 *   @0x220694 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x220698 mov r0, #0
 *   @0x22069c add sp, sp, #12
 *   @0x2206a0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2206a4 ldr r3, [pc, #0xa0]
 *   @0x2206a8 ldr r2, [pc, #0xa4]
 *   @0x2206ac ldr r1, [pc, #0xa4]
 *   @0x2206b0 ldr r3, [r4, r3]
 *   @0x2206b4 add r2, pc, r2
 *   @0x2206b8 add r1, pc, r1
 *   @0x2206bc add r2, r2, #68
 *   @0x2206c0 ldr r0, [r3]
 *   @0x2206c4 ldr r3, [r0]
 *   @0x2206c8 ldr r3, [r3, #0xc]
 *   @0x2206cc blx r3
 *   @0x2206d0 b 0x220578 <_ZN13SoundHardware4LoadEPvii+0x2c>
 *   @0x2206d4 ldr r0, [pc, #0x70]
 *   @0x2206d8 mov r2, r9
 *   @0x2206dc ldr r1, [pc, #0x78]
 *   @0x2206e0 mov r3, r9
 *   @0x2206e4 ldr r0, [r4, r0]
 *   @0x2206e8 add r1, pc, r1
 *   @0x2206ec ldr r0, [r0]
 *   @0x2206f0 ldr r12, [r0]
 *   @0x2206f4 ldr r12, [r12, #0xc]
 *   @0x2206f8 blx r12
 *   @0x2206fc mov r0, r7
 *   @0x220700 add sp, sp, #12
 *   @0x220704 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x220708 ldr r0, [pc, #0x3c]
 *   @0x22070c add r6, r5, #4
 *   @0x220710 ldr r1, [pc, #0x48]
 *   @0x220714 mov r2, #4
 *   @0x220718 mov r3, r6
 *   @0x22071c ldr r0, [r4, r0]
 *   @0x220720 add r1, pc, r1
 *   @0x220724 ldr r0, [r0]
 *   @0x220728 ldr r12, [r0]
 *   @0x22072c ldr r12, [r12, #0xc]
 *   @0x220730 blx r12
 *   @0x220734 b 0x220654 <_ZN13SoundHardware4LoadEPvii+0x108>
 *   @0x220738 andseq r1, sp, r12, ror #13
 *   @0x22073c .word 0xfffff7d8
 *   @0x220740 .word 0xffffd3fc
 *   @0x220744 .word 0xfffff7e0
 *   @0x220748 .word 0xfffff7e4
 *   @0x22074c .word 0xffffbac4
 *   @0x220750 andseq r4, r3, r8, ror r2
 *   @0x220754 andseq sp, r3, r4, lsl r9
 *   @0x220758 andseq r4, r3, r4, lsl #3
 *   @0x22075c andseq r4, r3, r8, ror #2
 *   @0x220760 andseq r4, r3, r4, lsr #2
 *
 * ══ §32/57 JS_Global_parseInt(RValue&, CInstance*, CInstance*, int, RValue*)  0x254e18  size 536  134 条（0x254e18..0x255030）
 * @func 0x254e18 0x255030  size 536  134 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: isValidRadixChar(char, int)×2 / F_JS_ToString(RValue&, RValue*) / JS_isWhitespace(int) / F_JS_ToInt32(RValue&, RValue&) / JS_Global_parseInt(RValue&, CInstance*, CInstance*, int, RValue*)+0x1d8 / getRadixChar(char, int) / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0xc×5 / 0x1×3 / 0x40×1 / 0x8×1 / 0x18×1 / 0x1c×1 / 0x4×1 / 0x24×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x254e18 cmp r3, #0
 *   @0x254e1c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x254e20 mov r7, r0
 *   @0x254e24 sub sp, sp, #36
 *   @0x254e28 bne 0x254e44 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x254e2c str r3, [r0, #0xc]
 *   @0x254e30 mvn r2, #0
 *   @0x254e34 mvn r3, #-2147483648
 *   @0x254e38 stm r0, {r2, r3}
 *   @0x254e3c add sp, sp, #36
 *   @0x254e40 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x254e44 ldr r1, [sp, #0x40]
 *   @0x254e48 mov r0, sp
 *   @0x254e4c mov r2, #0
 *   @0x254e50 mov r3, #0
 *   @0x254e54 mov r12, #0
 *   @0x254e58 strd r2, r3, [sp]
 *   @0x254e5c str r12, [sp, #0x8]
 *   @0x254e60 mvn r3, #-16777216
 *   @0x254e64 add r5, r1, #16
 *   @0x254e68 str r3, [sp, #0xc]
 *   @0x254e6c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x254e70 cmp r0, #1
 *   @0x254e74 beq 0x255000 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x254e78 ldr r3, [sp]
 *   @0x254e7c ldr r6, [r3]
 *   @0x254e80 cmp r6, #0
 *   @0x254e84 beq 0x254eb0 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x254e88 mov r4, r6
 *   @0x254e8c mov r6, r4
 *   @0x254e90 add r4, r4, #1
 *   @0x254e94 ldrb r0, [r6]
 *   @0x254e98 bl 0x2425ac <_Z15JS_isWhitespacei>
 *   @0x254e9c cmp r0, #0
 *   @0x254ea0 beq 0x254eb0 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x254ea4 cmp r4, #0
 *   @0x254ea8 mov r6, r4
 *   @0x254eac bne 0x254e8c <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x254eb0 ldrb r3, [r6]
 *   @0x254eb4 cmp r3, #0
 *   @0x254eb8 beq 0x254edc <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x254ebc cmp r3, #45
 *   @0x254ec0 addeq r6, r6, #1
 *   @0x254ec4 mvneq r8, #0
 *   @0x254ec8 beq 0x254ee0 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x254ecc cmp r3, #43
 *   @0x254ed0 addeq r6, r6, #1
 *   @0x254ed4 moveq r8, #1
 *   @0x254ed8 beq 0x254ee0 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x254edc mov r8, #1
 *   @0x254ee0 mov r1, r5
 *   @0x254ee4 add r0, sp, #16
 *   @0x254ee8 mov r4, #0
 *   @0x254eec mov r9, #0
 *   @0x254ef0 mvn r3, #-16777216
 *   @0x254ef4 mov r5, #0
 *   @0x254ef8 str r9, [sp, #0x18]
 *   @0x254efc strd r4, r5, [sp, #16]
 *   @0x254f00 str r3, [sp, #0x1c]
 *   @0x254f04 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_>
 *   @0x254f08 vldr d7, [sp, #16]
 *   @0x254f0c vcvt.s32.f64 s13, d7
 *   @0x254f10 vmov r4, s13
 *   @0x254f14 cmp r4, r9
 *   @0x254f18 bne 0x254f50 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x254f1c mov r4, #10
 *   @0x254f20 ldrb r0, [r6]
 *   @0x254f24 cmp r0, #48
 *   @0x254f28 beq 0x255010 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x254f2c mov r1, r4
 *   @0x254f30 bl 0x23fe9c <_Z16isValidRadixCharci>
 *   @0x254f34 cmp r0, #0
 *   @0x254f38 bne 0x254f70 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x254f3c mvn r2, #0
 *   @0x254f40 mvn r3, #-2147483648
 *   @0x254f44 str r0, [r7, #0xc]
 *   @0x254f48 stm r7, {r2, r3}
 *   @0x254f4c b 0x254e3c <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x254f50 sub r3, r4, #2
 *   @0x254f54 cmp r3, #34
 *   @0x254f58 bls 0x254ff0 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x254f5c mvn r2, #0
 *   @0x254f60 mvn r3, #-2147483648
 *   @0x254f64 str r9, [r7, #0xc]
 *   @0x254f68 stm r7, {r2, r3}
 *   @0x254f6c b 0x254e3c <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x254f70 ldrb r3, [r6]
 *   @0x254f74 cmp r3, #0
 *   @0x254f78 bne 0x254fa4 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x254f7c mov r2, #0
 *   @0x254f80 mov r3, #0
 *   @0x254f84 mov r1, r2
 *   @0x254f88 mov r2, r3
 *   @0x254f8c str r1, [r7]
 *   @0x254f90 mov r3, #0
 *   @0x254f94 str r2, [r7, #0x4]
 *   @0x254f98 str r3, [r7, #0xc]
 *   @0x254f9c add sp, sp, #36
 *   @0x254fa0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x254fa4 sub r6, r6, #1
 *   @0x254fa8 mov r5, #0
 *   @0x254fac mov r1, r4
 *   @0x254fb0 mov r0, r3
 *   @0x254fb4 bl 0x23fe9c <_Z16isValidRadixCharci>
 *   @0x254fb8 mov r1, r4
 *   @0x254fbc cmp r0, #0
 *   @0x254fc0 beq 0x254fdc <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x254fc4 ldrb r0, [r6, #0x1]!
 *   @0x254fc8 bl 0x23fe14 <_Z12getRadixCharci>
 *   @0x254fcc ldrb r3, [r6, #0x1]
 *   @0x254fd0 cmp r3, #0
 *   @0x254fd4 mla r5, r4, r5, r0
 *   @0x254fd8 bne 0x254fac <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x254fdc mul r2, r5, r8
 *   @0x254fe0 vmov s15, r2
 *   @0x254fe4 vcvt.f64.s32 d7, s15
 *   @0x254fe8 vmov r2, r3, d7
 *   @0x254fec b 0x254f84 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x254ff0 cmp r4, #16
 *   @0x254ff4 beq 0x254f20 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x254ff8 ldrb r0, [r6]
 *   @0x254ffc b 0x254f2c <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x255000 ldr r0, [pc, #0x24]
 *   @0x255004 add r0, pc, r0
 *   @0x255008 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25500c b 0x254e3c <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x255010 ldrb r3, [r6, #0x1]
 *   @0x255014 and r3, r3, #223
 *   @0x255018 cmp r3, #88
 *   @0x25501c ldrbeq r0, [r6, #0x2]
 *   @0x255020 moveq r4, #16
 *   @0x255024 addeq r6, r6, #2
 *   @0x255028 b 0x254f2c <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x25502c andseq r1, r0, r0, lsr r9
 *
 * ══ §33/57 _zip_dirent_read(zip_dirent*, __sFILE*, unsigned char**, unsigned int*, int, zip_error*)  0x2a3ef0  size 536  134 条（0x2a3ef0..0x2a4108）
 * @func 0x2a3ef0 0x2a4108  size 536  134 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _zip_read2(unsigned char**)×4 / _zip_read4(unsigned char**)×2 / anon_2a399c+0xfc×2 / anon_2a399c+0x44×2 / _zip_error_set(zip_error*, int, int) / _zip_dirent_read(zip_dirent*, __sFILE*, unsigned char**, unsigned int*, int, zip_error*)+0x32 / 0xb65d4
 * 字段偏移 top8: 0x4×4 / 0x8×3 / 0x24×3 / 0x68×2 / 0x2e×2 / 0x34×2 / 0x2c×2 / 0x20×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a3ef0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a3ef4 mov r9, r2
 *   @0x2a3ef8 mov r10, r1
 *   @0x2a3efc mov r4, r0
 *   @0x2a3f00 ldr r2, [r2]
 *   @0x2a3f04 ldr r6, [sp, #0x6c]
 *   @0x2a3f08 str r2, [sp, #0x4]
 *   @0x2a3f0c ldr r1, [sp, #0x68]
 *   @0x2a3f10 ite eq
 *   @0x2a3f14 .word 0xf04f0b2e
 *   @0x2a3f18 teqlt r3, lr, lsl r11
 *   @0x2a3f1c ldr r3, [r3]
 *   @0x2a3f20 bhs 0x2a3f2a <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x3a>
 *   @0x2a3f24 movs r1, #0x13
 *   @0x2a3f28 b 0x2a3f58 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x68>
 *   @0x2a3f2c andle r0, r3, r0, lsl #30
 *   @0x2a3f30 ldr.w r3, [r9]
 *   @0x2a3f34 str r3, [sp, #0x8]
 *   @0x2a3f38 add r5, sp, #0xc
 *   @0x2a3f3c mov r2, r11
 *   @0x2a3f40 mov r0, r5
 *   @0x2a3f44 ldrbmi lr, [r8, #-0xcc2]
 *   @0x2a3f48 it hs
 *   @0x2a3f4c bhs 0x2a3f5e <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x6e>
 *   @0x2a3f50 qaddhs lr, r4, r5
 *   @0x2a3f54 ldr r2, [r0]
 *   @0x2a3f58 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a3f5c b 0x2a4066 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x176>
 *   @0x2a3f60 ldr r5, [sp, #0x8]
 *   @0x2a3f64 ldr r1, [pc, #0x198]
 *   @0x2a3f68 b 0x2a3f6e <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x7e>
 *   @0x2a3f6c add r1, pc
 *   @0x2a3f70 movs r2, #0x4
 *   @0x2a3f74 strmi lr, [r0], r6, ror #28
 *   @0x2a3f78 cmp r0, #0x0
 *   @0x2a3f7c adds r3, r5, #0x4
 *   @0x2a3f80 str r3, [r5, #-56]!
 *   @0x2a3f84 ldr r3, [sp, #0x68]
 *   @0x2a3f88 mov r0, r5
 *   @0x2a3f8c mlahi r0, r9, pc, pc
 *   @0x2a3f90 b 0x2a3f94 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0xa4>
 *   @0x2a3f94 mov r0, r5
 *   @0x2a3f98 mlshi r0, r3, pc, pc
 *   @0x2a3f9c mov r0, r5
 *   @0x2a3fa0 adchi pc, r0, pc, lsl #31
 *   @0x2a3fa4 mov r0, r5
 *   @0x2a3fa8 rschi pc, r0, r11, lsl #31
 *   @0x2a3fac mov r0, r5
 *   @0x2a3fb0 strmi pc, [r3], -r7, lsl #31
 *   @0x2a3fb4 mov r0, r5
 *   @0x2a3fb8 bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a3fbc ldr r3, [sp]
 *   @0x2a3fc0 mov r0, r3
 *   @0x2a3fc4 adcvs pc, r0, r8, asr #26
 *   @0x2a3fc8 mov r0, r5
 *   @0x2a3fcc rscvs pc, r0, r2, lsl #31
 *   @0x2a3fd0 mov r0, r5
 *   @0x2a3fd4 .word 0x6120ff7e
 *   @0x2a3fd8 mov r0, r5
 *   @0x2a3fdc .word 0x6160ff7a
 *   @0x2a3fe0 mov r0, r5
 *   @0x2a3fe4 movhi pc, #436
 *   @0x2a3fe8 mov r0, r5
 *   @0x2a3fec ldmdbls r10, {r0, r3, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2a3ff0 strh r0, [r4, #0x24]
 *   @0x2a3ff4 movs r3, #0x0
 *   @0x2a3ff8 strh r3, [r4, #0x2e]
 *   @0x2a3ffc str r3, [r4, #0x34]
 *   @0x2a4000 b 0x2a402a <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x13a>
 *   @0x2a4004 bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a4008 strh r0, [r4, #0x2c]
 *   @0x2a400c bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a4010 strh r0, [r4, #0x2e]
 *   @0x2a4014 bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a4018 strh r0, [r4, #0x30]
 *   @0x2a401c bl 0x2a3ed2 <_Z10_zip_read4PPh>
 *   @0x2a4020 str r0, [r4, #0x34]
 *   @0x2a4024 bl 0x2a3ed2 <_Z10_zip_read4PPh>
 *   @0x2a4028 str r0, [r4, #0x38]
 *   @0x2a402c ldrh r1, [r4, #0x1c]
 *   @0x2a4030 str r3, [r4, #0x20]
 *   @0x2a4034 ldrh r3, [r4, #0x24]
 *   @0x2a4038 add r3, r1
 *   @0x2a403c add r11, r3
 *   @0x2a4040 ldr r3, [r7]
 *   @0x2a4044 blo.w 0x2a3f22 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x32>
 *   @0x2a4048 cmp.w r9, #0x0
 *   @0x2a404c beq 0x2a4094 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1a4>
 *   @0x2a4050 ldrh r1, [r4, #0x24]
 *   @0x2a4054 b 0x2a406c <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x17c>
 *   @0x2a4058 movs r2, #0x1
 *   @0x2a405c bl 0x2a3a98 <zip_close+0x8ac>
 *   @0x2a4060 str r0, [r4, #0x18]
 *   @0x2a4064 bne 0x2a4050 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x160>
 *   @0x2a4068 ldrsht r3, [r7], -pc
 *   @0x2a406c mov r0, r5
 *   @0x2a4070 mov r3, r6
 *   @0x2a4074 eorvs pc, r0, #1088
 *   @0x2a4078 cmp r0, #0x0
 *   @0x2a407c ldrh r1, [r4, #0x2c]
 *   @0x2a4080 beq 0x2a40ec <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1fc>
 *   @0x2a4084 movs r2, #0x0
 *   @0x2a4088 bl 0x2a3a98 <zip_close+0x8ac>
 *   @0x2a408c str r0, [r4, #0x28]
 *   @0x2a4090 bne 0x2a40ec <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1fc>
 *   @0x2a4094 cbnz r1, 0x2a409c <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1ac>
 *   @0x2a4098 cbz r1, 0x2a40be <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1ce>
 *   @0x2a409c mov r0, r10
 *   @0x2a40a0 mov r3, r6
 *   @0x2a40a4 .word 0x61a0fc9d
 *   @0x2a40a8 cmp r0, #0x0
 *   @0x2a40ac b 0x2a4066 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x176>
 *   @0x2a40b0 movs r2, #0x0
 *   @0x2a40b4 bl 0x2a39e0 <zip_close+0x7f4>
 *   @0x2a40b8 str r0, [r4, #0x20]
 *   @0x2a40bc beq 0x2a4066 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x176>
 *   @0x2a40c0 cbz r1, 0x2a40d2 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1e2>
 *   @0x2a40c4 movs r2, #0x0
 *   @0x2a40c8 bl 0x2a39e0 <zip_close+0x7f4>
 *   @0x2a40cc str r0, [r4, #0x28]
 *   @0x2a40d0 beq 0x2a4066 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x176>
 *   @0x2a40d4 ldr r3, [r7]
 *   @0x2a40d8 eorsvs r0, r11, r3, lsl #6
 *   @0x2a40dc ldr r1, [sp, #0x4]
 *   @0x2a40e0 ldr r2, [sp, #0x3c]
 *   @0x2a40e4 cmp r2, r3
 *   @0x2a40e8 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2a40ec ldr r3, [sp, #0x8]
 *   @0x2a40f0 strb r3, [lr, r0]!
 *   @0x2a40f4 add sp, #0x44
 *   @0x2a40f8 svclt #0x8ff0
 *   @0x2a40fc ldr r2, [sp, #0x158]
 *   @0x2a4100 strh r0, [r3, #0x4]
 *   @0x2a4104 strh r7, [r2, #0x4]
 *
 * ══ §34/57 png_write_info  0x2afe14  size 536  134 条（0x2afe14..0x2b002c）
 * @func 0x2afe14 0x2b002c  size 536  134 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_error / png_write_tRNS / png_write_pCAL / png_write_sCAL / png_write_pHYs / png_write_tIME / png_write_sPLT / png_write_zTXt
 * 字段偏移 top8: 0x8×7 / 0x14×3 / 0x4×3 / 0x38×3 / 0x19×2 / 0x4c×2 / 0xc×2 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2afe14 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2afe18 mov r6, r1
 *   @0x2afe1c mov r7, r0
 *   @0x2afe20 beq.w 0x2b0022 <png_write_info+0x20e>
 *   @0x2afe24 cmp r1, #0x0
 *   @0x2afe28 .word 0xf7ff80fc
 *   @0x2afe2c ldmvs r3!, {r0, r5, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2afe30 lsls r2, r3, #0x1c
 *   @0x2afe34 mov r0, r7
 *   @0x2afe38 ldrh r2, [r6, #0x14]
 *   @0x2afe3c and pc, r7, r9, asr #23
 *   @0x2afe40 ldrb r3, [r6, #0x19]
 *   @0x2afe44 bne 0x2afe50 <png_write_info+0x3c>
 *   @0x2afe48 mov r0, r7
 *   @0x2afe4c bl 0x2a642c <png_error>
 *   @0x2afe50 ldr r3, [r6, #0x8]
 *   @0x2afe54 bpl 0x2afe8c <png_write_info+0x78>
 *   @0x2afe58 tsteq sp, #52, #2
 *   @0x2afe5c bmi 0x2afe72 <png_write_info+0x5e>
 *   @0x2afe60 mov r0, r7
 *   @0x2afe64 ldr r1, [r6, #0x4c]
 *   @0x2afe68 add.w r2, r6, #0x50
 *   @0x2afe6c bl 0x2b1d80 <png_write_tRNS>
 *   @0x2afe70 b 0x2afe8c <png_write_info+0x78>
 *   @0x2afe74 cmp r3, #0x3
 *   @0x2afe78 movs r3, #0x0
 *   @0x2afe7c cmp r3, r2
 *   @0x2afe80 ldr r2, [r6, #0x4c]
 *   @0x2afe84 mvns r1, r1
 *   @0x2afe88 adds r3, #0x1
 *   @0x2afe8c ldr r3, [r6, #0x8]
 *   @0x2afe90 bpl 0x2afe9e <png_write_info+0x8a>
 *   @0x2afe94 add.w r1, r6, #0x5a
 *   @0x2afe98 ldrb r2, [r6, #0x19]
 *   @0x2afe9c ldmvs r3!, {r0, r1, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2afea0 lsls r0, r3, #0x19
 *   @0x2afea4 mov r0, r7
 *   @0x2afea8 ldrh r2, [r6, #0x14]
 *   @0x2afeac ldmvs r3!, {r0, r2, r3, r4, r5, r11, r12, sp, lr, pc}
 *   @0x2afeb0 lsls r1, r3, #0x17
 *   @0x2afeb4 mov r0, r7
 *   @0x2afeb8 ldr r2, [r6, #0x68]
 *   @0x2afebc .word 0xf002306c
 *   @0x2afec0 ldmvs r3!, {r0, r1, r3, r7, r8, r11, r12, sp, lr, pc}
 *   @0x2afec4 lsls r2, r3, #0x15
 *   @0x2afec8 ldrb.w r3, [r6, #0xb4]
 *   @0x2afecc add.w r1, r6, #0xa0
 *   @0x2afed0 mov r0, r7
 *   @0x2afed4 ldrb.w r3, [r6, #0xb5]
 *   @0x2afed8 str r3, [sp, #0x4]
 *   @0x2afedc movwls r3, #0x20ac
 *   @0x2afee0 ldr.w r3, [r6, #0xb0]
 *   @0x2afee4 str r3, [sp, #0xc]
 *   @0x2afee8 bl 0x2b2250 <png_write_pCAL>
 *   @0x2afeec ldr r3, [r6, #0x8]
 *   @0x2afef0 bpl 0x2aff08 <png_write_info+0xf4>
 *   @0x2afef4 shasxmi r4, r8, r10
 *   @0x2afef8 ldrb.w r1, [r6, #0xdc]
 *   @0x2afefc ldrd r2, r3, [r6, #224]
 *   @0x2aff00 strd r4, r5, [sp]
 *   @0x2aff04 bl 0x2b2384 <png_write_sCAL>
 *   @0x2aff08 ldr r3, [r6, #0x8]
 *   @0x2aff0c bpl 0x2aff1c <png_write_info+0x108>
 *   @0x2aff10 ldr r1, [r6, #0x70]
 *   @0x2aff14 ldrb.w r3, [r6, #0x78]
 *   @0x2aff18 bl 0x2b2418 <png_write_pHYs>
 *   @0x2aff1c ldr r3, [r6, #0x8]
 *   @0x2aff20 bpl 0x2aff38 <png_write_info+0x124>
 *   @0x2aff24 add.w r1, r6, #0x3c
 *   @0x2aff28 bl 0x2b2490 <png_write_tIME>
 *   @0x2aff2c ldr.w r3, [r7, #0x12c]
 *   @0x2aff30 orr r3, r3, #0x200
 *   @0x2aff34 str.w r3, [r7, #0x12c]
 *   @0x2aff38 ldr r3, [r6, #0x8]
 *   @0x2aff3c bpl 0x2aff42 <png_write_info+0x12e>
 *   @0x2aff40 b 0x2aff54 <png_write_info+0x140>
 *   @0x2aff44 .word 0xf04f0800
 *   @0x2aff48 .word 0xf06f0a1c
 *   @0x2aff4c .word 0xf06f0902
 *   @0x2aff50 ands r0, r8, r1, lsl #22
 *   @0x2aff54 ldr.w r3, [r6, #0xd8]
 *   @0x2aff58 cmp r4, r3
 *   @0x2aff5c ldr.w r1, [r6, #0xd4]
 *   @0x2aff60 mov r0, r7
 *   @0x2aff64 strlo r1, [r1], #-260
 *   @0x2aff68 bl 0x2b198c <png_write_sPLT>
 *   @0x2aff6c b 0x2aff54 <png_write_info+0x140>
 *   @0x2aff70 str r3, [sp]
 *   @0x2aff74 ldr r1, [r4, #0x4]
 *   @0x2aff78 bl 0x2b2004 <png_write_zTXt>
 *   @0x2aff7c ldr r3, [r6, #0x38]
 *   @0x2aff80 .word 0xf108b005
 *   @0x2aff84 blvs 0xf71f90 <b2_toiTime+0x818aec>
 *   @0x2aff88 cmp r8, r3
 *   @0x2aff8c mul r5, r10, r8
 *   @0x2aff90 ldr r3, [r6, #0x38]
 *   @0x2aff94 ldr r3, [r3, r5]
 *   @0x2aff98 ble 0x2aff6e <png_write_info+0x15a>
 *   @0x2aff9c mov r1, r3
 *   @0x2affa0 str r2, [sp]
 *   @0x2affa4 str r2, [sp, #0x4]
 *   @0x2affa8 ldr r3, [r4, #0x14]
 *   @0x2affac and pc, r7, r5, lsl #17
 *   @0x2affb0 adds r3, #0x1
 *   @0x2affb4 mov r0, r7
 *   @0x2affb8 ldr r2, [r4, #0x8]
 *   @0x2affbc bl 0x2b1f94 <png_write_tEXt>
 *   @0x2affc0 ldr r3, [r6, #0x38]
 *   @0x2affc4 ldrb r9, [r12, r5]
 *   @0x2affc8 ldr.w r3, [r6, #0xc0]
 *   @0x2affcc cbz r3, 0x2b0022 <png_write_info+0x20e>
 *   @0x2affd0 ldrhs r4, [r4, #-0xbc]
 *   @0x2affd4 ldr.w r2, [r6, #0xc0]
 *   @0x2affd8 ldr.w r3, [r6, #0xbc]
 *   @0x2affdc mla r3, r5, r2, r3
 *   @0x2affe0 cmp r4, r3
 *   @0x2affe4 mov r0, r7
 *   @0x2affe8 bl 0x2a5fe4 <png_handle_as_unknown>
 *   @0x2affec cmp r0, #0x1
 *   @0x2afff0 ldrb r3, [r4, #0x10]
 *   @0x2afff4 and r2, r3, #0x6
 *   @0x2afff8 cmp r2, #0x2
 *   @0x2afffc lsls r1, r3, #0x1c
 *   @0x2b0000 ldrb r3, [r4, #0x3]
 *   @0x2b0004 bmi 0x2b0012 <png_write_info+0x1fe>
 *   @0x2b0008 beq 0x2b0012 <png_write_info+0x1fe>
 *   @0x2b000c bicseq r3, r11, #48, #2
 *   @0x2b0010 bpl 0x2b001e <png_write_info+0x20a>
 *   @0x2b0014 mov r1, r4
 *   @0x2b0018 ldr r3, [r4, #0xc]
 *   @0x2b001c ldrlo pc, [r4], #-2383
 *   @0x2b0020 b 0x2affd4 <png_write_info+0x1c0>
 *   @0x2b0024 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b0028 b 0x2b019c <png_create_write_struct_2+0x18>
 *
 * ══ §35/57 F_BUFFER_Copy_From_Vertex_Buffer(RValue&, CInstance*, CInstance*, int, RValue*)  0xc6498  size 532  133 条（0xc6498..0xc66ac）
 * @func 0xc6498 0xc66ac  size 532  133 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / GetBufferVertex(int) / F_BUFFER_Copy_From_Vertex_Buffer(RValue&, CInstance*, CInstance*, int, RValue*)+0x1d4 / F_BUFFER_Copy_From_Vertex_Buffer(RValue&, CInstance*, CInstance*, int, RValue*)+0x1b8 / GetVertexFormat(int) / F_BUFFER_Copy_From_Vertex_Buffer(RValue&, CInstance*, CInstance*, int, RValue*)+0x194 / IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool) / IsBigEndian()
 * 字段偏移 top8: 0x4×4 / 0x10×3 / 0x1c×2 / 0x28×2 / 0x2×2 / 0xc×2 / 0x38×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6498 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc649c sub sp, sp, #24
 *   @0xc64a0 mov r1, #0
 *   @0xc64a4 ldr r4, [sp, #0x38]
 *   @0xc64a8 mov r0, r4
 *   @0xc64ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc64b0 mov r1, #1
 *   @0xc64b4 mov r7, r0
 *   @0xc64b8 mov r0, r4
 *   @0xc64bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc64c0 mov r1, #2
 *   @0xc64c4 mov r5, r0
 *   @0xc64c8 mov r0, r4
 *   @0xc64cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc64d0 mov r1, #3
 *   @0xc64d4 mov r6, r0
 *   @0xc64d8 mov r0, r4
 *   @0xc64dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc64e0 mov r1, #4
 *   @0xc64e4 mov r8, r0
 *   @0xc64e8 mov r0, r4
 *   @0xc64ec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc64f0 mov r9, r0
 *   @0xc64f4 mov r0, r7
 *   @0xc64f8 bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xc64fc subs r4, r0, #0
 *   @0xc6500 beq 0xc665c <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0xc6504 ldrb r1, [r4, #0x20]
 *   @0xc6508 ldr r0, [pc, #0x178]
 *   @0xc650c cmp r1, #0
 *   @0xc6510 add r0, pc, r0
 *   @0xc6514 bne 0xc6634 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0xc6518 ldr r12, [r4, #0x1c]
 *   @0xc651c cmp r12, #0
 *   @0xc6520 beq 0xc6644 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0xc6524 ldr r0, [r4, #0x28]
 *   @0xc6528 cmn r0, #1
 *   @0xc652c beq 0xc6644 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0xc6530 cmp r6, #0
 *   @0xc6534 ble 0xc666c <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0xc6538 cmp r5, #0
 *   @0xc653c blt 0xc6650 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0xc6540 cmp r5, r12
 *   @0xc6544 bge 0xc6650 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0xc6548 add r3, r5, r6
 *   @0xc654c cmp r12, r3
 *   @0xc6550 rsblt r6, r5, r12
 *   @0xc6554 bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0xc6558 subs r7, r0, #0
 *   @0xc655c beq 0xc6678 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0xc6560 cmp r8, #0
 *   @0xc6564 ldr r12, [r7, #0x14]
 *   @0xc6568 blt 0xc662c <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0xc656c ldr r3, [pc, #0x118]
 *   @0xc6570 add r3, pc, r3
 *   @0xc6574 ldr r2, [r3]
 *   @0xc6578 cmp r8, r2
 *   @0xc657c bge 0xc662c <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0xc6580 ldr r3, [r3, #0x4]
 *   @0xc6584 ldr r0, [r3, r8, lsl #2]
 *   @0xc6588 cmp r0, #0
 *   @0xc658c beq 0xc662c <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0xc6590 ldr r10, [r0, #0x18]
 *   @0xc6594 ldr r2, [r4, #0x1c]
 *   @0xc6598 cmp r10, #1
 *   @0xc659c mul r3, r12, r5
 *   @0xc65a0 moveq lr, r10
 *   @0xc65a4 mul r2, r2, r12
 *   @0xc65a8 beq 0xc65b8 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0xc65ac ldr lr, [r0, #0x10]
 *   @0xc65b0 rsbs lr, lr, #1
 *   @0xc65b4 movlo lr, #0
 *   @0xc65b8 mul r12, r12, r6
 *   @0xc65bc subs r5, r10, #2
 *   @0xc65c0 ldr r1, [r4]
 *   @0xc65c4 rsbs r4, r5, #0
 *   @0xc65c8 adcs r4, r4, r5
 *   @0xc65cc str lr, [sp, #0x8]
 *   @0xc65d0 str r9, [sp, #0x4]
 *   @0xc65d4 str r4, [sp, #0xc]
 *   @0xc65d8 str r12, [sp]
 *   @0xc65dc mov r12, #0
 *   @0xc65e0 str r12, [sp, #0x10]
 *   @0xc65e4 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb>
 *   @0xc65e8 bl 0x212e98 <_Z11IsBigEndianv>
 *   @0xc65ec cmp r0, #0
 *   @0xc65f0 beq 0xc6624 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0xc65f4 ldr r1, [pc, #0x94]
 *   @0xc65f8 mov r0, r7
 *   @0xc65fc mov r2, r6
 *   @0xc6600 mov r3, r9
 *   @0xc6604 add r1, pc, r1
 *   @0xc6608 ldr r1, [r1, #0x4]
 *   @0xc660c ldr r12, [r1, r8, lsl #2]
 *   @0xc6610 ldr r1, [r12, #0xc]
 *   @0xc6614 ldr r12, [r12, #0x10]
 *   @0xc6618 str r4, [sp, #0x4]
 *   @0xc661c str r12, [sp]
 *   @0xc6620 bl 0x1e251c <_ZN12VertexFormat16EndianSwapBufferEPhiiib>
 *   @0xc6624 add sp, sp, #24
 *   @0xc6628 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xc662c ldr r0, [pc, #0x60]
 *   @0xc6630 add r0, pc, r0
 *   @0xc6634 mov r1, #0
 *   @0xc6638 add sp, sp, #24
 *   @0xc663c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc6640 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6644 ldr r0, [pc, #0x4c]
 *   @0xc6648 add r0, pc, r0
 *   @0xc664c b 0xc6634 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0xc6650 ldr r0, [pc, #0x44]
 *   @0xc6654 add r0, pc, r0
 *   @0xc6658 b 0xc6634 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0xc665c ldr r0, [pc, #0x3c]
 *   @0xc6660 mov r1, r4
 *   @0xc6664 add r0, pc, r0
 *   @0xc6668 b 0xc6638 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0xc666c ldr r0, [pc, #0x30]
 *   @0xc6670 add r0, pc, r0
 *   @0xc6674 b 0xc6638 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0xc6678 ldr r0, [pc, #0x28]
 *   @0xc667c mov r1, r7
 *   @0xc6680 add r0, pc, r0
 *   @0xc6684 b 0xc6638 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0xc6688 eoreq r10, r6, r4, lsl #19
 *   @0xc668c eorseq r3, r11, r4, lsr #23
 *   @0xc6690 eorseq r3, r11, r0, lsl r11
 *   @0xc6694 .word 0x0026a9bc
 *   @0xc6698 mlaeq r6, r4, r8, r10
 *   @0xc669c eoreq r10, r6, r4, lsl r9
 *   @0xc66a0 .word 0x0026a7f4
 *   @0xc66a4 .word 0x0026a8b4
 *   @0xc66a8 eoreq r10, r6, r0, lsr r9
 *
 * ══ §36/57 F_SpriteCreateFromSurface(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b96c  size 532  133 条（0x12b96c..0x12bb80）
 * @func 0x12b96c 0x12bb80  size 532  133 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×15 / 0xb66e8×2 / Sprite_Data(int)×2 / CSprite::CreateFromBitmap(IBitmap*, bool, bool, bool, bool, int, int, bool)×2 / Sprite_AddEmpty() / GR_Surface_Screenshot_Part(int, int, int, int, int)
 * 字段偏移 top8: 0xc×3 / 0x4×3 / 0x8×2 / 0x10×2 / 0x40×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b96c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x12b970 sub sp, sp, #28
 *   @0x12b974 mov r7, #0
 *   @0x12b978 str r7, [r0, #0xc]
 *   @0x12b97c ldr r4, [sp, #0x40]
 *   @0x12b980 mov r5, r0
 *   @0x12b984 mov r8, r3
 *   @0x12b988 bl 0x1ef890 <_Z15Sprite_AddEmptyv>
 *   @0x12b98c mov r1, r7
 *   @0x12b990 vmov s15, r0
 *   @0x12b994 mov r0, r4
 *   @0x12b998 vcvt.f64.s32 d7, s15
 *   @0x12b99c vmov r2, r3, d7
 *   @0x12b9a0 stm r5, {r2, r3}
 *   @0x12b9a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b9a8 mov r1, #1
 *   @0x12b9ac mov r6, r0
 *   @0x12b9b0 mov r0, r4
 *   @0x12b9b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b9b8 mov r1, #2
 *   @0x12b9bc mov r11, r0
 *   @0x12b9c0 mov r0, r4
 *   @0x12b9c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b9c8 mov r1, #3
 *   @0x12b9cc mov r10, r0
 *   @0x12b9d0 mov r0, r4
 *   @0x12b9d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b9d8 mov r1, #4
 *   @0x12b9dc mov r9, r0
 *   @0x12b9e0 mov r0, r4
 *   @0x12b9e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b9e8 mov r1, r11
 *   @0x12b9ec mov r2, r10
 *   @0x12b9f0 mov r3, r9
 *   @0x12b9f4 str r0, [sp]
 *   @0x12b9f8 mov r0, r6
 *   @0x12b9fc bl 0x1720e4 <_Z26GR_Surface_Screenshot_Partiiiii>
 *   @0x12ba00 subs r6, r0, #0
 *   @0x12ba04 beq 0x12bab4 <_Z25F_SpriteCreateFromSurfaceR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x12ba08 cmp r8, #11
 *   @0x12ba0c beq 0x12babc <_Z25F_SpriteCreateFromSurfaceR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x12ba10 mov r1, #5
 *   @0x12ba14 mov r0, r4
 *   @0x12ba18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ba1c ldm r5, {r2, r3}
 *   @0x12ba20 mov r1, r3
 *   @0x12ba24 cmp r0, #0
 *   @0x12ba28 mov r0, r2
 *   @0x12ba2c movle r5, #0
 *   @0x12ba30 movgt r5, #1
 *   @0x12ba34 bl 0xb66e8 <lrint@plt>
 *   @0x12ba38 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12ba3c mov r1, #6
 *   @0x12ba40 mov r8, r0
 *   @0x12ba44 mov r0, r4
 *   @0x12ba48 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ba4c mov r1, #7
 *   @0x12ba50 mov r10, r0
 *   @0x12ba54 mov r0, r4
 *   @0x12ba58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ba5c mov r1, #8
 *   @0x12ba60 mov r9, r0
 *   @0x12ba64 mov r0, r4
 *   @0x12ba68 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ba6c cmp r10, #0
 *   @0x12ba70 eor r2, r5, #1
 *   @0x12ba74 str r9, [sp, #0x8]
 *   @0x12ba78 movle r10, #0
 *   @0x12ba7c movgt r10, #1
 *   @0x12ba80 str r2, [sp, #0x10]
 *   @0x12ba84 mov r3, r5
 *   @0x12ba88 str r10, [sp]
 *   @0x12ba8c mov r1, r6
 *   @0x12ba90 str r7, [sp, #0x4]
 *   @0x12ba94 mov r2, #1
 *   @0x12ba98 str r0, [sp, #0xc]
 *   @0x12ba9c mov r0, r8
 *   @0x12baa0 bl 0x1e74ac <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib>
 *   @0x12baa4 ldr r3, [r6]
 *   @0x12baa8 mov r0, r6
 *   @0x12baac ldr r3, [r3, #0x4]
 *   @0x12bab0 blx r3
 *   @0x12bab4 add sp, sp, #28
 *   @0x12bab8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x12babc ldm r5, {r0, r1}
 *   @0x12bac0 bl 0xb66e8 <lrint@plt>
 *   @0x12bac4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12bac8 mov r1, #5
 *   @0x12bacc mov r5, r0
 *   @0x12bad0 mov r0, r4
 *   @0x12bad4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bad8 mov r1, #6
 *   @0x12badc mov r9, r0
 *   @0x12bae0 mov r0, r4
 *   @0x12bae4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bae8 mov r1, #7
 *   @0x12baec mov r7, r0
 *   @0x12baf0 mov r0, r4
 *   @0x12baf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12baf8 mov r1, #8
 *   @0x12bafc mov r11, r0
 *   @0x12bb00 mov r0, r4
 *   @0x12bb04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bb08 mov r1, #9
 *   @0x12bb0c mov r10, r0
 *   @0x12bb10 mov r0, r4
 *   @0x12bb14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bb18 mov r1, #10
 *   @0x12bb1c mov r8, r0
 *   @0x12bb20 mov r0, r4
 *   @0x12bb24 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bb28 cmp r11, #0
 *   @0x12bb2c mov r12, #1
 *   @0x12bb30 str r8, [sp, #0x8]
 *   @0x12bb34 movle r11, #0
 *   @0x12bb38 movgt r11, #1
 *   @0x12bb3c cmp r10, #0
 *   @0x12bb40 str r11, [sp]
 *   @0x12bb44 mov r1, r6
 *   @0x12bb48 str r12, [sp, #0x10]
 *   @0x12bb4c movle r10, #0
 *   @0x12bb50 movgt r10, #1
 *   @0x12bb54 cmp r9, #0
 *   @0x12bb58 str r10, [sp, #0x4]
 *   @0x12bb5c movle r2, #0
 *   @0x12bb60 movgt r2, #1
 *   @0x12bb64 cmp r7, #0
 *   @0x12bb68 movle r3, #0
 *   @0x12bb6c movgt r3, #1
 *   @0x12bb70 str r0, [sp, #0xc]
 *   @0x12bb74 mov r0, r5
 *   @0x12bb78 bl 0x1e74ac <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib>
 *   @0x12bb7c b 0x12baa4 <_Z25F_SpriteCreateFromSurfaceR6RValueP9CInstanceS2_iPS_+0x138>
 *
 * ══ §37/57 CIAPPurchase::PopulateMap(int)  0x18ae38  size 532  133 条（0x18ae38..0x18b04c）
 * @func 0x18ae38 0x18b04c  size 532  133 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, char const*)×11 / F_DsMapAdd(RValue&, CInstance*, CInstance*, int, RValue*)×8 / YYSetString(RValue*, char const*)×2 / F_DsMapClear(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x24×1 / 0x1a4×1 / 0x4×1 / 0x174×1 / 0x144×1 / 0x8×1 / 0x114×1 / 0x10×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ae38 vmov s13, r1
 *   @0x18ae3c mov r3, #1
 *   @0x18ae40 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18ae44 vcvt.f64.s32 d7, s13
 *   @0x18ae48 sub sp, sp, #76
 *   @0x18ae4c mov r4, #0
 *   @0x18ae50 add r5, sp, #8
 *   @0x18ae54 mov r7, r0
 *   @0x18ae58 add r6, sp, #24
 *   @0x18ae5c mov r2, r4
 *   @0x18ae60 mov r1, r4
 *   @0x18ae64 mov r0, r5
 *   @0x18ae68 str r6, [sp]
 *   @0x18ae6c add r8, sp, #40
 *   @0x18ae70 str r4, [sp, #0x24]
 *   @0x18ae74 add r9, sp, #56
 *   @0x18ae78 vstr d7, [sp, #24]
 *   @0x18ae7c bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_>
 *   @0x18ae80 ldr r1, [pc, #0x1a4]
 *   @0x18ae84 mov r0, r8
 *   @0x18ae88 add r1, pc, r1
 *   @0x18ae8c bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x18ae90 ldr r1, [r7, #0x4]
 *   @0x18ae94 mov r0, r9
 *   @0x18ae98 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x18ae9c mov r2, r4
 *   @0x18aea0 mov r3, #3
 *   @0x18aea4 mov r0, r5
 *   @0x18aea8 mov r1, r4
 *   @0x18aeac str r6, [sp]
 *   @0x18aeb0 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18aeb4 ldr r1, [pc, #0x174]
 *   @0x18aeb8 mov r0, r8
 *   @0x18aebc add r1, pc, r1
 *   @0x18aec0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18aec4 mov r0, r9
 *   @0x18aec8 ldr r1, [r7]
 *   @0x18aecc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18aed0 mov r2, r4
 *   @0x18aed4 mov r3, #3
 *   @0x18aed8 mov r0, r5
 *   @0x18aedc mov r1, r4
 *   @0x18aee0 str r6, [sp]
 *   @0x18aee4 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18aee8 ldr r1, [pc, #0x144]
 *   @0x18aeec mov r0, r8
 *   @0x18aef0 add r1, pc, r1
 *   @0x18aef4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18aef8 mov r0, r9
 *   @0x18aefc ldr r1, [r7, #0x8]
 *   @0x18af00 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18af04 mov r2, r4
 *   @0x18af08 mov r3, #3
 *   @0x18af0c mov r0, r5
 *   @0x18af10 mov r1, r4
 *   @0x18af14 str r6, [sp]
 *   @0x18af18 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18af1c ldr r1, [pc, #0x114]
 *   @0x18af20 mov r0, r8
 *   @0x18af24 add r1, pc, r1
 *   @0x18af28 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18af2c mov r0, r9
 *   @0x18af30 ldr r1, [r7, #0x10]
 *   @0x18af34 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18af38 mov r2, r4
 *   @0x18af3c mov r3, #3
 *   @0x18af40 mov r0, r5
 *   @0x18af44 mov r1, r4
 *   @0x18af48 str r6, [sp]
 *   @0x18af4c bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18af50 ldr r1, [pc, #0xe4]
 *   @0x18af54 mov r0, r8
 *   @0x18af58 add r1, pc, r1
 *   @0x18af5c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18af60 mov r0, r9
 *   @0x18af64 ldr r1, [r7, #0xc]
 *   @0x18af68 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18af6c mov r2, r4
 *   @0x18af70 mov r0, r5
 *   @0x18af74 mov r1, r4
 *   @0x18af78 mov r3, #3
 *   @0x18af7c str r6, [sp]
 *   @0x18af80 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18af84 ldr r1, [pc, #0xb4]
 *   @0x18af88 mov r0, r8
 *   @0x18af8c add r1, pc, r1
 *   @0x18af90 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18af94 vldr s14, [r7, #28]
 *   @0x18af98 vcvt.f64.s32 d7, s14
 *   @0x18af9c mov r2, r4
 *   @0x18afa0 mov r0, r5
 *   @0x18afa4 mov r1, r4
 *   @0x18afa8 mov r3, #3
 *   @0x18afac str r6, [sp]
 *   @0x18afb0 str r4, [sp, #0x44]
 *   @0x18afb4 vstr d7, [sp, #56]
 *   @0x18afb8 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18afbc ldr r1, [pc, #0x80]
 *   @0x18afc0 mov r0, r8
 *   @0x18afc4 add r1, pc, r1
 *   @0x18afc8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18afcc vldr s14, [r7, #24]
 *   @0x18afd0 vcvt.f64.s32 d7, s14
 *   @0x18afd4 mov r2, r4
 *   @0x18afd8 mov r0, r5
 *   @0x18afdc mov r1, r4
 *   @0x18afe0 mov r3, #3
 *   @0x18afe4 str r6, [sp]
 *   @0x18afe8 vstr d7, [sp, #56]
 *   @0x18afec bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18aff0 ldr r1, [pc, #0x50]
 *   @0x18aff4 mov r0, r8
 *   @0x18aff8 add r1, pc, r1
 *   @0x18affc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18b000 vldr s14, [r7, #20]
 *   @0x18b004 vcvt.f64.s32 d7, s14
 *   @0x18b008 mov r1, r4
 *   @0x18b00c str r6, [sp]
 *   @0x18b010 mov r0, r5
 *   @0x18b014 mov r2, r4
 *   @0x18b018 mov r3, #3
 *   @0x18b01c vstr d7, [sp, #56]
 *   @0x18b020 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18b024 add sp, sp, #76
 *   @0x18b028 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18b02c andseq r11, r11, r8, lsr #5
 *   @0x18b030 andseq r1, r12, r8, lsl #6
 *   @0x18b034 andseq r1, r12, r12, asr #5
 *   @0x18b038 andseq r11, r11, r4, lsr #4
 *   @0x18b03c andseq r11, r11, r4, asr #5
 *   @0x18b040 andseq r5, r10, r4, asr #21
 *   @0x18b044 andseq r1, r12, r8, lsl #4
 *   @0x18b048 andseq r11, r11, r8, lsl r2
 *
 * ══ §38/57 CInstance::ChangeObjectIndex(int)  0x193368  size 532  126 条（0x193368..0x19357c）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x193368 0x19357c  size 532  126 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x193378→0x542a64, 0x1933b4→0x542374, 0x19340c→0x5428e8, 0x19345c→0x54298c, 0x193498→0x542a58
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / CInstance::SetSpriteIndex(int) / CInstance::RebuildPhysicsBody(CRoom*) / CInstance::ChangeObjectIndex(int)+0x180
 * 字段偏移 top8: 0x4×6 / 0x8×5 / 0x2×2 / 0x80×2 / 0x1e4×1 / 0x1e0×1 / 0x168×1 / 0x7c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x193368 push {r4, r5, r6, r7, lr}
 *   @0x19336c mov r4, r0
 *   @0x193370 ldr r6, [pc, #0x1e4]
 *   @0x193374 sub sp, sp, #12
 *   @0x193378 ldr r3, [pc, #0x1e0]
 *   @0x19337c mov r5, r1
 *   @0x193380 add r6, pc, r6
 *   @0x193384 ldr r7, [r6, r3]
 *   @0x193388 ldm r7, {r0, r3, r12}
 *   @0x19338c cmp r12, r3
 *   @0x193390 beq 0x1934f8 <_ZN9CInstance17ChangeObjectIndexEi+0x190>
 *   @0x193394 str r4, [r0, r12, lsl #2]
 *   @0x193398 add r12, r12, #1
 *   @0x19339c ldr r3, [r4, #0x168]
 *   @0x1933a0 str r12, [r7, #0x8]
 *   @0x1933a4 cmp r3, #0
 *   @0x1933a8 str r5, [r4, #0x7c]
 *   @0x1933ac ldreq r3, [r4, #0x80]
 *   @0x1933b0 streq r3, [r4, #0x168]
 *   @0x1933b4 ldr r3, [pc, #0x1a8]
 *   @0x1933b8 ldr r3, [r6, r3]
 *   @0x1933bc ldr r3, [r3]
 *   @0x1933c0 ldr r2, [r3, #0x4]
 *   @0x1933c4 ldr r3, [r3]
 *   @0x1933c8 and r2, r5, r2
 *   @0x1933cc ldr r3, [r3, r2, lsl #3]
 *   @0x1933d0 cmp r3, #0
 *   @0x1933d4 bne 0x1933e8 <_ZN9CInstance17ChangeObjectIndexEi+0x80>
 *   @0x1933d8 b 0x193488 <_ZN9CInstance17ChangeObjectIndexEi+0x120>
 *   @0x1933dc ldr r3, [r3, #0x4]
 *   @0x1933e0 cmp r3, #0
 *   @0x1933e4 beq 0x193488 <_ZN9CInstance17ChangeObjectIndexEi+0x120>
 *   @0x1933e8 ldr r2, [r3, #0x8]
 *   @0x1933ec cmp r5, r2
 *   @0x1933f0 bne 0x1933dc <_ZN9CInstance17ChangeObjectIndexEi+0x74>
 *   @0x1933f4 ldr r3, [r3, #0xc]
 *   @0x1933f8 cmp r3, #0
 *   @0x1933fc str r3, [r4, #0x80]
 *   @0x193400 beq 0x193490 <_ZN9CInstance17ChangeObjectIndexEi+0x128>
 *   @0x193420 cmp r2, #0
 *   @0x193424 vldreq s14, [r3, #8]
 *   @0x193428 ldr r2, [r3]
 *   @0x19342c vcvteq.f32.s32 s15, s14
 *   @0x193430 ubfx r3, r2, #0x1, #0x1
 *   @0x193434 and r12, r2, #1
 *   @0x193438 strb r3, [r4, #0x65]
 *   @0x19343c ubfx r2, r2, #0x2, #0x1
 *   @0x193440 strb r12, [r4, #0x66]
 *   @0x193444 strb r2, [r4, #0x67]
 *   @0x193448 vstreq s15, [r4, #384]
 *   @0x19344c bl 0x1931c0 <_ZN9CInstance14SetSpriteIndexEi>
 *   @0x193450 ldrb r3, [r5]
 *   @0x193454 cmp r3, #0
 *   @0x193458 beq 0x193498 <_ZN9CInstance17ChangeObjectIndexEi+0x130>
 *   @0x19345c ldr r3, [pc, #0x108]
 *   @0x193460 mov r0, r4
 *   @0x193464 ldr r3, [r6, r3]
 *   @0x193468 ldr r1, [r3]
 *   @0x19346c bl 0x192fa4 <_ZN9CInstance18RebuildPhysicsBodyEP5CRoom>
 *   @0x193470 mov r3, #1
 *   @0x193474 mov r0, r4
 *   @0x193478 strb r3, [r4, #0x64]
 *   @0x19347c add sp, sp, #12
 *   @0x193480 pop {r4, r5, r6, r7, lr}
 *   @0x193484 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance>
 *   @0x193488 mov r3, #0
 *   @0x19348c str r3, [r4, #0x80]
 *   @0x193490 add sp, sp, #12
 *   @0x193494 pop {r4, r5, r6, r7, pc}
 *   @0x193498 ldr r2, [pc, #0xd0]
 *   @0x19349c ldr r5, [r6, r2]
 *   @0x1934a0 ldmib r5, {r2, r12}
 *   @0x1934a4 cmp r12, r2
 *   @0x1934a8 beq 0x193528 <_ZN9CInstance17ChangeObjectIndexEi+0x1c0>
 *   @0x1934ac ldr lr, [r5]
 *   @0x1934b0 cmp r12, #0
 *   @0x1934b4 ble 0x1934e8 <_ZN9CInstance17ChangeObjectIndexEi+0x180>
 *   @0x1934b8 ldr r3, [lr]
 *   @0x1934bc cmp r4, r3
 *   @0x1934c0 beq 0x19345c <_ZN9CInstance17ChangeObjectIndexEi+0xf4>
 *   @0x1934c4 mov r2, lr
 *   @0x1934c8 mov r3, #0
 *   @0x1934cc b 0x1934dc <_ZN9CInstance17ChangeObjectIndexEi+0x174>
 *   @0x1934d0 ldr r1, [r2, #0x4]!
 *   @0x1934d4 cmp r4, r1
 *   @0x1934d8 beq 0x19345c <_ZN9CInstance17ChangeObjectIndexEi+0xf4>
 *   @0x1934dc add r3, r3, #1
 *   @0x1934e0 cmp r3, r12
 *   @0x1934e4 bne 0x1934d0 <_ZN9CInstance17ChangeObjectIndexEi+0x168>
 *   @0x1934e8 str r4, [lr, r12, lsl #2]
 *   @0x1934ec add r12, r12, #1
 *   @0x1934f0 str r12, [r5, #0x8]
 *   @0x1934f4 b 0x19345c <_ZN9CInstance17ChangeObjectIndexEi+0xf4>
 *   @0x1934f8 ldr r2, [pc, #0x74]
 *   @0x1934fc mov r3, #0
 *   @0x193500 lsl r1, r12, #3
 *   @0x193504 str r3, [sp]
 *   @0x193508 lsl r12, r12, #1
 *   @0x19350c add r2, pc, r2
 *   @0x193510 str r12, [r7, #0x4]
 *   @0x193514 mov r3, #74
 *   @0x193518 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x19351c ldr r12, [r7, #0x8]
 *   @0x193520 str r0, [r7]
 *   @0x193524 b 0x193394 <_ZN9CInstance17ChangeObjectIndexEi+0x2c>
 *   @0x193528 ldr r2, [pc, #0x48]
 *   @0x19352c lsl r1, r12, #3
 *   @0x193530 ldr r0, [r5]
 *   @0x193534 lsl r12, r12, #1
 *   @0x193538 str r3, [sp]
 *   @0x19353c add r2, pc, r2
 *   @0x193540 str r12, [r5, #0x4]
 *   @0x193544 mov r3, #74
 *   @0x193548 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x19354c ldr r12, [r5, #0x8]
 *   @0x193550 mov lr, r0
 *   @0x193554 str r0, [r5]
 *   @0x193558 b 0x1934b0 <_ZN9CInstance17ChangeObjectIndexEi+0x148>
 *   @0x19355c .word 0x0025e8d0
 *   @0x193560 .word 0xffffbff0
 *   @0x193564 .word 0xffffbfec
 *   @0x193568 .word 0xffffbcd4
 *   @0x19356c .word 0xffffbcd8
 *   @0x193570 .word 0xffffc454
 *   @0x193574 andseq sp, r9, r4, lsr #22
 *   @0x193578 ldrsheq sp, [r9], -r4
 *
 * ══ §39/57 Eff_Effect09(int, float, float, int, unsigned int)  0x1a1c9c  size 532  133 条（0x1a1c9c..0x1a1eb0）
 * @func 0x1a1c9c 0x1a1eb0  size 532  133 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a1cc8→0x5423ec
 * 调用序列: 0xb66e8×6 / ParticleType_Shape(int, int)×3 / ParticleType_Size(int, float, float, float, float)×3 / ParticleType_Scale(int, float, float)×3 / ParticleType_Alpha3(int, float, float, float)×3 / ParticleType_Life(int, int, int)×3 / Speed_Factor() / ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)
 * 字段偏移 top8: 0x4×7 / 0x8×6 / 0x1e0×1 / 0x1dc×1 / 0x30×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a1c9c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a1ca0 vpush {d8}
 *   @0x1a1ca4 sub sp, sp, #12
 *   @0x1a1ca8 mov r4, r3
 *   @0x1a1cac mov r7, r1
 *   @0x1a1cb0 mov r8, r0
 *   @0x1a1cb4 mov r6, r2
 *   @0x1a1cb8 bl 0x19ff6c <_Z12Speed_Factorv>
 *   @0x1a1cbc cmp r4, #0
 *   @0x1a1cc0 ldr r12, [pc, #0x1e0]
 *   @0x1a1cc4 mov r1, #10
 *   @0x1a1cc8 ldr r3, [pc, #0x1dc]
 *   @0x1a1ccc mov r5, #0
 *   @0x1a1cd0 add r12, pc, r12
 *   @0x1a1cd4 vmov s16, r0
 *   @0x1a1cd8 beq 0x1a1d98 <_Z12Eff_Effect09iffij+0xfc>
 *   @0x1a1cdc cmp r4, #2
 *   @0x1a1ce0 ldr r4, [r12, r3]
 *   @0x1a1ce4 beq 0x1a1e20 <_Z12Eff_Effect09iffij+0x184>
 *   @0x1a1ce8 ldr r0, [r4, #0x4]
 *   @0x1a1cec bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a1cf0 mov r1, #0
 *   @0x1a1cf4 movt r1, #0x4080
 *   @0x1a1cf8 mov r3, r5
 *   @0x1a1cfc ldr r0, [r4, #0x4]
 *   @0x1a1d00 mov r2, r1
 *   @0x1a1d04 str r5, [sp]
 *   @0x1a1d08 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a1d0c ldr r0, [r4, #0x4]
 *   @0x1a1d10 mov r1, #1065353216
 *   @0x1a1d14 mov r2, #1056964608
 *   @0x1a1d18 bl 0x1a3278 <_Z18ParticleType_Scaleiff>
 *   @0x1a1d1c mov r3, r5
 *   @0x1a1d20 mov r1, r5
 *   @0x1a1d24 ldr r0, [r4, #0x4]
 *   @0x1a1d28 movw r2, #0x999a
 *   @0x1a1d2c movt r2, #0x3e99
 *   @0x1a1d30 bl 0x1a36f8 <_Z19ParticleType_Alpha3ifff>
 *   @0x1a1d34 vldr s15, [pc, #360]
 *   @0x1a1d38 vdiv.f32 s16, s15, s16
 *   @0x1a1d3c ldr r9, [r4, #0x4]
 *   @0x1a1d40 vcvt.f64.f32 d8, s16
 *   @0x1a1d44 vmov r0, r1, d8
 *   @0x1a1d48 bl 0xb66e8 <lrint@plt>
 *   @0x1a1d4c mov r5, r0
 *   @0x1a1d50 vmov r0, r1, d8
 *   @0x1a1d54 bl 0xb66e8 <lrint@plt>
 *   @0x1a1d58 mov r1, r5
 *   @0x1a1d5c mov r2, r0
 *   @0x1a1d60 mov r0, r9
 *   @0x1a1d64 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a1d68 ldr r3, [r4, #0x4]
 *   @0x1a1d6c ldr r2, [sp, #0x30]
 *   @0x1a1d70 mov r12, #1
 *   @0x1a1d74 mov r0, r8
 *   @0x1a1d78 mov r1, r7
 *   @0x1a1d7c str r12, [sp, #0x4]
 *   @0x1a1d80 str r2, [sp]
 *   @0x1a1d84 mov r2, r6
 *   @0x1a1d88 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a1d8c add sp, sp, #12
 *   @0x1a1d90 vpop {d8}
 *   @0x1a1d94 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a1d98 ldr r4, [r12, r3]
 *   @0x1a1d9c ldr r0, [r4]
 *   @0x1a1da0 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a1da4 mov r1, #1073741824
 *   @0x1a1da8 mov r3, r5
 *   @0x1a1dac ldr r0, [r4]
 *   @0x1a1db0 mov r2, r1
 *   @0x1a1db4 str r5, [sp]
 *   @0x1a1db8 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a1dbc ldr r0, [r4]
 *   @0x1a1dc0 mov r1, #1065353216
 *   @0x1a1dc4 mov r2, #1056964608
 *   @0x1a1dc8 bl 0x1a3278 <_Z18ParticleType_Scaleiff>
 *   @0x1a1dcc mov r3, r5
 *   @0x1a1dd0 mov r1, r5
 *   @0x1a1dd4 ldr r0, [r4]
 *   @0x1a1dd8 movw r2, #0x999a
 *   @0x1a1ddc movt r2, #0x3e99
 *   @0x1a1de0 bl 0x1a36f8 <_Z19ParticleType_Alpha3ifff>
 *   @0x1a1de4 vldr s15, [pc, #184]
 *   @0x1a1de8 vdiv.f32 s16, s15, s16
 *   @0x1a1dec ldr r9, [r4]
 *   @0x1a1df0 vcvt.f64.f32 d8, s16
 *   @0x1a1df4 vmov r0, r1, d8
 *   @0x1a1df8 bl 0xb66e8 <lrint@plt>
 *   @0x1a1dfc mov r5, r0
 *   @0x1a1e00 vmov r0, r1, d8
 *   @0x1a1e04 bl 0xb66e8 <lrint@plt>
 *   @0x1a1e08 mov r1, r5
 *   @0x1a1e0c mov r2, r0
 *   @0x1a1e10 mov r0, r9
 *   @0x1a1e14 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a1e18 ldr r3, [r4]
 *   @0x1a1e1c b 0x1a1d6c <_Z12Eff_Effect09iffij+0xd0>
 *   @0x1a1e20 ldr r0, [r4, #0x8]
 *   @0x1a1e24 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a1e28 mov r1, #1090519040
 *   @0x1a1e2c mov r3, r5
 *   @0x1a1e30 ldr r0, [r4, #0x8]
 *   @0x1a1e34 mov r2, r1
 *   @0x1a1e38 str r5, [sp]
 *   @0x1a1e3c bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a1e40 ldr r0, [r4, #0x8]
 *   @0x1a1e44 mov r1, #1065353216
 *   @0x1a1e48 mov r2, #1056964608
 *   @0x1a1e4c bl 0x1a3278 <_Z18ParticleType_Scaleiff>
 *   @0x1a1e50 mov r3, r5
 *   @0x1a1e54 mov r1, r5
 *   @0x1a1e58 ldr r0, [r4, #0x8]
 *   @0x1a1e5c movw r2, #0x999a
 *   @0x1a1e60 movt r2, #0x3e99
 *   @0x1a1e64 bl 0x1a36f8 <_Z19ParticleType_Alpha3ifff>
 *   @0x1a1e68 vldr s15, [pc, #52]
 *   @0x1a1e6c vdiv.f32 s16, s15, s16
 *   @0x1a1e70 ldr r9, [r4, #0x8]
 *   @0x1a1e74 vcvt.f64.f32 d8, s16
 *   @0x1a1e78 vmov r0, r1, d8
 *   @0x1a1e7c bl 0xb66e8 <lrint@plt>
 *   @0x1a1e80 mov r5, r0
 *   @0x1a1e84 vmov r0, r1, d8
 *   @0x1a1e88 bl 0xb66e8 <lrint@plt>
 *   @0x1a1e8c mov r1, r5
 *   @0x1a1e90 mov r2, r0
 *   @0x1a1e94 mov r0, r9
 *   @0x1a1e98 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a1e9c ldr r3, [r4, #0x8]
 *   @0x1a1ea0 b 0x1a1d6c <_Z12Eff_Effect09iffij+0xd0>
 *   @0x1a1ea4 sbcmi r0, r8, #0
 *   @0x1a1ea8 eoreq pc, r4, r0, lsl #31
 *   @0x1a1eac .word 0xffffeb44
 *
 * ══ §40/57 F_JSDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x24c2d8  size 532  133 条（0x24c2d8..0x24c4ec）
 * @func 0x24c2d8 0x24c4ec  size 532  133 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / UNLOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / YYFree(void const*)×2 / operator delete(void*)×2 / F_JSDelete(RValue&, CInstance*, CInstance*, int, RValue*)+0x130 / F_JSDelete(RValue&, CInstance*, CInstance*, int, RValue*)+0x1c8 / F_JSDelete(RValue&, CInstance*, CInstance*, int, RValue*)+0x180
 * 字段偏移 top8: 0x4×14 / 0x8×6 / 0xc×5 / 0x10×3 / 0x30×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24c2d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24c2dc sub sp, sp, #12
 *   @0x24c2e0 mov r10, r0
 *   @0x24c2e4 ldr r5, [sp, #0x30]
 *   @0x24c2e8 ldr r2, [r5, #0xc]
 *   @0x24c2ec sub r3, r2, #1
 *   @0x24c2f0 bic r3, r3, #-16777216
 *   @0x24c2f4 bics r4, r3, #3
 *   @0x24c2f8 beq 0x24c320 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x24c2fc mov r3, #0
 *   @0x24c300 mov r2, #5
 *   @0x24c304 str r3, [r5, #0x8]
 *   @0x24c308 str r3, [r5]
 *   @0x24c30c str r2, [r5, #0xc]
 *   @0x24c310 str r3, [r10]
 *   @0x24c314 str r2, [r10, #0xc]
 *   @0x24c318 add sp, sp, #12
 *   @0x24c31c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24c320 bic r2, r2, #-16777216
 *   @0x24c324 cmp r2, #2
 *   @0x24c328 beq 0x24c398 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x24c32c cmp r2, #3
 *   @0x24c330 beq 0x24c370 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x24c334 cmp r2, #1
 *   @0x24c338 bne 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x24c33c ldr r4, [r5]
 *   @0x24c340 cmp r4, #0
 *   @0x24c344 beq 0x24c364 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x24c348 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c34c ldr r6, [r4, #0x4]
 *   @0x24c350 sub r6, r6, #1
 *   @0x24c354 str r6, [r4, #0x4]
 *   @0x24c358 cmp r6, #0
 *   @0x24c35c beq 0x24c3d0 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x24c360 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c364 mov r3, #0
 *   @0x24c368 str r3, [r5]
 *   @0x24c36c b 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x24c370 ldr r3, [r5, #0x8]
 *   @0x24c374 tst r3, #8
 *   @0x24c378 beq 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x24c37c ldr r0, [r5]
 *   @0x24c380 cmp r0, #0
 *   @0x24c384 beq 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x24c388 ldr r3, [r0]
 *   @0x24c38c ldr r3, [r3, #0x4]
 *   @0x24c390 blx r3
 *   @0x24c394 b 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x24c398 ldr r8, [r5]
 *   @0x24c39c cmp r8, #0
 *   @0x24c3a0 beq 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x24c3a4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c3a8 ldr r3, [r8]
 *   @0x24c3ac ldr r2, [r8, #0x8]
 *   @0x24c3b0 sub r3, r3, #1
 *   @0x24c3b4 str r3, [r8]
 *   @0x24c3b8 cmp r5, r2
 *   @0x24c3bc streq r4, [r8, #0x8]
 *   @0x24c3c0 cmp r3, #0
 *   @0x24c3c4 ble 0x24c408 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x24c3c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c3cc b 0x24c2fc <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x24c3d0 ldr r0, [r4]
 *   @0x24c3d4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24c3d8 str r6, [r4]
 *   @0x24c3dc str r6, [r4, #0x8]
 *   @0x24c3e0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c3e4 ldr r6, [r4, #0x4]
 *   @0x24c3e8 sub r6, r6, #1
 *   @0x24c3ec str r6, [r4, #0x4]
 *   @0x24c3f0 cmp r6, #0
 *   @0x24c3f4 beq 0x24c4c8 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x24c3f8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c3fc mov r0, r4
 *   @0x24c400 bl 0x27d1d0 <_ZdlPv>
 *   @0x24c404 b 0x24c360 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x24c408 ldr r3, [r8, #0x10]
 *   @0x24c40c cmp r3, #0
 *   @0x24c410 movgt r7, #0
 *   @0x24c414 movgt r9, #5
 *   @0x24c418 movgt r6, r7
 *   @0x24c41c ble 0x24c4a0 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x24c420 ldr r3, [r8, #0x4]
 *   @0x24c424 add r2, r3, r7, lsl #3
 *   @0x24c428 str r2, [sp, #0x4]
 *   @0x24c42c ldr r11, [r3, r7, lsl #3]
 *   @0x24c430 ldr r4, [r2, #0x4]
 *   @0x24c434 add r11, r4, r11, lsl #4
 *   @0x24c438 cmp r4, r11
 *   @0x24c43c blo 0x24c458 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x24c440 b 0x24c4c0 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x24c444 str r6, [r4, #0x8]
 *   @0x24c448 str r9, [r4, #0xc]
 *   @0x24c44c str r6, [r4], #16
 *   @0x24c450 cmp r11, r4
 *   @0x24c454 bls 0x24c47c <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x24c458 ldr r3, [r4, #0xc]
 *   @0x24c45c sub r3, r3, #1
 *   @0x24c460 bic r3, r3, #-16777216
 *   @0x24c464 bic r3, r3, #3
 *   @0x24c468 cmp r3, #0
 *   @0x24c46c bne 0x24c444 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x24c470 mov r0, r4
 *   @0x24c474 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24c478 b 0x24c444 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x24c47c ldr r3, [sp, #0x4]
 *   @0x24c480 ldr r0, [r3, #0x4]
 *   @0x24c484 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x24c488 ldr r3, [r8, #0x10]
 *   @0x24c48c add r7, r7, #1
 *   @0x24c490 ldr r2, [sp, #0x4]
 *   @0x24c494 cmp r7, r3
 *   @0x24c498 str r6, [r2, #0x4]
 *   @0x24c49c blt 0x24c420 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x24c4a0 ldr r0, [r8, #0x4]
 *   @0x24c4a4 mov r4, #0
 *   @0x24c4a8 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x24c4ac str r4, [r8, #0x4]
 *   @0x24c4b0 mov r0, r8
 *   @0x24c4b4 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x24c4b8 str r4, [r5]
 *   @0x24c4bc b 0x24c3c8 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x24c4c0 mov r0, r4
 *   @0x24c4c4 b 0x24c484 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x24c4c8 ldr r0, [r4]
 *   @0x24c4cc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24c4d0 mov r0, r4
 *   @0x24c4d4 str r6, [r4]
 *   @0x24c4d8 str r6, [r4, #0x8]
 *   @0x24c4dc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x24c4e0 mov r0, r4
 *   @0x24c4e4 bl 0x27d1d0 <_ZdlPv>
 *   @0x24c4e8 b 0x24c3f8 <_Z10F_JSDeleteR6RValueP9CInstanceS2_iPS_+0x120>
 *
 * ══ §41/57 b2FrictionJoint::SolveVelocityConstraints(b2SolverData const&)  0x2cd528  size 532  133 条（0x2cd528..0x2cd73c）
 * @func 0x2cd528 0x2cd73c  size 532  133 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 0x68×2 / 0x6c×2 / 0x1c×2 / 0x4×2
 * VFP 指令 106 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd528 push {r4, r5, lr}
 *   @0x2cd52c vldr s13, [r0, #92]
 *   @0x2cd530 mov r4, r0
 *   @0x2cd534 vldr s5, [r0, #176]
 *   @0x2cd538 ldr r5, [r0, #0x68]
 *   @0x2cd53c vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2cd540 ldr r12, [r0, #0x6c]
 *   @0x2cd544 vmov.f32 s2, s13
 *   @0x2cd548 ldr r0, [r1, #0x1c]
 *   @0x2cd54c vldr s6, [r1]
 *   @0x2cd550 add r2, r5, r5, lsl #1
 *   @0x2cd554 vldr s11, [r4, #100]
 *   @0x2cd558 add r3, r12, r12, lsl #1
 *   @0x2cd55c vldr s24, [r4, #156]
 *   @0x2cd560 add r2, r0, r2, lsl #2
 *   @0x2cd564 vldr s17, [r2, #8]
 *   @0x2cd568 add r3, r0, r3, lsl #2
 *   @0x2cd56c vldr s16, [r3, #8]
 *   @0x2cd570 vsub.f32 s12, s16, s17
 *   @0x2cd574 vldr s18, [r3, #4]
 *   @0x2cd578 vldr s20, [r3]
 *   @0x2cd57c vldr s22, [r2, #4]
 *   @0x2cd580 vldr s23, [r2]
 *   @0x2cd584 vldr s10, [r4, #120]
 *   @0x2cd588 vldr s25, [r4, #152]
 *   @0x2cd58c vldr s8, [r4, #124]
 *   @0x2cd590 vldr s9, [r4, #112]
 *   @0x2cd594 vldr s7, [r4, #116]
 *   @0x2cd598 vldr s15, [r4, #172]
 *   @0x2cd59c vldr s3, [r4, #164]
 *   @0x2cd5a0 vldr s14, [r4, #168]
 *   @0x2cd5a4 vldr s4, [r4, #160]
 *   @0x2cd5a8 vldr s26, [r4, #88]
 *   @0x2cd5ac vldr s27, [r4, #84]
 *   @0x2cd5b0 vldr s28, [r4, #96]
 *   @0x2cd5b4 sub sp, sp, #12
 *   @0x2cd5b8 vldr s21, [r4, #144]
 *   @0x2cd5bc vldr s19, [r4, #148]
 *   @0x2cd5c0 vmls.f32 s2, s5, s12
 *   @0x2cd5c4 vmul.f32 s11, s6, s11
 *   @0x2cd5c8 vcmpe.f32 s11, s2
 *   @0x2cd5cc vneg.f32 s5, s11
 *   @0x2cd5d0 vmrs APSR_nzcv, fpscr
 *   @0x2cd5d4 vmovgt.f32 s11, s2
 *   @0x2cd5d8 vcmpe.f32 s5, s11
 *   @0x2cd5dc vmrs APSR_nzcv, fpscr
 *   @0x2cd5e0 vmovgt.f32 s11, s5
 *   @0x2cd5e4 vstr s11, [r4, #92]
 *   @0x2cd5e8 vsub.f32 s11, s11, s13
 *   @0x2cd5ec vmla.f32 s16, s24, s11
 *   @0x2cd5f0 vmov.f32 s12, s18
 *   @0x2cd5f4 vmla.f32 s12, s16, s10
 *   @0x2cd5f8 vmov.f32 s13, s20
 *   @0x2cd5fc vmls.f32 s17, s25, s11
 *   @0x2cd600 vmls.f32 s13, s16, s8
 *   @0x2cd604 vsub.f32 s12, s12, s22
 *   @0x2cd608 vmls.f32 s12, s17, s9
 *   @0x2cd60c vsub.f32 s13, s13, s23
 *   @0x2cd610 vmla.f32 s13, s17, s7
 *   @0x2cd614 vmul.f32 s15, s12, s15
 *   @0x2cd618 vmul.f32 s14, s12, s14
 *   @0x2cd61c vmla.f32 s15, s13, s3
 *   @0x2cd620 vmla.f32 s14, s13, s4
 *   @0x2cd624 vsub.f32 s15, s26, s15
 *   @0x2cd628 vmul.f32 s13, s15, s15
 *   @0x2cd62c vstr s15, [r4, #88]
 *   @0x2cd630 vsub.f32 s14, s27, s14
 *   @0x2cd634 vmul.f32 s28, s6, s28
 *   @0x2cd638 vstr s14, [r4, #84]
 *   @0x2cd63c vmla.f32 s13, s14, s14
 *   @0x2cd640 vmul.f32 s12, s28, s28
 *   @0x2cd644 vcmpe.f32 s12, s13
 *   @0x2cd648 vmrs APSR_nzcv, fpscr
 *   @0x2cd64c bmi 0x2cd6a4 <_ZN15b2FrictionJoint24SolveVelocityConstraintsERK12b2SolverData+0x17c>
 *   @0x2cd650 vsub.f32 s14, s14, s27
 *   @0x2cd654 vmul.f32 s12, s14, s7
 *   @0x2cd658 vmul.f32 s13, s14, s8
 *   @0x2cd65c vsub.f32 s15, s15, s26
 *   @0x2cd660 vnmls.f32 s12, s15, s9
 *   @0x2cd664 vnmls.f32 s13, s15, s10
 *   @0x2cd668 vmls.f32 s17, s25, s12
 *   @0x2cd66c vmla.f32 s16, s24, s13
 *   @0x2cd670 vstr s17, [r2, #8]
 *   @0x2cd674 vmls.f32 s23, s21, s14
 *   @0x2cd678 vmls.f32 s22, s21, s15
 *   @0x2cd67c vstr s23, [r2]
 *   @0x2cd680 vmla.f32 s20, s19, s14
 *   @0x2cd684 vstr s22, [r2, #4]
 *   @0x2cd688 vstr s16, [r3, #8]
 *   @0x2cd68c vmla.f32 s18, s19, s15
 *   @0x2cd690 vstr s20, [r3]
 *   @0x2cd694 vstr s18, [r3, #4]
 *   @0x2cd698 add sp, sp, #12
 *   @0x2cd69c vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2cd6a0 pop {r4, r5, pc}
 *   @0x2cd6a4 vsqrt.f32 s12, s13
 *   @0x2cd6a8 vcmp.f32 s12, s12
 *   @0x2cd6ac vmrs APSR_nzcv, fpscr
 *   @0x2cd6b0 bne 0x2cd704 <_ZN15b2FrictionJoint24SolveVelocityConstraintsERK12b2SolverData+0x1dc>
 *   @0x2cd6b4 vldr s15, [pc, #124]
 *   @0x2cd6b8 vcmpe.f32 s12, s15
 *   @0x2cd6bc add r5, r5, r5, lsl #1
 *   @0x2cd6c0 add r12, r12, r12, lsl #1
 *   @0x2cd6c4 add r2, r0, r5, lsl #2
 *   @0x2cd6c8 add r3, r0, r12, lsl #2
 *   @0x2cd6cc vmrs APSR_nzcv, fpscr
 *   @0x2cd6d0 vmovpl.f32 s13, #1.000000e+00
 *   @0x2cd6d4 vldrpl s15, [r4, #88]
 *   @0x2cd6d8 vldrpl s14, [r4, #84]
 *   @0x2cd6dc vldrmi s14, [r4, #84]
 *   @0x2cd6e0 vldrmi s15, [r4, #88]
 *   @0x2cd6e4 vdivpl.f32 s12, s13, s12
 *   @0x2cd6e8 vmulpl.f32 s15, s12, s15
 *   @0x2cd6ec vmulpl.f32 s14, s12, s14
 *   @0x2cd6f0 vmul.f32 s15, s28, s15
 *   @0x2cd6f4 vmul.f32 s14, s28, s14
 *   @0x2cd6f8 vstr s15, [r4, #88]
 *   @0x2cd6fc vstr s14, [r4, #84]
 *   @0x2cd700 b 0x2cd650 <_ZN15b2FrictionJoint24SolveVelocityConstraintsERK12b2SolverData+0x128>
 *   @0x2cd704 vmov r0, s13
 *   @0x2cd708 str r1, [sp, #0x4]
 *   @0x2cd70c bl 0xb6700 <sqrtf@plt>
 *   @0x2cd710 ldr r1, [sp, #0x4]
 *   @0x2cd714 vldr s8, [r4, #124]
 *   @0x2cd718 ldr r5, [r4, #0x68]
 *   @0x2cd71c vldr s10, [r4, #120]
 *   @0x2cd720 ldr r12, [r4, #0x6c]
 *   @0x2cd724 vldr s7, [r4, #116]
 *   @0x2cd728 vldr s9, [r4, #112]
 *   @0x2cd72c vmov s12, r0
 *   @0x2cd730 ldr r0, [r1, #0x1c]
 *   @0x2cd734 b 0x2cd6b4 <_ZN15b2FrictionJoint24SolveVelocityConstraintsERK12b2SolverData+0x18c>
 *   @0x2cd738 strlo r0, [r0], #-0
 *
 * ══ §42/57 F_SpriteFlushMulti(RValue&, CInstance*, CInstance*, int, RValue*)  0x1305e0  size 528  132 条（0x1305e0..0x1307f0）
 * @func 0x1305e0 0x1307f0  size 528  132 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_SpriteFlushMulti(RValue&, CInstance*, CInstance*, int, RValue*)+0x1b8×2 / Graphics::FlushTexture(void*)×2 / Graphics::Flush() / YYGetInt32(RValue const*, int) / Sprite_Data(int) / F_SpriteFlushMulti(RValue&, CInstance*, CInstance*, int, RValue*)+0xe8 / CSprite::GetTexture(int)
 * 字段偏移 top8: 0x4×10 / 0xc×6 / 0x18c×2 / 0x2×2 / 0x30×1 / 0x1d0×1 / 0x10×1 / 0x16c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1305e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1305e4 sub sp, sp, #12
 *   @0x1305e8 mov r6, #0
 *   @0x1305ec str r6, [r0, #0xc]
 *   @0x1305f0 ldr r2, [sp, #0x30]
 *   @0x1305f4 mov r3, r6
 *   @0x1305f8 ldr r7, [pc, #0x1d0]
 *   @0x1305fc movt r3, #0xbff0
 *   @0x130600 mov r8, r0
 *   @0x130604 str r6, [r0]
 *   @0x130608 ldr r1, [r2, #0xc]
 *   @0x13060c add r7, pc, r7
 *   @0x130610 str r3, [r0, #0x4]
 *   @0x130614 cmp r1, #2
 *   @0x130618 bne 0x130668 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x13061c ldr r9, [r2]
 *   @0x130620 cmp r9, #0
 *   @0x130624 beq 0x130640 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x130628 ldr r3, [r9, #0x4]
 *   @0x13062c cmp r3, #0
 *   @0x130630 beq 0x130640 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x130634 ldr r3, [r9, #0x10]
 *   @0x130638 cmp r3, #1
 *   @0x13063c beq 0x130678 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x130640 ldr r1, [pc, #0x18c]
 *   @0x130644 ldr r3, [pc, #0x18c]
 *   @0x130648 add r1, pc, r1
 *   @0x13064c ldr r3, [r7, r3]
 *   @0x130650 ldr r0, [r3]
 *   @0x130654 ldr r3, [r0]
 *   @0x130658 ldr r3, [r3, #0xc]
 *   @0x13065c blx r3
 *   @0x130660 add sp, sp, #12
 *   @0x130664 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x130668 ldr r1, [pc, #0x16c]
 *   @0x13066c ldr r3, [pc, #0x164]
 *   @0x130670 add r1, pc, r1
 *   @0x130674 b 0x13064c <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x130678 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x13067c ldr r3, [r9, #0x4]
 *   @0x130680 ldr r2, [r3]
 *   @0x130684 cmp r2, #0
 *   @0x130688 ble 0x130798 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x13068c ldr r2, [pc, #0x14c]
 *   @0x130690 add r2, pc, r2
 *   @0x130694 str r2, [sp, #0x4]
 *   @0x130698 ldr r2, [pc, #0x144]
 *   @0x13069c add r2, pc, r2
 *   @0x1306a0 str r2, [sp]
 *   @0x1306a4 b 0x1306dc <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x1306a8 ldr r3, [pc, #0x128]
 *   @0x1306ac mov r2, r6
 *   @0x1306b0 ldr r1, [sp]
 *   @0x1306b4 ldr r3, [r7, r3]
 *   @0x1306b8 ldr r0, [r3]
 *   @0x1306bc ldr r3, [r0]
 *   @0x1306c0 ldr r3, [r3, #0xc]
 *   @0x1306c4 blx r3
 *   @0x1306c8 ldr r3, [r9, #0x4]
 *   @0x1306cc add r6, r6, #1
 *   @0x1306d0 ldr r2, [r3]
 *   @0x1306d4 cmp r2, r6
 *   @0x1306d8 ble 0x130798 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x1306dc ldr r0, [r3, #0x4]
 *   @0x1306e0 add r0, r0, r6, lsl #4
 *   @0x1306e4 ldr r1, [r0, #0xc]
 *   @0x1306e8 cmp r1, #0
 *   @0x1306ec bne 0x1306a8 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x1306f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1306f4 mov r5, r0
 *   @0x1306f8 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1306fc subs r4, r0, #0
 *   @0x130700 beq 0x130788 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x130704 ldr r3, [r4, #0x74]
 *   @0x130708 cmp r3, #0
 *   @0x13070c bne 0x1307a8 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x130710 ldr r5, [r4, #0x18]
 *   @0x130714 cmp r5, #0
 *   @0x130718 ble 0x1306c8 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x13071c ldr r2, [pc, #0xc4]
 *   @0x130720 mov r10, r3
 *   @0x130724 ldr r11, [r7, r2]
 *   @0x130728 b 0x130754 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x13072c cmn r0, #1
 *   @0x130730 beq 0x13076c <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x130734 ldrsh r0, [r0, #20]
 *   @0x130738 ldr r1, [r11, #0x4]
 *   @0x13073c ldr r1, [r1, r0, lsl #2]
 *   @0x130740 ldr r0, [r1]
 *   @0x130744 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv>
 *   @0x130748 add r10, r10, #1
 *   @0x13074c cmp r10, r5
 *   @0x130750 beq 0x1306c8 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x130754 mov r1, r10
 *   @0x130758 mov r0, r4
 *   @0x13075c bl 0x1e57f4 <_ZN7CSprite10GetTextureEi>
 *   @0x130760 ldr r1, [r11]
 *   @0x130764 cmp r0, r1
 *   @0x130768 bhi 0x13072c <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x13076c ldr r1, [r11, #0x4]
 *   @0x130770 ldr r1, [r1, r0, lsl #2]
 *   @0x130774 cmp r1, #0
 *   @0x130778 beq 0x130748 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x13077c ldr r0, [r1]
 *   @0x130780 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv>
 *   @0x130784 b 0x130748 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x130788 ldr r3, [pc, #0x48]
 *   @0x13078c mov r2, r5
 *   @0x130790 ldr r1, [sp, #0x4]
 *   @0x130794 b 0x1306b4 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x130798 mov r3, #0
 *   @0x13079c str r3, [r8]
 *   @0x1307a0 str r3, [r8, #0x4]
 *   @0x1307a4 b 0x130660 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1307a8 ldr r3, [pc, #0x28]
 *   @0x1307ac mov r2, r5
 *   @0x1307b0 ldr r1, [pc, #0x34]
 *   @0x1307b4 ldr r3, [r7, r3]
 *   @0x1307b8 add r1, pc, r1
 *   @0x1307bc ldr r0, [r3]
 *   @0x1307c0 ldr r3, [r0]
 *   @0x1307c4 ldr r3, [r3, #0xc]
 *   @0x1307c8 blx r3
 *   @0x1307cc b 0x130660 <_Z18F_SpriteFlushMultiR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1307d0 eoreq r1, r12, r4, asr #12
 *   @0x1307d4 eoreq sp, r0, r4, lsr r11
 *   @0x1307d8 .word 0xffffbac4
 *   @0x1307dc eoreq sp, r0, r8, asr #21
 *   @0x1307e0 eoreq sp, r0, r0, asr r11
 *   @0x1307e4 eoreq sp, r0, r0, lsl r11
 *   @0x1307e8 .word 0xffffbccc
 *   @0x1307ec eoreq sp, r0, r4, asr r10
 *
 * ══ §43/57 GraphicsPerf::DisplayVersionInfo()  0x17c5d8  size 528  132 条（0x17c5d8..0x17c7e8）
 * @func 0x17c5d8 0x17c7e8  size 528  132 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Get_Region_Width()×2 / GraphicsPerf::cprintf(float, float, unsigned int, char const*, ...)×2 / GraphicsPerf::printf(float, float, unsigned int, char const*, ...)×2 / GraphicsPerf::RenderRectangle(float, float, float, float, unsigned int)
 * 字段偏移 top8: 0x4×3 / 0x190×2 / 0x8×2 / 0x1bc×1 / 0xc×1 / 0x10×1 / 0x148×1 / 0x140×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17c5d8 push {r4, lr}
 *   @0x17c5dc vpush {d8}
 *   @0x17c5e0 sub sp, sp, #24
 *   @0x17c5e4 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv>
 *   @0x17c5e8 ldr r4, [pc, #0x1bc]
 *   @0x17c5ec mov r2, #-1073741824
 *   @0x17c5f0 mov r3, #0
 *   @0x17c5f4 str r2, [sp]
 *   @0x17c5f8 movt r3, #0x42c8
 *   @0x17c5fc add r4, pc, r4
 *   @0x17c600 vmov s15, r0
 *   @0x17c604 mov r0, #0
 *   @0x17c608 mov r1, r0
 *   @0x17c60c vcvt.f32.s32 s16, s15
 *   @0x17c610 vmov r2, s16
 *   @0x17c614 bl 0x17b83c <_ZN12GraphicsPerf15RenderRectangleEffffj>
 *   @0x17c618 ldr r3, [pc, #0x190]
 *   @0x17c61c ldr r2, [pc, #0x190]
 *   @0x17c620 mov lr, #1
 *   @0x17c624 mov r12, #0
 *   @0x17c628 movw r0, #0x70c
 *   @0x17c62c ldr r3, [r4, r3]
 *   @0x17c630 add r2, pc, r2
 *   @0x17c634 str lr, [sp]
 *   @0x17c638 str r2, [sp, #0xc]
 *   @0x17c63c mvn r2, #0
 *   @0x17c640 ldr r3, [r3]
 *   @0x17c644 vmov r1, s16
 *   @0x17c648 cmp r3, r12
 *   @0x17c64c str r0, [sp, #0x8]
 *   @0x17c650 str r12, [sp, #0x4]
 *   @0x17c654 mov r0, #0
 *   @0x17c658 movne r3, #42
 *   @0x17c65c moveq r3, #32
 *   @0x17c660 str r3, [sp, #0x10]
 *   @0x17c664 movt r0, #0x4220
 *   @0x17c668 ldr r3, [pc, #0x148]
 *   @0x17c66c add r3, pc, r3
 *   @0x17c670 bl 0x17c508 <_ZN12GraphicsPerf7cprintfEffjPKcz>
 *   @0x17c674 ldr r3, [pc, #0x140]
 *   @0x17c678 ldr r3, [r4, r3]
 *   @0x17c67c ldr r3, [r3]
 *   @0x17c680 cmp r3, #0
 *   @0x17c684 beq 0x17c6d8 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x100>
 *   @0x17c688 ldr r3, [r3, #0x4]
 *   @0x17c68c cmp r3, #0
 *   @0x17c690 moveq r1, r3
 *   @0x17c694 bne 0x17c774 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x19c>
 *   @0x17c698 ldr r3, [pc, #0x120]
 *   @0x17c69c mov r0, #0
 *   @0x17c6a0 str r1, [sp]
 *   @0x17c6a4 mvn r2, #0
 *   @0x17c6a8 ldr r12, [pc, #0x114]
 *   @0x17c6ac movt r0, #0x4258
 *   @0x17c6b0 ldr r3, [r4, r3]
 *   @0x17c6b4 vmov r1, s16
 *   @0x17c6b8 ldr lr, [r3]
 *   @0x17c6bc ldr r3, [pc, #0x104]
 *   @0x17c6c0 str lr, [sp, #0x4]
 *   @0x17c6c4 add r3, pc, r3
 *   @0x17c6c8 ldr r12, [r4, r12]
 *   @0x17c6cc ldr r12, [r12]
 *   @0x17c6d0 str r12, [sp, #0x8]
 *   @0x17c6d4 bl 0x17c508 <_ZN12GraphicsPerf7cprintfEffjPKcz>
 *   @0x17c6d8 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv>
 *   @0x17c6dc ldr r3, [pc, #0xe8]
 *   @0x17c6e0 mov r1, #0
 *   @0x17c6e4 mvn r2, #0
 *   @0x17c6e8 add r3, pc, r3
 *   @0x17c6ec movt r1, #0x42a0
 *   @0x17c6f0 sub r0, r0, #80
 *   @0x17c6f4 vmov s15, r0
 *   @0x17c6f8 vcvt.f32.s32 s15, s15
 *   @0x17c6fc vmov r0, s15
 *   @0x17c700 bl 0x17c258 <_ZN12GraphicsPerf6printfEffjPKcz>
 *   @0x17c704 ldr r3, [pc, #0xc4]
 *   @0x17c708 ldr r4, [r4, r3]
 *   @0x17c70c ldr r3, [r4]
 *   @0x17c710 tst r3, #8
 *   @0x17c714 beq 0x17c794 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x1bc>
 *   @0x17c718 tst r3, #2
 *   @0x17c71c bne 0x17c788 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x1b0>
 *   @0x17c720 ldr r3, [pc, #0xac]
 *   @0x17c724 add r3, pc, r3
 *   @0x17c728 mov r0, #0
 *   @0x17c72c movt r0, #0x4120
 *   @0x17c730 mvn r2, #0
 *   @0x17c734 mov r1, r0
 *   @0x17c738 bl 0x17c258 <_ZN12GraphicsPerf6printfEffjPKcz>
 *   @0x17c73c ldr r3, [r4]
 *   @0x17c740 tst r3, #16
 *   @0x17c744 beq 0x17c7a0 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x1c8>
 *   @0x17c748 ldr r3, [pc, #0x88]
 *   @0x17c74c add r3, pc, r3
 *   @0x17c750 mov r0, #0
 *   @0x17c754 mov r1, #0
 *   @0x17c758 movt r0, #0x4120
 *   @0x17c75c movt r1, #0x41f0
 *   @0x17c760 mvn r2, #0
 *   @0x17c764 add sp, sp, #24
 *   @0x17c768 vpop {d8}
 *   @0x17c76c pop {r4, lr}
 *   @0x17c770 b 0x17c258 <_ZN12GraphicsPerf6printfEffjPKcz>
 *   @0x17c774 ldr r2, [pc, #0x60]
 *   @0x17c778 ldr r2, [r4, r2]
 *   @0x17c77c ldr r1, [r2]
 *   @0x17c780 add r1, r1, r3
 *   @0x17c784 b 0x17c698 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0xc0>
 *   @0x17c788 ldr r3, [pc, #0x50]
 *   @0x17c78c add r3, pc, r3
 *   @0x17c790 b 0x17c728 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x150>
 *   @0x17c794 add sp, sp, #24
 *   @0x17c798 vpop {d8}
 *   @0x17c79c pop {r4, pc}
 *   @0x17c7a0 ldr r3, [pc, #0x3c]
 *   @0x17c7a4 add r3, pc, r3
 *   @0x17c7a8 b 0x17c750 <_ZN12GraphicsPerf18DisplayVersionInfoEv+0x178>
 *   @0x17c7ac eoreq r5, r7, r4, asr r6
 *   @0x17c7b0 .word 0xffffe798
 *   @0x17c7b4 andseq pc, r12, r4, lsr r0
 *   @0x17c7b8 ldrsbeq lr, [r12], -r4
 *   @0x17c7bc .word 0xffffe79c
 *   @0x17c7c0 .word 0xffffe7a0
 *   @0x17c7c4 .word 0xffffe7a4
 *   @0x17c7c8 andseq lr, r12, r8, lsr #31
 *   @0x17c7cc mulseq r12, r8, pc
 *   @0x17c7d0 .word 0xffffc7dc
 *   @0x17c7d4 ldrsheq lr, [r12], -r8
 *   @0x17c7d8 ldrsbeq lr, [r12], -r12
 *   @0x17c7dc .word 0xffffbcf4
 *   @0x17c7e0 andseq lr, r12, r4, lsl #29
 *   @0x17c7e4 mulseq r12, r0, lr
 *
 * ══ §44/57 anon_216048  0x216048  size 528  132 条（0x216048..0x216258）
 * @func 0x216048 0x216258  size 528  132 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x216110→0x75531c, 0x2161bc→0x75531c, 0x2161d4→0x3eb70c
 * 调用序列: 0xb6a6c×2 / 0xb6a84×2 / COggAudio::Play_Sound(int, cAudio_Sound*, bool, float, int, int) / anon_216048+0x94 / 0xb6a54 / anon_216048+0x13c / 0xb6a78 / checkAL(char const*)
 * 字段偏移 top8: 0x2×5 / 0x30×3 / 0x4×2 / 0x414×2 / 0x24×2 / 0xc×2 / 0x78×2 / 0x1e8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216048 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x21604c mov r5, r1
 *   @0x216050 ldr r6, [pc, #0x1e8]
 *   @0x216054 sub sp, sp, #1040
 *   @0x216058 ldr r3, [pc, #0x1e4]
 *   @0x21605c sub sp, sp, #8
 *   @0x216060 add r6, pc, r6
 *   @0x216064 ldrb r2, [r0, #0x5c]
 *   @0x216068 ldr r8, [r1, #0x10]
 *   @0x21606c mov r4, r0
 *   @0x216070 ldr r7, [r6, r3]
 *   @0x216074 cmp r2, #0
 *   @0x216078 ldrb r9, [r1, #0x4]
 *   @0x21607c ldr r1, [r7]
 *   @0x216080 str r1, [sp, #0x414]
 *   @0x216084 bne 0x2161bc <_Z7checkALPKc+0x1ec>
 *   @0x216088 ldrb r3, [r0, #0x24]
 *   @0x21608c cmp r3, #0
 *   @0x216090 beq 0x2160f8 <_Z7checkALPKc+0x128>
 *   @0x216094 ldr r3, [r0, #0x30]
 *   @0x216098 cmp r3, #0
 *   @0x21609c beq 0x2161f8 <_Z7checkALPKc+0x228>
 *   @0x2160a0 ldr r2, [r5, #0x34]
 *   @0x2160a4 mvn r0, #0
 *   @0x2160a8 ldr r12, [r4, #0x48]
 *   @0x2160ac mov r1, r8
 *   @0x2160b0 str r0, [sp, #0x8]
 *   @0x2160b4 mov r3, r9
 *   @0x2160b8 ldr r0, [pc, #0x188]
 *   @0x2160bc str r2, [sp, #0x4]
 *   @0x2160c0 mov r2, r4
 *   @0x2160c4 str r12, [sp]
 *   @0x2160c8 add r0, pc, r0
 *   @0x2160cc bl 0x22630c <_ZN9COggAudio10Play_SoundEiP12cAudio_Soundbfii>
 *   @0x2160d0 cmn r0, #1
 *   @0x2160d4 bne 0x216190 <_Z7checkALPKc+0x1c0>
 *   @0x2160d8 mov r0, #0
 *   @0x2160dc ldr r2, [sp, #0x414]
 *   @0x2160e0 ldr r3, [r7]
 *   @0x2160e4 cmp r2, r3
 *   @0x2160e8 bne 0x21623c <_Z7checkALPKc+0x26c>
 *   @0x2160ec add sp, sp, #1040
 *   @0x2160f0 add sp, sp, #8
 *   @0x2160f4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2160f8 ldrb r0, [r0, #0x25]
 *   @0x2160fc cmp r0, #0
 *   @0x216100 bne 0x2160a0 <_Z7checkALPKc+0xd0>
 *   @0x216104 ldr r2, [r4, #0x18]
 *   @0x216108 cmp r2, #0
 *   @0x21610c ble 0x2160dc <_Z7checkALPKc+0x10c>
 *   @0x216110 ldr r3, [pc, #0x134]
 *   @0x216114 movw r1, #0x1009
 *   @0x216118 ldr r10, [r6, r3]
 *   @0x21611c ldr r3, [r10]
 *   @0x216120 ldr r0, [r3, r8, lsl #2]
 *   @0x216124 bl 0xb6a6c <alSourcei@plt>
 *   @0x216128 bl 0xb6a54 <alGetError@plt>
 *   @0x21612c subs r2, r0, #0
 *   @0x216130 bne 0x2161d4 <_Z7checkALPKc+0x204>
 *   @0x216134 ldr r3, [r10]
 *   @0x216138 cmp r9, #0
 *   @0x21613c movwne r1, #0x1007
 *   @0x216140 movne r2, #1
 *   @0x216144 moveq r2, r9
 *   @0x216148 movweq r1, #0x1007
 *   @0x21614c ldr r0, [r3, r8, lsl #2]
 *   @0x216150 bl 0xb6a6c <alSourcei@plt>
 *   @0x216154 vldr s15, [r4, #72]
 *   @0x216158 vcmpe.f32 s15, #0
 *   @0x21615c vmrs APSR_nzcv, fpscr
 *   @0x216160 ble 0x216184 <_Z7checkALPKc+0x1b4>
 *   @0x216164 ldr r3, [r10]
 *   @0x216168 movw r1, #0x1024
 *   @0x21616c vmov r2, s15
 *   @0x216170 ldr r0, [r3, r8, lsl #2]
 *   @0x216174 bl 0xb6a78 <alSourcef@plt>
 *   @0x216178 ldr r0, [pc, #0xd0]
 *   @0x21617c add r0, pc, r0
 *   @0x216180 bl 0x215fd0 <_Z7checkALPKc>
 *   @0x216184 ldr r3, [r10]
 *   @0x216188 ldr r0, [r3, r8, lsl #2]
 *   @0x21618c bl 0xb6a84 <alSourcePlay@plt>
 *   @0x216190 ldrb r3, [r4, #0x24]
 *   @0x216194 mov r2, #0
 *   @0x216198 strb r2, [r5, #0xd]
 *   @0x21619c cmp r3, r2
 *   @0x2161a0 mov r3, #1
 *   @0x2161a4 mov r0, r3
 *   @0x2161a8 ldrbeq r2, [r4, #0x25]
 *   @0x2161ac movne r2, #1
 *   @0x2161b0 strb r3, [r5, #0x5]
 *   @0x2161b4 strb r2, [r5, #0xc]
 *   @0x2161b8 b 0x2160dc <_Z7checkALPKc+0x10c>
 *   @0x2161bc ldr r3, [pc, #0x88]
 *   @0x2161c0 ldr r3, [r6, r3]
 *   @0x2161c4 ldr r3, [r3]
 *   @0x2161c8 ldr r0, [r3, r8, lsl #2]
 *   @0x2161cc bl 0xb6a84 <alSourcePlay@plt>
 *   @0x2161d0 b 0x216190 <_Z7checkALPKc+0x1c0>
 *   @0x2161d4 ldr r3, [pc, #0x78]
 *   @0x2161d8 ldr r1, [pc, #0x78]
 *   @0x2161dc ldr r3, [r6, r3]
 *   @0x2161e0 add r1, pc, r1
 *   @0x2161e4 ldr r0, [r3]
 *   @0x2161e8 ldr r3, [r0]
 *   @0x2161ec ldr r3, [r3, #0xc]
 *   @0x2161f0 blx r3
 *   @0x2161f4 b 0x216134 <_Z7checkALPKc+0x164>
 *   @0x2161f8 add r6, sp, #20
 *   @0x2161fc ldr r2, [r0]
 *   @0x216200 mov r1, #1024
 *   @0x216204 mov r0, r6
 *   @0x216208 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x21620c mov r0, r6
 *   @0x216210 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x216214 cmp r0, #0
 *   @0x216218 beq 0x2160a0 <_Z7checkALPKc+0xd0>
 *   @0x21621c ldr r0, [r4, #0x30]
 *   @0x216220 cmp r0, #0
 *   @0x216224 beq 0x21622c <_Z7checkALPKc+0x25c>
 *   @0x216228 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x21622c mov r0, r6
 *   @0x216230 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x216234 str r0, [r4, #0x30]
 *   @0x216238 b 0x2160a0 <_Z7checkALPKc+0xd0>
 *   @0x21623c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x216240 ldrsheq r11, [sp], -r0
 *   @0x216244 .word 0xffffbd00
 *   @0x216248 subseq pc, r3, r12, asr #3
 *   @0x21624c .word 0xfffff77c
 *   @0x216250 andseq sp, r3, r4, ror #19
 *   @0x216254 .word 0xffffbac4
 *
 * ══ §45/57 Audio_SetNumChannels(int)  0x21a454  size 528  132 条（0x21a454..0x21a664）
 * @func 0x21a454 0x21a664  size 528  132 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21a460→0x755314, 0x21a478→0x3f52c8, 0x21a49c→0x3eb70c, 0x21a4d4→0x75531c
 * 调用序列: operator delete(void*)×2 / MemoryManager::Free(void const*)×2 / Audio_StopAll(bool) / COggAudio::Quit() / Audio_SetNumChannels(int)+0xc8 / 0xb6a6c / 0xb6b20 / Audio_SetNumChannels(int)+0x190
 * 字段偏移 top8: 0x3c×5 / 0x38×3 / 0x1d0×2 / 0x2×2 / 0x4×2 / 0x1bc×1 / 0x19c×1 / 0x198×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21a454 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21a458 sub sp, sp, #12
 *   @0x21a45c ldr r4, [pc, #0x1d0]
 *   @0x21a460 ldr r3, [pc, #0x1d0]
 *   @0x21a464 add r4, pc, r4
 *   @0x21a468 ldr r3, [r4, r3]
 *   @0x21a46c ldrb r3, [r3]
 *   @0x21a470 cmp r3, #0
 *   @0x21a474 beq 0x21a61c <_Z20Audio_SetNumChannelsi+0x1c8>
 *   @0x21a478 ldr r3, [pc, #0x1bc]
 *   @0x21a47c cmp r0, #1
 *   @0x21a480 andgt r7, r0, #3
 *   @0x21a484 addgt r7, r0, r7
 *   @0x21a488 movle r7, #4
 *   @0x21a48c ldr r5, [r4, r3]
 *   @0x21a490 ldr r3, [r5]
 *   @0x21a494 cmp r7, r3
 *   @0x21a498 beq 0x21a61c <_Z20Audio_SetNumChannelsi+0x1c8>
 *   @0x21a49c ldr r3, [pc, #0x19c]
 *   @0x21a4a0 mov r2, r7
 *   @0x21a4a4 ldr r1, [pc, #0x198]
 *   @0x21a4a8 ldr r3, [r4, r3]
 *   @0x21a4ac add r1, pc, r1
 *   @0x21a4b0 ldr r0, [r3]
 *   @0x21a4b4 ldr r3, [r0]
 *   @0x21a4b8 ldr r3, [r3, #0xc]
 *   @0x21a4bc blx r3
 *   @0x21a4c0 mov r0, #1
 *   @0x21a4c4 bl 0x21a3bc <_Z13Audio_StopAllb>
 *   @0x21a4c8 ldr r0, [pc, #0x178]
 *   @0x21a4cc add r0, pc, r0
 *   @0x21a4d0 bl 0x225fa4 <_ZN9COggAudio4QuitEv>
 *   @0x21a4d4 ldr r3, [pc, #0x170]
 *   @0x21a4d8 ldr r6, [r4, r3]
 *   @0x21a4dc ldr r1, [r6]
 *   @0x21a4e0 cmp r1, #0
 *   @0x21a4e4 beq 0x21a530 <_Z20Audio_SetNumChannelsi+0xdc>
 *   @0x21a4e8 ldr r0, [r5]
 *   @0x21a4ec cmp r0, #0
 *   @0x21a4f0 ble 0x21a51c <_Z20Audio_SetNumChannelsi+0xc8>
 *   @0x21a4f4 mov r4, #0
 *   @0x21a4f8 ldr r0, [r1, r4, lsl #2]
 *   @0x21a4fc mov r2, #0
 *   @0x21a500 movw r1, #0x1009
 *   @0x21a504 add r4, r4, #1
 *   @0x21a508 bl 0xb6a6c <alSourcei@plt>
 *   @0x21a50c ldr r0, [r5]
 *   @0x21a510 ldr r1, [r6]
 *   @0x21a514 cmp r0, r4
 *   @0x21a518 bgt 0x21a4f8 <_Z20Audio_SetNumChannelsi+0xa4>
 *   @0x21a51c bl 0xb6b20 <alDeleteSources@plt>
 *   @0x21a520 ldr r0, [r6]
 *   @0x21a524 bl 0x27d1d0 <_ZdlPv>
 *   @0x21a528 mov r3, #0
 *   @0x21a52c str r3, [r6]
 *   @0x21a530 ldr r9, [pc, #0x118]
 *   @0x21a534 add r9, pc, r9
 *   @0x21a538 ldr r3, [r9, #0x38]
 *   @0x21a53c cmp r3, #0
 *   @0x21a540 beq 0x21a60c <_Z20Audio_SetNumChannelsi+0x1b8>
 *   @0x21a544 ldr r5, [r9, #0x3c]
 *   @0x21a548 cmp r5, #0
 *   @0x21a54c beq 0x21a624 <_Z20Audio_SetNumChannelsi+0x1d0>
 *   @0x21a550 cmp r3, #0
 *   @0x21a554 ble 0x21a5e4 <_Z20Audio_SetNumChannelsi+0x190>
 *   @0x21a558 ldr r11, [pc, #0xf4]
 *   @0x21a55c mov r4, #0
 *   @0x21a560 ldr r2, [pc, #0xf0]
 *   @0x21a564 mov r10, r4
 *   @0x21a568 add r11, pc, r11
 *   @0x21a56c add r2, pc, r2
 *   @0x21a570 ldr r0, [r5]
 *   @0x21a574 movw r3, #0xfeee
 *   @0x21a578 movt r3, #0xfeee
 *   @0x21a57c movw r1, #0xfeee
 *   @0x21a580 cmp r0, r3
 *   @0x21a584 movt r1, #0xfeee
 *   @0x21a588 lsl r8, r4, #2
 *   @0x21a58c beq 0x21a5d4 <_Z20Audio_SetNumChannelsi+0x180>
 *   @0x21a590 ldr r6, [r5, r4, lsl #2]
 *   @0x21a594 add r3, r5, r8
 *   @0x21a598 cmp r6, #0
 *   @0x21a59c mov r0, r6
 *   @0x21a5a0 beq 0x21a5d4 <_Z20Audio_SetNumChannelsi+0x180>
 *   @0x21a5a4 ldr r12, [r6]
 *   @0x21a5a8 cmp r12, r1
 *   @0x21a5ac beq 0x21a5cc <_Z20Audio_SetNumChannelsi+0x178>
 *   @0x21a5b0 str r2, [sp, #0x4]
 *   @0x21a5b4 bl 0x21db28 <_ZN6CNoiseD2Ev>
 *   @0x21a5b8 mov r0, r6
 *   @0x21a5bc bl 0x27d1d0 <_ZdlPv>
 *   @0x21a5c0 ldr r2, [sp, #0x4]
 *   @0x21a5c4 ldr r3, [r2, #0x3c]
 *   @0x21a5c8 add r3, r3, r8
 *   @0x21a5cc str r10, [r3]
 *   @0x21a5d0 ldr r5, [r11, #0x3c]
 *   @0x21a5d4 ldr r3, [r9, #0x38]
 *   @0x21a5d8 add r4, r4, #1
 *   @0x21a5dc cmp r4, r3
 *   @0x21a5e0 blt 0x21a570 <_Z20Audio_SetNumChannelsi+0x11c>
 *   @0x21a5e4 mov r0, r5
 *   @0x21a5e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21a5ec ldr r3, [pc, #0x68]
 *   @0x21a5f0 mov r2, #0
 *   @0x21a5f4 add r3, pc, r3
 *   @0x21a5f8 str r2, [r3, #0x3c]
 *   @0x21a5fc ldr r3, [pc, #0x5c]
 *   @0x21a600 mov r2, #0
 *   @0x21a604 add r3, pc, r3
 *   @0x21a608 str r2, [r3, #0x38]
 *   @0x21a60c mov r0, r7
 *   @0x21a610 add sp, sp, #12
 *   @0x21a614 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21a618 b 0x21625c <_Z19Audio_CreateSourcesi>
 *   @0x21a61c add sp, sp, #12
 *   @0x21a620 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21a624 mov r0, r5
 *   @0x21a628 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21a62c str r5, [r9, #0x3c]
 *   @0x21a630 b 0x21a5fc <_Z20Audio_SetNumChannelsi+0x1a8>
 *   @0x21a634 andseq r7, sp, r12, ror #15
 *   @0x21a638 .word 0xffffd0e0
 *   @0x21a63c .word 0xfffff780
 *   @0x21a640 .word 0xffffbac4
 *   @0x21a644 andseq r9, r3, r12, asr r11
 *   @0x21a648 subseq r10, r3, r8, asr #27
 *   @0x21a64c .word 0xfffff77c
 *   @0x21a650 subseq r10, r3, r0, ror #26
 *   @0x21a654 subseq r10, r3, r12, lsr #26
 *   @0x21a658 subseq r10, r3, r8, lsr #26
 *   @0x21a65c subseq r10, r3, r0, lsr #25
 *   @0x21a660 .word 0x0053ac90
 *
 * ══ §46/57 F_SkeletonDrawInstance(RValue&, CInstance*, CInstance*, int, RValue*)  0x11d6b4  size 524  131 条（0x11d6b4..0x11d8c0）
 * @func 0x11d6b4 0x11d8c0  size 524  131 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x11d6ec→0x536f28, 0x11d73c→0x3eb70c, 0x11d8a0→0x3eb70c
 * 调用序列: YYGetFloat(RValue const*, int)×7 / YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int)×2 / F_SkeletonDrawInstance(RValue&, CInstance*, CInstance*, int, RValue*)+0x80 / CInstance::SkeletonAnimation() / Sprite_Data(int) / CSkeletonSprite::DrawFrame(CSkeletonInstance*, char const*, char const*, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x8×3 / 0x58×2 / 0x2c×2 / 0x20×2 / 0x24×2 / 0x28×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11d6b4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11d6b8 sub sp, sp, #52
 *   @0x11d6bc mov r1, #0
 *   @0x11d6c0 str r1, [r0, #0xc]
 *   @0x11d6c4 ldr r4, [sp, #0x58]
 *   @0x11d6c8 mov r3, r1
 *   @0x11d6cc movt r3, #0xbff0
 *   @0x11d6d0 stm r0, {r1, r3}
 *   @0x11d6d4 ldr r7, [pc, #0x1d0]
 *   @0x11d6d8 mov r0, r4
 *   @0x11d6dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d6e0 add r7, pc, r7
 *   @0x11d6e4 subs r6, r0, #0
 *   @0x11d6e8 blt 0x11d734 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x11d6ec ldr r3, [pc, #0x1bc]
 *   @0x11d6f0 ldr r3, [r7, r3]
 *   @0x11d6f4 ldr r2, [r3, #0x4]
 *   @0x11d6f8 ldr r3, [r3]
 *   @0x11d6fc and r2, r6, r2
 *   @0x11d700 ldr r3, [r3, r2, lsl #3]
 *   @0x11d704 cmp r3, #0
 *   @0x11d708 beq 0x11d734 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x11d70c ldr r2, [r3, #0x8]
 *   @0x11d710 cmp r6, r2
 *   @0x11d714 bne 0x11d728 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x11d718 b 0x11d760 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x11d71c ldr r1, [r3, #0x8]
 *   @0x11d720 cmp r6, r1
 *   @0x11d724 beq 0x11d760 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x11d728 ldr r3, [r3, #0x4]
 *   @0x11d72c cmp r3, #0
 *   @0x11d730 bne 0x11d71c <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x11d734 ldr r1, [pc, #0x178]
 *   @0x11d738 mov r2, r6
 *   @0x11d73c ldr r3, [pc, #0x174]
 *   @0x11d740 add r1, pc, r1
 *   @0x11d744 ldr r3, [r7, r3]
 *   @0x11d748 ldr r0, [r3]
 *   @0x11d74c ldr r3, [r0]
 *   @0x11d750 ldr r3, [r3, #0xc]
 *   @0x11d754 blx r3
 *   @0x11d758 add sp, sp, #52
 *   @0x11d75c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11d760 ldr r8, [r3, #0xc]
 *   @0x11d764 cmp r8, #0
 *   @0x11d768 beq 0x11d734 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x11d76c mov r0, r8
 *   @0x11d770 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11d774 subs r5, r0, #0
 *   @0x11d778 beq 0x11d898 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x11d77c ldr r0, [r8, #0x8c]
 *   @0x11d780 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11d784 subs r3, r0, #0
 *   @0x11d788 beq 0x11d798 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x11d78c ldr r6, [r3, #0x74]
 *   @0x11d790 cmp r6, #2
 *   @0x11d794 beq 0x11d7a0 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x11d798 add sp, sp, #52
 *   @0x11d79c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11d7a0 ldr r3, [r3, #0x58]
 *   @0x11d7a4 mov r0, r4
 *   @0x11d7a8 mov r1, #1
 *   @0x11d7ac str r3, [sp, #0x2c]
 *   @0x11d7b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d7b4 mov r1, r6
 *   @0x11d7b8 mov r7, r0
 *   @0x11d7bc mov r0, r4
 *   @0x11d7c0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11d7c4 mov r1, #3
 *   @0x11d7c8 mov r6, r0
 *   @0x11d7cc mov r0, r4
 *   @0x11d7d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d7d4 mov r1, #4
 *   @0x11d7d8 mov r12, r0
 *   @0x11d7dc mov r0, r4
 *   @0x11d7e0 str r12, [sp, #0x20]
 *   @0x11d7e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d7e8 mov r1, #5
 *   @0x11d7ec mov r2, r0
 *   @0x11d7f0 mov r0, r4
 *   @0x11d7f4 str r2, [sp, #0x24]
 *   @0x11d7f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d7fc mov r1, #6
 *   @0x11d800 mov r3, r0
 *   @0x11d804 mov r0, r4
 *   @0x11d808 str r3, [sp, #0x28]
 *   @0x11d80c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d810 mov r1, #7
 *   @0x11d814 mov r11, r0
 *   @0x11d818 mov r0, r4
 *   @0x11d81c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d820 mov r1, #8
 *   @0x11d824 mov r10, r0
 *   @0x11d828 mov r0, r4
 *   @0x11d82c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d830 mov r1, #9
 *   @0x11d834 mov r9, r0
 *   @0x11d838 mov r0, r4
 *   @0x11d83c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11d840 mov r1, #10
 *   @0x11d844 mov r8, r0
 *   @0x11d848 mov r0, r4
 *   @0x11d84c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11d850 ldr r2, [sp, #0x24]
 *   @0x11d854 ldr r3, [sp, #0x28]
 *   @0x11d858 mov r1, r5
 *   @0x11d85c ldr r12, [sp, #0x20]
 *   @0x11d860 str r2, [sp, #0x4]
 *   @0x11d864 mov r2, r7
 *   @0x11d868 str r3, [sp, #0x8]
 *   @0x11d86c mov r3, r6
 *   @0x11d870 str r12, [sp]
 *   @0x11d874 str r11, [sp, #0xc]
 *   @0x11d878 str r10, [sp, #0x10]
 *   @0x11d87c str r9, [sp, #0x14]
 *   @0x11d880 str r8, [sp, #0x18]
 *   @0x11d884 str r0, [sp, #0x1c]
 *   @0x11d888 ldr r0, [sp, #0x2c]
 *   @0x11d88c bl 0xc069c <_ZN15CSkeletonSprite9DrawFrameEP17CSkeletonInstancePKcS3_ffffffjf>
 *   @0x11d890 add sp, sp, #52
 *   @0x11d894 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11d898 ldr r1, [pc, #0x1c]
 *   @0x11d89c mov r2, r6
 *   @0x11d8a0 ldr r3, [pc, #0x10]
 *   @0x11d8a4 add r1, pc, r1
 *   @0x11d8a8 b 0x11d744 <_Z22F_SkeletonDrawInstanceR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x11d8ac eoreq r4, sp, r0, ror r5
 *   @0x11d8b0 .word 0xffffbff4
 *   @0x11d8b4 eoreq r12, r1, r0, lsl #19
 *   @0x11d8b8 .word 0xffffbac4
 *   @0x11d8bc eoreq r12, r1, r12, asr r8
 *
 * ══ §47/57 F_DrawBackgroundTiledExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11f640  size 524  124 条（0x11f640..0x11f84c）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x11f640 0x11f84c  size 524  124 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x11f650→0x5428e8, 0x11f6c0→0x54298c, 0x11f798→0x54298c
 * 调用序列: YYGetFloat(RValue const*, int)×10 / YYGetInt32(RValue const*, int)×4 / Sprite_Data(int) / CSprite::DrawTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float) / Background_Data(int) / CBackground::DrawTiled(float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x20×3 / 0x1e8×2 / 0x8×2 / 0xc×2 / 0x4×2 / 0x10×2 / 0x50×1 / 0x17c×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11f640 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11f644 vpush {d8}
 *   @0x11f664 ldrb r1, [r3]
 *   @0x11f668 cmp r1, #0
 *   @0x11f66c beq 0x11f74c <_Z24F_DrawBackgroundTiledExtR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x11f670 mov r1, #0
 *   @0x11f674 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f678 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11f67c subs r6, r0, #0
 *   @0x11f680 beq 0x11f820 <_Z24F_DrawBackgroundTiledExtR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x11f684 mov r0, r4
 *   @0x11f688 mov r1, #1
 *   @0x11f68c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f690 mov r1, #2
 *   @0x11f694 mov r8, r0
 *   @0x11f698 mov r0, r4
 *   @0x11f69c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f6a0 mov r1, #3
 *   @0x11f6a4 mov r7, r0
 *   @0x11f6a8 mov r0, r4
 *   @0x11f6ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f6b0 mov r1, #4
 *   @0x11f6b4 mov r10, r0
 *   @0x11f6b8 mov r0, r4
 *   @0x11f6bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f6c0 ldr r3, [pc, #0x17c]
 *   @0x11f6c4 mov r1, #5
 *   @0x11f6c8 ldr r3, [r5, r3]
 *   @0x11f6cc ldr r12, [r3]
 *   @0x11f6d0 vldr s17, [r12, #16]
 *   @0x11f6d4 vldr s16, [r12, #20]
 *   @0x11f6d8 vcvt.f32.s32 s17, s17
 *   @0x11f6dc vcvt.f32.s32 s16, s16
 *   @0x11f6e0 mov r9, r0
 *   @0x11f6e4 mov r0, r4
 *   @0x11f6e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f6ec mov r1, #6
 *   @0x11f6f0 mov r5, r0
 *   @0x11f6f4 mov r0, r4
 *   @0x11f6f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f6fc mov r12, #0
 *   @0x11f700 mov r1, #1
 *   @0x11f704 str r10, [sp]
 *   @0x11f708 str r1, [sp, #0x8]
 *   @0x11f70c vstr s17, [sp, #24]
 *   @0x11f710 str r1, [sp, #0xc]
 *   @0x11f714 mov r2, r8
 *   @0x11f718 str r9, [sp, #0x4]
 *   @0x11f71c vstr s16, [sp, #28]
 *   @0x11f720 str r5, [sp, #0x20]
 *   @0x11f724 mov r3, r7
 *   @0x11f728 str r12, [sp, #0x10]
 *   @0x11f72c mov r1, #0
 *   @0x11f730 str r12, [sp, #0x14]
 *   @0x11f734 str r0, [sp, #0x24]
 *   @0x11f738 mov r0, r6
 *   @0x11f73c bl 0x1ed1dc <_ZN7CSprite9DrawTiledEiffffbbffffjf>
 *   @0x11f740 add sp, sp, #40
 *   @0x11f744 vpop {d8}
 *   @0x11f748 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11f74c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f750 bl 0xc3794 <_Z15Background_Datai>
 *   @0x11f754 subs r6, r0, #0
 *   @0x11f758 beq 0x11f820 <_Z24F_DrawBackgroundTiledExtR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x11f75c mov r0, r4
 *   @0x11f760 mov r1, #1
 *   @0x11f764 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f768 mov r1, #2
 *   @0x11f76c mov r9, r0
 *   @0x11f770 mov r0, r4
 *   @0x11f774 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f778 mov r1, #3
 *   @0x11f77c mov r8, r0
 *   @0x11f780 mov r0, r4
 *   @0x11f784 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f788 mov r1, #4
 *   @0x11f78c mov r7, r0
 *   @0x11f790 mov r0, r4
 *   @0x11f794 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f798 ldr r3, [pc, #0xa4]
 *   @0x11f79c mov r1, #5
 *   @0x11f7a0 ldr r3, [r5, r3]
 *   @0x11f7a4 ldr r12, [r3]
 *   @0x11f7a8 vldr s17, [r12, #16]
 *   @0x11f7ac vldr s16, [r12, #20]
 *   @0x11f7b0 vcvt.f32.s32 s17, s17
 *   @0x11f7b4 vcvt.f32.s32 s16, s16
 *   @0x11f7b8 mov r10, r0
 *   @0x11f7bc mov r0, r4
 *   @0x11f7c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f7c4 mov r1, #6
 *   @0x11f7c8 mov r5, r0
 *   @0x11f7cc mov r0, r4
 *   @0x11f7d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11f7d4 mov r12, #1
 *   @0x11f7d8 mov lr, #0
 *   @0x11f7dc str r10, [sp]
 *   @0x11f7e0 vstr s17, [sp, #20]
 *   @0x11f7e4 str r5, [sp, #0x1c]
 *   @0x11f7e8 mov r1, r9
 *   @0x11f7ec mov r2, r8
 *   @0x11f7f0 vstr s16, [sp, #24]
 *   @0x11f7f4 mov r3, r7
 *   @0x11f7f8 str r12, [sp, #0x4]
 *   @0x11f7fc str lr, [sp, #0xc]
 *   @0x11f800 str r12, [sp, #0x8]
 *   @0x11f804 str lr, [sp, #0x10]
 *   @0x11f808 str r0, [sp, #0x20]
 *   @0x11f80c mov r0, r6
 *   @0x11f810 bl 0xc22d8 <_ZN11CBackground9DrawTiledEffffbbffffjf>
 *   @0x11f814 add sp, sp, #40
 *   @0x11f818 vpop {d8}
 *   @0x11f81c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11f820 ldr r0, [pc, #0x20]
 *   @0x11f824 mov r1, #0
 *   @0x11f828 add r0, pc, r0
 *   @0x11f82c add sp, sp, #40
 *   @0x11f830 vpop {d8}
 *   @0x11f834 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11f838 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11f83c .word 0x002d25fc
 *   @0x11f840 .word 0xffffbcd4
 *   @0x11f844 .word 0xffffbcd8
 *   @0x11f848 eoreq r10, r1, r12, lsr #19
 *
 * ══ §48/57 F_SpritePrefetchMulti(RValue&, CInstance*, CInstance*, int, RValue*)  0x1303d4  size 524  131 条（0x1303d4..0x1305e0）
 * @func 0x1303d4 0x1305e0  size 524  131 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_SpritePrefetchMulti(RValue&, CInstance*, CInstance*, int, RValue*)+0x1b0×2 / Graphics::PrefetchTexture(void*)×2 / YYGetInt32(RValue const*, int) / Sprite_Data(int) / F_SpritePrefetchMulti(RValue&, CInstance*, CInstance*, int, RValue*)+0xe0 / CSprite::GetTexture(int)
 * 字段偏移 top8: 0x4×9 / 0xc×6 / 0x188×2 / 0x2×2 / 0x30×1 / 0x1cc×1 / 0x10×1 / 0x168×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1303d4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1303d8 sub sp, sp, #12
 *   @0x1303dc mov r6, #0
 *   @0x1303e0 str r6, [r0, #0xc]
 *   @0x1303e4 ldr r2, [sp, #0x30]
 *   @0x1303e8 mov r3, r6
 *   @0x1303ec ldr r7, [pc, #0x1cc]
 *   @0x1303f0 movt r3, #0xbff0
 *   @0x1303f4 mov r9, r0
 *   @0x1303f8 str r6, [r0]
 *   @0x1303fc ldr r1, [r2, #0xc]
 *   @0x130400 add r7, pc, r7
 *   @0x130404 str r3, [r0, #0x4]
 *   @0x130408 cmp r1, #2
 *   @0x13040c bne 0x13045c <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x130410 ldr r8, [r2]
 *   @0x130414 cmp r8, #0
 *   @0x130418 beq 0x130434 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x13041c ldr r3, [r8, #0x4]
 *   @0x130420 cmp r3, #0
 *   @0x130424 beq 0x130434 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x130428 ldr r2, [r8, #0x10]
 *   @0x13042c cmp r2, #1
 *   @0x130430 beq 0x13046c <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x130434 ldr r1, [pc, #0x188]
 *   @0x130438 ldr r3, [pc, #0x188]
 *   @0x13043c add r1, pc, r1
 *   @0x130440 ldr r3, [r7, r3]
 *   @0x130444 ldr r0, [r3]
 *   @0x130448 ldr r3, [r0]
 *   @0x13044c ldr r3, [r3, #0xc]
 *   @0x130450 blx r3
 *   @0x130454 add sp, sp, #12
 *   @0x130458 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13045c ldr r1, [pc, #0x168]
 *   @0x130460 ldr r3, [pc, #0x160]
 *   @0x130464 add r1, pc, r1
 *   @0x130468 b 0x130440 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x13046c ldr r2, [r3]
 *   @0x130470 cmp r2, #0
 *   @0x130474 ble 0x130584 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x130478 ldr r2, [pc, #0x150]
 *   @0x13047c add r2, pc, r2
 *   @0x130480 str r2, [sp, #0x4]
 *   @0x130484 ldr r2, [pc, #0x148]
 *   @0x130488 add r2, pc, r2
 *   @0x13048c str r2, [sp]
 *   @0x130490 b 0x1304c8 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x130494 ldr r3, [pc, #0x12c]
 *   @0x130498 mov r2, r6
 *   @0x13049c ldr r1, [sp]
 *   @0x1304a0 ldr r3, [r7, r3]
 *   @0x1304a4 ldr r0, [r3]
 *   @0x1304a8 ldr r3, [r0]
 *   @0x1304ac ldr r3, [r3, #0xc]
 *   @0x1304b0 blx r3
 *   @0x1304b4 ldr r3, [r8, #0x4]
 *   @0x1304b8 add r6, r6, #1
 *   @0x1304bc ldr r2, [r3]
 *   @0x1304c0 cmp r2, r6
 *   @0x1304c4 ble 0x130584 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x1304c8 ldr r0, [r3, #0x4]
 *   @0x1304cc add r0, r0, r6, lsl #4
 *   @0x1304d0 ldr r1, [r0, #0xc]
 *   @0x1304d4 cmp r1, #0
 *   @0x1304d8 bne 0x130494 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1304dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1304e0 mov r5, r0
 *   @0x1304e4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1304e8 subs r4, r0, #0
 *   @0x1304ec beq 0x130574 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x1304f0 ldr r3, [r4, #0x74]
 *   @0x1304f4 cmp r3, #0
 *   @0x1304f8 bne 0x130598 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x1304fc ldr r5, [r4, #0x18]
 *   @0x130500 cmp r5, #0
 *   @0x130504 ble 0x1304b4 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x130508 ldr r2, [pc, #0xc8]
 *   @0x13050c mov r10, r3
 *   @0x130510 ldr r11, [r7, r2]
 *   @0x130514 b 0x130540 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x130518 cmn r0, #1
 *   @0x13051c beq 0x130558 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x130520 ldrsh r0, [r0, #20]
 *   @0x130524 ldr r1, [r11, #0x4]
 *   @0x130528 ldr r1, [r1, r0, lsl #2]
 *   @0x13052c ldr r0, [r1]
 *   @0x130530 bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv>
 *   @0x130534 add r10, r10, #1
 *   @0x130538 cmp r10, r5
 *   @0x13053c beq 0x1304b4 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x130540 mov r1, r10
 *   @0x130544 mov r0, r4
 *   @0x130548 bl 0x1e57f4 <_ZN7CSprite10GetTextureEi>
 *   @0x13054c ldr r1, [r11]
 *   @0x130550 cmp r0, r1
 *   @0x130554 bhi 0x130518 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x130558 ldr r1, [r11, #0x4]
 *   @0x13055c ldr r1, [r1, r0, lsl #2]
 *   @0x130560 cmp r1, #0
 *   @0x130564 beq 0x130534 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x130568 ldr r0, [r1]
 *   @0x13056c bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv>
 *   @0x130570 b 0x130534 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x130574 ldr r3, [pc, #0x4c]
 *   @0x130578 mov r2, r5
 *   @0x13057c ldr r1, [sp, #0x4]
 *   @0x130580 b 0x1304a0 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x130584 mov r3, #0
 *   @0x130588 str r3, [r9]
 *   @0x13058c str r3, [r9, #0x4]
 *   @0x130590 add sp, sp, #12
 *   @0x130594 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x130598 ldr r3, [pc, #0x28]
 *   @0x13059c mov r2, r5
 *   @0x1305a0 ldr r1, [pc, #0x34]
 *   @0x1305a4 ldr r3, [r7, r3]
 *   @0x1305a8 add r1, pc, r1
 *   @0x1305ac ldr r0, [r3]
 *   @0x1305b0 ldr r3, [r0]
 *   @0x1305b4 ldr r3, [r3, #0xc]
 *   @0x1305b8 blx r3
 *   @0x1305bc b 0x130454 <_Z21F_SpritePrefetchMultiR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1305c0 eoreq r1, r12, r0, asr r8
 *   @0x1305c4 eoreq sp, r0, r12, lsl r12
 *   @0x1305c8 .word 0xffffbac4
 *   @0x1305cc .word 0x0020dbb0
 *   @0x1305d0 eoreq sp, r0, r4, asr #24
 *   @0x1305d4 eoreq sp, r0, r0, lsl #24
 *   @0x1305d8 .word 0xffffbccc
 *   @0x1305dc eoreq sp, r0, r8, asr #22
 *
 * ══ §49/57 IO_Record()  0x18bb00  size 524  131 条（0x18bb00..0x18bd0c）
 * @func 0x18bb00 0x18bd0c  size 524  131 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18bb08→0x5346c8, 0x18bb20→0x5356aa, 0x18bb34→0x534ea8, 0x18bb4c→0x534ea4, 0x18bb64→0x534ea0, 0x18bb7c→0x534da0, 0x18bb94→0x534ca0, 0x18bbac→0x534ba0
 * 调用序列: 0xb68bc×17
 * 字段偏移 top8: 0x1b4×2 / 0x1a0×1 / 0x190×1 / 0x17c×1 / 0x168×1 / 0x154×1 / 0x140×1 / 0x12c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bb00 push {r3, r4, r5, lr}
 *   @0x18bb04 ldr r4, [pc, #0x1b4]
 *   @0x18bb08 ldr r3, [pc, #0x1b4]
 *   @0x18bb0c add r4, pc, r4
 *   @0x18bb10 ldr r5, [r4, r3]
 *   @0x18bb14 ldr r3, [r5]
 *   @0x18bb18 cmp r3, #0
 *   @0x18bb1c popeq {r3, r4, r5, pc}
 *   @0x18bb20 ldr r0, [pc, #0x1a0]
 *   @0x18bb24 mov r1, #2
 *   @0x18bb28 mov r2, #1
 *   @0x18bb2c ldr r0, [r4, r0]
 *   @0x18bb30 bl 0xb68bc <fwrite@plt>
 *   @0x18bb34 ldr r0, [pc, #0x190]
 *   @0x18bb38 ldr r3, [r5]
 *   @0x18bb3c movw r1, #0x802
 *   @0x18bb40 mov r2, #1
 *   @0x18bb44 ldr r0, [r4, r0]
 *   @0x18bb48 bl 0xb68bc <fwrite@plt>
 *   @0x18bb4c ldr r0, [pc, #0x17c]
 *   @0x18bb50 ldr r3, [r5]
 *   @0x18bb54 mov r1, #4
 *   @0x18bb58 mov r2, #1
 *   @0x18bb5c ldr r0, [r4, r0]
 *   @0x18bb60 bl 0xb68bc <fwrite@plt>
 *   @0x18bb64 ldr r0, [pc, #0x168]
 *   @0x18bb68 ldr r3, [r5]
 *   @0x18bb6c mov r1, #4
 *   @0x18bb70 mov r2, #1
 *   @0x18bb74 ldr r0, [r4, r0]
 *   @0x18bb78 bl 0xb68bc <fwrite@plt>
 *   @0x18bb7c ldr r0, [pc, #0x154]
 *   @0x18bb80 ldr r3, [r5]
 *   @0x18bb84 mov r1, #256
 *   @0x18bb88 mov r2, #1
 *   @0x18bb8c ldr r0, [r4, r0]
 *   @0x18bb90 bl 0xb68bc <fwrite@plt>
 *   @0x18bb94 ldr r0, [pc, #0x140]
 *   @0x18bb98 ldr r3, [r5]
 *   @0x18bb9c mov r1, #256
 *   @0x18bba0 mov r2, #1
 *   @0x18bba4 ldr r0, [r4, r0]
 *   @0x18bba8 bl 0xb68bc <fwrite@plt>
 *   @0x18bbac ldr r0, [pc, #0x12c]
 *   @0x18bbb0 ldr r3, [r5]
 *   @0x18bbb4 mov r1, #256
 *   @0x18bbb8 mov r2, #1
 *   @0x18bbbc ldr r0, [r4, r0]
 *   @0x18bbc0 bl 0xb68bc <fwrite@plt>
 *   @0x18bbc4 ldr r0, [pc, #0x118]
 *   @0x18bbc8 ldr r3, [r5]
 *   @0x18bbcc mov r1, #40
 *   @0x18bbd0 mov r2, #1
 *   @0x18bbd4 ldr r0, [r4, r0]
 *   @0x18bbd8 bl 0xb68bc <fwrite@plt>
 *   @0x18bbdc ldr r0, [pc, #0x104]
 *   @0x18bbe0 ldr r3, [r5]
 *   @0x18bbe4 mov r1, #40
 *   @0x18bbe8 mov r2, #1
 *   @0x18bbec ldr r0, [r4, r0]
 *   @0x18bbf0 bl 0xb68bc <fwrite@plt>
 *   @0x18bbf4 ldr r0, [pc, #0xf0]
 *   @0x18bbf8 ldr r3, [r5]
 *   @0x18bbfc mov r1, #30
 *   @0x18bc00 mov r2, #1
 *   @0x18bc04 ldr r0, [r4, r0]
 *   @0x18bc08 bl 0xb68bc <fwrite@plt>
 *   @0x18bc0c ldr r0, [pc, #0xdc]
 *   @0x18bc10 ldr r3, [r5]
 *   @0x18bc14 mov r1, #30
 *   @0x18bc18 mov r2, #1
 *   @0x18bc1c ldr r0, [r4, r0]
 *   @0x18bc20 bl 0xb68bc <fwrite@plt>
 *   @0x18bc24 ldr r0, [pc, #0xc8]
 *   @0x18bc28 ldr r3, [r5]
 *   @0x18bc2c mov r1, #30
 *   @0x18bc30 mov r2, #1
 *   @0x18bc34 ldr r0, [r4, r0]
 *   @0x18bc38 bl 0xb68bc <fwrite@plt>
 *   @0x18bc3c ldr r0, [pc, #0xb4]
 *   @0x18bc40 ldr r3, [r5]
 *   @0x18bc44 mov r1, #10
 *   @0x18bc48 mov r2, #1
 *   @0x18bc4c ldr r0, [r4, r0]
 *   @0x18bc50 bl 0xb68bc <fwrite@plt>
 *   @0x18bc54 ldr r0, [pc, #0xa0]
 *   @0x18bc58 ldr r3, [r5]
 *   @0x18bc5c mov r1, #10
 *   @0x18bc60 mov r2, #1
 *   @0x18bc64 ldr r0, [r4, r0]
 *   @0x18bc68 bl 0xb68bc <fwrite@plt>
 *   @0x18bc6c ldr r0, [pc, #0x8c]
 *   @0x18bc70 ldr r3, [r5]
 *   @0x18bc74 mov r1, #8
 *   @0x18bc78 mov r2, #1
 *   @0x18bc7c ldr r0, [r4, r0]
 *   @0x18bc80 bl 0xb68bc <fwrite@plt>
 *   @0x18bc84 ldr r0, [pc, #0x78]
 *   @0x18bc88 ldr r3, [r5]
 *   @0x18bc8c mov r1, #4
 *   @0x18bc90 mov r2, #1
 *   @0x18bc94 ldr r0, [r4, r0]
 *   @0x18bc98 bl 0xb68bc <fwrite@plt>
 *   @0x18bc9c ldr r0, [pc, #0x64]
 *   @0x18bca0 ldr r3, [r5]
 *   @0x18bca4 mov r1, #4
 *   @0x18bca8 mov r2, #1
 *   @0x18bcac ldr r0, [r4, r0]
 *   @0x18bcb0 bl 0xb68bc <fwrite@plt>
 *   @0x18bcb4 ldr r0, [r5]
 *   @0x18bcb8 pop {r3, r4, r5, lr}
 *   @0x18bcbc b 0xb691c <fflush@plt>
 *   @0x18bcc0 eoreq r6, r6, r4, asr #2
 *   @0x18bcc4 .word 0xffffe97c
 *   @0x18bcc8 .word 0xffffe980
 *   @0x18bccc .word 0xffffe984
 *   @0x18bcd0 .word 0xffffe988
 *   @0x18bcd4 .word 0xffffe98c
 *   @0x18bcd8 .word 0xffffe990
 *   @0x18bcdc .word 0xffffe994
 *   @0x18bce0 .word 0xffffe998
 *   @0x18bce4 .word 0xffffe99c
 *   @0x18bce8 .word 0xffffe9a0
 *   @0x18bcec .word 0xffffe9a4
 *   @0x18bcf0 .word 0xffffe9a8
 *   @0x18bcf4 .word 0xffffe9ac
 *   @0x18bcf8 .word 0xffffe9b0
 *   @0x18bcfc .word 0xffffe9b4
 *   @0x18bd00 .word 0xffffe9b8
 *   @0x18bd04 .word 0xffffe720
 *   @0x18bd08 .word 0xffffe724
 *
 * ══ §50/57 Debug_PokeStructure(Buffer_Standard*, Buffer_Standard*)  0x29bb78  size 524  131 条（0x29bb78..0x29bd84）
 * @func 0x29bb78 0x29bd84  size 524  131 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int)×5 / ReadString(Buffer_Standard*) / YYSetString(RValue*, char const*) / VM::PokeDSGrid(int, int, int, RValue&) / VM::PokeDSList(int, int, RValue&) / VM::PokeDSMap(int, int, RValue&) / VM::PokeDSStack(int, int, RValue&) / VM::PokeDSQueue(int, int, RValue&)
 * 字段偏移 top8: 0xc×7 / 0x2c×3 / 0x30×2 / 0x38×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29bb78 ldr r3, [r0]
 *   @0x29bb7c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29bb80 add r4, r0, #44
 *   @0x29bb84 sub sp, sp, #20
 *   @0x29bb88 ldr r3, [r3, #0xc]
 *   @0x29bb8c mov r2, r4
 *   @0x29bb90 mov r10, r1
 *   @0x29bb94 mov r1, #5
 *   @0x29bb98 mov r11, r0
 *   @0x29bb9c blx r3
 *   @0x29bba0 mov r1, #0
 *   @0x29bba4 mov r0, r4
 *   @0x29bba8 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29bbac ldr r3, [r11]
 *   @0x29bbb0 mov r2, r4
 *   @0x29bbb4 mov r1, #5
 *   @0x29bbb8 ldr r3, [r3, #0xc]
 *   @0x29bbbc mov r6, r0
 *   @0x29bbc0 mov r0, r11
 *   @0x29bbc4 blx r3
 *   @0x29bbc8 mov r1, #0
 *   @0x29bbcc mov r0, r4
 *   @0x29bbd0 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29bbd4 ldr r3, [r11]
 *   @0x29bbd8 mov r2, r4
 *   @0x29bbdc mov r1, #5
 *   @0x29bbe0 ldr r3, [r3, #0xc]
 *   @0x29bbe4 mov r8, r0
 *   @0x29bbe8 mov r0, r11
 *   @0x29bbec blx r3
 *   @0x29bbf0 mov r1, #0
 *   @0x29bbf4 mov r0, r4
 *   @0x29bbf8 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29bbfc ldr r3, [r11]
 *   @0x29bc00 mov r2, r4
 *   @0x29bc04 mov r1, #5
 *   @0x29bc08 ldr r3, [r3, #0xc]
 *   @0x29bc0c mov r7, r0
 *   @0x29bc10 mov r0, r11
 *   @0x29bc14 blx r3
 *   @0x29bc18 mov r1, #0
 *   @0x29bc1c mov r0, r4
 *   @0x29bc20 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29bc24 ldr r3, [r11]
 *   @0x29bc28 mov r2, r4
 *   @0x29bc2c mov r1, #5
 *   @0x29bc30 ldr r3, [r3, #0xc]
 *   @0x29bc34 mov r9, r0
 *   @0x29bc38 mov r0, r11
 *   @0x29bc3c blx r3
 *   @0x29bc40 mov r0, r4
 *   @0x29bc44 mov r1, #0
 *   @0x29bc48 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29bc4c cmp r0, #1
 *   @0x29bc50 beq 0x29bcdc <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x164>
 *   @0x29bc54 ldr r3, [r11]
 *   @0x29bc58 mov r2, r4
 *   @0x29bc5c mov r1, #0
 *   @0x29bc60 mov r0, r11
 *   @0x29bc64 str r1, [sp, #0xc]
 *   @0x29bc68 mov r1, #9
 *   @0x29bc6c ldr r3, [r3, #0xc]
 *   @0x29bc70 blx r3
 *   @0x29bc74 ldr r4, [r11, #0x2c]
 *   @0x29bc78 ldr r5, [r11, #0x30]
 *   @0x29bc7c strd r4, r5, [sp]
 *   @0x29bc80 cmp r6, #5
 *   @0x29bc84 addls pc, pc, r6, lsl #2
 *   @0x29bc88 b 0x29bca4 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x12c>
 *   @0x29bc8c b 0x29bd20 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x1a8>
 *   @0x29bc90 b 0x29bd34 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x1bc>
 *   @0x29bc94 b 0x29bd48 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x1d0>
 *   @0x29bc98 b 0x29bd5c <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x1e4>
 *   @0x29bc9c b 0x29bd70 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x1f8>
 *   @0x29bca0 b 0x29bcf4 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x17c>
 *   @0x29bca4 mov r3, #0
 *   @0x29bca8 mov r1, r3
 *   @0x29bcac mov r2, r10
 *   @0x29bcb0 str r3, [r10, #0x2c]
 *   @0x29bcb4 ldr r3, [r2], #44
 *   @0x29bcb8 mov r12, #0
 *   @0x29bcbc str r1, [r10, #0x30]
 *   @0x29bcc0 mov r0, r10
 *   @0x29bcc4 str r12, [r10, #0x38]
 *   @0x29bcc8 mov r1, #5
 *   @0x29bccc ldr r3, [r3, #0x8]
 *   @0x29bcd0 blx r3
 *   @0x29bcd4 add sp, sp, #20
 *   @0x29bcd8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29bcdc mov r0, r11
 *   @0x29bce0 bl 0x29e69c <_Z10ReadStringP15Buffer_Standard>
 *   @0x29bce4 mov r1, r0
 *   @0x29bce8 mov r0, sp
 *   @0x29bcec bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x29bcf0 b 0x29bc80 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x108>
 *   @0x29bcf4 mov r0, r8
 *   @0x29bcf8 mov r1, r7
 *   @0x29bcfc mov r2, r9
 *   @0x29bd00 mov r3, sp
 *   @0x29bd04 bl 0xe9bd8 <_ZN2VM10PokeDSGridEiiiR6RValue>
 *   @0x29bd08 cmp r0, #0
 *   @0x29bd0c beq 0x29bca4 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x12c>
 *   @0x29bd10 mov r1, #0
 *   @0x29bd14 mov r3, #0
 *   @0x29bd18 movt r1, #0x3ff0
 *   @0x29bd1c b 0x29bcac <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x134>
 *   @0x29bd20 mov r0, r8
 *   @0x29bd24 mov r1, r7
 *   @0x29bd28 mov r2, sp
 *   @0x29bd2c bl 0xe4ba8 <_ZN2VM10PokeDSListEiiR6RValue>
 *   @0x29bd30 b 0x29bd08 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x190>
 *   @0x29bd34 mov r0, r8
 *   @0x29bd38 mov r1, r7
 *   @0x29bd3c mov r2, sp
 *   @0x29bd40 bl 0xe6364 <_ZN2VM9PokeDSMapEiiR6RValue>
 *   @0x29bd44 b 0x29bd08 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x190>
 *   @0x29bd48 mov r0, r8
 *   @0x29bd4c mov r1, r7
 *   @0x29bd50 mov r2, sp
 *   @0x29bd54 bl 0xe4d6c <_ZN2VM11PokeDSStackEiiR6RValue>
 *   @0x29bd58 b 0x29bd08 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x190>
 *   @0x29bd5c mov r0, r8
 *   @0x29bd60 mov r1, r7
 *   @0x29bd64 mov r2, sp
 *   @0x29bd68 bl 0xe4f18 <_ZN2VM11PokeDSQueueEiiR6RValue>
 *   @0x29bd6c b 0x29bd08 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x190>
 *   @0x29bd70 mov r0, r8
 *   @0x29bd74 mov r1, r7
 *   @0x29bd78 mov r2, sp
 *   @0x29bd7c bl 0xe50b4 <_ZN2VM14PokeDSPriorityEiiR6RValue>
 *   @0x29bd80 b 0x29bd08 <_Z19Debug_PokeStructureP15Buffer_StandardS0_+0x190>
 *
 * ══ §51/57 b2World::Dump()  0x2cb220  size 524  131 条（0x2cb220..0x2cb42c）
 * @func 0x2cb220 0x2cb42c  size 524  131 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×11 / b2Body::Dump()
 * 字段偏移 top8: 0xc×4 / 0x38×2 / 0xf4×2 / 0x4×2 / 0x10×2 / 0x1a0×1 / 0x184×1 / 0x178×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb220 movw r3, #0x91d4
 *   @0x2cb224 movt r3, #0x1
 *   @0x2cb228 push {r4, r5, r6, r7, lr}
 *   @0x2cb22c mov r6, r0
 *   @0x2cb230 ldr r5, [r0, r3]
 *   @0x2cb234 sub sp, sp, #12
 *   @0x2cb238 ands r5, r5, #2
 *   @0x2cb23c beq 0x2cb248 <_ZN7b2World4DumpEv+0x28>
 *   @0x2cb240 add sp, sp, #12
 *   @0x2cb244 pop {r4, r5, r6, r7, pc}
 *   @0x2cb248 add r2, r0, #102400
 *   @0x2cb24c vldr s14, [r2, #572]
 *   @0x2cb250 vcvt.f64.f32 d7, s14
 *   @0x2cb254 ldr r0, [pc, #0x1a0]
 *   @0x2cb258 mov r3, r2
 *   @0x2cb25c vldr s13, [r3, #568]
 *   @0x2cb260 add r0, pc, r0
 *   @0x2cb264 vstr d7, [sp]
 *   @0x2cb268 vcvt.f64.f32 d7, s13
 *   @0x2cb26c vmov r2, r3, d7
 *   @0x2cb270 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cb274 ldr r0, [pc, #0x184]
 *   @0x2cb278 add r0, pc, r0
 *   @0x2cb27c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cb280 movw r3, #0x9230
 *   @0x2cb284 ldr r0, [pc, #0x178]
 *   @0x2cb288 movt r3, #0x1
 *   @0x2cb28c add r0, pc, r0
 *   @0x2cb290 ldr r1, [r6, r3]
 *   @0x2cb294 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cb298 movw r3, #0x9234
 *   @0x2cb29c ldr r0, [pc, #0x164]
 *   @0x2cb2a0 movt r3, #0x1
 *   @0x2cb2a4 add r0, pc, r0
 *   @0x2cb2a8 ldr r1, [r6, r3]
 *   @0x2cb2ac bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cb2b0 movw r3, #0x9228
 *   @0x2cb2b4 movt r3, #0x1
 *   @0x2cb2b8 ldr r4, [r6, r3]
 *   @0x2cb2bc cmp r4, #0
 *   @0x2cb2c0 beq 0x2cb2e0 <_ZN7b2World4DumpEv+0xc0>
 *   @0x2cb2c4 str r5, [r4, #0x8]
 *   @0x2cb2c8 mov r0, r4
 *   @0x2cb2cc bl 0x2c75b4 <_ZN6b2Body4DumpEv>
 *   @0x2cb2d0 ldr r4, [r4, #0x70]
 *   @0x2cb2d4 add r5, r5, #1
 *   @0x2cb2d8 cmp r4, #0
 *   @0x2cb2dc bne 0x2cb2c4 <_ZN7b2World4DumpEv+0xa4>
 *   @0x2cb2e0 movw r3, #0x922c
 *   @0x2cb2e4 movt r3, #0x1
 *   @0x2cb2e8 ldr r4, [r6, r3]
 *   @0x2cb2ec cmp r4, #0
 *   @0x2cb2f0 movne r3, r4
 *   @0x2cb2f4 movne r2, #0
 *   @0x2cb2f8 beq 0x2cb3c4 <_ZN7b2World4DumpEv+0x1a4>
 *   @0x2cb2fc str r2, [r3, #0x38]
 *   @0x2cb300 add r2, r2, #1
 *   @0x2cb304 ldr r3, [r3, #0xc]
 *   @0x2cb308 cmp r3, #0
 *   @0x2cb30c bne 0x2cb2fc <_ZN7b2World4DumpEv+0xdc>
 *   @0x2cb310 ldr r5, [pc, #0xf4]
 *   @0x2cb314 ldr r7, [pc, #0xf4]
 *   @0x2cb318 add r5, pc, r5
 *   @0x2cb31c add r7, pc, r7
 *   @0x2cb320 ldr r3, [r4, #0x4]
 *   @0x2cb324 mov r0, r5
 *   @0x2cb328 cmp r3, #6
 *   @0x2cb32c beq 0x2cb34c <_ZN7b2World4DumpEv+0x12c>
 *   @0x2cb330 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cb334 ldr r3, [r4]
 *   @0x2cb338 mov r0, r4
 *   @0x2cb33c ldr r3, [r3, #0x10]
 *   @0x2cb340 blx r3
 *   @0x2cb344 mov r0, r7
 *   @0x2cb348 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cb34c ldr r4, [r4, #0xc]
 *   @0x2cb350 cmp r4, #0
 *   @0x2cb354 bne 0x2cb320 <_ZN7b2World4DumpEv+0x100>
 *   @0x2cb358 movw r3, #0x922c
 *   @0x2cb35c movt r3, #0x1
 *   @0x2cb360 ldr r5, [pc, #0xac]
 *   @0x2cb364 ldr r4, [r6, r3]
 *   @0x2cb368 ldr r6, [pc, #0xa8]
 *   @0x2cb36c add r5, pc, r5
 *   @0x2cb370 cmp r4, #0
 *   @0x2cb374 add r6, pc, r6
 *   @0x2cb378 bne 0x2cb38c <_ZN7b2World4DumpEv+0x16c>
 *   @0x2cb37c b 0x2cb3c4 <_ZN7b2World4DumpEv+0x1a4>
 *   @0x2cb380 ldr r4, [r4, #0xc]
 *   @0x2cb384 cmp r4, #0
 *   @0x2cb388 beq 0x2cb3c4 <_ZN7b2World4DumpEv+0x1a4>
 *   @0x2cb38c ldr r3, [r4, #0x4]
 *   @0x2cb390 cmp r3, #6
 *   @0x2cb394 bne 0x2cb380 <_ZN7b2World4DumpEv+0x160>
 *   @0x2cb398 mov r0, r6
 *   @0x2cb39c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cb3a0 ldr r3, [r4]
 *   @0x2cb3a4 mov r0, r4
 *   @0x2cb3a8 ldr r3, [r3, #0x10]
 *   @0x2cb3ac blx r3
 *   @0x2cb3b0 mov r0, r5
 *   @0x2cb3b4 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cb3b8 ldr r4, [r4, #0xc]
 *   @0x2cb3bc cmp r4, #0
 *   @0x2cb3c0 bne 0x2cb38c <_ZN7b2World4DumpEv+0x16c>
 *   @0x2cb3c4 ldr r0, [pc, #0x50]
 *   @0x2cb3c8 add r0, pc, r0
 *   @0x2cb3cc bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cb3d0 ldr r0, [pc, #0x48]
 *   @0x2cb3d4 add r0, pc, r0
 *   @0x2cb3d8 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cb3dc ldr r0, [pc, #0x40]
 *   @0x2cb3e0 add r0, pc, r0
 *   @0x2cb3e4 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cb3e8 ldr r0, [pc, #0x38]
 *   @0x2cb3ec add r0, pc, r0
 *   @0x2cb3f0 add sp, sp, #12
 *   @0x2cb3f4 pop {r4, r5, r6, r7, lr}
 *   @0x2cb3f8 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cb3fc andeq r0, r9, r0, lsl #22
 *   @0x2cb400 andeq r0, r9, r8, lsl #22
 *   @0x2cb404 andeq r0, r9, r0, lsl r11
 *   @0x2cb408 andeq r0, r9, r4, lsr r11
 *   @0x2cb40c andeq r0, r9, r8, lsr r4
 *   @0x2cb410 andeq r0, r9, r8, lsl r6
 *   @0x2cb414 andeq r0, r9, r8, asr #11
 *   @0x2cb418 ldrdeq r0, r1, [r9], -r12
 *   @0x2cb41c andeq r0, r9, r0, asr r10
 *   @0x2cb420 andeq r0, r9, r8, asr r10
 *   @0x2cb424 andeq r0, r9, r0, ror #20
 *   @0x2cb428 andeq r0, r9, r4, ror #20
 *
 * ══ §52/57 Get_Event_Name_Short(int, int)  0xf44f4  size 520  130 条（0xf44f4..0xf46fc）
 * @func 0xf44f4 0xf46fc  size 520  130 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65c8×4 / KeyToStr(int)×2 / StepToStr(int)
 * 字段偏移 top8: 0x170×1 / 0x164×1 / 0x15c×1 / 0x154×1 / 0x150×1 / 0x12c×1 / 0x128×1 / 0x124×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf44f4 push {r4, lr}
 *   @0xf44f8 sub sp, sp, #8
 *   @0xf44fc cmp r0, #14
 *   @0xf4500 addls pc, pc, r0, lsl #2
 *   @0xf4504 b 0xf46a4 <_Z20Get_Event_Name_Shortii+0x1b0>
 *   @0xf4508 b 0xf4554 <_Z20Get_Event_Name_Shortii+0x60>
 *   @0xf450c b 0xf4560 <_Z20Get_Event_Name_Shortii+0x6c>
 *   @0xf4510 b 0xf456c <_Z20Get_Event_Name_Shortii+0x78>
 *   @0xf4514 b 0xf4598 <_Z20Get_Event_Name_Shortii+0xa4>
 *   @0xf4518 b 0xf45d8 <_Z20Get_Event_Name_Shortii+0xe4>
 *   @0xf451c b 0xf45e8 <_Z20Get_Event_Name_Shortii+0xf4>
 *   @0xf4520 b 0xf45f8 <_Z20Get_Event_Name_Shortii+0x104>
 *   @0xf4524 b 0xf4608 <_Z20Get_Event_Name_Shortii+0x114>
 *   @0xf4528 b 0xf4620 <_Z20Get_Event_Name_Shortii+0x12c>
 *   @0xf452c b 0xf462c <_Z20Get_Event_Name_Shortii+0x138>
 *   @0xf4530 b 0xf4668 <_Z20Get_Event_Name_Shortii+0x174>
 *   @0xf4534 b 0xf46a4 <_Z20Get_Event_Name_Shortii+0x1b0>
 *   @0xf4538 b 0xf46a4 <_Z20Get_Event_Name_Shortii+0x1b0>
 *   @0xf453c b 0xf46a4 <_Z20Get_Event_Name_Shortii+0x1b0>
 *   @0xf4540 b 0xf4544 <_Z20Get_Event_Name_Shortii+0x50>
 *   @0xf4544 ldr r0, [pc, #0x170]
 *   @0xf4548 add r0, pc, r0
 *   @0xf454c add sp, sp, #8
 *   @0xf4550 pop {r4, pc}
 *   @0xf4554 ldr r0, [pc, #0x164]
 *   @0xf4558 add r0, pc, r0
 *   @0xf455c b 0xf454c <_Z20Get_Event_Name_Shortii+0x58>
 *   @0xf4560 ldr r0, [pc, #0x15c]
 *   @0xf4564 add r0, pc, r0
 *   @0xf4568 b 0xf454c <_Z20Get_Event_Name_Shortii+0x58>
 *   @0xf456c ldr r4, [pc, #0x154]
 *   @0xf4570 mov r3, r1
 *   @0xf4574 ldr r2, [pc, #0x150]
 *   @0xf4578 mov r1, #512
 *   @0xf457c add r4, pc, r4
 *   @0xf4580 add r4, r4, #64
 *   @0xf4584 add r2, pc, r2
 *   @0xf4588 mov r0, r4
 *   @0xf458c bl 0xb65c8 <snprintf@plt>
 *   @0xf4590 mov r0, r4
 *   @0xf4594 b 0xf454c <_Z20Get_Event_Name_Shortii+0x58>
 *   @0xf4598 mov r0, r1
 *   @0xf459c ldr r4, [pc, #0x12c]
 *   @0xf45a0 bl 0xf344c <_Z9StepToStri>
 *   @0xf45a4 ldr r12, [pc, #0x128]
 *   @0xf45a8 add r4, pc, r4
 *   @0xf45ac ldr r2, [pc, #0x124]
 *   @0xf45b0 add r4, r4, #64
 *   @0xf45b4 add r12, pc, r12
 *   @0xf45b8 mov r1, #512
 *   @0xf45bc add r2, pc, r2
 *   @0xf45c0 str r12, [sp]
 *   @0xf45c4 mov r3, r0
 *   @0xf45c8 mov r0, r4
 *   @0xf45cc bl 0xb65c8 <snprintf@plt>
 *   @0xf45d0 mov r0, r4
 *   @0xf45d4 b 0xf454c <_Z20Get_Event_Name_Shortii+0x58>
 *   @0xf45d8 mov r0, r1
 *   @0xf45dc add sp, sp, #8
 *   @0xf45e0 pop {r4, lr}
 *   @0xf45e4 b 0x19ed54 <_Z11Object_Namei>
 *   @0xf45e8 mov r0, r1
 *   @0xf45ec add sp, sp, #8
 *   @0xf45f0 pop {r4, lr}
 *   @0xf45f4 b 0xf348c <_Z8KeyToStri>
 *   @0xf45f8 mov r0, r1
 *   @0xf45fc add sp, sp, #8
 *   @0xf4600 pop {r4, lr}
 *   @0xf4604 b 0xf38f0 <_Z10MouseToStri>
 *   @0xf4608 cmp r1, #59
 *   @0xf460c mov r0, r1
 *   @0xf4610 bgt 0xf46b0 <_Z20Get_Event_Name_Shortii+0x1bc>
 *   @0xf4614 add sp, sp, #8
 *   @0xf4618 pop {r4, lr}
 *   @0xf461c b 0xf3cf4 <_Z10OtherToStri>
 *   @0xf4620 ldr r0, [pc, #0xb4]
 *   @0xf4624 add r0, pc, r0
 *   @0xf4628 b 0xf454c <_Z20Get_Event_Name_Shortii+0x58>
 *   @0xf462c mov r0, r1
 *   @0xf4630 ldr r4, [pc, #0xa8]
 *   @0xf4634 bl 0xf348c <_Z8KeyToStri>
 *   @0xf4638 ldr r2, [pc, #0xa4]
 *   @0xf463c add r4, pc, r4
 *   @0xf4640 ldr r3, [pc, #0xa0]
 *   @0xf4644 add r4, r4, #64
 *   @0xf4648 mov r1, #512
 *   @0xf464c add r2, pc, r2
 *   @0xf4650 add r3, pc, r3
 *   @0xf4654 str r0, [sp]
 *   @0xf4658 mov r0, r4
 *   @0xf465c bl 0xb65c8 <snprintf@plt>
 *   @0xf4660 mov r0, r4
 *   @0xf4664 b 0xf454c <_Z20Get_Event_Name_Shortii+0x58>
 *   @0xf4668 mov r0, r1
 *   @0xf466c ldr r4, [pc, #0x78]
 *   @0xf4670 bl 0xf348c <_Z8KeyToStri>
 *   @0xf4674 ldr r2, [pc, #0x74]
 *   @0xf4678 add r4, pc, r4
 *   @0xf467c ldr r3, [pc, #0x70]
 *   @0xf4680 add r4, r4, #64
 *   @0xf4684 mov r1, #512
 *   @0xf4688 add r2, pc, r2
 *   @0xf468c add r3, pc, r3
 *   @0xf4690 str r0, [sp]
 *   @0xf4694 mov r0, r4
 *   @0xf4698 bl 0xb65c8 <snprintf@plt>
 *   @0xf469c mov r0, r4
 *   @0xf46a0 b 0xf454c <_Z20Get_Event_Name_Shortii+0x58>
 *   @0xf46a4 ldr r0, [pc, #0x4c]
 *   @0xf46a8 add r0, pc, r0
 *   @0xf46ac b 0xf454c <_Z20Get_Event_Name_Shortii+0x58>
 *   @0xf46b0 add sp, sp, #8
 *   @0xf46b4 pop {r4, lr}
 *   @0xf46b8 b 0xf40bc <_Z8WebToStri>
 *   @0xf46bc eoreq r3, r4, r0, lsl #7
 *   @0xf46c0 eoreq r3, r4, r12, ror r3
 *   @0xf46c4 eoreq r3, r4, r8, ror r3
 *   @0xf46c8 eorseq lr, r8, r12, lsl #29
 *   @0xf46cc eoreq r3, r4, r8, ror #6
 *   @0xf46d0 eorseq lr, r8, r0, ror #28
 *   @0xf46d4 eoreq r3, r4, r4, asr #6
 *   @0xf46d8 eoreq r0, r4, r8, lsl r6
 *   @0xf46dc eoreq r3, r4, r0, asr #5
 *   @0xf46e0 eorseq lr, r8, r12, asr #27
 *   @0xf46e4 eoreq r0, r4, r8, lsl #11
 *   @0xf46e8 .word 0x002432b0
 *   @0xf46ec mlaseq r8, r0, sp, lr
 *   @0xf46f0 eoreq r0, r4, r12, asr #10
 *   @0xf46f4 eoreq r3, r4, r12, ror r2
 *   @0xf46f8 eoreq r3, r4, r0, lsl r1
 *
 * ══ §53/57 YYGML_show_debug_message(YYRValue const&)  0x1176a8  size 520  123 条（0x1176a8..0x1178b0）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1176a8 0x1178b0  size 520  123 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x117758→0x3eb708, 0x1177ec→0x5428e8, 0x117800→0x544c38, 0x11784c→0x3eb708
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / 0xb6538 / YYGML_show_debug_message(YYRValue const&)+0x1a4 / 0xb6568 / MemoryManager::Free(void const*) / Debug_AddTag(eTagNameType, char const*, ...) / 0xb65d4
 * 字段偏移 top8: 0xc×6 / 0x4×3 / 0x414×2 / 0x1d4×1 / 0x1d0×1 / 0x194×1 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1176a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1176ac sub sp, sp, #1040
 *   @0x1176b0 ldr r9, [pc, #0x1d4]
 *   @0x1176b4 sub sp, sp, #12
 *   @0x1176b8 ldr r3, [pc, #0x1d0]
 *   @0x1176bc mov r4, r0
 *   @0x1176c0 add r9, pc, r9
 *   @0x1176c4 ldr r2, [r0, #0xc]
 *   @0x1176c8 ldr r3, [r9, r3]
 *   @0x1176cc str r3, [sp]
 *   @0x1176d0 bic r3, r2, #-16777216
 *   @0x1176d4 ldr r1, [sp]
 *   @0x1176d8 cmp r3, #1
 *   @0x1176dc ldr r3, [r1]
 *   @0x1176e0 str r3, [sp, #0x414]
 *   @0x1176e4 movne r3, #0
 *   @0x1176e8 strne r3, [sp, #0x4]
 *   @0x1176ec beq 0x117874 <_Z24YYGML_show_debug_messageRK8YYRValue+0x1cc>
 *   @0x1176f0 cmp r2, #1
 *   @0x1176f4 beq 0x117844 <_Z24YYGML_show_debug_messageRK8YYRValue+0x19c>
 *   @0x1176f8 ldr r1, [pc, #0x194]
 *   @0x1176fc mov r12, #256
 *   @0x117700 mov r0, r12
 *   @0x117704 movw r2, #0x20e
 *   @0x117708 add r1, pc, r1
 *   @0x11770c mov r3, #1
 *   @0x117710 str r12, [sp, #0x8]
 *   @0x117714 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x117718 mov r12, #0
 *   @0x11771c mov r3, r4
 *   @0x117720 add r1, sp, #12
 *   @0x117724 mov r2, r0
 *   @0x117728 str r0, [sp, #0xc]
 *   @0x11772c str r0, [sp, #0x10]
 *   @0x117730 add r0, sp, #16
 *   @0x117734 strb r12, [r2]
 *   @0x117738 add r2, sp, #8
 *   @0x11773c bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x117740 ldr r10, [sp, #0xc]
 *   @0x117744 mov r0, r10
 *   @0x117748 bl 0xb6538 <strlen@plt>
 *   @0x11774c cmp r0, #1024
 *   @0x117750 mov r11, r0
 *   @0x117754 ble 0x11784c <_Z24YYGML_show_debug_messageRK8YYRValue+0x1a4>
 *   @0x117758 ldr r2, [pc, #0x138]
 *   @0x11775c add r6, sp, #20
 *   @0x117760 ldr r8, [pc, #0x134]
 *   @0x117764 mov r4, r10
 *   @0x117768 mov r7, #0
 *   @0x11776c ldr r2, [r9, r2]
 *   @0x117770 add r8, pc, r8
 *   @0x117774 ldr r5, [r2]
 *   @0x117778 mov r1, r4
 *   @0x11777c movw r2, #0x3ff
 *   @0x117780 mov r0, r6
 *   @0x117784 sub r11, r11, #1020
 *   @0x117788 bl 0xb6568 <strncpy@plt>
 *   @0x11778c strb r7, [sp, #0x413]
 *   @0x117790 ldr r3, [r5]
 *   @0x117794 mov r0, r5
 *   @0x117798 mov r1, r8
 *   @0x11779c mov r2, r6
 *   @0x1177a0 sub r11, r11, #3
 *   @0x1177a4 add r4, r4, #1020
 *   @0x1177a8 ldr r3, [r3, #0xc]
 *   @0x1177ac add r4, r4, #3
 *   @0x1177b0 blx r3
 *   @0x1177b4 cmp r11, #1024
 *   @0x1177b8 bge 0x117778 <_Z24YYGML_show_debug_messageRK8YYRValue+0xd0>
 *   @0x1177bc ldr r3, [r5]
 *   @0x1177c0 mov r2, r4
 *   @0x1177c4 ldr r1, [pc, #0xd4]
 *   @0x1177c8 mov r0, r5
 *   @0x1177cc add r1, pc, r1
 *   @0x1177d0 ldr r3, [r3, #0xc]
 *   @0x1177d4 blx r3
 *   @0x1177d8 ldr r1, [sp, #0x4]
 *   @0x1177dc cmp r10, r1
 *   @0x1177e0 beq 0x1177ec <_Z24YYGML_show_debug_messageRK8YYRValue+0x144>
 *   @0x117800 ldr r3, [pc, #0xa0]
 *   @0x117804 ldr r3, [r9, r3]
 *   @0x117808 ldr r3, [r3]
 *   @0x11780c cmp r3, #0
 *   @0x117810 beq 0x117834 <_Z24YYGML_show_debug_messageRK8YYRValue+0x18c>
 *   @0x117814 ldr r1, [sp]
 *   @0x117818 ldr r2, [sp, #0x414]
 *   @0x11781c ldr r3, [r1]
 *   @0x117820 cmp r2, r3
 *   @0x117824 bne 0x117888 <_Z24YYGML_show_debug_messageRK8YYRValue+0x1e0>
 *   @0x117828 add sp, sp, #1040
 *   @0x11782c add sp, sp, #12
 *   @0x117830 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x117834 mov r1, r10
 *   @0x117838 mov r0, #1
 *   @0x11783c bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz>
 *   @0x117840 b 0x117814 <_Z24YYGML_show_debug_messageRK8YYRValue+0x16c>
 *   @0x117844 ldr r10, [sp, #0x4]
 *   @0x117848 b 0x117744 <_Z24YYGML_show_debug_messageRK8YYRValue+0x9c>
 *   @0x11784c ldr r3, [pc, #0x44]
 *   @0x117850 mov r2, r10
 *   @0x117854 ldr r1, [pc, #0x50]
 *   @0x117858 ldr r3, [r9, r3]
 *   @0x11785c add r1, pc, r1
 *   @0x117860 ldr r0, [r3]
 *   @0x117864 ldr r3, [r0]
 *   @0x117868 ldr r3, [r3, #0xc]
 *   @0x11786c blx r3
 *   @0x117870 b 0x1177d8 <_Z24YYGML_show_debug_messageRK8YYRValue+0x130>
 *   @0x117874 ldr r11, [r0]
 *   @0x117878 cmp r11, #0
 *   @0x11787c ldrne r11, [r11]
 *   @0x117880 str r11, [sp, #0x4]
 *   @0x117884 b 0x1176f0 <_Z24YYGML_show_debug_messageRK8YYRValue+0x48>
 *   @0x117888 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x11788c mlaeq sp, r0, r5, r10
 *   @0x117890 .word 0xffffbd00
 *   @0x117894 .word 0x002220f0
 *   @0x117898 .word 0xffffbcf0
 *   @0x11789c mlaeq r1, r8, r3, sp
 *   @0x1178a0 .word 0x0021d4d8
 *   @0x1178a4 .word 0xffffbcd4
 *   @0x1178a8 .word 0xffffc7d0
 *   @0x1178ac eoreq sp, r1, r8, asr #8
 *
 * ══ §54/57 Eff_Effect01(int, float, float, int, unsigned int)  0x1a0614  size 520  130 条（0x1a0614..0x1a081c）
 * @func 0x1a0614 0x1a081c  size 520  130 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a0640→0x54241c
 * 调用序列: 0xb66e8×6 / ParticleType_Shape(int, int)×3 / ParticleType_Alpha2(int, float, float)×3 / ParticleType_Size(int, float, float, float, float)×3 / ParticleType_Life(int, int, int)×3 / Speed_Factor() / ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)
 * 字段偏移 top8: 0x4×6 / 0x8×5 / 0x1d4×1 / 0x1d0×1 / 0x30×1
 * VFP 指令 36 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a0614 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a0618 vpush {d8}
 *   @0x1a061c sub sp, sp, #12
 *   @0x1a0620 mov r4, r3
 *   @0x1a0624 mov r7, r1
 *   @0x1a0628 mov r8, r0
 *   @0x1a062c mov r6, r2
 *   @0x1a0630 bl 0x19ff6c <_Z12Speed_Factorv>
 *   @0x1a0634 cmp r4, #0
 *   @0x1a0638 ldr r12, [pc, #0x1d4]
 *   @0x1a063c mov r1, #6
 *   @0x1a0640 ldr r3, [pc, #0x1d0]
 *   @0x1a0644 mov r5, #0
 *   @0x1a0648 add r12, pc, r12
 *   @0x1a064c vmov s16, r0
 *   @0x1a0650 beq 0x1a0708 <_Z12Eff_Effect01iffij+0xf4>
 *   @0x1a0654 cmp r4, #2
 *   @0x1a0658 ldr r4, [r12, r3]
 *   @0x1a065c beq 0x1a078c <_Z12Eff_Effect01iffij+0x178>
 *   @0x1a0660 ldr r0, [r4, #0x4]
 *   @0x1a0664 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0668 mov r2, r5
 *   @0x1a066c ldr r0, [r4, #0x4]
 *   @0x1a0670 mov r1, #1065353216
 *   @0x1a0674 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a0678 vmov.f32 s15, #2.500000e-01
 *   @0x1a067c mov r2, r5
 *   @0x1a0680 mov r1, r5
 *   @0x1a0684 ldr r0, [r4, #0x4]
 *   @0x1a0688 str r5, [sp]
 *   @0x1a068c vmul.f32 s15, s16, s15
 *   @0x1a0690 vmov r3, s15
 *   @0x1a0694 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a0698 vmov.f32 s15, #1.300000e+01
 *   @0x1a069c ldr r9, [r4, #0x4]
 *   @0x1a06a0 vdiv.f32 s15, s15, s16
 *   @0x1a06a4 vcvt.f64.f32 d6, s15
 *   @0x1a06a8 vmov r0, r1, d6
 *   @0x1a06ac bl 0xb66e8 <lrint@plt>
 *   @0x1a06b0 vmov.f32 s15, #1.500000e+01
 *   @0x1a06b4 vdiv.f32 s16, s15, s16
 *   @0x1a06b8 mov r5, r0
 *   @0x1a06bc vcvt.f64.f32 d7, s16
 *   @0x1a06c0 vmov r0, r1, d7
 *   @0x1a06c4 bl 0xb66e8 <lrint@plt>
 *   @0x1a06c8 mov r1, r5
 *   @0x1a06cc mov r2, r0
 *   @0x1a06d0 mov r0, r9
 *   @0x1a06d4 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a06d8 ldr r3, [r4, #0x4]
 *   @0x1a06dc ldr r2, [sp, #0x30]
 *   @0x1a06e0 mov r12, #1
 *   @0x1a06e4 mov r0, r8
 *   @0x1a06e8 mov r1, r7
 *   @0x1a06ec str r12, [sp, #0x4]
 *   @0x1a06f0 str r2, [sp]
 *   @0x1a06f4 mov r2, r6
 *   @0x1a06f8 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a06fc add sp, sp, #12
 *   @0x1a0700 vpop {d8}
 *   @0x1a0704 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a0708 ldr r4, [r12, r3]
 *   @0x1a070c ldr r0, [r4]
 *   @0x1a0710 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0714 mov r2, r5
 *   @0x1a0718 ldr r0, [r4]
 *   @0x1a071c mov r1, #1065353216
 *   @0x1a0720 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a0724 vldr s15, [pc, #224]
 *   @0x1a0728 vmul.f32 s15, s16, s15
 *   @0x1a072c mov r2, r5
 *   @0x1a0730 mov r1, r5
 *   @0x1a0734 ldr r0, [r4]
 *   @0x1a0738 str r5, [sp]
 *   @0x1a073c vmov r3, s15
 *   @0x1a0740 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a0744 vmov.f32 s15, #1.000000e+01
 *   @0x1a0748 ldr r9, [r4]
 *   @0x1a074c vdiv.f32 s15, s15, s16
 *   @0x1a0750 vcvt.f64.f32 d6, s15
 *   @0x1a0754 vmov r0, r1, d6
 *   @0x1a0758 bl 0xb66e8 <lrint@plt>
 *   @0x1a075c vmov.f32 s15, #1.200000e+01
 *   @0x1a0760 vdiv.f32 s16, s15, s16
 *   @0x1a0764 mov r5, r0
 *   @0x1a0768 vcvt.f64.f32 d7, s16
 *   @0x1a076c vmov r0, r1, d7
 *   @0x1a0770 bl 0xb66e8 <lrint@plt>
 *   @0x1a0774 mov r1, r5
 *   @0x1a0778 mov r2, r0
 *   @0x1a077c mov r0, r9
 *   @0x1a0780 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a0784 ldr r3, [r4]
 *   @0x1a0788 b 0x1a06dc <_Z12Eff_Effect01iffij+0xc8>
 *   @0x1a078c ldr r0, [r4, #0x8]
 *   @0x1a0790 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0794 mov r2, r5
 *   @0x1a0798 ldr r0, [r4, #0x8]
 *   @0x1a079c mov r1, #1065353216
 *   @0x1a07a0 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a07a4 vldr s15, [pc, #100]
 *   @0x1a07a8 vmul.f32 s15, s16, s15
 *   @0x1a07ac mov r2, r5
 *   @0x1a07b0 mov r1, r5
 *   @0x1a07b4 ldr r0, [r4, #0x8]
 *   @0x1a07b8 str r5, [sp]
 *   @0x1a07bc vmov r3, s15
 *   @0x1a07c0 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a07c4 vmov.f32 s15, #1.800000e+01
 *   @0x1a07c8 ldr r9, [r4, #0x8]
 *   @0x1a07cc vdiv.f32 s15, s15, s16
 *   @0x1a07d0 vcvt.f64.f32 d6, s15
 *   @0x1a07d4 vmov r0, r1, d6
 *   @0x1a07d8 bl 0xb66e8 <lrint@plt>
 *   @0x1a07dc vmov.f32 s15, #2.000000e+01
 *   @0x1a07e0 vdiv.f32 s16, s15, s16
 *   @0x1a07e4 mov r5, r0
 *   @0x1a07e8 vcvt.f64.f32 d7, s16
 *   @0x1a07ec vmov r0, r1, d7
 *   @0x1a07f0 bl 0xb66e8 <lrint@plt>
 *   @0x1a07f4 mov r1, r5
 *   @0x1a07f8 mov r2, r0
 *   @0x1a07fc mov r0, r9
 *   @0x1a0800 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a0804 ldr r3, [r4, #0x8]
 *   @0x1a0808 b 0x1a06dc <_Z12Eff_Effect01iffij+0xc8>
 *   @0x1a080c mrclo p9, #0x0, r9, c9, c10, #0x4
 *   @0x1a0810 cdplo p12, #0xc, c12, c12, c13, #0x6
 *   @0x1a0814 eoreq r1, r5, r8, lsl #12
 *   @0x1a0818 .word 0xffffeb24
 *
 * ══ §55/57 JS_String_prototype_toLowerCase(RValue&, CInstance*, CInstance*, int, RValue*)  0x255a24  size 520  130 条（0x255a24..0x255c2c）
 * @func 0x255a24 0x255c2c  size 520  130 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCodepointIterator_UTF8::GetNext()×2 / JS_CheckObjectCoercible(RValue&) / F_JS_ToString(RValue&, RValue*) / CCodepointIterator_UTF8::CCodepointIterator_UTF8(char const*) / 0xb6538 / 0xb65b0 / utf8_tolower(int) / JS_String_prototype_toLowerCase(RValue&, CInstance*, CInstance*, int, RValue*)+0xc0
 * 字段偏移 top8: 0x-58×2 / 0x-28×2 / 0x-38×2 / 0x-5c×2 / 0x1×2 / 0x1f0×1 / 0x-3c×1 / 0x-24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x255a24 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x255a28 add r11, sp, #32
 *   @0x255a2c ldr r7, [pc, #0x1f0]
 *   @0x255a30 sub sp, sp, #60
 *   @0x255a34 sub r4, r11, #36
 *   @0x255a38 ldr r7, [pc, r7]
 *   @0x255a3c mov r3, #6
 *   @0x255a40 str r3, [r11, #-0x3c]
 *   @0x255a44 ldr r3, [r7]
 *   @0x255a48 str r0, [r11, #-0x58]
 *   @0x255a4c str r1, [r4, #-0x24]!
 *   @0x255a50 mov r0, r4
 *   @0x255a54 str r3, [r11, #-0x28]
 *   @0x255a58 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x255a5c cmp r0, #1
 *   @0x255a60 beq 0x255c10 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0x1ec>
 *   @0x255a64 mov r1, r4
 *   @0x255a68 sub r0, r11, #56
 *   @0x255a6c mov r5, #0
 *   @0x255a70 mvn r3, #-16777216
 *   @0x255a74 str r5, [r11, #-0x38]
 *   @0x255a78 sub r6, r11, #84
 *   @0x255a7c str r5, [r11, #-0x34]
 *   @0x255a80 movw r10, #0xfffe
 *   @0x255a84 str r5, [r11, #-0x30]
 *   @0x255a88 mov r4, r5
 *   @0x255a8c str r3, [r11, #-0x2c]
 *   @0x255a90 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x255a94 ldr r3, [r11, #-0x38]
 *   @0x255a98 mov r0, r6
 *   @0x255a9c movt r10, #0x1f
 *   @0x255aa0 movw r8, #0x7fe
 *   @0x255aa4 movw r9, #0xfffe
 *   @0x255aa8 ldr r3, [r3]
 *   @0x255aac mov r1, r3
 *   @0x255ab0 str r3, [r11, #-0x5c]
 *   @0x255ab4 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x255ab8 ldr r3, [r11, #-0x5c]
 *   @0x255abc mov r0, r3
 *   @0x255ac0 bl 0xb6538 <strlen@plt>
 *   @0x255ac4 mov r1, r5
 *   @0x255ac8 lsl r2, r0, #2
 *   @0x255acc add r3, r2, #14
 *   @0x255ad0 bic r3, r3, #7
 *   @0x255ad4 sub sp, sp, r3
 *   @0x255ad8 mov r0, sp
 *   @0x255adc mov r5, sp
 *   @0x255ae0 bl 0xb65b0 <memset@plt>
 *   @0x255ae4 mov r0, r6
 *   @0x255ae8 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x255aec cmp r0, #0
 *   @0x255af0 beq 0x255b48 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x255af4 bl 0x23f8b8 <_Z12utf8_toloweri>
 *   @0x255af8 cmp r0, #126
 *   @0x255afc strble r0, [r5, r4]
 *   @0x255b00 addle r4, r4, #1
 *   @0x255b04 ble 0x255ae4 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x255b08 cmp r0, r8
 *   @0x255b0c bgt 0x255b6c <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x255b10 ubfx r3, r0, #0x6, #0x5
 *   @0x255b14 and r0, r0, #63
 *   @0x255b18 add r2, r4, #1
 *   @0x255b1c mvn r3, r3, lsl #26
 *   @0x255b20 mvn r0, r0, lsl #25
 *   @0x255b24 mvn r3, r3, lsr #26
 *   @0x255b28 mvn r0, r0, lsr #25
 *   @0x255b2c strb r3, [r5, r4]
 *   @0x255b30 add r4, r4, #2
 *   @0x255b34 strb r0, [r5, r2]
 *   @0x255b38 mov r0, r6
 *   @0x255b3c bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x255b40 cmp r0, #0
 *   @0x255b44 bne 0x255af4 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x255b48 ldr r0, [r11, #-0x58]
 *   @0x255b4c mov r1, r5
 *   @0x255b50 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x255b54 ldr r2, [r11, #-0x28]
 *   @0x255b58 ldr r3, [r7]
 *   @0x255b5c cmp r2, r3
 *   @0x255b60 bne 0x255c20 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x255b64 sub sp, r11, #32
 *   @0x255b68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x255b6c cmp r0, r9
 *   @0x255b70 bgt 0x255bb4 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x255b74 ubfx r1, r0, #0xc, #0x4
 *   @0x255b78 ubfx r2, r0, #0x6, #0x6
 *   @0x255b7c and r0, r0, #63
 *   @0x255b80 add r12, r4, #2
 *   @0x255b84 mov r3, r5
 *   @0x255b88 mvn r1, r1, lsl #27
 *   @0x255b8c mvn r2, r2, lsl #25
 *   @0x255b90 mvn r0, r0, lsl #25
 *   @0x255b94 mvn r1, r1, lsr #27
 *   @0x255b98 mvn r2, r2, lsr #25
 *   @0x255b9c strb r1, [r3, r4]!
 *   @0x255ba0 mvn r0, r0, lsr #25
 *   @0x255ba4 strb r2, [r3, #0x1]
 *   @0x255ba8 add r4, r4, #3
 *   @0x255bac strb r0, [r5, r12]
 *   @0x255bb0 b 0x255ae4 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x255bb4 cmp r0, r10
 *   @0x255bb8 bgt 0x255ae4 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x255bbc and lr, r0, #3670016
 *   @0x255bc0 ubfx r12, r0, #0xc, #0x6
 *   @0x255bc4 ubfx r1, r0, #0x6, #0x6
 *   @0x255bc8 and r0, r0, #63
 *   @0x255bcc asr lr, lr, #18
 *   @0x255bd0 add r2, r4, #3
 *   @0x255bd4 mov r3, r5
 *   @0x255bd8 mvn r12, r12, lsl #25
 *   @0x255bdc mvn lr, lr, lsl #28
 *   @0x255be0 mvn r1, r1, lsl #25
 *   @0x255be4 mvn r0, r0, lsl #25
 *   @0x255be8 mvn lr, lr, lsr #28
 *   @0x255bec mvn r12, r12, lsr #25
 *   @0x255bf0 strb lr, [r3, r4]!
 *   @0x255bf4 mvn r1, r1, lsr #25
 *   @0x255bf8 strb r12, [r3, #0x1]
 *   @0x255bfc strb r1, [r3, #0x2]
 *   @0x255c00 mvn r0, r0, lsr #25
 *   @0x255c04 add r4, r4, #4
 *   @0x255c08 strb r0, [r5, r2]
 *   @0x255c0c b 0x255ae4 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x255c10 ldr r0, [pc, #0x10]
 *   @0x255c14 add r0, pc, r0
 *   @0x255c18 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x255c1c b 0x255b54 <_Z31JS_String_prototype_toLowerCaseR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x255c20 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x255c24 andseq r7, r9, r8, lsl pc
 *   @0x255c28 andseq r0, r0, r4, lsr r3
 *
 * ══ §56/57 JS_String_prototype_toUpperCase(RValue&, CInstance*, CInstance*, int, RValue*)  0x255c2c  size 520  130 条（0x255c2c..0x255e34）
 * @func 0x255c2c 0x255e34  size 520  130 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCodepointIterator_UTF8::GetNext()×2 / JS_CheckObjectCoercible(RValue&) / F_JS_ToString(RValue&, RValue*) / CCodepointIterator_UTF8::CCodepointIterator_UTF8(char const*) / 0xb6538 / 0xb65b0 / utf8_toupper(int) / JS_String_prototype_toUpperCase(RValue&, CInstance*, CInstance*, int, RValue*)+0xc0
 * 字段偏移 top8: 0x-58×2 / 0x-28×2 / 0x-38×2 / 0x-5c×2 / 0x1×2 / 0x1f0×1 / 0x-3c×1 / 0x-24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x255c2c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x255c30 add r11, sp, #32
 *   @0x255c34 ldr r7, [pc, #0x1f0]
 *   @0x255c38 sub sp, sp, #60
 *   @0x255c3c sub r4, r11, #36
 *   @0x255c40 ldr r7, [pc, r7]
 *   @0x255c44 mov r3, #6
 *   @0x255c48 str r3, [r11, #-0x3c]
 *   @0x255c4c ldr r3, [r7]
 *   @0x255c50 str r0, [r11, #-0x58]
 *   @0x255c54 str r1, [r4, #-0x24]!
 *   @0x255c58 mov r0, r4
 *   @0x255c5c str r3, [r11, #-0x28]
 *   @0x255c60 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x255c64 cmp r0, #1
 *   @0x255c68 beq 0x255e18 <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0x1ec>
 *   @0x255c6c mov r1, r4
 *   @0x255c70 sub r0, r11, #56
 *   @0x255c74 mov r5, #0
 *   @0x255c78 mvn r3, #-16777216
 *   @0x255c7c str r5, [r11, #-0x38]
 *   @0x255c80 sub r6, r11, #84
 *   @0x255c84 str r5, [r11, #-0x34]
 *   @0x255c88 movw r10, #0xfffe
 *   @0x255c8c str r5, [r11, #-0x30]
 *   @0x255c90 mov r4, r5
 *   @0x255c94 str r3, [r11, #-0x2c]
 *   @0x255c98 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x255c9c ldr r3, [r11, #-0x38]
 *   @0x255ca0 mov r0, r6
 *   @0x255ca4 movt r10, #0x1f
 *   @0x255ca8 movw r8, #0x7fe
 *   @0x255cac movw r9, #0xfffe
 *   @0x255cb0 ldr r3, [r3]
 *   @0x255cb4 mov r1, r3
 *   @0x255cb8 str r3, [r11, #-0x5c]
 *   @0x255cbc bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x255cc0 ldr r3, [r11, #-0x5c]
 *   @0x255cc4 mov r0, r3
 *   @0x255cc8 bl 0xb6538 <strlen@plt>
 *   @0x255ccc mov r1, r5
 *   @0x255cd0 lsl r2, r0, #2
 *   @0x255cd4 add r3, r2, #14
 *   @0x255cd8 bic r3, r3, #7
 *   @0x255cdc sub sp, sp, r3
 *   @0x255ce0 mov r0, sp
 *   @0x255ce4 mov r5, sp
 *   @0x255ce8 bl 0xb65b0 <memset@plt>
 *   @0x255cec mov r0, r6
 *   @0x255cf0 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x255cf4 cmp r0, #0
 *   @0x255cf8 beq 0x255d50 <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x255cfc bl 0x23f8d4 <_Z12utf8_toupperi>
 *   @0x255d00 cmp r0, #126
 *   @0x255d04 strble r0, [r5, r4]
 *   @0x255d08 addle r4, r4, #1
 *   @0x255d0c ble 0x255cec <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x255d10 cmp r0, r8
 *   @0x255d14 bgt 0x255d74 <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x255d18 ubfx r3, r0, #0x6, #0x5
 *   @0x255d1c and r0, r0, #63
 *   @0x255d20 add r2, r4, #1
 *   @0x255d24 mvn r3, r3, lsl #26
 *   @0x255d28 mvn r0, r0, lsl #25
 *   @0x255d2c mvn r3, r3, lsr #26
 *   @0x255d30 mvn r0, r0, lsr #25
 *   @0x255d34 strb r3, [r5, r4]
 *   @0x255d38 add r4, r4, #2
 *   @0x255d3c strb r0, [r5, r2]
 *   @0x255d40 mov r0, r6
 *   @0x255d44 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x255d48 cmp r0, #0
 *   @0x255d4c bne 0x255cfc <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x255d50 ldr r0, [r11, #-0x58]
 *   @0x255d54 mov r1, r5
 *   @0x255d58 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x255d5c ldr r2, [r11, #-0x28]
 *   @0x255d60 ldr r3, [r7]
 *   @0x255d64 cmp r2, r3
 *   @0x255d68 bne 0x255e28 <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x255d6c sub sp, r11, #32
 *   @0x255d70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x255d74 cmp r0, r9
 *   @0x255d78 bgt 0x255dbc <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x255d7c ubfx r1, r0, #0xc, #0x4
 *   @0x255d80 ubfx r2, r0, #0x6, #0x6
 *   @0x255d84 and r0, r0, #63
 *   @0x255d88 add r12, r4, #2
 *   @0x255d8c mov r3, r5
 *   @0x255d90 mvn r1, r1, lsl #27
 *   @0x255d94 mvn r2, r2, lsl #25
 *   @0x255d98 mvn r0, r0, lsl #25
 *   @0x255d9c mvn r1, r1, lsr #27
 *   @0x255da0 mvn r2, r2, lsr #25
 *   @0x255da4 strb r1, [r3, r4]!
 *   @0x255da8 mvn r0, r0, lsr #25
 *   @0x255dac strb r2, [r3, #0x1]
 *   @0x255db0 add r4, r4, #3
 *   @0x255db4 strb r0, [r5, r12]
 *   @0x255db8 b 0x255cec <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x255dbc cmp r0, r10
 *   @0x255dc0 bgt 0x255cec <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x255dc4 and lr, r0, #3670016
 *   @0x255dc8 ubfx r12, r0, #0xc, #0x6
 *   @0x255dcc ubfx r1, r0, #0x6, #0x6
 *   @0x255dd0 and r0, r0, #63
 *   @0x255dd4 asr lr, lr, #18
 *   @0x255dd8 add r2, r4, #3
 *   @0x255ddc mov r3, r5
 *   @0x255de0 mvn r12, r12, lsl #25
 *   @0x255de4 mvn lr, lr, lsl #28
 *   @0x255de8 mvn r1, r1, lsl #25
 *   @0x255dec mvn r0, r0, lsl #25
 *   @0x255df0 mvn lr, lr, lsr #28
 *   @0x255df4 mvn r12, r12, lsr #25
 *   @0x255df8 strb lr, [r3, r4]!
 *   @0x255dfc mvn r1, r1, lsr #25
 *   @0x255e00 strb r12, [r3, #0x1]
 *   @0x255e04 strb r1, [r3, #0x2]
 *   @0x255e08 mvn r0, r0, lsr #25
 *   @0x255e0c add r4, r4, #4
 *   @0x255e10 strb r0, [r5, r2]
 *   @0x255e14 b 0x255cec <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x255e18 ldr r0, [pc, #0x10]
 *   @0x255e1c add r0, pc, r0
 *   @0x255e20 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x255e24 b 0x255d5c <_Z31JS_String_prototype_toUpperCaseR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x255e28 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x255e2c andseq r7, r9, r0, lsl sp
 *   @0x255e30 andseq r0, r0, r12, lsr #2
 *
 * ══ §57/57 YYGML_sins(double)  0x110ff0  size 64  14 条（0x110ff0..0x111030）
 * @func 0x110ff0 0x111030  size 64  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb67d8
 * 字段偏移 top8: 无
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110ff0 push {r3, lr}
 *   @0x110ff4 bl 0xb67d8 <sin@plt>
 *   @0x110ff8 vldr d5, [pc, #32]
 *   @0x110ffc vldr d6, [pc, #36]
 *   @0x111000 vmov d7, r0, r1
 *   @0x111004 vabs.f64 d4, d7
 *   @0x111008 vcmpe.f64 d4, d5
 *   @0x11100c vmrs APSR_nzcv, fpscr
 *   @0x111010 vmovpl r0, r1, d7
 *   @0x111014 vmovmi r0, r1, d6
 *   @0x111018 pop {r3, pc}
 *   @0x11101c nop
 *   @0x111020 andhi r0, r0, r0
 *   @0x111024 mcrlo p8, #0x7, pc, c4, c5, #0x5
 */
