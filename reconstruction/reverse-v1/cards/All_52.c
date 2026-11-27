/* cally 逆向卡：All_52 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 127 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/127 png_handle_oFFs  0x2ad030  size 248  62 条（0x2ad030..0x2ad128）
 * @func 0x2ad030 0x2ad128  size 248  62 条
 * 部分覆盖: 本节 62/106 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_error / png_warning / png_crc_finish / 0xfe6ec894 / 0x42c518
 * 字段偏移 top8: 0xe0×1 / 0x14×1 / 0xc4×1 / 0xb0×1 / 0x9c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ad030 ldr r3, [pc, #0xe0]
 *   @0x2ad034 add r3, pc
 *   @0x2ad038 mov r5, r2
 *   @0x2ad03c ldr r2, [r3]
 *   @0x2ad040 mov r6, r1
 *   @0x2ad044 str r2, [sp, #0x14]
 *   @0x2ad048 .word 0xf012212c
 *   @0x2ad04c .word 0xd1040f01
 *   @0x2ad050 ldr r1, [pc, #0xc4]
 *   @0x2ad054 bl 0x2a642c <png_error>
 *   @0x2ad058 b 0x2ad07e <png_handle_oFFs+0x4e>
 *   @0x2ad05c bpl 0x2ad064 <png_handle_oFFs+0x34>
 *   @0x2ad060 add r1, pc
 *   @0x2ad064 cbz r1, 0x2ad07e <png_handle_oFFs+0x4e>
 *   @0x2ad068 lsls r3, r3, #0x17
 *   @0x2ad06c ldr r1, [pc, #0xb0]
 *   @0x2ad070 bl 0x2a6474 <png_warning>
 *   @0x2ad074 mov r0, r4
 *   @0x2ad078 bl 0x2abc94 <png_crc_finish>
 *   @0x2ad07c b 0x2ad102 <png_handle_oFFs+0xd2>
 *   @0x2ad080 mov r0, r4
 *   @0x2ad084 ldr r1, [pc, #0x9c]
 *   @0x2ad088 b 0x2ad070 <png_handle_oFFs+0x40>
 *   @0x2ad08c mov r2, r5
 *   @0x2ad090 .word 0x4620fdbd
 *   @0x2ad094 movs r1, #0x0
 *   @0x2ad098 bllt 0xfe6ec894 <b2_toiTime+0xfffffffffdf933f0>
 *   @0x2ad09c ldrb.w r2, [sp, #0x8]
 *   @0x2ad0a0 ldrb.w r0, [sp, #0x9]
 *   @0x2ad0a4 tst.w r2, #0x80
 *   @0x2ad0a8 ldrb.w r1, [sp, #0xb]
 *   @0x2ad0ac lsl.w r2, r2, #0x18
 *   @0x2ad0b0 ldrb.w r3, [sp, #0xa]
 *   @0x2ad0b4 add.w r2, r2, r0, lsl #16
 *   @0x2ad0b8 add r2, r1
 *   @0x2ad0bc andle r2, r3, r3, lsl #4
 *   @0x2ad0c0 rsbs r2, r2, #0
 *   @0x2ad0c4 subsmi r4, r2, #0, #4
 *   @0x2ad0c8 ldrb.w r3, [sp, #0xc]
 *   @0x2ad0cc ldrb.w r5, [sp, #0xd]
 *   @0x2ad0d0 tst.w r3, #0x80
 *   @0x2ad0d4 ldrb.w r0, [sp, #0xf]
 *   @0x2ad0d8 lsl.w r3, r3, #0x18
 *   @0x2ad0dc ldrb.w r1, [sp, #0xe]
 *   @0x2ad0e0 add.w r3, r3, r5, lsl #16
 *   @0x2ad0e4 add r3, r0
 *   @0x2ad0e8 andle r2, r3, r1, lsl #6
 *   @0x2ad0ec rsbs r3, r3, #0
 *   @0x2ad0f0 subsmi r4, r11, #0, #6
 *   @0x2ad0f4 ldrb.w r1, [sp, #0x10]
 *   @0x2ad0f8 mov r0, r4
 *   @0x2ad0fc mov r1, r6
 *   @0x2ad100 bls 0x42c518 <g_RomDisk+0x34cf8>
 *   @0x2ad104 ldr r3, [r7]
 *   @0x2ad108 beq 0x2ad10e <png_handle_oFFs+0xde>
 *   @0x2ad10c andlt lr, r7, r4, ror #20
 *   @0x2ad110 pop {r4, r5, r6, r7, pc}
 *   @0x2ad114 lsrs r0, r4, #0x4
 *   @0x2ad118 lsls r5, r2, #0x11
 *   @0x2ad11c lsls r0, r4, #0x11
 *   @0x2ad120 lsls r2, r5, #0x11
 *   @0x2ad124 lsls r7, r4, #0x11
 *
 * ══ §2/127 b2ClipSegmentToLine(b2ClipVertex*, b2ClipVertex const*, b2Vec2 const&, float, int)  0x2c39c4  size 248  62 条（0x2c39c4..0x2c3abc）
 * @func 0x2c39c4 0x2c3abc  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ClipSegmentToLine(b2ClipVertex*, b2ClipVertex const*, b2Vec2 const&, float, int)+0xdc
 * 字段偏移 top8: 0x8×2 / 0x9×2 / 0xa×1 / 0xb×1
 * VFP 指令 32 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c39c4 vldr s15, [r2, #4]
 *   @0x2c39c8 vldr s14, [r1, #4]
 *   @0x2c39cc vmul.f32 s14, s15, s14
 *   @0x2c39d0 vldr s10, [r1, #16]
 *   @0x2c39d4 vldr s12, [r2]
 *   @0x2c39d8 vldr s9, [r1]
 *   @0x2c39dc vldr s11, [r1, #12]
 *   @0x2c39e0 vmov s13, r3
 *   @0x2c39e4 push {r4, r5}
 *   @0x2c39e8 mov r12, r1
 *   @0x2c39ec mov r4, r0
 *   @0x2c39f0 vmul.f32 s15, s15, s10
 *   @0x2c39f4 vmla.f32 s14, s12, s9
 *   @0x2c39f8 vmla.f32 s15, s12, s11
 *   @0x2c39fc vsub.f32 s14, s14, s13
 *   @0x2c3a00 vsub.f32 s15, s15, s13
 *   @0x2c3a04 vcmpe.f32 s14, #0
 *   @0x2c3a08 vmrs APSR_nzcv, fpscr
 *   @0x2c3a0c ldmls r1, {r0, r1, r2}
 *   @0x2c3a10 vcmpe.f32 s15, #0
 *   @0x2c3a14 movls r3, #1
 *   @0x2c3a18 movhi r3, #0
 *   @0x2c3a1c stmls r4, {r0, r1, r2}
 *   @0x2c3a20 vmrs APSR_nzcv, fpscr
 *   @0x2c3a24 bls 0x2c3aa0 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi+0xdc>
 *   @0x2c3a28 vmul.f32 s13, s14, s15
 *   @0x2c3a2c vcmpe.f32 s13, #0
 *   @0x2c3a30 vmrs APSR_nzcv, fpscr
 *   @0x2c3a34 bpl 0x2c3a94 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi+0xd0>
 *   @0x2c3a38 vsub.f32 s15, s14, s15
 *   @0x2c3a3c vldr s12, [r12, #4]
 *   @0x2c3a40 vldr s13, [r12]
 *   @0x2c3a44 vldr s11, [r12, #16]
 *   @0x2c3a48 vldr s10, [r12, #12]
 *   @0x2c3a4c add r0, r3, r3, lsl #1
 *   @0x2c3a50 ldr r2, [sp, #0x8]
 *   @0x2c3a54 add r3, r3, #1
 *   @0x2c3a58 add r0, r4, r0, lsl #2
 *   @0x2c3a5c mov r5, #0
 *   @0x2c3a60 mov r1, #1
 *   @0x2c3a64 strb r2, [r0, #0x8]
 *   @0x2c3a68 vdiv.f32 s14, s14, s15
 *   @0x2c3a6c vsub.f32 s11, s11, s12
 *   @0x2c3a70 vsub.f32 s15, s10, s13
 *   @0x2c3a74 vmla.f32 s12, s14, s11
 *   @0x2c3a78 vmla.f32 s13, s14, s15
 *   @0x2c3a7c vstr s12, [r0, #4]
 *   @0x2c3a80 vstr s13, [r0]
 *   @0x2c3a84 ldrb r2, [r12, #0x9]
 *   @0x2c3a88 strb r5, [r0, #0xa]
 *   @0x2c3a8c strb r1, [r0, #0xb]
 *   @0x2c3a90 strb r2, [r0, #0x9]
 *   @0x2c3a94 mov r0, r3
 *   @0x2c3a98 pop {r4, r5}
 *   @0x2c3a9c bx lr
 *   @0x2c3aa0 add r2, r12, #12
 *   @0x2c3aa4 add r5, r3, r3, lsl #1
 *   @0x2c3aa8 add r3, r3, #1
 *   @0x2c3aac ldm r2, {r0, r1, r2}
 *   @0x2c3ab0 add r5, r4, r5, lsl #2
 *   @0x2c3ab4 stm r5, {r0, r1, r2}
 *   @0x2c3ab8 b 0x2c3a28 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi+0x64>
 *
 * ══ §3/127 FT_GlyphLoader_CheckPoints  0x2e8106  size 248  62 条（0x2e8106..0x2e81fe）
 * @func 0x2e8106 0x2e81fe  size 248  62 条
 * 部分覆盖: 本节 62/110 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_realloc×2 / FT_GlyphLoader_CheckPoints+0xa2 / FT_GlyphLoader_CheckPoints+0x32 / 0x3e7fd2 / 0x3e7f9a / 0xb6694 / 0x3e70a2 / FT_GlyphLoader_Reset
 * 字段偏移 top8: 0xc×4 / 0x28×2 / 0x4×2 / 0x18×1 / 0x10×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8106 push.w {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2e810a mov r9, r2
 *   @0x2e810e addlt r5, r5, r10, lsr r0
 *   @0x2e8112 ldrsh.w r2, [r0, #0x16]
 *   @0x2e8116 movs r3, #0x0
 *   @0x2e811a mov r4, r0
 *   @0x2e811e ldr r7, [r0]
 *   @0x2e8122 str r3, [sp, #0xc]
 *   @0x2e8126 bls 0x2e81a8 <FT_GlyphLoader_CheckPoints+0xa2>
 *   @0x2e812a bic r5, r5, #0x7
 *   @0x2e812e cmp.w r5, #0x8000
 *   @0x2e8132 blo 0x2e8138 <FT_GlyphLoader_CheckPoints+0x32>
 *   @0x2e8136 b 0x2e81f8 <FT_GlyphLoader_CheckPoints+0xf2>
 *   @0x2e813a add.w r8, sp, #0xc
 *   @0x2e813e mov r0, r7
 *   @0x2e8142 .word 0x21088004
 *   @0x2e8146 mov r2, r6
 *   @0x2e814a mov r3, r5
 *   @0x2e814e blls 0x3e7fd2 <error_g0017+0x40c76>
 *   @0x2e8152 str r0, [r4, #0x18]
 *   @0x2e8156 bne 0x2e81ec <FT_GlyphLoader_CheckPoints+0xe6>
 *   @0x2e815a mov r0, r7
 *   @0x2e815e mov r2, r6
 *   @0x2e8162 strtmi r0, [r11], -r8, lsl #2
 *   @0x2e8166 bl 0x2e808e <ft_mem_realloc>
 *   @0x2e816a ldr r3, [sp, #0xc]
 *   @0x2e816e cmp r3, #0x0
 *   @0x2e8172 ldrb r3, [r4, #0x10]
 *   @0x2e8176 ldr r3, [r4, #0x28]
 *   @0x2e817a mov r0, r7
 *   @0x2e817e stm.w sp, {r3, r8}
 *   @0x2e8182 lsls r3, r5, #0x1
 *   @0x2e8186 blls 0x3e7f9a <error_g0017+0x40c3e>
 *   @0x2e818a mov r1, r0
 *   @0x2e818e cbnz r3, 0x2e81ec <FT_GlyphLoader_CheckPoints+0xe6>
 *   @0x2e8192 rscseq r0, r2, r5, asr #17
 *   @0x2e8196 add r0, r8
 *   @0x2e819a blx 0xb6694 <memmove@plt>
 *   @0x2e819e ldr r3, [r4, #0x28]
 *   @0x2e81a2 str r3, [r4, #0x2c]
 *   @0x2e81a6 str r5, [r4, #0x4]
 *   @0x2e81aa rfeib r4!
 *   @0x2e81ae stmvs r2!, {r2, r4, r12}
 *   @0x2e81b2 add r5, r1
 *   @0x2e81b6 cmp r9, r2
 *   @0x2e81ba add.w r9, r9, #0x3
 *   @0x2e81be bic r5, r9, #0x3
 *   @0x2e81c2 cmp.w r5, #0x8000
 *   @0x2e81c6 bhs 0x2e8134 <FT_GlyphLoader_CheckPoints+0x2e>
 *   @0x2e81ca mov r0, r7
 *   @0x2e81ce str r3, [sp]
 *   @0x2e81d2 str r3, [sp, #0x4]
 *   @0x2e81d6 bl 0x2e808e <ft_mem_realloc>
 *   @0x2e81da ldr r3, [sp, #0xc]
 *   @0x2e81de cbnz r3, 0x2e81ec <FT_GlyphLoader_CheckPoints+0xe6>
 *   @0x2e81e2 b 0x2e81e6 <FT_GlyphLoader_CheckPoints+0xe0>
 *   @0x2e81e6 mov r0, r4
 *   @0x2e81ea blls 0x3e70a2 <error_g0017+0x3fd46>
 *   @0x2e81ee cbz r3, 0x2e81f6 <FT_GlyphLoader_CheckPoints+0xf0>
 *   @0x2e81f2 bl 0x2e7340 <FT_GlyphLoader_Reset>
 *   @0x2e81f6 ldr r0, [sp, #0xc]
 *   @0x2e81fa pop.w {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §4/127 FT_Bitmap_Copy  0x3149d8  size 248  62 条（0x3149d8..0x314ad0）
 * @func 0x3149d8 0x314ad0  size 248  62 条
 * 部分覆盖: 本节 62/116 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xfedb35e0 / ft_mem_qrealloc / 0xb65bc
 * 字段偏移 top8: 0xc×4 / 0x8×2 / 0x4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3149d8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x3149dc sub sp, #0x14
 *   @0x3149e0 mov r5, r1
 *   @0x3149e4 str r3, [sp, #0xc]
 *   @0x3149e8 beq 0x314ac4 <FT_Bitmap_Copy+0xec>
 *   @0x3149ec beq 0x314ac8 <FT_Bitmap_Copy+0xf0>
 *   @0x3149f0 beq 0x314ac8 <FT_Bitmap_Copy+0xf0>
 *   @0x3149f4 bne 0x3149fa <FT_Bitmap_Copy+0x22>
 *   @0x3149f8 b 0x314aca <FT_Bitmap_Copy+0xf2>
 *   @0x3149fc ldr r2, [r2, #0x8]
 *   @0x314a00 svchs #0xc00c
 *   @0x314a04 ite ge
 *   @0x314a08 .word 0xf04f0901
 *   @0x314a0c bhs 0x323210
 *   @0x314a10 ite ge
 *   @0x314a14 .word 0xf04f0801
 *   @0x314a18 .word 0xf1bc38ff
 *   @0x314a1c .word 0xd10b0f00
 *   @0x314a20 ldm r5!, {r0, r1, r2, r3}
 *   @0x314a24 cmp r9, r8
 *   @0x314a28 ldm.w r5, {r0, r1}
 *   @0x314a2c stm.w r6, {r0, r1}
 *   @0x314a30 beq 0x3149f6 <FT_Bitmap_Copy+0x1e>
 *   @0x314a34 str r7, [r4, #0x8]
 *   @0x314a38 ldr r3, [r1]
 *   @0x314a3c bl 0xfedb35e0 <b2_toiTime+0xfffffffffe65a13c>
 *   @0x314a40 stmdavs r0, {r0, r1, r2, r5, r6, r7, r9, r11, r12, sp, lr}
 *   @0x314a44 mul r11, r3, r10
 *   @0x314a48 ldr r3, [r4, #0xc]
 *   @0x314a4c ldr r1, [r4]
 *   @0x314a50 it lt
 *   @0x314a54 muls r2, r1, r2
 *   @0x314a58 beq 0x314a74 <FT_Bitmap_Copy+0x9c>
 *   @0x314a5c movs r1, #0x1
 *   @0x314a60 str r3, [sp, #0x4]
 *   @0x314a64 bl 0x2e8010 <ft_mem_qrealloc>
 *   @0x314a68 b 0x314a72 <FT_Bitmap_Copy+0x9a>
 *   @0x314a6c add r2, sp, #0xc
 *   @0x314a70 rscvs pc, r0, r7, asr #22
 *   @0x314a74 ldr r3, [sp, #0xc]
 *   @0x314a78 mov r7, r5
 *   @0x314a7c ldm r7!, {r0, r1, r2, r3}
 *   @0x314a80 ldr.w r12, [r4, #0xc]
 *   @0x314a84 stm r6!, {r0, r1, r2, r3}
 *   @0x314a88 stm r6, {r0, r1}
 *   @0x314a8c .word 0xf8c40003
 *   @0x314a90 stmvs r9!, {r2, r3, lr, pc} ^
 *   @0x314a94 bne 0x314aa0 <FT_Bitmap_Copy+0xc8>
 *   @0x314a98 mov r2, r11
 *   @0x314a9c mul pc, r0, sp
 *   @0x314aa0 ldr r4, [r4]
 *   @0x314aa4 subs r3, r4, #0x1
 *   @0x314aa8 mrslt r12, spsr
 *   @0x314aac mov r0, r12
 *   @0x314ab0 mov r2, r10
 *   @0x314ab4 blx 0xb65bc <memcpy@plt>
 *   @0x314ab8 subs r4, #0x1
 *   @0x314abc ldrb r0, [r4, r0, lsl #24]!
 *   @0x314ac0 ldr r0, [sp, #0xc]
 *   @0x314ac4 movs r0, #0x21
 *   @0x314ac8 movs r0, #0x6
 *   @0x314acc pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §5/127 F_BUFFER_GetSurface(RValue&, CInstance*, CInstance*, int, RValue*)  0xc6154  size 244  61 条（0xc6154..0xc6248）
 * @func 0xc6154 0xc6248  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_BUFFER_GetSurface(RValue&, CInstance*, CInstance*, int, RValue*)+0xbc / GR_Surface_Exists(int)
 * 字段偏移 top8: 0x28×2 / 0x4×2 / 0x2×2 / 0xc0×1 / 0x40×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6154 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xc6158 sub sp, sp, #12
 *   @0xc615c mov r1, #0
 *   @0xc6160 ldr r4, [sp, #0x28]
 *   @0xc6164 mov r0, r4
 *   @0xc6168 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc616c subs r5, r0, #0
 *   @0xc6170 blt 0xc6210 <_Z19F_BUFFER_GetSurfaceR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0xc6174 ldr r6, [pc, #0xc0]
 *   @0xc6178 add r6, pc, r6
 *   @0xc617c ldr r3, [r6]
 *   @0xc6180 cmp r5, r3
 *   @0xc6184 bge 0xc6210 <_Z19F_BUFFER_GetSurfaceR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0xc6188 ldr r3, [r6, #0x4]
 *   @0xc618c ldr r3, [r3, r5, lsl #2]
 *   @0xc6190 cmp r3, #0
 *   @0xc6194 beq 0xc6210 <_Z19F_BUFFER_GetSurfaceR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0xc6198 mov r1, #1
 *   @0xc619c mov r0, r4
 *   @0xc61a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc61a4 mov r7, r0
 *   @0xc61a8 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0xc61ac subs r1, r0, #0
 *   @0xc61b0 beq 0xc6228 <_Z19F_BUFFER_GetSurfaceR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0xc61b4 ldr r3, [r6, #0x4]
 *   @0xc61b8 mov r0, r4
 *   @0xc61bc mov r1, #2
 *   @0xc61c0 ldr r5, [r3, r5, lsl #2]
 *   @0xc61c4 ldr r3, [r5]
 *   @0xc61c8 ldr r6, [r3, #0x40]
 *   @0xc61cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc61d0 mov r1, #3
 *   @0xc61d4 mov r9, r0
 *   @0xc61d8 mov r0, r4
 *   @0xc61dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc61e0 mov r1, #4
 *   @0xc61e4 mov r8, r0
 *   @0xc61e8 mov r0, r4
 *   @0xc61ec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc61f0 mov r2, r9
 *   @0xc61f4 mov r3, r8
 *   @0xc61f8 mov r1, r7
 *   @0xc61fc str r0, [sp]
 *   @0xc6200 mov r0, r5
 *   @0xc6204 blx r6
 *   @0xc6208 add sp, sp, #12
 *   @0xc620c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xc6210 ldr r0, [pc, #0x28]
 *   @0xc6214 mov r1, #0
 *   @0xc6218 add r0, pc, r0
 *   @0xc621c add sp, sp, #12
 *   @0xc6220 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xc6224 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6228 ldr r0, [pc, #0x14]
 *   @0xc622c add r0, pc, r0
 *   @0xc6230 add sp, sp, #12
 *   @0xc6234 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xc6238 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc623c mlaseq r11, r12, pc, r3
 *   @0xc6240 eoreq r10, r6, r12, lsr r11
 *   @0xc6244 eoreq r10, r6, r12, asr r11
 *
 * ══ §6/127 YYGML_vertex_position_3d(int, float, float, float)  0xc97e4  size 244  61 条（0xc97e4..0xc98d8）
 * @func 0xc97e4 0xc98d8  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_vertex_position_3d(int, float, float, float)+0xcc / YYGML_vertex_position_3d(int, float, float, float)+0x94 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGML_vertex_position_3d(int, float, float, float)+0x1c
 * 字段偏移 top8: 0x4×4 / 0xc×3 / 0x14×2 / 0x10×2 / 0xc4×1 / 0x2×1 / 0x2c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc97e4 cmp r0, #0
 *   @0xc97e8 push {r4, r5, r6, r7, r8, lr}
 *   @0xc97ec mov r8, r1
 *   @0xc97f0 sub sp, sp, #8
 *   @0xc97f4 mov r7, r2
 *   @0xc97f8 mov r6, r3
 *   @0xc97fc blt 0xc98b0 <_Z24YYGML_vertex_position_3difff+0xcc>
 *   @0xc9800 ldr r3, [pc, #0xc4]
 *   @0xc9804 add r3, pc, r3
 *   @0xc9808 ldr r3, [r3]
 *   @0xc980c ldr r4, [r3, r0, lsl #2]
 *   @0xc9810 ldr r3, [r4, #0x2c]
 *   @0xc9814 ldr r12, [r4, #0xc]
 *   @0xc9818 ldr r5, [r4, #0x4]
 *   @0xc981c ldr r0, [r3, #0x14]
 *   @0xc9820 add r3, r0, r12
 *   @0xc9824 cmp r5, r3
 *   @0xc9828 blo 0xc9878 <_Z24YYGML_vertex_position_3difff+0x94>
 *   @0xc982c ldr r3, [r4]
 *   @0xc9830 ldr r1, [r4, #0x10]
 *   @0xc9834 add r0, r3, r12
 *   @0xc9838 ldr r3, [r4, #0x14]
 *   @0xc983c add r12, r12, #12
 *   @0xc9840 add r1, r1, #1
 *   @0xc9844 str r8, [r0]
 *   @0xc9848 cmp r1, r3
 *   @0xc984c str r7, [r0, #0x4]
 *   @0xc9850 str r6, [r0, #0x8]
 *   @0xc9854 ldrhs r3, [r4, #0x1c]
 *   @0xc9858 movhs r2, #0
 *   @0xc985c str r1, [r4, #0x10]
 *   @0xc9860 addhs r3, r3, #1
 *   @0xc9864 str r12, [r4, #0xc]
 *   @0xc9868 strhs r2, [r4, #0x10]
 *   @0xc986c strhs r3, [r4, #0x1c]
 *   @0xc9870 add sp, sp, #8
 *   @0xc9874 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc9878 add r1, r0, r5
 *   @0xc987c mov r2, #0
 *   @0xc9880 ldr r0, [r4]
 *   @0xc9884 add r1, r1, r5, lsr #1
 *   @0xc9888 str r1, [r4, #0x4]
 *   @0xc988c mov r3, #74
 *   @0xc9890 str r2, [sp]
 *   @0xc9894 ldr r2, [pc, #0x34]
 *   @0xc9898 add r2, pc, r2
 *   @0xc989c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc98a0 ldr r12, [r4, #0xc]
 *   @0xc98a4 mov r3, r0
 *   @0xc98a8 str r0, [r4]
 *   @0xc98ac b 0xc9830 <_Z24YYGML_vertex_position_3difff+0x4c>
 *   @0xc98b0 ldr r3, [pc, #0x1c]
 *   @0xc98b4 add r3, pc, r3
 *   @0xc98b8 ldr r3, [r3, #0x4]
 *   @0xc98bc cmp r0, r3
 *   @0xc98c0 blt 0xc9800 <_Z24YYGML_vertex_position_3difff+0x1c>
 *   @0xc98c4 add sp, sp, #8
 *   @0xc98c8 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc98cc eorseq r0, r11, r0, lsr r9
 *   @0xc98d0 mlaeq r6, r8, r7, r7
 *   @0xc98d4 eorseq r0, r11, r0, lsl #17
 *
 * ══ §7/127 YYGML_vertex_normal(int, float, float, float)  0xc9bec  size 244  61 条（0xc9bec..0xc9ce0）
 * @func 0xc9bec 0xc9cf4  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_vertex_normal(int, float, float, float)+0xcc / YYGML_vertex_normal(int, float, float, float)+0x94 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGML_vertex_normal(int, float, float, float)+0x1c
 * 字段偏移 top8: 0x4×4 / 0xc×3 / 0x14×2 / 0x10×2 / 0xc4×1 / 0x2×1 / 0x2c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9bec cmp r0, #0
 *   @0xc9bf0 push {r4, r5, r6, r7, r8, lr}
 *   @0xc9bf4 mov r8, r1
 *   @0xc9bf8 sub sp, sp, #8
 *   @0xc9bfc mov r7, r2
 *   @0xc9c00 mov r6, r3
 *   @0xc9c04 blt 0xc9cb8 <_Z19YYGML_vertex_normalifff+0xcc>
 *   @0xc9c08 ldr r3, [pc, #0xc4]
 *   @0xc9c0c add r3, pc, r3
 *   @0xc9c10 ldr r3, [r3]
 *   @0xc9c14 ldr r4, [r3, r0, lsl #2]
 *   @0xc9c18 ldr r3, [r4, #0x2c]
 *   @0xc9c1c ldr r12, [r4, #0xc]
 *   @0xc9c20 ldr r5, [r4, #0x4]
 *   @0xc9c24 ldr r0, [r3, #0x14]
 *   @0xc9c28 add r3, r0, r12
 *   @0xc9c2c cmp r5, r3
 *   @0xc9c30 blo 0xc9c80 <_Z19YYGML_vertex_normalifff+0x94>
 *   @0xc9c34 ldr r3, [r4]
 *   @0xc9c38 ldr r1, [r4, #0x10]
 *   @0xc9c3c add r0, r3, r12
 *   @0xc9c40 ldr r3, [r4, #0x14]
 *   @0xc9c44 add r12, r12, #12
 *   @0xc9c48 add r1, r1, #1
 *   @0xc9c4c str r8, [r0]
 *   @0xc9c50 cmp r1, r3
 *   @0xc9c54 str r7, [r0, #0x4]
 *   @0xc9c58 str r6, [r0, #0x8]
 *   @0xc9c5c ldrhs r3, [r4, #0x1c]
 *   @0xc9c60 movhs r2, #0
 *   @0xc9c64 str r1, [r4, #0x10]
 *   @0xc9c68 addhs r3, r3, #1
 *   @0xc9c6c str r12, [r4, #0xc]
 *   @0xc9c70 strhs r2, [r4, #0x10]
 *   @0xc9c74 strhs r3, [r4, #0x1c]
 *   @0xc9c78 add sp, sp, #8
 *   @0xc9c7c pop {r4, r5, r6, r7, r8, pc}
 *   @0xc9c80 add r1, r0, r5
 *   @0xc9c84 mov r2, #0
 *   @0xc9c88 ldr r0, [r4]
 *   @0xc9c8c add r1, r1, r5, lsr #1
 *   @0xc9c90 str r1, [r4, #0x4]
 *   @0xc9c94 mov r3, #74
 *   @0xc9c98 str r2, [sp]
 *   @0xc9c9c ldr r2, [pc, #0x34]
 *   @0xc9ca0 add r2, pc, r2
 *   @0xc9ca4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc9ca8 ldr r12, [r4, #0xc]
 *   @0xc9cac mov r3, r0
 *   @0xc9cb0 str r0, [r4]
 *   @0xc9cb4 b 0xc9c38 <_Z19YYGML_vertex_normalifff+0x4c>
 *   @0xc9cb8 ldr r3, [pc, #0x1c]
 *   @0xc9cbc add r3, pc, r3
 *   @0xc9cc0 ldr r3, [r3, #0x4]
 *   @0xc9cc4 cmp r0, r3
 *   @0xc9cc8 blt 0xc9c08 <_Z19YYGML_vertex_normalifff+0x1c>
 *   @0xc9ccc add sp, sp, #8
 *   @0xc9cd0 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc9cd4 eorseq r0, r11, r8, lsr #10
 *   @0xc9cd8 mlaeq r6, r0, r3, r7
 *   @0xc9cdc eorseq r0, r11, r8, ror r4
 *
 * ══ §8/127 YYGML_vertex_float3(int, float, float, float)  0xc9eb0  size 244  61 条（0xc9eb0..0xc9fa4）
 * @func 0xc9eb0 0xc9fa4  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_vertex_float3(int, float, float, float)+0xcc / YYGML_vertex_float3(int, float, float, float)+0x94 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGML_vertex_float3(int, float, float, float)+0x1c
 * 字段偏移 top8: 0x4×4 / 0xc×3 / 0x14×2 / 0x10×2 / 0xc4×1 / 0x2×1 / 0x2c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9eb0 cmp r0, #0
 *   @0xc9eb4 push {r4, r5, r6, r7, r8, lr}
 *   @0xc9eb8 mov r8, r1
 *   @0xc9ebc sub sp, sp, #8
 *   @0xc9ec0 mov r7, r2
 *   @0xc9ec4 mov r6, r3
 *   @0xc9ec8 blt 0xc9f7c <_Z19YYGML_vertex_float3ifff+0xcc>
 *   @0xc9ecc ldr r3, [pc, #0xc4]
 *   @0xc9ed0 add r3, pc, r3
 *   @0xc9ed4 ldr r3, [r3]
 *   @0xc9ed8 ldr r4, [r3, r0, lsl #2]
 *   @0xc9edc ldr r3, [r4, #0x2c]
 *   @0xc9ee0 ldr r12, [r4, #0xc]
 *   @0xc9ee4 ldr r5, [r4, #0x4]
 *   @0xc9ee8 ldr r0, [r3, #0x14]
 *   @0xc9eec add r3, r0, r12
 *   @0xc9ef0 cmp r5, r3
 *   @0xc9ef4 blo 0xc9f44 <_Z19YYGML_vertex_float3ifff+0x94>
 *   @0xc9ef8 ldr r3, [r4]
 *   @0xc9efc ldr r1, [r4, #0x10]
 *   @0xc9f00 add r0, r3, r12
 *   @0xc9f04 ldr r3, [r4, #0x14]
 *   @0xc9f08 add r12, r12, #12
 *   @0xc9f0c add r1, r1, #1
 *   @0xc9f10 str r8, [r0]
 *   @0xc9f14 cmp r1, r3
 *   @0xc9f18 str r7, [r0, #0x4]
 *   @0xc9f1c str r6, [r0, #0x8]
 *   @0xc9f20 ldrhs r3, [r4, #0x1c]
 *   @0xc9f24 movhs r2, #0
 *   @0xc9f28 str r1, [r4, #0x10]
 *   @0xc9f2c addhs r3, r3, #1
 *   @0xc9f30 str r12, [r4, #0xc]
 *   @0xc9f34 strhs r2, [r4, #0x10]
 *   @0xc9f38 strhs r3, [r4, #0x1c]
 *   @0xc9f3c add sp, sp, #8
 *   @0xc9f40 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc9f44 add r1, r0, r5
 *   @0xc9f48 mov r2, #0
 *   @0xc9f4c ldr r0, [r4]
 *   @0xc9f50 add r1, r1, r5, lsr #1
 *   @0xc9f54 str r1, [r4, #0x4]
 *   @0xc9f58 mov r3, #74
 *   @0xc9f5c str r2, [sp]
 *   @0xc9f60 ldr r2, [pc, #0x34]
 *   @0xc9f64 add r2, pc, r2
 *   @0xc9f68 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc9f6c ldr r12, [r4, #0xc]
 *   @0xc9f70 mov r3, r0
 *   @0xc9f74 str r0, [r4]
 *   @0xc9f78 b 0xc9efc <_Z19YYGML_vertex_float3ifff+0x4c>
 *   @0xc9f7c ldr r3, [pc, #0x1c]
 *   @0xc9f80 add r3, pc, r3
 *   @0xc9f84 ldr r3, [r3, #0x4]
 *   @0xc9f88 cmp r0, r3
 *   @0xc9f8c blt 0xc9ecc <_Z19YYGML_vertex_float3ifff+0x1c>
 *   @0xc9f90 add sp, sp, #8
 *   @0xc9f94 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc9f98 eorseq r0, r11, r4, ror #4
 *   @0xc9f9c eoreq r7, r6, r12, asr #1
 *   @0xc9fa0 ldrhteq r0, [r11], -r4
 *
 * ══ §9/127 FreeAllObjects()  0xd675c  size 244  61 条（0xd675c..0xd6850）
 * @func 0xd675c 0xd6850  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd6764→0x47f295, 0xd677c→0x3f5050, 0xd6784→0x536f0c, 0xd67dc→0x544be0, 0xd67e4→0x756450, 0xd67ec→0x756454, 0xd67f8→0x544bdc, 0xd67fc→0x3f7420
 * 调用序列: FreeAllObjects()+0x80 / FreeAllObjects()+0x3c / YYObjectBase::Free(YYObjectBase*)
 * 字段偏移 top8: 0xc4×2 / 0x8×2 / 0x48×2 / 0xb0×1 / 0xac×1 / 0x4×1 / 0x2×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd675c push {r4, r5, r6, r7, r8, lr}
 *   @0xd6760 ldr r7, [pc, #0xc4]
 *   @0xd6764 ldr r3, [pc, #0xc4]
 *   @0xd6768 add r7, pc, r7
 *   @0xd676c ldr r3, [r7, r3]
 *   @0xd6770 ldrb r3, [r3]
 *   @0xd6774 cmp r3, #0
 *   @0xd6778 popeq {r4, r5, r6, r7, r8, pc}
 *   @0xd677c ldr r1, [pc, #0xb0]
 *   @0xd6780 mov r2, #0
 *   @0xd6784 ldr r3, [pc, #0xac]
 *   @0xd6788 ldr r8, [r7, r1]
 *   @0xd678c strb r2, [r8]
 *   @0xd6790 ldr r5, [r7, r3]
 *   @0xd6794 ldr r3, [r5, #0x8]
 *   @0xd6798 cmp r3, #0
 *   @0xd679c ble 0xd67dc <_Z14FreeAllObjectsv+0x80>
 *   @0xd67a0 ldr r6, [r5, #0x4]
 *   @0xd67a4 cmp r6, #0
 *   @0xd67a8 ble 0xd6798 <_Z14FreeAllObjectsv+0x3c>
 *   @0xd67ac mov r4, #0
 *   @0xd67b0 ldr r3, [r5]
 *   @0xd67b4 ldr r0, [r3, r4, lsl #2]
 *   @0xd67b8 add r4, r4, #1
 *   @0xd67bc cmp r0, #0
 *   @0xd67c0 beq 0xd67c8 <_Z14FreeAllObjectsv+0x6c>
 *   @0xd67c4 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_>
 *   @0xd67c8 cmp r4, r6
 *   @0xd67cc bne 0xd67b0 <_Z14FreeAllObjectsv+0x54>
 *   @0xd67d0 ldr r3, [r5, #0x8]
 *   @0xd67d4 cmp r3, #0
 *   @0xd67d8 bgt 0xd67a0 <_Z14FreeAllObjectsv+0x44>
 *   @0xd67dc ldr r0, [pc, #0x58]
 *   @0xd67e0 mov r3, #0
 *   @0xd67e4 ldr r5, [pc, #0x54]
 *   @0xd67e8 mvn r2, #0
 *   @0xd67ec ldr r4, [pc, #0x50]
 *   @0xd67f0 mov r1, #1
 *   @0xd67f4 ldr r6, [r7, r0]
 *   @0xd67f8 ldr r12, [pc, #0x48]
 *   @0xd67fc ldr r0, [pc, #0x48]
 *   @0xd6800 str r3, [r6]
 *   @0xd6804 ldr r5, [r7, r5]
 *   @0xd6808 str r3, [r5]
 *   @0xd680c ldr r4, [r7, r4]
 *   @0xd6810 str r3, [r4]
 *   @0xd6814 ldr r12, [r7, r12]
 *   @0xd6818 str r3, [r12]
 *   @0xd681c ldr r3, [r7, r0]
 *   @0xd6820 strb r1, [r8]
 *   @0xd6824 str r2, [r3]
 *   @0xd6828 pop {r4, r5, r6, r7, r8, pc}
 *   @0xd682c eorseq r11, r1, r8, ror #9
 *   @0xd6830 .word 0xffffbf68
 *   @0xd6834 .word 0xffffc04c
 *   @0xd6838 .word 0xffffc014
 *   @0xd683c .word 0xffffbf64
 *   @0xd6840 .word 0xffffc050
 *   @0xd6844 .word 0xffffc054
 *   @0xd6848 .word 0xffffc058
 *   @0xd684c .word 0xffffc05c
 *
 * ══ §10/127 InputQuery::Input(char const*, char const*, char const*, char*&)  0xf28b0  size 244  61 条（0xf28b0..0xf29a4）
 * @func 0xf28b0 0xf29a4  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×6 / _JNIEnv::CallStaticObjectMethod(_jclass*, _jmethodID*, ...) / MemoryManager::Free(void const*) / YYStrDup(char const*)
 * 字段偏移 top8: 0x29c×2 / 0x9c×1 / 0x98×1 / 0x2a4×1 / 0x2a8×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf28b0 push {r4, r5, r6, lr}
 *   @0xf28b4 sub sp, sp, #8
 *   @0xf28b8 mov r5, r2
 *   @0xf28bc mov r4, r3
 *   @0xf28c0 mov r6, r1
 *   @0xf28c4 bl 0x290274 <getJNIEnv>
 *   @0xf28c8 mov r1, r6
 *   @0xf28cc ldr r3, [r0]
 *   @0xf28d0 ldr r3, [r3, #0x29c]
 *   @0xf28d4 blx r3
 *   @0xf28d8 mov r6, r0
 *   @0xf28dc bl 0x290274 <getJNIEnv>
 *   @0xf28e0 mov r1, r5
 *   @0xf28e4 ldr r3, [r0]
 *   @0xf28e8 ldr r3, [r3, #0x29c]
 *   @0xf28ec blx r3
 *   @0xf28f0 mov r5, r0
 *   @0xf28f4 bl 0x290274 <getJNIEnv>
 *   @0xf28f8 ldr r1, [pc, #0x9c]
 *   @0xf28fc mov r3, r6
 *   @0xf2900 ldr r2, [pc, #0x98]
 *   @0xf2904 ldr r1, [pc, r1]
 *   @0xf2908 ldr r2, [pc, r2]
 *   @0xf290c ldr r1, [r1]
 *   @0xf2910 ldr r2, [r2]
 *   @0xf2914 str r5, [sp]
 *   @0xf2918 bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz>
 *   @0xf291c mov r5, r0
 *   @0xf2920 bl 0x290274 <getJNIEnv>
 *   @0xf2924 mov r1, r5
 *   @0xf2928 mov r2, #0
 *   @0xf292c ldr r3, [r0]
 *   @0xf2930 ldr r3, [r3, #0x2a4]
 *   @0xf2934 blx r3
 *   @0xf2938 mov r6, r0
 *   @0xf293c ldr r0, [r4]
 *   @0xf2940 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf2944 mov r3, #0
 *   @0xf2948 mov r0, r6
 *   @0xf294c str r3, [r4]
 *   @0xf2950 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf2954 cmp r6, #0
 *   @0xf2958 cmpne r5, #0
 *   @0xf295c str r0, [r4]
 *   @0xf2960 beq 0xf2990 <_ZN10InputQuery5InputEPKcS1_S1_RPc+0xe0>
 *   @0xf2964 bl 0x290274 <getJNIEnv>
 *   @0xf2968 mov r1, r5
 *   @0xf296c mov r2, r6
 *   @0xf2970 ldr r3, [r0]
 *   @0xf2974 ldr r3, [r3, #0x2a8]
 *   @0xf2978 blx r3
 *   @0xf297c bl 0x290274 <getJNIEnv>
 *   @0xf2980 mov r1, r5
 *   @0xf2984 ldr r3, [r0]
 *   @0xf2988 ldr r3, [r3, #0x5c]
 *   @0xf298c blx r3
 *   @0xf2990 mov r0, #1
 *   @0xf2994 add sp, sp, #8
 *   @0xf2998 pop {r4, r5, r6, pc}
 *   @0xf299c eoreq r11, pc, r0, lsr #1
 *   @0xf29a0 .word 0x002fb4f4
 *
 * ══ §11/127 F_InstanceFind(RValue&, CInstance*, CInstance*, int, RValue*)  0x108758  size 244  61 条（0x108758..0x10884c）
 * @func 0x108758 0x10884c  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / WithObjIterator::WithObjIterator(int, CInstance*, CInstance*, bool) / WithObjIterator::Next() / WithObjIterator::operator*()
 * 字段偏移 top8: 0xc×2 / 0x58×1 / 0x68×1 / 0x69×1 / 0x50×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108758 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10875c sub sp, sp, #52
 *   @0x108760 mov r10, r1
 *   @0x108764 mov r8, r0
 *   @0x108768 ldr r4, [sp, #0x58]
 *   @0x10876c mov r1, #0
 *   @0x108770 mov r9, r2
 *   @0x108774 add r5, sp, #12
 *   @0x108778 mvn r6, #0
 *   @0x10877c mov r0, r4
 *   @0x108780 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108784 mov r1, #1
 *   @0x108788 mov r11, r0
 *   @0x10878c mov r0, r4
 *   @0x108790 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108794 mov r12, #0
 *   @0x108798 mov r1, r11
 *   @0x10879c mov r2, r10
 *   @0x1087a0 mov r3, r9
 *   @0x1087a4 str r12, [sp]
 *   @0x1087a8 mov r7, r0
 *   @0x1087ac mov r0, r5
 *   @0x1087b0 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b>
 *   @0x1087b4 b 0x1087dc <_Z14F_InstanceFindR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1087b8 bl 0x19d1c8 <_ZN15WithObjIterator4NextEv>
 *   @0x1087bc ldrb r3, [r4, #0x68]
 *   @0x1087c0 cmp r3, #0
 *   @0x1087c4 bne 0x1087d4 <_Z14F_InstanceFindR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x1087c8 ldrb r3, [r4, #0x69]
 *   @0x1087cc cmp r3, #0
 *   @0x1087d0 addeq r6, r6, #1
 *   @0x1087d4 cmp r6, r7
 *   @0x1087d8 beq 0x1087f0 <_Z14F_InstanceFindR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1087dc mov r0, r5
 *   @0x1087e0 bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x1087e4 subs r4, r0, #0
 *   @0x1087e8 mov r0, r5
 *   @0x1087ec bne 0x1087b8 <_Z14F_InstanceFindR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x1087f0 ldr r3, [pc, #0x50]
 *   @0x1087f4 ldr r3, [pc, r3]
 *   @0x1087f8 ldrb r3, [r3]
 *   @0x1087fc cmp r3, #0
 *   @0x108800 bne 0x108834 <_Z14F_InstanceFindR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x108804 cmp r4, #0
 *   @0x108808 str r3, [r8, #0xc]
 *   @0x10880c ldrne r2, [r4, #0x78]
 *   @0x108810 moveq r3, #0
 *   @0x108814 moveq r2, #0
 *   @0x108818 movteq r3, #0xc010
 *   @0x10881c vmovne s15, r2
 *   @0x108820 vcvtne.f64.s32 d7, s15
 *   @0x108824 vmovne r2, r3, d7
 *   @0x108828 stm r8, {r2, r3}
 *   @0x10882c add sp, sp, #52
 *   @0x108830 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x108834 mov r3, #6
 *   @0x108838 str r4, [r8]
 *   @0x10883c str r3, [r8, #0xc]
 *   @0x108840 add sp, sp, #52
 *   @0x108844 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x108848 eoreq r5, lr, r4, asr #7
 *
 * ══ §12/127 F_DotProduct_3D_Normalised(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f21c  size 244  61 条（0x10f21c..0x10f310）
 * @func 0x10f21c 0x10f310  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / 0xb6700×2
 * 字段偏移 top8: 0x30×1 / 0xc×1
 * VFP 指令 31 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f21c push {r3, r4, r5, lr}
 *   @0x10f220 vpush {d8, d9, d10, d11}
 *   @0x10f224 mov r1, #0
 *   @0x10f228 ldr r4, [sp, #0x30]
 *   @0x10f22c mov r5, r0
 *   @0x10f230 str r1, [r0, #0xc]
 *   @0x10f234 mov r0, r4
 *   @0x10f238 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f23c mov r1, #1
 *   @0x10f240 vmov s20, r0
 *   @0x10f244 mov r0, r4
 *   @0x10f248 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f24c mov r1, #2
 *   @0x10f250 vmov s22, r0
 *   @0x10f254 mov r0, r4
 *   @0x10f258 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f25c mov r1, #3
 *   @0x10f260 vmov s18, r0
 *   @0x10f264 mov r0, r4
 *   @0x10f268 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f26c mov r1, #4
 *   @0x10f270 vmov s19, r0
 *   @0x10f274 mov r0, r4
 *   @0x10f278 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f27c mov r1, #5
 *   @0x10f280 vmov s21, r0
 *   @0x10f284 mov r0, r4
 *   @0x10f288 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f28c vmul.f32 s15, s22, s22
 *   @0x10f290 vmla.f32 s15, s20, s20
 *   @0x10f294 vmov s17, r0
 *   @0x10f298 vmla.f32 s15, s18, s18
 *   @0x10f29c vsqrt.f32 s16, s15
 *   @0x10f2a0 vcmp.f32 s16, s16
 *   @0x10f2a4 vmrs APSR_nzcv, fpscr
 *   @0x10f2a8 bne 0x10f2f0 <_Z26F_DotProduct_3D_NormalisedR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x10f2ac vmul.f32 s15, s21, s21
 *   @0x10f2b0 vmla.f32 s15, s19, s19
 *   @0x10f2b4 vmla.f32 s15, s17, s17
 *   @0x10f2b8 vsqrt.f32 s14, s15
 *   @0x10f2bc vcmp.f32 s14, s14
 *   @0x10f2c0 vmrs APSR_nzcv, fpscr
 *   @0x10f2c4 bne 0x10f300 <_Z26F_DotProduct_3D_NormalisedR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x10f2c8 vmul.f32 s15, s22, s21
 *   @0x10f2cc vmla.f32 s15, s20, s19
 *   @0x10f2d0 vmla.f32 s15, s18, s17
 *   @0x10f2d4 vmul.f32 s16, s16, s14
 *   @0x10f2d8 vdiv.f32 s15, s15, s16
 *   @0x10f2dc vcvt.f64.f32 d6, s15
 *   @0x10f2e0 vmov r2, r3, d6
 *   @0x10f2e4 stm r5, {r2, r3}
 *   @0x10f2e8 vpop {d8, d9, d10, d11}
 *   @0x10f2ec pop {r3, r4, r5, pc}
 *   @0x10f2f0 vmov r0, s15
 *   @0x10f2f4 bl 0xb6700 <sqrtf@plt>
 *   @0x10f2f8 vmov s16, r0
 *   @0x10f2fc b 0x10f2ac <_Z26F_DotProduct_3D_NormalisedR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x10f300 vmov r0, s15
 *   @0x10f304 bl 0xb6700 <sqrtf@plt>
 *   @0x10f308 vmov s14, r0
 *   @0x10f30c b 0x10f2c8 <_Z26F_DotProduct_3D_NormalisedR6RValueP9CInstanceS2_iPS_+0xac>
 *
 * ══ §13/127 F_SpriteGetTexture(RValue&, CInstance*, CInstance*, int, RValue*)  0x11fa38  size 244  61 条（0x11fa38..0x11fb2c）
 * @func 0x11fa38 0x11fb2c  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_SpriteGetTexture(RValue&, CInstance*, CInstance*, int, RValue*)+0x70 / Sprite_Data(int) / CSprite::GetTexture(int) / 0xb6598
 * 字段偏移 top8: 0xc×3 / 0x18×1 / 0x74×1 / 0x50×1 / 0x30×1 / 0x10×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11fa38 push {r3, r4, r5, r6, r7, lr}
 *   @0x11fa3c mov r4, r0
 *   @0x11fa40 ldr r5, [sp, #0x18]
 *   @0x11fa44 mov r7, r1
 *   @0x11fa48 mov r1, #0
 *   @0x11fa4c mov r0, r5
 *   @0x11fa50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11fa54 mov r1, #1
 *   @0x11fa58 mov r6, r0
 *   @0x11fa5c mov r0, r5
 *   @0x11fa60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11fa64 subs r5, r0, #0
 *   @0x11fa68 blt 0x11faa8 <_Z18F_SpriteGetTextureR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x11fa6c mov r0, r6
 *   @0x11fa70 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11fa74 subs r1, r0, #0
 *   @0x11fa78 beq 0x11fb10 <_Z18F_SpriteGetTextureR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x11fa7c ldr r3, [r1, #0x74]
 *   @0x11fa80 cmp r3, #1
 *   @0x11fa84 beq 0x11faec <_Z18F_SpriteGetTextureR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x11fa88 cmp r3, #2
 *   @0x11fa8c beq 0x11fac8 <_Z18F_SpriteGetTextureR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x11fa90 mov r3, #3
 *   @0x11fa94 mov r1, r5
 *   @0x11fa98 str r3, [r4, #0xc]
 *   @0x11fa9c bl 0x1e57f4 <_ZN7CSprite10GetTextureEi>
 *   @0x11faa0 str r0, [r4]
 *   @0x11faa4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x11faa8 vldr s15, [r7, #144]
 *   @0x11faac vcvt.f64.f32 d6, s15
 *   @0x11fab0 vmov r0, r1, d6
 *   @0x11fab4 bl 0xb6598 <floor@plt>
 *   @0x11fab8 vmov d7, r0, r1
 *   @0x11fabc vcvt.s32.f64 s15, d7
 *   @0x11fac0 vmov r5, s15
 *   @0x11fac4 b 0x11fa6c <_Z18F_SpriteGetTextureR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x11fac8 ldr r0, [pc, #0x50]
 *   @0x11facc mov r1, #0
 *   @0x11fad0 mov r3, r1
 *   @0x11fad4 str r1, [r4, #0xc]
 *   @0x11fad8 movt r3, #0xbff0
 *   @0x11fadc add r0, pc, r0
 *   @0x11fae0 stm r4, {r1, r3}
 *   @0x11fae4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x11fae8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11faec ldr r0, [pc, #0x30]
 *   @0x11faf0 mov r1, #0
 *   @0x11faf4 mov r3, r1
 *   @0x11faf8 str r1, [r4, #0xc]
 *   @0x11fafc movt r3, #0xbff0
 *   @0x11fb00 add r0, pc, r0
 *   @0x11fb04 stm r4, {r1, r3}
 *   @0x11fb08 pop {r3, r4, r5, r6, r7, lr}
 *   @0x11fb0c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11fb10 ldr r0, [pc, #0x10]
 *   @0x11fb14 pop {r3, r4, r5, r6, r7, lr}
 *   @0x11fb18 add r0, pc, r0
 *   @0x11fb1c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11fb20 eoreq r10, r1, r8, lsl r8
 *   @0x11fb24 .word 0x0021a7bc
 *   @0x11fb28 eoreq r10, r1, r4, ror r7
 *
 * ══ §14/127 F_TileGetIDs(RValue&, CInstance*, CInstance*, int, RValue*)  0x1216f4  size 244  61 条（0x1216f4..0x1217e8）
 * @func 0x1216f4 0x1217e8  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateArray(RValue*, int, ...) / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×3 / 0xb8×2 / 0xd8×1 / 0xc×1 / 0x20×1 / 0x38×1 / 0x28×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1216f4 push {r4, r5, r6, lr}
 *   @0x1216f8 mov r6, r0
 *   @0x1216fc ldr r5, [pc, #0xd8]
 *   @0x121700 ldr r5, [pc, r5]
 *   @0x121704 ldr r2, [r5]
 *   @0x121708 ldr r4, [r2, #0xb8]
 *   @0x12170c cmp r4, #0
 *   @0x121710 popeq {r4, r5, r6, pc}
 *   @0x121714 cmp r3, #0
 *   @0x121718 bne 0x1217a0 <_Z12F_TileGetIDsR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x12171c mov r3, #0
 *   @0x121720 mov r1, #1
 *   @0x121724 mov r2, #0
 *   @0x121728 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x12172c ldr r3, [r6]
 *   @0x121730 ldr r0, [r3, #0x4]
 *   @0x121734 ldr r3, [r0]
 *   @0x121738 cmp r4, r3
 *   @0x12173c bge 0x1217b4 <_Z12F_TileGetIDsR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x121740 cmp r4, #0
 *   @0x121744 ldr r1, [r0, #0x4]
 *   @0x121748 pople {r4, r5, r6, pc}
 *   @0x12174c ldr r5, [r5]
 *   @0x121750 mov r12, #0
 *   @0x121754 mov r0, r12
 *   @0x121758 mov r6, r12
 *   @0x12175c ldr r2, [r5, #0xb8]
 *   @0x121760 mov r3, #0
 *   @0x121764 cmp r2, r0
 *   @0x121768 add r0, r0, #1
 *   @0x12176c ldrgt r3, [r5, #0xc0]
 *   @0x121770 str r6, [r1, #0xc]
 *   @0x121774 addgt r3, r3, r12
 *   @0x121778 cmp r0, r4
 *   @0x12177c add r12, r12, #56
 *   @0x121780 ldr r2, [r3, #0x20]
 *   @0x121784 vmov s15, r2
 *   @0x121788 vcvt.f64.s32 d7, s15
 *   @0x12178c vmov r2, r3, d7
 *   @0x121790 stm r1, {r2, r3}
 *   @0x121794 add r1, r1, #16
 *   @0x121798 bne 0x12175c <_Z12F_TileGetIDsR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x12179c pop {r4, r5, r6, pc}
 *   @0x1217a0 ldr r0, [pc, #0x38]
 *   @0x1217a4 mov r1, #0
 *   @0x1217a8 pop {r4, r5, r6, lr}
 *   @0x1217ac add r0, pc, r0
 *   @0x1217b0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1217b4 ldr r2, [pc, #0x28]
 *   @0x1217b8 add r0, r0, #4
 *   @0x1217bc movw r3, #0x1160
 *   @0x1217c0 lsl r1, r4, #4
 *   @0x1217c4 add r2, pc, r2
 *   @0x1217c8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1217cc ldr r3, [r6]
 *   @0x1217d0 ldr r0, [r3, #0x4]
 *   @0x1217d4 str r4, [r0]
 *   @0x1217d8 b 0x121740 <_Z12F_TileGetIDsR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x1217dc eoreq r12, r12, r8, lsr #4
 *   @0x1217e0 .word 0x00218cbc
 *   @0x1217e4 eoreq r8, r1, r12, lsl #15
 *
 * ══ §15/127 F_FileTextWriteReal(RValue&, CInstance*, CInstance*, int, RValue*)  0x1382c4  size 244  61 条（0x1382c4..0x1383b8）
 * @func 0x1382c4 0x1383b8  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetReal(RValue const*, int) / Error_Show_Action(char const*, bool) / 0xb65b0 / 0xb6550 / LoadSave::fputs(_YYFILE*, char const*) / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0xd0×1 / 0x420×1 / 0x8c×1 / 0x2×1 / 0x7c×1 / 0x3c×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1382c4 push {r4, r5, r6, r7, r8, lr}
 *   @0x1382c8 sub sp, sp, #1024
 *   @0x1382cc ldr r6, [pc, #0xd0]
 *   @0x1382d0 sub sp, sp, #8
 *   @0x1382d4 mov r1, #0
 *   @0x1382d8 ldr r6, [pc, r6]
 *   @0x1382dc ldr r4, [sp, #0x420]
 *   @0x1382e0 ldr r3, [r6]
 *   @0x1382e4 mov r0, r4
 *   @0x1382e8 str r3, [sp, #0x404]
 *   @0x1382ec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1382f0 mov r1, #1
 *   @0x1382f4 mov r7, r0
 *   @0x1382f8 mov r0, r4
 *   @0x1382fc bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x138300 sub r3, r7, #1
 *   @0x138304 cmp r3, #30
 *   @0x138308 mov r4, r0
 *   @0x13830c mov r5, r1
 *   @0x138310 bhi 0x138328 <_Z19F_FileTextWriteRealR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x138314 ldr r3, [pc, #0x8c]
 *   @0x138318 ldr r3, [pc, r3]
 *   @0x13831c ldr r3, [r3, r7, lsl #2]
 *   @0x138320 cmp r3, #2
 *   @0x138324 beq 0x138354 <_Z19F_FileTextWriteRealR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x138328 ldr r0, [pc, #0x7c]
 *   @0x13832c mov r1, #0
 *   @0x138330 add r0, pc, r0
 *   @0x138334 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x138338 ldr r2, [sp, #0x404]
 *   @0x13833c ldr r3, [r6]
 *   @0x138340 cmp r2, r3
 *   @0x138344 bne 0x1383a0 <_Z19F_FileTextWriteRealR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x138348 add sp, sp, #1024
 *   @0x13834c add sp, sp, #8
 *   @0x138350 pop {r4, r5, r6, r7, r8, pc}
 *   @0x138354 add r8, sp, #4
 *   @0x138358 mov r1, #0
 *   @0x13835c mov r2, #1024
 *   @0x138360 add r7, r7, r7, lsl #1
 *   @0x138364 mov r0, r8
 *   @0x138368 bl 0xb65b0 <memset@plt>
 *   @0x13836c ldr r1, [pc, #0x3c]
 *   @0x138370 mov r3, r5
 *   @0x138374 mov r0, r8
 *   @0x138378 mov r2, r4
 *   @0x13837c add r1, pc, r1
 *   @0x138380 bl 0xb6550 <sprintf@plt>
 *   @0x138384 ldr r3, [pc, #0x28]
 *   @0x138388 mov r1, r8
 *   @0x13838c ldr r3, [pc, r3]
 *   @0x138390 add r3, r3, r7, lsl #2
 *   @0x138394 ldr r0, [r3, #0x8]
 *   @0x138398 bl 0x18e114 <_ZN8LoadSave5fputsEP7_YYFILEPKc>
 *   @0x13839c b 0x138338 <_Z19F_FileTextWriteRealR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1383a0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1383a4 eoreq r5, r11, r8, ror r6
 *   @0x1383a8 eoreq r6, r11, r8, asr pc
 *   @0x1383ac eoreq r7, r0, r12, asr sp
 *   @0x1383b0 eoreq r7, r0, r0, lsr sp
 *   @0x1383b4 eoreq r6, r11, r8, ror #29
 *
 * ══ §16/127 F_HttpPostString(RValue&, CInstance*, CInstance*, int, RValue*)  0x138f80  size 244  61 条（0x138f80..0x139074）
 * @func 0x138f80 0x139074  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / 0xb65e0×2 / YYStrDup(char const*) / LoadSave::HTTP_Post(char const*, char const*, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*)
 * 字段偏移 top8: 0xd0×1 / 0x20×1 / 0xc×1 / 0x4×1 / 0x7c×1 / 0x64×1 / 0x4c×1 / 0x3c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x138f80 push {r4, r5, r6, r7, lr}
 *   @0x138f84 sub sp, sp, #12
 *   @0x138f88 ldr r3, [pc, #0xd0]
 *   @0x138f8c mov r4, r0
 *   @0x138f90 ldr r6, [sp, #0x20]
 *   @0x138f94 mov r1, #0
 *   @0x138f98 ldr r3, [pc, r3]
 *   @0x138f9c mov r7, #1
 *   @0x138fa0 mov r0, r6
 *   @0x138fa4 strb r7, [r3]
 *   @0x138fa8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x138fac mov r1, r7
 *   @0x138fb0 mov r5, r0
 *   @0x138fb4 mov r0, r6
 *   @0x138fb8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x138fbc cmp r5, #0
 *   @0x138fc0 mov r2, #0
 *   @0x138fc4 mov r3, r2
 *   @0x138fc8 movt r2, #0xbff0
 *   @0x138fcc str r3, [r4, #0xc]
 *   @0x138fd0 str r2, [r4, #0x4]
 *   @0x138fd4 str r3, [r4]
 *   @0x138fd8 mov r6, r0
 *   @0x138fdc beq 0x139058 <_Z16F_HttpPostStringR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x138fe0 ldr r0, [pc, #0x7c]
 *   @0x138fe4 mov r1, r5
 *   @0x138fe8 mov r2, #7
 *   @0x138fec add r0, pc, r0
 *   @0x138ff0 bl 0xb65e0 <strncmp@plt>
 *   @0x138ff4 cmp r0, #0
 *   @0x138ff8 beq 0x139018 <_Z16F_HttpPostStringR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x138ffc ldr r0, [pc, #0x64]
 *   @0x139000 mov r1, r5
 *   @0x139004 mov r2, #8
 *   @0x139008 add r0, pc, r0
 *   @0x13900c bl 0xb65e0 <strncmp@plt>
 *   @0x139010 cmp r0, #0
 *   @0x139014 bne 0x139058 <_Z16F_HttpPostStringR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x139018 ldr r3, [pc, #0x4c]
 *   @0x13901c mov r0, r6
 *   @0x139020 ldr r3, [pc, r3]
 *   @0x139024 ldr r6, [r3]
 *   @0x139028 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x13902c ldr r2, [pc, #0x3c]
 *   @0x139030 mov r3, #0
 *   @0x139034 str r3, [sp]
 *   @0x139038 ldr r2, [pc, r2]
 *   @0x13903c mov r1, r0
 *   @0x139040 mov r0, r5
 *   @0x139044 bl 0x18fd00 <_ZN8LoadSave9HTTP_PostEPKcS1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_>
 *   @0x139048 vmov s15, r6
 *   @0x13904c vcvt.f64.s32 d7, s15
 *   @0x139050 vmov r2, r3, d7
 *   @0x139054 stm r4, {r2, r3}
 *   @0x139058 add sp, sp, #12
 *   @0x13905c pop {r4, r5, r6, r7, pc}
 *   @0x139060 .word 0x002b49bc
 *   @0x139064 ldrsheq r7, [pc], -r4
 *   @0x139068 andseq r7, pc, r0, ror #21
 *   @0x13906c eoreq r6, r11, r8, asr r2
 *   @0x139070 eoreq r6, r11, r4, asr #4
 *
 * ══ §17/127 F_ActionPartEmitCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x13ffac  size 244  61 条（0x13ffac..0x1400a0）
 * @func 0x13ffac 0x1400a0  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / F_ActionPartEmitCreate(RValue&, CInstance*, CInstance*, int, RValue*)+0xd4 / F_ActionPartEmitCreate(RValue&, CInstance*, CInstance*, int, RValue*)+0xc0 / ParticleSystem_Emitter_Region(int, int, float, float, float, float, int, int) / ParticleSystem_Emitter_Create(int) / ParticleSystem_Create(int, bool)
 * 字段偏移 top8: 0x2×2 / 0xd8×1 / 0x38×1 / 0x64×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ffac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13ffb0 sub sp, sp, #20
 *   @0x13ffb4 mov r1, #0
 *   @0x13ffb8 ldr r5, [pc, #0xd8]
 *   @0x13ffbc ldr r4, [sp, #0x38]
 *   @0x13ffc0 mov r0, r4
 *   @0x13ffc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13ffc8 mov r1, #1
 *   @0x13ffcc mov r6, r0
 *   @0x13ffd0 mov r0, r4
 *   @0x13ffd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13ffd8 mov r1, #2
 *   @0x13ffdc mov r9, r0
 *   @0x13ffe0 mov r0, r4
 *   @0x13ffe4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13ffe8 mov r1, #3
 *   @0x13ffec mov r8, r0
 *   @0x13fff0 mov r0, r4
 *   @0x13fff4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13fff8 mov r1, #4
 *   @0x13fffc mov r7, r0
 *   @0x140000 mov r0, r4
 *   @0x140004 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140008 mov r1, #5
 *   @0x14000c mov r10, r0
 *   @0x140010 mov r0, r4
 *   @0x140014 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140018 ldr r5, [pc, r5]
 *   @0x14001c ldr r3, [r5]
 *   @0x140020 cmp r3, #0
 *   @0x140024 mov r11, r0
 *   @0x140028 movge r0, r3
 *   @0x14002c blt 0x140080 <_Z22F_ActionPartEmitCreateR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x140030 ldr r4, [pc, #0x64]
 *   @0x140034 ldr r4, [pc, r4]
 *   @0x140038 ldr r1, [r4, r6, lsl #2]
 *   @0x14003c cmp r1, #0
 *   @0x140040 blt 0x14006c <_Z22F_ActionPartEmitCreateR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x140044 mov r12, #0
 *   @0x140048 str r10, [sp]
 *   @0x14004c str r11, [sp, #0x4]
 *   @0x140050 mov r2, r8
 *   @0x140054 str r9, [sp, #0x8]
 *   @0x140058 mov r3, r7
 *   @0x14005c str r12, [sp, #0xc]
 *   @0x140060 bl 0x1a394c <_Z29ParticleSystem_Emitter_Regioniiffffii>
 *   @0x140064 add sp, sp, #20
 *   @0x140068 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14006c bl 0x1a39b4 <_Z29ParticleSystem_Emitter_Createi>
 *   @0x140070 mov r1, r0
 *   @0x140074 ldr r0, [r5]
 *   @0x140078 str r1, [r4, r6, lsl #2]
 *   @0x14007c b 0x140044 <_Z22F_ActionPartEmitCreateR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x140080 mvn r0, #0
 *   @0x140084 mov r1, #1
 *   @0x140088 bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x14008c mov r3, r0
 *   @0x140090 str r3, [r5]
 *   @0x140094 b 0x140030 <_Z22F_ActionPartEmitCreateR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x140098 eoreq pc, r10, r4, asr #7
 *   @0x14009c .word 0x002af3b0
 *
 * ══ §18/127 F_ActionDrawEllipseGradient(RValue&, CInstance*, CInstance*, int, RValue*)  0x14073c  size 244  61 条（0x14073c..0x140830）
 * @func 0x14073c 0x140830  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / GR_Draw_Ellipse_Ext(float, float, float, float, unsigned int, unsigned int, bool)×2
 * 字段偏移 top8: 0x30×1 / 0x78×1 / 0x4×1 / 0x8×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14073c push {r4, r5, r6, lr}
 *   @0x140740 vpush {d8, d9}
 *   @0x140744 sub sp, sp, #16
 *   @0x140748 mov r6, r1
 *   @0x14074c mov r1, #0
 *   @0x140750 ldr r4, [sp, #0x30]
 *   @0x140754 mov r0, r4
 *   @0x140758 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14075c mov r1, #1
 *   @0x140760 vmov s19, r0
 *   @0x140764 mov r0, r4
 *   @0x140768 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14076c mov r1, #2
 *   @0x140770 vmov s18, r0
 *   @0x140774 mov r0, r4
 *   @0x140778 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14077c mov r1, #3
 *   @0x140780 vmov s17, r0
 *   @0x140784 mov r0, r4
 *   @0x140788 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14078c mov r1, #4
 *   @0x140790 vmov s16, r0
 *   @0x140794 mov r0, r4
 *   @0x140798 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14079c mov r1, #5
 *   @0x1407a0 mov r5, r0
 *   @0x1407a4 mov r0, r4
 *   @0x1407a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1407ac ldr r3, [pc, #0x78]
 *   @0x1407b0 ldr r3, [pc, r3]
 *   @0x1407b4 ldrb r3, [r3]
 *   @0x1407b8 str r5, [sp]
 *   @0x1407bc cmp r3, #0
 *   @0x1407c0 bne 0x1407e8 <_Z27F_ActionDrawEllipseGradientR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x1407c4 stmib sp, {r0, r3}
 *   @0x1407c8 vmov r1, s18
 *   @0x1407cc vmov r0, s19
 *   @0x1407d0 vmov r2, s17
 *   @0x1407d4 vmov r3, s16
 *   @0x1407d8 bl 0x16b2ac <_Z19GR_Draw_Ellipse_Extffffjjb>
 *   @0x1407dc add sp, sp, #16
 *   @0x1407e0 vpop {d8, d9}
 *   @0x1407e4 pop {r4, r5, r6, pc}
 *   @0x1407e8 vldr s14, [r6, #180]
 *   @0x1407ec str r0, [sp, #0x4]
 *   @0x1407f0 vadd.f32 s19, s19, s14
 *   @0x1407f4 vldr s15, [r6, #184]
 *   @0x1407f8 mov r3, #0
 *   @0x1407fc str r3, [sp, #0x8]
 *   @0x140800 vadd.f32 s14, s17, s14
 *   @0x140804 vmov r0, s19
 *   @0x140808 vadd.f32 s18, s18, s15
 *   @0x14080c vmov r2, s14
 *   @0x140810 vadd.f32 s15, s16, s15
 *   @0x140814 vmov r1, s18
 *   @0x140818 vmov r3, s15
 *   @0x14081c bl 0x16b2ac <_Z19GR_Draw_Ellipse_Extffffjjb>
 *   @0x140820 add sp, sp, #16
 *   @0x140824 vpop {d8, d9}
 *   @0x140828 pop {r4, r5, r6, pc}
 *   @0x14082c eoreq sp, r10, r12, lsl #7
 *
 * ══ §19/127 F_IAP_ProductDetails(RValue&, CInstance*, CInstance*, int, RValue*)  0x1552f4  size 244  61 条（0x1552f4..0x1553e8）
 * @func 0x1552f4 0x1553e8  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_15327c / F_IAP_ProductDetails(RValue&, CInstance*, CInstance*, int, RValue*)+0x88 / YYGetInt32(RValue const*, int) / CIAPProduct::PopulateMap(int) / anon_154a70 / anon_153710+0x3bc
 * 字段偏移 top8: 0x4×4 / 0x30×2 / 0x2×2 / 0xc×1 / 0xac×1 / 0x9c×1 / 0x14×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1552f4 push {r4, r5, r6, r7, r8, lr}
 *   @0x1552f8 sub sp, sp, #24
 *   @0x1552fc mov r3, #0
 *   @0x155300 mov r4, r0
 *   @0x155304 ldr r5, [sp, #0x30]
 *   @0x155308 str r3, [r0, #0xc]
 *   @0x15530c str r3, [r0]
 *   @0x155310 str r3, [r0, #0x4]
 *   @0x155314 mov r0, r5
 *   @0x155318 bl 0x15327c <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x15531c subs r6, r0, #0
 *   @0x155320 blt 0x15537c <_Z20F_IAP_ProductDetailsR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x155324 ldr r3, [pc, #0xac]
 *   @0x155328 ldr r3, [pc, r3]
 *   @0x15532c ldr r3, [r3]
 *   @0x155330 cmp r6, r3
 *   @0x155334 bge 0x15537c <_Z20F_IAP_ProductDetailsR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x155338 ldr r7, [pc, #0x9c]
 *   @0x15533c ldr r7, [pc, r7]
 *   @0x155340 ldr r3, [r7, #0x4]
 *   @0x155344 ldr r8, [r3, r6, lsl #2]
 *   @0x155348 ldrb r1, [r8, #0x14]
 *   @0x15534c cmp r1, #0
 *   @0x155350 beq 0x155384 <_Z20F_IAP_ProductDetailsR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x155354 mov r1, #1
 *   @0x155358 mov r0, r5
 *   @0x15535c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x155360 mov r1, r0
 *   @0x155364 mov r0, r8
 *   @0x155368 bl 0x18b348 <_ZN11CIAPProduct11PopulateMapEi>
 *   @0x15536c mov r3, #0
 *   @0x155370 mov r2, r3
 *   @0x155374 movt r3, #0x3ff0
 *   @0x155378 stm r4, {r2, r3}
 *   @0x15537c add sp, sp, #24
 *   @0x155380 pop {r4, r5, r6, r7, r8, pc}
 *   @0x155384 ldr r12, [pc, #0x54]
 *   @0x155388 mov r2, #0
 *   @0x15538c str r1, [sp]
 *   @0x155390 mov r3, #0
 *   @0x155394 add r12, pc, r12
 *   @0x155398 strd r2, r3, [sp, #8]
 *   @0x15539c str r12, [sp, #0x4]
 *   @0x1553a0 mov r2, #0
 *   @0x1553a4 ldr r12, [r8]
 *   @0x1553a8 mov r0, #2
 *   @0x1553ac ldr r1, [pc, #0x30]
 *   @0x1553b0 mov r3, #0
 *   @0x1553b4 movt r3, #0x4008
 *   @0x1553b8 add r1, pc, r1
 *   @0x1553bc str r12, [sp, #0x10]
 *   @0x1553c0 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88>
 *   @0x1553c4 mov r1, #3
 *   @0x1553c8 bl 0x153acc <_Z16InitIAPFunctionsv+0x5f8>
 *   @0x1553cc ldr r3, [r7, #0x4]
 *   @0x1553d0 ldr r8, [r3, r6, lsl #2]
 *   @0x1553d4 b 0x155354 <_Z20F_IAP_ProductDetailsR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x1553d8 eoreq r10, r9, r8, lsr #15
 *   @0x1553dc mlaeq r9, r8, r7, r10
 *   @0x1553e0 mulseq pc, r12, sp
 *   @0x1553e4 andseq r0, pc, r0, ror sp
 *
 * ══ §20/127 anon_159b90  0x159b90  size 244  61 条（0x159b90..0x159c84）
 * @func 0x159b90 0x159c84  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Cache_ReadInt32(unsigned char*, int*)×2 / Achievement_PlayerID() / 0xb6550 / LoadSave::ReadSaveFile(char const*, int*) / anon_159b90+0xc4 / Cache_ReadString(unsigned char*, int*) / AddAchievementCacheBlock(eCacheType, char const*, unsigned int*) / anon_159b90+0x74
 * 字段偏移 top8: 0x10c×2 / 0xc0×2 / 0x4×2 / 0xd8×1 / 0x-10c×1 / 0x94×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159b90 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x159b94 sub sp, sp, #276
 *   @0x159b98 ldr r9, [pc, #0xd8]
 *   @0x159b9c add r4, sp, #12
 *   @0x159ba0 mov r6, #0
 *   @0x159ba4 ldr r9, [pc, r9]
 *   @0x159ba8 ldr r3, [r9]
 *   @0x159bac str r3, [sp, #0x10c]
 *   @0x159bb0 bl 0x161210 <_Z20Achievement_PlayerIDv>
 *   @0x159bb4 ldr r1, [pc, #0xc0]
 *   @0x159bb8 ldr r3, [pc, #0xc0]
 *   @0x159bbc add r1, pc, r1
 *   @0x159bc0 add r3, pc, r3
 *   @0x159bc4 mov r2, r0
 *   @0x159bc8 mov r0, r4
 *   @0x159bcc bl 0xb6550 <sprintf@plt>
 *   @0x159bd0 add r1, sp, #272
 *   @0x159bd4 mov r0, r4
 *   @0x159bd8 str r6, [r1, #-0x10c]!
 *   @0x159bdc bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0x159be0 subs r5, r0, #0
 *   @0x159be4 beq 0x159c5c <_Z16Cache_ReadStringPhPi+0xf8>
 *   @0x159be8 ldr r4, [pc, #0x94]
 *   @0x159bec ldr r3, [sp, #0x4]
 *   @0x159bf0 ldr r4, [pc, r4]
 *   @0x159bf4 cmp r3, r6
 *   @0x159bf8 str r6, [r4]
 *   @0x159bfc addgt r8, sp, #8
 *   @0x159c00 ble 0x159c54 <_Z16Cache_ReadStringPhPi+0xf0>
 *   @0x159c04 mov r1, r4
 *   @0x159c08 mov r0, r5
 *   @0x159c0c bl 0x159b2c <_Z15Cache_ReadInt32PhPi>
 *   @0x159c10 mov r1, r4
 *   @0x159c14 mov r6, r0
 *   @0x159c18 mov r0, r5
 *   @0x159c1c bl 0x159b64 <_Z16Cache_ReadStringPhPi>
 *   @0x159c20 mov r1, r4
 *   @0x159c24 mov r7, r0
 *   @0x159c28 mov r0, r5
 *   @0x159c2c bl 0x159b2c <_Z15Cache_ReadInt32PhPi>
 *   @0x159c30 mov r1, r7
 *   @0x159c34 mov r2, r8
 *   @0x159c38 str r0, [sp, #0x8]
 *   @0x159c3c mov r0, r6
 *   @0x159c40 bl 0x159a9c <_Z24AddAchievementCacheBlock10eCacheTypePKcPj>
 *   @0x159c44 ldr r1, [r4]
 *   @0x159c48 ldr r3, [sp, #0x4]
 *   @0x159c4c cmp r1, r3
 *   @0x159c50 blt 0x159c04 <_Z16Cache_ReadStringPhPi+0xa0>
 *   @0x159c54 mov r0, r5
 *   @0x159c58 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x159c5c ldr r2, [sp, #0x10c]
 *   @0x159c60 ldr r3, [r9]
 *   @0x159c64 cmp r2, r3
 *   @0x159c68 bne 0x159c74 <_Z16Cache_ReadStringPhPi+0x110>
 *   @0x159c6c add sp, sp, #276
 *   @0x159c70 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x159c74 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x159c78 eoreq r3, r9, r12, lsr #27
 *   @0x159c7c andseq r11, sp, r8, lsl r0
 *   @0x159c80 ldrsheq r12, [lr], -r8
 *
 * ══ §21/127 GR_Draw_Line_Ext(float, float, float, float, unsigned int, unsigned int)  0x16a45c  size 244  61 条（0x16a45c..0x16a550）
 * @func 0x16a45c 0x16a550  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16a470→0x4859c0, 0x16a4a4→0x3f23d8, 0x16a4a8→0x3f23d4, 0x16a4b0→0x4859ac, 0x16a4c8→0x3f23cc
 * 调用序列: GR_Color_To_D3DColor(unsigned int, unsigned int)×2 / Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0x94×2 / 0xc8×1 / 0xc4×1 / 0x28×1 / 0x2c×1 / 0x90×1 / 0x7c×1 / 0x8×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16a45c push {r3, r4, r5, r6, r7, lr}
 *   @0x16a460 vpush {d8, d9}
 *   @0x16a464 vmov s18, r1
 *   @0x16a468 ldr r5, [pc, #0xc8]
 *   @0x16a46c vmov s19, r0
 *   @0x16a470 ldr r12, [pc, #0xc4]
 *   @0x16a474 mov r0, #2
 *   @0x16a478 add r5, pc, r5
 *   @0x16a47c vmov s16, r3
 *   @0x16a480 vmov s17, r2
 *   @0x16a484 mov r3, r0
 *   @0x16a488 ldr r1, [r5, r12]
 *   @0x16a48c mov r2, #16
 *   @0x16a490 ldr r6, [sp, #0x28]
 *   @0x16a494 ldr r7, [sp, #0x2c]
 *   @0x16a498 ldr r1, [r1]
 *   @0x16a49c ldr r1, [r1]
 *   @0x16a4a0 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16a4a4 ldr r1, [pc, #0x94]
 *   @0x16a4a8 ldr r3, [pc, #0x94]
 *   @0x16a4ac vldr s13, [pc, #128]
 *   @0x16a4b0 ldr r2, [pc, #0x90]
 *   @0x16a4b4 ldr r1, [r5, r1]
 *   @0x16a4b8 vldr s14, [r1]
 *   @0x16a4bc ldr r3, [r5, r3]
 *   @0x16a4c0 vmul.f32 s14, s14, s13
 *   @0x16a4c4 vldr s15, [r3]
 *   @0x16a4c8 ldr r3, [pc, #0x7c]
 *   @0x16a4cc vmul.f32 s15, s15, s13
 *   @0x16a4d0 vadd.f32 s19, s14, s19
 *   @0x16a4d4 mov r4, r0
 *   @0x16a4d8 mov r0, r6
 *   @0x16a4dc vadd.f32 s18, s15, s18
 *   @0x16a4e0 vstr s19, [r4]
 *   @0x16a4e4 vstr s18, [r4, #4]
 *   @0x16a4e8 ldr r6, [r5, r2]
 *   @0x16a4ec vadd.f32 s17, s14, s17
 *   @0x16a4f0 ldr r2, [r6]
 *   @0x16a4f4 str r2, [r4, #0x8]
 *   @0x16a4f8 ldr r5, [r5, r3]
 *   @0x16a4fc ldr r1, [r5]
 *   @0x16a500 vadd.f32 s16, s15, s16
 *   @0x16a504 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16a508 ldr r3, [r6]
 *   @0x16a50c vstr s17, [r4, #16]
 *   @0x16a510 ldr r1, [r5]
 *   @0x16a514 str r3, [r4, #0x18]
 *   @0x16a518 vstr s16, [r4, #20]
 *   @0x16a51c str r0, [r4, #0xc]
 *   @0x16a520 mov r0, r7
 *   @0x16a524 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16a528 vpop {d8, d9}
 *   @0x16a52c str r0, [r4, #0x1c]
 *   @0x16a530 pop {r3, r4, r5, r6, r7, pc}
 *   @0x16a534 stclo p7, c13, [r3], #-40
 *   @0x16a538 .word 0x002877d8
 *   @0x16a53c .word 0xffffe4e0
 *   @0x16a540 .word 0xffffe524
 *   @0x16a544 .word 0xffffe520
 *   @0x16a548 .word 0xffffbcd0
 *   @0x16a54c .word 0xffffc0b0
 *
 * ══ §22/127 GR_Draw_Primitive_Begin(int, int)  0x16b964  size 244  61 条（0x16b964..0x16ba58）
 * @func 0x16b964 0x16ba58  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16b974→0x4899b0, 0x16b97c→0x4899ac, 0x16b980→0x3f23c8, 0x16b988→0x490000, 0x16b9ec→0x48ffec, 0x16b9fc→0x48fffc, 0x16ba00→0x48fff8
 * 调用序列: GR_Texture_Exists(int)
 * 字段偏移 top8: 0xb8×2 / 0x4c×2 / 0xc0×1 / 0xbc×1 / 0xb4×1 / 0x6c×1 / 0x58×1 / 0x4×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16b964 push {r3, r4, r5, r6, r7, lr}
 *   @0x16b968 mov r5, r1
 *   @0x16b96c ldr r4, [pc, #0xc0]
 *   @0x16b970 mov r3, #0
 *   @0x16b974 ldr r2, [pc, #0xbc]
 *   @0x16b978 add r4, pc, r4
 *   @0x16b97c ldr r12, [pc, #0xb8]
 *   @0x16b980 ldr r1, [pc, #0xb8]
 *   @0x16b984 ldr lr, [r4, r2]
 *   @0x16b988 ldr r2, [pc, #0xb4]
 *   @0x16b98c str r3, [lr]
 *   @0x16b990 ldr r12, [r4, r12]
 *   @0x16b994 str r0, [r12]
 *   @0x16b998 mov r0, r5
 *   @0x16b99c ldr r6, [r4, r1]
 *   @0x16b9a0 str r5, [r6]
 *   @0x16b9a4 ldr r7, [r4, r2]
 *   @0x16b9a8 str r3, [r7]
 *   @0x16b9ac bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x16b9b0 cmp r0, #0
 *   @0x16b9b4 strne r5, [r6]
 *   @0x16b9b8 popne {r3, r4, r5, r6, r7, pc}
 *   @0x16b9bc add r2, r5, #1
 *   @0x16b9c0 movw r3, #0x4001
 *   @0x16b9c4 cmp r2, r3
 *   @0x16b9c8 bhi 0x16b9e8 <_Z23GR_Draw_Primitive_Beginii+0x84>
 *   @0x16b9cc cmn r5, #1
 *   @0x16b9d0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x16b9d4 ldr r0, [pc, #0x6c]
 *   @0x16b9d8 mov r1, #1
 *   @0x16b9dc pop {r3, r4, r5, r6, r7, lr}
 *   @0x16b9e0 add r0, pc, r0
 *   @0x16b9e4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x16b9e8 ldrsh r3, [r5, #20]
 *   @0x16b9ec ldr r2, [pc, #0x58]
 *   @0x16b9f0 str r5, [r7]
 *   @0x16b9f4 str r3, [r6]
 *   @0x16b9f8 ldr r0, [r4, r2]
 *   @0x16b9fc ldr r1, [pc, #0x4c]
 *   @0x16ba00 ldr r2, [pc, #0x4c]
 *   @0x16ba04 ldr r0, [r0, #0x4]
 *   @0x16ba08 ldr r1, [r4, r1]
 *   @0x16ba0c ldr r3, [r0, r3, lsl #2]
 *   @0x16ba10 ldr r3, [r3]
 *   @0x16ba14 vldr s14, [r3, #4]
 *   @0x16ba18 vldr s15, [r3, #8]
 *   @0x16ba1c vcvt.f32.s32 s14, s14
 *   @0x16ba20 vcvt.f32.s32 s15, s15
 *   @0x16ba24 vstr s14, [r1]
 *   @0x16ba28 ldr r3, [r4, r2]
 *   @0x16ba2c vstr s15, [r3]
 *   @0x16ba30 pop {r3, r4, r5, r6, r7, pc}
 *   @0x16ba34 .word 0x002862d8
 *   @0x16ba38 .word 0xffffe534
 *   @0x16ba3c .word 0xffffe538
 *   @0x16ba40 .word 0xffffe53c
 *   @0x16ba44 .word 0xffffe540
 *   @0x16ba48 andseq lr, sp, r12, asr lr
 *   @0x16ba4c .word 0xffffbccc
 *   @0x16ba50 .word 0xffffe544
 *   @0x16ba54 .word 0xffffe548
 *
 * ══ §23/127 GR_3D_Primitive_Begin(int, int)  0x1769dc  size 244  61 条（0x1769dc..0x176ad0）
 * @func 0x1769dc 0x176ad0  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1769ec→0x490008, 0x1769f8→0x490004, 0x1769fc→0x3f241c, 0x176a0c→0x490000, 0x176a48→0x48ffec, 0x176a58→0x48fffc, 0x176a5c→0x48fff8, 0x176a90→0x3f2418
 * 调用序列: GR_Texture_Exists(int)
 * 字段偏移 top8: 0xb0×2 / 0x60×2 / 0x2×2 / 0x34×2 / 0xbc×1 / 0xb8×1 / 0xa4×1 / 0x6c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1769dc push {r4, r5, r6, r7, r8, lr}
 *   @0x1769e0 mov r3, #0
 *   @0x1769e4 ldr r4, [pc, #0xbc]
 *   @0x1769e8 mov r6, r0
 *   @0x1769ec ldr r7, [pc, #0xb8]
 *   @0x1769f0 mov r5, r1
 *   @0x1769f4 add r4, pc, r4
 *   @0x1769f8 ldr lr, [pc, #0xb0]
 *   @0x1769fc ldr r12, [pc, #0xb0]
 *   @0x176a00 mov r0, r1
 *   @0x176a04 ldr r7, [r4, r7]
 *   @0x176a08 mvn r2, #0
 *   @0x176a0c ldr r1, [pc, #0xa4]
 *   @0x176a10 str r3, [r7]
 *   @0x176a14 ldr lr, [r4, lr]
 *   @0x176a18 str r6, [lr]
 *   @0x176a1c ldr r7, [r4, r12]
 *   @0x176a20 str r2, [r7]
 *   @0x176a24 ldr r8, [r4, r1]
 *   @0x176a28 str r3, [r8]
 *   @0x176a2c bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x176a30 cmp r0, #0
 *   @0x176a34 strne r5, [r7]
 *   @0x176a38 bne 0x176a8c <_Z21GR_3D_Primitive_Beginii+0xb0>
 *   @0x176a3c cmn r5, #1
 *   @0x176a40 beq 0x176a8c <_Z21GR_3D_Primitive_Beginii+0xb0>
 *   @0x176a44 ldrsh r3, [r5, #20]
 *   @0x176a48 ldr r2, [pc, #0x6c]
 *   @0x176a4c str r5, [r8]
 *   @0x176a50 str r3, [r7]
 *   @0x176a54 ldr r0, [r4, r2]
 *   @0x176a58 ldr r1, [pc, #0x60]
 *   @0x176a5c ldr r2, [pc, #0x60]
 *   @0x176a60 ldr r0, [r0, #0x4]
 *   @0x176a64 ldr r1, [r4, r1]
 *   @0x176a68 ldr r3, [r0, r3, lsl #2]
 *   @0x176a6c ldr r3, [r3]
 *   @0x176a70 vldr s14, [r3, #4]
 *   @0x176a74 vldr s15, [r3, #8]
 *   @0x176a78 vcvt.f32.s32 s14, s14
 *   @0x176a7c vcvt.f32.s32 s15, s15
 *   @0x176a80 vstr s14, [r1]
 *   @0x176a84 ldr r3, [r4, r2]
 *   @0x176a88 vstr s15, [r3]
 *   @0x176a8c ldr r2, [pc, #0x34]
 *   @0x176a90 ldr r3, [pc, #0x34]
 *   @0x176a94 add r2, pc, r2
 *   @0x176a98 ldr r3, [r4, r3]
 *   @0x176a9c ldr r2, [r2, r6, lsl #2]
 *   @0x176aa0 str r2, [r3]
 *   @0x176aa4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x176aa8 eoreq r11, r7, r12, asr r2
 *   @0x176aac .word 0xffffe670
 *   @0x176ab0 .word 0xffffe674
 *   @0x176ab4 .word 0xffffe678
 *   @0x176ab8 .word 0xffffe540
 *   @0x176abc .word 0xffffbccc
 *   @0x176ac0 .word 0xffffe544
 *   @0x176ac4 .word 0xffffe548
 *   @0x176ac8 andseq r7, lr, r8, lsl #1
 *   @0x176acc .word 0xffffe67c
 *
 * ══ §24/127 YYObjectBase::HasValue(char const*)  0x192218  size 244  61 条（0x192218..0x19230c）
 * @func 0x192218 0x19230c  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Variable_Find_Slot_From_Name(YYObjectBase*, char const*) / CHashMapCalculateHash(int) / YYObjectBase::HasValue(char const*)+0xbc
 * 字段偏移 top8: 0x8×3 / 0x60×2 / 0x10×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x192218 ldr r3, [r0, #0x60]
 *   @0x19221c push {r4, r5, r6, r7, r8, lr}
 *   @0x192220 cmp r3, #0
 *   @0x192224 mov r4, r0
 *   @0x192228 beq 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc>
 *   @0x19222c bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc>
 *   @0x192230 cmn r0, #1
 *   @0x192234 beq 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc>
 *   @0x192238 ldr r5, [r4, #0x60]
 *   @0x19223c bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x192240 ldr r1, [r5, #0x8]
 *   @0x192244 ldr r7, [r5, #0x10]
 *   @0x192248 bic r0, r0, #-2147483648
 *   @0x19224c and r3, r0, r1
 *   @0x192250 lsl r4, r3, #1
 *   @0x192254 add r2, r4, r3
 *   @0x192258 add r2, r7, r2, lsl #2
 *   @0x19225c ldr r2, [r2, #0x8]
 *   @0x192260 cmp r2, #0
 *   @0x192264 beq 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc>
 *   @0x192268 cmp r0, r2
 *   @0x19226c beq 0x1922e4 <_ZN12YYObjectBase8HasValueEPKc+0xcc>
 *   @0x192270 ldr r8, [r5]
 *   @0x192274 and r2, r1, r2
 *   @0x192278 add r12, r3, r8
 *   @0x19227c rsb r2, r2, r12
 *   @0x192280 tst r2, r1
 *   @0x192284 bmi 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc>
 *   @0x192288 mov r12, #0
 *   @0x19228c b 0x1922a0 <_ZN12YYObjectBase8HasValueEPKc+0x88>
 *   @0x192290 cmp r0, r2
 *   @0x192294 beq 0x1922dc <_ZN12YYObjectBase8HasValueEPKc+0xc4>
 *   @0x192298 cmp r5, r12
 *   @0x19229c blt 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc>
 *   @0x1922a0 add r3, r3, #1
 *   @0x1922a4 add r12, r12, #1
 *   @0x1922a8 and r3, r1, r3
 *   @0x1922ac add r6, r3, r8
 *   @0x1922b0 lsl r4, r3, #1
 *   @0x1922b4 add r2, r4, r3
 *   @0x1922b8 add r2, r7, r2, lsl #2
 *   @0x1922bc ldr r2, [r2, #0x8]
 *   @0x1922c0 and r5, r1, r2
 *   @0x1922c4 cmp r2, #0
 *   @0x1922c8 rsb r5, r5, r6
 *   @0x1922cc and r5, r5, r1
 *   @0x1922d0 bne 0x192290 <_ZN12YYObjectBase8HasValueEPKc+0x78>
 *   @0x1922d4 mov r0, #0
 *   @0x1922d8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1922dc cmn r3, #1
 *   @0x1922e0 beq 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc>
 *   @0x1922e4 add r3, r4, r3
 *   @0x1922e8 add r7, r7, r3, lsl #2
 *   @0x1922ec cmn r7, #4
 *   @0x1922f0 beq 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc>
 *   @0x1922f4 ldr r2, [r7, #0x4]
 *   @0x1922f8 mvn r3, #-16777216
 *   @0x1922fc ldr r0, [r2, #0xc]
 *   @0x192300 subs r0, r0, r3
 *   @0x192304 movne r0, #1
 *   @0x192308 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §25/127 CLayerManager::RemoveTilemapElement(CLayer*, CLayerTilemapElement*)  0x1b7dcc  size 244  61 条（0x1b7dcc..0x1b7ec0）
 * @func 0x1b7dcc 0x1b7ec0  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryInWad(void*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x34×4 / 0x8×3 / 0x18×2 / 0x14×2 / 0x60×2 / 0x70×1 / 0xc×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b7dcc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1b7dd0 mov r5, r0
 *   @0x1b7dd4 ldr r0, [r1, #0x34]
 *   @0x1b7dd8 mov r4, r1
 *   @0x1b7ddc bl 0x1aad50 <_Z11MemoryInWadPv>
 *   @0x1b7de0 cmp r0, #0
 *   @0x1b7de4 bne 0x1b7df8 <_ZN13CLayerManager20RemoveTilemapElementEP6CLayerP20CLayerTilemapElement+0x2c>
 *   @0x1b7de8 ldr r0, [r4, #0x34]
 *   @0x1b7dec cmp r0, #0
 *   @0x1b7df0 beq 0x1b7df8 <_ZN13CLayerManager20RemoveTilemapElementEP6CLayerP20CLayerTilemapElement+0x2c>
 *   @0x1b7df4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b7df8 ldr r3, [r4, #0x18]
 *   @0x1b7dfc mov r2, #0
 *   @0x1b7e00 str r2, [r4, #0x34]
 *   @0x1b7e04 mvn r0, #0
 *   @0x1b7e08 cmp r3, r2
 *   @0x1b7e0c ldr r2, [r4, #0x14]
 *   @0x1b7e10 ldr r9, [r5, #0x60]
 *   @0x1b7e14 mov r1, #0
 *   @0x1b7e18 mov r7, #5
 *   @0x1b7e1c mvn r6, #-2147483648
 *   @0x1b7e20 strne r2, [r3, #0x14]
 *   @0x1b7e24 add r9, r9, r0
 *   @0x1b7e28 ldrne r2, [r4, #0x14]
 *   @0x1b7e2c ldrne r3, [r4, #0x18]
 *   @0x1b7e30 streq r2, [r5, #0x58]
 *   @0x1b7e34 cmp r2, #0
 *   @0x1b7e38 streq r3, [r5, #0x5c]
 *   @0x1b7e3c strne r3, [r2, #0x18]
 *   @0x1b7e40 mov r3, #0
 *   @0x1b7e44 ldr r2, [pc, #0x70]
 *   @0x1b7e48 str r9, [r5, #0x60]
 *   @0x1b7e4c ldr r2, [pc, r2]
 *   @0x1b7e50 str r3, [r4, #0xc]
 *   @0x1b7e54 str r1, [r4, #0x20]
 *   @0x1b7e58 ldr r12, [r2]
 *   @0x1b7e5c ldr r8, [r2, #0x8]
 *   @0x1b7e60 cmp r12, r3
 *   @0x1b7e64 str r7, [r4]
 *   @0x1b7e68 str r0, [r4, #0x4]
 *   @0x1b7e6c add r5, r8, #1
 *   @0x1b7e70 strb r3, [r4, #0x8]
 *   @0x1b7e74 str r3, [r4, #0x10]
 *   @0x1b7e78 str r1, [r4, #0x24]
 *   @0x1b7e7c str r3, [r4, #0x14]
 *   @0x1b7e80 str r1, [r4, #0x30]
 *   @0x1b7e84 str r3, [r4, #0x18]
 *   @0x1b7e88 str r3, [r4, #0x28]
 *   @0x1b7e8c str r3, [r4, #0x2c]
 *   @0x1b7e90 str r3, [r4, #0x34]
 *   @0x1b7e94 str r0, [r4, #0x1c]
 *   @0x1b7e98 str r6, [r4, #0x38]
 *   @0x1b7e9c str r5, [r2, #0x8]
 *   @0x1b7ea0 streq r4, [r2, #0x4]
 *   @0x1b7ea4 streq r4, [r2]
 *   @0x1b7ea8 strne r4, [r12, #0x18]
 *   @0x1b7eac strne r4, [r2]
 *   @0x1b7eb0 strne r12, [r4, #0x14]
 *   @0x1b7eb4 strne r3, [r4, #0x18]
 *   @0x1b7eb8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1b7ebc eoreq r8, r3, r4, lsr #20
 *
 * ══ §26/127 CListener::Update()  0x215b48  size 244  61 条（0x215b48..0x215c3c）
 * @func 0x215b48 0x215c3c  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x215bbc→0x3eb70c, 0x215be0→0x3eb70c, 0x215c04→0x3eb70c
 * 调用序列: 0xb6a54×3 / 0xb6a48×2 / 0xb6a3c / 0xb6a60
 * 字段偏移 top8: 0xc×4 / 0x68×2 / 0xcc×1 / 0x4×1 / 0x8×1 / 0x10×1 / 0x14×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215b48 push {r3, r4, r5, lr}
 *   @0x215b4c mov r4, r0
 *   @0x215b50 bl 0xb6a3c <alcGetCurrentContext@plt>
 *   @0x215b54 ldr r5, [pc, #0xcc]
 *   @0x215b58 add r5, pc, r5
 *   @0x215b5c cmp r0, #0
 *   @0x215b60 popeq {r3, r4, r5, pc}
 *   @0x215b64 ldr r2, [r4, #0x4]
 *   @0x215b68 movw r0, #0x1004
 *   @0x215b6c ldr r1, [r4]
 *   @0x215b70 ldr r3, [r4, #0x8]
 *   @0x215b74 bl 0xb6a48 <alListener3f@plt>
 *   @0x215b78 bl 0xb6a54 <alGetError@plt>
 *   @0x215b7c subs r2, r0, #0
 *   @0x215b80 bne 0x215c04 <_ZN9CListener6UpdateEv+0xbc>
 *   @0x215b84 ldr r2, [r4, #0x10]
 *   @0x215b88 movw r0, #0x1006
 *   @0x215b8c ldr r1, [r4, #0xc]
 *   @0x215b90 ldr r3, [r4, #0x14]
 *   @0x215b94 bl 0xb6a48 <alListener3f@plt>
 *   @0x215b98 bl 0xb6a54 <alGetError@plt>
 *   @0x215b9c subs r2, r0, #0
 *   @0x215ba0 bne 0x215be0 <_ZN9CListener6UpdateEv+0x98>
 *   @0x215ba4 add r1, r4, #24
 *   @0x215ba8 movw r0, #0x100f
 *   @0x215bac bl 0xb6a60 <alListenerfv@plt>
 *   @0x215bb0 bl 0xb6a54 <alGetError@plt>
 *   @0x215bb4 subs r2, r0, #0
 *   @0x215bb8 popeq {r3, r4, r5, pc}
 *   @0x215bbc ldr r3, [pc, #0x68]
 *   @0x215bc0 ldr r1, [pc, #0x68]
 *   @0x215bc4 ldr r3, [r5, r3]
 *   @0x215bc8 add r1, pc, r1
 *   @0x215bcc ldr r0, [r3]
 *   @0x215bd0 ldr r3, [r0]
 *   @0x215bd4 ldr r3, [r3, #0xc]
 *   @0x215bd8 blx r3
 *   @0x215bdc pop {r3, r4, r5, pc}
 *   @0x215be0 ldr r3, [pc, #0x44]
 *   @0x215be4 ldr r1, [pc, #0x48]
 *   @0x215be8 ldr r3, [r5, r3]
 *   @0x215bec add r1, pc, r1
 *   @0x215bf0 ldr r0, [r3]
 *   @0x215bf4 ldr r3, [r0]
 *   @0x215bf8 ldr r3, [r3, #0xc]
 *   @0x215bfc blx r3
 *   @0x215c00 b 0x215ba4 <_ZN9CListener6UpdateEv+0x5c>
 *   @0x215c04 ldr r3, [pc, #0x20]
 *   @0x215c08 ldr r1, [pc, #0x28]
 *   @0x215c0c ldr r3, [r5, r3]
 *   @0x215c10 add r1, pc, r1
 *   @0x215c14 ldr r0, [r3]
 *   @0x215c18 ldr r3, [r0]
 *   @0x215c1c ldr r3, [r3, #0xc]
 *   @0x215c20 blx r3
 *   @0x215c24 b 0x215b84 <_ZN9CListener6UpdateEv+0x3c>
 *   @0x215c28 ldrsheq r12, [sp], -r8
 *   @0x215c2c .word 0xffffbac4
 *   @0x215c30 andseq sp, r3, r4, lsr #30
 *   @0x215c34 ldrsbeq sp, [r3], -r12
 *   @0x215c38 mulseq r3, r4, lr
 *
 * ══ §27/127 vorbis_comment_query  0x22aa8c  size 244  61 条（0x22aa8c..0x22ab80）
 * @func 0x22aa8c 0x22ab80  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / 0xb65bc / vorbis_comment_query+0xc0 / anon_229e24+0xbd4 / 0xb65d4
 * 字段偏移 top8: 0x-30×2 / 0x-34×2 / 0x-28×2 / 0xdc×1 / 0x8c×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22aa8c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22aa90 add r11, sp, #32
 *   @0x22aa94 ldr r3, [pc, #0xdc]
 *   @0x22aa98 sub sp, sp, #20
 *   @0x22aa9c str r2, [r11, #-0x30]
 *   @0x22aaa0 ldr r3, [pc, r3]
 *   @0x22aaa4 mov r9, r0
 *   @0x22aaa8 mov r0, r1
 *   @0x22aaac mov r5, r1
 *   @0x22aab0 ldr r2, [r3]
 *   @0x22aab4 str r3, [r11, #-0x34]
 *   @0x22aab8 str r2, [r11, #-0x28]
 *   @0x22aabc bl 0xb6538 <strlen@plt>
 *   @0x22aac0 mov r1, r5
 *   @0x22aac4 add r2, r0, #16
 *   @0x22aac8 mov r4, r0
 *   @0x22aacc bic r2, r2, #7
 *   @0x22aad0 add r8, r0, #1
 *   @0x22aad4 sub sp, sp, r2
 *   @0x22aad8 mov r2, r0
 *   @0x22aadc mov r0, sp
 *   @0x22aae0 mov r6, sp
 *   @0x22aae4 bl 0xb65bc <memcpy@plt>
 *   @0x22aae8 ldr r2, [pc, #0x8c]
 *   @0x22aaec ldr r7, [r9, #0x8]
 *   @0x22aaf0 add r2, pc, r2
 *   @0x22aaf4 cmp r7, #0
 *   @0x22aaf8 ldrh r2, [r2]
 *   @0x22aafc strh r2, [sp, r4]
 *   @0x22ab00 ble 0x22ab4c <vorbis_comment_query+0xc0>
 *   @0x22ab04 ldr r3, [r9]
 *   @0x22ab08 mov r5, #0
 *   @0x22ab0c mov r4, r5
 *   @0x22ab10 sub r9, r3, #4
 *   @0x22ab14 ldr r10, [r9, #0x4]!
 *   @0x22ab18 mov r1, r6
 *   @0x22ab1c mov r2, r8
 *   @0x22ab20 mov r0, r10
 *   @0x22ab24 bl 0x22a9f8 <vorbis_lsp_to_curve+0x114c>
 *   @0x22ab28 cmp r0, #0
 *   @0x22ab2c bne 0x22ab40 <vorbis_comment_query+0xb4>
 *   @0x22ab30 ldr r3, [r11, #-0x30]
 *   @0x22ab34 cmp r3, r5
 *   @0x22ab38 beq 0x22ab6c <vorbis_comment_query+0xe0>
 *   @0x22ab3c add r5, r5, #1
 *   @0x22ab40 add r4, r4, #1
 *   @0x22ab44 cmp r4, r7
 *   @0x22ab48 bne 0x22ab14 <vorbis_comment_query+0x88>
 *   @0x22ab4c mov r0, #0
 *   @0x22ab50 ldr r1, [r11, #-0x34]
 *   @0x22ab54 ldr r2, [r11, #-0x28]
 *   @0x22ab58 ldr r3, [r1]
 *   @0x22ab5c cmp r2, r3
 *   @0x22ab60 bne 0x22ab74 <vorbis_comment_query+0xe8>
 *   @0x22ab64 sub sp, r11, #32
 *   @0x22ab68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22ab6c add r0, r10, r8
 *   @0x22ab70 b 0x22ab50 <vorbis_comment_query+0xc4>
 *   @0x22ab74 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x22ab78 ldrheq r2, [r12], -r0
 *   @0x22ab7c andseq r10, r2, r0, ror #11
 *
 * ══ §28/127 spSkeleton_setBonesToSetupPose  0x289f70  size 244  61 条（0x289f70..0x28a064）
 * @func 0x289f70 0x28a064  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_setBonesToSetupPose+0x34 / spBone_setToSetupPose / spSkeleton_setBonesToSetupPose+0x68 / spSkeleton_setBonesToSetupPose+0xac
 * 字段偏移 top8: 0x4×5 / 0x14×5 / 0x10×5 / 0x1c×4 / 0x18×3 / 0x28×2 / 0x8×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x289f70 push {r3, r4, r5, lr}
 *   @0x289f74 mov r5, r0
 *   @0x289f78 ldr r3, [r0, #0x4]
 *   @0x289f7c cmp r3, #0
 *   @0x289f80 movgt r4, #0
 *   @0x289f84 ble 0x289fa4 <spSkeleton_setBonesToSetupPose+0x34>
 *   @0x289f88 ldr r3, [r5, #0x8]
 *   @0x289f8c ldr r0, [r3, r4, lsl #2]
 *   @0x289f90 add r4, r4, #1
 *   @0x289f94 bl 0x285388 <spBone_setToSetupPose>
 *   @0x289f98 ldr r3, [r5, #0x4]
 *   @0x289f9c cmp r3, r4
 *   @0x289fa0 bgt 0x289f88 <spSkeleton_setBonesToSetupPose+0x18>
 *   @0x289fa4 ldr r12, [r5, #0x1c]
 *   @0x289fa8 cmp r12, #0
 *   @0x289fac ldrgt r2, [r5, #0x20]
 *   @0x289fb0 addgt r12, r2, r12, lsl #2
 *   @0x289fb4 ble 0x289fd8 <spSkeleton_setBonesToSetupPose+0x68>
 *   @0x289fb8 ldr r3, [r2], #4
 *   @0x289fbc cmp r2, r12
 *   @0x289fc0 ldr r1, [r3]
 *   @0x289fc4 ldr r0, [r1, #0x14]
 *   @0x289fc8 ldr r1, [r1, #0x10]
 *   @0x289fcc str r0, [r3, #0x14]
 *   @0x289fd0 str r1, [r3, #0x10]
 *   @0x289fd4 bne 0x289fb8 <spSkeleton_setBonesToSetupPose+0x48>
 *   @0x289fd8 ldr r4, [r5, #0x28]
 *   @0x289fdc cmp r4, #0
 *   @0x289fe0 ldrgt r1, [r5, #0x2c]
 *   @0x289fe4 addgt r4, r1, r4, lsl #2
 *   @0x289fe8 ble 0x28a01c <spSkeleton_setBonesToSetupPose+0xac>
 *   @0x289fec ldr r3, [r1], #4
 *   @0x289ff0 cmp r1, r4
 *   @0x289ff4 ldr r2, [r3]
 *   @0x289ff8 ldr r0, [r2, #0x14]
 *   @0x289ffc ldr r12, [r2, #0x10]
 *   @0x28a000 str r0, [r3, #0x14]
 *   @0x28a004 ldr r0, [r2, #0x18]
 *   @0x28a008 ldr r2, [r2, #0x1c]
 *   @0x28a00c str r12, [r3, #0x10]
 *   @0x28a010 str r0, [r3, #0x18]
 *   @0x28a014 str r2, [r3, #0x1c]
 *   @0x28a018 bne 0x289fec <spSkeleton_setBonesToSetupPose+0x7c>
 *   @0x28a01c ldr r4, [r5, #0x30]
 *   @0x28a020 cmp r4, #0
 *   @0x28a024 pople {r3, r4, r5, pc}
 *   @0x28a028 ldr r1, [r5, #0x34]
 *   @0x28a02c add r4, r1, r4, lsl #2
 *   @0x28a030 ldr r3, [r1], #4
 *   @0x28a034 cmp r1, r4
 *   @0x28a038 ldr r2, [r3]
 *   @0x28a03c ldr r0, [r2, #0x24]
 *   @0x28a040 ldr r12, [r2, #0x20]
 *   @0x28a044 str r0, [r3, #0x14]
 *   @0x28a048 ldr r0, [r2, #0x28]
 *   @0x28a04c ldr r2, [r2, #0x2c]
 *   @0x28a050 str r12, [r3, #0x10]
 *   @0x28a054 str r0, [r3, #0x18]
 *   @0x28a058 str r2, [r3, #0x1c]
 *   @0x28a05c bne 0x28a030 <spSkeleton_setBonesToSetupPose+0xc0>
 *   @0x28a060 pop {r3, r4, r5, pc}
 *
 * ══ §29/127 yySocket::SendPacket(unsigned char*, int)  0x296944  size 244  61 条（0x296944..0x296a38）
 * @func 0x296944 0x296a38  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / debug_display_buffer(tagIConsole&, unsigned char*, int)
 * 字段偏移 top8: 0x58×4 / 0x38×2 / 0xdc×1 / 0x5c×1 / 0x8×1 / 0x4×1 / 0x60×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x296944 ldr r3, [pc, #0xdc]
 *   @0x296948 push {r4, r5, r6, r7, lr}
 *   @0x29694c ldr r3, [pc, r3]
 *   @0x296950 sub sp, sp, #12
 *   @0x296954 mov r4, r0
 *   @0x296958 ldrb r3, [r3]
 *   @0x29695c mov r7, r1
 *   @0x296960 mov r5, r2
 *   @0x296964 cmp r3, #0
 *   @0x296968 bne 0x2969f0 <_ZN8yySocket10SendPacketEPhi+0xac>
 *   @0x29696c ldr r3, [r4, #0x5c]
 *   @0x296970 add r6, r5, #12
 *   @0x296974 cmp r6, r3
 *   @0x296978 bgt 0x2969c4 <_ZN8yySocket10SendPacketEPhi+0x80>
 *   @0x29697c ldr r3, [r4, #0x58]
 *   @0x296980 mov r1, r7
 *   @0x296984 mov r2, r5
 *   @0x296988 add r0, r3, #12
 *   @0x29698c bl 0xb65bc <memcpy@plt>
 *   @0x296990 ldr r3, [r4, #0x58]
 *   @0x296994 mov r12, #12
 *   @0x296998 mov r2, r6
 *   @0x29699c movw r1, #0xc0de
 *   @0x2969a0 mov r0, r4
 *   @0x2969a4 movt r1, #0xdead
 *   @0x2969a8 str r5, [r3, #0x8]
 *   @0x2969ac str r1, [r3]
 *   @0x2969b0 mov r1, r3
 *   @0x2969b4 str r12, [r3, #0x4]
 *   @0x2969b8 add sp, sp, #12
 *   @0x2969bc pop {r4, r5, r6, r7, lr}
 *   @0x2969c0 b 0x295464 <_ZN8yySocket5WriteEPvj>
 *   @0x2969c4 ldr r2, [pc, #0x60]
 *   @0x2969c8 mov r3, #0
 *   @0x2969cc ldr r0, [r4, #0x58]
 *   @0x2969d0 mov r1, r6
 *   @0x2969d4 str r3, [sp]
 *   @0x2969d8 add r2, pc, r2
 *   @0x2969dc mov r3, #74
 *   @0x2969e0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x2969e4 mov r3, r0
 *   @0x2969e8 str r0, [r4, #0x58]
 *   @0x2969ec b 0x296980 <_ZN8yySocket10SendPacketEPhi+0x3c>
 *   @0x2969f0 ldr r3, [pc, #0x38]
 *   @0x2969f4 ldr r1, [pc, #0x38]
 *   @0x2969f8 ldr r3, [pc, r3]
 *   @0x2969fc add r1, pc, r1
 *   @0x296a00 ldr r6, [r3]
 *   @0x296a04 ldr r3, [r6]
 *   @0x296a08 mov r0, r6
 *   @0x296a0c ldr r3, [r3, #0xc]
 *   @0x296a10 blx r3
 *   @0x296a14 mov r0, r6
 *   @0x296a18 mov r1, r7
 *   @0x296a1c mov r2, r5
 *   @0x296a20 bl 0x2967e8 <_Z20debug_display_bufferR11tagIConsolePhi>
 *   @0x296a24 b 0x29696c <_ZN8yySocket10SendPacketEPhi+0x28>
 *   @0x296a28 andseq r11, r5, r12, asr #32
 *   @0x296a2c andeq r10, r9, r8, asr r6
 *   @0x296a30 andseq r6, r5, r12, lsl sp
 *   @0x296a34 andeq r2, r12, r12, lsl #22
 *
 * ══ §30/127 F_NETWORK_Connect(RValue&, CInstance*, CInstance*, int, RValue*)  0x298178  size 244  61 条（0x298178..0x29826c）
 * @func 0x298178 0x298280  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_NETWORK_Connect(RValue&, CInstance*, CInstance*, int, RValue*)+0xd0 / YYGetString(RValue const*, int) / yySocket::ConnectGMS(char*, int) / yySocket::Startup()
 * 字段偏移 top8: 0x4×2 / 0x18×2 / 0xd4×1 / 0xc×1 / 0xa4×1 / 0x80×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x298178 push {r3, r4, r5, r6, r7, lr}
 *   @0x29817c mov r2, #0
 *   @0x298180 ldr r5, [pc, #0xd4]
 *   @0x298184 mov r6, r3
 *   @0x298188 str r2, [r0]
 *   @0x29818c mov r4, r0
 *   @0x298190 ldr r5, [pc, r5]
 *   @0x298194 str r2, [r0, #0xc]
 *   @0x298198 str r2, [r0, #0x4]
 *   @0x29819c ldrb r3, [r5]
 *   @0x2981a0 ldr r7, [sp, #0x18]
 *   @0x2981a4 cmp r3, r2
 *   @0x2981a8 beq 0x298238 <_Z17F_NETWORK_ConnectR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x2981ac cmp r6, #3
 *   @0x2981b0 beq 0x2981c8 <_Z17F_NETWORK_ConnectR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x2981b4 ldr r0, [pc, #0xa4]
 *   @0x2981b8 mov r1, #0
 *   @0x2981bc pop {r3, r4, r5, r6, r7, lr}
 *   @0x2981c0 add r0, pc, r0
 *   @0x2981c4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x2981c8 mov r0, r7
 *   @0x2981cc mov r1, #0
 *   @0x2981d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x2981d4 cmp r0, #0
 *   @0x2981d8 blt 0x298248 <_Z17F_NETWORK_ConnectR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x2981dc ldr r3, [pc, #0x80]
 *   @0x2981e0 add r2, r0, r0, lsl #1
 *   @0x2981e4 mov r1, #1
 *   @0x2981e8 mov r0, r7
 *   @0x2981ec ldr r3, [pc, r3]
 *   @0x2981f0 add r3, r3, r2, lsl #2
 *   @0x2981f4 ldr r6, [r3, #0x4]
 *   @0x2981f8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x2981fc mov r1, #2
 *   @0x298200 mov r5, r0
 *   @0x298204 mov r0, r7
 *   @0x298208 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29820c mov r1, r5
 *   @0x298210 mov r2, r0
 *   @0x298214 mov r0, r6
 *   @0x298218 bl 0x2966ac <_ZN8yySocket10ConnectGMSEPci>
 *   @0x29821c vmov s15, r0
 *   @0x298220 vcvt.f64.s32 d7, s15
 *   @0x298224 vmov r0, r1, d7
 *   @0x298228 vmov r2, s14
 *   @0x29822c mov r3, r1
 *   @0x298230 stm r4, {r2, r3}
 *   @0x298234 pop {r3, r4, r5, r6, r7, pc}
 *   @0x298238 bl 0x294d18 <_ZN8yySocket7StartupEv>
 *   @0x29823c mov r3, #1
 *   @0x298240 strb r3, [r5]
 *   @0x298244 b 0x2981ac <_Z17F_NETWORK_ConnectR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x298248 ldr r0, [pc, #0x18]
 *   @0x29824c mov r1, #0
 *   @0x298250 pop {r3, r4, r5, r6, r7, lr}
 *   @0x298254 add r0, pc, r0
 *   @0x298258 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x29825c andseq r9, r5, r12, lsl #16
 *   @0x298260 andeq lr, r10, r8, lsl #8
 *   @0x298264 ldrheq r9, [r5], -r8
 *   @0x298268 andeq r1, r12, r0, ror #7
 *
 * ══ §31/127 png_set_unknown_chunks  0x2af340  size 244  61 条（0x2af340..0x2af434）
 * @func 0x2af340 0x2af434  size 244  61 条
 * 部分覆盖: 本节 61/106 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x51b632 / png_warning / 0xb65bc
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x8×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af340 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2af344 mov r4, r1
 *   @0x2af348 mov r7, r3
 *   @0x2af34c cmp r0, #0x0
 *   @0x2af350 cmp r1, #0x0
 *   @0x2af354 cmp r3, #0x0
 *   @0x2af358 ldr.w r1, [r1, #0xc0]
 *   @0x2af35c mov.w r9, #0x14
 *   @0x2af360 add r1, r3
 *   @0x2af364 .word 0xf7f7f101
 *   @0x2af368 pkhtbmi pc, r0, r6, asr #25
 *   @0x2af36c cbnz r0, 0x2af37e <png_set_unknown_chunks+0x3e>
 *   @0x2af370 mov r0, r6
 *   @0x2af374 add sp, #0xc
 *   @0x2af378 .word 0xf7f74ff0
 *   @0x2af37c .word 0xf8d4b87b
 *   @0x2af380 .word 0xf8d420c0
 *   @0x2af384 .word 0xf8df10bc
 *   @0x2af388 blx 0x51b632 <SrcVerts+0x78676>
 *   @0x2af38c .word 0xf607f202
 *   @0x2af390 shadd16mi lr, r0, r6
 *   @0x2af394 ldr.w r1, [r4, #0xbc]
 *   @0x2af398 add r11, pc
 *   @0x2af39c movwhs pc, #0xcaf
 *   @0x2af3a0 mov r10, r3
 *   @0x2af3a4 ldrmi r3, [r10, #0xbc]!
 *   @0x2af3a8 ldr.w r3, [r4, #0xc0]
 *   @0x2af3ac bge 0x2af410 <png_set_unknown_chunks+0xd0>
 *   @0x2af3b0 movs r1, #0x14
 *   @0x2af3b4 stmdavs r9!, {r0, r1, r9, r12, sp, lr, pc}
 *   @0x2af3b8 mov.w r3, #0x0
 *   @0x2af3bc add.w r9, r8, r2
 *   @0x2af3c0 str.w r1, [r8, r2]
 *   @0x2af3c4 strb.w r3, [r9, #0x4]
 *   @0x2af3c8 ldr r2, [r5, #0xc]
 *   @0x2af3cc .word 0xf8d6200c
 *   @0x2af3d0 .word 0xf889212c
 *   @0x2af3d4 stmvs r9!, {r4, sp} ^
 *   @0x2af3d8 cbnz r1, 0x2af3e0 <png_set_unknown_chunks+0xa0>
 *   @0x2af3dc ands r1, r3, r8
 *   @0x2af3e0 mov r0, r6
 *   @0x2af3e4 .word 0x4602fc98
 *   @0x2af3e8 str.w r0, [r9, #0x8]
 *   @0x2af3ec cbnz r0, 0x2af400 <png_set_unknown_chunks+0xc0>
 *   @0x2af3f0 mov r1, r11
 *   @0x2af3f4 bl 0x2a6474 <png_warning>
 *   @0x2af3f8 ldr r2, [sp, #0x4]
 *   @0x2af3fc and r2, r3, r12
 *   @0x2af400 ldr r1, [r5, #0x8]
 *   @0x2af404 blx 0xb65bc <memcpy@plt>
 *   @0x2af408 add.w r10, r10, #0x1
 *   @0x2af40c adds r5, #0x14
 *   @0x2af410 add r7, r3
 *   @0x2af414 .word 0xf8c430b8
 *   @0x2af418 vst4.32 {d24, d25, d26, d27}, [r3:256], r12
 *   @0x2af41c .word 0xf8c47300
 *   @0x2af420 .word 0xf8c470c0
 *   @0x2af424 strhlt r3, [r3], -r8
 *   @0x2af428 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2af42c .word 0xe9a1 000d
 *   @0x2af430 ldrd r0, r0, [r11, #-52]!
 *
 * ══ §32/127 CSkeletonInstance::RectangleCollision(int, float, float, float, float, float, float, float, float, float)  0xbf434  size 240  60 条（0xbf434..0xbf524）
 * @func 0xbf434 0xbf524  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonBounds_intersectsSegment×5 / CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*)
 * 字段偏移 top8: 0x20×5 / 0x28×1 / 0x2c×1 / 0x34×1 / 0x30×1 / 0x4×1 / 0x3c×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbf434 push {r4, r5, r6, r7, r8, lr}
 *   @0xbf438 sub sp, sp, #16
 *   @0xbf43c mov r12, #0
 *   @0xbf440 mov r6, r0
 *   @0xbf444 ldr lr, [sp, #0x28]
 *   @0xbf448 ldr r4, [sp, #0x2c]
 *   @0xbf44c ldr r7, [sp, #0x34]
 *   @0xbf450 str lr, [sp]
 *   @0xbf454 ldr lr, [sp, #0x30]
 *   @0xbf458 str r4, [sp, #0x4]
 *   @0xbf45c ldr r5, [sp, #0x3c]
 *   @0xbf460 ldr r4, [sp, #0x38]
 *   @0xbf464 ldr r8, [sp, #0x40]
 *   @0xbf468 str lr, [sp, #0x8]
 *   @0xbf46c str r12, [sp, #0xc]
 *   @0xbf470 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xbf474 ldr r0, [r6, #0x20]
 *   @0xbf478 mov r1, r7
 *   @0xbf47c str r8, [sp]
 *   @0xbf480 mov r2, r4
 *   @0xbf484 mov r3, r5
 *   @0xbf488 bl 0x28acf4 <spSkeletonBounds_intersectsSegment>
 *   @0xbf48c cmp r0, #0
 *   @0xbf490 beq 0xbf4a0 <_ZN17CSkeletonInstance18RectangleCollisionEifffffffff+0x6c>
 *   @0xbf494 mov r0, #1
 *   @0xbf498 add sp, sp, #16
 *   @0xbf49c pop {r4, r5, r6, r7, r8, pc}
 *   @0xbf4a0 ldr r0, [r6, #0x20]
 *   @0xbf4a4 mov r1, r7
 *   @0xbf4a8 str r4, [sp]
 *   @0xbf4ac mov r2, r4
 *   @0xbf4b0 mov r3, r5
 *   @0xbf4b4 bl 0x28acf4 <spSkeletonBounds_intersectsSegment>
 *   @0xbf4b8 cmp r0, #0
 *   @0xbf4bc bne 0xbf494 <_ZN17CSkeletonInstance18RectangleCollisionEifffffffff+0x60>
 *   @0xbf4c0 ldr r0, [r6, #0x20]
 *   @0xbf4c4 mov r1, r5
 *   @0xbf4c8 str r8, [sp]
 *   @0xbf4cc mov r2, r4
 *   @0xbf4d0 mov r3, r5
 *   @0xbf4d4 bl 0x28acf4 <spSkeletonBounds_intersectsSegment>
 *   @0xbf4d8 cmp r0, #0
 *   @0xbf4dc bne 0xbf494 <_ZN17CSkeletonInstance18RectangleCollisionEifffffffff+0x60>
 *   @0xbf4e0 ldr r0, [r6, #0x20]
 *   @0xbf4e4 mov r1, r5
 *   @0xbf4e8 str r8, [sp]
 *   @0xbf4ec mov r2, r8
 *   @0xbf4f0 mov r3, r7
 *   @0xbf4f4 bl 0x28acf4 <spSkeletonBounds_intersectsSegment>
 *   @0xbf4f8 cmp r0, #0
 *   @0xbf4fc bne 0xbf494 <_ZN17CSkeletonInstance18RectangleCollisionEifffffffff+0x60>
 *   @0xbf500 str r4, [sp]
 *   @0xbf504 mov r1, r7
 *   @0xbf508 ldr r0, [r6, #0x20]
 *   @0xbf50c mov r2, r8
 *   @0xbf510 mov r3, r7
 *   @0xbf514 bl 0x28acf4 <spSkeletonBounds_intersectsSegment>
 *   @0xbf518 adds r0, r0, #0
 *   @0xbf51c movne r0, #1
 *   @0xbf520 b 0xbf498 <_ZN17CSkeletonInstance18RectangleCollisionEifffffffff+0x64>
 *
 * ══ §33/127 CBackground::DrawStretched(float, float, float, float, unsigned int, float)  0xc2094  size 240  60 条（0xc2094..0xc2184）
 * @func 0xc2094 0xc2184  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::DrawStretched(float, float, float, float, unsigned int, float)+0x9c×4 / GR_Texture_Draw(YYTPageEntry*, float, float, float, float, float, float, float, unsigned int, float) / GR_Texture_Draw(int, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0xc×3 / 0x2c×2 / 0x10×2 / 0x4×1 / 0x14×1
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2094 vmov s15, r3
 *   @0xc2098 mov r12, #0
 *   @0xc209c push {r4, r5, lr}
 *   @0xc20a0 vcmpe.f32 s15, #0
 *   @0xc20a4 sub sp, sp, #28
 *   @0xc20a8 mov r3, r1
 *   @0xc20ac vldr s14, [sp, #40]
 *   @0xc20b0 vmrs APSR_nzcv, fpscr
 *   @0xc20b4 bls 0xc2130 <_ZN11CBackground13DrawStretchedEffffjf+0x9c>
 *   @0xc20b8 vcmpe.f32 s14, #0
 *   @0xc20bc vmrs APSR_nzcv, fpscr
 *   @0xc20c0 bls 0xc2130 <_ZN11CBackground13DrawStretchedEffffjf+0x9c>
 *   @0xc20c4 ldr r4, [r0]
 *   @0xc20c8 cmp r4, #0
 *   @0xc20cc ble 0xc2130 <_ZN11CBackground13DrawStretchedEffffjf+0x9c>
 *   @0xc20d0 ldr r5, [r0, #0x4]
 *   @0xc20d4 cmp r5, #0
 *   @0xc20d8 ble 0xc2130 <_ZN11CBackground13DrawStretchedEffffjf+0x9c>
 *   @0xc20dc ldr lr, [r0, #0x14]
 *   @0xc20e0 cmp lr, #0
 *   @0xc20e4 beq 0xc2138 <_ZN11CBackground13DrawStretchedEffffjf+0xa4>
 *   @0xc20e8 vmov s11, r4
 *   @0xc20ec str r2, [sp]
 *   @0xc20f0 ldr r2, [sp, #0x2c]
 *   @0xc20f4 mov r1, r12
 *   @0xc20f8 vcvt.f32.s32 s12, s11
 *   @0xc20fc vldr s11, [sp, #48]
 *   @0xc2100 vstr s11, [sp, #20]
 *   @0xc2104 vmov s11, r5
 *   @0xc2108 str r2, [sp, #0x10]
 *   @0xc210c mov r0, lr
 *   @0xc2110 str r12, [sp, #0xc]
 *   @0xc2114 mov r2, r12
 *   @0xc2118 vcvt.f32.s32 s13, s11
 *   @0xc211c vdiv.f32 s15, s15, s12
 *   @0xc2120 vdiv.f32 s14, s14, s13
 *   @0xc2124 vstr s15, [sp, #4]
 *   @0xc2128 vstr s14, [sp, #8]
 *   @0xc212c bl 0x174ee0 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf>
 *   @0xc2130 add sp, sp, #28
 *   @0xc2134 pop {r4, r5, pc}
 *   @0xc2138 ldr r0, [r0, #0xc]
 *   @0xc213c vmov s13, r4
 *   @0xc2140 vldr s11, [sp, #48]
 *   @0xc2144 vstr s11, [sp, #20]
 *   @0xc2148 vmov s11, r5
 *   @0xc214c str r2, [sp]
 *   @0xc2150 vcvt.f32.s32 s12, s13
 *   @0xc2154 ldr r2, [sp, #0x2c]
 *   @0xc2158 mov r1, r12
 *   @0xc215c str r12, [sp, #0xc]
 *   @0xc2160 str r2, [sp, #0x10]
 *   @0xc2164 mov r2, r12
 *   @0xc2168 vcvt.f32.s32 s13, s11
 *   @0xc216c vdiv.f32 s15, s15, s12
 *   @0xc2170 vdiv.f32 s14, s14, s13
 *   @0xc2174 vstr s15, [sp, #4]
 *   @0xc2178 vstr s14, [sp, #8]
 *   @0xc217c bl 0x174c40 <_Z15GR_Texture_Drawifffffffjf>
 *   @0xc2180 b 0xc2130 <_ZN11CBackground13DrawStretchedEffffjf+0x9c>
 *
 * ══ §34/127 CExtensionFile::Assign(CExtensionFile*)  0xf516c  size 240  60 条（0xf516c..0xf525c）
 * @func 0xf516c 0xf525c  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×3 / YYStrDup(char const*)×3 / CExtensionFile::SetFunctionsCount(int) / CExtensionFile::Assign(CExtensionFile*)+0xac / CExtensionFunction::Assign(CExtensionFunction*) / CExtensionFile::SetConstantsCount(int) / CExtensionConstant::Assign(CExtensionConstant*)
 * 字段偏移 top8: 0x2×4 / 0xc×3 / 0x10×3 / 0x1c×3 / 0x28×3 / 0x4×2 / 0x18×2 / 0x24×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf516c push {r4, r5, r6, lr}
 *   @0xf5170 mov r4, r0
 *   @0xf5174 ldr r0, [r0, #0x4]
 *   @0xf5178 mov r6, r1
 *   @0xf517c cmp r0, #0
 *   @0xf5180 beq 0xf5188 <_ZN14CExtensionFile6AssignEPS_+0x1c>
 *   @0xf5184 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf5188 ldr r0, [r6, #0x4]
 *   @0xf518c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf5190 ldr r3, [r4, #0xc]
 *   @0xf5194 ldr r2, [r6, #0x8]
 *   @0xf5198 cmp r3, #0
 *   @0xf519c stmib r4, {r0, r2}
 *   @0xf51a0 beq 0xf51ac <_ZN14CExtensionFile6AssignEPS_+0x40>
 *   @0xf51a4 mov r0, r3
 *   @0xf51a8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf51ac ldr r0, [r6, #0xc]
 *   @0xf51b0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf51b4 ldr r3, [r4, #0x10]
 *   @0xf51b8 cmp r3, #0
 *   @0xf51bc str r0, [r4, #0xc]
 *   @0xf51c0 beq 0xf51cc <_ZN14CExtensionFile6AssignEPS_+0x60>
 *   @0xf51c4 mov r0, r3
 *   @0xf51c8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf51cc ldr r0, [r6, #0x10]
 *   @0xf51d0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf51d4 ldr r1, [r6, #0x1c]
 *   @0xf51d8 str r0, [r4, #0x10]
 *   @0xf51dc mov r0, r4
 *   @0xf51e0 bl 0xf504c <_ZN14CExtensionFile17SetFunctionsCountEi>
 *   @0xf51e4 ldr r3, [r4, #0x1c]
 *   @0xf51e8 cmp r3, #0
 *   @0xf51ec movgt r5, #0
 *   @0xf51f0 ble 0xf5218 <_ZN14CExtensionFile6AssignEPS_+0xac>
 *   @0xf51f4 ldr r3, [r6, #0x18]
 *   @0xf51f8 ldr r2, [r4, #0x18]
 *   @0xf51fc ldr r1, [r3, r5, lsl #2]
 *   @0xf5200 ldr r0, [r2, r5, lsl #2]
 *   @0xf5204 add r5, r5, #1
 *   @0xf5208 bl 0xf4a0c <_ZN18CExtensionFunction6AssignEPS_>
 *   @0xf520c ldr r3, [r4, #0x1c]
 *   @0xf5210 cmp r3, r5
 *   @0xf5214 bgt 0xf51f4 <_ZN14CExtensionFile6AssignEPS_+0x88>
 *   @0xf5218 mov r0, r4
 *   @0xf521c ldr r1, [r6, #0x28]
 *   @0xf5220 bl 0xf5060 <_ZN14CExtensionFile17SetConstantsCountEi>
 *   @0xf5224 ldr r3, [r4, #0x28]
 *   @0xf5228 cmp r3, #0
 *   @0xf522c pople {r4, r5, r6, pc}
 *   @0xf5230 mov r5, #0
 *   @0xf5234 ldr r3, [r6, #0x24]
 *   @0xf5238 ldr r2, [r4, #0x24]
 *   @0xf523c ldr r1, [r3, r5, lsl #2]
 *   @0xf5240 ldr r0, [r2, r5, lsl #2]
 *   @0xf5244 add r5, r5, #1
 *   @0xf5248 bl 0xf482c <_ZN18CExtensionConstant6AssignEPS_>
 *   @0xf524c ldr r3, [r4, #0x28]
 *   @0xf5250 cmp r3, r5
 *   @0xf5254 bgt 0xf5234 <_ZN14CExtensionFile6AssignEPS_+0xc8>
 *   @0xf5258 pop {r4, r5, r6, pc}
 *
 * ══ §35/127 CFontGM::Assign(CFontGM*)  0xf7dfc  size 240  60 条（0xf7dfc..0xf7eec）
 * @func 0xf7dfc 0xf7eec  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::Clear() / YYStrDup(char const*) / CFontGM::Assign(CFontGM*)+0x90 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CFontGM::Assign(CFontGM*)+0x84
 * 字段偏移 top8: 0x30×3 / 0x4×2 / 0x40×2 / 0x20×2 / 0x8×2 / 0xc×2 / 0xd×2 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf7dfc push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf7e00 mov r5, r1
 *   @0xf7e04 mov r4, r0
 *   @0xf7e08 bl 0xf70a0 <_ZN7CFontGM5ClearEv>
 *   @0xf7e0c cmp r5, #0
 *   @0xf7e10 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf7e14 ldr r0, [r5, #0x4]
 *   @0xf7e18 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf7e1c ldr r2, [r5, #0x40]
 *   @0xf7e20 ldr r3, [r5, #0x20]
 *   @0xf7e24 ldr r11, [r5, #0x8]
 *   @0xf7e28 ldrb r10, [r5, #0xc]
 *   @0xf7e2c cmp r3, #0
 *   @0xf7e30 ldrb r9, [r5, #0xd]
 *   @0xf7e34 ldr r8, [r5, #0x18]
 *   @0xf7e38 ldr r7, [r5, #0x1c]
 *   @0xf7e3c ldr r6, [r5, #0x10]
 *   @0xf7e40 ldr r12, [r5, #0x14]
 *   @0xf7e44 ldr r1, [r5, #0x2c]
 *   @0xf7e48 str r2, [r4, #0x40]
 *   @0xf7e4c ldr r2, [r5, #0x44]
 *   @0xf7e50 str r11, [r4, #0x8]
 *   @0xf7e54 strb r10, [r4, #0xc]
 *   @0xf7e58 str r2, [r4, #0x44]
 *   @0xf7e5c strb r9, [r4, #0xd]
 *   @0xf7e60 str r8, [r4, #0x18]
 *   @0xf7e64 str r3, [r4, #0x20]
 *   @0xf7e68 str r7, [r4, #0x1c]
 *   @0xf7e6c str r6, [r4, #0x10]
 *   @0xf7e70 str r12, [r4, #0x14]
 *   @0xf7e74 str r1, [r4, #0x2c]
 *   @0xf7e78 str r0, [r4, #0x4]
 *   @0xf7e7c blt 0xf7e8c <_ZN7CFontGM6AssignEPS_+0x90>
 *   @0xf7e80 mov r0, r4
 *   @0xf7e84 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf7e88 b 0xf7db4 <_ZN7CFontGM11InitTextureEv>
 *   @0xf7e8c ldr r2, [r5, #0x28]
 *   @0xf7e90 movw r3, #0x271
 *   @0xf7e94 ldr r12, [r5, #0x24]
 *   @0xf7e98 add r0, r4, #52
 *   @0xf7e9c ldr r1, [r5, #0x30]
 *   @0xf7ea0 str r2, [r4, #0x28]
 *   @0xf7ea4 ldr r2, [pc, #0x3c]
 *   @0xf7ea8 str r12, [r4, #0x24]
 *   @0xf7eac add r2, pc, r2
 *   @0xf7eb0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xf7eb4 ldr r3, [r4, #0x30]
 *   @0xf7eb8 cmp r3, #0
 *   @0xf7ebc ble 0xf7e80 <_ZN7CFontGM6AssignEPS_+0x84>
 *   @0xf7ec0 mov r3, #0
 *   @0xf7ec4 ldr r1, [r5, #0x34]
 *   @0xf7ec8 ldr r2, [r4, #0x34]
 *   @0xf7ecc ldrb r1, [r1, r3]
 *   @0xf7ed0 strb r1, [r2, r3]
 *   @0xf7ed4 add r3, r3, #1
 *   @0xf7ed8 ldr r2, [r4, #0x30]
 *   @0xf7edc cmp r2, r3
 *   @0xf7ee0 bgt 0xf7ec4 <_ZN7CFontGM6AssignEPS_+0xc8>
 *   @0xf7ee4 b 0xf7e80 <_ZN7CFontGM6AssignEPS_+0x84>
 *   @0xf7ee8 eoreq pc, r3, r8, asr r11
 *
 * ══ §36/127 YYGML_ds_stack_create()  0xffcc4  size 240  60 条（0xffcc4..0xffdb4）
 * @func 0xffcc4 0xffdb4  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xffcc8→0x4836d0, 0xffcd8→0x4836d4
 * 调用序列: YYGML_ds_stack_create()+0x5c / operator new(unsigned int) / CDS_Stack::CDS_Stack() / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×3 / 0xd8×2 / 0xcc×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xffcc4 ldr r3, [pc, #0xd8]
 *   @0xffcc8 ldr r2, [pc, #0xd8]
 *   @0xffccc add r3, pc, r3
 *   @0xffcd0 push {r4, r5, r6, r7, r8, lr}
 *   @0xffcd4 ldr r8, [r3, r2]
 *   @0xffcd8 ldr r2, [pc, #0xcc]
 *   @0xffcdc ldr r5, [r8]
 *   @0xffce0 ldr r7, [r3, r2]
 *   @0xffce4 cmp r5, #0
 *   @0xffce8 ble 0xffd20 <_Z21YYGML_ds_stack_createv+0x5c>
 *   @0xffcec ldr r3, [r7, #0x4]
 *   @0xffcf0 ldr r6, [r3]
 *   @0xffcf4 cmp r6, #0
 *   @0xffcf8 beq 0xffd9c <_Z21YYGML_ds_stack_createv+0xd8>
 *   @0xffcfc mov r4, #0
 *   @0xffd00 b 0xffd10 <_Z21YYGML_ds_stack_createv+0x4c>
 *   @0xffd04 ldr r2, [r3, #0x4]!
 *   @0xffd08 cmp r2, #0
 *   @0xffd0c beq 0xffd40 <_Z21YYGML_ds_stack_createv+0x7c>
 *   @0xffd10 add r4, r4, #1
 *   @0xffd14 cmp r4, r5
 *   @0xffd18 lsl r6, r4, #2
 *   @0xffd1c bne 0xffd04 <_Z21YYGML_ds_stack_createv+0x40>
 *   @0xffd20 ldr r3, [r7]
 *   @0xffd24 cmp r5, r3
 *   @0xffd28 movlt r3, r5
 *   @0xffd2c bge 0xffd60 <_Z21YYGML_ds_stack_createv+0x9c>
 *   @0xffd30 lsl r6, r5, #2
 *   @0xffd34 mov r4, r5
 *   @0xffd38 add r3, r3, #1
 *   @0xffd3c str r3, [r8]
 *   @0xffd40 mov r0, #16
 *   @0xffd44 bl 0x27c524 <_Znwj>
 *   @0xffd48 mov r5, r0
 *   @0xffd4c bl 0x20f4dc <_ZN9CDS_StackC2Ev>
 *   @0xffd50 ldr r3, [r7, #0x4]
 *   @0xffd54 mov r0, r4
 *   @0xffd58 str r5, [r3, r6]
 *   @0xffd5c pop {r4, r5, r6, r7, r8, pc}
 *   @0xffd60 add r1, r5, #16
 *   @0xffd64 ldr r2, [pc, #0x44]
 *   @0xffd68 mov r3, #145
 *   @0xffd6c add r0, r7, #4
 *   @0xffd70 add r2, pc, r2
 *   @0xffd74 lsl r1, r1, #2
 *   @0xffd78 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xffd7c ldr r3, [r8]
 *   @0xffd80 lsl r6, r5, #2
 *   @0xffd84 mov r4, r5
 *   @0xffd88 add r2, r3, #16
 *   @0xffd8c add r3, r3, #1
 *   @0xffd90 str r2, [r7]
 *   @0xffd94 str r3, [r8]
 *   @0xffd98 b 0xffd40 <_Z21YYGML_ds_stack_createv+0x7c>
 *   @0xffd9c mov r4, r6
 *   @0xffda0 b 0xffd40 <_Z21YYGML_ds_stack_createv+0x7c>
 *   @0xffda4 eoreq r1, pc, r4, lsl #31
 *   @0xffda8 .word 0xffffc22c
 *   @0xffdac .word 0xffffc230
 *   @0xffdb0 eoreq r7, r3, r12, lsr #28
 *
 * ══ §37/127 F_DateIncMonth(RValue&, CInstance*, CInstance*, int, RValue*)  0x1157a8  size 240  60 条（0x1157a8..0x115898）
 * @func 0x1157a8 0x1158ac  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / YYGetInt32(RValue const*, int) / 0xb6814 / __floatdidf / 0x826544
 * 字段偏移 top8: 0x10×2 / 0x18×1 / 0xc×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1157a8 push {r4, r5, r6, lr}
 *   @0x1157ac sub sp, sp, #8
 *   @0x1157b0 mov r1, #0
 *   @0x1157b4 mov r4, r0
 *   @0x1157b8 ldr r6, [sp, #0x18]
 *   @0x1157bc mov r3, r1
 *   @0x1157c0 str r1, [r0, #0xc]
 *   @0x1157c4 movt r3, #0xbff0
 *   @0x1157c8 stm r0, {r1, r3}
 *   @0x1157cc mov r0, r6
 *   @0x1157d0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1157d4 vldr d7, [pc, #164]
 *   @0x1157d8 vldr d5, [pc, #168]
 *   @0x1157dc vmov d6, r0, r1
 *   @0x1157e0 vsub.f64 d7, d6, d7
 *   @0x1157e4 vabs.f64 d4, d7
 *   @0x1157e8 vcmpe.f64 d4, d5
 *   @0x1157ec vmrs APSR_nzcv, fpscr
 *   @0x1157f0 vldrls d7, [pc, #152]
 *   @0x1157f4 vldrhi d6, [pc, #148]
 *   @0x1157f8 vmulls.f64 d4, d6, d7
 *   @0x1157fc vmulhi.f64 d5, d7, d6
 *   @0x115800 vmovls r0, r1, d4
 *   @0x115804 vmovhi r0, r1, d5
 *   @0x115808 bl 0x3194a0 <__fixdfdi>
 *   @0x11580c mov r2, r0
 *   @0x115810 add r0, sp, #8
 *   @0x115814 mov r3, r1
 *   @0x115818 strd r2, r3, [r0, #-8]!
 *   @0x11581c mov r0, sp
 *   @0x115820 bl 0xb6820 <gmtime64@plt>
 *   @0x115824 subs r5, r0, #0
 *   @0x115828 beq 0x115874 <_Z14F_DateIncMonthR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x11582c mov r0, r6
 *   @0x115830 mov r1, #1
 *   @0x115834 ldr r6, [r5, #0x10]
 *   @0x115838 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11583c add r6, r6, r0
 *   @0x115840 mov r0, r5
 *   @0x115844 str r6, [r5, #0x10]
 *   @0x115848 bl 0xb6814 <timegm64@plt>
 *   @0x11584c bl 0x319164 <__floatdidf>
 *   @0x115850 vmov.f64 d6, #5.000000e-01
 *   @0x115854 vldr d5, [pc, #52]
 *   @0x115858 vldr d7, [pc, #32]
 *   @0x11585c vmov d4, r0, r1
 *   @0x115860 vadd.f64 d6, d4, d6
 *   @0x115864 vdiv.f64 d6, d6, d5
 *   @0x115868 vadd.f64 d5, d6, d7
 *   @0x11586c vmov r2, r3, d5
 *   @0x115870 stm r4, {r2, r3}
 *   @0x115874 add sp, sp, #8
 *   @0x115878 pop {r4, r5, r6, pc}
 *   @0x11587c nop
 *   @0x115880 andeq r0, r0, r0
 *   @0x115884 sbcsmi pc, r8, r0, asr #16
 *   @0x115888 bl 0x826544 <b2_toiTime+0xcd0a0>
 *   @0x11588c svclo #0x1a36e2
 *   @0x115890 andeq r0, r0, r0
 *   @0x115894 rscsmi r1, r5, r0, lsl #16
 *
 * ══ §38/127 F_DateIncWeek(RValue&, CInstance*, CInstance*, int, RValue*)  0x115898  size 240  60 条（0x115898..0x115988）
 * @func 0x115898 0x11599c  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / YYGetInt32(RValue const*, int) / 0xb6814 / __floatdidf / 0x826634
 * 字段偏移 top8: 0xc×3 / 0x18×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115898 push {r4, r5, r6, lr}
 *   @0x11589c sub sp, sp, #8
 *   @0x1158a0 mov r1, #0
 *   @0x1158a4 mov r4, r0
 *   @0x1158a8 ldr r6, [sp, #0x18]
 *   @0x1158ac mov r3, r1
 *   @0x1158b0 str r1, [r0, #0xc]
 *   @0x1158b4 movt r3, #0xbff0
 *   @0x1158b8 stm r0, {r1, r3}
 *   @0x1158bc mov r0, r6
 *   @0x1158c0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1158c4 vldr d7, [pc, #164]
 *   @0x1158c8 vldr d5, [pc, #168]
 *   @0x1158cc vmov d6, r0, r1
 *   @0x1158d0 vsub.f64 d7, d6, d7
 *   @0x1158d4 vabs.f64 d4, d7
 *   @0x1158d8 vcmpe.f64 d4, d5
 *   @0x1158dc vmrs APSR_nzcv, fpscr
 *   @0x1158e0 vldrls d7, [pc, #152]
 *   @0x1158e4 vldrhi d6, [pc, #148]
 *   @0x1158e8 vmulls.f64 d4, d6, d7
 *   @0x1158ec vmulhi.f64 d5, d7, d6
 *   @0x1158f0 vmovls r0, r1, d4
 *   @0x1158f4 vmovhi r0, r1, d5
 *   @0x1158f8 bl 0x3194a0 <__fixdfdi>
 *   @0x1158fc mov r2, r0
 *   @0x115900 add r0, sp, #8
 *   @0x115904 mov r3, r1
 *   @0x115908 strd r2, r3, [r0, #-8]!
 *   @0x11590c mov r0, sp
 *   @0x115910 bl 0xb6820 <gmtime64@plt>
 *   @0x115914 subs r5, r0, #0
 *   @0x115918 beq 0x115968 <_Z13F_DateIncWeekR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x11591c mov r0, r6
 *   @0x115920 mov r1, #1
 *   @0x115924 ldr r6, [r5, #0xc]
 *   @0x115928 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11592c rsb r3, r0, r0, lsl #3
 *   @0x115930 mov r0, r5
 *   @0x115934 add r6, r6, r3
 *   @0x115938 str r6, [r5, #0xc]
 *   @0x11593c bl 0xb6814 <timegm64@plt>
 *   @0x115940 bl 0x319164 <__floatdidf>
 *   @0x115944 vmov.f64 d6, #5.000000e-01
 *   @0x115948 vldr d5, [pc, #48]
 *   @0x11594c vldr d7, [pc, #28]
 *   @0x115950 vmov d4, r0, r1
 *   @0x115954 vadd.f64 d6, d4, d6
 *   @0x115958 vdiv.f64 d6, d6, d5
 *   @0x11595c vadd.f64 d5, d6, d7
 *   @0x115960 vmov r2, r3, d5
 *   @0x115964 stm r4, {r2, r3}
 *   @0x115968 add sp, sp, #8
 *   @0x11596c pop {r4, r5, r6, pc}
 *   @0x115970 andeq r0, r0, r0
 *   @0x115974 sbcsmi pc, r8, r0, asr #16
 *   @0x115978 bl 0x826634 <b2_toiTime+0xcd190>
 *   @0x11597c svclo #0x1a36e2
 *   @0x115980 andeq r0, r0, r0
 *   @0x115984 rscsmi r1, r5, r0, lsl #16
 *
 * ══ §39/127 F_DateIncDay(RValue&, CInstance*, CInstance*, int, RValue*)  0x115988  size 240  60 条（0x115988..0x115a78）
 * @func 0x115988 0x115a8c  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / YYGetInt32(RValue const*, int) / 0xb6814 / __floatdidf / 0x826724
 * 字段偏移 top8: 0xc×3 / 0x18×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115988 push {r4, r5, r6, lr}
 *   @0x11598c sub sp, sp, #8
 *   @0x115990 mov r1, #0
 *   @0x115994 mov r4, r0
 *   @0x115998 ldr r6, [sp, #0x18]
 *   @0x11599c mov r3, r1
 *   @0x1159a0 str r1, [r0, #0xc]
 *   @0x1159a4 movt r3, #0xbff0
 *   @0x1159a8 stm r0, {r1, r3}
 *   @0x1159ac mov r0, r6
 *   @0x1159b0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1159b4 vldr d7, [pc, #164]
 *   @0x1159b8 vldr d5, [pc, #168]
 *   @0x1159bc vmov d6, r0, r1
 *   @0x1159c0 vsub.f64 d7, d6, d7
 *   @0x1159c4 vabs.f64 d4, d7
 *   @0x1159c8 vcmpe.f64 d4, d5
 *   @0x1159cc vmrs APSR_nzcv, fpscr
 *   @0x1159d0 vldrls d7, [pc, #152]
 *   @0x1159d4 vldrhi d6, [pc, #148]
 *   @0x1159d8 vmulls.f64 d4, d6, d7
 *   @0x1159dc vmulhi.f64 d5, d7, d6
 *   @0x1159e0 vmovls r0, r1, d4
 *   @0x1159e4 vmovhi r0, r1, d5
 *   @0x1159e8 bl 0x3194a0 <__fixdfdi>
 *   @0x1159ec mov r2, r0
 *   @0x1159f0 add r0, sp, #8
 *   @0x1159f4 mov r3, r1
 *   @0x1159f8 strd r2, r3, [r0, #-8]!
 *   @0x1159fc mov r0, sp
 *   @0x115a00 bl 0xb6820 <gmtime64@plt>
 *   @0x115a04 subs r5, r0, #0
 *   @0x115a08 beq 0x115a54 <_Z12F_DateIncDayR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x115a0c mov r0, r6
 *   @0x115a10 mov r1, #1
 *   @0x115a14 ldr r6, [r5, #0xc]
 *   @0x115a18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115a1c add r6, r6, r0
 *   @0x115a20 mov r0, r5
 *   @0x115a24 str r6, [r5, #0xc]
 *   @0x115a28 bl 0xb6814 <timegm64@plt>
 *   @0x115a2c bl 0x319164 <__floatdidf>
 *   @0x115a30 vmov.f64 d6, #5.000000e-01
 *   @0x115a34 vldr d5, [pc, #52]
 *   @0x115a38 vldr d7, [pc, #32]
 *   @0x115a3c vmov d4, r0, r1
 *   @0x115a40 vadd.f64 d6, d4, d6
 *   @0x115a44 vdiv.f64 d6, d6, d5
 *   @0x115a48 vadd.f64 d5, d6, d7
 *   @0x115a4c vmov r2, r3, d5
 *   @0x115a50 stm r4, {r2, r3}
 *   @0x115a54 add sp, sp, #8
 *   @0x115a58 pop {r4, r5, r6, pc}
 *   @0x115a5c nop
 *   @0x115a60 andeq r0, r0, r0
 *   @0x115a64 sbcsmi pc, r8, r0, asr #16
 *   @0x115a68 bl 0x826724 <b2_toiTime+0xcd280>
 *   @0x115a6c svclo #0x1a36e2
 *   @0x115a70 andeq r0, r0, r0
 *   @0x115a74 rscsmi r1, r5, r0, lsl #16
 *
 * ══ §40/127 F_DateIncHour(RValue&, CInstance*, CInstance*, int, RValue*)  0x115a78  size 240  60 条（0x115a78..0x115b68）
 * @func 0x115a78 0x115b7c  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / YYGetInt32(RValue const*, int) / 0xb6814 / __floatdidf / 0x826814
 * 字段偏移 top8: 0x8×2 / 0x18×1 / 0xc×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115a78 push {r4, r5, r6, lr}
 *   @0x115a7c sub sp, sp, #8
 *   @0x115a80 mov r1, #0
 *   @0x115a84 mov r4, r0
 *   @0x115a88 ldr r6, [sp, #0x18]
 *   @0x115a8c mov r3, r1
 *   @0x115a90 str r1, [r0, #0xc]
 *   @0x115a94 movt r3, #0xbff0
 *   @0x115a98 stm r0, {r1, r3}
 *   @0x115a9c mov r0, r6
 *   @0x115aa0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x115aa4 vldr d7, [pc, #164]
 *   @0x115aa8 vldr d5, [pc, #168]
 *   @0x115aac vmov d6, r0, r1
 *   @0x115ab0 vsub.f64 d7, d6, d7
 *   @0x115ab4 vabs.f64 d4, d7
 *   @0x115ab8 vcmpe.f64 d4, d5
 *   @0x115abc vmrs APSR_nzcv, fpscr
 *   @0x115ac0 vldrls d7, [pc, #152]
 *   @0x115ac4 vldrhi d6, [pc, #148]
 *   @0x115ac8 vmulls.f64 d4, d6, d7
 *   @0x115acc vmulhi.f64 d5, d7, d6
 *   @0x115ad0 vmovls r0, r1, d4
 *   @0x115ad4 vmovhi r0, r1, d5
 *   @0x115ad8 bl 0x3194a0 <__fixdfdi>
 *   @0x115adc mov r2, r0
 *   @0x115ae0 add r0, sp, #8
 *   @0x115ae4 mov r3, r1
 *   @0x115ae8 strd r2, r3, [r0, #-8]!
 *   @0x115aec mov r0, sp
 *   @0x115af0 bl 0xb6820 <gmtime64@plt>
 *   @0x115af4 subs r5, r0, #0
 *   @0x115af8 beq 0x115b44 <_Z13F_DateIncHourR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x115afc mov r0, r6
 *   @0x115b00 mov r1, #1
 *   @0x115b04 ldr r6, [r5, #0x8]
 *   @0x115b08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115b0c add r6, r6, r0
 *   @0x115b10 mov r0, r5
 *   @0x115b14 str r6, [r5, #0x8]
 *   @0x115b18 bl 0xb6814 <timegm64@plt>
 *   @0x115b1c bl 0x319164 <__floatdidf>
 *   @0x115b20 vmov.f64 d6, #5.000000e-01
 *   @0x115b24 vldr d5, [pc, #52]
 *   @0x115b28 vldr d7, [pc, #32]
 *   @0x115b2c vmov d4, r0, r1
 *   @0x115b30 vadd.f64 d6, d4, d6
 *   @0x115b34 vdiv.f64 d6, d6, d5
 *   @0x115b38 vadd.f64 d5, d6, d7
 *   @0x115b3c vmov r2, r3, d5
 *   @0x115b40 stm r4, {r2, r3}
 *   @0x115b44 add sp, sp, #8
 *   @0x115b48 pop {r4, r5, r6, pc}
 *   @0x115b4c nop
 *   @0x115b50 andeq r0, r0, r0
 *   @0x115b54 sbcsmi pc, r8, r0, asr #16
 *   @0x115b58 bl 0x826814 <b2_toiTime+0xcd370>
 *   @0x115b5c svclo #0x1a36e2
 *   @0x115b60 andeq r0, r0, r0
 *   @0x115b64 rscsmi r1, r5, r0, lsl #16
 *
 * ══ §41/127 F_DateIncMinute(RValue&, CInstance*, CInstance*, int, RValue*)  0x115b68  size 240  60 条（0x115b68..0x115c58）
 * @func 0x115b68 0x115c6c  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / YYGetInt32(RValue const*, int) / 0xb6814 / __floatdidf / 0x826904
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0xc×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115b68 push {r4, r5, r6, lr}
 *   @0x115b6c sub sp, sp, #8
 *   @0x115b70 mov r1, #0
 *   @0x115b74 mov r4, r0
 *   @0x115b78 ldr r6, [sp, #0x18]
 *   @0x115b7c mov r3, r1
 *   @0x115b80 str r1, [r0, #0xc]
 *   @0x115b84 movt r3, #0xbff0
 *   @0x115b88 stm r0, {r1, r3}
 *   @0x115b8c mov r0, r6
 *   @0x115b90 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x115b94 vldr d7, [pc, #164]
 *   @0x115b98 vldr d5, [pc, #168]
 *   @0x115b9c vmov d6, r0, r1
 *   @0x115ba0 vsub.f64 d7, d6, d7
 *   @0x115ba4 vabs.f64 d4, d7
 *   @0x115ba8 vcmpe.f64 d4, d5
 *   @0x115bac vmrs APSR_nzcv, fpscr
 *   @0x115bb0 vldrls d7, [pc, #152]
 *   @0x115bb4 vldrhi d6, [pc, #148]
 *   @0x115bb8 vmulls.f64 d4, d6, d7
 *   @0x115bbc vmulhi.f64 d5, d7, d6
 *   @0x115bc0 vmovls r0, r1, d4
 *   @0x115bc4 vmovhi r0, r1, d5
 *   @0x115bc8 bl 0x3194a0 <__fixdfdi>
 *   @0x115bcc mov r2, r0
 *   @0x115bd0 add r0, sp, #8
 *   @0x115bd4 mov r3, r1
 *   @0x115bd8 strd r2, r3, [r0, #-8]!
 *   @0x115bdc mov r0, sp
 *   @0x115be0 bl 0xb6820 <gmtime64@plt>
 *   @0x115be4 subs r5, r0, #0
 *   @0x115be8 beq 0x115c34 <_Z15F_DateIncMinuteR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x115bec mov r0, r6
 *   @0x115bf0 mov r1, #1
 *   @0x115bf4 ldr r6, [r5, #0x4]
 *   @0x115bf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115bfc add r6, r6, r0
 *   @0x115c00 mov r0, r5
 *   @0x115c04 str r6, [r5, #0x4]
 *   @0x115c08 bl 0xb6814 <timegm64@plt>
 *   @0x115c0c bl 0x319164 <__floatdidf>
 *   @0x115c10 vmov.f64 d6, #5.000000e-01
 *   @0x115c14 vldr d5, [pc, #52]
 *   @0x115c18 vldr d7, [pc, #32]
 *   @0x115c1c vmov d4, r0, r1
 *   @0x115c20 vadd.f64 d6, d4, d6
 *   @0x115c24 vdiv.f64 d6, d6, d5
 *   @0x115c28 vadd.f64 d5, d6, d7
 *   @0x115c2c vmov r2, r3, d5
 *   @0x115c30 stm r4, {r2, r3}
 *   @0x115c34 add sp, sp, #8
 *   @0x115c38 pop {r4, r5, r6, pc}
 *   @0x115c3c nop
 *   @0x115c40 andeq r0, r0, r0
 *   @0x115c44 sbcsmi pc, r8, r0, asr #16
 *   @0x115c48 bl 0x826904 <b2_toiTime+0xcd460>
 *   @0x115c4c svclo #0x1a36e2
 *   @0x115c50 andeq r0, r0, r0
 *   @0x115c54 rscsmi r1, r5, r0, lsl #16
 *
 * ══ §42/127 F_DateIncSecond(RValue&, CInstance*, CInstance*, int, RValue*)  0x115c58  size 240  60 条（0x115c58..0x115d48）
 * @func 0x115c58 0x115d48  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / YYGetInt32(RValue const*, int) / 0xb6814 / __floatdidf / 0x8269f4
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115c58 push {r4, r5, r6, lr}
 *   @0x115c5c sub sp, sp, #8
 *   @0x115c60 mov r1, #0
 *   @0x115c64 mov r4, r0
 *   @0x115c68 ldr r6, [sp, #0x18]
 *   @0x115c6c mov r3, r1
 *   @0x115c70 str r1, [r0, #0xc]
 *   @0x115c74 movt r3, #0xbff0
 *   @0x115c78 stm r0, {r1, r3}
 *   @0x115c7c mov r0, r6
 *   @0x115c80 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x115c84 vldr d7, [pc, #164]
 *   @0x115c88 vldr d5, [pc, #168]
 *   @0x115c8c vmov d6, r0, r1
 *   @0x115c90 vsub.f64 d7, d6, d7
 *   @0x115c94 vabs.f64 d4, d7
 *   @0x115c98 vcmpe.f64 d4, d5
 *   @0x115c9c vmrs APSR_nzcv, fpscr
 *   @0x115ca0 vldrls d7, [pc, #152]
 *   @0x115ca4 vldrhi d6, [pc, #148]
 *   @0x115ca8 vmulls.f64 d4, d6, d7
 *   @0x115cac vmulhi.f64 d5, d7, d6
 *   @0x115cb0 vmovls r0, r1, d4
 *   @0x115cb4 vmovhi r0, r1, d5
 *   @0x115cb8 bl 0x3194a0 <__fixdfdi>
 *   @0x115cbc mov r2, r0
 *   @0x115cc0 add r0, sp, #8
 *   @0x115cc4 mov r3, r1
 *   @0x115cc8 strd r2, r3, [r0, #-8]!
 *   @0x115ccc mov r0, sp
 *   @0x115cd0 bl 0xb6820 <gmtime64@plt>
 *   @0x115cd4 subs r5, r0, #0
 *   @0x115cd8 beq 0x115d24 <_Z15F_DateIncSecondR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x115cdc mov r0, r6
 *   @0x115ce0 mov r1, #1
 *   @0x115ce4 ldr r6, [r5]
 *   @0x115ce8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115cec add r6, r6, r0
 *   @0x115cf0 mov r0, r5
 *   @0x115cf4 str r6, [r5]
 *   @0x115cf8 bl 0xb6814 <timegm64@plt>
 *   @0x115cfc bl 0x319164 <__floatdidf>
 *   @0x115d00 vmov.f64 d6, #5.000000e-01
 *   @0x115d04 vldr d5, [pc, #52]
 *   @0x115d08 vldr d7, [pc, #32]
 *   @0x115d0c vmov d4, r0, r1
 *   @0x115d10 vadd.f64 d6, d4, d6
 *   @0x115d14 vdiv.f64 d6, d6, d5
 *   @0x115d18 vadd.f64 d5, d6, d7
 *   @0x115d1c vmov r2, r3, d5
 *   @0x115d20 stm r4, {r2, r3}
 *   @0x115d24 add sp, sp, #8
 *   @0x115d28 pop {r4, r5, r6, pc}
 *   @0x115d2c nop
 *   @0x115d30 andeq r0, r0, r0
 *   @0x115d34 sbcsmi pc, r8, r0, asr #16
 *   @0x115d38 bl 0x8269f4 <b2_toiTime+0xcd550>
 *   @0x115d3c svclo #0x1a36e2
 *   @0x115d40 andeq r0, r0, r0
 *   @0x115d44 rscsmi r1, r5, r0, lsl #16
 *
 * ══ §43/127 F_ObjectIsAncestor(RValue&, CInstance*, CInstance*, int, RValue*)  0x12af98  size 240  60 条（0x12af98..0x12b088）
 * @func 0x12af98 0x12b088  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x4×5 / 0xc×5 / 0x3×2 / 0x8×2 / 0x18×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12af98 push {r3, r4, r5, r6, r7, lr}
 *   @0x12af9c mov r1, #0
 *   @0x12afa0 ldr r7, [sp, #0x18]
 *   @0x12afa4 mov r5, r0
 *   @0x12afa8 ldr r6, [pc, #0xd4]
 *   @0x12afac mov r0, r7
 *   @0x12afb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12afb4 ldr r6, [pc, r6]
 *   @0x12afb8 ldr r3, [r6]
 *   @0x12afbc ldr r2, [r3, #0x4]
 *   @0x12afc0 ldr r3, [r3]
 *   @0x12afc4 and r2, r0, r2
 *   @0x12afc8 ldr r3, [r3, r2, lsl #3]
 *   @0x12afcc cmp r3, #0
 *   @0x12afd0 bne 0x12afe4 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x12afd4 b 0x12b058 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x12afd8 ldr r3, [r3, #0x4]
 *   @0x12afdc cmp r3, #0
 *   @0x12afe0 beq 0x12b058 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x12afe4 ldr r2, [r3, #0x8]
 *   @0x12afe8 cmp r0, r2
 *   @0x12afec bne 0x12afd8 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12aff0 ldr r4, [r3, #0xc]
 *   @0x12aff4 cmp r4, #0
 *   @0x12aff8 beq 0x12b058 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x12affc mov r0, r7
 *   @0x12b000 mov r1, #1
 *   @0x12b004 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b008 ldr r12, [r6]
 *   @0x12b00c ldr r1, [r4, #0xc]
 *   @0x12b010 cmp r0, r1
 *   @0x12b014 beq 0x12b070 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x12b018 ldr r2, [r12, #0x4]
 *   @0x12b01c ldr r3, [r12]
 *   @0x12b020 and r2, r1, r2
 *   @0x12b024 ldr r3, [r3, r2, lsl #3]
 *   @0x12b028 cmp r3, #0
 *   @0x12b02c bne 0x12b040 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x12b030 b 0x12b058 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x12b034 ldr r3, [r3, #0x4]
 *   @0x12b038 cmp r3, #0
 *   @0x12b03c beq 0x12b058 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x12b040 ldr r2, [r3, #0x8]
 *   @0x12b044 cmp r1, r2
 *   @0x12b048 bne 0x12b034 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x12b04c ldr r4, [r3, #0xc]
 *   @0x12b050 cmp r4, #0
 *   @0x12b054 bne 0x12b00c <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12b058 mov r3, #0
 *   @0x12b05c str r3, [r5, #0xc]
 *   @0x12b060 mov r2, r3
 *   @0x12b064 str r3, [r5]
 *   @0x12b068 str r2, [r5, #0x4]
 *   @0x12b06c pop {r3, r4, r5, r6, r7, pc}
 *   @0x12b070 mov r3, #0
 *   @0x12b074 str r3, [r5, #0xc]
 *   @0x12b078 mov r2, r3
 *   @0x12b07c movt r2, #0x3ff0
 *   @0x12b080 b 0x12b064 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x12b084 eoreq r2, r12, r8, lsl #25
 *
 * ══ §44/127 F_ActionPartTypeColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x13fba8  size 240  60 条（0x13fba8..0x13fc98）
 * @func 0x13fba8 0x13fc98  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetFloat(RValue const*, int)×2 / F_ActionPartTypeColor(RValue&, CInstance*, CInstance*, int, RValue*)+0xd4 / F_ActionPartTypeColor(RValue&, CInstance*, CInstance*, int, RValue*)+0xc4 / ParticleType_Color2(int, unsigned int, unsigned int) / ParticleType_Color_Mix(int, unsigned int, unsigned int) / ParticleType_Create() / ParticleSystem_Create(int, bool)
 * 字段偏移 top8: 0x2×2 / 0x28×1 / 0xd4×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13fba8 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13fbac mov r1, #0
 *   @0x13fbb0 ldr r4, [sp, #0x28]
 *   @0x13fbb4 ldr r5, [pc, #0xd4]
 *   @0x13fbb8 mov r0, r4
 *   @0x13fbbc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fbc0 mov r1, #1
 *   @0x13fbc4 mov r6, r0
 *   @0x13fbc8 mov r0, r4
 *   @0x13fbcc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fbd0 mov r1, #2
 *   @0x13fbd4 mov r10, r0
 *   @0x13fbd8 mov r0, r4
 *   @0x13fbdc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fbe0 mov r1, #3
 *   @0x13fbe4 mov r9, r0
 *   @0x13fbe8 mov r0, r4
 *   @0x13fbec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fbf0 mov r1, #4
 *   @0x13fbf4 mov r8, r0
 *   @0x13fbf8 mov r0, r4
 *   @0x13fbfc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13fc00 mov r1, #5
 *   @0x13fc04 mov r7, r0
 *   @0x13fc08 mov r0, r4
 *   @0x13fc0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13fc10 ldr r5, [pc, r5]
 *   @0x13fc14 ldr r3, [r5]
 *   @0x13fc18 cmp r3, #0
 *   @0x13fc1c mov r11, r0
 *   @0x13fc20 blt 0x13fc7c <_Z21F_ActionPartTypeColorR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x13fc24 ldr r5, [pc, #0x68]
 *   @0x13fc28 ldr r5, [pc, r5]
 *   @0x13fc2c ldr r4, [r5, r6, lsl #2]
 *   @0x13fc30 cmp r4, #0
 *   @0x13fc34 blt 0x13fc6c <_Z21F_ActionPartTypeColorR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x13fc38 cmp r10, #0
 *   @0x13fc3c mov r1, r9
 *   @0x13fc40 mov r2, r8
 *   @0x13fc44 mov r0, r4
 *   @0x13fc48 beq 0x13fc64 <_Z21F_ActionPartTypeColorR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x13fc4c bl 0x1a35d8 <_Z19ParticleType_Color2ijj>
 *   @0x13fc50 mov r0, r4
 *   @0x13fc54 mov r1, r7
 *   @0x13fc58 mov r2, r11
 *   @0x13fc5c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13fc60 b 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x13fc64 bl 0x1a34f4 <_Z22ParticleType_Color_Mixijj>
 *   @0x13fc68 b 0x13fc50 <_Z21F_ActionPartTypeColorR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x13fc6c bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x13fc70 mov r4, r0
 *   @0x13fc74 str r0, [r5, r6, lsl #2]
 *   @0x13fc78 b 0x13fc38 <_Z21F_ActionPartTypeColorR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x13fc7c mvn r0, #0
 *   @0x13fc80 mov r1, #1
 *   @0x13fc84 bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x13fc88 str r0, [r5]
 *   @0x13fc8c b 0x13fc24 <_Z21F_ActionPartTypeColorR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x13fc90 eoreq pc, r10, r12, asr #15
 *   @0x13fc94 .word 0x002af7b8
 *
 * ══ §45/127 GR_3DM_Create()  0x1650c0  size 240  60 条（0x1650c0..0x1651b0）
 * @func 0x1650c0 0x1651b0  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1650c4→0x4859b4, 0x1650d4→0x4859b8
 * 调用序列: GR_3DM_Create()+0x5c / operator new(unsigned int) / C3D_Model::C3D_Model() / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×3 / 0xd8×2 / 0xcc×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1650c0 ldr r3, [pc, #0xd8]
 *   @0x1650c4 ldr r2, [pc, #0xd8]
 *   @0x1650c8 add r3, pc, r3
 *   @0x1650cc push {r4, r5, r6, r7, r8, lr}
 *   @0x1650d0 ldr r8, [r3, r2]
 *   @0x1650d4 ldr r2, [pc, #0xcc]
 *   @0x1650d8 ldr r5, [r8]
 *   @0x1650dc ldr r7, [r3, r2]
 *   @0x1650e0 cmp r5, #0
 *   @0x1650e4 ble 0x16511c <_Z13GR_3DM_Createv+0x5c>
 *   @0x1650e8 ldr r3, [r7, #0x4]
 *   @0x1650ec ldr r6, [r3]
 *   @0x1650f0 cmp r6, #0
 *   @0x1650f4 beq 0x165198 <_Z13GR_3DM_Createv+0xd8>
 *   @0x1650f8 mov r4, #0
 *   @0x1650fc b 0x16510c <_Z13GR_3DM_Createv+0x4c>
 *   @0x165100 ldr r2, [r3, #0x4]!
 *   @0x165104 cmp r2, #0
 *   @0x165108 beq 0x16513c <_Z13GR_3DM_Createv+0x7c>
 *   @0x16510c add r4, r4, #1
 *   @0x165110 cmp r4, r5
 *   @0x165114 lsl r6, r4, #2
 *   @0x165118 bne 0x165100 <_Z13GR_3DM_Createv+0x40>
 *   @0x16511c ldr r3, [r7]
 *   @0x165120 cmp r5, r3
 *   @0x165124 movlt r3, r5
 *   @0x165128 bge 0x16515c <_Z13GR_3DM_Createv+0x9c>
 *   @0x16512c lsl r6, r5, #2
 *   @0x165130 mov r4, r5
 *   @0x165134 add r3, r3, #1
 *   @0x165138 str r3, [r8]
 *   @0x16513c mov r0, #28
 *   @0x165140 bl 0x27c524 <_Znwj>
 *   @0x165144 mov r5, r0
 *   @0x165148 bl 0x163d84 <_ZN9C3D_ModelC2Ev>
 *   @0x16514c ldr r3, [r7, #0x4]
 *   @0x165150 mov r0, r4
 *   @0x165154 str r5, [r3, r6]
 *   @0x165158 pop {r4, r5, r6, r7, r8, pc}
 *   @0x16515c add r1, r5, #16
 *   @0x165160 ldr r2, [pc, #0x44]
 *   @0x165164 movw r3, #0x283
 *   @0x165168 add r0, r7, #4
 *   @0x16516c add r2, pc, r2
 *   @0x165170 lsl r1, r1, #2
 *   @0x165174 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x165178 ldr r3, [r8]
 *   @0x16517c lsl r6, r5, #2
 *   @0x165180 mov r4, r5
 *   @0x165184 add r2, r3, #16
 *   @0x165188 add r3, r3, #1
 *   @0x16518c str r2, [r7]
 *   @0x165190 str r3, [r8]
 *   @0x165194 b 0x16513c <_Z13GR_3DM_Createv+0x7c>
 *   @0x165198 mov r4, r6
 *   @0x16519c b 0x16513c <_Z13GR_3DM_Createv+0x7c>
 *   @0x1651a0 eoreq r12, r8, r8, lsl #23
 *   @0x1651a4 .word 0xffffe4a0
 *   @0x1651a8 .word 0xffffe4a4
 *   @0x1651ac andseq r5, lr, r8, lsr #7
 *
 * ══ §46/127 GR_Text_Height(char const*, int, int)  0x172d08  size 240  60 条（0x172d08..0x172df8）
 * @func 0x172d08 0x172df8  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::TextHeight(unsigned short*)×2 / MemoryManager::Free(void const*)×2 / SetFont() / Split_TextBlock(char const*, int, TStringList*) / GR_Text_Height(char const*, int, int)+0xc0 / GR_Text_Height(char const*, int, int)+0x78
 * 字段偏移 top8: 0x8×4 / 0xc×2 / 0x84×2 / 0x20×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x172d08 push {r4, r5, r6, lr}
 *   @0x172d0c sub sp, sp, #16
 *   @0x172d10 mov r5, r2
 *   @0x172d14 mov r6, r0
 *   @0x172d18 mov r3, #0
 *   @0x172d1c mov r4, r1
 *   @0x172d20 str r3, [sp, #0x4]
 *   @0x172d24 str r3, [sp]
 *   @0x172d28 str r3, [sp, #0xc]
 *   @0x172d2c str r3, [sp, #0x8]
 *   @0x172d30 bl 0x1724e4 <_Z7SetFontv>
 *   @0x172d34 mov r0, r6
 *   @0x172d38 mov r1, r5
 *   @0x172d3c mov r2, sp
 *   @0x172d40 bl 0x172560 <_Z15Split_TextBlockPKciP11TStringList>
 *   @0x172d44 cmp r4, #0
 *   @0x172d48 blt 0x172dc8 <_Z14GR_Text_HeightPKcii+0xc0>
 *   @0x172d4c ldr r3, [sp, #0x8]
 *   @0x172d50 cmp r3, #0
 *   @0x172d54 movle r5, #0
 *   @0x172d58 ble 0x172d80 <_Z14GR_Text_HeightPKcii+0x78>
 *   @0x172d5c ldr r3, [pc, #0x84]
 *   @0x172d60 ldr r1, [pc, #0x84]
 *   @0x172d64 ldr r3, [pc, r3]
 *   @0x172d68 add r1, pc, r1
 *   @0x172d6c ldr r0, [r3]
 *   @0x172d70 bl 0xf93a4 <_ZN7CFontGM10TextHeightEPt>
 *   @0x172d74 ldr r5, [sp, #0x8]
 *   @0x172d78 sub r5, r5, #1
 *   @0x172d7c mla r5, r4, r5, r0
 *   @0x172d80 ldr r0, [sp]
 *   @0x172d84 cmp r0, #0
 *   @0x172d88 beq 0x172da0 <_Z14GR_Text_HeightPKcii+0x98>
 *   @0x172d8c ldr r4, [r0]
 *   @0x172d90 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x172d94 cmp r4, #0
 *   @0x172d98 mov r0, r4
 *   @0x172d9c bne 0x172d8c <_Z14GR_Text_HeightPKcii+0x84>
 *   @0x172da0 ldr r0, [sp, #0xc]
 *   @0x172da4 mov r3, #0
 *   @0x172da8 str r3, [sp, #0x8]
 *   @0x172dac cmp r0, r3
 *   @0x172db0 str r3, [sp]
 *   @0x172db4 beq 0x172dbc <_Z14GR_Text_HeightPKcii+0xb4>
 *   @0x172db8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x172dbc mov r0, r5
 *   @0x172dc0 add sp, sp, #16
 *   @0x172dc4 pop {r4, r5, r6, pc}
 *   @0x172dc8 ldr r3, [pc, #0x20]
 *   @0x172dcc ldr r1, [pc, #0x20]
 *   @0x172dd0 ldr r3, [pc, r3]
 *   @0x172dd4 add r1, pc, r1
 *   @0x172dd8 ldr r0, [r3]
 *   @0x172ddc bl 0xf93a4 <_ZN7CFontGM10TextHeightEPt>
 *   @0x172de0 mov r4, r0
 *   @0x172de4 b 0x172d4c <_Z14GR_Text_HeightPKcii+0x44>
 *   @0x172de8 eoreq sp, r7, r0, asr #10
 *   @0x172dec andseq r8, sp, r0, lsr #15
 *   @0x172df0 .word 0x0027d4d4
 *   @0x172df4 andseq r8, sp, r4, lsr r7
 *
 * ══ §47/127 CPath::ComputeLength()  0x1a5f78  size 240  60 条（0x1a5f78..0x1a6068）
 * @func 0x1a5f78 0x1a6068  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::ComputeLength()+0xcc / 0xb6700
 * 字段偏移 top8: 0xc×3 / 0x20×2 / 0x28×1 / 0x24×1
 * VFP 指令 30 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a5f78 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a5f7c vpush {d8}
 *   @0x1a5f80 mov r4, r0
 *   @0x1a5f84 ldr r0, [r0, #0x20]
 *   @0x1a5f88 mov r2, #0
 *   @0x1a5f8c str r2, [r4, #0x28]
 *   @0x1a5f90 cmp r0, #0
 *   @0x1a5f94 str r2, [r4, #0x24]
 *   @0x1a5f98 ble 0x1a6044 <_ZN5CPath13ComputeLengthEv+0xcc>
 *   @0x1a5f9c ldr r3, [r4, #0xc]
 *   @0x1a5fa0 cmp r0, #1
 *   @0x1a5fa4 str r2, [r3, #0xc]
 *   @0x1a5fa8 beq 0x1a6044 <_ZN5CPath13ComputeLengthEv+0xcc>
 *   @0x1a5fac vmov.f32 s17, #5.000000e-01
 *   @0x1a5fb0 mov r6, #0
 *   @0x1a5fb4 mov r5, #1
 *   @0x1a5fb8 vldr s16, [pc, #164]
 *   @0x1a5fbc lsl r7, r5, #4
 *   @0x1a5fc0 add r2, r3, r6
 *   @0x1a5fc4 add r1, r3, r7
 *   @0x1a5fc8 vldr s15, [r2, #4]
 *   @0x1a5fcc vldr s14, [r1, #4]
 *   @0x1a5fd0 vldr s13, [r1]
 *   @0x1a5fd4 add r5, r5, #1
 *   @0x1a5fd8 vsub.f32 s14, s14, s15
 *   @0x1a5fdc vldr s15, [r2]
 *   @0x1a5fe0 vmul.f32 s14, s14, s14
 *   @0x1a5fe4 vsub.f32 s15, s13, s15
 *   @0x1a5fe8 vmla.f32 s14, s15, s15
 *   @0x1a5fec vsqrt.f32 s15, s14
 *   @0x1a5ff0 vcmp.f32 s15, s15
 *   @0x1a5ff4 vmrs APSR_nzcv, fpscr
 *   @0x1a5ff8 bne 0x1a604c <_ZN5CPath13ComputeLengthEv+0xd4>
 *   @0x1a5ffc add r7, r3, r7
 *   @0x1a6000 add r2, r3, r6
 *   @0x1a6004 vldr s11, [r7, #8]
 *   @0x1a6008 vldr s14, [r2, #8]
 *   @0x1a600c vadd.f32 s14, s11, s14
 *   @0x1a6010 vldr s13, [r4, #40]
 *   @0x1a6014 vldr s12, [r4, #36]
 *   @0x1a6018 cmp r0, r5
 *   @0x1a601c add r6, r6, #16
 *   @0x1a6020 vmul.f32 s14, s14, s17
 *   @0x1a6024 vdiv.f32 s14, s14, s16
 *   @0x1a6028 vdiv.f32 s14, s15, s14
 *   @0x1a602c vadd.f32 s15, s15, s12
 *   @0x1a6030 vadd.f32 s14, s13, s14
 *   @0x1a6034 vstr s15, [r4, #36]
 *   @0x1a6038 vstr s15, [r7, #12]
 *   @0x1a603c vstr s14, [r4, #40]
 *   @0x1a6040 bgt 0x1a5fbc <_ZN5CPath13ComputeLengthEv+0x44>
 *   @0x1a6044 vpop {d8}
 *   @0x1a6048 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a604c vmov r0, s14
 *   @0x1a6050 bl 0xb6700 <sqrtf@plt>
 *   @0x1a6054 ldr r3, [r4, #0xc]
 *   @0x1a6058 vmov s15, r0
 *   @0x1a605c ldr r0, [r4, #0x20]
 *   @0x1a6060 b 0x1a5ffc <_ZN5CPath13ComputeLengthEv+0x84>
 *   @0x1a6064 sbcmi r0, r8, #0
 *
 * ══ §48/127 CPath::InsertPoint(int, float, float, float)  0x1a71d0  size 240  60 条（0x1a71d0..0x1a72c0）
 * @func 0x1a71d0 0x1a72c0  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::InsertPoint(int, float, float, float)+0xb4 / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×5 / 0x10×3 / 0x8×2 / 0x24×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a71d0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a71d4 vpush {d8}
 *   @0x1a71d8 subs r9, r1, #0
 *   @0x1a71dc vldr s16, [sp, #48]
 *   @0x1a71e0 mov r8, r0
 *   @0x1a71e4 mov r10, r2
 *   @0x1a71e8 mov r11, r3
 *   @0x1a71ec blt 0x1a7284 <_ZN5CPath11InsertPointEifff+0xb4>
 *   @0x1a71f0 ldr r3, [r0, #0x10]
 *   @0x1a71f4 cmp r9, r3
 *   @0x1a71f8 bgt 0x1a7284 <_ZN5CPath11InsertPointEifff+0xb4>
 *   @0x1a71fc ldr r2, [r0]
 *   @0x1a7200 add r6, r3, #1
 *   @0x1a7204 str r6, [r0, #0x10]
 *   @0x1a7208 cmp r6, r2
 *   @0x1a720c bgt 0x1a728c <_ZN5CPath11InsertPointEifff+0xbc>
 *   @0x1a7210 sub r6, r6, #1
 *   @0x1a7214 cmp r9, r6
 *   @0x1a7218 addlt r12, r6, r6, lsl #1
 *   @0x1a721c lsllt r12, r12, #2
 *   @0x1a7220 bge 0x1a725c <_ZN5CPath11InsertPointEifff+0x8c>
 *   @0x1a7224 ldr r4, [r8, #0x4]
 *   @0x1a7228 sub r3, r12, #12
 *   @0x1a722c sub r6, r6, #1
 *   @0x1a7230 add r5, r4, r3
 *   @0x1a7234 add r7, r4, r12
 *   @0x1a7238 cmp r6, r9
 *   @0x1a723c ldr r0, [r5]
 *   @0x1a7240 ldr r1, [r5, #0x4]
 *   @0x1a7244 ldr r2, [r5, #0x8]
 *   @0x1a7248 str r0, [r4, r12]
 *   @0x1a724c mov r12, r3
 *   @0x1a7250 str r1, [r7, #0x4]
 *   @0x1a7254 str r2, [r7, #0x8]
 *   @0x1a7258 bne 0x1a7224 <_ZN5CPath11InsertPointEifff+0x54>
 *   @0x1a725c ldr r3, [r8, #0x4]
 *   @0x1a7260 add r9, r9, r9, lsl #1
 *   @0x1a7264 mov r0, r8
 *   @0x1a7268 add r9, r3, r9, lsl #2
 *   @0x1a726c vstr s16, [r9, #8]
 *   @0x1a7270 vpop {d8}
 *   @0x1a7274 str r10, [r9]
 *   @0x1a7278 str r11, [r9, #0x4]
 *   @0x1a727c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a7280 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *   @0x1a7284 vpop {d8}
 *   @0x1a7288 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a728c add r1, r3, #6
 *   @0x1a7290 ldr r2, [pc, #0x24]
 *   @0x1a7294 movw r3, #0x201
 *   @0x1a7298 add r0, r0, #4
 *   @0x1a729c add r1, r1, r1, lsl #1
 *   @0x1a72a0 add r2, pc, r2
 *   @0x1a72a4 lsl r1, r1, #2
 *   @0x1a72a8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a72ac ldr r6, [r8, #0x10]
 *   @0x1a72b0 add r3, r6, #5
 *   @0x1a72b4 str r3, [r8]
 *   @0x1a72b8 b 0x1a7210 <_ZN5CPath11InsertPointEifff+0x40>
 *   @0x1a72bc andseq r5, r10, r8, lsr lr
 *
 * ══ §49/127 F_LayerTilemapGetID(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c06f4  size 240  60 条（0x1c06f4..0x1c07e4）
 * @func 0x1c06f4 0x1c07e4  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::GetElementFromName(CLayer*, char const*) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x20×2 / 0x18×1 / 0xb0×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c06f4 cmp r3, #1
 *   @0x1c06f8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1c06fc mov r3, #0
 *   @0x1c0700 mov r5, r3
 *   @0x1c0704 mov r4, r0
 *   @0x1c0708 movt r3, #0xbff0
 *   @0x1c070c str r5, [r0, #0xc]
 *   @0x1c0710 str r3, [r0, #0x4]
 *   @0x1c0714 str r5, [r0]
 *   @0x1c0718 ldr r6, [sp, #0x18]
 *   @0x1c071c beq 0x1c0734 <_Z19F_LayerTilemapGetIDR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1c0720 ldr r0, [pc, #0xb0]
 *   @0x1c0724 mov r1, r5
 *   @0x1c0728 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1c072c add r0, pc, r0
 *   @0x1c0730 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c0734 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c0738 ldr r3, [r6, #0xc]
 *   @0x1c073c mov r1, r5
 *   @0x1c0740 bic r3, r3, #-16777216
 *   @0x1c0744 cmp r3, #1
 *   @0x1c0748 mov r7, r0
 *   @0x1c074c mov r0, r6
 *   @0x1c0750 beq 0x1c07a0 <_Z19F_LayerTilemapGetIDR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x1c0754 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0758 mov r1, r0
 *   @0x1c075c mov r0, r7
 *   @0x1c0760 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c0764 cmp r0, #0
 *   @0x1c0768 beq 0x1c07b4 <_Z19F_LayerTilemapGetIDR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1c076c ldr r1, [r0, #0x1c]
 *   @0x1c0770 bl 0x1c048c <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc>
 *   @0x1c0774 cmp r0, #0
 *   @0x1c0778 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1c077c ldr r3, [r0]
 *   @0x1c0780 cmp r3, #5
 *   @0x1c0784 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1c0788 ldr r2, [r0, #0x4]
 *   @0x1c078c vmov s15, r2
 *   @0x1c0790 vcvt.f64.s32 d7, s15
 *   @0x1c0794 vmov r2, r3, d7
 *   @0x1c0798 stm r4, {r2, r3}
 *   @0x1c079c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c07a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c07a4 mov r1, r0
 *   @0x1c07a8 mov r0, r7
 *   @0x1c07ac bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c07b0 b 0x1c0764 <_Z19F_LayerTilemapGetIDR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1c07b4 ldr r3, [pc, #0x20]
 *   @0x1c07b8 ldr r1, [pc, #0x20]
 *   @0x1c07bc ldr r3, [pc, r3]
 *   @0x1c07c0 add r1, pc, r1
 *   @0x1c07c4 ldr r0, [r3]
 *   @0x1c07c8 ldr r3, [r0]
 *   @0x1c07cc ldr r3, [r3, #0xc]
 *   @0x1c07d0 blx r3
 *   @0x1c07d4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c07d8 andseq pc, r8, r4, asr #3
 *   @0x1c07dc eoreq r12, r2, r8, asr pc
 *   @0x1c07e0 andseq pc, r8, r4, ror #2
 *
 * ══ §50/127 AddToDsMap(int, char*, double)  0x20bf40  size 240  60 条（0x20bf40..0x20c030）
 * @func 0x20bf40 0x20c044  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×2 / GetDsMap(int) / YYSetString(RValue*, char const*) / CDS_Map::Add(RValue*, RValue*)
 * 字段偏移 top8: 0xc×3 / 0x1c×3 / 0x8×2 / 0x4×1 / 0x10×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20bf40 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x20bf44 subs r6, r1, #0
 *   @0x20bf48 sub sp, sp, #36
 *   @0x20bf4c mov r4, r2
 *   @0x20bf50 mov r5, r3
 *   @0x20bf54 beq 0x20c004 <_Z10AddToDsMapiPcd+0xc4>
 *   @0x20bf58 bl 0x2052d4 <_Z8GetDsMapi>
 *   @0x20bf5c subs r9, r0, #0
 *   @0x20bf60 beq 0x20c004 <_Z10AddToDsMapiPcd+0xc4>
 *   @0x20bf64 add r8, sp, #16
 *   @0x20bf68 mov r1, r6
 *   @0x20bf6c mov r0, sp
 *   @0x20bf70 mov r6, #0
 *   @0x20bf74 mov r3, #1
 *   @0x20bf78 str r6, [sp]
 *   @0x20bf7c str r3, [sp, #0xc]
 *   @0x20bf80 str r6, [sp, #0x4]
 *   @0x20bf84 str r6, [sp, #0x8]
 *   @0x20bf88 str r6, [sp, #0x10]
 *   @0x20bf8c str r6, [sp, #0x14]
 *   @0x20bf90 str r6, [sp, #0x18]
 *   @0x20bf94 str r6, [sp, #0x1c]
 *   @0x20bf98 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x20bf9c mov r0, r9
 *   @0x20bfa0 mov r1, sp
 *   @0x20bfa4 mov r2, r8
 *   @0x20bfa8 str r6, [sp, #0x1c]
 *   @0x20bfac strd r4, r5, [sp, #16]
 *   @0x20bfb0 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x20bfb4 ldr r3, [sp, #0xc]
 *   @0x20bfb8 sub r3, r3, #1
 *   @0x20bfbc bic r3, r3, #-16777216
 *   @0x20bfc0 bic r3, r3, #3
 *   @0x20bfc4 cmp r3, r6
 *   @0x20bfc8 beq 0x20c024 <_Z10AddToDsMapiPcd+0xe4>
 *   @0x20bfcc ldr r1, [sp, #0x1c]
 *   @0x20bfd0 mov r3, #0
 *   @0x20bfd4 str r3, [sp, #0x8]
 *   @0x20bfd8 mov r2, #5
 *   @0x20bfdc sub r1, r1, #1
 *   @0x20bfe0 str r3, [sp]
 *   @0x20bfe4 bic r3, r1, #-16777216
 *   @0x20bfe8 str r2, [sp, #0xc]
 *   @0x20bfec bic r3, r3, #3
 *   @0x20bff0 cmp r3, #0
 *   @0x20bff4 movne r0, #1
 *   @0x20bff8 beq 0x20c010 <_Z10AddToDsMapiPcd+0xd0>
 *   @0x20bffc add sp, sp, #36
 *   @0x20c000 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x20c004 mov r0, #0
 *   @0x20c008 add sp, sp, #36
 *   @0x20c00c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x20c010 mov r0, r8
 *   @0x20c014 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20c018 mov r0, #1
 *   @0x20c01c add sp, sp, #36
 *   @0x20c020 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x20c024 mov r0, sp
 *   @0x20c028 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20c02c b 0x20bfcc <_Z10AddToDsMapiPcd+0x8c>
 *
 * ══ §51/127 AddToDsMap(int, char*, char*)  0x20c030  size 240  60 条（0x20c030..0x20c120）
 * @func 0x20c030 0x20c120  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*)×2 / FREE_RValue__Pre(RValue*)×2 / GetDsMap(int) / CDS_Map::Add(RValue*, RValue*)
 * 字段偏移 top8: 0xc×3 / 0x8×2 / 0x1c×2 / 0x4×1 / 0x10×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20c030 push {r4, r5, r6, r7, r8, lr}
 *   @0x20c034 subs r7, r1, #0
 *   @0x20c038 sub sp, sp, #32
 *   @0x20c03c mov r6, r2
 *   @0x20c040 beq 0x20c0f4 <_Z10AddToDsMapiPcS_+0xc4>
 *   @0x20c044 bl 0x2052d4 <_Z8GetDsMapi>
 *   @0x20c048 subs r8, r0, #0
 *   @0x20c04c beq 0x20c0f4 <_Z10AddToDsMapiPcS_+0xc4>
 *   @0x20c050 add r4, sp, #16
 *   @0x20c054 mov r1, r7
 *   @0x20c058 mov r0, sp
 *   @0x20c05c mov r3, #0
 *   @0x20c060 mov r2, #1
 *   @0x20c064 str r3, [sp]
 *   @0x20c068 str r3, [sp, #0x4]
 *   @0x20c06c str r3, [sp, #0x8]
 *   @0x20c070 str r3, [sp, #0x10]
 *   @0x20c074 str r3, [sp, #0x14]
 *   @0x20c078 str r3, [sp, #0x18]
 *   @0x20c07c str r3, [sp, #0x1c]
 *   @0x20c080 str r2, [sp, #0xc]
 *   @0x20c084 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x20c088 mov r1, r6
 *   @0x20c08c mov r0, r4
 *   @0x20c090 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x20c094 mov r0, r8
 *   @0x20c098 mov r1, sp
 *   @0x20c09c mov r2, r4
 *   @0x20c0a0 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x20c0a4 ldr r3, [sp, #0xc]
 *   @0x20c0a8 sub r3, r3, #1
 *   @0x20c0ac bic r3, r3, #-16777216
 *   @0x20c0b0 bic r3, r3, #3
 *   @0x20c0b4 cmp r3, #0
 *   @0x20c0b8 beq 0x20c114 <_Z10AddToDsMapiPcS_+0xe4>
 *   @0x20c0bc ldr r1, [sp, #0x1c]
 *   @0x20c0c0 mov r3, #0
 *   @0x20c0c4 str r3, [sp, #0x8]
 *   @0x20c0c8 mov r2, #5
 *   @0x20c0cc sub r1, r1, #1
 *   @0x20c0d0 str r3, [sp]
 *   @0x20c0d4 bic r3, r1, #-16777216
 *   @0x20c0d8 str r2, [sp, #0xc]
 *   @0x20c0dc bic r3, r3, #3
 *   @0x20c0e0 cmp r3, #0
 *   @0x20c0e4 movne r0, #1
 *   @0x20c0e8 beq 0x20c100 <_Z10AddToDsMapiPcS_+0xd0>
 *   @0x20c0ec add sp, sp, #32
 *   @0x20c0f0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x20c0f4 mov r0, #0
 *   @0x20c0f8 add sp, sp, #32
 *   @0x20c0fc pop {r4, r5, r6, r7, r8, pc}
 *   @0x20c100 mov r0, r4
 *   @0x20c104 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20c108 mov r0, #1
 *   @0x20c10c add sp, sp, #32
 *   @0x20c110 pop {r4, r5, r6, r7, r8, pc}
 *   @0x20c114 mov r0, sp
 *   @0x20c118 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20c11c b 0x20c0bc <_Z10AddToDsMapiPcS_+0x8c>
 *
 * ══ §52/127 Audio_PrepareGroup(int)  0x219590  size 240  60 条（0x219590..0x219680）
 * @func 0x219590 0x219680  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: cAudio_Sound::Prepare(int)×2 / CAudioGroupMan::GetGroup(int) / Audio_PrepareGroup(int)+0x40 / CAudioGroup::IncLoadCount() / Audio_PrepareGroup(int)+0x9c
 * 字段偏移 top8: 0x20×3 / 0x24×2 / 0x2×2 / 0x4c×2 / 0xd8×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x219590 push {r4, r5, r6, r7, r8, lr}
 *   @0x219594 mov r6, r0
 *   @0x219598 ldr r7, [pc, #0xd8]
 *   @0x21959c mov r1, r6
 *   @0x2195a0 ldr r0, [pc, #0xd4]
 *   @0x2195a4 add r7, pc, r7
 *   @0x2195a8 ldr r0, [pc, r0]
 *   @0x2195ac ldr r5, [r7, #0x20]
 *   @0x2195b0 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi>
 *   @0x2195b4 cmp r5, #0
 *   @0x2195b8 mov r8, r0
 *   @0x2195bc pople {r4, r5, r6, r7, r8, pc}
 *   @0x2195c0 cmp r0, #0
 *   @0x2195c4 movne r4, #0
 *   @0x2195c8 bne 0x2195dc <_Z18Audio_PrepareGroupi+0x4c>
 *   @0x2195cc b 0x219624 <_Z18Audio_PrepareGroupi+0x94>
 *   @0x2195d0 add r4, r4, #1
 *   @0x2195d4 cmp r4, r5
 *   @0x2195d8 beq 0x219620 <_Z18Audio_PrepareGroupi+0x90>
 *   @0x2195dc ldr r3, [r7, #0x20]
 *   @0x2195e0 cmp r3, r4
 *   @0x2195e4 ble 0x2195d0 <_Z18Audio_PrepareGroupi+0x40>
 *   @0x2195e8 ldr r3, [r7, #0x24]
 *   @0x2195ec ldr r0, [r3, r4, lsl #2]
 *   @0x2195f0 cmp r0, #0
 *   @0x2195f4 beq 0x2195d0 <_Z18Audio_PrepareGroupi+0x40>
 *   @0x2195f8 ldr r2, [r0, #0x4c]
 *   @0x2195fc cmp r2, r6
 *   @0x219600 bne 0x2195d0 <_Z18Audio_PrepareGroupi+0x40>
 *   @0x219604 mov r1, r6
 *   @0x219608 add r4, r4, #1
 *   @0x21960c bl 0x219404 <_ZN12cAudio_Sound7PrepareEi>
 *   @0x219610 mov r0, r8
 *   @0x219614 bl 0x21ddf4 <_ZN11CAudioGroup12IncLoadCountEv>
 *   @0x219618 cmp r4, r5
 *   @0x21961c bne 0x2195dc <_Z18Audio_PrepareGroupi+0x4c>
 *   @0x219620 pop {r4, r5, r6, r7, r8, pc}
 *   @0x219624 mov r4, r0
 *   @0x219628 b 0x219638 <_Z18Audio_PrepareGroupi+0xa8>
 *   @0x21962c add r4, r4, #1
 *   @0x219630 cmp r4, r5
 *   @0x219634 beq 0x219674 <_Z18Audio_PrepareGroupi+0xe4>
 *   @0x219638 ldr r3, [r7, #0x20]
 *   @0x21963c cmp r3, r4
 *   @0x219640 ble 0x21962c <_Z18Audio_PrepareGroupi+0x9c>
 *   @0x219644 ldr r3, [r7, #0x24]
 *   @0x219648 ldr r0, [r3, r4, lsl #2]
 *   @0x21964c cmp r0, #0
 *   @0x219650 beq 0x21962c <_Z18Audio_PrepareGroupi+0x9c>
 *   @0x219654 ldr r3, [r0, #0x4c]
 *   @0x219658 cmp r3, r6
 *   @0x21965c bne 0x21962c <_Z18Audio_PrepareGroupi+0x9c>
 *   @0x219660 mov r1, r6
 *   @0x219664 add r4, r4, #1
 *   @0x219668 bl 0x219404 <_ZN12cAudio_Sound7PrepareEi>
 *   @0x21966c cmp r4, r5
 *   @0x219670 bne 0x219638 <_Z18Audio_PrepareGroupi+0xa8>
 *   @0x219674 pop {r4, r5, r6, r7, r8, pc}
 *   @0x219678 ldrsheq r11, [r3], #-192
 *   @0x21967c andseq r5, sp, r8, lsr #21
 *
 * ══ §53/127 CPhysicsWorld::CPhysicsWorld(float, int)  0x237ca0  size 240  60 条（0x237ca0..0x237d90）
 * @func 0x237ca0 0x237d90  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / operator new(unsigned int) / b2World::b2World(b2Vec2 const&) / CPhysicsWorld::Init()
 * 字段偏移 top8: 0xd4×1 / 0xa4×1 / 0xa0×1 / 0x4×1 / 0x14×1 / 0x18×1 / 0x24×1 / 0x30×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237ca0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x237ca4 mov r9, r1
 *   @0x237ca8 ldr r1, [pc, #0xd4]
 *   @0x237cac mov r4, r0
 *   @0x237cb0 sub sp, sp, #12
 *   @0x237cb4 mov r5, #0
 *   @0x237cb8 mov r8, r2
 *   @0x237cbc mov r6, #10
 *   @0x237cc0 add r1, pc, r1
 *   @0x237cc4 stmib r0, {r5, r6}
 *   @0x237cc8 mov r2, #55
 *   @0x237ccc mov r3, #1
 *   @0x237cd0 movw r0, #0x1bf8
 *   @0x237cd4 add r10, r4, #28
 *   @0x237cd8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x237cdc ldr r3, [pc, #0xa4]
 *   @0x237ce0 vmov.f32 s15, #1.000000e+00
 *   @0x237ce4 ldr r12, [pc, #0xa0]
 *   @0x237ce8 ldr r3, [pc, r3]
 *   @0x237cec mov r1, #0
 *   @0x237cf0 movt r1, #0x4120
 *   @0x237cf4 str r1, [sp, #0x4]
 *   @0x237cf8 add r2, r4, #40
 *   @0x237cfc ldr r12, [pc, r12]
 *   @0x237d00 mov lr, #0
 *   @0x237d04 str r5, [r4, #0x14]
 *   @0x237d08 str r5, [r4, #0x18]
 *   @0x237d0c mov r7, #1
 *   @0x237d10 lsl r11, r7, #16
 *   @0x237d14 str lr, [sp]
 *   @0x237d18 str r0, [r4]
 *   @0x237d1c ldm r3, {r0, r1}
 *   @0x237d20 stm r10, {r0, r1}
 *   @0x237d24 str lr, [r4, #0x24]
 *   @0x237d28 stm r2, {r0, r1}
 *   @0x237d2c vstr s15, [r4, #56]
 *   @0x237d30 ldr r0, [r12]
 *   @0x237d34 str lr, [r4, #0x30]
 *   @0x237d38 str r5, [r4, #0x3c]
 *   @0x237d3c str r0, [r4, #0x34]
 *   @0x237d40 orr r0, r11, #37632
 *   @0x237d44 str r5, [r4, #0x44]
 *   @0x237d48 orr r0, r0, #84
 *   @0x237d4c str r9, [r4, #0x60]
 *   @0x237d50 str r6, [r4, #0x5c]
 *   @0x237d54 str r8, [r4, #0x58]
 *   @0x237d58 strb r7, [r4, #0x40]
 *   @0x237d5c bl 0x27c524 <_Znwj>
 *   @0x237d60 mov r1, sp
 *   @0x237d64 mov r5, r0
 *   @0x237d68 bl 0x2c8e10 <_ZN7b2WorldC2ERK6b2Vec2>
 *   @0x237d6c mov r0, r4
 *   @0x237d70 str r5, [r4, #0x10]
 *   @0x237d74 bl 0x237bf8 <_ZN13CPhysicsWorld4InitEv>
 *   @0x237d78 mov r0, r4
 *   @0x237d7c add sp, sp, #12
 *   @0x237d80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x237d84 andseq sp, r1, r4, asr #10
 *   @0x237d88 ldrsheq r9, [r11], -r0
 *   @0x237d8c andseq r9, r11, r0, ror #15
 *
 * ══ §54/127 CPhysicsWorld::CreateDistanceJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, bool)  0x238e70  size 240  60 条（0x238e70..0x238f60）
 * @func 0x238e70 0x238f74  size 260  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DistanceJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&, b2Vec2 const&) / CPhysicsJointFactory::CreateJoint(CPhysicsWorld*, b2JointDef const&)
 * 字段偏移 top8: 0x4×2 / 0x28×2 / 0x6c×1 / 0x1c×1 / 0x20×1 / 0x24×1 / 0x2c×1 / 0x30×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238e70 vmov s11, r3
 *   @0x238e74 ldr r1, [r1]
 *   @0x238e78 push {r4, r5, r6, r7, lr}
 *   @0x238e7c mov r4, r0
 *   @0x238e80 vldr s15, [r4, #96]
 *   @0x238e84 sub sp, sp, #76
 *   @0x238e88 vmul.f32 s11, s15, s11
 *   @0x238e8c vldr s13, [sp, #104]
 *   @0x238e90 vldr s12, [sp, #96]
 *   @0x238e94 vldr s14, [sp, #100]
 *   @0x238e98 ldrh r3, [r1, #4]
 *   @0x238e9c ldr r2, [r2]
 *   @0x238ea0 add r5, sp, #24
 *   @0x238ea4 tst r3, #2
 *   @0x238ea8 ldrb r6, [sp, #0x6c]
 *   @0x238eac orreq r3, r3, #2
 *   @0x238eb0 strheq r3, [r1, #4]
 *   @0x238eb4 ldrh r3, [r2, #4]
 *   @0x238eb8 moveq r0, #0
 *   @0x238ebc streq r0, [r1, #0xa0]
 *   @0x238ec0 mov lr, #0
 *   @0x238ec4 tst r3, #2
 *   @0x238ec8 mov r12, #0
 *   @0x238ecc orreq r3, r3, #2
 *   @0x238ed0 strheq r3, [r2, #4]
 *   @0x238ed4 moveq r0, #0
 *   @0x238ed8 add r3, sp, #16
 *   @0x238edc streq r0, [r2, #0xa0]
 *   @0x238ee0 mov r0, r5
 *   @0x238ee4 vmul.f32 s12, s15, s12
 *   @0x238ee8 str r3, [sp]
 *   @0x238eec add r3, sp, #8
 *   @0x238ef0 str lr, [sp, #0x1c]
 *   @0x238ef4 str lr, [sp, #0x20]
 *   @0x238ef8 vstr s11, [sp, #8]
 *   @0x238efc str lr, [sp, #0x24]
 *   @0x238f00 mov r7, #3
 *   @0x238f04 strb lr, [sp, #0x28]
 *   @0x238f08 str r12, [sp, #0x2c]
 *   @0x238f0c str r12, [sp, #0x30]
 *   @0x238f10 str r12, [sp, #0x34]
 *   @0x238f14 str r12, [sp, #0x38]
 *   @0x238f18 str r12, [sp, #0x40]
 *   @0x238f1c str r12, [sp, #0x44]
 *   @0x238f20 mov r12, #1065353216
 *   @0x238f24 str r7, [sp, #0x18]
 *   @0x238f28 vmul.f32 s14, s15, s14
 *   @0x238f2c vstr s12, [sp, #12]
 *   @0x238f30 str r12, [sp, #0x3c]
 *   @0x238f34 vmul.f32 s15, s15, s13
 *   @0x238f38 vstr s14, [sp, #16]
 *   @0x238f3c vstr s15, [sp, #20]
 *   @0x238f40 bl 0x2cd1e0 <_ZN18b2DistanceJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_>
 *   @0x238f44 mov r1, r5
 *   @0x238f48 mov r0, r4
 *   @0x238f4c strb r6, [sp, #0x28]
 *   @0x238f50 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef>
 *   @0x238f54 ldr r0, [r0, #0x8]
 *   @0x238f58 add sp, sp, #76
 *   @0x238f5c pop {r4, r5, r6, r7, pc}
 *
 * ══ §55/127 CPhysicsWorld::CreateRopeJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, float, bool)  0x238f60  size 240  60 条（0x238f60..0x239050）
 * @func 0x238f60 0x239050  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsJointFactory::CreateJoint(CPhysicsWorld*, b2JointDef const&)
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x-4×1 / 0x40×1 / 0x10×1 / 0xc×1
 * VFP 指令 32 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238f60 str lr, [sp, #-0x4]!
 *   @0x238f64 vldr s15, [r0, #96]
 *   @0x238f68 sub sp, sp, #44
 *   @0x238f6c vldr s14, [sp, #48]
 *   @0x238f70 ldr r12, [r1]
 *   @0x238f74 vldr s3, [sp, #56]
 *   @0x238f78 ldr r2, [r2]
 *   @0x238f7c vldr s11, [r12, #16]
 *   @0x238f80 vldr s12, [r2, #16]
 *   @0x238f84 vnmls.f32 s11, s15, s14
 *   @0x238f88 vmov s9, r3
 *   @0x238f8c vldr s13, [r12, #12]
 *   @0x238f90 vldr s14, [r2, #12]
 *   @0x238f94 vldr s10, [sp, #52]
 *   @0x238f98 vldr s6, [r12, #20]
 *   @0x238f9c vldr s5, [r12, #24]
 *   @0x238fa0 vldr s8, [r2, #20]
 *   @0x238fa4 vldr s7, [r2, #24]
 *   @0x238fa8 vldr s4, [sp, #60]
 *   @0x238fac ldrh r3, [r12, #4]
 *   @0x238fb0 ldrb lr, [sp, #0x40]
 *   @0x238fb4 tst r3, #2
 *   @0x238fb8 orreq r3, r3, #2
 *   @0x238fbc strheq r3, [r12, #4]
 *   @0x238fc0 ldrh r3, [r2, #4]
 *   @0x238fc4 moveq r1, #0
 *   @0x238fc8 streq r1, [r12, #0xa0]
 *   @0x238fcc tst r3, #2
 *   @0x238fd0 orreq r3, r3, #2
 *   @0x238fd4 strheq r3, [r2, #4]
 *   @0x238fd8 moveq r1, #0
 *   @0x238fdc streq r1, [r2, #0xa0]
 *   @0x238fe0 mov r1, sp
 *   @0x238fe4 str r12, [sp, #0x8]
 *   @0x238fe8 mov r3, #10
 *   @0x238fec mov r12, #0
 *   @0x238ff0 strb lr, [sp, #0x10]
 *   @0x238ff4 str r2, [sp, #0xc]
 *   @0x238ff8 stm sp, {r3, r12}
 *   @0x238ffc vnmls.f32 s12, s15, s3
 *   @0x239000 vnmls.f32 s13, s15, s9
 *   @0x239004 vnmls.f32 s14, s15, s10
 *   @0x239008 vmul.f32 s9, s11, s6
 *   @0x23900c vmul.f32 s10, s12, s8
 *   @0x239010 vmul.f32 s11, s11, s5
 *   @0x239014 vmul.f32 s12, s12, s7
 *   @0x239018 vmla.f32 s9, s13, s5
 *   @0x23901c vmls.f32 s11, s6, s13
 *   @0x239020 vstr s9, [sp, #20]
 *   @0x239024 vmla.f32 s10, s14, s7
 *   @0x239028 vstr s11, [sp, #24]
 *   @0x23902c vmls.f32 s12, s8, s14
 *   @0x239030 vstr s10, [sp, #28]
 *   @0x239034 vmul.f32 s15, s15, s4
 *   @0x239038 vstr s12, [sp, #32]
 *   @0x23903c vstr s15, [sp, #36]
 *   @0x239040 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef>
 *   @0x239044 ldr r0, [r0, #0x8]
 *   @0x239048 add sp, sp, #44
 *   @0x23904c ldr pc, [sp], #4
 *
 * ══ §56/127 F_JS_ToObject(RValue*, RValue*)  0x2403cc  size 240  60 条（0x2403cc..0x2404bc）
 * @func 0x2403cc 0x2404bc  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYError(char const*, ...)
 * 字段偏移 top8: 0xc×4 / 0x7c×2 / 0x58×2 / 0x4×2 / 0x8×2 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2403cc push {r3, r4, r5, lr}
 *   @0x2403d0 ldr r3, [r1, #0xc]
 *   @0x2403d4 bic r3, r3, #-16777216
 *   @0x2403d8 cmp r3, #12
 *   @0x2403dc addls pc, pc, r3, lsl #2
 *   @0x2403e0 b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4>
 *   @0x2403e4 b 0x240450 <_Z13F_JS_ToObjectP6RValueS0_+0x84>
 *   @0x2403e8 b 0x240424 <_Z13F_JS_ToObjectP6RValueS0_+0x58>
 *   @0x2403ec b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4>
 *   @0x2403f0 b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4>
 *   @0x2403f4 b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4>
 *   @0x2403f8 b 0x240418 <_Z13F_JS_ToObjectP6RValueS0_+0x4c>
 *   @0x2403fc b 0x240464 <_Z13F_JS_ToObjectP6RValueS0_+0x98>
 *   @0x240400 b 0x240450 <_Z13F_JS_ToObjectP6RValueS0_+0x84>
 *   @0x240404 b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4>
 *   @0x240408 b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4>
 *   @0x24040c b 0x240450 <_Z13F_JS_ToObjectP6RValueS0_+0x84>
 *   @0x240410 b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4>
 *   @0x240414 b 0x240418 <_Z13F_JS_ToObjectP6RValueS0_+0x4c>
 *   @0x240418 mov r3, #1
 *   @0x24041c mov r0, r3
 *   @0x240420 pop {r3, r4, r5, pc}
 *   @0x240424 ldr r3, [pc, #0x7c]
 *   @0x240428 ldr r1, [pc, #0x7c]
 *   @0x24042c ldr r3, [pc, r3]
 *   @0x240430 add r1, pc, r1
 *   @0x240434 ldr r0, [r3]
 *   @0x240438 ldr r3, [r0]
 *   @0x24043c ldr r3, [r3, #0xc]
 *   @0x240440 blx r3
 *   @0x240444 mov r3, #1
 *   @0x240448 mov r0, r3
 *   @0x24044c pop {r3, r4, r5, pc}
 *   @0x240450 ldr r3, [pc, #0x58]
 *   @0x240454 ldr r1, [pc, #0x58]
 *   @0x240458 ldr r3, [pc, r3]
 *   @0x24045c add r1, pc, r1
 *   @0x240460 b 0x240434 <_Z13F_JS_ToObjectP6RValueS0_+0x68>
 *   @0x240464 ldr r5, [r1]
 *   @0x240468 mov r3, #0
 *   @0x24046c ldr r4, [r1, #0x4]
 *   @0x240470 ldr r12, [r1, #0x8]
 *   @0x240474 ldr r2, [r1, #0xc]
 *   @0x240478 str r5, [r0]
 *   @0x24047c str r4, [r0, #0x4]
 *   @0x240480 str r12, [r0, #0x8]
 *   @0x240484 str r2, [r0, #0xc]
 *   @0x240488 mov r0, r3
 *   @0x24048c pop {r3, r4, r5, pc}
 *   @0x240490 ldr r0, [pc, #0x20]
 *   @0x240494 add r0, pc, r0
 *   @0x240498 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x24049c mov r3, #1
 *   @0x2404a0 mov r0, r3
 *   @0x2404a4 pop {r3, r4, r5, pc}
 *   @0x2404a8 andseq sp, r10, r8, ror #5
 *   @0x2404ac andseq r5, r1, r12, asr #32
 *   @0x2404b0 ldrheq sp, [r10], -r12
 *   @0x2404b4 ldrsbeq r4, [r1], -r4
 *   @0x2404b8 andseq r5, r1, r8, lsr #32
 *
 * ══ §57/127 lh_table_insert  0x280998  size 240  60 条（0x280998..0x280a88）
 * @func 0x280998 0x280a88  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_uidivmod / lh_table_resize
 * 字段偏移 top8: 0x4×4 / 0x14×2 / 0x8×2 / 0x30×1 / 0x28×1 / 0x20×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280998 ldr r3, [r0]
 *   @0x28099c vldr d7, [pc, #220]
 *   @0x2809a0 push {r4, r5, r6, r7, r8, lr}
 *   @0x2809a4 mov r6, r2
 *   @0x2809a8 vmov s11, r3
 *   @0x2809ac ldr r2, [r0, #0x14]
 *   @0x2809b0 mov r4, r0
 *   @0x2809b4 mov r7, r1
 *   @0x2809b8 vcvt.f64.s32 d6, s11
 *   @0x2809bc vldr s11, [r0, #4]
 *   @0x2809c0 add r2, r2, #1
 *   @0x2809c4 str r2, [r0, #0x14]
 *   @0x2809c8 vmul.f64 d7, d6, d7
 *   @0x2809cc vcvt.f64.s32 d6, s11
 *   @0x2809d0 vcmpe.f64 d6, d7
 *   @0x2809d4 vmrs APSR_nzcv, fpscr
 *   @0x2809d8 bgt 0x280a74 <lh_table_insert+0xdc>
 *   @0x2809dc ldr r3, [r4, #0x30]
 *   @0x2809e0 mov r0, r7
 *   @0x2809e4 blx r3
 *   @0x2809e8 ldr r8, [r4]
 *   @0x2809ec mov r1, r8
 *   @0x2809f0 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x2809f4 ldr r12, [r4, #0x28]
 *   @0x2809f8 b 0x280a10 <lh_table_insert+0x78>
 *   @0x2809fc cmp r8, r1
 *   @0x280a00 ldr r5, [r4, #0x8]
 *   @0x280a04 moveq r1, #0
 *   @0x280a08 add r5, r5, #1
 *   @0x280a0c str r5, [r4, #0x8]
 *   @0x280a10 ldr r5, [r12, r1, lsl #4]
 *   @0x280a14 add r2, r12, r1, lsl #4
 *   @0x280a18 add r1, r1, #1
 *   @0x280a1c add r5, r5, #2
 *   @0x280a20 cmp r5, #1
 *   @0x280a24 bhi 0x2809fc <lh_table_insert+0x64>
 *   @0x280a28 ldr r3, [r4, #0x20]
 *   @0x280a2c mov r0, #0
 *   @0x280a30 ldr r1, [r4, #0x4]
 *   @0x280a34 cmp r3, #0
 *   @0x280a38 str r7, [r2]
 *   @0x280a3c str r6, [r2, #0x4]
 *   @0x280a40 add r1, r1, #1
 *   @0x280a44 ldrne r3, [r4, #0x24]
 *   @0x280a48 str r1, [r4, #0x4]
 *   @0x280a4c movne r1, #0
 *   @0x280a50 streq r2, [r4, #0x24]
 *   @0x280a54 strne r2, [r3, #0x8]
 *   @0x280a58 streq r2, [r4, #0x20]
 *   @0x280a5c strne r3, [r2, #0xc]
 *   @0x280a60 strne r1, [r2, #0x8]
 *   @0x280a64 streq r3, [r2, #0xc]
 *   @0x280a68 streq r3, [r2, #0x8]
 *   @0x280a6c strne r2, [r4, #0x24]
 *   @0x280a70 pop {r4, r5, r6, r7, r8, pc}
 *   @0x280a74 lsl r1, r3, #1
 *   @0x280a78 bl 0x280a88 <lh_table_resize>
 *   @0x280a7c b 0x2809dc <lh_table_insert+0x44>
 *   @0x280a80 mvnpl r8, pc, lsl r5
 *   @0x280a84 svclo #0xe51eb8
 *
 * ══ §58/127 Debug_DoSingleStep(int)  0x29c780  size 240  60 条（0x29c780..0x29c870）
 * @func 0x29c780 0x29c870  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29c78c→0x47f298, 0x29c7c0→0x3f2098, 0x29c7cc→0x47f290, 0x29c7fc→0x47f28c, 0x29c808→0x542979, 0x29c810→0x3f2094, 0x29c828→0x3f2098, 0x29c830→0x47f290
 * 调用序列: VM::DebugInfo(VMBuffer*, int) / VM::DebugLineNumber(VMDebugInfo*, char const*, char**)
 * 字段偏移 top8: 0xc4×2 / 0x3c×2 / 0x28×2 / 0x44×1 / 0x38×1 / 0x94×1 / 0x8c×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c780 push {r4, r5, r6, lr}
 *   @0x29c784 mov r6, r0
 *   @0x29c788 ldr r4, [pc, #0xc4]
 *   @0x29c78c ldr r3, [pc, #0xc4]
 *   @0x29c790 add r4, pc, r4
 *   @0x29c794 ldr r5, [r4, r3]
 *   @0x29c798 ldr r3, [r5]
 *   @0x29c79c cmp r3, #0
 *   @0x29c7a0 beq 0x29c828 <_Z18Debug_DoSingleStepi+0xa8>
 *   @0x29c7a4 ldr r1, [r3, #0x44]
 *   @0x29c7a8 ldr r0, [r3, #0x38]
 *   @0x29c7ac bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi>
 *   @0x29c7b0 ldr r3, [r5]
 *   @0x29c7b4 mov r2, #0
 *   @0x29c7b8 ldr r1, [r3, #0x3c]
 *   @0x29c7bc bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc>
 *   @0x29c7c0 ldr r1, [pc, #0x94]
 *   @0x29c7c4 ldr r3, [r5]
 *   @0x29c7c8 mov r2, #0
 *   @0x29c7cc ldr r12, [pc, #0x8c]
 *   @0x29c7d0 ldr r5, [r4, r1]
 *   @0x29c7d4 ldr r1, [r3, #0x3c]
 *   @0x29c7d8 str r0, [r5]
 *   @0x29c7dc ldr r0, [r4, r12]
 *   @0x29c7e0 str r1, [r0]
 *   @0x29c7e4 ldr r1, [r3, #0x4c]
 *   @0x29c7e8 add r2, r2, #1
 *   @0x29c7ec ldr r3, [r3, #0x4]
 *   @0x29c7f0 add r2, r2, r1
 *   @0x29c7f4 cmp r3, #0
 *   @0x29c7f8 bne 0x29c7e4 <_Z18Debug_DoSingleStepi+0x64>
 *   @0x29c7fc ldr r3, [pc, #0x60]
 *   @0x29c800 ldr r3, [r4, r3]
 *   @0x29c804 str r2, [r3]
 *   @0x29c808 ldr r2, [pc, #0x58]
 *   @0x29c80c mov r1, #0
 *   @0x29c810 ldr r3, [pc, #0x54]
 *   @0x29c814 ldr r2, [r4, r2]
 *   @0x29c818 strb r1, [r2]
 *   @0x29c81c ldr r3, [r4, r3]
 *   @0x29c820 str r6, [r3]
 *   @0x29c824 pop {r4, r5, r6, pc}
 *   @0x29c828 ldr r0, [pc, #0x2c]
 *   @0x29c82c mvn r12, #0
 *   @0x29c830 ldr r1, [pc, #0x28]
 *   @0x29c834 ldr r2, [pc, #0x28]
 *   @0x29c838 ldr r0, [r4, r0]
 *   @0x29c83c str r12, [r0]
 *   @0x29c840 ldr r1, [r4, r1]
 *   @0x29c844 str r3, [r1]
 *   @0x29c848 ldr r2, [r4, r2]
 *   @0x29c84c str r3, [r2]
 *   @0x29c850 b 0x29c808 <_Z18Debug_DoSingleStepi+0x88>
 *   @0x29c854 andseq r5, r5, r0, asr #9
 *   @0x29c858 .word 0xffffbf58
 *   @0x29c85c .word 0xffffc0f8
 *   @0x29c860 .word 0xffffc0f0
 *   @0x29c864 .word 0xffffc0f4
 *   @0x29c868 .word 0xffffdfa0
 *   @0x29c86c .word 0xffffc0e8
 *
 * ══ §59/127 Quit()  0x2a27fc  size 240  60 条（0x2a27fc..0x2a28ec）
 * @func 0x2a27fc 0x2a28ec  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CleanGestures() / FreeAllObjects() / FreeAllDataStructures() / ResetGC() / QuitYoYoFunctions() / QuitNetworkingFunctions() / FINALIZE_Score() / FINALIZE_Code_Constant()
 * 字段偏移 top8: 0xd0×1 / 0x48×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a27fc push {r4, lr}
 *   @0x2a2800 bl 0x1dba70 <_Z13CleanGesturesv>
 *   @0x2a2804 bl 0xd675c <_Z14FreeAllObjectsv>
 *   @0x2a2808 ldr r4, [pc, #0xd0]
 *   @0x2a280c bl 0x20b27c <_Z21FreeAllDataStructuresv>
 *   @0x2a2810 bl 0xd66e0 <_Z7ResetGCv>
 *   @0x2a2814 bl 0x15a0c0 <_Z17QuitYoYoFunctionsv>
 *   @0x2a2818 bl 0x2998b8 <_Z23QuitNetworkingFunctionsv>
 *   @0x2a281c bl 0x1dc3bc <_Z14FINALIZE_Scorev>
 *   @0x2a2820 bl 0xf1bb0 <_Z22FINALIZE_Code_Constantv>
 *   @0x2a2824 bl 0xce274 <_Z22FINALIZE_Code_Functionv>
 *   @0x2a2828 bl 0xcf478 <_Z18FINALIZE_Code_Mainv>
 *   @0x2a282c bl 0xd2618 <_Z22FINALIZE_Code_Variablev>
 *   @0x2a2830 bl 0x19c2cc <_Z20FINALIZE_Motion_Gridv>
 *   @0x2a2834 bl 0x1b5e54 <_Z18FINALIZE_Room_Mainv>
 *   @0x2a2838 bl 0x1959f4 <_Z23FINALIZE_Instance_Classv>
 *   @0x2a283c bl 0x1d37cc <_Z17FINALIZE_Run_Mainv>
 *   @0x2a2840 bl 0x19e884 <_Z21FINALIZE_Object_Listsv>
 *   @0x2a2844 bl 0x19f0c0 <_Z20FINALIZE_Object_Mainv>
 *   @0x2a2848 bl 0x19e1c8 <_Z21FINALIZE_Object_Classv>
 *   @0x2a284c bl 0x1a5de8 <_Z22FINALIZE_Particle_Mainv>
 *   @0x2a2850 bl 0x1ee76c <_Z21FINALIZE_Sprite_Classv>
 *   @0x2a2854 bl 0x1ef514 <_Z20FINALIZE_Sprite_Mainv>
 *   @0x2a2858 bl 0x214e14 <_Z21FINALIZE_Support_Filev>
 *   @0x2a285c bl 0x1e3180 <_Z22FINALIZE_VertexFormatsv>
 *   @0x2a2860 bl 0x17dbb8 <_Z25FINALIZE_Graphics_Displayv>
 *   @0x2a2864 bl 0xc42f4 <_Z19FINALIZE_Backgroundv>
 *   @0x2a2868 bl 0x1767cc <_Z25FINALIZE_Graphics_Texturev>
 *   @0x2a286c bl 0x1e0770 <_Z20FINALIZE_Script_Mainv>
 *   @0x2a2870 bl 0x1f4d10 <_Z22FINALIZE_Variable_Mainv>
 *   @0x2a2874 bl 0xface8 <_Z18FINALIZE_Font_Mainv>
 *   @0x2a2878 bl 0x1738fc <_Z22FINALIZE_Graphics_Textv>
 *   @0x2a287c bl 0xf2c9c <_Z21FINALIZE_Event_Actionv>
 *   @0x2a2880 bl 0x13cf04 <_Z22FINALIZE_Function_Filev>
 *   @0x2a2884 bl 0x1f3174 <_Z22FINALIZE_Timeline_Mainv>
 *   @0x2a2888 bl 0x1df90c <_Z20FINALIZE_Runner_Formv>
 *   @0x2a288c bl 0x21f49c <_Z14FINALIZE_Soundv>
 *   @0x2a2890 bl 0xc47f8 <_Z12FINALIZE_Allv>
 *   @0x2a2894 ldr r0, [pc, #0x48]
 *   @0x2a2898 ldr r0, [pc, r0]
 *   @0x2a289c bl 0x2a0364 <_ZN9CProfiler5CleanEv>
 *   @0x2a28a0 bl 0x168c90 <_Z10GR_D3D_Endv>
 *   @0x2a28a4 ldr r4, [pc, r4]
 *   @0x2a28a8 ldr r0, [r4]
 *   @0x2a28ac cmp r0, #0
 *   @0x2a28b0 beq 0x2a28d0 <_Z4Quitv+0xd4>
 *   @0x2a28b4 bl 0x1a88c0 <_Z15yyDestroyWindowPv>
 *   @0x2a28b8 ldr r3, [pc, #0x28]
 *   @0x2a28bc mov r2, #1
 *   @0x2a28c0 mov r1, #0
 *   @0x2a28c4 ldr r3, [pc, r3]
 *   @0x2a28c8 str r1, [r4]
 *   @0x2a28cc strb r2, [r3]
 *   @0x2a28d0 bl 0x28fe68 <_Z25FINALIZE_PlatformSpecificv>
 *   @0x2a28d4 bl 0xd826c <_ZN2VM4QuitEv>
 *   @0x2a28d8 pop {r4, lr}
 *   @0x2a28dc b 0xc7b44 <_Z14FreeAllBuffersv>
 *   @0x2a28e0 andseq sp, r4, r0, asr pc
 *   @0x2a28e4 ldrsbeq r11, [r4], -r4
 *   @0x2a28e8 ldrheq pc, [r4], -r4
 *
 * ══ §60/127 _zip_error_strerror(zip_error*)  0x2a57f8  size 240  60 条（0x2a57f8..0x2a58e8）
 * @func 0x2a57f8 0x2a58e8  size 240  60 条
 * 部分覆盖: 本节 60/108 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6550×2 / _zip_error_strerror(zip_error*)+0x3a / 0xc758c8 / ps_hints_apply+0x4d0 / 0xb6f28 / 0xb6f34 / 0xb6538 / 0xb6544
 * 字段偏移 top8: 0x14×3 / 0x8c×1 / 0xb0×1 / 0xa8×1 / 0x50×1 / 0x38×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a57f8 push.w {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2a57fc sub sp, #0x94
 *   @0x2a5800 mov r7, r0
 *   @0x2a5804 add r5, pc
 *   @0x2a5808 ldr r3, [r4]
 *   @0x2a580c str r3, [sp, #0x8c]
 *   @0x2a5810 ldmdavs r10!, {r1, r2, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2a5814 cmp r2, #0x0
 *   @0x2a5818 ldr r3, [pc, #0xb0]
 *   @0x2a581c ldr r3, [r3]
 *   @0x2a5820 blt 0x2a5832 <_Z19_zip_error_strerrorP9zip_error+0x3a>
 *   @0x2a5824 ldr r1, [pc, #0xa8]
 *   @0x2a5828 mov r0, r6
 *   @0x2a582c blx 0xb6550 <sprintf@plt>
 *   @0x2a5830 b 0x2a585c <_Z19_zip_error_strerrorP9zip_error+0x64>
 *   @0x2a5834 ldr r3, [r5, r3]
 *   @0x2a5838 blmi 0xc758c8 <b2_toiTime+0x51c424>
 *   @0x2a583c ldr r3, [r5, r3]
 *   @0x2a5840 blhs 0x2f18d0 <ps_hints_apply+0x4d0>
 *   @0x2a5844 beq 0x2a5852 <_Z19_zip_error_strerrorP9zip_error+0x5a>
 *   @0x2a5848 bne 0x2a58ac <_Z19_zip_error_strerrorP9zip_error+0xb4>
 *   @0x2a584c blx 0xb6f28 <zError@plt>
 *   @0x2a5850 b 0x2a5858 <_Z19_zip_error_strerrorP9zip_error+0x60>
 *   @0x2a5854 blx 0xb6f34 <strerror@plt>
 *   @0x2a5858 mov r6, r0
 *   @0x2a585c mov r0, r6
 *   @0x2a5860 strmi lr, [r0], r12, ror #28
 *   @0x2a5864 cbz r4, 0x2a5870 <_Z19_zip_error_strerrorP9zip_error+0x78>
 *   @0x2a5868 blx 0xb6538 <strlen@plt>
 *   @0x2a586c adds r3, r0, #0x2
 *   @0x2a5870 mov r3, r4
 *   @0x2a5874 ldrmi r0, [r8], #-1
 *   @0x2a5878 blx 0xb6544 <malloc@plt>
 *   @0x2a587c mov r8, r0
 *   @0x2a5880 ldr r3, [pc, #0x50]
 *   @0x2a5884 ldr r0, [r3, #0x38]
 *   @0x2a5888 cbnz r4, 0x2a5892 <_Z19_zip_error_strerrorP9zip_error+0x9a>
 *   @0x2a588c add r2, pc
 *   @0x2a5890 b 0x2a5898 <_Z19_zip_error_strerrorP9zip_error+0xa0>
 *   @0x2a5894 mov r2, r4
 *   @0x2a5898 ldr r1, [pc, #0x48]
 *   @0x2a589c str r6, [sp]
 *   @0x2a58a0 blx 0xb6550 <sprintf@plt>
 *   @0x2a58a4 str.w r8, [r7, #0x8]
 *   @0x2a58a8 mov r0, r8
 *   @0x2a58ac mov r0, r4
 *   @0x2a58b0 ldr.w r3, [r9]
 *   @0x2a58b4 cmp r2, r3
 *   @0x2a58b8 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2a58bc add sp, #0x94
 *   @0x2a58c0 svclt #0x83f0
 *   @0x2a58c4 stm r4!, {r4, r6}
 *   @0x2a58c8 pop {pc}
 *   @0x2a58cc .word 0xfffffe30
 *   @0x2a58d0 ldrdeq r6, r7, [lr], -r8
 *   @0x2a58d4 mcr2 p15, #0x2, pc, c0, c15, #0x7
 *   @0x2a58d8 mrc2 p15, #0x1, apsr_nzcv, c4, c15, #0x7
 *   @0x2a58dc ldr r5, [r6, #0x14]
 *   @0x2a58e0 ldr r0, [r5, #0x14]
 *   @0x2a58e4 ldr r5, [r6, #0x14]
 *
 * ══ §61/127 png_handle_sBIT  0x2ac238  size 240  60 条（0x2ac238..0x2ac328）
 * @func 0x2ac238 0x2ac328  size 240  60 条
 * 部分覆盖: 本节 60/104 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning / png_crc_finish / 0xceb66c / png_set_sBIT
 * 字段偏移 top8: 0xac×1 / 0x8×1 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ac238 push {r0, r1, r4, r5, r6, lr}
 *   @0x2ac23c strb.w r3, [sp, #0x7]
 *   @0x2ac240 mov r5, r2
 *   @0x2ac244 strmi r3, [r4], -r6
 *   @0x2ac248 strb.w r3, [sp, #0x5]
 *   @0x2ac24c mov r6, r1
 *   @0x2ac250 .word 0xf8d03004
 *   @0x2ac254 ldrbeq r3, [r10, r12, lsr #2]
 *   @0x2ac258 bmi 0x2ac264 <png_handle_sBIT+0x2c>
 *   @0x2ac25c add r1, pc
 *   @0x2ac260 and pc, r10, r5, ror #17
 *   @0x2ac264 lsls r1, r3, #0x1d
 *   @0x2ac268 ldr r1, [pc, #0xac]
 *   @0x2ac26c b 0x2ac288 <png_handle_sBIT+0x50>
 *   @0x2ac270 bpl 0x2ac27a <png_handle_sBIT+0x42>
 *   @0x2ac274 add r1, pc
 *   @0x2ac278 .word 0xb166f8fd
 *   @0x2ac27c ldr r3, [r6, #0x8]
 *   @0x2ac280 bpl 0x2ac296 <png_handle_sBIT+0x5e>
 *   @0x2ac284 mov r0, r4
 *   @0x2ac288 bl 0x2a6474 <png_warning>
 *   @0x2ac28c mov r0, r4
 *   @0x2ac290 bl 0x2abc94 <png_crc_finish>
 *   @0x2ac294 b 0x2ac310 <png_handle_sBIT+0xd8>
 *   @0x2ac298 strtmi r3, [r0], -r10, ror #3
 *   @0x2ac29c cmp r3, #0x3
 *   @0x2ac2a0 ldrbne.w r3, [r4, #0x1ee]
 *   @0x2ac2a4 cmp r5, r3
 *   @0x2ac2a8 cmp r5, #0x4
 *   @0x2ac2ac ldr r1, [pc, #0x74]
 *   @0x2ac2b0 b 0x2ac288 <png_handle_sBIT+0x50>
 *   @0x2ac2b4 mov r2, r5
 *   @0x2ac2b8 strtmi pc, [r0], -r9, lsr #25
 *   @0x2ac2bc movs r1, #0x0
 *   @0x2ac2c0 bllt 0xceb66c <b2_toiTime+0x5921c8>
 *   @0x2ac2c4 ldrb.w r3, [r4, #0x1ea]
 *   @0x2ac2c8 ldrb.w r2, [sp, #0x5]
 *   @0x2ac2cc tst.w r3, #0x2
 *   @0x2ac2d0 ldrb.w r3, [sp, #0x4]
 *   @0x2ac2d4 beq 0x2ac2f0 <png_handle_sBIT+0xb8>
 *   @0x2ac2d8 .word 0xf89d3240
 *   @0x2ac2dc .word 0xf8843006
 *   @0x2ac2e0 .word 0xf8842241
 *   @0x2ac2e4 .word 0xf89d3242
 *   @0x2ac2e8 .word 0xf8843007
 *   @0x2ac2ec and r3, r9, r4, asr #4
 *   @0x2ac2f0 strb.w r3, [r4, #0x243]
 *   @0x2ac2f4 strb.w r3, [r4, #0x240]
 *   @0x2ac2f8 strb.w r3, [r4, #0x241]
 *   @0x2ac2fc strb.w r3, [r4, #0x242]
 *   @0x2ac300 strb.w r2, [r4, #0x244]
 *   @0x2ac304 mov r0, r4
 *   @0x2ac308 add.w r2, r4, #0x240
 *   @0x2ac30c bl 0x2aed1c <png_set_sBIT>
 *   @0x2ac310 add sp, #0x8
 *   @0x2ac314 lsrs r7, r4, #0x10
 *   @0x2ac318 lsrs r2, r6, #0x10
 *   @0x2ac31c lsrs r0, r0, #0x11
 *   @0x2ac320 lsrs r6, r0, #0x11
 *   @0x2ac324 lsrs r3, r6, #0x10
 *
 * ══ §62/127 DGifGetRecordType(GifFileType*, GifRecordType*)  0x2c1db8  size 240  60 条（0x2c1db8..0x2c1ea8）
 * @func 0x2c1db8 0x2c1ea8  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68c8
 * 字段偏移 top8: 0x40×2 / 0x48×1 / 0x3c×1 / 0x7×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c1db8 ldr r2, [r0, #0x48]
 *   @0x2c1dbc push {r4, r5, lr}
 *   @0x2c1dc0 mov r4, r0
 *   @0x2c1dc4 ldr r3, [r2]
 *   @0x2c1dc8 sub sp, sp, #12
 *   @0x2c1dcc mov r5, r1
 *   @0x2c1dd0 ands r3, r3, #8
 *   @0x2c1dd4 moveq r2, #111
 *   @0x2c1dd8 streq r2, [r0, #0x40]
 *   @0x2c1ddc beq 0x2c1e34 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0x7c>
 *   @0x2c1de0 ldr r3, [r2, #0x3c]
 *   @0x2c1de4 cmp r3, #0
 *   @0x2c1de8 beq 0x2c1e88 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0xd0>
 *   @0x2c1dec add r1, sp, #7
 *   @0x2c1df0 mov r2, #1
 *   @0x2c1df4 blx r3
 *   @0x2c1df8 subs r0, r0, #1
 *   @0x2c1dfc movne r0, #1
 *   @0x2c1e00 cmp r0, #0
 *   @0x2c1e04 bne 0x2c1e40 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0x88>
 *   @0x2c1e08 ldrb r3, [sp, #0x7]
 *   @0x2c1e0c cmp r3, #44
 *   @0x2c1e10 beq 0x2c1e78 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0xc0>
 *   @0x2c1e14 cmp r3, #59
 *   @0x2c1e18 beq 0x2c1e58 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0xa0>
 *   @0x2c1e1c cmp r3, #33
 *   @0x2c1e20 beq 0x2c1e68 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0xb0>
 *   @0x2c1e24 mov r3, r0
 *   @0x2c1e28 str r0, [r5]
 *   @0x2c1e2c mov r2, #107
 *   @0x2c1e30 str r2, [r4, #0x40]
 *   @0x2c1e34 mov r0, r3
 *   @0x2c1e38 add sp, sp, #12
 *   @0x2c1e3c pop {r4, r5, pc}
 *   @0x2c1e40 mov r3, #0
 *   @0x2c1e44 mov r2, #102
 *   @0x2c1e48 mov r0, r3
 *   @0x2c1e4c str r2, [r4, #0x40]
 *   @0x2c1e50 add sp, sp, #12
 *   @0x2c1e54 pop {r4, r5, pc}
 *   @0x2c1e58 mov r2, #4
 *   @0x2c1e5c mov r3, #1
 *   @0x2c1e60 str r2, [r5]
 *   @0x2c1e64 b 0x2c1e34 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0x7c>
 *   @0x2c1e68 mov r2, #3
 *   @0x2c1e6c mov r3, #1
 *   @0x2c1e70 str r2, [r5]
 *   @0x2c1e74 b 0x2c1e34 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0x7c>
 *   @0x2c1e78 mov r2, #2
 *   @0x2c1e7c mov r3, #1
 *   @0x2c1e80 str r2, [r5]
 *   @0x2c1e84 b 0x2c1e34 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0x7c>
 *   @0x2c1e88 mov r1, #1
 *   @0x2c1e8c ldr r3, [r2, #0x38]
 *   @0x2c1e90 add r0, sp, #7
 *   @0x2c1e94 mov r2, r1
 *   @0x2c1e98 bl 0xb68c8 <fread@plt>
 *   @0x2c1e9c subs r0, r0, #1
 *   @0x2c1ea0 movne r0, #1
 *   @0x2c1ea4 b 0x2c1e00 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType+0x48>
 *
 * ══ §63/127 b2RopeJoint::Dump()  0x2d2534  size 240  60 条（0x2d2534..0x2d2624）
 * @func 0x2d2534 0x2d2624  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×7
 * 字段偏移 top8: 0x8×2 / 0x38×2 / 0x30×1 / 0x34×1 / 0xb4×1 / 0xa4×1 / 0x98×1 / 0x8c×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2534 push {r4, r5, r6, lr}
 *   @0x2d2538 mov r4, r0
 *   @0x2d253c ldr r2, [r4, #0x30]
 *   @0x2d2540 sub sp, sp, #8
 *   @0x2d2544 ldr r3, [r4, #0x34]
 *   @0x2d2548 ldr r0, [pc, #0xb4]
 *   @0x2d254c ldr r6, [r2, #0x8]
 *   @0x2d2550 add r0, pc, r0
 *   @0x2d2554 ldr r5, [r3, #0x8]
 *   @0x2d2558 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d255c ldr r0, [pc, #0xa4]
 *   @0x2d2560 mov r1, r6
 *   @0x2d2564 add r0, pc, r0
 *   @0x2d2568 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d256c ldr r0, [pc, #0x98]
 *   @0x2d2570 mov r1, r5
 *   @0x2d2574 add r0, pc, r0
 *   @0x2d2578 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d257c ldr r0, [pc, #0x8c]
 *   @0x2d2580 ldrb r1, [r4, #0x3d]
 *   @0x2d2584 add r0, pc, r0
 *   @0x2d2588 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d258c vldr s13, [r4, #68]
 *   @0x2d2590 vldr s14, [r4, #72]
 *   @0x2d2594 vcvt.f64.f32 d5, s13
 *   @0x2d2598 ldr r0, [pc, #0x74]
 *   @0x2d259c add r0, pc, r0
 *   @0x2d25a0 vcvt.f64.f32 d7, s14
 *   @0x2d25a4 vmov r2, r3, d5
 *   @0x2d25a8 vstr d7, [sp]
 *   @0x2d25ac bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d25b0 vldr s13, [r4, #76]
 *   @0x2d25b4 vldr s14, [r4, #80]
 *   @0x2d25b8 vcvt.f64.f32 d5, s13
 *   @0x2d25bc ldr r0, [pc, #0x54]
 *   @0x2d25c0 add r0, pc, r0
 *   @0x2d25c4 vcvt.f64.f32 d7, s14
 *   @0x2d25c8 vmov r2, r3, d5
 *   @0x2d25cc vstr d7, [sp]
 *   @0x2d25d0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d25d4 vldr s15, [r4, #84]
 *   @0x2d25d8 vcvt.f64.f32 d6, s15
 *   @0x2d25dc ldr r0, [pc, #0x38]
 *   @0x2d25e0 add r0, pc, r0
 *   @0x2d25e4 vmov r2, r3, d6
 *   @0x2d25e8 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d25ec ldr r0, [pc, #0x2c]
 *   @0x2d25f0 ldr r1, [r4, #0x38]
 *   @0x2d25f4 add r0, pc, r0
 *   @0x2d25f8 add sp, sp, #8
 *   @0x2d25fc pop {r4, r5, r6, lr}
 *   @0x2d2600 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d2604 strdeq r9, r10, [r8], -r4
 *   @0x2d2608 andeq r9, r8, r8, asr #18
 *   @0x2d260c andeq r9, r8, r4, asr r9
 *   @0x2d2610 andeq r9, r8, r0, ror #18
 *   @0x2d2614 andeq r9, r8, r12, ror #18
 *   @0x2d2618 andeq r9, r8, r4, ror r9
 *   @0x2d261c andeq r9, r8, r12, ror sp
 *   @0x2d2620 andeq r9, r8, r4, asr #19
 *
 * ══ §64/127 FT_Set_Default_Properties  0x2e9a40  size 240  60 条（0x2e9a40..0x2e9b30）
 * @func 0x2e9a40 0x2e9b30  size 240  60 条
 * 部分覆盖: 本节 60/111 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a24 / 0xb65d4
 * 字段偏移 top8: 0x1×3 / 0x-88×1 / 0x11c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9a40 push.w {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2e9a44 mov r8, r0
 *   @0x2e9a48 sub sp, #0x190
 *   @0x2e9a4c add r5, pc
 *   @0x2e9a50 add r0, pc
 *   @0x2e9a54 mov r9, r5
 *   @0x2e9a58 blx 0xb6a24 <getenv@plt>
 *   @0x2e9a5c mov r4, r0
 *   @0x2e9a60 beq 0x2e9b12 <FT_Set_Default_Properties+0xd2>
 *   @0x2e9a64 strbtmi r7, [pc], -r4, lsl #21
 *   @0x2e9a68 ldrb r3, [r4]
 *   @0x2e9a6c beq 0x2e9b12 <FT_Set_Default_Properties+0xd2>
 *   @0x2e9a70 beq 0x2e9b0e <FT_Set_Default_Properties+0xce>
 *   @0x2e9a74 beq 0x2e9b0e <FT_Set_Default_Properties+0xce>
 *   @0x2e9a78 movs r2, #0x0
 *   @0x2e9a7c ldrb r0, [r1], #1
 *   @0x2e9a80 cbz r0, 0x2e9a90 <FT_Set_Default_Properties+0x50>
 *   @0x2e9a84 beq 0x2e9a90 <FT_Set_Default_Properties+0x50>
 *   @0x2e9a88 adds r2, #0x1
 *   @0x2e9a8c mov r3, r1
 *   @0x2e9a90 movs r0, #0x0
 *   @0x2e9a94 ldrb r2, [r3]
 *   @0x2e9a98 bne 0x2e9b12 <FT_Set_Default_Properties+0xd2>
 *   @0x2e9a9c beq 0x2e9b12 <FT_Set_Default_Properties+0xd2>
 *   @0x2e9aa0 add r2, sp, #0x84
 *   @0x2e9aa4 mov r1, r6
 *   @0x2e9aa8 ldrb r0, [r1], #1
 *   @0x2e9aac cbz r0, 0x2e9abc <FT_Set_Default_Properties+0x7c>
 *   @0x2e9ab0 beq 0x2e9abc <FT_Set_Default_Properties+0x7c>
 *   @0x2e9ab4 adds r4, #0x1
 *   @0x2e9ab8 mov r3, r1
 *   @0x2e9abc movs r5, #0x0
 *   @0x2e9ac0 ldrb r1, [r3]
 *   @0x2e9ac4 bne 0x2e9b12 <FT_Set_Default_Properties+0xd2>
 *   @0x2e9ac8 beq 0x2e9b12 <FT_Set_Default_Properties+0xd2>
 *   @0x2e9acc mov r6, r3
 *   @0x2e9ad0 ldrb r1, [r6], #1
 *   @0x2e9ad4 tst.w r1, #0xdf
 *   @0x2e9ad8 beq 0x2e9aea <FT_Set_Default_Properties+0xaa>
 *   @0x2e9adc beq 0x2e9aea <FT_Set_Default_Properties+0xaa>
 *   @0x2e9ae0 strlo r1, [r1, #-0xa]
 *   @0x2e9ae4 cmp r5, #0x80
 *   @0x2e9ae8 bne 0x2e9ace <FT_Set_Default_Properties+0x8e>
 *   @0x2e9aec add r5, r1
 *   @0x2e9af0 strb r1, [r5, #-136]
 *   @0x2e9af4 ldrb r1, [r4]
 *   @0x2e9af8 ldrdle r0, r1, [r1], -pc
 *   @0x2e9afc cmp r1, #0x9
 *   @0x2e9b00 cmp r4, r3
 *   @0x2e9b04 mov r0, r8
 *   @0x2e9b08 mov r3, r10
 *   @0x2e9b0c strlo pc, [r1], #-2636
 *   @0x2e9b10 b 0x2e9a68 <FT_Set_Default_Properties+0x28>
 *   @0x2e9b14 ldr.w r3, [r9]
 *   @0x2e9b18 cmp r2, r3
 *   @0x2e9b1c blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2e9b20 add sp, #0x190
 *   @0x2e9b24 svclt #0x87f0
 *   @0x2e9b28 subs r7, #0x8
 *   @0x2e9b2c ldr r5, [pc, #0x11c]
 *
 * ══ §65/127 F_Vertex_ARGB_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xc7d8c  size 236  59 条（0xc7d8c..0xc7e78）
 * @func 0xc7d8c 0xc7e8c  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_Vertex_ARGB_release(RValue&, CInstance*, CInstance*, int, RValue*)+0xac / YYGetUint32(RValue const*, int) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×4 / 0x4×2 / 0x14×2 / 0x10×2 / 0xd4×1 / 0x20×1 / 0x2×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc7d8c push {r4, r5, r6, r7, lr}
 *   @0xc7d90 sub sp, sp, #12
 *   @0xc7d94 ldr r3, [pc, #0xd4]
 *   @0xc7d98 mov r1, #0
 *   @0xc7d9c ldr r6, [sp, #0x20]
 *   @0xc7da0 add r3, pc, r3
 *   @0xc7da4 mov r0, r6
 *   @0xc7da8 ldr r4, [r3]
 *   @0xc7dac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc7db0 ldr r4, [r4, r0, lsl #2]
 *   @0xc7db4 ldr r2, [r4, #0x2c]
 *   @0xc7db8 ldr r5, [r4, #0xc]
 *   @0xc7dbc ldr r3, [r4, #0x4]
 *   @0xc7dc0 ldr r2, [r2, #0x14]
 *   @0xc7dc4 add r1, r2, r5
 *   @0xc7dc8 cmp r3, r1
 *   @0xc7dcc blo 0xc7e38 <_Z21F_Vertex_ARGB_releaseR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xc7dd0 ldr r7, [r4]
 *   @0xc7dd4 mov r0, r6
 *   @0xc7dd8 mov r1, #1
 *   @0xc7ddc bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc7de0 bic r3, r0, #16711680
 *   @0xc7de4 ubfx r2, r0, #0x10, #0x8
 *   @0xc7de8 bic r3, r3, #255
 *   @0xc7dec uxtb r0, r0
 *   @0xc7df0 orr r3, r3, r2
 *   @0xc7df4 orr r3, r3, r0, lsl #16
 *   @0xc7df8 str r3, [r7, r5]
 *   @0xc7dfc ldr r3, [r4, #0x10]
 *   @0xc7e00 ldr r1, [r4, #0x14]
 *   @0xc7e04 add r3, r3, #1
 *   @0xc7e08 ldr r2, [r4, #0xc]
 *   @0xc7e0c cmp r3, r1
 *   @0xc7e10 str r3, [r4, #0x10]
 *   @0xc7e14 add r3, r2, #4
 *   @0xc7e18 str r3, [r4, #0xc]
 *   @0xc7e1c ldrhs r3, [r4, #0x1c]
 *   @0xc7e20 movhs r2, #0
 *   @0xc7e24 strhs r2, [r4, #0x10]
 *   @0xc7e28 addhs r3, r3, #1
 *   @0xc7e2c strhs r3, [r4, #0x1c]
 *   @0xc7e30 add sp, sp, #12
 *   @0xc7e34 pop {r4, r5, r6, r7, pc}
 *   @0xc7e38 add r2, r2, r3
 *   @0xc7e3c ldr r0, [r4]
 *   @0xc7e40 add r1, r2, r3, lsr #1
 *   @0xc7e44 mov r2, #0
 *   @0xc7e48 str r1, [r4, #0x4]
 *   @0xc7e4c mov r3, #74
 *   @0xc7e50 str r2, [sp]
 *   @0xc7e54 ldr r2, [pc, #0x18]
 *   @0xc7e58 add r2, pc, r2
 *   @0xc7e5c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc7e60 ldr r5, [r4, #0xc]
 *   @0xc7e64 mov r7, r0
 *   @0xc7e68 str r0, [r4]
 *   @0xc7e6c b 0xc7dd4 <_Z21F_Vertex_ARGB_releaseR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0xc7e70 mlaseq r11, r4, r3, r2
 *   @0xc7e74 .word 0x002691d8
 *
 * ══ §66/127 YYGML_vertex_position(int, float, float)  0xc96f8  size 236  59 条（0xc96f8..0xc97e4）
 * @func 0xc96f8 0xc97f8  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_vertex_position(int, float, float)+0xc4 / YYGML_vertex_position(int, float, float)+0x8c / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGML_vertex_position(int, float, float)+0x18
 * 字段偏移 top8: 0x4×4 / 0xc×3 / 0x14×2 / 0x10×2 / 0xc0×1 / 0x2×1 / 0x2c×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc96f8 cmp r0, #0
 *   @0xc96fc push {r4, r5, r6, lr}
 *   @0xc9700 mov r6, r1
 *   @0xc9704 sub sp, sp, #8
 *   @0xc9708 mov r5, r2
 *   @0xc970c blt 0xc97bc <_Z21YYGML_vertex_positioniff+0xc4>
 *   @0xc9710 ldr r3, [pc, #0xc0]
 *   @0xc9714 add r3, pc, r3
 *   @0xc9718 ldr r3, [r3]
 *   @0xc971c ldr r4, [r3, r0, lsl #2]
 *   @0xc9720 ldr r2, [r4, #0x2c]
 *   @0xc9724 ldr r3, [r4, #0xc]
 *   @0xc9728 ldr r12, [r4, #0x4]
 *   @0xc972c ldr r0, [r2, #0x14]
 *   @0xc9730 add r2, r0, r3
 *   @0xc9734 cmp r12, r2
 *   @0xc9738 blo 0xc9784 <_Z21YYGML_vertex_positioniff+0x8c>
 *   @0xc973c ldr r2, [r4]
 *   @0xc9740 ldr r1, [r4, #0x10]
 *   @0xc9744 add r0, r2, r3
 *   @0xc9748 ldr r2, [r4, #0x14]
 *   @0xc974c add r3, r3, #8
 *   @0xc9750 add r1, r1, #1
 *   @0xc9754 str r6, [r0]
 *   @0xc9758 cmp r1, r2
 *   @0xc975c str r5, [r0, #0x4]
 *   @0xc9760 str r3, [r4, #0xc]
 *   @0xc9764 ldrhs r3, [r4, #0x1c]
 *   @0xc9768 movhs r2, #0
 *   @0xc976c str r1, [r4, #0x10]
 *   @0xc9770 addhs r3, r3, #1
 *   @0xc9774 strhs r2, [r4, #0x10]
 *   @0xc9778 strhs r3, [r4, #0x1c]
 *   @0xc977c add sp, sp, #8
 *   @0xc9780 pop {r4, r5, r6, pc}
 *   @0xc9784 add r1, r0, r12
 *   @0xc9788 mov r2, #0
 *   @0xc978c ldr r0, [r4]
 *   @0xc9790 add r1, r1, r12, lsr #1
 *   @0xc9794 str r1, [r4, #0x4]
 *   @0xc9798 mov r3, #74
 *   @0xc979c str r2, [sp]
 *   @0xc97a0 ldr r2, [pc, #0x34]
 *   @0xc97a4 add r2, pc, r2
 *   @0xc97a8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc97ac ldr r3, [r4, #0xc]
 *   @0xc97b0 mov r2, r0
 *   @0xc97b4 str r0, [r4]
 *   @0xc97b8 b 0xc9740 <_Z21YYGML_vertex_positioniff+0x48>
 *   @0xc97bc ldr r3, [pc, #0x1c]
 *   @0xc97c0 add r3, pc, r3
 *   @0xc97c4 ldr r3, [r3, #0x4]
 *   @0xc97c8 cmp r0, r3
 *   @0xc97cc blt 0xc9710 <_Z21YYGML_vertex_positioniff+0x18>
 *   @0xc97d0 add sp, sp, #8
 *   @0xc97d4 pop {r4, r5, r6, pc}
 *   @0xc97d8 eorseq r0, r11, r0, lsr #20
 *   @0xc97dc eoreq r7, r6, r12, lsl #17
 *   @0xc97e0 eorseq r0, r11, r4, ror r9
 *
 * ══ §67/127 YYGML_vertex_texcoord(int, float, float)  0xc9b00  size 236  59 条（0xc9b00..0xc9bec）
 * @func 0xc9b00 0xc9c00  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_vertex_texcoord(int, float, float)+0xc4 / YYGML_vertex_texcoord(int, float, float)+0x8c / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGML_vertex_texcoord(int, float, float)+0x18
 * 字段偏移 top8: 0x4×4 / 0xc×3 / 0x14×2 / 0x10×2 / 0xc0×1 / 0x2×1 / 0x2c×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9b00 cmp r0, #0
 *   @0xc9b04 push {r4, r5, r6, lr}
 *   @0xc9b08 mov r6, r1
 *   @0xc9b0c sub sp, sp, #8
 *   @0xc9b10 mov r5, r2
 *   @0xc9b14 blt 0xc9bc4 <_Z21YYGML_vertex_texcoordiff+0xc4>
 *   @0xc9b18 ldr r3, [pc, #0xc0]
 *   @0xc9b1c add r3, pc, r3
 *   @0xc9b20 ldr r3, [r3]
 *   @0xc9b24 ldr r4, [r3, r0, lsl #2]
 *   @0xc9b28 ldr r2, [r4, #0x2c]
 *   @0xc9b2c ldr r3, [r4, #0xc]
 *   @0xc9b30 ldr r12, [r4, #0x4]
 *   @0xc9b34 ldr r0, [r2, #0x14]
 *   @0xc9b38 add r2, r0, r3
 *   @0xc9b3c cmp r12, r2
 *   @0xc9b40 blo 0xc9b8c <_Z21YYGML_vertex_texcoordiff+0x8c>
 *   @0xc9b44 ldr r2, [r4]
 *   @0xc9b48 ldr r1, [r4, #0x10]
 *   @0xc9b4c add r0, r2, r3
 *   @0xc9b50 ldr r2, [r4, #0x14]
 *   @0xc9b54 add r3, r3, #8
 *   @0xc9b58 add r1, r1, #1
 *   @0xc9b5c str r6, [r0]
 *   @0xc9b60 cmp r1, r2
 *   @0xc9b64 str r5, [r0, #0x4]
 *   @0xc9b68 str r3, [r4, #0xc]
 *   @0xc9b6c ldrhs r3, [r4, #0x1c]
 *   @0xc9b70 movhs r2, #0
 *   @0xc9b74 str r1, [r4, #0x10]
 *   @0xc9b78 addhs r3, r3, #1
 *   @0xc9b7c strhs r2, [r4, #0x10]
 *   @0xc9b80 strhs r3, [r4, #0x1c]
 *   @0xc9b84 add sp, sp, #8
 *   @0xc9b88 pop {r4, r5, r6, pc}
 *   @0xc9b8c add r1, r0, r12
 *   @0xc9b90 mov r2, #0
 *   @0xc9b94 ldr r0, [r4]
 *   @0xc9b98 add r1, r1, r12, lsr #1
 *   @0xc9b9c str r1, [r4, #0x4]
 *   @0xc9ba0 mov r3, #74
 *   @0xc9ba4 str r2, [sp]
 *   @0xc9ba8 ldr r2, [pc, #0x34]
 *   @0xc9bac add r2, pc, r2
 *   @0xc9bb0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc9bb4 ldr r3, [r4, #0xc]
 *   @0xc9bb8 mov r2, r0
 *   @0xc9bbc str r0, [r4]
 *   @0xc9bc0 b 0xc9b48 <_Z21YYGML_vertex_texcoordiff+0x48>
 *   @0xc9bc4 ldr r3, [pc, #0x1c]
 *   @0xc9bc8 add r3, pc, r3
 *   @0xc9bcc ldr r3, [r3, #0x4]
 *   @0xc9bd0 cmp r0, r3
 *   @0xc9bd4 blt 0xc9b18 <_Z21YYGML_vertex_texcoordiff+0x18>
 *   @0xc9bd8 add sp, sp, #8
 *   @0xc9bdc pop {r4, r5, r6, pc}
 *   @0xc9be0 eorseq r0, r11, r8, lsl r6
 *   @0xc9be4 eoreq r7, r6, r4, lsl #9
 *   @0xc9be8 eorseq r0, r11, r12, ror #10
 *
 * ══ §68/127 YYGML_vertex_float2(int, float, float)  0xc9dc4  size 236  59 条（0xc9dc4..0xc9eb0）
 * @func 0xc9dc4 0xc9ec4  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_vertex_float2(int, float, float)+0xc4 / YYGML_vertex_float2(int, float, float)+0x8c / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGML_vertex_float2(int, float, float)+0x18
 * 字段偏移 top8: 0x4×4 / 0xc×3 / 0x14×2 / 0x10×2 / 0xc0×1 / 0x2×1 / 0x2c×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9dc4 cmp r0, #0
 *   @0xc9dc8 push {r4, r5, r6, lr}
 *   @0xc9dcc mov r6, r1
 *   @0xc9dd0 sub sp, sp, #8
 *   @0xc9dd4 mov r5, r2
 *   @0xc9dd8 blt 0xc9e88 <_Z19YYGML_vertex_float2iff+0xc4>
 *   @0xc9ddc ldr r3, [pc, #0xc0]
 *   @0xc9de0 add r3, pc, r3
 *   @0xc9de4 ldr r3, [r3]
 *   @0xc9de8 ldr r4, [r3, r0, lsl #2]
 *   @0xc9dec ldr r2, [r4, #0x2c]
 *   @0xc9df0 ldr r3, [r4, #0xc]
 *   @0xc9df4 ldr r12, [r4, #0x4]
 *   @0xc9df8 ldr r0, [r2, #0x14]
 *   @0xc9dfc add r2, r0, r3
 *   @0xc9e00 cmp r12, r2
 *   @0xc9e04 blo 0xc9e50 <_Z19YYGML_vertex_float2iff+0x8c>
 *   @0xc9e08 ldr r2, [r4]
 *   @0xc9e0c ldr r1, [r4, #0x10]
 *   @0xc9e10 add r0, r2, r3
 *   @0xc9e14 ldr r2, [r4, #0x14]
 *   @0xc9e18 add r3, r3, #8
 *   @0xc9e1c add r1, r1, #1
 *   @0xc9e20 str r6, [r0]
 *   @0xc9e24 cmp r1, r2
 *   @0xc9e28 str r5, [r0, #0x4]
 *   @0xc9e2c str r3, [r4, #0xc]
 *   @0xc9e30 ldrhs r3, [r4, #0x1c]
 *   @0xc9e34 movhs r2, #0
 *   @0xc9e38 str r1, [r4, #0x10]
 *   @0xc9e3c addhs r3, r3, #1
 *   @0xc9e40 strhs r2, [r4, #0x10]
 *   @0xc9e44 strhs r3, [r4, #0x1c]
 *   @0xc9e48 add sp, sp, #8
 *   @0xc9e4c pop {r4, r5, r6, pc}
 *   @0xc9e50 add r1, r0, r12
 *   @0xc9e54 mov r2, #0
 *   @0xc9e58 ldr r0, [r4]
 *   @0xc9e5c add r1, r1, r12, lsr #1
 *   @0xc9e60 str r1, [r4, #0x4]
 *   @0xc9e64 mov r3, #74
 *   @0xc9e68 str r2, [sp]
 *   @0xc9e6c ldr r2, [pc, #0x34]
 *   @0xc9e70 add r2, pc, r2
 *   @0xc9e74 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc9e78 ldr r3, [r4, #0xc]
 *   @0xc9e7c mov r2, r0
 *   @0xc9e80 str r0, [r4]
 *   @0xc9e84 b 0xc9e0c <_Z19YYGML_vertex_float2iff+0x48>
 *   @0xc9e88 ldr r3, [pc, #0x1c]
 *   @0xc9e8c add r3, pc, r3
 *   @0xc9e90 ldr r3, [r3, #0x4]
 *   @0xc9e94 cmp r0, r3
 *   @0xc9e98 blt 0xc9ddc <_Z19YYGML_vertex_float2iff+0x18>
 *   @0xc9e9c add sp, sp, #8
 *   @0xc9ea0 pop {r4, r5, r6, pc}
 *   @0xc9ea4 eorseq r0, r11, r4, asr r3
 *   @0xc9ea8 eoreq r7, r6, r0, asr #3
 *   @0xc9eac eorseq r0, r11, r8, lsr #5
 *
 * ══ §69/127 Function_Add(char const*, void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)  0xcdf84  size 236  59 条（0xcdf84..0xce070）
 * @func 0xcdf84 0xce070  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xcdf90→0x47a148, 0xcdfc0→0x47a14c, 0xce028→0x47a14c
 * 调用序列: 0xb6538 / 0xb65bc / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0xd0×1 / 0xc8×1 / 0xc4×1 / 0xa0×1 / 0x40×1 / 0x44×1 / 0x48×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcdf84 ldr r12, [pc, #0xd0]
 *   @0xcdf88 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xcdf8c add r12, pc, r12
 *   @0xcdf90 ldr lr, [pc, #0xc8]
 *   @0xcdf94 mov r10, r0
 *   @0xcdf98 ldr r0, [pc, #0xc4]
 *   @0xcdf9c mov r7, r3
 *   @0xcdfa0 mov r9, r1
 *   @0xcdfa4 mov r8, r2
 *   @0xcdfa8 ldr r4, [r12, lr]
 *   @0xcdfac add r0, pc, r0
 *   @0xcdfb0 ldr r3, [r0]
 *   @0xcdfb4 ldr r5, [r4]
 *   @0xcdfb8 cmp r5, r3
 *   @0xcdfbc bge 0xce028 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib+0xa4>
 *   @0xcdfc0 ldr r3, [pc, #0xa0]
 *   @0xcdfc4 ldr r6, [r12, r3]
 *   @0xcdfc8 mov r0, r10
 *   @0xcdfcc add r5, r5, #1
 *   @0xcdfd0 str r5, [r4]
 *   @0xcdfd4 bl 0xb6538 <strlen@plt>
 *   @0xcdfd8 add r5, r5, r5, lsl #2
 *   @0xcdfdc ldr r3, [r6]
 *   @0xcdfe0 mov r1, r10
 *   @0xcdfe4 lsl r5, r5, #4
 *   @0xcdfe8 sub r5, r5, #80
 *   @0xcdfec add r2, r0, #1
 *   @0xcdff0 add r0, r3, r5
 *   @0xcdff4 bl 0xb65bc <memcpy@plt>
 *   @0xcdff8 ldr r3, [r4]
 *   @0xcdffc ldr r0, [r6]
 *   @0xce000 mvn r2, #0
 *   @0xce004 add r3, r3, r3, lsl #2
 *   @0xce008 lsl r3, r3, #4
 *   @0xce00c sub r3, r3, #80
 *   @0xce010 add r0, r0, r3
 *   @0xce014 str r9, [r0, #0x40]
 *   @0xce018 str r8, [r0, #0x44]
 *   @0xce01c strb r7, [r0, #0x48]
 *   @0xce020 str r2, [r0, #0x4c]
 *   @0xce024 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xce028 ldr lr, [pc, #0x38]
 *   @0xce02c add r1, r3, #500
 *   @0xce030 str r1, [r0]
 *   @0xce034 mov r3, #71
 *   @0xce038 add r1, r1, r1, lsl #2
 *   @0xce03c ldr r2, [pc, #0x28]
 *   @0xce040 ldr r6, [r12, lr]
 *   @0xce044 add r2, pc, r2
 *   @0xce048 lsl r1, r1, #4
 *   @0xce04c mov r0, r6
 *   @0xce050 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xce054 ldr r5, [r4]
 *   @0xce058 b 0xcdfc8 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib+0x44>
 *   @0xce05c eorseq r3, r2, r4, asr #25
 *   @0xce060 .word 0xffffbec4
 *   @0xce064 mlaseq r10, r0, r1, r12
 *   @0xce068 .word 0xffffbec8
 *   @0xce06c eoreq r4, r6, r0, ror r1
 *
 * ══ §70/127 FindDist(CInstance*, CInstance*)  0x10ac9c  size 236  59 条（0x10ac9c..0x10ad88）
 * @func 0x10ac9c 0x10ad88  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::Compute_BoundingBox(bool)×2 / 0xb6700
 * 字段偏移 top8: 0x64×2 / 0xf0×2 / 0xe8×2 / 0xf4×2 / 0xec×2 / 0x68×1 / 0x69×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ac9c cmp r0, #0
 *   @0x10aca0 cmpne r0, r1
 *   @0x10aca4 push {r3, r4, r5, lr}
 *   @0x10aca8 mov r5, r1
 *   @0x10acac mov r4, r0
 *   @0x10acb0 beq 0x10acc0 <_Z8FindDistP9CInstanceS0_+0x24>
 *   @0x10acb4 ldrb r3, [r0, #0x68]
 *   @0x10acb8 cmp r3, #0
 *   @0x10acbc beq 0x10accc <_Z8FindDistP9CInstanceS0_+0x30>
 *   @0x10acc0 mov r0, #9216
 *   @0x10acc4 movt r0, #0x4974
 *   @0x10acc8 pop {r3, r4, r5, pc}
 *   @0x10accc ldrb r3, [r0, #0x69]
 *   @0x10acd0 cmp r3, #0
 *   @0x10acd4 bne 0x10acc0 <_Z8FindDistP9CInstanceS0_+0x24>
 *   @0x10acd8 ldrb r3, [r0, #0x64]
 *   @0x10acdc cmp r3, #0
 *   @0x10ace0 beq 0x10acec <_Z8FindDistP9CInstanceS0_+0x50>
 *   @0x10ace4 mov r1, #1
 *   @0x10ace8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x10acec ldrb r3, [r5, #0x64]
 *   @0x10acf0 cmp r3, #0
 *   @0x10acf4 bne 0x10ad68 <_Z8FindDistP9CInstanceS0_+0xcc>
 *   @0x10acf8 ldr r3, [r5, #0xf0]
 *   @0x10acfc ldr r2, [r4, #0xe8]
 *   @0x10ad00 ldr r1, [r4, #0xf0]
 *   @0x10ad04 cmp r2, r3
 *   @0x10ad08 ldr r0, [r4, #0xf4]
 *   @0x10ad0c rsbgt r3, r3, r2
 *   @0x10ad10 ldr r2, [r5, #0xe8]
 *   @0x10ad14 movle r3, #0
 *   @0x10ad18 cmp r1, r2
 *   @0x10ad1c rsblt r3, r2, r1
 *   @0x10ad20 ldr r2, [r5, #0xf4]
 *   @0x10ad24 ldr r1, [r4, #0xec]
 *   @0x10ad28 cmp r1, r2
 *   @0x10ad2c rsbgt r2, r2, r1
 *   @0x10ad30 ldr r1, [r5, #0xec]
 *   @0x10ad34 movle r2, #0
 *   @0x10ad38 cmp r0, r1
 *   @0x10ad3c rsblt r2, r1, r0
 *   @0x10ad40 mul r2, r2, r2
 *   @0x10ad44 mla r3, r3, r3, r2
 *   @0x10ad48 vmov s15, r3
 *   @0x10ad4c vcvt.f32.s32 s14, s15
 *   @0x10ad50 vsqrt.f32 s15, s14
 *   @0x10ad54 vcmp.f32 s15, s15
 *   @0x10ad58 vmrs APSR_nzcv, fpscr
 *   @0x10ad5c bne 0x10ad78 <_Z8FindDistP9CInstanceS0_+0xdc>
 *   @0x10ad60 vmov r0, s15
 *   @0x10ad64 pop {r3, r4, r5, pc}
 *   @0x10ad68 mov r0, r5
 *   @0x10ad6c mov r1, #1
 *   @0x10ad70 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x10ad74 b 0x10acf8 <_Z8FindDistP9CInstanceS0_+0x5c>
 *   @0x10ad78 vmov r0, s14
 *   @0x10ad7c bl 0xb6700 <sqrtf@plt>
 *   @0x10ad80 vmov s15, r0
 *   @0x10ad84 b 0x10ad60 <_Z8FindDistP9CInstanceS0_+0xc4>
 *
 * ══ §71/127 F_DrawTriangleExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b7a8  size 236  59 条（0x11b7a8..0x11b894）
 * @func 0x11b7a8 0x11b894  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / YYGetInt32(RValue const*, int)×3 / YYGetBool(RValue const*, int) / GR_Draw_Triangle_Ext(float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, bool)
 * 字段偏移 top8: 0x18×2 / 0x1c×2 / 0x48×1 / 0x8×1 / 0x4×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b7a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11b7ac sub sp, sp, #36
 *   @0x11b7b0 mov r1, #0
 *   @0x11b7b4 ldr r4, [sp, #0x48]
 *   @0x11b7b8 mov r0, r4
 *   @0x11b7bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b7c0 mov r1, #1
 *   @0x11b7c4 mov r5, r0
 *   @0x11b7c8 mov r0, r4
 *   @0x11b7cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b7d0 mov r1, #2
 *   @0x11b7d4 mov r8, r0
 *   @0x11b7d8 mov r0, r4
 *   @0x11b7dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b7e0 mov r1, #3
 *   @0x11b7e4 mov r7, r0
 *   @0x11b7e8 mov r0, r4
 *   @0x11b7ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b7f0 mov r1, #4
 *   @0x11b7f4 mov r6, r0
 *   @0x11b7f8 mov r0, r4
 *   @0x11b7fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b800 mov r1, #5
 *   @0x11b804 mov r2, r0
 *   @0x11b808 mov r0, r4
 *   @0x11b80c str r2, [sp, #0x18]
 *   @0x11b810 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b814 mov r1, #6
 *   @0x11b818 mov r3, r0
 *   @0x11b81c mov r0, r4
 *   @0x11b820 str r3, [sp, #0x1c]
 *   @0x11b824 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b828 mov r1, #7
 *   @0x11b82c mov r11, r0
 *   @0x11b830 mov r0, r4
 *   @0x11b834 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b838 mov r1, #8
 *   @0x11b83c mov r10, r0
 *   @0x11b840 mov r0, r4
 *   @0x11b844 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b848 mov r1, #9
 *   @0x11b84c mov r9, r0
 *   @0x11b850 mov r0, r4
 *   @0x11b854 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11b858 ldr r2, [sp, #0x18]
 *   @0x11b85c ldr r3, [sp, #0x1c]
 *   @0x11b860 mov r1, r8
 *   @0x11b864 str r11, [sp, #0x8]
 *   @0x11b868 str r2, [sp]
 *   @0x11b86c mov r2, r7
 *   @0x11b870 str r3, [sp, #0x4]
 *   @0x11b874 mov r3, r6
 *   @0x11b878 str r10, [sp, #0xc]
 *   @0x11b87c str r9, [sp, #0x10]
 *   @0x11b880 str r0, [sp, #0x14]
 *   @0x11b884 mov r0, r5
 *   @0x11b888 bl 0x16a85c <_Z20GR_Draw_Triangle_Extffffffjjjb>
 *   @0x11b88c add sp, sp, #36
 *   @0x11b890 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §72/127 F_TileSetRegion(RValue&, CInstance*, CInstance*, int, RValue*)  0x12060c  size 236  59 条（0x12060c..0x1206f8）
 * @func 0x12060c 0x1206f8  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / CRoom::FindTile(int) / F_TileSetRegion(RValue&, CInstance*, CInstance*, int, RValue*)+0xd0
 * 字段偏移 top8: 0x18×2 / 0xb8×2 / 0x10×2 / 0xd0×1 / 0xc×1 / 0x14×1 / 0xc0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12060c push {r3, r4, r5, r6, r7, lr}
 *   @0x120610 mov r1, #0
 *   @0x120614 ldr r6, [sp, #0x18]
 *   @0x120618 ldr r5, [pc, #0xd0]
 *   @0x12061c ldr r5, [pc, r5]
 *   @0x120620 mov r0, r6
 *   @0x120624 ldr r4, [r5]
 *   @0x120628 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12062c mov r1, r0
 *   @0x120630 mov r0, r4
 *   @0x120634 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x120638 subs r7, r0, #0
 *   @0x12063c blt 0x1206dc <_Z15F_TileSetRegionR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x120640 ldr r3, [r5]
 *   @0x120644 mov r1, #1
 *   @0x120648 mov r0, r6
 *   @0x12064c ldr r2, [r3, #0xb8]
 *   @0x120650 cmp r7, r2
 *   @0x120654 rsblt r4, r7, r7, lsl #3
 *   @0x120658 ldrlt r3, [r3, #0xc0]
 *   @0x12065c movge r4, #0
 *   @0x120660 addlt r4, r3, r4, lsl #3
 *   @0x120664 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120668 mov r1, #2
 *   @0x12066c str r0, [r4, #0xc]
 *   @0x120670 mov r0, r6
 *   @0x120674 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120678 mov r1, #3
 *   @0x12067c str r0, [r4, #0x10]
 *   @0x120680 mov r0, r6
 *   @0x120684 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120688 mov r1, #4
 *   @0x12068c str r0, [r4, #0x14]
 *   @0x120690 mov r0, r6
 *   @0x120694 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120698 ldr r3, [r5]
 *   @0x12069c ldr r2, [r3, #0xb8]
 *   @0x1206a0 cmp r7, r2
 *   @0x1206a4 str r0, [r4, #0x18]
 *   @0x1206a8 popge {r3, r4, r5, r6, r7, pc}
 *   @0x1206ac ldr r5, [r3, #0xc0]
 *   @0x1206b0 rsb r7, r7, r7, lsl #3
 *   @0x1206b4 ldm r4!, {r0, r1, r2, r3}
 *   @0x1206b8 add r12, r5, r7, lsl #3
 *   @0x1206bc stm r12!, {r0, r1, r2, r3}
 *   @0x1206c0 ldm r4!, {r0, r1, r2, r3}
 *   @0x1206c4 stm r12!, {r0, r1, r2, r3}
 *   @0x1206c8 ldm r4!, {r0, r1, r2, r3}
 *   @0x1206cc stm r12!, {r0, r1, r2, r3}
 *   @0x1206d0 ldm r4, {r0, r1}
 *   @0x1206d4 stm r12, {r0, r1}
 *   @0x1206d8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1206dc ldr r0, [pc, #0x10]
 *   @0x1206e0 mov r1, #0
 *   @0x1206e4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1206e8 add r0, pc, r0
 *   @0x1206ec b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1206f0 eoreq sp, r12, r12, lsl #6
 *   @0x1206f4 eoreq r9, r1, r4, lsl r11
 *
 * ══ §73/127 F_IniReadString(RValue&, CInstance*, CInstance*, int, RValue*)  0x13a0e4  size 236  59 条（0x13a0e4..0x13a1d0）
 * @func 0x13a0e4 0x13a1d0  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / YYCreateString(RValue*, char const*)×2 / IniFile::GetKey(char const*, char const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / YYFree(void const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x8×4 / 0xd0×1 / 0x28×1 / 0x70×1 / 0x4×1 / 0x-4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13a0e4 push {r4, r5, r6, r7, lr}
 *   @0x13a0e8 sub sp, sp, #20
 *   @0x13a0ec ldr r4, [pc, #0xd0]
 *   @0x13a0f0 mov r6, r0
 *   @0x13a0f4 ldr r5, [sp, #0x28]
 *   @0x13a0f8 ldr r4, [pc, r4]
 *   @0x13a0fc ldr r1, [r4]
 *   @0x13a100 cmp r1, #0
 *   @0x13a104 beq 0x13a1b0 <_Z15F_IniReadStringR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x13a108 mov r1, #0
 *   @0x13a10c mov r0, r5
 *   @0x13a110 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a114 mov r1, #1
 *   @0x13a118 mov r7, r0
 *   @0x13a11c mov r0, r5
 *   @0x13a120 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a124 mov r1, r7
 *   @0x13a128 mov r2, r0
 *   @0x13a12c ldr r0, [r4]
 *   @0x13a130 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x13a134 subs r4, r0, #0
 *   @0x13a138 beq 0x13a150 <_Z15F_IniReadStringR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x13a13c mov r0, r6
 *   @0x13a140 ldr r1, [r4, #0x8]
 *   @0x13a144 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x13a148 add sp, sp, #20
 *   @0x13a14c pop {r4, r5, r6, r7, pc}
 *   @0x13a150 ldr r1, [pc, #0x70]
 *   @0x13a154 mov r12, #16
 *   @0x13a158 mov r0, r12
 *   @0x13a15c movw r2, #0x7bf
 *   @0x13a160 add r1, pc, r1
 *   @0x13a164 mov r3, #1
 *   @0x13a168 str r12, [sp, #0x4]
 *   @0x13a16c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13a170 add r2, sp, #16
 *   @0x13a174 add r3, r5, #32
 *   @0x13a178 add r1, sp, #8
 *   @0x13a17c str r0, [sp, #0x8]
 *   @0x13a180 str r0, [r2, #-0x4]!
 *   @0x13a184 strb r4, [r0]
 *   @0x13a188 mov r0, r2
 *   @0x13a18c add r2, sp, #4
 *   @0x13a190 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x13a194 mov r0, r6
 *   @0x13a198 ldr r1, [sp, #0x8]
 *   @0x13a19c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x13a1a0 ldr r0, [sp, #0x8]
 *   @0x13a1a4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x13a1a8 add sp, sp, #20
 *   @0x13a1ac pop {r4, r5, r6, r7, pc}
 *   @0x13a1b0 ldr r0, [pc, #0x14]
 *   @0x13a1b4 add r0, pc, r0
 *   @0x13a1b8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13a1bc add sp, sp, #20
 *   @0x13a1c0 pop {r4, r5, r6, r7, pc}
 *   @0x13a1c4 mlaeq r11, r12, r1, r5
 *   @0x13a1c8 .word 0x00205ef0
 *   @0x13a1cc strhteq r6, [r0], -r4
 *
 * ══ §74/127 F_D3DVertexNormalTextureColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x144048  size 236  59 条（0x144048..0x144134）
 * @func 0x144048 0x144134  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×9 / YYGetInt32(RValue const*, int) / GR_3D_Vertex_N_Texture_Color(float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x18×2 / 0x1c×2 / 0x48×1 / 0x8×1 / 0x4×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144048 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14404c sub sp, sp, #36
 *   @0x144050 mov r1, #0
 *   @0x144054 ldr r4, [sp, #0x48]
 *   @0x144058 mov r0, r4
 *   @0x14405c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144060 mov r1, #1
 *   @0x144064 mov r5, r0
 *   @0x144068 mov r0, r4
 *   @0x14406c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144070 mov r1, #2
 *   @0x144074 mov r8, r0
 *   @0x144078 mov r0, r4
 *   @0x14407c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144080 mov r1, #3
 *   @0x144084 mov r7, r0
 *   @0x144088 mov r0, r4
 *   @0x14408c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144090 mov r1, #4
 *   @0x144094 mov r6, r0
 *   @0x144098 mov r0, r4
 *   @0x14409c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1440a0 mov r1, #5
 *   @0x1440a4 mov r2, r0
 *   @0x1440a8 mov r0, r4
 *   @0x1440ac str r2, [sp, #0x18]
 *   @0x1440b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1440b4 mov r1, #6
 *   @0x1440b8 mov r3, r0
 *   @0x1440bc mov r0, r4
 *   @0x1440c0 str r3, [sp, #0x1c]
 *   @0x1440c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1440c8 mov r1, #7
 *   @0x1440cc mov r11, r0
 *   @0x1440d0 mov r0, r4
 *   @0x1440d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1440d8 mov r1, #8
 *   @0x1440dc mov r10, r0
 *   @0x1440e0 mov r0, r4
 *   @0x1440e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1440e8 mov r1, #9
 *   @0x1440ec mov r9, r0
 *   @0x1440f0 mov r0, r4
 *   @0x1440f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1440f8 ldr r2, [sp, #0x18]
 *   @0x1440fc ldr r3, [sp, #0x1c]
 *   @0x144100 mov r1, r8
 *   @0x144104 str r11, [sp, #0x8]
 *   @0x144108 str r2, [sp]
 *   @0x14410c mov r2, r7
 *   @0x144110 str r3, [sp, #0x4]
 *   @0x144114 mov r3, r6
 *   @0x144118 str r10, [sp, #0xc]
 *   @0x14411c str r9, [sp, #0x10]
 *   @0x144120 str r0, [sp, #0x14]
 *   @0x144124 mov r0, r5
 *   @0x144128 bl 0x1774e4 <_Z28GR_3D_Vertex_N_Texture_Colorffffffffjf>
 *   @0x14412c add sp, sp, #36
 *   @0x144130 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §75/127 F_D3DDrawEllipsoid(RValue&, CInstance*, CInstance*, int, RValue*)  0x144414  size 236  59 条（0x144414..0x144500）
 * @func 0x144414 0x144500  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetPtrOrInt(RValue const*, int) / YYGetInt32(RValue const*, int) / GR_3D_Draw_Ellipsoid(float, float, float, float, float, float, int, float, float, int)
 * 字段偏移 top8: 0x18×2 / 0x1c×2 / 0x48×1 / 0x8×1 / 0x4×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144414 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x144418 sub sp, sp, #36
 *   @0x14441c mov r1, #0
 *   @0x144420 ldr r4, [sp, #0x48]
 *   @0x144424 mov r0, r4
 *   @0x144428 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14442c mov r1, #1
 *   @0x144430 mov r5, r0
 *   @0x144434 mov r0, r4
 *   @0x144438 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14443c mov r1, #2
 *   @0x144440 mov r8, r0
 *   @0x144444 mov r0, r4
 *   @0x144448 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14444c mov r1, #3
 *   @0x144450 mov r7, r0
 *   @0x144454 mov r0, r4
 *   @0x144458 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14445c mov r1, #4
 *   @0x144460 mov r6, r0
 *   @0x144464 mov r0, r4
 *   @0x144468 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14446c mov r1, #5
 *   @0x144470 mov r2, r0
 *   @0x144474 mov r0, r4
 *   @0x144478 str r2, [sp, #0x18]
 *   @0x14447c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144480 mov r1, #6
 *   @0x144484 mov r3, r0
 *   @0x144488 mov r0, r4
 *   @0x14448c str r3, [sp, #0x1c]
 *   @0x144490 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x144494 mov r1, #7
 *   @0x144498 mov r11, r0
 *   @0x14449c mov r0, r4
 *   @0x1444a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1444a4 mov r1, #8
 *   @0x1444a8 mov r10, r0
 *   @0x1444ac mov r0, r4
 *   @0x1444b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1444b4 mov r1, #9
 *   @0x1444b8 mov r9, r0
 *   @0x1444bc mov r0, r4
 *   @0x1444c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1444c4 ldr r2, [sp, #0x18]
 *   @0x1444c8 ldr r3, [sp, #0x1c]
 *   @0x1444cc mov r1, r8
 *   @0x1444d0 str r11, [sp, #0x8]
 *   @0x1444d4 str r2, [sp]
 *   @0x1444d8 mov r2, r7
 *   @0x1444dc str r3, [sp, #0x4]
 *   @0x1444e0 mov r3, r6
 *   @0x1444e4 str r10, [sp, #0xc]
 *   @0x1444e8 str r9, [sp, #0x10]
 *   @0x1444ec str r0, [sp, #0x14]
 *   @0x1444f0 mov r0, r5
 *   @0x1444f4 bl 0x17934c <_Z20GR_3D_Draw_Ellipsoidffffffiffi>
 *   @0x1444f8 add sp, sp, #36
 *   @0x1444fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §76/127 F_D3DModelEllipsoid(RValue&, CInstance*, CInstance*, int, RValue*)  0x145d4c  size 236  59 条（0x145d4c..0x145e38）
 * @func 0x145d4c 0x145e38  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetInt32(RValue const*, int)×2 / GR_3DM_Ellipsoid(int, float, float, float, float, float, float, float, float, int)
 * 字段偏移 top8: 0x18×2 / 0x1c×2 / 0x48×1 / 0x8×1 / 0x4×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145d4c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x145d50 sub sp, sp, #36
 *   @0x145d54 mov r1, #0
 *   @0x145d58 ldr r4, [sp, #0x48]
 *   @0x145d5c mov r0, r4
 *   @0x145d60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145d64 mov r1, #1
 *   @0x145d68 mov r5, r0
 *   @0x145d6c mov r0, r4
 *   @0x145d70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145d74 mov r1, #2
 *   @0x145d78 mov r8, r0
 *   @0x145d7c mov r0, r4
 *   @0x145d80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145d84 mov r1, #3
 *   @0x145d88 mov r7, r0
 *   @0x145d8c mov r0, r4
 *   @0x145d90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145d94 mov r1, #4
 *   @0x145d98 mov r6, r0
 *   @0x145d9c mov r0, r4
 *   @0x145da0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145da4 mov r1, #5
 *   @0x145da8 mov r2, r0
 *   @0x145dac mov r0, r4
 *   @0x145db0 str r2, [sp, #0x18]
 *   @0x145db4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145db8 mov r1, #6
 *   @0x145dbc mov r3, r0
 *   @0x145dc0 mov r0, r4
 *   @0x145dc4 str r3, [sp, #0x1c]
 *   @0x145dc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145dcc mov r1, #7
 *   @0x145dd0 mov r11, r0
 *   @0x145dd4 mov r0, r4
 *   @0x145dd8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145ddc mov r1, #8
 *   @0x145de0 mov r10, r0
 *   @0x145de4 mov r0, r4
 *   @0x145de8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145dec mov r1, #9
 *   @0x145df0 mov r9, r0
 *   @0x145df4 mov r0, r4
 *   @0x145df8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145dfc ldr r2, [sp, #0x18]
 *   @0x145e00 ldr r3, [sp, #0x1c]
 *   @0x145e04 mov r1, r8
 *   @0x145e08 str r11, [sp, #0x8]
 *   @0x145e0c str r2, [sp]
 *   @0x145e10 mov r2, r7
 *   @0x145e14 str r3, [sp, #0x4]
 *   @0x145e18 mov r3, r6
 *   @0x145e1c str r10, [sp, #0xc]
 *   @0x145e20 str r9, [sp, #0x10]
 *   @0x145e24 str r0, [sp, #0x14]
 *   @0x145e28 mov r0, r5
 *   @0x145e2c bl 0x165b1c <_Z16GR_3DM_Ellipsoidiffffffffi>
 *   @0x145e30 add sp, sp, #36
 *   @0x145e34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §77/127 InitYoYoBuiltInVariables()  0x15dafc  size 236  59 条（0x15dafc..0x15dbe8）
 * @func 0x15dafc 0x15dbe8  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Variable_BuiltIn_Add(char const*, bool (*)(CInstance*, int, RValue*), bool (*)(CInstance*, int, RValue*), bool)×5
 * 字段偏移 top8: 0x94×2 / 0x80×2 / 0x6c×2 / 0x58×2 / 0x44×2 / 0xa8×1 / 0xa4×1 / 0xa0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15dafc push {r4, lr}
 *   @0x15db00 mov r2, #0
 *   @0x15db04 ldr r4, [pc, #0xa8]
 *   @0x15db08 mov r3, r2
 *   @0x15db0c ldr r1, [pc, #0xa4]
 *   @0x15db10 add r4, pc, r4
 *   @0x15db14 ldr r0, [pc, #0xa0]
 *   @0x15db18 ldr r1, [r4, r1]
 *   @0x15db1c add r0, pc, r0
 *   @0x15db20 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x15db24 ldr r1, [pc, #0x94]
 *   @0x15db28 ldr r0, [pc, #0x94]
 *   @0x15db2c mov r2, #0
 *   @0x15db30 mov r3, r2
 *   @0x15db34 ldr r1, [r4, r1]
 *   @0x15db38 add r0, pc, r0
 *   @0x15db3c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x15db40 ldr r1, [pc, #0x80]
 *   @0x15db44 ldr r0, [pc, #0x80]
 *   @0x15db48 mov r2, #0
 *   @0x15db4c mov r3, r2
 *   @0x15db50 ldr r1, [r4, r1]
 *   @0x15db54 add r0, pc, r0
 *   @0x15db58 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x15db5c ldr r1, [pc, #0x6c]
 *   @0x15db60 ldr r0, [pc, #0x6c]
 *   @0x15db64 mov r2, #0
 *   @0x15db68 mov r3, r2
 *   @0x15db6c ldr r1, [r4, r1]
 *   @0x15db70 add r0, pc, r0
 *   @0x15db74 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x15db78 ldr r1, [pc, #0x58]
 *   @0x15db7c ldr r0, [pc, #0x58]
 *   @0x15db80 mov r2, #0
 *   @0x15db84 mov r3, r2
 *   @0x15db88 ldr r1, [r4, r1]
 *   @0x15db8c add r0, pc, r0
 *   @0x15db90 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x15db94 ldr r1, [pc, #0x44]
 *   @0x15db98 ldr r0, [pc, #0x44]
 *   @0x15db9c mov r2, #0
 *   @0x15dba0 mov r3, r2
 *   @0x15dba4 ldr r1, [r4, r1]
 *   @0x15dba8 add r0, pc, r0
 *   @0x15dbac pop {r4, lr}
 *   @0x15dbb0 b 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x15dbb4 eoreq r4, r9, r0, asr #2
 *   @0x15dbb8 .word 0xffffe204
 *   @0x15dbbc ldrsheq r11, [lr], -r8
 *   @0x15dbc0 .word 0xffffe208
 *   @0x15dbc4 andseq r11, lr, r4, ror #23
 *   @0x15dbc8 .word 0xffffe20c
 *   @0x15dbcc ldrsbeq r11, [lr], -r4
 *   @0x15dbd0 .word 0xffffe210
 *   @0x15dbd4 andseq r11, lr, r4, asr #23
 *   @0x15dbd8 .word 0xffffe214
 *   @0x15dbdc ldrheq r11, [lr], -r4
 *   @0x15dbe0 .word 0xffffe218
 *   @0x15dbe4 andseq r11, lr, r8, lsr #23
 *
 * ══ §78/127 EmbeddedImage_Find(char*, bool)  0x1768f0  size 236  59 条（0x1768f0..0x1769dc）
 * @func 0x1768f0 0x1769f0  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x176904→0x48ffdc, 0x176920→0x48ffe0, 0x176970→0x48ffe0
 * 调用序列: EmbeddedImage_Find(char*, bool)+0xc0 / 0xb6604 / EmbeddedImage_Find(char*, bool)+0x6c / 0xb6574
 * 字段偏移 top8: 0xd0×1 / 0xc8×1 / 0xb0×1 / 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1768f0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1768f4 subs r6, r0, #0
 *   @0x1768f8 ldr r3, [pc, #0xd0]
 *   @0x1768fc add r3, pc, r3
 *   @0x176900 beq 0x1769c8 <_Z18EmbeddedImage_FindPcb+0xd8>
 *   @0x176904 ldr r2, [pc, #0xc8]
 *   @0x176908 cmp r1, #0
 *   @0x17690c ldr r2, [r3, r2]
 *   @0x176910 ldr r7, [r2]
 *   @0x176914 beq 0x176964 <_Z18EmbeddedImage_FindPcb+0x74>
 *   @0x176918 cmp r7, #0
 *   @0x17691c ble 0x1769b0 <_Z18EmbeddedImage_FindPcb+0xc0>
 *   @0x176920 ldr r2, [pc, #0xb0]
 *   @0x176924 mov r5, #0
 *   @0x176928 ldr r3, [r3, r2]
 *   @0x17692c ldr r3, [r3]
 *   @0x176930 b 0x17693c <_Z18EmbeddedImage_FindPcb+0x4c>
 *   @0x176934 cmp r5, r7
 *   @0x176938 beq 0x1769bc <_Z18EmbeddedImage_FindPcb+0xcc>
 *   @0x17693c ldr r0, [r3]
 *   @0x176940 mov r1, r6
 *   @0x176944 mov r4, r3
 *   @0x176948 bl 0xb6604 <strstr@plt>
 *   @0x17694c add r5, r5, #1
 *   @0x176950 add r3, r4, #8
 *   @0x176954 cmp r0, #0
 *   @0x176958 beq 0x176934 <_Z18EmbeddedImage_FindPcb+0x44>
 *   @0x17695c mov r0, r4
 *   @0x176960 pop {r3, r4, r5, r6, r7, pc}
 *   @0x176964 cmp r7, #0
 *   @0x176968 movle r4, r1
 *   @0x17696c ble 0x17695c <_Z18EmbeddedImage_FindPcb+0x6c>
 *   @0x176970 ldr r2, [pc, #0x60]
 *   @0x176974 mov r5, r1
 *   @0x176978 ldr r3, [r3, r2]
 *   @0x17697c ldr r3, [r3]
 *   @0x176980 b 0x17698c <_Z18EmbeddedImage_FindPcb+0x9c>
 *   @0x176984 cmp r5, r7
 *   @0x176988 beq 0x1769b0 <_Z18EmbeddedImage_FindPcb+0xc0>
 *   @0x17698c ldr r0, [r3]
 *   @0x176990 mov r1, r6
 *   @0x176994 mov r4, r3
 *   @0x176998 bl 0xb6574 <strcmp@plt>
 *   @0x17699c add r5, r5, #1
 *   @0x1769a0 add r3, r4, #8
 *   @0x1769a4 cmp r0, #0
 *   @0x1769a8 bne 0x176984 <_Z18EmbeddedImage_FindPcb+0x94>
 *   @0x1769ac b 0x17695c <_Z18EmbeddedImage_FindPcb+0x6c>
 *   @0x1769b0 mov r4, #0
 *   @0x1769b4 mov r0, r4
 *   @0x1769b8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1769bc mov r4, r0
 *   @0x1769c0 mov r0, r4
 *   @0x1769c4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1769c8 mov r4, r6
 *   @0x1769cc b 0x17695c <_Z18EmbeddedImage_FindPcb+0x6c>
 *   @0x1769d0 eoreq r11, r7, r4, asr r3
 *   @0x1769d4 .word 0xffffe66c
 *   @0x1769d8 .word 0xffffe668
 *
 * ══ §79/127 ParticleType_Clear(int)  0x1a2f7c  size 236  59 条（0x1a2f7c..0x1a3068）
 * @func 0x1a2f7c 0x1a3068  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_Exists(int)
 * 字段偏移 top8: 0x4×2 / 0xcc×1 / 0x2×1 / 0x14×1 / 0x18×1 / 0x3c×1 / 0x40×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a2f7c push {r4, r5, r6, r7, r8, lr}
 *   @0x1a2f80 mov r6, r0
 *   @0x1a2f84 bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a2f88 cmp r0, #0
 *   @0x1a2f8c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1a2f90 ldr r3, [pc, #0xcc]
 *   @0x1a2f94 mov r2, #0
 *   @0x1a2f98 mov r1, #0
 *   @0x1a2f9c mov r12, #1065353216
 *   @0x1a2fa0 ldr r3, [pc, r3]
 *   @0x1a2fa4 mvn r4, #-16777216
 *   @0x1a2fa8 mov r5, #100
 *   @0x1a2fac mvn r7, #0
 *   @0x1a2fb0 ldr r3, [r3, #0x4]
 *   @0x1a2fb4 mov r0, #1
 *   @0x1a2fb8 mov r8, #0
 *   @0x1a2fbc movt r8, #0x4387
 *   @0x1a2fc0 ldr r3, [r3, r6, lsl #2]
 *   @0x1a2fc4 str r2, [r3, #0x14]
 *   @0x1a2fc8 str r2, [r3, #0x18]
 *   @0x1a2fcc str r2, [r3, #0x3c]
 *   @0x1a2fd0 str r2, [r3, #0x40]
 *   @0x1a2fd4 str r2, [r3, #0x44]
 *   @0x1a2fd8 str r7, [r3]
 *   @0x1a2fdc str r12, [r3, #0xc]
 *   @0x1a2fe0 strb r0, [r3, #0x4]
 *   @0x1a2fe4 str r12, [r3, #0x10]
 *   @0x1a2fe8 strb r1, [r3, #0x5]
 *   @0x1a2fec str r12, [r3, #0x1c]
 *   @0x1a2ff0 strb r1, [r3, #0x6]
 *   @0x1a2ff4 str r12, [r3, #0x20]
 *   @0x1a2ff8 str r1, [r3, #0x8]
 *   @0x1a2ffc str r2, [r3, #0x48]
 *   @0x1a3000 str r1, [r3, #0x34]
 *   @0x1a3004 str r2, [r3, #0x4c]
 *   @0x1a3008 str r1, [r3, #0x38]
 *   @0x1a300c str r2, [r3, #0x50]
 *   @0x1a3010 str r1, [r3, #0x2c]
 *   @0x1a3014 str r2, [r3, #0x54]
 *   @0x1a3018 str r1, [r3, #0x30]
 *   @0x1a301c str r2, [r3, #0x58]
 *   @0x1a3020 strb r1, [r3, #0x74]
 *   @0x1a3024 str r2, [r3, #0x64]
 *   @0x1a3028 str r2, [r3, #0x68]
 *   @0x1a302c str r2, [r3, #0x6c]
 *   @0x1a3030 str r2, [r3, #0x70]
 *   @0x1a3034 str r5, [r3, #0x24]
 *   @0x1a3038 str r5, [r3, #0x28]
 *   @0x1a303c str r2, [r3, #0x5c]
 *   @0x1a3040 str r1, [r3, #0x78]
 *   @0x1a3044 str r12, [r3, #0x94]
 *   @0x1a3048 str r12, [r3, #0x98]
 *   @0x1a304c str r12, [r3, #0x9c]
 *   @0x1a3050 str r8, [r3, #0x60]
 *   @0x1a3054 str r4, [r3, #0x7c]
 *   @0x1a3058 str r4, [r3, #0x80]
 *   @0x1a305c str r4, [r3, #0x84]
 *   @0x1a3060 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1a3064 eoreq sp, r4, r12, lsl #16
 *
 * ══ §80/127 F_LayerGetName(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bbe00  size 236  59 条（0x1bbe00..0x1bbeec）
 * @func 0x1bbe00 0x1bbeec  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x24×2 / 0x4×1 / 0x18×1 / 0xa8×1 / 0x1c×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bbe00 cmp r3, #1
 *   @0x1bbe04 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bbe08 mov r3, #0
 *   @0x1bbe0c mov r5, r3
 *   @0x1bbe10 mov r4, r0
 *   @0x1bbe14 movt r3, #0xbff0
 *   @0x1bbe18 str r5, [r0, #0xc]
 *   @0x1bbe1c str r3, [r0, #0x4]
 *   @0x1bbe20 str r5, [r0]
 *   @0x1bbe24 ldr r6, [sp, #0x18]
 *   @0x1bbe28 beq 0x1bbe40 <_Z14F_LayerGetNameR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bbe2c ldr r0, [pc, #0xa8]
 *   @0x1bbe30 mov r1, r5
 *   @0x1bbe34 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bbe38 add r0, pc, r0
 *   @0x1bbe3c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bbe40 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bbe44 subs r7, r0, #0
 *   @0x1bbe48 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bbe4c ldr r3, [r6, #0xc]
 *   @0x1bbe50 mov r0, r6
 *   @0x1bbe54 mov r1, r5
 *   @0x1bbe58 bic r3, r3, #-16777216
 *   @0x1bbe5c cmp r3, #1
 *   @0x1bbe60 beq 0x1bbe94 <_Z14F_LayerGetNameR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x1bbe64 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bbe68 mov r1, r0
 *   @0x1bbe6c mov r0, r7
 *   @0x1bbe70 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bbe74 cmp r0, #0
 *   @0x1bbe78 beq 0x1bbeb8 <_Z14F_LayerGetNameR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x1bbe7c ldr r1, [r0, #0x1c]
 *   @0x1bbe80 mov r0, r4
 *   @0x1bbe84 cmp r1, #0
 *   @0x1bbe88 beq 0x1bbea8 <_Z14F_LayerGetNameR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x1bbe8c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bbe90 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1bbe94 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bbe98 mov r1, r0
 *   @0x1bbe9c mov r0, r7
 *   @0x1bbea0 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bbea4 b 0x1bbe74 <_Z14F_LayerGetNameR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1bbea8 ldr r1, [pc, #0x30]
 *   @0x1bbeac pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bbeb0 add r1, pc, r1
 *   @0x1bbeb4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1bbeb8 ldr r3, [pc, #0x24]
 *   @0x1bbebc ldr r1, [pc, #0x24]
 *   @0x1bbec0 ldr r3, [pc, r3]
 *   @0x1bbec4 add r1, pc, r1
 *   @0x1bbec8 ldr r0, [r3]
 *   @0x1bbecc ldr r3, [r0]
 *   @0x1bbed0 ldr r3, [r3, #0xc]
 *   @0x1bbed4 blx r3
 *   @0x1bbed8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bbedc andseq r1, r9, r8, lsr pc
 *   @0x1bbee0 andseq r2, r7, r6, lsl #25
 *   @0x1bbee4 eoreq r1, r3, r4, asr r8
 *   @0x1bbee8 andseq r1, r9, r4, ror lr
 *
 * ══ §81/127 CLayerManager::MoveElement(CRoom*, CLayerElementBase*, CLayer*)  0x1bc1b4  size 236  59 条（0x1bc1b4..0x1bc2a0）
 * @func 0x1bc1b4 0x1bc2a0  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x60×4 / 0x10×2 / 0x4×2 / 0x20×2 / 0x-4×1 / 0x18×1 / 0x14×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc1b4 cmp r0, #0
 *   @0x1bc1b8 str r4, [sp, #-0x4]!
 *   @0x1bc1bc beq 0x1bc26c <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0xb8>
 *   @0x1bc1c0 cmp r1, #0
 *   @0x1bc1c4 beq 0x1bc26c <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0xb8>
 *   @0x1bc1c8 cmp r2, #0
 *   @0x1bc1cc beq 0x1bc26c <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0xb8>
 *   @0x1bc1d0 ldr r3, [r1, #0x10]
 *   @0x1bc1d4 cmp r3, r2
 *   @0x1bc1d8 beq 0x1bc26c <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0xb8>
 *   @0x1bc1dc cmp r3, #0
 *   @0x1bc1e0 beq 0x1bc218 <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0x64>
 *   @0x1bc1e4 ldr r12, [r1, #0x18]
 *   @0x1bc1e8 ldr r4, [r1, #0x14]
 *   @0x1bc1ec cmp r12, #0
 *   @0x1bc1f0 strne r4, [r12, #0x14]
 *   @0x1bc1f4 ldrne r12, [r1, #0x18]
 *   @0x1bc1f8 ldrne r4, [r1, #0x14]
 *   @0x1bc1fc streq r4, [r3, #0x58]
 *   @0x1bc200 cmp r4, #0
 *   @0x1bc204 streq r12, [r3, #0x5c]
 *   @0x1bc208 strne r12, [r4, #0x18]
 *   @0x1bc20c ldr r12, [r3, #0x60]
 *   @0x1bc210 sub r12, r12, #1
 *   @0x1bc214 str r12, [r3, #0x60]
 *   @0x1bc218 ldr r3, [r1]
 *   @0x1bc21c cmp r3, #2
 *   @0x1bc220 beq 0x1bc274 <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0xc0>
 *   @0x1bc224 ldr r12, [r2, #0x58]
 *   @0x1bc228 ldr r4, [r2, #0x60]
 *   @0x1bc22c cmp r12, #0
 *   @0x1bc230 streq r1, [r2, #0x5c]
 *   @0x1bc234 add r4, r4, #1
 *   @0x1bc238 str r4, [r2, #0x60]
 *   @0x1bc23c strne r1, [r12, #0x18]
 *   @0x1bc240 movne r12, #0
 *   @0x1bc244 ldrne r4, [r2, #0x58]
 *   @0x1bc248 streq r1, [r2, #0x58]
 *   @0x1bc24c streq r12, [r1, #0x18]
 *   @0x1bc250 strne r4, [r1, #0x14]
 *   @0x1bc254 streq r12, [r1, #0x14]
 *   @0x1bc258 strne r1, [r2, #0x58]
 *   @0x1bc25c strne r12, [r1, #0x18]
 *   @0x1bc260 cmp r3, #2
 *   @0x1bc264 str r2, [r1, #0x10]
 *   @0x1bc268 beq 0x1bc294 <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0xe0>
 *   @0x1bc26c ldr r4, [sp], #4
 *   @0x1bc270 bx lr
 *   @0x1bc274 ldr r12, [r1, #0x20]
 *   @0x1bc278 cmp r12, #0
 *   @0x1bc27c ldrne r3, [r2]
 *   @0x1bc280 movne r4, #1
 *   @0x1bc284 strbne r4, [r12, #0x174]
 *   @0x1bc288 strne r3, [r12, #0x170]
 *   @0x1bc28c ldrne r3, [r1]
 *   @0x1bc290 b 0x1bc224 <_ZN13CLayerManager11MoveElementEP5CRoomP17CLayerElementBaseP6CLayer+0x70>
 *   @0x1bc294 ldr r1, [r1, #0x20]
 *   @0x1bc298 ldr r4, [sp], #4
 *   @0x1bc29c b 0x1b8a28 <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance>
 *
 * ══ §82/127 CVariableList::Serialise(IBuffer*)  0x1f5550  size 236  59 条（0x1f5550..0x1f563c）
 * @func 0x1f5550 0x1f563c  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Variable_Find_Name(char const*, int, int) / IBuffer::Write(char const*) / RValue::Serialise(IBuffer*)
 * 字段偏移 top8: 0x8×2 / 0x4×2 / 0x18×1 / 0x2c×1 / 0x38×1 / 0x30×1 / 0xc×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f5550 push {r4, r5, r6, r7, r8, lr}
 *   @0x1f5554 mov r2, r1
 *   @0x1f5558 ldr r4, [r0, #0x18]
 *   @0x1f555c mov r7, r1
 *   @0x1f5560 ldr r3, [r2], #44
 *   @0x1f5564 mov r8, r0
 *   @0x1f5568 mov r1, #0
 *   @0x1f556c mov r0, r7
 *   @0x1f5570 vmov s15, r4
 *   @0x1f5574 str r1, [r7, #0x38]
 *   @0x1f5578 mov r1, #6
 *   @0x1f557c add r6, r8, #20
 *   @0x1f5580 vcvt.f64.s32 d7, s15
 *   @0x1f5584 vmov r4, r5, d7
 *   @0x1f5588 vstr s14, [r7, #44]
 *   @0x1f558c str r5, [r7, #0x30]
 *   @0x1f5590 ldr r3, [r3, #0x8]
 *   @0x1f5594 blx r3
 *   @0x1f5598 cmp r6, r8
 *   @0x1f559c add r5, r8, #4
 *   @0x1f55a0 beq 0x1f55ac <_ZN13CVariableList9SerialiseEP7IBuffer+0x5c>
 *   @0x1f55a4 cmp r6, r5
 *   @0x1f55a8 bne 0x1f5624 <_ZN13CVariableList9SerialiseEP7IBuffer+0xd4>
 *   @0x1f55ac mov r5, r6
 *   @0x1f55b0 mov r4, #0
 *   @0x1f55b4 cmp r4, #0
 *   @0x1f55b8 beq 0x1f5620 <_ZN13CVariableList9SerialiseEP7IBuffer+0xd0>
 *   @0x1f55bc ldr r3, [r4, #0xc]
 *   @0x1f55c0 mvn r1, #0
 *   @0x1f55c4 ldr r2, [r4, #0x8]
 *   @0x1f55c8 mov r0, #0
 *   @0x1f55cc vmov d7, r2, r3
 *   @0x1f55d0 vcvt.s32.f64 s15, d7
 *   @0x1f55d4 vmov r2, s15
 *   @0x1f55d8 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii>
 *   @0x1f55dc mov r1, r0
 *   @0x1f55e0 mov r0, r7
 *   @0x1f55e4 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc>
 *   @0x1f55e8 add r0, r4, #24
 *   @0x1f55ec mov r1, r7
 *   @0x1f55f0 bl 0xcf47c <_ZN6RValue9SerialiseEP7IBuffer>
 *   @0x1f55f4 ldr r4, [r4]
 *   @0x1f55f8 cmp r4, #0
 *   @0x1f55fc add r3, r5, #4
 *   @0x1f5600 bne 0x1f55b4 <_ZN13CVariableList9SerialiseEP7IBuffer+0x64>
 *   @0x1f5604 cmp r6, r5
 *   @0x1f5608 beq 0x1f5638 <_ZN13CVariableList9SerialiseEP7IBuffer+0xe8>
 *   @0x1f560c cmp r6, r3
 *   @0x1f5610 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1f5614 ldr r4, [r5, #0x4]
 *   @0x1f5618 mov r5, r3
 *   @0x1f561c b 0x1f55f8 <_ZN13CVariableList9SerialiseEP7IBuffer+0xa8>
 *   @0x1f5620 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f5624 ldr r4, [r8, #0x4]
 *   @0x1f5628 cmp r4, #0
 *   @0x1f562c bne 0x1f55b4 <_ZN13CVariableList9SerialiseEP7IBuffer+0x64>
 *   @0x1f5630 mov r8, r5
 *   @0x1f5634 b 0x1f5598 <_ZN13CVariableList9SerialiseEP7IBuffer+0x48>
 *   @0x1f5638 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §83/127 CStream::ReadCompressedStream()  0x201db0  size 236  59 条（0x201db0..0x201e9c）
 * @func 0x201db0 0x201e9c  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / CStream::CStream(int)×2 / CStream::SetPosition(int)×2 / CStream::ReadInteger() / CStream::CopyFrom(CStream*, long long, bool) / ZDecompressStream(CStream&, CStream&) / CStream::Free()
 * 字段偏移 top8: 0x70×2 / 0xc×2 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201db0 push {r4, r5, r6, r7, lr}
 *   @0x201db4 mov r5, r0
 *   @0x201db8 sub sp, sp, #12
 *   @0x201dbc mov r0, #32
 *   @0x201dc0 bl 0x27c524 <_Znwj>
 *   @0x201dc4 mov r1, #0
 *   @0x201dc8 mov r6, r0
 *   @0x201dcc bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x201dd0 mov r0, #32
 *   @0x201dd4 bl 0x27c524 <_Znwj>
 *   @0x201dd8 mov r1, #0
 *   @0x201ddc mov r4, r0
 *   @0x201de0 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x201de4 mov r0, r5
 *   @0x201de8 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x201dec mov r12, #1
 *   @0x201df0 mov r1, r5
 *   @0x201df4 str r12, [sp]
 *   @0x201df8 mov r7, r0
 *   @0x201dfc mov r0, r4
 *   @0x201e00 mov r2, r7
 *   @0x201e04 asr r3, r7, #31
 *   @0x201e08 bl 0x2015c8 <_ZN7CStream8CopyFromEPS_xb>
 *   @0x201e0c mov r0, r4
 *   @0x201e10 mov r1, #0
 *   @0x201e14 bl 0x201148 <_ZN7CStream11SetPositionEi>
 *   @0x201e18 ldr r3, [pc, #0x70]
 *   @0x201e1c ldr r1, [pc, #0x70]
 *   @0x201e20 mov r2, r7
 *   @0x201e24 ldr r3, [pc, r3]
 *   @0x201e28 add r1, pc, r1
 *   @0x201e2c ldr r5, [r3]
 *   @0x201e30 ldr r3, [r5]
 *   @0x201e34 mov r0, r5
 *   @0x201e38 ldr r3, [r3, #0xc]
 *   @0x201e3c blx r3
 *   @0x201e40 mov r0, r4
 *   @0x201e44 mov r1, r6
 *   @0x201e48 bl 0x201bbc <_Z17ZDecompressStreamR7CStreamS0_>
 *   @0x201e4c subs r7, r0, #0
 *   @0x201e50 movne r0, #0
 *   @0x201e54 bne 0x201e88 <_ZN7CStream20ReadCompressedStreamEv+0xd8>
 *   @0x201e58 ldr r3, [r5]
 *   @0x201e5c mov r0, r5
 *   @0x201e60 ldr r1, [pc, #0x30]
 *   @0x201e64 ldr r3, [r3, #0xc]
 *   @0x201e68 add r1, pc, r1
 *   @0x201e6c blx r3
 *   @0x201e70 mov r0, r4
 *   @0x201e74 bl 0x20133c <_ZN7CStream4FreeEv>
 *   @0x201e78 mov r0, r6
 *   @0x201e7c mov r1, r7
 *   @0x201e80 bl 0x201148 <_ZN7CStream11SetPositionEi>
 *   @0x201e84 mov r0, r6
 *   @0x201e88 add sp, sp, #12
 *   @0x201e8c pop {r4, r5, r6, r7, pc}
 *   @0x201e90 ldrsheq r11, [lr], -r0
 *   @0x201e94 andseq r1, r5, r12, lsr r9
 *   @0x201e98 andseq r1, r5, r4, lsl r9
 *
 * ══ §84/127 SetKey(int)  0x202294  size 236  59 条（0x202294..0x202380）
 * @func 0x202294 0x202380  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xbc×1 / 0x84×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202294 movw r3, #0x4dd3
 *   @0x202298 movt r3, #0x1062
 *   @0x20229c mov r1, #250
 *   @0x2022a0 smull r2, r3, r3, r0
 *   @0x2022a4 asr r2, r0, #31
 *   @0x2022a8 push {r4, r5, r6, r7, r8}
 *   @0x2022ac rsb r3, r2, r3, asr #4
 *   @0x2022b0 mls r3, r1, r3, r0
 *   @0x2022b4 ldr r1, [pc, #0xbc]
 *   @0x2022b8 ldr r1, [pc, r1]
 *   @0x2022bc adds r7, r3, #6
 *   @0x2022c0 addmi r7, r3, #260
 *   @0x2022c4 movw r3, #0x4dd3
 *   @0x2022c8 movt r3, #0x1062
 *   @0x2022cc addmi r7, r7, #2
 *   @0x2022d0 smull r12, r0, r3, r0
 *   @0x2022d4 rsbs r3, r2, r0, asr #4
 *   @0x2022d8 mov r2, #0
 *   @0x2022dc addmi r3, r3, #256
 *   @0x2022e0 strb r2, [r1, r2]
 *   @0x2022e4 add r2, r2, #1
 *   @0x2022e8 cmp r2, #256
 *   @0x2022ec bne 0x2022e0 <_Z6SetKeyi+0x4c>
 *   @0x2022f0 ldr r4, [pc, #0x84]
 *   @0x2022f4 mov r2, #0
 *   @0x2022f8 ldr r4, [pc, r4]
 *   @0x2022fc strb r2, [r4, r2]
 *   @0x202300 add r2, r2, #1
 *   @0x202304 cmp r2, #256
 *   @0x202308 bne 0x2022fc <_Z6SetKeyi+0x68>
 *   @0x20230c movw r8, #0x409
 *   @0x202310 add r3, r7, r3
 *   @0x202314 movt r8, #0x8102
 *   @0x202318 movw r0, #0x2710
 *   @0x20231c smull r12, r2, r8, r3
 *   @0x202320 asr r12, r3, #31
 *   @0x202324 subs r0, r0, #1
 *   @0x202328 add r2, r2, r3
 *   @0x20232c rsb r2, r12, r2, asr #7
 *   @0x202330 rsb r2, r2, r2, lsl #7
 *   @0x202334 sub r2, r3, r2, lsl #1
 *   @0x202338 add r3, r3, r7
 *   @0x20233c add r12, r2, #1
 *   @0x202340 add r2, r2, #2
 *   @0x202344 ldrb r5, [r1, r12]
 *   @0x202348 ldrb r6, [r1, r2]
 *   @0x20234c strb r6, [r1, r12]
 *   @0x202350 strb r5, [r1, r2]
 *   @0x202354 bne 0x20231c <_Z6SetKeyi+0x88>
 *   @0x202358 mov r3, #1
 *   @0x20235c ldrb r2, [r1, #0x1]!
 *   @0x202360 strb r3, [r4, r2]
 *   @0x202364 add r3, r3, #1
 *   @0x202368 cmp r3, #256
 *   @0x20236c bne 0x20235c <_Z6SetKeyi+0xc8>
 *   @0x202370 pop {r4, r5, r6, r7, r8}
 *   @0x202374 bx lr
 *   @0x202378 andseq pc, lr, r4, asr #1
 *   @0x20237c andseq pc, lr, r8, lsl #1
 *
 * ══ §85/127 cARRAY_CLASS<DLL_RFunction*>::~cARRAY_CLASS()  0x210040  size 236  59 条（0x210040..0x21012c）
 * @func 0x210040 0x21012c  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×4 / cARRAY_CLASS<DLL_RFunction*>::~cARRAY_CLASS()+0xbc / operator delete(void*) / cARRAY_CLASS<DLL_RFunction*>::~cARRAY_CLASS()+0x30
 * 字段偏移 top8: 0x4×5 / 0x8×2 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x210040 ldr r12, [r0]
 *   @0x210044 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x210048 cmp r12, #0
 *   @0x21004c mov r7, r0
 *   @0x210050 beq 0x210114 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xd4>
 *   @0x210054 ldr r5, [r0, #0x4]
 *   @0x210058 cmp r5, #0
 *   @0x21005c beq 0x21011c <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xdc>
 *   @0x210060 cmp r12, #0
 *   @0x210064 ble 0x2100fc <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xbc>
 *   @0x210068 mov r4, #0
 *   @0x21006c mov r8, r4
 *   @0x210070 ldr r1, [r5]
 *   @0x210074 movw r3, #0xfeee
 *   @0x210078 movt r3, #0xfeee
 *   @0x21007c movw r2, #0xfeee
 *   @0x210080 cmp r1, r3
 *   @0x210084 movt r2, #0xfeee
 *   @0x210088 lsl r9, r4, #2
 *   @0x21008c beq 0x2100f0 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xb0>
 *   @0x210090 ldr r6, [r5, r4, lsl #2]
 *   @0x210094 add r1, r5, r9
 *   @0x210098 cmp r6, #0
 *   @0x21009c beq 0x2100f0 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xb0>
 *   @0x2100a0 ldr r3, [r6]
 *   @0x2100a4 cmp r3, r2
 *   @0x2100a8 mov r0, r3
 *   @0x2100ac beq 0x2100e8 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xa8>
 *   @0x2100b0 cmp r3, #0
 *   @0x2100b4 beq 0x2100c0 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0x80>
 *   @0x2100b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2100bc str r8, [r6]
 *   @0x2100c0 ldr r0, [r6, #0x8]
 *   @0x2100c4 cmp r0, #0
 *   @0x2100c8 beq 0x2100d4 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0x94>
 *   @0x2100cc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2100d0 str r8, [r6, #0x8]
 *   @0x2100d4 mov r0, r6
 *   @0x2100d8 bl 0x27d1d0 <_ZdlPv>
 *   @0x2100dc ldr r1, [r7, #0x4]
 *   @0x2100e0 ldr r12, [r7]
 *   @0x2100e4 add r1, r1, r9
 *   @0x2100e8 str r8, [r1]
 *   @0x2100ec ldr r5, [r7, #0x4]
 *   @0x2100f0 add r4, r4, #1
 *   @0x2100f4 cmp r4, r12
 *   @0x2100f8 blt 0x210070 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0x30>
 *   @0x2100fc mov r0, r5
 *   @0x210100 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x210104 mov r3, #0
 *   @0x210108 str r3, [r7, #0x4]
 *   @0x21010c mov r3, #0
 *   @0x210110 str r3, [r7]
 *   @0x210114 mov r0, r7
 *   @0x210118 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21011c mov r0, r5
 *   @0x210120 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x210124 str r5, [r7, #0x4]
 *   @0x210128 b 0x21010c <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xcc>
 *
 * ══ §86/127 COggSyncThread::Play_Sound(int&, cAudio_Sound*, bool, float, int)  0x224e48  size 236  59 条（0x224e48..0x224f34）
 * @func 0x224e48 0x224f34  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock()
 * 字段偏移 top8: 0x80c×3 / 0x20×2 / 0x84e×1 / 0x24×1 / 0x808×1 / 0x804×1 / 0x2d6×1 / 0x2dc×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224e48 push {r4, r5, r6, r7, r8, lr}
 *   @0x224e4c vpush {d8}
 *   @0x224e50 mov r5, r0
 *   @0x224e54 vldr s16, [sp, #32]
 *   @0x224e58 ldrb r0, [r0, #0x84e]
 *   @0x224e5c mov r6, r2
 *   @0x224e60 mov r8, r3
 *   @0x224e64 ldr r7, [sp, #0x24]
 *   @0x224e68 cmp r0, #0
 *   @0x224e6c beq 0x224e90 <_ZN14COggSyncThread10Play_SoundERiP12cAudio_Soundbfi+0x48>
 *   @0x224e70 ldr r3, [r5, #0x80c]
 *   @0x224e74 str r3, [r1]
 *   @0x224e78 ldr r0, [r5, #0x80c]
 *   @0x224e7c ldr r3, [r5, #0x808]
 *   @0x224e80 add r0, r0, #1
 *   @0x224e84 str r0, [r5, #0x80c]
 *   @0x224e88 cmp r0, r3
 *   @0x224e8c bgt 0x224f04 <_ZN14COggSyncThread10Play_SoundERiP12cAudio_Soundbfi+0xbc>
 *   @0x224e90 ldr r1, [r1]
 *   @0x224e94 mov r0, r5
 *   @0x224e98 ldr r3, [r5, #0x804]
 *   @0x224e9c add r1, r1, r1, lsl #1
 *   @0x224ea0 add r4, r3, r1, lsl #8
 *   @0x224ea4 bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x224ea8 vcmpe.f32 s16, #0
 *   @0x224eac cmp r8, #0
 *   @0x224eb0 mov r3, #1
 *   @0x224eb4 strb r3, [r4, #0x2d6]
 *   @0x224eb8 movne r3, #3
 *   @0x224ebc strbne r3, [r4, #0x2d6]
 *   @0x224ec0 mov r3, #0
 *   @0x224ec4 str r7, [r4, #0x2dc]
 *   @0x224ec8 vmrs APSR_nzcv, fpscr
 *   @0x224ecc ldrbgt r3, [r4, #0x2d6]
 *   @0x224ed0 vstrgt s16, [r4, #744]
 *   @0x224ed4 strle r3, [r4, #0x2e8]
 *   @0x224ed8 orrgt r3, r3, #16
 *   @0x224edc str r6, [r4, #0x2d8]
 *   @0x224ee0 strbgt r3, [r4, #0x2d6]
 *   @0x224ee4 mov r0, r5
 *   @0x224ee8 vpop {d8}
 *   @0x224eec mov r2, #1
 *   @0x224ef0 mov r3, #0
 *   @0x224ef4 strb r2, [r4, #0x2d5]
 *   @0x224ef8 str r3, [r4, #0x2e0]
 *   @0x224efc pop {r4, r5, r6, r7, r8, lr}
 *   @0x224f00 b 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x224f04 ldr r3, [pc, #0x20]
 *   @0x224f08 ldr r1, [pc, #0x20]
 *   @0x224f0c ldr r3, [pc, r3]
 *   @0x224f10 add r1, pc, r1
 *   @0x224f14 ldr r0, [r3]
 *   @0x224f18 ldr r3, [r0]
 *   @0x224f1c ldr r3, [r3, #0xc]
 *   @0x224f20 blx r3
 *   @0x224f24 vpop {d8}
 *   @0x224f28 pop {r4, r5, r6, r7, r8, pc}
 *   @0x224f2c andseq r8, r12, r8, lsl #16
 *   @0x224f30 andseq pc, r2, r4, asr #30
 *
 * ══ §87/127 CPhysicsFixture::CheckPolygonIntegrity()  0x2369dc  size 236  59 条（0x2369dc..0x236ac8）
 * @func 0x2369dc 0x236ac8  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsFixture::CheckPolygonIntegrity()+0xd4 / __aeabi_idivmod / CPhysicsFixture::CheckPolygonIntegrity()+0xb8 / YYError(char const*, ...)
 * 字段偏移 top8: 0xc×1 / 0x14×1 / 0x28×1 / 0x1c×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2369dc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2369e0 vpush {d8}
 *   @0x2369e4 mov r8, r0
 *   @0x2369e8 ldr r5, [r0, #0xc]
 *   @0x2369ec cmp r5, #2
 *   @0x2369f0 ble 0x236ab0 <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv+0xd4>
 *   @0x2369f4 ldr r10, [r0, #0x14]
 *   @0x2369f8 mov r4, #0
 *   @0x2369fc vldr s16, [pc, #188]
 *   @0x236a00 mov r7, r10
 *   @0x236a04 add r9, r4, #1
 *   @0x236a08 mov r1, r5
 *   @0x236a0c mov r0, r9
 *   @0x236a10 bl 0x318dec <__aeabi_idivmod>
 *   @0x236a14 vldr s12, [r7]
 *   @0x236a18 vldr s13, [r7, #4]
 *   @0x236a1c mov r2, r10
 *   @0x236a20 add r3, r10, r1, lsl #3
 *   @0x236a24 vldr s10, [r3]
 *   @0x236a28 vldr s11, [r3, #4]
 *   @0x236a2c vsub.f32 s10, s10, s12
 *   @0x236a30 mov r3, #0
 *   @0x236a34 vsub.f32 s11, s11, s13
 *   @0x236a38 cmp r4, r3
 *   @0x236a3c cmpne r3, r1
 *   @0x236a40 add r3, r3, #1
 *   @0x236a44 movne r6, #0
 *   @0x236a48 moveq r6, #1
 *   @0x236a4c beq 0x236a74 <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv+0x98>
 *   @0x236a50 vldr s15, [r2]
 *   @0x236a54 vldr s14, [r2, #4]
 *   @0x236a58 vsub.f32 s15, s15, s12
 *   @0x236a5c vmul.f32 s15, s11, s15
 *   @0x236a60 vsub.f32 s14, s14, s13
 *   @0x236a64 vnmls.f32 s15, s10, s14
 *   @0x236a68 vcmpe.f32 s15, s16
 *   @0x236a6c vmrs APSR_nzcv, fpscr
 *   @0x236a70 bls 0x236a94 <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv+0xb8>
 *   @0x236a74 cmp r3, r5
 *   @0x236a78 add r2, r2, #8
 *   @0x236a7c bne 0x236a38 <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv+0x5c>
 *   @0x236a80 cmp r9, r5
 *   @0x236a84 add r7, r7, #8
 *   @0x236a88 beq 0x236ab0 <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv+0xd4>
 *   @0x236a8c mov r4, r9
 *   @0x236a90 b 0x236a04 <_ZN15CPhysicsFixture21CheckPolygonIntegrityEv+0x28>
 *   @0x236a94 ldr r0, [pc, #0x28]
 *   @0x236a98 ldr r1, [r8, #0x1c]
 *   @0x236a9c add r0, pc, r0
 *   @0x236aa0 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x236aa4 vpop {d8}
 *   @0x236aa8 mov r0, r6
 *   @0x236aac pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x236ab0 vpop {d8}
 *   @0x236ab4 mov r6, #1
 *   @0x236ab8 mov r0, r6
 *   @0x236abc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x236ac0 strlt r12, [r7, -r12, lsr #11]!
 *   @0x236ac4 ldrsbeq lr, [r1], -r12
 *
 * ══ §88/127 F_JSObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*)  0x24a8b0  size 236  59 条（0x24a8b0..0x24a99c）
 * @func 0x24a8b0 0x24a99c  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / Call_ScriptRef(YYObjectBase*, RValue*, CScriptRef*, int, RValue*) / FREE_RValue__Pre(RValue*) / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0x18×2 / 0x14×2 / 0x30×1 / 0x48×1 / 0x4×1 / 0xc×1 / 0x64×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24a8b0 push {r4, r5, r6, r7, r8, lr}
 *   @0x24a8b4 sub sp, sp, #24
 *   @0x24a8b8 mov r4, r1
 *   @0x24a8bc mov r6, r0
 *   @0x24a8c0 ldr r5, [sp, #0x30]
 *   @0x24a8c4 mov r7, r3
 *   @0x24a8c8 str r5, [sp]
 *   @0x24a8cc bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x24a8d0 ldr r2, [r4, #0x48]
 *   @0x24a8d4 ldr r6, [r6]
 *   @0x24a8d8 cmp r2, #3
 *   @0x24a8dc beq 0x24a8e8 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x24a8e0 add sp, sp, #24
 *   @0x24a8e4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x24a8e8 ldr r1, [r4, #0x4]
 *   @0x24a8ec cmp r1, #0
 *   @0x24a8f0 beq 0x24a988 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x24a8f4 ldr r3, [r1, #0xc]
 *   @0x24a8f8 bic r3, r3, #-16777216
 *   @0x24a8fc cmp r3, #6
 *   @0x24a900 beq 0x24a974 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x24a904 mov r3, #0
 *   @0x24a908 str r3, [r6, #0x18]
 *   @0x24a90c ldr r3, [r4, #0x64]
 *   @0x24a910 cmp r3, #0
 *   @0x24a914 beq 0x24a8e0 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x24a918 add r8, sp, #8
 *   @0x24a91c str r5, [sp]
 *   @0x24a920 mov r2, r4
 *   @0x24a924 mov r3, r7
 *   @0x24a928 mov r0, r6
 *   @0x24a92c mov r1, r8
 *   @0x24a930 mov lr, #0
 *   @0x24a934 mvn r12, #-16777216
 *   @0x24a938 mov r4, #0
 *   @0x24a93c mov r5, #0
 *   @0x24a940 str lr, [sp, #0x10]
 *   @0x24a944 strd r4, r5, [sp, #8]
 *   @0x24a948 str r12, [sp, #0x14]
 *   @0x24a94c bl 0x249590 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_>
 *   @0x24a950 ldr r3, [sp, #0x14]
 *   @0x24a954 sub r3, r3, #1
 *   @0x24a958 bic r3, r3, #-16777216
 *   @0x24a95c bic r3, r3, #3
 *   @0x24a960 cmp r3, #0
 *   @0x24a964 bne 0x24a8e0 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x24a968 mov r0, r8
 *   @0x24a96c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24a970 b 0x24a8e0 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x24a974 ldr r1, [r1]
 *   @0x24a978 mov r0, r6
 *   @0x24a97c str r1, [r6, #0x18]
 *   @0x24a980 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x24a984 b 0x24a90c <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x24a988 mov r0, r4
 *   @0x24a98c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24a990 subs r1, r0, #0
 *   @0x24a994 bne 0x24a8f4 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x24a998 b 0x24a904 <_Z21F_JSObjectConstructorR6RValueP9CInstanceS2_iPS_+0x54>
 *
 * ══ §89/127 anon_27e910  0x27e910  size 236  59 条（0x27e910..0x27e9fc）
 * @func 0x27e910 0x27e9fc  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: sprintbuf×5 / json_object_get_object / anon_27e408+0x50
 * 字段偏移 top8: 0xa4×3 / 0x20×2 / 0x4×2 / 0x8×2 / 0xc8×1 / 0xa0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e910 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x27e914 mov r4, r1
 *   @0x27e918 ldr r1, [pc, #0xc8]
 *   @0x27e91c mov r5, r0
 *   @0x27e920 mov r0, r4
 *   @0x27e924 add r1, pc, r1
 *   @0x27e928 bl 0x280dbc <sprintbuf>
 *   @0x27e92c mov r0, r5
 *   @0x27e930 bl 0x27e8f4 <json_object_get_object>
 *   @0x27e934 ldr r5, [r0, #0x20]
 *   @0x27e938 cmp r5, #0
 *   @0x27e93c beq 0x27e9d4 <json_object_get_object+0xe0>
 *   @0x27e940 ldr r10, [pc, #0xa4]
 *   @0x27e944 ldr r9, [pc, #0xa4]
 *   @0x27e948 ldr r11, [pc, #0xa4]
 *   @0x27e94c add r10, pc, r10
 *   @0x27e950 ldr r8, [pc, #0xa0]
 *   @0x27e954 add r9, pc, r9
 *   @0x27e958 ldr r7, [r5]
 *   @0x27e95c add r11, pc, r11
 *   @0x27e960 ldr r6, [r5, #0x4]
 *   @0x27e964 add r8, pc, r8
 *   @0x27e968 b 0x27e994 <json_object_get_object+0xa0>
 *   @0x27e96c ldr r3, [r6, #0x8]
 *   @0x27e970 blx r3
 *   @0x27e974 ldr r5, [r5, #0x8]
 *   @0x27e978 mov r0, r4
 *   @0x27e97c mov r1, r8
 *   @0x27e980 cmp r5, #0
 *   @0x27e984 beq 0x27e9d4 <json_object_get_object+0xe0>
 *   @0x27e988 ldr r7, [r5]
 *   @0x27e98c ldr r6, [r5, #0x4]
 *   @0x27e990 bl 0x280dbc <sprintbuf>
 *   @0x27e994 mov r1, r10
 *   @0x27e998 mov r0, r4
 *   @0x27e99c bl 0x280dbc <sprintbuf>
 *   @0x27e9a0 mov r1, r7
 *   @0x27e9a4 mov r0, r4
 *   @0x27e9a8 bl 0x27e458 <mc_info+0x90>
 *   @0x27e9ac mov r1, r9
 *   @0x27e9b0 mov r0, r4
 *   @0x27e9b4 bl 0x280dbc <sprintbuf>
 *   @0x27e9b8 subs r0, r6, #0
 *   @0x27e9bc mov r1, r4
 *   @0x27e9c0 bne 0x27e96c <json_object_get_object+0x78>
 *   @0x27e9c4 mov r0, r4
 *   @0x27e9c8 mov r1, r11
 *   @0x27e9cc bl 0x280dbc <sprintbuf>
 *   @0x27e9d0 b 0x27e974 <json_object_get_object+0x80>
 *   @0x27e9d4 ldr r1, [pc, #0x20]
 *   @0x27e9d8 mov r0, r4
 *   @0x27e9dc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x27e9e0 add r1, pc, r1
 *   @0x27e9e4 b 0x280dbc <sprintbuf>
 *   @0x27e9e8 andeq r8, sp, r4, lsl #19
 *   @0x27e9ec andeq r8, sp, r0, ror #18
 *   @0x27e9f0 andeq r8, sp, r12, asr r9
 *   @0x27e9f4 andeq r3, r11, r8, asr #18
 *   @0x27e9f8 andeq r3, r11, r0, asr #23
 *
 * ══ §90/127 PB_AchievementPicLoaded(HTTP_REQ_CONTEXT*, void*, int*)  0x28fb88  size 236  59 条（0x28fb88..0x28fc74）
 * @func 0x28fb88 0x28fc74  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / CreateDsMap(int, ...)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0xcc×1 / 0xc0×1 / 0x84×1 / 0x74×1 / 0x68×1 / 0x64×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fb88 ldr r3, [pc, #0xcc]
 *   @0x28fb8c push {r4, r5, r6, r7, lr}
 *   @0x28fb90 ldr r3, [pc, r3]
 *   @0x28fb94 mov r6, r1
 *   @0x28fb98 ldr r1, [pc, #0xc0]
 *   @0x28fb9c ldr r4, [r3]
 *   @0x28fba0 sub sp, sp, #44
 *   @0x28fba4 add r1, pc, r1
 *   @0x28fba8 mov r7, r2
 *   @0x28fbac mov r5, #0
 *   @0x28fbb0 ldr r3, [r4]
 *   @0x28fbb4 mov r0, r4
 *   @0x28fbb8 ldr r3, [r3, #0xc]
 *   @0x28fbbc blx r3
 *   @0x28fbc0 ldr r1, [r4]
 *   @0x28fbc4 mov r0, r4
 *   @0x28fbc8 ldr r2, [r6, #0x4]
 *   @0x28fbcc ldr r3, [r6]
 *   @0x28fbd0 mov r4, #0
 *   @0x28fbd4 ldr r12, [r1, #0xc]
 *   @0x28fbd8 ldr r1, [pc, #0x84]
 *   @0x28fbdc add r1, pc, r1
 *   @0x28fbe0 blx r12
 *   @0x28fbe4 vldr s13, [r6, #4]
 *   @0x28fbe8 vcvt.f64.s32 d7, s13
 *   @0x28fbec ldr r1, [pc, #0x74]
 *   @0x28fbf0 ldr r0, [r6]
 *   @0x28fbf4 mov r3, #0
 *   @0x28fbf8 add r1, pc, r1
 *   @0x28fbfc ldr r2, [pc, #0x68]
 *   @0x28fc00 str r1, [sp, #0x4]
 *   @0x28fc04 ldr r1, [pc, #0x64]
 *   @0x28fc08 add r2, pc, r2
 *   @0x28fc0c str r0, [sp, #0x20]
 *   @0x28fc10 mov r0, #3
 *   @0x28fc14 add r1, pc, r1
 *   @0x28fc18 str r2, [sp, #0x14]
 *   @0x28fc1c vstr d7, [sp, #8]
 *   @0x28fc20 mov r2, #0
 *   @0x28fc24 str r3, [sp]
 *   @0x28fc28 str r3, [sp, #0x10]
 *   @0x28fc2c mov r3, #28672
 *   @0x28fc30 strd r4, r5, [sp, #24]
 *   @0x28fc34 movt r3, #0x408f
 *   @0x28fc38 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x28fc3c str r0, [r7]
 *   @0x28fc40 ldr r0, [r6]
 *   @0x28fc44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x28fc48 mov r0, r6
 *   @0x28fc4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x28fc50 mov r0, #70
 *   @0x28fc54 add sp, sp, #44
 *   @0x28fc58 pop {r4, r5, r6, r7, pc}
 *   @0x28fc5c ldrheq sp, [r5], -r0
 *   @0x28fc60 andeq r8, r12, r4, lsr r5
 *   @0x28fc64 andeq r8, r12, r0, lsr #10
 *   @0x28fc68 andeq r8, r12, r0, lsr r5
 *   @0x28fc6c andeq r8, r12, r12, lsr #9
 *   @0x28fc70 andeq r0, r10, r12, lsr #28
 *
 * ══ §91/127 F_NETWORK_Connect_ex(RValue&, CInstance*, CInstance*, int, RValue*)  0x29826c  size 236  59 条（0x29826c..0x298358）
 * @func 0x29826c 0x298358  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_NETWORK_Connect_ex(RValue&, CInstance*, CInstance*, int, RValue*)+0xc8 / YYGetString(RValue const*, int) / yySocket::Connect(char*, int) / yySocket::Startup()
 * 字段偏移 top8: 0x4×2 / 0x18×2 / 0xcc×1 / 0xc×1 / 0xa8×1 / 0x80×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29826c push {r3, r4, r5, r6, r7, lr}
 *   @0x298270 mov r3, #0
 *   @0x298274 ldr r5, [pc, #0xcc]
 *   @0x298278 mov r4, r0
 *   @0x29827c str r3, [r0]
 *   @0x298280 ldr r5, [pc, r5]
 *   @0x298284 str r3, [r0, #0xc]
 *   @0x298288 str r3, [r0, #0x4]
 *   @0x29828c ldrb r3, [r5]
 *   @0x298290 ldr r6, [sp, #0x18]
 *   @0x298294 cmp r3, #0
 *   @0x298298 beq 0x298324 <_Z20F_NETWORK_Connect_exR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x29829c ldr r3, [pc, #0xa8]
 *   @0x2982a0 ldr r3, [pc, r3]
 *   @0x2982a4 ldr r3, [r3]
 *   @0x2982a8 sub r3, r3, #2
 *   @0x2982ac cmp r3, #2
 *   @0x2982b0 pophi {r3, r4, r5, r6, r7, pc}
 *   @0x2982b4 mov r0, r6
 *   @0x2982b8 mov r1, #0
 *   @0x2982bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x2982c0 cmp r0, #0
 *   @0x2982c4 blt 0x298334 <_Z20F_NETWORK_Connect_exR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x2982c8 ldr r3, [pc, #0x80]
 *   @0x2982cc add r2, r0, r0, lsl #1
 *   @0x2982d0 mov r1, #1
 *   @0x2982d4 mov r0, r6
 *   @0x2982d8 ldr r3, [pc, r3]
 *   @0x2982dc add r3, r3, r2, lsl #2
 *   @0x2982e0 ldr r7, [r3, #0x4]
 *   @0x2982e4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x2982e8 mov r1, #2
 *   @0x2982ec mov r5, r0
 *   @0x2982f0 mov r0, r6
 *   @0x2982f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x2982f8 mov r1, r5
 *   @0x2982fc mov r2, r0
 *   @0x298300 mov r0, r7
 *   @0x298304 bl 0x295858 <_ZN8yySocket7ConnectEPci>
 *   @0x298308 vmov s15, r0
 *   @0x29830c vcvt.f64.s32 d7, s15
 *   @0x298310 vmov r0, r1, d7
 *   @0x298314 vmov r2, s14
 *   @0x298318 mov r3, r1
 *   @0x29831c stm r4, {r2, r3}
 *   @0x298320 pop {r3, r4, r5, r6, r7, pc}
 *   @0x298324 bl 0x294d18 <_ZN8yySocket7StartupEv>
 *   @0x298328 mov r3, #1
 *   @0x29832c strb r3, [r5]
 *   @0x298330 b 0x29829c <_Z20F_NETWORK_Connect_exR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x298334 ldr r0, [pc, #0x18]
 *   @0x298338 mov r1, #0
 *   @0x29833c pop {r3, r4, r5, r6, r7, lr}
 *   @0x298340 add r0, pc, r0
 *   @0x298344 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x298348 andseq r9, r5, r12, lsl r7
 *   @0x29834c andseq r8, r5, r0, lsl #1
 *   @0x298350 andseq r9, r5, r12, asr #13
 *   @0x298354 strdeq r1, r2, [r12], -r4
 *
 * ══ §92/127 RelySendUnreliable(int, char const*, int, int)  0x29a0b8  size 236  59 条（0x29a0b8..0x29a1a4）
 * @func 0x29a0b8 0x29a1a4  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::Write(void const*, unsigned int, unsigned int)×3 / GetIBuffer(int)×2 / CreateBuffer(int, eBuffer_Format, int) / CalcCRC(char const*, int) / RelySendData(int, char const*, int, int, int) / FreeIBuffer(int)
 * 字段偏移 top8: 0x10×4 / 0xc×3 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29a0b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29a0bc mov r11, r0
 *   @0x29a0c0 sub sp, sp, #20
 *   @0x29a0c4 mov r0, r3
 *   @0x29a0c8 mov r10, r1
 *   @0x29a0cc mov r9, r2
 *   @0x29a0d0 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x29a0d4 mov r2, #1
 *   @0x29a0d8 mov r1, #3
 *   @0x29a0dc add r8, sp, #8
 *   @0x29a0e0 mov r5, #0
 *   @0x29a0e4 mov r6, r0
 *   @0x29a0e8 ldr r0, [r0, #0x10]
 *   @0x29a0ec add r0, r0, r2
 *   @0x29a0f0 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati>
 *   @0x29a0f4 mov r7, r0
 *   @0x29a0f8 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x29a0fc mov r1, r8
 *   @0x29a100 mov r2, #1
 *   @0x29a104 mov r3, #8
 *   @0x29a108 str r5, [sp, #0x8]
 *   @0x29a10c str r5, [sp, #0xc]
 *   @0x29a110 mov r4, r0
 *   @0x29a114 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x29a118 ldr r3, [r6, #0x10]
 *   @0x29a11c mov r2, #1
 *   @0x29a120 ldr r1, [r6, #0xc]
 *   @0x29a124 mov r0, r4
 *   @0x29a128 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x29a12c ldr r0, [r4, #0xc]
 *   @0x29a130 ldr r1, [r4, #0x10]
 *   @0x29a134 add r0, r0, #4
 *   @0x29a138 sub r1, r1, #4
 *   @0x29a13c bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x29a140 ldr r3, [r4]
 *   @0x29a144 mov r1, r5
 *   @0x29a148 mov r2, r5
 *   @0x29a14c ldr r3, [r3, #0x10]
 *   @0x29a150 str r0, [sp, #0x8]
 *   @0x29a154 mov r0, r4
 *   @0x29a158 blx r3
 *   @0x29a15c mov r1, r8
 *   @0x29a160 mov r0, r4
 *   @0x29a164 mov r2, #1
 *   @0x29a168 mov r3, #8
 *   @0x29a16c bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x29a170 mvn r12, #0
 *   @0x29a174 mov r1, r10
 *   @0x29a178 mov r2, r9
 *   @0x29a17c mov r3, r7
 *   @0x29a180 str r12, [sp]
 *   @0x29a184 mov r0, r11
 *   @0x29a188 bl 0x299ff8 <_Z12RelySendDataiPKciii>
 *   @0x29a18c mov r4, r0
 *   @0x29a190 mov r0, r7
 *   @0x29a194 bl 0xc6a88 <_Z11FreeIBufferi>
 *   @0x29a198 mov r0, r4
 *   @0x29a19c add sp, sp, #20
 *   @0x29a1a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §93/127 png_write_IDAT  0x2b16a0  size 236  59 条（0x2b16a0..0x2b178c）
 * @func 0x2b16a0 0x2b178c  size 236  59 条
 * 部分覆盖: 本节 59/103 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2be194+0x148 / png_write_IDAT+0xb2 / __aeabi_uidivmod / png_write_IDAT+0x8a
 * 字段偏移 top8: 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b16a0 push.w {r0, r1, r4, r5, r6, r7, r8, lr}
 *   @0x2b16a4 mov r5, r1
 *   @0x2b16a8 mov r4, r0
 *   @0x2b16ac add r1, pc
 *   @0x2b16b0 stmdbvc r11, {r1, r4, r8, r9, r10, r11}
 *   @0x2b16b4 str r0, [sp]
 *   @0x2b16b8 .word 0xf8d43004
 *   @0x2b16bc ldrbeq r3, [r11, -r12, lsr #2]
 *   @0x2b16c0 bmi 0x2b1766 <png_write_IDAT+0xc6>
 *   @0x2b16c4 blhs 0x2be2dc <jinit_color_deconverter+0x374>
 *   @0x2b16c8 bne 0x2b1766 <png_write_IDAT+0xc6>
 *   @0x2b16cc and r3, r6, #0xf
 *   @0x2b16d0 cmp r3, #0x8
 *   @0x2b16d4 and r3, r6, #0xf0
 *   @0x2b16d8 cmp r3, #0x70
 *   @0x2b16dc cmp r2, #0x1
 *   @0x2b16e0 ldr.w r3, [r4, #0x190]
 *   @0x2b16e4 movw r2, #0x3fff
 *   @0x2b16e8 cmp r3, r2
 *   @0x2b16ec ldr.w r1, [r4, #0x18c]
 *   @0x2b16f0 cmp r1, r2
 *   @0x2b16f4 ldrb.w r7, [r4, #0x1ee]
 *   @0x2b16f8 ldrb.w r2, [r4, #0x1eb]
 *   @0x2b16fc smulbb r7, r7, r2
 *   @0x2b1700 muls r7, r1, r7
 *   @0x2b1704 strlo r1, [pc, -r7, ror #3]
 *   @0x2b1708 lsrs r7, r7, #0x3
 *   @0x2b170c cbz r1, 0x2b171e <png_write_IDAT+0x7e>
 *   @0x2b1710 cmp r2, #0x7
 *   @0x2b1714 movhi r2, #0x6
 *   @0x2b1718 lsrs r3, r3, #0x3
 *   @0x2b171c ldmdbeq r1!, {r1, r8, r9, r10, r12, sp, lr}
 *   @0x2b1720 movs r0, #0x1
 *   @0x2b1724 lsls r0, r3
 *   @0x2b1728 bls 0x2b1752 <png_write_IDAT+0xb2>
 *   @0x2b172c orr r0, r1, #0x8
 *   @0x2b1730 uxtb r3, r0
 *   @0x2b1734 beq 0x2b1766 <png_write_IDAT+0xc6>
 *   @0x2b1738 movs r1, #0x1f
 *   @0x2b173c and r3, r3, #0xe0
 *   @0x2b1740 add.w r0, r3, r0, lsl #8
 *   @0x2b1744 add.w r6, r3, #0x1f
 *   @0x2b1748 blx 0x318cf0 <__aeabi_uidivmod>
 *   @0x2b174c subs r1, r6, r1
 *   @0x2b1750 b 0x2b1766 <png_write_IDAT+0xc6>
 *   @0x2b1754 bls 0x2b172a <png_write_IDAT+0x8a>
 *   @0x2b1758 lsrs r0, r0, #0x1
 *   @0x2b175c ldr r1, [pc, #0x28]
 *   @0x2b1760 add r1, pc
 *   @0x2b1764 strbmi pc, [r3], -r3, ror #28
 *   @0x2b1768 mov r0, r4
 *   @0x2b176c mov r2, r5
 *   @0x2b1770 .word 0xf8d4fda5
 *   @0x2b1774 .word 0xf043312c
 *   @0x2b1778 .word 0xf8c40304
 *   @0x2b177c andlt r3, r2, r12, lsr #2
 *   @0x2b1780 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2b1784 b 0x2b14f0 <png_write_IHDR+0x20c>
 *   @0x2b1788 ldm r4!, {r1, r2}
 *
 * ══ §94/127 FT_Remove_Module  0x2e9724  size 236  59 条（0x2e9724..0x2e9810）
 * @func 0x2e9724 0x2e9810  size 236  59 条
 * 部分覆盖: 本节 59/106 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_free×2 / FT_List_Find / FT_List_Remove / 0x66780e
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0x16×1 / 0xc×1 / 0x24×1 / 0x14×1 / 0x8×1 / 0x11×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9724 push.w {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2e9728 mov r4, r1
 *   @0x2e972c beq 0x2e97fa <FT_Remove_Module+0xd6>
 *   @0x2e9730 beq 0x2e9800 <FT_Remove_Module+0xdc>
 *   @0x2e9734 add.w r1, r0, #0x14
 *   @0x2e9738 add.w r2, r1, r5, lsl #2
 *   @0x2e973c cmp r1, r2
 *   @0x2e9740 bhs 0x2e9800 <FT_Remove_Module+0xdc>
 *   @0x2e9744 adds r1, r3, #0x4
 *   @0x2e9748 bne 0x2e973c <FT_Remove_Module+0x18>
 *   @0x2e974c str r5, [r0, #0x10]
 *   @0x2e9750 cmp r3, r0
 *   @0x2e9754 ldr r1, [r3, #0x4]
 *   @0x2e9758 ldrb r1, [r9, r4, lsl #22]!
 *   @0x2e975c movs r1, #0x0
 *   @0x2e9760 stmdavs r3!, {r2, r10, r11, r12} ^
 *   @0x2e9764 ldr.w r8, [r4, #0x8]
 *   @0x2e9768 ldr.w r9, [r4]
 *   @0x2e976c cbz r3, 0x2e977a <FT_Remove_Module+0x56>
 *   @0x2e9770 adcmi r2, r2, #160
 *   @0x2e9774 it eq
 *   @0x2e9778 stmdavs r3!, {r5, r7, r12}
 *   @0x2e977c ldr r3, [r3]
 *   @0x2e9780 bpl 0x2e97ca <FT_Remove_Module+0xa6>
 *   @0x2e9784 cbz r5, 0x2e97ca <FT_Remove_Module+0xa6>
 *   @0x2e9788 mov r1, r4
 *   @0x2e978c shadd8mi r10, r0, r4
 *   @0x2e9790 bl 0x2e890e <FT_List_Find>
 *   @0x2e9794 mov r7, r0
 *   @0x2e9798 ldr r2, [r4, #0xc]
 *   @0x2e979c ldr r3, [r2, #0x24]
 *   @0x2e97a0 bne 0x2e97ac <FT_Remove_Module+0x88>
 *   @0x2e97a4 cbz r0, 0x2e97ac <FT_Remove_Module+0x88>
 *   @0x2e97a8 ldr r2, [r2, #0x14]
 *   @0x2e97ac mov r0, r6
 *   @0x2e97b0 bl 0x2e89f2 <FT_List_Remove>
 *   @0x2e97b4 mov r0, r10
 *   @0x2e97b8 bl 0x2e7336 <ft_mem_free>
 *   @0x2e97bc mov r0, r5
 *   @0x2e97c0 movs r2, #0x0
 *   @0x2e97c4 .word 0xf8c5fb38
 *   @0x2e97c8 stmdavs r3!, {r2, r3, r4, r7}
 *   @0x2e97cc ldr r3, [r3]
 *   @0x2e97d0 bpl 0x2e97e2 <FT_Remove_Module+0xbe>
 *   @0x2e97d4 add.w r0, r4, #0x10
 *   @0x2e97d8 ldr r2, [r4, #0x8]
 *   @0x2e97dc add r1, pc
 *   @0x2e97e0 .word 0xf8d9f9a1
 *   @0x2e97e4 .word 0xb10b301c
 *   @0x2e97e8 mov r0, r4
 *   @0x2e97ec mov r0, r8
 *   @0x2e97f0 bl 0x2e7336 <ft_mem_free>
 *   @0x2e97f4 movs r0, #0x0
 *   @0x2e97f8 .word 0x202187f0
 *   @0x2e97fc pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2e9800 movs r0, #0x22
 *   @0x2e9804 svclt #0x87f0
 *   @0x2e9808 strb r4, [r5, #0x11]
 *   @0x2e980c bl 0x66780e <g_SWFlinevertbuff+0x14746>
 *
 * ══ §95/127 CSkeletonSprite::DrawCollisionBounds(spSkeletonBounds*)  0xbdd30  size 232  58 条（0xbdd30..0xbde18）
 * @func 0xbdd30 0xbde18  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Draw_Line(float, float, float, float)×5 / CSkeletonSprite::DrawCollisionBounds(spSkeletonBounds*)+0xd8
 * 字段偏移 top8: 0xc×3 / 0x10×3 / 0x18×3 / 0x14×3 / 0x4×2 / 0x8×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbdd30 ldr r0, [r1, #0xc]
 *   @0xbdd34 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xbdd38 mov r10, r1
 *   @0xbdd3c mov r2, r0
 *   @0xbdd40 ldr r1, [r1, #0x10]
 *   @0xbdd44 ldr r3, [r10, #0x18]
 *   @0xbdd48 bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0xbdd4c ldr r1, [r10, #0x18]
 *   @0xbdd50 ldr r0, [r10, #0xc]
 *   @0xbdd54 ldr r2, [r10, #0x14]
 *   @0xbdd58 mov r3, r1
 *   @0xbdd5c bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0xbdd60 ldr r0, [r10, #0x14]
 *   @0xbdd64 ldr r1, [r10, #0x18]
 *   @0xbdd68 ldr r3, [r10, #0x10]
 *   @0xbdd6c mov r2, r0
 *   @0xbdd70 bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0xbdd74 ldr r1, [r10, #0x10]
 *   @0xbdd78 ldr r0, [r10, #0x14]
 *   @0xbdd7c ldr r2, [r10, #0xc]
 *   @0xbdd80 mov r3, r1
 *   @0xbdd84 bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0xbdd88 ldr r3, [r10]
 *   @0xbdd8c cmp r3, #0
 *   @0xbdd90 pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xbdd94 mov r9, #0
 *   @0xbdd98 ldr r2, [r10, #0x8]
 *   @0xbdd9c ldr r7, [r2, r9, lsl #2]
 *   @0xbdda0 ldr r6, [r7, #0x4]
 *   @0xbdda4 add r6, r6, r6, lsr #31
 *   @0xbdda8 asr r6, r6, #1
 *   @0xbddac cmp r6, #0
 *   @0xbddb0 subgt r8, r6, #1
 *   @0xbddb4 movgt r4, #1
 *   @0xbddb8 movgt r5, #0
 *   @0xbddbc ble 0xbde08 <_ZN15CSkeletonSprite19DrawCollisionBoundsEP16spSkeletonBounds+0xd8>
 *   @0xbddc0 ldr r12, [r7]
 *   @0xbddc4 sub r3, r4, #1
 *   @0xbddc8 cmp r3, r8
 *   @0xbddcc mov r11, r4
 *   @0xbddd0 add r3, r12, r5
 *   @0xbddd4 addne r12, r12, r4, lsl #3
 *   @0xbddd8 ldreq r2, [r12]
 *   @0xbdddc add r5, r5, #8
 *   @0xbdde0 ldr r0, [r3]
 *   @0xbdde4 add r4, r4, #1
 *   @0xbdde8 ldr r1, [r3, #0x4]
 *   @0xbddec ldrne r2, [r12]
 *   @0xbddf0 ldreq r3, [r12, #0x4]
 *   @0xbddf4 ldrne r3, [r3, #0xc]
 *   @0xbddf8 bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0xbddfc cmp r6, r11
 *   @0xbde00 bgt 0xbddc0 <_ZN15CSkeletonSprite19DrawCollisionBoundsEP16spSkeletonBounds+0x90>
 *   @0xbde04 ldr r3, [r10]
 *   @0xbde08 add r9, r9, #1
 *   @0xbde0c cmp r3, r9
 *   @0xbde10 bgt 0xbdd98 <_ZN15CSkeletonSprite19DrawCollisionBoundsEP16spSkeletonBounds+0x68>
 *   @0xbde14 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §96/127 F_Vertex_TexCoord_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xc7e78  size 232  58 条（0xc7e78..0xc7f60）
 * @func 0xc7e78 0xc7f74  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / F_Vertex_TexCoord_release(RValue&, CInstance*, CInstance*, int, RValue*)+0xa8 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x18×2 / 0x14×2 / 0x10×2 / 0xd0×1 / 0x2×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc7e78 push {r4, r5, r6, lr}
 *   @0xc7e7c sub sp, sp, #8
 *   @0xc7e80 ldr r3, [pc, #0xd0]
 *   @0xc7e84 mov r1, #0
 *   @0xc7e88 ldr r5, [sp, #0x18]
 *   @0xc7e8c add r3, pc, r3
 *   @0xc7e90 mov r0, r5
 *   @0xc7e94 ldr r4, [r3]
 *   @0xc7e98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc7e9c ldr r4, [r4, r0, lsl #2]
 *   @0xc7ea0 ldr r1, [r4, #0x2c]
 *   @0xc7ea4 ldr r3, [r4, #0xc]
 *   @0xc7ea8 ldr r2, [r4, #0x4]
 *   @0xc7eac ldr r1, [r1, #0x14]
 *   @0xc7eb0 add r0, r1, r3
 *   @0xc7eb4 cmp r2, r0
 *   @0xc7eb8 blo 0xc7f20 <_Z25F_Vertex_TexCoord_releaseR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0xc7ebc ldr r6, [r4]
 *   @0xc7ec0 mov r0, r5
 *   @0xc7ec4 mov r1, #1
 *   @0xc7ec8 add r6, r6, r3
 *   @0xc7ecc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc7ed0 mov r1, #2
 *   @0xc7ed4 str r0, [r6]
 *   @0xc7ed8 mov r0, r5
 *   @0xc7edc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc7ee0 ldr r3, [r4, #0x10]
 *   @0xc7ee4 ldr r1, [r4, #0x14]
 *   @0xc7ee8 add r3, r3, #1
 *   @0xc7eec ldr r2, [r4, #0xc]
 *   @0xc7ef0 cmp r3, r1
 *   @0xc7ef4 add r2, r2, #8
 *   @0xc7ef8 str r0, [r6, #0x4]
 *   @0xc7efc str r3, [r4, #0x10]
 *   @0xc7f00 ldrhs r3, [r4, #0x1c]
 *   @0xc7f04 str r2, [r4, #0xc]
 *   @0xc7f08 movhs r2, #0
 *   @0xc7f0c addhs r3, r3, #1
 *   @0xc7f10 strhs r2, [r4, #0x10]
 *   @0xc7f14 strhs r3, [r4, #0x1c]
 *   @0xc7f18 add sp, sp, #8
 *   @0xc7f1c pop {r4, r5, r6, pc}
 *   @0xc7f20 add r1, r1, r2
 *   @0xc7f24 ldr r0, [r4]
 *   @0xc7f28 add r1, r1, r2, lsr #1
 *   @0xc7f2c mov r2, #0
 *   @0xc7f30 str r1, [r4, #0x4]
 *   @0xc7f34 mov r3, #74
 *   @0xc7f38 str r2, [sp]
 *   @0xc7f3c ldr r2, [pc, #0x18]
 *   @0xc7f40 add r2, pc, r2
 *   @0xc7f44 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc7f48 ldr r3, [r4, #0xc]
 *   @0xc7f4c mov r6, r0
 *   @0xc7f50 str r0, [r4]
 *   @0xc7f54 b 0xc7ec0 <_Z25F_Vertex_TexCoord_releaseR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0xc7f58 eorseq r2, r11, r8, lsr #5
 *   @0xc7f5c .word 0x002690f0
 *
 * ══ §97/127 F_Vertex_Float2_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xc7f60  size 232  58 条（0xc7f60..0xc8048）
 * @func 0xc7f60 0xc805c  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / F_Vertex_Float2_release(RValue&, CInstance*, CInstance*, int, RValue*)+0xa8 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x18×2 / 0x14×2 / 0x10×2 / 0xd0×1 / 0x2×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc7f60 push {r4, r5, r6, lr}
 *   @0xc7f64 sub sp, sp, #8
 *   @0xc7f68 ldr r3, [pc, #0xd0]
 *   @0xc7f6c mov r1, #0
 *   @0xc7f70 ldr r5, [sp, #0x18]
 *   @0xc7f74 add r3, pc, r3
 *   @0xc7f78 mov r0, r5
 *   @0xc7f7c ldr r4, [r3]
 *   @0xc7f80 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc7f84 ldr r4, [r4, r0, lsl #2]
 *   @0xc7f88 ldr r1, [r4, #0x2c]
 *   @0xc7f8c ldr r3, [r4, #0xc]
 *   @0xc7f90 ldr r2, [r4, #0x4]
 *   @0xc7f94 ldr r1, [r1, #0x14]
 *   @0xc7f98 add r0, r1, r3
 *   @0xc7f9c cmp r2, r0
 *   @0xc7fa0 blo 0xc8008 <_Z23F_Vertex_Float2_releaseR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0xc7fa4 ldr r6, [r4]
 *   @0xc7fa8 mov r0, r5
 *   @0xc7fac mov r1, #1
 *   @0xc7fb0 add r6, r6, r3
 *   @0xc7fb4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc7fb8 mov r1, #2
 *   @0xc7fbc str r0, [r6]
 *   @0xc7fc0 mov r0, r5
 *   @0xc7fc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc7fc8 ldr r3, [r4, #0x10]
 *   @0xc7fcc ldr r1, [r4, #0x14]
 *   @0xc7fd0 add r3, r3, #1
 *   @0xc7fd4 ldr r2, [r4, #0xc]
 *   @0xc7fd8 cmp r3, r1
 *   @0xc7fdc add r2, r2, #8
 *   @0xc7fe0 str r0, [r6, #0x4]
 *   @0xc7fe4 str r3, [r4, #0x10]
 *   @0xc7fe8 ldrhs r3, [r4, #0x1c]
 *   @0xc7fec str r2, [r4, #0xc]
 *   @0xc7ff0 movhs r2, #0
 *   @0xc7ff4 addhs r3, r3, #1
 *   @0xc7ff8 strhs r2, [r4, #0x10]
 *   @0xc7ffc strhs r3, [r4, #0x1c]
 *   @0xc8000 add sp, sp, #8
 *   @0xc8004 pop {r4, r5, r6, pc}
 *   @0xc8008 add r1, r1, r2
 *   @0xc800c ldr r0, [r4]
 *   @0xc8010 add r1, r1, r2, lsr #1
 *   @0xc8014 mov r2, #0
 *   @0xc8018 str r1, [r4, #0x4]
 *   @0xc801c mov r3, #74
 *   @0xc8020 str r2, [sp]
 *   @0xc8024 ldr r2, [pc, #0x18]
 *   @0xc8028 add r2, pc, r2
 *   @0xc802c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc8030 ldr r3, [r4, #0xc]
 *   @0xc8034 mov r6, r0
 *   @0xc8038 str r0, [r4]
 *   @0xc803c b 0xc7fa8 <_Z23F_Vertex_Float2_releaseR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0xc8040 eorseq r2, r11, r0, asr #3
 *   @0xc8044 eoreq r9, r6, r8
 *
 * ══ §98/127 F_Vertex_Position_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8048  size 232  58 条（0xc8048..0xc8130）
 * @func 0xc8048 0xc8130  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / F_Vertex_Position_release(RValue&, CInstance*, CInstance*, int, RValue*)+0xa8 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x18×2 / 0x14×2 / 0x10×2 / 0xd0×1 / 0x2×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8048 push {r4, r5, r6, lr}
 *   @0xc804c sub sp, sp, #8
 *   @0xc8050 ldr r3, [pc, #0xd0]
 *   @0xc8054 mov r1, #0
 *   @0xc8058 ldr r5, [sp, #0x18]
 *   @0xc805c add r3, pc, r3
 *   @0xc8060 mov r0, r5
 *   @0xc8064 ldr r4, [r3]
 *   @0xc8068 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc806c ldr r4, [r4, r0, lsl #2]
 *   @0xc8070 ldr r1, [r4, #0x2c]
 *   @0xc8074 ldr r3, [r4, #0xc]
 *   @0xc8078 ldr r2, [r4, #0x4]
 *   @0xc807c ldr r1, [r1, #0x14]
 *   @0xc8080 add r0, r1, r3
 *   @0xc8084 cmp r2, r0
 *   @0xc8088 blo 0xc80f0 <_Z25F_Vertex_Position_releaseR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0xc808c ldr r6, [r4]
 *   @0xc8090 mov r0, r5
 *   @0xc8094 mov r1, #1
 *   @0xc8098 add r6, r6, r3
 *   @0xc809c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc80a0 mov r1, #2
 *   @0xc80a4 str r0, [r6]
 *   @0xc80a8 mov r0, r5
 *   @0xc80ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc80b0 ldr r3, [r4, #0x10]
 *   @0xc80b4 ldr r1, [r4, #0x14]
 *   @0xc80b8 add r3, r3, #1
 *   @0xc80bc ldr r2, [r4, #0xc]
 *   @0xc80c0 cmp r3, r1
 *   @0xc80c4 add r2, r2, #8
 *   @0xc80c8 str r0, [r6, #0x4]
 *   @0xc80cc str r3, [r4, #0x10]
 *   @0xc80d0 ldrhs r3, [r4, #0x1c]
 *   @0xc80d4 str r2, [r4, #0xc]
 *   @0xc80d8 movhs r2, #0
 *   @0xc80dc addhs r3, r3, #1
 *   @0xc80e0 strhs r2, [r4, #0x10]
 *   @0xc80e4 strhs r3, [r4, #0x1c]
 *   @0xc80e8 add sp, sp, #8
 *   @0xc80ec pop {r4, r5, r6, pc}
 *   @0xc80f0 add r1, r1, r2
 *   @0xc80f4 ldr r0, [r4]
 *   @0xc80f8 add r1, r1, r2, lsr #1
 *   @0xc80fc mov r2, #0
 *   @0xc8100 str r1, [r4, #0x4]
 *   @0xc8104 mov r3, #74
 *   @0xc8108 str r2, [sp]
 *   @0xc810c ldr r2, [pc, #0x18]
 *   @0xc8110 add r2, pc, r2
 *   @0xc8114 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc8118 ldr r3, [r4, #0xc]
 *   @0xc811c mov r6, r0
 *   @0xc8120 str r0, [r4]
 *   @0xc8124 b 0xc8090 <_Z25F_Vertex_Position_releaseR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0xc8128 ldrsbteq r2, [r11], -r8
 *   @0xc812c eoreq r8, r6, r0, lsr #30
 *
 * ══ §99/127 IBuffer::Seek(eBuffer_Seek, int)  0xcb730  size 232  58 条（0xcb730..0xcb818）
 * @func 0xcb730 0xcb818  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_idivmod×3 / IBuffer::Seek(eBuffer_Seek, int)+0x48
 * 字段偏移 top8: 0x24×5 / 0x1c×3 / 0x10×2 / 0x14×2 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcb730 cmp r1, #1
 *   @0xcb734 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xcb738 mov r5, r0
 *   @0xcb73c beq 0xcb760 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0x30>
 *   @0xcb740 cmp r1, #2
 *   @0xcb744 beq 0xcb784 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0x54>
 *   @0xcb748 cmp r1, #0
 *   @0xcb74c streq r1, [r5, #0x24]
 *   @0xcb750 ldrne r0, [r0, #0x1c]
 *   @0xcb754 biceq r0, r2, r2, asr #31
 *   @0xcb758 streq r0, [r5, #0x1c]
 *   @0xcb75c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xcb760 ldr r3, [r0, #0x18]
 *   @0xcb764 ldr r4, [r0, #0x1c]
 *   @0xcb768 cmp r3, #2
 *   @0xcb76c addne r4, r2, r4
 *   @0xcb770 bicne r4, r4, r4, asr #31
 *   @0xcb774 beq 0xcb7a8 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0x78>
 *   @0xcb778 str r4, [r5, #0x1c]
 *   @0xcb77c mov r0, r4
 *   @0xcb780 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xcb784 ldr r3, [r0, #0x10]
 *   @0xcb788 bic r0, r2, r2, asr #31
 *   @0xcb78c mov r2, #0
 *   @0xcb790 str r2, [r5, #0x24]
 *   @0xcb794 cmp r0, r3
 *   @0xcb798 movge r0, r3
 *   @0xcb79c rsb r0, r0, r3
 *   @0xcb7a0 str r0, [r5, #0x1c]
 *   @0xcb7a4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xcb7a8 adds r4, r2, r4
 *   @0xcb7ac ldr r6, [r0, #0x10]
 *   @0xcb7b0 bpl 0xcb7e8 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0xb8>
 *   @0xcb7b4 ldr r8, [r0, #0x14]
 *   @0xcb7b8 ldr r7, [r0, #0x24]
 *   @0xcb7bc mov r0, r6
 *   @0xcb7c0 mov r1, r8
 *   @0xcb7c4 bl 0x318dec <__aeabi_idivmod>
 *   @0xcb7c8 rsb r9, r1, r8
 *   @0xcb7cc add r0, r7, r9
 *   @0xcb7d0 mov r1, r8
 *   @0xcb7d4 bl 0x318dec <__aeabi_idivmod>
 *   @0xcb7d8 adds r4, r4, r6
 *   @0xcb7dc mov r7, r1
 *   @0xcb7e0 bmi 0xcb7cc <_ZN7IBuffer4SeekE12eBuffer_Seeki+0x9c>
 *   @0xcb7e4 str r1, [r5, #0x24]
 *   @0xcb7e8 cmp r4, r6
 *   @0xcb7ec blt 0xcb778 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0x48>
 *   @0xcb7f0 ldr r7, [r5, #0x14]
 *   @0xcb7f4 ldr r1, [r5, #0x24]
 *   @0xcb7f8 add r0, r1, r6
 *   @0xcb7fc rsb r4, r6, r4
 *   @0xcb800 mov r1, r7
 *   @0xcb804 bl 0x318dec <__aeabi_idivmod>
 *   @0xcb808 cmp r4, r6
 *   @0xcb80c bge 0xcb7f8 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0xc8>
 *   @0xcb810 str r1, [r5, #0x24]
 *   @0xcb814 b 0xcb778 <_ZN7IBuffer4SeekE12eBuffer_Seeki+0x48>
 *
 * ══ §100/127 F_DsMapAdd_Internal(int, char*, long long, bool)  0x104e7c  size 232  58 条（0x104e7c..0x104f64）
 * @func 0x104e7c 0x104f64  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×2 / DS_AutoMutex::DS_AutoMutex() / YYSetString(RValue*, char const*) / CDS_Map::Add(RValue*, RValue*) / DS_AutoMutex::~DS_AutoMutex()
 * 字段偏移 top8: 0x24×3 / 0x14×2 / 0xa8×1 / 0x4×1 / 0x2×1 / 0x20×1 / 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x104e7c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x104e80 sub sp, sp, #44
 *   @0x104e84 add r8, sp, #4
 *   @0x104e88 add r7, sp, #8
 *   @0x104e8c mov r6, r1
 *   @0x104e90 mov r9, r0
 *   @0x104e94 mov r0, r8
 *   @0x104e98 mov r4, r2
 *   @0x104e9c mov r5, r3
 *   @0x104ea0 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x104ea4 mov r1, r6
 *   @0x104ea8 mov r0, r7
 *   @0x104eac bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x104eb0 ldr r3, [pc, #0xa8]
 *   @0x104eb4 add r6, sp, #40
 *   @0x104eb8 mov r0, #10
 *   @0x104ebc ldr r3, [pc, r3]
 *   @0x104ec0 str r0, [sp, #0x24]
 *   @0x104ec4 strd r4, r5, [r6, #-16]!
 *   @0x104ec8 mov r1, r7
 *   @0x104ecc ldr r3, [r3, #0x4]
 *   @0x104ed0 mov r2, r6
 *   @0x104ed4 ldr r0, [r3, r9, lsl #2]
 *   @0x104ed8 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x104edc ldr r3, [sp, #0x24]
 *   @0x104ee0 sub r3, r3, #1
 *   @0x104ee4 bic r3, r3, #-16777216
 *   @0x104ee8 bic r3, r3, #3
 *   @0x104eec cmp r3, #0
 *   @0x104ef0 mov r4, r0
 *   @0x104ef4 beq 0x104f54 <_Z19F_DsMapAdd_InternaliPcxb+0xd8>
 *   @0x104ef8 ldr r1, [sp, #0x14]
 *   @0x104efc mov r3, #0
 *   @0x104f00 str r3, [sp, #0x20]
 *   @0x104f04 mov r2, #5
 *   @0x104f08 sub r1, r1, #1
 *   @0x104f0c str r3, [sp, #0x18]
 *   @0x104f10 bic r3, r1, #-16777216
 *   @0x104f14 str r2, [sp, #0x24]
 *   @0x104f18 bic r3, r3, #3
 *   @0x104f1c cmp r3, #0
 *   @0x104f20 bne 0x104f2c <_Z19F_DsMapAdd_InternaliPcxb+0xb0>
 *   @0x104f24 mov r0, r7
 *   @0x104f28 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x104f2c mov r0, r8
 *   @0x104f30 mov r3, #0
 *   @0x104f34 mov r2, #5
 *   @0x104f38 str r3, [sp, #0x10]
 *   @0x104f3c str r3, [sp, #0x8]
 *   @0x104f40 str r2, [sp, #0x14]
 *   @0x104f44 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x104f48 mov r0, r4
 *   @0x104f4c add sp, sp, #44
 *   @0x104f50 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x104f54 mov r0, r6
 *   @0x104f58 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x104f5c b 0x104ef8 <_Z19F_DsMapAdd_InternaliPcxb+0x7c>
 *   @0x104f60 eoreq r8, lr, r0, lsl #21
 *
 * ══ §101/127 F_DsMapAdd_Internal(int, double, char*)  0x105048  size 232  58 条（0x105048..0x105130）
 * @func 0x105048 0x105130  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×2 / DS_AutoMutex::DS_AutoMutex() / YYSetString(RValue*, char const*) / CDS_Map::Add(RValue*, RValue*) / DS_AutoMutex::~DS_AutoMutex()
 * 字段偏移 top8: 0x14×3 / 0x24×2 / 0x48×1 / 0x9c×1 / 0x4×1 / 0x2×1 / 0x20×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x105048 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x10504c sub sp, sp, #44
 *   @0x105050 add r7, sp, #4
 *   @0x105054 add r6, sp, #24
 *   @0x105058 ldr r8, [sp, #0x48]
 *   @0x10505c mov r9, r0
 *   @0x105060 mov r0, r7
 *   @0x105064 mov r4, r2
 *   @0x105068 mov r5, r3
 *   @0x10506c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x105070 mov r1, r8
 *   @0x105074 mov r0, r6
 *   @0x105078 strd r4, r5, [sp, #8]
 *   @0x10507c mov r3, #0
 *   @0x105080 str r3, [sp, #0x14]
 *   @0x105084 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x105088 ldr r3, [pc, #0x9c]
 *   @0x10508c add r4, sp, #8
 *   @0x105090 mov r2, r6
 *   @0x105094 ldr r3, [pc, r3]
 *   @0x105098 mov r1, r4
 *   @0x10509c ldr r3, [r3, #0x4]
 *   @0x1050a0 ldr r0, [r3, r9, lsl #2]
 *   @0x1050a4 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x1050a8 ldr r3, [sp, #0x24]
 *   @0x1050ac sub r3, r3, #1
 *   @0x1050b0 bic r3, r3, #-16777216
 *   @0x1050b4 bic r3, r3, #3
 *   @0x1050b8 cmp r3, #0
 *   @0x1050bc mov r5, r0
 *   @0x1050c0 beq 0x105120 <_Z19F_DsMapAdd_InternalidPc+0xd8>
 *   @0x1050c4 ldr r1, [sp, #0x14]
 *   @0x1050c8 mov r3, #0
 *   @0x1050cc str r3, [sp, #0x20]
 *   @0x1050d0 mov r2, #5
 *   @0x1050d4 sub r1, r1, #1
 *   @0x1050d8 str r3, [sp, #0x18]
 *   @0x1050dc bic r3, r1, #-16777216
 *   @0x1050e0 str r2, [sp, #0x24]
 *   @0x1050e4 bic r3, r3, #3
 *   @0x1050e8 cmp r3, #0
 *   @0x1050ec bne 0x1050f8 <_Z19F_DsMapAdd_InternalidPc+0xb0>
 *   @0x1050f0 mov r0, r4
 *   @0x1050f4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1050f8 mov r0, r7
 *   @0x1050fc mov r3, #0
 *   @0x105100 mov r2, #5
 *   @0x105104 str r3, [sp, #0x10]
 *   @0x105108 str r3, [sp, #0x8]
 *   @0x10510c str r2, [sp, #0x14]
 *   @0x105110 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x105114 mov r0, r5
 *   @0x105118 add sp, sp, #44
 *   @0x10511c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x105120 mov r0, r6
 *   @0x105124 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x105128 b 0x1050c4 <_Z19F_DsMapAdd_InternalidPc+0x7c>
 *   @0x10512c eoreq r8, lr, r8, lsr #17
 *
 * ══ §102/127 F_PlaceSnapped(RValue&, CInstance*, CInstance*, int, RValue*)  0x108078  size 232  58 条（0x108078..0x108160）
 * @func 0x108078 0x108160  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2 / 0xb66e8×2 / F_PlaceSnapped(RValue&, CInstance*, CInstance*, int, RValue*)+0x84 / F_PlaceSnapped(RValue&, CInstance*, CInstance*, int, RValue*)+0xc4
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 30 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108078 push {r4, r5, r6, lr}
 *   @0x10807c vpush {d8, d9, d10}
 *   @0x108080 mov r3, #0
 *   @0x108084 ldr r5, [sp, #0x28]
 *   @0x108088 mov r4, r0
 *   @0x10808c str r3, [r0, #0xc]
 *   @0x108090 mov r6, r1
 *   @0x108094 str r3, [r0]
 *   @0x108098 mov r1, r3
 *   @0x10809c str r3, [r4, #0x4]
 *   @0x1080a0 mov r0, r5
 *   @0x1080a4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1080a8 vmov d8, r0, r1
 *   @0x1080ac mov r0, r5
 *   @0x1080b0 mov r1, #1
 *   @0x1080b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1080b8 vcmpe.f64 d8, #0
 *   @0x1080bc vmrs APSR_nzcv, fpscr
 *   @0x1080c0 vmov d9, r0, r1
 *   @0x1080c4 ble 0x1080fc <_Z14F_PlaceSnappedR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1080c8 vldr s20, [r6, #180]
 *   @0x1080cc vcvt.f64.f32 d10, s20
 *   @0x1080d0 vdiv.f64 d7, d10, d8
 *   @0x1080d4 vmov r0, r1, d7
 *   @0x1080d8 bl 0xb66e8 <lrint@plt>
 *   @0x1080dc vldr d7, [pc, #116]
 *   @0x1080e0 vmov s11, r0
 *   @0x1080e4 vcvt.f64.s32 d6, s11
 *   @0x1080e8 vmls.f64 d10, d6, d8
 *   @0x1080ec vabs.f64 d10, d10
 *   @0x1080f0 vcmpe.f64 d10, d7
 *   @0x1080f4 vmrs APSR_nzcv, fpscr
 *   @0x1080f8 bge 0x10814c <_Z14F_PlaceSnappedR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x1080fc vcmpe.f64 d9, #0
 *   @0x108100 vmrs APSR_nzcv, fpscr
 *   @0x108104 ble 0x10813c <_Z14F_PlaceSnappedR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x108108 vldr s16, [r6, #184]
 *   @0x10810c vcvt.f64.f32 d8, s16
 *   @0x108110 vdiv.f64 d7, d8, d9
 *   @0x108114 vmov r0, r1, d7
 *   @0x108118 bl 0xb66e8 <lrint@plt>
 *   @0x10811c vldr d7, [pc, #52]
 *   @0x108120 vmov s11, r0
 *   @0x108124 vcvt.f64.s32 d6, s11
 *   @0x108128 vmls.f64 d8, d6, d9
 *   @0x10812c vabs.f64 d8, d8
 *   @0x108130 vcmpe.f64 d8, d7
 *   @0x108134 vmrs APSR_nzcv, fpscr
 *   @0x108138 bge 0x10814c <_Z14F_PlaceSnappedR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x10813c mov r3, #0
 *   @0x108140 mov r2, r3
 *   @0x108144 movt r3, #0x3ff0
 *   @0x108148 stm r4, {r2, r3}
 *   @0x10814c vpop {d8, d9, d10}
 *   @0x108150 pop {r4, r5, r6, pc}
 *   @0x108154 nop
 *   @0x108158 rscsle r10, r1, #252, #18
 *   @0x10815c svclo #0x50624d
 *
 * ══ §103/127 F_SurfaceCreateSpecial(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c7a0  size 232  58 条（0x11c7a0..0x11c888）
 * @func 0x11c7a0 0x11c888  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / GR_Surface_Create_Special(int, int, int, int) / Debug_AddTag(eTagNameType, char const*, ...) / YYError(char const*, ...)
 * 字段偏移 top8: 0x20×1 / 0xc×1 / 0x70×1 / 0x4×1 / 0x4c×1 / 0x34×1 / 0x14×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c7a0 push {r4, r6, r7, r8, lr}
 *   @0x11c7a4 sub sp, sp, #12
 *   @0x11c7a8 mov r1, #0
 *   @0x11c7ac mov r6, r0
 *   @0x11c7b0 ldr r4, [sp, #0x20]
 *   @0x11c7b4 str r1, [r0, #0xc]
 *   @0x11c7b8 mov r0, r4
 *   @0x11c7bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c7c0 mov r1, #1
 *   @0x11c7c4 mov r8, r0
 *   @0x11c7c8 mov r0, r4
 *   @0x11c7cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c7d0 cmp r8, #0
 *   @0x11c7d4 cmpne r0, #0
 *   @0x11c7d8 mov r7, r0
 *   @0x11c7dc beq 0x11c868 <_Z22F_SurfaceCreateSpecialR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x11c7e0 mov r1, #2
 *   @0x11c7e4 mov r0, r4
 *   @0x11c7e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c7ec mov r1, r7
 *   @0x11c7f0 mvn r2, #0
 *   @0x11c7f4 mov r3, r0
 *   @0x11c7f8 mov r0, r8
 *   @0x11c7fc bl 0x171228 <_Z25GR_Surface_Create_Specialiiii>
 *   @0x11c800 ldr r12, [pc, #0x70]
 *   @0x11c804 ldr r12, [pc, r12]
 *   @0x11c808 vmov s15, r0
 *   @0x11c80c vcvt.f64.s32 d7, s15
 *   @0x11c810 vmov r0, r1, d7
 *   @0x11c814 vstr s14, [r6]
 *   @0x11c818 ldrb r3, [r12]
 *   @0x11c81c cmp r3, #0
 *   @0x11c820 str r1, [r6, #0x4]
 *   @0x11c824 beq 0x11c83c <_Z22F_SurfaceCreateSpecialR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x11c828 ldr r3, [pc, #0x4c]
 *   @0x11c82c ldr r3, [pc, r3]
 *   @0x11c830 ldr r3, [r3]
 *   @0x11c834 cmp r3, #0
 *   @0x11c838 beq 0x11c844 <_Z22F_SurfaceCreateSpecialR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x11c83c add sp, sp, #12
 *   @0x11c840 pop {r4, r6, r7, r8, pc}
 *   @0x11c844 ldr r1, [pc, #0x34]
 *   @0x11c848 vstr d7, [sp]
 *   @0x11c84c mov r2, r8
 *   @0x11c850 mov r3, r7
 *   @0x11c854 mov r0, #4
 *   @0x11c858 add r1, pc, r1
 *   @0x11c85c bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz>
 *   @0x11c860 add sp, sp, #12
 *   @0x11c864 pop {r4, r6, r7, r8, pc}
 *   @0x11c868 ldr r0, [pc, #0x14]
 *   @0x11c86c add r0, pc, r0
 *   @0x11c870 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x11c874 b 0x11c7e0 <_Z22F_SurfaceCreateSpecialR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x11c878 eoreq r1, sp, r0, lsr #2
 *   @0x11c87c .word 0x002d1bf4
 *   @0x11c880 eoreq sp, r1, r0, lsr r8
 *   @0x11c884 eoreq sp, r1, r0, ror #15
 *
 * ══ §104/127 F_SurfaceSavePart(RValue&, CInstance*, CInstance*, int, RValue*)  0x11efe8  size 232  58 条（0x11efe8..0x11f0d0）
 * @func 0x11efe8 0x11f0d0  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / YYGetString(RValue const*, int) / GR_Surface_Exists(int) / GR_Surface_Get_Texture(int) / GR_Texture_Get_Surface(int) / Graphics::Surface_GrabRect(void*, int, int, int, int) / WritePNG32(char*, void*, int, int)
 * 字段偏移 top8: 0x28×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11efe8 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x11efec sub sp, sp, #12
 *   @0x11eff0 mov r1, #0
 *   @0x11eff4 ldr r4, [sp, #0x28]
 *   @0x11eff8 mov r0, r4
 *   @0x11effc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f000 mov r1, #1
 *   @0x11f004 mov r5, r0
 *   @0x11f008 mov r0, r4
 *   @0x11f00c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11f010 mov r1, #2
 *   @0x11f014 mov r9, r0
 *   @0x11f018 mov r0, r4
 *   @0x11f01c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f020 mov r1, #3
 *   @0x11f024 mov r8, r0
 *   @0x11f028 mov r0, r4
 *   @0x11f02c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f030 mov r1, #4
 *   @0x11f034 mov r7, r0
 *   @0x11f038 mov r0, r4
 *   @0x11f03c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f040 mov r1, #5
 *   @0x11f044 mov r6, r0
 *   @0x11f048 mov r0, r4
 *   @0x11f04c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11f050 mov r4, r0
 *   @0x11f054 mov r0, r5
 *   @0x11f058 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11f05c subs r1, r0, #0
 *   @0x11f060 beq 0x11f0b0 <_Z17F_SurfaceSavePartR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x11f064 mov r0, r5
 *   @0x11f068 bl 0x17155c <_Z22GR_Surface_Get_Texturei>
 *   @0x11f06c bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x11f070 str r4, [sp]
 *   @0x11f074 mov r1, r8
 *   @0x11f078 mov r2, r7
 *   @0x11f07c mov r3, r6
 *   @0x11f080 bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii>
 *   @0x11f084 subs r5, r0, #0
 *   @0x11f088 beq 0x11f0c4 <_Z17F_SurfaceSavePartR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x11f08c mov r0, r9
 *   @0x11f090 mov r2, r6
 *   @0x11f094 mov r3, r4
 *   @0x11f098 mov r1, r5
 *   @0x11f09c bl 0x16cc8c <_Z10WritePNG32PcPvii>
 *   @0x11f0a0 mov r0, r5
 *   @0x11f0a4 add sp, sp, #12
 *   @0x11f0a8 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x11f0ac b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x11f0b0 ldr r0, [pc, #0x14]
 *   @0x11f0b4 add r0, pc, r0
 *   @0x11f0b8 add sp, sp, #12
 *   @0x11f0bc pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x11f0c0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11f0c4 add sp, sp, #12
 *   @0x11f0c8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x11f0cc .word 0x0021b1b4
 *
 * ══ §105/127 CreateArray(RValue*, int, ...)  0x120eb4  size 232  58 条（0x120eb4..0x120f9c）
 * @func 0x120eb4 0x120f9c  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / ARRAY_RefAlloc(void*) / CreateArray(RValue*, int, ...)+0xd0
 * 字段偏移 top8: 0x4×10 / 0xc×2 / 0x1c×1 / 0xb8×1 / 0x10×1 / 0x94×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120eb4 push {r1, r2, r3}
 *   @0x120eb8 mov r3, #2
 *   @0x120ebc push {r4, r5, r6, r7, lr}
 *   @0x120ec0 sub sp, sp, #8
 *   @0x120ec4 str r3, [r0, #0xc]
 *   @0x120ec8 mov r6, r0
 *   @0x120ecc ldr r7, [sp, #0x1c]
 *   @0x120ed0 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x120ed4 ldr r1, [pc, #0xb8]
 *   @0x120ed8 mov r5, #1
 *   @0x120edc mov r3, r5
 *   @0x120ee0 mov r2, #70
 *   @0x120ee4 add r1, pc, r1
 *   @0x120ee8 mov r4, r0
 *   @0x120eec mov r0, #8
 *   @0x120ef0 str r4, [r6]
 *   @0x120ef4 str r5, [r4, #0x10]
 *   @0x120ef8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x120efc ldr r1, [pc, #0x94]
 *   @0x120f00 mov r3, r5
 *   @0x120f04 mov r2, #1808
 *   @0x120f08 add r1, pc, r1
 *   @0x120f0c str r0, [r4, #0x4]
 *   @0x120f10 lsl r0, r7, #4
 *   @0x120f14 ldr r12, [r6]
 *   @0x120f18 add r4, sp, #32
 *   @0x120f1c ldr r5, [r12, #0x4]
 *   @0x120f20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x120f24 cmp r7, #0
 *   @0x120f28 str r0, [r5, #0x4]
 *   @0x120f2c ldr r3, [r6]
 *   @0x120f30 ldr r3, [r3, #0x4]
 *   @0x120f34 str r7, [r3]
 *   @0x120f38 str r4, [sp, #0x4]
 *   @0x120f3c ble 0x120f84 <_Z11CreateArrayP6RValueiz+0xd0>
 *   @0x120f40 mov r3, #0
 *   @0x120f44 mov r0, r3
 *   @0x120f48 ldr r1, [r6]
 *   @0x120f4c add r2, r4, #7
 *   @0x120f50 bic r2, r2, #7
 *   @0x120f54 add r4, r2, #8
 *   @0x120f58 ldr r1, [r1, #0x4]
 *   @0x120f5c ldr r5, [r2]
 *   @0x120f60 ldr r2, [r2, #0x4]
 *   @0x120f64 ldr r12, [r1, #0x4]
 *   @0x120f68 add r1, r12, r3, lsl #4
 *   @0x120f6c str r0, [r1, #0xc]
 *   @0x120f70 str r5, [r12, r3, lsl #4]
 *   @0x120f74 add r3, r3, #1
 *   @0x120f78 cmp r3, r7
 *   @0x120f7c str r2, [r1, #0x4]
 *   @0x120f80 bne 0x120f48 <_Z11CreateArrayP6RValueiz+0x94>
 *   @0x120f84 add sp, sp, #8
 *   @0x120f88 pop {r4, r5, r6, r7, lr}
 *   @0x120f8c add sp, sp, #12
 *   @0x120f90 bx lr
 *   @0x120f94 eoreq r0, r1, r12, asr #2
 *   @0x120f98 eoreq r9, r1, r8, asr #32
 *
 * ══ §106/127 F_GetString(RValue&, CInstance*, CInstance*, int, RValue*)  0x126ff0  size 232  58 条（0x126ff0..0x1270d8）
 * @func 0x126ff0 0x1270d8  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: InputQuery::Input(char const*, char const*, char const*, char*&)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / YYGetString(RValue const*, int) / DebuggerIsConnected() / IO_Clear() / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x4×4 / 0xc×2 / 0xd4×1 / 0x20×1 / 0x-8×1 / 0x58×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126ff0 ldr r1, [pc, #0xd4]
 *   @0x126ff4 mov r12, #16
 *   @0x126ff8 push {r4, r5, r6, lr}
 *   @0x126ffc sub sp, sp, #16
 *   @0x127000 add r1, pc, r1
 *   @0x127004 movw r2, #0x5b9
 *   @0x127008 mov r3, #1
 *   @0x12700c mov r6, r0
 *   @0x127010 mov r0, r12
 *   @0x127014 str r12, [sp]
 *   @0x127018 ldr r5, [sp, #0x20]
 *   @0x12701c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x127020 mov r4, #0
 *   @0x127024 mov r2, sp
 *   @0x127028 add r1, sp, #4
 *   @0x12702c mov r3, r0
 *   @0x127030 add r0, sp, #16
 *   @0x127034 str r3, [sp, #0x4]
 *   @0x127038 str r3, [r0, #-0x8]!
 *   @0x12703c strb r4, [r3]
 *   @0x127040 add r3, r5, #16
 *   @0x127044 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x127048 ldr r0, [sp, #0x4]
 *   @0x12704c bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x127050 mov r0, r5
 *   @0x127054 mov r1, r4
 *   @0x127058 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12705c str r4, [sp, #0xc]
 *   @0x127060 mov r5, r0
 *   @0x127064 bl 0x29cb74 <_Z19DebuggerIsConnectedv>
 *   @0x127068 cmp r0, r4
 *   @0x12706c bne 0x1270a4 <_Z11F_GetStringR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x127070 ldr r12, [pc, #0x58]
 *   @0x127074 mov r1, r5
 *   @0x127078 ldr r2, [sp, #0x4]
 *   @0x12707c add r3, sp, #12
 *   @0x127080 ldr r12, [pc, r12]
 *   @0x127084 ldr r0, [r12]
 *   @0x127088 bl 0xf28b0 <_ZN10InputQuery5InputEPKcS1_S1_RPc>
 *   @0x12708c bl 0x18c2c8 <_Z8IO_Clearv>
 *   @0x127090 mov r0, r6
 *   @0x127094 ldr r1, [sp, #0xc]
 *   @0x127098 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x12709c add sp, sp, #16
 *   @0x1270a0 pop {r4, r5, r6, pc}
 *   @0x1270a4 bl 0x29cb88 <_Z32DebuggerRunBackgroundMessageLoopv>
 *   @0x1270a8 ldr r0, [pc, #0x24]
 *   @0x1270ac mov r1, r5
 *   @0x1270b0 ldr r2, [sp, #0x4]
 *   @0x1270b4 ldr r0, [pc, r0]
 *   @0x1270b8 add r3, sp, #12
 *   @0x1270bc ldr r0, [r0]
 *   @0x1270c0 bl 0xf28b0 <_ZN10InputQuery5InputEPKcS1_S1_RPc>
 *   @0x1270c4 bl 0x29cc30 <_Z33DebuggerStopBackgroundMessageLoopv>
 *   @0x1270c8 b 0x12708c <_Z11F_GetStringR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1270cc eoreq r5, r1, r4, lsr r2
 *   @0x1270d0 eoreq r7, r12, r0, lsl #20
 *   @0x1270d4 eoreq r7, r12, r12, asr #19
 *
 * ══ §107/127 F_ActionIfAligned(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e9f8  size 232  58 条（0x13e9f8..0x13eae0）
 * @func 0x13e9f8 0x13eae0  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2 / 0xb66e8×2 / F_ActionIfAligned(RValue&, CInstance*, CInstance*, int, RValue*)+0x84 / F_ActionIfAligned(RValue&, CInstance*, CInstance*, int, RValue*)+0xc4
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 30 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e9f8 push {r4, r5, r6, lr}
 *   @0x13e9fc vpush {d8, d9, d10}
 *   @0x13ea00 mov r3, #0
 *   @0x13ea04 ldr r5, [sp, #0x28]
 *   @0x13ea08 mov r4, r0
 *   @0x13ea0c str r3, [r0, #0xc]
 *   @0x13ea10 mov r6, r1
 *   @0x13ea14 str r3, [r0]
 *   @0x13ea18 mov r1, r3
 *   @0x13ea1c str r3, [r4, #0x4]
 *   @0x13ea20 mov r0, r5
 *   @0x13ea24 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13ea28 vmov d8, r0, r1
 *   @0x13ea2c mov r0, r5
 *   @0x13ea30 mov r1, #1
 *   @0x13ea34 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13ea38 vcmpe.f64 d8, #0
 *   @0x13ea3c vmrs APSR_nzcv, fpscr
 *   @0x13ea40 vmov d9, r0, r1
 *   @0x13ea44 ble 0x13ea7c <_Z17F_ActionIfAlignedR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x13ea48 vldr s20, [r6, #180]
 *   @0x13ea4c vcvt.f64.f32 d10, s20
 *   @0x13ea50 vdiv.f64 d7, d10, d8
 *   @0x13ea54 vmov r0, r1, d7
 *   @0x13ea58 bl 0xb66e8 <lrint@plt>
 *   @0x13ea5c vldr d7, [pc, #116]
 *   @0x13ea60 vmov s11, r0
 *   @0x13ea64 vcvt.f64.s32 d6, s11
 *   @0x13ea68 vmls.f64 d10, d6, d8
 *   @0x13ea6c vabs.f64 d10, d10
 *   @0x13ea70 vcmpe.f64 d10, d7
 *   @0x13ea74 vmrs APSR_nzcv, fpscr
 *   @0x13ea78 bge 0x13eacc <_Z17F_ActionIfAlignedR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x13ea7c vcmpe.f64 d9, #0
 *   @0x13ea80 vmrs APSR_nzcv, fpscr
 *   @0x13ea84 ble 0x13eabc <_Z17F_ActionIfAlignedR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x13ea88 vldr s16, [r6, #184]
 *   @0x13ea8c vcvt.f64.f32 d8, s16
 *   @0x13ea90 vdiv.f64 d7, d8, d9
 *   @0x13ea94 vmov r0, r1, d7
 *   @0x13ea98 bl 0xb66e8 <lrint@plt>
 *   @0x13ea9c vldr d7, [pc, #52]
 *   @0x13eaa0 vmov s11, r0
 *   @0x13eaa4 vcvt.f64.s32 d6, s11
 *   @0x13eaa8 vmls.f64 d8, d6, d9
 *   @0x13eaac vabs.f64 d8, d8
 *   @0x13eab0 vcmpe.f64 d8, d7
 *   @0x13eab4 vmrs APSR_nzcv, fpscr
 *   @0x13eab8 bge 0x13eacc <_Z17F_ActionIfAlignedR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x13eabc mov r3, #0
 *   @0x13eac0 mov r2, r3
 *   @0x13eac4 movt r3, #0x3ff0
 *   @0x13eac8 stm r4, {r2, r3}
 *   @0x13eacc vpop {d8, d9, d10}
 *   @0x13ead0 pop {r4, r5, r6, pc}
 *   @0x13ead4 nop
 *   @0x13ead8 rscsle r10, r1, #252, #18
 *   @0x13eadc svclo #0x50624d
 *
 * ══ §108/127 CBitmap32::CBitmap32(IBitmap*, bool, bool, bool)  0x167188  size 232  58 条（0x167188..0x167270）
 * @func 0x167188 0x167270  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / CBitmap32::Assign(CBitmap32*)×2 / CBitmap32::CBitmap32(IBitmap*, bool, bool, int) / CBitmap32::CBitmap32(IBitmap*, bool, bool)
 * 字段偏移 top8: 0x4×3 / 0xd0×1 / 0x28×1 / 0x8×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167188 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x16718c sub sp, sp, #12
 *   @0x167190 mov r4, r0
 *   @0x167194 ldr r0, [pc, #0xd0]
 *   @0x167198 ldrb r12, [sp, #0x28]
 *   @0x16719c mov r5, #0
 *   @0x1671a0 ldr r0, [pc, r0]
 *   @0x1671a4 mov r9, r1
 *   @0x1671a8 cmp r12, #0
 *   @0x1671ac add r0, r0, #8
 *   @0x1671b0 mov r8, r2
 *   @0x1671b4 str r0, [r4]
 *   @0x1671b8 mov r7, r3
 *   @0x1671bc strb r5, [r4, #0x4]
 *   @0x1671c0 str r5, [r4, #0x8]
 *   @0x1671c4 mov r0, #24
 *   @0x1671c8 str r5, [r4, #0xc]
 *   @0x1671cc str r5, [r4, #0x10]
 *   @0x1671d0 str r5, [r4, #0x14]
 *   @0x1671d4 beq 0x167224 <_ZN9CBitmap32C2EP7IBitmapbbb+0x9c>
 *   @0x1671d8 bl 0x27c524 <_Znwj>
 *   @0x1671dc mov r1, r9
 *   @0x1671e0 mov r2, r8
 *   @0x1671e4 mov r3, r7
 *   @0x1671e8 str r5, [sp]
 *   @0x1671ec mov r6, r0
 *   @0x1671f0 bl 0x166fd0 <_ZN9CBitmap32C2EP7IBitmapbbi>
 *   @0x1671f4 mov r0, r4
 *   @0x1671f8 mov r1, r6
 *   @0x1671fc bl 0x165dac <_ZN9CBitmap326AssignEPS_>
 *   @0x167200 cmp r6, r5
 *   @0x167204 beq 0x167218 <_ZN9CBitmap32C2EP7IBitmapbbb+0x90>
 *   @0x167208 ldr r3, [r6]
 *   @0x16720c mov r0, r6
 *   @0x167210 ldr r3, [r3, #0x4]
 *   @0x167214 blx r3
 *   @0x167218 mov r0, r4
 *   @0x16721c add sp, sp, #12
 *   @0x167220 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x167224 bl 0x27c524 <_Znwj>
 *   @0x167228 mov r1, r9
 *   @0x16722c mov r2, r8
 *   @0x167230 mov r3, r7
 *   @0x167234 mov r5, r0
 *   @0x167238 bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb>
 *   @0x16723c mov r0, r4
 *   @0x167240 mov r1, r5
 *   @0x167244 bl 0x165dac <_ZN9CBitmap326AssignEPS_>
 *   @0x167248 cmp r5, #0
 *   @0x16724c beq 0x167218 <_ZN9CBitmap32C2EP7IBitmapbbb+0x90>
 *   @0x167250 ldr r3, [r5]
 *   @0x167254 mov r0, r5
 *   @0x167258 ldr r3, [r3, #0x4]
 *   @0x16725c blx r3
 *   @0x167260 mov r0, r4
 *   @0x167264 add sp, sp, #12
 *   @0x167268 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x16726c eoreq r8, r8, r8, asr pc
 *
 * ══ §109/127 GR_Draw_RoundRect(float, float, float, float, float, float, bool)  0x16b77c  size 232  58 条（0x16b77c..0x16b864）
 * @func 0x16b77c 0x16b864  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598×2 / _Draw_RoundRect(float, float, float, float, float, float, unsigned int, unsigned int, bool)
 * 字段偏移 top8: 0x38×1 / 0x3c×1 / 0x40×1 / 0x58×1 / 0x4×1 / 0x10×1 / 0x8×1 / 0xc×1
 * VFP 指令 38 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16b77c push {r4, r5, r6, lr}
 *   @0x16b780 vpush {d8, d9}
 *   @0x16b784 vmov s17, r2
 *   @0x16b788 vmov s19, r0
 *   @0x16b78c sub sp, sp, #24
 *   @0x16b790 vmov s16, r3
 *   @0x16b794 vcmpe.f32 s17, s19
 *   @0x16b798 ldr r6, [sp, #0x38]
 *   @0x16b79c vmov s18, r1
 *   @0x16b7a0 ldr r5, [sp, #0x3c]
 *   @0x16b7a4 ldrb r4, [sp, #0x40]
 *   @0x16b7a8 vmrs APSR_nzcv, fpscr
 *   @0x16b7ac vmovmi.f32 s15, s19
 *   @0x16b7b0 vmovmi.f32 s19, s17
 *   @0x16b7b4 vmovmi.f32 s17, s15
 *   @0x16b7b8 vcmpe.f32 s16, s18
 *   @0x16b7bc vcvt.f64.f32 d6, s17
 *   @0x16b7c0 vmrs APSR_nzcv, fpscr
 *   @0x16b7c4 vmovmi.f32 s15, s18
 *   @0x16b7c8 vmov r0, r1, d6
 *   @0x16b7cc vmovmi.f32 s18, s16
 *   @0x16b7d0 vmovmi.f32 s16, s15
 *   @0x16b7d4 bl 0xb6598 <floor@plt>
 *   @0x16b7d8 vmov d6, r0, r1
 *   @0x16b7dc vcvt.s32.f64 s15, d6
 *   @0x16b7e0 vcvt.f32.s32 s15, s15
 *   @0x16b7e4 vcmp.f32 s15, s17
 *   @0x16b7e8 vmrs APSR_nzcv, fpscr
 *   @0x16b7ec vldreq s15, [pc, #104]
 *   @0x16b7f0 vaddeq.f32 s17, s17, s15
 *   @0x16b7f4 vcvt.f64.f32 d7, s16
 *   @0x16b7f8 vmov r0, r1, d7
 *   @0x16b7fc bl 0xb6598 <floor@plt>
 *   @0x16b800 ldr r3, [pc, #0x58]
 *   @0x16b804 vmov r2, s17
 *   @0x16b808 ldr r3, [pc, r3]
 *   @0x16b80c ldr r12, [r3]
 *   @0x16b810 str r6, [sp]
 *   @0x16b814 str r5, [sp, #0x4]
 *   @0x16b818 str r4, [sp, #0x10]
 *   @0x16b81c str r12, [sp, #0x8]
 *   @0x16b820 str r12, [sp, #0xc]
 *   @0x16b824 vmov d6, r0, r1
 *   @0x16b828 vcvt.s32.f64 s15, d6
 *   @0x16b82c vmov r0, s19
 *   @0x16b830 vmov r1, s18
 *   @0x16b834 vcvt.f32.s32 s15, s15
 *   @0x16b838 vcmp.f32 s15, s16
 *   @0x16b83c vmrs APSR_nzcv, fpscr
 *   @0x16b840 vldreq s15, [pc, #20]
 *   @0x16b844 vaddeq.f32 s16, s16, s15
 *   @0x16b848 vmov r3, s16
 *   @0x16b84c bl 0x16b31c <_Z15_Draw_RoundRectffffffjjb>
 *   @0x16b850 add sp, sp, #24
 *   @0x16b854 vpop {d8, d9}
 *   @0x16b858 pop {r4, r5, r6, pc}
 *   @0x16b85c stclo p7, c13, [r3], #-40
 *   @0x16b860 .word 0x002824f4
 *
 * ══ §110/127 CCameraManager::Serialize(IBuffer*)  0x16e874  size 232  58 条（0x16e874..0x16e95c）
 * @func 0x16e874 0x16e95c  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCamera::Serialize(IBuffer*) / CCameraManager::Serialize(IBuffer*)+0xe4
 * 字段偏移 top8: 0x14×4 / 0x38×3 / 0x30×3 / 0x8×3 / 0x2c×2 / 0xc×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16e874 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x16e878 add r8, r1, #44
 *   @0x16e87c ldr r4, [r0, #0x14]
 *   @0x16e880 mov r6, r1
 *   @0x16e884 ldr r3, [r1]
 *   @0x16e888 mov r7, r0
 *   @0x16e88c mov r9, #0
 *   @0x16e890 mov r0, r1
 *   @0x16e894 vmov s15, r4
 *   @0x16e898 str r9, [r1, #0x38]
 *   @0x16e89c mov r2, r8
 *   @0x16e8a0 mov r1, #6
 *   @0x16e8a4 vcvt.f64.s32 d7, s15
 *   @0x16e8a8 vmov r4, r5, d7
 *   @0x16e8ac vstr s14, [r6, #44]
 *   @0x16e8b0 str r5, [r6, #0x30]
 *   @0x16e8b4 ldr r3, [r3, #0x8]
 *   @0x16e8b8 blx r3
 *   @0x16e8bc ldr r3, [r7, #0x14]
 *   @0x16e8c0 cmp r3, r9
 *   @0x16e8c4 pople {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x16e8c8 mov r10, r9
 *   @0x16e8cc mov r4, r9
 *   @0x16e8d0 movt r10, #0x3ff0
 *   @0x16e8d4 b 0x16e908 <_ZN14CCameraManager9SerializeEP7IBuffer+0x94>
 *   @0x16e8d8 str r9, [r6, #0x2c]
 *   @0x16e8dc add r4, r4, #1
 *   @0x16e8e0 str r10, [r6, #0x30]
 *   @0x16e8e4 str r9, [r6, #0x38]
 *   @0x16e8e8 ldr r3, [r3, #0x8]
 *   @0x16e8ec blx r3
 *   @0x16e8f0 mov r0, r5
 *   @0x16e8f4 mov r1, r6
 *   @0x16e8f8 bl 0x16e4f8 <_ZN7CCamera9SerializeEP7IBuffer>
 *   @0x16e8fc ldr r3, [r7, #0x14]
 *   @0x16e900 cmp r3, r4
 *   @0x16e904 ble 0x16e958 <_ZN14CCameraManager9SerializeEP7IBuffer+0xe4>
 *   @0x16e908 ldr r3, [r7, #0xc]
 *   @0x16e90c mov r0, r6
 *   @0x16e910 mov r2, r8
 *   @0x16e914 mov r1, #6
 *   @0x16e918 ldr r5, [r3, r4, lsl #2]
 *   @0x16e91c ldr r3, [r6]
 *   @0x16e920 cmp r5, #0
 *   @0x16e924 bne 0x16e8d8 <_ZN14CCameraManager9SerializeEP7IBuffer+0x64>
 *   @0x16e928 str r5, [r6, #0x2c]
 *   @0x16e92c mov r0, r6
 *   @0x16e930 str r5, [r6, #0x30]
 *   @0x16e934 mov r1, #6
 *   @0x16e938 ldr r3, [r3, #0x8]
 *   @0x16e93c mov r2, r8
 *   @0x16e940 str r5, [r6, #0x38]
 *   @0x16e944 add r4, r4, #1
 *   @0x16e948 blx r3
 *   @0x16e94c ldr r3, [r7, #0x14]
 *   @0x16e950 cmp r3, r4
 *   @0x16e954 bgt 0x16e908 <_ZN14CCameraManager9SerializeEP7IBuffer+0x94>
 *   @0x16e958 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §111/127 GraphicsPerf::EndDebugDraw()  0x17b3e4  size 232  58 条（0x17b3e4..0x17b4cc）
 * @func 0x17b3e4 0x17b4cc  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17b3f0→0x48ffe4, 0x17b404→0x4859c8, 0x17b408→0x499324, 0x17b424→0x49932a, 0x17b43c→0x499329, 0x17b454→0x499328, 0x17b47c→0x4a2088, 0x17b48c→0x4a2048
 * 调用序列: RenderStateManager::SetRenderState(eRenderState, unsigned int)×5 / Graphics::SetMatrix(eMatrix, float*)×2 / Graphics::SetTexture(int, void*)
 * 字段偏移 top8: 0xb4×2 / 0xa4×2 / 0x8c×1 / 0x78×1 / 0x64×1 / 0x40×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b3e4 push {r3, r4, r5, lr}
 *   @0x17b3e8 mov r1, #0
 *   @0x17b3ec ldr r4, [pc, #0xb4]
 *   @0x17b3f0 ldr r3, [pc, #0xb4]
 *   @0x17b3f4 add r4, pc, r4
 *   @0x17b3f8 ldr r3, [r4, r3]
 *   @0x17b3fc ldr r0, [r3]
 *   @0x17b400 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x17b404 ldr r2, [pc, #0xa4]
 *   @0x17b408 ldr r3, [pc, #0xa4]
 *   @0x17b40c mov r1, #8
 *   @0x17b410 ldr r5, [r4, r2]
 *   @0x17b414 ldr r3, [r4, r3]
 *   @0x17b418 mov r0, r5
 *   @0x17b41c ldr r2, [r3]
 *   @0x17b420 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17b424 ldr r3, [pc, #0x8c]
 *   @0x17b428 mov r0, r5
 *   @0x17b42c mov r1, #1
 *   @0x17b430 ldr r3, [r4, r3]
 *   @0x17b434 ldrb r2, [r3]
 *   @0x17b438 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17b43c ldr r3, [pc, #0x78]
 *   @0x17b440 mov r0, r5
 *   @0x17b444 mov r1, #21
 *   @0x17b448 ldr r3, [r4, r3]
 *   @0x17b44c ldrb r2, [r3]
 *   @0x17b450 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17b454 ldr r3, [pc, #0x64]
 *   @0x17b458 mov r0, r5
 *   @0x17b45c mov r1, #13
 *   @0x17b460 ldr r3, [r4, r3]
 *   @0x17b464 ldrb r2, [r3]
 *   @0x17b468 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17b46c mov r0, r5
 *   @0x17b470 mov r2, #1
 *   @0x17b474 mov r1, #12
 *   @0x17b478 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17b47c ldr r3, [pc, #0x40]
 *   @0x17b480 mov r0, #1
 *   @0x17b484 ldr r1, [r4, r3]
 *   @0x17b488 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x17b48c ldr r3, [pc, #0x34]
 *   @0x17b490 mov r0, #0
 *   @0x17b494 ldr r1, [r4, r3]
 *   @0x17b498 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x17b49c mov r0, r5
 *   @0x17b4a0 pop {r3, r4, r5, lr}
 *   @0x17b4a4 b 0x168050 <_ZN18RenderStateManager13RestoreStatesEv>
 *   @0x17b4a8 eoreq r6, r7, r12, asr r8
 *   @0x17b4ac .word 0xffffe4d4
 *   @0x17b4b0 .word 0xffffc0a8
 *   @0x17b4b4 .word 0xffffe6f8
 *   @0x17b4b8 .word 0xffffe6f4
 *   @0x17b4bc .word 0xffffe6fc
 *   @0x17b4c0 .word 0xffffe700
 *   @0x17b4c4 .word 0xffffe704
 *   @0x17b4c8 .word 0xffffe708
 *
 * ══ §112/127 LoadSave::freadreal(_YYFILE*, double*)  0x18df88  size 232  58 条（0x18df88..0x18e070）
 * @func 0x18df88 0x18e070  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::yyfeof(_YYFILE*) / 0xb6658 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x1c×3 / 0xc×2 / 0x10×2 / 0x-4×1 / 0x4×1 / 0x14×1 / 0x30×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18df88 push {r4, r5, r6, r7, lr}
 *   @0x18df8c sub sp, sp, #12
 *   @0x18df90 mov r4, r0
 *   @0x18df94 mov r5, r1
 *   @0x18df98 mov r0, r4
 *   @0x18df9c bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE>
 *   @0x18dfa0 subs r6, r0, #0
 *   @0x18dfa4 beq 0x18e008 <_ZN8LoadSave9freadrealEP7_YYFILEPd+0x80>
 *   @0x18dfa8 ldr r3, [r4]
 *   @0x18dfac add r1, sp, #8
 *   @0x18dfb0 mov r2, #0
 *   @0x18dfb4 str r2, [r1, #-0x4]!
 *   @0x18dfb8 ldr r0, [r3, #0xc]
 *   @0x18dfbc ldr r3, [r3, #0x1c]
 *   @0x18dfc0 add r0, r0, r3
 *   @0x18dfc4 bl 0xb6658 <strtod@plt>
 *   @0x18dfc8 ldr r3, [r4]
 *   @0x18dfcc ldr r2, [sp, #0x4]
 *   @0x18dfd0 ldr r12, [r3]
 *   @0x18dfd4 ldr r12, [r12, #0x10]
 *   @0x18dfd8 strd r0, r1, [r5]
 *   @0x18dfdc mov r0, r3
 *   @0x18dfe0 ldr r4, [r3, #0xc]
 *   @0x18dfe4 mov r1, #1
 *   @0x18dfe8 ldr r3, [r3, #0x1c]
 *   @0x18dfec add r4, r4, r3
 *   @0x18dff0 rsb r4, r4, r2
 *   @0x18dff4 mov r2, r4
 *   @0x18dff8 blx r12
 *   @0x18dffc mov r0, r4
 *   @0x18e000 add sp, sp, #12
 *   @0x18e004 pop {r4, r5, r6, r7, pc}
 *   @0x18e008 ldr r0, [r4]
 *   @0x18e00c mov r2, #1
 *   @0x18e010 add r7, r0, #44
 *   @0x18e014 ldr r12, [r0]
 *   @0x18e018 ldr r1, [r0, #0x1c]
 *   @0x18e01c mov r3, r7
 *   @0x18e020 ldr r12, [r12, #0x14]
 *   @0x18e024 blx r12
 *   @0x18e028 mov r1, r6
 *   @0x18e02c mov r0, r7
 *   @0x18e030 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x18e034 ldr r3, [pc, #0x30]
 *   @0x18e038 mov r1, #1
 *   @0x18e03c ldr r3, [pc, r3]
 *   @0x18e040 mov r2, r1
 *   @0x18e044 ldr r3, [r3]
 *   @0x18e048 uxtab r0, r3, r0
 *   @0x18e04c ldrb r3, [r0, #0x1]
 *   @0x18e050 tst r3, #8
 *   @0x18e054 beq 0x18dfa8 <_ZN8LoadSave9freadrealEP7_YYFILEPd+0x20>
 *   @0x18e058 ldr r0, [r4]
 *   @0x18e05c ldr r3, [r0]
 *   @0x18e060 ldr r3, [r3, #0x10]
 *   @0x18e064 blx r3
 *   @0x18e068 b 0x18df98 <_ZN8LoadSave9freadrealEP7_YYFILEPd+0x10>
 *   @0x18e06c eoreq pc, r5, r4, asr #18
 *
 * ══ §113/127 GMGamePad::SetGamePadCount(int)  0x18e4a4  size 232  58 条（0x18e4a4..0x18e58c）
 * @func 0x18e4a4 0x18e58c  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18e4b4→0x3eb708, 0x18e4dc→0x5356c4, 0x18e4f0→0x5356c0, 0x18e560→0x5356c0
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / GMGamePad::SetGamePadCount(int)+0xb0
 * 字段偏移 top8: 0xc0×1 / 0xbc×1 / 0xb4×1 / 0xc×1 / 0x9c×1 / 0x8c×1 / 0x88×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e4a4 push {r4, r5, r6, r7, lr}
 *   @0x18e4a8 mov r2, r0
 *   @0x18e4ac ldr r5, [pc, #0xc0]
 *   @0x18e4b0 mov r4, r0
 *   @0x18e4b4 ldr r3, [pc, #0xbc]
 *   @0x18e4b8 sub sp, sp, #12
 *   @0x18e4bc add r5, pc, r5
 *   @0x18e4c0 ldr r1, [pc, #0xb4]
 *   @0x18e4c4 ldr r3, [r5, r3]
 *   @0x18e4c8 add r1, pc, r1
 *   @0x18e4cc ldr r0, [r3]
 *   @0x18e4d0 ldr r3, [r0]
 *   @0x18e4d4 ldr r3, [r3, #0xc]
 *   @0x18e4d8 blx r3
 *   @0x18e4dc ldr r3, [pc, #0x9c]
 *   @0x18e4e0 ldr r6, [r5, r3]
 *   @0x18e4e4 ldr r3, [r6]
 *   @0x18e4e8 cmp r4, r3
 *   @0x18e4ec beq 0x18e560 <_ZN9GMGamePad15SetGamePadCountEi+0xbc>
 *   @0x18e4f0 ldr r0, [pc, #0x8c]
 *   @0x18e4f4 mov r3, #74
 *   @0x18e4f8 ldr r2, [pc, #0x88]
 *   @0x18e4fc mov r7, #0
 *   @0x18e500 lsl r1, r4, #2
 *   @0x18e504 ldr r5, [r5, r0]
 *   @0x18e508 add r2, pc, r2
 *   @0x18e50c str r7, [sp]
 *   @0x18e510 ldr r0, [r5]
 *   @0x18e514 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x18e518 ldr r3, [r6]
 *   @0x18e51c cmp r4, r3
 *   @0x18e520 str r0, [r5]
 *   @0x18e524 ble 0x18e554 <_ZN9GMGamePad15SetGamePadCountEi+0xb0>
 *   @0x18e528 lsl r1, r3, #2
 *   @0x18e52c mov r12, r0
 *   @0x18e530 mov r2, r7
 *   @0x18e534 b 0x18e53c <_ZN9GMGamePad15SetGamePadCountEi+0x98>
 *   @0x18e538 ldr r12, [r5]
 *   @0x18e53c add r3, r3, #1
 *   @0x18e540 str r2, [r12, r1]
 *   @0x18e544 cmp r3, r4
 *   @0x18e548 add r1, r1, #4
 *   @0x18e54c bne 0x18e538 <_ZN9GMGamePad15SetGamePadCountEi+0x94>
 *   @0x18e550 ldr r0, [r5]
 *   @0x18e554 str r4, [r6]
 *   @0x18e558 add sp, sp, #12
 *   @0x18e55c pop {r4, r5, r6, r7, pc}
 *   @0x18e560 ldr r3, [pc, #0x1c]
 *   @0x18e564 ldr r3, [r5, r3]
 *   @0x18e568 ldr r0, [r3]
 *   @0x18e56c add sp, sp, #12
 *   @0x18e570 pop {r4, r5, r6, r7, pc}
 *   @0x18e574 mlaeq r6, r4, r7, r3
 *   @0x18e578 .word 0xffffbcf0
 *   @0x18e57c andseq sp, r11, r0, asr lr
 *   @0x18e580 .word 0xffffde10
 *   @0x18e584 .word 0xffffde14
 *   @0x18e588 andseq sp, r11, r8, lsr lr
 *
 * ══ §114/127 YYObjectBase::MarkOnlyChildren4GC(unsigned int*, int)  0x191f84  size 232  58 条（0x191f84..0x19206c）
 * @func 0x191f84 0x19206c  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC_THISONLY(RValue const*, unsigned int*, int)×2 / YYObjectBase::MarkThisOnly4GC(unsigned int*, int) / YYObjectBase::MarkOnlyChildren4GC(unsigned int*, int)+0x9c
 * 字段偏移 top8: 0x4×3 / 0x60×2 / 0x24×2 / 0x18×1 / 0x10×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191f84 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x191f88 mov r6, r0
 *   @0x191f8c ldr r0, [r0, #0x18]
 *   @0x191f90 mov r7, r1
 *   @0x191f94 mov r8, r2
 *   @0x191f98 cmp r0, #0
 *   @0x191f9c beq 0x191fa4 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x20>
 *   @0x191fa0 bl 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji>
 *   @0x191fa4 ldr r2, [r6, #0x60]
 *   @0x191fa8 cmp r2, #0
 *   @0x191fac beq 0x192020 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x9c>
 *   @0x191fb0 ldr r3, [r2, #0x4]
 *   @0x191fb4 cmp r3, #0
 *   @0x191fb8 ble 0x192020 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x9c>
 *   @0x191fbc mov r4, #0
 *   @0x191fc0 mov r9, r4
 *   @0x191fc4 add r3, r4, r4, lsl #1
 *   @0x191fc8 ldr r1, [r2, #0x10]
 *   @0x191fcc ldr r5, [r2]
 *   @0x191fd0 add r3, r1, r3, lsl #2
 *   @0x191fd4 b 0x191fe4 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x60>
 *   @0x191fd8 ldr lr, [r12, #0x8]
 *   @0x191fdc cmp lr, #0
 *   @0x191fe0 bgt 0x192064 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0xe0>
 *   @0x191fe4 add r4, r4, #1
 *   @0x191fe8 mov r12, r3
 *   @0x191fec cmp r5, r4
 *   @0x191ff0 add r3, r3, #12
 *   @0x191ff4 bge 0x191fd8 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x54>
 *   @0x191ff8 mov r12, #0
 *   @0x191ffc mov r2, r8
 *   @0x192000 ldr r0, [r12]
 *   @0x192004 mov r1, r7
 *   @0x192008 add r9, r9, #1
 *   @0x19200c bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji>
 *   @0x192010 ldr r2, [r6, #0x60]
 *   @0x192014 ldr r3, [r2, #0x4]
 *   @0x192018 cmp r3, r9
 *   @0x19201c bgt 0x191fc4 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x40>
 *   @0x192020 ldr r4, [r6, #0x4]
 *   @0x192024 cmp r4, #0
 *   @0x192028 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19202c ldr r3, [r6, #0x24]
 *   @0x192030 cmp r3, #0
 *   @0x192034 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x192038 mov r5, #0
 *   @0x19203c mov r0, r4
 *   @0x192040 mov r1, r7
 *   @0x192044 mov r2, r8
 *   @0x192048 add r5, r5, #1
 *   @0x19204c bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji>
 *   @0x192050 ldr r3, [r6, #0x24]
 *   @0x192054 add r4, r4, #16
 *   @0x192058 cmp r3, r5
 *   @0x19205c bhi 0x19203c <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0xb8>
 *   @0x192060 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x192064 add r12, r12, #4
 *   @0x192068 b 0x191ffc <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x78>
 *
 * ══ §115/127 CScript::GetText()  0x1dfe94  size 232  58 条（0x1dfe94..0x1dff7c）
 * @func 0x1dfe94 0x1dff7c  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / operator new(unsigned int) / CStream::CStream(int) / CStream::CopyFrom(CStream*, long long, bool) / CStream::Decrypt(int, int, int) / CStream::SetPosition(int) / MemoryManager::Free(void const*) / CStream::ReadString(char const*&)
 * 字段偏移 top8: 0xc×5 / 0x4×2 / 0x10×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfe94 push {r4, r5, r6, lr}
 *   @0x1dfe98 sub sp, sp, #16
 *   @0x1dfe9c ldr r4, [r0, #0x10]
 *   @0x1dfea0 mov r5, r0
 *   @0x1dfea4 cmp r4, #0
 *   @0x1dfea8 str r4, [sp, #0xc]
 *   @0x1dfeac movne r0, r4
 *   @0x1dfeb0 beq 0x1dfebc <_ZN7CScript7GetTextEv+0x28>
 *   @0x1dfeb4 add sp, sp, #16
 *   @0x1dfeb8 pop {r4, r5, r6, pc}
 *   @0x1dfebc ldr r1, [pc, #0xb4]
 *   @0x1dfec0 mov r0, #1
 *   @0x1dfec4 mov r3, r0
 *   @0x1dfec8 mov r2, #234
 *   @0x1dfecc add r1, pc, r1
 *   @0x1dfed0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1dfed4 str r0, [sp, #0xc]
 *   @0x1dfed8 strb r4, [r0]
 *   @0x1dfedc ldr r3, [r5, #0x4]
 *   @0x1dfee0 cmp r3, #0
 *   @0x1dfee4 beq 0x1dff70 <_ZN7CScript7GetTextEv+0xdc>
 *   @0x1dfee8 mov r0, #32
 *   @0x1dfeec bl 0x27c524 <_Znwj>
 *   @0x1dfef0 mov r1, r4
 *   @0x1dfef4 mov r6, r0
 *   @0x1dfef8 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x1dfefc mov r12, #1
 *   @0x1dff00 ldr r1, [r5, #0x4]
 *   @0x1dff04 mov r2, #0
 *   @0x1dff08 str r12, [sp]
 *   @0x1dff0c mov r3, #0
 *   @0x1dff10 mov r0, r6
 *   @0x1dff14 bl 0x2015c8 <_ZN7CStream8CopyFromEPS_xb>
 *   @0x1dff18 mov r0, r6
 *   @0x1dff1c movw r1, #0x3039
 *   @0x1dff20 mov r2, r4
 *   @0x1dff24 mov r3, r4
 *   @0x1dff28 bl 0x202380 <_ZN7CStream7DecryptEiii>
 *   @0x1dff2c mov r0, r6
 *   @0x1dff30 mov r1, r4
 *   @0x1dff34 bl 0x201148 <_ZN7CStream11SetPositionEi>
 *   @0x1dff38 ldr r0, [sp, #0xc]
 *   @0x1dff3c cmp r0, #0
 *   @0x1dff40 beq 0x1dff4c <_ZN7CScript7GetTextEv+0xb8>
 *   @0x1dff44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1dff48 str r4, [sp, #0xc]
 *   @0x1dff4c mov r0, r6
 *   @0x1dff50 add r1, sp, #12
 *   @0x1dff54 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0x1dff58 cmp r6, #0
 *   @0x1dff5c beq 0x1dff70 <_ZN7CScript7GetTextEv+0xdc>
 *   @0x1dff60 mov r0, r6
 *   @0x1dff64 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x1dff68 mov r0, r6
 *   @0x1dff6c bl 0x27d1d0 <_ZdlPv>
 *   @0x1dff70 ldr r0, [sp, #0xc]
 *   @0x1dff74 b 0x1dfeb4 <_ZN7CScript7GetTextEv+0x20>
 *   @0x1dff78 andseq r1, r7, r0, lsl #28
 *
 * ══ §116/127 Audio_StopSound(int)  0x21a210  size 232  58 条（0x21a210..0x21a2f8）
 * @func 0x21a210 0x21a2f8  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_StopSound(int)+0xb8 / Audio_StopSoundNoise(CNoise*, bool) / Audio_GetNoiseFromID(int)
 * 字段偏移 top8: 0x38×2 / 0xc8×1 / 0xb0×1 / 0xa0×1 / 0x90×1 / 0x80×1 / 0x7c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21a210 ldr r3, [pc, #0xc8]
 *   @0x21a214 push {r4, r5, r6, r7, r8, lr}
 *   @0x21a218 ldr r3, [pc, r3]
 *   @0x21a21c mov r5, r0
 *   @0x21a220 ldrb r4, [r3]
 *   @0x21a224 cmp r4, #0
 *   @0x21a228 popne {r4, r5, r6, r7, r8, pc}
 *   @0x21a22c ldr r3, [pc, #0xb0]
 *   @0x21a230 ldr r3, [pc, r3]
 *   @0x21a234 ldrb r3, [r3]
 *   @0x21a238 cmp r3, #0
 *   @0x21a23c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x21a240 ldr r3, [pc, #0xa0]
 *   @0x21a244 ldr r3, [pc, r3]
 *   @0x21a248 ldr r3, [r3]
 *   @0x21a24c cmp r3, r0
 *   @0x21a250 ble 0x21a2c8 <_Z15Audio_StopSoundi+0xb8>
 *   @0x21a254 ldr r3, [pc, #0x90]
 *   @0x21a258 add r3, pc, r3
 *   @0x21a25c ldr r6, [r3, #0x38]
 *   @0x21a260 cmp r6, #0
 *   @0x21a264 pople {r4, r5, r6, r7, r8, pc}
 *   @0x21a268 ldr r8, [pc, #0x80]
 *   @0x21a26c mov r3, r6
 *   @0x21a270 ldr r7, [pc, #0x7c]
 *   @0x21a274 add r8, pc, r8
 *   @0x21a278 add r7, pc, r7
 *   @0x21a27c b 0x21a28c <_Z15Audio_StopSoundi+0x7c>
 *   @0x21a280 cmp r4, r6
 *   @0x21a284 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x21a288 ldr r3, [r7, #0x38]
 *   @0x21a28c cmp r3, r4
 *   @0x21a290 mov r0, #0
 *   @0x21a294 ldrgt r3, [r8, #0x3c]
 *   @0x21a298 ldrgt r0, [r3, r4, lsl #2]
 *   @0x21a29c add r4, r4, #1
 *   @0x21a2a0 ldr r2, [r0, #0x18]
 *   @0x21a2a4 cmp r2, r5
 *   @0x21a2a8 bne 0x21a280 <_Z15Audio_StopSoundi+0x70>
 *   @0x21a2ac ldrb r1, [r0, #0xd]
 *   @0x21a2b0 cmp r1, #0
 *   @0x21a2b4 bne 0x21a280 <_Z15Audio_StopSoundi+0x70>
 *   @0x21a2b8 bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb>
 *   @0x21a2bc cmp r4, r6
 *   @0x21a2c0 bne 0x21a288 <_Z15Audio_StopSoundi+0x78>
 *   @0x21a2c4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x21a2c8 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x21a2cc cmp r0, #0
 *   @0x21a2d0 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x21a2d4 mov r1, r4
 *   @0x21a2d8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x21a2dc b 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb>
 *   @0x21a2e0 andseq r4, sp, r4, lsr lr
 *   @0x21a2e4 andseq r4, sp, r0, lsl #22
 *   @0x21a2e8 andseq r7, sp, r0, lsr #3
 *   @0x21a2ec subseq r11, r3, r12, lsr r0
 *   @0x21a2f0 subseq r11, r3, r0, lsr #32
 *   @0x21a2f4 subseq r11, r3, r12, lsl r0
 *
 * ══ §117/127 F_JSNewProperty(RValue&, CInstance*, CInstance*, int, RValue*)  0x23c81c  size 232  58 条（0x23c81c..0x23c904）
 * @func 0x23c81c 0x23c904  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×4 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / YYObjectBase::Alloc(unsigned int, int, bool)
 * 字段偏移 top8: 0x4×4 / 0x10×3 / 0xc×3 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c81c push {r4, r5, r6, lr}
 *   @0x23c820 mvn r1, #-16777216
 *   @0x23c824 mov r6, r0
 *   @0x23c828 mov r2, #0
 *   @0x23c82c mov r0, #2
 *   @0x23c830 ldr r5, [sp, #0x10]
 *   @0x23c834 bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0x23c838 mov r3, #2
 *   @0x23c83c str r3, [r0, #0x48]
 *   @0x23c840 mov r4, r0
 *   @0x23c844 str r0, [r6]
 *   @0x23c848 mov r3, #6
 *   @0x23c84c ldr r1, [r0, #0x4]
 *   @0x23c850 str r3, [r6, #0xc]
 *   @0x23c854 cmp r1, #0
 *   @0x23c858 beq 0x23c8c8 <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x23c85c ldr r3, [r5, #0x10]
 *   @0x23c860 mov r0, r4
 *   @0x23c864 str r3, [r1]
 *   @0x23c868 ldr r1, [r5, #0x10]
 *   @0x23c86c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x23c870 ldr r1, [r4, #0x4]
 *   @0x23c874 cmp r1, #0
 *   @0x23c878 movne r3, #11
 *   @0x23c87c strne r3, [r1, #0xc]
 *   @0x23c880 beq 0x23c8d4 <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x23c884 add r1, r1, #16
 *   @0x23c888 ldr r3, [r5]
 *   @0x23c88c mov r0, r4
 *   @0x23c890 str r3, [r1]
 *   @0x23c894 ldr r1, [r5]
 *   @0x23c898 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x23c89c ldr r0, [r4, #0x4]
 *   @0x23c8a0 cmp r0, #0
 *   @0x23c8a4 beq 0x23c8b8 <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x23c8a8 add r0, r0, #16
 *   @0x23c8ac mov r3, #11
 *   @0x23c8b0 str r3, [r0, #0xc]
 *   @0x23c8b4 pop {r4, r5, r6, pc}
 *   @0x23c8b8 mov r0, r4
 *   @0x23c8bc mov r1, #1
 *   @0x23c8c0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x23c8c4 b 0x23c8ac <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x23c8c8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x23c8cc mov r1, r0
 *   @0x23c8d0 b 0x23c85c <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x23c8d4 mov r0, r4
 *   @0x23c8d8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x23c8dc ldr r1, [r4, #0x4]
 *   @0x23c8e0 mov r3, #11
 *   @0x23c8e4 cmp r1, #0
 *   @0x23c8e8 str r3, [r0, #0xc]
 *   @0x23c8ec bne 0x23c884 <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x23c8f0 mov r1, #1
 *   @0x23c8f4 mov r0, r4
 *   @0x23c8f8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x23c8fc mov r1, r0
 *   @0x23c900 b 0x23c888 <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0x6c>
 *
 * ══ §118/127 add_nanbits_D2A  0x23f5dc  size 232  58 条（0x23f5dc..0x23f6c4）
 * @func 0x23f5dc 0x23f6c4  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: add_nanbits_D2A+0xd8 / add_nanbits_D2A+0xa4
 * 字段偏移 top8: 0x-1×4 / 0x-4×1 / 0x-2×1 / 0x74×1 / 0x4×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23f5dc push {r4, r5, r6, r7, r8, r9}
 *   @0x23f5e0 add r4, r2, r3, lsl #2
 *   @0x23f5e4 b 0x23f5f0 <add_nanbits_D2A+0x14>
 *   @0x23f5e8 cmp r3, #0
 *   @0x23f5ec beq 0x23f6b4 <add_nanbits_D2A+0xd8>
 *   @0x23f5f0 ldr r12, [r4, #-0x4]
 *   @0x23f5f4 sub r6, r4, #4
 *   @0x23f5f8 sub r3, r3, #1
 *   @0x23f5fc cmp r12, #0
 *   @0x23f600 mov r4, r6
 *   @0x23f604 beq 0x23f5e8 <add_nanbits_D2A+0xc>
 *   @0x23f608 lsl r4, r3, #3
 *   @0x23f60c add r4, r4, #3
 *   @0x23f610 lsrs r12, r12, #4
 *   @0x23f614 add r4, r4, #1
 *   @0x23f618 bne 0x23f610 <add_nanbits_D2A+0x34>
 *   @0x23f61c cmp r1, r4
 *   @0x23f620 blo 0x23f6b4 <add_nanbits_D2A+0xd8>
 *   @0x23f624 add r7, r0, r4
 *   @0x23f628 cmp r3, #0
 *   @0x23f62c mov r1, #41
 *   @0x23f630 sub r8, r7, #2
 *   @0x23f634 strb r12, [r7, #-0x1]
 *   @0x23f638 strb r1, [r7, #-0x2]
 *   @0x23f63c ble 0x23f680 <add_nanbits_D2A+0xa4>
 *   @0x23f640 ldr r5, [pc, #0x74]
 *   @0x23f644 add r9, r2, r3, lsl #2
 *   @0x23f648 mov r1, r8
 *   @0x23f64c add r5, pc, r5
 *   @0x23f650 ldr r0, [r2], #4
 *   @0x23f654 sub r4, r1, #8
 *   @0x23f658 and r12, r0, #15
 *   @0x23f65c lsr r0, r0, #4
 *   @0x23f660 ldrb r12, [r5, r12]
 *   @0x23f664 strb r12, [r1, #-0x1]!
 *   @0x23f668 cmp r4, r1
 *   @0x23f66c bne 0x23f658 <add_nanbits_D2A+0x7c>
 *   @0x23f670 cmp r2, r9
 *   @0x23f674 mov r1, r4
 *   @0x23f678 bne 0x23f650 <add_nanbits_D2A+0x74>
 *   @0x23f67c sub r8, r8, r3, lsl #3
 *   @0x23f680 ldr r0, [pc, #0x38]
 *   @0x23f684 sub r2, r8, #1
 *   @0x23f688 ldr r3, [r6]
 *   @0x23f68c add r0, pc, r0
 *   @0x23f690 and r1, r3, #15
 *   @0x23f694 lsrs r3, r3, #4
 *   @0x23f698 mov r12, r2
 *   @0x23f69c ldrb r1, [r0, r1]
 *   @0x23f6a0 strb r1, [r2], #-1
 *   @0x23f6a4 bne 0x23f690 <add_nanbits_D2A+0xb4>
 *   @0x23f6a8 sub r0, r7, #1
 *   @0x23f6ac mov r3, #40
 *   @0x23f6b0 strb r3, [r12, #-0x1]
 *   @0x23f6b4 pop {r4, r5, r6, r7, r8, r9}
 *   @0x23f6b8 bx lr
 *   @0x23f6bc andseq r5, r1, r12, lsr #27
 *   @0x23f6c0 andseq r5, r1, r12, ror #26
 *
 * ══ §119/127 anon_2aba80  0x2aba80  size 232  58 条（0x2aba80..0x2abb68）
 * @func 0x2aba80 0x2abb68  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xfe9e8ea4 / 0xff421f0c / 0x4ac310
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aba80 svcmi #0xf0e92d
 *   @0x2aba84 ldmdami r5!, {r2, r9, r10, lr}
 *   @0x2aba88 ldrmi r11, [r8], pc, lsl #1
 *   @0x2aba8c blvc 0xfe9e8ea4 <b2_toiTime+0xfffffffffe28fa00>
 *   @0x2aba90 stmdavs r0, {r3, r4, r5, r6, r10, lr}
 *   @0x2aba94 .word 0xa060f8dd
 *   @0x2aba98 .word 0xf8c42500
 *   @0x2aba9c stmdavs r3, {r3, r4, r5, r8, r12}
 *   @0x2abaa0 .word 0xf8c44681
 *   @0x2abaa4 movwls r2, #0xd13c
 *   @0x2abaa8 ldrsblo pc, [r0, #-132]!
 *   @0x2abaac qaddhs r4, r8, r0
 *   @0x2abab0 smlalbtlo pc, r4, r4, r8
 *   @0x2abab4 ldrsblo pc, [r4, #-132]!
 *   @0x2abab8 smlalbtlo pc, r8, r4, r8
 *   @0x2ababc svc #0x8ef60a
 *   @0x2abac0 ldrsbvc pc, [r4, #-132]!
 *   @0x2abac4 .word 0x3148f8d4
 *   @0x2abac8 strmi r2, [r6], -r1, lsl #16
 *   @0x2abacc bne 0x2a1b2c <_Z10BeginToEndv+0x320>
 *   @0x2abad0 ldcle p15, c2, [r0, #-0]
 *   @0x2abad4 svceq #0xf1b8
 *   @0x2abad8 strmi sp, [r10, #0xc]!
 *   @0x2abadc bl 0xff421f0c <b2_toiTime+0xfffffffffecc8a68>
 *   @0x2abae0 bl 0x4ac310 <SrcVerts+0x9354>
 *   @0x2abae4 .word 0xf8d40005
 *   @0x2abae8 adcsmi r1, r10, #112, #2
 *   @0x2abaec ldrtmi r11, [r10], -r8, lsr #30
 *   @0x2abaf0 stcl p6, c15, [r4, #-40]!
 *   @0x2abaf4 mcrhs p4, #0x0, r4, c0, c13, #0x1
 *   @0x2abaf8 .word 0x2601d0d6
 *   @0x2abafc ldrbmi r2, [r8], -r0, lsl #14
 *   @0x2abb00 teqvc r12, r4, asr #17
 *   @0x2abb04 b 0x9e9338 <b2_toiTime+0x28fe94>
 *   @0x2abb08 andsle r2, r10, r1, lsl #28
 *   @0x2abb0c ldrsblo pc, [r0, #-132]
 *   @0x2abb10 ldclne p9, c11, [r3, #-812]!
 *   @0x2abb14 strlo sp, [r3], -r4
 *   @0x2abb18 bmi 0x71fb34 <g_SWFvertbuff+0x4ca6c>
 *   @0x2abb1c and r4, r4, r10, ror r4
 *   @0x2abb20 ldrbtmi r4, [r10], #-2576
 *   @0x2abb24 bmi 0x6e3b30 <g_SWFvertbuff+0x10a68>
 *   @0x2abb28 teqhs r4, r10, ror r4
 *   @0x2abb2c mvnsvc pc, #4, #10
 *   @0x2abb30 .word 0xf60a4668
 *   @0x2abb34 strtmi lr, [r0], -r10, asr #26
 *   @0x2abb38 .word 0xf7fa4669
 *   @0x2abb3c mulhs r0, r11, r12
 *   @0x2abb40 strtmi lr, [r8], -r2
 *   @0x2abb44 ldrtmi lr, [r8], -r0
 *   @0x2abb48 .word 0xf8d99a0d
 *   @0x2abb4c addsmi r3, r10, #0
 *   @0x2abb50 .word 0xf60ad001
 *   @0x2abb54 andlt lr, pc, r0, asr #26
 *   @0x2abb58 svchi #0xf0e8bd
 *   @0x2abb5c andseq r1, r4, r4, asr #29
 *   @0x2abb60 andeq r1, lr, r8, lsr r0
 *   @0x2abb64 ldrdeq r0, r1, [lr], -r0
 *
 * ══ §120/127 jpeg_read_raw_data  0x2b3698  size 232  58 条（0x2b3698..0x2b3780）
 * @func 0x2b3698 0x2b3780  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×4 / 0x8×2 / 0x4×2 / 0x18×1 / 0x78×1 / 0x60×1 / 0x114×1 / 0x118×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b3698 push {r3, r4, r5, r6, r7, lr}
 *   @0x2b369c mov r4, r0
 *   @0x2b36a0 ldr r3, [r0, #0x14]
 *   @0x2b36a4 mov r6, r1
 *   @0x2b36a8 mov r7, r2
 *   @0x2b36ac cmp r3, #206
 *   @0x2b36b0 beq 0x2b36d0 <jpeg_read_raw_data+0x38>
 *   @0x2b36b4 ldr r2, [r0]
 *   @0x2b36b8 mov r1, #20
 *   @0x2b36bc str r3, [r2, #0x18]
 *   @0x2b36c0 ldr r3, [r0]
 *   @0x2b36c4 str r1, [r2, #0x14]
 *   @0x2b36c8 ldr r3, [r3]
 *   @0x2b36cc blx r3
 *   @0x2b36d0 ldr r0, [r4, #0x78]
 *   @0x2b36d4 ldr r12, [r4, #0x60]
 *   @0x2b36d8 cmp r0, r12
 *   @0x2b36dc bhs 0x2b375c <jpeg_read_raw_data+0xc4>
 *   @0x2b36e0 ldr r3, [r4, #0x8]
 *   @0x2b36e4 cmp r3, #0
 *   @0x2b36e8 beq 0x2b3700 <jpeg_read_raw_data+0x68>
 *   @0x2b36ec str r0, [r3, #0x4]
 *   @0x2b36f0 mov r0, r4
 *   @0x2b36f4 str r12, [r3, #0x8]
 *   @0x2b36f8 ldr r3, [r3]
 *   @0x2b36fc blx r3
 *   @0x2b3700 ldr r3, [r4, #0x114]
 *   @0x2b3704 ldr r5, [r4, #0x118]
 *   @0x2b3708 mul r5, r5, r3
 *   @0x2b370c cmp r5, r7
 *   @0x2b3710 bhi 0x2b3740 <jpeg_read_raw_data+0xa8>
 *   @0x2b3714 ldr r3, [r4, #0x188]
 *   @0x2b3718 mov r1, r6
 *   @0x2b371c mov r0, r4
 *   @0x2b3720 ldr r3, [r3, #0xc]
 *   @0x2b3724 blx r3
 *   @0x2b3728 cmp r0, #0
 *   @0x2b372c ldrne r3, [r4, #0x78]
 *   @0x2b3730 movne r0, r5
 *   @0x2b3734 addne r5, r3, r5
 *   @0x2b3738 strne r5, [r4, #0x78]
 *   @0x2b373c pop {r3, r4, r5, r6, r7, pc}
 *   @0x2b3740 ldr r3, [r4]
 *   @0x2b3744 mov r2, #23
 *   @0x2b3748 mov r0, r4
 *   @0x2b374c str r2, [r3, #0x14]
 *   @0x2b3750 ldr r3, [r3]
 *   @0x2b3754 blx r3
 *   @0x2b3758 b 0x2b3714 <jpeg_read_raw_data+0x7c>
 *   @0x2b375c ldr r3, [r4]
 *   @0x2b3760 mov r0, r4
 *   @0x2b3764 mov r2, #123
 *   @0x2b3768 mvn r1, #0
 *   @0x2b376c str r2, [r3, #0x14]
 *   @0x2b3770 ldr r3, [r3, #0x4]
 *   @0x2b3774 blx r3
 *   @0x2b3778 mov r0, #0
 *   @0x2b377c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §121/127 jpeg_save_markers  0x2b5fbc  size 232  58 条（0x2b5fbc..0x2b60a4）
 * @func 0x2b5fbc 0x2b60a4  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_save_markers+0x4c
 * 字段偏移 top8: 0x4×1 / 0x30×1 / 0x194×1 / 0x94×1 / 0x1c×1 / 0x60×1 / 0x78×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b5fbc ldr r3, [r0, #0x4]
 *   @0x2b5fc0 mov r12, r0
 *   @0x2b5fc4 push {r4, lr}
 *   @0x2b5fc8 ldr r3, [r3, #0x30]
 *   @0x2b5fcc ldr r0, [r0, #0x194]
 *   @0x2b5fd0 sub r3, r3, #20
 *   @0x2b5fd4 cmp r3, r2
 *   @0x2b5fd8 movge r3, r2
 *   @0x2b5fdc cmp r3, #0
 *   @0x2b5fe0 beq 0x2b6018 <jpeg_save_markers+0x5c>
 *   @0x2b5fe4 cmp r3, #13
 *   @0x2b5fe8 cmpls r1, #224
 *   @0x2b5fec bne 0x2b6078 <jpeg_save_markers+0xbc>
 *   @0x2b5ff0 mov r3, #14
 *   @0x2b5ff4 sub r2, r1, #224
 *   @0x2b5ff8 ldr r4, [pc, #0x94]
 *   @0x2b5ffc cmp r2, #15
 *   @0x2b6000 add r4, pc, r4
 *   @0x2b6004 bhi 0x2b6048 <jpeg_save_markers+0x8c>
 *   @0x2b6008 add r2, r0, r2, lsl #2
 *   @0x2b600c str r4, [r2, #0x1c]
 *   @0x2b6010 str r3, [r2, #0x60]
 *   @0x2b6014 pop {r4, pc}
 *   @0x2b6018 ldr r4, [pc, #0x78]
 *   @0x2b601c cmp r1, #224
 *   @0x2b6020 cmpne r1, #238
 *   @0x2b6024 add r4, pc, r4
 *   @0x2b6028 beq 0x2b606c <jpeg_save_markers+0xb0>
 *   @0x2b602c cmp r1, #254
 *   @0x2b6030 streq r4, [r0, #0x18]
 *   @0x2b6034 streq r3, [r0, #0x5c]
 *   @0x2b6038 popeq {r4, pc}
 *   @0x2b603c sub r2, r1, #224
 *   @0x2b6040 cmp r2, #15
 *   @0x2b6044 bls 0x2b6008 <jpeg_save_markers+0x4c>
 *   @0x2b6048 ldr r3, [r12]
 *   @0x2b604c mov lr, #68
 *   @0x2b6050 mov r0, r12
 *   @0x2b6054 str r1, [r3, #0x18]
 *   @0x2b6058 ldr r2, [r12]
 *   @0x2b605c str lr, [r3, #0x14]
 *   @0x2b6060 ldr r3, [r2]
 *   @0x2b6064 blx r3
 *   @0x2b6068 pop {r4, pc}
 *   @0x2b606c ldr r4, [pc, #0x28]
 *   @0x2b6070 add r4, pc, r4
 *   @0x2b6074 b 0x2b602c <jpeg_save_markers+0x70>
 *   @0x2b6078 ldr r4, [pc, #0x20]
 *   @0x2b607c cmp r3, #11
 *   @0x2b6080 cmpls r1, #238
 *   @0x2b6084 add r4, pc, r4
 *   @0x2b6088 bne 0x2b602c <jpeg_save_markers+0x70>
 *   @0x2b608c mov r3, #12
 *   @0x2b6090 b 0x2b5ff4 <jpeg_save_markers+0x38>
 *   @0x2b6094 .word 0xfffffa54
 *   @0x2b6098 .word 0xffffe5d8
 *   @0x2b609c .word 0xfffff814
 *   @0x2b60a0 .word 0xfffff9d0
 *
 * ══ §122/127 DGifGetCodeNext(GifFileType*, unsigned char**)  0x2c25c0  size 232  58 条（0x2c25c0..0x2c26a8）
 * @func 0x2c25c0 0x2c26a8  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68c8×2
 * 字段偏移 top8: 0x48×2 / 0x3c×2 / 0x7×2 / 0x44×2 / 0x38×2 / 0x40×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c25c0 push {r4, r5, r6, lr}
 *   @0x2c25c4 mov r5, r0
 *   @0x2c25c8 ldr r4, [r0, #0x48]
 *   @0x2c25cc sub sp, sp, #8
 *   @0x2c25d0 mov r6, r1
 *   @0x2c25d4 ldr r3, [r4, #0x3c]
 *   @0x2c25d8 cmp r3, #0
 *   @0x2c25dc beq 0x2c2670 <_Z15DGifGetCodeNextP11GifFileTypePPh+0xb0>
 *   @0x2c25e0 add r1, sp, #7
 *   @0x2c25e4 mov r2, #1
 *   @0x2c25e8 blx r3
 *   @0x2c25ec subs r3, r0, #1
 *   @0x2c25f0 movne r3, #1
 *   @0x2c25f4 cmp r3, #0
 *   @0x2c25f8 bne 0x2c2644 <_Z15DGifGetCodeNextP11GifFileTypePPh+0x84>
 *   @0x2c25fc ldrb r2, [sp, #0x7]
 *   @0x2c2600 cmp r2, #0
 *   @0x2c2604 beq 0x2c2658 <_Z15DGifGetCodeNextP11GifFileTypePPh+0x98>
 *   @0x2c2608 add r3, r4, #68
 *   @0x2c260c str r3, [r6]
 *   @0x2c2610 strb r2, [r4, #0x44]
 *   @0x2c2614 ldr r1, [r5, #0x48]
 *   @0x2c2618 ldr r3, [r1, #0x3c]
 *   @0x2c261c cmp r3, #0
 *   @0x2c2620 beq 0x2c2690 <_Z15DGifGetCodeNextP11GifFileTypePPh+0xd0>
 *   @0x2c2624 ldr r1, [r6]
 *   @0x2c2628 mov r0, r5
 *   @0x2c262c add r1, r1, #1
 *   @0x2c2630 blx r3
 *   @0x2c2634 ldrb r3, [sp, #0x7]
 *   @0x2c2638 cmp r0, r3
 *   @0x2c263c moveq r0, #1
 *   @0x2c2640 beq 0x2c2650 <_Z15DGifGetCodeNextP11GifFileTypePPh+0x90>
 *   @0x2c2644 mov r0, #0
 *   @0x2c2648 mov r3, #102
 *   @0x2c264c str r3, [r5, #0x40]
 *   @0x2c2650 add sp, sp, #8
 *   @0x2c2654 pop {r4, r5, r6, pc}
 *   @0x2c2658 str r3, [r6]
 *   @0x2c265c mov r0, #1
 *   @0x2c2660 strb r3, [r4, #0x44]
 *   @0x2c2664 str r3, [r4, #0x34]
 *   @0x2c2668 add sp, sp, #8
 *   @0x2c266c pop {r4, r5, r6, pc}
 *   @0x2c2670 mov r1, #1
 *   @0x2c2674 ldr r3, [r4, #0x38]
 *   @0x2c2678 add r0, sp, #7
 *   @0x2c267c mov r2, r1
 *   @0x2c2680 bl 0xb68c8 <fread@plt>
 *   @0x2c2684 subs r3, r0, #1
 *   @0x2c2688 movne r3, #1
 *   @0x2c268c b 0x2c25f4 <_Z15DGifGetCodeNextP11GifFileTypePPh+0x34>
 *   @0x2c2690 ldr r0, [r6]
 *   @0x2c2694 ldr r3, [r1, #0x38]
 *   @0x2c2698 mov r1, #1
 *   @0x2c269c add r0, r0, r1
 *   @0x2c26a0 bl 0xb68c8 <fread@plt>
 *   @0x2c26a4 b 0x2c2634 <_Z15DGifGetCodeNextP11GifFileTypePPh+0x74>
 *
 * ══ §123/127 b2World::ShiftOrigin(b2Vec2 const&)  0x2cb138  size 232  58 条（0x2cb138..0x2cb220）
 * @func 0x2cb138 0x2cb220  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x70×1 / 0x14×1 / 0xc×1
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb138 movw r3, #0x91d4
 *   @0x2cb13c movt r3, #0x1
 *   @0x2cb140 push {r4, r5, r6, lr}
 *   @0x2cb144 mov r6, r0
 *   @0x2cb148 ldr r3, [r0, r3]
 *   @0x2cb14c mov r4, r1
 *   @0x2cb150 tst r3, #2
 *   @0x2cb154 popne {r4, r5, r6, pc}
 *   @0x2cb158 movw r3, #0x9228
 *   @0x2cb15c movt r3, #0x1
 *   @0x2cb160 ldr r3, [r0, r3]
 *   @0x2cb164 cmp r3, #0
 *   @0x2cb168 beq 0x2cb1d8 <_ZN7b2World11ShiftOriginERK6b2Vec2+0xa0>
 *   @0x2cb16c vldr s15, [r4]
 *   @0x2cb170 vldr s10, [r4, #4]
 *   @0x2cb174 vldr s14, [r3, #12]
 *   @0x2cb178 vldr s9, [r3, #16]
 *   @0x2cb17c vsub.f32 s15, s14, s15
 *   @0x2cb180 vldr s12, [r3, #52]
 *   @0x2cb184 vldr s11, [r3, #56]
 *   @0x2cb188 vldr s14, [r3, #60]
 *   @0x2cb18c vldr s13, [r3, #64]
 *   @0x2cb190 vsub.f32 s10, s9, s10
 *   @0x2cb194 vstr s15, [r3, #12]
 *   @0x2cb198 vldr s15, [r4]
 *   @0x2cb19c vstr s10, [r3, #16]
 *   @0x2cb1a0 vsub.f32 s15, s12, s15
 *   @0x2cb1a4 vldr s12, [r4, #4]
 *   @0x2cb1a8 vsub.f32 s12, s11, s12
 *   @0x2cb1ac vstr s15, [r3, #52]
 *   @0x2cb1b0 vldr s15, [r4]
 *   @0x2cb1b4 vstr s12, [r3, #56]
 *   @0x2cb1b8 vsub.f32 s14, s14, s15
 *   @0x2cb1bc vldr s15, [r4, #4]
 *   @0x2cb1c0 vsub.f32 s15, s13, s15
 *   @0x2cb1c4 vstr s14, [r3, #60]
 *   @0x2cb1c8 vstr s15, [r3, #64]
 *   @0x2cb1cc ldr r3, [r3, #0x70]
 *   @0x2cb1d0 cmp r3, #0
 *   @0x2cb1d4 bne 0x2cb16c <_ZN7b2World11ShiftOriginERK6b2Vec2+0x34>
 *   @0x2cb1d8 movw r3, #0x922c
 *   @0x2cb1dc movt r3, #0x1
 *   @0x2cb1e0 ldr r5, [r6, r3]
 *   @0x2cb1e4 cmp r5, #0
 *   @0x2cb1e8 beq 0x2cb20c <_ZN7b2World11ShiftOriginERK6b2Vec2+0xd4>
 *   @0x2cb1ec ldr r3, [r5]
 *   @0x2cb1f0 mov r0, r5
 *   @0x2cb1f4 mov r1, r4
 *   @0x2cb1f8 ldr r3, [r3, #0x14]
 *   @0x2cb1fc blx r3
 *   @0x2cb200 ldr r5, [r5, #0xc]
 *   @0x2cb204 cmp r5, #0
 *   @0x2cb208 bne 0x2cb1ec <_ZN7b2World11ShiftOriginERK6b2Vec2+0xb4>
 *   @0x2cb20c add r0, r6, #102400
 *   @0x2cb210 mov r1, r4
 *   @0x2cb214 add r0, r0, #472
 *   @0x2cb218 pop {r4, r5, r6, lr}
 *   @0x2cb21c b 0x2dfc84 <_ZN13b2DynamicTree11ShiftOriginERK6b2Vec2>
 *
 * ══ §124/127 YYGML_vertex_float1(int, float)  0xc9ce0  size 228  57 条（0xc9ce0..0xc9dc4）
 * @func 0xc9ce0 0xc9dd8  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_vertex_float1(int, float)+0xbc / YYGML_vertex_float1(int, float)+0x84 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGML_vertex_float1(int, float)+0x14
 * 字段偏移 top8: 0xc×3 / 0x4×3 / 0x14×2 / 0x10×2 / 0xbc×1 / 0x2×1 / 0x2c×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9ce0 cmp r0, #0
 *   @0xc9ce4 push {r4, r5, lr}
 *   @0xc9ce8 mov r5, r1
 *   @0xc9cec sub sp, sp, #12
 *   @0xc9cf0 blt 0xc9d9c <_Z19YYGML_vertex_float1if+0xbc>
 *   @0xc9cf4 ldr r3, [pc, #0xbc]
 *   @0xc9cf8 add r3, pc, r3
 *   @0xc9cfc ldr r3, [r3]
 *   @0xc9d00 ldr r4, [r3, r0, lsl #2]
 *   @0xc9d04 ldr r1, [r4, #0x2c]
 *   @0xc9d08 ldr r3, [r4, #0xc]
 *   @0xc9d0c ldr r2, [r4, #0x4]
 *   @0xc9d10 ldr r0, [r1, #0x14]
 *   @0xc9d14 add r1, r0, r3
 *   @0xc9d18 cmp r2, r1
 *   @0xc9d1c blo 0xc9d64 <_Z19YYGML_vertex_float1if+0x84>
 *   @0xc9d20 ldr r1, [r4]
 *   @0xc9d24 ldr r2, [r4, #0x10]
 *   @0xc9d28 add r0, r1, r3
 *   @0xc9d2c ldr r1, [r4, #0x14]
 *   @0xc9d30 add r3, r3, #4
 *   @0xc9d34 add r2, r2, #1
 *   @0xc9d38 str r5, [r0]
 *   @0xc9d3c cmp r2, r1
 *   @0xc9d40 str r3, [r4, #0xc]
 *   @0xc9d44 str r2, [r4, #0x10]
 *   @0xc9d48 ldrhs r3, [r4, #0x1c]
 *   @0xc9d4c movhs r2, #0
 *   @0xc9d50 strhs r2, [r4, #0x10]
 *   @0xc9d54 addhs r3, r3, #1
 *   @0xc9d58 strhs r3, [r4, #0x1c]
 *   @0xc9d5c add sp, sp, #12
 *   @0xc9d60 pop {r4, r5, pc}
 *   @0xc9d64 add r1, r0, r2
 *   @0xc9d68 ldr r0, [r4]
 *   @0xc9d6c add r1, r1, r2, lsr #1
 *   @0xc9d70 mov r2, #0
 *   @0xc9d74 str r1, [r4, #0x4]
 *   @0xc9d78 mov r3, #74
 *   @0xc9d7c str r2, [sp]
 *   @0xc9d80 ldr r2, [pc, #0x34]
 *   @0xc9d84 add r2, pc, r2
 *   @0xc9d88 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc9d8c ldr r3, [r4, #0xc]
 *   @0xc9d90 mov r1, r0
 *   @0xc9d94 str r0, [r4]
 *   @0xc9d98 b 0xc9d24 <_Z19YYGML_vertex_float1if+0x44>
 *   @0xc9d9c ldr r3, [pc, #0x1c]
 *   @0xc9da0 add r3, pc, r3
 *   @0xc9da4 ldr r3, [r3, #0x4]
 *   @0xc9da8 cmp r0, r3
 *   @0xc9dac blt 0xc9cf4 <_Z19YYGML_vertex_float1if+0x14>
 *   @0xc9db0 add sp, sp, #12
 *   @0xc9db4 pop {r4, r5, pc}
 *   @0xc9db8 eorseq r0, r11, r12, lsr r4
 *   @0xc9dbc eoreq r7, r6, r12, lsr #5
 *   @0xc9dc0 mlaseq r11, r4, r3, r0
 *
 * ══ §125/127 PTR_RValue(RValue const*)  0xd0fc0  size 228  57 条（0xd0fc0..0xd10a4）
 * @func 0xd0fc0 0xd10a4  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYError(char const*, ...)×2 / __fixdfdi / 0xb6664 / ARRAY_LVAL_RValue(YYRValue*, int)
 * 字段偏移 top8: 0xc×1 / 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd0fc0 push {r3, lr}
 *   @0xd0fc4 ldr r1, [r0, #0xc]
 *   @0xd0fc8 bic r1, r1, #-16777216
 *   @0xd0fcc cmp r1, #13
 *   @0xd0fd0 addls pc, pc, r1, lsl #2
 *   @0xd0fd4 b 0xd1068 <_Z10PTR_RValuePK6RValue+0xa8>
 *   @0xd0fd8 b 0xd1020 <_Z10PTR_RValuePK6RValue+0x60>
 *   @0xd0fdc b 0xd1034 <_Z10PTR_RValuePK6RValue+0x74>
 *   @0xd0fe0 b 0xd105c <_Z10PTR_RValuePK6RValue+0x9c>
 *   @0xd0fe4 b 0xd1010 <_Z10PTR_RValuePK6RValue+0x50>
 *   @0xd0fe8 b 0xd1068 <_Z10PTR_RValuePK6RValue+0xa8>
 *   @0xd0fec b 0xd1018 <_Z10PTR_RValuePK6RValue+0x58>
 *   @0xd0ff0 b 0xd1010 <_Z10PTR_RValuePK6RValue+0x50>
 *   @0xd0ff4 b 0xd1010 <_Z10PTR_RValuePK6RValue+0x50>
 *   @0xd0ff8 b 0xd1068 <_Z10PTR_RValuePK6RValue+0xa8>
 *   @0xd0ffc b 0xd1068 <_Z10PTR_RValuePK6RValue+0xa8>
 *   @0xd1000 b 0xd1010 <_Z10PTR_RValuePK6RValue+0x50>
 *   @0xd1004 b 0xd1068 <_Z10PTR_RValuePK6RValue+0xa8>
 *   @0xd1008 b 0xd1068 <_Z10PTR_RValuePK6RValue+0xa8>
 *   @0xd100c b 0xd1020 <_Z10PTR_RValuePK6RValue+0x60>
 *   @0xd1010 ldr r0, [r0]
 *   @0xd1014 pop {r3, pc}
 *   @0xd1018 mov r0, #0
 *   @0xd101c pop {r3, pc}
 *   @0xd1020 ldm r0, {r2, r3}
 *   @0xd1024 mov r0, r2
 *   @0xd1028 mov r1, r3
 *   @0xd102c bl 0x3194a0 <__fixdfdi>
 *   @0xd1030 pop {r3, pc}
 *   @0xd1034 ldr r0, [r0]
 *   @0xd1038 cmp r0, #0
 *   @0xd103c popeq {r3, pc}
 *   @0xd1040 ldr r0, [r0]
 *   @0xd1044 cmp r0, #0
 *   @0xd1048 popeq {r3, pc}
 *   @0xd104c mov r2, #16
 *   @0xd1050 mov r1, #0
 *   @0xd1054 bl 0xb6664 <strtoll@plt>
 *   @0xd1058 pop {r3, pc}
 *   @0xd105c mov r1, #0
 *   @0xd1060 bl 0xd0d38 <_Z17ARRAY_LVAL_RValueP8YYRValuei>
 *   @0xd1064 b 0xd0fc4 <_Z10PTR_RValuePK6RValue+0x4>
 *   @0xd1068 mvn r3, #-16777216
 *   @0xd106c cmp r1, r3
 *   @0xd1070 beq 0xd1088 <_Z10PTR_RValuePK6RValue+0xc8>
 *   @0xd1074 ldr r0, [pc, #0x20]
 *   @0xd1078 add r0, pc, r0
 *   @0xd107c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd1080 mov r0, #0
 *   @0xd1084 pop {r3, pc}
 *   @0xd1088 ldr r0, [pc, #0x10]
 *   @0xd108c add r0, pc, r0
 *   @0xd1090 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd1094 mov r0, #0
 *   @0xd1098 pop {r3, pc}
 *   @0xd109c eoreq r1, r6, r12, ror #10
 *   @0xd10a0 eoreq r1, r6, r0, asr #10
 *
 * ══ §126/127 INT32_RValue(RValue const*)  0xd11b0  size 228  57 条（0xd11b0..0xd1294）
 * @func 0xd11b0 0xd1294  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYError(char const*, ...)×2 / ARRAY_LVAL_RValue(YYRValue*, int)
 * 字段偏移 top8: 0xc×1 / 0x20×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd11b0 push {r3, lr}
 *   @0xd11b4 ldr r1, [r0, #0xc]
 *   @0xd11b8 bic r1, r1, #-16777216
 *   @0xd11bc cmp r1, #13
 *   @0xd11c0 addls pc, pc, r1, lsl #2
 *   @0xd11c4 b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8>
 *   @0xd11c8 b 0xd1210 <_Z12INT32_RValuePK6RValue+0x60>
 *   @0xd11cc b 0xd1224 <_Z12INT32_RValuePK6RValue+0x74>
 *   @0xd11d0 b 0xd124c <_Z12INT32_RValuePK6RValue+0x9c>
 *   @0xd11d4 b 0xd1200 <_Z12INT32_RValuePK6RValue+0x50>
 *   @0xd11d8 b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8>
 *   @0xd11dc b 0xd1208 <_Z12INT32_RValuePK6RValue+0x58>
 *   @0xd11e0 b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8>
 *   @0xd11e4 b 0xd1200 <_Z12INT32_RValuePK6RValue+0x50>
 *   @0xd11e8 b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8>
 *   @0xd11ec b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8>
 *   @0xd11f0 b 0xd1200 <_Z12INT32_RValuePK6RValue+0x50>
 *   @0xd11f4 b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8>
 *   @0xd11f8 b 0xd1258 <_Z12INT32_RValuePK6RValue+0xa8>
 *   @0xd11fc b 0xd1210 <_Z12INT32_RValuePK6RValue+0x60>
 *   @0xd1200 ldr r0, [r0]
 *   @0xd1204 pop {r3, pc}
 *   @0xd1208 mov r0, #0
 *   @0xd120c pop {r3, pc}
 *   @0xd1210 ldm r0, {r2, r3}
 *   @0xd1214 vmov d7, r2, r3
 *   @0xd1218 vcvt.s32.f64 s15, d7
 *   @0xd121c vmov r0, s15
 *   @0xd1220 pop {r3, pc}
 *   @0xd1224 ldr r0, [r0]
 *   @0xd1228 cmp r0, #0
 *   @0xd122c popeq {r3, pc}
 *   @0xd1230 ldr r0, [r0]
 *   @0xd1234 cmp r0, #0
 *   @0xd1238 popeq {r3, pc}
 *   @0xd123c mov r1, #0
 *   @0xd1240 mov r2, #10
 *   @0xd1244 pop {r3, lr}
 *   @0xd1248 b 0xb6670 <strtol@plt>
 *   @0xd124c mov r1, #0
 *   @0xd1250 bl 0xd0d38 <_Z17ARRAY_LVAL_RValueP8YYRValuei>
 *   @0xd1254 b 0xd11b4 <_Z12INT32_RValuePK6RValue+0x4>
 *   @0xd1258 mvn r3, #-16777216
 *   @0xd125c cmp r1, r3
 *   @0xd1260 beq 0xd1278 <_Z12INT32_RValuePK6RValue+0xc8>
 *   @0xd1264 ldr r0, [pc, #0x20]
 *   @0xd1268 add r0, pc, r0
 *   @0xd126c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd1270 mov r0, #0
 *   @0xd1274 pop {r3, pc}
 *   @0xd1278 ldr r0, [pc, #0x10]
 *   @0xd127c add r0, pc, r0
 *   @0xd1280 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd1284 mov r0, #0
 *   @0xd1288 pop {r3, pc}
 *   @0xd128c eoreq r1, r6, r12, ror #7
 *   @0xd1290 eoreq r1, r6, r0, asr #7
 *
 * ══ §127/127 CBackground::GetTransparent()  0xc2d88  size 8  2 条（0xc2d88..0xc2d90）
 * @func 0xc2d88 0xc2d90  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2d88 ldrb r0, [r0, #0x8]
 *   @0xc2d8c bx lr
 */
