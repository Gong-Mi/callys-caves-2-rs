/* cally 逆向卡：All_29 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 29 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/29 png_build_gamma_table  0x2aaca0  size 1236  309 条（0x2aaca0..0x2ab174）
 * @func 0x2aaca0 0x2ab174  size 1236  309 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6784×5 / png_malloc×3 / png_calloc×2 / png_build_gamma_table+0x1ac / png_build_gamma_table+0x1e0 / 0x15756e4 / 0xc6af4c / 0x52cfb0
 * 字段偏移 top8: 0x4×2 / 0x22c×1 / 0xb0×1 / 0x228×1
 * VFP 指令 84 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aaca0 cmp r1, #0x8
 *   @0x2aaca4 stc p15, c4, [sp, #-960]!
 *   @0x2aaca8 strmi r8, [r4], -lr, lsl #22
 *   @0x2aacac vldr s13, [r0, #548]
 *   @0x2aacb0 sub sp, #0xc
 *   @0x2aacb4 .word 0xeeb79ba9
 *   @0x2aacb8 .word 0xf2008b00
 *   @0x2aacbc cdp p0, #0xb, c8, c7, c5, #0x5
 *   @0x2aacc0 vcmpe.f32 s14, s13
 *   @0x2aacc4 vsqrt.f64 d23, d9
 *   @0x2aacc8 vstrle s30, [r8, #-64]
 *   @0x2aaccc vldr s24, [r0, #544]
 *   @0x2aacd0 vmul.f32 s24, s13, s24
 *   @0x2aacd4 vcvt.f64.f32 d12, s24
 *   @0x2aacd8 vdiv.f64 d12, d8, d12
 *   @0x2aacdc b 0x2aace2 <png_build_gamma_table+0x42>
 *   @0x2aace0 strtmi r12, [r0], -r8, asr #22
 *   @0x2aace4 mov.w r1, #0x100
 *   @0x2aace8 bl 0x2a6ca0 <png_malloc>
 *   @0x2aacec movs r5, #0x0
 *   @0x2aacf0 vldr d14, [pc]
 *   @0x2aacf4 .word 0xf8c4bb9b
 *   @0x2aacf8 cdp p2, #0x0, c0, c6, c8, #0x1
 *   @0x2aacfc .word 0xf8d45a10
 *   @0x2aad00 mrrc p2, #0x2, r6, r3, c8
 *   @0x2aad04 vldr d2, [pc, #112]
 *   @0x2aad08 .word 0xeeb8ab96
 *   @0x2aad0c .word 0xee877bc6
 *   @0x2aad10 .word 0xec516b0b
 *   @0x2aad14 .word 0xf60b0b16
 *   @0x2aad18 mrc p13, #0x5, lr, c0, c6, #0x1
 *   @0x2aad1c .word 0xeeb67b4e
 *   @0x2aad20 .word 0xec41db00
 *   @0x2aad24 .word 0xee060b16
 *   @0x2aad28 vmov.f64 d23, #-2.109375e-01
 *   @0x2aad2c vnmla.f64 d6, d22, d7
 *   @0x2aad30 ldrbpl r3, [r3, #-0xa90]!
 *   @0x2aad34 adds r5, #0x1
 *   @0x2aad38 bicsle r7, lr, r0, lsl #31
 *   @0x2aad3c ldr.w r2, [r4, #0x134]
 *   @0x2aad40 ldr r3, [pc, #0x22c]
 *   @0x2aad44 cmp r3, #0x0
 *   @0x2aad48 ldc p2, c8, [r4, #16]
 *   @0x2aad4c .word 0xeeb7ba88
 *   @0x2aad50 strtmi r11, [r9], -r11, asr #21
 *   @0x2aad54 mov r0, r4
 *   @0x2aad58 strhs pc, [r0, #-0xfa3]
 *   @0x2aad5c vdiv.f64 d11, d8, d11
 *   @0x2aad60 str.w r0, [r4, #0x230]
 *   @0x2aad64 vmov s12, r5
 *   @0x2aad68 ldr.w r6, [r4, #0x230]
 *   @0x2aad6c vmov r2, r3, d11
 *   @0x2aad70 vcvt.f64.s32 d7, s12
 *   @0x2aad74 vdiv.f64 d6, d7, d10
 *   @0x2aad78 vmov r0, r1, d6
 *   @0x2aad7c blx 0xb6784 <pow@plt>
 *   @0x2aad80 vmov.f64 d7, d13
 *   @0x2aad84 vmov d6, r0, r1
 *   @0x2aad88 vmla.f64 d7, d6, d10
 *   @0x2aad8c vcvt.u32.f64 s13, d7
 *   @0x2aad90 vmov r3, s13
 *   @0x2aad94 strb r3, [r6, r5]
 *   @0x2aad98 cmp.w r5, #0x100
 *   @0x2aad9c bne 0x2aad64 <png_build_gamma_table+0xc4>
 *   @0x2aada0 mov r0, r4
 *   @0x2aada4 ldc p15, c15, [r4, #500]
 *   @0x2aada8 .word 0xeeb77a89
 *   @0x2aadac strhs r7, [r0, #-0xac7]
 *   @0x2aadb0 vcmpe.f64 d7, d9
 *   @0x2aadb4 vmrs APSR_nzcv, fpscr
 *   @0x2aadb8 ite gt
 *   @0x2aadbc vldr d8, [r4, #28]
 *   @0x2aadc0 .word 0xf8c48a88
 *   @0x2aadc4 svclt #0xd8022c
 *   @0x2aadc8 vcvtle.f64.f32 d8, s16
 *   @0x2aadcc vmov s12, r5
 *   @0x2aadd0 ldr.w r6, [r4, #0x22c]
 *   @0x2aadd4 vmov r2, r3, d8
 *   @0x2aadd8 vcvt.f64.s32 d7, s12
 *   @0x2aaddc vdiv.f64 d6, d7, d10
 *   @0x2aade0 vmov r0, r1, d6
 *   @0x2aade4 blx 0xb6784 <pow@plt>
 *   @0x2aade8 vmov.f64 d7, d13
 *   @0x2aadec vmov d6, r0, r1
 *   @0x2aadf0 vmla.f64 d7, d6, d10
 *   @0x2aadf4 vcvt.u32.f64 s13, d7
 *   @0x2aadf8 vmov r3, s13
 *   @0x2aadfc strb r3, [r6, r5]
 *   @0x2aae00 cmp.w r5, #0x100
 *   @0x2aae04 bne 0x2aadcc <png_build_gamma_table+0x12c>
 *   @0x2aae08 ldrb.w r3, [r0, #0x1ea]
 *   @0x2aae0c lsls r2, r3, #0x1e
 *   @0x2aae10 ldrb.w r3, [r0, #0x240]
 *   @0x2aae14 ldrb.w r5, [r0, #0x241]
 *   @0x2aae18 cmp r5, r3
 *   @0x2aae1c movlt r5, r3
 *   @0x2aae20 adcmi r3, r11, #536870916
 *   @0x2aae24 bgt 0x2aae30 <png_build_gamma_table+0x190>
 *   @0x2aae28 ldrb.w r5, [r0, #0x243]
 *   @0x2aae2c cbnz r5, 0x2aae32 <png_build_gamma_table+0x192>
 *   @0x2aae30 mov r5, r3
 *   @0x2aae34 .word 0xf8d40510
 *   @0x2aae38 ldrbeq r3, [r11, #-0x134]
 *   @0x2aae3c bpl 0x2aae42 <png_build_gamma_table+0x1a2>
 *   @0x2aae40 ble 0x2aae4c <png_build_gamma_table+0x1ac>
 *   @0x2aae44 bgt 0x2aae50 <png_build_gamma_table+0x1b0>
 *   @0x2aae48 and r7, r2, r5, ror #11
 *   @0x2aae4c movs r5, #0x5
 *   @0x2aae50 movs r5, #0x8
 *   @0x2aae54 .word 0xf1c57ae6
 *   @0x2aae58 strhs r0, [r1], -r8, lsl #18
 *   @0x2aae5c str.w r5, [r4, #0x21c]
 *   @0x2aae60 lsl.w r6, r6, r9
 *   @0x2aae64 vcmpe.f64 d7, d9
 *   @0x2aae68 vmrs APSR_nzcv, fpscr
 *   @0x2aae6c ble 0x2aae80 <png_build_gamma_table+0x1e0>
 *   @0x2aae70 vmul.f32 s20, s13, s16
 *   @0x2aae74 .word 0xeeb7aa8a
 *   @0x2aae78 .word 0xee88aaca
 *   @0x2aae7c and r10, r1, r10, lsl #22
 *   @0x2aae80 vmov.f64 d10, #1.000000e+00
 *   @0x2aae84 lsls r2, r6, #0x2
 *   @0x2aae88 str r2, [sp]
 *   @0x2aae8c bl 0x2a6cd8 <png_calloc>
 *   @0x2aae90 ldr.w r7, [r4, #0x134]
 *   @0x2aae94 ands r7, r7, #0x480
 *   @0x2aae98 str.w r0, [r4, #0x234]
 *   @0x2aae9c beq 0x2aaf74 <png_build_gamma_table+0x2d4>
 *   @0x2aaea0 mov r0, r4
 *   @0x2aaea4 .word 0xf8d47100
 *   @0x2aaea8 .word 0xf7fb8234
 *   @0x2aaeac .word 0xf848fef9
 *   @0x2aaeb0 strlo r0, [r1, -r7, lsr #32]
 *   @0x2aaeb4 cmp r7, r6
 *   @0x2aaeb8 vdiv.f64 d10, d8, d10
 *   @0x2aaebc mov.w r11, #0xff
 *   @0x2aaec0 movs r7, #0x0
 *   @0x2aaec4 blx 0x15756e4 <b2_toiTime+0xe1c240>
 *   @0x2aaec8 ldrtmi pc, [r8], r5, lsl #22
 *   @0x2aaecc vldr d12, [pc, #152]
 *   @0x2aaed0 vmov.f64 d11, #5.000000e-01
 *   @0x2aaed4 vmov s12, r8
 *   @0x2aaed8 vmov r2, r3, d10
 *   @0x2aaedc vcvt.f64.s32 d7, s12
 *   @0x2aaee0 vadd.f64 d7, d7, d11
 *   @0x2aaee4 vmul.f64 d6, d7, d12
 *   @0x2aaee8 vmov r0, r1, d6
 *   @0x2aaeec blx 0xb6784 <pow@plt>
 *   @0x2aaef0 orr.w r2, r8, r8, lsl #8
 *   @0x2aaef4 vmov s13, r10
 *   @0x2aaef8 uxth r2, r2
 *   @0x2aaefc .word 0xec417be6
 *   @0x2aaf00 .word 0xee260b16
 *   @0x2aaf04 vmov.f64 d7, #-1.796875e-01
 *   @0x2aaf08 vnmla.f64 d7, d23, d7
 *   @0x2aaf0c addsmi r3, pc, #16, #20
 *   @0x2aaf10 bhi 0x2aaf2a <png_build_gamma_table+0x28a>
 *   @0x2aaf14 b 0x4777ec <g_RomDisk+0x7ffcc>
 *   @0x2aaf18 blx 0xc6af4c <b2_toiTime+0x511aa8>
 *   @0x2aaf1c strlo pc, [r1, -r9, lsl #2]
 *   @0x2aaf20 ldr.w r3, [r3, r0, lsl #2]
 *   @0x2aaf24 strh.w r2, [r3, r1, lsl #1]
 *   @0x2aaf28 b 0x2aaf0a <png_build_gamma_table+0x26a>
 *   @0x2aaf2c .word 0xf5b80801
 *   @0x2aaf30 bicle r7, pc, r0, lsl #31
 *   @0x2aaf34 movw r2, #0xffff
 *   @0x2aaf38 cmp r7, r10
 *   @0x2aaf3c ldr.w r3, [r4, #0x234]
 *   @0x2aaf40 and.w r0, r7, r11
 *   @0x2aaf44 lsr.w r1, r7, r9
 *   @0x2aaf48 adds r7, #0x1
 *   @0x2aaf4c .word 0xf8233020
 *   @0x2aaf50 .word 0xe7f12011
 *   @0x2aaf54 nop.w
 *   @0x2aaf58 stc p0, c10, [sp, #724]
 *   @0x2aaf5c stm r6!, {r0, r1, r2, r4, r5, r6, r7}
 *   @0x2aaf60 movs r0, r0
 *   @0x2aaf64 b 0x2aaf68 <png_build_gamma_table+0x2c8>
 *   @0x2aaf68 movs r0, r0
 *   @0x2aaf6c movs r0, r0
 *   @0x2aaf70 lsls r0, r0, #0x2
 *   @0x2aaf74 vmov.f64 d12, #5.000000e-01
 *   @0x2aaf78 ldr.w r9, [pc, #0x1f0]
 *   @0x2aaf7c vldr d11, [pc, #480]
 *   @0x2aaf80 add r9, pc
 *   @0x2aaf84 strtmi r0, [r0], -r5, lsl #19
 *   @0x2aaf88 mov.w r1, #0x200
 *   @0x2aaf8c ldr.w r8, [r4, #0x234]
 *   @0x2aaf90 bl 0x2a6ca0 <png_malloc>
 *   @0x2aaf94 ldr.w r3, [r9, #0x18]
 *   @0x2aaf98 lsl.w r11, r7, #0x2
 *   @0x2aaf9c muls r3, r7, r3
 *   @0x2aafa0 .word 0xf8481a13
 *   @0x2aafa4 .word 0xf04f0027
 *   @0x2aafa8 bl 0x52cfb0 <SrcVerts+0x89ff4>
 *   @0x2aafac .word 0xf8d42208
 *   @0x2aafb0 mcr p2, #0x0, r3, c7, c4, #0x1
 *   @0x2aafb4 .word 0xf8532a10
 *   @0x2aafb8 cdp p0, #0xb, c3, c8, c11, #0x0
 *   @0x2aafbc movwls r7, #0x1bc7
 *   @0x2aafc0 vmov r2, r3, d10
 *   @0x2aafc4 vdiv.f64 d6, d7, d11
 *   @0x2aafc8 vmov r0, r1, d6
 *   @0x2aafcc blx 0xb6784 <pow@plt>
 *   @0x2aafd0 ldr r2, [sp, #0x4]
 *   @0x2aafd4 .word 0xec417b4c
 *   @0x2aafd8 .word 0xee060b16
 *   @0x2aafdc vmov.f64 d23, #-2.109375e-01
 *   @0x2aafe0 vnmla.f64 d6, d22, d7
 *   @0x2aafe4 .word 0xf8223a90
 *   @0x2aafe8 .word 0xf1083018
 *   @0x2aafec .word 0xf5b80801
 *   @0x2aaff0 bicsle r7, r10, r0, lsl #31
 *   @0x2aaff4 adds r7, #0x1
 *   @0x2aaff8 blt 0x2aaf86 <png_build_gamma_table+0x2e6>
 *   @0x2aaffc blmi 0x19334d4 <b2_toiTime+0x11da030>
 *   @0x2ab000 ands r3, r2
 *   @0x2ab004 beq.w 0x2ab152 <png_build_gamma_table+0x4b2>
 *   @0x2ab008 vldr s26, [r4, #544]
 *   @0x2ab00c vcvt.f64.f32 d13, s26
 *   @0x2ab010 mov r0, r4
 *   @0x2ab014 bl 0x2a6cd8 <png_calloc>
 *   @0x2ab018 ldr.w r9, [pc, #0x154]
 *   @0x2ab01c movs r7, #0x0
 *   @0x2ab020 ldrbtmi r11, [r9], #2896
 *   @0x2ab024 add.w r9, r9, r5, lsl #2
 *   @0x2ab028 vdiv.f64 d13, d8, d13
 *   @0x2ab02c str.w r0, [r4, #0x23c]
 *   @0x2ab030 vmov.f64 d12, #5.000000e-01
 *   @0x2ab034 mov r0, r4
 *   @0x2ab038 .word 0xf8d47100
 *   @0x2ab03c .word 0xf7fb523c
 *   @0x2ab040 b 0x16aa904 <b2_toiTime+0xf51460>
 *   @0x2ab044 .word 0xf04f0b87
 *   @0x2ab048 .word 0xf8450800
 *   @0x2ab04c .word 0xf8d90027
 *   @0x2ab050 blx 0x3ff0ba <g_RomDisk+0x789a>
 *   @0x2ab054 b 0x16aa078 <b2_toiTime+0xf50bd4>
 *   @0x2ab058 .word 0xf8d41a1c
 *   @0x2ab05c mrc p2, #0x5, r3, c6, c12, #0x1
 *   @0x2ab060 vldr d14, [pc]
 *   @0x2ab064 .word 0xf853ab3f
 *   @0x2ab068 movwls r3, #0x100b
 *   @0x2ab06c add.w r3, r10, r8, lsl #8
 *   @0x2ab070 vmov s14, r3
 *   @0x2ab074 vmov r2, r3, d13
 *   @0x2ab078 vcvt.f64.s32 d7, s14
 *   @0x2ab07c vdiv.f64 d6, d7, d11
 *   @0x2ab080 vmov r0, r1, d6
 *   @0x2ab084 blx 0xb6784 <pow@plt>
 *   @0x2ab088 ldr r2, [sp, #0x4]
 *   @0x2ab08c .word 0xec417b4c
 *   @0x2ab090 .word 0xee060b16
 *   @0x2ab094 vmov.f64 d23, #-2.109375e-01
 *   @0x2ab098 vnmla.f64 d6, d22, d7
 *   @0x2ab09c .word 0xf8223a90
 *   @0x2ab0a0 .word 0xf1083018
 *   @0x2ab0a4 .word 0xf5b80801
 *   @0x2ab0a8 bicsle r7, r6, r0, lsl #31
 *   @0x2ab0ac adds r7, #0x1
 *   @0x2ab0b0 blt 0x2ab034 <png_build_gamma_table+0x394>
 *   @0x2ab0b4 .word 0xeeb77a89
 *   @0x2ab0b8 strtmi r7, [r0], -r7, asr #21
 *   @0x2ab0bc ldr r1, [sp]
 *   @0x2ab0c0 strbmi r0, [pc], -r0, lsl #18
 *   @0x2ab0c4 vcmpe.f64 d7, d9
 *   @0x2ab0c8 vmrs APSR_nzcv, fpscr
 *   @0x2ab0cc itet le
 *   @0x2ab0d0 vdiv.f32 s16, s17, s16
 *   @0x2ab0d4 vmov.f64 d8, #1.437500e+00
 *   @0x2ab0d8 .word 0xf7fb8ac8
 *   @0x2ab0dc .word 0xf8c4fdfd
 *   @0x2ab0e0 qasxmi r0, r0, r8
 *   @0x2ab0e4 mov.w r1, #0x200
 *   @0x2ab0e8 ldr.w r8, [r4, #0x238]
 *   @0x2ab0ec bl 0x2a6ca0 <png_malloc>
 *   @0x2ab0f0 lsl.w r11, r7, #0x2
 *   @0x2ab0f4 lsr.w r10, r9, #0x4
 *   @0x2ab0f8 str.w r0, [r8, r7, lsl #2]
 *   @0x2ab0fc mov.w r8, #0x0
 *   @0x2ab100 ldr.w r3, [r4, #0x238]
 *   @0x2ab104 ldr.w r3, [r3, r11]
 *   @0x2ab108 str r3, [sp]
 *   @0x2ab10c cdp p3, #0x0, c2, c7, c8, #0x0
 *   @0x2ab110 vmov r3, r3, s0, s1
 *   @0x2ab114 .word 0xeeb82b18
 *   @0x2ab118 .word 0xee877bc7
 *   @0x2ab11c .word 0xec516b0a
 *   @0x2ab120 .word 0xf60b0b16
 *   @0x2ab124 bls 0x2e5dec <FT_Face_GetVariantsOfChar+0xe>
 *   @0x2ab128 vmov.f64 d7, d14
 *   @0x2ab12c vmov d6, r0, r1
 *   @0x2ab130 vmla.f64 d7, d6, d10
 *   @0x2ab134 vcvt.u32.f64 s13, d7
 *   @0x2ab138 vmov r3, s13
 *   @0x2ab13c strh.w r3, [r2, r8, lsl #1]
 *   @0x2ab140 add.w r8, r8, #0x1
 *   @0x2ab144 cmp.w r8, #0x100
 *   @0x2ab148 bne 0x2ab100 <png_build_gamma_table+0x460>
 *   @0x2ab14c add r9, r5
 *   @0x2ab150 blt 0x2ab0e2 <png_build_gamma_table+0x442>
 *   @0x2ab154 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2ab158 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ab15c nop.w
 *   @0x2ab160 movs r0, r0
 *   @0x2ab164 vmla.i32 q10, q8, d15[1]
 *   @0x2ab168 lsls r0, r0, #0x2
 *   @0x2ab16c ldr r2, [pc, #0xb0]
 *   @0x2ab170 ldr r1, [pc, #0x228]
 *
 * ══ §2/29 anon_3180e8  0x3180e8  size 1224  306 条（0x3180e8..0x3185b0）
 * @func 0x3180e8 0x3185b0  size 1224  306 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x31be08 / 0x31be78 / 0x1954326 / 0x13d4352 / 0x15d43aa / 0x12d43c2 / 0x18fd038 / 0x18fd040
 * 字段偏移 top8: 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3180e8 ldrlt r4, [r0, #-0xb04]
 *   @0x3180ec .word 0x4604447b
 *   @0x3180f0 andvs r3, r3, r8, lsl #6
 *   @0x3180f4 stc2l p0, c15, [r8], #0
 *   @0x3180f8 ldclt p6, c4, [r0, #-128]
 *   @0x3180fc ldrdeq r4, r5, [sp], -r0
 *   @0x318100 .word 0x4604b510
 *   @0x318104 .word 0xfff0f7ff
 *   @0x318108 .word 0xf7654620
 *   @0x31810c strtmi lr, [r0], -r2, ror #16
 *   @0x318110 svclt #0xbd10
 *   @0x318114 .word 0xf013b538
 *   @0x318118 strmi r0, [sp], -r1, lsl #6
 *   @0x31811c svclt #0x89c04
 *   @0x318120 .word 0xd1004618
 *   @0x318124 stmdbmi sp, {r3, r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x318128 ldrbtmi r6, [r9], #-2240
 *   @0x31812c .word 0xf0006809
 *   @0x318130 stmdahs r0, {r0, r1, r3, r4, r8, r11, r12, sp, lr, pc}
 *   @0x318134 stmvs r8!, {r1, r2, r4, r5, r6, r7, r12, lr, pc} ^
 *   @0x318138 stmdbmi r9, {r3, r5, r6, r8, r12, sp, pc}
 *   @0x31813c bmi 0x560d44 <g_SWFlineaavertbuff+0xdc7c>
 *   @0x318140 stmdavs r9, {r0, r3, r4, r5, r6, r10, lr}
 *   @0x318144 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr}
 *   @0x318148 ldc2l p7, c15, [r12], #-1020
 *   @0x31814c movwhs r11, #0x118
 *   @0x318150 eorvc r2, r3, r1
 *   @0x318154 andhs r11, r1, r8, lsr sp
 *   @0x318158 ldclt p0, c7, [r8, #-128]!
 *   @0x31815c andeq r9, sp, r6, ror #21
 *   @0x318160 andeq r9, sp, r4, asr #21
 *   @0x318164 ldrdeq r9, r10, [sp], -r0
 *   @0x318168 ldrbmi r2, [r0, -r1]!
 *   @0x31816c ldrlt r4, [r0, #-0xb04]
 *   @0x318170 .word 0x4604447b
 *   @0x318174 andvs r3, r3, r8, lsl #6
 *   @0x318178 .word 0xf8d2f7ff
 *   @0x31817c ldclt p6, c4, [r0, #-128]
 *   @0x318180 andeq r4, sp, r12, ror #30
 *   @0x318184 .word 0x4604b510
 *   @0x318188 .word 0xfff0f7ff
 *   @0x31818c .word 0xf7654620
 *   @0x318190 strtmi lr, [r0], -r0, lsr #16
 *   @0x318194 svclt #0xbd10
 *   @0x318198 .word 0x4607b5f8
 *   @0x31819c ldrmi r4, [r5], -lr, lsl #12
 *   @0x3181a0 .word 0xf7ff461c
 *   @0x3181a4 .word 0xb108f8d3
 *   @0x3181a8 ldcllt p0, c2, [r8, #4]!
 *   @0x3181ac .word 0x462368b8
 *   @0x3181b0 qasxmi r4, r10, r1
 *   @0x3181b4 stmdbvs r4!, {r2, r11, sp, lr}
 *   @0x3181b8 ldcllt p7, c4, [r8, #640]!
 *   @0x3181bc .word 0xf64cb508
 *   @0x3181c0 .word 0xf6cd23b1
 *   @0x3181c4 andhs r6, r0, #-1275068414
 *   @0x3181c8 .word 0xf59e701a
 *   @0x3181cc svclt #0xed5e
 *   @0x3181d0 tstlt r0, r8, lsl #10
 *   @0x3181d4 .word 0xf7ff4780
 *   @0x3181d8 stmdami r5, {r0, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3181dc .word 0x47804478
 *   @0x3181e0 .word 0xf7ffe7f9
 *   @0x3181e4 .word 0xf7fffa9d
 *   @0x3181e8 .word 0xf7fffad7
 *   @0x3181ec svclt #0xffe7
 *   @0x3181f0 .word 0xffffffdd
 *   @0x3181f4 andhs r4, r0, #9216
 *   @0x3181f8 .word 0xf3bf447b
 *   @0x3181fc ldmda r3, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11, pc} ^
 *   @0x318200 bl 0x31be08
 *   @0x318204 stmda r3, {r1, r8} ^
 *   @0x318208 .word 0xf0901000
 *   @0x31820c mvnsle r0, r0, lsl #30
 *   @0x318210 andeq lr, r2, r1, lsr #23
 *   @0x318214 svchi #0x5ff3bf
 *   @0x318218 svclt #0x4770
 *   @0x31821c andseq r1, r6, r8, lsl #17
 *   @0x318220 .word 0xb1684602
 *   @0x318224 ldrbtmi r4, [r11], #-2824
 *   @0x318228 svceq #0xe853
 *   @0x31822c .word 0x2100e843
 *   @0x318230 svceq #0xf091
 *   @0x318234 .word 0xf3bfd1f8
 *   @0x318238 .word 0xf3bf8f5f
 *   @0x31823c .word 0x47708f5f
 *   @0x318240 ldrbtmi r4, [r10], #-2562
 *   @0x318244 svclt #0xe7ee
 *   @0x318248 andseq r1, r6, r10, asr r8
 *   @0x31824c .word 0xffffff77
 *   @0x318250 .word 0xf7ffb508
 *   @0x318254 .word 0xf7ffffcf
 *   @0x318258 svclt #0xffbb
 *   @0x31825c .word 0xf7ffb508
 *   @0x318260 svclt #0xfff7
 *   @0x318264 andhs r4, r0, #9216
 *   @0x318268 .word 0xf3bf447b
 *   @0x31826c ldmda r3, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11, pc} ^
 *   @0x318270 bl 0x31be78
 *   @0x318274 stmda r3, {r1, r8} ^
 *   @0x318278 .word 0xf0901000
 *   @0x31827c mvnsle r0, r0, lsl #30
 *   @0x318280 andeq lr, r2, r1, lsr #23
 *   @0x318284 svchi #0x5ff3bf
 *   @0x318288 svclt #0x4770
 *   @0x31828c andseq r1, r6, r4, lsl r8
 *   @0x318290 .word 0xb1684602
 *   @0x318294 ldrbtmi r4, [r11], #-2824
 *   @0x318298 svceq #0xe853
 *   @0x31829c .word 0x2100e843
 *   @0x3182a0 svceq #0xf091
 *   @0x3182a4 .word 0xf3bfd1f8
 *   @0x3182a8 .word 0xf3bf8f5f
 *   @0x3182ac .word 0x47708f5f
 *   @0x3182b0 ldrbtmi r4, [r10], #-2562
 *   @0x3182b4 svclt #0xe7ee
 *   @0x3182b8 andseq r1, r6, r6, ror #15
 *   @0x3182bc .word 0xffffff07
 *   @0x3182c0 .word 0xf7ffb508
 *   @0x3182c4 smlabtlt r0, pc, pc, pc
 *   @0x3182c8 .word 0xf7ff4780
 *   @0x3182cc svclt #0xffc1
 *   @0x3182d0 ldrbtmi r4, [r11], #-2818
 *   @0x3182d4 andvs r3, r3, r8, lsl #6
 *   @0x3182d8 svclt #0x4770
 *   @0x3182dc andeq r4, sp, r2, asr lr
 *   @0x3182e0 ldrbtmi r4, [r8], #-2049
 *   @0x3182e4 svclt #0x4770
 *   @0x3182e8 andeq r4, r4, r2, lsr #6
 *   @0x3182ec ldrbtmi r4, [r8], #-2049
 *   @0x3182f0 svclt #0x4770
 *   @0x3182f4 andeq r4, r4, r6, lsr #6
 *   @0x3182f8 ldrlt r4, [r0, #-0xb04]
 *   @0x3182fc .word 0x4604447b
 *   @0x318300 andvs r3, r3, r8, lsl #6
 *   @0x318304 svc #0x64f764
 *   @0x318308 ldclt p6, c4, [r0, #-128]
 *   @0x31830c andeq r4, sp, r8, lsr #28
 *   @0x318310 ldrlt r4, [r0, #-0xb04]
 *   @0x318314 .word 0x4604447b
 *   @0x318318 andvs r3, r3, r8, lsl #6
 *   @0x31831c blx 0x1954326 <b2_toiTime+0x11fae82>
 *   @0x318320 ldclt p6, c4, [r0, #-128]
 *   @0x318324 strdeq r4, r5, [sp], -r8
 *   @0x318328 .word 0x4604b510
 *   @0x31832c .word 0xfff0f7ff
 *   @0x318330 .word 0xf7644620
 *   @0x318334 strtmi lr, [r0], -lr, asr #30
 *   @0x318338 svclt #0xbd10
 *   @0x31833c ldrlt r4, [r0, #-0xb04]
 *   @0x318340 .word 0x4604447b
 *   @0x318344 andvs r3, r3, r8, lsl #6
 *   @0x318348 blx 0x13d4352 <b2_toiTime+0xc7aeae>
 *   @0x31834c ldclt p6, c4, [r0, #-128]
 *   @0x318350 andeq r4, sp, r4, lsl #28
 *   @0x318354 .word 0x4604b510
 *   @0x318358 .word 0xfff0f7ff
 *   @0x31835c .word 0xf7644620
 *   @0x318360 qasxmi lr, r0, r8
 *   @0x318364 svclt #0xbd10
 *   @0x318368 stmdavs r0, {r3, r8, r10, r12, sp, pc} ^
 *   @0x31836c .word 0xf59e6849
 *   @0x318370 .word 0xf1d0e902
 *   @0x318374 svclt #0x380001
 *   @0x318378 stclt p0, c2, [r8, #-0]
 *   @0x31837c .word 0xf7ffb508
 *   @0x318380 .word 0xf080fff3
 *   @0x318384 sbclt r0, r0, #1
 *   @0x318388 svclt #0xbd08
 *   @0x31838c stmdavs r0, {r3, r8, r10, r12, sp, pc} ^
 *   @0x318390 .word 0xf59e6849
 *   @0x318394 svceq #0xc0e8f0
 *   @0x318398 svclt #0xbd08
 *   @0x31839c .word 0x4604b510
 *   @0x3183a0 blx 0x15d43aa <b2_toiTime+0xe7af06>
 *   @0x3183a4 strtmi r4, [r0], -r2, lsl #22
 *   @0x3183a8 movwlo r4, #0x847b
 *   @0x3183ac ldclt p0, c6, [r0, #-140]
 *   @0x3183b0 muleq sp, r12, sp
 *   @0x3183b4 .word 0x4604b510
 *   @0x3183b8 blx 0x12d43c2 <b2_toiTime+0xb7af1e>
 *   @0x3183bc strtmi r4, [r0], -r2, lsl #22
 *   @0x3183c0 movwlo r4, #0x847b
 *   @0x3183c4 ldclt p0, c6, [r0, #-140]
 *   @0x3183c8 andeq r4, sp, r12, asr #26
 *   @0x3183cc ldrbmi r2, [r0, -r2]!
 *   @0x3183d0 ldrlt r4, [r0, #-0xb04]
 *   @0x3183d4 .word 0x4604447b
 *   @0x3183d8 andvs r3, r3, r8, lsl #6
 *   @0x3183dc .word 0xffa0f7fe
 *   @0x3183e0 ldclt p6, c4, [r0, #-128]
 *   @0x3183e4 andeq r4, sp, r0, lsr #27
 *   @0x3183e8 .word 0x4604b510
 *   @0x3183ec .word 0xfff0f7ff
 *   @0x3183f0 .word 0xf7644620
 *   @0x3183f4 strtmi lr, [r0], -lr, ror #29
 *   @0x3183f8 svclt #0xbd10
 *   @0x3183fc svcmi #0xf0e92d
 *   @0x318400 strmi r11, [r5], -sp, lsl #1
 *   @0x318404 swpls r4, r3, [r1]
 *   @0x318408 .word 0xf7fe461e
 *   @0x31840c stmdahs r0, {r0, r1, r2, r3, r4, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x318410 addshi pc, r0, r0, asr #32
 *   @0x318414 movwls r6, #0x28eb
 *   @0x318418 rsbsle r2, r1, r0, lsl #22
 *   @0x31841c ssatmi r4, #0x9, r8, asr #22
 *   @0x318420 strtmi r4, [pc], -r4, lsl #12
 *   @0x318424 blmi 0x18fd038 <b2_toiTime+0x11a3b94>
 *   @0x318428 blmi 0x18fd040 <b2_toiTime+0x11a3b9c>
 *   @0x31842c blls 0x3fd048 <g_RomDisk+0x5828>
 *   @0x318430 movwls r4, #0x347b
 *   @0x318434 ldrbtmi r9, [r11], #-2820
 *   @0x318438 blls 0x47d050 <targetStr+0x1e10>
 *   @0x31843c movwls r4, #0x547b
 *   @0x318440 ldrtmi r10, [r9], -r7, lsl #16
 *   @0x318444 .word 0xff94f7fe
 *   @0x318448 sbceq lr, r4, #7168
 *   @0x31844c .word 0x3000f8db
 *   @0x318450 .word 0xf8d86952
 *   @0x318454 movwls r0, #0x6010
 *   @0x318458 beq 0x394468 <ft_adobe_glyph_list+0x3b44>
 *   @0x31845c stmdbeq r0, {r1, r6, r7, r8, r9, r12, sp, lr, pc} ^
 *   @0x318460 andsne r11, r2, #-1073741810
 *   @0x318464 svceq #0xf1ba
 *   @0x318468 ldmdavs r9, {r0, r12, lr, pc}
 *   @0x31846c ldmne r11, {r1, r3, r7, r11, r12, lr}
 *   @0x318470 .word 0xf1b99306
 *   @0x318474 .word 0xd1020f00
 *   @0x318478 .word 0x07da68f3
 *   @0x31847c stmdavs r5, {r1, r3, r4, r5, r8, r10, r12, lr, pc}
 *   @0x318480 stmdbls r1, {r1, r2, r9, r11, sp, pc}
 *   @0x318484 pushvs {r0, r1, r2, r8, r9, r11, sp, pc}
 *   @0x318488 stmdahs r0, {r3, r5, r7, r8, r9, r10, lr}
 *   @0x31848c .word 0xf1b9d032
 *   @0x318490 .word 0xd1010f00
 *   @0x318494 movwls r2, #0x7302
 *   @0x318498 svceq #0xf1ba
 *   @0x31849c ldmdavs r1!, {r0, r2, r4, r5, r8, r12, lr, pc} ^
 *   @0x3184a0 andsle r2, r12, r0, lsl #18
 *   @0x3184a4 stmdahs r0, {r3, r11, r12, pc}
 *   @0x3184a8 .word 0xf7ffd050
 *   @0x3184ac stmiblt r0, {r0, r1, r2, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3184b0 blhs 0x332784
 *   @0x3184b4 ldmdavs r0!, {r0, r2, r3, r5, r12, lr, pc} ^
 *   @0x3184b8 .word 0xf7ff9908
 *   @0x3184bc stmdahs r0, {r0, r2, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3184c0 ldmvs r3!, {r1, r3, r4, r5, r12, lr, pc}
 *   @0x3184c4 suble r2, sp, r0, lsl #22
 *   @0x3184c8 bhs 0x33ecf4
 *   @0x3184cc addsmi sp, r3, #74
 *   @0x3184d0 andhs sp, r1, r0, lsl r0
 *   @0x3184d4 eorsvs r2, r3, r2, lsl #6
 *   @0x3184d8 pop {r0, r2, r3, r12, sp, pc}
 *   @0x3184dc blls 0x53c4a4 <obj_has_event+0x1934>
 *   @0x3184e0 eorsle r2, r3, r0, lsl #22
 *   @0x3184e4 shadd16mi r2, r0, r1
 *   @0x3184e8 .word 0xf59ea907
 *   @0x3184ec ldmdavs r0!, {r3, r5, r6, r11, sp, lr, pc}
 *   @0x3184f0 suble r2, r0, r1, lsl #16
 *   @0x3184f4 strlo r9, [r1], #-2818
 *   @0x3184f8 stmdaeq r8, {r3, r8, r12, sp, lr, pc}
 *   @0x3184fc orrsle r4, pc, r3, lsr #5
 *   @0x318500 andlo r6, r0, r0, lsr r8
 *   @0x318504 andhs r11, r1, r8, lsl pc
 *   @0x318508 movwhs lr, #0x7e6
 *   @0x31850c eorlo pc, r12, sp, lsl #17
 *   @0x318510 blls 0x59242c <g_SWFlineaavertbuff+0x3f364>
 *   @0x318514 bicle r2, lr, r0, lsl #22
 *   @0x318518 blhs 0x3375ec
 *   @0x31851c .word 0xf89dd1d9
 *   @0x318520 blhs 0x3245d8
 *   @0x318524 ldmdavs r0!, {r0, r2, r4, r6, r7, r8, r12, lr, pc} ^
 *   @0x318528 .word 0xf7ff9908
 *   @0x31852c stmdahs r0, {r0, r2, r3, r4, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x318530 strb sp, [lr, r1, asr #1]
 *   @0x318534 strb r2, [pc, r1]
 *   @0x318538 orrhs r4, r10, r4, lsl r8
 *   @0x31853c blmi 0x86ad94 <b2_toiTime+0x1118f0>
 *   @0x318540 ldrbtmi r4, [r10], #-1144
 *   @0x318544 .word 0xf59e447b
 *   @0x318548 .word 0xe7baed32
 *   @0x31854c .word 0x216f4812
 *   @0x318550 blmi 0x7eada0 <b2_toiTime+0x918fc>
 *   @0x318554 ldrbtmi r4, [r10], #-1144
 *   @0x318558 .word 0xf59e447b
 *   @0x31855c stmdals r8, {r3, r5, r8, r10, r11, sp, lr, pc}
 *   @0x318560 .word 0xe7a26871
 *   @0x318564 orrhs r9, pc, r4, lsl #20
 *   @0x318568 stmdals r3, {r0, r2, r8, r9, r11, r12, pc}
 *   @0x31856c ldc p5, c15, [lr, #-632]
 *   @0x318570 bls 0x572844 <g_SWFlineaavertbuff+0x1f77c>
 *   @0x318574 ldmvs r11!, {r0, r1, r3, r5, r7, r8, r9, r10, sp, lr, pc}
 *   @0x318578 ldrtle r0, [r11], #2011
 *   @0x31857c svclt #0xe7ac
 *   @0x318580 strdeq r4, r5, [r4], -r4
 *   @0x318584 andeq sp, r8, lr, ror #2
 *   @0x318588 andeq r4, r4, r8, lsr #5
 *   @0x31858c andeq r4, r4, r4, ror #1
 *   @0x318590 andeq sp, r8, r2, rrx
 *   @0x318594 andeq r4, r4, r4, ror r1
 *   @0x318598 ldrdeq r4, r5, [r4], -r0
 *   @0x31859c andeq sp, r8, lr, asr #32
 *   @0x3185a0 andeq r4, r4, r4, lsr #2
 *   @0x3185a4 .word 0xf000b41e
 *   @0x3185a8 .word 0xbc1ef867
 *   @0x3185ac ldmda r8!, {r1, r12, sp, lr, pc}
 *
 * ══ §3/29 CDS_Grid::Resize(int, int)  0x20c3bc  size 1216  304 条（0x20c3bc..0x20c87c）
 * @func 0x20c3bc 0x20c87c  size 1216  304 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×3 / LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / CDS_Grid::SetSize(int, int) / CDS_Grid::Resize(int, int)+0x284 / CDS_Grid::Resize(int, int)+0x254
 * 字段偏移 top8: 0x4×31 / 0x8×26 / 0xc×22 / 0x18×7 / 0x-c×6 / 0x10×6 / 0x14×5 / 0x2c×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20c3bc ldr r12, [r0]
 *   @0x20c3c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20c3c4 sub sp, sp, #52
 *   @0x20c3c8 mov r4, #0
 *   @0x20c3cc ldr r6, [r0, #0x4]
 *   @0x20c3d0 str r12, [sp, #0x2c]
 *   @0x20c3d4 mov r8, r1
 *   @0x20c3d8 ldr r12, [r0, #0x8]
 *   @0x20c3dc str r4, [r0]
 *   @0x20c3e0 str r4, [r0, #0x4]
 *   @0x20c3e4 str r4, [r0, #0x8]
 *   @0x20c3e8 str r12, [sp, #0x24]
 *   @0x20c3ec str r2, [sp, #0x20]
 *   @0x20c3f0 str r0, [sp, #0x8]
 *   @0x20c3f4 bl 0x20affc <_ZN8CDS_Grid7SetSizeEii>
 *   @0x20c3f8 ldr r12, [sp, #0x20]
 *   @0x20c3fc ldr r3, [sp, #0x8]
 *   @0x20c400 cmp r12, r4
 *   @0x20c404 ble 0x20c640 <_ZN8CDS_Grid6ResizeEii+0x284>
 *   @0x20c408 lsl r2, r6, #4
 *   @0x20c40c str r2, [sp, #0x28]
 *   @0x20c410 ldr r2, [sp, #0x2c]
 *   @0x20c414 mov r12, r4
 *   @0x20c418 mov r11, r3
 *   @0x20c41c str r4, [sp, #0x18]
 *   @0x20c420 add r2, r2, #12
 *   @0x20c424 str r6, [sp, #0x14]
 *   @0x20c428 str r2, [sp, #0x1c]
 *   @0x20c42c cmp r8, #0
 *   @0x20c430 ble 0x20c610 <_ZN8CDS_Grid6ResizeEii+0x254>
 *   @0x20c434 ldr r2, [sp, #0x24]
 *   @0x20c438 mov r4, #0
 *   @0x20c43c ldr r1, [sp, #0x18]
 *   @0x20c440 cmp r2, r1
 *   @0x20c444 ldr r2, [sp, #0x1c]
 *   @0x20c448 movle r3, #0
 *   @0x20c44c movgt r3, #1
 *   @0x20c450 sub r5, r2, #12
 *   @0x20c454 mov r6, r2
 *   @0x20c458 mov r2, r8
 *   @0x20c45c mov r8, r3
 *   @0x20c460 mov r3, r2
 *   @0x20c464 b 0x20c47c <_ZN8CDS_Grid6ResizeEii+0xc0>
 *   @0x20c468 add r4, r4, #1
 *   @0x20c46c add r6, r6, #16
 *   @0x20c470 cmp r4, r3
 *   @0x20c474 add r5, r5, #16
 *   @0x20c478 beq 0x20c60c <_ZN8CDS_Grid6ResizeEii+0x250>
 *   @0x20c47c ldr r1, [sp, #0x14]
 *   @0x20c480 cmp r4, r1
 *   @0x20c484 movge r2, #0
 *   @0x20c488 andlt r2, r8, #1
 *   @0x20c48c cmp r2, #0
 *   @0x20c490 beq 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c494 ldm r11, {r9, r10}
 *   @0x20c498 ldr r2, [sp, #0x18]
 *   @0x20c49c mla r10, r10, r2, r4
 *   @0x20c4a0 add r7, r9, r10, lsl #4
 *   @0x20c4a4 ldr r2, [r7, #0xc]
 *   @0x20c4a8 sub r2, r2, #1
 *   @0x20c4ac bic r2, r2, #-16777216
 *   @0x20c4b0 bic r2, r2, #3
 *   @0x20c4b4 cmp r2, #0
 *   @0x20c4b8 beq 0x20c774 <_ZN8CDS_Grid6ResizeEii+0x3b8>
 *   @0x20c4bc str r12, [r7, #0x8]
 *   @0x20c4c0 mov r1, #5
 *   @0x20c4c4 ldr r2, [sp, #0x18]
 *   @0x20c4c8 str r1, [r7, #0xc]
 *   @0x20c4cc str r12, [r9, r10, lsl #4]
 *   @0x20c4d0 ldm r11, {r9, r10}
 *   @0x20c4d4 mla r10, r10, r2, r4
 *   @0x20c4d8 add r7, r9, r10, lsl #4
 *   @0x20c4dc ldr r1, [r7, #0xc]
 *   @0x20c4e0 bic r2, r1, #-16777216
 *   @0x20c4e4 cmp r2, #1
 *   @0x20c4e8 beq 0x20c71c <_ZN8CDS_Grid6ResizeEii+0x360>
 *   @0x20c4ec cmp r2, #2
 *   @0x20c4f0 bne 0x20c514 <_ZN8CDS_Grid6ResizeEii+0x158>
 *   @0x20c4f4 sub r1, r1, #1
 *   @0x20c4f8 bic r1, r1, #-16777216
 *   @0x20c4fc bic r1, r1, #3
 *   @0x20c500 cmp r1, #0
 *   @0x20c504 beq 0x20c860 <_ZN8CDS_Grid6ResizeEii+0x4a4>
 *   @0x20c508 mov r1, #5
 *   @0x20c50c str r12, [r7, #0x8]
 *   @0x20c510 str r1, [r7, #0xc]
 *   @0x20c514 str r12, [r9, r10, lsl #4]
 *   @0x20c518 ldr r2, [r5, #0xc]
 *   @0x20c51c str r2, [r7, #0xc]
 *   @0x20c520 ldr r2, [r5, #0x8]
 *   @0x20c524 str r2, [r7, #0x8]
 *   @0x20c528 ldr r2, [r5, #0xc]
 *   @0x20c52c bic r2, r2, #-16777216
 *   @0x20c530 cmp r2, #14
 *   @0x20c534 addls pc, pc, r2, lsl #2
 *   @0x20c538 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c53c b 0x20c584 <_ZN8CDS_Grid6ResizeEii+0x1c8>
 *   @0x20c540 b 0x20c5f4 <_ZN8CDS_Grid6ResizeEii+0x238>
 *   @0x20c544 b 0x20c5c8 <_ZN8CDS_Grid6ResizeEii+0x20c>
 *   @0x20c548 b 0x20c578 <_ZN8CDS_Grid6ResizeEii+0x1bc>
 *   @0x20c54c b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c550 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c554 b 0x20c594 <_ZN8CDS_Grid6ResizeEii+0x1d8>
 *   @0x20c558 b 0x20c578 <_ZN8CDS_Grid6ResizeEii+0x1bc>
 *   @0x20c55c b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c560 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c564 b 0x20c584 <_ZN8CDS_Grid6ResizeEii+0x1c8>
 *   @0x20c568 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c56c b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c570 b 0x20c584 <_ZN8CDS_Grid6ResizeEii+0x1c8>
 *   @0x20c574 b 0x20c578 <_ZN8CDS_Grid6ResizeEii+0x1bc>
 *   @0x20c578 ldr r2, [r6, #-0xc]
 *   @0x20c57c str r2, [r9, r10, lsl #4]
 *   @0x20c580 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c584 ldm r5, {r1, r2}
 *   @0x20c588 str r1, [r9, r10, lsl #4]
 *   @0x20c58c str r2, [r7, #0x4]
 *   @0x20c590 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c594 ldr r2, [r6, #-0xc]
 *   @0x20c598 str r2, [r9, r10, lsl #4]
 *   @0x20c59c ldr r2, [r6, #-0xc]
 *   @0x20c5a0 cmp r2, #0
 *   @0x20c5a4 beq 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c5a8 str r3, [sp, #0x8]
 *   @0x20c5ac str r12, [sp, #0x4]
 *   @0x20c5b0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20c5b4 ldr r1, [r6, #-0xc]
 *   @0x20c5b8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20c5bc ldr r3, [sp, #0x8]
 *   @0x20c5c0 ldr r12, [sp, #0x4]
 *   @0x20c5c4 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c5c8 ldr r2, [r6, #-0xc]
 *   @0x20c5cc cmp r2, #0
 *   @0x20c5d0 str r2, [r9, r10, lsl #4]
 *   @0x20c5d4 beq 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c5d8 ldr r0, [r2, #0x8]
 *   @0x20c5dc ldr r1, [r2]
 *   @0x20c5e0 cmp r0, #0
 *   @0x20c5e4 streq r7, [r2, #0x8]
 *   @0x20c5e8 add r1, r1, #1
 *   @0x20c5ec str r1, [r2]
 *   @0x20c5f0 b 0x20c468 <_ZN8CDS_Grid6ResizeEii+0xac>
 *   @0x20c5f4 ldr r2, [r6, #-0xc]
 *   @0x20c5f8 cmp r2, #0
 *   @0x20c5fc ldrne r1, [r2, #0x4]
 *   @0x20c600 addne r1, r1, #1
 *   @0x20c604 strne r1, [r2, #0x4]
 *   @0x20c608 b 0x20c57c <_ZN8CDS_Grid6ResizeEii+0x1c0>
 *   @0x20c60c mov r8, r3
 *   @0x20c610 ldr r2, [sp, #0x18]
 *   @0x20c614 ldr r3, [sp, #0x1c]
 *   @0x20c618 add r2, r2, #1
 *   @0x20c61c str r2, [sp, #0x18]
 *   @0x20c620 ldr r2, [sp, #0x28]
 *   @0x20c624 ldr r1, [sp, #0x20]
 *   @0x20c628 add r3, r3, r2
 *   @0x20c62c str r3, [sp, #0x1c]
 *   @0x20c630 ldr r3, [sp, #0x18]
 *   @0x20c634 cmp r3, r1
 *   @0x20c638 bne 0x20c42c <_ZN8CDS_Grid6ResizeEii+0x70>
 *   @0x20c63c ldr r6, [sp, #0x14]
 *   @0x20c640 ldr r3, [sp, #0x24]
 *   @0x20c644 cmp r3, #0
 *   @0x20c648 ble 0x20c70c <_ZN8CDS_Grid6ResizeEii+0x350>
 *   @0x20c64c mov r10, #0
 *   @0x20c650 ldr r3, [sp, #0x2c]
 *   @0x20c654 mov r11, r10
 *   @0x20c658 mov r1, r10
 *   @0x20c65c ldr r10, [sp, #0x24]
 *   @0x20c660 mov r2, r8
 *   @0x20c664 mov r9, #5
 *   @0x20c668 mov r8, r3
 *   @0x20c66c lsl r12, r6, #4
 *   @0x20c670 str r12, [sp, #0x14]
 *   @0x20c674 cmp r6, #0
 *   @0x20c678 ble 0x20c6f8 <_ZN8CDS_Grid6ResizeEii+0x33c>
 *   @0x20c67c ldr r12, [sp, #0x20]
 *   @0x20c680 mov r5, r8
 *   @0x20c684 mov r4, #0
 *   @0x20c688 cmp r12, r1
 *   @0x20c68c mov r12, r8
 *   @0x20c690 mov r8, r2
 *   @0x20c694 movle r7, #0
 *   @0x20c698 movgt r7, #1
 *   @0x20c69c cmp r4, r8
 *   @0x20c6a0 movge r3, #0
 *   @0x20c6a4 andlt r3, r7, #1
 *   @0x20c6a8 cmp r3, #0
 *   @0x20c6ac beq 0x20c6e0 <_ZN8CDS_Grid6ResizeEii+0x324>
 *   @0x20c6b0 cmp r4, r10
 *   @0x20c6b4 cmplt r1, r6
 *   @0x20c6b8 bge 0x20c6e0 <_ZN8CDS_Grid6ResizeEii+0x324>
 *   @0x20c6bc ldr r3, [r5, #0xc]
 *   @0x20c6c0 sub r3, r3, #1
 *   @0x20c6c4 bic r3, r3, #-16777216
 *   @0x20c6c8 bic r3, r3, #3
 *   @0x20c6cc cmp r3, #0
 *   @0x20c6d0 beq 0x20c790 <_ZN8CDS_Grid6ResizeEii+0x3d4>
 *   @0x20c6d4 str r11, [r5, #0x8]
 *   @0x20c6d8 str r9, [r5, #0xc]
 *   @0x20c6dc str r11, [r5]
 *   @0x20c6e0 add r4, r4, #1
 *   @0x20c6e4 add r5, r5, #16
 *   @0x20c6e8 cmp r4, r6
 *   @0x20c6ec bne 0x20c69c <_ZN8CDS_Grid6ResizeEii+0x2e0>
 *   @0x20c6f0 mov r2, r8
 *   @0x20c6f4 mov r8, r12
 *   @0x20c6f8 add r1, r1, #1
 *   @0x20c6fc ldr r3, [sp, #0x14]
 *   @0x20c700 cmp r1, r10
 *   @0x20c704 add r8, r8, r3
 *   @0x20c708 bne 0x20c674 <_ZN8CDS_Grid6ResizeEii+0x2b8>
 *   @0x20c70c ldr r0, [sp, #0x2c]
 *   @0x20c710 add sp, sp, #52
 *   @0x20c714 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20c718 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x20c71c ldr r2, [r9, r10, lsl #4]
 *   @0x20c720 cmp r2, #0
 *   @0x20c724 beq 0x20c76c <_ZN8CDS_Grid6ResizeEii+0x3b0>
 *   @0x20c728 str r2, [sp, #0xc]
 *   @0x20c72c str r3, [sp, #0x8]
 *   @0x20c730 str r12, [sp, #0x4]
 *   @0x20c734 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20c738 ldr r2, [sp, #0xc]
 *   @0x20c73c ldr r3, [sp, #0x8]
 *   @0x20c740 ldr r12, [sp, #0x4]
 *   @0x20c744 ldr r1, [r2, #0x4]
 *   @0x20c748 sub r1, r1, #1
 *   @0x20c74c str r1, [r2, #0x4]
 *   @0x20c750 cmp r1, #0
 *   @0x20c754 beq 0x20c7ac <_ZN8CDS_Grid6ResizeEii+0x3f0>
 *   @0x20c758 str r3, [sp, #0x8]
 *   @0x20c75c str r12, [sp, #0x4]
 *   @0x20c760 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20c764 ldr r12, [sp, #0x4]
 *   @0x20c768 ldr r3, [sp, #0x8]
 *   @0x20c76c str r12, [r9, r10, lsl #4]
 *   @0x20c770 b 0x20c514 <_ZN8CDS_Grid6ResizeEii+0x158>
 *   @0x20c774 mov r0, r7
 *   @0x20c778 str r3, [sp, #0x8]
 *   @0x20c77c str r12, [sp, #0x4]
 *   @0x20c780 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20c784 ldr r12, [sp, #0x4]
 *   @0x20c788 ldr r3, [sp, #0x8]
 *   @0x20c78c b 0x20c4bc <_ZN8CDS_Grid6ResizeEii+0x100>
 *   @0x20c790 mov r0, r5
 *   @0x20c794 str r1, [sp, #0x10]
 *   @0x20c798 str r12, [sp, #0x4]
 *   @0x20c79c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20c7a0 ldr r12, [sp, #0x4]
 *   @0x20c7a4 ldr r1, [sp, #0x10]
 *   @0x20c7a8 b 0x20c6d4 <_ZN8CDS_Grid6ResizeEii+0x318>
 *   @0x20c7ac ldr r0, [r2]
 *   @0x20c7b0 str r1, [sp, #0x10]
 *   @0x20c7b4 str r2, [sp, #0xc]
 *   @0x20c7b8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20c7bc ldr r2, [sp, #0xc]
 *   @0x20c7c0 ldr r1, [sp, #0x10]
 *   @0x20c7c4 str r1, [r2]
 *   @0x20c7c8 str r1, [r2, #0x8]
 *   @0x20c7cc str r2, [sp, #0xc]
 *   @0x20c7d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20c7d4 ldr r2, [sp, #0xc]
 *   @0x20c7d8 ldr r3, [sp, #0x8]
 *   @0x20c7dc ldr r12, [sp, #0x4]
 *   @0x20c7e0 ldr r1, [r2, #0x4]
 *   @0x20c7e4 sub r1, r1, #1
 *   @0x20c7e8 str r1, [r2, #0x4]
 *   @0x20c7ec cmp r1, #0
 *   @0x20c7f0 bne 0x20c838 <_ZN8CDS_Grid6ResizeEii+0x47c>
 *   @0x20c7f4 ldr r0, [r2]
 *   @0x20c7f8 str r1, [sp, #0x10]
 *   @0x20c7fc str r2, [sp, #0xc]
 *   @0x20c800 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20c804 ldr r2, [sp, #0xc]
 *   @0x20c808 ldr r1, [sp, #0x10]
 *   @0x20c80c mov r0, r2
 *   @0x20c810 str r1, [r2]
 *   @0x20c814 str r1, [r2, #0x8]
 *   @0x20c818 str r2, [sp, #0xc]
 *   @0x20c81c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20c820 ldr r2, [sp, #0xc]
 *   @0x20c824 mov r0, r2
 *   @0x20c828 bl 0x27d1d0 <_ZdlPv>
 *   @0x20c82c ldr r12, [sp, #0x4]
 *   @0x20c830 ldr r3, [sp, #0x8]
 *   @0x20c834 ldr r2, [sp, #0xc]
 *   @0x20c838 str r3, [sp, #0x8]
 *   @0x20c83c str r12, [sp, #0x4]
 *   @0x20c840 str r2, [sp, #0xc]
 *   @0x20c844 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20c848 ldr r2, [sp, #0xc]
 *   @0x20c84c mov r0, r2
 *   @0x20c850 bl 0x27d1d0 <_ZdlPv>
 *   @0x20c854 ldr r12, [sp, #0x4]
 *   @0x20c858 ldr r3, [sp, #0x8]
 *   @0x20c85c b 0x20c758 <_ZN8CDS_Grid6ResizeEii+0x39c>
 *   @0x20c860 mov r0, r7
 *   @0x20c864 str r3, [sp, #0x8]
 *   @0x20c868 str r12, [sp, #0x4]
 *   @0x20c86c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20c870 ldr r12, [sp, #0x4]
 *   @0x20c874 ldr r3, [sp, #0x8]
 *   @0x20c878 b 0x20c508 <_ZN8CDS_Grid6ResizeEii+0x14c>
 *
 * ══ §4/29 Platform_Setup(IniFile*)  0x1de984  size 1208  302 条（0x1de984..0x1dee3c）
 * @func 0x1de984 0x1dee3c  size 1208  302 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::GetKey(char const*, char const*)×8 / 0xb6574×8 / 0xb66b8×8 / Platform_SetupM(IniFile*) / Facebook_Setup(IniFile*) / Purchases_Setup(IniFile*) / Misc_Setup(IniFile*) / 0xb6538
 * 字段偏移 top8: 0x8×9 / 0x158×2 / 0x414×1 / 0x3fc×1 / 0x3ec×1 / 0x3d8×1 / 0x3c4×1 / 0x3c0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1de984 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1de988 mov r4, r0
 *   @0x1de98c bl 0x1dfb88 <_Z15Platform_SetupMP7IniFile>
 *   @0x1de990 mov r0, r4
 *   @0x1de994 ldr r5, [pc, #0x414]
 *   @0x1de998 bl 0x1de8e8 <_Z14Facebook_SetupP7IniFile>
 *   @0x1de99c mov r0, r4
 *   @0x1de9a0 bl 0x1de980 <_Z15Purchases_SetupP7IniFile>
 *   @0x1de9a4 mov r0, r4
 *   @0x1de9a8 add r5, pc, r5
 *   @0x1de9ac bl 0x1de97c <_Z10Misc_SetupP7IniFile>
 *   @0x1de9b0 ldr r2, [pc, #0x3fc]
 *   @0x1de9b4 mov r0, r4
 *   @0x1de9b8 mov r1, r5
 *   @0x1de9bc add r2, pc, r2
 *   @0x1de9c0 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x1de9c4 ldr r2, [pc, #0x3ec]
 *   @0x1de9c8 mov r1, r5
 *   @0x1de9cc add r2, pc, r2
 *   @0x1de9d0 mov r9, r0
 *   @0x1de9d4 mov r0, r4
 *   @0x1de9d8 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x1de9dc ldr r2, [pc, #0x3d8]
 *   @0x1de9e0 mov r1, r5
 *   @0x1de9e4 add r2, pc, r2
 *   @0x1de9e8 mov r8, r0
 *   @0x1de9ec mov r0, r4
 *   @0x1de9f0 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x1de9f4 ldr r2, [pc, #0x3c4]
 *   @0x1de9f8 mov r1, r5
 *   @0x1de9fc ldr r5, [pc, #0x3c0]
 *   @0x1dea00 add r2, pc, r2
 *   @0x1dea04 add r5, pc, r5
 *   @0x1dea08 mov r7, r0
 *   @0x1dea0c mov r0, r4
 *   @0x1dea10 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x1dea14 cmp r9, #0
 *   @0x1dea18 mov r6, r0
 *   @0x1dea1c beq 0x1dea70 <_Z14Platform_SetupP7IniFile+0xec>
 *   @0x1dea20 ldr r9, [r9, #0x8]
 *   @0x1dea24 ldr r1, [pc, #0x39c]
 *   @0x1dea28 mov r0, r9
 *   @0x1dea2c add r1, pc, r1
 *   @0x1dea30 bl 0xb6574 <strcmp@plt>
 *   @0x1dea34 cmp r0, #0
 *   @0x1dea38 beq 0x1ded1c <_Z14Platform_SetupP7IniFile+0x398>
 *   @0x1dea3c ldr r1, [pc, #0x388]
 *   @0x1dea40 mov r0, r9
 *   @0x1dea44 add r1, pc, r1
 *   @0x1dea48 bl 0xb6574 <strcmp@plt>
 *   @0x1dea4c cmp r0, #0
 *   @0x1dea50 beq 0x1ded90 <_Z14Platform_SetupP7IniFile+0x40c>
 *   @0x1dea54 mov r0, r9
 *   @0x1dea58 bl 0xb66b8 <atoi@plt>
 *   @0x1dea5c ldr r3, [pc, #0x36c]
 *   @0x1dea60 ldr r3, [r5, r3]
 *   @0x1dea64 adds r0, r0, #0
 *   @0x1dea68 movne r0, #1
 *   @0x1dea6c str r0, [r3]
 *   @0x1dea70 cmp r8, #0
 *   @0x1dea74 beq 0x1deac8 <_Z14Platform_SetupP7IniFile+0x144>
 *   @0x1dea78 ldr r8, [r8, #0x8]
 *   @0x1dea7c ldr r1, [pc, #0x350]
 *   @0x1dea80 mov r0, r8
 *   @0x1dea84 add r1, pc, r1
 *   @0x1dea88 bl 0xb6574 <strcmp@plt>
 *   @0x1dea8c cmp r0, #0
 *   @0x1dea90 beq 0x1ded30 <_Z14Platform_SetupP7IniFile+0x3ac>
 *   @0x1dea94 ldr r1, [pc, #0x33c]
 *   @0x1dea98 mov r0, r8
 *   @0x1dea9c add r1, pc, r1
 *   @0x1deaa0 bl 0xb6574 <strcmp@plt>
 *   @0x1deaa4 cmp r0, #0
 *   @0x1deaa8 beq 0x1deda0 <_Z14Platform_SetupP7IniFile+0x41c>
 *   @0x1deaac mov r0, r8
 *   @0x1deab0 bl 0xb66b8 <atoi@plt>
 *   @0x1deab4 ldr r3, [pc, #0x320]
 *   @0x1deab8 ldr r3, [r5, r3]
 *   @0x1deabc adds r0, r0, #0
 *   @0x1deac0 movne r0, #1
 *   @0x1deac4 str r0, [r3]
 *   @0x1deac8 cmp r7, #0
 *   @0x1deacc beq 0x1deb20 <_Z14Platform_SetupP7IniFile+0x19c>
 *   @0x1dead0 ldr r7, [r7, #0x8]
 *   @0x1dead4 ldr r1, [pc, #0x304]
 *   @0x1dead8 mov r0, r7
 *   @0x1deadc add r1, pc, r1
 *   @0x1deae0 bl 0xb6574 <strcmp@plt>
 *   @0x1deae4 cmp r0, #0
 *   @0x1deae8 beq 0x1ded08 <_Z14Platform_SetupP7IniFile+0x384>
 *   @0x1deaec ldr r1, [pc, #0x2f0]
 *   @0x1deaf0 mov r0, r7
 *   @0x1deaf4 add r1, pc, r1
 *   @0x1deaf8 bl 0xb6574 <strcmp@plt>
 *   @0x1deafc cmp r0, #0
 *   @0x1deb00 beq 0x1ded80 <_Z14Platform_SetupP7IniFile+0x3fc>
 *   @0x1deb04 mov r0, r7
 *   @0x1deb08 bl 0xb66b8 <atoi@plt>
 *   @0x1deb0c ldr r3, [pc, #0x2d4]
 *   @0x1deb10 ldr r3, [r5, r3]
 *   @0x1deb14 adds r0, r0, #0
 *   @0x1deb18 movne r0, #1
 *   @0x1deb1c str r0, [r3]
 *   @0x1deb20 cmp r6, #0
 *   @0x1deb24 beq 0x1deb78 <_Z14Platform_SetupP7IniFile+0x1f4>
 *   @0x1deb28 ldr r6, [r6, #0x8]
 *   @0x1deb2c ldr r1, [pc, #0x2b8]
 *   @0x1deb30 mov r0, r6
 *   @0x1deb34 add r1, pc, r1
 *   @0x1deb38 bl 0xb6574 <strcmp@plt>
 *   @0x1deb3c cmp r0, #0
 *   @0x1deb40 beq 0x1decf4 <_Z14Platform_SetupP7IniFile+0x370>
 *   @0x1deb44 ldr r1, [pc, #0x2a4]
 *   @0x1deb48 mov r0, r6
 *   @0x1deb4c add r1, pc, r1
 *   @0x1deb50 bl 0xb6574 <strcmp@plt>
 *   @0x1deb54 cmp r0, #0
 *   @0x1deb58 beq 0x1ded70 <_Z14Platform_SetupP7IniFile+0x3ec>
 *   @0x1deb5c mov r0, r6
 *   @0x1deb60 bl 0xb66b8 <atoi@plt>
 *   @0x1deb64 ldr r3, [pc, #0x288]
 *   @0x1deb68 ldr r3, [r5, r3]
 *   @0x1deb6c adds r0, r0, #0
 *   @0x1deb70 movne r0, #1
 *   @0x1deb74 str r0, [r3]
 *   @0x1deb78 ldr r1, [pc, #0x278]
 *   @0x1deb7c mov r0, r4
 *   @0x1deb80 ldr r2, [pc, #0x274]
 *   @0x1deb84 add r1, pc, r1
 *   @0x1deb88 add r2, pc, r2
 *   @0x1deb8c bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x1deb90 cmp r0, #0
 *   @0x1deb94 beq 0x1debbc <_Z14Platform_SetupP7IniFile+0x238>
 *   @0x1deb98 ldr r0, [r0, #0x8]
 *   @0x1deb9c bl 0xb66b8 <atoi@plt>
 *   @0x1deba0 ldr r3, [pc, #0x258]
 *   @0x1deba4 ldr r3, [r5, r3]
 *   @0x1deba8 adds r0, r0, #0
 *   @0x1debac movne r0, #1
 *   @0x1debb0 cmp r0, #0
 *   @0x1debb4 strb r0, [r3]
 *   @0x1debb8 bne 0x1ded44 <_Z14Platform_SetupP7IniFile+0x3c0>
 *   @0x1debbc ldr r1, [pc, #0x240]
 *   @0x1debc0 mov r0, r4
 *   @0x1debc4 ldr r2, [pc, #0x23c]
 *   @0x1debc8 add r1, pc, r1
 *   @0x1debcc add r2, pc, r2
 *   @0x1debd0 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x1debd4 cmp r0, #0
 *   @0x1debd8 beq 0x1debf8 <_Z14Platform_SetupP7IniFile+0x274>
 *   @0x1debdc ldr r0, [r0, #0x8]
 *   @0x1debe0 bl 0xb66b8 <atoi@plt>
 *   @0x1debe4 ldr r3, [pc, #0x220]
 *   @0x1debe8 ldr r3, [r5, r3]
 *   @0x1debec adds r0, r0, #0
 *   @0x1debf0 movne r0, #1
 *   @0x1debf4 strb r0, [r3]
 *   @0x1debf8 ldr r1, [pc, #0x210]
 *   @0x1debfc mov r0, r4
 *   @0x1dec00 ldr r2, [pc, #0x20c]
 *   @0x1dec04 add r1, pc, r1
 *   @0x1dec08 add r2, pc, r2
 *   @0x1dec0c bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x1dec10 cmp r0, #0
 *   @0x1dec14 beq 0x1dec34 <_Z14Platform_SetupP7IniFile+0x2b0>
 *   @0x1dec18 ldr r0, [r0, #0x8]
 *   @0x1dec1c bl 0xb66b8 <atoi@plt>
 *   @0x1dec20 ldr r3, [pc, #0x1f0]
 *   @0x1dec24 ldr r3, [r5, r3]
 *   @0x1dec28 adds r0, r0, #0
 *   @0x1dec2c movne r0, #1
 *   @0x1dec30 strb r0, [r3]
 *   @0x1dec34 ldr r1, [pc, #0x1e0]
 *   @0x1dec38 mov r0, r4
 *   @0x1dec3c ldr r2, [pc, #0x1dc]
 *   @0x1dec40 add r1, pc, r1
 *   @0x1dec44 add r2, pc, r2
 *   @0x1dec48 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_>
 *   @0x1dec4c subs r4, r0, #0
 *   @0x1dec50 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1dec54 ldr r0, [r4, #0x8]
 *   @0x1dec58 bl 0xb6538 <strlen@plt>
 *   @0x1dec5c ldr r1, [pc, #0x1c0]
 *   @0x1dec60 movw r2, #0x7ee
 *   @0x1dec64 mov r3, #1
 *   @0x1dec68 add r1, pc, r1
 *   @0x1dec6c add r0, r0, r3
 *   @0x1dec70 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1dec74 ldr r3, [pc, #0x1ac]
 *   @0x1dec78 ldr r1, [r4, #0x8]
 *   @0x1dec7c ldr r4, [r5, r3]
 *   @0x1dec80 str r0, [r4]
 *   @0x1dec84 bl 0xb65a4 <strcpy@plt>
 *   @0x1dec88 ldr r6, [r4]
 *   @0x1dec8c mov r1, #58
 *   @0x1dec90 mov r0, r6
 *   @0x1dec94 bl 0xb6868 <strrchr@plt>
 *   @0x1dec98 cmp r0, #0
 *   @0x1dec9c beq 0x1ded5c <_Z14Platform_SetupP7IniFile+0x3d8>
 *   @0x1deca0 mov r3, #0
 *   @0x1deca4 strb r3, [r0], #1
 *   @0x1deca8 bl 0xb66b8 <atoi@plt>
 *   @0x1decac ldr lr, [pc, #0x178]
 *   @0x1decb0 ldr r1, [pc, #0x160]
 *   @0x1decb4 mov r12, #1
 *   @0x1decb8 ldr r2, [r4]
 *   @0x1decbc ldr lr, [r5, lr]
 *   @0x1decc0 str r0, [lr]
 *   @0x1decc4 mov r3, r0
 *   @0x1decc8 ldr r1, [r5, r1]
 *   @0x1deccc strb r12, [r1]
 *   @0x1decd0 ldr r0, [pc, #0x158]
 *   @0x1decd4 ldr r1, [pc, #0x158]
 *   @0x1decd8 ldr r0, [r5, r0]
 *   @0x1decdc add r1, pc, r1
 *   @0x1dece0 ldr r0, [r0]
 *   @0x1dece4 ldr r12, [r0]
 *   @0x1dece8 ldr r12, [r12, #0xc]
 *   @0x1decec blx r12
 *   @0x1decf0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1decf4 ldr r3, [pc, #0xf8]
 *   @0x1decf8 mov r2, #1
 *   @0x1decfc ldr r3, [r5, r3]
 *   @0x1ded00 str r2, [r3]
 *   @0x1ded04 b 0x1deb78 <_Z14Platform_SetupP7IniFile+0x1f4>
 *   @0x1ded08 ldr r3, [pc, #0xd8]
 *   @0x1ded0c mov r2, #1
 *   @0x1ded10 ldr r3, [r5, r3]
 *   @0x1ded14 str r2, [r3]
 *   @0x1ded18 b 0x1deb20 <_Z14Platform_SetupP7IniFile+0x19c>
 *   @0x1ded1c ldr r3, [pc, #0xac]
 *   @0x1ded20 mov r2, #1
 *   @0x1ded24 ldr r3, [r5, r3]
 *   @0x1ded28 str r2, [r3]
 *   @0x1ded2c b 0x1dea70 <_Z14Platform_SetupP7IniFile+0xec>
 *   @0x1ded30 ldr r3, [pc, #0xa4]
 *   @0x1ded34 mov r2, #1
 *   @0x1ded38 ldr r3, [r5, r3]
 *   @0x1ded3c str r2, [r3]
 *   @0x1ded40 b 0x1deac8 <_Z14Platform_SetupP7IniFile+0x144>
 *   @0x1ded44 ldr r3, [pc, #0xec]
 *   @0x1ded48 mov r2, #2
 *   @0x1ded4c ldr r3, [r5, r3]
 *   @0x1ded50 str r2, [r3]
 *   @0x1ded54 bl 0x237b88 <_ZN13CPhysicsWorld12SetDebugModeEv>
 *   @0x1ded58 b 0x1debbc <_Z14Platform_SetupP7IniFile+0x238>
 *   @0x1ded5c ldr r3, [pc, #0xc8]
 *   @0x1ded60 mov r2, r6
 *   @0x1ded64 ldr r3, [r5, r3]
 *   @0x1ded68 ldr r3, [r3]
 *   @0x1ded6c b 0x1decd0 <_Z14Platform_SetupP7IniFile+0x34c>
 *   @0x1ded70 ldr r3, [pc, #0x7c]
 *   @0x1ded74 ldr r3, [r5, r3]
 *   @0x1ded78 str r0, [r3]
 *   @0x1ded7c b 0x1deb78 <_Z14Platform_SetupP7IniFile+0x1f4>
 *   @0x1ded80 ldr r3, [pc, #0x60]
 *   @0x1ded84 ldr r3, [r5, r3]
 *   @0x1ded88 str r0, [r3]
 *   @0x1ded8c b 0x1deb20 <_Z14Platform_SetupP7IniFile+0x19c>
 *   @0x1ded90 ldr r3, [pc, #0x38]
 *   @0x1ded94 ldr r3, [r5, r3]
 *   @0x1ded98 str r0, [r3]
 *   @0x1ded9c b 0x1dea70 <_Z14Platform_SetupP7IniFile+0xec>
 *   @0x1deda0 ldr r3, [pc, #0x34]
 *   @0x1deda4 ldr r3, [r5, r3]
 *   @0x1deda8 str r0, [r3]
 *   @0x1dedac b 0x1deac8 <_Z14Platform_SetupP7IniFile+0x144>
 *   @0x1dedb0 andseq r2, r7, r12, asr #28
 *   @0x1dedb4 andseq r2, r7, r0, lsr #29
 *   @0x1dedb8 andseq r2, r7, r0, lsr #29
 *   @0x1dedbc andseq r2, r7, r0, lsr #29
 *   @0x1dedc0 mulseq r7, r4, lr
 *   @0x1dedc4 eoreq r3, r1, r12, asr #4
 *   @0x1dedc8 andseq r2, r7, r0, lsl #29
 *   @0x1dedcc andseq r2, r7, r0, ror lr
 *   @0x1dedd0 .word 0xffffdf64
 *   @0x1dedd4 andseq r2, r7, r8, lsr #28
 *   @0x1dedd8 andseq r2, r7, r8, lsl lr
 *   @0x1deddc .word 0xffffdf6c
 *   @0x1dede0 ldrsbeq r2, [r7], -r0
 *   @0x1dede4 andseq r2, r7, r0, asr #27
 *   @0x1dede8 .word 0xffffdf68
 *   @0x1dedec andseq r2, r7, r8, ror sp
 *   @0x1dedf0 andseq r2, r7, r8, ror #26
 *   @0x1dedf4 .word 0xffffdf70
 *   @0x1dedf8 andseq r2, r7, r0, ror r12
 *   @0x1dedfc andseq r2, r7, r4, lsr sp
 *   @0x1dee00 .word 0xffffef34
 *   @0x1dee04 andseq r2, r7, r12, lsr #24
 *   @0x1dee08 ldrsheq r2, [r7], -r8
 *   @0x1dee0c .word 0xffffc100
 *   @0x1dee10 ldrsheq r2, [r7], -r0
 *   @0x1dee14 andseq r2, r7, r4, asr #25
 *   @0x1dee18 .word 0xfffff0a0
 *   @0x1dee1c ldrheq r2, [r7], -r4
 *   @0x1dee20 mulseq r7, r4, r12
 *   @0x1dee24 ldrheq r2, [r7], -r12
 *   @0x1dee28 .word 0xfffff0a4
 *   @0x1dee2c .word 0xfffff0a8
 *   @0x1dee30 .word 0xffffbac4
 *   @0x1dee34 andseq r2, r7, r4, lsl #24
 *   @0x1dee38 .word 0xffffc7dc
 *
 * ══ §5/29 F_DsGridSetPost(RValue&, CInstance*, CInstance*, int, RValue*)  0x1038dc  size 1204  301 条（0x1038dc..0x103d90）
 * @func 0x1038dc 0x103d90  size 1204  301 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int)×3 / GetContextStackTop()×2 / _RefThing<char const*>::dec()×2 / FREE_RValue__Pre(RValue*)×2
 * 字段偏移 top8: 0x4×28 / 0x8×13 / 0xc×9 / 0x30×8 / 0x3c×2 / 0x450×1 / 0x440×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1038dc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1038e0 sub sp, sp, #16
 *   @0x1038e4 mov r1, #0
 *   @0x1038e8 mov r7, r0
 *   @0x1038ec ldr r4, [sp, #0x30]
 *   @0x1038f0 mov r0, r4
 *   @0x1038f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1038f8 mov r1, #1
 *   @0x1038fc mov r5, r0
 *   @0x103900 mov r0, r4
 *   @0x103904 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x103908 mov r1, #2
 *   @0x10390c mov r6, r0
 *   @0x103910 mov r0, r4
 *   @0x103914 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x103918 cmp r5, #0
 *   @0x10391c mov r12, r0
 *   @0x103920 blt 0x103a28 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x103924 ldr r2, [pc, #0x450]
 *   @0x103928 ldr r2, [pc, r2]
 *   @0x10392c ldr r3, [r2]
 *   @0x103930 cmp r5, r3
 *   @0x103934 bge 0x103a28 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x103938 ldr r3, [pc, #0x440]
 *   @0x10393c ldr r3, [pc, r3]
 *   @0x103940 ldr r3, [r3, #0x4]
 *   @0x103944 ldr r3, [r3, r5, lsl #2]
 *   @0x103948 cmp r3, #0
 *   @0x10394c beq 0x103a28 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x103950 cmp r6, #0
 *   @0x103954 ldr r8, [r3, #0x4]
 *   @0x103958 blt 0x103a40 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x10395c cmp r6, r8
 *   @0x103960 bge 0x103a40 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x103964 cmp r0, #0
 *   @0x103968 ldr r9, [r3, #0x8]
 *   @0x10396c blt 0x103a44 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x103970 cmp r0, r9
 *   @0x103974 bge 0x103a44 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x103978 mla r6, r8, r0, r6
 *   @0x10397c ldr r2, [r7, #0xc]
 *   @0x103980 ldr r9, [r3]
 *   @0x103984 bic r3, r2, #-16777216
 *   @0x103988 cmp r3, #1
 *   @0x10398c add r5, r9, r6, lsl #4
 *   @0x103990 beq 0x103c7c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x3a0>
 *   @0x103994 cmp r3, #2
 *   @0x103998 bne 0x1039c0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x10399c sub r3, r2, #1
 *   @0x1039a0 bic r3, r3, #-16777216
 *   @0x1039a4 bic r3, r3, #3
 *   @0x1039a8 cmp r3, #0
 *   @0x1039ac beq 0x103d64 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x488>
 *   @0x1039b0 mov r2, #0
 *   @0x1039b4 mov r3, #5
 *   @0x1039b8 str r2, [r7, #0x8]
 *   @0x1039bc str r3, [r7, #0xc]
 *   @0x1039c0 ldr r2, [r5, #0xc]
 *   @0x1039c4 mov r1, #0
 *   @0x1039c8 ldr r3, [r5, #0x8]
 *   @0x1039cc str r1, [r7]
 *   @0x1039d0 str r2, [r7, #0xc]
 *   @0x1039d4 ldr r2, [r5, #0xc]
 *   @0x1039d8 str r3, [r7, #0x8]
 *   @0x1039dc bic r3, r2, #-16777216
 *   @0x1039e0 cmp r3, #14
 *   @0x1039e4 addls pc, pc, r3, lsl #2
 *   @0x1039e8 b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x1039ec b 0x103c6c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x390>
 *   @0x1039f0 b 0x103c48 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x36c>
 *   @0x1039f4 b 0x103c1c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x340>
 *   @0x1039f8 b 0x103ae0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x1039fc b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x103a00 b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x103a04 b 0x103a7c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x103a08 b 0x103ae0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x103a0c b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x103a10 b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x103a14 b 0x103ba0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x2c4>
 *   @0x103a18 b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x103a1c b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x103a20 b 0x103c6c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x390>
 *   @0x103a24 b 0x103ae0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x103a28 ldr r0, [pc, #0x354]
 *   @0x103a2c mov r1, #0
 *   @0x103a30 add r0, pc, r0
 *   @0x103a34 add sp, sp, #16
 *   @0x103a38 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x103a3c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x103a40 ldr r9, [r3, #0x8]
 *   @0x103a44 ldr r0, [pc, #0x33c]
 *   @0x103a48 mov r2, r5
 *   @0x103a4c ldr r1, [pc, #0x338]
 *   @0x103a50 mov r3, r6
 *   @0x103a54 ldr r0, [pc, r0]
 *   @0x103a58 add r1, pc, r1
 *   @0x103a5c ldr r0, [r0]
 *   @0x103a60 ldr lr, [r0]
 *   @0x103a64 str r12, [sp]
 *   @0x103a68 stmib sp, {r8, r9}
 *   @0x103a6c ldr r12, [lr, #0xc]
 *   @0x103a70 blx r12
 *   @0x103a74 add sp, sp, #16
 *   @0x103a78 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x103a7c ldr r3, [r9, r6, lsl #4]
 *   @0x103a80 str r3, [r7]
 *   @0x103a84 ldr r3, [r9, r6, lsl #4]
 *   @0x103a88 cmp r3, #0
 *   @0x103a8c beq 0x103ae8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x103a90 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x103a94 ldr r1, [r9, r6, lsl #4]
 *   @0x103a98 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x103a9c ldr r2, [r5, #0xc]
 *   @0x103aa0 bic r3, r2, #-16777216
 *   @0x103aa4 cmp r3, #1
 *   @0x103aa8 bne 0x103b70 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x294>
 *   @0x103aac ldr r7, [r9, r6, lsl #4]
 *   @0x103ab0 cmp r7, #0
 *   @0x103ab4 beq 0x103ad4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x103ab8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x103abc ldr r8, [r7, #0x4]
 *   @0x103ac0 sub r8, r8, #1
 *   @0x103ac4 str r8, [r7, #0x4]
 *   @0x103ac8 cmp r8, #0
 *   @0x103acc beq 0x103cb0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x3d4>
 *   @0x103ad0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x103ad4 mov r3, #0
 *   @0x103ad8 str r3, [r9, r6, lsl #4]
 *   @0x103adc b 0x103ae8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x103ae0 ldr r3, [r9, r6, lsl #4]
 *   @0x103ae4 str r3, [r7]
 *   @0x103ae8 ldr r3, [r4, #0x3c]
 *   @0x103aec mov r1, #0
 *   @0x103af0 ldr r2, [r4, #0x38]
 *   @0x103af4 str r1, [r9, r6, lsl #4]
 *   @0x103af8 str r3, [r5, #0xc]
 *   @0x103afc ldr r3, [r4, #0x3c]
 *   @0x103b00 str r2, [r5, #0x8]
 *   @0x103b04 bic r3, r3, #-16777216
 *   @0x103b08 cmp r3, #14
 *   @0x103b0c addls pc, pc, r3, lsl #2
 *   @0x103b10 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103b14 b 0x103b5c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x280>
 *   @0x103b18 b 0x103c04 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x328>
 *   @0x103b1c b 0x103bd8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x2fc>
 *   @0x103b20 b 0x103b50 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x103b24 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103b28 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103b2c b 0x103bb0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x2d4>
 *   @0x103b30 b 0x103b50 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x103b34 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103b38 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103b3c b 0x103b5c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x280>
 *   @0x103b40 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103b44 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103b48 b 0x103b5c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x280>
 *   @0x103b4c b 0x103b50 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x103b50 ldr r3, [r4, #0x30]
 *   @0x103b54 str r3, [r9, r6, lsl #4]
 *   @0x103b58 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103b5c ldr r2, [r4, #0x30]
 *   @0x103b60 ldr r3, [r4, #0x34]
 *   @0x103b64 str r2, [r9, r6, lsl #4]
 *   @0x103b68 str r3, [r5, #0x4]
 *   @0x103b6c b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103b70 cmp r3, #2
 *   @0x103b74 bne 0x103ae8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x103b78 sub r3, r2, #1
 *   @0x103b7c bic r3, r3, #-16777216
 *   @0x103b80 bic r3, r3, #3
 *   @0x103b84 cmp r3, #0
 *   @0x103b88 beq 0x103d70 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x494>
 *   @0x103b8c mov r2, #0
 *   @0x103b90 mov r3, #5
 *   @0x103b94 str r2, [r5, #0x8]
 *   @0x103b98 str r3, [r5, #0xc]
 *   @0x103b9c b 0x103ae8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x103ba0 ldr r2, [r9, r6, lsl #4]
 *   @0x103ba4 ldr r3, [r5, #0x4]
 *   @0x103ba8 stm r7, {r2, r3}
 *   @0x103bac b 0x103ae8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x103bb0 ldr r3, [r4, #0x30]
 *   @0x103bb4 str r3, [r9, r6, lsl #4]
 *   @0x103bb8 ldr r3, [r4, #0x30]
 *   @0x103bbc cmp r3, #0
 *   @0x103bc0 beq 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103bc4 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x103bc8 ldr r1, [r4, #0x30]
 *   @0x103bcc add sp, sp, #16
 *   @0x103bd0 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x103bd4 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x103bd8 ldr r3, [r4, #0x30]
 *   @0x103bdc cmp r3, #0
 *   @0x103be0 str r3, [r9, r6, lsl #4]
 *   @0x103be4 beq 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103be8 ldr r1, [r3, #0x8]
 *   @0x103bec ldr r2, [r3]
 *   @0x103bf0 cmp r1, #0
 *   @0x103bf4 streq r5, [r3, #0x8]
 *   @0x103bf8 add r2, r2, #1
 *   @0x103bfc str r2, [r3]
 *   @0x103c00 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103c04 ldr r3, [r4, #0x30]
 *   @0x103c08 cmp r3, #0
 *   @0x103c0c ldrne r2, [r3, #0x4]
 *   @0x103c10 addne r2, r2, #1
 *   @0x103c14 strne r2, [r3, #0x4]
 *   @0x103c18 b 0x103b54 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x278>
 *   @0x103c1c ldr r3, [r9, r6, lsl #4]
 *   @0x103c20 cmp r3, #0
 *   @0x103c24 str r3, [r7]
 *   @0x103c28 beq 0x103b78 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x103c2c ldr r0, [r3, #0x8]
 *   @0x103c30 ldr r1, [r3]
 *   @0x103c34 cmp r0, #0
 *   @0x103c38 streq r7, [r3, #0x8]
 *   @0x103c3c add r1, r1, #1
 *   @0x103c40 str r1, [r3]
 *   @0x103c44 b 0x103b78 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x103c48 ldr r1, [r9, r6, lsl #4]
 *   @0x103c4c cmp r1, #0
 *   @0x103c50 ldrne r3, [r1, #0x4]
 *   @0x103c54 addne r3, r3, #1
 *   @0x103c58 strne r3, [r1, #0x4]
 *   @0x103c5c ldrne r2, [r5, #0xc]
 *   @0x103c60 str r1, [r7]
 *   @0x103c64 bicne r3, r2, #-16777216
 *   @0x103c68 b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x103c6c ldr r0, [r9, r6, lsl #4]
 *   @0x103c70 ldr r1, [r5, #0x4]
 *   @0x103c74 stm r7, {r0, r1}
 *   @0x103c78 b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x103c7c ldr r8, [r7]
 *   @0x103c80 cmp r8, #0
 *   @0x103c84 beq 0x103ca4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x3c8>
 *   @0x103c88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x103c8c ldr r3, [r8, #0x4]
 *   @0x103c90 sub r3, r3, #1
 *   @0x103c94 str r3, [r8, #0x4]
 *   @0x103c98 cmp r3, #0
 *   @0x103c9c beq 0x103d08 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x42c>
 *   @0x103ca0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x103ca4 mov r3, #0
 *   @0x103ca8 str r3, [r7]
 *   @0x103cac b 0x1039c0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x103cb0 ldr r0, [r7]
 *   @0x103cb4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x103cb8 str r8, [r7]
 *   @0x103cbc str r8, [r7, #0x8]
 *   @0x103cc0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x103cc4 ldr r8, [r7, #0x4]
 *   @0x103cc8 sub r8, r8, #1
 *   @0x103ccc str r8, [r7, #0x4]
 *   @0x103cd0 cmp r8, #0
 *   @0x103cd4 bne 0x103cf8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x41c>
 *   @0x103cd8 ldr r0, [r7]
 *   @0x103cdc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x103ce0 mov r0, r7
 *   @0x103ce4 str r8, [r7]
 *   @0x103ce8 str r8, [r7, #0x8]
 *   @0x103cec bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x103cf0 mov r0, r7
 *   @0x103cf4 bl 0x27d1d0 <_ZdlPv>
 *   @0x103cf8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x103cfc mov r0, r7
 *   @0x103d00 bl 0x27d1d0 <_ZdlPv>
 *   @0x103d04 b 0x103ad0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x103d08 ldr r0, [r8]
 *   @0x103d0c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x103d10 mov r3, #0
 *   @0x103d14 str r3, [r8]
 *   @0x103d18 str r3, [r8, #0x8]
 *   @0x103d1c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x103d20 ldr r10, [r8, #0x4]
 *   @0x103d24 sub r10, r10, #1
 *   @0x103d28 str r10, [r8, #0x4]
 *   @0x103d2c cmp r10, #0
 *   @0x103d30 bne 0x103d54 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x478>
 *   @0x103d34 ldr r0, [r8]
 *   @0x103d38 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x103d3c mov r0, r8
 *   @0x103d40 str r10, [r8]
 *   @0x103d44 str r10, [r8, #0x8]
 *   @0x103d48 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x103d4c mov r0, r8
 *   @0x103d50 bl 0x27d1d0 <_ZdlPv>
 *   @0x103d54 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x103d58 mov r0, r8
 *   @0x103d5c bl 0x27d1d0 <_ZdlPv>
 *   @0x103d60 b 0x103ca0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x3c4>
 *   @0x103d64 mov r0, r7
 *   @0x103d68 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x103d6c b 0x1039b0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x103d70 mov r0, r5
 *   @0x103d74 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x103d78 b 0x103b8c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x2b0>
 *   @0x103d7c eoreq r10, lr, r12, asr r5
 *   @0x103d80 eoreq r10, lr, r12, asr #10
 *   @0x103d84 eoreq r4, r3, r12, asr #3
 *   @0x103d88 eoreq r9, lr, r12, ror #29
 *   @0x103d8c eoreq r4, r3, r4, lsr r12
 *
 * ══ §6/29 IBuffer::Fill(int, int, eBuffer_Type, RValue*, int, bool)  0xcc280  size 1192  298 条（0xcc280..0xcc728）
 * @func 0xcc280 0xcc728  size 1192  298 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / __aeabi_idivmod×3 / IBuffer::Fill(int, int, eBuffer_Type, RValue*, int, bool)+0x1c4×2 / YYGetString(RValue const*, int)×2 / 0xb6538×2 / 0xb65b0×2 / IBuffer::Fill(int, int, eBuffer_Type, RValue*, int, bool)+0x484 / IBuffer::Fill(int, int, eBuffer_Type, RValue*, int, bool)+0x1ac
 * 字段偏移 top8: 0x10×10 / 0x8×10 / 0x4×8 / 0x48×8 / 0xc×6 / 0x20×5 / 0x-8×4 / 0x14×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcc280 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xcc284 sub sp, sp, #36
 *   @0xcc288 mov r6, r1
 *   @0xcc28c ldr r1, [r0, #0x10]
 *   @0xcc290 str r2, [sp, #0x4]
 *   @0xcc294 mov r10, r0
 *   @0xcc298 ldrb r2, [sp, #0x50]
 *   @0xcc29c cmp r1, #0
 *   @0xcc2a0 str r2, [sp, #0xc]
 *   @0xcc2a4 beq 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4>
 *   @0xcc2a8 sub r3, r3, #1
 *   @0xcc2ac cmp r3, #12
 *   @0xcc2b0 addls pc, pc, r3, lsl #2
 *   @0xcc2b4 b 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4>
 *   @0xcc2b8 b 0xcc44c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1cc>
 *   @0xcc2bc b 0xcc44c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1cc>
 *   @0xcc2c0 b 0xcc46c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1ec>
 *   @0xcc2c4 b 0xcc46c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1ec>
 *   @0xcc2c8 b 0xcc2ec <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x6c>
 *   @0xcc2cc b 0xcc2ec <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x6c>
 *   @0xcc2d0 b 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4>
 *   @0xcc2d4 b 0xcc4d8 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x258>
 *   @0xcc2d8 b 0xcc4f8 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x278>
 *   @0xcc2dc b 0xcc48c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x20c>
 *   @0xcc2e0 b 0xcc518 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x298>
 *   @0xcc2e4 b 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4>
 *   @0xcc2e8 b 0xcc4bc <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x23c>
 *   @0xcc2ec ldr r0, [sp, #0x48]
 *   @0xcc2f0 mov r1, #0
 *   @0xcc2f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcc2f8 add r3, sp, #32
 *   @0xcc2fc mov r9, #4
 *   @0xcc300 str r0, [r3, #-0x8]!
 *   @0xcc304 str r3, [sp, #0x8]
 *   @0xcc308 ldr r2, [sp, #0x4]
 *   @0xcc30c cmp r2, #0
 *   @0xcc310 ldrlt r3, [r10, #0x10]
 *   @0xcc314 strlt r3, [sp, #0x4]
 *   @0xcc318 ldr r3, [r10, #0x18]
 *   @0xcc31c cmp r3, #2
 *   @0xcc320 beq 0xcc6cc <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x44c>
 *   @0xcc324 cmp r6, #0
 *   @0xcc328 blt 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4>
 *   @0xcc32c ldr r4, [r10, #0x10]
 *   @0xcc330 cmp r6, r4
 *   @0xcc334 bge 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4>
 *   @0xcc338 ldr r3, [sp, #0x4]
 *   @0xcc33c add r3, r6, r3
 *   @0xcc340 str r3, [sp, #0x10]
 *   @0xcc344 cmp r4, r3
 *   @0xcc348 strlt r4, [sp, #0x10]
 *   @0xcc34c rsblt r2, r6, r4
 *   @0xcc350 strlt r2, [sp, #0x4]
 *   @0xcc354 ldr r3, [sp, #0x4c]
 *   @0xcc358 cmp r3, #0
 *   @0xcc35c ble 0xcc704 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x484>
 *   @0xcc360 cmp r9, r3
 *   @0xcc364 movge r9, r3
 *   @0xcc368 mov r3, #0
 *   @0xcc36c str r3, [sp, #0x14]
 *   @0xcc370 ldr r2, [sp, #0x4]
 *   @0xcc374 cmp r2, r9
 *   @0xcc378 movlt r3, #0
 *   @0xcc37c movge r3, #1
 *   @0xcc380 ldr r2, [sp, #0x4]
 *   @0xcc384 cmp r2, #0
 *   @0xcc388 ble 0xcc444 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1c4>
 *   @0xcc38c ldr r2, [sp, #0x8]
 *   @0xcc390 mov r11, r6
 *   @0xcc394 str r6, [sp]
 *   @0xcc398 mov r8, #0
 *   @0xcc39c add r7, r2, r9
 *   @0xcc3a0 mov r6, r3
 *   @0xcc3a4 mov r0, r11
 *   @0xcc3a8 mov r1, r4
 *   @0xcc3ac bl 0x318dec <__aeabi_idivmod>
 *   @0xcc3b0 cmp r6, #0
 *   @0xcc3b4 mov r5, r1
 *   @0xcc3b8 beq 0xcc534 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x2b4>
 *   @0xcc3bc add r2, r9, r1
 *   @0xcc3c0 ldr r3, [r10, #0xc]
 *   @0xcc3c4 cmp r4, r2
 *   @0xcc3c8 add r3, r3, r1
 *   @0xcc3cc bge 0xcc644 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x3c4>
 *   @0xcc3d0 cmp r9, #0
 *   @0xcc3d4 ldrgt r2, [sp, #0x8]
 *   @0xcc3d8 ble 0xcc42c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1ac>
 *   @0xcc3dc ldrb r1, [r2], #1
 *   @0xcc3e0 add r5, r5, #1
 *   @0xcc3e4 add r3, r3, #1
 *   @0xcc3e8 strb r1, [r3, #-0x1]
 *   @0xcc3ec ldr r4, [r10, #0x10]
 *   @0xcc3f0 cmp r5, r4
 *   @0xcc3f4 blt 0xcc424 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1a4>
 *   @0xcc3f8 cmn r4, #1
 *   @0xcc3fc ldr r3, [r10, #0xc]
 *   @0xcc400 mov r1, r4
 *   @0xcc404 ldr r0, [r10, #0x20]
 *   @0xcc408 ldreq r1, [r10, #0x1c]
 *   @0xcc40c mov r5, #0
 *   @0xcc410 cmp r1, r0
 *   @0xcc414 movlt r1, r0
 *   @0xcc418 cmp r1, r4
 *   @0xcc41c strle r1, [r10, #0x20]
 *   @0xcc420 strgt r4, [r10, #0x20]
 *   @0xcc424 cmp r2, r7
 *   @0xcc428 bne 0xcc3dc <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x15c>
 *   @0xcc42c add r11, r11, r9
 *   @0xcc430 add r8, r8, r9
 *   @0xcc434 mov r6, #0
 *   @0xcc438 ldr r3, [sp, #0x4]
 *   @0xcc43c cmp r3, r8
 *   @0xcc440 bgt 0xcc3a4 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x124>
 *   @0xcc444 add sp, sp, #36
 *   @0xcc448 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcc44c ldr r0, [sp, #0x48]
 *   @0xcc450 mov r1, #0
 *   @0xcc454 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcc458 add r3, sp, #32
 *   @0xcc45c mov r9, #1
 *   @0xcc460 strb r0, [r3, #-0x8]!
 *   @0xcc464 str r3, [sp, #0x8]
 *   @0xcc468 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88>
 *   @0xcc46c ldr r0, [sp, #0x48]
 *   @0xcc470 mov r1, #0
 *   @0xcc474 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcc478 add r3, sp, #32
 *   @0xcc47c mov r9, #2
 *   @0xcc480 strh r0, [r3, #-8]!
 *   @0xcc484 str r3, [sp, #0x8]
 *   @0xcc488 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88>
 *   @0xcc48c ldr r0, [sp, #0x48]
 *   @0xcc490 mov r1, #0
 *   @0xcc494 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0xcc498 cmp r0, #0
 *   @0xcc49c addne r3, sp, #32
 *   @0xcc4a0 addeq r3, sp, #32
 *   @0xcc4a4 movne r9, #1
 *   @0xcc4a8 moveq r9, #1
 *   @0xcc4ac strbne r9, [r3, #-0x8]!
 *   @0xcc4b0 strbeq r0, [r3, #-0x8]!
 *   @0xcc4b4 str r3, [sp, #0x8]
 *   @0xcc4b8 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88>
 *   @0xcc4bc mov r1, #0
 *   @0xcc4c0 ldr r0, [sp, #0x48]
 *   @0xcc4c4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xcc4c8 str r0, [sp, #0x8]
 *   @0xcc4cc bl 0xb6538 <strlen@plt>
 *   @0xcc4d0 mov r9, r0
 *   @0xcc4d4 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88>
 *   @0xcc4d8 ldr r0, [sp, #0x48]
 *   @0xcc4dc mov r1, #0
 *   @0xcc4e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xcc4e4 add r3, sp, #32
 *   @0xcc4e8 mov r9, #4
 *   @0xcc4ec str r0, [r3, #-0x8]!
 *   @0xcc4f0 str r3, [sp, #0x8]
 *   @0xcc4f4 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88>
 *   @0xcc4f8 ldr r0, [sp, #0x48]
 *   @0xcc4fc mov r1, #0
 *   @0xcc500 bl 0xcea30 <_Z10YYGetInt64PK6RValuei>
 *   @0xcc504 add r3, sp, #32
 *   @0xcc508 mov r9, #8
 *   @0xcc50c strd r0, r1, [r3, #-8]!
 *   @0xcc510 str r3, [sp, #0x8]
 *   @0xcc514 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88>
 *   @0xcc518 mov r1, #0
 *   @0xcc51c ldr r0, [sp, #0x48]
 *   @0xcc520 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xcc524 str r0, [sp, #0x8]
 *   @0xcc528 bl 0xb6538 <strlen@plt>
 *   @0xcc52c add r9, r0, #1
 *   @0xcc530 b 0xcc308 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x88>
 *   @0xcc534 ldr r3, [sp, #0x14]
 *   @0xcc538 cmp r3, #0
 *   @0xcc53c ldrne r3, [r10, #0x14]
 *   @0xcc540 ldreq r3, [sp, #0x4c]
 *   @0xcc544 subne r2, r3, #1
 *   @0xcc548 ldreq r2, [sp]
 *   @0xcc54c rsbne r3, r3, #0
 *   @0xcc550 addne r6, r11, r2
 *   @0xcc554 andne r6, r6, r3
 *   @0xcc558 addeq r6, r3, r2
 *   @0xcc55c ldr r3, [sp, #0x10]
 *   @0xcc560 cmp r3, r6
 *   @0xcc564 movge r3, r6
 *   @0xcc568 str r3, [sp]
 *   @0xcc56c ldr r3, [sp, #0xc]
 *   @0xcc570 cmp r3, #0
 *   @0xcc574 ldr r3, [sp]
 *   @0xcc578 rsb r11, r11, r3
 *   @0xcc57c beq 0xcc61c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x39c>
 *   @0xcc580 add r6, r1, r11
 *   @0xcc584 cmp r4, r6
 *   @0xcc588 bge 0xcc68c <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x40c>
 *   @0xcc58c cmp r11, #0
 *   @0xcc590 movgt r6, r11
 *   @0xcc594 ble 0xcc5fc <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x37c>
 *   @0xcc598 rsb r4, r5, r4
 *   @0xcc59c ldr r0, [r10, #0xc]
 *   @0xcc5a0 cmp r4, r6
 *   @0xcc5a4 movge r4, r6
 *   @0xcc5a8 mov r1, #0
 *   @0xcc5ac add r0, r0, r5
 *   @0xcc5b0 rsb r6, r4, r6
 *   @0xcc5b4 mov r2, r4
 *   @0xcc5b8 bl 0xb65b0 <memset@plt>
 *   @0xcc5bc add r0, r5, r4
 *   @0xcc5c0 cmn r0, #1
 *   @0xcc5c4 ldr r4, [r10, #0x10]
 *   @0xcc5c8 mov r3, r0
 *   @0xcc5cc ldr r2, [r10, #0x20]
 *   @0xcc5d0 ldreq r3, [r10, #0x1c]
 *   @0xcc5d4 mov r1, r4
 *   @0xcc5d8 cmp r3, r2
 *   @0xcc5dc movlt r3, r2
 *   @0xcc5e0 cmp r3, r4
 *   @0xcc5e4 strle r3, [r10, #0x20]
 *   @0xcc5e8 strgt r4, [r10, #0x20]
 *   @0xcc5ec bl 0x318dec <__aeabi_idivmod>
 *   @0xcc5f0 cmp r6, #0
 *   @0xcc5f4 mov r5, r1
 *   @0xcc5f8 bgt 0xcc598 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x318>
 *   @0xcc5fc add r8, r8, r11
 *   @0xcc600 ldr r2, [sp, #0x4]
 *   @0xcc604 add r3, r9, r8
 *   @0xcc608 ldr r11, [sp]
 *   @0xcc60c cmp r2, r3
 *   @0xcc610 movlt r6, #0
 *   @0xcc614 movge r6, #1
 *   @0xcc618 b 0xcc438 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1b8>
 *   @0xcc61c add r5, r1, r11
 *   @0xcc620 ldr r3, [r10, #0x20]
 *   @0xcc624 cmn r5, #1
 *   @0xcc628 ldreq r5, [r10, #0x1c]
 *   @0xcc62c cmp r5, r3
 *   @0xcc630 movlt r5, r3
 *   @0xcc634 cmp r5, r4
 *   @0xcc638 strle r5, [r10, #0x20]
 *   @0xcc63c strgt r4, [r10, #0x20]
 *   @0xcc640 b 0xcc5fc <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x37c>
 *   @0xcc644 cmp r9, #0
 *   @0xcc648 ble 0xcc664 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x3e4>
 *   @0xcc64c ldr r1, [sp, #0x8]
 *   @0xcc650 ldrb r0, [r1], #1
 *   @0xcc654 cmp r1, r7
 *   @0xcc658 strb r0, [r3], #1
 *   @0xcc65c bne 0xcc650 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x3d0>
 *   @0xcc660 ldr r4, [r10, #0x10]
 *   @0xcc664 cmn r2, #1
 *   @0xcc668 ldr r3, [r10, #0x20]
 *   @0xcc66c add r11, r11, r9
 *   @0xcc670 ldreq r2, [r10, #0x1c]
 *   @0xcc674 cmp r2, r3
 *   @0xcc678 movlt r2, r3
 *   @0xcc67c cmp r2, r4
 *   @0xcc680 strle r2, [r10, #0x20]
 *   @0xcc684 strgt r4, [r10, #0x20]
 *   @0xcc688 b 0xcc430 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x1b0>
 *   @0xcc68c ldr r0, [r10, #0xc]
 *   @0xcc690 mov r2, r11
 *   @0xcc694 mov r1, #0
 *   @0xcc698 add r0, r0, r5
 *   @0xcc69c bl 0xb65b0 <memset@plt>
 *   @0xcc6a0 cmn r6, #1
 *   @0xcc6a4 ldr r4, [r10, #0x10]
 *   @0xcc6a8 ldreq r6, [r10, #0x1c]
 *   @0xcc6ac ldr r2, [r10, #0x20]
 *   @0xcc6b0 cmp r6, r2
 *   @0xcc6b4 movge r3, r6
 *   @0xcc6b8 movlt r3, r2
 *   @0xcc6bc cmp r3, r4
 *   @0xcc6c0 strle r3, [r10, #0x20]
 *   @0xcc6c4 strgt r4, [r10, #0x20]
 *   @0xcc6c8 b 0xcc5fc <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x37c>
 *   @0xcc6cc cmp r6, #0
 *   @0xcc6d0 ldr r4, [r10, #0x10]
 *   @0xcc6d4 bge 0xcc6ec <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x46c>
 *   @0xcc6d8 adds r6, r6, r4
 *   @0xcc6dc bmi 0xcc6d8 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x458>
 *   @0xcc6e0 cmp r6, r4
 *   @0xcc6e4 blt 0xcc6f4 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x474>
 *   @0xcc6e8 rsb r6, r4, r6
 *   @0xcc6ec cmp r6, r4
 *   @0xcc6f0 bge 0xcc6e8 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x468>
 *   @0xcc6f4 ldr r3, [sp, #0x4]
 *   @0xcc6f8 add r3, r6, r3
 *   @0xcc6fc str r3, [sp, #0x10]
 *   @0xcc700 b 0xcc354 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0xd4>
 *   @0xcc704 mov r0, r6
 *   @0xcc708 ldr r1, [r10, #0x14]
 *   @0xcc70c bl 0x318dec <__aeabi_idivmod>
 *   @0xcc710 mov r3, #1
 *   @0xcc714 str r3, [sp, #0x14]
 *   @0xcc718 cmp r1, #0
 *   @0xcc71c movne r3, #0
 *   @0xcc720 bne 0xcc380 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0x100>
 *   @0xcc724 b 0xcc370 <_ZN7IBuffer4FillEii12eBuffer_TypeP6RValueib+0xf0>
 *
 * ══ §7/29 Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap  0x293778  size 1192  296 条（0x293778..0x293c20）
 * @func 0x293778 0x293c20  size 1192  296 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / CreateDsMap(int, ...)
 * 字段偏移 top8: 0x2a4×11 / 0x2a8×11 / 0xb8×3 / 0xbc×3 / 0xc0×3 / 0xc4×3 / 0xc8×3 / 0x2b0×3
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x293778 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29377c mov r5, r0
 *   @0x293780 sub sp, sp, #212
 *   @0x293784 mov r11, r2
 *   @0x293788 mov r10, r3
 *   @0x29378c bl 0x290614 <setJNIEnv>
 *   @0x293790 ldr r3, [r5]
 *   @0x293794 mov r1, r10
 *   @0x293798 mov r2, #0
 *   @0x29379c mov r0, r5
 *   @0x2937a0 ldr r3, [r3, #0x2a4]
 *   @0x2937a4 blx r3
 *   @0x2937a8 ldr r3, [r5]
 *   @0x2937ac ldr r1, [sp, #0xf8]
 *   @0x2937b0 mov r2, #0
 *   @0x2937b4 ldr r3, [r3, #0x2a4]
 *   @0x2937b8 mov r9, r0
 *   @0x2937bc mov r0, r5
 *   @0x2937c0 blx r3
 *   @0x2937c4 ldr r3, [r5]
 *   @0x2937c8 ldr r1, [sp, #0xfc]
 *   @0x2937cc mov r2, #0
 *   @0x2937d0 ldr r3, [r3, #0x2a4]
 *   @0x2937d4 mov r8, r0
 *   @0x2937d8 mov r0, r5
 *   @0x2937dc blx r3
 *   @0x2937e0 ldr r3, [r5]
 *   @0x2937e4 ldr r1, [sp, #0x100]
 *   @0x2937e8 mov r2, #0
 *   @0x2937ec ldr r3, [r3, #0x2a4]
 *   @0x2937f0 str r0, [sp, #0xb8]
 *   @0x2937f4 mov r0, r5
 *   @0x2937f8 blx r3
 *   @0x2937fc ldr r3, [r5]
 *   @0x293800 ldr r1, [sp, #0x104]
 *   @0x293804 mov r2, #0
 *   @0x293808 ldr r3, [r3, #0x2a4]
 *   @0x29380c str r0, [sp, #0xbc]
 *   @0x293810 mov r0, r5
 *   @0x293814 blx r3
 *   @0x293818 ldr r3, [r5]
 *   @0x29381c ldr r1, [sp, #0x108]
 *   @0x293820 mov r2, #0
 *   @0x293824 ldr r3, [r3, #0x2a4]
 *   @0x293828 str r0, [sp, #0xc0]
 *   @0x29382c mov r0, r5
 *   @0x293830 blx r3
 *   @0x293834 ldr r3, [r5]
 *   @0x293838 ldr r1, [sp, #0x10c]
 *   @0x29383c mov r2, #0
 *   @0x293840 ldr r3, [r3, #0x2a4]
 *   @0x293844 str r0, [sp, #0xc4]
 *   @0x293848 mov r0, r5
 *   @0x29384c blx r3
 *   @0x293850 ldr r3, [r5]
 *   @0x293854 ldr r1, [sp, #0x110]
 *   @0x293858 mov r2, #0
 *   @0x29385c ldr r3, [r3, #0x2a4]
 *   @0x293860 str r0, [sp, #0xc8]
 *   @0x293864 mov r0, r5
 *   @0x293868 blx r3
 *   @0x29386c ldr r3, [r5]
 *   @0x293870 ldr r1, [sp, #0x114]
 *   @0x293874 mov r2, #0
 *   @0x293878 ldr r3, [r3, #0x2a4]
 *   @0x29387c mov r7, r0
 *   @0x293880 mov r0, r5
 *   @0x293884 blx r3
 *   @0x293888 ldr r3, [r5]
 *   @0x29388c ldr r1, [sp, #0x11c]
 *   @0x293890 mov r2, #0
 *   @0x293894 ldr r3, [r3, #0x2a4]
 *   @0x293898 mov r6, r0
 *   @0x29389c mov r0, r5
 *   @0x2938a0 blx r3
 *   @0x2938a4 ldr r3, [r5]
 *   @0x2938a8 ldr r1, [sp, #0x118]
 *   @0x2938ac mov r2, #0
 *   @0x2938b0 ldr r3, [r3, #0x2a4]
 *   @0x2938b4 mov r4, r0
 *   @0x2938b8 mov r0, r5
 *   @0x2938bc blx r3
 *   @0x2938c0 ldr r12, [sp, #0xb8]
 *   @0x2938c4 ldr r1, [pc, #0x324]
 *   @0x2938c8 vmov s15, r11
 *   @0x2938cc ldr lr, [pc, #0x320]
 *   @0x2938d0 str r12, [sp, #0x30]
 *   @0x2938d4 add r1, pc, r1
 *   @0x2938d8 ldr r12, [sp, #0xbc]
 *   @0x2938dc vcvt.f64.s32 d7, s15
 *   @0x2938e0 str r1, [sp, #0x14]
 *   @0x2938e4 add lr, pc, lr
 *   @0x2938e8 ldr r1, [pc, #0x308]
 *   @0x2938ec str r12, [sp, #0x40]
 *   @0x2938f0 ldr r12, [sp, #0xc0]
 *   @0x2938f4 add r1, pc, r1
 *   @0x2938f8 str lr, [sp, #0x4]
 *   @0x2938fc str r1, [sp, #0x44]
 *   @0x293900 str r12, [sp, #0x50]
 *   @0x293904 ldr r12, [sp, #0xc4]
 *   @0x293908 ldr r11, [pc, #0x2ec]
 *   @0x29390c ldr lr, [pc, #0x2ec]
 *   @0x293910 str r12, [sp, #0x60]
 *   @0x293914 add r11, pc, r11
 *   @0x293918 ldr r12, [sp, #0xc8]
 *   @0x29391c add lr, pc, lr
 *   @0x293920 ldr r1, [pc, #0x2dc]
 *   @0x293924 str r11, [sp, #0x24]
 *   @0x293928 str lr, [sp, #0x34]
 *   @0x29392c add r1, pc, r1
 *   @0x293930 ldr r11, [pc, #0x2d0]
 *   @0x293934 str r1, [sp, #0x74]
 *   @0x293938 ldr lr, [pc, #0x2cc]
 *   @0x29393c add r11, pc, r11
 *   @0x293940 ldr r1, [pc, #0x2c8]
 *   @0x293944 str r12, [sp, #0x70]
 *   @0x293948 add lr, pc, lr
 *   @0x29394c str r11, [sp, #0x54]
 *   @0x293950 add r1, pc, r1
 *   @0x293954 str lr, [sp, #0x64]
 *   @0x293958 str r1, [sp, #0xa4]
 *   @0x29395c ldr r11, [pc, #0x2b0]
 *   @0x293960 ldr lr, [pc, #0x2b0]
 *   @0x293964 ldr r1, [pc, #0x2b0]
 *   @0x293968 add r11, pc, r11
 *   @0x29396c vmov r2, r3, d7
 *   @0x293970 add lr, pc, lr
 *   @0x293974 str r0, [sp, #0xcc]
 *   @0x293978 vldr d7, [pc, #616]
 *   @0x29397c ldr r12, [sp, #0xcc]
 *   @0x293980 vstr d7, [sp, #8]
 *   @0x293984 str r11, [sp, #0x84]
 *   @0x293988 vstr d7, [sp, #24]
 *   @0x29398c str lr, [sp, #0x94]
 *   @0x293990 vstr d7, [sp, #40]
 *   @0x293994 str r12, [sp, #0xa0]
 *   @0x293998 mov lr, #0
 *   @0x29399c vstr d7, [sp, #56]
 *   @0x2939a0 str lr, [sp]
 *   @0x2939a4 mov r0, #12
 *   @0x2939a8 str r9, [sp, #0x10]
 *   @0x2939ac str r8, [sp, #0x20]
 *   @0x2939b0 add r1, pc, r1
 *   @0x2939b4 str r7, [sp, #0x80]
 *   @0x2939b8 str r6, [sp, #0x90]
 *   @0x2939bc vstr d7, [sp, #72]
 *   @0x2939c0 vstr d7, [sp, #88]
 *   @0x2939c4 vstr d7, [sp, #104]
 *   @0x2939c8 vstr d7, [sp, #120]
 *   @0x2939cc vstr d7, [sp, #136]
 *   @0x2939d0 vstr d7, [sp, #152]
 *   @0x2939d4 vstr d7, [sp, #168]
 *   @0x2939d8 str r4, [sp, #0xb0]
 *   @0x2939dc bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x2939e0 cmp r9, #0
 *   @0x2939e4 cmpne r10, #0
 *   @0x2939e8 mov r11, r0
 *   @0x2939ec bne 0x293bc8 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x450>
 *   @0x2939f0 ldr r12, [sp, #0xf8]
 *   @0x2939f4 cmp r8, #0
 *   @0x2939f8 cmpne r12, #0
 *   @0x2939fc bne 0x293bac <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x434>
 *   @0x293a00 ldr r12, [sp, #0xb8]
 *   @0x293a04 ldr r2, [sp, #0xfc]
 *   @0x293a08 cmp r12, #0
 *   @0x293a0c cmpne r2, #0
 *   @0x293a10 bne 0x293b90 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x418>
 *   @0x293a14 ldr r12, [sp, #0xbc]
 *   @0x293a18 ldr r2, [sp, #0x100]
 *   @0x293a1c cmp r12, #0
 *   @0x293a20 cmpne r2, #0
 *   @0x293a24 bne 0x293b74 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x3fc>
 *   @0x293a28 ldr r12, [sp, #0xc0]
 *   @0x293a2c ldr r2, [sp, #0x104]
 *   @0x293a30 cmp r12, #0
 *   @0x293a34 cmpne r2, #0
 *   @0x293a38 bne 0x293b58 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x3e0>
 *   @0x293a3c ldr r12, [sp, #0xc4]
 *   @0x293a40 ldr r2, [sp, #0x108]
 *   @0x293a44 cmp r12, #0
 *   @0x293a48 cmpne r2, #0
 *   @0x293a4c bne 0x293b3c <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x3c4>
 *   @0x293a50 ldr r12, [sp, #0xc8]
 *   @0x293a54 ldr r2, [sp, #0x10c]
 *   @0x293a58 cmp r12, #0
 *   @0x293a5c cmpne r2, #0
 *   @0x293a60 bne 0x293b20 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x3a8>
 *   @0x293a64 ldr r12, [sp, #0x110]
 *   @0x293a68 cmp r7, #0
 *   @0x293a6c cmpne r12, #0
 *   @0x293a70 bne 0x293b04 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x38c>
 *   @0x293a74 ldr r12, [sp, #0x114]
 *   @0x293a78 cmp r6, #0
 *   @0x293a7c cmpne r12, #0
 *   @0x293a80 bne 0x293ae8 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x370>
 *   @0x293a84 ldr r12, [sp, #0xcc]
 *   @0x293a88 ldr r2, [sp, #0x118]
 *   @0x293a8c cmp r12, #0
 *   @0x293a90 cmpne r2, #0
 *   @0x293a94 bne 0x293acc <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x354>
 *   @0x293a98 ldr r12, [sp, #0x11c]
 *   @0x293a9c cmp r4, #0
 *   @0x293aa0 cmpne r12, #0
 *   @0x293aa4 beq 0x293ac0 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x348>
 *   @0x293aa8 ldr r3, [r5]
 *   @0x293aac mov r1, r12
 *   @0x293ab0 mov r2, r4
 *   @0x293ab4 mov r0, r5
 *   @0x293ab8 ldr r3, [r3, #0x2a8]
 *   @0x293abc blx r3
 *   @0x293ac0 mov r0, r11
 *   @0x293ac4 add sp, sp, #212
 *   @0x293ac8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x293acc ldr r3, [r5]
 *   @0x293ad0 mov r1, r2
 *   @0x293ad4 mov r0, r5
 *   @0x293ad8 mov r2, r12
 *   @0x293adc ldr r3, [r3, #0x2a8]
 *   @0x293ae0 blx r3
 *   @0x293ae4 b 0x293a98 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x320>
 *   @0x293ae8 ldr r3, [r5]
 *   @0x293aec mov r1, r12
 *   @0x293af0 mov r2, r6
 *   @0x293af4 mov r0, r5
 *   @0x293af8 ldr r3, [r3, #0x2a8]
 *   @0x293afc blx r3
 *   @0x293b00 b 0x293a84 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x30c>
 *   @0x293b04 ldr r3, [r5]
 *   @0x293b08 mov r1, r12
 *   @0x293b0c mov r2, r7
 *   @0x293b10 mov r0, r5
 *   @0x293b14 ldr r3, [r3, #0x2a8]
 *   @0x293b18 blx r3
 *   @0x293b1c b 0x293a74 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x2fc>
 *   @0x293b20 ldr r3, [r5]
 *   @0x293b24 mov r1, r2
 *   @0x293b28 mov r0, r5
 *   @0x293b2c mov r2, r12
 *   @0x293b30 ldr r3, [r3, #0x2a8]
 *   @0x293b34 blx r3
 *   @0x293b38 b 0x293a64 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x2ec>
 *   @0x293b3c ldr r3, [r5]
 *   @0x293b40 mov r1, r2
 *   @0x293b44 mov r0, r5
 *   @0x293b48 mov r2, r12
 *   @0x293b4c ldr r3, [r3, #0x2a8]
 *   @0x293b50 blx r3
 *   @0x293b54 b 0x293a50 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x2d8>
 *   @0x293b58 ldr r3, [r5]
 *   @0x293b5c mov r1, r2
 *   @0x293b60 mov r0, r5
 *   @0x293b64 mov r2, r12
 *   @0x293b68 ldr r3, [r3, #0x2a8]
 *   @0x293b6c blx r3
 *   @0x293b70 b 0x293a3c <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x2c4>
 *   @0x293b74 ldr r3, [r5]
 *   @0x293b78 mov r1, r2
 *   @0x293b7c mov r0, r5
 *   @0x293b80 mov r2, r12
 *   @0x293b84 ldr r3, [r3, #0x2a8]
 *   @0x293b88 blx r3
 *   @0x293b8c b 0x293a28 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x2b0>
 *   @0x293b90 ldr r3, [r5]
 *   @0x293b94 mov r1, r2
 *   @0x293b98 mov r0, r5
 *   @0x293b9c mov r2, r12
 *   @0x293ba0 ldr r3, [r3, #0x2a8]
 *   @0x293ba4 blx r3
 *   @0x293ba8 b 0x293a14 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x29c>
 *   @0x293bac ldr r3, [r5]
 *   @0x293bb0 mov r1, r12
 *   @0x293bb4 mov r2, r8
 *   @0x293bb8 mov r0, r5
 *   @0x293bbc ldr r3, [r3, #0x2a8]
 *   @0x293bc0 blx r3
 *   @0x293bc4 b 0x293a00 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x288>
 *   @0x293bc8 ldr r3, [r5]
 *   @0x293bcc mov r1, r10
 *   @0x293bd0 mov r2, r9
 *   @0x293bd4 mov r0, r5
 *   @0x293bd8 ldr r3, [r3, #0x2a8]
 *   @0x293bdc blx r3
 *   @0x293be0 b 0x2939f0 <Java_com_yoyogames_runner_RunnerJNILib_CreateVersionDSMap+0x278>
 *   @0x293be4 nop
 *   @0x293bf0 andeq r6, r11, r8, lsr r0
 *   @0x293bf4 andeq r6, r11, r0, lsl r0
 *   @0x293bf8 andeq r6, r11, r8, rrx
 *   @0x293bfc andeq r6, r11, r0, lsl r0
 *   @0x293c00 andeq r6, r11, r0, lsr #32
 *   @0x293c04 andeq r6, r11, r0, lsl #1
 *   @0x293c08 andeq r6, r11, r8, lsr r0
 *   @0x293c0c andeq r6, r11, r8, asr #32
 *   @0x293c10 andeq r6, r11, r12, lsl #1
 *   @0x293c14 andeq r6, r11, r12, asr r0
 *   @0x293c18 andeq r6, r11, r8, lsl #1
 *   @0x293c1c andeq r5, r11, r12, lsr #30
 *
 * ══ §8/29 VM::WriteCallStack(Buffer_Standard*, VMExec*, bool)  0xd90a8  size 1184  296 条（0xd90a8..0xd9548）
 * @func 0xd90a8 0xd9548  size 1184  296 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::WriteRValueToBuffer(RValue*, Buffer_Standard*)×3 / VM::GetLocalVariables(Buffer_Standard*, YYObjectBase*, bool, int)×2 / VM::WriteCallStack(Buffer_Standard*, VMExec*, bool)+0x88 / VM::WriteCallStack(Buffer_Standard*, VMExec*, bool)+0x278 / VM::WriteCallStack(Buffer_Standard*, VMExec*, bool)+0x234 / VM::WriteCallStack(Buffer_Standard*, VMExec*, bool)+0x3c4
 * 字段偏移 top8: 0x8×19 / 0x38×15 / 0x30×15 / 0x2c×6 / 0x10×6 / 0x78×4 / 0x1c×3 / 0x4×3
 * VFP 指令 40 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd90a8 subs r3, r2, #0
 *   @0xd90ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd90b0 mov r7, r1
 *   @0xd90b4 sub sp, sp, #12
 *   @0xd90b8 mov r4, r0
 *   @0xd90bc beq 0xd9508 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x460>
 *   @0xd90c0 ldr r10, [pc, #0x478]
 *   @0xd90c4 add r5, r0, #44
 *   @0xd90c8 ldr r3, [r0]
 *   @0xd90cc mov r6, #0
 *   @0xd90d0 ldr r10, [pc, r10]
 *   @0xd90d4 vldr s15, [r10]
 *   @0xd90d8 vcvt.f64.u32 d7, s15
 *   @0xd90dc str r6, [r0, #0x38]
 *   @0xd90e0 mov r2, r5
 *   @0xd90e4 mov r1, #5
 *   @0xd90e8 vmov r8, r9, d7
 *   @0xd90ec vstr s14, [r4, #44]
 *   @0xd90f0 str r9, [r4, #0x30]
 *   @0xd90f4 ldr r3, [r3, #0x8]
 *   @0xd90f8 blx r3
 *   @0xd90fc ldr r3, [r10]
 *   @0xd9100 cmp r3, r6
 *   @0xd9104 ble 0xd9130 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x88>
 *   @0xd9108 ldr r8, [pc, #0x434]
 *   @0xd910c ldr r8, [pc, r8]
 *   @0xd9110 ldr r0, [r8]
 *   @0xd9114 mov r1, r4
 *   @0xd9118 add r0, r0, r6, lsl #4
 *   @0xd911c add r6, r6, #1
 *   @0xd9120 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xd9124 ldr r3, [r10]
 *   @0xd9128 cmp r3, r6
 *   @0xd912c bgt 0xd9110 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x68>
 *   @0xd9130 ldr r3, [r4]
 *   @0xd9134 mov r9, #0
 *   @0xd9138 ldr r12, [r4, #0x1c]
 *   @0xd913c mov r0, r4
 *   @0xd9140 str r9, [r4, #0x2c]
 *   @0xd9144 mov r1, #5
 *   @0xd9148 str r9, [r4, #0x30]
 *   @0xd914c mov r2, r5
 *   @0xd9150 str r9, [r4, #0x38]
 *   @0xd9154 ldr r3, [r3, #0x8]
 *   @0xd9158 str r12, [sp, #0x4]
 *   @0xd915c blx r3
 *   @0xd9160 cmp r7, r9
 *   @0xd9164 moveq r6, r7
 *   @0xd9168 beq 0xd9498 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x3f0>
 *   @0xd916c mov r6, r9
 *   @0xd9170 str r9, [sp]
 *   @0xd9174 ldr r10, [r7, #0x4c]
 *   @0xd9178 ldr r11, [r7, #0x28]
 *   @0xd917c cmp r10, #100
 *   @0xd9180 movge r10, #100
 *   @0xd9184 cmp r10, #0
 *   @0xd9188 ble 0xd9320 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x278>
 *   @0xd918c ldr r3, [r11, #0x18]
 *   @0xd9190 cmp r3, #0
 *   @0xd9194 beq 0xd9320 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x278>
 *   @0xd9198 ldr lr, [r3, #0x10]
 *   @0xd919c mov r1, #12
 *   @0xd91a0 ldr r8, [r4]
 *   @0xd91a4 mov r3, #10
 *   @0xd91a8 mov r2, r5
 *   @0xd91ac str r3, [r4, #0x38]
 *   @0xd91b0 str lr, [r4, #0x2c]
 *   @0xd91b4 asr r3, lr, #31
 *   @0xd91b8 mov r0, r4
 *   @0xd91bc str r3, [r4, #0x30]
 *   @0xd91c0 ldr r3, [r8, #0x8]
 *   @0xd91c4 blx r3
 *   @0xd91c8 ldr r8, [r11]
 *   @0xd91cc ldr r3, [r4]
 *   @0xd91d0 mov r1, #5
 *   @0xd91d4 mov r2, r5
 *   @0xd91d8 mov r0, r4
 *   @0xd91dc vmov s15, r8
 *   @0xd91e0 str r6, [r4, #0x38]
 *   @0xd91e4 vcvt.f64.u32 d7, s15
 *   @0xd91e8 vmov r8, r9, d7
 *   @0xd91ec vstr s14, [r4, #44]
 *   @0xd91f0 str r9, [r4, #0x30]
 *   @0xd91f4 ldr r3, [r3, #0x8]
 *   @0xd91f8 blx r3
 *   @0xd91fc ldr r2, [r11, #0x10]
 *   @0xd9200 ldr r3, [r4]
 *   @0xd9204 mov r1, #5
 *   @0xd9208 mov r0, r4
 *   @0xd920c ldr r8, [r2, #0x78]
 *   @0xd9210 mov r2, r5
 *   @0xd9214 str r6, [r4, #0x38]
 *   @0xd9218 vmov s15, r8
 *   @0xd921c vcvt.f64.u32 d7, s15
 *   @0xd9220 vmov r8, r9, d7
 *   @0xd9224 vstr s14, [r4, #44]
 *   @0xd9228 str r9, [r4, #0x30]
 *   @0xd922c ldr r3, [r3, #0x8]
 *   @0xd9230 blx r3
 *   @0xd9234 ldr r2, [r11, #0x14]
 *   @0xd9238 ldr r3, [r4]
 *   @0xd923c mov r1, #5
 *   @0xd9240 mov r0, r4
 *   @0xd9244 ldr r8, [r2, #0x78]
 *   @0xd9248 mov r2, r5
 *   @0xd924c str r6, [r4, #0x38]
 *   @0xd9250 vmov s15, r8
 *   @0xd9254 vcvt.f64.u32 d7, s15
 *   @0xd9258 vmov r8, r9, d7
 *   @0xd925c vstr s14, [r4, #44]
 *   @0xd9260 str r9, [r4, #0x30]
 *   @0xd9264 ldr r3, [r3, #0x8]
 *   @0xd9268 blx r3
 *   @0xd926c ldr r8, [r11, #0x8]
 *   @0xd9270 ldr r3, [r4]
 *   @0xd9274 mov r0, r4
 *   @0xd9278 str r6, [r4, #0x38]
 *   @0xd927c mov r1, #5
 *   @0xd9280 vmov s15, r8
 *   @0xd9284 mov r2, r5
 *   @0xd9288 vcvt.f64.u32 d7, s15
 *   @0xd928c vmov r8, r9, d7
 *   @0xd9290 vstr s14, [r4, #44]
 *   @0xd9294 str r9, [r4, #0x30]
 *   @0xd9298 ldr r3, [r3, #0x8]
 *   @0xd929c blx r3
 *   @0xd92a0 ldr r3, [r11, #0x8]
 *   @0xd92a4 ldr r8, [r7, #0x8]
 *   @0xd92a8 cmp r3, #0
 *   @0xd92ac ldr r3, [r11, #0x38]
 *   @0xd92b0 add r8, r8, r3
 *   @0xd92b4 ble 0xd92dc <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x234>
 *   @0xd92b8 mov r9, #0
 *   @0xd92bc mov r0, r8
 *   @0xd92c0 mov r1, r4
 *   @0xd92c4 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xd92c8 ldr r3, [r11, #0x8]
 *   @0xd92cc add r9, r9, #1
 *   @0xd92d0 add r8, r8, #16
 *   @0xd92d4 cmp r3, r9
 *   @0xd92d8 bgt 0xd92bc <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x214>
 *   @0xd92dc ldr r12, [sp]
 *   @0xd92e0 mov r2, #1
 *   @0xd92e4 ldr r1, [r11, #0x30]
 *   @0xd92e8 mov r3, #3392
 *   @0xd92ec mov r0, r4
 *   @0xd92f0 movt r3, #0x3
 *   @0xd92f4 add r12, r12, r2
 *   @0xd92f8 sub r10, r10, #1
 *   @0xd92fc str r12, [sp]
 *   @0xd9300 bl 0xd8f48 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi>
 *   @0xd9304 ldr r2, [r11, #0xc]
 *   @0xd9308 cmp r10, #0
 *   @0xd930c ldr r12, [r7, #0x40]
 *   @0xd9310 ldr r3, [r7, #0x8]
 *   @0xd9314 rsb r12, r2, r12
 *   @0xd9318 add r11, r3, r12
 *   @0xd931c bgt 0xd918c <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0xe4>
 *   @0xd9320 ldr r7, [r7, #0x4]
 *   @0xd9324 cmp r7, #0
 *   @0xd9328 beq 0xd9494 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x3ec>
 *   @0xd932c ldr r3, [r7, #0x2c]
 *   @0xd9330 mov lr, #10
 *   @0xd9334 ldr r12, [r4]
 *   @0xd9338 mov r1, #12
 *   @0xd933c mov r2, r5
 *   @0xd9340 mov r0, r4
 *   @0xd9344 ldr r3, [r3, #0x10]
 *   @0xd9348 str lr, [r4, #0x38]
 *   @0xd934c asr r9, r3, #31
 *   @0xd9350 str r3, [r4, #0x2c]
 *   @0xd9354 str r9, [r4, #0x30]
 *   @0xd9358 ldr r3, [r12, #0x8]
 *   @0xd935c blx r3
 *   @0xd9360 ldr r8, [r7, #0x44]
 *   @0xd9364 ldr r3, [r4]
 *   @0xd9368 mov r1, #5
 *   @0xd936c mov r2, r5
 *   @0xd9370 mov r0, r4
 *   @0xd9374 vmov s15, r8
 *   @0xd9378 str r6, [r4, #0x38]
 *   @0xd937c vcvt.f64.u32 d7, s15
 *   @0xd9380 vmov r8, r9, d7
 *   @0xd9384 vstr s14, [r4, #44]
 *   @0xd9388 str r9, [r4, #0x30]
 *   @0xd938c ldr r3, [r3, #0x8]
 *   @0xd9390 blx r3
 *   @0xd9394 ldr r12, [r7, #0x14]
 *   @0xd9398 ldr r3, [r4]
 *   @0xd939c mov r1, #5
 *   @0xd93a0 mov r2, r5
 *   @0xd93a4 mov r0, r4
 *   @0xd93a8 ldr r8, [r12, #0x78]
 *   @0xd93ac str r6, [r4, #0x38]
 *   @0xd93b0 vmov s15, r8
 *   @0xd93b4 vcvt.f64.u32 d7, s15
 *   @0xd93b8 vmov r8, r9, d7
 *   @0xd93bc vstr s14, [r4, #44]
 *   @0xd93c0 str r9, [r4, #0x30]
 *   @0xd93c4 ldr r3, [r3, #0x8]
 *   @0xd93c8 blx r3
 *   @0xd93cc ldr r12, [r7, #0x18]
 *   @0xd93d0 ldr r3, [r4]
 *   @0xd93d4 mov r1, #5
 *   @0xd93d8 mov r2, r5
 *   @0xd93dc mov r0, r4
 *   @0xd93e0 ldr r8, [r12, #0x78]
 *   @0xd93e4 str r6, [r4, #0x38]
 *   @0xd93e8 vmov s15, r8
 *   @0xd93ec vcvt.f64.u32 d7, s15
 *   @0xd93f0 vmov r8, r9, d7
 *   @0xd93f4 vstr s14, [r4, #44]
 *   @0xd93f8 str r9, [r4, #0x30]
 *   @0xd93fc ldr r3, [r3, #0x8]
 *   @0xd9400 blx r3
 *   @0xd9404 ldr r8, [r7, #0x20]
 *   @0xd9408 ldr r3, [r4]
 *   @0xd940c mov r0, r4
 *   @0xd9410 str r6, [r4, #0x38]
 *   @0xd9414 mov r1, #5
 *   @0xd9418 vmov s15, r8
 *   @0xd941c mov r2, r5
 *   @0xd9420 vcvt.f64.u32 d7, s15
 *   @0xd9424 vmov r8, r9, d7
 *   @0xd9428 vstr s14, [r4, #44]
 *   @0xd942c str r9, [r4, #0x30]
 *   @0xd9430 ldr r3, [r3, #0x8]
 *   @0xd9434 blx r3
 *   @0xd9438 ldr r3, [r7, #0x20]
 *   @0xd943c ldr r8, [r7, #0x1c]
 *   @0xd9440 cmp r3, #0
 *   @0xd9444 movgt r9, #0
 *   @0xd9448 ble 0xd946c <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x3c4>
 *   @0xd944c mov r0, r8
 *   @0xd9450 mov r1, r4
 *   @0xd9454 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xd9458 ldr r3, [r7, #0x20]
 *   @0xd945c add r9, r9, #1
 *   @0xd9460 add r8, r8, #16
 *   @0xd9464 cmp r3, r9
 *   @0xd9468 bgt 0xd944c <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0x3a4>
 *   @0xd946c ldr r12, [sp]
 *   @0xd9470 mov r2, #1
 *   @0xd9474 mov r3, #3392
 *   @0xd9478 mov r0, r4
 *   @0xd947c movt r3, #0x3
 *   @0xd9480 ldr r1, [r7, #0x10]
 *   @0xd9484 add r12, r12, r2
 *   @0xd9488 str r12, [sp]
 *   @0xd948c bl 0xd8f48 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi>
 *   @0xd9490 b 0xd9174 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb+0xcc>
 *   @0xd9494 ldr r6, [sp]
 *   @0xd9498 ldr r3, [r4]
 *   @0xd949c mov r1, #0
 *   @0xd94a0 ldr r2, [sp, #0x4]
 *   @0xd94a4 mov r0, r4
 *   @0xd94a8 mov r8, r1
 *   @0xd94ac ldr r9, [r4, #0x1c]
 *   @0xd94b0 ldr r3, [r3, #0x10]
 *   @0xd94b4 blx r3
 *   @0xd94b8 vmov s15, r6
 *   @0xd94bc ldr r3, [r4]
 *   @0xd94c0 mov r2, r5
 *   @0xd94c4 vcvt.f64.u32 d7, s15
 *   @0xd94c8 str r8, [r4, #0x38]
 *   @0xd94cc mov r0, r4
 *   @0xd94d0 mov r1, #5
 *   @0xd94d4 vmov r6, r7, d7
 *   @0xd94d8 vstr s14, [r4, #44]
 *   @0xd94dc str r7, [r4, #0x30]
 *   @0xd94e0 ldr r3, [r3, #0x8]
 *   @0xd94e4 blx r3
 *   @0xd94e8 ldr r3, [r4]
 *   @0xd94ec mov r1, r8
 *   @0xd94f0 mov r2, r9
 *   @0xd94f4 mov r0, r4
 *   @0xd94f8 ldr r3, [r3, #0x10]
 *   @0xd94fc blx r3
 *   @0xd9500 add sp, sp, #12
 *   @0xd9504 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd9508 mov r2, r0
 *   @0xd950c str r3, [r0, #0x38]
 *   @0xd9510 ldr r12, [r2], #44
 *   @0xd9514 mov r1, #0
 *   @0xd9518 movw r3, #0xffff
 *   @0xd951c movt r1, #0xffe0
 *   @0xd9520 movt r3, #0x41ef
 *   @0xd9524 str r1, [r0, #0x2c]
 *   @0xd9528 str r3, [r0, #0x30]
 *   @0xd952c mov r1, #5
 *   @0xd9530 ldr r3, [r12, #0x8]
 *   @0xd9534 blx r3
 *   @0xd9538 add sp, sp, #12
 *   @0xd953c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd9540 eorseq r4, r1, r12, lsr r12
 *   @0xd9544 eorseq r4, r1, r4, lsl #24
 *
 * ══ §9/29 F_DsGridSetPre(RValue&, CInstance*, CInstance*, int, RValue*)  0x103444  size 1176  294 条（0x103444..0x1038dc）
 * @func 0x103444 0x1038dc  size 1176  294 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int)×3 / GetContextStackTop()×2 / _RefThing<char const*>::dec()×2 / FREE_RValue__Pre(RValue*)×2
 * 字段偏移 top8: 0x4×18 / 0x30×15 / 0x8×12 / 0xc×7 / 0x3c×4 / 0x38×2 / 0x34×2 / 0x434×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x103444 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x103448 sub sp, sp, #16
 *   @0x10344c mov r1, #0
 *   @0x103450 mov r7, r0
 *   @0x103454 ldr r4, [sp, #0x30]
 *   @0x103458 mov r0, r4
 *   @0x10345c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x103460 mov r1, #1
 *   @0x103464 mov r5, r0
 *   @0x103468 mov r0, r4
 *   @0x10346c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x103470 mov r1, #2
 *   @0x103474 mov r6, r0
 *   @0x103478 mov r0, r4
 *   @0x10347c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x103480 cmp r5, #0
 *   @0x103484 mov r12, r0
 *   @0x103488 blt 0x103590 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x10348c ldr r2, [pc, #0x434]
 *   @0x103490 ldr r2, [pc, r2]
 *   @0x103494 ldr r3, [r2]
 *   @0x103498 cmp r5, r3
 *   @0x10349c bge 0x103590 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x1034a0 ldr r3, [pc, #0x424]
 *   @0x1034a4 ldr r3, [pc, r3]
 *   @0x1034a8 ldr r3, [r3, #0x4]
 *   @0x1034ac ldr r3, [r3, r5, lsl #2]
 *   @0x1034b0 cmp r3, #0
 *   @0x1034b4 beq 0x103590 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x1034b8 cmp r6, #0
 *   @0x1034bc ldr r8, [r3, #0x4]
 *   @0x1034c0 blt 0x1035a8 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x1034c4 cmp r6, r8
 *   @0x1034c8 bge 0x1035a8 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x1034cc cmp r0, #0
 *   @0x1034d0 ldr r9, [r3, #0x8]
 *   @0x1034d4 blt 0x1035ac <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1034d8 cmp r0, r9
 *   @0x1034dc bge 0x1035ac <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1034e0 mla r6, r8, r0, r6
 *   @0x1034e4 ldr r9, [r3]
 *   @0x1034e8 add r5, r9, r6, lsl #4
 *   @0x1034ec ldr r2, [r5, #0xc]
 *   @0x1034f0 bic r3, r2, #-16777216
 *   @0x1034f4 cmp r3, #1
 *   @0x1034f8 beq 0x1037c8 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x384>
 *   @0x1034fc cmp r3, #2
 *   @0x103500 bne 0x103528 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x103504 sub r3, r2, #1
 *   @0x103508 bic r3, r3, #-16777216
 *   @0x10350c bic r3, r3, #3
 *   @0x103510 cmp r3, #0
 *   @0x103514 beq 0x1038b0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x46c>
 *   @0x103518 mov r2, #0
 *   @0x10351c mov r3, #5
 *   @0x103520 str r2, [r5, #0x8]
 *   @0x103524 str r3, [r5, #0xc]
 *   @0x103528 ldr r3, [r4, #0x3c]
 *   @0x10352c mov r1, #0
 *   @0x103530 ldr r2, [r4, #0x38]
 *   @0x103534 str r1, [r9, r6, lsl #4]
 *   @0x103538 str r3, [r5, #0xc]
 *   @0x10353c ldr r3, [r4, #0x3c]
 *   @0x103540 str r2, [r5, #0x8]
 *   @0x103544 bic r3, r3, #-16777216
 *   @0x103548 cmp r3, #14
 *   @0x10354c addls pc, pc, r3, lsl #2
 *   @0x103550 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x103554 b 0x10369c <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x258>
 *   @0x103558 b 0x1036c0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x27c>
 *   @0x10355c b 0x103768 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x324>
 *   @0x103560 b 0x1035e4 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x103564 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x103568 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x10356c b 0x103744 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x300>
 *   @0x103570 b 0x1035e4 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x103574 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x103578 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x10357c b 0x10369c <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x258>
 *   @0x103580 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x103584 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x103588 b 0x10369c <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x258>
 *   @0x10358c b 0x1035e4 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x103590 ldr r0, [pc, #0x338]
 *   @0x103594 mov r1, #0
 *   @0x103598 add r0, pc, r0
 *   @0x10359c add sp, sp, #16
 *   @0x1035a0 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1035a4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1035a8 ldr r9, [r3, #0x8]
 *   @0x1035ac ldr r0, [pc, #0x320]
 *   @0x1035b0 mov r2, r5
 *   @0x1035b4 ldr r1, [pc, #0x31c]
 *   @0x1035b8 mov r3, r6
 *   @0x1035bc ldr r0, [pc, r0]
 *   @0x1035c0 add r1, pc, r1
 *   @0x1035c4 ldr r0, [r0]
 *   @0x1035c8 ldr lr, [r0]
 *   @0x1035cc str r12, [sp]
 *   @0x1035d0 stmib sp, {r8, r9}
 *   @0x1035d4 ldr r12, [lr, #0xc]
 *   @0x1035d8 blx r12
 *   @0x1035dc add sp, sp, #16
 *   @0x1035e0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1035e4 ldr r3, [r4, #0x30]
 *   @0x1035e8 str r3, [r9, r6, lsl #4]
 *   @0x1035ec ldr r2, [r7, #0xc]
 *   @0x1035f0 bic r3, r2, #-16777216
 *   @0x1035f4 cmp r3, #1
 *   @0x1035f8 beq 0x103794 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x350>
 *   @0x1035fc cmp r3, #2
 *   @0x103600 bne 0x103628 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x103604 sub r3, r2, #1
 *   @0x103608 bic r3, r3, #-16777216
 *   @0x10360c bic r3, r3, #3
 *   @0x103610 cmp r3, #0
 *   @0x103614 beq 0x1038bc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x478>
 *   @0x103618 mov r2, #0
 *   @0x10361c mov r3, #5
 *   @0x103620 str r2, [r7, #0x8]
 *   @0x103624 str r3, [r7, #0xc]
 *   @0x103628 ldr r3, [r4, #0x3c]
 *   @0x10362c mov r1, #0
 *   @0x103630 ldr r2, [r4, #0x38]
 *   @0x103634 str r1, [r7]
 *   @0x103638 str r3, [r7, #0xc]
 *   @0x10363c ldr r3, [r4, #0x3c]
 *   @0x103640 str r2, [r7, #0x8]
 *   @0x103644 bic r3, r3, #-16777216
 *   @0x103648 cmp r3, #14
 *   @0x10364c addls pc, pc, r3, lsl #2
 *   @0x103650 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103654 b 0x1036b0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x103658 b 0x10372c <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x2e8>
 *   @0x10365c b 0x103700 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x2bc>
 *   @0x103660 b 0x103690 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x103664 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103668 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x10366c b 0x1036d8 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x294>
 *   @0x103670 b 0x103690 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x103674 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103678 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x10367c b 0x1036b0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x103680 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103684 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103688 b 0x1036b0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x10368c b 0x103690 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x103690 ldr r3, [r4, #0x30]
 *   @0x103694 str r3, [r7]
 *   @0x103698 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x10369c ldr r2, [r4, #0x30]
 *   @0x1036a0 ldr r3, [r4, #0x34]
 *   @0x1036a4 str r2, [r9, r6, lsl #4]
 *   @0x1036a8 str r3, [r5, #0x4]
 *   @0x1036ac b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x1036b0 ldr r2, [r4, #0x30]
 *   @0x1036b4 ldr r3, [r4, #0x34]
 *   @0x1036b8 stm r7, {r2, r3}
 *   @0x1036bc b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x1036c0 ldr r3, [r4, #0x30]
 *   @0x1036c4 cmp r3, #0
 *   @0x1036c8 ldrne r2, [r3, #0x4]
 *   @0x1036cc addne r2, r2, #1
 *   @0x1036d0 strne r2, [r3, #0x4]
 *   @0x1036d4 b 0x1035e8 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x1036d8 ldr r3, [r4, #0x30]
 *   @0x1036dc str r3, [r7]
 *   @0x1036e0 ldr r3, [r4, #0x30]
 *   @0x1036e4 cmp r3, #0
 *   @0x1036e8 beq 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x1036ec bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1036f0 ldr r1, [r4, #0x30]
 *   @0x1036f4 add sp, sp, #16
 *   @0x1036f8 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1036fc b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x103700 ldr r3, [r4, #0x30]
 *   @0x103704 cmp r3, #0
 *   @0x103708 str r3, [r7]
 *   @0x10370c beq 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x103710 ldr r1, [r3, #0x8]
 *   @0x103714 ldr r2, [r3]
 *   @0x103718 cmp r1, #0
 *   @0x10371c streq r7, [r3, #0x8]
 *   @0x103720 add r2, r2, #1
 *   @0x103724 str r2, [r3]
 *   @0x103728 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x10372c ldr r3, [r4, #0x30]
 *   @0x103730 cmp r3, #0
 *   @0x103734 ldrne r2, [r3, #0x4]
 *   @0x103738 addne r2, r2, #1
 *   @0x10373c strne r2, [r3, #0x4]
 *   @0x103740 b 0x103694 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x250>
 *   @0x103744 ldr r3, [r4, #0x30]
 *   @0x103748 str r3, [r9, r6, lsl #4]
 *   @0x10374c ldr r3, [r4, #0x30]
 *   @0x103750 cmp r3, #0
 *   @0x103754 beq 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x103758 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x10375c ldr r1, [r4, #0x30]
 *   @0x103760 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x103764 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x103768 ldr r3, [r4, #0x30]
 *   @0x10376c cmp r3, #0
 *   @0x103770 str r3, [r9, r6, lsl #4]
 *   @0x103774 beq 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x103778 ldr r1, [r3, #0x8]
 *   @0x10377c ldr r2, [r3]
 *   @0x103780 cmp r1, #0
 *   @0x103784 streq r5, [r3, #0x8]
 *   @0x103788 add r2, r2, #1
 *   @0x10378c str r2, [r3]
 *   @0x103790 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x103794 ldr r5, [r7]
 *   @0x103798 cmp r5, #0
 *   @0x10379c beq 0x1037bc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x378>
 *   @0x1037a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1037a4 ldr r6, [r5, #0x4]
 *   @0x1037a8 sub r6, r6, #1
 *   @0x1037ac str r6, [r5, #0x4]
 *   @0x1037b0 cmp r6, #0
 *   @0x1037b4 beq 0x1037fc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x3b8>
 *   @0x1037b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1037bc mov r3, #0
 *   @0x1037c0 str r3, [r7]
 *   @0x1037c4 b 0x103628 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x1037c8 ldr r8, [r9, r6, lsl #4]
 *   @0x1037cc cmp r8, #0
 *   @0x1037d0 beq 0x1037f0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x3ac>
 *   @0x1037d4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1037d8 ldr r3, [r8, #0x4]
 *   @0x1037dc sub r3, r3, #1
 *   @0x1037e0 str r3, [r8, #0x4]
 *   @0x1037e4 cmp r3, #0
 *   @0x1037e8 beq 0x103854 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x410>
 *   @0x1037ec bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1037f0 mov r3, #0
 *   @0x1037f4 str r3, [r9, r6, lsl #4]
 *   @0x1037f8 b 0x103528 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x1037fc ldr r0, [r5]
 *   @0x103800 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x103804 str r6, [r5]
 *   @0x103808 str r6, [r5, #0x8]
 *   @0x10380c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x103810 ldr r6, [r5, #0x4]
 *   @0x103814 sub r6, r6, #1
 *   @0x103818 str r6, [r5, #0x4]
 *   @0x10381c cmp r6, #0
 *   @0x103820 bne 0x103844 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x400>
 *   @0x103824 ldr r0, [r5]
 *   @0x103828 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10382c mov r0, r5
 *   @0x103830 str r6, [r5]
 *   @0x103834 str r6, [r5, #0x8]
 *   @0x103838 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x10383c mov r0, r5
 *   @0x103840 bl 0x27d1d0 <_ZdlPv>
 *   @0x103844 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x103848 mov r0, r5
 *   @0x10384c bl 0x27d1d0 <_ZdlPv>
 *   @0x103850 b 0x1037b8 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x103854 ldr r0, [r8]
 *   @0x103858 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10385c mov r3, #0
 *   @0x103860 str r3, [r8]
 *   @0x103864 str r3, [r8, #0x8]
 *   @0x103868 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x10386c ldr r10, [r8, #0x4]
 *   @0x103870 sub r10, r10, #1
 *   @0x103874 str r10, [r8, #0x4]
 *   @0x103878 cmp r10, #0
 *   @0x10387c bne 0x1038a0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x45c>
 *   @0x103880 ldr r0, [r8]
 *   @0x103884 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x103888 mov r0, r8
 *   @0x10388c str r10, [r8]
 *   @0x103890 str r10, [r8, #0x8]
 *   @0x103894 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x103898 mov r0, r8
 *   @0x10389c bl 0x27d1d0 <_ZdlPv>
 *   @0x1038a0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1038a4 mov r0, r8
 *   @0x1038a8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1038ac b 0x1037ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x3a8>
 *   @0x1038b0 mov r0, r5
 *   @0x1038b4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1038b8 b 0x103518 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x1038bc mov r0, r7
 *   @0x1038c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1038c4 b 0x103618 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x1038c8 .word 0x002ea9f4
 *   @0x1038cc eoreq r10, lr, r4, ror #19
 *   @0x1038d0 eoreq r4, r3, r4, ror #12
 *   @0x1038d4 eoreq r10, lr, r4, lsl #7
 *   @0x1038d8 eoreq r5, r3, r12, asr #1
 *
 * ══ §10/29 F_IAP_Activate(RValue&, CInstance*, CInstance*, int, RValue*)  0x154bd4  size 1176  294 条（0x154bd4..0x15506c）
 * @func 0x154bd4 0x15506c  size 1176  294 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x154c8c→0x484a58, 0x154ca0→0x484a5c, 0x154dac→0x484a5c, 0x154e2c→0x4836b0, 0x154e48→0x484a58, 0x154e7c→0x484a5c, 0x154fa0→0x484a5c, 0x155020→0x484a5c
 * 调用序列: MemoryManager::Free(void const*)×5 / YYGetInt32(RValue const*, int)×2 / F_IAP_Activate(RValue&, CInstance*, CInstance*, int, RValue*)+0x40×2 / operator new(unsigned int)×2 / CIAPProduct::SetFromMap(int)×2 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / F_IAP_Activate(RValue&, CInstance*, CInstance*, int, RValue*)+0x68 / anon_154a70
 * 字段偏移 top8: 0x4×14 / 0x8×12 / 0xc×10 / 0x10×8 / 0x2×6 / 0x4c×4 / 0x14×4 / 0x18×3
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x154bd4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x154bd8 vpush {d8}
 *   @0x154bdc cmp r3, #0
 *   @0x154be0 sub sp, sp, #100
 *   @0x154be4 ldr r4, [pc, #0x464]
 *   @0x154be8 mov r8, r0
 *   @0x154bec add r4, pc, r4
 *   @0x154bf0 str r1, [sp, #0xc]
 *   @0x154bf4 str r2, [sp, #0x10]
 *   @0x154bf8 ldr r12, [sp, #0x90]
 *   @0x154bfc ble 0x154c3c <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x154c00 ldr r9, [r12, #0xc]
 *   @0x154c04 cmp r9, #0
 *   @0x154c08 beq 0x154c48 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x154c0c cmp r9, #1
 *   @0x154c10 beq 0x154df8 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x154c14 ldr r1, [pc, #0x438]
 *   @0x154c18 mov r4, #0
 *   @0x154c1c mov r0, #1
 *   @0x154c20 str r4, [sp]
 *   @0x154c24 add r1, pc, r1
 *   @0x154c28 mov r2, #0
 *   @0x154c2c mov r3, #0
 *   @0x154c30 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88>
 *   @0x154c34 mov r1, r4
 *   @0x154c38 bl 0x153acc <_Z16InitIAPFunctionsv+0x5f8>
 *   @0x154c3c add sp, sp, #100
 *   @0x154c40 vpop {d8}
 *   @0x154c44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x154c48 mov r0, r12
 *   @0x154c4c mov r1, r9
 *   @0x154c50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x154c54 add r1, sp, #48
 *   @0x154c58 str r1, [sp, #0x8]
 *   @0x154c5c mov r3, #1
 *   @0x154c60 add r7, sp, #64
 *   @0x154c64 mov r1, r9
 *   @0x154c68 str r7, [sp]
 *   @0x154c6c mov r2, r9
 *   @0x154c70 str r9, [sp, #0x30]
 *   @0x154c74 str r9, [sp, #0x4c]
 *   @0x154c78 vmov s13, r0
 *   @0x154c7c ldr r0, [sp, #0x8]
 *   @0x154c80 vcvt.f64.s32 d7, s13
 *   @0x154c84 vstr d7, [sp, #64]
 *   @0x154c88 bl 0xfc350 <_Z12F_DsListSizeR6RValueP9CInstanceS2_iPS_>
 *   @0x154c8c ldr r3, [pc, #0x3c4]
 *   @0x154c90 ldr r6, [r4, r3]
 *   @0x154c94 ldr r3, [r6]
 *   @0x154c98 cmp r3, #0
 *   @0x154c9c ble 0x154d44 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x154ca0 ldr r3, [pc, #0x3b4]
 *   @0x154ca4 mov r10, r9
 *   @0x154ca8 ldr r5, [r4, r3]
 *   @0x154cac ldr r3, [r5, #0x4]
 *   @0x154cb0 lsl r11, r9, #2
 *   @0x154cb4 ldr r8, [r3, r9, lsl #2]
 *   @0x154cb8 cmp r8, #0
 *   @0x154cbc beq 0x154d34 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x154cc0 ldr r0, [r8]
 *   @0x154cc4 cmp r0, #0
 *   @0x154cc8 beq 0x154cd4 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x154ccc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x154cd0 str r10, [r8]
 *   @0x154cd4 ldr r0, [r8, #0x4]
 *   @0x154cd8 cmp r0, #0
 *   @0x154cdc beq 0x154ce8 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x154ce0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x154ce4 str r10, [r8, #0x4]
 *   @0x154ce8 ldr r0, [r8, #0x8]
 *   @0x154cec cmp r0, #0
 *   @0x154cf0 beq 0x154cfc <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x154cf4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x154cf8 str r10, [r8, #0x8]
 *   @0x154cfc ldr r0, [r8, #0xc]
 *   @0x154d00 cmp r0, #0
 *   @0x154d04 beq 0x154d10 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x154d08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x154d0c str r10, [r8, #0xc]
 *   @0x154d10 ldr r0, [r8, #0x10]
 *   @0x154d14 cmp r0, #0
 *   @0x154d18 beq 0x154d24 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x154d1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x154d20 str r10, [r8, #0x10]
 *   @0x154d24 mov r0, r8
 *   @0x154d28 bl 0x27d1d0 <_ZdlPv>
 *   @0x154d2c ldr r3, [r5, #0x4]
 *   @0x154d30 str r10, [r3, r11]
 *   @0x154d34 ldr r3, [r6]
 *   @0x154d38 add r9, r9, #1
 *   @0x154d3c cmp r9, r3
 *   @0x154d40 blt 0x154cac <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x154d44 vldr d7, [sp, #48]
 *   @0x154d48 vcvt.s32.f64 s13, d7
 *   @0x154d4c vmov r9, s13
 *   @0x154d50 cmp r9, r3
 *   @0x154d54 bgt 0x154fa0 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x3cc>
 *   @0x154d58 cmp r9, #0
 *   @0x154d5c ble 0x154c14 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x154d60 ldr r8, [sp, #0x8]
 *   @0x154d64 mov r5, #0
 *   @0x154d68 mov r6, r5
 *   @0x154d6c vmov s13, r5
 *   @0x154d70 mov r1, #0
 *   @0x154d74 mov r0, r8
 *   @0x154d78 str r7, [sp]
 *   @0x154d7c vcvt.f64.s32 d7, s13
 *   @0x154d80 mov r2, r1
 *   @0x154d84 mov r3, #2
 *   @0x154d88 str r6, [sp, #0x5c]
 *   @0x154d8c vstr d7, [sp, #80]
 *   @0x154d90 bl 0x106634 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_>
 *   @0x154d94 vldr d8, [sp, #48]
 *   @0x154d98 vcmpe.f64 d8, #0
 *   @0x154d9c mov r0, #24
 *   @0x154da0 vmrs APSR_nzcv, fpscr
 *   @0x154da4 blt 0x154de8 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x154da8 bl 0x27c524 <_Znwj>
 *   @0x154dac ldr r3, [pc, #0x2a8]
 *   @0x154db0 vcvt.s32.f64 s15, d8
 *   @0x154db4 vmov r1, s15
 *   @0x154db8 str r6, [r0]
 *   @0x154dbc str r6, [r0, #0x4]
 *   @0x154dc0 str r6, [r0, #0x8]
 *   @0x154dc4 str r6, [r0, #0xc]
 *   @0x154dc8 str r6, [r0, #0x10]
 *   @0x154dcc strb r6, [r0, #0x14]
 *   @0x154dd0 ldr r3, [r4, r3]
 *   @0x154dd4 ldr r2, [r3, #0x4]
 *   @0x154dd8 str r0, [r2, r5, lsl #2]
 *   @0x154ddc ldr r3, [r3, #0x4]
 *   @0x154de0 ldr r0, [r3, r5, lsl #2]
 *   @0x154de4 bl 0x18b5c4 <_ZN11CIAPProduct10SetFromMapEi>
 *   @0x154de8 add r5, r5, #1
 *   @0x154dec cmp r5, r9
 *   @0x154df0 bne 0x154d6c <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x154df4 b 0x154c14 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x154df8 str r12, [sp]
 *   @0x154dfc bl 0x13d348 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_>
 *   @0x154e00 ldm r8, {r0, r1}
 *   @0x154e04 bl 0xb66e8 <lrint@plt>
 *   @0x154e08 cmp r0, #0
 *   @0x154e0c str r0, [sp, #0x18]
 *   @0x154e10 blt 0x154c14 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x154e14 add r1, sp, #44
 *   @0x154e18 lsl r2, r0, #2
 *   @0x154e1c str r1, [sp, #0x20]
 *   @0x154e20 mov r0, r1
 *   @0x154e24 str r2, [sp, #0x14]
 *   @0x154e28 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x154e2c ldr r3, [pc, #0x22c]
 *   @0x154e30 ldr r1, [sp, #0x18]
 *   @0x154e34 ldr r3, [r4, r3]
 *   @0x154e38 str r3, [sp, #0x1c]
 *   @0x154e3c ldr r3, [r3, #0x4]
 *   @0x154e40 ldr r0, [r3, r1, lsl #2]
 *   @0x154e44 bl 0x2052c0 <_ZN7CDS_Map4SizeEv>
 *   @0x154e48 ldr r3, [pc, #0x208]
 *   @0x154e4c ldr r6, [r4, r3]
 *   @0x154e50 ldr r3, [r6]
 *   @0x154e54 cmp r0, r3
 *   @0x154e58 mov r7, r0
 *   @0x154e5c bgt 0x155020 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x44c>
 *   @0x154e60 ldr r2, [sp, #0x1c]
 *   @0x154e64 ldr r1, [sp, #0x18]
 *   @0x154e68 ldr r3, [r2, #0x4]
 *   @0x154e6c ldr r0, [r3, r1, lsl #2]
 *   @0x154e70 bl 0x203c8c <_ZN7CDS_Map9FindFirstEv>
 *   @0x154e74 subs r10, r0, #0
 *   @0x154e78 beq 0x155048 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x474>
 *   @0x154e7c ldr r3, [pc, #0x1d8]
 *   @0x154e80 add r1, sp, #48
 *   @0x154e84 str r1, [sp, #0x8]
 *   @0x154e88 add r7, sp, #64
 *   @0x154e8c mov r9, #0
 *   @0x154e90 mov r11, r1
 *   @0x154e94 ldr r5, [r4, r3]
 *   @0x154e98 str r8, [sp, #0x24]
 *   @0x154e9c str r5, [sp, #0x8]
 *   @0x154ea0 ldr r5, [sp, #0x1c]
 *   @0x154ea4 b 0x154f24 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x350>
 *   @0x154ea8 ldr r0, [r4]
 *   @0x154eac cmp r0, #0
 *   @0x154eb0 beq 0x154eb8 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x2e4>
 *   @0x154eb4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x154eb8 mov r0, r8
 *   @0x154ebc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x154ec0 mov r12, r10
 *   @0x154ec4 mov lr, r7
 *   @0x154ec8 str r0, [r4]
 *   @0x154ecc ldr r0, [r12, #0x10]!
 *   @0x154ed0 ldr r1, [r12, #0x4]
 *   @0x154ed4 ldr r3, [r12, #0xc]
 *   @0x154ed8 ldr r2, [r12, #0x8]
 *   @0x154edc stm lr!, {r0, r1, r2, r3}
 *   @0x154ee0 mov r1, #0
 *   @0x154ee4 ldr r3, [sp, #0x4c]
 *   @0x154ee8 mov r0, r7
 *   @0x154eec bic r3, r3, #-16777216
 *   @0x154ef0 str r3, [sp, #0x4c]
 *   @0x154ef4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x154ef8 subs r1, r0, #0
 *   @0x154efc mov r0, r4
 *   @0x154f00 blt 0x154f08 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x334>
 *   @0x154f04 bl 0x18b5c4 <_ZN11CIAPProduct10SetFromMapEi>
 *   @0x154f08 ldr r3, [r5, #0x4]
 *   @0x154f0c mov r1, r11
 *   @0x154f10 ldr r2, [sp, #0x14]
 *   @0x154f14 ldr r0, [r3, r2]
 *   @0x154f18 bl 0x203b94 <_ZN7CDS_Map8FindNextEP6RValue>
 *   @0x154f1c subs r10, r0, #0
 *   @0x154f20 beq 0x154fcc <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x3f8>
 *   @0x154f24 mov r0, #24
 *   @0x154f28 mov r8, #0
 *   @0x154f2c bl 0x27c524 <_Znwj>
 *   @0x154f30 ldr r1, [sp, #0x8]
 *   @0x154f34 ldr r3, [r6]
 *   @0x154f38 mov lr, r11
 *   @0x154f3c ldr r2, [r1, #0x4]
 *   @0x154f40 add r1, r3, #1
 *   @0x154f44 str r9, [r0]
 *   @0x154f48 mov r4, r0
 *   @0x154f4c str r9, [r0, #0x4]
 *   @0x154f50 str r9, [r0, #0x8]
 *   @0x154f54 str r9, [r0, #0xc]
 *   @0x154f58 str r9, [r0, #0x10]
 *   @0x154f5c strb r9, [r0, #0x14]
 *   @0x154f60 str r1, [r6]
 *   @0x154f64 str r0, [r2, r3, lsl #2]
 *   @0x154f68 ldr r3, [r10, #0xc]
 *   @0x154f6c ldr r0, [r10]
 *   @0x154f70 ldr r1, [r10, #0x4]
 *   @0x154f74 ldr r2, [r10, #0x8]
 *   @0x154f78 stm lr!, {r0, r1, r2, r3}
 *   @0x154f7c ldr r3, [sp, #0x3c]
 *   @0x154f80 bic r3, r3, #-16777216
 *   @0x154f84 str r3, [sp, #0x3c]
 *   @0x154f88 cmp r3, #1
 *   @0x154f8c bne 0x154ea8 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x2d4>
 *   @0x154f90 ldr r8, [sp, #0x30]
 *   @0x154f94 cmp r8, #0
 *   @0x154f98 ldrne r8, [r8]
 *   @0x154f9c b 0x154ea8 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x2d4>
 *   @0x154fa0 ldr r0, [pc, #0xb4]
 *   @0x154fa4 lsl r1, r9, #2
 *   @0x154fa8 ldr r2, [pc, #0xb4]
 *   @0x154fac mov r3, #255
 *   @0x154fb0 ldr r5, [r4, r0]
 *   @0x154fb4 add r2, pc, r2
 *   @0x154fb8 add r0, r5, #4
 *   @0x154fbc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x154fc0 str r9, [r5]
 *   @0x154fc4 str r9, [r6]
 *   @0x154fc8 b 0x154d58 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x154fcc ldr r8, [sp, #0x24]
 *   @0x154fd0 vldr s13, [sp, #24]
 *   @0x154fd4 vcvt.f64.s32 d7, s13
 *   @0x154fd8 mov r0, r8
 *   @0x154fdc ldr r1, [sp, #0xc]
 *   @0x154fe0 ldr r2, [sp, #0x10]
 *   @0x154fe4 mov r3, #1
 *   @0x154fe8 str r7, [sp]
 *   @0x154fec mov r12, #0
 *   @0x154ff0 str r12, [sp, #0x4c]
 *   @0x154ff4 vstr d7, [sp, #64]
 *   @0x154ff8 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_>
 *   @0x154ffc mov r0, r8
 *   @0x155000 str r7, [sp]
 *   @0x155004 ldr r1, [sp, #0xc]
 *   @0x155008 mov r3, #1
 *   @0x15500c ldr r2, [sp, #0x10]
 *   @0x155010 bl 0xfec90 <_Z14F_DsMapDestroyR6RValueP9CInstanceS2_iPS_>
 *   @0x155014 add r0, sp, #44
 *   @0x155018 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x15501c b 0x154c14 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x155020 ldr r0, [pc, #0x34]
 *   @0x155024 lsl r1, r7, #2
 *   @0x155028 ldr r2, [pc, #0x38]
 *   @0x15502c movw r3, #0x126
 *   @0x155030 ldr r5, [r4, r0]
 *   @0x155034 add r2, pc, r2
 *   @0x155038 add r0, r5, #4
 *   @0x15503c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x155040 str r7, [r5]
 *   @0x155044 b 0x154e60 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x28c>
 *   @0x155048 add r7, sp, #64
 *   @0x15504c b 0x154fd0 <_Z14F_IAP_ActivateR6RValueP9CInstanceS2_iPS_+0x3fc>
 *   @0x155050 eoreq sp, r9, r4, rrx
 *   @0x155054 andseq r1, pc, r4, lsl #10
 *   @0x155058 .word 0xffffde80
 *   @0x15505c .word 0xffffde84
 *   @0x155060 .word 0xffffbcec
 *   @0x155064 ldrsheq r0, [pc], -r8
 *   @0x155068 andseq r0, pc, r8, ror pc
 *
 * ══ §11/29 RVariable::RVariable(RValue const*, RValue const*)  0x1f5dc8  size 1172  293 条（0x1f5dc8..0x1f625c）
 * @func 0x1f5dc8 0x1f625c  size 1172  293 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×8 / UNLOCK_RVALUE_MUTEX()×8 / YYFree(void const*)×8 / operator delete(void*)×8 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / FREE_RValue__Pre(RValue*)×2 / _RefThing<char const*>::dec()×2
 * 字段偏移 top8: 0x8×19 / 0x4×17 / 0x18×7 / 0xc×5 / 0x14×3 / 0x24×3 / 0x10×2 / 0x20×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f5dc8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1f5dcc mov r4, r0
 *   @0x1f5dd0 mov r3, #0
 *   @0x1f5dd4 mov r0, r1
 *   @0x1f5dd8 str r3, [r4]
 *   @0x1f5ddc mov r6, r2
 *   @0x1f5de0 str r3, [r4, #0x4]
 *   @0x1f5de4 mov r5, r1
 *   @0x1f5de8 bl 0xcee94 <_Z11HASH_RValuePK6RValue>
 *   @0x1f5dec ldr r2, [r4, #0x14]
 *   @0x1f5df0 add r8, r4, #8
 *   @0x1f5df4 bic r3, r2, #-16777216
 *   @0x1f5df8 cmp r3, #1
 *   @0x1f5dfc str r0, [r4, #0x28]
 *   @0x1f5e00 beq 0x1f5f7c <_ZN9RVariableC2EPK6RValueS2_+0x1b4>
 *   @0x1f5e04 cmp r3, #2
 *   @0x1f5e08 bne 0x1f5e30 <_ZN9RVariableC2EPK6RValueS2_+0x68>
 *   @0x1f5e0c sub r2, r2, #1
 *   @0x1f5e10 bic r2, r2, #-16777216
 *   @0x1f5e14 bic r2, r2, #3
 *   @0x1f5e18 cmp r2, #0
 *   @0x1f5e1c beq 0x1f6124 <_ZN9RVariableC2EPK6RValueS2_+0x35c>
 *   @0x1f5e20 mov r2, #0
 *   @0x1f5e24 mov r3, #5
 *   @0x1f5e28 str r2, [r4, #0x10]
 *   @0x1f5e2c str r3, [r4, #0x14]
 *   @0x1f5e30 ldr r3, [r5, #0xc]
 *   @0x1f5e34 mov r1, #0
 *   @0x1f5e38 ldr r2, [r5, #0x8]
 *   @0x1f5e3c str r1, [r4, #0x8]
 *   @0x1f5e40 str r3, [r4, #0x14]
 *   @0x1f5e44 ldr r3, [r5, #0xc]
 *   @0x1f5e48 str r2, [r4, #0x10]
 *   @0x1f5e4c bic r3, r3, #-16777216
 *   @0x1f5e50 cmp r3, #14
 *   @0x1f5e54 addls pc, pc, r3, lsl #2
 *   @0x1f5e58 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8>
 *   @0x1f5e5c b 0x1f5f58 <_ZN9RVariableC2EPK6RValueS2_+0x190>
 *   @0x1f5e60 b 0x1f6008 <_ZN9RVariableC2EPK6RValueS2_+0x240>
 *   @0x1f5e64 b 0x1f6020 <_ZN9RVariableC2EPK6RValueS2_+0x258>
 *   @0x1f5e68 b 0x1f5e98 <_ZN9RVariableC2EPK6RValueS2_+0xd0>
 *   @0x1f5e6c b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8>
 *   @0x1f5e70 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8>
 *   @0x1f5e74 b 0x1f5fe4 <_ZN9RVariableC2EPK6RValueS2_+0x21c>
 *   @0x1f5e78 b 0x1f5e98 <_ZN9RVariableC2EPK6RValueS2_+0xd0>
 *   @0x1f5e7c b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8>
 *   @0x1f5e80 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8>
 *   @0x1f5e84 b 0x1f5f58 <_ZN9RVariableC2EPK6RValueS2_+0x190>
 *   @0x1f5e88 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8>
 *   @0x1f5e8c b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8>
 *   @0x1f5e90 b 0x1f5f58 <_ZN9RVariableC2EPK6RValueS2_+0x190>
 *   @0x1f5e94 b 0x1f5e98 <_ZN9RVariableC2EPK6RValueS2_+0xd0>
 *   @0x1f5e98 ldr r3, [r5]
 *   @0x1f5e9c str r3, [r4, #0x8]
 *   @0x1f5ea0 ldr r2, [r4, #0x24]
 *   @0x1f5ea4 add r7, r4, #24
 *   @0x1f5ea8 bic r3, r2, #-16777216
 *   @0x1f5eac cmp r3, #1
 *   @0x1f5eb0 beq 0x1f5fb0 <_ZN9RVariableC2EPK6RValueS2_+0x1e8>
 *   @0x1f5eb4 cmp r3, #2
 *   @0x1f5eb8 bne 0x1f5ee0 <_ZN9RVariableC2EPK6RValueS2_+0x118>
 *   @0x1f5ebc sub r2, r2, #1
 *   @0x1f5ec0 bic r2, r2, #-16777216
 *   @0x1f5ec4 bic r2, r2, #3
 *   @0x1f5ec8 cmp r2, #0
 *   @0x1f5ecc beq 0x1f6130 <_ZN9RVariableC2EPK6RValueS2_+0x368>
 *   @0x1f5ed0 mov r2, #0
 *   @0x1f5ed4 mov r3, #5
 *   @0x1f5ed8 str r2, [r4, #0x20]
 *   @0x1f5edc str r3, [r4, #0x24]
 *   @0x1f5ee0 ldr r3, [r6, #0xc]
 *   @0x1f5ee4 mov r1, #0
 *   @0x1f5ee8 ldr r2, [r6, #0x8]
 *   @0x1f5eec str r1, [r4, #0x18]
 *   @0x1f5ef0 str r3, [r4, #0x24]
 *   @0x1f5ef4 ldr r3, [r6, #0xc]
 *   @0x1f5ef8 str r2, [r4, #0x20]
 *   @0x1f5efc bic r3, r3, #-16777216
 *   @0x1f5f00 cmp r3, #14
 *   @0x1f5f04 addls pc, pc, r3, lsl #2
 *   @0x1f5f08 b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188>
 *   @0x1f5f0c b 0x1f5f68 <_ZN9RVariableC2EPK6RValueS2_+0x1a0>
 *   @0x1f5f10 b 0x1f604c <_ZN9RVariableC2EPK6RValueS2_+0x284>
 *   @0x1f5f14 b 0x1f6088 <_ZN9RVariableC2EPK6RValueS2_+0x2c0>
 *   @0x1f5f18 b 0x1f5f48 <_ZN9RVariableC2EPK6RValueS2_+0x180>
 *   @0x1f5f1c b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188>
 *   @0x1f5f20 b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188>
 *   @0x1f5f24 b 0x1f6064 <_ZN9RVariableC2EPK6RValueS2_+0x29c>
 *   @0x1f5f28 b 0x1f5f48 <_ZN9RVariableC2EPK6RValueS2_+0x180>
 *   @0x1f5f2c b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188>
 *   @0x1f5f30 b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188>
 *   @0x1f5f34 b 0x1f5f68 <_ZN9RVariableC2EPK6RValueS2_+0x1a0>
 *   @0x1f5f38 b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188>
 *   @0x1f5f3c b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188>
 *   @0x1f5f40 b 0x1f5f68 <_ZN9RVariableC2EPK6RValueS2_+0x1a0>
 *   @0x1f5f44 b 0x1f5f48 <_ZN9RVariableC2EPK6RValueS2_+0x180>
 *   @0x1f5f48 ldr r3, [r6]
 *   @0x1f5f4c str r3, [r4, #0x18]
 *   @0x1f5f50 mov r0, r4
 *   @0x1f5f54 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1f5f58 ldm r5, {r2, r3}
 *   @0x1f5f5c str r2, [r4, #0x8]
 *   @0x1f5f60 str r3, [r4, #0xc]
 *   @0x1f5f64 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8>
 *   @0x1f5f68 ldm r6, {r2, r3}
 *   @0x1f5f6c mov r0, r4
 *   @0x1f5f70 str r2, [r4, #0x18]
 *   @0x1f5f74 str r3, [r4, #0x1c]
 *   @0x1f5f78 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1f5f7c ldr r7, [r4, #0x8]
 *   @0x1f5f80 cmp r7, #0
 *   @0x1f5f84 beq 0x1f5fa4 <_ZN9RVariableC2EPK6RValueS2_+0x1dc>
 *   @0x1f5f88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f5f8c ldr r9, [r7, #0x4]
 *   @0x1f5f90 sub r9, r9, #1
 *   @0x1f5f94 str r9, [r7, #0x4]
 *   @0x1f5f98 cmp r9, #0
 *   @0x1f5f9c beq 0x1f60b4 <_ZN9RVariableC2EPK6RValueS2_+0x2ec>
 *   @0x1f5fa0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f5fa4 mov r3, #0
 *   @0x1f5fa8 str r3, [r4, #0x8]
 *   @0x1f5fac b 0x1f5e30 <_ZN9RVariableC2EPK6RValueS2_+0x68>
 *   @0x1f5fb0 ldr r5, [r4, #0x18]
 *   @0x1f5fb4 cmp r5, #0
 *   @0x1f5fb8 beq 0x1f5fd8 <_ZN9RVariableC2EPK6RValueS2_+0x210>
 *   @0x1f5fbc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f5fc0 ldr r8, [r5, #0x4]
 *   @0x1f5fc4 sub r8, r8, #1
 *   @0x1f5fc8 str r8, [r5, #0x4]
 *   @0x1f5fcc cmp r8, #0
 *   @0x1f5fd0 beq 0x1f60ec <_ZN9RVariableC2EPK6RValueS2_+0x324>
 *   @0x1f5fd4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f5fd8 mov r3, #0
 *   @0x1f5fdc str r3, [r4, #0x18]
 *   @0x1f5fe0 b 0x1f5ee0 <_ZN9RVariableC2EPK6RValueS2_+0x118>
 *   @0x1f5fe4 ldr r3, [r5]
 *   @0x1f5fe8 str r3, [r4, #0x8]
 *   @0x1f5fec ldr r3, [r5]
 *   @0x1f5ff0 cmp r3, #0
 *   @0x1f5ff4 beq 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8>
 *   @0x1f5ff8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1f5ffc ldr r1, [r5]
 *   @0x1f6000 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1f6004 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8>
 *   @0x1f6008 ldr r3, [r5]
 *   @0x1f600c cmp r3, #0
 *   @0x1f6010 ldrne r2, [r3, #0x4]
 *   @0x1f6014 addne r2, r2, #1
 *   @0x1f6018 strne r2, [r3, #0x4]
 *   @0x1f601c b 0x1f5e9c <_ZN9RVariableC2EPK6RValueS2_+0xd4>
 *   @0x1f6020 ldr r3, [r5]
 *   @0x1f6024 cmp r3, #0
 *   @0x1f6028 str r3, [r4, #0x8]
 *   @0x1f602c beq 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8>
 *   @0x1f6030 ldr r1, [r3, #0x8]
 *   @0x1f6034 ldr r2, [r3]
 *   @0x1f6038 cmp r1, #0
 *   @0x1f603c streq r8, [r3, #0x8]
 *   @0x1f6040 add r2, r2, #1
 *   @0x1f6044 str r2, [r3]
 *   @0x1f6048 b 0x1f5ea0 <_ZN9RVariableC2EPK6RValueS2_+0xd8>
 *   @0x1f604c ldr r3, [r6]
 *   @0x1f6050 cmp r3, #0
 *   @0x1f6054 ldrne r2, [r3, #0x4]
 *   @0x1f6058 addne r2, r2, #1
 *   @0x1f605c strne r2, [r3, #0x4]
 *   @0x1f6060 b 0x1f5f4c <_ZN9RVariableC2EPK6RValueS2_+0x184>
 *   @0x1f6064 ldr r3, [r6]
 *   @0x1f6068 str r3, [r4, #0x18]
 *   @0x1f606c ldr r3, [r6]
 *   @0x1f6070 cmp r3, #0
 *   @0x1f6074 beq 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188>
 *   @0x1f6078 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1f607c ldr r1, [r6]
 *   @0x1f6080 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1f6084 b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188>
 *   @0x1f6088 ldr r3, [r6]
 *   @0x1f608c cmp r3, #0
 *   @0x1f6090 str r3, [r4, #0x18]
 *   @0x1f6094 beq 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188>
 *   @0x1f6098 ldr r1, [r3, #0x8]
 *   @0x1f609c ldr r2, [r3]
 *   @0x1f60a0 cmp r1, #0
 *   @0x1f60a4 streq r7, [r3, #0x8]
 *   @0x1f60a8 add r2, r2, #1
 *   @0x1f60ac str r2, [r3]
 *   @0x1f60b0 b 0x1f5f50 <_ZN9RVariableC2EPK6RValueS2_+0x188>
 *   @0x1f60b4 ldr r0, [r7]
 *   @0x1f60b8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f60bc str r9, [r7]
 *   @0x1f60c0 str r9, [r7, #0x8]
 *   @0x1f60c4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f60c8 ldr r9, [r7, #0x4]
 *   @0x1f60cc sub r9, r9, #1
 *   @0x1f60d0 str r9, [r7, #0x4]
 *   @0x1f60d4 cmp r9, #0
 *   @0x1f60d8 beq 0x1f613c <_ZN9RVariableC2EPK6RValueS2_+0x374>
 *   @0x1f60dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f60e0 mov r0, r7
 *   @0x1f60e4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f60e8 b 0x1f5fa0 <_ZN9RVariableC2EPK6RValueS2_+0x1d8>
 *   @0x1f60ec ldr r0, [r5]
 *   @0x1f60f0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f60f4 str r8, [r5]
 *   @0x1f60f8 str r8, [r5, #0x8]
 *   @0x1f60fc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6100 ldr r8, [r5, #0x4]
 *   @0x1f6104 sub r8, r8, #1
 *   @0x1f6108 str r8, [r5, #0x4]
 *   @0x1f610c cmp r8, #0
 *   @0x1f6110 beq 0x1f6174 <_ZN9RVariableC2EPK6RValueS2_+0x3ac>
 *   @0x1f6114 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6118 mov r0, r5
 *   @0x1f611c bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6120 b 0x1f5fd4 <_ZN9RVariableC2EPK6RValueS2_+0x20c>
 *   @0x1f6124 mov r0, r8
 *   @0x1f6128 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f612c b 0x1f5e20 <_ZN9RVariableC2EPK6RValueS2_+0x58>
 *   @0x1f6130 mov r0, r7
 *   @0x1f6134 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f6138 b 0x1f5ed0 <_ZN9RVariableC2EPK6RValueS2_+0x108>
 *   @0x1f613c ldr r0, [r7]
 *   @0x1f6140 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f6144 str r9, [r7]
 *   @0x1f6148 str r9, [r7, #0x8]
 *   @0x1f614c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6150 ldr r9, [r7, #0x4]
 *   @0x1f6154 sub r9, r9, #1
 *   @0x1f6158 str r9, [r7, #0x4]
 *   @0x1f615c cmp r9, #0
 *   @0x1f6160 beq 0x1f61ac <_ZN9RVariableC2EPK6RValueS2_+0x3e4>
 *   @0x1f6164 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6168 mov r0, r7
 *   @0x1f616c bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6170 b 0x1f60dc <_ZN9RVariableC2EPK6RValueS2_+0x314>
 *   @0x1f6174 ldr r0, [r5]
 *   @0x1f6178 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f617c str r8, [r5]
 *   @0x1f6180 str r8, [r5, #0x8]
 *   @0x1f6184 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6188 ldr r8, [r5, #0x4]
 *   @0x1f618c sub r8, r8, #1
 *   @0x1f6190 str r8, [r5, #0x4]
 *   @0x1f6194 cmp r8, #0
 *   @0x1f6198 beq 0x1f6204 <_ZN9RVariableC2EPK6RValueS2_+0x43c>
 *   @0x1f619c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f61a0 mov r0, r5
 *   @0x1f61a4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f61a8 b 0x1f6114 <_ZN9RVariableC2EPK6RValueS2_+0x34c>
 *   @0x1f61ac ldr r0, [r7]
 *   @0x1f61b0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f61b4 str r9, [r7]
 *   @0x1f61b8 str r9, [r7, #0x8]
 *   @0x1f61bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f61c0 ldr r9, [r7, #0x4]
 *   @0x1f61c4 sub r9, r9, #1
 *   @0x1f61c8 str r9, [r7, #0x4]
 *   @0x1f61cc cmp r9, #0
 *   @0x1f61d0 bne 0x1f61f4 <_ZN9RVariableC2EPK6RValueS2_+0x42c>
 *   @0x1f61d4 ldr r0, [r7]
 *   @0x1f61d8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f61dc mov r0, r7
 *   @0x1f61e0 str r9, [r7]
 *   @0x1f61e4 str r9, [r7, #0x8]
 *   @0x1f61e8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1f61ec mov r0, r7
 *   @0x1f61f0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f61f4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f61f8 mov r0, r7
 *   @0x1f61fc bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6200 b 0x1f6164 <_ZN9RVariableC2EPK6RValueS2_+0x39c>
 *   @0x1f6204 ldr r0, [r5]
 *   @0x1f6208 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f620c str r8, [r5]
 *   @0x1f6210 str r8, [r5, #0x8]
 *   @0x1f6214 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f6218 ldr r8, [r5, #0x4]
 *   @0x1f621c sub r8, r8, #1
 *   @0x1f6220 str r8, [r5, #0x4]
 *   @0x1f6224 cmp r8, #0
 *   @0x1f6228 bne 0x1f624c <_ZN9RVariableC2EPK6RValueS2_+0x484>
 *   @0x1f622c ldr r0, [r5]
 *   @0x1f6230 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f6234 mov r0, r5
 *   @0x1f6238 str r8, [r5]
 *   @0x1f623c str r8, [r5, #0x8]
 *   @0x1f6240 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1f6244 mov r0, r5
 *   @0x1f6248 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f624c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f6250 mov r0, r5
 *   @0x1f6254 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f6258 b 0x1f619c <_ZN9RVariableC2EPK6RValueS2_+0x3d4>
 *
 * ══ §12/29 jpeg_idct_4x4  0x2c0b24  size 1168  292 条（0x2c0b24..0x2c0fb4）
 * @func 0x2c0b24 0x2c0fb4  size 1168  292 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×15 / 0x18×11 / 0x1c×11 / 0x14×8 / 0x4×7 / 0xc×7 / 0x60×6 / 0x10×5
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c0b24 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2c0b28 sub sp, sp, #176
 *   @0x2c0b2c ldr r1, [r1, #0x50]
 *   @0x2c0b30 add r4, sp, #48
 *   @0x2c0b34 ldr r0, [r0, #0x120]
 *   @0x2c0b38 movw r5, #0xe782
 *   @0x2c0b3c str r4, [sp, #0x28]
 *   @0x2c0b40 movw r7, #0xf93e
 *   @0x2c0b44 add r0, r0, #128
 *   @0x2c0b48 str r3, [sp, #0x24]
 *   @0x2c0b4c add r4, r2, #2
 *   @0x2c0b50 str r0, [sp, #0x2c]
 *   @0x2c0b54 mov r3, r2
 *   @0x2c0b58 movt r5, #0xffff
 *   @0x2c0b5c movt r7, #0xffff
 *   @0x2c0b60 movw r8, #0xba79
 *   @0x2c0b64 movw r9, #0xefb0
 *   @0x2c0b68 movt r8, #0xffff
 *   @0x2c0b6c movt r9, #0xffff
 *   @0x2c0b70 movw r11, #0xecc2
 *   @0x2c0b74 add r12, r1, #4
 *   @0x2c0b78 movt r11, #0xffff
 *   @0x2c0b7c add r0, sp, #48
 *   @0x2c0b80 str r5, [sp, #0x10]
 *   @0x2c0b84 str r7, [sp, #0x14]
 *   @0x2c0b88 mov r2, #7
 *   @0x2c0b8c str r8, [sp, #0x18]
 *   @0x2c0b90 str r9, [sp, #0x1c]
 *   @0x2c0b94 str r11, [sp, #0x20]
 *   @0x2c0b98 b 0x2c0cf0 <jpeg_idct_4x4+0x1cc>
 *   @0x2c0b9c cmp r7, #0
 *   @0x2c0ba0 bne 0x2c0d08 <jpeg_idct_4x4+0x1e4>
 *   @0x2c0ba4 ldrh r6, [r3, #48]
 *   @0x2c0ba8 cmp r6, #0
 *   @0x2c0bac beq 0x2c0ec8 <jpeg_idct_4x4+0x3a4>
 *   @0x2c0bb0 ldrh r8, [r3, #96]
 *   @0x2c0bb4 mov r7, r5
 *   @0x2c0bb8 ldrh r9, [r3, #112]
 *   @0x2c0bbc ldrh r10, [r3, #80]
 *   @0x2c0bc0 sxth r8, r8
 *   @0x2c0bc4 str r8, [sp, #0x4]
 *   @0x2c0bc8 ldr r8, [r1, #0xa0]
 *   @0x2c0bcc sxth r10, r10
 *   @0x2c0bd0 ldr r11, [r1, #0xe0]
 *   @0x2c0bd4 sxth r9, r9
 *   @0x2c0bd8 sxth r6, r6
 *   @0x2c0bdc sxth r5, r5
 *   @0x2c0be0 mul r10, r8, r10
 *   @0x2c0be4 ldr r8, [r1, #0x60]
 *   @0x2c0be8 mul r9, r11, r9
 *   @0x2c0bec str r5, [sp, #0x8]
 *   @0x2c0bf0 mul r6, r8, r6
 *   @0x2c0bf4 ldr r8, [sp, #0x20]
 *   @0x2c0bf8 movw r5, #0x2e75
 *   @0x2c0bfc sxth r7, r7
 *   @0x2c0c00 mul r11, r5, r10
 *   @0x2c0c04 ldr r5, [sp, #0x14]
 *   @0x2c0c08 mul r10, r8, r10
 *   @0x2c0c0c ldr r8, [sp, #0x1c]
 *   @0x2c0c10 mla r11, r5, r9, r11
 *   @0x2c0c14 ldr r5, [sp, #0x4]
 *   @0x2c0c18 mla r10, r8, r9, r10
 *   @0x2c0c1c ldr r9, [r1, #0xc0]
 *   @0x2c0c20 mul r8, r9, r5
 *   @0x2c0c24 ldr r9, [r1, #0x40]
 *   @0x2c0c28 ldr r5, [r1, #0x20]
 *   @0x2c0c2c mul r7, r9, r7
 *   @0x2c0c30 ldrsh r9, [r4, #-2]
 *   @0x2c0c34 str r7, [sp, #0xc]
 *   @0x2c0c38 ldr r7, [sp, #0x8]
 *   @0x2c0c3c mul r5, r5, r7
 *   @0x2c0c40 ldr r7, [r12, #-0x4]
 *   @0x2c0c44 mul r9, r7, r9
 *   @0x2c0c48 ldr r7, [sp, #0x10]
 *   @0x2c0c4c str r5, [sp, #0x4]
 *   @0x2c0c50 ldr r5, [sp, #0x18]
 *   @0x2c0c54 mul r8, r7, r8
 *   @0x2c0c58 movw r7, #0x3b21
 *   @0x2c0c5c mla r11, r5, r6, r11
 *   @0x2c0c60 movw r5, #0x1ccd
 *   @0x2c0c64 mla r6, r5, r6, r10
 *   @0x2c0c68 ldr r5, [sp, #0xc]
 *   @0x2c0c6c lsl r9, r9, #14
 *   @0x2c0c70 mla r8, r7, r5, r8
 *   @0x2c0c74 ldr r5, [sp, #0x4]
 *   @0x2c0c78 movw r7, #0x21f9
 *   @0x2c0c7c mla r11, r7, r5, r11
 *   @0x2c0c80 movw r7, #0x5203
 *   @0x2c0c84 mla r6, r7, r5, r6
 *   @0x2c0c88 add r5, r9, r8
 *   @0x2c0c8c rsb r8, r8, r9
 *   @0x2c0c90 add r7, r8, r11
 *   @0x2c0c94 rsb r11, r11, r8
 *   @0x2c0c98 add r8, r5, r6
 *   @0x2c0c9c rsb r6, r6, r5
 *   @0x2c0ca0 add r8, r8, #2048
 *   @0x2c0ca4 add r6, r6, #2048
 *   @0x2c0ca8 add r7, r7, #2048
 *   @0x2c0cac add r11, r11, #2048
 *   @0x2c0cb0 asr r8, r8, #12
 *   @0x2c0cb4 asr r6, r6, #12
 *   @0x2c0cb8 asr r7, r7, #12
 *   @0x2c0cbc asr r11, r11, #12
 *   @0x2c0cc0 str r8, [r0]
 *   @0x2c0cc4 str r6, [r0, #0x60]
 *   @0x2c0cc8 str r7, [r0, #0x20]
 *   @0x2c0ccc str r11, [r0, #0x40]
 *   @0x2c0cd0 cmp r2, #0
 *   @0x2c0cd4 add r0, r0, #4
 *   @0x2c0cd8 beq 0x2c0d24 <jpeg_idct_4x4+0x200>
 *   @0x2c0cdc add r4, r4, #2
 *   @0x2c0ce0 add r3, r3, #2
 *   @0x2c0ce4 add r12, r12, #4
 *   @0x2c0ce8 add r1, r1, #4
 *   @0x2c0cec sub r2, r2, #1
 *   @0x2c0cf0 cmp r2, #3
 *   @0x2c0cf4 beq 0x2c0d1c <jpeg_idct_4x4+0x1f8>
 *   @0x2c0cf8 ldrh r5, [r3, #16]
 *   @0x2c0cfc ldrh r7, [r3, #32]
 *   @0x2c0d00 cmp r5, #0
 *   @0x2c0d04 beq 0x2c0b9c <jpeg_idct_4x4+0x78>
 *   @0x2c0d08 ldrh r8, [r3, #96]
 *   @0x2c0d0c ldrh r9, [r3, #112]
 *   @0x2c0d10 ldrh r10, [r3, #80]
 *   @0x2c0d14 ldrh r6, [r3, #48]
 *   @0x2c0d18 b 0x2c0bc0 <jpeg_idct_4x4+0x9c>
 *   @0x2c0d1c add r0, r0, #4
 *   @0x2c0d20 b 0x2c0cdc <jpeg_idct_4x4+0x1b8>
 *   @0x2c0d24 movw r10, #0xf93e
 *   @0x2c0d28 movw r12, #0xecc2
 *   @0x2c0d2c movt r10, #0xffff
 *   @0x2c0d30 movt r12, #0xffff
 *   @0x2c0d34 str r10, [sp, #0x14]
 *   @0x2c0d38 add r3, sp, #48
 *   @0x2c0d3c str r12, [sp, #0xc]
 *   @0x2c0d40 movw r11, #0xe782
 *   @0x2c0d44 ldr r12, [sp, #0x2c]
 *   @0x2c0d48 movt r11, #0xffff
 *   @0x2c0d4c ldr r10, [sp, #0xd0]
 *   @0x2c0d50 movw r8, #0xba79
 *   @0x2c0d54 movw r9, #0xefb0
 *   @0x2c0d58 movt r8, #0xffff
 *   @0x2c0d5c movt r9, #0xffff
 *   @0x2c0d60 str r8, [sp, #0x4]
 *   @0x2c0d64 str r9, [sp, #0x8]
 *   @0x2c0d68 str r11, [sp, #0x10]
 *   @0x2c0d6c ldr r1, [sp, #0x24]
 *   @0x2c0d70 ldr r0, [r3, #0x4]
 *   @0x2c0d74 ldr r8, [r3, #0x8]
 *   @0x2c0d78 ldr r6, [r1, r2]
 *   @0x2c0d7c cmp r0, #0
 *   @0x2c0d80 add r1, r6, r10
 *   @0x2c0d84 bne 0x2c0e90 <jpeg_idct_4x4+0x36c>
 *   @0x2c0d88 cmp r8, #0
 *   @0x2c0d8c beq 0x2c0ea8 <jpeg_idct_4x4+0x384>
 *   @0x2c0d90 ldr r4, [r3, #0x18]
 *   @0x2c0d94 ldr r7, [r3, #0x1c]
 *   @0x2c0d98 ldr r5, [r3, #0x14]
 *   @0x2c0d9c str r4, [sp, #0x20]
 *   @0x2c0da0 ldr r4, [r3, #0xc]
 *   @0x2c0da4 ldr r11, [sp, #0xc]
 *   @0x2c0da8 ldr r9, [sp, #0x8]
 *   @0x2c0dac mul r11, r11, r5
 *   @0x2c0db0 mla r9, r9, r7, r11
 *   @0x2c0db4 movw r11, #0x2e75
 *   @0x2c0db8 mul r5, r11, r5
 *   @0x2c0dbc movw r11, #0x1ccd
 *   @0x2c0dc0 str r9, [sp, #0x1c]
 *   @0x2c0dc4 ldr r9, [sp, #0x14]
 *   @0x2c0dc8 mla r5, r9, r7, r5
 *   @0x2c0dcc ldr r7, [sp, #0x1c]
 *   @0x2c0dd0 mla r11, r11, r4, r7
 *   @0x2c0dd4 ldr r7, [sp, #0x10]
 *   @0x2c0dd8 str r5, [sp, #0x18]
 *   @0x2c0ddc ldr r5, [r3], #32
 *   @0x2c0de0 str r11, [sp, #0x1c]
 *   @0x2c0de4 lsl r5, r5, #14
 *   @0x2c0de8 ldr r11, [sp, #0x20]
 *   @0x2c0dec mul r9, r7, r11
 *   @0x2c0df0 movw r7, #0x3b21
 *   @0x2c0df4 mla r9, r7, r8, r9
 *   @0x2c0df8 ldr r7, [sp, #0x1c]
 *   @0x2c0dfc movw r8, #0x5203
 *   @0x2c0e00 mla r11, r8, r0, r7
 *   @0x2c0e04 ldr r7, [sp, #0x18]
 *   @0x2c0e08 ldr r8, [sp, #0x4]
 *   @0x2c0e0c mla r4, r8, r4, r7
 *   @0x2c0e10 add r8, r5, r9
 *   @0x2c0e14 rsb r9, r9, r5
 *   @0x2c0e18 str r4, [sp, #0x18]
 *   @0x2c0e1c add r4, r8, r11
 *   @0x2c0e20 ldr r5, [sp, #0x18]
 *   @0x2c0e24 rsb r11, r11, r8
 *   @0x2c0e28 add r4, r4, #262144
 *   @0x2c0e2c movw r8, #0x21f9
 *   @0x2c0e30 ubfx r4, r4, #0x13, #0xa
 *   @0x2c0e34 add r11, r11, #262144
 *   @0x2c0e38 mla r7, r8, r0, r5
 *   @0x2c0e3c ldrb r4, [r12, r4]
 *   @0x2c0e40 ubfx r11, r11, #0x13, #0xa
 *   @0x2c0e44 add r0, r9, r7
 *   @0x2c0e48 strb r4, [r6, r10]
 *   @0x2c0e4c add r0, r0, #262144
 *   @0x2c0e50 ldrb r6, [r12, r11]
 *   @0x2c0e54 ubfx r0, r0, #0x13, #0xa
 *   @0x2c0e58 rsb r7, r7, r9
 *   @0x2c0e5c add r7, r7, #262144
 *   @0x2c0e60 strb r6, [r1, #0x3]
 *   @0x2c0e64 ubfx r7, r7, #0x13, #0xa
 *   @0x2c0e68 ldrb r0, [r12, r0]
 *   @0x2c0e6c strb r0, [r1, #0x1]
 *   @0x2c0e70 ldrb r0, [r12, r7]
 *   @0x2c0e74 strb r0, [r1, #0x2]
 *   @0x2c0e78 add r2, r2, #4
 *   @0x2c0e7c cmp r2, #16
 *   @0x2c0e80 bne 0x2c0d6c <jpeg_idct_4x4+0x248>
 *   @0x2c0e84 add sp, sp, #176
 *   @0x2c0e88 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2c0e8c bx lr
 *   @0x2c0e90 ldr r9, [r3, #0x18]
 *   @0x2c0e94 ldr r7, [r3, #0x1c]
 *   @0x2c0e98 ldr r5, [r3, #0x14]
 *   @0x2c0e9c str r9, [sp, #0x20]
 *   @0x2c0ea0 ldr r4, [r3, #0xc]
 *   @0x2c0ea4 b 0x2c0da4 <jpeg_idct_4x4+0x280>
 *   @0x2c0ea8 ldr r4, [r3, #0xc]
 *   @0x2c0eac cmp r4, #0
 *   @0x2c0eb0 beq 0x2c0f18 <jpeg_idct_4x4+0x3f4>
 *   @0x2c0eb4 ldr r5, [r3, #0x18]
 *   @0x2c0eb8 ldr r7, [r3, #0x1c]
 *   @0x2c0ebc str r5, [sp, #0x20]
 *   @0x2c0ec0 ldr r5, [r3, #0x14]
 *   @0x2c0ec4 b 0x2c0da4 <jpeg_idct_4x4+0x280>
 *   @0x2c0ec8 ldrh r10, [r3, #80]
 *   @0x2c0ecc ldrh r8, [r3, #96]
 *   @0x2c0ed0 cmp r10, #0
 *   @0x2c0ed4 ldrh r9, [r3, #112]
 *   @0x2c0ed8 movne r6, r5
 *   @0x2c0edc movne r7, r5
 *   @0x2c0ee0 bne 0x2c0bc0 <jpeg_idct_4x4+0x9c>
 *   @0x2c0ee4 cmp r8, #0
 *   @0x2c0ee8 bne 0x2c0f80 <jpeg_idct_4x4+0x45c>
 *   @0x2c0eec cmp r9, #0
 *   @0x2c0ef0 bne 0x2c0f90 <jpeg_idct_4x4+0x46c>
 *   @0x2c0ef4 ldrsh r5, [r4, #-2]
 *   @0x2c0ef8 ldr r6, [r12, #-0x4]
 *   @0x2c0efc mul r5, r6, r5
 *   @0x2c0f00 lsl r5, r5, #2
 *   @0x2c0f04 str r5, [r0]
 *   @0x2c0f08 str r5, [r0, #0x20]
 *   @0x2c0f0c str r5, [r0, #0x40]
 *   @0x2c0f10 str r5, [r0, #0x60]
 *   @0x2c0f14 b 0x2c0cd0 <jpeg_idct_4x4+0x1ac>
 *   @0x2c0f18 ldr r5, [r3, #0x14]
 *   @0x2c0f1c cmp r5, #0
 *   @0x2c0f20 bne 0x2c0f6c <jpeg_idct_4x4+0x448>
 *   @0x2c0f24 ldr r8, [r3, #0x18]
 *   @0x2c0f28 ldr r7, [r3, #0x1c]
 *   @0x2c0f2c cmp r8, #0
 *   @0x2c0f30 str r8, [sp, #0x20]
 *   @0x2c0f34 movne r4, r5
 *   @0x2c0f38 movne r8, r5
 *   @0x2c0f3c bne 0x2c0da4 <jpeg_idct_4x4+0x280>
 *   @0x2c0f40 cmp r7, #0
 *   @0x2c0f44 bne 0x2c0fa4 <jpeg_idct_4x4+0x480>
 *   @0x2c0f48 ldr r0, [r3], #32
 *   @0x2c0f4c add r0, r0, #16
 *   @0x2c0f50 ubfx r0, r0, #0x5, #0xa
 *   @0x2c0f54 ldrb r0, [r12, r0]
 *   @0x2c0f58 strb r0, [r6, r10]
 *   @0x2c0f5c strb r0, [r1, #0x1]
 *   @0x2c0f60 strb r0, [r1, #0x2]
 *   @0x2c0f64 strb r0, [r1, #0x3]
 *   @0x2c0f68 b 0x2c0e78 <jpeg_idct_4x4+0x354>
 *   @0x2c0f6c ldr r7, [r3, #0x18]
 *   @0x2c0f70 mov r8, r4
 *   @0x2c0f74 str r7, [sp, #0x20]
 *   @0x2c0f78 ldr r7, [r3, #0x1c]
 *   @0x2c0f7c b 0x2c0da4 <jpeg_idct_4x4+0x280>
 *   @0x2c0f80 mov r6, r5
 *   @0x2c0f84 mov r10, r5
 *   @0x2c0f88 mov r7, r5
 *   @0x2c0f8c b 0x2c0bc0 <jpeg_idct_4x4+0x9c>
 *   @0x2c0f90 mov r6, r5
 *   @0x2c0f94 mov r10, r5
 *   @0x2c0f98 mov r8, r5
 *   @0x2c0f9c mov r7, r5
 *   @0x2c0fa0 b 0x2c0bc0 <jpeg_idct_4x4+0x9c>
 *   @0x2c0fa4 ldr r4, [sp, #0x20]
 *   @0x2c0fa8 mov r5, r4
 *   @0x2c0fac mov r8, r4
 *   @0x2c0fb0 b 0x2c0da4 <jpeg_idct_4x4+0x280>
 *
 * ══ §13/29 png_do_rgb_to_gray  0x2a91ac  size 1166  292 条（0x2a91ac..0x2a963a）
 * @func 0x2a91ac 0x2a963a  size 1166  292 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x33dd20 / anon_2b3f58+0x1b64 / anon_31518e+0xe2 / anon_2b3f58+0x1c38 / anon_31518e+0x23a / 0x4053b2 / 0x1a77e90 / 0x1473bc4
 * 字段偏移 top8: 0x-1×6 / 0x-2×2 / 0x18×2 / 0x1×2 / 0xa×2 / 0x8×1 / 0x9×1 / 0x4×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a91ac ldrb r3, [r1, #0x8]
 *   @0x2a91b0 .word 0xf0034ff7
 *   @0x2a91b4 stchs p5, c0, [r2, #-12]
 *   @0x2a91b8 ldr r4, [r1]
 *   @0x2a91bc rfeia r0!
 *   @0x2a91c0 blhs 0x33dd20
 *   @0x2a91c4 ldrh.w r9, [r0, #0x2d8]
 *   @0x2a91c8 str r5, [sp]
 *   @0x2a91cc rfeia r0!
 *   @0x2a91d0 .word 0xf04052da
 *   @0x2a91d4 bvc 0x15895f8 <b2_toiTime+0xe30154>
 *   @0x2a91d8 cmp r3, #0x8
 *   @0x2a91dc ldr.w r3, [r0, #0x22c]
 *   @0x2a91e0 mov.w r10, #0x3
 *   @0x2a91e4 adds r7, r2, #0x1
 *   @0x2a91e8 mla r10, r10, r4, r2
 *   @0x2a91ec cbnz r3, 0x2a91f2 <png_do_rgb_to_gray+0x46>
 *   @0x2a91f0 b 0x2a9286 <png_do_rgb_to_gray+0xda>
 *   @0x2a91f4 blhs 0x2b5abc <jinit_input_controller+0x1bdc>
 *   @0x2a91f8 beq 0x2a91ee <png_do_rgb_to_gray+0x42>
 *   @0x2a91fc cmp r6, r10
 *   @0x2a9200 .word 0xf8d080f2
 *   @0x2a9204 .word 0xf8968230
 *   @0x2a9208 .word 0xf8969001
 *   @0x2a920c .word 0xf818c000
 *   @0x2a9210 .word 0xf818b009
 *   @0x2a9214 .word 0xf896c00c
 *   @0x2a9218 ldrbmi r9, [r12, #0x2]
 *   @0x2a921c ldrb.w r8, [r8, r9]
 *   @0x2a9220 bne 0x2a9226 <png_do_rgb_to_gray+0x7a>
 *   @0x2a9224 beq 0x2a924c <png_do_rgb_to_gray+0xa0>
 *   @0x2a9228 ldr.w r9, [sp, #0x4]
 *   @0x2a922c mul r12, r3, r12
 *   @0x2a9230 ldr.w r3, [r0, #0x22c]
 *   @0x2a9234 mla r11, r9, r11, r12
 *   @0x2a9238 mla r8, r5, r8, r11
 *   @0x2a923c lsr.w r8, r8, #0xf
 *   @0x2a9240 ldrb.w r3, [r3, r8]
 *   @0x2a9244 strb r3, [r7, #-1]
 *   @0x2a9248 movs r3, #0x1
 *   @0x2a924c strb r9, [r7, #-1]
 *   @0x2a9250 adds r6, #0x3
 *   @0x2a9254 b 0x2a91fc <png_do_rgb_to_gray+0x50>
 *   @0x2a9258 .word 0xf896c000
 *   @0x2a925c .word 0xf8969001
 *   @0x2a9260 strbmi r8, [r12, #0x2]
 *   @0x2a9264 beq 0x2a928c <png_do_rgb_to_gray+0xe0>
 *   @0x2a9268 blls 0x315270 <FT_Bitmap_Embolden+0x42a>
 *   @0x2a926c mul r12, r11, r12
 *   @0x2a9270 mla r9, r3, r9, r12
 *   @0x2a9274 movs r3, #0x1
 *   @0x2a9278 b 0x168f2a0 <b2_toiTime+0xf35dfc>
 *   @0x2a927c .word 0xf80738d8
 *   @0x2a9280 strlo r8, [r3], -r1, lsl #24
 *   @0x2a9284 adds r7, #0x1
 *   @0x2a9288 bne 0x2a9256 <png_do_rgb_to_gray+0xaa>
 *   @0x2a928c cmp r12, r8
 *   @0x2a9290 strb r12, [r7, #-1]
 *   @0x2a9294 b 0x2a9282 <png_do_rgb_to_gray+0xd6>
 *   @0x2a9298 ldcne p2, c3, [r7], {60}
 *   @0x2a929c mov r6, r2
 *   @0x2a92a0 movs r3, #0x0
 *   @0x2a92a4 b 0x2a93da <png_do_rgb_to_gray+0x22e>
 *   @0x2a92a8 blhs 0x2b5b90 <jinit_input_controller+0x1cb0>
 *   @0x2a92ac beq 0x2a92a0 <png_do_rgb_to_gray+0xf4>
 *   @0x2a92b0 mov r12, r7
 *   @0x2a92b4 cmp r8, r4
 *   @0x2a92b8 .word 0xf8968096
 *   @0x2a92bc ldmdavc r7!, {r12, pc} ^
 *   @0x2a92c0 ldrb.w r10, [r6, #0x2]
 *   @0x2a92c4 orr.w r7, r7, r9, lsl #8
 *   @0x2a92c8 ldrb.w r9, [r6, #0x3]
 *   @0x2a92cc ldrb.w r11, [r6, #0x4]
 *   @0x2a92d0 orr.w r10, r9, r10, lsl #8
 *   @0x2a92d4 ldrb.w r9, [r6, #0x5]
 *   @0x2a92d8 cmp r7, r10
 *   @0x2a92dc mrsle r2, apsr
 *   @0x2a92e0 cmp r7, r9
 *   @0x2a92e4 uxtb.w r11, r10
 *   @0x2a92e8 ldr.w r3, [r0, #0x21c]
 *   @0x2a92ec lsr.w r10, r10, #0x8
 *   @0x2a92f0 asr.w r11, r11, r3
 *   @0x2a92f4 ldr.w r3, [r0, #0x23c]
 *   @0x2a92f8 ldr.w r11, [r3, r11, lsl #2]
 *   @0x2a92fc ldr.w r3, [r0, #0x21c]
 *   @0x2a9300 ldrh.w r10, [r11, r10, lsl #1]
 *   @0x2a9304 uxtb.w r11, r7
 *   @0x2a9308 lsrs r7, r7, #0x8
 *   @0x2a930c .word 0xf8d0fb03
 *   @0x2a9310 .word 0xf853323c
 *   @0x2a9314 blls 0x3153c8 <FT_Bitmap_Embolden+0x582>
 *   @0x2a9318 ldrh.w r7, [r11, r7, lsl #1]
 *   @0x2a931c ldr.w r11, [sp]
 *   @0x2a9320 mul r7, r11, r7
 *   @0x2a9324 mla r10, r3, r10, r7
 *   @0x2a9328 uxtb.w r7, r9
 *   @0x2a932c ldr.w r3, [r0, #0x21c]
 *   @0x2a9330 lsr.w r9, r9, #0x8
 *   @0x2a9334 asrs r7, r3
 *   @0x2a9338 .word 0xf853323c
 *   @0x2a933c .word 0xf8d07027
 *   @0x2a9340 rfeda r7!
 *   @0x2a9344 blx 0x4053b2 <g_RomDisk+0xdb92>
 *   @0x2a9348 vmlsl.u8 q13, d10, d7
 *   @0x2a934c blx 0x1a77e90 <b2_toiTime+0x131e9ec>
 *   @0x2a9350 b 0x16a7180 <b2_toiTime+0xf4dcdc>
 *   @0x2a9354 blx 0x1473bc4 <b2_toiTime+0xd1a720>
 *   @0x2a9358 .word 0xf8d0f903
 *   @0x2a935c .word 0xf8577238
 *   @0x2a9360 rfeda r3!
 *   @0x2a9364 movwhs r7, #0x101a
 *   @0x2a9368 lsr.w r9, r7, #0x8
 *   @0x2a936c strb r7, [r12, #-1]
 *   @0x2a9370 strb r9, [r12, #-2]
 *   @0x2a9374 add.w r8, r8, #0x1
 *   @0x2a9378 adds r6, #0x6
 *   @0x2a937c ldr r0, [r9, r2, lsl #24]
 *   @0x2a9380 ldrb.w r9, [r6]
 *   @0x2a9384 ldrb.w r8, [r6, #0x1]
 *   @0x2a9388 ldrb.w r10, [r6, #0x2]
 *   @0x2a938c orr.w r8, r8, r9, lsl #8
 *   @0x2a9390 ldrb.w r9, [r6, #0x3]
 *   @0x2a9394 ldrb.w r11, [r6, #0x4]
 *   @0x2a9398 orr.w r9, r9, r10, lsl #8
 *   @0x2a939c ldrb.w r10, [r6, #0x5]
 *   @0x2a93a0 cmp r8, r9
 *   @0x2a93a4 tstle r11, r11, lsl #20
 *   @0x2a93a8 cmp r8, r10
 *   @0x2a93ac movne r3, #0x1
 *   @0x2a93b0 .word 0xf10cb000
 *   @0x2a93b4 strlo r0, [r6], -r1, lsl #24
 *   @0x2a93b8 adds r7, #0x2
 *   @0x2a93bc .word 0xf8ddf808
 *   @0x2a93c0 blx 0x5953da <g_SWFlineaavertbuff+0x42312>
 *   @0x2a93c4 blx 0x40b3f2 <g_RomDisk+0x13bd2>
 *   @0x2a93c8 b 0x168bbf8 <b2_toiTime+0xf32754>
 *   @0x2a93cc .word 0xf8073ada
 *   @0x2a93d0 vmull.u8 q13, d10, d3
 *   @0x2a93d4 .word 0xf8072807
 *   @0x2a93d8 strmi r8, [r4, #0xc04]!
 *   @0x2a93dc bne 0x2a9380 <png_do_rgb_to_gray+0x1d4>
 *   @0x2a93e0 movs r3, #0x1
 *   @0x2a93e4 movs r3, #0x0
 *   @0x2a93e8 cmp r6, #0x6
 *   @0x2a93ec bvc 0x1649820 <b2_toiTime+0xef037c>
 *   @0x2a93f0 cmp r6, #0x8
 *   @0x2a93f4 ldr.w r6, [r0, #0x22c]
 *   @0x2a93f8 adds r7, r2, #0x2
 *   @0x2a93fc movs r0, #0x0
 *   @0x2a9400 ldr.w r6, [r0, #0x230]
 *   @0x2a9404 cmp r6, #0x0
 *   @0x2a9408 mov.w r12, #0x0
 *   @0x2a940c cmp r12, r4
 *   @0x2a9410 .word 0xf8d080f9
 *   @0x2a9414 ldmdavc r6, {r4, r5, r9, pc}
 *   @0x2a9418 ldrb.w r9, [r2, #0x1]
 *   @0x2a941c ldrb.w r10, [r2, #0x2]
 *   @0x2a9420 ldrb.w r6, [r8, r6]
 *   @0x2a9424 ldrb.w r9, [r8, r9]
 *   @0x2a9428 ldrb.w r8, [r8, r10]
 *   @0x2a942c cmp r6, r9
 *   @0x2a9430 cmp r6, r8
 *   @0x2a9434 movne r3, #0x1
 *   @0x2a9438 movs r3, #0x1
 *   @0x2a943c .word 0xf10ca000
 *   @0x2a9440 .word 0xf8dd0c01
 *   @0x2a9444 andlo r11, r4, #4
 *   @0x2a9448 adds r7, #0x2
 *   @0x2a944c blx 0x5a6c6e <g_SWFlineaavertbuff+0x53ba6>
 *   @0x2a9450 .word 0xf8d06909
 *   @0x2a9454 blx 0x401d0e <g_RomDisk+0xa4ee>
 *   @0x2a9458 b 0x168f480 <b2_toiTime+0xf35fdc>
 *   @0x2a945c .word 0xf81638d8
 *   @0x2a9460 .word 0xf8076008
 *   @0x2a9464 .word 0xf8126c04
 *   @0x2a9468 .word 0xf8076c01
 *   @0x2a946c strb r6, [sp, r3, lsl #24]
 *   @0x2a9470 ldrb r6, [r2]
 *   @0x2a9474 .word 0xf8928001
 *   @0x2a9478 strbmi r12, [r6, #-0x2]
 *   @0x2a947c bne 0x2a94b4 <png_do_rgb_to_gray+0x308>
 *   @0x2a9480 it ne
 *   @0x2a9484 ldr.w r9, [sp]
 *   @0x2a9488 adds r0, #0x1
 *   @0x2a948c andlo r10, r4, #4
 *   @0x2a9490 adds r7, #0x2
 *   @0x2a9494 blx 0x566cb6 <g_SWFlineaavertbuff+0x13bee>
 *   @0x2a9498 blx 0x4034c2 <g_RomDisk+0xbca2>
 *   @0x2a949c b 0x168c4d4 <b2_toiTime+0xf33030>
 *   @0x2a94a0 .word 0xf8073cdc
 *   @0x2a94a4 .word 0xf812cc04
 *   @0x2a94a8 .word 0xf8076c01
 *   @0x2a94ac adcmi r6, r0, #768
 *   @0x2a94b0 bne 0x2a9470 <png_do_rgb_to_gray+0x2c4>
 *   @0x2a94b4 movs r3, #0x1
 *   @0x2a94b8 ldr.w r6, [r0, #0x23c]
 *   @0x2a94bc cbnz r6, 0x2a94c4 <png_do_rgb_to_gray+0x318>
 *   @0x2a94c0 movs r6, #0x0
 *   @0x2a94c4 ldr.w r6, [r0, #0x238]
 *   @0x2a94c8 cmp r6, #0x0
 *   @0x2a94cc mov r7, r2
 *   @0x2a94d0 strmi r0, [r4, #0xc00]!
 *   @0x2a94d4 beq.w 0x2a9604 <png_do_rgb_to_gray+0x458>
 *   @0x2a94d8 ldrb.w r8, [r2]
 *   @0x2a94dc ldrb r6, [r2, #0x1]
 *   @0x2a94e0 b 0x144d4f0 <b2_toiTime+0xcf404c>
 *   @0x2a94e4 .word 0xf8922608
 *   @0x2a94e8 .word 0xf8928003
 *   @0x2a94ec b 0x14d1504 <b2_toiTime+0xd78060>
 *   @0x2a94f0 .word 0xf8922909
 *   @0x2a94f4 strbmi r8, [lr, #-0x5]
 *   @0x2a94f8 orr.w r8, r8, r10, lsl #8
 *   @0x2a94fc bne 0x2a9502 <png_do_rgb_to_gray+0x356>
 *   @0x2a9500 beq 0x2a9574 <png_do_rgb_to_gray+0x3c8>
 *   @0x2a9504 blx 0x1a75d7c <b2_toiTime+0x131c8d8>
 *   @0x2a9508 .word 0xf8d0fa89
 *   @0x2a950c b 0x1695e04 <b2_toiTime+0xf3c960>
 *   @0x2a9510 blx 0x153397c <b2_toiTime+0xdda4d8>
 *   @0x2a9514 .word 0xf85bfa03
 *   @0x2a9518 rfeda r10!
 *   @0x2a951c blx 0x1a8d588 <b2_toiTime+0x13340e4>
 *   @0x2a9520 beq 0x1067f40 <b2_toiTime+0x90ea9c>
 *   @0x2a9524 asr.w r10, r10, r3
 *   @0x2a9528 ldr.w r10, [r11, r10, lsl #2]
 *   @0x2a952c ldrh.w r6, [r10, r6, lsl #1]
 *   @0x2a9530 ldr.w r10, [sp]
 *   @0x2a9534 mul r6, r10, r6
 *   @0x2a9538 ldr.w r10, [sp, #0x4]
 *   @0x2a953c mla r9, r10, r9, r6
 *   @0x2a9540 uxtb.w r6, r8
 *   @0x2a9544 lsr.w r8, r8, #0x8
 *   @0x2a9548 asrs r6, r3
 *   @0x2a954c rfeda r6!
 *   @0x2a9550 blx 0x4015ba <g_RomDisk+0x9d9a>
 *   @0x2a9554 .word 0xf3c99906
 *   @0x2a9558 blx 0x1a77c9c <b2_toiTime+0x131e7f8>
 *   @0x2a955c b 0x16a6f88 <b2_toiTime+0xf4dae4>
 *   @0x2a9560 blx 0x14339cc <b2_toiTime+0xcda528>
 *   @0x2a9564 .word 0xf8d0f303
 *   @0x2a9568 .word 0xf8566238
 *   @0x2a956c rfeda r3!
 *   @0x2a9570 movwhs r6, #0x1019
 *   @0x2a9574 strb r6, [r7, #0x1]
 *   @0x2a9578 .word 0xf8872816
 *   @0x2a957c .word 0xf10c8000
 *   @0x2a9580 ldmibvc r6, {r0, r10, r11}
 *   @0x2a9584 adds r7, #0x4
 *   @0x2a9588 strb r6, [r7, #-2]
 *   @0x2a958c ldrb r6, [r2, #-1]
 *   @0x2a9590 strb r6, [r7, #-1]
 *   @0x2a9594 b 0x2a94d2 <png_do_rgb_to_gray+0x326>
 *   @0x2a9598 ldmdavc r7, {lr, pc} ^
 *   @0x2a959c ldrb.w r8, [r2, #0x2]
 *   @0x2a95a0 orr.w r7, r7, r12, lsl #8
 *   @0x2a95a4 ldrb.w r12, [r2, #0x3]
 *   @0x2a95a8 ldrb.w r9, [r2, #0x4]
 *   @0x2a95ac orr.w r8, r12, r8, lsl #8
 *   @0x2a95b0 ldrb.w r12, [r2, #0x5]
 *   @0x2a95b4 cmp r7, r8
 *   @0x2a95b8 .word 0xd1212c09
 *   @0x2a95bc cmp r7, r12
 *   @0x2a95c0 movne r3, #0x1
 *   @0x2a95c4 strlo r11, [r1], -r0
 *   @0x2a95c8 ldr.w r9, [sp, #0x4]
 *   @0x2a95cc adds r2, #0x8
 *   @0x2a95d0 mul r7, r11, r7
 *   @0x2a95d4 mla r7, r9, r8, r7
 *   @0x2a95d8 mla r7, r5, r12, r7
 *   @0x2a95dc lsrs r7, r7, #0xf
 *   @0x2a95e0 .word 0xf3c77c03
 *   @0x2a95e4 .word 0xf8002c07
 *   @0x2a95e8 .word 0xf812cc04
 *   @0x2a95ec .word 0xf8007c02
 *   @0x2a95f0 .word 0xf8127c02
 *   @0x2a95f4 .word 0xf8007c01
 *   @0x2a95f8 adcmi r7, r6, #256
 *   @0x2a95fc bne 0x2a9596 <png_do_rgb_to_gray+0x3ea>
 *   @0x2a9600 movs r3, #0x1
 *   @0x2a9604 ldrb r2, [r1, #0xa]
 *   @0x2a9608 subs r2, #0x2
 *   @0x2a960c andvc r0, r8, #2
 *   @0x2a9610 ldrb r0, [r1, #0x9]
 *   @0x2a9614 strb r2, [r1, #0xa]
 *   @0x2a9618 uxtb r2, r2
 *   @0x2a961c cmp r2, #0x7
 *   @0x2a9620 lsrs r2, r2, #0x3
 *   @0x2a9624 b 0x2a962c <png_do_rgb_to_gray+0x480>
 *   @0x2a9628 adds r4, #0x7
 *   @0x2a962c str r4, [r1, #0x4]
 *   @0x2a9630 movs r3, #0x0
 *   @0x2a9634 add sp, #0xc
 *   @0x2a9638 strdeq r8, r9, [r0], -r0
 *
 * ══ §14/29 b2PrismaticJoint::SolvePositionConstraints(b2SolverData const&)  0x2cf714  size 1164  291 条（0x2cf714..0x2cfba0）
 * @func 0x2cf714 0x2cfba0  size 1164  291 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / b2Mat33::Solve33(b2Vec3 const&) const / b2PrismaticJoint::SolvePositionConstraints(b2SolverData const&)+0x408 / 0xfebc57c4
 * 字段偏移 top8: 0x90×2 / 0x94×2 / 0x18×2 / 0x88×1
 * VFP 指令 238 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf714 push {r4, r5, r6, r7, lr}
 *   @0x2cf718 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2cf71c mov r4, r0
 *   @0x2cf720 ldr r5, [r0, #0x90]
 *   @0x2cf724 sub sp, sp, #84
 *   @0x2cf728 ldr r6, [r0, #0x94]
 *   @0x2cf72c mov r7, r1
 *   @0x2cf730 ldr r3, [r1, #0x18]
 *   @0x2cf734 add r5, r5, r5, lsl #1
 *   @0x2cf738 add r6, r6, r6, lsl #1
 *   @0x2cf73c add r5, r3, r5, lsl #2
 *   @0x2cf740 vldr s25, [r5, #8]
 *   @0x2cf744 vmov r0, s25
 *   @0x2cf748 add r6, r3, r6, lsl #2
 *   @0x2cf74c bl 0xb6580 <sinf@plt>
 *   @0x2cf750 vldr s8, [r6, #4]
 *   @0x2cf754 vstr s8, [sp, #8]
 *   @0x2cf758 vldr s26, [r6, #8]
 *   @0x2cf75c vmov s23, r0
 *   @0x2cf760 vmov r0, s25
 *   @0x2cf764 bl 0xb658c <cosf@plt>
 *   @0x2cf768 vmov s24, r0
 *   @0x2cf76c vmov r0, s26
 *   @0x2cf770 bl 0xb6580 <sinf@plt>
 *   @0x2cf774 vmov s16, r0
 *   @0x2cf778 vmov r0, s26
 *   @0x2cf77c bl 0xb658c <cosf@plt>
 *   @0x2cf780 vldr s14, [r4, #80]
 *   @0x2cf784 vldr s15, [r4, #164]
 *   @0x2cf788 vsub.f32 s15, s14, s15
 *   @0x2cf78c vldr s5, [r4, #76]
 *   @0x2cf790 vldr s8, [r4, #160]
 *   @0x2cf794 vldr s6, [r4, #72]
 *   @0x2cf798 vldr s14, [r4, #156]
 *   @0x2cf79c vldr s7, [r4, #68]
 *   @0x2cf7a0 vldr s13, [r4, #152]
 *   @0x2cf7a4 vldr s17, [r4, #96]
 *   @0x2cf7a8 vldr s10, [r4, #92]
 *   @0x2cf7ac vldr s11, [r5, #4]
 *   @0x2cf7b0 vstr s11, [sp]
 *   @0x2cf7b4 vldr s20, [r4, #88]
 *   @0x2cf7b8 vldr s31, [r6]
 *   @0x2cf7bc vldr s11, [r5]
 *   @0x2cf7c0 vstr s11, [sp, #4]
 *   @0x2cf7c4 vldr s11, [r4, #84]
 *   @0x2cf7c8 vldr s9, [r4, #100]
 *   @0x2cf7cc vldr s29, [r4, #168]
 *   @0x2cf7d0 vldr s30, [r4, #172]
 *   @0x2cf7d4 vsub.f32 s8, s5, s8
 *   @0x2cf7d8 vldr s27, [r4, #176]
 *   @0x2cf7dc vldr s28, [r4, #180]
 *   @0x2cf7e0 vsub.f32 s14, s6, s14
 *   @0x2cf7e4 vmul.f32 s21, s14, s24
 *   @0x2cf7e8 vmov s12, r0
 *   @0x2cf7ec vmul.f32 s22, s15, s12
 *   @0x2cf7f0 vmul.f32 s15, s15, s16
 *   @0x2cf7f4 vmla.f32 s22, s8, s16
 *   @0x2cf7f8 vsub.f32 s13, s7, s13
 *   @0x2cf7fc vnmls.f32 s15, s8, s12
 *   @0x2cf800 vldr s8, [sp, #8]
 *   @0x2cf804 vmul.f32 s18, s17, s24
 *   @0x2cf808 vmla.f32 s21, s13, s23
 *   @0x2cf80c vmul.f32 s14, s14, s23
 *   @0x2cf810 vadd.f32 s12, s22, s8
 *   @0x2cf814 vldr s8, [sp]
 *   @0x2cf818 vmla.f32 s18, s10, s23
 *   @0x2cf81c vmul.f32 s17, s17, s23
 *   @0x2cf820 vsub.f32 s12, s12, s8
 *   @0x2cf824 vnmls.f32 s14, s13, s24
 *   @0x2cf828 vmul.f32 s19, s20, s23
 *   @0x2cf82c vadd.f32 s13, s15, s31
 *   @0x2cf830 vsub.f32 s12, s12, s21
 *   @0x2cf834 vnmls.f32 s17, s10, s24
 *   @0x2cf838 vldr s10, [sp, #4]
 *   @0x2cf83c vsub.f32 s13, s13, s10
 *   @0x2cf840 vnmls.f32 s19, s11, s24
 *   @0x2cf844 vmul.f32 s20, s20, s24
 *   @0x2cf848 vmul.f32 s16, s12, s18
 *   @0x2cf84c vsub.f32 s13, s13, s14
 *   @0x2cf850 vmla.f32 s20, s11, s23
 *   @0x2cf854 vmla.f32 s16, s13, s17
 *   @0x2cf858 vmul.f32 s24, s22, s19
 *   @0x2cf85c vmul.f32 s22, s22, s17
 *   @0x2cf860 vsub.f32 s11, s26, s25
 *   @0x2cf864 vadd.f32 s21, s21, s12
 *   @0x2cf868 vnmls.f32 s24, s15, s20
 *   @0x2cf86c vnmls.f32 s22, s15, s18
 *   @0x2cf870 vsub.f32 s15, s11, s9
 *   @0x2cf874 vcmpe.f32 s16, #0
 *   @0x2cf878 vmul.f32 s23, s19, s21
 *   @0x2cf87c vmrs APSR_nzcv, fpscr
 *   @0x2cf880 vmul.f32 s21, s21, s17
 *   @0x2cf884 vadd.f32 s14, s14, s13
 *   @0x2cf888 vnegle.f32 s16, s16
 *   @0x2cf88c vcmpe.f32 s15, #0
 *   @0x2cf890 vneggt.f32 s9, s16
 *   @0x2cf894 vmovle.f32 s9, s16
 *   @0x2cf898 vmrs APSR_nzcv, fpscr
 *   @0x2cf89c vstrgt s15, [sp, #12]
 *   @0x2cf8a0 ldrb r3, [r4, #0x88]
 *   @0x2cf8a4 vnegle.f32 s15, s15
 *   @0x2cf8a8 vneggt.f32 s8, s15
 *   @0x2cf8ac vstrle s15, [sp, #12]
 *   @0x2cf8b0 vmovle.f32 s8, s15
 *   @0x2cf8b4 cmp r3, #0
 *   @0x2cf8b8 vnmls.f32 s23, s20, s14
 *   @0x2cf8bc vnmls.f32 s21, s14, s18
 *   @0x2cf8c0 beq 0x2cf9d8 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x2c4>
 *   @0x2cf8c4 vldr s11, [r4, #124]
 *   @0x2cf8c8 vldr s15, [r4, #120]
 *   @0x2cf8cc vsub.f32 s14, s11, s15
 *   @0x2cf8d0 vmul.f32 s12, s12, s20
 *   @0x2cf8d4 vcmpe.f32 s14, #0
 *   @0x2cf8d8 vmrs APSR_nzcv, fpscr
 *   @0x2cf8dc vnegle.f32 s14, s14
 *   @0x2cf8e0 vmla.f32 s12, s13, s19
 *   @0x2cf8e4 vldr s13, [pc, #664]
 *   @0x2cf8e8 vcmpe.f32 s14, s13
 *   @0x2cf8ec vmrs APSR_nzcv, fpscr
 *   @0x2cf8f0 bpl 0x2cfacc <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x3b8>
 *   @0x2cf8f4 vldr s14, [pc, #652]
 *   @0x2cf8f8 vcmpe.f32 s12, s14
 *   @0x2cf8fc vmrs APSR_nzcv, fpscr
 *   @0x2cf900 bmi 0x2cfb08 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x3f4>
 *   @0x2cf904 vldr s14, [pc, #640]
 *   @0x2cf908 vcmpe.f32 s12, #0
 *   @0x2cf90c vmrs APSR_nzcv, fpscr
 *   @0x2cf910 vnegle.f32 s12, s12
 *   @0x2cf914 vcmpe.f32 s16, s12
 *   @0x2cf918 vmrs APSR_nzcv, fpscr
 *   @0x2cf91c vmovle.f32 s16, s12
 *   @0x2cf920 vstr s9, [sp, #32]
 *   @0x2cf924 vstr s14, [sp, #40]
 *   @0x2cf928 add r0, sp, #20
 *   @0x2cf92c add r1, sp, #44
 *   @0x2cf930 vmul.f32 s9, s27, s23
 *   @0x2cf934 add r2, sp, #32
 *   @0x2cf938 vstr s8, [sp, #36]
 *   @0x2cf93c vadd.f32 s15, s29, s30
 *   @0x2cf940 vmul.f32 s12, s27, s21
 *   @0x2cf944 vmov.f32 s11, s15
 *   @0x2cf948 vmla.f32 s15, s9, s23
 *   @0x2cf94c vmul.f32 s13, s28, s22
 *   @0x2cf950 vmla.f32 s11, s12, s21
 *   @0x2cf954 vmul.f32 s10, s28, s24
 *   @0x2cf958 vmul.f32 s14, s13, s24
 *   @0x2cf95c vmla.f32 s15, s10, s24
 *   @0x2cf960 vmla.f32 s14, s12, s23
 *   @0x2cf964 vstr s15, [sp, #76]
 *   @0x2cf968 vmla.f32 s11, s13, s22
 *   @0x2cf96c vstr s14, [sp, #52]
 *   @0x2cf970 vstr s14, [sp, #68]
 *   @0x2cf974 vadd.f32 s15, s27, s28
 *   @0x2cf978 vstr s11, [sp, #44]
 *   @0x2cf97c vadd.f32 s14, s9, s10
 *   @0x2cf980 vadd.f32 s13, s12, s13
 *   @0x2cf984 vstr s14, [sp, #64]
 *   @0x2cf988 vstr s14, [sp, #72]
 *   @0x2cf98c vmov.f32 s11, #1.000000e+00
 *   @0x2cf990 vstr s13, [sp, #48]
 *   @0x2cf994 vstr s13, [sp, #56]
 *   @0x2cf998 vcmp.f32 s15, #0
 *   @0x2cf99c vmrs APSR_nzcv, fpscr
 *   @0x2cf9a0 vmoveq.f32 s15, s11
 *   @0x2cf9a4 vstr s15, [sp, #60]
 *   @0x2cf9a8 bl 0x2c6808 <_ZNK7b2Mat337Solve33ERK6b2Vec3>
 *   @0x2cf9ac ldr r5, [r4, #0x90]
 *   @0x2cf9b0 vldr s14, [sp, #20]
 *   @0x2cf9b4 ldr r6, [r4, #0x94]
 *   @0x2cf9b8 vldr s13, [sp, #24]
 *   @0x2cf9bc ldr r3, [r7, #0x18]
 *   @0x2cf9c0 vldr s15, [sp, #28]
 *   @0x2cf9c4 add r5, r5, r5, lsl #1
 *   @0x2cf9c8 add r6, r6, r6, lsl #1
 *   @0x2cf9cc add r5, r3, r5, lsl #2
 *   @0x2cf9d0 add r6, r3, r6, lsl #2
 *   @0x2cf9d4 b 0x2cfa34 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x320>
 *   @0x2cf9d8 vmul.f32 s13, s27, s21
 *   @0x2cf9dc vadd.f32 s12, s29, s30
 *   @0x2cf9e0 vmla.f32 s12, s13, s21
 *   @0x2cf9e4 vmul.f32 s15, s28, s22
 *   @0x2cf9e8 vadd.f32 s13, s13, s15
 *   @0x2cf9ec vmla.f32 s12, s15, s22
 *   @0x2cf9f0 vadd.f32 s10, s27, s28
 *   @0x2cf9f4 vmov.f32 s15, #1.000000e+00
 *   @0x2cf9f8 vmul.f32 s11, s13, s13
 *   @0x2cf9fc vcmp.f32 s10, #0
 *   @0x2cfa00 vmrs APSR_nzcv, fpscr
 *   @0x2cfa04 vmoveq.f32 s10, s15
 *   @0x2cfa08 vnmls.f32 s11, s10, s12
 *   @0x2cfa0c vcmp.f32 s11, #0
 *   @0x2cfa10 vmrs APSR_nzcv, fpscr
 *   @0x2cfa14 vdivne.f32 s11, s15, s11
 *   @0x2cfa18 vldr s15, [pc, #368]
 *   @0x2cfa1c vmul.f32 s14, s13, s8
 *   @0x2cfa20 vmul.f32 s13, s13, s9
 *   @0x2cfa24 vnmls.f32 s14, s10, s9
 *   @0x2cfa28 vnmls.f32 s13, s12, s8
 *   @0x2cfa2c vmul.f32 s14, s14, s11
 *   @0x2cfa30 vmul.f32 s13, s11, s13
 *   @0x2cfa34 vldr s11, [pc, #344]
 *   @0x2cfa38 vmul.f32 s20, s15, s20
 *   @0x2cfa3c vmov.f32 s12, s13
 *   @0x2cfa40 vmla.f32 s20, s14, s18
 *   @0x2cfa44 vmla.f32 s12, s14, s21
 *   @0x2cfa48 vmla.f32 s13, s14, s22
 *   @0x2cfa4c vmul.f32 s19, s15, s19
 *   @0x2cfa50 vmla.f32 s12, s15, s23
 *   @0x2cfa54 vmla.f32 s19, s14, s17
 *   @0x2cfa58 vldr s14, [sp, #4]
 *   @0x2cfa5c vmla.f32 s13, s15, s24
 *   @0x2cfa60 vldr s15, [sp]
 *   @0x2cfa64 vmls.f32 s15, s29, s20
 *   @0x2cfa68 vmls.f32 s25, s27, s12
 *   @0x2cfa6c vstr s15, [r5, #4]
 *   @0x2cfa70 vldr s15, [sp, #8]
 *   @0x2cfa74 vmls.f32 s14, s29, s19
 *   @0x2cfa78 vstr s25, [r5, #8]
 *   @0x2cfa7c vmla.f32 s31, s30, s19
 *   @0x2cfa80 vstr s14, [r5]
 *   @0x2cfa84 vmla.f32 s15, s30, s20
 *   @0x2cfa88 vstr s31, [r6]
 *   @0x2cfa8c vmla.f32 s26, s28, s13
 *   @0x2cfa90 vstr s15, [r6, #4]
 *   @0x2cfa94 vcmpe.f32 s16, s11
 *   @0x2cfa98 vstr s26, [r6, #8]
 *   @0x2cfa9c vmrs APSR_nzcv, fpscr
 *   @0x2cfaa0 movhi r0, #0
 *   @0x2cfaa4 bhi 0x2cfac0 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x3ac>
 *   @0x2cfaa8 vldr s15, [pc, #232]
 *   @0x2cfaac vldr s11, [sp, #12]
 *   @0x2cfab0 vcmpe.f32 s11, s15
 *   @0x2cfab4 vmrs APSR_nzcv, fpscr
 *   @0x2cfab8 movhi r0, #0
 *   @0x2cfabc movls r0, #1
 *   @0x2cfac0 add sp, sp, #84
 *   @0x2cfac4 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2cfac8 pop {r4, r5, r6, r7, pc}
 *   @0x2cfacc vcmpe.f32 s15, s12
 *   @0x2cfad0 vmrs APSR_nzcv, fpscr
 *   @0x2cfad4 blt 0x2cfb1c <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x408>
 *   @0x2cfad8 vsub.f32 s13, s12, s15
 *   @0x2cfadc vldr s14, [pc, #176]
 *   @0x2cfae0 vadd.f32 s14, s13, s14
 *   @0x2cfae4 vcmpe.f32 s14, #0
 *   @0x2cfae8 vmrs APSR_nzcv, fpscr
 *   @0x2cfaec bmi 0x2cfb6c <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x458>
 *   @0x2cfaf0 vldr s14, [pc, #164]
 *   @0x2cfaf4 vsub.f32 s12, s15, s12
 *   @0x2cfaf8 vcmpe.f32 s12, s16
 *   @0x2cfafc vmrs APSR_nzcv, fpscr
 *   @0x2cfb00 vmovpl.f32 s16, s12
 *   @0x2cfb04 b 0x2cf920 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x20c>
 *   @0x2cfb08 vldr s15, [pc, #124]
 *   @0x2cfb0c vcmpe.f32 s12, s15
 *   @0x2cfb10 vmrs APSR_nzcv, fpscr
 *   @0x2cfb14 vnegpl.f32 s14, s12
 *   @0x2cfb18 b 0x2cf908 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x1f4>
 *   @0x2cfb1c vcmpe.f32 s11, s12
 *   @0x2cfb20 vmrs APSR_nzcv, fpscr
 *   @0x2cfb24 bhi 0x2cf9d8 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x2c4>
 *   @0x2cfb28 vsub.f32 s12, s12, s11
 *   @0x2cfb2c vldr s14, [pc, #96]
 *   @0x2cfb30 vldr s15, [pc, #80]
 *   @0x2cfb34 vsub.f32 s14, s12, s14
 *   @0x2cfb38 vcmpe.f32 s14, s15
 *   @0x2cfb3c vmrs APSR_nzcv, fpscr
 *   @0x2cfb40 bpl 0x2cfb58 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x444>
 *   @0x2cfb44 vcmpe.f32 s14, #0
 *   @0x2cfb48 vmrs APSR_nzcv, fpscr
 *   @0x2cfb4c vnegpl.f32 s14, s14
 *   @0x2cfb50 vldrmi s14, [pc, #68]
 *   @0x2cfb54 b 0x2cfb5c <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x448>
 *   @0x2cfb58 vldr s14, [pc, #44]
 *   @0x2cfb5c vcmpe.f32 s12, s16
 *   @0x2cfb60 vmrs APSR_nzcv, fpscr
 *   @0x2cfb64 vmovpl.f32 s16, s12
 *   @0x2cfb68 b 0x2cf920 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x20c>
 *   @0x2cfb6c vldr s13, [pc, #24]
 *   @0x2cfb70 vcmpe.f32 s14, s13
 *   @0x2cfb74 vmrs APSR_nzcv, fpscr
 *   @0x2cfb78 vnegpl.f32 s14, s14
 *   @0x2cfb7c vldrmi s14, [pc, #4]
 *   @0x2cfb80 b 0x2cfaf4 <_ZN16b2PrismaticJoint24SolvePositionConstraintsERK12b2SolverData+0x3e0>
 *   @0x2cfb84 stclo p7, c13, [r3], #-40
 *   @0x2cfb88 cdplo p12, #0x4, c12, c12, c13, #0x6
 *   @0x2cfb8c cdplt p12, #0x4, c12, c12, c13, #0x6
 *   @0x2cfb90 andeq r0, r0, r0
 *   @0x2cfb94 bllo 0xfebc57c4 <b2_toiTime+0xfffffffffe46c320>
 *   @0x2cfb98 vstrlo s30, [lr, #-216]
 *   @0x2cfb9c andhi r0, r0, r0
 *
 * ══ §15/29 b2ParticleSystem::JoinParticleGroups(b2ParticleGroup*, b2ParticleGroup*)  0x2db6a0  size 1164  291 条（0x2db6a0..0x2dbb2c）
 * @func 0x2db6a0 0x2dbb2c  size 1164  291 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::RotateBuffer(int, int, int)×2 / b2ParticleSystem::UpdateContacts(bool)×2 / b2ParticleSystem::JoinParticleGroupsCallback::operator()(int, int, int) const×2 / b2ParticleSystem::JoinParticleGroups(b2ParticleGroup*, b2ParticleGroup*)+0x320 / b2ParticleSystem::JoinParticleGroups(b2ParticleGroup*, b2ParticleGroup*)+0x188 / b2VoronoiDiagram::b2VoronoiDiagram(b2StackAllocator*, int) / b2ParticleSystem::JoinParticleGroups(b2ParticleGroup*, b2ParticleGroup*)+0x238 / b2VoronoiDiagram::AddGenerator(b2Vec2 const&, int)
 * 字段偏移 top8: 0x8×34 / 0x4×17 / 0xc×7 / 0x8c×4 / 0x38×4 / 0x2×4 / 0x94×3 / 0xd4×3
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2db6a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2db6a4 sub sp, sp, #68
 *   @0x2db6a8 mov r9, r1
 *   @0x2db6ac ldr r3, [r0, #0x24]
 *   @0x2db6b0 str r2, [sp, #0x8]
 *   @0x2db6b4 mov r11, r0
 *   @0x2db6b8 ldr r12, [sp, #0x8]
 *   @0x2db6bc ldr r2, [r2, #0x8]
 *   @0x2db6c0 ldr r1, [r12, #0x4]
 *   @0x2db6c4 bl 0x2d7500 <_ZN16b2ParticleSystem12RotateBufferEiii>
 *   @0x2db6c8 ldr r12, [sp, #0x8]
 *   @0x2db6cc ldmib r9, {r1, r2}
 *   @0x2db6d0 mov r0, r11
 *   @0x2db6d4 ldr r3, [r12, #0x4]
 *   @0x2db6d8 bl 0x2d7500 <_ZN16b2ParticleSystem12RotateBufferEiii>
 *   @0x2db6dc ldr r12, [sp, #0x8]
 *   @0x2db6e0 ldr r3, [r9, #0x4]
 *   @0x2db6e4 ldr r2, [r12, #0x8]
 *   @0x2db6e8 cmp r3, r2
 *   @0x2db6ec bge 0x2dbaf8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x458>
 *   @0x2db6f0 ldr r1, [r11, #0x30]
 *   @0x2db6f4 mov r5, #0
 *   @0x2db6f8 add r3, r1, r3, lsl #2
 *   @0x2db6fc add r1, r1, r2, lsl #2
 *   @0x2db700 ldr r2, [r3], #4
 *   @0x2db704 cmp r3, r1
 *   @0x2db708 orr r5, r5, r2
 *   @0x2db70c bne 0x2db700 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x60>
 *   @0x2db710 mov r0, r11
 *   @0x2db714 mov r1, #1
 *   @0x2db718 bl 0x2da664 <_ZN16b2ParticleSystem14UpdateContactsEb>
 *   @0x2db71c tst r5, #8
 *   @0x2db720 beq 0x2db9c0 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x320>
 *   @0x2db724 ldr r1, [r11, #0x74]
 *   @0x2db728 cmp r1, #0
 *   @0x2db72c ble 0x2db9c0 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x320>
 *   @0x2db730 ldr r12, [sp, #0x8]
 *   @0x2db734 mov r6, #0
 *   @0x2db738 mov r8, r6
 *   @0x2db73c ldr r2, [r12, #0x8]
 *   @0x2db740 mov r12, r5
 *   @0x2db744 ldr r5, [sp, #0x8]
 *   @0x2db748 ldr r3, [r11, #0x7c]
 *   @0x2db74c add r10, r3, r6
 *   @0x2db750 ldr r7, [r3, r6]
 *   @0x2db754 ldr r4, [r10, #0x4]
 *   @0x2db758 cmp r7, r4
 *   @0x2db75c movle r3, r4
 *   @0x2db760 movle r4, r7
 *   @0x2db764 movle r7, r3
 *   @0x2db768 ldr r3, [r9, #0x4]
 *   @0x2db76c cmp r3, r4
 *   @0x2db770 bgt 0x2db828 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x188>
 *   @0x2db774 ldr r3, [r9, #0x8]
 *   @0x2db778 cmp r3, r4
 *   @0x2db77c ble 0x2db828 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x188>
 *   @0x2db780 ldr r3, [r5, #0x4]
 *   @0x2db784 cmp r3, r7
 *   @0x2db788 bgt 0x2db828 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x188>
 *   @0x2db78c cmp r7, r2
 *   @0x2db790 bge 0x2db828 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x188>
 *   @0x2db794 ldr r0, [r11, #0x8c]
 *   @0x2db798 ldr r3, [r11, #0x90]
 *   @0x2db79c cmp r0, r3
 *   @0x2db7a0 bge 0x2dba70 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3d0>
 *   @0x2db7a4 ldr r2, [r11, #0x94]
 *   @0x2db7a8 ldr r3, [r11, #0x38]
 *   @0x2db7ac vldr s12, [r9, #16]
 *   @0x2db7b0 vldr s13, [r5, #16]
 *   @0x2db7b4 vcmpe.f32 s12, s13
 *   @0x2db7b8 add r1, r3, r4, lsl #3
 *   @0x2db7bc add r3, r3, r7, lsl #3
 *   @0x2db7c0 vldr s10, [r1, #4]
 *   @0x2db7c4 vldr s14, [r3, #4]
 *   @0x2db7c8 vldr s11, [r1]
 *   @0x2db7cc vldr s15, [r3]
 *   @0x2db7d0 vsub.f32 s14, s10, s14
 *   @0x2db7d4 vmrs APSR_nzcv, fpscr
 *   @0x2db7d8 add r3, r0, r0, lsl #2
 *   @0x2db7dc ldr r1, [r10, #0x8]
 *   @0x2db7e0 add r10, r2, r3, lsl #2
 *   @0x2db7e4 str r4, [r2, r3, lsl #2]
 *   @0x2db7e8 str r1, [r10, #0x8]
 *   @0x2db7ec str r7, [r10, #0x4]
 *   @0x2db7f0 vmul.f32 s14, s14, s14
 *   @0x2db7f4 vsub.f32 s15, s11, s15
 *   @0x2db7f8 vmla.f32 s14, s15, s15
 *   @0x2db7fc vsqrt.f32 s15, s14
 *   @0x2db800 vcmp.f32 s15, s15
 *   @0x2db804 vmovmi.f32 s13, s12
 *   @0x2db808 vmrs APSR_nzcv, fpscr
 *   @0x2db80c vstr s13, [r10, #12]
 *   @0x2db810 bne 0x2dbb10 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x470>
 *   @0x2db814 ldr r1, [r11, #0x74]
 *   @0x2db818 add r0, r0, #1
 *   @0x2db81c ldr r2, [r5, #0x8]
 *   @0x2db820 vstr s15, [r10, #16]
 *   @0x2db824 str r0, [r11, #0x8c]
 *   @0x2db828 add r8, r8, #1
 *   @0x2db82c add r6, r6, #24
 *   @0x2db830 cmp r1, r8
 *   @0x2db834 bgt 0x2db748 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0xa8>
 *   @0x2db838 and r5, r12, #16
 *   @0x2db83c cmp r5, #0
 *   @0x2db840 beq 0x2db9d4 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x334>
 *   @0x2db844 add r12, sp, #40
 *   @0x2db848 ldr r1, [r11, #0xd4]
 *   @0x2db84c ldr r3, [r9, #0x4]
 *   @0x2db850 mov r0, r12
 *   @0x2db854 add r1, r1, #68
 *   @0x2db858 rsb r2, r3, r2
 *   @0x2db85c str r12, [sp, #0xc]
 *   @0x2db860 bl 0x2dbb2c <_ZN16b2VoronoiDiagramC2EP16b2StackAllocatori>
 *   @0x2db864 ldr r12, [sp, #0x8]
 *   @0x2db868 ldr r4, [r9, #0x4]
 *   @0x2db86c ldr r2, [r12, #0x8]
 *   @0x2db870 cmp r4, r2
 *   @0x2db874 bge 0x2db8d8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x238>
 *   @0x2db878 lsl r5, r4, #2
 *   @0x2db87c lsl r6, r4, #3
 *   @0x2db880 ldr r7, [sp, #0x8]
 *   @0x2db884 add r8, sp, #40
 *   @0x2db888 b 0x2db89c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x1fc>
 *   @0x2db88c add r4, r4, #1
 *   @0x2db890 add r6, r6, #8
 *   @0x2db894 cmp r2, r4
 *   @0x2db898 ble 0x2db8d8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x238>
 *   @0x2db89c ldr r3, [r11, #0x30]
 *   @0x2db8a0 ldr r3, [r3, r5]
 *   @0x2db8a4 add r5, r5, #4
 *   @0x2db8a8 tst r3, #2
 *   @0x2db8ac bne 0x2db88c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x1ec>
 *   @0x2db8b0 ldr r1, [r11, #0x38]
 *   @0x2db8b4 mov r2, r4
 *   @0x2db8b8 mov r0, r8
 *   @0x2db8bc add r4, r4, #1
 *   @0x2db8c0 add r1, r1, r6
 *   @0x2db8c4 add r6, r6, #8
 *   @0x2db8c8 bl 0x2dbb94 <_ZN16b2VoronoiDiagram12AddGeneratorERK6b2Vec2i>
 *   @0x2db8cc ldr r2, [r7, #0x8]
 *   @0x2db8d0 cmp r2, r4
 *   @0x2db8d4 bgt 0x2db89c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x1fc>
 *   @0x2db8d8 mov r0, r11
 *   @0x2db8dc bl 0x2d85a8 <_ZNK16b2ParticleSystem17GetParticleStrideEv>
 *   @0x2db8e0 vmov.f32 s15, #5.000000e-01
 *   @0x2db8e4 vmov s14, r0
 *   @0x2db8e8 add r0, sp, #40
 *   @0x2db8ec vmul.f32 s15, s14, s15
 *   @0x2db8f0 vmov r1, s15
 *   @0x2db8f4 bl 0x2dbbc4 <_ZN16b2VoronoiDiagram8GenerateEf>
 *   @0x2db8f8 ldr r3, [sp, #0x38]
 *   @0x2db8fc ldr r12, [sp, #0x8]
 *   @0x2db900 cmp r3, #1
 *   @0x2db904 str r11, [sp, #0x1c]
 *   @0x2db908 str r9, [sp, #0x20]
 *   @0x2db90c str r12, [sp, #0x24]
 *   @0x2db910 ble 0x2dba5c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3bc>
 *   @0x2db914 ldr r1, [sp, #0x34]
 *   @0x2db918 add r10, sp, #28
 *   @0x2db91c mov r8, #0
 *   @0x2db920 cmp r1, #1
 *   @0x2db924 ble 0x2dba4c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3ac>
 *   @0x2db928 mov r6, #0
 *   @0x2db92c b 0x2db950 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x2b0>
 *   @0x2db930 cmp r4, r7
 *   @0x2db934 cmpne r5, r7
 *   @0x2db938 bne 0x2db9a8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x308>
 *   @0x2db93c ldr r1, [sp, #0x34]
 *   @0x2db940 add r6, r6, #1
 *   @0x2db944 sub r3, r1, #1
 *   @0x2db948 cmp r6, r3
 *   @0x2db94c bge 0x2dba48 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3a8>
 *   @0x2db950 mla r2, r1, r8, r6
 *   @0x2db954 ldr r3, [sp, #0x3c]
 *   @0x2db958 add r0, r1, r2
 *   @0x2db95c add r12, r0, #1
 *   @0x2db960 add lr, r3, r2, lsl #2
 *   @0x2db964 ldr r4, [r3, r0, lsl #2]
 *   @0x2db968 ldr r2, [r3, r2, lsl #2]
 *   @0x2db96c ldr r5, [lr, #0x4]
 *   @0x2db970 ldr r7, [r3, r12, lsl #2]
 *   @0x2db974 cmp r5, r4
 *   @0x2db978 beq 0x2db940 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x2a0>
 *   @0x2db97c cmp r2, r4
 *   @0x2db980 cmpne r2, r5
 *   @0x2db984 beq 0x2db930 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x290>
 *   @0x2db988 ldr r1, [r2, #0x8]
 *   @0x2db98c mov r0, r10
 *   @0x2db990 ldr r2, [r5, #0x8]
 *   @0x2db994 ldr r3, [r4, #0x8]
 *   @0x2db998 bl 0x2d5580 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii>
 *   @0x2db99c cmp r4, r7
 *   @0x2db9a0 cmpne r5, r7
 *   @0x2db9a4 beq 0x2db93c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x29c>
 *   @0x2db9a8 ldr r1, [r5, #0x8]
 *   @0x2db9ac mov r0, r10
 *   @0x2db9b0 ldr r2, [r7, #0x8]
 *   @0x2db9b4 ldr r3, [r4, #0x8]
 *   @0x2db9b8 bl 0x2d5580 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii>
 *   @0x2db9bc b 0x2db93c <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x29c>
 *   @0x2db9c0 and r5, r5, #16
 *   @0x2db9c4 ldr r12, [sp, #0x8]
 *   @0x2db9c8 cmp r5, #0
 *   @0x2db9cc ldr r2, [r12, #0x8]
 *   @0x2db9d0 bne 0x2db844 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x1a4>
 *   @0x2db9d4 ldr r12, [sp, #0x8]
 *   @0x2db9d8 ldr r3, [r12, #0x4]
 *   @0x2db9dc cmp r3, r2
 *   @0x2db9e0 lsllt r1, r3, #2
 *   @0x2db9e4 bge 0x2dba00 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x360>
 *   @0x2db9e8 add r3, r3, #1
 *   @0x2db9ec ldr r0, [r11, #0x5c]
 *   @0x2db9f0 cmp r3, r2
 *   @0x2db9f4 str r9, [r0, r1]
 *   @0x2db9f8 add r1, r1, #4
 *   @0x2db9fc bne 0x2db9e8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x348>
 *   @0x2dba00 ldr r12, [sp, #0x8]
 *   @0x2dba04 mov r0, r11
 *   @0x2dba08 ldr r4, [r12, #0xc]
 *   @0x2dba0c mov r1, r12
 *   @0x2dba10 str r2, [r9, #0x8]
 *   @0x2dba14 ldr r3, [r12, #0x8]
 *   @0x2dba18 ldr r2, [r9, #0xc]
 *   @0x2dba1c orr r4, r4, r2
 *   @0x2dba20 str r4, [r9, #0xc]
 *   @0x2dba24 str r3, [r12, #0x4]
 *   @0x2dba28 bl 0x2d5874 <_ZN16b2ParticleSystem20DestroyParticleGroupEP15b2ParticleGroup>
 *   @0x2dba2c tst r4, #1
 *   @0x2dba30 beq 0x2dba40 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x3a0>
 *   @0x2dba34 mov r0, r11
 *   @0x2dba38 mov r1, r9
 *   @0x2dba3c bl 0x2d5920 <_ZN16b2ParticleSystem20ComputeDepthForGroupEP15b2ParticleGroup>
 *   @0x2dba40 add sp, sp, #68
 *   @0x2dba44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2dba48 ldr r3, [sp, #0x38]
 *   @0x2dba4c add r8, r8, #1
 *   @0x2dba50 sub r2, r3, #1
 *   @0x2dba54 cmp r8, r2
 *   @0x2dba58 blt 0x2db920 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x280>
 *   @0x2dba5c add r0, sp, #40
 *   @0x2dba60 bl 0x2dbb68 <_ZN16b2VoronoiDiagramD2Ev>
 *   @0x2dba64 ldr r12, [sp, #0x8]
 *   @0x2dba68 ldr r2, [r12, #0x8]
 *   @0x2dba6c b 0x2db9d4 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x334>
 *   @0x2dba70 cmp r0, #0
 *   @0x2dba74 lslne r1, r0, #1
 *   @0x2dba78 strne r1, [sp, #0x14]
 *   @0x2dba7c moveq r2, #256
 *   @0x2dba80 addne r1, r1, r0, lsl #3
 *   @0x2dba84 streq r2, [sp, #0x14]
 *   @0x2dba88 moveq r1, #5120
 *   @0x2dba8c ldr r2, [r11, #0x94]
 *   @0x2dba90 lslne r1, r1, #2
 *   @0x2dba94 ldr r0, [r11, #0xd4]
 *   @0x2dba98 str r12, [sp]
 *   @0x2dba9c str r2, [sp, #0xc]
 *   @0x2dbaa0 str r3, [sp, #0x4]
 *   @0x2dbaa4 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2dbaa8 ldr r3, [sp, #0x4]
 *   @0x2dbaac ldr r1, [sp, #0xc]
 *   @0x2dbab0 add r3, r3, r3, lsl #2
 *   @0x2dbab4 lsl r3, r3, #2
 *   @0x2dbab8 str r3, [sp, #0x4]
 *   @0x2dbabc mov r2, r3
 *   @0x2dbac0 str r0, [sp, #0x10]
 *   @0x2dbac4 bl 0xb65bc <memcpy@plt>
 *   @0x2dbac8 ldr r3, [sp, #0x4]
 *   @0x2dbacc ldr r0, [r11, #0xd4]
 *   @0x2dbad0 ldr r1, [sp, #0xc]
 *   @0x2dbad4 mov r2, r3
 *   @0x2dbad8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2dbadc ldr r2, [sp, #0x10]
 *   @0x2dbae0 ldr r3, [sp, #0x14]
 *   @0x2dbae4 ldr r0, [r11, #0x8c]
 *   @0x2dbae8 str r2, [r11, #0x94]
 *   @0x2dbaec str r3, [r11, #0x90]
 *   @0x2dbaf0 ldr r12, [sp]
 *   @0x2dbaf4 b 0x2db7a8 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x108>
 *   @0x2dbaf8 mov r0, r11
 *   @0x2dbafc mov r1, #1
 *   @0x2dbb00 bl 0x2da664 <_ZN16b2ParticleSystem14UpdateContactsEb>
 *   @0x2dbb04 ldr r12, [sp, #0x8]
 *   @0x2dbb08 ldr r2, [r12, #0x8]
 *   @0x2dbb0c b 0x2db9d4 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x334>
 *   @0x2dbb10 vmov r0, s14
 *   @0x2dbb14 str r12, [sp]
 *   @0x2dbb18 bl 0xb6700 <sqrtf@plt>
 *   @0x2dbb1c ldr r12, [sp]
 *   @0x2dbb20 vmov s15, r0
 *   @0x2dbb24 ldr r0, [r11, #0x8c]
 *   @0x2dbb28 b 0x2db814 <_ZN16b2ParticleSystem18JoinParticleGroupsEP15b2ParticleGroupS1_+0x174>
 *
 * ══ §16/29 CreateColPairs()  0x19e1cc  size 1156  289 条（0x19e1cc..0x19e650）
 * @func 0x19e1cc 0x19e650  size 1156  289 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x19e1d0→0x536f64, 0x19e1e0→0x536f68, 0x19e1e8→0x542370, 0x19e228→0x542374, 0x19e2ac→0x542374, 0x19e4f4→0x542379
 * 调用序列: Object_Exists(int)×3 / CObjectGM::GetEventRecursive(int, int)×2 / CreateColPairs()+0x1bc / CreateColPairs()+0x1c4 / CreateColPairs()+0x304 / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×24 / 0x8×13 / 0xc×12 / 0x3×9 / 0x460×2 / 0x454×1 / 0x450×1 / 0x414×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19e1cc ldr r0, [pc, #0x460]
 *   @0x19e1d0 ldr r1, [pc, #0x460]
 *   @0x19e1d4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x19e1d8 add r0, pc, r0
 *   @0x19e1dc sub sp, sp, #20
 *   @0x19e1e0 ldr r2, [pc, #0x454]
 *   @0x19e1e4 mov r7, #0
 *   @0x19e1e8 ldr r3, [pc, #0x450]
 *   @0x19e1ec str r0, [sp, #0x4]
 *   @0x19e1f0 ldr r8, [r0, r1]
 *   @0x19e1f4 str r7, [r8]
 *   @0x19e1f8 ldr r5, [r0, r2]
 *   @0x19e1fc str r7, [r5]
 *   @0x19e200 str r7, [r5, #0x4]
 *   @0x19e204 ldr r3, [r0, r3]
 *   @0x19e208 ldr r6, [r3]
 *   @0x19e20c cmp r6, r7
 *   @0x19e210 ble 0x19e388 <_Z14CreateColPairsv+0x1bc>
 *   @0x19e214 mov r9, r0
 *   @0x19e218 mov r0, r7
 *   @0x19e21c bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x19e220 cmp r0, #0
 *   @0x19e224 beq 0x19e278 <_Z14CreateColPairsv+0xac>
 *   @0x19e228 ldr r3, [pc, #0x414]
 *   @0x19e22c ldr r4, [r9, r3]
 *   @0x19e230 ldr r3, [r4]
 *   @0x19e234 ldr r2, [r3, #0x4]
 *   @0x19e238 ldr r3, [r3]
 *   @0x19e23c and r2, r7, r2
 *   @0x19e240 ldr r3, [r3, r2, lsl #3]
 *   @0x19e244 cmp r3, #0
 *   @0x19e248 bne 0x19e25c <_Z14CreateColPairsv+0x90>
 *   @0x19e24c b 0x19e26c <_Z14CreateColPairsv+0xa0>
 *   @0x19e250 ldr r3, [r3, #0x4]
 *   @0x19e254 cmp r3, #0
 *   @0x19e258 beq 0x19e26c <_Z14CreateColPairsv+0xa0>
 *   @0x19e25c ldr r2, [r3, #0x8]
 *   @0x19e260 cmp r7, r2
 *   @0x19e264 bne 0x19e250 <_Z14CreateColPairsv+0x84>
 *   @0x19e268 ldr r3, [r3, #0xc]
 *   @0x19e26c ldrb r2, [r3, #0x1c]
 *   @0x19e270 cmp r2, #0
 *   @0x19e274 beq 0x19e4f4 <_Z14CreateColPairsv+0x328>
 *   @0x19e278 add r7, r7, #1
 *   @0x19e27c cmp r7, r6
 *   @0x19e280 bne 0x19e218 <_Z14CreateColPairsv+0x4c>
 *   @0x19e284 ldr r2, [pc, #0x3bc]
 *   @0x19e288 mov r9, #0
 *   @0x19e28c add r1, r5, #4
 *   @0x19e290 str r1, [sp, #0x8]
 *   @0x19e294 add r2, pc, r2
 *   @0x19e298 str r2, [sp, #0xc]
 *   @0x19e29c mov r0, r9
 *   @0x19e2a0 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x19e2a4 cmp r0, #0
 *   @0x19e2a8 beq 0x19e37c <_Z14CreateColPairsv+0x1b0>
 *   @0x19e2ac ldr r3, [pc, #0x390]
 *   @0x19e2b0 ldr r1, [sp, #0x4]
 *   @0x19e2b4 ldr r3, [r1, r3]
 *   @0x19e2b8 str r3, [sp]
 *   @0x19e2bc ldr r3, [r3]
 *   @0x19e2c0 ldr r2, [r3, #0x4]
 *   @0x19e2c4 ldr r3, [r3]
 *   @0x19e2c8 and r2, r9, r2
 *   @0x19e2cc ldr r7, [r3, r2, lsl #3]
 *   @0x19e2d0 cmp r7, #0
 *   @0x19e2d4 bne 0x19e2e8 <_Z14CreateColPairsv+0x11c>
 *   @0x19e2d8 b 0x19e2f8 <_Z14CreateColPairsv+0x12c>
 *   @0x19e2dc ldr r7, [r7, #0x4]
 *   @0x19e2e0 cmp r7, #0
 *   @0x19e2e4 beq 0x19e2f8 <_Z14CreateColPairsv+0x12c>
 *   @0x19e2e8 ldr r3, [r7, #0x8]
 *   @0x19e2ec cmp r9, r3
 *   @0x19e2f0 bne 0x19e2dc <_Z14CreateColPairsv+0x110>
 *   @0x19e2f4 ldr r7, [r7, #0xc]
 *   @0x19e2f8 mov r4, #0
 *   @0x19e2fc mov r0, r7
 *   @0x19e300 mov r1, #4
 *   @0x19e304 mov r2, r4
 *   @0x19e308 bl 0x19daf4 <_ZN9CObjectGM17GetEventRecursiveEii>
 *   @0x19e30c cmp r0, #0
 *   @0x19e310 beq 0x19e370 <_Z14CreateColPairsv+0x1a4>
 *   @0x19e314 cmp r4, r9
 *   @0x19e318 ldr r0, [r5]
 *   @0x19e31c movgt r11, r4
 *   @0x19e320 movgt r10, r9
 *   @0x19e324 movle r11, r9
 *   @0x19e328 movle r10, r4
 *   @0x19e32c cmp r0, #0
 *   @0x19e330 ble 0x19e390 <_Z14CreateColPairsv+0x1c4>
 *   @0x19e334 mov r3, #0
 *   @0x19e338 ldr r2, [r5, #0x4]
 *   @0x19e33c mov r1, r3
 *   @0x19e340 b 0x19e350 <_Z14CreateColPairsv+0x184>
 *   @0x19e344 cmp r1, r0
 *   @0x19e348 add r3, r3, #20
 *   @0x19e34c beq 0x19e390 <_Z14CreateColPairsv+0x1c4>
 *   @0x19e350 ldr r12, [r2, r3]
 *   @0x19e354 add r1, r1, #1
 *   @0x19e358 cmp r12, r10
 *   @0x19e35c bne 0x19e344 <_Z14CreateColPairsv+0x178>
 *   @0x19e360 add r12, r2, r3
 *   @0x19e364 ldr r12, [r12, #0x4]
 *   @0x19e368 cmp r12, r11
 *   @0x19e36c bne 0x19e344 <_Z14CreateColPairsv+0x178>
 *   @0x19e370 add r4, r4, #1
 *   @0x19e374 cmp r4, r6
 *   @0x19e378 bne 0x19e2fc <_Z14CreateColPairsv+0x130>
 *   @0x19e37c add r9, r9, #1
 *   @0x19e380 cmp r9, r6
 *   @0x19e384 bne 0x19e29c <_Z14CreateColPairsv+0xd0>
 *   @0x19e388 add sp, sp, #20
 *   @0x19e38c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19e390 ldr r3, [r8]
 *   @0x19e394 cmp r0, r3
 *   @0x19e398 ble 0x19e4d0 <_Z14CreateColPairsv+0x304>
 *   @0x19e39c ldr r2, [sp]
 *   @0x19e3a0 ldr r1, [r2]
 *   @0x19e3a4 ldr r2, [r1, #0x4]
 *   @0x19e3a8 ldr r3, [r1]
 *   @0x19e3ac and r2, r9, r2
 *   @0x19e3b0 ldr r3, [r3, r2, lsl #3]
 *   @0x19e3b4 cmp r3, #0
 *   @0x19e3b8 bne 0x19e3cc <_Z14CreateColPairsv+0x200>
 *   @0x19e3bc b 0x19e3dc <_Z14CreateColPairsv+0x210>
 *   @0x19e3c0 ldr r3, [r3, #0x4]
 *   @0x19e3c4 cmp r3, #0
 *   @0x19e3c8 beq 0x19e3dc <_Z14CreateColPairsv+0x210>
 *   @0x19e3cc ldr r2, [r3, #0x8]
 *   @0x19e3d0 cmp r9, r2
 *   @0x19e3d4 bne 0x19e3c0 <_Z14CreateColPairsv+0x1f4>
 *   @0x19e3d8 ldr r3, [r3, #0xc]
 *   @0x19e3dc ldr r2, [r3]
 *   @0x19e3e0 orr r2, r2, #8
 *   @0x19e3e4 str r2, [r3]
 *   @0x19e3e8 ldr r2, [r1, #0x4]
 *   @0x19e3ec ldr r3, [r1]
 *   @0x19e3f0 and r2, r4, r2
 *   @0x19e3f4 ldr r3, [r3, r2, lsl #3]
 *   @0x19e3f8 cmp r3, #0
 *   @0x19e3fc bne 0x19e410 <_Z14CreateColPairsv+0x244>
 *   @0x19e400 b 0x19e420 <_Z14CreateColPairsv+0x254>
 *   @0x19e404 ldr r3, [r3, #0x4]
 *   @0x19e408 cmp r3, #0
 *   @0x19e40c beq 0x19e420 <_Z14CreateColPairsv+0x254>
 *   @0x19e410 ldr r2, [r3, #0x8]
 *   @0x19e414 cmp r4, r2
 *   @0x19e418 bne 0x19e404 <_Z14CreateColPairsv+0x238>
 *   @0x19e41c ldr r3, [r3, #0xc]
 *   @0x19e420 ldr r2, [r3]
 *   @0x19e424 ldr r10, [r5, #0x4]
 *   @0x19e428 orr r2, r2, #8
 *   @0x19e42c str r2, [r3]
 *   @0x19e430 ldm r1, {r0, r12}
 *   @0x19e434 ldr r1, [r8]
 *   @0x19e438 and r3, r9, r12
 *   @0x19e43c add r11, r1, r1, lsl #2
 *   @0x19e440 ldr r3, [r0, r3, lsl #3]
 *   @0x19e444 add r2, r10, r11, lsl #2
 *   @0x19e448 cmp r3, #0
 *   @0x19e44c str r9, [r10, r11, lsl #2]
 *   @0x19e450 str r4, [r2, #0x4]
 *   @0x19e454 bne 0x19e468 <_Z14CreateColPairsv+0x29c>
 *   @0x19e458 b 0x19e478 <_Z14CreateColPairsv+0x2ac>
 *   @0x19e45c ldr r3, [r3, #0x4]
 *   @0x19e460 cmp r3, #0
 *   @0x19e464 beq 0x19e478 <_Z14CreateColPairsv+0x2ac>
 *   @0x19e468 ldr r10, [r3, #0x8]
 *   @0x19e46c cmp r9, r10
 *   @0x19e470 bne 0x19e45c <_Z14CreateColPairsv+0x290>
 *   @0x19e474 ldr r3, [r3, #0xc]
 *   @0x19e478 and r12, r4, r12
 *   @0x19e47c str r3, [r2, #0x8]
 *   @0x19e480 ldr r3, [r0, r12, lsl #3]
 *   @0x19e484 cmp r3, #0
 *   @0x19e488 bne 0x19e49c <_Z14CreateColPairsv+0x2d0>
 *   @0x19e48c b 0x19e4ac <_Z14CreateColPairsv+0x2e0>
 *   @0x19e490 ldr r3, [r3, #0x4]
 *   @0x19e494 cmp r3, #0
 *   @0x19e498 beq 0x19e4ac <_Z14CreateColPairsv+0x2e0>
 *   @0x19e49c ldr r0, [r3, #0x8]
 *   @0x19e4a0 cmp r4, r0
 *   @0x19e4a4 bne 0x19e490 <_Z14CreateColPairsv+0x2c4>
 *   @0x19e4a8 ldr r3, [r3, #0xc]
 *   @0x19e4ac add r4, r4, #1
 *   @0x19e4b0 add r1, r1, #1
 *   @0x19e4b4 cmp r4, r6
 *   @0x19e4b8 str r3, [r2, #0xc]
 *   @0x19e4bc str r1, [r8]
 *   @0x19e4c0 mov r3, #1
 *   @0x19e4c4 strb r3, [r2, #0x10]
 *   @0x19e4c8 bne 0x19e2fc <_Z14CreateColPairsv+0x130>
 *   @0x19e4cc b 0x19e37c <_Z14CreateColPairsv+0x1b0>
 *   @0x19e4d0 add r12, r3, #5
 *   @0x19e4d4 ldr r0, [sp, #0x8]
 *   @0x19e4d8 ldr r2, [sp, #0xc]
 *   @0x19e4dc mov r3, #90
 *   @0x19e4e0 add r1, r12, r12, lsl #2
 *   @0x19e4e4 str r12, [r5]
 *   @0x19e4e8 lsl r1, r1, #2
 *   @0x19e4ec bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x19e4f0 b 0x19e39c <_Z14CreateColPairsv+0x1d0>
 *   @0x19e4f4 ldr r3, [pc, #0x150]
 *   @0x19e4f8 ldr r0, [sp, #0x4]
 *   @0x19e4fc ldr r3, [r0, r3]
 *   @0x19e500 ldrb r3, [r3]
 *   @0x19e504 cmp r3, #0
 *   @0x19e508 movne r8, r2
 *   @0x19e50c beq 0x19e284 <_Z14CreateColPairsv+0xb8>
 *   @0x19e510 mov r0, r8
 *   @0x19e514 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x19e518 cmp r0, #0
 *   @0x19e51c beq 0x19e618 <_Z14CreateColPairsv+0x44c>
 *   @0x19e520 ldr r3, [r4]
 *   @0x19e524 ldr r2, [r3, #0x4]
 *   @0x19e528 ldr r3, [r3]
 *   @0x19e52c and r2, r8, r2
 *   @0x19e530 ldr r7, [r3, r2, lsl #3]
 *   @0x19e534 cmp r7, #0
 *   @0x19e538 bne 0x19e54c <_Z14CreateColPairsv+0x380>
 *   @0x19e53c b 0x19e55c <_Z14CreateColPairsv+0x390>
 *   @0x19e540 ldr r7, [r7, #0x4]
 *   @0x19e544 cmp r7, #0
 *   @0x19e548 beq 0x19e55c <_Z14CreateColPairsv+0x390>
 *   @0x19e54c ldr r3, [r7, #0x8]
 *   @0x19e550 cmp r8, r3
 *   @0x19e554 bne 0x19e540 <_Z14CreateColPairsv+0x374>
 *   @0x19e558 ldr r7, [r7, #0xc]
 *   @0x19e55c mov r5, #0
 *   @0x19e560 mov r0, r7
 *   @0x19e564 mov r1, #4
 *   @0x19e568 mov r2, r5
 *   @0x19e56c bl 0x19daf4 <_ZN9CObjectGM17GetEventRecursiveEii>
 *   @0x19e570 cmp r0, #0
 *   @0x19e574 beq 0x19e60c <_Z14CreateColPairsv+0x440>
 *   @0x19e578 ldr r2, [r4]
 *   @0x19e57c ldr r1, [r2, #0x4]
 *   @0x19e580 ldr r3, [r2]
 *   @0x19e584 and r1, r8, r1
 *   @0x19e588 ldr r3, [r3, r1, lsl #3]
 *   @0x19e58c cmp r3, #0
 *   @0x19e590 bne 0x19e5a4 <_Z14CreateColPairsv+0x3d8>
 *   @0x19e594 b 0x19e5b4 <_Z14CreateColPairsv+0x3e8>
 *   @0x19e598 ldr r3, [r3, #0x4]
 *   @0x19e59c cmp r3, #0
 *   @0x19e5a0 beq 0x19e5b4 <_Z14CreateColPairsv+0x3e8>
 *   @0x19e5a4 ldr r1, [r3, #0x8]
 *   @0x19e5a8 cmp r8, r1
 *   @0x19e5ac bne 0x19e598 <_Z14CreateColPairsv+0x3cc>
 *   @0x19e5b0 ldr r3, [r3, #0xc]
 *   @0x19e5b4 ldr r1, [r3]
 *   @0x19e5b8 orr r1, r1, #8
 *   @0x19e5bc str r1, [r3]
 *   @0x19e5c0 ldr r1, [r2, #0x4]
 *   @0x19e5c4 ldr r3, [r2]
 *   @0x19e5c8 and r2, r5, r1
 *   @0x19e5cc ldr r3, [r3, r2, lsl #3]
 *   @0x19e5d0 cmp r3, #0
 *   @0x19e5d4 beq 0x19e600 <_Z14CreateColPairsv+0x434>
 *   @0x19e5d8 ldr r2, [r3, #0x8]
 *   @0x19e5dc cmp r5, r2
 *   @0x19e5e0 bne 0x19e5f4 <_Z14CreateColPairsv+0x428>
 *   @0x19e5e4 b 0x19e62c <_Z14CreateColPairsv+0x460>
 *   @0x19e5e8 ldr r1, [r3, #0x8]
 *   @0x19e5ec cmp r5, r1
 *   @0x19e5f0 beq 0x19e62c <_Z14CreateColPairsv+0x460>
 *   @0x19e5f4 ldr r3, [r3, #0x4]
 *   @0x19e5f8 cmp r3, #0
 *   @0x19e5fc bne 0x19e5e8 <_Z14CreateColPairsv+0x41c>
 *   @0x19e600 ldr r2, [r3]
 *   @0x19e604 orr r2, r2, #8
 *   @0x19e608 str r2, [r3]
 *   @0x19e60c add r5, r5, #1
 *   @0x19e610 cmp r5, r6
 *   @0x19e614 bne 0x19e560 <_Z14CreateColPairsv+0x394>
 *   @0x19e618 add r8, r8, #1
 *   @0x19e61c cmp r8, r6
 *   @0x19e620 bne 0x19e510 <_Z14CreateColPairsv+0x344>
 *   @0x19e624 add sp, sp, #20
 *   @0x19e628 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19e62c ldr r3, [r3, #0xc]
 *   @0x19e630 b 0x19e600 <_Z14CreateColPairsv+0x434>
 *   @0x19e634 eoreq r3, r5, r8, ror r10
 *   @0x19e638 .word 0xffffea8c
 *   @0x19e63c .word 0xffffea90
 *   @0x19e640 .word 0xffffea94
 *   @0x19e644 .word 0xffffbfec
 *   @0x19e648 andseq lr, r10, r12, asr #23
 *   @0x19e64c .word 0xffffea30
 *
 * ══ §17/29 RVariable::Assign(RVariable const&)  0x1f6f80  size 1156  289 条（0x1f6f80..0x1f7404）
 * @func 0x1f6f80 0x1f7404  size 1156  289 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×8 / UNLOCK_RVALUE_MUTEX()×8 / YYFree(void const*)×8 / operator delete(void*)×8 / GetContextStackTop()×2 / FREE_RValue__Pre(RValue*)×2 / _RefThing<char const*>::dec()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x8×24 / 0x4×17 / 0x18×14 / 0x24×5 / 0x14×5 / 0x20×3 / 0x10×3 / 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f6f80 push {r4, r5, r6, r7, r8, lr}
 *   @0x1f6f84 mov r5, r1
 *   @0x1f6f88 ldr r1, [r0, #0x24]
 *   @0x1f6f8c mov r3, #0
 *   @0x1f6f90 mov r4, r0
 *   @0x1f6f94 add r7, r0, #24
 *   @0x1f6f98 bic r2, r1, #-16777216
 *   @0x1f6f9c str r3, [r0]
 *   @0x1f6fa0 cmp r2, #1
 *   @0x1f6fa4 str r3, [r0, #0x4]
 *   @0x1f6fa8 beq 0x1f7124 <_ZN9RVariable6AssignERKS_+0x1a4>
 *   @0x1f6fac cmp r2, #2
 *   @0x1f6fb0 bne 0x1f6fd8 <_ZN9RVariable6AssignERKS_+0x58>
 *   @0x1f6fb4 sub r1, r1, #1
 *   @0x1f6fb8 bic r1, r1, #-16777216
 *   @0x1f6fbc bic r1, r1, #3
 *   @0x1f6fc0 cmp r1, #0
 *   @0x1f6fc4 beq 0x1f72cc <_ZN9RVariable6AssignERKS_+0x34c>
 *   @0x1f6fc8 mov r2, #0
 *   @0x1f6fcc mov r3, #5
 *   @0x1f6fd0 str r2, [r4, #0x20]
 *   @0x1f6fd4 str r3, [r4, #0x24]
 *   @0x1f6fd8 ldr r3, [r5, #0x24]
 *   @0x1f6fdc mov r1, #0
 *   @0x1f6fe0 ldr r2, [r5, #0x20]
 *   @0x1f6fe4 str r1, [r4, #0x18]
 *   @0x1f6fe8 str r3, [r4, #0x24]
 *   @0x1f6fec ldr r3, [r5, #0x24]
 *   @0x1f6ff0 str r2, [r4, #0x20]
 *   @0x1f6ff4 bic r3, r3, #-16777216
 *   @0x1f6ff8 cmp r3, #14
 *   @0x1f6ffc addls pc, pc, r3, lsl #2
 *   @0x1f7000 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8>
 *   @0x1f7004 b 0x1f70fc <_ZN9RVariable6AssignERKS_+0x17c>
 *   @0x1f7008 b 0x1f71b0 <_ZN9RVariable6AssignERKS_+0x230>
 *   @0x1f700c b 0x1f71c8 <_ZN9RVariable6AssignERKS_+0x248>
 *   @0x1f7010 b 0x1f7040 <_ZN9RVariable6AssignERKS_+0xc0>
 *   @0x1f7014 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8>
 *   @0x1f7018 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8>
 *   @0x1f701c b 0x1f718c <_ZN9RVariable6AssignERKS_+0x20c>
 *   @0x1f7020 b 0x1f7040 <_ZN9RVariable6AssignERKS_+0xc0>
 *   @0x1f7024 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8>
 *   @0x1f7028 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8>
 *   @0x1f702c b 0x1f70fc <_ZN9RVariable6AssignERKS_+0x17c>
 *   @0x1f7030 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8>
 *   @0x1f7034 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8>
 *   @0x1f7038 b 0x1f70fc <_ZN9RVariable6AssignERKS_+0x17c>
 *   @0x1f703c b 0x1f7040 <_ZN9RVariable6AssignERKS_+0xc0>
 *   @0x1f7040 ldr r3, [r5, #0x18]
 *   @0x1f7044 str r3, [r4, #0x18]
 *   @0x1f7048 ldr r2, [r4, #0x14]
 *   @0x1f704c add r7, r4, #8
 *   @0x1f7050 bic r3, r2, #-16777216
 *   @0x1f7054 cmp r3, #1
 *   @0x1f7058 beq 0x1f7158 <_ZN9RVariable6AssignERKS_+0x1d8>
 *   @0x1f705c cmp r3, #2
 *   @0x1f7060 bne 0x1f7088 <_ZN9RVariable6AssignERKS_+0x108>
 *   @0x1f7064 sub r2, r2, #1
 *   @0x1f7068 bic r2, r2, #-16777216
 *   @0x1f706c bic r2, r2, #3
 *   @0x1f7070 cmp r2, #0
 *   @0x1f7074 beq 0x1f72d8 <_ZN9RVariable6AssignERKS_+0x358>
 *   @0x1f7078 mov r2, #0
 *   @0x1f707c mov r3, #5
 *   @0x1f7080 str r2, [r4, #0x10]
 *   @0x1f7084 str r3, [r4, #0x14]
 *   @0x1f7088 ldr r3, [r5, #0x14]
 *   @0x1f708c mov r1, #0
 *   @0x1f7090 ldr r2, [r5, #0x10]
 *   @0x1f7094 str r1, [r4, #0x8]
 *   @0x1f7098 str r3, [r4, #0x14]
 *   @0x1f709c ldr r3, [r5, #0x14]
 *   @0x1f70a0 str r2, [r4, #0x10]
 *   @0x1f70a4 bic r3, r3, #-16777216
 *   @0x1f70a8 cmp r3, #14
 *   @0x1f70ac addls pc, pc, r3, lsl #2
 *   @0x1f70b0 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178>
 *   @0x1f70b4 b 0x1f7110 <_ZN9RVariable6AssignERKS_+0x190>
 *   @0x1f70b8 b 0x1f71f4 <_ZN9RVariable6AssignERKS_+0x274>
 *   @0x1f70bc b 0x1f7230 <_ZN9RVariable6AssignERKS_+0x2b0>
 *   @0x1f70c0 b 0x1f70f0 <_ZN9RVariable6AssignERKS_+0x170>
 *   @0x1f70c4 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178>
 *   @0x1f70c8 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178>
 *   @0x1f70cc b 0x1f720c <_ZN9RVariable6AssignERKS_+0x28c>
 *   @0x1f70d0 b 0x1f70f0 <_ZN9RVariable6AssignERKS_+0x170>
 *   @0x1f70d4 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178>
 *   @0x1f70d8 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178>
 *   @0x1f70dc b 0x1f7110 <_ZN9RVariable6AssignERKS_+0x190>
 *   @0x1f70e0 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178>
 *   @0x1f70e4 b 0x1f70f8 <_ZN9RVariable6AssignERKS_+0x178>
 *   @0x1f70e8 b 0x1f7110 <_ZN9RVariable6AssignERKS_+0x190>
 *   @0x1f70ec b 0x1f70f0 <_ZN9RVariable6AssignERKS_+0x170>
 *   @0x1f70f0 ldr r3, [r5, #0x8]
 *   @0x1f70f4 str r3, [r4, #0x8]
 *   @0x1f70f8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f70fc ldr r2, [r5, #0x18]
 *   @0x1f7100 ldr r3, [r5, #0x1c]
 *   @0x1f7104 str r2, [r4, #0x18]
 *   @0x1f7108 str r3, [r4, #0x1c]
 *   @0x1f710c b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8>
 *   @0x1f7110 ldr r2, [r5, #0x8]
 *   @0x1f7114 ldr r3, [r5, #0xc]
 *   @0x1f7118 str r2, [r4, #0x8]
 *   @0x1f711c str r3, [r4, #0xc]
 *   @0x1f7120 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f7124 ldr r6, [r0, #0x18]
 *   @0x1f7128 cmp r6, #0
 *   @0x1f712c beq 0x1f714c <_ZN9RVariable6AssignERKS_+0x1cc>
 *   @0x1f7130 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f7134 ldr r8, [r6, #0x4]
 *   @0x1f7138 sub r8, r8, #1
 *   @0x1f713c str r8, [r6, #0x4]
 *   @0x1f7140 cmp r8, #0
 *   @0x1f7144 beq 0x1f725c <_ZN9RVariable6AssignERKS_+0x2dc>
 *   @0x1f7148 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f714c mov r3, #0
 *   @0x1f7150 str r3, [r4, #0x18]
 *   @0x1f7154 b 0x1f6fd8 <_ZN9RVariable6AssignERKS_+0x58>
 *   @0x1f7158 ldr r6, [r4, #0x8]
 *   @0x1f715c cmp r6, #0
 *   @0x1f7160 beq 0x1f7180 <_ZN9RVariable6AssignERKS_+0x200>
 *   @0x1f7164 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f7168 ldr r8, [r6, #0x4]
 *   @0x1f716c sub r8, r8, #1
 *   @0x1f7170 str r8, [r6, #0x4]
 *   @0x1f7174 cmp r8, #0
 *   @0x1f7178 beq 0x1f7294 <_ZN9RVariable6AssignERKS_+0x314>
 *   @0x1f717c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f7180 mov r3, #0
 *   @0x1f7184 str r3, [r4, #0x8]
 *   @0x1f7188 b 0x1f7088 <_ZN9RVariable6AssignERKS_+0x108>
 *   @0x1f718c ldr r3, [r5, #0x18]
 *   @0x1f7190 str r3, [r4, #0x18]
 *   @0x1f7194 ldr r3, [r5, #0x18]
 *   @0x1f7198 cmp r3, #0
 *   @0x1f719c beq 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8>
 *   @0x1f71a0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1f71a4 ldr r1, [r5, #0x18]
 *   @0x1f71a8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1f71ac b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8>
 *   @0x1f71b0 ldr r3, [r5, #0x18]
 *   @0x1f71b4 cmp r3, #0
 *   @0x1f71b8 ldrne r2, [r3, #0x4]
 *   @0x1f71bc addne r2, r2, #1
 *   @0x1f71c0 strne r2, [r3, #0x4]
 *   @0x1f71c4 b 0x1f7044 <_ZN9RVariable6AssignERKS_+0xc4>
 *   @0x1f71c8 ldr r3, [r5, #0x18]
 *   @0x1f71cc cmp r3, #0
 *   @0x1f71d0 str r3, [r4, #0x18]
 *   @0x1f71d4 beq 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8>
 *   @0x1f71d8 ldr r1, [r3, #0x8]
 *   @0x1f71dc ldr r2, [r3]
 *   @0x1f71e0 cmp r1, #0
 *   @0x1f71e4 streq r7, [r3, #0x8]
 *   @0x1f71e8 add r2, r2, #1
 *   @0x1f71ec str r2, [r3]
 *   @0x1f71f0 b 0x1f7048 <_ZN9RVariable6AssignERKS_+0xc8>
 *   @0x1f71f4 ldr r3, [r5, #0x8]
 *   @0x1f71f8 cmp r3, #0
 *   @0x1f71fc ldrne r2, [r3, #0x4]
 *   @0x1f7200 addne r2, r2, #1
 *   @0x1f7204 strne r2, [r3, #0x4]
 *   @0x1f7208 b 0x1f70f4 <_ZN9RVariable6AssignERKS_+0x174>
 *   @0x1f720c ldr r3, [r5, #0x8]
 *   @0x1f7210 str r3, [r4, #0x8]
 *   @0x1f7214 ldr r3, [r5, #0x8]
 *   @0x1f7218 cmp r3, #0
 *   @0x1f721c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1f7220 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1f7224 ldr r1, [r5, #0x8]
 *   @0x1f7228 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1f722c b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1f7230 ldr r3, [r5, #0x8]
 *   @0x1f7234 cmp r3, #0
 *   @0x1f7238 str r3, [r4, #0x8]
 *   @0x1f723c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1f7240 ldr r1, [r3, #0x8]
 *   @0x1f7244 ldr r2, [r3]
 *   @0x1f7248 cmp r1, #0
 *   @0x1f724c streq r7, [r3, #0x8]
 *   @0x1f7250 add r2, r2, #1
 *   @0x1f7254 str r2, [r3]
 *   @0x1f7258 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f725c ldr r0, [r6]
 *   @0x1f7260 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f7264 str r8, [r6]
 *   @0x1f7268 str r8, [r6, #0x8]
 *   @0x1f726c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f7270 ldr r8, [r6, #0x4]
 *   @0x1f7274 sub r8, r8, #1
 *   @0x1f7278 str r8, [r6, #0x4]
 *   @0x1f727c cmp r8, #0
 *   @0x1f7280 beq 0x1f72e4 <_ZN9RVariable6AssignERKS_+0x364>
 *   @0x1f7284 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f7288 mov r0, r6
 *   @0x1f728c bl 0x27d1d0 <_ZdlPv>
 *   @0x1f7290 b 0x1f7148 <_ZN9RVariable6AssignERKS_+0x1c8>
 *   @0x1f7294 ldr r0, [r6]
 *   @0x1f7298 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f729c str r8, [r6]
 *   @0x1f72a0 str r8, [r6, #0x8]
 *   @0x1f72a4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f72a8 ldr r8, [r6, #0x4]
 *   @0x1f72ac sub r8, r8, #1
 *   @0x1f72b0 str r8, [r6, #0x4]
 *   @0x1f72b4 cmp r8, #0
 *   @0x1f72b8 beq 0x1f731c <_ZN9RVariable6AssignERKS_+0x39c>
 *   @0x1f72bc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f72c0 mov r0, r6
 *   @0x1f72c4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f72c8 b 0x1f717c <_ZN9RVariable6AssignERKS_+0x1fc>
 *   @0x1f72cc mov r0, r7
 *   @0x1f72d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f72d4 b 0x1f6fc8 <_ZN9RVariable6AssignERKS_+0x48>
 *   @0x1f72d8 mov r0, r7
 *   @0x1f72dc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f72e0 b 0x1f7078 <_ZN9RVariable6AssignERKS_+0xf8>
 *   @0x1f72e4 ldr r0, [r6]
 *   @0x1f72e8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f72ec str r8, [r6]
 *   @0x1f72f0 str r8, [r6, #0x8]
 *   @0x1f72f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f72f8 ldr r8, [r6, #0x4]
 *   @0x1f72fc sub r8, r8, #1
 *   @0x1f7300 str r8, [r6, #0x4]
 *   @0x1f7304 cmp r8, #0
 *   @0x1f7308 beq 0x1f7354 <_ZN9RVariable6AssignERKS_+0x3d4>
 *   @0x1f730c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f7310 mov r0, r6
 *   @0x1f7314 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f7318 b 0x1f7284 <_ZN9RVariable6AssignERKS_+0x304>
 *   @0x1f731c ldr r0, [r6]
 *   @0x1f7320 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f7324 str r8, [r6]
 *   @0x1f7328 str r8, [r6, #0x8]
 *   @0x1f732c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f7330 ldr r8, [r6, #0x4]
 *   @0x1f7334 sub r8, r8, #1
 *   @0x1f7338 str r8, [r6, #0x4]
 *   @0x1f733c cmp r8, #0
 *   @0x1f7340 beq 0x1f73ac <_ZN9RVariable6AssignERKS_+0x42c>
 *   @0x1f7344 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f7348 mov r0, r6
 *   @0x1f734c bl 0x27d1d0 <_ZdlPv>
 *   @0x1f7350 b 0x1f72bc <_ZN9RVariable6AssignERKS_+0x33c>
 *   @0x1f7354 ldr r0, [r6]
 *   @0x1f7358 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f735c str r8, [r6]
 *   @0x1f7360 str r8, [r6, #0x8]
 *   @0x1f7364 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f7368 ldr r8, [r6, #0x4]
 *   @0x1f736c sub r8, r8, #1
 *   @0x1f7370 str r8, [r6, #0x4]
 *   @0x1f7374 cmp r8, #0
 *   @0x1f7378 bne 0x1f739c <_ZN9RVariable6AssignERKS_+0x41c>
 *   @0x1f737c ldr r0, [r6]
 *   @0x1f7380 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f7384 mov r0, r6
 *   @0x1f7388 str r8, [r6]
 *   @0x1f738c str r8, [r6, #0x8]
 *   @0x1f7390 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1f7394 mov r0, r6
 *   @0x1f7398 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f739c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f73a0 mov r0, r6
 *   @0x1f73a4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f73a8 b 0x1f730c <_ZN9RVariable6AssignERKS_+0x38c>
 *   @0x1f73ac ldr r0, [r6]
 *   @0x1f73b0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f73b4 str r8, [r6]
 *   @0x1f73b8 str r8, [r6, #0x8]
 *   @0x1f73bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f73c0 ldr r8, [r6, #0x4]
 *   @0x1f73c4 sub r8, r8, #1
 *   @0x1f73c8 str r8, [r6, #0x4]
 *   @0x1f73cc cmp r8, #0
 *   @0x1f73d0 bne 0x1f73f4 <_ZN9RVariable6AssignERKS_+0x474>
 *   @0x1f73d4 ldr r0, [r6]
 *   @0x1f73d8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f73dc mov r0, r6
 *   @0x1f73e0 str r8, [r6]
 *   @0x1f73e4 str r8, [r6, #0x8]
 *   @0x1f73e8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1f73ec mov r0, r6
 *   @0x1f73f0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f73f4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f73f8 mov r0, r6
 *   @0x1f73fc bl 0x27d1d0 <_ZdlPv>
 *   @0x1f7400 b 0x1f7344 <_ZN9RVariable6AssignERKS_+0x3c4>
 *
 * ══ §18/29 CDS_Grid::Get_Disk_Max(RValue&, double, double, double)  0x207104  size 1156  289 条（0x207104..0x207588）
 * @func 0x207104 0x207588  size 1156  289 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / 0xb6598×2 / 0xb670c×2 / CDS_Grid::Get_Disk_Max(RValue&, double, double, double)+0x198 / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0xc×20 / 0x8×12 / 0x4×11 / 0x188×2 / 0x334×1 / 0x2f8×1
 * VFP 指令 52 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x207104 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x207108 vpush {d8, d9, d10, d11, d12}
 *   @0x20710c vmov d12, r2, r3
 *   @0x207110 sub sp, sp, #20
 *   @0x207114 vldr d11, [sp, #104]
 *   @0x207118 vsub.f64 d6, d12, d11
 *   @0x20711c mov r8, r0
 *   @0x207120 str r1, [sp, #0xc]
 *   @0x207124 vldr d10, [sp, #96]
 *   @0x207128 vmov r0, r1, d6
 *   @0x20712c bl 0xb6598 <floor@plt>
 *   @0x207130 ldr r3, [r8, #0x4]
 *   @0x207134 sub r3, r3, #1
 *   @0x207138 str r3, [sp, #0x8]
 *   @0x20713c vmov d7, r0, r1
 *   @0x207140 vcmpe.f64 d7, #0
 *   @0x207144 vmrs APSR_nzcv, fpscr
 *   @0x207148 vcvtpl.s32.f64 s13, d7
 *   @0x20714c movmi r9, #0
 *   @0x207150 vadd.f64 d7, d12, d11
 *   @0x207154 vmovpl r9, s13
 *   @0x207158 vmov r0, r1, d7
 *   @0x20715c bl 0xb670c <ceil@plt>
 *   @0x207160 vldr s11, [sp, #8]
 *   @0x207164 vcvt.f64.s32 d6, s11
 *   @0x207168 vmov d7, r0, r1
 *   @0x20716c vcmpe.f64 d6, d7
 *   @0x207170 vmrs APSR_nzcv, fpscr
 *   @0x207174 vcvtpl.s32.f64 s12, d7
 *   @0x207178 vsub.f64 d7, d10, d11
 *   @0x20717c vstrpl s12, [sp, #8]
 *   @0x207180 vmov r0, r1, d7
 *   @0x207184 bl 0xb6598 <floor@plt>
 *   @0x207188 ldr r7, [r8, #0x8]
 *   @0x20718c vadd.f64 d6, d10, d11
 *   @0x207190 sub r7, r7, #1
 *   @0x207194 vmov d7, r0, r1
 *   @0x207198 vcmpe.f64 d7, #0
 *   @0x20719c vmrs APSR_nzcv, fpscr
 *   @0x2071a0 vcvtpl.s32.f64 s11, d7
 *   @0x2071a4 movmi r0, #0
 *   @0x2071a8 strmi r0, [sp, #0x4]
 *   @0x2071ac vmov r0, r1, d6
 *   @0x2071b0 vstrpl s11, [sp, #4]
 *   @0x2071b4 bl 0xb670c <ceil@plt>
 *   @0x2071b8 vmov s11, r7
 *   @0x2071bc vcvt.f64.s32 d6, s11
 *   @0x2071c0 vmov d7, r0, r1
 *   @0x2071c4 ldr r0, [sp, #0x8]
 *   @0x2071c8 vcmpe.f64 d6, d7
 *   @0x2071cc vmrs APSR_nzcv, fpscr
 *   @0x2071d0 vcvtpl.s32.f64 s12, d7
 *   @0x2071d4 vmovpl r7, s12
 *   @0x2071d8 cmp r9, r0
 *   @0x2071dc bgt 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280>
 *   @0x2071e0 mov r6, #0
 *   @0x2071e4 mov r11, #1
 *   @0x2071e8 mov r10, r6
 *   @0x2071ec ldr r1, [sp, #0x4]
 *   @0x2071f0 cmp r1, r7
 *   @0x2071f4 bgt 0x2072a8 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x1a4>
 *   @0x2071f8 vmov s11, r9
 *   @0x2071fc mov r4, r1
 *   @0x207200 vmul.f64 d9, d11, d11
 *   @0x207204 vcvt.f64.s32 d8, s11
 *   @0x207208 vsub.f64 d8, d8, d12
 *   @0x20720c vmul.f64 d8, d8, d8
 *   @0x207210 vmov s11, r4
 *   @0x207214 vcvt.f64.s32 d7, s11
 *   @0x207218 vsub.f64 d7, d7, d10
 *   @0x20721c vmov.f64 d6, d8
 *   @0x207220 vmla.f64 d6, d7, d7
 *   @0x207224 vcmpe.f64 d9, d6
 *   @0x207228 vmrs APSR_nzcv, fpscr
 *   @0x20722c blt 0x20729c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x198>
 *   @0x207230 ldr r5, [r8, #0x4]
 *   @0x207234 cmp r11, #0
 *   @0x207238 ldr r2, [r8]
 *   @0x20723c ldr r3, [pc, #0x334]
 *   @0x207240 movne r11, #0
 *   @0x207244 mla r5, r5, r4, r9
 *   @0x207248 add r5, r2, r5, lsl #4
 *   @0x20724c movne r6, r5
 *   @0x207250 bne 0x20729c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x198>
 *   @0x207254 ldr r3, [pc, r3]
 *   @0x207258 ldrb r3, [r3]
 *   @0x20725c cmp r3, #0
 *   @0x207260 beq 0x20727c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x178>
 *   @0x207264 ldr r3, [r6, #0xc]
 *   @0x207268 cmp r3, #1
 *   @0x20726c ldr r3, [r5, #0xc]
 *   @0x207270 beq 0x207390 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x28c>
 *   @0x207274 cmp r3, #1
 *   @0x207278 moveq r10, #1
 *   @0x20727c ldr r3, [pc, #0x2f8]
 *   @0x207280 mov r0, r6
 *   @0x207284 mov r1, r5
 *   @0x207288 ldr r3, [pc, r3]
 *   @0x20728c ldrd r2, r3, [r3]
 *   @0x207290 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x207294 cmp r0, #0
 *   @0x207298 movlt r6, r5
 *   @0x20729c add r4, r4, #1
 *   @0x2072a0 cmp r7, r4
 *   @0x2072a4 bge 0x207210 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x10c>
 *   @0x2072a8 ldr r0, [sp, #0x8]
 *   @0x2072ac add r9, r9, #1
 *   @0x2072b0 cmp r0, r9
 *   @0x2072b4 bge 0x2071ec <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0xe8>
 *   @0x2072b8 cmp r6, #0
 *   @0x2072bc beq 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280>
 *   @0x2072c0 cmp r10, #0
 *   @0x2072c4 bne 0x2073f0 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x2ec>
 *   @0x2072c8 ldr r0, [sp, #0xc]
 *   @0x2072cc ldr r2, [r0, #0xc]
 *   @0x2072d0 bic r3, r2, #-16777216
 *   @0x2072d4 cmp r3, #1
 *   @0x2072d8 beq 0x2073b4 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x2b0>
 *   @0x2072dc cmp r3, #2
 *   @0x2072e0 bne 0x20730c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x208>
 *   @0x2072e4 sub r3, r2, #1
 *   @0x2072e8 bic r3, r3, #-16777216
 *   @0x2072ec bic r3, r3, #3
 *   @0x2072f0 cmp r3, #0
 *   @0x2072f4 beq 0x2074d8 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x3d4>
 *   @0x2072f8 ldr r0, [sp, #0xc]
 *   @0x2072fc mov r2, #0
 *   @0x207300 mov r3, #5
 *   @0x207304 str r2, [r0, #0x8]
 *   @0x207308 str r3, [r0, #0xc]
 *   @0x20730c ldr r3, [r6, #0xc]
 *   @0x207310 mov r1, #0
 *   @0x207314 ldr r0, [sp, #0xc]
 *   @0x207318 ldr r2, [r6, #0x8]
 *   @0x20731c str r3, [r0, #0xc]
 *   @0x207320 ldr r3, [r6, #0xc]
 *   @0x207324 str r1, [r0]
 *   @0x207328 bic r3, r3, #-16777216
 *   @0x20732c str r2, [r0, #0x8]
 *   @0x207330 cmp r3, #14
 *   @0x207334 addls pc, pc, r3, lsl #2
 *   @0x207338 b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280>
 *   @0x20733c b 0x20739c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x298>
 *   @0x207340 b 0x207444 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x340>
 *   @0x207344 b 0x20746c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x368>
 *   @0x207348 b 0x207378 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x274>
 *   @0x20734c b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280>
 *   @0x207350 b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280>
 *   @0x207354 b 0x207414 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x310>
 *   @0x207358 b 0x207378 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x274>
 *   @0x20735c b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280>
 *   @0x207360 b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280>
 *   @0x207364 b 0x20739c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x298>
 *   @0x207368 b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280>
 *   @0x20736c b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280>
 *   @0x207370 b 0x20739c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x298>
 *   @0x207374 b 0x207378 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x274>
 *   @0x207378 ldr r3, [r6]
 *   @0x20737c ldr r1, [sp, #0xc]
 *   @0x207380 str r3, [r1]
 *   @0x207384 add sp, sp, #20
 *   @0x207388 vpop {d8, d9, d10, d11, d12}
 *   @0x20738c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x207390 cmp r3, #1
 *   @0x207394 movne r10, #1
 *   @0x207398 b 0x20727c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x178>
 *   @0x20739c ldm r6, {r2, r3}
 *   @0x2073a0 ldr r0, [sp, #0xc]
 *   @0x2073a4 stm r0, {r2, r3}
 *   @0x2073a8 add sp, sp, #20
 *   @0x2073ac vpop {d8, d9, d10, d11, d12}
 *   @0x2073b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2073b4 ldr r1, [sp, #0xc]
 *   @0x2073b8 ldr r4, [r1]
 *   @0x2073bc cmp r4, #0
 *   @0x2073c0 beq 0x2073e0 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x2dc>
 *   @0x2073c4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2073c8 ldr r5, [r4, #0x4]
 *   @0x2073cc sub r5, r5, #1
 *   @0x2073d0 str r5, [r4, #0x4]
 *   @0x2073d4 cmp r5, #0
 *   @0x2073d8 beq 0x2074a0 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x39c>
 *   @0x2073dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2073e0 ldr r2, [sp, #0xc]
 *   @0x2073e4 mov r3, #0
 *   @0x2073e8 str r3, [r2]
 *   @0x2073ec b 0x20730c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x208>
 *   @0x2073f0 ldr r3, [pc, #0x188]
 *   @0x2073f4 ldr r1, [pc, #0x188]
 *   @0x2073f8 ldr r3, [pc, r3]
 *   @0x2073fc add r1, pc, r1
 *   @0x207400 ldr r0, [r3]
 *   @0x207404 ldr r3, [r0]
 *   @0x207408 ldr r3, [r3, #0xc]
 *   @0x20740c blx r3
 *   @0x207410 b 0x2072c8 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x1c4>
 *   @0x207414 ldr r3, [r6]
 *   @0x207418 ldr r0, [sp, #0xc]
 *   @0x20741c str r3, [r0]
 *   @0x207420 ldr r3, [r6]
 *   @0x207424 cmp r3, #0
 *   @0x207428 beq 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280>
 *   @0x20742c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x207430 ldr r1, [r6]
 *   @0x207434 add sp, sp, #20
 *   @0x207438 vpop {d8, d9, d10, d11, d12}
 *   @0x20743c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x207440 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x207444 ldr r3, [r6]
 *   @0x207448 cmp r3, #0
 *   @0x20744c ldrne r2, [r3, #0x4]
 *   @0x207450 addne r2, r2, #1
 *   @0x207454 strne r2, [r3, #0x4]
 *   @0x207458 ldr r2, [sp, #0xc]
 *   @0x20745c str r3, [r2]
 *   @0x207460 add sp, sp, #20
 *   @0x207464 vpop {d8, d9, d10, d11, d12}
 *   @0x207468 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20746c ldr r3, [r6]
 *   @0x207470 ldr r1, [sp, #0xc]
 *   @0x207474 cmp r3, #0
 *   @0x207478 str r3, [r1]
 *   @0x20747c beq 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280>
 *   @0x207480 ldr r1, [r3, #0x8]
 *   @0x207484 ldr r2, [r3]
 *   @0x207488 cmp r1, #0
 *   @0x20748c add r2, r2, #1
 *   @0x207490 str r2, [r3]
 *   @0x207494 ldreq r2, [sp, #0xc]
 *   @0x207498 streq r2, [r3, #0x8]
 *   @0x20749c b 0x207384 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x280>
 *   @0x2074a0 ldr r0, [r4]
 *   @0x2074a4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2074a8 str r5, [r4]
 *   @0x2074ac str r5, [r4, #0x8]
 *   @0x2074b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2074b4 ldr r5, [r4, #0x4]
 *   @0x2074b8 sub r5, r5, #1
 *   @0x2074bc str r5, [r4, #0x4]
 *   @0x2074c0 cmp r5, #0
 *   @0x2074c4 beq 0x2074e4 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x3e0>
 *   @0x2074c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2074cc mov r0, r4
 *   @0x2074d0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2074d4 b 0x2073dc <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x2d8>
 *   @0x2074d8 ldr r0, [sp, #0xc]
 *   @0x2074dc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2074e0 b 0x2072f8 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x1f4>
 *   @0x2074e4 ldr r0, [r4]
 *   @0x2074e8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2074ec str r5, [r4]
 *   @0x2074f0 str r5, [r4, #0x8]
 *   @0x2074f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2074f8 ldr r5, [r4, #0x4]
 *   @0x2074fc sub r5, r5, #1
 *   @0x207500 str r5, [r4, #0x4]
 *   @0x207504 cmp r5, #0
 *   @0x207508 beq 0x20751c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x418>
 *   @0x20750c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x207510 mov r0, r4
 *   @0x207514 bl 0x27d1d0 <_ZdlPv>
 *   @0x207518 b 0x2074c8 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x3c4>
 *   @0x20751c ldr r0, [r4]
 *   @0x207520 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x207524 str r5, [r4]
 *   @0x207528 str r5, [r4, #0x8]
 *   @0x20752c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x207530 ldr r5, [r4, #0x4]
 *   @0x207534 sub r5, r5, #1
 *   @0x207538 str r5, [r4, #0x4]
 *   @0x20753c cmp r5, #0
 *   @0x207540 beq 0x207554 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x450>
 *   @0x207544 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x207548 mov r0, r4
 *   @0x20754c bl 0x27d1d0 <_ZdlPv>
 *   @0x207550 b 0x20750c <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x408>
 *   @0x207554 ldr r0, [r4]
 *   @0x207558 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20755c mov r0, r4
 *   @0x207560 str r5, [r4]
 *   @0x207564 str r5, [r4, #0x8]
 *   @0x207568 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20756c mov r0, r4
 *   @0x207570 bl 0x27d1d0 <_ZdlPv>
 *   @0x207574 b 0x207544 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd+0x440>
 *   @0x207578 andseq r6, lr, r12, lsr r12
 *   @0x20757c ldrsheq r10, [lr], -r12
 *   @0x207580 andseq r6, lr, r8, asr #10
 *   @0x207584 andseq r12, r4, r4, lsr r4
 *
 * ══ §19/29 CDS_Grid::Get_Disk_Min(RValue&, double, double, double)  0x207588  size 1156  289 条（0x207588..0x207a0c）
 * @func 0x207588 0x207a0c  size 1156  289 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / 0xb6598×2 / 0xb670c×2 / CDS_Grid::Get_Disk_Min(RValue&, double, double, double)+0x198 / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0xc×20 / 0x8×12 / 0x4×11 / 0x188×2 / 0x334×1 / 0x2f8×1
 * VFP 指令 52 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x207588 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20758c vpush {d8, d9, d10, d11, d12}
 *   @0x207590 vmov d12, r2, r3
 *   @0x207594 sub sp, sp, #20
 *   @0x207598 vldr d11, [sp, #104]
 *   @0x20759c vsub.f64 d6, d12, d11
 *   @0x2075a0 mov r8, r0
 *   @0x2075a4 str r1, [sp, #0xc]
 *   @0x2075a8 vldr d10, [sp, #96]
 *   @0x2075ac vmov r0, r1, d6
 *   @0x2075b0 bl 0xb6598 <floor@plt>
 *   @0x2075b4 ldr r3, [r8, #0x4]
 *   @0x2075b8 sub r3, r3, #1
 *   @0x2075bc str r3, [sp, #0x8]
 *   @0x2075c0 vmov d7, r0, r1
 *   @0x2075c4 vcmpe.f64 d7, #0
 *   @0x2075c8 vmrs APSR_nzcv, fpscr
 *   @0x2075cc vcvtpl.s32.f64 s13, d7
 *   @0x2075d0 movmi r9, #0
 *   @0x2075d4 vadd.f64 d7, d12, d11
 *   @0x2075d8 vmovpl r9, s13
 *   @0x2075dc vmov r0, r1, d7
 *   @0x2075e0 bl 0xb670c <ceil@plt>
 *   @0x2075e4 vldr s11, [sp, #8]
 *   @0x2075e8 vcvt.f64.s32 d6, s11
 *   @0x2075ec vmov d7, r0, r1
 *   @0x2075f0 vcmpe.f64 d6, d7
 *   @0x2075f4 vmrs APSR_nzcv, fpscr
 *   @0x2075f8 vcvtpl.s32.f64 s12, d7
 *   @0x2075fc vsub.f64 d7, d10, d11
 *   @0x207600 vstrpl s12, [sp, #8]
 *   @0x207604 vmov r0, r1, d7
 *   @0x207608 bl 0xb6598 <floor@plt>
 *   @0x20760c ldr r7, [r8, #0x8]
 *   @0x207610 vadd.f64 d6, d10, d11
 *   @0x207614 sub r7, r7, #1
 *   @0x207618 vmov d7, r0, r1
 *   @0x20761c vcmpe.f64 d7, #0
 *   @0x207620 vmrs APSR_nzcv, fpscr
 *   @0x207624 vcvtpl.s32.f64 s11, d7
 *   @0x207628 movmi r0, #0
 *   @0x20762c strmi r0, [sp, #0x4]
 *   @0x207630 vmov r0, r1, d6
 *   @0x207634 vstrpl s11, [sp, #4]
 *   @0x207638 bl 0xb670c <ceil@plt>
 *   @0x20763c vmov s11, r7
 *   @0x207640 vcvt.f64.s32 d6, s11
 *   @0x207644 vmov d7, r0, r1
 *   @0x207648 ldr r0, [sp, #0x8]
 *   @0x20764c vcmpe.f64 d6, d7
 *   @0x207650 vmrs APSR_nzcv, fpscr
 *   @0x207654 vcvtpl.s32.f64 s12, d7
 *   @0x207658 vmovpl r7, s12
 *   @0x20765c cmp r9, r0
 *   @0x207660 bgt 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280>
 *   @0x207664 mov r6, #0
 *   @0x207668 mov r11, #1
 *   @0x20766c mov r10, r6
 *   @0x207670 ldr r1, [sp, #0x4]
 *   @0x207674 cmp r1, r7
 *   @0x207678 bgt 0x20772c <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x1a4>
 *   @0x20767c vmov s11, r9
 *   @0x207680 mov r4, r1
 *   @0x207684 vmul.f64 d9, d11, d11
 *   @0x207688 vcvt.f64.s32 d8, s11
 *   @0x20768c vsub.f64 d8, d8, d12
 *   @0x207690 vmul.f64 d8, d8, d8
 *   @0x207694 vmov s11, r4
 *   @0x207698 vcvt.f64.s32 d7, s11
 *   @0x20769c vsub.f64 d7, d7, d10
 *   @0x2076a0 vmov.f64 d6, d8
 *   @0x2076a4 vmla.f64 d6, d7, d7
 *   @0x2076a8 vcmpe.f64 d9, d6
 *   @0x2076ac vmrs APSR_nzcv, fpscr
 *   @0x2076b0 blt 0x207720 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x198>
 *   @0x2076b4 ldr r5, [r8, #0x4]
 *   @0x2076b8 cmp r11, #0
 *   @0x2076bc ldr r2, [r8]
 *   @0x2076c0 ldr r3, [pc, #0x334]
 *   @0x2076c4 movne r11, #0
 *   @0x2076c8 mla r5, r5, r4, r9
 *   @0x2076cc add r5, r2, r5, lsl #4
 *   @0x2076d0 movne r6, r5
 *   @0x2076d4 bne 0x207720 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x198>
 *   @0x2076d8 ldr r3, [pc, r3]
 *   @0x2076dc ldrb r3, [r3]
 *   @0x2076e0 cmp r3, #0
 *   @0x2076e4 beq 0x207700 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x178>
 *   @0x2076e8 ldr r3, [r6, #0xc]
 *   @0x2076ec cmp r3, #1
 *   @0x2076f0 ldr r3, [r5, #0xc]
 *   @0x2076f4 beq 0x207814 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x28c>
 *   @0x2076f8 cmp r3, #1
 *   @0x2076fc moveq r10, #1
 *   @0x207700 ldr r3, [pc, #0x2f8]
 *   @0x207704 mov r0, r6
 *   @0x207708 mov r1, r5
 *   @0x20770c ldr r3, [pc, r3]
 *   @0x207710 ldrd r2, r3, [r3]
 *   @0x207714 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x207718 cmp r0, #0
 *   @0x20771c movgt r6, r5
 *   @0x207720 add r4, r4, #1
 *   @0x207724 cmp r7, r4
 *   @0x207728 bge 0x207694 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x10c>
 *   @0x20772c ldr r0, [sp, #0x8]
 *   @0x207730 add r9, r9, #1
 *   @0x207734 cmp r0, r9
 *   @0x207738 bge 0x207670 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0xe8>
 *   @0x20773c cmp r6, #0
 *   @0x207740 beq 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280>
 *   @0x207744 cmp r10, #0
 *   @0x207748 bne 0x207874 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x2ec>
 *   @0x20774c ldr r0, [sp, #0xc]
 *   @0x207750 ldr r2, [r0, #0xc]
 *   @0x207754 bic r3, r2, #-16777216
 *   @0x207758 cmp r3, #1
 *   @0x20775c beq 0x207838 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x2b0>
 *   @0x207760 cmp r3, #2
 *   @0x207764 bne 0x207790 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x208>
 *   @0x207768 sub r3, r2, #1
 *   @0x20776c bic r3, r3, #-16777216
 *   @0x207770 bic r3, r3, #3
 *   @0x207774 cmp r3, #0
 *   @0x207778 beq 0x20795c <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x3d4>
 *   @0x20777c ldr r0, [sp, #0xc]
 *   @0x207780 mov r2, #0
 *   @0x207784 mov r3, #5
 *   @0x207788 str r2, [r0, #0x8]
 *   @0x20778c str r3, [r0, #0xc]
 *   @0x207790 ldr r3, [r6, #0xc]
 *   @0x207794 mov r1, #0
 *   @0x207798 ldr r0, [sp, #0xc]
 *   @0x20779c ldr r2, [r6, #0x8]
 *   @0x2077a0 str r3, [r0, #0xc]
 *   @0x2077a4 ldr r3, [r6, #0xc]
 *   @0x2077a8 str r1, [r0]
 *   @0x2077ac bic r3, r3, #-16777216
 *   @0x2077b0 str r2, [r0, #0x8]
 *   @0x2077b4 cmp r3, #14
 *   @0x2077b8 addls pc, pc, r3, lsl #2
 *   @0x2077bc b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280>
 *   @0x2077c0 b 0x207820 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x298>
 *   @0x2077c4 b 0x2078c8 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x340>
 *   @0x2077c8 b 0x2078f0 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x368>
 *   @0x2077cc b 0x2077fc <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x274>
 *   @0x2077d0 b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280>
 *   @0x2077d4 b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280>
 *   @0x2077d8 b 0x207898 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x310>
 *   @0x2077dc b 0x2077fc <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x274>
 *   @0x2077e0 b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280>
 *   @0x2077e4 b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280>
 *   @0x2077e8 b 0x207820 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x298>
 *   @0x2077ec b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280>
 *   @0x2077f0 b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280>
 *   @0x2077f4 b 0x207820 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x298>
 *   @0x2077f8 b 0x2077fc <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x274>
 *   @0x2077fc ldr r3, [r6]
 *   @0x207800 ldr r1, [sp, #0xc]
 *   @0x207804 str r3, [r1]
 *   @0x207808 add sp, sp, #20
 *   @0x20780c vpop {d8, d9, d10, d11, d12}
 *   @0x207810 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x207814 cmp r3, #1
 *   @0x207818 movne r10, #1
 *   @0x20781c b 0x207700 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x178>
 *   @0x207820 ldm r6, {r2, r3}
 *   @0x207824 ldr r0, [sp, #0xc]
 *   @0x207828 stm r0, {r2, r3}
 *   @0x20782c add sp, sp, #20
 *   @0x207830 vpop {d8, d9, d10, d11, d12}
 *   @0x207834 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x207838 ldr r1, [sp, #0xc]
 *   @0x20783c ldr r4, [r1]
 *   @0x207840 cmp r4, #0
 *   @0x207844 beq 0x207864 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x2dc>
 *   @0x207848 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20784c ldr r5, [r4, #0x4]
 *   @0x207850 sub r5, r5, #1
 *   @0x207854 str r5, [r4, #0x4]
 *   @0x207858 cmp r5, #0
 *   @0x20785c beq 0x207924 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x39c>
 *   @0x207860 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x207864 ldr r2, [sp, #0xc]
 *   @0x207868 mov r3, #0
 *   @0x20786c str r3, [r2]
 *   @0x207870 b 0x207790 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x208>
 *   @0x207874 ldr r3, [pc, #0x188]
 *   @0x207878 ldr r1, [pc, #0x188]
 *   @0x20787c ldr r3, [pc, r3]
 *   @0x207880 add r1, pc, r1
 *   @0x207884 ldr r0, [r3]
 *   @0x207888 ldr r3, [r0]
 *   @0x20788c ldr r3, [r3, #0xc]
 *   @0x207890 blx r3
 *   @0x207894 b 0x20774c <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x1c4>
 *   @0x207898 ldr r3, [r6]
 *   @0x20789c ldr r0, [sp, #0xc]
 *   @0x2078a0 str r3, [r0]
 *   @0x2078a4 ldr r3, [r6]
 *   @0x2078a8 cmp r3, #0
 *   @0x2078ac beq 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280>
 *   @0x2078b0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x2078b4 ldr r1, [r6]
 *   @0x2078b8 add sp, sp, #20
 *   @0x2078bc vpop {d8, d9, d10, d11, d12}
 *   @0x2078c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2078c4 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2078c8 ldr r3, [r6]
 *   @0x2078cc cmp r3, #0
 *   @0x2078d0 ldrne r2, [r3, #0x4]
 *   @0x2078d4 addne r2, r2, #1
 *   @0x2078d8 strne r2, [r3, #0x4]
 *   @0x2078dc ldr r2, [sp, #0xc]
 *   @0x2078e0 str r3, [r2]
 *   @0x2078e4 add sp, sp, #20
 *   @0x2078e8 vpop {d8, d9, d10, d11, d12}
 *   @0x2078ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2078f0 ldr r3, [r6]
 *   @0x2078f4 ldr r1, [sp, #0xc]
 *   @0x2078f8 cmp r3, #0
 *   @0x2078fc str r3, [r1]
 *   @0x207900 beq 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280>
 *   @0x207904 ldr r1, [r3, #0x8]
 *   @0x207908 ldr r2, [r3]
 *   @0x20790c cmp r1, #0
 *   @0x207910 add r2, r2, #1
 *   @0x207914 str r2, [r3]
 *   @0x207918 ldreq r2, [sp, #0xc]
 *   @0x20791c streq r2, [r3, #0x8]
 *   @0x207920 b 0x207808 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x280>
 *   @0x207924 ldr r0, [r4]
 *   @0x207928 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20792c str r5, [r4]
 *   @0x207930 str r5, [r4, #0x8]
 *   @0x207934 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x207938 ldr r5, [r4, #0x4]
 *   @0x20793c sub r5, r5, #1
 *   @0x207940 str r5, [r4, #0x4]
 *   @0x207944 cmp r5, #0
 *   @0x207948 beq 0x207968 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x3e0>
 *   @0x20794c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x207950 mov r0, r4
 *   @0x207954 bl 0x27d1d0 <_ZdlPv>
 *   @0x207958 b 0x207860 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x2d8>
 *   @0x20795c ldr r0, [sp, #0xc]
 *   @0x207960 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x207964 b 0x20777c <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x1f4>
 *   @0x207968 ldr r0, [r4]
 *   @0x20796c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x207970 str r5, [r4]
 *   @0x207974 str r5, [r4, #0x8]
 *   @0x207978 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20797c ldr r5, [r4, #0x4]
 *   @0x207980 sub r5, r5, #1
 *   @0x207984 str r5, [r4, #0x4]
 *   @0x207988 cmp r5, #0
 *   @0x20798c beq 0x2079a0 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x418>
 *   @0x207990 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x207994 mov r0, r4
 *   @0x207998 bl 0x27d1d0 <_ZdlPv>
 *   @0x20799c b 0x20794c <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x3c4>
 *   @0x2079a0 ldr r0, [r4]
 *   @0x2079a4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2079a8 str r5, [r4]
 *   @0x2079ac str r5, [r4, #0x8]
 *   @0x2079b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2079b4 ldr r5, [r4, #0x4]
 *   @0x2079b8 sub r5, r5, #1
 *   @0x2079bc str r5, [r4, #0x4]
 *   @0x2079c0 cmp r5, #0
 *   @0x2079c4 beq 0x2079d8 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x450>
 *   @0x2079c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2079cc mov r0, r4
 *   @0x2079d0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2079d4 b 0x207990 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x408>
 *   @0x2079d8 ldr r0, [r4]
 *   @0x2079dc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2079e0 mov r0, r4
 *   @0x2079e4 str r5, [r4]
 *   @0x2079e8 str r5, [r4, #0x8]
 *   @0x2079ec bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x2079f0 mov r0, r4
 *   @0x2079f4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2079f8 b 0x2079c8 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd+0x440>
 *   @0x2079fc ldrheq r6, [lr], -r8
 *   @0x207a00 andseq r9, lr, r8, ror r12
 *   @0x207a04 andseq r6, lr, r4, asr #1
 *   @0x207a08 andseq r12, r4, r8, asr r0
 *
 * ══ §20/29 b2ParticleSystem::CreateParticle(b2ParticleDef const&)  0x2da108  size 1148  287 条（0x2da108..0x2da584）
 * @func 0x2da108 0x2da584  size 1148  287 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int)×9 / 0xb65bc×8 / b2BlockAllocator::Free(void*, int)×8 / b2Vec2* b2ParticleSystem::ReallocateBuffer<b2Vec2>(b2ParticleSystem::ParticleBuffer<b2Vec2>*, int, int, bool)×2 / b2ParticleSystem::CreateParticle(b2ParticleDef const&)+0x2b0 / b2ParticleSystem::CreateParticle(b2ParticleDef const&)+0xa4 / anon_2d49b8+0x78 / 0xb65b0
 * 字段偏移 top8: 0xd4×17 / 0x28×12 / 0x54×4 / 0x60×4 / 0x24×3 / 0x30×3 / 0x50×3 / 0x5c×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2da108 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2da10c mov r4, r0
 *   @0x2da110 ldr r5, [r0, #0x24]
 *   @0x2da114 sub sp, sp, #12
 *   @0x2da118 ldr r2, [r0, #0x28]
 *   @0x2da11c mov r6, r1
 *   @0x2da120 cmp r5, r2
 *   @0x2da124 blt 0x2da3b8 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x2b0>
 *   @0x2da128 cmp r5, #0
 *   @0x2da12c ldr r3, [r0, #0x2c]
 *   @0x2da130 lslne r5, r5, #1
 *   @0x2da134 ldr r1, [r0, #0x34]
 *   @0x2da138 moveq r5, #256
 *   @0x2da13c cmp r3, #0
 *   @0x2da140 cmpne r5, r3
 *   @0x2da144 ldr r7, [r0, #0x3c]
 *   @0x2da148 movgt r5, r3
 *   @0x2da14c cmp r1, #0
 *   @0x2da150 cmpne r1, r5
 *   @0x2da154 ldr r12, [r0, #0x44]
 *   @0x2da158 movlt r5, r1
 *   @0x2da15c cmp r7, #0
 *   @0x2da160 cmpne r7, r5
 *   @0x2da164 ldr r0, [r0, #0x58]
 *   @0x2da168 movge r7, r5
 *   @0x2da16c cmp r12, #0
 *   @0x2da170 cmpne r12, r7
 *   @0x2da174 ldr r3, [r4, #0x64]
 *   @0x2da178 movge r12, r7
 *   @0x2da17c cmp r0, #0
 *   @0x2da180 cmpne r0, r12
 *   @0x2da184 movge r0, r12
 *   @0x2da188 cmp r3, #0
 *   @0x2da18c cmpne r3, r0
 *   @0x2da190 movge r7, r0
 *   @0x2da194 movlt r7, r3
 *   @0x2da198 cmp r2, r7
 *   @0x2da19c blt 0x2da1ac <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0xa4>
 *   @0x2da1a0 mvn r0, #0
 *   @0x2da1a4 add sp, sp, #12
 *   @0x2da1a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2da1ac cmp r1, #0
 *   @0x2da1b0 lsl r5, r7, #2
 *   @0x2da1b4 ldr r8, [r4, #0x30]
 *   @0x2da1b8 beq 0x2da548 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x440>
 *   @0x2da1bc str r8, [r4, #0x30]
 *   @0x2da1c0 add r1, r4, #56
 *   @0x2da1c4 mov r8, #0
 *   @0x2da1c8 mov r3, r7
 *   @0x2da1cc str r8, [sp]
 *   @0x2da1d0 mov r0, r4
 *   @0x2da1d4 bl 0x2da090 <_ZN16b2ParticleSystem16ReallocateBufferI6b2Vec2EEPT_PNS_14ParticleBufferIS2_EEiib>
 *   @0x2da1d8 ldr r2, [r4, #0x28]
 *   @0x2da1dc mov r3, r7
 *   @0x2da1e0 str r8, [sp]
 *   @0x2da1e4 add r1, r4, #64
 *   @0x2da1e8 str r0, [r4, #0x38]
 *   @0x2da1ec mov r0, r4
 *   @0x2da1f0 bl 0x2da090 <_ZN16b2ParticleSystem16ReallocateBufferI6b2Vec2EEPT_PNS_14ParticleBufferIS2_EEiib>
 *   @0x2da1f4 mov r1, r5
 *   @0x2da1f8 ldr r8, [r4, #0x48]
 *   @0x2da1fc ldr r9, [r4, #0x28]
 *   @0x2da200 lsl r9, r9, #2
 *   @0x2da204 str r0, [r4, #0x40]
 *   @0x2da208 ldr r0, [r4, #0xd4]
 *   @0x2da20c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2da210 mov r1, r8
 *   @0x2da214 mov r2, r9
 *   @0x2da218 mov r10, r0
 *   @0x2da21c bl 0xb65bc <memcpy@plt>
 *   @0x2da220 mov r2, r9
 *   @0x2da224 mov r1, r8
 *   @0x2da228 ldr r0, [r4, #0xd4]
 *   @0x2da22c bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2da230 ldr r8, [r4, #0x4c]
 *   @0x2da234 str r10, [r4, #0x48]
 *   @0x2da238 cmp r8, #0
 *   @0x2da23c ldr r2, [r4, #0x28]
 *   @0x2da240 moveq r10, r8
 *   @0x2da244 beq 0x2da27c <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x174>
 *   @0x2da248 lsl r1, r7, #3
 *   @0x2da24c ldr r0, [r4, #0xd4]
 *   @0x2da250 lsl r9, r2, #3
 *   @0x2da254 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2da258 mov r1, r8
 *   @0x2da25c mov r2, r9
 *   @0x2da260 mov r10, r0
 *   @0x2da264 bl 0xb65bc <memcpy@plt>
 *   @0x2da268 mov r2, r9
 *   @0x2da26c mov r1, r8
 *   @0x2da270 ldr r0, [r4, #0xd4]
 *   @0x2da274 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2da278 ldr r2, [r4, #0x28]
 *   @0x2da27c ldr r8, [r4, #0x50]
 *   @0x2da280 str r10, [r4, #0x4c]
 *   @0x2da284 cmp r8, #0
 *   @0x2da288 moveq r10, r8
 *   @0x2da28c beq 0x2da2c4 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x1bc>
 *   @0x2da290 mov r1, r5
 *   @0x2da294 ldr r0, [r4, #0xd4]
 *   @0x2da298 lsl r9, r2, #2
 *   @0x2da29c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2da2a0 mov r1, r8
 *   @0x2da2a4 mov r2, r9
 *   @0x2da2a8 mov r10, r0
 *   @0x2da2ac bl 0xb65bc <memcpy@plt>
 *   @0x2da2b0 mov r2, r9
 *   @0x2da2b4 mov r1, r8
 *   @0x2da2b8 ldr r0, [r4, #0xd4]
 *   @0x2da2bc bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2da2c0 ldr r2, [r4, #0x28]
 *   @0x2da2c4 ldr r8, [r4, #0x54]
 *   @0x2da2c8 str r10, [r4, #0x50]
 *   @0x2da2cc cmp r8, #0
 *   @0x2da2d0 ldr r3, [r4, #0x58]
 *   @0x2da2d4 beq 0x2da318 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x210>
 *   @0x2da2d8 cmp r3, #0
 *   @0x2da2dc bne 0x2da318 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x210>
 *   @0x2da2e0 mov r1, r5
 *   @0x2da2e4 ldr r0, [r4, #0xd4]
 *   @0x2da2e8 lsl r9, r2, #2
 *   @0x2da2ec bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2da2f0 mov r1, r8
 *   @0x2da2f4 mov r2, r9
 *   @0x2da2f8 mov r10, r0
 *   @0x2da2fc bl 0xb65bc <memcpy@plt>
 *   @0x2da300 mov r2, r9
 *   @0x2da304 mov r1, r8
 *   @0x2da308 ldr r0, [r4, #0xd4]
 *   @0x2da30c mov r8, r10
 *   @0x2da310 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2da314 ldr r2, [r4, #0x28]
 *   @0x2da318 str r8, [r4, #0x54]
 *   @0x2da31c mov r1, r5
 *   @0x2da320 ldr r0, [r4, #0xd4]
 *   @0x2da324 lsl r9, r2, #2
 *   @0x2da328 ldr r10, [r4, #0x5c]
 *   @0x2da32c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2da330 mov r2, r9
 *   @0x2da334 mov r1, r10
 *   @0x2da338 mov r11, r0
 *   @0x2da33c bl 0xb65bc <memcpy@plt>
 *   @0x2da340 mov r2, r9
 *   @0x2da344 mov r1, r10
 *   @0x2da348 ldr r0, [r4, #0xd4]
 *   @0x2da34c bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2da350 ldr r8, [r4, #0x60]
 *   @0x2da354 str r11, [r4, #0x5c]
 *   @0x2da358 cmp r8, #0
 *   @0x2da35c ldr r2, [r4, #0x28]
 *   @0x2da360 ldr r3, [r4, #0x64]
 *   @0x2da364 beq 0x2da3a4 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x29c>
 *   @0x2da368 cmp r3, #0
 *   @0x2da36c bne 0x2da3a4 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x29c>
 *   @0x2da370 mov r1, r5
 *   @0x2da374 ldr r0, [r4, #0xd4]
 *   @0x2da378 lsl r9, r2, #2
 *   @0x2da37c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2da380 mov r1, r8
 *   @0x2da384 mov r2, r9
 *   @0x2da388 mov r5, r0
 *   @0x2da38c bl 0xb65bc <memcpy@plt>
 *   @0x2da390 mov r1, r8
 *   @0x2da394 mov r2, r9
 *   @0x2da398 ldr r0, [r4, #0xd4]
 *   @0x2da39c mov r8, r5
 *   @0x2da3a0 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2da3a4 ldr r5, [r4, #0x24]
 *   @0x2da3a8 str r8, [r4, #0x60]
 *   @0x2da3ac cmp r5, r7
 *   @0x2da3b0 str r7, [r4, #0x28]
 *   @0x2da3b4 bge 0x2da1a0 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x98>
 *   @0x2da3b8 mov r3, r6
 *   @0x2da3bc ldr r2, [r4, #0x38]
 *   @0x2da3c0 ldr r9, [r3], #4
 *   @0x2da3c4 lsl r12, r5, #3
 *   @0x2da3c8 ldr r8, [r4, #0x30]
 *   @0x2da3cc add r2, r2, r12
 *   @0x2da3d0 add r7, r6, #12
 *   @0x2da3d4 ldr r10, [r4, #0x40]
 *   @0x2da3d8 ldm r3, {r0, r1}
 *   @0x2da3dc add r3, r5, #1
 *   @0x2da3e0 str r3, [r4, #0x24]
 *   @0x2da3e4 add r3, r10, r12
 *   @0x2da3e8 str r9, [r8, r5, lsl #2]
 *   @0x2da3ec mov r12, #0
 *   @0x2da3f0 stm r2, {r0, r1}
 *   @0x2da3f4 lsl r8, r5, #2
 *   @0x2da3f8 ldr r2, [r4, #0x5c]
 *   @0x2da3fc ldm r7, {r0, r1}
 *   @0x2da400 stm r3, {r0, r1}
 *   @0x2da404 str r12, [r2, r5, lsl #2]
 *   @0x2da408 ldr r3, [r4, #0x50]
 *   @0x2da40c cmp r3, r12
 *   @0x2da410 addne r3, r3, r8
 *   @0x2da414 movne r2, #0
 *   @0x2da418 strne r2, [r3]
 *   @0x2da41c ldr r3, [r4, #0x54]
 *   @0x2da420 cmp r3, #0
 *   @0x2da424 beq 0x2da4d0 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x3c8>
 *   @0x2da428 str r3, [r4, #0x54]
 *   @0x2da42c ldr r0, [r6, #0x14]
 *   @0x2da430 str r0, [r3, r8]
 *   @0x2da434 ldr r7, [r4, #0x60]
 *   @0x2da438 cmp r7, #0
 *   @0x2da43c beq 0x2da514 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x40c>
 *   @0x2da440 ldr r3, [r6, #0x18]
 *   @0x2da444 str r7, [r4, #0x60]
 *   @0x2da448 str r3, [r7, r8]
 *   @0x2da44c ldr r1, [r4, #0x68]
 *   @0x2da450 ldr r2, [r4, #0x6c]
 *   @0x2da454 cmp r1, r2
 *   @0x2da458 bge 0x2da478 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x370>
 *   @0x2da45c ldr r3, [r4, #0x70]
 *   @0x2da460 add r2, r1, #1
 *   @0x2da464 mov r0, r5
 *   @0x2da468 str r2, [r4, #0x68]
 *   @0x2da46c str r5, [r3, r1, lsl #3]
 *   @0x2da470 add sp, sp, #12
 *   @0x2da474 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2da478 cmp r1, #0
 *   @0x2da47c ldr r0, [r4, #0xd4]
 *   @0x2da480 lslne r9, r1, #1
 *   @0x2da484 lslne r1, r1, #4
 *   @0x2da488 moveq r1, #2048
 *   @0x2da48c moveq r9, #256
 *   @0x2da490 ldr r7, [r4, #0x70]
 *   @0x2da494 lsl r6, r2, #3
 *   @0x2da498 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2da49c mov r2, r6
 *   @0x2da4a0 mov r1, r7
 *   @0x2da4a4 mov r8, r0
 *   @0x2da4a8 bl 0xb65bc <memcpy@plt>
 *   @0x2da4ac mov r1, r7
 *   @0x2da4b0 mov r2, r6
 *   @0x2da4b4 ldr r0, [r4, #0xd4]
 *   @0x2da4b8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2da4bc ldr r1, [r4, #0x68]
 *   @0x2da4c0 mov r3, r8
 *   @0x2da4c4 str r8, [r4, #0x70]
 *   @0x2da4c8 str r9, [r4, #0x6c]
 *   @0x2da4cc b 0x2da460 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x358>
 *   @0x2da4d0 ldrb r3, [r6, #0x14]
 *   @0x2da4d4 cmp r3, #0
 *   @0x2da4d8 bne 0x2da500 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x3f8>
 *   @0x2da4dc ldrb r3, [r6, #0x15]
 *   @0x2da4e0 cmp r3, #0
 *   @0x2da4e4 bne 0x2da500 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x3f8>
 *   @0x2da4e8 ldrb r3, [r6, #0x16]
 *   @0x2da4ec cmp r3, #0
 *   @0x2da4f0 bne 0x2da500 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x3f8>
 *   @0x2da4f4 ldrb r3, [r6, #0x17]
 *   @0x2da4f8 cmp r3, #0
 *   @0x2da4fc beq 0x2da434 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x32c>
 *   @0x2da500 add r0, r4, #40
 *   @0x2da504 add r1, r4, #212
 *   @0x2da508 bl 0x2d4a30 <_ZN15b2QueryCallbackD0Ev+0xa0>
 *   @0x2da50c mov r3, r0
 *   @0x2da510 b 0x2da428 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x320>
 *   @0x2da514 ldr r3, [r6, #0x18]
 *   @0x2da518 cmp r3, #0
 *   @0x2da51c beq 0x2da44c <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x344>
 *   @0x2da520 ldr r1, [r4, #0x28]
 *   @0x2da524 ldr r0, [r4, #0xd4]
 *   @0x2da528 lsl r1, r1, #2
 *   @0x2da52c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2da530 ldr r2, [r4, #0x28]
 *   @0x2da534 mov r1, #0
 *   @0x2da538 lsl r2, r2, #2
 *   @0x2da53c mov r7, r0
 *   @0x2da540 bl 0xb65b0 <memset@plt>
 *   @0x2da544 b 0x2da440 <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0x338>
 *   @0x2da548 mov r1, r5
 *   @0x2da54c ldr r0, [r4, #0xd4]
 *   @0x2da550 lsl r9, r2, #2
 *   @0x2da554 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2da558 mov r1, r8
 *   @0x2da55c mov r2, r9
 *   @0x2da560 mov r10, r0
 *   @0x2da564 bl 0xb65bc <memcpy@plt>
 *   @0x2da568 mov r2, r9
 *   @0x2da56c mov r1, r8
 *   @0x2da570 ldr r0, [r4, #0xd4]
 *   @0x2da574 mov r8, r10
 *   @0x2da578 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2da57c ldr r2, [r4, #0x28]
 *   @0x2da580 b 0x2da1bc <_ZN16b2ParticleSystem14CreateParticleERK13b2ParticleDef+0xb4>
 *
 * ══ §21/29 jpeg_idct_float  0x2bf9dc  size 1144  286 条（0x2bf9dc..0x2bfe54）
 * @func 0x2bf9dc 0x2bfe54  size 1144  286 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x50×5 / 0x60×4 / 0x70×4 / 0x4×3 / 0x8×2 / 0xc×2 / 0x30×2 / 0x40×2
 * VFP 指令 153 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bf9dc push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2bf9e0 vpush {d8, d9}
 *   @0x2bf9e4 sub sp, sp, #272
 *   @0x2bf9e8 vldr s4, [pc, #968]
 *   @0x2bf9ec ldr r12, [r0, #0x120]
 *   @0x2bf9f0 vldr s1, [pc, #964]
 *   @0x2bf9f4 ldr r0, [r1, #0x50]
 *   @0x2bf9f8 add r1, sp, #16
 *   @0x2bf9fc str r1, [sp, #0x4]
 *   @0x2bfa00 mov r1, r2
 *   @0x2bfa04 add r4, r1, #16
 *   @0x2bfa08 add r12, r12, #128
 *   @0x2bfa0c add r5, r0, #4
 *   @0x2bfa10 str r3, [sp, #0x8]
 *   @0x2bfa14 add r2, r2, #2
 *   @0x2bfa18 add r0, r0, #64
 *   @0x2bfa1c add r3, sp, #16
 *   @0x2bfa20 vldr s2, [pc, #920]
 *   @0x2bfa24 vldr s3, [pc, #920]
 *   @0x2bfa28 str r12, [sp, #0xc]
 *   @0x2bfa2c mov r11, r4
 *   @0x2bfa30 b 0x2bfbbc <jpeg_idct_float+0x1e0>
 *   @0x2bfa34 cmp r7, #0
 *   @0x2bfa38 bne 0x2bfbcc <jpeg_idct_float+0x1f0>
 *   @0x2bfa3c ldrh r10, [r1, #48]
 *   @0x2bfa40 ldrh r4, [r1, #64]
 *   @0x2bfa44 cmp r10, #0
 *   @0x2bfa48 beq 0x2bfd98 <jpeg_idct_float+0x3bc>
 *   @0x2bfa4c ldrh r6, [r1, #96]
 *   @0x2bfa50 mov r7, r12
 *   @0x2bfa54 ldrh r9, [r1, #80]
 *   @0x2bfa58 ldrh r8, [r1, #112]
 *   @0x2bfa5c sxth r12, r12
 *   @0x2bfa60 sxth r10, r10
 *   @0x2bfa64 sxth r9, r9
 *   @0x2bfa68 sxth r8, r8
 *   @0x2bfa6c vmov s5, r12
 *   @0x2bfa70 vldr s19, [r0, #-32]
 *   @0x2bfa74 vmov s15, r10
 *   @0x2bfa78 vldr s9, [r0, #160]
 *   @0x2bfa7c vmov s12, r9
 *   @0x2bfa80 vldr s13, [r0, #32]
 *   @0x2bfa84 vmov s6, r8
 *   @0x2bfa88 vldr s14, [r0, #96]
 *   @0x2bfa8c vcvt.f32.s32 s5, s5
 *   @0x2bfa90 sxth r7, r7
 *   @0x2bfa94 sxth r6, r6
 *   @0x2bfa98 vldr s18, [r0]
 *   @0x2bfa9c vmov s7, r7
 *   @0x2bfaa0 vldr s17, [r0, #128]
 *   @0x2bfaa4 vmov s10, r6
 *   @0x2bfaa8 ldrsh r12, [r2, #-2]
 *   @0x2bfaac sxth r4, r4
 *   @0x2bfab0 vldr s16, [r0, #64]
 *   @0x2bfab4 vldr s0, [r5, #-4]
 *   @0x2bfab8 add r3, r3, #4
 *   @0x2bfabc vmov s11, r12
 *   @0x2bfac0 vcvt.f32.s32 s6, s6
 *   @0x2bfac4 vmov s8, r4
 *   @0x2bfac8 vcvt.f32.s32 s15, s15
 *   @0x2bfacc vcvt.f32.s32 s12, s12
 *   @0x2bfad0 vmul.f32 s15, s15, s13
 *   @0x2bfad4 vmul.f32 s5, s5, s19
 *   @0x2bfad8 vmul.f32 s6, s6, s9
 *   @0x2bfadc vmul.f32 s12, s12, s14
 *   @0x2bfae0 vsub.f32 s13, s5, s6
 *   @0x2bfae4 vsub.f32 s14, s12, s15
 *   @0x2bfae8 vadd.f32 s9, s14, s13
 *   @0x2bfaec vmul.f32 s9, s9, s1
 *   @0x2bfaf0 vmov.f32 s19, s9
 *   @0x2bfaf4 vmla.f32 s19, s14, s2
 *   @0x2bfaf8 vadd.f32 s12, s12, s15
 *   @0x2bfafc vadd.f32 s6, s5, s6
 *   @0x2bfb00 vadd.f32 s15, s6, s12
 *   @0x2bfb04 vcvt.f32.s32 s7, s7
 *   @0x2bfb08 vcvt.f32.s32 s10, s10
 *   @0x2bfb0c vmul.f32 s7, s7, s18
 *   @0x2bfb10 vmul.f32 s10, s10, s17
 *   @0x2bfb14 vsub.f32 s14, s19, s15
 *   @0x2bfb18 vsub.f32 s6, s6, s12
 *   @0x2bfb1c vcvt.f32.s32 s8, s8
 *   @0x2bfb20 vcvt.f32.s32 s11, s11
 *   @0x2bfb24 vadd.f32 s12, s7, s10
 *   @0x2bfb28 vnmls.f32 s9, s13, s3
 *   @0x2bfb2c vmov.f32 s13, s14
 *   @0x2bfb30 vmul.f32 s8, s8, s16
 *   @0x2bfb34 vmul.f32 s11, s11, s0
 *   @0x2bfb38 vsub.f32 s10, s7, s10
 *   @0x2bfb3c vnmls.f32 s13, s6, s4
 *   @0x2bfb40 vmov.f32 s7, s12
 *   @0x2bfb44 vnmls.f32 s7, s10, s4
 *   @0x2bfb48 vadd.f32 s10, s11, s8
 *   @0x2bfb4c vadd.f32 s9, s9, s13
 *   @0x2bfb50 vsub.f32 s11, s11, s8
 *   @0x2bfb54 vsub.f32 s8, s10, s12
 *   @0x2bfb58 vadd.f32 s12, s10, s12
 *   @0x2bfb5c vsub.f32 s10, s11, s7
 *   @0x2bfb60 vadd.f32 s11, s11, s7
 *   @0x2bfb64 vadd.f32 s7, s8, s9
 *   @0x2bfb68 vsub.f32 s9, s8, s9
 *   @0x2bfb6c vstr s7, [r3, #124]
 *   @0x2bfb70 vadd.f32 s7, s10, s13
 *   @0x2bfb74 vstr s9, [r3, #92]
 *   @0x2bfb78 vsub.f32 s13, s10, s13
 *   @0x2bfb7c vstr s7, [r3, #60]
 *   @0x2bfb80 vadd.f32 s9, s11, s14
 *   @0x2bfb84 vstr s13, [r3, #156]
 *   @0x2bfb88 vsub.f32 s14, s11, s14
 *   @0x2bfb8c vstr s9, [r3, #28]
 *   @0x2bfb90 vadd.f32 s13, s12, s15
 *   @0x2bfb94 vstr s14, [r3, #188]
 *   @0x2bfb98 vsub.f32 s12, s12, s15
 *   @0x2bfb9c vstr s13, [r3, #-4]
 *   @0x2bfba0 vstr s12, [r3, #220]
 *   @0x2bfba4 add r1, r1, #2
 *   @0x2bfba8 add r2, r2, #2
 *   @0x2bfbac cmp r1, r11
 *   @0x2bfbb0 add r5, r5, #4
 *   @0x2bfbb4 add r0, r0, #4
 *   @0x2bfbb8 beq 0x2bfbe4 <jpeg_idct_float+0x208>
 *   @0x2bfbbc ldrh r12, [r1, #16]
 *   @0x2bfbc0 ldrh r7, [r1, #32]
 *   @0x2bfbc4 cmp r12, #0
 *   @0x2bfbc8 beq 0x2bfa34 <jpeg_idct_float+0x58>
 *   @0x2bfbcc ldrh r4, [r1, #64]
 *   @0x2bfbd0 ldrh r6, [r1, #96]
 *   @0x2bfbd4 ldrh r10, [r1, #48]
 *   @0x2bfbd8 ldrh r9, [r1, #80]
 *   @0x2bfbdc ldrh r8, [r1, #112]
 *   @0x2bfbe0 b 0x2bfa5c <jpeg_idct_float+0x80>
 *   @0x2bfbe4 ldr r1, [sp, #0x8]
 *   @0x2bfbe8 add r3, sp, #16
 *   @0x2bfbec ldr r12, [sp, #0xc]
 *   @0x2bfbf0 vldr s4, [pc, #448]
 *   @0x2bfbf4 ldr r4, [sp, #0x140]
 *   @0x2bfbf8 sub r0, r1, #4
 *   @0x2bfbfc vldr s1, [pc, #440]
 *   @0x2bfc00 vldr s2, [pc, #440]
 *   @0x2bfc04 vldr s3, [pc, #440]
 *   @0x2bfc08 vldr s5, [r3, #20]
 *   @0x2bfc0c vldr s13, [r3, #28]
 *   @0x2bfc10 vldr s8, [r3, #12]
 *   @0x2bfc14 vldr s7, [r3, #4]
 *   @0x2bfc18 vsub.f32 s14, s5, s8
 *   @0x2bfc1c vldr s12, [r3, #24]
 *   @0x2bfc20 vldr s6, [r3, #8]
 *   @0x2bfc24 vldr s15, [r3, #16]
 *   @0x2bfc28 vldr s10, [r3]
 *   @0x2bfc2c add r5, sp, #272
 *   @0x2bfc30 add r3, r3, #32
 *   @0x2bfc34 ldr r1, [r0, #0x4]!
 *   @0x2bfc38 cmp r3, r5
 *   @0x2bfc3c add r2, r1, r4
 *   @0x2bfc40 vsub.f32 s9, s7, s13
 *   @0x2bfc44 vadd.f32 s11, s14, s9
 *   @0x2bfc48 vmul.f32 s11, s11, s1
 *   @0x2bfc4c vmov.f32 s0, s11
 *   @0x2bfc50 vmla.f32 s0, s14, s2
 *   @0x2bfc54 vadd.f32 s8, s5, s8
 *   @0x2bfc58 vadd.f32 s7, s7, s13
 *   @0x2bfc5c vadd.f32 s13, s6, s12
 *   @0x2bfc60 vsub.f32 s6, s6, s12
 *   @0x2bfc64 vadd.f32 s12, s7, s8
 *   @0x2bfc68 vmov.f32 s5, s13
 *   @0x2bfc6c vsub.f32 s14, s0, s12
 *   @0x2bfc70 vnmls.f32 s5, s6, s4
 *   @0x2bfc74 vsub.f32 s7, s7, s8
 *   @0x2bfc78 vadd.f32 s8, s10, s15
 *   @0x2bfc7c vsub.f32 s10, s10, s15
 *   @0x2bfc80 vmov.f32 s15, s14
 *   @0x2bfc84 vnmls.f32 s15, s7, s4
 *   @0x2bfc88 vadd.f32 s7, s8, s13
 *   @0x2bfc8c vmov.f32 s6, s5
 *   @0x2bfc90 vnmls.f32 s11, s9, s3
 *   @0x2bfc94 vadd.f32 s9, s10, s5
 *   @0x2bfc98 vadd.f32 s5, s7, s12
 *   @0x2bfc9c vcvt.s32.f32 s5, s5
 *   @0x2bfca0 vmov r5, s5
 *   @0x2bfca4 vsub.f32 s12, s7, s12
 *   @0x2bfca8 vcvt.s32.f32 s12, s12
 *   @0x2bfcac vsub.f32 s10, s10, s6
 *   @0x2bfcb0 add r5, r5, #4
 *   @0x2bfcb4 ubfx r5, r5, #0x3, #0xa
 *   @0x2bfcb8 ldrb r5, [r12, r5]
 *   @0x2bfcbc strb r5, [r1, r4]
 *   @0x2bfcc0 vmov r1, s12
 *   @0x2bfcc4 vadd.f32 s6, s9, s14
 *   @0x2bfcc8 vcvt.s32.f32 s6, s6
 *   @0x2bfccc vsub.f32 s14, s9, s14
 *   @0x2bfcd0 add r1, r1, #4
 *   @0x2bfcd4 ubfx r1, r1, #0x3, #0xa
 *   @0x2bfcd8 ldrb r1, [r12, r1]
 *   @0x2bfcdc strb r1, [r2, #0x7]
 *   @0x2bfce0 vmov r1, s6
 *   @0x2bfce4 vcvt.s32.f32 s14, s14
 *   @0x2bfce8 vsub.f32 s13, s8, s13
 *   @0x2bfcec vadd.f32 s8, s10, s15
 *   @0x2bfcf0 add r1, r1, #4
 *   @0x2bfcf4 ubfx r1, r1, #0x3, #0xa
 *   @0x2bfcf8 ldrb r1, [r12, r1]
 *   @0x2bfcfc strb r1, [r2, #0x1]
 *   @0x2bfd00 vmov r1, s14
 *   @0x2bfd04 vadd.f32 s11, s11, s15
 *   @0x2bfd08 vsub.f32 s15, s10, s15
 *   @0x2bfd0c add r1, r1, #4
 *   @0x2bfd10 vcvt.s32.f32 s8, s8
 *   @0x2bfd14 ubfx r1, r1, #0x3, #0xa
 *   @0x2bfd18 ldrb r1, [r12, r1]
 *   @0x2bfd1c strb r1, [r2, #0x6]
 *   @0x2bfd20 vcvt.s32.f32 s15, s15
 *   @0x2bfd24 vmov r5, s8
 *   @0x2bfd28 vmov r1, s15
 *   @0x2bfd2c vadd.f32 s12, s13, s11
 *   @0x2bfd30 vsub.f32 s13, s13, s11
 *   @0x2bfd34 add r5, r5, #4
 *   @0x2bfd38 ubfx r5, r5, #0x3, #0xa
 *   @0x2bfd3c ldrb r5, [r12, r5]
 *   @0x2bfd40 add r1, r1, #4
 *   @0x2bfd44 strb r5, [r2, #0x2]
 *   @0x2bfd48 vcvt.s32.f32 s12, s12
 *   @0x2bfd4c ubfx r1, r1, #0x3, #0xa
 *   @0x2bfd50 ldrb r1, [r12, r1]
 *   @0x2bfd54 strb r1, [r2, #0x5]
 *   @0x2bfd58 vcvt.s32.f32 s13, s13
 *   @0x2bfd5c vmov r5, s12
 *   @0x2bfd60 vmov r1, s13
 *   @0x2bfd64 add r5, r5, #4
 *   @0x2bfd68 ubfx r5, r5, #0x3, #0xa
 *   @0x2bfd6c ldrb r5, [r12, r5]
 *   @0x2bfd70 add r1, r1, #4
 *   @0x2bfd74 strb r5, [r2, #0x4]
 *   @0x2bfd78 ubfx r1, r1, #0x3, #0xa
 *   @0x2bfd7c ldrb r1, [r12, r1]
 *   @0x2bfd80 strb r1, [r2, #0x3]
 *   @0x2bfd84 bne 0x2bfc08 <jpeg_idct_float+0x22c>
 *   @0x2bfd88 add sp, sp, #272
 *   @0x2bfd8c vpop {d8, d9}
 *   @0x2bfd90 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2bfd94 bx lr
 *   @0x2bfd98 cmp r4, #0
 *   @0x2bfd9c beq 0x2bfdc8 <jpeg_idct_float+0x3ec>
 *   @0x2bfda0 ldrh r6, [r1, #96]
 *   @0x2bfda4 mov r10, r12
 *   @0x2bfda8 ldrh r9, [r1, #80]
 *   @0x2bfdac mov r7, r12
 *   @0x2bfdb0 ldrh r8, [r1, #112]
 *   @0x2bfdb4 b 0x2bfa5c <jpeg_idct_float+0x80>
 *   @0x2bfdb8 svclo #0xb504f3
 *   @0x2bfdbc svclo #0xec835e
 *   @0x2bfdc0 eorgt r3, r7, r5, ror sp
 *   @0x2bfdc4 svclo #0x8a8bd4
 *   @0x2bfdc8 ldrh r9, [r1, #80]
 *   @0x2bfdcc ldrh r6, [r1, #96]
 *   @0x2bfdd0 cmp r9, #0
 *   @0x2bfdd4 ldrh r8, [r1, #112]
 *   @0x2bfdd8 bne 0x2bfe2c <jpeg_idct_float+0x450>
 *   @0x2bfddc cmp r6, #0
 *   @0x2bfde0 bne 0x2bfe28 <jpeg_idct_float+0x44c>
 *   @0x2bfde4 cmp r8, #0
 *   @0x2bfde8 bne 0x2bfe3c <jpeg_idct_float+0x460>
 *   @0x2bfdec ldrsh r12, [r2, #-2]
 *   @0x2bfdf0 vldr s14, [r5, #-4]
 *   @0x2bfdf4 add r3, r3, #4
 *   @0x2bfdf8 vmov s15, r12
 *   @0x2bfdfc vcvt.f32.s32 s15, s15
 *   @0x2bfe00 vmul.f32 s15, s15, s14
 *   @0x2bfe04 vstr s15, [r3, #-4]
 *   @0x2bfe08 vstr s15, [r3, #28]
 *   @0x2bfe0c vstr s15, [r3, #60]
 *   @0x2bfe10 vstr s15, [r3, #92]
 *   @0x2bfe14 vstr s15, [r3, #124]
 *   @0x2bfe18 vstr s15, [r3, #156]
 *   @0x2bfe1c vstr s15, [r3, #188]
 *   @0x2bfe20 vstr s15, [r3, #220]
 *   @0x2bfe24 b 0x2bfba4 <jpeg_idct_float+0x1c8>
 *   @0x2bfe28 mov r9, r12
 *   @0x2bfe2c mov r10, r12
 *   @0x2bfe30 mov r4, r12
 *   @0x2bfe34 mov r7, r12
 *   @0x2bfe38 b 0x2bfa5c <jpeg_idct_float+0x80>
 *   @0x2bfe3c mov r9, r12
 *   @0x2bfe40 mov r10, r12
 *   @0x2bfe44 mov r6, r12
 *   @0x2bfe48 mov r4, r12
 *   @0x2bfe4c mov r7, r12
 *   @0x2bfe50 b 0x2bfa5c <jpeg_idct_float+0x80>
 *
 * ══ §22/29 anon_3187cc  0x3187cc  size 1144  286 条（0x3187cc..0x318c44）
 * @func 0x3187cc 0x318c44  size 1144  286 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x396830 / 0x396854 / 0xb0cfe8 / 0x7a5428 / 0x74c8b4 / 0x653254 / 0x3d697c / 0x653304
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3187cc andhi pc, r0, pc, lsr #7
 *   @0x3187d0 movwhs r11, #0x430
 *   @0x3187d4 ldrmi r6, [r9], -r4, lsl #16
 *   @0x3187d8 blhs 0x396830 <ft_adobe_glyph_list+0x5f0c>
 *   @0x3187dc ldrbeq pc, [pc, #-0x2]!
 *   @0x3187e0 movwlo r4, #0x709d
 *   @0x3187e4 b 0x135a034 <b2_toiTime+0xc00b90>
 *   @0x3187e8 ldrbtle r0, [r5], #261
 *   @0x3187ec strmi r6, [r8], -r4
 *   @0x3187f0 .word 0x4770bc30
 *   @0x3187f4 movwhs r11, #0x430
 *   @0x3187f8 ldrmi r6, [r9], -r4, lsl #16
 *   @0x3187fc blhs 0x396854 <ft_adobe_glyph_list+0x5f30>
 *   @0x318800 ldrbeq pc, [pc, #-0x2]!
 *   @0x318804 movwlo r4, #0x709d
 *   @0x318808 svceq #0x80f012
 *   @0x31880c .word 0x0105ea41
 *   @0x318810 blhs 0xb0cfe8 <b2_toiTime+0x3b3b44>
 *   @0x318814 svclt #0x8c6004
 *   @0x318818 strhs r2, [r1, #-0x500]
 *   @0x31881c ldrne lr, [r2, #0xa15]
 *   @0x318820 .word 0xf04fd004
 *   @0x318824 blx 0x7a5428 <b2_toiTime+0x4bf84>
 *   @0x318828 tstmi r9, #201326592
 *   @0x31882c ldclt p6, c4, [r0], #-32
 *   @0x318830 svclt #0x4770
 *   @0x318834 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r11, sp}
 *   @0x318838 .word 0x46064ff0
 *   @0x31883c strmi r11, [sp], -r9, lsl #1
 *   @0x318840 sbchi pc, r3, r0
 *   @0x318844 .word 0xf0016804
 *   @0x318848 strls r0, [r7], #-783
 *   @0x31884c ldmdale r10, {r2, r3, r8, r9, r11, sp}
 *   @0x318850 .word 0xf003e8df
 *   @0x318854 ldrbeq r6, [sp, -r7, lsl #30]!
 *   @0x318858 ldmdbne r9, {r0, r2, r3, r5, r8, r11, r12}
 *   @0x31885c .word 0x07676319
 *   @0x318860 stmvc r0!, {r0, r2, r7}
 *   @0x318864 stmdavc r1!, {r1, r5, r8, r10, r11, r12} ^
 *   @0x318868 .word 0xf8947823
 *   @0x31886c streq r10, [r0], #-3
 *   @0x318870 andhs lr, r1, r0, asr #20
 *   @0x318874 tstmi r8, #1879048192
 *   @0x318878 andvs lr, r10, r0, asr #20
 *   @0x31887c cmneq r0, #21
 *   @0x318880 blhs 0x74c8b4 <g_SWFvertbuff+0x797ec>
 *   @0x318884 .word 0xf59ed001
 *   @0x318888 stmdblt r0!, {r9, r11, sp, lr, pc}
 *   @0x31888c eorsvs r9, r3, r7, lsl #22
 *   @0x318890 pop {r0, r3, r12, sp, pc}
 *   @0x318894 ldmdavs r3!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x318898 stmibeq sp!, {r3, r4, r11, r12} ^
 *   @0x31889c svclt #0xc2800
 *   @0x3188a0 .word 0xf0052500
 *   @0x3188a4 stchs p5, c0, [r0, #-4]
 *   @0x3188a8 stmdavs r0, {r4, r5, r6, r7, r12, lr, pc}
 *   @0x3188ac stmdbvc r0!, {r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x3188b0 stmdavc r2!, {r0, r5, r11, r12, sp, lr} ^
 *   @0x3188b4 andls r7, r5, r3, lsr #17
 *   @0x3188b8 b 0x16f6f40 <b2_toiTime+0xf9da9c>
 *   @0x3188bc .word 0x91022802
 *   @0x3188c0 mrsls r2, apsr
 *   @0x3188c4 bmi 0x413208 <g_RomDisk+0x1b9e8>
 *   @0x3188c8 b 0x153c8d4 <b2_toiTime+0xde3430>
 *   @0x3188cc ldmib sp, {r1, r3, r9} ^
 *   @0x3188d0 movwhs r0, #0x102
 *   @0x3188d4 mulgt r3, r4, r8
 *   @0x3188d8 b 0x13bd4f0 <b2_toiTime+0xc6404c>
 *   @0x3188dc stmdbvc r7!, {r9, r11} ^
 *   @0x3188e0 movwhs lr, #0x49dd
 *   @0x3188e4 stmdavs r12, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x3188e8 b 0x15be8f4 <b2_toiTime+0xe65450>
 *   @0x3188ec eorseq r0, pc, #8, #20
 *   @0x3188f0 andls r9, r2, #786432
 *   @0x3188f4 stmdbmi r0, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x3188f8 andeq lr, r2, r10, asr #20
 *   @0x3188fc movwhs lr, #0x29dd
 *   @0x318900 .word 0xf8942300
 *   @0x318904 strlo r12, [r8], #-7
 *   @0x318908 .word 0x46984310
 *   @0x31890c .word 0x469a4318
 *   @0x318910 blvs 0x653254 <g_SWFlinevertbuff+0x18c>
 *   @0x318914 strls r4, [r7], #-792
 *   @0x318918 stmdage r7, {r4, r5, r7, r8, r9, r10, sp, lr, pc}
 *   @0x31891c .word 0xff6af7ff
 *   @0x318920 stmdavc r0!, {r2, r3, r5, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x318924 bllo 0x3d697c <error_g0017+0x2f620>
 *   @0x318928 andhs lr, r0, r3, asr #20
 *   @0x31892c andlt r9, r0, #117440512
 *   @0x318930 movwhs lr, #0x7a4
 *   @0x318934 .word 0xf8144618
 *   @0x318938 .word 0xf0022b01
 *   @0x31893c addsmi r0, r9, pc, ror r1
 *   @0x318940 ldreq r3, [r2], -r7, lsl #6
 *   @0x318944 andeq lr, r1, r0, asr #20
 *   @0x318948 strls sp, [r7], #-1269
 *   @0x31894c qadd8mi lr, r3, r6
 *   @0x318950 .word 0xf8137860
 *   @0x318954 b 0x13a3564 <b2_toiTime+0xc4a0c0>
 *   @0x318958 movwls r2, #0x7000
 *   @0x31895c stmdbvc r0!, {r1, r2, r3, r7, r8, r9, r10, sp, lr, pc}
 *   @0x318960 stmdavc r2!, {r0, r5, r11, r12, sp, lr} ^
 *   @0x318964 andls r7, r5, r3, lsr #17
 *   @0x318968 b 0x16f6ff0 <b2_toiTime+0xf9db4c>
 *   @0x31896c .word 0x91022802
 *   @0x318970 mrsls r2, apsr
 *   @0x318974 bmi 0x4132b8 <g_RomDisk+0x1ba98>
 *   @0x318978 b 0x153c984 <b2_toiTime+0xde34e0>
 *   @0x31897c ldmib sp, {r1, r3, r9} ^
 *   @0x318980 movwhs r0, #0x102
 *   @0x318984 mulgt r3, r4, r8
 *   @0x318988 b 0x13bd5a0 <b2_toiTime+0xc640fc>
 *   @0x31898c stmdbvc r7!, {r9, r11} ^
 *   @0x318990 movwhs lr, #0x49dd
 *   @0x318994 stmdavs r12, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x318998 b 0x15be9a4 <b2_toiTime+0xe65500>
 *   @0x31899c eorseq r0, pc, #8, #20
 *   @0x3189a0 andls r9, r2, #786432
 *   @0x3189a4 stmdbmi r0, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x3189a8 andeq lr, r2, r10, asr #20
 *   @0x3189ac movwhs lr, #0x29dd
 *   @0x3189b0 .word 0xf8942300
 *   @0x3189b4 strlo r12, [r8], #-7
 *   @0x3189b8 .word 0x46984310
 *   @0x3189bc .word 0x469a4318
 *   @0x3189c0 blvs 0x653304 <g_SWFlinevertbuff+0x23c>
 *   @0x3189c4 strls r4, [r7], #-792
 *   @0x3189c8 andhs lr, r0, r8, asr r7
 *   @0x3189cc svclt #0xe760
 *   @0x3189d0 ldrbtmi r4, [r11], #-2818
 *   @0x3189d4 andvs r3, r3, r8, lsl #6
 *   @0x3189d8 svclt #0x4770
 *   @0x3189dc andeq r4, sp, r2, lsl #16
 *   @0x3189e0 ldrbtmi r4, [r8], #-2049
 *   @0x3189e4 svclt #0x4770
 *   @0x3189e8 andeq r3, r4, r2, lsr sp
 *   @0x3189ec ldrbtmi r4, [r11], #-2818
 *   @0x3189f0 andvs r3, r3, r8, lsl #6
 *   @0x3189f4 svclt #0x4770
 *   @0x3189f8 andeq r4, sp, r6, ror #15
 *   @0x3189fc ldrbtmi r4, [r8], #-2049
 *   @0x318a00 svclt #0x4770
 *   @0x318a04 andeq r3, r4, r6, lsr #26
 *   @0x318a08 ldrlt r4, [r0, #-0xb04]
 *   @0x318a0c .word 0x4604447b
 *   @0x318a10 andvs r3, r3, r8, lsl #6
 *   @0x318a14 bl 0xffa567ac <b2_toiTime+0xffffffffff2fd308>
 *   @0x318a18 ldclt p6, c4, [r0, #-128]
 *   @0x318a1c andeq r4, sp, r8, asr #15
 *   @0x318a20 ldrlt r4, [r0, #-0xb04]
 *   @0x318a24 .word 0x4604447b
 *   @0x318a28 andvs r3, r3, r8, lsl #6
 *   @0x318a2c bl 0xff7567c4 <b2_toiTime+0xfffffffffeffd320>
 *   @0x318a30 ldclt p6, c4, [r0, #-128]
 *   @0x318a34 strheq r4, [sp], -r0
 *   @0x318a38 ldrbtmi r4, [r11], #-2818
 *   @0x318a3c andvs r3, r3, r8, lsl #6
 *   @0x318a40 svclt #0x4770
 *   @0x318a44 muleq sp, r10, r7
 *   @0x318a48 ldrbtmi r4, [r11], #-2818
 *   @0x318a4c andvs r3, r3, r8, lsl #6
 *   @0x318a50 svclt #0x4770
 *   @0x318a54 andeq r4, sp, r2, ror #14
 *   @0x318a58 .word 0xf7feb508
 *   @0x318a5c stmdavs r0, {r0, r6, r8, r10, r11, r12, sp, lr, pc} ^
 *   @0x318a60 svclt #0x183000
 *   @0x318a64 stclt p0, c2, [r8, #-4]
 *   @0x318a68 ldrbmi r2, [r0, -r0]!
 *   @0x318a6c ldrlt r4, [r0, #-0xb04]
 *   @0x318a70 .word 0x4604447b
 *   @0x318a74 andvs r3, r3, r8, lsl #6
 *   @0x318a78 stc2 p7, c15, [r12, #-1016]
 *   @0x318a7c ldclt p6, c4, [r0, #-128]
 *   @0x318a80 andeq r4, sp, r12, ror r7
 *   @0x318a84 .word 0x4604b510
 *   @0x318a88 .word 0xfff0f7ff
 *   @0x318a8c .word 0xf7644620
 *   @0x318a90 strtmi lr, [r0], -r0, lsr #23
 *   @0x318a94 svclt #0xbd10
 *   @0x318a98 stcllt p7, c15, [r6], #-1020
 *   @0x318a9c ldrlt r4, [r0, #-0xb04]
 *   @0x318aa0 .word 0x4604447b
 *   @0x318aa4 andvs r3, r3, r8, lsl #6
 *   @0x318aa8 ldc2l p7, c15, [r4], #1016
 *   @0x318aac ldclt p6, c4, [r0, #-128]
 *   @0x318ab0 andeq r4, sp, r12, lsl #22
 *   @0x318ab4 .word 0x4604b510
 *   @0x318ab8 .word 0xfff0f7ff
 *   @0x318abc .word 0xf7644620
 *   @0x318ac0 strtmi lr, [r0], -r8, lsl #23
 *   @0x318ac4 svclt #0xbd10
 *   @0x318ac8 ldrlt r4, [r0, #-0xb04]
 *   @0x318acc .word 0x4604447b
 *   @0x318ad0 andvs r3, r3, r8, lsl #6
 *   @0x318ad4 ldc2l p7, c15, [lr], {254}
 *   @0x318ad8 ldclt p6, c4, [r0, #-128]
 *   @0x318adc andeq r4, sp, r8, lsl #22
 *   @0x318ae0 .word 0x4604b510
 *   @0x318ae4 .word 0xfff0f7ff
 *   @0x318ae8 .word 0xf7644620
 *   @0x318aec qsub16mi lr, r0, r2
 *   @0x318af0 svclt #0xbd10
 *   @0x318af4 movwhs r11, #0x1538
 *   @0x318af8 strmi r6, [r12], -r5, lsl #16
 *   @0x318afc strmi r6, [r8, sp, ror #17]!
 *   @0x318b00 andhs r11, r1, r8, lsl #2
 *   @0x318b04 stmdbmi r4, {r3, r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x318b08 ldrbtmi r4, [r9], #-1568
 *   @0x318b0c pop {r0, r3, r11, sp, lr}
 *   @0x318b10 .word 0xf7ff4038
 *   @0x318b14 svclt #0xbc29
 *   @0x318b18 andeq r9, sp, r10, lsl r1
 *   @0x318b1c mvnsmi lr, sp, lsr #18
 *   @0x318b20 stmdavs r7, {r2, r7, r12, sp, pc}
 *   @0x318b24 .word 0xf10d4698
 *   @0x318b28 movwls r0, #0x30f
 *   @0x318b2c strmi r4, [r4], -r3, asr #12
 *   @0x318b30 .word 0x460e693f
 *   @0x318b34 .word 0x47b84615
 *   @0x318b38 .word 0xf89d4603
 *   @0x318b3c stmiblt r3, {r0, r1, r2, r3}
 *   @0x318b40 orrlt r6, r12, r4, ror #17
 *   @0x318b44 strtmi r4, [r0], -r12, lsl #18
 *   @0x318b48 ldrbtmi r4, [r9], #-2572
 *   @0x318b4c ldrbtmi r6, [r10], #-2057
 *   @0x318b50 .word 0xff78f7fe
 *   @0x318b54 stmdavs r4, {r6, r8, r12, sp, pc}
 *   @0x318b58 ldmvs r1!, {r1, r3, r5, r9, r10, lr} ^
 *   @0x318b5c stmvs r4!, {r0, r1, r6, r9, r10, lr} ^
 *   @0x318b60 andlt r4, r4, r0, lsr #15
 *   @0x318b64 ldrhhi lr, [r0, #141]!
 *   @0x318b68 strtmi r6, [r0], -r3, lsr #16
 *   @0x318b6c qsub8mi r6, r10, r1
 *   @0x318b70 .word 0x4798689b
 *   @0x318b74 svclt #0xe7f5
 *   @0x318b78 strheq r9, [sp], -r10
 *   @0x318b7c andeq r4, sp, r6, lsr #21
 *   @0x318b80 mvnsmi lr, sp, lsr #18
 *   @0x318b84 strmi r4, [r12], -r5, lsl #12
 *   @0x318b88 .word 0x46984616
 *   @0x318b8c blx 0xffe56b92 <b2_toiTime+0xffffffffff6fd6ee>
 *   @0x318b90 stmdahs r0, {r0, r1, r2, r9, r10, lr}
 *   @0x318b94 stmdavs r11!, {r1, r2, r5, r8, r12, lr, pc}
 *   @0x318b98 .word 0x0c04f853
 *   @0x318b9c eorle r2, r9, r0, lsl #24
 *   @0x318ba0 .word 0xf8536823
 *   @0x318ba4 .word 0xf7ff1c04
 *   @0x318ba8 stmiblt r0, {r0, r3, r5, r6, r7, r8, r9, r11, r12, sp, lr, pc} ^
 *   @0x318bac stmvs r7!, {r0, r1, r3, r5, r7, r11, sp, lr}
 *   @0x318bb0 andeq lr, r3, #225280
 *   @0x318bb4 .word 0xf1b8d114
 *   @0x318bb8 andsle r0, r6, r1, lsl #30
 *   @0x318bbc svceq #0x4f018
 *   @0x318bc0 streq pc, [r1, -r8, lsr #32]
 *   @0x318bc4 bfieq sp, r3, #2, #26
 *   @0x318bc8 svclt #0x584628
 *   @0x318bcc streq pc, [r4, -r7, asr #32]
 *   @0x318bd0 ldrtmi r4, [r2], -r1, lsr #12
 *   @0x318bd4 pop {r0, r1, r3, r4, r5, r9, r10, lr}
 *   @0x318bd8 .word 0xf7ff41f0
 *   @0x318bdc shadd8mi r11, r8, pc
 *   @0x318be0 ldrhhi lr, [r0, #141]!
 *   @0x318be4 pop {r0, sp}
 *   @0x318be8 .word 0x270381f0
 *   @0x318bec ldrmi lr, [r0], -r11, ror #15
 *   @0x318bf0 ldrhhi lr, [r0, #141]!
 *   @0x318bf4 .word 0xf814f000
 *   @0x318bf8 andhs r11, r4, r0, lsl r5
 *   @0x318bfc ldc2 p7, c15, [r2, #-1016]
 *   @0x318c00 .word 0xf7ff4604
 *   @0x318c04 stmdbmi r4, {r0, r1, r3, r6, r7, r8, r9, r11, r12, sp, lr, pc}
 *   @0x318c08 bmi 0x42a490 <g_RomDisk+0x32c70>
 *   @0x318c0c stmdavs r9, {r0, r3, r4, r5, r6, r10, lr}
 *   @0x318c10 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr}
 *   @0x318c14 stc2l p7, c15, [r4, #-1016]
 *   @0x318c18 andeq r9, sp, r12, lsl r0
 *   @0x318c1c andeq r9, sp, r12, lsl r0
 *   @0x318c20 andhs r11, r4, r0, lsl r5
 *   @0x318c24 ldc2l p7, c15, [lr], #1016
 *   @0x318c28 .word 0xf7ff4604
 *   @0x318c2c stmdbmi r4, {r0, r1, r6, r7, r8, r9, r11, r12, sp, lr, pc}
 *   @0x318c30 bmi 0x42a4b8 <g_RomDisk+0x32c98>
 *   @0x318c34 stmdavs r9, {r0, r3, r4, r5, r6, r10, lr}
 *   @0x318c38 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr}
 *   @0x318c3c ldc2 p7, c15, [r0, #-1016]!
 *   @0x318c40 strdeq r8, r9, [sp], -r12
 *
 * ══ §23/29 JS_RegExp_prototype_exec(RValue&, CInstance*, CInstance*, int, RValue*)  0x257248  size 1140  285 条（0x257248..0x2576bc）
 * @func 0x257248 0x2576bc  size 1140  285 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2575c4→0x3eb70c, 0x2575e8→0x3eb70c, 0x2575f4→0x3eb70c, 0x257600→0x3eb70c, 0x25760c→0x3eb70c, 0x257654→0x3eb70c
 * 调用序列: JS_Object_Put(YYObjectBase*, RValue*, char const*, bool)×3 / JSThrowTypeError(char const*)×2 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×2 / JS_RegExp_prototype_exec(RValue&, CInstance*, CInstance*, int, RValue*)+0x44×2 / 0xb6574 / F_JS_ToString(RValue&, RValue*) / YYGetString(RValue const*, int) / 0xb6538
 * 字段偏移 top8: 0x14×4 / 0x20×4 / 0x10×3 / 0x1c×3 / 0x5c×3 / 0xc×3 / 0x38×3 / 0x3c×3
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x257248 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25724c mov r8, r1
 *   @0x257250 ldr r1, [pc, #0x41c]
 *   @0x257254 sub sp, sp, #548
 *   @0x257258 mov r9, r0
 *   @0x25725c ldr r0, [r8, #0x40]
 *   @0x257260 add r1, pc, r1
 *   @0x257264 str r2, [sp, #0x18]
 *   @0x257268 bl 0xb6574 <strcmp@plt>
 *   @0x25726c ldr r6, [pc, #0x404]
 *   @0x257270 add r6, pc, r6
 *   @0x257274 str r6, [sp, #0x10]
 *   @0x257278 subs r5, r0, #0
 *   @0x25727c beq 0x257294 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x257280 ldr r0, [pc, #0x3f4]
 *   @0x257284 add r0, pc, r0
 *   @0x257288 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25728c add sp, sp, #548
 *   @0x257290 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x257294 add r4, sp, #64
 *   @0x257298 movw r12, #0xfe20
 *   @0x25729c add r10, sp, #544
 *   @0x2572a0 movt r12, #0xffff
 *   @0x2572a4 ldr r1, [sp, #0x248]
 *   @0x2572a8 mov r0, r4
 *   @0x2572ac mov r2, #0
 *   @0x2572b0 mov r3, #0
 *   @0x2572b4 mvn lr, #-16777216
 *   @0x2572b8 str r5, [sp, #0x48]
 *   @0x2572bc strd r2, r3, [r10, r12]
 *   @0x2572c0 str lr, [sp, #0x4c]
 *   @0x2572c4 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x2572c8 cmp r0, #2
 *   @0x2572cc beq 0x25728c <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x2572d0 cmp r0, #1
 *   @0x2572d4 beq 0x257660 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x418>
 *   @0x2572d8 mov r1, r5
 *   @0x2572dc mov r0, r4
 *   @0x2572e0 add r11, sp, #80
 *   @0x2572e4 str r11, [sp, #0x1c]
 *   @0x2572e8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x2572ec add r6, sp, #96
 *   @0x2572f0 ldr r11, [pc, #0x388]
 *   @0x2572f4 add r11, pc, r11
 *   @0x2572f8 str r0, [sp, #0x14]
 *   @0x2572fc bl 0xb6538 <strlen@plt>
 *   @0x257300 ldr r2, [pc, #0x37c]
 *   @0x257304 add r1, sp, #80
 *   @0x257308 str r5, [sp, #0x50]
 *   @0x25730c add r2, pc, r2
 *   @0x257310 str r5, [sp, #0x54]
 *   @0x257314 str r5, [sp, #0x58]
 *   @0x257318 str r5, [sp, #0x5c]
 *   @0x25731c str r5, [sp, #0x60]
 *   @0x257320 str r5, [sp, #0x64]
 *   @0x257324 str r5, [sp, #0x68]
 *   @0x257328 str r5, [sp, #0x6c]
 *   @0x25732c mov r4, r0
 *   @0x257330 mov r0, r8
 *   @0x257334 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x257338 ldr r2, [pc, #0x348]
 *   @0x25733c mov r1, r6
 *   @0x257340 mov r0, r8
 *   @0x257344 add r2, pc, r2
 *   @0x257348 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x25734c mov r1, r5
 *   @0x257350 add r0, sp, #80
 *   @0x257354 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x257358 mov r1, r5
 *   @0x25735c mov r10, r0
 *   @0x257360 mov r0, r6
 *   @0x257364 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x257368 ldr r6, [pc, #0x31c]
 *   @0x25736c str r11, [sp, #0x24]
 *   @0x257370 ldr r11, [pc, #0x318]
 *   @0x257374 add r6, pc, r6
 *   @0x257378 str r6, [sp, #0x20]
 *   @0x25737c add r11, pc, r11
 *   @0x257380 ldr r6, [pc, #0x30c]
 *   @0x257384 str r11, [sp, #0x2c]
 *   @0x257388 ldr r11, [pc, #0x308]
 *   @0x25738c add r6, pc, r6
 *   @0x257390 str r6, [sp, #0x28]
 *   @0x257394 add r11, pc, r11
 *   @0x257398 ldr r6, [pc, #0x2fc]
 *   @0x25739c str r11, [sp, #0x34]
 *   @0x2573a0 add r6, pc, r6
 *   @0x2573a4 str r6, [sp, #0x30]
 *   @0x2573a8 cmp r0, #0
 *   @0x2573ac moveq r10, #0
 *   @0x2573b0 lsr r11, r10, #31
 *   @0x2573b4 cmp r10, r4
 *   @0x2573b8 movle r7, r11
 *   @0x2573bc orrgt r7, r11, #1
 *   @0x2573c0 ldr r2, [sp, #0x14]
 *   @0x2573c4 cmp r7, #0
 *   @0x2573c8 mov r3, r4
 *   @0x2573cc add r5, sp, #144
 *   @0x2573d0 mov r12, #100
 *   @0x2573d4 bne 0x257618 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x3d0>
 *   @0x2573d8 ldr r0, [r8, #0x1c]
 *   @0x2573dc ldr r1, [r8, #0x20]
 *   @0x2573e0 str r10, [sp]
 *   @0x2573e4 str r7, [sp, #0x4]
 *   @0x2573e8 str r5, [sp, #0x8]
 *   @0x2573ec str r12, [sp, #0xc]
 *   @0x2573f0 bl 0x279390 <pcre_exec>
 *   @0x2573f4 cmp r0, #0
 *   @0x2573f8 blt 0x257590 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x348>
 *   @0x2573fc ldr r1, [r8, #0x20]
 *   @0x257400 add r10, sp, #544
 *   @0x257404 mov r6, r0
 *   @0x257408 mov r2, #2
 *   @0x25740c ldr r0, [r8, #0x1c]
 *   @0x257410 add r3, sp, #56
 *   @0x257414 bl 0x25ee20 <pcre_fullinfo>
 *   @0x257418 add r3, r10, r6, lsl #3
 *   @0x25741c vldr s14, [r3, #-404]
 *   @0x257420 vcvt.f64.s32 d7, s14
 *   @0x257424 ldr r2, [pc, #0x274]
 *   @0x257428 mov r0, r8
 *   @0x25742c add r1, sp, #80
 *   @0x257430 mov r3, #1
 *   @0x257434 add r2, pc, r2
 *   @0x257438 mov r4, r10
 *   @0x25743c str r7, [sp, #0x5c]
 *   @0x257440 ldr r10, [sp, #0x90]
 *   @0x257444 vstr d7, [sp, #80]
 *   @0x257448 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x25744c ldr r11, [sp, #0x248]
 *   @0x257450 mov r1, r8
 *   @0x257454 ldr r2, [sp, #0x18]
 *   @0x257458 mov r0, r9
 *   @0x25745c mov r3, r7
 *   @0x257460 str r11, [sp]
 *   @0x257464 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x257468 ldr r8, [r9]
 *   @0x25746c ldr r1, [pc, #0x230]
 *   @0x257470 mov r2, r10
 *   @0x257474 mov r3, #7
 *   @0x257478 add r1, pc, r1
 *   @0x25747c mov r0, r8
 *   @0x257480 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii>
 *   @0x257484 ldr r1, [pc, #0x21c]
 *   @0x257488 mov r0, r8
 *   @0x25748c ldr r2, [sp, #0x14]
 *   @0x257490 add r1, pc, r1
 *   @0x257494 mov r3, #7
 *   @0x257498 bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i>
 *   @0x25749c ldr r3, [sp, #0x38]
 *   @0x2574a0 ldr r2, [pc, #0x204]
 *   @0x2574a4 mov r0, r8
 *   @0x2574a8 add r3, r3, #1
 *   @0x2574ac str r7, [sp, #0x78]
 *   @0x2574b0 add r2, pc, r2
 *   @0x2574b4 str r7, [sp, #0x7c]
 *   @0x2574b8 vmov s14, r3
 *   @0x2574bc mov r3, r7
 *   @0x2574c0 vcvt.f64.s32 d7, s14
 *   @0x2574c4 vmov r10, r11, d7
 *   @0x2574c8 str r10, [r4, #-0x1b0]!
 *   @0x2574cc str r11, [r4, #0x4]
 *   @0x2574d0 mov r1, r4
 *   @0x2574d4 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x2574d8 ldr r3, [sp, #0x38]
 *   @0x2574dc mov r11, #5
 *   @0x2574e0 str r7, [sp, #0x80]
 *   @0x2574e4 cmp r3, #0
 *   @0x2574e8 str r7, [sp, #0x84]
 *   @0x2574ec str r7, [sp, #0x88]
 *   @0x2574f0 str r11, [sp, #0x8c]
 *   @0x2574f4 blt 0x25728c <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x2574f8 mov r8, r7
 *   @0x2574fc mov r10, r7
 *   @0x257500 add r2, sp, #60
 *   @0x257504 add r7, sp, #128
 *   @0x257508 str r2, [sp, #0x10]
 *   @0x25750c b 0x257544 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x2fc>
 *   @0x257510 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x257514 mov r2, #7
 *   @0x257518 mov r1, r4
 *   @0x25751c str r2, [sp, #0x88]
 *   @0x257520 mov r0, r9
 *   @0x257524 mov r2, r7
 *   @0x257528 add r8, r8, #1
 *   @0x25752c bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_>
 *   @0x257530 ldr r0, [sp, #0x3c]
 *   @0x257534 bl 0x25f6ac <pcre_free_substring>
 *   @0x257538 ldr r3, [sp, #0x38]
 *   @0x25753c cmp r3, r8
 *   @0x257540 blt 0x25728c <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x257544 add r2, sp, #60
 *   @0x257548 mov r1, r5
 *   @0x25754c str r2, [sp]
 *   @0x257550 mov r3, r8
 *   @0x257554 ldr r0, [sp, #0x14]
 *   @0x257558 mov r2, r6
 *   @0x25755c str r10, [sp, #0x3c]
 *   @0x257560 bl 0x25f5e8 <pcre_get_substring>
 *   @0x257564 vmov s13, r8
 *   @0x257568 ldr r3, [sp, #0x3c]
 *   @0x25756c mov r0, r7
 *   @0x257570 vcvt.f64.s32 d7, s13
 *   @0x257574 cmp r3, #0
 *   @0x257578 mov r1, r3
 *   @0x25757c vstr d7, [sp, #112]
 *   @0x257580 bne 0x257510 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x2c8>
 *   @0x257584 str r11, [sp, #0x8c]
 *   @0x257588 str r3, [sp, #0x80]
 *   @0x25758c b 0x257514 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x2cc>
 *   @0x257590 add r6, r0, #6
 *   @0x257594 cmp r6, #5
 *   @0x257598 addls pc, pc, r6, lsl #2
 *   @0x25759c b 0x257654 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x40c>
 *   @0x2575a0 b 0x25760c <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x3c4>
 *   @0x2575a4 b 0x257600 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x3b8>
 *   @0x2575a8 b 0x2575f4 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x3ac>
 *   @0x2575ac b 0x2575e8 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x3a0>
 *   @0x2575b0 b 0x2575c4 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x37c>
 *   @0x2575b4 b 0x2575b8 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x370>
 *   @0x2575b8 add r10, r10, #1
 *   @0x2575bc lsr r11, r10, #31
 *   @0x2575c0 b 0x2573b4 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x2575c4 ldr r3, [pc, #0xe4]
 *   @0x2575c8 ldr r1, [sp, #0x34]
 *   @0x2575cc ldr r6, [sp, #0x10]
 *   @0x2575d0 ldr r3, [r6, r3]
 *   @0x2575d4 ldr r0, [r3]
 *   @0x2575d8 ldr r3, [r0]
 *   @0x2575dc ldr r3, [r3, #0xc]
 *   @0x2575e0 blx r3
 *   @0x2575e4 b 0x2573b4 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x2575e8 ldr r3, [pc, #0xc0]
 *   @0x2575ec ldr r1, [sp, #0x30]
 *   @0x2575f0 b 0x2575cc <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x384>
 *   @0x2575f4 ldr r3, [pc, #0xb4]
 *   @0x2575f8 ldr r1, [sp, #0x2c]
 *   @0x2575fc b 0x2575cc <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x384>
 *   @0x257600 ldr r3, [pc, #0xa8]
 *   @0x257604 ldr r1, [sp, #0x28]
 *   @0x257608 b 0x2575cc <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x384>
 *   @0x25760c ldr r3, [pc, #0x9c]
 *   @0x257610 ldr r1, [sp, #0x24]
 *   @0x257614 b 0x2575cc <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x384>
 *   @0x257618 ldr r2, [pc, #0x94]
 *   @0x25761c mov r12, #0
 *   @0x257620 mov r3, r12
 *   @0x257624 mov r0, r8
 *   @0x257628 add r1, sp, #80
 *   @0x25762c add r2, pc, r2
 *   @0x257630 mov r4, #0
 *   @0x257634 mov r5, #0
 *   @0x257638 str r12, [sp, #0x5c]
 *   @0x25763c strd r4, r5, [sp, #80]
 *   @0x257640 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x257644 mov r3, #12
 *   @0x257648 str r3, [r9, #0xc]
 *   @0x25764c add sp, sp, #548
 *   @0x257650 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x257654 ldr r3, [pc, #0x54]
 *   @0x257658 ldr r1, [sp, #0x20]
 *   @0x25765c b 0x2575cc <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_+0x384>
 *   @0x257660 ldr r0, [pc, #0x50]
 *   @0x257664 add r0, pc, r0
 *   @0x257668 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25766c add sp, sp, #548
 *   @0x257670 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x257674 andeq lr, pc, r12, asr #19
 *   @0x257678 andseq r10, r9, r0, ror #19
 *   @0x25767c andeq lr, pc, r4, asr #25
 *   @0x257680 andeq lr, pc, r8, lsr #28
 *   @0x257684 muleq pc, r4, sp
 *   @0x257688 muleq sp, r4, r11
 *   @0x25768c andeq lr, pc, r4, asr #27
 *   @0x257690 andeq lr, pc, r4, ror #26
 *   @0x257694 andeq lr, pc, r0, ror sp
 *   @0x257698 andeq lr, pc, r8, lsl sp
 *   @0x25769c andeq lr, pc, r4, lsr #26
 *   @0x2576a0 andeq lr, pc, r12, ror #24
 *   @0x2576a4 muleq lr, r0, sp
 *   @0x2576a8 strheq pc, [pc], -r4
 *   @0x2576ac strheq r9, [sp], -r12
 *   @0x2576b0 .word 0xffffbac4
 *   @0x2576b4 andeq lr, pc, r4, ror r10
 *   @0x2576b8 andeq pc, pc, r0, lsr #9
 *
 * ══ §24/29 Shader_Build(GLSLShader*, char**, bool*, int, char**)  0x187468  size 1136  284 条（0x187468..0x1878d8）
 * @func 0x187468 0x1878d8  size 1136  284 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadShader(unsigned int, char const*, char**)×2 / SetupErrorString(char**, char*)×2 / 0xb6544 / 0xb655c / InitialiseUniforms(GLSLShader*) / Shader_Build(GLSLShader*, char**, bool*, int, char**)+0x50 / InitialisePreParsedAttribs(GLSLShader*, int, char**)
 * 字段偏移 top8: 0x8×25 / 0x4×4 / 0xc×2 / 0x2b4×2 / 0x22c×2 / 0x1dc×2 / 0x28×2 / 0x3e8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x187468 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18746c subs r4, r0, #0
 *   @0x187470 ldr r7, [pc, #0x3e8]
 *   @0x187474 sub sp, sp, #12
 *   @0x187478 mov r8, r1
 *   @0x18747c mov r6, r2
 *   @0x187480 mov r9, r3
 *   @0x187484 add r7, pc, r7
 *   @0x187488 beq 0x187600 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x198>
 *   @0x18748c movw r0, #0x8b31
 *   @0x187490 ldr r1, [r4, #0xc]
 *   @0x187494 mov r2, r8
 *   @0x187498 bl 0x1865bc <_Z10LoadShaderjPKcPPc>
 *   @0x18749c cmp r0, #0
 *   @0x1874a0 str r0, [r4]
 *   @0x1874a4 bne 0x1874c4 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x5c>
 *   @0x1874a8 cmp r6, #0
 *   @0x1874ac beq 0x187600 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x198>
 *   @0x1874b0 mov r5, r0
 *   @0x1874b4 strb r0, [r6]
 *   @0x1874b8 mov r0, r5
 *   @0x1874bc add sp, sp, #12
 *   @0x1874c0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1874c4 movw r0, #0x8b30
 *   @0x1874c8 ldr r1, [r4, #0x10]
 *   @0x1874cc mov r2, r8
 *   @0x1874d0 bl 0x1865bc <_Z10LoadShaderjPKcPPc>
 *   @0x1874d4 cmp r0, #0
 *   @0x1874d8 str r0, [r4, #0x4]
 *   @0x1874dc beq 0x187610 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x1a8>
 *   @0x1874e0 ldr r3, [pc, #0x37c]
 *   @0x1874e4 ldr r3, [r7, r3]
 *   @0x1874e8 ldr r3, [r3]
 *   @0x1874ec blx r3
 *   @0x1874f0 cmp r0, #0
 *   @0x1874f4 mov r5, r0
 *   @0x1874f8 str r0, [r4, #0x8]
 *   @0x1874fc beq 0x187630 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x1c8>
 *   @0x187500 ldr r3, [pc, #0x360]
 *   @0x187504 ldr r1, [r4]
 *   @0x187508 ldr r5, [r7, r3]
 *   @0x18750c ldr r3, [r5]
 *   @0x187510 blx r3
 *   @0x187514 ldr r3, [r5]
 *   @0x187518 ldr r1, [r4, #0x4]
 *   @0x18751c ldr r0, [r4, #0x8]
 *   @0x187520 blx r3
 *   @0x187524 ldr r3, [pc, #0x340]
 *   @0x187528 ldr r0, [r4, #0x8]
 *   @0x18752c ldr r3, [r7, r3]
 *   @0x187530 ldr r3, [r3]
 *   @0x187534 blx r3
 *   @0x187538 ldr r3, [pc, #0x330]
 *   @0x18753c add r2, sp, #8
 *   @0x187540 mov r1, #0
 *   @0x187544 ldr r0, [r4, #0x8]
 *   @0x187548 str r1, [r2, #-0x8]!
 *   @0x18754c movw r1, #0x8b82
 *   @0x187550 ldr r5, [r7, r3]
 *   @0x187554 mov r2, sp
 *   @0x187558 ldr r3, [r5]
 *   @0x18755c blx r3
 *   @0x187560 ldr r3, [sp]
 *   @0x187564 cmp r3, #0
 *   @0x187568 bne 0x187650 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x1e8>
 *   @0x18756c add r2, sp, #8
 *   @0x187570 ldr r12, [r5]
 *   @0x187574 movw r1, #0x8b84
 *   @0x187578 ldr r0, [r4, #0x8]
 *   @0x18757c str r3, [r2, #-0x4]!
 *   @0x187580 blx r12
 *   @0x187584 ldr r0, [sp, #0x4]
 *   @0x187588 cmp r0, #1
 *   @0x18758c movle r0, #1024
 *   @0x187590 strle r0, [sp, #0x4]
 *   @0x187594 bl 0xb6544 <malloc@plt>
 *   @0x187598 ldr r12, [pc, #0x2d4]
 *   @0x18759c mov r2, #0
 *   @0x1875a0 ldr r1, [sp, #0x4]
 *   @0x1875a4 ldr r12, [r7, r12]
 *   @0x1875a8 ldr r12, [r12]
 *   @0x1875ac mov r5, r0
 *   @0x1875b0 mov r3, r0
 *   @0x1875b4 ldr r0, [r4, #0x8]
 *   @0x1875b8 blx r12
 *   @0x1875bc ldr r3, [pc, #0x2b4]
 *   @0x1875c0 ldr r1, [pc, #0x2b4]
 *   @0x1875c4 mov r2, r5
 *   @0x1875c8 ldr r3, [r7, r3]
 *   @0x1875cc add r1, pc, r1
 *   @0x1875d0 ldr r0, [r3]
 *   @0x1875d4 ldr r3, [r0]
 *   @0x1875d8 ldr r3, [r3, #0xc]
 *   @0x1875dc blx r3
 *   @0x1875e0 mov r0, r8
 *   @0x1875e4 mov r1, r5
 *   @0x1875e8 bl 0x186544 <_Z16SetupErrorStringPPcS_>
 *   @0x1875ec mov r0, r5
 *   @0x1875f0 bl 0xb655c <free@plt>
 *   @0x1875f4 cmp r6, #0
 *   @0x1875f8 movne r3, #0
 *   @0x1875fc strbne r3, [r6]
 *   @0x187600 mov r5, #0
 *   @0x187604 mov r0, r5
 *   @0x187608 add sp, sp, #12
 *   @0x18760c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x187610 cmp r6, #0
 *   @0x187614 beq 0x187600 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x198>
 *   @0x187618 mov r5, r0
 *   @0x18761c mov r3, #1
 *   @0x187620 mov r0, r5
 *   @0x187624 strb r3, [r6]
 *   @0x187628 add sp, sp, #12
 *   @0x18762c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x187630 ldr r1, [pc, #0x248]
 *   @0x187634 mov r0, r8
 *   @0x187638 add r1, pc, r1
 *   @0x18763c bl 0x186544 <_Z16SetupErrorStringPPcS_>
 *   @0x187640 cmp r6, #0
 *   @0x187644 strbne r5, [r6]
 *   @0x187648 bne 0x1874b8 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x50>
 *   @0x18764c b 0x187600 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x198>
 *   @0x187650 ldr r3, [pc, #0x22c]
 *   @0x187654 ldr r1, [pc, #0x22c]
 *   @0x187658 ldr r0, [r4, #0x8]
 *   @0x18765c ldr r5, [r7, r3]
 *   @0x187660 add r1, pc, r1
 *   @0x187664 ldr r3, [r5]
 *   @0x187668 blx r3
 *   @0x18766c ldr r1, [pc, #0x218]
 *   @0x187670 ldr r3, [r5]
 *   @0x187674 add r1, pc, r1
 *   @0x187678 str r0, [r4, #0x1c]
 *   @0x18767c ldr r0, [r4, #0x8]
 *   @0x187680 blx r3
 *   @0x187684 ldr r1, [pc, #0x204]
 *   @0x187688 ldr r3, [r5]
 *   @0x18768c add r1, pc, r1
 *   @0x187690 str r0, [r4, #0x20]
 *   @0x187694 ldr r0, [r4, #0x8]
 *   @0x187698 blx r3
 *   @0x18769c ldr r1, [pc, #0x1f0]
 *   @0x1876a0 ldr r3, [r5]
 *   @0x1876a4 add r1, pc, r1
 *   @0x1876a8 str r0, [r4, #0x24]
 *   @0x1876ac ldr r0, [r4, #0x8]
 *   @0x1876b0 blx r3
 *   @0x1876b4 ldr r3, [pc, #0x1dc]
 *   @0x1876b8 ldr r1, [pc, #0x1dc]
 *   @0x1876bc add r1, pc, r1
 *   @0x1876c0 str r0, [r4, #0x28]
 *   @0x1876c4 ldr r5, [r7, r3]
 *   @0x1876c8 ldr r0, [r4, #0x8]
 *   @0x1876cc ldr r3, [r5]
 *   @0x1876d0 blx r3
 *   @0x1876d4 ldr r1, [pc, #0x1c4]
 *   @0x1876d8 ldr r3, [r5]
 *   @0x1876dc add r1, pc, r1
 *   @0x1876e0 str r0, [r4, #0x3c]
 *   @0x1876e4 ldr r0, [r4, #0x8]
 *   @0x1876e8 blx r3
 *   @0x1876ec ldr r1, [pc, #0x1b0]
 *   @0x1876f0 ldr r3, [r5]
 *   @0x1876f4 add r1, pc, r1
 *   @0x1876f8 str r0, [r4, #0x40]
 *   @0x1876fc ldr r0, [r4, #0x8]
 *   @0x187700 blx r3
 *   @0x187704 ldr r1, [pc, #0x19c]
 *   @0x187708 ldr r3, [r5]
 *   @0x18770c add r1, pc, r1
 *   @0x187710 str r0, [r4, #0x44]
 *   @0x187714 ldr r0, [r4, #0x8]
 *   @0x187718 blx r3
 *   @0x18771c ldr r1, [pc, #0x188]
 *   @0x187720 ldr r3, [r5]
 *   @0x187724 add r1, pc, r1
 *   @0x187728 str r0, [r4, #0x48]
 *   @0x18772c ldr r0, [r4, #0x8]
 *   @0x187730 blx r3
 *   @0x187734 ldr r1, [pc, #0x174]
 *   @0x187738 ldr r3, [r5]
 *   @0x18773c add r1, pc, r1
 *   @0x187740 str r0, [r4, #0x4c]
 *   @0x187744 ldr r0, [r4, #0x8]
 *   @0x187748 blx r3
 *   @0x18774c ldr r1, [pc, #0x160]
 *   @0x187750 ldr r3, [r5]
 *   @0x187754 add r1, pc, r1
 *   @0x187758 str r0, [r4, #0x50]
 *   @0x18775c ldr r0, [r4, #0x8]
 *   @0x187760 blx r3
 *   @0x187764 ldr r1, [pc, #0x14c]
 *   @0x187768 ldr r3, [r5]
 *   @0x18776c add r1, pc, r1
 *   @0x187770 str r0, [r4, #0x54]
 *   @0x187774 ldr r0, [r4, #0x8]
 *   @0x187778 blx r3
 *   @0x18777c ldr r1, [pc, #0x138]
 *   @0x187780 ldr r3, [r5]
 *   @0x187784 add r1, pc, r1
 *   @0x187788 str r0, [r4, #0x58]
 *   @0x18778c ldr r0, [r4, #0x8]
 *   @0x187790 blx r3
 *   @0x187794 ldr r1, [pc, #0x124]
 *   @0x187798 ldr r3, [r5]
 *   @0x18779c add r1, pc, r1
 *   @0x1877a0 str r0, [r4, #0x5c]
 *   @0x1877a4 ldr r0, [r4, #0x8]
 *   @0x1877a8 blx r3
 *   @0x1877ac ldr r1, [pc, #0x110]
 *   @0x1877b0 ldr r3, [r5]
 *   @0x1877b4 add r1, pc, r1
 *   @0x1877b8 str r0, [r4, #0x60]
 *   @0x1877bc ldr r0, [r4, #0x8]
 *   @0x1877c0 blx r3
 *   @0x1877c4 ldr r1, [pc, #0xfc]
 *   @0x1877c8 ldr r3, [r5]
 *   @0x1877cc add r1, pc, r1
 *   @0x1877d0 str r0, [r4, #0x64]
 *   @0x1877d4 ldr r0, [r4, #0x8]
 *   @0x1877d8 blx r3
 *   @0x1877dc ldr r1, [pc, #0xe8]
 *   @0x1877e0 ldr r3, [r5]
 *   @0x1877e4 add r1, pc, r1
 *   @0x1877e8 str r0, [r4, #0x68]
 *   @0x1877ec ldr r0, [r4, #0x8]
 *   @0x1877f0 blx r3
 *   @0x1877f4 ldr r1, [pc, #0xd4]
 *   @0x1877f8 ldr r3, [r5]
 *   @0x1877fc add r1, pc, r1
 *   @0x187800 str r0, [r4, #0x6c]
 *   @0x187804 ldr r0, [r4, #0x8]
 *   @0x187808 blx r3
 *   @0x18780c ldr r1, [pc, #0xc0]
 *   @0x187810 ldr r3, [r5]
 *   @0x187814 add r1, pc, r1
 *   @0x187818 str r0, [r4, #0x70]
 *   @0x18781c ldr r0, [r4, #0x8]
 *   @0x187820 blx r3
 *   @0x187824 str r0, [r4, #0x74]
 *   @0x187828 mov r0, r4
 *   @0x18782c bl 0x186834 <_Z18InitialiseUniformsP10GLSLShader>
 *   @0x187830 ldr r3, [sp, #0x28]
 *   @0x187834 cmp r3, #0
 *   @0x187838 cmpne r9, #0
 *   @0x18783c movle r5, #0
 *   @0x187840 movgt r5, #1
 *   @0x187844 movle r5, #1
 *   @0x187848 ble 0x1874b8 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x50>
 *   @0x18784c mov r0, r4
 *   @0x187850 mov r1, r9
 *   @0x187854 mov r2, r3
 *   @0x187858 bl 0x186eac <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc>
 *   @0x18785c b 0x1874b8 <_Z12Shader_BuildP10GLSLShaderPPcPbiS2_+0x50>
 *   @0x187860 eoreq r10, r6, r12, asr #15
 *   @0x187864 .word 0xffffbba8
 *   @0x187868 .word 0xffffbbac
 *   @0x18786c .word 0xffffbbb0
 *   @0x187870 .word 0xffffbbb4
 *   @0x187874 .word 0xffffbbb8
 *   @0x187878 .word 0xffffbac4
 *   @0x18787c andseq r4, r12, r0, asr #19
 *   @0x187880 ldrsheq r4, [r12], -r4
 *   @0x187884 .word 0xffffbbbc
 *   @0x187888 ldrsheq r4, [r12], -r4
 *   @0x18788c andseq r4, r12, r12, lsr #15
 *   @0x187890 andseq r4, r12, r4, lsl #15
 *   @0x187894 ldrheq r4, [r12], -r12
 *   @0x187898 .word 0xffffbbc0
 *   @0x18789c mulseq r12, r4, r7
 *   @0x1878a0 andseq r4, r12, r8, ror #10
 *   @0x1878a4 andseq r4, r12, r8, ror #14
 *   @0x1878a8 andseq r4, r12, r4, ror #14
 *   @0x1878ac andseq r4, r12, r0, ror #14
 *   @0x1878b0 andseq r4, r12, r4, asr r7
 *   @0x1878b4 andseq r4, r12, r12, asr #14
 *   @0x1878b8 andseq r4, r12, r8, asr #14
 *   @0x1878bc andseq r4, r12, r0, asr #14
 *   @0x1878c0 andseq r4, r12, r12, lsr r7
 *   @0x1878c4 andseq r4, r12, r8, lsr r7
 *   @0x1878c8 andseq r4, r12, r8, lsr r7
 *   @0x1878cc andseq r4, r12, r12, lsr r7
 *   @0x1878d0 andseq r4, r12, r8, asr #14
 *   @0x1878d4 andseq r4, r12, r4, asr r7
 *
 * ══ §25/29 vorbis_book_decodevv_add  0x228f20  size 1136  284 条（0x228f20..0x229390）
 * @func 0x228f20 0x229390  size 1136  284 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_look×6 / oggpack_adv×6 / vorbis_book_decodevv_add+0x460×2 / vorbis_book_decodevv_add+0x210 / vorbis_book_decodevv_add+0x244 / vorbis_book_decodevv_add+0x198 / vorbis_book_decodevv_add+0x48 / vorbis_book_decodevv_add+0x54
 * 字段偏移 top8: 0x38×11 / 0x2×10 / 0x8×8 / 0xc×6 / 0x4×6 / 0x1c×4 / 0x3c×2 / 0x24×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x228f20 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x228f24 mov r9, r1
 *   @0x228f28 ldr r1, [r0, #0x8]
 *   @0x228f2c sub sp, sp, #20
 *   @0x228f30 mov r11, r0
 *   @0x228f34 mov r5, r2
 *   @0x228f38 cmp r1, #0
 *   @0x228f3c mov r10, r3
 *   @0x228f40 ble 0x229130 <vorbis_book_decodevv_add+0x210>
 *   @0x228f44 ldr r3, [r0, #0xc]
 *   @0x228f48 ldr r2, [sp, #0x40]
 *   @0x228f4c subs r3, r2, r3
 *   @0x228f50 str r3, [sp, #0x8]
 *   @0x228f54 bmi 0x229180 <vorbis_book_decodevv_add+0x260>
 *   @0x228f58 ldr r2, [sp, #0x3c]
 *   @0x228f5c mov r4, #0
 *   @0x228f60 add r2, r5, r2
 *   @0x228f64 str r2, [sp, #0xc]
 *   @0x228f68 ldr r3, [sp, #0xc]
 *   @0x228f6c cmp r5, r3
 *   @0x228f70 bge 0x229130 <vorbis_book_decodevv_add+0x210>
 *   @0x228f74 ldr r0, [sp, #0x38]
 *   @0x228f78 ldr r1, [r11, #0x24]
 *   @0x228f7c ldr r6, [r11, #0x28]
 *   @0x228f80 bl 0x23388c <oggpack_look>
 *   @0x228f84 cmp r0, #0
 *   @0x228f88 blt 0x229164 <vorbis_book_decodevv_add+0x244>
 *   @0x228f8c ldr r3, [r11, #0x20]
 *   @0x228f90 ldr r7, [r3, r0, lsl #2]
 *   @0x228f94 cmp r7, #0
 *   @0x228f98 bge 0x22913c <vorbis_book_decodevv_add+0x21c>
 *   @0x228f9c ldr r2, [r11, #0x8]
 *   @0x228fa0 ubfx r3, r7, #0x0, #0xf
 *   @0x228fa4 ubfx r7, r7, #0xf, #0xf
 *   @0x228fa8 rsb r8, r3, r2
 *   @0x228fac ldr r0, [sp, #0x38]
 *   @0x228fb0 mov r1, r6
 *   @0x228fb4 bl 0x23388c <oggpack_look>
 *   @0x228fb8 cmp r6, #1
 *   @0x228fbc movle r3, #0
 *   @0x228fc0 movgt r3, #1
 *   @0x228fc4 ands r3, r3, r0, lsr #31
 *   @0x228fc8 beq 0x229014 <vorbis_book_decodevv_add+0xf4>
 *   @0x228fcc str r4, [sp, #0x4]
 *   @0x228fd0 mov r3, r5
 *   @0x228fd4 ldr r4, [sp, #0x38]
 *   @0x228fd8 mov r5, r6
 *   @0x228fdc mov r6, r3
 *   @0x228fe0 sub r5, r5, #1
 *   @0x228fe4 mov r0, r4
 *   @0x228fe8 mov r1, r5
 *   @0x228fec bl 0x23388c <oggpack_look>
 *   @0x228ff0 cmp r5, #1
 *   @0x228ff4 movle r2, #0
 *   @0x228ff8 movgt r2, #1
 *   @0x228ffc ands r2, r2, r0, lsr #31
 *   @0x229000 bne 0x228fe0 <vorbis_book_decodevv_add+0xc0>
 *   @0x229004 ldr r4, [sp, #0x4]
 *   @0x229008 mov r3, r6
 *   @0x22900c mov r6, r5
 *   @0x229010 mov r5, r3
 *   @0x229014 cmp r0, #0
 *   @0x229018 blt 0x229380 <vorbis_book_decodevv_add+0x460>
 *   @0x22901c rev r0, r0
 *   @0x229020 movw r3, #0xf0f
 *   @0x229024 movw r1, #0xf0f0
 *   @0x229028 bfi r3, r3, #16, #16
 *   @0x22902c bfi r1, r1, #16, #16
 *   @0x229030 and r3, r3, r0, lsr #4
 *   @0x229034 and r0, r1, r0, lsl #4
 *   @0x229038 movw r1, #0x3333
 *   @0x22903c orr r0, r0, r3
 *   @0x229040 bfi r1, r1, #16, #16
 *   @0x229044 movw r3, #0xcccc
 *   @0x229048 bfi r3, r3, #16, #16
 *   @0x22904c and r1, r1, r0, lsr #2
 *   @0x229050 and r3, r3, r0, lsl #2
 *   @0x229054 orr r12, r3, r1
 *   @0x229058 rsb r3, r7, r8
 *   @0x22905c movw r0, #0xaaaa
 *   @0x229060 movw r1, #0x5555
 *   @0x229064 bfi r0, r0, #16, #16
 *   @0x229068 bfi r1, r1, #16, #16
 *   @0x22906c cmp r3, #1
 *   @0x229070 and r0, r0, r12, lsl #1
 *   @0x229074 and r1, r1, r12, lsr #1
 *   @0x229078 orr r0, r0, r1
 *   @0x22907c ble 0x2290b8 <vorbis_book_decodevv_add+0x198>
 *   @0x229080 ldr lr, [r11, #0x14]
 *   @0x229084 asr r3, r3, #1
 *   @0x229088 add r2, r3, r7
 *   @0x22908c ldr r2, [lr, r2, lsl #2]
 *   @0x229090 cmp r2, r0
 *   @0x229094 movls r1, r3
 *   @0x229098 movhi r1, #0
 *   @0x22909c cmp r2, r0
 *   @0x2290a0 add r7, r7, r1
 *   @0x2290a4 movls r3, #0
 *   @0x2290a8 rsb r8, r3, r8
 *   @0x2290ac rsb r3, r7, r8
 *   @0x2290b0 cmp r3, #1
 *   @0x2290b4 bgt 0x229084 <vorbis_book_decodevv_add+0x164>
 *   @0x2290b8 ldr r3, [r11, #0x1c]
 *   @0x2290bc ldr r0, [sp, #0x38]
 *   @0x2290c0 ldrb r1, [r3, r7]
 *   @0x2290c4 cmp r1, r6
 *   @0x2290c8 bgt 0x229170 <vorbis_book_decodevv_add+0x250>
 *   @0x2290cc bl 0x233a7c <oggpack_adv>
 *   @0x2290d0 ldr r1, [r11]
 *   @0x2290d4 ldr r3, [r11, #0x10]
 *   @0x2290d8 cmp r1, #0
 *   @0x2290dc mul r7, r7, r1
 *   @0x2290e0 add r7, r3, r7, lsl #2
 *   @0x2290e4 ble 0x228f68 <vorbis_book_decodevv_add+0x48>
 *   @0x2290e8 ldr r12, [sp, #0x8]
 *   @0x2290ec add r1, r7, r1, lsl #2
 *   @0x2290f0 mov r3, r4
 *   @0x2290f4 ldr r3, [r9, r3, lsl #2]
 *   @0x2290f8 add r4, r4, #1
 *   @0x2290fc ldr r0, [r7], #4
 *   @0x229100 cmp r4, r10
 *   @0x229104 ldr r2, [r3, r5, lsl #2]
 *   @0x229108 moveq r4, #0
 *   @0x22910c add r2, r2, r0, asr r12
 *   @0x229110 str r2, [r3, r5, lsl #2]
 *   @0x229114 addeq r5, r5, #1
 *   @0x229118 cmp r7, r1
 *   @0x22911c mov r3, r4
 *   @0x229120 bne 0x2290f4 <vorbis_book_decodevv_add+0x1d4>
 *   @0x229124 ldr r3, [sp, #0xc]
 *   @0x229128 cmp r5, r3
 *   @0x22912c blt 0x228f74 <vorbis_book_decodevv_add+0x54>
 *   @0x229130 mov r0, #0
 *   @0x229134 add sp, sp, #20
 *   @0x229138 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22913c ldr r3, [r11, #0x1c]
 *   @0x229140 ldr r0, [sp, #0x38]
 *   @0x229144 add r3, r3, r7
 *   @0x229148 ldrb r1, [r3, #-0x1]
 *   @0x22914c bl 0x233a7c <oggpack_adv>
 *   @0x229150 subs r7, r7, #1
 *   @0x229154 bhs 0x2290d0 <vorbis_book_decodevv_add+0x1b0>
 *   @0x229158 mvn r0, #0
 *   @0x22915c add sp, sp, #20
 *   @0x229160 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x229164 ldr r8, [r11, #0x8]
 *   @0x229168 mov r7, #0
 *   @0x22916c b 0x228fac <vorbis_book_decodevv_add+0x8c>
 *   @0x229170 add r1, r6, #1
 *   @0x229174 bl 0x233a7c <oggpack_adv>
 *   @0x229178 mvn r0, #0
 *   @0x22917c b 0x22915c <vorbis_book_decodevv_add+0x23c>
 *   @0x229180 ldr r3, [sp, #0x3c]
 *   @0x229184 mov r4, #0
 *   @0x229188 add r3, r5, r3
 *   @0x22918c str r3, [sp, #0xc]
 *   @0x229190 ldr r3, [sp, #0xc]
 *   @0x229194 cmp r5, r3
 *   @0x229198 bge 0x229130 <vorbis_book_decodevv_add+0x210>
 *   @0x22919c ldr r0, [sp, #0x38]
 *   @0x2291a0 ldr r1, [r11, #0x24]
 *   @0x2291a4 ldr r6, [r11, #0x28]
 *   @0x2291a8 bl 0x23388c <oggpack_look>
 *   @0x2291ac cmp r0, #0
 *   @0x2291b0 blt 0x229374 <vorbis_book_decodevv_add+0x454>
 *   @0x2291b4 ldr r3, [r11, #0x20]
 *   @0x2291b8 ldr r7, [r3, r0, lsl #2]
 *   @0x2291bc cmp r7, #0
 *   @0x2291c0 bge 0x229354 <vorbis_book_decodevv_add+0x434>
 *   @0x2291c4 ldr r2, [r11, #0x8]
 *   @0x2291c8 ubfx r3, r7, #0x0, #0xf
 *   @0x2291cc ubfx r7, r7, #0xf, #0xf
 *   @0x2291d0 rsb r8, r3, r2
 *   @0x2291d4 ldr r0, [sp, #0x38]
 *   @0x2291d8 mov r1, r6
 *   @0x2291dc bl 0x23388c <oggpack_look>
 *   @0x2291e0 cmp r6, #1
 *   @0x2291e4 movle r3, #0
 *   @0x2291e8 movgt r3, #1
 *   @0x2291ec ands r3, r3, r0, lsr #31
 *   @0x2291f0 beq 0x22923c <vorbis_book_decodevv_add+0x31c>
 *   @0x2291f4 str r4, [sp, #0x4]
 *   @0x2291f8 mov r3, r5
 *   @0x2291fc ldr r4, [sp, #0x38]
 *   @0x229200 mov r5, r6
 *   @0x229204 mov r6, r3
 *   @0x229208 sub r5, r5, #1
 *   @0x22920c mov r0, r4
 *   @0x229210 mov r1, r5
 *   @0x229214 bl 0x23388c <oggpack_look>
 *   @0x229218 cmp r5, #1
 *   @0x22921c movle r2, #0
 *   @0x229220 movgt r2, #1
 *   @0x229224 ands r2, r2, r0, lsr #31
 *   @0x229228 bne 0x229208 <vorbis_book_decodevv_add+0x2e8>
 *   @0x22922c ldr r4, [sp, #0x4]
 *   @0x229230 mov r3, r6
 *   @0x229234 mov r6, r5
 *   @0x229238 mov r5, r3
 *   @0x22923c cmp r0, #0
 *   @0x229240 blt 0x229380 <vorbis_book_decodevv_add+0x460>
 *   @0x229244 rev r0, r0
 *   @0x229248 movw r1, #0xf0f
 *   @0x22924c movw r3, #0xf0f0
 *   @0x229250 bfi r1, r1, #16, #16
 *   @0x229254 bfi r3, r3, #16, #16
 *   @0x229258 and r12, r1, r0, lsr #4
 *   @0x22925c and r0, r3, r0, lsl #4
 *   @0x229260 movw r1, #0x3333
 *   @0x229264 orr r0, r0, r12
 *   @0x229268 bfi r1, r1, #16, #16
 *   @0x22926c movw r3, #0xcccc
 *   @0x229270 bfi r3, r3, #16, #16
 *   @0x229274 and r1, r1, r0, lsr #2
 *   @0x229278 and r3, r3, r0, lsl #2
 *   @0x22927c orr r12, r3, r1
 *   @0x229280 rsb r3, r7, r8
 *   @0x229284 movw r0, #0xaaaa
 *   @0x229288 movw r1, #0x5555
 *   @0x22928c bfi r0, r0, #16, #16
 *   @0x229290 bfi r1, r1, #16, #16
 *   @0x229294 cmp r3, #1
 *   @0x229298 and r0, r0, r12, lsl #1
 *   @0x22929c and r1, r1, r12, lsr #1
 *   @0x2292a0 orr r0, r0, r1
 *   @0x2292a4 ble 0x2292e0 <vorbis_book_decodevv_add+0x3c0>
 *   @0x2292a8 ldr r12, [r11, #0x14]
 *   @0x2292ac asr r3, r3, #1
 *   @0x2292b0 add r2, r3, r7
 *   @0x2292b4 ldr r2, [r12, r2, lsl #2]
 *   @0x2292b8 cmp r2, r0
 *   @0x2292bc movls r1, r3
 *   @0x2292c0 movhi r1, #0
 *   @0x2292c4 cmp r2, r0
 *   @0x2292c8 add r7, r7, r1
 *   @0x2292cc movls r3, #0
 *   @0x2292d0 rsb r8, r3, r8
 *   @0x2292d4 rsb r3, r7, r8
 *   @0x2292d8 cmp r3, #1
 *   @0x2292dc bgt 0x2292ac <vorbis_book_decodevv_add+0x38c>
 *   @0x2292e0 ldr r3, [r11, #0x1c]
 *   @0x2292e4 ldr r0, [sp, #0x38]
 *   @0x2292e8 ldrb r1, [r3, r7]
 *   @0x2292ec cmp r1, r6
 *   @0x2292f0 bgt 0x229170 <vorbis_book_decodevv_add+0x250>
 *   @0x2292f4 bl 0x233a7c <oggpack_adv>
 *   @0x2292f8 ldr r0, [r11]
 *   @0x2292fc ldr r3, [r11, #0x10]
 *   @0x229300 cmp r0, #0
 *   @0x229304 mul r7, r7, r0
 *   @0x229308 add r3, r3, r7, lsl #2
 *   @0x22930c ble 0x229190 <vorbis_book_decodevv_add+0x270>
 *   @0x229310 ldr r2, [sp, #0x8]
 *   @0x229314 add r0, r3, r0, lsl #2
 *   @0x229318 rsb r12, r2, #0
 *   @0x22931c mov r2, r4
 *   @0x229320 ldr r2, [r9, r2, lsl #2]
 *   @0x229324 add r4, r4, #1
 *   @0x229328 ldr r6, [r3], #4
 *   @0x22932c cmp r4, r10
 *   @0x229330 ldr r1, [r2, r5, lsl #2]
 *   @0x229334 moveq r4, #0
 *   @0x229338 add r1, r1, r6, lsl r12
 *   @0x22933c str r1, [r2, r5, lsl #2]
 *   @0x229340 addeq r5, r5, #1
 *   @0x229344 cmp r3, r0
 *   @0x229348 mov r2, r4
 *   @0x22934c bne 0x229320 <vorbis_book_decodevv_add+0x400>
 *   @0x229350 b 0x229190 <vorbis_book_decodevv_add+0x270>
 *   @0x229354 ldr r3, [r11, #0x1c]
 *   @0x229358 ldr r0, [sp, #0x38]
 *   @0x22935c add r3, r3, r7
 *   @0x229360 ldrb r1, [r3, #-0x1]
 *   @0x229364 bl 0x233a7c <oggpack_adv>
 *   @0x229368 subs r7, r7, #1
 *   @0x22936c bhs 0x2292f8 <vorbis_book_decodevv_add+0x3d8>
 *   @0x229370 b 0x229158 <vorbis_book_decodevv_add+0x238>
 *   @0x229374 ldr r8, [r11, #0x8]
 *   @0x229378 mov r7, #0
 *   @0x22937c b 0x2291d4 <vorbis_book_decodevv_add+0x2b4>
 *   @0x229380 ldr r0, [sp, #0x38]
 *   @0x229384 mov r1, #1
 *   @0x229388 bl 0x233a7c <oggpack_adv>
 *   @0x22938c b 0x229158 <vorbis_book_decodevv_add+0x238>
 *
 * ══ §26/29 anon_2de0f4  0x2de0f4  size 876  72 条（0x2de0f4..0x2de460）｜其中 147 条已由别的卡落锚，本节不再重复
 * @func 0x2de0f4 0x2de460  size 876  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2de0f4×6 / anon_2de0f4+0x2e4×2 / anon_2de0f4+0x114 / anon_2de0f4+0x344
 * 字段偏移 top8: 0xc×3 / 0x94×2 / 0x10×1 / 0x48×1
 * VFP 指令 106 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2de0f4 add r12, r0, #84
 *   @0x2de0f8 lsl r2, r2, #3
 *   @0x2de0fc add r12, r12, r2
 *   @0x2de100 vldr s7, [r1, #12]
 *   @0x2de104 vldr s10, [r12, #4]
 *   @0x2de108 vmul.f32 s9, s7, s10
 *   @0x2de10c vldr s15, [r12]
 *   @0x2de110 vldr s5, [r1, #8]
 *   @0x2de114 push {r4, r5, r6, r7}
 *   @0x2de118 add r0, r0, #20
 *   @0x2de11c ldr r7, [sp, #0x10]
 *   @0x2de120 vldr s6, [r7, #8]
 *   @0x2de124 vldr s8, [r7, #12]
 *   @0x2de128 ldr r5, [r3, #0x94]
 *   @0x2de12c add r3, r3, #20
 *   @0x2de130 cmp r5, #0
 *   @0x2de134 vmla.f32 s9, s15, s5
 *   @0x2de138 vmul.f32 s10, s5, s10
 *   @0x2de13c vnmls.f32 s10, s7, s15
 *   @0x2de140 vmul.f32 s12, s9, s6
 *   @0x2de144 vmul.f32 s11, s9, s8
 *   @0x2de148 vmla.f32 s12, s10, s8
 *   @0x2de14c vmls.f32 s11, s6, s10
 *   @0x2de150 ble 0x2de208 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x14c>
 *   @0x2de154 mov r4, #0
 *   @0x2de158 mov r12, r3
 *   @0x2de15c mov r6, r4
 *   @0x2de160 vldr s13, [pc, #168]
 *   @0x2de164 vldr s15, [r12, #4]
 *   @0x2de168 vldr s14, [r12]
 *   @0x2de16c add r12, r12, #8
 *   @0x2de170 vmul.f32 s15, s11, s15
 *   @0x2de174 vmla.f32 s15, s12, s14
 *   @0x2de178 vcmpe.f32 s15, s13
 *   @0x2de17c vmrs APSR_nzcv, fpscr
 *   @0x2de180 movmi r6, r4
 *   @0x2de184 add r4, r4, #1
 *   @0x2de188 vmovmi.f32 s13, s15
 *   @0x2de18c cmp r4, r5
 *   @0x2de190 bne 0x2de164 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0xa8>
 *   @0x2de194 lsl r6, r6, #3
 *   @0x2de198 add r6, r3, r6
 *   @0x2de19c add r2, r0, r2
 *   @0x2de1a0 vldr s14, [r6, #4]
 *   @0x2de1a4 vldr s15, [r2, #4]
 *   @0x2de1a8 vmul.f32 s13, s8, s14
 *   @0x2de1ac vldr s11, [r6]
 *   @0x2de1b0 vldr s4, [r2]
 *   @0x2de1b4 vldr s0, [r7, #4]
 *   @0x2de1b8 vldr s1, [r1, #4]
 *   @0x2de1bc vldr s2, [r7]
 *   @0x2de1c0 vldr s3, [r1]
 *   @0x2de1c4 pop {r4, r5, r6, r7}
 *   @0x2de1c8 vmul.f32 s12, s7, s15
 *   @0x2de1cc vmul.f32 s14, s6, s14
 *   @0x2de1d0 vmul.f32 s15, s5, s15
 *   @0x2de1d4 vmla.f32 s12, s5, s4
 *   @0x2de1d8 vmla.f32 s13, s6, s11
 *   @0x2de1dc vnmls.f32 s15, s7, s4
 *   @0x2de1e0 vnmls.f32 s14, s8, s11
 *   @0x2de1e4 vadd.f32 s12, s12, s1
 *   @0x2de1e8 vadd.f32 s0, s13, s0
 *   @0x2de1ec vsub.f32 s0, s0, s12
 *   @0x2de1f0 vadd.f32 s14, s14, s2
 *   @0x2de1f4 vadd.f32 s15, s15, s3
 *   @0x2de1f8 vmul.f32 s0, s9, s0
 *   @0x2de1fc vsub.f32 s15, s14, s15
 *   @0x2de200 vmla.f32 s0, s10, s15
 *   @0x2de204 bx lr
 *   @0x2de208 mov r6, #0
 *   @0x2de20c b 0x2de198 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0xdc>
 *   @0x2de210 svcvc #0x7fffff
 *
 * ══ §27/29 anonT_2e90fc  0x2e90fc  size 666  26 条（0x2e90fc..0x2e9396）｜其中 141 条已由别的卡落锚，本节不再重复
 * @func 0x2e90fc 0x2e9396  size 666  26 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Stream_ReadULong×3 / FT_Stream_Seek×2 / ft_mem_alloc / ft_mem_free / anonT_2e8c38 / FT_Stream_ReadUShort / FT_Stream_Skip / 0x477208
 * 字段偏移 top8: 0x24×6 / 0x8×5 / 0x18×2 / 0x14×2 / 0x54×1 / 0xc×1 / 0x100×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9114 ldrtmi r0, [r0], -r8, lsl #18
 *   @0x2e912c bmi 0xa27fec <b2_toiTime+0x2ceb48>
 *   @0x2e9160 andls pc, r7, r7, asr #29
 *   @0x2e9180 addsvs r6, r10, r0, lsl #5
 *   @0x2e918c ldrtmi pc, [r0], -r6, lsl #23
 *   @0x2e9194 .word 0x4628f8d0
 *   @0x2e919c svclt #0x8ff0
 *   @0x2e91c0 .word 0x4631fbbf
 *   @0x2e91e8 cmple sp, r0, lsl #30
 *   @0x2e9204 bls 0x477208 <g_RomDisk+0x7f9e8>
 *   @0x2e9220 andls pc, r9, r7, lsl #23
 *   @0x2e922c stmdbls r9, {r0, r1, r3, r6, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2e9270 .word 0xf10b0701
 *   @0x2e9274 .word 0xf1aa0b18
 *   @0x2e9278 pkhbtmi r0, r1, r8, lsl #20
 *   @0x2e92c4 strmi r0, [r10, #0x101]
 *   @0x2e92e0 bls 0x568f70 <g_SWFlineaavertbuff+0x15ea8>
 *   @0x2e92f0 andls pc, r9, lr, asr #22
 *   @0x2e92fc ands pc, r3, r12, lsl r8
 *   @0x2e9324 andls pc, r9, r11, ror #29
 *   @0x2e9344 svclt #0x8ff0
 *   @0x2e9374 strmi pc, [r7], -sp, ror #23
 *   @0x2e937c blmi 0xfea89a28 <b2_toiTime+0xfffffffffe330584>
 *   @0x2e9384 .word 0xf10d0b3c
 *   @0x2e9388 .word 0xf8cd0a40
 *   @0x2e938c strbmi r11, [r0], -r8
 *
 * ══ §28/29 anonT_2fb68c  0x2fb68c  size 518  35 条（0x2fb68c..0x2fb892）｜其中 95 条已由别的卡落锚，本节不再重复
 * @func 0x2fb68c 0x2fb892  size 518  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anonT_2fb68c+0x36 / 0xff3bb778 / 0xff3fbb88 / 0xff3bbb80 / anonT_2fb68c+0x18a / anonT_2f8e0a+0x1aa / anonT_2fb68c+0x5a / 0x3879c0
 * 字段偏移 top8: 0x-4×2 / 0x8×1 / 0x4×1 / 0x-c×1 / 0x-8×1 / 0x18×1 / 0x38×1 / 0x-6×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2fb698 ldrmi r2, [r3], #-364
 *   @0x2fb6d0 .word 0xf8d03274
 *   @0x2fb6d4 movwlo r2, #0x1278
 *   @0x2fb6e8 .word 0x46884ff7
 *   @0x2fb70c addsmi r3, sp, #4
 *   @0x2fb714 vst4.8 {d19, d20, d21, d22}, [pc], r8
 *   @0x2fb718 strhs r3, [r0, -r0, lsl #19]
 *   @0x2fb76c bl 0xff3bb778 <b2_toiTime+0xfffffffffec622d4>
 *   @0x2fb770 bl 0xff3fbb88 <b2_toiTime+0xfffffffffeca26e4>
 *   @0x2fb774 bl 0xff3bbb80 <b2_toiTime+0xfffffffffec626dc>
 *   @0x2fb778 .word 0xf7e90000
 *   @0x2fb77c .word 0x4601fb9c
 *   @0x2fb788 strbmi r3, [r8], -r0, lsl #3
 *   @0x2fb790 .word 0xf10afb3c
 *   @0x2fb794 strmi r0, [r1], r12, lsl #20
 *   @0x2fb7a0 strlo r1, [r1, #-0x15]
 *   @0x2fb7a8 strmi pc, [r6], #-2864
 *   @0x2fb7b0 strne r4, [r0], #-0
 *   @0x2fb7b8 strdeq r8, r9, [r0], -r0
 *   @0x2fb7c4 .word 0xf8d032c0
 *   @0x2fb7c8 ldrbeq r6, [r11, #0x2b8]
 *   @0x2fb7e4 ldrmi r0, [r9, #0x30c]
 *   @0x2fb7ec strtmi r1, [r0], -r12, lsl #24
 *   @0x2fb7f8 .word 0x31042c08
 *   @0x2fb80c ldrmi r3, [r8], #-3076
 *   @0x2fb818 .word 0xf64f2174
 *   @0x2fb81c addsmi r7, r10, #-67108861
 *   @0x2fb824 ldmdblt r3, {r1, r3, r4, r5, r7, r8, r12, sp}
 *   @0x2fb830 rfeia r4!
 *   @0x2fb834 .word 0xf8a411be
 *   @0x2fb838 strmi r3, [r11], #-70
 *   @0x2fb844 and r2, r11, r10, asr #32
 *   @0x2fb870 bl 0x3879c0 <_ZTS13C_UTF16String+0x1ea6c>
 *   @0x2fb874 bl 0xfeb583c4 <b2_toiTime+0xfffffffffe3fef20>
 *   @0x2fb878 stmdbmi r5, {r1, r5, r6, r9}
 *
 * ══ §29/29 SoundHardware::PlayingMP3()  0x221078  size 188  40 条（0x221078..0x221134）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x221078 0x221134  size 188  40 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x221080→0x755361, 0x221098→0x755363, 0x2210ac→0x755362, 0x2210c0→0x755360, 0x2210dc→0x3eb70c
 * 调用序列: 无
 * 字段偏移 top8: 0x44×3 / 0x90×2 / 0x7c×1 / 0x6c×1 / 0x5c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221078 push {r4, lr}
 *   @0x22107c ldr r4, [pc, #0x90]
 *   @0x221080 ldr r3, [pc, #0x90]
 *   @0x221084 add r4, pc, r4
 *   @0x221088 ldr r3, [r4, r3]
 *   @0x22108c ldrb r3, [r3]
 *   @0x2210ac ldr r3, [pc, #0x6c]
 *   @0x2210b0 ldr r3, [r4, r3]
 *   @0x2210b4 ldrb r3, [r3]
 *   @0x2210b8 cmp r3, #0
 *   @0x2210bc bne 0x2210d4 <_ZN13SoundHardware10PlayingMP3Ev+0x5c>
 *   @0x2210c0 ldr r3, [pc, #0x5c]
 *   @0x2210c4 ldr r3, [r4, r3]
 *   @0x2210c8 ldrb r3, [r3]
 *   @0x2210cc cmp r3, #0
 *   @0x2210d0 beq 0x22110c <_ZN13SoundHardware10PlayingMP3Ev+0x94>
 *   @0x2210d4 mov r0, #0
 *   @0x2210d8 pop {r4, pc}
 *   @0x2210dc ldr r3, [pc, #0x44]
 *   @0x2210e0 ldr r2, [pc, #0x44]
 *   @0x2210e4 ldr r1, [pc, #0x44]
 *   @0x2210e8 ldr r3, [r4, r3]
 *   @0x2210ec add r2, pc, r2
 *   @0x2210f0 add r1, pc, r1
 *   @0x2210f4 add r2, r2, #160
 *   @0x2210f8 ldr r0, [r3]
 *   @0x2210fc ldr r3, [r0]
 *   @0x221100 ldr r3, [r3, #0xc]
 *   @0x221104 blx r3
 *   @0x221108 b 0x221098 <_ZN13SoundHardware10PlayingMP3Ev+0x20>
 *   @0x22110c pop {r4, lr}
 *   @0x221110 b 0x2232a0 <_Z17OpenAL_PlayingMP3v>
 *   @0x221114 andseq r0, sp, r12, asr #23
 *   @0x221118 .word 0xfffff7d8
 *   @0x22111c .word 0xffffd3fc
 *   @0x221120 .word 0xfffff7e0
 *   @0x221124 .word 0xfffff7e4
 *   @0x221128 .word 0xffffbac4
 *   @0x22112c ldrsbeq r12, [r3], -r12
 *   @0x221130 andseq r3, r3, r12, asr #14
 */
