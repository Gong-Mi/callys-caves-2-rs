/* cally 逆向卡：All_45 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 76 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/76 png_write_info_before_PLTE  0x2afc70  size 420  105 条（0x2afc70..0x2afe14）
 * @func 0x2afc70 0x2afe14  size 420  105 条
 * 部分覆盖: 本节 105/172 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_sBIT / png_write_cHRM / png_handle_as_unknown / png_warning / png_write_chunk
 * 字段偏移 top8: 0x8×3 / 0xc×2 / 0x164×1 / 0x4×1 / 0x10×1
 * VFP 指令 25 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2afc70 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2afc74 mov r4, r1
 *   @0x2afc78 mov r5, r0
 *   @0x2afc7c beq.w 0x2afe04 <png_write_info_before_PLTE+0x194>
 *   @0x2afc80 cmp r1, #0x0
 *   @0x2afc84 .word 0xf8d080bf
 *   @0x2afc88 .word 0xf413312c
 *   @0x2afc8c .word 0xf0406680
 *   @0x2afc90 .word 0xf00180b9
 *   @0x2afc94 .word 0xf8d5fa55
 *   @0x2afc98 ldrbeq r3, [r10], #300
 *   @0x2afc9c bpl 0x2afcb2 <png_write_info_before_PLTE+0x42>
 *   @0x2afca0 ldrsblt r3, [r3, -r12]!
 *   @0x2afca4 ldr r1, [pc, #0x164]
 *   @0x2afca8 add r1, pc
 *   @0x2afcac .word 0xf8c5fbe3
 *   @0x2afcb0 mcrvc p2, #0x3, r6, c2, c12, #0x6
 *   @0x2afcb4 mov r0, r5
 *   @0x2afcb8 str r2, [sp]
 *   @0x2afcbc str r2, [sp, #0x4]
 *   @0x2afcc0 str r2, [sp, #0x8]
 *   @0x2afcc4 str r2, [sp, #0xc]
 *   @0x2afcc8 .word 0xf0010006
 *   @0x2afccc stmvs r3!, {r0, r1, r3, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2afcd0 lsls r3, r3, #0x1f
 *   @0x2afcd4 vldr s15, [r4, #40]
 *   @0x2afcd8 vcvt.f64.f32 d6, s15
 *   @0x2afcdc mov r0, r5
 *   @0x2afce0 .word 0xf0012b16
 *   @0x2afce4 stmvs r3!, {r0, r2, r3, r5, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2afce8 lsls r7, r3, #0x14
 *   @0x2afcec mov r0, r5
 *   @0x2afcf0 .word 0xf001102c
 *   @0x2afcf4 stmvs r3!, {r0, r1, r3, r5, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2afcf8 lsls r6, r3, #0x13
 *   @0x2afcfc ldr.w r3, [r4, #0xcc]
 *   @0x2afd00 mov r0, r5
 *   @0x2afd04 andhs r1, r0, #196
 *   @0x2afd08 str r3, [sp]
 *   @0x2afd0c .word 0xf00130c8
 *   @0x2afd10 stmvs r3!, {r0, r1, r2, r3, r4, r5, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2afd14 lsls r0, r3, #0x1e
 *   @0x2afd18 mov r0, r5
 *   @0x2afd1c cdpvc p1, #0x6, c0, c2, c4, #0x2
 *   @0x2afd20 bl 0x2b1aac <png_write_sBIT>
 *   @0x2afd24 ldr r3, [r4, #0x8]
 *   @0x2afd28 bpl 0x2afd90 <png_write_info_before_PLTE+0x120>
 *   @0x2afd2c .word 0xeeb77a21
 *   @0x2afd30 vldr s15, [r4, #796]
 *   @0x2afd34 strtmi r6, [r8], -r0, lsr #20
 *   @0x2afd38 vstr d7, [sp]
 *   @0x2afd3c vldr s14, [r4, #136]
 *   @0x2afd40 vcvt.f64.f32 d7, s14
 *   @0x2afd44 vstr d7, [sp, #8]
 *   @0x2afd48 vldr s14, [r4, #140]
 *   @0x2afd4c vcvt.f64.f32 d7, s14
 *   @0x2afd50 vstr d7, [sp, #16]
 *   @0x2afd54 vldr s14, [r4, #144]
 *   @0x2afd58 vcvt.f64.f32 d7, s14
 *   @0x2afd5c vstr d7, [sp, #24]
 *   @0x2afd60 vldr s14, [r4, #148]
 *   @0x2afd64 vcvt.f64.f32 d7, s14
 *   @0x2afd68 vstr d7, [sp, #32]
 *   @0x2afd6c vldr s14, [r4, #152]
 *   @0x2afd70 vcvt.f64.f32 d7, s14
 *   @0x2afd74 vstr d7, [sp, #40]
 *   @0x2afd78 vldr s14, [r4, #156]
 *   @0x2afd7c vcvt.f64.f32 d7, s14
 *   @0x2afd80 vstr d7, [sp, #48]
 *   @0x2afd84 vcvt.f64.f32 d7, s13
 *   @0x2afd88 vmov r2, r3, d7
 *   @0x2afd8c bl 0x2b1b50 <png_write_cHRM>
 *   @0x2afd90 ldr.w r3, [r4, #0xc0]
 *   @0x2afd94 cbnz r3, 0x2afda4 <png_write_info_before_PLTE+0x134>
 *   @0x2afd98 vst4.8 {d19, d21, d23, d25}, [r3:128], r12
 *   @0x2afd9c .word 0xf8c56380
 *   @0x2afda0 eor r3, pc, r12, lsr #2
 *   @0x2afda4 ldr.w r8, [pc, #0x68]
 *   @0x2afda8 movs r7, #0x14
 *   @0x2afdac ldrbtmi r6, [r8], #188
 *   @0x2afdb0 ldr.w r2, [r4, #0xc0]
 *   @0x2afdb4 ldr.w r3, [r4, #0xbc]
 *   @0x2afdb8 mla r3, r7, r2, r3
 *   @0x2afdbc cmp r6, r3
 *   @0x2afdc0 mov r0, r5
 *   @0x2afdc4 bl 0x2a5fe4 <png_handle_as_unknown>
 *   @0x2afdc8 cmp r0, #0x1
 *   @0x2afdcc ldrb r3, [r6, #0x10]
 *   @0x2afdd0 tst.w r3, #0x6
 *   @0x2afdd4 bne 0x2afe00 <png_write_info_before_PLTE+0x190>
 *   @0x2afdd8 lsls r2, r3, #0x1a
 *   @0x2afddc cmp r0, #0x3
 *   @0x2afde0 ldr.w r3, [r5, #0x130]
 *   @0x2afde4 lsls r3, r3, #0xf
 *   @0x2afde8 ldr r3, [r6, #0xc]
 *   @0x2afdec mov r0, r5
 *   @0x2afdf0 bl 0x2a6474 <png_warning>
 *   @0x2afdf4 mov r0, r5
 *   @0x2afdf8 ldr r2, [r6, #0x8]
 *   @0x2afdfc bl 0x2b12bc <png_write_chunk>
 *   @0x2afe00 adds r6, #0x14
 *   @0x2afe04 add sp, #0x38
 *   @0x2afe08 svclt #0x81f0
 *   @0x2afe0c ldm r1, {r1, r5, r7}
 *   @0x2afe10 b 0x2b0078 <png_write_end+0x4c>
 *
 * ══ §2/76 F_D3DMatrixStackPush(RValue&, CInstance*, CInstance*, int, RValue*)  0x148e70  size 416  104 条（0x148e70..0x149010）
 * @func 0x148e70 0x149024  size 436  109 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x148e7c→0x48481c, 0x148eec→0x483b5c, 0x148fac→0x483b5c
 * 调用序列: Error_Show_Action(char const*, bool)×3 / REAL_RValue_Ex(RValue const*) / yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*)
 * 字段偏移 top8: 0x178×2 / 0xa0×2 / 0x4×2 / 0xc×2 / 0x124×1 / 0x110×1 / 0xdc×1 / 0x6c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148e70 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x148e74 sub sp, sp, #132
 *   @0x148e78 ldr r6, [pc, #0x178]
 *   @0x148e7c ldr r2, [pc, #0x178]
 *   @0x148e80 add r6, pc, r6
 *   @0x148e84 ldr r7, [r6, r2]
 *   @0x148e88 ldr r4, [r7]
 *   @0x148e8c cmp r4, #49
 *   @0x148e90 bgt 0x148f24 <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x148e94 cmp r3, #0
 *   @0x148e98 add r2, r4, #1
 *   @0x148e9c str r2, [r7]
 *   @0x148ea0 beq 0x148eec <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x148ea4 cmp r3, #1
 *   @0x148ea8 beq 0x148f84 <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x148eac ldr r1, [sp, #0xa0]
 *   @0x148eb0 ldr r3, [r1]
 *   @0x148eb4 cmp r3, #0
 *   @0x148eb8 beq 0x148ed4 <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x148ebc ldr r3, [r3, #0x4]
 *   @0x148ec0 cmp r3, #0
 *   @0x148ec4 beq 0x148ed4 <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x148ec8 ldr r2, [r3]
 *   @0x148ecc cmp r2, #16
 *   @0x148ed0 beq 0x148f3c <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x148ed4 ldr r0, [pc, #0x124]
 *   @0x148ed8 mov r1, #1
 *   @0x148edc add r0, pc, r0
 *   @0x148ee0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148ee4 add sp, sp, #132
 *   @0x148ee8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x148eec ldr r3, [pc, #0x110]
 *   @0x148ef0 ldr r12, [r6, r3]
 *   @0x148ef4 add r4, r12, r4, lsl #6
 *   @0x148ef8 add r12, r12, r2, lsl #6
 *   @0x148efc ldm r4!, {r0, r1, r2, r3}
 *   @0x148f00 stm r12!, {r0, r1, r2, r3}
 *   @0x148f04 ldm r4!, {r0, r1, r2, r3}
 *   @0x148f08 stm r12!, {r0, r1, r2, r3}
 *   @0x148f0c ldm r4!, {r0, r1, r2, r3}
 *   @0x148f10 stm r12!, {r0, r1, r2, r3}
 *   @0x148f14 ldm r4, {r0, r1, r2, r3}
 *   @0x148f18 stm r12, {r0, r1, r2, r3}
 *   @0x148f1c add sp, sp, #132
 *   @0x148f20 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x148f24 ldr r0, [pc, #0xdc]
 *   @0x148f28 mov r1, #1
 *   @0x148f2c add r0, pc, r0
 *   @0x148f30 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148f34 add sp, sp, #132
 *   @0x148f38 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x148f3c ldr r4, [r3, #0x4]
 *   @0x148f40 add r9, sp, #64
 *   @0x148f44 mov r5, sp
 *   @0x148f48 b 0x148f68 <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x148f4c ldm r4, {r0, r1}
 *   @0x148f50 vmov d6, r0, r1
 *   @0x148f54 add r4, r4, #16
 *   @0x148f58 vcvt.f32.f64 s15, d6
 *   @0x148f5c vstmia r5!, {s15}
 *   @0x148f60 cmp r5, r9
 *   @0x148f64 beq 0x148fac <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x148f68 ldr r3, [r4, #0xc]
 *   @0x148f6c bic r3, r3, #-16777216
 *   @0x148f70 cmp r3, #0
 *   @0x148f74 beq 0x148f4c <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x148f78 mov r0, r4
 *   @0x148f7c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x148f80 b 0x148f50 <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x148f84 ldr r1, [sp, #0xa0]
 *   @0x148f88 ldr r3, [r1, #0xc]
 *   @0x148f8c bic r3, r3, #-16777216
 *   @0x148f90 cmp r3, #2
 *   @0x148f94 beq 0x148eac <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x148f98 ldr r0, [pc, #0x6c]
 *   @0x148f9c mov r1, #0
 *   @0x148fa0 add r0, pc, r0
 *   @0x148fa4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148fa8 b 0x148f1c <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x148fac ldr r3, [pc, #0x50]
 *   @0x148fb0 mov r1, sp
 *   @0x148fb4 ldr r2, [r7]
 *   @0x148fb8 mov r0, r5
 *   @0x148fbc ldr r4, [r6, r3]
 *   @0x148fc0 sub r2, r2, #1
 *   @0x148fc4 add r2, r4, r2, lsl #6
 *   @0x148fc8 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x148fcc ldm r5!, {r0, r1, r2, r3}
 *   @0x148fd0 ldr r12, [r7]
 *   @0x148fd4 add r12, r4, r12, lsl #6
 *   @0x148fd8 stm r12!, {r0, r1, r2, r3}
 *   @0x148fdc ldm r5!, {r0, r1, r2, r3}
 *   @0x148fe0 stm r12!, {r0, r1, r2, r3}
 *   @0x148fe4 ldm r5!, {r0, r1, r2, r3}
 *   @0x148fe8 stm r12!, {r0, r1, r2, r3}
 *   @0x148fec ldm r5, {r0, r1, r2, r3}
 *   @0x148ff0 stm r12, {r0, r1, r2, r3}
 *   @0x148ff4 b 0x148f1c <_Z20F_D3DMatrixStackPushR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x148ff8 .word 0x002a8dd0
 *   @0x148ffc .word 0xffffd9b4
 *   @0x149000 mulseq pc, r12, r7
 *   @0x149004 .word 0xffffd9b8
 *   @0x149008 andseq r9, pc, r8, lsr #14
 *   @0x14900c andseq r9, pc, r4, lsl #14
 *
 * ══ §3/76 GR_D3D_Screenshot_Part(int, int, int, int)  0x169b34  size 416  104 条（0x169b34..0x169cd4）
 * @func 0x169b34 0x169cd4  size 416  104 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_D3D_Screenshot_Part(int, int, int, int)+0x194 / IBitmap::Create() / Graphics::GrabScreenRect(int, int, int, int, int*, int*) / 0xb65bc / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×6 / 0xc×5 / 0x10×4 / 0x14×3 / 0x4×2 / 0x194×1 / 0x1c×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169b34 ldr r12, [pc, #0x194]
 *   @0x169b38 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x169b3c ldr r12, [pc, r12]
 *   @0x169b40 sub sp, sp, #28
 *   @0x169b44 bic r4, r0, r0, asr #31
 *   @0x169b48 ldr r9, [r12, #0x8]
 *   @0x169b4c add r0, r2, r4
 *   @0x169b50 str r3, [sp, #0x8]
 *   @0x169b54 mov r5, r2
 *   @0x169b58 ldr r3, [r12]
 *   @0x169b5c bic r7, r1, r1, asr #31
 *   @0x169b60 str r2, [sp, #0xc]
 *   @0x169b64 rsb r9, r3, r9
 *   @0x169b68 ldr r8, [r12, #0xc]
 *   @0x169b6c cmp r9, r0
 *   @0x169b70 ldr r3, [r12, #0x4]
 *   @0x169b74 rsblt r2, r4, r9
 *   @0x169b78 strlt r2, [sp, #0xc]
 *   @0x169b7c movge r2, r5
 *   @0x169b80 ldr r5, [sp, #0x8]
 *   @0x169b84 rsb r8, r3, r8
 *   @0x169b88 add r3, r5, r7
 *   @0x169b8c cmp r8, r3
 *   @0x169b90 rsblt r5, r7, r8
 *   @0x169b94 strlt r5, [sp, #0x8]
 *   @0x169b98 cmp r2, #0
 *   @0x169b9c cmpgt r5, #0
 *   @0x169ba0 movgt r5, #0
 *   @0x169ba4 movle r5, #1
 *   @0x169ba8 movle r0, #0
 *   @0x169bac ble 0x169cc8 <_Z22GR_D3D_Screenshot_Partiiii+0x194>
 *   @0x169bb0 bl 0x1a912c <_ZN7IBitmap6CreateEv>
 *   @0x169bb4 ldr r1, [sp, #0xc]
 *   @0x169bb8 ldr r3, [r0]
 *   @0x169bbc mov r6, r0
 *   @0x169bc0 ldr r3, [r3, #0xc]
 *   @0x169bc4 blx r3
 *   @0x169bc8 ldr r3, [r6]
 *   @0x169bcc mov r0, r6
 *   @0x169bd0 ldr r1, [sp, #0x8]
 *   @0x169bd4 ldr r3, [r3, #0x14]
 *   @0x169bd8 blx r3
 *   @0x169bdc ldr r3, [r6]
 *   @0x169be0 mov r0, r6
 *   @0x169be4 mov r1, #7
 *   @0x169be8 ldr r3, [r3, #0x1c]
 *   @0x169bec blx r3
 *   @0x169bf0 mov r1, r8
 *   @0x169bf4 add r12, sp, #12
 *   @0x169bf8 mov r0, r9
 *   @0x169bfc str r12, [sp]
 *   @0x169c00 mov r2, r4
 *   @0x169c04 add r12, sp, #8
 *   @0x169c08 mov r3, r7
 *   @0x169c0c str r12, [sp, #0x4]
 *   @0x169c10 bl 0x17e0dc <_ZN8Graphics14GrabScreenRectEiiiiPiS0_>
 *   @0x169c14 subs r8, r0, #0
 *   @0x169c18 beq 0x169cbc <_Z22GR_D3D_Screenshot_Partiiii+0x188>
 *   @0x169c1c str r5, [sp, #0x10]
 *   @0x169c20 mov r0, r6
 *   @0x169c24 ldr r12, [r6]
 *   @0x169c28 mov r1, r5
 *   @0x169c2c add r2, sp, #16
 *   @0x169c30 add r3, sp, #20
 *   @0x169c34 ldr r7, [sp, #0xc]
 *   @0x169c38 ldr r12, [r12, #0x24]
 *   @0x169c3c blx r12
 *   @0x169c40 mov r9, r0
 *   @0x169c44 ldr r0, [sp, #0x10]
 *   @0x169c48 cmp r0, #0
 *   @0x169c4c beq 0x169cbc <_Z22GR_D3D_Screenshot_Partiiii+0x188>
 *   @0x169c50 ldr r3, [sp, #0x14]
 *   @0x169c54 cmp r3, #0
 *   @0x169c58 beq 0x169cbc <_Z22GR_D3D_Screenshot_Partiiii+0x188>
 *   @0x169c5c ldr r3, [sp, #0x8]
 *   @0x169c60 cmp r3, #0
 *   @0x169c64 lslgt r7, r7, #2
 *   @0x169c68 movgt r4, r8
 *   @0x169c6c bgt 0x169c78 <_Z22GR_D3D_Screenshot_Partiiii+0x144>
 *   @0x169c70 b 0x169ca8 <_Z22GR_D3D_Screenshot_Partiiii+0x174>
 *   @0x169c74 mov r0, r3
 *   @0x169c78 mov r1, r4
 *   @0x169c7c mov r2, r7
 *   @0x169c80 bl 0xb65bc <memcpy@plt>
 *   @0x169c84 ldr r3, [sp, #0x8]
 *   @0x169c88 add r5, r5, #1
 *   @0x169c8c ldr r2, [sp, #0x10]
 *   @0x169c90 cmp r3, r5
 *   @0x169c94 ldr r3, [sp, #0x14]
 *   @0x169c98 add r4, r4, r7
 *   @0x169c9c add r3, r2, r3
 *   @0x169ca0 str r3, [sp, #0x10]
 *   @0x169ca4 bgt 0x169c74 <_Z22GR_D3D_Screenshot_Partiiii+0x140>
 *   @0x169ca8 ldr r3, [r6]
 *   @0x169cac mov r1, r9
 *   @0x169cb0 mov r0, r6
 *   @0x169cb4 ldr r3, [r3, #0x28]
 *   @0x169cb8 blx r3
 *   @0x169cbc mov r0, r8
 *   @0x169cc0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x169cc4 mov r0, r6
 *   @0x169cc8 add sp, sp, #28
 *   @0x169ccc pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x169cd0 eoreq r6, r8, r0, lsl r6
 *
 * ══ §4/76 GR_Draw_Line_Width_Ext(float, float, float, float, float, unsigned int, unsigned int)  0x16a550  size 416  104 条（0x16a550..0x16a6f0）
 * @func 0x16a550 0x16a6f0  size 416  104 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16a568→0x4859c0, 0x16a59c→0x3f23d4, 0x16a5a4→0x3f23d8, 0x16a5f8→0x4859ac, 0x16a5fc→0x3f23cc
 * 调用序列: GR_Color_To_D3DColor(unsigned int, unsigned int)×4 / Graphics::AllocVerts(ePrimType, void*, int, int) / 0xb6700
 * 字段偏移 top8: 0xe8×2 / 0x170×1 / 0x16c×1 / 0x44×1 / 0x48×1 / 0x13c×1 / 0x138×1 / 0x8×1
 * VFP 指令 47 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16a550 push {r4, r5, r6, r7, r8, lr}
 *   @0x16a554 vpush {d8, d9, d10, d11, d12}
 *   @0x16a558 vmov s18, r1
 *   @0x16a55c vldr s23, [sp, #64]
 *   @0x16a560 ldr r5, [pc, #0x170]
 *   @0x16a564 vmov s19, r0
 *   @0x16a568 ldr r1, [pc, #0x16c]
 *   @0x16a56c vmov s24, r2
 *   @0x16a570 add r5, pc, r5
 *   @0x16a574 vmov s17, r3
 *   @0x16a578 mov r2, #16
 *   @0x16a57c mov r3, #4
 *   @0x16a580 ldr r1, [r5, r1]
 *   @0x16a584 mov r0, #6
 *   @0x16a588 ldr r7, [sp, #0x44]
 *   @0x16a58c ldr r8, [sp, #0x48]
 *   @0x16a590 ldr r1, [r1]
 *   @0x16a594 ldr r1, [r1]
 *   @0x16a598 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16a59c ldr r2, [pc, #0x13c]
 *   @0x16a5a0 vldr s14, [pc, #300]
 *   @0x16a5a4 ldr r3, [pc, #0x138]
 *   @0x16a5a8 ldr r2, [r5, r2]
 *   @0x16a5ac vldr s20, [r2]
 *   @0x16a5b0 vmul.f32 s20, s20, s14
 *   @0x16a5b4 ldr r3, [r5, r3]
 *   @0x16a5b8 vldr s21, [r3]
 *   @0x16a5bc vadd.f32 s18, s20, s18
 *   @0x16a5c0 vmul.f32 s21, s21, s14
 *   @0x16a5c4 mov r4, r0
 *   @0x16a5c8 vadd.f32 s20, s20, s17
 *   @0x16a5cc vsub.f32 s22, s20, s18
 *   @0x16a5d0 vadd.f32 s19, s21, s19
 *   @0x16a5d4 vadd.f32 s21, s21, s24
 *   @0x16a5d8 vmul.f32 s14, s22, s22
 *   @0x16a5dc vsub.f32 s16, s21, s19
 *   @0x16a5e0 vmla.f32 s14, s16, s16
 *   @0x16a5e4 vsqrt.f32 s15, s14
 *   @0x16a5e8 vcmp.f32 s15, s15
 *   @0x16a5ec vmrs APSR_nzcv, fpscr
 *   @0x16a5f0 bne 0x16a6c4 <_Z22GR_Draw_Line_Width_Extfffffjj+0x174>
 *   @0x16a5f4 vmov.f32 s17, #5.000000e-01
 *   @0x16a5f8 ldr r2, [pc, #0xe8]
 *   @0x16a5fc ldr r3, [pc, #0xe8]
 *   @0x16a600 mov r0, r7
 *   @0x16a604 vmul.f32 s17, s23, s17
 *   @0x16a608 vmul.f32 s16, s16, s17
 *   @0x16a60c vmul.f32 s17, s22, s17
 *   @0x16a610 vdiv.f32 s16, s16, s15
 *   @0x16a614 vdiv.f32 s17, s17, s15
 *   @0x16a618 vadd.f32 s14, s18, s16
 *   @0x16a61c vsub.f32 s15, s19, s17
 *   @0x16a620 vstr s14, [r4, #4]
 *   @0x16a624 vstr s15, [r4]
 *   @0x16a628 ldr r6, [r5, r2]
 *   @0x16a62c ldr r2, [r6]
 *   @0x16a630 str r2, [r4, #0x8]
 *   @0x16a634 ldr r5, [r5, r3]
 *   @0x16a638 ldr r1, [r5]
 *   @0x16a63c bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16a640 vsub.f32 s14, s21, s17
 *   @0x16a644 ldr r3, [r6]
 *   @0x16a648 ldr r1, [r5]
 *   @0x16a64c str r3, [r4, #0x18]
 *   @0x16a650 vadd.f32 s15, s20, s16
 *   @0x16a654 vstr s14, [r4, #16]
 *   @0x16a658 vstr s15, [r4, #20]
 *   @0x16a65c str r0, [r4, #0xc]
 *   @0x16a660 mov r0, r8
 *   @0x16a664 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16a668 vadd.f32 s21, s21, s17
 *   @0x16a66c ldr r3, [r6]
 *   @0x16a670 ldr r1, [r5]
 *   @0x16a674 str r3, [r4, #0x28]
 *   @0x16a678 vsub.f32 s20, s20, s16
 *   @0x16a67c vstr s21, [r4, #32]
 *   @0x16a680 vstr s20, [r4, #36]
 *   @0x16a684 str r0, [r4, #0x1c]
 *   @0x16a688 mov r0, r8
 *   @0x16a68c bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16a690 vadd.f32 s17, s19, s17
 *   @0x16a694 ldr r3, [r6]
 *   @0x16a698 ldr r1, [r5]
 *   @0x16a69c str r3, [r4, #0x38]
 *   @0x16a6a0 vsub.f32 s16, s18, s16
 *   @0x16a6a4 vstr s17, [r4, #48]
 *   @0x16a6a8 vstr s16, [r4, #52]
 *   @0x16a6ac str r0, [r4, #0x2c]
 *   @0x16a6b0 mov r0, r7
 *   @0x16a6b4 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16a6b8 vpop {d8, d9, d10, d11, d12}
 *   @0x16a6bc str r0, [r4, #0x3c]
 *   @0x16a6c0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x16a6c4 vmov r0, s14
 *   @0x16a6c8 bl 0xb6700 <sqrtf@plt>
 *   @0x16a6cc vmov s15, r0
 *   @0x16a6d0 b 0x16a5f4 <_Z22GR_Draw_Line_Width_Extfffffjj+0xa4>
 *   @0x16a6d4 stclo p7, c13, [r3], #-40
 *   @0x16a6d8 eoreq r7, r8, r0, ror #13
 *   @0x16a6dc .word 0xffffe4e0
 *   @0x16a6e0 .word 0xffffe520
 *   @0x16a6e4 .word 0xffffe524
 *   @0x16a6e8 .word 0xffffbcd0
 *   @0x16a6ec .word 0xffffc0b0
 *
 * ══ §5/76 GR_Window_View_Mouse_Set(int, int, int)  0x17aae0  size 416  104 条（0x17aae0..0x17ac80）
 * @func 0x17aae0 0x17ac80  size 416  104 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb658c / 0xb6580 / GR_Window_Mouse_Set(int, int) / GR_Window_View_Convert_World(int, float, float, int&, int&)
 * 字段偏移 top8: 0x178×1 / 0x140×1
 * VFP 指令 67 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17aae0 cmp r0, #31
 *   @0x17aae4 push {r4, lr}
 *   @0x17aae8 vpush {d8, d9, d10}
 *   @0x17aaec sub sp, sp, #16
 *   @0x17aaf0 bhi 0x17ac0c <_Z24GR_Window_View_Mouse_Setiii+0x12c>
 *   @0x17aaf4 add r3, r0, r0, lsl #1
 *   @0x17aaf8 ldr r12, [pc, #0x178]
 *   @0x17aafc lsl r3, r3, #4
 *   @0x17ab00 ldr r12, [pc, r12]
 *   @0x17ab04 add r4, r12, r3
 *   @0x17ab08 ldrb r3, [r12, r3]
 *   @0x17ab0c cmp r3, #0
 *   @0x17ab10 beq 0x17ac0c <_Z24GR_Window_View_Mouse_Setiii+0x12c>
 *   @0x17ab14 vldr s11, [r4, #12]
 *   @0x17ab18 vcmp.f32 s11, #0
 *   @0x17ab1c vmrs APSR_nzcv, fpscr
 *   @0x17ab20 beq 0x17ac0c <_Z24GR_Window_View_Mouse_Setiii+0x12c>
 *   @0x17ab24 vldr s10, [r4, #16]
 *   @0x17ab28 vcmp.f32 s10, #0
 *   @0x17ab2c vmrs APSR_nzcv, fpscr
 *   @0x17ab30 beq 0x17ac0c <_Z24GR_Window_View_Mouse_Setiii+0x12c>
 *   @0x17ab34 ldr r3, [pc, #0x140]
 *   @0x17ab38 ldr r3, [pc, r3]
 *   @0x17ab3c ldrb r3, [r3]
 *   @0x17ab40 cmp r3, #0
 *   @0x17ab44 bne 0x17ac2c <_Z24GR_Window_View_Mouse_Setiii+0x14c>
 *   @0x17ab48 vmov s13, r1
 *   @0x17ab4c vldr s12, [r4, #4]
 *   @0x17ab50 vmov s4, r2
 *   @0x17ab54 vldr s7, [r4, #36]
 *   @0x17ab58 vcvt.f32.s32 s5, s13
 *   @0x17ab5c vldr s13, [r4, #8]
 *   @0x17ab60 vldr s8, [r4, #28]
 *   @0x17ab64 vldr s9, [r4, #32]
 *   @0x17ab68 vldr d7, [pc, #248]
 *   @0x17ab6c vcvt.f32.s32 s6, s4
 *   @0x17ab70 vsub.f32 s5, s5, s12
 *   @0x17ab74 vsub.f32 s6, s6, s13
 *   @0x17ab78 vabs.f32 s12, s7
 *   @0x17ab7c vmul.f32 s5, s8, s5
 *   @0x17ab80 vmul.f32 s6, s9, s6
 *   @0x17ab84 vcvt.f64.f32 d6, s12
 *   @0x17ab88 vcmpe.f64 d6, d7
 *   @0x17ab8c vdiv.f32 s11, s5, s11
 *   @0x17ab90 vmrs APSR_nzcv, fpscr
 *   @0x17ab94 vdiv.f32 s10, s6, s10
 *   @0x17ab98 bmi 0x17ac18 <_Z24GR_Window_View_Mouse_Setiii+0x138>
 *   @0x17ab9c vldr s21, [pc, #204]
 *   @0x17aba0 vldr s15, [pc, #204]
 *   @0x17aba4 vmul.f32 s7, s7, s21
 *   @0x17aba8 vdiv.f32 s21, s7, s15
 *   @0x17abac vmov.f32 s19, #5.000000e-01
 *   @0x17abb0 vmov r0, s21
 *   @0x17abb4 vmul.f32 s20, s8, s19
 *   @0x17abb8 vmul.f32 s19, s9, s19
 *   @0x17abbc vsub.f32 s18, s11, s20
 *   @0x17abc0 vsub.f32 s17, s10, s19
 *   @0x17abc4 bl 0xb658c <cosf@plt>
 *   @0x17abc8 vmov s16, r0
 *   @0x17abcc vmov r0, s21
 *   @0x17abd0 bl 0xb6580 <sinf@plt>
 *   @0x17abd4 vldr s14, [r4, #20]
 *   @0x17abd8 vldr s15, [r4, #24]
 *   @0x17abdc vadd.f32 s14, s20, s14
 *   @0x17abe0 vadd.f32 s15, s19, s15
 *   @0x17abe4 vmla.f32 s14, s16, s18
 *   @0x17abe8 vmov s13, r0
 *   @0x17abec vmls.f32 s15, s18, s13
 *   @0x17abf0 vmla.f32 s14, s13, s17
 *   @0x17abf4 vmla.f32 s15, s17, s16
 *   @0x17abf8 vcvt.s32.f32 s14, s14
 *   @0x17abfc vcvt.s32.f32 s15, s15
 *   @0x17ac00 vmov r0, s14
 *   @0x17ac04 vmov r1, s15
 *   @0x17ac08 bl 0x17af30 <_Z19GR_Window_Mouse_Setii>
 *   @0x17ac0c add sp, sp, #16
 *   @0x17ac10 vpop {d8, d9, d10}
 *   @0x17ac14 pop {r4, pc}
 *   @0x17ac18 vldr s14, [r4, #20]
 *   @0x17ac1c vldr s15, [r4, #24]
 *   @0x17ac20 vadd.f32 s14, s11, s14
 *   @0x17ac24 vadd.f32 s15, s10, s15
 *   @0x17ac28 b 0x17abf8 <_Z24GR_Window_View_Mouse_Setiii+0x118>
 *   @0x17ac2c vmov s4, r1
 *   @0x17ac30 add r12, sp, #12
 *   @0x17ac34 vmov s13, r2
 *   @0x17ac38 add r3, sp, #8
 *   @0x17ac3c vcvt.f32.s32 s4, s4
 *   @0x17ac40 str r12, [sp]
 *   @0x17ac44 vcvt.f32.s32 s13, s13
 *   @0x17ac48 vmov r1, s4
 *   @0x17ac4c vmov r2, s13
 *   @0x17ac50 bl 0x17a110 <_Z28GR_Window_View_Convert_WorldiffRiS_>
 *   @0x17ac54 vldr s15, [sp, #8]
 *   @0x17ac58 vldr s4, [sp, #12]
 *   @0x17ac5c vcvt.f32.s32 s14, s15
 *   @0x17ac60 vcvt.f32.s32 s15, s4
 *   @0x17ac64 b 0x17abf8 <_Z24GR_Window_View_Mouse_Setiii+0x118>
 *   @0x17ac68 .word 0x47ae147b
 *   @0x17ac6c svclo #0x847ae1
 *   @0x17ac70 ldrdmi r0, r1, [r9], #-251
 *   @0x17ac74 teqmi r4, #0
 *   @0x17ac78 eoreq r5, r7, r0, lsl #16
 *   @0x17ac7c eoreq r2, r7, r12, ror #27
 *
 * ══ §6/76 CDS_Grid::Get_Disk_Sum(RValue&, double, double, double)  0x20441c  size 416  104 条（0x20441c..0x2045bc）
 * @func 0x20441c 0x2045bc  size 416  104 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598×2 / 0xb670c×2
 * 字段偏移 top8: 0x4×4 / 0xc×2 / 0x8×1
 * VFP 指令 56 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20441c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x204420 vpush {d8, d9, d10}
 *   @0x204424 vmov d10, r2, r3
 *   @0x204428 sub sp, sp, #12
 *   @0x20442c vldr d9, [sp, #80]
 *   @0x204430 vsub.f64 d5, d10, d9
 *   @0x204434 mov r5, r1
 *   @0x204438 mov r8, #0
 *   @0x20443c mov r7, r0
 *   @0x204440 str r8, [r1, #0xc]
 *   @0x204444 str r8, [r1]
 *   @0x204448 str r8, [r5, #0x4]
 *   @0x20444c vmov r0, r1, d5
 *   @0x204450 bl 0xb6598 <floor@plt>
 *   @0x204454 ldr r6, [r7, #0x4]
 *   @0x204458 vldr d8, [sp, #72]
 *   @0x20445c sub r4, r6, #1
 *   @0x204460 vmov d7, r0, r1
 *   @0x204464 vcmpe.f64 d7, #0
 *   @0x204468 vmrs APSR_nzcv, fpscr
 *   @0x20446c vcvtpl.s32.f64 s11, d7
 *   @0x204470 vadd.f64 d7, d10, d9
 *   @0x204474 vmovpl r8, s11
 *   @0x204478 vmov r0, r1, d7
 *   @0x20447c bl 0xb670c <ceil@plt>
 *   @0x204480 vmov s10, r4
 *   @0x204484 vcvt.f64.s32 d6, s10
 *   @0x204488 vmov d7, r0, r1
 *   @0x20448c vcmpe.f64 d6, d7
 *   @0x204490 vmrs APSR_nzcv, fpscr
 *   @0x204494 vcvtpl.s32.f64 s11, d7
 *   @0x204498 vsub.f64 d7, d8, d9
 *   @0x20449c vmovpl r4, s11
 *   @0x2044a0 vmov r0, r1, d7
 *   @0x2044a4 bl 0xb6598 <floor@plt>
 *   @0x2044a8 ldr r10, [r7, #0x8]
 *   @0x2044ac sub r10, r10, #1
 *   @0x2044b0 vmov d7, r0, r1
 *   @0x2044b4 vcmpe.f64 d7, #0
 *   @0x2044b8 vmrs APSR_nzcv, fpscr
 *   @0x2044bc vcvtpl.s32.f64 s10, d7
 *   @0x2044c0 movmi r9, #0
 *   @0x2044c4 vadd.f64 d7, d8, d9
 *   @0x2044c8 vmovpl r9, s10
 *   @0x2044cc vmov r0, r1, d7
 *   @0x2044d0 bl 0xb670c <ceil@plt>
 *   @0x2044d4 vmov s10, r10
 *   @0x2044d8 vcvt.f64.s32 d6, s10
 *   @0x2044dc vmov d7, r0, r1
 *   @0x2044e0 vcmpe.f64 d6, d7
 *   @0x2044e4 vmrs APSR_nzcv, fpscr
 *   @0x2044e8 vcvtpl.s32.f64 s11, d7
 *   @0x2044ec vmovpl r10, s11
 *   @0x2044f0 cmp r8, r4
 *   @0x2044f4 bgt 0x2045b0 <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd+0x194>
 *   @0x2044f8 mla r11, r6, r9, r8
 *   @0x2044fc add r4, r4, #1
 *   @0x204500 lsl r6, r6, #4
 *   @0x204504 add r1, r10, #1
 *   @0x204508 lsl r11, r11, #4
 *   @0x20450c cmp r9, r10
 *   @0x204510 bgt 0x2045a0 <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd+0x184>
 *   @0x204514 vmov s10, r8
 *   @0x204518 mov r2, r11
 *   @0x20451c vmul.f64 d4, d9, d9
 *   @0x204520 mov r3, r9
 *   @0x204524 str r4, [sp, #0x4]
 *   @0x204528 vcvt.f64.s32 d6, s10
 *   @0x20452c vsub.f64 d6, d6, d10
 *   @0x204530 vmul.f64 d6, d6, d6
 *   @0x204534 vmov s10, r3
 *   @0x204538 add r3, r3, #1
 *   @0x20453c vcvt.f64.s32 d7, s10
 *   @0x204540 vsub.f64 d7, d7, d8
 *   @0x204544 vmov.f64 d5, d6
 *   @0x204548 vmla.f64 d5, d7, d7
 *   @0x20454c vcmpe.f64 d5, d4
 *   @0x204550 vmrs APSR_nzcv, fpscr
 *   @0x204554 bhi 0x204590 <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd+0x174>
 *   @0x204558 ldr r12, [r7]
 *   @0x20455c add r0, r12, r2
 *   @0x204560 ldr r4, [r0, #0xc]
 *   @0x204564 cmp r4, #0
 *   @0x204568 bne 0x204590 <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd+0x174>
 *   @0x20456c ldr r12, [r12, r2]
 *   @0x204570 vldr s15, [r0, #4]
 *   @0x204574 vldr s10, [r5]
 *   @0x204578 vldr s11, [r5, #4]
 *   @0x20457c vmov s14, r12
 *   @0x204580 vadd.f64 d7, d5, d7
 *   @0x204584 vmov r0, s14
 *   @0x204588 vmov r12, s15
 *   @0x20458c stm r5, {r0, r12}
 *   @0x204590 cmp r3, r1
 *   @0x204594 add r2, r2, r6
 *   @0x204598 bne 0x204534 <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd+0x118>
 *   @0x20459c ldr r4, [sp, #0x4]
 *   @0x2045a0 add r8, r8, #1
 *   @0x2045a4 add r11, r11, #16
 *   @0x2045a8 cmp r8, r4
 *   @0x2045ac bne 0x20450c <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd+0xf0>
 *   @0x2045b0 add sp, sp, #12
 *   @0x2045b4 vpop {d8, d9, d10}
 *   @0x2045b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §7/76 IniFile::WriteIniFile()  0x235d3c  size 416  104 条（0x235d3c..0x235edc）
 * @func 0x235d3c 0x235edc  size 416  104 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×3 / 0xb65bc×3 / IniFile::CalcFileSize() / MemoryManager::Alloc(unsigned int, char const*, int, bool) / EnsureDirectoryIsCreated(char const*) / IniFile::_sysWriteIniFile(char const*, char const*, int)
 * 字段偏移 top8: 0x8×9 / 0x4×7 / 0xc×3 / 0x1×3 / 0x2×2 / 0x18×2 / 0x184×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235d3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x235d40 sub sp, sp, #20
 *   @0x235d44 str r0, [sp, #0x8]
 *   @0x235d48 bl 0x235cb0 <_ZN7IniFile12CalcFileSizeEv>
 *   @0x235d4c ldr r1, [pc, #0x184]
 *   @0x235d50 mov r3, #1
 *   @0x235d54 movw r2, #0x2f5
 *   @0x235d58 add r1, pc, r1
 *   @0x235d5c str r0, [sp, #0xc]
 *   @0x235d60 add r0, r0, #1
 *   @0x235d64 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x235d68 ldr r3, [sp, #0x8]
 *   @0x235d6c ldr r3, [r3, #0x8]
 *   @0x235d70 cmp r3, #0
 *   @0x235d74 str r3, [sp, #0x4]
 *   @0x235d78 movne r5, #0
 *   @0x235d7c movne r8, #13
 *   @0x235d80 movne r7, #10
 *   @0x235d84 movne r6, #34
 *   @0x235d88 mov r4, r0
 *   @0x235d8c beq 0x235e7c <_ZN7IniFile12WriteIniFileEv+0x140>
 *   @0x235d90 mov r3, #91
 *   @0x235d94 strb r3, [r4, r5]
 *   @0x235d98 ldr r3, [sp, #0x4]
 *   @0x235d9c add r5, r5, #1
 *   @0x235da0 ldr r11, [r3, #0x8]
 *   @0x235da4 mov r0, r11
 *   @0x235da8 bl 0xb6538 <strlen@plt>
 *   @0x235dac mov r1, r11
 *   @0x235db0 mov r9, r0
 *   @0x235db4 add r0, r4, r5
 *   @0x235db8 mov r2, r9
 *   @0x235dbc add r9, r5, r9
 *   @0x235dc0 bl 0xb65bc <memcpy@plt>
 *   @0x235dc4 mov r3, r4
 *   @0x235dc8 mov r2, #93
 *   @0x235dcc strb r2, [r3, r9]!
 *   @0x235dd0 strb r8, [r3, #0x1]
 *   @0x235dd4 add r5, r9, #3
 *   @0x235dd8 strb r7, [r3, #0x2]
 *   @0x235ddc ldr r3, [sp, #0x4]
 *   @0x235de0 ldr r9, [r3, #0x4]
 *   @0x235de4 cmp r9, #0
 *   @0x235de8 beq 0x235e68 <_ZN7IniFile12WriteIniFileEv+0x12c>
 *   @0x235dec ldr r11, [r9, #0x4]
 *   @0x235df0 mov r0, r11
 *   @0x235df4 bl 0xb6538 <strlen@plt>
 *   @0x235df8 mov r1, r11
 *   @0x235dfc mov r10, r0
 *   @0x235e00 mov r2, r0
 *   @0x235e04 add r0, r4, r5
 *   @0x235e08 add r5, r5, r10
 *   @0x235e0c bl 0xb65bc <memcpy@plt>
 *   @0x235e10 mov r3, r4
 *   @0x235e14 mov r2, #61
 *   @0x235e18 strb r2, [r3, r5]!
 *   @0x235e1c strb r6, [r3, #0x1]
 *   @0x235e20 add r10, r5, #2
 *   @0x235e24 ldr r11, [r9, #0x8]
 *   @0x235e28 mov r0, r11
 *   @0x235e2c bl 0xb6538 <strlen@plt>
 *   @0x235e30 mov r1, r11
 *   @0x235e34 mov r5, r0
 *   @0x235e38 add r0, r4, r10
 *   @0x235e3c mov r2, r5
 *   @0x235e40 add r10, r10, r5
 *   @0x235e44 bl 0xb65bc <memcpy@plt>
 *   @0x235e48 mov r3, r4
 *   @0x235e4c strb r6, [r3, r10]!
 *   @0x235e50 add r5, r10, #3
 *   @0x235e54 strb r8, [r3, #0x1]
 *   @0x235e58 strb r7, [r3, #0x2]
 *   @0x235e5c ldr r9, [r9]
 *   @0x235e60 cmp r9, #0
 *   @0x235e64 bne 0x235dec <_ZN7IniFile12WriteIniFileEv+0xb0>
 *   @0x235e68 ldr r3, [sp, #0x4]
 *   @0x235e6c ldr r3, [r3]
 *   @0x235e70 cmp r3, #0
 *   @0x235e74 str r3, [sp, #0x4]
 *   @0x235e78 bne 0x235d90 <_ZN7IniFile12WriteIniFileEv+0x54>
 *   @0x235e7c ldr r2, [sp, #0x8]
 *   @0x235e80 ldrb r3, [r2, #0x18]
 *   @0x235e84 cmp r3, #0
 *   @0x235e88 beq 0x235ec0 <_ZN7IniFile12WriteIniFileEv+0x184>
 *   @0x235e8c ldr r2, [sp, #0x8]
 *   @0x235e90 ldr r0, [r2]
 *   @0x235e94 cmp r0, #0
 *   @0x235e98 beq 0x235eb4 <_ZN7IniFile12WriteIniFileEv+0x178>
 *   @0x235e9c bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc>
 *   @0x235ea0 ldr r0, [sp, #0x8]
 *   @0x235ea4 mov r2, r4
 *   @0x235ea8 ldr r3, [sp, #0xc]
 *   @0x235eac ldr r1, [r0]
 *   @0x235eb0 bl 0x235d2c <_ZN7IniFile16_sysWriteIniFileEPKcS1_i>
 *   @0x235eb4 ldr r2, [sp, #0x8]
 *   @0x235eb8 mov r3, #0
 *   @0x235ebc strb r3, [r2, #0x18]
 *   @0x235ec0 ldr r2, [sp, #0xc]
 *   @0x235ec4 mov r3, #0
 *   @0x235ec8 mov r0, r4
 *   @0x235ecc strb r3, [r4, r2]
 *   @0x235ed0 add sp, sp, #20
 *   @0x235ed4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x235ed8 andseq pc, r1, r12, lsl #7
 *
 * ══ §8/76 png_do_write_interlace  0x2b279c  size 416  104 条（0x2b279c..0x2b293c）
 * @func 0x2b279c 0x2b293c  size 416  104 条
 * 部分覆盖: 本节 104/184 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x635020 / anon_2f929c+0x6e0 / __udivsi3
 * 字段偏移 top8: 0x-38×3 / 0x-1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b279c push.w {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2b27a0 mov r12, r2
 *   @0x2b27a4 mov r8, r0
 *   @0x2b27a8 sub sp, #0x38
 *   @0x2b27ac cmp.w r12, #0x5
 *   @0x2b27b0 add.w r6, r5, #0x74
 *   @0x2b27b4 mov r4, sp
 *   @0x2b27b8 mcrgt p5, #0x0, r0, c15, c0, #0x4
 *   @0x2b27bc stm r4!, {r0, r1, r2, r3}
 *   @0x2b27c0 stm r4, {r0, r1, r2}
 *   @0x2b27c4 .word 0xac070007
 *   @0x2b27c8 ldm r5!, {r0, r1, r2, r3}
 *   @0x2b27cc ldm.w r5, {r0, r1, r2}
 *   @0x2b27d0 stm.w r4, {r0, r1, r2}
 *   @0x2b27d4 bgt.w 0x2b2930 <png_do_write_interlace+0x194>
 *   @0x2b27d8 ldrb.w r3, [r8, #0xb]
 *   @0x2b27dc lsl.w r4, r12, #0x2
 *   @0x2b27e0 ldr.w r5, [r8]
 *   @0x2b27e4 cmp r3, #0x2
 *   @0x2b27e8 cmp r3, #0x4
 *   @0x2b27ec cmp r3, #0x1
 *   @0x2b27f0 add r0, sp, #0x38
 *   @0x2b27f4 add r0, r4
 *   @0x2b27f8 movs r3, #0x7
 *   @0x2b27fc .word 0x46861c38
 *   @0x2b2800 cmp r1, r5
 *   @0x2b2804 lsrs r0, r1, #0x3
 *   @0x2b2808 bicmi r12, r8, #0
 *   @0x2b280c and r0, r0, #0x7
 *   @0x2b2810 asr.w r0, r12, r0
 *   @0x2b2814 and r0, r0, #0x1
 *   @0x2b2818 lsls r0, r3
 *   @0x2b281c cbnz r3, 0x2b2828 <png_do_write_interlace+0x8c>
 *   @0x2b2820 mov r2, r3
 *   @0x2b2824 movs r3, #0x7
 *   @0x2b2828 subs r3, #0x1
 *   @0x2b282c strmi r0, [r1], #-3100
 *   @0x2b2830 b 0x2b2800 <png_do_write_interlace+0x64>
 *   @0x2b2834 b 0x2b28c4 <png_do_write_interlace+0x128>
 *   @0x2b2838 mov r6, r7
 *   @0x2b283c movs r2, #0x0
 *   @0x2b2840 ldr r1, [r0, #-56]
 *   @0x2b2844 mov lr, r0
 *   @0x2b2848 bhs 0x2b287a <png_do_write_interlace+0xde>
 *   @0x2b284c ldrb.w r12, [r7, r0]
 *   @0x2b2850 mvns r0, r1
 *   @0x2b2854 subeq r0, r0, r3
 *   @0x2b2858 asr.w r0, r12, r0
 *   @0x2b285c and r0, r0, #0x3
 *   @0x2b2860 lsls r0, r3
 *   @0x2b2864 cbnz r3, 0x2b2870 <png_do_write_interlace+0xd4>
 *   @0x2b2868 mov r2, r3
 *   @0x2b286c movs r3, #0x6
 *   @0x2b2870 subs r3, #0x2
 *   @0x2b2874 strmi r0, [r1], #-3100
 *   @0x2b2878 b 0x2b2846 <png_do_write_interlace+0xaa>
 *   @0x2b287c b 0x2b28c4 <png_do_write_interlace+0x128>
 *   @0x2b2880 mov r6, r7
 *   @0x2b2884 movs r2, #0x0
 *   @0x2b2888 .word 0x46861c38
 *   @0x2b288c cmp r1, r5
 *   @0x2b2890 lsrs r0, r1, #0x1
 *   @0x2b2894 .word 0xf8170f01
 *   @0x2b2898 svclt #0x14c000
 *   @0x2b289c movne r0, #0x0
 *   @0x2b28a0 asr.w r0, r12, r0
 *   @0x2b28a4 and r0, r0, #0xf
 *   @0x2b28a8 lsls r0, r3
 *   @0x2b28ac cbnz r3, 0x2b28b8 <png_do_write_interlace+0x11c>
 *   @0x2b28b0 mov r2, r3
 *   @0x2b28b4 movs r3, #0x4
 *   @0x2b28b8 subs r3, #0x4
 *   @0x2b28bc strmi r0, [r1], #-3100
 *   @0x2b28c0 b 0x2b288c <png_do_write_interlace+0xf0>
 *   @0x2b28c4 beq 0x2b28fa <png_do_write_interlace+0x15e>
 *   @0x2b28c8 b 0x2b28fa <png_do_write_interlace+0x15e>
 *   @0x2b28cc blge 0x635020 <g_SWFaavertbuff+0x61f58>
 *   @0x2b28d0 add r3, r4
 *   @0x2b28d4 ldr r6, [r3, #-56]
 *   @0x2b28d8 mov r10, r3
 *   @0x2b28dc bhs 0x2b28fa <png_do_write_interlace+0x15e>
 *   @0x2b28e0 strmi r7, [r12, #0x106]
 *   @0x2b28e4 beq 0x2b28f0 <png_do_write_interlace+0x154>
 *   @0x2b28e8 mov r2, r9
 *   @0x2b28ec strmi lr, [r4], r8, ror #28
 *   @0x2b28f0 ldr r2, [r10, #-28]
 *   @0x2b28f4 add r12, r9
 *   @0x2b28f8 b 0x2b28da <png_do_write_interlace+0x13e>
 *   @0x2b28fc add r4, r3
 *   @0x2b2900 .word 0xf8543000
 *   @0x2b2904 bllo 0x2f997c <ps_hints_apply+0x857c>
 *   @0x2b2908 ldr r2, [r4, #-56]
 *   @0x2b290c adds r0, r3, r1
 *   @0x2b2910 blx 0x318c48 <__udivsi3>
 *   @0x2b2914 ldrb.w r3, [r8, #0xb]
 *   @0x2b2918 cmp r3, #0x7
 *   @0x2b291c .word 0xd9020000
 *   @0x2b2920 lsrs r3, r3, #0x3
 *   @0x2b2924 b 0x2b292c <png_do_write_interlace+0x190>
 *   @0x2b2928 adds r0, #0x7
 *   @0x2b292c str.w r0, [r8, #0x4]
 *   @0x2b2930 add sp, #0x38
 *   @0x2b2934 svclt #0x87f0
 *   @0x2b2938 bpl 0x2b28a8 <png_do_write_interlace+0x10c>
 *
 * ══ §9/76 F_ActionDrawBackground(RValue&, CInstance*, CInstance*, int, RValue*)  0x140fac  size 412  103 条（0x140fac..0x141148）
 * @func 0x140fac 0x141148  size 412  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x141020→0x47a174, 0x14103c→0x54298c, 0x1410b0→0x54298c
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetFloat(RValue const*, int)×2 / Background_Data(int)×2 / CBackground::DrawTiled(float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)×2 / Background_Exists(int)
 * 字段偏移 top8: 0x1c×3 / 0xc×2 / 0x10×2 / 0x4×2 / 0x8×2 / 0x20×2 / 0x48×1 / 0x16c×1
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140fac push {r4, r5, r6, r7, lr}
 *   @0x140fb0 vpush {d8}
 *   @0x140fb4 sub sp, sp, #44
 *   @0x140fb8 mov r7, r1
 *   @0x140fbc mov r1, #0
 *   @0x140fc0 ldr r4, [sp, #0x48]
 *   @0x140fc4 ldr r5, [pc, #0x16c]
 *   @0x140fc8 mov r0, r4
 *   @0x140fcc add r5, pc, r5
 *   @0x140fd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140fd4 mov r1, #1
 *   @0x140fd8 mov r6, r0
 *   @0x140fdc mov r0, r4
 *   @0x140fe0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140fe4 mov r1, #2
 *   @0x140fe8 vmov s17, r0
 *   @0x140fec mov r0, r4
 *   @0x140ff0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140ff4 mov r1, #3
 *   @0x140ff8 vmov s16, r0
 *   @0x140ffc mov r0, r4
 *   @0x141000 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x141004 cmp r0, #0
 *   @0x141008 mov r0, r6
 *   @0x14100c movle r4, #0
 *   @0x141010 movgt r4, #1
 *   @0x141014 bl 0xc3640 <_Z17Background_Existsi>
 *   @0x141018 subs r1, r0, #0
 *   @0x14101c beq 0x141120 <_Z22F_ActionDrawBackgroundR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x141020 ldr r3, [pc, #0x114]
 *   @0x141024 mov r0, r6
 *   @0x141028 ldr r3, [r5, r3]
 *   @0x14102c ldrb r3, [r3]
 *   @0x141030 cmp r3, #0
 *   @0x141034 bne 0x1410a4 <_Z22F_ActionDrawBackgroundR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x141038 bl 0xc3794 <_Z15Background_Datai>
 *   @0x14103c ldr lr, [pc, #0xfc]
 *   @0x141040 mov r12, #1065353216
 *   @0x141044 mov r3, #0
 *   @0x141048 mvn r6, #-16777216
 *   @0x14104c vmov r1, s17
 *   @0x141050 ldr lr, [r5, lr]
 *   @0x141054 str r3, [sp, #0xc]
 *   @0x141058 str r3, [sp, #0x10]
 *   @0x14105c mov r3, r12
 *   @0x141060 str r4, [sp, #0x4]
 *   @0x141064 str r4, [sp, #0x8]
 *   @0x141068 ldr lr, [lr]
 *   @0x14106c str r12, [sp]
 *   @0x141070 vldr s14, [lr, #16]
 *   @0x141074 vcvt.f32.s32 s15, s14
 *   @0x141078 vmov r2, s16
 *   @0x14107c vstr s15, [sp, #20]
 *   @0x141080 vldr s15, [lr, #20]
 *   @0x141084 vcvt.f32.s32 s15, s15
 *   @0x141088 str r12, [sp, #0x20]
 *   @0x14108c str r6, [sp, #0x1c]
 *   @0x141090 vstr s15, [sp, #24]
 *   @0x141094 bl 0xc22d8 <_ZN11CBackground9DrawTiledEffffbbffffjf>
 *   @0x141098 add sp, sp, #44
 *   @0x14109c vpop {d8}
 *   @0x1410a0 pop {r4, r5, r6, r7, pc}
 *   @0x1410a4 bl 0xc3794 <_Z15Background_Datai>
 *   @0x1410a8 vldr s15, [r7, #180]
 *   @0x1410ac vadd.f32 s15, s17, s15
 *   @0x1410b0 ldr r2, [pc, #0x88]
 *   @0x1410b4 vldr s14, [r7, #184]
 *   @0x1410b8 mov r12, #1065353216
 *   @0x1410bc mov r3, #0
 *   @0x1410c0 mvn lr, #-16777216
 *   @0x1410c4 ldr r2, [r5, r2]
 *   @0x1410c8 str r3, [sp, #0xc]
 *   @0x1410cc str r3, [sp, #0x10]
 *   @0x1410d0 mov r3, r12
 *   @0x1410d4 str r4, [sp, #0x4]
 *   @0x1410d8 str r4, [sp, #0x8]
 *   @0x1410dc ldr r2, [r2]
 *   @0x1410e0 str r12, [sp]
 *   @0x1410e4 vldr s13, [r2, #16]
 *   @0x1410e8 vmov r1, s15
 *   @0x1410ec vcvt.f32.s32 s15, s13
 *   @0x1410f0 vadd.f32 s14, s16, s14
 *   @0x1410f4 vstr s15, [sp, #20]
 *   @0x1410f8 vldr s15, [r2, #20]
 *   @0x1410fc str r12, [sp, #0x20]
 *   @0x141100 str lr, [sp, #0x1c]
 *   @0x141104 vcvt.f32.s32 s15, s15
 *   @0x141108 vmov r2, s14
 *   @0x14110c vstr s15, [sp, #24]
 *   @0x141110 bl 0xc22d8 <_ZN11CBackground9DrawTiledEffffbbffffjf>
 *   @0x141114 add sp, sp, #44
 *   @0x141118 vpop {d8}
 *   @0x14111c pop {r4, r5, r6, r7, pc}
 *   @0x141120 ldr r0, [pc, #0x1c]
 *   @0x141124 add r0, pc, r0
 *   @0x141128 add sp, sp, #44
 *   @0x14112c vpop {d8}
 *   @0x141130 pop {r4, r5, r6, r7, lr}
 *   @0x141134 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x141138 eoreq r0, r11, r4, lsl #25
 *   @0x14113c .word 0xffffbeec
 *   @0x141140 .word 0xffffbcd8
 *   @0x141144 ldrheq pc, [pc], -r8
 *
 * ══ §10/76 LoadSave::fputs(_YYFILE*, char const*)  0x18e114  size 412  103 条（0x18e114..0x18e2b0）
 * @func 0x18e114 0x18e2b0  size 412  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::Write(void const*, unsigned int, unsigned int)×2 / 0xb6538 / LoadSave::fputs(_YYFILE*, char const*)+0x154 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / MemoryManager::Free(void const*) / 0xb65d4
 * 字段偏移 top8: 0x1×4 / 0x-ffc×2 / 0x-1×2 / 0x184×1 / 0xec×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e114 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18e118 sub sp, sp, #4096
 *   @0x18e11c ldr r5, [pc, #0x184]
 *   @0x18e120 sub sp, sp, #12
 *   @0x18e124 add r2, sp, #8192
 *   @0x18e128 mov r6, r0
 *   @0x18e12c ldr r5, [pc, r5]
 *   @0x18e130 mov r0, r1
 *   @0x18e134 mov r7, r1
 *   @0x18e138 ldr r3, [r5]
 *   @0x18e13c str r3, [r2, #-0xffc]
 *   @0x18e140 bl 0xb6538 <strlen@plt>
 *   @0x18e144 cmp r0, #0
 *   @0x18e148 mov r4, r0
 *   @0x18e14c mov r9, r0
 *   @0x18e150 ble 0x18e268 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x154>
 *   @0x18e154 cmp r7, #0
 *   @0x18e158 addeq r7, sp, #4
 *   @0x18e15c ldrb r3, [r7]
 *   @0x18e160 subs r2, r3, #10
 *   @0x18e164 rsbs r3, r2, #0
 *   @0x18e168 adcs r3, r3, r2
 *   @0x18e16c cmp r0, #1
 *   @0x18e170 beq 0x18e1b0 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x9c>
 *   @0x18e174 mov r12, r7
 *   @0x18e178 mov r2, #1
 *   @0x18e17c b 0x18e18c <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x78>
 *   @0x18e180 add r2, r2, #1
 *   @0x18e184 cmp r4, r2
 *   @0x18e188 beq 0x18e1b0 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x9c>
 *   @0x18e18c ldrb lr, [r12, #0x1]!
 *   @0x18e190 cmp lr, #10
 *   @0x18e194 bne 0x18e180 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x6c>
 *   @0x18e198 ldrb r1, [r12, #-0x1]
 *   @0x18e19c add r2, r2, #1
 *   @0x18e1a0 cmp r1, #13
 *   @0x18e1a4 addne r3, r3, #1
 *   @0x18e1a8 cmp r4, r2
 *   @0x18e1ac bne 0x18e18c <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x78>
 *   @0x18e1b0 cmp r3, #0
 *   @0x18e1b4 beq 0x18e28c <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x178>
 *   @0x18e1b8 ldr r1, [pc, #0xec]
 *   @0x18e1bc add r9, r4, r3
 *   @0x18e1c0 movw r2, #0x24a
 *   @0x18e1c4 add r0, r9, #1
 *   @0x18e1c8 add r1, pc, r1
 *   @0x18e1cc mov r3, #1
 *   @0x18e1d0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18e1d4 sub r7, r7, #1
 *   @0x18e1d8 mov r12, #0
 *   @0x18e1dc mov r1, #10
 *   @0x18e1e0 mov r8, r0
 *   @0x18e1e4 mov r2, r0
 *   @0x18e1e8 mov r0, #13
 *   @0x18e1ec b 0x18e204 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0xf0>
 *   @0x18e1f0 add r12, r12, #1
 *   @0x18e1f4 strb lr, [r2]
 *   @0x18e1f8 cmp r4, r12
 *   @0x18e1fc add r2, r2, #1
 *   @0x18e200 beq 0x18e244 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x130>
 *   @0x18e204 ldrb lr, [r7, #0x1]!
 *   @0x18e208 cmp lr, #10
 *   @0x18e20c bne 0x18e1f0 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0xdc>
 *   @0x18e210 cmp r12, #0
 *   @0x18e214 beq 0x18e224 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x110>
 *   @0x18e218 ldrb r3, [r7, #-0x1]
 *   @0x18e21c cmp r3, #13
 *   @0x18e220 beq 0x18e1f0 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0xdc>
 *   @0x18e224 add r12, r12, #1
 *   @0x18e228 mov r3, r2
 *   @0x18e22c cmp r4, r12
 *   @0x18e230 strb r0, [r3], #1
 *   @0x18e234 strb r1, [r2, #0x1]
 *   @0x18e238 mov r2, r3
 *   @0x18e23c add r2, r2, #1
 *   @0x18e240 bne 0x18e204 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0xf0>
 *   @0x18e244 ldr r0, [r6]
 *   @0x18e248 mov r1, r8
 *   @0x18e24c mov r2, #1
 *   @0x18e250 mov r3, r9
 *   @0x18e254 bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x18e258 cmp r8, #0
 *   @0x18e25c beq 0x18e268 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x154>
 *   @0x18e260 mov r0, r8
 *   @0x18e264 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18e268 add r3, sp, #8192
 *   @0x18e26c mov r0, r9
 *   @0x18e270 ldr r2, [r3, #-0xffc]
 *   @0x18e274 ldr r3, [r5]
 *   @0x18e278 cmp r2, r3
 *   @0x18e27c bne 0x18e2a4 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x190>
 *   @0x18e280 add sp, sp, #4096
 *   @0x18e284 add sp, sp, #12
 *   @0x18e288 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18e28c ldr r0, [r6]
 *   @0x18e290 mov r1, r7
 *   @0x18e294 mov r3, r4
 *   @0x18e298 mov r2, #1
 *   @0x18e29c bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x18e2a0 b 0x18e268 <_ZN8LoadSave5fputsEP7_YYFILEPKc+0x154>
 *   @0x18e2a4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x18e2a8 eoreq pc, r5, r4, lsr #16
 *   @0x18e2ac andseq lr, r11, r0, lsl r1
 *
 * ══ §11/76 F_TilemapSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bde54  size 412  103 条（0x1bde54..0x1bdff0）
 * @func 0x1bde54 0x1bdff0  size 412  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1bded4→0x3eb70c, 0x1bdf50→0x3f50e0, 0x1bdf94→0x3eb70c, 0x1bdfa4→0x3eb70c
 * 调用序列: YYGetInt32(RValue const*, int)×4 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / Background_Data(int) / F_TilemapSet(RValue&, CInstance*, CInstance*, int, RValue*)+0x15c
 * 字段偏移 top8: 0x34×4 / 0xc×2 / 0x104×2 / 0x28×2 / 0x44×2 / 0x170×1 / 0x4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bde54 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1bde58 cmp r3, #4
 *   @0x1bde5c ldr r6, [pc, #0x170]
 *   @0x1bde60 mov r4, #0
 *   @0x1bde64 mov r3, #13
 *   @0x1bde68 mov r5, r0
 *   @0x1bde6c add r6, pc, r6
 *   @0x1bde70 str r3, [r0, #0xc]
 *   @0x1bde74 str r4, [r0]
 *   @0x1bde78 str r4, [r0, #0x4]
 *   @0x1bde7c ldr r7, [sp, #0x20]
 *   @0x1bde80 beq 0x1bde98 <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1bde84 ldr r0, [pc, #0x14c]
 *   @0x1bde88 mov r1, r4
 *   @0x1bde8c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1bde90 add r0, pc, r0
 *   @0x1bde94 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bde98 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bde9c mov r1, r4
 *   @0x1bdea0 mov r8, r0
 *   @0x1bdea4 mov r0, r7
 *   @0x1bdea8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bdeac mov r2, r4
 *   @0x1bdeb0 mov r1, r0
 *   @0x1bdeb4 mov r0, r8
 *   @0x1bdeb8 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bdebc subs r4, r0, #0
 *   @0x1bdec0 beq 0x1bded0 <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x1bdec4 ldr r3, [r4]
 *   @0x1bdec8 cmp r3, #5
 *   @0x1bdecc beq 0x1bdef4 <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1bded0 ldr r1, [pc, #0x104]
 *   @0x1bded4 ldr r3, [pc, #0x104]
 *   @0x1bded8 add r1, pc, r1
 *   @0x1bdedc ldr r3, [r6, r3]
 *   @0x1bdee0 ldr r0, [r3]
 *   @0x1bdee4 ldr r3, [r0]
 *   @0x1bdee8 ldr r3, [r3, #0xc]
 *   @0x1bdeec blx r3
 *   @0x1bdef0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1bdef4 ldr r3, [r4, #0x34]
 *   @0x1bdef8 cmp r3, #0
 *   @0x1bdefc beq 0x1bdfa0 <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x1bdf00 mov r1, #2
 *   @0x1bdf04 mov r0, r7
 *   @0x1bdf08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bdf0c mov r1, #3
 *   @0x1bdf10 mov r8, r0
 *   @0x1bdf14 mov r0, r7
 *   @0x1bdf18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bdf1c cmp r8, #0
 *   @0x1bdf20 mov r9, r0
 *   @0x1bdf24 poplt {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1bdf28 ldr r3, [r4, #0x28]
 *   @0x1bdf2c cmp r8, r3
 *   @0x1bdf30 popge {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1bdf34 cmp r0, #0
 *   @0x1bdf38 poplt {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1bdf3c ldr r3, [r4, #0x2c]
 *   @0x1bdf40 cmp r0, r3
 *   @0x1bdf44 popge {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1bdf48 ldr r0, [r4, #0x1c]
 *   @0x1bdf4c bl 0xc3794 <_Z15Background_Datai>
 *   @0x1bdf50 ldr r2, [pc, #0x8c]
 *   @0x1bdf54 ldr r3, [r4, #0x38]
 *   @0x1bdf58 mov r1, #1
 *   @0x1bdf5c ldr r2, [r6, r2]
 *   @0x1bdf60 mov r10, r0
 *   @0x1bdf64 mov r0, r7
 *   @0x1bdf68 ldr r7, [r2]
 *   @0x1bdf6c and r7, r7, r3
 *   @0x1bdf70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bdf74 cmp r10, #0
 *   @0x1bdf78 and r7, r7, r0
 *   @0x1bdf7c ubfx r7, r7, #0x0, #0x13
 *   @0x1bdf80 beq 0x1bdfb0 <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x1bdf84 ldr r3, [r10, #0x34]
 *   @0x1bdf88 cmp r7, r3
 *   @0x1bdf8c blt 0x1bdfb0 <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x1bdf90 ldr r1, [pc, #0x50]
 *   @0x1bdf94 ldr r3, [pc, #0x44]
 *   @0x1bdf98 add r1, pc, r1
 *   @0x1bdf9c b 0x1bdedc <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1bdfa0 ldr r1, [pc, #0x44]
 *   @0x1bdfa4 ldr r3, [pc, #0x34]
 *   @0x1bdfa8 add r1, pc, r1
 *   @0x1bdfac b 0x1bdedc <_Z12F_TilemapSetR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1bdfb0 mov r3, #0
 *   @0x1bdfb4 mov r2, r3
 *   @0x1bdfb8 movt r3, #0x3ff0
 *   @0x1bdfbc stm r5, {r2, r3}
 *   @0x1bdfc0 ldr r2, [r4, #0x28]
 *   @0x1bdfc4 ldr r3, [r4, #0x34]
 *   @0x1bdfc8 mla r8, r2, r9, r8
 *   @0x1bdfcc str r0, [r3, r8, lsl #2]
 *   @0x1bdfd0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1bdfd4 eoreq r3, r3, r4, ror #27
 *   @0x1bdfd8 andseq r0, r9, r8, ror #18
 *   @0x1bdfdc andseq r0, r9, r8, lsl #19
 *   @0x1bdfe0 .word 0xffffbac4
 *   @0x1bdfe4 .word 0xffffebc8
 *   @0x1bdfe8 ldrsheq r0, [r9], -r12
 *   @0x1bdfec andseq r0, r9, r12, ror r8
 *
 * ══ §12/76 CSprite::CreateMask()  0x1e3bcc  size 412  103 条（0x1e3bcc..0x1e3d68）
 * @func 0x1e3bcc 0x1e3d68  size 412  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / CSprite::CreateMask()+0x184×2 / CBitmap32::GetData()×2 / CSprite::CreateMask()+0x174 / CSprite::CreateMask()+0x160 / CSprite::CreateMask()+0xe0 / CSprite::FreeMask()
 * 字段偏移 top8: 0x18×4 / 0x1c×3 / 0x20×3 / 0x40×3 / 0x4×3 / 0x31×2 / 0x48×2 / 0x2×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e3bcc push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e3bd0 mov r8, r0
 *   @0x1e3bd4 ldrb r3, [r0, #0x31]
 *   @0x1e3bd8 cmp r3, #0
 *   @0x1e3bdc bne 0x1e3d5c <_ZN7CSprite10CreateMaskEv+0x190>
 *   @0x1e3be0 ldrb r3, [r8, #0x30]
 *   @0x1e3be4 cmp r3, #0
 *   @0x1e3be8 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e3bec ldrb r3, [r8, #0x32]
 *   @0x1e3bf0 cmp r3, #0
 *   @0x1e3bf4 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e3bf8 ldr r1, [r8, #0x18]
 *   @0x1e3bfc cmp r1, #0
 *   @0x1e3c00 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e3c04 ldr r3, [r8, #0x74]
 *   @0x1e3c08 cmp r3, #0
 *   @0x1e3c0c popne {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e3c10 ldr r3, [r8, #0x54]
 *   @0x1e3c14 cmp r3, #0
 *   @0x1e3c18 beq 0x1e3c28 <_ZN7CSprite10CreateMaskEv+0x5c>
 *   @0x1e3c1c ldrb r3, [r8, #0x36]
 *   @0x1e3c20 cmp r3, #0
 *   @0x1e3c24 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e3c28 ldr r5, [pc, #0x134]
 *   @0x1e3c2c mov r3, #268
 *   @0x1e3c30 lsl r1, r1, #3
 *   @0x1e3c34 add r0, r8, #64
 *   @0x1e3c38 add r5, pc, r5
 *   @0x1e3c3c mov r2, r5
 *   @0x1e3c40 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e3c44 ldr r3, [r8, #0x18]
 *   @0x1e3c48 cmp r3, #0
 *   @0x1e3c4c str r3, [r8, #0x3c]
 *   @0x1e3c50 ble 0x1e3d50 <_ZN7CSprite10CreateMaskEv+0x184>
 *   @0x1e3c54 ldr r1, [r8, #0x1c]
 *   @0x1e3c58 mov r4, #0
 *   @0x1e3c5c ldr r0, [r8, #0x20]
 *   @0x1e3c60 ldr r3, [r8, #0x40]
 *   @0x1e3c64 mul r1, r0, r1
 *   @0x1e3c68 add r0, r3, r4, lsl #3
 *   @0x1e3c6c mov r2, r5
 *   @0x1e3c70 add r0, r0, #4
 *   @0x1e3c74 mov r3, #272
 *   @0x1e3c78 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e3c7c ldr r1, [r8, #0x1c]
 *   @0x1e3c80 ldr r0, [r8, #0x20]
 *   @0x1e3c84 ldr r3, [r8, #0x40]
 *   @0x1e3c88 ldr r12, [r8, #0x18]
 *   @0x1e3c8c mul r1, r0, r1
 *   @0x1e3c90 str r1, [r3, r4, lsl #3]
 *   @0x1e3c94 add r4, r4, #1
 *   @0x1e3c98 cmp r12, r4
 *   @0x1e3c9c bgt 0x1e3c68 <_ZN7CSprite10CreateMaskEv+0x9c>
 *   @0x1e3ca0 cmp r12, #0
 *   @0x1e3ca4 ble 0x1e3d50 <_ZN7CSprite10CreateMaskEv+0x184>
 *   @0x1e3ca8 mov r10, #0
 *   @0x1e3cac ldr r3, [r8, #0x48]
 *   @0x1e3cb0 ldr r0, [r3, r10, lsl #2]
 *   @0x1e3cb4 bl 0x167970 <_ZN9CBitmap327GetDataEv>
 *   @0x1e3cb8 ldr r3, [r8, #0x48]
 *   @0x1e3cbc ldr r0, [r3, r10, lsl #2]
 *   @0x1e3cc0 bl 0x167970 <_ZN9CBitmap327GetDataEv>
 *   @0x1e3cc4 ldr r9, [r8, #0x20]
 *   @0x1e3cc8 cmp r9, #0
 *   @0x1e3ccc ldr r7, [r0, #0x4]
 *   @0x1e3cd0 ble 0x1e3d40 <_ZN7CSprite10CreateMaskEv+0x174>
 *   @0x1e3cd4 ldr r6, [r8, #0x1c]
 *   @0x1e3cd8 mov r4, #0
 *   @0x1e3cdc sub r7, r7, #4
 *   @0x1e3ce0 lsl r11, r10, #3
 *   @0x1e3ce4 mov r5, r4
 *   @0x1e3ce8 lsl r0, r6, #2
 *   @0x1e3cec cmp r6, #0
 *   @0x1e3cf0 ble 0x1e3d2c <_ZN7CSprite10CreateMaskEv+0x160>
 *   @0x1e3cf4 ldr r3, [r8, #0x40]
 *   @0x1e3cf8 mov r2, r7
 *   @0x1e3cfc add r3, r3, r11
 *   @0x1e3d00 ldr r3, [r3, #0x4]
 *   @0x1e3d04 add r12, r3, r6
 *   @0x1e3d08 add r3, r3, r4
 *   @0x1e3d0c add r12, r12, r4
 *   @0x1e3d10 ldr r1, [r2, #0x4]!
 *   @0x1e3d14 tst r1, #-16777216
 *   @0x1e3d18 moveq r1, #0
 *   @0x1e3d1c movne r1, #1
 *   @0x1e3d20 strb r1, [r3], #1
 *   @0x1e3d24 cmp r3, r12
 *   @0x1e3d28 bne 0x1e3d10 <_ZN7CSprite10CreateMaskEv+0x144>
 *   @0x1e3d2c add r5, r5, #1
 *   @0x1e3d30 add r7, r7, r0
 *   @0x1e3d34 cmp r5, r9
 *   @0x1e3d38 add r4, r4, r6
 *   @0x1e3d3c bne 0x1e3cec <_ZN7CSprite10CreateMaskEv+0x120>
 *   @0x1e3d40 ldr r3, [r8, #0x18]
 *   @0x1e3d44 add r10, r10, #1
 *   @0x1e3d48 cmp r10, r3
 *   @0x1e3d4c blt 0x1e3cac <_ZN7CSprite10CreateMaskEv+0xe0>
 *   @0x1e3d50 mov r3, #1
 *   @0x1e3d54 strb r3, [r8, #0x31]
 *   @0x1e3d58 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e3d5c bl 0x1e3b58 <_ZN7CSprite8FreeMaskEv>
 *   @0x1e3d60 b 0x1e3be0 <_ZN7CSprite10CreateMaskEv+0x14>
 *   @0x1e3d64 andseq lr, r6, r12, ror #15
 *
 * ══ §13/76 CPhysicsWorld::CreatePulleyJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, float, float, float, float, float, bool)  0x2392a8  size 412  103 条（0x2392a8..0x239444）
 * @func 0x2392a8 0x239444  size 412  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2PulleyJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&, b2Vec2 const&, b2Vec2 const&, b2Vec2 const&, float) / CPhysicsJointFactory::CreateJoint(CPhysicsWorld*, b2JointDef const&)
 * 字段偏移 top8: 0x4×3 / 0x40×2 / 0x8×2 / 0xb4×1 / 0xb8×1 / 0x34×1 / 0x38×1 / 0x3c×1
 * VFP 指令 43 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2392a8 push {r4, r5, r6, r7, lr}
 *   @0x2392ac vpush {d8, d9}
 *   @0x2392b0 sub sp, sp, #116
 *   @0x2392b4 vldr s12, [sp, #168]
 *   @0x2392b8 ldr r1, [r1]
 *   @0x2392bc vldr s14, [sp, #176]
 *   @0x2392c0 ldr r2, [r2]
 *   @0x2392c4 vldr s5, [r1, #24]
 *   @0x2392c8 vldr s7, [r1, #20]
 *   @0x2392cc vldr s10, [r2, #20]
 *   @0x2392d0 vldr s8, [r2, #24]
 *   @0x2392d4 vmul.f32 s11, s12, s5
 *   @0x2392d8 vldr s6, [sp, #164]
 *   @0x2392dc vldr s9, [sp, #172]
 *   @0x2392e0 vmov s18, r3
 *   @0x2392e4 mov r4, r0
 *   @0x2392e8 vldr s15, [r4, #96]
 *   @0x2392ec ldrh r3, [r1, #4]
 *   @0x2392f0 vldr s2, [r1, #12]
 *   @0x2392f4 vldr s1, [r1, #16]
 *   @0x2392f8 tst r3, #2
 *   @0x2392fc vldr s4, [r2, #12]
 *   @0x239300 orreq r3, r3, #2
 *   @0x239304 strheq r3, [r1, #4]
 *   @0x239308 ldrh r3, [r2, #4]
 *   @0x23930c moveq r0, #0
 *   @0x239310 streq r0, [r1, #0xa0]
 *   @0x239314 vldr s3, [r2, #16]
 *   @0x239318 tst r3, #2
 *   @0x23931c vldr s0, [sp, #160]
 *   @0x239320 orreq r3, r3, #2
 *   @0x239324 mov r12, #0
 *   @0x239328 strheq r3, [r2, #4]
 *   @0x23932c moveq r0, #0
 *   @0x239330 vmul.f32 s13, s14, s8
 *   @0x239334 streq r0, [r2, #0xa0]
 *   @0x239338 mov r3, #0
 *   @0x23933c vldr s17, [sp, #152]
 *   @0x239340 vldr s16, [sp, #156]
 *   @0x239344 ldr r7, [sp, #0xb4]
 *   @0x239348 ldrb r6, [sp, #0xb8]
 *   @0x23934c mov r0, #4
 *   @0x239350 str r12, [sp, #0x34]
 *   @0x239354 add r5, sp, #48
 *   @0x239358 str r12, [sp, #0x38]
 *   @0x23935c mov lr, #0
 *   @0x239360 str r12, [sp, #0x3c]
 *   @0x239364 mov r12, #1
 *   @0x239368 str r0, [sp, #0x30]
 *   @0x23936c mov r0, r5
 *   @0x239370 str r3, [sp, #0x58]
 *   @0x239374 movt lr, #0xbf80
 *   @0x239378 str r3, [sp, #0x60]
 *   @0x23937c str r3, [sp, #0x64]
 *   @0x239380 str r3, [sp, #0x68]
 *   @0x239384 add r3, sp, #16
 *   @0x239388 vmul.f32 s12, s12, s7
 *   @0x23938c strb r12, [sp, #0x40]
 *   @0x239390 str r7, [sp, #0xc]
 *   @0x239394 mov r12, #1065353216
 *   @0x239398 str r12, [sp, #0x48]
 *   @0x23939c str r12, [sp, #0x4c]
 *   @0x2393a0 str r12, [sp, #0x50]
 *   @0x2393a4 str r12, [sp, #0x5c]
 *   @0x2393a8 str r12, [sp, #0x6c]
 *   @0x2393ac add r12, sp, #24
 *   @0x2393b0 str r12, [sp]
 *   @0x2393b4 add r12, sp, #32
 *   @0x2393b8 str r12, [sp, #0x4]
 *   @0x2393bc add r12, sp, #40
 *   @0x2393c0 str r12, [sp, #0x8]
 *   @0x2393c4 str lr, [sp, #0x44]
 *   @0x2393c8 str lr, [sp, #0x54]
 *   @0x2393cc vmul.f32 s14, s14, s10
 *   @0x2393d0 vnmls.f32 s12, s6, s5
 *   @0x2393d4 vnmls.f32 s14, s9, s8
 *   @0x2393d8 vmla.f32 s11, s6, s7
 *   @0x2393dc vmla.f32 s13, s9, s10
 *   @0x2393e0 vmul.f32 s10, s15, s18
 *   @0x2393e4 vmul.f32 s9, s15, s17
 *   @0x2393e8 vstr s10, [sp, #16]
 *   @0x2393ec vmul.f32 s10, s15, s16
 *   @0x2393f0 vstr s9, [sp, #20]
 *   @0x2393f4 vmul.f32 s15, s15, s0
 *   @0x2393f8 vstr s10, [sp, #24]
 *   @0x2393fc vadd.f32 s11, s11, s1
 *   @0x239400 vstr s15, [sp, #28]
 *   @0x239404 vadd.f32 s12, s12, s2
 *   @0x239408 vstr s11, [sp, #36]
 *   @0x23940c vadd.f32 s13, s13, s3
 *   @0x239410 vstr s12, [sp, #32]
 *   @0x239414 vadd.f32 s14, s14, s4
 *   @0x239418 vstr s13, [sp, #44]
 *   @0x23941c vstr s14, [sp, #40]
 *   @0x239420 bl 0x2d0f08 <_ZN16b2PulleyJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_S4_S4_f>
 *   @0x239424 mov r1, r5
 *   @0x239428 mov r0, r4
 *   @0x23942c strb r6, [sp, #0x40]
 *   @0x239430 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef>
 *   @0x239434 ldr r0, [r0, #0x8]
 *   @0x239438 add sp, sp, #116
 *   @0x23943c vpop {d8, d9}
 *   @0x239440 pop {r4, r5, r6, r7, pc}
 *
 * ══ §14/76 _spColorTimeline_apply  0x28202c  size 412  103 条（0x28202c..0x2821c8）
 * @func 0x28202c 0x2821c8  size 412  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spColorTimeline_apply+0x98 / anon_280ed0 / spCurveTimeline_getCurvePercent
 * 字段偏移 top8: 0x10×2 / 0x14×2 / 0xc×1 / 0x2×1
 * VFP 指令 68 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28202c push {r3, r4, r5, r6, r7, lr}
 *   @0x282030 vpush {d8, d9, d10}
 *   @0x282034 vmov s16, r3
 *   @0x282038 vldr s17, [sp, #56]
 *   @0x28203c ldr r5, [r0, #0x10]
 *   @0x282040 vldr s15, [r5]
 *   @0x282044 vcmpe.f32 s15, s16
 *   @0x282048 mov r4, r0
 *   @0x28204c mov r6, r1
 *   @0x282050 vmrs APSR_nzcv, fpscr
 *   @0x282054 bgt 0x2820bc <_spColorTimeline_apply+0x90>
 *   @0x282058 ldr r1, [r0, #0xc]
 *   @0x28205c sub r3, r1, #-1073741819
 *   @0x282060 lsl r3, r3, #2
 *   @0x282064 add r2, r5, r3
 *   @0x282068 vldr s15, [r2]
 *   @0x28206c vcmpe.f32 s16, s15
 *   @0x282070 vmrs APSR_nzcv, fpscr
 *   @0x282074 blt 0x2820c4 <_spColorTimeline_apply+0x98>
 *   @0x282078 add r3, r3, #4
 *   @0x28207c add r5, r5, r3
 *   @0x282080 vldr s11, [r5]
 *   @0x282084 vldr s12, [r5, #4]
 *   @0x282088 vldr s13, [r5, #8]
 *   @0x28208c vldr s14, [r5, #12]
 *   @0x282090 vmov.f32 s15, #1.000000e+00
 *   @0x282094 ldr r2, [r4, #0x14]
 *   @0x282098 ldr r3, [r6, #0x14]
 *   @0x28209c ldr r3, [r3, r2, lsl #2]
 *   @0x2820a0 vcmpe.f32 s17, s15
 *   @0x2820a4 vmrs APSR_nzcv, fpscr
 *   @0x2820a8 bmi 0x282180 <_spColorTimeline_apply+0x154>
 *   @0x2820ac vstr s11, [r3, #8]
 *   @0x2820b0 vstr s12, [r3, #12]
 *   @0x2820b4 vstr s13, [r3, #16]
 *   @0x2820b8 vstr s14, [r3, #20]
 *   @0x2820bc vpop {d8, d9, d10}
 *   @0x2820c0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2820c4 vmov.f32 s0, s16
 *   @0x2820c8 mov r0, r5
 *   @0x2820cc mov r2, #5
 *   @0x2820d0 bl 0x280ed0 <printbuf_free+0x20>
 *   @0x2820d4 movw r2, #0x6667
 *   @0x2820d8 movt r2, #0x6666
 *   @0x2820dc vmov.f32 s14, #1.000000e+00
 *   @0x2820e0 sub r7, r0, #4
 *   @0x2820e4 mvn r1, r0
 *   @0x2820e8 smull r3, r2, r2, r0
 *   @0x2820ec lsl r7, r7, #2
 *   @0x2820f0 add r5, r5, r7
 *   @0x2820f4 vldr s15, [r5, #16]
 *   @0x2820f8 vldr s13, [r5, #-4]
 *   @0x2820fc vsub.f32 s16, s16, s15
 *   @0x282100 lsr r1, r1, #31
 *   @0x282104 mov r0, r4
 *   @0x282108 vldr s21, [r5]
 *   @0x28210c vldr s20, [r5, #4]
 *   @0x282110 rsb r1, r1, r2, asr #1
 *   @0x282114 vldr s19, [r5, #8]
 *   @0x282118 vldr s18, [r5, #12]
 *   @0x28211c vsub.f32 s15, s13, s15
 *   @0x282120 vdiv.f32 s15, s16, s15
 *   @0x282124 vsub.f32 s14, s14, s15
 *   @0x282128 vmov r2, s14
 *   @0x28212c bl 0x2818e0 <spCurveTimeline_getCurvePercent>
 *   @0x282130 ldr r3, [r4, #0x10]
 *   @0x282134 add r3, r3, r7
 *   @0x282138 vldr s11, [r3, #20]
 *   @0x28213c vldr s12, [r3, #24]
 *   @0x282140 vsub.f32 s11, s11, s21
 *   @0x282144 vldr s13, [r3, #28]
 *   @0x282148 vldr s14, [r3, #32]
 *   @0x28214c vsub.f32 s12, s12, s20
 *   @0x282150 vsub.f32 s13, s13, s19
 *   @0x282154 vmov s15, r0
 *   @0x282158 vsub.f32 s14, s14, s18
 *   @0x28215c vmla.f32 s21, s11, s15
 *   @0x282160 vmla.f32 s20, s12, s15
 *   @0x282164 vmla.f32 s19, s13, s15
 *   @0x282168 vmla.f32 s18, s14, s15
 *   @0x28216c vmov.f32 s11, s21
 *   @0x282170 vmov.f32 s12, s20
 *   @0x282174 vmov.f32 s13, s19
 *   @0x282178 vmov.f32 s14, s18
 *   @0x28217c b 0x282090 <_spColorTimeline_apply+0x64>
 *   @0x282180 vldr s8, [r3, #8]
 *   @0x282184 vldr s9, [r3, #12]
 *   @0x282188 vldr s10, [r3, #16]
 *   @0x28218c vldr s15, [r3, #20]
 *   @0x282190 vsub.f32 s11, s11, s8
 *   @0x282194 vsub.f32 s12, s12, s9
 *   @0x282198 vsub.f32 s13, s13, s10
 *   @0x28219c vsub.f32 s14, s14, s15
 *   @0x2821a0 vmla.f32 s8, s11, s17
 *   @0x2821a4 vmla.f32 s9, s12, s17
 *   @0x2821a8 vstr s8, [r3, #8]
 *   @0x2821ac vmla.f32 s10, s13, s17
 *   @0x2821b0 vstr s9, [r3, #12]
 *   @0x2821b4 vmla.f32 s15, s14, s17
 *   @0x2821b8 vstr s10, [r3, #16]
 *   @0x2821bc vpop {d8, d9, d10}
 *   @0x2821c0 vstr s15, [r3, #20]
 *   @0x2821c4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §15/76 RelyTick()  0x29a5c8  size 412  103 条（0x29a5c8..0x29a764）
 * @func 0x29a5c8 0x29a764  size 412  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29a5dc→0x7578e4, 0x29a5fc→0x3f7804, 0x29a65c→0x7578dc, 0x29a68c→0x3f7808
 * 调用序列: __floatdisf×3 / Timing_Time×2 / RelyTick()+0x178×2 / RelyTick()+0x48 / RelyAckSendToClient(SRelyAck*) / RelyAddPacket(SRelyEntry*) / RelyRemovePacket(SRelyEntry*) / RelySendData(int, char const*, int, int, int)
 * 字段偏移 top8: 0x20×3 / 0x170×2 / 0x40c×2 / 0x154×1 / 0xf8×1 / 0xcc×1 / 0x10×1 / 0x8×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29a5c8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x29a5cc vpush {d8}
 *   @0x29a5d0 sub sp, sp, #8
 *   @0x29a5d4 bl 0x215148 <Timing_Time>
 *   @0x29a5d8 ldr r6, [pc, #0x170]
 *   @0x29a5dc ldr r3, [pc, #0x170]
 *   @0x29a5e0 add r6, pc, r6
 *   @0x29a5e4 ldr r3, [r6, r3]
 *   @0x29a5e8 ldr r7, [r3]
 *   @0x29a5ec cmp r7, #0
 *   @0x29a5f0 mov r4, r0
 *   @0x29a5f4 mov r5, r1
 *   @0x29a5f8 beq 0x29a658 <_Z8RelyTickv+0x90>
 *   @0x29a5fc ldr r3, [pc, #0x154]
 *   @0x29a600 movw r9, #0x418
 *   @0x29a604 vldr s16, [pc, #320]
 *   @0x29a608 ldr r8, [r6, r3]
 *   @0x29a60c b 0x29a61c <_Z8RelyTickv+0x54>
 *   @0x29a610 ldr r7, [r7, #0x40c]
 *   @0x29a614 cmp r7, #0
 *   @0x29a618 beq 0x29a658 <_Z8RelyTickv+0x90>
 *   @0x29a61c ldrd r0, r1, [r7, r9]
 *   @0x29a620 subs r0, r4, r0
 *   @0x29a624 sbc r1, r5, r1
 *   @0x29a628 bl 0x319398 <__floatdisf>
 *   @0x29a62c vldr s15, [r8]
 *   @0x29a630 vmov s13, r0
 *   @0x29a634 vdiv.f32 s14, s13, s16
 *   @0x29a638 vcmpe.f32 s14, s15
 *   @0x29a63c vmrs APSR_nzcv, fpscr
 *   @0x29a640 ble 0x29a610 <_Z8RelyTickv+0x48>
 *   @0x29a644 mov r0, r7
 *   @0x29a648 bl 0x29a2c8 <_Z19RelyAckSendToClientP8SRelyAck>
 *   @0x29a64c ldr r7, [r7, #0x40c]
 *   @0x29a650 cmp r7, #0
 *   @0x29a654 bne 0x29a61c <_Z8RelyTickv+0x54>
 *   @0x29a658 bl 0x215148 <Timing_Time>
 *   @0x29a65c ldr r3, [pc, #0xf8]
 *   @0x29a660 ldr r3, [r6, r3]
 *   @0x29a664 ldr r7, [r3]
 *   @0x29a668 cmp r7, #0
 *   @0x29a66c mov r4, r0
 *   @0x29a670 mov r5, r1
 *   @0x29a674 beq 0x29a740 <_Z8RelyTickv+0x178>
 *   @0x29a678 ldrd r0, r1, [r7, #24]
 *   @0x29a67c vldr s16, [pc, #200]
 *   @0x29a680 subs r0, r4, r0
 *   @0x29a684 sbc r1, r5, r1
 *   @0x29a688 bl 0x319398 <__floatdisf>
 *   @0x29a68c ldr r3, [pc, #0xcc]
 *   @0x29a690 ldr r6, [r6, r3]
 *   @0x29a694 vldr s15, [r6]
 *   @0x29a698 vmov s13, r0
 *   @0x29a69c vdiv.f32 s14, s13, s16
 *   @0x29a6a0 vcmpe.f32 s14, s15
 *   @0x29a6a4 vmrs APSR_nzcv, fpscr
 *   @0x29a6a8 ble 0x29a740 <_Z8RelyTickv+0x178>
 *   @0x29a6ac mvn r8, #0
 *   @0x29a6b0 mov r9, #0
 *   @0x29a6b4 b 0x29a6f4 <_Z8RelyTickv+0x12c>
 *   @0x29a6b8 strd r4, r5, [r7, #24]
 *   @0x29a6bc bl 0x299a9c <_Z13RelyAddPacketP10SRelyEntry>
 *   @0x29a6c0 ldr r7, [r7, #0x20]
 *   @0x29a6c4 cmp r7, #0
 *   @0x29a6c8 beq 0x29a740 <_Z8RelyTickv+0x178>
 *   @0x29a6cc ldrd r0, r1, [r7, #24]
 *   @0x29a6d0 subs r0, r4, r0
 *   @0x29a6d4 sbc r1, r5, r1
 *   @0x29a6d8 bl 0x319398 <__floatdisf>
 *   @0x29a6dc vldr s15, [r6]
 *   @0x29a6e0 vmov s13, r0
 *   @0x29a6e4 vdiv.f32 s14, s13, s16
 *   @0x29a6e8 vcmpe.f32 s14, s15
 *   @0x29a6ec vmrs APSR_nzcv, fpscr
 *   @0x29a6f0 ble 0x29a740 <_Z8RelyTickv+0x178>
 *   @0x29a6f4 mov r0, r7
 *   @0x29a6f8 bl 0x299b9c <_Z16RelyRemovePacketP10SRelyEntry>
 *   @0x29a6fc ldr r0, [r7, #0x10]
 *   @0x29a700 ldr r1, [r7, #0x8]
 *   @0x29a704 ldr r2, [r7, #0xc]
 *   @0x29a708 ldr r3, [r7, #0x4]
 *   @0x29a70c str r8, [sp]
 *   @0x29a710 bl 0x299ff8 <_Z12RelySendDataiPKciii>
 *   @0x29a714 cmp r0, #0
 *   @0x29a718 mov r0, r7
 *   @0x29a71c bge 0x29a6b8 <_Z8RelyTickv+0xf0>
 *   @0x29a720 ldr r10, [r7, #0x20]
 *   @0x29a724 mov r0, r7
 *   @0x29a728 str r9, [r7, #0x24]
 *   @0x29a72c str r9, [r7, #0x20]
 *   @0x29a730 bl 0x299be8 <_Z16RelyDeletePacketP10SRelyEntry>
 *   @0x29a734 mov r7, r10
 *   @0x29a738 cmp r7, #0
 *   @0x29a73c bne 0x29a6cc <_Z8RelyTickv+0x104>
 *   @0x29a740 add sp, sp, #8
 *   @0x29a744 vpop {d8}
 *   @0x29a748 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x29a74c ldmdbmi r4!, {r10, sp} ^
 *   @0x29a750 andseq r7, r5, r0, ror r6
 *   @0x29a754 .word 0xfffffd98
 *   @0x29a758 .word 0xfffffd9c
 *   @0x29a75c .word 0xfffffda4
 *   @0x29a760 .word 0xfffffda0
 *
 * ══ §16/76 AddScripts(Buffer_Standard*)  0x29ec54  size 412  103 条（0x29ec54..0x29edf0）
 * @func 0x29ec54 0x29edf0  size 412  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AddScripts(Buffer_Standard*)+0x190 / AddScripts(Buffer_Standard*)+0x10c / WriteString(Buffer_Standard*, char const*)
 * 字段偏移 top8: 0x8×6 / 0x30×5 / 0x38×5 / 0x10×5 / 0x2c×3 / 0x4×3 / 0x1c×2 / 0x188×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29ec54 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29ec58 add r7, r0, #44
 *   @0x29ec5c ldr r8, [pc, #0x188]
 *   @0x29ec60 sub sp, sp, #12
 *   @0x29ec64 ldr r3, [r0]
 *   @0x29ec68 mov r6, #0
 *   @0x29ec6c ldr r8, [pc, r8]
 *   @0x29ec70 ldr r4, [r0, #0x1c]
 *   @0x29ec74 str r6, [r0, #0x2c]
 *   @0x29ec78 mov r2, r7
 *   @0x29ec7c ldr r9, [r8]
 *   @0x29ec80 mov r1, #5
 *   @0x29ec84 str r6, [r0, #0x30]
 *   @0x29ec88 mov r10, r0
 *   @0x29ec8c str r6, [r0, #0x38]
 *   @0x29ec90 ldr r3, [r3, #0x8]
 *   @0x29ec94 str r4, [sp, #0x4]
 *   @0x29ec98 blx r3
 *   @0x29ec9c cmp r9, r6
 *   @0x29eca0 ble 0x29ede4 <_Z10AddScriptsP15Buffer_Standard+0x190>
 *   @0x29eca4 ldr r2, [r8, #0x4]
 *   @0x29eca8 mov r12, #0
 *   @0x29ecac ldr r3, [r10]
 *   @0x29ecb0 mov r1, #5
 *   @0x29ecb4 mov r0, r10
 *   @0x29ecb8 ldr r11, [r2, r6, lsl #2]
 *   @0x29ecbc mov r2, r7
 *   @0x29ecc0 add r6, r6, #1
 *   @0x29ecc4 ldr r4, [r11, #0x10]
 *   @0x29ecc8 str r12, [r10, #0x38]
 *   @0x29eccc vmov s15, r4
 *   @0x29ecd0 vcvt.f64.u32 d7, s15
 *   @0x29ecd4 vmov r4, r5, d7
 *   @0x29ecd8 vstr s14, [r10, #44]
 *   @0x29ecdc str r5, [r10, #0x30]
 *   @0x29ece0 ldr r3, [r3, #0x8]
 *   @0x29ece4 blx r3
 *   @0x29ece8 ldr r12, [r11, #0x10]
 *   @0x29ecec mov r1, #12
 *   @0x29ecf0 mov r2, r7
 *   @0x29ecf4 cmp r12, #0
 *   @0x29ecf8 mov r0, r10
 *   @0x29ecfc ldr r3, [r11, #0x8]
 *   @0x29ed00 blt 0x29ed60 <_Z10AddScriptsP15Buffer_Standard+0x10c>
 *   @0x29ed04 ldr lr, [r3, #0x50]
 *   @0x29ed08 mov r4, #10
 *   @0x29ed0c ldr r3, [r3, #0x6c]
 *   @0x29ed10 ldr r12, [r10]
 *   @0x29ed14 ldr lr, [lr, #0x10]
 *   @0x29ed18 str r4, [r10, #0x38]
 *   @0x29ed1c adds r4, lr, r3
 *   @0x29ed20 asr r5, lr, #31
 *   @0x29ed24 str lr, [r10, #0x2c]
 *   @0x29ed28 str r5, [r10, #0x30]
 *   @0x29ed2c adc r5, r5, r3, asr #31
 *   @0x29ed30 ldr r3, [r12, #0x8]
 *   @0x29ed34 blx r3
 *   @0x29ed38 ldr r3, [r10]
 *   @0x29ed3c str r4, [r10, #0x2c]
 *   @0x29ed40 mov r12, #10
 *   @0x29ed44 str r5, [r10, #0x30]
 *   @0x29ed48 mov r0, r10
 *   @0x29ed4c mov r1, #12
 *   @0x29ed50 str r12, [r10, #0x38]
 *   @0x29ed54 mov r2, r7
 *   @0x29ed58 ldr r3, [r3, #0x8]
 *   @0x29ed5c blx r3
 *   @0x29ed60 ldr r1, [r11, #0x14]
 *   @0x29ed64 mov r0, r10
 *   @0x29ed68 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29ed6c cmp r6, r9
 *   @0x29ed70 bne 0x29eca4 <_Z10AddScriptsP15Buffer_Standard+0x50>
 *   @0x29ed74 ldr r3, [r10]
 *   @0x29ed78 mov r1, #0
 *   @0x29ed7c ldr r2, [sp, #0x4]
 *   @0x29ed80 mov r0, r10
 *   @0x29ed84 mov r6, r1
 *   @0x29ed88 ldr r8, [r10, #0x1c]
 *   @0x29ed8c ldr r3, [r3, #0x10]
 *   @0x29ed90 blx r3
 *   @0x29ed94 vmov s15, r9
 *   @0x29ed98 ldr r3, [r10]
 *   @0x29ed9c mov r2, r7
 *   @0x29eda0 vcvt.f64.s32 d7, s15
 *   @0x29eda4 str r6, [r10, #0x38]
 *   @0x29eda8 mov r0, r10
 *   @0x29edac mov r1, #5
 *   @0x29edb0 vmov r4, r5, d7
 *   @0x29edb4 vstr s14, [r10, #44]
 *   @0x29edb8 str r5, [r10, #0x30]
 *   @0x29edbc ldr r3, [r3, #0x8]
 *   @0x29edc0 blx r3
 *   @0x29edc4 ldr r3, [r10]
 *   @0x29edc8 mov r1, r6
 *   @0x29edcc mov r2, r8
 *   @0x29edd0 mov r0, r10
 *   @0x29edd4 ldr r3, [r3, #0x10]
 *   @0x29edd8 blx r3
 *   @0x29eddc add sp, sp, #12
 *   @0x29ede0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29ede4 mov r9, r6
 *   @0x29ede8 b 0x29ed74 <_Z10AddScriptsP15Buffer_Standard+0x120>
 *   @0x29edec ldrheq r2, [r5], -r12
 *
 * ══ §17/76 __aeabi_frsub  0x3191c4  size 412  103 条（0x3191c4..0x319360）
 * @func 0x3191c4 0x319360  size 412  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_fadd+0xbc / __aeabi_fadd+0xa8
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3191c4 eor r0, r0, #-2147483648
 *   @0x3191c8 b 0x3191d0 <__aeabi_fadd>
 *   @0x3191cc eor r1, r1, #-2147483648
 *   @0x3191d0 lsls r2, r0, #1
 *   @0x3191d4 lslsne r3, r1, #1
 *   @0x3191d8 teqne r2, r3
 *   @0x3191dc mvnsne r12, r2, asr #24
 *   @0x3191e0 mvnsne r12, r3, asr #24
 *   @0x3191e4 beq 0x3192dc <__aeabi_fadd+0x10c>
 *   @0x3191e8 lsr r2, r2, #24
 *   @0x3191ec rsbs r3, r2, r3, lsr #24
 *   @0x3191f0 addgt r2, r2, r3
 *   @0x3191f4 eorgt r1, r0, r1
 *   @0x3191f8 eorgt r0, r1, r0
 *   @0x3191fc eorgt r1, r0, r1
 *   @0x319200 rsblt r3, r3, #0
 *   @0x319204 cmp r3, #25
 *   @0x319208 bxhi lr
 *   @0x31920c tst r0, #-2147483648
 *   @0x319210 orr r0, r0, #8388608
 *   @0x319214 bic r0, r0, #-16777216
 *   @0x319218 rsbne r0, r0, #0
 *   @0x31921c tst r1, #-2147483648
 *   @0x319220 orr r1, r1, #8388608
 *   @0x319224 bic r1, r1, #-16777216
 *   @0x319228 rsbne r1, r1, #0
 *   @0x31922c teq r2, r3
 *   @0x319230 beq 0x3192c4 <__aeabi_fadd+0xf4>
 *   @0x319234 sub r2, r2, #1
 *   @0x319238 adds r0, r0, r1, asr r3
 *   @0x31923c rsb r3, r3, #32
 *   @0x319240 lsl r1, r1, r3
 *   @0x319244 and r3, r0, #-2147483648
 *   @0x319248 bpl 0x319254 <__aeabi_fadd+0x84>
 *   @0x31924c rsbs r1, r1, #0
 *   @0x319250 rsc r0, r0, #0
 *   @0x319254 cmp r0, #8388608
 *   @0x319258 blo 0x31928c <__aeabi_fadd+0xbc>
 *   @0x31925c cmp r0, #16777216
 *   @0x319260 blo 0x319278 <__aeabi_fadd+0xa8>
 *   @0x319264 lsrs r0, r0, #1
 *   @0x319268 rrx r1, r1
 *   @0x31926c add r2, r2, #1
 *   @0x319270 cmp r2, #254
 *   @0x319274 bhs 0x319330 <__aeabi_fadd+0x160>
 *   @0x319278 cmp r1, #-2147483648
 *   @0x31927c adc r0, r0, r2, lsl #23
 *   @0x319280 biceq r0, r0, #1
 *   @0x319284 orr r0, r0, r3
 *   @0x319288 bx lr
 *   @0x31928c lsls r1, r1, #1
 *   @0x319290 adc r0, r0, r0
 *   @0x319294 tst r0, #8388608
 *   @0x319298 sub r2, r2, #1
 *   @0x31929c bne 0x319278 <__aeabi_fadd+0xa8>
 *   @0x3192a0 clz r12, r0
 *   @0x3192a4 sub r12, r12, #8
 *   @0x3192a8 subs r2, r2, r12
 *   @0x3192ac lsl r0, r0, r12
 *   @0x3192b0 addge r0, r0, r2, lsl #23
 *   @0x3192b4 rsblt r2, r2, #0
 *   @0x3192b8 orrge r0, r0, r3
 *   @0x3192bc orrlt r0, r3, r0, lsr r2
 *   @0x3192c0 bx lr
 *   @0x3192c4 teq r2, #0
 *   @0x3192c8 eor r1, r1, #8388608
 *   @0x3192cc eoreq r0, r0, #8388608
 *   @0x3192d0 addeq r2, r2, #1
 *   @0x3192d4 subne r3, r3, #1
 *   @0x3192d8 b 0x319234 <__aeabi_fadd+0x64>
 *   @0x3192dc lsl r3, r1, #1
 *   @0x3192e0 mvns r12, r2, asr #24
 *   @0x3192e4 mvnsne r12, r3, asr #24
 *   @0x3192e8 beq 0x31933c <__aeabi_fadd+0x16c>
 *   @0x3192ec teq r2, r3
 *   @0x3192f0 beq 0x319300 <__aeabi_fadd+0x130>
 *   @0x3192f4 teq r2, #0
 *   @0x3192f8 moveq r0, r1
 *   @0x3192fc bx lr
 *   @0x319300 teq r0, r1
 *   @0x319304 movne r0, #0
 *   @0x319308 bxne lr
 *   @0x31930c tst r2, #-16777216
 *   @0x319310 bne 0x319320 <__aeabi_fadd+0x150>
 *   @0x319314 lsls r0, r0, #1
 *   @0x319318 orrhs r0, r0, #-2147483648
 *   @0x31931c bx lr
 *   @0x319320 adds r2, r2, #33554432
 *   @0x319324 addlo r0, r0, #8388608
 *   @0x319328 bxlo lr
 *   @0x31932c and r3, r0, #-2147483648
 *   @0x319330 orr r0, r3, #2130706432
 *   @0x319334 orr r0, r0, #8388608
 *   @0x319338 bx lr
 *   @0x31933c mvns r2, r2, asr #24
 *   @0x319340 movne r0, r1
 *   @0x319344 mvnseq r3, r3, asr #24
 *   @0x319348 movne r1, r0
 *   @0x31934c lsls r2, r0, #9
 *   @0x319350 lslseq r3, r1, #9
 *   @0x319354 teqeq r0, r1
 *   @0x319358 orrne r0, r0, #4194304
 *   @0x31935c bx lr
 *
 * ══ §18/76 Buffer_Network::Peek(int, eBuffer_Type, RValue*)  0xcb598  size 408  102 条（0xcb598..0xcb730）
 * @func 0xcb598 0xcb730  size 408  102 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Buffer_Network::Peek(int, eBuffer_Type, RValue*)+0x38 / Buffer_Network::Peek(int, eBuffer_Type, RValue*)+0x40 / IBuffer::SizeOf(eBuffer_Type) / __floatundidf
 * 字段偏移 top8: 0xc×9 / 0x4×5 / 0x10×2 / 0x18×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcb598 push {r4, r5, r6, r7, lr}
 *   @0xcb59c subs r6, r1, #0
 *   @0xcb5a0 mov r4, r3
 *   @0xcb5a4 sub sp, sp, #12
 *   @0xcb5a8 mov r3, #0
 *   @0xcb5ac mov r5, r0
 *   @0xcb5b0 mov r7, r2
 *   @0xcb5b4 str r3, [r4, #0xc]
 *   @0xcb5b8 str r3, [r4]
 *   @0xcb5bc str r3, [r4, #0x4]
 *   @0xcb5c0 blt 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38>
 *   @0xcb5c4 ldr r3, [r0, #0x10]
 *   @0xcb5c8 cmp r6, r3
 *   @0xcb5cc blt 0xcb5d8 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x40>
 *   @0xcb5d0 add sp, sp, #12
 *   @0xcb5d4 pop {r4, r5, r6, r7, pc}
 *   @0xcb5d8 mov r0, r2
 *   @0xcb5dc bl 0xcd100 <_ZN7IBuffer6SizeOfE12eBuffer_Type>
 *   @0xcb5e0 ldr r3, [r5, #0x18]
 *   @0xcb5e4 cmp r3, #2
 *   @0xcb5e8 beq 0xcb5fc <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x64>
 *   @0xcb5ec ldr r3, [r5, #0x10]
 *   @0xcb5f0 rsb r0, r0, r3
 *   @0xcb5f4 cmp r6, r0
 *   @0xcb5f8 bgt 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38>
 *   @0xcb5fc sub r7, r7, #1
 *   @0xcb600 cmp r7, #11
 *   @0xcb604 addls pc, pc, r7, lsl #2
 *   @0xcb608 b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38>
 *   @0xcb60c b 0xcb63c <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xa4>
 *   @0xcb610 b 0xcb63c <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xa4>
 *   @0xcb614 b 0xcb658 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xc0>
 *   @0xcb618 b 0xcb66c <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xd4>
 *   @0xcb61c b 0xcb690 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xf8>
 *   @0xcb620 b 0xcb6a0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x108>
 *   @0xcb624 b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38>
 *   @0xcb628 b 0xcb6b4 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x11c>
 *   @0xcb62c b 0xcb6d8 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x140>
 *   @0xcb630 b 0xcb63c <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xa4>
 *   @0xcb634 b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38>
 *   @0xcb638 b 0xcb700 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x168>
 *   @0xcb63c ldr r3, [r5, #0xc]
 *   @0xcb640 ldrb r2, [r3, r6]
 *   @0xcb644 vmov s15, r2
 *   @0xcb648 vcvt.f64.u32 d7, s15
 *   @0xcb64c vmov r2, r3, d7
 *   @0xcb650 stm r4, {r2, r3}
 *   @0xcb654 b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38>
 *   @0xcb658 ldr r3, [r5, #0xc]
 *   @0xcb65c ldrh r2, [r3, r6]
 *   @0xcb660 rev16 r2, r2
 *   @0xcb664 uxth r2, r2
 *   @0xcb668 b 0xcb644 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xac>
 *   @0xcb66c ldr r3, [r5, #0xc]
 *   @0xcb670 ldrh r2, [r3, r6]
 *   @0xcb674 rev16 r2, r2
 *   @0xcb678 sxth r2, r2
 *   @0xcb67c vmov s15, r2
 *   @0xcb680 vcvt.f64.s32 d7, s15
 *   @0xcb684 vmov r2, r3, d7
 *   @0xcb688 stm r4, {r2, r3}
 *   @0xcb68c b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38>
 *   @0xcb690 ldr r3, [r5, #0xc]
 *   @0xcb694 ldr r2, [r3, r6]
 *   @0xcb698 rev r2, r2
 *   @0xcb69c b 0xcb644 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xac>
 *   @0xcb6a0 ldr r3, [r5, #0xc]
 *   @0xcb6a4 ldrh r2, [r3, r6]
 *   @0xcb6a8 rev16 r2, r2
 *   @0xcb6ac uxth r2, r2
 *   @0xcb6b0 b 0xcb67c <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0xe4>
 *   @0xcb6b4 ldr r3, [r5, #0xc]
 *   @0xcb6b8 ldrh r2, [r3, r6]
 *   @0xcb6bc rev16 r2, r2
 *   @0xcb6c0 uxth r2, r2
 *   @0xcb6c4 vmov s15, r2
 *   @0xcb6c8 vcvt.f64.f32 d7, s15
 *   @0xcb6cc vmov r2, r3, d7
 *   @0xcb6d0 stm r4, {r2, r3}
 *   @0xcb6d4 b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38>
 *   @0xcb6d8 ldr r3, [r5, #0xc]
 *   @0xcb6dc add r2, r3, r6
 *   @0xcb6e0 ldr r3, [r3, r6]
 *   @0xcb6e4 rev r3, r3
 *   @0xcb6e8 str r3, [sp]
 *   @0xcb6ec ldr r2, [r2, #0x4]
 *   @0xcb6f0 rev r2, r2
 *   @0xcb6f4 str r3, [r4]
 *   @0xcb6f8 str r2, [r4, #0x4]
 *   @0xcb6fc b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38>
 *   @0xcb700 ldr r3, [r5, #0xc]
 *   @0xcb704 add r2, r3, r6
 *   @0xcb708 ldr r3, [r3, r6]
 *   @0xcb70c rev r3, r3
 *   @0xcb710 str r3, [sp]
 *   @0xcb714 ldr r3, [r2, #0x4]
 *   @0xcb718 rev r3, r3
 *   @0xcb71c str r3, [sp, #0x4]
 *   @0xcb720 ldrd r0, r1, [sp]
 *   @0xcb724 bl 0x319150 <__floatundidf>
 *   @0xcb728 stm r4, {r0, r1}
 *   @0xcb72c b 0xcb5d0 <_ZN14Buffer_Network4PeekEi12eBuffer_TypeP6RValue+0x38>
 *
 * ══ §19/76 VM::WriteRValueToBuffer(RValue*, Buffer_Standard*)  0xd8a88  size 408  102 条（0xd8a88..0xd8c20）
 * @func 0xd8a88 0xd8c20  size 408  102 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×5 / 0x30×5 / 0x8×5 / 0x2c×3 / 0xc×2 / 0x4×2
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd8a88 push {r4, r5, r6, r7, r8, lr}
 *   @0xd8a8c add r8, r1, #44
 *   @0xd8a90 ldr r4, [r0, #0xc]
 *   @0xd8a94 mov r6, r1
 *   @0xd8a98 ldr r3, [r1]
 *   @0xd8a9c mov r7, r0
 *   @0xd8aa0 mov r1, #0
 *   @0xd8aa4 mov r2, r8
 *   @0xd8aa8 vmov s15, r4
 *   @0xd8aac str r1, [r6, #0x38]
 *   @0xd8ab0 mov r0, r6
 *   @0xd8ab4 mov r1, #5
 *   @0xd8ab8 vcvt.f64.u32 d7, s15
 *   @0xd8abc vmov r4, r5, d7
 *   @0xd8ac0 vstr s14, [r6, #44]
 *   @0xd8ac4 str r5, [r6, #0x30]
 *   @0xd8ac8 ldr r3, [r3, #0x8]
 *   @0xd8acc blx r3
 *   @0xd8ad0 ldr r2, [r7, #0xc]
 *   @0xd8ad4 bic r3, r2, #-268435456
 *   @0xd8ad8 cmp r3, #13
 *   @0xd8adc addls pc, pc, r3, lsl #2
 *   @0xd8ae0 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4>
 *   @0xd8ae4 b 0xd8bc4 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0x13c>
 *   @0xd8ae8 b 0xd8bf8 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0x170>
 *   @0xd8aec b 0xd8b50 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc8>
 *   @0xd8af0 b 0xd8b50 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc8>
 *   @0xd8af4 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4>
 *   @0xd8af8 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4>
 *   @0xd8afc b 0xd8b50 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc8>
 *   @0xd8b00 b 0xd8b88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0x100>
 *   @0xd8b04 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4>
 *   @0xd8b08 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4>
 *   @0xd8b0c b 0xd8b1c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0x94>
 *   @0xd8b10 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4>
 *   @0xd8b14 b 0xd8b4c <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0xc4>
 *   @0xd8b18 b 0xd8bc4 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0x13c>
 *   @0xd8b1c ldr r1, [r7]
 *   @0xd8b20 mov r12, #10
 *   @0xd8b24 ldr lr, [r7, #0x4]
 *   @0xd8b28 mov r2, r8
 *   @0xd8b2c ldr r3, [r6]
 *   @0xd8b30 mov r0, r6
 *   @0xd8b34 str r1, [r6, #0x2c]
 *   @0xd8b38 mov r1, #12
 *   @0xd8b3c str lr, [r6, #0x30]
 *   @0xd8b40 str r12, [r6, #0x38]
 *   @0xd8b44 ldr r3, [r3, #0x8]
 *   @0xd8b48 blx r3
 *   @0xd8b4c pop {r4, r5, r6, r7, r8, pc}
 *   @0xd8b50 ldr r3, [r7]
 *   @0xd8b54 mov r1, #10
 *   @0xd8b58 ldr r12, [r6]
 *   @0xd8b5c mov r2, r8
 *   @0xd8b60 str r1, [r6, #0x38]
 *   @0xd8b64 mov r0, r6
 *   @0xd8b68 asr r5, r3, #31
 *   @0xd8b6c mov r4, r3
 *   @0xd8b70 str r3, [r6, #0x2c]
 *   @0xd8b74 mov r1, #12
 *   @0xd8b78 str r5, [r6, #0x30]
 *   @0xd8b7c ldr r3, [r12, #0x8]
 *   @0xd8b80 blx r3
 *   @0xd8b84 pop {r4, r5, r6, r7, r8, pc}
 *   @0xd8b88 ldr r4, [r7]
 *   @0xd8b8c mov r1, #0
 *   @0xd8b90 ldr r3, [r6]
 *   @0xd8b94 mov r2, r8
 *   @0xd8b98 str r1, [r6, #0x38]
 *   @0xd8b9c mov r0, r6
 *   @0xd8ba0 vmov s15, r4
 *   @0xd8ba4 mov r1, #6
 *   @0xd8ba8 vcvt.f64.s32 d7, s15
 *   @0xd8bac vmov r4, r5, d7
 *   @0xd8bb0 vstr s14, [r6, #44]
 *   @0xd8bb4 str r5, [r6, #0x30]
 *   @0xd8bb8 ldr r3, [r3, #0x8]
 *   @0xd8bbc blx r3
 *   @0xd8bc0 pop {r4, r5, r6, r7, r8, pc}
 *   @0xd8bc4 ldr r1, [r7]
 *   @0xd8bc8 mov r12, #0
 *   @0xd8bcc ldr lr, [r7, #0x4]
 *   @0xd8bd0 mov r2, r8
 *   @0xd8bd4 ldr r3, [r6]
 *   @0xd8bd8 mov r0, r6
 *   @0xd8bdc str r1, [r6, #0x2c]
 *   @0xd8be0 mov r1, #9
 *   @0xd8be4 str lr, [r6, #0x30]
 *   @0xd8be8 str r12, [r6, #0x38]
 *   @0xd8bec ldr r3, [r3, #0x8]
 *   @0xd8bf0 blx r3
 *   @0xd8bf4 pop {r4, r5, r6, r7, r8, pc}
 *   @0xd8bf8 bic r2, r2, #-16777216
 *   @0xd8bfc cmp r2, #1
 *   @0xd8c00 movne r1, #0
 *   @0xd8c04 bne 0xd8c14 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard+0x18c>
 *   @0xd8c08 ldr r1, [r7]
 *   @0xd8c0c cmp r1, #0
 *   @0xd8c10 ldrne r1, [r1]
 *   @0xd8c14 mov r0, r6
 *   @0xd8c18 pop {r4, r5, r6, r7, r8, lr}
 *   @0xd8c1c b 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *
 * ══ §20/76 CGCGeneration::AddClassStat(char const*)  0x191578  size 408  102 条（0x191578..0x191710）
 * @func 0x191578 0x191710  size 408  102 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574 / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65a4 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4c×5 / 0x4×5 / 0x48×4 / 0x3×3 / 0x50×1 / 0x108×1 / 0xa0×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191578 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x19157c subs r7, r1, #0
 *   @0x191580 sub sp, sp, #12
 *   @0x191584 mov r9, r0
 *   @0x191588 ldr r6, [r0, #0x4c]
 *   @0x19158c ldr r5, [r0, #0x48]
 *   @0x191590 beq 0x1916b4 <_ZN13CGCGeneration12AddClassStatEPKc+0x13c>
 *   @0x191594 cmp r6, #0
 *   @0x191598 movne r3, #0
 *   @0x19159c movne r4, r3
 *   @0x1915a0 beq 0x1915d4 <_ZN13CGCGeneration12AddClassStatEPKc+0x5c>
 *   @0x1915a4 ldr r0, [r5, r3, lsl #3]
 *   @0x1915a8 mov r1, r7
 *   @0x1915ac add r4, r4, #1
 *   @0x1915b0 add r8, r5, r3, lsl #3
 *   @0x1915b4 cmp r0, #0
 *   @0x1915b8 beq 0x1915c8 <_ZN13CGCGeneration12AddClassStatEPKc+0x50>
 *   @0x1915bc bl 0xb6574 <strcmp@plt>
 *   @0x1915c0 cmp r0, #0
 *   @0x1915c4 beq 0x19164c <_ZN13CGCGeneration12AddClassStatEPKc+0xd4>
 *   @0x1915c8 cmp r4, r6
 *   @0x1915cc mov r3, r4
 *   @0x1915d0 bne 0x1915a4 <_ZN13CGCGeneration12AddClassStatEPKc+0x2c>
 *   @0x1915d4 ldr r3, [r9, #0x50]
 *   @0x1915d8 cmp r3, r6
 *   @0x1915dc beq 0x191660 <_ZN13CGCGeneration12AddClassStatEPKc+0xe8>
 *   @0x1915e0 cmp r7, #0
 *   @0x1915e4 streq r7, [r5, r6, lsl #3]
 *   @0x1915e8 addeq r5, r5, r6, lsl #3
 *   @0x1915ec beq 0x191634 <_ZN13CGCGeneration12AddClassStatEPKc+0xbc>
 *   @0x1915f0 mov r0, r7
 *   @0x1915f4 bl 0xb6538 <strlen@plt>
 *   @0x1915f8 ldr r1, [pc, #0x108]
 *   @0x1915fc mov r3, #1
 *   @0x191600 mov r2, #70
 *   @0x191604 add r1, pc, r1
 *   @0x191608 add r0, r0, r3
 *   @0x19160c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x191610 ldr r2, [r9, #0x4c]
 *   @0x191614 ldr r3, [r9, #0x48]
 *   @0x191618 mov r1, r7
 *   @0x19161c str r0, [r5, r6, lsl #3]
 *   @0x191620 ldr r0, [r3, r2, lsl #3]
 *   @0x191624 bl 0xb65a4 <strcpy@plt>
 *   @0x191628 ldr r6, [r9, #0x4c]
 *   @0x19162c ldr r5, [r9, #0x48]
 *   @0x191630 add r5, r5, r6, lsl #3
 *   @0x191634 add r6, r6, #1
 *   @0x191638 mov r3, #1
 *   @0x19163c str r3, [r5, #0x4]
 *   @0x191640 str r6, [r9, #0x4c]
 *   @0x191644 add sp, sp, #12
 *   @0x191648 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x19164c ldr r3, [r8, #0x4]
 *   @0x191650 add r3, r3, #1
 *   @0x191654 str r3, [r8, #0x4]
 *   @0x191658 add sp, sp, #12
 *   @0x19165c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x191660 lsls r3, r6, #1
 *   @0x191664 ldr r2, [pc, #0xa0]
 *   @0x191668 strne r3, [r9, #0x50]
 *   @0x19166c lslne r1, r6, #4
 *   @0x191670 moveq r3, #1
 *   @0x191674 moveq r1, #8
 *   @0x191678 streq r3, [r9, #0x50]
 *   @0x19167c mov r0, r5
 *   @0x191680 mov r3, #0
 *   @0x191684 add r2, pc, r2
 *   @0x191688 str r3, [sp]
 *   @0x19168c mov r3, #74
 *   @0x191690 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x191694 ldr r6, [r9, #0x4c]
 *   @0x191698 cmp r7, #0
 *   @0x19169c mov r5, r0
 *   @0x1916a0 str r0, [r9, #0x48]
 *   @0x1916a4 streq r7, [r5, r6, lsl #3]
 *   @0x1916a8 addeq r5, r5, r6, lsl #3
 *   @0x1916ac bne 0x1915f0 <_ZN13CGCGeneration12AddClassStatEPKc+0x78>
 *   @0x1916b0 b 0x191634 <_ZN13CGCGeneration12AddClassStatEPKc+0xbc>
 *   @0x1916b4 cmp r6, #0
 *   @0x1916b8 beq 0x1915d4 <_ZN13CGCGeneration12AddClassStatEPKc+0x5c>
 *   @0x1916bc ldr r3, [r5]
 *   @0x1916c0 cmp r3, #0
 *   @0x1916c4 addne r2, r5, #8
 *   @0x1916c8 movne r3, r7
 *   @0x1916cc bne 0x1916e0 <_ZN13CGCGeneration12AddClassStatEPKc+0x168>
 *   @0x1916d0 b 0x1916f4 <_ZN13CGCGeneration12AddClassStatEPKc+0x17c>
 *   @0x1916d4 ldr r1, [r2], #8
 *   @0x1916d8 cmp r1, #0
 *   @0x1916dc beq 0x1916f8 <_ZN13CGCGeneration12AddClassStatEPKc+0x180>
 *   @0x1916e0 add r3, r3, #1
 *   @0x1916e4 mov r0, r2
 *   @0x1916e8 cmp r3, r6
 *   @0x1916ec bne 0x1916d4 <_ZN13CGCGeneration12AddClassStatEPKc+0x15c>
 *   @0x1916f0 b 0x1915d4 <_ZN13CGCGeneration12AddClassStatEPKc+0x5c>
 *   @0x1916f4 mov r0, r5
 *   @0x1916f8 ldr r3, [r0, #0x4]
 *   @0x1916fc add r3, r3, #1
 *   @0x191700 str r3, [r0, #0x4]
 *   @0x191704 b 0x191644 <_ZN13CGCGeneration12AddClassStatEPKc+0xcc>
 *   @0x191708 andseq pc, r9, r12, lsr #20
 *   @0x19170c andseq pc, r9, r12, lsr #19
 *
 * ══ §21/76 InitVertexFormats()  0x1e2fe8  size 408  102 条（0x1e2fe8..0x1e3180）
 * @func 0x1e2fe8 0x1e3180  size 408  102 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Function_Add(char const*, void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×10
 * 字段偏移 top8: 0x120×2 / 0x10c×2 / 0xf8×2 / 0xe4×2 / 0xd0×2 / 0xa4×2 / 0x90×2 / 0x64×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2fe8 push {r4, r5, r6, lr}
 *   @0x1e2fec mov r2, #0
 *   @0x1e2ff0 ldr r4, [pc, #0x134]
 *   @0x1e2ff4 mov r3, r2
 *   @0x1e2ff8 ldr r1, [pc, #0x130]
 *   @0x1e2ffc add r4, pc, r4
 *   @0x1e3000 ldr r0, [pc, #0x12c]
 *   @0x1e3004 ldr r1, [r4, r1]
 *   @0x1e3008 add r0, pc, r0
 *   @0x1e300c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1e3010 ldr r1, [pc, #0x120]
 *   @0x1e3014 ldr r0, [pc, #0x120]
 *   @0x1e3018 mov r2, #1
 *   @0x1e301c mov r3, #0
 *   @0x1e3020 ldr r1, [r4, r1]
 *   @0x1e3024 add r0, pc, r0
 *   @0x1e3028 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1e302c ldr r1, [pc, #0x10c]
 *   @0x1e3030 ldr r0, [pc, #0x10c]
 *   @0x1e3034 mov r2, #0
 *   @0x1e3038 mov r3, r2
 *   @0x1e303c ldr r1, [r4, r1]
 *   @0x1e3040 add r0, pc, r0
 *   @0x1e3044 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1e3048 ldr r1, [pc, #0xf8]
 *   @0x1e304c ldr r0, [pc, #0xf8]
 *   @0x1e3050 mov r2, #0
 *   @0x1e3054 mov r3, r2
 *   @0x1e3058 ldr r1, [r4, r1]
 *   @0x1e305c add r0, pc, r0
 *   @0x1e3060 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1e3064 ldr r1, [pc, #0xe4]
 *   @0x1e3068 ldr r0, [pc, #0xe4]
 *   @0x1e306c mov r2, #0
 *   @0x1e3070 mov r3, r2
 *   @0x1e3074 ldr r1, [r4, r1]
 *   @0x1e3078 add r0, pc, r0
 *   @0x1e307c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1e3080 ldr r1, [pc, #0xd0]
 *   @0x1e3084 ldr r0, [pc, #0xd0]
 *   @0x1e3088 mov r2, #0
 *   @0x1e308c mov r3, r2
 *   @0x1e3090 ldr r5, [r4, r1]
 *   @0x1e3094 add r0, pc, r0
 *   @0x1e3098 mov r1, r5
 *   @0x1e309c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1e30a0 ldr r0, [pc, #0xb8]
 *   @0x1e30a4 mov r2, #0
 *   @0x1e30a8 mov r1, r5
 *   @0x1e30ac mov r3, r2
 *   @0x1e30b0 add r0, pc, r0
 *   @0x1e30b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1e30b8 ldr r1, [pc, #0xa4]
 *   @0x1e30bc ldr r0, [pc, #0xa4]
 *   @0x1e30c0 mov r2, #0
 *   @0x1e30c4 mov r3, r2
 *   @0x1e30c8 ldr r1, [r4, r1]
 *   @0x1e30cc add r0, pc, r0
 *   @0x1e30d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1e30d4 ldr r1, [pc, #0x90]
 *   @0x1e30d8 ldr r0, [pc, #0x90]
 *   @0x1e30dc mov r2, #0
 *   @0x1e30e0 mov r3, r2
 *   @0x1e30e4 ldr r5, [r4, r1]
 *   @0x1e30e8 add r0, pc, r0
 *   @0x1e30ec mov r1, r5
 *   @0x1e30f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1e30f4 ldr r0, [pc, #0x78]
 *   @0x1e30f8 mov r2, #0
 *   @0x1e30fc mov r1, r5
 *   @0x1e3100 mov r3, r2
 *   @0x1e3104 add r0, pc, r0
 *   @0x1e3108 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1e310c ldr r1, [pc, #0x64]
 *   @0x1e3110 ldr r0, [pc, #0x64]
 *   @0x1e3114 mov r2, #2
 *   @0x1e3118 mov r3, #0
 *   @0x1e311c ldr r1, [r4, r1]
 *   @0x1e3120 add r0, pc, r0
 *   @0x1e3124 pop {r4, r5, r6, lr}
 *   @0x1e3128 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1e312c eoreq lr, r0, r4, asr r12
 *   @0x1e3130 .word 0xfffff154
 *   @0x1e3134 ldrsheq pc, [r6], -r12
 *   @0x1e3138 .word 0xfffff158
 *   @0x1e313c ldrsheq pc, [r6], -r4
 *   @0x1e3140 .word 0xfffff15c
 *   @0x1e3144 ldrsheq pc, [r6], -r0
 *   @0x1e3148 .word 0xfffff160
 *   @0x1e314c andseq pc, r6, r8, ror #5
 *   @0x1e3150 .word 0xfffff164
 *   @0x1e3154 andseq pc, r6, r8, ror #5
 *   @0x1e3158 .word 0xfffff168
 *   @0x1e315c andseq pc, r6, r12, ror #5
 *   @0x1e3160 andseq pc, r6, r12, ror #5
 *   @0x1e3164 .word 0xfffff16c
 *   @0x1e3168 andseq pc, r6, r8, ror #5
 *   @0x1e316c .word 0xfffff170
 *   @0x1e3170 andseq pc, r6, r8, ror #5
 *   @0x1e3174 andseq pc, r6, r8, ror #5
 *   @0x1e3178 .word 0xfffff174
 *   @0x1e317c andseq pc, r6, r8, ror #5
 *
 * ══ §22/76 TimeLine_Quit()  0x1f241c  size 408  102 条（0x1f241c..0x1f25b4）
 * @func 0x1f241c 0x1f25b4  size 408  102 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×5 / operator delete(void*)×2 / TimeLine_Quit()+0xa4 / TimeLine_Quit()+0x3c / TimeLine_Quit()+0x134 / MemoryManager::IsAllocated(void const*) / TimeLine_Quit()+0xf8
 * 字段偏移 top8: 0x4×14 / 0x2×3 / 0x184×1 / 0xc4×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f241c ldr r3, [pc, #0x184]
 *   @0x1f2420 push {r4, r5, r6, r7, r8, lr}
 *   @0x1f2424 ldr r6, [pc, r3]
 *   @0x1f2428 cmp r6, #0
 *   @0x1f242c beq 0x1f24e0 <_Z13TimeLine_Quitv+0xc4>
 *   @0x1f2430 ldr r12, [r6]
 *   @0x1f2434 cmp r12, #0
 *   @0x1f2438 beq 0x1f24d8 <_Z13TimeLine_Quitv+0xbc>
 *   @0x1f243c ldr r5, [r6, #0x4]
 *   @0x1f2440 cmp r5, #0
 *   @0x1f2444 beq 0x1f2598 <_Z13TimeLine_Quitv+0x17c>
 *   @0x1f2448 cmp r12, #0
 *   @0x1f244c ble 0x1f24c0 <_Z13TimeLine_Quitv+0xa4>
 *   @0x1f2450 mov r4, #0
 *   @0x1f2454 mov r8, r4
 *   @0x1f2458 ldr r1, [r5]
 *   @0x1f245c movw r3, #0xfeee
 *   @0x1f2460 movt r3, #0xfeee
 *   @0x1f2464 movw r2, #0xfeee
 *   @0x1f2468 cmp r1, r3
 *   @0x1f246c movt r2, #0xfeee
 *   @0x1f2470 lsl r7, r4, #2
 *   @0x1f2474 beq 0x1f24b4 <_Z13TimeLine_Quitv+0x98>
 *   @0x1f2478 ldr r3, [r5, r4, lsl #2]
 *   @0x1f247c add r1, r5, r7
 *   @0x1f2480 cmp r3, #0
 *   @0x1f2484 mov r0, r3
 *   @0x1f2488 beq 0x1f24b4 <_Z13TimeLine_Quitv+0x98>
 *   @0x1f248c ldr r3, [r3]
 *   @0x1f2490 cmp r3, r2
 *   @0x1f2494 beq 0x1f24ac <_Z13TimeLine_Quitv+0x90>
 *   @0x1f2498 ldr r3, [r3, #0x4]
 *   @0x1f249c blx r3
 *   @0x1f24a0 ldr r1, [r6, #0x4]
 *   @0x1f24a4 ldr r12, [r6]
 *   @0x1f24a8 add r1, r1, r7
 *   @0x1f24ac str r8, [r1]
 *   @0x1f24b0 ldr r5, [r6, #0x4]
 *   @0x1f24b4 add r4, r4, #1
 *   @0x1f24b8 cmp r4, r12
 *   @0x1f24bc blt 0x1f2458 <_Z13TimeLine_Quitv+0x3c>
 *   @0x1f24c0 mov r0, r5
 *   @0x1f24c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f24c8 mov r3, #0
 *   @0x1f24cc str r3, [r6, #0x4]
 *   @0x1f24d0 mov r3, #0
 *   @0x1f24d4 str r3, [r6]
 *   @0x1f24d8 mov r0, r6
 *   @0x1f24dc bl 0x27d1d0 <_ZdlPv>
 *   @0x1f24e0 ldr r3, [pc, #0xc4]
 *   @0x1f24e4 add r3, pc, r3
 *   @0x1f24e8 ldr r5, [r3, #0x4]
 *   @0x1f24ec cmp r5, #0
 *   @0x1f24f0 beq 0x1f2570 <_Z13TimeLine_Quitv+0x154>
 *   @0x1f24f4 ldr r6, [r5, #0x4]
 *   @0x1f24f8 cmp r6, #0
 *   @0x1f24fc beq 0x1f2588 <_Z13TimeLine_Quitv+0x16c>
 *   @0x1f2500 ldr r3, [r5]
 *   @0x1f2504 cmp r3, #0
 *   @0x1f2508 ble 0x1f2550 <_Z13TimeLine_Quitv+0x134>
 *   @0x1f250c mov r4, #0
 *   @0x1f2510 mov r7, r4
 *   @0x1f2514 ldr r0, [r6, r4, lsl #2]
 *   @0x1f2518 lsl r6, r4, #2
 *   @0x1f251c bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv>
 *   @0x1f2520 cmp r0, #0
 *   @0x1f2524 beq 0x1f2534 <_Z13TimeLine_Quitv+0x118>
 *   @0x1f2528 ldr r3, [r5, #0x4]
 *   @0x1f252c ldr r0, [r3, r4, lsl #2]
 *   @0x1f2530 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f2534 ldr r2, [r5]
 *   @0x1f2538 add r4, r4, #1
 *   @0x1f253c ldr r3, [r5, #0x4]
 *   @0x1f2540 cmp r4, r2
 *   @0x1f2544 str r7, [r3, r6]
 *   @0x1f2548 ldr r6, [r5, #0x4]
 *   @0x1f254c blt 0x1f2514 <_Z13TimeLine_Quitv+0xf8>
 *   @0x1f2550 mov r0, r6
 *   @0x1f2554 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f2558 mov r3, #0
 *   @0x1f255c str r3, [r5, #0x4]
 *   @0x1f2560 mov r3, #0
 *   @0x1f2564 mov r0, r5
 *   @0x1f2568 str r3, [r5]
 *   @0x1f256c bl 0x27d1d0 <_ZdlPv>
 *   @0x1f2570 ldr r3, [pc, #0x38]
 *   @0x1f2574 mov r2, #0
 *   @0x1f2578 add r3, pc, r3
 *   @0x1f257c str r2, [r3]
 *   @0x1f2580 str r2, [r3, #0x4]
 *   @0x1f2584 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f2588 mov r0, r6
 *   @0x1f258c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f2590 str r6, [r5, #0x4]
 *   @0x1f2594 b 0x1f2560 <_Z13TimeLine_Quitv+0x144>
 *   @0x1f2598 mov r0, r5
 *   @0x1f259c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f25a0 str r5, [r6, #0x4]
 *   @0x1f25a4 b 0x1f24d0 <_Z13TimeLine_Quitv+0xb4>
 *   @0x1f25a8 subseq r0, r6, r8, asr #25
 *   @0x1f25ac subseq r0, r6, r8, lsl #24
 *   @0x1f25b0 subseq r0, r6, r4, ror r11
 *
 * ══ §23/76 COggAudio::Create_SyncThread(bool)  0x225d94  size 408  102 条（0x225d94..0x225f2c）
 * @func 0x225d94 0x225f2c  size 408  102 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / operator new(unsigned int) / COggSyncThread::COggSyncThread() / COggAudio::Create_SyncThread(bool)+0xd4 / COggAudio::Create_SyncThread(bool)+0x94 / __divsi3 / COggSyncThread::Create(int, int, int, bool) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×5 / 0x10×5 / 0x4×3 / 0x853×1 / 0x84e×1 / 0x14×1 / 0x18×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x225d94 push {r4, r5, r6, r7, lr}
 *   @0x225d98 mov r5, r0
 *   @0x225d9c sub sp, sp, #12
 *   @0x225da0 movw r0, #0x878
 *   @0x225da4 mov r7, r1
 *   @0x225da8 bl 0x27c524 <_Znwj>
 *   @0x225dac mov r6, r0
 *   @0x225db0 bl 0x224834 <_ZN14COggSyncThreadC2Ev>
 *   @0x225db4 ldr r4, [r5, #0x8]
 *   @0x225db8 mov r3, #1
 *   @0x225dbc strb r7, [r6, #0x853]
 *   @0x225dc0 cmp r4, #0
 *   @0x225dc4 strb r3, [r6, #0x84e]
 *   @0x225dc8 ble 0x225e68 <_ZN9COggAudio17Create_SyncThreadEb+0xd4>
 *   @0x225dcc ldr r1, [r5, #0x4]
 *   @0x225dd0 cmp r1, #0
 *   @0x225dd4 ldrle r12, [r5, #0x10]
 *   @0x225dd8 movle r3, #0
 *   @0x225ddc ble 0x225e28 <_ZN9COggAudio17Create_SyncThreadEb+0x94>
 *   @0x225de0 ldr r0, [r5, #0x10]
 *   @0x225de4 ldr r3, [r0]
 *   @0x225de8 cmp r3, #0
 *   @0x225dec addne r2, r0, #4
 *   @0x225df0 movne r3, #0
 *   @0x225df4 bne 0x225e08 <_ZN9COggAudio17Create_SyncThreadEb+0x74>
 *   @0x225df8 b 0x225f20 <_ZN9COggAudio17Create_SyncThreadEb+0x18c>
 *   @0x225dfc ldr lr, [r12]
 *   @0x225e00 cmp lr, #0
 *   @0x225e04 beq 0x225e28 <_ZN9COggAudio17Create_SyncThreadEb+0x94>
 *   @0x225e08 add r3, r3, #1
 *   @0x225e0c mov r12, r2
 *   @0x225e10 cmp r3, r4
 *   @0x225e14 add r2, r2, #4
 *   @0x225e18 beq 0x225e70 <_ZN9COggAudio17Create_SyncThreadEb+0xdc>
 *   @0x225e1c cmp r3, r1
 *   @0x225e20 bne 0x225dfc <_ZN9COggAudio17Create_SyncThreadEb+0x68>
 *   @0x225e24 add r12, r0, r3, lsl #2
 *   @0x225e28 mov r4, r3
 *   @0x225e2c str r6, [r12]
 *   @0x225e30 ldr r7, [r5, #0x14]
 *   @0x225e34 ldr r0, [r5, #0x18]
 *   @0x225e38 mov r1, r7
 *   @0x225e3c bl 0x318d10 <__divsi3>
 *   @0x225e40 mov r12, #1
 *   @0x225e44 mov r2, r7
 *   @0x225e48 mov r1, r4
 *   @0x225e4c str r12, [sp]
 *   @0x225e50 mov r3, r0
 *   @0x225e54 mov r0, r6
 *   @0x225e58 bl 0x224a4c <_ZN14COggSyncThread6CreateEiiib>
 *   @0x225e5c mov r0, r4
 *   @0x225e60 add sp, sp, #12
 *   @0x225e64 pop {r4, r5, r6, r7, pc}
 *   @0x225e68 ldr r0, [r5, #0x10]
 *   @0x225e6c ldr r1, [r5, #0x4]
 *   @0x225e70 cmp r1, r4
 *   @0x225e74 beq 0x225e8c <_ZN9COggAudio17Create_SyncThreadEb+0xf8>
 *   @0x225e78 add r0, r0, r4, lsl #2
 *   @0x225e7c add r3, r4, #1
 *   @0x225e80 str r6, [r0]
 *   @0x225e84 str r3, [r5, #0x8]
 *   @0x225e88 b 0x225e30 <_ZN9COggAudio17Create_SyncThreadEb+0x9c>
 *   @0x225e8c ldr r7, [r5, #0xc]
 *   @0x225e90 add r7, r4, r7
 *   @0x225e94 cmp r7, r4
 *   @0x225e98 beq 0x225e78 <_ZN9COggAudio17Create_SyncThreadEb+0xe4>
 *   @0x225e9c cmp r7, #0
 *   @0x225ea0 bne 0x225ecc <_ZN9COggAudio17Create_SyncThreadEb+0x138>
 *   @0x225ea4 cmp r0, #0
 *   @0x225ea8 beq 0x225f00 <_ZN9COggAudio17Create_SyncThreadEb+0x16c>
 *   @0x225eac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x225eb0 mov r4, r7
 *   @0x225eb4 mov r0, r7
 *   @0x225eb8 mov r3, #1
 *   @0x225ebc str r7, [r5, #0x10]
 *   @0x225ec0 str r7, [r5, #0x8]
 *   @0x225ec4 str r7, [r5, #0x4]
 *   @0x225ec8 b 0x225e80 <_ZN9COggAudio17Create_SyncThreadEb+0xec>
 *   @0x225ecc lsls r1, r7, #2
 *   @0x225ed0 beq 0x225f00 <_ZN9COggAudio17Create_SyncThreadEb+0x16c>
 *   @0x225ed4 ldr r2, [pc, #0x4c]
 *   @0x225ed8 mov r3, #0
 *   @0x225edc str r3, [sp]
 *   @0x225ee0 movw r3, #0x11b
 *   @0x225ee4 add r2, pc, r2
 *   @0x225ee8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x225eec ldr r4, [r5, #0x8]
 *   @0x225ef0 add r3, r4, #1
 *   @0x225ef4 str r0, [r5, #0x10]
 *   @0x225ef8 add r0, r0, r4, lsl #2
 *   @0x225efc b 0x225ec4 <_ZN9COggAudio17Create_SyncThreadEb+0x130>
 *   @0x225f00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x225f04 mov r3, #0
 *   @0x225f08 mov r0, r3
 *   @0x225f0c str r3, [r5, #0x10]
 *   @0x225f10 str r3, [r5, #0x8]
 *   @0x225f14 mov r4, r3
 *   @0x225f18 mov r3, #1
 *   @0x225f1c b 0x225ec4 <_ZN9COggAudio17Create_SyncThreadEb+0x130>
 *   @0x225f20 mov r12, r0
 *   @0x225f24 b 0x225e28 <_ZN9COggAudio17Create_SyncThreadEb+0x94>
 *   @0x225f28 andseq r7, r2, r12, lsl #8
 *
 * ══ §24/76 F_NETWORK_Set_Config(RValue&, CInstance*, CInstance*, int, RValue*)  0x298358  size 408  102 条（0x298358..0x2984f0）
 * @func 0x298358 0x2984f0  size 408  102 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2983bc→0x75790c, 0x29840c→0x3f7810, 0x298428→0x7578e8, 0x29844c→0x75790c, 0x29848c→0x75790c
 * 调用序列: YYGetInt32(RValue const*, int)×5 / yySocket::AvoidTimeWait() / YYGetBool(RValue const*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0x16c×1 / 0xc×1 / 0x11c×1 / 0xd0×1 / 0xb8×1 / 0x8c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x298358 push {r4, r5, r6, lr}
 *   @0x29835c mov r3, #0
 *   @0x298360 ldr r5, [sp, #0x10]
 *   @0x298364 mov r4, r0
 *   @0x298368 ldr r6, [pc, #0x16c]
 *   @0x29836c mov r1, r3
 *   @0x298370 str r3, [r0, #0xc]
 *   @0x298374 str r3, [r0]
 *   @0x298378 add r6, pc, r6
 *   @0x29837c str r3, [r0, #0x4]
 *   @0x298380 mov r0, r5
 *   @0x298384 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298388 cmp r0, #4
 *   @0x29838c addls pc, pc, r0, lsl #2
 *   @0x298390 b 0x2984b8 <_Z20F_NETWORK_Set_ConfigR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x298394 b 0x298400 <_Z20F_NETWORK_Set_ConfigR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x298398 b 0x29841c <_Z20F_NETWORK_Set_ConfigR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x29839c b 0x298438 <_Z20F_NETWORK_Set_ConfigR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x2983a0 b 0x298478 <_Z20F_NETWORK_Set_ConfigR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x2983a4 b 0x2983a8 <_Z20F_NETWORK_Set_ConfigR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x2983a8 mov r0, r5
 *   @0x2983ac mov r1, #1
 *   @0x2983b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x2983b4 cmp r0, #63
 *   @0x2983b8 pophi {r4, r5, r6, pc}
 *   @0x2983bc ldr r3, [pc, #0x11c]
 *   @0x2983c0 add r0, r0, r0, lsl #1
 *   @0x2983c4 lsl r0, r0, #2
 *   @0x2983c8 ldr r3, [r6, r3]
 *   @0x2983cc ldrb r2, [r3, r0]
 *   @0x2983d0 cmp r2, #0
 *   @0x2983d4 popeq {r4, r5, r6, pc}
 *   @0x2983d8 add r3, r3, r0
 *   @0x2983dc ldr r0, [r3, #0x4]
 *   @0x2983e0 bl 0x294f30 <_ZN8yySocket13AvoidTimeWaitEv>
 *   @0x2983e4 vmov s15, r0
 *   @0x2983e8 vcvt.f64.s32 d7, s15
 *   @0x2983ec vmov r0, r1, d7
 *   @0x2983f0 vmov r2, s14
 *   @0x2983f4 mov r3, r1
 *   @0x2983f8 stm r4, {r2, r3}
 *   @0x2983fc pop {r4, r5, r6, pc}
 *   @0x298400 mov r0, r5
 *   @0x298404 mov r1, #1
 *   @0x298408 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29840c ldr r3, [pc, #0xd0]
 *   @0x298410 ldr r3, [r6, r3]
 *   @0x298414 str r0, [r3]
 *   @0x298418 pop {r4, r5, r6, pc}
 *   @0x29841c mov r0, r5
 *   @0x298420 mov r1, #1
 *   @0x298424 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x298428 ldr r3, [pc, #0xb8]
 *   @0x29842c ldr r3, [r6, r3]
 *   @0x298430 strb r0, [r3]
 *   @0x298434 pop {r4, r5, r6, pc}
 *   @0x298438 mov r0, r5
 *   @0x29843c mov r1, #1
 *   @0x298440 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298444 cmp r0, #63
 *   @0x298448 pophi {r4, r5, r6, pc}
 *   @0x29844c ldr r3, [pc, #0x8c]
 *   @0x298450 add r0, r0, r0, lsl #1
 *   @0x298454 lsl r0, r0, #2
 *   @0x298458 ldr r3, [r6, r3]
 *   @0x29845c ldrb r2, [r3, r0]
 *   @0x298460 cmp r2, #0
 *   @0x298464 addne r3, r3, r0
 *   @0x298468 movne r2, #1
 *   @0x29846c ldrne r3, [r3, #0x4]
 *   @0x298470 strbne r2, [r3, #0x30]
 *   @0x298474 pop {r4, r5, r6, pc}
 *   @0x298478 mov r0, r5
 *   @0x29847c mov r1, #1
 *   @0x298480 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298484 cmp r0, #63
 *   @0x298488 pophi {r4, r5, r6, pc}
 *   @0x29848c ldr r3, [pc, #0x4c]
 *   @0x298490 add r0, r0, r0, lsl #1
 *   @0x298494 lsl r0, r0, #2
 *   @0x298498 ldr r3, [r6, r3]
 *   @0x29849c ldrb r2, [r3, r0]
 *   @0x2984a0 cmp r2, #0
 *   @0x2984a4 addne r3, r3, r0
 *   @0x2984a8 movne r2, #0
 *   @0x2984ac ldrne r3, [r3, #0x4]
 *   @0x2984b0 strbne r2, [r3, #0x30]
 *   @0x2984b4 pop {r4, r5, r6, pc}
 *   @0x2984b8 ldr r0, [pc, #0x2c]
 *   @0x2984bc mov r1, #0
 *   @0x2984c0 add r0, pc, r0
 *   @0x2984c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x2984c8 mov r3, #0
 *   @0x2984cc mov r2, r3
 *   @0x2984d0 movt r3, #0xbff0
 *   @0x2984d4 stm r4, {r2, r3}
 *   @0x2984d8 pop {r4, r5, r6, pc}
 *   @0x2984dc ldrsbeq r9, [r5], -r8
 *   @0x2984e0 .word 0xfffffd54
 *   @0x2984e4 .word 0xfffffd3c
 *   @0x2984e8 .word 0xfffffd44
 *   @0x2984ec andeq r1, r12, r12, lsl #3
 *
 * ══ §25/76 jinit_2pass_quantizer  0x2bc654  size 408  102 条（0x2bc654..0x2bc7ec）
 * @func 0x2bc654 0x2bc7ec  size 408  102 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jinit_2pass_quantizer+0x158
 * 字段偏移 top8: 0x4×7 / 0x14×3 / 0x18×3 / 0x16c×2 / 0x20×2 / 0x4c×2 / 0x64×1 / 0x1a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bc654 push {r3, r4, r5, r6, r7, lr}
 *   @0x2bc658 mov r1, #1
 *   @0x2bc65c ldr r3, [r0, #0x4]
 *   @0x2bc660 mov r2, #44
 *   @0x2bc664 mov r5, r0
 *   @0x2bc668 ldr r3, [r3]
 *   @0x2bc66c blx r3
 *   @0x2bc670 ldr r1, [pc, #0x16c]
 *   @0x2bc674 ldr r2, [pc, #0x16c]
 *   @0x2bc678 mov r3, #0
 *   @0x2bc67c add r1, pc, r1
 *   @0x2bc680 add r2, pc, r2
 *   @0x2bc684 mov r7, r0
 *   @0x2bc688 ldr r0, [r5, #0x64]
 *   @0x2bc68c str r7, [r5, #0x1a8]
 *   @0x2bc690 cmp r0, #3
 *   @0x2bc694 str r1, [r7]
 *   @0x2bc698 str r2, [r7, #0xc]
 *   @0x2bc69c str r3, [r7, #0x20]
 *   @0x2bc6a0 str r3, [r7, #0x28]
 *   @0x2bc6a4 beq 0x2bc6c0 <jinit_2pass_quantizer+0x6c>
 *   @0x2bc6a8 ldr r3, [r5]
 *   @0x2bc6ac mov r2, #47
 *   @0x2bc6b0 mov r0, r5
 *   @0x2bc6b4 str r2, [r3, #0x14]
 *   @0x2bc6b8 ldr r3, [r3]
 *   @0x2bc6bc blx r3
 *   @0x2bc6c0 ldr r3, [r5, #0x4]
 *   @0x2bc6c4 mov r0, r5
 *   @0x2bc6c8 mov r1, #1
 *   @0x2bc6cc mov r2, #128
 *   @0x2bc6d0 mov r4, #0
 *   @0x2bc6d4 ldr r3, [r3]
 *   @0x2bc6d8 blx r3
 *   @0x2bc6dc mov r6, r0
 *   @0x2bc6e0 str r0, [r7, #0x18]
 *   @0x2bc6e4 b 0x2bc6ec <jinit_2pass_quantizer+0x98>
 *   @0x2bc6e8 ldr r6, [r7, #0x18]
 *   @0x2bc6ec ldr r3, [r5, #0x4]
 *   @0x2bc6f0 mov r0, r5
 *   @0x2bc6f4 mov r1, #1
 *   @0x2bc6f8 mov r2, #4096
 *   @0x2bc6fc ldr r3, [r3, #0x4]
 *   @0x2bc700 blx r3
 *   @0x2bc704 str r0, [r6, r4]
 *   @0x2bc708 add r4, r4, #4
 *   @0x2bc70c cmp r4, #128
 *   @0x2bc710 bne 0x2bc6e8 <jinit_2pass_quantizer+0x94>
 *   @0x2bc714 mov r3, #1
 *   @0x2bc718 strb r3, [r7, #0x1c]
 *   @0x2bc71c ldrb r3, [r5, #0x5a]
 *   @0x2bc720 cmp r3, #0
 *   @0x2bc724 streq r3, [r7, #0x10]
 *   @0x2bc728 beq 0x2bc764 <jinit_2pass_quantizer+0x110>
 *   @0x2bc72c ldr r4, [r5, #0x54]
 *   @0x2bc730 cmp r4, #7
 *   @0x2bc734 ble 0x2bc7ac <jinit_2pass_quantizer+0x158>
 *   @0x2bc738 cmp r4, #256
 *   @0x2bc73c bgt 0x2bc7d4 <jinit_2pass_quantizer+0x180>
 *   @0x2bc740 ldr r12, [r5, #0x4]
 *   @0x2bc744 mov r0, r5
 *   @0x2bc748 mov r1, #1
 *   @0x2bc74c mov r2, r4
 *   @0x2bc750 mov r3, #3
 *   @0x2bc754 ldr r12, [r12, #0x8]
 *   @0x2bc758 blx r12
 *   @0x2bc75c str r4, [r7, #0x14]
 *   @0x2bc760 str r0, [r7, #0x10]
 *   @0x2bc764 ldr r3, [r5, #0x4c]
 *   @0x2bc768 cmp r3, #0
 *   @0x2bc76c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x2bc770 ldr r3, [r5, #0x5c]
 *   @0x2bc774 mov r1, #2
 *   @0x2bc778 ldr r2, [r5, #0x4]
 *   @0x2bc77c mov r0, r5
 *   @0x2bc780 str r1, [r5, #0x4c]
 *   @0x2bc784 mov r1, #1
 *   @0x2bc788 add r3, r3, r3, lsl #1
 *   @0x2bc78c ldr r12, [r2, #0x4]
 *   @0x2bc790 lsl r2, r3, r1
 *   @0x2bc794 add r2, r2, #12
 *   @0x2bc798 blx r12
 *   @0x2bc79c str r0, [r7, #0x20]
 *   @0x2bc7a0 mov r0, r5
 *   @0x2bc7a4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x2bc7a8 b 0x2bb17c <jinit_1pass_quantizer+0x44c>
 *   @0x2bc7ac ldr r3, [r5]
 *   @0x2bc7b0 mov r2, #8
 *   @0x2bc7b4 mov r1, #56
 *   @0x2bc7b8 str r2, [r3, #0x18]
 *   @0x2bc7bc mov r0, r5
 *   @0x2bc7c0 ldr r2, [r5]
 *   @0x2bc7c4 str r1, [r3, #0x14]
 *   @0x2bc7c8 ldr r3, [r2]
 *   @0x2bc7cc blx r3
 *   @0x2bc7d0 b 0x2bc740 <jinit_2pass_quantizer+0xec>
 *   @0x2bc7d4 ldr r3, [r5]
 *   @0x2bc7d8 mov r2, #256
 *   @0x2bc7dc mov r1, #57
 *   @0x2bc7e0 b 0x2bc7b8 <jinit_2pass_quantizer+0x164>
 *   @0x2bc7e4 .word 0xffffebb4
 *   @0x2bc7e8 .word 0xffffeba0
 *
 * ══ §26/76 FT_Stream_OpenGzip  0x316ac0  size 408  102 条（0x316ac0..0x316c58）
 * @func 0x316ac0 0x316c58  size 408  102 条
 * 部分覆盖: 本节 102/183 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_free×2 / anon_31518e+0x422 / 0x355708 / FT_Stream_Pos / anon_31518e+0x69e / FT_Stream_ReadULongLE / 0x8d5a80 / anon_31518e+0x186c
 * 字段偏移 top8: 0x4×5 / 0x8×4 / 0xc×3 / 0x10×2 / 0x1c×2 / 0x34×2 / 0x14×2 / 0x114×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x316ac0 push.w {r0, r1, r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x316ac4 mov r6, r1
 *   @0x316ac8 cbz r0, 0x316acc <FT_Stream_OpenGzip+0xc>
 *   @0x316acc movs r3, #0x28
 *   @0x316ad0 b 0x316c3c <FT_Stream_OpenGzip+0x17c>
 *   @0x316ad4 ldr.w r8, [r1, #0x1c]
 *   @0x316ad8 bl 0x3155b0 <FT_Bitmap_Embolden+0x76a>
 *   @0x316adc mov r1, r0
 *   @0x316ae0 cmp r0, #0x0
 *   @0x316ae4 eorhs r8, r8, #171
 *   @0x316ae8 mov r0, r5
 *   @0x316aec strbtmi lr, [r10], -r2, ror #26
 *   @0x316af0 str.w r8, [r5, #0x1c]
 *   @0x316af4 mov r0, r8
 *   @0x316af8 .word 0xf7d00154
 *   @0x316afc bls 0x355708
 *   @0x316b00 mov r4, r0
 *   @0x316b04 bne 0x316b74 <FT_Stream_OpenGzip+0xb4>
 *   @0x316b08 str r6, [r0]
 *   @0x316b0c str r3, [r0, #0x8]
 *   @0x316b10 .word 0xf1035301
 *   @0x316b14 ldrtmi r0, [r0], -r8, lsl #2
 *   @0x316b18 str r1, [r3, #0x10]
 *   @0x316b1c str r2, [r3, #0x8]
 *   @0x316b20 strmi pc, [r7], -r7, asr #26
 *   @0x316b24 cbnz r0, 0x316b64 <FT_Stream_OpenGzip+0xa4>
 *   @0x316b28 bl 0x2e6940 <FT_Stream_Pos>
 *   @0x316b2c ldr r3, [pc, #0x114]
 *   @0x316b30 ldrbtmi r0, [r11], #-270
 *   @0x316b34 str r3, [r4, #0x2c]
 *   @0x316b38 add r3, pc
 *   @0x316b3c str r0, [r4, #0x44]
 *   @0x316b40 ldr r3, [r6, #0x1c]
 *   @0x316b44 str r3, [r4, #0x34]
 *   @0x316b48 movwlo r5, #0x8382
 *   @0x316b4c str r3, [r0, #12]!
 *   @0x316b50 bl 0x31582c <FT_Bitmap_Embolden+0x9e6>
 *   @0x316b54 cbnz r0, 0x316b62 <FT_Stream_OpenGzip+0xa2>
 *   @0x316b58 cmp r7, #0x0
 *   @0x316b5c moveq r7, #0x3
 *   @0x316b60 b 0x316b64 <FT_Stream_OpenGzip+0xa4>
 *   @0x316b64 str r7, [sp]
 *   @0x316b68 mov r0, r8
 *   @0x316b6c bl 0x2e7336 <ft_mem_free>
 *   @0x316b70 b 0x316c3c <FT_Stream_OpenGzip+0x17c>
 *   @0x316b74 ldr r1, [r6, #0x4]
 *   @0x316b78 ldr.w r10, [r6, #0x8]
 *   @0x316b7c subs r1, #0x4
 *   @0x316b80 stmdblt r8!, {r1, r4, r7, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x316b84 add r1, sp, #0x4
 *   @0x316b88 bl 0x2e6ee8 <FT_Stream_ReadULongLE>
 *   @0x316b8c ldr r7, [sp, #0x4]
 *   @0x316b90 cmp r7, #0x0
 *   @0x316b94 moveq r7, r0
 *   @0x316b98 mov r0, r6
 *   @0x316b9c and pc, r0, r4, lsl #29
 *   @0x316ba0 movs r7, #0x0
 *   @0x316ba4 movw r3, #0x9ffe
 *   @0x316ba8 cmp r2, r3
 *   @0x316bac mov r0, r8
 *   @0x316bb0 mov r2, sp
 *   @0x316bb4 .word 0x9e00fab8
 *   @0x316bb8 mov r9, r0
 *   @0x316bbc bne 0x316c18 <FT_Stream_OpenGzip+0x158>
 *   @0x316bc0 mov r1, r6
 *   @0x316bc4 mov r3, r7
 *   @0x316bc8 adcsmi pc, r8, #24, #30
 *   @0x316bcc bne 0x316c04 <FT_Stream_OpenGzip+0x144>
 *   @0x316bd0 .word 0xf7fe000c
 *   @0x316bd4 rscvs pc, r6, #13120
 *   @0x316bd8 str r6, [r4, #0x30]
 *   @0x316bdc str r6, [r4, #0x34]
 *   @0x316be0 str r6, [r4, #0xc]
 *   @0x316be4 str r6, [r4, #0x10]
 *   @0x316be8 str r6, [r4, #0x8]
 *   @0x316bec str r6, [r4, #0x4]
 *   @0x316bf0 blmi 0x8d5a80 <b2_toiTime+0x17c5dc>
 *   @0x316bf4 str r6, [r5, #0xc]
 *   @0x316bf8 add r3, pc
 *   @0x316bfc str.w r9, [r5]
 *   @0x316c00 str r6, [r5, #0x14]
 *   @0x316c04 mov r1, r6
 *   @0x316c08 mov r2, r6
 *   @0x316c0c bl 0x3169fa <FT_Bitmap_Embolden+0x1bb4>
 *   @0x316c10 mov r0, r8
 *   @0x316c14 bl 0x2e7336 <ft_mem_free>
 *   @0x316c18 movs r3, #0x0
 *   @0x316c1c b 0x316c20 <FT_Stream_OpenGzip+0x160>
 *   @0x316c20 str r7, [r5, #0x4]
 *   @0x316c24 mvn r3, #0x80000000
 *   @0x316c28 str r3, [r5, #0x4]
 *   @0x316c2c str r3, [r5, #0x8]
 *   @0x316c30 ldr r3, [pc, #0x1c]
 *   @0x316c34 str r3, [r5, #0x14]
 *   @0x316c38 add r3, pc
 *   @0x316c3c ldr r0, [sp]
 *   @0x316c40 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x316c44 orn pc, r7, pc, ror #31
 *   @0x316c48 .word 0xea59 ffff
 *   @0x316c4c cmp.w sp, pc, ror #31
 *   @0x316c50 mcr2 p15, #0x4, pc, c5, c15, #0x7
 *   @0x316c54 sbcs.w pc, sp, pc, ror #31
 *
 * ══ §27/76 Background_Add_Alpha(char const*, bool)  0xc3ccc  size 404  101 条（0xc3ccc..0xc3e60）
 * @func 0xc3ccc 0xc3e60  size 404  101 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / LoadSave::SaveFileExists(char const*) / LoadSave::_GetSaveFileName(char*, int, char const*) / 0xb65c8 / YYStrDup(char const*) / operator new(unsigned int) / CBackground::CBackground() / CBackground::LoadFromFile(char const*, bool, bool, bool, bool)
 * 字段偏移 top8: 0x2×3 / 0x50c×2 / 0x4×2 / 0x16c×1 / 0x138×1 / 0x134×1 / 0x130×1 / 0x12c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc3ccc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc3cd0 sub sp, sp, #1296
 *   @0xc3cd4 ldr r5, [pc, #0x16c]
 *   @0xc3cd8 mov r10, r1
 *   @0xc3cdc mov r4, r0
 *   @0xc3ce0 ldr r5, [pc, r5]
 *   @0xc3ce4 ldr r3, [r5]
 *   @0xc3ce8 str r3, [sp, #0x50c]
 *   @0xc3cec bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xc3cf0 cmp r0, #0
 *   @0xc3cf4 beq 0xc3e14 <_Z20Background_Add_AlphaPKcb+0x148>
 *   @0xc3cf8 add r8, sp, #268
 *   @0xc3cfc mov r2, r4
 *   @0xc3d00 mov r1, #1024
 *   @0xc3d04 mov r0, r8
 *   @0xc3d08 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0xc3d0c ldr r4, [pc, #0x138]
 *   @0xc3d10 movw r3, #0x213
 *   @0xc3d14 ldr r9, [pc, #0x134]
 *   @0xc3d18 ldr r4, [pc, r4]
 *   @0xc3d1c ldr r6, [pc, #0x130]
 *   @0xc3d20 add r9, pc, r9
 *   @0xc3d24 ldr r7, [pc, #0x12c]
 *   @0xc3d28 ldr r1, [r4]
 *   @0xc3d2c add r6, pc, r6
 *   @0xc3d30 mov r2, r9
 *   @0xc3d34 add r0, r6, #4
 *   @0xc3d38 add r1, r1, #1
 *   @0xc3d3c str r1, [r4]
 *   @0xc3d40 lsl r1, r1, #2
 *   @0xc3d44 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xc3d48 ldr r12, [r4]
 *   @0xc3d4c ldr r7, [pc, r7]
 *   @0xc3d50 mov r2, r9
 *   @0xc3d54 movw r3, #0x215
 *   @0xc3d58 add r9, sp, #12
 *   @0xc3d5c lsl r1, r12, #2
 *   @0xc3d60 mov r0, r7
 *   @0xc3d64 str r12, [r6]
 *   @0xc3d68 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xc3d6c ldr r3, [r4]
 *   @0xc3d70 mov r1, #256
 *   @0xc3d74 ldr r2, [pc, #0xe0]
 *   @0xc3d78 mov r0, r9
 *   @0xc3d7c sub r3, r3, #1
 *   @0xc3d80 add r2, pc, r2
 *   @0xc3d84 bl 0xb65c8 <snprintf@plt>
 *   @0xc3d88 ldr r3, [r4]
 *   @0xc3d8c mov r0, r9
 *   @0xc3d90 ldr r7, [r7]
 *   @0xc3d94 sub r9, r3, #-1073741823
 *   @0xc3d98 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xc3d9c str r0, [r7, r9, lsl #2]
 *   @0xc3da0 mov r0, #72
 *   @0xc3da4 bl 0x27c524 <_Znwj>
 *   @0xc3da8 mov r7, r0
 *   @0xc3dac bl 0xc2b58 <_ZN11CBackgroundC2Ev>
 *   @0xc3db0 ldr lr, [r4]
 *   @0xc3db4 mov r12, #1
 *   @0xc3db8 ldr r0, [r6, #0x4]
 *   @0xc3dbc mov r3, #0
 *   @0xc3dc0 sub lr, lr, #-1073741823
 *   @0xc3dc4 mov r1, r8
 *   @0xc3dc8 mov r2, r12
 *   @0xc3dcc str r7, [r0, lr, lsl #2]
 *   @0xc3dd0 ldr r0, [r6, #0x4]
 *   @0xc3dd4 ldr r0, [r0, lr, lsl #2]
 *   @0xc3dd8 stm sp, {r10, r12}
 *   @0xc3ddc bl 0xc2984 <_ZN11CBackground12LoadFromFileEPKcbbbb>
 *   @0xc3de0 cmp r0, #0
 *   @0xc3de4 ldrne r0, [r4]
 *   @0xc3de8 mvneq r0, #0
 *   @0xc3dec ldreq r3, [r4]
 *   @0xc3df0 subne r0, r0, #1
 *   @0xc3df4 addeq r3, r3, r0
 *   @0xc3df8 streq r3, [r4]
 *   @0xc3dfc ldr r2, [sp, #0x50c]
 *   @0xc3e00 ldr r3, [r5]
 *   @0xc3e04 cmp r2, r3
 *   @0xc3e08 bne 0xc3e44 <_Z20Background_Add_AlphaPKcb+0x178>
 *   @0xc3e0c add sp, sp, #1296
 *   @0xc3e10 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xc3e14 mov r0, r4
 *   @0xc3e18 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0xc3e1c cmp r0, #0
 *   @0xc3e20 beq 0xc3e3c <_Z20Background_Add_AlphaPKcb+0x170>
 *   @0xc3e24 add r8, sp, #268
 *   @0xc3e28 mov r2, r4
 *   @0xc3e2c mov r1, #1024
 *   @0xc3e30 mov r0, r8
 *   @0xc3e34 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0xc3e38 b 0xc3d0c <_Z20Background_Add_AlphaPKcb+0x40>
 *   @0xc3e3c mvn r0, #0
 *   @0xc3e40 b 0xc3dfc <_Z20Background_Add_AlphaPKcb+0x130>
 *   @0xc3e44 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xc3e48 eorseq r9, r2, r0, ror r12
 *   @0xc3e4c eorseq r9, r2, r0, lsr r12
 *   @0xc3e50 eoreq r12, r6, r0, ror #26
 *   @0xc3e54 eorseq r5, r11, r12, ror pc
 *   @0xc3e58 eorseq r9, r2, r0, lsl #24
 *   @0xc3e5c eoreq r12, r6, r12, asr #26
 *
 * ══ §28/76 F_ResourceGetType(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ec60  size 404  101 条（0x12ec60..0x12edf4）
 * @func 0x12ec60 0x12edf4  size 404  101 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / Object_Find(char const*) / F_ResourceGetType(RValue&, CInstance*, CInstance*, int, RValue*)+0x48 / Sprite_Find(char const*) / F_ResourceGetType(RValue&, CInstance*, CInstance*, int, RValue*)+0x6c / Sound_Find(char const*) / F_ResourceGetType(RValue&, CInstance*, CInstance*, int, RValue*)+0x8c / Audio_Find(char const*)
 * 字段偏移 top8: 0x4×9 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ec60 push {r4, r5, r6, lr}
 *   @0x12ec64 mov r5, #0
 *   @0x12ec68 mov r1, r5
 *   @0x12ec6c str r5, [r0, #0xc]
 *   @0x12ec70 str r5, [r0]
 *   @0x12ec74 mov r4, r0
 *   @0x12ec78 mov r3, r5
 *   @0x12ec7c movt r3, #0xbff0
 *   @0x12ec80 str r3, [r0, #0x4]
 *   @0x12ec84 ldr r0, [sp, #0x10]
 *   @0x12ec88 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12ec8c mov r6, r0
 *   @0x12ec90 bl 0x19edf4 <_Z11Object_FindPKc>
 *   @0x12ec94 cmp r0, r5
 *   @0x12ec98 blt 0x12eca8 <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12ec9c str r5, [r4]
 *   @0x12eca0 str r5, [r4, #0x4]
 *   @0x12eca4 pop {r4, r5, r6, pc}
 *   @0x12eca8 mov r0, r6
 *   @0x12ecac bl 0x1eef64 <_Z11Sprite_FindPKc>
 *   @0x12ecb0 cmp r0, #0
 *   @0x12ecb4 blt 0x12eccc <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x12ecb8 mov r3, #0
 *   @0x12ecbc str r5, [r4]
 *   @0x12ecc0 movt r3, #0x3ff0
 *   @0x12ecc4 str r3, [r4, #0x4]
 *   @0x12ecc8 pop {r4, r5, r6, pc}
 *   @0x12eccc mov r0, r6
 *   @0x12ecd0 bl 0x21fc54 <_Z10Sound_FindPKc>
 *   @0x12ecd4 cmp r0, #0
 *   @0x12ecd8 blt 0x12ecec <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x12ecdc mov r3, #1073741824
 *   @0x12ece0 str r5, [r4]
 *   @0x12ece4 str r3, [r4, #0x4]
 *   @0x12ece8 pop {r4, r5, r6, pc}
 *   @0x12ecec mov r0, r6
 *   @0x12ecf0 bl 0x219794 <_Z10Audio_FindPKc>
 *   @0x12ecf4 cmp r0, #0
 *   @0x12ecf8 bge 0x12ecdc <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x12ecfc mov r0, r6
 *   @0x12ed00 bl 0xc370c <_Z15Background_FindPKc>
 *   @0x12ed04 cmp r0, #0
 *   @0x12ed08 blt 0x12ed20 <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x12ed0c mov r3, #0
 *   @0x12ed10 str r5, [r4]
 *   @0x12ed14 movt r3, #0x4010
 *   @0x12ed18 str r3, [r4, #0x4]
 *   @0x12ed1c pop {r4, r5, r6, pc}
 *   @0x12ed20 mov r0, r6
 *   @0x12ed24 bl 0x1a80d4 <_Z9Path_FindPKc>
 *   @0x12ed28 cmp r0, #0
 *   @0x12ed2c blt 0x12ed44 <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x12ed30 mov r3, #0
 *   @0x12ed34 str r5, [r4]
 *   @0x12ed38 movt r3, #0x4014
 *   @0x12ed3c str r3, [r4, #0x4]
 *   @0x12ed40 pop {r4, r5, r6, pc}
 *   @0x12ed44 mov r0, r6
 *   @0x12ed48 bl 0xfa374 <_Z9Font_FindPKc>
 *   @0x12ed4c cmp r0, #0
 *   @0x12ed50 blt 0x12ed68 <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x12ed54 mov r3, #0
 *   @0x12ed58 str r5, [r4]
 *   @0x12ed5c movt r3, #0x401c
 *   @0x12ed60 str r3, [r4, #0x4]
 *   @0x12ed64 pop {r4, r5, r6, pc}
 *   @0x12ed68 mov r0, r6
 *   @0x12ed6c bl 0x1f2bcc <_Z13TimeLine_FindPKc>
 *   @0x12ed70 cmp r0, #0
 *   @0x12ed74 blt 0x12ed8c <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x12ed78 mov r3, #0
 *   @0x12ed7c str r5, [r4]
 *   @0x12ed80 movt r3, #0x4020
 *   @0x12ed84 str r3, [r4, #0x4]
 *   @0x12ed88 pop {r4, r5, r6, pc}
 *   @0x12ed8c mov r0, r6
 *   @0x12ed90 bl 0x1e0610 <_Z11Script_FindPKc>
 *   @0x12ed94 cmp r0, #0
 *   @0x12ed98 blt 0x12edb0 <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x12ed9c mov r3, #0
 *   @0x12eda0 str r5, [r4]
 *   @0x12eda4 movt r3, #0x4018
 *   @0x12eda8 str r3, [r4, #0x4]
 *   @0x12edac pop {r4, r5, r6, pc}
 *   @0x12edb0 mov r0, r6
 *   @0x12edb4 bl 0x1b524c <_Z9Room_FindPKc>
 *   @0x12edb8 cmp r0, #0
 *   @0x12edbc blt 0x12edd4 <_Z17F_ResourceGetTypeR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x12edc0 mov r3, #0
 *   @0x12edc4 mov r2, r3
 *   @0x12edc8 movt r3, #0x4008
 *   @0x12edcc stm r4, {r2, r3}
 *   @0x12edd0 pop {r4, r5, r6, pc}
 *   @0x12edd4 mov r0, r6
 *   @0x12edd8 bl 0x1e12dc <_Z11Shader_FindPKc>
 *   @0x12eddc cmp r0, #0
 *   @0x12ede0 movge r3, #0
 *   @0x12ede4 movge r2, r3
 *   @0x12ede8 movtge r3, #0x4024
 *   @0x12edec stmge r4, {r2, r3}
 *   @0x12edf0 pop {r4, r5, r6, pc}
 *
 * ══ §29/76 F_D3DLightGet(RValue&, CInstance*, CInstance*, int, RValue*)  0x146b00  size 404  101 条（0x146b00..0x146c94）
 * @func 0x146b00 0x146ca8  size 424  106 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x146b4c→0x484884, 0x146b60→0x484944, 0x146b74→0x4848a4, 0x146b78→0x4848c4, 0x146c50→0x4849c4
 * 调用序列: YYGetInt32(RValue const*, int) / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0x108×2 / 0x160×1 / 0x40×1 / 0x150×1 / 0x128×1 / 0x2×1 / 0x118×1 / 0x34×1
 * VFP 指令 38 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x146b00 push {r4, r5, lr}
 *   @0x146b04 cmp r3, #1
 *   @0x146b08 sub sp, sp, #52
 *   @0x146b0c ldr r4, [pc, #0x160]
 *   @0x146b10 mov r5, r0
 *   @0x146b14 add r4, pc, r4
 *   @0x146b18 ldr r0, [sp, #0x40]
 *   @0x146b1c beq 0x146b38 <_Z13F_D3DLightGetR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x146b20 ldr r0, [pc, #0x150]
 *   @0x146b24 add r0, pc, r0
 *   @0x146b28 mov r1, #0
 *   @0x146b2c add sp, sp, #52
 *   @0x146b30 pop {r4, r5, lr}
 *   @0x146b34 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x146b38 mov r1, #0
 *   @0x146b3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x146b40 cmp r0, #7
 *   @0x146b44 mov r3, r0
 *   @0x146b48 bhi 0x146c64 <_Z13F_D3DLightGetR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x146b4c ldr r2, [pc, #0x128]
 *   @0x146b50 ldr r2, [r4, r2]
 *   @0x146b54 ldr r1, [r2, r0, lsl #2]
 *   @0x146b58 cmp r1, #0
 *   @0x146b5c beq 0x146c50 <_Z13F_D3DLightGetR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x146b60 ldr r0, [pc, #0x118]
 *   @0x146b64 lsl r2, r3, #2
 *   @0x146b68 ldr r0, [r4, r0]
 *   @0x146b6c add r3, r0, r3, lsl #4
 *   @0x146b70 vmov s13, r1
 *   @0x146b74 ldr lr, [pc, #0x108]
 *   @0x146b78 ldr r12, [pc, #0x108]
 *   @0x146b7c mov r0, r5
 *   @0x146b80 vcvt.f64.s32 d7, s13
 *   @0x146b84 vldr s13, [pc, #228]
 *   @0x146b88 ldr lr, [r4, lr]
 *   @0x146b8c mov r1, #7
 *   @0x146b90 ldr r12, [r4, r12]
 *   @0x146b94 add lr, lr, r2
 *   @0x146b98 vldr s12, [lr]
 *   @0x146b9c add r2, r12, r2, lsl #2
 *   @0x146ba0 vstr d7, [sp]
 *   @0x146ba4 vldr s14, [r3]
 *   @0x146ba8 vcvt.f64.f32 d7, s14
 *   @0x146bac vstr d7, [sp, #8]
 *   @0x146bb0 vldr s14, [r3, #4]
 *   @0x146bb4 vcvt.f64.f32 d7, s14
 *   @0x146bb8 vstr d7, [sp, #16]
 *   @0x146bbc vldr s14, [r3, #8]
 *   @0x146bc0 vcvt.f64.f32 d7, s14
 *   @0x146bc4 vstr d7, [sp, #24]
 *   @0x146bc8 vldr s14, [r3, #12]
 *   @0x146bcc vcvt.f64.f32 d7, s14
 *   @0x146bd0 vstr d7, [sp, #32]
 *   @0x146bd4 vldr s11, [r2, #4]
 *   @0x146bd8 vmul.f32 s11, s11, s13
 *   @0x146bdc vldr s14, [r2, #8]
 *   @0x146be0 vldr s10, [r2]
 *   @0x146be4 vldr s15, [r2, #12]
 *   @0x146be8 vmul.f32 s14, s14, s13
 *   @0x146bec vmul.f32 s15, s15, s13
 *   @0x146bf0 vmul.f32 s13, s10, s13
 *   @0x146bf4 vcvt.u32.f32 s11, s11
 *   @0x146bf8 vcvt.u32.f32 s14, s14
 *   @0x146bfc vmov r2, s11
 *   @0x146c00 vcvt.u32.f32 s15, s15
 *   @0x146c04 vmov r3, s14
 *   @0x146c08 vcvt.u32.f32 s13, s13
 *   @0x146c0c vmov lr, s15
 *   @0x146c10 vmov r12, s13
 *   @0x146c14 lsl r2, r2, #8
 *   @0x146c18 vcvt.f64.f32 d7, s12
 *   @0x146c1c uxth r2, r2
 *   @0x146c20 uxtb r3, r3
 *   @0x146c24 orr r3, r2, r3, lsl #16
 *   @0x146c28 orr lr, r3, lr, lsl #24
 *   @0x146c2c vmov r2, r3, d7
 *   @0x146c30 uxtb r12, r12
 *   @0x146c34 orr r12, lr, r12
 *   @0x146c38 vmov s13, r12
 *   @0x146c3c vcvt.f64.u32 d7, s13
 *   @0x146c40 vstr d7, [sp, #40]
 *   @0x146c44 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x146c48 add sp, sp, #52
 *   @0x146c4c pop {r4, r5, pc}
 *   @0x146c50 ldr r0, [pc, #0x34]
 *   @0x146c54 lsl r2, r3, #2
 *   @0x146c58 ldr r0, [r4, r0]
 *   @0x146c5c add r3, r0, r3, lsl #4
 *   @0x146c60 b 0x146b70 <_Z13F_D3DLightGetR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x146c64 ldr r0, [pc, #0x24]
 *   @0x146c68 add r0, pc, r0
 *   @0x146c6c b 0x146b28 <_Z13F_D3DLightGetR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x146c70 cmnmi pc, #0
 *   @0x146c74 eoreq r11, r10, r12, lsr r1
 *   @0x146c78 andseq r10, pc, r12, asr #27
 *   @0x146c7c .word 0xffffd9cc
 *   @0x146c80 .word 0xffffd9d0
 *   @0x146c84 .word 0xffffd9d4
 *   @0x146c88 .word 0xffffd9d8
 *   @0x146c8c .word 0xffffd9dc
 *   @0x146c90 ldrsbeq r10, [pc], -r0
 *
 * ══ §30/76 FINALIZE_Sound()  0x21f49c  size 404  101 条（0x21f49c..0x21f630）
 * @func 0x21f49c 0x21f630  size 404  101 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSound::~CSound()×2 / operator delete(void*)×2 / MemoryManager::Free(void const*)×2 / FINALIZE_Sound()+0x8c / FINALIZE_Sound()+0x138 / FINALIZE_Sound()+0xcc
 * 字段偏移 top8: 0x4×7 / 0x168×1 / 0x15c×1 / 0x158×1 / 0xe0×1 / 0xc8×1 / 0xc4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f49c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21f4a0 ldr r3, [pc, #0x168]
 *   @0x21f4a4 ldr r8, [pc, r3]
 *   @0x21f4a8 cmp r8, #0
 *   @0x21f4ac ble 0x21f528 <_Z14FINALIZE_Soundv+0x8c>
 *   @0x21f4b0 ldr r7, [pc, #0x15c]
 *   @0x21f4b4 mov r4, #0
 *   @0x21f4b8 ldr r10, [pc, #0x158]
 *   @0x21f4bc mov r5, r4
 *   @0x21f4c0 add r7, pc, r7
 *   @0x21f4c4 mov r9, r4
 *   @0x21f4c8 add r10, pc, r10
 *   @0x21f4cc mov r2, r8
 *   @0x21f4d0 b 0x21f4f0 <_Z14FINALIZE_Soundv+0x54>
 *   @0x21f4d4 ldr r3, [r10, #0x4]
 *   @0x21f4d8 add r3, r3, r4
 *   @0x21f4dc add r5, r5, #1
 *   @0x21f4e0 add r4, r4, #4
 *   @0x21f4e4 cmp r5, r8
 *   @0x21f4e8 str r9, [r3]
 *   @0x21f4ec beq 0x21f52c <_Z14FINALIZE_Soundv+0x90>
 *   @0x21f4f0 cmp r5, r2
 *   @0x21f4f4 bge 0x21f4d4 <_Z14FINALIZE_Soundv+0x38>
 *   @0x21f4f8 ldr r1, [r7, #0x4]
 *   @0x21f4fc add r3, r1, r4
 *   @0x21f500 ldr r6, [r1, r4]
 *   @0x21f504 cmp r6, #0
 *   @0x21f508 mov r0, r6
 *   @0x21f50c beq 0x21f4dc <_Z14FINALIZE_Soundv+0x40>
 *   @0x21f510 bl 0x215384 <_ZN6CSoundD2Ev>
 *   @0x21f514 mov r0, r6
 *   @0x21f518 bl 0x27d1d0 <_ZdlPv>
 *   @0x21f51c ldm r7, {r2, r3}
 *   @0x21f520 add r3, r3, r4
 *   @0x21f524 b 0x21f4dc <_Z14FINALIZE_Soundv+0x40>
 *   @0x21f528 mov r2, r8
 *   @0x21f52c cmp r2, #0
 *   @0x21f530 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21f534 ldr r8, [pc, #0xe0]
 *   @0x21f538 add r8, pc, r8
 *   @0x21f53c ldr r5, [r8, #0x4]
 *   @0x21f540 cmp r5, #0
 *   @0x21f544 beq 0x21f600 <_Z14FINALIZE_Soundv+0x164>
 *   @0x21f548 cmp r2, #0
 *   @0x21f54c ble 0x21f5d4 <_Z14FINALIZE_Soundv+0x138>
 *   @0x21f550 ldr r10, [pc, #0xc8]
 *   @0x21f554 mov r4, #0
 *   @0x21f558 ldr r11, [pc, #0xc4]
 *   @0x21f55c mov r9, r4
 *   @0x21f560 add r10, pc, r10
 *   @0x21f564 add r11, pc, r11
 *   @0x21f568 ldr r1, [r5]
 *   @0x21f56c movw r3, #0xfeee
 *   @0x21f570 movt r3, #0xfeee
 *   @0x21f574 movw r2, #0xfeee
 *   @0x21f578 cmp r1, r3
 *   @0x21f57c movt r2, #0xfeee
 *   @0x21f580 lsl r7, r4, #2
 *   @0x21f584 beq 0x21f5c4 <_Z14FINALIZE_Soundv+0x128>
 *   @0x21f588 ldr r6, [r5, r4, lsl #2]
 *   @0x21f58c add r3, r5, r7
 *   @0x21f590 cmp r6, #0
 *   @0x21f594 mov r0, r6
 *   @0x21f598 beq 0x21f5c4 <_Z14FINALIZE_Soundv+0x128>
 *   @0x21f59c ldr r1, [r6]
 *   @0x21f5a0 cmp r1, r2
 *   @0x21f5a4 beq 0x21f5bc <_Z14FINALIZE_Soundv+0x120>
 *   @0x21f5a8 bl 0x215384 <_ZN6CSoundD2Ev>
 *   @0x21f5ac mov r0, r6
 *   @0x21f5b0 bl 0x27d1d0 <_ZdlPv>
 *   @0x21f5b4 ldr r3, [r11, #0x4]
 *   @0x21f5b8 add r3, r3, r7
 *   @0x21f5bc str r9, [r3]
 *   @0x21f5c0 ldr r5, [r10, #0x4]
 *   @0x21f5c4 ldr r3, [r8]
 *   @0x21f5c8 add r4, r4, #1
 *   @0x21f5cc cmp r4, r3
 *   @0x21f5d0 blt 0x21f568 <_Z14FINALIZE_Soundv+0xcc>
 *   @0x21f5d4 mov r0, r5
 *   @0x21f5d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f5dc ldr r3, [pc, #0x44]
 *   @0x21f5e0 mov r2, #0
 *   @0x21f5e4 add r3, pc, r3
 *   @0x21f5e8 str r2, [r3, #0x4]
 *   @0x21f5ec ldr r3, [pc, #0x38]
 *   @0x21f5f0 mov r2, #0
 *   @0x21f5f4 add r3, pc, r3
 *   @0x21f5f8 str r2, [r3]
 *   @0x21f5fc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21f600 mov r0, r5
 *   @0x21f604 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f608 str r5, [r8, #0x4]
 *   @0x21f60c b 0x21f5ec <_Z14FINALIZE_Soundv+0x150>
 *   @0x21f610 .word 0x00535e94
 *   @0x21f614 subseq r5, r3, r8, ror lr
 *   @0x21f618 subseq r5, r3, r0, ror lr
 *   @0x21f61c subseq r5, r3, r0, lsl #28
 *   @0x21f620 ldrsbeq r5, [r3], #-216
 *   @0x21f624 ldrsbeq r5, [r3], #-212
 *   @0x21f628 subseq r5, r3, r4, asr sp
 *   @0x21f62c subseq r5, r3, r4, asr #26
 *
 * ══ §31/76 JS_CreateNativeErrorSetup(char const*, void (*)(RValue&, CInstance*, CInstance*, int, RValue*), YYObjectBase**, YYObjectBase*)  0x2441d4  size 404  101 条（0x2441d4..0x244368）
 * @func 0x2441d4 0x244368  size 404  101 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×3 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / YYObjectBase::Add(char const*, char const*, int)×2 / JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×2 / YYObjectBase::Add(char const*, YYObjectBase*, int)×2 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x28×2 / 0xf8×2 / 0x138×1 / 0x18×1 / 0x40×1 / 0x114×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2441d4 push {r4, r5, r6, r7, r8, lr}
 *   @0x2441d8 sub sp, sp, #24
 *   @0x2441dc mov r12, #0
 *   @0x2441e0 mov r5, r3
 *   @0x2441e4 str r12, [sp]
 *   @0x2441e8 mov r3, r12
 *   @0x2441ec mov r6, r1
 *   @0x2441f0 mov r7, r2
 *   @0x2441f4 mov r1, r12
 *   @0x2441f8 mov r2, r12
 *   @0x2441fc mov r8, r0
 *   @0x244200 add r0, sp, #8
 *   @0x244204 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x244208 ldr r4, [sp, #0x8]
 *   @0x24420c ldr r3, [pc, #0x138]
 *   @0x244210 cmp r7, #0
 *   @0x244214 mov r1, r5
 *   @0x244218 strne r4, [r7]
 *   @0x24421c add r3, pc, r3
 *   @0x244220 str r5, [r4, #0x18]
 *   @0x244224 mov r0, r4
 *   @0x244228 str r3, [r4, #0x40]
 *   @0x24422c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x244230 ldr r3, [r4, #0x28]
 *   @0x244234 ldr r1, [pc, #0x114]
 *   @0x244238 mov r2, r8
 *   @0x24423c mov r0, r4
 *   @0x244240 orr r3, r3, #1
 *   @0x244244 add r1, pc, r1
 *   @0x244248 str r3, [r4, #0x28]
 *   @0x24424c mov r3, #6
 *   @0x244250 bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i>
 *   @0x244254 ldr r1, [pc, #0xf8]
 *   @0x244258 ldr r2, [pc, #0xf8]
 *   @0x24425c mov r3, #6
 *   @0x244260 mov r0, r4
 *   @0x244264 add r1, pc, r1
 *   @0x244268 add r2, pc, r2
 *   @0x24426c bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i>
 *   @0x244270 ldr r0, [pc, #0xe4]
 *   @0x244274 mov r1, #0
 *   @0x244278 mov r2, r1
 *   @0x24427c ldr r0, [pc, r0]
 *   @0x244280 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x244284 ldr r1, [pc, #0xd4]
 *   @0x244288 mov r3, #6
 *   @0x24428c add r1, pc, r1
 *   @0x244290 mov r2, r0
 *   @0x244294 mov r0, r4
 *   @0x244298 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x24429c mov r1, #0
 *   @0x2442a0 mov r2, r1
 *   @0x2442a4 mov r0, r6
 *   @0x2442a8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2442ac ldr r1, [pc, #0xb0]
 *   @0x2442b0 mov r3, #0
 *   @0x2442b4 add r1, pc, r1
 *   @0x2442b8 mov r5, r0
 *   @0x2442bc str r6, [r0, #0x94]
 *   @0x2442c0 mov r2, r0
 *   @0x2442c4 mov r0, r4
 *   @0x2442c8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2442cc ldr r1, [r5, #0x4]
 *   @0x2442d0 cmp r1, #0
 *   @0x2442d4 beq 0x244310 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_+0x13c>
 *   @0x2442d8 str r4, [r1]
 *   @0x2442dc mov r0, r5
 *   @0x2442e0 mov r1, r4
 *   @0x2442e4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2442e8 ldr r1, [r5, #0x4]
 *   @0x2442ec cmp r1, #0
 *   @0x2442f0 movne r3, #6
 *   @0x2442f4 strne r3, [r1, #0xc]
 *   @0x2442f8 beq 0x244320 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_+0x14c>
 *   @0x2442fc mov r3, #6
 *   @0x244300 mov r0, r5
 *   @0x244304 str r3, [r1, #0x8]
 *   @0x244308 add sp, sp, #24
 *   @0x24430c pop {r4, r5, r6, r7, r8, pc}
 *   @0x244310 mov r0, r5
 *   @0x244314 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x244318 mov r1, r0
 *   @0x24431c b 0x2442d8 <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_+0x104>
 *   @0x244320 mov r0, r5
 *   @0x244324 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x244328 ldr r1, [r5, #0x4]
 *   @0x24432c mov r3, #6
 *   @0x244330 cmp r1, #0
 *   @0x244334 str r3, [r0, #0xc]
 *   @0x244338 bne 0x2442fc <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_+0x128>
 *   @0x24433c mov r0, r5
 *   @0x244340 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x244344 mov r1, r0
 *   @0x244348 b 0x2442fc <_Z25JS_CreateNativeErrorSetupPKcPFvR6RValueP9CInstanceS4_iPS1_EPP12YYObjectBaseS9_+0x128>
 *   @0x24434c andseq r1, r1, r8, ror #14
 *   @0x244350 andeq r12, lr, r4, asr #11
 *   @0x244354 andseq r5, r0, r0, lsr #10
 *   @0x244358 andeq r10, lr, lr, asr #17
 *   @0x24435c andseq sp, r10, r8, ror #8
 *   @0x244360 andeq lr, lr, r4, lsl #5
 *   @0x244364 andseq r1, r1, r0, ror r2
 *
 * ══ §32/76 b2WheelJoint::SolveVelocityConstraints(b2SolverData const&)  0x2d3798  size 404  101 条（0x2d3798..0x2d392c）
 * @func 0x2d3798 0x2d392c  size 404  101 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x84×1 / 0x88×1 / 0x1c×1
 * VFP 指令 93 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d3798 ldr r2, [r0, #0x84]
 *   @0x2d379c vldr s15, [r0, #176]
 *   @0x2d37a0 ldr r3, [r0, #0x88]
 *   @0x2d37a4 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d37a8 ldr r12, [r1, #0x1c]
 *   @0x2d37ac vldr s19, [r0, #172]
 *   @0x2d37b0 add r2, r2, r2, lsl #1
 *   @0x2d37b4 vldr s20, [r0, #192]
 *   @0x2d37b8 add r3, r3, r3, lsl #1
 *   @0x2d37bc vldr s24, [r0, #188]
 *   @0x2d37c0 add r2, r12, r2, lsl #2
 *   @0x2d37c4 vldr s2, [r2, #4]
 *   @0x2d37c8 add r3, r12, r3, lsl #2
 *   @0x2d37cc vldr s6, [r3, #4]
 *   @0x2d37d0 vsub.f32 s14, s6, s2
 *   @0x2d37d4 vldr s1, [r2]
 *   @0x2d37d8 vldr s5, [r3]
 *   @0x2d37dc vldr s7, [r3, #8]
 *   @0x2d37e0 vldr s3, [r2, #8]
 *   @0x2d37e4 vldr s29, [r0, #216]
 *   @0x2d37e8 vldr s8, [r0, #116]
 *   @0x2d37ec vldr s28, [r0, #220]
 *   @0x2d37f0 vldr s27, [r0, #212]
 *   @0x2d37f4 vldr s10, [r0, #164]
 *   @0x2d37f8 vldr s11, [r0, #168]
 *   @0x2d37fc vldr s26, [r0, #124]
 *   @0x2d3800 vldr s18, [r0, #112]
 *   @0x2d3804 vldr s25, [r0, #208]
 *   @0x2d3808 vldr s12, [r0, #156]
 *   @0x2d380c vldr s13, [r0, #160]
 *   @0x2d3810 vldr s23, [r1]
 *   @0x2d3814 vldr s9, [r0, #120]
 *   @0x2d3818 vldr s17, [r0, #184]
 *   @0x2d381c vldr s4, [r0, #180]
 *   @0x2d3820 vmul.f32 s14, s14, s15
 *   @0x2d3824 vldr s0, [r0, #200]
 *   @0x2d3828 vldr s16, [r0, #196]
 *   @0x2d382c vldr s22, [r0, #204]
 *   @0x2d3830 vldr s21, [r0, #108]
 *   @0x2d3834 vsub.f32 s30, s5, s1
 *   @0x2d3838 vmla.f32 s14, s30, s19
 *   @0x2d383c vmla.f32 s14, s20, s7
 *   @0x2d3840 vmls.f32 s14, s24, s3
 *   @0x2d3844 vadd.f32 s14, s14, s29
 *   @0x2d3848 vmla.f32 s14, s8, s28
 *   @0x2d384c vnmul.f32 s14, s27, s14
 *   @0x2d3850 vmul.f32 s24, s24, s14
 *   @0x2d3854 vmul.f32 s20, s20, s14
 *   @0x2d3858 vmls.f32 s3, s10, s24
 *   @0x2d385c vmla.f32 s7, s11, s20
 *   @0x2d3860 vsub.f32 s20, s7, s3
 *   @0x2d3864 vsub.f32 s20, s20, s26
 *   @0x2d3868 vmul.f32 s15, s14, s15
 *   @0x2d386c vmov.f32 s24, s18
 *   @0x2d3870 vmls.f32 s24, s25, s20
 *   @0x2d3874 vmul.f32 s19, s14, s19
 *   @0x2d3878 vmls.f32 s2, s12, s15
 *   @0x2d387c vmla.f32 s6, s13, s15
 *   @0x2d3880 vmul.f32 s9, s23, s9
 *   @0x2d3884 vmls.f32 s1, s12, s19
 *   @0x2d3888 vmla.f32 s5, s13, s19
 *   @0x2d388c vcmpe.f32 s9, s24
 *   @0x2d3890 vneg.f32 s19, s9
 *   @0x2d3894 vmrs APSR_nzcv, fpscr
 *   @0x2d3898 vsub.f32 s15, s6, s2
 *   @0x2d389c vmovgt.f32 s9, s24
 *   @0x2d38a0 vcmpe.f32 s19, s9
 *   @0x2d38a4 vmrs APSR_nzcv, fpscr
 *   @0x2d38a8 vmovgt.f32 s9, s19
 *   @0x2d38ac vstr s9, [r0, #112]
 *   @0x2d38b0 vmul.f32 s15, s15, s17
 *   @0x2d38b4 vsub.f32 s19, s5, s1
 *   @0x2d38b8 vsub.f32 s9, s9, s18
 *   @0x2d38bc vmla.f32 s15, s19, s4
 *   @0x2d38c0 vmla.f32 s7, s11, s9
 *   @0x2d38c4 vmls.f32 s3, s10, s9
 *   @0x2d38c8 vmla.f32 s15, s0, s7
 *   @0x2d38cc vmls.f32 s15, s16, s3
 *   @0x2d38d0 vnmul.f32 s15, s22, s15
 *   @0x2d38d4 vmul.f32 s9, s15, s17
 *   @0x2d38d8 vmul.f32 s4, s15, s4
 *   @0x2d38dc vmul.f32 s16, s16, s15
 *   @0x2d38e0 vmul.f32 s0, s0, s15
 *   @0x2d38e4 vmls.f32 s3, s10, s16
 *   @0x2d38e8 vmls.f32 s1, s12, s4
 *   @0x2d38ec vmls.f32 s2, s12, s9
 *   @0x2d38f0 vmla.f32 s5, s13, s4
 *   @0x2d38f4 vmla.f32 s6, s13, s9
 *   @0x2d38f8 vmla.f32 s7, s11, s0
 *   @0x2d38fc vadd.f32 s15, s21, s15
 *   @0x2d3900 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d3904 vadd.f32 s14, s8, s14
 *   @0x2d3908 vstr s15, [r0, #108]
 *   @0x2d390c vstr s14, [r0, #116]
 *   @0x2d3910 vstr s1, [r2]
 *   @0x2d3914 vstr s2, [r2, #4]
 *   @0x2d3918 vstr s3, [r2, #8]
 *   @0x2d391c vstr s5, [r3]
 *   @0x2d3920 vstr s6, [r3, #4]
 *   @0x2d3924 vstr s7, [r3, #8]
 *   @0x2d3928 bx lr
 *
 * ══ §33/76 __subsf3  0x3191cc  size 404  101 条（0x3191cc..0x319360）
 * @func 0x3191cc 0x319360  size 404  101 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_fadd+0xbc / __aeabi_fadd+0xa8
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3191cc eor r1, r1, #-2147483648
 *   @0x3191d0 lsls r2, r0, #1
 *   @0x3191d4 lslsne r3, r1, #1
 *   @0x3191d8 teqne r2, r3
 *   @0x3191dc mvnsne r12, r2, asr #24
 *   @0x3191e0 mvnsne r12, r3, asr #24
 *   @0x3191e4 beq 0x3192dc <__aeabi_fadd+0x10c>
 *   @0x3191e8 lsr r2, r2, #24
 *   @0x3191ec rsbs r3, r2, r3, lsr #24
 *   @0x3191f0 addgt r2, r2, r3
 *   @0x3191f4 eorgt r1, r0, r1
 *   @0x3191f8 eorgt r0, r1, r0
 *   @0x3191fc eorgt r1, r0, r1
 *   @0x319200 rsblt r3, r3, #0
 *   @0x319204 cmp r3, #25
 *   @0x319208 bxhi lr
 *   @0x31920c tst r0, #-2147483648
 *   @0x319210 orr r0, r0, #8388608
 *   @0x319214 bic r0, r0, #-16777216
 *   @0x319218 rsbne r0, r0, #0
 *   @0x31921c tst r1, #-2147483648
 *   @0x319220 orr r1, r1, #8388608
 *   @0x319224 bic r1, r1, #-16777216
 *   @0x319228 rsbne r1, r1, #0
 *   @0x31922c teq r2, r3
 *   @0x319230 beq 0x3192c4 <__aeabi_fadd+0xf4>
 *   @0x319234 sub r2, r2, #1
 *   @0x319238 adds r0, r0, r1, asr r3
 *   @0x31923c rsb r3, r3, #32
 *   @0x319240 lsl r1, r1, r3
 *   @0x319244 and r3, r0, #-2147483648
 *   @0x319248 bpl 0x319254 <__aeabi_fadd+0x84>
 *   @0x31924c rsbs r1, r1, #0
 *   @0x319250 rsc r0, r0, #0
 *   @0x319254 cmp r0, #8388608
 *   @0x319258 blo 0x31928c <__aeabi_fadd+0xbc>
 *   @0x31925c cmp r0, #16777216
 *   @0x319260 blo 0x319278 <__aeabi_fadd+0xa8>
 *   @0x319264 lsrs r0, r0, #1
 *   @0x319268 rrx r1, r1
 *   @0x31926c add r2, r2, #1
 *   @0x319270 cmp r2, #254
 *   @0x319274 bhs 0x319330 <__aeabi_fadd+0x160>
 *   @0x319278 cmp r1, #-2147483648
 *   @0x31927c adc r0, r0, r2, lsl #23
 *   @0x319280 biceq r0, r0, #1
 *   @0x319284 orr r0, r0, r3
 *   @0x319288 bx lr
 *   @0x31928c lsls r1, r1, #1
 *   @0x319290 adc r0, r0, r0
 *   @0x319294 tst r0, #8388608
 *   @0x319298 sub r2, r2, #1
 *   @0x31929c bne 0x319278 <__aeabi_fadd+0xa8>
 *   @0x3192a0 clz r12, r0
 *   @0x3192a4 sub r12, r12, #8
 *   @0x3192a8 subs r2, r2, r12
 *   @0x3192ac lsl r0, r0, r12
 *   @0x3192b0 addge r0, r0, r2, lsl #23
 *   @0x3192b4 rsblt r2, r2, #0
 *   @0x3192b8 orrge r0, r0, r3
 *   @0x3192bc orrlt r0, r3, r0, lsr r2
 *   @0x3192c0 bx lr
 *   @0x3192c4 teq r2, #0
 *   @0x3192c8 eor r1, r1, #8388608
 *   @0x3192cc eoreq r0, r0, #8388608
 *   @0x3192d0 addeq r2, r2, #1
 *   @0x3192d4 subne r3, r3, #1
 *   @0x3192d8 b 0x319234 <__aeabi_fadd+0x64>
 *   @0x3192dc lsl r3, r1, #1
 *   @0x3192e0 mvns r12, r2, asr #24
 *   @0x3192e4 mvnsne r12, r3, asr #24
 *   @0x3192e8 beq 0x31933c <__aeabi_fadd+0x16c>
 *   @0x3192ec teq r2, r3
 *   @0x3192f0 beq 0x319300 <__aeabi_fadd+0x130>
 *   @0x3192f4 teq r2, #0
 *   @0x3192f8 moveq r0, r1
 *   @0x3192fc bx lr
 *   @0x319300 teq r0, r1
 *   @0x319304 movne r0, #0
 *   @0x319308 bxne lr
 *   @0x31930c tst r2, #-16777216
 *   @0x319310 bne 0x319320 <__aeabi_fadd+0x150>
 *   @0x319314 lsls r0, r0, #1
 *   @0x319318 orrhs r0, r0, #-2147483648
 *   @0x31931c bx lr
 *   @0x319320 adds r2, r2, #33554432
 *   @0x319324 addlo r0, r0, #8388608
 *   @0x319328 bxlo lr
 *   @0x31932c and r3, r0, #-2147483648
 *   @0x319330 orr r0, r3, #2130706432
 *   @0x319334 orr r0, r0, #8388608
 *   @0x319338 bx lr
 *   @0x31933c mvns r2, r2, asr #24
 *   @0x319340 movne r0, r1
 *   @0x319344 mvnseq r3, r3, asr #24
 *   @0x319348 movne r1, r0
 *   @0x31934c lsls r2, r0, #9
 *   @0x319350 lslseq r3, r1, #9
 *   @0x319354 teqeq r0, r1
 *   @0x319358 orrne r0, r0, #4194304
 *   @0x31935c bx lr
 *
 * ══ §34/76 CSkeletonInstance::GetBoneData(char const*, int)  0xbfd18  size 400  100 条（0xbfd18..0xbfea8）
 * @func 0xbfd18 0xbfea8  size 400  100 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Map::Add(char const*, double, char const*)×7 / DS_AutoMutex::~DS_AutoMutex()×2 / spSkeleton_findBone / DS_AutoMutex::DS_AutoMutex()
 * 字段偏移 top8: 0x4×2 / 0x1c×1 / 0x13c×1 / 0x2×1 / 0x11c×1 / 0xf8×1 / 0xd8×1 / 0xb8×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbfd18 push {r4, r5, r6, r7, lr}
 *   @0xbfd1c sub sp, sp, #20
 *   @0xbfd20 ldr r0, [r0, #0x1c]
 *   @0xbfd24 mov r4, r2
 *   @0xbfd28 bl 0x28a0c8 <spSkeleton_findBone>
 *   @0xbfd2c subs r5, r0, #0
 *   @0xbfd30 moveq r0, r5
 *   @0xbfd34 beq 0xbfe6c <_ZN17CSkeletonInstance11GetBoneDataEPKci+0x154>
 *   @0xbfd38 add r7, sp, #12
 *   @0xbfd3c mov r0, r7
 *   @0xbfd40 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xbfd44 ldr r3, [pc, #0x13c]
 *   @0xbfd48 ldr r3, [pc, r3]
 *   @0xbfd4c ldr r3, [r3, #0x4]
 *   @0xbfd50 ldr r4, [r3, r4, lsl #2]
 *   @0xbfd54 cmp r4, #0
 *   @0xbfd58 beq 0xbfe74 <_ZN17CSkeletonInstance11GetBoneDataEPKci+0x15c>
 *   @0xbfd5c ldr r3, [r5]
 *   @0xbfd60 vldr s15, [r3, #12]
 *   @0xbfd64 vcvt.f64.f32 d6, s15
 *   @0xbfd68 ldr r1, [pc, #0x11c]
 *   @0xbfd6c mov r6, #0
 *   @0xbfd70 mov r0, r4
 *   @0xbfd74 add r1, pc, r1
 *   @0xbfd78 str r6, [sp]
 *   @0xbfd7c vmov r2, r3, d6
 *   @0xbfd80 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbfd84 ldr r3, [r5]
 *   @0xbfd88 vldr s15, [r3, #16]
 *   @0xbfd8c vcvt.f64.f32 d6, s15
 *   @0xbfd90 ldr r1, [pc, #0xf8]
 *   @0xbfd94 mov r0, r4
 *   @0xbfd98 str r6, [sp]
 *   @0xbfd9c add r1, pc, r1
 *   @0xbfda0 vmov r2, r3, d6
 *   @0xbfda4 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbfda8 ldr r3, [r5]
 *   @0xbfdac vldr s15, [r3, #20]
 *   @0xbfdb0 vcvt.f64.f32 d6, s15
 *   @0xbfdb4 ldr r1, [pc, #0xd8]
 *   @0xbfdb8 mov r0, r4
 *   @0xbfdbc str r6, [sp]
 *   @0xbfdc0 add r1, pc, r1
 *   @0xbfdc4 vmov r2, r3, d6
 *   @0xbfdc8 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbfdcc ldr r3, [r5]
 *   @0xbfdd0 vldr s15, [r3, #24]
 *   @0xbfdd4 vcvt.f64.f32 d6, s15
 *   @0xbfdd8 ldr r1, [pc, #0xb8]
 *   @0xbfddc mov r0, r4
 *   @0xbfde0 str r6, [sp]
 *   @0xbfde4 add r1, pc, r1
 *   @0xbfde8 vmov r2, r3, d6
 *   @0xbfdec bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbfdf0 ldr r3, [r5]
 *   @0xbfdf4 vldr s15, [r3, #28]
 *   @0xbfdf8 vcvt.f64.f32 d6, s15
 *   @0xbfdfc ldr r1, [pc, #0x98]
 *   @0xbfe00 mov r0, r4
 *   @0xbfe04 str r6, [sp]
 *   @0xbfe08 add r1, pc, r1
 *   @0xbfe0c vmov r2, r3, d6
 *   @0xbfe10 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbfe14 ldr r3, [r5]
 *   @0xbfe18 vldr s15, [r3, #32]
 *   @0xbfe1c vcvt.f64.f32 d6, s15
 *   @0xbfe20 ldr r1, [pc, #0x78]
 *   @0xbfe24 mov r0, r4
 *   @0xbfe28 str r6, [sp]
 *   @0xbfe2c add r1, pc, r1
 *   @0xbfe30 vmov r2, r3, d6
 *   @0xbfe34 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbfe38 ldr r12, [r5]
 *   @0xbfe3c ldr r1, [pc, #0x60]
 *   @0xbfe40 mov r2, #0
 *   @0xbfe44 mov r3, #0
 *   @0xbfe48 mov r0, r4
 *   @0xbfe4c ldr r12, [r12, #0x8]
 *   @0xbfe50 add r1, pc, r1
 *   @0xbfe54 ldr r12, [r12, #0x4]
 *   @0xbfe58 str r12, [sp]
 *   @0xbfe5c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbfe60 mov r0, r7
 *   @0xbfe64 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xbfe68 mov r0, #1
 *   @0xbfe6c add sp, sp, #20
 *   @0xbfe70 pop {r4, r5, r6, r7, pc}
 *   @0xbfe74 mov r0, r7
 *   @0xbfe78 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xbfe7c mov r0, r4
 *   @0xbfe80 add sp, sp, #20
 *   @0xbfe84 pop {r4, r5, r6, r7, pc}
 *   @0xbfe88 ldrshteq sp, [r2], -r4
 *   @0xbfe8c .word 0x00270af8
 *   @0xbfe90 .word 0x00270ad8
 *   @0xbfe94 .word 0x00270ab8
 *   @0xbfe98 mlaeq r7, r8, r10, r0
 *   @0xbfe9c eoreq r0, r7, r12, ror r10
 *   @0xbfea0 eoreq r0, r7, r0, ror #20
 *   @0xbfea4 eoreq r0, r7, r4, asr #20
 *
 * ══ §35/76 F_MoveWrap(RValue&, CInstance*, CInstance*, int, RValue*)  0x1081ec  size 400  100 条（0x1081ec..0x10837c）
 * @func 0x1081ec 0x10837c  size 400  100 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x108248→0x54298c, 0x10828c→0x54298c
 * 调用序列: CInstance::SetPosition(float, float)×3 / YYGetBool(RValue const*, int)×2 / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0xb4×2 / 0xb8×2 / 0x20×1 / 0x16c×1 / 0x128×1 / 0xe4×1
 * VFP 指令 46 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1081ec push {r4, r5, r6, r7, r8, lr}
 *   @0x1081f0 vpush {d8}
 *   @0x1081f4 mov r5, r1
 *   @0x1081f8 ldr r4, [sp, #0x20]
 *   @0x1081fc mov r1, #0
 *   @0x108200 ldr r6, [pc, #0x16c]
 *   @0x108204 mov r0, r4
 *   @0x108208 add r6, pc, r6
 *   @0x10820c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x108210 mov r1, #1
 *   @0x108214 mov r8, r0
 *   @0x108218 mov r0, r4
 *   @0x10821c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x108220 mov r1, #2
 *   @0x108224 mov r7, r0
 *   @0x108228 mov r0, r4
 *   @0x10822c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108230 cmp r8, #0
 *   @0x108234 vmov s16, r0
 *   @0x108238 beq 0x108278 <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x10823c vldr s14, [pc, #300]
 *   @0x108240 vsub.f32 s14, s14, s16
 *   @0x108244 vldr s15, [r5, #180]
 *   @0x108248 ldr r3, [pc, #0x128]
 *   @0x10824c vcmpe.f32 s15, s14
 *   @0x108250 vmrs APSR_nzcv, fpscr
 *   @0x108254 bmi 0x10833c <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x108258 ldr r4, [r6, r3]
 *   @0x10825c ldr r3, [r4]
 *   @0x108260 vldr s14, [r3, #16]
 *   @0x108264 vcvt.f32.s32 s14, s14
 *   @0x108268 vadd.f32 s13, s14, s16
 *   @0x10826c vcmpe.f32 s13, s15
 *   @0x108270 vmrs APSR_nzcv, fpscr
 *   @0x108274 bmi 0x10831c <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x108278 cmp r7, #0
 *   @0x10827c beq 0x1082e0 <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x108280 vldr s14, [pc, #232]
 *   @0x108284 vsub.f32 s14, s14, s16
 *   @0x108288 vldr s15, [r5, #184]
 *   @0x10828c ldr r3, [pc, #0xe4]
 *   @0x108290 vcmpe.f32 s15, s14
 *   @0x108294 vmrs APSR_nzcv, fpscr
 *   @0x108298 bmi 0x1082e8 <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x10829c ldr r4, [r6, r3]
 *   @0x1082a0 ldr r3, [r4]
 *   @0x1082a4 vldr s14, [r3, #20]
 *   @0x1082a8 vcvt.f32.s32 s14, s14
 *   @0x1082ac vadd.f32 s13, s14, s16
 *   @0x1082b0 vcmpe.f32 s13, s15
 *   @0x1082b4 vmrs APSR_nzcv, fpscr
 *   @0x1082b8 bpl 0x1082e0 <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x1082bc vsub.f32 s15, s15, s14
 *   @0x1082c0 mov r0, r5
 *   @0x1082c4 ldr r1, [r5, #0xb4]
 *   @0x1082c8 vadd.f32 s16, s16, s16
 *   @0x1082cc vsub.f32 s16, s15, s16
 *   @0x1082d0 vmov r2, s16
 *   @0x1082d4 vpop {d8}
 *   @0x1082d8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1082dc b 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1082e0 vpop {d8}
 *   @0x1082e4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1082e8 ldr r4, [r6, r3]
 *   @0x1082ec vadd.f32 s14, s16, s16
 *   @0x1082f0 mov r0, r5
 *   @0x1082f4 ldr r1, [r5, #0xb4]
 *   @0x1082f8 ldr r3, [r4]
 *   @0x1082fc vldr s13, [r3, #20]
 *   @0x108300 vcvt.f32.s32 s13, s13
 *   @0x108304 vadd.f32 s15, s15, s13
 *   @0x108308 vadd.f32 s14, s15, s14
 *   @0x10830c vmov r2, s14
 *   @0x108310 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x108314 vldr s15, [r5, #184]
 *   @0x108318 b 0x1082a0 <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x10831c vsub.f32 s15, s15, s14
 *   @0x108320 mov r0, r5
 *   @0x108324 ldr r2, [r5, #0xb8]
 *   @0x108328 vadd.f32 s13, s16, s16
 *   @0x10832c vsub.f32 s13, s15, s13
 *   @0x108330 vmov r1, s13
 *   @0x108334 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x108338 b 0x108278 <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x10833c ldr r4, [r6, r3]
 *   @0x108340 vadd.f32 s14, s16, s16
 *   @0x108344 mov r0, r5
 *   @0x108348 ldr r2, [r5, #0xb8]
 *   @0x10834c ldr r3, [r4]
 *   @0x108350 vldr s13, [r3, #16]
 *   @0x108354 vcvt.f32.s32 s13, s13
 *   @0x108358 vadd.f32 s15, s15, s13
 *   @0x10835c vadd.f32 s14, s15, s14
 *   @0x108360 vmov r1, s14
 *   @0x108364 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x108368 vldr s15, [r5, #180]
 *   @0x10836c b 0x10825c <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x108370 andeq r0, r0, r0
 *   @0x108374 eoreq r9, lr, r8, asr #20
 *   @0x108378 .word 0xffffbcd8
 *
 * ══ §36/76 F_D3DBuildMatrixProjPerspFov(RValue&, CInstance*, CInstance*, int, RValue*)  0x146e18  size 400  100 条（0x146e18..0x146fa8）
 * @func 0x146e18 0x146fa8  size 400  100 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / yyMatrix::PerspectiveFovLH(yyMatrix*, float, float, float, float) / CreateArray(RValue*, int, ...) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x108×1 / 0x18×1
 * VFP 指令 62 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x146e18 push {r4, r5, r6, lr}
 *   @0x146e1c vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x146e20 sub sp, sp, #184
 *   @0x146e24 mov r1, #0
 *   @0x146e28 mov r5, r0
 *   @0x146e2c ldr r4, [sp, #0x108]
 *   @0x146e30 mov r0, r4
 *   @0x146e34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x146e38 mov r1, #1
 *   @0x146e3c vmov s17, r0
 *   @0x146e40 mov r0, r4
 *   @0x146e44 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x146e48 mov r1, #2
 *   @0x146e4c vmov s16, r0
 *   @0x146e50 mov r0, r4
 *   @0x146e54 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x146e58 mov r1, #3
 *   @0x146e5c mov r6, r0
 *   @0x146e60 mov r0, r4
 *   @0x146e64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x146e68 vcmp.f32 s16, #0
 *   @0x146e6c vmrs APSR_nzcv, fpscr
 *   @0x146e70 vcmp.f32 s17, #0
 *   @0x146e74 movne r2, #0
 *   @0x146e78 moveq r2, #1
 *   @0x146e7c vmrs APSR_nzcv, fpscr
 *   @0x146e80 orreq r2, r2, #1
 *   @0x146e84 cmp r2, #0
 *   @0x146e88 bne 0x146f84 <_Z28F_D3DBuildMatrixProjPerspFovR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x146e8c vldr s15, [pc, #268]
 *   @0x146e90 vmul.f32 s15, s17, s15
 *   @0x146e94 str r0, [sp]
 *   @0x146e98 mov r3, r6
 *   @0x146e9c add r0, sp, #120
 *   @0x146ea0 vmov r2, s16
 *   @0x146ea4 vmov r1, s15
 *   @0x146ea8 bl 0x27b068 <_ZN8yyMatrix16PerspectiveFovLHEPS_ffff>
 *   @0x146eac vldr s14, [sp, #180]
 *   @0x146eb0 vcvt.f64.f32 d7, s14
 *   @0x146eb4 vldr s28, [sp, #124]
 *   @0x146eb8 vldr s26, [sp, #128]
 *   @0x146ebc vldr s24, [sp, #132]
 *   @0x146ec0 vldr s22, [sp, #136]
 *   @0x146ec4 vldr s20, [sp, #140]
 *   @0x146ec8 vldr s18, [sp, #144]
 *   @0x146ecc vldr s16, [sp, #148]
 *   @0x146ed0 vldr s0, [sp, #152]
 *   @0x146ed4 vldr s2, [sp, #156]
 *   @0x146ed8 vldr s4, [sp, #160]
 *   @0x146edc vldr s6, [sp, #164]
 *   @0x146ee0 vldr s8, [sp, #168]
 *   @0x146ee4 vldr s10, [sp, #172]
 *   @0x146ee8 vldr s12, [sp, #176]
 *   @0x146eec vldr s30, [sp, #120]
 *   @0x146ef0 vcvt.f64.f32 d0, s0
 *   @0x146ef4 vstr d7, [sp, #112]
 *   @0x146ef8 mov r0, r5
 *   @0x146efc mov r1, #16
 *   @0x146f00 vcvt.f64.f32 d1, s2
 *   @0x146f04 vstr d0, [sp, #56]
 *   @0x146f08 vcvt.f64.f32 d2, s4
 *   @0x146f0c vstr d1, [sp, #64]
 *   @0x146f10 vcvt.f64.f32 d3, s6
 *   @0x146f14 vstr d2, [sp, #72]
 *   @0x146f18 vcvt.f64.f32 d4, s8
 *   @0x146f1c vstr d3, [sp, #80]
 *   @0x146f20 vcvt.f64.f32 d5, s10
 *   @0x146f24 vstr d4, [sp, #88]
 *   @0x146f28 vcvt.f64.f32 d6, s12
 *   @0x146f2c vstr d5, [sp, #96]
 *   @0x146f30 vcvt.f64.f32 d7, s30
 *   @0x146f34 vstr d6, [sp, #104]
 *   @0x146f38 vcvt.f64.f32 d14, s28
 *   @0x146f3c vmov r2, r3, d7
 *   @0x146f40 vcvt.f64.f32 d13, s26
 *   @0x146f44 vstr d14, [sp]
 *   @0x146f48 vcvt.f64.f32 d12, s24
 *   @0x146f4c vstr d13, [sp, #8]
 *   @0x146f50 vcvt.f64.f32 d11, s22
 *   @0x146f54 vstr d12, [sp, #16]
 *   @0x146f58 vcvt.f64.f32 d10, s20
 *   @0x146f5c vstr d11, [sp, #24]
 *   @0x146f60 vcvt.f64.f32 d9, s18
 *   @0x146f64 vstr d10, [sp, #32]
 *   @0x146f68 vcvt.f64.f32 d8, s16
 *   @0x146f6c vstr d9, [sp, #40]
 *   @0x146f70 vstr d8, [sp, #48]
 *   @0x146f74 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x146f78 add sp, sp, #184
 *   @0x146f7c vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x146f80 pop {r4, r5, r6, pc}
 *   @0x146f84 ldr r0, [pc, #0x18]
 *   @0x146f88 mov r1, #1
 *   @0x146f8c add r0, pc, r0
 *   @0x146f90 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x146f94 add sp, sp, #184
 *   @0x146f98 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x146f9c pop {r4, r5, r6, pc}
 *   @0x146fa0 vstmialo lr, {s30, s31}
 *   @0x146fa4 andseq r10, pc, r4, lsr #20
 *
 * ══ §37/76 GR_3D_Light_Define_Direction(int, float, float, float, unsigned int)  0x17f658  size 400  100 条（0x17f658..0x17f7e8）
 * @func 0x17f658 0x17f7e8  size 400  100 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17f670→0x3f26e0, 0x17f6d4→0x3f26dc, 0x17f704→0x4a2314, 0x17f708→0x4a22f4, 0x17f76c→0x4a2314, 0x17f774→0x4a22f4, 0x17f77c→0x4a22d4
 * 调用序列: 无
 * 字段偏移 top8: 0xd0×2 / 0x20×1 / 0x160×1 / 0x15c×1 / 0xfc×1 / 0x68×1 / 0x64×1 / 0x60×1
 * VFP 指令 30 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f658 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x17f65c vldr s15, [pc, #352]
 *   @0x17f660 and r0, r0, #7
 *   @0x17f664 ldr r4, [sp, #0x20]
 *   @0x17f668 ldr r12, [pc, #0x160]
 *   @0x17f66c ubfx r5, r4, #0x8, #0x8
 *   @0x17f670 ldr r6, [pc, #0x15c]
 *   @0x17f674 add r12, pc, r12
 *   @0x17f678 vmov s14, r5
 *   @0x17f67c uxtb r5, r4
 *   @0x17f680 ubfx r4, r4, #0x10, #0x8
 *   @0x17f684 vmov s12, r5
 *   @0x17f688 lsl r5, r0, #2
 *   @0x17f68c vcvt.f32.s32 s14, s14
 *   @0x17f690 add r7, r5, #1
 *   @0x17f694 vmov s13, r4
 *   @0x17f698 ldr r4, [r12, r6]
 *   @0x17f69c lsl r7, r7, #2
 *   @0x17f6a0 lsl r6, r0, #4
 *   @0x17f6a4 add r10, r4, r7
 *   @0x17f6a8 add r11, r4, r6
 *   @0x17f6ac add r9, r5, #2
 *   @0x17f6b0 add r8, r5, #3
 *   @0x17f6b4 lsl r9, r9, #2
 *   @0x17f6b8 lsl r8, r8, #2
 *   @0x17f6bc vcvt.f32.s32 s12, s12
 *   @0x17f6c0 vdiv.f32 s14, s14, s15
 *   @0x17f6c4 vdiv.f32 s12, s12, s15
 *   @0x17f6c8 vcvt.f32.s32 s13, s13
 *   @0x17f6cc vstr s12, [r11]
 *   @0x17f6d0 vstr s14, [r10]
 *   @0x17f6d4 ldr r11, [pc, #0xfc]
 *   @0x17f6d8 add r10, r4, r9
 *   @0x17f6dc add r4, r4, r8
 *   @0x17f6e0 vdiv.f32 s15, s13, s15
 *   @0x17f6e4 vmov.f32 s14, #1.000000e+00
 *   @0x17f6e8 vstr s15, [r10]
 *   @0x17f6ec vstr s14, [r4]
 *   @0x17f6f0 ldr r4, [r12, r11]
 *   @0x17f6f4 ldr r4, [r4]
 *   @0x17f6f8 cmp r4, #0
 *   @0x17f6fc bne 0x17f764 <_Z28GR_3D_Light_Define_Directionifffj+0x10c>
 *   @0x17f700 vmov s12, r1
 *   @0x17f704 ldr r10, [pc, #0xd0]
 *   @0x17f708 ldr r4, [pc, #0xd0]
 *   @0x17f70c vldr s13, [pc, #180]
 *   @0x17f710 vneg.f32 s15, s12
 *   @0x17f714 mov r11, #9216
 *   @0x17f718 vmov s12, r2
 *   @0x17f71c ldr r1, [r12, r10]
 *   @0x17f720 movt r11, #0x4974
 *   @0x17f724 add r6, r1, r6
 *   @0x17f728 add r7, r1, r7
 *   @0x17f72c vneg.f32 s14, s12
 *   @0x17f730 vstr s15, [r6]
 *   @0x17f734 vmov s12, r3
 *   @0x17f738 add r9, r1, r9
 *   @0x17f73c add r8, r1, r8
 *   @0x17f740 vneg.f32 s15, s12
 *   @0x17f744 vstr s14, [r7]
 *   @0x17f748 vstr s15, [r9]
 *   @0x17f74c vstr s13, [r8]
 *   @0x17f750 ldr r3, [r12, r4]
 *   @0x17f754 add r5, r3, r5
 *   @0x17f758 str r11, [r5]
 *   @0x17f75c pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x17f760 b 0x17f4c4 <_Z18GR_3D_Light_Updatei>
 *   @0x17f764 cmp r4, #1
 *   @0x17f768 bne 0x17f75c <_Z28GR_3D_Light_Define_Directionifffj+0x104>
 *   @0x17f76c ldr r4, [pc, #0x68]
 *   @0x17f770 vldr s14, [pc, #80]
 *   @0x17f774 ldr r11, [pc, #0x64]
 *   @0x17f778 vldr s15, [pc, #76]
 *   @0x17f77c ldr r10, [pc, #0x60]
 *   @0x17f780 ldr r4, [r12, r4]
 *   @0x17f784 add r6, r4, r6
 *   @0x17f788 add r7, r4, r7
 *   @0x17f78c add r9, r4, r9
 *   @0x17f790 add r8, r4, r8
 *   @0x17f794 str r1, [r6]
 *   @0x17f798 str r2, [r7]
 *   @0x17f79c mov r2, #0
 *   @0x17f7a0 str r3, [r9]
 *   @0x17f7a4 vstr s14, [r8]
 *   @0x17f7a8 ldr r3, [r12, r11]
 *   @0x17f7ac add r5, r3, r5
 *   @0x17f7b0 vstr s15, [r5]
 *   @0x17f7b4 ldr r3, [r12, r10]
 *   @0x17f7b8 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x17f7bc str r2, [r3, r0, lsl #2]
 *   @0x17f7c0 b 0x17f4c4 <_Z18GR_3D_Light_Updatei>
 *   @0x17f7c4 cmnmi pc, #0
 *   @0x17f7c8 andeq r0, r0, r0
 *   @0x17f7cc ldmdbmi r4!, {r10, sp} ^
 *   @0x17f7d0 .word 0x002725dc
 *   @0x17f7d4 .word 0xffffe850
 *   @0x17f7d8 .word 0xffffe7b8
 *   @0x17f7dc .word 0xffffe854
 *   @0x17f7e0 .word 0xffffe84c
 *   @0x17f7e4 .word 0xffffe858
 *
 * ══ §38/76 CSprite::SetupGradientTexture(SWF_GradientFillStyleData*)  0x1e7c8c  size 400  100 条（0x1e7c8c..0x1e7e1c）
 * @func 0x1e7c8c 0x1e7e1c  size 400  100 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / CSprite::SampleGradient(SWF_GradientFillStyleData*, int)×2 / GR_Texture_Create_And_Fill(int, int, unsigned char*, unsigned int) / GR_Texture_Exists(int) / 0xb6700
 * 字段偏移 top8: 0x4×4 / 0x54×2 / 0x14c×1 / 0xec×1 / 0x2×1 / 0xc0×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e7c8c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1e7c90 vpush {d8, d9}
 *   @0x1e7c94 subs r6, r1, #0
 *   @0x1e7c98 mov r7, r0
 *   @0x1e7c9c beq 0x1e7cb4 <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x28>
 *   @0x1e7ca0 ldr r4, [r6, #0x4]
 *   @0x1e7ca4 cmp r4, #0
 *   @0x1e7ca8 beq 0x1e7cbc <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x30>
 *   @0x1e7cac cmp r4, #1
 *   @0x1e7cb0 beq 0x1e7d50 <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0xc4>
 *   @0x1e7cb4 vpop {d8, d9}
 *   @0x1e7cb8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1e7cbc ldr r1, [pc, #0x14c]
 *   @0x1e7cc0 mov r0, #1024
 *   @0x1e7cc4 movw r2, #0xe7b
 *   @0x1e7cc8 mov r3, #1
 *   @0x1e7ccc add r1, pc, r1
 *   @0x1e7cd0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1e7cd4 sub r5, r0, #4
 *   @0x1e7cd8 mov r9, r0
 *   @0x1e7cdc mov r2, r4
 *   @0x1e7ce0 mov r0, r7
 *   @0x1e7ce4 mov r1, r6
 *   @0x1e7ce8 add r4, r4, #1
 *   @0x1e7cec bl 0x1e7b44 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai>
 *   @0x1e7cf0 cmp r4, #256
 *   @0x1e7cf4 str r0, [r5, #0x4]!
 *   @0x1e7cf8 bne 0x1e7cdc <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x50>
 *   @0x1e7cfc mov r0, r4
 *   @0x1e7d00 mov r3, #1024
 *   @0x1e7d04 mov r1, #1
 *   @0x1e7d08 mov r2, r9
 *   @0x1e7d0c bl 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj>
 *   @0x1e7d10 str r0, [r6, #0x54]
 *   @0x1e7d14 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x1e7d18 cmp r0, #0
 *   @0x1e7d1c beq 0x1e7d40 <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0xb4>
 *   @0x1e7d20 ldr r3, [pc, #0xec]
 *   @0x1e7d24 ldr r2, [r6, #0x54]
 *   @0x1e7d28 ldr r3, [pc, r3]
 *   @0x1e7d2c ldr r3, [r3, #0x4]
 *   @0x1e7d30 ldr r3, [r3, r2, lsl #2]
 *   @0x1e7d34 cmp r3, #0
 *   @0x1e7d38 ldrne r3, [r3]
 *   @0x1e7d3c strne r3, [r6, #0x58]
 *   @0x1e7d40 vpop {d8, d9}
 *   @0x1e7d44 mov r0, r9
 *   @0x1e7d48 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1e7d4c b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e7d50 ldr r1, [pc, #0xc0]
 *   @0x1e7d54 mov r3, r4
 *   @0x1e7d58 mov r0, #16384
 *   @0x1e7d5c movw r2, #0xe86
 *   @0x1e7d60 add r1, pc, r1
 *   @0x1e7d64 vmov.f32 s18, #3.100000e+01
 *   @0x1e7d68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1e7d6c mvn r8, #30
 *   @0x1e7d70 vldr s17, [pc, #148]
 *   @0x1e7d74 sub r10, r0, #4
 *   @0x1e7d78 mov r9, r0
 *   @0x1e7d7c vmov s15, r8
 *   @0x1e7d80 mov r5, r10
 *   @0x1e7d84 mvn r4, #30
 *   @0x1e7d88 vcvt.f32.s32 s16, s15
 *   @0x1e7d8c vmul.f32 s16, s16, s16
 *   @0x1e7d90 vmov s14, r4
 *   @0x1e7d94 add r4, r4, #1
 *   @0x1e7d98 vcvt.f32.s32 s15, s14
 *   @0x1e7d9c vmov.f32 s14, s16
 *   @0x1e7da0 vmla.f32 s14, s15, s15
 *   @0x1e7da4 vsqrt.f32 s15, s14
 *   @0x1e7da8 vcmp.f32 s15, s15
 *   @0x1e7dac vmrs APSR_nzcv, fpscr
 *   @0x1e7db0 bne 0x1e7dfc <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x170>
 *   @0x1e7db4 vdiv.f32 s15, s15, s18
 *   @0x1e7db8 mov r0, r7
 *   @0x1e7dbc mov r1, r6
 *   @0x1e7dc0 vmul.f32 s15, s15, s17
 *   @0x1e7dc4 vcvt.s32.f32 s15, s15
 *   @0x1e7dc8 vmov r2, s15
 *   @0x1e7dcc bl 0x1e7b44 <_ZN7CSprite14SampleGradientEP25SWF_GradientFillStyleDatai>
 *   @0x1e7dd0 cmp r4, #33
 *   @0x1e7dd4 str r0, [r5, #0x4]!
 *   @0x1e7dd8 bne 0x1e7d90 <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x104>
 *   @0x1e7ddc add r8, r8, #1
 *   @0x1e7de0 add r10, r10, #256
 *   @0x1e7de4 cmp r8, #33
 *   @0x1e7de8 bne 0x1e7d7c <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0xf0>
 *   @0x1e7dec mov r1, #64
 *   @0x1e7df0 mov r3, #16384
 *   @0x1e7df4 mov r0, r1
 *   @0x1e7df8 b 0x1e7d08 <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x7c>
 *   @0x1e7dfc vmov r0, s14
 *   @0x1e7e00 bl 0xb6700 <sqrtf@plt>
 *   @0x1e7e04 vmov s15, r0
 *   @0x1e7e08 b 0x1e7db4 <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData+0x128>
 *   @0x1e7e0c cmnmi pc, #0
 *   @0x1e7e10 andseq r10, r6, r8, asr r7
 *   @0x1e7e14 .word 0x00205bf4
 *   @0x1e7e18 andseq r10, r6, r4, asr #13
 *
 * ══ §39/76 deviceListAdd(char const*)  0x21c2e0  size 400  100 条（0x21c2e0..0x21c470）
 * @func 0x21c2e0 0x21c470  size 400  100 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / operator new(unsigned int) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / deviceListAdd(char const*)+0xfc / operator delete(void*) / deviceListAdd(char const*)+0x7c / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×6 / 0xc×3 / 0x2×2 / 0x8×2 / 0x154×1 / 0x138×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21c2e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21c2e4 mov r7, r0
 *   @0x21c2e8 sub sp, sp, #20
 *   @0x21c2ec mov r0, #4
 *   @0x21c2f0 bl 0x27c524 <_Znwj>
 *   @0x21c2f4 mov r4, #0
 *   @0x21c2f8 mov r6, r0
 *   @0x21c2fc mov r0, r7
 *   @0x21c300 str r4, [r6]
 *   @0x21c304 bl 0xb6538 <strlen@plt>
 *   @0x21c308 ldr r1, [pc, #0x154]
 *   @0x21c30c mov r3, #1
 *   @0x21c310 movw r2, #0xd07
 *   @0x21c314 add r1, pc, r1
 *   @0x21c318 add r0, r0, r3
 *   @0x21c31c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x21c320 subs r8, r0, #0
 *   @0x21c324 beq 0x21c3f0 <_Z13deviceListAddPKc+0x110>
 *   @0x21c328 ldr r5, [pc, #0x138]
 *   @0x21c32c ldr r5, [pc, r5]
 *   @0x21c330 ldr r9, [r5]
 *   @0x21c334 adds r2, r9, #1
 *   @0x21c338 str r2, [sp, #0xc]
 *   @0x21c33c bne 0x21c414 <_Z13deviceListAddPKc+0x134>
 *   @0x21c340 ldr r0, [r5, #0x4]
 *   @0x21c344 cmp r0, r4
 *   @0x21c348 beq 0x21c3dc <_Z13deviceListAddPKc+0xfc>
 *   @0x21c34c cmp r9, r4
 *   @0x21c350 ble 0x21c3dc <_Z13deviceListAddPKc+0xfc>
 *   @0x21c354 mov r4, r2
 *   @0x21c358 mov r10, r2
 *   @0x21c35c ldr r3, [r0]
 *   @0x21c360 movw r2, #0xfeee
 *   @0x21c364 movt r2, #0xfeee
 *   @0x21c368 movw r1, #0xfeee
 *   @0x21c36c cmp r3, r2
 *   @0x21c370 movt r1, #0xfeee
 *   @0x21c374 lsl r11, r4, #2
 *   @0x21c378 beq 0x21c3cc <_Z13deviceListAddPKc+0xec>
 *   @0x21c37c ldr r2, [r0, r4, lsl #2]
 *   @0x21c380 add lr, r0, r11
 *   @0x21c384 cmp r2, #0
 *   @0x21c388 beq 0x21c3cc <_Z13deviceListAddPKc+0xec>
 *   @0x21c38c ldr r3, [r2]
 *   @0x21c390 cmp r3, r1
 *   @0x21c394 mov r0, r3
 *   @0x21c398 beq 0x21c3c4 <_Z13deviceListAddPKc+0xe4>
 *   @0x21c39c cmp r3, #0
 *   @0x21c3a0 beq 0x21c3b4 <_Z13deviceListAddPKc+0xd4>
 *   @0x21c3a4 str r2, [sp, #0x8]
 *   @0x21c3a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21c3ac ldr r2, [sp, #0x8]
 *   @0x21c3b0 str r10, [r2]
 *   @0x21c3b4 mov r0, r2
 *   @0x21c3b8 bl 0x27d1d0 <_ZdlPv>
 *   @0x21c3bc ldr lr, [r5, #0x4]
 *   @0x21c3c0 add lr, lr, r11
 *   @0x21c3c4 str r10, [lr]
 *   @0x21c3c8 ldr r0, [r5, #0x4]
 *   @0x21c3cc ldr r2, [r5]
 *   @0x21c3d0 add r4, r4, #1
 *   @0x21c3d4 cmp r4, r2
 *   @0x21c3d8 blt 0x21c35c <_Z13deviceListAddPKc+0x7c>
 *   @0x21c3dc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21c3e0 mov r2, #0
 *   @0x21c3e4 mov r3, r2
 *   @0x21c3e8 str r2, [r5, #0x4]
 *   @0x21c3ec b 0x21c440 <_Z13deviceListAddPKc+0x160>
 *   @0x21c3f0 ldr r0, [r6]
 *   @0x21c3f4 cmp r0, #0
 *   @0x21c3f8 beq 0x21c404 <_Z13deviceListAddPKc+0x124>
 *   @0x21c3fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21c400 str r8, [r6]
 *   @0x21c404 mov r0, r6
 *   @0x21c408 add sp, sp, #20
 *   @0x21c40c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21c410 b 0x27d1d0 <_ZdlPv>
 *   @0x21c414 ldr r3, [sp, #0xc]
 *   @0x21c418 ldr r0, [r5, #0x4]
 *   @0x21c41c lsls r1, r3, #2
 *   @0x21c420 beq 0x21c3dc <_Z13deviceListAddPKc+0xfc>
 *   @0x21c424 ldr r2, [pc, #0x40]
 *   @0x21c428 mov r3, #135
 *   @0x21c42c str r4, [sp]
 *   @0x21c430 add r2, pc, r2
 *   @0x21c434 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x21c438 mov r3, r0
 *   @0x21c43c str r0, [r5, #0x4]
 *   @0x21c440 ldr r2, [sp, #0xc]
 *   @0x21c444 mov r1, r7
 *   @0x21c448 mov r0, r8
 *   @0x21c44c str r2, [r5]
 *   @0x21c450 str r6, [r3, r9, lsl #2]
 *   @0x21c454 bl 0xb65a4 <strcpy@plt>
 *   @0x21c458 str r8, [r6]
 *   @0x21c45c add sp, sp, #20
 *   @0x21c460 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21c464 andseq r7, r3, r4, lsl #21
 *   @0x21c468 andseq r5, sp, r12, asr #1
 *   @0x21c46c andseq r0, r3, r0, asr #29
 *
 * ══ §40/76 png_write_finish_row  0x2b260c  size 400  100 条（0x2b260c..0x2b279c）
 * @func 0x2b260c 0x2b27b0  size 420  105 条
 * 部分覆盖: 本节 105/180 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 104/179 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 103/177 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 102/175 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 101/173 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __udivsi3×2 / png_write_finish_row+0x184 / anon_2f929c+0x558 / png_write_finish_row+0x84 / png_write_IDAT
 * 字段偏移 top8: 0x180×1 / 0x-1c×1 / 0x2×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b260c push {r4, r5, r6, r7, lr}
 *   @0x2b2610 ldr r6, [pc, #0x180]
 *   @0x2b2614 add r6, pc
 *   @0x2b2618 add.w r7, r6, #0x74
 *   @0x2b261c ldm r7!, {r0, r1, r2, r3}
 *   @0x2b2620 ldm.w r7, {r0, r1, r2}
 *   @0x2b2624 add.w r7, r6, #0x90
 *   @0x2b2628 stm.w r5, {r0, r1, r2}
 *   @0x2b262c add r5, sp, #0x1c
 *   @0x2b2630 stm r5!, {r0, r1, r2, r3}
 *   @0x2b2634 .word 0xf1060007
 *   @0x2b2638 strblo r0, [r8], r12, lsr #15
 *   @0x2b263c stm.w r5, {r0, r1, r2}
 *   @0x2b2640 add r5, sp, #0x38
 *   @0x2b2644 stm r5!, {r0, r1, r2, r3}
 *   @0x2b2648 stm r5, {r0, r1, r2}
 *   @0x2b264c ldcge p0, c0, [r5, #-28]
 *   @0x2b2650 ldm r6!, {r0, r1, r2, r3}
 *   @0x2b2654 ldm.w r6, {r0, r1, r2}
 *   @0x2b2658 ldr.w r3, [r4, #0x1a8]
 *   @0x2b265c adds r3, #0x1
 *   @0x2b2660 stm r5, {r3, r5, r7, r8, r12, sp}
 *   @0x2b2664 .word 0xf8d40007
 *   @0x2b2668 addsmi r2, r3, #148, #2
 *   @0x2b266c blo.w 0x2b2790 <png_write_finish_row+0x184>
 *   @0x2b2670 ldrb.w r3, [r4, #0x1e7]
 *   @0x2b2674 cmp r3, #0x0
 *   @0x2b2678 movs r3, #0x0
 *   @0x2b267c .word 0xf8d431a8
 *   @0x2b2680 .word 0xf8943134
 *   @0x2b2684 .word 0xf01351e8
 *   @0x2b2688 eorle r0, r0, r2, lsl #30
 *   @0x2b268c adds r5, #0x1
 *   @0x2b2690 add r3, sp, #0x70
 *   @0x2b2694 .word 0xf8d40685
 *   @0x2b2698 .word 0xf856318c
 *   @0x2b269c bllo 0x2f97f4 <ps_hints_apply+0x83f4>
 *   @0x2b26a0 adds r0, r3, r1
 *   @0x2b26a4 bne 0xff2c186c <b2_toiTime+0xfffffffffeb683c8>
 *   @0x2b26a8 blx 0x318c48 <__udivsi3>
 *   @0x2b26ac ldr.w r3, [r4, #0x190]
 *   @0x2b26b0 ldr r1, [r6, #-28]
 *   @0x2b26b4 subs r3, #0x1
 *   @0x2b26b8 .word 0xf8c42c38
 *   @0x2b26bc .word 0x46070198
 *   @0x2b26c0 adds r0, r3, r1
 *   @0x2b26c4 blx 0x318c48 <__udivsi3>
 *   @0x2b26c8 str.w r0, [r4, #0x194]
 *   @0x2b26cc cbnz r7, 0x2b26d8 <png_write_finish_row+0xcc>
 *   @0x2b26d0 uxtb r5, r5
 *   @0x2b26d4 bls 0x2b2690 <png_write_finish_row+0x84>
 *   @0x2b26d8 cmp r0, #0x0
 *   @0x2b26dc strb.w r5, [r4, #0x1e8]
 *   @0x2b26e0 ldrb.w r3, [r4, #0x1e8]
 *   @0x2b26e4 cmp r3, #0x6
 *   @0x2b26e8 ldr.w r0, [r4, #0x1ac]
 *   @0x2b26ec cmp r0, #0x0
 *   @0x2b26f0 ldrb.w r2, [r4, #0x1ef]
 *   @0x2b26f4 ldrb.w r3, [r4, #0x1ec]
 *   @0x2b26f8 smulbb r3, r2, r3
 *   @0x2b26fc ldr.w r2, [r4, #0x18c]
 *   @0x2b2700 cmp r3, #0x7
 *   @0x2b2704 lsrs r3, r3, #0x3
 *   @0x2b2708 b 0x2b2710 <png_write_finish_row+0x104>
 *   @0x2b270c adds r2, #0x7
 *   @0x2b2710 adds r2, #0x1
 *   @0x2b2714 add sp, #0x74
 *   @0x2b2718 .word 0xf06940f0
 *   @0x2b271c mrcmi p9, #0x0, r11, c14, c7, #0x6
 *   @0x2b2720 add.w r5, r4, #0x138
 *   @0x2b2724 add r6, pc
 *   @0x2b2728 movs r1, #0x4
 *   @0x2b272c ldmiblt r8, {r6, r8, r11, sp, lr, pc}
 *   @0x2b2730 ldr.w r3, [r4, #0x148]
 *   @0x2b2734 cmp r3, #0x0
 *   @0x2b2738 mov r0, r4
 *   @0x2b273c .word 0xf8d41170
 *   @0x2b2740 .word 0xf7fe2174
 *   @0x2b2744 .word 0xf8d4ffad
 *   @0x2b2748 .word 0xf8c43170
 *   @0x2b274c .word 0xf8d43144
 *   @0x2b2750 .word 0xf8c43174
 *   @0x2b2754 strb r3, [r6, r8, asr #2]!
 *   @0x2b2758 cmp r0, #0x1
 *   @0x2b275c ldr.w r1, [r4, #0x150]
 *   @0x2b2760 mov r0, r4
 *   @0x2b2764 mov r1, r6
 *   @0x2b2768 ldrb pc, [r12, r1, ror #28]
 *   @0x2b276c ldr.w r3, [r4, #0x148]
 *   @0x2b2770 ldr.w r2, [r4, #0x174]
 *   @0x2b2774 cmp r3, r2
 *   @0x2b2778 mov r0, r4
 *   @0x2b277c bne 0xff736d44 <b2_toiTime+0xfffffffffefdd8a0>
 *   @0x2b2780 bl 0x2b16a0 <png_write_IDAT>
 *   @0x2b2784 mov r0, r5
 *   @0x2b2788 movwhs lr, #0xbe8
 *   @0x2b278c str.w r3, [r4, #0x164]
 *   @0x2b2790 add sp, #0x74
 *   @0x2b2794 bvc 0x2b2830 <png_do_write_interlace+0x94>
 *   @0x2b2798 .word 0xb859
 *
 * ══ §41/76 __aeabi_fadd  0x3191d0  size 400  100 条（0x3191d0..0x319360）
 * @func 0x3191d0 0x319360  size 400  100 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_fadd+0xbc / __aeabi_fadd+0xa8
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3191d0 lsls r2, r0, #1
 *   @0x3191d4 lslsne r3, r1, #1
 *   @0x3191d8 teqne r2, r3
 *   @0x3191dc mvnsne r12, r2, asr #24
 *   @0x3191e0 mvnsne r12, r3, asr #24
 *   @0x3191e4 beq 0x3192dc <__aeabi_fadd+0x10c>
 *   @0x3191e8 lsr r2, r2, #24
 *   @0x3191ec rsbs r3, r2, r3, lsr #24
 *   @0x3191f0 addgt r2, r2, r3
 *   @0x3191f4 eorgt r1, r0, r1
 *   @0x3191f8 eorgt r0, r1, r0
 *   @0x3191fc eorgt r1, r0, r1
 *   @0x319200 rsblt r3, r3, #0
 *   @0x319204 cmp r3, #25
 *   @0x319208 bxhi lr
 *   @0x31920c tst r0, #-2147483648
 *   @0x319210 orr r0, r0, #8388608
 *   @0x319214 bic r0, r0, #-16777216
 *   @0x319218 rsbne r0, r0, #0
 *   @0x31921c tst r1, #-2147483648
 *   @0x319220 orr r1, r1, #8388608
 *   @0x319224 bic r1, r1, #-16777216
 *   @0x319228 rsbne r1, r1, #0
 *   @0x31922c teq r2, r3
 *   @0x319230 beq 0x3192c4 <__aeabi_fadd+0xf4>
 *   @0x319234 sub r2, r2, #1
 *   @0x319238 adds r0, r0, r1, asr r3
 *   @0x31923c rsb r3, r3, #32
 *   @0x319240 lsl r1, r1, r3
 *   @0x319244 and r3, r0, #-2147483648
 *   @0x319248 bpl 0x319254 <__aeabi_fadd+0x84>
 *   @0x31924c rsbs r1, r1, #0
 *   @0x319250 rsc r0, r0, #0
 *   @0x319254 cmp r0, #8388608
 *   @0x319258 blo 0x31928c <__aeabi_fadd+0xbc>
 *   @0x31925c cmp r0, #16777216
 *   @0x319260 blo 0x319278 <__aeabi_fadd+0xa8>
 *   @0x319264 lsrs r0, r0, #1
 *   @0x319268 rrx r1, r1
 *   @0x31926c add r2, r2, #1
 *   @0x319270 cmp r2, #254
 *   @0x319274 bhs 0x319330 <__aeabi_fadd+0x160>
 *   @0x319278 cmp r1, #-2147483648
 *   @0x31927c adc r0, r0, r2, lsl #23
 *   @0x319280 biceq r0, r0, #1
 *   @0x319284 orr r0, r0, r3
 *   @0x319288 bx lr
 *   @0x31928c lsls r1, r1, #1
 *   @0x319290 adc r0, r0, r0
 *   @0x319294 tst r0, #8388608
 *   @0x319298 sub r2, r2, #1
 *   @0x31929c bne 0x319278 <__aeabi_fadd+0xa8>
 *   @0x3192a0 clz r12, r0
 *   @0x3192a4 sub r12, r12, #8
 *   @0x3192a8 subs r2, r2, r12
 *   @0x3192ac lsl r0, r0, r12
 *   @0x3192b0 addge r0, r0, r2, lsl #23
 *   @0x3192b4 rsblt r2, r2, #0
 *   @0x3192b8 orrge r0, r0, r3
 *   @0x3192bc orrlt r0, r3, r0, lsr r2
 *   @0x3192c0 bx lr
 *   @0x3192c4 teq r2, #0
 *   @0x3192c8 eor r1, r1, #8388608
 *   @0x3192cc eoreq r0, r0, #8388608
 *   @0x3192d0 addeq r2, r2, #1
 *   @0x3192d4 subne r3, r3, #1
 *   @0x3192d8 b 0x319234 <__aeabi_fadd+0x64>
 *   @0x3192dc lsl r3, r1, #1
 *   @0x3192e0 mvns r12, r2, asr #24
 *   @0x3192e4 mvnsne r12, r3, asr #24
 *   @0x3192e8 beq 0x31933c <__aeabi_fadd+0x16c>
 *   @0x3192ec teq r2, r3
 *   @0x3192f0 beq 0x319300 <__aeabi_fadd+0x130>
 *   @0x3192f4 teq r2, #0
 *   @0x3192f8 moveq r0, r1
 *   @0x3192fc bx lr
 *   @0x319300 teq r0, r1
 *   @0x319304 movne r0, #0
 *   @0x319308 bxne lr
 *   @0x31930c tst r2, #-16777216
 *   @0x319310 bne 0x319320 <__aeabi_fadd+0x150>
 *   @0x319314 lsls r0, r0, #1
 *   @0x319318 orrhs r0, r0, #-2147483648
 *   @0x31931c bx lr
 *   @0x319320 adds r2, r2, #33554432
 *   @0x319324 addlo r0, r0, #8388608
 *   @0x319328 bxlo lr
 *   @0x31932c and r3, r0, #-2147483648
 *   @0x319330 orr r0, r3, #2130706432
 *   @0x319334 orr r0, r0, #8388608
 *   @0x319338 bx lr
 *   @0x31933c mvns r2, r2, asr #24
 *   @0x319340 movne r0, r1
 *   @0x319344 mvnseq r3, r3, asr #24
 *   @0x319348 movne r1, r0
 *   @0x31934c lsls r2, r0, #9
 *   @0x319350 lslseq r3, r1, #9
 *   @0x319354 teqeq r0, r1
 *   @0x319358 orrne r0, r0, #4194304
 *   @0x31935c bx lr
 *
 * ══ §42/76 CompareFileNames(char const*, char const*)  0x16068c  size 396  99 条（0x16068c..0x160818）
 * @func 0x16068c 0x160818  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×2
 * 字段偏移 top8: 0x1×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16068c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x160690 mov r9, r1
 *   @0x160694 mov r10, r0
 *   @0x160698 bl 0xb6538 <strlen@plt>
 *   @0x16069c mvn r6, #0
 *   @0x1606a0 mov r7, r0
 *   @0x1606a4 mov r0, r9
 *   @0x1606a8 bl 0xb6538 <strlen@plt>
 *   @0x1606ac mov r12, #0
 *   @0x1606b0 mov r4, r12
 *   @0x1606b4 mov r8, r0
 *   @0x1606b8 subs r0, r12, r8
 *   @0x1606bc rsbs r3, r0, #0
 *   @0x1606c0 adcs r3, r3, r0
 *   @0x1606c4 subs r1, r4, r7
 *   @0x1606c8 rsbs r2, r1, #0
 *   @0x1606cc adcs r2, r2, r1
 *   @0x1606d0 ands r0, r2, r3
 *   @0x1606d4 popne {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1606d8 cmp r7, r4
 *   @0x1606dc moveq r5, #0
 *   @0x1606e0 andne r5, r3, #1
 *   @0x1606e4 cmp r5, #0
 *   @0x1606e8 beq 0x160704 <_Z16CompareFileNamesPKcS0_+0x78>
 *   @0x1606ec cmn r6, #1
 *   @0x1606f0 beq 0x1607b0 <_Z16CompareFileNamesPKcS0_+0x124>
 *   @0x1606f4 subs r1, r6, r8
 *   @0x1606f8 mov r12, r6
 *   @0x1606fc rsbs r3, r1, #0
 *   @0x160700 adcs r3, r3, r1
 *   @0x160704 orrs r3, r3, r2
 *   @0x160708 bne 0x1607b0 <_Z16CompareFileNamesPKcS0_+0x124>
 *   @0x16070c ldrb r5, [r9, r12]
 *   @0x160710 cmp r5, #42
 *   @0x160714 beq 0x160754 <_Z16CompareFileNamesPKcS0_+0xc8>
 *   @0x160718 cmp r5, #63
 *   @0x16071c bne 0x160738 <_Z16CompareFileNamesPKcS0_+0xac>
 *   @0x160720 ldrb r2, [r10, r4]
 *   @0x160724 cmp r2, #46
 *   @0x160728 beq 0x16079c <_Z16CompareFileNamesPKcS0_+0x110>
 *   @0x16072c add r12, r12, #1
 *   @0x160730 add r4, r4, #1
 *   @0x160734 b 0x1606b8 <_Z16CompareFileNamesPKcS0_+0x2c>
 *   @0x160738 ldrb r2, [r10, r4]
 *   @0x16073c cmp r2, r5
 *   @0x160740 beq 0x16072c <_Z16CompareFileNamesPKcS0_+0xa0>
 *   @0x160744 cmn r6, #1
 *   @0x160748 beq 0x160808 <_Z16CompareFileNamesPKcS0_+0x17c>
 *   @0x16074c mov r12, r6
 *   @0x160750 b 0x1606b8 <_Z16CompareFileNamesPKcS0_+0x2c>
 *   @0x160754 add r1, r12, #1
 *   @0x160758 cmp r1, r8
 *   @0x16075c beq 0x160810 <_Z16CompareFileNamesPKcS0_+0x184>
 *   @0x160760 add r3, r9, r12
 *   @0x160764 ldrb r2, [r10, r4]
 *   @0x160768 ldrb r3, [r3, #0x1]
 *   @0x16076c cmp r3, r2
 *   @0x160770 beq 0x160790 <_Z16CompareFileNamesPKcS0_+0x104>
 *   @0x160774 cmp r3, #63
 *   @0x160778 beq 0x160788 <_Z16CompareFileNamesPKcS0_+0xfc>
 *   @0x16077c add r4, r4, #1
 *   @0x160780 mov r6, r12
 *   @0x160784 b 0x1606b8 <_Z16CompareFileNamesPKcS0_+0x2c>
 *   @0x160788 cmp r2, #46
 *   @0x16078c beq 0x16077c <_Z16CompareFileNamesPKcS0_+0xf0>
 *   @0x160790 mov r6, r12
 *   @0x160794 mov r12, r1
 *   @0x160798 b 0x1606b8 <_Z16CompareFileNamesPKcS0_+0x2c>
 *   @0x16079c cmn r6, #1
 *   @0x1607a0 beq 0x160808 <_Z16CompareFileNamesPKcS0_+0x17c>
 *   @0x1607a4 add r4, r4, #1
 *   @0x1607a8 mov r12, r6
 *   @0x1607ac b 0x1606b8 <_Z16CompareFileNamesPKcS0_+0x2c>
 *   @0x1607b0 cmp r4, r7
 *   @0x1607b4 popne {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1607b8 cmp r12, r8
 *   @0x1607bc beq 0x160810 <_Z16CompareFileNamesPKcS0_+0x184>
 *   @0x1607c0 ldrb r0, [r9, r12]
 *   @0x1607c4 add r9, r9, r12
 *   @0x1607c8 cmp r0, #42
 *   @0x1607cc cmpne r0, #63
 *   @0x1607d0 movne r0, #0
 *   @0x1607d4 moveq r0, #1
 *   @0x1607d8 beq 0x1607f8 <_Z16CompareFileNamesPKcS0_+0x16c>
 *   @0x1607dc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1607e0 ldrb r3, [r9, #0x1]!
 *   @0x1607e4 cmp r3, #42
 *   @0x1607e8 cmpne r3, #63
 *   @0x1607ec movne r3, #0
 *   @0x1607f0 moveq r3, #1
 *   @0x1607f4 bne 0x160808 <_Z16CompareFileNamesPKcS0_+0x17c>
 *   @0x1607f8 add r12, r12, #1
 *   @0x1607fc cmp r8, r12
 *   @0x160800 bne 0x1607e0 <_Z16CompareFileNamesPKcS0_+0x154>
 *   @0x160804 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x160808 mov r0, r3
 *   @0x16080c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x160810 mov r0, #1
 *   @0x160814 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §43/76 ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)  0x1a3f48  size 396  99 条（0x1a3f48..0x1a40d4）
 * @func 0x1a3f48 0x1a40d4  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a3f88→0x542460, 0x1a4084→0x3eb70c, 0x1a40ac→0x3eb70c
 * 调用序列: ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)+0x158×2 / ParticleSystem_Exists(int) / ParticleType_Exists(int) / MemoryManager::Free(void const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CreateParticle(float, float, int, RParticle&) / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×4 / 0x2×4 / 0x8×4 / 0x40×2 / 0x34×1 / 0x148×1 / 0x12c×1 / 0x118×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3f48 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a3f4c sub sp, sp, #12
 *   @0x1a3f50 mov r8, r1
 *   @0x1a3f54 mov r6, r3
 *   @0x1a3f58 mov r9, r2
 *   @0x1a3f5c mov r5, r0
 *   @0x1a3f60 ldr r7, [sp, #0x34]
 *   @0x1a3f64 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a3f68 ldr r4, [pc, #0x148]
 *   @0x1a3f6c add r4, pc, r4
 *   @0x1a3f70 cmp r0, #0
 *   @0x1a3f74 beq 0x1a4080 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x138>
 *   @0x1a3f78 mov r0, r6
 *   @0x1a3f7c bl 0x1a2e14 <_Z19ParticleType_Existsi>
 *   @0x1a3f80 cmp r0, #0
 *   @0x1a3f84 beq 0x1a40a8 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x160>
 *   @0x1a3f88 ldr r3, [pc, #0x12c]
 *   @0x1a3f8c cmp r7, #0
 *   @0x1a3f90 ldr r3, [r4, r3]
 *   @0x1a3f94 ldr r3, [r3, #0x4]
 *   @0x1a3f98 ldr r4, [r3, r5, lsl #2]
 *   @0x1a3f9c ble 0x1a40a0 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x158>
 *   @0x1a3fa0 ldr r2, [pc, #0x118]
 *   @0x1a3fa4 add r1, r4, #4
 *   @0x1a3fa8 ldr r11, [pc, #0x114]
 *   @0x1a3fac mov r5, #1
 *   @0x1a3fb0 add r2, pc, r2
 *   @0x1a3fb4 ldr r3, [r4, #0x8]
 *   @0x1a3fb8 str r1, [sp]
 *   @0x1a3fbc add r11, pc, r11
 *   @0x1a3fc0 str r2, [sp, #0x4]
 *   @0x1a3fc4 b 0x1a404c <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x104>
 *   @0x1a3fc8 ldr r2, [r4, #0x4]
 *   @0x1a3fcc add r1, r3, #1073741824
 *   @0x1a3fd0 add r3, r3, #1
 *   @0x1a3fd4 str r3, [r4, #0x8]
 *   @0x1a3fd8 add r10, r2, r1, lsl #2
 *   @0x1a3fdc ldr r0, [r2, r1, lsl #2]
 *   @0x1a3fe0 cmp r0, #0
 *   @0x1a3fe4 beq 0x1a3ff8 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0xb0>
 *   @0x1a3fe8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a3fec ldmib r4, {r3, r12}
 *   @0x1a3ff0 sub r12, r12, #-1073741823
 *   @0x1a3ff4 add r10, r3, r12, lsl #2
 *   @0x1a3ff8 mov r1, r11
 *   @0x1a3ffc movw r2, #0x5b2
 *   @0x1a4000 mov r3, #1
 *   @0x1a4004 mov r0, #64
 *   @0x1a4008 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1a400c ldr lr, [r4, #0x8]
 *   @0x1a4010 mov r1, r9
 *   @0x1a4014 mov r2, r6
 *   @0x1a4018 sub lr, lr, #-1073741823
 *   @0x1a401c str r0, [r10]
 *   @0x1a4020 mov r0, r8
 *   @0x1a4024 ldr r3, [r4, #0x4]
 *   @0x1a4028 ldr r3, [r3, lr, lsl #2]
 *   @0x1a402c bl 0x1a2e5c <_Z14CreateParticleffiR9RParticle>
 *   @0x1a4030 ldmib r4, {r2, r3}
 *   @0x1a4034 cmp r7, r5
 *   @0x1a4038 sub r1, r3, #-1073741823
 *   @0x1a403c ldr r2, [r2, r1, lsl #2]
 *   @0x1a4040 ldr r1, [sp, #0x30]
 *   @0x1a4044 str r1, [r2, #0x2c]
 *   @0x1a4048 blt 0x1a40a0 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x158>
 *   @0x1a404c ldr r2, [r4]
 *   @0x1a4050 add r5, r5, #1
 *   @0x1a4054 cmp r2, r3
 *   @0x1a4058 bgt 0x1a3fc8 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x80>
 *   @0x1a405c add r1, r3, #100
 *   @0x1a4060 ldm sp, {r0, r2}
 *   @0x1a4064 movw r3, #0x5aa
 *   @0x1a4068 lsl r1, r1, #2
 *   @0x1a406c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a4070 ldr r3, [r4, #0x8]
 *   @0x1a4074 add r2, r3, #100
 *   @0x1a4078 str r2, [r4]
 *   @0x1a407c b 0x1a3fc8 <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x80>
 *   @0x1a4080 ldr r1, [pc, #0x40]
 *   @0x1a4084 ldr r3, [pc, #0x40]
 *   @0x1a4088 add r1, pc, r1
 *   @0x1a408c ldr r3, [r4, r3]
 *   @0x1a4090 ldr r0, [r3]
 *   @0x1a4094 ldr r3, [r0]
 *   @0x1a4098 ldr r3, [r3, #0xc]
 *   @0x1a409c blx r3
 *   @0x1a40a0 add sp, sp, #12
 *   @0x1a40a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a40a8 ldr r1, [pc, #0x20]
 *   @0x1a40ac ldr r3, [pc, #0x18]
 *   @0x1a40b0 add r1, pc, r1
 *   @0x1a40b4 b 0x1a408c <_Z37ParticleSystem_Particles_Create_Coloriffiji+0x144>
 *   @0x1a40b8 eoreq sp, r4, r4, ror #25
 *   @0x1a40bc .word 0xffffeb68
 *   @0x1a40c0 ldrsbeq r8, [r10], -r0
 *   @0x1a40c4 andseq r8, r10, r4, asr #31
 *   @0x1a40c8 andseq r8, r10, r4, lsr #31
 *   @0x1a40cc .word 0xffffbac4
 *   @0x1a40d0 ldrheq r8, [r10], -r8
 *
 * ══ §44/76 F_LayerGetIdAtDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x1ba800  size 396  99 条（0x1ba800..0x1ba98c）
 * @func 0x1ba800 0x1ba98c  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / CLayerManager::GetTargetRoomObj() / Error_Show(char const*, bool) / YYGetInt32(RValue const*, int) / ARRAY_RefAlloc(void*)
 * 字段偏移 top8: 0x4×10 / 0x68×3 / 0xd4×2 / 0xc×2 / 0x28×1 / 0x154×1 / 0x19×1 / 0xc8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ba800 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ba804 sub sp, sp, #4
 *   @0x1ba808 mov r6, r0
 *   @0x1ba80c mov r4, r3
 *   @0x1ba810 ldr r5, [sp, #0x28]
 *   @0x1ba814 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1ba818 subs r8, r0, #0
 *   @0x1ba81c beq 0x1ba838 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1ba820 cmp r4, #1
 *   @0x1ba824 beq 0x1ba858 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x1ba828 ldr r0, [pc, #0x154]
 *   @0x1ba82c mov r1, #0
 *   @0x1ba830 add r0, pc, r0
 *   @0x1ba834 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1ba838 mov r0, r6
 *   @0x1ba83c mov r1, #1
 *   @0x1ba840 mov r2, #0
 *   @0x1ba844 mov r3, #0
 *   @0x1ba848 movt r3, #0xbff0
 *   @0x1ba84c add sp, sp, #4
 *   @0x1ba850 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ba854 b 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x1ba858 mov r0, r5
 *   @0x1ba85c mov r1, #0
 *   @0x1ba860 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1ba864 ldr r4, [r8, #0xd4]
 *   @0x1ba868 cmp r4, #0
 *   @0x1ba86c mov r5, r0
 *   @0x1ba870 beq 0x1ba838 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1ba874 mov r7, #0
 *   @0x1ba878 ldrb r3, [r4, #0x19]
 *   @0x1ba87c cmp r3, #0
 *   @0x1ba880 bne 0x1ba890 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x1ba884 ldr r3, [r4, #0x4]
 *   @0x1ba888 cmp r3, r5
 *   @0x1ba88c addeq r7, r7, #1
 *   @0x1ba890 ldr r4, [r4, #0x68]
 *   @0x1ba894 cmp r4, #0
 *   @0x1ba898 bne 0x1ba878 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1ba89c cmp r7, #0
 *   @0x1ba8a0 beq 0x1ba838 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1ba8a4 mov r3, #2
 *   @0x1ba8a8 mov r0, r6
 *   @0x1ba8ac str r3, [r6, #0xc]
 *   @0x1ba8b0 mov r10, #1
 *   @0x1ba8b4 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x1ba8b8 ldr r11, [pc, #0xc8]
 *   @0x1ba8bc mov r3, r10
 *   @0x1ba8c0 mov r2, #2688
 *   @0x1ba8c4 add r11, pc, r11
 *   @0x1ba8c8 mov r1, r11
 *   @0x1ba8cc mov r9, r0
 *   @0x1ba8d0 str r0, [r6]
 *   @0x1ba8d4 str r10, [r0, #0x10]
 *   @0x1ba8d8 mov r0, #8
 *   @0x1ba8dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1ba8e0 mov r1, r11
 *   @0x1ba8e4 mov r3, r10
 *   @0x1ba8e8 movw r2, #0xa81
 *   @0x1ba8ec str r0, [r9, #0x4]
 *   @0x1ba8f0 lsl r0, r7, #4
 *   @0x1ba8f4 ldr r12, [r6]
 *   @0x1ba8f8 ldr r9, [r12, #0x4]
 *   @0x1ba8fc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1ba900 ldr r1, [r8, #0xd4]
 *   @0x1ba904 cmp r1, #0
 *   @0x1ba908 str r0, [r9, #0x4]
 *   @0x1ba90c ldr r3, [r6]
 *   @0x1ba910 ldr r3, [r3, #0x4]
 *   @0x1ba914 str r7, [r3]
 *   @0x1ba918 beq 0x1ba97c <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x1ba91c mov r7, r4
 *   @0x1ba920 b 0x1ba930 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x1ba924 ldr r1, [r1, #0x68]
 *   @0x1ba928 cmp r1, #0
 *   @0x1ba92c beq 0x1ba97c <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x1ba930 ldr r3, [r1, #0x4]
 *   @0x1ba934 cmp r3, r5
 *   @0x1ba938 bne 0x1ba924 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1ba93c vldr s15, [r1]
 *   @0x1ba940 vcvt.f64.s32 d7, s15
 *   @0x1ba944 ldr r3, [r6]
 *   @0x1ba948 lsl r12, r4, #4
 *   @0x1ba94c ldr r8, [r3, #0x4]
 *   @0x1ba950 vmov r2, r3, d7
 *   @0x1ba954 ldr r8, [r8, #0x4]
 *   @0x1ba958 mov r0, r8
 *   @0x1ba95c add r8, r8, r12
 *   @0x1ba960 str r7, [r8, #0xc]
 *   @0x1ba964 str r2, [r0, r4, lsl #4]
 *   @0x1ba968 add r4, r4, #1
 *   @0x1ba96c str r3, [r8, #0x4]
 *   @0x1ba970 ldr r1, [r1, #0x68]
 *   @0x1ba974 cmp r1, #0
 *   @0x1ba978 bne 0x1ba930 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x1ba97c add sp, sp, #4
 *   @0x1ba980 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ba984 andseq r2, r9, r8, lsl #30
 *   @0x1ba988 andseq r2, r9, r8, lsr #29
 *
 * ══ §45/76 F_LayerTileCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c7340  size 396  99 条（0x1c7340..0x1c74cc）
 * @func 0x1c7340 0x1c74cc  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×6 / YYGetFloat(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::GetNewTileElement() / CLayerManager::AddNewElement(CRoom*, CLayer*, CLayerElementBase*, bool) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x24×2 / 0x28×2 / 0x18×1 / 0x148×1 / 0x20×1 / 0x48×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c7340 cmp r3, #8
 *   @0x1c7344 mov r3, #0
 *   @0x1c7348 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c734c mov r6, r3
 *   @0x1c7350 mov r4, r0
 *   @0x1c7354 movt r3, #0xbff0
 *   @0x1c7358 str r6, [r0, #0xc]
 *   @0x1c735c str r3, [r0, #0x4]
 *   @0x1c7360 str r6, [r0]
 *   @0x1c7364 ldr r5, [sp, #0x18]
 *   @0x1c7368 beq 0x1c7380 <_Z17F_LayerTileCreateR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1c736c ldr r0, [pc, #0x148]
 *   @0x1c7370 mov r1, r6
 *   @0x1c7374 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c7378 add r0, pc, r0
 *   @0x1c737c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c7380 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c7384 ldr r3, [r5, #0xc]
 *   @0x1c7388 mov r1, r6
 *   @0x1c738c bic r3, r3, #-16777216
 *   @0x1c7390 cmp r3, #1
 *   @0x1c7394 mov r8, r0
 *   @0x1c7398 mov r0, r5
 *   @0x1c739c beq 0x1c747c <_Z17F_LayerTileCreateR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x1c73a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c73a4 mov r1, r0
 *   @0x1c73a8 mov r0, r8
 *   @0x1c73ac bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c73b0 mov r7, r0
 *   @0x1c73b4 cmp r7, #0
 *   @0x1c73b8 beq 0x1c7494 <_Z17F_LayerTileCreateR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x1c73bc bl 0x1c1260 <_ZN13CLayerManager17GetNewTileElementEv>
 *   @0x1c73c0 mov r1, #3
 *   @0x1c73c4 mov r6, r0
 *   @0x1c73c8 mov r0, r5
 *   @0x1c73cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c73d0 mov r1, #1
 *   @0x1c73d4 str r0, [r6, #0x20]
 *   @0x1c73d8 mov r0, r5
 *   @0x1c73dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1c73e0 mov r1, #2
 *   @0x1c73e4 str r0, [r6, #0x24]
 *   @0x1c73e8 mov r0, r5
 *   @0x1c73ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1c73f0 mov r1, #4
 *   @0x1c73f4 str r0, [r6, #0x28]
 *   @0x1c73f8 mov r0, r5
 *   @0x1c73fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c7400 mov r1, #5
 *   @0x1c7404 str r0, [r6, #0x48]
 *   @0x1c7408 mov r0, r5
 *   @0x1c740c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c7410 mov r1, #6
 *   @0x1c7414 str r0, [r6, #0x4c]
 *   @0x1c7418 mov r0, r5
 *   @0x1c741c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c7420 mov r1, #7
 *   @0x1c7424 str r0, [r6, #0x2c]
 *   @0x1c7428 mov r0, r5
 *   @0x1c742c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c7430 ldr r3, [pc, #0x88]
 *   @0x1c7434 mov r2, #1
 *   @0x1c7438 mov r1, r7
 *   @0x1c743c ldr r3, [pc, r3]
 *   @0x1c7440 strb r2, [r6, #0x1c]
 *   @0x1c7444 mov r2, r6
 *   @0x1c7448 ldr r3, [r3]
 *   @0x1c744c subs r12, r3, r8
 *   @0x1c7450 rsbs r3, r12, #0
 *   @0x1c7454 adcs r3, r3, r12
 *   @0x1c7458 str r0, [r6, #0x30]
 *   @0x1c745c mov r0, r8
 *   @0x1c7460 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb>
 *   @0x1c7464 ldr r2, [r6, #0x4]
 *   @0x1c7468 vmov s15, r2
 *   @0x1c746c vcvt.f64.s32 d7, s15
 *   @0x1c7470 vmov r2, r3, d7
 *   @0x1c7474 stm r4, {r2, r3}
 *   @0x1c7478 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c747c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c7480 mov r1, r0
 *   @0x1c7484 mov r0, r8
 *   @0x1c7488 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c748c mov r7, r0
 *   @0x1c7490 b 0x1c73b4 <_Z17F_LayerTileCreateR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1c7494 ldr r3, [pc, #0x28]
 *   @0x1c7498 mov r2, r7
 *   @0x1c749c ldr r1, [pc, #0x24]
 *   @0x1c74a0 ldr r3, [pc, r3]
 *   @0x1c74a4 add r1, pc, r1
 *   @0x1c74a8 ldr r0, [r3]
 *   @0x1c74ac ldr r3, [r0]
 *   @0x1c74b0 ldr r3, [r3, #0xc]
 *   @0x1c74b4 blx r3
 *   @0x1c74b8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c74bc andseq r9, r8, r4, asr r7
 *   @0x1c74c0 eoreq r6, r2, r12, ror #9
 *   @0x1c74c4 eoreq r6, r2, r4, ror r2
 *   @0x1c74c8 andseq r9, r8, r8, asr r6
 *
 * ══ §46/76 DecodeScore(char const*, char const*&, int&)  0x1dc048  size 396  99 条（0x1dc048..0x1dc1d4）
 * @func 0x1dc048 0x1dc1d4  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0×2 / 0xb6538×2 / DecodeScore(char const*, char const*&, int&)+0x50 / MemoryManager::Free(void const*) / DecodeScore(char const*, char const*&, int&)+0x138 / YYStrDup(char const*) / 0xb65d4
 * 字段偏移 top8: 0x4×6 / 0xc0c×2 / 0x174×1 / 0x-2×1 / 0x-1×1 / 0xfc×1 / 0x-4×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc048 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1dc04c sub sp, sp, #3088
 *   @0x1dc050 ldr r6, [pc, #0x174]
 *   @0x1dc054 sub sp, sp, #4
 *   @0x1dc058 add r8, sp, #16
 *   @0x1dc05c mov r5, r0
 *   @0x1dc060 ldr r6, [pc, r6]
 *   @0x1dc064 sub r7, r8, #8
 *   @0x1dc068 mov r9, r1
 *   @0x1dc06c str r2, [sp, #0x4]
 *   @0x1dc070 ldr r3, [r6]
 *   @0x1dc074 mov r0, r7
 *   @0x1dc078 mov r1, #0
 *   @0x1dc07c movw r2, #0x101
 *   @0x1dc080 mov r11, r7
 *   @0x1dc084 mov r4, r5
 *   @0x1dc088 mov r10, #1
 *   @0x1dc08c str r3, [sp, #0xc0c]
 *   @0x1dc090 bl 0xb65b0 <memset@plt>
 *   @0x1dc094 b 0x1dc0b4 <_Z11DecodeScorePKcRS0_Ri+0x6c>
 *   @0x1dc098 ldrb r2, [r4, #-0x2]
 *   @0x1dc09c add r10, r10, #1
 *   @0x1dc0a0 ldrb r3, [r4, #-0x1]
 *   @0x1dc0a4 add r3, r3, r2, lsl #4
 *   @0x1dc0a8 sub r3, r3, #1104
 *   @0x1dc0ac sub r3, r3, #1
 *   @0x1dc0b0 str r3, [r11, #0x4]!
 *   @0x1dc0b4 mov r0, r5
 *   @0x1dc0b8 add r4, r4, #2
 *   @0x1dc0bc bl 0xb6538 <strlen@plt>
 *   @0x1dc0c0 add r0, r0, r0, lsr #31
 *   @0x1dc0c4 cmp r10, r0, asr #1
 *   @0x1dc0c8 ble 0x1dc098 <_Z11DecodeScorePKcRS0_Ri+0x50>
 *   @0x1dc0cc ldr r2, [pc, #0xfc]
 *   @0x1dc0d0 sub r1, r8, #4
 *   @0x1dc0d4 mov r3, #1
 *   @0x1dc0d8 movw lr, #0x101
 *   @0x1dc0dc ldr r2, [pc, r2]
 *   @0x1dc0e0 ldr r12, [r2]
 *   @0x1dc0e4 ldr r0, [r1], #4
 *   @0x1dc0e8 rsb r0, r3, r0
 *   @0x1dc0ec add r3, r3, #1
 *   @0x1dc0f0 rsb r0, r12, r0
 *   @0x1dc0f4 asr r2, r0, #31
 *   @0x1dc0f8 lsr r2, r2, #24
 *   @0x1dc0fc add r0, r0, r2
 *   @0x1dc100 uxtb r0, r0
 *   @0x1dc104 subs r2, r0, r2
 *   @0x1dc108 addmi r2, r2, #256
 *   @0x1dc10c cmp r3, lr
 *   @0x1dc110 str r2, [r1, #-0x4]
 *   @0x1dc114 bne 0x1dc0e4 <_Z11DecodeScorePKcRS0_Ri+0x9c>
 *   @0x1dc118 add r0, r7, #64
 *   @0x1dc11c mov r2, #0
 *   @0x1dc120 mov r3, #1
 *   @0x1dc124 ldr r1, [r7, #0x4]!
 *   @0x1dc128 cmp r7, r0
 *   @0x1dc12c mla r2, r3, r1, r2
 *   @0x1dc130 lsl r3, r3, #8
 *   @0x1dc134 bne 0x1dc124 <_Z11DecodeScorePKcRS0_Ri+0xdc>
 *   @0x1dc138 ldr r0, [r9]
 *   @0x1dc13c ldr r3, [sp, #0x4]
 *   @0x1dc140 cmp r0, #0
 *   @0x1dc144 str r2, [r3]
 *   @0x1dc148 beq 0x1dc158 <_Z11DecodeScorePKcRS0_Ri+0x110>
 *   @0x1dc14c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1dc150 mov r3, #0
 *   @0x1dc154 str r3, [r9]
 *   @0x1dc158 add r7, sp, #1040
 *   @0x1dc15c mov r1, #0
 *   @0x1dc160 sub r10, r7, #4
 *   @0x1dc164 mov r2, #2048
 *   @0x1dc168 add r8, r8, #56
 *   @0x1dc16c sub r7, r7, #5
 *   @0x1dc170 mov r0, r10
 *   @0x1dc174 mov r4, #17
 *   @0x1dc178 bl 0xb65b0 <memset@plt>
 *   @0x1dc17c b 0x1dc18c <_Z11DecodeScorePKcRS0_Ri+0x144>
 *   @0x1dc180 ldr r3, [r8, #0x4]!
 *   @0x1dc184 add r4, r4, #1
 *   @0x1dc188 strb r3, [r7, #0x1]!
 *   @0x1dc18c mov r0, r5
 *   @0x1dc190 bl 0xb6538 <strlen@plt>
 *   @0x1dc194 add r0, r0, r0, lsr #31
 *   @0x1dc198 cmp r4, r0, asr #1
 *   @0x1dc19c ble 0x1dc180 <_Z11DecodeScorePKcRS0_Ri+0x138>
 *   @0x1dc1a0 mov r0, r10
 *   @0x1dc1a4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1dc1a8 ldr r3, [sp, #0xc0c]
 *   @0x1dc1ac str r0, [r9]
 *   @0x1dc1b0 ldr r2, [r6]
 *   @0x1dc1b4 cmp r3, r2
 *   @0x1dc1b8 bne 0x1dc1c8 <_Z11DecodeScorePKcRS0_Ri+0x180>
 *   @0x1dc1bc add sp, sp, #3088
 *   @0x1dc1c0 add sp, sp, #4
 *   @0x1dc1c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1dc1c8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1dc1cc .word 0x002118f0
 *   @0x1dc1d0 eoreq r4, r1, r8, lsr r10
 *
 * ══ §47/76 CDS_Grid::Value_Disk_X(RValue&, double, double, double, RValue*)  0x204c54  size 396  99 条（0x204c54..0x204de0）
 * @func 0x204c54 0x204df4  size 416  104 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598×2 / 0xb670c×2 / CDS_Grid::Value_Disk_X(RValue&, double, double, double, RValue*)+0x174 / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x68×1 / 0x8×1 / 0x44×1
 * VFP 指令 52 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x204c54 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x204c58 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x204c5c vmov d12, r2, r3
 *   @0x204c60 vldr d11, [sp, #96]
 *   @0x204c64 mov r10, r1
 *   @0x204c68 mov r3, #0
 *   @0x204c6c vsub.f64 d6, d12, d11
 *   @0x204c70 mov r6, r3
 *   @0x204c74 mov r11, r0
 *   @0x204c78 movt r3, #0xbff0
 *   @0x204c7c str r6, [r1, #0xc]
 *   @0x204c80 str r3, [r1, #0x4]
 *   @0x204c84 str r6, [r10]
 *   @0x204c88 vmov r0, r1, d6
 *   @0x204c8c bl 0xb6598 <floor@plt>
 *   @0x204c90 ldr r9, [r11, #0x4]
 *   @0x204c94 vldr d10, [sp, #88]
 *   @0x204c98 ldr r7, [sp, #0x68]
 *   @0x204c9c sub r9, r9, #1
 *   @0x204ca0 vmov d7, r0, r1
 *   @0x204ca4 vcmpe.f64 d7, #0
 *   @0x204ca8 vmrs APSR_nzcv, fpscr
 *   @0x204cac vcvtpl.s32.f64 s13, d7
 *   @0x204cb0 vadd.f64 d7, d12, d11
 *   @0x204cb4 vmovpl r6, s13
 *   @0x204cb8 vmov r0, r1, d7
 *   @0x204cbc bl 0xb670c <ceil@plt>
 *   @0x204cc0 vmov s11, r9
 *   @0x204cc4 vcvt.f64.s32 d6, s11
 *   @0x204cc8 vmov d7, r0, r1
 *   @0x204ccc vcmpe.f64 d6, d7
 *   @0x204cd0 vmrs APSR_nzcv, fpscr
 *   @0x204cd4 vcvtpl.s32.f64 s12, d7
 *   @0x204cd8 vsub.f64 d7, d10, d11
 *   @0x204cdc vmovpl r9, s12
 *   @0x204ce0 vmov r0, r1, d7
 *   @0x204ce4 bl 0xb6598 <floor@plt>
 *   @0x204ce8 ldr r5, [r11, #0x8]
 *   @0x204cec vadd.f64 d6, d10, d11
 *   @0x204cf0 sub r5, r5, #1
 *   @0x204cf4 vmov d7, r0, r1
 *   @0x204cf8 vcmpe.f64 d7, #0
 *   @0x204cfc vmov r0, r1, d6
 *   @0x204d00 vmrs APSR_nzcv, fpscr
 *   @0x204d04 vcvtpl.s32.f64 s11, d7
 *   @0x204d08 movmi r8, #0
 *   @0x204d0c vmovpl r8, s11
 *   @0x204d10 bl 0xb670c <ceil@plt>
 *   @0x204d14 vmov s11, r5
 *   @0x204d18 vcvt.f64.s32 d6, s11
 *   @0x204d1c vmov d7, r0, r1
 *   @0x204d20 vcmpe.f64 d6, d7
 *   @0x204d24 vmrs APSR_nzcv, fpscr
 *   @0x204d28 vcvtpl.s32.f64 s12, d7
 *   @0x204d2c vmovpl r5, s12
 *   @0x204d30 cmp r6, r9
 *   @0x204d34 bgt 0x204dc0 <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0x16c>
 *   @0x204d38 cmp r8, r5
 *   @0x204d3c bgt 0x204dc8 <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0x174>
 *   @0x204d40 vmov s13, r6
 *   @0x204d44 mov r4, r8
 *   @0x204d48 vmul.f64 d9, d11, d11
 *   @0x204d4c vcvt.f64.s32 d13, s13
 *   @0x204d50 vsub.f64 d8, d13, d12
 *   @0x204d54 vmul.f64 d8, d8, d8
 *   @0x204d58 b 0x204d68 <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0x114>
 *   @0x204d5c add r4, r4, #1
 *   @0x204d60 cmp r5, r4
 *   @0x204d64 blt 0x204dc8 <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0x174>
 *   @0x204d68 vmov s13, r4
 *   @0x204d6c vcvt.f64.s32 d7, s13
 *   @0x204d70 vsub.f64 d7, d7, d10
 *   @0x204d74 vmov.f64 d6, d8
 *   @0x204d78 vmla.f64 d6, d7, d7
 *   @0x204d7c vcmpe.f64 d6, d9
 *   @0x204d80 vmrs APSR_nzcv, fpscr
 *   @0x204d84 bhi 0x204d5c <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0x108>
 *   @0x204d88 ldr r0, [r11, #0x4]
 *   @0x204d8c mov r1, r7
 *   @0x204d90 ldr r3, [pc, #0x44]
 *   @0x204d94 ldr r12, [r11]
 *   @0x204d98 mla r0, r0, r4, r6
 *   @0x204d9c ldr r3, [pc, r3]
 *   @0x204da0 ldrd r2, r3, [r3]
 *   @0x204da4 add r0, r12, r0, lsl #4
 *   @0x204da8 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x204dac cmp r0, #0
 *   @0x204db0 bne 0x204d5c <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0x108>
 *   @0x204db4 vmov r2, s26
 *   @0x204db8 vmov r3, s27
 *   @0x204dbc stm r10, {r2, r3}
 *   @0x204dc0 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x204dc4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x204dc8 add r6, r6, #1
 *   @0x204dcc cmp r9, r6
 *   @0x204dd0 bge 0x204d38 <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_+0xe4>
 *   @0x204dd4 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x204dd8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x204ddc andseq r12, lr, r8, ror #11
 *
 * ══ §48/76 CDS_Grid::Value_Disk_Y(RValue&, double, double, double, RValue*)  0x204de0  size 396  99 条（0x204de0..0x204f6c）
 * @func 0x204de0 0x204f6c  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598×2 / 0xb670c×2 / CDS_Grid::Value_Disk_Y(RValue&, double, double, double, RValue*)+0x174 / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x68×1 / 0x8×1 / 0x44×1
 * VFP 指令 52 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x204de0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x204de4 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x204de8 vmov d13, r2, r3
 *   @0x204dec vldr d12, [sp, #96]
 *   @0x204df0 mov r10, r1
 *   @0x204df4 mov r3, #0
 *   @0x204df8 vsub.f64 d6, d13, d12
 *   @0x204dfc mov r6, r3
 *   @0x204e00 mov r11, r0
 *   @0x204e04 movt r3, #0xbff0
 *   @0x204e08 str r6, [r1, #0xc]
 *   @0x204e0c str r3, [r1, #0x4]
 *   @0x204e10 str r6, [r10]
 *   @0x204e14 vmov r0, r1, d6
 *   @0x204e18 bl 0xb6598 <floor@plt>
 *   @0x204e1c ldr r9, [r11, #0x4]
 *   @0x204e20 vldr d11, [sp, #88]
 *   @0x204e24 ldr r7, [sp, #0x68]
 *   @0x204e28 sub r9, r9, #1
 *   @0x204e2c vmov d7, r0, r1
 *   @0x204e30 vcmpe.f64 d7, #0
 *   @0x204e34 vmrs APSR_nzcv, fpscr
 *   @0x204e38 vcvtpl.s32.f64 s13, d7
 *   @0x204e3c vadd.f64 d7, d13, d12
 *   @0x204e40 vmovpl r6, s13
 *   @0x204e44 vmov r0, r1, d7
 *   @0x204e48 bl 0xb670c <ceil@plt>
 *   @0x204e4c vmov s11, r9
 *   @0x204e50 vcvt.f64.s32 d6, s11
 *   @0x204e54 vmov d7, r0, r1
 *   @0x204e58 vcmpe.f64 d6, d7
 *   @0x204e5c vmrs APSR_nzcv, fpscr
 *   @0x204e60 vcvtpl.s32.f64 s12, d7
 *   @0x204e64 vsub.f64 d7, d11, d12
 *   @0x204e68 vmovpl r9, s12
 *   @0x204e6c vmov r0, r1, d7
 *   @0x204e70 bl 0xb6598 <floor@plt>
 *   @0x204e74 ldr r5, [r11, #0x8]
 *   @0x204e78 vadd.f64 d6, d11, d12
 *   @0x204e7c sub r5, r5, #1
 *   @0x204e80 vmov d7, r0, r1
 *   @0x204e84 vcmpe.f64 d7, #0
 *   @0x204e88 vmov r0, r1, d6
 *   @0x204e8c vmrs APSR_nzcv, fpscr
 *   @0x204e90 vcvtpl.s32.f64 s11, d7
 *   @0x204e94 movmi r8, #0
 *   @0x204e98 vmovpl r8, s11
 *   @0x204e9c bl 0xb670c <ceil@plt>
 *   @0x204ea0 vmov s11, r5
 *   @0x204ea4 vcvt.f64.s32 d6, s11
 *   @0x204ea8 vmov d7, r0, r1
 *   @0x204eac vcmpe.f64 d6, d7
 *   @0x204eb0 vmrs APSR_nzcv, fpscr
 *   @0x204eb4 vcvtpl.s32.f64 s12, d7
 *   @0x204eb8 vmovpl r5, s12
 *   @0x204ebc cmp r6, r9
 *   @0x204ec0 bgt 0x204f4c <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0x16c>
 *   @0x204ec4 cmp r8, r5
 *   @0x204ec8 bgt 0x204f54 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0x174>
 *   @0x204ecc vmov s13, r6
 *   @0x204ed0 mov r4, r8
 *   @0x204ed4 vmul.f64 d10, d12, d12
 *   @0x204ed8 vcvt.f64.s32 d9, s13
 *   @0x204edc vsub.f64 d9, d9, d13
 *   @0x204ee0 vmul.f64 d9, d9, d9
 *   @0x204ee4 b 0x204ef4 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0x114>
 *   @0x204ee8 add r4, r4, #1
 *   @0x204eec cmp r5, r4
 *   @0x204ef0 blt 0x204f54 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0x174>
 *   @0x204ef4 vmov s13, r4
 *   @0x204ef8 vcvt.f64.s32 d8, s13
 *   @0x204efc vsub.f64 d7, d8, d11
 *   @0x204f00 vmov.f64 d6, d9
 *   @0x204f04 vmla.f64 d6, d7, d7
 *   @0x204f08 vcmpe.f64 d6, d10
 *   @0x204f0c vmrs APSR_nzcv, fpscr
 *   @0x204f10 bhi 0x204ee8 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0x108>
 *   @0x204f14 ldr r0, [r11, #0x4]
 *   @0x204f18 mov r1, r7
 *   @0x204f1c ldr r3, [pc, #0x44]
 *   @0x204f20 ldr r12, [r11]
 *   @0x204f24 mla r0, r0, r4, r6
 *   @0x204f28 ldr r3, [pc, r3]
 *   @0x204f2c ldrd r2, r3, [r3]
 *   @0x204f30 add r0, r12, r0, lsl #4
 *   @0x204f34 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x204f38 cmp r0, #0
 *   @0x204f3c bne 0x204ee8 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0x108>
 *   @0x204f40 vmov r2, s16
 *   @0x204f44 vmov r3, s17
 *   @0x204f48 stm r10, {r2, r3}
 *   @0x204f4c vpop {d8, d9, d10, d11, d12, d13}
 *   @0x204f50 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x204f54 add r6, r6, #1
 *   @0x204f58 cmp r9, r6
 *   @0x204f5c bge 0x204ec4 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_+0xe4>
 *   @0x204f60 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x204f64 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x204f68 andseq r12, lr, r12, asr r4
 *
 * ══ §49/76 vorbis_book_decode  0x2280d0  size 396  99 条（0x2280d0..0x22825c）
 * @func 0x2280d0 0x22825c  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_adv×4 / oggpack_look×2 / vorbis_book_decode+0x15c / vorbis_book_decode+0x164 / vorbis_book_decode+0x17c / vorbis_book_decode+0x11c
 * 字段偏移 top8: 0x8×3 / 0x2×3 / 0x1c×2 / 0x24×1 / 0x28×1 / 0x20×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2280d0 ldr r3, [r0, #0x8]
 *   @0x2280d4 push {r4, r5, r6, r7, r8, lr}
 *   @0x2280d8 cmp r3, #0
 *   @0x2280dc mov r8, r0
 *   @0x2280e0 mov r7, r1
 *   @0x2280e4 ble 0x22822c <vorbis_book_decode+0x15c>
 *   @0x2280e8 mov r0, r1
 *   @0x2280ec ldr r1, [r8, #0x24]
 *   @0x2280f0 ldr r4, [r8, #0x28]
 *   @0x2280f4 bl 0x23388c <oggpack_look>
 *   @0x2280f8 cmp r0, #0
 *   @0x2280fc blt 0x228234 <vorbis_book_decode+0x164>
 *   @0x228100 ldr r3, [r8, #0x20]
 *   @0x228104 ldr r5, [r3, r0, lsl #2]
 *   @0x228108 cmp r5, #0
 *   @0x22810c bge 0x228210 <vorbis_book_decode+0x140>
 *   @0x228110 ldr r6, [r8, #0x8]
 *   @0x228114 ubfx r3, r5, #0x0, #0xf
 *   @0x228118 ubfx r5, r5, #0xf, #0xf
 *   @0x22811c rsb r6, r3, r6
 *   @0x228120 b 0x228128 <vorbis_book_decode+0x58>
 *   @0x228124 sub r4, r4, #1
 *   @0x228128 mov r0, r7
 *   @0x22812c mov r1, r4
 *   @0x228130 bl 0x23388c <oggpack_look>
 *   @0x228134 cmp r4, #1
 *   @0x228138 movle r3, #0
 *   @0x22813c movgt r3, #1
 *   @0x228140 ands r3, r3, r0, lsr #31
 *   @0x228144 bne 0x228124 <vorbis_book_decode+0x54>
 *   @0x228148 cmp r0, #0
 *   @0x22814c blt 0x22824c <vorbis_book_decode+0x17c>
 *   @0x228150 rev r0, r0
 *   @0x228154 movw r3, #0xf0f
 *   @0x228158 movw r2, #0xf0f0
 *   @0x22815c bfi r3, r3, #16, #16
 *   @0x228160 bfi r2, r2, #16, #16
 *   @0x228164 and r3, r3, r0, lsr #4
 *   @0x228168 and r0, r2, r0, lsl #4
 *   @0x22816c movw r2, #0x3333
 *   @0x228170 orr r12, r0, r3
 *   @0x228174 bfi r2, r2, #16, #16
 *   @0x228178 movw r3, #0xcccc
 *   @0x22817c bfi r3, r3, #16, #16
 *   @0x228180 and r2, r2, r12, lsr #2
 *   @0x228184 and r3, r3, r12, lsl #2
 *   @0x228188 orr r0, r3, r2
 *   @0x22818c rsb r3, r5, r6
 *   @0x228190 movw r1, #0xaaaa
 *   @0x228194 movw r2, #0x5555
 *   @0x228198 bfi r1, r1, #16, #16
 *   @0x22819c bfi r2, r2, #16, #16
 *   @0x2281a0 cmp r3, #1
 *   @0x2281a4 and r1, r1, r0, lsl #1
 *   @0x2281a8 and r2, r2, r0, lsr #1
 *   @0x2281ac orr r1, r1, r2
 *   @0x2281b0 ble 0x2281ec <vorbis_book_decode+0x11c>
 *   @0x2281b4 ldr r12, [r8, #0x14]
 *   @0x2281b8 asr r3, r3, #1
 *   @0x2281bc add r2, r3, r5
 *   @0x2281c0 ldr r2, [r12, r2, lsl #2]
 *   @0x2281c4 cmp r2, r1
 *   @0x2281c8 movls r0, r3
 *   @0x2281cc movhi r0, #0
 *   @0x2281d0 cmp r2, r1
 *   @0x2281d4 add r5, r5, r0
 *   @0x2281d8 movls r3, #0
 *   @0x2281dc rsb r6, r3, r6
 *   @0x2281e0 rsb r3, r5, r6
 *   @0x2281e4 cmp r3, #1
 *   @0x2281e8 bgt 0x2281b8 <vorbis_book_decode+0xe8>
 *   @0x2281ec ldr r3, [r8, #0x1c]
 *   @0x2281f0 mov r0, r7
 *   @0x2281f4 ldrb r1, [r3, r5]
 *   @0x2281f8 cmp r1, r4
 *   @0x2281fc bgt 0x228240 <vorbis_book_decode+0x170>
 *   @0x228200 bl 0x233a7c <oggpack_adv>
 *   @0x228204 ldr r3, [r8, #0x18]
 *   @0x228208 ldr r0, [r3, r5, lsl #2]
 *   @0x22820c pop {r4, r5, r6, r7, r8, pc}
 *   @0x228210 ldr r3, [r8, #0x1c]
 *   @0x228214 mov r0, r7
 *   @0x228218 add r3, r3, r5
 *   @0x22821c ldrb r1, [r3, #-0x1]
 *   @0x228220 bl 0x233a7c <oggpack_adv>
 *   @0x228224 subs r5, r5, #1
 *   @0x228228 bhs 0x228204 <vorbis_book_decode+0x134>
 *   @0x22822c mvn r0, #0
 *   @0x228230 pop {r4, r5, r6, r7, r8, pc}
 *   @0x228234 ldr r6, [r8, #0x8]
 *   @0x228238 mov r5, #0
 *   @0x22823c b 0x228128 <vorbis_book_decode+0x58>
 *   @0x228240 add r1, r4, #1
 *   @0x228244 bl 0x233a7c <oggpack_adv>
 *   @0x228248 b 0x22822c <vorbis_book_decode+0x15c>
 *   @0x22824c mov r0, r7
 *   @0x228250 mov r1, #1
 *   @0x228254 bl 0x233a7c <oggpack_adv>
 *   @0x228258 b 0x22822c <vorbis_book_decode+0x15c>
 *
 * ══ §50/76 json_parse_to_object(json_object*, RValue&)  0x24bd20  size 396  99 条（0x24bd20..0x24beac）
 * @func 0x24bd20 0x24beac  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_object_get_type×2 / FREE_RValue__Pre(RValue*)×2 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / json_object_get_object / json_parse(json_object*, RValue&) / YYObjectBase::Add(char const*, RValue&, int) / YYSetString(RValue*, char const*) / json_object_object_get
 * 字段偏移 top8: 0x24×3 / 0x34×3 / 0x20×2 / 0x28×2 / 0x44×2 / 0x30×2 / 0x8×2 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24bd20 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24bd24 sub sp, sp, #76
 *   @0x24bd28 mov r5, #0
 *   @0x24bd2c mov r9, r1
 *   @0x24bd30 str r0, [sp, #0x24]
 *   @0x24bd34 mov r2, r5
 *   @0x24bd38 mov r0, r1
 *   @0x24bd3c mov r3, r5
 *   @0x24bd40 mov r1, r5
 *   @0x24bd44 str r5, [sp]
 *   @0x24bd48 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x24bd4c ldr r0, [sp, #0x24]
 *   @0x24bd50 bl 0x27e8f4 <json_object_get_object>
 *   @0x24bd54 ldr r4, [r0, #0x20]
 *   @0x24bd58 cmp r4, r5
 *   @0x24bd5c beq 0x24be98 <_Z20json_parse_to_objectP11json_objectR6RValue+0x178>
 *   @0x24bd60 add r8, sp, #40
 *   @0x24bd64 add r2, sp, #44
 *   @0x24bd68 add r3, sp, #48
 *   @0x24bd6c mov r11, r5
 *   @0x24bd70 str r2, [sp, #0x18]
 *   @0x24bd74 add r5, sp, #56
 *   @0x24bd78 add r2, sp, #52
 *   @0x24bd7c str r3, [sp, #0x1c]
 *   @0x24bd80 str r2, [sp, #0x20]
 *   @0x24bd84 add r3, sp, #60
 *   @0x24bd88 add r2, sp, #64
 *   @0x24bd8c str r3, [sp, #0xc]
 *   @0x24bd90 mov r7, r8
 *   @0x24bd94 add r3, sp, #68
 *   @0x24bd98 str r2, [sp, #0x10]
 *   @0x24bd9c str r3, [sp, #0x14]
 *   @0x24bda0 b 0x24be20 <_Z20json_parse_to_objectP11json_objectR6RValue+0x100>
 *   @0x24bda4 bl 0x27e828 <json_object_get_type>
 *   @0x24bda8 cmp r0, #5
 *   @0x24bdac beq 0x24be70 <_Z20json_parse_to_objectP11json_objectR6RValue+0x150>
 *   @0x24bdb0 mov r0, r10
 *   @0x24bdb4 mov r1, r5
 *   @0x24bdb8 bl 0x24beac <_Z10json_parseP11json_objectR6RValue>
 *   @0x24bdbc ldr r1, [sp, #0x28]
 *   @0x24bdc0 mov r3, #7
 *   @0x24bdc4 ldr r0, [r9]
 *   @0x24bdc8 mov r2, r5
 *   @0x24bdcc ldr r1, [r1]
 *   @0x24bdd0 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x24bdd4 ldr r3, [sp, #0x34]
 *   @0x24bdd8 sub r3, r3, #1
 *   @0x24bddc bic r3, r3, #-16777216
 *   @0x24bde0 bic r3, r3, #3
 *   @0x24bde4 cmp r3, #0
 *   @0x24bde8 beq 0x24bea0 <_Z20json_parse_to_objectP11json_objectR6RValue+0x180>
 *   @0x24bdec ldr r3, [sp, #0x44]
 *   @0x24bdf0 mov r2, #5
 *   @0x24bdf4 str r11, [sp, #0x30]
 *   @0x24bdf8 sub r3, r3, #1
 *   @0x24bdfc str r2, [sp, #0x34]
 *   @0x24be00 bic r3, r3, #-16777216
 *   @0x24be04 str r11, [sp, #0x28]
 *   @0x24be08 bic r3, r3, #3
 *   @0x24be0c cmp r3, #0
 *   @0x24be10 beq 0x24be84 <_Z20json_parse_to_objectP11json_objectR6RValue+0x164>
 *   @0x24be14 ldr r4, [r4, #0x8]
 *   @0x24be18 cmp r4, #0
 *   @0x24be1c beq 0x24be98 <_Z20json_parse_to_objectP11json_objectR6RValue+0x178>
 *   @0x24be20 ldr r6, [r4]
 *   @0x24be24 mov r0, r7
 *   @0x24be28 ldr r10, [r4, #0x4]
 *   @0x24be2c str r11, [r8]
 *   @0x24be30 mov r8, r7
 *   @0x24be34 mov r1, r6
 *   @0x24be38 str r11, [sp, #0x2c]
 *   @0x24be3c str r11, [sp, #0x30]
 *   @0x24be40 str r11, [sp, #0x34]
 *   @0x24be44 str r11, [r5]
 *   @0x24be48 str r11, [sp, #0x3c]
 *   @0x24be4c str r11, [sp, #0x40]
 *   @0x24be50 str r11, [sp, #0x44]
 *   @0x24be54 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x24be58 subs r0, r10, #0
 *   @0x24be5c beq 0x24bdb0 <_Z20json_parse_to_objectP11json_objectR6RValue+0x90>
 *   @0x24be60 bl 0x27e828 <json_object_get_type>
 *   @0x24be64 cmp r0, #4
 *   @0x24be68 mov r0, r10
 *   @0x24be6c bne 0x24bda4 <_Z20json_parse_to_objectP11json_objectR6RValue+0x84>
 *   @0x24be70 mov r1, r6
 *   @0x24be74 ldr r0, [sp, #0x24]
 *   @0x24be78 bl 0x27ea38 <json_object_object_get>
 *   @0x24be7c mov r10, r0
 *   @0x24be80 b 0x24bdb0 <_Z20json_parse_to_objectP11json_objectR6RValue+0x90>
 *   @0x24be84 mov r0, r5
 *   @0x24be88 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24be8c ldr r4, [r4, #0x8]
 *   @0x24be90 cmp r4, #0
 *   @0x24be94 bne 0x24be20 <_Z20json_parse_to_objectP11json_objectR6RValue+0x100>
 *   @0x24be98 add sp, sp, #76
 *   @0x24be9c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24bea0 mov r0, r7
 *   @0x24bea4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24bea8 b 0x24bdec <_Z20json_parse_to_objectP11json_objectR6RValue+0xcc>
 *
 * ══ §51/76 anon_2e7168  0x2e7168  size 396  99 条（0x2e7168..0x2e72f4）
 * @func 0x2e7168 0x2e72f4  size 396  99 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x1aa48ec / 0x393684 / 0x3936a8 / 0x5074e0 / 0x8217dc / 0x366fa0 / 0x4253e8
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7168 .word 0x43f7e92d
 *   @0x2e716c strmi r10, [r4], -r2, lsl #28
 *   @0x2e7170 ldrmi r4, [r7], -r8, lsl #12
 *   @0x2e7174 .word 0xf04f460d
 *   @0x2e7178 .word 0xf8460900
 *   @0x2e717c .word 0xf5cf9d04
 *   @0x2e7180 pkhtbmi lr, r0, r12, asr #19
 *   @0x2e7184 .word 0xf5cf4638
 *   @0x2e7188 .word 0x4632e9d8
 *   @0x2e718c .word 0x0100eb08
 *   @0x2e7190 .word 0x31014620
 *   @0x2e7194 .word 0xffc7f7ff
 *   @0x2e7198 .word 0x8004f8dd
 *   @0x2e719c .word 0xf1b84604
 *   @0x2e71a0 tstle lr, r0, lsl #30
 *   @0x2e71a4 .word 0x212f4628
 *   @0x2e71a8 bl 0x1aa48ec <b2_toiTime+0x134b448>
 *   @0x2e71ac .word 0xb1684606
 *   @0x2e71b0 stmdbeq r0, {r0, r2, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x2e71b4 strtmi r4, [r0], -r9, lsr #12
 *   @0x2e71b8 andeq pc, r1, #1073741826
 *   @0x2e71bc ldmib r4, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x2e71c0 movweq lr, #0x9b04
 *   @0x2e71c4 .word 0xf8831c75
 *   @0x2e71c8 and r8, r0, r1
 *   @0x2e71cc ldrtmi r7, [r9], -r0, lsr #32
 *   @0x2e71d0 .word 0xf5cf4620
 *   @0x2e71d4 strtmi lr, [r0], -r10, lsr #20
 *   @0x2e71d8 .word 0xf5cf4629
 *   @0x2e71dc strtmi lr, [r0], -r6, lsr #20
 *   @0x2e71e0 strbmi lr, [r8], -r0
 *   @0x2e71e4 pop {r0, r1, r12, sp, pc}
 *   @0x2e71e8 strdeq r8, r9, [r0], -r0
 *   @0x2e71ec bmi 0x4b8a38 <SrcVerts+0x15a7c>
 *   @0x2e71f0 ldrbtmi r11, [r10], #-1296
 *   @0x2e71f4 ldrmi r6, [r12], -r0, lsl #16
 *   @0x2e71f8 .word 0xffb6f7ff
 *   @0x2e71fc blls 0x393684 <ft_adobe_glyph_list+0x2d60>
 *   @0x2e7200 andhs r6, r0, r0, lsr #32
 *   @0x2e7204 ldclt p0, c6, [r0, #-96]
 *   @0x2e7208 ldclt p0, c2, [r0, #-256]
 *   @0x2e720c andeq r7, r10, r7, asr #10
 *   @0x2e7210 bmi 0x4b8a5c <SrcVerts+0x15aa0>
 *   @0x2e7214 ldrbtmi r11, [r10], #-1296
 *   @0x2e7218 ldrmi r6, [r12], -r0, lsl #16
 *   @0x2e721c .word 0xffa4f7ff
 *   @0x2e7220 blls 0x3936a8 <ft_adobe_glyph_list+0x2d84>
 *   @0x2e7224 andhs r6, r0, r0, lsr #32
 *   @0x2e7228 ldclt p0, c6, [r0, #-96]
 *   @0x2e722c ldclt p0, c2, [r0, #-256]
 *   @0x2e7230 andeq r7, r10, lr, lsr #10
 *   @0x2e7234 mvnsmi lr, sp, lsr #18
 *   @0x2e7238 ldrmi r4, [r0], -r5, lsl #12
 *   @0x2e723c sadd8mi r4, r7, r8
 *   @0x2e7240 ldmdb r10!, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x2e7244 .word 0x46044b10
 *   @0x2e7248 stmdavs r8!, {r2, r3, r4, r7, r9, lr}
 *   @0x2e724c stcne p12, c13, [r1, #88]!
 *   @0x2e7250 .word 0xf7ffaa01
 *   @0x2e7254 stcls p15, c15, [r1, #-416]
 *   @0x2e7258 stmiblt sp, {r1, r2, r9, r10, lr}
 *   @0x2e725c qasxmi r4, r2, r9
 *   @0x2e7260 stmib r12!, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc}
 *   @0x2e7264 ldmdbne r3!, {r0, r3, r9, r11, lr}
 *   @0x2e7268 ldmdavs r1, {r1, r3, r4, r5, r6, r10, lr}
 *   @0x2e726c .word 0x51318892
 *   @0x2e7270 blls 0x5074e0 <SrcVerts+0x64524>
 *   @0x2e7274 andvs pc, r0, r8, asr #17
 *   @0x2e7278 and r6, r1, sp, lsl r0
 *   @0x2e727c and r2, r0, r10
 *   @0x2e7280 andlt r4, r2, r8, lsr #12
 *   @0x2e7284 ldrhhi lr, [r0, #141]!
 *   @0x2e7288 svcvc #0xfffff9
 *   @0x2e728c andeq r7, r10, r10, ror #9
 *   @0x2e7290 .word 0x4606b5f7
 *   @0x2e7294 sadd16mi r4, pc, r0
 *   @0x2e7298 .word 0xf5cf4615
 *   @0x2e729c blmi 0x8217dc <b2_toiTime+0xc8338>
 *   @0x2e72a0 addsmi r4, r12, #4, #12
 *   @0x2e72a4 .word 0xdc1d6830
 *   @0x2e72a8 .word 0xf104aa01
 *   @0x2e72ac .word 0xf7ff0112
 *   @0x2e72b0 bls 0x366fa0 <_ZTS12CDS_Priority+0x8ff8>
 *   @0x2e72b4 ldmiblt r10!, {r1, r2, r9, r10, lr}
 *   @0x2e72b8 strtmi r4, [r2], -r9, lsr #12
 *   @0x2e72bc ldmdb lr!, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x2e72c0 ldrtmi r4, [r4], #-2316
 *   @0x2e72c4 .word 0xf1014479
 *   @0x2e72c8 .word 0xf8510310
 *   @0x2e72cc addsmi r2, r9, #4, #22
 *   @0x2e72d0 blhs 0x4253e8 <g_RomDisk+0x2dbc8>
 *   @0x2e72d4 stmdahi r11, {r0, r3, r4, r5, r6, r7, r8, r12, lr, pc}
 *   @0x2e72d8 eorhi r2, r3, r0
 *   @0x2e72dc eorsvs r9, lr, r8, lsl #22
 *   @0x2e72e0 and r6, r2, r8, lsl r0
 *   @0x2e72e4 and r2, r0, r10
 *   @0x2e72e8 andlt r4, r3, r0, lsl r6
 *   @0x2e72ec svclt #0xbdf0
 *   @0x2e72f0 svcvc #0xffffed
 *
 * ══ §52/76 FT_Raccess_Get_DataOffsets  0x2e85b8  size 396  99 条（0x2e85b8..0x2e8744）
 * @func 0x2e85b8 0x2e8744  size 396  99 条
 * 部分覆盖: 本节 99/175 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Stream_ReadUShort×4 / FT_Raccess_Get_DataOffsets+0x86 / 0x467588 / FT_Raccess_Get_DataOffsets+0x46 / FT_Stream_Seek / FT_Stream_Skip / 0x4674e4 / anon_2f1de8+0x28e0
 * 字段偏移 top8: 0x14×7 / 0x4c×1 / 0x-4×1 / 0x54×1 / 0x4×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e85b8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e85bc sub sp, #0x1c
 *   @0x2e85c0 strmi r8, [r12], -r0
 *   @0x2e85c4 mov r0, r1
 *   @0x2e85c8 mov r10, r2
 *   @0x2e85cc ldr r6, [sp, #0x4c]
 *   @0x2e85d0 andls pc, r5, r10, ror #18
 *   @0x2e85d4 cmp r0, #0x0
 *   @0x2e85d8 stcge p0, c8, [r5, #-704]
 *   @0x2e85dc mov r0, r4
 *   @0x2e85e0 bl 0x2e6b04 <FT_Stream_ReadUShort>
 *   @0x2e85e4 ldr r7, [sp, #0x14]
 *   @0x2e85e8 bne.w 0x2e8738 <FT_Raccess_Get_DataOffsets+0x180>
 *   @0x2e85ec sxth.w r9, r0
 *   @0x2e85f0 add.w r9, r9, #0x1
 *   @0x2e85f4 cmp.w r9, #0xff0
 *   @0x2e85f8 blt 0x2e863e <FT_Raccess_Get_DataOffsets+0x86>
 *   @0x2e85fc b 0x2e873a <FT_Raccess_Get_DataOffsets+0x182>
 *   @0x2e8600 mov r1, r5
 *   @0x2e8604 blls 0x467588 <g_RomDisk+0x6fd68>
 *   @0x2e8608 mov r11, r0
 *   @0x2e860c bne.w 0x2e8730 <FT_Raccess_Get_DataOffsets+0x178>
 *   @0x2e8610 mov r0, r4
 *   @0x2e8614 bl 0x2e6b04 <FT_Stream_ReadUShort>
 *   @0x2e8618 ldr r2, [sp, #0x14]
 *   @0x2e861c cmp r2, #0x0
 *   @0x2e8620 strtmi r8, [r9], -r7, lsl #1
 *   @0x2e8624 mov r0, r4
 *   @0x2e8628 bl 0x2e6b04 <FT_Stream_ReadUShort>
 *   @0x2e862c ldr r2, [sp, #0x14]
 *   @0x2e8630 mov r1, r0
 *   @0x2e8634 bne 0x2e8730 <FT_Raccess_Get_DataOffsets+0x178>
 *   @0x2e8638 cmp r11, r2
 *   @0x2e863c adds r7, #0x1
 *   @0x2e8640 blt 0x2e85fe <FT_Raccess_Get_DataOffsets+0x46>
 *   @0x2e8644 sxth r3, r3
 *   @0x2e8648 str r2, [r6]
 *   @0x2e864c addsmi r2, r3, #1610612746
 *   @0x2e8650 bhi 0x2e85fa <FT_Raccess_Get_DataOffsets+0x42>
 *   @0x2e8654 sxtah r1, r10, r1
 *   @0x2e8658 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e865c mov r2, r0
 *   @0x2e8660 cmp r0, #0x0
 *   @0x2e8664 stm.w sp, {r2, r5}
 *   @0x2e8668 mov r0, r8
 *   @0x2e866c ldr r3, [r6]
 *   @0x2e8670 strmi pc, [r1], lr, lsl #26
 *   @0x2e8674 ldr r0, [sp, #0x14]
 *   @0x2e8678 bne 0x2e873a <FT_Raccess_Get_DataOffsets+0x182>
 *   @0x2e867c mov r10, r0
 *   @0x2e8680 cmp r10, r1
 *   @0x2e8684 mov r0, r4
 *   @0x2e8688 bl 0x2e6b04 <FT_Stream_ReadUShort>
 *   @0x2e868c strh r0, [r7]
 *   @0x2e8690 cmp r3, #0x0
 *   @0x2e8694 mov r0, r4
 *   @0x2e8698 bl 0x2e6930 <FT_Stream_Skip>
 *   @0x2e869c str r0, [sp, #0x14]
 *   @0x2e86a0 bne 0x2e8728 <FT_Raccess_Get_DataOffsets+0x170>
 *   @0x2e86a4 mov r1, r5
 *   @0x2e86a8 blls 0x4674e4 <g_RomDisk+0x6fcc4>
 *   @0x2e86ac mov r11, r0
 *   @0x2e86b0 bne 0x2e8728 <FT_Raccess_Get_DataOffsets+0x170>
 *   @0x2e86b4 movs r1, #0x4
 *   @0x2e86b8 andls pc, r5, r11, lsr r9
 *   @0x2e86bc cbnz r0, 0x2e8728 <FT_Raccess_Get_DataOffsets+0x170>
 *   @0x2e86c0 blhs 0x2f46c8 <ps_hints_apply+0x32c8>
 *   @0x2e86c4 blt 0x2e86d0 <FT_Raccess_Get_DataOffsets+0x118>
 *   @0x2e86c8 .word 0xf1070f00
 *   @0x2e86cc ble 0x32a2f4
 *   @0x2e86d0 movs r3, #0x8
 *   @0x2e86d4 bic r3, r11, #0xff000000
 *   @0x2e86d8 add.w r10, r10, #0x1
 *   @0x2e86dc str r3, [r7, #-4]
 *   @0x2e86e0 b 0x2e867e <FT_Raccess_Get_DataOffsets+0xc6>
 *   @0x2e86e4 .word 0xb12b3044
 *   @0x2e86e8 ldr r3, [pc, #0x54]
 *   @0x2e86ec movs r2, #0x8
 *   @0x2e86f0 blx 0xb66dc <qsort@plt>
 *   @0x2e86f4 movs r2, #0x0
 *   @0x2e86f8 stm.w sp, {r2, r5}
 *   @0x2e86fc movs r1, #0x4
 *   @0x2e8700 bl 0x2e808e <ft_mem_realloc>
 *   @0x2e8704 ldr r3, [sp, #0x14]
 *   @0x2e8708 ldr r2, [r6]
 *   @0x2e870c bge 0x2e8720 <FT_Raccess_Get_DataOffsets+0x168>
 *   @0x2e8710 stmdbls r3, {r0, r1, r6, r7, r9}
 *   @0x2e8714 ldr r2, [r2, #0x4]
 *   @0x2e8718 str.w r2, [r0, r3, lsl #2]
 *   @0x2e871c adds r3, #0x1
 *   @0x2e8720 ldr r3, [sp, #0x48]
 *   @0x2e8724 movs r3, #0x0
 *   @0x2e8728 mov r0, r8
 *   @0x2e872c bl 0x2e7336 <ft_mem_free>
 *   @0x2e8730 ldr r0, [sp, #0x14]
 *   @0x2e8734 movs r0, #0x1
 *   @0x2e8738 mov r0, r7
 *   @0x2e873c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e8740 stm r3!, {r0, r1, r2, r3, r4, r6}
 *
 * ══ §53/76 F_TextureGetUVs(RValue&, CInstance*, CInstance*, int, RValue*)  0x12156c  size 392  98 条（0x12156c..0x1216f4）
 * @func 0x12156c 0x1216f4  size 392  98 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateArray(RValue*, int, ...)×2 / YYGetPtrOrInt(RValue const*, int) / F_TextureGetUVs(RValue&, CInstance*, CInstance*, int, RValue*)+0x38
 * 字段偏移 top8: 0x48×1 / 0x164×1 / 0x4×1 / 0x2×1
 * VFP 指令 45 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12156c push {r4, r5, r6, lr}
 *   @0x121570 sub sp, sp, #56
 *   @0x121574 mov r6, r0
 *   @0x121578 mov r1, #0
 *   @0x12157c ldr r0, [sp, #0x48]
 *   @0x121580 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x121584 ldr r3, [pc, #0x164]
 *   @0x121588 ldr r3, [pc, r3]
 *   @0x12158c ldr r2, [r3]
 *   @0x121590 cmp r0, r2
 *   @0x121594 mov r12, r0
 *   @0x121598 bls 0x1215a4 <_Z15F_TextureGetUVsR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x12159c cmn r0, #1
 *   @0x1215a0 bne 0x1215e8 <_Z15F_TextureGetUVsR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x1215a4 mov r4, #0
 *   @0x1215a8 mov r2, #0
 *   @0x1215ac mov r3, #0
 *   @0x1215b0 mov r0, r6
 *   @0x1215b4 mov r1, #8
 *   @0x1215b8 strd r2, r3, [sp]
 *   @0x1215bc strd r2, r3, [sp, #24]
 *   @0x1215c0 mov r5, #0
 *   @0x1215c4 strd r2, r3, [sp, #32]
 *   @0x1215c8 movt r5, #0x3ff0
 *   @0x1215cc strd r4, r5, [sp, #8]
 *   @0x1215d0 strd r4, r5, [sp, #16]
 *   @0x1215d4 strd r4, r5, [sp, #40]
 *   @0x1215d8 strd r4, r5, [sp, #48]
 *   @0x1215dc bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x1215e0 add sp, sp, #56
 *   @0x1215e4 pop {r4, r5, r6, pc}
 *   @0x1215e8 ldrsh r4, [r0, #20]
 *   @0x1215ec vmov.f32 s13, #1.000000e+00
 *   @0x1215f0 ldr r3, [r3, #0x4]
 *   @0x1215f4 mov r0, r6
 *   @0x1215f8 ldrsh r2, [r12, #2]
 *   @0x1215fc mov r1, #8
 *   @0x121600 ldrsh lr, [r12]
 *   @0x121604 ldr r3, [r3, r4, lsl #2]
 *   @0x121608 vmov s12, r2
 *   @0x12160c ldr r3, [r3]
 *   @0x121610 vldr s15, [r3, #8]
 *   @0x121614 vldr s9, [r3, #4]
 *   @0x121618 vcvt.f32.s32 s15, s15
 *   @0x12161c vdiv.f32 s15, s13, s15
 *   @0x121620 vcvt.f32.s32 s9, s9
 *   @0x121624 vcvt.f32.s32 s10, s12
 *   @0x121628 vdiv.f32 s9, s13, s9
 *   @0x12162c vmov s13, lr
 *   @0x121630 vmul.f32 s10, s10, s15
 *   @0x121634 vcvt.f64.f32 d5, s10
 *   @0x121638 vstr d5, [sp]
 *   @0x12163c ldrsh r3, [r12, #12]
 *   @0x121640 vcvt.f32.s32 s14, s13
 *   @0x121644 add r3, lr, r3
 *   @0x121648 vmov s12, r3
 *   @0x12164c vcvt.f32.s32 s12, s12
 *   @0x121650 vmul.f32 s12, s12, s9
 *   @0x121654 vcvt.f64.f32 d6, s12
 *   @0x121658 vstr d6, [sp, #8]
 *   @0x12165c ldrsh r3, [r12, #14]
 *   @0x121660 vmul.f32 s9, s14, s9
 *   @0x121664 add r3, r2, r3
 *   @0x121668 vmov s14, r3
 *   @0x12166c vcvt.f32.s32 s14, s14
 *   @0x121670 vmul.f32 s14, s14, s15
 *   @0x121674 vcvt.f64.f32 d7, s14
 *   @0x121678 vstr d7, [sp, #16]
 *   @0x12167c ldrsh r3, [r12, #8]
 *   @0x121680 vcvt.f64.f32 d6, s9
 *   @0x121684 vmov s14, r3
 *   @0x121688 vcvt.f64.s32 d7, s14
 *   @0x12168c vmov r2, r3, d6
 *   @0x121690 vstr d7, [sp, #24]
 *   @0x121694 ldrsh lr, [r12, #10]
 *   @0x121698 vmov s14, lr
 *   @0x12169c vcvt.f64.s32 d7, s14
 *   @0x1216a0 vstr d7, [sp, #32]
 *   @0x1216a4 ldrsh lr, [r12, #4]
 *   @0x1216a8 vmov s12, lr
 *   @0x1216ac ldrsh lr, [r12, #16]
 *   @0x1216b0 vcvt.f64.s32 d6, s12
 *   @0x1216b4 vmov s14, lr
 *   @0x1216b8 vcvt.f64.s32 d7, s14
 *   @0x1216bc vdiv.f64 d7, d6, d7
 *   @0x1216c0 vstr d7, [sp, #40]
 *   @0x1216c4 ldrsh lr, [r12, #6]
 *   @0x1216c8 ldrsh r12, [r12, #18]
 *   @0x1216cc vmov s12, lr
 *   @0x1216d0 vmov s14, r12
 *   @0x1216d4 vcvt.f64.s32 d6, s12
 *   @0x1216d8 vcvt.f64.s32 d7, s14
 *   @0x1216dc vdiv.f64 d7, d6, d7
 *   @0x1216e0 vstr d7, [sp, #48]
 *   @0x1216e4 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x1216e8 add sp, sp, #56
 *   @0x1216ec pop {r4, r5, r6, pc}
 *   @0x1216f0 mlaeq r12, r4, r3, r12
 *
 * ══ §54/76 HttpBufferRequestCallback(HTTP_REQ_CONTEXT*, void*, int*)  0x138ce8  size 392  96 条（0x138ce8..0x138e70）
 * @func 0x138ce8 0x138e70  size 392  96 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool) / CreateDsMap(int, ...)
 * 字段偏移 top8: 0x10×3 / 0x1c×2 / 0x34×2 / 0x3c×2 / 0x4×2 / 0x24×2 / 0x20×2 / 0xb4×2
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x138ce8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x138cec sub sp, sp, #120
 *   @0x138cf0 ldr r6, [r0, #0x1c]
 *   @0x138cf4 mvn r3, #0
 *   @0x138cf8 str r3, [sp]
 *   @0x138cfc mov r4, #0
 *   @0x138d00 mov r5, r0
 *   @0x138d04 ldr r1, [r0, #0x34]
 *   @0x138d08 ldr lr, [r6, #0x1c]
 *   @0x138d0c mov r12, #1
 *   @0x138d10 mov r7, r2
 *   @0x138d14 mov r3, r4
 *   @0x138d18 ldr r2, [r5, #0x3c]
 *   @0x138d1c mov r0, r6
 *   @0x138d20 str lr, [sp, #0x4]
 *   @0x138d24 str r12, [sp, #0x8]
 *   @0x138d28 str r4, [sp, #0xc]
 *   @0x138d2c str r4, [sp, #0x10]
 *   @0x138d30 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb>
 *   @0x138d34 ldr r3, [r6]
 *   @0x138d38 mov r1, r4
 *   @0x138d3c ldr r8, [pc, #0x10c]
 *   @0x138d40 ldr r3, [r3, #0x10]
 *   @0x138d44 add r8, pc, r8
 *   @0x138d48 mov r2, r0
 *   @0x138d4c mov r0, r6
 *   @0x138d50 blx r3
 *   @0x138d54 ldr r3, [r5, #0x3c]
 *   @0x138d58 vmov.f64 d5, #-1.000000e+00
 *   @0x138d5c vldr s6, [r6, #28]
 *   @0x138d60 ldr r10, [r5, #0x2c]
 *   @0x138d64 cmp r3, r4
 *   @0x138d68 vmov s9, r3
 *   @0x138d6c ldr r2, [r5, #0x24]
 *   @0x138d70 vldr s8, [r5, #40]
 *   @0x138d74 vldr d7, [pc, #204]
 *   @0x138d78 vstr d7, [sp, #8]
 *   @0x138d7c ldr r9, [r5, #0x20]
 *   @0x138d80 ldr r1, [pc, #0xcc]
 *   @0x138d84 mov r0, #8
 *   @0x138d88 ldr r6, [pc, #0xc8]
 *   @0x138d8c add r1, pc, r1
 *   @0x138d90 ldr r5, [pc, #0xc4]
 *   @0x138d94 str r1, [sp, #0x54]
 *   @0x138d98 add r6, pc, r6
 *   @0x138d9c ldr lr, [pc, #0xbc]
 *   @0x138da0 add r5, pc, r5
 *   @0x138da4 vcvt.f64.s32 d3, s6
 *   @0x138da8 ldr r12, [pc, #0xb4]
 *   @0x138dac ldr r3, [pc, #0xb4]
 *   @0x138db0 add lr, pc, lr
 *   @0x138db4 ldr r1, [pc, #0xb0]
 *   @0x138db8 add r12, pc, r12
 *   @0x138dbc str r4, [sp]
 *   @0x138dc0 add r3, pc, r3
 *   @0x138dc4 str r4, [sp, #0x20]
 *   @0x138dc8 add r1, pc, r1
 *   @0x138dcc str r3, [sp, #0x64]
 *   @0x138dd0 str r4, [sp, #0x30]
 *   @0x138dd4 vcvt.f64.s32 d6, s9
 *   @0x138dd8 vstr d3, [sp, #24]
 *   @0x138ddc vmov s7, r10
 *   @0x138de0 str r4, [sp, #0x40]
 *   @0x138de4 str r4, [sp, #0x50]
 *   @0x138de8 str r4, [sp, #0x60]
 *   @0x138dec str r4, [sp, #0x70]
 *   @0x138df0 str r9, [sp, #0x10]
 *   @0x138df4 str r8, [sp, #0x4]
 *   @0x138df8 vmovle.f64 d7, d5
 *   @0x138dfc vstr d7, [sp, #104]
 *   @0x138e00 vmov s15, r2
 *   @0x138e04 vstr d6, [sp, #72]
 *   @0x138e08 vstr d6, [sp, #88]
 *   @0x138e0c str r6, [sp, #0x14]
 *   @0x138e10 str r5, [sp, #0x24]
 *   @0x138e14 vcvt.f64.s32 d4, s8
 *   @0x138e18 str lr, [sp, #0x34]
 *   @0x138e1c str r12, [sp, #0x44]
 *   @0x138e20 vcvt.f64.s32 d6, s7
 *   @0x138e24 vstr d4, [sp, #40]
 *   @0x138e28 vcvt.f64.s32 d7, s15
 *   @0x138e2c vstr d6, [sp, #56]
 *   @0x138e30 vmov r2, r3, d7
 *   @0x138e34 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x138e38 str r0, [r7]
 *   @0x138e3c mov r0, #62
 *   @0x138e40 add sp, sp, #120
 *   @0x138e44 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x138e50 eoreq r7, r0, r8, lsl #7
 *   @0x138e54 eoreq r7, r0, r8, ror #6
 *   @0x138e58 andseq lr, pc, r0, asr #3
 *   @0x138e5c andseq r7, pc, r4, lsr #25
 *   @0x138e60 eoreq r7, r0, r0, lsr #6
 *   @0x138e64 eoreq r7, r0, r12, lsr #6
 *   @0x138e68 mulseq pc, r0, r12
 *   @0x138e6c andseq r7, pc, r8, ror r12
 *
 * ══ §55/76 F_GPUSetFog(RValue&, CInstance*, CInstance*, int, RValue*)  0x149010  size 392  98 条（0x149010..0x149198）
 * @func 0x149010 0x149198  size 392  98 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetFloat(RValue const*, int)×4 / RenderStateManager::SetRenderState(eRenderState, unsigned int)×3 / GR_Color_To_D3DColor(unsigned int, unsigned int)
 * 字段偏移 top8: 0x4×8 / 0xc×2 / 0x18×1 / 0x12c×1 / 0x11c×1 / 0xa4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x149010 cmp r3, #1
 *   @0x149014 cmpne r3, #4
 *   @0x149018 mov r2, #0
 *   @0x14901c push {r4, r5, r6, r7, r8, lr}
 *   @0x149020 mov r1, r2
 *   @0x149024 moveq r12, #0
 *   @0x149028 movne r12, #1
 *   @0x14902c movt r2, #0xbff0
 *   @0x149030 str r1, [r0, #0xc]
 *   @0x149034 stm r0, {r1, r2}
 *   @0x149038 ldr r4, [sp, #0x18]
 *   @0x14903c bne 0x14906c <_Z11F_GPUSetFogR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x149040 cmp r3, #4
 *   @0x149044 beq 0x149148 <_Z11F_GPUSetFogR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x149048 ldr r5, [r4, #0xc]
 *   @0x14904c bic r5, r5, #-16777216
 *   @0x149050 cmp r5, #2
 *   @0x149054 beq 0x14907c <_Z11F_GPUSetFogR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x149058 ldr r0, [pc, #0x12c]
 *   @0x14905c mov r1, #0
 *   @0x149060 pop {r4, r5, r6, r7, r8, lr}
 *   @0x149064 add r0, pc, r0
 *   @0x149068 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14906c ldr r0, [pc, #0x11c]
 *   @0x149070 pop {r4, r5, r6, r7, r8, lr}
 *   @0x149074 add r0, pc, r0
 *   @0x149078 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14907c ldr r3, [r4]
 *   @0x149080 ldr r3, [r3, #0x4]
 *   @0x149084 ldr r2, [r3]
 *   @0x149088 cmp r2, #4
 *   @0x14908c bne 0x149058 <_Z11F_GPUSetFogR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x149090 mov r1, r12
 *   @0x149094 ldr r0, [r3, #0x4]
 *   @0x149098 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14909c ldr r3, [r4]
 *   @0x1490a0 mov r1, #1
 *   @0x1490a4 ldr r3, [r3, #0x4]
 *   @0x1490a8 mov r6, r0
 *   @0x1490ac ldr r0, [r3, #0x4]
 *   @0x1490b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1490b4 ldr r3, [r4]
 *   @0x1490b8 mov r1, r5
 *   @0x1490bc ldr r3, [r3, #0x4]
 *   @0x1490c0 mov r8, r0
 *   @0x1490c4 ldr r0, [r3, #0x4]
 *   @0x1490c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1490cc ldr r3, [r4]
 *   @0x1490d0 mov r1, #3
 *   @0x1490d4 ldr r3, [r3, #0x4]
 *   @0x1490d8 mov r7, r0
 *   @0x1490dc ldr r0, [r3, #0x4]
 *   @0x1490e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1490e4 mov r5, r0
 *   @0x1490e8 ldr r4, [pc, #0xa4]
 *   @0x1490ec mov r1, #13
 *   @0x1490f0 mov r2, r6
 *   @0x1490f4 ldr r4, [pc, r4]
 *   @0x1490f8 mov r0, r4
 *   @0x1490fc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x149100 cmp r6, #0
 *   @0x149104 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x149108 mov r0, r8
 *   @0x14910c mov r1, #255
 *   @0x149110 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x149114 mov r1, #15
 *   @0x149118 mov r2, r0
 *   @0x14911c mov r0, r4
 *   @0x149120 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x149124 mov r0, r4
 *   @0x149128 mov r2, r7
 *   @0x14912c mov r1, #17
 *   @0x149130 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x149134 mov r0, r4
 *   @0x149138 mov r2, r5
 *   @0x14913c mov r1, #18
 *   @0x149140 pop {r4, r5, r6, r7, r8, lr}
 *   @0x149144 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x149148 mov r1, r12
 *   @0x14914c mov r0, r4
 *   @0x149150 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149154 mov r1, #1
 *   @0x149158 mov r6, r0
 *   @0x14915c mov r0, r4
 *   @0x149160 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149164 mov r1, #2
 *   @0x149168 mov r8, r0
 *   @0x14916c mov r0, r4
 *   @0x149170 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x149174 mov r1, #3
 *   @0x149178 mov r7, r0
 *   @0x14917c mov r0, r4
 *   @0x149180 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x149184 mov r5, r0
 *   @0x149188 b 0x1490e8 <_Z11F_GPUSetFogR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x14918c andseq r9, pc, r8, asr #13
 *   @0x149190 andseq r9, pc, r0, ror #12
 *   @0x149194 eoreq r4, r10, r4, lsl #24
 *
 * ══ §56/76 CLayerManager::BuildInstanceElementRuntimeData(CRoom*, CLayer*, CLayerInstanceElement*)  0x1b8048  size 392  98 条（0x1b8048..0x1b81d0）
 * @func 0x1b8048 0x1b81d0  size 392  98 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::BuildInstanceElementRuntimeData(CRoom*, CLayer*, CLayerInstanceElement*)+0x178
 * 字段偏移 top8: 0x8×5 / 0x14×3 / 0x20×3 / 0x1c×2 / 0x4×2 / 0xc×2 / 0x170×2 / 0x174×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b8048 push {r4, r5, r6, r7, r8}
 *   @0x1b804c ldr r4, [r2, #0x1c]
 *   @0x1b8050 cmp r4, #0
 *   @0x1b8054 blt 0x1b81c0 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x178>
 *   @0x1b8058 ldr r3, [pc, #0x168]
 *   @0x1b805c ldr r3, [pc, r3]
 *   @0x1b8060 ldm r3, {r3, r12}
 *   @0x1b8064 and r12, r4, r12
 *   @0x1b8068 ldr r3, [r3, r12, lsl #3]
 *   @0x1b806c cmp r3, #0
 *   @0x1b8070 bne 0x1b8084 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x3c>
 *   @0x1b8074 b 0x1b81c0 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x178>
 *   @0x1b8078 ldr r3, [r3, #0x4]
 *   @0x1b807c cmp r3, #0
 *   @0x1b8080 beq 0x1b81c0 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x178>
 *   @0x1b8084 ldr r12, [r3, #0x8]
 *   @0x1b8088 cmp r4, r12
 *   @0x1b808c bne 0x1b8078 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x30>
 *   @0x1b8090 ldr r4, [r3, #0xc]
 *   @0x1b8094 cmp r4, #0
 *   @0x1b8098 beq 0x1b81c0 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x178>
 *   @0x1b809c ldr r5, [r4, #0x170]
 *   @0x1b80a0 cmn r5, #1
 *   @0x1b80a4 beq 0x1b81a8 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x160>
 *   @0x1b80a8 ldrb r3, [r4, #0x174]
 *   @0x1b80ac cmp r3, #0
 *   @0x1b80b0 beq 0x1b81a8 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x160>
 *   @0x1b80b4 ldr r12, [r0, #0xd4]
 *   @0x1b80b8 cmp r12, #0
 *   @0x1b80bc bne 0x1b80d0 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x88>
 *   @0x1b80c0 b 0x1b81a8 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x160>
 *   @0x1b80c4 ldr r12, [r12, #0x68]
 *   @0x1b80c8 cmp r12, #0
 *   @0x1b80cc beq 0x1b81a8 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x160>
 *   @0x1b80d0 ldr r3, [r12]
 *   @0x1b80d4 cmp r5, r3
 *   @0x1b80d8 bne 0x1b80c4 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x7c>
 *   @0x1b80dc ldr r3, [r12, #0x58]
 *   @0x1b80e0 cmp r3, #0
 *   @0x1b80e4 bne 0x1b80f8 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0xb0>
 *   @0x1b80e8 b 0x1b80c4 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x7c>
 *   @0x1b80ec ldr r3, [r3, #0x14]
 *   @0x1b80f0 cmp r3, #0
 *   @0x1b80f4 beq 0x1b80c4 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0x7c>
 *   @0x1b80f8 ldr r0, [r3]
 *   @0x1b80fc cmp r0, #2
 *   @0x1b8100 bne 0x1b80ec <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0xa4>
 *   @0x1b8104 ldr r0, [r3, #0x20]
 *   @0x1b8108 cmp r0, r4
 *   @0x1b810c bne 0x1b80ec <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement+0xa4>
 *   @0x1b8110 ldr r0, [r3, #0x18]
 *   @0x1b8114 mvn r6, #0
 *   @0x1b8118 ldr r5, [r3, #0x14]
 *   @0x1b811c mov r8, #2
 *   @0x1b8120 cmp r0, #0
 *   @0x1b8124 ldr r7, [r12, #0x60]
 *   @0x1b8128 strne r5, [r0, #0x14]
 *   @0x1b812c add r7, r7, r6
 *   @0x1b8130 ldrne r5, [r3, #0x14]
 *   @0x1b8134 ldrne r0, [r3, #0x18]
 *   @0x1b8138 streq r5, [r12, #0x58]
 *   @0x1b813c cmp r5, #0
 *   @0x1b8140 streq r0, [r12, #0x5c]
 *   @0x1b8144 strne r0, [r5, #0x18]
 *   @0x1b8148 mov r0, #0
 *   @0x1b814c ldr r5, [pc, #0x78]
 *   @0x1b8150 str r7, [r12, #0x60]
 *   @0x1b8154 ldr r5, [pc, r5]
 *   @0x1b8158 str r0, [r3, #0x14]
 *   @0x1b815c str r0, [r3, #0x18]
 *   @0x1b8160 ldr r12, [r5]
 *   @0x1b8164 ldr r7, [r5, #0x8]
 *   @0x1b8168 cmp r12, r0
 *   @0x1b816c str r8, [r3]
 *   @0x1b8170 str r6, [r3, #0x4]
 *   @0x1b8174 add r7, r7, #1
 *   @0x1b8178 strb r0, [r3, #0x8]
 *   @0x1b817c str r0, [r3, #0xc]
 *   @0x1b8180 str r0, [r3, #0x10]
 *   @0x1b8184 str r0, [r3, #0x20]
 *   @0x1b8188 str r6, [r3, #0x1c]
 *   @0x1b818c str r7, [r5, #0x8]
 *   @0x1b8190 strne r3, [r12, #0x18]
 *   @0x1b8194 streq r3, [r5, #0x4]
 *   @0x1b8198 streq r3, [r5]
 *   @0x1b819c strne r3, [r5]
 *   @0x1b81a0 strne r12, [r3, #0x14]
 *   @0x1b81a4 strne r0, [r3, #0x18]
 *   @0x1b81a8 ldr r1, [r1]
 *   @0x1b81ac mov r3, #1
 *   @0x1b81b0 str r4, [r2, #0x20]
 *   @0x1b81b4 strb r3, [r4, #0x174]
 *   @0x1b81b8 str r1, [r4, #0x170]
 *   @0x1b81bc strb r3, [r2, #0x8]
 *   @0x1b81c0 pop {r4, r5, r6, r7, r8}
 *   @0x1b81c4 bx lr
 *   @0x1b81c8 eoreq r5, r3, r8, ror #23
 *   @0x1b81cc eoreq r8, r3, r0, lsl r7
 *
 * ══ §57/76 CDS_Grid::Value_Disk_Exists(RValue&, double, double, double, RValue*)  0x204acc  size 392  98 条（0x204acc..0x204c54）
 * @func 0x204acc 0x204c68  size 412  103 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598×2 / 0xb670c×2 / CDS_Grid::Value_Disk_Exists(RValue&, double, double, double, RValue*)+0x170 / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0x4×4 / 0xc×1 / 0x60×1 / 0x8×1 / 0x48×1
 * VFP 指令 50 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x204acc push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x204ad0 vpush {d8, d9, d10, d11, d12}
 *   @0x204ad4 vmov d12, r2, r3
 *   @0x204ad8 vldr d11, [sp, #88]
 *   @0x204adc mov r10, r1
 *   @0x204ae0 mov r6, #0
 *   @0x204ae4 vsub.f64 d6, d12, d11
 *   @0x204ae8 str r6, [r1, #0xc]
 *   @0x204aec str r6, [r1]
 *   @0x204af0 mov r11, r0
 *   @0x204af4 str r6, [r10, #0x4]
 *   @0x204af8 vmov r0, r1, d6
 *   @0x204afc bl 0xb6598 <floor@plt>
 *   @0x204b00 ldr r9, [r11, #0x4]
 *   @0x204b04 vldr d10, [sp, #80]
 *   @0x204b08 ldr r7, [sp, #0x60]
 *   @0x204b0c sub r9, r9, #1
 *   @0x204b10 vmov d7, r0, r1
 *   @0x204b14 vcmpe.f64 d7, #0
 *   @0x204b18 vmrs APSR_nzcv, fpscr
 *   @0x204b1c vcvtpl.s32.f64 s13, d7
 *   @0x204b20 vadd.f64 d7, d12, d11
 *   @0x204b24 vmovpl r6, s13
 *   @0x204b28 vmov r0, r1, d7
 *   @0x204b2c bl 0xb670c <ceil@plt>
 *   @0x204b30 vmov s11, r9
 *   @0x204b34 vcvt.f64.s32 d6, s11
 *   @0x204b38 vmov d7, r0, r1
 *   @0x204b3c vcmpe.f64 d6, d7
 *   @0x204b40 vmrs APSR_nzcv, fpscr
 *   @0x204b44 vcvtpl.s32.f64 s12, d7
 *   @0x204b48 vsub.f64 d7, d10, d11
 *   @0x204b4c vmovpl r9, s12
 *   @0x204b50 vmov r0, r1, d7
 *   @0x204b54 bl 0xb6598 <floor@plt>
 *   @0x204b58 ldr r5, [r11, #0x8]
 *   @0x204b5c vadd.f64 d6, d10, d11
 *   @0x204b60 sub r5, r5, #1
 *   @0x204b64 vmov d7, r0, r1
 *   @0x204b68 vcmpe.f64 d7, #0
 *   @0x204b6c vmov r0, r1, d6
 *   @0x204b70 vmrs APSR_nzcv, fpscr
 *   @0x204b74 vcvtpl.s32.f64 s11, d7
 *   @0x204b78 movmi r8, #0
 *   @0x204b7c vmovpl r8, s11
 *   @0x204b80 bl 0xb670c <ceil@plt>
 *   @0x204b84 vmov s11, r5
 *   @0x204b88 vcvt.f64.s32 d6, s11
 *   @0x204b8c vmov d7, r0, r1
 *   @0x204b90 vcmpe.f64 d6, d7
 *   @0x204b94 vmrs APSR_nzcv, fpscr
 *   @0x204b98 vcvtpl.s32.f64 s12, d7
 *   @0x204b9c vmovpl r5, s12
 *   @0x204ba0 cmp r6, r9
 *   @0x204ba4 bgt 0x204c34 <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0x168>
 *   @0x204ba8 cmp r8, r5
 *   @0x204bac bgt 0x204c3c <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0x170>
 *   @0x204bb0 vmov s13, r6
 *   @0x204bb4 mov r4, r8
 *   @0x204bb8 vmul.f64 d9, d11, d11
 *   @0x204bbc vcvt.f64.s32 d8, s13
 *   @0x204bc0 vsub.f64 d8, d8, d12
 *   @0x204bc4 vmul.f64 d8, d8, d8
 *   @0x204bc8 b 0x204bd8 <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0x10c>
 *   @0x204bcc add r4, r4, #1
 *   @0x204bd0 cmp r5, r4
 *   @0x204bd4 blt 0x204c3c <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0x170>
 *   @0x204bd8 vmov s13, r4
 *   @0x204bdc vcvt.f64.s32 d7, s13
 *   @0x204be0 vsub.f64 d7, d7, d10
 *   @0x204be4 vmov.f64 d6, d8
 *   @0x204be8 vmla.f64 d6, d7, d7
 *   @0x204bec vcmpe.f64 d6, d9
 *   @0x204bf0 vmrs APSR_nzcv, fpscr
 *   @0x204bf4 bhi 0x204bcc <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0x100>
 *   @0x204bf8 ldr r0, [r11, #0x4]
 *   @0x204bfc mov r1, r7
 *   @0x204c00 ldr r3, [pc, #0x48]
 *   @0x204c04 ldr r12, [r11]
 *   @0x204c08 mla r0, r0, r4, r6
 *   @0x204c0c ldr r3, [pc, r3]
 *   @0x204c10 ldrd r2, r3, [r3]
 *   @0x204c14 add r0, r12, r0, lsl #4
 *   @0x204c18 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x204c1c cmp r0, #0
 *   @0x204c20 bne 0x204bcc <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0x100>
 *   @0x204c24 mov r3, #0
 *   @0x204c28 str r0, [r10]
 *   @0x204c2c movt r3, #0x3ff0
 *   @0x204c30 str r3, [r10, #0x4]
 *   @0x204c34 vpop {d8, d9, d10, d11, d12}
 *   @0x204c38 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x204c3c add r6, r6, #1
 *   @0x204c40 cmp r9, r6
 *   @0x204c44 bge 0x204ba8 <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_+0xdc>
 *   @0x204c48 vpop {d8, d9, d10, d11, d12}
 *   @0x204c4c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x204c50 andseq r12, lr, r8, ror r7
 *
 * ══ §58/76 DateFromTime(double)  0x244f60  size 392  98 条（0x244f60..0x2450e8）
 * @func 0x244f60 0x2450e8  size 392  98 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DayWithinYear(double) / InLeapYear(double) / MonthFromTime(double)
 * 字段偏移 top8: 无
 * VFP 指令 42 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244f60 push {r3, r4, r5, lr}
 *   @0x244f64 vpush {d8, d9}
 *   @0x244f68 mov r4, r0
 *   @0x244f6c mov r5, r1
 *   @0x244f70 bl 0x244c28 <_Z13DayWithinYeard>
 *   @0x244f74 vmov d8, r0, r1
 *   @0x244f78 mov r0, r4
 *   @0x244f7c mov r1, r5
 *   @0x244f80 bl 0x244be8 <_Z10InLeapYeard>
 *   @0x244f84 vmov d9, r0, r1
 *   @0x244f88 mov r0, r4
 *   @0x244f8c mov r1, r5
 *   @0x244f90 bl 0x244c68 <_Z13MonthFromTimed>
 *   @0x244f94 vmov d7, r0, r1
 *   @0x244f98 vcvt.s32.f64 s15, d7
 *   @0x244f9c vmov r0, s15
 *   @0x244fa0 cmp r0, #10
 *   @0x244fa4 addls pc, pc, r0, lsl #2
 *   @0x244fa8 b 0x245088 <_Z12DateFromTimed+0x128>
 *   @0x244fac b 0x244ff0 <_Z12DateFromTimed+0x90>
 *   @0x244fb0 b 0x244ffc <_Z12DateFromTimed+0x9c>
 *   @0x244fb4 b 0x245008 <_Z12DateFromTimed+0xa8>
 *   @0x244fb8 b 0x245018 <_Z12DateFromTimed+0xb8>
 *   @0x244fbc b 0x245028 <_Z12DateFromTimed+0xc8>
 *   @0x244fc0 b 0x245038 <_Z12DateFromTimed+0xd8>
 *   @0x244fc4 b 0x245048 <_Z12DateFromTimed+0xe8>
 *   @0x244fc8 b 0x245058 <_Z12DateFromTimed+0xf8>
 *   @0x244fcc b 0x245068 <_Z12DateFromTimed+0x108>
 *   @0x244fd0 b 0x245078 <_Z12DateFromTimed+0x118>
 *   @0x244fd4 b 0x244fd8 <_Z12DateFromTimed+0x78>
 *   @0x244fd8 vldr d7, [pc, #184]
 *   @0x244fdc vsub.f64 d8, d8, d7
 *   @0x244fe0 vsub.f64 d8, d8, d9
 *   @0x244fe4 vmov r0, r1, d8
 *   @0x244fe8 vpop {d8, d9}
 *   @0x244fec pop {r3, r4, r5, pc}
 *   @0x244ff0 vmov.f64 d7, #1.000000e+00
 *   @0x244ff4 vadd.f64 d8, d8, d7
 *   @0x244ff8 b 0x244fe4 <_Z12DateFromTimed+0x84>
 *   @0x244ffc vmov.f64 d7, #3.000000e+01
 *   @0x245000 vsub.f64 d8, d8, d7
 *   @0x245004 b 0x244fe4 <_Z12DateFromTimed+0x84>
 *   @0x245008 vldr d7, [pc, #144]
 *   @0x24500c vsub.f64 d8, d8, d7
 *   @0x245010 vsub.f64 d8, d8, d9
 *   @0x245014 b 0x244fe4 <_Z12DateFromTimed+0x84>
 *   @0x245018 vldr d7, [pc, #136]
 *   @0x24501c vsub.f64 d8, d8, d7
 *   @0x245020 vsub.f64 d8, d8, d9
 *   @0x245024 b 0x244fe4 <_Z12DateFromTimed+0x84>
 *   @0x245028 vldr d7, [pc, #128]
 *   @0x24502c vsub.f64 d8, d8, d7
 *   @0x245030 vsub.f64 d8, d8, d9
 *   @0x245034 b 0x244fe4 <_Z12DateFromTimed+0x84>
 *   @0x245038 vldr d7, [pc, #120]
 *   @0x24503c vsub.f64 d8, d8, d7
 *   @0x245040 vsub.f64 d8, d8, d9
 *   @0x245044 b 0x244fe4 <_Z12DateFromTimed+0x84>
 *   @0x245048 vldr d7, [pc, #112]
 *   @0x24504c vsub.f64 d8, d8, d7
 *   @0x245050 vsub.f64 d8, d8, d9
 *   @0x245054 b 0x244fe4 <_Z12DateFromTimed+0x84>
 *   @0x245058 vldr d7, [pc, #104]
 *   @0x24505c vsub.f64 d8, d8, d7
 *   @0x245060 vsub.f64 d8, d8, d9
 *   @0x245064 b 0x244fe4 <_Z12DateFromTimed+0x84>
 *   @0x245068 vldr d7, [pc, #96]
 *   @0x24506c vsub.f64 d8, d8, d7
 *   @0x245070 vsub.f64 d8, d8, d9
 *   @0x245074 b 0x244fe4 <_Z12DateFromTimed+0x84>
 *   @0x245078 vldr d7, [pc, #88]
 *   @0x24507c vsub.f64 d8, d8, d7
 *   @0x245080 vsub.f64 d8, d8, d9
 *   @0x245084 b 0x244fe4 <_Z12DateFromTimed+0x84>
 *   @0x245088 vldr d7, [pc, #80]
 *   @0x24508c vsub.f64 d8, d8, d7
 *   @0x245090 vsub.f64 d8, d8, d9
 *   @0x245094 b 0x244fe4 <_Z12DateFromTimed+0x84>
 *   @0x245098 andeq r0, r0, r0
 *   @0x24509c rsbsmi pc, r2, r0
 *   @0x2450a0 andeq r0, r0, r0
 *   @0x2450a4 submi r0, sp, r0
 *   @0x2450a8 andeq r0, r0, r0
 *   @0x2450ac subsmi r4, r6, r0
 *   @0x2450b0 andeq r0, r0, r0
 *   @0x2450b4 subsmi r12, sp, r0
 *   @0x2450b8 andeq r0, r0, r0
 *   @0x2450bc rsbmi r12, r2, r0
 *   @0x2450c0 andeq r0, r0, r0
 *   @0x2450c4 rsbmi r8, r6, r0
 *   @0x2450c8 andeq r0, r0, r0
 *   @0x2450cc rsbmi r6, r10, r0
 *   @0x2450d0 andeq r0, r0, r0
 *   @0x2450d4 rsbmi r4, lr, r0
 *   @0x2450d8 andeq r0, r0, r0
 *   @0x2450dc rsbsmi r0, r1, r0
 *   @0x2450e0 andeq r0, r0, r0
 *   @0x2450e4 rsbsmi sp, r4, r0
 *
 * ══ §59/76 Java_com_yoyogames_runner_RunnerJNILib_LoadPicForUserWithUrl  0x29401c  size 392  98 条（0x29401c..0x2941a4）
 * @func 0x29401c 0x2941a4  size 392  98 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / Sprite_Add(char const*, int, bool, bool, bool, bool, int, int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / YYStrDup(char const*) / operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool)
 * 字段偏移 top8: 0xc×4 / 0x2a4×2 / 0x4×2 / 0x8×2 / 0x2a8×2 / 0x120×1 / 0x114×1 / 0xcc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29401c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x294020 mov r4, r0
 *   @0x294024 sub sp, sp, #16
 *   @0x294028 mov r9, r2
 *   @0x29402c mov r8, r3
 *   @0x294030 bl 0x290614 <setJNIEnv>
 *   @0x294034 ldr r3, [r4]
 *   @0x294038 mov r1, r9
 *   @0x29403c mov r2, #0
 *   @0x294040 mov r0, r4
 *   @0x294044 ldr r3, [r3, #0x2a4]
 *   @0x294048 blx r3
 *   @0x29404c ldr r3, [r4]
 *   @0x294050 mov r1, r8
 *   @0x294054 mov r2, #0
 *   @0x294058 ldr r3, [r3, #0x2a4]
 *   @0x29405c mov r7, r0
 *   @0x294060 mov r0, r4
 *   @0x294064 blx r3
 *   @0x294068 ldr r1, [pc, #0x120]
 *   @0x29406c mov r2, r7
 *   @0x294070 add r1, pc, r1
 *   @0x294074 mov r6, r0
 *   @0x294078 ldr r0, [pc, #0x114]
 *   @0x29407c mov r3, r6
 *   @0x294080 ldr r0, [pc, r0]
 *   @0x294084 ldr r5, [r0]
 *   @0x294088 ldr r12, [r5]
 *   @0x29408c mov r0, r5
 *   @0x294090 ldr r12, [r12, #0xc]
 *   @0x294094 blx r12
 *   @0x294098 mov r12, #0
 *   @0x29409c mov r1, r12
 *   @0x2940a0 mov r2, r12
 *   @0x2940a4 mov r3, r12
 *   @0x2940a8 str r12, [sp]
 *   @0x2940ac str r12, [sp, #0x4]
 *   @0x2940b0 mov r0, r6
 *   @0x2940b4 str r12, [sp, #0x8]
 *   @0x2940b8 str r12, [sp, #0xc]
 *   @0x2940bc bl 0x1f114c <_Z10Sprite_AddPKcibbbbii>
 *   @0x2940c0 ldr r3, [r5]
 *   @0x2940c4 ldr r1, [pc, #0xcc]
 *   @0x2940c8 ldr r3, [r3, #0xc]
 *   @0x2940cc add r1, pc, r1
 *   @0x2940d0 mov r10, r0
 *   @0x2940d4 mov r0, r5
 *   @0x2940d8 mov r2, r10
 *   @0x2940dc blx r3
 *   @0x2940e0 ldr r1, [pc, #0xb4]
 *   @0x2940e4 movw r2, #0x9fe
 *   @0x2940e8 mov r3, #1
 *   @0x2940ec add r1, pc, r1
 *   @0x2940f0 mov r0, #8
 *   @0x2940f4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2940f8 mov r5, r0
 *   @0x2940fc mov r0, r7
 *   @0x294100 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x294104 cmp r7, #0
 *   @0x294108 cmpne r9, #0
 *   @0x29410c stm r5, {r0, r10}
 *   @0x294110 bne 0x294174 <Java_com_yoyogames_runner_RunnerJNILib_LoadPicForUserWithUrl+0x158>
 *   @0x294114 cmp r6, #0
 *   @0x294118 cmpne r8, #0
 *   @0x29411c beq 0x294138 <Java_com_yoyogames_runner_RunnerJNILib_LoadPicForUserWithUrl+0x11c>
 *   @0x294120 ldr r3, [r4]
 *   @0x294124 mov r1, r8
 *   @0x294128 mov r2, r6
 *   @0x29412c mov r0, r4
 *   @0x294130 ldr r3, [r3, #0x2a8]
 *   @0x294134 blx r3
 *   @0x294138 mov r0, #68
 *   @0x29413c bl 0x27c524 <_Znwj>
 *   @0x294140 ldr r3, [pc, #0x58]
 *   @0x294144 mov r2, #0
 *   @0x294148 str r5, [sp, #0x4]
 *   @0x29414c mov r1, r2
 *   @0x294150 ldr r3, [pc, r3]
 *   @0x294154 str r2, [sp]
 *   @0x294158 str r2, [sp, #0x8]
 *   @0x29415c mov r4, r0
 *   @0x294160 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0x294164 mov r3, #7
 *   @0x294168 str r3, [r4, #0xc]
 *   @0x29416c add sp, sp, #16
 *   @0x294170 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x294174 ldr r3, [r4]
 *   @0x294178 mov r1, r9
 *   @0x29417c mov r2, r7
 *   @0x294180 mov r0, r4
 *   @0x294184 ldr r3, [r3, #0x2a8]
 *   @0x294188 blx r3
 *   @0x29418c b 0x294114 <Java_com_yoyogames_runner_RunnerJNILib_LoadPicForUserWithUrl+0xf8>
 *   @0x294190 strheq r5, [r12], -r8
 *   @0x294194 andseq r9, r5, r0, asr #17
 *   @0x294198 muleq r12, r0, r0
 *   @0x29419c andeq r4, r12, r8, asr #32
 *   @0x2941a0 andseq sp, r5, r8, lsr r8
 *
 * ══ §60/76 png_check_keyword  0x2af5b0  size 392  98 条（0x2af5b0..0x2af738）
 * @func 0x2af5b0 0x2af738  size 392  98 条
 * 部分覆盖: 本节 98/185 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / png_check_keyword+0x60 / anon_2e9c78+0x5610 / png_warning / png_free
 * 字段偏移 top8: 0x4×2 / 0x160×1 / 0x13c×1 / 0x118×1 / 0x1×1 / 0x64×1 / 0x54×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af5b0 ldr r3, [pc, #0x160]
 *   @0x2af5b4 ldrbtmi r4, [r11], #-4080
 *   @0x2af5b8 ldr r3, [r3]
 *   @0x2af5bc sub sp, #0x3c
 *   @0x2af5c0 movs r7, #0x0
 *   @0x2af5c4 str r7, [r6]
 *   @0x2af5c8 str r3, [sp, #0x4]
 *   @0x2af5cc cbz r1, 0x2af5d8 <png_check_keyword+0x28>
 *   @0x2af5d0 blx 0xb6538 <strlen@plt>
 *   @0x2af5d4 mov r4, r0
 *   @0x2af5d8 ldr r1, [pc, #0x13c]
 *   @0x2af5dc add r1, pc
 *   @0x2af5e0 andhs pc, r0, r9, asr #30
 *   @0x2af5e4 b 0x2af700 <png_check_keyword+0x150>
 *   @0x2af5e8 adds r1, r4, #0x2
 *   @0x2af5ec pkhbtmi pc, r0, r4, lsl #23
 *   @0x2af5f0 str r0, [r6]
 *   @0x2af5f4 ldr.w r11, [pc, #0x124]
 *   @0x2af5f8 add.w r10, sp, #0xc
 *   @0x2af5fc mov.w r12, #0x20
 *   @0x2af600 add r11, pc
 *   @0x2af604 ldr r1, [pc, #0x118]
 *   @0x2af608 add r1, pc
 *   @0x2af60c cmp r3, #0x1f
 *   @0x2af610 movs r1, #0x28
 *   @0x2af614 mov r0, r10
 *   @0x2af618 .word 0xf606c000
 *   @0x2af61c .word 0x4628efd6
 *   @0x2af620 mov r1, r10
 *   @0x2af624 .word 0xf8ddff27
 *   @0x2af628 .word 0xf808c000
 *   @0x2af62c strlo r12, [r1, -r7]
 *   @0x2af630 ldrb.w r3, [r9, r7]
 *   @0x2af634 add.w r2, r8, r7
 *   @0x2af638 cmp r3, #0x0
 *   @0x2af63c b 0x2af64c <png_check_keyword+0x9c>
 *   @0x2af640 bhs 0xaf0044 <b2_toiTime+0x396ba0>
 *   @0x2af644 bls 0x2af610 <png_check_keyword+0x60>
 *   @0x2af648 ldrb r3, [r0, r7]!
 *   @0x2af64c strb r3, [r2]
 *   @0x2af650 ldr r0, [r6]
 *   @0x2af654 ldrb r2, [r0, r1]
 *   @0x2af658 bne 0x2af676 <png_check_keyword+0xc6>
 *   @0x2af65c mov r0, r5
 *   @0x2af660 add r1, pc
 *   @0x2af664 blls 0x2ef288 <FT_Done_Memory+0x5614>
 *   @0x2af668 subs r2, r7, r4
 *   @0x2af66c cmp r1, #0x20
 *   @0x2af670 strb r3, [r2, r4]
 *   @0x2af674 bne 0x2af66a <png_check_keyword+0xba>
 *   @0x2af678 ldrb r3, [r7]
 *   @0x2af67c bne 0x2af698 <png_check_keyword+0xe8>
 *   @0x2af680 mov r0, r5
 *   @0x2af684 bl 0x2a6474 <png_warning>
 *   @0x2af688 adds r1, r7, r4
 *   @0x2af68c mov r7, r3
 *   @0x2af690 ldrb r2, [r7]
 *   @0x2af694 cmp r2, #0x20
 *   @0x2af698 ldr r3, [r6]
 *   @0x2af69c movs r1, #0x0
 *   @0x2af6a0 ldrb r2, [r7, #1]!
 *   @0x2af6a4 cbz r2, 0x2af6c0 <png_check_keyword+0x110>
 *   @0x2af6a8 bne 0x2af6ba <png_check_keyword+0x10a>
 *   @0x2af6ac strb r2, [r3]
 *   @0x2af6b0 movs r0, #0x1
 *   @0x2af6b4 subs r4, #0x1
 *   @0x2af6b8 b 0x2af6b0 <png_check_keyword+0x100>
 *   @0x2af6bc adds r3, #0x1
 *   @0x2af6c0 strb r2, [r3]
 *   @0x2af6c4 ldr r1, [pc, #0x64]
 *   @0x2af6c8 add r1, pc
 *   @0x2af6cc stmdblt r12, {r0, r1, r4, r6, r7, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2af6d0 mov r0, r5
 *   @0x2af6d4 bl 0x2a6cfc <png_free>
 *   @0x2af6d8 ldr r1, [pc, #0x54]
 *   @0x2af6dc add r1, pc
 *   @0x2af6e0 and pc, r12, r9, asr #29
 *   @0x2af6e4 cmp r4, #0x4f
 *   @0x2af6e8 ldr r1, [pc, #0x48]
 *   @0x2af6ec add r1, pc
 *   @0x2af6f0 ldmdavs r3!, {r0, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2af6f4 movs r2, #0x0
 *   @0x2af6f8 strb.w r2, [r3, #0x4f]
 *   @0x2af6fc b 0x2af700 <png_check_keyword+0x150>
 *   @0x2af700 ldr r1, [sp, #0x4]
 *   @0x2af704 ldr r3, [r1]
 *   @0x2af708 beq 0x2af70e <png_check_keyword+0x15e>
 *   @0x2af70c andlt lr, pc, r4, ror #30
 *   @0x2af710 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2af714 b 0x2afe54 <png_write_info+0x40>
 *   @0x2af718 b 0x2af5e4 <png_check_keyword+0x34>
 *   @0x2af71c b 0x2af614 <png_check_keyword+0x64>
 *   @0x2af720 b 0x2af5bc <png_check_keyword+0xc>
 *   @0x2af724 b 0x2af59e <png_set_user_limits+0xa>
 *   @0x2af728 b 0x2af5a8 <png_set_chunk_malloc_max>
 *   @0x2af72c b 0x2af568 <png_set_compression_buffer_size+0x10>
 *   @0x2af730 b 0x2af59a <png_set_user_limits+0x6>
 *   @0x2af734 b 0x2af5a6 <png_set_chunk_cache_max+0x6>
 *
 * ══ §61/76 b2RevoluteJoint::Dump()  0x2d1358  size 392  98 条（0x2d1358..0x2d14e0）
 * @func 0x2d1358 0x2d14e0  size 392  98 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×13
 * 字段偏移 top8: 0x8×2 / 0x64×2 / 0x30×1 / 0x34×1 / 0x134×1 / 0x124×1 / 0x118×1 / 0x10c×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d1358 push {r4, r5, r6, lr}
 *   @0x2d135c mov r4, r0
 *   @0x2d1360 ldr r2, [r4, #0x30]
 *   @0x2d1364 sub sp, sp, #8
 *   @0x2d1368 ldr r3, [r4, #0x34]
 *   @0x2d136c ldr r0, [pc, #0x134]
 *   @0x2d1370 ldr r6, [r2, #0x8]
 *   @0x2d1374 add r0, pc, r0
 *   @0x2d1378 ldr r5, [r3, #0x8]
 *   @0x2d137c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d1380 ldr r0, [pc, #0x124]
 *   @0x2d1384 mov r1, r6
 *   @0x2d1388 add r0, pc, r0
 *   @0x2d138c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d1390 ldr r0, [pc, #0x118]
 *   @0x2d1394 mov r1, r5
 *   @0x2d1398 add r0, pc, r0
 *   @0x2d139c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d13a0 ldr r0, [pc, #0x10c]
 *   @0x2d13a4 ldrb r1, [r4, #0x3d]
 *   @0x2d13a8 add r0, pc, r0
 *   @0x2d13ac bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d13b0 vldr s13, [r4, #68]
 *   @0x2d13b4 vldr s14, [r4, #72]
 *   @0x2d13b8 vcvt.f64.f32 d5, s13
 *   @0x2d13bc ldr r0, [pc, #0xf4]
 *   @0x2d13c0 add r0, pc, r0
 *   @0x2d13c4 vcvt.f64.f32 d7, s14
 *   @0x2d13c8 vmov r2, r3, d5
 *   @0x2d13cc vstr d7, [sp]
 *   @0x2d13d0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d13d4 vldr s13, [r4, #76]
 *   @0x2d13d8 vldr s14, [r4, #80]
 *   @0x2d13dc vcvt.f64.f32 d5, s13
 *   @0x2d13e0 ldr r0, [pc, #0xd4]
 *   @0x2d13e4 add r0, pc, r0
 *   @0x2d13e8 vcvt.f64.f32 d7, s14
 *   @0x2d13ec vmov r2, r3, d5
 *   @0x2d13f0 vstr d7, [sp]
 *   @0x2d13f4 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d13f8 vldr s15, [r4, #116]
 *   @0x2d13fc vcvt.f64.f32 d6, s15
 *   @0x2d1400 ldr r0, [pc, #0xb8]
 *   @0x2d1404 add r0, pc, r0
 *   @0x2d1408 vmov r2, r3, d6
 *   @0x2d140c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d1410 ldr r0, [pc, #0xac]
 *   @0x2d1414 ldrb r1, [r4, #0x70]
 *   @0x2d1418 add r0, pc, r0
 *   @0x2d141c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d1420 vldr s15, [r4, #120]
 *   @0x2d1424 vcvt.f64.f32 d5, s15
 *   @0x2d1428 ldr r0, [pc, #0x98]
 *   @0x2d142c add r0, pc, r0
 *   @0x2d1430 vmov r2, r3, d5
 *   @0x2d1434 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d1438 vldr s15, [r4, #124]
 *   @0x2d143c vcvt.f64.f32 d6, s15
 *   @0x2d1440 ldr r0, [pc, #0x84]
 *   @0x2d1444 add r0, pc, r0
 *   @0x2d1448 vmov r2, r3, d6
 *   @0x2d144c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d1450 ldr r0, [pc, #0x78]
 *   @0x2d1454 ldrb r1, [r4, #0x64]
 *   @0x2d1458 add r0, pc, r0
 *   @0x2d145c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d1460 vldr s15, [r4, #108]
 *   @0x2d1464 vcvt.f64.f32 d5, s15
 *   @0x2d1468 ldr r0, [pc, #0x64]
 *   @0x2d146c add r0, pc, r0
 *   @0x2d1470 vmov r2, r3, d5
 *   @0x2d1474 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d1478 vldr s15, [r4, #104]
 *   @0x2d147c vcvt.f64.f32 d6, s15
 *   @0x2d1480 ldr r0, [pc, #0x50]
 *   @0x2d1484 add r0, pc, r0
 *   @0x2d1488 vmov r2, r3, d6
 *   @0x2d148c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d1490 ldr r0, [pc, #0x44]
 *   @0x2d1494 ldr r1, [r4, #0x38]
 *   @0x2d1498 add r0, pc, r0
 *   @0x2d149c add sp, sp, #8
 *   @0x2d14a0 pop {r4, r5, r6, lr}
 *   @0x2d14a4 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d14a8 andeq r10, r8, r12, asr pc
 *   @0x2d14ac andeq r10, r8, r4, lsr #22
 *   @0x2d14b0 andeq r10, r8, r0, lsr r11
 *   @0x2d14b4 andeq r10, r8, r12, lsr r11
 *   @0x2d14b8 andeq r10, r8, r8, asr #22
 *   @0x2d14bc andeq r10, r8, r0, asr r11
 *   @0x2d14c0 andeq r10, r8, r8, lsr #26
 *   @0x2d14c4 andeq r10, r8, r4, lsr sp
 *   @0x2d14c8 andeq r10, r8, r0, asr #29
 *   @0x2d14cc andeq r10, r8, r4, asr #29
 *   @0x2d14d0 andeq r10, r8, r12, asr sp
 *   @0x2d14d4 andeq r10, r8, r8, ror #26
 *   @0x2d14d8 andeq r10, r8, r0, lsr #29
 *   @0x2d14dc andeq r10, r8, r0, lsr #22
 *
 * ══ §62/76 b2GearJoint::SolveVelocityConstraints(b2SolverData const&)  0x2e38a4  size 392  98 条（0x2e38a4..0x2e3a2c）
 * @func 0x2e38a4 0x2e3a2c  size 392  98 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-4×1 / 0x1c×1 / 0xa0×1 / 0xa8×1 / 0xa4×1 / 0xac×1 / 0x4×1
 * VFP 指令 82 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e38a4 str r4, [sp, #-0x4]!
 *   @0x2e38a8 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e38ac vldr s13, [r0, #244]
 *   @0x2e38b0 vldr s15, [r0, #252]
 *   @0x2e38b4 ldr r4, [r1, #0x1c]
 *   @0x2e38b8 vldr s3, [r0, #264]
 *   @0x2e38bc ldr r12, [r0, #0xa0]
 *   @0x2e38c0 vldr s7, [r0, #268]
 *   @0x2e38c4 ldr r2, [r0, #0xa8]
 *   @0x2e38c8 vldr s12, [r0, #240]
 *   @0x2e38cc ldr r1, [r0, #0xa4]
 *   @0x2e38d0 vldr s14, [r0, #248]
 *   @0x2e38d4 ldr r3, [r0, #0xac]
 *   @0x2e38d8 add r12, r12, r12, lsl #1
 *   @0x2e38dc add r2, r2, r2, lsl #1
 *   @0x2e38e0 vldr s23, [r0, #256]
 *   @0x2e38e4 add r1, r1, r1, lsl #1
 *   @0x2e38e8 add r12, r4, r12, lsl #2
 *   @0x2e38ec add r3, r3, r3, lsl #1
 *   @0x2e38f0 add r2, r4, r2, lsl #2
 *   @0x2e38f4 add r1, r4, r1, lsl #2
 *   @0x2e38f8 vldr s20, [r12, #4]
 *   @0x2e38fc add r3, r4, r3, lsl #2
 *   @0x2e3900 vldr s1, [r2, #4]
 *   @0x2e3904 vldr s18, [r1, #4]
 *   @0x2e3908 vsub.f32 s8, s20, s1
 *   @0x2e390c vldr s5, [r3, #4]
 *   @0x2e3910 vldr s2, [r2, #8]
 *   @0x2e3914 vldr s6, [r3, #8]
 *   @0x2e3918 vldr s21, [r12]
 *   @0x2e391c vldr s0, [r2]
 *   @0x2e3920 vldr s19, [r1]
 *   @0x2e3924 vldr s4, [r3]
 *   @0x2e3928 vldr s17, [r0, #260]
 *   @0x2e392c vldr s22, [r12, #8]
 *   @0x2e3930 vldr s16, [r1, #8]
 *   @0x2e3934 vldr s29, [r0, #272]
 *   @0x2e3938 vldr s28, [r0, #224]
 *   @0x2e393c vldr s27, [r0, #208]
 *   @0x2e3940 vldr s26, [r0, #212]
 *   @0x2e3944 vldr s25, [r0, #228]
 *   @0x2e3948 vldr s24, [r0, #216]
 *   @0x2e394c vsub.f32 s9, s18, s5
 *   @0x2e3950 vmul.f32 s10, s3, s2
 *   @0x2e3954 vmul.f32 s11, s7, s6
 *   @0x2e3958 vmul.f32 s8, s8, s13
 *   @0x2e395c vmul.f32 s9, s9, s15
 *   @0x2e3960 vsub.f32 s31, s21, s0
 *   @0x2e3964 vsub.f32 s30, s19, s4
 *   @0x2e3968 vnmls.f32 s10, s23, s22
 *   @0x2e396c vmla.f32 s8, s31, s12
 *   @0x2e3970 vnmls.f32 s11, s17, s16
 *   @0x2e3974 vmla.f32 s9, s30, s14
 *   @0x2e3978 vadd.f32 s11, s10, s11
 *   @0x2e397c vldr s10, [r0, #220]
 *   @0x2e3980 vadd.f32 s9, s8, s9
 *   @0x2e3984 vldr s8, [r0, #232]
 *   @0x2e3988 vadd.f32 s9, s11, s9
 *   @0x2e398c vnmul.f32 s29, s29, s9
 *   @0x2e3990 vmul.f32 s27, s29, s27
 *   @0x2e3994 vmul.f32 s26, s29, s26
 *   @0x2e3998 vmul.f32 s28, s29, s28
 *   @0x2e399c vmul.f32 s25, s29, s25
 *   @0x2e39a0 vmul.f32 s24, s29, s24
 *   @0x2e39a4 vmul.f32 s11, s29, s10
 *   @0x2e39a8 vmul.f32 s9, s29, s8
 *   @0x2e39ac vldr s8, [r0, #236]
 *   @0x2e39b0 vmul.f32 s10, s29, s8
 *   @0x2e39b4 vmla.f32 s22, s23, s28
 *   @0x2e39b8 vmla.f32 s21, s27, s12
 *   @0x2e39bc vmla.f32 s20, s27, s13
 *   @0x2e39c0 vmla.f32 s19, s26, s14
 *   @0x2e39c4 vmla.f32 s18, s26, s15
 *   @0x2e39c8 vmla.f32 s16, s17, s25
 *   @0x2e39cc vmls.f32 s0, s24, s12
 *   @0x2e39d0 vmls.f32 s1, s24, s13
 *   @0x2e39d4 vmls.f32 s6, s7, s10
 *   @0x2e39d8 vldr s10, [r0, #156]
 *   @0x2e39dc vmls.f32 s2, s3, s9
 *   @0x2e39e0 vmls.f32 s4, s11, s14
 *   @0x2e39e4 vmls.f32 s5, s11, s15
 *   @0x2e39e8 vadd.f32 s29, s10, s29
 *   @0x2e39ec vstr s29, [r0, #156]
 *   @0x2e39f0 vstr s21, [r12]
 *   @0x2e39f4 vstr s22, [r12, #8]
 *   @0x2e39f8 vstr s20, [r12, #4]
 *   @0x2e39fc vstr s19, [r1]
 *   @0x2e3a00 vstr s18, [r1, #4]
 *   @0x2e3a04 vstr s16, [r1, #8]
 *   @0x2e3a08 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e3a0c vstr s0, [r2]
 *   @0x2e3a10 vstr s1, [r2, #4]
 *   @0x2e3a14 vstr s2, [r2, #8]
 *   @0x2e3a18 vstr s4, [r3]
 *   @0x2e3a1c vstr s5, [r3, #4]
 *   @0x2e3a20 vstr s6, [r3, #8]
 *   @0x2e3a24 ldr r4, [sp], #4
 *   @0x2e3a28 bx lr
 *
 * ══ §63/76 F_D3DBuildMatrixProjPersp(RValue&, CInstance*, CInstance*, int, RValue*)  0x146c94  size 388  97 条（0x146c94..0x146e18）
 * @func 0x146c94 0x146e2c  size 408  102 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / yyMatrix::PerspectiveLH(yyMatrix*, float, float, float, float) / CreateArray(RValue*, int, ...) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x100×1 / 0x14×1
 * VFP 指令 59 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x146c94 push {r4, r5, r6, lr}
 *   @0x146c98 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x146c9c sub sp, sp, #184
 *   @0x146ca0 mov r1, #0
 *   @0x146ca4 mov r5, r0
 *   @0x146ca8 ldr r4, [sp, #0x100]
 *   @0x146cac mov r0, r4
 *   @0x146cb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x146cb4 mov r1, #1
 *   @0x146cb8 vmov s17, r0
 *   @0x146cbc mov r0, r4
 *   @0x146cc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x146cc4 mov r1, #2
 *   @0x146cc8 vmov s16, r0
 *   @0x146ccc mov r0, r4
 *   @0x146cd0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x146cd4 mov r1, #3
 *   @0x146cd8 mov r6, r0
 *   @0x146cdc mov r0, r4
 *   @0x146ce0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x146ce4 vcmp.f32 s16, #0
 *   @0x146ce8 vmrs APSR_nzcv, fpscr
 *   @0x146cec vcmp.f32 s17, #0
 *   @0x146cf0 movne r2, #0
 *   @0x146cf4 moveq r2, #1
 *   @0x146cf8 vmrs APSR_nzcv, fpscr
 *   @0x146cfc orreq r2, r2, #1
 *   @0x146d00 cmp r2, #0
 *   @0x146d04 bne 0x146df8 <_Z25F_D3DBuildMatrixProjPerspR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x146d08 str r0, [sp]
 *   @0x146d0c mov r3, r6
 *   @0x146d10 add r0, sp, #120
 *   @0x146d14 vmov r1, s17
 *   @0x146d18 vmov r2, s16
 *   @0x146d1c bl 0x27b180 <_ZN8yyMatrix13PerspectiveLHEPS_ffff>
 *   @0x146d20 vldr s14, [sp, #124]
 *   @0x146d24 vcvt.f64.f32 d7, s14
 *   @0x146d28 vldr s26, [sp, #128]
 *   @0x146d2c vldr s24, [sp, #132]
 *   @0x146d30 vldr s22, [sp, #136]
 *   @0x146d34 vldr s20, [sp, #140]
 *   @0x146d38 vldr s18, [sp, #144]
 *   @0x146d3c vldr s16, [sp, #148]
 *   @0x146d40 vldr s0, [sp, #152]
 *   @0x146d44 vldr s2, [sp, #156]
 *   @0x146d48 vldr s4, [sp, #160]
 *   @0x146d4c vldr s6, [sp, #164]
 *   @0x146d50 vldr s8, [sp, #168]
 *   @0x146d54 vldr s10, [sp, #172]
 *   @0x146d58 vldr s12, [sp, #176]
 *   @0x146d5c vstr d7, [sp]
 *   @0x146d60 vldr s14, [sp, #180]
 *   @0x146d64 vcvt.f64.f32 d7, s14
 *   @0x146d68 vldr s28, [sp, #120]
 *   @0x146d6c mov r0, r5
 *   @0x146d70 mov r1, #16
 *   @0x146d74 vcvt.f64.f32 d0, s0
 *   @0x146d78 vstr d7, [sp, #112]
 *   @0x146d7c vcvt.f64.f32 d1, s2
 *   @0x146d80 vstr d0, [sp, #56]
 *   @0x146d84 vcvt.f64.f32 d2, s4
 *   @0x146d88 vstr d1, [sp, #64]
 *   @0x146d8c vcvt.f64.f32 d3, s6
 *   @0x146d90 vstr d2, [sp, #72]
 *   @0x146d94 vcvt.f64.f32 d4, s8
 *   @0x146d98 vstr d3, [sp, #80]
 *   @0x146d9c vcvt.f64.f32 d5, s10
 *   @0x146da0 vstr d4, [sp, #88]
 *   @0x146da4 vcvt.f64.f32 d6, s12
 *   @0x146da8 vstr d5, [sp, #96]
 *   @0x146dac vcvt.f64.f32 d7, s28
 *   @0x146db0 vstr d6, [sp, #104]
 *   @0x146db4 vcvt.f64.f32 d13, s26
 *   @0x146db8 vmov r2, r3, d7
 *   @0x146dbc vcvt.f64.f32 d12, s24
 *   @0x146dc0 vstr d13, [sp, #8]
 *   @0x146dc4 vcvt.f64.f32 d11, s22
 *   @0x146dc8 vstr d12, [sp, #16]
 *   @0x146dcc vcvt.f64.f32 d10, s20
 *   @0x146dd0 vstr d11, [sp, #24]
 *   @0x146dd4 vcvt.f64.f32 d9, s18
 *   @0x146dd8 vstr d10, [sp, #32]
 *   @0x146ddc vcvt.f64.f32 d8, s16
 *   @0x146de0 vstr d9, [sp, #40]
 *   @0x146de4 vstr d8, [sp, #48]
 *   @0x146de8 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x146dec add sp, sp, #184
 *   @0x146df0 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x146df4 pop {r4, r5, r6, pc}
 *   @0x146df8 ldr r0, [pc, #0x14]
 *   @0x146dfc mov r1, #1
 *   @0x146e00 add r0, pc, r0
 *   @0x146e04 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x146e08 add sp, sp, #184
 *   @0x146e0c vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x146e10 pop {r4, r5, r6, pc}
 *   @0x146e14 andseq r10, pc, r4, ror #22
 *
 * ══ §64/76 F_GPUSetBlendModeExtSepAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x1492bc  size 388  97 条（0x1492bc..0x149440）
 * @func 0x1492bc 0x149440  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×8 / RenderStateManager::SetRenderState(eRenderState, unsigned int)×4
 * 字段偏移 top8: 0x4×8 / 0xc×2 / 0x18×1 / 0x128×1 / 0x118×1 / 0xa0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1492bc cmp r3, #1
 *   @0x1492c0 cmpne r3, #4
 *   @0x1492c4 mov r2, #0
 *   @0x1492c8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1492cc mov r1, r2
 *   @0x1492d0 moveq r12, #0
 *   @0x1492d4 movne r12, #1
 *   @0x1492d8 movt r2, #0xbff0
 *   @0x1492dc str r1, [r0, #0xc]
 *   @0x1492e0 stm r0, {r1, r2}
 *   @0x1492e4 ldr r4, [sp, #0x18]
 *   @0x1492e8 bne 0x149318 <_Z28F_GPUSetBlendModeExtSepAlphaR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x1492ec cmp r3, #4
 *   @0x1492f0 beq 0x1493f0 <_Z28F_GPUSetBlendModeExtSepAlphaR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1492f4 ldr r5, [r4, #0xc]
 *   @0x1492f8 bic r5, r5, #-16777216
 *   @0x1492fc cmp r5, #2
 *   @0x149300 beq 0x149328 <_Z28F_GPUSetBlendModeExtSepAlphaR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x149304 ldr r0, [pc, #0x128]
 *   @0x149308 mov r1, #0
 *   @0x14930c pop {r4, r5, r6, r7, r8, lr}
 *   @0x149310 add r0, pc, r0
 *   @0x149314 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x149318 ldr r0, [pc, #0x118]
 *   @0x14931c pop {r4, r5, r6, r7, r8, lr}
 *   @0x149320 add r0, pc, r0
 *   @0x149324 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x149328 ldr r3, [r4]
 *   @0x14932c ldr r3, [r3, #0x4]
 *   @0x149330 ldr r2, [r3]
 *   @0x149334 cmp r2, #4
 *   @0x149338 bne 0x149304 <_Z28F_GPUSetBlendModeExtSepAlphaR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x14933c mov r1, r12
 *   @0x149340 ldr r0, [r3, #0x4]
 *   @0x149344 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149348 ldr r3, [r4]
 *   @0x14934c mov r1, #1
 *   @0x149350 ldr r3, [r3, #0x4]
 *   @0x149354 mov r8, r0
 *   @0x149358 ldr r0, [r3, #0x4]
 *   @0x14935c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149360 ldr r3, [r4]
 *   @0x149364 mov r1, r5
 *   @0x149368 ldr r3, [r3, #0x4]
 *   @0x14936c mov r7, r0
 *   @0x149370 ldr r0, [r3, #0x4]
 *   @0x149374 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149378 ldr r3, [r4]
 *   @0x14937c mov r1, #3
 *   @0x149380 ldr r3, [r3, #0x4]
 *   @0x149384 mov r6, r0
 *   @0x149388 ldr r0, [r3, #0x4]
 *   @0x14938c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149390 mov r5, r0
 *   @0x149394 ldr r4, [pc, #0xa0]
 *   @0x149398 mov r2, r8
 *   @0x14939c mov r1, #6
 *   @0x1493a0 ldr r4, [pc, r4]
 *   @0x1493a4 mov r0, r4
 *   @0x1493a8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1493ac mov r0, r4
 *   @0x1493b0 mov r2, r7
 *   @0x1493b4 mov r1, #7
 *   @0x1493b8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1493bc mov r0, r4
 *   @0x1493c0 mov r2, r6
 *   @0x1493c4 mov r1, #34
 *   @0x1493c8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1493cc mov r0, r4
 *   @0x1493d0 mov r2, r5
 *   @0x1493d4 mov r1, #35
 *   @0x1493d8 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1493dc mov r0, r4
 *   @0x1493e0 mov r1, #33
 *   @0x1493e4 mov r2, #1
 *   @0x1493e8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1493ec b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1493f0 mov r1, r12
 *   @0x1493f4 mov r0, r4
 *   @0x1493f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1493fc mov r1, #1
 *   @0x149400 mov r8, r0
 *   @0x149404 mov r0, r4
 *   @0x149408 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14940c mov r1, #2
 *   @0x149410 mov r7, r0
 *   @0x149414 mov r0, r4
 *   @0x149418 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14941c mov r1, #3
 *   @0x149420 mov r6, r0
 *   @0x149424 mov r0, r4
 *   @0x149428 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14942c mov r5, r0
 *   @0x149430 b 0x149394 <_Z28F_GPUSetBlendModeExtSepAlphaR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x149434 andseq r9, pc, r12, lsl #10
 *   @0x149438 ldrheq r9, [pc], -r8
 *   @0x14943c eoreq r4, r10, r8, asr r9
 *
 * ══ §65/76 BuildFrustum(yyMatrix*)  0x149b40  size 388  97 条（0x149b40..0x149cc4）
 * @func 0x149b40 0x149cc4  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 0x164×1 / 0x10×1
 * VFP 指令 84 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x149b40 push {r3, r4, r5, lr}
 *   @0x149b44 vpush {d8}
 *   @0x149b48 vldr s7, [r0, #16]
 *   @0x149b4c vldr s13, [r0, #28]
 *   @0x149b50 vadd.f32 s6, s13, s7
 *   @0x149b54 ldr r3, [pc, #0x164]
 *   @0x149b58 vldr s10, [r0]
 *   @0x149b5c vldr s12, [r0, #12]
 *   @0x149b60 ldr r3, [pc, r3]
 *   @0x149b64 vldr s14, [r0, #44]
 *   @0x149b68 vldr s8, [r0, #32]
 *   @0x149b6c vldr s15, [r0, #60]
 *   @0x149b70 vldr s9, [r0, #48]
 *   @0x149b74 vldr s11, [r0, #52]
 *   @0x149b78 add r4, r3, #8
 *   @0x149b7c add r5, r3, #104
 *   @0x149b80 vsub.f32 s7, s13, s7
 *   @0x149b84 vstr s6, [r3, #4]
 *   @0x149b88 vstr s7, [r3, #20]
 *   @0x149b8c vadd.f32 s6, s14, s8
 *   @0x149b90 vadd.f32 s7, s15, s9
 *   @0x149b94 vstr s6, [r3, #8]
 *   @0x149b98 vsub.f32 s5, s12, s10
 *   @0x149b9c vstr s7, [r3, #12]
 *   @0x149ba0 vsub.f32 s8, s14, s8
 *   @0x149ba4 vstr s5, [r3, #16]
 *   @0x149ba8 vsub.f32 s9, s15, s9
 *   @0x149bac vstr s8, [r3, #24]
 *   @0x149bb0 vstr s9, [r3, #28]
 *   @0x149bb4 vldr s8, [r0, #4]
 *   @0x149bb8 vsub.f32 s9, s12, s8
 *   @0x149bbc vadd.f32 s8, s12, s8
 *   @0x149bc0 vstr s9, [r3, #32]
 *   @0x149bc4 vldr s9, [r0, #20]
 *   @0x149bc8 vsub.f32 s6, s13, s9
 *   @0x149bcc vadd.f32 s9, s13, s9
 *   @0x149bd0 vstr s6, [r3, #36]
 *   @0x149bd4 vadd.f32 s7, s12, s10
 *   @0x149bd8 vldr s10, [r0, #36]
 *   @0x149bdc vstr s8, [r3, #48]
 *   @0x149be0 vstr s9, [r3, #52]
 *   @0x149be4 vsub.f32 s8, s14, s10
 *   @0x149be8 vstr s7, [r3]
 *   @0x149bec vsub.f32 s9, s15, s11
 *   @0x149bf0 vstr s8, [r3, #40]
 *   @0x149bf4 vadd.f32 s10, s14, s10
 *   @0x149bf8 vstr s9, [r3, #44]
 *   @0x149bfc vadd.f32 s11, s15, s11
 *   @0x149c00 vstr s10, [r3, #56]
 *   @0x149c04 vstr s11, [r3, #60]
 *   @0x149c08 vmov.f32 s16, #1.000000e+00
 *   @0x149c0c vldr s8, [r0, #8]
 *   @0x149c10 vstr s8, [r3, #64]
 *   @0x149c14 vldr s9, [r0, #24]
 *   @0x149c18 vstr s9, [r3, #68]
 *   @0x149c1c vldr s10, [r0, #40]
 *   @0x149c20 vstr s10, [r3, #72]
 *   @0x149c24 vldr s11, [r0, #56]
 *   @0x149c28 vstr s11, [r3, #76]
 *   @0x149c2c vsub.f32 s12, s12, s8
 *   @0x149c30 vsub.f32 s13, s13, s9
 *   @0x149c34 vstr s12, [r3, #80]
 *   @0x149c38 vsub.f32 s14, s14, s10
 *   @0x149c3c vstr s13, [r3, #84]
 *   @0x149c40 vsub.f32 s15, s15, s11
 *   @0x149c44 vstr s14, [r3, #88]
 *   @0x149c48 vstr s15, [r3, #92]
 *   @0x149c4c vldr s13, [r4, #-4]
 *   @0x149c50 vmul.f32 s15, s13, s13
 *   @0x149c54 vldr s12, [r4, #-8]
 *   @0x149c58 vldr s14, [r4]
 *   @0x149c5c vmla.f32 s15, s12, s12
 *   @0x149c60 vmla.f32 s15, s14, s14
 *   @0x149c64 vsqrt.f32 s11, s15
 *   @0x149c68 vcmp.f32 s11, s11
 *   @0x149c6c vmrs APSR_nzcv, fpscr
 *   @0x149c70 bne 0x149ca4 <_Z12BuildFrustumP8yyMatrix+0x164>
 *   @0x149c74 vdiv.f32 s11, s16, s11
 *   @0x149c78 vmul.f32 s12, s12, s11
 *   @0x149c7c vmul.f32 s13, s13, s11
 *   @0x149c80 vstr s12, [r4, #-8]
 *   @0x149c84 vmul.f32 s11, s14, s11
 *   @0x149c88 vstr s13, [r4, #-4]
 *   @0x149c8c vmov r3, s11
 *   @0x149c90 str r3, [r4], #16
 *   @0x149c94 cmp r4, r5
 *   @0x149c98 bne 0x149c4c <_Z12BuildFrustumP8yyMatrix+0x10c>
 *   @0x149c9c vpop {d8}
 *   @0x149ca0 pop {r3, r4, r5, pc}
 *   @0x149ca4 vmov r0, s15
 *   @0x149ca8 bl 0xb6700 <sqrtf@plt>
 *   @0x149cac vldr s12, [r4, #-8]
 *   @0x149cb0 vldr s13, [r4, #-4]
 *   @0x149cb4 vldr s14, [r4]
 *   @0x149cb8 vmov s11, r0
 *   @0x149cbc b 0x149c74 <_Z12BuildFrustumP8yyMatrix+0x134>
 *   @0x149cc0 .word 0x002a5ad4
 *
 * ══ §66/76 gluBuild2DMipmaps(unsigned int, int, int, int, unsigned int, unsigned int, void const*)  0x181b58  size 388  97 条（0x181b58..0x181cdc）
 * @func 0x181b58 0x181cdc  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: gluBuild2DMipmaps(unsigned int, int, int, int, unsigned int, unsigned int, void const*)+0xf8 / HalfTextureRGB(int, int, unsigned char*, int, int, unsigned char*) / HalfTextureRGBA(int, int, unsigned int*, int, int, unsigned int*)
 * 字段偏移 top8: 0x18×4 / 0x48×3 / 0x4c×3 / 0x8×3 / 0xc×3 / 0x10×3 / 0x4×3 / 0x1c×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x181b58 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x181b5c sub sp, sp, #36
 *   @0x181b60 ldr r9, [pc, #0x170]
 *   @0x181b64 mov r7, r2
 *   @0x181b68 str r1, [sp, #0x18]
 *   @0x181b6c mov r11, #0
 *   @0x181b70 ldr r1, [sp, #0x48]
 *   @0x181b74 ldr r9, [pc, r9]
 *   @0x181b78 ldr r2, [sp, #0x4c]
 *   @0x181b7c mov r10, r3
 *   @0x181b80 ldr r6, [sp, #0x50]
 *   @0x181b84 add r5, r7, r7, lsr #31
 *   @0x181b88 str r1, [sp, #0x8]
 *   @0x181b8c mov r1, r11
 *   @0x181b90 str r3, [sp]
 *   @0x181b94 mov r3, r7
 *   @0x181b98 str r2, [sp, #0xc]
 *   @0x181b9c asr r5, r5, #1
 *   @0x181ba0 str r6, [sp, #0x10]
 *   @0x181ba4 str r11, [sp, #0x4]
 *   @0x181ba8 ldr r2, [sp, #0x18]
 *   @0x181bac ldr r4, [r9]
 *   @0x181bb0 str r0, [sp, #0x1c]
 *   @0x181bb4 blx r4
 *   @0x181bb8 add r4, r10, r10, lsr #31
 *   @0x181bbc asr r4, r4, #1
 *   @0x181bc0 cmp r5, #1
 *   @0x181bc4 cmpgt r4, #1
 *   @0x181bc8 ble 0x181c50 <_Z17gluBuild2DMipmapsjiiijjPKv+0xf8>
 *   @0x181bcc ldr r1, [sp, #0x48]
 *   @0x181bd0 movw r3, #0x1908
 *   @0x181bd4 mov r8, #1
 *   @0x181bd8 cmp r1, r3
 *   @0x181bdc beq 0x181c58 <_Z17gluBuild2DMipmapsjiiijjPKv+0x100>
 *   @0x181be0 mov r3, r7
 *   @0x181be4 ldr r7, [sp, #0x4c]
 *   @0x181be8 mov r0, r5
 *   @0x181bec mov r1, r4
 *   @0x181bf0 str r10, [sp]
 *   @0x181bf4 mov r2, r6
 *   @0x181bf8 str r6, [sp, #0x4]
 *   @0x181bfc mov r10, r4
 *   @0x181c00 bl 0x18941c <_Z14HalfTextureRGBiiPhiiS_>
 *   @0x181c04 ldr r2, [sp, #0x48]
 *   @0x181c08 stm sp, {r4, r11}
 *   @0x181c0c mov r3, r5
 *   @0x181c10 mov r1, r8
 *   @0x181c14 str r7, [sp, #0xc]
 *   @0x181c18 str r2, [sp, #0x8]
 *   @0x181c1c asr r4, r4, #1
 *   @0x181c20 ldr r2, [sp, #0x18]
 *   @0x181c24 add r8, r8, #1
 *   @0x181c28 str r6, [sp, #0x10]
 *   @0x181c2c ldr r0, [sp, #0x1c]
 *   @0x181c30 ldr r12, [r9]
 *   @0x181c34 blx r12
 *   @0x181c38 asr r2, r5, #1
 *   @0x181c3c cmp r4, #1
 *   @0x181c40 cmpgt r2, #1
 *   @0x181c44 mov r3, r5
 *   @0x181c48 mov r5, r2
 *   @0x181c4c bgt 0x181be8 <_Z17gluBuild2DMipmapsjiiijjPKv+0x90>
 *   @0x181c50 add sp, sp, #36
 *   @0x181c54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x181c58 mov r2, r10
 *   @0x181c5c mov r10, r9
 *   @0x181c60 ldr r9, [sp, #0x4c]
 *   @0x181c64 mov r3, r7
 *   @0x181c68 mov r0, r5
 *   @0x181c6c mov r1, r4
 *   @0x181c70 str r2, [sp]
 *   @0x181c74 str r6, [sp, #0x4]
 *   @0x181c78 mov r2, r6
 *   @0x181c7c bl 0x18923c <_Z15HalfTextureRGBAiiPjiiS_>
 *   @0x181c80 stm sp, {r4, r11}
 *   @0x181c84 movw r3, #0x1908
 *   @0x181c88 mov r1, r8
 *   @0x181c8c str r3, [sp, #0x8]
 *   @0x181c90 mov r3, r5
 *   @0x181c94 str r9, [sp, #0xc]
 *   @0x181c98 mov r7, r5
 *   @0x181c9c ldr r2, [sp, #0x18]
 *   @0x181ca0 asr r5, r5, #1
 *   @0x181ca4 str r6, [sp, #0x10]
 *   @0x181ca8 add r8, r8, #1
 *   @0x181cac ldr r0, [sp, #0x1c]
 *   @0x181cb0 ldr r12, [r10]
 *   @0x181cb4 blx r12
 *   @0x181cb8 asr r3, r4, #1
 *   @0x181cbc cmp r3, #1
 *   @0x181cc0 cmpgt r5, #1
 *   @0x181cc4 mov r2, r4
 *   @0x181cc8 mov r4, r3
 *   @0x181ccc bgt 0x181c64 <_Z17gluBuild2DMipmapsjiiijjPKv+0x10c>
 *   @0x181cd0 add sp, sp, #36
 *   @0x181cd4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x181cd8 eoreq r11, r6, r8, lsl #24
 *
 * ══ §67/76 LoadTextureFromPNG(Texture*, eMipEnable)  0x1828a4  size 388  97 条（0x1828a4..0x182a28）
 * @func 0x1828a4 0x182a28  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1828ec→0x3f5028, 0x182908→0x479bb4, 0x18292c→0x479bbc, 0x182944→0x479bb0, 0x1829e0→0x3eb70c
 * 调用序列: ReadPNGFile(void*, int, int*, int*, bool) / _InvalidateTextureState() / FreePNGFile() / GenerateMips(Texture*, int, int, int, char*)
 * 字段偏移 top8: 0x10×4 / 0x20×3 / 0x1c×3 / 0x4×2 / 0x8×2 / 0x24×2 / 0xc×2 / 0x38×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1828a4 ldr r12, [r0, #0x10]
 *   @0x1828a8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1828ac sub sp, sp, #40
 *   @0x1828b0 mov r4, r0
 *   @0x1828b4 eor r12, r12, #2
 *   @0x1828b8 ldr r0, [r0, #0x2c]
 *   @0x1828bc ubfx r12, r12, #0x1, #0x1
 *   @0x1828c0 mov r6, r1
 *   @0x1828c4 add r2, sp, #28
 *   @0x1828c8 ldr r1, [r4, #0x30]
 *   @0x1828cc add r3, sp, #32
 *   @0x1828d0 str r12, [sp]
 *   @0x1828d4 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b>
 *   @0x1828d8 ldr r5, [pc, #0x12c]
 *   @0x1828dc add r5, pc, r5
 *   @0x1828e0 subs r7, r0, #0
 *   @0x1828e4 beq 0x1829e0 <_Z18LoadTextureFromPNGP7Texture10eMipEnable+0x13c>
 *   @0x1828e8 bl 0x182598 <_Z23_InvalidateTextureStatev>
 *   @0x1828ec ldr r3, [pc, #0x11c]
 *   @0x1828f0 ldr lr, [sp, #0x20]
 *   @0x1828f4 mov r0, #1
 *   @0x1828f8 ldr r12, [sp, #0x1c]
 *   @0x1828fc add r1, sp, #36
 *   @0x182900 ldr r3, [r5, r3]
 *   @0x182904 movw r8, #0x1401
 *   @0x182908 ldr r2, [pc, #0x104]
 *   @0x18290c ldr r3, [r3]
 *   @0x182910 mul r12, r3, r12
 *   @0x182914 mul r3, lr, r3
 *   @0x182918 str r12, [r4, #0x4]
 *   @0x18291c str r3, [r4, #0x8]
 *   @0x182920 ldr r3, [r5, r2]
 *   @0x182924 ldr r3, [r3]
 *   @0x182928 blx r3
 *   @0x18292c ldr r3, [pc, #0xe4]
 *   @0x182930 movw r0, #0xde1
 *   @0x182934 ldr r1, [sp, #0x24]
 *   @0x182938 ldr r3, [r5, r3]
 *   @0x18293c ldr r3, [r3]
 *   @0x182940 blx r3
 *   @0x182944 ldr r1, [pc, #0xd0]
 *   @0x182948 ldr r2, [sp, #0x20]
 *   @0x18294c mov lr, #0
 *   @0x182950 movw r12, #0x1908
 *   @0x182954 ldr r3, [sp, #0x1c]
 *   @0x182958 ldr r0, [r5, r1]
 *   @0x18295c mov r1, lr
 *   @0x182960 str r2, [sp]
 *   @0x182964 mov r2, r12
 *   @0x182968 str r7, [sp, #0x10]
 *   @0x18296c ldr r5, [r0]
 *   @0x182970 movw r0, #0xde1
 *   @0x182974 str lr, [sp, #0x4]
 *   @0x182978 str r12, [sp, #0x8]
 *   @0x18297c str r8, [sp, #0xc]
 *   @0x182980 blx r5
 *   @0x182984 ldr r3, [r4, #0x10]
 *   @0x182988 cmp r6, #1
 *   @0x18298c orr r2, r3, #64
 *   @0x182990 str r2, [r4, #0x10]
 *   @0x182994 beq 0x1829c4 <_Z18LoadTextureFromPNGP7Texture10eMipEnable+0x120>
 *   @0x182998 cmp r6, #2
 *   @0x18299c beq 0x1829bc <_Z18LoadTextureFromPNGP7Texture10eMipEnable+0x118>
 *   @0x1829a0 bl 0x18a518 <_Z11FreePNGFilev>
 *   @0x1829a4 ldr r0, [sp, #0x24]
 *   @0x1829a8 mov r3, #6
 *   @0x1829ac str r3, [r4]
 *   @0x1829b0 str r0, [r4, #0x14]
 *   @0x1829b4 add sp, sp, #40
 *   @0x1829b8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1829bc tst r3, #16
 *   @0x1829c0 beq 0x1829a0 <_Z18LoadTextureFromPNGP7Texture10eMipEnable+0xfc>
 *   @0x1829c4 ldr r1, [sp, #0x1c]
 *   @0x1829c8 mov r0, r4
 *   @0x1829cc ldr r2, [sp, #0x20]
 *   @0x1829d0 mov r3, #4
 *   @0x1829d4 str r7, [sp]
 *   @0x1829d8 bl 0x181db0 <_Z12GenerateMipsP7TextureiiiPc>
 *   @0x1829dc b 0x1829a0 <_Z18LoadTextureFromPNGP7Texture10eMipEnable+0xfc>
 *   @0x1829e0 ldr r3, [pc, #0x38]
 *   @0x1829e4 ldr r1, [pc, #0x38]
 *   @0x1829e8 ldr r3, [r5, r3]
 *   @0x1829ec add r1, pc, r1
 *   @0x1829f0 ldr r0, [r3]
 *   @0x1829f4 ldr r3, [r0]
 *   @0x1829f8 ldr r3, [r3, #0xc]
 *   @0x1829fc blx r3
 *   @0x182a00 mov r0, r7
 *   @0x182a04 add sp, sp, #40
 *   @0x182a08 pop {r4, r5, r6, r7, r8, pc}
 *   @0x182a0c eoreq pc, r6, r4, ror r3
 *   @0x182a10 .word 0xffffc984
 *   @0x182a14 .word 0xffffbb28
 *   @0x182a18 .word 0xffffbb20
 *   @0x182a1c .word 0xffffbb2c
 *   @0x182a20 .word 0xffffbac4
 *   @0x182a24 andseq r9, r12, r0, lsl r1
 *
 * ══ §68/76 Graphics::UpdateRegion(void*, int, int, int, int)  0x183240  size 388  97 条（0x183240..0x1833c4）
 * @func 0x183240 0x1833c4  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::UpdateRegion(void*, int, int, int, int)+0x158 / Graphics::UpdateRegion(void*, int, int, int, int)+0x15c / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / _InvalidateTextureState() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x1c×3 / 0x28×2 / 0x14×2 / 0x4×2 / 0x8×2 / 0x18×2 / 0x48×1 / 0xe0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183240 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x183244 subs r4, r0, #0
 *   @0x183248 sub sp, sp, #36
 *   @0x18324c beq 0x1833a8 <_ZN8Graphics12UpdateRegionEPviiii+0x168>
 *   @0x183250 ldr r5, [r4, #0x28]
 *   @0x183254 cmp r5, #0
 *   @0x183258 beq 0x18339c <_ZN8Graphics12UpdateRegionEPviiii+0x15c>
 *   @0x18325c ldr r0, [r4, #0x14]
 *   @0x183260 cmn r0, #1
 *   @0x183264 beq 0x183398 <_ZN8Graphics12UpdateRegionEPviiii+0x158>
 *   @0x183268 ldr r9, [r4, #0x4]
 *   @0x18326c bic r6, r1, r1, asr #31
 *   @0x183270 ldr r0, [r4, #0x8]
 *   @0x183274 cmp r9, r6
 *   @0x183278 ble 0x183398 <_ZN8Graphics12UpdateRegionEPviiii+0x158>
 *   @0x18327c bic r8, r2, r2, asr #31
 *   @0x183280 cmp r8, r0
 *   @0x183284 bge 0x183398 <_ZN8Graphics12UpdateRegionEPviiii+0x158>
 *   @0x183288 adds r1, r1, r3
 *   @0x18328c bmi 0x183398 <_ZN8Graphics12UpdateRegionEPviiii+0x158>
 *   @0x183290 ldr r3, [sp, #0x48]
 *   @0x183294 adds r2, r2, r3
 *   @0x183298 bmi 0x183398 <_ZN8Graphics12UpdateRegionEPviiii+0x158>
 *   @0x18329c cmp r9, r1
 *   @0x1832a0 rsble r1, r6, r9
 *   @0x1832a4 rsbgt r1, r6, r1
 *   @0x1832a8 cmp r0, r2
 *   @0x1832ac rsble r7, r8, r0
 *   @0x1832b0 rsbgt r7, r8, r2
 *   @0x1832b4 cmp r1, #0
 *   @0x1832b8 cmpgt r7, #0
 *   @0x1832bc str r1, [sp, #0x18]
 *   @0x1832c0 movgt r5, #0
 *   @0x1832c4 movle r5, #1
 *   @0x1832c8 ble 0x18339c <_ZN8Graphics12UpdateRegionEPviiii+0x15c>
 *   @0x1832cc lsl r11, r1, #2
 *   @0x1832d0 ldr r1, [pc, #0xe0]
 *   @0x1832d4 mov r2, #70
 *   @0x1832d8 mov r3, #1
 *   @0x1832dc add r1, pc, r1
 *   @0x1832e0 mov r10, r5
 *   @0x1832e4 mul r0, r7, r11
 *   @0x1832e8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1832ec ldr r2, [r4, #0x28]
 *   @0x1832f0 mla r1, r9, r8, r6
 *   @0x1832f4 lsl r9, r9, #2
 *   @0x1832f8 add r5, r2, r1, lsl #2
 *   @0x1832fc mov r12, r0
 *   @0x183300 str r0, [sp, #0x1c]
 *   @0x183304 mov r0, r12
 *   @0x183308 mov r1, r5
 *   @0x18330c mov r2, r11
 *   @0x183310 add r10, r10, #1
 *   @0x183314 bl 0xb65bc <memcpy@plt>
 *   @0x183318 cmp r7, r10
 *   @0x18331c add r5, r5, r9
 *   @0x183320 add r12, r0, r11
 *   @0x183324 bgt 0x183304 <_ZN8Graphics12UpdateRegionEPviiii+0xc4>
 *   @0x183328 bl 0x182598 <_Z23_InvalidateTextureStatev>
 *   @0x18332c ldr r3, [pc, #0x88]
 *   @0x183330 ldr r1, [r4, #0x14]
 *   @0x183334 movw r0, #0xde1
 *   @0x183338 ldr r3, [pc, r3]
 *   @0x18333c mov r5, #1
 *   @0x183340 ldr r3, [r3]
 *   @0x183344 blx r3
 *   @0x183348 ldr r12, [pc, #0x70]
 *   @0x18334c ldr r0, [sp, #0x18]
 *   @0x183350 mov r2, r6
 *   @0x183354 ldr r3, [sp, #0x1c]
 *   @0x183358 ldr r12, [pc, r12]
 *   @0x18335c str r7, [sp, #0x4]
 *   @0x183360 movw r1, #0x1401
 *   @0x183364 str r0, [sp]
 *   @0x183368 movw r0, #0x1908
 *   @0x18336c str r3, [sp, #0x10]
 *   @0x183370 mov r3, r8
 *   @0x183374 str r0, [sp, #0x8]
 *   @0x183378 movw r0, #0xde1
 *   @0x18337c str r1, [sp, #0xc]
 *   @0x183380 mov r1, #0
 *   @0x183384 ldr r12, [r12]
 *   @0x183388 blx r12
 *   @0x18338c ldr r0, [sp, #0x1c]
 *   @0x183390 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x183394 b 0x18339c <_ZN8Graphics12UpdateRegionEPviiii+0x15c>
 *   @0x183398 mov r5, #1
 *   @0x18339c mov r0, r5
 *   @0x1833a0 add sp, sp, #36
 *   @0x1833a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1833a8 mov r5, r4
 *   @0x1833ac mov r0, r5
 *   @0x1833b0 add sp, sp, #36
 *   @0x1833b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1833b8 andseq sp, r10, r4, asr sp
 *   @0x1833bc eoreq r10, r6, r8, lsr r4
 *   @0x1833c0 eoreq r10, r6, r8, lsr #8
 *
 * ══ §69/76 CDS_List::Shuffle()  0x203360  size 388  97 条（0x203360..0x2034e4）
 * @func 0x203360 0x2034e4  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYRandom(int)×2 / CDS_List::Shuffle()+0x16c / CDS_List::Shuffle()+0x138 / CDS_List::Shuffle()+0x154 / CDS_List::Shuffle()+0x54
 * 字段偏移 top8: 0x4×13 / 0xc×11 / 0x8×6 / 0x18×2 / 0x1c×2 / 0x10×2 / 0x20×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203360 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x203364 mov r11, r0
 *   @0x203368 ldr r0, [r0, #0x4]
 *   @0x20336c mov r3, #0
 *   @0x203370 sub sp, sp, #52
 *   @0x203374 cmp r0, r3
 *   @0x203378 str r3, [sp, #0x20]
 *   @0x20337c str r3, [sp, #0x24]
 *   @0x203380 str r3, [sp, #0x28]
 *   @0x203384 str r3, [sp, #0x2c]
 *   @0x203388 ble 0x2034cc <_ZN8CDS_List7ShuffleEv+0x16c>
 *   @0x20338c ldr r4, [pc, #0x140]
 *   @0x203390 add r10, sp, #32
 *   @0x203394 ldr r5, [pc, #0x13c]
 *   @0x203398 mov r8, #1
 *   @0x20339c add r4, pc, r4
 *   @0x2033a0 str r10, [sp, #0x4]
 *   @0x2033a4 add r5, pc, r5
 *   @0x2033a8 str r4, [sp, #0x18]
 *   @0x2033ac str r5, [sp, #0x1c]
 *   @0x2033b0 b 0x203468 <_ZN8CDS_List7ShuffleEv+0x108>
 *   @0x2033b4 cmp r7, #0
 *   @0x2033b8 blt 0x203498 <_ZN8CDS_List7ShuffleEv+0x138>
 *   @0x2033bc cmp r6, r3
 *   @0x2033c0 ldr r0, [pc, #0x114]
 *   @0x2033c4 ldr r1, [sp, #0x1c]
 *   @0x2033c8 mov r2, r6
 *   @0x2033cc bge 0x2034b4 <_ZN8CDS_List7ShuffleEv+0x154>
 *   @0x2033d0 cmp r6, #0
 *   @0x2033d4 blt 0x2034b4 <_ZN8CDS_List7ShuffleEv+0x154>
 *   @0x2033d8 ldr r9, [r11, #0xc]
 *   @0x2033dc lsl r10, r6, #4
 *   @0x2033e0 ldr r5, [sp, #0x4]
 *   @0x2033e4 add r4, r9, r10
 *   @0x2033e8 add r12, r9, r7, lsl #4
 *   @0x2033ec ldr r9, [r4]
 *   @0x2033f0 ldr r1, [r12, #0x4]
 *   @0x2033f4 ldr r2, [r12, #0x8]
 *   @0x2033f8 str r9, [sp, #0x8]
 *   @0x2033fc ldr r9, [r4, #0x4]
 *   @0x203400 ldr r3, [r12, #0xc]
 *   @0x203404 ldr r0, [r12]
 *   @0x203408 str r9, [sp, #0xc]
 *   @0x20340c ldr r9, [r4, #0x8]
 *   @0x203410 str r9, [sp, #0x10]
 *   @0x203414 ldr r9, [r4, #0xc]
 *   @0x203418 mov r4, r5
 *   @0x20341c stm r5!, {r0, r1, r2, r3}
 *   @0x203420 ldr r5, [r11, #0xc]
 *   @0x203424 ldm r4!, {r0, r1, r2, r3}
 *   @0x203428 ldr r4, [sp, #0x8]
 *   @0x20342c str r4, [r5, r7, lsl #4]
 *   @0x203430 ldr r4, [sp, #0xc]
 *   @0x203434 ldr r5, [sp, #0x10]
 *   @0x203438 str r9, [r12, #0xc]
 *   @0x20343c str r4, [r12, #0x4]
 *   @0x203440 str r5, [r12, #0x8]
 *   @0x203444 ldr r4, [r11, #0xc]
 *   @0x203448 add r12, r4, r10
 *   @0x20344c str r0, [r4, r6, lsl #4]
 *   @0x203450 str r1, [r12, #0x4]
 *   @0x203454 str r2, [r12, #0x8]
 *   @0x203458 str r3, [r12, #0xc]
 *   @0x20345c ldr r0, [r11, #0x4]
 *   @0x203460 cmp r8, r0, lsl #3
 *   @0x203464 bgt 0x2034cc <_ZN8CDS_List7ShuffleEv+0x16c>
 *   @0x203468 bl 0xc4600 <_Z8YYRandomi>
 *   @0x20346c add r8, r8, #1
 *   @0x203470 mov r7, r0
 *   @0x203474 ldr r0, [r11, #0x4]
 *   @0x203478 bl 0xc4600 <_Z8YYRandomi>
 *   @0x20347c ldr r3, [r11, #0x4]
 *   @0x203480 ldr r1, [sp, #0x18]
 *   @0x203484 mov r2, r7
 *   @0x203488 cmp r7, r3
 *   @0x20348c mov r6, r0
 *   @0x203490 ldr r0, [pc, #0x48]
 *   @0x203494 blt 0x2033b4 <_ZN8CDS_List7ShuffleEv+0x54>
 *   @0x203498 ldr r0, [pc, r0]
 *   @0x20349c ldr r0, [r0]
 *   @0x2034a0 ldr r3, [r0]
 *   @0x2034a4 ldr r3, [r3, #0xc]
 *   @0x2034a8 blx r3
 *   @0x2034ac ldr r3, [r11, #0x4]
 *   @0x2034b0 b 0x2033bc <_ZN8CDS_List7ShuffleEv+0x5c>
 *   @0x2034b4 ldr r0, [pc, r0]
 *   @0x2034b8 ldr r0, [r0]
 *   @0x2034bc ldr r3, [r0]
 *   @0x2034c0 ldr r3, [r3, #0xc]
 *   @0x2034c4 blx r3
 *   @0x2034c8 b 0x2033d8 <_ZN8CDS_List7ShuffleEv+0x78>
 *   @0x2034cc add sp, sp, #52
 *   @0x2034d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2034d4 andseq r0, r5, r0, asr #8
 *   @0x2034d8 andseq r0, r5, r0, asr #8
 *   @0x2034dc andseq r10, lr, r0, ror #4
 *   @0x2034e0 andseq r10, lr, r12, ror r2
 *
 * ══ §70/76 CAudioGroupMan::LoadGroup(int)  0x21e018  size 388  97 条（0x21e018..0x21e19c）
 * @func 0x21e018 0x21e19c  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21e120→0x3eb70c, 0x21e154→0x3eb70c
 * 调用序列: CAudioGroupMan::GetGroup(int) / CAudioGroupMan::LoadGroup(int)+0x28 / 0xb65c8 / LoadSave::ReadBundleFile(char const*, int*) / CAudioGroup::SetLoadState(CAudioGroup::eLoadState) / Audio_WAVs(unsigned char*, unsigned int, unsigned char*, int) / CAudioGroup::AsyncDecode() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0xc×3 / 0x8c×2 / 0x8×2 / 0x4×2 / 0x34×2 / 0x15c×1 / 0x158×1 / 0x100×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e018 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21e01c subs r7, r1, #0
 *   @0x21e020 ldr r4, [pc, #0x15c]
 *   @0x21e024 sub sp, sp, #148
 *   @0x21e028 ldr r2, [pc, #0x158]
 *   @0x21e02c add r4, pc, r4
 *   @0x21e030 ldr r5, [r4, r2]
 *   @0x21e034 ldr r2, [r5]
 *   @0x21e038 str r2, [sp, #0x8c]
 *   @0x21e03c bne 0x21e05c <_ZN14CAudioGroupMan9LoadGroupEi+0x44>
 *   @0x21e040 mov r0, #0
 *   @0x21e044 ldr r2, [sp, #0x8c]
 *   @0x21e048 ldr r3, [r5]
 *   @0x21e04c cmp r2, r3
 *   @0x21e050 bne 0x21e180 <_ZN14CAudioGroupMan9LoadGroupEi+0x168>
 *   @0x21e054 add sp, sp, #148
 *   @0x21e058 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21e05c bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi>
 *   @0x21e060 subs r6, r0, #0
 *   @0x21e064 beq 0x21e040 <_ZN14CAudioGroupMan9LoadGroupEi+0x28>
 *   @0x21e068 ldr r3, [r6, #0x8]
 *   @0x21e06c cmp r3, #0
 *   @0x21e070 ble 0x21e040 <_ZN14CAudioGroupMan9LoadGroupEi+0x28>
 *   @0x21e074 ldr r8, [r6]
 *   @0x21e078 cmp r8, #0
 *   @0x21e07c bne 0x21e040 <_ZN14CAudioGroupMan9LoadGroupEi+0x28>
 *   @0x21e080 add r10, sp, #12
 *   @0x21e084 ldr r2, [pc, #0x100]
 *   @0x21e088 mov r1, #128
 *   @0x21e08c mov r3, r7
 *   @0x21e090 add r2, pc, r2
 *   @0x21e094 mov r0, r10
 *   @0x21e098 bl 0xb65c8 <snprintf@plt>
 *   @0x21e09c mov r0, r10
 *   @0x21e0a0 mov r1, r8
 *   @0x21e0a4 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x21e0a8 subs r9, r0, #0
 *   @0x21e0ac beq 0x21e154 <_ZN14CAudioGroupMan9LoadGroupEi+0x13c>
 *   @0x21e0b0 ldr r11, [r9, #0x8]
 *   @0x21e0b4 movw r3, #0x5541
 *   @0x21e0b8 movt r3, #0x4f44
 *   @0x21e0bc ldr r2, [r9, #0xc]
 *   @0x21e0c0 subs r3, r11, r3
 *   @0x21e0c4 rsbs r11, r3, #0
 *   @0x21e0c8 adcs r11, r11, r3
 *   @0x21e0cc cmp r2, #0
 *   @0x21e0d0 moveq r11, #0
 *   @0x21e0d4 cmp r11, #0
 *   @0x21e0d8 beq 0x21e120 <_ZN14CAudioGroupMan9LoadGroupEi+0x108>
 *   @0x21e0dc str r9, [r6, #0x18]
 *   @0x21e0e0 mov r0, r6
 *   @0x21e0e4 mov r1, #1
 *   @0x21e0e8 str r2, [sp, #0x4]
 *   @0x21e0ec bl 0x21dd48 <_ZN11CAudioGroup12SetLoadStateENS_10eLoadStateE>
 *   @0x21e0f0 ldr r2, [sp, #0x4]
 *   @0x21e0f4 mov r3, r7
 *   @0x21e0f8 str r8, [r6, #0x10]
 *   @0x21e0fc str r8, [r6, #0x14]
 *   @0x21e100 add r0, r9, #16
 *   @0x21e104 mov r1, r2
 *   @0x21e108 mov r2, r9
 *   @0x21e10c bl 0x219680 <_Z10Audio_WAVsPhjS_i>
 *   @0x21e110 mov r0, r6
 *   @0x21e114 bl 0x21dcb8 <_ZN11CAudioGroup11AsyncDecodeEv>
 *   @0x21e118 mov r0, #1
 *   @0x21e11c b 0x21e044 <_ZN14CAudioGroupMan9LoadGroupEi+0x2c>
 *   @0x21e120 ldr r3, [pc, #0x68]
 *   @0x21e124 mov r2, r10
 *   @0x21e128 ldr r1, [pc, #0x64]
 *   @0x21e12c ldr r3, [r4, r3]
 *   @0x21e130 add r1, pc, r1
 *   @0x21e134 ldr r0, [r3]
 *   @0x21e138 ldr r3, [r0]
 *   @0x21e13c ldr r3, [r3, #0xc]
 *   @0x21e140 blx r3
 *   @0x21e144 mov r0, r9
 *   @0x21e148 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21e14c mov r0, r11
 *   @0x21e150 b 0x21e044 <_ZN14CAudioGroupMan9LoadGroupEi+0x2c>
 *   @0x21e154 ldr r3, [pc, #0x34]
 *   @0x21e158 mov r2, r10
 *   @0x21e15c ldr r1, [pc, #0x34]
 *   @0x21e160 ldr r3, [r4, r3]
 *   @0x21e164 add r1, pc, r1
 *   @0x21e168 ldr r0, [r3]
 *   @0x21e16c ldr r3, [r0]
 *   @0x21e170 ldr r3, [r3, #0xc]
 *   @0x21e174 blx r3
 *   @0x21e178 mov r0, r9
 *   @0x21e17c b 0x21e044 <_ZN14CAudioGroupMan9LoadGroupEi+0x2c>
 *   @0x21e180 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x21e184 andseq r3, sp, r4, lsr #24
 *   @0x21e188 .word 0xffffbd00
 *   @0x21e18c andseq r6, r3, r0, lsl #12
 *   @0x21e190 .word 0xffffbac4
 *   @0x21e194 andseq r6, r3, r8, lsl #11
 *   @0x21e198 andseq r6, r3, r0, asr #10
 *
 * ══ §71/76 JS_Array_prototype_push(RValue&, CInstance*, CInstance*, int, RValue*)  0x24f7f8  size 388  97 条（0x24f7f8..0x24f97c）
 * @func 0x24f7f8 0x24f97c  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Object_Put(YYObjectBase*, RValue*, char const*, bool)×2 / 0xb6574 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*) / YYGetUint32(RValue const*, int) / JS_Array_prototype_push(RValue&, CInstance*, CInstance*, int, RValue*)+0x154 / 0xb65c8 / SetArrayEntry(YYObjectBase*, unsigned int, RValue*) / YYObjectBase::InternalGetYYVar(int)
 * 字段偏移 top8: 0x4×4 / 0xc×3 / 0x34×2 / 0x8×2 / 0x160×1 / 0x15c×1 / 0x40×1 / 0x60×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24f7f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24f7fc mov r8, r1
 *   @0x24f800 ldr r10, [pc, #0x160]
 *   @0x24f804 mov r4, r3
 *   @0x24f808 ldr r1, [pc, #0x15c]
 *   @0x24f80c sub sp, sp, #60
 *   @0x24f810 ldr r10, [pc, r10]
 *   @0x24f814 mov r9, r0
 *   @0x24f818 add r1, pc, r1
 *   @0x24f81c ldr r0, [r8, #0x40]
 *   @0x24f820 ldr r3, [r10]
 *   @0x24f824 ldr r6, [sp, #0x60]
 *   @0x24f828 str r3, [sp, #0x34]
 *   @0x24f82c bl 0xb6574 <strcmp@plt>
 *   @0x24f830 cmp r0, #0
 *   @0x24f834 bne 0x24f840 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x24f838 cmp r4, #1
 *   @0x24f83c beq 0x24f928 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x24f840 add r5, sp, #4
 *   @0x24f844 ldr r2, [pc, #0x124]
 *   @0x24f848 mov r7, #0
 *   @0x24f84c mov r0, r8
 *   @0x24f850 mov r1, r5
 *   @0x24f854 add r2, pc, r2
 *   @0x24f858 mvn r11, #-16777216
 *   @0x24f85c str r7, [sp, #0x4]
 *   @0x24f860 str r7, [sp, #0x8]
 *   @0x24f864 str r7, [sp, #0xc]
 *   @0x24f868 str r11, [sp, #0x10]
 *   @0x24f86c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24f870 mov r0, r5
 *   @0x24f874 mov r1, r7
 *   @0x24f878 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x24f87c cmp r4, r7
 *   @0x24f880 str r7, [r9]
 *   @0x24f884 str r7, [r9, #0x4]
 *   @0x24f888 str r7, [r9, #0x8]
 *   @0x24f88c str r11, [r9, #0xc]
 *   @0x24f890 mov r5, r0
 *   @0x24f894 ble 0x24f94c <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x24f898 ldr r11, [pc, #0xd4]
 *   @0x24f89c add r4, r0, r4
 *   @0x24f8a0 add r7, sp, #20
 *   @0x24f8a4 add r11, pc, r11
 *   @0x24f8a8 mov r3, r5
 *   @0x24f8ac mov r1, #32
 *   @0x24f8b0 mov r2, r11
 *   @0x24f8b4 mov r0, r7
 *   @0x24f8b8 bl 0xb65c8 <snprintf@plt>
 *   @0x24f8bc add r5, r5, #1
 *   @0x24f8c0 mov r1, r6
 *   @0x24f8c4 mov r0, r8
 *   @0x24f8c8 mov r2, r7
 *   @0x24f8cc mov r3, #0
 *   @0x24f8d0 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x24f8d4 cmp r5, r4
 *   @0x24f8d8 add r6, r6, #16
 *   @0x24f8dc bne 0x24f8a8 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x24f8e0 vmov s15, r4
 *   @0x24f8e4 ldr r2, [pc, #0x8c]
 *   @0x24f8e8 mov r3, #0
 *   @0x24f8ec mov r0, r8
 *   @0x24f8f0 vcvt.f64.u32 d7, s15
 *   @0x24f8f4 str r3, [r9, #0xc]
 *   @0x24f8f8 mov r1, r9
 *   @0x24f8fc add r2, pc, r2
 *   @0x24f900 vmov r4, r5, d7
 *   @0x24f904 vstr s14, [r9]
 *   @0x24f908 str r5, [r9, #0x4]
 *   @0x24f90c bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x24f910 ldr r2, [sp, #0x34]
 *   @0x24f914 ldr r3, [r10]
 *   @0x24f918 cmp r2, r3
 *   @0x24f91c bne 0x24f964 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x24f920 add sp, sp, #60
 *   @0x24f924 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24f928 ldr r3, [r8, #0x4]
 *   @0x24f92c cmp r3, #0
 *   @0x24f930 beq 0x24f954 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x24f934 add r0, r3, #16
 *   @0x24f938 ldr r0, [r0]
 *   @0x24f93c mov r2, r6
 *   @0x24f940 ldr r1, [r0, #0x24]
 *   @0x24f944 bl 0x247904 <_Z13SetArrayEntryP12YYObjectBasejP6RValue>
 *   @0x24f948 b 0x24f910 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x24f94c mov r4, r0
 *   @0x24f950 b 0x24f8e0 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x24f954 mov r0, r8
 *   @0x24f958 mov r1, r4
 *   @0x24f95c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24f960 b 0x24f938 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x24f964 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x24f968 andseq lr, r9, r0, asr #2
 *   @0x24f96c andeq r5, lr, r0, lsl #2
 *   @0x24f970 andeq r1, lr, r8, lsl r0
 *   @0x24f974 ldrheq r6, [r0], -r12
 *   @0x24f978 andeq r0, lr, r0, ror pc
 *
 * ══ §72/76 png_handle_zTXt  0x2ad6cc  size 388  97 条（0x2ad6cc..0x2ad850）
 * @func 0x2ad6cc 0x2ad850  size 388  97 条
 * 部分覆盖: 本节 97/174 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning×3 / png_free×2 / anonT_2fa06c+0x2c0 / png_malloc_warn / png_handle_zTXt+0xaa / png_handle_zTXt+0xc6 / png_set_text_2 / png_error
 * 字段偏移 top8: 0x130×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ad6cc push.w {r0, r1, r2, r3, r4, r5, r6, r7, r8, lr}
 *   @0x2ad6d0 mov r4, r0
 *   @0x2ad6d4 .word 0x460f3310
 *   @0x2ad6d8 mov r5, r2
 *   @0x2ad6dc cmp r3, #0x1
 *   @0x2ad6e0 subs r3, #0x1
 *   @0x2ad6e4 blhs 0x2fa32c <ps_hints_apply+0x8f2c>
 *   @0x2ad6e8 bne 0x2ad6fc <png_handle_zTXt+0x30>
 *   @0x2ad6ec add r1, pc
 *   @0x2ad6f0 strtmi pc, [r0], -r1, asr #29
 *   @0x2ad6f4 mov r1, r5
 *   @0x2ad6f8 adds pc, r7, sp, asr #21
 *   @0x2ad6fc ldr.w r3, [r4, #0x12c]
 *   @0x2ad700 lsls r1, r3, #0x1f
 *   @0x2ad704 ldr r1, [pc, #0x130]
 *   @0x2ad708 add r1, pc
 *   @0x2ad70c .word 0xf8d4fe8f
 *   @0x2ad710 strtmi r3, [r0], -r12, lsr #2
 *   @0x2ad714 ldr.w r1, [r4, #0x330]
 *   @0x2ad718 lsls r2, r3, #0x1d
 *   @0x2ad71c orrmi r3, r3, #0x8
 *   @0x2ad720 strmi.w r3, [r4, #0x12c]
 *   @0x2ad724 bl 0x2a6cfc <png_free>
 *   @0x2ad728 adds r1, r5, #0x1
 *   @0x2ad72c bl 0x2a6d16 <png_malloc_warn>
 *   @0x2ad730 mov r1, r0
 *   @0x2ad734 qasxmi r0, r0, r0
 *   @0x2ad738 cbnz r1, 0x2ad744 <png_handle_zTXt+0x78>
 *   @0x2ad73c add r1, pc
 *   @0x2ad740 .word 0xe073fe99
 *   @0x2ad744 mov r2, r5
 *   @0x2ad748 strtmi pc, [r0], -r1, ror #20
 *   @0x2ad74c movs r1, #0x0
 *   @0x2ad750 stmiblt r8!, {r0, r5, r7, r9, r11, r12, sp, lr, pc}
 *   @0x2ad754 ldr.w r3, [r4, #0x330]
 *   @0x2ad758 strb r0, [r3, r5]
 *   @0x2ad75c sasxmi r3, r10, r0
 *   @0x2ad760 mov r6, r2
 *   @0x2ad764 ldrb r1, [r6]
 *   @0x2ad768 bne 0x2ad760 <png_handle_zTXt+0x94>
 *   @0x2ad76c bls 0x2ad776 <png_handle_zTXt+0xaa>
 *   @0x2ad770 add r3, r2
 *   @0x2ad774 blo 0x2ad792 <png_handle_zTXt+0xc6>
 *   @0x2ad778 mov r0, r4
 *   @0x2ad77c bl 0x2a6474 <png_warning>
 *   @0x2ad780 mov r0, r4
 *   @0x2ad784 .word 0xf7f91330
 *   @0x2ad788 movwhs pc, #0xab9
 *   @0x2ad78c str.w r3, [r4, #0x330]
 *   @0x2ad790 b 0x2ad82c <png_handle_zTXt+0x160>
 *   @0x2ad794 cbz r3, 0x2ad7a0 <png_handle_zTXt+0xd4>
 *   @0x2ad798 mov r0, r4
 *   @0x2ad79c bl 0x2a6474 <png_warning>
 *   @0x2ad7a0 ldr.w r3, [r4, #0x330]
 *   @0x2ad7a4 adds r6, #0x2
 *   @0x2ad7a8 mov r0, r4
 *   @0x2ad7ac .word 0x21000806
 *   @0x2ad7b0 add r3, sp, #0xc
 *   @0x2ad7b4 mov r3, r8
 *   @0x2ad7b8 strtmi pc, [r0], -r7, lsr #21
 *   @0x2ad7bc movs r1, #0x1c
 *   @0x2ad7c0 strmi pc, [r5], -r10, lsr #21
 *   @0x2ad7c4 cbnz r0, 0x2ad7e0 <png_handle_zTXt+0x114>
 *   @0x2ad7c8 mov r0, r4
 *   @0x2ad7cc bl 0x2a6474 <png_warning>
 *   @0x2ad7d0 mov r0, r4
 *   @0x2ad7d4 .word 0xf7f91330
 *   @0x2ad7d8 .word 0xf8c4fa91
 *   @0x2ad7dc eor r5, r5, r0, lsr r3
 *   @0x2ad7e0 movs r6, #0x0
 *   @0x2ad7e4 ldr.w r3, [r4, #0x330]
 *   @0x2ad7e8 mov r1, r7
 *   @0x2ad7ec mov r2, r5
 *   @0x2ad7f0 str r3, [r0, #0x4]
 *   @0x2ad7f4 ldr.w r3, [r4, #0x330]
 *   @0x2ad7f8 add r3, r8
 *   @0x2ad7fc ldr r3, [sp, #0xc]
 *   @0x2ad800 movs r3, #0x1
 *   @0x2ad804 bl 0x2aeef8 <png_set_text_2>
 *   @0x2ad808 mov r1, r5
 *   @0x2ad80c mov r0, r4
 *   @0x2ad810 qsub16mi pc, r0, r5
 *   @0x2ad814 ldr.w r1, [r4, #0x330]
 *   @0x2ad818 bl 0x2a6cfc <png_free>
 *   @0x2ad81c str.w r6, [r4, #0x330]
 *   @0x2ad820 cbz r7, 0x2ad82c <png_handle_zTXt+0x160>
 *   @0x2ad824 mov r0, r4
 *   @0x2ad828 bl 0x2a642c <png_error>
 *   @0x2ad82c add sp, #0x10
 *   @0x2ad830 svclt #0x81f0
 *   @0x2ad834 lsls r2, r5, #0x3
 *   @0x2ad838 lsls r7, r5, #0x3
 *   @0x2ad83c lsls r4, r2, #0x3
 *   @0x2ad840 lsls r2, r7, #0x2
 *   @0x2ad844 lsls r7, r5, #0x2
 *   @0x2ad848 lsls r6, r4, #0x2
 *   @0x2ad84c lsls r2, r6, #0x1
 *
 * ══ §73/76 png_do_shift  0x2b0ad4  size 388  97 条（0x2b0ad4..0x2b0c58）
 * @func 0x2b0ad4 0x2b0c58  size 388  97 条
 * 部分覆盖: 本节 97/174 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x4eae38 / 0x3977c4 / 0x37fc14 / 0x4ba830 / png_do_shift+0x16e / 0x14af040
 * 字段偏移 top8: 0x10×3 / 0x-10×2 / 0x-20×2 / 0x-1×2 / 0x14×1 / 0x18×1 / 0x4×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0ad4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b0ad8 sub sp, #0x24
 *   @0x2b0adc cmp r5, #0x3
 *   @0x2b0ae0 .word 0xf01580b8
 *   @0x2b0ae4 bvc 0x13746f4 <b2_toiTime+0xc1b250>
 *   @0x2b0ae8 beq 0x2b0b06 <png_do_shift+0x32>
 *   @0x2b0aec subs r6, r3, r4
 *   @0x2b0af0 str r4, [sp, #0x10]
 *   @0x2b0af4 subs r6, r3, r4
 *   @0x2b0af8 str r4, [sp, #0x14]
 *   @0x2b0afc subs r6, r3, r4
 *   @0x2b0b00 str r4, [sp, #0x18]
 *   @0x2b0b04 b 0x2b0b10 <png_do_shift+0x3c>
 *   @0x2b0b08 subs r6, r3, r4
 *   @0x2b0b0c str r4, [sp, #0x10]
 *   @0x2b0b10 lsls r5, r5, #0x1d
 *   @0x2b0b14 ldrb r6, [r2, #0x4]
 *   @0x2b0b18 add.w r5, r7, r4, lsl #2
 *   @0x2b0b1c adds r4, #0x1
 *   @0x2b0b20 str r6, [r5, #-16]
 *   @0x2b0b24 str r7, [r5, #-32]
 *   @0x2b0b28 cmp r3, #0x7
 *   @0x2b0b2c ldrb r2, [r2, #0x3]
 *   @0x2b0b30 cmp r2, #0x1
 *   @0x2b0b34 cmp r3, #0x2
 *   @0x2b0b38 moveq r3, #0x55
 *   @0x2b0b3c b 0x2b0b4e <png_do_shift+0x7a>
 *   @0x2b0b40 bne 0x2b0b4c <png_do_shift+0x78>
 *   @0x2b0b44 ite eq
 *   @0x2b0b48 movne r3, #0xff
 *   @0x2b0b4c movs r3, #0xff
 *   @0x2b0b50 add.w r12, r1, r4
 *   @0x2b0b54 ldr r0, [sp, #0x10]
 *   @0x2b0b58 .word 0xf1c50900
 *   @0x2b0b5c .word 0xf1c00a00
 *   @0x2b0b60 strbmi r0, [r1, #-0x800]!
 *   @0x2b0b64 beq 0x2b0c52 <png_do_shift+0x17e>
 *   @0x2b0b68 mov r2, r5
 *   @0x2b0b6c strb r9, [r1], #1
 *   @0x2b0b70 cmp r2, r8
 *   @0x2b0b74 cmp r2, #0x0
 *   @0x2b0b78 svclt #0xd67c01
 *   @0x2b0b7c asrle.w r11, r6, r4
 *   @0x2b0b80 lslgt.w r11, r6, r2
 *   @0x2b0b84 andle.w r11, r11, r3
 *   @0x2b0b88 subs r2, r2, r0
 *   @0x2b0b8c strmi r0, [r4], #-1799
 *   @0x2b0b90 strb r7, [r1, #-1]
 *   @0x2b0b94 b 0x2b0b70 <png_do_shift+0x9c>
 *   @0x2b0b98 ldr r3, [r0]
 *   @0x2b0b9c .word 0xd128f804
 *   @0x2b0ba0 movs r6, #0x0
 *   @0x2b0ba4 mov r9, r6
 *   @0x2b0ba8 beq 0x2b0c52 <png_do_shift+0x17e>
 *   @0x2b0bac mov r1, r4
 *   @0x2b0bb0 blge 0x4eae38 <SrcVerts+0x47e7c>
 *   @0x2b0bb4 ldrb r0, [r5]
 *   @0x2b0bb8 bl 0x3977c4 <ft_adobe_glyph_list+0x6ea0>
 *   @0x2b0bbc .word 0xf8510181
 *   @0x2b0bc0 .word 0xf8513c20
 *   @0x2b0bc4 subsmi r1, r10, #16, #24
 *   @0x2b0bc8 rsb.w r12, r1, #0x0
 *   @0x2b0bcc cmp r3, r12
 *   @0x2b0bd0 cmp r3, #0x0
 *   @0x2b0bd4 svclt #0xcc7c01
 *   @0x2b0bd8 lslgt.w r10, r0, r3
 *   @0x2b0bdc asrle.w r10, r0, r2
 *   @0x2b0be0 orr.w r7, r10, r7
 *   @0x2b0be4 subs r3, r3, r1
 *   @0x2b0be8 strmi r7, [r10], #-3073
 *   @0x2b0bec b 0x2b0bcc <png_do_shift+0xf8>
 *   @0x2b0bf0 b 0x2b0ba6 <png_do_shift+0xd2>
 *   @0x2b0bf4 movs r6, #0x0
 *   @0x2b0bf8 beq 0x2b0c52 <png_do_shift+0x17e>
 *   @0x2b0bfc mov r1, r4
 *   @0x2b0c00 .word 0xf815e878
 *   @0x2b0c04 .word 0xf8157c02
 *   @0x2b0c08 bl 0x37fc14 <_ZTS13C_UTF16String+0x16cc0>
 *   @0x2b0c0c blge 0x4ba830 <SrcVerts+0x17874>
 *   @0x2b0c10 uxth r7, r7
 *   @0x2b0c14 movwhs r0, #0x181
 *   @0x2b0c18 ldr r0, [r1, #-16]
 *   @0x2b0c1c ldr r2, [r1, #-32]
 *   @0x2b0c20 rsb.w r12, r0, #0x0
 *   @0x2b0c24 rsbs r1, r2, #0
 *   @0x2b0c28 ble 0x2b0c42 <png_do_shift+0x16e>
 *   @0x2b0c2c ite gt
 *   @0x2b0c30 blx 0x14af040 <b2_toiTime+0xd55b9c>
 *   @0x2b0c34 b 0x13af040 <b2_toiTime+0xc55b9c>
 *   @0x2b0c38 bne 0x731864 <g_SWFvertbuff+0x5e79c>
 *   @0x2b0c3c add r1, r0
 *   @0x2b0c40 b 0x2b0c26 <png_do_shift+0x152>
 *   @0x2b0c44 strb r3, [r5, #-1]
 *   @0x2b0c48 strb r2, [r5, #-2]
 *   @0x2b0c4c adds r6, #0x1
 *   @0x2b0c50 b 0x2b0bf6 <png_do_shift+0x122>
 *   @0x2b0c54 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §74/76 b2CircleShape::RayCast(b2RayCastOutput*, b2RayCastInput const&, b2Transform const&, int) const  0x2c4fc0  size 388  97 条（0x2c4fc0..0x2c5144）
 * @func 0x2c4fc0 0x2c5144  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700×2 / b2CircleShape::RayCast(b2RayCastOutput*, b2RayCastInput const&, b2Transform const&, int) const+0xa0
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 74 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4fc0 str lr, [sp, #-0x4]!
 *   @0x2c4fc4 vldr s10, [r3, #12]
 *   @0x2c4fc8 vpush {d8, d9, d10}
 *   @0x2c4fcc vldr s18, [r0, #16]
 *   @0x2c4fd0 vmul.f32 s15, s10, s18
 *   @0x2c4fd4 vldr s9, [r3, #8]
 *   @0x2c4fd8 vldr s11, [r0, #12]
 *   @0x2c4fdc vldr s20, [r3, #4]
 *   @0x2c4fe0 vldr s12, [r2, #4]
 *   @0x2c4fe4 vldr s8, [r3]
 *   @0x2c4fe8 vldr s13, [r2]
 *   @0x2c4fec vldr s21, [r2, #12]
 *   @0x2c4ff0 vldr s19, [r2, #8]
 *   @0x2c4ff4 vldr s14, [r0, #8]
 *   @0x2c4ff8 sub sp, sp, #12
 *   @0x2c4ffc vmla.f32 s15, s11, s9
 *   @0x2c5000 vmul.f32 s18, s9, s18
 *   @0x2c5004 vnmls.f32 s18, s10, s11
 *   @0x2c5008 vadd.f32 s20, s15, s20
 *   @0x2c500c vsub.f32 s20, s12, s20
 *   @0x2c5010 vadd.f32 s18, s18, s8
 *   @0x2c5014 vmul.f32 s15, s20, s20
 *   @0x2c5018 vsub.f32 s18, s13, s18
 *   @0x2c501c vsub.f32 s21, s21, s12
 *   @0x2c5020 vmla.f32 s15, s18, s18
 *   @0x2c5024 vmul.f32 s17, s21, s21
 *   @0x2c5028 vsub.f32 s19, s19, s13
 *   @0x2c502c vmls.f32 s15, s14, s14
 *   @0x2c5030 vmla.f32 s17, s19, s19
 *   @0x2c5034 vmul.f32 s16, s20, s21
 *   @0x2c5038 vmla.f32 s16, s18, s19
 *   @0x2c503c vmul.f32 s15, s15, s17
 *   @0x2c5040 vnmls.f32 s15, s16, s16
 *   @0x2c5044 vcmpe.f32 s15, #0
 *   @0x2c5048 vmrs APSR_nzcv, fpscr
 *   @0x2c504c bmi 0x2c5060 <_ZNK13b2CircleShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0xa0>
 *   @0x2c5050 vldr s14, [pc, #232]
 *   @0x2c5054 vcmpe.f32 s17, s14
 *   @0x2c5058 vmrs APSR_nzcv, fpscr
 *   @0x2c505c bpl 0x2c5070 <_ZNK13b2CircleShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0xb0>
 *   @0x2c5060 mov r0, #0
 *   @0x2c5064 add sp, sp, #12
 *   @0x2c5068 vpop {d8, d9, d10}
 *   @0x2c506c ldr pc, [sp], #4
 *   @0x2c5070 vsqrt.f32 s14, s15
 *   @0x2c5074 vcmp.f32 s14, s14
 *   @0x2c5078 vmrs APSR_nzcv, fpscr
 *   @0x2c507c bne 0x2c5110 <_ZNK13b2CircleShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x150>
 *   @0x2c5080 vadd.f32 s14, s16, s14
 *   @0x2c5084 vneg.f32 s14, s14
 *   @0x2c5088 vcmpe.f32 s14, #0
 *   @0x2c508c vmrs APSR_nzcv, fpscr
 *   @0x2c5090 blt 0x2c5060 <_ZNK13b2CircleShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0xa0>
 *   @0x2c5094 vldr s15, [r2, #16]
 *   @0x2c5098 vmul.f32 s15, s17, s15
 *   @0x2c509c vcmpe.f32 s14, s15
 *   @0x2c50a0 vmrs APSR_nzcv, fpscr
 *   @0x2c50a4 bhi 0x2c5060 <_ZNK13b2CircleShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0xa0>
 *   @0x2c50a8 vdiv.f32 s14, s14, s17
 *   @0x2c50ac vmla.f32 s20, s14, s21
 *   @0x2c50b0 vstr s14, [r1, #8]
 *   @0x2c50b4 vmla.f32 s18, s14, s19
 *   @0x2c50b8 vstr s20, [r1, #4]
 *   @0x2c50bc vmul.f32 s20, s20, s20
 *   @0x2c50c0 vstr s18, [r1]
 *   @0x2c50c4 vmla.f32 s20, s18, s18
 *   @0x2c50c8 vsqrt.f32 s15, s20
 *   @0x2c50cc vcmp.f32 s15, s15
 *   @0x2c50d0 vmrs APSR_nzcv, fpscr
 *   @0x2c50d4 bne 0x2c5128 <_ZNK13b2CircleShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x168>
 *   @0x2c50d8 vldr s14, [pc, #96]
 *   @0x2c50dc vcmpe.f32 s15, s14
 *   @0x2c50e0 vmrs APSR_nzcv, fpscr
 *   @0x2c50e4 vmovpl.f32 s12, #1.000000e+00
 *   @0x2c50e8 vldrpl s14, [r1]
 *   @0x2c50ec vldrpl s13, [r1, #4]
 *   @0x2c50f0 movpl r0, #1
 *   @0x2c50f4 movmi r0, #1
 *   @0x2c50f8 vdivpl.f32 s15, s12, s15
 *   @0x2c50fc vmulpl.f32 s14, s14, s15
 *   @0x2c5100 vmulpl.f32 s15, s13, s15
 *   @0x2c5104 vstrpl s14, [r1]
 *   @0x2c5108 vstrpl s15, [r1, #4]
 *   @0x2c510c b 0x2c5064 <_ZNK13b2CircleShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0xa4>
 *   @0x2c5110 vmov r0, s15
 *   @0x2c5114 stm sp, {r1, r2}
 *   @0x2c5118 bl 0xb6700 <sqrtf@plt>
 *   @0x2c511c ldm sp, {r1, r2}
 *   @0x2c5120 vmov s14, r0
 *   @0x2c5124 b 0x2c5080 <_ZNK13b2CircleShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0xc0>
 *   @0x2c5128 vmov r0, s20
 *   @0x2c512c str r1, [sp]
 *   @0x2c5130 bl 0xb6700 <sqrtf@plt>
 *   @0x2c5134 ldr r1, [sp]
 *   @0x2c5138 vmov s15, r0
 *   @0x2c513c b 0x2c50d8 <_ZNK13b2CircleShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x118>
 *   @0x2c5140 strlo r0, [r0], #-0
 *
 * ══ §75/76 Audio_StopSoundNoise(CNoise*, bool)  0x21a0b0  size 352  81 条（0x21a0b0..0x21a210）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x21a0b0 0x21a210  size 352  81 条
 * 部分覆盖: 本节 81/88 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21a0bc→0x755363, 0x21a0fc→0x75531c, 0x21a1a0→0x75531c, 0x21a1d0→0x3eb70c
 * 调用序列: Audio_GetSound(int) / 0xb6b14 / 0xb6a54
 * 字段偏移 top8: 0x10×3 / 0x18×3 / 0x138×2 / 0x8×2 / 0x24×2 / 0x2×2 / 0x30×2 / 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21a0b0 push {r3, r4, r5, lr}
 *   @0x21a0d0 popne {r3, r4, r5, pc}
 *   @0x21a0d4 cmp r0, #0
 *   @0x21a0d8 popeq {r3, r4, r5, pc}
 *   @0x21a0dc ldrb r3, [r0, #0x5]
 *   @0x21a0e0 cmp r3, #0
 *   @0x21a0e4 beq 0x21a138 <_Z20Audio_StopSoundNoiseP6CNoiseb+0x88>
 *   @0x21a0e8 cmp r1, #0
 *   @0x21a0ec bne 0x21a15c <_Z20Audio_StopSoundNoiseP6CNoiseb+0xac>
 *   @0x21a0f0 ldr r3, [r4, #0x8]
 *   @0x21a0f4 cmp r3, #0
 *   @0x21a0f8 popne {r3, r4, r5, pc}
 *   @0x21a0fc ldr r3, [pc, #0xfc]
 *   @0x21a100 mov r1, #1
 *   @0x21a104 mov r2, #0
 *   @0x21a108 str r1, [r4, #0x8]
 *   @0x21a10c str r2, [r4, #0x24]
 *   @0x21a110 movw r1, #0x6b28
 *   @0x21a114 movt r1, #0xce6e
 *   @0x21a118 str r1, [r4, #0x1c]
 *   @0x21a11c ldr r3, [r5, r3]
 *   @0x21a120 movw r1, #0x100a
 *   @0x21a124 ldr r0, [r4, #0x10]
 *   @0x21a128 ldr r3, [r3]
 *   @0x21a12c ldr r0, [r3, r0, lsl #2]
 *   @0x21a130 pop {r3, r4, r5, lr}
 *   @0x21a134 b 0xb6a78 <alSourcef@plt>
 *   @0x21a138 ldr r2, [r0, #0x18]
 *   @0x21a13c movw r3, #0x869f
 *   @0x21a140 movt r3, #0x1
 *   @0x21a144 sub r2, r2, #199680
 *   @0x21a148 sub r2, r2, #320
 *   @0x21a14c cmp r2, r3
 *   @0x21a150 pophi {r3, r4, r5, pc}
 *   @0x21a154 cmp r1, #0
 *   @0x21a158 beq 0x21a0f0 <_Z20Audio_StopSoundNoiseP6CNoiseb+0x40>
 *   @0x21a15c mov r3, #1
 *   @0x21a160 ldr r0, [r4, #0x18]
 *   @0x21a164 strb r3, [r4, #0xd]
 *   @0x21a168 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x21a16c cmp r0, #0
 *   @0x21a170 beq 0x21a1a0 <_Z20Audio_StopSoundNoiseP6CNoiseb+0xf0>
 *   @0x21a174 ldrb r3, [r0, #0x24]
 *   @0x21a178 cmp r3, #0
 *   @0x21a17c beq 0x21a194 <_Z20Audio_StopSoundNoiseP6CNoiseb+0xe4>
 *   @0x21a180 ldr r0, [pc, #0x7c]
 *   @0x21a184 ldr r1, [r4, #0x10]
 *   @0x21a188 add r0, pc, r0
 *   @0x21a18c pop {r3, r4, r5, lr}
 *   @0x21a190 b 0x226404 <_ZN9COggAudio10Stop_SoundEi>
 *   @0x21a194 ldrb r3, [r0, #0x25]
 *   @0x21a198 cmp r3, #0
 *   @0x21a19c bne 0x21a180 <_Z20Audio_StopSoundNoiseP6CNoiseb+0xd0>
 *   @0x21a1a0 ldr r3, [pc, #0x58]
 *   @0x21a1a4 ldr r2, [r4, #0x10]
 *   @0x21a1a8 ldr r3, [r5, r3]
 *   @0x21a1ac ldr r3, [r3]
 *   @0x21a1b0 ldr r0, [r3, r2, lsl #2]
 *   @0x21a1b4 bl 0xb6b14 <alSourceStop@plt>
 *   @0x21a1b8 bl 0xb6a54 <alGetError@plt>
 *   @0x21a1bc subs r3, r0, #0
 *   @0x21a1c0 bne 0x21a1d0 <_Z20Audio_StopSoundNoiseP6CNoiseb+0x120>
 *   @0x21a1c4 mov r0, r4
 *   @0x21a1c8 pop {r3, r4, r5, lr}
 *   @0x21a1cc b 0x21a048 <_Z22Audio_SetNoiseInactiveP6CNoise>
 *   @0x21a1d0 ldr r0, [pc, #0x30]
 *   @0x21a1d4 ldr r1, [pc, #0x30]
 *   @0x21a1d8 ldr r2, [r4, #0x18]
 *   @0x21a1dc ldr r0, [r5, r0]
 *   @0x21a1e0 add r1, pc, r1
 *   @0x21a1e4 ldr r0, [r0]
 *   @0x21a1e8 ldr r12, [r0]
 *   @0x21a1ec ldr r12, [r12, #0xc]
 *   @0x21a1f0 blx r12
 *   @0x21a1f4 b 0x21a1c4 <_Z20Audio_StopSoundNoiseP6CNoiseb+0x114>
 *   @0x21a1f8 mulseq sp, r0, r11
 *   @0x21a1fc .word 0xffffd3fc
 *   @0x21a200 .word 0xfffff77c
 *   @0x21a204 subseq r11, r3, r12, lsl #2
 *   @0x21a208 .word 0xffffbac4
 *   @0x21a20c andseq r9, r3, r0, lsl #28
 *
 * ══ §76/76 TConsole::Output(char const*, ...)  0xc481c  size 12  3 条（0xc481c..0xc4828）
 * @func 0xc481c 0xc4828  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc481c push {r1, r2, r3}
 *   @0xc4820 add sp, sp, #12
 *   @0xc4824 bx lr
 */
