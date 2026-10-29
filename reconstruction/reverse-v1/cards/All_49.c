/* cally 逆向卡：All_49 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 102 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/102 spSkeletonBounds_aabbIntersectsSegment  0x28aaf8  size 308  77 条（0x28aaf8..0x28ac2c）
 * @func 0x28aaf8 0x28ac2c  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonBounds_aabbIntersectsSegment+0x2c / spSkeletonBounds_aabbIntersectsSegment+0x48 / spSkeletonBounds_aabbIntersectsSegment+0x64 / spSkeletonBounds_aabbIntersectsSegment+0x74
 * 字段偏移 top8: 无
 * VFP 指令 55 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28aaf8 vmov s15, r1
 *   @0x28aafc vldr s13, [r0, #12]
 *   @0x28ab00 vmov s14, r2
 *   @0x28ab04 vldr s9, [sp]
 *   @0x28ab08 vcmpe.f32 s13, s15
 *   @0x28ab0c vmov s11, r3
 *   @0x28ab10 vmrs APSR_nzcv, fpscr
 *   @0x28ab14 blt 0x28ab24 <spSkeletonBounds_aabbIntersectsSegment+0x2c>
 *   @0x28ab18 vcmpe.f32 s13, s11
 *   @0x28ab1c vmrs APSR_nzcv, fpscr
 *   @0x28ab20 bge 0x28ac1c <spSkeletonBounds_aabbIntersectsSegment+0x124>
 *   @0x28ab24 vldr s12, [r0, #16]
 *   @0x28ab28 vcmpe.f32 s12, s14
 *   @0x28ab2c vmrs APSR_nzcv, fpscr
 *   @0x28ab30 blt 0x28ab40 <spSkeletonBounds_aabbIntersectsSegment+0x48>
 *   @0x28ab34 vcmpe.f32 s12, s9
 *   @0x28ab38 vmrs APSR_nzcv, fpscr
 *   @0x28ab3c bge 0x28ac1c <spSkeletonBounds_aabbIntersectsSegment+0x124>
 *   @0x28ab40 vldr s10, [r0, #20]
 *   @0x28ab44 vcmpe.f32 s15, s10
 *   @0x28ab48 vmrs APSR_nzcv, fpscr
 *   @0x28ab4c blt 0x28ab5c <spSkeletonBounds_aabbIntersectsSegment+0x64>
 *   @0x28ab50 vcmpe.f32 s11, s10
 *   @0x28ab54 vmrs APSR_nzcv, fpscr
 *   @0x28ab58 bge 0x28ac1c <spSkeletonBounds_aabbIntersectsSegment+0x124>
 *   @0x28ab5c vldr s8, [r0, #24]
 *   @0x28ab60 vcmpe.f32 s14, s8
 *   @0x28ab64 vmrs APSR_nzcv, fpscr
 *   @0x28ab68 bge 0x28ac10 <spSkeletonBounds_aabbIntersectsSegment+0x118>
 *   @0x28ab6c vsub.f32 s9, s9, s14
 *   @0x28ab70 vsub.f32 s11, s11, s15
 *   @0x28ab74 vdiv.f32 s11, s9, s11
 *   @0x28ab78 vsub.f32 s9, s13, s15
 *   @0x28ab7c vmov.f32 s7, s14
 *   @0x28ab80 vmla.f32 s7, s9, s11
 *   @0x28ab84 vcmpe.f32 s12, s7
 *   @0x28ab88 vmrs APSR_nzcv, fpscr
 *   @0x28ab8c bpl 0x28ab9c <spSkeletonBounds_aabbIntersectsSegment+0xa4>
 *   @0x28ab90 vcmpe.f32 s8, s7
 *   @0x28ab94 vmrs APSR_nzcv, fpscr
 *   @0x28ab98 bgt 0x28ac24 <spSkeletonBounds_aabbIntersectsSegment+0x12c>
 *   @0x28ab9c vsub.f32 s9, s10, s15
 *   @0x28aba0 vmov.f32 s7, s14
 *   @0x28aba4 vmla.f32 s7, s9, s11
 *   @0x28aba8 vcmpe.f32 s12, s7
 *   @0x28abac vmrs APSR_nzcv, fpscr
 *   @0x28abb0 bpl 0x28abc0 <spSkeletonBounds_aabbIntersectsSegment+0xc8>
 *   @0x28abb4 vcmpe.f32 s8, s7
 *   @0x28abb8 vmrs APSR_nzcv, fpscr
 *   @0x28abbc bgt 0x28ac24 <spSkeletonBounds_aabbIntersectsSegment+0x12c>
 *   @0x28abc0 vsub.f32 s12, s12, s14
 *   @0x28abc4 vdiv.f32 s12, s12, s11
 *   @0x28abc8 vadd.f32 s12, s12, s15
 *   @0x28abcc vcmpe.f32 s13, s12
 *   @0x28abd0 vmrs APSR_nzcv, fpscr
 *   @0x28abd4 bpl 0x28abe4 <spSkeletonBounds_aabbIntersectsSegment+0xec>
 *   @0x28abd8 vcmpe.f32 s10, s12
 *   @0x28abdc vmrs APSR_nzcv, fpscr
 *   @0x28abe0 bgt 0x28ac24 <spSkeletonBounds_aabbIntersectsSegment+0x12c>
 *   @0x28abe4 vsub.f32 s14, s8, s14
 *   @0x28abe8 vdiv.f32 s11, s14, s11
 *   @0x28abec vadd.f32 s15, s11, s15
 *   @0x28abf0 vcmpe.f32 s13, s15
 *   @0x28abf4 vmrs APSR_nzcv, fpscr
 *   @0x28abf8 bpl 0x28ac1c <spSkeletonBounds_aabbIntersectsSegment+0x124>
 *   @0x28abfc vcmpe.f32 s10, s15
 *   @0x28ac00 vmrs APSR_nzcv, fpscr
 *   @0x28ac04 movle r0, #0
 *   @0x28ac08 movgt r0, #1
 *   @0x28ac0c bx lr
 *   @0x28ac10 vcmpe.f32 s9, s8
 *   @0x28ac14 vmrs APSR_nzcv, fpscr
 *   @0x28ac18 blt 0x28ab6c <spSkeletonBounds_aabbIntersectsSegment+0x74>
 *   @0x28ac1c mov r0, #0
 *   @0x28ac20 bx lr
 *   @0x28ac24 mov r0, #1
 *   @0x28ac28 bx lr
 *
 * ══ §2/102 png_set_sPLT  0x2af20c  size 308  77 条（0x2af20c..0x2af340）
 * @func 0x2af20c 0x2af340  size 308  77 条
 * 部分覆盖: 本节 77/133 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc×2 / 0x102e79c / 0x46f284 / 0x4352b0 / anon_2e9c78+0x564c / png_warning / 0x32e720
 * 字段偏移 top8: 0xc×2 / 0xcc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af20c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2af210 mov r4, r1
 *   @0x2af214 mov r8, r2
 *   @0x2af218 mov r5, r0
 *   @0x2af21c beq.w 0x2af32c <png_set_sPLT+0x120>
 *   @0x2af220 cmp r1, #0x0
 *   @0x2af224 .word 0xf8d18083
 *   @0x2af228 ldrmi r1, [r9], #-216
 *   @0x2af22c lsls r1, r1, #0x4
 *   @0x2af230 .word 0x4606fd72
 *   @0x2af234 cbnz r0, 0x2af246 <png_set_sPLT+0x3a>
 *   @0x2af238 mov r0, r5
 *   @0x2af23c add sp, #0x14
 *   @0x2af240 .word 0xf7f74ff0
 *   @0x2af244 .word 0xf8d4b917
 *   @0x2af248 .word 0x46c320d8
 *   @0x2af24c ldr.w r1, [r4, #0xd4]
 *   @0x2af250 movs r7, #0x0
 *   @0x2af254 blx 0xb65bc <memcpy@plt>
 *   @0x2af258 mov r0, r5
 *   @0x2af25c .word 0xf7f710d4
 *   @0x2af260 blmi 0x102e79c <b2_toiTime+0x8d52f8>
 *   @0x2af264 str.w r7, [r4, #0xd4]
 *   @0x2af268 add r3, pc
 *   @0x2af26c ldr r3, [pc, #0xcc]
 *   @0x2af270 str r3, [sp, #0xc]
 *   @0x2af274 ldr.w r2, [r4, #0xd8]
 *   @0x2af278 bge 0x2af30e <png_set_sPLT+0x102>
 *   @0x2af27c bl 0x46f284 <g_RomDisk+0x77a64>
 *   @0x2af280 .word 0xf6070802
 *   @0x2af284 b 0x16a97f4 <b2_toiTime+0xf50350>
 *   @0x2af288 bl 0x4352b0 <g_RomDisk+0x3da90>
 *   @0x2af28c .word 0x1c420a08
 *   @0x2af290 mov r0, r5
 *   @0x2af294 mov r1, r2
 *   @0x2af298 .word 0xf846fd3e
 *   @0x2af29c bls 0x2ef2c4 <FT_Done_Memory+0x5650>
 *   @0x2af2a0 cbnz r0, 0x2af2ac <png_set_sPLT+0xa0>
 *   @0x2af2a4 ldr r1, [sp, #0xc]
 *   @0x2af2a8 eor pc, r12, r5, ror #17
 *   @0x2af2ac ldr.w r1, [r11]
 *   @0x2af2b0 blx 0xb65bc <memcpy@plt>
 *   @0x2af2b4 ldr.w r1, [r11, #0xc]
 *   @0x2af2b8 movs r3, #0xa
 *   @0x2af2bc muls r1, r3, r1
 *   @0x2af2c0 strmi pc, [r2], -r10, lsr #26
 *   @0x2af2c4 str.w r0, [r10, #0x8]
 *   @0x2af2c8 cbnz r0, 0x2af2e6 <png_set_sPLT+0xda>
 *   @0x2af2cc ldr r1, [sp, #0x8]
 *   @0x2af2d0 bl 0x2a6474 <png_warning>
 *   @0x2af2d4 mov r0, r5
 *   @0x2af2d8 .word 0xf7f71008
 *   @0x2af2dc bls 0x32e720
 *   @0x2af2e0 str.w r2, [r6, r8]
 *   @0x2af2e4 b 0x2af306 <png_set_sPLT+0xfa>
 *   @0x2af2e8 movwhs r2, #0xa00c
 *   @0x2af2ec ldr.w r1, [r11, #0x8]
 *   @0x2af2f0 muls r2, r3, r2
 *   @0x2af2f4 .word 0xf8dbe964
 *   @0x2af2f8 .word 0xf8ca200c
 *   @0x2af2fc .word 0xf89b200c
 *   @0x2af300 .word 0xf88a2004
 *   @0x2af304 strlo r2, [r1, -r4]
 *   @0x2af308 add.w r11, r11, #0x10
 *   @0x2af30c b 0x2af272 <png_set_sPLT+0x66>
 *   @0x2af310 add r2, r9
 *   @0x2af314 .word 0xf44360d4
 *   @0x2af318 adcvs r5, r3, r0, lsl #6
 *   @0x2af31c ldr.w r3, [r4, #0xb8]
 *   @0x2af320 str.w r2, [r4, #0xd8]
 *   @0x2af324 orr r3, r3, #0x20
 *   @0x2af328 str.w r3, [r4, #0xb8]
 *   @0x2af32c add sp, #0x14
 *   @0x2af330 svclt #0x8ff0
 *   @0x2af334 eors.w r0, r3, sp
 *   @0x2af338 eor.w r0, r1, sp
 *   @0x2af33c orns r0, r11, sp
 *
 * ══ §3/102 png_write_pCAL  0x2b2250  size 308  77 条（0x2b2250..0x2b2384）
 * @func 0x2b2250 0x2b2384  size 308  77 条
 * 部分覆盖: 本节 77/135 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_chunk_data×2 / png_check_keyword / png_malloc / 0x36c7a4 / png_write_chunk_start / png_save_int_32 / png_free / 0xb65d4
 * 字段偏移 top8: 0x60×2 / 0x1c×2 / 0x118×1 / 0x6c×1 / 0x104×1 / 0x20×1 / 0xf4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b2250 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b2254 sub sp, #0x3c
 *   @0x2b2258 mov r6, r1
 *   @0x2b225c ldr r3, [pc, #0x118]
 *   @0x2b2260 add r3, pc
 *   @0x2b2264 ldr r1, [sp, #0x60]
 *   @0x2b2268 ldr r2, [r3]
 *   @0x2b226c ldr.w r9, [sp, #0x68]
 *   @0x2b2270 ldr r7, [sp, #0x6c]
 *   @0x2b2274 ldr r2, [pc, #0x104]
 *   @0x2b2278 add r2, pc
 *   @0x2b227c ldmdbvc r2, {r0, r2, r3, r4, r6, r8, r9, r10, r11}
 *   @0x2b2280 str r0, [sp, #0x20]
 *   @0x2b2284 stcle p0, c2, [r4, #-144]
 *   @0x2b2288 ldr r1, [pc, #0xf4]
 *   @0x2b228c add r1, pc
 *   @0x2b2290 shsub8mi pc, r1, r1
 *   @0x2b2294 add r2, sp, #0x1c
 *   @0x2b2298 bl 0x2af5b0 <png_check_keyword>
 *   @0x2b229c add.w r10, r0, #0x1
 *   @0x2b22a0 mov r0, r9
 *   @0x2b22a4 adceq lr, r9, r10, asr #18
 *   @0x2b22a8 cmp r5, #0x0
 *   @0x2b22ac moveq r8, r0
 *   @0x2b22b0 strtmi r0, [r0], -r1, lsl #16
 *   @0x2b22b4 add.w r2, r10, r8
 *   @0x2b22b8 add.w r11, r2, #0xa
 *   @0x2b22bc bl 0x2a6ca0 <png_malloc>
 *   @0x2b22c0 subs r1, r5, #0x1
 *   @0x2b22c4 mov r6, r0
 *   @0x2b22c8 bge 0x2b22ea <png_write_pCAL+0x9a>
 *   @0x2b22cc .word 0x91010023
 *   @0x2b22d0 str r3, [sp, #0x8]
 *   @0x2b22d4 blls 0x36c7a4 <_ZTS13C_UTF16String+0x3850>
 *   @0x2b22d8 ldr r1, [sp, #0x4]
 *   @0x2b22dc it ne
 *   @0x2b22e0 str.w r0, [r6, r3, lsl #2]
 *   @0x2b22e4 add r11, r0
 *   @0x2b22e8 b 0x2b22c6 <png_write_pCAL+0x76>
 *   @0x2b22ec add r1, sp, #0x20
 *   @0x2b22f0 bl 0x2b11a0 <png_write_chunk_start>
 *   @0x2b22f4 mov r2, r10
 *   @0x2b22f8 strtmi r0, [r0], -r8, lsr #20
 *   @0x2b22fc ldr r1, [sp, #0x1c]
 *   @0x2b2300 ldrbmi pc, [r0], -r1, lsl #31
 *   @0x2b2304 ldr r1, [sp, #0xc]
 *   @0x2b2308 .word 0xf10aff15
 *   @0x2b230c stmdbls r4, {r2}
 *   @0x2b2310 bl 0x2b1134 <png_save_int_32>
 *   @0x2b2314 ldr r3, [sp, #0x60]
 *   @0x2b2318 mov r1, r10
 *   @0x2b231c strb.w r5, [sp, #0x31]
 *   @0x2b2320 strb.w r3, [sp, #0x30]
 *   @0x2b2324 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b2328 mov r2, r8
 *   @0x2b232c mov r1, r9
 *   @0x2b2330 .word 0xf7fe0800
 *   @0x2b2334 strtmi pc, [r0], -r7, ror #30
 *   @0x2b2338 ldr r1, [sp, #0x1c]
 *   @0x2b233c strmi pc, [r8, #0xcdf]!
 *   @0x2b2340 mov r0, r4
 *   @0x2b2344 ldr.w r1, [r7, r8, lsl #2]
 *   @0x2b2348 ldr.w r2, [r6, r8, lsl #2]
 *   @0x2b234c add.w r8, r8, #0x1
 *   @0x2b2350 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b2354 b 0x2b233e <png_write_pCAL+0xee>
 *   @0x2b2358 bl 0x2a6cfc <png_free>
 *   @0x2b235c mov r0, r4
 *   @0x2b2360 stmdbls r5, {r1, r3, r4, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2b2364 ldr r2, [sp, #0x34]
 *   @0x2b2368 cmp r2, r3
 *   @0x2b236c blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b2370 add sp, #0x3c
 *   @0x2b2374 svclt #0x8ff0
 *   @0x2b2378 .word 0xb6f4
 *   @0x2b237c bge 0x2b2350 <png_write_pCAL+0x100>
 *   @0x2b2380 cbz r2, 0x2b23ca <png_write_sCAL+0x46>
 *
 * ══ §4/102 b2EdgeShape::ComputeDistance(b2Transform const&, b2Vec2 const&, float*, b2Vec2*, int) const  0x2c54fc  size 308  77 条（0x2c54fc..0x2c5630）
 * @func 0x2c54fc 0x2c5630  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2EdgeShape::ComputeDistance(b2Transform const&, b2Vec2 const&, float*, b2Vec2*, int) const+0xb0 / b2EdgeShape::ComputeDistance(b2Transform const&, b2Vec2 const&, float*, b2Vec2*, int) const+0xfc / 0xb6700
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0x2c×1
 * VFP 指令 58 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c54fc vldr s15, [r1, #12]
 *   @0x2c5500 vldr s12, [r0, #16]
 *   @0x2c5504 vldr s13, [r0, #24]
 *   @0x2c5508 vmul.f32 s10, s15, s12
 *   @0x2c550c vldr s14, [r1, #8]
 *   @0x2c5510 vldr s6, [r0, #12]
 *   @0x2c5514 vldr s7, [r0, #20]
 *   @0x2c5518 vldr s8, [r1, #4]
 *   @0x2c551c push {r4, lr}
 *   @0x2c5520 vldr s5, [r2, #4]
 *   @0x2c5524 vpush {d8}
 *   @0x2c5528 vldr s9, [r1]
 *   @0x2c552c vldr s4, [r2]
 *   @0x2c5530 sub sp, sp, #8
 *   @0x2c5534 ldr r4, [sp, #0x18]
 *   @0x2c5538 vmul.f32 s11, s15, s13
 *   @0x2c553c vmla.f32 s10, s6, s14
 *   @0x2c5540 vmul.f32 s12, s14, s12
 *   @0x2c5544 vmul.f32 s13, s14, s13
 *   @0x2c5548 vmla.f32 s11, s14, s7
 *   @0x2c554c vnmls.f32 s12, s15, s6
 *   @0x2c5550 vnmls.f32 s13, s15, s7
 *   @0x2c5554 vadd.f32 s10, s10, s8
 *   @0x2c5558 vadd.f32 s11, s8, s11
 *   @0x2c555c vsub.f32 s16, s5, s10
 *   @0x2c5560 vsub.f32 s10, s11, s10
 *   @0x2c5564 vadd.f32 s12, s12, s9
 *   @0x2c5568 vadd.f32 s13, s9, s13
 *   @0x2c556c vmul.f32 s15, s16, s10
 *   @0x2c5570 vsub.f32 s17, s4, s12
 *   @0x2c5574 vsub.f32 s12, s13, s12
 *   @0x2c5578 vmla.f32 s15, s17, s12
 *   @0x2c557c vcmpe.f32 s15, #0
 *   @0x2c5580 vmrs APSR_nzcv, fpscr
 *   @0x2c5584 ble 0x2c55ac <_ZNK11b2EdgeShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0xb0>
 *   @0x2c5588 vmul.f32 s14, s10, s10
 *   @0x2c558c vmla.f32 s14, s12, s12
 *   @0x2c5590 vcmpe.f32 s15, s14
 *   @0x2c5594 vmrs APSR_nzcv, fpscr
 *   @0x2c5598 vdivle.f32 s15, s15, s14
 *   @0x2c559c vmlsle.f32 s17, s15, s12
 *   @0x2c55a0 vmlsle.f32 s16, s15, s10
 *   @0x2c55a4 vsubgt.f32 s17, s4, s13
 *   @0x2c55a8 vsubgt.f32 s16, s5, s11
 *   @0x2c55ac vmul.f32 s14, s16, s16
 *   @0x2c55b0 vmla.f32 s14, s17, s17
 *   @0x2c55b4 vsqrt.f32 s15, s14
 *   @0x2c55b8 vcmp.f32 s15, s15
 *   @0x2c55bc vmrs APSR_nzcv, fpscr
 *   @0x2c55c0 bne 0x2c5614 <_ZNK11b2EdgeShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x118>
 *   @0x2c55c4 vcmpe.f32 s15, #0
 *   @0x2c55c8 vstr s15, [r3]
 *   @0x2c55cc vmrs APSR_nzcv, fpscr
 *   @0x2c55d0 ble 0x2c55f8 <_ZNK11b2EdgeShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0xfc>
 *   @0x2c55d4 vmov.f32 s14, #1.000000e+00
 *   @0x2c55d8 vdiv.f32 s15, s14, s15
 *   @0x2c55dc vmul.f32 s17, s15, s17
 *   @0x2c55e0 vmul.f32 s15, s15, s16
 *   @0x2c55e4 vstr s17, [r4]
 *   @0x2c55e8 vstr s15, [r4, #4]
 *   @0x2c55ec add sp, sp, #8
 *   @0x2c55f0 vpop {d8}
 *   @0x2c55f4 pop {r4, pc}
 *   @0x2c55f8 ldr r3, [pc, #0x2c]
 *   @0x2c55fc ldr r3, [pc, r3]
 *   @0x2c5600 ldm r3, {r0, r1}
 *   @0x2c5604 stm r4, {r0, r1}
 *   @0x2c5608 add sp, sp, #8
 *   @0x2c560c vpop {d8}
 *   @0x2c5610 pop {r4, pc}
 *   @0x2c5614 vmov r0, s14
 *   @0x2c5618 str r3, [sp, #0x4]
 *   @0x2c561c bl 0xb6700 <sqrtf@plt>
 *   @0x2c5620 ldr r3, [sp, #0x4]
 *   @0x2c5624 vmov s15, r0
 *   @0x2c5628 b 0x2c55c4 <_ZNK11b2EdgeShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0xc8>
 *   @0x2c562c ldrsbeq r11, [r2], -r12
 *
 * ══ §5/102 b2Body::SetType(b2BodyType)  0x2c7378  size 308  77 条（0x2c7378..0x2c74ac）
 * @func 0x2c7378 0x2c74ac  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Body::ResetMassData() / b2ContactManager::Destroy(b2Contact*) / b2Body::SetType(b2BodyType)+0xf0 / b2BroadPhase::TouchProxy(int) / b2Body::SynchronizeFixtures()
 * 字段偏移 top8: 0x68×3 / 0x4×3 / 0x80×2 / 0x18×2 / 0x5c×1 / 0x60×1 / 0x64×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7378 ldr r2, [r0, #0x68]
 *   @0x2c737c movw r3, #0x91d4
 *   @0x2c7380 movt r3, #0x1
 *   @0x2c7384 push {r4, r5, r6, r7, r8, lr}
 *   @0x2c7388 mov r5, r0
 *   @0x2c738c ldr r3, [r2, r3]
 *   @0x2c7390 tst r3, #2
 *   @0x2c7394 popne {r4, r5, r6, r7, r8, pc}
 *   @0x2c7398 ldr r3, [r0]
 *   @0x2c739c cmp r3, r1
 *   @0x2c73a0 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x2c73a4 str r1, [r0]
 *   @0x2c73a8 bl 0x2c6c00 <_ZN6b2Body13ResetMassDataEv>
 *   @0x2c73ac ldr r3, [r5]
 *   @0x2c73b0 cmp r3, #0
 *   @0x2c73b4 beq 0x2c7478 <_ZN6b2Body7SetTypeE10b2BodyType+0x100>
 *   @0x2c73b8 ldrh r3, [r5, #4]
 *   @0x2c73bc tst r3, #2
 *   @0x2c73c0 orreq r3, r3, #2
 *   @0x2c73c4 strheq r3, [r5, #4]
 *   @0x2c73c8 ldr r3, [r5, #0x80]
 *   @0x2c73cc moveq r2, #0
 *   @0x2c73d0 streq r2, [r5, #0xa0]
 *   @0x2c73d4 mov r2, #0
 *   @0x2c73d8 cmp r3, #0
 *   @0x2c73dc str r2, [r5, #0x5c]
 *   @0x2c73e0 str r2, [r5, #0x60]
 *   @0x2c73e4 str r2, [r5, #0x64]
 *   @0x2c73e8 beq 0x2c7410 <_ZN6b2Body7SetTypeE10b2BodyType+0x98>
 *   @0x2c73ec ldr r0, [r5, #0x68]
 *   @0x2c73f0 ldr r4, [r3, #0xc]
 *   @0x2c73f4 add r0, r0, #102400
 *   @0x2c73f8 ldr r1, [r3, #0x4]
 *   @0x2c73fc add r0, r0, #472
 *   @0x2c7400 bl 0x2c7894 <_ZN16b2ContactManager7DestroyEP9b2Contact>
 *   @0x2c7404 cmp r4, #0
 *   @0x2c7408 mov r3, r4
 *   @0x2c740c bne 0x2c73ec <_ZN6b2Body7SetTypeE10b2BodyType+0x74>
 *   @0x2c7410 ldr r6, [r5, #0x74]
 *   @0x2c7414 mov r3, #0
 *   @0x2c7418 ldr r8, [r5, #0x68]
 *   @0x2c741c cmp r6, r3
 *   @0x2c7420 str r3, [r5, #0x80]
 *   @0x2c7424 add r8, r8, #102400
 *   @0x2c7428 add r8, r8, #472
 *   @0x2c742c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x2c7430 ldr r7, [r6, #0x1c]
 *   @0x2c7434 cmp r7, #0
 *   @0x2c7438 movgt r4, #0
 *   @0x2c743c movgt r5, r4
 *   @0x2c7440 ble 0x2c7468 <_ZN6b2Body7SetTypeE10b2BodyType+0xf0>
 *   @0x2c7444 ldr r3, [r6, #0x18]
 *   @0x2c7448 add r5, r5, #1
 *   @0x2c744c mov r0, r8
 *   @0x2c7450 add r3, r3, r4
 *   @0x2c7454 add r4, r4, #28
 *   @0x2c7458 ldr r1, [r3, #0x18]
 *   @0x2c745c bl 0x2dc8e0 <_ZN12b2BroadPhase10TouchProxyEi>
 *   @0x2c7460 cmp r5, r7
 *   @0x2c7464 bne 0x2c7444 <_ZN6b2Body7SetTypeE10b2BodyType+0xcc>
 *   @0x2c7468 ldr r6, [r6, #0x4]
 *   @0x2c746c cmp r6, #0
 *   @0x2c7470 bne 0x2c7430 <_ZN6b2Body7SetTypeE10b2BodyType+0xb8>
 *   @0x2c7474 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2c7478 add r2, r5, #60
 *   @0x2c747c mov r3, #0
 *   @0x2c7480 str r3, [r5, #0x50]
 *   @0x2c7484 str r3, [r5, #0x54]
 *   @0x2c7488 ldm r2, {r0, r1}
 *   @0x2c748c add r2, r5, #52
 *   @0x2c7490 str r3, [r5, #0x58]
 *   @0x2c7494 ldr r3, [r5, #0x48]
 *   @0x2c7498 str r3, [r5, #0x44]
 *   @0x2c749c stm r2, {r0, r1}
 *   @0x2c74a0 mov r0, r5
 *   @0x2c74a4 bl 0x2c72cc <_ZN6b2Body19SynchronizeFixturesEv>
 *   @0x2c74a8 b 0x2c73b8 <_ZN6b2Body7SetTypeE10b2BodyType+0x40>
 *
 * ══ §6/102 _spAtlasPage_createTexture  0xbd6e4  size 304  76 条（0xbd6e4..0xbd814）
 * @func 0xbd6e4 0xbd814  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ReadPNGFile(void*, int, int*, int*, bool)×2 / GR_Texture_Create_And_Fill(int, int, unsigned char*, unsigned int)×2 / FreePNGFile()×2 / LoadSave::SaveFileExists(char const*) / LoadSave::ReadSaveFile(char const*, int*) / MemoryManager::Free(void const*) / LoadSave::BundleFileExists(char const*) / LoadSave::ReadBundleFile(char const*, int*)
 * 字段偏移 top8: 0xc×3 / 0x10×2 / 0x14×2 / 0x20×2 / 0x24×2 / 0x1c×2 / 0x11c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbd6e4 push {r4, r5, r6, lr}
 *   @0xbd6e8 mov r5, r0
 *   @0xbd6ec ldr r4, [pc, #0x11c]
 *   @0xbd6f0 sub sp, sp, #24
 *   @0xbd6f4 mov r6, r1
 *   @0xbd6f8 add r4, pc, r4
 *   @0xbd6fc ldr r3, [r4]
 *   @0xbd700 cmp r3, #0
 *   @0xbd704 beq 0xbd764 <_spAtlasPage_createTexture+0x80>
 *   @0xbd708 ldr r1, [r4, #0x4]
 *   @0xbd70c mov r0, r3
 *   @0xbd710 add r2, sp, #16
 *   @0xbd714 mov r3, #0
 *   @0xbd718 str r3, [sp]
 *   @0xbd71c add r3, sp, #20
 *   @0xbd720 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b>
 *   @0xbd724 subs r2, r0, #0
 *   @0xbd728 beq 0xbd75c <_spAtlasPage_createTexture+0x78>
 *   @0xbd72c ldr r3, [sp, #0x10]
 *   @0xbd730 ldr r1, [sp, #0x14]
 *   @0xbd734 ldr lr, [r4, #0x8]
 *   @0xbd738 mov r0, r3
 *   @0xbd73c ldr r12, [r4, #0xc]
 *   @0xbd740 mul r3, r1, r3
 *   @0xbd744 str lr, [r5, #0x20]
 *   @0xbd748 str r12, [r5, #0x24]
 *   @0xbd74c lsl r3, r3, #2
 *   @0xbd750 bl 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj>
 *   @0xbd754 str r0, [r5, #0x1c]
 *   @0xbd758 bl 0x18a518 <_Z11FreePNGFilev>
 *   @0xbd75c add sp, sp, #24
 *   @0xbd760 pop {r4, r5, r6, pc}
 *   @0xbd764 mov r0, r1
 *   @0xbd768 str r3, [sp, #0xc]
 *   @0xbd76c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xbd770 cmp r0, #0
 *   @0xbd774 mov r0, r6
 *   @0xbd778 beq 0xbd7ec <_spAtlasPage_createTexture+0x108>
 *   @0xbd77c add r1, sp, #12
 *   @0xbd780 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0xbd784 mov r4, r0
 *   @0xbd788 cmp r4, #0
 *   @0xbd78c beq 0xbd7dc <_spAtlasPage_createTexture+0xf8>
 *   @0xbd790 mov r3, #0
 *   @0xbd794 add r2, sp, #16
 *   @0xbd798 str r3, [sp]
 *   @0xbd79c mov r0, r4
 *   @0xbd7a0 ldr r1, [sp, #0xc]
 *   @0xbd7a4 add r3, sp, #20
 *   @0xbd7a8 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b>
 *   @0xbd7ac subs r2, r0, #0
 *   @0xbd7b0 beq 0xbd7dc <_spAtlasPage_createTexture+0xf8>
 *   @0xbd7b4 ldr r3, [sp, #0x10]
 *   @0xbd7b8 ldr r1, [sp, #0x14]
 *   @0xbd7bc str r3, [r5, #0x20]
 *   @0xbd7c0 mov r0, r3
 *   @0xbd7c4 mul r3, r1, r3
 *   @0xbd7c8 str r1, [r5, #0x24]
 *   @0xbd7cc lsl r3, r3, #2
 *   @0xbd7d0 bl 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj>
 *   @0xbd7d4 str r0, [r5, #0x1c]
 *   @0xbd7d8 bl 0x18a518 <_Z11FreePNGFilev>
 *   @0xbd7dc mov r0, r4
 *   @0xbd7e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xbd7e4 add sp, sp, #24
 *   @0xbd7e8 pop {r4, r5, r6, pc}
 *   @0xbd7ec bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0xbd7f0 cmp r0, #0
 *   @0xbd7f4 moveq r4, r0
 *   @0xbd7f8 beq 0xbd7dc <_spAtlasPage_createTexture+0xf8>
 *   @0xbd7fc mov r0, r6
 *   @0xbd800 add r1, sp, #12
 *   @0xbd804 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0xbd808 mov r4, r0
 *   @0xbd80c b 0xbd788 <_spAtlasPage_createTexture+0xa4>
 *   @0xbd810 mlaseq r11, r8, r5, r12
 *
 * ══ §7/102 F_DrawShapeString(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c17c  size 304  76 条（0x11c17c..0x11c2ac）
 * @func 0x11c17c 0x11c2ac  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / YYGetInt32(RValue const*, int)×4 / Sprite_Exists(int) / Error_Show_Action(char const*, bool) / Sprite_Data(int) / YYGetString(RValue const*, int) / CSprite::DrawShapeString(int, char const*, float, float, float, float, float, unsigned int, unsigned int, float)
 * 字段偏移 top8: 0x24×2 / 0x28×2 / 0x2c×2 / 0x58×1 / 0xfc×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c17c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11c180 sub sp, sp, #52
 *   @0x11c184 mov r1, #0
 *   @0x11c188 ldr r4, [sp, #0x58]
 *   @0x11c18c mov r0, r4
 *   @0x11c190 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c194 mov r5, r0
 *   @0x11c198 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x11c19c subs r1, r0, #0
 *   @0x11c1a0 bne 0x11c1b0 <_Z17F_DrawShapeStringR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x11c1a4 ldr r0, [pc, #0xfc]
 *   @0x11c1a8 add r0, pc, r0
 *   @0x11c1ac bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11c1b0 mov r0, r5
 *   @0x11c1b4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11c1b8 mov r1, #1
 *   @0x11c1bc mov r5, r0
 *   @0x11c1c0 mov r0, r4
 *   @0x11c1c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c1c8 mov r1, #2
 *   @0x11c1cc mov r8, r0
 *   @0x11c1d0 mov r0, r4
 *   @0x11c1d4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11c1d8 mov r1, #3
 *   @0x11c1dc mov r7, r0
 *   @0x11c1e0 mov r0, r4
 *   @0x11c1e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c1e8 mov r1, #4
 *   @0x11c1ec mov r6, r0
 *   @0x11c1f0 mov r0, r4
 *   @0x11c1f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c1f8 mov r1, #5
 *   @0x11c1fc mov r12, r0
 *   @0x11c200 mov r0, r4
 *   @0x11c204 str r12, [sp, #0x24]
 *   @0x11c208 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c20c mov r1, #6
 *   @0x11c210 mov r2, r0
 *   @0x11c214 mov r0, r4
 *   @0x11c218 str r2, [sp, #0x28]
 *   @0x11c21c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c220 mov r1, #7
 *   @0x11c224 mov r3, r0
 *   @0x11c228 mov r0, r4
 *   @0x11c22c str r3, [sp, #0x2c]
 *   @0x11c230 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c234 mov r1, #8
 *   @0x11c238 mov r11, r0
 *   @0x11c23c mov r0, r4
 *   @0x11c240 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c244 mov r1, #9
 *   @0x11c248 mov r10, r0
 *   @0x11c24c mov r0, r4
 *   @0x11c250 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c254 mov r1, #10
 *   @0x11c258 mov r9, r0
 *   @0x11c25c mov r0, r4
 *   @0x11c260 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11c264 ldr r2, [sp, #0x28]
 *   @0x11c268 ldr r3, [sp, #0x2c]
 *   @0x11c26c mov r1, r8
 *   @0x11c270 ldr r12, [sp, #0x24]
 *   @0x11c274 str r2, [sp, #0x4]
 *   @0x11c278 mov r2, r7
 *   @0x11c27c str r3, [sp, #0x8]
 *   @0x11c280 mov r3, r6
 *   @0x11c284 str r12, [sp]
 *   @0x11c288 str r11, [sp, #0xc]
 *   @0x11c28c str r10, [sp, #0x10]
 *   @0x11c290 str r9, [sp, #0x14]
 *   @0x11c294 str r0, [sp, #0x18]
 *   @0x11c298 mov r0, r5
 *   @0x11c29c bl 0x1ee768 <_ZN7CSprite15DrawShapeStringEiPKcfffffjjf>
 *   @0x11c2a0 add sp, sp, #52
 *   @0x11c2a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11c2a8 eoreq sp, r1, r12, lsl #28
 *
 * ══ §8/102 F_SkeletonCreateAttachment(RValue&, CInstance*, CInstance*, int, RValue*)  0x11cecc  size 304  76 条（0x11cecc..0x11cffc）
 * @func 0x11cecc 0x11cffc  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetInt32(RValue const*, int)×2 / CInstance::SkeletonAnimation() / Sprite_Exists(int) / F_SkeletonCreateAttachment(RValue&, CInstance*, CInstance*, int, RValue*)+0x128 / YYGetString(RValue const*, int) / Sprite_Data(int) / CSkeletonInstance::CreateAttachment(char const*, CSprite*, int, float, float, float, float, float)
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x1c×2 / 0x20×2 / 0x24×2 / 0x50×1 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11cecc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11ced0 mov r4, r0
 *   @0x11ced4 sub sp, sp, #44
 *   @0x11ced8 mov r6, #0
 *   @0x11cedc mov r3, #0
 *   @0x11cee0 mov r0, r1
 *   @0x11cee4 movt r3, #0xbff0
 *   @0x11cee8 str r6, [r4, #0xc]
 *   @0x11ceec str r3, [r4, #0x4]
 *   @0x11cef0 str r6, [r4]
 *   @0x11cef4 ldr r5, [sp, #0x50]
 *   @0x11cef8 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x11cefc subs r9, r0, #0
 *   @0x11cf00 beq 0x11cff4 <_Z26F_SkeletonCreateAttachmentR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x11cf04 mov r1, #1
 *   @0x11cf08 mov r0, r5
 *   @0x11cf0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11cf10 mov r1, #2
 *   @0x11cf14 mov r7, r0
 *   @0x11cf18 mov r0, r5
 *   @0x11cf1c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11cf20 mov r8, r0
 *   @0x11cf24 mov r0, r7
 *   @0x11cf28 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x11cf2c cmp r0, r6
 *   @0x11cf30 beq 0x11cff4 <_Z26F_SkeletonCreateAttachmentR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x11cf34 cmp r8, r6
 *   @0x11cf38 blt 0x11cff4 <_Z26F_SkeletonCreateAttachmentR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x11cf3c mov r1, r6
 *   @0x11cf40 mov r0, r5
 *   @0x11cf44 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11cf48 mov r10, r0
 *   @0x11cf4c mov r0, r7
 *   @0x11cf50 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11cf54 mov r1, #3
 *   @0x11cf58 mov r7, r0
 *   @0x11cf5c mov r0, r5
 *   @0x11cf60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11cf64 mov r1, #4
 *   @0x11cf68 mov r12, r0
 *   @0x11cf6c mov r0, r5
 *   @0x11cf70 str r12, [sp, #0x1c]
 *   @0x11cf74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11cf78 mov r1, #5
 *   @0x11cf7c mov r2, r0
 *   @0x11cf80 mov r0, r5
 *   @0x11cf84 str r2, [sp, #0x20]
 *   @0x11cf88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11cf8c mov r1, #6
 *   @0x11cf90 mov r3, r0
 *   @0x11cf94 mov r0, r5
 *   @0x11cf98 str r3, [sp, #0x24]
 *   @0x11cf9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11cfa0 mov r1, #7
 *   @0x11cfa4 mov r11, r0
 *   @0x11cfa8 mov r0, r5
 *   @0x11cfac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11cfb0 ldr r2, [sp, #0x20]
 *   @0x11cfb4 ldr r3, [sp, #0x24]
 *   @0x11cfb8 mov r1, r10
 *   @0x11cfbc ldr r12, [sp, #0x1c]
 *   @0x11cfc0 str r2, [sp, #0x4]
 *   @0x11cfc4 mov r2, r7
 *   @0x11cfc8 str r3, [sp, #0x8]
 *   @0x11cfcc mov r3, r8
 *   @0x11cfd0 str r12, [sp]
 *   @0x11cfd4 str r11, [sp, #0xc]
 *   @0x11cfd8 str r0, [sp, #0x10]
 *   @0x11cfdc mov r0, r9
 *   @0x11cfe0 bl 0xbfb44 <_ZN17CSkeletonInstance16CreateAttachmentEPKcP7CSpriteifffff>
 *   @0x11cfe4 mov r3, r6
 *   @0x11cfe8 str r6, [r4]
 *   @0x11cfec movt r3, #0x3ff0
 *   @0x11cff0 str r3, [r4, #0x4]
 *   @0x11cff4 add sp, sp, #44
 *   @0x11cff8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §9/102 F_ShowQuestion(RValue&, CInstance*, CInstance*, int, RValue*)  0x126694  size 304  76 条（0x126694..0x1267c4）
 * @func 0x126694 0x1267c4  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x126708→0x5428e8, 0x12671c→0x544c38, 0x126734→0x483718, 0x126780→0x483718
 * 调用序列: InputQuery::Question(char const*, char const*)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / DebuggerIsConnected() / DebuggerRunBackgroundMessageLoop() / DebuggerStopBackgroundMessageLoop() / IO_Clear()
 * 字段偏移 top8: 0x10×5 / 0xc×2 / 0x4×2 / 0x110×1 / 0x28×1 / 0xdc×1 / 0x-4×1 / 0xa4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126694 ldr r1, [pc, #0x110]
 *   @0x126698 mov r12, #16
 *   @0x12669c push {r4, r5, lr}
 *   @0x1266a0 sub sp, sp, #28
 *   @0x1266a4 add r1, pc, r1
 *   @0x1266a8 movw r2, #0x232
 *   @0x1266ac mov r3, #1
 *   @0x1266b0 mov r5, r0
 *   @0x1266b4 mov r0, r12
 *   @0x1266b8 str r12, [sp, #0xc]
 *   @0x1266bc ldr r4, [sp, #0x28]
 *   @0x1266c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1266c4 mov r1, #0
 *   @0x1266c8 mov r3, r4
 *   @0x1266cc ldr r4, [pc, #0xdc]
 *   @0x1266d0 add r4, pc, r4
 *   @0x1266d4 mov r2, r0
 *   @0x1266d8 add r0, sp, #24
 *   @0x1266dc str r2, [sp, #0x10]
 *   @0x1266e0 str r2, [r0, #-0x4]!
 *   @0x1266e4 strb r1, [r2]
 *   @0x1266e8 add r1, sp, #16
 *   @0x1266ec add r2, sp, #12
 *   @0x1266f0 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x1266f4 ldr r0, [sp, #0x10]
 *   @0x1266f8 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x1266fc bl 0x29cb74 <_Z19DebuggerIsConnectedv>
 *   @0x126700 cmp r0, #0
 *   @0x126704 beq 0x126780 <_Z14F_ShowQuestionR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x126708 ldr r3, [pc, #0xa4]
 *   @0x12670c ldr r3, [r4, r3]
 *   @0x126710 ldrb r3, [r3]
 *   @0x126714 cmp r3, #0
 *   @0x126718 beq 0x126730 <_Z14F_ShowQuestionR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x12671c ldr r3, [pc, #0x94]
 *   @0x126720 ldr r3, [r4, r3]
 *   @0x126724 ldr r3, [r3]
 *   @0x126728 cmp r3, #0
 *   @0x12672c beq 0x126798 <_Z14F_ShowQuestionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x126730 bl 0x29cb88 <_Z32DebuggerRunBackgroundMessageLoopv>
 *   @0x126734 ldr r3, [pc, #0x80]
 *   @0x126738 ldr r1, [sp, #0x10]
 *   @0x12673c ldr r3, [r4, r3]
 *   @0x126740 ldr r0, [r3]
 *   @0x126744 bl 0xf29a4 <_ZN10InputQuery8QuestionEPKcS1_>
 *   @0x126748 str r0, [sp, #0x4]
 *   @0x12674c bl 0x29cc30 <_Z33DebuggerStopBackgroundMessageLoopv>
 *   @0x126750 ldr r0, [sp, #0x4]
 *   @0x126754 vmov s15, r0
 *   @0x126758 mov r1, #0
 *   @0x12675c str r1, [r5, #0xc]
 *   @0x126760 vcvt.f64.s32 d7, s15
 *   @0x126764 vmov r2, r3, d7
 *   @0x126768 stm r5, {r2, r3}
 *   @0x12676c bl 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126770 ldr r0, [sp, #0x10]
 *   @0x126774 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x126778 add sp, sp, #28
 *   @0x12677c pop {r4, r5, pc}
 *   @0x126780 ldr r3, [pc, #0x34]
 *   @0x126784 ldr r1, [sp, #0x10]
 *   @0x126788 ldr r3, [r4, r3]
 *   @0x12678c ldr r0, [r3]
 *   @0x126790 bl 0xf29a4 <_ZN10InputQuery8QuestionEPKcS1_>
 *   @0x126794 b 0x126754 <_Z14F_ShowQuestionR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x126798 ldr r1, [pc, #0x20]
 *   @0x12679c mov r0, #1
 *   @0x1267a0 add r1, pc, r1
 *   @0x1267a4 bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz>
 *   @0x1267a8 b 0x126730 <_Z14F_ShowQuestionR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1267ac mlaeq r1, r0, r11, r5
 *   @0x1267b0 eoreq r11, r12, r0, lsl #11
 *   @0x1267b4 .word 0xffffbcd4
 *   @0x1267b8 .word 0xffffc7d0
 *   @0x1267bc .word 0xffffce30
 *   @0x1267c0 .word 0x00215ad8
 *
 * ══ §10/102 F_ZipUnzip(RValue&, CInstance*, CInstance*, int, RValue*)  0x13914c  size 304  76 条（0x13914c..0x13927c）
 * @func 0x13914c 0x13927c  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::_GetSaveFileName(char*, int, char const*)×3 / YYGetString(RValue const*, int)×2 / LoadSave::SaveFileExists(char const*) / LoadSave::BundleFileExists(char const*) / Command_Unzip(char const*, char const*, int, int, char*) / LoadSave::_GetBundleFileName(char*, int, char const*) / 0xb65d4
 * 字段偏移 top8: 0x80c×2 / 0x4×2 / 0x118×1 / 0x828×1 / 0xc×1 / 0xb4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13914c push {r4, r5, r6, r7, r8, lr}
 *   @0x139150 sub sp, sp, #2064
 *   @0x139154 ldr r5, [pc, #0x118]
 *   @0x139158 mov r4, r0
 *   @0x13915c ldr r7, [sp, #0x828]
 *   @0x139160 mov r1, #0
 *   @0x139164 ldr r5, [pc, r5]
 *   @0x139168 ldr r3, [r5]
 *   @0x13916c mov r0, r7
 *   @0x139170 str r3, [sp, #0x80c]
 *   @0x139174 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x139178 mov r1, #1
 *   @0x13917c mov r6, r0
 *   @0x139180 mov r0, r7
 *   @0x139184 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x139188 mov r3, #0
 *   @0x13918c str r3, [r4, #0xc]
 *   @0x139190 str r3, [r4]
 *   @0x139194 str r3, [r4, #0x4]
 *   @0x139198 mov r8, r0
 *   @0x13919c mov r0, r6
 *   @0x1391a0 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x1391a4 cmp r0, #0
 *   @0x1391a8 bne 0x139258 <_Z10F_ZipUnzipR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x1391ac mov r0, r6
 *   @0x1391b0 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x1391b4 cmp r0, #0
 *   @0x1391b8 bne 0x139240 <_Z10F_ZipUnzipR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x1391bc ldr r3, [pc, #0xb4]
 *   @0x1391c0 add r7, sp, #12
 *   @0x1391c4 movw r12, #0x6261
 *   @0x1391c8 mov r2, r6
 *   @0x1391cc ldr r3, [pc, r3]
 *   @0x1391d0 movt r12, #0x2b
 *   @0x1391d4 mov r0, r7
 *   @0x1391d8 mov r1, #1024
 *   @0x1391dc str r12, [r3]
 *   @0x1391e0 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1391e4 add r6, sp, #1040
 *   @0x1391e8 mov r2, r8
 *   @0x1391ec sub r6, r6, #4
 *   @0x1391f0 mov r1, #1024
 *   @0x1391f4 mov r0, r6
 *   @0x1391f8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1391fc mov r3, #0
 *   @0x139200 mov r2, r3
 *   @0x139204 mov r1, r6
 *   @0x139208 str r3, [sp]
 *   @0x13920c mov r0, r7
 *   @0x139210 bl 0x1ca040 <_Z13Command_UnzipPKcS0_iiPc>
 *   @0x139214 ldr r1, [sp, #0x80c]
 *   @0x139218 vmov s15, r0
 *   @0x13921c vcvt.f64.s32 d7, s15
 *   @0x139220 vmov r2, r3, d7
 *   @0x139224 vstr s14, [r4]
 *   @0x139228 ldr r2, [r5]
 *   @0x13922c cmp r1, r2
 *   @0x139230 str r3, [r4, #0x4]
 *   @0x139234 bne 0x139270 <_Z10F_ZipUnzipR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x139238 add sp, sp, #2064
 *   @0x13923c pop {r4, r5, r6, r7, r8, pc}
 *   @0x139240 add r7, sp, #12
 *   @0x139244 mov r2, r6
 *   @0x139248 mov r1, #1024
 *   @0x13924c mov r0, r7
 *   @0x139250 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x139254 b 0x1391e4 <_Z10F_ZipUnzipR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x139258 add r7, sp, #12
 *   @0x13925c mov r2, r6
 *   @0x139260 mov r1, #1024
 *   @0x139264 mov r0, r7
 *   @0x139268 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x13926c b 0x1391e4 <_Z10F_ZipUnzipR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x139270 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x139274 eoreq r4, r11, r12, ror #15
 *   @0x139278 strhteq r6, [r11], -r4
 *
 * ══ §11/102 F_D3DSetProjectionExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x144770  size 304  76 条（0x144770..0x1448a0）
 * @func 0x144770 0x1448a0  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×13 / GR_3D_Projection_LookAt_Ext(float, float, float, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x2c×2 / 0x30×2 / 0x34×2 / 0x38×2 / 0x3c×2 / 0x68×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144770 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x144774 sub sp, sp, #68
 *   @0x144778 mov r1, #0
 *   @0x14477c ldr r4, [sp, #0x68]
 *   @0x144780 mov r0, r4
 *   @0x144784 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144788 mov r1, #1
 *   @0x14478c mov r5, r0
 *   @0x144790 mov r0, r4
 *   @0x144794 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144798 mov r1, #2
 *   @0x14479c mov r6, r0
 *   @0x1447a0 mov r0, r4
 *   @0x1447a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1447a8 mov r1, #3
 *   @0x1447ac mov r2, r0
 *   @0x1447b0 mov r0, r4
 *   @0x1447b4 str r2, [sp, #0x2c]
 *   @0x1447b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1447bc mov r1, #4
 *   @0x1447c0 mov r3, r0
 *   @0x1447c4 mov r0, r4
 *   @0x1447c8 str r3, [sp, #0x30]
 *   @0x1447cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1447d0 mov r1, #5
 *   @0x1447d4 mov r12, r0
 *   @0x1447d8 mov r0, r4
 *   @0x1447dc str r12, [sp, #0x34]
 *   @0x1447e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1447e4 mov r1, #6
 *   @0x1447e8 str r0, [sp, #0x38]
 *   @0x1447ec mov r0, r4
 *   @0x1447f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1447f4 mov r1, #7
 *   @0x1447f8 str r0, [sp, #0x3c]
 *   @0x1447fc mov r0, r4
 *   @0x144800 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144804 mov r1, #8
 *   @0x144808 mov r11, r0
 *   @0x14480c mov r0, r4
 *   @0x144810 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144814 mov r1, #9
 *   @0x144818 mov r10, r0
 *   @0x14481c mov r0, r4
 *   @0x144820 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144824 mov r1, #10
 *   @0x144828 mov r9, r0
 *   @0x14482c mov r0, r4
 *   @0x144830 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144834 mov r1, #11
 *   @0x144838 mov r8, r0
 *   @0x14483c mov r0, r4
 *   @0x144840 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144844 mov r1, #12
 *   @0x144848 mov r7, r0
 *   @0x14484c mov r0, r4
 *   @0x144850 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144854 ldr r1, [sp, #0x38]
 *   @0x144858 ldr r12, [sp, #0x34]
 *   @0x14485c str r11, [sp, #0xc]
 *   @0x144860 str r1, [sp, #0x4]
 *   @0x144864 ldr r1, [sp, #0x3c]
 *   @0x144868 str r12, [sp]
 *   @0x14486c str r10, [sp, #0x10]
 *   @0x144870 str r1, [sp, #0x8]
 *   @0x144874 mov r1, r6
 *   @0x144878 str r9, [sp, #0x14]
 *   @0x14487c str r8, [sp, #0x18]
 *   @0x144880 str r7, [sp, #0x1c]
 *   @0x144884 ldr r2, [sp, #0x2c]
 *   @0x144888 ldr r3, [sp, #0x30]
 *   @0x14488c str r0, [sp, #0x20]
 *   @0x144890 mov r0, r5
 *   @0x144894 bl 0x1632f0 <_Z27GR_3D_Projection_LookAt_Extfffffffffffff>
 *   @0x144898 add sp, sp, #68
 *   @0x14489c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §12/102 GraphicsPerf::oprintf(float, float, unsigned int, unsigned int, char const*, ...)  0x17c2f8  size 304  76 条（0x17c2f8..0x17c428）
 * @func 0x17c2f8 0x17c428  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GraphicsPerf::Print(float, float, float, float, unsigned int, char*, int)×5 / 0xb667c / 0xb65d4
 * 字段偏移 top8: 0x814×2 / 0x118×1 / 0x848×1 / 0x10×1 / 0x4×1 / 0x8×1
 * VFP 指令 29 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17c2f8 push {r4, r5, r6, r7, r8, lr}
 *   @0x17c2fc vpush {d8, d9, d10}
 *   @0x17c300 sub sp, sp, #2064
 *   @0x17c304 ldr r5, [pc, #0x118]
 *   @0x17c308 sub sp, sp, #8
 *   @0x17c30c mov r7, r2
 *   @0x17c310 vmov s18, r0
 *   @0x17c314 ldr r5, [pc, r5]
 *   @0x17c318 ldr r12, [sp, #0x848]
 *   @0x17c31c mov r8, r3
 *   @0x17c320 vmov s17, r1
 *   @0x17c324 ldr r2, [r5]
 *   @0x17c328 cmp r12, #0
 *   @0x17c32c moveq r0, r12
 *   @0x17c330 str r2, [sp, #0x814]
 *   @0x17c334 beq 0x17c400 <_ZN12GraphicsPerf7oprintfEffjjPKcz+0x108>
 *   @0x17c338 vmov.f32 s16, #1.000000e+00
 *   @0x17c33c add r4, sp, #20
 *   @0x17c340 add r2, sp, #2112
 *   @0x17c344 mov r1, r12
 *   @0x17c348 add r2, r2, #12
 *   @0x17c34c mov r0, r4
 *   @0x17c350 str r2, [sp, #0x10]
 *   @0x17c354 bl 0xb667c <vsprintf@plt>
 *   @0x17c358 mvn r6, #-2147483648
 *   @0x17c35c str r4, [sp, #0x4]
 *   @0x17c360 str r7, [sp]
 *   @0x17c364 str r6, [sp, #0x8]
 *   @0x17c368 vsub.f32 s19, s17, s16
 *   @0x17c36c vmov r2, s16
 *   @0x17c370 vmov r3, s16
 *   @0x17c374 vsub.f32 s21, s18, s16
 *   @0x17c378 vmov r1, s19
 *   @0x17c37c vmov r0, s21
 *   @0x17c380 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17c384 vadd.f32 s20, s18, s16
 *   @0x17c388 vmov r1, s19
 *   @0x17c38c vmov r2, s16
 *   @0x17c390 vmov r3, s16
 *   @0x17c394 stmib sp, {r4, r6}
 *   @0x17c398 str r7, [sp]
 *   @0x17c39c vmov r0, s20
 *   @0x17c3a0 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17c3a4 vadd.f32 s19, s17, s16
 *   @0x17c3a8 vmov r2, s16
 *   @0x17c3ac vmov r3, s16
 *   @0x17c3b0 stmib sp, {r4, r6}
 *   @0x17c3b4 str r7, [sp]
 *   @0x17c3b8 vmov r0, s21
 *   @0x17c3bc vmov r1, s19
 *   @0x17c3c0 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17c3c4 vmov r1, s19
 *   @0x17c3c8 vmov r2, s16
 *   @0x17c3cc vmov r3, s16
 *   @0x17c3d0 stmib sp, {r4, r6}
 *   @0x17c3d4 str r7, [sp]
 *   @0x17c3d8 vmov r0, s20
 *   @0x17c3dc bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17c3e0 vmov r2, s16
 *   @0x17c3e4 stmib sp, {r4, r6}
 *   @0x17c3e8 str r8, [sp]
 *   @0x17c3ec vmov r0, s18
 *   @0x17c3f0 vmov r1, s17
 *   @0x17c3f4 vmov r3, s16
 *   @0x17c3f8 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17c3fc add r0, r0, #2
 *   @0x17c400 ldr r2, [sp, #0x814]
 *   @0x17c404 ldr r3, [r5]
 *   @0x17c408 cmp r2, r3
 *   @0x17c40c bne 0x17c420 <_ZN12GraphicsPerf7oprintfEffjjPKcz+0x128>
 *   @0x17c410 add sp, sp, #2064
 *   @0x17c414 add sp, sp, #8
 *   @0x17c418 vpop {d8, d9, d10}
 *   @0x17c41c pop {r4, r5, r6, r7, r8, pc}
 *   @0x17c420 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x17c424 eoreq r1, r7, r12, lsr r6
 *
 * ══ §13/102 IniFile::ReadIniFile()  0x236120  size 304  76 条（0x236120..0x236250）
 * @func 0x236120 0x236250  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::GetSection()×2 / IniFile::GetKey() / IniFile::ReadIniFile()+0x5c / MemoryManager::Free(void const*) / IniFile::_sysReadIniFile(char const*)
 * 字段偏移 top8: 0x4×7 / 0x10×5 / 0xc×5 / 0x8×3 / 0x110×1 / 0x14×1 / 0x1×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236120 ldr r2, [r0, #0x10]
 *   @0x236124 push {r3, r4, r5, lr}
 *   @0x236128 cmp r2, #0
 *   @0x23612c mov r4, r0
 *   @0x236130 beq 0x236230 <_ZN7IniFile11ReadIniFileEv+0x110>
 *   @0x236134 ldr r3, [pc, #0x110]
 *   @0x236138 mov r1, #0
 *   @0x23613c str r1, [r4, #0xc]
 *   @0x236140 ldr r3, [pc, r3]
 *   @0x236144 str r1, [r4, #0x14]
 *   @0x236148 ldr r3, [r3]
 *   @0x23614c cmp r3, #2
 *   @0x236150 str r3, [r4, #0x4]
 *   @0x236154 bgt 0x236204 <_ZN7IniFile11ReadIniFileEv+0xe4>
 *   @0x236158 mov r0, r4
 *   @0x23615c bl 0x2355e4 <_ZN7IniFile10GetSectionEv>
 *   @0x236160 ldr r2, [r4, #0xc]
 *   @0x236164 ldr r1, [r4, #0x4]
 *   @0x236168 mov r5, r0
 *   @0x23616c str r0, [r4, #0x8]
 *   @0x236170 cmp r2, r1
 *   @0x236174 mov r0, r4
 *   @0x236178 bge 0x2361a8 <_ZN7IniFile11ReadIniFileEv+0x88>
 *   @0x23617c bl 0x235710 <_ZN7IniFile6GetKeyEv>
 *   @0x236180 cmp r0, #0
 *   @0x236184 beq 0x2361c0 <_ZN7IniFile11ReadIniFileEv+0xa0>
 *   @0x236188 ldr r2, [r4, #0xc]
 *   @0x23618c ldr r1, [r4, #0x4]
 *   @0x236190 ldr r3, [r5, #0x4]
 *   @0x236194 cmp r2, r1
 *   @0x236198 str r3, [r0]
 *   @0x23619c str r0, [r5, #0x4]
 *   @0x2361a0 mov r0, r4
 *   @0x2361a4 blt 0x23617c <_ZN7IniFile11ReadIniFileEv+0x5c>
 *   @0x2361a8 ldr r0, [r4, #0x10]
 *   @0x2361ac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2361b0 mov r3, #0
 *   @0x2361b4 mov r0, #1
 *   @0x2361b8 str r3, [r4, #0x10]
 *   @0x2361bc pop {r3, r4, r5, pc}
 *   @0x2361c0 ldr r2, [r4, #0xc]
 *   @0x2361c4 ldr r1, [r4, #0x4]
 *   @0x2361c8 cmp r2, r1
 *   @0x2361cc bge 0x236170 <_ZN7IniFile11ReadIniFileEv+0x50>
 *   @0x2361d0 ldr r3, [r4, #0x10]
 *   @0x2361d4 ldrb r3, [r3, r2]
 *   @0x2361d8 cmp r3, #91
 *   @0x2361dc bne 0x236170 <_ZN7IniFile11ReadIniFileEv+0x50>
 *   @0x2361e0 mov r0, r4
 *   @0x2361e4 bl 0x2355e4 <_ZN7IniFile10GetSectionEv>
 *   @0x2361e8 ldr r3, [r4, #0x8]
 *   @0x2361ec ldr r2, [r4, #0xc]
 *   @0x2361f0 ldr r1, [r4, #0x4]
 *   @0x2361f4 mov r5, r0
 *   @0x2361f8 str r3, [r0]
 *   @0x2361fc str r0, [r4, #0x8]
 *   @0x236200 b 0x236170 <_ZN7IniFile11ReadIniFileEv+0x50>
 *   @0x236204 ldrb r3, [r2]
 *   @0x236208 cmp r3, #239
 *   @0x23620c bne 0x236158 <_ZN7IniFile11ReadIniFileEv+0x38>
 *   @0x236210 ldrb r3, [r2, #0x1]
 *   @0x236214 cmp r3, #187
 *   @0x236218 bne 0x236158 <_ZN7IniFile11ReadIniFileEv+0x38>
 *   @0x23621c ldrb r3, [r2, #0x2]
 *   @0x236220 cmp r3, #191
 *   @0x236224 moveq r3, #3
 *   @0x236228 streq r3, [r4, #0xc]
 *   @0x23622c b 0x236158 <_ZN7IniFile11ReadIniFileEv+0x38>
 *   @0x236230 ldr r1, [r0]
 *   @0x236234 bl 0x2360d8 <_ZN7IniFile15_sysReadIniFileEPKc>
 *   @0x236238 cmp r0, #0
 *   @0x23623c mov r2, r0
 *   @0x236240 str r0, [r4, #0x10]
 *   @0x236244 bne 0x236134 <_ZN7IniFile11ReadIniFileEv+0x14>
 *   @0x236248 pop {r3, r4, r5, pc}
 *   @0x23624c andseq r11, r11, r12, asr r3
 *
 * ══ §14/102 _zip_dirent_write(zip_dirent*, __sFILE*, int, zip_error*)  0x2a3ce0  size 304  76 条（0x2a3ce0..0x2a3e10）
 * @func 0x2a3ce0 0x2a3e10  size 304  76 条
 * 部分覆盖: 本节 76/133 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2a399c+0x2c×7 / anon_2a399c×2 / 0xb68bc×2 / 0xb6f04 / 0xfece35c0 / _zip_error_set(zip_error*, int, int)
 * 字段偏移 top8: 0x18×3 / 0xc×2 / 0x114×1 / 0x2×1 / 0x4×1 / 0x8×1 / 0x-4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a3ce0 push.w {r0, r1, r4, r5, r6, r7, r8, lr}
 *   @0x2a3ce4 mov r5, r0
 *   @0x2a3ce8 mov r7, r3
 *   @0x2a3cec cbz r2, 0x2a3cf4 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0x14>
 *   @0x2a3cf0 add r0, pc
 *   @0x2a3cf4 ldr r0, [pc, #0x114]
 *   @0x2a3cf8 movs r1, #0x1
 *   @0x2a3cfc mov r3, r4
 *   @0x2a3d00 ldmdblt lr, {r1, r2, r3, r4, r6, r7, r8, r10, r11, sp, lr, pc}
 *   @0x2a3d04 ldrh r0, [r5]
 *   @0x2a3d08 bl 0x2a39c8 <zip_close+0x7dc>
 *   @0x2a3d0c ldrh r0, [r5, #0x2]
 *   @0x2a3d10 bl 0x2a39c8 <zip_close+0x7dc>
 *   @0x2a3d14 ldrh r0, [r5, #0x4]
 *   @0x2a3d18 bl 0x2a39c8 <zip_close+0x7dc>
 *   @0x2a3d1c mov r1, r4
 *   @0x2a3d20 bl 0x2a39c8 <zip_close+0x7dc>
 *   @0x2a3d24 ldr r3, [r5, #0x8]
 *   @0x2a3d28 str r3, [r0, #-4]!
 *   @0x2a3d2c blx 0xb6f04 <localtime@plt>
 *   @0x2a3d30 mov r1, r4
 *   @0x2a3d34 ldr r3, [r0, #0x14]
 *   @0x2a3d38 subs r3, #0x50
 *   @0x2a3d3c add.w r8, r2, r3, lsl #9
 *   @0x2a3d40 ldr r3, [r0, #0xc]
 *   @0x2a3d44 add r3, r8
 *   @0x2a3d48 stmdavs r3, {r0, r1, r7, r11, r12, sp, lr, pc} ^
 *   @0x2a3d4c ldr r0, [r0]
 *   @0x2a3d50 add.w r3, r2, r3, lsl #5
 *   @0x2a3d54 add.w r0, r3, r0, asr #1
 *   @0x2a3d58 uxth r0, r0
 *   @0x2a3d5c .word 0x4640fe35
 *   @0x2a3d60 mov r1, r4
 *   @0x2a3d64 stmvs r8!, {r0, r4, r5, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2a3d68 mov r1, r4
 *   @0x2a3d6c stmdbvs r8!, {r0, r1, r2, r4, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2a3d70 mov r1, r4
 *   @0x2a3d74 stmdbvs r8!, {r0, r1, r4, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2a3d78 mov r1, r4
 *   @0x2a3d7c blhi 0xfece35c0 <b2_toiTime+0xfffffffffe58a11c>
 *   @0x2a3d80 mov r1, r4
 *   @0x2a3d84 stchi p14, c15, [r8], #132
 *   @0x2a3d88 mov r1, r4
 *   @0x2a3d8c ldmiblt lr, {r0, r2, r3, r4, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2a3d90 ldrh r0, [r5, #0x2c]
 *   @0x2a3d94 bl 0x2a39c8 <zip_close+0x7dc>
 *   @0x2a3d98 ldrh r0, [r5, #0x2e]
 *   @0x2a3d9c bl 0x2a39c8 <zip_close+0x7dc>
 *   @0x2a3da0 ldrh r0, [r5, #0x30]
 *   @0x2a3da4 bl 0x2a39c8 <zip_close+0x7dc>
 *   @0x2a3da8 ldr r0, [r5, #0x34]
 *   @0x2a3dac bl 0x2a399c <zip_close+0x7b0>
 *   @0x2a3db0 ldr r0, [r5, #0x38]
 *   @0x2a3db4 bl 0x2a399c <zip_close+0x7b0>
 *   @0x2a3db8 ldrh r2, [r5, #0x1c]
 *   @0x2a3dbc ldr r0, [r5, #0x18]
 *   @0x2a3dc0 mov r3, r4
 *   @0x2a3dc4 stchi p13, c14, [r10], #496
 *   @0x2a3dc8 cbz r2, 0x2a3dd4 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0xf4>
 *   @0x2a3dcc movs r1, #0x1
 *   @0x2a3dd0 blx 0xb68bc <fwrite@plt>
 *   @0x2a3dd4 cbnz r6, 0x2a3de4 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0x104>
 *   @0x2a3dd8 cbz r2, 0x2a3de4 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0x104>
 *   @0x2a3ddc movs r1, #0x1
 *   @0x2a3de0 blx 0xb68bc <fwrite@plt>
 *   @0x2a3de4 ldrh r0, [r4, #0xc]
 *   @0x2a3de8 addlt r0, r0, #64
 *   @0x2a3dec cbz r0, 0x2a3e00 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0x120>
 *   @0x2a3df0 .word 0x2106ef04
 *   @0x2a3df4 ldr r2, [r0]
 *   @0x2a3df8 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a3dfc mov.w r0, #0xffffffff
 *   @0x2a3e00 add sp, #0x8
 *   @0x2a3e04 svclt #0x81f0
 *   @0x2a3e08 strh r6, [r1, #0x18]
 *   @0x2a3e0c strh r5, [r1, #0x18]
 *
 * ══ §15/102 b2GetPointStates(b2PointState*, b2PointState*, b2Manifold const*, b2Manifold const*)  0x2c3664  size 304  76 条（0x2c3664..0x2c3794）
 * @func 0x2c3664 0x2c3794  size 304  76 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2GetPointStates(b2PointState*, b2PointState*, b2Manifold const*, b2Manifold const*)+0x78 / b2GetPointStates(b2PointState*, b2PointState*, b2Manifold const*, b2Manifold const*)+0xe8 / b2GetPointStates(b2PointState*, b2PointState*, b2Manifold const*, b2Manifold const*)+0xd0 / b2GetPointStates(b2PointState*, b2PointState*, b2Manifold const*, b2Manifold const*)+0x10c
 * 字段偏移 top8: 0x4×8 / 0x10×4 / 0x3c×2 / 0x24×2 / 0x-4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c3664 push {r4, r5, r6, r7, r8, r9, r10}
 *   @0x2c3668 mov r12, #0
 *   @0x2c366c ldr r7, [r2, #0x3c]
 *   @0x2c3670 ldr r8, [r3, #0x3c]
 *   @0x2c3674 cmp r7, r12
 *   @0x2c3678 str r12, [r0]
 *   @0x2c367c str r12, [r1]
 *   @0x2c3680 str r12, [r0, #0x4]
 *   @0x2c3684 str r12, [r1, #0x4]
 *   @0x2c3688 ble 0x2c36dc <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x78>
 *   @0x2c368c cmp r8, #0
 *   @0x2c3690 mov r6, r0
 *   @0x2c3694 mov r4, r2
 *   @0x2c3698 mov r9, #3
 *   @0x2c369c mov r10, #2
 *   @0x2c36a0 ble 0x2c374c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xe8>
 *   @0x2c36a4 ldr r5, [r4, #0x10]
 *   @0x2c36a8 add r12, r12, #1
 *   @0x2c36ac str r9, [r6], #4
 *   @0x2c36b0 add r4, r4, #20
 *   @0x2c36b4 ldr r0, [r3, #0x10]
 *   @0x2c36b8 cmp r0, r5
 *   @0x2c36bc beq 0x2c373c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd8>
 *   @0x2c36c0 cmp r8, #1
 *   @0x2c36c4 beq 0x2c36d4 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x70>
 *   @0x2c36c8 ldr r0, [r3, #0x24]
 *   @0x2c36cc cmp r0, r5
 *   @0x2c36d0 beq 0x2c373c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd8>
 *   @0x2c36d4 cmp r12, r7
 *   @0x2c36d8 bne 0x2c36a4 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x40>
 *   @0x2c36dc cmp r8, #0
 *   @0x2c36e0 ble 0x2c3734 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd0>
 *   @0x2c36e4 cmp r7, #0
 *   @0x2c36e8 mov r0, r3
 *   @0x2c36ec mov r5, #1
 *   @0x2c36f0 mov r3, #0
 *   @0x2c36f4 mov r6, #2
 *   @0x2c36f8 ble 0x2c3770 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x10c>
 *   @0x2c36fc ldr r12, [r0, #0x10]
 *   @0x2c3700 add r3, r3, #1
 *   @0x2c3704 str r5, [r1], #4
 *   @0x2c3708 add r0, r0, #20
 *   @0x2c370c ldr r4, [r2, #0x10]
 *   @0x2c3710 cmp r12, r4
 *   @0x2c3714 beq 0x2c3744 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xe0>
 *   @0x2c3718 cmp r7, #1
 *   @0x2c371c beq 0x2c372c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xc8>
 *   @0x2c3720 ldr r4, [r2, #0x24]
 *   @0x2c3724 cmp r12, r4
 *   @0x2c3728 beq 0x2c3744 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xe0>
 *   @0x2c372c cmp r3, r8
 *   @0x2c3730 bne 0x2c36fc <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x98>
 *   @0x2c3734 pop {r4, r5, r6, r7, r8, r9, r10}
 *   @0x2c3738 bx lr
 *   @0x2c373c str r10, [r6, #-0x4]
 *   @0x2c3740 b 0x2c36d4 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x70>
 *   @0x2c3744 str r6, [r1, #-0x4]
 *   @0x2c3748 b 0x2c372c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xc8>
 *   @0x2c374c add r12, r12, #1
 *   @0x2c3750 str r9, [r6], #4
 *   @0x2c3754 cmp r12, r7
 *   @0x2c3758 beq 0x2c36dc <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x78>
 *   @0x2c375c add r12, r12, #1
 *   @0x2c3760 str r9, [r6], #4
 *   @0x2c3764 cmp r12, r7
 *   @0x2c3768 bne 0x2c374c <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xe8>
 *   @0x2c376c b 0x2c36dc <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x78>
 *   @0x2c3770 add r3, r3, #1
 *   @0x2c3774 str r5, [r1], #4
 *   @0x2c3778 cmp r3, r8
 *   @0x2c377c beq 0x2c3734 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd0>
 *   @0x2c3780 add r3, r3, #1
 *   @0x2c3784 str r5, [r1], #4
 *   @0x2c3788 cmp r3, r8
 *   @0x2c378c bne 0x2c3770 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x10c>
 *   @0x2c3790 b 0x2c3734 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0xd0>
 *
 * ══ §16/102 CSkeletonSprite::DrawFrame(CSkeletonInstance*, char const*, char const*, float, float, float, float, float, float, unsigned int, float)  0xc069c  size 300  75 条（0xc069c..0xc07c8）
 * @func 0xc069c 0xc07c8  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spBone_setYDown / operator new(unsigned int) / CSkeletonInstance::CSkeletonInstance(CSkeletonInstance*) / CSkeletonInstance::SelectAnimation(char const*) / CSkeletonInstance::SelectSkin(char const*) / CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*) / CSkeletonSprite::DrawFrame(CSkeletonInstance*, char const*, char const*, float, float, float, float, float, float, unsigned int, float)+0xfc / CSkeletonInstance::SetAttachment(char const*, char const*, bool)
 * 字段偏移 top8: 0x10×4 / 0x14×3 / 0x1c×3 / 0x2×2 / 0x54×1 / 0x58×1 / 0x68×1 / 0x6c×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc069c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc06a0 vpush {d8, d9}
 *   @0xc06a4 sub sp, sp, #28
 *   @0xc06a8 vldr s16, [sp, #80]
 *   @0xc06ac mov r11, r2
 *   @0xc06b0 mov r7, r0
 *   @0xc06b4 ldr r2, [sp, #0x54]
 *   @0xc06b8 mov r0, #1
 *   @0xc06bc str r3, [sp, #0x14]
 *   @0xc06c0 mov r5, r1
 *   @0xc06c4 ldr r10, [sp, #0x58]
 *   @0xc06c8 vldr s19, [sp, #92]
 *   @0xc06cc str r2, [sp, #0x10]
 *   @0xc06d0 vldr s18, [sp, #96]
 *   @0xc06d4 vldr s17, [sp, #100]
 *   @0xc06d8 ldr r8, [sp, #0x68]
 *   @0xc06dc ldr r9, [sp, #0x6c]
 *   @0xc06e0 bl 0x284ed8 <spBone_setYDown>
 *   @0xc06e4 mov r0, #52
 *   @0xc06e8 mov r4, #0
 *   @0xc06ec bl 0x27c524 <_Znwj>
 *   @0xc06f0 mov r1, r5
 *   @0xc06f4 mov r6, r0
 *   @0xc06f8 bl 0xc04d8 <_ZN17CSkeletonInstanceC2EPS_>
 *   @0xc06fc mov r0, r6
 *   @0xc0700 mov r1, r11
 *   @0xc0704 bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc>
 *   @0xc0708 ldr r3, [sp, #0x14]
 *   @0xc070c mov r0, r6
 *   @0xc0710 mov r1, r3
 *   @0xc0714 bl 0xbe590 <_ZN17CSkeletonInstance10SelectSkinEPKc>
 *   @0xc0718 vcvt.s32.f32 s16, s16
 *   @0xc071c mov r3, r10
 *   @0xc0720 vstr s19, [sp]
 *   @0xc0724 vstr s18, [sp, #4]
 *   @0xc0728 vstr s17, [sp, #8]
 *   @0xc072c ldr r2, [sp, #0x10]
 *   @0xc0730 mov r0, r6
 *   @0xc0734 str r4, [sp, #0xc]
 *   @0xc0738 vmov r1, s16
 *   @0xc073c bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xc0740 ldr r5, [r5, #0x1c]
 *   @0xc0744 ldr r3, [r5, #0x10]
 *   @0xc0748 cmp r3, r4
 *   @0xc074c ble 0xc0798 <_ZN15CSkeletonSprite9DrawFrameEP17CSkeletonInstancePKcS3_ffffffjf+0xfc>
 *   @0xc0750 ldr r2, [r5, #0x14]
 *   @0xc0754 ldr r2, [r2, r4, lsl #2]
 *   @0xc0758 cmp r2, #0
 *   @0xc075c beq 0xc078c <_ZN15CSkeletonSprite9DrawFrameEP17CSkeletonInstancePKcS3_ffffffjf+0xf0>
 *   @0xc0760 ldr r3, [r5]
 *   @0xc0764 mov r0, r6
 *   @0xc0768 ldr r2, [r2, #0x18]
 *   @0xc076c ldr r3, [r3, #0x1c]
 *   @0xc0770 cmp r2, #0
 *   @0xc0774 ldrne r2, [r2]
 *   @0xc0778 ldr r3, [r3, r4, lsl #2]
 *   @0xc077c ldr r1, [r3, #0x4]
 *   @0xc0780 mov r3, #1
 *   @0xc0784 bl 0xbe6cc <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b>
 *   @0xc0788 ldr r3, [r5, #0x10]
 *   @0xc078c add r4, r4, #1
 *   @0xc0790 cmp r3, r4
 *   @0xc0794 bgt 0xc0750 <_ZN15CSkeletonSprite9DrawFrameEP17CSkeletonInstancePKcS3_ffffffjf+0xb4>
 *   @0xc0798 mov r0, r7
 *   @0xc079c mov r2, r8
 *   @0xc07a0 mov r3, r9
 *   @0xc07a4 ldr r1, [r6, #0x1c]
 *   @0xc07a8 bl 0xbe054 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf>
 *   @0xc07ac mov r0, r6
 *   @0xc07b0 bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev>
 *   @0xc07b4 mov r0, r6
 *   @0xc07b8 add sp, sp, #28
 *   @0xc07bc vpop {d8, d9}
 *   @0xc07c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc07c4 b 0x27d1d0 <_ZdlPv>
 *
 * ══ §17/102 YYGML_vertex_colour(int, int, float)  0xc98d8  size 300  75 条（0xc98d8..0xc9a04）
 * @func 0xc98d8 0xc9a04  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_vertex_colour(int, int, float)+0xfc / YYGML_vertex_colour(int, int, float)+0xc4 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / YYGML_vertex_colour(int, int, float)+0x1c
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x14×2 / 0x10×2 / 0xfc×1 / 0x2×1 / 0x2c×1 / 0x3c×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc98d8 cmp r0, #0
 *   @0xc98dc push {r4, r5, lr}
 *   @0xc98e0 vpush {d8}
 *   @0xc98e4 mov r5, r1
 *   @0xc98e8 sub sp, sp, #12
 *   @0xc98ec vmov s16, r2
 *   @0xc98f0 blt 0xc99d4 <_Z19YYGML_vertex_colouriif+0xfc>
 *   @0xc98f4 ldr r3, [pc, #0xfc]
 *   @0xc98f8 add r3, pc, r3
 *   @0xc98fc ldr r3, [r3]
 *   @0xc9900 ldr r4, [r3, r0, lsl #2]
 *   @0xc9904 ldr r2, [r4, #0x2c]
 *   @0xc9908 ldr r3, [r4, #0xc]
 *   @0xc990c ldr r12, [r4, #0x4]
 *   @0xc9910 ldr r0, [r2, #0x14]
 *   @0xc9914 add r2, r0, r3
 *   @0xc9918 cmp r12, r2
 *   @0xc991c blo 0xc999c <_Z19YYGML_vertex_colouriif+0xc4>
 *   @0xc9920 ldr r2, [r4]
 *   @0xc9924 vldr s15, [pc, #200]
 *   @0xc9928 vmul.f32 s16, s16, s15
 *   @0xc992c add r3, r2, r3
 *   @0xc9930 vcvt.s32.f32 s16, s16
 *   @0xc9934 vmov r2, s16
 *   @0xc9938 cmp r2, #255
 *   @0xc993c movgt r2, #-16777216
 *   @0xc9940 bgt 0xc9950 <_Z19YYGML_vertex_colouriif+0x78>
 *   @0xc9944 cmp r2, #0
 *   @0xc9948 lslge r2, r2, #24
 *   @0xc994c movlt r2, #0
 *   @0xc9950 bic r5, r5, #-16777216
 *   @0xc9954 orr r5, r2, r5
 *   @0xc9958 str r5, [r3]
 *   @0xc995c ldr r3, [r4, #0x10]
 *   @0xc9960 ldr r1, [r4, #0x14]
 *   @0xc9964 add r3, r3, #1
 *   @0xc9968 ldr r2, [r4, #0xc]
 *   @0xc996c cmp r3, r1
 *   @0xc9970 str r3, [r4, #0x10]
 *   @0xc9974 add r3, r2, #4
 *   @0xc9978 str r3, [r4, #0xc]
 *   @0xc997c ldrhs r3, [r4, #0x1c]
 *   @0xc9980 movhs r2, #0
 *   @0xc9984 strhs r2, [r4, #0x10]
 *   @0xc9988 addhs r3, r3, #1
 *   @0xc998c strhs r3, [r4, #0x1c]
 *   @0xc9990 add sp, sp, #12
 *   @0xc9994 vpop {d8}
 *   @0xc9998 pop {r4, r5, pc}
 *   @0xc999c add r1, r0, r12
 *   @0xc99a0 mov r2, #0
 *   @0xc99a4 ldr r0, [r4]
 *   @0xc99a8 add r1, r1, r12, lsr #1
 *   @0xc99ac str r1, [r4, #0x4]
 *   @0xc99b0 mov r3, #74
 *   @0xc99b4 str r2, [sp]
 *   @0xc99b8 ldr r2, [pc, #0x3c]
 *   @0xc99bc add r2, pc, r2
 *   @0xc99c0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc99c4 ldr r3, [r4, #0xc]
 *   @0xc99c8 mov r2, r0
 *   @0xc99cc str r0, [r4]
 *   @0xc99d0 b 0xc9924 <_Z19YYGML_vertex_colouriif+0x4c>
 *   @0xc99d4 ldr r3, [pc, #0x24]
 *   @0xc99d8 add r3, pc, r3
 *   @0xc99dc ldr r3, [r3, #0x4]
 *   @0xc99e0 cmp r0, r3
 *   @0xc99e4 blt 0xc98f4 <_Z19YYGML_vertex_colouriif+0x1c>
 *   @0xc99e8 add sp, sp, #12
 *   @0xc99ec vpop {d8}
 *   @0xc99f0 pop {r4, r5, pc}
 *   @0xc99f4 cmnmi pc, #0
 *   @0xc99f8 eorseq r0, r11, r12, lsr r8
 *   @0xc99fc eoreq r7, r6, r4, ror r6
 *   @0xc9a00 eorseq r0, r11, r12, asr r7
 *
 * ══ §18/102 LoginDialogASync(HTTP_REQ_CONTEXT*, void*, int*)  0xf2074  size 300  75 条（0xf2074..0xf21a0）
 * @func 0xf2074 0xf21a0  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb6538×2 / 0xb65bc / 0xb65a4 / CreateDsMap(int, ...) / MemoryManager::Free(void const*) / RemoveDialogAndKick(HTTP_REQ_CONTEXT*)
 * 字段偏移 top8: 0x3c×3 / 0x34×2 / 0x24×2 / 0x108×1 / 0x80×1 / 0x7c×1 / 0x78×1 / 0x70×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2074 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xf2078 mov r6, r0
 *   @0xf207c ldr r5, [pc, #0x108]
 *   @0xf2080 sub sp, sp, #60
 *   @0xf2084 ldr r0, [r0, #0x3c]
 *   @0xf2088 mov r3, #1
 *   @0xf208c add r5, pc, r5
 *   @0xf2090 mov r9, r2
 *   @0xf2094 add r0, r0, r3
 *   @0xf2098 mov r2, #167
 *   @0xf209c mov r1, r5
 *   @0xf20a0 mov r8, #0
 *   @0xf20a4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf20a8 ldr r1, [r6, #0x34]
 *   @0xf20ac ldr r2, [r6, #0x3c]
 *   @0xf20b0 mov r7, r0
 *   @0xf20b4 bl 0xb65bc <memcpy@plt>
 *   @0xf20b8 ldr r3, [r6, #0x3c]
 *   @0xf20bc mov r0, r7
 *   @0xf20c0 strb r8, [r7, r3]
 *   @0xf20c4 bl 0xb6538 <strlen@plt>
 *   @0xf20c8 ldr r3, [r6, #0x34]
 *   @0xf20cc add r0, r0, #1
 *   @0xf20d0 add r4, r3, r0
 *   @0xf20d4 mov r0, r4
 *   @0xf20d8 bl 0xb6538 <strlen@plt>
 *   @0xf20dc mov r3, #1
 *   @0xf20e0 mov r1, r5
 *   @0xf20e4 mov r2, #173
 *   @0xf20e8 mov r5, #0
 *   @0xf20ec add r0, r0, r3
 *   @0xf20f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf20f4 mov r1, r4
 *   @0xf20f8 bl 0xb65a4 <strcpy@plt>
 *   @0xf20fc vldr s14, [r6, #40]
 *   @0xf2100 vcvt.f64.s32 d7, s14
 *   @0xf2104 ldr r2, [r6, #0x24]
 *   @0xf2108 ldr r1, [pc, #0x80]
 *   @0xf210c mov r4, #0
 *   @0xf2110 ldr lr, [pc, #0x7c]
 *   @0xf2114 add r1, pc, r1
 *   @0xf2118 ldr r12, [pc, #0x78]
 *   @0xf211c str r1, [sp, #0x24]
 *   @0xf2120 add lr, pc, lr
 *   @0xf2124 ldr r1, [pc, #0x70]
 *   @0xf2128 add r12, pc, r12
 *   @0xf212c str lr, [sp, #0x4]
 *   @0xf2130 vstr d7, [sp, #40]
 *   @0xf2134 vmov s15, r2
 *   @0xf2138 str r12, [sp, #0x14]
 *   @0xf213c add r1, pc, r1
 *   @0xf2140 vcvt.f64.s32 d7, s15
 *   @0xf2144 strd r4, r5, [sp, #8]
 *   @0xf2148 strd r4, r5, [sp, #24]
 *   @0xf214c str r8, [sp]
 *   @0xf2150 str r7, [sp, #0x10]
 *   @0xf2154 str r8, [sp, #0x30]
 *   @0xf2158 mov r3, r0
 *   @0xf215c mov r0, #4
 *   @0xf2160 str r3, [sp, #0x20]
 *   @0xf2164 vmov r2, r3, d7
 *   @0xf2168 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0xf216c str r0, [r9]
 *   @0xf2170 mov r0, r7
 *   @0xf2174 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf2178 mov r0, r6
 *   @0xf217c bl 0xf1d98 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT>
 *   @0xf2180 mov r0, #63
 *   @0xf2184 add sp, sp, #60
 *   @0xf2188 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xf218c mlaeq r4, r8, lr, r4
 *   @0xf2190 eoreq lr, r3, r12, lsr r9
 *   @0xf2194 eoreq r4, r4, r8, asr #28
 *   @0xf2198 eoreq r4, r4, r12, asr #28
 *   @0xf219c eoreq lr, r3, r4, lsl #18
 *
 * ══ §19/102 F_DrawSpritePart(RValue&, CInstance*, CInstance*, int, RValue*)  0x1228a4  size 300  75 条（0x1228a4..0x1229d0）
 * @func 0x1228a4 0x1229d0  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / Error_Show_Action(char const*, bool)×2 / GetSpriteIndices(CInstance*, RValue*, int&, int&) / Sprite_Data(int) / GR_Draw_Get_Alpha() / CSprite::DrawPart(int, float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x20×2 / 0x10×2 / 0x50×1 / 0x74×1 / 0x24×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1228a4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1228a8 sub sp, sp, #44
 *   @0x1228ac mov r0, r1
 *   @0x1228b0 add r2, sp, #32
 *   @0x1228b4 ldr r4, [sp, #0x50]
 *   @0x1228b8 add r3, sp, #36
 *   @0x1228bc mov r1, r4
 *   @0x1228c0 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_>
 *   @0x1228c4 cmp r0, #0
 *   @0x1228c8 bne 0x1228d4 <_Z16F_DrawSpritePartR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x1228cc add sp, sp, #44
 *   @0x1228d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1228d4 ldr r0, [sp, #0x20]
 *   @0x1228d8 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1228dc ldr r3, [r0, #0x74]
 *   @0x1228e0 mov r5, r0
 *   @0x1228e4 cmp r3, #1
 *   @0x1228e8 beq 0x1229b4 <_Z16F_DrawSpritePartR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x1228ec cmp r3, #2
 *   @0x1228f0 beq 0x1229a0 <_Z16F_DrawSpritePartR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x1228f4 mov r0, r4
 *   @0x1228f8 mov r1, #2
 *   @0x1228fc ldr r8, [sp, #0x24]
 *   @0x122900 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122904 mov r1, #3
 *   @0x122908 mov r7, r0
 *   @0x12290c mov r0, r4
 *   @0x122910 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122914 mov r1, #4
 *   @0x122918 mov r6, r0
 *   @0x12291c mov r0, r4
 *   @0x122920 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122924 mov r1, #5
 *   @0x122928 mov r11, r0
 *   @0x12292c mov r0, r4
 *   @0x122930 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122934 mov r1, #6
 *   @0x122938 mov r10, r0
 *   @0x12293c mov r0, r4
 *   @0x122940 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122944 mov r1, #7
 *   @0x122948 mov r9, r0
 *   @0x12294c mov r0, r4
 *   @0x122950 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122954 mov r4, r0
 *   @0x122958 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x12295c mov r12, #1065353216
 *   @0x122960 mvn lr, #-16777216
 *   @0x122964 str r11, [sp]
 *   @0x122968 mov r1, r8
 *   @0x12296c str r10, [sp, #0x4]
 *   @0x122970 mov r2, r7
 *   @0x122974 str r9, [sp, #0x8]
 *   @0x122978 mov r3, r6
 *   @0x12297c str r4, [sp, #0xc]
 *   @0x122980 str lr, [sp, #0x18]
 *   @0x122984 str r12, [sp, #0x10]
 *   @0x122988 str r12, [sp, #0x14]
 *   @0x12298c str r0, [sp, #0x1c]
 *   @0x122990 mov r0, r5
 *   @0x122994 bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf>
 *   @0x122998 add sp, sp, #44
 *   @0x12299c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1229a0 ldr r0, [pc, #0x20]
 *   @0x1229a4 mov r1, #0
 *   @0x1229a8 add r0, pc, r0
 *   @0x1229ac bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1229b0 b 0x1228cc <_Z16F_DrawSpritePartR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x1229b4 ldr r0, [pc, #0x10]
 *   @0x1229b8 mov r1, #0
 *   @0x1229bc add r0, pc, r0
 *   @0x1229c0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1229c4 b 0x1228cc <_Z16F_DrawSpritePartR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x1229c8 eoreq r7, r1, r0, lsl r11
 *   @0x1229cc eoreq r7, r1, r8, asr #21
 *
 * ══ §20/102 F_AudioPlaySoundAt(RValue&, CInstance*, CInstance*, int, RValue*)  0x134cac  size 300  75 条（0x134cac..0x134dd8）
 * @func 0x134cac 0x134dd8  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×7 / YYGetInt32(RValue const*, int)×2 / Audio_PlaySoundAt(int, double, double, double, double, double, double, int, double)
 * 字段偏移 top8: 0x3c×2 / 0x44×2 / 0x40×2 / 0x5c×2 / 0x120×1 / 0x88×1 / 0xc×1 / 0x28×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134cac ldr r3, [pc, #0x120]
 *   @0x134cb0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x134cb4 ldr r3, [pc, r3]
 *   @0x134cb8 sub sp, sp, #100
 *   @0x134cbc mov r11, r0
 *   @0x134cc0 ldrb r1, [r3]
 *   @0x134cc4 ldr r10, [sp, #0x88]
 *   @0x134cc8 cmp r1, #0
 *   @0x134ccc bne 0x134dcc <_Z18F_AudioPlaySoundAtR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x134cd0 str r1, [r0, #0xc]
 *   @0x134cd4 mov r0, r10
 *   @0x134cd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134cdc mov r1, #1
 *   @0x134ce0 mov r12, r0
 *   @0x134ce4 mov r0, r10
 *   @0x134ce8 str r12, [sp, #0x3c]
 *   @0x134cec bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134cf0 mov r2, r0
 *   @0x134cf4 mov r3, r1
 *   @0x134cf8 mov r0, r10
 *   @0x134cfc mov r1, #2
 *   @0x134d00 str r2, [sp, #0x44]
 *   @0x134d04 str r3, [sp, #0x40]
 *   @0x134d08 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134d0c mov r8, r0
 *   @0x134d10 mov r9, r1
 *   @0x134d14 mov r0, r10
 *   @0x134d18 mov r1, #3
 *   @0x134d1c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134d20 mov r6, r0
 *   @0x134d24 mov r7, r1
 *   @0x134d28 mov r0, r10
 *   @0x134d2c mov r1, #4
 *   @0x134d30 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134d34 strd r0, r1, [sp, #72]
 *   @0x134d38 mov r0, r10
 *   @0x134d3c mov r1, #5
 *   @0x134d40 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134d44 strd r0, r1, [sp, #80]
 *   @0x134d48 mov r0, r10
 *   @0x134d4c mov r1, #6
 *   @0x134d50 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134d54 mov r4, r0
 *   @0x134d58 mov r5, r1
 *   @0x134d5c mov r0, r10
 *   @0x134d60 mov r1, #7
 *   @0x134d64 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134d68 mov r1, #8
 *   @0x134d6c str r0, [sp, #0x5c]
 *   @0x134d70 mov r0, r10
 *   @0x134d74 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134d78 ldr lr, [sp, #0x5c]
 *   @0x134d7c ldr r12, [sp, #0x3c]
 *   @0x134d80 vldr d7, [sp, #72]
 *   @0x134d84 ldr r2, [sp, #0x44]
 *   @0x134d88 vstr d7, [sp, #16]
 *   @0x134d8c ldr r3, [sp, #0x40]
 *   @0x134d90 vldr d7, [sp, #80]
 *   @0x134d94 strd r8, r9, [sp]
 *   @0x134d98 vstr d7, [sp, #24]
 *   @0x134d9c strd r6, r7, [sp, #8]
 *   @0x134da0 strd r4, r5, [sp, #32]
 *   @0x134da4 str lr, [sp, #0x28]
 *   @0x134da8 strd r0, r1, [sp, #48]
 *   @0x134dac mov r0, r12
 *   @0x134db0 bl 0x21b29c <_Z17Audio_PlaySoundAtiddddddid>
 *   @0x134db4 vmov s15, r0
 *   @0x134db8 vcvt.f64.s32 d7, s15
 *   @0x134dbc vmov r0, r1, d7
 *   @0x134dc0 vmov r2, s14
 *   @0x134dc4 mov r3, r1
 *   @0x134dc8 stm r11, {r2, r3}
 *   @0x134dcc add sp, sp, #100
 *   @0x134dd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x134dd4 mlaeq r11, r8, r3, r10
 *
 * ══ §21/102 F_YoYo_MD5Unicode(RValue&, CInstance*, CInstance*, int, RValue*)  0x157b28  size 300  75 条（0x157b28..0x157c54）
 * @func 0x157b28 0x157c54  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / 0xb6538 / F_YoYo_MD5Unicode(RValue&, CInstance*, CInstance*, int, RValue*)+0x78 / utf8_extract_char / MD5Init(MD5_CTX*) / MD5Update(MD5_CTX*, unsigned char*, unsigned int) / MD5Final(MD5_CTX*) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x-28×2 / 0x110×1 / 0x4×1 / 0x-94×1 / 0x70×1 / 0x5c×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157b28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x157b2c add r11, sp, #32
 *   @0x157b30 ldr r8, [pc, #0x110]
 *   @0x157b34 sub sp, sp, #116
 *   @0x157b38 mov r1, #0
 *   @0x157b3c ldr r8, [pc, r8]
 *   @0x157b40 mov r9, r0
 *   @0x157b44 ldr r0, [r11, #0x4]
 *   @0x157b48 ldr r3, [r8]
 *   @0x157b4c str r3, [r11, #-0x28]
 *   @0x157b50 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157b54 mov r4, r0
 *   @0x157b58 bl 0xb6538 <strlen@plt>
 *   @0x157b5c str r4, [r11, #-0x94]
 *   @0x157b60 lsl r3, r0, #1
 *   @0x157b64 cmp r0, #0
 *   @0x157b68 add r3, r3, #16
 *   @0x157b6c lsl r6, r0, #1
 *   @0x157b70 bic r3, r3, #7
 *   @0x157b74 subgt r7, r11, #148
 *   @0x157b78 sub sp, sp, r3
 *   @0x157b7c movgt r4, #0
 *   @0x157b80 mov r5, sp
 *   @0x157b84 ble 0x157ba0 <_Z17F_YoYo_MD5UnicodeR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x157b88 mov r0, r7
 *   @0x157b8c bl 0x10fb38 <utf8_extract_char>
 *   @0x157b90 strh r0, [r5, r4]
 *   @0x157b94 add r4, r4, #2
 *   @0x157b98 cmp r4, r6
 *   @0x157b9c bne 0x157b88 <_Z17F_YoYo_MD5UnicodeR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x157ba0 sub r10, r11, #144
 *   @0x157ba4 mov r3, #0
 *   @0x157ba8 strh r3, [r5, r6]
 *   @0x157bac sub r4, r11, #57
 *   @0x157bb0 mov r0, r10
 *   @0x157bb4 sub r7, r11, #41
 *   @0x157bb8 bl 0x2140d8 <_Z7MD5InitP7MD5_CTX>
 *   @0x157bbc mov r1, r5
 *   @0x157bc0 mov r2, r6
 *   @0x157bc4 mov r0, r10
 *   @0x157bc8 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj>
 *   @0x157bcc mov r0, r10
 *   @0x157bd0 bl 0x2141d0 <_Z8MD5FinalP7MD5_CTX>
 *   @0x157bd4 ldr r1, [pc, #0x70]
 *   @0x157bd8 mov r0, #33
 *   @0x157bdc movw r2, #0x977
 *   @0x157be0 add r1, pc, r1
 *   @0x157be4 mov r3, #1
 *   @0x157be8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x157bec ldr r6, [pc, #0x5c]
 *   @0x157bf0 add r6, pc, r6
 *   @0x157bf4 mov r10, r0
 *   @0x157bf8 mov r5, r0
 *   @0x157bfc ldrb r2, [r4, #0x1]!
 *   @0x157c00 mov r0, r5
 *   @0x157c04 mov r1, r6
 *   @0x157c08 add r5, r5, #2
 *   @0x157c0c bl 0xb6550 <sprintf@plt>
 *   @0x157c10 cmp r4, r7
 *   @0x157c14 bne 0x157bfc <_Z17F_YoYo_MD5UnicodeR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x157c18 mov r0, r9
 *   @0x157c1c mov r1, r10
 *   @0x157c20 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x157c24 mov r0, r10
 *   @0x157c28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x157c2c ldr r2, [r11, #-0x28]
 *   @0x157c30 ldr r3, [r8]
 *   @0x157c34 cmp r2, r3
 *   @0x157c38 bne 0x157c44 <_Z17F_YoYo_MD5UnicodeR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x157c3c sub sp, r11, #32
 *   @0x157c40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x157c44 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x157c48 eoreq r5, r9, r4, lsl lr
 *   @0x157c4c andseq lr, lr, r4, lsl #19
 *   @0x157c50 ldrheq r10, [sp], -r4
 *
 * ══ §22/102 F_YoYo_SHA1Unicode(RValue&, CInstance*, CInstance*, int, RValue*)  0x157f4c  size 300  75 条（0x157f4c..0x158078）
 * @func 0x157f4c 0x158078  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / 0xb6538 / F_YoYo_SHA1Unicode(RValue&, CInstance*, CInstance*, int, RValue*)+0x78 / utf8_extract_char / SHA1Reset(SHA1Context*) / SHA1Input(SHA1Context*, unsigned char const*, unsigned int) / SHA1Result(SHA1Context*) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×2 / 0x-28×2 / 0x110×1 / 0x-94×1 / 0x70×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157f4c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x157f50 add r11, sp, #32
 *   @0x157f54 ldr r7, [pc, #0x110]
 *   @0x157f58 sub sp, sp, #116
 *   @0x157f5c mov r1, #0
 *   @0x157f60 ldr r7, [pc, r7]
 *   @0x157f64 mov r8, r0
 *   @0x157f68 ldr r0, [r11, #0x4]
 *   @0x157f6c sub r9, r11, #148
 *   @0x157f70 ldr r3, [r7]
 *   @0x157f74 str r3, [r11, #-0x28]
 *   @0x157f78 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157f7c mov r4, r0
 *   @0x157f80 bl 0xb6538 <strlen@plt>
 *   @0x157f84 str r4, [r11, #-0x94]
 *   @0x157f88 lsl r3, r0, #1
 *   @0x157f8c cmp r0, #0
 *   @0x157f90 add r3, r3, #16
 *   @0x157f94 lsl r6, r0, #1
 *   @0x157f98 bic r3, r3, #7
 *   @0x157f9c movgt r4, #0
 *   @0x157fa0 sub sp, sp, r3
 *   @0x157fa4 mov r5, sp
 *   @0x157fa8 ble 0x157fc4 <_Z18F_YoYo_SHA1UnicodeR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x157fac mov r0, r9
 *   @0x157fb0 bl 0x10fb38 <utf8_extract_char>
 *   @0x157fb4 strh r0, [r5, r4]
 *   @0x157fb8 add r4, r4, #2
 *   @0x157fbc cmp r4, r6
 *   @0x157fc0 bne 0x157fac <_Z18F_YoYo_SHA1UnicodeR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x157fc4 sub r10, r11, #144
 *   @0x157fc8 mov r3, #0
 *   @0x157fcc strh r3, [r5, r6]
 *   @0x157fd0 mov r4, r9
 *   @0x157fd4 mov r0, r10
 *   @0x157fd8 sub r9, r11, #128
 *   @0x157fdc bl 0x214294 <_Z9SHA1ResetP11SHA1Context>
 *   @0x157fe0 mov r1, r5
 *   @0x157fe4 mov r2, r6
 *   @0x157fe8 mov r0, r10
 *   @0x157fec bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj>
 *   @0x157ff0 mov r0, r10
 *   @0x157ff4 bl 0x2146e4 <_Z10SHA1ResultP11SHA1Context>
 *   @0x157ff8 ldr r1, [pc, #0x70]
 *   @0x157ffc mov r0, #45
 *   @0x158000 movw r2, #0x9e7
 *   @0x158004 add r1, pc, r1
 *   @0x158008 mov r3, #1
 *   @0x15800c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x158010 ldr r6, [pc, #0x5c]
 *   @0x158014 add r6, pc, r6
 *   @0x158018 mov r10, r0
 *   @0x15801c mov r5, r0
 *   @0x158020 ldr r2, [r4, #0x4]!
 *   @0x158024 mov r0, r5
 *   @0x158028 mov r1, r6
 *   @0x15802c add r5, r5, #8
 *   @0x158030 bl 0xb6550 <sprintf@plt>
 *   @0x158034 cmp r4, r9
 *   @0x158038 bne 0x158020 <_Z18F_YoYo_SHA1UnicodeR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x15803c mov r0, r8
 *   @0x158040 mov r1, r10
 *   @0x158044 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x158048 mov r0, r10
 *   @0x15804c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x158050 ldr r2, [r11, #-0x28]
 *   @0x158054 ldr r3, [r7]
 *   @0x158058 cmp r2, r3
 *   @0x15805c bne 0x158068 <_Z18F_YoYo_SHA1UnicodeR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x158060 sub sp, r11, #32
 *   @0x158064 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x158068 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x15806c .word 0x002959f0
 *   @0x158070 andseq lr, lr, r0, ror #10
 *   @0x158074 mulseq sp, r8, r1
 *
 * ══ §23/102 GR_D3D_Set_Fog(bool, unsigned int, short, short)  0x168520  size 300  75 条（0x168520..0x16864c）
 * @func 0x168520 0x16864c  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x168534→0x489788, 0x168540→0x489790, 0x168544→0x48978c, 0x168550→0x3f23b8, 0x168554→0x4859c8
 * 调用序列: RenderStateManager::SetRenderState(eRenderState, unsigned int)×5 / GR_Color_To_D3DColor(unsigned int, unsigned int) / Graphics::FogType()
 * 字段偏移 top8: 0xf4×2 / 0xec×2 / 0x100×1 / 0xfc×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168520 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x168524 vpush {d8}
 *   @0x168528 vmov s15, r2
 *   @0x16852c ldr lr, [pc, #0x100]
 *   @0x168530 mov r2, r0
 *   @0x168534 ldr r6, [pc, #0xfc]
 *   @0x168538 mov r10, r1
 *   @0x16853c add lr, pc, lr
 *   @0x168540 ldr r12, [pc, #0xf4]
 *   @0x168544 ldr r0, [pc, #0xf4]
 *   @0x168548 vcvt.f32.s32 s17, s15
 *   @0x16854c mov r1, lr
 *   @0x168550 ldr r4, [pc, #0xec]
 *   @0x168554 ldr lr, [pc, #0xec]
 *   @0x168558 vmov s15, r3
 *   @0x16855c ldr r9, [r1, r6]
 *   @0x168560 ldr r5, [r1, r12]
 *   @0x168564 ldr r7, [r1, r0]
 *   @0x168568 ldr r8, [r1, r4]
 *   @0x16856c vcvt.f32.s32 s16, s15
 *   @0x168570 ldr r6, [r1, lr]
 *   @0x168574 b 0x168590 <_Z14GR_D3D_Set_Fogbjss+0x70>
 *   @0x168578 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x16857c cmp r4, #1
 *   @0x168580 mov r2, #0
 *   @0x168584 beq 0x1685e4 <_Z14GR_D3D_Set_Fogbjss+0xc4>
 *   @0x168588 cmp r4, #2
 *   @0x16858c beq 0x168610 <_Z14GR_D3D_Set_Fogbjss+0xf0>
 *   @0x168590 mov r1, #255
 *   @0x168594 mov r0, r10
 *   @0x168598 strb r2, [r5]
 *   @0x16859c bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x1685a0 vstr s17, [r9]
 *   @0x1685a4 vstr s16, [r8]
 *   @0x1685a8 str r0, [r7]
 *   @0x1685ac bl 0x17f360 <_ZN8Graphics7FogTypeEv>
 *   @0x1685b0 ldrb r3, [r5]
 *   @0x1685b4 mov r1, #13
 *   @0x1685b8 mov r2, #1
 *   @0x1685bc cmp r3, #0
 *   @0x1685c0 mov r4, r0
 *   @0x1685c4 mov r0, r6
 *   @0x1685c8 bne 0x168578 <_Z14GR_D3D_Set_Fogbjss+0x58>
 *   @0x1685cc vpop {d8}
 *   @0x1685d0 mov r0, r6
 *   @0x1685d4 mov r2, r3
 *   @0x1685d8 mov r1, #13
 *   @0x1685dc pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1685e0 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1685e4 mov r0, r6
 *   @0x1685e8 mov r1, #16
 *   @0x1685ec mov r2, #3
 *   @0x1685f0 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1685f4 mov r0, r6
 *   @0x1685f8 ldr r2, [r7]
 *   @0x1685fc mov r1, #15
 *   @0x168600 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168604 vpop {d8}
 *   @0x168608 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x16860c b 0x1684d4 <_Z16_SetFogDistancesv>
 *   @0x168610 mov r0, r6
 *   @0x168614 mov r1, #23
 *   @0x168618 mov r2, #3
 *   @0x16861c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168620 mov r0, r6
 *   @0x168624 mov r1, #20
 *   @0x168628 mov r2, #1
 *   @0x16862c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168630 b 0x1685f4 <_Z14GR_D3D_Set_Fogbjss+0xd4>
 *   @0x168634 eoreq r9, r8, r4, lsl r7
 *   @0x168638 .word 0xffffe4c8
 *   @0x16863c .word 0xffffe4c0
 *   @0x168640 .word 0xffffe4c4
 *   @0x168644 .word 0xffffe4cc
 *   @0x168648 .word 0xffffc0a8
 *
 * ══ §24/102 GR_Draw_Vertex_Texture_Color(float, float, float, float, unsigned int, float)  0x16bc84  size 300  75 条（0x16bc84..0x16bdb0）
 * @func 0x16bc84 0x16bdb0  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16bc98→0x4899b0, 0x16bccc→0x4899b4, 0x16bcd0→0x4859ac, 0x16bd00→0x490000, 0x16bd3c→0x48fffc, 0x16bd50→0x48fff8
 * 调用序列: GR_Draw_Vertex_Texture_Color(float, float, float, float, unsigned int, float)+0x3c / ConvertAlpha(float) / GR_Color_To_D3DColor(unsigned int, unsigned int)
 * 字段偏移 top8: 0xc8×2 / 0xfc×1 / 0xf8×1 / 0x24×1 / 0x4×1 / 0x8×1 / 0x20×1 / 0x9c×1
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16bc84 push {r4, r5, r6, r7, r8, lr}
 *   @0x16bc88 vpush {d8}
 *   @0x16bc8c vmov s16, r3
 *   @0x16bc90 ldr r4, [pc, #0xfc]
 *   @0x16bc94 mov r8, r0
 *   @0x16bc98 ldr r12, [pc, #0xf8]
 *   @0x16bc9c mov r7, r1
 *   @0x16bca0 add r4, pc, r4
 *   @0x16bca4 vmov s17, r2
 *   @0x16bca8 ldr r5, [r4, r12]
 *   @0x16bcac ldr r3, [r5]
 *   @0x16bcb0 cmp r3, #1000
 *   @0x16bcb4 ble 0x16bcc0 <_Z28GR_Draw_Vertex_Texture_Colorffffjf+0x3c>
 *   @0x16bcb8 vpop {d8}
 *   @0x16bcbc pop {r4, r5, r6, r7, r8, pc}
 *   @0x16bcc0 ldr r0, [sp, #0x24]
 *   @0x16bcc4 bl 0x16ca2c <_Z12ConvertAlphaf>
 *   @0x16bcc8 ldr r6, [r5]
 *   @0x16bccc ldr r2, [pc, #0xc8]
 *   @0x16bcd0 ldr r3, [pc, #0xc8]
 *   @0x16bcd4 add r6, r6, r6, lsl #1
 *   @0x16bcd8 ldr r2, [r4, r2]
 *   @0x16bcdc add r6, r2, r6, lsl #3
 *   @0x16bce0 str r8, [r6]
 *   @0x16bce4 str r7, [r6, #0x4]
 *   @0x16bce8 ldr r3, [r4, r3]
 *   @0x16bcec ldr r3, [r3]
 *   @0x16bcf0 str r3, [r6, #0x8]
 *   @0x16bcf4 mov r1, r0
 *   @0x16bcf8 ldr r0, [sp, #0x20]
 *   @0x16bcfc bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16bd00 ldr r3, [pc, #0x9c]
 *   @0x16bd04 str r0, [r6, #0xc]
 *   @0x16bd08 ldr r3, [r4, r3]
 *   @0x16bd0c ldr r3, [r3]
 *   @0x16bd10 cmp r3, #0
 *   @0x16bd14 vstreq s17, [r6, #16]
 *   @0x16bd18 vstreq s16, [r6, #20]
 *   @0x16bd1c beq 0x16bd80 <_Z28GR_Draw_Vertex_Texture_Colorffffjf+0xfc>
 *   @0x16bd20 ldrsh r1, [r3]
 *   @0x16bd24 ldrsh r2, [r3, #12]
 *   @0x16bd28 vmov s14, r1
 *   @0x16bd2c ldrsh r1, [r3, #2]
 *   @0x16bd30 vmov s11, r2
 *   @0x16bd34 ldrsh r3, [r3, #14]
 *   @0x16bd38 vcvt.f32.s32 s14, s14
 *   @0x16bd3c ldr r2, [pc, #0x64]
 *   @0x16bd40 vmov s15, r1
 *   @0x16bd44 vmov s13, r3
 *   @0x16bd48 ldr r3, [r4, r2]
 *   @0x16bd4c vldr s12, [r3]
 *   @0x16bd50 ldr r3, [pc, #0x54]
 *   @0x16bd54 vcvt.f32.s32 s11, s11
 *   @0x16bd58 vmla.f32 s14, s17, s11
 *   @0x16bd5c vdiv.f32 s14, s14, s12
 *   @0x16bd60 vcvt.f32.s32 s15, s15
 *   @0x16bd64 vstr s14, [r6, #16]
 *   @0x16bd68 ldr r3, [r4, r3]
 *   @0x16bd6c vldr s14, [r3]
 *   @0x16bd70 vcvt.f32.s32 s13, s13
 *   @0x16bd74 vmla.f32 s15, s16, s13
 *   @0x16bd78 vdiv.f32 s15, s15, s14
 *   @0x16bd7c vstr s15, [r6, #20]
 *   @0x16bd80 vpop {d8}
 *   @0x16bd84 ldr r3, [r5]
 *   @0x16bd88 add r3, r3, #1
 *   @0x16bd8c str r3, [r5]
 *   @0x16bd90 pop {r4, r5, r6, r7, r8, pc}
 *   @0x16bd94 .word 0x00285fb0
 *   @0x16bd98 .word 0xffffe534
 *   @0x16bd9c .word 0xffffe54c
 *   @0x16bda0 .word 0xffffbcd0
 *   @0x16bda4 .word 0xffffe540
 *   @0x16bda8 .word 0xffffe544
 *   @0x16bdac .word 0xffffe548
 *
 * ══ §25/102 CCameraManager::CreateCameraFromView(YYRoomView*)  0x16f108  size 300  75 条（0x16f108..0x16f234）
 * @func 0x16f108 0x16f234  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCameraManager::CreateCamera() / CCamera::SetViewX(float) / CCamera::SetViewY(float) / CCamera::SetViewWidth(float) / CCamera::SetViewHeight(float) / CCamera::SetViewSpeedX(float) / CCamera::SetViewSpeedY(float) / CCamera::SetViewBorderX(float)
 * 字段偏移 top8: 0x34×1
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f108 push {r3, r4, r5, lr}
 *   @0x16f10c vpush {d8, d9}
 *   @0x16f110 subs r5, r1, #0
 *   @0x16f114 beq 0x16f22c <_ZN14CCameraManager20CreateCameraFromViewEP10YYRoomView+0x124>
 *   @0x16f118 bl 0x16edb4 <_ZN14CCameraManager12CreateCameraEv>
 *   @0x16f11c vldr s15, [r5, #4]
 *   @0x16f120 vcvt.f32.s32 s15, s15
 *   @0x16f124 vmov r1, s15
 *   @0x16f128 vmov.f32 s17, #5.000000e-01
 *   @0x16f12c mov r4, r0
 *   @0x16f130 bl 0x16d29c <_ZN7CCamera8SetViewXEf>
 *   @0x16f134 vldr s15, [r5, #8]
 *   @0x16f138 vcvt.f32.s32 s15, s15
 *   @0x16f13c mov r0, r4
 *   @0x16f140 vmov r1, s15
 *   @0x16f144 bl 0x16d2ac <_ZN7CCamera8SetViewYEf>
 *   @0x16f148 vldr s15, [r5, #12]
 *   @0x16f14c vcvt.f32.s32 s15, s15
 *   @0x16f150 mov r0, r4
 *   @0x16f154 vmov r1, s15
 *   @0x16f158 bl 0x16d2bc <_ZN7CCamera12SetViewWidthEf>
 *   @0x16f15c vldr s15, [r5, #16]
 *   @0x16f160 vcvt.f32.s32 s15, s15
 *   @0x16f164 mov r0, r4
 *   @0x16f168 vmov r1, s15
 *   @0x16f16c bl 0x16d2cc <_ZN7CCamera13SetViewHeightEf>
 *   @0x16f170 vldr s15, [r5, #44]
 *   @0x16f174 vcvt.f32.s32 s15, s15
 *   @0x16f178 mov r0, r4
 *   @0x16f17c vmov r1, s15
 *   @0x16f180 bl 0x16d2dc <_ZN7CCamera13SetViewSpeedXEf>
 *   @0x16f184 vldr s15, [r5, #48]
 *   @0x16f188 vcvt.f32.s32 s15, s15
 *   @0x16f18c mov r0, r4
 *   @0x16f190 vmov r1, s15
 *   @0x16f194 bl 0x16d2ec <_ZN7CCamera13SetViewSpeedYEf>
 *   @0x16f198 vldr s15, [r5, #36]
 *   @0x16f19c vcvt.f32.s32 s15, s15
 *   @0x16f1a0 mov r0, r4
 *   @0x16f1a4 vmov r1, s15
 *   @0x16f1a8 bl 0x16d2fc <_ZN7CCamera14SetViewBorderXEf>
 *   @0x16f1ac vldr s15, [r5, #40]
 *   @0x16f1b0 vcvt.f32.s32 s15, s15
 *   @0x16f1b4 mov r0, r4
 *   @0x16f1b8 vmov r1, s15
 *   @0x16f1bc bl 0x16d30c <_ZN7CCamera14SetViewBorderYEf>
 *   @0x16f1c0 mov r0, r4
 *   @0x16f1c4 mov r1, #0
 *   @0x16f1c8 bl 0x16d31c <_ZN7CCamera12SetViewAngleEf>
 *   @0x16f1cc ldr r1, [r5, #0x34]
 *   @0x16f1d0 mov r0, r4
 *   @0x16f1d4 bl 0x16d32c <_ZN7CCamera17SetTargetInstanceEi>
 *   @0x16f1d8 mov r0, r4
 *   @0x16f1dc bl 0x16d2a4 <_ZN7CCamera8GetViewXEv>
 *   @0x16f1e0 vmov s16, r0
 *   @0x16f1e4 mov r0, r4
 *   @0x16f1e8 bl 0x16d2c4 <_ZN7CCamera12GetViewWidthEv>
 *   @0x16f1ec vmov s15, r0
 *   @0x16f1f0 mov r0, r4
 *   @0x16f1f4 vmla.f32 s16, s15, s17
 *   @0x16f1f8 bl 0x16d2b4 <_ZN7CCamera8GetViewYEv>
 *   @0x16f1fc vmov s18, r0
 *   @0x16f200 mov r0, r4
 *   @0x16f204 bl 0x16d2d4 <_ZN7CCamera13GetViewHeightEv>
 *   @0x16f208 vmov r1, s16
 *   @0x16f20c vmov s15, r0
 *   @0x16f210 mov r0, r4
 *   @0x16f214 vmla.f32 s18, s15, s17
 *   @0x16f218 vmov r2, s18
 *   @0x16f21c bl 0x16db44 <_ZN7CCamera11Build2DViewEff>
 *   @0x16f220 mov r0, r4
 *   @0x16f224 vpop {d8, d9}
 *   @0x16f228 pop {r3, r4, r5, pc}
 *   @0x16f22c mov r0, r5
 *   @0x16f230 b 0x16f224 <_ZN14CCameraManager20CreateCameraFromViewEP10YYRoomView+0x11c>
 *
 * ══ §26/102 GR_Surface_FreeAll()  0x171c64  size 300  75 条（0x171c64..0x171d90）
 * @func 0x171c64 0x171d90  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_FreeAll()+0x9c / _FreeSurfaceData(int) / GR_Surface_FreeAll()+0x7c / GR_Surface_FreeAll()+0x104 / operator delete(void*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×5 / 0xc×3 / 0x8×3 / 0x114×1 / 0x3×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171c64 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x171c68 mov r3, #0
 *   @0x171c6c ldr r6, [pc, #0x114]
 *   @0x171c70 ldr r6, [pc, r6]
 *   @0x171c74 ldm r6, {r2, r8}
 *   @0x171c78 b 0x171c84 <_Z18GR_Surface_FreeAllv+0x20>
 *   @0x171c7c cmp r8, r3
 *   @0x171c80 blt 0x171d00 <_Z18GR_Surface_FreeAllv+0x9c>
 *   @0x171c84 ldr r4, [r2, r3, lsl #3]
 *   @0x171c88 mov r5, r3
 *   @0x171c8c add r3, r3, #1
 *   @0x171c90 cmp r4, #0
 *   @0x171c94 beq 0x171c7c <_Z18GR_Surface_FreeAllv+0x18>
 *   @0x171c98 ldr r3, [r4, #0xc]
 *   @0x171c9c cmp r3, #0
 *   @0x171ca0 bne 0x171cb4 <_Z18GR_Surface_FreeAllv+0x50>
 *   @0x171ca4 b 0x171d00 <_Z18GR_Surface_FreeAllv+0x9c>
 *   @0x171ca8 ldr r3, [r4, #0xc]
 *   @0x171cac cmp r3, #0
 *   @0x171cb0 beq 0x171d80 <_Z18GR_Surface_FreeAllv+0x11c>
 *   @0x171cb4 ldr r0, [r3]
 *   @0x171cb8 bl 0x171a90 <_Z16_FreeSurfaceDatai>
 *   @0x171cbc ldr r4, [r4, #0x4]
 *   @0x171cc0 cmp r4, #0
 *   @0x171cc4 bne 0x171ca8 <_Z18GR_Surface_FreeAllv+0x44>
 *   @0x171cc8 ldr r8, [r6, #0x4]
 *   @0x171ccc add r3, r5, #1
 *   @0x171cd0 cmp r3, r8
 *   @0x171cd4 bgt 0x171d00 <_Z18GR_Surface_FreeAllv+0x9c>
 *   @0x171cd8 ldr r2, [r6]
 *   @0x171cdc add r2, r2, r5, lsl #3
 *   @0x171ce0 ldr r4, [r2, #0x8]
 *   @0x171ce4 mov r5, r3
 *   @0x171ce8 add r2, r2, #8
 *   @0x171cec add r3, r3, #1
 *   @0x171cf0 cmp r4, #0
 *   @0x171cf4 bne 0x171ca8 <_Z18GR_Surface_FreeAllv+0x44>
 *   @0x171cf8 cmp r3, r8
 *   @0x171cfc ble 0x171ce0 <_Z18GR_Surface_FreeAllv+0x7c>
 *   @0x171d00 cmp r8, #0
 *   @0x171d04 lslge r7, r8, #3
 *   @0x171d08 movge r9, #0
 *   @0x171d0c blt 0x171d68 <_Z18GR_Surface_FreeAllv+0x104>
 *   @0x171d10 ldr r3, [r6]
 *   @0x171d14 add r2, r3, r7
 *   @0x171d18 ldr r4, [r3, r7]
 *   @0x171d1c str r9, [r3, r7]
 *   @0x171d20 cmp r4, #0
 *   @0x171d24 str r9, [r2, #0x4]
 *   @0x171d28 beq 0x171d58 <_Z18GR_Surface_FreeAllv+0xf4>
 *   @0x171d2c ldr r5, [r4, #0x4]
 *   @0x171d30 ldr r0, [r4, #0xc]
 *   @0x171d34 bl 0x27d1d0 <_ZdlPv>
 *   @0x171d38 mov r0, r4
 *   @0x171d3c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x171d40 ldr r3, [r6, #0x8]
 *   @0x171d44 cmp r5, #0
 *   @0x171d48 mov r4, r5
 *   @0x171d4c sub r3, r3, #1
 *   @0x171d50 str r3, [r6, #0x8]
 *   @0x171d54 bne 0x171d2c <_Z18GR_Surface_FreeAllv+0xc8>
 *   @0x171d58 sub r8, r8, #1
 *   @0x171d5c sub r7, r7, #8
 *   @0x171d60 cmn r8, #1
 *   @0x171d64 bne 0x171d10 <_Z18GR_Surface_FreeAllv+0xac>
 *   @0x171d68 ldr r3, [pc, #0x1c]
 *   @0x171d6c movw r2, #0xdead
 *   @0x171d70 movt r2, #0xfeee
 *   @0x171d74 ldr r3, [pc, r3]
 *   @0x171d78 str r2, [r3]
 *   @0x171d7c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x171d80 ldr r8, [r6, #0x4]
 *   @0x171d84 b 0x171d00 <_Z18GR_Surface_FreeAllv+0x9c>
 *   @0x171d88 eoreq r11, r7, r0, lsr #29
 *   @0x171d8c eoreq r12, r7, r4, ror #16
 *
 * ══ §27/102 Graphics::SetViewPort(int, int, int, int)  0x17dfb0  size 300  75 条（0x17dfb0..0x17e0dc）
 * @func 0x17dfb0 0x17e0dc  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17dfc0→0x4a2150, 0x17dfcc→0x4a214c, 0x17dfd0→0x4a2148, 0x17dfdc→0x4a2144, 0x17dfe0→0x3f23b4, 0x17e010→0x479c74, 0x17e024→0x479c2c, 0x17e044→0x479c18
 * 调用序列: GR_Window_Get_Height()
 * 字段偏移 top8: 0xec×2 / 0xe4×2 / 0xf8×1 / 0xf4×1 / 0xb8×1 / 0xa8×1 / 0x8c×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dfb0 push {r4, r5, r6, r7, r8, lr}
 *   @0x17dfb4 mov r7, r0
 *   @0x17dfb8 ldr r4, [pc, #0xf8]
 *   @0x17dfbc mov r8, r1
 *   @0x17dfc0 ldr r0, [pc, #0xf4]
 *   @0x17dfc4 mov r6, r2
 *   @0x17dfc8 add r4, pc, r4
 *   @0x17dfcc ldr r1, [pc, #0xec]
 *   @0x17dfd0 ldr r2, [pc, #0xec]
 *   @0x17dfd4 mov r5, r3
 *   @0x17dfd8 ldr r12, [r4, r0]
 *   @0x17dfdc ldr r0, [pc, #0xe4]
 *   @0x17dfe0 ldr r3, [pc, #0xe4]
 *   @0x17dfe4 str r7, [r12]
 *   @0x17dfe8 ldr r1, [r4, r1]
 *   @0x17dfec str r8, [r1]
 *   @0x17dff0 ldr r2, [r4, r2]
 *   @0x17dff4 str r6, [r2]
 *   @0x17dff8 ldr r2, [r4, r0]
 *   @0x17dffc str r5, [r2]
 *   @0x17e000 ldr r3, [r4, r3]
 *   @0x17e004 ldr r3, [r3]
 *   @0x17e008 cmp r3, #1
 *   @0x17e00c beq 0x17e068 <_ZN8Graphics11SetViewPortEiiii+0xb8>
 *   @0x17e010 ldr r3, [pc, #0xb8]
 *   @0x17e014 movw r0, #0xc11
 *   @0x17e018 ldr r3, [r4, r3]
 *   @0x17e01c ldr r3, [r3]
 *   @0x17e020 blx r3
 *   @0x17e024 ldr r12, [pc, #0xa8]
 *   @0x17e028 mov r0, r7
 *   @0x17e02c mov r1, r8
 *   @0x17e030 mov r2, r6
 *   @0x17e034 mov r3, r5
 *   @0x17e038 ldr r12, [r4, r12]
 *   @0x17e03c ldr r12, [r12]
 *   @0x17e040 blx r12
 *   @0x17e044 ldr r12, [pc, #0x8c]
 *   @0x17e048 mov r0, r7
 *   @0x17e04c mov r1, r8
 *   @0x17e050 ldr r12, [r4, r12]
 *   @0x17e054 mov r2, r6
 *   @0x17e058 mov r3, r5
 *   @0x17e05c ldr r12, [r12]
 *   @0x17e060 blx r12
 *   @0x17e064 pop {r4, r5, r6, r7, r8, pc}
 *   @0x17e068 bl 0x17af64 <_Z20GR_Window_Get_Heightv>
 *   @0x17e06c ldr r3, [pc, #0x5c]
 *   @0x17e070 add r8, r5, r8
 *   @0x17e074 ldr r3, [r4, r3]
 *   @0x17e078 ldr r3, [r3]
 *   @0x17e07c rsb r8, r8, r0
 *   @0x17e080 movw r0, #0xc11
 *   @0x17e084 blx r3
 *   @0x17e088 ldr r12, [pc, #0x44]
 *   @0x17e08c mov r1, r8
 *   @0x17e090 mov r0, r7
 *   @0x17e094 mov r2, r6
 *   @0x17e098 mov r3, r5
 *   @0x17e09c ldr r12, [r4, r12]
 *   @0x17e0a0 ldr r12, [r12]
 *   @0x17e0a4 blx r12
 *   @0x17e0a8 ldr r12, [pc, #0x28]
 *   @0x17e0ac mov r1, r8
 *   @0x17e0b0 mov r0, r7
 *   @0x17e0b4 b 0x17e050 <_ZN8Graphics11SetViewPortEiiii+0xa0>
 *   @0x17e0b8 eoreq r3, r7, r8, lsl #25
 *   @0x17e0bc .word 0xffffe80c
 *   @0x17e0c0 .word 0xffffe810
 *   @0x17e0c4 .word 0xffffe814
 *   @0x17e0c8 .word 0xffffe818
 *   @0x17e0cc .word 0xffffe48c
 *   @0x17e0d0 .word 0xffffbad8
 *   @0x17e0d4 .word 0xffffbae4
 *   @0x17e0d8 .word 0xffffbaf0
 *
 * ══ §28/102 F_DrawTile(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b68c8  size 300  75 条（0x1b68c8..0x1b69f4）
 * @func 0x1b68c8 0x1b69f4  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1b6948→0x3eb70c, 0x1b6998→0x5425c0, 0x1b69d0→0x3eb70c
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetFloat(RValue const*, int)×2 / Background_Data(int) / F_DrawTile(RValue&, CInstance*, CInstance*, int, RValue*)+0xa4 / DrawTile(tagYYRECT*, CBackground*, unsigned int, int, float, float, float)
 * 字段偏移 top8: 0xc×2 / 0x98×2 / 0x100×1 / 0x30×1 / 0xdc×1 / 0x34×1 / 0x4c×1 / 0x180×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b68c8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1b68cc cmp r3, #5
 *   @0x1b68d0 sub sp, sp, #16
 *   @0x1b68d4 ldr r4, [pc, #0x100]
 *   @0x1b68d8 mov r2, #0
 *   @0x1b68dc mov r6, r1
 *   @0x1b68e0 add r4, pc, r4
 *   @0x1b68e4 mov r1, r2
 *   @0x1b68e8 movt r2, #0xbff0
 *   @0x1b68ec str r1, [r0, #0xc]
 *   @0x1b68f0 stm r0, {r1, r2}
 *   @0x1b68f4 ldr r5, [sp, #0x30]
 *   @0x1b68f8 beq 0x1b6910 <_Z10F_DrawTileR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1b68fc ldr r0, [pc, #0xdc]
 *   @0x1b6900 add r0, pc, r0
 *   @0x1b6904 add sp, sp, #16
 *   @0x1b6908 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1b690c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b6910 mov r0, r5
 *   @0x1b6914 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b6918 bl 0xc3794 <_Z15Background_Datai>
 *   @0x1b691c subs r7, r0, #0
 *   @0x1b6920 beq 0x1b69cc <_Z10F_DrawTileR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x1b6924 mov r0, r5
 *   @0x1b6928 mov r1, #1
 *   @0x1b692c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b6930 ldr r3, [r7, #0x34]
 *   @0x1b6934 ubfx r2, r0, #0x0, #0x13
 *   @0x1b6938 mov r8, r0
 *   @0x1b693c cmp r2, r3
 *   @0x1b6940 blt 0x1b696c <_Z10F_DrawTileR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x1b6944 ldr r1, [pc, #0x98]
 *   @0x1b6948 ldr r3, [pc, #0x98]
 *   @0x1b694c add r1, pc, r1
 *   @0x1b6950 ldr r3, [r4, r3]
 *   @0x1b6954 ldr r0, [r3]
 *   @0x1b6958 ldr r3, [r0]
 *   @0x1b695c ldr r3, [r3, #0xc]
 *   @0x1b6960 blx r3
 *   @0x1b6964 add sp, sp, #16
 *   @0x1b6968 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b696c mov r0, r5
 *   @0x1b6970 mov r1, #2
 *   @0x1b6974 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b6978 mov r1, #3
 *   @0x1b697c mov r10, r0
 *   @0x1b6980 mov r0, r5
 *   @0x1b6984 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1b6988 mov r1, #4
 *   @0x1b698c mov r9, r0
 *   @0x1b6990 mov r0, r5
 *   @0x1b6994 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1b6998 ldr r12, [pc, #0x4c]
 *   @0x1b699c ldr lr, [r6, #0x180]
 *   @0x1b69a0 mov r3, r10
 *   @0x1b69a4 mov r1, r7
 *   @0x1b69a8 mov r2, r8
 *   @0x1b69ac ldr r12, [r4, r12]
 *   @0x1b69b0 str r9, [sp]
 *   @0x1b69b4 str lr, [sp, #0x8]
 *   @0x1b69b8 str r0, [sp, #0x4]
 *   @0x1b69bc mov r0, r12
 *   @0x1b69c0 bl 0x1b1d08 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff>
 *   @0x1b69c4 add sp, sp, #16
 *   @0x1b69c8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b69cc ldr r1, [pc, #0x1c]
 *   @0x1b69d0 ldr r3, [pc, #0x10]
 *   @0x1b69d4 add r1, pc, r1
 *   @0x1b69d8 b 0x1b6950 <_Z10F_DrawTileR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1b69dc eoreq r11, r3, r0, ror r3
 *   @0x1b69e0 andseq r6, r9, r8, lsl #26
 *   @0x1b69e4 andseq r6, r9, r4, lsl sp
 *   @0x1b69e8 .word 0xffffbac4
 *   @0x1b69ec .word 0xffffe4fc
 *   @0x1b69f0 andseq r6, r9, r12, asr r12
 *
 * ══ §29/102 F_TilemapGet(RValue&, CInstance*, CInstance*, int, RValue*)  0x1be70c  size 300  75 条（0x1be70c..0x1be838）
 * @func 0x1be70c 0x1be838  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×2 / 0xa0×2 / 0x34×2 / 0x4×1 / 0x18×1 / 0xe8×1 / 0x28×1 / 0x2c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1be70c cmp r3, #3
 *   @0x1be710 push {r3, r4, r5, r6, r7, lr}
 *   @0x1be714 mov r3, #0
 *   @0x1be718 mov r4, r3
 *   @0x1be71c mov r5, r0
 *   @0x1be720 movt r3, #0xbff0
 *   @0x1be724 str r4, [r0, #0xc]
 *   @0x1be728 str r3, [r0, #0x4]
 *   @0x1be72c str r4, [r0]
 *   @0x1be730 ldr r6, [sp, #0x18]
 *   @0x1be734 beq 0x1be74c <_Z12F_TilemapGetR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1be738 ldr r0, [pc, #0xe8]
 *   @0x1be73c mov r1, r4
 *   @0x1be740 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1be744 add r0, pc, r0
 *   @0x1be748 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be74c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1be750 mov r1, r4
 *   @0x1be754 mov r7, r0
 *   @0x1be758 mov r0, r6
 *   @0x1be75c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be760 mov r2, r4
 *   @0x1be764 mov r1, r0
 *   @0x1be768 mov r0, r7
 *   @0x1be76c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1be770 subs r4, r0, #0
 *   @0x1be774 beq 0x1be784 <_Z12F_TilemapGetR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1be778 ldr r3, [r4]
 *   @0x1be77c cmp r3, #5
 *   @0x1be780 beq 0x1be7a8 <_Z12F_TilemapGetR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1be784 ldr r3, [pc, #0xa0]
 *   @0x1be788 ldr r1, [pc, #0xa0]
 *   @0x1be78c ldr r3, [pc, r3]
 *   @0x1be790 add r1, pc, r1
 *   @0x1be794 ldr r0, [r3]
 *   @0x1be798 ldr r3, [r0]
 *   @0x1be79c ldr r3, [r3, #0xc]
 *   @0x1be7a0 blx r3
 *   @0x1be7a4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1be7a8 ldr r1, [r4, #0x34]
 *   @0x1be7ac cmp r1, #0
 *   @0x1be7b0 beq 0x1be818 <_Z12F_TilemapGetR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x1be7b4 mov r1, #1
 *   @0x1be7b8 mov r0, r6
 *   @0x1be7bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be7c0 mov r1, #2
 *   @0x1be7c4 mov r7, r0
 *   @0x1be7c8 mov r0, r6
 *   @0x1be7cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be7d0 cmp r7, #0
 *   @0x1be7d4 poplt {r3, r4, r5, r6, r7, pc}
 *   @0x1be7d8 ldr r3, [r4, #0x28]
 *   @0x1be7dc cmp r7, r3
 *   @0x1be7e0 popge {r3, r4, r5, r6, r7, pc}
 *   @0x1be7e4 cmp r0, #0
 *   @0x1be7e8 poplt {r3, r4, r5, r6, r7, pc}
 *   @0x1be7ec ldr r2, [r4, #0x2c]
 *   @0x1be7f0 cmp r0, r2
 *   @0x1be7f4 popge {r3, r4, r5, r6, r7, pc}
 *   @0x1be7f8 mla r3, r3, r0, r7
 *   @0x1be7fc ldr r2, [r4, #0x34]
 *   @0x1be800 ldr r2, [r2, r3, lsl #2]
 *   @0x1be804 vmov s15, r2
 *   @0x1be808 vcvt.f64.u32 d7, s15
 *   @0x1be80c vmov r2, r3, d7
 *   @0x1be810 stm r5, {r2, r3}
 *   @0x1be814 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1be818 ldr r0, [pc, #0x14]
 *   @0x1be81c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1be820 add r0, pc, r0
 *   @0x1be824 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be828 andseq r0, r9, r4, lsl #9
 *   @0x1be82c eoreq lr, r2, r8, lsl #31
 *   @0x1be830 mulseq r9, r0, r4
 *   @0x1be834 ldrsbeq r0, [r9], -r4
 *
 * ══ §30/102 OLD_VARI_Load(unsigned char*, unsigned int, unsigned char*)  0x1dc960  size 300  75 条（0x1dc960..0x1dca8c）
 * @func 0x1dc960 0x1dca8c  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Variable_Find(char const*) / OLD_VARI_Load(unsigned char*, unsigned int, unsigned char*)+0xd4 / OLD_VARI_Load(unsigned char*, unsigned int, unsigned char*)+0xac / 0xb65c8 / Error_Show(char const*, bool) / YYGML_game_end() / 0xb65d4 / 0xb6688
 * 字段偏移 top8: 0x404×2 / 0x10c×1 / 0x108×1 / 0x4×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc960 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1dc964 sub sp, sp, #1024
 *   @0x1dc968 ldr r8, [pc, #0x10c]
 *   @0x1dc96c sub sp, sp, #12
 *   @0x1dc970 ldr r9, [pc, #0x108]
 *   @0x1dc974 subs r10, r1, #0
 *   @0x1dc978 ldr r8, [pc, r8]
 *   @0x1dc97c add r7, sp, #4
 *   @0x1dc980 add r9, pc, r9
 *   @0x1dc984 mov r6, r0
 *   @0x1dc988 ldr r3, [r8]
 *   @0x1dc98c mov r5, r2
 *   @0x1dc990 str r3, [sp, #0x404]
 *   @0x1dc994 beq 0x1dca14 <_Z13OLD_VARI_LoadPhjS_+0xb4>
 *   @0x1dc998 ldr r0, [r6]
 *   @0x1dc99c cmp r0, #0
 *   @0x1dc9a0 moveq r11, r0
 *   @0x1dc9a4 ldrne r3, [pc, #0xd8]
 *   @0x1dc9a8 ldrne r3, [pc, r3]
 *   @0x1dc9ac ldrne r11, [r3]
 *   @0x1dc9b0 addne r11, r11, r0
 *   @0x1dc9b4 mov r0, r11
 *   @0x1dc9b8 bl 0xd1d60 <_Z18Code_Variable_FindPKc>
 *   @0x1dc9bc subs r4, r0, #0
 *   @0x1dc9c0 blt 0x1dca34 <_Z13OLD_VARI_LoadPhjS_+0xd4>
 *   @0x1dc9c4 ldr r11, [r6, #0x4]
 *   @0x1dc9c8 sub r10, r10, #12
 *   @0x1dc9cc ldr r3, [r6, #0x8]
 *   @0x1dc9d0 add r6, r6, #12
 *   @0x1dc9d4 cmp r11, #0
 *   @0x1dc9d8 bicgt r0, r4, #-268435456
 *   @0x1dc9dc movgt r12, #0
 *   @0x1dc9e0 ble 0x1dca0c <_Z13OLD_VARI_LoadPhjS_+0xac>
 *   @0x1dc9e4 add r4, r3, #4
 *   @0x1dc9e8 add r12, r12, #1
 *   @0x1dc9ec cmp r12, r11
 *   @0x1dc9f0 ldr r2, [r5, r4]
 *   @0x1dc9f4 and r1, r2, #-268435456
 *   @0x1dc9f8 sbfx r2, r2, #0x0, #0x1d
 *   @0x1dc9fc orr r1, r1, r0
 *   @0x1dca00 add r3, r3, r2
 *   @0x1dca04 str r1, [r5, r4]
 *   @0x1dca08 bne 0x1dc9e4 <_Z13OLD_VARI_LoadPhjS_+0x84>
 *   @0x1dca0c cmp r10, #0
 *   @0x1dca10 bne 0x1dc998 <_Z13OLD_VARI_LoadPhjS_+0x38>
 *   @0x1dca14 ldr r2, [sp, #0x404]
 *   @0x1dca18 mov r0, #1
 *   @0x1dca1c ldr r3, [r8]
 *   @0x1dca20 cmp r2, r3
 *   @0x1dca24 bne 0x1dca70 <_Z13OLD_VARI_LoadPhjS_+0x110>
 *   @0x1dca28 add sp, sp, #1024
 *   @0x1dca2c add sp, sp, #12
 *   @0x1dca30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1dca34 mov r3, r11
 *   @0x1dca38 mov r1, #1024
 *   @0x1dca3c mov r2, r9
 *   @0x1dca40 mov r0, r7
 *   @0x1dca44 bl 0xb65c8 <snprintf@plt>
 *   @0x1dca48 mov r0, r7
 *   @0x1dca4c mov r1, #1
 *   @0x1dca50 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1dca54 ldr r3, [pc, #0x2c]
 *   @0x1dca58 ldr r3, [pc, r3]
 *   @0x1dca5c ldrb r3, [r3]
 *   @0x1dca60 cmp r3, #0
 *   @0x1dca64 beq 0x1dca74 <_Z13OLD_VARI_LoadPhjS_+0x114>
 *   @0x1dca68 bl 0x10c320 <_Z14YYGML_game_endv>
 *   @0x1dca6c b 0x1dc9c4 <_Z13OLD_VARI_LoadPhjS_+0x64>
 *   @0x1dca70 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1dca74 mov r0, #1
 *   @0x1dca78 bl 0xb6688 <exit@plt>
 *   @0x1dca7c .word 0x00210fd8
 *   @0x1dca80 andseq r4, r7, r4, lsl sp
 *   @0x1dca84 mlaeq r1, r12, pc, r0
 *   @0x1dca88 .word 0x002111d8
 *
 * ══ §31/102 OpenAL_PlayMP3(char const*, bool)  0x223098  size 300  75 条（0x223098..0x2231c4）
 * @func 0x223098 0x2231c4  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x223160→0x756d44, 0x223168→0x756c8c
 * 调用序列: getJNIEnv×2 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...) / 0xb65d4
 * 字段偏移 top8: 0x40c×2 / 0x108×1 / 0x104×1 / 0xe0×1 / 0x1×1 / 0x2×1 / 0x-1×1 / 0x29c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223098 push {r4, r5, r6, r7, lr}
 *   @0x22309c sub sp, sp, #1040
 *   @0x2230a0 ldr r5, [pc, #0x108]
 *   @0x2230a4 sub sp, sp, #4
 *   @0x2230a8 ldr r2, [pc, #0x104]
 *   @0x2230ac mov r6, r1
 *   @0x2230b0 add r5, pc, r5
 *   @0x2230b4 ldrb r3, [r0]
 *   @0x2230b8 ldr r4, [r5, r2]
 *   @0x2230bc cmp r3, #46
 *   @0x2230c0 cmpne r3, #0
 *   @0x2230c4 ldr r2, [r4]
 *   @0x2230c8 str r2, [sp, #0x40c]
 *   @0x2230cc beq 0x2231a0 <_Z14OpenAL_PlayMP3PKcb+0x108>
 *   @0x2230d0 ldr r1, [pc, #0xe0]
 *   @0x2230d4 add r2, sp, #13
 *   @0x2230d8 mov r7, #95
 *   @0x2230dc ldr r1, [r5, r1]
 *   @0x2230e0 ldr r1, [r1]
 *   @0x2230e4 b 0x223114 <_Z14OpenAL_PlayMP3PKcb+0x7c>
 *   @0x2230e8 cmp r3, #95
 *   @0x2230ec beq 0x223130 <_Z14OpenAL_PlayMP3PKcb+0x98>
 *   @0x2230f0 cmp r3, #36
 *   @0x2230f4 strbne r7, [r2, #-0x1]
 *   @0x2230f8 beq 0x223130 <_Z14OpenAL_PlayMP3PKcb+0x98>
 *   @0x2230fc ldrb r3, [r0, #0x1]!
 *   @0x223100 mov r12, r2
 *   @0x223104 add r2, r2, #1
 *   @0x223108 cmp r3, #0
 *   @0x22310c cmpne r3, #46
 *   @0x223110 beq 0x223138 <_Z14OpenAL_PlayMP3PKcb+0xa0>
 *   @0x223114 add r3, r1, r3, lsl #1
 *   @0x223118 ldrb r3, [r3, #0x2]
 *   @0x22311c sub lr, r3, #48
 *   @0x223120 sub r12, r3, #97
 *   @0x223124 cmp lr, #9
 *   @0x223128 cmphi r12, #25
 *   @0x22312c bhi 0x2230e8 <_Z14OpenAL_PlayMP3PKcb+0x50>
 *   @0x223130 strb r3, [r2, #-0x1]
 *   @0x223134 b 0x2230fc <_Z14OpenAL_PlayMP3PKcb+0x64>
 *   @0x223138 add r7, sp, #12
 *   @0x22313c mov r3, #0
 *   @0x223140 strb r3, [r12]
 *   @0x223144 bl 0x290274 <getJNIEnv>
 *   @0x223148 mov r1, r7
 *   @0x22314c ldr r3, [r0]
 *   @0x223150 ldr r3, [r3, #0x29c]
 *   @0x223154 blx r3
 *   @0x223158 mov r7, r0
 *   @0x22315c bl 0x290274 <getJNIEnv>
 *   @0x223160 ldr r1, [pc, #0x54]
 *   @0x223164 mov r3, r7
 *   @0x223168 ldr r2, [pc, #0x50]
 *   @0x22316c ldr r1, [r5, r1]
 *   @0x223170 ldr r2, [r5, r2]
 *   @0x223174 str r6, [sp]
 *   @0x223178 ldr r1, [r1]
 *   @0x22317c ldr r2, [r2]
 *   @0x223180 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x223184 ldr r2, [sp, #0x40c]
 *   @0x223188 ldr r3, [r4]
 *   @0x22318c cmp r2, r3
 *   @0x223190 bne 0x2231ac <_Z14OpenAL_PlayMP3PKcb+0x114>
 *   @0x223194 add sp, sp, #1040
 *   @0x223198 add sp, sp, #4
 *   @0x22319c pop {r4, r5, r6, r7, pc}
 *   @0x2231a0 add r7, sp, #12
 *   @0x2231a4 mov r12, r7
 *   @0x2231a8 b 0x22313c <_Z14OpenAL_PlayMP3PKcb+0xa4>
 *   @0x2231ac bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2231b0 andseq lr, r12, r0, lsr #23
 *   @0x2231b4 .word 0xffffbd00
 *   @0x2231b8 .word 0xffffbd34
 *   @0x2231bc .word 0xffffbd54
 *   @0x2231c0 .word 0xfffff80c
 *
 * ══ §32/102 IniFile::GetSection()  0x2355e4  size 300  75 条（0x2355e4..0x235710）
 * @func 0x2355e4 0x235710  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IniFile::SkipWhiteSpace() / operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc
 * 字段偏移 top8: 0xc×6 / 0x8×3 / 0x10×2 / 0x4×2 / 0x1×1 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2355e4 push {r4, r5, r6, r7, r8, lr}
 *   @0x2355e8 mov r4, r0
 *   @0x2355ec bl 0x235578 <_ZN7IniFile14SkipWhiteSpaceEv>
 *   @0x2355f0 ldr r0, [r4, #0x10]
 *   @0x2355f4 ldr r3, [r4, #0xc]
 *   @0x2355f8 ldr r6, [r4, #0x4]
 *   @0x2355fc add r2, r0, r3
 *   @0x235600 ldrb r1, [r0, r3]
 *   @0x235604 cmp r1, #91
 *   @0x235608 beq 0x23563c <_ZN7IniFile10GetSectionEv+0x58>
 *   @0x23560c cmp r3, r6
 *   @0x235610 bge 0x2356fc <_ZN7IniFile10GetSectionEv+0x118>
 *   @0x235614 add r5, r6, r0
 *   @0x235618 rsb r12, r0, #1
 *   @0x23561c b 0x235628 <_ZN7IniFile10GetSectionEv+0x44>
 *   @0x235620 cmp r2, r5
 *   @0x235624 beq 0x2356fc <_ZN7IniFile10GetSectionEv+0x118>
 *   @0x235628 add r3, r12, r2
 *   @0x23562c str r3, [r4, #0xc]
 *   @0x235630 ldrb r1, [r2, #0x1]!
 *   @0x235634 cmp r1, #91
 *   @0x235638 bne 0x235620 <_ZN7IniFile10GetSectionEv+0x3c>
 *   @0x23563c cmp r3, r6
 *   @0x235640 bge 0x2356fc <_ZN7IniFile10GetSectionEv+0x118>
 *   @0x235644 add r7, r3, #1
 *   @0x235648 str r7, [r4, #0xc]
 *   @0x23564c ldrb r2, [r0, r7]
 *   @0x235650 cmp r2, #93
 *   @0x235654 beq 0x235704 <_ZN7IniFile10GetSectionEv+0x120>
 *   @0x235658 cmp r7, r6
 *   @0x23565c bge 0x2356fc <_ZN7IniFile10GetSectionEv+0x118>
 *   @0x235660 add r3, r3, #2
 *   @0x235664 add r5, r6, #1
 *   @0x235668 b 0x235674 <_ZN7IniFile10GetSectionEv+0x90>
 *   @0x23566c cmp r3, r5
 *   @0x235670 beq 0x2356fc <_ZN7IniFile10GetSectionEv+0x118>
 *   @0x235674 str r3, [r4, #0xc]
 *   @0x235678 mov r12, r3
 *   @0x23567c ldrb r2, [r0, r3]
 *   @0x235680 add r3, r3, #1
 *   @0x235684 cmp r2, #93
 *   @0x235688 bne 0x23566c <_ZN7IniFile10GetSectionEv+0x88>
 *   @0x23568c cmp r12, r6
 *   @0x235690 bge 0x2356fc <_ZN7IniFile10GetSectionEv+0x118>
 *   @0x235694 mov r0, #12
 *   @0x235698 rsb r8, r7, r12
 *   @0x23569c bl 0x27c524 <_Znwj>
 *   @0x2356a0 ldr r1, [pc, #0x64]
 *   @0x2356a4 mov r6, #0
 *   @0x2356a8 mov r3, #1
 *   @0x2356ac mov r2, #253
 *   @0x2356b0 add r1, pc, r1
 *   @0x2356b4 mov r5, r0
 *   @0x2356b8 add r0, r8, #1
 *   @0x2356bc str r6, [r5]
 *   @0x2356c0 str r6, [r5, #0x4]
 *   @0x2356c4 str r6, [r5, #0x8]
 *   @0x2356c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2356cc ldr r1, [r4, #0x10]
 *   @0x2356d0 mov r2, r8
 *   @0x2356d4 add r1, r1, r7
 *   @0x2356d8 str r0, [r5, #0x8]
 *   @0x2356dc bl 0xb65bc <memcpy@plt>
 *   @0x2356e0 ldr r3, [r5, #0x8]
 *   @0x2356e4 mov r0, r5
 *   @0x2356e8 strb r6, [r3, r8]
 *   @0x2356ec ldr r3, [r4, #0xc]
 *   @0x2356f0 add r3, r3, #1
 *   @0x2356f4 str r3, [r4, #0xc]
 *   @0x2356f8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2356fc mov r0, #0
 *   @0x235700 pop {r4, r5, r6, r7, r8, pc}
 *   @0x235704 mov r12, r7
 *   @0x235708 b 0x23568c <_ZN7IniFile10GetSectionEv+0xa8>
 *   @0x23570c andseq pc, r1, r4, lsr r10
 *
 * ══ §33/102 CPhysicsWorld::CreateWheelJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, bool, float, float, float, float, bool)  0x239444  size 300  75 条（0x239444..0x239570）
 * @func 0x239444 0x239570  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2WheelJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&, b2Vec2 const&) / CPhysicsJointFactory::CreateJoint(CPhysicsWorld*, b2JointDef const&)
 * 字段偏移 top8: 0x4×2 / 0x28×2 / 0x44×2 / 0x48×2 / 0x4c×2 / 0x54×2 / 0x50×2 / 0x84×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239444 vmov s14, r3
 *   @0x239448 ldr r1, [r1]
 *   @0x23944c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x239450 mov r4, r0
 *   @0x239454 vldr s15, [r4, #96]
 *   @0x239458 sub sp, sp, #92
 *   @0x23945c vmul.f32 s14, s15, s14
 *   @0x239460 vldr s13, [sp, #128]
 *   @0x239464 ldrh r3, [r1, #4]
 *   @0x239468 ldr r2, [r2]
 *   @0x23946c add r5, sp, #24
 *   @0x239470 tst r3, #2
 *   @0x239474 ldr lr, [sp, #0x84]
 *   @0x239478 orreq r3, r3, #2
 *   @0x23947c strheq r3, [r1, #4]
 *   @0x239480 ldrh r3, [r2, #4]
 *   @0x239484 moveq r0, #0
 *   @0x239488 ldr r12, [sp, #0x88]
 *   @0x23948c streq r0, [r1, #0xa0]
 *   @0x239490 tst r3, #2
 *   @0x239494 ldrb r7, [sp, #0x8c]
 *   @0x239498 orreq r3, r3, #2
 *   @0x23949c ldr r11, [sp, #0x90]
 *   @0x2394a0 moveq r0, #0
 *   @0x2394a4 ldr r10, [sp, #0x94]
 *   @0x2394a8 ldr r9, [sp, #0x98]
 *   @0x2394ac vmul.f32 s15, s15, s13
 *   @0x2394b0 ldr r8, [sp, #0x9c]
 *   @0x2394b4 ldrb r6, [sp, #0xa0]
 *   @0x2394b8 vstr s14, [sp, #8]
 *   @0x2394bc strheq r3, [r2, #4]
 *   @0x2394c0 add r3, sp, #16
 *   @0x2394c4 streq r0, [r2, #0xa0]
 *   @0x2394c8 mov r0, r5
 *   @0x2394cc str r3, [sp]
 *   @0x2394d0 add r3, sp, #8
 *   @0x2394d4 str lr, [sp, #0x10]
 *   @0x2394d8 mov lr, #1065353216
 *   @0x2394dc str r12, [sp, #0x14]
 *   @0x2394e0 mov r12, #0
 *   @0x2394e4 str r12, [sp, #0x1c]
 *   @0x2394e8 str r12, [sp, #0x20]
 *   @0x2394ec str r12, [sp, #0x24]
 *   @0x2394f0 strb r12, [sp, #0x28]
 *   @0x2394f4 strb r12, [sp, #0x44]
 *   @0x2394f8 mov r12, #7
 *   @0x2394fc str r12, [sp, #0x18]
 *   @0x239500 mov r12, #0
 *   @0x239504 str r12, [sp, #0x2c]
 *   @0x239508 str r12, [sp, #0x30]
 *   @0x23950c str r12, [sp, #0x34]
 *   @0x239510 str r12, [sp, #0x38]
 *   @0x239514 str r12, [sp, #0x40]
 *   @0x239518 vstr s15, [sp, #12]
 *   @0x23951c str r12, [sp, #0x48]
 *   @0x239520 str r12, [sp, #0x4c]
 *   @0x239524 movw r12, #0x3333
 *   @0x239528 str lr, [sp, #0x3c]
 *   @0x23952c movt r12, #0x3f33
 *   @0x239530 str r12, [sp, #0x54]
 *   @0x239534 mov r12, #1073741824
 *   @0x239538 str r12, [sp, #0x50]
 *   @0x23953c bl 0x2d4170 <_ZN15b2WheelJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_>
 *   @0x239540 mov r1, r5
 *   @0x239544 mov r0, r4
 *   @0x239548 strb r7, [sp, #0x44]
 *   @0x23954c str r11, [sp, #0x48]
 *   @0x239550 str r10, [sp, #0x4c]
 *   @0x239554 str r9, [sp, #0x50]
 *   @0x239558 str r8, [sp, #0x54]
 *   @0x23955c strb r6, [sp, #0x28]
 *   @0x239560 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef>
 *   @0x239564 ldr r0, [r0, #0x8]
 *   @0x239568 add sp, sp, #92
 *   @0x23956c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §34/102 JS_JSON_parse(RValue&, CInstance*, CInstance*, int, RValue*)  0x25a3ec  size 300  75 条（0x25a3ec..0x25a518）
 * @func 0x25a3ec 0x25a518  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JSThrowSyntaxError(char const*)×2 / F_JS_ToString(RValue&, RValue*) / 0xb6538 / json_tokener_new / json_tokener_parse_ex / JS_JSON_parse(RValue&, CInstance*, CInstance*, int, RValue*)+0xd0 / 0xb6550 / json_tokener_free
 * 字段偏移 top8: 0x4×2 / 0x414×2 / 0x18×2 / 0x10c×1 / 0x430×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25a3ec push {r4, r5, r6, r7, r8, lr}
 *   @0x25a3f0 sub sp, sp, #1040
 *   @0x25a3f4 ldr r4, [pc, #0x10c]
 *   @0x25a3f8 sub sp, sp, #8
 *   @0x25a3fc mov r5, r0
 *   @0x25a400 add r0, sp, #4
 *   @0x25a404 ldr r4, [pc, r4]
 *   @0x25a408 ldr r1, [sp, #0x430]
 *   @0x25a40c mov r3, #0
 *   @0x25a410 mvn r2, #-16777216
 *   @0x25a414 ldr r12, [r4]
 *   @0x25a418 str r3, [sp, #0x4]
 *   @0x25a41c str r3, [sp, #0x8]
 *   @0x25a420 str r12, [sp, #0x414]
 *   @0x25a424 str r3, [sp, #0xc]
 *   @0x25a428 str r2, [sp, #0x10]
 *   @0x25a42c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x25a430 cmp r0, #2
 *   @0x25a434 beq 0x25a4a0 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x25a438 cmp r0, #1
 *   @0x25a43c beq 0x25a4e4 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x25a440 ldr r3, [sp, #0x4]
 *   @0x25a444 ldr r8, [r3]
 *   @0x25a448 mov r0, r8
 *   @0x25a44c bl 0xb6538 <strlen@plt>
 *   @0x25a450 mov r7, r0
 *   @0x25a454 bl 0x27eff0 <json_tokener_new>
 *   @0x25a458 mov r1, r8
 *   @0x25a45c mov r2, r7
 *   @0x25a460 mov r6, r0
 *   @0x25a464 bl 0x27f048 <json_tokener_parse_ex>
 *   @0x25a468 ldr r3, [r6, #0x18]
 *   @0x25a46c ldr r2, [r6, #0x14]
 *   @0x25a470 cmp r3, #0
 *   @0x25a474 mov r8, r0
 *   @0x25a478 rsbne r8, r3, #0
 *   @0x25a47c cmp r7, r2
 *   @0x25a480 ble 0x25a4bc <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x25a484 add r5, sp, #20
 *   @0x25a488 ldr r1, [pc, #0x7c]
 *   @0x25a48c mov r0, r5
 *   @0x25a490 add r1, pc, r1
 *   @0x25a494 bl 0xb6550 <sprintf@plt>
 *   @0x25a498 mov r0, r5
 *   @0x25a49c bl 0x253d88 <_Z18JSThrowSyntaxErrorPKc>
 *   @0x25a4a0 ldr r2, [sp, #0x414]
 *   @0x25a4a4 ldr r3, [r4]
 *   @0x25a4a8 cmp r2, r3
 *   @0x25a4ac bne 0x25a504 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x25a4b0 add sp, sp, #1040
 *   @0x25a4b4 add sp, sp, #8
 *   @0x25a4b8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x25a4bc mov r0, r6
 *   @0x25a4c0 bl 0x27f020 <json_tokener_free>
 *   @0x25a4c4 cmn r8, #4000
 *   @0x25a4c8 bhi 0x25a4f4 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x25a4cc mov r0, r8
 *   @0x25a4d0 mov r1, r5
 *   @0x25a4d4 bl 0x24beac <_Z10json_parseP11json_objectR6RValue>
 *   @0x25a4d8 mov r0, r8
 *   @0x25a4dc bl 0x27e7c8 <json_object_put>
 *   @0x25a4e0 b 0x25a4a0 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x25a4e4 ldr r0, [pc, #0x24]
 *   @0x25a4e8 add r0, pc, r0
 *   @0x25a4ec bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25a4f0 b 0x25a4a0 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x25a4f4 ldr r0, [pc, #0x18]
 *   @0x25a4f8 add r0, pc, r0
 *   @0x25a4fc bl 0x253d88 <_Z18JSThrowSyntaxErrorPKc>
 *   @0x25a500 b 0x25a4a0 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x25a504 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x25a508 andseq r3, r9, r12, asr #10
 *   @0x25a50c andeq r12, pc, r4, asr #17
 *   @0x25a510 andeq r12, pc, r12, lsr #16
 *   @0x25a514 andeq r12, pc, r0, lsr #17
 *
 * ══ §35/102 Java_com_yoyogames_runner_RunnerJNILib_callreward  0x2943ec  size 300  75 条（0x2943ec..0x294518）
 * @func 0x2943ec 0x294518  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / getJNIEnv / YYSetString(RValue*, char const*) / Script_Perform(int, CInstance*, CInstance*, int, RValue*, DynamicArrayOfRValue*) / Error_Show_Action(char const*, bool) / 0xb65d4
 * 字段偏移 top8: 0x4×2 / 0x-40×2 / 0x-20×2 / 0x110×1 / 0x-38×1 / 0x14×1 / 0x-34×1 / 0x2a4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2943ec push {r4, r5, r6, r7, r8, r9, r11, lr}
 *   @0x2943f0 add r11, sp, #28
 *   @0x2943f4 ldr r4, [pc, #0x110]
 *   @0x2943f8 sub sp, sp, #48
 *   @0x2943fc mov r8, r2
 *   @0x294400 ldr r4, [pc, r4]
 *   @0x294404 ldr r6, [r11, #0x4]
 *   @0x294408 mov r9, r0
 *   @0x29440c mov r7, #0
 *   @0x294410 ldr r2, [r4]
 *   @0x294414 str r3, [r11, #-0x40]
 *   @0x294418 str r2, [r11, #-0x20]
 *   @0x29441c bl 0x290614 <setJNIEnv>
 *   @0x294420 ldr r3, [r11, #-0x40]
 *   @0x294424 sub sp, sp, #40
 *   @0x294428 mov r2, #2
 *   @0x29442c str r2, [r11, #-0x38]
 *   @0x294430 str r7, [sp, #0x14]
 *   @0x294434 vmov s13, r3
 *   @0x294438 add r3, sp, #8
 *   @0x29443c str r3, [r11, #-0x34]
 *   @0x294440 vcvt.f64.s32 d7, s13
 *   @0x294444 mov r5, r3
 *   @0x294448 vmov r2, r3, d7
 *   @0x29444c strd r2, r3, [r5], #16
 *   @0x294450 bl 0x290274 <getJNIEnv>
 *   @0x294454 mov r2, r7
 *   @0x294458 mov r1, r6
 *   @0x29445c ldr r3, [r0]
 *   @0x294460 ldr r3, [r3, #0x2a4]
 *   @0x294464 blx r3
 *   @0x294468 mov r7, r0
 *   @0x29446c mov r0, r5
 *   @0x294470 mov r1, r7
 *   @0x294474 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x294478 cmp r7, #0
 *   @0x29447c cmpne r6, #0
 *   @0x294480 bne 0x2944ec <Java_com_yoyogames_runner_RunnerJNILib_callreward+0x100>
 *   @0x294484 mov r1, #0
 *   @0x294488 sub r3, r11, #48
 *   @0x29448c mov r0, r8
 *   @0x294490 str r3, [sp]
 *   @0x294494 mov r2, r1
 *   @0x294498 sub r3, r11, #56
 *   @0x29449c str r3, [sp, #0x4]
 *   @0x2944a0 mov r3, #2
 *   @0x2944a4 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue>
 *   @0x2944a8 ldr r3, [pc, #0x60]
 *   @0x2944ac ldr r3, [pc, r3]
 *   @0x2944b0 ldrb r3, [r3]
 *   @0x2944b4 cmp r3, #0
 *   @0x2944b8 beq 0x2944d4 <Java_com_yoyogames_runner_RunnerJNILib_callreward+0xe8>
 *   @0x2944bc ldr r3, [pc, #0x50]
 *   @0x2944c0 mov r1, #0
 *   @0x2944c4 ldr r3, [pc, r3]
 *   @0x2944c8 ldr r3, [r3]
 *   @0x2944cc ldr r0, [r3]
 *   @0x2944d0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x2944d4 ldr r2, [r11, #-0x20]
 *   @0x2944d8 ldr r3, [r4]
 *   @0x2944dc cmp r2, r3
 *   @0x2944e0 bne 0x294508 <Java_com_yoyogames_runner_RunnerJNILib_callreward+0x11c>
 *   @0x2944e4 sub sp, r11, #28
 *   @0x2944e8 pop {r4, r5, r6, r7, r8, r9, r11, pc}
 *   @0x2944ec ldr r3, [r9]
 *   @0x2944f0 mov r1, r6
 *   @0x2944f4 mov r2, r7
 *   @0x2944f8 mov r0, r9
 *   @0x2944fc ldr r3, [r3, #0x2a8]
 *   @0x294500 blx r3
 *   @0x294504 b 0x294484 <Java_com_yoyogames_runner_RunnerJNILib_callreward+0x98>
 *   @0x294508 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x29450c andseq r9, r5, r0, asr r5
 *   @0x294510 ldrheq r9, [r5], -r8
 *   @0x294514 andseq r9, r5, r12, lsr #13
 *
 * ══ §36/102 b2RopeJoint::SolveVelocityConstraints(b2SolverData const&)  0x2d2340  size 300  75 条（0x2d2340..0x2d246c）
 * @func 0x2d2340 0x2d246c  size 300  75 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x60×1 / 0x64×1 / 0x1c×1
 * VFP 指令 66 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2340 ldr r2, [r0, #0x60]
 *   @0x2d2344 vpush {d8, d9, d10}
 *   @0x2d2348 ldr r3, [r0, #0x64]
 *   @0x2d234c vldr s2, [r0, #112]
 *   @0x2d2350 ldr r12, [r1, #0x1c]
 *   @0x2d2354 vldr s3, [r0, #120]
 *   @0x2d2358 add r2, r2, r2, lsl #1
 *   @0x2d235c vldr s1, [r0, #124]
 *   @0x2d2360 add r3, r3, r3, lsl #1
 *   @0x2d2364 vldr s11, [r0, #116]
 *   @0x2d2368 add r2, r12, r2, lsl #2
 *   @0x2d236c vldr s5, [r2, #4]
 *   @0x2d2370 add r3, r12, r3, lsl #2
 *   @0x2d2374 vmov.f32 s13, s5
 *   @0x2d2378 vldr s9, [r3, #4]
 *   @0x2d237c vldr s10, [r2, #8]
 *   @0x2d2380 vldr s12, [r3, #8]
 *   @0x2d2384 vldr s7, [r3]
 *   @0x2d2388 vldr s4, [r2]
 *   @0x2d238c vldr s0, [r0, #108]
 *   @0x2d2390 vmov.f32 s17, s9
 *   @0x2d2394 vldr s14, [r0, #104]
 *   @0x2d2398 vldr s16, [r0, #88]
 *   @0x2d239c vldr s15, [r0, #84]
 *   @0x2d23a0 vldr s19, [pc, #192]
 *   @0x2d23a4 vldr s18, [r0, #152]
 *   @0x2d23a8 vmla.f32 s17, s12, s3
 *   @0x2d23ac vmla.f32 s13, s10, s2
 *   @0x2d23b0 vmov.f32 s6, s7
 *   @0x2d23b4 vmov.f32 s8, s4
 *   @0x2d23b8 vmls.f32 s6, s12, s1
 *   @0x2d23bc vmls.f32 s8, s10, s11
 *   @0x2d23c0 vsub.f32 s13, s17, s13
 *   @0x2d23c4 vldr s17, [r0, #156]
 *   @0x2d23c8 vmul.f32 s13, s13, s0
 *   @0x2d23cc vsub.f32 s8, s6, s8
 *   @0x2d23d0 vldr s6, [r0, #144]
 *   @0x2d23d4 vmla.f32 s13, s8, s14
 *   @0x2d23d8 vsub.f32 s15, s16, s15
 *   @0x2d23dc vldr s16, [r0, #92]
 *   @0x2d23e0 vcmpe.f32 s15, #0
 *   @0x2d23e4 vmrs APSR_nzcv, fpscr
 *   @0x2d23e8 vldrmi s8, [r1, #4]
 *   @0x2d23ec vmlami.f32 s13, s15, s8
 *   @0x2d23f0 vldr s15, [r0, #160]
 *   @0x2d23f4 vldr s8, [r0, #148]
 *   @0x2d23f8 vmov.f32 s20, s16
 *   @0x2d23fc vmls.f32 s20, s15, s13
 *   @0x2d2400 vmov.f32 s15, s20
 *   @0x2d2404 vcmpe.f32 s20, s19
 *   @0x2d2408 vmrs APSR_nzcv, fpscr
 *   @0x2d240c vmovgt.f32 s15, s19
 *   @0x2d2410 vstr s15, [r0, #92]
 *   @0x2d2414 vsub.f32 s15, s15, s16
 *   @0x2d2418 vmul.f32 s14, s15, s14
 *   @0x2d241c vmul.f32 s15, s15, s0
 *   @0x2d2420 vmul.f32 s11, s11, s14
 *   @0x2d2424 vmul.f32 s13, s1, s14
 *   @0x2d2428 vnmls.f32 s11, s2, s15
 *   @0x2d242c vnmls.f32 s13, s3, s15
 *   @0x2d2430 vmls.f32 s10, s11, s18
 *   @0x2d2434 vmla.f32 s12, s13, s17
 *   @0x2d2438 vstr s10, [r2, #8]
 *   @0x2d243c vpop {d8, d9, d10}
 *   @0x2d2440 vmls.f32 s4, s6, s14
 *   @0x2d2444 vmls.f32 s5, s6, s15
 *   @0x2d2448 vstr s4, [r2]
 *   @0x2d244c vmla.f32 s7, s8, s14
 *   @0x2d2450 vstr s5, [r2, #4]
 *   @0x2d2454 vstr s12, [r3, #8]
 *   @0x2d2458 vmla.f32 s9, s8, s15
 *   @0x2d245c vstr s7, [r3]
 *   @0x2d2460 vstr s9, [r3, #4]
 *   @0x2d2464 bx lr
 *   @0x2d2468 andeq r0, r0, r0
 *
 * ══ §37/102 FT_Vector_NormLen  0x2e5096  size 300  75 条（0x2e5096..0x2e51c2）
 * @func 0x2e5096 0x2e51c2  size 300  75 条
 * 部分覆盖: 本节 75/116 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Vector_Polarize+0x2a / FT_Vector_NormLen+0x11c
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5096 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e509a ldm.w r0, {r2, r3}
 *   @0x2e509e cmp r2, #0x0
 *   @0x2e50a2 rsblt r2, r2, #0
 *   @0x2e50a6 .word 0xf04f38ff
 *   @0x2e50aa blhs 0x2e70b6 <FT_Vector_Polarize+0x2a>
 *   @0x2e50ae itte lt
 *   @0x2e50b2 movlt.w r12, #0xffffffff
 *   @0x2e50b6 movge.w r12, #0x1
 *   @0x2e50ba cbnz r2, 0x2e50c8 <FT_Vector_NormLen+0x32>
 *   @0x2e50be beq 0x2e51bc <FT_Vector_NormLen+0x126>
 *   @0x2e50c2 subvs r4, r2, r12, lsl #4
 *   @0x2e50c6 b 0x2e51bc <FT_Vector_NormLen+0x126>
 *   @0x2e50ca lsl.w r3, r8, #0x10
 *   @0x2e50ce str r3, [r0]
 *   @0x2e50d2 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e50d6 cmp r2, r3
 *   @0x2e50da svclt #0x8c31aa
 *   @0x2e50de addhi.w r4, r2, r3, lsr #1
 *   @0x2e50e2 addls.w r4, r3, r2, lsr #1
 *   @0x2e50e6 clz r5, r4
 *   @0x2e50ea lsrs r1, r5
 *   @0x2e50ee ite lo
 *   @0x2e50f2 movhs r1, #0x10
 *   @0x2e50f6 cmp r1, #0x0
 *   @0x2e50fa lsls r2, r1
 *   @0x2e50fe cmp r2, r3
 *   @0x2e5102 addhi.w r6, r2, r3, lsr #1
 *   @0x2e5106 addls.w r6, r3, r2, lsr #1
 *   @0x2e510a b 0x2e5116 <FT_Vector_NormLen+0x80>
 *   @0x2e510e lsrs r2, r6
 *   @0x2e5112 lsr.w r6, r4, r6
 *   @0x2e5116 rsb.w r6, r6, #0x10000
 *   @0x2e511a mul r5, r6, r2
 *   @0x2e511e add.w r9, r6, #0x10000
 *   @0x2e5122 mul r4, r6, r3
 *   @0x2e5126 asr.w r9, r9, #0x8
 *   @0x2e512a add.w r5, r2, r5, asr #16
 *   @0x2e512e add.w r11, r3, r4, asr #16
 *   @0x2e5132 mul r7, r5, r5
 *   @0x2e5136 mla r7, r11, r11, r7
 *   @0x2e513a cmp r7, #0x0
 *   @0x2e513e addwlt r7, r7, #0x1ff
 *   @0x2e5142 asr.w r10, r7, #0x9
 *   @0x2e5146 mov r7, r9
 *   @0x2e514a ldrbmi r0, [r4], -r0, lsl #20
 *   @0x2e514e muls r4, r7, r4
 *   @0x2e5152 addmi.w r7, r4, #0xff00
 *   @0x2e5156 mov r9, r4
 *   @0x2e515a addmi.w r9, r7, #0xff
 *   @0x2e515e asr.w r7, r9, #0x10
 *   @0x2e5162 cmp r7, #0x0
 *   @0x2e5166 bgt 0x2e511a <FT_Vector_NormLen+0x84>
 *   @0x2e516a cmp.w r8, #0xffffffff
 *   @0x2e516e mla r3, r3, r11, r2
 *   @0x2e5172 ite eq
 *   @0x2e5176 movne r6, r5
 *   @0x2e517a strdvs r3, r4, [r6], -pc
 *   @0x2e517e ite eq
 *   @0x2e5182 ldrbmi r0, [lr], -r0, lsl #12
 *   @0x2e5186 cmp r3, #0x0
 *   @0x2e518a addlt.w r3, r3, #0xff00
 *   @0x2e518e str r6, [r0, #0x4]
 *   @0x2e5192 addlt r3, #0xff
 *   @0x2e5196 asr.w r3, r3, #0x10
 *   @0x2e519a add.w r3, r3, #0x10000
 *   @0x2e519e ble 0x2e51b2 <FT_Vector_NormLen+0x11c>
 *   @0x2e51a2 movs r0, #0x1
 *   @0x2e51a6 ldrmi pc, [r3], #-514
 *   @0x2e51aa lsr.w r0, r3, r1
 *   @0x2e51ae pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e51b2 rsbs r1, r1, #0
 *   @0x2e51b6 pop {r0, r12, sp, lr, pc}
 *   @0x2e51ba ssub8mi r8, r8, r0
 *   @0x2e51be pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §38/102 BOOL_RValue(RValue const*)  0xd1294  size 296  74 条（0xd1294..0xd13bc）
 * @func 0xd1294 0xd13bc  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYError(char const*, ...)×2 / 0xb6658 / ARRAY_LVAL_RValue(YYRValue*, int)
 * 字段偏移 top8: 0xc×1 / 0x20×1 / 0x10×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd1294 push {r3, lr}
 *   @0xd1298 ldr r1, [r0, #0xc]
 *   @0xd129c bic r1, r1, #-16777216
 *   @0xd12a0 cmp r1, #13
 *   @0xd12a4 addls pc, pc, r1, lsl #2
 *   @0xd12a8 b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec>
 *   @0xd12ac b 0xd1300 <_Z11BOOL_RValuePK6RValue+0x6c>
 *   @0xd12b0 b 0xd1320 <_Z11BOOL_RValuePK6RValue+0x8c>
 *   @0xd12b4 b 0xd135c <_Z11BOOL_RValuePK6RValue+0xc8>
 *   @0xd12b8 b 0xd12e4 <_Z11BOOL_RValuePK6RValue+0x50>
 *   @0xd12bc b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec>
 *   @0xd12c0 b 0xd12f8 <_Z11BOOL_RValuePK6RValue+0x64>
 *   @0xd12c4 b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec>
 *   @0xd12c8 b 0xd12e4 <_Z11BOOL_RValuePK6RValue+0x50>
 *   @0xd12cc b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec>
 *   @0xd12d0 b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec>
 *   @0xd12d4 b 0xd1368 <_Z11BOOL_RValuePK6RValue+0xd4>
 *   @0xd12d8 b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec>
 *   @0xd12dc b 0xd1380 <_Z11BOOL_RValuePK6RValue+0xec>
 *   @0xd12e0 b 0xd1300 <_Z11BOOL_RValuePK6RValue+0x6c>
 *   @0xd12e4 ldr r0, [r0]
 *   @0xd12e8 cmp r0, #0
 *   @0xd12ec movle r0, #0
 *   @0xd12f0 movgt r0, #1
 *   @0xd12f4 pop {r3, pc}
 *   @0xd12f8 mov r0, #0
 *   @0xd12fc pop {r3, pc}
 *   @0xd1300 vmov.f64 d7, #5.000000e-01
 *   @0xd1304 ldm r0, {r2, r3}
 *   @0xd1308 vmov d6, r2, r3
 *   @0xd130c vcmpe.f64 d6, d7
 *   @0xd1310 vmrs APSR_nzcv, fpscr
 *   @0xd1314 movle r0, #0
 *   @0xd1318 movgt r0, #1
 *   @0xd131c pop {r3, pc}
 *   @0xd1320 ldr r0, [r0]
 *   @0xd1324 cmp r0, #0
 *   @0xd1328 popeq {r3, pc}
 *   @0xd132c ldr r0, [r0]
 *   @0xd1330 cmp r0, #0
 *   @0xd1334 popeq {r3, pc}
 *   @0xd1338 mov r1, #0
 *   @0xd133c bl 0xb6658 <strtod@plt>
 *   @0xd1340 vmov.f64 d7, #5.000000e-01
 *   @0xd1344 vmov d6, r0, r1
 *   @0xd1348 vcmpe.f64 d6, d7
 *   @0xd134c vmrs APSR_nzcv, fpscr
 *   @0xd1350 movle r0, #0
 *   @0xd1354 movgt r0, #1
 *   @0xd1358 pop {r3, pc}
 *   @0xd135c mov r1, #0
 *   @0xd1360 bl 0xd0d38 <_Z17ARRAY_LVAL_RValueP8YYRValuei>
 *   @0xd1364 b 0xd1298 <_Z11BOOL_RValuePK6RValue+0x4>
 *   @0xd1368 ldm r0, {r2, r3}
 *   @0xd136c cmp r2, #1
 *   @0xd1370 sbcs r1, r3, #0
 *   @0xd1374 movlt r0, #0
 *   @0xd1378 movge r0, #1
 *   @0xd137c pop {r3, pc}
 *   @0xd1380 mvn r3, #-16777216
 *   @0xd1384 cmp r1, r3
 *   @0xd1388 beq 0xd13a0 <_Z11BOOL_RValuePK6RValue+0x10c>
 *   @0xd138c ldr r0, [pc, #0x20]
 *   @0xd1390 add r0, pc, r0
 *   @0xd1394 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd1398 mov r0, #0
 *   @0xd139c pop {r3, pc}
 *   @0xd13a0 ldr r0, [pc, #0x10]
 *   @0xd13a4 add r0, pc, r0
 *   @0xd13a8 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd13ac mov r0, #0
 *   @0xd13b0 pop {r3, pc}
 *   @0xd13b4 .word 0x002612fc
 *   @0xd13b8 .word 0x002612d0
 *
 * ══ §39/102 Code_Variable_Read_Local_Names(unsigned char*)  0xd24d4  size 296  74 条（0xd24d4..0xd25fc）
 * @func 0xd24d4 0xd25fc  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd24fc→0x47a1b0, 0xd250c→0x47a1ac, 0xd253c→0x544c44, 0xd2588→0x544c44
 * 调用序列: YYAlloc(int)×2 / YYStrDup(char const*)×2 / Code_Variable_Read_Local_Names(unsigned char*)+0x110 / Code_Variable_Read_Local_Names(unsigned char*)+0xf0
 * 字段偏移 top8: 0x4×8 / 0x8×2 / 0x100×1 / 0xec×1 / 0xe0×1 / 0x68×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd24d4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd24d8 mov r8, r0
 *   @0xd24dc ldr r2, [r8], #4
 *   @0xd24e0 sub sp, sp, #12
 *   @0xd24e4 ldr r9, [pc, #0x100]
 *   @0xd24e8 add r0, r2, r2, lsl #1
 *   @0xd24ec str r2, [sp, #0x4]
 *   @0xd24f0 add r9, pc, r9
 *   @0xd24f4 lsl r0, r0, #2
 *   @0xd24f8 bl 0xcef4c <_Z7YYAlloci>
 *   @0xd24fc ldr r2, [pc, #0xec]
 *   @0xd2500 ldr r3, [sp, #0x4]
 *   @0xd2504 ldr r7, [r9, r2]
 *   @0xd2508 cmp r3, #0
 *   @0xd250c ldr r3, [pc, #0xe0]
 *   @0xd2510 ldr r2, [sp, #0x4]
 *   @0xd2514 str r0, [r7]
 *   @0xd2518 ldr r3, [r9, r3]
 *   @0xd251c str r2, [r3]
 *   @0xd2520 ble 0xd25e4 <_Z30Code_Variable_Read_Local_NamesPh+0x110>
 *   @0xd2524 mov r4, r0
 *   @0xd2528 mov r5, #0
 *   @0xd252c str r5, [sp]
 *   @0xd2530 ldr r0, [r8, #0x4]
 *   @0xd2534 ldr r6, [r8]
 *   @0xd2538 cmp r0, #0
 *   @0xd253c ldrne r3, [pc, #0xb4]
 *   @0xd2540 ldrne r3, [r9, r3]
 *   @0xd2544 ldrne r3, [r3]
 *   @0xd2548 addne r0, r3, r0
 *   @0xd254c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xd2550 ldr r3, [r7]
 *   @0xd2554 add r8, r8, #8
 *   @0xd2558 add r11, r3, r5
 *   @0xd255c str r0, [r4, r5]
 *   @0xd2560 lsl r0, r6, #2
 *   @0xd2564 str r6, [r11, #0x4]
 *   @0xd2568 bl 0xcef4c <_Z7YYAlloci>
 *   @0xd256c cmp r6, #0
 *   @0xd2570 str r0, [r11, #0x8]
 *   @0xd2574 ble 0xd25c4 <_Z30Code_Variable_Read_Local_NamesPh+0xf0>
 *   @0xd2578 mov r11, r8
 *   @0xd257c mov r4, #0
 *   @0xd2580 ldr r3, [r11, #0x4]
 *   @0xd2584 add r11, r11, #8
 *   @0xd2588 ldr r1, [pc, #0x68]
 *   @0xd258c cmp r3, #0
 *   @0xd2590 mov r0, r3
 *   @0xd2594 ldrne r1, [r9, r1]
 *   @0xd2598 ldrne r0, [r1]
 *   @0xd259c addne r0, r0, r3
 *   @0xd25a0 ldr r3, [r7]
 *   @0xd25a4 add r3, r3, r5
 *   @0xd25a8 ldr r10, [r3, #0x8]
 *   @0xd25ac bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xd25b0 str r0, [r10, r4, lsl #2]
 *   @0xd25b4 add r4, r4, #1
 *   @0xd25b8 cmp r4, r6
 *   @0xd25bc bne 0xd2580 <_Z30Code_Variable_Read_Local_NamesPh+0xac>
 *   @0xd25c0 add r8, r8, r4, lsl #3
 *   @0xd25c4 ldr r3, [sp]
 *   @0xd25c8 add r5, r5, #12
 *   @0xd25cc ldr r2, [sp, #0x4]
 *   @0xd25d0 add r3, r3, #1
 *   @0xd25d4 str r3, [sp]
 *   @0xd25d8 cmp r3, r2
 *   @0xd25dc ldrne r4, [r7]
 *   @0xd25e0 bne 0xd2530 <_Z30Code_Variable_Read_Local_NamesPh+0x5c>
 *   @0xd25e4 add sp, sp, #12
 *   @0xd25e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd25ec eorseq pc, r1, r0, ror #14
 *   @0xd25f0 .word 0xffffbf60
 *   @0xd25f4 .word 0xffffbf5c
 *   @0xd25f8 .word 0xffffbcf4
 *
 * ══ §40/102 YYGML_CallLegacyFunction(CInstance*, CInstance*, YYRValue&, int, int, YYRValue**)  0xe3d30  size 296  74 条（0xe3d30..0xe3e58）
 * @func 0xe3d30 0xe3e58  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_CallLegacyFunction(CInstance*, CInstance*, YYRValue&, int, int, YYRValue**)+0x98 / FREE_RValue__Pre(RValue*) / 0xb65d4
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0xc×3 / 0x-28×2 / 0x-30×2 / 0x-34×2 / 0x10c×1 / 0x104×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xe3d30 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xe3d34 add r11, sp, #32
 *   @0xe3d38 ldr r7, [pc, #0x10c]
 *   @0xe3d3c sub sp, sp, #28
 *   @0xe3d40 mov r5, r3
 *   @0xe3d44 ldr r3, [pc, #0x104]
 *   @0xe3d48 lsl r4, r5, #4
 *   @0xe3d4c ldr r7, [pc, r7]
 *   @0xe3d50 ldr r12, [r11, #0x4]
 *   @0xe3d54 add r4, r4, #8
 *   @0xe3d58 ldr r3, [pc, r3]
 *   @0xe3d5c ldr lr, [r7]
 *   @0xe3d60 sub sp, sp, r4
 *   @0xe3d64 cmp r5, #0
 *   @0xe3d68 ldr r3, [r3]
 *   @0xe3d6c add r12, r12, r12, lsl #2
 *   @0xe3d70 add r9, sp, #8
 *   @0xe3d74 ldr r10, [r11, #0x8]
 *   @0xe3d78 mov r6, r2
 *   @0xe3d7c str lr, [r11, #-0x28]
 *   @0xe3d80 add r8, r3, r12, lsl #4
 *   @0xe3d84 str r0, [r11, #-0x30]
 *   @0xe3d88 subgt r10, r10, #4
 *   @0xe3d8c str r1, [r11, #-0x34]
 *   @0xe3d90 movgt r4, r9
 *   @0xe3d94 movgt lr, #0
 *   @0xe3d98 ble 0xe3dc8 <_Z24YYGML_CallLegacyFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x98>
 *   @0xe3d9c ldr r3, [r10, #0x4]!
 *   @0xe3da0 add lr, lr, #1
 *   @0xe3da4 cmp lr, r5
 *   @0xe3da8 mov r12, r4
 *   @0xe3dac add r4, r4, #16
 *   @0xe3db0 ldr r0, [r3]
 *   @0xe3db4 ldr r1, [r3, #0x4]
 *   @0xe3db8 ldr r2, [r3, #0x8]
 *   @0xe3dbc ldr r3, [r3, #0xc]
 *   @0xe3dc0 stm r12!, {r0, r1, r2, r3}
 *   @0xe3dc4 bne 0xe3d9c <_Z24YYGML_CallLegacyFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x6c>
 *   @0xe3dc8 ldr r3, [r6, #0xc]
 *   @0xe3dcc sub r3, r3, #1
 *   @0xe3dd0 bic r3, r3, #-16777216
 *   @0xe3dd4 bic r3, r3, #3
 *   @0xe3dd8 cmp r3, #0
 *   @0xe3ddc bne 0xe3de8 <_Z24YYGML_CallLegacyFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0xb8>
 *   @0xe3de0 mov r0, r6
 *   @0xe3de4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xe3de8 ldr r4, [pc, #0x64]
 *   @0xe3dec mov r3, r5
 *   @0xe3df0 mov r0, #0
 *   @0xe3df4 ldr r2, [r11, #-0x34]
 *   @0xe3df8 ldr r4, [pc, r4]
 *   @0xe3dfc str r0, [r6]
 *   @0xe3e00 str r0, [r6, #0x8]
 *   @0xe3e04 mov r12, #5
 *   @0xe3e08 ldr r5, [r4]
 *   @0xe3e0c mov r0, r6
 *   @0xe3e10 str r12, [r6, #0xc]
 *   @0xe3e14 str r8, [r4]
 *   @0xe3e18 ldr r1, [r11, #-0x30]
 *   @0xe3e1c str r9, [sp]
 *   @0xe3e20 ldr r12, [r8, #0x40]
 *   @0xe3e24 blx r12
 *   @0xe3e28 ldr r2, [r11, #-0x28]
 *   @0xe3e2c ldr r3, [r7]
 *   @0xe3e30 mov r0, r6
 *   @0xe3e34 str r5, [r4]
 *   @0xe3e38 cmp r2, r3
 *   @0xe3e3c bne 0xe3e48 <_Z24YYGML_CallLegacyFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe3e40 sub sp, r11, #32
 *   @0xe3e44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xe3e48 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xe3e4c eorseq r9, r0, r4, lsl #24
 *   @0xe3e50 eorseq r9, r0, r0, asr #27
 *   @0xe3e54 eorseq r9, r0, r8, lsr sp
 *
 * ══ §41/102 DIALOG_REQ_CONTEXT::AddLoginDialog(char const*, char const*)  0xf2474  size 296  74 条（0xf2474..0xf259c）
 * @func 0xf2474 0xf25ac  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6640×2 / operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool) / loginDialogAsync / showMessage / questionDialogAsync / inputDialogAsync
 * 字段偏移 top8: 0x24×5 / 0x48×4 / 0x4c×4 / 0xfc×1 / 0x4×1 / 0x8×1 / 0xdc×1 / 0xb0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2474 push {r4, r5, r6, lr}
 *   @0xf2478 mov r6, r0
 *   @0xf247c sub sp, sp, #16
 *   @0xf2480 mov r0, #88
 *   @0xf2484 mov r5, r1
 *   @0xf2488 bl 0x27c524 <_Znwj>
 *   @0xf248c ldr r3, [pc, #0xfc]
 *   @0xf2490 mov r2, #0
 *   @0xf2494 mov r1, r2
 *   @0xf2498 str r2, [sp]
 *   @0xf249c ldr r3, [pc, r3]
 *   @0xf24a0 str r2, [sp, #0x4]
 *   @0xf24a4 str r2, [sp, #0x8]
 *   @0xf24a8 mov r4, r0
 *   @0xf24ac bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0xf24b0 ldr r3, [pc, #0xdc]
 *   @0xf24b4 subs r0, r6, #0
 *   @0xf24b8 ldr r3, [pc, r3]
 *   @0xf24bc add r3, r3, #8
 *   @0xf24c0 str r3, [r4]
 *   @0xf24c4 beq 0xf24cc <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0x58>
 *   @0xf24c8 bl 0xb6640 <strdup@plt>
 *   @0xf24cc cmp r5, #0
 *   @0xf24d0 str r0, [r4, #0x48]
 *   @0xf24d4 mov r0, r5
 *   @0xf24d8 beq 0xf24e0 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0x6c>
 *   @0xf24dc bl 0xb6640 <strdup@plt>
 *   @0xf24e0 ldr r3, [pc, #0xb0]
 *   @0xf24e4 mov r1, #0
 *   @0xf24e8 str r1, [r4, #0x50]
 *   @0xf24ec mov r2, #3
 *   @0xf24f0 ldr r3, [pc, r3]
 *   @0xf24f4 str r0, [r4, #0x4c]
 *   @0xf24f8 str r2, [r4, #0x54]
 *   @0xf24fc mov r0, #1
 *   @0xf2500 ldr r1, [r3]
 *   @0xf2504 str r0, [r4, #0x30]
 *   @0xf2508 cmp r1, #0
 *   @0xf250c str r4, [r3]
 *   @0xf2510 str r1, [r4, #0x44]
 *   @0xf2514 beq 0xf2524 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xb0>
 *   @0xf2518 ldr r0, [r4, #0x24]
 *   @0xf251c add sp, sp, #16
 *   @0xf2520 pop {r4, r5, r6, pc}
 *   @0xf2524 cmp r2, r2
 *   @0xf2528 addls pc, pc, r2, lsl #2
 *   @0xf252c b 0xf2518 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xa4>
 *   @0xf2530 b 0xf257c <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0x108>
 *   @0xf2534 b 0xf2568 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xf4>
 *   @0xf2538 b 0xf2554 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xe0>
 *   @0xf253c b 0xf2540 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xcc>
 *   @0xf2540 ldr r0, [r4, #0x48]
 *   @0xf2544 ldr r1, [r4, #0x4c]
 *   @0xf2548 ldr r2, [r4, #0x24]
 *   @0xf254c bl 0xf2ad0 <loginDialogAsync>
 *   @0xf2550 b 0xf2518 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xa4>
 *   @0xf2554 ldr r0, [r4, #0x48]
 *   @0xf2558 ldr r1, [r4, #0x4c]
 *   @0xf255c ldr r2, [r4, #0x24]
 *   @0xf2560 bl 0xf2b4c <showMessage>
 *   @0xf2564 b 0xf2518 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xa4>
 *   @0xf2568 ldr r0, [r4, #0x48]
 *   @0xf256c ldr r1, [r4, #0x4c]
 *   @0xf2570 ldr r2, [r4, #0x24]
 *   @0xf2574 bl 0xf2a70 <questionDialogAsync>
 *   @0xf2578 b 0xf2518 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xa4>
 *   @0xf257c add r0, r4, #72
 *   @0xf2580 ldr r3, [r4, #0x24]
 *   @0xf2584 ldm r0, {r0, r1, r2}
 *   @0xf2588 bl 0xf29f4 <inputDialogAsync>
 *   @0xf258c b 0xf2518 <_ZN18DIALOG_REQ_CONTEXT14AddLoginDialogEPKcS1_+0xa4>
 *   @0xf2590 eoreq r11, pc, r4, asr r9
 *   @0xf2594 eoreq r11, pc, r8, lsr #18
 *   @0xf2598 .word 0x002fb8f4
 *
 * ══ §42/102 DIALOG_REQ_CONTEXT::AddMessageDialog(char const*, char const*)  0xf259c  size 296  74 条（0xf259c..0xf26c4）
 * @func 0xf259c 0xf26c4  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6640×2 / operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool) / loginDialogAsync / showMessage / questionDialogAsync / inputDialogAsync
 * 字段偏移 top8: 0x24×5 / 0x48×4 / 0x4c×4 / 0xfc×1 / 0x4×1 / 0x8×1 / 0xdc×1 / 0xb0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf259c push {r4, r5, r6, lr}
 *   @0xf25a0 mov r6, r0
 *   @0xf25a4 sub sp, sp, #16
 *   @0xf25a8 mov r0, #88
 *   @0xf25ac mov r5, r1
 *   @0xf25b0 bl 0x27c524 <_Znwj>
 *   @0xf25b4 ldr r3, [pc, #0xfc]
 *   @0xf25b8 mov r2, #0
 *   @0xf25bc mov r1, r2
 *   @0xf25c0 str r2, [sp]
 *   @0xf25c4 ldr r3, [pc, r3]
 *   @0xf25c8 str r2, [sp, #0x4]
 *   @0xf25cc str r2, [sp, #0x8]
 *   @0xf25d0 mov r4, r0
 *   @0xf25d4 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0xf25d8 ldr r3, [pc, #0xdc]
 *   @0xf25dc subs r0, r6, #0
 *   @0xf25e0 ldr r3, [pc, r3]
 *   @0xf25e4 add r3, r3, #8
 *   @0xf25e8 str r3, [r4]
 *   @0xf25ec beq 0xf25f4 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0x58>
 *   @0xf25f0 bl 0xb6640 <strdup@plt>
 *   @0xf25f4 cmp r5, #0
 *   @0xf25f8 str r0, [r4, #0x48]
 *   @0xf25fc mov r0, r5
 *   @0xf2600 beq 0xf2608 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0x6c>
 *   @0xf2604 bl 0xb6640 <strdup@plt>
 *   @0xf2608 ldr r3, [pc, #0xb0]
 *   @0xf260c mov r1, #0
 *   @0xf2610 str r1, [r4, #0x50]
 *   @0xf2614 mov r2, #2
 *   @0xf2618 ldr r3, [pc, r3]
 *   @0xf261c str r0, [r4, #0x4c]
 *   @0xf2620 str r2, [r4, #0x54]
 *   @0xf2624 mov r0, #1
 *   @0xf2628 ldr r1, [r3]
 *   @0xf262c str r0, [r4, #0x30]
 *   @0xf2630 cmp r1, #0
 *   @0xf2634 str r4, [r3]
 *   @0xf2638 str r1, [r4, #0x44]
 *   @0xf263c beq 0xf264c <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xb0>
 *   @0xf2640 ldr r0, [r4, #0x24]
 *   @0xf2644 add sp, sp, #16
 *   @0xf2648 pop {r4, r5, r6, pc}
 *   @0xf264c cmp r2, #3
 *   @0xf2650 addls pc, pc, r2, lsl #2
 *   @0xf2654 b 0xf2640 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xa4>
 *   @0xf2658 b 0xf26a4 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0x108>
 *   @0xf265c b 0xf2690 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xf4>
 *   @0xf2660 b 0xf267c <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xe0>
 *   @0xf2664 b 0xf2668 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xcc>
 *   @0xf2668 ldr r0, [r4, #0x48]
 *   @0xf266c ldr r1, [r4, #0x4c]
 *   @0xf2670 ldr r2, [r4, #0x24]
 *   @0xf2674 bl 0xf2ad0 <loginDialogAsync>
 *   @0xf2678 b 0xf2640 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xa4>
 *   @0xf267c ldr r0, [r4, #0x48]
 *   @0xf2680 ldr r1, [r4, #0x4c]
 *   @0xf2684 ldr r2, [r4, #0x24]
 *   @0xf2688 bl 0xf2b4c <showMessage>
 *   @0xf268c b 0xf2640 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xa4>
 *   @0xf2690 ldr r0, [r4, #0x48]
 *   @0xf2694 ldr r1, [r4, #0x4c]
 *   @0xf2698 ldr r2, [r4, #0x24]
 *   @0xf269c bl 0xf2a70 <questionDialogAsync>
 *   @0xf26a0 b 0xf2640 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xa4>
 *   @0xf26a4 add r0, r4, #72
 *   @0xf26a8 ldr r3, [r4, #0x24]
 *   @0xf26ac ldm r0, {r0, r1, r2}
 *   @0xf26b0 bl 0xf29f4 <inputDialogAsync>
 *   @0xf26b4 b 0xf2640 <_ZN18DIALOG_REQ_CONTEXT16AddMessageDialogEPKcS1_+0xa4>
 *   @0xf26b8 eoreq r11, pc, r0, lsr r8
 *   @0xf26bc eoreq r11, pc, r0, lsl #16
 *   @0xf26c0 eoreq r11, pc, r12, asr #15
 *
 * ══ §43/102 CFontGM::Clear()  0xf70a0  size 296  74 条（0xf70a0..0xf71c8）
 * @func 0xf70a0 0xf71c8  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×6 / FT_Done_Face / CFontGM::Clear()+0xbc / CFontGM::FreeTexture()
 * 字段偏移 top8: 0x44×4 / 0x4×2 / 0x54×2 / 0x70×2 / 0x40×2 / 0x2×2 / 0x8c×2 / 0x34×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf70a0 push {r4, r5, r6, lr}
 *   @0xf70a4 mov r4, r0
 *   @0xf70a8 ldr r0, [r0, #0x4]
 *   @0xf70ac cmp r0, #0
 *   @0xf70b0 beq 0xf70c0 <_ZN7CFontGM5ClearEv+0x20>
 *   @0xf70b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf70b8 mov r3, #0
 *   @0xf70bc str r3, [r4, #0x4]
 *   @0xf70c0 ldr r0, [r4, #0x54]
 *   @0xf70c4 mov r5, #0
 *   @0xf70c8 mov r3, #1065353216
 *   @0xf70cc mov r2, #12
 *   @0xf70d0 cmp r0, r5
 *   @0xf70d4 mov r1, #32
 *   @0xf70d8 str r2, [r4, #0x8]
 *   @0xf70dc mov r2, #128
 *   @0xf70e0 str r1, [r4, #0x18]
 *   @0xf70e4 mov r1, #0
 *   @0xf70e8 str r2, [r4, #0x1c]
 *   @0xf70ec mvn r2, #0
 *   @0xf70f0 strb r5, [r4, #0xc]
 *   @0xf70f4 strb r5, [r4, #0xd]
 *   @0xf70f8 str r1, [r4, #0x50]
 *   @0xf70fc str r2, [r4, #0x20]
 *   @0xf7100 str r3, [r4, #0x48]
 *   @0xf7104 str r3, [r4, #0x4c]
 *   @0xf7108 beq 0xf7114 <_ZN7CFontGM5ClearEv+0x74>
 *   @0xf710c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf7110 str r5, [r4, #0x54]
 *   @0xf7114 ldr r0, [r4, #0x70]
 *   @0xf7118 cmp r0, #0
 *   @0xf711c beq 0xf7164 <_ZN7CFontGM5ClearEv+0xc4>
 *   @0xf7120 blx 0x2e8bdc <FT_Done_Face>
 *   @0xf7124 ldr r3, [r4, #0x40]
 *   @0xf7128 cmp r3, #0
 *   @0xf712c movgt r5, #0
 *   @0xf7130 movgt r6, r5
 *   @0xf7134 ble 0xf715c <_ZN7CFontGM5ClearEv+0xbc>
 *   @0xf7138 ldr r3, [r4, #0x44]
 *   @0xf713c ldr r0, [r3, r5, lsl #2]
 *   @0xf7140 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf7144 ldr r2, [r4, #0x44]
 *   @0xf7148 ldr r3, [r4, #0x40]
 *   @0xf714c str r6, [r2, r5, lsl #2]
 *   @0xf7150 add r5, r5, #1
 *   @0xf7154 cmp r3, r5
 *   @0xf7158 bgt 0xf7138 <_ZN7CFontGM5ClearEv+0x98>
 *   @0xf715c mov r3, #0
 *   @0xf7160 str r3, [r4, #0x70]
 *   @0xf7164 ldr r0, [r4, #0x44]
 *   @0xf7168 cmp r0, #0
 *   @0xf716c beq 0xf717c <_ZN7CFontGM5ClearEv+0xdc>
 *   @0xf7170 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf7174 mov r3, #0
 *   @0xf7178 str r3, [r4, #0x44]
 *   @0xf717c ldr r0, [r4, #0x8c]
 *   @0xf7180 cmp r0, #0
 *   @0xf7184 beq 0xf7194 <_ZN7CFontGM5ClearEv+0xf4>
 *   @0xf7188 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf718c mov r3, #0
 *   @0xf7190 str r3, [r4, #0x8c]
 *   @0xf7194 mov r0, r4
 *   @0xf7198 bl 0xf707c <_ZN7CFontGM11FreeTextureEv>
 *   @0xf719c ldr r0, [r4, #0x34]
 *   @0xf71a0 cmp r0, #0
 *   @0xf71a4 beq 0xf71ac <_ZN7CFontGM5ClearEv+0x10c>
 *   @0xf71a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf71ac mov r3, #0
 *   @0xf71b0 mvn r2, #0
 *   @0xf71b4 str r3, [r4, #0x34]
 *   @0xf71b8 str r3, [r4, #0x30]
 *   @0xf71bc str r3, [r4, #0x2c]
 *   @0xf71c0 str r2, [r4, #0x38]
 *   @0xf71c4 pop {r4, r5, r6, pc}
 *
 * ══ §44/102 F_DsGridSetGridRegion(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd948  size 296  74 条（0xfd948..0xfda70）
 * @func 0xfd948 0xfda80  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×8 / F_DsGridSetGridRegion(RValue&, CInstance*, CInstance*, int, RValue*)+0x104×2 / CDS_Grid::Grid_Operation(int, CDS_Grid*, int, int, int, int, int, int)
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x40×1 / 0x80×1 / 0x70×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd948 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfd94c sub sp, sp, #28
 *   @0xfd950 mov r1, #0
 *   @0xfd954 ldr r4, [sp, #0x40]
 *   @0xfd958 mov r0, r4
 *   @0xfd95c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd960 mov r1, #1
 *   @0xfd964 mov r5, r0
 *   @0xfd968 mov r0, r4
 *   @0xfd96c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd970 mov r1, #2
 *   @0xfd974 mov r11, r0
 *   @0xfd978 mov r0, r4
 *   @0xfd97c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd980 mov r1, #3
 *   @0xfd984 mov r7, r0
 *   @0xfd988 mov r0, r4
 *   @0xfd98c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd990 mov r1, #4
 *   @0xfd994 mov r10, r0
 *   @0xfd998 mov r0, r4
 *   @0xfd99c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd9a0 mov r1, #5
 *   @0xfd9a4 mov r9, r0
 *   @0xfd9a8 mov r0, r4
 *   @0xfd9ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd9b0 mov r1, #6
 *   @0xfd9b4 mov r8, r0
 *   @0xfd9b8 mov r0, r4
 *   @0xfd9bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd9c0 mov r1, #7
 *   @0xfd9c4 mov r6, r0
 *   @0xfd9c8 mov r0, r4
 *   @0xfd9cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd9d0 cmp r5, #0
 *   @0xfd9d4 mov r12, r0
 *   @0xfd9d8 blt 0xfda4c <_Z21F_DsGridSetGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfd9dc ldr r2, [pc, #0x80]
 *   @0xfd9e0 ldr r2, [pc, r2]
 *   @0xfd9e4 ldr r3, [r2]
 *   @0xfd9e8 cmp r5, r3
 *   @0xfd9ec bge 0xfda4c <_Z21F_DsGridSetGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfd9f0 ldr r2, [pc, #0x70]
 *   @0xfd9f4 ldr r2, [pc, r2]
 *   @0xfd9f8 ldr r2, [r2, #0x4]
 *   @0xfd9fc ldr r0, [r2, r5, lsl #2]
 *   @0xfda00 cmp r0, #0
 *   @0xfda04 beq 0xfda4c <_Z21F_DsGridSetGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfda08 cmp r11, #0
 *   @0xfda0c blt 0xfda4c <_Z21F_DsGridSetGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfda10 cmp r11, r3
 *   @0xfda14 bge 0xfda4c <_Z21F_DsGridSetGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfda18 ldr r2, [r2, r11, lsl #2]
 *   @0xfda1c cmp r2, #0
 *   @0xfda20 beq 0xfda4c <_Z21F_DsGridSetGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfda24 str r10, [sp]
 *   @0xfda28 mov r3, r7
 *   @0xfda2c str r9, [sp, #0x4]
 *   @0xfda30 mov r1, #1
 *   @0xfda34 str r8, [sp, #0x8]
 *   @0xfda38 str r6, [sp, #0xc]
 *   @0xfda3c str r12, [sp, #0x10]
 *   @0xfda40 bl 0x207fe8 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii>
 *   @0xfda44 add sp, sp, #28
 *   @0xfda48 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xfda4c ldr r0, [pc, #0x18]
 *   @0xfda50 mov r1, #0
 *   @0xfda54 add r0, pc, r0
 *   @0xfda58 add sp, sp, #28
 *   @0xfda5c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfda60 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfda64 eoreq r0, pc, r4, lsr #9
 *   @0xfda68 mlaeq pc, r4, r4, r0
 *   @0xfda6c eoreq r10, r3, r8, lsr #3
 *
 * ══ §45/102 F_DsGridAddGridRegion(RValue&, CInstance*, CInstance*, int, RValue*)  0xfda70  size 296  74 条（0xfda70..0xfdb98）
 * @func 0xfda70 0xfdba8  size 312  78 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×8 / F_DsGridAddGridRegion(RValue&, CInstance*, CInstance*, int, RValue*)+0x104×2 / CDS_Grid::Grid_Operation(int, CDS_Grid*, int, int, int, int, int, int)
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x40×1 / 0x80×1 / 0x70×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfda70 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfda74 sub sp, sp, #28
 *   @0xfda78 mov r1, #0
 *   @0xfda7c ldr r4, [sp, #0x40]
 *   @0xfda80 mov r0, r4
 *   @0xfda84 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfda88 mov r1, #1
 *   @0xfda8c mov r5, r0
 *   @0xfda90 mov r0, r4
 *   @0xfda94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfda98 mov r1, #2
 *   @0xfda9c mov r11, r0
 *   @0xfdaa0 mov r0, r4
 *   @0xfdaa4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdaa8 mov r1, #3
 *   @0xfdaac mov r7, r0
 *   @0xfdab0 mov r0, r4
 *   @0xfdab4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdab8 mov r1, #4
 *   @0xfdabc mov r10, r0
 *   @0xfdac0 mov r0, r4
 *   @0xfdac4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdac8 mov r1, #5
 *   @0xfdacc mov r9, r0
 *   @0xfdad0 mov r0, r4
 *   @0xfdad4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdad8 mov r1, #6
 *   @0xfdadc mov r8, r0
 *   @0xfdae0 mov r0, r4
 *   @0xfdae4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdae8 mov r1, #7
 *   @0xfdaec mov r6, r0
 *   @0xfdaf0 mov r0, r4
 *   @0xfdaf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdaf8 cmp r5, #0
 *   @0xfdafc mov r12, r0
 *   @0xfdb00 blt 0xfdb74 <_Z21F_DsGridAddGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfdb04 ldr r2, [pc, #0x80]
 *   @0xfdb08 ldr r2, [pc, r2]
 *   @0xfdb0c ldr r3, [r2]
 *   @0xfdb10 cmp r5, r3
 *   @0xfdb14 bge 0xfdb74 <_Z21F_DsGridAddGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfdb18 ldr r2, [pc, #0x70]
 *   @0xfdb1c ldr r2, [pc, r2]
 *   @0xfdb20 ldr r2, [r2, #0x4]
 *   @0xfdb24 ldr r0, [r2, r5, lsl #2]
 *   @0xfdb28 cmp r0, #0
 *   @0xfdb2c beq 0xfdb74 <_Z21F_DsGridAddGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfdb30 cmp r11, #0
 *   @0xfdb34 blt 0xfdb74 <_Z21F_DsGridAddGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfdb38 cmp r11, r3
 *   @0xfdb3c bge 0xfdb74 <_Z21F_DsGridAddGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfdb40 ldr r2, [r2, r11, lsl #2]
 *   @0xfdb44 cmp r2, #0
 *   @0xfdb48 beq 0xfdb74 <_Z21F_DsGridAddGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfdb4c str r10, [sp]
 *   @0xfdb50 mov r3, r7
 *   @0xfdb54 str r9, [sp, #0x4]
 *   @0xfdb58 mov r1, #2
 *   @0xfdb5c str r8, [sp, #0x8]
 *   @0xfdb60 str r6, [sp, #0xc]
 *   @0xfdb64 str r12, [sp, #0x10]
 *   @0xfdb68 bl 0x207fe8 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii>
 *   @0xfdb6c add sp, sp, #28
 *   @0xfdb70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xfdb74 ldr r0, [pc, #0x18]
 *   @0xfdb78 mov r1, #0
 *   @0xfdb7c add r0, pc, r0
 *   @0xfdb80 add sp, sp, #28
 *   @0xfdb84 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfdb88 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfdb8c eoreq r0, pc, r12, ror r3
 *   @0xfdb90 eoreq r0, pc, r12, ror #6
 *   @0xfdb94 eoreq r10, r3, r0, lsl #1
 *
 * ══ §46/102 F_DsGridMultiplyGridRegion(RValue&, CInstance*, CInstance*, int, RValue*)  0xfdb98  size 296  74 条（0xfdb98..0xfdcc0）
 * @func 0xfdb98 0xfdcc0  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×8 / F_DsGridMultiplyGridRegion(RValue&, CInstance*, CInstance*, int, RValue*)+0x104×2 / CDS_Grid::Grid_Operation(int, CDS_Grid*, int, int, int, int, int, int)
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x40×1 / 0x80×1 / 0x70×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfdb98 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfdb9c sub sp, sp, #28
 *   @0xfdba0 mov r1, #0
 *   @0xfdba4 ldr r4, [sp, #0x40]
 *   @0xfdba8 mov r0, r4
 *   @0xfdbac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdbb0 mov r1, #1
 *   @0xfdbb4 mov r5, r0
 *   @0xfdbb8 mov r0, r4
 *   @0xfdbbc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdbc0 mov r1, #2
 *   @0xfdbc4 mov r11, r0
 *   @0xfdbc8 mov r0, r4
 *   @0xfdbcc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdbd0 mov r1, #3
 *   @0xfdbd4 mov r7, r0
 *   @0xfdbd8 mov r0, r4
 *   @0xfdbdc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdbe0 mov r1, #4
 *   @0xfdbe4 mov r10, r0
 *   @0xfdbe8 mov r0, r4
 *   @0xfdbec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdbf0 mov r1, #5
 *   @0xfdbf4 mov r9, r0
 *   @0xfdbf8 mov r0, r4
 *   @0xfdbfc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdc00 mov r1, #6
 *   @0xfdc04 mov r8, r0
 *   @0xfdc08 mov r0, r4
 *   @0xfdc0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdc10 mov r1, #7
 *   @0xfdc14 mov r6, r0
 *   @0xfdc18 mov r0, r4
 *   @0xfdc1c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfdc20 cmp r5, #0
 *   @0xfdc24 mov r12, r0
 *   @0xfdc28 blt 0xfdc9c <_Z26F_DsGridMultiplyGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfdc2c ldr r2, [pc, #0x80]
 *   @0xfdc30 ldr r2, [pc, r2]
 *   @0xfdc34 ldr r3, [r2]
 *   @0xfdc38 cmp r5, r3
 *   @0xfdc3c bge 0xfdc9c <_Z26F_DsGridMultiplyGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfdc40 ldr r2, [pc, #0x70]
 *   @0xfdc44 ldr r2, [pc, r2]
 *   @0xfdc48 ldr r2, [r2, #0x4]
 *   @0xfdc4c ldr r0, [r2, r5, lsl #2]
 *   @0xfdc50 cmp r0, #0
 *   @0xfdc54 beq 0xfdc9c <_Z26F_DsGridMultiplyGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfdc58 cmp r11, #0
 *   @0xfdc5c blt 0xfdc9c <_Z26F_DsGridMultiplyGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfdc60 cmp r11, r3
 *   @0xfdc64 bge 0xfdc9c <_Z26F_DsGridMultiplyGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfdc68 ldr r2, [r2, r11, lsl #2]
 *   @0xfdc6c cmp r2, #0
 *   @0xfdc70 beq 0xfdc9c <_Z26F_DsGridMultiplyGridRegionR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xfdc74 str r10, [sp]
 *   @0xfdc78 mov r3, r7
 *   @0xfdc7c str r9, [sp, #0x4]
 *   @0xfdc80 mov r1, #3
 *   @0xfdc84 str r8, [sp, #0x8]
 *   @0xfdc88 str r6, [sp, #0xc]
 *   @0xfdc8c str r12, [sp, #0x10]
 *   @0xfdc90 bl 0x207fe8 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii>
 *   @0xfdc94 add sp, sp, #28
 *   @0xfdc98 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xfdc9c ldr r0, [pc, #0x18]
 *   @0xfdca0 mov r1, #0
 *   @0xfdca4 add r0, pc, r0
 *   @0xfdca8 add sp, sp, #28
 *   @0xfdcac pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfdcb0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfdcb4 eoreq r0, pc, r4, asr r2
 *   @0xfdcb8 eoreq r0, pc, r4, asr #4
 *   @0xfdcbc eoreq r9, r3, r8, asr pc
 *
 * ══ §47/102 F_DateDaysInMonth(RValue&, CInstance*, CInstance*, int, RValue*)  0x117ab0  size 296  74 条（0x117ab0..0x117bd8）
 * @func 0x117ab0 0x117bd8  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / is_leap_year(int) / 0xb682c / 0x82887c
 * 字段偏移 top8: 0x110×1 / 0xc×1 / 0x4×1 / 0x50×1 / 0x94×1 / 0x14×1 / 0x10×1 / 0x-30×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x117ab0 push {r4, r5, lr}
 *   @0x117ab4 mov r5, #0
 *   @0x117ab8 ldr lr, [pc, #0x110]
 *   @0x117abc mov r4, r0
 *   @0x117ac0 str r5, [r0, #0xc]
 *   @0x117ac4 sub sp, sp, #68
 *   @0x117ac8 add lr, pc, lr
 *   @0x117acc add r12, sp, #12
 *   @0x117ad0 str r5, [r4]
 *   @0x117ad4 ldm lr!, {r0, r1, r2, r3}
 *   @0x117ad8 str r5, [r4, #0x4]
 *   @0x117adc stm r12!, {r0, r1, r2, r3}
 *   @0x117ae0 ldm lr!, {r0, r1, r2, r3}
 *   @0x117ae4 stm r12!, {r0, r1, r2, r3}
 *   @0x117ae8 ldm lr!, {r0, r1, r2, r3}
 *   @0x117aec ldr lr, [lr]
 *   @0x117af0 stm r12!, {r0, r1, r2, r3}
 *   @0x117af4 mov r1, r5
 *   @0x117af8 ldr r0, [sp, #0x50]
 *   @0x117afc str lr, [r12]
 *   @0x117b00 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x117b04 vldr d7, [pc, #172]
 *   @0x117b08 vldr d5, [pc, #176]
 *   @0x117b0c vmov d6, r0, r1
 *   @0x117b10 vsub.f64 d7, d6, d7
 *   @0x117b14 vabs.f64 d4, d7
 *   @0x117b18 vcmpe.f64 d4, d5
 *   @0x117b1c vmrs APSR_nzcv, fpscr
 *   @0x117b20 vldrls d7, [pc, #160]
 *   @0x117b24 vldrhi d6, [pc, #156]
 *   @0x117b28 vmul.f64 d5, d7, d6
 *   @0x117b2c vmov r0, r1, d5
 *   @0x117b30 bl 0x3194a0 <__fixdfdi>
 *   @0x117b34 mov r3, r1
 *   @0x117b38 ldr r1, [pc, #0x94]
 *   @0x117b3c mov r2, r0
 *   @0x117b40 strd r2, r3, [sp]
 *   @0x117b44 add r1, pc, r1
 *   @0x117b48 mov r0, sp
 *   @0x117b4c ldrb r3, [r1]
 *   @0x117b50 cmp r3, #0
 *   @0x117b54 bne 0x117bac <_Z17F_DateDaysInMonthR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x117b58 bl 0xb6820 <gmtime64@plt>
 *   @0x117b5c mov r5, r0
 *   @0x117b60 cmp r5, #0
 *   @0x117b64 beq 0x117ba4 <_Z17F_DateDaysInMonthR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x117b68 ldr r0, [r5, #0x14]
 *   @0x117b6c add r0, r0, #1888
 *   @0x117b70 add r0, r0, #12
 *   @0x117b74 bl 0x117a5c <_Z12is_leap_yeari>
 *   @0x117b78 add r2, sp, #64
 *   @0x117b7c cmp r0, #0
 *   @0x117b80 movne r3, #29
 *   @0x117b84 strne r3, [sp, #0x14]
 *   @0x117b88 ldr r3, [r5, #0x10]
 *   @0x117b8c add r3, r2, r3, lsl #2
 *   @0x117b90 ldr r2, [r3, #-0x30]
 *   @0x117b94 vmov s11, r2
 *   @0x117b98 vcvt.f64.s32 d5, s11
 *   @0x117b9c vmov r2, r3, d5
 *   @0x117ba0 stm r4, {r2, r3}
 *   @0x117ba4 add sp, sp, #68
 *   @0x117ba8 pop {r4, r5, pc}
 *   @0x117bac bl 0xb682c <localtime64@plt>
 *   @0x117bb0 mov r5, r0
 *   @0x117bb4 b 0x117b60 <_Z17F_DateDaysInMonthR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x117bb8 andeq r0, r0, r0
 *   @0x117bbc sbcsmi pc, r8, r0, asr #16
 *   @0x117bc0 bl 0x82887c <b2_toiTime+0xcf3d8>
 *   @0x117bc4 svclo #0x1a36e2
 *   @0x117bc8 andeq r0, r0, r0
 *   @0x117bcc rscsmi r1, r5, r0, lsl #16
 *   @0x117bd0 eoreq r4, r4, r8, ror lr
 *   @0x117bd4 .word 0x002da5f4
 *
 * ══ §48/102 F_CollisionShape(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bf10  size 296  74 条（0x11bf10..0x11c038）
 * @func 0x11bf10 0x11c038  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×7 / YYGetInt32(RValue const*, int)×2 / Sprite_Exists(int) / Sprite_Data(int) / CSprite::Collision(int, float, float, float, float, float, float, float) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x18×2 / 0x1c×2 / 0x8×2 / 0xc×2 / 0x48×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bf10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11bf14 sub sp, sp, #36
 *   @0x11bf18 mov r1, #0
 *   @0x11bf1c mov r5, r0
 *   @0x11bf20 ldr r4, [sp, #0x48]
 *   @0x11bf24 mov r0, r4
 *   @0x11bf28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11bf2c mov r6, r0
 *   @0x11bf30 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x11bf34 subs r1, r0, #0
 *   @0x11bf38 beq 0x11c024 <_Z16F_CollisionShapeR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x11bf3c mov r0, r6
 *   @0x11bf40 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11bf44 mov r1, #1
 *   @0x11bf48 mov r6, r0
 *   @0x11bf4c mov r0, r4
 *   @0x11bf50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11bf54 mov r1, #2
 *   @0x11bf58 mov r9, r0
 *   @0x11bf5c mov r0, r4
 *   @0x11bf60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bf64 mov r1, #3
 *   @0x11bf68 mov r8, r0
 *   @0x11bf6c mov r0, r4
 *   @0x11bf70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bf74 mov r1, #4
 *   @0x11bf78 mov r7, r0
 *   @0x11bf7c mov r0, r4
 *   @0x11bf80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bf84 mov r1, #5
 *   @0x11bf88 mov r2, r0
 *   @0x11bf8c mov r0, r4
 *   @0x11bf90 str r2, [sp, #0x18]
 *   @0x11bf94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bf98 mov r1, #6
 *   @0x11bf9c mov r3, r0
 *   @0x11bfa0 mov r0, r4
 *   @0x11bfa4 str r3, [sp, #0x1c]
 *   @0x11bfa8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bfac mov r1, #7
 *   @0x11bfb0 mov r11, r0
 *   @0x11bfb4 mov r0, r4
 *   @0x11bfb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bfbc mov r1, #8
 *   @0x11bfc0 mov r10, r0
 *   @0x11bfc4 mov r0, r4
 *   @0x11bfc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11bfcc ldr r2, [sp, #0x18]
 *   @0x11bfd0 ldr r3, [sp, #0x1c]
 *   @0x11bfd4 mov r1, r9
 *   @0x11bfd8 str r11, [sp, #0x8]
 *   @0x11bfdc str r2, [sp]
 *   @0x11bfe0 mov r2, r8
 *   @0x11bfe4 str r3, [sp, #0x4]
 *   @0x11bfe8 mov r3, r7
 *   @0x11bfec str r10, [sp, #0xc]
 *   @0x11bff0 str r0, [sp, #0x10]
 *   @0x11bff4 mov r0, r6
 *   @0x11bff8 bl 0x1ed3d0 <_ZN7CSprite9CollisionEifffffff>
 *   @0x11bffc mov r3, #13
 *   @0x11c000 str r3, [r5, #0xc]
 *   @0x11c004 cmp r0, #0
 *   @0x11c008 movne r3, #0
 *   @0x11c00c moveq r3, r0
 *   @0x11c010 movne r0, r3
 *   @0x11c014 movtne r3, #0x3ff0
 *   @0x11c018 stm r5, {r0, r3}
 *   @0x11c01c add sp, sp, #36
 *   @0x11c020 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11c024 ldr r0, [pc, #0x8]
 *   @0x11c028 add r0, pc, r0
 *   @0x11c02c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11c030 b 0x11bf3c <_Z16F_CollisionShapeR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x11c034 eoreq sp, r1, r12, lsl #31
 *
 * ══ §49/102 F_DrawSurfacePartExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11eb0c  size 296  74 条（0x11eb0c..0x11ec34）
 * @func 0x11eb0c 0x11ec34  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×9 / YYGetInt32(RValue const*, int)×2 / YYGML_draw_surface_part_ext(int, float, float, float, float, float, float, float, float, int, float)
 * 字段偏移 top8: 0x24×2 / 0x28×2 / 0x2c×2 / 0xc×2 / 0x58×1 / 0x4×1 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11eb0c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11eb10 sub sp, sp, #52
 *   @0x11eb14 mov r1, #0
 *   @0x11eb18 ldr r4, [sp, #0x58]
 *   @0x11eb1c mov r0, r4
 *   @0x11eb20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11eb24 mov r1, #1
 *   @0x11eb28 mov r5, r0
 *   @0x11eb2c mov r0, r4
 *   @0x11eb30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eb34 mov r1, #2
 *   @0x11eb38 mov r8, r0
 *   @0x11eb3c mov r0, r4
 *   @0x11eb40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eb44 mov r1, #3
 *   @0x11eb48 mov r7, r0
 *   @0x11eb4c mov r0, r4
 *   @0x11eb50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eb54 mov r1, #4
 *   @0x11eb58 mov r6, r0
 *   @0x11eb5c mov r0, r4
 *   @0x11eb60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eb64 mov r1, #5
 *   @0x11eb68 mov r12, r0
 *   @0x11eb6c mov r0, r4
 *   @0x11eb70 str r12, [sp, #0x24]
 *   @0x11eb74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eb78 mov r1, #6
 *   @0x11eb7c mov r2, r0
 *   @0x11eb80 mov r0, r4
 *   @0x11eb84 str r2, [sp, #0x28]
 *   @0x11eb88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eb8c mov r1, #7
 *   @0x11eb90 mov r3, r0
 *   @0x11eb94 mov r0, r4
 *   @0x11eb98 str r3, [sp, #0x2c]
 *   @0x11eb9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eba0 mov r1, #8
 *   @0x11eba4 mov r11, r0
 *   @0x11eba8 mov r0, r4
 *   @0x11ebac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ebb0 mov r1, #9
 *   @0x11ebb4 mov r10, r0
 *   @0x11ebb8 mov r0, r4
 *   @0x11ebbc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ebc0 mov r1, #10
 *   @0x11ebc4 mov r9, r0
 *   @0x11ebc8 mov r0, r4
 *   @0x11ebcc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ebd0 ldr r2, [sp, #0x28]
 *   @0x11ebd4 ldr r3, [sp, #0x2c]
 *   @0x11ebd8 mov r1, r8
 *   @0x11ebdc ldr r12, [sp, #0x24]
 *   @0x11ebe0 str r2, [sp, #0x4]
 *   @0x11ebe4 mov r2, r7
 *   @0x11ebe8 str r3, [sp, #0x8]
 *   @0x11ebec mov r3, r6
 *   @0x11ebf0 str r12, [sp]
 *   @0x11ebf4 str r11, [sp, #0xc]
 *   @0x11ebf8 str r10, [sp, #0x10]
 *   @0x11ebfc str r9, [sp, #0x14]
 *   @0x11ec00 str r0, [sp, #0x18]
 *   @0x11ec04 mov r0, r5
 *   @0x11ec08 bl 0x171ee0 <_Z27YYGML_draw_surface_part_extiffffffffif>
 *   @0x11ec0c subs r1, r0, #0
 *   @0x11ec10 beq 0x11ec1c <_Z20F_DrawSurfacePartExtR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x11ec14 add sp, sp, #52
 *   @0x11ec18 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11ec1c ldr r0, [pc, #0xc]
 *   @0x11ec20 add r0, pc, r0
 *   @0x11ec24 add sp, sp, #52
 *   @0x11ec28 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11ec2c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11ec30 eoreq r11, r1, r8, asr #12
 *
 * ══ §50/102 F_FilenameDir(RValue&, CInstance*, CInstance*, int, RValue*)  0x139dd8  size 296  74 条（0x139dd8..0x139f00）
 * @func 0x139dd8 0x139f00  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ExtractFilePath(char const*)×2 / 0xb6538×2 / YYGetString(RValue const*, int) / F_FilenameDir(RValue&, CInstance*, CInstance*, int, RValue*)+0xa8 / F_FilenameDir(RValue&, CInstance*, CInstance*, int, RValue*)+0x78 / YYCreateString(RValue*, char const*) / YYFree(void const*) / LoadSave::SaveFileExists(char const*)
 * 字段偏移 top8: 0x404×2 / 0x110×1 / 0x420×1 / 0xc×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139dd8 push {r4, r5, r6, r7, lr}
 *   @0x139ddc sub sp, sp, #1024
 *   @0x139de0 ldr r4, [pc, #0x110]
 *   @0x139de4 sub sp, sp, #12
 *   @0x139de8 mov r5, r0
 *   @0x139dec mov r1, #0
 *   @0x139df0 ldr r4, [pc, r4]
 *   @0x139df4 ldr r0, [sp, #0x420]
 *   @0x139df8 ldr r3, [r4]
 *   @0x139dfc str r3, [sp, #0x404]
 *   @0x139e00 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x139e04 mov r3, #0
 *   @0x139e08 mov r1, #1
 *   @0x139e0c str r3, [r5]
 *   @0x139e10 str r1, [r5, #0xc]
 *   @0x139e14 subs r7, r0, #0
 *   @0x139e18 beq 0x139ebc <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x139e1c bl 0x214f5c <_Z15ExtractFilePathPKc>
 *   @0x139e20 subs r6, r0, #0
 *   @0x139e24 beq 0x139e64 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x139e28 bl 0xb6538 <strlen@plt>
 *   @0x139e2c subs r0, r0, #1
 *   @0x139e30 blo 0x139e80 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x139e34 cmp r0, #0
 *   @0x139e38 ble 0x139e50 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x139e3c ldrb r2, [r6, r0]
 *   @0x139e40 cmp r2, #92
 *   @0x139e44 cmpne r2, #47
 *   @0x139e48 moveq r2, #0
 *   @0x139e4c strbeq r2, [r6, r0]
 *   @0x139e50 mov r0, r5
 *   @0x139e54 mov r1, r6
 *   @0x139e58 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x139e5c mov r0, r6
 *   @0x139e60 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x139e64 ldr r2, [sp, #0x404]
 *   @0x139e68 ldr r3, [r4]
 *   @0x139e6c cmp r2, r3
 *   @0x139e70 bne 0x139ef4 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x139e74 add sp, sp, #1024
 *   @0x139e78 add sp, sp, #12
 *   @0x139e7c pop {r4, r5, r6, r7, pc}
 *   @0x139e80 mov r0, r7
 *   @0x139e84 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x139e88 cmp r0, #0
 *   @0x139e8c beq 0x139ecc <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x139e90 add r6, sp, #4
 *   @0x139e94 mov r2, r7
 *   @0x139e98 mov r1, #1024
 *   @0x139e9c mov r0, r6
 *   @0x139ea0 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x139ea4 mov r0, r6
 *   @0x139ea8 bl 0x214f5c <_Z15ExtractFilePathPKc>
 *   @0x139eac mov r6, r0
 *   @0x139eb0 bl 0xb6538 <strlen@plt>
 *   @0x139eb4 sub r0, r0, #1
 *   @0x139eb8 b 0x139e34 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x139ebc ldr r0, [pc, #0x38]
 *   @0x139ec0 add r0, pc, r0
 *   @0x139ec4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139ec8 b 0x139e64 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x139ecc mov r0, r7
 *   @0x139ed0 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x139ed4 cmp r0, #0
 *   @0x139ed8 beq 0x139e50 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x139edc add r6, sp, #4
 *   @0x139ee0 mov r2, r7
 *   @0x139ee4 mov r1, #1024
 *   @0x139ee8 mov r0, r6
 *   @0x139eec bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x139ef0 b 0x139ea4 <_Z13F_FilenameDirR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x139ef4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x139ef8 eoreq r3, r11, r0, ror #22
 *   @0x139efc eoreq r6, r0, r0, ror #6
 *
 * ══ §51/102 OLD_FUNC_Load(unsigned char*, unsigned int, unsigned char*)  0x1dccc8  size 296  74 条（0x1dccc8..0x1dcdf0）
 * @func 0x1dccc8 0x1dcdf0  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Function_Find(char const*, int*) / OLD_FUNC_Load(unsigned char*, unsigned int, unsigned char*)+0xd0 / OLD_FUNC_Load(unsigned char*, unsigned int, unsigned char*)+0xa8 / 0xb65c8 / Error_Show(char const*, bool) / YYGML_game_end() / 0xb65d4 / 0xb6688
 * 字段偏移 top8: 0x404×2 / 0x108×1 / 0x104×1 / 0x4×1 / 0x8×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dccc8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1dcccc sub sp, sp, #1024
 *   @0x1dccd0 ldr r8, [pc, #0x108]
 *   @0x1dccd4 sub sp, sp, #12
 *   @0x1dccd8 ldr r9, [pc, #0x104]
 *   @0x1dccdc subs r10, r1, #0
 *   @0x1dcce0 ldr r8, [pc, r8]
 *   @0x1dcce4 add r7, sp, #4
 *   @0x1dcce8 add r9, pc, r9
 *   @0x1dccec mov r5, r0
 *   @0x1dccf0 ldr r3, [r8]
 *   @0x1dccf4 mov r4, r2
 *   @0x1dccf8 str r3, [sp, #0x404]
 *   @0x1dccfc beq 0x1dcd78 <_Z13OLD_FUNC_LoadPhjS_+0xb0>
 *   @0x1dcd00 ldr r0, [r5]
 *   @0x1dcd04 cmp r0, #0
 *   @0x1dcd08 moveq r11, r0
 *   @0x1dcd0c ldrne r3, [pc, #0xd4]
 *   @0x1dcd10 ldrne r3, [pc, r3]
 *   @0x1dcd14 ldrne r11, [r3]
 *   @0x1dcd18 addne r11, r11, r0
 *   @0x1dcd1c mov r0, r11
 *   @0x1dcd20 mov r1, sp
 *   @0x1dcd24 bl 0xce158 <_Z18Code_Function_FindPKcPi>
 *   @0x1dcd28 ldr r3, [sp]
 *   @0x1dcd2c cmp r3, #0
 *   @0x1dcd30 blt 0x1dcd98 <_Z13OLD_FUNC_LoadPhjS_+0xd0>
 *   @0x1dcd34 ldr r0, [r5, #0x4]
 *   @0x1dcd38 sub r10, r10, #12
 *   @0x1dcd3c ldr r3, [r5, #0x8]
 *   @0x1dcd40 add r5, r5, #12
 *   @0x1dcd44 cmp r0, #0
 *   @0x1dcd48 ldrgt r11, [sp]
 *   @0x1dcd4c movgt r12, #0
 *   @0x1dcd50 ble 0x1dcd70 <_Z13OLD_FUNC_LoadPhjS_+0xa8>
 *   @0x1dcd54 add r2, r3, #4
 *   @0x1dcd58 add r12, r12, #1
 *   @0x1dcd5c cmp r12, r0
 *   @0x1dcd60 ldr r1, [r4, r2]
 *   @0x1dcd64 str r11, [r4, r2]
 *   @0x1dcd68 add r3, r3, r1
 *   @0x1dcd6c bne 0x1dcd54 <_Z13OLD_FUNC_LoadPhjS_+0x8c>
 *   @0x1dcd70 cmp r10, #0
 *   @0x1dcd74 bne 0x1dcd00 <_Z13OLD_FUNC_LoadPhjS_+0x38>
 *   @0x1dcd78 ldr r2, [sp, #0x404]
 *   @0x1dcd7c mov r0, #1
 *   @0x1dcd80 ldr r3, [r8]
 *   @0x1dcd84 cmp r2, r3
 *   @0x1dcd88 bne 0x1dcdd4 <_Z13OLD_FUNC_LoadPhjS_+0x10c>
 *   @0x1dcd8c add sp, sp, #1024
 *   @0x1dcd90 add sp, sp, #12
 *   @0x1dcd94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1dcd98 mov r3, r11
 *   @0x1dcd9c mov r1, #1024
 *   @0x1dcda0 mov r2, r9
 *   @0x1dcda4 mov r0, r7
 *   @0x1dcda8 bl 0xb65c8 <snprintf@plt>
 *   @0x1dcdac mov r0, r7
 *   @0x1dcdb0 mov r1, #1
 *   @0x1dcdb4 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1dcdb8 ldr r3, [pc, #0x2c]
 *   @0x1dcdbc ldr r3, [pc, r3]
 *   @0x1dcdc0 ldrb r3, [r3]
 *   @0x1dcdc4 cmp r3, #0
 *   @0x1dcdc8 beq 0x1dcdd8 <_Z13OLD_FUNC_LoadPhjS_+0x110>
 *   @0x1dcdcc bl 0x10c320 <_Z14YYGML_game_endv>
 *   @0x1dcdd0 b 0x1dcd34 <_Z13OLD_FUNC_LoadPhjS_+0x6c>
 *   @0x1dcdd4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1dcdd8 mov r0, #1
 *   @0x1dcddc bl 0xb6688 <exit@plt>
 *   @0x1dcde0 eoreq r0, r1, r0, ror r12
 *   @0x1dcde4 andseq r4, r7, r4, lsr r10
 *   @0x1dcde8 eoreq r0, r1, r4, lsr r12
 *   @0x1dcdec eoreq r0, r1, r4, ror lr
 *
 * ══ §52/102 FINALIZE_VertexFormats()  0x1e3180  size 296  74 条（0x1e3180..0x1e32a8）
 * @func 0x1e3180 0x1e32a8  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush() / FINALIZE_VertexFormats()+0x9c / FreeVertexFormat(VertexFormat*) / FINALIZE_VertexFormats()+0x7c / FINALIZE_VertexFormats()+0x104 / operator delete(void*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×5 / 0xc×3 / 0x8×3 / 0x10c×1 / 0x3×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e3180 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1e3184 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1e3188 mov r3, #0
 *   @0x1e318c ldr r6, [pc, #0x10c]
 *   @0x1e3190 ldr r6, [pc, r6]
 *   @0x1e3194 ldm r6, {r2, r8}
 *   @0x1e3198 b 0x1e31a4 <_Z22FINALIZE_VertexFormatsv+0x24>
 *   @0x1e319c cmp r8, r3
 *   @0x1e31a0 blt 0x1e321c <_Z22FINALIZE_VertexFormatsv+0x9c>
 *   @0x1e31a4 ldr r4, [r2, r3, lsl #3]
 *   @0x1e31a8 mov r5, r3
 *   @0x1e31ac add r3, r3, #1
 *   @0x1e31b0 cmp r4, #0
 *   @0x1e31b4 beq 0x1e319c <_Z22FINALIZE_VertexFormatsv+0x1c>
 *   @0x1e31b8 ldr r0, [r4, #0xc]
 *   @0x1e31bc cmp r0, #0
 *   @0x1e31c0 bne 0x1e31d4 <_Z22FINALIZE_VertexFormatsv+0x54>
 *   @0x1e31c4 b 0x1e321c <_Z22FINALIZE_VertexFormatsv+0x9c>
 *   @0x1e31c8 ldr r0, [r4, #0xc]
 *   @0x1e31cc cmp r0, #0
 *   @0x1e31d0 beq 0x1e3298 <_Z22FINALIZE_VertexFormatsv+0x118>
 *   @0x1e31d4 bl 0x185640 <_Z16FreeVertexFormatP12VertexFormat>
 *   @0x1e31d8 ldr r4, [r4, #0x4]
 *   @0x1e31dc cmp r4, #0
 *   @0x1e31e0 bne 0x1e31c8 <_Z22FINALIZE_VertexFormatsv+0x48>
 *   @0x1e31e4 ldr r8, [r6, #0x4]
 *   @0x1e31e8 add r3, r5, #1
 *   @0x1e31ec cmp r3, r8
 *   @0x1e31f0 bgt 0x1e321c <_Z22FINALIZE_VertexFormatsv+0x9c>
 *   @0x1e31f4 ldr r2, [r6]
 *   @0x1e31f8 add r2, r2, r5, lsl #3
 *   @0x1e31fc ldr r4, [r2, #0x8]
 *   @0x1e3200 mov r5, r3
 *   @0x1e3204 add r2, r2, #8
 *   @0x1e3208 add r3, r3, #1
 *   @0x1e320c cmp r4, #0
 *   @0x1e3210 bne 0x1e31c8 <_Z22FINALIZE_VertexFormatsv+0x48>
 *   @0x1e3214 cmp r3, r8
 *   @0x1e3218 ble 0x1e31fc <_Z22FINALIZE_VertexFormatsv+0x7c>
 *   @0x1e321c cmp r8, #0
 *   @0x1e3220 lslge r7, r8, #3
 *   @0x1e3224 movge r9, #0
 *   @0x1e3228 blt 0x1e3284 <_Z22FINALIZE_VertexFormatsv+0x104>
 *   @0x1e322c ldr r3, [r6]
 *   @0x1e3230 add r2, r3, r7
 *   @0x1e3234 ldr r4, [r3, r7]
 *   @0x1e3238 str r9, [r3, r7]
 *   @0x1e323c cmp r4, #0
 *   @0x1e3240 str r9, [r2, #0x4]
 *   @0x1e3244 beq 0x1e3274 <_Z22FINALIZE_VertexFormatsv+0xf4>
 *   @0x1e3248 ldr r5, [r4, #0x4]
 *   @0x1e324c ldr r0, [r4, #0xc]
 *   @0x1e3250 bl 0x27d1d0 <_ZdlPv>
 *   @0x1e3254 mov r0, r4
 *   @0x1e3258 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e325c ldr r3, [r6, #0x8]
 *   @0x1e3260 cmp r5, #0
 *   @0x1e3264 mov r4, r5
 *   @0x1e3268 sub r3, r3, #1
 *   @0x1e326c str r3, [r6, #0x8]
 *   @0x1e3270 bne 0x1e3248 <_Z22FINALIZE_VertexFormatsv+0xc8>
 *   @0x1e3274 sub r8, r8, #1
 *   @0x1e3278 sub r7, r7, #8
 *   @0x1e327c cmn r8, #1
 *   @0x1e3280 bne 0x1e322c <_Z22FINALIZE_VertexFormatsv+0xac>
 *   @0x1e3284 ldr r3, [pc, #0x18]
 *   @0x1e3288 mov r2, #0
 *   @0x1e328c ldr r3, [pc, r3]
 *   @0x1e3290 str r2, [r3]
 *   @0x1e3294 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1e3298 ldr r8, [r6, #0x4]
 *   @0x1e329c b 0x1e321c <_Z22FINALIZE_VertexFormatsv+0x9c>
 *   @0x1e32a0 eoreq sp, r0, r12, lsl #24
 *   @0x1e32a4 eoreq sp, r0, r12, lsl #22
 *
 * ══ §53/102 CSprite::SetupSWFCollisionMasks(unsigned char**, int*, int)  0x1e8264  size 296  74 条（0x1e8264..0x1e838c）
 * @func 0x1e8264 0x1e838c  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / CSprite::SetupSWFCollisionMasks(unsigned char**, int*, int)+0x110 / CSprite::SetupSWFCollisionMasks(unsigned char**, int*, int)+0x104 / CSprite::FreeMask()
 * 字段偏移 top8: 0x31×2 / 0x1c×2 / 0x20×2 / 0x40×2 / 0x30×1 / 0xdc×1 / 0x3c×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e8264 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1e8268 subs r8, r1, #0
 *   @0x1e826c mov r7, r2
 *   @0x1e8270 mov r4, r3
 *   @0x1e8274 mov r9, r0
 *   @0x1e8278 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1e827c cmp r2, #0
 *   @0x1e8280 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1e8284 ldrb r3, [r0, #0x31]
 *   @0x1e8288 cmp r3, #0
 *   @0x1e828c bne 0x1e8380 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0x11c>
 *   @0x1e8290 ldrb r3, [r9, #0x30]
 *   @0x1e8294 cmp r3, #0
 *   @0x1e8298 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1e829c cmp r4, #0
 *   @0x1e82a0 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1e82a4 ldr r5, [pc, #0xdc]
 *   @0x1e82a8 add r0, r9, #64
 *   @0x1e82ac lsl r1, r4, #3
 *   @0x1e82b0 movw r3, #0xf82
 *   @0x1e82b4 add r5, pc, r5
 *   @0x1e82b8 mov r2, r5
 *   @0x1e82bc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e82c0 cmp r4, #0
 *   @0x1e82c4 str r4, [r9, #0x3c]
 *   @0x1e82c8 ble 0x1e8374 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0x110>
 *   @0x1e82cc ldr r3, [r9, #0x1c]
 *   @0x1e82d0 mov r10, #0
 *   @0x1e82d4 ldr r1, [r9, #0x20]
 *   @0x1e82d8 ldr r0, [r9, #0x40]
 *   @0x1e82dc mul r1, r1, r3
 *   @0x1e82e0 add r0, r0, r10, lsl #3
 *   @0x1e82e4 movw r3, #0xf86
 *   @0x1e82e8 add r0, r0, #4
 *   @0x1e82ec mov r2, r5
 *   @0x1e82f0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e82f4 ldr r3, [r9, #0x1c]
 *   @0x1e82f8 ldr r1, [r9, #0x20]
 *   @0x1e82fc ldr r0, [r9, #0x40]
 *   @0x1e8300 mul r1, r1, r3
 *   @0x1e8304 str r1, [r0, r10, lsl #3]
 *   @0x1e8308 add r10, r10, #1
 *   @0x1e830c cmp r10, r4
 *   @0x1e8310 bne 0x1e82e0 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0x7c>
 *   @0x1e8314 lsl r10, r10, #2
 *   @0x1e8318 mov r1, #0
 *   @0x1e831c ldr r2, [r7, r1]
 *   @0x1e8320 add r3, r0, r1, lsl #1
 *   @0x1e8324 ldr r6, [r8, r1]
 *   @0x1e8328 cmp r2, #0
 *   @0x1e832c ldr r12, [r3, #0x4]
 *   @0x1e8330 addgt r2, r6, r2
 *   @0x1e8334 ble 0x1e8368 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0x104>
 *   @0x1e8338 ldrb r5, [r6], #1
 *   @0x1e833c mov r3, #0
 *   @0x1e8340 and r4, r5, #127
 *   @0x1e8344 lsr r5, r5, #7
 *   @0x1e8348 strb r5, [r12, r3]
 *   @0x1e834c add r3, r3, #1
 *   @0x1e8350 cmp r4, r3
 *   @0x1e8354 bge 0x1e8348 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0xe4>
 *   @0x1e8358 cmp r6, r2
 *   @0x1e835c add r4, r4, #1
 *   @0x1e8360 add r12, r12, r4
 *   @0x1e8364 bne 0x1e8338 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0xd4>
 *   @0x1e8368 add r1, r1, #4
 *   @0x1e836c cmp r1, r10
 *   @0x1e8370 bne 0x1e831c <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0xb8>
 *   @0x1e8374 mov r3, #1
 *   @0x1e8378 strb r3, [r9, #0x31]
 *   @0x1e837c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1e8380 bl 0x1e3b58 <_ZN7CSprite8FreeMaskEv>
 *   @0x1e8384 b 0x1e8290 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii+0x2c>
 *   @0x1e8388 andseq r10, r6, r0, ror r1
 *
 * ══ §54/102 CTimeLine::Clear()  0x1f1768  size 296  74 条（0x1f1768..0x1f1890）
 * @func 0x1f1768 0x1f1890  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×4 / CTimeLine::Clear()+0x38 / CTimeLine::Clear()+0xd0 / CTimeLine::Clear()+0x68
 * 字段偏移 top8: 0xc×6 / 0x8×3 / 0x14×3 / 0x2×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f1768 ldr r12, [r0, #0x8]
 *   @0x1f176c push {r4, r5, r6, r7, r8, lr}
 *   @0x1f1770 subs r3, r12, #1
 *   @0x1f1774 mov r5, r0
 *   @0x1f1778 lslpl r2, r3, #2
 *   @0x1f177c movpl lr, #0
 *   @0x1f1780 bmi 0x1f17ac <_ZN9CTimeLine5ClearEv+0x44>
 *   @0x1f1784 cmp r12, r3
 *   @0x1f1788 sub r3, r3, #1
 *   @0x1f178c ble 0x1f17a0 <_ZN9CTimeLine5ClearEv+0x38>
 *   @0x1f1790 ldr r1, [r5, #0xc]
 *   @0x1f1794 ldr r0, [r1, r2]
 *   @0x1f1798 tst r0, #1
 *   @0x1f179c strne lr, [r1, r2]
 *   @0x1f17a0 cmn r3, #1
 *   @0x1f17a4 sub r2, r2, #4
 *   @0x1f17a8 bne 0x1f1784 <_ZN9CTimeLine5ClearEv+0x1c>
 *   @0x1f17ac cmp r12, #0
 *   @0x1f17b0 beq 0x1f1850 <_ZN9CTimeLine5ClearEv+0xe8>
 *   @0x1f17b4 ldr r6, [r5, #0xc]
 *   @0x1f17b8 cmp r6, #0
 *   @0x1f17bc beq 0x1f1880 <_ZN9CTimeLine5ClearEv+0x118>
 *   @0x1f17c0 cmp r12, #0
 *   @0x1f17c4 ble 0x1f1838 <_ZN9CTimeLine5ClearEv+0xd0>
 *   @0x1f17c8 mov r4, #0
 *   @0x1f17cc mov r8, r4
 *   @0x1f17d0 ldr r1, [r6]
 *   @0x1f17d4 movw r3, #0xfeee
 *   @0x1f17d8 movt r3, #0xfeee
 *   @0x1f17dc movw r2, #0xfeee
 *   @0x1f17e0 cmp r1, r3
 *   @0x1f17e4 movt r2, #0xfeee
 *   @0x1f17e8 lsl r7, r4, #2
 *   @0x1f17ec beq 0x1f1828 <_ZN9CTimeLine5ClearEv+0xc0>
 *   @0x1f17f0 ldr r3, [r6, r4, lsl #2]
 *   @0x1f17f4 add r1, r6, r7
 *   @0x1f17f8 cmp r3, #0
 *   @0x1f17fc mov r0, r3
 *   @0x1f1800 beq 0x1f1828 <_ZN9CTimeLine5ClearEv+0xc0>
 *   @0x1f1804 ldr r3, [r3]
 *   @0x1f1808 cmp r3, r2
 *   @0x1f180c beq 0x1f1820 <_ZN9CTimeLine5ClearEv+0xb8>
 *   @0x1f1810 ldr r3, [r3, #0x4]
 *   @0x1f1814 blx r3
 *   @0x1f1818 ldr r1, [r5, #0xc]
 *   @0x1f181c add r1, r1, r7
 *   @0x1f1820 str r8, [r1]
 *   @0x1f1824 ldr r6, [r5, #0xc]
 *   @0x1f1828 ldr r3, [r5, #0x8]
 *   @0x1f182c add r4, r4, #1
 *   @0x1f1830 cmp r4, r3
 *   @0x1f1834 blt 0x1f17d0 <_ZN9CTimeLine5ClearEv+0x68>
 *   @0x1f1838 mov r0, r6
 *   @0x1f183c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1840 mov r3, #0
 *   @0x1f1844 str r3, [r5, #0xc]
 *   @0x1f1848 mov r3, #0
 *   @0x1f184c str r3, [r5, #0x8]
 *   @0x1f1850 ldr r4, [r5, #0x14]
 *   @0x1f1854 subs r0, r4, #0
 *   @0x1f1858 beq 0x1f1874 <_ZN9CTimeLine5ClearEv+0x10c>
 *   @0x1f185c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1860 mov r3, #0
 *   @0x1f1864 str r3, [r5, #0x14]
 *   @0x1f1868 mov r3, #0
 *   @0x1f186c str r3, [r5, #0x10]
 *   @0x1f1870 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f1874 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1878 str r4, [r5, #0x14]
 *   @0x1f187c b 0x1f1868 <_ZN9CTimeLine5ClearEv+0x100>
 *   @0x1f1880 mov r0, r6
 *   @0x1f1884 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1888 str r6, [r5, #0xc]
 *   @0x1f188c b 0x1f1848 <_ZN9CTimeLine5ClearEv+0xe0>
 *
 * ══ §55/102 CDS_Grid::ReadFromString(char const*, bool)  0x20b138  size 296  74 条（0x20b138..0x20b260）
 * @func 0x20b138 0x20b260  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×3 / CStream::~CStream()×2 / operator delete(void*)×2 / operator new(unsigned int) / CStream::CStream(int) / CStream::ConvertFromString(char const*) / CDS_Grid::ReadFromString(char const*, bool)+0x70 / CDS_Grid::SetSize(int, int)
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20b138 push {r4, r5, r6, r7, r8, lr}
 *   @0x20b13c mov r5, r0
 *   @0x20b140 mov r0, #32
 *   @0x20b144 mov r4, r1
 *   @0x20b148 mov r7, r2
 *   @0x20b14c bl 0x27c524 <_Znwj>
 *   @0x20b150 mov r1, #0
 *   @0x20b154 mov r6, r0
 *   @0x20b158 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x20b15c mov r1, r4
 *   @0x20b160 mov r0, r6
 *   @0x20b164 bl 0x2025b0 <_ZN7CStream17ConvertFromStringEPKc>
 *   @0x20b168 mov r0, r6
 *   @0x20b16c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20b170 sub r3, r0, #600
 *   @0x20b174 mov r4, r0
 *   @0x20b178 sub r3, r3, #1
 *   @0x20b17c mov r0, r6
 *   @0x20b180 cmp r3, #1
 *   @0x20b184 bls 0x20b1a8 <_ZN8CDS_Grid14ReadFromStringEPKcb+0x70>
 *   @0x20b188 cmp r6, #0
 *   @0x20b18c beq 0x20b1a4 <_ZN8CDS_Grid14ReadFromStringEPKcb+0x6c>
 *   @0x20b190 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x20b194 mov r0, r6
 *   @0x20b198 bl 0x27d1d0 <_ZdlPv>
 *   @0x20b19c mov r0, #0
 *   @0x20b1a0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x20b1a4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x20b1a8 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20b1ac mov r8, r0
 *   @0x20b1b0 mov r0, r6
 *   @0x20b1b4 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20b1b8 mov r1, r8
 *   @0x20b1bc mov r2, r0
 *   @0x20b1c0 mov r0, r5
 *   @0x20b1c4 bl 0x20affc <_ZN8CDS_Grid7SetSizeEii>
 *   @0x20b1c8 cmp r7, #0
 *   @0x20b1cc movne r8, #1
 *   @0x20b1d0 bne 0x20b1e4 <_ZN8CDS_Grid14ReadFromStringEPKcb+0xac>
 *   @0x20b1d4 movw r8, #0x259
 *   @0x20b1d8 cmp r4, r8
 *   @0x20b1dc moveq r8, #2
 *   @0x20b1e0 movne r8, #0
 *   @0x20b1e4 ldr r3, [r5, #0x4]
 *   @0x20b1e8 cmp r3, #0
 *   @0x20b1ec ble 0x20b238 <_ZN8CDS_Grid14ReadFromStringEPKcb+0x100>
 *   @0x20b1f0 ldr r12, [r5, #0x8]
 *   @0x20b1f4 mov r7, #0
 *   @0x20b1f8 cmp r12, #0
 *   @0x20b1fc ble 0x20b22c <_ZN8CDS_Grid14ReadFromStringEPKcb+0xf4>
 *   @0x20b200 mov r4, #0
 *   @0x20b204 mla r3, r3, r4, r7
 *   @0x20b208 ldr r0, [r5]
 *   @0x20b20c mov r1, r6
 *   @0x20b210 mov r2, r8
 *   @0x20b214 add r4, r4, #1
 *   @0x20b218 add r0, r0, r3, lsl #4
 *   @0x20b21c bl 0x208638 <_Z9ReadValueR6RValueR7CStreami>
 *   @0x20b220 ldmib r5, {r3, r12}
 *   @0x20b224 cmp r12, r4
 *   @0x20b228 bgt 0x20b204 <_ZN8CDS_Grid14ReadFromStringEPKcb+0xcc>
 *   @0x20b22c add r7, r7, #1
 *   @0x20b230 cmp r7, r3
 *   @0x20b234 blt 0x20b1f8 <_ZN8CDS_Grid14ReadFromStringEPKcb+0xc0>
 *   @0x20b238 cmp r6, #0
 *   @0x20b23c beq 0x20b258 <_ZN8CDS_Grid14ReadFromStringEPKcb+0x120>
 *   @0x20b240 mov r0, r6
 *   @0x20b244 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x20b248 mov r0, r6
 *   @0x20b24c bl 0x27d1d0 <_ZdlPv>
 *   @0x20b250 mov r0, #1
 *   @0x20b254 pop {r4, r5, r6, r7, r8, pc}
 *   @0x20b258 mov r0, #1
 *   @0x20b25c pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §56/102 png_handle_gAMA  0x2ac110  size 296  74 条（0x2ac110..0x2ac238）
 * @func 0x2ac110 0x2ac238  size 296  74 条
 * 部分覆盖: 本节 74/126 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning×4 / png_crc_finish×2 / png_error / png_crc_read / 0xff4bce78 / png_handle_gAMA+0xcc / png_set_gAMA
 * 字段偏移 top8: 0x8×2 / 0xf0×1 / 0xe0×1 / 0xcc×1 / 0x64×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ac110 push {r0, r1, r4, r5, r6, lr}
 *   @0x2ac114 ldr.w r3, [r0, #0x12c]
 *   @0x2ac118 mov r4, r0
 *   @0x2ac11c lsls r2, r3, #0x1f
 *   @0x2ac120 ldr r1, [pc, #0xf0]
 *   @0x2ac124 bl 0x2a642c <png_error>
 *   @0x2ac128 b 0x2ac140 <png_handle_gAMA+0x30>
 *   @0x2ac12c bpl 0x2ac134 <png_handle_gAMA+0x24>
 *   @0x2ac130 add r1, pc
 *   @0x2ac134 lsls r2, r3, #0x1e
 *   @0x2ac138 ldr r1, [pc, #0xe0]
 *   @0x2ac13c bl 0x2a6474 <png_warning>
 *   @0x2ac140 mov r0, r4
 *   @0x2ac144 ldr r2, [r5, #0x8]
 *   @0x2ac148 andsmi r0, r3, r1, lsl #6
 *   @0x2ac14c cmp r3, #0x1
 *   @0x2ac150 ldr r1, [pc, #0xcc]
 *   @0x2ac154 bl 0x2a6474 <png_warning>
 *   @0x2ac158 mov r0, r4
 *   @0x2ac15c bl 0x2abc94 <png_crc_finish>
 *   @0x2ac160 b 0x2ac20a <png_handle_gAMA+0xfa>
 *   @0x2ac164 beq 0x2ac16c <png_handle_gAMA+0x5c>
 *   @0x2ac168 add r1, pc
 *   @0x2ac16c add r1, sp, #0x4
 *   @0x2ac170 bl 0x2abc0c <png_crc_read>
 *   @0x2ac174 mov r0, r4
 *   @0x2ac178 bl 0x2abc94 <png_crc_finish>
 *   @0x2ac17c cmp r0, #0x0
 *   @0x2ac180 ldrb.w r6, [sp, #0x5]
 *   @0x2ac184 ldrb.w r3, [sp, #0x4]
 *   @0x2ac188 lsls r6, r6, #0x10
 *   @0x2ac18c .word 0xf89d6603
 *   @0x2ac190 ldrmi r3, [lr], #-7
 *   @0x2ac194 ldrb.w r3, [sp, #0x6]
 *   @0x2ac198 adds.w r6, r6, r3, lsl #8
 *   @0x2ac19c bne 0x2ac1aa <png_handle_gAMA+0x9a>
 *   @0x2ac1a0 mov r0, r4
 *   @0x2ac1a4 bl 0x2a6474 <png_warning>
 *   @0x2ac1a8 b 0x2ac20a <png_handle_gAMA+0xfa>
 *   @0x2ac1ac ldr r3, [r5, #0x8]
 *   @0x2ac1b0 bpl 0x2ac1dc <png_handle_gAMA+0xcc>
 *   @0x2ac1b4 bllo 0xff4bce78 <b2_toiTime+0xfffffffffed639d4>
 *   @0x2ac1b8 cmp.w r3, #0x3e8
 *   @0x2ac1bc bls 0x2ac1dc <png_handle_gAMA+0xcc>
 *   @0x2ac1c0 mov r0, r4
 *   @0x2ac1c4 bl 0x2a6474 <png_warning>
 *   @0x2ac1c8 ldr r0, [pc, #0x64]
 *   @0x2ac1cc mov r2, r6
 *   @0x2ac1d0 ldr r0, [r0]
 *   @0x2ac1d4 adds r0, #0xa8
 *   @0x2ac1d8 ands lr, r6, r6, ror #22
 *   @0x2ac1dc vmov s12, r6
 *   @0x2ac1e0 vldr s15, [pc, #44]
 *   @0x2ac1e4 mov r0, r4
 *   @0x2ac1e8 vcvt.f32.s32 s14, s12
 *   @0x2ac1ec vdiv.f32 s15, s14, s15
 *   @0x2ac1f0 vcvt.f64.f32 d6, s15
 *   @0x2ac1f4 vstr s15, [r4, #544]
 *   @0x2ac1f8 vmov r2, r3, d6
 *   @0x2ac1fc bl 0x2ae8f8 <png_set_gAMA>
 *   @0x2ac200 mov r0, r4
 *   @0x2ac204 mov r2, r6
 *   @0x2ac208 strhlt pc, [r2], -pc
 *   @0x2ac20c pop {r4, r5, r6, pc}
 *   @0x2ac210 str r0, [r0, r0]
 *   @0x2ac214 lsrs r2, r7, #0x11
 *   @0x2ac218 lsrs r5, r0, #0x12
 *   @0x2ac21c lsrs r3, r2, #0x12
 *   @0x2ac220 lsrs r3, r2, #0x12
 *   @0x2ac224 lsrs r2, r2, #0x12
 *   @0x2ac228 lsrs r4, r6, #0x11
 *   @0x2ac22c lsrs r5, r6, #0x11
 *   @0x2ac230 strh r2, [r7, r1]
 *   @0x2ac234 lsrs r5, r3, #0x12
 *
 * ══ §57/102 b2Body::SetMassData(b2MassData const*)  0x2c7030  size 296  74 条（0x2c7030..0x2c7158）
 * @func 0x2c7030 0x2c7158  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Body::SetMassData(b2MassData const*)+0xa4
 * 字段偏移 top8: 0x68×1 / 0x88×1 / 0x8c×1 / 0x90×1 / 0x4×1
 * VFP 指令 48 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7030 mov r3, r0
 *   @0x2c7034 ldr r0, [r0, #0x68]
 *   @0x2c7038 movw r2, #0x91d4
 *   @0x2c703c movt r2, #0x1
 *   @0x2c7040 ldr r2, [r0, r2]
 *   @0x2c7044 tst r2, #2
 *   @0x2c7048 bxne lr
 *   @0x2c704c ldr r2, [r3]
 *   @0x2c7050 cmp r2, #2
 *   @0x2c7054 bxne lr
 *   @0x2c7058 vmov.f32 s14, #1.000000e+00
 *   @0x2c705c vldr s15, [r1]
 *   @0x2c7060 mov r2, #0
 *   @0x2c7064 str r2, [r3, #0x88]
 *   @0x2c7068 str r2, [r3, #0x8c]
 *   @0x2c706c str r2, [r3, #0x90]
 *   @0x2c7070 vcmpe.f32 s15, #0
 *   @0x2c7074 vmrs APSR_nzcv, fpscr
 *   @0x2c7078 vstrhi s15, [r3, #132]
 *   @0x2c707c vmovhi.f32 s13, s15
 *   @0x2c7080 vstrls s14, [r3, #132]
 *   @0x2c7084 vdivhi.f32 s15, s14, s15
 *   @0x2c7088 vmovls.f32 s15, s14
 *   @0x2c708c vldr s14, [r1, #12]
 *   @0x2c7090 vstr s15, [r3, #136]
 *   @0x2c7094 vcmpe.f32 s14, #0
 *   @0x2c7098 vmovls.f32 s13, s15
 *   @0x2c709c vmrs APSR_nzcv, fpscr
 *   @0x2c70a0 ble 0x2c70d4 <_ZN6b2Body11SetMassDataEPK10b2MassData+0xa4>
 *   @0x2c70a4 ldrh r2, [r3, #4]
 *   @0x2c70a8 tst r2, #16
 *   @0x2c70ac bne 0x2c70d4 <_ZN6b2Body11SetMassDataEPK10b2MassData+0xa4>
 *   @0x2c70b0 vldr s15, [r1, #8]
 *   @0x2c70b4 vmul.f32 s15, s15, s15
 *   @0x2c70b8 vldr s12, [r1, #4]
 *   @0x2c70bc vmla.f32 s15, s12, s12
 *   @0x2c70c0 vmls.f32 s14, s15, s13
 *   @0x2c70c4 vmov.f32 s15, #1.000000e+00
 *   @0x2c70c8 vstr s14, [r3, #140]
 *   @0x2c70cc vdiv.f32 s14, s15, s14
 *   @0x2c70d0 vstr s14, [r3, #144]
 *   @0x2c70d4 ldmib r1, {r0, r1}
 *   @0x2c70d8 add r2, r3, #44
 *   @0x2c70dc vldr s11, [r3, #20]
 *   @0x2c70e0 vldr s7, [r3, #60]
 *   @0x2c70e4 vldr s8, [r3, #64]
 *   @0x2c70e8 vldr s9, [r3, #24]
 *   @0x2c70ec stm r2, {r0, r1}
 *   @0x2c70f0 vldr s15, [r3, #48]
 *   @0x2c70f4 vmul.f32 s14, s11, s15
 *   @0x2c70f8 vldr s10, [r3, #44]
 *   @0x2c70fc vldr s6, [r3, #12]
 *   @0x2c7100 vldr s12, [r3, #16]
 *   @0x2c7104 add r1, r3, #60
 *   @0x2c7108 add r2, r3, #52
 *   @0x2c710c vldr s13, [r3, #88]
 *   @0x2c7110 vmul.f32 s15, s9, s15
 *   @0x2c7114 vnmls.f32 s14, s9, s10
 *   @0x2c7118 vmla.f32 s15, s10, s11
 *   @0x2c711c vadd.f32 s14, s14, s6
 *   @0x2c7120 vadd.f32 s12, s15, s12
 *   @0x2c7124 vstr s14, [r3, #60]
 *   @0x2c7128 vstr s12, [r3, #64]
 *   @0x2c712c vsub.f32 s11, s14, s7
 *   @0x2c7130 ldm r1, {r0, r1}
 *   @0x2c7134 stm r2, {r0, r1}
 *   @0x2c7138 vldr s15, [r3, #80]
 *   @0x2c713c vldr s14, [r3, #84]
 *   @0x2c7140 vsub.f32 s12, s12, s8
 *   @0x2c7144 vmla.f32 s14, s13, s11
 *   @0x2c7148 vmls.f32 s15, s13, s12
 *   @0x2c714c vstr s14, [r3, #84]
 *   @0x2c7150 vstr s15, [r3, #80]
 *   @0x2c7154 bx lr
 *
 * ══ §58/102 b2DistanceJoint::Dump()  0x2ccab8  size 296  74 条（0x2ccab8..0x2ccbe0）
 * @func 0x2ccab8 0x2ccbe0  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×9
 * 字段偏移 top8: 0x34×2 / 0x8×2 / 0x30×1 / 0xe4×1 / 0xd4×1 / 0xc8×1 / 0xbc×1 / 0x3d×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ccab8 push {r4, r5, r6, lr}
 *   @0x2ccabc mov r4, r0
 *   @0x2ccac0 ldr r2, [r4, #0x30]
 *   @0x2ccac4 sub sp, sp, #8
 *   @0x2ccac8 ldr r3, [r4, #0x34]
 *   @0x2ccacc ldr r0, [pc, #0xe4]
 *   @0x2ccad0 ldr r6, [r2, #0x8]
 *   @0x2ccad4 add r0, pc, r0
 *   @0x2ccad8 ldr r5, [r3, #0x8]
 *   @0x2ccadc bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ccae0 ldr r0, [pc, #0xd4]
 *   @0x2ccae4 mov r1, r6
 *   @0x2ccae8 add r0, pc, r0
 *   @0x2ccaec bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ccaf0 ldr r0, [pc, #0xc8]
 *   @0x2ccaf4 mov r1, r5
 *   @0x2ccaf8 add r0, pc, r0
 *   @0x2ccafc bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ccb00 ldr r0, [pc, #0xbc]
 *   @0x2ccb04 ldrb r1, [r4, #0x3d]
 *   @0x2ccb08 add r0, pc, r0
 *   @0x2ccb0c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ccb10 vldr s13, [r4, #80]
 *   @0x2ccb14 vldr s14, [r4, #84]
 *   @0x2ccb18 vcvt.f64.f32 d5, s13
 *   @0x2ccb1c ldr r0, [pc, #0xa4]
 *   @0x2ccb20 add r0, pc, r0
 *   @0x2ccb24 vcvt.f64.f32 d7, s14
 *   @0x2ccb28 vmov r2, r3, d5
 *   @0x2ccb2c vstr d7, [sp]
 *   @0x2ccb30 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ccb34 vldr s13, [r4, #88]
 *   @0x2ccb38 vldr s14, [r4, #92]
 *   @0x2ccb3c vcvt.f64.f32 d5, s13
 *   @0x2ccb40 ldr r0, [pc, #0x84]
 *   @0x2ccb44 add r0, pc, r0
 *   @0x2ccb48 vcvt.f64.f32 d7, s14
 *   @0x2ccb4c vmov r2, r3, d5
 *   @0x2ccb50 vstr d7, [sp]
 *   @0x2ccb54 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ccb58 vldr s15, [r4, #104]
 *   @0x2ccb5c vcvt.f64.f32 d6, s15
 *   @0x2ccb60 ldr r0, [pc, #0x68]
 *   @0x2ccb64 add r0, pc, r0
 *   @0x2ccb68 vmov r2, r3, d6
 *   @0x2ccb6c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ccb70 vldr s15, [r4, #68]
 *   @0x2ccb74 vcvt.f64.f32 d5, s15
 *   @0x2ccb78 ldr r0, [pc, #0x54]
 *   @0x2ccb7c add r0, pc, r0
 *   @0x2ccb80 vmov r2, r3, d5
 *   @0x2ccb84 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ccb88 vldr s15, [r4, #72]
 *   @0x2ccb8c vcvt.f64.f32 d6, s15
 *   @0x2ccb90 ldr r0, [pc, #0x40]
 *   @0x2ccb94 add r0, pc, r0
 *   @0x2ccb98 vmov r2, r3, d6
 *   @0x2ccb9c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ccba0 ldr r0, [pc, #0x34]
 *   @0x2ccba4 ldr r1, [r4, #0x38]
 *   @0x2ccba8 add r0, pc, r0
 *   @0x2ccbac add sp, sp, #8
 *   @0x2ccbb0 pop {r4, r5, r6, lr}
 *   @0x2ccbb4 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ccbb8 strheq pc, [r8], -r12
 *   @0x2ccbbc andeq pc, r8, r4, asr #7
 *   @0x2ccbc0 .word 0x0008f3d0
 *   @0x2ccbc4 .word 0x0008f3dc
 *   @0x2ccbc8 andeq pc, r8, r8, ror #7
 *   @0x2ccbcc .word 0x0008f3f0
 *   @0x2ccbd0 .word 0x0008f3fc
 *   @0x2ccbd4 .word 0x0008f3fc
 *   @0x2ccbd8 andeq pc, r8, r4, lsl #8
 *   @0x2ccbdc andeq pc, r8, r0, lsl r4
 *
 * ══ §59/102 b2WeldJoint::Dump()  0x2d2eac  size 296  74 条（0x2d2eac..0x2d2fd4）
 * @func 0x2d2eac 0x2d2fd4  size 296  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×9
 * 字段偏移 top8: 0x34×2 / 0x8×2 / 0x30×1 / 0xe4×1 / 0xd4×1 / 0xc8×1 / 0xbc×1 / 0x3d×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2eac push {r4, r5, r6, lr}
 *   @0x2d2eb0 mov r4, r0
 *   @0x2d2eb4 ldr r2, [r4, #0x30]
 *   @0x2d2eb8 sub sp, sp, #8
 *   @0x2d2ebc ldr r3, [r4, #0x34]
 *   @0x2d2ec0 ldr r0, [pc, #0xe4]
 *   @0x2d2ec4 ldr r6, [r2, #0x8]
 *   @0x2d2ec8 add r0, pc, r0
 *   @0x2d2ecc ldr r5, [r3, #0x8]
 *   @0x2d2ed0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d2ed4 ldr r0, [pc, #0xd4]
 *   @0x2d2ed8 mov r1, r6
 *   @0x2d2edc add r0, pc, r0
 *   @0x2d2ee0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d2ee4 ldr r0, [pc, #0xc8]
 *   @0x2d2ee8 mov r1, r5
 *   @0x2d2eec add r0, pc, r0
 *   @0x2d2ef0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d2ef4 ldr r0, [pc, #0xbc]
 *   @0x2d2ef8 ldrb r1, [r4, #0x3d]
 *   @0x2d2efc add r0, pc, r0
 *   @0x2d2f00 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d2f04 vldr s13, [r4, #80]
 *   @0x2d2f08 vldr s14, [r4, #84]
 *   @0x2d2f0c vcvt.f64.f32 d5, s13
 *   @0x2d2f10 ldr r0, [pc, #0xa4]
 *   @0x2d2f14 add r0, pc, r0
 *   @0x2d2f18 vcvt.f64.f32 d7, s14
 *   @0x2d2f1c vmov r2, r3, d5
 *   @0x2d2f20 vstr d7, [sp]
 *   @0x2d2f24 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d2f28 vldr s13, [r4, #88]
 *   @0x2d2f2c vldr s14, [r4, #92]
 *   @0x2d2f30 vcvt.f64.f32 d5, s13
 *   @0x2d2f34 ldr r0, [pc, #0x84]
 *   @0x2d2f38 add r0, pc, r0
 *   @0x2d2f3c vcvt.f64.f32 d7, s14
 *   @0x2d2f40 vmov r2, r3, d5
 *   @0x2d2f44 vstr d7, [sp]
 *   @0x2d2f48 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d2f4c vldr s15, [r4, #96]
 *   @0x2d2f50 vcvt.f64.f32 d6, s15
 *   @0x2d2f54 ldr r0, [pc, #0x68]
 *   @0x2d2f58 add r0, pc, r0
 *   @0x2d2f5c vmov r2, r3, d6
 *   @0x2d2f60 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d2f64 vldr s15, [r4, #68]
 *   @0x2d2f68 vcvt.f64.f32 d5, s15
 *   @0x2d2f6c ldr r0, [pc, #0x54]
 *   @0x2d2f70 add r0, pc, r0
 *   @0x2d2f74 vmov r2, r3, d5
 *   @0x2d2f78 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d2f7c vldr s15, [r4, #72]
 *   @0x2d2f80 vcvt.f64.f32 d6, s15
 *   @0x2d2f84 ldr r0, [pc, #0x40]
 *   @0x2d2f88 add r0, pc, r0
 *   @0x2d2f8c vmov r2, r3, d6
 *   @0x2d2f90 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d2f94 ldr r0, [pc, #0x34]
 *   @0x2d2f98 ldr r1, [r4, #0x38]
 *   @0x2d2f9c add r0, pc, r0
 *   @0x2d2fa0 add sp, sp, #8
 *   @0x2d2fa4 pop {r4, r5, r6, lr}
 *   @0x2d2fa8 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d2fac strheq r9, [r8], -r0
 *   @0x2d2fb0 ldrdeq r8, r9, [r8], -r0
 *   @0x2d2fb4 ldrdeq r8, r9, [r8], -r12
 *   @0x2d2fb8 andeq r8, r8, r8, ror #31
 *   @0x2d2fbc strdeq r8, r9, [r8], -r4
 *   @0x2d2fc0 strdeq r8, r9, [r8], -r12
 *   @0x2d2fc4 ldrdeq r9, r10, [r8], -r4
 *   @0x2d2fc8 andeq r9, r8, r8
 *   @0x2d2fcc andeq r9, r8, r0, lsl r0
 *   @0x2d2fd0 andeq r9, r8, r12, lsl r0
 *
 * ══ §60/102 DIALOG_REQ_CONTEXT::AddQuestionDialog(char const*, char const*)  0xf2350  size 292  73 条（0xf2350..0xf2474）
 * @func 0xf2350 0xf2484  size 308  77 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6640×2 / operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool) / loginDialogAsync / showMessage / questionDialogAsync / inputDialogAsync
 * 字段偏移 top8: 0x24×5 / 0x48×4 / 0x4c×4 / 0xf8×1 / 0x4×1 / 0x8×1 / 0xd8×1 / 0xac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2350 push {r4, r5, r6, lr}
 *   @0xf2354 mov r6, r0
 *   @0xf2358 sub sp, sp, #16
 *   @0xf235c mov r0, #88
 *   @0xf2360 mov r5, r1
 *   @0xf2364 bl 0x27c524 <_Znwj>
 *   @0xf2368 ldr r3, [pc, #0xf8]
 *   @0xf236c mov r2, #0
 *   @0xf2370 mov r1, r2
 *   @0xf2374 str r2, [sp]
 *   @0xf2378 ldr r3, [pc, r3]
 *   @0xf237c str r2, [sp, #0x4]
 *   @0xf2380 str r2, [sp, #0x8]
 *   @0xf2384 mov r4, r0
 *   @0xf2388 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0xf238c ldr r3, [pc, #0xd8]
 *   @0xf2390 subs r0, r6, #0
 *   @0xf2394 ldr r3, [pc, r3]
 *   @0xf2398 add r3, r3, #8
 *   @0xf239c str r3, [r4]
 *   @0xf23a0 beq 0xf23a8 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0x58>
 *   @0xf23a4 bl 0xb6640 <strdup@plt>
 *   @0xf23a8 cmp r5, #0
 *   @0xf23ac str r0, [r4, #0x48]
 *   @0xf23b0 mov r0, r5
 *   @0xf23b4 beq 0xf23bc <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0x6c>
 *   @0xf23b8 bl 0xb6640 <strdup@plt>
 *   @0xf23bc ldr r2, [pc, #0xac]
 *   @0xf23c0 mov r1, #0
 *   @0xf23c4 str r1, [r4, #0x50]
 *   @0xf23c8 mov r3, #1
 *   @0xf23cc ldr r2, [pc, r2]
 *   @0xf23d0 str r0, [r4, #0x4c]
 *   @0xf23d4 str r3, [r4, #0x54]
 *   @0xf23d8 ldr r1, [r2]
 *   @0xf23dc str r3, [r4, #0x30]
 *   @0xf23e0 cmp r1, #0
 *   @0xf23e4 str r4, [r2]
 *   @0xf23e8 str r1, [r4, #0x44]
 *   @0xf23ec beq 0xf23fc <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xac>
 *   @0xf23f0 ldr r0, [r4, #0x24]
 *   @0xf23f4 add sp, sp, #16
 *   @0xf23f8 pop {r4, r5, r6, pc}
 *   @0xf23fc cmp r3, #3
 *   @0xf2400 addls pc, pc, r3, lsl #2
 *   @0xf2404 b 0xf23f0 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xa0>
 *   @0xf2408 b 0xf2454 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0x104>
 *   @0xf240c b 0xf2440 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xf0>
 *   @0xf2410 b 0xf242c <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xdc>
 *   @0xf2414 b 0xf2418 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xc8>
 *   @0xf2418 ldr r0, [r4, #0x48]
 *   @0xf241c ldr r1, [r4, #0x4c]
 *   @0xf2420 ldr r2, [r4, #0x24]
 *   @0xf2424 bl 0xf2ad0 <loginDialogAsync>
 *   @0xf2428 b 0xf23f0 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xa0>
 *   @0xf242c ldr r0, [r4, #0x48]
 *   @0xf2430 ldr r1, [r4, #0x4c]
 *   @0xf2434 ldr r2, [r4, #0x24]
 *   @0xf2438 bl 0xf2b4c <showMessage>
 *   @0xf243c b 0xf23f0 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xa0>
 *   @0xf2440 ldr r0, [r4, #0x48]
 *   @0xf2444 ldr r1, [r4, #0x4c]
 *   @0xf2448 ldr r2, [r4, #0x24]
 *   @0xf244c bl 0xf2a70 <questionDialogAsync>
 *   @0xf2450 b 0xf23f0 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xa0>
 *   @0xf2454 add r0, r4, #72
 *   @0xf2458 ldr r3, [r4, #0x24]
 *   @0xf245c ldm r0, {r0, r1, r2}
 *   @0xf2460 bl 0xf29f4 <inputDialogAsync>
 *   @0xf2464 b 0xf23f0 <_ZN18DIALOG_REQ_CONTEXT17AddQuestionDialogEPKcS1_+0xa0>
 *   @0xf2468 eoreq r11, pc, r4, ror r10
 *   @0xf246c eoreq r11, pc, r12, asr #20
 *   @0xf2470 eoreq r11, pc, r8, lsl r10
 *
 * ══ §61/102 F_DsMapAddMap(RValue&, CInstance*, CInstance*, int, RValue*)  0xff378  size 292  73 条（0xff378..0xff49c）
 * @func 0xff378 0xff49c  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsMapAddMap(RValue&, CInstance*, CInstance*, int, RValue*)+0xf4×2 / Error_Show_Action(char const*, bool)×2 / DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapAddMap(RValue&, CInstance*, CInstance*, int, RValue*)+0xd4 / CDS_Map::Add(RValue*, RValue*)
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x2c×2 / 0x24×2 / 0x28×1 / 0xc×1 / 0xcc×1 / 0xbc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xff378 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xff37c sub sp, sp, #12
 *   @0xff380 add r8, sp, #4
 *   @0xff384 mov r6, r0
 *   @0xff388 ldr r7, [sp, #0x28]
 *   @0xff38c mov r0, r8
 *   @0xff390 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xff394 mov r3, #0
 *   @0xff398 mov r1, r3
 *   @0xff39c str r3, [r6, #0xc]
 *   @0xff3a0 str r3, [r6]
 *   @0xff3a4 mov r0, r7
 *   @0xff3a8 str r3, [r6, #0x4]
 *   @0xff3ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xff3b0 cmp r0, #0
 *   @0xff3b4 blt 0xff44c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0xff3b8 ldr r3, [pc, #0xcc]
 *   @0xff3bc ldr r3, [pc, r3]
 *   @0xff3c0 ldr r3, [r3]
 *   @0xff3c4 cmp r0, r3
 *   @0xff3c8 bge 0xff44c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0xff3cc ldr r2, [pc, #0xbc]
 *   @0xff3d0 ldr r2, [pc, r2]
 *   @0xff3d4 ldr r2, [r2, #0x4]
 *   @0xff3d8 ldr r0, [r2, r0, lsl #2]
 *   @0xff3dc cmp r0, #0
 *   @0xff3e0 beq 0xff44c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0xff3e4 ldr r9, [r7, #0x2c]
 *   @0xff3e8 ldr r4, [r7, #0x20]
 *   @0xff3ec cmp r9, #0
 *   @0xff3f0 ldr r5, [r7, #0x24]
 *   @0xff3f4 bne 0xff46c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0xff3f8 vmov d7, r4, r5
 *   @0xff3fc vcvt.s32.f64 s15, d7
 *   @0xff400 vmov r4, s15
 *   @0xff404 cmp r4, #0
 *   @0xff408 blt 0xff46c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0xff40c cmp r3, r4
 *   @0xff410 ble 0xff46c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0xff414 ldr r3, [r2, r4, lsl #2]
 *   @0xff418 cmp r3, #0
 *   @0xff41c beq 0xff46c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0xff420 mov r3, #-2147483648
 *   @0xff424 add r1, r7, #16
 *   @0xff428 str r3, [r7, #0x2c]
 *   @0xff42c add r2, r7, #32
 *   @0xff430 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0xff434 cmp r0, #0
 *   @0xff438 movne r3, #0
 *   @0xff43c strne r9, [r6]
 *   @0xff440 movtne r3, #0x3ff0
 *   @0xff444 strne r3, [r6, #0x4]
 *   @0xff448 b 0xff45c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0xff44c ldr r0, [pc, #0x40]
 *   @0xff450 mov r1, #0
 *   @0xff454 add r0, pc, r0
 *   @0xff458 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff45c mov r0, r8
 *   @0xff460 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff464 add sp, sp, #12
 *   @0xff468 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xff46c ldr r0, [pc, #0x24]
 *   @0xff470 mov r1, #0
 *   @0xff474 add r0, pc, r0
 *   @0xff478 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff47c mov r0, r8
 *   @0xff480 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff484 add sp, sp, #12
 *   @0xff488 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xff48c .word 0x002ee8bc
 *   @0xff490 eoreq lr, lr, r12, ror #10
 *   @0xff494 eoreq r8, r3, r8, lsr #15
 *   @0xff498 eoreq r8, r3, r4, lsl r8
 *
 * ══ §62/102 F_ExternalDefine3(RValue&, CInstance*, CInstance*, int, RValue*)  0x116138  size 292  73 条（0x116138..0x11625c）
 * @func 0x116138 0x11625c  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetString(RValue const*, int)×2 / 0xb65b0 / DLL_Define(char const*, char const*, int, int, int*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x78×1 / 0x4×1 / 0xc×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116138 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11613c sub sp, sp, #84
 *   @0x116140 add r5, sp, #12
 *   @0x116144 mov r2, #68
 *   @0x116148 ldr r4, [sp, #0x78]
 *   @0x11614c mov r6, r0
 *   @0x116150 mov r1, #0
 *   @0x116154 mov r0, r5
 *   @0x116158 bl 0xb65b0 <memset@plt>
 *   @0x11615c mov r1, #0
 *   @0x116160 mov r0, r4
 *   @0x116164 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x116168 mov r1, #1
 *   @0x11616c mov r11, r0
 *   @0x116170 mov r0, r4
 *   @0x116174 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x116178 mov r1, #2
 *   @0x11617c mov r10, r0
 *   @0x116180 mov r0, r4
 *   @0x116184 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x116188 mov r1, #3
 *   @0x11618c mov r9, r0
 *   @0x116190 mov r0, r4
 *   @0x116194 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x116198 mov r1, #4
 *   @0x11619c mov r8, r0
 *   @0x1161a0 mov r0, r4
 *   @0x1161a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1161a8 mov r1, #5
 *   @0x1161ac mov r7, r0
 *   @0x1161b0 mov r0, r4
 *   @0x1161b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1161b8 cmp r9, #1
 *   @0x1161bc streq r9, [sp, #0xc]
 *   @0x1161c0 mov r1, r10
 *   @0x1161c4 movne r3, #0
 *   @0x1161c8 str r5, [sp]
 *   @0x1161cc strne r3, [sp, #0xc]
 *   @0x1161d0 cmp r8, #1
 *   @0x1161d4 streq r8, [sp, #0x10]
 *   @0x1161d8 movne r3, #0
 *   @0x1161dc strne r3, [sp, #0x10]
 *   @0x1161e0 cmp r7, #1
 *   @0x1161e4 streq r7, [sp, #0x14]
 *   @0x1161e8 mov r7, #0
 *   @0x1161ec movne r3, #0
 *   @0x1161f0 strne r3, [sp, #0x14]
 *   @0x1161f4 subs r2, r0, #1
 *   @0x1161f8 mov r0, r11
 *   @0x1161fc rsbs r3, r2, #0
 *   @0x116200 adcs r3, r3, r2
 *   @0x116204 mov r2, r7
 *   @0x116208 str r3, [sp, #0x4]
 *   @0x11620c mov r3, #3
 *   @0x116210 str r7, [r6, #0xc]
 *   @0x116214 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii>
 *   @0x116218 vmov.f64 d7, #-1.000000e+00
 *   @0x11621c vmov s13, r0
 *   @0x116220 vcvt.f64.s32 d6, s13
 *   @0x116224 vmov r0, r1, d6
 *   @0x116228 vmov r2, s12
 *   @0x11622c vcmp.f64 d6, d7
 *   @0x116230 vmrs APSR_nzcv, fpscr
 *   @0x116234 mov r3, r1
 *   @0x116238 stm r6, {r2, r3}
 *   @0x11623c bne 0x116250 <_Z17F_ExternalDefine3R6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x116240 ldr r0, [pc, #0x10]
 *   @0x116244 mov r1, r7
 *   @0x116248 add r0, pc, r0
 *   @0x11624c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x116250 add sp, sp, #84
 *   @0x116254 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x116258 eoreq r3, r2, r8, asr r4
 *
 * ══ §63/102 F_ScreenSavePart(RValue&, CInstance*, CInstance*, int, RValue*)  0x120d14  size 292  73 条（0x120d14..0x120e38）
 * @func 0x120d14 0x120e38  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetString(RValue const*, int) / GR_Window_Get_Region_Width() / GR_Window_Get_Region_Height() / Graphics::GrabScreenRect(int, int, int, int, int*, int*) / SetImageALPHA(unsigned char*, int, int) / WritePNG32(char*, void*, int, int) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×4 / 0xc×3 / 0x30×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120d14 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x120d18 sub sp, sp, #20
 *   @0x120d1c mov r1, #0
 *   @0x120d20 ldr r4, [sp, #0x30]
 *   @0x120d24 mov r0, r4
 *   @0x120d28 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x120d2c mov r8, r0
 *   @0x120d30 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv>
 *   @0x120d34 mov r9, r0
 *   @0x120d38 bl 0x17999c <_Z27GR_Window_Get_Region_Heightv>
 *   @0x120d3c mov r1, #1
 *   @0x120d40 mov r7, r0
 *   @0x120d44 mov r0, r4
 *   @0x120d48 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120d4c mov r1, #2
 *   @0x120d50 mov r6, r0
 *   @0x120d54 mov r0, r4
 *   @0x120d58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120d5c mov r1, #3
 *   @0x120d60 mov r5, r0
 *   @0x120d64 mov r0, r4
 *   @0x120d68 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120d6c mov r1, #4
 *   @0x120d70 str r0, [sp, #0x8]
 *   @0x120d74 mov r0, r4
 *   @0x120d78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120d7c ldr r3, [sp, #0x8]
 *   @0x120d80 cmp r6, #0
 *   @0x120d84 addlt r3, r6, r3
 *   @0x120d88 movlt r6, #0
 *   @0x120d8c strlt r3, [sp, #0x8]
 *   @0x120d90 cmp r5, #0
 *   @0x120d94 add r1, r6, r3
 *   @0x120d98 addlt r2, r5, r0
 *   @0x120d9c movge r2, r0
 *   @0x120da0 movlt r5, #0
 *   @0x120da4 str r0, [sp, #0xc]
 *   @0x120da8 strlt r2, [sp, #0xc]
 *   @0x120dac cmp r9, r1
 *   @0x120db0 add r1, r5, r2
 *   @0x120db4 rsblt r3, r6, r9
 *   @0x120db8 strlt r3, [sp, #0x8]
 *   @0x120dbc cmp r7, r1
 *   @0x120dc0 rsblt r2, r5, r7
 *   @0x120dc4 strlt r2, [sp, #0xc]
 *   @0x120dc8 cmp r3, #0
 *   @0x120dcc cmpgt r2, #0
 *   @0x120dd0 bgt 0x120ddc <_Z16F_ScreenSavePartR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x120dd4 add sp, sp, #20
 *   @0x120dd8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x120ddc add r12, sp, #8
 *   @0x120de0 mov r0, r9
 *   @0x120de4 str r12, [sp]
 *   @0x120de8 mov r1, r7
 *   @0x120dec add r12, sp, #12
 *   @0x120df0 mov r2, r6
 *   @0x120df4 mov r3, r5
 *   @0x120df8 str r12, [sp, #0x4]
 *   @0x120dfc bl 0x17e0dc <_ZN8Graphics14GrabScreenRectEiiiiPiS0_>
 *   @0x120e00 subs r4, r0, #0
 *   @0x120e04 beq 0x120dd4 <_Z16F_ScreenSavePartR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x120e08 ldr r1, [sp, #0x8]
 *   @0x120e0c ldr r2, [sp, #0xc]
 *   @0x120e10 bl 0x120c3c <_Z13SetImageALPHAPhii>
 *   @0x120e14 mov r1, r4
 *   @0x120e18 ldr r2, [sp, #0x8]
 *   @0x120e1c mov r0, r8
 *   @0x120e20 ldr r3, [sp, #0xc]
 *   @0x120e24 bl 0x16cc8c <_Z10WritePNG32PcPvii>
 *   @0x120e28 mov r0, r4
 *   @0x120e2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x120e30 add sp, sp, #20
 *   @0x120e34 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §64/102 F_DrawTextTransformedColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x1220ac  size 292  73 条（0x1220ac..0x1221d0）
 * @func 0x1220ac 0x1221d0  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / YYGetInt32(RValue const*, int)×4 / GetTextFromArg(RValue const*, int, char**) / GR_Text_Draw_Transformed_Color(float, float, char const*, int, int, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x3c×2 / 0x34×2 / 0x2c×2 / 0x30×2 / 0x68×1 / 0x-4×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1220ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1220b0 sub sp, sp, #68
 *   @0x1220b4 add r2, sp, #64
 *   @0x1220b8 mov r5, #0
 *   @0x1220bc ldr r4, [sp, #0x68]
 *   @0x1220c0 mov r1, #1024
 *   @0x1220c4 str r5, [r2, #-0x4]!
 *   @0x1220c8 add r0, r4, #32
 *   @0x1220cc bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc>
 *   @0x1220d0 mov r1, r5
 *   @0x1220d4 mov r0, r4
 *   @0x1220d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1220dc mov r1, #1
 *   @0x1220e0 mov r5, r0
 *   @0x1220e4 mov r0, r4
 *   @0x1220e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1220ec mov r1, #3
 *   @0x1220f0 ldr r9, [sp, #0x3c]
 *   @0x1220f4 mov r6, r0
 *   @0x1220f8 mov r0, r4
 *   @0x1220fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122100 mov r1, #4
 *   @0x122104 str r0, [sp, #0x34]
 *   @0x122108 mov r0, r4
 *   @0x12210c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122110 mov r1, #5
 *   @0x122114 mov r12, r0
 *   @0x122118 mov r0, r4
 *   @0x12211c str r12, [sp, #0x2c]
 *   @0x122120 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122124 mov r1, #6
 *   @0x122128 mov r2, r0
 *   @0x12212c mov r0, r4
 *   @0x122130 str r2, [sp, #0x30]
 *   @0x122134 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122138 mov r1, #7
 *   @0x12213c mov r11, r0
 *   @0x122140 mov r0, r4
 *   @0x122144 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122148 mov r1, #8
 *   @0x12214c mov r10, r0
 *   @0x122150 mov r0, r4
 *   @0x122154 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122158 mov r1, #9
 *   @0x12215c mov r8, r0
 *   @0x122160 mov r0, r4
 *   @0x122164 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122168 mov r1, #10
 *   @0x12216c mov r7, r0
 *   @0x122170 mov r0, r4
 *   @0x122174 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122178 ldr r3, [sp, #0x34]
 *   @0x12217c ldr r12, [sp, #0x2c]
 *   @0x122180 mvn lr, #0
 *   @0x122184 ldr r2, [sp, #0x30]
 *   @0x122188 mov r1, r6
 *   @0x12218c str r3, [sp, #0x4]
 *   @0x122190 mov r3, lr
 *   @0x122194 str r12, [sp, #0x8]
 *   @0x122198 str r2, [sp, #0xc]
 *   @0x12219c mov r2, r9
 *   @0x1221a0 str lr, [sp]
 *   @0x1221a4 str r11, [sp, #0x10]
 *   @0x1221a8 str r10, [sp, #0x14]
 *   @0x1221ac str r8, [sp, #0x18]
 *   @0x1221b0 str r7, [sp, #0x1c]
 *   @0x1221b4 str r0, [sp, #0x20]
 *   @0x1221b8 mov r0, r5
 *   @0x1221bc bl 0x1735a0 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf>
 *   @0x1221c0 ldr r0, [sp, #0x3c]
 *   @0x1221c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1221c8 add sp, sp, #68
 *   @0x1221cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §65/102 F_FileBinReadByte(RValue&, CInstance*, CInstance*, int, RValue*)  0x139688  size 292  73 条（0x139688..0x1397ac）
 * @func 0x139688 0x1397ac  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×3 / YYGetInt32(RValue const*, int) / LoadSave::fread(void const*, unsigned int, unsigned int, _YYFILE*)
 * 字段偏移 top8: 0x4×3 / 0x18×1 / 0xe4×1 / 0xd0×1 / 0xc×1 / 0x8×1 / 0x7×1 / 0x58×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139688 push {r4, r5, lr}
 *   @0x13968c sub sp, sp, #12
 *   @0x139690 mov r4, r0
 *   @0x139694 mov r1, #0
 *   @0x139698 ldr r0, [sp, #0x18]
 *   @0x13969c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1396a0 sub r2, r0, #1
 *   @0x1396a4 cmp r2, #30
 *   @0x1396a8 bhi 0x13975c <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x1396ac ldr r2, [pc, #0xe4]
 *   @0x1396b0 ldr r2, [pc, r2]
 *   @0x1396b4 ldrb r2, [r2, r0]
 *   @0x1396b8 cmp r2, #0
 *   @0x1396bc beq 0x13975c <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x1396c0 add r3, r0, r0, lsl #1
 *   @0x1396c4 ldr r2, [pc, #0xd0]
 *   @0x1396c8 mov r1, #0
 *   @0x1396cc str r1, [r4, #0xc]
 *   @0x1396d0 ldr r2, [pc, r2]
 *   @0x1396d4 lsl r1, r3, #2
 *   @0x1396d8 add r0, r1, r2
 *   @0x1396dc ldr r3, [r0, #0x8]
 *   @0x1396e0 cmp r3, #0
 *   @0x1396e4 beq 0x139774 <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x1396e8 ldr r2, [r1, r2]
 *   @0x1396ec cmp r2, #0
 *   @0x1396f0 beq 0x139774 <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x1396f4 ldr r2, [r0, #0x4]
 *   @0x1396f8 cmp r2, #1
 *   @0x1396fc beq 0x139774 <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x139700 cmp r2, #0
 *   @0x139704 beq 0x139710 <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x139708 cmp r2, #2
 *   @0x13970c bne 0x139724 <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x139710 mov r1, #1
 *   @0x139714 add r0, sp, #7
 *   @0x139718 mov r2, r1
 *   @0x13971c bl 0x18e070 <_ZN8LoadSave5freadEPKvjjP7_YYFILE>
 *   @0x139720 mov r5, r0
 *   @0x139724 ldrb r2, [sp, #0x7]
 *   @0x139728 cmp r5, #0
 *   @0x13972c vmov s15, r2
 *   @0x139730 vcvt.f64.u32 d7, s15
 *   @0x139734 vmov r2, r3, d7
 *   @0x139738 stm r4, {r2, r3}
 *   @0x13973c bne 0x13976c <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x139740 ldr r0, [pc, #0x58]
 *   @0x139744 mov r1, r5
 *   @0x139748 add r0, pc, r0
 *   @0x13974c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139750 str r5, [r4]
 *   @0x139754 str r5, [r4, #0x4]
 *   @0x139758 b 0x13976c <_Z17F_FileBinReadByteR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x13975c ldr r0, [pc, #0x40]
 *   @0x139760 mov r1, #0
 *   @0x139764 add r0, pc, r0
 *   @0x139768 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13976c add sp, sp, #12
 *   @0x139770 pop {r4, r5, pc}
 *   @0x139774 ldr r0, [pc, #0x2c]
 *   @0x139778 mov r1, #0
 *   @0x13977c add r0, pc, r0
 *   @0x139780 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139784 mov r3, #0
 *   @0x139788 str r3, [r4]
 *   @0x13978c str r3, [r4, #0x4]
 *   @0x139790 add sp, sp, #12
 *   @0x139794 pop {r4, r5, pc}
 *   @0x139798 .word 0x002b5bdc
 *   @0x13979c eoreq r5, r11, r0, asr #23
 *   @0x1397a0 eoreq r6, r0, r12, asr #20
 *   @0x1397a4 eoreq r6, r0, r12, lsl r10
 *   @0x1397a8 eoreq r6, r0, r8, lsl r10
 *
 * ══ §66/102 F_D3DGetMatrix(RValue&, CInstance*, CInstance*, int, RValue*)  0x1469dc  size 292  73 条（0x1469dc..0x146b00）
 * @func 0x1469dc 0x146b00  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Graphics::GetMatrix(eMatrix, float*) / CreateArray(RValue*, int, ...) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0xf8×1 / 0x14×1
 * VFP 指令 51 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1469dc push {r4, lr}
 *   @0x1469e0 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x1469e4 sub sp, sp, #184
 *   @0x1469e8 mov r4, r0
 *   @0x1469ec mov r1, #0
 *   @0x1469f0 ldr r0, [sp, #0xf8]
 *   @0x1469f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1469f8 cmp r0, #2
 *   @0x1469fc bhi 0x146ae0 <_Z14F_D3DGetMatrixR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x146a00 add r1, sp, #120
 *   @0x146a04 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x146a08 vldr s14, [sp, #124]
 *   @0x146a0c vcvt.f64.f32 d7, s14
 *   @0x146a10 vldr s26, [sp, #128]
 *   @0x146a14 vldr s24, [sp, #132]
 *   @0x146a18 vldr s22, [sp, #136]
 *   @0x146a1c vldr s20, [sp, #140]
 *   @0x146a20 vldr s18, [sp, #144]
 *   @0x146a24 vldr s16, [sp, #148]
 *   @0x146a28 vldr s0, [sp, #152]
 *   @0x146a2c vldr s2, [sp, #156]
 *   @0x146a30 vldr s4, [sp, #160]
 *   @0x146a34 vldr s6, [sp, #164]
 *   @0x146a38 vldr s8, [sp, #168]
 *   @0x146a3c vldr s10, [sp, #172]
 *   @0x146a40 vldr s12, [sp, #176]
 *   @0x146a44 vstr d7, [sp]
 *   @0x146a48 vldr s14, [sp, #180]
 *   @0x146a4c vcvt.f64.f32 d7, s14
 *   @0x146a50 vldr s28, [sp, #120]
 *   @0x146a54 mov r0, r4
 *   @0x146a58 mov r1, #16
 *   @0x146a5c vcvt.f64.f32 d0, s0
 *   @0x146a60 vstr d7, [sp, #112]
 *   @0x146a64 vcvt.f64.f32 d1, s2
 *   @0x146a68 vstr d0, [sp, #56]
 *   @0x146a6c vcvt.f64.f32 d2, s4
 *   @0x146a70 vstr d1, [sp, #64]
 *   @0x146a74 vcvt.f64.f32 d3, s6
 *   @0x146a78 vstr d2, [sp, #72]
 *   @0x146a7c vcvt.f64.f32 d4, s8
 *   @0x146a80 vstr d3, [sp, #80]
 *   @0x146a84 vcvt.f64.f32 d5, s10
 *   @0x146a88 vstr d4, [sp, #88]
 *   @0x146a8c vcvt.f64.f32 d6, s12
 *   @0x146a90 vstr d5, [sp, #96]
 *   @0x146a94 vcvt.f64.f32 d7, s28
 *   @0x146a98 vstr d6, [sp, #104]
 *   @0x146a9c vcvt.f64.f32 d13, s26
 *   @0x146aa0 vmov r2, r3, d7
 *   @0x146aa4 vcvt.f64.f32 d12, s24
 *   @0x146aa8 vstr d13, [sp, #8]
 *   @0x146aac vcvt.f64.f32 d11, s22
 *   @0x146ab0 vstr d12, [sp, #16]
 *   @0x146ab4 vcvt.f64.f32 d10, s20
 *   @0x146ab8 vstr d11, [sp, #24]
 *   @0x146abc vcvt.f64.f32 d9, s18
 *   @0x146ac0 vstr d10, [sp, #32]
 *   @0x146ac4 vcvt.f64.f32 d8, s16
 *   @0x146ac8 vstr d9, [sp, #40]
 *   @0x146acc vstr d8, [sp, #48]
 *   @0x146ad0 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x146ad4 add sp, sp, #184
 *   @0x146ad8 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x146adc pop {r4, pc}
 *   @0x146ae0 ldr r0, [pc, #0x14]
 *   @0x146ae4 mov r1, #1
 *   @0x146ae8 add r0, pc, r0
 *   @0x146aec bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x146af0 add sp, sp, #184
 *   @0x146af4 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x146af8 pop {r4, pc}
 *   @0x146afc ldrsheq r10, [pc], -r4
 *
 * ══ §67/102 F_GPUGetBlendMode(RValue&, CInstance*, CInstance*, int, RValue*)  0x147efc  size 292  73 条（0x147efc..0x148020）
 * @func 0x147efc 0x148020  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)×4
 * 字段偏移 top8: 0x4×4 / 0xc×1 / 0xf0×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147efc cmp r3, #0
 *   @0x147f00 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x147f04 mov r6, #0
 *   @0x147f08 mov r1, r6
 *   @0x147f0c mov r4, r0
 *   @0x147f10 movt r6, #0xbff0
 *   @0x147f14 str r1, [r0, #0xc]
 *   @0x147f18 stm r0, {r1, r6}
 *   @0x147f1c bne 0x147fc4 <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x147f20 ldr r5, [pc, #0xf0]
 *   @0x147f24 mov r1, #6
 *   @0x147f28 ldr r5, [pc, r5]
 *   @0x147f2c mov r0, r5
 *   @0x147f30 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x147f34 mov r1, #7
 *   @0x147f38 mov r7, r0
 *   @0x147f3c mov r0, r5
 *   @0x147f40 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x147f44 mov r1, #34
 *   @0x147f48 mov r8, r0
 *   @0x147f4c mov r0, r5
 *   @0x147f50 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x147f54 mov r1, #35
 *   @0x147f58 mov r9, r0
 *   @0x147f5c mov r0, r5
 *   @0x147f60 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x147f64 cmp r7, r9
 *   @0x147f68 cmpeq r8, r0
 *   @0x147f6c moveq r0, #0
 *   @0x147f70 movne r0, #1
 *   @0x147f74 bne 0x147fb0 <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x147f78 cmp r7, #1
 *   @0x147f7c beq 0x147fa8 <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x147f80 cmp r7, #5
 *   @0x147f84 popne {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x147f88 cmp r8, #4
 *   @0x147f8c beq 0x147ffc <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x147f90 cmp r8, #6
 *   @0x147f94 beq 0x14800c <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x147f98 cmp r8, #2
 *   @0x147f9c beq 0x147fe8 <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x147fa0 stm r4, {r0, r6}
 *   @0x147fa4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x147fa8 cmp r8, #4
 *   @0x147fac beq 0x147fd4 <_Z17F_GPUGetBlendModeR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x147fb0 mov r3, #0
 *   @0x147fb4 mov r2, r3
 *   @0x147fb8 movt r3, #0xbff0
 *   @0x147fbc stm r4, {r2, r3}
 *   @0x147fc0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x147fc4 ldr r0, [pc, #0x50]
 *   @0x147fc8 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x147fcc add r0, pc, r0
 *   @0x147fd0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147fd4 mov r3, #0
 *   @0x147fd8 str r0, [r4]
 *   @0x147fdc movt r3, #0x4008
 *   @0x147fe0 str r3, [r4, #0x4]
 *   @0x147fe4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x147fe8 mov r3, #0
 *   @0x147fec str r0, [r4]
 *   @0x147ff0 movt r3, #0x3ff0
 *   @0x147ff4 str r3, [r4, #0x4]
 *   @0x147ff8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x147ffc mov r3, #1073741824
 *   @0x148000 str r0, [r4]
 *   @0x148004 str r3, [r4, #0x4]
 *   @0x148008 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x14800c str r0, [r4]
 *   @0x148010 str r0, [r4, #0x4]
 *   @0x148014 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x148018 .word 0x002a5dd0
 *   @0x14801c ldrsheq r9, [pc], -r8
 *
 * ══ §68/102 F_GPUSetBlendModeExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x149198  size 292  73 条（0x149198..0x1492bc）
 * @func 0x149198 0x1492bc  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / RenderStateManager::SetRenderState(eRenderState, unsigned int)×4 / F_GPUSetBlendModeExt(RValue&, CInstance*, CInstance*, int, RValue*)+0x40
 * 字段偏移 top8: 0x4×4 / 0xc×2 / 0x10×1 / 0xd0×1 / 0xc0×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x149198 sub r2, r3, #1
 *   @0x14919c cmp r2, #1
 *   @0x1491a0 mov r2, #0
 *   @0x1491a4 push {r4, r5, r6, lr}
 *   @0x1491a8 mov r1, r2
 *   @0x1491ac ldr r4, [sp, #0x10]
 *   @0x1491b0 movt r2, #0xbff0
 *   @0x1491b4 str r1, [r0, #0xc]
 *   @0x1491b8 stm r0, {r1, r2}
 *   @0x1491bc bhi 0x1491ec <_Z20F_GPUSetBlendModeExtR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1491c0 cmp r3, #2
 *   @0x1491c4 beq 0x149290 <_Z20F_GPUSetBlendModeExtR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x1491c8 ldr r3, [r4, #0xc]
 *   @0x1491cc bic r3, r3, #-16777216
 *   @0x1491d0 cmp r3, #2
 *   @0x1491d4 beq 0x1491fc <_Z20F_GPUSetBlendModeExtR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x1491d8 ldr r0, [pc, #0xd0]
 *   @0x1491dc mov r1, #0
 *   @0x1491e0 pop {r4, r5, r6, lr}
 *   @0x1491e4 add r0, pc, r0
 *   @0x1491e8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1491ec ldr r0, [pc, #0xc0]
 *   @0x1491f0 pop {r4, r5, r6, lr}
 *   @0x1491f4 add r0, pc, r0
 *   @0x1491f8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1491fc ldr r3, [r4]
 *   @0x149200 ldr r3, [r3, #0x4]
 *   @0x149204 ldr r2, [r3]
 *   @0x149208 cmp r2, #1
 *   @0x14920c ble 0x1491d8 <_Z20F_GPUSetBlendModeExtR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x149210 ldr r0, [r3, #0x4]
 *   @0x149214 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149218 ldr r3, [r4]
 *   @0x14921c mov r1, #1
 *   @0x149220 ldr r3, [r3, #0x4]
 *   @0x149224 mov r6, r0
 *   @0x149228 ldr r0, [r3, #0x4]
 *   @0x14922c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149230 mov r5, r0
 *   @0x149234 ldr r4, [pc, #0x7c]
 *   @0x149238 mov r2, r6
 *   @0x14923c mov r1, #6
 *   @0x149240 ldr r4, [pc, r4]
 *   @0x149244 mov r0, r4
 *   @0x149248 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x14924c mov r0, r4
 *   @0x149250 mov r2, r5
 *   @0x149254 mov r1, #7
 *   @0x149258 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x14925c mov r0, r4
 *   @0x149260 mov r2, r6
 *   @0x149264 mov r1, #34
 *   @0x149268 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x14926c mov r0, r4
 *   @0x149270 mov r2, r5
 *   @0x149274 mov r1, #35
 *   @0x149278 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x14927c mov r0, r4
 *   @0x149280 mov r1, #33
 *   @0x149284 mov r2, #0
 *   @0x149288 pop {r4, r5, r6, lr}
 *   @0x14928c b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x149290 mov r0, r4
 *   @0x149294 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149298 mov r1, #1
 *   @0x14929c mov r6, r0
 *   @0x1492a0 mov r0, r4
 *   @0x1492a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1492a8 mov r5, r0
 *   @0x1492ac b 0x149234 <_Z20F_GPUSetBlendModeExtR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1492b0 ldrheq r9, [pc], -r8
 *   @0x1492b4 andseq r9, pc, r12, ror #10
 *   @0x1492b8 .word 0x002a4ab8
 *
 * ══ §69/102 GraphicsPerf::AddMemoryBar(int, unsigned int, void*)  0x17bdf4  size 292  73 条（0x17bdf4..0x17bf18）
 * @func 0x17bdf4 0x17bf18  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Get_Region_Width()
 * 字段偏移 top8: 0x100×1 / 0xdc×1 / 0xd8×1 / 0x84×1 / 0x34×1 / 0x6c×1 / 0x54×1 / 0x3c×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17bdf4 vmov.f32 s15, #1.000000e+00
 *   @0x17bdf8 push {r3, r4, r5, lr}
 *   @0x17bdfc vpush {d8}
 *   @0x17be00 vmov s13, r0
 *   @0x17be04 ldr r3, [pc, #0x100]
 *   @0x17be08 mov r4, r2
 *   @0x17be0c mov r5, r1
 *   @0x17be10 ldr r3, [pc, r3]
 *   @0x17be14 vldr s16, [r3]
 *   @0x17be18 vcvt.f32.s32 s16, s16
 *   @0x17be1c vdiv.f32 s16, s15, s16
 *   @0x17be20 vcvt.f32.s32 s15, s13
 *   @0x17be24 vmul.f32 s16, s15, s16
 *   @0x17be28 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv>
 *   @0x17be2c ldr r12, [pc, #0xdc]
 *   @0x17be30 mov r2, #1056964608
 *   @0x17be34 ldr r1, [pc, #0xd8]
 *   @0x17be38 mov r3, #0
 *   @0x17be3c ldr r12, [pc, r12]
 *   @0x17be40 vldr s15, [r12]
 *   @0x17be44 vstr s15, [r4]
 *   @0x17be48 vstr s15, [r4, #96]
 *   @0x17be4c vstr s15, [r4, #120]
 *   @0x17be50 movt r3, #0x4220
 *   @0x17be54 str r5, [r4, #0x84]
 *   @0x17be58 str r3, [r4, #0x34]
 *   @0x17be5c str r5, [r4, #0x6c]
 *   @0x17be60 str r5, [r4, #0x54]
 *   @0x17be64 str r5, [r4, #0x3c]
 *   @0x17be68 str r3, [r4, #0x4c]
 *   @0x17be6c str r5, [r4, #0x24]
 *   @0x17be70 str r3, [r4, #0x64]
 *   @0x17be74 mov r3, #0
 *   @0x17be78 str r5, [r4, #0xc]
 *   @0x17be7c mov r5, #0
 *   @0x17be80 str r3, [r4, #0x88]
 *   @0x17be84 movt r5, #0x41f0
 *   @0x17be88 str r3, [r4, #0x70]
 *   @0x17be8c str r3, [r4, #0x58]
 *   @0x17be90 str r3, [r4, #0x40]
 *   @0x17be94 str r3, [r4, #0x28]
 *   @0x17be98 str r3, [r4, #0x10]
 *   @0x17be9c str r3, [r4, #0x8c]
 *   @0x17bea0 str r2, [r4, #0x80]
 *   @0x17bea4 str r2, [r4, #0x68]
 *   @0x17bea8 str r2, [r4, #0x50]
 *   @0x17beac str r2, [r4, #0x38]
 *   @0x17beb0 str r2, [r4, #0x20]
 *   @0x17beb4 str r2, [r4, #0x8]
 *   @0x17beb8 str r5, [r4, #0x4]
 *   @0x17bebc str r5, [r4, #0x1c]
 *   @0x17bec0 str r5, [r4, #0x7c]
 *   @0x17bec4 vmov s13, r0
 *   @0x17bec8 vcvt.f32.s32 s14, s13
 *   @0x17becc vmla.f32 s15, s14, s16
 *   @0x17bed0 vstr s15, [r4, #24]
 *   @0x17bed4 vstr s15, [r4, #48]
 *   @0x17bed8 vstr s15, [r4, #72]
 *   @0x17bedc str r3, [r4, #0x74]
 *   @0x17bee0 str r3, [r4, #0x5c]
 *   @0x17bee4 ldr r1, [pc, r1]
 *   @0x17bee8 str r3, [r4, #0x44]
 *   @0x17beec vstr s15, [r12]
 *   @0x17bef0 str r3, [r4, #0x2c]
 *   @0x17bef4 str r3, [r4, #0x14]
 *   @0x17bef8 vpop {d8}
 *   @0x17befc ldr r2, [r1]
 *   @0x17bf00 add r3, r2, #2
 *   @0x17bf04 str r3, [r1]
 *   @0x17bf08 pop {r3, r4, r5, pc}
 *   @0x17bf0c .word 0x002745bc
 *   @0x17bf10 mlaeq r7, r4, r5, r4
 *   @0x17bf14 .word 0x002744f0
 *
 * ══ §70/102 Motion_Grid_ClearRectangle(int, int, int, int, int)  0x19a2e0  size 292  73 条（0x19a2e0..0x19a404）
 * @func 0x19a2e0 0x19a404  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×4 / Motion_Grid_ClearRectangle(int, int, int, int, int)+0x10c
 * 字段偏移 top8: 0x2×2 / 0x20×2 / 0x18×2 / 0xfc×1 / 0xec×1 / 0xc×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19a2e0 cmp r0, #0
 *   @0x19a2e4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x19a2e8 mov r6, r1
 *   @0x19a2ec mov r9, r2
 *   @0x19a2f0 mov r7, r3
 *   @0x19a2f4 poplt {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19a2f8 ldr r12, [pc, #0xfc]
 *   @0x19a2fc ldr r12, [pc, r12]
 *   @0x19a300 ldr r3, [r12]
 *   @0x19a304 cmp r0, r3
 *   @0x19a308 popge {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19a30c ldr r12, [pc, #0xec]
 *   @0x19a310 ldr r12, [pc, r12]
 *   @0x19a314 ldr r3, [r12]
 *   @0x19a318 ldr r5, [r3, r0, lsl #2]
 *   @0x19a31c cmp r5, #0
 *   @0x19a320 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19a324 ldr r4, [r5, #0xc]
 *   @0x19a328 ldr r8, [r5, #0x4]
 *   @0x19a32c mov r1, r4
 *   @0x19a330 cmp r6, r7
 *   @0x19a334 rsble r0, r8, r6
 *   @0x19a338 rsbgt r0, r8, r7
 *   @0x19a33c bl 0x318d10 <__divsi3>
 *   @0x19a340 mov r1, r4
 *   @0x19a344 bic r4, r0, r0, asr #31
 *   @0x19a348 cmp r6, r7
 *   @0x19a34c rsbge r0, r8, r6
 *   @0x19a350 rsblt r0, r8, r7
 *   @0x19a354 bl 0x318d10 <__divsi3>
 *   @0x19a358 ldr r3, [r5, #0x14]
 *   @0x19a35c ldr r7, [r5, #0x10]
 *   @0x19a360 ldr r6, [r5, #0x8]
 *   @0x19a364 mov r1, r7
 *   @0x19a368 cmp r0, r3
 *   @0x19a36c mov r8, r0
 *   @0x19a370 subge r8, r3, #1
 *   @0x19a374 ldr r3, [sp, #0x20]
 *   @0x19a378 cmp r9, r3
 *   @0x19a37c rsble r0, r6, r9
 *   @0x19a380 rsbgt r0, r6, r3
 *   @0x19a384 bl 0x318d10 <__divsi3>
 *   @0x19a388 ldr r3, [sp, #0x20]
 *   @0x19a38c mov r1, r7
 *   @0x19a390 bic r7, r0, r0, asr #31
 *   @0x19a394 cmp r9, r3
 *   @0x19a398 rsbge r0, r6, r9
 *   @0x19a39c rsblt r0, r6, r3
 *   @0x19a3a0 bl 0x318d10 <__divsi3>
 *   @0x19a3a4 ldr r3, [r5, #0x18]
 *   @0x19a3a8 cmp r0, r3
 *   @0x19a3ac subge r0, r3, #1
 *   @0x19a3b0 cmp r8, r4
 *   @0x19a3b4 poplt {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19a3b8 add r8, r8, #1
 *   @0x19a3bc add r6, r0, #1
 *   @0x19a3c0 mov r12, #0
 *   @0x19a3c4 cmp r0, r7
 *   @0x19a3c8 blt 0x19a3ec <_Z26Motion_Grid_ClearRectangleiiiii+0x10c>
 *   @0x19a3cc ldr r1, [r5, #0x1c]
 *   @0x19a3d0 mov r3, r7
 *   @0x19a3d4 ldr r2, [r5, #0x18]
 *   @0x19a3d8 mla r2, r2, r4, r3
 *   @0x19a3dc add r3, r3, #1
 *   @0x19a3e0 cmp r3, r6
 *   @0x19a3e4 str r12, [r1, r2, lsl #2]
 *   @0x19a3e8 bne 0x19a3d4 <_Z26Motion_Grid_ClearRectangleiiiii+0xf4>
 *   @0x19a3ec add r4, r4, #1
 *   @0x19a3f0 cmp r4, r8
 *   @0x19a3f4 bne 0x19a3c4 <_Z26Motion_Grid_ClearRectangleiiiii+0xe4>
 *   @0x19a3f8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19a3fc .word 0x002563b0
 *   @0x19a400 eoreq r6, r5, r0, lsr #7
 *
 * ══ §71/102 Motion_Grid_AddRectangle(int, int, int, int, int)  0x19a4f4  size 292  73 条（0x19a4f4..0x19a618）
 * @func 0x19a4f4 0x19a618  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×4 / Motion_Grid_AddRectangle(int, int, int, int, int)+0x10c
 * 字段偏移 top8: 0x2×2 / 0x20×2 / 0x18×2 / 0xfc×1 / 0xec×1 / 0xc×1 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19a4f4 cmp r0, #0
 *   @0x19a4f8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x19a4fc mov r6, r1
 *   @0x19a500 mov r9, r2
 *   @0x19a504 mov r7, r3
 *   @0x19a508 poplt {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19a50c ldr r12, [pc, #0xfc]
 *   @0x19a510 ldr r12, [pc, r12]
 *   @0x19a514 ldr r3, [r12]
 *   @0x19a518 cmp r0, r3
 *   @0x19a51c popge {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19a520 ldr r12, [pc, #0xec]
 *   @0x19a524 ldr r12, [pc, r12]
 *   @0x19a528 ldr r3, [r12]
 *   @0x19a52c ldr r5, [r3, r0, lsl #2]
 *   @0x19a530 cmp r5, #0
 *   @0x19a534 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19a538 ldr r4, [r5, #0xc]
 *   @0x19a53c ldr r8, [r5, #0x4]
 *   @0x19a540 mov r1, r4
 *   @0x19a544 cmp r6, r7
 *   @0x19a548 rsble r0, r8, r6
 *   @0x19a54c rsbgt r0, r8, r7
 *   @0x19a550 bl 0x318d10 <__divsi3>
 *   @0x19a554 mov r1, r4
 *   @0x19a558 bic r4, r0, r0, asr #31
 *   @0x19a55c cmp r6, r7
 *   @0x19a560 rsbge r0, r8, r6
 *   @0x19a564 rsblt r0, r8, r7
 *   @0x19a568 bl 0x318d10 <__divsi3>
 *   @0x19a56c ldr r3, [r5, #0x14]
 *   @0x19a570 ldr r7, [r5, #0x10]
 *   @0x19a574 ldr r6, [r5, #0x8]
 *   @0x19a578 mov r1, r7
 *   @0x19a57c cmp r0, r3
 *   @0x19a580 mov r8, r0
 *   @0x19a584 subge r8, r3, #1
 *   @0x19a588 ldr r3, [sp, #0x20]
 *   @0x19a58c cmp r9, r3
 *   @0x19a590 rsble r0, r6, r9
 *   @0x19a594 rsbgt r0, r6, r3
 *   @0x19a598 bl 0x318d10 <__divsi3>
 *   @0x19a59c ldr r3, [sp, #0x20]
 *   @0x19a5a0 mov r1, r7
 *   @0x19a5a4 bic r7, r0, r0, asr #31
 *   @0x19a5a8 cmp r9, r3
 *   @0x19a5ac rsbge r0, r6, r9
 *   @0x19a5b0 rsblt r0, r6, r3
 *   @0x19a5b4 bl 0x318d10 <__divsi3>
 *   @0x19a5b8 ldr r3, [r5, #0x18]
 *   @0x19a5bc cmp r0, r3
 *   @0x19a5c0 subge r0, r3, #1
 *   @0x19a5c4 cmp r8, r4
 *   @0x19a5c8 poplt {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19a5cc add r8, r8, #1
 *   @0x19a5d0 add r6, r0, #1
 *   @0x19a5d4 mvn r12, #0
 *   @0x19a5d8 cmp r0, r7
 *   @0x19a5dc blt 0x19a600 <_Z24Motion_Grid_AddRectangleiiiii+0x10c>
 *   @0x19a5e0 ldr r1, [r5, #0x1c]
 *   @0x19a5e4 mov r3, r7
 *   @0x19a5e8 ldr r2, [r5, #0x18]
 *   @0x19a5ec mla r2, r2, r4, r3
 *   @0x19a5f0 add r3, r3, #1
 *   @0x19a5f4 cmp r3, r6
 *   @0x19a5f8 str r12, [r1, r2, lsl #2]
 *   @0x19a5fc bne 0x19a5e8 <_Z24Motion_Grid_AddRectangleiiiii+0xf4>
 *   @0x19a600 add r4, r4, #1
 *   @0x19a604 cmp r4, r8
 *   @0x19a608 bne 0x19a5d8 <_Z24Motion_Grid_AddRectangleiiiii+0xe4>
 *   @0x19a60c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19a610 mlaeq r5, r12, r1, r6
 *   @0x19a614 eoreq r6, r5, r12, lsl #3
 *
 * ══ §72/102 Motion_Linear_Step(CInstance*, float, float, float, int, bool)  0x19c8a8  size 292  73 条（0x19c8a8..0x19c9cc）
 * @func 0x19c8a8 0x19c9cc  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TestFree(CInstance*, float, float, int, bool) / ComputeDir(float, float, float, float) / CInstance::SetDirection(float) / CInstance::SetPosition(float, float) / 0xb6700
 * 字段偏移 top8: 0x2c×1 / 0x28×1 / 0xb8×1 / 0xb4×1
 * VFP 指令 39 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19c8a8 push {r4, r5, r6, lr}
 *   @0x19c8ac vpush {d8, d9}
 *   @0x19c8b0 vmov s16, r1
 *   @0x19c8b4 vldr s13, [r0, #180]
 *   @0x19c8b8 sub sp, sp, #8
 *   @0x19c8bc mov r4, r0
 *   @0x19c8c0 vcmp.f32 s13, s16
 *   @0x19c8c4 vldr s14, [r0, #184]
 *   @0x19c8c8 ldrb r5, [sp, #0x2c]
 *   @0x19c8cc vmov s17, r2
 *   @0x19c8d0 vmov s18, r3
 *   @0x19c8d4 vmrs APSR_nzcv, fpscr
 *   @0x19c8d8 bne 0x19c8ec <_Z18Motion_Linear_StepP9CInstancefffib+0x44>
 *   @0x19c8dc vcmp.f32 s14, s17
 *   @0x19c8e0 vmrs APSR_nzcv, fpscr
 *   @0x19c8e4 moveq r0, #1
 *   @0x19c8e8 beq 0x19c940 <_Z18Motion_Linear_StepP9CInstancefffib+0x98>
 *   @0x19c8ec vsub.f32 s14, s14, s17
 *   @0x19c8f0 vmul.f32 s14, s14, s14
 *   @0x19c8f4 vsub.f32 s13, s13, s16
 *   @0x19c8f8 vmla.f32 s14, s13, s13
 *   @0x19c8fc vsqrt.f32 s15, s14
 *   @0x19c900 vcmp.f32 s15, s15
 *   @0x19c904 vmrs APSR_nzcv, fpscr
 *   @0x19c908 bne 0x19c9bc <_Z18Motion_Linear_StepP9CInstancefffib+0x114>
 *   @0x19c90c vcmpe.f32 s15, s18
 *   @0x19c910 vmrs APSR_nzcv, fpscr
 *   @0x19c914 movls r6, #1
 *   @0x19c918 bhi 0x19c94c <_Z18Motion_Linear_StepP9CInstancefffib+0xa4>
 *   @0x19c91c str r5, [sp]
 *   @0x19c920 mov r0, r4
 *   @0x19c924 vmov r1, s16
 *   @0x19c928 ldr r3, [sp, #0x28]
 *   @0x19c92c vmov r2, s17
 *   @0x19c930 bl 0x19c6f4 <_Z8TestFreeP9CInstanceffib>
 *   @0x19c934 cmp r0, #0
 *   @0x19c938 moveq r0, r6
 *   @0x19c93c bne 0x19c97c <_Z18Motion_Linear_StepP9CInstancefffib+0xd4>
 *   @0x19c940 add sp, sp, #8
 *   @0x19c944 vpop {d8, d9}
 *   @0x19c948 pop {r4, r5, r6, pc}
 *   @0x19c94c vldr s13, [r4, #180]
 *   @0x19c950 vldr s14, [r4, #184]
 *   @0x19c954 vsub.f32 s16, s16, s13
 *   @0x19c958 mov r6, #0
 *   @0x19c95c vsub.f32 s17, s17, s14
 *   @0x19c960 vmul.f32 s16, s16, s18
 *   @0x19c964 vmul.f32 s18, s17, s18
 *   @0x19c968 vdiv.f32 s16, s16, s15
 *   @0x19c96c vdiv.f32 s15, s18, s15
 *   @0x19c970 vadd.f32 s16, s13, s16
 *   @0x19c974 vadd.f32 s17, s14, s15
 *   @0x19c978 b 0x19c91c <_Z18Motion_Linear_StepP9CInstancefffib+0x74>
 *   @0x19c97c vmov r2, s16
 *   @0x19c980 vmov r3, s17
 *   @0x19c984 ldr r1, [r4, #0xb8]
 *   @0x19c988 ldr r0, [r4, #0xb4]
 *   @0x19c98c bl 0x19c740 <_Z10ComputeDirffff>
 *   @0x19c990 mov r1, r0
 *   @0x19c994 mov r0, r4
 *   @0x19c998 bl 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x19c99c mov r0, r4
 *   @0x19c9a0 vmov r1, s16
 *   @0x19c9a4 vmov r2, s17
 *   @0x19c9a8 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x19c9ac mov r0, r6
 *   @0x19c9b0 add sp, sp, #8
 *   @0x19c9b4 vpop {d8, d9}
 *   @0x19c9b8 pop {r4, r5, r6, pc}
 *   @0x19c9bc vmov r0, s14
 *   @0x19c9c0 bl 0xb6700 <sqrtf@plt>
 *   @0x19c9c4 vmov s15, r0
 *   @0x19c9c8 b 0x19c90c <_Z18Motion_Linear_StepP9CInstancefffib+0x64>
 *
 * ══ §73/102 InitGraphics()  0x1df5f0  size 292  73 条（0x1df5f0..0x1df714）
 * @func 0x1df5f0 0x1df714  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1df5f8→0x5423b4, 0x1df610→0x3eb6b8, 0x1df634→0x542554, 0x1df638→0x3f5228, 0x1df63c→0x3f5224, 0x1df640→0x3f5220
 * 调用序列: GR_D3D_Init(void*, int, int, int) / Background_InitTextures() / Sprite_InitTextures() / Font_InitTextures() / Graphics::EndInit() / DisplaySet(int, int, int, int)
 * 字段偏移 top8: 0xc×4 / 0xbc×4 / 0xec×2 / 0xd8×2 / 0x88×1 / 0x74×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1df5f0 push {r3, r4, r5, lr}
 *   @0x1df5f4 ldr r4, [pc, #0xec]
 *   @0x1df5f8 ldr r3, [pc, #0xec]
 *   @0x1df5fc add r4, pc, r4
 *   @0x1df600 ldr r3, [r4, r3]
 *   @0x1df604 ldrb r3, [r3]
 *   @0x1df608 cmp r3, #0
 *   @0x1df60c bne 0x1df6d0 <_Z12InitGraphicsv+0xe0>
 *   @0x1df610 ldr r3, [pc, #0xd8]
 *   @0x1df614 ldr r1, [pc, #0xd8]
 *   @0x1df618 ldr r3, [r4, r3]
 *   @0x1df61c add r1, pc, r1
 *   @0x1df620 ldr r5, [r3]
 *   @0x1df624 ldr r3, [r5]
 *   @0x1df628 mov r0, r5
 *   @0x1df62c ldr r3, [r3, #0xc]
 *   @0x1df630 blx r3
 *   @0x1df634 ldr r0, [pc, #0xbc]
 *   @0x1df638 ldr r1, [pc, #0xbc]
 *   @0x1df63c ldr r2, [pc, #0xbc]
 *   @0x1df640 ldr r3, [pc, #0xbc]
 *   @0x1df644 ldr r0, [r4, r0]
 *   @0x1df648 ldr r1, [r4, r1]
 *   @0x1df64c ldr r2, [r4, r2]
 *   @0x1df650 ldr r3, [r4, r3]
 *   @0x1df654 ldr r0, [r0]
 *   @0x1df658 ldr r1, [r1]
 *   @0x1df65c ldr r2, [r2]
 *   @0x1df660 ldr r3, [r3]
 *   @0x1df664 bl 0x16973c <_Z11GR_D3D_InitPviii>
 *   @0x1df668 subs r4, r0, #0
 *   @0x1df66c beq 0x1df6c8 <_Z12InitGraphicsv+0xd8>
 *   @0x1df670 ldr r3, [r5]
 *   @0x1df674 mov r0, r5
 *   @0x1df678 ldr r1, [pc, #0x88]
 *   @0x1df67c ldr r3, [r3, #0xc]
 *   @0x1df680 add r1, pc, r1
 *   @0x1df684 blx r3
 *   @0x1df688 bl 0xc3578 <_Z23Background_InitTexturesv>
 *   @0x1df68c ldr r3, [r5]
 *   @0x1df690 ldr r1, [pc, #0x74]
 *   @0x1df694 mov r0, r5
 *   @0x1df698 add r1, pc, r1
 *   @0x1df69c ldr r3, [r3, #0xc]
 *   @0x1df6a0 blx r3
 *   @0x1df6a4 bl 0x1eedd0 <_Z19Sprite_InitTexturesv>
 *   @0x1df6a8 ldr r3, [r5]
 *   @0x1df6ac ldr r1, [pc, #0x5c]
 *   @0x1df6b0 mov r0, r5
 *   @0x1df6b4 add r1, pc, r1
 *   @0x1df6b8 ldr r3, [r3, #0xc]
 *   @0x1df6bc blx r3
 *   @0x1df6c0 bl 0xfac40 <_Z17Font_InitTexturesv>
 *   @0x1df6c4 bl 0x17dd44 <_ZN8Graphics7EndInitEv>
 *   @0x1df6c8 mov r0, r4
 *   @0x1df6cc pop {r3, r4, r5, pc}
 *   @0x1df6d0 mvn r0, #0
 *   @0x1df6d4 mov r1, r0
 *   @0x1df6d8 mov r2, r0
 *   @0x1df6dc mov r3, r0
 *   @0x1df6e0 bl 0x17db64 <_Z10DisplaySetiiii>
 *   @0x1df6e4 b 0x1df610 <_Z12InitGraphicsv+0x20>
 *   @0x1df6e8 eoreq r2, r1, r4, asr r6
 *   @0x1df6ec .word 0xffffeab4
 *   @0x1df6f0 .word 0xffffdecc
 *   @0x1df6f4 andseq r2, r7, r4, lsr #8
 *   @0x1df6f8 .word 0xffffeba4
 *   @0x1df6fc .word 0xfffff05c
 *   @0x1df700 .word 0xfffff060
 *   @0x1df704 .word 0xfffff064
 *   @0x1df708 ldrsbeq r2, [r7], -r0
 *   @0x1df70c ldrsbeq r2, [r7], -r4
 *   @0x1df710 ldrsbeq r2, [r7], -r0
 *
 * ══ §74/102 SV_Depth(CInstance*, int, RValue*)  0x1fb148  size 292  73 条（0x1fb148..0x1fb26c）
 * @func 0x1fb148 0x1fb26c  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::ChangeInstanceDepth(CRoom*, CInstance*) / SV_Depth(CInstance*, int, RValue*)+0xb8 / REAL_RValue_Ex(RValue const*) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×3 / 0x4×3 / 0xc×1 / 0xc4×1 / 0xc0×1 / 0x2×1 / 0x38×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb148 ldr r3, [r2, #0xc]
 *   @0x1fb14c push {r4, r5, r6, lr}
 *   @0x1fb150 vpush {d8}
 *   @0x1fb154 bic r3, r3, #-16777216
 *   @0x1fb158 vldr s16, [r0, #384]
 *   @0x1fb15c cmp r3, #0
 *   @0x1fb160 sub sp, sp, #8
 *   @0x1fb164 mov r4, r0
 *   @0x1fb168 bne 0x1fb21c <_Z8SV_DepthP9CInstanceiP6RValue+0xd4>
 *   @0x1fb16c ldm r2, {r0, r1}
 *   @0x1fb170 vmov d6, r0, r1
 *   @0x1fb174 vcvt.f32.f64 s15, d6
 *   @0x1fb178 vcmp.f32 s16, s15
 *   @0x1fb17c vmrs APSR_nzcv, fpscr
 *   @0x1fb180 bne 0x1fb194 <_Z8SV_DepthP9CInstanceiP6RValue+0x4c>
 *   @0x1fb184 mov r0, #1
 *   @0x1fb188 add sp, sp, #8
 *   @0x1fb18c vpop {d8}
 *   @0x1fb190 pop {r4, r5, r6, pc}
 *   @0x1fb194 ldr r3, [pc, #0xc4]
 *   @0x1fb198 mov r1, r4
 *   @0x1fb19c ldr r5, [pc, #0xc0]
 *   @0x1fb1a0 vstr s15, [r4, #384]
 *   @0x1fb1a4 ldr r3, [pc, r3]
 *   @0x1fb1a8 ldr r0, [r3]
 *   @0x1fb1ac bl 0x1c5f40 <_ZN13CLayerManager19ChangeInstanceDepthEP5CRoomP9CInstance>
 *   @0x1fb1b0 ldr r5, [pc, r5]
 *   @0x1fb1b4 ldr r1, [r5, #0x8]
 *   @0x1fb1b8 ldr r3, [r5, #0x4]
 *   @0x1fb1bc cmp r1, r3
 *   @0x1fb1c0 beq 0x1fb228 <_Z8SV_DepthP9CInstanceiP6RValue+0xe0>
 *   @0x1fb1c4 ldr r6, [r5]
 *   @0x1fb1c8 cmp r1, #0
 *   @0x1fb1cc ble 0x1fb200 <_Z8SV_DepthP9CInstanceiP6RValue+0xb8>
 *   @0x1fb1d0 ldr r3, [r6]
 *   @0x1fb1d4 cmp r4, r3
 *   @0x1fb1d8 beq 0x1fb184 <_Z8SV_DepthP9CInstanceiP6RValue+0x3c>
 *   @0x1fb1dc mov r2, r6
 *   @0x1fb1e0 mov r3, #0
 *   @0x1fb1e4 b 0x1fb1f4 <_Z8SV_DepthP9CInstanceiP6RValue+0xac>
 *   @0x1fb1e8 ldr r12, [r2, #0x4]!
 *   @0x1fb1ec cmp r4, r12
 *   @0x1fb1f0 beq 0x1fb184 <_Z8SV_DepthP9CInstanceiP6RValue+0x3c>
 *   @0x1fb1f4 add r3, r3, #1
 *   @0x1fb1f8 cmp r3, r1
 *   @0x1fb1fc bne 0x1fb1e8 <_Z8SV_DepthP9CInstanceiP6RValue+0xa0>
 *   @0x1fb200 str r4, [r6, r1, lsl #2]
 *   @0x1fb204 mov r0, #1
 *   @0x1fb208 add r1, r1, #1
 *   @0x1fb20c str r1, [r5, #0x8]
 *   @0x1fb210 add sp, sp, #8
 *   @0x1fb214 vpop {d8}
 *   @0x1fb218 pop {r4, r5, r6, pc}
 *   @0x1fb21c mov r0, r2
 *   @0x1fb220 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb224 b 0x1fb170 <_Z8SV_DepthP9CInstanceiP6RValue+0x28>
 *   @0x1fb228 ldr r2, [pc, #0x38]
 *   @0x1fb22c lsl r3, r1, #1
 *   @0x1fb230 ldr r0, [r5]
 *   @0x1fb234 lsl r1, r1, #3
 *   @0x1fb238 str r3, [r5, #0x4]
 *   @0x1fb23c add r2, pc, r2
 *   @0x1fb240 mov r3, #0
 *   @0x1fb244 str r3, [sp]
 *   @0x1fb248 mov r3, #74
 *   @0x1fb24c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1fb250 ldr r1, [r5, #0x8]
 *   @0x1fb254 mov r6, r0
 *   @0x1fb258 str r0, [r5]
 *   @0x1fb25c b 0x1fb1c8 <_Z8SV_DepthP9CInstanceiP6RValue+0x80>
 *   @0x1fb260 andseq r2, pc, r4, lsl #15
 *   @0x1fb264 ldrsheq r2, [pc], -r4
 *   @0x1fb268 ldrsheq r5, [r3], -r4
 *
 * ══ §75/102 Audio_GetSound(int)  0x21632c  size 292  73 条（0x21632c..0x216450）
 * @func 0x21632c 0x216450  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetSound(int)+0xc8×6 / Audio_GetSound(int)+0xd0 / Audio_GetSound(int)+0xe0
 * 字段偏移 top8: 0x2×4 / 0x10c×1 / 0x20×1 / 0x28×1 / 0x30×1 / 0x34×1 / 0x80×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21632c cmp r0, #0
 *   @0x216330 blt 0x2163f4 <_Z14Audio_GetSoundi+0xc8>
 *   @0x216334 ldr r3, [pc, #0x10c]
 *   @0x216338 add r3, pc, r3
 *   @0x21633c ldr r2, [r3, #0x20]
 *   @0x216340 cmp r0, r2
 *   @0x216344 ble 0x2163fc <_Z14Audio_GetSoundi+0xd0>
 *   @0x216348 movw r2, #0x869f
 *   @0x21634c movt r2, #0x1
 *   @0x216350 cmp r0, r2
 *   @0x216354 ble 0x2163f4 <_Z14Audio_GetSoundi+0xc8>
 *   @0x216358 movw r2, #0x7961
 *   @0x21635c ldr r1, [r3, #0x28]
 *   @0x216360 movt r2, #0xfffe
 *   @0x216364 add r2, r0, r2
 *   @0x216368 cmp r2, r1
 *   @0x21636c ble 0x21640c <_Z14Audio_GetSoundi+0xe0>
 *   @0x216370 movw r2, #0xd3f
 *   @0x216374 movt r2, #0x3
 *   @0x216378 cmp r0, r2
 *   @0x21637c ble 0x2163f4 <_Z14Audio_GetSoundi+0xc8>
 *   @0x216380 movw r2, #0xf2c1
 *   @0x216384 ldr r1, [r3, #0x30]
 *   @0x216388 movt r2, #0xfffc
 *   @0x21638c add r2, r0, r2
 *   @0x216390 cmp r2, r1
 *   @0x216394 bgt 0x2163b4 <_Z14Audio_GetSoundi+0x88>
 *   @0x216398 sub r0, r0, #199680
 *   @0x21639c sub r0, r0, #320
 *   @0x2163a0 cmp r1, r0
 *   @0x2163a4 ble 0x2163f4 <_Z14Audio_GetSoundi+0xc8>
 *   @0x2163a8 ldr r3, [r3, #0x34]
 *   @0x2163ac ldr r0, [r3, r0, lsl #2]
 *   @0x2163b0 bx lr
 *   @0x2163b4 movw r3, #0x93df
 *   @0x2163b8 movt r3, #0x4
 *   @0x2163bc cmp r0, r3
 *   @0x2163c0 ble 0x2163f4 <_Z14Audio_GetSoundi+0xc8>
 *   @0x2163c4 ldr r2, [pc, #0x80]
 *   @0x2163c8 movw r3, #0x6c21
 *   @0x2163cc movt r3, #0xfffb
 *   @0x2163d0 ldr r2, [pc, r2]
 *   @0x2163d4 add r3, r0, r3
 *   @0x2163d8 ldr r1, [r2]
 *   @0x2163dc cmp r3, r1
 *   @0x2163e0 bgt 0x2163f4 <_Z14Audio_GetSoundi+0xc8>
 *   @0x2163e4 sub r0, r0, #299008
 *   @0x2163e8 sub r0, r0, #992
 *   @0x2163ec cmp r1, r0
 *   @0x2163f0 bgt 0x216428 <_Z14Audio_GetSoundi+0xfc>
 *   @0x2163f4 mov r0, #0
 *   @0x2163f8 bx lr
 *   @0x2163fc bge 0x2163f4 <_Z14Audio_GetSoundi+0xc8>
 *   @0x216400 ldr r3, [r3, #0x24]
 *   @0x216404 ldr r0, [r3, r0, lsl #2]
 *   @0x216408 bx lr
 *   @0x21640c sub r0, r0, #99328
 *   @0x216410 sub r0, r0, #672
 *   @0x216414 cmp r1, r0
 *   @0x216418 ble 0x2163f4 <_Z14Audio_GetSoundi+0xc8>
 *   @0x21641c ldr r3, [r3, #0x2c]
 *   @0x216420 ldr r0, [r3, r0, lsl #2]
 *   @0x216424 bx lr
 *   @0x216428 ldr r3, [r2, #0x4]
 *   @0x21642c ldr r0, [r3, r0, lsl #2]
 *   @0x216430 cmp r0, #0
 *   @0x216434 bxeq lr
 *   @0x216438 ldrb r3, [r0, #0x27]
 *   @0x21643c cmp r3, #0
 *   @0x216440 movne r0, #0
 *   @0x216444 bx lr
 *   @0x216448 subseq lr, r3, r12, asr pc
 *   @0x21644c andseq r11, sp, r8
 *
 * ══ §76/102 Audio_SetEmitterPitch(int, double)  0x2181bc  size 292  73 条（0x2181bc..0x2182e0）
 * @func 0x2181bc 0x2182e0  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_SetEmitterPitch(int, double)+0x10c×3 / Audio_SetEmitterPitch(int, double)+0x100 / Audio_GetSound(int) / 0xb6a78
 * 字段偏移 top8: 0x2×3 / 0x34×2 / 0x10×2 / 0x10c×1 / 0xf0×1 / 0xcc×1 / 0x40×1 / 0x44×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2181bc ldr r1, [pc, #0x10c]
 *   @0x2181c0 push {r3, r4, r5, r6, r7, lr}
 *   @0x2181c4 vpush {d8}
 *   @0x2181c8 ldr r1, [pc, r1]
 *   @0x2181cc vmov d8, r2, r3
 *   @0x2181d0 ldrb r4, [r1]
 *   @0x2181d4 cmp r4, #0
 *   @0x2181d8 bne 0x2182c8 <_Z21Audio_SetEmitterPitchid+0x10c>
 *   @0x2181dc ldr r3, [pc, #0xf0]
 *   @0x2181e0 ldr r3, [pc, r3]
 *   @0x2181e4 ldrb r3, [r3]
 *   @0x2181e8 cmp r3, #0
 *   @0x2181ec beq 0x2182c8 <_Z21Audio_SetEmitterPitchid+0x10c>
 *   @0x2181f0 vcmpe.f64 d8, #0
 *   @0x2181f4 vmrs APSR_nzcv, fpscr
 *   @0x2181f8 blt 0x2182c8 <_Z21Audio_SetEmitterPitchid+0x10c>
 *   @0x2181fc cmp r0, #0
 *   @0x218200 blt 0x2182c8 <_Z21Audio_SetEmitterPitchid+0x10c>
 *   @0x218204 ldr r3, [pc, #0xcc]
 *   @0x218208 add r3, pc, r3
 *   @0x21820c ldr r2, [r3, #0x40]
 *   @0x218210 cmp r0, r2
 *   @0x218214 bge 0x2182c8 <_Z21Audio_SetEmitterPitchid+0x10c>
 *   @0x218218 ldr r3, [r3, #0x44]
 *   @0x21821c vcvt.f32.f64 s15, d8
 *   @0x218220 ldr r6, [r3, r0, lsl #2]
 *   @0x218224 ldr r7, [r6, #0x34]
 *   @0x218228 vstr s15, [r6, #44]
 *   @0x21822c cmp r7, #0
 *   @0x218230 ble 0x2182c8 <_Z21Audio_SetEmitterPitchid+0x10c>
 *   @0x218234 mov r3, r7
 *   @0x218238 b 0x218240 <_Z21Audio_SetEmitterPitchid+0x84>
 *   @0x21823c ldr r3, [r6, #0x34]
 *   @0x218240 cmp r4, r3
 *   @0x218244 bge 0x2182bc <_Z21Audio_SetEmitterPitchid+0x100>
 *   @0x218248 ldr r3, [r6, #0x38]
 *   @0x21824c ldr r5, [r3, r4, lsl #2]
 *   @0x218250 cmp r5, #0
 *   @0x218254 beq 0x2182bc <_Z21Audio_SetEmitterPitchid+0x100>
 *   @0x218258 ldrb r3, [r5, #0x5]
 *   @0x21825c cmp r3, #0
 *   @0x218260 beq 0x2182bc <_Z21Audio_SetEmitterPitchid+0x100>
 *   @0x218264 ldr r3, [r5, #0x8]
 *   @0x218268 cmp r3, #0
 *   @0x21826c bne 0x2182bc <_Z21Audio_SetEmitterPitchid+0x100>
 *   @0x218270 ldr r3, [r5, #0x10]
 *   @0x218274 cmp r3, #0
 *   @0x218278 blt 0x2182bc <_Z21Audio_SetEmitterPitchid+0x100>
 *   @0x21827c ldr r0, [r5, #0x18]
 *   @0x218280 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x218284 ldr r3, [pc, #0x50]
 *   @0x218288 movw r1, #0x1003
 *   @0x21828c cmp r0, #0
 *   @0x218290 beq 0x2182bc <_Z21Audio_SetEmitterPitchid+0x100>
 *   @0x218294 vldr s14, [r6, #44]
 *   @0x218298 vcvt.f64.f32 d7, s14
 *   @0x21829c ldr r3, [pc, r3]
 *   @0x2182a0 ldr r2, [r5, #0x10]
 *   @0x2182a4 ldr r3, [r3]
 *   @0x2182a8 ldr r0, [r3, r2, lsl #2]
 *   @0x2182ac vmul.f64 d7, d7, d8
 *   @0x2182b0 vcvt.f32.f64 s13, d7
 *   @0x2182b4 vmov r2, s13
 *   @0x2182b8 bl 0xb6a78 <alSourcef@plt>
 *   @0x2182bc add r4, r4, #1
 *   @0x2182c0 cmp r4, r7
 *   @0x2182c4 bne 0x21823c <_Z21Audio_SetEmitterPitchid+0x80>
 *   @0x2182c8 vpop {d8}
 *   @0x2182cc pop {r3, r4, r5, r6, r7, pc}
 *   @0x2182d0 andseq r6, sp, r4, lsl #29
 *   @0x2182d4 andseq r6, sp, r0, asr r11
 *   @0x2182d8 subseq sp, r3, r12, lsl #1
 *   @0x2182dc andseq r9, sp, r0, lsr r1
 *
 * ══ §77/102 ov_time_tell  0x232d04  size 292  73 条（0x232d04..0x232e28）
 * @func 0x232d04 0x232e28  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_time_total×2 / ov_time_tell+0x108 / anon_319414 / ov_pcm_total / ov_time_tell+0xf8 / ov_time_tell+0xa8
 * 字段偏移 top8: 0x50×2 / 0x54×2 / 0x58×1 / 0x4×1 / 0x48×1 / 0x8×1 / 0x34×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x232d04 ldr r3, [r0, #0x58]
 *   @0x232d08 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x232d0c cmp r3, #1
 *   @0x232d10 mov r8, r0
 *   @0x232d14 ble 0x232e0c <ov_time_tell+0x108>
 *   @0x232d18 ldr r9, [r0, #0x4]
 *   @0x232d1c cmp r9, #0
 *   @0x232d20 bne 0x232d70 <ov_time_tell+0x6c>
 *   @0x232d24 ldr r0, [r0, #0x50]
 *   @0x232d28 mov r6, #0
 *   @0x232d2c ldr lr, [r8, #0x54]
 *   @0x232d30 mov r7, #0
 *   @0x232d34 mov r4, r6
 *   @0x232d38 mov r5, r7
 *   @0x232d3c mov r12, #1000
 *   @0x232d40 ldr r3, [r8, #0x48]
 *   @0x232d44 umull r0, r1, r0, r12
 *   @0x232d48 add r9, r3, r9
 *   @0x232d4c ldr r2, [r9, #0x8]
 *   @0x232d50 mla r1, r12, lr, r1
 *   @0x232d54 asr r3, r2, #31
 *   @0x232d58 subs r0, r0, r4
 *   @0x232d5c sbc r1, r1, r5
 *   @0x232d60 bl 0x319414 <__aeabi_ldivmod>
 *   @0x232d64 adds r0, r0, r6
 *   @0x232d68 adc r1, r1, r7
 *   @0x232d6c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x232d70 mvn r1, #0
 *   @0x232d74 bl 0x23138c <ov_pcm_total>
 *   @0x232d78 mov r4, r0
 *   @0x232d7c mov r5, r1
 *   @0x232d80 mov r0, r8
 *   @0x232d84 mvn r1, #0
 *   @0x232d88 bl 0x231424 <ov_time_total>
 *   @0x232d8c ldr r9, [r8, #0x34]
 *   @0x232d90 subs r9, r9, #1
 *   @0x232d94 lslpl r10, r9, #4
 *   @0x232d98 addpl r10, r10, #8
 *   @0x232d9c mov r6, r0
 *   @0x232da0 mov r7, r1
 *   @0x232da4 bpl 0x232db4 <ov_time_tell+0xb0>
 *   @0x232da8 b 0x232e18 <ov_time_tell+0x114>
 *   @0x232dac subs r9, r9, #1
 *   @0x232db0 blo 0x232dfc <ov_time_tell+0xf8>
 *   @0x232db4 ldr r3, [r8, #0x44]
 *   @0x232db8 mov r0, r8
 *   @0x232dbc mov r1, r9
 *   @0x232dc0 ldrd r2, r3, [r3, r10]
 *   @0x232dc4 sub r10, r10, #16
 *   @0x232dc8 subs r4, r4, r2
 *   @0x232dcc sbc r5, r5, r3
 *   @0x232dd0 bl 0x231424 <ov_time_total>
 *   @0x232dd4 ldrd r2, r3, [r8, #80]
 *   @0x232dd8 subs r6, r6, r0
 *   @0x232ddc sbc r7, r7, r1
 *   @0x232de0 cmp r2, r4
 *   @0x232de4 sbcs r1, r3, r5
 *   @0x232de8 blt 0x232dac <ov_time_tell+0xa8>
 *   @0x232dec lsl r9, r9, #5
 *   @0x232df0 mov r0, r2
 *   @0x232df4 mov lr, r3
 *   @0x232df8 b 0x232d3c <ov_time_tell+0x38>
 *   @0x232dfc mov r0, r2
 *   @0x232e00 mov lr, r3
 *   @0x232e04 mvn r9, #31
 *   @0x232e08 b 0x232d3c <ov_time_tell+0x38>
 *   @0x232e0c mvn r0, #130
 *   @0x232e10 mvn r1, #0
 *   @0x232e14 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x232e18 lsl r9, r9, #5
 *   @0x232e1c ldr r0, [r8, #0x50]
 *   @0x232e20 ldr lr, [r8, #0x54]
 *   @0x232e24 b 0x232d3c <ov_time_tell+0x38>
 *
 * ══ §78/102 anon_2336e0  0x2336e0  size 292  73 条（0x2336e0..0x233804）
 * @func 0x2336e0 0x233804  size 292  73 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2336e0+0x5c / anon_2336e0+0xf0 / 0xb6c28 / 0xb6694
 * 字段偏移 top8: 0xc×4 / 0x10×2 / 0x8×2 / 0x4×1 / 0x28×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2336e0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2336e4 mov r8, r2
 *   @0x2336e8 ldr r2, [r0, #0x4]
 *   @0x2336ec cmp r8, #0
 *   @0x2336f0 add r9, r8, #7
 *   @0x2336f4 mov r5, r0
 *   @0x2336f8 movge r9, r8
 *   @0x2336fc cmp r2, #0
 *   @0x233700 mov r10, r1
 *   @0x233704 mov r6, r3
 *   @0x233708 asr r9, r9, #3
 *   @0x23370c ldr r11, [sp, #0x28]
 *   @0x233710 beq 0x233768 <oggpackB_writealign+0xa0>
 *   @0x233714 cmp r9, #0
 *   @0x233718 ble 0x23373c <oggpackB_writealign+0x74>
 *   @0x23371c add r7, r1, r9
 *   @0x233720 mov r4, r1
 *   @0x233724 ldrb r1, [r4], #1
 *   @0x233728 mov r0, r5
 *   @0x23372c mov r2, #8
 *   @0x233730 blx r6
 *   @0x233734 cmp r4, r7
 *   @0x233738 bne 0x233724 <oggpackB_writealign+0x5c>
 *   @0x23373c subs r2, r8, r9, lsl #3
 *   @0x233740 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x233744 cmp r11, #0
 *   @0x233748 rsbne r3, r2, #8
 *   @0x23374c ldrbne r1, [r10, r9]
 *   @0x233750 movne r0, r5
 *   @0x233754 moveq r0, r5
 *   @0x233758 ldrbeq r1, [r10, r9]
 *   @0x23375c asrne r1, r1, r3
 *   @0x233760 blx r6
 *   @0x233764 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x233768 ldr r3, [r0]
 *   @0x23376c ldr r2, [r0, #0x10]
 *   @0x233770 add r3, r9, r3
 *   @0x233774 add r1, r3, #1
 *   @0x233778 cmp r1, r2
 *   @0x23377c ldrlt r0, [r0, #0xc]
 *   @0x233780 blt 0x2337d0 <oggpackB_writealign+0x108>
 *   @0x233784 ldr r1, [r5, #0xc]
 *   @0x233788 cmp r1, #0
 *   @0x23378c beq 0x23379c <oggpackB_writealign+0xd4>
 *   @0x233790 add r1, r3, #255
 *   @0x233794 cmp r2, r1
 *   @0x233798 bgt 0x2337a8 <oggpackB_writealign+0xe0>
 *   @0x23379c mov r0, r5
 *   @0x2337a0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2337a4 b 0x23339c <oggpack_writeclear>
 *   @0x2337a8 add r1, r3, #256
 *   @0x2337ac ldr r0, [r5, #0x8]
 *   @0x2337b0 str r1, [r5, #0x10]
 *   @0x2337b4 bl 0xb6c28 <realloc@plt>
 *   @0x2337b8 cmp r0, #0
 *   @0x2337bc beq 0x23379c <oggpackB_writealign+0xd4>
 *   @0x2337c0 ldr r3, [r5]
 *   @0x2337c4 str r0, [r5, #0x8]
 *   @0x2337c8 add r0, r0, r3
 *   @0x2337cc str r0, [r5, #0xc]
 *   @0x2337d0 mov r1, r10
 *   @0x2337d4 mov r2, r9
 *   @0x2337d8 bl 0xb6694 <memmove@plt>
 *   @0x2337dc ldr r3, [r5, #0xc]
 *   @0x2337e0 ldr r1, [r5]
 *   @0x2337e4 mov r2, #0
 *   @0x2337e8 add r0, r3, r9
 *   @0x2337ec str r0, [r5, #0xc]
 *   @0x2337f0 add r1, r1, r9
 *   @0x2337f4 str r1, [r5]
 *   @0x2337f8 strb r2, [r3, r9]
 *   @0x2337fc subs r2, r8, r9, lsl #3
 *   @0x233800 bne 0x233744 <oggpackB_writealign+0x7c>
 *
 * ══ §79/102 png_set_pCAL  0x2aeb24  size 292  73 条（0x2aeb24..0x2aec48）
 * @func 0x2aeb24 0x2aec48  size 292  73 条
 * 部分覆盖: 本节 73/133 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc×2 / anon_2e9c78+0x3260 / 0x32a010 / png_malloc_warn
 * 字段偏移 top8: 0x38×1 / 0x3c×1 / 0x9c×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aeb24 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2aeb28 mov r11, r3
 *   @0x2aeb2c mov r4, r1
 *   @0x2aeb30 .word 0x46059034
 *   @0x2aeb34 ldr r7, [sp, #0x38]
 *   @0x2aeb38 ldr r6, [sp, #0x3c]
 *   @0x2aeb3c stmdahs r0, {r6, pc}
 *   @0x2aeb40 beq 0x2aec32 <png_set_pCAL+0x10e>
 *   @0x2aeb44 beq 0x2aec32 <png_set_pCAL+0x10e>
 *   @0x2aeb48 str r2, [sp]
 *   @0x2aeb4c .word 0xf100ecf6
 *   @0x2aeb50 strtmi r0, [r8], -r1, lsl #20
 *   @0x2aeb54 mov r1, r10
 *   @0x2aeb58 bls 0x2eced8 <FT_Done_Memory+0x3264>
 *   @0x2aeb5c str.w r0, [r4, #0xa0]
 *   @0x2aeb60 cbnz r0, 0x2aeb6a <png_set_pCAL+0x46>
 *   @0x2aeb64 mov r0, r5
 *   @0x2aeb68 b 0x2aec14 <png_set_pCAL+0xf0>
 *   @0x2aeb6c mov r2, r10
 *   @0x2aeb70 blls 0x32a010
 *   @0x2aeb74 strb.w r9, [r4, #0xb4]
 *   @0x2aeb78 mov r0, r6
 *   @0x2aeb7c .word 0xf8c4b0a4
 *   @0x2aeb80 .word 0xf88430a8
 *   @0x2aeb84 .word 0xf60770b5
 *   @0x2aeb88 .word 0xf100ecd8
 *   @0x2aeb8c strtmi r0, [r8], -r1, lsl #18
 *   @0x2aeb90 mov r1, r9
 *   @0x2aeb94 .word 0xf8c4f8c0
 *   @0x2aeb98 ldmdblt r8, {r2, r3, r5, r7}
 *   @0x2aeb9c ldr r1, [pc, #0x9c]
 *   @0x2aeba0 add r1, pc
 *   @0x2aeba4 mov r1, r6
 *   @0x2aeba8 mov r2, r9
 *   @0x2aebac blx 0xb65bc <memcpy@plt>
 *   @0x2aebb0 mov r0, r5
 *   @0x2aebb4 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2aebb8 str.w r0, [r4, #0xb0]
 *   @0x2aebbc cbnz r0, 0x2aebc6 <png_set_pCAL+0xa2>
 *   @0x2aebc0 mov r0, r5
 *   @0x2aebc4 b 0x2aec14 <png_set_pCAL+0xf0>
 *   @0x2aebc8 movs r1, #0x0
 *   @0x2aebcc .word 0xf1a8ecf2
 *   @0x2aebd0 strhs r0, [r0], -r4, lsl #16
 *   @0x2aebd4 b 0x2aebe2 <png_set_pCAL+0xbe>
 *   @0x2aebd8 strbmi r1, [r10], -r4, lsl #30
 *   @0x2aebdc blx 0xb65bc <memcpy@plt>
 *   @0x2aebe0 adds r6, #0x1
 *   @0x2aebe4 bge 0x2aec1e <png_set_pCAL+0xfa>
 *   @0x2aebe8 .word 0xf6070004
 *   @0x2aebec .word 0xf8d4eca6
 *   @0x2aebf0 .word 0xf100a0b0
 *   @0x2aebf4 strtmi r0, [r8], -r1, lsl #18
 *   @0x2aebf8 mov r1, r9
 *   @0x2aebfc .word 0xf84af88c
 *   @0x2aec00 .word 0xf8d40026
 *   @0x2aec04 .word 0xf85330b0
 *   @0x2aec08 stmdahs r0, {r1, r2, r5}
 *   @0x2aec0c bne 0x2aebd6 <png_set_pCAL+0xb2>
 *   @0x2aec10 mov r0, r5
 *   @0x2aec14 add sp, #0xc
 *   @0x2aec18 .word 0xf7f74ff0
 *   @0x2aec1c stmvs r3!, {r0, r1, r3, r5, r10, r11, r12, sp, pc}
 *   @0x2aec20 orr r3, r3, #0x400
 *   @0x2aec24 str r3, [r4, #0x8]
 *   @0x2aec28 .word 0xf04330b8
 *   @0x2aec2c .word 0xf8c40380
 *   @0x2aec30 strhlt r3, [r3], -r8
 *   @0x2aec34 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2aec38 vext.32 d0, d0, d13, #0x0
 *   @0x2aec3c vaddl.s16 q0, d11, d13
 *   @0x2aec40 vaddl.s16 q0, d12, d13
 *   @0x2aec44 .word 0xef70 000d
 *
 * ══ §80/102 F_BUFFER_Copy(RValue&, CInstance*, CInstance*, int, RValue*)  0xc56a0  size 288  72 条（0xc56a0..0xc57c0）
 * @func 0xc56a0 0xc57c0  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_BUFFER_Copy(RValue&, CInstance*, CInstance*, int, RValue*)+0xec×2
 * 字段偏移 top8: 0x4×4 / 0x2×4 / 0xc×1 / 0x28×1 / 0xdc×1 / 0x38×1 / 0x24×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc56a0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc56a4 sub sp, sp, #8
 *   @0xc56a8 mov r4, #0
 *   @0xc56ac str r4, [r0, #0xc]
 *   @0xc56b0 ldr r6, [sp, #0x28]
 *   @0xc56b4 mov r1, r4
 *   @0xc56b8 str r4, [r0]
 *   @0xc56bc str r4, [r0, #0x4]
 *   @0xc56c0 mov r0, r6
 *   @0xc56c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc56c8 subs r7, r0, #0
 *   @0xc56cc blt 0xc578c <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0xc56d0 ldr r5, [pc, #0xdc]
 *   @0xc56d4 add r5, pc, r5
 *   @0xc56d8 ldr r3, [r5]
 *   @0xc56dc cmp r7, r3
 *   @0xc56e0 bge 0xc578c <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0xc56e4 ldr r3, [r5, #0x4]
 *   @0xc56e8 ldr r3, [r3, r7, lsl #2]
 *   @0xc56ec cmp r3, #0
 *   @0xc56f0 beq 0xc578c <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0xc56f4 mov r0, r6
 *   @0xc56f8 mov r1, #3
 *   @0xc56fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5700 subs r8, r0, #0
 *   @0xc5704 blt 0xc578c <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0xc5708 ldr r3, [r5]
 *   @0xc570c cmp r8, r3
 *   @0xc5710 bge 0xc578c <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0xc5714 ldr r3, [r5, #0x4]
 *   @0xc5718 ldr r2, [r3, r8, lsl #2]
 *   @0xc571c cmp r2, #0
 *   @0xc5720 beq 0xc578c <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0xc5724 cmp r7, r8
 *   @0xc5728 beq 0xc57a4 <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0xc572c ldr r4, [r3, r7, lsl #2]
 *   @0xc5730 mov r0, r6
 *   @0xc5734 mov r1, #1
 *   @0xc5738 ldr r3, [r4]
 *   @0xc573c ldr r7, [r3, #0x38]
 *   @0xc5740 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5744 mov r1, #2
 *   @0xc5748 mov r10, r0
 *   @0xc574c mov r0, r6
 *   @0xc5750 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5754 ldr r3, [r5, #0x4]
 *   @0xc5758 mov r1, #4
 *   @0xc575c ldr r5, [r3, r8, lsl #2]
 *   @0xc5760 mov r9, r0
 *   @0xc5764 mov r0, r6
 *   @0xc5768 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc576c mov r1, r10
 *   @0xc5770 mov r2, r9
 *   @0xc5774 mov r3, r5
 *   @0xc5778 str r0, [sp]
 *   @0xc577c mov r0, r4
 *   @0xc5780 blx r7
 *   @0xc5784 add sp, sp, #8
 *   @0xc5788 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xc578c ldr r0, [pc, #0x24]
 *   @0xc5790 mov r1, #0
 *   @0xc5794 add r0, pc, r0
 *   @0xc5798 add sp, sp, #8
 *   @0xc579c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc57a0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc57a4 ldr r0, [pc, #0x10]
 *   @0xc57a8 mov r1, r4
 *   @0xc57ac add r0, pc, r0
 *   @0xc57b0 b 0xc5798 <_Z13F_BUFFER_CopyR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0xc57b4 eorseq r4, r11, r0, asr #20
 *   @0xc57b8 eoreq r11, r6, r0, ror r4
 *   @0xc57bc eoreq r11, r6, r4, ror r4
 *
 * ══ §81/102 F_Vertex_Colour_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8130  size 288  72 条（0xc8130..0xc8250）
 * @func 0xc8130 0xc8250  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_Vertex_Colour_release(RValue&, CInstance*, CInstance*, int, RValue*)+0xdc / YYGetUint32(RValue const*, int) / YYGetFloat(RValue const*, int) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×4 / 0x4×2 / 0x14×2 / 0x10×2 / 0x108×1 / 0x20×1 / 0x2×1 / 0x2c×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8130 push {r4, r5, r6, r7, lr}
 *   @0xc8134 sub sp, sp, #12
 *   @0xc8138 ldr r3, [pc, #0x108]
 *   @0xc813c mov r1, #0
 *   @0xc8140 ldr r5, [sp, #0x20]
 *   @0xc8144 add r3, pc, r3
 *   @0xc8148 mov r0, r5
 *   @0xc814c ldr r4, [r3]
 *   @0xc8150 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc8154 ldr r4, [r4, r0, lsl #2]
 *   @0xc8158 ldr r1, [r4, #0x2c]
 *   @0xc815c ldr r3, [r4, #0xc]
 *   @0xc8160 ldr r2, [r4, #0x4]
 *   @0xc8164 ldr r1, [r1, #0x14]
 *   @0xc8168 add r0, r1, r3
 *   @0xc816c cmp r2, r0
 *   @0xc8170 blo 0xc820c <_Z23F_Vertex_Colour_releaseR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0xc8174 ldr r6, [r4]
 *   @0xc8178 mov r1, #1
 *   @0xc817c mov r0, r5
 *   @0xc8180 add r6, r6, r3
 *   @0xc8184 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc8188 mov r1, #2
 *   @0xc818c mov r7, r0
 *   @0xc8190 mov r0, r5
 *   @0xc8194 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc8198 vldr s15, [pc, #164]
 *   @0xc819c vmov s14, r0
 *   @0xc81a0 vmul.f32 s15, s14, s15
 *   @0xc81a4 vcvt.s32.f32 s15, s15
 *   @0xc81a8 vmov r2, s15
 *   @0xc81ac cmp r2, #255
 *   @0xc81b0 movgt r2, #-16777216
 *   @0xc81b4 bgt 0xc81c4 <_Z23F_Vertex_Colour_releaseR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0xc81b8 cmp r2, #0
 *   @0xc81bc lslge r2, r2, #24
 *   @0xc81c0 movlt r2, #0
 *   @0xc81c4 bic r7, r7, #-16777216
 *   @0xc81c8 orr r7, r2, r7
 *   @0xc81cc str r7, [r6]
 *   @0xc81d0 ldr r3, [r4, #0x10]
 *   @0xc81d4 ldr r1, [r4, #0x14]
 *   @0xc81d8 add r3, r3, #1
 *   @0xc81dc ldr r2, [r4, #0xc]
 *   @0xc81e0 cmp r3, r1
 *   @0xc81e4 str r3, [r4, #0x10]
 *   @0xc81e8 add r3, r2, #4
 *   @0xc81ec str r3, [r4, #0xc]
 *   @0xc81f0 ldrhs r3, [r4, #0x1c]
 *   @0xc81f4 movhs r2, #0
 *   @0xc81f8 strhs r2, [r4, #0x10]
 *   @0xc81fc addhs r3, r3, #1
 *   @0xc8200 strhs r3, [r4, #0x1c]
 *   @0xc8204 add sp, sp, #12
 *   @0xc8208 pop {r4, r5, r6, r7, pc}
 *   @0xc820c add r1, r1, r2
 *   @0xc8210 ldr r0, [r4]
 *   @0xc8214 add r1, r1, r2, lsr #1
 *   @0xc8218 mov r2, #0
 *   @0xc821c str r1, [r4, #0x4]
 *   @0xc8220 mov r3, #74
 *   @0xc8224 str r2, [sp]
 *   @0xc8228 ldr r2, [pc, #0x1c]
 *   @0xc822c add r2, pc, r2
 *   @0xc8230 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xc8234 ldr r3, [r4, #0xc]
 *   @0xc8238 mov r6, r0
 *   @0xc823c str r0, [r4]
 *   @0xc8240 b 0xc8178 <_Z23F_Vertex_Colour_releaseR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0xc8244 cmnmi pc, #0
 *   @0xc8248 ldrshteq r1, [r11], -r0
 *   @0xc824c eoreq r8, r6, r4, lsl #28
 *
 * ══ §82/102 Font_Init()  0xf9fb4  size 288  72 条（0xf9fb4..0xfa0d4）
 * @func 0xf9fb4 0xfa0d4  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xf9fbc→0x483690, 0xf9fd4→0x483688, 0xf9fe8→0x483680, 0xf9ff8→0x483684, 0xfa094→0x3eb70c
 * 调用序列: MemoryManager::Free(void const*)×3 / FT_Init_FreeType / Font_Init()+0xbc
 * 字段偏移 top8: 0x4×5 / 0xf8×2 / 0x30×2 / 0xe4×1 / 0xd4×1 / 0xc8×1 / 0x2×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9fb4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xf9fb8 ldr r5, [pc, #0xf8]
 *   @0xf9fbc ldr r3, [pc, #0xf8]
 *   @0xf9fc0 add r5, pc, r5
 *   @0xf9fc4 ldr r0, [r5, r3]
 *   @0xf9fc8 blx 0x2e9b30 <FT_Init_FreeType>
 *   @0xf9fcc subs r2, r0, #0
 *   @0xf9fd0 bne 0xfa094 <_Z9Font_Initv+0xe0>
 *   @0xf9fd4 ldr r3, [pc, #0xe4]
 *   @0xf9fd8 ldr r6, [r5, r3]
 *   @0xf9fdc ldr r0, [r6, #0x4]
 *   @0xf9fe0 cmp r0, #0
 *   @0xf9fe4 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xf9fe8 ldr r3, [pc, #0xd4]
 *   @0xf9fec ldr r8, [r5, r3]
 *   @0xf9ff0 ldr r3, [r8]
 *   @0xf9ff4 cmp r3, #0
 *   @0xf9ff8 ldr r3, [pc, #0xc8]
 *   @0xf9ffc ldrle r9, [r5, r3]
 *   @0xfa000 ble 0xfa070 <_Z9Font_Initv+0xbc>
 *   @0xfa004 ldr r9, [r5, r3]
 *   @0xfa008 mov r4, #0
 *   @0xfa00c mov r7, r4
 *   @0xfa010 ldr r3, [r0, r4, lsl #2]
 *   @0xfa014 lsl r5, r4, #2
 *   @0xfa018 add r2, r0, r5
 *   @0xfa01c add r4, r4, #1
 *   @0xfa020 cmp r3, #0
 *   @0xfa024 mov r0, r3
 *   @0xfa028 beq 0xfa040 <_Z9Font_Initv+0x8c>
 *   @0xfa02c ldr r3, [r3]
 *   @0xfa030 ldr r3, [r3, #0x4]
 *   @0xfa034 blx r3
 *   @0xfa038 ldr r2, [r6, #0x4]
 *   @0xfa03c add r2, r2, r5
 *   @0xfa040 str r7, [r2]
 *   @0xfa044 ldr r3, [r9]
 *   @0xfa048 ldr r0, [r3, r5]
 *   @0xfa04c cmp r0, #0
 *   @0xfa050 beq 0xfa060 <_Z9Font_Initv+0xac>
 *   @0xfa054 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfa058 ldr r3, [r9]
 *   @0xfa05c str r7, [r3, r5]
 *   @0xfa060 ldr r3, [r8]
 *   @0xfa064 ldr r0, [r6, #0x4]
 *   @0xfa068 cmp r3, r4
 *   @0xfa06c bgt 0xfa010 <_Z9Font_Initv+0x5c>
 *   @0xfa070 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfa074 ldr r0, [r9]
 *   @0xfa078 mov r4, #0
 *   @0xfa07c str r4, [r6, #0x4]
 *   @0xfa080 str r4, [r6]
 *   @0xfa084 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfa088 str r4, [r8]
 *   @0xfa08c str r4, [r9]
 *   @0xfa090 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xfa094 ldr r3, [pc, #0x30]
 *   @0xfa098 ldr r1, [pc, #0x30]
 *   @0xfa09c ldr r3, [r5, r3]
 *   @0xfa0a0 add r1, pc, r1
 *   @0xfa0a4 ldr r0, [r3]
 *   @0xfa0a8 ldr r3, [r0]
 *   @0xfa0ac ldr r3, [r3, #0xc]
 *   @0xfa0b0 blx r3
 *   @0xfa0b4 b 0xf9fd4 <_Z9Font_Initv+0x20>
 *   @0xfa0b8 mlaeq pc, r0, r12, r7
 *   @0xfa0bc .word 0xffffc200
 *   @0xfa0c0 .word 0xffffc20c
 *   @0xfa0c4 .word 0xffffc210
 *   @0xfa0c8 .word 0xffffc214
 *   @0xfa0cc .word 0xffffbac4
 *   @0xfa0d0 mlaeq r3, r4, r10, sp
 *
 * ══ §83/102 String_Copy(char const*&, char const*, int, int)  0x1114c4  size 288  72 条（0x1114c4..0x1115e4）
 * @func 0x1114c4 0x1115e4  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / String_Copy(char const*&, char const*, int, int)+0x110×2 / utf8_extract_char×2 / utf8_add_char×2 / MemoryManager::Free(void const*) / utf8_strlen / String_Copy(char const*&, char const*, int, int)+0xdc
 * 字段偏移 top8: 0xc0×1 / 0x4×1 / 0x2c×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1114c4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1114c8 mov r8, r1
 *   @0x1114cc sub sp, sp, #12
 *   @0x1114d0 mov r5, r0
 *   @0x1114d4 ldr r0, [r0]
 *   @0x1114d8 mov r6, r2
 *   @0x1114dc mov r7, r3
 *   @0x1114e0 mov r4, #0
 *   @0x1114e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1114e8 str r4, [r5]
 *   @0x1114ec mov r0, r8
 *   @0x1114f0 bl 0x110648 <utf8_strlen>
 *   @0x1114f4 cmp r0, r6
 *   @0x1114f8 mov r9, r0
 *   @0x1114fc blt 0x1115a0 <_Z11String_CopyRPKcS0_ii+0xdc>
 *   @0x111500 rsb r3, r6, r0
 *   @0x111504 mov r0, r8
 *   @0x111508 cmp r7, r3
 *   @0x11150c movge r7, r3
 *   @0x111510 bl 0xb6538 <strlen@plt>
 *   @0x111514 ldr r1, [pc, #0xc0]
 *   @0x111518 mov r3, #1
 *   @0x11151c movw r2, #0x899
 *   @0x111520 add r1, pc, r1
 *   @0x111524 add r0, r0, r3
 *   @0x111528 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x11152c cmp r9, r6
 *   @0x111530 str r8, [sp]
 *   @0x111534 str r0, [r5]
 *   @0x111538 str r0, [sp, #0x4]
 *   @0x11153c ble 0x1115d4 <_Z11String_CopyRPKcS0_ii+0x110>
 *   @0x111540 cmp r6, #0
 *   @0x111544 ble 0x11155c <_Z11String_CopyRPKcS0_ii+0x98>
 *   @0x111548 add r4, r4, #1
 *   @0x11154c mov r0, sp
 *   @0x111550 bl 0x10fb38 <utf8_extract_char>
 *   @0x111554 cmp r4, r6
 *   @0x111558 bne 0x111548 <_Z11String_CopyRPKcS0_ii+0x84>
 *   @0x11155c cmp r7, #0
 *   @0x111560 addgt r6, sp, #4
 *   @0x111564 movgt r4, #0
 *   @0x111568 ble 0x1115d4 <_Z11String_CopyRPKcS0_ii+0x110>
 *   @0x11156c mov r0, sp
 *   @0x111570 add r4, r4, #1
 *   @0x111574 bl 0x10fb38 <utf8_extract_char>
 *   @0x111578 mov r1, r0
 *   @0x11157c mov r0, r6
 *   @0x111580 bl 0x10fe28 <utf8_add_char>
 *   @0x111584 cmp r4, r7
 *   @0x111588 bne 0x11156c <_Z11String_CopyRPKcS0_ii+0xa8>
 *   @0x11158c mov r0, r6
 *   @0x111590 mov r1, #0
 *   @0x111594 bl 0x10fe28 <utf8_add_char>
 *   @0x111598 add sp, sp, #12
 *   @0x11159c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1115a0 mov r0, r8
 *   @0x1115a4 add r6, sp, #8
 *   @0x1115a8 bl 0xb6538 <strlen@plt>
 *   @0x1115ac ldr r1, [pc, #0x2c]
 *   @0x1115b0 mov r3, #1
 *   @0x1115b4 movw r2, #0x899
 *   @0x1115b8 add r1, pc, r1
 *   @0x1115bc add r0, r0, r3
 *   @0x1115c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1115c4 str r8, [sp]
 *   @0x1115c8 str r0, [r5]
 *   @0x1115cc str r0, [r6, #-0x4]!
 *   @0x1115d0 b 0x11158c <_Z11String_CopyRPKcS0_ii+0xc8>
 *   @0x1115d4 add r6, sp, #4
 *   @0x1115d8 b 0x11158c <_Z11String_CopyRPKcS0_ii+0xc8>
 *   @0x1115dc eoreq r7, r2, r4, lsr #18
 *   @0x1115e0 eoreq r7, r2, r12, lsl #17
 *
 * ══ §84/102 F_DateCreateDate(RValue&, CInstance*, CInstance*, int, RValue*)  0x115130  size 288  72 条（0x115130..0x115250）
 * @func 0x115130 0x115250  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / 0xb6808 / 0xb6814 / YYError(char const*, ...)
 * 字段偏移 top8: 0xc×2 / 0x10×2 / 0x14×2 / 0x18×2 / 0x20×2 / 0x24×2 / 0x40×1 / 0x4×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115130 push {r4, r5, r6, lr}
 *   @0x115134 sub sp, sp, #48
 *   @0x115138 mov r3, #0
 *   @0x11513c mov r4, r0
 *   @0x115140 ldr r5, [sp, #0x40]
 *   @0x115144 mov r1, r3
 *   @0x115148 str r3, [r0, #0xc]
 *   @0x11514c add r6, sp, #4
 *   @0x115150 str r3, [sp, #0x4]
 *   @0x115154 mov r0, r5
 *   @0x115158 str r3, [sp, #0x8]
 *   @0x11515c str r3, [sp, #0xc]
 *   @0x115160 str r3, [sp, #0x10]
 *   @0x115164 str r3, [sp, #0x14]
 *   @0x115168 str r3, [sp, #0x18]
 *   @0x11516c str r3, [sp, #0x1c]
 *   @0x115170 str r3, [sp, #0x20]
 *   @0x115174 str r3, [sp, #0x24]
 *   @0x115178 str r3, [sp, #0x28]
 *   @0x11517c str r3, [sp, #0x2c]
 *   @0x115180 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115184 mov r1, #1
 *   @0x115188 sub r3, r0, #1888
 *   @0x11518c mov r0, r5
 *   @0x115190 sub r3, r3, #12
 *   @0x115194 str r3, [sp, #0x18]
 *   @0x115198 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11519c mov r1, #2
 *   @0x1151a0 sub r3, r0, #1
 *   @0x1151a4 mov r0, r5
 *   @0x1151a8 str r3, [sp, #0x14]
 *   @0x1151ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1151b0 ldr r3, [pc, #0x90]
 *   @0x1151b4 mvn r2, #0
 *   @0x1151b8 str r2, [sp, #0x24]
 *   @0x1151bc add r3, pc, r3
 *   @0x1151c0 ldrb r3, [r3]
 *   @0x1151c4 cmp r3, #0
 *   @0x1151c8 str r0, [sp, #0x10]
 *   @0x1151cc mov r0, r6
 *   @0x1151d0 beq 0x115214 <_Z16F_DateCreateDateR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x1151d4 bl 0xb6808 <mktime64@plt>
 *   @0x1151d8 mov r5, r0
 *   @0x1151dc cmn r5, #1
 *   @0x1151e0 beq 0x115224 <_Z16F_DateCreateDateR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x1151e4 vmov.f64 d4, #5.000000e-01
 *   @0x1151e8 vldr d5, [pc, #72]
 *   @0x1151ec vmov s7, r5
 *   @0x1151f0 vldr d7, [pc, #72]
 *   @0x1151f4 vcvt.f64.s32 d6, s7
 *   @0x1151f8 vadd.f64 d6, d6, d4
 *   @0x1151fc vdiv.f64 d6, d6, d5
 *   @0x115200 vadd.f64 d5, d6, d7
 *   @0x115204 vmov r2, r3, d5
 *   @0x115208 stm r4, {r2, r3}
 *   @0x11520c add sp, sp, #48
 *   @0x115210 pop {r4, r5, r6, pc}
 *   @0x115214 bl 0xb6814 <timegm64@plt>
 *   @0x115218 mov r5, r0
 *   @0x11521c cmn r5, #1
 *   @0x115220 bne 0x1151e4 <_Z16F_DateCreateDateR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x115224 ldr r0, [pc, #0x20]
 *   @0x115228 add r0, pc, r0
 *   @0x11522c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x115230 b 0x1151e4 <_Z16F_DateCreateDateR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x115234 nop
 *   @0x115238 andeq r0, r0, r0
 *   @0x11523c rscsmi r1, r5, r0, lsl #16
 *   @0x115240 andeq r0, r0, r0
 *   @0x115244 sbcsmi pc, r8, r0, asr #16
 *   @0x115248 eoreq r12, sp, r12, ror pc
 *   @0x11524c eoreq r4, r2, r4, lsr r5
 *
 * ══ §85/102 anon_14c57c  0x14c57c  size 288  72 条（0x14c57c..0x14c69c）
 * @func 0x14c57c 0x14c69c  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: WithObjIterator::operator*()×2 / Error_Show_Action(char const*, bool)×2 / CPhysicsFixtureFactory::FindFixture(unsigned int) / WithObjIterator::WithObjIterator(int, CInstance*, CInstance*, bool) / CPhysicsWorld::CreateBody(CPhysicsFixture*, CInstance*, float, float) / WithObjIterator::Next()
 * 字段偏移 top8: 0xb4×2 / 0xe4×1 / 0x68×1 / 0x69×1 / 0x38×1 / 0x18×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c57c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x14c580 vpush {d8}
 *   @0x14c584 mov r6, r0
 *   @0x14c588 sub sp, sp, #52
 *   @0x14c58c mov r0, r1
 *   @0x14c590 mov r9, r2
 *   @0x14c594 vmov.f32 s16, s1
 *   @0x14c598 vmov r8, s0
 *   @0x14c59c bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14c5a0 subs r7, r0, #0
 *   @0x14c5a4 beq 0x14c67c <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x14c5a8 ldr r5, [pc, #0xe4]
 *   @0x14c5ac ldr r5, [pc, r5]
 *   @0x14c5b0 ldr r3, [r5]
 *   @0x14c5b4 cmp r3, #0
 *   @0x14c5b8 beq 0x14c658 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x14c5bc ldr r3, [r3, #0xb4]
 *   @0x14c5c0 cmp r3, #0
 *   @0x14c5c4 beq 0x14c658 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x14c5c8 add r4, sp, #12
 *   @0x14c5cc mov r2, r6
 *   @0x14c5d0 mov r3, r6
 *   @0x14c5d4 mov r12, #0
 *   @0x14c5d8 mov r1, r9
 *   @0x14c5dc mov r0, r4
 *   @0x14c5e0 str r12, [sp]
 *   @0x14c5e4 mvn r6, #0
 *   @0x14c5e8 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b>
 *   @0x14c5ec b 0x14c634 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x14c5f0 bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x14c5f4 ldrb r12, [r0, #0x68]
 *   @0x14c5f8 cmp r12, #0
 *   @0x14c5fc bne 0x14c62c <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x14c600 ldrb r12, [r0, #0x69]
 *   @0x14c604 mov r1, r7
 *   @0x14c608 mov r2, r0
 *   @0x14c60c mov r3, r8
 *   @0x14c610 cmp r12, #0
 *   @0x14c614 bne 0x14c62c <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x14c618 ldr r0, [r5]
 *   @0x14c61c ldr r0, [r0, #0xb4]
 *   @0x14c620 vstr s16, [sp]
 *   @0x14c624 bl 0x23894c <_ZN13CPhysicsWorld10CreateBodyEP15CPhysicsFixtureP9CInstanceff>
 *   @0x14c628 mov r6, r0
 *   @0x14c62c mov r0, r4
 *   @0x14c630 bl 0x19d1c8 <_ZN15WithObjIterator4NextEv>
 *   @0x14c634 mov r0, r4
 *   @0x14c638 bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x14c63c cmp r0, #0
 *   @0x14c640 mov r0, r4
 *   @0x14c644 bne 0x14c5f0 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x14c648 mov r0, r6
 *   @0x14c64c add sp, sp, #52
 *   @0x14c650 vpop {d8}
 *   @0x14c654 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x14c658 ldr r0, [pc, #0x38]
 *   @0x14c65c mov r1, #0
 *   @0x14c660 mvn r6, #0
 *   @0x14c664 add r0, pc, r0
 *   @0x14c668 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c66c mov r0, r6
 *   @0x14c670 add sp, sp, #52
 *   @0x14c674 vpop {d8}
 *   @0x14c678 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x14c67c ldr r0, [pc, #0x18]
 *   @0x14c680 mov r1, r7
 *   @0x14c684 mvn r6, #0
 *   @0x14c688 add r0, pc, r0
 *   @0x14c68c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c690 b 0x14c648 <_Z29F_PhysicsFixtureAddShapePointR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x14c694 eoreq r1, r10, r12, ror r3
 *   @0x14c698 andseq r7, pc, r0, ror #16
 *
 * ══ §86/102 F_PhysicsRemoveFixture(RValue&, CInstance*, CInstance*, int, RValue*)  0x14ce18  size 288  72 条（0x14ce18..0x14cf38）
 * @func 0x14ce18 0x14cf38  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / WithObjIterator::operator*()×2 / WithObjIterator::WithObjIterator(int, CInstance*, CInstance*, bool) / CPhysicsObject::RemoveFixture(int) / WithObjIterator::Next() / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×2 / 0x110×1 / 0xc×1 / 0x50×1 / 0xb4×1 / 0x68×1 / 0x69×1 / 0x84×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14ce18 ldr r12, [pc, #0x110]
 *   @0x14ce1c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x14ce20 ldr r12, [pc, r12]
 *   @0x14ce24 mov r6, #0
 *   @0x14ce28 str r6, [r0]
 *   @0x14ce2c ldr r12, [r12]
 *   @0x14ce30 sub sp, sp, #48
 *   @0x14ce34 mov r5, r0
 *   @0x14ce38 mov r9, r1
 *   @0x14ce3c cmp r12, r6
 *   @0x14ce40 mov r0, r6
 *   @0x14ce44 mov r8, r2
 *   @0x14ce48 movt r0, #0xbff0
 *   @0x14ce4c str r6, [r5, #0xc]
 *   @0x14ce50 str r0, [r5, #0x4]
 *   @0x14ce54 ldr r7, [sp, #0x50]
 *   @0x14ce58 beq 0x14cf18 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x14ce5c ldr r3, [r12, #0xb4]
 *   @0x14ce60 cmp r3, r6
 *   @0x14ce64 beq 0x14cf18 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x14ce68 mov r1, r6
 *   @0x14ce6c mov r0, r7
 *   @0x14ce70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14ce74 mov r1, #1
 *   @0x14ce78 add r4, sp, #12
 *   @0x14ce7c mov r10, r0
 *   @0x14ce80 mov r0, r7
 *   @0x14ce84 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14ce88 mov r1, r10
 *   @0x14ce8c str r6, [sp]
 *   @0x14ce90 mov r2, r9
 *   @0x14ce94 mov r3, r8
 *   @0x14ce98 mov r7, r0
 *   @0x14ce9c mov r0, r4
 *   @0x14cea0 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b>
 *   @0x14cea4 b 0x14cf00 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x14cea8 mov r0, r4
 *   @0x14ceac bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x14ceb0 ldrb r3, [r0, #0x68]
 *   @0x14ceb4 cmp r3, #0
 *   @0x14ceb8 bne 0x14cef8 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x14cebc ldrb r6, [r0, #0x69]
 *   @0x14cec0 cmp r6, #0
 *   @0x14cec4 bne 0x14cef8 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x14cec8 ldr r0, [r0, #0x84]
 *   @0x14cecc cmp r0, #0
 *   @0x14ced0 beq 0x14cef8 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x14ced4 mov r1, r7
 *   @0x14ced8 bl 0x2377c4 <_ZN14CPhysicsObject13RemoveFixtureEi>
 *   @0x14cedc cmp r0, #0
 *   @0x14cee0 moveq r6, r0
 *   @0x14cee4 movne r3, #0
 *   @0x14cee8 moveq r3, r6
 *   @0x14ceec movtne r3, #0x3ff0
 *   @0x14cef0 str r6, [r5]
 *   @0x14cef4 str r3, [r5, #0x4]
 *   @0x14cef8 mov r0, r4
 *   @0x14cefc bl 0x19d1c8 <_ZN15WithObjIterator4NextEv>
 *   @0x14cf00 mov r0, r4
 *   @0x14cf04 bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x14cf08 cmp r0, #0
 *   @0x14cf0c bne 0x14cea8 <_Z22F_PhysicsRemoveFixtureR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x14cf10 add sp, sp, #48
 *   @0x14cf14 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x14cf18 ldr r0, [pc, #0x14]
 *   @0x14cf1c mov r1, #0
 *   @0x14cf20 add r0, pc, r0
 *   @0x14cf24 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14cf28 add sp, sp, #48
 *   @0x14cf2c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x14cf30 eoreq r0, r10, r8, lsl #22
 *   @0x14cf34 andseq r6, pc, r4, lsr #31
 *
 * ══ §87/102 CBitmap32::CBitmap32(CBitmap32*, int, int, int, int)  0x166020  size 288  72 条（0x166020..0x166140）
 * @func 0x166020 0x166140  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::CBitmap32(CBitmap32*, int, int, int, int)+0x110×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc
 * 字段偏移 top8: 0x8×7 / 0xc×5 / 0x4×3 / 0x14×3 / 0x10×2 / 0x18×2 / 0x1c×2 / 0xf8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x166020 push {r4, r5, r6, r7, r8, lr}
 *   @0x166024 mov r4, r0
 *   @0x166028 mov r6, #0
 *   @0x16602c strb r6, [r0, #0x4]
 *   @0x166030 ldrb r0, [r1, #0x4]
 *   @0x166034 mov r7, r1
 *   @0x166038 ldr r1, [pc, #0xf8]
 *   @0x16603c mov r8, r2
 *   @0x166040 cmp r0, r6
 *   @0x166044 mov r5, r3
 *   @0x166048 ldr r1, [pc, r1]
 *   @0x16604c str r6, [r4, #0x8]
 *   @0x166050 add r1, r1, #8
 *   @0x166054 str r6, [r4, #0xc]
 *   @0x166058 str r1, [r4]
 *   @0x16605c str r6, [r4, #0x14]
 *   @0x166060 str r6, [r4, #0x10]
 *   @0x166064 beq 0x166130 <_ZN9CBitmap32C2EPS_iiii+0x110>
 *   @0x166068 ldr r1, [sp, #0x18]
 *   @0x16606c ldr r2, [r7, #0x8]
 *   @0x166070 add r3, r8, r1
 *   @0x166074 cmp r2, r3
 *   @0x166078 blt 0x166130 <_ZN9CBitmap32C2EPS_iiii+0x110>
 *   @0x16607c ldr r1, [sp, #0x1c]
 *   @0x166080 ldr r2, [r7, #0xc]
 *   @0x166084 add r3, r5, r1
 *   @0x166088 cmp r2, r3
 *   @0x16608c blt 0x166130 <_ZN9CBitmap32C2EPS_iiii+0x110>
 *   @0x166090 ldr r2, [sp, #0x1c]
 *   @0x166094 mov r1, #1
 *   @0x166098 ldr r3, [sp, #0x18]
 *   @0x16609c strb r1, [r4, #0x4]
 *   @0x1660a0 str r2, [r4, #0xc]
 *   @0x1660a4 mul r0, r2, r3
 *   @0x1660a8 str r3, [r4, #0x8]
 *   @0x1660ac mov r3, r1
 *   @0x1660b0 ldr r1, [pc, #0x84]
 *   @0x1660b4 mov r2, #222
 *   @0x1660b8 add r1, pc, r1
 *   @0x1660bc lsl r0, r0, #2
 *   @0x1660c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1660c4 ldr r2, [r7, #0x8]
 *   @0x1660c8 ldr r3, [r4, #0xc]
 *   @0x1660cc mla r5, r2, r5, r8
 *   @0x1660d0 cmp r3, #0
 *   @0x1660d4 mov r12, r0
 *   @0x1660d8 ldr r0, [r4, #0x8]
 *   @0x1660dc str r12, [r4, #0x14]
 *   @0x1660e0 ldr r1, [r7, #0x14]
 *   @0x1660e4 mul r2, r3, r0
 *   @0x1660e8 add r5, r1, r5, lsl #2
 *   @0x1660ec lsl r3, r2, #2
 *   @0x1660f0 str r3, [r4, #0x10]
 *   @0x1660f4 ble 0x166130 <_ZN9CBitmap32C2EPS_iiii+0x110>
 *   @0x1660f8 lsl r2, r0, #2
 *   @0x1660fc mov r0, r12
 *   @0x166100 mov r1, r5
 *   @0x166104 bl 0xb65bc <memcpy@plt>
 *   @0x166108 ldr r2, [r4, #0xc]
 *   @0x16610c add r6, r6, #1
 *   @0x166110 ldr r3, [r7, #0x8]
 *   @0x166114 cmp r2, r6
 *   @0x166118 add r5, r5, r3, lsl #2
 *   @0x16611c mov r12, r0
 *   @0x166120 ldr r0, [r4, #0x8]
 *   @0x166124 lsl r2, r0, #2
 *   @0x166128 add r12, r12, r2
 *   @0x16612c bgt 0x1660fc <_ZN9CBitmap32C2EPS_iiii+0xdc>
 *   @0x166130 mov r0, r4
 *   @0x166134 pop {r4, r5, r6, r7, r8, pc}
 *   @0x166138 strhteq r10, [r8], -r0
 *   @0x16613c andseq r4, lr, r8, lsl #10
 *
 * ══ §88/102 CBitmap32::CreateBitmap32()  0x167724  size 288  72 条（0x167724..0x167844）
 * @func 0x167724 0x167844  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBitmap::Create() / CBitmap32::CreateBitmap32()+0x100 / CBitmap32::CreateBitmap32()+0xec
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x8×3 / 0x14×2 / 0x2×2 / 0x1c×1 / 0x-4×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167724 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x167728 mov r5, r0
 *   @0x16772c ldrb r0, [r0, #0x4]
 *   @0x167730 sub sp, sp, #8
 *   @0x167734 cmp r0, #0
 *   @0x167738 beq 0x16783c <_ZN9CBitmap3214CreateBitmap32Ev+0x118>
 *   @0x16773c bl 0x1a912c <_ZN7IBitmap6CreateEv>
 *   @0x167740 mov r1, #7
 *   @0x167744 mov r9, #0
 *   @0x167748 ldr r3, [r0]
 *   @0x16774c mov r7, r0
 *   @0x167750 ldr r3, [r3, #0x1c]
 *   @0x167754 blx r3
 *   @0x167758 ldr r3, [r7]
 *   @0x16775c mov r0, r7
 *   @0x167760 ldr r1, [r5, #0x8]
 *   @0x167764 ldr r3, [r3, #0xc]
 *   @0x167768 blx r3
 *   @0x16776c ldr r3, [r7]
 *   @0x167770 mov r0, r7
 *   @0x167774 ldr r1, [r5, #0xc]
 *   @0x167778 ldr r3, [r3, #0x14]
 *   @0x16777c blx r3
 *   @0x167780 add r2, sp, #8
 *   @0x167784 mov r0, r7
 *   @0x167788 mov r1, r9
 *   @0x16778c str r9, [r2, #-0x4]!
 *   @0x167790 mov r3, sp
 *   @0x167794 ldr r12, [r7]
 *   @0x167798 str r9, [sp]
 *   @0x16779c ldr r12, [r12, #0x24]
 *   @0x1677a0 blx r12
 *   @0x1677a4 ldr r2, [r5, #0xc]
 *   @0x1677a8 cmp r2, r9
 *   @0x1677ac ble 0x167824 <_ZN9CBitmap3214CreateBitmap32Ev+0x100>
 *   @0x1677b0 ldr r4, [sp, #0x4]
 *   @0x1677b4 ldr r10, [sp]
 *   @0x1677b8 ldr r3, [r5, #0x8]
 *   @0x1677bc cmp r3, #0
 *   @0x1677c0 movgt r2, #0
 *   @0x1677c4 movgt r12, r2
 *   @0x1677c8 ble 0x167810 <_ZN9CBitmap3214CreateBitmap32Ev+0xec>
 *   @0x1677cc mla r3, r3, r9, r12
 *   @0x1677d0 ldr r1, [r5, #0x14]
 *   @0x1677d4 add lr, r4, r2
 *   @0x1677d8 add r12, r12, #1
 *   @0x1677dc ldr r3, [r1, r3, lsl #2]
 *   @0x1677e0 lsr r6, r3, #24
 *   @0x1677e4 lsr r8, r3, #16
 *   @0x1677e8 strb r6, [lr, #0x3]
 *   @0x1677ec lsr r6, r3, #8
 *   @0x1677f0 strb r8, [lr, #0x2]
 *   @0x1677f4 strb r6, [lr, #0x1]
 *   @0x1677f8 strb r3, [r4, r2]
 *   @0x1677fc add r2, r2, #4
 *   @0x167800 ldr r3, [r5, #0x8]
 *   @0x167804 cmp r3, r12
 *   @0x167808 bgt 0x1677cc <_ZN9CBitmap3214CreateBitmap32Ev+0xa8>
 *   @0x16780c ldr r2, [r5, #0xc]
 *   @0x167810 add r9, r9, #1
 *   @0x167814 add r4, r4, r10
 *   @0x167818 cmp r2, r9
 *   @0x16781c bgt 0x1677bc <_ZN9CBitmap3214CreateBitmap32Ev+0x98>
 *   @0x167820 str r4, [sp, #0x4]
 *   @0x167824 ldr r3, [r7]
 *   @0x167828 mov r1, r0
 *   @0x16782c mov r0, r7
 *   @0x167830 ldr r3, [r3, #0x28]
 *   @0x167834 blx r3
 *   @0x167838 mov r0, r7
 *   @0x16783c add sp, sp, #8
 *   @0x167840 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §89/102 CreateBMP(void*, int, int, int*, int)  0x16cb6c  size 288  72 条（0x16cb6c..0x16cc8c）
 * @func 0x16cb6c 0x16cc8c  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / CreateBMP(void*, int, int, int*, int)+0x114
 * 字段偏移 top8: 0x100×1 / 0x20×1 / 0x1×1 / 0xa×1 / 0xe×1 / 0x1a×1 / 0x1c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16cb6c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x16cb70 add r7, r1, r1, lsl #1
 *   @0x16cb74 mov r4, r2
 *   @0x16cb78 mov r6, r1
 *   @0x16cb7c mul r10, r4, r7
 *   @0x16cb80 ldr r1, [pc, #0x100]
 *   @0x16cb84 mov r2, #182
 *   @0x16cb88 mov r5, r0
 *   @0x16cb8c add r1, pc, r1
 *   @0x16cb90 ldr r8, [sp, #0x20]
 *   @0x16cb94 add r10, r10, #54
 *   @0x16cb98 str r10, [r3]
 *   @0x16cb9c mov r3, #1
 *   @0x16cba0 mov r0, r10
 *   @0x16cba4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x16cba8 mul r1, r4, r6
 *   @0x16cbac subs r9, r4, #1
 *   @0x16cbb0 mov r12, #66
 *   @0x16cbb4 mov r2, #77
 *   @0x16cbb8 mov r3, #54
 *   @0x16cbbc strb r12, [r0]
 *   @0x16cbc0 mov r12, #40
 *   @0x16cbc4 strb r2, [r0, #0x1]
 *   @0x16cbc8 mov r2, #1
 *   @0x16cbcc str r3, [r0, #0xa]
 *   @0x16cbd0 mov r3, #24
 *   @0x16cbd4 str r12, [r0, #0xe]
 *   @0x16cbd8 add r12, r1, r1, lsl #1
 *   @0x16cbdc strh r2, [r0, #26]
 *   @0x16cbe0 mov r2, #0
 *   @0x16cbe4 strh r3, [r0, #28]
 *   @0x16cbe8 add r3, r0, #54
 *   @0x16cbec str r10, [r0, #0x2]
 *   @0x16cbf0 str r6, [r0, #0x12]
 *   @0x16cbf4 str r4, [r0, #0x16]
 *   @0x16cbf8 str r12, [r0, #0x22]
 *   @0x16cbfc strh r2, [r0, #6]
 *   @0x16cc00 strh r2, [r0, #8]
 *   @0x16cc04 str r2, [r0, #0x1e]
 *   @0x16cc08 str r2, [r0, #0x26]
 *   @0x16cc0c str r2, [r0, #0x2a]
 *   @0x16cc10 str r2, [r0, #0x2e]
 *   @0x16cc14 str r2, [r0, #0x32]
 *   @0x16cc18 popmi {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x16cc1c rsb r1, r6, r1
 *   @0x16cc20 rsb r10, r6, #0
 *   @0x16cc24 cmp r6, #0
 *   @0x16cc28 mla r1, r8, r1, r5
 *   @0x16cc2c mul r10, r8, r10
 *   @0x16cc30 mov r12, r1
 *   @0x16cc34 ble 0x16cc80 <_Z9CreateBMPPviiPii+0x114>
 *   @0x16cc38 add r5, r3, r7
 *   @0x16cc3c ldr r2, [r12], r8
 *   @0x16cc40 add r3, r3, #3
 *   @0x16cc44 strb r2, [r3, #-0x3]
 *   @0x16cc48 lsr r4, r2, #8
 *   @0x16cc4c lsr r2, r2, #16
 *   @0x16cc50 strb r4, [r3, #-0x2]
 *   @0x16cc54 strb r2, [r3, #-0x1]
 *   @0x16cc58 cmp r3, r5
 *   @0x16cc5c bne 0x16cc3c <_Z9CreateBMPPviiPii+0xd0>
 *   @0x16cc60 sub r9, r9, #1
 *   @0x16cc64 add r1, r1, r10
 *   @0x16cc68 cmn r9, #1
 *   @0x16cc6c popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x16cc70 cmp r6, #0
 *   @0x16cc74 mov r3, r5
 *   @0x16cc78 mov r12, r1
 *   @0x16cc7c bgt 0x16cc38 <_Z9CreateBMPPviiPii+0xcc>
 *   @0x16cc80 mov r5, r3
 *   @0x16cc84 b 0x16cc60 <_Z9CreateBMPPviiPii+0xf4>
 *   @0x16cc88 andseq sp, sp, r12, asr #25
 *
 * ══ §90/102 Motion_Grid_Draw(int)  0x19c1ac  size 288  72 条（0x19c1ac..0x19c2cc）
 * @func 0x19c1ac 0x19c2cc  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Motion_Grid_Draw(int)+0x110×2 / Motion_Grid_Draw(int)+0x104 / GR_Draw_Rectangle_Ext(float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, bool)
 * 字段偏移 top8: 0x2×2 / 0x14×2 / 0x18×2 / 0x10×2 / 0x8×2 / 0xc×2 / 0x4×2 / 0x100×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19c1ac cmp r0, #0
 *   @0x19c1b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x19c1b4 sub sp, sp, #28
 *   @0x19c1b8 blt 0x19c2bc <_Z16Motion_Grid_Drawi+0x110>
 *   @0x19c1bc ldr r3, [pc, #0x100]
 *   @0x19c1c0 ldr r3, [pc, r3]
 *   @0x19c1c4 ldr r3, [r3]
 *   @0x19c1c8 cmp r0, r3
 *   @0x19c1cc bge 0x19c2bc <_Z16Motion_Grid_Drawi+0x110>
 *   @0x19c1d0 ldr r3, [pc, #0xf0]
 *   @0x19c1d4 ldr r3, [pc, r3]
 *   @0x19c1d8 ldr r3, [r3]
 *   @0x19c1dc ldr r4, [r3, r0, lsl #2]
 *   @0x19c1e0 cmp r4, #0
 *   @0x19c1e4 beq 0x19c2bc <_Z16Motion_Grid_Drawi+0x110>
 *   @0x19c1e8 ldr r3, [r4, #0x14]
 *   @0x19c1ec cmp r3, #0
 *   @0x19c1f0 ble 0x19c2bc <_Z16Motion_Grid_Drawi+0x110>
 *   @0x19c1f4 ldr r1, [r4, #0x18]
 *   @0x19c1f8 mov r6, #1
 *   @0x19c1fc mov r7, #0
 *   @0x19c200 cmp r1, #0
 *   @0x19c204 mov r8, r6
 *   @0x19c208 sub r9, r6, #1
 *   @0x19c20c movgt r5, #0
 *   @0x19c210 ble 0x19c2b0 <_Z16Motion_Grid_Drawi+0x104>
 *   @0x19c214 ldr r3, [r4, #0x10]
 *   @0x19c218 ldr r10, [r4, #0x8]
 *   @0x19c21c mla r1, r9, r1, r5
 *   @0x19c220 ldr r11, [r4, #0x1c]
 *   @0x19c224 mul lr, r3, r5
 *   @0x19c228 ldr r12, [r4, #0xc]
 *   @0x19c22c ldr r2, [r4, #0x4]
 *   @0x19c230 add r5, r5, #1
 *   @0x19c234 add r3, lr, r3
 *   @0x19c238 ldr r11, [r11, r1, lsl #2]
 *   @0x19c23c add r3, r10, r3
 *   @0x19c240 add r1, r10, lr
 *   @0x19c244 mla r0, r9, r12, r2
 *   @0x19c248 vmov s15, r3
 *   @0x19c24c mla r2, r6, r12, r2
 *   @0x19c250 vcvt.f32.s32 s15, s15
 *   @0x19c254 cmp r11, #0
 *   @0x19c258 str r7, [sp, #0x10]
 *   @0x19c25c movge r12, #32768
 *   @0x19c260 movlt r12, #255
 *   @0x19c264 str r12, [sp]
 *   @0x19c268 str r12, [sp, #0x4]
 *   @0x19c26c str r12, [sp, #0x8]
 *   @0x19c270 vmov r3, s15
 *   @0x19c274 vmov s15, r1
 *   @0x19c278 str r12, [sp, #0xc]
 *   @0x19c27c vcvt.f32.s32 s15, s15
 *   @0x19c280 vmov r1, s15
 *   @0x19c284 vmov s15, r0
 *   @0x19c288 vcvt.f32.s32 s15, s15
 *   @0x19c28c vmov r0, s15
 *   @0x19c290 vmov s15, r2
 *   @0x19c294 vcvt.f32.s32 s15, s15
 *   @0x19c298 vmov r2, s15
 *   @0x19c29c bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb>
 *   @0x19c2a0 ldr r1, [r4, #0x18]
 *   @0x19c2a4 cmp r1, r5
 *   @0x19c2a8 bgt 0x19c214 <_Z16Motion_Grid_Drawi+0x68>
 *   @0x19c2ac ldr r3, [r4, #0x14]
 *   @0x19c2b0 cmp r3, r8
 *   @0x19c2b4 add r6, r6, #1
 *   @0x19c2b8 bgt 0x19c200 <_Z16Motion_Grid_Drawi+0x54>
 *   @0x19c2bc add sp, sp, #28
 *   @0x19c2c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19c2c4 eoreq r4, r5, r12, ror #9
 *   @0x19c2c8 .word 0x002544dc
 *
 * ══ §91/102 TryDir(float, CInstance*, float, int, bool)  0x19cba8  size 288  72 条（0x19cba8..0x19ccc8）
 * @func 0x19cba8 0x19ccc8  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TestFree(CInstance*, float, float, int, bool)×2 / DiffDir(float, float) / TryDir(float, CInstance*, float, int, bool)+0x58 / 0xb658c / 0xb6580 / CInstance::SetDirection(float) / CInstance::SetPosition(float, float)
 * 字段偏移 top8: 0xcc×1 / 0x30×1 / 0xe8×1 / 0xb0×1
 * VFP 指令 33 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19cba8 push {r4, r5, r6, lr}
 *   @0x19cbac vpush {d8, d9, d10}
 *   @0x19cbb0 sub sp, sp, #8
 *   @0x19cbb4 mov r4, r1
 *   @0x19cbb8 ldr r1, [r1, #0xcc]
 *   @0x19cbbc vmov s16, r2
 *   @0x19cbc0 mov r5, r3
 *   @0x19cbc4 vmov s17, r0
 *   @0x19cbc8 ldrb r6, [sp, #0x30]
 *   @0x19cbcc bl 0x19c7ec <_Z7DiffDirff>
 *   @0x19cbd0 ldr r2, [pc, #0xe8]
 *   @0x19cbd4 ldr r2, [pc, r2]
 *   @0x19cbd8 vldr s15, [r2]
 *   @0x19cbdc vmov s14, r0
 *   @0x19cbe0 vcmpe.f32 s14, s15
 *   @0x19cbe4 vmrs APSR_nzcv, fpscr
 *   @0x19cbe8 ble 0x19cc00 <_Z6TryDirfP9CInstancefib+0x58>
 *   @0x19cbec mov r5, #0
 *   @0x19cbf0 mov r0, r5
 *   @0x19cbf4 add sp, sp, #8
 *   @0x19cbf8 vpop {d8, d9, d10}
 *   @0x19cbfc pop {r4, r5, r6, pc}
 *   @0x19cc00 vldr s19, [pc, #176]
 *   @0x19cc04 vmul.f32 s19, s17, s19
 *   @0x19cc08 vldr s15, [pc, #172]
 *   @0x19cc0c ldr r2, [pc, #0xb0]
 *   @0x19cc10 ldr r2, [pc, r2]
 *   @0x19cc14 vldr s18, [r2]
 *   @0x19cc18 vdiv.f32 s19, s19, s15
 *   @0x19cc1c vmov r0, s19
 *   @0x19cc20 bl 0xb658c <cosf@plt>
 *   @0x19cc24 vmul.f32 s18, s16, s18
 *   @0x19cc28 vmov s20, r0
 *   @0x19cc2c vmov r0, s19
 *   @0x19cc30 bl 0xb6580 <sinf@plt>
 *   @0x19cc34 str r6, [sp]
 *   @0x19cc38 vldr s14, [r4, #180]
 *   @0x19cc3c vldr s15, [r4, #184]
 *   @0x19cc40 vmla.f32 s14, s18, s20
 *   @0x19cc44 mov r3, r5
 *   @0x19cc48 vmov r1, s14
 *   @0x19cc4c vmov s19, r0
 *   @0x19cc50 mov r0, r4
 *   @0x19cc54 vmls.f32 s15, s18, s19
 *   @0x19cc58 vmov r2, s15
 *   @0x19cc5c bl 0x19c6f4 <_Z8TestFreeP9CInstanceffib>
 *   @0x19cc60 cmp r0, #0
 *   @0x19cc64 beq 0x19cbec <_Z6TryDirfP9CInstancefib+0x44>
 *   @0x19cc68 vldr s21, [r4, #180]
 *   @0x19cc6c vldr s18, [r4, #184]
 *   @0x19cc70 vmla.f32 s21, s16, s20
 *   @0x19cc74 mov r3, r5
 *   @0x19cc78 str r6, [sp]
 *   @0x19cc7c mov r0, r4
 *   @0x19cc80 vmls.f32 s18, s16, s19
 *   @0x19cc84 vmov r1, s21
 *   @0x19cc88 vmov r2, s18
 *   @0x19cc8c bl 0x19c6f4 <_Z8TestFreeP9CInstanceffib>
 *   @0x19cc90 subs r5, r0, #0
 *   @0x19cc94 beq 0x19cbec <_Z6TryDirfP9CInstancefib+0x44>
 *   @0x19cc98 mov r0, r4
 *   @0x19cc9c vmov r1, s17
 *   @0x19cca0 bl 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x19cca4 mov r0, r4
 *   @0x19cca8 vmov r1, s21
 *   @0x19ccac vmov r2, s18
 *   @0x19ccb0 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x19ccb4 b 0x19cbf0 <_Z6TryDirfP9CInstancefib+0x48>
 *   @0x19ccb8 ldrdmi r0, r1, [r9], #-251
 *   @0x19ccbc teqmi r4, #0
 *   @0x19ccc0 .word 0x00253af4
 *   @0x19ccc4 eoreq r3, r5, r0, asr #21
 *
 * ══ §92/102 ParticleSystem_Emitter_Create(int)  0x1a39b4  size 288  72 条（0x1a39b4..0x1a3ad4）
 * @func 0x1a39b4 0x1a3ad4  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int) / ParticleSystem_Emitter_Create(int)+0xfc / MemoryManager::SetLength(void**, unsigned int, char const*, int) / operator new(unsigned int) / ParticleSystem_Emitter_Clear(int, int)
 * 字段偏移 top8: 0x10×4 / 0x4×3 / 0x14×3 / 0xc×2 / 0xfc×1 / 0x2×1 / 0xa4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a39b4 push {r4, r5, r6, r7, r8, lr}
 *   @0x1a39b8 mov r6, r0
 *   @0x1a39bc bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a39c0 cmp r0, #0
 *   @0x1a39c4 beq 0x1a3ac4 <_Z29ParticleSystem_Emitter_Createi+0x110>
 *   @0x1a39c8 ldr r3, [pc, #0xfc]
 *   @0x1a39cc ldr r3, [pc, r3]
 *   @0x1a39d0 ldr r3, [r3, #0x4]
 *   @0x1a39d4 ldr r7, [r3, r6, lsl #2]
 *   @0x1a39d8 ldr r1, [r7, #0x14]
 *   @0x1a39dc cmp r1, #0
 *   @0x1a39e0 ble 0x1a3ab0 <_Z29ParticleSystem_Emitter_Createi+0xfc>
 *   @0x1a39e4 ldr r3, [r7, #0x10]
 *   @0x1a39e8 ldr r2, [r3]
 *   @0x1a39ec ldrb r5, [r2]
 *   @0x1a39f0 cmp r5, #0
 *   @0x1a39f4 beq 0x1a3aa8 <_Z29ParticleSystem_Emitter_Createi+0xf4>
 *   @0x1a39f8 mov r4, #0
 *   @0x1a39fc b 0x1a3a10 <_Z29ParticleSystem_Emitter_Createi+0x5c>
 *   @0x1a3a00 ldr r2, [r3, #0x4]!
 *   @0x1a3a04 ldrb r2, [r2]
 *   @0x1a3a08 cmp r2, #0
 *   @0x1a3a0c beq 0x1a3a44 <_Z29ParticleSystem_Emitter_Createi+0x90>
 *   @0x1a3a10 add r4, r4, #1
 *   @0x1a3a14 cmp r4, r1
 *   @0x1a3a18 lsl r5, r4, #2
 *   @0x1a3a1c bne 0x1a3a00 <_Z29ParticleSystem_Emitter_Createi+0x4c>
 *   @0x1a3a20 add r8, r4, #1
 *   @0x1a3a24 ldr r2, [pc, #0xa4]
 *   @0x1a3a28 add r0, r7, #16
 *   @0x1a3a2c mov r3, #1072
 *   @0x1a3a30 add r2, pc, r2
 *   @0x1a3a34 lsl r1, r8, #2
 *   @0x1a3a38 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a3a3c str r8, [r7, #0xc]
 *   @0x1a3a40 str r8, [r7, #0x14]
 *   @0x1a3a44 mov r0, #36
 *   @0x1a3a48 bl 0x27c524 <_Znwj>
 *   @0x1a3a4c mov r2, #0
 *   @0x1a3a50 mov r1, #0
 *   @0x1a3a54 mov r3, r0
 *   @0x1a3a58 ldr r0, [r7, #0x10]
 *   @0x1a3a5c strb r2, [r3]
 *   @0x1a3a60 str r2, [r3, #0x4]
 *   @0x1a3a64 str r1, [r3, #0x8]
 *   @0x1a3a68 str r2, [r3, #0x18]
 *   @0x1a3a6c str r1, [r3, #0xc]
 *   @0x1a3a70 str r2, [r3, #0x1c]
 *   @0x1a3a74 str r1, [r3, #0x10]
 *   @0x1a3a78 str r2, [r3, #0x20]
 *   @0x1a3a7c mov r2, #1
 *   @0x1a3a80 str r1, [r3, #0x14]
 *   @0x1a3a84 mov r1, r4
 *   @0x1a3a88 str r3, [r0, r5]
 *   @0x1a3a8c mov r0, r6
 *   @0x1a3a90 ldr r3, [r7, #0x10]
 *   @0x1a3a94 ldr r3, [r3, r5]
 *   @0x1a3a98 strb r2, [r3]
 *   @0x1a3a9c bl 0x1a38ec <_Z28ParticleSystem_Emitter_Clearii>
 *   @0x1a3aa0 mov r0, r4
 *   @0x1a3aa4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1a3aa8 mov r4, r5
 *   @0x1a3aac b 0x1a3a44 <_Z29ParticleSystem_Emitter_Createi+0x90>
 *   @0x1a3ab0 movne r5, #0
 *   @0x1a3ab4 bne 0x1a3aa8 <_Z29ParticleSystem_Emitter_Createi+0xf4>
 *   @0x1a3ab8 mov r5, r1
 *   @0x1a3abc mov r4, r1
 *   @0x1a3ac0 b 0x1a3a20 <_Z29ParticleSystem_Emitter_Createi+0x6c>
 *   @0x1a3ac4 mvn r0, #0
 *   @0x1a3ac8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1a3acc eoreq r12, r4, r12, ror #27
 *   @0x1a3ad0 andseq r9, r10, r0, asr r5
 *
 * ══ §93/102 mysort(RValue*, int, int, RValue*, E_MYSORTVAL (*)(RValue*, RValue*, RValue*))  0x242f54  size 288  72 条（0x242f54..0x243074）
 * @func 0x242f54 0x243074  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: myswap(RValue*, int, int)×3 / mysort(RValue*, int, int, RValue*, E_MYSORTVAL (*)(RValue*, RValue*, RValue*))×2 / mysort(RValue*, int, int, RValue*, E_MYSORTVAL (*)(RValue*, RValue*, RValue*))+0x30 / mysort(RValue*, int, int, RValue*, E_MYSORTVAL (*)(RValue*, RValue*, RValue*))+0x118 / mysort(RValue*, int, int, RValue*, E_MYSORTVAL (*)(RValue*, RValue*, RValue*))+0xc0 / mysort(RValue*, int, int, RValue*, E_MYSORTVAL (*)(RValue*, RValue*, RValue*))+0x28
 * 字段偏移 top8: 0xc×7 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x242f54 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x242f58 cmp r1, r2
 *   @0x242f5c sub sp, sp, #20
 *   @0x242f60 mov r10, r0
 *   @0x242f64 mov r5, r2
 *   @0x242f68 mov r9, r1
 *   @0x242f6c mov r6, r3
 *   @0x242f70 ldr r7, [sp, #0x38]
 *   @0x242f74 movge r0, #0
 *   @0x242f78 blt 0x242f84 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0x30>
 *   @0x242f7c add sp, sp, #20
 *   @0x242f80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x242f84 add r3, r1, r2
 *   @0x242f88 add r4, r1, #1
 *   @0x242f8c add r2, r3, r3, lsr #31
 *   @0x242f90 asr r2, r2, #1
 *   @0x242f94 bl 0x242edc <_Z6myswapP6RValueii>
 *   @0x242f98 cmp r5, r4
 *   @0x242f9c blt 0x24306c <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0x118>
 *   @0x242fa0 lsl r8, r9, #4
 *   @0x242fa4 str r9, [sp, #0xc]
 *   @0x242fa8 add r3, r8, #16
 *   @0x242fac add r8, r10, r8
 *   @0x242fb0 add r11, r10, r3
 *   @0x242fb4 b 0x242fc4 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0x70>
 *   @0x242fb8 add r4, r4, #1
 *   @0x242fbc cmp r5, r4
 *   @0x242fc0 blt 0x243014 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0xc0>
 *   @0x242fc4 mov r1, r11
 *   @0x242fc8 mov r2, r8
 *   @0x242fcc mov r0, r6
 *   @0x242fd0 add r11, r11, #16
 *   @0x242fd4 blx r7
 *   @0x242fd8 add r2, r0, #5
 *   @0x242fdc cmp r2, #1
 *   @0x242fe0 bls 0x242f7c <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0x28>
 *   @0x242fe4 cmp r0, #0
 *   @0x242fe8 bge 0x242fb8 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0x64>
 *   @0x242fec ldr r3, [sp, #0xc]
 *   @0x242ff0 mov r2, r4
 *   @0x242ff4 mov r0, r10
 *   @0x242ff8 add r4, r4, #1
 *   @0x242ffc add r3, r3, #1
 *   @0x243000 str r3, [sp, #0xc]
 *   @0x243004 mov r1, r3
 *   @0x243008 bl 0x242edc <_Z6myswapP6RValueii>
 *   @0x24300c cmp r5, r4
 *   @0x243010 bge 0x242fc4 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0x70>
 *   @0x243014 ldr r3, [sp, #0xc]
 *   @0x243018 add r4, r3, #1
 *   @0x24301c mov r0, r10
 *   @0x243020 mov r1, r9
 *   @0x243024 ldr r2, [sp, #0xc]
 *   @0x243028 bl 0x242edc <_Z6myswapP6RValueii>
 *   @0x24302c ldr r3, [sp, #0xc]
 *   @0x243030 mov r1, r9
 *   @0x243034 str r7, [sp]
 *   @0x243038 sub r2, r3, #1
 *   @0x24303c mov r0, r10
 *   @0x243040 mov r3, r6
 *   @0x243044 bl 0x242f54 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E>
 *   @0x243048 str r7, [sp]
 *   @0x24304c mov r0, r10
 *   @0x243050 mov r1, r4
 *   @0x243054 mov r2, r5
 *   @0x243058 mov r3, r6
 *   @0x24305c bl 0x242f54 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E>
 *   @0x243060 mov r0, #0
 *   @0x243064 add sp, sp, #20
 *   @0x243068 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24306c str r9, [sp, #0xc]
 *   @0x243070 b 0x24301c <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E+0xc8>
 *
 * ══ §94/102 png_write_sPLT  0x2b198c  size 288  72 条（0x2b198c..0x2b1aac）
 * @func 0x2b198c 0x2b1aac  size 288  72 条
 * 部分覆盖: 本节 72/125 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_chunk_data×2 / png_save_uint_16×2 / png_check_keyword / png_write_chunk_start / png_write_chunk_end / png_free
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0x114×1 / 0xc×1 / 0x2b×1 / 0x-a×1 / 0x-8×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b198c ldr r3, [pc, #0x114]
 *   @0x2b1990 ldrbtmi r4, [r11], #-4080
 *   @0x2b1994 ldr r3, [r3]
 *   @0x2b1998 mov r6, r0
 *   @0x2b199c mov r5, r1
 *   @0x2b19a0 ldrmi r8, [r9], r4
 *   @0x2b19a4 ldr r7, [r1, #0xc]
 *   @0x2b19a8 cmp.w r8, #0x8
 *   @0x2b19ac ite ne
 *   @0x2b19b0 .word 0xf04f080a
 *   @0x2b19b4 bmi 0x11b39d4 <b2_toiTime+0xa5a530>
 *   @0x2b19b8 ldr r1, [r1]
 *   @0x2b19bc ldr r0, [r2, #43]!
 *   @0x2b19c0 ldrb r2, [r2, #0x4]
 *   @0x2b19c4 mov r0, r6
 *   @0x2b19c8 bge 0x2f9a00 <ps_hints_apply+0x8600>
 *   @0x2b19cc bl 0x2af5b0 <png_check_keyword>
 *   @0x2b19d0 mov r4, r0
 *   @0x2b19d4 beq 0x2b1a90 <png_write_sPLT+0x104>
 *   @0x2b19d8 add r1, sp, #0x8
 *   @0x2b19dc mov.w r10, #0xa
 *   @0x2b19e0 mla r2, r7, r8, r2
 *   @0x2b19e4 bl 0x2b11a0 <png_write_chunk_start>
 *   @0x2b19e8 adds r2, r4, #0x1
 *   @0x2b19ec ldr r1, [sp, #0x4]
 *   @0x2b19f0 ldrtmi pc, [r0], -r9, lsl #24
 *   @0x2b19f4 adds r1, r5, #0x4
 *   @0x2b19f8 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b19fc ldr r4, [r5, #0x8]
 *   @0x2b1a00 adds r4, #0xa
 *   @0x2b1a04 stmvs r10!, {r1, r8, r9, r11} ^
 *   @0x2b1a08 sub.w r1, r4, #0xa
 *   @0x2b1a0c ldr r3, [r5, #0x8]
 *   @0x2b1a10 addsmi r3, r9, #134217728
 *   @0x2b1a14 bhs 0x2b1a82 <png_write_sPLT+0xf6>
 *   @0x2b1a18 cmp r3, #0x8
 *   @0x2b1a1c ldrh r3, [r4, #-10]
 *   @0x2b1a20 adds r0, r7, #0x4
 *   @0x2b1a24 rfeda r4!
 *   @0x2b1a28 .word 0xf88d3c08
 *   @0x2b1a2c rfeda r4!
 *   @0x2b1a30 .word 0xf88d3c06
 *   @0x2b1a34 rfeda r4!
 *   @0x2b1a38 .word 0xf88d3c04
 *   @0x2b1a3c ands r3, r5, r3, lsl r0
 *   @0x2b1a40 mov r0, r7
 *   @0x2b1a44 .word 0xf7ff1c0a
 *   @0x2b1a48 usub16mi pc, r8, r7
 *   @0x2b1a4c ldrh r1, [r4, #-8]
 *   @0x2b1a50 bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1a54 adds r0, r7, #0x4
 *   @0x2b1a58 .word 0xf7ff1c06
 *   @0x2b1a5c .word 0x1db8fb6d
 *   @0x2b1a60 ldrh r1, [r4, #-4]
 *   @0x2b1a64 bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1a68 add.w r0, r7, #0x8
 *   @0x2b1a6c ldrh r1, [r4, #-2]
 *   @0x2b1a70 adds r4, #0xa
 *   @0x2b1a74 ldrtmi pc, [r0], -r1, ror #22
 *   @0x2b1a78 mov r1, r7
 *   @0x2b1a7c bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b1a80 b 0x2b1a06 <png_write_sPLT+0x7a>
 *   @0x2b1a84 bl 0x2b1296 <png_write_chunk_end>
 *   @0x2b1a88 mov r0, r6
 *   @0x2b1a8c bl 0x2a6cfc <png_free>
 *   @0x2b1a90 ldr r2, [sp, #0x1c]
 *   @0x2b1a94 addsmi r3, r10, #0
 *   @0x2b1a98 beq 0x2b1a9e <png_write_sPLT+0x112>
 *   @0x2b1a9c mullt r9, r12, sp
 *   @0x2b1aa0 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b1aa4 ittt gt
 *   @0x2b1aa8 bgt 0x2b21f8 <png_write_oFFs+0x20>
 *
 * ══ §95/102 png_write_iTXt  0x2b20b8  size 288  72 条（0x2b20b8..0x2b21d8）
 * @func 0x2b20b8 0x2b21d8  size 288  72 条
 * 部分覆盖: 本节 72/131 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_write_chunk_data×2 / png_warning / 0xb6538 / png_write_chunk_start / 0x2b1226
 * 字段偏移 top8: 0x10×2 / 0xc×2 / 0x58×1 / 0x4×1 / 0x14×1 / 0x28×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b20b8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b20bc mov r4, r0
 *   @0x2b20c0 sub sp, #0x34
 *   @0x2b20c4 mov r9, r1
 *   @0x2b20c8 mov r1, r2
 *   @0x2b20cc ldr r5, [sp, #0x58]
 *   @0x2b20d0 svcls #0x170f53
 *   @0x2b20d4 ldrb r3, [r6, #0x4]
 *   @0x2b20d8 str r0, [sp, #0x14]
 *   @0x2b20dc str r6, [sp, #0x10]
 *   @0x2b20e0 .word 0x96093018
 *   @0x2b20e4 str r6, [sp, #0x28]
 *   @0x2b20e8 str r6, [sp, #0x1c]
 *   @0x2b20ec strmi pc, [r2], r1, ror #20
 *   @0x2b20f0 cmp r0, #0x0
 *   @0x2b20f4 mov r0, r4
 *   @0x2b20f8 add r2, sp, #0xc
 *   @0x2b20fc .word 0x4606fa59
 *   @0x2b2100 cbnz r0, 0x2b210e <png_write_iTXt+0x56>
 *   @0x2b2104 mov r0, r4
 *   @0x2b2108 bl 0x2a6474 <png_warning>
 *   @0x2b210c str r6, [sp, #0xc]
 *   @0x2b2110 mov r0, r5
 *   @0x2b2114 pkhbtmi lr, r0, r2, lsl #20
 *   @0x2b2118 b 0x2b211c <png_write_iTXt+0x64>
 *   @0x2b211c cbz r7, 0x2b2128 <png_write_iTXt+0x70>
 *   @0x2b2120 blx 0xb6538 <strlen@plt>
 *   @0x2b2124 mov r2, r0
 *   @0x2b2128 mov r2, r7
 *   @0x2b212c ldrtmi r0, [r9], -r2, lsl #6
 *   @0x2b2130 add.w r11, sp, #0x1c
 *   @0x2b2134 mov r0, r4
 *   @0x2b2138 .word 0xf7feb000
 *   @0x2b213c .word 0xf10afeff
 *   @0x2b2140 ldrtmi r0, [r2], #-517
 *   @0x2b2144 add r1, sp, #0x14
 *   @0x2b2148 add r2, r0
 *   @0x2b214c bl 0x2b11a0 <png_write_chunk_start>
 *   @0x2b2150 mov r0, r4
 *   @0x2b2154 add.w r2, r10, #0x1
 *   @0x2b2158 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b215c cmp.w r9, #0x1
 *   @0x2b2160 beq 0x2b2168 <png_write_iTXt+0xb0>
 *   @0x2b2164 strdle r3, r4, [r1, -pc]
 *   @0x2b2168 movs r3, #0x0
 *   @0x2b216c movs r3, #0x1
 *   @0x2b2170 mov r0, r4
 *   @0x2b2174 strb.w r3, [sp, #0x8]
 *   @0x2b2178 mov r1, r7
 *   @0x2b217c .word 0xf88d0900
 *   @0x2b2180 .word 0xf7ff9009
 *   @0x2b2184 stmdbls r3, {r0, r1, r2, r3, r4, r5, r11, r12, sp, lr, pc}
 *   @0x2b2188 mov r0, r4
 *   @0x2b218c strb.w r9, [sp, #0x8]
 *   @0x2b2190 cmp r1, r9
 *   @0x2b2194 moveq r1, r7
 *   @0x2b2198 .word 0xf108f835
 *   @0x2b219c strtmi r0, [r0], -r1, lsl #4
 *   @0x2b21a0 cmp r5, r9
 *   @0x2b21a4 movne r1, r5
 *   @0x2b21a8 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b21ac mov r1, r11
 *   @0x2b21b0 bl 0x2b1226 <png_write_chunk_data+0x22>
 *   @0x2b21b4 mov r0, r4
 *   @0x2b21b8 strtmi pc, [r0], -lr, ror #16
 *   @0x2b21bc ldr r1, [sp, #0x10]
 *   @0x2b21c0 qadd8mi pc, r0, sp
 *   @0x2b21c4 ldr r1, [sp, #0xc]
 *   @0x2b21c8 mullt sp, r9, sp
 *   @0x2b21cc pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b21d0 bgt 0x2b2108 <png_write_iTXt+0x50>
 *   @0x2b21d4 stm r5!, {r1, r2, r4, r5}
 *
 * ══ §96/102 anon_317e5c  0x317e5c  size 288  72 条（0x317e5c..0x317f7c）
 * @func 0x317e5c 0x317f7c  size 288  72 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3f2904 / 0xfe653f14 / 0x3936bc / 0x397054 / 0x323fec
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x317e5c .word 0x460db5f0
 *   @0x317e60 smlabbhs r0, r5, r0, r11
 *   @0x317e64 ldrmi r10, [r6], -r4, lsl #24
 *   @0x317e68 strmi r4, [r10], -r7, lsl #12
 *   @0x317e6c strtmi r4, [r8], -r11, lsl #12
 *   @0x317e70 stcvc p8, c15, [r4, #-272]
 *   @0x317e74 .word 0xf0019400
 *   @0x317e78 ldmdavs r7!, {r3, r4, r5, r6, r7, r9, r10, r11, sp, lr, pc}
 *   @0x317e7c andhs r2, r1, #0, #2
 *   @0x317e80 strmi r4, [r11], -r8, lsr #12
 *   @0x317e84 strls r9, [r3, -r0, lsl #8]
 *   @0x317e88 cdp p0, #0xe, c15, c14, c1, #0x0
 *   @0x317e8c andhs r2, pc, #0, #2
 *   @0x317e90 ldmdbvs r6!, {r3, r5, r9, r10, lr}
 *   @0x317e94 strls r4, [r0], #-1547
 *   @0x317e98 cdp p0, #0xa, c15, c4, c1, #0x0
 *   @0x317e9c .word 0x21009b03
 *   @0x317ea0 .word 0xf0034628
 *   @0x317ea4 andhs r0, pc, #67108864
 *   @0x317ea8 .word 0x460b431e
 *   @0x317eac strls r9, [r3], -r0, lsl #8
 *   @0x317eb0 cdp p0, #0xd, c15, c10, c1, #0x0
 *   @0x317eb4 ldcllt p0, c11, [r0, #20]!
 *   @0x317eb8 .word 0xf002b508
 *   @0x317ebc stmdahs r0, {r1, r2, r3, r4, r5, r6, r7, r8, r10, r11, sp, lr, pc}
 *   @0x317ec0 andhs r11, r8, r12, lsl #30
 *   @0x317ec4 stclt p0, c2, [r8, #-36]
 *   @0x317ec8 .word 0x4604b570
 *   @0x317ecc .word 0x21004608
 *   @0x317ed0 ldrmi r11, [r5], -r4, lsl #1
 *   @0x317ed4 andhs r4, sp, #11534336
 *   @0x317ed8 strls r10, [r0], -r3, lsl #28
 *   @0x317edc cdp p0, #0x8, c15, c2, c1, #0x0
 *   @0x317ee0 stmdavs r10!, {r0, r3, r5, r6, r8, r11, sp, lr}
 *   @0x317ee4 rsbvs r6, r1, #704512
 *   @0x317ee8 adcvs r9, r2, #49152
 *   @0x317eec eorvs r6, r1, #-1946157056
 *   @0x317ef0 ldcllt p0, c11, [r0, #-16]!
 *   @0x317ef4 blvs 0x3f2904 <MAX_TEXTURE_SIZE+0x5c>
 *   @0x317ef8 bvs 0x1444f40 <b2_toiTime+0xceba9c>
 *   @0x317efc andhs r6, r0, #10
 *   @0x317f00 mrsvs r6, spsr
 *   @0x317f04 .word 0xbc10604a
 *   @0x317f08 svclt #0x4770
 *   @0x317f0c bllt 0xfe653f14 <b2_toiTime+0xfffffffffdefaa70>
 *   @0x317f10 .word 0x460db5f0
 *   @0x317f14 ldrmi r11, [r7], -r3, lsl #1
 *   @0x317f18 .word 0xf7ff4604
 *   @0x317f1c qsub8mi pc, r8, r7
 *   @0x317f20 .word 0xf002ae02
 *   @0x317f24 .word 0x4603edf2
 *   @0x317f28 .word 0xf8139001
 *   @0x317f2c .word 0xf8461b01
 *   @0x317f30 ldrtmi r3, [r0], -r4, lsl #26
 *   @0x317f34 ldc2l p0, c15, [lr], #-0
 *   @0x317f38 .word 0xf0024628
 *   @0x317f3c blls 0x3936bc <ft_adobe_glyph_list+0x2d98>
 *   @0x317f40 .word 0xf8132000
 *   @0x317f44 bhs 0x2e2b50 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x25c>
 *   @0x317f48 andle r9, r4, r1, lsl #6
 *   @0x317f4c .word 0xf0004630
 *   @0x317f50 blls 0x397054 <ft_adobe_glyph_list+0x6730>
 *   @0x317f54 ldmdavs r10!, {r3, r4, r11, r12}
 *   @0x317f58 .word 0xf85043d2
 *   @0x317f5c bl 0x323fec
 *   @0x317f60 teqlt r3, r2, lsl #1
 *   @0x317f64 strmi r2, [r2], -r0, lsl #6
 *   @0x317f68 svcne #0x4f852
 *   @0x317f6c stmdbhs r0, {r0, r8, r9, r12, sp}
 *   @0x317f70 adcvs sp, r3, #-2147483586
 *   @0x317f74 .word 0x63602304
 *   @0x317f78 andlt r6, r3, r3, lsr #6
 *
 * ══ §97/102 F_DateGetDayOfYear(RValue&, CInstance*, CInstance*, int, RValue*)  0x1182c8  size 284  71 条（0x1182c8..0x1183e4）
 * @func 0x1182c8 0x1183e4  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / GetSecondOfYear(int, int, int, int, int, int) / 0xb682c / 0x82908c
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x18×1 / 0xb4×1 / 0x14×1 / 0x10×1 / 0x8×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1182c8 push {r4, lr}
 *   @0x1182cc sub sp, sp, #16
 *   @0x1182d0 mov r3, #0
 *   @0x1182d4 mov r4, r0
 *   @0x1182d8 str r3, [r0, #0xc]
 *   @0x1182dc mov r1, r3
 *   @0x1182e0 str r3, [r0]
 *   @0x1182e4 str r3, [r0, #0x4]
 *   @0x1182e8 ldr r0, [sp, #0x18]
 *   @0x1182ec bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1182f0 vldr d7, [pc, #208]
 *   @0x1182f4 vldr d5, [pc, #212]
 *   @0x1182f8 vmov d6, r0, r1
 *   @0x1182fc vsub.f64 d7, d6, d7
 *   @0x118300 vabs.f64 d4, d7
 *   @0x118304 vcmpe.f64 d4, d5
 *   @0x118308 vmrs APSR_nzcv, fpscr
 *   @0x11830c vldrls d7, [pc, #196]
 *   @0x118310 vldrhi d6, [pc, #192]
 *   @0x118314 vmul.f64 d5, d7, d6
 *   @0x118318 vmov r0, r1, d5
 *   @0x11831c bl 0x3194a0 <__fixdfdi>
 *   @0x118320 mov r3, r1
 *   @0x118324 ldr r1, [pc, #0xb4]
 *   @0x118328 mov r2, r0
 *   @0x11832c strd r2, r3, [sp, #8]
 *   @0x118330 add r1, pc, r1
 *   @0x118334 add r0, sp, #8
 *   @0x118338 ldrb r3, [r1]
 *   @0x11833c cmp r3, #0
 *   @0x118340 bne 0x1183b8 <_Z18F_DateGetDayOfYearR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x118344 bl 0xb6820 <gmtime64@plt>
 *   @0x118348 mov r12, r0
 *   @0x11834c cmp r12, #0
 *   @0x118350 beq 0x1183b0 <_Z18F_DateGetDayOfYearR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x118354 ldr lr, [r12, #0x4]
 *   @0x118358 ldr r0, [r12, #0x14]
 *   @0x11835c ldr r1, [r12, #0x10]
 *   @0x118360 ldr r2, [r12, #0xc]
 *   @0x118364 add r0, r0, #1888
 *   @0x118368 ldr r3, [r12, #0x8]
 *   @0x11836c add r1, r1, #1
 *   @0x118370 str lr, [sp]
 *   @0x118374 add r2, r2, #1
 *   @0x118378 ldr r12, [r12]
 *   @0x11837c add r0, r0, #12
 *   @0x118380 str r12, [sp, #0x4]
 *   @0x118384 bl 0x1180c0 <_Z15GetSecondOfYeariiiiii>
 *   @0x118388 movw r3, #0x4507
 *   @0x11838c movt r3, #0xc22e
 *   @0x118390 smull r2, r3, r3, r0
 *   @0x118394 asr r1, r0, #31
 *   @0x118398 add r0, r3, r0
 *   @0x11839c rsb r0, r1, r0, asr #16
 *   @0x1183a0 vmov s11, r0
 *   @0x1183a4 vcvt.f64.s32 d5, s11
 *   @0x1183a8 vmov r2, r3, d5
 *   @0x1183ac stm r4, {r2, r3}
 *   @0x1183b0 add sp, sp, #16
 *   @0x1183b4 pop {r4, pc}
 *   @0x1183b8 bl 0xb682c <localtime64@plt>
 *   @0x1183bc mov r12, r0
 *   @0x1183c0 b 0x11834c <_Z18F_DateGetDayOfYearR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1183c4 nop
 *   @0x1183c8 andeq r0, r0, r0
 *   @0x1183cc sbcsmi pc, r8, r0, asr #16
 *   @0x1183d0 bl 0x82908c <b2_toiTime+0xcfbe8>
 *   @0x1183d4 svclo #0x1a36e2
 *   @0x1183d8 andeq r0, r0, r0
 *   @0x1183dc rscsmi r1, r5, r0, lsl #16
 *   @0x1183e0 eoreq r9, sp, r8, lsl #28
 *
 * ══ §98/102 F_BackgroundCreateFromSurface(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c564  size 284  71 条（0x12c564..0x12c680）
 * @func 0x12c564 0x12c680  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / YYGetBool(RValue const*, int)×3 / Background_AddEmpty() / Background_Data(int) / GR_Surface_Screenshot_Part(int, int, int, int, int) / CBackground::CreateFromBitmap(IBitmap*, bool, bool, bool, bool)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x28×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c564 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x12c568 sub sp, sp, #8
 *   @0x12c56c mov r6, #0
 *   @0x12c570 str r6, [r0, #0xc]
 *   @0x12c574 ldr r4, [sp, #0x28]
 *   @0x12c578 mov r5, r0
 *   @0x12c57c mov r8, r3
 *   @0x12c580 bl 0xc41f0 <_Z19Background_AddEmptyv>
 *   @0x12c584 mov r9, r0
 *   @0x12c588 bl 0xc3794 <_Z15Background_Datai>
 *   @0x12c58c vmov s15, r9
 *   @0x12c590 mov r1, r6
 *   @0x12c594 vcvt.f64.s32 d7, s15
 *   @0x12c598 vmov r2, r3, d7
 *   @0x12c59c stm r5, {r2, r3}
 *   @0x12c5a0 mov r7, r0
 *   @0x12c5a4 mov r0, r4
 *   @0x12c5a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c5ac mov r1, #1
 *   @0x12c5b0 mov r5, r0
 *   @0x12c5b4 mov r0, r4
 *   @0x12c5b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c5bc mov r1, #2
 *   @0x12c5c0 mov r10, r0
 *   @0x12c5c4 mov r0, r4
 *   @0x12c5c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c5cc mov r1, #3
 *   @0x12c5d0 mov r9, r0
 *   @0x12c5d4 mov r0, r4
 *   @0x12c5d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c5dc mov r1, #4
 *   @0x12c5e0 mov r6, r0
 *   @0x12c5e4 mov r0, r4
 *   @0x12c5e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c5ec mov r1, r10
 *   @0x12c5f0 mov r2, r9
 *   @0x12c5f4 mov r3, r6
 *   @0x12c5f8 str r0, [sp]
 *   @0x12c5fc mov r0, r5
 *   @0x12c600 bl 0x1720e4 <_Z26GR_Surface_Screenshot_Partiiiii>
 *   @0x12c604 subs r5, r0, #0
 *   @0x12c608 beq 0x12c678 <_Z29F_BackgroundCreateFromSurfaceR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x12c60c mov r1, #5
 *   @0x12c610 mov r0, r4
 *   @0x12c614 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c618 mov r1, #6
 *   @0x12c61c eor r9, r0, #1
 *   @0x12c620 mov r6, r0
 *   @0x12c624 mov r0, r4
 *   @0x12c628 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c62c cmp r8, #7
 *   @0x12c630 uxtb r9, r9
 *   @0x12c634 mov r10, r0
 *   @0x12c638 moveq r0, #1
 *   @0x12c63c beq 0x12c64c <_Z29F_BackgroundCreateFromSurfaceR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x12c640 mov r0, r4
 *   @0x12c644 mov r1, #7
 *   @0x12c648 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c64c str r0, [sp]
 *   @0x12c650 mov r3, r10
 *   @0x12c654 mov r0, r7
 *   @0x12c658 str r9, [sp, #0x4]
 *   @0x12c65c mov r2, r6
 *   @0x12c660 mov r1, r5
 *   @0x12c664 bl 0xc244c <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb>
 *   @0x12c668 ldr r3, [r5]
 *   @0x12c66c mov r0, r5
 *   @0x12c670 ldr r3, [r3, #0x4]
 *   @0x12c674 blx r3
 *   @0x12c678 add sp, sp, #8
 *   @0x12c67c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §99/102 F_BackgroundReplace(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c90c  size 284  71 条（0x12c90c..0x12ca28）
 * @func 0x12c90c 0x12ca28  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)×5 / YYGetString(RValue const*, int)×2 / Background_Replace(int, char const*, bool, bool, bool)×2 / YYGetInt32(RValue const*, int) / Background_Data(int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0xc×2 / 0x28×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c90c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x12c910 sub sp, sp, #12
 *   @0x12c914 mov r1, #0
 *   @0x12c918 mov r5, r0
 *   @0x12c91c ldr r4, [sp, #0x28]
 *   @0x12c920 mov r7, r3
 *   @0x12c924 mov r0, r4
 *   @0x12c928 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c92c mov r6, r0
 *   @0x12c930 bl 0xc3794 <_Z15Background_Datai>
 *   @0x12c934 subs r8, r0, #0
 *   @0x12c938 beq 0x12ca0c <_Z19F_BackgroundReplaceR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x12c93c cmp r7, #5
 *   @0x12c940 mov r0, r4
 *   @0x12c944 mov r1, #1
 *   @0x12c948 beq 0x12c9bc <_Z19F_BackgroundReplaceR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x12c94c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12c950 mov r1, #2
 *   @0x12c954 mov r8, r0
 *   @0x12c958 mov r0, r4
 *   @0x12c95c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c960 mov r1, #3
 *   @0x12c964 mov r7, r0
 *   @0x12c968 mov r0, r4
 *   @0x12c96c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c970 mov r12, #1
 *   @0x12c974 mov r1, r8
 *   @0x12c978 mov r2, r7
 *   @0x12c97c str r12, [sp]
 *   @0x12c980 mov r3, r0
 *   @0x12c984 mov r0, r6
 *   @0x12c988 bl 0xc3aa4 <_Z18Background_ReplaceiPKcbbb>
 *   @0x12c98c cmp r0, #0
 *   @0x12c990 mov r3, #0
 *   @0x12c994 str r3, [r5, #0xc]
 *   @0x12c998 movne r2, #0
 *   @0x12c99c movtne r2, #0x3ff0
 *   @0x12c9a0 bne 0x12c9ac <_Z19F_BackgroundReplaceR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x12c9a4 mov r3, #0
 *   @0x12c9a8 mov r2, r3
 *   @0x12c9ac str r3, [r5]
 *   @0x12c9b0 str r2, [r5, #0x4]
 *   @0x12c9b4 add sp, sp, #12
 *   @0x12c9b8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x12c9bc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12c9c0 mov r1, #2
 *   @0x12c9c4 mov r9, r0
 *   @0x12c9c8 mov r0, r4
 *   @0x12c9cc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c9d0 mov r1, #3
 *   @0x12c9d4 mov r8, r0
 *   @0x12c9d8 mov r0, r4
 *   @0x12c9dc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c9e0 mov r1, #4
 *   @0x12c9e4 mov r7, r0
 *   @0x12c9e8 mov r0, r4
 *   @0x12c9ec bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c9f0 mov r1, r9
 *   @0x12c9f4 mov r2, r8
 *   @0x12c9f8 mov r3, r7
 *   @0x12c9fc str r0, [sp]
 *   @0x12ca00 mov r0, r6
 *   @0x12ca04 bl 0xc3aa4 <_Z18Background_ReplaceiPKcbbb>
 *   @0x12ca08 b 0x12c98c <_Z19F_BackgroundReplaceR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12ca0c ldr r0, [pc, #0x10]
 *   @0x12ca10 mov r1, r8
 *   @0x12ca14 add r0, pc, r0
 *   @0x12ca18 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12ca1c str r8, [r5, #0xc]
 *   @0x12ca20 b 0x12c9a4 <_Z19F_BackgroundReplaceR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x12ca24 eoreq r0, r1, r4, lsr #21
 *
 * ══ §100/102 F_SpriteSave(RValue&, CInstance*, CInstance*, int, RValue*)  0x1307f0  size 284  71 条（0x1307f0..0x13090c）
 * @func 0x1307f0 0x13090c  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int) / Sprite_Data(int) / CSprite::GetBitmap32(int) / WritePNG32(char*, void*, int, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x20×4 / 0x4×2 / 0x74×1 / 0x-4×1 / 0x24×1 / 0x1c×1 / 0x28×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1307f0 push {r4, r5, r6, r7, r8, lr}
 *   @0x1307f4 sub sp, sp, #8
 *   @0x1307f8 mov r1, #0
 *   @0x1307fc ldr r4, [sp, #0x20]
 *   @0x130800 mov r0, r4
 *   @0x130804 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130808 mov r1, #1
 *   @0x13080c mov r5, r0
 *   @0x130810 mov r0, r4
 *   @0x130814 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130818 mov r1, #2
 *   @0x13081c mov r7, r0
 *   @0x130820 mov r0, r4
 *   @0x130824 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x130828 mov r8, r0
 *   @0x13082c mov r0, r5
 *   @0x130830 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x130834 subs r6, r0, #0
 *   @0x130838 beq 0x1308bc <_Z12F_SpriteSaveR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x13083c ldr r4, [r6, #0x74]
 *   @0x130840 cmp r4, #0
 *   @0x130844 bne 0x1308c4 <_Z12F_SpriteSaveR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x130848 mov r1, r7
 *   @0x13084c bl 0x1e6398 <_ZN7CSprite11GetBitmap32Ei>
 *   @0x130850 subs r5, r0, #0
 *   @0x130854 beq 0x1308dc <_Z12F_SpriteSaveR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x130858 add r2, sp, #8
 *   @0x13085c mov r1, r4
 *   @0x130860 str r4, [sp]
 *   @0x130864 mov r3, sp
 *   @0x130868 str r4, [r2, #-0x4]!
 *   @0x13086c ldr r12, [r5]
 *   @0x130870 ldr r12, [r12, #0x24]
 *   @0x130874 blx r12
 *   @0x130878 ldr r1, [sp, #0x4]
 *   @0x13087c cmp r1, #0
 *   @0x130880 mov r4, r0
 *   @0x130884 beq 0x130898 <_Z12F_SpriteSaveR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x130888 mov r0, r8
 *   @0x13088c ldr r2, [r6, #0x1c]
 *   @0x130890 ldr r3, [r6, #0x20]
 *   @0x130894 bl 0x16cc8c <_Z10WritePNG32PcPvii>
 *   @0x130898 ldr r3, [r5]
 *   @0x13089c mov r0, r5
 *   @0x1308a0 mov r1, r4
 *   @0x1308a4 ldr r3, [r3, #0x28]
 *   @0x1308a8 blx r3
 *   @0x1308ac ldr r3, [r5]
 *   @0x1308b0 mov r0, r5
 *   @0x1308b4 ldr r3, [r3, #0x4]
 *   @0x1308b8 blx r3
 *   @0x1308bc add sp, sp, #8
 *   @0x1308c0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1308c4 ldr r0, [pc, #0x34]
 *   @0x1308c8 mov r1, #0
 *   @0x1308cc add r0, pc, r0
 *   @0x1308d0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1308d4 add sp, sp, #8
 *   @0x1308d8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1308dc ldr r3, [pc, #0x20]
 *   @0x1308e0 ldr r1, [pc, #0x20]
 *   @0x1308e4 ldr r3, [pc, r3]
 *   @0x1308e8 add r1, pc, r1
 *   @0x1308ec ldr r0, [r3]
 *   @0x1308f0 ldr r3, [r0]
 *   @0x1308f4 ldr r3, [r3, #0xc]
 *   @0x1308f8 blx r3
 *   @0x1308fc b 0x1308bc <_Z12F_SpriteSaveR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x130900 eoreq sp, r0, r8, lsl #19
 *   @0x130904 eoreq r12, r11, r0, lsr lr
 *   @0x130908 mlaeq r0, r12, r9, sp
 *
 * ══ §101/102 F_SoundEffectCompressor(RValue&, CInstance*, CInstance*, int, RValue*)  0x133fa0  size 284  71 条（0x133fa0..0x1340bc）
 * @func 0x133fa0 0x1340bc  size 284  71 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×6 / YYGetInt32(RValue const*, int) / Sound_Data(int) / CSound::GetSoundId() / SND_Set_Effect_Compressor(int, double, double, double, double, double, double)
 * 字段偏移 top8: 0x2c×2 / 0x28×2 / 0x108×1 / 0x60×1 / 0xec×1 / 0x14×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x133fa0 ldr r3, [pc, #0x108]
 *   @0x133fa4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x133fa8 ldr r3, [pc, r3]
 *   @0x133fac sub sp, sp, #60
 *   @0x133fb0 ldrb r3, [r3]
 *   @0x133fb4 ldr r10, [sp, #0x60]
 *   @0x133fb8 cmp r3, #0
 *   @0x133fbc bne 0x133fd4 <_Z23F_SoundEffectCompressorR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x133fc0 ldr r3, [pc, #0xec]
 *   @0x133fc4 ldr r3, [pc, r3]
 *   @0x133fc8 ldrb r1, [r3]
 *   @0x133fcc cmp r1, #0
 *   @0x133fd0 beq 0x133fdc <_Z23F_SoundEffectCompressorR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x133fd4 add sp, sp, #60
 *   @0x133fd8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x133fdc mov r0, r10
 *   @0x133fe0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x133fe4 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x133fe8 subs r1, r0, #0
 *   @0x133fec beq 0x13409c <_Z23F_SoundEffectCompressorR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x133ff0 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x133ff4 mov r1, #1
 *   @0x133ff8 mov r11, r0
 *   @0x133ffc mov r0, r10
 *   @0x134000 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134004 mov r2, r0
 *   @0x134008 mov r3, r1
 *   @0x13400c mov r0, r10
 *   @0x134010 mov r1, #2
 *   @0x134014 str r2, [sp, #0x2c]
 *   @0x134018 str r3, [sp, #0x28]
 *   @0x13401c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134020 mov r8, r0
 *   @0x134024 mov r9, r1
 *   @0x134028 mov r0, r10
 *   @0x13402c mov r1, #3
 *   @0x134030 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134034 mov r6, r0
 *   @0x134038 mov r7, r1
 *   @0x13403c mov r0, r10
 *   @0x134040 mov r1, #4
 *   @0x134044 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134048 mov r4, r0
 *   @0x13404c mov r5, r1
 *   @0x134050 mov r0, r10
 *   @0x134054 mov r1, #5
 *   @0x134058 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13405c strd r0, r1, [sp, #48]
 *   @0x134060 mov r0, r10
 *   @0x134064 mov r1, #6
 *   @0x134068 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13406c vldr d7, [sp, #48]
 *   @0x134070 strd r8, r9, [sp]
 *   @0x134074 vstr d7, [sp, #24]
 *   @0x134078 strd r6, r7, [sp, #8]
 *   @0x13407c strd r4, r5, [sp, #16]
 *   @0x134080 ldr r2, [sp, #0x2c]
 *   @0x134084 ldr r3, [sp, #0x28]
 *   @0x134088 strd r0, r1, [sp, #32]
 *   @0x13408c mov r0, r11
 *   @0x134090 bl 0x21f12c <_Z25SND_Set_Effect_Compressoridddddd>
 *   @0x134094 add sp, sp, #60
 *   @0x134098 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13409c ldr r0, [pc, #0x14]
 *   @0x1340a0 add r0, pc, r0
 *   @0x1340a4 add sp, sp, #60
 *   @0x1340a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1340ac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1340b0 eoreq r10, r11, r8, lsl #27
 *   @0x1340b4 eoreq r11, r11, r8, lsl #1
 *   @0x1340b8 eoreq r11, r0, r12, ror #7
 *
 * ══ §102/102 SND_PlatformResume()  0x21efc8  size 180  38 条（0x21efc8..0x21f07c）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x21efc8 0x21f07c  size 180  38 条
 * 部分覆盖: 本节 38/45 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21efcc→0x755314, 0x21efe8→0x755363, 0x21effc→0x755334, 0x21f010→0x755338
 * 调用序列: SoundHardware::Resume(void*)
 * 字段偏移 top8: 0x94×2 / 0x1×2 / 0x7c×1 / 0x6c×1 / 0x5c×1 / 0x58×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21efc8 ldr r3, [pc, #0x94]
 *   @0x21efcc ldr r2, [pc, #0x94]
 *   @0x21efd0 add r3, pc, r3
 *   @0x21efd4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x21efd8 ldr r2, [r3, r2]
 *   @0x21efdc ldrb r2, [r2]
 *   @0x21effc ldr r2, [pc, #0x6c]
 *   @0x21f000 ldr r9, [r3, r2]
 *   @0x21f004 ldr r2, [r9]
 *   @0x21f008 cmp r2, #0
 *   @0x21f00c pople {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x21f010 ldr r2, [pc, #0x5c]
 *   @0x21f014 mov r5, r4
 *   @0x21f018 ldr r8, [pc, #0x58]
 *   @0x21f01c mov r7, r4
 *   @0x21f020 ldr r10, [r3, r2]
 *   @0x21f024 add r8, pc, r8
 *   @0x21f028 ldr r6, [r10, #0x4]
 *   @0x21f02c add r5, r5, #1
 *   @0x21f030 add r6, r6, r4
 *   @0x21f034 add r4, r4, #20
 *   @0x21f038 ldrb r3, [r6, #0x1]
 *   @0x21f03c cmp r3, #0
 *   @0x21f040 beq 0x21f054 <_Z18SND_PlatformResumev+0x8c>
 *   @0x21f044 ldr r0, [r8]
 *   @0x21f048 ldr r1, [r6, #0x8]
 *   @0x21f04c bl 0x220e68 <_ZN13SoundHardware6ResumeEPv>
 *   @0x21f050 strb r7, [r6, #0x1]
 *   @0x21f054 ldr r3, [r9]
 *   @0x21f058 cmp r3, r5
 *   @0x21f05c bgt 0x21f028 <_Z18SND_PlatformResumev+0x60>
 *   @0x21f060 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x21f064 andseq r2, sp, r0, lsl #25
 *   @0x21f068 .word 0xffffd0e0
 *   @0x21f06c .word 0xffffd3fc
 *   @0x21f070 .word 0xfffff7c4
 *   @0x21f074 .word 0xfffff7c8
 *   @0x21f078 subseq r6, r3, r0, lsl #6
 */
