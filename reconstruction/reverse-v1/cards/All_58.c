/* cally 逆向卡：All_58 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 197 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/197 F_Texture_Get_Texel_Width(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e0e58  size 160  40 条（0x1e0e58..0x1e0ef8）
 * @func 0x1e0e58 0x1e0ef8  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int)×2 / YYGetPtrOrInt(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x54×1 / 0x4×1 / 0x2×1 / 0x28×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0e58 push {r4, r5, r6, lr}
 *   @0x1e0e5c mov r1, #0
 *   @0x1e0e60 mov r3, r1
 *   @0x1e0e64 str r1, [r0, #0xc]
 *   @0x1e0e68 movt r3, #0x3ff0
 *   @0x1e0e6c mov r4, r0
 *   @0x1e0e70 stm r0, {r1, r3}
 *   @0x1e0e74 ldr r0, [sp, #0x10]
 *   @0x1e0e78 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x1e0e7c cmn r0, #1
 *   @0x1e0e80 mov r5, r0
 *   @0x1e0e84 popeq {r4, r5, r6, pc}
 *   @0x1e0e88 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x1e0e8c cmp r0, #0
 *   @0x1e0e90 beq 0x1e0ec4 <_Z25F_Texture_Get_Texel_WidthR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1e0e94 ldr r6, [pc, #0x54]
 *   @0x1e0e98 ldr r6, [pc, r6]
 *   @0x1e0e9c ldr r3, [r6, #0x4]
 *   @0x1e0ea0 vmov.f64 d6, #1.000000e+00
 *   @0x1e0ea4 ldr r3, [r3, r5, lsl #2]
 *   @0x1e0ea8 ldr r3, [r3]
 *   @0x1e0eac vldr s14, [r3, #4]
 *   @0x1e0eb0 vcvt.f64.s32 d7, s14
 *   @0x1e0eb4 vdiv.f64 d5, d6, d7
 *   @0x1e0eb8 vmov r2, r3, d5
 *   @0x1e0ebc stm r4, {r2, r3}
 *   @0x1e0ec0 pop {r4, r5, r6, pc}
 *   @0x1e0ec4 ldr r6, [pc, #0x28]
 *   @0x1e0ec8 ldr r6, [pc, r6]
 *   @0x1e0ecc ldr r3, [r6]
 *   @0x1e0ed0 cmp r5, r3
 *   @0x1e0ed4 poplo {r4, r5, r6, pc}
 *   @0x1e0ed8 ldrsh r5, [r5, #20]
 *   @0x1e0edc mov r0, r5
 *   @0x1e0ee0 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x1e0ee4 cmp r0, #0
 *   @0x1e0ee8 bne 0x1e0e9c <_Z25F_Texture_Get_Texel_WidthR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1e0eec pop {r4, r5, r6, pc}
 *   @0x1e0ef0 eoreq r12, r0, r4, lsl #21
 *   @0x1e0ef4 eoreq r12, r0, r4, asr r10
 *
 * ══ §2/197 F_Texture_Get_Texel_Height(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e0ef8  size 160  40 条（0x1e0ef8..0x1e0f98）
 * @func 0x1e0ef8 0x1e0f98  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int)×2 / YYGetPtrOrInt(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x54×1 / 0x4×1 / 0x2×1 / 0x28×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0ef8 push {r4, r5, r6, lr}
 *   @0x1e0efc mov r1, #0
 *   @0x1e0f00 mov r3, r1
 *   @0x1e0f04 str r1, [r0, #0xc]
 *   @0x1e0f08 movt r3, #0x3ff0
 *   @0x1e0f0c mov r4, r0
 *   @0x1e0f10 stm r0, {r1, r3}
 *   @0x1e0f14 ldr r0, [sp, #0x10]
 *   @0x1e0f18 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x1e0f1c cmn r0, #1
 *   @0x1e0f20 mov r5, r0
 *   @0x1e0f24 popeq {r4, r5, r6, pc}
 *   @0x1e0f28 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x1e0f2c cmp r0, #0
 *   @0x1e0f30 beq 0x1e0f64 <_Z26F_Texture_Get_Texel_HeightR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1e0f34 ldr r6, [pc, #0x54]
 *   @0x1e0f38 ldr r6, [pc, r6]
 *   @0x1e0f3c ldr r3, [r6, #0x4]
 *   @0x1e0f40 vmov.f64 d6, #1.000000e+00
 *   @0x1e0f44 ldr r3, [r3, r5, lsl #2]
 *   @0x1e0f48 ldr r3, [r3]
 *   @0x1e0f4c vldr s14, [r3, #8]
 *   @0x1e0f50 vcvt.f64.s32 d7, s14
 *   @0x1e0f54 vdiv.f64 d5, d6, d7
 *   @0x1e0f58 vmov r2, r3, d5
 *   @0x1e0f5c stm r4, {r2, r3}
 *   @0x1e0f60 pop {r4, r5, r6, pc}
 *   @0x1e0f64 ldr r6, [pc, #0x28]
 *   @0x1e0f68 ldr r6, [pc, r6]
 *   @0x1e0f6c ldr r3, [r6]
 *   @0x1e0f70 cmp r5, r3
 *   @0x1e0f74 poplo {r4, r5, r6, pc}
 *   @0x1e0f78 ldrsh r5, [r5, #20]
 *   @0x1e0f7c mov r0, r5
 *   @0x1e0f80 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x1e0f84 cmp r0, #0
 *   @0x1e0f88 bne 0x1e0f3c <_Z26F_Texture_Get_Texel_HeightR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1e0f8c pop {r4, r5, r6, pc}
 *   @0x1e0f90 eoreq r12, r0, r4, ror #19
 *   @0x1e0f94 .word 0x0020c9b4
 *
 * ══ §3/197 F_VertexFormat_Begin(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e2bb0  size 160  40 条（0x1e2bb0..0x1e2c50）
 * @func 0x1e2bb0 0x1e2c50  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)
 * 字段偏移 top8: 0xc×2 / 0x68×1 / 0x58×1 / 0x4c×1 / 0x34×1 / 0x4×1 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2bb0 subs r1, r3, #0
 *   @0x1e2bb4 mov r12, #0
 *   @0x1e2bb8 mov r2, r12
 *   @0x1e2bbc movt r12, #0xbff0
 *   @0x1e2bc0 push {r3, r4, r5, lr}
 *   @0x1e2bc4 str r2, [r0, #0xc]
 *   @0x1e2bc8 stm r0, {r2, r12}
 *   @0x1e2bcc bne 0x1e2bf4 <_Z20F_VertexFormat_BeginR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1e2bd0 ldr r4, [pc, #0x68]
 *   @0x1e2bd4 ldr r4, [pc, r4]
 *   @0x1e2bd8 ldr r5, [r4]
 *   @0x1e2bdc cmp r5, #0
 *   @0x1e2be0 beq 0x1e2c08 <_Z20F_VertexFormat_BeginR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x1e2be4 ldr r0, [pc, #0x58]
 *   @0x1e2be8 pop {r3, r4, r5, lr}
 *   @0x1e2bec add r0, pc, r0
 *   @0x1e2bf0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2bf4 ldr r0, [pc, #0x4c]
 *   @0x1e2bf8 mov r1, r2
 *   @0x1e2bfc pop {r3, r4, r5, lr}
 *   @0x1e2c00 add r0, pc, r0
 *   @0x1e2c04 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2c08 mov r0, #28
 *   @0x1e2c0c bl 0x27c524 <_Znwj>
 *   @0x1e2c10 ldr r3, [pc, #0x34]
 *   @0x1e2c14 mov r2, #1
 *   @0x1e2c18 ldr r3, [pc, r3]
 *   @0x1e2c1c str r5, [r0]
 *   @0x1e2c20 str r5, [r0, #0x4]
 *   @0x1e2c24 str r5, [r0, #0x8]
 *   @0x1e2c28 str r5, [r0, #0xc]
 *   @0x1e2c2c str r5, [r0, #0x10]
 *   @0x1e2c30 str r5, [r0, #0x18]
 *   @0x1e2c34 str r0, [r4]
 *   @0x1e2c38 str r2, [r3]
 *   @0x1e2c3c pop {r3, r4, r5, pc}
 *   @0x1e2c40 .word 0x0020e1bc
 *   @0x1e2c44 andseq pc, r6, r4, lsl #13
 *   @0x1e2c48 andseq pc, r6, r0, asr #12
 *   @0x1e2c4c eoreq lr, r0, r12, ror r1
 *
 * ══ §4/197 FreeRange(CVariableList&, RVariable**, RVariable**)  0x1f69f4  size 160  40 条（0x1f69f4..0x1f6a94）
 * @func 0x1f69f4 0x1f6a94  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CVariableList::Free(RVariable*, RVariable**, RVariable**)
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f69f4 push {r4, r5, r6, r7, r8, lr}
 *   @0x1f69f8 adds r4, r0, #4
 *   @0x1f69fc mov r7, r1
 *   @0x1f6a00 mov r8, r2
 *   @0x1f6a04 addne r4, r0, #20
 *   @0x1f6a08 beq 0x1f6a70 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x7c>
 *   @0x1f6a0c cmp r4, r0
 *   @0x1f6a10 add r6, r0, #4
 *   @0x1f6a14 beq 0x1f6a20 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x2c>
 *   @0x1f6a18 cmp r4, r6
 *   @0x1f6a1c bne 0x1f6a7c <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x88>
 *   @0x1f6a20 mov r6, r4
 *   @0x1f6a24 mov r5, #0
 *   @0x1f6a28 cmp r5, #0
 *   @0x1f6a2c beq 0x1f6a6c <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x78>
 *   @0x1f6a30 mov r0, r5
 *   @0x1f6a34 mov r1, r7
 *   @0x1f6a38 mov r2, r8
 *   @0x1f6a3c bl 0x1f67ac <_ZN13CVariableList4FreeEP9RVariablePS1_S2_>
 *   @0x1f6a40 ldr r5, [r5]
 *   @0x1f6a44 cmp r5, #0
 *   @0x1f6a48 add r3, r6, #4
 *   @0x1f6a4c bne 0x1f6a28 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x34>
 *   @0x1f6a50 cmp r4, r6
 *   @0x1f6a54 beq 0x1f6a90 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x9c>
 *   @0x1f6a58 cmp r3, r4
 *   @0x1f6a5c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1f6a60 ldr r5, [r6, #0x4]
 *   @0x1f6a64 mov r6, r3
 *   @0x1f6a68 b 0x1f6a44 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x50>
 *   @0x1f6a6c pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f6a70 mov r6, r4
 *   @0x1f6a74 mov r5, r4
 *   @0x1f6a78 b 0x1f6a28 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x34>
 *   @0x1f6a7c ldr r5, [r0, #0x4]
 *   @0x1f6a80 cmp r5, #0
 *   @0x1f6a84 bne 0x1f6a28 <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x34>
 *   @0x1f6a88 mov r0, r6
 *   @0x1f6a8c b 0x1f6a0c <_Z9FreeRangeR13CVariableListPP9RVariableS3_+0x18>
 *   @0x1f6a90 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §5/197 GV_InstanceId(CInstance*, int, RValue*)  0x1fb0a8  size 160  40 条（0x1fb0a8..0x1fb148）
 * @func 0x1fb0a8 0x1fb148  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_InstanceId(CInstance*, int, RValue*)+0x70
 * 字段偏移 top8: 0x178×2 / 0xc×1 / 0x4×1 / 0x74×1 / 0x88×1 / 0x80×1 / 0x78×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb0a8 cmp r1, #0
 *   @0x1fb0ac mov r0, #0
 *   @0x1fb0b0 mov r3, r0
 *   @0x1fb0b4 movt r0, #0xc010
 *   @0x1fb0b8 str r3, [r2, #0xc]
 *   @0x1fb0bc str r0, [r2, #0x4]
 *   @0x1fb0c0 str r3, [r2]
 *   @0x1fb0c4 blt 0x1fb118 <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x70>
 *   @0x1fb0c8 ldr r3, [pc, #0x74]
 *   @0x1fb0cc ldr r3, [pc, r3]
 *   @0x1fb0d0 ldr r3, [r3]
 *   @0x1fb0d4 ldr r0, [r3, #0x88]
 *   @0x1fb0d8 cmp r1, r0
 *   @0x1fb0dc bge 0x1fb118 <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x70>
 *   @0x1fb0e0 ldr r0, [r3, #0x80]
 *   @0x1fb0e4 cmp r0, #0
 *   @0x1fb0e8 beq 0x1fb118 <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x70>
 *   @0x1fb0ec cmp r1, #0
 *   @0x1fb0f0 ldr r3, [r0, #0x178]
 *   @0x1fb0f4 bne 0x1fb10c <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x64>
 *   @0x1fb0f8 b 0x1fb120 <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x78>
 *   @0x1fb0fc cmp r1, #0
 *   @0x1fb100 ldr r0, [r3, #0x178]
 *   @0x1fb104 beq 0x1fb124 <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x7c>
 *   @0x1fb108 mov r3, r0
 *   @0x1fb10c cmp r3, #0
 *   @0x1fb110 sub r1, r1, #1
 *   @0x1fb114 bne 0x1fb0fc <_Z13GV_InstanceIdP9CInstanceiP6RValue+0x54>
 *   @0x1fb118 mov r0, #1
 *   @0x1fb11c bx lr
 *   @0x1fb120 mov r3, r0
 *   @0x1fb124 ldr r0, [r3, #0x78]
 *   @0x1fb128 vmov s15, r0
 *   @0x1fb12c vcvt.f64.s32 d7, s15
 *   @0x1fb130 vmov r0, r1, d7
 *   @0x1fb134 mov r3, r1
 *   @0x1fb138 stm r2, {r0, r3}
 *   @0x1fb13c mov r0, #1
 *   @0x1fb140 bx lr
 *   @0x1fb144 andseq r2, pc, r12, asr r8
 *
 * ══ §6/197 CreateNameFile()  0x1ffb30  size 160  40 条（0x1ffb30..0x1ffbd0）
 * @func 0x1ffb30 0x1ffbd0  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6844 / 0xb68a4
 * 字段偏移 top8: 0x80×2 / 0x54×2 / 0x68×1 / 0x58×1 / 0x-c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ffb30 ldr r0, [pc, #0x80]
 *   @0x1ffb34 ldr r1, [pc, #0x80]
 *   @0x1ffb38 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1ffb3c add r0, pc, r0
 *   @0x1ffb40 add r1, pc, r1
 *   @0x1ffb44 bl 0xb6844 <fopen@plt>
 *   @0x1ffb48 subs r6, r0, #0
 *   @0x1ffb4c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1ffb50 ldr r7, [pc, #0x68]
 *   @0x1ffb54 ldr r7, [pc, r7]
 *   @0x1ffb58 ldr r3, [r7]
 *   @0x1ffb5c cmp r3, #0
 *   @0x1ffb60 pople {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1ffb64 ldr r4, [pc, #0x58]
 *   @0x1ffb68 mov r5, #0
 *   @0x1ffb6c ldr r8, [pc, #0x54]
 *   @0x1ffb70 ldr r9, [pc, #0x54]
 *   @0x1ffb74 ldr r4, [pc, r4]
 *   @0x1ffb78 add r8, pc, r8
 *   @0x1ffb7c add r4, r4, #12
 *   @0x1ffb80 add r9, pc, r9
 *   @0x1ffb84 ldrb r3, [r4]
 *   @0x1ffb88 mov r1, r8
 *   @0x1ffb8c ldr r2, [r4, #-0xc]
 *   @0x1ffb90 mov r0, r6
 *   @0x1ffb94 cmp r3, #0
 *   @0x1ffb98 add r5, r5, #1
 *   @0x1ffb9c add r4, r4, #16
 *   @0x1ffba0 movne r1, r9
 *   @0x1ffba4 bl 0xb68a4 <fprintf@plt>
 *   @0x1ffba8 ldr r3, [r7]
 *   @0x1ffbac cmp r3, r5
 *   @0x1ffbb0 bgt 0x1ffb84 <_Z14CreateNameFilev+0x54>
 *   @0x1ffbb4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1ffbb8 mulseq r5, r4, r11
 *   @0x1ffbbc mulseq r5, r12, r11
 *   @0x1ffbc0 andseq lr, lr, r0, ror #1
 *   @0x1ffbc4 andseq lr, lr, r4, asr #1
 *   @0x1ffbc8 andseq r3, r5, r8, ror #22
 *   @0x1ffbcc andseq r5, r3, r4, lsr #2
 *
 * ══ §7/197 CStream::ReadBuffer(void*, int)  0x2011e4  size 160  40 条（0x2011e4..0x201284）
 * @func 0x2011e4 0x201284  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadBuffer(void*, int)+0x8c / 0xb65bc
 * 字段偏移 top8: 0x4×2 / 0x10×2 / 0x18×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2011e4 cmp r1, #0
 *   @0x2011e8 mov r3, r0
 *   @0x2011ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2011f0 mov r12, r2
 *   @0x2011f4 sub sp, sp, #12
 *   @0x2011f8 beq 0x201278 <_ZN7CStream10ReadBufferEPvi+0x94>
 *   @0x2011fc ldrd r6, r7, [r0, #8]
 *   @0x201200 asr r9, r2, #31
 *   @0x201204 ldrd r4, r5, [r0, #16]
 *   @0x201208 mov r8, r2
 *   @0x20120c mov r10, r6
 *   @0x201210 mov r11, r7
 *   @0x201214 subs r10, r10, r4
 *   @0x201218 sbc r11, r11, r5
 *   @0x20121c cmp r10, r8
 *   @0x201220 sbcs r2, r11, r9
 *   @0x201224 rsblt r12, r4, r6
 *   @0x201228 cmp r12, #0
 *   @0x20122c movle r0, #0
 *   @0x201230 ble 0x201270 <_ZN7CStream10ReadBufferEPvi+0x8c>
 *   @0x201234 ldr lr, [r3, #0x18]
 *   @0x201238 mov r2, r12
 *   @0x20123c mov r0, r1
 *   @0x201240 str r3, [sp, #0x4]
 *   @0x201244 add r1, lr, r4
 *   @0x201248 str r12, [sp]
 *   @0x20124c bl 0xb65bc <memcpy@plt>
 *   @0x201250 ldr r3, [sp, #0x4]
 *   @0x201254 ldr r12, [sp]
 *   @0x201258 mov r2, #0
 *   @0x20125c ldr r1, [r3, #0x10]
 *   @0x201260 mov r0, r12
 *   @0x201264 str r2, [r3, #0x14]
 *   @0x201268 add r12, r12, r1
 *   @0x20126c str r12, [r3, #0x10]
 *   @0x201270 add sp, sp, #12
 *   @0x201274 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x201278 mov r0, r1
 *   @0x20127c add sp, sp, #12
 *   @0x201280 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §8/197 SND_Set_Volume(int, double, int)  0x21f07c  size 160  40 条（0x21f07c..0x21f11c）
 * @func 0x21f07c 0x21f11c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x84×1 / 0x64×1 / 0x54×1 / 0x34×1 / 0x8×1 / 0x1c×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f07c ldr r1, [pc, #0x84]
 *   @0x21f080 vmov d7, r2, r3
 *   @0x21f084 ldr r3, [sp]
 *   @0x21f088 ldr r1, [pc, r1]
 *   @0x21f08c ldrb r2, [r1]
 *   @0x21f090 cmp r2, #0
 *   @0x21f094 bxne lr
 *   @0x21f098 cmp r0, #0
 *   @0x21f09c bxlt lr
 *   @0x21f0a0 ldr r2, [pc, #0x64]
 *   @0x21f0a4 ldr r2, [pc, r2]
 *   @0x21f0a8 ldr r2, [r2]
 *   @0x21f0ac cmp r0, r2
 *   @0x21f0b0 bxge lr
 *   @0x21f0b4 ldr r2, [pc, #0x54]
 *   @0x21f0b8 add r0, r0, r0, lsl #2
 *   @0x21f0bc ldr r2, [pc, r2]
 *   @0x21f0c0 ldr r2, [r2, #0x4]
 *   @0x21f0c4 add r0, r2, r0, lsl #2
 *   @0x21f0c8 ldr r1, [r0, #0x4]
 *   @0x21f0cc cmp r1, #1
 *   @0x21f0d0 beq 0x21f0f0 <_Z14SND_Set_Volumeidi+0x74>
 *   @0x21f0d4 vcvt.f32.f64 s13, d7
 *   @0x21f0d8 ldr r12, [pc, #0x34]
 *   @0x21f0dc ldr r1, [r0, #0x8]
 *   @0x21f0e0 add r12, pc, r12
 *   @0x21f0e4 ldr r0, [r12]
 *   @0x21f0e8 vmov r2, s13
 *   @0x21f0ec b 0x220be0 <_ZN13SoundHardware9SetVolumeEPvfi>
 *   @0x21f0f0 vcvt.f32.f64 s13, d7
 *   @0x21f0f4 ldr r0, [pc, #0x1c]
 *   @0x21f0f8 add r0, pc, r0
 *   @0x21f0fc ldr r0, [r0]
 *   @0x21f100 vmov r2, s13
 *   @0x21f104 b 0x220be0 <_ZN13SoundHardware9SetVolumeEPvfi>
 *   @0x21f108 andseq pc, r12, r4, asr #31
 *   @0x21f10c andseq r2, sp, r0, ror r3
 *   @0x21f110 andseq r2, sp, r12, asr r3
 *   @0x21f114 subseq r6, r3, r4, asr #4
 *   @0x21f118 subseq r6, r3, r12, lsr #4
 *
 * ══ §9/197 COggSyncThread::CleanUp()  0x224940  size 160  40 条（0x224940..0x2249e0）
 * @func 0x224940 0x2249e0  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete[](void*)×2 / Mutex::~Mutex() / operator delete(void*) / SOggChannel::~SOggChannel() / 0xb655c
 * 字段偏移 top8: 0x804×3 / 0x82c×2 / 0x858×2 / 0x830×1 / 0x-4×1 / 0x803×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224940 push {r4, r5, r6, lr}
 *   @0x224944 mov r5, r0
 *   @0x224948 ldr r4, [r0, #0x830]
 *   @0x22494c cmp r4, #0
 *   @0x224950 beq 0x224964 <_ZN14COggSyncThread7CleanUpEv+0x24>
 *   @0x224954 mov r0, r4
 *   @0x224958 bl 0x27e020 <_ZN5MutexD2Ev>
 *   @0x22495c mov r0, r4
 *   @0x224960 bl 0x27d1d0 <_ZdlPv>
 *   @0x224964 ldr r0, [r5, #0x804]
 *   @0x224968 cmp r0, #0
 *   @0x22496c beq 0x2249ac <_ZN14COggSyncThread7CleanUpEv+0x6c>
 *   @0x224970 ldr r4, [r0, #-0x4]
 *   @0x224974 add r4, r4, r4, lsl #1
 *   @0x224978 add r4, r0, r4, lsl #8
 *   @0x22497c cmp r0, r4
 *   @0x224980 beq 0x2249a4 <_ZN14COggSyncThread7CleanUpEv+0x64>
 *   @0x224984 sub r4, r4, #768
 *   @0x224988 mov r0, r4
 *   @0x22498c mov r6, r4
 *   @0x224990 bl 0x2234d0 <_ZN11SOggChannelD2Ev>
 *   @0x224994 ldr r0, [r5, #0x804]
 *   @0x224998 cmp r0, r4
 *   @0x22499c sub r4, r4, #768
 *   @0x2249a0 bne 0x224988 <_ZN14COggSyncThread7CleanUpEv+0x48>
 *   @0x2249a4 sub r0, r0, #8
 *   @0x2249a8 bl 0x27d1d4 <_ZdaPv>
 *   @0x2249ac ldr r0, [r5, #0x82c]
 *   @0x2249b0 mov r3, #0
 *   @0x2249b4 str r3, [r5, #0x804]
 *   @0x2249b8 cmp r0, r3
 *   @0x2249bc beq 0x2249c4 <_ZN14COggSyncThread7CleanUpEv+0x84>
 *   @0x2249c0 bl 0x27d1d4 <_ZdaPv>
 *   @0x2249c4 ldr r0, [r5, #0x858]
 *   @0x2249c8 bl 0xb655c <free@plt>
 *   @0x2249cc mov r3, #0
 *   @0x2249d0 str r3, [r5, #0x858]
 *   @0x2249d4 str r3, [r5, #0x82c]
 *   @0x2249d8 strb r3, [r5, #0x803]
 *   @0x2249dc pop {r4, r5, r6, pc}
 *
 * ══ §10/197 F_JS_Object_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*)  0x23cb44  size 160  40 条（0x23cb44..0x23cbe4）
 * @func 0x23cb44 0x23cbe4  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / 0xb65c8 / YYCreateString(RValue*, char const*) / 0xb65d4
 * 字段偏移 top8: 0x40×2 / 0x-18×2 / 0x80×1 / 0x60×1 / 0x4c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23cb44 push {r4, r5, r6, r7, r11, lr}
 *   @0x23cb48 add r11, sp, #20
 *   @0x23cb4c ldr r4, [pc, #0x80]
 *   @0x23cb50 sub sp, sp, #16
 *   @0x23cb54 mov r7, r0
 *   @0x23cb58 ldr r4, [pc, r4]
 *   @0x23cb5c ldr r6, [r1, #0x40]
 *   @0x23cb60 ldr r3, [r4]
 *   @0x23cb64 mov r0, r6
 *   @0x23cb68 str r3, [r11, #-0x18]
 *   @0x23cb6c bl 0xb6538 <strlen@plt>
 *   @0x23cb70 ldr r3, [pc, #0x60]
 *   @0x23cb74 add r3, pc, r3
 *   @0x23cb78 add r2, r0, #24
 *   @0x23cb7c add r1, r0, #10
 *   @0x23cb80 bic r2, r2, #7
 *   @0x23cb84 sub sp, sp, r2
 *   @0x23cb88 ldr r2, [pc, #0x4c]
 *   @0x23cb8c add r5, sp, #8
 *   @0x23cb90 str r3, [sp, #0x4]
 *   @0x23cb94 add r2, pc, r2
 *   @0x23cb98 ldr r3, [pc, #0x40]
 *   @0x23cb9c mov r0, r5
 *   @0x23cba0 str r6, [sp]
 *   @0x23cba4 add r3, pc, r3
 *   @0x23cba8 bl 0xb65c8 <snprintf@plt>
 *   @0x23cbac mov r0, r7
 *   @0x23cbb0 mov r1, r5
 *   @0x23cbb4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x23cbb8 ldr r2, [r11, #-0x18]
 *   @0x23cbbc ldr r3, [r4]
 *   @0x23cbc0 cmp r2, r3
 *   @0x23cbc4 bne 0x23cbd0 <_Z30F_JS_Object_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x23cbc8 sub sp, r11, #20
 *   @0x23cbcc pop {r4, r5, r6, r7, r11, pc}
 *   @0x23cbd0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x23cbd4 ldrsheq r0, [r11], -r8
 *   @0x23cbd8 andseq r8, r1, r4, ror r8
 *   @0x23cbdc andeq r10, pc, r12, lsr #25
 *   @0x23cbe0 andseq r8, r1, r8, lsr r8
 *
 * ══ §11/197 HasInstance(YYObjectBase*, RValue*)  0x23cd84  size 160  40 条（0x23cd84..0x23ce24）
 * @func 0x23cd84 0x23ce24  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0xc×2 / 0x18×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23cd84 ldr r3, [r1, #0xc]
 *   @0x23cd88 push {r4, r5, r6, lr}
 *   @0x23cd8c bic r3, r3, #-16777216
 *   @0x23cd90 cmp r3, #6
 *   @0x23cd94 mov r5, r1
 *   @0x23cd98 beq 0x23cda4 <_Z11HasInstanceP12YYObjectBaseP6RValue+0x20>
 *   @0x23cd9c mov r0, #0
 *   @0x23cda0 pop {r4, r5, r6, pc}
 *   @0x23cda4 ldr r6, [r0, #0x4]
 *   @0x23cda8 cmp r6, #0
 *   @0x23cdac beq 0x23ce14 <_Z11HasInstanceP12YYObjectBaseP6RValue+0x90>
 *   @0x23cdb0 ldr r3, [r6, #0xc]
 *   @0x23cdb4 bic r3, r3, #-16777216
 *   @0x23cdb8 cmp r3, #6
 *   @0x23cdbc beq 0x23cdc8 <_Z11HasInstanceP12YYObjectBaseP6RValue+0x44>
 *   @0x23cdc0 mov r0, #2
 *   @0x23cdc4 pop {r4, r5, r6, pc}
 *   @0x23cdc8 ldr r0, [r5]
 *   @0x23cdcc ldr r4, [r0, #0x18]
 *   @0x23cdd0 cmp r4, #0
 *   @0x23cdd4 beq 0x23cd9c <_Z11HasInstanceP12YYObjectBaseP6RValue+0x18>
 *   @0x23cdd8 ldr r3, [r6]
 *   @0x23cddc cmp r4, r3
 *   @0x23cde0 bne 0x23cdec <_Z11HasInstanceP12YYObjectBaseP6RValue+0x68>
 *   @0x23cde4 b 0x23ce0c <_Z11HasInstanceP12YYObjectBaseP6RValue+0x88>
 *   @0x23cde8 ldr r0, [r5]
 *   @0x23cdec ldr r4, [r4, #0x18]
 *   @0x23cdf0 mov r1, r4
 *   @0x23cdf4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x23cdf8 cmp r4, #0
 *   @0x23cdfc beq 0x23cd9c <_Z11HasInstanceP12YYObjectBaseP6RValue+0x18>
 *   @0x23ce00 ldr r3, [r6]
 *   @0x23ce04 cmp r3, r4
 *   @0x23ce08 bne 0x23cde8 <_Z11HasInstanceP12YYObjectBaseP6RValue+0x64>
 *   @0x23ce0c mov r0, #1
 *   @0x23ce10 pop {r4, r5, r6, pc}
 *   @0x23ce14 mov r1, r6
 *   @0x23ce18 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x23ce1c mov r6, r0
 *   @0x23ce20 b 0x23cdb0 <_Z11HasInstanceP12YYObjectBaseP6RValue+0x2c>
 *
 * ══ §12/197 DaysInYear(double)  0x244a08  size 160  40 条（0x244a08..0x244aa8）
 * @func 0x244a08 0x244aa8  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66ac×3
 * 字段偏移 top8: 无
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244a08 push {r3, r4, r5, lr}
 *   @0x244a0c mov r2, #0
 *   @0x244a10 mov r3, #0
 *   @0x244a14 movt r3, #0x4010
 *   @0x244a18 mov r4, r0
 *   @0x244a1c mov r5, r1
 *   @0x244a20 bl 0xb66ac <fmod@plt>
 *   @0x244a24 vmov d7, r0, r1
 *   @0x244a28 vcmp.f64 d7, #0
 *   @0x244a2c vmrs APSR_nzcv, fpscr
 *   @0x244a30 beq 0x244a44 <_Z10DaysInYeard+0x3c>
 *   @0x244a34 mov r0, #0
 *   @0x244a38 mov r1, #53248
 *   @0x244a3c movt r1, #0x4076
 *   @0x244a40 pop {r3, r4, r5, pc}
 *   @0x244a44 mov r0, r4
 *   @0x244a48 mov r1, r5
 *   @0x244a4c mov r2, #0
 *   @0x244a50 mov r3, #0
 *   @0x244a54 movt r3, #0x4059
 *   @0x244a58 bl 0xb66ac <fmod@plt>
 *   @0x244a5c vmov d7, r0, r1
 *   @0x244a60 vcmp.f64 d7, #0
 *   @0x244a64 vmrs APSR_nzcv, fpscr
 *   @0x244a68 beq 0x244a7c <_Z10DaysInYeard+0x74>
 *   @0x244a6c mov r0, #0
 *   @0x244a70 mov r1, #57344
 *   @0x244a74 movt r1, #0x4076
 *   @0x244a78 pop {r3, r4, r5, pc}
 *   @0x244a7c mov r0, r4
 *   @0x244a80 mov r1, r5
 *   @0x244a84 mov r2, #0
 *   @0x244a88 mov r3, #0
 *   @0x244a8c movt r3, #0x4079
 *   @0x244a90 bl 0xb66ac <fmod@plt>
 *   @0x244a94 vmov d7, r0, r1
 *   @0x244a98 vcmp.f64 d7, #0
 *   @0x244a9c vmrs APSR_nzcv, fpscr
 *   @0x244aa0 beq 0x244a6c <_Z10DaysInYeard+0x64>
 *   @0x244aa4 b 0x244a34 <_Z10DaysInYeard+0x2c>
 *
 * ══ §13/197 EncodeObject(RValue*)  0x24a810  size 160  40 条（0x24a810..0x24a8b0）
 * @func 0x24a810 0x24a8b0  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_object_new_object / YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int) / JS_GetProperty(YYObjectBase*, RValue*, char const*) / EncodeValue(RValue*) / json_object_object_add / YYObject_PropertyNameIterator::Next(RValue*)
 * 字段偏移 top8: 0x4×3 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24a810 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x24a814 sub sp, sp, #68
 *   @0x24a818 ldr r6, [r0]
 *   @0x24a81c bl 0x27e89c <json_object_new_object>
 *   @0x24a820 add r7, sp, #36
 *   @0x24a824 mov r2, #1
 *   @0x24a828 add r9, sp, #4
 *   @0x24a82c add r4, sp, #20
 *   @0x24a830 mov r1, r6
 *   @0x24a834 mov r8, r0
 *   @0x24a838 mov r0, r7
 *   @0x24a83c bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x24a840 mov r3, #0
 *   @0x24a844 mvn r2, #-16777216
 *   @0x24a848 str r3, [sp, #0x4]
 *   @0x24a84c str r3, [sp, #0x8]
 *   @0x24a850 str r3, [sp, #0xc]
 *   @0x24a854 str r2, [sp, #0x10]
 *   @0x24a858 b 0x24a888 <_Z12EncodeObjectP6RValue+0x78>
 *   @0x24a85c ldr r3, [sp, #0x4]
 *   @0x24a860 ldr r2, [r3]
 *   @0x24a864 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x24a868 ldr r3, [sp, #0x4]
 *   @0x24a86c mov r0, r4
 *   @0x24a870 ldr r5, [r3]
 *   @0x24a874 bl 0x13be2c <_Z11EncodeValueP6RValue>
 *   @0x24a878 mov r1, r5
 *   @0x24a87c mov r2, r0
 *   @0x24a880 mov r0, r8
 *   @0x24a884 bl 0x27ea00 <json_object_object_add>
 *   @0x24a888 mov r1, r9
 *   @0x24a88c mov r0, r7
 *   @0x24a890 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x24a894 mov r1, r4
 *   @0x24a898 cmp r0, #0
 *   @0x24a89c mov r0, r6
 *   @0x24a8a0 bne 0x24a85c <_Z12EncodeObjectP6RValue+0x4c>
 *   @0x24a8a4 mov r0, r8
 *   @0x24a8a8 add sp, sp, #68
 *   @0x24a8ac pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §14/197 spDeformTimeline_create  0x282e58  size 160  40 条（0x282e58..0x282ef8）
 * @func 0x282e58 0x282ef8  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc×3 / _spCurveTimeline_init
 * 字段偏移 top8: 0x64×2 / 0x84×1 / 0xc×1 / 0x10×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282e58 push {r4, r5, r6, r7, lr}
 *   @0x282e5c movw r3, #0x30f
 *   @0x282e60 ldr r6, [pc, #0x84]
 *   @0x282e64 sub sp, sp, #12
 *   @0x282e68 mov r5, r0
 *   @0x282e6c mov r7, r1
 *   @0x282e70 add r6, pc, r6
 *   @0x282e74 mov r1, #36
 *   @0x282e78 mov r0, #1
 *   @0x282e7c mov r2, r6
 *   @0x282e80 bl 0x285c4c <_calloc>
 *   @0x282e84 ldr r3, [pc, #0x64]
 *   @0x282e88 ldr r12, [pc, #0x64]
 *   @0x282e8c mov r2, r5
 *   @0x282e90 mov r1, #8
 *   @0x282e94 ldr r3, [pc, r3]
 *   @0x282e98 ldr r12, [pc, r12]
 *   @0x282e9c str r12, [sp]
 *   @0x282ea0 mov r4, r0
 *   @0x282ea4 bl 0x2816d8 <_spCurveTimeline_init>
 *   @0x282ea8 mov r2, r6
 *   @0x282eac str r5, [r4, #0xc]
 *   @0x282eb0 mov r0, r5
 *   @0x282eb4 mov r1, #4
 *   @0x282eb8 movw r3, #0x312
 *   @0x282ebc bl 0x285c4c <_calloc>
 *   @0x282ec0 mov r2, r6
 *   @0x282ec4 mov r1, #4
 *   @0x282ec8 movw r3, #0x313
 *   @0x282ecc str r0, [r4, #0x10]
 *   @0x282ed0 mov r0, r5
 *   @0x282ed4 bl 0x285c4c <_calloc>
 *   @0x282ed8 str r7, [r4, #0x14]
 *   @0x282edc str r0, [r4, #0x18]
 *   @0x282ee0 mov r0, r4
 *   @0x282ee4 add sp, sp, #12
 *   @0x282ee8 pop {r4, r5, r6, r7, pc}
 *   @0x282eec andeq r4, sp, r0, ror #11
 *   @0x282ef0 andseq lr, r6, r12, lsr r10
 *   @0x282ef4 andseq lr, r6, r12, lsr r10
 *
 * ══ §15/197 spSkeleton_setAttachment  0x28a398  size 160  40 条（0x28a398..0x28a438）
 * @func 0x28a398 0x28a438  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSlot_setAttachment×2 / spSkeleton_setAttachment+0x84 / 0xb6574 / spSkeleton_getAttachmentForSlotIndex
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a398 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x28a39c mov r9, r0
 *   @0x28a3a0 ldr r7, [r0, #0x10]
 *   @0x28a3a4 mov r8, r1
 *   @0x28a3a8 mov r10, r2
 *   @0x28a3ac cmp r7, #0
 *   @0x28a3b0 ble 0x28a41c <spSkeleton_setAttachment+0x84>
 *   @0x28a3b4 ldr r5, [r0, #0x14]
 *   @0x28a3b8 mov r4, #0
 *   @0x28a3bc sub r5, r5, #4
 *   @0x28a3c0 b 0x28a3d0 <spSkeleton_setAttachment+0x38>
 *   @0x28a3c4 add r4, r4, #1
 *   @0x28a3c8 cmp r4, r7
 *   @0x28a3cc beq 0x28a41c <spSkeleton_setAttachment+0x84>
 *   @0x28a3d0 ldr r6, [r5, #0x4]!
 *   @0x28a3d4 mov r1, r8
 *   @0x28a3d8 ldr r3, [r6]
 *   @0x28a3dc ldr r0, [r3, #0x4]
 *   @0x28a3e0 bl 0xb6574 <strcmp@plt>
 *   @0x28a3e4 cmp r0, #0
 *   @0x28a3e8 bne 0x28a3c4 <spSkeleton_setAttachment+0x2c>
 *   @0x28a3ec cmp r10, #0
 *   @0x28a3f0 beq 0x28a424 <spSkeleton_setAttachment+0x8c>
 *   @0x28a3f4 mov r1, r4
 *   @0x28a3f8 mov r0, r9
 *   @0x28a3fc mov r2, r10
 *   @0x28a400 bl 0x28a314 <spSkeleton_getAttachmentForSlotIndex>
 *   @0x28a404 subs r1, r0, #0
 *   @0x28a408 beq 0x28a41c <spSkeleton_setAttachment+0x84>
 *   @0x28a40c mov r0, r6
 *   @0x28a410 bl 0x28ee1c <spSlot_setAttachment>
 *   @0x28a414 mov r0, #1
 *   @0x28a418 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x28a41c mov r0, #0
 *   @0x28a420 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x28a424 mov r0, r6
 *   @0x28a428 mov r1, r10
 *   @0x28a42c bl 0x28ee1c <spSlot_setAttachment>
 *   @0x28a430 mov r0, #1
 *   @0x28a434 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §16/197 RelyConfig(char*, char*)  0x2999fc  size 160  40 条（0x2999fc..0x299a9c）
 * @func 0x2999fc 0x299a9c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66d0×2 / 0xb6658×2
 * 字段偏移 top8: 0x80×1 / 0x6c×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2999fc push {r3, r4, r5, lr}
 *   @0x299a00 mov r5, r1
 *   @0x299a04 ldr r1, [pc, #0x80]
 *   @0x299a08 mov r4, r0
 *   @0x299a0c add r1, pc, r1
 *   @0x299a10 bl 0xb66d0 <strcasecmp@plt>
 *   @0x299a14 subs r1, r0, #0
 *   @0x299a18 beq 0x299a60 <_Z10RelyConfigPcS_+0x64>
 *   @0x299a1c ldr r1, [pc, #0x6c]
 *   @0x299a20 mov r0, r4
 *   @0x299a24 add r1, pc, r1
 *   @0x299a28 bl 0xb66d0 <strcasecmp@plt>
 *   @0x299a2c subs r1, r0, #0
 *   @0x299a30 popne {r3, r4, r5, pc}
 *   @0x299a34 mov r0, r5
 *   @0x299a38 bl 0xb6658 <strtod@plt>
 *   @0x299a3c vmov.f32 s14, #1.000000e+01
 *   @0x299a40 vmov d6, r0, r1
 *   @0x299a44 vcvt.f32.f64 s15, d6
 *   @0x299a48 vcmpe.f32 s15, s14
 *   @0x299a4c vmrs APSR_nzcv, fpscr
 *   @0x299a50 ldrls r3, [pc, #0x3c]
 *   @0x299a54 ldrls r3, [pc, r3]
 *   @0x299a58 vstrls s15, [r3]
 *   @0x299a5c pop {r3, r4, r5, pc}
 *   @0x299a60 mov r0, r5
 *   @0x299a64 bl 0xb6658 <strtod@plt>
 *   @0x299a68 vmov.f32 s14, #3.000000e+01
 *   @0x299a6c vmov d6, r0, r1
 *   @0x299a70 vcvt.f32.f64 s15, d6
 *   @0x299a74 vcmpe.f32 s15, s14
 *   @0x299a78 vmrs APSR_nzcv, fpscr
 *   @0x299a7c ldrls r3, [pc, #0x14]
 *   @0x299a80 ldrls r3, [pc, r3]
 *   @0x299a84 vstrls s15, [r3]
 *   @0x299a88 b 0x299a1c <_Z10RelyConfigPcS_+0x20>
 *   @0x299a8c andeq pc, r11, r12, ror #29
 *   @0x299a90 andeq pc, r11, r0, ror #29
 *   @0x299a94 mulseq r5, r8, pc
 *   @0x299a98 andseq r7, r5, r0, ror pc
 *
 * ══ §17/197 png_write_sBIT  0x2b1aac  size 160  40 条（0x2b1aac..0x2b1b4c）
 * @func 0x2b1aac 0x2b1b4c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning / png_write_chunk
 * 字段偏移 top8: 0x90×1 / 0x30×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1aac push {r0, r1, r2, r3, r4, r5, r6, lr}
 *   @0x2b1ab0 ldr r3, [pc, #0x90]
 *   @0x2b1ab4 ldr r0, [r3, #48]!
 *   @0x2b1ab8 ldrb r3, [r3, #0x4]
 *   @0x2b1abc lsls r0, r2, #0x1e
 *   @0x2b1ac0 strle r3, [r0, #-0xc]!
 *   @0x2b1ac4 cmp r2, #0x3
 *   @0x2b1ac8 ite ne
 *   @0x2b1acc movwhs r3, #0x81ec
 *   @0x2b1ad0 cbnz r6, 0x2b1ade <png_write_sBIT+0x32>
 *   @0x2b1ad4 mov r0, r4
 *   @0x2b1ad8 bl 0x2a6474 <png_warning>
 *   @0x2b1adc b 0x2b1b40 <png_write_sBIT+0x94>
 *   @0x2b1ae0 bhi 0x2b1ad2 <png_write_sBIT+0x26>
 *   @0x2b1ae4 cmp r5, #0x0
 *   @0x2b1ae8 cmp r5, r3
 *   @0x2b1aec ldrb r0, [r1, #0x2]
 *   @0x2b1af0 beq 0x2b1ad2 <png_write_sBIT+0x26>
 *   @0x2b1af4 bhi 0x2b1ad2 <png_write_sBIT+0x26>
 *   @0x2b1af8 movwhs r6, #0x3004
 *   @0x2b1afc strb.w r5, [sp, #0x5]
 *   @0x2b1b00 strb.w r0, [sp, #0x6]
 *   @0x2b1b04 b 0x2b1b1a <png_write_sBIT+0x6e>
 *   @0x2b1b08 cmp r3, #0x0
 *   @0x2b1b0c ldrb.w r0, [r4, #0x1ec]
 *   @0x2b1b10 cmp r0, r3
 *   @0x2b1b14 strb.w r3, [sp, #0x4]
 *   @0x2b1b18 movs r3, #0x1
 *   @0x2b1b1c bpl 0x2b1b36 <png_write_sBIT+0x8a>
 *   @0x2b1b20 cmp r2, #0x0
 *   @0x2b1b24 ldrb.w r1, [r4, #0x1ec]
 *   @0x2b1b28 cmp r1, r2
 *   @0x2b1b2c add r1, sp, #0x10
 *   @0x2b1b30 adds r3, #0x1
 *   @0x2b1b34 strtmi r2, [r0], -r12, lsl #24
 *   @0x2b1b38 add r1, sp, #0x8
 *   @0x2b1b3c bl 0x2b12bc <png_write_chunk>
 *   @0x2b1b40 add sp, #0x10
 *   @0x2b1b44 b 0x2b20a4 <png_write_zTXt+0xa0>
 *   @0x2b1b48 ldm r1!, {r2, r5, r7}
 *
 * ══ §18/197 b2ChainShape::Clone(b2BlockAllocator*) const  0x2c4b1c  size 160  40 条（0x2c4b1c..0x2c4bbc）
 * @func 0x2c4b1c 0x2c4bbc  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / b2ChainShape::CreateChain(b2Vec2 const*, int)
 * 字段偏移 top8: 0x24×3 / 0x25×3 / 0xc×2 / 0x10×2 / 0x78×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4b1c push {r4, r5, r6, lr}
 *   @0x2c4b20 mov r5, r0
 *   @0x2c4b24 mov r0, r1
 *   @0x2c4b28 mov r1, #40
 *   @0x2c4b2c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2c4b30 subs r4, r0, #0
 *   @0x2c4b34 beq 0x2c4b70 <_ZNK12b2ChainShape5CloneEP16b2BlockAllocator+0x54>
 *   @0x2c4b38 ldr r3, [pc, #0x78]
 *   @0x2c4b3c mov r2, #3
 *   @0x2c4b40 movw r1, #0xd70a
 *   @0x2c4b44 str r2, [r4, #0x4]
 *   @0x2c4b48 ldr r3, [pc, r3]
 *   @0x2c4b4c movt r1, #0x3c23
 *   @0x2c4b50 add r2, r3, #8
 *   @0x2c4b54 str r1, [r4, #0x8]
 *   @0x2c4b58 mov r3, #0
 *   @0x2c4b5c str r2, [r4]
 *   @0x2c4b60 str r3, [r4, #0xc]
 *   @0x2c4b64 str r3, [r4, #0x10]
 *   @0x2c4b68 strb r3, [r4, #0x24]
 *   @0x2c4b6c strb r3, [r4, #0x25]
 *   @0x2c4b70 mov r0, r4
 *   @0x2c4b74 ldr r1, [r5, #0xc]
 *   @0x2c4b78 ldr r2, [r5, #0x10]
 *   @0x2c4b7c bl 0x2c4ae0 <_ZN12b2ChainShape11CreateChainEPK6b2Vec2i>
 *   @0x2c4b80 add r3, r5, #20
 *   @0x2c4b84 add r2, r5, #28
 *   @0x2c4b88 add r12, r4, #20
 *   @0x2c4b8c ldm r3, {r0, r1}
 *   @0x2c4b90 add r3, r4, #28
 *   @0x2c4b94 ldrb r6, [r5, #0x24]
 *   @0x2c4b98 ldrb r5, [r5, #0x25]
 *   @0x2c4b9c stm r12, {r0, r1}
 *   @0x2c4ba0 ldm r2, {r0, r1}
 *   @0x2c4ba4 stm r3, {r0, r1}
 *   @0x2c4ba8 mov r0, r4
 *   @0x2c4bac strb r6, [r4, #0x24]
 *   @0x2c4bb0 strb r5, [r4, #0x25]
 *   @0x2c4bb4 pop {r4, r5, r6, pc}
 *   @0x2c4bb8 andseq r12, r2, r0, ror r9
 *
 * ══ §19/197 b2Fixture::Refilter()  0x2c88fc  size 160  40 条（0x2c88fc..0x2c899c）
 * @func 0x2c88fc 0x2c899c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BroadPhase::TouchProxy(int)
 * 字段偏移 top8: 0x1c×2 / 0x18×2 / 0x8×1 / 0x80×1 / 0x4×1 / 0xc×1 / 0x30×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c88fc ldr r12, [r0, #0x8]
 *   @0x2c8900 push {r3, r4, r5, r6, r7, lr}
 *   @0x2c8904 cmp r12, #0
 *   @0x2c8908 mov r4, r0
 *   @0x2c890c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x2c8910 ldr r3, [r12, #0x80]
 *   @0x2c8914 cmp r3, #0
 *   @0x2c8918 beq 0x2c8948 <_ZN9b2Fixture8RefilterEv+0x4c>
 *   @0x2c891c ldr r2, [r3, #0x4]
 *   @0x2c8920 ldr r3, [r3, #0xc]
 *   @0x2c8924 ldr r1, [r2, #0x30]
 *   @0x2c8928 ldr r0, [r2, #0x34]
 *   @0x2c892c cmp r4, r1
 *   @0x2c8930 cmpne r4, r0
 *   @0x2c8934 ldreq r1, [r2, #0x4]
 *   @0x2c8938 orreq r1, r1, #8
 *   @0x2c893c streq r1, [r2, #0x4]
 *   @0x2c8940 cmp r3, #0
 *   @0x2c8944 bne 0x2c891c <_ZN9b2Fixture8RefilterEv+0x20>
 *   @0x2c8948 ldr r7, [r12, #0x68]
 *   @0x2c894c cmp r7, #0
 *   @0x2c8950 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x2c8954 ldr r3, [r4, #0x1c]
 *   @0x2c8958 add r7, r7, #102400
 *   @0x2c895c add r7, r7, #472
 *   @0x2c8960 cmp r3, #0
 *   @0x2c8964 pople {r3, r4, r5, r6, r7, pc}
 *   @0x2c8968 mov r5, #0
 *   @0x2c896c mov r6, r5
 *   @0x2c8970 ldr r3, [r4, #0x18]
 *   @0x2c8974 mov r0, r7
 *   @0x2c8978 add r6, r6, #1
 *   @0x2c897c add r3, r3, r5
 *   @0x2c8980 add r5, r5, #28
 *   @0x2c8984 ldr r1, [r3, #0x18]
 *   @0x2c8988 bl 0x2dc8e0 <_ZN12b2BroadPhase10TouchProxyEi>
 *   @0x2c898c ldr r3, [r4, #0x1c]
 *   @0x2c8990 cmp r3, r6
 *   @0x2c8994 bgt 0x2c8970 <_ZN9b2Fixture8RefilterEv+0x74>
 *   @0x2c8998 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §20/197 b2PrismaticJoint::GetJointTranslation() const  0x2d016c  size 160  40 条（0x2d016c..0x2d020c）
 * @func 0x2d016c 0x2d020c  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0x34×1
 * VFP 指令 37 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d016c ldr r3, [r0, #0x30]
 *   @0x2d0170 vldr s11, [r0, #72]
 *   @0x2d0174 ldr r2, [r0, #0x34]
 *   @0x2d0178 vldr s15, [r3, #24]
 *   @0x2d017c vldr s10, [r0, #80]
 *   @0x2d0180 vmul.f32 s8, s15, s11
 *   @0x2d0184 vldr s5, [r2, #24]
 *   @0x2d0188 vldr s14, [r3, #20]
 *   @0x2d018c vldr s4, [r0, #68]
 *   @0x2d0190 vldr s6, [r0, #76]
 *   @0x2d0194 vldr s3, [r2, #20]
 *   @0x2d0198 vldr s13, [r0, #88]
 *   @0x2d019c vldr s7, [r0, #84]
 *   @0x2d01a0 vpush {d8}
 *   @0x2d01a4 vldr s0, [r2, #16]
 *   @0x2d01a8 vldr s16, [r3, #16]
 *   @0x2d01ac vldr s1, [r2, #12]
 *   @0x2d01b0 vldr s2, [r3, #12]
 *   @0x2d01b4 vmul.f32 s9, s5, s10
 *   @0x2d01b8 vmul.f32 s11, s14, s11
 *   @0x2d01bc vmla.f32 s8, s4, s14
 *   @0x2d01c0 vmul.f32 s10, s3, s10
 *   @0x2d01c4 vmla.f32 s9, s6, s3
 *   @0x2d01c8 vmul.f32 s12, s15, s13
 *   @0x2d01cc vnmls.f32 s11, s15, s4
 *   @0x2d01d0 vnmls.f32 s10, s5, s6
 *   @0x2d01d4 vmul.f32 s13, s14, s13
 *   @0x2d01d8 vmla.f32 s12, s14, s7
 *   @0x2d01dc vadd.f32 s8, s8, s16
 *   @0x2d01e0 vpop {d8}
 *   @0x2d01e4 vadd.f32 s9, s9, s0
 *   @0x2d01e8 vsub.f32 s9, s9, s8
 *   @0x2d01ec vnmls.f32 s13, s15, s7
 *   @0x2d01f0 vadd.f32 s10, s10, s1
 *   @0x2d01f4 vadd.f32 s11, s11, s2
 *   @0x2d01f8 vmul.f32 s12, s9, s12
 *   @0x2d01fc vsub.f32 s11, s10, s11
 *   @0x2d0200 vmla.f32 s12, s11, s13
 *   @0x2d0204 vmov r0, s12
 *   @0x2d0208 bx lr
 *
 * ══ §21/197 b2RevoluteJoint::b2RevoluteJoint(b2RevoluteJointDef const*)  0x2d2064  size 160  40 条（0x2d2064..0x2d2104）
 * @func 0x2d2064 0x2d2104  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::b2Joint(b2JointDef const*)
 * 字段偏移 top8: 0x80×1 / 0x28×1 / 0x34×1 / 0x24×1 / 0x2c×1 / 0x44×1 / 0x30×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2064 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2d2068 mov r4, r0
 *   @0x2d206c mov r5, r1
 *   @0x2d2070 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef>
 *   @0x2d2074 add r3, r5, #20
 *   @0x2d2078 ldr r2, [pc, #0x80]
 *   @0x2d207c add r12, r5, #28
 *   @0x2d2080 ldrb r7, [r5, #0x28]
 *   @0x2d2084 ldm r3, {r0, r1}
 *   @0x2d2088 ldr r2, [pc, r2]
 *   @0x2d208c mov r3, r4
 *   @0x2d2090 ldrb r6, [r5, #0x34]
 *   @0x2d2094 ldr r11, [r5, #0x24]
 *   @0x2d2098 add r2, r2, #8
 *   @0x2d209c ldr r10, [r5, #0x2c]
 *   @0x2d20a0 str r2, [r3], #68
 *   @0x2d20a4 add r2, r4, #76
 *   @0x2d20a8 stm r3, {r0, r1}
 *   @0x2d20ac mov r3, #0
 *   @0x2d20b0 ldm r12, {r0, r1}
 *   @0x2d20b4 mov r12, #0
 *   @0x2d20b8 ldr r9, [r5, #0x30]
 *   @0x2d20bc ldr r8, [r5, #0x3c]
 *   @0x2d20c0 ldr r5, [r5, #0x38]
 *   @0x2d20c4 stm r2, {r0, r1}
 *   @0x2d20c8 mov r0, r4
 *   @0x2d20cc str r11, [r4, #0x74]
 *   @0x2d20d0 str r10, [r4, #0x78]
 *   @0x2d20d4 str r9, [r4, #0x7c]
 *   @0x2d20d8 str r8, [r4, #0x68]
 *   @0x2d20dc str r5, [r4, #0x6c]
 *   @0x2d20e0 strb r7, [r4, #0x70]
 *   @0x2d20e4 strb r6, [r4, #0x64]
 *   @0x2d20e8 str r3, [r4, #0x54]
 *   @0x2d20ec str r12, [r4, #0xe0]
 *   @0x2d20f0 str r3, [r4, #0x58]
 *   @0x2d20f4 str r3, [r4, #0x5c]
 *   @0x2d20f8 str r3, [r4, #0x60]
 *   @0x2d20fc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d2100 andseq pc, r1, r8, ror #21
 *
 * ══ §22/197 b2WheelJoint::GetJointTranslation() const  0x2d42e0  size 160  40 条（0x2d42e0..0x2d4380）
 * @func 0x2d42e0 0x2d4380  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0x34×1
 * VFP 指令 37 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d42e0 ldr r3, [r0, #0x30]
 *   @0x2d42e4 vldr s11, [r0, #80]
 *   @0x2d42e8 ldr r2, [r0, #0x34]
 *   @0x2d42ec vldr s15, [r3, #24]
 *   @0x2d42f0 vldr s10, [r0, #88]
 *   @0x2d42f4 vmul.f32 s8, s15, s11
 *   @0x2d42f8 vldr s5, [r2, #24]
 *   @0x2d42fc vldr s14, [r3, #20]
 *   @0x2d4300 vldr s4, [r0, #76]
 *   @0x2d4304 vldr s6, [r0, #84]
 *   @0x2d4308 vldr s3, [r2, #20]
 *   @0x2d430c vldr s13, [r0, #96]
 *   @0x2d4310 vldr s7, [r0, #92]
 *   @0x2d4314 vpush {d8}
 *   @0x2d4318 vldr s0, [r2, #16]
 *   @0x2d431c vldr s16, [r3, #16]
 *   @0x2d4320 vldr s1, [r2, #12]
 *   @0x2d4324 vldr s2, [r3, #12]
 *   @0x2d4328 vmul.f32 s9, s5, s10
 *   @0x2d432c vmul.f32 s11, s14, s11
 *   @0x2d4330 vmla.f32 s8, s4, s14
 *   @0x2d4334 vmul.f32 s10, s3, s10
 *   @0x2d4338 vmla.f32 s9, s6, s3
 *   @0x2d433c vmul.f32 s12, s15, s13
 *   @0x2d4340 vnmls.f32 s11, s15, s4
 *   @0x2d4344 vnmls.f32 s10, s5, s6
 *   @0x2d4348 vmul.f32 s13, s14, s13
 *   @0x2d434c vmla.f32 s12, s14, s7
 *   @0x2d4350 vadd.f32 s8, s8, s16
 *   @0x2d4354 vpop {d8}
 *   @0x2d4358 vadd.f32 s9, s9, s0
 *   @0x2d435c vsub.f32 s9, s9, s8
 *   @0x2d4360 vnmls.f32 s13, s15, s7
 *   @0x2d4364 vadd.f32 s10, s10, s1
 *   @0x2d4368 vadd.f32 s11, s11, s2
 *   @0x2d436c vmul.f32 s12, s9, s12
 *   @0x2d4370 vsub.f32 s11, s10, s11
 *   @0x2d4374 vmla.f32 s12, s11, s13
 *   @0x2d4378 vmov r0, s12
 *   @0x2d437c bx lr
 *
 * ══ §23/197 b2BroadPhase::QueryCallback(int)  0x2dc950  size 160  40 条（0x2dc950..0x2dc9f0）
 * @func 0x2dc950 0x2dc9f0  size 160  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Alloc(int) / 0xb65bc / b2Free(void*)
 * 字段偏移 top8: 0x34×4 / 0x2c×3 / 0x38×2 / 0x30×2 / 0x4×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dc950 ldr r3, [r0, #0x38]
 *   @0x2dc954 push {r4, r5, r6, lr}
 *   @0x2dc958 cmp r3, r1
 *   @0x2dc95c mov r4, r0
 *   @0x2dc960 mov r5, r1
 *   @0x2dc964 beq 0x2dc99c <_ZN12b2BroadPhase13QueryCallbackEi+0x4c>
 *   @0x2dc968 ldr r0, [r0, #0x34]
 *   @0x2dc96c ldr r2, [r4, #0x30]
 *   @0x2dc970 cmp r0, r2
 *   @0x2dc974 beq 0x2dc9b4 <_ZN12b2BroadPhase13QueryCallbackEi+0x64>
 *   @0x2dc978 ldr r2, [r4, #0x2c]
 *   @0x2dc97c cmp r5, r3
 *   @0x2dc980 add r1, r2, r0, lsl #3
 *   @0x2dc984 strlt r5, [r2, r0, lsl #3]
 *   @0x2dc988 movlt r5, r3
 *   @0x2dc98c bge 0x2dc9a4 <_ZN12b2BroadPhase13QueryCallbackEi+0x54>
 *   @0x2dc990 str r5, [r1, #0x4]
 *   @0x2dc994 add r0, r0, #1
 *   @0x2dc998 str r0, [r4, #0x34]
 *   @0x2dc99c mov r0, #1
 *   @0x2dc9a0 pop {r4, r5, r6, pc}
 *   @0x2dc9a4 cmp r5, r3
 *   @0x2dc9a8 movlt r5, r3
 *   @0x2dc9ac str r3, [r2, r0, lsl #3]
 *   @0x2dc9b0 b 0x2dc990 <_ZN12b2BroadPhase13QueryCallbackEi+0x40>
 *   @0x2dc9b4 lsl r3, r0, #1
 *   @0x2dc9b8 lsl r0, r0, #4
 *   @0x2dc9bc str r3, [r4, #0x30]
 *   @0x2dc9c0 ldr r6, [r4, #0x2c]
 *   @0x2dc9c4 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2dc9c8 ldr r2, [r4, #0x34]
 *   @0x2dc9cc mov r1, r6
 *   @0x2dc9d0 lsl r2, r2, #3
 *   @0x2dc9d4 str r0, [r4, #0x2c]
 *   @0x2dc9d8 bl 0xb65bc <memcpy@plt>
 *   @0x2dc9dc mov r0, r6
 *   @0x2dc9e0 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2dc9e4 ldr r0, [r4, #0x34]
 *   @0x2dc9e8 ldr r3, [r4, #0x38]
 *   @0x2dc9ec b 0x2dc978 <_ZN12b2BroadPhase13QueryCallbackEi+0x28>
 *
 * ══ §24/197 F_BUFFER_Peek(RValue&, CInstance*, CInstance*, int, RValue*)  0xc54ac  size 156  39 条（0xc54ac..0xc5548）
 * @func 0xc54ac 0xc5548  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_BUFFER_Peek(RValue&, CInstance*, CInstance*, int, RValue*)+0x80
 * 字段偏移 top8: 0x18×1 / 0x6c×1 / 0x4×1 / 0x2×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc54ac push {r4, r5, r6, r7, r8, lr}
 *   @0xc54b0 mov r1, #0
 *   @0xc54b4 ldr r4, [sp, #0x18]
 *   @0xc54b8 mov r6, r0
 *   @0xc54bc mov r0, r4
 *   @0xc54c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc54c4 cmp r0, #0
 *   @0xc54c8 blt 0xc552c <_Z13F_BUFFER_PeekR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc54cc ldr r1, [pc, #0x6c]
 *   @0xc54d0 add r1, pc, r1
 *   @0xc54d4 ldr r12, [r1]
 *   @0xc54d8 cmp r0, r12
 *   @0xc54dc bge 0xc552c <_Z13F_BUFFER_PeekR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc54e0 ldr r3, [r1, #0x4]
 *   @0xc54e4 ldr r5, [r3, r0, lsl #2]
 *   @0xc54e8 cmp r5, #0
 *   @0xc54ec beq 0xc552c <_Z13F_BUFFER_PeekR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc54f0 ldr r3, [r5]
 *   @0xc54f4 mov r0, r4
 *   @0xc54f8 mov r1, #1
 *   @0xc54fc ldr r7, [r3, #0x14]
 *   @0xc5500 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5504 mov r1, #2
 *   @0xc5508 mov r8, r0
 *   @0xc550c mov r0, r4
 *   @0xc5510 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5514 mov r1, r8
 *   @0xc5518 mov r3, r6
 *   @0xc551c mov r2, r0
 *   @0xc5520 mov r0, r5
 *   @0xc5524 blx r7
 *   @0xc5528 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc552c ldr r0, [pc, #0x10]
 *   @0xc5530 mov r1, #0
 *   @0xc5534 pop {r4, r5, r6, r7, r8, lr}
 *   @0xc5538 add r0, pc, r0
 *   @0xc553c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc5540 eorseq r4, r11, r4, asr #24
 *   @0xc5544 eoreq r11, r6, r12, ror r6
 *
 * ══ §25/197 F_BUFFER_MD5(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5908  size 156  39 条（0xc5908..0xc59a4）
 * @func 0xc5908 0xc59a4  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_BUFFER_MD5(RValue&, CInstance*, CInstance*, int, RValue*)+0x80
 * 字段偏移 top8: 0x18×1 / 0x6c×1 / 0x4×1 / 0x2×1 / 0x2c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5908 push {r4, r5, r6, r7, r8, lr}
 *   @0xc590c mov r1, #0
 *   @0xc5910 ldr r4, [sp, #0x18]
 *   @0xc5914 mov r6, r0
 *   @0xc5918 mov r0, r4
 *   @0xc591c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5920 cmp r0, #0
 *   @0xc5924 blt 0xc5988 <_Z12F_BUFFER_MD5R6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc5928 ldr r2, [pc, #0x6c]
 *   @0xc592c add r2, pc, r2
 *   @0xc5930 ldr r12, [r2]
 *   @0xc5934 cmp r0, r12
 *   @0xc5938 bge 0xc5988 <_Z12F_BUFFER_MD5R6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc593c ldr r2, [r2, #0x4]
 *   @0xc5940 ldr r5, [r2, r0, lsl #2]
 *   @0xc5944 cmp r5, #0
 *   @0xc5948 beq 0xc5988 <_Z12F_BUFFER_MD5R6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc594c ldr r3, [r5]
 *   @0xc5950 mov r0, r4
 *   @0xc5954 mov r1, #1
 *   @0xc5958 ldr r7, [r3, #0x2c]
 *   @0xc595c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5960 mov r1, #2
 *   @0xc5964 mov r8, r0
 *   @0xc5968 mov r0, r4
 *   @0xc596c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5970 mov r1, r6
 *   @0xc5974 mov r2, r8
 *   @0xc5978 mov r3, r0
 *   @0xc597c mov r0, r5
 *   @0xc5980 blx r7
 *   @0xc5984 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc5988 ldr r0, [pc, #0x10]
 *   @0xc598c mov r1, #0
 *   @0xc5990 pop {r4, r5, r6, r7, r8, lr}
 *   @0xc5994 add r0, pc, r0
 *   @0xc5998 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc599c eorseq r4, r11, r8, ror #15
 *   @0xc59a0 eoreq r11, r6, r0, lsr #4
 *
 * ══ §26/197 F_BUFFER_SHA1(RValue&, CInstance*, CInstance*, int, RValue*)  0xc59a4  size 156  39 条（0xc59a4..0xc5a40）
 * @func 0xc59a4 0xc5a40  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_BUFFER_SHA1(RValue&, CInstance*, CInstance*, int, RValue*)+0x80
 * 字段偏移 top8: 0x18×1 / 0x6c×1 / 0x4×1 / 0x2×1 / 0x30×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc59a4 push {r4, r5, r6, r7, r8, lr}
 *   @0xc59a8 mov r1, #0
 *   @0xc59ac ldr r4, [sp, #0x18]
 *   @0xc59b0 mov r6, r0
 *   @0xc59b4 mov r0, r4
 *   @0xc59b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc59bc cmp r0, #0
 *   @0xc59c0 blt 0xc5a24 <_Z13F_BUFFER_SHA1R6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc59c4 ldr r2, [pc, #0x6c]
 *   @0xc59c8 add r2, pc, r2
 *   @0xc59cc ldr r12, [r2]
 *   @0xc59d0 cmp r0, r12
 *   @0xc59d4 bge 0xc5a24 <_Z13F_BUFFER_SHA1R6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc59d8 ldr r2, [r2, #0x4]
 *   @0xc59dc ldr r5, [r2, r0, lsl #2]
 *   @0xc59e0 cmp r5, #0
 *   @0xc59e4 beq 0xc5a24 <_Z13F_BUFFER_SHA1R6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc59e8 ldr r3, [r5]
 *   @0xc59ec mov r0, r4
 *   @0xc59f0 mov r1, #1
 *   @0xc59f4 ldr r7, [r3, #0x30]
 *   @0xc59f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc59fc mov r1, #2
 *   @0xc5a00 mov r8, r0
 *   @0xc5a04 mov r0, r4
 *   @0xc5a08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5a0c mov r1, r6
 *   @0xc5a10 mov r2, r8
 *   @0xc5a14 mov r3, r0
 *   @0xc5a18 mov r0, r5
 *   @0xc5a1c blx r7
 *   @0xc5a20 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc5a24 ldr r0, [pc, #0x10]
 *   @0xc5a28 mov r1, #0
 *   @0xc5a2c pop {r4, r5, r6, r7, r8, lr}
 *   @0xc5a30 add r0, pc, r0
 *   @0xc5a34 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc5a38 eorseq r4, r11, r12, asr #14
 *   @0xc5a3c eoreq r11, r6, r4, lsl #3
 *
 * ══ §27/197 F_BUFFER_Base64_Encode(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5a40  size 156  39 条（0xc5a40..0xc5adc）
 * @func 0xc5a40 0xc5adc  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_BUFFER_Base64_Encode(RValue&, CInstance*, CInstance*, int, RValue*)+0x80
 * 字段偏移 top8: 0x18×1 / 0x6c×1 / 0x4×1 / 0x2×1 / 0x24×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5a40 push {r4, r5, r6, r7, r8, lr}
 *   @0xc5a44 mov r1, #0
 *   @0xc5a48 ldr r4, [sp, #0x18]
 *   @0xc5a4c mov r6, r0
 *   @0xc5a50 mov r0, r4
 *   @0xc5a54 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5a58 cmp r0, #0
 *   @0xc5a5c blt 0xc5ac0 <_Z22F_BUFFER_Base64_EncodeR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc5a60 ldr r2, [pc, #0x6c]
 *   @0xc5a64 add r2, pc, r2
 *   @0xc5a68 ldr r12, [r2]
 *   @0xc5a6c cmp r0, r12
 *   @0xc5a70 bge 0xc5ac0 <_Z22F_BUFFER_Base64_EncodeR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc5a74 ldr r2, [r2, #0x4]
 *   @0xc5a78 ldr r5, [r2, r0, lsl #2]
 *   @0xc5a7c cmp r5, #0
 *   @0xc5a80 beq 0xc5ac0 <_Z22F_BUFFER_Base64_EncodeR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc5a84 ldr r3, [r5]
 *   @0xc5a88 mov r0, r4
 *   @0xc5a8c mov r1, #1
 *   @0xc5a90 ldr r7, [r3, #0x24]
 *   @0xc5a94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5a98 mov r1, #2
 *   @0xc5a9c mov r8, r0
 *   @0xc5aa0 mov r0, r4
 *   @0xc5aa4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5aa8 mov r1, r6
 *   @0xc5aac mov r2, r8
 *   @0xc5ab0 mov r3, r0
 *   @0xc5ab4 mov r0, r5
 *   @0xc5ab8 blx r7
 *   @0xc5abc pop {r4, r5, r6, r7, r8, pc}
 *   @0xc5ac0 ldr r0, [pc, #0x10]
 *   @0xc5ac4 mov r1, #0
 *   @0xc5ac8 pop {r4, r5, r6, r7, r8, lr}
 *   @0xc5acc add r0, pc, r0
 *   @0xc5ad0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc5ad4 ldrhteq r4, [r11], -r0
 *   @0xc5ad8 eoreq r11, r6, r8, ror #1
 *
 * ══ §28/197 IBuffer::Base64encode(RValue*, int, int)  0xcd804  size 156  39 条（0xcd804..0xcd8a0）
 * @func 0xcd804 0xcd8a0  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / IBuffer::SaveToFileInMemory(char**, int*, int, int, int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / base64_encode(char const*, unsigned int, char*) / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x8×2 / 0x-8×1 / 0x4×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcd804 push {r4, r5, lr}
 *   @0xcd808 subs r5, r1, #0
 *   @0xcd80c sub sp, sp, #20
 *   @0xcd810 beq 0xcd894 <_ZN7IBuffer12Base64encodeEP6RValueii+0x90>
 *   @0xcd814 add r1, sp, #16
 *   @0xcd818 mov r12, #0
 *   @0xcd81c str r3, [sp]
 *   @0xcd820 mov r3, r2
 *   @0xcd824 str r12, [r1, #-0x8]!
 *   @0xcd828 add r2, sp, #12
 *   @0xcd82c str r12, [sp, #0x4]
 *   @0xcd830 bl 0xcd660 <_ZN7IBuffer18SaveToFileInMemoryEPPcPiiii>
 *   @0xcd834 ldr r12, [sp, #0xc]
 *   @0xcd838 movw lr, #0x5556
 *   @0xcd83c movt lr, #0x5555
 *   @0xcd840 ldr r1, [pc, #0x54]
 *   @0xcd844 mov r3, #1
 *   @0xcd848 lsl r12, r12, #2
 *   @0xcd84c movw r2, #0x49d
 *   @0xcd850 add r1, pc, r1
 *   @0xcd854 smull r0, lr, lr, r12
 *   @0xcd858 sub r0, lr, r12, asr #31
 *   @0xcd85c add r0, r0, #4
 *   @0xcd860 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xcd864 ldr r1, [sp, #0xc]
 *   @0xcd868 mov r2, r0
 *   @0xcd86c mov r4, r0
 *   @0xcd870 ldr r0, [sp, #0x8]
 *   @0xcd874 bl 0x1d1e60 <_Z13base64_encodePKcjPc>
 *   @0xcd878 mov r0, r5
 *   @0xcd87c mov r1, r4
 *   @0xcd880 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xcd884 mov r0, r4
 *   @0xcd888 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcd88c ldr r0, [sp, #0x8]
 *   @0xcd890 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcd894 add sp, sp, #20
 *   @0xcd898 pop {r4, r5, pc}
 *   @0xcd89c eoreq r4, r6, r0, lsr #18
 *
 * ══ §29/197 DEEP_COPY_RValue(RValue*, RValue const*)  0xd0a88  size 156  39 条（0xd0a88..0xd0b24）
 * @func 0xd0a88 0xd0b24  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CopyRefArrayAndUnref(RefDynamicArrayOfRValue*, void*)
 * 字段偏移 top8: 0xc×3 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd0a88 ldr r3, [r1, #0xc]
 *   @0xd0a8c push {r4, lr}
 *   @0xd0a90 mov r4, r0
 *   @0xd0a94 str r3, [r0, #0xc]
 *   @0xd0a98 ldr r3, [r1, #0xc]
 *   @0xd0a9c bic r3, r3, #-16777216
 *   @0xd0aa0 cmp r3, #10
 *   @0xd0aa4 addls pc, pc, r3, lsl #2
 *   @0xd0aa8 b 0xd0af4 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x6c>
 *   @0xd0aac b 0xd0b04 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x7c>
 *   @0xd0ab0 b 0xd0ad8 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x50>
 *   @0xd0ab4 b 0xd0b10 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x88>
 *   @0xd0ab8 b 0xd0af8 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x70>
 *   @0xd0abc b 0xd0af4 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x6c>
 *   @0xd0ac0 b 0xd0af4 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x6c>
 *   @0xd0ac4 b 0xd0af4 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x6c>
 *   @0xd0ac8 b 0xd0af8 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x70>
 *   @0xd0acc b 0xd0af4 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x6c>
 *   @0xd0ad0 b 0xd0af4 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x6c>
 *   @0xd0ad4 b 0xd0b04 <_Z16DEEP_COPY_RValueP6RValuePKS_+0x7c>
 *   @0xd0ad8 ldr r3, [r1]
 *   @0xd0adc cmp r3, #0
 *   @0xd0ae0 str r3, [r0]
 *   @0xd0ae4 popeq {r4, pc}
 *   @0xd0ae8 ldr r2, [r3, #0x4]
 *   @0xd0aec add r2, r2, #1
 *   @0xd0af0 str r2, [r3, #0x4]
 *   @0xd0af4 pop {r4, pc}
 *   @0xd0af8 ldr r3, [r1]
 *   @0xd0afc str r3, [r0]
 *   @0xd0b00 pop {r4, pc}
 *   @0xd0b04 ldm r1, {r2, r3}
 *   @0xd0b08 stm r0, {r2, r3}
 *   @0xd0b0c pop {r4, pc}
 *   @0xd0b10 ldr r0, [r1]
 *   @0xd0b14 mov r1, r4
 *   @0xd0b18 bl 0xd064c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv>
 *   @0xd0b1c str r0, [r4]
 *   @0xd0b20 pop {r4, pc}
 *
 * ══ §30/197 F_DsMapDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0xff7f4  size 156  39 条（0xff7f4..0xff890）
 * @func 0xff7f4 0xff890  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapDelete(RValue&, CInstance*, CInstance*, int, RValue*)+0x70 / CDS_Map::Delete(RValue*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x18×1 / 0x5c×1 / 0x4c×1 / 0x4×1 / 0x2×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xff7f4 push {r4, r5, lr}
 *   @0xff7f8 sub sp, sp, #12
 *   @0xff7fc add r4, sp, #4
 *   @0xff800 ldr r5, [sp, #0x18]
 *   @0xff804 mov r0, r4
 *   @0xff808 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xff80c mov r1, #0
 *   @0xff810 mov r0, r5
 *   @0xff814 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xff818 cmp r0, #0
 *   @0xff81c blt 0xff864 <_Z13F_DsMapDeleteR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xff820 ldr r3, [pc, #0x5c]
 *   @0xff824 ldr r3, [pc, r3]
 *   @0xff828 ldr r3, [r3]
 *   @0xff82c cmp r0, r3
 *   @0xff830 bge 0xff864 <_Z13F_DsMapDeleteR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xff834 ldr r3, [pc, #0x4c]
 *   @0xff838 ldr r3, [pc, r3]
 *   @0xff83c ldr r3, [r3, #0x4]
 *   @0xff840 ldr r0, [r3, r0, lsl #2]
 *   @0xff844 cmp r0, #0
 *   @0xff848 beq 0xff864 <_Z13F_DsMapDeleteR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xff84c add r1, r5, #16
 *   @0xff850 bl 0x20b6cc <_ZN7CDS_Map6DeleteEP6RValue>
 *   @0xff854 mov r0, r4
 *   @0xff858 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff85c add sp, sp, #12
 *   @0xff860 pop {r4, r5, pc}
 *   @0xff864 ldr r0, [pc, #0x20]
 *   @0xff868 mov r1, #0
 *   @0xff86c add r0, pc, r0
 *   @0xff870 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff874 mov r0, r4
 *   @0xff878 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff87c add sp, sp, #12
 *   @0xff880 pop {r4, r5, pc}
 *   @0xff884 eoreq lr, lr, r4, asr r4
 *   @0xff888 eoreq lr, lr, r4, lsl #2
 *   @0xff88c mlaeq r3, r0, r3, r8
 *
 * ══ §31/197 YYGML_ds_map_add(int, YYRValue const&, YYRValue const&)  0x1001a8  size 156  39 条（0x1001a8..0x100244）
 * @func 0x1001a8 0x100244  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::DS_AutoMutex() / YYGML_ds_map_add(int, YYRValue const&, YYRValue const&)+0x68 / CDS_Map::Add(RValue*, RValue*) / YYError(char const*, ...) / DS_AutoMutex::~DS_AutoMutex()
 * 字段偏移 top8: 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1001a8 push {r4, r5, r6, r7, lr}
 *   @0x1001ac sub sp, sp, #12
 *   @0x1001b0 add r5, sp, #4
 *   @0x1001b4 mov r4, r0
 *   @0x1001b8 mov r7, r1
 *   @0x1001bc mov r6, r2
 *   @0x1001c0 mov r0, r5
 *   @0x1001c4 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x1001c8 cmp r4, #0
 *   @0x1001cc blt 0x100210 <_Z16YYGML_ds_map_addiRK8YYRValueS1_+0x68>
 *   @0x1001d0 ldr r3, [pc, #0x60]
 *   @0x1001d4 ldr r3, [pc, r3]
 *   @0x1001d8 ldr r3, [r3]
 *   @0x1001dc cmp r4, r3
 *   @0x1001e0 bge 0x100210 <_Z16YYGML_ds_map_addiRK8YYRValueS1_+0x68>
 *   @0x1001e4 ldr r3, [pc, #0x50]
 *   @0x1001e8 ldr r3, [pc, r3]
 *   @0x1001ec ldr r3, [r3, #0x4]
 *   @0x1001f0 ldr r0, [r3, r4, lsl #2]
 *   @0x1001f4 cmp r0, #0
 *   @0x1001f8 beq 0x100210 <_Z16YYGML_ds_map_addiRK8YYRValueS1_+0x68>
 *   @0x1001fc mov r1, r7
 *   @0x100200 mov r2, r6
 *   @0x100204 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x100208 mov r4, r0
 *   @0x10020c b 0x100224 <_Z16YYGML_ds_map_addiRK8YYRValueS1_+0x7c>
 *   @0x100210 ldr r0, [pc, #0x28]
 *   @0x100214 mov r1, r4
 *   @0x100218 mov r4, #0
 *   @0x10021c add r0, pc, r0
 *   @0x100220 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x100224 mov r0, r5
 *   @0x100228 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x10022c mov r0, r4
 *   @0x100230 add sp, sp, #12
 *   @0x100234 pop {r4, r5, r6, r7, pc}
 *   @0x100238 eoreq sp, lr, r4, lsr #21
 *   @0x10023c eoreq sp, lr, r4, asr r7
 *   @0x100240 eoreq r7, r3, r12, lsr #21
 *
 * ══ §32/197 F_MpLinearStep(RValue&, CInstance*, CInstance*, int, RValue*)  0x108900  size 156  39 条（0x108900..0x10899c）
 * @func 0x108900 0x10899c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetBool(RValue const*, int) / Motion_Linear_Step(CInstance*, float, float, float, int, bool)
 * 字段偏移 top8: 0x4×2 / 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108900 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x108904 sub sp, sp, #8
 *   @0x108908 mov r6, #0
 *   @0x10890c mov r5, r0
 *   @0x108910 ldr r4, [sp, #0x28]
 *   @0x108914 mov r7, r1
 *   @0x108918 str r6, [r0, #0xc]
 *   @0x10891c mov r1, r6
 *   @0x108920 mov r0, r4
 *   @0x108924 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108928 mov r1, #1
 *   @0x10892c mov r10, r0
 *   @0x108930 mov r0, r4
 *   @0x108934 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108938 mov r1, #2
 *   @0x10893c mov r9, r0
 *   @0x108940 mov r0, r4
 *   @0x108944 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108948 mov r1, #3
 *   @0x10894c mov r8, r0
 *   @0x108950 mov r0, r4
 *   @0x108954 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x108958 mov r3, r8
 *   @0x10895c mvn r12, #2
 *   @0x108960 mov r1, r10
 *   @0x108964 mov r2, r9
 *   @0x108968 str r12, [sp]
 *   @0x10896c str r0, [sp, #0x4]
 *   @0x108970 mov r0, r7
 *   @0x108974 bl 0x19c8a8 <_Z18Motion_Linear_StepP9CInstancefffib>
 *   @0x108978 cmp r0, #0
 *   @0x10897c moveq r6, r0
 *   @0x108980 movne r3, r6
 *   @0x108984 moveq r3, r6
 *   @0x108988 movtne r3, #0x3ff0
 *   @0x10898c str r6, [r5]
 *   @0x108990 str r3, [r5, #0x4]
 *   @0x108994 add sp, sp, #8
 *   @0x108998 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §33/197 F_ArrayCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x10dd40  size 156  39 条（0x10dd40..0x10dddc）
 * @func 0x10dd40 0x10dddc  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue_Array(RValue*, RValue*, int)×2 / ARRAY_RefAlloc(void*) / YYGetInt32(RValue const*, int) / F_ArrayCreate(RValue&, CInstance*, CInstance*, int, RValue*)+0x64 / F_ArrayCreate(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c
 * 字段偏移 top8: 0xc×2 / 0x28×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10dd40 push {r4, r5, r6, r7, lr}
 *   @0x10dd44 sub sp, sp, #20
 *   @0x10dd48 mov r2, #2
 *   @0x10dd4c str r2, [r0, #0xc]
 *   @0x10dd50 mov r5, r0
 *   @0x10dd54 mov r7, r3
 *   @0x10dd58 ldr r6, [sp, #0x28]
 *   @0x10dd5c bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x10dd60 mov r1, #0
 *   @0x10dd64 str r0, [r5]
 *   @0x10dd68 mov r0, r6
 *   @0x10dd6c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10dd70 subs r2, r0, #0
 *   @0x10dd74 ble 0x10dda4 <_Z13F_ArrayCreateR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x10dd78 cmp r7, #1
 *   @0x10dd7c ble 0x10ddac <_Z13F_ArrayCreateR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x10dd80 sub r4, r2, #1
 *   @0x10dd84 add r6, r6, #16
 *   @0x10dd88 mov r2, r4
 *   @0x10dd8c mov r0, r5
 *   @0x10dd90 mov r1, r6
 *   @0x10dd94 sub r4, r4, #1
 *   @0x10dd98 bl 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i>
 *   @0x10dd9c cmn r4, #1
 *   @0x10dda0 bne 0x10dd88 <_Z13F_ArrayCreateR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x10dda4 add sp, sp, #20
 *   @0x10dda8 pop {r4, r5, r6, r7, pc}
 *   @0x10ddac mov r0, r5
 *   @0x10ddb0 sub r2, r2, #1
 *   @0x10ddb4 mov r1, sp
 *   @0x10ddb8 mov r3, #0
 *   @0x10ddbc mov r4, #0
 *   @0x10ddc0 mov r5, #0
 *   @0x10ddc4 str r3, [sp, #0x8]
 *   @0x10ddc8 strd r4, r5, [sp]
 *   @0x10ddcc str r3, [sp, #0xc]
 *   @0x10ddd0 bl 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i>
 *   @0x10ddd4 add sp, sp, #20
 *   @0x10ddd8 pop {r4, r5, r6, r7, pc}
 *
 * ══ §34/197 F_PointDistance(RValue&, CInstance*, CInstance*, int, RValue*)  0x10eff4  size 156  39 条（0x10eff4..0x10f090）
 * @func 0x10eff4 0x10f090  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / 0xb6700
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10eff4 push {r4, r5, r6, lr}
 *   @0x10eff8 vpush {d8}
 *   @0x10effc mov r6, #0
 *   @0x10f000 ldr r4, [sp, #0x18]
 *   @0x10f004 mov r1, #2
 *   @0x10f008 str r6, [r0, #0xc]
 *   @0x10f00c mov r5, r0
 *   @0x10f010 mov r0, r4
 *   @0x10f014 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f018 mov r1, r6
 *   @0x10f01c vmov s16, r0
 *   @0x10f020 mov r0, r4
 *   @0x10f024 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f028 mov r1, #3
 *   @0x10f02c vmov s12, r0
 *   @0x10f030 mov r0, r4
 *   @0x10f034 vsub.f32 s16, s16, s12
 *   @0x10f038 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f03c mov r1, #1
 *   @0x10f040 vmov s17, r0
 *   @0x10f044 mov r0, r4
 *   @0x10f048 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f04c vmov s13, r0
 *   @0x10f050 vsub.f32 s14, s17, s13
 *   @0x10f054 vmul.f32 s14, s14, s14
 *   @0x10f058 vmla.f32 s14, s16, s16
 *   @0x10f05c vsqrt.f32 s15, s14
 *   @0x10f060 vcmp.f32 s15, s15
 *   @0x10f064 vmrs APSR_nzcv, fpscr
 *   @0x10f068 bne 0x10f080 <_Z15F_PointDistanceR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x10f06c vcvt.f64.f32 d6, s15
 *   @0x10f070 vmov r2, r3, d6
 *   @0x10f074 stm r5, {r2, r3}
 *   @0x10f078 vpop {d8}
 *   @0x10f07c pop {r4, r5, r6, pc}
 *   @0x10f080 vmov r0, s14
 *   @0x10f084 bl 0xb6700 <sqrtf@plt>
 *   @0x10f088 vmov s15, r0
 *   @0x10f08c b 0x10f06c <_Z15F_PointDistanceR6RValueP9CInstanceS2_iPS_+0x78>
 *
 * ══ §35/197 F_ObjectGetSolid(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ab68  size 156  39 条（0x12ab68..0x12ac04）
 * @func 0x12ab68 0x12ac04  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0xc×3 / 0x8×2 / 0x7c×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ab68 push {r4, lr}
 *   @0x12ab6c mov r1, #0
 *   @0x12ab70 mov r4, r0
 *   @0x12ab74 ldr r0, [sp, #0x8]
 *   @0x12ab78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ab7c ldr r3, [pc, #0x7c]
 *   @0x12ab80 ldr r3, [pc, r3]
 *   @0x12ab84 ldr r3, [r3]
 *   @0x12ab88 ldr r2, [r3, #0x4]
 *   @0x12ab8c ldr r3, [r3]
 *   @0x12ab90 and r2, r0, r2
 *   @0x12ab94 ldr r3, [r3, r2, lsl #3]
 *   @0x12ab98 cmp r3, #0
 *   @0x12ab9c bne 0x12abb0 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12aba0 b 0x12abe8 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12aba4 ldr r3, [r3, #0x4]
 *   @0x12aba8 cmp r3, #0
 *   @0x12abac beq 0x12abe8 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12abb0 ldr r2, [r3, #0x8]
 *   @0x12abb4 cmp r0, r2
 *   @0x12abb8 bne 0x12aba4 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12abbc ldr r3, [r3, #0xc]
 *   @0x12abc0 cmp r3, #0
 *   @0x12abc4 beq 0x12abe8 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12abc8 ldr r3, [r3]
 *   @0x12abcc tst r3, #1
 *   @0x12abd0 beq 0x12abe8 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12abd4 mov r3, #0
 *   @0x12abd8 str r3, [r4, #0xc]
 *   @0x12abdc mov r2, r3
 *   @0x12abe0 movt r2, #0x3ff0
 *   @0x12abe4 b 0x12abf4 <_Z16F_ObjectGetSolidR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x12abe8 mov r3, #0
 *   @0x12abec str r3, [r4, #0xc]
 *   @0x12abf0 mov r2, r3
 *   @0x12abf4 str r3, [r4]
 *   @0x12abf8 str r2, [r4, #0x4]
 *   @0x12abfc pop {r4, pc}
 *   @0x12ac00 strhteq r3, [r12], -r12
 *
 * ══ §36/197 F_ObjectGetVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ac04  size 156  39 条（0x12ac04..0x12aca0）
 * @func 0x12ac04 0x12aca0  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0xc×3 / 0x8×2 / 0x7c×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ac04 push {r4, lr}
 *   @0x12ac08 mov r1, #0
 *   @0x12ac0c mov r4, r0
 *   @0x12ac10 ldr r0, [sp, #0x8]
 *   @0x12ac14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ac18 ldr r3, [pc, #0x7c]
 *   @0x12ac1c ldr r3, [pc, r3]
 *   @0x12ac20 ldr r3, [r3]
 *   @0x12ac24 ldr r2, [r3, #0x4]
 *   @0x12ac28 ldr r3, [r3]
 *   @0x12ac2c and r2, r0, r2
 *   @0x12ac30 ldr r3, [r3, r2, lsl #3]
 *   @0x12ac34 cmp r3, #0
 *   @0x12ac38 bne 0x12ac4c <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12ac3c b 0x12ac84 <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12ac40 ldr r3, [r3, #0x4]
 *   @0x12ac44 cmp r3, #0
 *   @0x12ac48 beq 0x12ac84 <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12ac4c ldr r2, [r3, #0x8]
 *   @0x12ac50 cmp r0, r2
 *   @0x12ac54 bne 0x12ac40 <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12ac58 ldr r3, [r3, #0xc]
 *   @0x12ac5c cmp r3, #0
 *   @0x12ac60 beq 0x12ac84 <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12ac64 ldr r3, [r3]
 *   @0x12ac68 tst r3, #2
 *   @0x12ac6c beq 0x12ac84 <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12ac70 mov r3, #0
 *   @0x12ac74 str r3, [r4, #0xc]
 *   @0x12ac78 mov r2, r3
 *   @0x12ac7c movt r2, #0x3ff0
 *   @0x12ac80 b 0x12ac90 <_Z18F_ObjectGetVisibleR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x12ac84 mov r3, #0
 *   @0x12ac88 str r3, [r4, #0xc]
 *   @0x12ac8c mov r2, r3
 *   @0x12ac90 str r3, [r4]
 *   @0x12ac94 str r2, [r4, #0x4]
 *   @0x12ac98 pop {r4, pc}
 *   @0x12ac9c eoreq r3, r12, r0, lsr #32
 *
 * ══ §37/197 F_ObjectGetPersistent(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ad34  size 156  39 条（0x12ad34..0x12add0）
 * @func 0x12ad34 0x12add0  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0xc×3 / 0x8×2 / 0x7c×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ad34 push {r4, lr}
 *   @0x12ad38 mov r1, #0
 *   @0x12ad3c mov r4, r0
 *   @0x12ad40 ldr r0, [sp, #0x8]
 *   @0x12ad44 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ad48 ldr r3, [pc, #0x7c]
 *   @0x12ad4c ldr r3, [pc, r3]
 *   @0x12ad50 ldr r3, [r3]
 *   @0x12ad54 ldr r2, [r3, #0x4]
 *   @0x12ad58 ldr r3, [r3]
 *   @0x12ad5c and r2, r0, r2
 *   @0x12ad60 ldr r3, [r3, r2, lsl #3]
 *   @0x12ad64 cmp r3, #0
 *   @0x12ad68 bne 0x12ad7c <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12ad6c b 0x12adb4 <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12ad70 ldr r3, [r3, #0x4]
 *   @0x12ad74 cmp r3, #0
 *   @0x12ad78 beq 0x12adb4 <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12ad7c ldr r2, [r3, #0x8]
 *   @0x12ad80 cmp r0, r2
 *   @0x12ad84 bne 0x12ad70 <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12ad88 ldr r3, [r3, #0xc]
 *   @0x12ad8c cmp r3, #0
 *   @0x12ad90 beq 0x12adb4 <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12ad94 ldr r3, [r3]
 *   @0x12ad98 tst r3, #4
 *   @0x12ad9c beq 0x12adb4 <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12ada0 mov r3, #0
 *   @0x12ada4 str r3, [r4, #0xc]
 *   @0x12ada8 mov r2, r3
 *   @0x12adac movt r2, #0x3ff0
 *   @0x12adb0 b 0x12adc0 <_Z21F_ObjectGetPersistentR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x12adb4 mov r3, #0
 *   @0x12adb8 str r3, [r4, #0xc]
 *   @0x12adbc mov r2, r3
 *   @0x12adc0 str r3, [r4]
 *   @0x12adc4 str r2, [r4, #0x4]
 *   @0x12adc8 pop {r4, pc}
 *   @0x12adcc .word 0x002c2ef0
 *
 * ══ §38/197 F_SpriteDuplicate(RValue&, CInstance*, CInstance*, int, RValue*)  0x13001c  size 156  39 条（0x13001c..0x1300b8）
 * @func 0x13001c 0x1300b8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Sprite_Data(int) / Sprite_Duplicate(int)
 * 字段偏移 top8: 0x10×2 / 0x74×1 / 0xc×1 / 0x30×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13001c push {r3, r4, r5, lr}
 *   @0x130020 mov r1, #0
 *   @0x130024 mov r4, r0
 *   @0x130028 ldr r0, [sp, #0x10]
 *   @0x13002c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130030 mov r5, r0
 *   @0x130034 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x130038 cmp r0, #0
 *   @0x13003c beq 0x13008c <_Z17F_SpriteDuplicateR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x130040 ldr r3, [r0, #0x74]
 *   @0x130044 cmp r3, #1
 *   @0x130048 beq 0x13009c <_Z17F_SpriteDuplicateR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x13004c cmp r3, #2
 *   @0x130050 beq 0x130078 <_Z17F_SpriteDuplicateR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x130054 mov r0, r5
 *   @0x130058 bl 0x1f07f0 <_Z16Sprite_Duplicatei>
 *   @0x13005c vmov s15, r0
 *   @0x130060 vcvt.f64.s32 d7, s15
 *   @0x130064 vmov r2, r3, d7
 *   @0x130068 mov r1, #0
 *   @0x13006c stm r4, {r2, r3}
 *   @0x130070 str r1, [r4, #0xc]
 *   @0x130074 pop {r3, r4, r5, pc}
 *   @0x130078 ldr r0, [pc, #0x30]
 *   @0x13007c mov r1, #0
 *   @0x130080 pop {r3, r4, r5, lr}
 *   @0x130084 add r0, pc, r0
 *   @0x130088 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13008c mov r3, #0
 *   @0x130090 mov r2, #0
 *   @0x130094 movt r3, #0xbff0
 *   @0x130098 b 0x130068 <_Z17F_SpriteDuplicateR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x13009c ldr r0, [pc, #0x10]
 *   @0x1300a0 mov r1, #0
 *   @0x1300a4 pop {r3, r4, r5, lr}
 *   @0x1300a8 add r0, pc, r0
 *   @0x1300ac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1300b0 eoreq sp, r0, r8, asr #23
 *   @0x1300b4 eoreq sp, r0, r0, ror r11
 *
 * ══ §39/197 F_Sound3DSetSoundDistance(RValue&, CInstance*, CInstance*, int, RValue*)  0x13629c  size 156  39 条（0x13629c..0x136338）
 * @func 0x13629c 0x136338  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Sound_Data(int) / CSound::GetSoundId() / SND_3D_Set_Sound_Distance(int, double, double)
 * 字段偏移 top8: 0x8c×1 / 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13629c ldr r3, [pc, #0x8c]
 *   @0x1362a0 push {r4, r5, r6, r7, lr}
 *   @0x1362a4 ldr r3, [pc, r3]
 *   @0x1362a8 sub sp, sp, #12
 *   @0x1362ac ldrb r1, [r3]
 *   @0x1362b0 ldr r6, [sp, #0x20]
 *   @0x1362b4 cmp r1, #0
 *   @0x1362b8 beq 0x1362c4 <_Z25F_Sound3DSetSoundDistanceR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x1362bc add sp, sp, #12
 *   @0x1362c0 pop {r4, r5, r6, r7, pc}
 *   @0x1362c4 mov r0, r6
 *   @0x1362c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1362cc bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x1362d0 subs r1, r0, #0
 *   @0x1362d4 beq 0x13631c <_Z25F_Sound3DSetSoundDistanceR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1362d8 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x1362dc mov r1, #1
 *   @0x1362e0 mov r7, r0
 *   @0x1362e4 mov r0, r6
 *   @0x1362e8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1362ec mov r4, r0
 *   @0x1362f0 mov r5, r1
 *   @0x1362f4 mov r0, r6
 *   @0x1362f8 mov r1, #2
 *   @0x1362fc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x136300 mov r2, r4
 *   @0x136304 mov r3, r5
 *   @0x136308 strd r0, r1, [sp]
 *   @0x13630c mov r0, r7
 *   @0x136310 bl 0x21f174 <_Z25SND_3D_Set_Sound_Distanceidd>
 *   @0x136314 add sp, sp, #12
 *   @0x136318 pop {r4, r5, r6, r7, pc}
 *   @0x13631c ldr r0, [pc, #0x10]
 *   @0x136320 add r0, pc, r0
 *   @0x136324 add sp, sp, #12
 *   @0x136328 pop {r4, r5, r6, r7, lr}
 *   @0x13632c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x136330 eoreq r8, r11, r8, lsr #27
 *   @0x136334 eoreq r9, r0, r12, ror #2
 *
 * ══ §40/197 DSMapToJSON(int, char**)  0x13c1d8  size 156  39 条（0x13c1d8..0x13c274）
 * @func 0x13c1d8 0x13c274  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DSMapToJSON(int, char**)+0x28 / DSMapToJSON(int, char**)+0x30 / DS_AutoMutex::DS_AutoMutex() / EncodeDSMap(CDS_Map*) / YYFree(void const*) / json_object_to_json_string / YYStrDup(char const*) / json_object_put
 * 字段偏移 top8: 0x78×1 / 0x54×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13c1d8 push {r4, r5, r6, lr}
 *   @0x13c1dc subs r4, r0, #0
 *   @0x13c1e0 sub sp, sp, #8
 *   @0x13c1e4 mov r5, r1
 *   @0x13c1e8 blt 0x13c200 <_Z11DSMapToJSONiPPc+0x28>
 *   @0x13c1ec ldr r3, [pc, #0x78]
 *   @0x13c1f0 ldr r3, [pc, r3]
 *   @0x13c1f4 ldr r3, [r3]
 *   @0x13c1f8 cmp r4, r3
 *   @0x13c1fc blt 0x13c208 <_Z11DSMapToJSONiPPc+0x30>
 *   @0x13c200 add sp, sp, #8
 *   @0x13c204 pop {r4, r5, r6, pc}
 *   @0x13c208 add r6, sp, #4
 *   @0x13c20c mov r0, r6
 *   @0x13c210 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x13c214 ldr r3, [pc, #0x54]
 *   @0x13c218 ldr r3, [pc, r3]
 *   @0x13c21c ldr r3, [r3, #0x4]
 *   @0x13c220 ldr r0, [r3, r4, lsl #2]
 *   @0x13c224 cmp r0, #0
 *   @0x13c228 beq 0x13c25c <_Z11DSMapToJSONiPPc+0x84>
 *   @0x13c22c bl 0x13bcec <_Z11EncodeDSMapP7CDS_Map>
 *   @0x13c230 mov r4, r0
 *   @0x13c234 ldr r0, [r5]
 *   @0x13c238 cmp r0, #0
 *   @0x13c23c beq 0x13c244 <_Z11DSMapToJSONiPPc+0x6c>
 *   @0x13c240 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x13c244 mov r0, r4
 *   @0x13c248 bl 0x27e830 <json_object_to_json_string>
 *   @0x13c24c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x13c250 str r0, [r5]
 *   @0x13c254 mov r0, r4
 *   @0x13c258 bl 0x27e7c8 <json_object_put>
 *   @0x13c25c mov r0, r6
 *   @0x13c260 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x13c264 add sp, sp, #8
 *   @0x13c268 pop {r4, r5, r6, pc}
 *   @0x13c26c eoreq r1, r11, r8, lsl #21
 *   @0x13c270 eoreq r1, r11, r4, lsr #14
 *
 * ══ §41/197 F_ActionIfMouse(RValue&, CInstance*, CInstance*, int, RValue*)  0x140b80  size 156  39 条（0x140b80..0x140c1c）
 * @func 0x140b80 0x140c1c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / IO_Button_Current_Get(int) / IO_Button_Down(int, int) / IO_Button_Released(int, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140b80 push {r3, r4, r5, r6, r7, lr}
 *   @0x140b84 mov r1, #0
 *   @0x140b88 mov r4, r0
 *   @0x140b8c ldr r0, [sp, #0x18]
 *   @0x140b90 mov r5, r1
 *   @0x140b94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140b98 str r5, [r4, #0xc]
 *   @0x140b9c cmp r0, #2
 *   @0x140ba0 mov r6, r0
 *   @0x140ba4 beq 0x140be4 <_Z15F_ActionIfMouseR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x140ba8 cmp r0, #3
 *   @0x140bac beq 0x140be4 <_Z15F_ActionIfMouseR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x140bb0 cmp r0, #1
 *   @0x140bb4 beq 0x140be4 <_Z15F_ActionIfMouseR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x140bb8 mov r0, r5
 *   @0x140bbc bl 0x18c048 <_Z21IO_Button_Current_Geti>
 *   @0x140bc0 cmp r0, #0
 *   @0x140bc4 movne r3, r5
 *   @0x140bc8 bne 0x140bd8 <_Z15F_ActionIfMouseR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x140bcc mov r5, r0
 *   @0x140bd0 mov r3, #0
 *   @0x140bd4 movt r3, #0x3ff0
 *   @0x140bd8 str r5, [r4]
 *   @0x140bdc str r3, [r4, #0x4]
 *   @0x140be0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x140be4 mov r1, r5
 *   @0x140be8 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x140bec subs r7, r0, #0
 *   @0x140bf0 bne 0x140bd0 <_Z15F_ActionIfMouseR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x140bf4 mov r0, r6
 *   @0x140bf8 mov r1, r7
 *   @0x140bfc bl 0x18c12c <_Z18IO_Button_Releasedii>
 *   @0x140c00 cmp r0, #0
 *   @0x140c04 moveq r5, r0
 *   @0x140c08 movne r3, #0
 *   @0x140c0c moveq r3, r5
 *   @0x140c10 movtne r3, #0x3ff0
 *   @0x140c14 movne r5, r7
 *   @0x140c18 b 0x140bd8 <_Z15F_ActionIfMouseR6RValueP9CInstanceS2_iPS_+0x58>
 *
 * ══ §42/197 F_PhysicsDestroyParticleRegionBox(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d43c  size 156  39 条（0x14d43c..0x14d4d8）
 * @func 0x14d43c 0x14d4d8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4
 * 字段偏移 top8: 0x18×2 / 0x8c×1 / 0xb4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d43c ldr r3, [pc, #0x8c]
 *   @0x14d440 push {r4, r5, r6, r7, r8, lr}
 *   @0x14d444 ldr r3, [pc, r3]
 *   @0x14d448 ldr r4, [sp, #0x18]
 *   @0x14d44c ldr r3, [r3]
 *   @0x14d450 cmp r3, #0
 *   @0x14d454 beq 0x14d4bc <_Z33F_PhysicsDestroyParticleRegionBoxR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x14d458 ldr r5, [r3, #0xb4]
 *   @0x14d45c cmp r5, #0
 *   @0x14d460 beq 0x14d4bc <_Z33F_PhysicsDestroyParticleRegionBoxR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x14d464 mov r0, r4
 *   @0x14d468 mov r1, #0
 *   @0x14d46c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d470 mov r1, #1
 *   @0x14d474 mov r8, r0
 *   @0x14d478 mov r0, r4
 *   @0x14d47c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d480 mov r1, #2
 *   @0x14d484 mov r7, r0
 *   @0x14d488 mov r0, r4
 *   @0x14d48c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d490 mov r1, #3
 *   @0x14d494 mov r6, r0
 *   @0x14d498 mov r0, r4
 *   @0x14d49c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14d4a0 mov r1, r8
 *   @0x14d4a4 mov r2, r7
 *   @0x14d4a8 mov r3, r6
 *   @0x14d4ac str r0, [sp, #0x18]
 *   @0x14d4b0 mov r0, r5
 *   @0x14d4b4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14d4b8 b 0x239fd0 <_ZN13CPhysicsWorld23DeleteParticleBoxRegionEffff>
 *   @0x14d4bc ldr r0, [pc, #0x10]
 *   @0x14d4c0 mov r1, #0
 *   @0x14d4c4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14d4c8 add r0, pc, r0
 *   @0x14d4cc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d4d0 eoreq r0, r10, r4, ror #9
 *   @0x14d4d4 andseq r6, pc, r8, ror #23
 *
 * ══ §43/197 F_GamepadButtonCheck(RValue&, CInstance*, CInstance*, int, RValue*)  0x1514b4  size 156  39 条（0x1514b4..0x151550）
 * @func 0x1514b4 0x151550  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / anon_15149c / TranslateGamepadButtonM(int, int) / GMGamePad::ButtonDown(int) const
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x30×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1514b4 push {r4, r5, r6, lr}
 *   @0x1514b8 mov r4, #0
 *   @0x1514bc ldr r6, [sp, #0x10]
 *   @0x1514c0 mov r5, r0
 *   @0x1514c4 str r4, [r0, #0xc]
 *   @0x1514c8 str r4, [r0]
 *   @0x1514cc str r4, [r0, #0x4]
 *   @0x1514d0 bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1514d4 mov r1, r4
 *   @0x1514d8 mov r0, r6
 *   @0x1514dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1514e0 subs r4, r0, #0
 *   @0x1514e4 poplt {r4, r5, r6, pc}
 *   @0x1514e8 ldr r3, [pc, #0x58]
 *   @0x1514ec ldr r3, [pc, r3]
 *   @0x1514f0 ldr r3, [r3]
 *   @0x1514f4 cmp r4, r3
 *   @0x1514f8 popge {r4, r5, r6, pc}
 *   @0x1514fc mov r1, #1
 *   @0x151500 mov r0, r6
 *   @0x151504 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x151508 mov r1, r0
 *   @0x15150c mov r0, r4
 *   @0x151510 bl 0x190acc <_Z23TranslateGamepadButtonMii>
 *   @0x151514 ldr r3, [pc, #0x30]
 *   @0x151518 ldr r3, [pc, r3]
 *   @0x15151c ldr r3, [r3]
 *   @0x151520 mov r1, r0
 *   @0x151524 ldr r0, [r3, r4, lsl #2]
 *   @0x151528 bl 0x18eb5c <_ZNK9GMGamePad10ButtonDownEi>
 *   @0x15152c vmov s15, r0
 *   @0x151530 vcvt.f64.u32 d7, s15
 *   @0x151534 vmov r0, r1, d7
 *   @0x151538 vmov r2, s14
 *   @0x15153c mov r3, r1
 *   @0x151540 stm r5, {r2, r3}
 *   @0x151544 pop {r4, r5, r6, pc}
 *   @0x151548 eoreq lr, r9, r4, ror r5
 *   @0x15154c eoreq lr, r9, r12, asr #10
 *
 * ══ §44/197 F_GamepadButtonCheckPressed(RValue&, CInstance*, CInstance*, int, RValue*)  0x151550  size 156  39 条（0x151550..0x1515ec）
 * @func 0x151550 0x1515ec  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / anon_15149c / TranslateGamepadButtonM(int, int) / GMGamePad::ButtonPressed(int) const
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x30×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x151550 push {r4, r5, r6, lr}
 *   @0x151554 mov r4, #0
 *   @0x151558 ldr r6, [sp, #0x10]
 *   @0x15155c mov r5, r0
 *   @0x151560 str r4, [r0, #0xc]
 *   @0x151564 str r4, [r0]
 *   @0x151568 str r4, [r0, #0x4]
 *   @0x15156c bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x151570 mov r1, r4
 *   @0x151574 mov r0, r6
 *   @0x151578 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15157c subs r4, r0, #0
 *   @0x151580 poplt {r4, r5, r6, pc}
 *   @0x151584 ldr r3, [pc, #0x58]
 *   @0x151588 ldr r3, [pc, r3]
 *   @0x15158c ldr r3, [r3]
 *   @0x151590 cmp r4, r3
 *   @0x151594 popge {r4, r5, r6, pc}
 *   @0x151598 mov r1, #1
 *   @0x15159c mov r0, r6
 *   @0x1515a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1515a4 mov r1, r0
 *   @0x1515a8 mov r0, r4
 *   @0x1515ac bl 0x190acc <_Z23TranslateGamepadButtonMii>
 *   @0x1515b0 ldr r3, [pc, #0x30]
 *   @0x1515b4 ldr r3, [pc, r3]
 *   @0x1515b8 ldr r3, [r3]
 *   @0x1515bc mov r1, r0
 *   @0x1515c0 ldr r0, [r3, r4, lsl #2]
 *   @0x1515c4 bl 0x18ebd8 <_ZNK9GMGamePad13ButtonPressedEi>
 *   @0x1515c8 vmov s15, r0
 *   @0x1515cc vcvt.f64.u32 d7, s15
 *   @0x1515d0 vmov r0, r1, d7
 *   @0x1515d4 vmov r2, s14
 *   @0x1515d8 mov r3, r1
 *   @0x1515dc stm r5, {r2, r3}
 *   @0x1515e0 pop {r4, r5, r6, pc}
 *   @0x1515e4 .word 0x0029e4d8
 *   @0x1515e8 .word 0x0029e4b0
 *
 * ══ §45/197 F_GamepadButtonCheckReleased(RValue&, CInstance*, CInstance*, int, RValue*)  0x1515ec  size 156  39 条（0x1515ec..0x151688）
 * @func 0x1515ec 0x151688  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / anon_15149c / TranslateGamepadButtonM(int, int) / GMGamePad::ButtonReleased(int) const
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x30×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1515ec push {r4, r5, r6, lr}
 *   @0x1515f0 mov r4, #0
 *   @0x1515f4 ldr r6, [sp, #0x10]
 *   @0x1515f8 mov r5, r0
 *   @0x1515fc str r4, [r0, #0xc]
 *   @0x151600 str r4, [r0]
 *   @0x151604 str r4, [r0, #0x4]
 *   @0x151608 bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x15160c mov r1, r4
 *   @0x151610 mov r0, r6
 *   @0x151614 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x151618 subs r4, r0, #0
 *   @0x15161c poplt {r4, r5, r6, pc}
 *   @0x151620 ldr r3, [pc, #0x58]
 *   @0x151624 ldr r3, [pc, r3]
 *   @0x151628 ldr r3, [r3]
 *   @0x15162c cmp r4, r3
 *   @0x151630 popge {r4, r5, r6, pc}
 *   @0x151634 mov r1, #1
 *   @0x151638 mov r0, r6
 *   @0x15163c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x151640 mov r1, r0
 *   @0x151644 mov r0, r4
 *   @0x151648 bl 0x190acc <_Z23TranslateGamepadButtonMii>
 *   @0x15164c ldr r3, [pc, #0x30]
 *   @0x151650 ldr r3, [pc, r3]
 *   @0x151654 ldr r3, [r3]
 *   @0x151658 mov r1, r0
 *   @0x15165c ldr r0, [r3, r4, lsl #2]
 *   @0x151660 bl 0x18ec90 <_ZNK9GMGamePad14ButtonReleasedEi>
 *   @0x151664 vmov s15, r0
 *   @0x151668 vcvt.f64.u32 d7, s15
 *   @0x15166c vmov r0, r1, d7
 *   @0x151670 vmov r2, s14
 *   @0x151674 mov r3, r1
 *   @0x151678 stm r5, {r2, r3}
 *   @0x15167c pop {r4, r5, r6, pc}
 *   @0x151680 eoreq lr, r9, r12, lsr r4
 *   @0x151684 eoreq lr, r9, r4, lsl r4
 *
 * ══ §46/197 F_GamepadButtonValue(RValue&, CInstance*, CInstance*, int, RValue*)  0x151688  size 156  39 条（0x151688..0x151724）
 * @func 0x151688 0x151724  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / anon_15149c / TranslateGamepadButtonM(int, int) / GMGamePad::ButtonValue(int) const
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x30×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x151688 push {r4, r5, r6, lr}
 *   @0x15168c mov r4, #0
 *   @0x151690 ldr r6, [sp, #0x10]
 *   @0x151694 mov r5, r0
 *   @0x151698 str r4, [r0, #0xc]
 *   @0x15169c str r4, [r0]
 *   @0x1516a0 str r4, [r0, #0x4]
 *   @0x1516a4 bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1516a8 mov r1, r4
 *   @0x1516ac mov r0, r6
 *   @0x1516b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1516b4 subs r4, r0, #0
 *   @0x1516b8 poplt {r4, r5, r6, pc}
 *   @0x1516bc ldr r3, [pc, #0x58]
 *   @0x1516c0 ldr r3, [pc, r3]
 *   @0x1516c4 ldr r3, [r3]
 *   @0x1516c8 cmp r4, r3
 *   @0x1516cc popge {r4, r5, r6, pc}
 *   @0x1516d0 mov r1, #1
 *   @0x1516d4 mov r0, r6
 *   @0x1516d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1516dc mov r1, r0
 *   @0x1516e0 mov r0, r4
 *   @0x1516e4 bl 0x190acc <_Z23TranslateGamepadButtonMii>
 *   @0x1516e8 ldr r3, [pc, #0x30]
 *   @0x1516ec ldr r3, [pc, r3]
 *   @0x1516f0 ldr r3, [r3]
 *   @0x1516f4 mov r1, r0
 *   @0x1516f8 ldr r0, [r3, r4, lsl #2]
 *   @0x1516fc bl 0x18ed48 <_ZNK9GMGamePad11ButtonValueEi>
 *   @0x151700 vmov s15, r0
 *   @0x151704 vcvt.f64.f32 d7, s15
 *   @0x151708 vmov r0, r1, d7
 *   @0x15170c vmov r2, s14
 *   @0x151710 mov r3, r1
 *   @0x151714 stm r5, {r2, r3}
 *   @0x151718 pop {r4, r5, r6, pc}
 *   @0x15171c eoreq lr, r9, r0, lsr #7
 *   @0x151720 eoreq lr, r9, r8, ror r3
 *
 * ══ §47/197 F_GamepadAxisValue(RValue&, CInstance*, CInstance*, int, RValue*)  0x15184c  size 156  39 条（0x15184c..0x1518e8）
 * @func 0x15184c 0x1518e8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / anon_15149c / TranslateGamepadAxisM(int, int) / GMGamePad::AxisValue(int) const
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x58×1 / 0x30×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15184c push {r4, r5, r6, lr}
 *   @0x151850 mov r4, #0
 *   @0x151854 ldr r6, [sp, #0x10]
 *   @0x151858 mov r5, r0
 *   @0x15185c str r4, [r0, #0xc]
 *   @0x151860 str r4, [r0]
 *   @0x151864 str r4, [r0, #0x4]
 *   @0x151868 bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x15186c mov r1, r4
 *   @0x151870 mov r0, r6
 *   @0x151874 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x151878 subs r4, r0, #0
 *   @0x15187c poplt {r4, r5, r6, pc}
 *   @0x151880 ldr r3, [pc, #0x58]
 *   @0x151884 ldr r3, [pc, r3]
 *   @0x151888 ldr r3, [r3]
 *   @0x15188c cmp r4, r3
 *   @0x151890 popge {r4, r5, r6, pc}
 *   @0x151894 mov r1, #1
 *   @0x151898 mov r0, r6
 *   @0x15189c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1518a0 mov r1, r0
 *   @0x1518a4 mov r0, r4
 *   @0x1518a8 bl 0x190b44 <_Z21TranslateGamepadAxisMii>
 *   @0x1518ac ldr r3, [pc, #0x30]
 *   @0x1518b0 ldr r3, [pc, r3]
 *   @0x1518b4 ldr r3, [r3]
 *   @0x1518b8 mov r1, r0
 *   @0x1518bc ldr r0, [r3, r4, lsl #2]
 *   @0x1518c0 bl 0x18ed9c <_ZNK9GMGamePad9AxisValueEi>
 *   @0x1518c4 vmov s15, r0
 *   @0x1518c8 vcvt.f64.f32 d7, s15
 *   @0x1518cc vmov r0, r1, d7
 *   @0x1518d0 vmov r2, s14
 *   @0x1518d4 mov r3, r1
 *   @0x1518d8 stm r5, {r2, r3}
 *   @0x1518dc pop {r4, r5, r6, pc}
 *   @0x1518e0 .word 0x0029e1dc
 *   @0x1518e4 .word 0x0029e1b4
 *
 * ══ §48/197 GR_3DM_Vertex_N_Texture_Color(int, float, float, float, float, float, float, float, float, unsigned int, float)  0x165834  size 156  39 条（0x165834..0x1658d0）
 * @func 0x165834 0x1658d0  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Vertex_N_Texture_Color(int, float, float, float, float, float, float, float, float, unsigned int, float)+0x8c / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x78×1 / 0x68×1 / 0x4×1 / 0x2×1 / 0x3c×1 / 0x18×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165834 cmp r0, #0
 *   @0x165838 push {r4, lr}
 *   @0x16583c mov r4, r2
 *   @0x165840 sub sp, sp, #32
 *   @0x165844 blt 0x1658c0 <_Z29GR_3DM_Vertex_N_Texture_Coloriffffffffjf+0x8c>
 *   @0x165848 ldr r12, [pc, #0x78]
 *   @0x16584c ldr r12, [pc, r12]
 *   @0x165850 ldr r12, [r12]
 *   @0x165854 cmp r0, r12
 *   @0x165858 bge 0x1658c0 <_Z29GR_3DM_Vertex_N_Texture_Coloriffffffffjf+0x8c>
 *   @0x16585c ldr r12, [pc, #0x68]
 *   @0x165860 ldr r12, [pc, r12]
 *   @0x165864 ldr r2, [r12, #0x4]
 *   @0x165868 ldr r0, [r2, r0, lsl #2]
 *   @0x16586c cmp r0, #0
 *   @0x165870 beq 0x1658c0 <_Z29GR_3DM_Vertex_N_Texture_Coloriffffffffjf+0x8c>
 *   @0x165874 ldr r12, [sp, #0x3c]
 *   @0x165878 vldr s15, [sp, #40]
 *   @0x16587c str r3, [sp]
 *   @0x165880 vstr s15, [sp, #4]
 *   @0x165884 mov r2, r1
 *   @0x165888 vldr s15, [sp, #44]
 *   @0x16588c mov r1, #9
 *   @0x165890 vstr s15, [sp, #8]
 *   @0x165894 mov r3, r4
 *   @0x165898 vldr s15, [sp, #48]
 *   @0x16589c str r12, [sp, #0x18]
 *   @0x1658a0 vstr s15, [sp, #12]
 *   @0x1658a4 vldr s15, [sp, #52]
 *   @0x1658a8 vstr s15, [sp, #16]
 *   @0x1658ac vldr s15, [sp, #56]
 *   @0x1658b0 vstr s15, [sp, #20]
 *   @0x1658b4 vldr s15, [sp, #64]
 *   @0x1658b8 vstr s15, [sp, #28]
 *   @0x1658bc bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x1658c0 add sp, sp, #32
 *   @0x1658c4 pop {r4, pc}
 *   @0x1658c8 eoreq r10, r8, r4, lsr #17
 *   @0x1658cc mlaeq r8, r4, r8, r10
 *
 * ══ §49/197 GR_3DM_Cylinder(int, float, float, float, float, float, float, float, float, bool, int)  0x1659e4  size 156  39 条（0x1659e4..0x165a80）
 * @func 0x1659e4 0x165a80  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Cylinder(int, float, float, float, float, float, float, float, float, bool, int)+0x8c / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x3c×1 / 0x74×1 / 0x64×1 / 0x4×1 / 0x2×1 / 0x40×1 / 0x18×1 / 0x1c×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1659e4 push {r4, lr}
 *   @0x1659e8 cmp r0, #0
 *   @0x1659ec sub sp, sp, #32
 *   @0x1659f0 mov r4, r2
 *   @0x1659f4 ldrb r2, [sp, #0x3c]
 *   @0x1659f8 blt 0x165a70 <_Z15GR_3DM_Cylinderiffffffffbi+0x8c>
 *   @0x1659fc ldr r12, [pc, #0x74]
 *   @0x165a00 ldr r12, [pc, r12]
 *   @0x165a04 ldr r12, [r12]
 *   @0x165a08 cmp r0, r12
 *   @0x165a0c bge 0x165a70 <_Z15GR_3DM_Cylinderiffffffffbi+0x8c>
 *   @0x165a10 ldr r12, [pc, #0x64]
 *   @0x165a14 ldr r12, [pc, r12]
 *   @0x165a18 ldr r12, [r12, #0x4]
 *   @0x165a1c ldr r0, [r12, r0, lsl #2]
 *   @0x165a20 cmp r0, #0
 *   @0x165a24 beq 0x165a70 <_Z15GR_3DM_Cylinderiffffffffbi+0x8c>
 *   @0x165a28 ldr r12, [sp, #0x40]
 *   @0x165a2c vldr s15, [sp, #40]
 *   @0x165a30 str r3, [sp]
 *   @0x165a34 vstr s15, [sp, #4]
 *   @0x165a38 str r2, [sp, #0x18]
 *   @0x165a3c vldr s15, [sp, #44]
 *   @0x165a40 mov r2, r1
 *   @0x165a44 vstr s15, [sp, #8]
 *   @0x165a48 mov r3, r4
 *   @0x165a4c vldr s15, [sp, #48]
 *   @0x165a50 mov r1, #11
 *   @0x165a54 vstr s15, [sp, #12]
 *   @0x165a58 str r12, [sp, #0x1c]
 *   @0x165a5c vldr s15, [sp, #52]
 *   @0x165a60 vstr s15, [sp, #16]
 *   @0x165a64 vldr s15, [sp, #56]
 *   @0x165a68 vstr s15, [sp, #20]
 *   @0x165a6c bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x165a70 add sp, sp, #32
 *   @0x165a74 pop {r4, pc}
 *   @0x165a78 .word 0x0028a6f0
 *   @0x165a7c eoreq r10, r8, r0, ror #13
 *
 * ══ §50/197 GR_3DM_Cone(int, float, float, float, float, float, float, float, float, bool, int)  0x165a80  size 156  39 条（0x165a80..0x165b1c）
 * @func 0x165a80 0x165b1c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Cone(int, float, float, float, float, float, float, float, float, bool, int)+0x8c / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x3c×1 / 0x74×1 / 0x64×1 / 0x4×1 / 0x2×1 / 0x40×1 / 0x18×1 / 0x1c×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165a80 push {r4, lr}
 *   @0x165a84 cmp r0, #0
 *   @0x165a88 sub sp, sp, #32
 *   @0x165a8c mov r4, r2
 *   @0x165a90 ldrb r2, [sp, #0x3c]
 *   @0x165a94 blt 0x165b0c <_Z11GR_3DM_Coneiffffffffbi+0x8c>
 *   @0x165a98 ldr r12, [pc, #0x74]
 *   @0x165a9c ldr r12, [pc, r12]
 *   @0x165aa0 ldr r12, [r12]
 *   @0x165aa4 cmp r0, r12
 *   @0x165aa8 bge 0x165b0c <_Z11GR_3DM_Coneiffffffffbi+0x8c>
 *   @0x165aac ldr r12, [pc, #0x64]
 *   @0x165ab0 ldr r12, [pc, r12]
 *   @0x165ab4 ldr r12, [r12, #0x4]
 *   @0x165ab8 ldr r0, [r12, r0, lsl #2]
 *   @0x165abc cmp r0, #0
 *   @0x165ac0 beq 0x165b0c <_Z11GR_3DM_Coneiffffffffbi+0x8c>
 *   @0x165ac4 ldr r12, [sp, #0x40]
 *   @0x165ac8 vldr s15, [sp, #40]
 *   @0x165acc str r3, [sp]
 *   @0x165ad0 vstr s15, [sp, #4]
 *   @0x165ad4 str r2, [sp, #0x18]
 *   @0x165ad8 vldr s15, [sp, #44]
 *   @0x165adc mov r2, r1
 *   @0x165ae0 vstr s15, [sp, #8]
 *   @0x165ae4 mov r3, r4
 *   @0x165ae8 vldr s15, [sp, #48]
 *   @0x165aec mov r1, #12
 *   @0x165af0 vstr s15, [sp, #12]
 *   @0x165af4 str r12, [sp, #0x1c]
 *   @0x165af8 vldr s15, [sp, #52]
 *   @0x165afc vstr s15, [sp, #16]
 *   @0x165b00 vldr s15, [sp, #56]
 *   @0x165b04 vstr s15, [sp, #20]
 *   @0x165b08 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x165b0c add sp, sp, #32
 *   @0x165b10 pop {r4, pc}
 *   @0x165b14 eoreq r10, r8, r4, asr r6
 *   @0x165b18 eoreq r10, r8, r4, asr #12
 *
 * ══ §51/197 GR_3DM_Ellipsoid(int, float, float, float, float, float, float, float, float, int)  0x165b1c  size 156  39 条（0x165b1c..0x165bb8）
 * @func 0x165b1c 0x165bb8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Ellipsoid(int, float, float, float, float, float, float, float, float, int)+0x8c / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x78×1 / 0x68×1 / 0x4×1 / 0x2×1 / 0x3c×1 / 0x18×1 / 0x1c×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165b1c cmp r0, #0
 *   @0x165b20 push {r4, lr}
 *   @0x165b24 mov r4, r2
 *   @0x165b28 sub sp, sp, #32
 *   @0x165b2c blt 0x165ba8 <_Z16GR_3DM_Ellipsoidiffffffffi+0x8c>
 *   @0x165b30 ldr r12, [pc, #0x78]
 *   @0x165b34 ldr r12, [pc, r12]
 *   @0x165b38 ldr r12, [r12]
 *   @0x165b3c cmp r0, r12
 *   @0x165b40 bge 0x165ba8 <_Z16GR_3DM_Ellipsoidiffffffffi+0x8c>
 *   @0x165b44 ldr r12, [pc, #0x68]
 *   @0x165b48 ldr r12, [pc, r12]
 *   @0x165b4c ldr r2, [r12, #0x4]
 *   @0x165b50 ldr r0, [r2, r0, lsl #2]
 *   @0x165b54 cmp r0, #0
 *   @0x165b58 beq 0x165ba8 <_Z16GR_3DM_Ellipsoidiffffffffi+0x8c>
 *   @0x165b5c mov r2, r1
 *   @0x165b60 ldr r1, [sp, #0x3c]
 *   @0x165b64 vldr s15, [sp, #40]
 *   @0x165b68 str r3, [sp]
 *   @0x165b6c vstr s15, [sp, #4]
 *   @0x165b70 mov r12, #0
 *   @0x165b74 vldr s15, [sp, #44]
 *   @0x165b78 str r1, [sp, #0x18]
 *   @0x165b7c vstr s15, [sp, #8]
 *   @0x165b80 mov r3, r4
 *   @0x165b84 vldr s15, [sp, #48]
 *   @0x165b88 str r12, [sp, #0x1c]
 *   @0x165b8c vstr s15, [sp, #12]
 *   @0x165b90 mov r1, #13
 *   @0x165b94 vldr s15, [sp, #52]
 *   @0x165b98 vstr s15, [sp, #16]
 *   @0x165b9c vldr s15, [sp, #56]
 *   @0x165ba0 vstr s15, [sp, #20]
 *   @0x165ba4 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x165ba8 add sp, sp, #32
 *   @0x165bac pop {r4, pc}
 *   @0x165bb0 .word 0x0028a5bc
 *   @0x165bb4 eoreq r10, r8, r12, lsr #11
 *
 * ══ §52/197 GR_D3D_Set_Texture_Interpolation_Ext(int, bool)  0x1687d4  size 156  39 条（0x1687d4..0x168870）
 * @func 0x1687d4 0x168870  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1687f0→0x3f23c0, 0x1687f8→0x4859c8
 * 调用序列: RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)×2
 * 字段偏移 top8: 0x7c×1 / 0x70×1 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1687d4 push {r4, r5, r6, lr}
 *   @0x1687d8 cmp r0, #7
 *   @0x1687dc mov r4, r0
 *   @0x1687e0 ldr r0, [pc, #0x7c]
 *   @0x1687e4 mov r5, r1
 *   @0x1687e8 add r0, pc, r0
 *   @0x1687ec pophi {r4, r5, r6, pc}
 *   @0x1687f0 ldr r3, [pc, #0x70]
 *   @0x1687f4 cmp r5, #0
 *   @0x1687f8 ldr r12, [pc, #0x6c]
 *   @0x1687fc mov r1, r4
 *   @0x168800 ldr r3, [r0, r3]
 *   @0x168804 strb r5, [r3, r4]
 *   @0x168808 bne 0x168838 <_Z36GR_D3D_Set_Texture_Interpolation_Extib+0x64>
 *   @0x16880c ldr r6, [r0, r12]
 *   @0x168810 mov r2, r5
 *   @0x168814 mov r3, r5
 *   @0x168818 mov r0, r6
 *   @0x16881c bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x168820 mov r0, r6
 *   @0x168824 mov r1, r4
 *   @0x168828 mov r3, r5
 *   @0x16882c mov r2, #1
 *   @0x168830 pop {r4, r5, r6, lr}
 *   @0x168834 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x168838 ldr r5, [r0, r12]
 *   @0x16883c mov r2, #0
 *   @0x168840 mov r3, #1
 *   @0x168844 mov r0, r5
 *   @0x168848 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x16884c mov r2, #1
 *   @0x168850 mov r0, r5
 *   @0x168854 mov r1, r4
 *   @0x168858 mov r3, r2
 *   @0x16885c pop {r4, r5, r6, lr}
 *   @0x168860 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x168864 eoreq r9, r8, r8, ror #8
 *   @0x168868 .word 0xffffe4b8
 *   @0x16886c .word 0xffffc0a8
 *
 * ══ §53/197 SetupBlankTexture()  0x1830dc  size 156  39 条（0x1830dc..0x183178）
 * @func 0x1830dc 0x183178  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::CreateTexture(int, int, int, eTextureFlags, eTextureFormat) / Graphics::CopySurface(void*, int, int, int, void*) / 0xb65d4
 * 字段偏移 top8: 0x-10×2 / 0x84×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1830dc push {r4, r11, lr}
 *   @0x1830e0 add r11, sp, #8
 *   @0x1830e4 ldr r4, [pc, #0x84]
 *   @0x1830e8 sub sp, sp, #20
 *   @0x1830ec mov r0, #16
 *   @0x1830f0 ldr r4, [pc, r4]
 *   @0x1830f4 mov r12, #6
 *   @0x1830f8 mov r1, r0
 *   @0x1830fc mov r2, #1
 *   @0x183100 ldr lr, [r4]
 *   @0x183104 mov r3, #0
 *   @0x183108 str lr, [r11, #-0x10]
 *   @0x18310c str r12, [sp]
 *   @0x183110 bl 0x18269c <_ZN8Graphics13CreateTextureEiii13eTextureFlags14eTextureFormat>
 *   @0x183114 ldr r12, [pc, #0x58]
 *   @0x183118 sub r1, sp, #1024
 *   @0x18311c mov r3, #0
 *   @0x183120 ldr r12, [pc, r12]
 *   @0x183124 sub sp, r1, #8
 *   @0x183128 mvn r2, #0
 *   @0x18312c str r0, [r12]
 *   @0x183130 str r2, [r1, r3]
 *   @0x183134 add r3, r3, #4
 *   @0x183138 cmp r3, #1024
 *   @0x18313c bne 0x183130 <_Z17SetupBlankTexturev+0x54>
 *   @0x183140 mov r2, #16
 *   @0x183144 str r1, [sp]
 *   @0x183148 mov r3, r2
 *   @0x18314c mov r1, #0
 *   @0x183150 bl 0x183000 <_ZN8Graphics11CopySurfaceEPviiiS0_>
 *   @0x183154 ldr r2, [r11, #-0x10]
 *   @0x183158 ldr r3, [r4]
 *   @0x18315c cmp r2, r3
 *   @0x183160 bne 0x18316c <_Z17SetupBlankTexturev+0x90>
 *   @0x183164 sub sp, r11, #8
 *   @0x183168 pop {r4, r11, pc}
 *   @0x18316c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x183170 eoreq r10, r6, r0, ror #16
 *   @0x183174 eoreq sp, r6, r12, lsr #8
 *
 * ══ §54/197 ValueToKey(char const*)  0x18c4a0  size 156  39 条（0x18c4a0..0x18c53c）
 * @func 0x18c4a0 0x18c53c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Constant_Find_IgnoreCase(char const*)
 * 字段偏移 top8: 0x1×3 / 0x2×2 / 0x78×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c4a0 push {r3, lr}
 *   @0x18c4a4 ldrb r3, [r0]
 *   @0x18c4a8 cmp r3, #86
 *   @0x18c4ac beq 0x18c4fc <_Z10ValueToKeyPKc+0x5c>
 *   @0x18c4b0 cmp r3, #77
 *   @0x18c4b4 beq 0x18c4e0 <_Z10ValueToKeyPKc+0x40>
 *   @0x18c4b8 ldr r2, [pc, #0x78]
 *   @0x18c4bc ldr r2, [pc, r2]
 *   @0x18c4c0 ldr r2, [r2]
 *   @0x18c4c4 add r2, r2, r3
 *   @0x18c4c8 ldrb r2, [r2, #0x1]
 *   @0x18c4cc tst r2, #8
 *   @0x18c4d0 beq 0x18c4d8 <_Z10ValueToKeyPKc+0x38>
 *   @0x18c4d4 mov r3, #0
 *   @0x18c4d8 mov r0, r3
 *   @0x18c4dc pop {r3, pc}
 *   @0x18c4e0 ldrb r1, [r0, #0x1]
 *   @0x18c4e4 cmp r1, #66
 *   @0x18c4e8 bne 0x18c4b8 <_Z10ValueToKeyPKc+0x18>
 *   @0x18c4ec ldrb r2, [r0, #0x2]
 *   @0x18c4f0 cmp r2, #95
 *   @0x18c4f4 bne 0x18c4b8 <_Z10ValueToKeyPKc+0x18>
 *   @0x18c4f8 b 0x18c4d4 <_Z10ValueToKeyPKc+0x34>
 *   @0x18c4fc ldrb r1, [r0, #0x1]
 *   @0x18c500 cmp r1, #75
 *   @0x18c504 bne 0x18c4b8 <_Z10ValueToKeyPKc+0x18>
 *   @0x18c508 ldrb r2, [r0, #0x2]
 *   @0x18c50c cmp r2, #95
 *   @0x18c510 bne 0x18c4b8 <_Z10ValueToKeyPKc+0x18>
 *   @0x18c514 bl 0xedc8c <_Z29Code_Constant_Find_IgnoreCasePKc>
 *   @0x18c518 cmp r0, #0
 *   @0x18c51c beq 0x18c4d4 <_Z10ValueToKeyPKc+0x34>
 *   @0x18c520 ldm r0, {r2, r3}
 *   @0x18c524 vmov d7, r2, r3
 *   @0x18c528 vcvt.u32.f64 s15, d7
 *   @0x18c52c vmov r3, s15
 *   @0x18c530 uxtb r3, r3
 *   @0x18c534 b 0x18c4d8 <_Z10ValueToKeyPKc+0x38>
 *   @0x18c538 eoreq r1, r6, r4, asr #9
 *
 * ══ §55/197 ParticleSystem_Emitter_DestroyAll(int)  0x1a37b8  size 156  39 条（0x1a37b8..0x1a3854）
 * @func 0x1a37b8 0x1a3854  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / ParticleSystem_Exists(int) / ParticleSystem_Emitter_DestroyAll(int)+0x70
 * 字段偏移 top8: 0x2×5 / 0x4×4 / 0x10×4 / 0xc×3 / 0x7c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a37b8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1a37bc mov r8, r0
 *   @0x1a37c0 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a37c4 cmp r0, #0
 *   @0x1a37c8 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1a37cc ldr r5, [pc, #0x7c]
 *   @0x1a37d0 lsl r6, r8, #2
 *   @0x1a37d4 ldr r5, [pc, r5]
 *   @0x1a37d8 ldr r3, [r5, #0x4]
 *   @0x1a37dc ldr r3, [r3, r8, lsl #2]
 *   @0x1a37e0 ldr r2, [r3, #0xc]
 *   @0x1a37e4 cmp r2, #0
 *   @0x1a37e8 ble 0x1a3828 <_Z33ParticleSystem_Emitter_DestroyAlli+0x70>
 *   @0x1a37ec mov r4, #0
 *   @0x1a37f0 mov r7, r4
 *   @0x1a37f4 ldr r3, [r3, #0x10]
 *   @0x1a37f8 ldr r0, [r3, r4, lsl #2]
 *   @0x1a37fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a3800 ldr r3, [r5, #0x4]
 *   @0x1a3804 ldr r3, [r3, r6]
 *   @0x1a3808 ldr r3, [r3, #0x10]
 *   @0x1a380c str r7, [r3, r4, lsl #2]
 *   @0x1a3810 add r4, r4, #1
 *   @0x1a3814 ldr r3, [r5, #0x4]
 *   @0x1a3818 ldr r3, [r3, r6]
 *   @0x1a381c ldr r2, [r3, #0xc]
 *   @0x1a3820 cmp r2, r4
 *   @0x1a3824 bgt 0x1a37f4 <_Z33ParticleSystem_Emitter_DestroyAlli+0x3c>
 *   @0x1a3828 ldr r0, [r3, #0x10]
 *   @0x1a382c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a3830 ldr r2, [r5, #0x4]
 *   @0x1a3834 mov r3, #0
 *   @0x1a3838 ldr r1, [r2, r8, lsl #2]
 *   @0x1a383c str r3, [r1, #0x10]
 *   @0x1a3840 ldr r2, [r2, r8, lsl #2]
 *   @0x1a3844 str r3, [r2, #0xc]
 *   @0x1a3848 str r3, [r2, #0x14]
 *   @0x1a384c pop {r4, r5, r6, r7, r8, pc}
 *   @0x1a3850 eoreq r12, r4, r4, ror #31
 *
 * ══ §56/197 CPath::Scale(float, float)  0x1a794c  size 156  39 条（0x1a794c..0x1a79e8）
 * @func 0x1a794c 0x1a79e8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::Shift(float, float)×2 / CPath::Center(float&, float&) / CPath::Scale(float, float)+0x78 / CPath::ComputeInternal()
 * 字段偏移 top8: 0x4×3 / 0x10×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a794c push {r4, lr}
 *   @0x1a7950 vpush {d8}
 *   @0x1a7954 sub sp, sp, #8
 *   @0x1a7958 vmov s16, r1
 *   @0x1a795c mov r4, r0
 *   @0x1a7960 mov r1, sp
 *   @0x1a7964 vmov s17, r2
 *   @0x1a7968 add r2, sp, #4
 *   @0x1a796c bl 0x1a7610 <_ZN5CPath6CenterERfS0_>
 *   @0x1a7970 ldr r1, [sp]
 *   @0x1a7974 ldr r2, [sp, #0x4]
 *   @0x1a7978 mov r0, r4
 *   @0x1a797c eor r1, r1, #-2147483648
 *   @0x1a7980 eor r2, r2, #-2147483648
 *   @0x1a7984 bl 0x1a7734 <_ZN5CPath5ShiftEff>
 *   @0x1a7988 ldr r2, [r4, #0x10]
 *   @0x1a798c cmp r2, #0
 *   @0x1a7990 ble 0x1a79c4 <_ZN5CPath5ScaleEff+0x78>
 *   @0x1a7994 add r2, r2, r2, lsl #1
 *   @0x1a7998 ldr r3, [r4, #0x4]
 *   @0x1a799c add r2, r3, r2, lsl #2
 *   @0x1a79a0 vldr s14, [r3]
 *   @0x1a79a4 vldr s15, [r3, #4]
 *   @0x1a79a8 vmul.f32 s14, s14, s16
 *   @0x1a79ac add r3, r3, #12
 *   @0x1a79b0 vmul.f32 s15, s15, s17
 *   @0x1a79b4 vstr s14, [r3, #-12]
 *   @0x1a79b8 vstr s15, [r3, #-8]
 *   @0x1a79bc cmp r3, r2
 *   @0x1a79c0 bne 0x1a79a0 <_ZN5CPath5ScaleEff+0x54>
 *   @0x1a79c4 mov r0, r4
 *   @0x1a79c8 ldr r1, [sp]
 *   @0x1a79cc ldr r2, [sp, #0x4]
 *   @0x1a79d0 bl 0x1a7734 <_ZN5CPath5ShiftEff>
 *   @0x1a79d4 mov r0, r4
 *   @0x1a79d8 bl 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *   @0x1a79dc add sp, sp, #8
 *   @0x1a79e0 vpop {d8}
 *   @0x1a79e4 pop {r4, pc}
 *
 * ══ §57/197 TBitmap::Create()  0x1a8c3c  size 156  39 条（0x1a8c3c..0x1a8cd8）
 * @func 0x1a8c3c 0x1a8cd8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×6 / 0x20×6 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8c3c ldr r3, [r0, #0x14]
 *   @0x1a8c40 sub r3, r3, #1
 *   @0x1a8c44 cmp r3, #6
 *   @0x1a8c48 addls pc, pc, r3, lsl #2
 *   @0x1a8c4c b 0x1a8c7c <_ZN7TBitmap6CreateEv+0x40>
 *   @0x1a8c50 b 0x1a8cbc <_ZN7TBitmap6CreateEv+0x80>
 *   @0x1a8c54 b 0x1a8c9c <_ZN7TBitmap6CreateEv+0x60>
 *   @0x1a8c58 b 0x1a8cb0 <_ZN7TBitmap6CreateEv+0x74>
 *   @0x1a8c5c b 0x1a8c6c <_ZN7TBitmap6CreateEv+0x30>
 *   @0x1a8c60 b 0x1a8c6c <_ZN7TBitmap6CreateEv+0x30>
 *   @0x1a8c64 b 0x1a8c8c <_ZN7TBitmap6CreateEv+0x50>
 *   @0x1a8c68 b 0x1a8c7c <_ZN7TBitmap6CreateEv+0x40>
 *   @0x1a8c6c ldr r3, [r0, #0x18]
 *   @0x1a8c70 lsl r3, r3, #1
 *   @0x1a8c74 str r3, [r0, #0x20]
 *   @0x1a8c78 bx lr
 *   @0x1a8c7c ldr r3, [r0, #0x18]
 *   @0x1a8c80 lsl r3, r3, #2
 *   @0x1a8c84 str r3, [r0, #0x20]
 *   @0x1a8c88 bx lr
 *   @0x1a8c8c ldr r3, [r0, #0x18]
 *   @0x1a8c90 add r3, r3, r3, lsl #1
 *   @0x1a8c94 str r3, [r0, #0x20]
 *   @0x1a8c98 bx lr
 *   @0x1a8c9c ldr r3, [r0, #0x18]
 *   @0x1a8ca0 add r3, r3, r3, lsr #31
 *   @0x1a8ca4 asr r3, r3, #1
 *   @0x1a8ca8 str r3, [r0, #0x20]
 *   @0x1a8cac bx lr
 *   @0x1a8cb0 ldr r3, [r0, #0x18]
 *   @0x1a8cb4 str r3, [r0, #0x20]
 *   @0x1a8cb8 bx lr
 *   @0x1a8cbc ldr r3, [r0, #0x18]
 *   @0x1a8cc0 add r2, r3, #7
 *   @0x1a8cc4 cmp r3, #0
 *   @0x1a8cc8 movlt r3, r2
 *   @0x1a8ccc asr r3, r3, #3
 *   @0x1a8cd0 str r3, [r0, #0x20]
 *   @0x1a8cd4 bx lr
 *
 * ══ §58/197 F_LayerBackgroundGetIndex(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd000  size 156  39 条（0x1bd000..0x1bd09c）
 * @func 0x1bd000 0x1bd09c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x64×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd000 cmp r3, #1
 *   @0x1bd004 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bd008 mov r3, #0
 *   @0x1bd00c mov r4, r3
 *   @0x1bd010 mov r5, r0
 *   @0x1bd014 movt r3, #0xbff0
 *   @0x1bd018 str r4, [r0, #0xc]
 *   @0x1bd01c str r3, [r0, #0x4]
 *   @0x1bd020 str r4, [r0]
 *   @0x1bd024 ldr r6, [sp, #0x18]
 *   @0x1bd028 beq 0x1bd040 <_Z25F_LayerBackgroundGetIndexR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bd02c ldr r0, [pc, #0x64]
 *   @0x1bd030 mov r1, r4
 *   @0x1bd034 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bd038 add r0, pc, r0
 *   @0x1bd03c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd040 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd044 mov r1, r4
 *   @0x1bd048 mov r7, r0
 *   @0x1bd04c mov r0, r6
 *   @0x1bd050 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd054 mov r2, r4
 *   @0x1bd058 mov r1, r0
 *   @0x1bd05c mov r0, r7
 *   @0x1bd060 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd064 cmp r0, #0
 *   @0x1bd068 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bd06c ldr r3, [r0]
 *   @0x1bd070 cmp r3, #1
 *   @0x1bd074 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bd078 ldr r3, [r0, #0x1c]
 *   @0x1bd07c cmp r3, #0
 *   @0x1bd080 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bd084 vldr s15, [r3, #32]
 *   @0x1bd088 vcvt.f64.f32 d6, s15
 *   @0x1bd08c vmov r2, r3, d6
 *   @0x1bd090 stm r5, {r2, r3}
 *   @0x1bd094 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bd098 andseq r1, r9, r0, lsr #5
 *
 * ══ §59/197 F_LayerSpriteGetBlend(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bda4c  size 156  39 条（0x1bda4c..0x1bdae8）
 * @func 0x1bda4c 0x1bdae8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x64×1 / 0x38×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bda4c cmp r3, #1
 *   @0x1bda50 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bda54 mov r3, #0
 *   @0x1bda58 mov r4, r3
 *   @0x1bda5c mov r5, r0
 *   @0x1bda60 movt r3, #0xbff0
 *   @0x1bda64 str r4, [r0, #0xc]
 *   @0x1bda68 str r3, [r0, #0x4]
 *   @0x1bda6c str r4, [r0]
 *   @0x1bda70 ldr r6, [sp, #0x18]
 *   @0x1bda74 beq 0x1bda8c <_Z21F_LayerSpriteGetBlendR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bda78 ldr r0, [pc, #0x64]
 *   @0x1bda7c mov r1, r4
 *   @0x1bda80 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bda84 add r0, pc, r0
 *   @0x1bda88 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bda8c str r4, [r0]
 *   @0x1bda90 str r4, [r0, #0x4]
 *   @0x1bda94 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bda98 mov r1, r4
 *   @0x1bda9c mov r7, r0
 *   @0x1bdaa0 mov r0, r6
 *   @0x1bdaa4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bdaa8 mov r2, r4
 *   @0x1bdaac mov r1, r0
 *   @0x1bdab0 mov r0, r7
 *   @0x1bdab4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bdab8 cmp r0, #0
 *   @0x1bdabc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bdac0 ldr r3, [r0]
 *   @0x1bdac4 cmp r3, #4
 *   @0x1bdac8 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bdacc ldr r2, [r0, #0x38]
 *   @0x1bdad0 vmov s15, r2
 *   @0x1bdad4 vcvt.f64.u32 d7, s15
 *   @0x1bdad8 vmov r2, r3, d7
 *   @0x1bdadc stm r5, {r2, r3}
 *   @0x1bdae0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bdae4 andseq r0, r9, r12, lsl r12
 *
 * ══ §60/197 F_LayerTileGetBlend(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bfb08  size 156  39 条（0x1bfb08..0x1bfba4）
 * @func 0x1bfb08 0x1bfba4  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x64×1 / 0x40×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bfb08 cmp r3, #1
 *   @0x1bfb0c push {r3, r4, r5, r6, r7, lr}
 *   @0x1bfb10 mov r3, #0
 *   @0x1bfb14 mov r4, r3
 *   @0x1bfb18 mov r5, r0
 *   @0x1bfb1c movt r3, #0xbff0
 *   @0x1bfb20 str r4, [r0, #0xc]
 *   @0x1bfb24 str r3, [r0, #0x4]
 *   @0x1bfb28 str r4, [r0]
 *   @0x1bfb2c ldr r6, [sp, #0x18]
 *   @0x1bfb30 beq 0x1bfb48 <_Z19F_LayerTileGetBlendR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bfb34 ldr r0, [pc, #0x64]
 *   @0x1bfb38 mov r1, r4
 *   @0x1bfb3c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bfb40 add r0, pc, r0
 *   @0x1bfb44 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bfb48 str r4, [r0]
 *   @0x1bfb4c str r4, [r0, #0x4]
 *   @0x1bfb50 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bfb54 mov r1, r4
 *   @0x1bfb58 mov r7, r0
 *   @0x1bfb5c mov r0, r6
 *   @0x1bfb60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bfb64 mov r2, r4
 *   @0x1bfb68 mov r1, r0
 *   @0x1bfb6c mov r0, r7
 *   @0x1bfb70 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bfb74 cmp r0, #0
 *   @0x1bfb78 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bfb7c ldr r3, [r0]
 *   @0x1bfb80 cmp r3, #7
 *   @0x1bfb84 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bfb88 ldr r2, [r0, #0x40]
 *   @0x1bfb8c vmov s15, r2
 *   @0x1bfb90 vcvt.f64.u32 d7, s15
 *   @0x1bfb94 vmov r2, r3, d7
 *   @0x1bfb98 stm r5, {r2, r3}
 *   @0x1bfb9c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bfba0 mulseq r8, r12, r9
 *
 * ══ §61/197 F_LayerTileGetVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bfd6c  size 156  39 条（0x1bfd6c..0x1bfe08）
 * @func 0x1bfd6c 0x1bfe08  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x64×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bfd6c cmp r3, #1
 *   @0x1bfd70 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bfd74 mov r3, #0
 *   @0x1bfd78 mov r4, r3
 *   @0x1bfd7c mov r5, r0
 *   @0x1bfd80 movt r3, #0xbff0
 *   @0x1bfd84 str r4, [r0, #0xc]
 *   @0x1bfd88 str r3, [r0, #0x4]
 *   @0x1bfd8c str r4, [r0]
 *   @0x1bfd90 ldr r6, [sp, #0x18]
 *   @0x1bfd94 beq 0x1bfdac <_Z21F_LayerTileGetVisibleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bfd98 ldr r0, [pc, #0x64]
 *   @0x1bfd9c mov r1, r4
 *   @0x1bfda0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bfda4 add r0, pc, r0
 *   @0x1bfda8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bfdac str r4, [r0]
 *   @0x1bfdb0 str r4, [r0, #0x4]
 *   @0x1bfdb4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bfdb8 mov r1, r4
 *   @0x1bfdbc mov r7, r0
 *   @0x1bfdc0 mov r0, r6
 *   @0x1bfdc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bfdc8 mov r2, r4
 *   @0x1bfdcc mov r1, r0
 *   @0x1bfdd0 mov r0, r7
 *   @0x1bfdd4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bfdd8 cmp r0, #0
 *   @0x1bfddc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bfde0 ldr r3, [r0]
 *   @0x1bfde4 cmp r3, #7
 *   @0x1bfde8 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bfdec ldrb r2, [r0, #0x1c]
 *   @0x1bfdf0 vmov s15, r2
 *   @0x1bfdf4 vcvt.f64.u32 d7, s15
 *   @0x1bfdf8 vmov r2, r3, d7
 *   @0x1bfdfc stm r5, {r2, r3}
 *   @0x1bfe00 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bfe04 andseq pc, r8, r0, lsl r8
 *
 * ══ §62/197 Code_Patch(unsigned char*, unsigned int, unsigned char*)  0x1dc8c4  size 156  39 条（0x1dc8c4..0x1dc960）
 * @func 0x1dc8c4 0x1dc960  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Patch(unsigned char*, void*, int) / RewriteOldCode(unsigned char*, void*, int)
 * 字段偏移 top8: 0x4×3 / 0x7c×1 / 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc8c4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1dc8c8 mov r5, r2
 *   @0x1dc8cc ldr r10, [r0]
 *   @0x1dc8d0 cmp r10, #0
 *   @0x1dc8d4 beq 0x1dc954 <_Z10Code_PatchPhjS_+0x90>
 *   @0x1dc8d8 ldr r9, [pc, #0x7c]
 *   @0x1dc8dc mov r8, r0
 *   @0x1dc8e0 mov r4, #0
 *   @0x1dc8e4 ldr r9, [pc, r9]
 *   @0x1dc8e8 b 0x1dc924 <_Z10Code_PatchPhjS_+0x60>
 *   @0x1dc8ec ldr r2, [r3, #0x10]
 *   @0x1dc8f0 ldr r7, [r3, #0x4]
 *   @0x1dc8f4 cmp r2, #0
 *   @0x1dc8f8 bne 0x1dc918 <_Z10Code_PatchPhjS_+0x54>
 *   @0x1dc8fc add r6, r3, #12
 *   @0x1dc900 ldr r3, [r3, #0xc]
 *   @0x1dc904 add r6, r6, r3
 *   @0x1dc908 mov r0, r6
 *   @0x1dc90c mov r2, r7
 *   @0x1dc910 mov r1, r5
 *   @0x1dc914 bl 0x1dc7cc <_Z10Code_PatchPhPvi>
 *   @0x1dc918 add r4, r4, #1
 *   @0x1dc91c cmp r4, r10
 *   @0x1dc920 beq 0x1dc954 <_Z10Code_PatchPhjS_+0x90>
 *   @0x1dc924 ldrb r2, [r9]
 *   @0x1dc928 mov r1, r5
 *   @0x1dc92c ldr r3, [r8, #0x4]!
 *   @0x1dc930 cmp r2, #0
 *   @0x1dc934 add r3, r5, r3
 *   @0x1dc938 add r6, r3, #8
 *   @0x1dc93c bne 0x1dc8ec <_Z10Code_PatchPhjS_+0x28>
 *   @0x1dc940 ldr r7, [r3, #0x4]
 *   @0x1dc944 mov r0, r6
 *   @0x1dc948 mov r2, r7
 *   @0x1dc94c bl 0x1dc890 <_Z14RewriteOldCodePhPvi>
 *   @0x1dc950 b 0x1dc908 <_Z10Code_PatchPhjS_+0x44>
 *   @0x1dc954 mov r0, #1
 *   @0x1dc958 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1dc95c eoreq r1, r1, r0, ror r2
 *
 * ══ §63/197 Script_Init()  0x1dff7c  size 156  39 条（0x1dff7c..0x1e0018）
 * @func 0x1dff7c 0x1e0018  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / Script_Init()+0x60
 * 字段偏移 top8: 0x4×4 / 0x84×1 / 0x74×1 / 0x2×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dff7c push {r3, r4, r5, r6, r7, lr}
 *   @0x1dff80 ldr r6, [pc, #0x84]
 *   @0x1dff84 ldr r6, [pc, r6]
 *   @0x1dff88 ldr r2, [r6, #0x4]
 *   @0x1dff8c cmp r2, #0
 *   @0x1dff90 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1dff94 ldr r5, [pc, #0x74]
 *   @0x1dff98 ldr r5, [pc, r5]
 *   @0x1dff9c ldr r3, [r5]
 *   @0x1dffa0 cmp r3, #0
 *   @0x1dffa4 ble 0x1dffdc <_Z11Script_Initv+0x60>
 *   @0x1dffa8 mov r4, #0
 *   @0x1dffac ldr r3, [r2, r4, lsl #2]
 *   @0x1dffb0 add r4, r4, #1
 *   @0x1dffb4 cmp r3, #0
 *   @0x1dffb8 mov r0, r3
 *   @0x1dffbc beq 0x1dffd0 <_Z11Script_Initv+0x54>
 *   @0x1dffc0 ldr r3, [r3]
 *   @0x1dffc4 ldr r3, [r3, #0x4]
 *   @0x1dffc8 blx r3
 *   @0x1dffcc ldr r2, [r6, #0x4]
 *   @0x1dffd0 ldr r3, [r5]
 *   @0x1dffd4 cmp r3, r4
 *   @0x1dffd8 bgt 0x1dffac <_Z11Script_Initv+0x30>
 *   @0x1dffdc ldr r7, [pc, #0x30]
 *   @0x1dffe0 mov r0, r2
 *   @0x1dffe4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1dffe8 mov r4, #0
 *   @0x1dffec ldr r7, [pc, r7]
 *   @0x1dfff0 str r4, [r6, #0x4]
 *   @0x1dfff4 str r4, [r6]
 *   @0x1dfff8 ldr r0, [r7]
 *   @0x1dfffc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e0000 str r4, [r7]
 *   @0x1e0004 str r4, [r5]
 *   @0x1e0008 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1e000c eoreq r0, r1, r4, lsr #27
 *   @0x1e0010 mlaeq r1, r4, sp, r0
 *   @0x1e0014 eoreq r0, r1, r4, asr #26
 *
 * ══ §64/197 SV_BackgroundBlend(CInstance*, int, RValue*)  0x1fcd30  size 156  39 条（0x1fcd30..0x1fcdcc）
 * @func 0x1fcd30 0x1fcdcc  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x24×2 / 0x88×1 / 0x68×1 / 0xc×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fcd30 ldr r3, [pc, #0x88]
 *   @0x1fcd34 cmp r1, #7
 *   @0x1fcd38 push {r4, lr}
 *   @0x1fcd3c ldr r3, [pc, r3]
 *   @0x1fcd40 movls r0, r1
 *   @0x1fcd44 movhi r0, #0
 *   @0x1fcd48 ldrb r1, [r3]
 *   @0x1fcd4c cmp r1, #0
 *   @0x1fcd50 beq 0x1fcdac <_Z18SV_BackgroundBlendP9CInstanceiP6RValue+0x7c>
 *   @0x1fcd54 ldr r3, [pc, #0x68]
 *   @0x1fcd58 ldr r1, [r2, #0xc]
 *   @0x1fcd5c ldr r3, [pc, r3]
 *   @0x1fcd60 bic r1, r1, #-16777216
 *   @0x1fcd64 ldr r3, [r3]
 *   @0x1fcd68 cmp r1, #0
 *   @0x1fcd6c add r0, r3, r0, lsl #2
 *   @0x1fcd70 ldr r4, [r0, #0x24]
 *   @0x1fcd74 bne 0x1fcd98 <_Z18SV_BackgroundBlendP9CInstanceiP6RValue+0x68>
 *   @0x1fcd78 ldr r12, [r2]
 *   @0x1fcd7c ldr r3, [r2, #0x4]
 *   @0x1fcd80 mov r0, r12
 *   @0x1fcd84 mov r1, r3
 *   @0x1fcd88 bl 0xb66e8 <lrint@plt>
 *   @0x1fcd8c str r0, [r4, #0x24]
 *   @0x1fcd90 mov r0, #1
 *   @0x1fcd94 pop {r4, pc}
 *   @0x1fcd98 mov r0, r2
 *   @0x1fcd9c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fcda0 mov r12, r0
 *   @0x1fcda4 mov r3, r1
 *   @0x1fcda8 b 0x1fcd80 <_Z18SV_BackgroundBlendP9CInstanceiP6RValue+0x50>
 *   @0x1fcdac ldr r0, [pc, #0x14]
 *   @0x1fcdb0 add r0, pc, r0
 *   @0x1fcdb4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1fcdb8 mov r0, #1
 *   @0x1fcdbc pop {r4, pc}
 *   @0x1fcdc0 andseq r3, pc, r0, lsl #31
 *   @0x1fcdc4 andseq r0, pc, r12, asr #23
 *   @0x1fcdc8 andseq r5, r5, r0, asr r12
 *
 * ══ §65/197 SV_PhysicsPositionX(CInstance*, int, RValue*)  0x1fe674  size 156  39 条（0x1fe674..0x1fe710）
 * @func 0x1fe674 0x1fe710  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckPhysicsError(CInstance*, bool, bool) / CPhysicsObject::SetPosition(float, float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x70×1 / 0x84×1 / 0xb4×1 / 0xc×1 / 0x10×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fe674 mov r1, #1
 *   @0x1fe678 push {r3, r4, r6, r7, r8, r9, r10, lr}
 *   @0x1fe67c mov r9, r2
 *   @0x1fe680 mov r2, r1
 *   @0x1fe684 mov r4, r0
 *   @0x1fe688 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1fe68c subs r6, r0, #0
 *   @0x1fe690 beq 0x1fe6f8 <_Z19SV_PhysicsPositionXP9CInstanceiP6RValue+0x84>
 *   @0x1fe694 ldr r3, [pc, #0x70]
 *   @0x1fe698 ldr r7, [r4, #0x84]
 *   @0x1fe69c ldr r3, [pc, r3]
 *   @0x1fe6a0 ldr r3, [r3]
 *   @0x1fe6a4 ldr r8, [r3, #0xb4]
 *   @0x1fe6a8 cmp r7, #0
 *   @0x1fe6ac cmpne r8, #0
 *   @0x1fe6b0 moveq r6, #0
 *   @0x1fe6b4 movne r6, #1
 *   @0x1fe6b8 beq 0x1fe6f8 <_Z19SV_PhysicsPositionXP9CInstanceiP6RValue+0x84>
 *   @0x1fe6bc ldr r3, [r9, #0xc]
 *   @0x1fe6c0 ldr r2, [r7]
 *   @0x1fe6c4 bic r3, r3, #-16777216
 *   @0x1fe6c8 cmp r3, #0
 *   @0x1fe6cc ldr r10, [r2, #0x10]
 *   @0x1fe6d0 bne 0x1fe700 <_Z19SV_PhysicsPositionXP9CInstanceiP6RValue+0x8c>
 *   @0x1fe6d4 ldm r9, {r0, r1}
 *   @0x1fe6d8 vmov d6, r0, r1
 *   @0x1fe6dc vldr s15, [r8, #96]
 *   @0x1fe6e0 mov r0, r7
 *   @0x1fe6e4 mov r2, r10
 *   @0x1fe6e8 vcvt.f32.f64 s14, d6
 *   @0x1fe6ec vmul.f32 s15, s14, s15
 *   @0x1fe6f0 vmov r1, s15
 *   @0x1fe6f4 bl 0x236e00 <_ZN14CPhysicsObject11SetPositionEff>
 *   @0x1fe6f8 mov r0, r6
 *   @0x1fe6fc pop {r3, r4, r6, r7, r8, r9, r10, pc}
 *   @0x1fe700 mov r0, r9
 *   @0x1fe704 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fe708 b 0x1fe6d8 <_Z19SV_PhysicsPositionXP9CInstanceiP6RValue+0x64>
 *   @0x1fe70c andseq pc, lr, r12, lsl #5
 *
 * ══ §66/197 SV_PhysicsPositionY(CInstance*, int, RValue*)  0x1fe710  size 156  39 条（0x1fe710..0x1fe7ac）
 * @func 0x1fe710 0x1fe7ac  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckPhysicsError(CInstance*, bool, bool) / CPhysicsObject::SetPosition(float, float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×2 / 0x70×1 / 0x84×1 / 0xb4×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fe710 mov r1, #1
 *   @0x1fe714 push {r3, r4, r6, r7, r8, r9, r10, lr}
 *   @0x1fe718 mov r9, r2
 *   @0x1fe71c mov r2, r1
 *   @0x1fe720 mov r4, r0
 *   @0x1fe724 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1fe728 subs r6, r0, #0
 *   @0x1fe72c beq 0x1fe794 <_Z19SV_PhysicsPositionYP9CInstanceiP6RValue+0x84>
 *   @0x1fe730 ldr r3, [pc, #0x70]
 *   @0x1fe734 ldr r7, [r4, #0x84]
 *   @0x1fe738 ldr r3, [pc, r3]
 *   @0x1fe73c ldr r3, [r3]
 *   @0x1fe740 ldr r8, [r3, #0xb4]
 *   @0x1fe744 cmp r7, #0
 *   @0x1fe748 cmpne r8, #0
 *   @0x1fe74c moveq r6, #0
 *   @0x1fe750 movne r6, #1
 *   @0x1fe754 beq 0x1fe794 <_Z19SV_PhysicsPositionYP9CInstanceiP6RValue+0x84>
 *   @0x1fe758 ldr r3, [r9, #0xc]
 *   @0x1fe75c ldr r2, [r7]
 *   @0x1fe760 bic r3, r3, #-16777216
 *   @0x1fe764 cmp r3, #0
 *   @0x1fe768 ldr r10, [r2, #0xc]
 *   @0x1fe76c bne 0x1fe79c <_Z19SV_PhysicsPositionYP9CInstanceiP6RValue+0x8c>
 *   @0x1fe770 ldm r9, {r0, r1}
 *   @0x1fe774 vmov d6, r0, r1
 *   @0x1fe778 vldr s15, [r8, #96]
 *   @0x1fe77c mov r0, r7
 *   @0x1fe780 mov r1, r10
 *   @0x1fe784 vcvt.f32.f64 s14, d6
 *   @0x1fe788 vmul.f32 s15, s14, s15
 *   @0x1fe78c vmov r2, s15
 *   @0x1fe790 bl 0x236e00 <_ZN14CPhysicsObject11SetPositionEff>
 *   @0x1fe794 mov r0, r6
 *   @0x1fe798 pop {r3, r4, r6, r7, r8, r9, r10, pc}
 *   @0x1fe79c mov r0, r9
 *   @0x1fe7a0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fe7a4 b 0x1fe774 <_Z19SV_PhysicsPositionYP9CInstanceiP6RValue+0x64>
 *   @0x1fe7a8 ldrsheq pc, [lr], -r0
 *
 * ══ §67/197 COggThread::LogError(char const*, ...)  0x223c18  size 156  39 条（0x223c18..0x223cb4）
 * @func 0x223c18 0x223cb4  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6610 / COggThread::Lock() / 0xb6538 / 0xb6c1c / COggThread::Unlock() / 0xb65d4
 * 字段偏移 top8: 0x104×2 / 0x80×1 / 0x11c×1 / 0x800×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223c18 push {r1, r2, r3}
 *   @0x223c1c mov r1, #255
 *   @0x223c20 push {r4, r5, r6, lr}
 *   @0x223c24 sub sp, sp, #268
 *   @0x223c28 ldr r5, [pc, #0x80]
 *   @0x223c2c add r12, sp, #288
 *   @0x223c30 add r6, sp, #4
 *   @0x223c34 mov r4, r0
 *   @0x223c38 ldr r5, [pc, r5]
 *   @0x223c3c mov r3, r12
 *   @0x223c40 ldr r2, [sp, #0x11c]
 *   @0x223c44 mov r0, r6
 *   @0x223c48 ldr lr, [r5]
 *   @0x223c4c str r12, [sp]
 *   @0x223c50 str lr, [sp, #0x104]
 *   @0x223c54 bl 0xb6610 <vsnprintf@plt>
 *   @0x223c58 mov r0, r4
 *   @0x223c5c bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x223c60 mov r3, #1
 *   @0x223c64 mov r0, r4
 *   @0x223c68 strb r3, [r4, #0x800]
 *   @0x223c6c bl 0xb6538 <strlen@plt>
 *   @0x223c70 mov r1, r6
 *   @0x223c74 rsb r2, r0, #2032
 *   @0x223c78 mov r0, r4
 *   @0x223c7c add r2, r2, #15
 *   @0x223c80 bl 0xb6c1c <strncat@plt>
 *   @0x223c84 mov r0, r4
 *   @0x223c88 bl 0x223aa4 <_ZN10COggThread6UnlockEv>
 *   @0x223c8c ldr r2, [sp, #0x104]
 *   @0x223c90 ldr r3, [r5]
 *   @0x223c94 cmp r2, r3
 *   @0x223c98 bne 0x223cac <_ZN10COggThread8LogErrorEPKcz+0x94>
 *   @0x223c9c add sp, sp, #268
 *   @0x223ca0 pop {r4, r5, r6, lr}
 *   @0x223ca4 add sp, sp, #12
 *   @0x223ca8 bx lr
 *   @0x223cac bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x223cb0 andseq r9, r12, r8, lsl sp
 *
 * ══ §68/197 COggSyncThread::LogError(char const*, ...)  0x224fdc  size 156  39 条（0x224fdc..0x225078）
 * @func 0x224fdc 0x225078  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6610 / COggSyncThread::Lock() / 0xb6538 / 0xb6c1c / COggSyncThread::Unlock() / 0xb65d4
 * 字段偏移 top8: 0x104×2 / 0x80×1 / 0x11c×1 / 0x800×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224fdc push {r1, r2, r3}
 *   @0x224fe0 mov r1, #255
 *   @0x224fe4 push {r4, r5, r6, lr}
 *   @0x224fe8 sub sp, sp, #268
 *   @0x224fec ldr r5, [pc, #0x80]
 *   @0x224ff0 add r12, sp, #288
 *   @0x224ff4 add r6, sp, #4
 *   @0x224ff8 mov r4, r0
 *   @0x224ffc ldr r5, [pc, r5]
 *   @0x225000 mov r3, r12
 *   @0x225004 ldr r2, [sp, #0x11c]
 *   @0x225008 mov r0, r6
 *   @0x22500c ldr lr, [r5]
 *   @0x225010 str r12, [sp]
 *   @0x225014 str lr, [sp, #0x104]
 *   @0x225018 bl 0xb6610 <vsnprintf@plt>
 *   @0x22501c mov r0, r4
 *   @0x225020 bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x225024 mov r3, #1
 *   @0x225028 mov r0, r4
 *   @0x22502c strb r3, [r4, #0x800]
 *   @0x225030 bl 0xb6538 <strlen@plt>
 *   @0x225034 mov r1, r6
 *   @0x225038 rsb r2, r0, #2032
 *   @0x22503c mov r0, r4
 *   @0x225040 add r2, r2, #15
 *   @0x225044 bl 0xb6c1c <strncat@plt>
 *   @0x225048 mov r0, r4
 *   @0x22504c bl 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x225050 ldr r2, [sp, #0x104]
 *   @0x225054 ldr r3, [r5]
 *   @0x225058 cmp r2, r3
 *   @0x22505c bne 0x225070 <_ZN14COggSyncThread8LogErrorEPKcz+0x94>
 *   @0x225060 add sp, sp, #268
 *   @0x225064 pop {r4, r5, r6, lr}
 *   @0x225068 add sp, sp, #12
 *   @0x22506c bx lr
 *   @0x225070 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x225074 andseq r8, r12, r4, asr r9
 *
 * ══ §69/197 res0_free_look  0x22df08  size 156  39 条（0x22df08..0x22dfa4）
 * @func 0x22df08 0x22dfa4  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×4 / res0_free_look+0x44 / res0_free_look+0x78 / 0xb65b0
 * 字段偏移 top8: 0x8×2 / 0x18×2 / 0x2×2 / 0x1c×2 / 0x20×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22df08 push {r3, r4, r5, lr}
 *   @0x22df0c subs r4, r0, #0
 *   @0x22df10 popeq {r3, r4, r5, pc}
 *   @0x22df14 ldr r3, [r4, #0x8]
 *   @0x22df18 ldr r2, [r4, #0x18]
 *   @0x22df1c cmp r3, #0
 *   @0x22df20 movgt r5, #0
 *   @0x22df24 ble 0x22df4c <res0_free_look+0x44>
 *   @0x22df28 ldr r0, [r2, r5, lsl #2]
 *   @0x22df2c add r5, r5, #1
 *   @0x22df30 cmp r0, #0
 *   @0x22df34 beq 0x22df44 <res0_free_look+0x3c>
 *   @0x22df38 bl 0xb655c <free@plt>
 *   @0x22df3c ldr r2, [r4, #0x18]
 *   @0x22df40 ldr r3, [r4, #0x8]
 *   @0x22df44 cmp r3, r5
 *   @0x22df48 bgt 0x22df28 <res0_free_look+0x20>
 *   @0x22df4c mov r0, r2
 *   @0x22df50 bl 0xb655c <free@plt>
 *   @0x22df54 ldr r3, [r4, #0x1c]
 *   @0x22df58 cmp r3, #0
 *   @0x22df5c movgt r5, #0
 *   @0x22df60 ble 0x22df80 <res0_free_look+0x78>
 *   @0x22df64 ldr r3, [r4, #0x20]
 *   @0x22df68 ldr r0, [r3, r5, lsl #2]
 *   @0x22df6c add r5, r5, #1
 *   @0x22df70 bl 0xb655c <free@plt>
 *   @0x22df74 ldr r3, [r4, #0x1c]
 *   @0x22df78 cmp r3, r5
 *   @0x22df7c bgt 0x22df64 <res0_free_look+0x5c>
 *   @0x22df80 ldr r0, [r4, #0x20]
 *   @0x22df84 bl 0xb655c <free@plt>
 *   @0x22df88 mov r0, r4
 *   @0x22df8c mov r1, #0
 *   @0x22df90 mov r2, #36
 *   @0x22df94 bl 0xb65b0 <memset@plt>
 *   @0x22df98 mov r0, r4
 *   @0x22df9c pop {r3, r4, r5, lr}
 *   @0x22dfa0 b 0xb655c <free@plt>
 *
 * ══ §70/197 CPhysicsWorld::SetGravity(float, float)  0x238c14  size 156  39 条（0x238c14..0x238cb0）
 * @func 0x238c14 0x238cb0  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×2 / 0x70×2 / 0x238×1 / 0x4×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238c14 vmov s14, r1
 *   @0x238c18 ldr r3, [r0, #0x10]
 *   @0x238c1c vmov s15, r2
 *   @0x238c20 vcmp.f32 s14, #0
 *   @0x238c24 add r2, r3, #102400
 *   @0x238c28 mov r3, r2
 *   @0x238c2c str r1, [r2, #0x238]
 *   @0x238c30 vstr s15, [r3, #572]
 *   @0x238c34 vmrs APSR_nzcv, fpscr
 *   @0x238c38 vcmp.f32 s15, #0
 *   @0x238c3c moveq r3, #0
 *   @0x238c40 movne r3, #1
 *   @0x238c44 vmrs APSR_nzcv, fpscr
 *   @0x238c48 orrne r3, r3, #1
 *   @0x238c4c cmp r3, #0
 *   @0x238c50 bxeq lr
 *   @0x238c54 ldr r2, [r0, #0x10]
 *   @0x238c58 movw r3, #0x9228
 *   @0x238c5c movt r3, #0x1
 *   @0x238c60 ldr r3, [r2, r3]
 *   @0x238c64 cmp r3, #0
 *   @0x238c68 bxeq lr
 *   @0x238c6c mov r1, #0
 *   @0x238c70 b 0x238c80 <_ZN13CPhysicsWorld10SetGravityEff+0x6c>
 *   @0x238c74 ldr r3, [r3, #0x70]
 *   @0x238c78 cmp r3, #0
 *   @0x238c7c beq 0x238cac <_ZN13CPhysicsWorld10SetGravityEff+0x98>
 *   @0x238c80 ldr r2, [r3]
 *   @0x238c84 cmp r2, #2
 *   @0x238c88 bne 0x238c74 <_ZN13CPhysicsWorld10SetGravityEff+0x60>
 *   @0x238c8c ldrh r2, [r3, #4]
 *   @0x238c90 tst r2, #2
 *   @0x238c94 orr r2, r2, #2
 *   @0x238c98 streq r1, [r3, #0xa0]
 *   @0x238c9c strheq r2, [r3, #4]
 *   @0x238ca0 ldr r3, [r3, #0x70]
 *   @0x238ca4 cmp r3, #0
 *   @0x238ca8 bne 0x238c80 <_ZN13CPhysicsWorld10SetGravityEff+0x6c>
 *   @0x238cac bx lr
 *
 * ══ §71/197 CPhysicsDebugRender::DrawPolygon(b2Vec2 const*, int, b2Color const&)  0x23c380  size 156  39 条（0x23c380..0x23c41c）
 * @func 0x23c380 0x23c41c  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsDebugRender::TranslateColour(b2Color const&) / YYGML_draw_set_colour(unsigned int) / CPhysicsDebugRender::DrawPolygon(b2Vec2 const*, int, b2Color const&)+0x94 / __aeabi_idivmod / GR_Draw_Line(float, float, float, float)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c380 push {r3, r4, r5, r6, r7, lr}
 *   @0x23c384 vpush {d8}
 *   @0x23c388 vmov.f32 s16, #1.000000e+00
 *   @0x23c38c mov r7, r1
 *   @0x23c390 mov r1, r3
 *   @0x23c394 mov r6, r2
 *   @0x23c398 mov r4, r0
 *   @0x23c39c bl 0x23c338 <_ZN19CPhysicsDebugRender15TranslateColourERK7b2Color>
 *   @0x23c3a0 bl 0x169d98 <_Z21YYGML_draw_set_colourj>
 *   @0x23c3a4 cmp r6, #0
 *   @0x23c3a8 ldr r3, [r4, #0x8]
 *   @0x23c3ac vldr s15, [r3, #96]
 *   @0x23c3b0 vdiv.f32 s16, s16, s15
 *   @0x23c3b4 ble 0x23c414 <_ZN19CPhysicsDebugRender11DrawPolygonEPK6b2Vec2iRK7b2Color+0x94>
 *   @0x23c3b8 mov r5, r7
 *   @0x23c3bc mov r4, #0
 *   @0x23c3c0 add r4, r4, #1
 *   @0x23c3c4 mov r1, r6
 *   @0x23c3c8 add r5, r5, #8
 *   @0x23c3cc mov r0, r4
 *   @0x23c3d0 bl 0x318dec <__aeabi_idivmod>
 *   @0x23c3d4 vldr s14, [r5, #-8]
 *   @0x23c3d8 vldr s15, [r5, #-4]
 *   @0x23c3dc vmul.f32 s14, s16, s14
 *   @0x23c3e0 add r1, r7, r1, lsl #3
 *   @0x23c3e4 vldr s13, [r1]
 *   @0x23c3e8 vmov r0, s14
 *   @0x23c3ec vldr s14, [r1, #4]
 *   @0x23c3f0 vmul.f32 s13, s16, s13
 *   @0x23c3f4 vmul.f32 s14, s16, s14
 *   @0x23c3f8 vmov r2, s13
 *   @0x23c3fc vmul.f32 s15, s16, s15
 *   @0x23c400 vmov r3, s14
 *   @0x23c404 vmov r1, s15
 *   @0x23c408 bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x23c40c cmp r4, r6
 *   @0x23c410 bne 0x23c3c0 <_ZN19CPhysicsDebugRender11DrawPolygonEPK6b2Vec2iRK7b2Color+0x40>
 *   @0x23c414 vpop {d8}
 *   @0x23c418 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §72/197 json_parse_jsarray(json_object*, RValue&)  0x24bf1c  size 156  39 条（0x24bf1c..0x24bfb8）
 * @func 0x24bf1c 0x24bfb8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_object_array_length / F_JSNewArray_NoArguments(RValue&, CInstance*, CInstance*, int, RValue*) / json_parse_jsarray(json_object*, RValue&)+0x88 / json_object_array_get_idx / json_parse(json_object*, RValue&) / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0x4×2 / 0x-8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24bf1c push {r4, r5, r6, r7, r8, lr}
 *   @0x24bf20 sub sp, sp, #8
 *   @0x24bf24 mov r4, r1
 *   @0x24bf28 mov r7, r0
 *   @0x24bf2c bl 0x27ede8 <json_object_array_length>
 *   @0x24bf30 mov r3, #0
 *   @0x24bf34 mov r1, r3
 *   @0x24bf38 str r3, [sp]
 *   @0x24bf3c mov r2, r3
 *   @0x24bf40 mov r6, r0
 *   @0x24bf44 mov r0, r4
 *   @0x24bf48 mov r3, r6
 *   @0x24bf4c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x24bf50 ldr r0, [r4]
 *   @0x24bf54 ldr r3, [r0, #0x4]
 *   @0x24bf58 cmp r3, #0
 *   @0x24bf5c beq 0x24bfac <_Z18json_parse_jsarrayP11json_objectR6RValue+0x90>
 *   @0x24bf60 add r0, r3, #16
 *   @0x24bf64 ldr r3, [r0]
 *   @0x24bf68 cmp r6, #0
 *   @0x24bf6c ldr r4, [r3, #0x4]
 *   @0x24bf70 ble 0x24bfa4 <_Z18json_parse_jsarrayP11json_objectR6RValue+0x88>
 *   @0x24bf74 mov r5, #0
 *   @0x24bf78 mov r8, #6
 *   @0x24bf7c mov r1, r5
 *   @0x24bf80 mov r0, r7
 *   @0x24bf84 bl 0x27ee00 <json_object_array_get_idx>
 *   @0x24bf88 add r5, r5, #1
 *   @0x24bf8c mov r1, r4
 *   @0x24bf90 add r4, r4, #16
 *   @0x24bf94 bl 0x24beac <_Z10json_parseP11json_objectR6RValue>
 *   @0x24bf98 cmp r5, r6
 *   @0x24bf9c str r8, [r4, #-0x8]
 *   @0x24bfa0 bne 0x24bf7c <_Z18json_parse_jsarrayP11json_objectR6RValue+0x60>
 *   @0x24bfa4 add sp, sp, #8
 *   @0x24bfa8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x24bfac mov r1, #1
 *   @0x24bfb0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24bfb4 b 0x24bf64 <_Z18json_parse_jsarrayP11json_objectR6RValue+0x48>
 *
 * ══ §73/197 JS_ToUint16(RValue&, RValue&)  0x24d8ec  size 156  39 条（0x24d8ec..0x24d988）
 * @func 0x24d8ec 0x24d988  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToNumber(RValue&, RValue&) / yyisinf(RValue&) / __fixdfdi
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x4×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24d8ec push {r4, r5, lr}
 *   @0x24d8f0 sub sp, sp, #20
 *   @0x24d8f4 mov r3, #0
 *   @0x24d8f8 mov r4, r0
 *   @0x24d8fc str r3, [r0, #0xc]
 *   @0x24d900 mov r0, sp
 *   @0x24d904 str r3, [sp, #0x8]
 *   @0x24d908 mov r2, #0
 *   @0x24d90c mov r3, #0
 *   @0x24d910 mvn r12, #-16777216
 *   @0x24d914 strd r2, r3, [sp]
 *   @0x24d918 str r12, [sp, #0xc]
 *   @0x24d91c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x24d920 vldr d7, [sp]
 *   @0x24d924 vcmp.f64 d7, #0
 *   @0x24d928 vmrs APSR_nzcv, fpscr
 *   @0x24d92c bne 0x24d944 <_Z11JS_ToUint16R6RValueS0_+0x58>
 *   @0x24d930 mov r3, #0
 *   @0x24d934 str r3, [r4]
 *   @0x24d938 str r3, [r4, #0x4]
 *   @0x24d93c add sp, sp, #20
 *   @0x24d940 pop {r4, r5, pc}
 *   @0x24d944 mov r0, sp
 *   @0x24d948 bl 0x240970 <_Z7yyisinfR6RValue>
 *   @0x24d94c cmp r0, #0
 *   @0x24d950 bne 0x24d930 <_Z11JS_ToUint16R6RValueS0_+0x44>
 *   @0x24d954 vldr d7, [sp]
 *   @0x24d958 vcmp.f64 d7, d7
 *   @0x24d95c vmrs APSR_nzcv, fpscr
 *   @0x24d960 bvs 0x24d930 <_Z11JS_ToUint16R6RValueS0_+0x44>
 *   @0x24d964 vmov r0, r1, d7
 *   @0x24d968 bl 0x3194a0 <__fixdfdi>
 *   @0x24d96c uxth r0, r0
 *   @0x24d970 vmov s15, r0
 *   @0x24d974 vcvt.f64.s32 d7, s15
 *   @0x24d978 vmov r2, r3, d7
 *   @0x24d97c stm r4, {r2, r3}
 *   @0x24d980 add sp, sp, #20
 *   @0x24d984 pop {r4, r5, pc}
 *
 * ══ §74/197 PB_OurInfo(HTTP_REQ_CONTEXT*, void*, int*)  0x28fa58  size 156  39 条（0x28fa58..0x28faf4）
 * @func 0x28fa58 0x28faf4  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateDsMap(int, ...)
 * 字段偏移 top8: 0x70×2 / 0x80×1 / 0x4×1 / 0x4c×1 / 0x10×1 / 0x14×1 / 0x2c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fa58 ldr r12, [pc, #0x80]
 *   @0x28fa5c mov r0, #0
 *   @0x28fa60 push {r4, lr}
 *   @0x28fa64 ldr r12, [pc, r12]
 *   @0x28fa68 sub sp, sp, #40
 *   @0x28fa6c ldr lr, [pc, #0x70]
 *   @0x28fa70 ldr r3, [pc, #0x70]
 *   @0x28fa74 mov r1, #0
 *   @0x28fa78 mov r4, #0
 *   @0x28fa7c strd r0, r1, [sp, #8]
 *   @0x28fa80 str r4, [sp]
 *   @0x28fa84 add lr, pc, lr
 *   @0x28fa88 str lr, [sp, #0x4]
 *   @0x28fa8c ldr r3, [pc, r3]
 *   @0x28fa90 ldr lr, [r12]
 *   @0x28fa94 mov r4, r2
 *   @0x28fa98 ldr r12, [pc, #0x4c]
 *   @0x28fa9c mov r2, #0
 *   @0x28faa0 strd r0, r1, [sp, #24]
 *   @0x28faa4 mov r0, #3
 *   @0x28faa8 str lr, [sp, #0x10]
 *   @0x28faac add r12, pc, r12
 *   @0x28fab0 str r12, [sp, #0x14]
 *   @0x28fab4 ldr r12, [r3]
 *   @0x28fab8 mov r3, #20480
 *   @0x28fabc ldr r1, [pc, #0x2c]
 *   @0x28fac0 movt r3, #0x408f
 *   @0x28fac4 add r1, pc, r1
 *   @0x28fac8 str r12, [sp, #0x20]
 *   @0x28facc bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x28fad0 str r0, [r4]
 *   @0x28fad4 mov r0, #70
 *   @0x28fad8 add sp, sp, #40
 *   @0x28fadc pop {r4, pc}
 *   @0x28fae0 andseq r1, r6, r8, lsr #29
 *   @0x28fae4 andeq r0, r10, r4, lsl #27
 *   @0x28fae8 andseq r1, r6, r4, lsl #29
 *   @0x28faec andeq r8, r12, r8, lsl #12
 *   @0x28faf0 andeq r0, r10, r12, ror pc
 *
 * ══ §75/197 yySocket::ResolveIP()  0x296f64  size 156  39 条（0x296f64..0x297000）
 * @func 0x296f64 0x297000  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6e80 / 0xb65c8 / 0xb65d4
 * 字段偏移 top8: 0x24×2 / 0x84×1 / 0x6c×1 / 0x10×1 / 0x1b×1 / 0x19×1 / 0x1a×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x296f64 push {r4, r5, r6, lr}
 *   @0x296f68 mov r5, r0
 *   @0x296f6c ldr r4, [pc, #0x84]
 *   @0x296f70 sub sp, sp, #40
 *   @0x296f74 add r1, sp, #20
 *   @0x296f78 add r2, sp, #16
 *   @0x296f7c ldr r4, [pc, r4]
 *   @0x296f80 mov r6, r0
 *   @0x296f84 ldr r0, [r5], #108
 *   @0x296f88 mov r12, #16
 *   @0x296f8c ldr r3, [r4]
 *   @0x296f90 str r12, [sp, #0x10]
 *   @0x296f94 str r3, [sp, #0x24]
 *   @0x296f98 bl 0xb6e80 <getpeername@plt>
 *   @0x296f9c ldrb r2, [sp, #0x1b]
 *   @0x296fa0 mov r0, r5
 *   @0x296fa4 ldrb lr, [sp, #0x19]
 *   @0x296fa8 mov r1, #15
 *   @0x296fac ldrb r12, [sp, #0x1a]
 *   @0x296fb0 str r2, [sp, #0x8]
 *   @0x296fb4 ldr r2, [pc, #0x40]
 *   @0x296fb8 ldrb r3, [sp, #0x18]
 *   @0x296fbc str lr, [sp]
 *   @0x296fc0 add r2, pc, r2
 *   @0x296fc4 str r12, [sp, #0x4]
 *   @0x296fc8 bl 0xb65c8 <snprintf@plt>
 *   @0x296fcc ldrh r3, [sp, #22]
 *   @0x296fd0 rev16 r3, r3
 *   @0x296fd4 ldr r1, [sp, #0x24]
 *   @0x296fd8 uxth r3, r3
 *   @0x296fdc ldr r2, [r4]
 *   @0x296fe0 str r3, [r6, #0xb0]
 *   @0x296fe4 cmp r1, r2
 *   @0x296fe8 bne 0x296ff4 <_ZN8yySocket9ResolveIPEv+0x90>
 *   @0x296fec add sp, sp, #40
 *   @0x296ff0 pop {r4, r5, r6, pc}
 *   @0x296ff4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x296ff8 ldrsbeq r6, [r5], -r4
 *   @0x296ffc andeq r2, r12, r8, asr r5
 *
 * ══ §76/197 png_write_filtered_row  0x2b293c  size 156  39 条（0x2b293c..0x2b29d8）
 * @func 0x2b293c 0x2b29d8  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2bec94+0x1f8 / png_write_filtered_row+0x94
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b293c push {r4, r5, r6, lr}
 *   @0x2b2940 mcrmi p5, #0x1, r7, c4, c12, #0x4
 *   @0x2b2944 mov r4, r0
 *   @0x2b2948 ldrbtmi r3, [lr], #-456
 *   @0x2b294c str.w r1, [r0, #0x138]
 *   @0x2b2950 adds r3, #0x1
 *   @0x2b2954 qasxmi r3, r8, r12
 *   @0x2b2958 movs r1, #0x0
 *   @0x2b295c teqlt r0, r8, lsr #16
 *   @0x2b2960 ldr.w r1, [r4, #0x150]
 *   @0x2b2964 mov r0, r4
 *   @0x2b2968 mov r1, r6
 *   @0x2b296c .word 0xf8d4fd5f
 *   @0x2b2970 ldmdblt r3!, {r3, r6, r8, r12, sp} ^
 *   @0x2b2974 mov r0, r4
 *   @0x2b2978 .word 0xf8d41170
 *   @0x2b297c .word 0xf7fe2174
 *   @0x2b2980 .word 0xf8d4fe8f
 *   @0x2b2984 .word 0xf8c43170
 *   @0x2b2988 .word 0xf8d43144
 *   @0x2b298c .word 0xf8c43174
 *   @0x2b2990 .word 0xf8d43148
 *   @0x2b2994 blhs 0x2bee8c <jpeg_huff_decode+0x300>
 *   @0x2b2998 bne 0x2b2956 <png_write_filtered_row+0x1a>
 *   @0x2b299c smulwblt r11, r12, r1
 *   @0x2b29a0 ldr.w r2, [r4, #0x1b0]
 *   @0x2b29a4 str.w r3, [r4, #0x1b0]
 *   @0x2b29a8 str.w r2, [r4, #0x1ac]
 *   @0x2b29ac mov r0, r4
 *   @0x2b29b0 .word 0xf8d4fe2d
 *   @0x2b29b4 .word 0xf8d42218
 *   @0x2b29b8 andlo r3, r1, #20, #4
 *   @0x2b29bc str.w r2, [r4, #0x218]
 *   @0x2b29c0 cbz r3, 0x2b29d0 <png_write_filtered_row+0x94>
 *   @0x2b29c4 blo 0x2b29d0 <png_write_filtered_row+0x94>
 *   @0x2b29c8 pop.w {r4, r5, r6, lr}
 *   @0x2b29cc b.w 0x2b0554 <png_write_flush>
 *   @0x2b29d0 pop {r4, r5, r6, pc}
 *   @0x2b29d4 .word 0xb633
 *
 * ══ §77/197 b2ChainAndCircleContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&)  0x2e1ca8  size 156  39 条（0x2e1ca8..0x2e1d44）
 * @func 0x2e1ca8 0x2e1d44  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ChainShape::GetChildEdge(b2EdgeShape*, int) const / b2CollideEdgeAndCircle(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&)
 * 字段偏移 top8: 0xc×3 / 0x30×2 / 0x34×2 / 0x7c×1 / 0x38×1 / 0x35×1 / 0x8×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1ca8 push {r4, r5, r6, r7, r8, lr}
 *   @0x2e1cac mov r4, r0
 *   @0x2e1cb0 sub sp, sp, #56
 *   @0x2e1cb4 ldr r0, [r0, #0x30]
 *   @0x2e1cb8 add r5, sp, #8
 *   @0x2e1cbc ldr r12, [pc, #0x7c]
 *   @0x2e1cc0 mov r7, r1
 *   @0x2e1cc4 mov r6, r2
 *   @0x2e1cc8 ldr r0, [r0, #0xc]
 *   @0x2e1ccc mov r1, r5
 *   @0x2e1cd0 ldr r2, [r4, #0x38]
 *   @0x2e1cd4 ldr r12, [pc, r12]
 *   @0x2e1cd8 mov lr, #0
 *   @0x2e1cdc mov r8, r3
 *   @0x2e1ce0 strb lr, [sp, #0x34]
 *   @0x2e1ce4 add r12, r12, #8
 *   @0x2e1ce8 strb lr, [sp, #0x35]
 *   @0x2e1cec mov r3, #1
 *   @0x2e1cf0 str r12, [sp, #0x8]
 *   @0x2e1cf4 mov r12, #0
 *   @0x2e1cf8 str r3, [sp, #0xc]
 *   @0x2e1cfc movw r3, #0xd70a
 *   @0x2e1d00 str r12, [sp, #0x24]
 *   @0x2e1d04 movt r3, #0x3c23
 *   @0x2e1d08 str r12, [sp, #0x28]
 *   @0x2e1d0c str r3, [sp, #0x10]
 *   @0x2e1d10 str r12, [sp, #0x2c]
 *   @0x2e1d14 str r12, [sp, #0x30]
 *   @0x2e1d18 bl 0x2c4bf4 <_ZNK12b2ChainShape12GetChildEdgeEP11b2EdgeShapei>
 *   @0x2e1d1c ldr r3, [r4, #0x34]
 *   @0x2e1d20 mov r0, r7
 *   @0x2e1d24 mov r1, r5
 *   @0x2e1d28 mov r2, r6
 *   @0x2e1d2c ldr r3, [r3, #0xc]
 *   @0x2e1d30 str r8, [sp]
 *   @0x2e1d34 bl 0x2dceb0 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_>
 *   @0x2e1d38 add sp, sp, #56
 *   @0x2e1d3c pop {r4, r5, r6, r7, r8, pc}
 *   @0x2e1d40 andseq pc, r0, r0, ror #15
 *
 * ══ §78/197 b2ChainAndPolygonContact::Evaluate(b2Manifold*, b2Transform const&, b2Transform const&)  0x2e1e34  size 156  39 条（0x2e1e34..0x2e1ed0）
 * @func 0x2e1e34 0x2e1ed0  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ChainShape::GetChildEdge(b2EdgeShape*, int) const / b2CollideEdgeAndPolygon(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)
 * 字段偏移 top8: 0xc×3 / 0x30×2 / 0x34×2 / 0x7c×1 / 0x38×1 / 0x35×1 / 0x8×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1e34 push {r4, r5, r6, r7, r8, lr}
 *   @0x2e1e38 mov r4, r0
 *   @0x2e1e3c sub sp, sp, #56
 *   @0x2e1e40 ldr r0, [r0, #0x30]
 *   @0x2e1e44 add r5, sp, #8
 *   @0x2e1e48 ldr r12, [pc, #0x7c]
 *   @0x2e1e4c mov r7, r1
 *   @0x2e1e50 mov r6, r2
 *   @0x2e1e54 ldr r0, [r0, #0xc]
 *   @0x2e1e58 mov r1, r5
 *   @0x2e1e5c ldr r2, [r4, #0x38]
 *   @0x2e1e60 ldr r12, [pc, r12]
 *   @0x2e1e64 mov lr, #0
 *   @0x2e1e68 mov r8, r3
 *   @0x2e1e6c strb lr, [sp, #0x34]
 *   @0x2e1e70 add r12, r12, #8
 *   @0x2e1e74 strb lr, [sp, #0x35]
 *   @0x2e1e78 mov r3, #1
 *   @0x2e1e7c str r12, [sp, #0x8]
 *   @0x2e1e80 mov r12, #0
 *   @0x2e1e84 str r3, [sp, #0xc]
 *   @0x2e1e88 movw r3, #0xd70a
 *   @0x2e1e8c str r12, [sp, #0x24]
 *   @0x2e1e90 movt r3, #0x3c23
 *   @0x2e1e94 str r12, [sp, #0x28]
 *   @0x2e1e98 str r3, [sp, #0x10]
 *   @0x2e1e9c str r12, [sp, #0x2c]
 *   @0x2e1ea0 str r12, [sp, #0x30]
 *   @0x2e1ea4 bl 0x2c4bf4 <_ZNK12b2ChainShape12GetChildEdgeEP11b2EdgeShapei>
 *   @0x2e1ea8 ldr r3, [r4, #0x34]
 *   @0x2e1eac mov r0, r7
 *   @0x2e1eb0 mov r1, r5
 *   @0x2e1eb4 mov r2, r6
 *   @0x2e1eb8 ldr r3, [r3, #0xc]
 *   @0x2e1ebc str r8, [sp]
 *   @0x2e1ec0 bl 0x2de0bc <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_>
 *   @0x2e1ec4 add sp, sp, #56
 *   @0x2e1ec8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2e1ecc andseq pc, r0, r4, asr r6
 *
 * ══ §79/197 FT_Outline_New_Internal  0x2e840a  size 156  39 条（0x2e840a..0x2e84a6）
 * @func 0x2e840a 0x2e84a6  size 156  39 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_realloc×3 / 0xb65b0 / FT_Outline_Done_Internal
 * 字段偏移 top8: 0xc×4 / 0x10×2 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e840a push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr}
 *   @0x2e840e mov r5, r0
 *   @0x2e8412 mov r7, r2
 *   @0x2e8416 cbnz r3, 0x2e841c <FT_Outline_New_Internal+0x12>
 *   @0x2e841a b 0x2e84a0 <FT_Outline_New_Internal+0x96>
 *   @0x2e841e beq 0x2e8418 <FT_Outline_New_Internal+0xe>
 *   @0x2e8422 movs r1, #0x0
 *   @0x2e8426 blx 0xb65b0 <memset@plt>
 *   @0x2e842a cmp r7, #0x0
 *   @0x2e842e cmp r7, r6
 *   @0x2e8432 cmp.w r6, #0x8000
 *   @0x2e8436 bhs 0x2e849e <FT_Outline_New_Internal+0x94>
 *   @0x2e843a add.w r8, sp, #0xc
 *   @0x2e843e str r2, [sp]
 *   @0x2e8442 str.w r8, [sp, #0x4]
 *   @0x2e8446 movs r1, #0x8
 *   @0x2e844a bl 0x2e808e <ft_mem_realloc>
 *   @0x2e844e ldr r2, [sp, #0xc]
 *   @0x2e8452 cbnz r2, 0x2e848a <FT_Outline_New_Internal+0x80>
 *   @0x2e8456 strtmi r0, [r8], -r4, lsl #2
 *   @0x2e845a movs r1, #0x1
 *   @0x2e845e bl 0x2e808e <ft_mem_realloc>
 *   @0x2e8462 ldr r2, [sp, #0xc]
 *   @0x2e8466 cbnz r2, 0x2e848a <FT_Outline_New_Internal+0x80>
 *   @0x2e846a strtmi r0, [r8], -r4, lsl #2
 *   @0x2e846e movs r1, #0x2
 *   @0x2e8472 bl 0x2e808e <ft_mem_realloc>
 *   @0x2e8476 str r0, [r4, #0xc]
 *   @0x2e847a cbnz r0, 0x2e848a <FT_Outline_New_Internal+0x80>
 *   @0x2e847e strh r6, [r4, #0x2]
 *   @0x2e8482 eorhi r0, r7, r1, lsl #6
 *   @0x2e8486 str r3, [r4, #0x10]
 *   @0x2e848a ldr r3, [r4, #0x10]
 *   @0x2e848e mov r1, r4
 *   @0x2e8492 .word 0x61230301
 *   @0x2e8496 bl 0x2e7dba <FT_Outline_Done_Internal>
 *   @0x2e849a ldr r0, [sp, #0xc]
 *   @0x2e849e movs r0, #0xa
 *   @0x2e84a2 pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ §80/197 CBackground::CreateGradient(int, int, unsigned int, unsigned int, int, bool)  0xc2ac0  size 152  38 条（0xc2ac0..0xc2b58）
 * @func 0xc2ac0 0xc2b58  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::Clear() / operator new(unsigned int) / CBitmap32::CBitmap32(int, int, unsigned int, unsigned int, int) / CBackground::InitTexture()
 * 字段偏移 top8: 0x4×3 / 0x10×2 / 0x30×1 / 0x28×1 / 0x2c×1 / 0xa×1 / 0x8×1 / 0x9×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2ac0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc2ac4 sub sp, sp, #8
 *   @0xc2ac8 mov r4, r0
 *   @0xc2acc mov r5, r2
 *   @0xc2ad0 mov r6, r1
 *   @0xc2ad4 ldrb r10, [sp, #0x30]
 *   @0xc2ad8 mov r7, r3
 *   @0xc2adc ldr r9, [sp, #0x28]
 *   @0xc2ae0 ldr r8, [sp, #0x2c]
 *   @0xc2ae4 bl 0xc23c0 <_ZN11CBackground5ClearEv>
 *   @0xc2ae8 ldr r0, [r4, #0x10]
 *   @0xc2aec mov r2, #0
 *   @0xc2af0 str r6, [r4]
 *   @0xc2af4 cmp r0, r2
 *   @0xc2af8 strb r10, [r4, #0xa]
 *   @0xc2afc str r5, [r4, #0x4]
 *   @0xc2b00 strb r2, [r4, #0x8]
 *   @0xc2b04 strb r2, [r4, #0x9]
 *   @0xc2b08 beq 0xc2b18 <_ZN11CBackground14CreateGradientEiijjib+0x58>
 *   @0xc2b0c ldr r3, [r0]
 *   @0xc2b10 ldr r3, [r3, #0x4]
 *   @0xc2b14 blx r3
 *   @0xc2b18 mov r0, #24
 *   @0xc2b1c bl 0x27c524 <_Znwj>
 *   @0xc2b20 mov r1, r6
 *   @0xc2b24 mov r2, r5
 *   @0xc2b28 mov r3, r7
 *   @0xc2b2c str r9, [sp]
 *   @0xc2b30 str r8, [sp, #0x4]
 *   @0xc2b34 mov r10, r0
 *   @0xc2b38 bl 0x166768 <_ZN9CBitmap32C2Eiijji>
 *   @0xc2b3c mov r0, r4
 *   @0xc2b40 str r10, [r4, #0x10]
 *   @0xc2b44 bl 0xc1e60 <_ZN11CBackground11InitTextureEv>
 *   @0xc2b48 mov r0, r4
 *   @0xc2b4c add sp, sp, #8
 *   @0xc2b50 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc2b54 b 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv>
 *
 * ══ §81/197 F_BUFFER_Poke(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5548  size 152  38 条（0xc5548..0xc55e0）
 * @func 0xc5548 0xc55e0  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_BUFFER_Poke(RValue&, CInstance*, CInstance*, int, RValue*)+0x7c
 * 字段偏移 top8: 0x18×2 / 0x6c×1 / 0x4×1 / 0x2×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5548 push {r3, r4, r5, r6, r7, lr}
 *   @0xc554c mov r1, #0
 *   @0xc5550 ldr r4, [sp, #0x18]
 *   @0xc5554 mov r0, r4
 *   @0xc5558 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc555c cmp r0, #0
 *   @0xc5560 blt 0xc55c4 <_Z13F_BUFFER_PokeR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xc5564 ldr r3, [pc, #0x6c]
 *   @0xc5568 add r3, pc, r3
 *   @0xc556c ldr r2, [r3]
 *   @0xc5570 cmp r0, r2
 *   @0xc5574 bge 0xc55c4 <_Z13F_BUFFER_PokeR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xc5578 ldr r3, [r3, #0x4]
 *   @0xc557c ldr r5, [r3, r0, lsl #2]
 *   @0xc5580 cmp r5, #0
 *   @0xc5584 beq 0xc55c4 <_Z13F_BUFFER_PokeR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xc5588 ldr r3, [r5]
 *   @0xc558c mov r0, r4
 *   @0xc5590 mov r1, #1
 *   @0xc5594 ldr r6, [r3, #0x18]
 *   @0xc5598 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc559c mov r1, #2
 *   @0xc55a0 mov r7, r0
 *   @0xc55a4 mov r0, r4
 *   @0xc55a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc55ac mov r1, r7
 *   @0xc55b0 add r3, r4, #48
 *   @0xc55b4 mov r2, r0
 *   @0xc55b8 mov r0, r5
 *   @0xc55bc blx r6
 *   @0xc55c0 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc55c4 ldr r0, [pc, #0x10]
 *   @0xc55c8 mov r1, #0
 *   @0xc55cc pop {r3, r4, r5, r6, r7, lr}
 *   @0xc55d0 add r0, pc, r0
 *   @0xc55d4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc55d8 eorseq r4, r11, r12, lsr #23
 *   @0xc55dc eoreq r11, r6, r4, ror #11
 *
 * ══ §82/197 F_BUFFER_Save(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5adc  size 152  38 条（0xc5adc..0xc5b74）
 * @func 0xc5adc 0xc5b74  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_BUFFER_Save(RValue&, CInstance*, CInstance*, int, RValue*)+0x7c / YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x4×2 / 0xc×1 / 0x5c×1 / 0x2×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5adc push {r4, r5, r6, lr}
 *   @0xc5ae0 mov r4, #0
 *   @0xc5ae4 ldr r5, [sp, #0x10]
 *   @0xc5ae8 mov r1, r4
 *   @0xc5aec str r4, [r0, #0xc]
 *   @0xc5af0 str r4, [r0]
 *   @0xc5af4 str r4, [r0, #0x4]
 *   @0xc5af8 mov r0, r5
 *   @0xc5afc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5b00 cmp r0, #0
 *   @0xc5b04 blt 0xc5b58 <_Z13F_BUFFER_SaveR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xc5b08 ldr r2, [pc, #0x5c]
 *   @0xc5b0c add r2, pc, r2
 *   @0xc5b10 ldr r1, [r2]
 *   @0xc5b14 cmp r0, r1
 *   @0xc5b18 bge 0xc5b58 <_Z13F_BUFFER_SaveR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xc5b1c ldr r2, [r2, #0x4]
 *   @0xc5b20 ldr r6, [r2, r0, lsl #2]
 *   @0xc5b24 cmp r6, r4
 *   @0xc5b28 beq 0xc5b58 <_Z13F_BUFFER_SaveR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xc5b2c ldr r3, [r6]
 *   @0xc5b30 mov r0, r5
 *   @0xc5b34 mov r1, #1
 *   @0xc5b38 ldr r5, [r3, #0x1c]
 *   @0xc5b3c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc5b40 mov r2, r4
 *   @0xc5b44 mvn r3, #0
 *   @0xc5b48 mov r1, r0
 *   @0xc5b4c mov r0, r6
 *   @0xc5b50 blx r5
 *   @0xc5b54 pop {r4, r5, r6, pc}
 *   @0xc5b58 ldr r0, [pc, #0x10]
 *   @0xc5b5c mov r1, #0
 *   @0xc5b60 pop {r4, r5, r6, lr}
 *   @0xc5b64 add r0, pc, r0
 *   @0xc5b68 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc5b6c eorseq r4, r11, r8, lsl #12
 *   @0xc5b70 eoreq r11, r6, r0, asr r0
 *
 * ══ §83/197 F_BUFFER_Base64_Decode_Ext(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5d8c  size 152  38 条（0xc5d8c..0xc5e24）
 * @func 0xc5d8c 0xc5e24  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_BUFFER_Base64_Decode_Ext(RValue&, CInstance*, CInstance*, int, RValue*)+0x7c / YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x18×1 / 0x6c×1 / 0x4×1 / 0x2×1 / 0x28×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5d8c push {r3, r4, r5, r6, r7, lr}
 *   @0xc5d90 mov r1, #0
 *   @0xc5d94 ldr r4, [sp, #0x18]
 *   @0xc5d98 mov r0, r4
 *   @0xc5d9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5da0 cmp r0, #0
 *   @0xc5da4 blt 0xc5e08 <_Z26F_BUFFER_Base64_Decode_ExtR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xc5da8 ldr r3, [pc, #0x6c]
 *   @0xc5dac add r3, pc, r3
 *   @0xc5db0 ldr r2, [r3]
 *   @0xc5db4 cmp r0, r2
 *   @0xc5db8 bge 0xc5e08 <_Z26F_BUFFER_Base64_Decode_ExtR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xc5dbc ldr r3, [r3, #0x4]
 *   @0xc5dc0 ldr r5, [r3, r0, lsl #2]
 *   @0xc5dc4 cmp r5, #0
 *   @0xc5dc8 beq 0xc5e08 <_Z26F_BUFFER_Base64_Decode_ExtR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xc5dcc ldr r3, [r5]
 *   @0xc5dd0 mov r0, r4
 *   @0xc5dd4 mov r1, #1
 *   @0xc5dd8 ldr r6, [r3, #0x28]
 *   @0xc5ddc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc5de0 mov r1, #2
 *   @0xc5de4 mov r7, r0
 *   @0xc5de8 mov r0, r4
 *   @0xc5dec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5df0 mov r1, r7
 *   @0xc5df4 mvn r3, #0
 *   @0xc5df8 mov r2, r0
 *   @0xc5dfc mov r0, r5
 *   @0xc5e00 blx r6
 *   @0xc5e04 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc5e08 ldr r0, [pc, #0x10]
 *   @0xc5e0c mov r1, #0
 *   @0xc5e10 pop {r3, r4, r5, r6, r7, lr}
 *   @0xc5e14 add r0, pc, r0
 *   @0xc5e18 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc5e1c eorseq r4, r11, r8, ror #6
 *   @0xc5e20 eoreq r10, r6, r0, lsr #27
 *
 * ══ §84/197 F_DsListFindIndex(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc7cc  size 152  38 条（0xfc7cc..0xfc864）
 * @func 0xfc7cc 0xfc864  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsListFindIndex(RValue&, CInstance*, CInstance*, int, RValue*)+0x78 / CDS_List::Find(RValue*)
 * 字段偏移 top8: 0x10×1 / 0x64×1 / 0x54×1 / 0x4×1 / 0x2×1 / 0xc×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc7cc push {r3, r4, r5, lr}
 *   @0xfc7d0 mov r1, #0
 *   @0xfc7d4 ldr r4, [sp, #0x10]
 *   @0xfc7d8 mov r5, r0
 *   @0xfc7dc mov r0, r4
 *   @0xfc7e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc7e4 cmp r0, #0
 *   @0xfc7e8 blt 0xfc844 <_Z17F_DsListFindIndexR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfc7ec ldr r3, [pc, #0x64]
 *   @0xfc7f0 ldr r3, [pc, r3]
 *   @0xfc7f4 ldr r3, [r3]
 *   @0xfc7f8 cmp r0, r3
 *   @0xfc7fc bge 0xfc844 <_Z17F_DsListFindIndexR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfc800 ldr r3, [pc, #0x54]
 *   @0xfc804 ldr r3, [pc, r3]
 *   @0xfc808 ldr r3, [r3, #0x4]
 *   @0xfc80c ldr r0, [r3, r0, lsl #2]
 *   @0xfc810 cmp r0, #0
 *   @0xfc814 beq 0xfc844 <_Z17F_DsListFindIndexR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfc818 mov r3, #0
 *   @0xfc81c add r1, r4, #16
 *   @0xfc820 str r3, [r5, #0xc]
 *   @0xfc824 bl 0x20318c <_ZN8CDS_List4FindEP6RValue>
 *   @0xfc828 vmov s15, r0
 *   @0xfc82c vcvt.f64.s32 d7, s15
 *   @0xfc830 vmov r0, r1, d7
 *   @0xfc834 vmov r2, s14
 *   @0xfc838 mov r3, r1
 *   @0xfc83c stm r5, {r2, r3}
 *   @0xfc840 pop {r3, r4, r5, pc}
 *   @0xfc844 ldr r0, [pc, #0x14]
 *   @0xfc848 mov r1, #0
 *   @0xfc84c pop {r3, r4, r5, lr}
 *   @0xfc850 add r0, pc, r0
 *   @0xfc854 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc858 eoreq r1, pc, r12, lsl #9
 *   @0xfc85c eoreq r1, pc, r12, ror r4
 *   @0xfc860 eoreq r11, r3, r12, lsr #7
 *
 * ══ §85/197 F_MpLinearStepObject(RValue&, CInstance*, CInstance*, int, RValue*)  0x10899c  size 152  38 条（0x10899c..0x108a34）
 * @func 0x10899c 0x108a34  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / Motion_Linear_Step(CInstance*, float, float, float, int, bool)
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10899c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1089a0 sub sp, sp, #8
 *   @0x1089a4 mov r6, #0
 *   @0x1089a8 mov r5, r0
 *   @0x1089ac ldr r4, [sp, #0x28]
 *   @0x1089b0 mov r7, r1
 *   @0x1089b4 str r6, [r0, #0xc]
 *   @0x1089b8 mov r1, r6
 *   @0x1089bc mov r0, r4
 *   @0x1089c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1089c4 mov r1, #1
 *   @0x1089c8 mov r10, r0
 *   @0x1089cc mov r0, r4
 *   @0x1089d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1089d4 mov r1, #2
 *   @0x1089d8 mov r9, r0
 *   @0x1089dc mov r0, r4
 *   @0x1089e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1089e4 mov r1, #3
 *   @0x1089e8 mov r8, r0
 *   @0x1089ec mov r0, r4
 *   @0x1089f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1089f4 mov r3, r8
 *   @0x1089f8 mov r12, #1
 *   @0x1089fc mov r1, r10
 *   @0x108a00 mov r2, r9
 *   @0x108a04 stm sp, {r0, r12}
 *   @0x108a08 mov r0, r7
 *   @0x108a0c bl 0x19c8a8 <_Z18Motion_Linear_StepP9CInstancefffib>
 *   @0x108a10 cmp r0, #0
 *   @0x108a14 moveq r6, r0
 *   @0x108a18 movne r3, r6
 *   @0x108a1c moveq r3, r6
 *   @0x108a20 movtne r3, #0x3ff0
 *   @0x108a24 str r6, [r5]
 *   @0x108a28 str r3, [r5, #0x4]
 *   @0x108a2c add sp, sp, #8
 *   @0x108a30 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §86/197 F_MpPotentialStepObject(RValue&, CInstance*, CInstance*, int, RValue*)  0x108ad0  size 152  38 条（0x108ad0..0x108b68）
 * @func 0x108ad0 0x108b68  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / Motion_Potential_Step(CInstance*, float, float, float, int, bool)
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108ad0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x108ad4 sub sp, sp, #8
 *   @0x108ad8 mov r6, #0
 *   @0x108adc mov r5, r0
 *   @0x108ae0 ldr r4, [sp, #0x28]
 *   @0x108ae4 mov r7, r1
 *   @0x108ae8 str r6, [r0, #0xc]
 *   @0x108aec mov r1, r6
 *   @0x108af0 mov r0, r4
 *   @0x108af4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108af8 mov r1, #1
 *   @0x108afc mov r10, r0
 *   @0x108b00 mov r0, r4
 *   @0x108b04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108b08 mov r1, #2
 *   @0x108b0c mov r9, r0
 *   @0x108b10 mov r0, r4
 *   @0x108b14 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108b18 mov r1, #3
 *   @0x108b1c mov r8, r0
 *   @0x108b20 mov r0, r4
 *   @0x108b24 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108b28 mov r3, r8
 *   @0x108b2c mov r12, #1
 *   @0x108b30 mov r1, r10
 *   @0x108b34 mov r2, r9
 *   @0x108b38 stm sp, {r0, r12}
 *   @0x108b3c mov r0, r7
 *   @0x108b40 bl 0x19ccc8 <_Z21Motion_Potential_StepP9CInstancefffib>
 *   @0x108b44 cmp r0, #0
 *   @0x108b48 moveq r6, r0
 *   @0x108b4c movne r3, r6
 *   @0x108b50 moveq r3, r6
 *   @0x108b54 movtne r3, #0x3ff0
 *   @0x108b58 str r6, [r5]
 *   @0x108b5c str r3, [r5, #0x4]
 *   @0x108b60 add sp, sp, #8
 *   @0x108b64 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §87/197 YYGML_instance_waiting_for_activation(int)  0x10ae7c  size 152  38 条（0x10ae7c..0x10af14）
 * @func 0x10ae7c 0x10af14  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_instance_waiting_for_activation(int)+0x7c
 * 字段偏移 top8: 0x8c×1 / 0x8×1 / 0x2×1 / 0x68×1 / 0x69×1 / 0x80×1 / 0x18×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ae7c ldr r3, [pc, #0x8c]
 *   @0x10ae80 push {r4, r5}
 *   @0x10ae84 ldr r3, [pc, r3]
 *   @0x10ae88 ldr r4, [r3, #0x8]
 *   @0x10ae8c cmp r4, #0
 *   @0x10ae90 ble 0x10aef8 <_Z37YYGML_instance_waiting_for_activationi+0x7c>
 *   @0x10ae94 ldr r5, [r3]
 *   @0x10ae98 mov r1, #0
 *   @0x10ae9c ldr r3, [r5, r1, lsl #2]
 *   @0x10aea0 ldrb r2, [r3, #0x68]
 *   @0x10aea4 cmp r2, #0
 *   @0x10aea8 bne 0x10aeec <_Z37YYGML_instance_waiting_for_activationi+0x70>
 *   @0x10aeac ldrb r2, [r3, #0x69]
 *   @0x10aeb0 cmp r2, #0
 *   @0x10aeb4 bne 0x10aeec <_Z37YYGML_instance_waiting_for_activationi+0x70>
 *   @0x10aeb8 ldr r3, [r3, #0x80]
 *   @0x10aebc cmp r3, #0
 *   @0x10aec0 beq 0x10aeec <_Z37YYGML_instance_waiting_for_activationi+0x70>
 *   @0x10aec4 ldr r2, [r3, #0x18]
 *   @0x10aec8 ldr r3, [r3, #0x48]
 *   @0x10aecc cmp r0, r2
 *   @0x10aed0 movne r12, #0
 *   @0x10aed4 moveq r12, #1
 *   @0x10aed8 cmp r0, r2
 *   @0x10aedc cmpne r3, #0
 *   @0x10aee0 bne 0x10aec4 <_Z37YYGML_instance_waiting_for_activationi+0x48>
 *   @0x10aee4 cmp r12, #0
 *   @0x10aee8 bne 0x10af04 <_Z37YYGML_instance_waiting_for_activationi+0x88>
 *   @0x10aeec add r1, r1, #1
 *   @0x10aef0 cmp r1, r4
 *   @0x10aef4 bne 0x10ae9c <_Z37YYGML_instance_waiting_for_activationi+0x20>
 *   @0x10aef8 mov r0, #0
 *   @0x10aefc pop {r4, r5}
 *   @0x10af00 bx lr
 *   @0x10af04 mov r0, #1
 *   @0x10af08 pop {r4, r5}
 *   @0x10af0c bx lr
 *   @0x10af10 eoreq r2, lr, r4, asr #27
 *
 * ══ §88/197 F_ArcCos(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e834  size 152  38 条（0x10e834..0x10e8cc）
 * @func 0x10e834 0x10e8cc  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / F_ArcCos(RValue&, CInstance*, CInstance*, int, RValue*)+0x4c / F_ArcCos(RValue&, CInstance*, CInstance*, int, RValue*)+0x60 / 0xb6760
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x4×1 / 0x40×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e834 push {r4, lr}
 *   @0x10e838 mov r3, #0
 *   @0x10e83c ldr r2, [sp, #0x8]
 *   @0x10e840 mov r4, r0
 *   @0x10e844 str r3, [r0, #0xc]
 *   @0x10e848 mov r1, r3
 *   @0x10e84c str r3, [r0]
 *   @0x10e850 str r3, [r0, #0x4]
 *   @0x10e854 mov r0, r2
 *   @0x10e858 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10e85c vmov.f32 s14, #-1.000000e+00
 *   @0x10e860 vmov s15, r0
 *   @0x10e864 vcmpe.f32 s15, s14
 *   @0x10e868 vmrs APSR_nzcv, fpscr
 *   @0x10e86c blt 0x10e880 <_Z8F_ArcCosR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x10e870 vmov.f32 s14, #1.000000e+00
 *   @0x10e874 vcmpe.f32 s15, s14
 *   @0x10e878 vmrs APSR_nzcv, fpscr
 *   @0x10e87c bls 0x10e894 <_Z8F_ArcCosR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x10e880 ldr r0, [pc, #0x40]
 *   @0x10e884 mov r1, #0
 *   @0x10e888 pop {r4, lr}
 *   @0x10e88c add r0, pc, r0
 *   @0x10e890 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x10e894 bl 0xb6760 <acosf@plt>
 *   @0x10e898 vldr s14, [pc, #36]
 *   @0x10e89c vmov s15, r0
 *   @0x10e8a0 vabs.f32 s13, s15
 *   @0x10e8a4 vcmpe.f32 s13, s14
 *   @0x10e8a8 vmrs APSR_nzcv, fpscr
 *   @0x10e8ac vcvtpl.f64.f32 d6, s15
 *   @0x10e8b0 movmi r2, #0
 *   @0x10e8b4 movmi r3, #0
 *   @0x10e8b8 vmovpl r2, r3, d6
 *   @0x10e8bc stm r4, {r2, r3}
 *   @0x10e8c0 pop {r4, pc}
 *   @0x10e8c4 strlo r12, [r7, -r12, lsr #11]!
 *   @0x10e8c8 mlaeq r2, r12, r5, r10
 *
 * ══ §89/197 F_StringSetByteAt(RValue&, CInstance*, CInstance*, int, RValue*)  0x10eeb4  size 152  38 条（0x10eeb4..0x10ef4c）
 * @func 0x10eeb4 0x10ef4c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int) / YYStrDup(char const*) / 0xb6538 / Error_Show_Action(char const*, bool) / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10eeb4 push {r4, r5, r6, r7, r8, lr}
 *   @0x10eeb8 mov r1, #0
 *   @0x10eebc ldr r4, [sp, #0x18]
 *   @0x10eec0 mov r7, r0
 *   @0x10eec4 mov r0, r4
 *   @0x10eec8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x10eecc mov r1, #1
 *   @0x10eed0 mov r6, r0
 *   @0x10eed4 mov r0, r4
 *   @0x10eed8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10eedc mov r1, #2
 *   @0x10eee0 sub r5, r0, #1
 *   @0x10eee4 mov r0, r4
 *   @0x10eee8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10eeec mov r8, r0
 *   @0x10eef0 mov r0, r6
 *   @0x10eef4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x10eef8 mov r4, r0
 *   @0x10eefc mov r0, r6
 *   @0x10ef00 bl 0xb6538 <strlen@plt>
 *   @0x10ef04 cmp r5, r0
 *   @0x10ef08 movge r1, #0
 *   @0x10ef0c movlt r1, #1
 *   @0x10ef10 cmp r5, #0
 *   @0x10ef14 movlt r1, #0
 *   @0x10ef18 cmp r1, #0
 *   @0x10ef1c strbne r8, [r4, r5]
 *   @0x10ef20 bne 0x10ef30 <_Z17F_StringSetByteAtR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x10ef24 ldr r0, [pc, #0x1c]
 *   @0x10ef28 add r0, pc, r0
 *   @0x10ef2c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x10ef30 mov r0, r7
 *   @0x10ef34 mov r1, r4
 *   @0x10ef38 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x10ef3c mov r0, r4
 *   @0x10ef40 pop {r4, r5, r6, r7, r8, lr}
 *   @0x10ef44 b 0xcef90 <_Z6YYFreePKv>
 *   @0x10ef48 eoreq r9, r2, r8, asr pc
 *
 * ══ §90/197 F_SoundEffectGargle(RValue&, CInstance*, CInstance*, int, RValue*)  0x1342f8  size 152  38 条（0x1342f8..0x134390）
 * @func 0x1342f8 0x134390  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / Sound_Data(int) / CSound::GetSoundId()
 * 字段偏移 top8: 0x10×2 / 0x84×1 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1342f8 ldr r3, [pc, #0x84]
 *   @0x1342fc push {r4, r5, r6, lr}
 *   @0x134300 ldr r3, [pc, r3]
 *   @0x134304 ldr r4, [sp, #0x10]
 *   @0x134308 ldrb r3, [r3]
 *   @0x13430c cmp r3, #0
 *   @0x134310 popne {r4, r5, r6, pc}
 *   @0x134314 ldr r3, [pc, #0x6c]
 *   @0x134318 ldr r3, [pc, r3]
 *   @0x13431c ldrb r1, [r3]
 *   @0x134320 cmp r1, #0
 *   @0x134324 popne {r4, r5, r6, pc}
 *   @0x134328 mov r0, r4
 *   @0x13432c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134330 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x134334 subs r1, r0, #0
 *   @0x134338 beq 0x134374 <_Z19F_SoundEffectGargleR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x13433c bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x134340 mov r1, #1
 *   @0x134344 mov r6, r0
 *   @0x134348 mov r0, r4
 *   @0x13434c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134350 mov r1, #2
 *   @0x134354 mov r5, r0
 *   @0x134358 mov r0, r4
 *   @0x13435c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134360 mov r1, r5
 *   @0x134364 mov r2, r0
 *   @0x134368 mov r0, r6
 *   @0x13436c pop {r4, r5, r6, lr}
 *   @0x134370 b 0x21f144 <_Z21SND_Set_Effect_Gargleiii>
 *   @0x134374 ldr r0, [pc, #0x10]
 *   @0x134378 pop {r4, r5, r6, lr}
 *   @0x13437c add r0, pc, r0
 *   @0x134380 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x134384 eoreq r10, r11, r0, lsr r10
 *   @0x134388 eoreq r10, r11, r4, lsr sp
 *   @0x13438c eoreq r11, r0, r0, lsl r1
 *
 * ══ §91/197 F_AudioPlaySoundOn(RValue&, CInstance*, CInstance*, int, RValue*)  0x134c14  size 152  38 条（0x134c14..0x134cac）
 * @func 0x134c14 0x134cac  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetReal(RValue const*, int) / Audio_PlaySoundOn(int, int, int, double)
 * 字段偏移 top8: 0x8c×1 / 0x20×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134c14 ldr r3, [pc, #0x8c]
 *   @0x134c18 push {r4, r5, r6, r7, r8, lr}
 *   @0x134c1c ldr r3, [pc, r3]
 *   @0x134c20 sub sp, sp, #8
 *   @0x134c24 mov r5, r0
 *   @0x134c28 ldrb r1, [r3]
 *   @0x134c2c ldr r4, [sp, #0x20]
 *   @0x134c30 cmp r1, #0
 *   @0x134c34 bne 0x134ca0 <_Z18F_AudioPlaySoundOnR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x134c38 str r1, [r0, #0xc]
 *   @0x134c3c mov r0, r4
 *   @0x134c40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134c44 mov r1, #1
 *   @0x134c48 mov r7, r0
 *   @0x134c4c mov r0, r4
 *   @0x134c50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134c54 mov r1, #2
 *   @0x134c58 mov r6, r0
 *   @0x134c5c mov r0, r4
 *   @0x134c60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134c64 mov r1, #3
 *   @0x134c68 mov r8, r0
 *   @0x134c6c mov r0, r4
 *   @0x134c70 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134c74 mov r2, r8
 *   @0x134c78 strd r0, r1, [sp]
 *   @0x134c7c mov r1, r6
 *   @0x134c80 mov r0, r7
 *   @0x134c84 bl 0x21b8c0 <_Z17Audio_PlaySoundOniiid>
 *   @0x134c88 vmov s15, r0
 *   @0x134c8c vcvt.f64.s32 d7, s15
 *   @0x134c90 vmov r0, r1, d7
 *   @0x134c94 vmov r2, s14
 *   @0x134c98 mov r3, r1
 *   @0x134c9c stm r5, {r2, r3}
 *   @0x134ca0 add sp, sp, #8
 *   @0x134ca4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x134ca8 eoreq r10, r11, r0, lsr r4
 *
 * ══ §92/197 SGamepadEntry::FromString(char const*)  0x152694  size 152  38 条（0x152694..0x15272c）
 * @func 0x152694 0x15272c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66b8×2
 * 字段偏移 top8: 0x4×2 / 0x4c×1 / 0x48×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x152694 push {r3, r4, r5, lr}
 *   @0x152698 mov r4, r1
 *   @0x15269c mov r5, r0
 *   @0x1526a0 add r0, r1, #1
 *   @0x1526a4 bl 0xb66b8 <atoi@plt>
 *   @0x1526a8 ldrb r3, [r4]
 *   @0x1526ac cmp r3, #98
 *   @0x1526b0 beq 0x152714 <_ZN13SGamepadEntry10FromStringEPKc+0x80>
 *   @0x1526b4 cmp r3, #104
 *   @0x1526b8 beq 0x1526f8 <_ZN13SGamepadEntry10FromStringEPKc+0x64>
 *   @0x1526bc cmp r3, #97
 *   @0x1526c0 streq r0, [r5, #0x4]
 *   @0x1526c4 moveq r3, #1
 *   @0x1526c8 streq r3, [r5]
 *   @0x1526cc popeq {r3, r4, r5, pc}
 *   @0x1526d0 ldr r3, [pc, #0x4c]
 *   @0x1526d4 mov r2, r4
 *   @0x1526d8 ldr r1, [pc, #0x48]
 *   @0x1526dc ldr r3, [pc, r3]
 *   @0x1526e0 add r1, pc, r1
 *   @0x1526e4 ldr r0, [r3]
 *   @0x1526e8 ldr r3, [r0]
 *   @0x1526ec ldr r3, [r3, #0xc]
 *   @0x1526f0 blx r3
 *   @0x1526f4 pop {r3, r4, r5, pc}
 *   @0x1526f8 str r0, [r5, #0x4]
 *   @0x1526fc mov r3, #3
 *   @0x152700 add r0, r4, #3
 *   @0x152704 str r3, [r5]
 *   @0x152708 bl 0xb66b8 <atoi@plt>
 *   @0x15270c str r0, [r5, #0x8]
 *   @0x152710 pop {r3, r4, r5, pc}
 *   @0x152714 mov r3, #2
 *   @0x152718 str r0, [r5, #0x4]
 *   @0x15271c str r3, [r5]
 *   @0x152720 pop {r3, r4, r5, pc}
 *   @0x152724 eoreq r11, r9, r4, ror #4
 *   @0x152728 andseq r3, pc, r4, lsr #10
 *
 * ══ §93/197 F_YoYo_FacebookSendInvite(RValue&, CInstance*, CInstance*, int, RValue*)  0x157450  size 152  38 条（0x157450..0x1574e8）
 * @func 0x157450 0x1574e8  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×4 / YYGetInt32(RValue const*, int) / FacebookSendInviteM(char*, char*, char*, char*, int)
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157450 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x157454 sub sp, sp, #12
 *   @0x157458 mov r5, r0
 *   @0x15745c mov r1, #0
 *   @0x157460 ldr r4, [sp, #0x28]
 *   @0x157464 str r1, [r0, #0xc]
 *   @0x157468 mov r0, r4
 *   @0x15746c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157470 mov r1, #1
 *   @0x157474 mov r6, r0
 *   @0x157478 mov r0, r4
 *   @0x15747c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157480 mov r1, #2
 *   @0x157484 mov r9, r0
 *   @0x157488 mov r0, r4
 *   @0x15748c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157490 mov r1, #3
 *   @0x157494 mov r8, r0
 *   @0x157498 mov r0, r4
 *   @0x15749c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1574a0 mov r1, #4
 *   @0x1574a4 mov r7, r0
 *   @0x1574a8 mov r0, r4
 *   @0x1574ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1574b0 mov r1, r9
 *   @0x1574b4 mov r2, r8
 *   @0x1574b8 mov r3, r7
 *   @0x1574bc str r0, [sp]
 *   @0x1574c0 mov r0, r6
 *   @0x1574c4 bl 0x15ece4 <_Z19FacebookSendInviteMPcS_S_S_i>
 *   @0x1574c8 vmov s15, r0
 *   @0x1574cc vcvt.f64.s32 d7, s15
 *   @0x1574d0 vmov r0, r1, d7
 *   @0x1574d4 vmov r2, s14
 *   @0x1574d8 mov r3, r1
 *   @0x1574dc stm r5, {r2, r3}
 *   @0x1574e0 add sp, sp, #12
 *   @0x1574e4 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §94/197 GR_3DM_Vertex_N_Color(int, float, float, float, float, float, float, unsigned int, float)  0x165704  size 152  38 条（0x165704..0x16579c）
 * @func 0x165704 0x16579c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Vertex_N_Color(int, float, float, float, float, float, float, unsigned int, float)+0x88 / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x74×1 / 0x64×1 / 0x4×1 / 0x2×1 / 0x34×1 / 0x18×1 / 0x1c×1 / 0x10×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165704 cmp r0, #0
 *   @0x165708 push {r4, lr}
 *   @0x16570c mov r4, r2
 *   @0x165710 sub sp, sp, #32
 *   @0x165714 blt 0x16578c <_Z21GR_3DM_Vertex_N_Coloriffffffjf+0x88>
 *   @0x165718 ldr r12, [pc, #0x74]
 *   @0x16571c ldr r12, [pc, r12]
 *   @0x165720 ldr r12, [r12]
 *   @0x165724 cmp r0, r12
 *   @0x165728 bge 0x16578c <_Z21GR_3DM_Vertex_N_Coloriffffffjf+0x88>
 *   @0x16572c ldr r12, [pc, #0x64]
 *   @0x165730 ldr r12, [pc, r12]
 *   @0x165734 ldr r2, [r12, #0x4]
 *   @0x165738 ldr r0, [r2, r0, lsl #2]
 *   @0x16573c cmp r0, #0
 *   @0x165740 beq 0x16578c <_Z21GR_3DM_Vertex_N_Coloriffffffjf+0x88>
 *   @0x165744 ldr r12, [sp, #0x34]
 *   @0x165748 vldr s15, [sp, #40]
 *   @0x16574c str r3, [sp]
 *   @0x165750 vstr s15, [sp, #4]
 *   @0x165754 mov r2, r1
 *   @0x165758 vldr s15, [sp, #44]
 *   @0x16575c mov r1, #0
 *   @0x165760 vstr s15, [sp, #8]
 *   @0x165764 str r1, [sp, #0x18]
 *   @0x165768 vldr s15, [sp, #48]
 *   @0x16576c str r1, [sp, #0x1c]
 *   @0x165770 vstr s15, [sp, #12]
 *   @0x165774 mov r3, r4
 *   @0x165778 vldr s15, [sp, #56]
 *   @0x16577c str r12, [sp, #0x10]
 *   @0x165780 vstr s15, [sp, #20]
 *   @0x165784 mov r1, #7
 *   @0x165788 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x16578c add sp, sp, #32
 *   @0x165790 pop {r4, pc}
 *   @0x165794 .word 0x0028a9d4
 *   @0x165798 eoreq r10, r8, r4, asr #19
 *
 * ══ §95/197 GR_3DM_Vertex_N_Texture(int, float, float, float, float, float, float, float, float)  0x16579c  size 152  38 条（0x16579c..0x165834）
 * @func 0x16579c 0x165834  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Vertex_N_Texture(int, float, float, float, float, float, float, float, float)+0x88 / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x74×1 / 0x64×1 / 0x4×1 / 0x2×1 / 0x18×1 / 0x1c×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16579c cmp r0, #0
 *   @0x1657a0 push {r4, lr}
 *   @0x1657a4 mov r4, r2
 *   @0x1657a8 sub sp, sp, #32
 *   @0x1657ac blt 0x165824 <_Z23GR_3DM_Vertex_N_Textureiffffffff+0x88>
 *   @0x1657b0 ldr r12, [pc, #0x74]
 *   @0x1657b4 ldr r12, [pc, r12]
 *   @0x1657b8 ldr r12, [r12]
 *   @0x1657bc cmp r0, r12
 *   @0x1657c0 bge 0x165824 <_Z23GR_3DM_Vertex_N_Textureiffffffff+0x88>
 *   @0x1657c4 ldr r12, [pc, #0x64]
 *   @0x1657c8 ldr r12, [pc, r12]
 *   @0x1657cc ldr r2, [r12, #0x4]
 *   @0x1657d0 ldr r0, [r2, r0, lsl #2]
 *   @0x1657d4 cmp r0, #0
 *   @0x1657d8 beq 0x165824 <_Z23GR_3DM_Vertex_N_Textureiffffffff+0x88>
 *   @0x1657dc vldr s15, [sp, #40]
 *   @0x1657e0 mov r12, #0
 *   @0x1657e4 str r3, [sp]
 *   @0x1657e8 vstr s15, [sp, #4]
 *   @0x1657ec mov r2, r1
 *   @0x1657f0 vldr s15, [sp, #44]
 *   @0x1657f4 mov r3, r4
 *   @0x1657f8 vstr s15, [sp, #8]
 *   @0x1657fc mov r1, #8
 *   @0x165800 vldr s15, [sp, #48]
 *   @0x165804 str r12, [sp, #0x18]
 *   @0x165808 vstr s15, [sp, #12]
 *   @0x16580c str r12, [sp, #0x1c]
 *   @0x165810 vldr s15, [sp, #52]
 *   @0x165814 vstr s15, [sp, #16]
 *   @0x165818 vldr s15, [sp, #56]
 *   @0x16581c vstr s15, [sp, #20]
 *   @0x165820 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x165824 add sp, sp, #32
 *   @0x165828 pop {r4, pc}
 *   @0x16582c eoreq r10, r8, r12, lsr r9
 *   @0x165830 eoreq r10, r8, r12, lsr #18
 *
 * ══ §96/197 GR_3DM_Block(int, float, float, float, float, float, float, float, float)  0x16594c  size 152  38 条（0x16594c..0x1659e4）
 * @func 0x16594c 0x1659e4  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Block(int, float, float, float, float, float, float, float, float)+0x88 / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x74×1 / 0x64×1 / 0x4×1 / 0x2×1 / 0x18×1 / 0x1c×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16594c cmp r0, #0
 *   @0x165950 push {r4, lr}
 *   @0x165954 mov r4, r2
 *   @0x165958 sub sp, sp, #32
 *   @0x16595c blt 0x1659d4 <_Z12GR_3DM_Blockiffffffff+0x88>
 *   @0x165960 ldr r12, [pc, #0x74]
 *   @0x165964 ldr r12, [pc, r12]
 *   @0x165968 ldr r12, [r12]
 *   @0x16596c cmp r0, r12
 *   @0x165970 bge 0x1659d4 <_Z12GR_3DM_Blockiffffffff+0x88>
 *   @0x165974 ldr r12, [pc, #0x64]
 *   @0x165978 ldr r12, [pc, r12]
 *   @0x16597c ldr r2, [r12, #0x4]
 *   @0x165980 ldr r0, [r2, r0, lsl #2]
 *   @0x165984 cmp r0, #0
 *   @0x165988 beq 0x1659d4 <_Z12GR_3DM_Blockiffffffff+0x88>
 *   @0x16598c vldr s15, [sp, #40]
 *   @0x165990 mov r12, #0
 *   @0x165994 str r3, [sp]
 *   @0x165998 vstr s15, [sp, #4]
 *   @0x16599c mov r2, r1
 *   @0x1659a0 vldr s15, [sp, #44]
 *   @0x1659a4 mov r3, r4
 *   @0x1659a8 vstr s15, [sp, #8]
 *   @0x1659ac mov r1, #10
 *   @0x1659b0 vldr s15, [sp, #48]
 *   @0x1659b4 str r12, [sp, #0x18]
 *   @0x1659b8 vstr s15, [sp, #12]
 *   @0x1659bc str r12, [sp, #0x1c]
 *   @0x1659c0 vldr s15, [sp, #52]
 *   @0x1659c4 vstr s15, [sp, #16]
 *   @0x1659c8 vldr s15, [sp, #56]
 *   @0x1659cc vstr s15, [sp, #20]
 *   @0x1659d0 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x1659d4 add sp, sp, #32
 *   @0x1659d8 pop {r4, pc}
 *   @0x1659dc eoreq r10, r8, r12, lsl #15
 *   @0x1659e0 eoreq r10, r8, r12, ror r7
 *
 * ══ §97/197 GR_3DM_Wall(int, float, float, float, float, float, float, float, float)  0x165bb8  size 152  38 条（0x165bb8..0x165c50）
 * @func 0x165bb8 0x165c50  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Wall(int, float, float, float, float, float, float, float, float)+0x88 / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x74×1 / 0x64×1 / 0x4×1 / 0x2×1 / 0x18×1 / 0x1c×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165bb8 cmp r0, #0
 *   @0x165bbc push {r4, lr}
 *   @0x165bc0 mov r4, r2
 *   @0x165bc4 sub sp, sp, #32
 *   @0x165bc8 blt 0x165c40 <_Z11GR_3DM_Walliffffffff+0x88>
 *   @0x165bcc ldr r12, [pc, #0x74]
 *   @0x165bd0 ldr r12, [pc, r12]
 *   @0x165bd4 ldr r12, [r12]
 *   @0x165bd8 cmp r0, r12
 *   @0x165bdc bge 0x165c40 <_Z11GR_3DM_Walliffffffff+0x88>
 *   @0x165be0 ldr r12, [pc, #0x64]
 *   @0x165be4 ldr r12, [pc, r12]
 *   @0x165be8 ldr r2, [r12, #0x4]
 *   @0x165bec ldr r0, [r2, r0, lsl #2]
 *   @0x165bf0 cmp r0, #0
 *   @0x165bf4 beq 0x165c40 <_Z11GR_3DM_Walliffffffff+0x88>
 *   @0x165bf8 vldr s15, [sp, #40]
 *   @0x165bfc mov r12, #0
 *   @0x165c00 str r3, [sp]
 *   @0x165c04 vstr s15, [sp, #4]
 *   @0x165c08 mov r2, r1
 *   @0x165c0c vldr s15, [sp, #44]
 *   @0x165c10 mov r3, r4
 *   @0x165c14 vstr s15, [sp, #8]
 *   @0x165c18 mov r1, #14
 *   @0x165c1c vldr s15, [sp, #48]
 *   @0x165c20 str r12, [sp, #0x18]
 *   @0x165c24 vstr s15, [sp, #12]
 *   @0x165c28 str r12, [sp, #0x1c]
 *   @0x165c2c vldr s15, [sp, #52]
 *   @0x165c30 vstr s15, [sp, #16]
 *   @0x165c34 vldr s15, [sp, #56]
 *   @0x165c38 vstr s15, [sp, #20]
 *   @0x165c3c bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x165c40 add sp, sp, #32
 *   @0x165c44 pop {r4, pc}
 *   @0x165c48 eoreq r10, r8, r0, lsr #10
 *   @0x165c4c eoreq r10, r8, r0, lsl r5
 *
 * ══ §98/197 GR_3DM_Floor(int, float, float, float, float, float, float, float, float)  0x165c50  size 152  38 条（0x165c50..0x165ce8）
 * @func 0x165c50 0x165ce8  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Floor(int, float, float, float, float, float, float, float, float)+0x88 / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x74×1 / 0x64×1 / 0x4×1 / 0x2×1 / 0x18×1 / 0x1c×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165c50 cmp r0, #0
 *   @0x165c54 push {r4, lr}
 *   @0x165c58 mov r4, r2
 *   @0x165c5c sub sp, sp, #32
 *   @0x165c60 blt 0x165cd8 <_Z12GR_3DM_Flooriffffffff+0x88>
 *   @0x165c64 ldr r12, [pc, #0x74]
 *   @0x165c68 ldr r12, [pc, r12]
 *   @0x165c6c ldr r12, [r12]
 *   @0x165c70 cmp r0, r12
 *   @0x165c74 bge 0x165cd8 <_Z12GR_3DM_Flooriffffffff+0x88>
 *   @0x165c78 ldr r12, [pc, #0x64]
 *   @0x165c7c ldr r12, [pc, r12]
 *   @0x165c80 ldr r2, [r12, #0x4]
 *   @0x165c84 ldr r0, [r2, r0, lsl #2]
 *   @0x165c88 cmp r0, #0
 *   @0x165c8c beq 0x165cd8 <_Z12GR_3DM_Flooriffffffff+0x88>
 *   @0x165c90 vldr s15, [sp, #40]
 *   @0x165c94 mov r12, #0
 *   @0x165c98 str r3, [sp]
 *   @0x165c9c vstr s15, [sp, #4]
 *   @0x165ca0 mov r2, r1
 *   @0x165ca4 vldr s15, [sp, #44]
 *   @0x165ca8 mov r3, r4
 *   @0x165cac vstr s15, [sp, #8]
 *   @0x165cb0 mov r1, #15
 *   @0x165cb4 vldr s15, [sp, #48]
 *   @0x165cb8 str r12, [sp, #0x18]
 *   @0x165cbc vstr s15, [sp, #12]
 *   @0x165cc0 str r12, [sp, #0x1c]
 *   @0x165cc4 vldr s15, [sp, #52]
 *   @0x165cc8 vstr s15, [sp, #16]
 *   @0x165ccc vldr s15, [sp, #56]
 *   @0x165cd0 vstr s15, [sp, #20]
 *   @0x165cd4 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x165cd8 add sp, sp, #32
 *   @0x165cdc pop {r4, pc}
 *   @0x165ce0 eoreq r10, r8, r8, lsl #9
 *   @0x165ce4 eoreq r10, r8, r8, ror r4
 *
 * ══ §99/197 GR_D3D_Start_Frame()  0x1699c0  size 152  38 条（0x1699c0..0x169a58）
 * @func 0x1699c0 0x169a58  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1699c8→0x4a22b1, 0x1699e0→0x757e7c, 0x169a0c→0x757e80, 0x169a20→0x757e80
 * 调用序列: Graphics::SceneBegin()×2 / CProfiler::Pop() / CProfiler::Push(int, int)
 * 字段偏移 top8: 0x7c×2 / 0x68×1 / 0x40×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1699c0 push {r4, r5, r6, lr}
 *   @0x1699c4 ldr r4, [pc, #0x7c]
 *   @0x1699c8 ldr r3, [pc, #0x7c]
 *   @0x1699cc add r4, pc, r4
 *   @0x1699d0 ldr r3, [r4, r3]
 *   @0x1699d4 ldrb r5, [r3]
 *   @0x1699d8 cmp r5, #0
 *   @0x1699dc beq 0x169a04 <_Z18GR_D3D_Start_Framev+0x44>
 *   @0x1699e0 ldr r3, [pc, #0x68]
 *   @0x1699e4 ldr r6, [r4, r3]
 *   @0x1699e8 ldrb r3, [r6]
 *   @0x1699ec cmp r3, #0
 *   @0x1699f0 bne 0x169a20 <_Z18GR_D3D_Start_Framev+0x60>
 *   @0x1699f4 bl 0x17dd58 <_ZN8Graphics10SceneBeginEv>
 *   @0x1699f8 ldrb r3, [r6]
 *   @0x1699fc cmp r3, #0
 *   @0x169a00 bne 0x169a0c <_Z18GR_D3D_Start_Framev+0x4c>
 *   @0x169a04 mov r0, r5
 *   @0x169a08 pop {r4, r5, r6, pc}
 *   @0x169a0c ldr r3, [pc, #0x40]
 *   @0x169a10 ldr r0, [r4, r3]
 *   @0x169a14 bl 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x169a18 mov r0, r5
 *   @0x169a1c pop {r4, r5, r6, pc}
 *   @0x169a20 ldr r3, [pc, #0x2c]
 *   @0x169a24 mov r1, #6
 *   @0x169a28 mov r2, #25
 *   @0x169a2c ldr r0, [r4, r3]
 *   @0x169a30 bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x169a34 bl 0x17dd58 <_ZN8Graphics10SceneBeginEv>
 *   @0x169a38 ldrb r3, [r6]
 *   @0x169a3c cmp r3, #0
 *   @0x169a40 beq 0x169a04 <_Z18GR_D3D_Start_Framev+0x44>
 *   @0x169a44 b 0x169a0c <_Z18GR_D3D_Start_Framev+0x4c>
 *   @0x169a48 eoreq r8, r8, r4, lsl #5
 *   @0x169a4c .word 0xffffe4d0
 *   @0x169a50 .word 0xffffbf18
 *   @0x169a54 .word 0xffffbf1c
 *
 * ══ §100/197 F_CameraSetViewPos(RValue&, CInstance*, CInstance*, int, RValue*)  0x16fab4  size 152  38 条（0x16fab4..0x16fb4c）
 * @func 0x16fab4 0x16fb4c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::SetViewX(float) / CCamera::SetViewY(float)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x64×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16fab4 cmp r3, #3
 *   @0x16fab8 push {r3, r4, r5, lr}
 *   @0x16fabc mov r3, #0
 *   @0x16fac0 mov r1, r3
 *   @0x16fac4 ldr r4, [sp, #0x10]
 *   @0x16fac8 movt r3, #0xbff0
 *   @0x16facc str r1, [r0, #0xc]
 *   @0x16fad0 stm r0, {r1, r3}
 *   @0x16fad4 beq 0x16fae8 <_Z18F_CameraSetViewPosR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x16fad8 ldr r0, [pc, #0x64]
 *   @0x16fadc pop {r3, r4, r5, lr}
 *   @0x16fae0 add r0, pc, r0
 *   @0x16fae4 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16fae8 mov r0, r4
 *   @0x16faec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16faf0 ldr r3, [pc, #0x50]
 *   @0x16faf4 mov r1, r0
 *   @0x16faf8 ldr r0, [pc, r3]
 *   @0x16fafc bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16fb00 subs r5, r0, #0
 *   @0x16fb04 popeq {r3, r4, r5, pc}
 *   @0x16fb08 mov r0, r4
 *   @0x16fb0c mov r1, #1
 *   @0x16fb10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fb14 mov r1, r0
 *   @0x16fb18 mov r0, r5
 *   @0x16fb1c bl 0x16d29c <_ZN7CCamera8SetViewXEf>
 *   @0x16fb20 mov r0, r4
 *   @0x16fb24 mov r1, #2
 *   @0x16fb28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fb2c mov r1, r0
 *   @0x16fb30 mov r0, r5
 *   @0x16fb34 bl 0x16d2ac <_ZN7CCamera8SetViewYEf>
 *   @0x16fb38 mov r0, r5
 *   @0x16fb3c pop {r3, r4, r5, lr}
 *   @0x16fb40 b 0x16d36c <_ZN7CCamera12SetViewDirtyEv>
 *   @0x16fb44 andseq r11, sp, r8, ror #8
 *   @0x16fb48 eoreq lr, r7, r12, ror r1
 *
 * ══ §101/197 F_CameraSetViewSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x16fb4c  size 152  38 条（0x16fb4c..0x16fbe4）
 * @func 0x16fb4c 0x16fbe4  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::SetViewWidth(float) / CCamera::SetViewHeight(float)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x64×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16fb4c cmp r3, #3
 *   @0x16fb50 push {r3, r4, r5, lr}
 *   @0x16fb54 mov r3, #0
 *   @0x16fb58 mov r1, r3
 *   @0x16fb5c ldr r4, [sp, #0x10]
 *   @0x16fb60 movt r3, #0xbff0
 *   @0x16fb64 str r1, [r0, #0xc]
 *   @0x16fb68 stm r0, {r1, r3}
 *   @0x16fb6c beq 0x16fb80 <_Z19F_CameraSetViewSizeR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x16fb70 ldr r0, [pc, #0x64]
 *   @0x16fb74 pop {r3, r4, r5, lr}
 *   @0x16fb78 add r0, pc, r0
 *   @0x16fb7c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16fb80 mov r0, r4
 *   @0x16fb84 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16fb88 ldr r3, [pc, #0x50]
 *   @0x16fb8c mov r1, r0
 *   @0x16fb90 ldr r0, [pc, r3]
 *   @0x16fb94 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16fb98 subs r5, r0, #0
 *   @0x16fb9c popeq {r3, r4, r5, pc}
 *   @0x16fba0 mov r0, r4
 *   @0x16fba4 mov r1, #1
 *   @0x16fba8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fbac mov r1, r0
 *   @0x16fbb0 mov r0, r5
 *   @0x16fbb4 bl 0x16d2bc <_ZN7CCamera12SetViewWidthEf>
 *   @0x16fbb8 mov r0, r4
 *   @0x16fbbc mov r1, #2
 *   @0x16fbc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x16fbc4 mov r1, r0
 *   @0x16fbc8 mov r0, r5
 *   @0x16fbcc bl 0x16d2cc <_ZN7CCamera13SetViewHeightEf>
 *   @0x16fbd0 mov r0, r5
 *   @0x16fbd4 pop {r3, r4, r5, lr}
 *   @0x16fbd8 b 0x16d36c <_ZN7CCamera12SetViewDirtyEv>
 *   @0x16fbdc andseq r11, sp, r4, lsl #8
 *   @0x16fbe0 eoreq lr, r7, r4, ror #1
 *
 * ══ §102/197 VertexBuffer::UpdateFromBuffer(void*, int)  0x1838c0  size 152  38 条（0x1838c0..0x183958）
 * @func 0x1838c0 0x183958  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x7c×1 / 0xc×1 / 0x58×1 / 0x8×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1838c0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1838c4 mov r5, r0
 *   @0x1838c8 ldr r3, [pc, #0x7c]
 *   @0x1838cc mov r6, r1
 *   @0x1838d0 mov r7, r2
 *   @0x1838d4 ldr r3, [pc, r3]
 *   @0x1838d8 ldrb r3, [r3]
 *   @0x1838dc cmp r3, #0
 *   @0x1838e0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1838e4 ldr r3, [r0, #0xc]
 *   @0x1838e8 cmp r3, #0
 *   @0x1838ec popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1838f0 ldr r4, [pc, #0x58]
 *   @0x1838f4 movw r0, #0x8892
 *   @0x1838f8 ldr r1, [r3]
 *   @0x1838fc ldr r4, [pc, r4]
 *   @0x183900 ldr r3, [r4]
 *   @0x183904 blx r3
 *   @0x183908 ldr r3, [r5, #0x8]
 *   @0x18390c ldr r0, [pc, #0x40]
 *   @0x183910 movw r12, #0x88e4
 *   @0x183914 tst r3, #2
 *   @0x183918 movw r3, #0x88e0
 *   @0x18391c ldr r0, [pc, r0]
 *   @0x183920 mov r1, r7
 *   @0x183924 moveq r3, r12
 *   @0x183928 mov r2, r6
 *   @0x18392c ldr r12, [r0]
 *   @0x183930 movw r0, #0x8892
 *   @0x183934 blx r12
 *   @0x183938 ldr r3, [r4]
 *   @0x18393c movw r0, #0x8892
 *   @0x183940 mov r1, #0
 *   @0x183944 blx r3
 *   @0x183948 pop {r3, r4, r5, r6, r7, pc}
 *   @0x18394c eoreq r12, r6, r12, asr r11
 *   @0x183950 mlaeq r6, r0, lr, r9
 *   @0x183954 eoreq r9, r6, r4, ror lr
 *
 * ══ §103/197 jpeg_memory_src(jpeg_decompress_struct*, unsigned char const*, unsigned int)  0x18a690  size 152  38 条（0x18a690..0x18a728）
 * @func 0x18a690 0x18a728  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×3 / 0x60×3 / 0x4×2 / 0x5c×1 / 0x58×1 / 0x8×1 / 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18a690 ldr r3, [r0, #0x18]
 *   @0x18a694 push {r4, r5, r6, lr}
 *   @0x18a698 cmp r3, #0
 *   @0x18a69c mov r4, r0
 *   @0x18a6a0 mov r6, r1
 *   @0x18a6a4 mov r5, r2
 *   @0x18a6a8 beq 0x18a6f4 <_Z15jpeg_memory_srcP22jpeg_decompress_structPKhj+0x64>
 *   @0x18a6ac ldr r4, [pc, #0x60]
 *   @0x18a6b0 ldr r12, [pc, #0x60]
 *   @0x18a6b4 ldr r1, [pc, #0x60]
 *   @0x18a6b8 add r4, pc, r4
 *   @0x18a6bc ldr r2, [pc, #0x5c]
 *   @0x18a6c0 add r12, pc, r12
 *   @0x18a6c4 ldr r0, [pc, #0x58]
 *   @0x18a6c8 add r1, pc, r1
 *   @0x18a6cc add r2, pc, r2
 *   @0x18a6d0 str r6, [r3]
 *   @0x18a6d4 ldr r0, [pc, r0]
 *   @0x18a6d8 str r5, [r3, #0x4]
 *   @0x18a6dc str r4, [r3, #0x8]
 *   @0x18a6e0 str r0, [r3, #0x14]
 *   @0x18a6e4 str r12, [r3, #0xc]
 *   @0x18a6e8 str r1, [r3, #0x10]
 *   @0x18a6ec str r2, [r3, #0x18]
 *   @0x18a6f0 pop {r4, r5, r6, pc}
 *   @0x18a6f4 ldr r12, [r0, #0x4]
 *   @0x18a6f8 mov r1, r3
 *   @0x18a6fc mov r2, #32
 *   @0x18a700 ldr r3, [r12]
 *   @0x18a704 blx r3
 *   @0x18a708 mov r3, r0
 *   @0x18a70c str r0, [r4, #0x18]
 *   @0x18a710 b 0x18a6ac <_Z15jpeg_memory_srcP22jpeg_decompress_structPKhj+0x1c>
 *   @0x18a714 .word 0xffffff5c
 *   @0x18a718 .word 0xffffff58
 *   @0x18a71c .word 0xffffff58
 *   @0x18a720 .word 0xffffff8c
 *   @0x18a724 .word 0x00265ef0
 *
 * ══ §104/197 Motion_Grid_ClearAll(int)  0x19a1d4  size 152  38 条（0x19a1d4..0x19a26c）
 * @func 0x19a1d4 0x19a26c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Motion_Grid_ClearAll(int)+0x88×2 / Motion_Grid_ClearAll(int)+0x7c / Motion_Grid_ClearAll(int)+0x50
 * 字段偏移 top8: 0x2×2 / 0x14×2 / 0x18×2 / 0x-4×1 / 0x7c×1 / 0x6c×1 / 0x1c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19a1d4 cmp r0, #0
 *   @0x19a1d8 str r4, [sp, #-0x4]!
 *   @0x19a1dc blt 0x19a25c <_Z20Motion_Grid_ClearAlli+0x88>
 *   @0x19a1e0 ldr r3, [pc, #0x7c]
 *   @0x19a1e4 ldr r3, [pc, r3]
 *   @0x19a1e8 ldr r3, [r3]
 *   @0x19a1ec cmp r0, r3
 *   @0x19a1f0 bge 0x19a25c <_Z20Motion_Grid_ClearAlli+0x88>
 *   @0x19a1f4 ldr r3, [pc, #0x6c]
 *   @0x19a1f8 ldr r3, [pc, r3]
 *   @0x19a1fc ldr r3, [r3]
 *   @0x19a200 ldr r0, [r3, r0, lsl #2]
 *   @0x19a204 cmp r0, #0
 *   @0x19a208 beq 0x19a25c <_Z20Motion_Grid_ClearAlli+0x88>
 *   @0x19a20c ldr r3, [r0, #0x14]
 *   @0x19a210 cmp r3, #0
 *   @0x19a214 ble 0x19a25c <_Z20Motion_Grid_ClearAlli+0x88>
 *   @0x19a218 ldr r2, [r0, #0x18]
 *   @0x19a21c mov r1, #0
 *   @0x19a220 mov r4, r1
 *   @0x19a224 cmp r2, #0
 *   @0x19a228 ble 0x19a250 <_Z20Motion_Grid_ClearAlli+0x7c>
 *   @0x19a22c ldr r12, [r0, #0x1c]
 *   @0x19a230 mov r3, #0
 *   @0x19a234 mla r2, r2, r1, r3
 *   @0x19a238 add r3, r3, #1
 *   @0x19a23c str r4, [r12, r2, lsl #2]
 *   @0x19a240 ldr r2, [r0, #0x18]
 *   @0x19a244 cmp r2, r3
 *   @0x19a248 bgt 0x19a234 <_Z20Motion_Grid_ClearAlli+0x60>
 *   @0x19a24c ldr r3, [r0, #0x14]
 *   @0x19a250 add r1, r1, #1
 *   @0x19a254 cmp r1, r3
 *   @0x19a258 blt 0x19a224 <_Z20Motion_Grid_ClearAlli+0x50>
 *   @0x19a25c ldr r4, [sp], #4
 *   @0x19a260 bx lr
 *   @0x19a264 eoreq r6, r5, r8, asr #9
 *   @0x19a268 .word 0x002564b8
 *
 * ══ §105/197 ParticleSystem_DestroyAll()  0x1a4590  size 152  38 条（0x1a4590..0x1a4628）
 * @func 0x1a4590 0x1a4628  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / ParticleSystem_DestroyAll()+0x34 / ParticleSystem_Destroy(int) / ParticleSystem_DestroyAll()+0x74
 * 字段偏移 top8: 0x4×4 / 0x2×2 / 0x84×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a4590 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a4594 ldr r6, [pc, #0x84]
 *   @0x1a4598 ldr r6, [pc, r6]
 *   @0x1a459c ldr r3, [r6]
 *   @0x1a45a0 cmp r3, #0
 *   @0x1a45a4 movgt r4, #0
 *   @0x1a45a8 ble 0x1a45c4 <_Z25ParticleSystem_DestroyAllv+0x34>
 *   @0x1a45ac mov r0, r4
 *   @0x1a45b0 add r4, r4, #1
 *   @0x1a45b4 bl 0x1a454c <_Z22ParticleSystem_Destroyi>
 *   @0x1a45b8 ldr r3, [r6]
 *   @0x1a45bc cmp r3, r4
 *   @0x1a45c0 bgt 0x1a45ac <_Z25ParticleSystem_DestroyAllv+0x1c>
 *   @0x1a45c4 ldr r5, [pc, #0x58]
 *   @0x1a45c8 ldr r5, [pc, r5]
 *   @0x1a45cc ldr r3, [r5]
 *   @0x1a45d0 cmp r3, #0
 *   @0x1a45d4 movgt r4, #0
 *   @0x1a45d8 movgt r7, r4
 *   @0x1a45dc ble 0x1a4604 <_Z25ParticleSystem_DestroyAllv+0x74>
 *   @0x1a45e0 ldr r3, [r5, #0x4]
 *   @0x1a45e4 ldr r0, [r3, r4, lsl #2]
 *   @0x1a45e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a45ec ldr r2, [r5, #0x4]
 *   @0x1a45f0 ldr r3, [r5]
 *   @0x1a45f4 str r7, [r2, r4, lsl #2]
 *   @0x1a45f8 add r4, r4, #1
 *   @0x1a45fc cmp r3, r4
 *   @0x1a4600 bgt 0x1a45e0 <_Z25ParticleSystem_DestroyAllv+0x50>
 *   @0x1a4604 ldr r0, [r5, #0x4]
 *   @0x1a4608 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a460c mov r3, #0
 *   @0x1a4610 str r3, [r5, #0x4]
 *   @0x1a4614 str r3, [r5]
 *   @0x1a4618 str r3, [r6]
 *   @0x1a461c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a4620 eoreq r12, r4, r12, lsl r2
 *   @0x1a4624 .word 0x0024c1f0
 *
 * ══ §106/197 F_LayerSpriteGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd7dc  size 152  38 条（0x1bd7dc..0x1bd874）
 * @func 0x1bd7dc 0x1bd874  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x60×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd7dc cmp r3, #1
 *   @0x1bd7e0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bd7e4 mov r3, #0
 *   @0x1bd7e8 mov r4, r3
 *   @0x1bd7ec mov r5, r0
 *   @0x1bd7f0 movt r3, #0xbff0
 *   @0x1bd7f4 str r4, [r0, #0xc]
 *   @0x1bd7f8 str r3, [r0, #0x4]
 *   @0x1bd7fc str r4, [r0]
 *   @0x1bd800 ldr r6, [sp, #0x18]
 *   @0x1bd804 beq 0x1bd81c <_Z21F_LayerSpriteGetSpeedR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bd808 ldr r0, [pc, #0x60]
 *   @0x1bd80c mov r1, r4
 *   @0x1bd810 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bd814 add r0, pc, r0
 *   @0x1bd818 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd81c str r4, [r0]
 *   @0x1bd820 str r4, [r0, #0x4]
 *   @0x1bd824 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd828 mov r1, r4
 *   @0x1bd82c mov r7, r0
 *   @0x1bd830 mov r0, r6
 *   @0x1bd834 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd838 mov r2, r4
 *   @0x1bd83c mov r1, r0
 *   @0x1bd840 mov r0, r7
 *   @0x1bd844 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd848 cmp r0, #0
 *   @0x1bd84c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bd850 ldr r3, [r0]
 *   @0x1bd854 cmp r3, #4
 *   @0x1bd858 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bd85c vldr s15, [r0, #36]
 *   @0x1bd860 vcvt.f64.f32 d6, s15
 *   @0x1bd864 vmov r2, r3, d6
 *   @0x1bd868 stm r5, {r2, r3}
 *   @0x1bd86c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bd870 andseq r0, r9, r12, lsr #27
 *
 * ══ §107/197 F_LayerSpriteGetAngle(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd9b4  size 152  38 条（0x1bd9b4..0x1bda4c）
 * @func 0x1bd9b4 0x1bda4c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x60×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd9b4 cmp r3, #1
 *   @0x1bd9b8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bd9bc mov r3, #0
 *   @0x1bd9c0 mov r4, r3
 *   @0x1bd9c4 mov r5, r0
 *   @0x1bd9c8 movt r3, #0xbff0
 *   @0x1bd9cc str r4, [r0, #0xc]
 *   @0x1bd9d0 str r3, [r0, #0x4]
 *   @0x1bd9d4 str r4, [r0]
 *   @0x1bd9d8 ldr r6, [sp, #0x18]
 *   @0x1bd9dc beq 0x1bd9f4 <_Z21F_LayerSpriteGetAngleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bd9e0 ldr r0, [pc, #0x60]
 *   @0x1bd9e4 mov r1, r4
 *   @0x1bd9e8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bd9ec add r0, pc, r0
 *   @0x1bd9f0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd9f4 str r4, [r0]
 *   @0x1bd9f8 str r4, [r0, #0x4]
 *   @0x1bd9fc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bda00 mov r1, r4
 *   @0x1bda04 mov r7, r0
 *   @0x1bda08 mov r0, r6
 *   @0x1bda0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bda10 mov r2, r4
 *   @0x1bda14 mov r1, r0
 *   @0x1bda18 mov r0, r7
 *   @0x1bda1c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bda20 cmp r0, #0
 *   @0x1bda24 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bda28 ldr r3, [r0]
 *   @0x1bda2c cmp r3, #4
 *   @0x1bda30 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bda34 vldr s15, [r0, #52]
 *   @0x1bda38 vcvt.f64.f32 d6, s15
 *   @0x1bda3c vmov r2, r3, d6
 *   @0x1bda40 stm r5, {r2, r3}
 *   @0x1bda44 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bda48 andseq r0, r9, r12, ror r12
 *
 * ══ §108/197 F_LayerSpriteGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bdae8  size 152  38 条（0x1bdae8..0x1bdb80）
 * @func 0x1bdae8 0x1bdb80  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x60×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bdae8 cmp r3, #1
 *   @0x1bdaec push {r3, r4, r5, r6, r7, lr}
 *   @0x1bdaf0 mov r3, #0
 *   @0x1bdaf4 mov r4, r3
 *   @0x1bdaf8 mov r5, r0
 *   @0x1bdafc movt r3, #0xbff0
 *   @0x1bdb00 str r4, [r0, #0xc]
 *   @0x1bdb04 str r3, [r0, #0x4]
 *   @0x1bdb08 str r4, [r0]
 *   @0x1bdb0c ldr r6, [sp, #0x18]
 *   @0x1bdb10 beq 0x1bdb28 <_Z21F_LayerSpriteGetAlphaR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bdb14 ldr r0, [pc, #0x60]
 *   @0x1bdb18 mov r1, r4
 *   @0x1bdb1c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bdb20 add r0, pc, r0
 *   @0x1bdb24 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bdb28 str r4, [r0]
 *   @0x1bdb2c str r4, [r0, #0x4]
 *   @0x1bdb30 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bdb34 mov r1, r4
 *   @0x1bdb38 mov r7, r0
 *   @0x1bdb3c mov r0, r6
 *   @0x1bdb40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bdb44 mov r2, r4
 *   @0x1bdb48 mov r1, r0
 *   @0x1bdb4c mov r0, r7
 *   @0x1bdb50 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bdb54 cmp r0, #0
 *   @0x1bdb58 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bdb5c ldr r3, [r0]
 *   @0x1bdb60 cmp r3, #4
 *   @0x1bdb64 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bdb68 vldr s15, [r0, #60]
 *   @0x1bdb6c vcvt.f64.f32 d6, s15
 *   @0x1bdb70 vmov r2, r3, d6
 *   @0x1bdb74 stm r5, {r2, r3}
 *   @0x1bdb78 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bdb7c ldrheq r0, [r9], -r8
 *
 * ══ §109/197 F_LayerSpriteGetX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bdb80  size 152  38 条（0x1bdb80..0x1bdc18）
 * @func 0x1bdb80 0x1bdc18  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x60×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bdb80 cmp r3, #1
 *   @0x1bdb84 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bdb88 mov r3, #0
 *   @0x1bdb8c mov r4, r3
 *   @0x1bdb90 mov r5, r0
 *   @0x1bdb94 movt r3, #0xbff0
 *   @0x1bdb98 str r4, [r0, #0xc]
 *   @0x1bdb9c str r3, [r0, #0x4]
 *   @0x1bdba0 str r4, [r0]
 *   @0x1bdba4 ldr r6, [sp, #0x18]
 *   @0x1bdba8 beq 0x1bdbc0 <_Z17F_LayerSpriteGetXR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bdbac ldr r0, [pc, #0x60]
 *   @0x1bdbb0 mov r1, r4
 *   @0x1bdbb4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bdbb8 add r0, pc, r0
 *   @0x1bdbbc b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bdbc0 str r4, [r0]
 *   @0x1bdbc4 str r4, [r0, #0x4]
 *   @0x1bdbc8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bdbcc mov r1, r4
 *   @0x1bdbd0 mov r7, r0
 *   @0x1bdbd4 mov r0, r6
 *   @0x1bdbd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bdbdc mov r2, r4
 *   @0x1bdbe0 mov r1, r0
 *   @0x1bdbe4 mov r0, r7
 *   @0x1bdbe8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bdbec cmp r0, #0
 *   @0x1bdbf0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bdbf4 ldr r3, [r0]
 *   @0x1bdbf8 cmp r3, #4
 *   @0x1bdbfc popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bdc00 vldr s15, [r0, #64]
 *   @0x1bdc04 vcvt.f64.f32 d6, s15
 *   @0x1bdc08 vmov r2, r3, d6
 *   @0x1bdc0c stm r5, {r2, r3}
 *   @0x1bdc10 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bdc14 andseq r0, r9, r8, asr r11
 *
 * ══ §110/197 F_LayerSpriteGetY(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bdc18  size 152  38 条（0x1bdc18..0x1bdcb0）
 * @func 0x1bdc18 0x1bdcb0  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x60×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bdc18 cmp r3, #1
 *   @0x1bdc1c push {r3, r4, r5, r6, r7, lr}
 *   @0x1bdc20 mov r3, #0
 *   @0x1bdc24 mov r4, r3
 *   @0x1bdc28 mov r5, r0
 *   @0x1bdc2c movt r3, #0xbff0
 *   @0x1bdc30 str r4, [r0, #0xc]
 *   @0x1bdc34 str r3, [r0, #0x4]
 *   @0x1bdc38 str r4, [r0]
 *   @0x1bdc3c ldr r6, [sp, #0x18]
 *   @0x1bdc40 beq 0x1bdc58 <_Z17F_LayerSpriteGetYR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bdc44 ldr r0, [pc, #0x60]
 *   @0x1bdc48 mov r1, r4
 *   @0x1bdc4c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bdc50 add r0, pc, r0
 *   @0x1bdc54 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bdc58 str r4, [r0]
 *   @0x1bdc5c str r4, [r0, #0x4]
 *   @0x1bdc60 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bdc64 mov r1, r4
 *   @0x1bdc68 mov r7, r0
 *   @0x1bdc6c mov r0, r6
 *   @0x1bdc70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bdc74 mov r2, r4
 *   @0x1bdc78 mov r1, r0
 *   @0x1bdc7c mov r0, r7
 *   @0x1bdc80 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bdc84 cmp r0, #0
 *   @0x1bdc88 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bdc8c ldr r3, [r0]
 *   @0x1bdc90 cmp r3, #4
 *   @0x1bdc94 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bdc98 vldr s15, [r0, #68]
 *   @0x1bdc9c vcvt.f64.f32 d6, s15
 *   @0x1bdca0 vmov r2, r3, d6
 *   @0x1bdca4 stm r5, {r2, r3}
 *   @0x1bdca8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bdcac ldrsheq r0, [r9], -r4
 *
 * ══ §111/197 F_LayerTileGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bfba4  size 152  38 条（0x1bfba4..0x1bfc3c）
 * @func 0x1bfba4 0x1bfc3c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x60×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bfba4 cmp r3, #1
 *   @0x1bfba8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bfbac mov r3, #0
 *   @0x1bfbb0 mov r4, r3
 *   @0x1bfbb4 mov r5, r0
 *   @0x1bfbb8 movt r3, #0xbff0
 *   @0x1bfbbc str r4, [r0, #0xc]
 *   @0x1bfbc0 str r3, [r0, #0x4]
 *   @0x1bfbc4 str r4, [r0]
 *   @0x1bfbc8 ldr r6, [sp, #0x18]
 *   @0x1bfbcc beq 0x1bfbe4 <_Z19F_LayerTileGetAlphaR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bfbd0 ldr r0, [pc, #0x60]
 *   @0x1bfbd4 mov r1, r4
 *   @0x1bfbd8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bfbdc add r0, pc, r0
 *   @0x1bfbe0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bfbe4 str r4, [r0]
 *   @0x1bfbe8 str r4, [r0, #0x4]
 *   @0x1bfbec bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bfbf0 mov r1, r4
 *   @0x1bfbf4 mov r7, r0
 *   @0x1bfbf8 mov r0, r6
 *   @0x1bfbfc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bfc00 mov r2, r4
 *   @0x1bfc04 mov r1, r0
 *   @0x1bfc08 mov r0, r7
 *   @0x1bfc0c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bfc10 cmp r0, #0
 *   @0x1bfc14 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bfc18 ldr r3, [r0]
 *   @0x1bfc1c cmp r3, #7
 *   @0x1bfc20 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bfc24 vldr s15, [r0, #68]
 *   @0x1bfc28 vcvt.f64.f32 d6, s15
 *   @0x1bfc2c vmov r2, r3, d6
 *   @0x1bfc30 stm r5, {r2, r3}
 *   @0x1bfc34 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bfc38 andseq pc, r8, r8, lsr r9
 *
 * ══ §112/197 F_LayerTileGetX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bfc3c  size 152  38 条（0x1bfc3c..0x1bfcd4）
 * @func 0x1bfc3c 0x1bfcd4  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x60×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bfc3c cmp r3, #1
 *   @0x1bfc40 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bfc44 mov r3, #0
 *   @0x1bfc48 mov r4, r3
 *   @0x1bfc4c mov r5, r0
 *   @0x1bfc50 movt r3, #0xbff0
 *   @0x1bfc54 str r4, [r0, #0xc]
 *   @0x1bfc58 str r3, [r0, #0x4]
 *   @0x1bfc5c str r4, [r0]
 *   @0x1bfc60 ldr r6, [sp, #0x18]
 *   @0x1bfc64 beq 0x1bfc7c <_Z15F_LayerTileGetXR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bfc68 ldr r0, [pc, #0x60]
 *   @0x1bfc6c mov r1, r4
 *   @0x1bfc70 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bfc74 add r0, pc, r0
 *   @0x1bfc78 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bfc7c str r4, [r0]
 *   @0x1bfc80 str r4, [r0, #0x4]
 *   @0x1bfc84 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bfc88 mov r1, r4
 *   @0x1bfc8c mov r7, r0
 *   @0x1bfc90 mov r0, r6
 *   @0x1bfc94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bfc98 mov r2, r4
 *   @0x1bfc9c mov r1, r0
 *   @0x1bfca0 mov r0, r7
 *   @0x1bfca4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bfca8 cmp r0, #0
 *   @0x1bfcac popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bfcb0 ldr r3, [r0]
 *   @0x1bfcb4 cmp r3, #7
 *   @0x1bfcb8 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bfcbc vldr s15, [r0, #36]
 *   @0x1bfcc0 vcvt.f64.f32 d6, s15
 *   @0x1bfcc4 vmov r2, r3, d6
 *   @0x1bfcc8 stm r5, {r2, r3}
 *   @0x1bfccc pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bfcd0 ldrsbeq pc, [r8], -r8
 *
 * ══ §113/197 F_LayerTileGetY(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bfcd4  size 152  38 条（0x1bfcd4..0x1bfd6c）
 * @func 0x1bfcd4 0x1bfd6c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x60×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bfcd4 cmp r3, #1
 *   @0x1bfcd8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bfcdc mov r3, #0
 *   @0x1bfce0 mov r4, r3
 *   @0x1bfce4 mov r5, r0
 *   @0x1bfce8 movt r3, #0xbff0
 *   @0x1bfcec str r4, [r0, #0xc]
 *   @0x1bfcf0 str r3, [r0, #0x4]
 *   @0x1bfcf4 str r4, [r0]
 *   @0x1bfcf8 ldr r6, [sp, #0x18]
 *   @0x1bfcfc beq 0x1bfd14 <_Z15F_LayerTileGetYR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bfd00 ldr r0, [pc, #0x60]
 *   @0x1bfd04 mov r1, r4
 *   @0x1bfd08 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bfd0c add r0, pc, r0
 *   @0x1bfd10 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bfd14 str r4, [r0]
 *   @0x1bfd18 str r4, [r0, #0x4]
 *   @0x1bfd1c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bfd20 mov r1, r4
 *   @0x1bfd24 mov r7, r0
 *   @0x1bfd28 mov r0, r6
 *   @0x1bfd2c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bfd30 mov r2, r4
 *   @0x1bfd34 mov r1, r0
 *   @0x1bfd38 mov r0, r7
 *   @0x1bfd3c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bfd40 cmp r0, #0
 *   @0x1bfd44 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bfd48 ldr r3, [r0]
 *   @0x1bfd4c cmp r3, #7
 *   @0x1bfd50 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bfd54 vldr s15, [r0, #40]
 *   @0x1bfd58 vcvt.f64.f32 d6, s15
 *   @0x1bfd5c vmov r2, r3, d6
 *   @0x1bfd60 stm r5, {r2, r3}
 *   @0x1bfd64 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bfd68 andseq pc, r8, r4, ror r8
 *
 * ══ §114/197 GetTouchAction(int, int)  0x1d755c  size 152  38 条（0x1d755c..0x1d75f4）
 * @func 0x1d755c 0x1d75f4  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x8c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d755c ldr r3, [pc, #0x8c]
 *   @0x1d7560 cmn r1, #1
 *   @0x1d7564 mov r12, r0
 *   @0x1d7568 ldr r3, [pc, r3]
 *   @0x1d756c ldr r2, [r3]
 *   @0x1d7570 beq 0x1d75b8 <_Z14GetTouchActionii+0x5c>
 *   @0x1d7574 cmp r2, #0
 *   @0x1d7578 beq 0x1d75a0 <_Z14GetTouchActionii+0x44>
 *   @0x1d757c ldr r0, [r2, #0x8]
 *   @0x1d7580 cmp r0, #0
 *   @0x1d7584 bxeq lr
 *   @0x1d7588 ldr r3, [r0]
 *   @0x1d758c cmp r3, r12
 *   @0x1d7590 beq 0x1d75a8 <_Z14GetTouchActionii+0x4c>
 *   @0x1d7594 ldr r2, [r2]
 *   @0x1d7598 cmp r2, #0
 *   @0x1d759c bne 0x1d757c <_Z14GetTouchActionii+0x20>
 *   @0x1d75a0 mov r0, r2
 *   @0x1d75a4 bx lr
 *   @0x1d75a8 ldr r3, [r0, #0x4]
 *   @0x1d75ac cmp r3, r1
 *   @0x1d75b0 bne 0x1d7594 <_Z14GetTouchActionii+0x38>
 *   @0x1d75b4 bx lr
 *   @0x1d75b8 cmp r2, #0
 *   @0x1d75bc beq 0x1d75a0 <_Z14GetTouchActionii+0x44>
 *   @0x1d75c0 ldr r0, [r2, #0x8]
 *   @0x1d75c4 cmp r0, #0
 *   @0x1d75c8 beq 0x1d75ec <_Z14GetTouchActionii+0x90>
 *   @0x1d75cc ldr r3, [r0]
 *   @0x1d75d0 cmp r3, r12
 *   @0x1d75d4 beq 0x1d75e8 <_Z14GetTouchActionii+0x8c>
 *   @0x1d75d8 ldr r2, [r2]
 *   @0x1d75dc cmp r2, #0
 *   @0x1d75e0 bne 0x1d75c0 <_Z14GetTouchActionii+0x64>
 *   @0x1d75e4 b 0x1d75a0 <_Z14GetTouchActionii+0x44>
 *   @0x1d75e8 bx lr
 *   @0x1d75ec bx lr
 *   @0x1d75f0 mlaeq r1, r12, r6, r9
 *
 * ══ §115/197 CSprite::LoadFromJPEGData(void*, int, int, bool, bool, bool, int, int, bool)  0x1e7140  size 152  38 条（0x1e7140..0x1e71d8）
 * @func 0x1e7140 0x1e71d8  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ReadJPEGFile(void*, int, int*, int*, bool) / CSprite::LoadFromData(void*, int, int, int, bool, bool, bool, int, int, bool) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x48×1 / 0x4c×1 / 0x50×1 / 0x5c×1 / 0x54×1 / 0x20×1 / 0x24×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e7140 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1e7144 sub sp, sp, #40
 *   @0x1e7148 mov r12, #0
 *   @0x1e714c mov r10, r0
 *   @0x1e7150 mov r9, r3
 *   @0x1e7154 mov r0, r1
 *   @0x1e7158 str r12, [sp]
 *   @0x1e715c mov r1, r2
 *   @0x1e7160 add r3, sp, #36
 *   @0x1e7164 add r2, sp, #32
 *   @0x1e7168 ldrb r8, [sp, #0x48]
 *   @0x1e716c ldrb r7, [sp, #0x4c]
 *   @0x1e7170 ldrb r6, [sp, #0x50]
 *   @0x1e7174 ldrb r5, [sp, #0x5c]
 *   @0x1e7178 bl 0x18a728 <_Z12ReadJPEGFilePviPiS0_b>
 *   @0x1e717c subs r4, r0, #0
 *   @0x1e7180 moveq r0, r4
 *   @0x1e7184 beq 0x1e71d0 <_ZN7CSprite16LoadFromJPEGDataEPviibbbiib+0x90>
 *   @0x1e7188 ldr r12, [sp, #0x54]
 *   @0x1e718c mov r1, r4
 *   @0x1e7190 ldr r2, [sp, #0x20]
 *   @0x1e7194 mov r0, r10
 *   @0x1e7198 ldr r3, [sp, #0x24]
 *   @0x1e719c str r12, [sp, #0x10]
 *   @0x1e71a0 ldr r12, [sp, #0x58]
 *   @0x1e71a4 str r5, [sp, #0x18]
 *   @0x1e71a8 str r9, [sp]
 *   @0x1e71ac str r12, [sp, #0x14]
 *   @0x1e71b0 str r8, [sp, #0x4]
 *   @0x1e71b4 str r7, [sp, #0x8]
 *   @0x1e71b8 str r6, [sp, #0xc]
 *   @0x1e71bc bl 0x1e6fd4 <_ZN7CSprite12LoadFromDataEPviiibbbiib>
 *   @0x1e71c0 mov r5, r0
 *   @0x1e71c4 mov r0, r4
 *   @0x1e71c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e71cc mov r0, r5
 *   @0x1e71d0 add sp, sp, #40
 *   @0x1e71d4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §116/197 CSprite::LoadFromGIFData(void*, int, int, bool, bool, bool, int, int, bool)  0x1e71d8  size 152  38 条（0x1e71d8..0x1e7270）
 * @func 0x1e71d8 0x1e7270  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ReadGIFFile(void*, int, int*, int*, bool) / CSprite::LoadFromData(void*, int, int, int, bool, bool, bool, int, int, bool) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x48×1 / 0x4c×1 / 0x50×1 / 0x5c×1 / 0x54×1 / 0x20×1 / 0x24×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e71d8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1e71dc sub sp, sp, #40
 *   @0x1e71e0 mov r12, #0
 *   @0x1e71e4 mov r10, r0
 *   @0x1e71e8 mov r9, r3
 *   @0x1e71ec mov r0, r1
 *   @0x1e71f0 str r12, [sp]
 *   @0x1e71f4 mov r1, r2
 *   @0x1e71f8 add r3, sp, #36
 *   @0x1e71fc add r2, sp, #32
 *   @0x1e7200 ldrb r8, [sp, #0x48]
 *   @0x1e7204 ldrb r7, [sp, #0x4c]
 *   @0x1e7208 ldrb r6, [sp, #0x50]
 *   @0x1e720c ldrb r5, [sp, #0x5c]
 *   @0x1e7210 bl 0x18a918 <_Z11ReadGIFFilePviPiS0_b>
 *   @0x1e7214 subs r4, r0, #0
 *   @0x1e7218 moveq r0, r4
 *   @0x1e721c beq 0x1e7268 <_ZN7CSprite15LoadFromGIFDataEPviibbbiib+0x90>
 *   @0x1e7220 ldr r12, [sp, #0x54]
 *   @0x1e7224 mov r1, r4
 *   @0x1e7228 ldr r2, [sp, #0x20]
 *   @0x1e722c mov r0, r10
 *   @0x1e7230 ldr r3, [sp, #0x24]
 *   @0x1e7234 str r12, [sp, #0x10]
 *   @0x1e7238 ldr r12, [sp, #0x58]
 *   @0x1e723c str r5, [sp, #0x18]
 *   @0x1e7240 str r9, [sp]
 *   @0x1e7244 str r12, [sp, #0x14]
 *   @0x1e7248 str r8, [sp, #0x4]
 *   @0x1e724c str r7, [sp, #0x8]
 *   @0x1e7250 str r6, [sp, #0xc]
 *   @0x1e7254 bl 0x1e6fd4 <_ZN7CSprite12LoadFromDataEPviiibbbiib>
 *   @0x1e7258 mov r5, r0
 *   @0x1e725c mov r0, r4
 *   @0x1e7260 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e7264 mov r0, r5
 *   @0x1e7268 add sp, sp, #40
 *   @0x1e726c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §117/197 FINALIZE_Variable_Main()  0x1f4d10  size 152  38 条（0x1f4d10..0x1f4da8）
 * @func 0x1f4d10 0x1f4da8  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / 0xb65b0
 * 字段偏移 top8: 0x4×3 / 0x7c×1 / 0x54×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f4d10 push {r4, r5, r6, lr}
 *   @0x1f4d14 mov r4, #0
 *   @0x1f4d18 ldr r5, [pc, #0x7c]
 *   @0x1f4d1c mov r6, r4
 *   @0x1f4d20 ldr r5, [pc, r5]
 *   @0x1f4d24 ldr r0, [r5, r4]
 *   @0x1f4d28 cmp r0, #0
 *   @0x1f4d2c beq 0x1f4d38 <_Z22FINALIZE_Variable_Mainv+0x28>
 *   @0x1f4d30 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f4d34 str r6, [r5, r4]
 *   @0x1f4d38 add r4, r4, #16
 *   @0x1f4d3c cmp r4, #8000
 *   @0x1f4d40 bne 0x1f4d24 <_Z22FINALIZE_Variable_Mainv+0x14>
 *   @0x1f4d44 ldr r6, [pc, #0x54]
 *   @0x1f4d48 mov r0, r5
 *   @0x1f4d4c mov r2, r4
 *   @0x1f4d50 mov r1, #0
 *   @0x1f4d54 bl 0xb65b0 <memset@plt>
 *   @0x1f4d58 ldr r6, [pc, r6]
 *   @0x1f4d5c ldr r3, [pc, #0x40]
 *   @0x1f4d60 mov r5, #0
 *   @0x1f4d64 ldr r4, [r6, #0x4]
 *   @0x1f4d68 ldr r3, [pc, r3]
 *   @0x1f4d6c cmp r4, r5
 *   @0x1f4d70 mov r0, r4
 *   @0x1f4d74 str r5, [r3]
 *   @0x1f4d78 beq 0x1f4d90 <_Z22FINALIZE_Variable_Mainv+0x80>
 *   @0x1f4d7c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f4d80 str r5, [r6, #0x4]
 *   @0x1f4d84 mov r3, #0
 *   @0x1f4d88 str r3, [r6]
 *   @0x1f4d8c pop {r4, r5, r6, pc}
 *   @0x1f4d90 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f4d94 str r4, [r6, #0x4]
 *   @0x1f4d98 b 0x1f4d84 <_Z22FINALIZE_Variable_Mainv+0x74>
 *   @0x1f4d9c andseq r8, pc, r8, lsl pc
 *   @0x1f4da0 ldrsbeq r12, [pc], -r0
 *   @0x1f4da4 andseq r8, pc, r12, asr #29
 *
 * ══ §118/197 CVariableList::Dump(tagIConsole&)  0x1f5ac8  size 152  38 条（0x1f5ac8..0x1f5b60）
 * @func 0x1f5ac8 0x1f5b60  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: OutputVariable(tagIConsole*, RVariable*)
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f5ac8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1f5acc adds r4, r0, #4
 *   @0x1f5ad0 mov r7, r1
 *   @0x1f5ad4 addne r4, r0, #20
 *   @0x1f5ad8 beq 0x1f5b3c <_ZN13CVariableList4DumpER11tagIConsole+0x74>
 *   @0x1f5adc cmp r4, r0
 *   @0x1f5ae0 add r6, r0, #4
 *   @0x1f5ae4 beq 0x1f5af0 <_ZN13CVariableList4DumpER11tagIConsole+0x28>
 *   @0x1f5ae8 cmp r4, r6
 *   @0x1f5aec bne 0x1f5b48 <_ZN13CVariableList4DumpER11tagIConsole+0x80>
 *   @0x1f5af0 mov r6, r4
 *   @0x1f5af4 mov r5, #0
 *   @0x1f5af8 cmp r5, #0
 *   @0x1f5afc beq 0x1f5b38 <_ZN13CVariableList4DumpER11tagIConsole+0x70>
 *   @0x1f5b00 mov r1, r5
 *   @0x1f5b04 mov r0, r7
 *   @0x1f5b08 bl 0x1f5a00 <_Z14OutputVariableP11tagIConsoleP9RVariable>
 *   @0x1f5b0c ldr r5, [r5]
 *   @0x1f5b10 cmp r5, #0
 *   @0x1f5b14 add r3, r6, #4
 *   @0x1f5b18 bne 0x1f5af8 <_ZN13CVariableList4DumpER11tagIConsole+0x30>
 *   @0x1f5b1c cmp r4, r6
 *   @0x1f5b20 beq 0x1f5b5c <_ZN13CVariableList4DumpER11tagIConsole+0x94>
 *   @0x1f5b24 cmp r3, r4
 *   @0x1f5b28 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1f5b2c ldr r5, [r6, #0x4]
 *   @0x1f5b30 mov r6, r3
 *   @0x1f5b34 b 0x1f5b10 <_ZN13CVariableList4DumpER11tagIConsole+0x48>
 *   @0x1f5b38 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1f5b3c mov r6, r4
 *   @0x1f5b40 mov r5, r4
 *   @0x1f5b44 b 0x1f5af8 <_ZN13CVariableList4DumpER11tagIConsole+0x30>
 *   @0x1f5b48 ldr r5, [r0, #0x4]
 *   @0x1f5b4c cmp r5, #0
 *   @0x1f5b50 bne 0x1f5af8 <_ZN13CVariableList4DumpER11tagIConsole+0x30>
 *   @0x1f5b54 mov r0, r6
 *   @0x1f5b58 b 0x1f5adc <_ZN13CVariableList4DumpER11tagIConsole+0x14>
 *   @0x1f5b5c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §119/197 SV_PhysicsLinearVelocityX(CInstance*, int, RValue*)  0x1fe7ac  size 152  38 条（0x1fe7ac..0x1fe844）
 * @func 0x1fe7ac 0x1fe844  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckPhysicsError(CInstance*, bool, bool) / CPhysicsObject::SetLinearVelocity(float, float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x6c×1 / 0x84×1 / 0xb4×1 / 0xc×1 / 0x54×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fe7ac mov r1, #1
 *   @0x1fe7b0 push {r4, r6, r7, r8, r9, lr}
 *   @0x1fe7b4 mov r9, r2
 *   @0x1fe7b8 mov r2, r1
 *   @0x1fe7bc mov r4, r0
 *   @0x1fe7c0 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1fe7c4 subs r6, r0, #0
 *   @0x1fe7c8 beq 0x1fe82c <_Z25SV_PhysicsLinearVelocityXP9CInstanceiP6RValue+0x80>
 *   @0x1fe7cc ldr r3, [pc, #0x6c]
 *   @0x1fe7d0 ldr r7, [r4, #0x84]
 *   @0x1fe7d4 ldr r3, [pc, r3]
 *   @0x1fe7d8 ldr r3, [r3]
 *   @0x1fe7dc ldr r8, [r3, #0xb4]
 *   @0x1fe7e0 cmp r7, #0
 *   @0x1fe7e4 cmpne r8, #0
 *   @0x1fe7e8 moveq r6, #0
 *   @0x1fe7ec movne r6, #1
 *   @0x1fe7f0 beq 0x1fe82c <_Z25SV_PhysicsLinearVelocityXP9CInstanceiP6RValue+0x80>
 *   @0x1fe7f4 ldr r3, [r9, #0xc]
 *   @0x1fe7f8 bic r3, r3, #-16777216
 *   @0x1fe7fc cmp r3, #0
 *   @0x1fe800 bne 0x1fe834 <_Z25SV_PhysicsLinearVelocityXP9CInstanceiP6RValue+0x88>
 *   @0x1fe804 ldm r9, {r0, r1}
 *   @0x1fe808 vmov d6, r0, r1
 *   @0x1fe80c vldr s15, [r8, #96]
 *   @0x1fe810 ldr r3, [r7]
 *   @0x1fe814 mov r0, r7
 *   @0x1fe818 vcvt.f32.f64 s14, d6
 *   @0x1fe81c ldr r2, [r3, #0x54]
 *   @0x1fe820 vmul.f32 s15, s14, s15
 *   @0x1fe824 vmov r1, s15
 *   @0x1fe828 bl 0x236e9c <_ZN14CPhysicsObject17SetLinearVelocityEff>
 *   @0x1fe82c mov r0, r6
 *   @0x1fe830 pop {r4, r6, r7, r8, r9, pc}
 *   @0x1fe834 mov r0, r9
 *   @0x1fe838 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fe83c b 0x1fe808 <_Z25SV_PhysicsLinearVelocityXP9CInstanceiP6RValue+0x5c>
 *   @0x1fe840 andseq pc, lr, r4, asr r1
 *
 * ══ §120/197 SV_PhysicsLinearVelocityY(CInstance*, int, RValue*)  0x1fe844  size 152  38 条（0x1fe844..0x1fe8dc）
 * @func 0x1fe844 0x1fe8dc  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckPhysicsError(CInstance*, bool, bool) / CPhysicsObject::SetLinearVelocity(float, float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x6c×1 / 0x84×1 / 0xb4×1 / 0xc×1 / 0x50×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fe844 mov r1, #1
 *   @0x1fe848 push {r4, r6, r7, r8, r9, lr}
 *   @0x1fe84c mov r9, r2
 *   @0x1fe850 mov r2, r1
 *   @0x1fe854 mov r4, r0
 *   @0x1fe858 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1fe85c subs r6, r0, #0
 *   @0x1fe860 beq 0x1fe8c4 <_Z25SV_PhysicsLinearVelocityYP9CInstanceiP6RValue+0x80>
 *   @0x1fe864 ldr r3, [pc, #0x6c]
 *   @0x1fe868 ldr r7, [r4, #0x84]
 *   @0x1fe86c ldr r3, [pc, r3]
 *   @0x1fe870 ldr r3, [r3]
 *   @0x1fe874 ldr r8, [r3, #0xb4]
 *   @0x1fe878 cmp r7, #0
 *   @0x1fe87c cmpne r8, #0
 *   @0x1fe880 moveq r6, #0
 *   @0x1fe884 movne r6, #1
 *   @0x1fe888 beq 0x1fe8c4 <_Z25SV_PhysicsLinearVelocityYP9CInstanceiP6RValue+0x80>
 *   @0x1fe88c ldr r3, [r9, #0xc]
 *   @0x1fe890 bic r3, r3, #-16777216
 *   @0x1fe894 cmp r3, #0
 *   @0x1fe898 bne 0x1fe8cc <_Z25SV_PhysicsLinearVelocityYP9CInstanceiP6RValue+0x88>
 *   @0x1fe89c ldm r9, {r0, r1}
 *   @0x1fe8a0 vmov d6, r0, r1
 *   @0x1fe8a4 vldr s15, [r8, #96]
 *   @0x1fe8a8 ldr r3, [r7]
 *   @0x1fe8ac mov r0, r7
 *   @0x1fe8b0 vcvt.f32.f64 s14, d6
 *   @0x1fe8b4 ldr r1, [r3, #0x50]
 *   @0x1fe8b8 vmul.f32 s15, s14, s15
 *   @0x1fe8bc vmov r2, s15
 *   @0x1fe8c0 bl 0x236e9c <_ZN14CPhysicsObject17SetLinearVelocityEff>
 *   @0x1fe8c4 mov r0, r6
 *   @0x1fe8c8 pop {r4, r6, r7, r8, r9, pc}
 *   @0x1fe8cc mov r0, r9
 *   @0x1fe8d0 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fe8d4 b 0x1fe8a0 <_Z25SV_PhysicsLinearVelocityYP9CInstanceiP6RValue+0x5c>
 *   @0x1fe8d8 ldrheq pc, [lr], -r12
 *
 * ══ §121/197 CStream::WriteCompressedStream(CStream*)  0x2021fc  size 152  38 条（0x2021fc..0x202294）
 * @func 0x2021fc 0x202294  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::SetPosition(int)×2 / CStream::GetPosition() / operator new(unsigned int) / CStream::CStream(int) / ZCompressStream(CStream&, CStream&, int) / CStream::GetSize() / CStream::WriteInteger(int) / CStream::CopyFrom(CStream*, long long)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2021fc push {r4, r5, r6, r7, r8, lr}
 *   @0x202200 mov r6, r0
 *   @0x202204 mov r0, r1
 *   @0x202208 mov r5, r1
 *   @0x20220c bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x202210 mov r1, #0
 *   @0x202214 mov r8, r0
 *   @0x202218 mov r0, r5
 *   @0x20221c bl 0x201148 <_ZN7CStream11SetPositionEi>
 *   @0x202220 mov r0, #32
 *   @0x202224 bl 0x27c524 <_Znwj>
 *   @0x202228 mov r1, #0
 *   @0x20222c mov r4, r0
 *   @0x202230 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x202234 mvn r2, #0
 *   @0x202238 mov r1, r4
 *   @0x20223c mov r0, r5
 *   @0x202240 bl 0x20208c <_Z15ZCompressStreamR7CStreamS0_i>
 *   @0x202244 mov r0, r4
 *   @0x202248 mov r1, #0
 *   @0x20224c bl 0x201148 <_ZN7CStream11SetPositionEi>
 *   @0x202250 mov r0, r4
 *   @0x202254 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x202258 mov r7, r0
 *   @0x20225c mov r0, r6
 *   @0x202260 mov r1, r7
 *   @0x202264 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x202268 mov r2, r7
 *   @0x20226c asr r3, r7, #31
 *   @0x202270 mov r0, r6
 *   @0x202274 mov r1, r4
 *   @0x202278 bl 0x20170c <_ZN7CStream8CopyFromEPS_x>
 *   @0x20227c mov r0, r4
 *   @0x202280 bl 0x20133c <_ZN7CStream4FreeEv>
 *   @0x202284 mov r0, r5
 *   @0x202288 mov r1, r8
 *   @0x20228c pop {r4, r5, r6, r7, r8, lr}
 *   @0x202290 b 0x201148 <_ZN7CStream11SetPositionEi>
 *
 * ══ §122/197 FUNC_GridSort(void const*, void const*)  0x202a60  size 152  38 条（0x202a60..0x202af8）
 * @func 0x202a60 0x202af8  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x202a68→0x755268, 0x202a70→0x3f5258, 0x202ac0→0x3f5270, 0x202ad0→0x75526c
 * 调用序列: YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0x78×2 / 0x74×1 / 0x4×1 / 0x28×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202a60 push {r3, r4, r5, lr}
 *   @0x202a64 ldr r4, [pc, #0x78]
 *   @0x202a68 ldr r2, [pc, #0x78]
 *   @0x202a6c add r4, pc, r4
 *   @0x202a70 ldr r3, [pc, #0x74]
 *   @0x202a74 ldr r5, [r1]
 *   @0x202a78 ldr r12, [r4, r2]
 *   @0x202a7c ldr r2, [r4, r3]
 *   @0x202a80 ldr r0, [r0]
 *   @0x202a84 ldr r12, [r12]
 *   @0x202a88 ldr r2, [r2]
 *   @0x202a8c ldr r1, [r12, #0x4]
 *   @0x202a90 ldr r3, [r12]
 *   @0x202a94 mla r0, r0, r1, r2
 *   @0x202a98 mla r1, r5, r1, r2
 *   @0x202a9c adds r0, r3, r0, lsl #4
 *   @0x202aa0 moveq r2, #0
 *   @0x202aa4 movne r2, #1
 *   @0x202aa8 adds r1, r3, r1, lsl #4
 *   @0x202aac moveq r2, #0
 *   @0x202ab0 andne r2, r2, #1
 *   @0x202ab4 cmp r2, #0
 *   @0x202ab8 moveq r0, r2
 *   @0x202abc beq 0x202ad0 <_Z13FUNC_GridSortPKvS0_+0x70>
 *   @0x202ac0 ldr r3, [pc, #0x28]
 *   @0x202ac4 ldr r3, [r4, r3]
 *   @0x202ac8 ldrd r2, r3, [r3]
 *   @0x202acc bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x202ad0 ldr r3, [pc, #0x1c]
 *   @0x202ad4 ldr r3, [r4, r3]
 *   @0x202ad8 ldr r3, [r3]
 *   @0x202adc mul r0, r3, r0
 *   @0x202ae0 pop {r3, r4, r5, pc}
 *   @0x202ae4 andseq pc, lr, r4, ror #3
 *   @0x202ae8 .word 0xfffff738
 *   @0x202aec .word 0xfffff73c
 *   @0x202af0 .word 0xfffff734
 *   @0x202af4 .word 0xfffff740
 *
 * ══ §123/197 CDS_Grid::Cell_Operation(int, int, int, int, RValue*)  0x207d1c  size 152  38 条（0x207d1c..0x207db4）
 * @func 0x207d1c 0x207db4  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Grid::Cell_Operation(int, int, int, int, RValue*)+0x58×2
 * 字段偏移 top8: 0x8×2 / 0x4×1 / 0x20×1 / 0x24×1 / 0x2c×1 / 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x207d1c push {r4, r5, r6, lr}
 *   @0x207d20 cmp r3, #0
 *   @0x207d24 sub sp, sp, #16
 *   @0x207d28 ldr r4, [r0, #0x4]
 *   @0x207d2c ldr r12, [sp, #0x20]
 *   @0x207d30 ldr r6, [sp, #0x24]
 *   @0x207d34 blt 0x207d74 <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue+0x58>
 *   @0x207d38 cmp r3, r4
 *   @0x207d3c bge 0x207d74 <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue+0x58>
 *   @0x207d40 cmp r12, #0
 *   @0x207d44 blt 0x207d74 <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue+0x58>
 *   @0x207d48 ldr r5, [r0, #0x8]
 *   @0x207d4c cmp r12, r5
 *   @0x207d50 bge 0x207d78 <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue+0x5c>
 *   @0x207d54 mla r12, r12, r4, r3
 *   @0x207d58 ldr r1, [r0]
 *   @0x207d5c mov r0, r2
 *   @0x207d60 mov r2, r6
 *   @0x207d64 add r1, r1, r12, lsl #4
 *   @0x207d68 add sp, sp, #16
 *   @0x207d6c pop {r4, r5, r6, lr}
 *   @0x207d70 b 0x207a0c <_Z11DoOperationiP6RValueS0_>
 *   @0x207d74 ldr r5, [r0, #0x8]
 *   @0x207d78 ldr r0, [pc, #0x2c]
 *   @0x207d7c mov r2, r1
 *   @0x207d80 ldr r1, [pc, #0x28]
 *   @0x207d84 ldr r0, [pc, r0]
 *   @0x207d88 add r1, pc, r1
 *   @0x207d8c ldr r0, [r0]
 *   @0x207d90 ldr lr, [r0]
 *   @0x207d94 str r12, [sp]
 *   @0x207d98 stmib sp, {r4, r5}
 *   @0x207d9c ldr r12, [lr, #0xc]
 *   @0x207da0 blx r12
 *   @0x207da4 add sp, sp, #16
 *   @0x207da8 pop {r4, r5, r6, pc}
 *   @0x207dac ldrheq r5, [lr], -r12
 *   @0x207db0 andseq r0, r3, r4, lsl #18
 *
 * ══ §124/197 Audio_Exists(int)  0x217260  size 152  38 条（0x217260..0x2172f8）
 * @func 0x217260 0x2172f8  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_Exists(int)+0x6c / Audio_Exists(int)+0x64 / Audio_GetNoiseFromID(int) / Audio_NoiseIsPlaying(CNoise*)
 * 字段偏移 top8: 0x84×1 / 0x6c×1 / 0x54×1 / 0x20×1 / 0x24×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217260 ldr r3, [pc, #0x84]
 *   @0x217264 push {r4, lr}
 *   @0x217268 ldr r3, [pc, r3]
 *   @0x21726c mov r4, r0
 *   @0x217270 ldrb r3, [r3]
 *   @0x217274 cmp r3, #0
 *   @0x217278 bne 0x2172c4 <_Z12Audio_Existsi+0x64>
 *   @0x21727c ldr r3, [pc, #0x6c]
 *   @0x217280 ldr r3, [pc, r3]
 *   @0x217284 ldr r3, [r3]
 *   @0x217288 cmp r3, r0
 *   @0x21728c ble 0x2172cc <_Z12Audio_Existsi+0x6c>
 *   @0x217290 cmp r4, #0
 *   @0x217294 blt 0x2172c4 <_Z12Audio_Existsi+0x64>
 *   @0x217298 ldr r3, [pc, #0x54]
 *   @0x21729c add r3, pc, r3
 *   @0x2172a0 ldr r2, [r3, #0x20]
 *   @0x2172a4 cmp r4, r2
 *   @0x2172a8 bge 0x2172c4 <_Z12Audio_Existsi+0x64>
 *   @0x2172ac ldr r3, [r3, #0x24]
 *   @0x2172b0 ldr r0, [r3, r4, lsl #2]
 *   @0x2172b4 cmp r0, #0
 *   @0x2172b8 beq 0x2172e8 <_Z12Audio_Existsi+0x88>
 *   @0x2172bc mov r0, #1
 *   @0x2172c0 pop {r4, pc}
 *   @0x2172c4 mov r0, #0
 *   @0x2172c8 pop {r4, pc}
 *   @0x2172cc bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x2172d0 bl 0x2164bc <_Z20Audio_NoiseIsPlayingP6CNoise>
 *   @0x2172d4 cmp r0, #0
 *   @0x2172d8 bne 0x2172bc <_Z12Audio_Existsi+0x5c>
 *   @0x2172dc cmp r4, #0
 *   @0x2172e0 bge 0x217298 <_Z12Audio_Existsi+0x38>
 *   @0x2172e4 b 0x2172c4 <_Z12Audio_Existsi+0x64>
 *   @0x2172e8 pop {r4, pc}
 *   @0x2172ec andseq r7, sp, r4, ror #27
 *   @0x2172f0 andseq r10, sp, r4, ror #2
 *   @0x2172f4 ldrsheq sp, [r3], #-248
 *
 * ══ §125/197 Audio_StopAll(bool)  0x21a3bc  size 152  38 条（0x21a3bc..0x21a454）
 * @func 0x21a3bc 0x21a454  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_StopSoundNoise(CNoise*, bool)
 * 字段偏移 top8: 0x38×2 / 0x7c×1 / 0x64×1 / 0x54×1 / 0x44×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21a3bc ldr r3, [pc, #0x7c]
 *   @0x21a3c0 push {r4, r5, r6, r7, r8, lr}
 *   @0x21a3c4 ldr r3, [pc, r3]
 *   @0x21a3c8 mov r6, r0
 *   @0x21a3cc ldrb r4, [r3]
 *   @0x21a3d0 cmp r4, #0
 *   @0x21a3d4 popne {r4, r5, r6, r7, r8, pc}
 *   @0x21a3d8 ldr r3, [pc, #0x64]
 *   @0x21a3dc ldr r3, [pc, r3]
 *   @0x21a3e0 ldrb r3, [r3]
 *   @0x21a3e4 cmp r3, #0
 *   @0x21a3e8 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x21a3ec ldr r3, [pc, #0x54]
 *   @0x21a3f0 add r3, pc, r3
 *   @0x21a3f4 ldr r5, [r3, #0x38]
 *   @0x21a3f8 cmp r5, #0
 *   @0x21a3fc pople {r4, r5, r6, r7, r8, pc}
 *   @0x21a400 ldr r8, [pc, #0x44]
 *   @0x21a404 mov r3, r5
 *   @0x21a408 ldr r7, [pc, #0x40]
 *   @0x21a40c add r8, pc, r8
 *   @0x21a410 add r7, pc, r7
 *   @0x21a414 cmp r3, r4
 *   @0x21a418 mov r0, #0
 *   @0x21a41c mov r1, r6
 *   @0x21a420 ldrgt r3, [r8, #0x3c]
 *   @0x21a424 ldrgt r0, [r3, r4, lsl #2]
 *   @0x21a428 add r4, r4, #1
 *   @0x21a42c bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb>
 *   @0x21a430 cmp r4, r5
 *   @0x21a434 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x21a438 ldr r3, [r7, #0x38]
 *   @0x21a43c b 0x21a414 <_Z13Audio_StopAllb+0x58>
 *   @0x21a440 andseq r4, sp, r8, lsl #25
 *   @0x21a444 andseq r4, sp, r4, asr r9
 *   @0x21a448 subseq r10, r3, r4, lsr #29
 *   @0x21a44c subseq r10, r3, r8, lsl #29
 *   @0x21a450 subseq r10, r3, r4, lsl #29
 *
 * ══ §126/197 Sound_WAVs(unsigned char*, unsigned int, unsigned char*)  0x21f9d4  size 152  38 条（0x21f9d4..0x21fa6c）
 * @func 0x21f9d4 0x21fa6c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sound_WAVs(unsigned char*, unsigned int, unsigned char*)+0x80
 * 字段偏移 top8: 0x78×2 / 0x4×2 / 0xc×1 / 0x60×1 / 0x4c×1 / 0x3c×1 / 0x2×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f9d4 push {r3, r4, r5, lr}
 *   @0x21f9d8 mov r4, r0
 *   @0x21f9dc ldr r3, [pc, #0x78]
 *   @0x21f9e0 ldr r1, [pc, #0x78]
 *   @0x21f9e4 ldr r3, [pc, r3]
 *   @0x21f9e8 add r1, pc, r1
 *   @0x21f9ec ldr r0, [r3]
 *   @0x21f9f0 ldr r2, [r0]
 *   @0x21f9f4 ldr r3, [r2, #0xc]
 *   @0x21f9f8 blx r3
 *   @0x21f9fc ldr r2, [pc, #0x60]
 *   @0x21fa00 add r0, r4, #4
 *   @0x21fa04 add r2, pc, r2
 *   @0x21fa08 ldr r4, [r2]
 *   @0x21fa0c cmp r4, #0
 *   @0x21fa10 ble 0x21fa54 <_Z10Sound_WAVsPhjS_+0x80>
 *   @0x21fa14 ldr r3, [pc, #0x4c]
 *   @0x21fa18 ldr r1, [r2, #0x4]
 *   @0x21fa1c ldr r3, [pc, r3]
 *   @0x21fa20 add r4, r1, r4, lsl #2
 *   @0x21fa24 ldr r5, [r3]
 *   @0x21fa28 ldr r2, [r1], #4
 *   @0x21fa2c cmp r2, #0
 *   @0x21fa30 beq 0x21fa4c <_Z10Sound_WAVsPhjS_+0x78>
 *   @0x21fa34 ldr r3, [r2, #0x3c]
 *   @0x21fa38 ldr r3, [r0, r3, lsl #2]
 *   @0x21fa3c cmp r3, #0
 *   @0x21fa40 add r12, r3, r5
 *   @0x21fa44 moveq r12, r3
 *   @0x21fa48 str r12, [r2, #0x38]
 *   @0x21fa4c cmp r1, r4
 *   @0x21fa50 bne 0x21fa28 <_Z10Sound_WAVsPhjS_+0x54>
 *   @0x21fa54 mov r0, #1
 *   @0x21fa58 pop {r3, r4, r5, pc}
 *   @0x21fa5c andseq sp, r12, r0, lsr sp
 *   @0x21fa60 andseq r4, r3, r8, lsl lr
 *   @0x21fa64 subseq r5, r3, r4, lsr r9
 *   @0x21fa68 andseq sp, r12, r8, lsr #30
 *
 * ══ §127/197 Sound_Delete(int)  0x2200cc  size 152  38 条（0x2200cc..0x220164）
 * @func 0x2200cc 0x220164  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sound_Delete(int)+0x88 / CSound::~CSound() / operator delete(void*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x2×3 / 0x4×2 / 0xc×2 / 0x80×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2200cc push {r3, r4, r5, r6, r7, lr}
 *   @0x2200d0 subs r4, r0, #0
 *   @0x2200d4 blt 0x220154 <_Z12Sound_Deletei+0x88>
 *   @0x2200d8 ldr r5, [pc, #0x80]
 *   @0x2200dc add r5, pc, r5
 *   @0x2200e0 ldr r3, [r5, #0x10]
 *   @0x2200e4 cmp r4, r3
 *   @0x2200e8 bge 0x220154 <_Z12Sound_Deletei+0x88>
 *   @0x2200ec ldr r3, [r5]
 *   @0x2200f0 cmp r4, r3
 *   @0x2200f4 bge 0x220154 <_Z12Sound_Deletei+0x88>
 *   @0x2200f8 ldr r3, [r5, #0x4]
 *   @0x2200fc lsl r7, r4, #2
 *   @0x220100 ldr r6, [r3, r4, lsl #2]
 *   @0x220104 subs r0, r6, #0
 *   @0x220108 beq 0x22015c <_Z12Sound_Deletei+0x90>
 *   @0x22010c bl 0x215384 <_ZN6CSoundD2Ev>
 *   @0x220110 mov r0, r6
 *   @0x220114 bl 0x27d1d0 <_ZdlPv>
 *   @0x220118 ldr r3, [r5, #0x4]
 *   @0x22011c mov r2, #0
 *   @0x220120 str r2, [r3, r4, lsl #2]
 *   @0x220124 ldr r2, [r5, #0xc]
 *   @0x220128 add r3, r2, r7
 *   @0x22012c ldr r0, [r2, r4, lsl #2]
 *   @0x220130 cmp r0, #0
 *   @0x220134 beq 0x220144 <_Z12Sound_Deletei+0x78>
 *   @0x220138 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x22013c ldr r3, [r5, #0xc]
 *   @0x220140 add r3, r3, r7
 *   @0x220144 mov r2, #0
 *   @0x220148 mov r0, #1
 *   @0x22014c str r2, [r3]
 *   @0x220150 pop {r3, r4, r5, r6, r7, pc}
 *   @0x220154 mov r0, #0
 *   @0x220158 pop {r3, r4, r5, r6, r7, pc}
 *   @0x22015c pop {r3, r4, r5, r6, r7, pc}
 *   @0x220160 subseq r5, r3, r12, asr r2
 *
 * ══ §128/197 IniFile::DeleteKey(char const*, char const*)  0x235b94  size 152  38 条（0x235b94..0x235c2c）
 * @func 0x235b94 0x235c2c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::GetSection(char const*) / 0xb6574 / Key::~Key() / operator delete(void*)
 * 字段偏移 top8: 0x4×2 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235b94 push {r4, r5, r6, r7, r8, lr}
 *   @0x235b98 mov r6, r2
 *   @0x235b9c mov r8, r0
 *   @0x235ba0 bl 0x235a90 <_ZN7IniFile10GetSectionEPKc>
 *   @0x235ba4 subs r7, r0, #0
 *   @0x235ba8 beq 0x235c1c <_ZN7IniFile9DeleteKeyEPKcS1_+0x88>
 *   @0x235bac ldr r4, [r7, #0x4]
 *   @0x235bb0 cmp r4, #0
 *   @0x235bb4 beq 0x235c24 <_ZN7IniFile9DeleteKeyEPKcS1_+0x90>
 *   @0x235bb8 mov r5, #0
 *   @0x235bbc b 0x235bd0 <_ZN7IniFile9DeleteKeyEPKcS1_+0x3c>
 *   @0x235bc0 cmp r3, #0
 *   @0x235bc4 mov r5, r4
 *   @0x235bc8 mov r4, r3
 *   @0x235bcc beq 0x235c14 <_ZN7IniFile9DeleteKeyEPKcS1_+0x80>
 *   @0x235bd0 mov r0, r6
 *   @0x235bd4 ldr r1, [r4, #0x4]
 *   @0x235bd8 bl 0xb6574 <strcmp@plt>
 *   @0x235bdc ldr r3, [r4]
 *   @0x235be0 cmp r0, #0
 *   @0x235be4 bne 0x235bc0 <_ZN7IniFile9DeleteKeyEPKcS1_+0x2c>
 *   @0x235be8 cmp r5, #0
 *   @0x235bec mov r0, r4
 *   @0x235bf0 streq r3, [r7, #0x4]
 *   @0x235bf4 mov r7, #1
 *   @0x235bf8 strne r3, [r5]
 *   @0x235bfc strb r7, [r8, #0x18]
 *   @0x235c00 bl 0x2353b0 <_ZN3KeyD2Ev>
 *   @0x235c04 mov r0, r4
 *   @0x235c08 bl 0x27d1d0 <_ZdlPv>
 *   @0x235c0c mov r0, r7
 *   @0x235c10 pop {r4, r5, r6, r7, r8, pc}
 *   @0x235c14 mov r0, r3
 *   @0x235c18 pop {r4, r5, r6, r7, r8, pc}
 *   @0x235c1c mov r0, r7
 *   @0x235c20 pop {r4, r5, r6, r7, r8, pc}
 *   @0x235c24 mov r0, r4
 *   @0x235c28 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §129/197 JS_SplitMatch(char const*, int, char const*)  0x242604  size 152  38 条（0x242604..0x24269c）
 * @func 0x242604 0x24269c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×2 / JS_SplitMatch(char const*, int, char const*)+0x90 / operator new(unsigned int)
 * 字段偏移 top8: 0x1×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x242604 push {r4, r5, r6, r7, r8, lr}
 *   @0x242608 mov r4, r0
 *   @0x24260c mov r0, r2
 *   @0x242610 mov r6, r1
 *   @0x242614 mov r7, r2
 *   @0x242618 bl 0xb6538 <strlen@plt>
 *   @0x24261c mov r5, r0
 *   @0x242620 mov r0, r4
 *   @0x242624 bl 0xb6538 <strlen@plt>
 *   @0x242628 add r8, r5, r6
 *   @0x24262c cmp r0, r8
 *   @0x242630 blo 0x242694 <_Z13JS_SplitMatchPKciS0_+0x90>
 *   @0x242634 cmp r5, #0
 *   @0x242638 beq 0x242678 <_Z13JS_SplitMatchPKciS0_+0x74>
 *   @0x24263c ldrb r1, [r4, r6]
 *   @0x242640 add r3, r4, r6
 *   @0x242644 ldrb r2, [r7]
 *   @0x242648 cmp r1, r2
 *   @0x24264c bne 0x242694 <_Z13JS_SplitMatchPKciS0_+0x90>
 *   @0x242650 sub r0, r7, #1
 *   @0x242654 mov r2, r7
 *   @0x242658 add r0, r0, r5
 *   @0x24265c b 0x242670 <_Z13JS_SplitMatchPKciS0_+0x6c>
 *   @0x242660 ldrb r12, [r3, #0x1]!
 *   @0x242664 ldrb r1, [r2, #0x1]!
 *   @0x242668 cmp r12, r1
 *   @0x24266c bne 0x242694 <_Z13JS_SplitMatchPKciS0_+0x90>
 *   @0x242670 cmp r2, r0
 *   @0x242674 bne 0x242660 <_Z13JS_SplitMatchPKciS0_+0x5c>
 *   @0x242678 mov r0, #8
 *   @0x24267c bl 0x27c524 <_Znwj>
 *   @0x242680 mov r2, #0
 *   @0x242684 mov r3, r0
 *   @0x242688 str r8, [r0]
 *   @0x24268c str r2, [r3, #0x4]
 *   @0x242690 pop {r4, r5, r6, r7, r8, pc}
 *   @0x242694 mov r0, #0
 *   @0x242698 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §130/197 F_JS_Object_prototype_propertyIsEnumerable(RValue&, CInstance*, CInstance*, int, RValue*)  0x255374  size 152  38 条（0x255374..0x25540c）
 * @func 0x255374 0x25540c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToString(RValue&, RValue*) / JS_GetOwnProperty(YYObjectBase*, RValue*, char const*)
 * 字段偏移 top8: 0x1c×2 / 0xc×2 / 0x4×2 / 0x30×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x255374 push {r4, r5, lr}
 *   @0x255378 sub sp, sp, #36
 *   @0x25537c mov r5, r1
 *   @0x255380 mov r4, r0
 *   @0x255384 ldr r1, [sp, #0x30]
 *   @0x255388 mov r0, sp
 *   @0x25538c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x255390 ldr r3, [sp]
 *   @0x255394 mov r2, #5
 *   @0x255398 mov r0, r5
 *   @0x25539c str r2, [sp, #0x1c]
 *   @0x2553a0 add r1, sp, #16
 *   @0x2553a4 ldr r2, [r3]
 *   @0x2553a8 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x2553ac ldr r3, [sp, #0x1c]
 *   @0x2553b0 mvn r2, #-16777216
 *   @0x2553b4 cmp r3, r2
 *   @0x2553b8 cmpne r3, #5
 *   @0x2553bc movne r3, #0
 *   @0x2553c0 moveq r3, #1
 *   @0x2553c4 beq 0x2553f4 <_Z42F_JS_Object_prototype_propertyIsEnumerableR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x2553c8 ldr r2, [sp, #0x18]
 *   @0x2553cc str r3, [r4, #0xc]
 *   @0x2553d0 ands r2, r2, #1
 *   @0x2553d4 moveq r3, r2
 *   @0x2553d8 movne r1, #0
 *   @0x2553dc moveq r1, r3
 *   @0x2553e0 movtne r1, #0x3ff0
 *   @0x2553e4 str r3, [r4]
 *   @0x2553e8 str r1, [r4, #0x4]
 *   @0x2553ec add sp, sp, #36
 *   @0x2553f0 pop {r4, r5, pc}
 *   @0x2553f4 mov r3, #0
 *   @0x2553f8 str r3, [r4, #0xc]
 *   @0x2553fc str r3, [r4]
 *   @0x255400 str r3, [r4, #0x4]
 *   @0x255404 add sp, sp, #36
 *   @0x255408 pop {r4, r5, pc}
 *
 * ══ §131/197 yySocket::ResolveToString(char*)  0x2957c0  size 152  38 条（0x2957c0..0x295858）
 * @func 0x2957c0 0x295858  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::Resolve(char*)×2 / yySocket::DetectIPv6() / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6e08 / 0xb6e14 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x68×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2957c0 push {r3, r4, r5, lr}
 *   @0x2957c4 mov r4, r0
 *   @0x2957c8 bl 0x297000 <_ZN8yySocket10DetectIPv6Ev>
 *   @0x2957cc cmp r0, #0
 *   @0x2957d0 mov r0, r4
 *   @0x2957d4 beq 0x295824 <_ZN8yySocket15ResolveToStringEPc+0x64>
 *   @0x2957d8 bl 0x2954a8 <_ZN8yySocket7ResolveEPc>
 *   @0x2957dc subs r5, r0, #0
 *   @0x2957e0 beq 0x295840 <_ZN8yySocket15ResolveToStringEPc+0x80>
 *   @0x2957e4 ldr r1, [pc, #0x68]
 *   @0x2957e8 mov r2, #624
 *   @0x2957ec mov r3, #1
 *   @0x2957f0 mov r0, #64
 *   @0x2957f4 add r1, pc, r1
 *   @0x2957f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2957fc add r1, r5, #8
 *   @0x295800 mov r3, #64
 *   @0x295804 mov r4, r0
 *   @0x295808 mov r2, r0
 *   @0x29580c mov r0, #10
 *   @0x295810 bl 0xb6e08 <inet_ntop@plt>
 *   @0x295814 subs r5, r0, #0
 *   @0x295818 mov r0, r4
 *   @0x29581c beq 0x295848 <_ZN8yySocket15ResolveToStringEPc+0x88>
 *   @0x295820 pop {r3, r4, r5, pc}
 *   @0x295824 bl 0x2954a8 <_ZN8yySocket7ResolveEPc>
 *   @0x295828 cmp r0, #0
 *   @0x29582c beq 0x295840 <_ZN8yySocket15ResolveToStringEPc+0x80>
 *   @0x295830 ldr r0, [r0, #0x4]
 *   @0x295834 bl 0xb6e14 <inet_ntoa@plt>
 *   @0x295838 pop {r3, r4, r5, lr}
 *   @0x29583c b 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x295840 mov r0, #0
 *   @0x295844 pop {r3, r4, r5, pc}
 *   @0x295848 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29584c mov r0, r5
 *   @0x295850 pop {r3, r4, r5, pc}
 *   @0x295854 strheq r3, [r12], -r4
 *
 * ══ §132/197 DebuggerStopBackgroundMessageLoop()  0x29cc30  size 152  38 条（0x29cc30..0x29ccc8）
 * @func 0x29cc30 0x29ccc8  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)×2 / CProfiler::Pause(bool) / Mutex::Lock() / Mutex::Unlock() / CThread::WaitForExit() / Mutex::~Mutex()
 * 字段偏移 top8: 0x214×4 / 0x14×4 / 0x7c×2 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29cc30 push {r3, r4, r5, lr}
 *   @0x29cc34 mov r1, #0
 *   @0x29cc38 ldr r5, [pc, #0x7c]
 *   @0x29cc3c ldr r0, [pc, #0x7c]
 *   @0x29cc40 add r5, pc, r5
 *   @0x29cc44 ldr r0, [pc, r0]
 *   @0x29cc48 bl 0x2a04b8 <_ZN9CProfiler5PauseEb>
 *   @0x29cc4c ldr r4, [r5, #0x214]
 *   @0x29cc50 cmp r4, #0
 *   @0x29cc54 popeq {r3, r4, r5, pc}
 *   @0x29cc58 ldr r0, [r4, #0x14]
 *   @0x29cc5c bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x29cc60 mov r3, #1
 *   @0x29cc64 ldr r0, [r4, #0x14]
 *   @0x29cc68 strb r3, [r4, #0x8]
 *   @0x29cc6c bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x29cc70 ldr r0, [r5, #0x214]
 *   @0x29cc74 bl 0x27e108 <_ZN7CThread11WaitForExitEv>
 *   @0x29cc78 ldr r4, [r5, #0x214]
 *   @0x29cc7c cmp r4, #0
 *   @0x29cc80 beq 0x29cca8 <_Z33DebuggerStopBackgroundMessageLoopv+0x78>
 *   @0x29cc84 ldr r5, [r4, #0x14]
 *   @0x29cc88 cmp r5, #0
 *   @0x29cc8c beq 0x29cca0 <_Z33DebuggerStopBackgroundMessageLoopv+0x70>
 *   @0x29cc90 mov r0, r5
 *   @0x29cc94 bl 0x27e020 <_ZN5MutexD2Ev>
 *   @0x29cc98 mov r0, r5
 *   @0x29cc9c bl 0x27d1d0 <_ZdlPv>
 *   @0x29cca0 mov r0, r4
 *   @0x29cca4 bl 0x27d1d0 <_ZdlPv>
 *   @0x29cca8 ldr r3, [pc, #0x14]
 *   @0x29ccac mov r2, #0
 *   @0x29ccb0 add r3, pc, r3
 *   @0x29ccb4 str r2, [r3, #0x214]
 *   @0x29ccb8 pop {r3, r4, r5, pc}
 *   @0x29ccbc subeq r10, r11, r8, asr #31
 *   @0x29ccc0 andseq r0, r5, r8, lsr #30
 *   @0x29ccc4 subeq r10, r11, r8, asr pc
 *
 * ══ §133/197 png_set_PLTE  0x2aec84  size 152  38 条（0x2aec84..0x2aed1c）
 * @func 0x2aec84 0x2aed1c  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_set_PLTE+0x2a / png_set_PLTE+0x46 / png_error / png_free_data
 * 字段偏移 top8: 0x5c×1 / 0x14×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aec84 push {r3, r4, r5, r6, r7, lr}
 *   @0x2aec88 mov r7, r2
 *   @0x2aec8c mov r5, r0
 *   @0x2aec90 beq 0x2aed12 <png_set_PLTE+0x8e>
 *   @0x2aec94 beq 0x2aed12 <png_set_PLTE+0x8e>
 *   @0x2aec98 cmp r3, #0x3
 *   @0x2aec9c ldrbeq r2, [r1, #0x18]
 *   @0x2aeca0 movne.w r0, #0x100
 *   @0x2aeca4 lsleq r0, r2
 *   @0x2aeca8 blt 0x2aecae <png_set_PLTE+0x2a>
 *   @0x2aecac ble 0x2aecca <png_set_PLTE+0x46>
 *   @0x2aecb0 mov r0, r5
 *   @0x2aecb4 ldr r1, [pc, #0x5c]
 *   @0x2aecb8 bl 0x2a642c <png_error>
 *   @0x2aecbc b 0x2aecca <png_set_PLTE+0x46>
 *   @0x2aecc0 pop.w {r3, r4, r5, r6, r7, lr}
 *   @0x2aecc4 add r1, pc
 *   @0x2aecc8 movwhs r11, #0xbd5
 *   @0x2aeccc mov.w r2, #0x1000
 *   @0x2aecd0 mov r0, r5
 *   @0x2aecd4 bl 0x2a5bc0 <png_free_data>
 *   @0x2aecd8 mov.w r1, #0x300
 *   @0x2aecdc mov r0, r5
 *   @0x2aece0 andhs pc, r3, #1004
 *   @0x2aece4 muls r2, r6, r2
 *   @0x2aece8 uxth r6, r6
 *   @0x2aecec .word 0xf60701d8
 *   @0x2aecf0 .word 0xf8d5ec66
 *   @0x2aecf4 ldrdvs r3, r4, [r3, -r8]!
 *   @0x2aecf8 strh.w r6, [r5, #0x1dc]
 *   @0x2aecfc ldr.w r3, [r4, #0xb8]
 *   @0x2aed00 strh r6, [r4, #0x14]
 *   @0x2aed04 .word 0xf8c45380
 *   @0x2aed08 stmvs r3!, {r3, r4, r5, r7, r12, sp}
 *   @0x2aed0c orr r3, r3, #0x8
 *   @0x2aed10 str r3, [r4, #0x8]
 *   @0x2aed14 cdp p0, #0xf, c0, c3, c13, #0x0
 *   @0x2aed18 cdp p0, #0xe, c0, c5, c13, #0x0
 *
 * ══ §134/197 DGifSavedExtensionToGCB(GifFileType*, int, GraphicsControlBlock*)  0x2c244c  size 152  38 条（0x2c244c..0x2c24e4）
 * @func 0x2c244c 0x2c24e4  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DGifSavedExtensionToGCB(GifFileType*, int, GraphicsControlBlock*)+0x80×2
 * 字段偏移 top8: 0x4×3 / 0x-4×2 / 0x8×2 / 0x18×1 / 0x34×1 / 0x1c×1 / 0xc×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c244c cmp r1, #0
 *   @0x2c2450 str r4, [sp, #-0x4]!
 *   @0x2c2454 blt 0x2c24cc <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x80>
 *   @0x2c2458 ldr r3, [r0, #0x18]
 *   @0x2c245c cmp r1, r3
 *   @0x2c2460 bge 0x2c24cc <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x80>
 *   @0x2c2464 ldr r3, [r0, #0x34]
 *   @0x2c2468 add r12, r1, r1, lsl #3
 *   @0x2c246c mov r1, #0
 *   @0x2c2470 mvn r0, #0
 *   @0x2c2474 add r3, r3, r12, lsl #2
 *   @0x2c2478 str r1, [r2]
 *   @0x2c247c strb r1, [r2, #0x4]
 *   @0x2c2480 ldr r4, [r3, #0x1c]
 *   @0x2c2484 str r1, [r2, #0x8]
 *   @0x2c2488 cmp r4, r1
 *   @0x2c248c str r0, [r2, #0xc]
 *   @0x2c2490 ble 0x2c24cc <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x80>
 *   @0x2c2494 ldr r12, [r3, #0x20]
 *   @0x2c2498 ldr r3, [r12, #0x8]
 *   @0x2c249c cmp r3, #249
 *   @0x2c24a0 addne r3, r12, #12
 *   @0x2c24a4 bne 0x2c24b8 <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x6c>
 *   @0x2c24a8 b 0x2c24d8 <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x8c>
 *   @0x2c24ac ldr r0, [r3, #-0x4]
 *   @0x2c24b0 cmp r0, #249
 *   @0x2c24b4 beq 0x2c24d8 <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x8c>
 *   @0x2c24b8 add r1, r1, #1
 *   @0x2c24bc mov r12, r3
 *   @0x2c24c0 cmp r1, r4
 *   @0x2c24c4 add r3, r3, #12
 *   @0x2c24c8 bne 0x2c24ac <_Z23DGifSavedExtensionToGCBP11GifFileTypeiP20GraphicsControlBlock+0x60>
 *   @0x2c24cc mov r0, #0
 *   @0x2c24d0 ldr r4, [sp], #4
 *   @0x2c24d4 bx lr
 *   @0x2c24d8 ldm r12, {r0, r1}
 *   @0x2c24dc ldr r4, [sp], #4
 *   @0x2c24e0 b 0x2c23f8 <_Z18DGifExtensionToGCBjPKhP20GraphicsControlBlock>
 *
 * ══ §135/197 GifMakeMapObject(int, GifColorType const*)  0x2c2bb0  size 152  38 条（0x2c2bb0..0x2c2c48）
 * @func 0x2c2bb0 0x2c2c48  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GifBitSize(int)×2 / 0xb6544 / 0xb6c34 / 0xb65bc / 0xb655c
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2bb0 push {r3, r4, r5, r6, r7, lr}
 *   @0x2c2bb4 mov r4, r0
 *   @0x2c2bb8 mov r6, r1
 *   @0x2c2bbc bl 0x2c2b8c <_Z10GifBitSizei>
 *   @0x2c2bc0 mov r3, #1
 *   @0x2c2bc4 cmp r4, r3, lsl r0
 *   @0x2c2bc8 bne 0x2c2c28 <_Z16GifMakeMapObjectiPK12GifColorType+0x78>
 *   @0x2c2bcc mov r0, #16
 *   @0x2c2bd0 bl 0xb6544 <malloc@plt>
 *   @0x2c2bd4 subs r5, r0, #0
 *   @0x2c2bd8 beq 0x2c2c30 <_Z16GifMakeMapObjectiPK12GifColorType+0x80>
 *   @0x2c2bdc mov r0, r4
 *   @0x2c2be0 mov r1, #3
 *   @0x2c2be4 bl 0xb6c34 <calloc@plt>
 *   @0x2c2be8 cmp r0, #0
 *   @0x2c2bec mov r7, r0
 *   @0x2c2bf0 str r0, [r5, #0xc]
 *   @0x2c2bf4 beq 0x2c2c38 <_Z16GifMakeMapObjectiPK12GifColorType+0x88>
 *   @0x2c2bf8 str r4, [r5]
 *   @0x2c2bfc mov r0, r4
 *   @0x2c2c00 bl 0x2c2b8c <_Z10GifBitSizei>
 *   @0x2c2c04 cmp r6, #0
 *   @0x2c2c08 str r0, [r5, #0x4]
 *   @0x2c2c0c beq 0x2c2c30 <_Z16GifMakeMapObjectiPK12GifColorType+0x80>
 *   @0x2c2c10 mov r1, r6
 *   @0x2c2c14 add r2, r4, r4, lsl #1
 *   @0x2c2c18 ldr r0, [r5, #0xc]
 *   @0x2c2c1c bl 0xb65bc <memcpy@plt>
 *   @0x2c2c20 mov r0, r5
 *   @0x2c2c24 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2c2c28 mov r0, #0
 *   @0x2c2c2c pop {r3, r4, r5, r6, r7, pc}
 *   @0x2c2c30 mov r0, r5
 *   @0x2c2c34 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2c2c38 mov r0, r5
 *   @0x2c2c3c bl 0xb655c <free@plt>
 *   @0x2c2c40 mov r0, r7
 *   @0x2c2c44 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §136/197 b2FrictionJoint::SetMaxForce(float)  0x2cda80  size 152  38 条（0x2cda80..0x2cdb18）
 * @func 0x2cda80 0x2cdb18  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x7c×1 / 0x2×1 / 0x38×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cda80 push {r4, lr}
 *   @0x2cda84 vpush {d8}
 *   @0x2cda88 vmov s16, r1
 *   @0x2cda8c ldr r3, [pc, #0x7c]
 *   @0x2cda90 sub sp, sp, #16
 *   @0x2cda94 vcmp.f32 s16, s16
 *   @0x2cda98 mov r4, r0
 *   @0x2cda9c ldr r3, [pc, r3]
 *   @0x2cdaa0 ldr r3, [r3]
 *   @0x2cdaa4 vmrs APSR_nzcv, fpscr
 *   @0x2cdaa8 bne 0x2cdad0 <_ZN15b2FrictionJoint11SetMaxForceEf+0x50>
 *   @0x2cdaac mov r1, #0
 *   @0x2cdab0 movw r2, #0x7f80
 *   @0x2cdab4 strh r1, [sp]
 *   @0x2cdab8 strh r2, [sp, #2]
 *   @0x2cdabc vldr s15, [sp]
 *   @0x2cdac0 vneg.f32 s14, s15
 *   @0x2cdac4 vcmpe.f32 s16, s14
 *   @0x2cdac8 vmrs APSR_nzcv, fpscr
 *   @0x2cdacc bgt 0x2cdaf0 <_ZN15b2FrictionJoint11SetMaxForceEf+0x70>
 *   @0x2cdad0 mov r0, #0
 *   @0x2cdad4 ldr r1, [pc, #0x38]
 *   @0x2cdad8 add r1, pc, r1
 *   @0x2cdadc blx r3
 *   @0x2cdae0 vstr s16, [r4, #96]
 *   @0x2cdae4 add sp, sp, #16
 *   @0x2cdae8 vpop {d8}
 *   @0x2cdaec pop {r4, pc}
 *   @0x2cdaf0 vcmpe.f32 s16, s15
 *   @0x2cdaf4 vmrs APSR_nzcv, fpscr
 *   @0x2cdaf8 bpl 0x2cdad0 <_ZN15b2FrictionJoint11SetMaxForceEf+0x50>
 *   @0x2cdafc vcmpe.f32 s16, #0
 *   @0x2cdb00 vmrs APSR_nzcv, fpscr
 *   @0x2cdb04 movge r0, #1
 *   @0x2cdb08 bge 0x2cdad4 <_ZN15b2FrictionJoint11SetMaxForceEf+0x54>
 *   @0x2cdb0c b 0x2cdad0 <_ZN15b2FrictionJoint11SetMaxForceEf+0x50>
 *   @0x2cdb10 andseq r3, r2, r12, lsr #20
 *   @0x2cdb14 .word 0x0008f8d0
 *
 * ══ §137/197 b2FrictionJoint::SetMaxTorque(float)  0x2cdb20  size 152  38 条（0x2cdb20..0x2cdbb8）
 * @func 0x2cdb20 0x2cdbb8  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x7c×1 / 0x2×1 / 0x38×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cdb20 push {r4, lr}
 *   @0x2cdb24 vpush {d8}
 *   @0x2cdb28 vmov s16, r1
 *   @0x2cdb2c ldr r3, [pc, #0x7c]
 *   @0x2cdb30 sub sp, sp, #16
 *   @0x2cdb34 vcmp.f32 s16, s16
 *   @0x2cdb38 mov r4, r0
 *   @0x2cdb3c ldr r3, [pc, r3]
 *   @0x2cdb40 ldr r3, [r3]
 *   @0x2cdb44 vmrs APSR_nzcv, fpscr
 *   @0x2cdb48 bne 0x2cdb70 <_ZN15b2FrictionJoint12SetMaxTorqueEf+0x50>
 *   @0x2cdb4c mov r1, #0
 *   @0x2cdb50 movw r2, #0x7f80
 *   @0x2cdb54 strh r1, [sp]
 *   @0x2cdb58 strh r2, [sp, #2]
 *   @0x2cdb5c vldr s15, [sp]
 *   @0x2cdb60 vneg.f32 s14, s15
 *   @0x2cdb64 vcmpe.f32 s16, s14
 *   @0x2cdb68 vmrs APSR_nzcv, fpscr
 *   @0x2cdb6c bgt 0x2cdb90 <_ZN15b2FrictionJoint12SetMaxTorqueEf+0x70>
 *   @0x2cdb70 mov r0, #0
 *   @0x2cdb74 ldr r1, [pc, #0x38]
 *   @0x2cdb78 add r1, pc, r1
 *   @0x2cdb7c blx r3
 *   @0x2cdb80 vstr s16, [r4, #100]
 *   @0x2cdb84 add sp, sp, #16
 *   @0x2cdb88 vpop {d8}
 *   @0x2cdb8c pop {r4, pc}
 *   @0x2cdb90 vcmpe.f32 s16, s15
 *   @0x2cdb94 vmrs APSR_nzcv, fpscr
 *   @0x2cdb98 bpl 0x2cdb70 <_ZN15b2FrictionJoint12SetMaxTorqueEf+0x50>
 *   @0x2cdb9c vcmpe.f32 s16, #0
 *   @0x2cdba0 vmrs APSR_nzcv, fpscr
 *   @0x2cdba4 movge r0, #1
 *   @0x2cdba8 bge 0x2cdb74 <_ZN15b2FrictionJoint12SetMaxTorqueEf+0x54>
 *   @0x2cdbac b 0x2cdb70 <_ZN15b2FrictionJoint12SetMaxTorqueEf+0x50>
 *   @0x2cdbb0 andseq r3, r2, r12, lsl #19
 *   @0x2cdbb4 strheq pc, [r8], -r8
 *
 * ══ §138/197 b2MotorJoint::SetMaxForce(float)  0x2ce730  size 152  38 条（0x2ce730..0x2ce7c8）
 * @func 0x2ce730 0x2ce7c8  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x7c×1 / 0x2×1 / 0x38×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce730 push {r4, lr}
 *   @0x2ce734 vpush {d8}
 *   @0x2ce738 vmov s16, r1
 *   @0x2ce73c ldr r3, [pc, #0x7c]
 *   @0x2ce740 sub sp, sp, #16
 *   @0x2ce744 vcmp.f32 s16, s16
 *   @0x2ce748 mov r4, r0
 *   @0x2ce74c ldr r3, [pc, r3]
 *   @0x2ce750 ldr r3, [r3]
 *   @0x2ce754 vmrs APSR_nzcv, fpscr
 *   @0x2ce758 bne 0x2ce780 <_ZN12b2MotorJoint11SetMaxForceEf+0x50>
 *   @0x2ce75c mov r1, #0
 *   @0x2ce760 movw r2, #0x7f80
 *   @0x2ce764 strh r1, [sp]
 *   @0x2ce768 strh r2, [sp, #2]
 *   @0x2ce76c vldr s15, [sp]
 *   @0x2ce770 vneg.f32 s14, s15
 *   @0x2ce774 vcmpe.f32 s16, s14
 *   @0x2ce778 vmrs APSR_nzcv, fpscr
 *   @0x2ce77c bgt 0x2ce7a0 <_ZN12b2MotorJoint11SetMaxForceEf+0x70>
 *   @0x2ce780 mov r0, #0
 *   @0x2ce784 ldr r1, [pc, #0x38]
 *   @0x2ce788 add r1, pc, r1
 *   @0x2ce78c blx r3
 *   @0x2ce790 vstr s16, [r4, #92]
 *   @0x2ce794 add sp, sp, #16
 *   @0x2ce798 vpop {d8}
 *   @0x2ce79c pop {r4, pc}
 *   @0x2ce7a0 vcmpe.f32 s16, s15
 *   @0x2ce7a4 vmrs APSR_nzcv, fpscr
 *   @0x2ce7a8 bpl 0x2ce780 <_ZN12b2MotorJoint11SetMaxForceEf+0x50>
 *   @0x2ce7ac vcmpe.f32 s16, #0
 *   @0x2ce7b0 vmrs APSR_nzcv, fpscr
 *   @0x2ce7b4 movge r0, #1
 *   @0x2ce7b8 bge 0x2ce784 <_ZN12b2MotorJoint11SetMaxForceEf+0x54>
 *   @0x2ce7bc b 0x2ce780 <_ZN12b2MotorJoint11SetMaxForceEf+0x50>
 *   @0x2ce7c0 andseq r2, r2, r12, ror sp
 *   @0x2ce7c4 andeq lr, r8, r0, lsr #24
 *
 * ══ §139/197 b2MotorJoint::SetMaxTorque(float)  0x2ce7d0  size 152  38 条（0x2ce7d0..0x2ce868）
 * @func 0x2ce7d0 0x2ce868  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x7c×1 / 0x2×1 / 0x38×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce7d0 push {r4, lr}
 *   @0x2ce7d4 vpush {d8}
 *   @0x2ce7d8 vmov s16, r1
 *   @0x2ce7dc ldr r3, [pc, #0x7c]
 *   @0x2ce7e0 sub sp, sp, #16
 *   @0x2ce7e4 vcmp.f32 s16, s16
 *   @0x2ce7e8 mov r4, r0
 *   @0x2ce7ec ldr r3, [pc, r3]
 *   @0x2ce7f0 ldr r3, [r3]
 *   @0x2ce7f4 vmrs APSR_nzcv, fpscr
 *   @0x2ce7f8 bne 0x2ce820 <_ZN12b2MotorJoint12SetMaxTorqueEf+0x50>
 *   @0x2ce7fc mov r1, #0
 *   @0x2ce800 movw r2, #0x7f80
 *   @0x2ce804 strh r1, [sp]
 *   @0x2ce808 strh r2, [sp, #2]
 *   @0x2ce80c vldr s15, [sp]
 *   @0x2ce810 vneg.f32 s14, s15
 *   @0x2ce814 vcmpe.f32 s16, s14
 *   @0x2ce818 vmrs APSR_nzcv, fpscr
 *   @0x2ce81c bgt 0x2ce840 <_ZN12b2MotorJoint12SetMaxTorqueEf+0x70>
 *   @0x2ce820 mov r0, #0
 *   @0x2ce824 ldr r1, [pc, #0x38]
 *   @0x2ce828 add r1, pc, r1
 *   @0x2ce82c blx r3
 *   @0x2ce830 vstr s16, [r4, #96]
 *   @0x2ce834 add sp, sp, #16
 *   @0x2ce838 vpop {d8}
 *   @0x2ce83c pop {r4, pc}
 *   @0x2ce840 vcmpe.f32 s16, s15
 *   @0x2ce844 vmrs APSR_nzcv, fpscr
 *   @0x2ce848 bpl 0x2ce820 <_ZN12b2MotorJoint12SetMaxTorqueEf+0x50>
 *   @0x2ce84c vcmpe.f32 s16, #0
 *   @0x2ce850 vmrs APSR_nzcv, fpscr
 *   @0x2ce854 movge r0, #1
 *   @0x2ce858 bge 0x2ce824 <_ZN12b2MotorJoint12SetMaxTorqueEf+0x54>
 *   @0x2ce85c b 0x2ce820 <_ZN12b2MotorJoint12SetMaxTorqueEf+0x50>
 *   @0x2ce860 ldrsbeq r2, [r2], -r12
 *   @0x2ce864 andeq lr, r8, r8, lsl #24
 *
 * ══ §140/197 b2ParticleGroup::b2ParticleGroup()  0x2d4560  size 152  38 条（0x2d4560..0x2d45f8）
 * @func 0x2d4560 0x2d45f8  size 152  38 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4c×2 / 0x8c×1 / 0x1c×1 / 0x20×1 / 0x24×1 / 0x10×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4560 ldr r12, [pc, #0x8c]
 *   @0x2d4564 mov r3, r0
 *   @0x2d4568 push {r4, r5, r6, r7, r8}
 *   @0x2d456c ldr r12, [pc, r12]
 *   @0x2d4570 ldrb r5, [r0, #0x4c]
 *   @0x2d4574 add r7, r0, #40
 *   @0x2d4578 ldm r12, {r0, r1}
 *   @0x2d457c mvn r6, #0
 *   @0x2d4580 orr r5, r5, #1
 *   @0x2d4584 str r6, [r3, #0x1c]
 *   @0x2d4588 add r6, r3, #48
 *   @0x2d458c and r5, r5, #253
 *   @0x2d4590 mov r2, #0
 *   @0x2d4594 mov r4, #0
 *   @0x2d4598 mov r8, #1065353216
 *   @0x2d459c str r4, [r3, #0x20]
 *   @0x2d45a0 str r4, [r3, #0x24]
 *   @0x2d45a4 bfi r5, r2, #2, #1
 *   @0x2d45a8 str r8, [r3, #0x10]
 *   @0x2d45ac str r2, [r3]
 *   @0x2d45b0 str r2, [r3, #0x4]
 *   @0x2d45b4 str r2, [r3, #0x8]
 *   @0x2d45b8 str r2, [r3, #0xc]
 *   @0x2d45bc str r2, [r3, #0x14]
 *   @0x2d45c0 str r2, [r3, #0x18]
 *   @0x2d45c4 stm r7, {r0, r1}
 *   @0x2d45c8 stm r6, {r0, r1}
 *   @0x2d45cc mov r0, r3
 *   @0x2d45d0 str r4, [r3, #0x38]
 *   @0x2d45d4 strb r5, [r3, #0x4c]
 *   @0x2d45d8 str r4, [r3, #0x3c]
 *   @0x2d45dc str r4, [r3, #0x40]
 *   @0x2d45e0 str r4, [r3, #0x44]
 *   @0x2d45e4 str r8, [r3, #0x48]
 *   @0x2d45e8 str r2, [r3, #0x50]
 *   @0x2d45ec pop {r4, r5, r6, r7, r8}
 *   @0x2d45f0 bx lr
 *   @0x2d45f4 andseq r12, r1, r12, ror #30
 *
 * ══ §141/197 CBackground::LoadFromData(void*, int, int, bool, bool, bool, bool)  0xc2618  size 148  37 条（0xc2618..0xc26ac）
 * @func 0xc2618 0xc26ac  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBitmapLoader::Create(void*, int, int) / CBackground::CreateFromBitmap(IBitmap*, bool, bool, bool, bool)
 * 字段偏移 top8: 0x4×3 / 0x28×1 / 0x2c×1 / 0x30×1 / 0x34×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2618 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc261c sub sp, sp, #8
 *   @0xc2620 mov r6, r0
 *   @0xc2624 mov r0, r1
 *   @0xc2628 mov r1, r2
 *   @0xc262c mov r2, r3
 *   @0xc2630 ldrb r9, [sp, #0x28]
 *   @0xc2634 ldrb r7, [sp, #0x2c]
 *   @0xc2638 ldrb r10, [sp, #0x30]
 *   @0xc263c ldrb r8, [sp, #0x34]
 *   @0xc2640 bl 0x1a928c <_ZN13IBitmapLoader6CreateEPvii>
 *   @0xc2644 mov r1, #0
 *   @0xc2648 ldr r3, [r0]
 *   @0xc264c mov r5, r0
 *   @0xc2650 ldr r3, [r3, #0x10]
 *   @0xc2654 blx r3
 *   @0xc2658 str r10, [sp]
 *   @0xc265c mov r2, r9
 *   @0xc2660 str r8, [sp, #0x4]
 *   @0xc2664 mov r3, r7
 *   @0xc2668 mov r4, r0
 *   @0xc266c mov r0, r6
 *   @0xc2670 mov r1, r4
 *   @0xc2674 bl 0xc244c <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb>
 *   @0xc2678 cmp r4, #0
 *   @0xc267c beq 0xc2690 <_ZN11CBackground12LoadFromDataEPviibbbb+0x78>
 *   @0xc2680 ldr r3, [r4]
 *   @0xc2684 mov r0, r4
 *   @0xc2688 ldr r3, [r3, #0x4]
 *   @0xc268c blx r3
 *   @0xc2690 ldr r3, [r5]
 *   @0xc2694 mov r0, r5
 *   @0xc2698 ldr r3, [r3, #0x4]
 *   @0xc269c blx r3
 *   @0xc26a0 mov r0, #1
 *   @0xc26a4 add sp, sp, #8
 *   @0xc26a8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §142/197 F_BUFFER_Get_Type(RValue&, CInstance*, CInstance*, int, RValue*)  0xc50ec  size 148  37 条（0xc50ec..0xc5180）
 * @func 0xc50ec 0xc5180  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x8×1 / 0x30×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc50ec push {r4, lr}
 *   @0xc50f0 mov r1, #0
 *   @0xc50f4 ldr r12, [sp, #0x8]
 *   @0xc50f8 mov r3, r1
 *   @0xc50fc str r1, [r0, #0xc]
 *   @0xc5100 movt r3, #0xbff0
 *   @0xc5104 mov r4, r0
 *   @0xc5108 str r1, [r0]
 *   @0xc510c ldr r2, [r12, #0xc]
 *   @0xc5110 str r3, [r0, #0x4]
 *   @0xc5114 cmp r2, #13
 *   @0xc5118 pophi {r4, pc}
 *   @0xc511c mov r0, #1
 *   @0xc5120 movw r3, #0x2483
 *   @0xc5124 lsl r2, r0, r2
 *   @0xc5128 and r3, r2, r3
 *   @0xc512c cmp r3, r1
 *   @0xc5130 popeq {r4, pc}
 *   @0xc5134 mov r0, r12
 *   @0xc5138 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc513c cmp r0, #0
 *   @0xc5140 poplt {r4, pc}
 *   @0xc5144 ldr r3, [pc, #0x30]
 *   @0xc5148 add r3, pc, r3
 *   @0xc514c ldr r2, [r3]
 *   @0xc5150 cmp r0, r2
 *   @0xc5154 popge {r4, pc}
 *   @0xc5158 ldr r3, [r3, #0x4]
 *   @0xc515c ldr r3, [r3, r0, lsl #2]
 *   @0xc5160 cmp r3, #0
 *   @0xc5164 ldrne r2, [r3, #0x18]
 *   @0xc5168 vmovne s15, r2
 *   @0xc516c vcvtne.f64.u32 d7, s15
 *   @0xc5170 vmovne r2, r3, d7
 *   @0xc5174 stmne r4, {r2, r3}
 *   @0xc5178 pop {r4, pc}
 *   @0xc517c eorseq r4, r11, r12, asr #31
 *
 * ══ §143/197 F_BUFFER_Get_Alignment(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5180  size 148  37 条（0xc5180..0xc5214）
 * @func 0xc5180 0xc5214  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x8×1 / 0x30×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5180 push {r4, lr}
 *   @0xc5184 mov r1, #0
 *   @0xc5188 ldr r12, [sp, #0x8]
 *   @0xc518c mov r3, r1
 *   @0xc5190 str r1, [r0, #0xc]
 *   @0xc5194 movt r3, #0xbff0
 *   @0xc5198 mov r4, r0
 *   @0xc519c str r1, [r0]
 *   @0xc51a0 ldr r2, [r12, #0xc]
 *   @0xc51a4 str r3, [r0, #0x4]
 *   @0xc51a8 cmp r2, #13
 *   @0xc51ac pophi {r4, pc}
 *   @0xc51b0 mov r0, #1
 *   @0xc51b4 movw r3, #0x2483
 *   @0xc51b8 lsl r2, r0, r2
 *   @0xc51bc and r3, r2, r3
 *   @0xc51c0 cmp r3, r1
 *   @0xc51c4 popeq {r4, pc}
 *   @0xc51c8 mov r0, r12
 *   @0xc51cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc51d0 cmp r0, #0
 *   @0xc51d4 poplt {r4, pc}
 *   @0xc51d8 ldr r3, [pc, #0x30]
 *   @0xc51dc add r3, pc, r3
 *   @0xc51e0 ldr r2, [r3]
 *   @0xc51e4 cmp r0, r2
 *   @0xc51e8 popge {r4, pc}
 *   @0xc51ec ldr r3, [r3, #0x4]
 *   @0xc51f0 ldr r3, [r3, r0, lsl #2]
 *   @0xc51f4 cmp r3, #0
 *   @0xc51f8 ldrne r2, [r3, #0x14]
 *   @0xc51fc vmovne s15, r2
 *   @0xc5200 vcvtne.f64.s32 d7, s15
 *   @0xc5204 vmovne r2, r3, d7
 *   @0xc5208 stmne r4, {r2, r3}
 *   @0xc520c pop {r4, pc}
 *   @0xc5210 eorseq r4, r11, r8, lsr pc
 *
 * ══ §144/197 F_Vertex_Colour_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc9360  size 148  37 条（0xc9360..0xc93f4）
 * @func 0xc9360 0xc93f4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Init_Vertex_Write(RValue&, int, RValue*, int) / Buffer_Vertex::FindNextUsage(yyVertexUsage, yyVertexType) / YYGetUint32(RValue const*, int) / YYGetFloat(RValue const*, int) / F_Vertex_Colour_debug(RValue&, CInstance*, CInstance*, int, RValue*)+0x80
 * 字段偏移 top8: 0x10×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9360 push {r4, r5, r6, lr}
 *   @0xc9364 mov r1, r3
 *   @0xc9368 ldr r4, [sp, #0x10]
 *   @0xc936c mov r3, #3
 *   @0xc9370 mov r2, r4
 *   @0xc9374 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i>
 *   @0xc9378 cmp r0, #0
 *   @0xc937c popeq {r4, r5, r6, pc}
 *   @0xc9380 mov r1, #2
 *   @0xc9384 mov r2, #5
 *   @0xc9388 bl 0xc8648 <_ZN13Buffer_Vertex13FindNextUsageE13yyVertexUsage12yyVertexType>
 *   @0xc938c subs r5, r0, #0
 *   @0xc9390 popeq {r4, r5, r6, pc}
 *   @0xc9394 mov r1, #1
 *   @0xc9398 mov r0, r4
 *   @0xc939c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc93a0 mov r1, #2
 *   @0xc93a4 mov r6, r0
 *   @0xc93a8 mov r0, r4
 *   @0xc93ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc93b0 vldr s15, [pc, #56]
 *   @0xc93b4 vmov s14, r0
 *   @0xc93b8 vmul.f32 s15, s14, s15
 *   @0xc93bc vcvt.s32.f32 s15, s15
 *   @0xc93c0 vmov r3, s15
 *   @0xc93c4 cmp r3, #255
 *   @0xc93c8 movgt r3, #-16777216
 *   @0xc93cc ble 0xc93e0 <_Z21F_Vertex_Colour_debugR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xc93d0 bic r6, r6, #-16777216
 *   @0xc93d4 orr r6, r3, r6
 *   @0xc93d8 str r6, [r5]
 *   @0xc93dc pop {r4, r5, r6, pc}
 *   @0xc93e0 cmp r3, #0
 *   @0xc93e4 lslge r3, r3, #24
 *   @0xc93e8 movlt r3, #0
 *   @0xc93ec b 0xc93d0 <_Z21F_Vertex_Colour_debugR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0xc93f0 cmnmi pc, #0
 *
 * ══ §145/197 F_DsStackEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0xfbb84  size 148  37 条（0xfbb84..0xfbc18）
 * @func 0xfbb84 0xfbc18  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsStackEmpty(RValue&, CInstance*, CInstance*, int, RValue*)+0x74 / CDS_Stack::Empty()
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x64×1 / 0x54×1 / 0x2×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfbb84 push {r3, r4, r5, lr}
 *   @0xfbb88 mov r1, #0
 *   @0xfbb8c mov r4, r0
 *   @0xfbb90 ldr r0, [sp, #0x10]
 *   @0xfbb94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfbb98 cmp r0, #0
 *   @0xfbb9c blt 0xfbbf8 <_Z14F_DsStackEmptyR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0xfbba0 ldr r3, [pc, #0x64]
 *   @0xfbba4 ldr r3, [pc, r3]
 *   @0xfbba8 ldr r3, [r3]
 *   @0xfbbac cmp r0, r3
 *   @0xfbbb0 bge 0xfbbf8 <_Z14F_DsStackEmptyR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0xfbbb4 ldr r3, [pc, #0x54]
 *   @0xfbbb8 ldr r3, [pc, r3]
 *   @0xfbbbc ldr r3, [r3, #0x4]
 *   @0xfbbc0 ldr r0, [r3, r0, lsl #2]
 *   @0xfbbc4 cmp r0, #0
 *   @0xfbbc8 beq 0xfbbf8 <_Z14F_DsStackEmptyR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0xfbbcc mov r5, #0
 *   @0xfbbd0 str r5, [r4, #0xc]
 *   @0xfbbd4 bl 0x202d40 <_ZN9CDS_Stack5EmptyEv>
 *   @0xfbbd8 cmp r0, #0
 *   @0xfbbdc moveq r5, r0
 *   @0xfbbe0 movne r3, r5
 *   @0xfbbe4 moveq r3, r5
 *   @0xfbbe8 movtne r3, #0x3ff0
 *   @0xfbbec str r5, [r4]
 *   @0xfbbf0 str r3, [r4, #0x4]
 *   @0xfbbf4 pop {r3, r4, r5, pc}
 *   @0xfbbf8 ldr r0, [pc, #0x14]
 *   @0xfbbfc mov r1, #0
 *   @0xfbc00 pop {r3, r4, r5, lr}
 *   @0xfbc04 add r0, pc, r0
 *   @0xfbc08 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfbc0c .word 0x002f22d8
 *   @0xfbc10 eoreq r2, pc, r8, asr #5
 *   @0xfbc14 .word 0x0023bff8
 *
 * ══ §146/197 F_DsQueueEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0xfbfb4  size 148  37 条（0xfbfb4..0xfc048）
 * @func 0xfbfb4 0xfc048  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsQueueEmpty(RValue&, CInstance*, CInstance*, int, RValue*)+0x74 / CDS_Queue::Empty()
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x64×1 / 0x54×1 / 0x2×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfbfb4 push {r3, r4, r5, lr}
 *   @0xfbfb8 mov r1, #0
 *   @0xfbfbc mov r4, r0
 *   @0xfbfc0 ldr r0, [sp, #0x10]
 *   @0xfbfc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfbfc8 cmp r0, #0
 *   @0xfbfcc blt 0xfc028 <_Z14F_DsQueueEmptyR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0xfbfd0 ldr r3, [pc, #0x64]
 *   @0xfbfd4 ldr r3, [pc, r3]
 *   @0xfbfd8 ldr r3, [r3]
 *   @0xfbfdc cmp r0, r3
 *   @0xfbfe0 bge 0xfc028 <_Z14F_DsQueueEmptyR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0xfbfe4 ldr r3, [pc, #0x54]
 *   @0xfbfe8 ldr r3, [pc, r3]
 *   @0xfbfec ldr r3, [r3, #0x4]
 *   @0xfbff0 ldr r0, [r3, r0, lsl #2]
 *   @0xfbff4 cmp r0, #0
 *   @0xfbff8 beq 0xfc028 <_Z14F_DsQueueEmptyR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0xfbffc mov r5, #0
 *   @0xfc000 str r5, [r4, #0xc]
 *   @0xfc004 bl 0x202fe0 <_ZN9CDS_Queue5EmptyEv>
 *   @0xfc008 cmp r0, #0
 *   @0xfc00c moveq r5, r0
 *   @0xfc010 movne r3, r5
 *   @0xfc014 moveq r3, r5
 *   @0xfc018 movtne r3, #0x3ff0
 *   @0xfc01c str r5, [r4]
 *   @0xfc020 str r3, [r4, #0x4]
 *   @0xfc024 pop {r3, r4, r5, pc}
 *   @0xfc028 ldr r0, [pc, #0x14]
 *   @0xfc02c mov r1, #0
 *   @0xfc030 pop {r3, r4, r5, lr}
 *   @0xfc034 add r0, pc, r0
 *   @0xfc038 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc03c mlaeq pc, r8, lr, r1
 *   @0xfc040 eoreq r1, pc, r8, lsl #29
 *   @0xfc044 eoreq r11, r3, r8, asr #23
 *
 * ══ §147/197 F_DsListEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc3e0  size 148  37 条（0xfc3e0..0xfc474）
 * @func 0xfc3e0 0xfc474  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsListEmpty(RValue&, CInstance*, CInstance*, int, RValue*)+0x74 / CDS_List::Empty()
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x64×1 / 0x54×1 / 0x2×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc3e0 push {r3, r4, r5, lr}
 *   @0xfc3e4 mov r1, #0
 *   @0xfc3e8 mov r4, r0
 *   @0xfc3ec ldr r0, [sp, #0x10]
 *   @0xfc3f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc3f4 cmp r0, #0
 *   @0xfc3f8 blt 0xfc454 <_Z13F_DsListEmptyR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0xfc3fc ldr r3, [pc, #0x64]
 *   @0xfc400 ldr r3, [pc, r3]
 *   @0xfc404 ldr r3, [r3]
 *   @0xfc408 cmp r0, r3
 *   @0xfc40c bge 0xfc454 <_Z13F_DsListEmptyR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0xfc410 ldr r3, [pc, #0x54]
 *   @0xfc414 ldr r3, [pc, r3]
 *   @0xfc418 ldr r3, [r3, #0x4]
 *   @0xfc41c ldr r0, [r3, r0, lsl #2]
 *   @0xfc420 cmp r0, #0
 *   @0xfc424 beq 0xfc454 <_Z13F_DsListEmptyR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0xfc428 mov r5, #0
 *   @0xfc42c str r5, [r4, #0xc]
 *   @0xfc430 bl 0x20317c <_ZN8CDS_List5EmptyEv>
 *   @0xfc434 cmp r0, #0
 *   @0xfc438 moveq r5, r0
 *   @0xfc43c movne r3, r5
 *   @0xfc440 moveq r3, r5
 *   @0xfc444 movtne r3, #0x3ff0
 *   @0xfc448 str r5, [r4]
 *   @0xfc44c str r3, [r4, #0x4]
 *   @0xfc450 pop {r3, r4, r5, pc}
 *   @0xfc454 ldr r0, [pc, #0x14]
 *   @0xfc458 mov r1, #0
 *   @0xfc45c pop {r3, r4, r5, lr}
 *   @0xfc460 add r0, pc, r0
 *   @0xfc464 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc468 eoreq r1, pc, r12, ror r8
 *   @0xfc46c eoreq r1, pc, r12, ror #16
 *   @0xfc470 mlaeq r3, r12, r7, r11
 *
 * ══ §148/197 F_DsPriorityEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0xfcc50  size 148  37 条（0xfcc50..0xfcce4）
 * @func 0xfcc50 0xfcce4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsPriorityEmpty(RValue&, CInstance*, CInstance*, int, RValue*)+0x74 / CDS_Priority::Empty()
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x64×1 / 0x54×1 / 0x2×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfcc50 push {r3, r4, r5, lr}
 *   @0xfcc54 mov r1, #0
 *   @0xfcc58 mov r4, r0
 *   @0xfcc5c ldr r0, [sp, #0x10]
 *   @0xfcc60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfcc64 cmp r0, #0
 *   @0xfcc68 blt 0xfccc4 <_Z17F_DsPriorityEmptyR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0xfcc6c ldr r3, [pc, #0x64]
 *   @0xfcc70 ldr r3, [pc, r3]
 *   @0xfcc74 ldr r3, [r3]
 *   @0xfcc78 cmp r0, r3
 *   @0xfcc7c bge 0xfccc4 <_Z17F_DsPriorityEmptyR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0xfcc80 ldr r3, [pc, #0x54]
 *   @0xfcc84 ldr r3, [pc, r3]
 *   @0xfcc88 ldr r3, [r3, #0x4]
 *   @0xfcc8c ldr r0, [r3, r0, lsl #2]
 *   @0xfcc90 cmp r0, #0
 *   @0xfcc94 beq 0xfccc4 <_Z17F_DsPriorityEmptyR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0xfcc98 mov r5, #0
 *   @0xfcc9c str r5, [r4, #0xc]
 *   @0xfcca0 bl 0x2040f8 <_ZN12CDS_Priority5EmptyEv>
 *   @0xfcca4 cmp r0, #0
 *   @0xfcca8 moveq r5, r0
 *   @0xfccac movne r3, r5
 *   @0xfccb0 moveq r3, r5
 *   @0xfccb4 movtne r3, #0x3ff0
 *   @0xfccb8 str r5, [r4]
 *   @0xfccbc str r3, [r4, #0x4]
 *   @0xfccc0 pop {r3, r4, r5, pc}
 *   @0xfccc4 ldr r0, [pc, #0x14]
 *   @0xfccc8 mov r1, #0
 *   @0xfcccc pop {r3, r4, r5, lr}
 *   @0xfccd0 add r0, pc, r0
 *   @0xfccd4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfccd8 eoreq r1, pc, r4, lsl #4
 *   @0xfccdc .word 0x002f11f4
 *   @0xfcce0 eoreq r10, r3, r12, lsr #30
 *
 * ══ §149/197 F_DotProduct_3D(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e0e8  size 148  37 条（0x10e0e8..0x10e17c）
 * @func 0x10e0e8 0x10e17c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×6
 * 字段偏移 top8: 0x38×1 / 0xc×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e0e8 push {r3, r4, r5, lr}
 *   @0x10e0ec vpush {d8, d9, d10, d11, d12}
 *   @0x10e0f0 mov r5, r0
 *   @0x10e0f4 ldr r4, [sp, #0x38]
 *   @0x10e0f8 mov r1, #0
 *   @0x10e0fc str r1, [r0, #0xc]
 *   @0x10e100 mov r0, r4
 *   @0x10e104 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e108 vmov d10, r0, r1
 *   @0x10e10c mov r0, r4
 *   @0x10e110 mov r1, #1
 *   @0x10e114 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e118 vmov d12, r0, r1
 *   @0x10e11c mov r0, r4
 *   @0x10e120 mov r1, #2
 *   @0x10e124 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e128 vmov d8, r0, r1
 *   @0x10e12c mov r0, r4
 *   @0x10e130 mov r1, #3
 *   @0x10e134 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e138 vmov d9, r0, r1
 *   @0x10e13c mov r0, r4
 *   @0x10e140 mov r1, #4
 *   @0x10e144 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e148 vmov d11, r0, r1
 *   @0x10e14c mov r0, r4
 *   @0x10e150 mov r1, #5
 *   @0x10e154 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10e158 vmul.f64 d7, d12, d11
 *   @0x10e15c vmla.f64 d7, d10, d9
 *   @0x10e160 vmov d6, r0, r1
 *   @0x10e164 vmla.f64 d7, d8, d6
 *   @0x10e168 vmov r2, s14
 *   @0x10e16c vmov r3, s15
 *   @0x10e170 stm r5, {r2, r3}
 *   @0x10e174 vpop {d8, d9, d10, d11, d12}
 *   @0x10e178 pop {r3, r4, r5, pc}
 *
 * ══ §150/197 F_DrawGetPixelExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a8ec  size 148  37 条（0x11a8ec..0x11a980）
 * @func 0x11a8ec 0x11a980  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / GR_Window_View_Convert_World(int, float, float, int&, int&) / GR_D3D_GetPixel(int, int)
 * 字段偏移 top8: 0xc×3 / 0x8×2 / 0x80×1 / 0x28×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a8ec push {r4, r5, r6, r7, r8, lr}
 *   @0x11a8f0 sub sp, sp, #16
 *   @0x11a8f4 ldr r3, [pc, #0x80]
 *   @0x11a8f8 mov r4, #0
 *   @0x11a8fc ldr r6, [sp, #0x28]
 *   @0x11a900 mov r5, r0
 *   @0x11a904 ldr r3, [pc, r3]
 *   @0x11a908 mov r1, r4
 *   @0x11a90c str r4, [sp, #0x8]
 *   @0x11a910 mov r0, r6
 *   @0x11a914 ldr r7, [r3]
 *   @0x11a918 str r4, [sp, #0xc]
 *   @0x11a91c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11a920 mov r1, #1
 *   @0x11a924 mov r8, r0
 *   @0x11a928 mov r0, r6
 *   @0x11a92c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11a930 add r3, sp, #8
 *   @0x11a934 add r12, sp, #12
 *   @0x11a938 mov r1, r8
 *   @0x11a93c str r12, [sp]
 *   @0x11a940 mov r2, r0
 *   @0x11a944 mov r0, r7
 *   @0x11a948 bl 0x17a110 <_Z28GR_Window_View_Convert_WorldiffRiS_>
 *   @0x11a94c ldr r1, [sp, #0xc]
 *   @0x11a950 str r4, [r5, #0xc]
 *   @0x11a954 ldr r0, [sp, #0x8]
 *   @0x11a958 bl 0x169d00 <_Z15GR_D3D_GetPixelii>
 *   @0x11a95c vmov s15, r0
 *   @0x11a960 vcvt.f64.u32 d7, s15
 *   @0x11a964 vmov r0, r1, d7
 *   @0x11a968 vmov r2, s14
 *   @0x11a96c mov r3, r1
 *   @0x11a970 stm r5, {r2, r3}
 *   @0x11a974 add sp, sp, #16
 *   @0x11a978 pop {r4, r5, r6, r7, r8, pc}
 *   @0x11a97c eoreq r3, sp, r12, asr #25
 *
 * ══ §151/197 YYGML_draw_text_ext_transformed_color(float, float, char const*, int, int, float, float, float, int, int, int, int, float)  0x122630  size 148  37 条（0x122630..0x1226c4）
 * @func 0x122630 0x1226c4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*) / GR_Text_Draw_Transformed_Color(float, float, char const*, int, int, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)
 * 字段偏移 top8: 0x2c×2 / 0x68×1 / 0x78×1 / 0x7c×1 / 0x80×1 / 0x84×1 / 0x10×1 / 0x14×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x122630 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x122634 vpush {d8, d9}
 *   @0x122638 sub sp, sp, #52
 *   @0x12263c vldr s19, [sp, #108]
 *   @0x122640 mov r7, r0
 *   @0x122644 mov r0, r2
 *   @0x122648 ldr r6, [sp, #0x68]
 *   @0x12264c mov r8, r1
 *   @0x122650 ldr r5, [sp, #0x78]
 *   @0x122654 vldr s18, [sp, #112]
 *   @0x122658 ldr r10, [sp, #0x7c]
 *   @0x12265c vldr s17, [sp, #116]
 *   @0x122660 ldr r11, [sp, #0x80]
 *   @0x122664 vldr s16, [sp, #136]
 *   @0x122668 ldr r9, [sp, #0x84]
 *   @0x12266c str r3, [sp, #0x2c]
 *   @0x122670 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x122674 str r6, [sp]
 *   @0x122678 vstr s19, [sp, #4]
 *   @0x12267c vstr s18, [sp, #8]
 *   @0x122680 vstr s17, [sp, #12]
 *   @0x122684 str r5, [sp, #0x10]
 *   @0x122688 vstr s16, [sp, #32]
 *   @0x12268c str r10, [sp, #0x14]
 *   @0x122690 mov r1, r8
 *   @0x122694 ldr r3, [sp, #0x2c]
 *   @0x122698 str r11, [sp, #0x18]
 *   @0x12269c str r9, [sp, #0x1c]
 *   @0x1226a0 mov r4, r0
 *   @0x1226a4 mov r0, r7
 *   @0x1226a8 mov r2, r4
 *   @0x1226ac bl 0x1735a0 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf>
 *   @0x1226b0 mov r0, r4
 *   @0x1226b4 add sp, sp, #52
 *   @0x1226b8 vpop {d8, d9}
 *   @0x1226bc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1226c0 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *
 * ══ §152/197 F_PartSystemLayer(RValue&, CInstance*, CInstance*, int, RValue*)  0x129864  size 148  37 条（0x129864..0x1298f8）
 * @func 0x129864 0x1298f8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129864 mov r1, #0
 *   @0x129868 push {r3, r4, r5, lr}
 *   @0x12986c mov r2, r1
 *   @0x129870 movt r1, #0xbff0
 *   @0x129874 str r2, [r0, #0xc]
 *   @0x129878 str r1, [r0, #0x4]
 *   @0x12987c str r2, [r0]
 *   @0x129880 ldr r4, [sp, #0x10]
 *   @0x129884 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x129888 ldr r1, [r4, #0x1c]
 *   @0x12988c bic r1, r1, #-16777216
 *   @0x129890 cmp r1, #1
 *   @0x129894 mov r5, r0
 *   @0x129898 mov r0, r4
 *   @0x12989c beq 0x1298d8 <_Z17F_PartSystemLayerR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1298a0 mov r1, #1
 *   @0x1298a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1298a8 mov r1, r0
 *   @0x1298ac mov r0, r5
 *   @0x1298b0 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1298b4 mov r5, r0
 *   @0x1298b8 cmp r5, #0
 *   @0x1298bc popeq {r3, r4, r5, pc}
 *   @0x1298c0 mov r0, r4
 *   @0x1298c4 mov r1, #0
 *   @0x1298c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1298cc ldr r1, [r5]
 *   @0x1298d0 pop {r3, r4, r5, lr}
 *   @0x1298d4 b 0x1a4660 <_Z20ParticleSystem_Layerii>
 *   @0x1298d8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1298dc mov r1, r0
 *   @0x1298e0 mov r0, r5
 *   @0x1298e4 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1298e8 mov r5, r0
 *   @0x1298ec cmp r5, #0
 *   @0x1298f0 bne 0x1298c0 <_Z17F_PartSystemLayerR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x1298f4 pop {r3, r4, r5, pc}
 *
 * ══ §153/197 F_ObjectGetSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x12aad4  size 148  37 条（0x12aad4..0x12ab68）
 * @func 0x12aad4 0x12ab68  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0xc×2 / 0x74×1 / 0x3×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12aad4 push {r4, lr}
 *   @0x12aad8 mov r1, #0
 *   @0x12aadc mov r4, r0
 *   @0x12aae0 ldr r0, [sp, #0x8]
 *   @0x12aae4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12aae8 ldr r3, [pc, #0x74]
 *   @0x12aaec ldr r3, [pc, r3]
 *   @0x12aaf0 ldr r3, [r3]
 *   @0x12aaf4 ldr r2, [r3, #0x4]
 *   @0x12aaf8 ldr r3, [r3]
 *   @0x12aafc and r2, r0, r2
 *   @0x12ab00 ldr r3, [r3, r2, lsl #3]
 *   @0x12ab04 cmp r3, #0
 *   @0x12ab08 bne 0x12ab1c <_Z17F_ObjectGetSpriteR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12ab0c b 0x12ab48 <_Z17F_ObjectGetSpriteR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12ab10 ldr r3, [r3, #0x4]
 *   @0x12ab14 cmp r3, #0
 *   @0x12ab18 beq 0x12ab48 <_Z17F_ObjectGetSpriteR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12ab1c ldr r2, [r3, #0x8]
 *   @0x12ab20 cmp r0, r2
 *   @0x12ab24 bne 0x12ab10 <_Z17F_ObjectGetSpriteR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12ab28 ldr r3, [r3, #0xc]
 *   @0x12ab2c cmp r3, #0
 *   @0x12ab30 beq 0x12ab48 <_Z17F_ObjectGetSpriteR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12ab34 ldr r2, [r3, #0x4]
 *   @0x12ab38 vmov s15, r2
 *   @0x12ab3c vcvt.f64.s32 d7, s15
 *   @0x12ab40 vmov r2, r3, d7
 *   @0x12ab44 b 0x12ab54 <_Z17F_ObjectGetSpriteR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12ab48 mov r3, #0
 *   @0x12ab4c movt r3, #0xbff0
 *   @0x12ab50 mov r2, #0
 *   @0x12ab54 mov r1, #0
 *   @0x12ab58 stm r4, {r2, r3}
 *   @0x12ab5c str r1, [r4, #0xc]
 *   @0x12ab60 pop {r4, pc}
 *   @0x12ab64 eoreq r3, r12, r0, asr r1
 *
 * ══ §154/197 F_ObjectGetDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x12aca0  size 148  37 条（0x12aca0..0x12ad34）
 * @func 0x12aca0 0x12ad34  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×3 / 0x4×2 / 0xc×2 / 0x74×1 / 0x3×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12aca0 push {r4, lr}
 *   @0x12aca4 mov r1, #0
 *   @0x12aca8 mov r4, r0
 *   @0x12acac ldr r0, [sp, #0x8]
 *   @0x12acb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12acb4 ldr r3, [pc, #0x74]
 *   @0x12acb8 ldr r3, [pc, r3]
 *   @0x12acbc ldr r3, [r3]
 *   @0x12acc0 ldr r2, [r3, #0x4]
 *   @0x12acc4 ldr r3, [r3]
 *   @0x12acc8 and r2, r0, r2
 *   @0x12accc ldr r3, [r3, r2, lsl #3]
 *   @0x12acd0 cmp r3, #0
 *   @0x12acd4 bne 0x12ace8 <_Z16F_ObjectGetDepthR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12acd8 b 0x12ad14 <_Z16F_ObjectGetDepthR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12acdc ldr r3, [r3, #0x4]
 *   @0x12ace0 cmp r3, #0
 *   @0x12ace4 beq 0x12ad14 <_Z16F_ObjectGetDepthR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12ace8 ldr r2, [r3, #0x8]
 *   @0x12acec cmp r0, r2
 *   @0x12acf0 bne 0x12acdc <_Z16F_ObjectGetDepthR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12acf4 ldr r3, [r3, #0xc]
 *   @0x12acf8 cmp r3, #0
 *   @0x12acfc beq 0x12ad14 <_Z16F_ObjectGetDepthR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12ad00 ldr r2, [r3, #0x8]
 *   @0x12ad04 vmov s15, r2
 *   @0x12ad08 vcvt.f64.s32 d7, s15
 *   @0x12ad0c vmov r2, r3, d7
 *   @0x12ad10 b 0x12ad20 <_Z16F_ObjectGetDepthR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12ad14 mov r3, #0
 *   @0x12ad18 movt r3, #0xbff0
 *   @0x12ad1c mov r2, #0
 *   @0x12ad20 mov r1, #0
 *   @0x12ad24 stm r4, {r2, r3}
 *   @0x12ad28 str r1, [r4, #0xc]
 *   @0x12ad2c pop {r4, pc}
 *   @0x12ad30 eoreq r2, r12, r4, lsl #31
 *
 * ══ §155/197 F_ObjectGetMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x12add0  size 148  37 条（0x12add0..0x12ae64）
 * @func 0x12add0 0x12ae64  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×2 / 0x4×2 / 0xc×2 / 0x74×1 / 0x3×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12add0 push {r4, lr}
 *   @0x12add4 mov r1, #0
 *   @0x12add8 mov r4, r0
 *   @0x12addc ldr r0, [sp, #0x8]
 *   @0x12ade0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ade4 ldr r3, [pc, #0x74]
 *   @0x12ade8 ldr r3, [pc, r3]
 *   @0x12adec ldr r3, [r3]
 *   @0x12adf0 ldr r2, [r3, #0x4]
 *   @0x12adf4 ldr r3, [r3]
 *   @0x12adf8 and r2, r0, r2
 *   @0x12adfc ldr r3, [r3, r2, lsl #3]
 *   @0x12ae00 cmp r3, #0
 *   @0x12ae04 bne 0x12ae18 <_Z15F_ObjectGetMaskR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12ae08 b 0x12ae44 <_Z15F_ObjectGetMaskR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12ae0c ldr r3, [r3, #0x4]
 *   @0x12ae10 cmp r3, #0
 *   @0x12ae14 beq 0x12ae44 <_Z15F_ObjectGetMaskR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12ae18 ldr r2, [r3, #0x8]
 *   @0x12ae1c cmp r0, r2
 *   @0x12ae20 bne 0x12ae0c <_Z15F_ObjectGetMaskR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12ae24 ldr r3, [r3, #0xc]
 *   @0x12ae28 cmp r3, #0
 *   @0x12ae2c beq 0x12ae44 <_Z15F_ObjectGetMaskR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12ae30 ldr r2, [r3, #0x10]
 *   @0x12ae34 vmov s15, r2
 *   @0x12ae38 vcvt.f64.s32 d7, s15
 *   @0x12ae3c vmov r2, r3, d7
 *   @0x12ae40 b 0x12ae50 <_Z15F_ObjectGetMaskR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12ae44 mov r3, #0
 *   @0x12ae48 movt r3, #0xbff0
 *   @0x12ae4c mov r2, #0
 *   @0x12ae50 mov r1, #0
 *   @0x12ae54 stm r4, {r2, r3}
 *   @0x12ae58 str r1, [r4, #0xc]
 *   @0x12ae5c pop {r4, pc}
 *   @0x12ae60 eoreq r2, r12, r4, asr lr
 *
 * ══ §156/197 F_ObjectGetParent(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ae64  size 148  37 条（0x12ae64..0x12aef8）
 * @func 0x12ae64 0x12aef8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×3 / 0x8×2 / 0x4×2 / 0x74×1 / 0x3×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ae64 push {r4, lr}
 *   @0x12ae68 mov r1, #0
 *   @0x12ae6c mov r4, r0
 *   @0x12ae70 ldr r0, [sp, #0x8]
 *   @0x12ae74 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ae78 ldr r3, [pc, #0x74]
 *   @0x12ae7c ldr r3, [pc, r3]
 *   @0x12ae80 ldr r3, [r3]
 *   @0x12ae84 ldr r2, [r3, #0x4]
 *   @0x12ae88 ldr r3, [r3]
 *   @0x12ae8c and r2, r0, r2
 *   @0x12ae90 ldr r3, [r3, r2, lsl #3]
 *   @0x12ae94 cmp r3, #0
 *   @0x12ae98 bne 0x12aeac <_Z17F_ObjectGetParentR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12ae9c b 0x12aed8 <_Z17F_ObjectGetParentR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12aea0 ldr r3, [r3, #0x4]
 *   @0x12aea4 cmp r3, #0
 *   @0x12aea8 beq 0x12aed8 <_Z17F_ObjectGetParentR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12aeac ldr r2, [r3, #0x8]
 *   @0x12aeb0 cmp r0, r2
 *   @0x12aeb4 bne 0x12aea0 <_Z17F_ObjectGetParentR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12aeb8 ldr r3, [r3, #0xc]
 *   @0x12aebc cmp r3, #0
 *   @0x12aec0 beq 0x12aed8 <_Z17F_ObjectGetParentR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12aec4 ldr r2, [r3, #0xc]
 *   @0x12aec8 vmov s15, r2
 *   @0x12aecc vcvt.f64.s32 d7, s15
 *   @0x12aed0 vmov r2, r3, d7
 *   @0x12aed4 b 0x12aee4 <_Z17F_ObjectGetParentR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12aed8 mov r3, #0
 *   @0x12aedc movt r3, #0xbff0
 *   @0x12aee0 mov r2, #0
 *   @0x12aee4 mov r1, #0
 *   @0x12aee8 stm r4, {r2, r3}
 *   @0x12aeec str r1, [r4, #0xc]
 *   @0x12aef0 pop {r4, pc}
 *   @0x12aef4 eoreq r2, r12, r0, asr #27
 *
 * ══ §157/197 F_SpriteGetSpeedType(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b264  size 148  37 条（0x12b264..0x12b2f8）
 * @func 0x12b264 0x12b2f8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sprite_Data(int)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x70×1 / 0x20×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b264 push {r3, r4, r5, r6, r7, lr}
 *   @0x12b268 mov r5, #0
 *   @0x12b26c ldr r6, [sp, #0x18]
 *   @0x12b270 mov r1, r5
 *   @0x12b274 str r5, [r0, #0xc]
 *   @0x12b278 mov r4, r0
 *   @0x12b27c str r5, [r0]
 *   @0x12b280 mov r3, r5
 *   @0x12b284 movt r3, #0xbff0
 *   @0x12b288 str r3, [r0, #0x4]
 *   @0x12b28c mov r0, r6
 *   @0x12b290 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b294 mov r1, r5
 *   @0x12b298 mov r7, r0
 *   @0x12b29c mov r0, r6
 *   @0x12b2a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b2a4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12b2a8 cmp r0, #0
 *   @0x12b2ac beq 0x12b2c8 <_Z20F_SpriteGetSpeedTypeR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x12b2b0 ldr r2, [r0, #0x70]
 *   @0x12b2b4 vmov s15, r2
 *   @0x12b2b8 vcvt.f64.s32 d7, s15
 *   @0x12b2bc vmov r2, r3, d7
 *   @0x12b2c0 stm r4, {r2, r3}
 *   @0x12b2c4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x12b2c8 ldr r3, [pc, #0x20]
 *   @0x12b2cc mov r2, r7
 *   @0x12b2d0 ldr r1, [pc, #0x1c]
 *   @0x12b2d4 ldr r3, [pc, r3]
 *   @0x12b2d8 add r1, pc, r1
 *   @0x12b2dc ldr r0, [r3]
 *   @0x12b2e0 ldr r3, [r0]
 *   @0x12b2e4 ldr r3, [r3, #0xc]
 *   @0x12b2e8 blx r3
 *   @0x12b2ec pop {r3, r4, r5, r6, r7, pc}
 *   @0x12b2f0 eoreq r2, r12, r0, asr #8
 *   @0x12b2f4 eoreq r2, r1, r8, asr #3
 *
 * ══ §158/197 F_SoundLoop(RValue&, CInstance*, CInstance*, int, RValue*)  0x13655c  size 148  37 条（0x13655c..0x1365f0）
 * @func 0x13655c 0x1365f0  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSound::GetSoundId()×2 / YYGetInt32(RValue const*, int) / Sound_Data(int) / SND_Play(char const*, int, bool)
 * 字段偏移 top8: 0x10×2 / 0x80×1 / 0x68×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13655c ldr r3, [pc, #0x80]
 *   @0x136560 push {r4, r5, r6, lr}
 *   @0x136564 ldr r3, [pc, r3]
 *   @0x136568 ldr r0, [sp, #0x10]
 *   @0x13656c ldrb r3, [r3]
 *   @0x136570 cmp r3, #0
 *   @0x136574 popne {r4, r5, r6, pc}
 *   @0x136578 ldr r3, [pc, #0x68]
 *   @0x13657c ldr r3, [pc, r3]
 *   @0x136580 ldrb r1, [r3]
 *   @0x136584 cmp r1, #0
 *   @0x136588 popne {r4, r5, r6, pc}
 *   @0x13658c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x136590 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x136594 subs r4, r0, #0
 *   @0x136598 beq 0x1365d0 <_Z11F_SoundLoopR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x13659c ldr r5, [r4, #0xc]
 *   @0x1365a0 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x1365a4 mov r2, #1
 *   @0x1365a8 mov r1, r0
 *   @0x1365ac mov r0, r5
 *   @0x1365b0 bl 0x21eb7c <_Z8SND_PlayPKcib>
 *   @0x1365b4 mov r0, r4
 *   @0x1365b8 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x1365bc ldrd r2, r3, [r4, #32]
 *   @0x1365c0 mov r1, #1
 *   @0x1365c4 str r1, [sp, #0x10]
 *   @0x1365c8 pop {r4, r5, r6, lr}
 *   @0x1365cc b 0x21f07c <_Z14SND_Set_Volumeidi>
 *   @0x1365d0 ldr r0, [pc, #0x14]
 *   @0x1365d4 mov r1, r4
 *   @0x1365d8 pop {r4, r5, r6, lr}
 *   @0x1365dc add r0, pc, r0
 *   @0x1365e0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1365e4 eoreq r8, r11, r12, asr #15
 *   @0x1365e8 .word 0x002b8ad0
 *   @0x1365ec .word 0x00208eb0
 *
 * ══ §159/197 F_FileTextEof(RValue&, CInstance*, CInstance*, int, RValue*)  0x137d08  size 148  37 条（0x137d08..0x137d9c）
 * @func 0x137d08 0x137d9c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / LoadSave::yyfeof(_YYFILE*)
 * 字段偏移 top8: 0x10×1 / 0x60×1 / 0x2×1 / 0x50×1 / 0x40×1 / 0xc×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x137d08 push {r3, r4, r5, lr}
 *   @0x137d0c mov r1, #0
 *   @0x137d10 mov r4, r0
 *   @0x137d14 ldr r0, [sp, #0x10]
 *   @0x137d18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x137d1c sub r3, r0, #1
 *   @0x137d20 cmp r3, #30
 *   @0x137d24 bhi 0x137d3c <_Z13F_FileTextEofR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x137d28 ldr r3, [pc, #0x60]
 *   @0x137d2c ldr r3, [pc, r3]
 *   @0x137d30 ldr r3, [r3, r0, lsl #2]
 *   @0x137d34 cmp r3, #1
 *   @0x137d38 beq 0x137d50 <_Z13F_FileTextEofR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x137d3c ldr r0, [pc, #0x50]
 *   @0x137d40 mov r1, #0
 *   @0x137d44 pop {r3, r4, r5, lr}
 *   @0x137d48 add r0, pc, r0
 *   @0x137d4c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x137d50 ldr r3, [pc, #0x40]
 *   @0x137d54 add r0, r0, r0, lsl #1
 *   @0x137d58 mov r5, #0
 *   @0x137d5c str r5, [r4, #0xc]
 *   @0x137d60 ldr r3, [pc, r3]
 *   @0x137d64 add r3, r3, r0, lsl #2
 *   @0x137d68 ldr r0, [r3, #0x8]
 *   @0x137d6c bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE>
 *   @0x137d70 cmp r0, #0
 *   @0x137d74 moveq r5, r0
 *   @0x137d78 movne r3, r5
 *   @0x137d7c moveq r3, r5
 *   @0x137d80 movtne r3, #0x3ff0
 *   @0x137d84 str r5, [r4]
 *   @0x137d88 str r3, [r4, #0x4]
 *   @0x137d8c pop {r3, r4, r5, pc}
 *   @0x137d90 eoreq r7, r11, r4, asr #10
 *   @0x137d94 eoreq r8, r0, r8, ror #5
 *   @0x137d98 eoreq r7, r11, r4, lsl r5
 *
 * ══ §160/197 F_FileTextEoln(RValue&, CInstance*, CInstance*, int, RValue*)  0x137d9c  size 148  37 条（0x137d9c..0x137e30）
 * @func 0x137d9c 0x137e30  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / LoadSave::yyfeoln(_YYFILE*)
 * 字段偏移 top8: 0x10×1 / 0x60×1 / 0x2×1 / 0x50×1 / 0x40×1 / 0xc×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x137d9c push {r3, r4, r5, lr}
 *   @0x137da0 mov r1, #0
 *   @0x137da4 mov r4, r0
 *   @0x137da8 ldr r0, [sp, #0x10]
 *   @0x137dac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x137db0 sub r3, r0, #1
 *   @0x137db4 cmp r3, #30
 *   @0x137db8 bhi 0x137dd0 <_Z14F_FileTextEolnR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x137dbc ldr r3, [pc, #0x60]
 *   @0x137dc0 ldr r3, [pc, r3]
 *   @0x137dc4 ldr r3, [r3, r0, lsl #2]
 *   @0x137dc8 cmp r3, #1
 *   @0x137dcc beq 0x137de4 <_Z14F_FileTextEolnR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x137dd0 ldr r0, [pc, #0x50]
 *   @0x137dd4 mov r1, #0
 *   @0x137dd8 pop {r3, r4, r5, lr}
 *   @0x137ddc add r0, pc, r0
 *   @0x137de0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x137de4 ldr r3, [pc, #0x40]
 *   @0x137de8 add r0, r0, r0, lsl #1
 *   @0x137dec mov r5, #0
 *   @0x137df0 str r5, [r4, #0xc]
 *   @0x137df4 ldr r3, [pc, r3]
 *   @0x137df8 add r3, r3, r0, lsl #2
 *   @0x137dfc ldr r0, [r3, #0x8]
 *   @0x137e00 bl 0x18de98 <_ZN8LoadSave7yyfeolnEP7_YYFILE>
 *   @0x137e04 cmp r0, #0
 *   @0x137e08 moveq r5, r0
 *   @0x137e0c movne r3, r5
 *   @0x137e10 moveq r3, r5
 *   @0x137e14 movtne r3, #0x3ff0
 *   @0x137e18 str r5, [r4]
 *   @0x137e1c str r3, [r4, #0x4]
 *   @0x137e20 pop {r3, r4, r5, pc}
 *   @0x137e24 .word 0x002b74b0
 *   @0x137e28 eoreq r8, r0, r4, asr r2
 *   @0x137e2c eoreq r7, r11, r0, lsl #9
 *
 * ══ §161/197 F_ActionReplaceSound(RValue&, CInstance*, CInstance*, int, RValue*)  0x141148  size 148  37 条（0x141148..0x1411dc）
 * @func 0x141148 0x1411dc  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int) / Sound_Exists(int) / FileExists(char const*) / Sound_Data(int)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0x14×1 / 0x18×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141148 push {r4, r5, r6, lr}
 *   @0x14114c mov r1, #0
 *   @0x141150 ldr r4, [sp, #0x10]
 *   @0x141154 mov r0, r4
 *   @0x141158 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14115c mov r1, #1
 *   @0x141160 mov r5, r0
 *   @0x141164 mov r0, r4
 *   @0x141168 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x14116c mov r4, r0
 *   @0x141170 mov r0, r5
 *   @0x141174 bl 0x21fbd0 <_Z12Sound_Existsi>
 *   @0x141178 subs r1, r0, #0
 *   @0x14117c beq 0x1411c4 <_Z20F_ActionReplaceSoundR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x141180 mov r0, r4
 *   @0x141184 bl 0x214e48 <_Z10FileExistsPKc>
 *   @0x141188 subs r1, r0, #0
 *   @0x14118c beq 0x1411b4 <_Z20F_ActionReplaceSoundR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x141190 mov r0, r5
 *   @0x141194 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x141198 mov r1, r4
 *   @0x14119c mov r3, r0
 *   @0x1411a0 mov r0, r5
 *   @0x1411a4 ldr r2, [r3, #0x4]
 *   @0x1411a8 pop {r4, r5, r6, lr}
 *   @0x1411ac ldrb r3, [r3, #0x14]
 *   @0x1411b0 b 0x220018 <_Z13Sound_ReplaceiPKcib>
 *   @0x1411b4 ldr r0, [pc, #0x18]
 *   @0x1411b8 pop {r4, r5, r6, lr}
 *   @0x1411bc add r0, pc, r0
 *   @0x1411c0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1411c4 ldr r0, [pc, #0xc]
 *   @0x1411c8 pop {r4, r5, r6, lr}
 *   @0x1411cc add r0, pc, r0
 *   @0x1411d0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1411d4 ldrheq pc, [pc], -r4
 *   @0x1411d8 andseq pc, pc, r8, ror r7
 *
 * ══ §162/197 F_GPUGetBlendModeExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x148020  size 148  37 条（0x148020..0x1480b4）
 * @func 0x148020 0x1480b4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)×2 / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0xc×1 / 0x5c×1 / 0x10×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148020 cmp r3, #0
 *   @0x148024 mov r3, #0
 *   @0x148028 push {r4, r5, r6, lr}
 *   @0x14802c mov r1, r3
 *   @0x148030 sub sp, sp, #8
 *   @0x148034 movt r3, #0xbff0
 *   @0x148038 mov r4, r0
 *   @0x14803c str r1, [r0, #0xc]
 *   @0x148040 stm r0, {r1, r3}
 *   @0x148044 bne 0x148098 <_Z20F_GPUGetBlendModeExtR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x148048 ldr r5, [pc, #0x5c]
 *   @0x14804c mov r1, #6
 *   @0x148050 ldr r5, [pc, r5]
 *   @0x148054 mov r0, r5
 *   @0x148058 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x14805c mov r1, #7
 *   @0x148060 mov r6, r0
 *   @0x148064 mov r0, r5
 *   @0x148068 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x14806c vmov s15, r6
 *   @0x148070 mov r1, #2
 *   @0x148074 vcvt.f64.u32 d7, s15
 *   @0x148078 vmov r2, r3, d7
 *   @0x14807c vmov s13, r0
 *   @0x148080 mov r0, r4
 *   @0x148084 vcvt.f64.u32 d7, s13
 *   @0x148088 vstr d7, [sp]
 *   @0x14808c bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x148090 add sp, sp, #8
 *   @0x148094 pop {r4, r5, r6, pc}
 *   @0x148098 ldr r0, [pc, #0x10]
 *   @0x14809c add r0, pc, r0
 *   @0x1480a0 add sp, sp, #8
 *   @0x1480a4 pop {r4, r5, r6, lr}
 *   @0x1480a8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1480ac eoreq r5, r10, r8, lsr #25
 *   @0x1480b0 andseq r9, pc, r12, asr pc
 *
 * ══ §163/197 F_PhysicsFixtureSetCircleShape(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c250  size 148  37 条（0x14c250..0x14c2e4）
 * @func 0x14c250 0x14c2e4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0x60×1 / 0xb4×1 / 0x24×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c250 push {r4, r5, r6, lr}
 *   @0x14c254 mov r1, #0
 *   @0x14c258 ldr r5, [sp, #0x10]
 *   @0x14c25c mov r0, r5
 *   @0x14c260 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c264 bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14c268 subs r6, r0, #0
 *   @0x14c26c beq 0x14c2c4 <_Z30F_PhysicsFixtureSetCircleShapeR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x14c270 ldr r3, [pc, #0x60]
 *   @0x14c274 ldr r3, [pc, r3]
 *   @0x14c278 ldr r3, [r3]
 *   @0x14c27c ldr r4, [r3, #0xb4]
 *   @0x14c280 cmp r4, #0
 *   @0x14c284 beq 0x14c2b0 <_Z30F_PhysicsFixtureSetCircleShapeR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x14c288 mov r0, r5
 *   @0x14c28c mov r1, #1
 *   @0x14c290 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c294 vldr s15, [r4, #96]
 *   @0x14c298 vmov s14, r0
 *   @0x14c29c mov r0, r6
 *   @0x14c2a0 pop {r4, r5, r6, lr}
 *   @0x14c2a4 vmul.f32 s15, s14, s15
 *   @0x14c2a8 vmov r1, s15
 *   @0x14c2ac b 0x236788 <_ZN15CPhysicsFixture14SetCircleShapeEf>
 *   @0x14c2b0 ldr r0, [pc, #0x24]
 *   @0x14c2b4 mov r1, r4
 *   @0x14c2b8 pop {r4, r5, r6, lr}
 *   @0x14c2bc add r0, pc, r0
 *   @0x14c2c0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c2c4 ldr r0, [pc, #0x14]
 *   @0x14c2c8 mov r1, r6
 *   @0x14c2cc pop {r4, r5, r6, lr}
 *   @0x14c2d0 add r0, pc, r0
 *   @0x14c2d4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c2d8 .word 0x002a16b4
 *   @0x14c2dc andseq r7, pc, r8, ror #22
 *   @0x14c2e0 ldrsbeq r7, [pc], -r8
 *
 * ══ §164/197 F_YoYo_Base64Decode(RValue&, CInstance*, CInstance*, int, RValue*)  0x157a94  size 148  37 条（0x157a94..0x157b28）
 * @func 0x157a94 0x157b28  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / 0xb6538 / base64_decode(char const*, unsigned int, char*, bool) / YYCreateString(RValue*, char const*) / 0xb65d4
 * 字段偏移 top8: 0x-18×2 / 0x80×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157a94 push {r4, r5, r6, r11, lr}
 *   @0x157a98 add r11, sp, #16
 *   @0x157a9c ldr r4, [pc, #0x80]
 *   @0x157aa0 sub sp, sp, #12
 *   @0x157aa4 mov r1, #0
 *   @0x157aa8 ldr r4, [pc, r4]
 *   @0x157aac mov r6, r0
 *   @0x157ab0 ldr r0, [r11, #0x4]
 *   @0x157ab4 ldr r3, [r4]
 *   @0x157ab8 str r3, [r11, #-0x18]
 *   @0x157abc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157ac0 mov r5, r0
 *   @0x157ac4 bl 0xb6538 <strlen@plt>
 *   @0x157ac8 mov r3, #1
 *   @0x157acc add r2, r0, r0, lsl #1
 *   @0x157ad0 mov r0, r5
 *   @0x157ad4 cmp r2, #0
 *   @0x157ad8 add r1, r2, #3
 *   @0x157adc movlt r2, r1
 *   @0x157ae0 asr r1, r2, #2
 *   @0x157ae4 add r2, r1, #18
 *   @0x157ae8 add r1, r1, #4
 *   @0x157aec bic r2, r2, #7
 *   @0x157af0 sub sp, sp, r2
 *   @0x157af4 mov r2, sp
 *   @0x157af8 bl 0x1d1ff0 <_Z13base64_decodePKcjPcb>
 *   @0x157afc mov r0, r6
 *   @0x157b00 mov r1, sp
 *   @0x157b04 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x157b08 ldr r2, [r11, #-0x18]
 *   @0x157b0c ldr r3, [r4]
 *   @0x157b10 cmp r2, r3
 *   @0x157b14 bne 0x157b20 <_Z19F_YoYo_Base64DecodeR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x157b18 sub sp, r11, #16
 *   @0x157b1c pop {r4, r5, r6, r11, pc}
 *   @0x157b20 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x157b24 eoreq r5, r9, r8, lsr #29
 *
 * ══ §165/197 F_AppSurfaceEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x1583ac  size 148  37 条（0x1583ac..0x158440）
 * @func 0x1583ac 0x158440  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1583b0→0x3f50f1, 0x1583d0→0x3f510c, 0x1583d4→0x3f5104, 0x1583d8→0x3f5108, 0x1583e4→0x3f5100
 * 调用序列: YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x58×3 / 0x74×2 / 0x8×1 / 0x50×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1583ac ldr r3, [pc, #0x74]
 *   @0x1583b0 ldr r2, [pc, #0x74]
 *   @0x1583b4 add r3, pc, r3
 *   @0x1583b8 push {r4, lr}
 *   @0x1583bc ldr r4, [r3, r2]
 *   @0x1583c0 ldr r0, [sp, #0x8]
 *   @0x1583c4 ldrb r2, [r4]
 *   @0x1583c8 cmp r2, #0
 *   @0x1583cc beq 0x158400 <_Z18F_AppSurfaceEnableR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1583d0 ldr r12, [pc, #0x58]
 *   @0x1583d4 ldr r1, [pc, #0x58]
 *   @0x1583d8 ldr r2, [pc, #0x58]
 *   @0x1583dc ldr lr, [r3, r12]
 *   @0x1583e0 ldr r12, [r3, r1]
 *   @0x1583e4 ldr r1, [pc, #0x50]
 *   @0x1583e8 ldr lr, [lr]
 *   @0x1583ec str lr, [r12]
 *   @0x1583f0 ldr r2, [r3, r2]
 *   @0x1583f4 ldr r3, [r3, r1]
 *   @0x1583f8 ldr r2, [r2]
 *   @0x1583fc str r2, [r3]
 *   @0x158400 mov r1, #0
 *   @0x158404 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x158408 vmov.f64 d7, #5.000000e-01
 *   @0x15840c vmov d6, r0, r1
 *   @0x158410 vcmpe.f64 d6, d7
 *   @0x158414 vmrs APSR_nzcv, fpscr
 *   @0x158418 movle r3, #0
 *   @0x15841c movgt r3, #1
 *   @0x158420 strb r3, [r4]
 *   @0x158424 pop {r4, pc}
 *   @0x158428 mlaeq r9, r12, r8, r9
 *   @0x15842c .word 0xffffdef8
 *   @0x158430 .word 0xffffdf38
 *   @0x158434 .word 0xffffdf3c
 *   @0x158438 .word 0xffffdf40
 *   @0x15843c .word 0xffffdf44
 *
 * ══ §166/197 GR_3DM_Vertex_Texture_Color(int, float, float, float, float, float, unsigned int, float)  0x1655e0  size 148  37 条（0x1655e0..0x165674）
 * @func 0x1655e0 0x165674  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Vertex_Texture_Color(int, float, float, float, float, float, unsigned int, float)+0x84 / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x70×1 / 0x60×1 / 0x4×1 / 0x2×1 / 0x30×1 / 0x14×1 / 0x18×1 / 0x1c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1655e0 cmp r0, #0
 *   @0x1655e4 push {r4, lr}
 *   @0x1655e8 mov r4, r2
 *   @0x1655ec sub sp, sp, #32
 *   @0x1655f0 blt 0x165664 <_Z27GR_3DM_Vertex_Texture_Colorifffffjf+0x84>
 *   @0x1655f4 ldr r12, [pc, #0x70]
 *   @0x1655f8 ldr r12, [pc, r12]
 *   @0x1655fc ldr r12, [r12]
 *   @0x165600 cmp r0, r12
 *   @0x165604 bge 0x165664 <_Z27GR_3DM_Vertex_Texture_Colorifffffjf+0x84>
 *   @0x165608 ldr r12, [pc, #0x60]
 *   @0x16560c ldr r12, [pc, r12]
 *   @0x165610 ldr r2, [r12, #0x4]
 *   @0x165614 ldr r0, [r2, r0, lsl #2]
 *   @0x165618 cmp r0, #0
 *   @0x16561c beq 0x165664 <_Z27GR_3DM_Vertex_Texture_Colorifffffjf+0x84>
 *   @0x165620 ldr r12, [sp, #0x30]
 *   @0x165624 vldr s15, [sp, #40]
 *   @0x165628 str r3, [sp]
 *   @0x16562c vstr s15, [sp, #4]
 *   @0x165630 mov r2, r1
 *   @0x165634 vldr s15, [sp, #44]
 *   @0x165638 mov r1, #0
 *   @0x16563c vstr s15, [sp, #8]
 *   @0x165640 str r1, [sp, #0x14]
 *   @0x165644 vldr s15, [sp, #52]
 *   @0x165648 str r1, [sp, #0x18]
 *   @0x16564c vstr s15, [sp, #16]
 *   @0x165650 str r1, [sp, #0x1c]
 *   @0x165654 mov r3, r4
 *   @0x165658 str r12, [sp, #0xc]
 *   @0x16565c mov r1, #5
 *   @0x165660 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x165664 add sp, sp, #32
 *   @0x165668 pop {r4, pc}
 *   @0x16566c .word 0x0028aaf8
 *   @0x165670 eoreq r10, r8, r8, ror #21
 *
 * ══ §167/197 GR_D3D_Set_Texture_Repeat_Ext(int, bool)  0x168934  size 148  37 条（0x168934..0x1689c8）
 * @func 0x168934 0x1689c8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16894c→0x489794, 0x168954→0x4859c8
 * 调用序列: RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)×2
 * 字段偏移 top8: 0x74×1 / 0x6c×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168934 push {r4, r5, r6, lr}
 *   @0x168938 cmp r0, #7
 *   @0x16893c mov r4, r0
 *   @0x168940 ldr r0, [pc, #0x74]
 *   @0x168944 add r0, pc, r0
 *   @0x168948 pophi {r4, r5, r6, pc}
 *   @0x16894c ldr r3, [pc, #0x6c]
 *   @0x168950 cmp r1, #0
 *   @0x168954 ldr r12, [pc, #0x68]
 *   @0x168958 mov r2, #2
 *   @0x16895c ldr r3, [r0, r3]
 *   @0x168960 strb r1, [r3, r4]
 *   @0x168964 mov r1, r4
 *   @0x168968 bne 0x168994 <_Z29GR_D3D_Set_Texture_Repeat_Extib+0x60>
 *   @0x16896c ldr r5, [r0, r12]
 *   @0x168970 mov r3, #1
 *   @0x168974 mov r0, r5
 *   @0x168978 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x16897c mov r0, r5
 *   @0x168980 mov r1, r4
 *   @0x168984 mov r2, #3
 *   @0x168988 mov r3, #1
 *   @0x16898c pop {r4, r5, r6, lr}
 *   @0x168990 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x168994 ldr r5, [r0, r12]
 *   @0x168998 mov r3, #0
 *   @0x16899c mov r0, r5
 *   @0x1689a0 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x1689a4 mov r0, r5
 *   @0x1689a8 mov r1, r4
 *   @0x1689ac mov r2, #3
 *   @0x1689b0 mov r3, #0
 *   @0x1689b4 pop {r4, r5, r6, lr}
 *   @0x1689b8 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x1689bc eoreq r9, r8, r12, lsl #6
 *   @0x1689c0 .word 0xffffe4bc
 *   @0x1689c4 .word 0xffffc0a8
 *
 * ══ §168/197 F_CameraDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x1707f4  size 148  37 条（0x1707f4..0x170888）
 * @func 0x1707f4 0x170888  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCameraManager::GetActiveCamera() / CCamera::GetID() / CCameraManager::SetActiveCamera(int)
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x60×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1707f4 cmp r3, #1
 *   @0x1707f8 push {r3, r4, r5, lr}
 *   @0x1707fc mov r3, #0
 *   @0x170800 mov r1, r3
 *   @0x170804 movt r3, #0xbff0
 *   @0x170808 str r1, [r0, #0xc]
 *   @0x17080c stm r0, {r1, r3}
 *   @0x170810 ldr r0, [sp, #0x10]
 *   @0x170814 beq 0x170828 <_Z15F_CameraDestroyR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x170818 ldr r0, [pc, #0x60]
 *   @0x17081c pop {r3, r4, r5, lr}
 *   @0x170820 add r0, pc, r0
 *   @0x170824 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x170828 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x17082c ldr r4, [pc, #0x50]
 *   @0x170830 ldr r4, [pc, r4]
 *   @0x170834 mov r1, r0
 *   @0x170838 mov r0, r4
 *   @0x17083c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x170840 subs r5, r0, #0
 *   @0x170844 popeq {r3, r4, r5, pc}
 *   @0x170848 mov r0, r4
 *   @0x17084c bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv>
 *   @0x170850 cmp r5, r0
 *   @0x170854 beq 0x170870 <_Z15F_CameraDestroyR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x170858 mov r0, r5
 *   @0x17085c bl 0x16d12c <_ZN7CCamera5GetIDEv>
 *   @0x170860 mov r1, r0
 *   @0x170864 mov r0, r4
 *   @0x170868 pop {r3, r4, r5, lr}
 *   @0x17086c b 0x16f2cc <_ZN14CCameraManager13DestroyCameraEi>
 *   @0x170870 mov r0, r4
 *   @0x170874 mvn r1, #0
 *   @0x170878 bl 0x1707c8 <_ZN14CCameraManager15SetActiveCameraEi>
 *   @0x17087c b 0x170858 <_Z15F_CameraDestroyR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x170880 andseq r10, sp, r4, asr r11
 *   @0x170884 eoreq sp, r7, r4, asr #8
 *
 * ══ §169/197 GR_Texture_Create_From_File(unsigned char*, unsigned int)  0x173b20  size 148  37 条（0x173b20..0x173bb4）
 * @func 0x173b20 0x173bb4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AllocTexture() / Graphics::CreateTextureFromFile(unsigned char*, unsigned int, ImageInfo*, eTextureFormat, bool)
 * 字段偏移 top8: 0x10×2 / 0x4×2 / 0x40×1 / 0x2×1 / 0x6×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173b20 push {r4, r5, r6, lr}
 *   @0x173b24 sub sp, sp, #40
 *   @0x173b28 mov r5, r0
 *   @0x173b2c mov r6, r1
 *   @0x173b30 bl 0x173944 <_Z12AllocTexturev>
 *   @0x173b34 mov r1, r6
 *   @0x173b38 add r2, sp, #12
 *   @0x173b3c mov r3, #0
 *   @0x173b40 str r3, [sp]
 *   @0x173b44 mov r3, #6
 *   @0x173b48 mov r4, r0
 *   @0x173b4c mov r0, r5
 *   @0x173b50 bl 0x182f3c <_ZN8Graphics21CreateTextureFromFileEPhjP9ImageInfo14eTextureFormatb>
 *   @0x173b54 ldr r2, [sp, #0x10]
 *   @0x173b58 vmov.f32 s15, #1.000000e+00
 *   @0x173b5c vldr s12, [sp, #12]
 *   @0x173b60 vmov r12, s12
 *   @0x173b64 mov r1, #1
 *   @0x173b68 ldr r3, [pc, #0x40]
 *   @0x173b6c ldr r3, [pc, r3]
 *   @0x173b70 ldr r3, [r3, #0x4]
 *   @0x173b74 ldr r3, [r3, r4, lsl #2]
 *   @0x173b78 vcvt.f32.u32 s14, s12
 *   @0x173b7c vmov s12, r2
 *   @0x173b80 strh r2, [r3, #6]
 *   @0x173b84 strb r1, [r3, #0x10]
 *   @0x173b88 vcvt.f32.u32 s13, s12
 *   @0x173b8c strh r12, [r3, #4]
 *   @0x173b90 vdiv.f32 s14, s15, s14
 *   @0x173b94 str r0, [r3]
 *   @0x173b98 mov r0, r4
 *   @0x173b9c vdiv.f32 s15, s15, s13
 *   @0x173ba0 vstr s14, [r3, #8]
 *   @0x173ba4 vstr s15, [r3, #12]
 *   @0x173ba8 add sp, sp, #40
 *   @0x173bac pop {r4, r5, r6, pc}
 *   @0x173bb0 .word 0x00279db0
 *
 * ══ §170/197 GR_Texture_Create(unsigned char*, unsigned int, bool, bool)  0x173cdc  size 148  37 条（0x173cdc..0x173d70）
 * @func 0x173cdc 0x173d70  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AllocTexture() / Graphics::CreateTextureFromFile(unsigned char*, unsigned int, ImageInfo*, eTextureFormat, bool)
 * 字段偏移 top8: 0x10×2 / 0x4×2 / 0x40×1 / 0x2×1 / 0x6×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173cdc push {r4, r5, r6, r7, lr}
 *   @0x173ce0 sub sp, sp, #44
 *   @0x173ce4 mov r7, r3
 *   @0x173ce8 mov r5, r0
 *   @0x173cec mov r6, r1
 *   @0x173cf0 bl 0x173944 <_Z12AllocTexturev>
 *   @0x173cf4 mov r1, r6
 *   @0x173cf8 add r2, sp, #12
 *   @0x173cfc str r7, [sp]
 *   @0x173d00 mov r3, #6
 *   @0x173d04 mov r4, r0
 *   @0x173d08 mov r0, r5
 *   @0x173d0c bl 0x182f3c <_ZN8Graphics21CreateTextureFromFileEPhjP9ImageInfo14eTextureFormatb>
 *   @0x173d10 ldr r2, [sp, #0x10]
 *   @0x173d14 vmov.f32 s15, #1.000000e+00
 *   @0x173d18 vldr s12, [sp, #12]
 *   @0x173d1c vmov r12, s12
 *   @0x173d20 mov r1, #1
 *   @0x173d24 ldr r3, [pc, #0x40]
 *   @0x173d28 ldr r3, [pc, r3]
 *   @0x173d2c ldr r3, [r3, #0x4]
 *   @0x173d30 ldr r3, [r3, r4, lsl #2]
 *   @0x173d34 vcvt.f32.u32 s14, s12
 *   @0x173d38 vmov s12, r2
 *   @0x173d3c strh r2, [r3, #6]
 *   @0x173d40 strb r1, [r3, #0x10]
 *   @0x173d44 vcvt.f32.u32 s13, s12
 *   @0x173d48 strh r12, [r3, #4]
 *   @0x173d4c vdiv.f32 s14, s15, s14
 *   @0x173d50 str r0, [r3]
 *   @0x173d54 mov r0, r4
 *   @0x173d58 vdiv.f32 s15, s15, s13
 *   @0x173d5c vstr s14, [r3, #8]
 *   @0x173d60 vstr s15, [r3, #12]
 *   @0x173d64 add sp, sp, #44
 *   @0x173d68 pop {r4, r5, r6, r7, pc}
 *   @0x173d6c .word 0x00279bf4
 *
 * ══ §171/197 GR_D3D_Lights_Resume()  0x17fb70  size 148  37 条（0x17fb70..0x17fc04）
 * @func 0x17fb70 0x17fc04  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17fb78→0x3f26dc, 0x17fb90→0x4a22d0, 0x17fbb8→0x479c74, 0x17fbbc→0x3f2770
 * 调用序列: GR_3D_Light_Update(int)
 * 字段偏移 top8: 0x74×2 / 0x3c×2 / 0x60×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17fb70 push {r3, r4, r5, r6, r7, lr}
 *   @0x17fb74 ldr r5, [pc, #0x74]
 *   @0x17fb78 ldr r3, [pc, #0x74]
 *   @0x17fb7c add r5, pc, r5
 *   @0x17fb80 ldr r3, [r5, r3]
 *   @0x17fb84 ldr r4, [r3]
 *   @0x17fb88 cmp r4, #0
 *   @0x17fb8c popne {r3, r4, r5, r6, r7, pc}
 *   @0x17fb90 ldr r3, [pc, #0x60]
 *   @0x17fb94 mov r7, #1
 *   @0x17fb98 ldr r6, [r5, r3]
 *   @0x17fb9c b 0x17fbac <_Z20GR_D3D_Lights_Resumev+0x3c>
 *   @0x17fba0 add r4, r4, #1
 *   @0x17fba4 cmp r4, #8
 *   @0x17fba8 beq 0x17fbe8 <_Z20GR_D3D_Lights_Resumev+0x78>
 *   @0x17fbac ldr r3, [r6]
 *   @0x17fbb0 ands r3, r3, r7, lsl r4
 *   @0x17fbb4 beq 0x17fba0 <_Z20GR_D3D_Lights_Resumev+0x30>
 *   @0x17fbb8 ldr r3, [pc, #0x3c]
 *   @0x17fbbc ldr r2, [pc, #0x3c]
 *   @0x17fbc0 ldr r3, [r5, r3]
 *   @0x17fbc4 ldr r2, [r5, r2]
 *   @0x17fbc8 ldr r3, [r3]
 *   @0x17fbcc ldr r0, [r2, r4, lsl #2]
 *   @0x17fbd0 blx r3
 *   @0x17fbd4 mov r0, r4
 *   @0x17fbd8 add r4, r4, #1
 *   @0x17fbdc bl 0x17f4c4 <_Z18GR_3D_Light_Updatei>
 *   @0x17fbe0 cmp r4, #8
 *   @0x17fbe4 bne 0x17fbac <_Z20GR_D3D_Lights_Resumev+0x3c>
 *   @0x17fbe8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x17fbec b 0x17f47c <_Z23GR_3D_Light_Set_Ambientv>
 *   @0x17fbf0 .word 0x002720d4
 *   @0x17fbf4 .word 0xffffe7b8
 *   @0x17fbf8 .word 0xffffe85c
 *   @0x17fbfc .word 0xffffbad8
 *   @0x17fc00 .word 0xffffe848
 *
 * ══ §172/197 LoadSave::yyfeoln(_YYFILE*)  0x18de98  size 148  37 条（0x18de98..0x18df2c）
 * @func 0x18de98 0x18df2c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / LoadSave::yyfeof(_YYFILE*)
 * 字段偏移 top8: 0x1c×2 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18de98 push {r4, r5, r6, lr}
 *   @0x18de9c mov r5, r0
 *   @0x18dea0 bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE>
 *   @0x18dea4 subs r4, r0, #0
 *   @0x18dea8 beq 0x18deb4 <_ZN8LoadSave7yyfeolnEP7_YYFILE+0x1c>
 *   @0x18deac mov r0, #1
 *   @0x18deb0 pop {r4, r5, r6, pc}
 *   @0x18deb4 ldr r0, [r5]
 *   @0x18deb8 mov r2, #1
 *   @0x18debc add r6, r0, #44
 *   @0x18dec0 ldr r12, [r0]
 *   @0x18dec4 ldr r1, [r0, #0x1c]
 *   @0x18dec8 mov r3, r6
 *   @0x18decc ldr r12, [r12, #0x14]
 *   @0x18ded0 blx r12
 *   @0x18ded4 mov r0, r6
 *   @0x18ded8 mov r1, r4
 *   @0x18dedc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18dee0 uxtb r0, r0
 *   @0x18dee4 cmp r0, #13
 *   @0x18dee8 beq 0x18deac <_ZN8LoadSave7yyfeolnEP7_YYFILE+0x14>
 *   @0x18deec ldr r0, [r5]
 *   @0x18def0 mov r2, #1
 *   @0x18def4 add r5, r0, #44
 *   @0x18def8 ldr r12, [r0]
 *   @0x18defc mov r3, r5
 *   @0x18df00 ldr r1, [r0, #0x1c]
 *   @0x18df04 ldr r12, [r12, #0x14]
 *   @0x18df08 blx r12
 *   @0x18df0c mov r0, r5
 *   @0x18df10 mov r1, r4
 *   @0x18df14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18df18 uxtb r0, r0
 *   @0x18df1c subs r3, r0, #10
 *   @0x18df20 rsbs r0, r3, #0
 *   @0x18df24 adcs r0, r0, r3
 *   @0x18df28 pop {r4, r5, r6, pc}
 *
 * ══ §173/197 Hash<CInstance>::~Hash()  0x190d2c  size 148  37 条（0x190d2c..0x190dc0）
 * @func 0x190d2c 0x190dc0  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / Hash<CInstance>::~Hash()+0x88
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190d2c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x190d30 mov r6, r0
 *   @0x190d34 ldm r0, {r0, r8}
 *   @0x190d38 cmp r8, #0
 *   @0x190d3c lslge r7, r8, #3
 *   @0x190d40 movge r9, #0
 *   @0x190d44 blt 0x190db4 <_ZN4HashI9CInstanceED2Ev+0x88>
 *   @0x190d48 ldr r4, [r0, r7]
 *   @0x190d4c add r3, r0, r7
 *   @0x190d50 str r9, [r0, r7]
 *   @0x190d54 cmp r4, #0
 *   @0x190d58 str r9, [r3, #0x4]
 *   @0x190d5c beq 0x190da4 <_ZN4HashI9CInstanceED2Ev+0x78>
 *   @0x190d60 ldr r3, [r4, #0xc]
 *   @0x190d64 ldr r5, [r4, #0x4]
 *   @0x190d68 cmp r3, #0
 *   @0x190d6c mov r0, r3
 *   @0x190d70 beq 0x190d80 <_ZN4HashI9CInstanceED2Ev+0x54>
 *   @0x190d74 ldr r3, [r3]
 *   @0x190d78 ldr r3, [r3, #0x4]
 *   @0x190d7c blx r3
 *   @0x190d80 mov r0, r4
 *   @0x190d84 mov r4, r5
 *   @0x190d88 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x190d8c ldr r3, [r6, #0x8]
 *   @0x190d90 cmp r5, #0
 *   @0x190d94 sub r3, r3, #1
 *   @0x190d98 str r3, [r6, #0x8]
 *   @0x190d9c bne 0x190d60 <_ZN4HashI9CInstanceED2Ev+0x34>
 *   @0x190da0 ldr r0, [r6]
 *   @0x190da4 sub r8, r8, #1
 *   @0x190da8 sub r7, r7, #8
 *   @0x190dac cmn r8, #1
 *   @0x190db0 bne 0x190d48 <_ZN4HashI9CInstanceED2Ev+0x1c>
 *   @0x190db4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x190db8 mov r0, r6
 *   @0x190dbc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §174/197 TFont::Assign(IYYFont*)  0x1a85e8  size 148  37 条（0x1a85e8..0x1a867c）
 * @func 0x1a85e8 0x1a867c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*) / YYStrDup(char const*) / TFont::Create()
 * 字段偏移 top8: 0x8×3 / 0x10×2 / 0x4×1 / 0x18×1 / 0x24×1 / 0xc×1 / 0x2c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a85e8 push {r3, r4, r5, lr}
 *   @0x1a85ec mov r5, r0
 *   @0x1a85f0 ldr r3, [r1]
 *   @0x1a85f4 mov r0, r1
 *   @0x1a85f8 mov r4, r1
 *   @0x1a85fc ldr r3, [r3, #0x8]
 *   @0x1a8600 blx r3
 *   @0x1a8604 ldr r3, [r5, #0x8]
 *   @0x1a8608 cmp r3, #0
 *   @0x1a860c str r0, [r5, #0x4]
 *   @0x1a8610 beq 0x1a861c <_ZN5TFont6AssignEP7IYYFont+0x34>
 *   @0x1a8614 mov r0, r3
 *   @0x1a8618 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1a861c ldr r3, [r4]
 *   @0x1a8620 mov r0, r4
 *   @0x1a8624 ldr r3, [r3, #0x10]
 *   @0x1a8628 blx r3
 *   @0x1a862c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1a8630 ldr r3, [r4]
 *   @0x1a8634 str r0, [r5, #0x8]
 *   @0x1a8638 mov r0, r4
 *   @0x1a863c ldr r3, [r3, #0x18]
 *   @0x1a8640 blx r3
 *   @0x1a8644 ldr r3, [r4]
 *   @0x1a8648 ldr r3, [r3, #0x24]
 *   @0x1a864c str r0, [r5, #0xc]
 *   @0x1a8650 mov r0, r4
 *   @0x1a8654 blx r3
 *   @0x1a8658 str r0, [r5, #0x10]
 *   @0x1a865c mov r0, r5
 *   @0x1a8660 bl 0x1a8850 <_ZN5TFont6CreateEv>
 *   @0x1a8664 ldr r3, [r4]
 *   @0x1a8668 mov r0, r4
 *   @0x1a866c ldr r3, [r3, #0x2c]
 *   @0x1a8670 blx r3
 *   @0x1a8674 str r0, [r5, #0x14]
 *   @0x1a8678 pop {r3, r4, r5, pc}
 *
 * ══ §175/197 cARRAY_MEMORY<char const*>::~cARRAY_MEMORY()  0x1b4a64  size 148  37 条（0x1b4a64..0x1b4af8）
 * @func 0x1b4a64 0x1b4af8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / cARRAY_MEMORY<char const*>::~cARRAY_MEMORY()+0x64 / MemoryManager::IsAllocated(void const*) / cARRAY_MEMORY<char const*>::~cARRAY_MEMORY()+0x28
 * 字段偏移 top8: 0x4×6 / 0x2×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b4a64 push {r3, r4, r5, r6, r7, lr}
 *   @0x1b4a68 mov r5, r0
 *   @0x1b4a6c ldr r6, [r0, #0x4]
 *   @0x1b4a70 cmp r6, #0
 *   @0x1b4a74 beq 0x1b4ae8 <_ZN13cARRAY_MEMORYIPKcED2Ev+0x84>
 *   @0x1b4a78 ldr r3, [r0]
 *   @0x1b4a7c cmp r3, #0
 *   @0x1b4a80 ble 0x1b4ac8 <_ZN13cARRAY_MEMORYIPKcED2Ev+0x64>
 *   @0x1b4a84 mov r4, #0
 *   @0x1b4a88 mov r7, r4
 *   @0x1b4a8c ldr r0, [r6, r4, lsl #2]
 *   @0x1b4a90 lsl r6, r4, #2
 *   @0x1b4a94 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv>
 *   @0x1b4a98 cmp r0, #0
 *   @0x1b4a9c beq 0x1b4aac <_ZN13cARRAY_MEMORYIPKcED2Ev+0x48>
 *   @0x1b4aa0 ldr r3, [r5, #0x4]
 *   @0x1b4aa4 ldr r0, [r3, r4, lsl #2]
 *   @0x1b4aa8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b4aac ldr r2, [r5]
 *   @0x1b4ab0 add r4, r4, #1
 *   @0x1b4ab4 ldr r3, [r5, #0x4]
 *   @0x1b4ab8 cmp r4, r2
 *   @0x1b4abc str r7, [r3, r6]
 *   @0x1b4ac0 ldr r6, [r5, #0x4]
 *   @0x1b4ac4 blt 0x1b4a8c <_ZN13cARRAY_MEMORYIPKcED2Ev+0x28>
 *   @0x1b4ac8 mov r0, r6
 *   @0x1b4acc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b4ad0 mov r3, #0
 *   @0x1b4ad4 str r3, [r5, #0x4]
 *   @0x1b4ad8 mov r3, #0
 *   @0x1b4adc mov r0, r5
 *   @0x1b4ae0 str r3, [r5]
 *   @0x1b4ae4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1b4ae8 mov r0, r6
 *   @0x1b4aec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b4af0 str r6, [r5, #0x4]
 *   @0x1b4af4 b 0x1b4ad8 <_ZN13cARRAY_MEMORYIPKcED2Ev+0x74>
 *
 * ══ §176/197 F_TileSetFlip(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b6424  size 148  37 条（0x1b6424..0x1b64b8）
 * @func 0x1b6424 0x1b64b8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x50×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b6424 cmp r3, #2
 *   @0x1b6428 mov r3, #0
 *   @0x1b642c push {r4, r5, r6, lr}
 *   @0x1b6430 vpush {d8}
 *   @0x1b6434 mov r5, r3
 *   @0x1b6438 mov r4, r0
 *   @0x1b643c movt r3, #0xbff0
 *   @0x1b6440 str r5, [r0, #0xc]
 *   @0x1b6444 str r3, [r0, #0x4]
 *   @0x1b6448 str r5, [r0]
 *   @0x1b644c ldr r6, [sp, #0x18]
 *   @0x1b6450 beq 0x1b646c <_Z13F_TileSetFlipR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1b6454 vpop {d8}
 *   @0x1b6458 mov r1, r5
 *   @0x1b645c ldr r0, [pc, #0x50]
 *   @0x1b6460 add r0, pc, r0
 *   @0x1b6464 pop {r4, r5, r6, lr}
 *   @0x1b6468 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b646c mov r1, #1
 *   @0x1b6470 mov r0, r6
 *   @0x1b6474 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1b6478 mov r1, r5
 *   @0x1b647c vmov s16, r0
 *   @0x1b6480 mov r0, r6
 *   @0x1b6484 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b6488 vmov.f32 s15, #5.000000e-01
 *   @0x1b648c vcmpe.f32 s16, s15
 *   @0x1b6490 vmrs APSR_nzcv, fpscr
 *   @0x1b6494 orrgt r2, r0, #536870912
 *   @0x1b6498 bicle r2, r0, #536870912
 *   @0x1b649c vmov s15, r2
 *   @0x1b64a0 vcvt.f64.s32 d7, s15
 *   @0x1b64a4 vmov r2, r3, d7
 *   @0x1b64a8 stm r4, {r2, r3}
 *   @0x1b64ac vpop {d8}
 *   @0x1b64b0 pop {r4, r5, r6, pc}
 *   @0x1b64b4 andseq r6, r9, r0, lsr #31
 *
 * ══ §177/197 F_TileSetMirror(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b64b8  size 148  37 条（0x1b64b8..0x1b654c）
 * @func 0x1b64b8 0x1b654c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x50×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b64b8 cmp r3, #2
 *   @0x1b64bc mov r3, #0
 *   @0x1b64c0 push {r4, r5, r6, lr}
 *   @0x1b64c4 vpush {d8}
 *   @0x1b64c8 mov r5, r3
 *   @0x1b64cc mov r4, r0
 *   @0x1b64d0 movt r3, #0xbff0
 *   @0x1b64d4 str r5, [r0, #0xc]
 *   @0x1b64d8 str r3, [r0, #0x4]
 *   @0x1b64dc str r5, [r0]
 *   @0x1b64e0 ldr r6, [sp, #0x18]
 *   @0x1b64e4 beq 0x1b6500 <_Z15F_TileSetMirrorR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1b64e8 vpop {d8}
 *   @0x1b64ec mov r1, r5
 *   @0x1b64f0 ldr r0, [pc, #0x50]
 *   @0x1b64f4 add r0, pc, r0
 *   @0x1b64f8 pop {r4, r5, r6, lr}
 *   @0x1b64fc b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b6500 mov r1, #1
 *   @0x1b6504 mov r0, r6
 *   @0x1b6508 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1b650c mov r1, r5
 *   @0x1b6510 vmov s16, r0
 *   @0x1b6514 mov r0, r6
 *   @0x1b6518 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b651c vmov.f32 s15, #5.000000e-01
 *   @0x1b6520 vcmpe.f32 s16, s15
 *   @0x1b6524 vmrs APSR_nzcv, fpscr
 *   @0x1b6528 orrgt r2, r0, #268435456
 *   @0x1b652c bicle r2, r0, #268435456
 *   @0x1b6530 vmov s15, r2
 *   @0x1b6534 vcvt.f64.s32 d7, s15
 *   @0x1b6538 vmov r2, r3, d7
 *   @0x1b653c stm r4, {r2, r3}
 *   @0x1b6540 vpop {d8}
 *   @0x1b6544 pop {r4, r5, r6, pc}
 *   @0x1b6548 andseq r6, r9, r8, lsr pc
 *
 * ══ §178/197 F_TileSetRotate(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b654c  size 148  37 条（0x1b654c..0x1b65e0）
 * @func 0x1b654c 0x1b65e0  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x50×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b654c cmp r3, #2
 *   @0x1b6550 mov r3, #0
 *   @0x1b6554 push {r4, r5, r6, lr}
 *   @0x1b6558 vpush {d8}
 *   @0x1b655c mov r5, r3
 *   @0x1b6560 mov r4, r0
 *   @0x1b6564 movt r3, #0xbff0
 *   @0x1b6568 str r5, [r0, #0xc]
 *   @0x1b656c str r3, [r0, #0x4]
 *   @0x1b6570 str r5, [r0]
 *   @0x1b6574 ldr r6, [sp, #0x18]
 *   @0x1b6578 beq 0x1b6594 <_Z15F_TileSetRotateR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1b657c vpop {d8}
 *   @0x1b6580 mov r1, r5
 *   @0x1b6584 ldr r0, [pc, #0x50]
 *   @0x1b6588 add r0, pc, r0
 *   @0x1b658c pop {r4, r5, r6, lr}
 *   @0x1b6590 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b6594 mov r1, #1
 *   @0x1b6598 mov r0, r6
 *   @0x1b659c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1b65a0 mov r1, r5
 *   @0x1b65a4 vmov s16, r0
 *   @0x1b65a8 mov r0, r6
 *   @0x1b65ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b65b0 vmov.f32 s15, #5.000000e-01
 *   @0x1b65b4 vcmpe.f32 s16, s15
 *   @0x1b65b8 vmrs APSR_nzcv, fpscr
 *   @0x1b65bc orrgt r2, r0, #1073741824
 *   @0x1b65c0 bicle r2, r0, #1073741824
 *   @0x1b65c4 vmov s15, r2
 *   @0x1b65c8 vcvt.f64.s32 d7, s15
 *   @0x1b65cc vmov r2, r3, d7
 *   @0x1b65d0 stm r4, {r2, r3}
 *   @0x1b65d4 vpop {d8}
 *   @0x1b65d8 pop {r4, r5, r6, pc}
 *   @0x1b65dc ldrsbeq r6, [r9], -r4
 *
 * ══ §179/197 F_LayerBackgroundVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bc3b8  size 148  37 条（0x1bc3b8..0x1bc44c）
 * @func 0x1bc3b8 0x1bc44c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x60×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc3b8 cmp r3, #2
 *   @0x1bc3bc mov r3, #0
 *   @0x1bc3c0 push {r4, r5, r6, lr}
 *   @0x1bc3c4 mov r4, r3
 *   @0x1bc3c8 ldr r5, [sp, #0x10]
 *   @0x1bc3cc movt r3, #0xbff0
 *   @0x1bc3d0 str r4, [r0, #0xc]
 *   @0x1bc3d4 str r3, [r0, #0x4]
 *   @0x1bc3d8 str r4, [r0]
 *   @0x1bc3dc beq 0x1bc3f4 <_Z24F_LayerBackgroundVisibleR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bc3e0 ldr r0, [pc, #0x60]
 *   @0x1bc3e4 mov r1, r4
 *   @0x1bc3e8 pop {r4, r5, r6, lr}
 *   @0x1bc3ec add r0, pc, r0
 *   @0x1bc3f0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bc3f4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bc3f8 mov r1, r4
 *   @0x1bc3fc mov r6, r0
 *   @0x1bc400 mov r0, r5
 *   @0x1bc404 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc408 mov r2, r4
 *   @0x1bc40c mov r1, r0
 *   @0x1bc410 mov r0, r6
 *   @0x1bc414 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bc418 cmp r0, #0
 *   @0x1bc41c popeq {r4, r5, r6, pc}
 *   @0x1bc420 ldr r1, [r0]
 *   @0x1bc424 cmp r1, #1
 *   @0x1bc428 popne {r4, r5, r6, pc}
 *   @0x1bc42c ldr r4, [r0, #0x1c]
 *   @0x1bc430 cmp r4, #0
 *   @0x1bc434 popeq {r4, r5, r6, pc}
 *   @0x1bc438 mov r0, r5
 *   @0x1bc43c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1bc440 strb r0, [r4]
 *   @0x1bc444 pop {r4, r5, r6, pc}
 *   @0x1bc448 andseq r1, r9, r8, ror #20
 *
 * ══ §180/197 F_LayerBackgroundHtiled(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bc44c  size 148  37 条（0x1bc44c..0x1bc4e0）
 * @func 0x1bc44c 0x1bc4e0  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x60×1 / 0x1c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc44c cmp r3, #2
 *   @0x1bc450 mov r3, #0
 *   @0x1bc454 push {r4, r5, r6, lr}
 *   @0x1bc458 mov r4, r3
 *   @0x1bc45c ldr r5, [sp, #0x10]
 *   @0x1bc460 movt r3, #0xbff0
 *   @0x1bc464 str r4, [r0, #0xc]
 *   @0x1bc468 str r3, [r0, #0x4]
 *   @0x1bc46c str r4, [r0]
 *   @0x1bc470 beq 0x1bc488 <_Z23F_LayerBackgroundHtiledR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bc474 ldr r0, [pc, #0x60]
 *   @0x1bc478 mov r1, r4
 *   @0x1bc47c pop {r4, r5, r6, lr}
 *   @0x1bc480 add r0, pc, r0
 *   @0x1bc484 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bc488 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bc48c mov r1, r4
 *   @0x1bc490 mov r6, r0
 *   @0x1bc494 mov r0, r5
 *   @0x1bc498 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc49c mov r2, r4
 *   @0x1bc4a0 mov r1, r0
 *   @0x1bc4a4 mov r0, r6
 *   @0x1bc4a8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bc4ac cmp r0, #0
 *   @0x1bc4b0 popeq {r4, r5, r6, pc}
 *   @0x1bc4b4 ldr r1, [r0]
 *   @0x1bc4b8 cmp r1, #1
 *   @0x1bc4bc popne {r4, r5, r6, pc}
 *   @0x1bc4c0 ldr r4, [r0, #0x1c]
 *   @0x1bc4c4 cmp r4, #0
 *   @0x1bc4c8 popeq {r4, r5, r6, pc}
 *   @0x1bc4cc mov r0, r5
 *   @0x1bc4d0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1bc4d4 strb r0, [r4, #0x8]
 *   @0x1bc4d8 pop {r4, r5, r6, pc}
 *   @0x1bc4dc andseq r1, r9, r12, lsl #20
 *
 * ══ §181/197 F_LayerBackgroundVtiled(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bc4e0  size 148  37 条（0x1bc4e0..0x1bc574）
 * @func 0x1bc4e0 0x1bc574  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x60×1 / 0x1c×1 / 0x9×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc4e0 cmp r3, #2
 *   @0x1bc4e4 mov r3, #0
 *   @0x1bc4e8 push {r4, r5, r6, lr}
 *   @0x1bc4ec mov r4, r3
 *   @0x1bc4f0 ldr r5, [sp, #0x10]
 *   @0x1bc4f4 movt r3, #0xbff0
 *   @0x1bc4f8 str r4, [r0, #0xc]
 *   @0x1bc4fc str r3, [r0, #0x4]
 *   @0x1bc500 str r4, [r0]
 *   @0x1bc504 beq 0x1bc51c <_Z23F_LayerBackgroundVtiledR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bc508 ldr r0, [pc, #0x60]
 *   @0x1bc50c mov r1, r4
 *   @0x1bc510 pop {r4, r5, r6, lr}
 *   @0x1bc514 add r0, pc, r0
 *   @0x1bc518 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bc51c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bc520 mov r1, r4
 *   @0x1bc524 mov r6, r0
 *   @0x1bc528 mov r0, r5
 *   @0x1bc52c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc530 mov r2, r4
 *   @0x1bc534 mov r1, r0
 *   @0x1bc538 mov r0, r6
 *   @0x1bc53c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bc540 cmp r0, #0
 *   @0x1bc544 popeq {r4, r5, r6, pc}
 *   @0x1bc548 ldr r1, [r0]
 *   @0x1bc54c cmp r1, #1
 *   @0x1bc550 popne {r4, r5, r6, pc}
 *   @0x1bc554 ldr r4, [r0, #0x1c]
 *   @0x1bc558 cmp r4, #0
 *   @0x1bc55c popeq {r4, r5, r6, pc}
 *   @0x1bc560 mov r0, r5
 *   @0x1bc564 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1bc568 strb r0, [r4, #0x9]
 *   @0x1bc56c pop {r4, r5, r6, pc}
 *   @0x1bc570 ldrheq r1, [r9], -r0
 *
 * ══ §182/197 F_LayerBackgroundStretch(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bc574  size 148  37 条（0x1bc574..0x1bc608）
 * @func 0x1bc574 0x1bc608  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x60×1 / 0x1c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc574 cmp r3, #2
 *   @0x1bc578 mov r3, #0
 *   @0x1bc57c push {r4, r5, r6, lr}
 *   @0x1bc580 mov r4, r3
 *   @0x1bc584 ldr r5, [sp, #0x10]
 *   @0x1bc588 movt r3, #0xbff0
 *   @0x1bc58c str r4, [r0, #0xc]
 *   @0x1bc590 str r3, [r0, #0x4]
 *   @0x1bc594 str r4, [r0]
 *   @0x1bc598 beq 0x1bc5b0 <_Z24F_LayerBackgroundStretchR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bc59c ldr r0, [pc, #0x60]
 *   @0x1bc5a0 mov r1, r4
 *   @0x1bc5a4 pop {r4, r5, r6, lr}
 *   @0x1bc5a8 add r0, pc, r0
 *   @0x1bc5ac b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bc5b0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bc5b4 mov r1, r4
 *   @0x1bc5b8 mov r6, r0
 *   @0x1bc5bc mov r0, r5
 *   @0x1bc5c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc5c4 mov r2, r4
 *   @0x1bc5c8 mov r1, r0
 *   @0x1bc5cc mov r0, r6
 *   @0x1bc5d0 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bc5d4 cmp r0, #0
 *   @0x1bc5d8 popeq {r4, r5, r6, pc}
 *   @0x1bc5dc ldr r1, [r0]
 *   @0x1bc5e0 cmp r1, #1
 *   @0x1bc5e4 popne {r4, r5, r6, pc}
 *   @0x1bc5e8 ldr r4, [r0, #0x1c]
 *   @0x1bc5ec cmp r4, #0
 *   @0x1bc5f0 popeq {r4, r5, r6, pc}
 *   @0x1bc5f4 mov r0, r5
 *   @0x1bc5f8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1bc5fc strb r0, [r4, #0x14]
 *   @0x1bc600 pop {r4, r5, r6, pc}
 *   @0x1bc604 andseq r1, r9, r4, asr r9
 *
 * ══ §183/197 F_LayerBackgroundXscale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bc608  size 148  37 条（0x1bc608..0x1bc69c）
 * @func 0x1bc608 0x1bc69c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x4×1 / 0x60×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc608 cmp r3, #2
 *   @0x1bc60c mov r3, #0
 *   @0x1bc610 push {r4, r5, r6, lr}
 *   @0x1bc614 mov r4, r3
 *   @0x1bc618 ldr r5, [sp, #0x10]
 *   @0x1bc61c movt r3, #0xbff0
 *   @0x1bc620 str r4, [r0, #0xc]
 *   @0x1bc624 str r3, [r0, #0x4]
 *   @0x1bc628 str r4, [r0]
 *   @0x1bc62c beq 0x1bc644 <_Z23F_LayerBackgroundXscaleR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bc630 ldr r0, [pc, #0x60]
 *   @0x1bc634 mov r1, r4
 *   @0x1bc638 pop {r4, r5, r6, lr}
 *   @0x1bc63c add r0, pc, r0
 *   @0x1bc640 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bc644 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bc648 mov r1, r4
 *   @0x1bc64c mov r6, r0
 *   @0x1bc650 mov r0, r5
 *   @0x1bc654 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc658 mov r2, r4
 *   @0x1bc65c mov r1, r0
 *   @0x1bc660 mov r0, r6
 *   @0x1bc664 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bc668 cmp r0, #0
 *   @0x1bc66c popeq {r4, r5, r6, pc}
 *   @0x1bc670 ldr r1, [r0]
 *   @0x1bc674 cmp r1, #1
 *   @0x1bc678 popne {r4, r5, r6, pc}
 *   @0x1bc67c ldr r4, [r0, #0x1c]
 *   @0x1bc680 cmp r4, #0
 *   @0x1bc684 popeq {r4, r5, r6, pc}
 *   @0x1bc688 mov r0, r5
 *   @0x1bc68c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bc690 str r0, [r4, #0xc]
 *   @0x1bc694 pop {r4, r5, r6, pc}
 *   @0x1bc698 ldrsheq r1, [r9], -r8
 *
 * ══ §184/197 F_LayerBackgroundYscale(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bc69c  size 148  37 条（0x1bc69c..0x1bc730）
 * @func 0x1bc69c 0x1bc730  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0xc×1 / 0x4×1 / 0x60×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc69c cmp r3, #2
 *   @0x1bc6a0 mov r3, #0
 *   @0x1bc6a4 push {r4, r5, r6, lr}
 *   @0x1bc6a8 mov r4, r3
 *   @0x1bc6ac ldr r5, [sp, #0x10]
 *   @0x1bc6b0 movt r3, #0xbff0
 *   @0x1bc6b4 str r4, [r0, #0xc]
 *   @0x1bc6b8 str r3, [r0, #0x4]
 *   @0x1bc6bc str r4, [r0]
 *   @0x1bc6c0 beq 0x1bc6d8 <_Z23F_LayerBackgroundYscaleR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bc6c4 ldr r0, [pc, #0x60]
 *   @0x1bc6c8 mov r1, r4
 *   @0x1bc6cc pop {r4, r5, r6, lr}
 *   @0x1bc6d0 add r0, pc, r0
 *   @0x1bc6d4 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bc6d8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bc6dc mov r1, r4
 *   @0x1bc6e0 mov r6, r0
 *   @0x1bc6e4 mov r0, r5
 *   @0x1bc6e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc6ec mov r2, r4
 *   @0x1bc6f0 mov r1, r0
 *   @0x1bc6f4 mov r0, r6
 *   @0x1bc6f8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bc6fc cmp r0, #0
 *   @0x1bc700 popeq {r4, r5, r6, pc}
 *   @0x1bc704 ldr r1, [r0]
 *   @0x1bc708 cmp r1, #1
 *   @0x1bc70c popne {r4, r5, r6, pc}
 *   @0x1bc710 ldr r4, [r0, #0x1c]
 *   @0x1bc714 cmp r4, #0
 *   @0x1bc718 popeq {r4, r5, r6, pc}
 *   @0x1bc71c mov r0, r5
 *   @0x1bc720 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bc724 str r0, [r4, #0x10]
 *   @0x1bc728 pop {r4, r5, r6, pc}
 *   @0x1bc72c mulseq r9, r12, r8
 *
 * ══ §185/197 F_LayerBackgroundBlend(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bc730  size 148  37 条（0x1bc730..0x1bc7c4）
 * @func 0x1bc730 0x1bc7c4  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x60×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc730 cmp r3, #2
 *   @0x1bc734 mov r3, #0
 *   @0x1bc738 push {r4, r5, r6, lr}
 *   @0x1bc73c mov r4, r3
 *   @0x1bc740 ldr r5, [sp, #0x10]
 *   @0x1bc744 movt r3, #0xbff0
 *   @0x1bc748 str r4, [r0, #0xc]
 *   @0x1bc74c str r3, [r0, #0x4]
 *   @0x1bc750 str r4, [r0]
 *   @0x1bc754 beq 0x1bc76c <_Z22F_LayerBackgroundBlendR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bc758 ldr r0, [pc, #0x60]
 *   @0x1bc75c mov r1, r4
 *   @0x1bc760 pop {r4, r5, r6, lr}
 *   @0x1bc764 add r0, pc, r0
 *   @0x1bc768 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bc76c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bc770 mov r1, r4
 *   @0x1bc774 mov r6, r0
 *   @0x1bc778 mov r0, r5
 *   @0x1bc77c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc780 mov r2, r4
 *   @0x1bc784 mov r1, r0
 *   @0x1bc788 mov r0, r6
 *   @0x1bc78c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bc790 cmp r0, #0
 *   @0x1bc794 popeq {r4, r5, r6, pc}
 *   @0x1bc798 ldr r1, [r0]
 *   @0x1bc79c cmp r1, #1
 *   @0x1bc7a0 popne {r4, r5, r6, pc}
 *   @0x1bc7a4 ldr r4, [r0, #0x1c]
 *   @0x1bc7a8 cmp r4, #0
 *   @0x1bc7ac popeq {r4, r5, r6, pc}
 *   @0x1bc7b0 mov r0, r5
 *   @0x1bc7b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc7b8 str r0, [r4, #0x18]
 *   @0x1bc7bc pop {r4, r5, r6, pc}
 *   @0x1bc7c0 andseq r1, r9, r0, asr #16
 *
 * ══ §186/197 F_LayerBackgroundAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bc7c4  size 148  37 条（0x1bc7c4..0x1bc858）
 * @func 0x1bc7c4 0x1bc858  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x1c×2 / 0x10×1 / 0xc×1 / 0x4×1 / 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc7c4 cmp r3, #2
 *   @0x1bc7c8 mov r3, #0
 *   @0x1bc7cc push {r4, r5, r6, lr}
 *   @0x1bc7d0 mov r4, r3
 *   @0x1bc7d4 ldr r5, [sp, #0x10]
 *   @0x1bc7d8 movt r3, #0xbff0
 *   @0x1bc7dc str r4, [r0, #0xc]
 *   @0x1bc7e0 str r3, [r0, #0x4]
 *   @0x1bc7e4 str r4, [r0]
 *   @0x1bc7e8 beq 0x1bc800 <_Z22F_LayerBackgroundAlphaR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bc7ec ldr r0, [pc, #0x60]
 *   @0x1bc7f0 mov r1, r4
 *   @0x1bc7f4 pop {r4, r5, r6, lr}
 *   @0x1bc7f8 add r0, pc, r0
 *   @0x1bc7fc b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bc800 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bc804 mov r1, r4
 *   @0x1bc808 mov r6, r0
 *   @0x1bc80c mov r0, r5
 *   @0x1bc810 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc814 mov r2, r4
 *   @0x1bc818 mov r1, r0
 *   @0x1bc81c mov r0, r6
 *   @0x1bc820 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bc824 cmp r0, #0
 *   @0x1bc828 popeq {r4, r5, r6, pc}
 *   @0x1bc82c ldr r1, [r0]
 *   @0x1bc830 cmp r1, #1
 *   @0x1bc834 popne {r4, r5, r6, pc}
 *   @0x1bc838 ldr r4, [r0, #0x1c]
 *   @0x1bc83c cmp r4, #0
 *   @0x1bc840 popeq {r4, r5, r6, pc}
 *   @0x1bc844 mov r0, r5
 *   @0x1bc848 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bc84c str r0, [r4, #0x1c]
 *   @0x1bc850 pop {r4, r5, r6, pc}
 *   @0x1bc854 andseq r1, r9, r4, ror #15
 *
 * ══ §187/197 F_LayerBackgroundIndex(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bc858  size 148  37 条（0x1bc858..0x1bc8ec）
 * @func 0x1bc858 0x1bc8ec  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x60×1 / 0x1c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc858 cmp r3, #2
 *   @0x1bc85c mov r3, #0
 *   @0x1bc860 push {r4, r5, r6, lr}
 *   @0x1bc864 mov r4, r3
 *   @0x1bc868 ldr r5, [sp, #0x10]
 *   @0x1bc86c movt r3, #0xbff0
 *   @0x1bc870 str r4, [r0, #0xc]
 *   @0x1bc874 str r3, [r0, #0x4]
 *   @0x1bc878 str r4, [r0]
 *   @0x1bc87c beq 0x1bc894 <_Z22F_LayerBackgroundIndexR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bc880 ldr r0, [pc, #0x60]
 *   @0x1bc884 mov r1, r4
 *   @0x1bc888 pop {r4, r5, r6, lr}
 *   @0x1bc88c add r0, pc, r0
 *   @0x1bc890 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bc894 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bc898 mov r1, r4
 *   @0x1bc89c mov r6, r0
 *   @0x1bc8a0 mov r0, r5
 *   @0x1bc8a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc8a8 mov r2, r4
 *   @0x1bc8ac mov r1, r0
 *   @0x1bc8b0 mov r0, r6
 *   @0x1bc8b4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bc8b8 cmp r0, #0
 *   @0x1bc8bc popeq {r4, r5, r6, pc}
 *   @0x1bc8c0 ldr r1, [r0]
 *   @0x1bc8c4 cmp r1, #1
 *   @0x1bc8c8 popne {r4, r5, r6, pc}
 *   @0x1bc8cc ldr r4, [r0, #0x1c]
 *   @0x1bc8d0 cmp r4, #0
 *   @0x1bc8d4 popeq {r4, r5, r6, pc}
 *   @0x1bc8d8 mov r0, r5
 *   @0x1bc8dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bc8e0 str r0, [r4, #0x20]
 *   @0x1bc8e4 pop {r4, r5, r6, pc}
 *   @0x1bc8e8 andseq r1, r9, r8, lsl #15
 *
 * ══ §188/197 F_LayerBackgroundSpeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bc8ec  size 148  37 条（0x1bc8ec..0x1bc980）
 * @func 0x1bc8ec 0x1bc980  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x60×1 / 0x1c×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc8ec cmp r3, #2
 *   @0x1bc8f0 mov r3, #0
 *   @0x1bc8f4 push {r4, r5, r6, lr}
 *   @0x1bc8f8 mov r4, r3
 *   @0x1bc8fc ldr r5, [sp, #0x10]
 *   @0x1bc900 movt r3, #0xbff0
 *   @0x1bc904 str r4, [r0, #0xc]
 *   @0x1bc908 str r3, [r0, #0x4]
 *   @0x1bc90c str r4, [r0]
 *   @0x1bc910 beq 0x1bc928 <_Z22F_LayerBackgroundSpeedR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bc914 ldr r0, [pc, #0x60]
 *   @0x1bc918 mov r1, r4
 *   @0x1bc91c pop {r4, r5, r6, lr}
 *   @0x1bc920 add r0, pc, r0
 *   @0x1bc924 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bc928 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bc92c mov r1, r4
 *   @0x1bc930 mov r6, r0
 *   @0x1bc934 mov r0, r5
 *   @0x1bc938 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc93c mov r2, r4
 *   @0x1bc940 mov r1, r0
 *   @0x1bc944 mov r0, r6
 *   @0x1bc948 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bc94c cmp r0, #0
 *   @0x1bc950 popeq {r4, r5, r6, pc}
 *   @0x1bc954 ldr r1, [r0]
 *   @0x1bc958 cmp r1, #1
 *   @0x1bc95c popne {r4, r5, r6, pc}
 *   @0x1bc960 ldr r4, [r0, #0x1c]
 *   @0x1bc964 cmp r4, #0
 *   @0x1bc968 popeq {r4, r5, r6, pc}
 *   @0x1bc96c mov r0, r5
 *   @0x1bc970 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bc974 str r0, [r4, #0x24]
 *   @0x1bc978 pop {r4, r5, r6, pc}
 *   @0x1bc97c andseq r1, r9, r12, lsr #14
 *
 * ══ §189/197 F_LayerBackgroundSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bc980  size 148  37 条（0x1bc980..0x1bca14）
 * @func 0x1bc980 0x1bca14  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0xc×1 / 0x60×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc980 cmp r3, #2
 *   @0x1bc984 mov r3, #0
 *   @0x1bc988 push {r4, r5, r6, lr}
 *   @0x1bc98c mov r4, r3
 *   @0x1bc990 ldr r5, [sp, #0x10]
 *   @0x1bc994 movt r3, #0xbff0
 *   @0x1bc998 str r4, [r0, #0xc]
 *   @0x1bc99c str r3, [r0, #0x4]
 *   @0x1bc9a0 str r4, [r0]
 *   @0x1bc9a4 beq 0x1bc9bc <_Z23F_LayerBackgroundSpriteR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bc9a8 ldr r0, [pc, #0x60]
 *   @0x1bc9ac mov r1, r4
 *   @0x1bc9b0 pop {r4, r5, r6, lr}
 *   @0x1bc9b4 add r0, pc, r0
 *   @0x1bc9b8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bc9bc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bc9c0 mov r1, r4
 *   @0x1bc9c4 mov r6, r0
 *   @0x1bc9c8 mov r0, r5
 *   @0x1bc9cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc9d0 mov r2, r4
 *   @0x1bc9d4 mov r1, r0
 *   @0x1bc9d8 mov r0, r6
 *   @0x1bc9dc bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bc9e0 cmp r0, #0
 *   @0x1bc9e4 popeq {r4, r5, r6, pc}
 *   @0x1bc9e8 ldr r1, [r0]
 *   @0x1bc9ec cmp r1, #1
 *   @0x1bc9f0 popne {r4, r5, r6, pc}
 *   @0x1bc9f4 ldr r4, [r0, #0x1c]
 *   @0x1bc9f8 cmp r4, #0
 *   @0x1bc9fc popeq {r4, r5, r6, pc}
 *   @0x1bca00 mov r0, r5
 *   @0x1bca04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bca08 str r0, [r4, #0x4]
 *   @0x1bca0c pop {r4, r5, r6, pc}
 *   @0x1bca10 ldrsbeq r1, [r9], -r0
 *
 * ══ §190/197 F_LayerSpriteGetSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bd6b8  size 148  37 条（0x1bd6b8..0x1bd74c）
 * @func 0x1bd6b8 0x1bd74c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x5c×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bd6b8 cmp r3, #1
 *   @0x1bd6bc push {r3, r4, r5, r6, r7, lr}
 *   @0x1bd6c0 mov r3, #0
 *   @0x1bd6c4 mov r4, r3
 *   @0x1bd6c8 mov r5, r0
 *   @0x1bd6cc movt r3, #0xbff0
 *   @0x1bd6d0 str r4, [r0, #0xc]
 *   @0x1bd6d4 str r3, [r0, #0x4]
 *   @0x1bd6d8 str r4, [r0]
 *   @0x1bd6dc ldr r6, [sp, #0x18]
 *   @0x1bd6e0 beq 0x1bd6f8 <_Z22F_LayerSpriteGetSpriteR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bd6e4 ldr r0, [pc, #0x5c]
 *   @0x1bd6e8 mov r1, r4
 *   @0x1bd6ec pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bd6f0 add r0, pc, r0
 *   @0x1bd6f4 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bd6f8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bd6fc mov r1, r4
 *   @0x1bd700 mov r7, r0
 *   @0x1bd704 mov r0, r6
 *   @0x1bd708 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bd70c mov r2, r4
 *   @0x1bd710 mov r1, r0
 *   @0x1bd714 mov r0, r7
 *   @0x1bd718 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bd71c cmp r0, #0
 *   @0x1bd720 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bd724 ldr r3, [r0]
 *   @0x1bd728 cmp r3, #4
 *   @0x1bd72c popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bd730 ldr r2, [r0, #0x1c]
 *   @0x1bd734 vmov s15, r2
 *   @0x1bd738 vcvt.f64.s32 d7, s15
 *   @0x1bd73c vmov r2, r3, d7
 *   @0x1bd740 stm r5, {r2, r3}
 *   @0x1bd744 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bd748 andseq r0, r9, r0, ror #28
 *
 * ══ §191/197 F_TilemapGetTileset(RValue&, CInstance*, CInstance*, int, RValue*)  0x1be2b8  size 148  37 条（0x1be2b8..0x1be34c）
 * @func 0x1be2b8 0x1be34c  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x5c×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1be2b8 cmp r3, #1
 *   @0x1be2bc push {r3, r4, r5, r6, r7, lr}
 *   @0x1be2c0 mov r3, #0
 *   @0x1be2c4 mov r4, r3
 *   @0x1be2c8 mov r5, r0
 *   @0x1be2cc movt r3, #0xbff0
 *   @0x1be2d0 str r4, [r0, #0xc]
 *   @0x1be2d4 str r3, [r0, #0x4]
 *   @0x1be2d8 str r4, [r0]
 *   @0x1be2dc ldr r6, [sp, #0x18]
 *   @0x1be2e0 beq 0x1be2f8 <_Z19F_TilemapGetTilesetR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1be2e4 ldr r0, [pc, #0x5c]
 *   @0x1be2e8 mov r1, r4
 *   @0x1be2ec pop {r3, r4, r5, r6, r7, lr}
 *   @0x1be2f0 add r0, pc, r0
 *   @0x1be2f4 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be2f8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1be2fc mov r1, r4
 *   @0x1be300 mov r7, r0
 *   @0x1be304 mov r0, r6
 *   @0x1be308 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be30c mov r2, r4
 *   @0x1be310 mov r1, r0
 *   @0x1be314 mov r0, r7
 *   @0x1be318 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1be31c cmp r0, #0
 *   @0x1be320 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1be324 ldr r3, [r0]
 *   @0x1be328 cmp r3, #5
 *   @0x1be32c popne {r3, r4, r5, r6, r7, pc}
 *   @0x1be330 ldr r2, [r0, #0x1c]
 *   @0x1be334 vmov s15, r2
 *   @0x1be338 vcvt.f64.s32 d7, s15
 *   @0x1be33c vmov r2, r3, d7
 *   @0x1be340 stm r5, {r2, r3}
 *   @0x1be344 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1be348 ldrsheq r0, [r9], -r8
 *
 * ══ §192/197 F_TilemapGetWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x1be4c4  size 148  37 条（0x1be4c4..0x1be558）
 * @func 0x1be4c4 0x1be558  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x5c×1 / 0x28×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1be4c4 cmp r3, #1
 *   @0x1be4c8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1be4cc mov r3, #0
 *   @0x1be4d0 mov r4, r3
 *   @0x1be4d4 mov r5, r0
 *   @0x1be4d8 movt r3, #0xbff0
 *   @0x1be4dc str r4, [r0, #0xc]
 *   @0x1be4e0 str r3, [r0, #0x4]
 *   @0x1be4e4 str r4, [r0]
 *   @0x1be4e8 ldr r6, [sp, #0x18]
 *   @0x1be4ec beq 0x1be504 <_Z17F_TilemapGetWidthR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1be4f0 ldr r0, [pc, #0x5c]
 *   @0x1be4f4 mov r1, r4
 *   @0x1be4f8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1be4fc add r0, pc, r0
 *   @0x1be500 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be504 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1be508 mov r1, r4
 *   @0x1be50c mov r7, r0
 *   @0x1be510 mov r0, r6
 *   @0x1be514 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be518 mov r2, r4
 *   @0x1be51c mov r1, r0
 *   @0x1be520 mov r0, r7
 *   @0x1be524 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1be528 cmp r0, #0
 *   @0x1be52c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1be530 ldr r3, [r0]
 *   @0x1be534 cmp r3, #5
 *   @0x1be538 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1be53c ldr r2, [r0, #0x28]
 *   @0x1be540 vmov s15, r2
 *   @0x1be544 vcvt.f64.s32 d7, s15
 *   @0x1be548 vmov r2, r3, d7
 *   @0x1be54c stm r5, {r2, r3}
 *   @0x1be550 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1be554 andseq r0, r9, r0, lsl r6
 *
 * ══ §193/197 F_TilemapGetHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x1be558  size 148  37 条（0x1be558..0x1be5ec）
 * @func 0x1be558 0x1be5ec  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x5c×1 / 0x2c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1be558 cmp r3, #1
 *   @0x1be55c push {r3, r4, r5, r6, r7, lr}
 *   @0x1be560 mov r3, #0
 *   @0x1be564 mov r4, r3
 *   @0x1be568 mov r5, r0
 *   @0x1be56c movt r3, #0xbff0
 *   @0x1be570 str r4, [r0, #0xc]
 *   @0x1be574 str r3, [r0, #0x4]
 *   @0x1be578 str r4, [r0]
 *   @0x1be57c ldr r6, [sp, #0x18]
 *   @0x1be580 beq 0x1be598 <_Z18F_TilemapGetHeightR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1be584 ldr r0, [pc, #0x5c]
 *   @0x1be588 mov r1, r4
 *   @0x1be58c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1be590 add r0, pc, r0
 *   @0x1be594 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be598 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1be59c mov r1, r4
 *   @0x1be5a0 mov r7, r0
 *   @0x1be5a4 mov r0, r6
 *   @0x1be5a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be5ac mov r2, r4
 *   @0x1be5b0 mov r1, r0
 *   @0x1be5b4 mov r0, r7
 *   @0x1be5b8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1be5bc cmp r0, #0
 *   @0x1be5c0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1be5c4 ldr r3, [r0]
 *   @0x1be5c8 cmp r3, #5
 *   @0x1be5cc popne {r3, r4, r5, r6, r7, pc}
 *   @0x1be5d0 ldr r2, [r0, #0x2c]
 *   @0x1be5d4 vmov s15, r2
 *   @0x1be5d8 vcvt.f64.s32 d7, s15
 *   @0x1be5dc vmov r2, r3, d7
 *   @0x1be5e0 stm r5, {r2, r3}
 *   @0x1be5e4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1be5e8 andseq r0, r9, r12, lsr #11
 *
 * ══ §194/197 F_LayerTileBlend(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf65c  size 148  37 条（0x1bf65c..0x1bf6f0）
 * @func 0x1bf65c 0x1bf6f0  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x60×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf65c cmp r3, #2
 *   @0x1bf660 mov r3, #0
 *   @0x1bf664 push {r4, r5, r6, lr}
 *   @0x1bf668 mov r4, r3
 *   @0x1bf66c ldr r5, [sp, #0x10]
 *   @0x1bf670 movt r3, #0xbff0
 *   @0x1bf674 str r4, [r0, #0xc]
 *   @0x1bf678 str r3, [r0, #0x4]
 *   @0x1bf67c str r4, [r0]
 *   @0x1bf680 beq 0x1bf698 <_Z16F_LayerTileBlendR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bf684 ldr r0, [pc, #0x60]
 *   @0x1bf688 mov r1, r4
 *   @0x1bf68c pop {r4, r5, r6, lr}
 *   @0x1bf690 add r0, pc, r0
 *   @0x1bf694 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf698 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf69c mov r1, r4
 *   @0x1bf6a0 mov r6, r0
 *   @0x1bf6a4 mov r0, r5
 *   @0x1bf6a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf6ac mov r2, r4
 *   @0x1bf6b0 mov r1, r0
 *   @0x1bf6b4 mov r0, r6
 *   @0x1bf6b8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf6bc subs r4, r0, #0
 *   @0x1bf6c0 popeq {r4, r5, r6, pc}
 *   @0x1bf6c4 ldr r3, [r4]
 *   @0x1bf6c8 cmp r3, #7
 *   @0x1bf6cc popne {r4, r5, r6, pc}
 *   @0x1bf6d0 mov r0, r5
 *   @0x1bf6d4 mov r1, #1
 *   @0x1bf6d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bf6dc vmov s15, r0
 *   @0x1bf6e0 vcvt.u32.f32 s15, s15
 *   @0x1bf6e4 vstr s15, [r4, #64]
 *   @0x1bf6e8 pop {r4, r5, r6, pc}
 *   @0x1bf6ec andseq pc, r8, r8, lsr #25
 *
 * ══ §195/197 F_LayerTileGetSprite(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf934  size 148  37 条（0x1bf934..0x1bf9c8）
 * @func 0x1bf934 0x1bf9c8  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x5c×1 / 0x20×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf934 cmp r3, #1
 *   @0x1bf938 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bf93c mov r3, #0
 *   @0x1bf940 mov r4, r3
 *   @0x1bf944 mov r5, r0
 *   @0x1bf948 movt r3, #0xbff0
 *   @0x1bf94c str r4, [r0, #0xc]
 *   @0x1bf950 str r3, [r0, #0x4]
 *   @0x1bf954 str r4, [r0]
 *   @0x1bf958 ldr r6, [sp, #0x18]
 *   @0x1bf95c beq 0x1bf974 <_Z20F_LayerTileGetSpriteR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bf960 ldr r0, [pc, #0x5c]
 *   @0x1bf964 mov r1, r4
 *   @0x1bf968 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bf96c add r0, pc, r0
 *   @0x1bf970 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf974 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf978 mov r1, r4
 *   @0x1bf97c mov r7, r0
 *   @0x1bf980 mov r0, r6
 *   @0x1bf984 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf988 mov r2, r4
 *   @0x1bf98c mov r1, r0
 *   @0x1bf990 mov r0, r7
 *   @0x1bf994 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf998 cmp r0, #0
 *   @0x1bf99c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bf9a0 ldr r3, [r0]
 *   @0x1bf9a4 cmp r3, #7
 *   @0x1bf9a8 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bf9ac ldr r2, [r0, #0x20]
 *   @0x1bf9b0 vmov s15, r2
 *   @0x1bf9b4 vcvt.f64.s32 d7, s15
 *   @0x1bf9b8 vmov r2, r3, d7
 *   @0x1bf9bc stm r5, {r2, r3}
 *   @0x1bf9c0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bf9c4 andseq pc, r8, r8, asr #21
 *
 * ══ §196/197 F_LayerInstanceGetInstance(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bff94  size 148  37 条（0x1bff94..0x1c0028）
 * @func 0x1bff94 0x1c0028  size 148  37 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x18×1 / 0x5c×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bff94 cmp r3, #1
 *   @0x1bff98 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bff9c mov r3, #0
 *   @0x1bffa0 mov r4, r3
 *   @0x1bffa4 mov r5, r0
 *   @0x1bffa8 movt r3, #0xc010
 *   @0x1bffac str r4, [r0, #0xc]
 *   @0x1bffb0 str r3, [r0, #0x4]
 *   @0x1bffb4 str r4, [r0]
 *   @0x1bffb8 ldr r6, [sp, #0x18]
 *   @0x1bffbc beq 0x1bffd4 <_Z26F_LayerInstanceGetInstanceR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bffc0 ldr r0, [pc, #0x5c]
 *   @0x1bffc4 mov r1, r4
 *   @0x1bffc8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bffcc add r0, pc, r0
 *   @0x1bffd0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bffd4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bffd8 mov r1, r4
 *   @0x1bffdc mov r7, r0
 *   @0x1bffe0 mov r0, r6
 *   @0x1bffe4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bffe8 mov r2, r4
 *   @0x1bffec mov r1, r0
 *   @0x1bfff0 mov r0, r7
 *   @0x1bfff4 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bfff8 cmp r0, #0
 *   @0x1bfffc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1c0000 ldr r3, [r0]
 *   @0x1c0004 cmp r3, #2
 *   @0x1c0008 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1c000c ldr r2, [r0, #0x1c]
 *   @0x1c0010 vmov s15, r2
 *   @0x1c0014 vcvt.f64.s32 d7, s15
 *   @0x1c0018 vmov r2, r3, d7
 *   @0x1c001c stm r5, {r2, r3}
 *   @0x1c0020 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c0024 andseq pc, r8, r4, lsl #13
 *
 * ══ §197/197 tagIConsole::~tagIConsole()  0xc4370  size 24  6 条（0xc4370..0xc4388）
 * @func 0xc4370 0xc4388  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4370 ldr r3, [pc, #0xc]
 *   @0xc4374 ldr r3, [pc, r3]
 *   @0xc4378 add r3, r3, #8
 *   @0xc437c str r3, [r0]
 *   @0xc4380 bx lr
 *   @0xc4384 eorseq r9, r2, r12, ror #11
 */
