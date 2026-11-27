/* cally 逆向卡：All_20 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 13 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/13 anon_2fa330  0x2fa330  size 4952  1238 条（0x2fa330..0x2fb688）
 * @func 0x2fa330 0x2fb688  size 4952  1238 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x916f90 / 0x3aa720 / 0xff07869c / 0x3b8790 / 0xff5ef86c / 0x378834 / 0x378858 / 0xffb4b324
 * 字段偏移 top8: 0x4×2 / 0x2×1 / 0xa×1 / 0x5×1 / 0x14×1 / 0x12×1 / 0x16×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2fa330 .word 0xf801f7ed
 *   @0x2fa334 strtmi r6, [r8], -r6, lsr #9
 *   @0x2fa338 pop {r0, r5, r9, r10, lr}
 *   @0x2fa33c .word 0xf7ec47f0
 *   @0x2fa340 pop {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, pc}
 *   @0x2fa344 ldrblt r8, [r0, #0x7f0]!
 *   @0x2fa348 ldrmi r11, [r7], -r5, lsl #1
 *   @0x2fa34c .word 0x9c0a680a
 *   @0x2fa350 ldrmi r4, [lr], -sp, lsl #12
 *   @0x2fa354 andle r4, lr, #536870922
 *   @0x2fa358 .word 0x2101681b
 *   @0x2fa35c movwls r4, #0x37a
 *   @0x2fa360 movwls r10, #0x1b03
 *   @0x2fa364 .word 0xf304fb07
 *   @0x2fa368 cdp2 p7, #0x9, c15, c1, c13, #0x7
 *   @0x2fa36c stmdals r3, {r4, r5, sp, lr}
 *   @0x2fa370 eorvs r11, r12, r0, lsl r9
 *   @0x2fa374 andhs lr, r0, r0
 *   @0x2fa378 ldcllt p0, c11, [r0, #20]!
 *   @0x2fa37c mvnsmi lr, sp, lsr #18
 *   @0x2fa380 strmi r4, [r8], r4, lsl #12
 *   @0x2fa384 eorvs r4, r1, r5, lsl r6
 *   @0x2fa388 bhs 0x312518 <af_shaper_get_elem+0x7d86>
 *   @0x2fa38c svcvs #0xd3d07b
 *   @0x2fa390 strbeq pc, [r12, -r2, lsl #2]
 *   @0x2fa394 ldrbteq pc, [r8], r0, lsl #2
 *   @0x2fa398 orrslo pc, r0, r0, asr #17
 *   @0x2fa39c .word 0x3080f8d2
 *   @0x2fa3a0 orrslo pc, r4, r0, asr #17
 *   @0x2fa3a4 .word 0x3088f8d2
 *   @0x2fa3a8 orrslo pc, r12, r0, asr #17
 *   @0x2fa3ac .word 0x308cf8d2
 *   @0x2fa3b0 asrlo pc, r0, #17
 *   @0x2fa3b4 .word 0x3084f8d2
 *   @0x2fa3b8 orrslo pc, r8, r0, asr #17
 *   @0x2fa3bc ldrsblo pc, [r0], r2
 *   @0x2fa3c0 .word 0x31a4f8c0
 *   @0x2fa3c4 .word 0xf8c06f93
 *   @0x2fa3c8 svcgt #0xf30d8
 *   @0x2fa3cc svcgt #0xfc60f
 *   @0x2fa3d0 ldm r7, {r0, r1, r2, r3, r9, r10, lr, pc}
 *   @0x2fa3d4 stm r6, {r0, r1}
 *   @0x2fa3d8 .word 0xf1040003
 *   @0x2fa3dc bvs 0xffebbf54 <b2_toiTime+0xffffffffff762ab0>
 *   @0x2fa3e0 strgt r12, [pc], -pc, lsl #30
 *   @0x2fa3e4 muleq r7, r7, r8
 *   @0x2fa3e8 andeq lr, r7, r6, lsl #17
 *   @0x2fa3ec ldrsblo pc, [r4], r5
 *   @0x2fa3f0 .word 0x31a8f8c4
 *   @0x2fa3f4 ldrsblo pc, [r8], r5
 *   @0x2fa3f8 .word 0x31acf8c4
 *   @0x2fa3fc stmne r9!, {r8, r9, sp} ^
 *   @0x2fa400 orrslo r1, r12, r2, ror #17
 *   @0x2fa404 .word 0xf5023308
 *   @0x2fa408 blhs 0x916f90 <b2_toiTime+0x1bdaec>
 *   @0x2fa40c stm r2, {r0, r1, r8, r11, lr, pc}
 *   @0x2fa410 mvnsle r0, r3
 *   @0x2fa414 .word 0x01b4f105
 *   @0x2fa418 .word 0xf5042244
 *   @0x2fa41c .word 0xf5057090
 *   @0x2fa420 .word 0xf5bc7584
 *   @0x2fa424 .word 0xf855e8cc
 *   @0x2fa428 .word 0xf1043c10
 *   @0x2fa42c .word 0xf10406b4
 *   @0x2fa430 .word 0xf8c40724
 *   @0x2fa434 .word 0xf8553180
 *   @0x2fa438 .word 0xf8c43c0c
 *   @0x2fa43c rfeda r5!
 *   @0x2fa440 .word 0xf8a43c08
 *   @0x2fa444 .word 0xf85531d8
 *   @0x2fa448 .word 0xf8c43c04
 *   @0x2fa44c stcgt p1, c3, [pc, #-880]
 *   @0x2fa450 stcgt p6, c12, [pc, #-60]
 *   @0x2fa454 ldrtmi r12, [r8], -pc, lsl #12
 *   @0x2fa458 .word 0x2100682b
 *   @0x2fa45c ldrtmi r2, [sp], -r4, lsr #4
 *   @0x2fa460 .word 0xf1046033
 *   @0x2fa464 .word 0xf5bc0648
 *   @0x2fa468 stcgt p8, c14, [pc, #-656]
 *   @0x2fa46c stcgt p6, c12, [pc, #-60]
 *   @0x2fa470 stmdavs r11!, {r0, r1, r2, r3, r9, r10, lr, pc}
 *   @0x2fa474 .word 0xf1046033
 *   @0x2fa478 svcgt #0xf066c
 *   @0x2fa47c svcgt #0xfc60f
 *   @0x2fa480 stmdavs r11!, {r0, r1, r2, r3, r9, r10, lr, pc}
 *   @0x2fa484 stmdbvs r3!, {r0, r1, r4, r5, sp, lr} ^
 *   @0x2fa488 stmvs r0!, {r2, r8, r10, r11, sp, pc}
 *   @0x2fa48c .word 0xf8452204
 *   @0x2fa490 strtmi r3, [r9], -r4, lsl #26
 *   @0x2fa494 ldrhlo pc, [r12, -r8]
 *   @0x2fa498 movwls r3, #0x320
 *   @0x2fa49c tsteq r8, #4, #2
 *   @0x2fa4a0 .word 0xff51f7ff
 *   @0x2fa4a4 .word 0x61639b03
 *   @0x2fa4a8 teqle r7, r0, lsl #16
 *   @0x2fa4ac .word 0x3188f8d4
 *   @0x2fa4b0 stmvs r0!, {r0, r3, r5, r9, r10, lr}
 *   @0x2fa4b4 movwls r2, #0x3201
 *   @0x2fa4b8 ldrhlo pc, [lr, -r8]
 *   @0x2fa4bc .word 0xf5049300
 *   @0x2fa4c0 .word 0xf7ff73c6
 *   @0x2fa4c4 rfeia sp!
 *   @0x2fa4c8 .word 0xf8c4300c
 *   @0x2fa4cc strmi r3, [r4], r8, lsl #3
 *   @0x2fa4d0 .word 0xf104bb18
 *   @0x2fa4d4 .word 0xf8a40590
 *   @0x2fa4d8 .word 0xf8a40098
 *   @0x2fa4dc .word 0xf104009a
 *   @0x2fa4e0 stcgt p6, c0, [pc, #-288]
 *   @0x2fa4e4 ldreq pc, [r0, r4, lsl #2]
 *   @0x2fa4e8 stcgt p6, c12, [pc, #-60]
 *   @0x2fa4ec stmdavs r11!, {r0, r1, r2, r3, r9, r10, lr, pc}
 *   @0x2fa4f0 .word 0xf1046033
 *   @0x2fa4f4 svcgt #0xf066c
 *   @0x2fa4f8 svcgt #0xfc60f
 *   @0x2fa4fc ldreq pc, [r0, r4, lsl #2]
 *   @0x2fa500 stmdavs r11!, {r0, r1, r2, r3, r9, r10, lr, pc}
 *   @0x2fa504 .word 0xf1046033
 *   @0x2fa508 svcgt #0xf0624
 *   @0x2fa50c svcgt #0xfc60f
 *   @0x2fa510 stmdavs r11!, {r0, r1, r2, r3, r9, r10, lr, pc}
 *   @0x2fa514 .word 0xf8846033
 *   @0x2fa518 strbtmi r12, [r0], -r12, ror #3
 *   @0x2fa51c pop {r2, r12, sp, pc}
 *   @0x2fa520 push {r4, r5, r6, r7, r8, pc}
 *   @0x2fa524 strdlt r4, r5, [r5], r0
 *   @0x2fa528 ldrsbhi pc, [r8], -r0
 *   @0x2fa52c stmdavs r6, {r2, r9, r10, lr}
 *   @0x2fa530 strmi r2, [pc], -r0, lsl #10
 *   @0x2fa534 andpl pc, r8, sp, lsr #17
 *   @0x2fa538 .word 0xf8ad4640
 *   @0x2fa53c .word 0xf8ad500a
 *   @0x2fa540 .word 0xf8ad500c
 *   @0x2fa544 .word 0xf7ec500e
 *   @0x2fa548 .word 0xf8d6f9fb
 *   @0x2fa54c bge 0x3c6dc4 <error_g0017+0x1fa68>
 *   @0x2fa550 andls r4, r0, #42991616
 *   @0x2fa554 .word 0xf8d3463a
 *   @0x2fa558 blge 0x3aa720 <error_g0017+0x33c4>
 *   @0x2fa55c ldrtmi r4, [r0], -r1, lsl #13
 *   @0x2fa560 .word 0xf10d47e0
 *   @0x2fa564 ldrtmi r0, [r0], -lr, lsl #6
 *   @0x2fa568 ldrtmi r9, [r9], -r0, lsl #6
 *   @0x2fa56c .word 0xf10d6b22
 *   @0x2fa570 .word 0xf7fe030a
 *   @0x2fa574 .word 0x4640fc58
 *   @0x2fa578 .word 0xf7ec4649
 *   @0x2fa57c stmiblt r8!, {r2, r4, r7, r8, r11, r12, sp, lr, pc}
 *   @0x2fa580 strhlo pc, [r8], -sp
 *   @0x2fa584 strhhs pc, [r12], -sp
 *   @0x2fa588 rfeib sp!
 *   @0x2fa58c .word 0x63a2300a
 *   @0x2fa590 adclo pc, r12, r4, asr #17
 *   @0x2fa594 strhlo pc, [lr], -sp
 *   @0x2fa598 adcslo pc, r0, r4, asr #17
 *   @0x2fa59c umaallo pc, r0, r4, r8
 *   @0x2fa5a0 ldrmi r11, [r8], -r3, lsr #18
 *   @0x2fa5a4 .word 0x63e22101
 *   @0x2fa5a8 subne pc, r0, r4, lsl #17
 *   @0x2fa5ac pop {r0, r2, r12, sp, pc}
 *   @0x2fa5b0 ldrblt r8, [r0, #-0x3f0]!
 *   @0x2fa5b4 stmibvs r4, {r0, r4, r9, r10, lr}
 *   @0x2fa5b8 ldrmi r4, [lr], -r5, lsl #12
 *   @0x2fa5bc .word 0xf7ec4620
 *   @0x2fa5c0 ldmdblt r0, {r1, r4, r5, r6, r8, r11, r12, sp, lr, pc} ^
 *   @0x2fa5c4 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2fa5c8 stc2 p7, c15, [r11], #-948
 *   @0x2fa5cc bvs 0xbe8a74 <b2_toiTime+0x48f5d0>
 *   @0x2fa5d0 sbclo pc, r4, r5, asr #17
 *   @0x2fa5d4 .word 0xf8c56a63
 *   @0x2fa5d8 ldcllt p0, c3, [r0, #-800]!
 *   @0x2fa5dc .word 0xf7ed6980
 *   @0x2fa5e0 ldrlt r11, [r8, #-0xc6b]!
 *   @0x2fa5e4 .word 0xf8d04604
 *   @0x2fa5e8 ldmiblt r11!, {r2, r8, r12, sp} ^
 *   @0x2fa5ec strhlo pc, [r12, -r0]!
 *   @0x2fa5f0 .word 0xf8d0b913
 *   @0x2fa5f4 strd r3, r4, [r4], -r8
 *   @0x2fa5f8 strhne pc, [r10, -r0]!
 *   @0x2fa5fc .word 0xf8d0b921
 *   @0x2fa600 .word 0xf8c430fc
 *   @0x2fa604 ands r3, r1, r4, lsl #2
 *   @0x2fa608 .word 0xf8d0b209
 *   @0x2fa60c .word 0xf7fe00f8
 *   @0x2fa610 rfeib r4!
 *   @0x2fa614 strmi r1, [r5], -r12, lsr #2
 *   @0x2fa618 ldrsbteq pc, [r12], #132
 *   @0x2fa61c mrc2 p7, #0x1, apsr_nzcv, c14, c14, #0x7
 *   @0x2fa620 strtmi r4, [r8], -r1, lsl #12
 *   @0x2fa624 stc2 p7, c15, [r9, #-944]!
 *   @0x2fa628 smlabteq r4, r4, r8, pc
 *   @0x2fa62c .word 0x0104f8d4
 *   @0x2fa630 ldrblt r11, [r8, #0xd38]!
 *   @0x2fa634 .word 0xf8d0460c
 *   @0x2fa638 ldrmi r5, [r7], -r4, lsl #3
 *   @0x2fa63c eorvs pc, r1, r5, asr r8
 *   @0x2fa640 .word 0xffcff7ff
 *   @0x2fa644 ldrtmi r4, [r8], -r1, lsl #12
 *   @0x2fa648 ldc2 p7, c15, [r5], #-936
 *   @0x2fa64c .word 0xf8454430
 *   @0x2fa650 ldcllt p0, c0, [r8, #144]!
 *   @0x2fa654 .word 0x460db570
 *   @0x2fa658 .word 0xf8d04616
 *   @0x2fa65c .word 0xf7ff4184
 *   @0x2fa660 strmi pc, [r1], -r0, asr #31
 *   @0x2fa664 .word 0xf7ea4630
 *   @0x2fa668 .word 0xf844fc26
 *   @0x2fa66c ldcllt p0, c0, [r0, #-148]!
 *   @0x2fa670 .word 0xf8d0b510
 *   @0x2fa674 .word 0xf8533184
 *   @0x2fa678 .word 0xf7ff4021
 *   @0x2fa67c .word 0x4601ffb2
 *   @0x2fa680 pop {r5, r9, r10, lr}
 *   @0x2fa684 .word 0xf7fe4010
 *   @0x2fa688 ldrlt r11, [r0, #-0xbc0]
 *   @0x2fa68c strhmi pc, [r0, -r0]
 *   @0x2fa690 .word 0xffa7f7ff
 *   @0x2fa694 strtmi r4, [r0], -r1, lsl #12
 *   @0x2fa698 ldrhmi lr, [r0], -sp
 *   @0x2fa69c bllt 0xff07869c <b2_toiTime+0xfffffffffe91f1f8>
 *   @0x2fa6a0 svcmi #0xf0e92d
 *   @0x2fa6a4 rfeia r0!
 *   @0x2fa6a8 addlt r8, r7, r0, lsr #32
 *   @0x2fa6ac .word 0xa0c4f8d0
 *   @0x2fa6b0 .word 0x60c8f8d0
 *   @0x2fa6b4 .word 0xf788fa0f
 *   @0x2fa6b8 stmdblt pc!, {r2, r6, r7, r11, sp, lr}
 *   @0x2fa6bc .word 0x73fef640
 *   @0x2fa6c0 stclvs p2, c4, [r1], #-636
 *   @0x2fa6c4 ands sp, r1, r8, lsl r12
 *   @0x2fa6c8 ldrhlo pc, [r4], -r4
 *   @0x2fa6cc ldrhths pc, [r8], -r4
 *   @0x2fa6d0 stmvs r3!, {r1, r3, r4, r10, lr}
 *   @0x2fa6d4 addsmi r4, r10, #973078528
 *   @0x2fa6d8 qsub8mi sp, r0, r0
 *   @0x2fa6dc ldrtmi r2, [r10], -r0, lsl #2
 *   @0x2fa6e0 ldc2 p7, c15, [r1, #-948]
 *   @0x2fa6e4 .word 0xf0402800
 *   @0x2fa6e8 strb r8, [r7, r7, lsr #2]!
 *   @0x2fa6ec subeq r1, r0, r8, ror r12
 *   @0x2fa6f0 movweq lr, #0xb0a
 *   @0x2fa6f4 andle r4, r1, #-536870903
 *   @0x2fa6f8 tst sp, r4, lsl r0
 *   @0x2fa6fc mulhs r0, r10, r8
 *   @0x2fa700 .word 0xf89a2f00
 *   @0x2fa704 b 0x13c6710 <b2_toiTime+0xc6d26c>
 *   @0x2fa708 svclt #0xc82202
 *   @0x2fa70c ldreq r8, [r3], #-10
 *   @0x2fa710 stmdalo r2, {r1, r4, r5, r6, r7, r10, r12, lr, pc}
 *   @0x2fa714 beq 0x3b6b44 <error_g0017+0xf7e8>
 *   @0x2fa718 strmi r1, [r8], #-3211
 *   @0x2fa71c andle r4, lr, #805306376
 *   @0x2fa720 blgt 0x3b8790 <error_g0017+0x11434>
 *   @0x2fa724 .word 0xf81ab212
 *   @0x2fa728 b 0x1341734 <b2_toiTime+0xbe8290>
 *   @0x2fa72c andshi r2, r9, r12, lsl #2
 *   @0x2fa730 stc2 p10, c15, [r1], {15}
 *   @0x2fa734 ldclle p5, c4, [pc, #592]
 *   @0x2fa738 strmi r3, [r10], -r2, lsl #6
 *   @0x2fa73c svchs #0xe7ee
 *   @0x2fa740 rfedb r3!
 *   @0x2fa744 strlo r7, [r1, -r2, lsl #24]
 *   @0x2fa748 ldrb sp, [r5, r1, lsl #10]
 *   @0x2fa74c rfeib r4!
 *   @0x2fa750 rfeib r4!
 *   @0x2fa754 ldrmi r2, [r10], #-22
 *   @0x2fa758 andlo r6, r4, #6488064
 *   @0x2fa75c addsmi r4, r10, #973078528
 *   @0x2fa760 stmvs r10!, {r0, r1, r3, r11, r12, lr, pc}
 *   @0x2fa764 .word 0xf10a2300
 *   @0x2fa768 ldrmi r0, [r3, #0xb02]!
 *   @0x2fa76c addlo pc, r12, r2, asr #17
 *   @0x2fa770 .word 0xf8c268aa
 *   @0x2fa774 ldmle pc!, {r3, r7, r12, sp}
 *   @0x2fa778 strtmi lr, [r0], -r8
 *   @0x2fa77c andhs r1, r0, #3648
 *   @0x2fa780 stc2l p7, c15, [r1], {237}
 *   @0x2fa784 .word 0xf0402800
 *   @0x2fa788 ubfx r8, r7, #0x1, #0xb
 *   @0x2fa78c mulls r0, r10, r8
 *   @0x2fa790 mullo r1, r10, r8
 *   @0x2fa794 stmdbhs r9, {r0, r1, r6, r9, r11, sp, lr, pc}
 *   @0x2fa798 ldreq r6, [r11, r11, lsr #18]
 *   @0x2fa79c bl 0xff5ef86c <b2_toiTime+0xfffffffffee963c8>
 *   @0x2fa7a0 strbmi r0, [r11, #-0x306]
 *   @0x2fa7a4 andshs sp, r6, r1, lsl #20
 *   @0x2fa7a8 .word 0xf8d5e0c6
 *   @0x2fa7ac stmdbge r6, {r2, r3, r4, r7, r12, sp}
 *   @0x2fa7b0 .word 0x2188f8d3
 *   @0x2fa7b4 stchs p8, c15, [r4, #-260]
 *   @0x2fa7b8 .word 0xf8cd2201
 *   @0x2fa7bc ldmvs r8, {r12, pc}
 *   @0x2fa7c0 bicvc pc, r6, #12582912
 *   @0x2fa7c4 ldc2 p7, c15, [pc, #1020]!
 *   @0x2fa7c8 ldrsblo pc, [r12], r5
 *   @0x2fa7cc ldrhhs pc, [r4], -sp
 *   @0x2fa7d0 orrhs pc, r8, r3, asr #17
 *   @0x2fa7d4 .word 0xf0402800
 *   @0x2fa7d8 stmvs r11!, {r0, r1, r2, r3, r5, r7, pc}
 *   @0x2fa7dc addls pc, r12, r3, asr #17
 *   @0x2fa7e0 ldrsbhs pc, [r12], r5
 *   @0x2fa7e4 .word 0xf8d268ab
 *   @0x2fa7e8 .word 0xf8c3218c
 *   @0x2fa7ec .word 0xf1b92088
 *   @0x2fa7f0 andle r0, r7, r0, lsl #30
 *   @0x2fa7f4 ldrsblo pc, [r12], r5
 *   @0x2fa7f8 .word 0x464a4659
 *   @0x2fa7fc .word 0x018cf8d3
 *   @0x2fa800 mrc p5, #0x6, apsr_nzcv, c12, c11, #0x5
 *   @0x2fa804 ldrbmi r6, [r9], #3107
 *   @0x2fa808 .word 0x0c07eb03
 *   @0x2fa80c .word 0x464b461a
 *   @0x2fa810 andsle r4, sp, #411041792
 *   @0x2fa814 adcsmi r1, r1, #22784
 *   @0x2fa818 svcge #0x6ef63f
 *   @0x2fa81c .word 0x0c01f811
 *   @0x2fa820 svceq #0x8f010
 *   @0x2fa824 bleq 0x378834 <_ZTS13C_UTF16String+0xf8e0>
 *   @0x2fa828 strmi sp, [r11], -r1, lsl #2
 *   @0x2fa82c .word 0xf103e7f0
 *   @0x2fa830 ldrmi r0, [r1, #0x902]!
 *   @0x2fa834 svcge #0x60f63f
 *   @0x2fa838 ldmdane r3, {r0, r3, r4, r6, r11, r12, sp, lr} ^
 *   @0x2fa83c .word 0xf63f4563
 *   @0x2fa840 stmdbhs r0, {r0, r1, r3, r4, r6, r8, r9, r10, r11, sp, pc}
 *   @0x2fa844 stmdblo r1, {r1, r5, r6, r7, r12, lr, pc}
 *   @0x2fa848 bleq 0x378858 <_ZTS13C_UTF16String+0xf904>
 *   @0x2fa84c ldrb r11, [r8, r9, asr #5]!
 *   @0x2fa850 blvs 0xffb4b324 <b2_toiTime+0xffffffffff3f1e80>
 *   @0x2fa854 .word 0xf63f6c22
 *   @0x2fa858 b 0x16e659c <b2_toiTime+0xf8d0f8>
 *   @0x2fa85c .word 0xf04f0ac7
 *   @0x2fa860 .word 0xf1020900
 *   @0x2fa864 bl 0x349c68
 *   @0x2fa868 andls r0, r3, #-1610612736
 *   @0x2fa86c addsmi r9, r1, #12288
 *   @0x2fa870 .word 0xf89cd229
 *   @0x2fa874 .word 0xf0000001
 *   @0x2fa878 .word 0xf0020202
 *   @0x2fa87c ldrshlt r0, [r2, #-191]
 *   @0x2fa880 adcsmi r1, r2, #23040
 *   @0x2fa884 svcge #0x38f63f
 *   @0x2fa888 mullt r0, r3, r8
 *   @0x2fa88c ldrle r0, [r1], #-1731
 *   @0x2fa890 bleq 0x336fc4
 *   @0x2fa894 strbeq lr, [r2], lr
 *   @0x2fa898 ldcne p4, c13, [r10], {11}
 *   @0x2fa89c .word 0xf63f42b2
 *   @0x2fa8a0 .word 0xf893af2b
 *   @0x2fa8a4 ldmdavc r11, {r12, sp, pc} ^
 *   @0x2fa8a8 blhs 0x5f51bc <g_SWFaavertbuff+0x220f4>
 *   @0x2fa8ac blx 0xfe5f90f2 <b2_toiTime+0xfffffffffde9fc4e>
 *   @0x2fa8b0 ldrmi lr, [r10], -r0
 *   @0x2fa8b4 .word 0xf02044d9
 *   @0x2fa8b8 .word 0xf8410012
 *   @0x2fa8bc ldrmi r9, [r3], -r8, lsl #22
 *   @0x2fa8c0 svceq #0x1f80c
 *   @0x2fa8c4 blvs 0xffbb4814 <b2_toiTime+0xffffffffff45b370>
 *   @0x2fa8c8 .word 0x0c00f04f
 *   @0x2fa8cc ldrmi r6, [r2], #3105
 *   @0x2fa8d0 ldmiblo pc!, {r0, r8, r12, sp, lr, pc} ^
 *   @0x2fa8d4 eorle r4, r9, #343932928
 *   @0x2fa8d8 muleq r1, r9, r8
 *   @0x2fa8dc .word 0x0104f000
 *   @0x2fa8e0 bleq 0x2f68ec <ps_hints_apply+0x54ec>
 *   @0x2fa8e4 mrrcne p1, #0x4, r11, r9, c9
 *   @0x2fa8e8 .word 0xf63f42b1
 *   @0x2fa8ec .word 0xf010af05
 *   @0x2fa8f0 ldmdavc r11, {r5, r8, r9, r10, r11}
 *   @0x2fa8f4 subsmi sp, r11, #16, #2
 *   @0x2fa8f8 streq lr, [r1], lr
 *   @0x2fa8fc ldcne p4, c13, [r9], {10}
 *   @0x2fa900 .word 0xf63f42b1
 *   @0x2fa904 .word 0xf893aef9
 *   @0x2fa908 ldmdavc r11, {r12, sp, pc} ^
 *   @0x2fa90c movwhs lr, #0xba43
 *   @0x2fa910 and r11, r1, r11, lsl r2
 *   @0x2fa914 uadd16mi r4, r11, r9
 *   @0x2fa918 .word 0xf000449c
 *   @0x2fa91c .word 0xf8c20001
 *   @0x2fa920 strmi r12, [r11], -r4
 *   @0x2fa924 svceq #0x1f809
 *   @0x2fa928 ldrb r3, [r3, r8, lsl #4]
 *   @0x2fa92c strbhi r2, [r7, -r0]!
 *   @0x2fa930 eorshi pc, r8, r4, lsr #17
 *   @0x2fa934 sbclo pc, r4, r5, asr #17
 *   @0x2fa938 pop {r0, r1, r2, r12, sp, pc}
 *   @0x2fa93c .word 0xf8d08ff0
 *   @0x2fa940 ldmdavs r8, {r2, r3, r4, r7, r12, sp}
 *   @0x2fa944 bllt 0xff438900 <b2_toiTime+0xfffffffffecdf45c>
 *   @0x2fa948 mvnsmi lr, sp, lsr #18
 *   @0x2fa94c stmdahs r0, {r2, r9, r10, lr}
 *   @0x2fa950 .word 0xf8d0d03f
 *   @0x2fa954 .word 0xf8d032a4
 *   @0x2fa958 cdpvs p0, #0x8, c8, c6, c4, #0x3
 *   @0x2fa95c andspl pc, r12, #208, #16
 *   @0x2fa960 .word 0xf8d0b113
 *   @0x2fa964 ldrmi r0, [r8, r0, lsr #5]
 *   @0x2fa968 stmvs r11!, {r0, r2, r4, r8, r12, sp, pc} ^
 *   @0x2fa96c ldrmi r4, [r8, r0, lsr #12]
 *   @0x2fa970 .word 0xf5046ea0
 *   @0x2fa974 .word 0xf7ed7136
 *   @0x2fa978 .word 0x6ea7fa48
 *   @0x2fa97c .word 0xf8c42500
 *   @0x2fa980 .word 0xf8d452d4
 *   @0x2fa984 ldmibvs r8!, {r2, r3, r5, r6, r7, r9, r12} ^
 *   @0x2fa988 ldc2l p7, c15, [r5], {236}
 *   @0x2fa98c .word 0xf5044638
 *   @0x2fa990 .word 0xf8c47137
 *   @0x2fa994 .word 0xf7ed52ec
 *   @0x2fa998 .word 0x4640fa38
 *   @0x2fa99c addsne pc, r8, #212, #16
 *   @0x2fa9a0 stc2l p7, c15, [r9], {236}
 *   @0x2fa9a4 .word 0xf5044630
 *   @0x2fa9a8 .word 0xf8c47122
 *   @0x2fa9ac .word 0xf8c45298
 *   @0x2fa9b0 .word 0xf7ed5294
 *   @0x2fa9b4 ldrtmi pc, [r0], -r10, lsr #20
 *   @0x2fa9b8 .word 0x7124f504
 *   @0x2fa9bc blx 0xc78978 <b2_toiTime+0x51f4d4>
 *   @0x2fa9c0 addpl pc, r4, #196, #16
 *   @0x2fa9c4 addpl pc, r12, #196, #16
 *   @0x2fa9c8 .word 0xf7ff4620
 *   @0x2fa9cc .word 0xf8c4fc2a
 *   @0x2fa9d0 pop {r3, r4, r5, r7, r9, r12, lr}
 *   @0x2fa9d4 strdeq r8, r9, [r0], -r0
 *   @0x2fa9d8 svcmi #0xf0e92d
 *   @0x2fa9dc .word 0xf8d04680
 *   @0x2fa9e0 ldrhlt r6, [r3], r8
 *   @0x2fa9e4 stmibvs pc, {r2, r3, r9, r10, lr} ^
 *   @0x2fa9e8 .word 0xf8d0b15e
 *   @0x2fa9ec swpblt r3, r8, [r3]
 *   @0x2fa9f0 andpl pc, r4, #208, #16
 *   @0x2fa9f4 stmibmi r4!, {r1, r5, r9, r10, lr}
 *   @0x2fa9f8 .word 0x47a8ab10
 *   @0x2fa9fc andls r4, pc, r5, lsl #12
 *   @0x2faa00 strhs r11, [r0, #-0x108]
 *   @0x2faa04 strtmi lr, [r0], -r6
 *   @0x2faa08 .word 0xf7ed9910
 *   @0x2faa0c strmi pc, [r1], r10, lsl #20
 *   @0x2faa10 tstlt r8, pc
 *   @0x2faa14 strls r9, [r5, #-0x50f]
 *   @0x2faa18 teq r11, r6, lsl #10
 *   @0x2faa1c strtmi r6, [r0], -r1, lsr #20
 *   @0x2faa20 .word 0x91076822
 *   @0x2faa24 .word 0xf7ec9208
 *   @0x2faa28 .word 0xf5b0f818
 *   @0x2faa2c andle r3, r7, r0, lsl #31
 *   @0x2faa30 eorsls pc, r12, sp, asr #17
 *   @0x2faa34 .word 0xf8cd464d
 *   @0x2faa38 .word 0xf8cd9014
 *   @0x2faa3c .word 0xe1269018
 *   @0x2faa40 andls pc, r0, sp, asr #17
 *   @0x2faa44 ldrtmi r10, [r8], -pc, lsl #26
 *   @0x2faa48 .word 0x21049501
 *   @0x2faa4c ldmdavs r3!, {r1, r3, r6, r9, r10, lr}
 *   @0x2faa50 blx 0xa78a0e <b2_toiTime+0x31f56a>
 *   @0x2faa54 ldrsbtlt pc, [r12], -sp
 *   @0x2faa58 .word 0xf1bb9006
 *   @0x2faa5c .word 0xf0400f00
 *   @0x2faa60 .word 0xf8cd810f
 *   @0x2faa64 ldrbmi r11, [r10], -r0
 *   @0x2faa68 ldrtmi r9, [r8], -r1, lsl #10
 *   @0x2faa6c ldmdavs r3!, {r2, r8, sp}
 *   @0x2faa70 blx 0x678a2e <g_SWFlinevertbuff+0x25966>
 *   @0x2faa74 andls r9, r5, pc, lsl #20
 *   @0x2faa78 .word 0xf0402a00
 *   @0x2faa7c stm sp, {r0, r1, r2, r8, pc}
 *   @0x2faa80 ldrtmi r0, [r8], -r4, lsr #32
 *   @0x2faa84 ldmdavs r3!, {r2, r8, sp}
 *   @0x2faa88 blx 0x378a46 <_ZTS13C_UTF16String+0xfaf2>
 *   @0x2faa8c ldrsbtge pc, [r12], -sp
 *   @0x2faa90 .word 0xf1ba4605
 *   @0x2faa94 .word 0xf0400f00
 *   @0x2faa98 qsub8mi r8, r0, r10
 *   @0x2faa9c .word 0xffa9f7eb
 *   @0x2faaa0 strtmi r4, [r0], -r1, lsl #13
 *   @0x2faaa4 .word 0xffa5f7eb
 *   @0x2faaa8 andeq pc, r11, #603979779
 *   @0x2faaac andls r11, r11, #536870921
 *   @0x2faab0 orreq lr, r2, r0, lsl #22
 *   @0x2faab4 addsmi r9, r1, #16, #20
 *   @0x2faab8 movwhs sp, #0x8902
 *   @0x2faabc rsc r9, r6, pc, lsl #6
 *   @0x2faac0 bge 0x760ee8 <b2_toiTime+0x7a44>
 *   @0x2faac4 .word 0xf8cd9b07
 *   @0x2faac8 bl 0xff362b50 <b2_toiTime+0xfffffffffec096ac>
 *   @0x2faacc andls r0, sp, #49152
 *   @0x2faad0 bleq 0x5756d8 <g_SWFlineaavertbuff+0x22610>
 *   @0x2faad4 stmdbls r11, {r3, r8, r9, r11, r12, pc}
 *   @0x2faad8 .word 0xf080428b
 *   @0x2faadc .word 0x462080d8
 *   @0x2faae0 .word 0xff87f7eb
 *   @0x2faae4 strtmi r9, [r0], -r10
 *   @0x2faae8 .word 0xff83f7eb
 *   @0x2faaec .word 0x43fff420
 *   @0x2faaf0 .word 0xf0234681
 *   @0x2faaf4 addslt r0, r11, #-67108863
 *   @0x2faaf8 .word 0xf04fb17b
 *   @0x2faafc ldmdavs r3!, {r9, r11}
 *   @0x2fab00 andsle r4, r11, #645922816
 *   @0x2fab04 .word 0xf7eb4620
 *   @0x2fab08 blls 0x4ba8e0 <SrcVerts+0x17924>
 *   @0x2fab0c addeq r11, r0, r0, lsl #4
 *   @0x2fab10 eoreq pc, r10, r3, asr #16
 *   @0x2fab14 beq 0x376f44 <_ZTS13C_UTF16String+0xdff0>
 *   @0x2fab18 .word 0xf410e7f1
 *   @0x2fab1c smlabble r2, r0, pc, r4
 *   @0x2fab20 strmi r9, [r11], #2314
 *   @0x2fab24 ldrmi lr, [r9], r8, lsr #1
 *   @0x2fab28 bl 0xff154bfc <b2_toiTime+0xfffffffffe9fb758>
 *   @0x2fab2c rscsle r0, r7, #268
 *   @0x2fab30 .word 0xf1094620
 *   @0x2fab34 .word 0xf7eb0901
 *   @0x2fab38 ubfx pc, r12, #0x1e, #0x16
 *   @0x2fab3c svcmi #0x80f419
 *   @0x2fab40 strls sp, [r0, #-0x109]
 *   @0x2fab44 .word 0x46494630
 *   @0x2fab48 blls 0x461368 <g_RomDisk+0x69b48>
 *   @0x2fab4c blx 0xfe57824a <b2_toiTime+0xfffffffffde1eda6>
 *   @0x2fab50 tstlt r0, #9
 *   @0x2fab54 .word 0xf04fe01e
 *   @0x2fab58 ldmdavs r3!, {r9, r11}
 *   @0x2fab5c andle r4, r10, #645922816
 *   @0x2fab60 .word 0xf7eb4620
 *   @0x2fab64 bls 0x47a884 <_ZN2VM13m_breakpointsE+0x650>
 *   @0x2fab68 addeq r11, r0, r0, lsl #4
 *   @0x2fab6c eoreq pc, r10, r2, asr #16
 *   @0x2fab70 beq 0x376fa0 <_ZTS13C_UTF16String+0xe04c>
 *   @0x2fab74 .word 0xf04fe7f1
 *   @0x2fab78 ldmdavs r3!, {r9, r11}
 *   @0x2fab7c rscle r4, r0, #645922816
 *   @0x2fab80 .word 0xf7eb4620
 *   @0x2fab84 andlt pc, r0, #54, #30
 *   @0x2fab88 .word 0xf8450080
 *   @0x2fab8c .word 0xf10a002a
 *   @0x2fab90 ldrb r0, [r2, r1, lsl #20]!
 *   @0x2fab94 svcpl #0xf419
 *   @0x2fab98 blls 0x5aefa8 <g_SWFlineaavertbuff+0x5bee0>
 *   @0x2fab9c mls r11, r11, r4, r4
 *   @0x2faba0 strtmi r6, [r0], -r3, lsr #16
 *   @0x2faba4 ldmdbls r0, {r1, r5, r9, r11, sp, lr}
 *   @0x2faba8 ldrbmi r1, [r11], #-2770
 *   @0x2fabac bge 0x75f3e4 <b2_toiTime+0x5f40>
 *   @0x2fabb0 .word 0xf5bd6223
 *   @0x2fabb4 bls 0x779a34 <b2_toiTime+0x20590>
 *   @0x2fabb8 pkhbtmi r9, r1, r0, lsl #18
 *   @0x2fabbc .word 0xf8d8b90a
 *   @0x2fabc0 qadd8mi r2, r0, r4
 *   @0x2fabc4 .word 0xfc19f5bd
 *   @0x2fabc8 .word 0xf1b99007
 *   @0x2fabcc .word 0xd1040f00
 *   @0x2fabd0 .word 0x46494638
 *   @0x2fabd4 blx 0xfeef8b8e <b2_toiTime+0xfffffffffe79f6ea>
 *   @0x2fabd8 bls 0x4f2cf0 <SrcVerts+0x4fd34>
 *   @0x2fabdc eorsle r2, lr, r0, lsl #20
 *   @0x2fabe0 svclo #0xfff1b9
 *   @0x2fabe4 .word 0xf04fd002
 *   @0x2fabe8 eors r0, r4, r0, lsl #20
 *   @0x2fabec stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2fabf0 addslo pc, r4, #216, #16
 *   @0x2fabf4 eorsle r4, r5, #641728512
 *   @0x2fabf8 addsge pc, r8, #216, #16
 *   @0x2fabfc stmdbls r9, {r0, r1, r2, r9, r11, r12, pc}
 *   @0x2fac00 andslo pc, r9, r10, lsr r8
 *   @0x2fac04 andseq pc, r9, r2, lsr r9
 *   @0x2fac08 .word 0xf7fe9302
 *   @0x2fac0c blls 0x3b900c <error_g0017+0x11cb0>
 *   @0x2fac10 .word 0xf82a4418
 *   @0x2fac14 .word 0xf1090019
 *   @0x2fac18 strb r0, [r9, r1, lsl #18]!
 *   @0x2fac1c andslo pc, r10, r9, lsr r8
 *   @0x2fac20 addshs pc, r4, #216, #16
 *   @0x2fac24 andsle r4, r4, #805306377
 *   @0x2fac28 addshs pc, r8, #216, #16
 *   @0x2fac2c rfeda r2!
 *   @0x2fac30 rfedb r1!
 *   @0x2fac34 stmdbls r9, {r1, r3, r4}
 *   @0x2fac38 movwls r9, #0x2203
 *   @0x2fac3c andsgt pc, r0, sp, asr #17
 *   @0x2fac40 .word 0xf8e3f7fe
 *   @0x2fac44 blls 0x3a1458 <af_arab_nonbase_uniranges+0x7c>
 *   @0x2fac48 ldrsbgt pc, [r0], -sp
 *   @0x2fac4c .word 0xf8224460
 *   @0x2fac50 cpsie none, #0x13
 *   @0x2fac54 blls 0x73d460 <g_SWFvertbuff+0x6a398>
 *   @0x2fac58 bicsle r4, pc, #645922816
 *   @0x2fac5c .word 0xf1b9e7b8
 *   @0x2fac60 ldrshle r3, [r5, pc]!
 *   @0x2fac64 ldrtmi r9, [r8], -r7, lsl #18
 *   @0x2fac68 blx 0x1c78c22 <b2_toiTime+0x151f77e>
 *   @0x2fac6c stmdavs r3!, {r1, r3, r9, r11, r12, pc}
 *   @0x2fac70 ldrmi r9, [r3], #2316
 *   @0x2fac74 eorvs r4, r3, #184549376
 *   @0x2fac78 andlo r9, r1, #8, #20
 *   @0x2fac7c str r9, [r9, -r8, lsl #4]!
 *   @0x2fac80 .word 0xf8cd464d
 *   @0x2fac84 and r9, r2, r4, lsl r0
 *   @0x2fac88 cmnvs r6, #-2147483620
 *   @0x2fac8c qsaxmi r4, r0, sp
 *   @0x2fac90 .word 0xf912f7ed
 *   @0x2fac94 stmdbls r6, {r3, r4, r5, r9, r10, lr}
 *   @0x2fac98 blx 0x1678c52 <b2_toiTime+0xf1f7ae>
 *   @0x2fac9c stmdbls r5, {r3, r4, r5, r9, r10, lr}
 *   @0x2faca0 blx 0x1578c5a <b2_toiTime+0xe1f7b6>
 *   @0x2faca4 qasxmi r4, r9, r8
 *   @0x2faca8 blx 0x1478c62 <b2_toiTime+0xd1f7be>
 *   @0x2facac andslt r9, r3, pc, lsl #16
 *   @0x2facb0 svchi #0xf0e8bd
 *   @0x2facb4 .word 0x460db5f0
 *   @0x2facb8 stmibvs pc, {r0, r2, r7, r12, sp, pc} ^
 *   @0x2facbc .word 0xf8d0462a
 *   @0x2facc0 stmdbmi r0!, {r2, r9, sp, lr}
 *   @0x2facc4 strmi r10, [r4], -r3, lsl #22
 *   @0x2facc8 .word 0x460247b0
 *   @0x2faccc teqlt r0, r2
 *   @0x2facd0 .word 0xf8c42300
 *   @0x2facd4 .word 0xf8c43294
 *   @0x2facd8 movwls r3, #0x2298
 *   @0x2facdc blls 0x3f2d9c <SVN_Lit_VertexShader+0x240>
 *   @0x2face0 andls r10, r0, r2, lsl #18
 *   @0x2face4 .word 0x91014638
 *   @0x2face8 ldmdaeq r11, {r1, r8, sp} ^
 *   @0x2facec addslo pc, r4, #196, #16
 *   @0x2facf0 .word 0xf9cdf7ed
 *   @0x2facf4 .word 0xf8c49b02
 *   @0x2facf8 ldmiblt r11!, {r3, r4, r7, r9} ^
 *   @0x2facfc addsne pc, r4, #212, #16
 *   @0x2fad00 subeq r4, r9, r8, lsr #12
 *   @0x2fad04 .word 0xf88df7ed
 *   @0x2fad08 ldmiblt r8!, {r1, r12, pc}
 *   @0x2fad0c addslo pc, r4, #212, #16
 *   @0x2fad10 addsvs pc, r8, #212, #16
 *   @0x2fad14 strbeq lr, [r3, -r6, lsl #22]
 *   @0x2fad18 .word 0x462842be
 *   @0x2fad1c .word 0xf7ebd204
 *   @0x2fad20 .word 0xf826fe68
 *   @0x2fad24 ldrb r0, [r7, r2, lsl #22]!
 *   @0x2fad28 .word 0xf8c6f7ed
 *   @0x2fad2c adcslo pc, r5, #148, #16
 *   @0x2fad30 strtmi r11, [r0], -r3, lsr #2
 *   @0x2fad34 .word 0xf7ff4629
 *   @0x2fad38 andls pc, r2, pc, asr #28
 *   @0x2fad3c andlt r9, r5, r2, lsl #16
 *   @0x2fad40 svclt #0xbdf0
 *   @0x2fad44 cmnvs r6, #32, #8
 *   @0x2fad48 svcmi #0xf0e92d
 *   @0x2fad4c cdpvs p0, #0x8, c11, c4, c7, #0x4
 *   @0x2fad50 .word 0xf8d02200
 *   @0x2fad54 blge 0x44f83c <g_RomDisk+0x5801c>
 *   @0x2fad58 andhs r9, r1, #4, #4
 *   @0x2fad5c ldrsbhi pc, [r12], -r4
 *   @0x2fad60 strtvc r4, [r10], -r9, asr #18
 *   @0x2fad64 .word 0xf8d04622
 *   @0x2fad68 ldrmi r6, [r0, r4, lsl #4]!
 *   @0x2fad6c stmdahs r0, {r2, r12, pc}
 *   @0x2fad70 addhi pc, r7, r0, asr #32
 *   @0x2fad74 stmdbls r5, {r5, r9, r10, lr}
 *   @0x2fad78 .word 0xf853f7ed
 *   @0x2fad7c andls r4, r4, r6, lsl #12
 *   @0x2fad80 cmnle lr, r0, lsl #16
 *   @0x2fad84 .word 0xf7eb4620
 *   @0x2fad88 strmi pc, [r7], -r8, ror #28
 *   @0x2fad8c .word 0xf7eb4620
 *   @0x2fad90 .word 0xf5b7fe64
 *   @0x2fad94 strmi r3, [r1], r0, lsl #31
 *   @0x2fad98 stmvs r11!, {r4, r5, r6, r8, r12, lr, pc} ^
 *   @0x2fad9c addsmi r6, r8, #1769472
 *   @0x2fada0 strls sp, [r0], -r12, ror #2
 *   @0x2fada4 beq 0x7371e0 <g_SWFvertbuff+0x64118>
 *   @0x2fada8 .word 0xf8cd4640
 *   @0x2fadac .word 0x2108a004
 *   @0x2fadb0 .word 0x464b4632
 *   @0x2fadb4 .word 0xf96bf7ed
 *   @0x2fadb8 mvnvs r9, r4, lsl #30
 *   @0x2fadbc cmple sp, r0, lsl #30
 *   @0x2fadc0 streq pc, [r8], -r0, lsl #2
 *   @0x2fadc4 ble 0x194c308 <b2_toiTime+0x11f2e64>
 *   @0x2fadc8 .word 0xf7eb4620
 *   @0x2fadcc .word 0xf826fe12
 *   @0x2fadd0 strmi r0, [r3], -r8, lsl #24
 *   @0x2fadd4 bl 0xfefa15f0 <b2_toiTime+0xfffffffffe84814c>
 *   @0x2fadd8 andle r0, r4, #128, #30
 *   @0x2faddc .word 0xf04f1e7e
 *   @0x2fade0 rscseq r0, pc, r0, lsl #18
 *   @0x2fade4 andhs lr, r0, #13
 *   @0x2fade8 stm sp, {r6, r9, r10, lr}
 *   @0x2fadec .word 0x21080404
 *   @0x2fadf0 .word 0xf94df7ed
 *   @0x2fadf4 .word 0x0c04f846
 *   @0x2fadf8 blhs 0x321a10
 *   @0x2fadfc ldrmi sp, [r11], lr, ror #3
 *   @0x2fae00 mcrhs p0, #0x0, lr, c0, c6, #0x0
 *   @0x2fae04 streq pc, [r8, -r7, lsr #3]
 *   @0x2fae08 stmibvs r11!, {r0, r1, r3, r8, r9, r11, r12, lr, pc} ^
 *   @0x2fae0c cdplo p6, #0x0, c4, c1, c0, #0x2
 *   @0x2fae10 ldmdavs r9, {r0, r1, r3, r4, r5, r10, lr} ^
 *   @0x2fae14 blx 0xfe6f8dcc <b2_toiTime+0xfffffffffdf9f928>
 *   @0x2fae18 ldrtmi r6, [r11], #-2539
 *   @0x2fae1c andls pc, r4, r3, asr #17
 *   @0x2fae20 strbmi lr, [r0], -pc, ror #15
 *   @0x2fae24 .word 0xf7ec69e9
 *   @0x2fae28 movwhs pc, #0xa86
 *   @0x2fae2c eor r6, r5, r11, ror #3
 *   @0x2fae30 .word 0x2c08f836
 *   @0x2fae34 ble 0xa8c488 <b2_toiTime+0x332fe4>
 *   @0x2fae38 .word 0x1c04f856
 *   @0x2fae3c b 0x16cc6c4 <b2_toiTime+0xf73220>
 *   @0x2fae40 .word 0xf8cd0ccb
 *   @0x2fae44 .word 0x9102c00c
 *   @0x2fae48 ldc2l p7, c15, [r3, #940]
 *   @0x2fae4c andlt r9, r0, #32768
 *   @0x2fae50 .word 0xf8410080
 *   @0x2fae54 .word 0xf8dd003b
 *   @0x2fae58 strtmi r12, [r0], -r12
 *   @0x2fae5c .word 0x2c04f856
 *   @0x2fae60 bleq 0x377294 <_ZTS13C_UTF16String+0xe340>
 *   @0x2fae64 andls r4, r3, #1644167168
 *   @0x2fae68 stc2l p7, c15, [r3, #940]
 *   @0x2fae6c andlt r9, r0, #12288
 *   @0x2fae70 subsvs r0, r0, r0, lsl #1
 *   @0x2fae74 .word 0x3701e7dc
 *   @0x2fae78 str r3, [r3, r8, lsl #12]!
 *   @0x2fae7c .word 0xf7ed4620
 *   @0x2fae80 andlt pc, r7, r11, lsl r8
 *   @0x2fae84 svchi #0xf0e8bd
 *   @0x2fae88 cmnvs r6, r2, ror r1
 *   @0x2fae8c svcmi #0xf0e92d
 *   @0x2fae90 cdpvs p0, #0x8, c11, c5, c11, #0x4
 *   @0x2fae94 .word 0xf8d04604
 *   @0x2fae98 andhs r6, r1, #184, #4
 *   @0x2fae9c blge 0x51f2b4 <SrcVerts+0x7c2f8>
 *   @0x2faea0 ldrsbls pc, [r12], -r5
 *   @0x2faea4 .word 0xf886b129
 *   @0x2faea8 ldmdbmi r6!, {r2, r3, r5, sp} ^
 *   @0x2faeac andvc pc, r4, #208, #16
 *   @0x2faeb0 .word 0xf886e004
 *   @0x2faeb4 ldmdbmi r4!, {r5, sp} ^
 *   @0x2faeb8 andvc pc, r4, #208, #16
 *   @0x2faebc ldrmi r4, [r8, r10, lsr #12]!
 *   @0x2faec0 blls 0x4deee4 <SrcVerts+0x3bf28>
 *   @0x2faec4 .word 0xf0402b00
 *   @0x2faec8 strtmi r8, [r8], -r5, asr #1
 *   @0x2faecc .word 0xf7ebaf07
 *   @0x2faed0 shasxmi pc, r9, r7
 *   @0x2faed4 strtmi r4, [r8], -r2, lsl #13
 *   @0x2faed8 cdp2 p7, #0x1, c15, c4, c11, #0x7
 *   @0x2faedc strmi r9, [r3], r7, lsl #22
 *   @0x2faee0 .word 0xf0402b00
 *   @0x2faee4 .word 0x462880b7
 *   @0x2faee8 .word 0xf7eb2102
 *   @0x2faeec andls pc, r7, r1, lsr #26
 *   @0x2faef0 .word 0xf0402800
 *   @0x2faef4 .word 0xf1bb80af
 *   @0x2faef8 andle r0, r1, r1, lsl #30
 *   @0x2faefc eors r2, r0, r8, lsl #6
 *   @0x2faf00 ldrtmi r4, [r9], -r8, lsr #12
 *   @0x2faf04 .word 0xff5ef7eb
 *   @0x2faf08 strmi r9, [r3], r7, lsl #22
 *   @0x2faf0c .word 0xf0402b00
 *   @0x2faf10 strtmi r8, [r8], -r1, lsr #1
 *   @0x2faf14 .word 0xf7eb4639
 *   @0x2faf18 blls 0x4fac74 <SrcVerts+0x57cb8>
 *   @0x2faf1c blhs 0x30c738 <af_shaper_get_elem+0x1fa6>
 *   @0x2faf20 addshi pc, r8, r0, asr #32
 *   @0x2faf24 strbmi r9, [r8], -r4, lsl #18
 *   @0x2faf28 shasxmi r11, r10, r1
 *   @0x2faf2c .word 0xf7ec2120
 *   @0x2faf30 .word 0x4607f8fa
 *   @0x2faf34 and r6, r5, r0, ror r3
 *   @0x2faf38 .word 0x2120463a
 *   @0x2faf3c .word 0xf8f3f7ec
 *   @0x2faf40 adcsvs r4, r0, #7340032
 *   @0x2faf44 blhs 0x321b68
 *   @0x2faf48 addhi pc, r4, r0, asr #32
 *   @0x2faf4c bl 0x5cc7d4 <g_SWFlineaavertbuff+0x7970c>
 *   @0x2faf50 ldrtmi r0, [r10], -r10, lsl #2
 *   @0x2faf54 blx 0xfeff8650 <b2_toiTime+0xfffffffffe89f1ac>
 *   @0x2faf58 stmdahs r0, {r0, r1, r2, r12, pc}
 *   @0x2faf5c ldmdblt r5, {r1, r3, r4, r5, r6, r8, r12, lr, pc}
 *   @0x2faf60 movwls r2, #0x7300
 *   @0x2faf64 .word 0xf8d4e076
 *   @0x2faf68 bl 0x45b110 <g_RomDisk+0x638f0>
 *   @0x2faf6c strbmi r0, [r0], -r10, lsl #2
 *   @0x2faf70 ldrsbls pc, [r12], -r8
 *   @0x2faf74 ldc2 p7, c15, [r7], {235}
 *   @0x2faf78 stmdahs r0, {r0, r3, r12, pc}
 *   @0x2faf7c stcge p1, c13, [r9, #-408]
 *   @0x2faf80 strtmi r4, [r9], -r0, asr #12
 *   @0x2faf84 ldc2 p7, c15, [lr, #940]!
 *   @0x2faf88 strmi r9, [r2], r9, lsl #22
 *   @0x2faf8c cmple sp, r0, lsl #22
 *   @0x2faf90 strtmi r4, [r9], -r0, asr #12
 *   @0x2faf94 ldc2 p7, c15, [r6, #940]!
 *   @0x2faf98 strmi r9, [r3], -r9, lsl #20
 *   @0x2faf9c bhs 0x313584 <af_shaper_get_elem+0x8df2>
 *   @0x2fafa0 .word 0xf02ad154
 *   @0x2fafa4 addslt r0, r2, #-268435453
 *   @0x2fafa8 .word 0xd14d2a00
 *   @0x2fafac smlabtne r1, r10, r3, pc
 *   @0x2fafb0 eoreq lr, r4, sp, lsl #17
 *   @0x2fafb4 strbmi r3, [r8], -r1, lsl #2
 *   @0x2fafb8 .word 0x21049105
 *   @0x2fafbc .word 0xf867f7ed
 *   @0x2fafc0 beq 0x6f6ff0 <g_SWFvertbuff+0x23f28>
 *   @0x2fafc4 beq 0x3773f4 <_ZTS13C_UTF16String+0xe4a0>
 *   @0x2fafc8 bleq 0x37710c <_ZTS13C_UTF16String+0xe1b8>
 *   @0x2fafcc blx 0x5e17f8 <g_SWFaavertbuff+0xe730>
 *   @0x2fafd0 .word 0xf10bfb0a
 *   @0x2fafd4 ldrshvs r3, [r8, #191]!
 *   @0x2fafd8 teqle r7, r0, lsl #20
 *   @0x2fafdc eoreq lr, r4, sp, lsl #17
 *   @0x2fafe0 ldmdbvs r11!, {r3, r6, r9, r10, lr} ^
 *   @0x2fafe4 .word 0xf7ed2104
 *   @0x2fafe8 blls 0x579138 <g_SWFlineaavertbuff+0x26070>
 *   @0x2fafec bllt 0x1dd36d4 <b2_toiTime+0x167a230>
 *   @0x2faff0 mul lr, r9, r6
 *   @0x2faff4 b 0x3d56e0 <error_g0017+0x2e384>
 *   @0x2faff8 .word 0xf841030b
 *   @0x2faffc tsteq r2, r9, lsr #32
 *   @0x2fb000 stmpl r10, {r0, r3, r4, r5, r6, r11, sp, lr}
 *   @0x2fb004 andsle r4, pc, #805306377
 *   @0x2fb008 .word 0xf84269fa
 *   @0x2fb00c .word 0xf1093029
 *   @0x2fb010 ldmdbvs r11!, {r0, r8, r11} ^
 *   @0x2fb014 andsle r4, r9, #641728512
 *   @0x2fb018 ldrmi r2, [r3], -r0, lsl #4
 *   @0x2fb01c strbmi r4, [r0], -r9, lsr #12
 *   @0x2fb020 movwls r9, #0x3202
 *   @0x2fb024 stc2l p7, c15, [r9, #-940]
 *   @0x2fb028 bls 0x3a1454 <af_arab_nonbase_uniranges+0x78>
 *   @0x2fb02c sbclt r9, r0, #3072
 *   @0x2fb030 stmdbls r5, {r0, r5, r6, r8, r11, r12, sp, pc}
 *   @0x2fb034 b 0x1307840 <b2_toiTime+0xbae39c>
 *   @0x2fb038 addmi r2, r10, #201326592
 *   @0x2fb03c ldmdavs r9!, {r1, r2, r3, r5, r6, r7, r8, r9, r12, lr, pc}
 *   @0x2fb040 vpmax.s8 d15, d10, d19
 *   @0x2fb044 bicsle r4, r5, #-1610612728
 *   @0x2fb048 movwls r2, #0x9308
 *   @0x2fb04c movwls r9, #0x7b09
 *   @0x2fb050 addle r2, r5, r0, lsl #22
 *   @0x2fb054 stmiblt r8, {r0, r1, r2, r11, r12, pc}
 *   @0x2fb058 movwhs r9, #0x1a04
 *   @0x2fb05c .word 0xf886b132
 *   @0x2fb060 .word 0xf8d4302d
 *   @0x2fb064 .word 0xf04332c0
 *   @0x2fb068 and r0, r5, r0, lsl r3
 *   @0x2fb06c eorlo pc, r1, r6, lsl #17
 *   @0x2fb070 sbclo pc, r0, #212, #16
 *   @0x2fb074 movweq pc, #0x2043
 *   @0x2fb078 sbclo pc, r0, #196, #16
 *   @0x2fb07c pop {r0, r1, r3, r12, sp, pc}
 *   @0x2fb080 svclt #0x8ff0
 *   @0x2fb084 usaxpl r4, r6, r2
 *   @0x2fb088 ldmdami r6, {r1, r4, r6, r8, lr} ^
 *   @0x2fb08c svcmi #0xf8e92d
 *   @0x2fb090 .word 0xf8d04606
 *   @0x2fb094 .word 0xf04f40c4
 *   @0x2fb098 .word 0xf8d00b00
 *   @0x2fb09c .word 0xf8d080c8
 *   @0x2fb0a0 .word 0xf10b900c
 *   @0x2fb0a4 strbmi r0, [r8], -r1, lsl #20
 *   @0x2fb0a8 .word 0xf7ed4651
 *   @0x2fb0ac strmi pc, [r7], -r3, ror #17
 *   @0x2fb0b0 .word 0xf0402800
 *   @0x2fb0b4 stcne p0, c8, [r0, #-748]!
 *   @0x2fb0b8 andle r4, r1, #128, #10
 *   @0x2fb0bc adcs r2, r5, r5, lsl r7
 *   @0x2fb0c0 ldrsbne pc, [r8], #-137
 *   @0x2fb0c4 blne 0x15f5a08 <b2_toiTime+0xe9c564>
 *   @0x2fb0c8 movweq lr, #0xbb01
 *   @0x2fb0cc ldrsbvs r6, [pc], pc
 *   @0x2fb0d0 stmdavc r2!, {r0, r2, r5, r11, r12, sp, lr} ^
 *   @0x2fb0d4 andhs lr, r5, #270336
 *   @0x2fb0d8 .word 0xf894809a
 *   @0x2fb0dc stmvc r5!, {r1, lr, pc} ^
 *   @0x2fb0e0 strhs lr, [r12, #-0xa45]
 *   @0x2fb0e4 .word 0x0c08f002
 *   @0x2fb0e8 andpl pc, r11, r1, asr #16
 *   @0x2fb0ec .word 0x0101f012
 *   @0x2fb0f0 stc2 p10, c15, [r12], {31}
 *   @0x2fb0f4 strhs r11, [r4, #-0xf14]
 *   @0x2fb0f8 .word 0xf1bc2502
 *   @0x2fb0fc andle r0, r1, r0, lsl #30
 *   @0x2fb100 and r3, r8, r2, lsl #10
 *   @0x2fb104 svceq #0x40f012
 *   @0x2fb108 strlo sp, [r4, #-0x1]
 *   @0x2fb10c .word 0xf012e003
 *   @0x2fb110 svclt #0x180f80
 *   @0x2fb114 strmi r3, [r5], #-1288
 *   @0x2fb118 bicle r4, pc, #168, #10
 *   @0x2fb11c ldrle r0, [r2, #-0x795]
 *   @0x2fb120 stmdbvc r0!, {r0, r3, r4, r6, r8, r12, sp, pc}
 *   @0x2fb124 b 0x13596b0 <b2_toiTime+0xc0020c>
 *   @0x2fb128 andlt r2, r9, #0, #2
 *   @0x2fb12c stmibvc r0!, {r0, r3, r4, r7, sp, lr}
 *   @0x2fb130 b 0x13598bc <b2_toiTime+0xc00418>
 *   @0x2fb134 andlt r2, r9, #0, #2
 *   @0x2fb138 .word 0xf994e00f
 *   @0x2fb13c addsvs r1, r9, r4
 *   @0x2fb140 mulne r5, r4, r9
 *   @0x2fb144 cmplt r9, pc
 *   @0x2fb148 stmdbvc r1!, {r5, r8, r11, r12, sp, lr} ^
 *   @0x2fb14c .word 0x2100ea41
 *   @0x2fb150 stmibvc r0!, {r0, r3, r4, r7, sp, lr}
 *   @0x2fb154 b 0x13598e0 <b2_toiTime+0xc0043c>
 *   @0x2fb158 sbcsvs r2, r9, r0, lsl #2
 *   @0x2fb15c and r3, r4, r8, lsl #8
 *   @0x2fb160 addsvs r7, r9, r1, lsr #18
 *   @0x2fb164 strlo r7, [r6], #-2401
 *   @0x2fb168 .word 0xf1bc60d9
 *   @0x2fb16c andle r0, r11, r0, lsl #30
 *   @0x2fb170 strlo r7, [r2], #-2080
 *   @0x2fb174 .word 0x1c01f814
 *   @0x2fb178 andhs lr, r0, r1, asr #20
 *   @0x2fb17c addeq r11, r0, r0, lsl #4
 *   @0x2fb180 strhs r4, [r0, #-0x601]
 *   @0x2fb184 eors r4, r12, lr, lsr #13
 *   @0x2fb188 ldrle r0, [r0, #-0x650]
 *   @0x2fb18c strlo r7, [r4], #-2080
 *   @0x2fb190 .word 0x1c03f814
 *   @0x2fb194 .word 0x5c02f814
 *   @0x2fb198 andhs lr, r0, r1, asr #20
 *   @0x2fb19c .word 0x1c01f814
 *   @0x2fb1a0 .word 0x2105ea41
 *   @0x2fb1a4 andlt r11, r9, #0, #4
 *   @0x2fb1a8 addeq r0, r9, r0, lsl #1
 *   @0x2fb1ac ldreq lr, [r1], -r9, ror #15
 *   @0x2fb1b0 stmdavc r0!, {r1, r5, r8, r10, r12, lr, pc}
 *   @0x2fb1b4 .word 0xf8143408
 *   @0x2fb1b8 .word 0xf8141c07
 *   @0x2fb1bc b 0x13521dc <b2_toiTime+0xbf8d38>
 *   @0x2fb1c0 .word 0xf8142000
 *   @0x2fb1c4 .word 0xf8141c05
 *   @0x2fb1c8 b 0x13761e0 <b2_toiTime+0xc1cd3c>
 *   @0x2fb1cc .word 0xf8142505
 *   @0x2fb1d0 .word 0xf8141c03
 *   @0x2fb1d4 andlt r12, r0, #512
 *   @0x2fb1d8 vmlshs.f32 s28, s28, s2
 *   @0x2fb1dc .word 0x1c01f814
 *   @0x2fb1e0 addeq r11, r0, sp, lsr #4
 *   @0x2fb1e4 .word 0x210cea41
 *   @0x2fb1e8 .word 0xfe8efa0f
 *   @0x2fb1ec andlt r0, r9, #173
 *   @0x2fb1f0 .word 0x0e8eea4f
 *   @0x2fb1f4 and r0, r4, r9, lsl #1
 *   @0x2fb1f8 orrlo pc, r0, pc, asr #8
 *   @0x2fb1fc strbtmi r4, [r6], r5, ror #12
 *   @0x2fb200 tstvs r8, r8, lsl #12
 *   @0x2fb204 ands pc, r4, r3, asr #17
 *   @0x2fb208 .word 0x61d9619d
 *   @0x2fb20c strle r0, [r1, #-0x693]
 *   @0x2fb210 .word 0xe74646d3
 *   @0x2fb214 subsge pc, r4, r9, asr #17
 *   @0x2fb218 .word 0xf7eb69b0
 *   @0x2fb21c .word 0xf8c6fb91
 *   @0x2fb220 strtmi r4, [r0], #-196
 *   @0x2fb224 andeq lr, r0, r8, asr #23
 *   @0x2fb228 adceq pc, r4, r6, asr #17
 *   @0x2fb22c pop {r3, r4, r5, r9, r10, lr}
 *   @0x2fb230 strdeq r8, r9, [r0], -r8
 *   @0x2fb234 sasxmi r11, r4, r8
 *   @0x2fb238 strmi r6, [r8], -r5, lsl #24
 *   @0x2fb23c ldrbtmi r4, [r9], #-2308
 *   @0x2fb240 ldmib r8, {r0, r1, r3, r4, r5, r7, r8, r10, r12, sp, lr, pc}
 *   @0x2fb244 eorvs r11, r5, r8, lsl #18
 *   @0x2fb248 andhs r11, r12, r8, lsr sp
 *   @0x2fb24c svclt #0xbd38
 *   @0x2fb250 muleq r9, r7, r9
 *   @0x2fb254 sadd16mi r11, r4, r3
 *   @0x2fb258 orrlt r11, r1, r0, lsl #18
 *   @0x2fb25c andeq lr, r3, sp, lsl #17
 *   @0x2fb260 .word 0xf7e94668
 *   @0x2fb264 blls 0x33aecc
 *   @0x2fb268 svclt #0xb82b00
 *   @0x2fb26c addsne r3, r11, r3, lsl #6
 *   @0x2fb270 blls 0x35b304
 *   @0x2fb274 svclt #0xb82b00
 *   @0x2fb278 addsne r3, r11, r3, lsl #6
 *   @0x2fb27c andhs r8, r0, r3, rrx
 *   @0x2fb280 ldclt p0, c11, [r0, #-8]
 *   @0x2fb284 rfeia r0!
 *   @0x2fb288 .word 0xf8905074
 *   @0x2fb28c addmi r4, sp, #116, #2
 *   @0x2fb290 rfeia r0!
 *   @0x2fb294 addsmi r5, r5, #80
 *   @0x2fb298 .word 0xf890d805
 *   @0x2fb29c tstlt r11, #1342177283
 *   @0x2fb2a0 sbcvs r2, r3, r6, lsl #7
 *   @0x2fb2a4 stcvs p0, c14, [r5, #128]
 *   @0x2fb2a8 bl 0x4571b0 <g_RomDisk+0x5f990>
 *   @0x2fb2ac bl 0x2fd1bc <TT_RunIns+0x3c8>
 *   @0x2fb2b0 .word 0xf85506c1
 *   @0x2fb2b4 .word 0xf8505032
 *   @0x2fb2b8 ldmdavs r2!, {r0, r4, r5} ^
 *   @0x2fb2bc bne 0xd154a8 <b2_toiTime+0x5bc004>
 *   @0x2fb2c0 smlabteq r1, r2, r11, lr
 *   @0x2fb2c4 stmdbhs r0, {r1, r2, r8, r12, lr, pc}
 *   @0x2fb2c8 strhs r11, [r0], #-3848
 *   @0x2fb2cc andhs r11, r0, r4, lsl pc
 *   @0x2fb2d0 addmi pc, r0, pc, asr #8
 *   @0x2fb2d4 strle r0, [r2, #-0x7e2]
 *   @0x2fb2d8 strmi r4, [r1], -r10, asr #4
 *   @0x2fb2dc sadd16mi r4, r10, r0
 *   @0x2fb2e0 .word 0xffb8f7ff
 *   @0x2fb2e4 ldcllt p0, c2, [r8, #0]!
 *   @0x2fb2e8 ldcllt p0, c2, [r8, #4]!
 *   @0x2fb2ec .word 0x43f8e92d
 *   @0x2fb2f0 rfeia r0!
 *   @0x2fb2f4 stmdahi pc, {r4, r6, r12, sp}
 *   @0x2fb2f8 .word 0x5174f890
 *   @0x2fb2fc stmdavs lr, {r0, r1, r3, r4, r5, r7, r9, lr} ^
 *   @0x2fb300 rfeia r0!
 *   @0x2fb304 adcslt r3, r6, #116
 *   @0x2fb308 stmdale r7, {r0, r1, r4, r5, r7, r9, lr}
 *   @0x2fb30c eorslo pc, r5, #148, #16
 *   @0x2fb310 suble r2, sp, r0, lsl #22
 *   @0x2fb314 rscvs r2, r3, r6, lsl #7
 *   @0x2fb318 .word 0x83f8e8bd
 *   @0x2fb31c b 0x16d682c <b2_toiTime+0xf7d388>
 *   @0x2fb320 svcvs #0x8309c7
 *   @0x2fb324 stmeq r6, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^
 *   @0x2fb328 .word 0x0109eb02
 *   @0x2fb32c vmlaeq.f64 d14, d8, d3
 *   @0x2fb330 eorseq pc, r7, r2, asr r8
 *   @0x2fb334 eorslo pc, r6, r3, asr r8
 *   @0x2fb338 .word 0xf8de6849
 *   @0x2fb33c bne 0xff303354 <b2_toiTime+0xfffffffffeba9eb0>
 *   @0x2fb340 smlabteq r1, r2, r11, lr
 *   @0x2fb344 stmdbhs r0, {r1, r2, r8, r12, lr, pc}
 *   @0x2fb348 strhs r11, [r0, #-0xf08]
 *   @0x2fb34c andhs r11, r0, r4, lsl pc
 *   @0x2fb350 addmi pc, r0, pc, asr #8
 *   @0x2fb354 strle r0, [r2, #-0x7ea]
 *   @0x2fb358 strmi r4, [r1], -r11, asr #4
 *   @0x2fb35c .word 0xf5044618
 *   @0x2fb360 .word 0xf7ff7293
 *   @0x2fb364 stcvs p15, c15, [r2, #476]!
 *   @0x2fb368 bl 0x3972fc <ft_adobe_glyph_list+0x69d8>
 *   @0x2fb36c ldrmi r0, [r8], #265
 *   @0x2fb370 eorseq pc, r7, r2, asr r8
 *   @0x2fb374 eorslo pc, r6, r3, asr r8
 *   @0x2fb378 .word 0xf8d86849
 *   @0x2fb37c bne 0xff303394 <b2_toiTime+0xfffffffffeba9ef0>
 *   @0x2fb380 smlabteq r1, r2, r11, lr
 *   @0x2fb384 stmdbhs r0, {r1, r2, r8, r12, lr, pc}
 *   @0x2fb388 strhs r11, [r0, #-0xf08]
 *   @0x2fb38c andhs r11, r0, r4, lsl pc
 *   @0x2fb390 addmi pc, r0, pc, asr #8
 *   @0x2fb394 strle r0, [r2, #-0x7eb]
 *   @0x2fb398 strmi r4, [r1], -r11, asr #4
 *   @0x2fb39c .word 0xf5044618
 *   @0x2fb3a0 .word 0xf7ff7295
 *   @0x2fb3a4 qsaxmi pc, r0, r7
 *   @0x2fb3a8 .word 0x43f8e8bd
 *   @0x2fb3ac ldmdalt r8, {r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r12, sp, lr, pc} ^
 *   @0x2fb3b0 .word 0x83f8e8bd
 *   @0x2fb3b4 .word 0xf8d0b530
 *   @0x2fb3b8 .word 0x9c0352b8
 *   @0x2fb3bc smlabblt r9, sp, r1, r11
 *   @0x2fb3c0 andvs r6, sp, sp, lsr #16
 *   @0x2fb3c4 .word 0xf8d0b11a
 *   @0x2fb3c8 stmdavs r9, {r3, r4, r5, r7, r9, r12} ^
 *   @0x2fb3cc tstlt r11, r1, lsl r0
 *   @0x2fb3d0 adcshs pc, r8, #208, #16
 *   @0x2fb3d4 mulsvs r10, r2, r8
 *   @0x2fb3d8 .word 0xf8d0b15c
 *   @0x2fb3dc ldmvs r11, {r3, r4, r5, r7, r9, r12, sp} ^
 *   @0x2fb3e0 mrslt lr, apsr
 *   @0x2fb3e4 .word 0xb10a600d
 *   @0x2fb3e8 andsvs r2, r3, r0, lsl #6
 *   @0x2fb3ec movwhs r11, #0x10c
 *   @0x2fb3f0 andhs r6, r0, r3, lsr #32
 *   @0x2fb3f4 mcrne p13, #0x2, r11, c11, c0, #0x1
 *   @0x2fb3f8 ldrlt r2, [r0, #-0xb02]!
 *   @0x2fb3fc orrhs sp, r4, #16384
 *   @0x2fb400 .word 0xf101e00c
 *   @0x2fb404 bl 0x2fc4e8 <ps_hints_apply+0xb0e8>
 *   @0x2fb408 .word 0xf85003c4
 *   @0x2fb40c stmdblt r12, {r2, r4, r5, lr}
 *   @0x2fb410 and r2, r3, r10, lsl #7
 *   @0x2fb414 adcmi r6, r10, #6094848
 *   @0x2fb418 orrhs sp, r3, #3, #26
 *   @0x2fb41c andhs r6, r1, r3, asr #1
 *   @0x2fb420 .word 0xf8c0bd30
 *   @0x2fb424 ldmdavs r11, {r3, r5, r6, r8, lr} ^
 *   @0x2fb428 smulbths r12, r0, r8
 *   @0x2fb42c smulbtne r4, r0, r8
 *   @0x2fb430 cmnlo r0, r0, asr #17
 *   @0x2fb434 ldclt p0, c2, [r0, #-0]!
 *   @0x2fb438 .word 0x4604b570
 *   @0x2fb43c .word 0x31a8f8d0
 *   @0x2fb440 stmdavs r10, {r0, r2, r3, r9, r10, lr} ^
 *   @0x2fb444 addsmi r3, r10, #67108864
 *   @0x2fb448 .word 0xf8d0d24d
 *   @0x2fb44c .word 0xf8d01198
 *   @0x2fb450 addmi r0, r3, #144, #2
 *   @0x2fb454 tsths r8, #1073741825
 *   @0x2fb458 movwne pc, #0x2b03
 *   @0x2fb45c addsmi r6, r6, #14548992
 *   @0x2fb460 tsths r8, #13
 *   @0x2fb464 andne pc, r0, r3, lsl #22
 *   @0x2fb468 addmi r4, r3, #11534336
 *   @0x2fb46c addmi sp, r3, #134217728
 *   @0x2fb470 eors sp, r8, r5, lsl #2
 *   @0x2fb474 addsmi r6, r1, #14221312
 *   @0x2fb478 tstlo r8, #249
 *   @0x2fb47c .word 0x7c1ae7f5
 *   @0x2fb480 .word 0xf8d4b38a
 *   @0x2fb484 .word 0xf8d421b0
 *   @0x2fb488 addmi r1, r10, #180, #2
 *   @0x2fb48c orrhs sp, r2, #1024
 *   @0x2fb490 stmdavs r9!, {r1, r3, r5, sp, lr, pc}
 *   @0x2fb494 stcle p9, c2, [r8, #-0]!
 *   @0x2fb498 ldrsbeq pc, [r8, r4]!
 *   @0x2fb49c .word 0xf8d40111
 *   @0x2fb4a0 stmdane r2, {r2, r5, r6, r8, sp, lr} ^
 *   @0x2fb4a4 strtmi r5, [r0], -r6, asr #32
 *   @0x2fb4a8 .word 0x116cf8d4
 *   @0x2fb4ac subsvs r3, r1, r1, lsl #2
 *   @0x2fb4b0 sbcsvs r6, r3, r9, lsr #16
 *   @0x2fb4b4 .word 0xf8d46091
 *   @0x2fb4b8 andlo r2, r1, #176, #2
 *   @0x2fb4bc asrshs pc, r4, #17
 *   @0x2fb4c0 muleq r6, r3, r8
 *   @0x2fb4c4 .word 0xff97f7ff
 *   @0x2fb4c8 .word 0xf8842300
 *   @0x2fb4cc .word 0xf8d4317c
 *   @0x2fb4d0 stmdavs r10!, {r2, r3, r5, r6, r9, r12, sp}
 *   @0x2fb4d4 .word 0xf8d44413
 *   @0x2fb4d8 .word 0xf8c42270
 *   @0x2fb4dc addsmi r3, r3, #108, #4
 *   @0x2fb4e0 orrhs sp, r11, #49152
 *   @0x2fb4e4 orrhs lr, r6, #0
 *   @0x2fb4e8 ldcllt p0, c6, [r0, #-908]!
 *   @0x2fb4ec tsths r8, r8, lsr r5
 *   @0x2fb4f0 .word 0x31a4f8d0
 *   @0x2fb4f4 .word 0xf8d04604
 *   @0x2fb4f8 blx 0x343b72
 *   @0x2fb4fc addsmi r3, r3, #536870912
 *   @0x2fb500 .word 0xf894d22a
 *   @0x2fb504 blvc 0x93badc <b2_toiTime+0x1e2638>
 *   @0x2fb508 smlawble r3, r8, r2, r4
 *   @0x2fb50c movwlt r7, #0x9c19
 *   @0x2fb510 ldrsbhs pc, [r0, r4]!
 *   @0x2fb514 ldrsbne pc, [r4, r4]!
 *   @0x2fb518 blle 0x34bf48
 *   @0x2fb51c ands r2, r12, r2, lsl #7
 *   @0x2fb520 ldrsbeq pc, [r8, r4]!
 *   @0x2fb524 .word 0xf8d41c51
 *   @0x2fb528 tsteq r2, r4, ror #2
 *   @0x2fb52c asrsne pc, r4, #17
 *   @0x2fb530 addpl r1, r5, r1, lsl #17
 *   @0x2fb534 .word 0xf8d44620
 *   @0x2fb538 sbcvs r2, r11, r12, ror #2
 *   @0x2fb53c subvs r3, r10, r1, lsl #4
 *   @0x2fb540 addvs r2, r10, r1, lsl #4
 *   @0x2fb544 muleq r6, r3, r8
 *   @0x2fb548 .word 0xff55f7ff
 *   @0x2fb54c .word 0xf8842300
 *   @0x2fb550 ldclt p1, c3, [r8, #-496]!
 *   @0x2fb554 bfi r3, r8, #6, #13
 *   @0x2fb558 rscvs r2, r3, r0, lsl #7
 *   @0x2fb55c stmdbhs r0, {r3, r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x2fb560 stmne r8, {r1, r2, r8, r9, r11, r12, lr, pc}
 *   @0x2fb564 .word 0xf0203020
 *   @0x2fb568 b 0xafb66c <b2_toiTime+0x3a21c8>
 *   @0x2fb56c ldrbmi r7, [r0, -r0, ror #1]!
 *   @0x2fb570 eorlo r1, r0, r0, asr r10
 *   @0x2fb574 eorseq pc, pc, r0, lsr #32
 *   @0x2fb578 b 0x30be80 <af_shaper_get_elem+0x16ee>
 *   @0x2fb57c ldrbmi r7, [r0, -r0, ror #1]!
 *   @0x2fb580 blle 0x485988 <mstack+0xc9c>
 *   @0x2fb584 .word 0xf0201888
 *   @0x2fb588 eorlo r0, r0, pc, lsr r0
 *   @0x2fb58c eorhs r11, r0, r8, asr #30
 *   @0x2fb590 bne 0x178d358 <b2_toiTime+0x1033eb4>
 *   @0x2fb594 andseq pc, pc, pc, rrx
 *   @0x2fb598 eorseq pc, pc, #34
 *   @0x2fb59c stmdahs r0, {r7, r9, r11, r12}
 *   @0x2fb5a0 .word 0xf06fbfc8
 *   @0x2fb5a4 .word 0x4770001f
 *   @0x2fb5a8 blle 0x4459b0 <g_RomDisk+0x4e190>
 *   @0x2fb5ac .word 0xf0201888
 *   @0x2fb5b0 b 0xafb6b4 <b2_toiTime+0x3a2210>
 *   @0x2fb5b4 ldrbmi r7, [r0, -r0, ror #1]!
 *   @0x2fb5b8 .word 0xf0201a50
 *   @0x2fb5bc submi r0, r0, #63
 *   @0x2fb5c0 rscvc lr, r0, r0, lsl #20
 *   @0x2fb5c4 stmdbhs r0, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2fb5c8 stmne r8, {r1, r2, r8, r9, r11, r12, lr, pc}
 *   @0x2fb5cc .word 0xf020303f
 *   @0x2fb5d0 b 0xafb6d4 <b2_toiTime+0x3a2230>
 *   @0x2fb5d4 ldrbmi r7, [r0, -r0, ror #1]!
 *   @0x2fb5d8 eorslo r1, pc, r0, asr r10
 *   @0x2fb5dc eorseq pc, pc, r0, lsr #32
 *   @0x2fb5e0 b 0x30bee8 <af_shaper_get_elem+0x1756>
 *   @0x2fb5e4 ldrbmi r7, [r0, -r0, ror #1]!
 *   @0x2fb5e8 blle 0x4859f0 <g_States+0x28>
 *   @0x2fb5ec andslo r1, r0, r8, lsl #17
 *   @0x2fb5f0 andseq pc, pc, r0, lsr #32
 *   @0x2fb5f4 rscvc lr, r0, r0, lsr #20
 *   @0x2fb5f8 bne 0x170d3c0 <b2_toiTime+0xfb3f1c>
 *   @0x2fb5fc .word 0xf0203010
 *   @0x2fb600 submi r0, r0, #31
 *   @0x2fb604 rscvc lr, r0, r0, lsl #20
 *   @0x2fb608 stmdbhs r0, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2fb60c .word 0xf8d0b530
 *   @0x2fb610 .word 0xf8d031e4
 *   @0x2fb614 .word 0xf8d051e8
 *   @0x2fb618 blle 0x54bda0 <gp_ActiveMaskObjects+0x70d8>
 *   @0x2fb61c rsbmi r1, r4, #823296
 *   @0x2fb620 strtmi r4, [r10], #-1037
 *   @0x2fb624 ldmne r2, {r1, r5, lr} ^
 *   @0x2fb628 ldrmi r11, [r8], -r12, asr #30
 *   @0x2fb62c ldclt p6, c4, [r0, #-64]!
 *   @0x2fb630 rsbmi r1, r4, #232, #20
 *   @0x2fb634 ldrmi r1, [r0], #-2624
 *   @0x2fb638 submi r4, r0, #32
 *   @0x2fb63c stmdahs r0, {r6, r7, r9, r11, r12}
 *   @0x2fb640 subsmi r11, r8, #200, #30
 *   @0x2fb644 stmdbhs r0, {r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x2fb648 .word 0xf8d0b538
 *   @0x2fb64c .word 0xf8d041e4
 *   @0x2fb650 .word 0xf8d051e0
 *   @0x2fb654 blle 0x607dfc <g_SWFaavertbuff+0x34d34>
 *   @0x2fb658 stmne r8, {r0, r3, r8, r9, r11, r12} ^
 *   @0x2fb65c ldrmi r4, [r0], #-1577
 *   @0x2fb660 bl 0x18b76dc <b2_toiTime+0x115e238>
 *   @0x2fb664 andmi pc, r0, r5, lsl #22
 *   @0x2fb668 eoreq lr, r0, r0, lsr r10
 *   @0x2fb66c strtmi r11, [r0], -r8, lsr #30
 *   @0x2fb670 blne 0x9eab58 <b2_toiTime+0x2916b4>
 *   @0x2fb674 qsaxmi r1, r9, r8
 *   @0x2fb678 .word 0xf01d4410
 *   @0x2fb67c .word 0x4368eb4a
 *   @0x2fb680 blne 0x30bf88 <af_shaper_get_elem+0x17f6>
 *   @0x2fb684 svclt #0xc82800
 *
 * ══ §2/13 anon_30754c  0x30754c  size 4724  1181 条（0x30754c..0x3087c0）
 * @func 0x30754c 0x3087c0  size 4724  1181 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x52b590 / 0x686b60 / 0x1b141e8 / 0x66c214 / 0x4607e0 / 0x349f1e / 0x50d7a8 / 0xff318084
 * 字段偏移 top8: 0x6×4 / 0xa×2 / 0x5×1 / 0x18×1 / 0xc×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x30754c andeq r4, r0, r0, ror r7
 *   @0x307550 svcmi #0xf0e92d
 *   @0x307554 stmvs r3!, {r2, r9, r10, lr}
 *   @0x307558 stmdavs r0, {r0, r1, r2, r3, r7, r12, sp, pc} ^
 *   @0x30755c .word 0x2100460f
 *   @0x307560 movwls r6, #0x81a1
 *   @0x307564 rscvs r6, r1, #268435462
 *   @0x307568 .word 0xf8c463a1
 *   @0x30756c .word 0xf8c41570
 *   @0x307570 rfeib r7!
 *   @0x307574 stmvs r2!, {r12, sp} ^
 *   @0x307578 blhs 0x52b590 <SrcVerts+0x885d4>
 *   @0x30757c andls r6, r5, #32, #18
 *   @0x307580 andls r9, r9, sp, lsl #2
 *   @0x307584 bvs 0xba1620 <b2_toiTime+0x44817c>
 *   @0x307588 bvs 0xfebfd5ac <b2_toiTime+0xfffffffffe4a4108>
 *   @0x30758c .word 0xf604bb0b
 *   @0x307590 adcvs r2, r3, #200, #6
 *   @0x307594 eorvs r2, r3, #8, #6
 *   @0x307598 addsmi lr, r3, #27
 *   @0x30759c bvs 0xfeb3da08 <b2_toiTime+0xfffffffffe3e4564>
 *   @0x3075a0 strbhs pc, [r8], r4, lsl #12
 *   @0x3075a4 adcsmi r3, r0, #201326592
 *   @0x3075a8 streq pc, [r3], -r3, lsr #32
 *   @0x3075ac adcvs r11, r1, #8, #30
 *   @0x3075b0 bvs 0xfebd8e58 <b2_toiTime+0xfffffffffe47f9b4>
 *   @0x3075b4 movwls r2, #0x104
 *   @0x3075b8 movwls r10, #0x1b0d
 *   @0x3075bc .word 0xf7e04633
 *   @0x3075c0 blls 0x686b60 <g_SWFlinevertbuff+0x33a98>
 *   @0x3075c4 tstlt r11, r0, lsr #5
 *   @0x3075c8 andlt r9, pc, sp, lsl #16
 *   @0x3075cc svchi #0xf0e8bd
 *   @0x3075d0 rfeib r7!
 *   @0x3075d4 stmdbvs r2!, {r1, r12, sp} ^
 *   @0x3075d8 blhs 0x1b141e8 <b2_toiTime+0x13bad44>
 *   @0x3075dc stmibvs r3!, {r0, r1, r2, r11, r12, lr, pc} ^
 *   @0x3075e0 .word 0xf604b9fb
 *   @0x3075e4 mvnvs r2, r8, ror #7
 *   @0x3075e8 .word 0x61632360
 *   @0x3075ec addsmi lr, r3, #25
 *   @0x3075f0 stmibvs r1!, {r0, r1, r2, r4, r8, r11, r12, lr, pc} ^
 *   @0x3075f4 rschs pc, r8, r4, lsl #12
 *   @0x3075f8 addmi r3, r1, #603979776
 *   @0x3075fc streq pc, [r7], -r3, lsr #32
 *   @0x307600 svclt #0x44628
 *   @0x307604 mvnvs r2, r0, lsl #2
 *   @0x307608 smulwths r8, r3, r9
 *   @0x30760c blge 0x66c214 <g_SWFlinevertbuff+0x1914c>
 *   @0x307610 ldrtmi r9, [r3], -r1, lsl #6
 *   @0x307614 ldc2 p7, c15, [r11, #-896]!
 *   @0x307618 mvnvs r9, sp, lsl #22
 *   @0x30761c bicsle r2, r3, r0, lsl #22
 *   @0x307620 rfeib r7!
 *   @0x307624 ldrtmi r3, [r8], -r2
 *   @0x307628 rfeib r7!
 *   @0x30762c rsbvs r3, r3, #0
 *   @0x307630 strbtvs r2, [r3], #-770
 *   @0x307634 .word 0x33fff04f
 *   @0x307638 strlo pc, [r8, #0x8c4]
 *   @0x30763c .word 0xffb2f7de
 *   @0x307640 .word 0xd1042801
 *   @0x307644 movweq pc, #0x106f
 *   @0x307648 streq pc, [r8, #0x8c4]
 *   @0x30764c bls 0x4607e0 <g_RomDisk+0x68fc0>
 *   @0x307650 stmdbls r4, {r3, r8, r9, r11, r12, pc}
 *   @0x307654 rscvs r9, r2, r9, lsl #16
 *   @0x307658 adcvs r6, r3, r2, lsr #19
 *   @0x30765c rsbvs r2, r1, r0, lsl #6
 *   @0x307660 .word 0xf8c46120
 *   @0x307664 .word 0xf8c43ac0
 *   @0x307668 stmibvs r5!, {r2, r6, r7, r9, r11, r12, sp} ^
 *   @0x30766c adcle r2, r11, r0, lsl #20
 *   @0x307670 .word 0xf1052128
 *   @0x307674 blx 0x349f1e
 *   @0x307678 .word 0xf8d45102
 *   @0x30767c .word 0x46562abc
 *   @0x307680 eorge pc, r12, sp, asr #17
 *   @0x307684 qaddls r6, r2, r6
 *   @0x307688 rfeia r2!
 *   @0x30768c movtmi r2, #0xa044
 *   @0x307690 andls r0, r7, #860160
 *   @0x307694 ldmdahi r2, {r1, r3, r4, r5, r6, r7, r11, sp, lr}
 *   @0x307698 b 0x16f3ee4 <b2_toiTime+0xf9aa40>
 *   @0x30769c bl 0x50d7a8 <SrcVerts+0x6a7ec>
 *   @0x3076a0 ldmdavs r9!, {r0, r6, r7, r11} ^
 *   @0x3076a4 .word 0xf10144a8
 *   @0x3076a8 ldmvs r9!, {r3, r8, r9, r11}
 *   @0x3076ac stmdblo r1, {r0, r6, r7, r9, r10, lr}
 *   @0x3076b0 stmdbls r6, {r1, r3, r8, r12, pc}
 *   @0x3076b4 beq 0xd43d54 <b2_toiTime+0x5ea8b0>
 *   @0x3076b8 rsbsle r4, r9, #578813952
 *   @0x3076bc andeq pc, r4, pc, asr #32
 *   @0x3076c0 stceq p8, c15, [r6], #-24
 *   @0x3076c4 stceq p8, c15, [r5], #-24
 *   @0x3076c8 .word 0x1c08f85b
 *   @0x3076cc .word 0x1c1cf826
 *   @0x3076d0 .word 0x1c04f85b
 *   @0x3076d4 .word 0x1c1af826
 *   @0x3076d8 .word 0xf85b9904
 *   @0x3076dc andls r0, r3, #8, #24
 *   @0x3076e0 .word 0xf7ff9302
 *   @0x3076e4 stmdbls r8, {r0, r1, r5, r6, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x3076e8 stmdbls r5, {r3, r10, lr}
 *   @0x3076ec .word 0x0c18f846
 *   @0x3076f0 stceq p8, c15, [r4], #-280
 *   @0x3076f4 .word 0x0c04f85b
 *   @0x3076f8 ldc2l p7, c15, [r8, #1020]
 *   @0x3076fc strmi r9, [r8], #-2313
 *   @0x307700 .word 0x0c14f846
 *   @0x307704 stceq p8, c15, [r0], #-280
 *   @0x307708 ldmdavs r8!, {r0, r1, r9, r11, r12, pc} ^
 *   @0x30770c .word 0xf850b211
 *   @0x307710 .word 0xf8a80031
 *   @0x307714 ldmdavs r8!, {r2, r3} ^
 *   @0x307718 biceq lr, r1, r0, lsl #22
 *   @0x30771c stmdavs r9, {r1, r3, r11, r12, pc} ^
 *   @0x307720 andne pc, lr, r8, lsr #17
 *   @0x307724 svcne #0x1f810
 *   @0x307728 .word 0xf0119b02
 *   @0x30772c andls r0, r10, r3, lsl #2
 *   @0x307730 stmdbhs r2, {r0, r1, r12, lr, pc}
 *   @0x307734 .word 0x2100bf18
 *   @0x307738 .word 0xf04fe001
 *   @0x30773c .word 0xf8260101
 *   @0x307740 rfedb r6!
 *   @0x307744 rfeib r9!
 *   @0x307748 rfedb r6!
 *   @0x30774c bne 0x137a7bc <b2_toiTime+0xc21318>
 *   @0x307750 strheq pc, [lr], -r9
 *   @0x307754 svclt #0xb82900
 *   @0x307758 bl 0xff318084 <b2_toiTime+0xfffffffffebbebe0>
 *   @0x30775c stmdahs r0, {r2, r3}
 *   @0x307760 submi r11, r0, #184, #30
 *   @0x307764 stmdals r7, {r0, r10, lr}
 *   @0x307768 ble 0x458174 <g_RomDisk+0x60954>
 *   @0x30776c strhne pc, [r0], -r9
 *   @0x307770 .word 0x0120f041
 *   @0x307774 andne pc, r0, r9, lsr #17
 *   @0x307778 .word 0xf84645c2
 *   @0x30777c .word 0xf8c99c04
 *   @0x307780 tstle r0, r0, lsr #32
 *   @0x307784 strhne pc, [r0], -r7
 *   @0x307788 addmi r3, r11, #67108864
 *   @0x30778c ldmvs r10!, {r1, r3, r9, r11, r12, lr, pc} ^
 *   @0x307790 andshs pc, r3, r2, lsr r8
 *   @0x307794 b 0x16f3fe0 <b2_toiTime+0xf9ab3c>
 *   @0x307798 bl 0x50d8a4 <SrcVerts+0x6a8e8>
 *   @0x30779c strtmi r0, [r8], #2241
 *   @0x3077a0 and r4, r0, r2, asr #13
 *   @0x3077a4 .word 0x362846d0
 *   @0x3077a8 bleq 0x543bdc <g_DecodeStringBuffer+0x1168>
 *   @0x3077ac .word 0xe78046d1
 *   @0x3077b0 .word 0x21006a62
 *   @0x3077b4 bl 0x3e2248 <error_g0017+0x3aeec>
 *   @0x3077b8 ldmvs r10!, {r1, r7} ^
 *   @0x3077bc andle r4, r11, #805306376
 *   @0x3077c0 .word 0x014eb209
 *   @0x3077c4 biceq lr, r1, r6, lsl #22
 *   @0x3077c8 .word 0xf8434429
 *   @0x3077cc rfeda r2!
 *   @0x3077d0 .word 0x31011b02
 *   @0x3077d4 ldrb r11, [r1, r9, lsl #5]!
 *   @0x3077d8 .word 0xf04f9a07
 *   @0x3077dc .word 0xf8df0c00
 *   @0x3077e0 .word 0xf04f8234
 *   @0x3077e4 bvs 0xfecc9c24 <b2_toiTime+0xfffffffffe570780>
 *   @0x3077e8 bllo 0x34793c
 *   @0x3077ec bvs 0x1bec404 <b2_toiTime+0x1492f60>
 *   @0x3077f0 orreq lr, r3, #7168
 *   @0x3077f4 stmdals r5, {r0, r2, r8, r9, r12, pc}
 *   @0x3077f8 .word 0xf0804287
 *   @0x3077fc .word 0xf8578082
 *   @0x307800 bvs 0x17d2418 <b2_toiTime+0x1078f74>
 *   @0x307804 addsmi r4, r3, #17825792
 *   @0x307808 rfeib r1!
 *   @0x30780c rfeib r3!
 *   @0x307810 rfeib r1!
 *   @0x307814 bne 0xb1f854 <b2_toiTime+0x3c63b0>
 *   @0x307818 strhmi pc, [lr], -r3
 *   @0x30781c svclt #0xb82800
 *   @0x307820 blne 0x1018128 <b2_toiTime+0x8bec84>
 *   @0x307824 svclt #0xb82c00
 *   @0x307828 strtmi r4, [r0], #-612
 *   @0x30782c adcmi r9, r0, #4, #24
 *   @0x307830 movwhs sp, #0xb08
 *   @0x307834 .word 0xf8c1460e
 *   @0x307838 .word 0x460ac018
 *   @0x30783c andsgt pc, r12, r1, asr #17
 *   @0x307840 eor r4, pc, r8, lsl r6
 *   @0x307844 bvs 0x19d90b0 <b2_toiTime+0x127fc0c>
 *   @0x307848 bne 0xfeb817c4 <b2_toiTime+0xfffffffffe428320>
 *   @0x30784c b 0x16d8260 <b2_toiTime+0xf7edbc>
 *   @0x307850 blx 0x507fde <SrcVerts+0x65022>
 *   @0x307854 orrsvs pc, r1, r1, lsl #2
 *   @0x307858 smlabteq r0, r1, r1, pc
 *   @0x30785c .word 0xf1c061e1
 *   @0x307860 blle 0x1307c68 <b2_toiTime+0xbae7c4>
 *   @0x307864 blle 0x1498298 <b2_toiTime+0xd3edf4>
 *   @0x307868 ldrmi r4, [r8], -r1, lsl #12
 *   @0x30786c .word 0x2102460b
 *   @0x307870 svclt #0xb82b00
 *   @0x307874 blx 0x5581ea <g_SWFlineaavertbuff+0x5122>
 *   @0x307878 addsmi pc, r8, #201326592
 *   @0x30787c ldrdhs r11, r12, [r4, -r8]
 *   @0x307880 sbcsvc r11, r1, r9, asr #5
 *   @0x307884 adcmi r6, r2, #73728
 *   @0x307888 .word 0xd1fa7091
 *   @0x30788c ldrhne r1, [r11], #163
 *   @0x307890 .word 0xf303fb08
 *   @0x307894 subsmi r6, r11, #-1073741788
 *   @0x307898 movwhs r6, #0x1f3
 *   @0x30789c adcsmi r4, r4, #24, #12
 *   @0x3078a0 strtmi sp, [r1], -r9, lsr #1
 *   @0x3078a4 rfeib r1!
 *   @0x3078a8 rfeib r1!
 *   @0x3078ac rfeib r4!
 *   @0x3078b0 bl 0xff5b38e8 <b2_toiTime+0xfffffffffee5a444>
 *   @0x3078b4 ldrbmi r0, [r0], #-2571
 *   @0x3078b8 strhge pc, [lr], -r4
 *   @0x3078bc beq 0x5c27c8 <g_SWFlineaavertbuff+0x6f700>
 *   @0x3078c0 b 0xfe318a14 <b2_toiTime+0xfffffffffdbbf570>
 *   @0x3078c4 bl 0xfeda644c <b2_toiTime+0xfffffffffe64cfa8>
 *   @0x3078c8 b 0xfe3e6450 <b2_toiTime+0xfffffffffdc8cfac>
 *   @0x3078cc bl 0xfeb64060 <b2_toiTime+0xfffffffffe40abbc>
 *   @0x3078d0 ldrbmi r7, [r1], #-483
 *   @0x3078d4 ldrsbge pc, [r12], -sp
 *   @0x3078d8 ble 0xff098e24 <b2_toiTime+0xfffffffffe93f980>
 *   @0x3078dc .word 0xf0418821
 *   @0x3078e0 eorhi r0, r1, r0, lsl r1
 *   @0x3078e4 addmi lr, r11, #57409536
 *   @0x3078e8 subsmi sp, r9, #36864
 *   @0x3078ec strmi r4, [r8], -r3, lsl #12
 *   @0x3078f0 .word 0x0101f06f
 *   @0x3078f4 .word 0x4608e7bc
 *   @0x3078f8 mvnslo pc, pc, asr #32
 *   @0x3078fc strhhs lr, [r1, -r8]
 *   @0x307900 svcmi #0x44e7b6
 *   @0x307904 strmi pc, [r4], -r0, asr #4
 *   @0x307908 .word 0x9c062128
 *   @0x30790c eorsle r4, r7, #1342177290
 *   @0x307910 strbeq r8, [r4], r8, lsr #16
 *   @0x307914 rfeib r5!
 *   @0x307918 adcsmi r3, r3, #2
 *   @0x30791c stmibvs r11!, {r1, r2, r3, r5, r8, r12, lr, pc}
 *   @0x307920 rfeib r5!
 *   @0x307924 blx 0x35795e
 *   @0x307928 rfeia r5!
 *   @0x30792c blx 0x36b96e <_ZTS13C_UTF16String+0x2a1a>
 *   @0x307930 rfeib r3!
 *   @0x307934 rfeia r3!
 *   @0x307938 rfeib r2!
 *   @0x30793c bl 0xff433974 <b2_toiTime+0xfffffffffecda4d0>
 *   @0x307940 rfeia r2!
 *   @0x307944 bl 0xff5f7984 <b2_toiTime+0xfffffffffee9e4e0>
 *   @0x307948 b 0xfe988960 <b2_toiTime+0xfffffffffe22f4bc>
 *   @0x30794c ldrle r0, [r5], #-3844
 *   @0x307950 .word 0xf989fa0f
 *   @0x307954 .word 0xf888fa0f
 *   @0x307958 stc2 p10, c15, [r12], {15}
 *   @0x30795c stmdaeq r8, {r0, r3, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x307960 stmdbeq r9, {r2, r3, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x307964 svceq #0x9ea98
 *   @0x307968 .word 0xf040d408
 *   @0x30796c eorhi r0, r8, r0, lsl r0
 *   @0x307970 smullne r1, r0, r8, r10
 *   @0x307974 orrsvs r4, r0, r8, ror r3
 *   @0x307978 bicsvs r4, r8, r0, asr #4
 *   @0x30797c strb r3, [r4, r8, lsr #10]
 *   @0x307980 strhs r9, [r8, -r11, lsl #24]!
 *   @0x307984 .word 0x808cf8df
 *   @0x307988 ldrsbge pc, [r8], -sp
 *   @0x30798c msreq APSR_nzcvq, #164, #2
 *   @0x307990 .word 0xf4bf4553
 *   @0x307994 rfeda r4!
 *   @0x307998 ldrbeq r2, [r1], r8, lsr #24
 *   @0x30799c .word 0x0792d437
 *   @0x3079a0 rfeda r4!
 *   @0x3079a4 .word 0xf0433c28
 *   @0x3079a8 .word 0xf8240310
 *   @0x3079ac eor r3, lr, r8, lsr #24
 *   @0x3079b0 stchs p9, c15, [r5], #-80
 *   @0x3079b4 stcne p9, c15, [r6], #-80
 *   @0x3079b8 smlawble r6, r10, r2, r4
 *   @0x3079bc mvnsle r2, r4, lsl #20
 *   @0x3079c0 .word 0x5c10f854
 *   @0x3079c4 .word 0x6c0cf854
 *   @0x3079c8 .word 0x2c1cf934
 *   @0x3079cc strlo pc, [r5, #-0xb07]
 *   @0x3079d0 strlo pc, [r6], -r7, lsl #22
 *   @0x3079d4 .word 0x3c1af934
 *   @0x3079d8 strhgt pc, [r12], -r5
 *   @0x3079dc strh pc, [lr], -r5
 *   @0x3079e0 strheq pc, [r12], -r6
 *   @0x3079e4 strhne pc, [lr], -r6
 *   @0x3079e8 bl 0xff38e230 <b2_toiTime+0xfffffffffec34d8c>
 *   @0x3079ec bne 0x1948224 <b2_toiTime+0x11eed80>
 *   @0x3079f0 movweq lr, #0xebc3
 *   @0x3079f4 stc2 p7, c15, [r8], #-884
 *   @0x3079f8 blne 0xfedf3f20 <b2_toiTime+0xfffffffffe69aa7c>
 *   @0x3079fc blx 0x50bd72 <SrcVerts+0x68db6>
 *   @0x307a00 .word 0x61b3f303
 *   @0x307a04 mvnvs r4, r11, asr r2
 *   @0x307a08 sbcsmi lr, r1, #53215232
 *   @0x307a0c strtlo sp, [r8], #-201
 *   @0x307a10 svclt #0xe7ba
 *   @0x307a14 stclgt p12, c12, [r12], {205}
 *   @0x307a18 .word 0x4608b570
 *   @0x307a1c ldrmi r4, [r1], -r12, lsl #12
 *   @0x307a20 .word 0xf7ff4616
 *   @0x307a24 .word 0x4605fd95
 *   @0x307a28 qadd16mi r11, r0, r8
 *   @0x307a2c .word 0xf7ff4631
 *   @0x307a30 strtmi pc, [r8], -r11, asr #24
 *   @0x307a34 andeq r11, r0, r0, ror sp
 *   @0x307a38 movtpl pc, #0x4240
 *   @0x307a3c movweq pc, #0x1b03
 *   @0x307a40 svcmi #0xf0e92d
 *   @0x307a44 strmi r11, [r5], -r9, lsr #1
 *   @0x307a48 ldcne p3, c3, [lr, #-160]
 *   @0x307a4c bvs 0x1dec6a8 <b2_toiTime+0x1693204>
 *   @0x307a50 bvs 0xfee19294 <b2_toiTime+0xfffffffffe6bfdf0>
 *   @0x307a54 stmdavs r0, {r1, r2, r3, r8, sp}
 *   @0x307a58 orreq lr, r3, #4, #22
 *   @0x307a5c .word 0xf8d5931b
 *   @0x307a60 ldrhls r3, [r7], -r12
 *   @0x307a64 .word 0xf0116a98
 *   @0x307a68 ldmdbge sp, {r4, r5, r6, r7, r11, sp, lr, pc}
 *   @0x307a6c tstls r9, r12, lsr #4
 *   @0x307a70 .word 0x46089012
 *   @0x307a74 .word 0xf5ae2100
 *   @0x307a78 ldmdals r5, {r2, r3, r4, r7, r8, r10, r11, sp, lr, pc}
 *   @0x307a7c .word 0x43faf44f
 *   @0x307a80 ldmibvs r3!, {r2, r5, r8, r9, r12, pc}
 *   @0x307a84 b 0xfe3cff2c <b2_toiTime+0xfffffffffdc76a88>
 *   @0x307a88 bl 0xfeba461c <b2_toiTime+0xfffffffffe44b178>
 *   @0x307a8c movwhs r7, #0x2e3
 *   @0x307a90 subvs r9, r3, pc, lsl #4
 *   @0x307a94 stmibvs r10!, {r0, r1, r3, r5, r6, r7, r8, r11, sp, lr}
 *   @0x307a98 andlo pc, r2, #1024
 *   @0x307a9c addsmi r11, r3, #2211840
 *   @0x307aa0 rfeib r3!
 *   @0x307aa4 .word 0x3328100c
 *   @0x307aa8 .word 0x1c10f843
 *   @0x307aac .word 0x1c1af933
 *   @0x307ab0 .word 0x1c0cf843
 *   @0x307ab4 stmdbls pc, {r0, r1, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x307ab8 strhs r9, [r0], #-1044
 *   @0x307abc and r9, r11, r0, lsl r1
 *   @0x307ac0 rscsle r4, r8, #805306377
 *   @0x307ac4 strhne pc, [lr], -r3
 *   @0x307ac8 .word 0xf8433328
 *   @0x307acc rfedb r3!
 *   @0x307ad0 .word 0xf8431c1c
 *   @0x307ad4 ldrb r1, [r3, r12, lsl #24]!
 *   @0x307ad8 blls 0x9ee330 <b2_toiTime+0x294e8c>
 *   @0x307adc .word 0xf080429a
 *   @0x307ae0 blls 0x828328 <b2_toiTime+0xcee84>
 *   @0x307ae4 .word 0xf853980f
 *   @0x307ae8 tstls r4, #4, #22
 *   @0x307aec andls r6, r7, #339968
 *   @0x307af0 mullo r3, r3, r9
 *   @0x307af4 svclt #0xb82b00
 *   @0x307af8 addmi r4, r3, #-1342177275
 *   @0x307afc .word 0xf992d116
 *   @0x307b00 blhs 0x313b14 <af_shaper_get_elem+0x9382>
 *   @0x307b04 subsmi r11, r11, #184, #30
 *   @0x307b08 smlabble pc, r3, r2, r4
 *   @0x307b0c bvs 0x19d9360 <b2_toiTime+0x127febc>
 *   @0x307b10 .word 0xf993990f
 *   @0x307b14 bhs 0x30fb28 <af_shaper_get_elem+0x5396>
 *   @0x307b18 subsmi r11, r2, #184, #30
 *   @0x307b1c andle r4, r2, r10, lsl #5
 *   @0x307b20 movwls r6, #0x7a1b
 *   @0x307b24 bls 0x4ffb34 <SrcVerts+0x5cb78>
 *   @0x307b28 .word 0xd1f04293
 *   @0x307b2c .word 0xf44f4b9c
 *   @0x307b30 stcls p0, c4, [r7, #-1000]
 *   @0x307b34 bleq 0x343c78
 *   @0x307b38 .word 0x460746d8
 *   @0x307b3c .word 0x4699469a
 *   @0x307b40 ldmdbge r12, {r2, r7, r9, r10, lr}
 *   @0x307b44 andls r9, r8, r9, lsl #6
 *   @0x307b48 sublt pc, r4, sp, asr #17
 *   @0x307b4c andls r9, sp, lr, lsl #6
 *   @0x307b50 andls r9, r10, r11, lsl #6
 *   @0x307b54 subslt pc, r8, sp, asr #17
 *   @0x307b58 andls r9, r4, r5, lsl #6
 *   @0x307b5c andslt pc, r8, sp, asr #17
 *   @0x307b60 andlt pc, r12, sp, asr #17
 *   @0x307b64 eorslt pc, r0, sp, asr #17
 *   @0x307b68 bls 0x62bfd8 <g_SWFaavertbuff+0x58f10>
 *   @0x307b6c .word 0xf0002a00
 *   @0x307b70 stmibvs r11!, {r0, r2, r3, r8, pc}
 *   @0x307b74 svclt #0xa8459c
 *   @0x307b78 ldrmi r4, [r9, #0x69c]
 *   @0x307b7c .word 0x4699bfb8
 *   @0x307b80 adcsmi r6, r11, #3850240
 *   @0x307b84 stmdahi r8!, {r1, r9, r11, r12, lr, pc}
 *   @0x307b88 andls r4, r3, pc, lsl r6
 *   @0x307b8c stcle p5, c4, [r2, #-332]
 *   @0x307b90 ldrmi r8, [r10], r9, lsr #16
 *   @0x307b94 stmdahi r10!, {r1, r2, r8, r12, pc}
 *   @0x307b98 swple r0, r0, [r9]
 *   @0x307b9c stmdals r5, {r2, r9, r11, r12, pc}
 *   @0x307ba0 svclt #0xa8429a
 *   @0x307ba4 andls r4, r4, #27262976
 *   @0x307ba8 svclt #0xb84298
 *   @0x307bac andls r4, r5, r8, lsl r6
 *   @0x307bb0 mullo r3, r5, r9
 *   @0x307bb4 addmi r9, r11, #16, #18
 *   @0x307bb8 bls 0x4fbfcc <SrcVerts+0x59010>
 *   @0x307bbc .word 0xf0404295
 *   @0x307bc0 .word 0xf1b880f1
 *   @0x307bc4 andle r0, r4, r0, lsl #30
 *   @0x307bc8 .word 0xf8d86a63
 *   @0x307bcc addsmi r2, r3, #40
 *   @0x307bd0 bl 0x63bc94 <g_SWFaavertbuff+0x68bcc>
 *   @0x307bd4 stmdbls r3, {r0, r3, r8, r9}
 *   @0x307bd8 subsne r9, r11, r6, lsl #16
 *   @0x307bdc bl 0xff627d70 <b2_toiTime+0xfffffffffeece8cc>
 *   @0x307be0 adcvs r0, r5, #603979776
 *   @0x307be4 adchi r1, r3, r11, asr r0
 *   @0x307be8 movweq lr, #0x1a40
 *   @0x307bec mulle r9, r9, r7
 *   @0x307bf0 stmdals r4, {r0, r2, r9, r11, r12, pc}
 *   @0x307bf4 bne 0x7ee044 <b2_toiTime+0x94ba0>
 *   @0x307bf8 ble 0x3d862c <error_g0017+0x312d0>
 *   @0x307bfc .word 0xf0437823
 *   @0x307c00 eorvc r0, r3, r1, lsl #6
 *   @0x307c04 movweq lr, #0xabc7
 *   @0x307c08 .word 0x81639a05
 *   @0x307c0c blls 0x419694 <g_RomDisk+0x21e74>
 *   @0x307c10 rschi r9, r7, r3, lsl #16
 *   @0x307c14 andge pc, r8, r4, lsr #17
 *   @0x307c18 movwls r9, #0x8209
 *   @0x307c1c ldrsblt pc, [r8], -sp
 *   @0x307c20 .word 0xf8cd9011
 *   @0x307c24 smladxls sp, r8, r0, r10
 *   @0x307c28 eorls pc, r12, sp, asr #17
 *   @0x307c2c eorgt pc, r8, sp, asr #17
 *   @0x307c30 .word 0xf993e0aa
 *   @0x307c34 .word 0xf9952002
 *   @0x307c38 addsmi r3, r10, #2
 *   @0x307c3c stmdbls r10, {r0, r2, r6, r8, r12, lr, pc}
 *   @0x307c40 blls 0x66e474 <g_SWFlinevertbuff+0x1b3ac>
 *   @0x307c44 svclt #0xa8458c
 *   @0x307c48 ldrmi r4, [r1, #0x68c]
 *   @0x307c4c .word 0x4691bfb8
 *   @0x307c50 ble 0x398744 <ft_adobe_glyph_list+0x7e20>
 *   @0x307c54 sadd16mi r9, pc, r1
 *   @0x307c58 stmdbls lr, {r0, r1, r12, pc}
 *   @0x307c5c ldrbmi r9, [r1, #-0xa04]
 *   @0x307c60 stmdals r9, {r3, r8, r9, r11, r12, pc}
 *   @0x307c64 strmi r11, [r10], r8, asr #31
 *   @0x307c68 svclt #0xc89905
 *   @0x307c6c andslt pc, r8, sp, asr #17
 *   @0x307c70 svclt #0xa8429a
 *   @0x307c74 addmi r4, r1, #27262976
 *   @0x307c78 .word 0x4601bfb8
 *   @0x307c7c bl 0x62c494 <g_SWFaavertbuff+0x593cc>
 *   @0x307c80 bls 0x4888ac <g_States+0x2ee4>
 *   @0x307c84 subsne r9, r11, r3, lsl #16
 *   @0x307c88 andlo pc, r2, r8, lsr #17
 *   @0x307c8c movweq lr, #0xa42
 *   @0x307c90 .word 0xf0139105
 *   @0x307c94 .word 0xf8c80f03
 *   @0x307c98 .word 0xf8985028
 *   @0x307c9c andle r3, r7, r0
 *   @0x307ca0 bne 0x5adcb8 <g_SWFlineaavertbuff+0x5abf0>
 *   @0x307ca4 addmi r9, r10, #294912
 *   @0x307ca8 .word 0xf043da02
 *   @0x307cac and r0, r1, r1, lsl #6
 *   @0x307cb0 movweq pc, #0x1023
 *   @0x307cb4 andlo pc, r0, r8, lsl #17
 *   @0x307cb8 movweq lr, #0xabc7
 *   @0x307cbc andvc pc, r6, r8, lsr #17
 *   @0x307cc0 andge pc, r8, r8, lsr #17
 *   @0x307cc4 andlo pc, r10, r8, lsr #17
 *   @0x307cc8 blls 0x6bfe3c <g_SWFlinevertbuff+0x6cd74>
 *   @0x307ccc bne 0x9add08 <b2_toiTime+0x254864>
 *   @0x307cd0 movweq lr, #0xabc7
 *   @0x307cd4 svclt #0xb82a00
 *   @0x307cd8 blhs 0x318628 <__cxa_begin_cleanup>
 *   @0x307cdc subsmi r11, r11, #184, #30
 *   @0x307ce0 ldcle p2, c4, [r1, #-616]
 *   @0x307ce4 bls 0x5ee114 <g_SWFaavertbuff+0x1b04c>
 *   @0x307ce8 svclt #0xa84561
 *   @0x307cec .word 0xf8c84661
 *   @0x307cf0 strbmi r5, [r10, #-0x28]
 *   @0x307cf4 .word 0x464abfb8
 *   @0x307cf8 strmi r9, [r11], -r10, lsl #2
 *   @0x307cfc andls r4, r11, #318767104
 *   @0x307d00 .word 0xf8a8105b
 *   @0x307d04 eors r3, r12, r2
 *   @0x307d08 stmdals r11, {r1, r3, r8, r9, r11, r12, pc}
 *   @0x307d0c svclt #0xa8459c
 *   @0x307d10 bls 0x3d9788 <error_g0017+0x3242c>
 *   @0x307d14 svclt #0xb84581
 *   @0x307d18 stmdbls r6, {r0, r7, r9, r10, lr}
 *   @0x307d1c movweq lr, #0x9b0c
 *   @0x307d20 subsne r6, r11, r5, lsr #5
 *   @0x307d24 b 0x1367eb8 <b2_toiTime+0xc0ea14>
 *   @0x307d28 ldreq r0, [r10, r2, lsl #6]
 *   @0x307d2c stmdals r5, {r0, r3, r12, lr, pc}
 *   @0x307d30 bls 0x7ae148 <b2_toiTime+0x54ca4>
 *   @0x307d34 addsmi r1, r3, #274432
 *   @0x307d38 stmdavc r3!, {r0, r1, r9, r11, r12, lr, pc}
 *   @0x307d3c movweq pc, #0x1043
 *   @0x307d40 rschi r7, r7, r3, lsr #32
 *   @0x307d44 movweq lr, #0xabc7
 *   @0x307d48 andge pc, r8, r4, lsr #17
 *   @0x307d4c smulbthi r3, r3, r6
 *   @0x307d50 .word 0xf8cdcc0f
 *   @0x307d54 stm r11!, {r3, r4, r5, sp, pc}
 *   @0x307d58 .word 0xcc0f000f
 *   @0x307d5c andeq lr, pc, r11, lsr #17
 *   @0x307d60 muleq r7, r4, r8
 *   @0x307d64 stm r11, {r0, r2, r8, r9, r11, r12, pc}
 *   @0x307d68 stmdals r4, {r0, r1, r2}
 *   @0x307d6c movwls r9, #0x9903
 *   @0x307d70 .word 0xf8dd9008
 *   @0x307d74 tstls r1, r8, lsl r0
 *   @0x307d78 .word 0xf8cd970d
 *   @0x307d7c .word 0xf8cd902c
 *   @0x307d80 ldmdavs r3!, {r3, r5, lr, pc}
 *   @0x307d84 eorsvs r3, r3, r1, lsl #22
 *   @0x307d88 strls r2, [r12], #-1024
 *   @0x307d8c addsmi r9, r5, #28672
 *   @0x307d90 blls 0x8bc1c8 <b2_toiTime+0x162d24>
 *   @0x307d94 .word 0xf47f2b00
 *   @0x307d98 mulhs r1, pc, lr
 *   @0x307d9c and r9, r5, r6, lsl r0
 *   @0x307da0 .word 0xffff8300
 *   @0x307da4 stmdbhs r0, {r2, r3, r8, r11, r12, pc}
 *   @0x307da8 adchi pc, r9, r0, asr #32
 *   @0x307dac stmdals pc, {r1, r3, r5, r6, r7, r11, r12, sp, lr}
 *   @0x307db0 tstls r3, #805306373
 *   @0x307db4 svclt #0xb82b00
 *   @0x307db8 andsls r4, r8, #-1342177275
 *   @0x307dbc andle r4, r3, r3, lsl #5
 *   @0x307dc0 addsmi r6, sp, #438272
 *   @0x307dc4 addshi pc, r11, r0, asr #32
 *   @0x307dc8 strhs r6, [r0], #-2099
 *   @0x307dcc blhs 0x76ce44 <b2_toiTime+0x139a0>
 *   @0x307dd0 ldmvs r3!, {r3, r10, r11, r12, lr, pc}
 *   @0x307dd4 teqle pc, r0, lsl #22
 *   @0x307dd8 tsteq r12, #-2147483647
 *   @0x307ddc tsths r2, #179
 *   @0x307de0 eors r6, r9, r3, ror r0
 *   @0x307de4 addsmi r6, r3, #7471104
 *   @0x307de8 ldmdbmi pc, {r1, r2, r4, r5, r8, r9, r11, r12, lr, pc} ^
 *   @0x307dec stcle p2, c4, [r2, #-552]
 *   @0x307df0 tstls r12, #64, #6
 *   @0x307df4 bl 0x3bfed8 <error_g0017+0x18b7c>
 *   @0x307df8 strlo r0, [r4], #-1186
 *   @0x307dfc blle 0x418854 <g_RomDisk+0x21034>
 *   @0x307e00 addsmi r4, r12, #92160
 *   @0x307e04 ldrmi r11, [r12], -r8, lsr #31
 *   @0x307e08 mrrcmi p0, #0x0, lr, r8, c0
 *   @0x307e0c .word 0xf10668b7
 *   @0x307e10 addsmi r0, pc, #28, #6
 *   @0x307e14 andhs sp, r0, #-1073741820
 *   @0x307e18 qadd16mi r10, r3, r12
 *   @0x307e1c andls r9, r0, #1
 *   @0x307e20 ldmdals r7, {r2, r3, r5, r8, sp}
 *   @0x307e24 rfedb r3!
 *   @0x307e28 adcsvs r9, r0, r12, lsl r11
 *   @0x307e2c strhs r11, [r0], #-267
 *   @0x307e30 shadd16mi lr, r9, r9
 *   @0x307e34 subvc pc, r6, #1325400064
 *   @0x307e38 bl 0xff3454f8 <b2_toiTime+0xfffffffffebec054>
 *   @0x307e3c ldmdbge r12, {r0, r1, r3, sp, lr, pc}
 *   @0x307e40 .word 0x91014623
 *   @0x307e44 strls r2, [r0, -r12, lsr #2]
 *   @0x307e48 .word 0xf7e09817
 *   @0x307e4c blls 0xa462d4 <b2_toiTime+0x2ece30>
 *   @0x307e50 blhs 0x320118
 *   @0x307e54 rsbsvs sp, r4, r11, ror #3
 *   @0x307e58 strths r6, [r12], #-2099
 *   @0x307e5c mrrcne p8, #0xb, r6, r9, c2
 *   @0x307e60 blx 0x41ff2e <g_RomDisk+0x2870e>
 *   @0x307e64 ldmdals r12, {r0, r1, r10, sp}
 *   @0x307e68 cmnle r10, r0, lsl #16
 *   @0x307e6c ldcleq p1, c15, [r4], #-52
 *   @0x307e70 ldm r12!, {r0, r1, r2, r5, r9, r10, lr}
 *   @0x307e74 strgt r0, [pc, -pc]
 *   @0x307e78 strheq lr, [pc], -r12
 *   @0x307e7c ldm r12, {r0, r1, r2, r3, r8, r9, r10, lr, pc}
 *   @0x307e80 stm r7, {r0, r1, r2}
 *   @0x307e84 bls 0x907ea8 <b2_toiTime+0x1aea04>
 *   @0x307e88 adcvs r6, r5, #1342177286
 *   @0x307e8c .word 0xf1b87062
 *   @0x307e90 andle r0, r1, r0, lsl #30
 *   @0x307e94 stmdaeq r12!, {r2, r5, r7, r8, r12, sp, lr, pc}
 *   @0x307e98 stmibvs pc!, {r0, r1, r3, r5, r11, pc} ^
 *   @0x307e9c ldrsbgt pc, [r8], -r5
 *   @0x307ea0 .word 0xf0039303
 *   @0x307ea4 blhs 0x308ab8 <TT_New_Context+0x88b0>
 *   @0x307ea8 svclt #0xc4b31
 *   @0x307eac .word 0xf44f4638
 *   @0x307eb0 strdls r4, r5, [r4], -r10
 *   @0x307eb4 ldrtmi r11, [r11], -r8, lsl #30
 *   @0x307eb8 bvs 0x1decad4 <b2_toiTime+0x1693630>
 *   @0x307ebc .word 0xd116429d
 *   @0x307ec0 andgt pc, r2, r4, lsr #17
 *   @0x307ec4 ldreq r8, [r11, r11, lsr #16]
 *   @0x307ec8 stmdavc r3!, {r0, r1, r12, lr, pc}
 *   @0x307ecc movweq pc, #0x1043
 *   @0x307ed0 stmibvs r11!, {r0, r1, r5, r12, sp, lr} ^
 *   @0x307ed4 stmdbls r3, {r1, r3, r4, r5, r7, r9, r10, lr}
 *   @0x307ed8 bls 0x7d9a64 <b2_toiTime+0x805c0>
 *   @0x307edc stmibvs r11!, {r0, r1, r5, r6, r7, pc} ^
 *   @0x307ee0 andsls r9, r0, #-2147483647
 *   @0x307ee4 movwhs r8, #0x123
 *   @0x307ee8 ldrmi r8, [r12], -r3, ror #2
 *   @0x307eec blls 0x3fff10 <g_RomDisk+0x86f0>
 *   @0x307ef0 ldmdals r3, {r1, r3, r4, r5, r7, r9, r10, lr}
 *   @0x307ef4 smlatths r1, r1, r6, r4
 *   @0x307ef8 movwls r9, #0x610c
 *   @0x307efc bvs 0xe6bf44 <b2_toiTime+0x712aa0>
 *   @0x307f00 ldmdals r5, {r0, r1, r4, r5, r9, r10, sp, lr, pc}
 *   @0x307f04 ldmvs r3!, {r2, r3, r5, r8, r10, sp}
 *   @0x307f08 blx 0x46201a <g_RomDisk+0x6a7fa>
 *   @0x307f0c adcmi r3, r11, #8388608
 *   @0x307f10 bvs 0x1a3c7b0 <b2_toiTime+0x12e330c>
 *   @0x307f14 stmibvs r1!, {r3, r4, r7, r9, r11, sp, lr} ^
 *   @0x307f18 bvs 0x1c22628 <b2_toiTime+0x14c9184>
 *   @0x307f1c stmibvs r4!, {r0, r4, r7, r9, lr} ^
 *   @0x307f20 addmi sp, r12, #12, #20
 *   @0x307f24 ldmdbhi lr, {r2, r9, r11, r12, lr, pc} ^
 *   @0x307f28 bl 0x48eb54 <prim_v+0x51a0>
 *   @0x307f2c cmphi r9, r1, ror #2
 *   @0x307f30 stmibvs r9, {r0, r9, r11, sp, lr} ^
 *   @0x307f34 ldcle p2, c4, [r1, #-580]
 *   @0x307f38 and r1, r11, r10, lsl #21
 *   @0x307f3c stcle p2, c4, [r4, #-560]
 *   @0x307f40 bne 0x1b6a4c0 <b2_toiTime+0x141101c>
 *   @0x307f44 .word 0x0161eb06
 *   @0x307f48 bvs 0x3684b4 <_ZTS12CDS_Priority+0xa50c>
 *   @0x307f4c addsmi r6, r1, #3293184
 *   @0x307f50 bne 0x17be768 <b2_toiTime+0x10652c4>
 *   @0x307f54 bl 0x32a4bc
 *   @0x307f58 cmphi r10, r2, ror #4
 *   @0x307f5c ldrb r3, [r6, r12, lsr #6]
 *   @0x307f60 eorlt r2, r9, r0
 *   @0x307f64 svchi #0xf0e8bd
 *   @0x307f68 rsceq r11, r8, #184320
 *   @0x307f6c rsceq r11, r8, #188416
 *   @0x307f70 .word 0xffff8300
 *   @0x307f74 svcmi #0xf0e92d
 *   @0x307f78 ldrmi r4, [r10], r4, lsl #12
 *   @0x307f7c addlt r6, r5, r3, ror #17
 *   @0x307f80 blhs 0x5d1b88 <g_SWFlineaavertbuff+0x7eac0>
 *   @0x307f84 ldrmi r4, [r1], r8, lsl #13
 *   @0x307f88 strls r9, [r3, -lr, lsl #16]
 *   @0x307f8c stmdbvs r3!, {r3, r10, r11, r12, lr, pc} ^
 *   @0x307f90 teqle r10, r0, lsl #22
 *   @0x307f94 movtvc pc, #0xd504
 *   @0x307f98 movwhs r6, #0xc163
 *   @0x307f9c eors r6, r4, r3, lsr #2
 *   @0x307fa0 addsmi r6, r3, #557056
 *   @0x307fa4 blmi 0x107ec70 <b2_toiTime+0x9257cc>
 *   @0x307fa8 stcle p2, c4, [r2, #-616]
 *   @0x307fac movwls r2, #0x3340
 *   @0x307fb0 bl 0x3c0130 <error_g0017+0x18dd4>
 *   @0x307fb4 ldcmi p3, c0, [r2, #-648]!
 *   @0x307fb8 addsmi r3, r3, #4, #6
 *   @0x307fbc adcmi sp, r11, #2048
 *   @0x307fc0 .word 0x461dbfb8
 *   @0x307fc4 .word 0xf5046966
 *   @0x307fc8 addsmi r7, lr, #872415233
 *   @0x307fcc tstle r1, r3, lsl #22
 *   @0x307fd0 .word 0x212c2200
 *   @0x307fd4 andeq lr, r12, sp, lsl #17
 *   @0x307fd8 .word 0xf7e0462b
 *   @0x307fdc blls 0x406144 <g_RomDisk+0xe924>
 *   @0x307fe0 .word 0xb10b6160
 *   @0x307fe4 sub r2, r3, r0, lsl #14
 *   @0x307fe8 .word 0xf44f4631
 *   @0x307fec .word 0xf5ae7204
 *   @0x307ff0 and lr, r9, r6, ror #21
 *   @0x307ff4 .word 0x212c9301
 *   @0x307ff8 strls r4, [r0], -r11, lsr #12
 *   @0x307ffc .word 0xf847f7e0
 *   @0x308000 .word 0x61609b03
 *   @0x308004 mvnle r2, r0, lsl #22
 *   @0x308008 .word 0xf8d46125
 *   @0x30800c .word 0xf04fb014
 *   @0x308010 stmvs r3!, {r2, r3, r5, r10, r11} ^
 *   @0x308014 .word 0xbc03fb0c
 *   @0x308018 ldrbmi r4, [pc, #-0x667]
 *   @0x30801c bl 0xff63e468 <b2_toiTime+0xfffffffffeee4fc4>
 *   @0x308020 .word 0xf1ac0307
 *   @0x308024 cdppl p2, #0xd, c0, c1, c12, #0x1
 *   @0x308028 svceq #0xf1ba
 *   @0x30802c strbmi sp, [r1, #-0x4]
 *   @0x308030 ldrdhs r11, r12, [r0, -r4]
 *   @0x308034 and r2, r3, r1, lsl #2
 *   @0x308038 svclt #0xac4541
 *   @0x30803c mrshs r2, apsr
 *   @0x308040 stmvs r3!, {r0, r3, r4, r8, r12, sp, pc} ^
 *   @0x308044 rscvs r3, r3, r1, lsl #6
 *   @0x308048 mrcpl p0, #0x6, lr, c3, c2, #0x0
 *   @0x30804c .word 0xd1024543
 *   @0x308050 ldrmi r6, [r9, #0x9a3]
 *   @0x308054 .word 0xf1a7d0f5
 *   @0x308058 ldrtmi r0, [sp], -r12, lsr #12
 *   @0x30805c cdpgt p15, #0x0, c3, c15, c12, #0x1
 *   @0x308060 cdpgt p5, #0x0, c12, c15, c15, #0x0
 *   @0x308064 ldm r6, {r0, r1, r2, r3, r8, r10, lr, pc}
 *   @0x308068 stm r5, {r0, r1, r2}
 *   @0x30806c ldrb r0, [r4, r7]
 *   @0x308070 stmdals r3, {r0, r1, r2, r3, r8, r9, r11, r12, pc}
 *   @0x308074 andlt r6, r5, pc, lsl r0
 *   @0x308078 svchi #0xf0e8bd
 *   @0x30807c rsceq r11, r8, #184320
 *   @0x308080 rsceq r11, r8, #188416
 *   @0x308084 svcmi #0xf0e92d
 *   @0x308088 vmax.s8 d20, d0, d15
 *   @0x30808c strmi r5, [r3], -r4, asr #2
 *   @0x308090 .word 0x0107fb01
 *   @0x308094 addlt r6, sp, r0, lsl #16
 *   @0x308098 strbtlo pc, [r8], #578
 *   @0x30809c andls r4, r5, r5, lsr #21
 *   @0x3080a0 strteq pc, [r12], -r1, lsl #2
 *   @0x3080a4 beq 0xff2463f8 <b2_toiTime+0xfffffffffeaecf54>
 *   @0x3080a8 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr}
 *   @0x3080ac blx 0x42238a <g_RomDisk+0x2ab6a>
 *   @0x3080b0 stmdavs r0, {r0, r1, r2, r10}
 *   @0x3080b4 strtlo r6, [r12], #-2176
 *   @0x3080b8 eoreq pc, r0, r2, asr r8
 *   @0x3080bc smlawths r12, r10, r10, r6
 *   @0x3080c0 .word 0x5102fb01
 *   @0x3080c4 rscsvs r2, r2, r0, lsl #4
 *   @0x3080c8 stmdblt r7, {r0, r1, r8, r12, pc} ^
 *   @0x3080cc ldmvs r9, {r6, sp} ^
 *   @0x3080d0 .word 0x8004f8d3
 *   @0x3080d4 mcr2 p7, #0x7, pc, c15, c12, #0x6
 *   @0x3080d8 selmi r4, r2, r11
 *   @0x3080dc svchs #0x1e008
 *   @0x3080e0 .word 0x800cf8d3
 *   @0x3080e4 .word 0xf890bf0b
 *   @0x3080e8 ldrmi r11, [r3], r12
 *   @0x3080ec .word 0x46da4692
 *   @0x3080f0 eorhs r4, r0, r1, asr #12
 *   @0x3080f4 mrc2 p7, #0x6, apsr_nzcv, c15, c12, #0x6
 *   @0x3080f8 andls r4, r6, r1, asr #12
 *   @0x3080fc .word 0x00ccf8d4
 *   @0x308100 strteq pc, [r12], #-261
 *   @0x308104 .word 0xf8d2f7ff
 *   @0x308108 ldmdahs r0, {r0, r6, r9, r10, lr}
 *   @0x30810c andshs r11, r0, r8, lsr #31
 *   @0x308110 mrc2 p7, #0x6, apsr_nzcv, c1, c12, #0x6
 *   @0x308114 blx 0x3d0d2a <error_g0017+0x299ce>
 *   @0x308118 stmdbge r11, {r1, r3, r8, r9, r12, sp, lr, pc}
 *   @0x30811c movwls r9, #0x7109
 *   @0x308120 .word 0xf8dd9004
 *   @0x308124 .word 0xf1a4c00c
 *   @0x308128 strbmi r0, [r7, #-0x72c]!
 *   @0x30812c rfedb r4!
 *   @0x308130 ldrbmi r3, [r3, #-0xc22]
 *   @0x308134 rfedb r4!
 *   @0x308138 .word 0xf8dd2c28
 *   @0x30813c strbmi r12, [r2, #-0x18]!
 *   @0x308140 .word 0xf814dc5b
 *   @0x308144 bhs 0x4131f8 <g_RomDisk+0x1b9d8>
 *   @0x308148 .word 0xf854d057
 *   @0x30814c .word 0xb1211c14
 *   @0x308150 ldrsbgt pc, [r12], -sp
 *   @0x308154 svceq #0x43ebbc
 *   @0x308158 ldmvs r0!, {r0, r1, r2, r3, r6, r10, r11, r12, lr, pc} ^
 *   @0x30815c subslt r2, r3, #0, #2
 *   @0x308160 andls r9, r8, r2, lsl #6
 *   @0x308164 addmi r9, r1, #8, #16
 *   @0x308168 .word 0xf04fda1d
 *   @0x30816c ldmdbvs r3!, {r2, r3, r5, r10, r11} ^
 *   @0x308170 .word 0xf001fb0c
 *   @0x308174 ldrsbgt pc, [r4], -r6
 *   @0x308178 stcls p9, c15, [r10], #-208
 *   @0x30817c rfedb r12!
 *   @0x308180 .word 0xf8dd0000
 *   @0x308184 bl 0xff3381cc <b2_toiTime+0xfffffffffebded28>
 *   @0x308188 stmdahs r0, {r0, r3}
 *   @0x30818c submi r11, r0, #184, #30
 *   @0x308190 ble 0x499718 <g_anumPerfBlocks+0x3d4>
 *   @0x308194 muleq sp, r3, r9
 *   @0x308198 .word 0xc008f8dd
 *   @0x30819c .word 0xf0004560
 *   @0x3081a0 strhlo r8, [r1, -sp]
 *   @0x3081a4 stmdals r5, {r1, r2, r3, r4, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x3081a8 rfedb r4!
 *   @0x3081ac subslt r1, r2, #10752
 *   @0x3081b0 ldrbmi r9, [r11], -r1, lsl #6
 *   @0x3081b4 ldrtmi r9, [r0], -r0
 *   @0x3081b8 mrc2 p7, #0x6, apsr_nzcv, c12, c15, #0x7
 *   @0x3081bc stmdahs r0, {r0, r9, r10, lr}
 *   @0x3081c0 adcshi pc, r3, r0, asr #32
 *   @0x3081c4 stmdals r11, {r2, r3, r5, r9, sp}
 *   @0x3081c8 ldmib r2!, {r1, r2, r3, r5, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x3081cc strbmi r9, [r1], -r11, lsl #22
 *   @0x3081d0 addsvs r6, pc, #-268435451
 *   @0x3081d4 stchs p8, c15, [r11], #-80
 *   @0x3081d8 rfeda r4!
 *   @0x3081dc andshi r2, r10, r10, lsr #24
 *   @0x3081e0 stceq p9, c15, [r10], #-208
 *   @0x3081e4 .word 0x902cf8dd
 *   @0x3081e8 .word 0xf860f7ff
 *   @0x3081ec .word 0xf8c99b0b
 *   @0x3081f0 ldmdavs r10, {r2} ^
 *   @0x3081f4 .word 0xf844609a
 *   @0x3081f8 strtlo r7, [r12], #-3100
 *   @0x3081fc strths lr, [r12], #-1937
 *   @0x308200 .word 0xc00cf8dd
 *   @0x308204 eorle r4, r0, #423624704
 *   @0x308208 mullo r1, r5, r9
 *   @0x30820c tstle r10, r4, lsl #22
 *   @0x308210 movwhs r6, #0x8f7
 *   @0x308214 ble 0x898d08 <b2_toiTime+0x13f864>
 *   @0x308218 .word 0xf103fb04
 *   @0x30821c rfeib r5!
 *   @0x308220 stmdane r2, {r1, lr, pc} ^
 *   @0x308224 bl 0xff35fb30 <b2_toiTime+0xfffffffffec0668c>
 *   @0x308228 .word 0xf8dd010c
 *   @0x30822c stmdbhs r0, {r4, lr, pc}
 *   @0x308230 submi r11, r9, #184, #30
 *   @0x308234 blle 0x3597c0
 *   @0x308238 strb r3, [r11, r1, lsl #6]!
 *   @0x30823c qsubvs r6, r3, r11
 *   @0x308240 .word 0x611d6a93
 *   @0x308244 strlo r6, [r12, #-0x295]!
 *   @0x308248 ldmdbvs r3!, {r1, r3, r4, r6, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x30824c stceq p0, c15, [r12], #-316
 *   @0x308250 blx 0x622622 <g_SWFaavertbuff+0x4f55a>
 *   @0x308254 ldrmi r3, [r10], -r2, lsl #24
 *   @0x308258 andle r4, r8, #411041792
 *   @0x30825c qsublt r6, r1, r1
 *   @0x308260 stmdbvs r9, {r1, r3, r6, r7, sp, lr}
 *   @0x308264 addmi r6, r1, #80, #20
 *   @0x308268 eorlo sp, r12, #-2147483586
 *   @0x30826c .word 0xf04fe7f4
 *   @0x308270 .word 0xf04f0800
 *   @0x308274 strbmi r0, [r3, #-0x901]!
 *   @0x308278 bvs 0x197cbb8 <b2_toiTime+0x1223714>
 *   @0x30827c strtmi r2, [r5], -r0, lsl #8
 *   @0x308280 stmibvs lr, {r1, r3, r11, r12, sp, lr}
 *   @0x308284 svclt #0x4c07d2
 *   @0x308288 strlo r3, [r1], #-1281
 *   @0x30828c ldmvs r7!, {r1, r2, r3, r5, r8, r12, sp, pc} ^
 *   @0x308290 bne 0x2f4734 <ps_hints_apply+0x3334>
 *   @0x308294 smladhs r1, r8, pc, r11
 *   @0x308298 ldrtmi lr, [r7], -r0
 *   @0x30829c rscslt r6, pc, #72, #18
 *   @0x3082a0 stmvs r2, {r3, r8, r12, sp, pc} ^
 *   @0x3082a4 tstlt pc, #32768
 *   @0x3082a8 swplt r6, r10, [pc]
 *   @0x3082ac .word 0x463069da
 *   @0x3082b0 rfeib r3!
 *   @0x3082b4 rfeib r2!
 *   @0x3082b8 rfeib r1!
 *   @0x3082bc bl 0xff4b42cc <b2_toiTime+0xfffffffffed5ae28>
 *   @0x3082c0 rfeib r0!
 *   @0x3082c4 cdphs p0, #0x0, c10, c0, c2, #0x0
 *   @0x3082c8 rsbsmi r11, r6, #184, #30
 *   @0x3082cc beq 0x6031fc <g_SWFaavertbuff+0x30134>
 *   @0x3082d0 svceq #0xf1ba
 *   @0x3082d4 .word 0xf1cabfb8
 *   @0x3082d8 ldrmi r0, [r2, #0xa00]!
 *   @0x3082dc stmvs r2, {r9, r11, r12, lr, pc} ^
 *   @0x3082e0 bicsvs r11, r10, pc, lsr #2
 *   @0x3082e4 .word 0xf0407b10
 *   @0x3082e8 tstvc r0, #2
 *   @0x3082ec orrsvs lr, r10, r0
 *   @0x3082f0 bvs 0x19a271c <b2_toiTime+0x1249278>
 *   @0x3082f4 .word 0xd1c34291
 *   @0x3082f8 .word 0xf883b915
 *   @0x3082fc and r8, r3, r12
 *   @0x308300 blle 0x198d9c <_ZN9CInstance6AssignEPS_b+0x6b0>
 *   @0x308304 andls pc, r12, r3, lsl #17
 *   @0x308308 ldrsblt r6, [r10, -r10]
 *   @0x30830c swplt r6, r10, [r10]
 *   @0x308310 andshi pc, r12, r3, asr #17
 *   @0x308314 str r3, [lr, r12, lsr #6]!
 *   @0x308318 and r2, r6, r0, lsl #2
 *   @0x30831c .word 0xf8446a5a
 *   @0x308320 bvs 0xfe993398 <b2_toiTime+0xfffffffffe239ef4>
 *   @0x308324 addsvs r6, pc, #-1073741819
 *   @0x308328 strmi lr, [r8], -r7, ror #14
 *   @0x30832c pop {r0, r2, r3, r12, sp, pc}
 *   @0x308330 svclt #0x8ff0
 *   @0x308334 andeq r9, lr, r12, lsr r11
 *   @0x308338 svcmi #0xf0e92d
 *   @0x30833c stmdapl r4, {r6, r9, r12, sp, lr, pc} ^
 *   @0x308340 andeq pc, r2, r8, lsl #22
 *   @0x308344 cps #0x5
 *   @0x308348 eorhs r0, r12, r12, lsr #16
 *   @0x30834c .word 0x300cf8d8
 *   @0x308350 ldrsbpl pc, [r4], -r8
 *   @0x308354 andpl pc, r3, r0, lsl #22
 *   @0x308358 .word 0x53e1f44f
 *   @0x30835c andne pc, r2, #3072
 *   @0x308360 .word 0xf1029003
 *   @0x308364 bvs 0xfe50b01c <b2_toiTime+0xfffffffffddb1b78>
 *   @0x308368 .word 0xf8d22128
 *   @0x30836c .word 0xf010a02c
 *   @0x308370 ldrbmi lr, [r1], -r12, ror #24
 *   @0x308374 stc2l p7, c15, [r10, #-880]!
 *   @0x308378 svclt #0xb42820
 *   @0x30837c .word 0xf04f4684
 *   @0x308380 blls 0x3cb408 <error_g0017+0x240ac>
 *   @0x308384 suble r4, r3, #-805306359
 *   @0x308388 .word 0xf10b2600
 *   @0x30838c strbtmi r0, [r3], -r8, ror #9
 *   @0x308390 .word 0xf8db4637
 *   @0x308394 addsmi r2, r7, #216
 *   @0x308398 stmvs r2!, {r1, r2, r4, r5, r9, r12, lr, pc} ^
 *   @0x30839c ldrbeq r4, [r1, r1, lsr #13]
 *   @0x3083a0 .word 0xf8d8d52f
 *   @0x3083a4 vmov.i32 d17, #0xa8
 *   @0x3083a8 .word 0xf9950240
 *   @0x3083ac bne 0x13083e8 <b2_toiTime+0xbaef44>
 *   @0x3083b0 .word 0x41414241
 *   @0x3083b4 mlale r4, r1, r2, r4
 *   @0x3083b8 strhhs pc, [r0], -r5
 *   @0x3083bc .word 0x1c0cf854
 *   @0x3083c0 b 0xfe34ed0c <b2_toiTime+0xfffffffffdbf5868>
 *   @0x3083c4 bl 0xfeb24750 <b2_toiTime+0xfffffffffe3cb2ac>
 *   @0x3083c8 stmdavs r1!, {r0, r5, r6, r7, r12, sp, lr}
 *   @0x3083cc stmdbhs r0, {r0, r4, r6, r9, r11, r12}
 *   @0x3083d0 submi r11, r9, #184, #30
 *   @0x3083d4 ldrbmi r4, [r1], -r8, lsl #5
 *   @0x3083d8 .word 0xf1a4bfd8
 *   @0x3083dc .word 0xf8d9090c
 *   @0x3083e0 movwls r0, #0x2000
 *   @0x3083e4 .word 0xf8cd1a10
 *   @0x3083e8 stmdahs r0, {r2, lr, pc}
 *   @0x3083ec submi r11, r0, #184, #30
 *   @0x3083f0 stc2 p7, c15, [r12, #-880]!
 *   @0x3083f4 .word 0xf8dd9b02
 *   @0x3083f8 addsmi r12, r8, #4
 *   @0x3083fc .word 0x4603bfbc
 *   @0x308400 strlo r4, [r1, -lr, asr #12]
 *   @0x308404 bfi r3, r12, #4, #1
 *   @0x308408 .word 0x616eb106
 *   @0x30840c ldr r3, [r8, r12, lsr #10]!
 *   @0x308410 pop {r0, r2, r12, sp, pc}
 *   @0x308414 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x308418 bhs 0x319400 <__floatdisf+0x68>
 *   @0x30841c stmdavs sp, {r0, r1, r3, r7, r11, sp, lr} ^
 *   @0x308420 svclt #0x1868ce
 *   @0x308424 vst1.8 {d20, d21, d22}, [pc:64]!
 *   @0x308428 blx 0x3dd3b6 <error_g0017+0x3605a>
 *   @0x30842c stmdbvs r9, {r1}
 *   @0x308430 .word 0x460ebf18
 *   @0x308434 stcne p0, c3, [r7, #-160]
 *   @0x308438 mvnpl pc, #29360128
 *   @0x30843c adcmi r6, r10, #2523136
 *   @0x308440 ldmibvs r10, {r1, r8, r12, lr, pc} ^
 *   @0x308444 ldrhle r4, [lr], #-34
 *   @0x308448 .word 0xf04f463c
 *   @0x30844c orrsvs r0, sp, r0, lsl #16
 *   @0x308450 ldrdvs r6, r7, [r5], #-30
 *   @0x308454 .word 0xf8d7607e
 *   @0x308458 ldrmi r3, [r8, #0xd8]
 *   @0x30845c qsaxmi sp, r9, r3
 *   @0x308460 ldrsbeq pc, [r12], #132
 *   @0x308464 ldc2l p7, c15, [r2], #880
 *   @0x308468 ldrtmi r4, [r0], #-1577
 *   @0x30846c rsceq pc, r0, r4, asr #17
 *   @0x308470 rsceq pc, r4, r4, asr #17
 *   @0x308474 .word 0x00e8f8d4
 *   @0x308478 stc2l p7, c15, [r8], #880
 *   @0x30847c ldrsbtlo pc, [r4], #132
 *   @0x308480 .word 0xf0234629
 *   @0x308484 .word 0xf8c40301
 *   @0x308488 .word 0xf8d430f4
 *   @0x30848c ldrtmi r3, [r0], #-232
 *   @0x308490 rsceq pc, r12, r4, asr #17
 *   @0x308494 rscseq pc, r0, r4, asr #17
 *   @0x308498 ldrsbeq pc, [r12], #132
 *   @0x30849c .word 0xf7dc1ac0
 *   @0x3084a0 ldrsbtlo pc, [r0], -r5
 *   @0x3084a4 stmdale r10!, {r5, r6, r11, sp}
 *   @0x3084a8 .word 0x00e0f8d4
 *   @0x3084ac eorlo r4, r0, r9, lsr #12
 *   @0x3084b0 eorseq pc, pc, r0, lsr #32
 *   @0x3084b4 rsceq pc, r4, r4, asr #17
 *   @0x3084b8 ldc2l p7, c15, [sp], #880
 *   @0x3084bc .word 0x30e8f8d4
 *   @0x3084c0 bl 0xff3d9d6c <b2_toiTime+0xfffffffffec808c8>
 *   @0x3084c4 b 0xfe54a8cc <b2_toiTime+0xfffffffffddf1428>
 *   @0x3084c8 bl 0xfeb24874 <b2_toiTime+0xfffffffffe3cb3d0>
 *   @0x3084cc .word 0xf7dc70e9
 *   @0x3084d0 .word 0xf8d4fcbd
 *   @0x3084d4 ldmdahs pc, {r2, r5, r6, r7, sp}
 *   @0x3084d8 cps #0x6
 *   @0x3084dc .word 0xf0230320
 *   @0x3084e0 movwhs r0, #0x33f
 *   @0x3084e4 svceq #0xf1b9
 *   @0x3084e8 subsmi r11, r11, #184, #30
 *   @0x3084ec .word 0xf8c41ad3
 *   @0x3084f0 .word 0xf8d430f0
 *   @0x3084f4 .word 0xf04330f4
 *   @0x3084f8 .word 0xf8c40301
 *   @0x3084fc .word 0xf10830f4
 *   @0x308500 ldrlo r0, [r12], #-2049
 *   @0x308504 pop {r0, r1, r2, r5, r7, r8, r9, r10, sp, lr, pc}
 *   @0x308508 ldrblt r8, [r8, #0x3f8]!
 *   @0x30850c strmi r4, [r7], -sp, lsl #12
 *   @0x308510 stcne p6, c4, [r4, #-56]
 *   @0x308514 strgt r12, [pc], #-3343
 *   @0x308518 muleq r7, r5, r8
 *   @0x30851c andeq lr, r7, r4, lsl #17
 *   @0x308520 shasxmi r4, r1, r8
 *   @0x308524 .word 0xf7ff2200
 *   @0x308528 shsub16mi pc, r8, r6
 *   @0x30852c andhs r4, r1, #51380224
 *   @0x308530 ldrhtmi lr, [r8], #141
 *   @0x308534 svclt #0x6ff7ff
 *   @0x308538 svclt #0xe7f7ff
 *   @0x30853c svcmi #0xf7e92d
 *   @0x308540 stmdbeq r0, {r1, r4, r5, r7, r8, r12, sp, lr, pc}
 *   @0x308544 blo 0xffd44e54 <b2_toiTime+0xffffffffff5eb9b0>
 *   @0x308548 blx 0x5a277e <g_SWFlineaavertbuff+0x4f6b6>
 *   @0x30854c stmdavs r12, {r0, r3, r9, r11} ^
 *   @0x308550 strmi r6, [r5], -pc, asr #17
 *   @0x308554 sadd16mi r11, r12, r8
 *   @0x308558 .word 0xf10a6909
 *   @0x30855c .word 0xf10a0a28
 *   @0x308560 svclt #0x180604
 *   @0x308564 .word 0xf506460f
 *   @0x308568 bvs 0x99d1ac <b2_toiTime+0x243d08>
 *   @0x30856c smlatble r3, r2, r2, r4
 *   @0x308570 adcsmi r6, r10, #368640
 *   @0x308574 .word 0x810ef000
 *   @0x308578 ldmdapl r0, {r0, r2, r8, r10, r12, sp, lr, pc}
 *   @0x30857c .word 0xf108621c
 *   @0x308580 subsvs r0, pc, #20, #16
 *   @0x308584 movwhs r2, #0x24
 *   @0x308588 ldrsbne pc, [r8], #136
 *   @0x30858c subsle r4, r11, r11, lsl #5
 *   @0x308590 .word 0xf203fb00
 *   @0x308594 vmlaeq.f64 d14, d2, d8
 *   @0x308598 ldrsbt pc, [r12], #142
 *   @0x30859c svceq #0x10f01e
 *   @0x3085a0 strbmi sp, [r2], #-13
 *   @0x3085a4 .word 0xf8d24621
 *   @0x3085a8 .word 0xf7fe00e8
 *   @0x3085ac stmdavs r11!, {r0, r1, r2, r3, r4, r5, r6, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x3085b0 ldmibhi r9, {r0, r1, r3, r4, r7, r8, r10, r11, sp, lr}
 *   @0x3085b4 ldmvs r11, {r0, r1, r3, r5, r6, r9, r11, sp, lr} ^
 *   @0x3085b8 ldmdblt r3, {r1, r9, r10, lr}
 *   @0x3085bc movwlo lr, #0x1008
 *   @0x3085c0 addsmi lr, r9, #228, #14
 *   @0x3085c4 stmdbhs r5, {r2, r11, r12, lr, pc}
 *   @0x3085c8 teqhs r4, r12, lsl #31
 *   @0x3085cc and r2, r0, r8, lsr #2
 *   @0x3085d0 ldrmi r2, [r1], #-296
 *   @0x3085d4 teqeq pc, r1, lsr #32
 *   @0x3085d8 eorsle r4, r5, r10, lsl #5
 *   @0x3085dc svceq #0x1f1b9
 *   @0x3085e0 qasxmi sp, r0, r2
 *   @0x3085e4 blx 0xfedc655e <b2_toiTime+0xfffffffffe66d0ba>
 *   @0x3085e8 ldrsbhs pc, [r8], #136
 *   @0x3085ec .word 0xf04f6aab
 *   @0x3085f0 blx 0x68be8a <g_SWFlinevertbuff+0x38dc2>
 *   @0x3085f4 andhs pc, r0, #2, #28
 *   @0x3085f8 ldrbmi r4, [r2, #-0x683]!
 *   @0x3085fc bl 0x53c63c <obj_has_event+0x1acc>
 *   @0x308600 eorlo r0, r4, #2
 *   @0x308604 ldrsbtne pc, [r8], #128
 *   @0x308608 ldrsbteq pc, [r4], #128
 *   @0x30860c addmi r4, r1, #-1879048188
 *   @0x308610 .word 0x4601bfb8
 *   @0x308614 svclt #0xb8428b
 *   @0x308618 strb r4, [lr, r11, lsl #12]!
 *   @0x30861c stmdaeq r11, {r2, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x308620 movwls r4, #0x1618
 *   @0x308624 .word 0xf7fe4641
 *   @0x308628 blls 0x387f34 <_ZTS13C_UTF16String+0x1efe0>
 *   @0x30862c stmdahs r0, {r0, r6, r9, r10, lr}
 *   @0x308630 ble 0x3d9e98 <error_g0017+0x32b3c>
 *   @0x308634 mrc2 p7, #0x1, apsr_nzcv, c10, c14, #0x7
 *   @0x308638 and r4, r1, r0, asr #4
 *   @0x30863c mrc2 p7, #0x1, apsr_nzcv, c6, c14, #0x7
 *   @0x308640 cmneq pc, #48
 *   @0x308644 ldrbmi r11, [r12], -r8, lsl #30
 *   @0x308648 andmi pc, r4, r10, asr #17
 *   @0x30864c .word 0xf1b96077
 *   @0x308650 .word 0xd1020f00
 *   @0x308654 smulwbvs pc, r12, r0
 *   @0x308658 rscvs lr, r12, r1
 *   @0x30865c ldrtmi r6, [r5], -pc, ror #2
 *   @0x308660 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x308664 ldrmi r6, [r8, #0x8b3]
 *   @0x308668 stmvs r8!, {r0, r3, r9, r12, lr, pc} ^
 *   @0x30866c .word 0xf7fe4621
 *   @0x308670 .word 0xf108fe1d
 *   @0x308674 strlo r0, [r12, #-0x801]
 *   @0x308678 adcvs r6, r8, r8, rrx
 *   @0x30867c .word 0xf8d6e7f2
 *   @0x308680 .word 0x462100d0
 *   @0x308684 mrc2 p7, #0x0, apsr_nzcv, c2, c14, #0x7
 *   @0x308688 svclt #0xcc2827
 *   @0x30868c andhs r2, r1, r0
 *   @0x308690 svceq #0x1f1b9
 *   @0x308694 sbcseq pc, r4, r6, lsl #17
 *   @0x308698 shsub16mi sp, r5, r12
 *   @0x30869c stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x3086a0 ldrsblo pc, [r8], #134
 *   @0x3086a4 suble r4, r8, #152, #10
 *   @0x3086a8 .word 0xf8d54621
 *   @0x3086ac .word 0xf7fe00dc
 *   @0x3086b0 qsub8mi pc, r1, sp
 *   @0x3086b4 .word 0xf8c54438
 *   @0x3086b8 .word 0xf8c500e0
 *   @0x3086bc .word 0xf8d500e4
 *   @0x3086c0 .word 0xf7fe00e8
 *   @0x3086c4 .word 0xf8d5fdf3
 *   @0x3086c8 qsub8mi r3, r1, r12
 *   @0x3086cc movweq pc, #0x1023
 *   @0x3086d0 rscslo pc, r12, r5, asr #17
 *   @0x3086d4 .word 0x30e8f8d5
 *   @0x3086d8 .word 0xf8c54438
 *   @0x3086dc .word 0xf8c500ec
 *   @0x3086e0 .word 0xf8d500f0
 *   @0x3086e4 bne 0xff308a5c <b2_toiTime+0xfffffffffebaf5b8>
 *   @0x3086e8 stc2l p7, c15, [r0, #1016]!
 *   @0x3086ec teqeq r0, #0, #2
 *   @0x3086f0 ldmdale lr, {r5, r6, r8, r9, r11, sp}
 *   @0x3086f4 mvnvc lr, #128, #20
 *   @0x3086f8 mvnvc lr, #166912
 *   @0x3086fc vstrle d2, [r4, #-124]
 *   @0x308700 svclt #0xc2b30
 *   @0x308704 .word 0x23202340
 *   @0x308708 movwhs lr, #0x0
 *   @0x30870c .word 0x20e0f8d5
 *   @0x308710 svclt #0xb82800
 *   @0x308714 eorlo r4, r0, #-1342177275
 *   @0x308718 eorseq pc, pc, #34
 *   @0x30871c rschs pc, r4, r5, asr #17
 *   @0x308720 .word 0xf8c51ad3
 *   @0x308724 .word 0xf8d530f0
 *   @0x308728 .word 0xf04330fc
 *   @0x30872c .word 0xf8c50301
 *   @0x308730 .word 0xf10830fc
 *   @0x308734 strlo r0, [r4, #-0x801]!
 *   @0x308738 .word 0x4633e7b2
 *   @0x30873c .word 0xf8d62100
 *   @0x308740 strbmi r12, [r1, #-0xd8]!
 *   @0x308744 .word 0xf8d3d226
 *   @0x308748 .word 0xf00770fc
 *   @0x30874c bhs 0x448f68 <g_RomDisk+0x51748>
 *   @0x308750 shadd16mi sp, r2, sp
 *   @0x308754 strbmi r2, [r0, #-0x0]!
 *   @0x308758 .word 0xf8d2d019
 *   @0x30875c .word 0x076c50fc
 *   @0x308760 .word 0x07ecd412
 *   @0x308764 .word 0xf8d2d510
 *   @0x308768 .word 0xf8d340e4
 *   @0x30876c adcmi r5, r12, #240
 *   @0x308770 .word 0xf8d2dc0a
 *   @0x308774 .word 0xf8d340f0
 *   @0x308778 adcmi r5, r12, #228
 *   @0x30877c .word 0xf027db04
 *   @0x308780 .word 0xf8c30201
 *   @0x308784 strd r2, r3, [r2], -r12
 *   @0x308788 eorlo r3, r4, #1
 *   @0x30878c smlattlo r1, r3, r7, lr
 *   @0x308790 ldrb r3, [r4, r4, lsr #6]
 *   @0x308794 pop {r0, r1, r12, sp, pc}
 *   @0x308798 ldrlt r8, [r8, #-0xff0]!
 *   @0x30879c stmdbvs r11, {r9, sp} ^
 *   @0x3087a0 strmi r4, [r12], -r5, lsl #12
 *   @0x3087a4 stmdavs r11, {r0, r1, r7, r8, sp, lr}
 *   @0x3087a8 stmibvs r11, {r0, r1, r6, sp, lr}
 *   @0x3087ac .word 0xf7ff61c3
 *   @0x3087b0 strtmi pc, [r8], -r5, asr #29
 *   @0x3087b4 andhs r4, r1, #34603008
 *   @0x3087b8 ldrhtmi lr, [r8], -sp
 *   @0x3087bc mrclt p7, #0x5, apsr_nzcv, c14, c15, #0x7
 *
 * ══ §3/13 anon_2bc92c  0x2bc92c  size 4208  1052 条（0x2bc92c..0x2bd99c）
 * @func 0x2bc92c 0x2bd99c  size 4208  1052 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×10 / anon_2bc92c×2 / anon_2bc92c+0x2c8×2 / __aeabi_uidivmod×2 / anon_2bc92c+0xd6c×2 / anon_2bc92c+0x28 / anon_2bc92c+0xd8 / anon_2bc92c+0x208
 * 字段偏移 top8: 0xc×40 / 0x14×29 / 0x8×29 / 0x4×24 / 0x10×23 / 0x20×22 / 0x24×19 / 0x1c×18
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bc92c ldr r2, [r0, #0x124]
 *   @0x2bc930 ldr r3, [r0, #0x188]
 *   @0x2bc934 cmp r2, #1
 *   @0x2bc938 ble 0x2bc954 <jpeg_alloc_huff_table+0x4c>
 *   @0x2bc93c mov r2, #1
 *   @0x2bc940 str r2, [r3, #0x1c]
 *   @0x2bc944 mov r2, #0
 *   @0x2bc948 str r2, [r3, #0x14]
 *   @0x2bc94c str r2, [r3, #0x18]
 *   @0x2bc950 bx lr
 *   @0x2bc954 ldr r2, [r0, #0x11c]
 *   @0x2bc958 ldr r1, [r0, #0x80]
 *   @0x2bc95c sub r2, r2, #1
 *   @0x2bc960 cmp r1, r2
 *   @0x2bc964 ldr r2, [r0, #0x128]
 *   @0x2bc968 ldrlo r2, [r2, #0xc]
 *   @0x2bc96c ldrhs r2, [r2, #0x48]
 *   @0x2bc970 str r2, [r3, #0x1c]
 *   @0x2bc974 b 0x2bc944 <jpeg_alloc_huff_table+0x3c>
 *   @0x2bc978 mov r2, #0
 *   @0x2bc97c str r2, [r0, #0x80]
 *   @0x2bc980 b 0x2bc92c <jpeg_alloc_huff_table+0x24>
 *   @0x2bc984 mov r0, #0
 *   @0x2bc988 bx lr
 *   @0x2bc98c ldr r3, [r0, #0x124]
 *   @0x2bc990 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bc994 cmp r3, #0
 *   @0x2bc998 sub sp, sp, #52
 *   @0x2bc99c mov r11, r0
 *   @0x2bc9a0 ldr r6, [r0, #0x188]
 *   @0x2bc9a4 ble 0x2bca04 <jpeg_alloc_huff_table+0xfc>
 *   @0x2bc9a8 add r8, sp, #32
 *   @0x2bc9ac mov r5, r0
 *   @0x2bc9b0 mov r4, #0
 *   @0x2bc9b4 mov r7, #1
 *   @0x2bc9b8 ldr r3, [r5, #0x128]
 *   @0x2bc9bc mov r0, r11
 *   @0x2bc9c0 ldr lr, [r11, #0x80]
 *   @0x2bc9c4 add r5, r5, #4
 *   @0x2bc9c8 ldr r12, [r11, #0x4]
 *   @0x2bc9cc ldr r1, [r3, #0x4]
 *   @0x2bc9d0 ldr r2, [r3, #0xc]
 *   @0x2bc9d4 add r3, r1, #18
 *   @0x2bc9d8 ldr r1, [r6, r3, lsl #2]
 *   @0x2bc9dc mov r3, r2
 *   @0x2bc9e0 str r7, [sp]
 *   @0x2bc9e4 mul r2, lr, r2
 *   @0x2bc9e8 ldr r12, [r12, #0x20]
 *   @0x2bc9ec blx r12
 *   @0x2bc9f0 ldr r3, [r11, #0x124]
 *   @0x2bc9f4 str r0, [r8, r4, lsl #2]
 *   @0x2bc9f8 add r4, r4, #1
 *   @0x2bc9fc cmp r3, r4
 *   @0x2bca00 bgt 0x2bc9b8 <jpeg_alloc_huff_table+0xb0>
 *   @0x2bca04 ldr r2, [r6, #0x18]
 *   @0x2bca08 str r2, [sp, #0x10]
 *   @0x2bca0c ldr r3, [sp, #0x10]
 *   @0x2bca10 ldr r2, [r6, #0x1c]
 *   @0x2bca14 cmp r3, r2
 *   @0x2bca18 bge 0x2bcb88 <jpeg_alloc_huff_table+0x280>
 *   @0x2bca1c ldr r3, [r6, #0x14]
 *   @0x2bca20 add r1, r6, #32
 *   @0x2bca24 str r11, [sp, #0x18]
 *   @0x2bca28 str r1, [sp, #0x1c]
 *   @0x2bca2c str r3, [sp, #0xc]
 *   @0x2bca30 ldr r3, [sp, #0x10]
 *   @0x2bca34 lsl r3, r3, #2
 *   @0x2bca38 str r3, [sp, #0x14]
 *   @0x2bca3c ldr r3, [r11, #0x138]
 *   @0x2bca40 ldr r1, [sp, #0xc]
 *   @0x2bca44 cmp r3, r1
 *   @0x2bca48 bls 0x2bcb34 <jpeg_alloc_huff_table+0x22c>
 *   @0x2bca4c ldr r3, [sp, #0x18]
 *   @0x2bca50 ldr r11, [r3, #0x124]
 *   @0x2bca54 cmp r11, #0
 *   @0x2bca58 ble 0x2bcaf4 <jpeg_alloc_huff_table+0x1ec>
 *   @0x2bca5c mov r9, #0
 *   @0x2bca60 lsl r11, r11, #2
 *   @0x2bca64 mov lr, r9
 *   @0x2bca68 mov r10, r3
 *   @0x2bca6c ldr r3, [r10, #0x128]
 *   @0x2bca70 ldr r2, [r3, #0x38]
 *   @0x2bca74 ldr r4, [r3, #0x34]
 *   @0x2bca78 cmp r2, #0
 *   @0x2bca7c ble 0x2bcae4 <jpeg_alloc_huff_table+0x1dc>
 *   @0x2bca80 ldr r3, [sp, #0x10]
 *   @0x2bca84 lsl r8, r4, #7
 *   @0x2bca88 add r2, r3, r2
 *   @0x2bca8c ldr r3, [sp, #0xc]
 *   @0x2bca90 mul r7, r3, r8
 *   @0x2bca94 add r3, sp, #32
 *   @0x2bca98 ldr r12, [r9, r3]
 *   @0x2bca9c add r5, r12, r2, lsl #2
 *   @0x2bcaa0 ldr r2, [sp, #0x14]
 *   @0x2bcaa4 add r12, r12, r2
 *   @0x2bcaa8 ldr r3, [r12], #4
 *   @0x2bcaac cmp r4, #0
 *   @0x2bcab0 add r3, r3, r7
 *   @0x2bcab4 ble 0x2bcadc <jpeg_alloc_huff_table+0x1d4>
 *   @0x2bcab8 add r1, lr, #7
 *   @0x2bcabc add r0, r3, r8
 *   @0x2bcac0 add r1, r6, r1, lsl #2
 *   @0x2bcac4 add r2, r3, #128
 *   @0x2bcac8 str r3, [r1, #0x4]!
 *   @0x2bcacc cmp r2, r0
 *   @0x2bcad0 mov r3, r2
 *   @0x2bcad4 bne 0x2bcac4 <jpeg_alloc_huff_table+0x1bc>
 *   @0x2bcad8 add lr, r4, lr
 *   @0x2bcadc cmp r12, r5
 *   @0x2bcae0 bne 0x2bcaa8 <jpeg_alloc_huff_table+0x1a0>
 *   @0x2bcae4 add r9, r9, #4
 *   @0x2bcae8 add r10, r10, #4
 *   @0x2bcaec cmp r9, r11
 *   @0x2bcaf0 bne 0x2bca6c <jpeg_alloc_huff_table+0x164>
 *   @0x2bcaf4 ldr r2, [sp, #0x18]
 *   @0x2bcaf8 ldr r1, [sp, #0x1c]
 *   @0x2bcafc ldr r3, [r2, #0x198]
 *   @0x2bcb00 mov r0, r2
 *   @0x2bcb04 ldr r3, [r3, #0x4]
 *   @0x2bcb08 blx r3
 *   @0x2bcb0c cmp r0, #0
 *   @0x2bcb10 beq 0x2bcb6c <jpeg_alloc_huff_table+0x264>
 *   @0x2bcb14 ldr r2, [sp, #0x18]
 *   @0x2bcb18 ldr r3, [r2, #0x138]
 *   @0x2bcb1c ldr r2, [sp, #0xc]
 *   @0x2bcb20 add r2, r2, #1
 *   @0x2bcb24 str r2, [sp, #0xc]
 *   @0x2bcb28 cmp r3, r2
 *   @0x2bcb2c bhi 0x2bca4c <jpeg_alloc_huff_table+0x144>
 *   @0x2bcb30 ldr r2, [r6, #0x1c]
 *   @0x2bcb34 ldr r1, [sp, #0x10]
 *   @0x2bcb38 add r1, r1, #1
 *   @0x2bcb3c str r1, [sp, #0x10]
 *   @0x2bcb40 mov r1, #0
 *   @0x2bcb44 str r1, [r6, #0x14]
 *   @0x2bcb48 ldr r1, [sp, #0x10]
 *   @0x2bcb4c cmp r2, r1
 *   @0x2bcb50 ldr r1, [sp, #0x14]
 *   @0x2bcb54 add r1, r1, #4
 *   @0x2bcb58 str r1, [sp, #0x14]
 *   @0x2bcb5c ble 0x2bcb84 <jpeg_alloc_huff_table+0x27c>
 *   @0x2bcb60 mov r1, #0
 *   @0x2bcb64 str r1, [sp, #0xc]
 *   @0x2bcb68 b 0x2bca40 <jpeg_alloc_huff_table+0x138>
 *   @0x2bcb6c ldr r3, [sp, #0x10]
 *   @0x2bcb70 ldr r2, [sp, #0xc]
 *   @0x2bcb74 str r3, [r6, #0x18]
 *   @0x2bcb78 str r2, [r6, #0x14]
 *   @0x2bcb7c add sp, sp, #52
 *   @0x2bcb80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bcb84 ldr r11, [sp, #0x18]
 *   @0x2bcb88 ldr r3, [r11, #0x80]
 *   @0x2bcb8c ldr r2, [r11, #0x11c]
 *   @0x2bcb90 add r3, r3, #1
 *   @0x2bcb94 str r3, [r11, #0x80]
 *   @0x2bcb98 cmp r3, r2
 *   @0x2bcb9c bhs 0x2bcbb4 <jpeg_alloc_huff_table+0x2ac>
 *   @0x2bcba0 mov r0, r11
 *   @0x2bcba4 bl 0x2bc92c <jpeg_alloc_huff_table+0x24>
 *   @0x2bcba8 mov r0, #3
 *   @0x2bcbac add sp, sp, #52
 *   @0x2bcbb0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bcbb4 ldr r3, [r11, #0x190]
 *   @0x2bcbb8 mov r0, r11
 *   @0x2bcbbc ldr r3, [r3, #0xc]
 *   @0x2bcbc0 blx r3
 *   @0x2bcbc4 mov r0, #4
 *   @0x2bcbc8 add sp, sp, #52
 *   @0x2bcbcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bcbd0 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2bcbd4 mov r6, r0
 *   @0x2bcbd8 ldr r7, [r0, #0x188]
 *   @0x2bcbdc ldr r3, [r7, #0x10]
 *   @0x2bcbe0 cmp r3, #0
 *   @0x2bcbe4 beq 0x2bcc00 <jpeg_alloc_huff_table+0x2f8>
 *   @0x2bcbe8 ldrb r3, [r0, #0x49]
 *   @0x2bcbec cmp r3, #0
 *   @0x2bcbf0 bne 0x2bcc0c <jpeg_alloc_huff_table+0x304>
 *   @0x2bcbf4 ldr r3, [pc, #0x174]
 *   @0x2bcbf8 add r3, pc, r3
 *   @0x2bcbfc str r3, [r7, #0xc]
 *   @0x2bcc00 mov r3, #0
 *   @0x2bcc04 str r3, [r6, #0x88]
 *   @0x2bcc08 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2bcc0c ldrb r3, [r0, #0xc8]
 *   @0x2bcc10 cmp r3, #0
 *   @0x2bcc14 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcc18 ldr r3, [r0, #0x8c]
 *   @0x2bcc1c cmp r3, #0
 *   @0x2bcc20 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcc24 ldr r9, [r7, #0x70]
 *   @0x2bcc28 cmp r9, #0
 *   @0x2bcc2c beq 0x2bcd48 <jpeg_alloc_huff_table+0x440>
 *   @0x2bcc30 ldr r3, [r6, #0x24]
 *   @0x2bcc34 ldr r8, [r6, #0xc4]
 *   @0x2bcc38 cmp r3, #0
 *   @0x2bcc3c ble 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcc40 ldr r3, [r8, #0x4c]
 *   @0x2bcc44 cmp r3, #0
 *   @0x2bcc48 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcc4c ldrh r2, [r3]
 *   @0x2bcc50 cmp r2, #0
 *   @0x2bcc54 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcc58 ldrh r2, [r3, #2]
 *   @0x2bcc5c cmp r2, #0
 *   @0x2bcc60 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcc64 ldrh r2, [r3, #16]
 *   @0x2bcc68 cmp r2, #0
 *   @0x2bcc6c beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcc70 ldrh r2, [r3, #32]
 *   @0x2bcc74 cmp r2, #0
 *   @0x2bcc78 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcc7c mov r4, #0
 *   @0x2bcc80 mov r0, r4
 *   @0x2bcc84 ldrh r2, [r3, #18]
 *   @0x2bcc88 cmp r2, #0
 *   @0x2bcc8c beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcc90 ldrh r3, [r3, #4]
 *   @0x2bcc94 cmp r3, #0
 *   @0x2bcc98 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcc9c ldr r3, [r6, #0x8c]
 *   @0x2bcca0 add r2, r3, r0, lsl #8
 *   @0x2bcca4 ldr r3, [r3, r0, lsl #8]
 *   @0x2bcca8 cmp r3, #0
 *   @0x2bccac blt 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bccb0 mov r12, r9
 *   @0x2bccb4 mov r1, r2
 *   @0x2bccb8 mov r3, #5
 *   @0x2bccbc ldr r5, [r2, #0x4]!
 *   @0x2bccc0 str r5, [r12, #0x4]!
 *   @0x2bccc4 ldr r5, [r1, #0x4]!
 *   @0x2bccc8 cmp r5, #0
 *   @0x2bcccc movne r4, #1
 *   @0x2bccd0 subs r3, r3, #1
 *   @0x2bccd4 bne 0x2bccbc <jpeg_alloc_huff_table+0x3b4>
 *   @0x2bccd8 ldr r3, [r6, #0x24]
 *   @0x2bccdc add r0, r0, #1
 *   @0x2bcce0 add r9, r9, #24
 *   @0x2bcce4 add r8, r8, #84
 *   @0x2bcce8 cmp r0, r3
 *   @0x2bccec bge 0x2bcd30 <jpeg_alloc_huff_table+0x428>
 *   @0x2bccf0 ldr r3, [r8, #0x4c]
 *   @0x2bccf4 cmp r3, #0
 *   @0x2bccf8 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bccfc ldrh r2, [r3]
 *   @0x2bcd00 cmp r2, #0
 *   @0x2bcd04 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcd08 ldrh r2, [r3, #2]
 *   @0x2bcd0c cmp r2, #0
 *   @0x2bcd10 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcd14 ldrh r2, [r3, #16]
 *   @0x2bcd18 cmp r2, #0
 *   @0x2bcd1c beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcd20 ldrh r2, [r3, #32]
 *   @0x2bcd24 cmp r2, #0
 *   @0x2bcd28 bne 0x2bcc84 <jpeg_alloc_huff_table+0x37c>
 *   @0x2bcd2c b 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcd30 cmp r4, #0
 *   @0x2bcd34 beq 0x2bcbf4 <jpeg_alloc_huff_table+0x2ec>
 *   @0x2bcd38 ldr r3, [pc, #0x34]
 *   @0x2bcd3c add r3, pc, r3
 *   @0x2bcd40 str r3, [r7, #0xc]
 *   @0x2bcd44 b 0x2bcc00 <jpeg_alloc_huff_table+0x2f8>
 *   @0x2bcd48 ldr r3, [r0, #0x24]
 *   @0x2bcd4c mov r1, #1
 *   @0x2bcd50 ldr r12, [r0, #0x4]
 *   @0x2bcd54 add r2, r3, r3, lsl #1
 *   @0x2bcd58 ldr r12, [r12]
 *   @0x2bcd5c lsl r2, r2, #3
 *   @0x2bcd60 blx r12
 *   @0x2bcd64 mov r9, r0
 *   @0x2bcd68 str r0, [r7, #0x70]
 *   @0x2bcd6c b 0x2bcc30 <jpeg_alloc_huff_table+0x328>
 *   @0x2bcd70 ldrdeq r0, r1, [r0], -r8
 *   @0x2bcd74 andeq r0, r0, r4, lsr r0
 *   @0x2bcd78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bcd7c sub sp, sp, #292
 *   @0x2bcd80 ldr r4, [r0, #0x188]
 *   @0x2bcd84 mov r6, r0
 *   @0x2bcd88 str r0, [sp, #0x38]
 *   @0x2bcd8c str r1, [sp, #0x98]
 *   @0x2bcd90 str r4, [sp, #0x94]
 *   @0x2bcd94 ldr r4, [r0, #0x11c]
 *   @0x2bcd98 b 0x2bcde4 <jpeg_alloc_huff_table+0x4dc>
 *   @0x2bcd9c ldr r1, [r6, #0x190]
 *   @0x2bcda0 ldrb r12, [r1, #0x11]
 *   @0x2bcda4 cmp r12, #0
 *   @0x2bcda8 bne 0x2bcdf8 <jpeg_alloc_huff_table+0x4f0>
 *   @0x2bcdac cmp r3, r2
 *   @0x2bcdb0 bne 0x2bcdd4 <jpeg_alloc_huff_table+0x4cc>
 *   @0x2bcdb4 ldr r5, [r6, #0x88]
 *   @0x2bcdb8 ldr r3, [r6, #0x16c]
 *   @0x2bcdbc ldr r2, [r6, #0x80]
 *   @0x2bcdc0 cmp r3, #0
 *   @0x2bcdc4 movne r3, r5
 *   @0x2bcdc8 addeq r3, r5, #1
 *   @0x2bcdcc cmp r2, r3
 *   @0x2bcdd0 bhi 0x2bce00 <jpeg_alloc_huff_table+0x4f8>
 *   @0x2bcdd4 ldr r3, [r1]
 *   @0x2bcdd8 blx r3
 *   @0x2bcddc cmp r0, #0
 *   @0x2bcde0 beq 0x2bd344 <jpeg_alloc_huff_table+0xa3c>
 *   @0x2bcde4 ldr r3, [r6, #0x7c]
 *   @0x2bcde8 mov r0, r6
 *   @0x2bcdec ldr r2, [r6, #0x84]
 *   @0x2bcdf0 cmp r3, r2
 *   @0x2bcdf4 ble 0x2bcd9c <jpeg_alloc_huff_table+0x494>
 *   @0x2bcdf8 ldr r12, [sp, #0x38]
 *   @0x2bcdfc ldr r5, [r12, #0x88]
 *   @0x2bce00 ldr r12, [sp, #0x38]
 *   @0x2bce04 ldr r2, [r12, #0x24]
 *   @0x2bce08 ldr r12, [r12, #0xc4]
 *   @0x2bce0c cmp r2, #0
 *   @0x2bce10 str r12, [sp, #0xc]
 *   @0x2bce14 ble 0x2bd328 <jpeg_alloc_huff_table+0xa20>
 *   @0x2bce18 sub r4, r4, #1
 *   @0x2bce1c str r4, [sp, #0x9c]
 *   @0x2bce20 mov r4, #0
 *   @0x2bce24 str r4, [sp, #0x88]
 *   @0x2bce28 ldr r4, [sp, #0x94]
 *   @0x2bce2c add r12, sp, #160
 *   @0x2bce30 str r12, [sp, #0x1c]
 *   @0x2bce34 str r4, [sp, #0x90]
 *   @0x2bce38 ldr r12, [sp, #0xc]
 *   @0x2bce3c ldrb r3, [r12, #0x30]
 *   @0x2bce40 cmp r3, #0
 *   @0x2bce44 beq 0x2bd2fc <jpeg_alloc_huff_table+0x9f4>
 *   @0x2bce48 ldr r4, [sp, #0x9c]
 *   @0x2bce4c cmp r4, r5
 *   @0x2bce50 bls 0x2bd450 <jpeg_alloc_huff_table+0xb48>
 *   @0x2bce54 ldr r4, [r12, #0xc]
 *   @0x2bce58 mov r12, #0
 *   @0x2bce5c str r12, [sp, #0x80]
 *   @0x2bce60 cmp r5, #0
 *   @0x2bce64 ldr r12, [sp, #0x90]
 *   @0x2bce68 str r4, [sp, #0x7c]
 *   @0x2bce6c lsl r3, r4, #1
 *   @0x2bce70 ldr r1, [r12, #0x48]
 *   @0x2bce74 beq 0x2bd498 <jpeg_alloc_huff_table+0xb90>
 *   @0x2bce78 ldr lr, [sp, #0x38]
 *   @0x2bce7c sub r2, r5, #1
 *   @0x2bce80 add r3, r4, r3
 *   @0x2bce84 mov r0, #0
 *   @0x2bce88 mul r2, r2, r4
 *   @0x2bce8c ldr r12, [lr, #0x4]
 *   @0x2bce90 str r0, [sp]
 *   @0x2bce94 mov r0, lr
 *   @0x2bce98 mov r6, #0
 *   @0x2bce9c ldr r12, [r12, #0x20]
 *   @0x2bcea0 blx r12
 *   @0x2bcea4 ldr r4, [sp, #0xc]
 *   @0x2bcea8 ldr r5, [r4, #0xc]
 *   @0x2bceac add r5, r0, r5, lsl #2
 *   @0x2bceb0 ldr r12, [sp, #0x38]
 *   @0x2bceb4 ldr r4, [sp, #0x7c]
 *   @0x2bceb8 ldr r1, [r12, #0x19c]
 *   @0x2bcebc cmp r4, #0
 *   @0x2bcec0 ldr r12, [sp, #0xc]
 *   @0x2bcec4 ldr r4, [sp, #0x88]
 *   @0x2bcec8 ldr r3, [r12, #0x4c]
 *   @0x2bcecc ldr r12, [sp, #0x94]
 *   @0x2bced0 add r1, r1, r4, lsl #2
 *   @0x2bced4 add r2, r4, r4, lsl #1
 *   @0x2bced8 ldr r1, [r1, #0x4]
 *   @0x2bcedc ldr r0, [r12, #0x70]
 *   @0x2bcee0 ldr r12, [sp, #0x98]
 *   @0x2bcee4 add r11, r0, r2, lsl #3
 *   @0x2bcee8 str r1, [sp, #0x3c]
 *   @0x2bceec ldrh r0, [r3, #16]
 *   @0x2bcef0 ldr r4, [r12, r4, lsl #2]
 *   @0x2bcef4 ldrh r1, [r3, #32]
 *   @0x2bcef8 ldrh r12, [r3, #2]
 *   @0x2bcefc str r4, [sp, #0x2c]
 *   @0x2bcf00 ldrh r2, [r3, #18]
 *   @0x2bcf04 ldrh r4, [r3]
 *   @0x2bcf08 ldrh r3, [r3, #4]
 *   @0x2bcf0c ble 0x2bd2f0 <jpeg_alloc_huff_table+0x9e8>
 *   @0x2bcf10 add lr, r4, r4, lsl #3
 *   @0x2bcf14 add r4, r4, r4, lsl #2
 *   @0x2bcf18 str r4, [sp, #0x68]
 *   @0x2bcf1c lsl r4, r12, #7
 *   @0x2bcf20 lsl r12, r12, #8
 *   @0x2bcf24 str r12, [sp, #0x54]
 *   @0x2bcf28 lsl r12, r0, #7
 *   @0x2bcf2c str r12, [sp, #0x58]
 *   @0x2bcf30 lsl r12, r2, #7
 *   @0x2bcf34 str r12, [sp, #0x6c]
 *   @0x2bcf38 ldr r12, [sp, #0x7c]
 *   @0x2bcf3c sub r5, r5, #4
 *   @0x2bcf40 str r4, [sp, #0x50]
 *   @0x2bcf44 lsl r0, r0, #8
 *   @0x2bcf48 lsl r4, lr, #2
 *   @0x2bcf4c lsl r2, r2, #8
 *   @0x2bcf50 str r4, [sp, #0x44]
 *   @0x2bcf54 sub r12, r12, #1
 *   @0x2bcf58 lsl r4, r1, #7
 *   @0x2bcf5c str lr, [sp, #0x40]
 *   @0x2bcf60 str r4, [sp, #0x60]
 *   @0x2bcf64 lsl r1, r1, #8
 *   @0x2bcf68 lsl r4, r3, #7
 *   @0x2bcf6c str r5, [sp, #0x4c]
 *   @0x2bcf70 str r4, [sp, #0x74]
 *   @0x2bcf74 lsl r3, r3, #8
 *   @0x2bcf78 mov r4, #0
 *   @0x2bcf7c str r0, [sp, #0x5c]
 *   @0x2bcf80 str r1, [sp, #0x64]
 *   @0x2bcf84 str r2, [sp, #0x70]
 *   @0x2bcf88 str r3, [sp, #0x78]
 *   @0x2bcf8c str r12, [sp, #0x8c]
 *   @0x2bcf90 str r6, [sp, #0x84]
 *   @0x2bcf94 str r4, [sp, #0x48]
 *   @0x2bcf98 ldr r4, [sp, #0x4c]
 *   @0x2bcf9c ldr r12, [sp, #0x48]
 *   @0x2bcfa0 ldr r3, [sp, #0x84]
 *   @0x2bcfa4 ldr r5, [r4, #0x4]!
 *   @0x2bcfa8 cmp r12, #0
 *   @0x2bcfac movne r3, #0
 *   @0x2bcfb0 andeq r3, r3, #1
 *   @0x2bcfb4 cmp r3, #0
 *   @0x2bcfb8 str r4, [sp, #0x4c]
 *   @0x2bcfbc ldreq r12, [r4, #-0x4]
 *   @0x2bcfc0 ldr r4, [sp, #0x80]
 *   @0x2bcfc4 strne r5, [sp, #0x34]
 *   @0x2bcfc8 streq r12, [sp, #0x34]
 *   @0x2bcfcc cmp r4, #0
 *   @0x2bcfd0 beq 0x2bcfe4 <jpeg_alloc_huff_table+0x6dc>
 *   @0x2bcfd4 ldr r12, [sp, #0x8c]
 *   @0x2bcfd8 ldr r4, [sp, #0x48]
 *   @0x2bcfdc cmp r12, r4
 *   @0x2bcfe0 beq 0x2bd4d0 <jpeg_alloc_huff_table+0xbc8>
 *   @0x2bcfe4 ldr r12, [sp, #0x4c]
 *   @0x2bcfe8 ldr r12, [r12, #0x4]
 *   @0x2bcfec str r12, [sp, #0x30]
 *   @0x2bcff0 ldr r12, [sp, #0x30]
 *   @0x2bcff4 mov r6, #0
 *   @0x2bcff8 ldr r4, [sp, #0x34]
 *   @0x2bcffc ldrsh r10, [r5]
 *   @0x2bd000 ldrsh r7, [r12]
 *   @0x2bd004 ldr r12, [sp, #0xc]
 *   @0x2bd008 ldrsh r9, [r4]
 *   @0x2bd00c mov r4, r6
 *   @0x2bd010 str r10, [sp, #0x20]
 *   @0x2bd014 ldr r3, [r12, #0x1c]
 *   @0x2bd018 str r9, [sp, #0x28]
 *   @0x2bd01c sub r3, r3, #1
 *   @0x2bd020 str r7, [sp, #0x24]
 *   @0x2bd024 str r3, [sp, #0x18]
 *   @0x2bd028 b 0x2bd044 <jpeg_alloc_huff_table+0x73c>
 *   @0x2bd02c str r7, [sp, #0x24]
 *   @0x2bd030 str r9, [sp, #0x28]
 *   @0x2bd034 ldr r7, [sp, #0x14]
 *   @0x2bd038 ldr r9, [sp, #0x10]
 *   @0x2bd03c str r10, [sp, #0x20]
 *   @0x2bd040 mov r10, r8
 *   @0x2bd044 mov r0, r5
 *   @0x2bd048 add r1, sp, #160
 *   @0x2bd04c mov r2, #1
 *   @0x2bd050 bl 0x2bc854 <jcopy_block_row>
 *   @0x2bd054 ldr r12, [sp, #0x18]
 *   @0x2bd058 cmp r12, r4
 *   @0x2bd05c bls 0x2bd4c0 <jpeg_alloc_huff_table+0xbb8>
 *   @0x2bd060 ldr r12, [sp, #0x34]
 *   @0x2bd064 lsl r3, r4, #7
 *   @0x2bd068 ldrsh r8, [r5, #128]
 *   @0x2bd06c add r1, r12, #128
 *   @0x2bd070 ldr r12, [sp, #0x30]
 *   @0x2bd074 add r2, r12, #128
 *   @0x2bd078 ldrsh r1, [r1, r3]
 *   @0x2bd07c ldrsh r2, [r2, r3]
 *   @0x2bd080 str r1, [sp, #0x10]
 *   @0x2bd084 str r2, [sp, #0x14]
 *   @0x2bd088 ldr r3, [r11, #0x4]
 *   @0x2bd08c cmp r3, #0
 *   @0x2bd090 beq 0x2bd0ec <jpeg_alloc_huff_table+0x7e4>
 *   @0x2bd094 ldrsh r2, [sp, #162]
 *   @0x2bd098 cmp r2, #0
 *   @0x2bd09c bne 0x2bd0ec <jpeg_alloc_huff_table+0x7e4>
 *   @0x2bd0a0 ldr r12, [sp, #0x20]
 *   @0x2bd0a4 rsb r0, r8, r12
 *   @0x2bd0a8 ldr r12, [sp, #0x44]
 *   @0x2bd0ac mul r0, r0, r12
 *   @0x2bd0b0 ldr r12, [sp, #0x50]
 *   @0x2bd0b4 cmp r0, #0
 *   @0x2bd0b8 blt 0x2bd380 <jpeg_alloc_huff_table+0xa78>
 *   @0x2bd0bc add r0, r12, r0
 *   @0x2bd0c0 ldr r1, [sp, #0x54]
 *   @0x2bd0c4 str r3, [sp, #0x8]
 *   @0x2bd0c8 bl 0x318d10 <__divsi3>
 *   @0x2bd0cc ldr r3, [sp, #0x8]
 *   @0x2bd0d0 cmp r3, #0
 *   @0x2bd0d4 ble 0x2bd0e8 <jpeg_alloc_huff_table+0x7e0>
 *   @0x2bd0d8 mov lr, #1
 *   @0x2bd0dc lsl r3, lr, r3
 *   @0x2bd0e0 cmp r0, r3
 *   @0x2bd0e4 subge r0, r3, #1
 *   @0x2bd0e8 strh r0, [sp, #162]
 *   @0x2bd0ec ldr r3, [r11, #0x8]
 *   @0x2bd0f0 cmp r3, #0
 *   @0x2bd0f4 beq 0x2bd14c <jpeg_alloc_huff_table+0x844>
 *   @0x2bd0f8 ldrsh r2, [sp, #176]
 *   @0x2bd0fc cmp r2, #0
 *   @0x2bd100 bne 0x2bd14c <jpeg_alloc_huff_table+0x844>
 *   @0x2bd104 ldr r12, [sp, #0x44]
 *   @0x2bd108 rsb r0, r7, r9
 *   @0x2bd10c mul r0, r0, r12
 *   @0x2bd110 ldr r12, [sp, #0x58]
 *   @0x2bd114 cmp r0, #0
 *   @0x2bd118 blt 0x2bd34c <jpeg_alloc_huff_table+0xa44>
 *   @0x2bd11c add r0, r12, r0
 *   @0x2bd120 ldr r1, [sp, #0x5c]
 *   @0x2bd124 str r3, [sp, #0x8]
 *   @0x2bd128 bl 0x318d10 <__divsi3>
 *   @0x2bd12c ldr r3, [sp, #0x8]
 *   @0x2bd130 cmp r3, #0
 *   @0x2bd134 ble 0x2bd148 <jpeg_alloc_huff_table+0x840>
 *   @0x2bd138 mov lr, #1
 *   @0x2bd13c lsl r3, lr, r3
 *   @0x2bd140 cmp r0, r3
 *   @0x2bd144 subge r0, r3, #1
 *   @0x2bd148 strh r0, [sp, #176]
 *   @0x2bd14c ldr r3, [r11, #0xc]
 *   @0x2bd150 cmp r3, #0
 *   @0x2bd154 beq 0x2bd1b0 <jpeg_alloc_huff_table+0x8a8>
 *   @0x2bd158 ldrsh r2, [sp, #192]
 *   @0x2bd15c cmp r2, #0
 *   @0x2bd160 bne 0x2bd1b0 <jpeg_alloc_huff_table+0x8a8>
 *   @0x2bd164 add r0, r9, r7
 *   @0x2bd168 ldr r12, [sp, #0x40]
 *   @0x2bd16c sub r0, r0, r10, lsl #1
 *   @0x2bd170 mul r0, r0, r12
 *   @0x2bd174 ldr r12, [sp, #0x60]
 *   @0x2bd178 cmp r0, #0
 *   @0x2bd17c blt 0x2bd3e8 <jpeg_alloc_huff_table+0xae0>
 *   @0x2bd180 add r0, r12, r0
 *   @0x2bd184 ldr r1, [sp, #0x64]
 *   @0x2bd188 str r3, [sp, #0x8]
 *   @0x2bd18c bl 0x318d10 <__divsi3>
 *   @0x2bd190 ldr r3, [sp, #0x8]
 *   @0x2bd194 cmp r3, #0
 *   @0x2bd198 ble 0x2bd1ac <jpeg_alloc_huff_table+0x8a4>
 *   @0x2bd19c mov lr, #1
 *   @0x2bd1a0 lsl r3, lr, r3
 *   @0x2bd1a4 cmp r0, r3
 *   @0x2bd1a8 subge r0, r3, #1
 *   @0x2bd1ac strh r0, [sp, #192]
 *   @0x2bd1b0 ldr r3, [r11, #0x10]
 *   @0x2bd1b4 cmp r3, #0
 *   @0x2bd1b8 beq 0x2bd228 <jpeg_alloc_huff_table+0x920>
 *   @0x2bd1bc ldrsh r2, [sp, #178]
 *   @0x2bd1c0 cmp r2, #0
 *   @0x2bd1c4 bne 0x2bd228 <jpeg_alloc_huff_table+0x920>
 *   @0x2bd1c8 ldr r12, [sp, #0x28]
 *   @0x2bd1cc ldr lr, [sp, #0x10]
 *   @0x2bd1d0 rsb r0, lr, r12
 *   @0x2bd1d4 ldr r12, [sp, #0x24]
 *   @0x2bd1d8 rsb r0, r12, r0
 *   @0x2bd1dc ldr r12, [sp, #0x14]
 *   @0x2bd1e0 add r0, r0, r12
 *   @0x2bd1e4 ldr r12, [sp, #0x68]
 *   @0x2bd1e8 mul r0, r0, r12
 *   @0x2bd1ec ldr r12, [sp, #0x6c]
 *   @0x2bd1f0 cmp r0, #0
 *   @0x2bd1f4 blt 0x2bd3b4 <jpeg_alloc_huff_table+0xaac>
 *   @0x2bd1f8 add r0, r12, r0
 *   @0x2bd1fc ldr r1, [sp, #0x70]
 *   @0x2bd200 str r3, [sp, #0x8]
 *   @0x2bd204 bl 0x318d10 <__divsi3>
 *   @0x2bd208 ldr r3, [sp, #0x8]
 *   @0x2bd20c cmp r3, #0
 *   @0x2bd210 ble 0x2bd224 <jpeg_alloc_huff_table+0x91c>
 *   @0x2bd214 mov lr, #1
 *   @0x2bd218 lsl r3, lr, r3
 *   @0x2bd21c cmp r0, r3
 *   @0x2bd220 subge r0, r3, #1
 *   @0x2bd224 strh r0, [sp, #178]
 *   @0x2bd228 ldr r3, [r11, #0x14]
 *   @0x2bd22c cmp r3, #0
 *   @0x2bd230 beq 0x2bd290 <jpeg_alloc_huff_table+0x988>
 *   @0x2bd234 ldrsh r2, [sp, #164]
 *   @0x2bd238 cmp r2, #0
 *   @0x2bd23c bne 0x2bd290 <jpeg_alloc_huff_table+0x988>
 *   @0x2bd240 ldr r12, [sp, #0x20]
 *   @0x2bd244 add r0, r12, r8
 *   @0x2bd248 ldr r12, [sp, #0x40]
 *   @0x2bd24c sub r0, r0, r10, lsl #1
 *   @0x2bd250 mul r0, r0, r12
 *   @0x2bd254 ldr r12, [sp, #0x74]
 *   @0x2bd258 cmp r0, #0
 *   @0x2bd25c blt 0x2bd41c <jpeg_alloc_huff_table+0xb14>
 *   @0x2bd260 add r0, r12, r0
 *   @0x2bd264 ldr r1, [sp, #0x78]
 *   @0x2bd268 str r3, [sp, #0x8]
 *   @0x2bd26c bl 0x318d10 <__divsi3>
 *   @0x2bd270 ldr r3, [sp, #0x8]
 *   @0x2bd274 cmp r3, #0
 *   @0x2bd278 ble 0x2bd28c <jpeg_alloc_huff_table+0x984>
 *   @0x2bd27c mov lr, #1
 *   @0x2bd280 lsl r3, lr, r3
 *   @0x2bd284 cmp r0, r3
 *   @0x2bd288 subge r0, r3, #1
 *   @0x2bd28c strh r0, [sp, #164]
 *   @0x2bd290 str r6, [sp]
 *   @0x2bd294 add r2, sp, #160
 *   @0x2bd298 ldr r3, [sp, #0x2c]
 *   @0x2bd29c add r4, r4, #1
 *   @0x2bd2a0 ldr r12, [sp, #0x3c]
 *   @0x2bd2a4 add r5, r5, #128
 *   @0x2bd2a8 ldr r0, [sp, #0x38]
 *   @0x2bd2ac ldr r1, [sp, #0xc]
 *   @0x2bd2b0 blx r12
 *   @0x2bd2b4 ldr r12, [sp, #0x18]
 *   @0x2bd2b8 cmp r12, r4
 *   @0x2bd2bc ldr r12, [sp, #0xc]
 *   @0x2bd2c0 ldr r3, [r12, #0x24]
 *   @0x2bd2c4 add r6, r6, r3
 *   @0x2bd2c8 bhs 0x2bd02c <jpeg_alloc_huff_table+0x724>
 *   @0x2bd2cc ldr r12, [sp, #0x2c]
 *   @0x2bd2d0 ldr r4, [sp, #0x48]
 *   @0x2bd2d4 add r12, r12, r3, lsl #2
 *   @0x2bd2d8 str r12, [sp, #0x2c]
 *   @0x2bd2dc ldr r12, [sp, #0x7c]
 *   @0x2bd2e0 add r4, r4, #1
 *   @0x2bd2e4 str r4, [sp, #0x48]
 *   @0x2bd2e8 cmp r4, r12
 *   @0x2bd2ec bne 0x2bcf98 <jpeg_alloc_huff_table+0x690>
 *   @0x2bd2f0 ldr r4, [sp, #0x38]
 *   @0x2bd2f4 ldr r5, [r4, #0x88]
 *   @0x2bd2f8 ldr r2, [r4, #0x24]
 *   @0x2bd2fc ldr r12, [sp, #0x88]
 *   @0x2bd300 ldr r4, [sp, #0xc]
 *   @0x2bd304 add r12, r12, #1
 *   @0x2bd308 str r12, [sp, #0x88]
 *   @0x2bd30c cmp r2, r12
 *   @0x2bd310 ldr r12, [sp, #0x90]
 *   @0x2bd314 add r4, r4, #84
 *   @0x2bd318 str r4, [sp, #0xc]
 *   @0x2bd31c add r12, r12, #4
 *   @0x2bd320 str r12, [sp, #0x90]
 *   @0x2bd324 bgt 0x2bce38 <jpeg_alloc_huff_table+0x530>
 *   @0x2bd328 ldr r4, [sp, #0x38]
 *   @0x2bd32c add r5, r5, #1
 *   @0x2bd330 ldr r0, [r4, #0x11c]
 *   @0x2bd334 str r5, [r4, #0x88]
 *   @0x2bd338 cmp r5, r0
 *   @0x2bd33c movhs r0, #4
 *   @0x2bd340 movlo r0, #3
 *   @0x2bd344 add sp, sp, #292
 *   @0x2bd348 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bd34c rsb r0, r0, r12
 *   @0x2bd350 ldr r1, [sp, #0x5c]
 *   @0x2bd354 str r3, [sp, #0x8]
 *   @0x2bd358 bl 0x318d10 <__divsi3>
 *   @0x2bd35c ldr r3, [sp, #0x8]
 *   @0x2bd360 cmp r3, #0
 *   @0x2bd364 ble 0x2bd378 <jpeg_alloc_huff_table+0xa70>
 *   @0x2bd368 mov lr, #1
 *   @0x2bd36c lsl r3, lr, r3
 *   @0x2bd370 cmp r0, r3
 *   @0x2bd374 subge r0, r3, #1
 *   @0x2bd378 rsb r0, r0, #0
 *   @0x2bd37c b 0x2bd148 <jpeg_alloc_huff_table+0x840>
 *   @0x2bd380 rsb r0, r0, r12
 *   @0x2bd384 ldr r1, [sp, #0x54]
 *   @0x2bd388 str r3, [sp, #0x8]
 *   @0x2bd38c bl 0x318d10 <__divsi3>
 *   @0x2bd390 ldr r3, [sp, #0x8]
 *   @0x2bd394 cmp r3, #0
 *   @0x2bd398 ble 0x2bd3ac <jpeg_alloc_huff_table+0xaa4>
 *   @0x2bd39c mov lr, #1
 *   @0x2bd3a0 lsl r3, lr, r3
 *   @0x2bd3a4 cmp r0, r3
 *   @0x2bd3a8 subge r0, r3, #1
 *   @0x2bd3ac rsb r0, r0, #0
 *   @0x2bd3b0 b 0x2bd0e8 <jpeg_alloc_huff_table+0x7e0>
 *   @0x2bd3b4 rsb r0, r0, r12
 *   @0x2bd3b8 ldr r1, [sp, #0x70]
 *   @0x2bd3bc str r3, [sp, #0x8]
 *   @0x2bd3c0 bl 0x318d10 <__divsi3>
 *   @0x2bd3c4 ldr r3, [sp, #0x8]
 *   @0x2bd3c8 cmp r3, #0
 *   @0x2bd3cc ble 0x2bd3e0 <jpeg_alloc_huff_table+0xad8>
 *   @0x2bd3d0 mov lr, #1
 *   @0x2bd3d4 lsl r3, lr, r3
 *   @0x2bd3d8 cmp r0, r3
 *   @0x2bd3dc subge r0, r3, #1
 *   @0x2bd3e0 rsb r0, r0, #0
 *   @0x2bd3e4 b 0x2bd224 <jpeg_alloc_huff_table+0x91c>
 *   @0x2bd3e8 rsb r0, r0, r12
 *   @0x2bd3ec ldr r1, [sp, #0x64]
 *   @0x2bd3f0 str r3, [sp, #0x8]
 *   @0x2bd3f4 bl 0x318d10 <__divsi3>
 *   @0x2bd3f8 ldr r3, [sp, #0x8]
 *   @0x2bd3fc cmp r3, #0
 *   @0x2bd400 ble 0x2bd414 <jpeg_alloc_huff_table+0xb0c>
 *   @0x2bd404 mov lr, #1
 *   @0x2bd408 lsl r3, lr, r3
 *   @0x2bd40c cmp r0, r3
 *   @0x2bd410 subge r0, r3, #1
 *   @0x2bd414 rsb r0, r0, #0
 *   @0x2bd418 b 0x2bd1ac <jpeg_alloc_huff_table+0x8a4>
 *   @0x2bd41c rsb r0, r0, r12
 *   @0x2bd420 ldr r1, [sp, #0x78]
 *   @0x2bd424 str r3, [sp, #0x8]
 *   @0x2bd428 bl 0x318d10 <__divsi3>
 *   @0x2bd42c ldr r3, [sp, #0x8]
 *   @0x2bd430 cmp r3, #0
 *   @0x2bd434 ble 0x2bd448 <jpeg_alloc_huff_table+0xb40>
 *   @0x2bd438 mov lr, #1
 *   @0x2bd43c lsl r3, lr, r3
 *   @0x2bd440 cmp r0, r3
 *   @0x2bd444 subge r0, r3, #1
 *   @0x2bd448 rsb r0, r0, #0
 *   @0x2bd44c b 0x2bd28c <jpeg_alloc_huff_table+0x984>
 *   @0x2bd450 ldr r12, [sp, #0xc]
 *   @0x2bd454 ldr r4, [r12, #0xc]
 *   @0x2bd458 mov r12, #1
 *   @0x2bd45c str r12, [sp, #0x80]
 *   @0x2bd460 ldr r12, [sp, #0xc]
 *   @0x2bd464 mov r1, r4
 *   @0x2bd468 ldr r0, [r12, #0x20]
 *   @0x2bd46c bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x2bd470 cmp r1, #0
 *   @0x2bd474 moveq r12, r4
 *   @0x2bd478 movne r12, r1
 *   @0x2bd47c str r12, [sp, #0x7c]
 *   @0x2bd480 ldr r12, [sp, #0x90]
 *   @0x2bd484 moveq r3, r4
 *   @0x2bd488 movne r3, r1
 *   @0x2bd48c cmp r5, #0
 *   @0x2bd490 ldr r1, [r12, #0x48]
 *   @0x2bd494 bne 0x2bce78 <jpeg_alloc_huff_table+0x570>
 *   @0x2bd498 ldr r4, [sp, #0x38]
 *   @0x2bd49c mov r2, r5
 *   @0x2bd4a0 mov r6, #1
 *   @0x2bd4a4 ldr r12, [r4, #0x4]
 *   @0x2bd4a8 mov r0, r4
 *   @0x2bd4ac str r5, [sp]
 *   @0x2bd4b0 ldr r12, [r12, #0x20]
 *   @0x2bd4b4 blx r12
 *   @0x2bd4b8 mov r5, r0
 *   @0x2bd4bc b 0x2bceb0 <jpeg_alloc_huff_table+0x5a8>
 *   @0x2bd4c0 str r7, [sp, #0x14]
 *   @0x2bd4c4 mov r8, r10
 *   @0x2bd4c8 str r9, [sp, #0x10]
 *   @0x2bd4cc b 0x2bd088 <jpeg_alloc_huff_table+0x780>
 *   @0x2bd4d0 str r5, [sp, #0x30]
 *   @0x2bd4d4 b 0x2bcff0 <jpeg_alloc_huff_table+0x6e8>
 *   @0x2bd4d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bd4dc sub sp, sp, #36
 *   @0x2bd4e0 ldr r4, [r0, #0x188]
 *   @0x2bd4e4 mov r11, r0
 *   @0x2bd4e8 ldr r6, [r0, #0x11c]
 *   @0x2bd4ec str r1, [sp, #0x18]
 *   @0x2bd4f0 ldr r2, [r11, #0x7c]
 *   @0x2bd4f4 mov r0, r11
 *   @0x2bd4f8 ldr r3, [r11, #0x84]
 *   @0x2bd4fc cmp r2, r3
 *   @0x2bd500 blt 0x2bd518 <jpeg_alloc_huff_table+0xc10>
 *   @0x2bd504 bne 0x2bd534 <jpeg_alloc_huff_table+0xc2c>
 *   @0x2bd508 ldr r3, [r11, #0x88]
 *   @0x2bd50c ldr r2, [r11, #0x80]
 *   @0x2bd510 cmp r2, r3
 *   @0x2bd514 bhi 0x2bd6b8 <jpeg_alloc_huff_table+0xdb0>
 *   @0x2bd518 ldr r3, [r11, #0x190]
 *   @0x2bd51c ldr r3, [r3]
 *   @0x2bd520 blx r3
 *   @0x2bd524 cmp r0, #0
 *   @0x2bd528 bne 0x2bd4f0 <jpeg_alloc_huff_table+0xbe8>
 *   @0x2bd52c add sp, sp, #36
 *   @0x2bd530 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bd534 ldr r2, [r11, #0x88]
 *   @0x2bd538 ldr r0, [r11, #0x24]
 *   @0x2bd53c ldr r5, [r11, #0xc4]
 *   @0x2bd540 cmp r0, #0
 *   @0x2bd544 ble 0x2bd698 <jpeg_alloc_huff_table+0xd90>
 *   @0x2bd548 sub r6, r6, #1
 *   @0x2bd54c mov r12, #0
 *   @0x2bd550 str r6, [sp, #0x1c]
 *   @0x2bd554 str r12, [sp, #0x10]
 *   @0x2bd558 str r4, [sp, #0x14]
 *   @0x2bd55c b 0x2bd584 <jpeg_alloc_huff_table+0xc7c>
 *   @0x2bd560 ldr r12, [sp, #0x10]
 *   @0x2bd564 add r5, r5, #84
 *   @0x2bd568 add r12, r12, #1
 *   @0x2bd56c str r12, [sp, #0x10]
 *   @0x2bd570 cmp r0, r12
 *   @0x2bd574 ldr r12, [sp, #0x14]
 *   @0x2bd578 add r12, r12, #4
 *   @0x2bd57c str r12, [sp, #0x14]
 *   @0x2bd580 ble 0x2bd698 <jpeg_alloc_huff_table+0xd90>
 *   @0x2bd584 ldrb r3, [r5, #0x30]
 *   @0x2bd588 cmp r3, #0
 *   @0x2bd58c beq 0x2bd560 <jpeg_alloc_huff_table+0xc58>
 *   @0x2bd590 ldr r12, [sp, #0x14]
 *   @0x2bd594 mov lr, #0
 *   @0x2bd598 ldr r3, [r5, #0xc]
 *   @0x2bd59c mov r0, r11
 *   @0x2bd5a0 ldr r1, [r12, #0x48]
 *   @0x2bd5a4 ldr r12, [r11, #0x4]
 *   @0x2bd5a8 mul r2, r2, r3
 *   @0x2bd5ac str lr, [sp]
 *   @0x2bd5b0 ldr r12, [r12, #0x20]
 *   @0x2bd5b4 blx r12
 *   @0x2bd5b8 ldr r12, [sp, #0x1c]
 *   @0x2bd5bc ldr r4, [r11, #0x88]
 *   @0x2bd5c0 cmp r12, r4
 *   @0x2bd5c4 ldr r12, [r5, #0xc]
 *   @0x2bd5c8 str r12, [sp, #0xc]
 *   @0x2bd5cc mov r10, r0
 *   @0x2bd5d0 bhi 0x2bd5f0 <jpeg_alloc_huff_table+0xce8>
 *   @0x2bd5d4 mov r1, r12
 *   @0x2bd5d8 ldr r0, [r5, #0x20]
 *   @0x2bd5dc bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x2bd5e0 ldr r12, [sp, #0xc]
 *   @0x2bd5e4 cmp r1, #0
 *   @0x2bd5e8 movne r12, r1
 *   @0x2bd5ec str r12, [sp, #0xc]
 *   @0x2bd5f0 ldr r12, [sp, #0xc]
 *   @0x2bd5f4 ldr r3, [r11, #0x19c]
 *   @0x2bd5f8 cmp r12, #0
 *   @0x2bd5fc ldr r12, [sp, #0x10]
 *   @0x2bd600 ldr r1, [sp, #0x18]
 *   @0x2bd604 add r3, r3, r12, lsl #2
 *   @0x2bd608 ldr r7, [r1, r12, lsl #2]
 *   @0x2bd60c ldr r8, [r3, #0x4]
 *   @0x2bd610 ble 0x2bd6c0 <jpeg_alloc_huff_table+0xdb8>
 *   @0x2bd614 ldr r3, [r5, #0x1c]
 *   @0x2bd618 mov r9, #0
 *   @0x2bd61c sub r10, r10, #4
 *   @0x2bd620 str r10, [sp, #0x8]
 *   @0x2bd624 ldr r12, [sp, #0x8]
 *   @0x2bd628 cmp r3, #0
 *   @0x2bd62c ldreq r2, [r5, #0x24]
 *   @0x2bd630 ldr r6, [r12, #0x4]!
 *   @0x2bd634 str r12, [sp, #0x8]
 *   @0x2bd638 beq 0x2bd678 <jpeg_alloc_huff_table+0xd70>
 *   @0x2bd63c mov r4, #0
 *   @0x2bd640 mov r10, r4
 *   @0x2bd644 mov r2, r6
 *   @0x2bd648 str r4, [sp]
 *   @0x2bd64c mov r3, r7
 *   @0x2bd650 mov r0, r11
 *   @0x2bd654 mov r1, r5
 *   @0x2bd658 add r10, r10, #1
 *   @0x2bd65c blx r8
 *   @0x2bd660 ldr r3, [r5, #0x1c]
 *   @0x2bd664 ldr r2, [r5, #0x24]
 *   @0x2bd668 add r6, r6, #128
 *   @0x2bd66c cmp r3, r10
 *   @0x2bd670 add r4, r4, r2
 *   @0x2bd674 bhi 0x2bd644 <jpeg_alloc_huff_table+0xd3c>
 *   @0x2bd678 ldr r12, [sp, #0xc]
 *   @0x2bd67c add r9, r9, #1
 *   @0x2bd680 add r7, r7, r2, lsl #2
 *   @0x2bd684 cmp r9, r12
 *   @0x2bd688 bne 0x2bd624 <jpeg_alloc_huff_table+0xd1c>
 *   @0x2bd68c ldr r2, [r11, #0x88]
 *   @0x2bd690 ldr r0, [r11, #0x24]
 *   @0x2bd694 b 0x2bd560 <jpeg_alloc_huff_table+0xc58>
 *   @0x2bd698 ldr r0, [r11, #0x11c]
 *   @0x2bd69c add r2, r2, #1
 *   @0x2bd6a0 str r2, [r11, #0x88]
 *   @0x2bd6a4 cmp r2, r0
 *   @0x2bd6a8 movhs r0, #4
 *   @0x2bd6ac movlo r0, #3
 *   @0x2bd6b0 add sp, sp, #36
 *   @0x2bd6b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bd6b8 mov r2, r3
 *   @0x2bd6bc b 0x2bd538 <jpeg_alloc_huff_table+0xc30>
 *   @0x2bd6c0 ldr r0, [r11, #0x24]
 *   @0x2bd6c4 mov r2, r4
 *   @0x2bd6c8 b 0x2bd560 <jpeg_alloc_huff_table+0xc58>
 *   @0x2bd6cc ldr r12, [r0, #0x188]
 *   @0x2bd6d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bd6d4 sub sp, sp, #60
 *   @0x2bd6d8 ldr r3, [r0, #0x138]
 *   @0x2bd6dc mov r11, r0
 *   @0x2bd6e0 str r12, [sp, #0x14]
 *   @0x2bd6e4 ldr r12, [r12, #0x18]
 *   @0x2bd6e8 sub r3, r3, #1
 *   @0x2bd6ec ldr r2, [r0, #0x11c]
 *   @0x2bd6f0 str r3, [sp, #0x2c]
 *   @0x2bd6f4 str r12, [sp, #0x20]
 *   @0x2bd6f8 ldr r12, [sp, #0x14]
 *   @0x2bd6fc str r1, [sp, #0x30]
 *   @0x2bd700 ldr r3, [r12, #0x1c]
 *   @0x2bd704 sub r12, r2, #1
 *   @0x2bd708 str r12, [sp, #0x10]
 *   @0x2bd70c ldr r12, [sp, #0x20]
 *   @0x2bd710 cmp r12, r3
 *   @0x2bd714 bge 0x2bd94c <jpeg_alloc_huff_table+0x1044>
 *   @0x2bd718 ldr r12, [sp, #0x14]
 *   @0x2bd71c ldr r12, [r12, #0x14]
 *   @0x2bd720 str r12, [sp, #0x28]
 *   @0x2bd724 ldr r12, [sp, #0x14]
 *   @0x2bd728 ldr lr, [sp, #0x28]
 *   @0x2bd72c add r12, r12, #32
 *   @0x2bd730 str r12, [sp, #0x34]
 *   @0x2bd734 ldr r12, [sp, #0x2c]
 *   @0x2bd738 cmp r12, lr
 *   @0x2bd73c blo 0x2bd7f4 <jpeg_alloc_huff_table+0xeec>
 *   @0x2bd740 ldr r12, [sp, #0x14]
 *   @0x2bd744 ldr r1, [r11, #0x140]
 *   @0x2bd748 ldr r0, [r12, #0x20]
 *   @0x2bd74c lsl r1, r1, #7
 *   @0x2bd750 bl 0x2bc868 <jzero_far>
 *   @0x2bd754 ldr r3, [r11, #0x198]
 *   @0x2bd758 mov r0, r11
 *   @0x2bd75c ldr r1, [sp, #0x34]
 *   @0x2bd760 ldr r3, [r3, #0x4]
 *   @0x2bd764 blx r3
 *   @0x2bd768 cmp r0, #0
 *   @0x2bd76c beq 0x2bd930 <jpeg_alloc_huff_table+0x1028>
 *   @0x2bd770 ldr r1, [r11, #0x124]
 *   @0x2bd774 cmp r1, #0
 *   @0x2bd778 ble 0x2bd7d4 <jpeg_alloc_huff_table+0xecc>
 *   @0x2bd77c mov r12, #0
 *   @0x2bd780 str r11, [sp, #0x24]
 *   @0x2bd784 str r12, [sp, #0x1c]
 *   @0x2bd788 str r12, [sp, #0xc]
 *   @0x2bd78c ldr r12, [sp, #0x24]
 *   @0x2bd790 ldr r6, [r12, #0x128]
 *   @0x2bd794 ldrb r3, [r6, #0x30]
 *   @0x2bd798 cmp r3, #0
 *   @0x2bd79c bne 0x2bd828 <jpeg_alloc_huff_table+0xf20>
 *   @0x2bd7a0 ldr r12, [sp, #0xc]
 *   @0x2bd7a4 ldr r3, [r6, #0x3c]
 *   @0x2bd7a8 add r12, r12, r3
 *   @0x2bd7ac str r12, [sp, #0xc]
 *   @0x2bd7b0 ldr r12, [sp, #0x1c]
 *   @0x2bd7b4 add r12, r12, #1
 *   @0x2bd7b8 str r12, [sp, #0x1c]
 *   @0x2bd7bc ldr r12, [sp, #0x24]
 *   @0x2bd7c0 add r12, r12, #4
 *   @0x2bd7c4 str r12, [sp, #0x24]
 *   @0x2bd7c8 ldr r12, [sp, #0x1c]
 *   @0x2bd7cc cmp r1, r12
 *   @0x2bd7d0 bgt 0x2bd78c <jpeg_alloc_huff_table+0xe84>
 *   @0x2bd7d4 ldr r12, [sp, #0x28]
 *   @0x2bd7d8 ldr lr, [sp, #0x2c]
 *   @0x2bd7dc add r12, r12, #1
 *   @0x2bd7e0 str r12, [sp, #0x28]
 *   @0x2bd7e4 cmp lr, r12
 *   @0x2bd7e8 bhs 0x2bd740 <jpeg_alloc_huff_table+0xe38>
 *   @0x2bd7ec ldr r12, [sp, #0x14]
 *   @0x2bd7f0 ldr r3, [r12, #0x1c]
 *   @0x2bd7f4 ldr r12, [sp, #0x20]
 *   @0x2bd7f8 mov lr, #0
 *   @0x2bd7fc add r12, r12, #1
 *   @0x2bd800 str r12, [sp, #0x20]
 *   @0x2bd804 ldr r12, [sp, #0x14]
 *   @0x2bd808 str lr, [r12, #0x14]
 *   @0x2bd80c ldr r12, [sp, #0x20]
 *   @0x2bd810 cmp r3, r12
 *   @0x2bd814 movgt r12, #0
 *   @0x2bd818 strgt r12, [sp, #0x28]
 *   @0x2bd81c bgt 0x2bd740 <jpeg_alloc_huff_table+0xe38>
 *   @0x2bd820 ldr r3, [r11, #0x11c]
 *   @0x2bd824 b 0x2bd950 <jpeg_alloc_huff_table+0x1048>
 *   @0x2bd828 ldr r0, [r6, #0x4]
 *   @0x2bd82c ldr r12, [sp, #0x2c]
 *   @0x2bd830 ldr lr, [sp, #0x28]
 *   @0x2bd834 ldr r3, [r11, #0x19c]
 *   @0x2bd838 cmp r12, lr
 *   @0x2bd83c ldr r12, [sp, #0x30]
 *   @0x2bd840 add r3, r3, r0, lsl #2
 *   @0x2bd844 ldr lr, [sp, #0x28]
 *   @0x2bd848 ldr r2, [r6, #0x38]
 *   @0x2bd84c ldr r0, [r12, r0, lsl #2]
 *   @0x2bd850 ldr r9, [r3, #0x4]
 *   @0x2bd854 ldr r12, [sp, #0x20]
 *   @0x2bd858 ldr r3, [r6, #0x24]
 *   @0x2bd85c ldrhi r8, [r6, #0x34]
 *   @0x2bd860 ldrls r8, [r6, #0x44]
 *   @0x2bd864 cmp r2, #0
 *   @0x2bd868 mul r7, r3, r12
 *   @0x2bd86c ldr r12, [r6, #0x40]
 *   @0x2bd870 mul r12, r12, lr
 *   @0x2bd874 add r7, r0, r7, lsl #2
 *   @0x2bd878 str r12, [sp, #0x18]
 *   @0x2bd87c ble 0x2bd7b0 <jpeg_alloc_huff_table+0xea8>
 *   @0x2bd880 mov r12, #0
 *   @0x2bd884 str r12, [sp, #0x8]
 *   @0x2bd888 ldr r1, [r11, #0x80]
 *   @0x2bd88c ldr r12, [sp, #0x10]
 *   @0x2bd890 cmp r12, r1
 *   @0x2bd894 bhi 0x2bd8b0 <jpeg_alloc_huff_table+0xfa8>
 *   @0x2bd898 ldr r12, [sp, #0x8]
 *   @0x2bd89c ldr lr, [sp, #0x20]
 *   @0x2bd8a0 ldr r1, [r6, #0x48]
 *   @0x2bd8a4 add r0, r12, lr
 *   @0x2bd8a8 cmp r0, r1
 *   @0x2bd8ac bge 0x2bd900 <jpeg_alloc_huff_table+0xff8>
 *   @0x2bd8b0 cmp r8, #0
 *   @0x2bd8b4 ble 0x2bd900 <jpeg_alloc_huff_table+0xff8>
 *   @0x2bd8b8 ldr r0, [sp, #0xc]
 *   @0x2bd8bc mov r4, #0
 *   @0x2bd8c0 ldr r1, [sp, #0x14]
 *   @0x2bd8c4 add r12, r0, #7
 *   @0x2bd8c8 ldr r5, [sp, #0x18]
 *   @0x2bd8cc add r10, r1, r12, lsl #2
 *   @0x2bd8d0 ldr r2, [r10, #0x4]!
 *   @0x2bd8d4 mov r3, r7
 *   @0x2bd8d8 str r5, [sp]
 *   @0x2bd8dc add r4, r4, #1
 *   @0x2bd8e0 mov r0, r11
 *   @0x2bd8e4 mov r1, r6
 *   @0x2bd8e8 blx r9
 *   @0x2bd8ec ldr r3, [r6, #0x24]
 *   @0x2bd8f0 cmp r4, r8
 *   @0x2bd8f4 add r5, r5, r3
 *   @0x2bd8f8 bne 0x2bd8d0 <jpeg_alloc_huff_table+0xfc8>
 *   @0x2bd8fc ldr r2, [r6, #0x38]
 *   @0x2bd900 ldr r12, [sp, #0x8]
 *   @0x2bd904 add r7, r7, r3, lsl #2
 *   @0x2bd908 ldr r1, [r6, #0x34]
 *   @0x2bd90c add r12, r12, #1
 *   @0x2bd910 str r12, [sp, #0x8]
 *   @0x2bd914 cmp r2, r12
 *   @0x2bd918 ldr r12, [sp, #0xc]
 *   @0x2bd91c add r12, r12, r1
 *   @0x2bd920 str r12, [sp, #0xc]
 *   @0x2bd924 bgt 0x2bd888 <jpeg_alloc_huff_table+0xf80>
 *   @0x2bd928 ldr r1, [r11, #0x124]
 *   @0x2bd92c b 0x2bd7b0 <jpeg_alloc_huff_table+0xea8>
 *   @0x2bd930 ldr r12, [sp, #0x20]
 *   @0x2bd934 ldr r1, [sp, #0x14]
 *   @0x2bd938 str r12, [r1, #0x18]
 *   @0x2bd93c ldr r12, [sp, #0x28]
 *   @0x2bd940 str r12, [r1, #0x14]
 *   @0x2bd944 add sp, sp, #60
 *   @0x2bd948 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bd94c mov r3, r2
 *   @0x2bd950 ldr r2, [r11, #0x80]
 *   @0x2bd954 ldr r1, [r11, #0x88]
 *   @0x2bd958 add r2, r2, #1
 *   @0x2bd95c str r2, [r11, #0x80]
 *   @0x2bd960 cmp r2, r3
 *   @0x2bd964 add r3, r1, #1
 *   @0x2bd968 str r3, [r11, #0x88]
 *   @0x2bd96c bhs 0x2bd984 <jpeg_alloc_huff_table+0x107c>
 *   @0x2bd970 mov r0, r11
 *   @0x2bd974 bl 0x2bc92c <jpeg_alloc_huff_table+0x24>
 *   @0x2bd978 mov r0, #3
 *   @0x2bd97c add sp, sp, #60
 *   @0x2bd980 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bd984 ldr r3, [r11, #0x190]
 *   @0x2bd988 mov r0, r11
 *   @0x2bd98c ldr r3, [r3, #0xc]
 *   @0x2bd990 blx r3
 *   @0x2bd994 mov r0, #4
 *   @0x2bd998 add sp, sp, #60
 *
 * ══ §4/13 anon_2b9054  0x2b9054  size 4188  1047 条（0x2b9054..0x2ba0b0）
 * @func 0x2b9054 0x2ba0b0  size 4188  1047 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2b9054+0xf4×4 / anon_2b9054+0x17c×4 / __udivsi3×4 / anon_2b9054+0xe10×3 / jpeg_free_small×2 / anon_2b9054+0x424×2 / anon_2b9054×2 / jzero_far×2
 * 字段偏移 top8: 0x14×32 / 0x4×31 / 0x18×29 / 0x8×21 / 0x10×17 / 0x24×15 / 0x1c×14 / 0x22×10
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b9054 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2b9058 mov r8, r0
 *   @0x2b905c ldr r7, [r1, #0x8]
 *   @0x2b9060 mov r4, r1
 *   @0x2b9064 ldr r0, [r1, #0x10]
 *   @0x2b9068 sub sp, sp, #8
 *   @0x2b906c ldr r1, [r1, #0x18]
 *   @0x2b9070 lsl r7, r7, #7
 *   @0x2b9074 cmp r0, #0
 *   @0x2b9078 mul r5, r1, r7
 *   @0x2b907c ble 0x2b9148 <jpeg_std_error+0x188>
 *   @0x2b9080 ldr r6, [r4, #0x14]
 *   @0x2b9084 ldr r3, [r4, #0x1c]
 *   @0x2b9088 ldr r12, [r4, #0x4]
 *   @0x2b908c cmp r0, r6
 *   @0x2b9090 movge r0, r6
 *   @0x2b9094 rsb r3, r1, r3
 *   @0x2b9098 cmp r3, r0
 *   @0x2b909c movge r3, r0
 *   @0x2b90a0 rsb r1, r1, r12
 *   @0x2b90a4 cmp r3, r1
 *   @0x2b90a8 movge r3, r1
 *   @0x2b90ac cmp r3, #0
 *   @0x2b90b0 ble 0x2b9148 <jpeg_std_error+0x188>
 *   @0x2b90b4 cmp r2, #0
 *   @0x2b90b8 addne r9, r4, #40
 *   @0x2b90bc movne r6, #0
 *   @0x2b90c0 bne 0x2b9188 <jpeg_std_error+0x1c8>
 *   @0x2b90c4 add r9, r4, #40
 *   @0x2b90c8 mov r6, r2
 *   @0x2b90cc b 0x2b9108 <jpeg_std_error+0x148>
 *   @0x2b90d0 ldr r2, [r4, #0x18]
 *   @0x2b90d4 cmp r3, r1
 *   @0x2b90d8 movge r3, r1
 *   @0x2b90dc ldr r12, [r4, #0x1c]
 *   @0x2b90e0 add r2, r6, r2
 *   @0x2b90e4 ldr r0, [r4, #0x4]
 *   @0x2b90e8 rsb r12, r2, r12
 *   @0x2b90ec cmp r3, r12
 *   @0x2b90f0 movge r3, r12
 *   @0x2b90f4 rsb r2, r2, r0
 *   @0x2b90f8 cmp r3, r2
 *   @0x2b90fc movge r3, r2
 *   @0x2b9100 cmp r3, #0
 *   @0x2b9104 ble 0x2b9148 <jpeg_std_error+0x188>
 *   @0x2b9108 mul r12, r7, r3
 *   @0x2b910c ldr r2, [r4]
 *   @0x2b9110 mov r3, r5
 *   @0x2b9114 ldr r10, [r4, #0x28]
 *   @0x2b9118 mov r1, r9
 *   @0x2b911c mov r0, r8
 *   @0x2b9120 ldr r2, [r2, r6, lsl #2]
 *   @0x2b9124 add r5, r5, r12
 *   @0x2b9128 str r12, [sp]
 *   @0x2b912c blx r10
 *   @0x2b9130 ldr r1, [r4, #0x14]
 *   @0x2b9134 ldr r2, [r4, #0x10]
 *   @0x2b9138 add r6, r1, r6
 *   @0x2b913c cmp r6, r2
 *   @0x2b9140 rsb r3, r6, r2
 *   @0x2b9144 blt 0x2b90d0 <jpeg_std_error+0x110>
 *   @0x2b9148 add sp, sp, #8
 *   @0x2b914c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2b9150 ldr r2, [r4, #0x18]
 *   @0x2b9154 cmp r3, r1
 *   @0x2b9158 movge r3, r1
 *   @0x2b915c ldr r12, [r4, #0x1c]
 *   @0x2b9160 add r2, r6, r2
 *   @0x2b9164 ldr r0, [r4, #0x4]
 *   @0x2b9168 rsb r12, r2, r12
 *   @0x2b916c cmp r3, r12
 *   @0x2b9170 movge r3, r12
 *   @0x2b9174 rsb r2, r2, r0
 *   @0x2b9178 cmp r3, r2
 *   @0x2b917c movge r3, r2
 *   @0x2b9180 cmp r3, #0
 *   @0x2b9184 ble 0x2b9148 <jpeg_std_error+0x188>
 *   @0x2b9188 mul r12, r7, r3
 *   @0x2b918c ldr r2, [r4]
 *   @0x2b9190 mov r3, r5
 *   @0x2b9194 ldr r10, [r4, #0x2c]
 *   @0x2b9198 mov r1, r9
 *   @0x2b919c mov r0, r8
 *   @0x2b91a0 ldr r2, [r2, r6, lsl #2]
 *   @0x2b91a4 add r5, r5, r12
 *   @0x2b91a8 str r12, [sp]
 *   @0x2b91ac blx r10
 *   @0x2b91b0 ldr r1, [r4, #0x14]
 *   @0x2b91b4 ldr r2, [r4, #0x10]
 *   @0x2b91b8 add r6, r1, r6
 *   @0x2b91bc cmp r2, r6
 *   @0x2b91c0 rsb r3, r6, r2
 *   @0x2b91c4 bgt 0x2b9150 <jpeg_std_error+0x190>
 *   @0x2b91c8 add sp, sp, #8
 *   @0x2b91cc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2b91d0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b91d4 movw r3, #0xc9f0
 *   @0x2b91d8 movt r3, #0x3b9a
 *   @0x2b91dc mov r5, r2
 *   @0x2b91e0 cmp r2, r3
 *   @0x2b91e4 mov r10, r0
 *   @0x2b91e8 mov r9, r1
 *   @0x2b91ec ldr r7, [r0, #0x4]
 *   @0x2b91f0 bhi 0x2b92f8 <jpeg_std_error+0x338>
 *   @0x2b91f4 ands r3, r5, #7
 *   @0x2b91f8 addne r5, r5, #8
 *   @0x2b91fc rsbne r5, r3, r5
 *   @0x2b9200 cmp r9, #1
 *   @0x2b9204 bls 0x2b9228 <jpeg_std_error+0x268>
 *   @0x2b9208 ldr r3, [r10]
 *   @0x2b920c mov r12, #14
 *   @0x2b9210 mov r0, r10
 *   @0x2b9214 str r9, [r3, #0x18]
 *   @0x2b9218 ldr r1, [r10]
 *   @0x2b921c str r12, [r3, #0x14]
 *   @0x2b9220 ldr r3, [r1]
 *   @0x2b9224 blx r3
 *   @0x2b9228 lsl r3, r9, #2
 *   @0x2b922c add r8, r7, r3
 *   @0x2b9230 ldr r4, [r8, #0x34]
 *   @0x2b9234 cmp r4, #0
 *   @0x2b9238 beq 0x2b9358 <jpeg_std_error+0x398>
 *   @0x2b923c ldr r12, [r4, #0x8]
 *   @0x2b9240 cmp r5, r12
 *   @0x2b9244 bhi 0x2b925c <jpeg_std_error+0x29c>
 *   @0x2b9248 b 0x2b92d8 <jpeg_std_error+0x318>
 *   @0x2b924c ldr r12, [r3, #0x8]
 *   @0x2b9250 mov r4, r3
 *   @0x2b9254 cmp r5, r12
 *   @0x2b9258 bls 0x2b92dc <jpeg_std_error+0x31c>
 *   @0x2b925c ldr r3, [r4]
 *   @0x2b9260 cmp r3, #0
 *   @0x2b9264 bne 0x2b924c <jpeg_std_error+0x28c>
 *   @0x2b9268 ldr r3, [pc, #0x100]
 *   @0x2b926c add r6, r5, #16
 *   @0x2b9270 add r3, pc, r3
 *   @0x2b9274 ldr r11, [r3, r9, lsl #2]
 *   @0x2b9278 movw r3, #0xc9f0
 *   @0x2b927c movt r3, #0x3b9a
 *   @0x2b9280 rsb r3, r5, r3
 *   @0x2b9284 cmp r11, r3
 *   @0x2b9288 movhs r11, r3
 *   @0x2b928c add r9, r11, r6
 *   @0x2b9290 mov r0, r10
 *   @0x2b9294 mov r1, r9
 *   @0x2b9298 bl 0x2c137c <jpeg_get_small>
 *   @0x2b929c subs r3, r0, #0
 *   @0x2b92a0 bne 0x2b931c <jpeg_std_error+0x35c>
 *   @0x2b92a4 lsr r11, r11, #1
 *   @0x2b92a8 cmp r11, #49
 *   @0x2b92ac bhi 0x2b928c <jpeg_std_error+0x2cc>
 *   @0x2b92b0 ldr r3, [r10]
 *   @0x2b92b4 mov r2, #2
 *   @0x2b92b8 mov r0, r10
 *   @0x2b92bc str r2, [r3, #0x18]
 *   @0x2b92c0 mov r2, #54
 *   @0x2b92c4 ldr r1, [r10]
 *   @0x2b92c8 str r2, [r3, #0x14]
 *   @0x2b92cc ldr r3, [r1]
 *   @0x2b92d0 blx r3
 *   @0x2b92d4 b 0x2b928c <jpeg_std_error+0x2cc>
 *   @0x2b92d8 mov r3, r4
 *   @0x2b92dc ldr r0, [r3, #0x4]
 *   @0x2b92e0 add r2, r3, #16
 *   @0x2b92e4 rsb r12, r5, r12
 *   @0x2b92e8 add r5, r0, r5
 *   @0x2b92ec add r0, r2, r0
 *   @0x2b92f0 stmib r3, {r5, r12}
 *   @0x2b92f4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b92f8 ldr r3, [r0]
 *   @0x2b92fc mov r1, #1
 *   @0x2b9300 mov r12, #54
 *   @0x2b9304 str r1, [r3, #0x18]
 *   @0x2b9308 ldr r1, [r0]
 *   @0x2b930c str r12, [r3, #0x14]
 *   @0x2b9310 ldr r3, [r1]
 *   @0x2b9314 blx r3
 *   @0x2b9318 b 0x2b91f4 <jpeg_std_error+0x234>
 *   @0x2b931c ldr r2, [r7, #0x4c]
 *   @0x2b9320 cmp r4, #0
 *   @0x2b9324 add r11, r11, r5
 *   @0x2b9328 mov r0, #0
 *   @0x2b932c add r12, r2, r9
 *   @0x2b9330 str r12, [r7, #0x4c]
 *   @0x2b9334 str r0, [r3]
 *   @0x2b9338 moveq r12, r11
 *   @0x2b933c str r0, [r3, #0x4]
 *   @0x2b9340 movne r12, r11
 *   @0x2b9344 str r11, [r3, #0x8]
 *   @0x2b9348 moveq r0, r4
 *   @0x2b934c streq r3, [r8, #0x34]
 *   @0x2b9350 strne r3, [r4]
 *   @0x2b9354 b 0x2b92e0 <jpeg_std_error+0x320>
 *   @0x2b9358 ldr r1, [pc, #0x14]
 *   @0x2b935c add r6, r5, #16
 *   @0x2b9360 add r1, pc, r1
 *   @0x2b9364 add r3, r1, r3
 *   @0x2b9368 ldr r11, [r3, #0x8]
 *   @0x2b936c b 0x2b9278 <jpeg_std_error+0x2b8>
 *   @0x2b9370 andeq r6, sp, r0, asr r12
 *   @0x2b9374 andeq r6, sp, r0, ror #22
 *   @0x2b9378 cmp r1, #1
 *   @0x2b937c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2b9380 mov r5, r1
 *   @0x2b9384 mov r4, r0
 *   @0x2b9388 mov r10, r2
 *   @0x2b938c mov r8, r3
 *   @0x2b9390 ldr r6, [r0, #0x4]
 *   @0x2b9394 ldr r9, [sp, #0x20]
 *   @0x2b9398 ldr r7, [sp, #0x24]
 *   @0x2b939c beq 0x2b93bc <jpeg_std_error+0x3fc>
 *   @0x2b93a0 ldr r3, [r0]
 *   @0x2b93a4 mov r1, #14
 *   @0x2b93a8 str r5, [r3, #0x18]
 *   @0x2b93ac ldr r2, [r0]
 *   @0x2b93b0 str r1, [r3, #0x14]
 *   @0x2b93b4 ldr r3, [r2]
 *   @0x2b93b8 blx r3
 *   @0x2b93bc mov r0, r4
 *   @0x2b93c0 mov r1, r5
 *   @0x2b93c4 mov r2, #120
 *   @0x2b93c8 bl 0x2b91d0 <jpeg_std_error+0x210>
 *   @0x2b93cc mov r2, #0
 *   @0x2b93d0 strb r10, [r0, #0x20]
 *   @0x2b93d4 strb r2, [r0, #0x22]
 *   @0x2b93d8 ldr r3, [r6, #0x48]
 *   @0x2b93dc str r9, [r0, #0x4]
 *   @0x2b93e0 str r8, [r0, #0x8]
 *   @0x2b93e4 str r7, [r0, #0xc]
 *   @0x2b93e8 str r2, [r0]
 *   @0x2b93ec str r3, [r0, #0x24]
 *   @0x2b93f0 str r0, [r6, #0x48]
 *   @0x2b93f4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2b93f8 cmp r1, #1
 *   @0x2b93fc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2b9400 mov r5, r1
 *   @0x2b9404 mov r4, r0
 *   @0x2b9408 mov r10, r2
 *   @0x2b940c mov r8, r3
 *   @0x2b9410 ldr r6, [r0, #0x4]
 *   @0x2b9414 ldr r9, [sp, #0x20]
 *   @0x2b9418 ldr r7, [sp, #0x24]
 *   @0x2b941c beq 0x2b943c <jpeg_std_error+0x47c>
 *   @0x2b9420 ldr r3, [r0]
 *   @0x2b9424 mov r1, #14
 *   @0x2b9428 str r5, [r3, #0x18]
 *   @0x2b942c ldr r2, [r0]
 *   @0x2b9430 str r1, [r3, #0x14]
 *   @0x2b9434 ldr r3, [r2]
 *   @0x2b9438 blx r3
 *   @0x2b943c mov r0, r4
 *   @0x2b9440 mov r1, r5
 *   @0x2b9444 mov r2, #120
 *   @0x2b9448 bl 0x2b91d0 <jpeg_std_error+0x210>
 *   @0x2b944c mov r2, #0
 *   @0x2b9450 strb r10, [r0, #0x20]
 *   @0x2b9454 strb r2, [r0, #0x22]
 *   @0x2b9458 ldr r3, [r6, #0x44]
 *   @0x2b945c str r9, [r0, #0x4]
 *   @0x2b9460 str r8, [r0, #0x8]
 *   @0x2b9464 str r7, [r0, #0xc]
 *   @0x2b9468 str r2, [r0]
 *   @0x2b946c str r3, [r0, #0x24]
 *   @0x2b9470 str r0, [r6, #0x44]
 *   @0x2b9474 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2b9478 cmp r1, #1
 *   @0x2b947c push {r4, r5, r6, r7, r8, lr}
 *   @0x2b9480 mov r8, r1
 *   @0x2b9484 mov r7, r0
 *   @0x2b9488 ldr r4, [r0, #0x4]
 *   @0x2b948c bls 0x2b9554 <jpeg_std_error+0x594>
 *   @0x2b9490 ldr r3, [r0]
 *   @0x2b9494 mov r1, #14
 *   @0x2b9498 str r8, [r3, #0x18]
 *   @0x2b949c ldr r2, [r0]
 *   @0x2b94a0 str r1, [r3, #0x14]
 *   @0x2b94a4 ldr r3, [r2]
 *   @0x2b94a8 blx r3
 *   @0x2b94ac add r8, r4, r8, lsl #2
 *   @0x2b94b0 mov r2, #0
 *   @0x2b94b4 ldr r3, [r8, #0x3c]
 *   @0x2b94b8 str r2, [r8, #0x3c]
 *   @0x2b94bc cmp r3, r2
 *   @0x2b94c0 beq 0x2b9500 <jpeg_std_error+0x540>
 *   @0x2b94c4 ldr r2, [r3, #0x8]
 *   @0x2b94c8 mov r1, r3
 *   @0x2b94cc ldr r5, [r3, #0x4]
 *   @0x2b94d0 mov r0, r7
 *   @0x2b94d4 ldr r6, [r3]
 *   @0x2b94d8 add r5, r5, r2
 *   @0x2b94dc add r5, r5, #16
 *   @0x2b94e0 mov r2, r5
 *   @0x2b94e4 bl 0x2c1394 <jpeg_free_large>
 *   @0x2b94e8 ldr r2, [r4, #0x4c]
 *   @0x2b94ec cmp r6, #0
 *   @0x2b94f0 mov r3, r6
 *   @0x2b94f4 rsb r5, r5, r2
 *   @0x2b94f8 str r5, [r4, #0x4c]
 *   @0x2b94fc bne 0x2b94c4 <jpeg_std_error+0x504>
 *   @0x2b9500 ldr r3, [r8, #0x34]
 *   @0x2b9504 mov r2, #0
 *   @0x2b9508 str r2, [r8, #0x34]
 *   @0x2b950c cmp r3, r2
 *   @0x2b9510 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x2b9514 ldr r2, [r3, #0x8]
 *   @0x2b9518 mov r1, r3
 *   @0x2b951c ldr r5, [r3, #0x4]
 *   @0x2b9520 mov r0, r7
 *   @0x2b9524 ldr r6, [r3]
 *   @0x2b9528 add r5, r5, r2
 *   @0x2b952c add r5, r5, #16
 *   @0x2b9530 mov r2, r5
 *   @0x2b9534 bl 0x2c1384 <jpeg_free_small>
 *   @0x2b9538 ldr r2, [r4, #0x4c]
 *   @0x2b953c cmp r6, #0
 *   @0x2b9540 mov r3, r6
 *   @0x2b9544 rsb r5, r5, r2
 *   @0x2b9548 str r5, [r4, #0x4c]
 *   @0x2b954c bne 0x2b9514 <jpeg_std_error+0x554>
 *   @0x2b9550 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2b9554 bne 0x2b94ac <jpeg_std_error+0x4ec>
 *   @0x2b9558 ldr r5, [r4, #0x44]
 *   @0x2b955c cmp r5, #0
 *   @0x2b9560 movne r6, #0
 *   @0x2b9564 bne 0x2b9578 <jpeg_std_error+0x5b8>
 *   @0x2b9568 b 0x2b95a4 <jpeg_std_error+0x5e4>
 *   @0x2b956c ldr r5, [r5, #0x24]
 *   @0x2b9570 cmp r5, #0
 *   @0x2b9574 beq 0x2b95a4 <jpeg_std_error+0x5e4>
 *   @0x2b9578 ldrb r3, [r5, #0x22]
 *   @0x2b957c cmp r3, #0
 *   @0x2b9580 beq 0x2b956c <jpeg_std_error+0x5ac>
 *   @0x2b9584 strb r6, [r5, #0x22]
 *   @0x2b9588 add r1, r5, #40
 *   @0x2b958c ldr r3, [r5, #0x30]
 *   @0x2b9590 mov r0, r7
 *   @0x2b9594 blx r3
 *   @0x2b9598 ldr r5, [r5, #0x24]
 *   @0x2b959c cmp r5, #0
 *   @0x2b95a0 bne 0x2b9578 <jpeg_std_error+0x5b8>
 *   @0x2b95a4 ldr r5, [r4, #0x48]
 *   @0x2b95a8 mov r6, #0
 *   @0x2b95ac str r6, [r4, #0x44]
 *   @0x2b95b0 cmp r5, r6
 *   @0x2b95b4 bne 0x2b95c8 <jpeg_std_error+0x608>
 *   @0x2b95b8 b 0x2b95f4 <jpeg_std_error+0x634>
 *   @0x2b95bc ldr r5, [r5, #0x24]
 *   @0x2b95c0 cmp r5, #0
 *   @0x2b95c4 beq 0x2b95f4 <jpeg_std_error+0x634>
 *   @0x2b95c8 ldrb r3, [r5, #0x22]
 *   @0x2b95cc cmp r3, #0
 *   @0x2b95d0 beq 0x2b95bc <jpeg_std_error+0x5fc>
 *   @0x2b95d4 strb r6, [r5, #0x22]
 *   @0x2b95d8 add r1, r5, #40
 *   @0x2b95dc ldr r3, [r5, #0x30]
 *   @0x2b95e0 mov r0, r7
 *   @0x2b95e4 blx r3
 *   @0x2b95e8 ldr r5, [r5, #0x24]
 *   @0x2b95ec cmp r5, #0
 *   @0x2b95f0 bne 0x2b95c8 <jpeg_std_error+0x608>
 *   @0x2b95f4 mov r3, #0
 *   @0x2b95f8 str r3, [r4, #0x48]
 *   @0x2b95fc b 0x2b94ac <jpeg_std_error+0x4ec>
 *   @0x2b9600 push {r4, lr}
 *   @0x2b9604 mov r1, #1
 *   @0x2b9608 mov r4, r0
 *   @0x2b960c bl 0x2b9478 <jpeg_std_error+0x4b8>
 *   @0x2b9610 mov r0, r4
 *   @0x2b9614 mov r1, #0
 *   @0x2b9618 bl 0x2b9478 <jpeg_std_error+0x4b8>
 *   @0x2b961c mov r0, r4
 *   @0x2b9620 ldr r1, [r4, #0x4]
 *   @0x2b9624 mov r2, #84
 *   @0x2b9628 bl 0x2c1384 <jpeg_free_small>
 *   @0x2b962c mov r3, #0
 *   @0x2b9630 mov r0, r4
 *   @0x2b9634 str r3, [r4, #0x4]
 *   @0x2b9638 pop {r4, lr}
 *   @0x2b963c b 0x2c1438 <jpeg_mem_term>
 *   @0x2b9640 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2b9644 mov r7, r2
 *   @0x2b9648 ldr r2, [r1, #0x4]
 *   @0x2b964c add r6, r7, r3
 *   @0x2b9650 mov r4, r1
 *   @0x2b9654 mov r8, r0
 *   @0x2b9658 cmp r6, r2
 *   @0x2b965c ldrb r9, [sp, #0x20]
 *   @0x2b9660 bhi 0x2b9670 <jpeg_std_error+0x6b0>
 *   @0x2b9664 ldr r2, [r1, #0xc]
 *   @0x2b9668 cmp r3, r2
 *   @0x2b966c bls 0x2b97c4 <jpeg_std_error+0x804>
 *   @0x2b9670 ldr r3, [r8]
 *   @0x2b9674 mov r2, #22
 *   @0x2b9678 mov r0, r8
 *   @0x2b967c str r2, [r3, #0x14]
 *   @0x2b9680 ldr r3, [r3]
 *   @0x2b9684 blx r3
 *   @0x2b9688 ldr r3, [r4, #0x18]
 *   @0x2b968c cmp r7, r3
 *   @0x2b9690 blo 0x2b96a4 <jpeg_std_error+0x6e4>
 *   @0x2b9694 ldr r2, [r4, #0x10]
 *   @0x2b9698 add r3, r3, r2
 *   @0x2b969c cmp r6, r3
 *   @0x2b96a0 bls 0x2b96e8 <jpeg_std_error+0x728>
 *   @0x2b96a4 ldrb r3, [r4, #0x22]
 *   @0x2b96a8 cmp r3, #0
 *   @0x2b96ac beq 0x2b97fc <jpeg_std_error+0x83c>
 *   @0x2b96b0 ldrb r3, [r4, #0x21]
 *   @0x2b96b4 cmp r3, #0
 *   @0x2b96b8 bne 0x2b97e0 <jpeg_std_error+0x820>
 *   @0x2b96bc ldr r3, [r4, #0x18]
 *   @0x2b96c0 mov r0, r8
 *   @0x2b96c4 mov r1, r4
 *   @0x2b96c8 mov r2, #0
 *   @0x2b96cc cmp r7, r3
 *   @0x2b96d0 strhi r7, [r4, #0x18]
 *   @0x2b96d4 ldrls r3, [r4, #0x10]
 *   @0x2b96d8 rsbls r3, r3, r6
 *   @0x2b96dc bicls r3, r3, r3, asr #31
 *   @0x2b96e0 strls r3, [r4, #0x18]
 *   @0x2b96e4 bl 0x2b9054 <jpeg_std_error+0x94>
 *   @0x2b96e8 ldr r5, [r4, #0x1c]
 *   @0x2b96ec cmp r6, r5
 *   @0x2b96f0 bls 0x2b97a0 <jpeg_std_error+0x7e0>
 *   @0x2b96f4 cmp r7, r5
 *   @0x2b96f8 bls 0x2b97d4 <jpeg_std_error+0x814>
 *   @0x2b96fc cmp r9, #0
 *   @0x2b9700 moveq r5, r7
 *   @0x2b9704 bne 0x2b9734 <jpeg_std_error+0x774>
 *   @0x2b9708 ldrb r3, [r4, #0x20]
 *   @0x2b970c cmp r3, #0
 *   @0x2b9710 bne 0x2b9760 <jpeg_std_error+0x7a0>
 *   @0x2b9714 ldr r3, [r8]
 *   @0x2b9718 mov r0, r8
 *   @0x2b971c mov r1, #22
 *   @0x2b9720 ldr r2, [r3]
 *   @0x2b9724 str r1, [r3, #0x14]
 *   @0x2b9728 blx r2
 *   @0x2b972c ldr r0, [r4, #0x18]
 *   @0x2b9730 b 0x2b97b4 <jpeg_std_error+0x7f4>
 *   @0x2b9734 ldr r3, [r8]
 *   @0x2b9738 mov r1, #22
 *   @0x2b973c mov r0, r8
 *   @0x2b9740 mov r5, r7
 *   @0x2b9744 ldr r2, [r3]
 *   @0x2b9748 str r1, [r3, #0x14]
 *   @0x2b974c blx r2
 *   @0x2b9750 ldrb r3, [r4, #0x20]
 *   @0x2b9754 str r6, [r4, #0x1c]
 *   @0x2b9758 cmp r3, #0
 *   @0x2b975c beq 0x2b9818 <jpeg_std_error+0x858>
 *   @0x2b9760 ldr r0, [r4, #0x18]
 *   @0x2b9764 ldr r10, [r4, #0x8]
 *   @0x2b9768 rsb r5, r0, r5
 *   @0x2b976c rsb r8, r0, r6
 *   @0x2b9770 cmp r5, r8
 *   @0x2b9774 lsl r10, r10, #7
 *   @0x2b9778 bhs 0x2b97a4 <jpeg_std_error+0x7e4>
 *   @0x2b977c lsl r6, r5, #2
 *   @0x2b9780 ldr r3, [r4]
 *   @0x2b9784 add r5, r5, #1
 *   @0x2b9788 mov r1, r10
 *   @0x2b978c ldr r0, [r3, r6]
 *   @0x2b9790 add r6, r6, #4
 *   @0x2b9794 bl 0x2bc868 <jzero_far>
 *   @0x2b9798 cmp r8, r5
 *   @0x2b979c bhi 0x2b9780 <jpeg_std_error+0x7c0>
 *   @0x2b97a0 ldr r0, [r4, #0x18]
 *   @0x2b97a4 cmp r9, #0
 *   @0x2b97a8 beq 0x2b97b4 <jpeg_std_error+0x7f4>
 *   @0x2b97ac mov r3, #1
 *   @0x2b97b0 strb r3, [r4, #0x21]
 *   @0x2b97b4 rsb r7, r0, r7
 *   @0x2b97b8 ldr r3, [r4]
 *   @0x2b97bc add r0, r3, r7, lsl #2
 *   @0x2b97c0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2b97c4 ldr r3, [r1]
 *   @0x2b97c8 cmp r3, #0
 *   @0x2b97cc bne 0x2b9688 <jpeg_std_error+0x6c8>
 *   @0x2b97d0 b 0x2b9670 <jpeg_std_error+0x6b0>
 *   @0x2b97d4 cmp r9, #0
 *   @0x2b97d8 bne 0x2b9750 <jpeg_std_error+0x790>
 *   @0x2b97dc b 0x2b9708 <jpeg_std_error+0x748>
 *   @0x2b97e0 mov r0, r8
 *   @0x2b97e4 mov r1, r4
 *   @0x2b97e8 mov r2, #1
 *   @0x2b97ec bl 0x2b9054 <jpeg_std_error+0x94>
 *   @0x2b97f0 mov r3, #0
 *   @0x2b97f4 strb r3, [r4, #0x21]
 *   @0x2b97f8 b 0x2b96bc <jpeg_std_error+0x6fc>
 *   @0x2b97fc ldr r3, [r8]
 *   @0x2b9800 mov r2, #69
 *   @0x2b9804 mov r0, r8
 *   @0x2b9808 str r2, [r3, #0x14]
 *   @0x2b980c ldr r3, [r3]
 *   @0x2b9810 blx r3
 *   @0x2b9814 b 0x2b96b0 <jpeg_std_error+0x6f0>
 *   @0x2b9818 ldr r0, [r4, #0x18]
 *   @0x2b981c b 0x2b97ac <jpeg_std_error+0x7ec>
 *   @0x2b9820 movw r3, #0xc9f0
 *   @0x2b9824 movt r3, #0x3b9a
 *   @0x2b9828 cmp r2, r3
 *   @0x2b982c push {r4, r5, r6, r7, r8, lr}
 *   @0x2b9830 mov r4, r2
 *   @0x2b9834 mov r6, r0
 *   @0x2b9838 mov r8, r1
 *   @0x2b983c ldr r7, [r0, #0x4]
 *   @0x2b9840 bhi 0x2b98c0 <jpeg_std_error+0x900>
 *   @0x2b9844 ands r3, r4, #7
 *   @0x2b9848 addne r4, r4, #8
 *   @0x2b984c rsbne r4, r3, r4
 *   @0x2b9850 cmp r8, #1
 *   @0x2b9854 bls 0x2b9878 <jpeg_std_error+0x8b8>
 *   @0x2b9858 ldr r3, [r6]
 *   @0x2b985c mov r1, #14
 *   @0x2b9860 mov r0, r6
 *   @0x2b9864 str r8, [r3, #0x18]
 *   @0x2b9868 ldr r2, [r6]
 *   @0x2b986c str r1, [r3, #0x14]
 *   @0x2b9870 ldr r3, [r2]
 *   @0x2b9874 blx r3
 *   @0x2b9878 mov r0, r6
 *   @0x2b987c add r1, r4, #16
 *   @0x2b9880 bl 0x2c138c <jpeg_get_large>
 *   @0x2b9884 subs r5, r0, #0
 *   @0x2b9888 beq 0x2b98e4 <jpeg_std_error+0x924>
 *   @0x2b988c ldr r3, [r7, #0x4c]
 *   @0x2b9890 add r8, r7, r8, lsl #2
 *   @0x2b9894 mov r2, #0
 *   @0x2b9898 add r0, r5, #16
 *   @0x2b989c add r3, r3, #16
 *   @0x2b98a0 add r3, r3, r4
 *   @0x2b98a4 str r3, [r7, #0x4c]
 *   @0x2b98a8 ldr r3, [r8, #0x3c]
 *   @0x2b98ac str r4, [r5, #0x4]
 *   @0x2b98b0 str r2, [r5, #0x8]
 *   @0x2b98b4 str r3, [r5]
 *   @0x2b98b8 str r5, [r8, #0x3c]
 *   @0x2b98bc pop {r4, r5, r6, r7, r8, pc}
 *   @0x2b98c0 ldr r3, [r0]
 *   @0x2b98c4 mov r2, #3
 *   @0x2b98c8 mov r1, #54
 *   @0x2b98cc str r2, [r3, #0x18]
 *   @0x2b98d0 ldr r2, [r0]
 *   @0x2b98d4 str r1, [r3, #0x14]
 *   @0x2b98d8 ldr r3, [r2]
 *   @0x2b98dc blx r3
 *   @0x2b98e0 b 0x2b9844 <jpeg_std_error+0x884>
 *   @0x2b98e4 ldr r3, [r6]
 *   @0x2b98e8 mov r2, #4
 *   @0x2b98ec mov r1, #54
 *   @0x2b98f0 mov r0, r6
 *   @0x2b98f4 str r2, [r3, #0x18]
 *   @0x2b98f8 ldr r2, [r6]
 *   @0x2b98fc str r1, [r3, #0x14]
 *   @0x2b9900 ldr r3, [r2]
 *   @0x2b9904 blx r3
 *   @0x2b9908 b 0x2b988c <jpeg_std_error+0x8cc>
 *   @0x2b990c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2b9910 lsl r4, r2, #7
 *   @0x2b9914 mov r7, r0
 *   @0x2b9918 mov r8, r1
 *   @0x2b991c movw r0, #0xc9f0
 *   @0x2b9920 mov r1, r4
 *   @0x2b9924 movt r0, #0x3b9a
 *   @0x2b9928 mov r9, r3
 *   @0x2b992c bl 0x318c48 <__udivsi3>
 *   @0x2b9930 ldr r5, [r7, #0x4]
 *   @0x2b9934 subs r6, r0, #0
 *   @0x2b9938 beq 0x2b99b8 <jpeg_std_error+0x9f8>
 *   @0x2b993c cmp r6, r9
 *   @0x2b9940 movge r6, r9
 *   @0x2b9944 mov r0, r7
 *   @0x2b9948 str r6, [r5, #0x50]
 *   @0x2b994c mov r1, r8
 *   @0x2b9950 lsl r2, r9, #2
 *   @0x2b9954 bl 0x2b91d0 <jpeg_std_error+0x210>
 *   @0x2b9958 cmp r9, #0
 *   @0x2b995c mov r10, r0
 *   @0x2b9960 beq 0x2b99b0 <jpeg_std_error+0x9f0>
 *   @0x2b9964 mov r5, #0
 *   @0x2b9968 rsb r3, r5, r9
 *   @0x2b996c mov r0, r7
 *   @0x2b9970 cmp r6, r3
 *   @0x2b9974 movhs r6, r3
 *   @0x2b9978 mov r1, r8
 *   @0x2b997c mul r2, r4, r6
 *   @0x2b9980 bl 0x2b9820 <jpeg_std_error+0x860>
 *   @0x2b9984 cmp r6, #0
 *   @0x2b9988 beq 0x2b99a8 <jpeg_std_error+0x9e8>
 *   @0x2b998c add r12, r10, r5, lsl #2
 *   @0x2b9990 add r5, r5, r6
 *   @0x2b9994 add r2, r10, r5, lsl #2
 *   @0x2b9998 str r0, [r12], #4
 *   @0x2b999c cmp r12, r2
 *   @0x2b99a0 add r0, r0, r4
 *   @0x2b99a4 bne 0x2b9998 <jpeg_std_error+0x9d8>
 *   @0x2b99a8 cmp r9, r5
 *   @0x2b99ac bhi 0x2b9968 <jpeg_std_error+0x9a8>
 *   @0x2b99b0 mov r0, r10
 *   @0x2b99b4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2b99b8 ldr r3, [r7]
 *   @0x2b99bc mov r2, #70
 *   @0x2b99c0 mov r0, r7
 *   @0x2b99c4 str r2, [r3, #0x14]
 *   @0x2b99c8 ldr r3, [r3]
 *   @0x2b99cc blx r3
 *   @0x2b99d0 b 0x2b993c <jpeg_std_error+0x97c>
 *   @0x2b99d4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2b99d8 mov r7, r0
 *   @0x2b99dc mov r8, r1
 *   @0x2b99e0 movw r0, #0xc9f0
 *   @0x2b99e4 mov r1, r2
 *   @0x2b99e8 movt r0, #0x3b9a
 *   @0x2b99ec mov r4, r2
 *   @0x2b99f0 mov r9, r3
 *   @0x2b99f4 bl 0x318c48 <__udivsi3>
 *   @0x2b99f8 ldr r5, [r7, #0x4]
 *   @0x2b99fc subs r6, r0, #0
 *   @0x2b9a00 beq 0x2b9a80 <jpeg_std_error+0xac0>
 *   @0x2b9a04 cmp r6, r9
 *   @0x2b9a08 movge r6, r9
 *   @0x2b9a0c mov r0, r7
 *   @0x2b9a10 str r6, [r5, #0x50]
 *   @0x2b9a14 mov r1, r8
 *   @0x2b9a18 lsl r2, r9, #2
 *   @0x2b9a1c bl 0x2b91d0 <jpeg_std_error+0x210>
 *   @0x2b9a20 cmp r9, #0
 *   @0x2b9a24 mov r10, r0
 *   @0x2b9a28 beq 0x2b9a78 <jpeg_std_error+0xab8>
 *   @0x2b9a2c mov r5, #0
 *   @0x2b9a30 rsb r3, r5, r9
 *   @0x2b9a34 mov r0, r7
 *   @0x2b9a38 cmp r6, r3
 *   @0x2b9a3c movhs r6, r3
 *   @0x2b9a40 mov r1, r8
 *   @0x2b9a44 mul r2, r4, r6
 *   @0x2b9a48 bl 0x2b9820 <jpeg_std_error+0x860>
 *   @0x2b9a4c cmp r6, #0
 *   @0x2b9a50 beq 0x2b9a70 <jpeg_std_error+0xab0>
 *   @0x2b9a54 add r12, r10, r5, lsl #2
 *   @0x2b9a58 add r5, r5, r6
 *   @0x2b9a5c add r2, r10, r5, lsl #2
 *   @0x2b9a60 str r0, [r12], #4
 *   @0x2b9a64 cmp r12, r2
 *   @0x2b9a68 add r0, r0, r4
 *   @0x2b9a6c bne 0x2b9a60 <jpeg_std_error+0xaa0>
 *   @0x2b9a70 cmp r9, r5
 *   @0x2b9a74 bhi 0x2b9a30 <jpeg_std_error+0xa70>
 *   @0x2b9a78 mov r0, r10
 *   @0x2b9a7c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2b9a80 ldr r3, [r7]
 *   @0x2b9a84 mov r2, #70
 *   @0x2b9a88 mov r0, r7
 *   @0x2b9a8c str r2, [r3, #0x14]
 *   @0x2b9a90 ldr r3, [r3]
 *   @0x2b9a94 blx r3
 *   @0x2b9a98 b 0x2b9a04 <jpeg_std_error+0xa44>
 *   @0x2b9a9c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b9aa0 mov r6, r0
 *   @0x2b9aa4 ldr r5, [r0, #0x4]
 *   @0x2b9aa8 ldr r3, [r5, #0x44]
 *   @0x2b9aac cmp r3, #0
 *   @0x2b9ab0 beq 0x2b9ce8 <jpeg_std_error+0xd28>
 *   @0x2b9ab4 mov r4, #0
 *   @0x2b9ab8 mov r7, r4
 *   @0x2b9abc ldr r12, [r3]
 *   @0x2b9ac0 cmp r12, #0
 *   @0x2b9ac4 ldreq r2, [r3, #0x8]
 *   @0x2b9ac8 ldreq r0, [r3, #0xc]
 *   @0x2b9acc ldreq r1, [r3, #0x4]
 *   @0x2b9ad0 ldr r3, [r3, #0x24]
 *   @0x2b9ad4 mlaeq r7, r0, r2, r7
 *   @0x2b9ad8 mlaeq r4, r1, r2, r4
 *   @0x2b9adc cmp r3, #0
 *   @0x2b9ae0 bne 0x2b9abc <jpeg_std_error+0xafc>
 *   @0x2b9ae4 ldr r3, [r5, #0x48]
 *   @0x2b9ae8 cmp r3, #0
 *   @0x2b9aec bne 0x2b9b00 <jpeg_std_error+0xb40>
 *   @0x2b9af0 b 0x2b9b34 <jpeg_std_error+0xb74>
 *   @0x2b9af4 ldr r3, [r3, #0x24]
 *   @0x2b9af8 cmp r3, #0
 *   @0x2b9afc beq 0x2b9b34 <jpeg_std_error+0xb74>
 *   @0x2b9b00 ldr r12, [r3]
 *   @0x2b9b04 cmp r12, #0
 *   @0x2b9b08 bne 0x2b9af4 <jpeg_std_error+0xb34>
 *   @0x2b9b0c ldr r2, [r3, #0x8]
 *   @0x2b9b10 ldr r1, [r3, #0xc]
 *   @0x2b9b14 ldr r0, [r3, #0x4]
 *   @0x2b9b18 ldr r3, [r3, #0x24]
 *   @0x2b9b1c mul r1, r1, r2
 *   @0x2b9b20 cmp r3, #0
 *   @0x2b9b24 mul r2, r0, r2
 *   @0x2b9b28 add r7, r7, r1, lsl #7
 *   @0x2b9b2c add r4, r4, r2, lsl #7
 *   @0x2b9b30 bne 0x2b9b00 <jpeg_std_error+0xb40>
 *   @0x2b9b34 cmp r7, #0
 *   @0x2b9b38 pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b9b3c mov r0, r6
 *   @0x2b9b40 mov r1, r7
 *   @0x2b9b44 mov r2, r4
 *   @0x2b9b48 ldr r3, [r5, #0x4c]
 *   @0x2b9b4c bl 0x2c139c <jpeg_mem_available>
 *   @0x2b9b50 cmp r0, r4
 *   @0x2b9b54 movge r8, #51712
 *   @0x2b9b58 movtge r8, #0x3b9a
 *   @0x2b9b5c blt 0x2b9c7c <jpeg_std_error+0xcbc>
 *   @0x2b9b60 ldr r4, [r5, #0x44]
 *   @0x2b9b64 cmp r4, #0
 *   @0x2b9b68 movne r10, #1
 *   @0x2b9b6c movne r9, #0
 *   @0x2b9b70 bne 0x2b9b84 <jpeg_std_error+0xbc4>
 *   @0x2b9b74 b 0x2b9bec <jpeg_std_error+0xc2c>
 *   @0x2b9b78 ldr r4, [r4, #0x24]
 *   @0x2b9b7c cmp r4, #0
 *   @0x2b9b80 beq 0x2b9bec <jpeg_std_error+0xc2c>
 *   @0x2b9b84 ldr r3, [r4]
 *   @0x2b9b88 cmp r3, #0
 *   @0x2b9b8c bne 0x2b9b78 <jpeg_std_error+0xbb8>
 *   @0x2b9b90 ldr r11, [r4, #0xc]
 *   @0x2b9b94 ldr r7, [r4, #0x4]
 *   @0x2b9b98 mov r1, r11
 *   @0x2b9b9c sub r0, r7, #1
 *   @0x2b9ba0 bl 0x318c48 <__udivsi3>
 *   @0x2b9ba4 mov r3, r7
 *   @0x2b9ba8 add r0, r0, #1
 *   @0x2b9bac cmp r8, r0
 *   @0x2b9bb0 strge r7, [r4, #0x10]
 *   @0x2b9bb4 blt 0x2b9cc0 <jpeg_std_error+0xd00>
 *   @0x2b9bb8 ldr r2, [r4, #0x8]
 *   @0x2b9bbc mov r1, #1
 *   @0x2b9bc0 mov r0, r6
 *   @0x2b9bc4 bl 0x2b99d4 <jpeg_std_error+0xa14>
 *   @0x2b9bc8 ldr r3, [r5, #0x50]
 *   @0x2b9bcc str r9, [r4, #0x18]
 *   @0x2b9bd0 str r9, [r4, #0x1c]
 *   @0x2b9bd4 str r3, [r4, #0x14]
 *   @0x2b9bd8 strb r9, [r4, #0x21]
 *   @0x2b9bdc str r0, [r4]
 *   @0x2b9be0 ldr r4, [r4, #0x24]
 *   @0x2b9be4 cmp r4, #0
 *   @0x2b9be8 bne 0x2b9b84 <jpeg_std_error+0xbc4>
 *   @0x2b9bec ldr r4, [r5, #0x48]
 *   @0x2b9bf0 cmp r4, #0
 *   @0x2b9bf4 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b9bf8 mov r10, #1
 *   @0x2b9bfc mov r9, #0
 *   @0x2b9c00 b 0x2b9c10 <jpeg_std_error+0xc50>
 *   @0x2b9c04 ldr r4, [r4, #0x24]
 *   @0x2b9c08 cmp r4, #0
 *   @0x2b9c0c beq 0x2b9c78 <jpeg_std_error+0xcb8>
 *   @0x2b9c10 ldr r3, [r4]
 *   @0x2b9c14 cmp r3, #0
 *   @0x2b9c18 bne 0x2b9c04 <jpeg_std_error+0xc44>
 *   @0x2b9c1c ldr r11, [r4, #0xc]
 *   @0x2b9c20 ldr r7, [r4, #0x4]
 *   @0x2b9c24 mov r1, r11
 *   @0x2b9c28 sub r0, r7, #1
 *   @0x2b9c2c bl 0x318c48 <__udivsi3>
 *   @0x2b9c30 mov r3, r7
 *   @0x2b9c34 add r0, r0, #1
 *   @0x2b9c38 cmp r8, r0
 *   @0x2b9c3c strge r7, [r4, #0x10]
 *   @0x2b9c40 blt 0x2b9c94 <jpeg_std_error+0xcd4>
 *   @0x2b9c44 ldr r2, [r4, #0x8]
 *   @0x2b9c48 mov r1, #1
 *   @0x2b9c4c mov r0, r6
 *   @0x2b9c50 bl 0x2b990c <jpeg_std_error+0x94c>
 *   @0x2b9c54 ldr r3, [r5, #0x50]
 *   @0x2b9c58 str r9, [r4, #0x18]
 *   @0x2b9c5c str r9, [r4, #0x1c]
 *   @0x2b9c60 str r3, [r4, #0x14]
 *   @0x2b9c64 strb r9, [r4, #0x21]
 *   @0x2b9c68 str r0, [r4]
 *   @0x2b9c6c ldr r4, [r4, #0x24]
 *   @0x2b9c70 cmp r4, #0
 *   @0x2b9c74 bne 0x2b9c10 <jpeg_std_error+0xc50>
 *   @0x2b9c78 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b9c7c mov r1, r7
 *   @0x2b9c80 bl 0x318d10 <__divsi3>
 *   @0x2b9c84 cmp r0, #1
 *   @0x2b9c88 movge r8, r0
 *   @0x2b9c8c movlt r8, #1
 *   @0x2b9c90 b 0x2b9b60 <jpeg_std_error+0xba0>
 *   @0x2b9c94 ldr r2, [r4, #0x8]
 *   @0x2b9c98 mov r0, r6
 *   @0x2b9c9c mul r11, r11, r8
 *   @0x2b9ca0 add r1, r4, #40
 *   @0x2b9ca4 mul r2, r2, r7
 *   @0x2b9ca8 str r11, [r4, #0x10]
 *   @0x2b9cac lsl r2, r2, #7
 *   @0x2b9cb0 bl 0x2c13ac <jpeg_open_backing_store>
 *   @0x2b9cb4 ldr r3, [r4, #0x10]
 *   @0x2b9cb8 strb r10, [r4, #0x22]
 *   @0x2b9cbc b 0x2b9c44 <jpeg_std_error+0xc84>
 *   @0x2b9cc0 mul r11, r11, r8
 *   @0x2b9cc4 ldr r2, [r4, #0x8]
 *   @0x2b9cc8 mov r0, r6
 *   @0x2b9ccc add r1, r4, #40
 *   @0x2b9cd0 mul r2, r2, r7
 *   @0x2b9cd4 str r11, [r4, #0x10]
 *   @0x2b9cd8 bl 0x2c13ac <jpeg_open_backing_store>
 *   @0x2b9cdc ldr r3, [r4, #0x10]
 *   @0x2b9ce0 strb r10, [r4, #0x22]
 *   @0x2b9ce4 b 0x2b9bb8 <jpeg_std_error+0xbf8>
 *   @0x2b9ce8 mov r4, r3
 *   @0x2b9cec mov r7, r3
 *   @0x2b9cf0 b 0x2b9ae4 <jpeg_std_error+0xb24>
 *   @0x2b9cf4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b9cf8 sub sp, sp, #28
 *   @0x2b9cfc mov r8, r2
 *   @0x2b9d00 ldr r2, [r1, #0x4]
 *   @0x2b9d04 add r9, r8, r3
 *   @0x2b9d08 ldrb r11, [sp, #0x40]
 *   @0x2b9d0c cmp r9, r2
 *   @0x2b9d10 mov r4, r1
 *   @0x2b9d14 mov r6, r0
 *   @0x2b9d18 str r11, [sp, #0x10]
 *   @0x2b9d1c bhi 0x2b9d2c <jpeg_std_error+0xd6c>
 *   @0x2b9d20 ldr r2, [r1, #0xc]
 *   @0x2b9d24 cmp r3, r2
 *   @0x2b9d28 bls 0x2b9f44 <jpeg_std_error+0xf84>
 *   @0x2b9d2c ldr r3, [r6]
 *   @0x2b9d30 mov r2, #22
 *   @0x2b9d34 mov r0, r6
 *   @0x2b9d38 str r2, [r3, #0x14]
 *   @0x2b9d3c ldr r3, [r3]
 *   @0x2b9d40 blx r3
 *   @0x2b9d44 ldr r2, [r4, #0x18]
 *   @0x2b9d48 cmp r8, r2
 *   @0x2b9d4c blo 0x2b9d60 <jpeg_std_error+0xda0>
 *   @0x2b9d50 ldr r3, [r4, #0x10]
 *   @0x2b9d54 add r3, r2, r3
 *   @0x2b9d58 cmp r9, r3
 *   @0x2b9d5c bls 0x2b9e60 <jpeg_std_error+0xea0>
 *   @0x2b9d60 ldrb r3, [r4, #0x22]
 *   @0x2b9d64 cmp r3, #0
 *   @0x2b9d68 beq 0x2ba068 <jpeg_std_error+0x10a8>
 *   @0x2b9d6c ldrb r3, [r4, #0x21]
 *   @0x2b9d70 cmp r3, #0
 *   @0x2b9d74 bne 0x2b9f64 <jpeg_std_error+0xfa4>
 *   @0x2b9d78 ldr r7, [r4, #0x8]
 *   @0x2b9d7c ldr r1, [r4, #0x10]
 *   @0x2b9d80 ldr r0, [r4, #0x1c]
 *   @0x2b9d84 mov r10, r7
 *   @0x2b9d88 cmp r8, r2
 *   @0x2b9d8c strhi r8, [r4, #0x18]
 *   @0x2b9d90 rsbls r11, r1, r9
 *   @0x2b9d94 bicls r11, r11, r11, asr #31
 *   @0x2b9d98 movhi r11, r8
 *   @0x2b9d9c strls r11, [r4, #0x18]
 *   @0x2b9da0 cmp r1, #0
 *   @0x2b9da4 mul r7, r7, r11
 *   @0x2b9da8 ble 0x2b9e64 <jpeg_std_error+0xea4>
 *   @0x2b9dac ldr r12, [r4, #0x14]
 *   @0x2b9db0 rsb r3, r11, r0
 *   @0x2b9db4 ldr r2, [r4, #0x4]
 *   @0x2b9db8 cmp r1, r12
 *   @0x2b9dbc movge r1, r12
 *   @0x2b9dc0 rsb r11, r11, r2
 *   @0x2b9dc4 cmp r1, r11
 *   @0x2b9dc8 movge r1, r11
 *   @0x2b9dcc cmp r1, r3
 *   @0x2b9dd0 movge r1, r3
 *   @0x2b9dd4 cmp r1, #0
 *   @0x2b9dd8 ble 0x2b9e64 <jpeg_std_error+0xea4>
 *   @0x2b9ddc add r11, r4, #40
 *   @0x2b9de0 mov r5, #0
 *   @0x2b9de4 b 0x2b9e20 <jpeg_std_error+0xe60>
 *   @0x2b9de8 ldr r3, [r4, #0x18]
 *   @0x2b9dec cmp r2, r1
 *   @0x2b9df0 movge r2, r1
 *   @0x2b9df4 ldr r0, [r4, #0x1c]
 *   @0x2b9df8 add r3, r5, r3
 *   @0x2b9dfc ldr r12, [r4, #0x4]
 *   @0x2b9e00 rsb r1, r3, r0
 *   @0x2b9e04 cmp r1, r2
 *   @0x2b9e08 movge r1, r2
 *   @0x2b9e0c rsb r3, r3, r12
 *   @0x2b9e10 cmp r1, r3
 *   @0x2b9e14 movge r1, r3
 *   @0x2b9e18 cmp r1, #0
 *   @0x2b9e1c ble 0x2b9e64 <jpeg_std_error+0xea4>
 *   @0x2b9e20 mul lr, r10, r1
 *   @0x2b9e24 ldr r2, [r4]
 *   @0x2b9e28 mov r3, r7
 *   @0x2b9e2c ldr r12, [r4, #0x28]
 *   @0x2b9e30 mov r1, r11
 *   @0x2b9e34 mov r0, r6
 *   @0x2b9e38 ldr r2, [r2, r5, lsl #2]
 *   @0x2b9e3c add r7, r7, lr
 *   @0x2b9e40 str lr, [sp]
 *   @0x2b9e44 blx r12
 *   @0x2b9e48 ldr r2, [r4, #0x14]
 *   @0x2b9e4c ldr r3, [r4, #0x10]
 *   @0x2b9e50 add r5, r2, r5
 *   @0x2b9e54 cmp r3, r5
 *   @0x2b9e58 rsb r1, r5, r3
 *   @0x2b9e5c bgt 0x2b9de8 <jpeg_std_error+0xe28>
 *   @0x2b9e60 ldr r0, [r4, #0x1c]
 *   @0x2b9e64 cmp r9, r0
 *   @0x2b9e68 bls 0x2b9f18 <jpeg_std_error+0xf58>
 *   @0x2b9e6c cmp r8, r0
 *   @0x2b9e70 bls 0x2b9f54 <jpeg_std_error+0xf94>
 *   @0x2b9e74 ldr r12, [sp, #0x10]
 *   @0x2b9e78 cmp r12, #0
 *   @0x2b9e7c moveq r0, r8
 *   @0x2b9e80 bne 0x2b9eb0 <jpeg_std_error+0xef0>
 *   @0x2b9e84 ldrb r3, [r4, #0x20]
 *   @0x2b9e88 cmp r3, #0
 *   @0x2b9e8c bne 0x2b9edc <jpeg_std_error+0xf1c>
 *   @0x2b9e90 ldr r3, [r6]
 *   @0x2b9e94 mov r0, r6
 *   @0x2b9e98 mov r1, #22
 *   @0x2b9e9c ldr r2, [r3]
 *   @0x2b9ea0 str r1, [r3, #0x14]
 *   @0x2b9ea4 blx r2
 *   @0x2b9ea8 ldr r0, [r4, #0x18]
 *   @0x2b9eac b 0x2b9f30 <jpeg_std_error+0xf70>
 *   @0x2b9eb0 ldr r3, [r6]
 *   @0x2b9eb4 mov r0, r6
 *   @0x2b9eb8 mov r1, #22
 *   @0x2b9ebc ldr r2, [r3]
 *   @0x2b9ec0 str r1, [r3, #0x14]
 *   @0x2b9ec4 blx r2
 *   @0x2b9ec8 mov r0, r8
 *   @0x2b9ecc ldrb r3, [r4, #0x20]
 *   @0x2b9ed0 str r9, [r4, #0x1c]
 *   @0x2b9ed4 cmp r3, #0
 *   @0x2b9ed8 beq 0x2ba088 <jpeg_std_error+0x10c8>
 *   @0x2b9edc ldr r3, [r4, #0x18]
 *   @0x2b9ee0 ldr r7, [r4, #0x8]
 *   @0x2b9ee4 rsb r5, r3, r0
 *   @0x2b9ee8 rsb r9, r3, r9
 *   @0x2b9eec cmp r5, r9
 *   @0x2b9ef0 bhs 0x2ba0ac <jpeg_std_error+0x10ec>
 *   @0x2b9ef4 lsl r6, r5, #2
 *   @0x2b9ef8 ldr r3, [r4]
 *   @0x2b9efc add r5, r5, #1
 *   @0x2b9f00 mov r1, r7
 *   @0x2b9f04 ldr r0, [r3, r6]
 *   @0x2b9f08 add r6, r6, #4
 *   @0x2b9f0c bl 0x2bc868 <jzero_far>
 *   @0x2b9f10 cmp r9, r5
 *   @0x2b9f14 bhi 0x2b9ef8 <jpeg_std_error+0xf38>
 *   @0x2b9f18 ldr r0, [r4, #0x18]
 *   @0x2b9f1c ldr r12, [sp, #0x10]
 *   @0x2b9f20 cmp r12, #0
 *   @0x2b9f24 beq 0x2b9f30 <jpeg_std_error+0xf70>
 *   @0x2b9f28 mov r3, #1
 *   @0x2b9f2c strb r3, [r4, #0x21]
 *   @0x2b9f30 rsb r8, r0, r8
 *   @0x2b9f34 ldr r3, [r4]
 *   @0x2b9f38 add r0, r3, r8, lsl #2
 *   @0x2b9f3c add sp, sp, #28
 *   @0x2b9f40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b9f44 ldr r3, [r1]
 *   @0x2b9f48 cmp r3, #0
 *   @0x2b9f4c bne 0x2b9d44 <jpeg_std_error+0xd84>
 *   @0x2b9f50 b 0x2b9d2c <jpeg_std_error+0xd6c>
 *   @0x2b9f54 ldr r11, [sp, #0x10]
 *   @0x2b9f58 cmp r11, #0
 *   @0x2b9f5c bne 0x2b9ecc <jpeg_std_error+0xf0c>
 *   @0x2b9f60 b 0x2b9e84 <jpeg_std_error+0xec4>
 *   @0x2b9f64 ldr r1, [r4, #0x10]
 *   @0x2b9f68 ldr r10, [r4, #0x8]
 *   @0x2b9f6c cmp r1, #0
 *   @0x2b9f70 mul r7, r10, r2
 *   @0x2b9f74 ldrle r0, [r4, #0x1c]
 *   @0x2b9f78 movle r7, r10
 *   @0x2b9f7c ble 0x2ba05c <jpeg_std_error+0x109c>
 *   @0x2b9f80 ldr r12, [r4, #0x14]
 *   @0x2b9f84 ldr r3, [r4, #0x4]
 *   @0x2b9f88 ldr r0, [r4, #0x1c]
 *   @0x2b9f8c cmp r12, r1
 *   @0x2b9f90 movge r12, r1
 *   @0x2b9f94 rsb r3, r2, r3
 *   @0x2b9f98 cmp r12, r3
 *   @0x2b9f9c movge r12, r3
 *   @0x2b9fa0 rsb r3, r2, r0
 *   @0x2b9fa4 cmp r12, r3
 *   @0x2b9fa8 movge r12, r3
 *   @0x2b9fac cmp r12, #0
 *   @0x2b9fb0 ble 0x2ba0a4 <jpeg_std_error+0x10e4>
 *   @0x2b9fb4 add r2, r4, #40
 *   @0x2b9fb8 str r9, [sp, #0x14]
 *   @0x2b9fbc str r2, [sp, #0xc]
 *   @0x2b9fc0 mov r5, #0
 *   @0x2b9fc4 mov r9, r2
 *   @0x2b9fc8 b 0x2ba004 <jpeg_std_error+0x1044>
 *   @0x2b9fcc ldr r2, [r4, #0x18]
 *   @0x2b9fd0 cmp r11, r1
 *   @0x2b9fd4 movge r11, r1
 *   @0x2b9fd8 ldr r0, [r4, #0x1c]
 *   @0x2b9fdc add r1, r2, r5
 *   @0x2b9fe0 rsb r12, r1, r0
 *   @0x2b9fe4 cmp r12, r11
 *   @0x2b9fe8 movge r12, r11
 *   @0x2b9fec ldr r11, [r4, #0x4]
 *   @0x2b9ff0 rsb r1, r1, r11
 *   @0x2b9ff4 cmp r12, r1
 *   @0x2b9ff8 movge r12, r1
 *   @0x2b9ffc cmp r12, #0
 *   @0x2ba000 ble 0x2ba090 <jpeg_std_error+0x10d0>
 *   @0x2ba004 mul r12, r12, r10
 *   @0x2ba008 ldr r2, [r4]
 *   @0x2ba00c ldr r11, [r4, #0x2c]
 *   @0x2ba010 mov r3, r7
 *   @0x2ba014 mov r1, r9
 *   @0x2ba018 mov r0, r6
 *   @0x2ba01c ldr r2, [r2, r5, lsl #2]
 *   @0x2ba020 add r7, r7, r12
 *   @0x2ba024 str r12, [sp]
 *   @0x2ba028 blx r11
 *   @0x2ba02c ldr r1, [r4, #0x14]
 *   @0x2ba030 ldr r3, [r4, #0x10]
 *   @0x2ba034 add r5, r1, r5
 *   @0x2ba038 cmp r3, r5
 *   @0x2ba03c rsb r11, r5, r3
 *   @0x2ba040 bgt 0x2b9fcc <jpeg_std_error+0x100c>
 *   @0x2ba044 ldr r7, [r4, #0x8]
 *   @0x2ba048 mov r1, r3
 *   @0x2ba04c ldr r9, [sp, #0x14]
 *   @0x2ba050 ldr r2, [r4, #0x18]
 *   @0x2ba054 ldr r0, [r4, #0x1c]
 *   @0x2ba058 mov r10, r7
 *   @0x2ba05c mov r3, #0
 *   @0x2ba060 strb r3, [r4, #0x21]
 *   @0x2ba064 b 0x2b9d88 <jpeg_std_error+0xdc8>
 *   @0x2ba068 ldr r3, [r6]
 *   @0x2ba06c mov r2, #69
 *   @0x2ba070 mov r0, r6
 *   @0x2ba074 str r2, [r3, #0x14]
 *   @0x2ba078 ldr r3, [r3]
 *   @0x2ba07c blx r3
 *   @0x2ba080 ldr r2, [r4, #0x18]
 *   @0x2ba084 b 0x2b9d6c <jpeg_std_error+0xdac>
 *   @0x2ba088 ldr r0, [r4, #0x18]
 *   @0x2ba08c b 0x2b9f28 <jpeg_std_error+0xf68>
 *   @0x2ba090 ldr r7, [r4, #0x8]
 *   @0x2ba094 mov r1, r3
 *   @0x2ba098 ldr r9, [sp, #0x14]
 *   @0x2ba09c mov r10, r7
 *   @0x2ba0a0 b 0x2ba05c <jpeg_std_error+0x109c>
 *   @0x2ba0a4 mov r7, r10
 *   @0x2ba0a8 b 0x2ba05c <jpeg_std_error+0x109c>
 *   @0x2ba0ac mov r0, r3
 *
 * ══ §5/13 CLayer::Serialize(IBuffer*)  0x1a9428  size 3584  896 条（0x1a9428..0x1aa228）
 * @func 0x1a9428 0x1aa228  size 3584  896 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::Write(char const*)×2 / CLayer::Serialize(IBuffer*)+0x830 / CLayer::Serialize(IBuffer*)+0x818
 * 字段偏移 top8: 0x8×63 / 0x38×61 / 0x30×60 / 0xc×18 / 0x14×13 / 0x4×11 / 0x28×6 / 0x1c×5
 * VFP 指令 235 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a9428 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a942c add r8, r1, #44
 *   @0x1a9430 ldr r6, [r0]
 *   @0x1a9434 sub sp, sp, #28
 *   @0x1a9438 ldr r3, [r1]
 *   @0x1a943c mov r4, r1
 *   @0x1a9440 mov r5, #0
 *   @0x1a9444 mov r2, r8
 *   @0x1a9448 vmov s13, r6
 *   @0x1a944c str r5, [r1, #0x38]
 *   @0x1a9450 str r0, [sp, #0xc]
 *   @0x1a9454 mov r0, r1
 *   @0x1a9458 vcvt.f64.s32 d6, s13
 *   @0x1a945c mov r1, #6
 *   @0x1a9460 vmov r6, r7, d6
 *   @0x1a9464 vstr s12, [r4, #44]
 *   @0x1a9468 str r7, [r4, #0x30]
 *   @0x1a946c ldr r3, [r3, #0x8]
 *   @0x1a9470 blx r3
 *   @0x1a9474 ldr r3, [sp, #0xc]
 *   @0x1a9478 mov r0, r4
 *   @0x1a947c ldr r1, [r3, #0x1c]
 *   @0x1a9480 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc>
 *   @0x1a9484 ldr r3, [sp, #0xc]
 *   @0x1a9488 mov r2, r8
 *   @0x1a948c mov r1, #6
 *   @0x1a9490 mov r0, r4
 *   @0x1a9494 ldr r6, [r3, #0x4]
 *   @0x1a9498 ldr r3, [r4]
 *   @0x1a949c str r5, [r4, #0x38]
 *   @0x1a94a0 vmov s13, r6
 *   @0x1a94a4 vcvt.f64.s32 d6, s13
 *   @0x1a94a8 vmov r6, r7, d6
 *   @0x1a94ac vstr s12, [r4, #44]
 *   @0x1a94b0 str r7, [r4, #0x30]
 *   @0x1a94b4 ldr r3, [r3, #0x8]
 *   @0x1a94b8 blx r3
 *   @0x1a94bc ldr r3, [sp, #0xc]
 *   @0x1a94c0 vldr s15, [r3, #8]
 *   @0x1a94c4 vcvt.f64.f32 d6, s15
 *   @0x1a94c8 ldr r3, [r4]
 *   @0x1a94cc mov r2, r8
 *   @0x1a94d0 mov r1, #8
 *   @0x1a94d4 str r5, [r4, #0x38]
 *   @0x1a94d8 mov r0, r4
 *   @0x1a94dc vmov r6, r7, d6
 *   @0x1a94e0 vstr s12, [r4, #44]
 *   @0x1a94e4 str r7, [r4, #0x30]
 *   @0x1a94e8 ldr r3, [r3, #0x8]
 *   @0x1a94ec blx r3
 *   @0x1a94f0 ldr r3, [sp, #0xc]
 *   @0x1a94f4 vldr s15, [r3, #12]
 *   @0x1a94f8 vcvt.f64.f32 d6, s15
 *   @0x1a94fc ldr r3, [r4]
 *   @0x1a9500 mov r2, r8
 *   @0x1a9504 mov r1, #8
 *   @0x1a9508 str r5, [r4, #0x38]
 *   @0x1a950c mov r0, r4
 *   @0x1a9510 vmov r6, r7, d6
 *   @0x1a9514 vstr s12, [r4, #44]
 *   @0x1a9518 str r7, [r4, #0x30]
 *   @0x1a951c ldr r3, [r3, #0x8]
 *   @0x1a9520 blx r3
 *   @0x1a9524 ldr r3, [sp, #0xc]
 *   @0x1a9528 vldr s15, [r3, #16]
 *   @0x1a952c vcvt.f64.f32 d6, s15
 *   @0x1a9530 ldr r3, [r4]
 *   @0x1a9534 mov r2, r8
 *   @0x1a9538 mov r1, #8
 *   @0x1a953c str r5, [r4, #0x38]
 *   @0x1a9540 mov r0, r4
 *   @0x1a9544 vmov r6, r7, d6
 *   @0x1a9548 vstr s12, [r4, #44]
 *   @0x1a954c str r7, [r4, #0x30]
 *   @0x1a9550 ldr r3, [r3, #0x8]
 *   @0x1a9554 blx r3
 *   @0x1a9558 ldr r3, [sp, #0xc]
 *   @0x1a955c vldr s15, [r3, #20]
 *   @0x1a9560 vcvt.f64.f32 d6, s15
 *   @0x1a9564 ldr r3, [r4]
 *   @0x1a9568 mov r2, r8
 *   @0x1a956c mov r1, #8
 *   @0x1a9570 str r5, [r4, #0x38]
 *   @0x1a9574 mov r0, r4
 *   @0x1a9578 vmov r6, r7, d6
 *   @0x1a957c vstr s12, [r4, #44]
 *   @0x1a9580 str r7, [r4, #0x30]
 *   @0x1a9584 ldr r3, [r3, #0x8]
 *   @0x1a9588 blx r3
 *   @0x1a958c ldr r3, [sp, #0xc]
 *   @0x1a9590 mov r2, r8
 *   @0x1a9594 mov r1, #6
 *   @0x1a9598 mov r0, r4
 *   @0x1a959c ldrb r6, [r3, #0x18]
 *   @0x1a95a0 ldr r3, [r4]
 *   @0x1a95a4 str r5, [r4, #0x38]
 *   @0x1a95a8 vmov s13, r6
 *   @0x1a95ac vcvt.f64.u32 d6, s13
 *   @0x1a95b0 vmov r6, r7, d6
 *   @0x1a95b4 vstr s12, [r4, #44]
 *   @0x1a95b8 str r7, [r4, #0x30]
 *   @0x1a95bc ldr r3, [r3, #0x8]
 *   @0x1a95c0 blx r3
 *   @0x1a95c4 ldr r3, [sp, #0xc]
 *   @0x1a95c8 mov r2, r8
 *   @0x1a95cc mov r1, #6
 *   @0x1a95d0 mov r0, r4
 *   @0x1a95d4 ldrb r6, [r3, #0x19]
 *   @0x1a95d8 ldr r3, [r4]
 *   @0x1a95dc str r5, [r4, #0x38]
 *   @0x1a95e0 vmov s13, r6
 *   @0x1a95e4 vcvt.f64.u32 d6, s13
 *   @0x1a95e8 vmov r6, r7, d6
 *   @0x1a95ec vstr s12, [r4, #44]
 *   @0x1a95f0 str r7, [r4, #0x30]
 *   @0x1a95f4 ldr r3, [r3, #0x8]
 *   @0x1a95f8 blx r3
 *   @0x1a95fc ldr r3, [sp, #0xc]
 *   @0x1a9600 mov r2, r8
 *   @0x1a9604 mov r1, #6
 *   @0x1a9608 mov r0, r4
 *   @0x1a960c ldr r6, [r3, #0x20]
 *   @0x1a9610 ldr r3, [r4]
 *   @0x1a9614 str r5, [r4, #0x38]
 *   @0x1a9618 vmov s13, r6
 *   @0x1a961c vcvt.f64.s32 d6, s13
 *   @0x1a9620 vmov r6, r7, d6
 *   @0x1a9624 vstr s12, [r4, #44]
 *   @0x1a9628 str r7, [r4, #0x30]
 *   @0x1a962c ldr r3, [r3, #0x8]
 *   @0x1a9630 blx r3
 *   @0x1a9634 ldr r3, [sp, #0xc]
 *   @0x1a9638 mov r2, r8
 *   @0x1a963c mov r1, #6
 *   @0x1a9640 mov r0, r4
 *   @0x1a9644 ldr r6, [r3, #0x24]
 *   @0x1a9648 ldr r3, [r4]
 *   @0x1a964c str r5, [r4, #0x38]
 *   @0x1a9650 vmov s13, r6
 *   @0x1a9654 vcvt.f64.s32 d6, s13
 *   @0x1a9658 vmov r6, r7, d6
 *   @0x1a965c vstr s12, [r4, #44]
 *   @0x1a9660 str r7, [r4, #0x30]
 *   @0x1a9664 ldr r3, [r3, #0x8]
 *   @0x1a9668 blx r3
 *   @0x1a966c ldr r3, [sp, #0xc]
 *   @0x1a9670 mov r1, #6
 *   @0x1a9674 mov r2, r8
 *   @0x1a9678 mov r0, r4
 *   @0x1a967c ldr r6, [r3, #0x28]
 *   @0x1a9680 ldr r3, [r4]
 *   @0x1a9684 str r5, [r4, #0x38]
 *   @0x1a9688 vmov s13, r6
 *   @0x1a968c vcvt.f64.s32 d6, s13
 *   @0x1a9690 vmov r6, r7, d6
 *   @0x1a9694 vstr s12, [r4, #44]
 *   @0x1a9698 str r7, [r4, #0x30]
 *   @0x1a969c ldr r3, [r3, #0x8]
 *   @0x1a96a0 blx r3
 *   @0x1a96a4 ldr r1, [sp, #0xc]
 *   @0x1a96a8 ldr r3, [r1, #0x58]
 *   @0x1a96ac cmp r3, r5
 *   @0x1a96b0 beq 0x1aa20c <_ZN6CLayer9SerializeEP7IBuffer+0xde4>
 *   @0x1a96b4 mov r7, r5
 *   @0x1a96b8 mov r2, r5
 *   @0x1a96bc mov r0, r5
 *   @0x1a96c0 mov r12, r5
 *   @0x1a96c4 str r5, [sp, #0x10]
 *   @0x1a96c8 str r5, [sp, #0x14]
 *   @0x1a96cc ldr r1, [r3]
 *   @0x1a96d0 sub r1, r1, #1
 *   @0x1a96d4 cmp r1, #6
 *   @0x1a96d8 addls pc, pc, r1, lsl #2
 *   @0x1a96dc b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8>
 *   @0x1a96e0 b 0x1aa1fc <_ZN6CLayer9SerializeEP7IBuffer+0xdd4>
 *   @0x1a96e4 b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8>
 *   @0x1a96e8 b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8>
 *   @0x1a96ec b 0x1aa204 <_ZN6CLayer9SerializeEP7IBuffer+0xddc>
 *   @0x1a96f0 b 0x1aa1f4 <_ZN6CLayer9SerializeEP7IBuffer+0xdcc>
 *   @0x1a96f4 b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8>
 *   @0x1a96f8 b 0x1a96fc <_ZN6CLayer9SerializeEP7IBuffer+0x2d4>
 *   @0x1a96fc add r12, r12, #1
 *   @0x1a9700 ldr r3, [r3, #0x14]
 *   @0x1a9704 cmp r3, #0
 *   @0x1a9708 bne 0x1a96cc <_ZN6CLayer9SerializeEP7IBuffer+0x2a4>
 *   @0x1a970c vmov s13, r2
 *   @0x1a9710 str r0, [sp, #0x14]
 *   @0x1a9714 str r12, [sp, #0x10]
 *   @0x1a9718 vcvt.f64.s32 d6, s13
 *   @0x1a971c vmov r2, r3, d6
 *   @0x1a9720 ldr r1, [r4]
 *   @0x1a9724 mov r6, #0
 *   @0x1a9728 str r2, [r4, #0x2c]
 *   @0x1a972c mov r0, r4
 *   @0x1a9730 str r3, [r4, #0x30]
 *   @0x1a9734 mov r2, r8
 *   @0x1a9738 ldr r3, [r1, #0x8]
 *   @0x1a973c mov r1, #6
 *   @0x1a9740 str r6, [r4, #0x38]
 *   @0x1a9744 blx r3
 *   @0x1a9748 ldr r3, [sp, #0xc]
 *   @0x1a974c ldr r9, [r3, #0x58]
 *   @0x1a9750 cmp r9, r6
 *   @0x1a9754 bne 0x1a9768 <_ZN6CLayer9SerializeEP7IBuffer+0x340>
 *   @0x1a9758 b 0x1a9a14 <_ZN6CLayer9SerializeEP7IBuffer+0x5ec>
 *   @0x1a975c ldr r9, [r9, #0x14]
 *   @0x1a9760 cmp r9, #0
 *   @0x1a9764 beq 0x1a9a14 <_ZN6CLayer9SerializeEP7IBuffer+0x5ec>
 *   @0x1a9768 ldr r3, [r9]
 *   @0x1a976c cmp r3, #1
 *   @0x1a9770 bne 0x1a975c <_ZN6CLayer9SerializeEP7IBuffer+0x334>
 *   @0x1a9774 ldr r5, [r9, #0x1c]
 *   @0x1a9778 mov r1, #6
 *   @0x1a977c ldr r3, [r4]
 *   @0x1a9780 mov r2, r8
 *   @0x1a9784 mov r0, r4
 *   @0x1a9788 ldrb r10, [r5]
 *   @0x1a978c str r6, [r4, #0x38]
 *   @0x1a9790 vmov s13, r10
 *   @0x1a9794 vcvt.f64.u32 d6, s13
 *   @0x1a9798 vmov r10, r11, d6
 *   @0x1a979c vstr s12, [r4, #44]
 *   @0x1a97a0 str r11, [r4, #0x30]
 *   @0x1a97a4 ldr r3, [r3, #0x8]
 *   @0x1a97a8 blx r3
 *   @0x1a97ac ldrb r10, [r5, #0x1]
 *   @0x1a97b0 ldr r3, [r4]
 *   @0x1a97b4 mov r1, #6
 *   @0x1a97b8 mov r2, r8
 *   @0x1a97bc mov r0, r4
 *   @0x1a97c0 vmov s15, r10
 *   @0x1a97c4 str r6, [r4, #0x38]
 *   @0x1a97c8 vcvt.f64.u32 d7, s15
 *   @0x1a97cc vmov r10, r11, d7
 *   @0x1a97d0 vstr s14, [r4, #44]
 *   @0x1a97d4 str r11, [r4, #0x30]
 *   @0x1a97d8 ldr r3, [r3, #0x8]
 *   @0x1a97dc blx r3
 *   @0x1a97e0 ldr r10, [r5, #0x4]
 *   @0x1a97e4 ldr r3, [r4]
 *   @0x1a97e8 mov r1, #6
 *   @0x1a97ec mov r2, r8
 *   @0x1a97f0 mov r0, r4
 *   @0x1a97f4 vmov s13, r10
 *   @0x1a97f8 str r6, [r4, #0x38]
 *   @0x1a97fc vcvt.f64.s32 d6, s13
 *   @0x1a9800 vmov r10, r11, d6
 *   @0x1a9804 vstr s12, [r4, #44]
 *   @0x1a9808 str r11, [r4, #0x30]
 *   @0x1a980c ldr r3, [r3, #0x8]
 *   @0x1a9810 blx r3
 *   @0x1a9814 ldrb r10, [r5, #0x8]
 *   @0x1a9818 ldr r3, [r4]
 *   @0x1a981c mov r1, #6
 *   @0x1a9820 mov r2, r8
 *   @0x1a9824 mov r0, r4
 *   @0x1a9828 vmov s15, r10
 *   @0x1a982c str r6, [r4, #0x38]
 *   @0x1a9830 vcvt.f64.u32 d7, s15
 *   @0x1a9834 vmov r10, r11, d7
 *   @0x1a9838 vstr s14, [r4, #44]
 *   @0x1a983c str r11, [r4, #0x30]
 *   @0x1a9840 ldr r3, [r3, #0x8]
 *   @0x1a9844 blx r3
 *   @0x1a9848 ldrb r10, [r5, #0x9]
 *   @0x1a984c ldr r3, [r4]
 *   @0x1a9850 mov r1, #6
 *   @0x1a9854 mov r2, r8
 *   @0x1a9858 mov r0, r4
 *   @0x1a985c vmov s13, r10
 *   @0x1a9860 str r6, [r4, #0x38]
 *   @0x1a9864 vcvt.f64.u32 d6, s13
 *   @0x1a9868 vmov r10, r11, d6
 *   @0x1a986c vstr s12, [r4, #44]
 *   @0x1a9870 str r11, [r4, #0x30]
 *   @0x1a9874 ldr r3, [r3, #0x8]
 *   @0x1a9878 blx r3
 *   @0x1a987c vldr s14, [r5, #12]
 *   @0x1a9880 vcvt.f64.f32 d6, s14
 *   @0x1a9884 ldr r3, [r4]
 *   @0x1a9888 mov r1, #8
 *   @0x1a988c mov r2, r8
 *   @0x1a9890 str r6, [r4, #0x38]
 *   @0x1a9894 mov r0, r4
 *   @0x1a9898 vmov r10, r11, d6
 *   @0x1a989c vstr s12, [r4, #44]
 *   @0x1a98a0 str r11, [r4, #0x30]
 *   @0x1a98a4 ldr r3, [r3, #0x8]
 *   @0x1a98a8 blx r3
 *   @0x1a98ac vldr s14, [r5, #16]
 *   @0x1a98b0 vcvt.f64.f32 d6, s14
 *   @0x1a98b4 ldr r3, [r4]
 *   @0x1a98b8 mov r1, #8
 *   @0x1a98bc mov r2, r8
 *   @0x1a98c0 str r6, [r4, #0x38]
 *   @0x1a98c4 mov r0, r4
 *   @0x1a98c8 vmov r10, r11, d6
 *   @0x1a98cc vstr s12, [r4, #44]
 *   @0x1a98d0 str r11, [r4, #0x30]
 *   @0x1a98d4 ldr r3, [r3, #0x8]
 *   @0x1a98d8 blx r3
 *   @0x1a98dc ldrb r10, [r5, #0x14]
 *   @0x1a98e0 ldr r3, [r4]
 *   @0x1a98e4 mov r1, #6
 *   @0x1a98e8 mov r2, r8
 *   @0x1a98ec mov r0, r4
 *   @0x1a98f0 vmov s15, r10
 *   @0x1a98f4 str r6, [r4, #0x38]
 *   @0x1a98f8 vcvt.f64.u32 d7, s15
 *   @0x1a98fc vmov r10, r11, d7
 *   @0x1a9900 vstr s14, [r4, #44]
 *   @0x1a9904 str r11, [r4, #0x30]
 *   @0x1a9908 ldr r3, [r3, #0x8]
 *   @0x1a990c blx r3
 *   @0x1a9910 ldr r10, [r5, #0x18]
 *   @0x1a9914 ldr r3, [r4]
 *   @0x1a9918 mov r1, #6
 *   @0x1a991c mov r2, r8
 *   @0x1a9920 mov r0, r4
 *   @0x1a9924 vmov s13, r10
 *   @0x1a9928 str r6, [r4, #0x38]
 *   @0x1a992c vcvt.f64.s32 d6, s13
 *   @0x1a9930 vmov r10, r11, d6
 *   @0x1a9934 vstr s12, [r4, #44]
 *   @0x1a9938 str r11, [r4, #0x30]
 *   @0x1a993c ldr r3, [r3, #0x8]
 *   @0x1a9940 blx r3
 *   @0x1a9944 vldr s14, [r5, #28]
 *   @0x1a9948 vcvt.f64.f32 d6, s14
 *   @0x1a994c ldr r3, [r4]
 *   @0x1a9950 mov r1, #8
 *   @0x1a9954 mov r2, r8
 *   @0x1a9958 str r6, [r4, #0x38]
 *   @0x1a995c mov r0, r4
 *   @0x1a9960 vmov r10, r11, d6
 *   @0x1a9964 vstr s12, [r4, #44]
 *   @0x1a9968 str r11, [r4, #0x30]
 *   @0x1a996c ldr r3, [r3, #0x8]
 *   @0x1a9970 blx r3
 *   @0x1a9974 vldr s14, [r5, #32]
 *   @0x1a9978 vcvt.f64.f32 d6, s14
 *   @0x1a997c ldr r3, [r4]
 *   @0x1a9980 mov r1, #8
 *   @0x1a9984 mov r2, r8
 *   @0x1a9988 str r6, [r4, #0x38]
 *   @0x1a998c mov r0, r4
 *   @0x1a9990 vmov r10, r11, d6
 *   @0x1a9994 vstr s12, [r4, #44]
 *   @0x1a9998 str r11, [r4, #0x30]
 *   @0x1a999c ldr r3, [r3, #0x8]
 *   @0x1a99a0 blx r3
 *   @0x1a99a4 vldr s14, [r5, #36]
 *   @0x1a99a8 vcvt.f64.f32 d6, s14
 *   @0x1a99ac ldr r3, [r4]
 *   @0x1a99b0 mov r1, #8
 *   @0x1a99b4 mov r2, r8
 *   @0x1a99b8 str r6, [r4, #0x38]
 *   @0x1a99bc mov r0, r4
 *   @0x1a99c0 vmov r10, r11, d6
 *   @0x1a99c4 vstr s12, [r4, #44]
 *   @0x1a99c8 str r11, [r4, #0x30]
 *   @0x1a99cc ldr r3, [r3, #0x8]
 *   @0x1a99d0 blx r3
 *   @0x1a99d4 ldr r10, [r5, #0x28]
 *   @0x1a99d8 ldr r3, [r4]
 *   @0x1a99dc mov r0, r4
 *   @0x1a99e0 str r6, [r4, #0x38]
 *   @0x1a99e4 mov r1, #6
 *   @0x1a99e8 vmov s15, r10
 *   @0x1a99ec mov r2, r8
 *   @0x1a99f0 vcvt.f64.s32 d7, s15
 *   @0x1a99f4 vmov r10, r11, d7
 *   @0x1a99f8 vstr s14, [r4, #44]
 *   @0x1a99fc str r11, [r4, #0x30]
 *   @0x1a9a00 ldr r3, [r3, #0x8]
 *   @0x1a9a04 blx r3
 *   @0x1a9a08 ldr r9, [r9, #0x14]
 *   @0x1a9a0c cmp r9, #0
 *   @0x1a9a10 bne 0x1a9768 <_ZN6CLayer9SerializeEP7IBuffer+0x340>
 *   @0x1a9a14 vmov s13, r7
 *   @0x1a9a18 ldr r3, [r4]
 *   @0x1a9a1c mov r9, #0
 *   @0x1a9a20 mov r0, r4
 *   @0x1a9a24 vcvt.f64.s32 d6, s13
 *   @0x1a9a28 str r9, [r4, #0x38]
 *   @0x1a9a2c mov r1, #6
 *   @0x1a9a30 mov r2, r8
 *   @0x1a9a34 vmov r6, r7, d6
 *   @0x1a9a38 vstr s12, [r4, #44]
 *   @0x1a9a3c str r7, [r4, #0x30]
 *   @0x1a9a40 ldr r3, [r3, #0x8]
 *   @0x1a9a44 blx r3
 *   @0x1a9a48 ldr r3, [sp, #0xc]
 *   @0x1a9a4c ldr r7, [r3, #0x58]
 *   @0x1a9a50 cmp r7, r9
 *   @0x1a9a54 strne r8, [sp, #0x4]
 *   @0x1a9a58 movne r5, r7
 *   @0x1a9a5c bne 0x1a9a70 <_ZN6CLayer9SerializeEP7IBuffer+0x648>
 *   @0x1a9a60 b 0x1a9c9c <_ZN6CLayer9SerializeEP7IBuffer+0x874>
 *   @0x1a9a64 ldr r5, [r5, #0x14]
 *   @0x1a9a68 cmp r5, #0
 *   @0x1a9a6c beq 0x1a9c98 <_ZN6CLayer9SerializeEP7IBuffer+0x870>
 *   @0x1a9a70 ldr r3, [r5]
 *   @0x1a9a74 cmp r3, #5
 *   @0x1a9a78 bne 0x1a9a64 <_ZN6CLayer9SerializeEP7IBuffer+0x63c>
 *   @0x1a9a7c ldr r6, [r5, #0x1c]
 *   @0x1a9a80 mov r1, #6
 *   @0x1a9a84 ldr r3, [r4]
 *   @0x1a9a88 mov r0, r4
 *   @0x1a9a8c ldr r2, [sp, #0x4]
 *   @0x1a9a90 vmov s13, r6
 *   @0x1a9a94 str r9, [r4, #0x38]
 *   @0x1a9a98 vcvt.f64.s32 d6, s13
 *   @0x1a9a9c vmov r6, r7, d6
 *   @0x1a9aa0 vstr s12, [r4, #44]
 *   @0x1a9aa4 str r7, [r4, #0x30]
 *   @0x1a9aa8 ldr r3, [r3, #0x8]
 *   @0x1a9aac blx r3
 *   @0x1a9ab0 ldr r1, [r5, #0xc]
 *   @0x1a9ab4 mov r0, r4
 *   @0x1a9ab8 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc>
 *   @0x1a9abc vldr s14, [r5, #32]
 *   @0x1a9ac0 vcvt.f64.f32 d6, s14
 *   @0x1a9ac4 ldr r3, [r4]
 *   @0x1a9ac8 mov r1, #8
 *   @0x1a9acc ldr r2, [sp, #0x4]
 *   @0x1a9ad0 str r9, [r4, #0x38]
 *   @0x1a9ad4 mov r0, r4
 *   @0x1a9ad8 vmov r6, r7, d6
 *   @0x1a9adc vstr s12, [r4, #44]
 *   @0x1a9ae0 str r7, [r4, #0x30]
 *   @0x1a9ae4 ldr r3, [r3, #0x8]
 *   @0x1a9ae8 blx r3
 *   @0x1a9aec vldr s14, [r5, #36]
 *   @0x1a9af0 vcvt.f64.f32 d6, s14
 *   @0x1a9af4 ldr r3, [r4]
 *   @0x1a9af8 mov r1, #8
 *   @0x1a9afc ldr r2, [sp, #0x4]
 *   @0x1a9b00 str r9, [r4, #0x38]
 *   @0x1a9b04 mov r0, r4
 *   @0x1a9b08 vmov r6, r7, d6
 *   @0x1a9b0c vstr s12, [r4, #44]
 *   @0x1a9b10 str r7, [r4, #0x30]
 *   @0x1a9b14 ldr r3, [r3, #0x8]
 *   @0x1a9b18 blx r3
 *   @0x1a9b1c ldr r6, [r5, #0x28]
 *   @0x1a9b20 ldr r3, [r4]
 *   @0x1a9b24 mov r1, #6
 *   @0x1a9b28 ldr r2, [sp, #0x4]
 *   @0x1a9b2c mov r0, r4
 *   @0x1a9b30 vmov s15, r6
 *   @0x1a9b34 str r9, [r4, #0x38]
 *   @0x1a9b38 vcvt.f64.s32 d7, s15
 *   @0x1a9b3c vmov r6, r7, d7
 *   @0x1a9b40 vstr s14, [r4, #44]
 *   @0x1a9b44 str r7, [r4, #0x30]
 *   @0x1a9b48 ldr r3, [r3, #0x8]
 *   @0x1a9b4c blx r3
 *   @0x1a9b50 ldr r6, [r5, #0x2c]
 *   @0x1a9b54 ldr r3, [r4]
 *   @0x1a9b58 mov r1, #6
 *   @0x1a9b5c ldr r2, [sp, #0x4]
 *   @0x1a9b60 mov r0, r4
 *   @0x1a9b64 vmov s13, r6
 *   @0x1a9b68 str r9, [r4, #0x38]
 *   @0x1a9b6c vcvt.f64.s32 d6, s13
 *   @0x1a9b70 vmov r6, r7, d6
 *   @0x1a9b74 vstr s12, [r4, #44]
 *   @0x1a9b78 str r7, [r4, #0x30]
 *   @0x1a9b7c ldr r3, [r3, #0x8]
 *   @0x1a9b80 blx r3
 *   @0x1a9b84 vldr s14, [r5, #48]
 *   @0x1a9b88 vcvt.f64.f32 d6, s14
 *   @0x1a9b8c ldr r3, [r4]
 *   @0x1a9b90 str r9, [r4, #0x38]
 *   @0x1a9b94 mov r0, r4
 *   @0x1a9b98 mov r1, #8
 *   @0x1a9b9c ldr r2, [sp, #0x4]
 *   @0x1a9ba0 vmov r6, r7, d6
 *   @0x1a9ba4 vstr s12, [r4, #44]
 *   @0x1a9ba8 str r7, [r4, #0x30]
 *   @0x1a9bac ldr r3, [r3, #0x8]
 *   @0x1a9bb0 blx r3
 *   @0x1a9bb4 ldr r3, [r5, #0x28]
 *   @0x1a9bb8 cmp r3, #0
 *   @0x1a9bbc ble 0x1a9c58 <_ZN6CLayer9SerializeEP7IBuffer+0x830>
 *   @0x1a9bc0 mov r1, #0
 *   @0x1a9bc4 mov r0, r5
 *   @0x1a9bc8 str r1, [sp, #0x8]
 *   @0x1a9bcc mov r11, r0
 *   @0x1a9bd0 ldr r2, [r5, #0x2c]
 *   @0x1a9bd4 mov r5, r1
 *   @0x1a9bd8 mov r1, r3
 *   @0x1a9bdc cmp r2, #0
 *   @0x1a9be0 ble 0x1a9c40 <_ZN6CLayer9SerializeEP7IBuffer+0x818>
 *   @0x1a9be4 lsl r10, r5, #2
 *   @0x1a9be8 mov r8, #0
 *   @0x1a9bec ldr r2, [r11, #0x34]
 *   @0x1a9bf0 mov r0, r4
 *   @0x1a9bf4 ldr r12, [r4]
 *   @0x1a9bf8 mov r1, #5
 *   @0x1a9bfc add r8, r8, #1
 *   @0x1a9c00 add r5, r5, #1
 *   @0x1a9c04 ldr r6, [r2, r10]
 *   @0x1a9c08 add r10, r10, #4
 *   @0x1a9c0c ldr r2, [sp, #0x4]
 *   @0x1a9c10 str r9, [r4, #0x38]
 *   @0x1a9c14 vmov s13, r6
 *   @0x1a9c18 vcvt.f64.u32 d6, s13
 *   @0x1a9c1c vmov r6, r7, d6
 *   @0x1a9c20 vstr s12, [r4, #44]
 *   @0x1a9c24 str r7, [r4, #0x30]
 *   @0x1a9c28 ldr r12, [r12, #0x8]
 *   @0x1a9c2c blx r12
 *   @0x1a9c30 ldr r2, [r11, #0x2c]
 *   @0x1a9c34 cmp r2, r8
 *   @0x1a9c38 bgt 0x1a9bec <_ZN6CLayer9SerializeEP7IBuffer+0x7c4>
 *   @0x1a9c3c ldr r1, [r11, #0x28]
 *   @0x1a9c40 ldr r3, [sp, #0x8]
 *   @0x1a9c44 add r3, r3, #1
 *   @0x1a9c48 str r3, [sp, #0x8]
 *   @0x1a9c4c cmp r1, r3
 *   @0x1a9c50 bgt 0x1a9bdc <_ZN6CLayer9SerializeEP7IBuffer+0x7b4>
 *   @0x1a9c54 mov r5, r11
 *   @0x1a9c58 ldr r6, [r5, #0x38]
 *   @0x1a9c5c mov r0, r4
 *   @0x1a9c60 ldr r3, [r4]
 *   @0x1a9c64 mov r1, #5
 *   @0x1a9c68 str r9, [r4, #0x38]
 *   @0x1a9c6c vmov s13, r6
 *   @0x1a9c70 ldr r2, [sp, #0x4]
 *   @0x1a9c74 vcvt.f64.u32 d6, s13
 *   @0x1a9c78 vmov r6, r7, d6
 *   @0x1a9c7c vstr s12, [r4, #44]
 *   @0x1a9c80 str r7, [r4, #0x30]
 *   @0x1a9c84 ldr r3, [r3, #0x8]
 *   @0x1a9c88 blx r3
 *   @0x1a9c8c ldr r5, [r5, #0x14]
 *   @0x1a9c90 cmp r5, #0
 *   @0x1a9c94 bne 0x1a9a70 <_ZN6CLayer9SerializeEP7IBuffer+0x648>
 *   @0x1a9c98 ldr r8, [sp, #0x4]
 *   @0x1a9c9c vldr s13, [sp, #20]
 *   @0x1a9ca0 vcvt.f64.s32 d6, s13
 *   @0x1a9ca4 ldr r3, [r4]
 *   @0x1a9ca8 mov r5, #0
 *   @0x1a9cac mov r0, r4
 *   @0x1a9cb0 str r5, [r4, #0x38]
 *   @0x1a9cb4 mov r1, #6
 *   @0x1a9cb8 mov r2, r8
 *   @0x1a9cbc vmov r6, r7, d6
 *   @0x1a9cc0 vstr s12, [r4, #44]
 *   @0x1a9cc4 str r7, [r4, #0x30]
 *   @0x1a9cc8 ldr r3, [r3, #0x8]
 *   @0x1a9ccc blx r3
 *   @0x1a9cd0 ldr r3, [sp, #0xc]
 *   @0x1a9cd4 ldr r9, [r3, #0x58]
 *   @0x1a9cd8 cmp r9, r5
 *   @0x1a9cdc bne 0x1a9cf0 <_ZN6CLayer9SerializeEP7IBuffer+0x8c8>
 *   @0x1a9ce0 b 0x1a9ef4 <_ZN6CLayer9SerializeEP7IBuffer+0xacc>
 *   @0x1a9ce4 ldr r9, [r9, #0x14]
 *   @0x1a9ce8 cmp r9, #0
 *   @0x1a9cec beq 0x1a9ef4 <_ZN6CLayer9SerializeEP7IBuffer+0xacc>
 *   @0x1a9cf0 ldr r3, [r9]
 *   @0x1a9cf4 cmp r3, #4
 *   @0x1a9cf8 bne 0x1a9ce4 <_ZN6CLayer9SerializeEP7IBuffer+0x8bc>
 *   @0x1a9cfc ldr r6, [r9, #0x1c]
 *   @0x1a9d00 mov r1, #6
 *   @0x1a9d04 ldr r3, [r4]
 *   @0x1a9d08 mov r2, r8
 *   @0x1a9d0c mov r0, r4
 *   @0x1a9d10 str r5, [r4, #0x38]
 *   @0x1a9d14 vmov s13, r6
 *   @0x1a9d18 vcvt.f64.s32 d6, s13
 *   @0x1a9d1c vmov r6, r7, d6
 *   @0x1a9d20 vstr s12, [r4, #44]
 *   @0x1a9d24 str r7, [r4, #0x30]
 *   @0x1a9d28 ldr r3, [r3, #0x8]
 *   @0x1a9d2c blx r3
 *   @0x1a9d30 vldr s15, [r9, #36]
 *   @0x1a9d34 vcvt.f64.f32 d6, s15
 *   @0x1a9d38 ldr r3, [r4]
 *   @0x1a9d3c mov r1, #8
 *   @0x1a9d40 mov r2, r8
 *   @0x1a9d44 str r5, [r4, #0x38]
 *   @0x1a9d48 mov r0, r4
 *   @0x1a9d4c vmov r6, r7, d6
 *   @0x1a9d50 vstr s12, [r4, #44]
 *   @0x1a9d54 str r7, [r4, #0x30]
 *   @0x1a9d58 ldr r3, [r3, #0x8]
 *   @0x1a9d5c blx r3
 *   @0x1a9d60 ldr r6, [r9, #0x28]
 *   @0x1a9d64 ldr r3, [r4]
 *   @0x1a9d68 mov r1, #6
 *   @0x1a9d6c mov r2, r8
 *   @0x1a9d70 mov r0, r4
 *   @0x1a9d74 vmov s15, r6
 *   @0x1a9d78 str r5, [r4, #0x38]
 *   @0x1a9d7c vcvt.f64.s32 d7, s15
 *   @0x1a9d80 vmov r6, r7, d7
 *   @0x1a9d84 vstr s14, [r4, #44]
 *   @0x1a9d88 str r7, [r4, #0x30]
 *   @0x1a9d8c ldr r3, [r3, #0x8]
 *   @0x1a9d90 blx r3
 *   @0x1a9d94 vldr s15, [r9, #44]
 *   @0x1a9d98 vcvt.f64.f32 d6, s15
 *   @0x1a9d9c ldr r3, [r4]
 *   @0x1a9da0 mov r1, #8
 *   @0x1a9da4 mov r2, r8
 *   @0x1a9da8 str r5, [r4, #0x38]
 *   @0x1a9dac mov r0, r4
 *   @0x1a9db0 vmov r6, r7, d6
 *   @0x1a9db4 vstr s12, [r4, #44]
 *   @0x1a9db8 str r7, [r4, #0x30]
 *   @0x1a9dbc ldr r3, [r3, #0x8]
 *   @0x1a9dc0 blx r3
 *   @0x1a9dc4 vldr s15, [r9, #48]
 *   @0x1a9dc8 vcvt.f64.f32 d6, s15
 *   @0x1a9dcc ldr r3, [r4]
 *   @0x1a9dd0 mov r1, #8
 *   @0x1a9dd4 mov r2, r8
 *   @0x1a9dd8 str r5, [r4, #0x38]
 *   @0x1a9ddc mov r0, r4
 *   @0x1a9de0 vmov r6, r7, d6
 *   @0x1a9de4 vstr s12, [r4, #44]
 *   @0x1a9de8 str r7, [r4, #0x30]
 *   @0x1a9dec ldr r3, [r3, #0x8]
 *   @0x1a9df0 blx r3
 *   @0x1a9df4 vldr s15, [r9, #52]
 *   @0x1a9df8 vcvt.f64.f32 d6, s15
 *   @0x1a9dfc ldr r3, [r4]
 *   @0x1a9e00 mov r1, #8
 *   @0x1a9e04 mov r2, r8
 *   @0x1a9e08 str r5, [r4, #0x38]
 *   @0x1a9e0c mov r0, r4
 *   @0x1a9e10 vmov r6, r7, d6
 *   @0x1a9e14 vstr s12, [r4, #44]
 *   @0x1a9e18 str r7, [r4, #0x30]
 *   @0x1a9e1c ldr r3, [r3, #0x8]
 *   @0x1a9e20 blx r3
 *   @0x1a9e24 ldr r6, [r9, #0x38]
 *   @0x1a9e28 ldr r3, [r4]
 *   @0x1a9e2c mov r1, #5
 *   @0x1a9e30 mov r2, r8
 *   @0x1a9e34 mov r0, r4
 *   @0x1a9e38 vmov s15, r6
 *   @0x1a9e3c str r5, [r4, #0x38]
 *   @0x1a9e40 vcvt.f64.u32 d7, s15
 *   @0x1a9e44 vmov r6, r7, d7
 *   @0x1a9e48 vstr s14, [r4, #44]
 *   @0x1a9e4c str r7, [r4, #0x30]
 *   @0x1a9e50 ldr r3, [r3, #0x8]
 *   @0x1a9e54 blx r3
 *   @0x1a9e58 vldr s15, [r9, #60]
 *   @0x1a9e5c vcvt.f64.f32 d6, s15
 *   @0x1a9e60 ldr r3, [r4]
 *   @0x1a9e64 mov r1, #8
 *   @0x1a9e68 mov r2, r8
 *   @0x1a9e6c str r5, [r4, #0x38]
 *   @0x1a9e70 mov r0, r4
 *   @0x1a9e74 vmov r6, r7, d6
 *   @0x1a9e78 vstr s12, [r4, #44]
 *   @0x1a9e7c str r7, [r4, #0x30]
 *   @0x1a9e80 ldr r3, [r3, #0x8]
 *   @0x1a9e84 blx r3
 *   @0x1a9e88 vldr s15, [r9, #64]
 *   @0x1a9e8c vcvt.f64.f32 d6, s15
 *   @0x1a9e90 ldr r3, [r4]
 *   @0x1a9e94 mov r1, #8
 *   @0x1a9e98 mov r2, r8
 *   @0x1a9e9c str r5, [r4, #0x38]
 *   @0x1a9ea0 mov r0, r4
 *   @0x1a9ea4 vmov r6, r7, d6
 *   @0x1a9ea8 vstr s12, [r4, #44]
 *   @0x1a9eac str r7, [r4, #0x30]
 *   @0x1a9eb0 ldr r3, [r3, #0x8]
 *   @0x1a9eb4 blx r3
 *   @0x1a9eb8 vldr s15, [r9, #68]
 *   @0x1a9ebc vcvt.f64.f32 d6, s15
 *   @0x1a9ec0 ldr r3, [r4]
 *   @0x1a9ec4 str r5, [r4, #0x38]
 *   @0x1a9ec8 mov r0, r4
 *   @0x1a9ecc mov r1, #8
 *   @0x1a9ed0 mov r2, r8
 *   @0x1a9ed4 vmov r6, r7, d6
 *   @0x1a9ed8 vstr s12, [r4, #44]
 *   @0x1a9edc str r7, [r4, #0x30]
 *   @0x1a9ee0 ldr r3, [r3, #0x8]
 *   @0x1a9ee4 blx r3
 *   @0x1a9ee8 ldr r9, [r9, #0x14]
 *   @0x1a9eec cmp r9, #0
 *   @0x1a9ef0 bne 0x1a9cf0 <_ZN6CLayer9SerializeEP7IBuffer+0x8c8>
 *   @0x1a9ef4 vldr s15, [sp, #16]
 *   @0x1a9ef8 vcvt.f64.s32 d7, s15
 *   @0x1a9efc ldr r3, [r4]
 *   @0x1a9f00 mov r5, #0
 *   @0x1a9f04 mov r0, r4
 *   @0x1a9f08 str r5, [r4, #0x38]
 *   @0x1a9f0c mov r1, #6
 *   @0x1a9f10 mov r2, r8
 *   @0x1a9f14 vmov r6, r7, d7
 *   @0x1a9f18 vstr s14, [r4, #44]
 *   @0x1a9f1c str r7, [r4, #0x30]
 *   @0x1a9f20 ldr r3, [r3, #0x8]
 *   @0x1a9f24 blx r3
 *   @0x1a9f28 ldr r3, [sp, #0xc]
 *   @0x1a9f2c ldr r9, [r3, #0x58]
 *   @0x1a9f30 cmp r9, r5
 *   @0x1a9f34 bne 0x1a9f48 <_ZN6CLayer9SerializeEP7IBuffer+0xb20>
 *   @0x1a9f38 b 0x1aa1ec <_ZN6CLayer9SerializeEP7IBuffer+0xdc4>
 *   @0x1a9f3c ldr r9, [r9, #0x14]
 *   @0x1a9f40 cmp r9, #0
 *   @0x1a9f44 beq 0x1aa1ec <_ZN6CLayer9SerializeEP7IBuffer+0xdc4>
 *   @0x1a9f48 ldr r3, [r9]
 *   @0x1a9f4c cmp r3, #7
 *   @0x1a9f50 bne 0x1a9f3c <_ZN6CLayer9SerializeEP7IBuffer+0xb14>
 *   @0x1a9f54 ldrb r6, [r9, #0x1c]
 *   @0x1a9f58 mov r1, #6
 *   @0x1a9f5c ldr r3, [r4]
 *   @0x1a9f60 mov r2, r8
 *   @0x1a9f64 mov r0, r4
 *   @0x1a9f68 str r5, [r4, #0x38]
 *   @0x1a9f6c vmov s15, r6
 *   @0x1a9f70 vcvt.f64.u32 d7, s15
 *   @0x1a9f74 vmov r6, r7, d7
 *   @0x1a9f78 vstr s14, [r4, #44]
 *   @0x1a9f7c str r7, [r4, #0x30]
 *   @0x1a9f80 ldr r3, [r3, #0x8]
 *   @0x1a9f84 blx r3
 *   @0x1a9f88 ldr r6, [r9, #0x20]
 *   @0x1a9f8c ldr r3, [r4]
 *   @0x1a9f90 mov r1, #6
 *   @0x1a9f94 mov r2, r8
 *   @0x1a9f98 mov r0, r4
 *   @0x1a9f9c vmov s13, r6
 *   @0x1a9fa0 str r5, [r4, #0x38]
 *   @0x1a9fa4 vcvt.f64.s32 d6, s13
 *   @0x1a9fa8 vmov r6, r7, d6
 *   @0x1a9fac vstr s12, [r4, #44]
 *   @0x1a9fb0 str r7, [r4, #0x30]
 *   @0x1a9fb4 ldr r3, [r3, #0x8]
 *   @0x1a9fb8 blx r3
 *   @0x1a9fbc vldr s15, [r9, #36]
 *   @0x1a9fc0 vcvt.f64.f32 d6, s15
 *   @0x1a9fc4 ldr r3, [r4]
 *   @0x1a9fc8 mov r1, #8
 *   @0x1a9fcc mov r2, r8
 *   @0x1a9fd0 str r5, [r4, #0x38]
 *   @0x1a9fd4 mov r0, r4
 *   @0x1a9fd8 vmov r6, r7, d6
 *   @0x1a9fdc vstr s12, [r4, #44]
 *   @0x1a9fe0 str r7, [r4, #0x30]
 *   @0x1a9fe4 ldr r3, [r3, #0x8]
 *   @0x1a9fe8 blx r3
 *   @0x1a9fec vldr s15, [r9, #40]
 *   @0x1a9ff0 vcvt.f64.f32 d6, s15
 *   @0x1a9ff4 ldr r3, [r4]
 *   @0x1a9ff8 mov r1, #8
 *   @0x1a9ffc mov r2, r8
 *   @0x1aa000 str r5, [r4, #0x38]
 *   @0x1aa004 mov r0, r4
 *   @0x1aa008 vmov r6, r7, d6
 *   @0x1aa00c vstr s12, [r4, #44]
 *   @0x1aa010 str r7, [r4, #0x30]
 *   @0x1aa014 ldr r3, [r3, #0x8]
 *   @0x1aa018 blx r3
 *   @0x1aa01c ldr r6, [r9, #0x2c]
 *   @0x1aa020 ldr r3, [r4]
 *   @0x1aa024 mov r1, #6
 *   @0x1aa028 mov r2, r8
 *   @0x1aa02c mov r0, r4
 *   @0x1aa030 vmov s15, r6
 *   @0x1aa034 str r5, [r4, #0x38]
 *   @0x1aa038 vcvt.f64.s32 d7, s15
 *   @0x1aa03c vmov r6, r7, d7
 *   @0x1aa040 vstr s14, [r4, #44]
 *   @0x1aa044 str r7, [r4, #0x30]
 *   @0x1aa048 ldr r3, [r3, #0x8]
 *   @0x1aa04c blx r3
 *   @0x1aa050 ldr r6, [r9, #0x30]
 *   @0x1aa054 ldr r3, [r4]
 *   @0x1aa058 mov r1, #6
 *   @0x1aa05c mov r2, r8
 *   @0x1aa060 mov r0, r4
 *   @0x1aa064 vmov s13, r6
 *   @0x1aa068 str r5, [r4, #0x38]
 *   @0x1aa06c vcvt.f64.s32 d6, s13
 *   @0x1aa070 vmov r6, r7, d6
 *   @0x1aa074 vstr s12, [r4, #44]
 *   @0x1aa078 str r7, [r4, #0x30]
 *   @0x1aa07c ldr r3, [r3, #0x8]
 *   @0x1aa080 blx r3
 *   @0x1aa084 vldr s15, [r9, #52]
 *   @0x1aa088 vcvt.f64.f32 d6, s15
 *   @0x1aa08c ldr r3, [r4]
 *   @0x1aa090 mov r1, #8
 *   @0x1aa094 mov r2, r8
 *   @0x1aa098 str r5, [r4, #0x38]
 *   @0x1aa09c mov r0, r4
 *   @0x1aa0a0 vmov r6, r7, d6
 *   @0x1aa0a4 vstr s12, [r4, #44]
 *   @0x1aa0a8 str r7, [r4, #0x30]
 *   @0x1aa0ac ldr r3, [r3, #0x8]
 *   @0x1aa0b0 blx r3
 *   @0x1aa0b4 vldr s15, [r9, #56]
 *   @0x1aa0b8 vcvt.f64.f32 d6, s15
 *   @0x1aa0bc ldr r3, [r4]
 *   @0x1aa0c0 mov r1, #8
 *   @0x1aa0c4 mov r2, r8
 *   @0x1aa0c8 str r5, [r4, #0x38]
 *   @0x1aa0cc mov r0, r4
 *   @0x1aa0d0 vmov r6, r7, d6
 *   @0x1aa0d4 vstr s12, [r4, #44]
 *   @0x1aa0d8 str r7, [r4, #0x30]
 *   @0x1aa0dc ldr r3, [r3, #0x8]
 *   @0x1aa0e0 blx r3
 *   @0x1aa0e4 vldr s15, [r9, #60]
 *   @0x1aa0e8 vcvt.f64.f32 d6, s15
 *   @0x1aa0ec ldr r3, [r4]
 *   @0x1aa0f0 mov r1, #8
 *   @0x1aa0f4 mov r2, r8
 *   @0x1aa0f8 str r5, [r4, #0x38]
 *   @0x1aa0fc mov r0, r4
 *   @0x1aa100 vmov r6, r7, d6
 *   @0x1aa104 vstr s12, [r4, #44]
 *   @0x1aa108 str r7, [r4, #0x30]
 *   @0x1aa10c ldr r3, [r3, #0x8]
 *   @0x1aa110 blx r3
 *   @0x1aa114 ldr r6, [r9, #0x40]
 *   @0x1aa118 ldr r3, [r4]
 *   @0x1aa11c mov r1, #5
 *   @0x1aa120 mov r2, r8
 *   @0x1aa124 mov r0, r4
 *   @0x1aa128 vmov s15, r6
 *   @0x1aa12c str r5, [r4, #0x38]
 *   @0x1aa130 vcvt.f64.u32 d7, s15
 *   @0x1aa134 vmov r6, r7, d7
 *   @0x1aa138 vstr s14, [r4, #44]
 *   @0x1aa13c str r7, [r4, #0x30]
 *   @0x1aa140 ldr r3, [r3, #0x8]
 *   @0x1aa144 blx r3
 *   @0x1aa148 vldr s15, [r9, #68]
 *   @0x1aa14c vcvt.f64.f32 d6, s15
 *   @0x1aa150 ldr r3, [r4]
 *   @0x1aa154 mov r1, #8
 *   @0x1aa158 mov r2, r8
 *   @0x1aa15c str r5, [r4, #0x38]
 *   @0x1aa160 mov r0, r4
 *   @0x1aa164 vmov r6, r7, d6
 *   @0x1aa168 vstr s12, [r4, #44]
 *   @0x1aa16c str r7, [r4, #0x30]
 *   @0x1aa170 ldr r3, [r3, #0x8]
 *   @0x1aa174 blx r3
 *   @0x1aa178 ldr r6, [r9, #0x48]
 *   @0x1aa17c ldr r3, [r4]
 *   @0x1aa180 mov r1, #6
 *   @0x1aa184 mov r2, r8
 *   @0x1aa188 mov r0, r4
 *   @0x1aa18c vmov s15, r6
 *   @0x1aa190 str r5, [r4, #0x38]
 *   @0x1aa194 vcvt.f64.s32 d7, s15
 *   @0x1aa198 vmov r6, r7, d7
 *   @0x1aa19c vstr s14, [r4, #44]
 *   @0x1aa1a0 str r7, [r4, #0x30]
 *   @0x1aa1a4 ldr r3, [r3, #0x8]
 *   @0x1aa1a8 blx r3
 *   @0x1aa1ac ldr r6, [r9, #0x4c]
 *   @0x1aa1b0 ldr r3, [r4]
 *   @0x1aa1b4 mov r0, r4
 *   @0x1aa1b8 str r5, [r4, #0x38]
 *   @0x1aa1bc mov r1, #6
 *   @0x1aa1c0 vmov s13, r6
 *   @0x1aa1c4 mov r2, r8
 *   @0x1aa1c8 vcvt.f64.s32 d6, s13
 *   @0x1aa1cc vmov r6, r7, d6
 *   @0x1aa1d0 vstr s12, [r4, #44]
 *   @0x1aa1d4 str r7, [r4, #0x30]
 *   @0x1aa1d8 ldr r3, [r3, #0x8]
 *   @0x1aa1dc blx r3
 *   @0x1aa1e0 ldr r9, [r9, #0x14]
 *   @0x1aa1e4 cmp r9, #0
 *   @0x1aa1e8 bne 0x1a9f48 <_ZN6CLayer9SerializeEP7IBuffer+0xb20>
 *   @0x1aa1ec add sp, sp, #28
 *   @0x1aa1f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1aa1f4 add r7, r7, #1
 *   @0x1aa1f8 b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8>
 *   @0x1aa1fc add r2, r2, #1
 *   @0x1aa200 b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8>
 *   @0x1aa204 add r0, r0, #1
 *   @0x1aa208 b 0x1a9700 <_ZN6CLayer9SerializeEP7IBuffer+0x2d8>
 *   @0x1aa20c str r3, [sp, #0x10]
 *   @0x1aa210 mov r2, #0
 *   @0x1aa214 ldr r1, [sp, #0x10]
 *   @0x1aa218 mov r3, #0
 *   @0x1aa21c str r1, [sp, #0x14]
 *   @0x1aa220 mov r7, r1
 *   @0x1aa224 b 0x1a9720 <_ZN6CLayer9SerializeEP7IBuffer+0x2f8>
 *
 * ══ §6/13 InitLocalVariables()  0x1fed5c  size 3540  885 条（0x1fed5c..0x1ffb30）
 * @func 0x1fed5c 0x1ffb30  size 3540  885 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Variable_BuiltIn_Add(char const*, bool (*)(CInstance*, int, RValue*), bool (*)(CInstance*, int, RValue*), bool)×85
 * 字段偏移 top8: 0xa3c×3 / 0xa28×2 / 0xa14×2 / 0xa00×2 / 0x9ec×2 / 0x9d8×2 / 0x9c4×2 / 0x9b0×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fed5c push {r4, lr}
 *   @0x1fed60 mov r3, #1
 *   @0x1fed64 ldr r4, [pc, #0xa3c]
 *   @0x1fed68 ldr r1, [pc, #0xa3c]
 *   @0x1fed6c ldr r2, [pc, #0xa3c]
 *   @0x1fed70 add r4, pc, r4
 *   @0x1fed74 ldr r0, [pc, #0xa38]
 *   @0x1fed78 ldr r1, [r4, r1]
 *   @0x1fed7c ldr r2, [r4, r2]
 *   @0x1fed80 add r0, pc, r0
 *   @0x1fed84 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fed88 ldr r1, [pc, #0xa28]
 *   @0x1fed8c ldr r2, [pc, #0xa28]
 *   @0x1fed90 mov r3, #1
 *   @0x1fed94 ldr r0, [pc, #0xa24]
 *   @0x1fed98 ldr r1, [r4, r1]
 *   @0x1fed9c ldr r2, [r4, r2]
 *   @0x1feda0 add r0, pc, r0
 *   @0x1feda4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1feda8 ldr r1, [pc, #0xa14]
 *   @0x1fedac ldr r2, [pc, #0xa14]
 *   @0x1fedb0 mov r3, #1
 *   @0x1fedb4 ldr r0, [pc, #0xa10]
 *   @0x1fedb8 ldr r1, [r4, r1]
 *   @0x1fedbc ldr r2, [r4, r2]
 *   @0x1fedc0 add r0, pc, r0
 *   @0x1fedc4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fedc8 ldr r1, [pc, #0xa00]
 *   @0x1fedcc ldr r2, [pc, #0xa00]
 *   @0x1fedd0 mov r3, #1
 *   @0x1fedd4 ldr r0, [pc, #0x9fc]
 *   @0x1fedd8 ldr r1, [r4, r1]
 *   @0x1feddc ldr r2, [r4, r2]
 *   @0x1fede0 add r0, pc, r0
 *   @0x1fede4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fede8 ldr r1, [pc, #0x9ec]
 *   @0x1fedec ldr r2, [pc, #0x9ec]
 *   @0x1fedf0 mov r3, #1
 *   @0x1fedf4 ldr r0, [pc, #0x9e8]
 *   @0x1fedf8 ldr r1, [r4, r1]
 *   @0x1fedfc ldr r2, [r4, r2]
 *   @0x1fee00 add r0, pc, r0
 *   @0x1fee04 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fee08 ldr r1, [pc, #0x9d8]
 *   @0x1fee0c ldr r2, [pc, #0x9d8]
 *   @0x1fee10 mov r3, #1
 *   @0x1fee14 ldr r0, [pc, #0x9d4]
 *   @0x1fee18 ldr r1, [r4, r1]
 *   @0x1fee1c ldr r2, [r4, r2]
 *   @0x1fee20 add r0, pc, r0
 *   @0x1fee24 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fee28 ldr r1, [pc, #0x9c4]
 *   @0x1fee2c ldr r2, [pc, #0x9c4]
 *   @0x1fee30 mov r3, #1
 *   @0x1fee34 ldr r0, [pc, #0x9c0]
 *   @0x1fee38 ldr r1, [r4, r1]
 *   @0x1fee3c ldr r2, [r4, r2]
 *   @0x1fee40 add r0, pc, r0
 *   @0x1fee44 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fee48 ldr r1, [pc, #0x9b0]
 *   @0x1fee4c ldr r2, [pc, #0x9b0]
 *   @0x1fee50 mov r3, #1
 *   @0x1fee54 ldr r0, [pc, #0x9ac]
 *   @0x1fee58 ldr r1, [r4, r1]
 *   @0x1fee5c ldr r2, [r4, r2]
 *   @0x1fee60 add r0, pc, r0
 *   @0x1fee64 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fee68 ldr r1, [pc, #0x99c]
 *   @0x1fee6c ldr r2, [pc, #0x99c]
 *   @0x1fee70 mov r3, #1
 *   @0x1fee74 ldr r0, [pc, #0x998]
 *   @0x1fee78 ldr r1, [r4, r1]
 *   @0x1fee7c ldr r2, [r4, r2]
 *   @0x1fee80 add r0, pc, r0
 *   @0x1fee84 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fee88 ldr r1, [pc, #0x988]
 *   @0x1fee8c ldr r2, [pc, #0x988]
 *   @0x1fee90 mov r3, #1
 *   @0x1fee94 ldr r0, [pc, #0x984]
 *   @0x1fee98 ldr r1, [r4, r1]
 *   @0x1fee9c ldr r2, [r4, r2]
 *   @0x1feea0 add r0, pc, r0
 *   @0x1feea4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1feea8 ldr r1, [pc, #0x974]
 *   @0x1feeac ldr r2, [pc, #0x974]
 *   @0x1feeb0 mov r3, #1
 *   @0x1feeb4 ldr r0, [pc, #0x970]
 *   @0x1feeb8 ldr r1, [r4, r1]
 *   @0x1feebc ldr r2, [r4, r2]
 *   @0x1feec0 add r0, pc, r0
 *   @0x1feec4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1feec8 ldr r1, [pc, #0x960]
 *   @0x1feecc ldr r2, [pc, #0x960]
 *   @0x1feed0 mov r3, #1
 *   @0x1feed4 ldr r0, [pc, #0x95c]
 *   @0x1feed8 ldr r1, [r4, r1]
 *   @0x1feedc ldr r2, [r4, r2]
 *   @0x1feee0 add r0, pc, r0
 *   @0x1feee4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1feee8 ldr r1, [pc, #0x94c]
 *   @0x1feeec ldr r2, [pc, #0x94c]
 *   @0x1feef0 mov r3, #1
 *   @0x1feef4 ldr r0, [pc, #0x948]
 *   @0x1feef8 ldr r1, [r4, r1]
 *   @0x1feefc ldr r2, [r4, r2]
 *   @0x1fef00 add r0, pc, r0
 *   @0x1fef04 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fef08 ldr r1, [pc, #0x938]
 *   @0x1fef0c ldr r0, [pc, #0x938]
 *   @0x1fef10 mov r2, #0
 *   @0x1fef14 mov r3, r2
 *   @0x1fef18 ldr r1, [r4, r1]
 *   @0x1fef1c add r0, pc, r0
 *   @0x1fef20 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fef24 ldr r1, [pc, #0x924]
 *   @0x1fef28 ldr r0, [pc, #0x924]
 *   @0x1fef2c mov r2, #0
 *   @0x1fef30 mov r3, r2
 *   @0x1fef34 ldr r1, [r4, r1]
 *   @0x1fef38 add r0, pc, r0
 *   @0x1fef3c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fef40 ldr r1, [pc, #0x910]
 *   @0x1fef44 ldr r2, [pc, #0x910]
 *   @0x1fef48 mov r3, #1
 *   @0x1fef4c ldr r0, [pc, #0x90c]
 *   @0x1fef50 ldr r1, [r4, r1]
 *   @0x1fef54 ldr r2, [r4, r2]
 *   @0x1fef58 add r0, pc, r0
 *   @0x1fef5c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fef60 ldr r1, [pc, #0x8fc]
 *   @0x1fef64 ldr r2, [pc, #0x8fc]
 *   @0x1fef68 mov r3, #1
 *   @0x1fef6c ldr r0, [pc, #0x8f8]
 *   @0x1fef70 ldr r1, [r4, r1]
 *   @0x1fef74 ldr r2, [r4, r2]
 *   @0x1fef78 add r0, pc, r0
 *   @0x1fef7c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fef80 ldr r1, [pc, #0x8e8]
 *   @0x1fef84 ldr r2, [pc, #0x8e8]
 *   @0x1fef88 mov r3, #1
 *   @0x1fef8c ldr r0, [pc, #0x8e4]
 *   @0x1fef90 ldr r1, [r4, r1]
 *   @0x1fef94 ldr r2, [r4, r2]
 *   @0x1fef98 add r0, pc, r0
 *   @0x1fef9c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fefa0 ldr r1, [pc, #0x8d4]
 *   @0x1fefa4 ldr r2, [pc, #0x8d4]
 *   @0x1fefa8 mov r3, #1
 *   @0x1fefac ldr r0, [pc, #0x8d0]
 *   @0x1fefb0 ldr r1, [r4, r1]
 *   @0x1fefb4 ldr r2, [r4, r2]
 *   @0x1fefb8 add r0, pc, r0
 *   @0x1fefbc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fefc0 ldr r1, [pc, #0x8c0]
 *   @0x1fefc4 ldr r2, [pc, #0x8c0]
 *   @0x1fefc8 mov r3, #1
 *   @0x1fefcc ldr r0, [pc, #0x8bc]
 *   @0x1fefd0 ldr r1, [r4, r1]
 *   @0x1fefd4 ldr r2, [r4, r2]
 *   @0x1fefd8 add r0, pc, r0
 *   @0x1fefdc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1fefe0 ldr r1, [pc, #0x8ac]
 *   @0x1fefe4 ldr r0, [pc, #0x8ac]
 *   @0x1fefe8 mov r2, #0
 *   @0x1fefec mov r3, r2
 *   @0x1feff0 ldr r1, [r4, r1]
 *   @0x1feff4 add r0, pc, r0
 *   @0x1feff8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1feffc ldr r1, [pc, #0x898]
 *   @0x1ff000 ldr r0, [pc, #0x898]
 *   @0x1ff004 mov r2, #0
 *   @0x1ff008 mov r3, r2
 *   @0x1ff00c ldr r1, [r4, r1]
 *   @0x1ff010 add r0, pc, r0
 *   @0x1ff014 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff018 ldr r1, [pc, #0x884]
 *   @0x1ff01c ldr r0, [pc, #0x884]
 *   @0x1ff020 mov r2, #0
 *   @0x1ff024 mov r3, r2
 *   @0x1ff028 ldr r1, [r4, r1]
 *   @0x1ff02c add r0, pc, r0
 *   @0x1ff030 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff034 ldr r1, [pc, #0x870]
 *   @0x1ff038 ldr r0, [pc, #0x870]
 *   @0x1ff03c mov r2, #0
 *   @0x1ff040 mov r3, r2
 *   @0x1ff044 ldr r1, [r4, r1]
 *   @0x1ff048 add r0, pc, r0
 *   @0x1ff04c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff050 ldr r1, [pc, #0x85c]
 *   @0x1ff054 ldr r2, [pc, #0x85c]
 *   @0x1ff058 mov r3, #1
 *   @0x1ff05c ldr r0, [pc, #0x858]
 *   @0x1ff060 ldr r1, [r4, r1]
 *   @0x1ff064 ldr r2, [r4, r2]
 *   @0x1ff068 add r0, pc, r0
 *   @0x1ff06c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff070 ldr r1, [pc, #0x848]
 *   @0x1ff074 ldr r2, [pc, #0x848]
 *   @0x1ff078 mov r3, #1
 *   @0x1ff07c ldr r0, [pc, #0x844]
 *   @0x1ff080 ldr r1, [r4, r1]
 *   @0x1ff084 ldr r2, [r4, r2]
 *   @0x1ff088 add r0, pc, r0
 *   @0x1ff08c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff090 ldr r1, [pc, #0x834]
 *   @0x1ff094 ldr r2, [pc, #0x834]
 *   @0x1ff098 mov r3, #1
 *   @0x1ff09c ldr r0, [pc, #0x830]
 *   @0x1ff0a0 ldr r1, [r4, r1]
 *   @0x1ff0a4 ldr r2, [r4, r2]
 *   @0x1ff0a8 add r0, pc, r0
 *   @0x1ff0ac bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff0b0 ldr r1, [pc, #0x820]
 *   @0x1ff0b4 ldr r0, [pc, #0x820]
 *   @0x1ff0b8 mov r2, #0
 *   @0x1ff0bc mov r3, r2
 *   @0x1ff0c0 ldr r1, [r4, r1]
 *   @0x1ff0c4 add r0, pc, r0
 *   @0x1ff0c8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff0cc ldr r1, [pc, #0x80c]
 *   @0x1ff0d0 ldr r0, [pc, #0x80c]
 *   @0x1ff0d4 mov r2, #0
 *   @0x1ff0d8 mov r3, r2
 *   @0x1ff0dc ldr r1, [r4, r1]
 *   @0x1ff0e0 add r0, pc, r0
 *   @0x1ff0e4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff0e8 ldr r1, [pc, #0x7f8]
 *   @0x1ff0ec ldr r0, [pc, #0x7f8]
 *   @0x1ff0f0 mov r2, #0
 *   @0x1ff0f4 mov r3, r2
 *   @0x1ff0f8 ldr r1, [r4, r1]
 *   @0x1ff0fc add r0, pc, r0
 *   @0x1ff100 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff104 ldr r1, [pc, #0x7e4]
 *   @0x1ff108 ldr r0, [pc, #0x7e4]
 *   @0x1ff10c mov r2, #0
 *   @0x1ff110 mov r3, r2
 *   @0x1ff114 ldr r1, [r4, r1]
 *   @0x1ff118 add r0, pc, r0
 *   @0x1ff11c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff120 ldr r1, [pc, #0x7d0]
 *   @0x1ff124 ldr r0, [pc, #0x7d0]
 *   @0x1ff128 mov r2, #0
 *   @0x1ff12c mov r3, r2
 *   @0x1ff130 ldr r1, [r4, r1]
 *   @0x1ff134 add r0, pc, r0
 *   @0x1ff138 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff13c ldr r1, [pc, #0x7bc]
 *   @0x1ff140 ldr r2, [pc, #0x7bc]
 *   @0x1ff144 mov r3, #1
 *   @0x1ff148 ldr r0, [pc, #0x7b8]
 *   @0x1ff14c ldr r1, [r4, r1]
 *   @0x1ff150 ldr r2, [r4, r2]
 *   @0x1ff154 add r0, pc, r0
 *   @0x1ff158 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff15c ldr r1, [pc, #0x7a8]
 *   @0x1ff160 ldr r2, [pc, #0x7a8]
 *   @0x1ff164 mov r3, #1
 *   @0x1ff168 ldr r0, [pc, #0x7a4]
 *   @0x1ff16c ldr r1, [r4, r1]
 *   @0x1ff170 ldr r2, [r4, r2]
 *   @0x1ff174 add r0, pc, r0
 *   @0x1ff178 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff17c ldr r1, [pc, #0x794]
 *   @0x1ff180 ldr r2, [pc, #0x794]
 *   @0x1ff184 mov r3, #1
 *   @0x1ff188 ldr r0, [pc, #0x790]
 *   @0x1ff18c ldr r1, [r4, r1]
 *   @0x1ff190 ldr r2, [r4, r2]
 *   @0x1ff194 add r0, pc, r0
 *   @0x1ff198 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff19c ldr r1, [pc, #0x780]
 *   @0x1ff1a0 ldr r2, [pc, #0x780]
 *   @0x1ff1a4 mov r3, #1
 *   @0x1ff1a8 ldr r0, [pc, #0x77c]
 *   @0x1ff1ac ldr r1, [r4, r1]
 *   @0x1ff1b0 ldr r2, [r4, r2]
 *   @0x1ff1b4 add r0, pc, r0
 *   @0x1ff1b8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff1bc ldr r1, [pc, #0x76c]
 *   @0x1ff1c0 ldr r2, [pc, #0x76c]
 *   @0x1ff1c4 mov r3, #1
 *   @0x1ff1c8 ldr r0, [pc, #0x768]
 *   @0x1ff1cc ldr r1, [r4, r1]
 *   @0x1ff1d0 ldr r2, [r4, r2]
 *   @0x1ff1d4 add r0, pc, r0
 *   @0x1ff1d8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff1dc ldr r1, [pc, #0x758]
 *   @0x1ff1e0 ldr r2, [pc, #0x758]
 *   @0x1ff1e4 mov r3, #1
 *   @0x1ff1e8 ldr r0, [pc, #0x754]
 *   @0x1ff1ec ldr r1, [r4, r1]
 *   @0x1ff1f0 ldr r2, [r4, r2]
 *   @0x1ff1f4 add r0, pc, r0
 *   @0x1ff1f8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff1fc ldr r1, [pc, #0x744]
 *   @0x1ff200 ldr r2, [pc, #0x744]
 *   @0x1ff204 mov r3, #1
 *   @0x1ff208 ldr r0, [pc, #0x740]
 *   @0x1ff20c ldr r1, [r4, r1]
 *   @0x1ff210 ldr r2, [r4, r2]
 *   @0x1ff214 add r0, pc, r0
 *   @0x1ff218 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff21c ldr r1, [pc, #0x730]
 *   @0x1ff220 ldr r0, [pc, #0x730]
 *   @0x1ff224 mov r2, #0
 *   @0x1ff228 mov r3, r2
 *   @0x1ff22c ldr r1, [r4, r1]
 *   @0x1ff230 add r0, pc, r0
 *   @0x1ff234 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff238 ldr r1, [pc, #0x71c]
 *   @0x1ff23c ldr r2, [pc, #0x71c]
 *   @0x1ff240 mov r3, #1
 *   @0x1ff244 ldr r0, [pc, #0x718]
 *   @0x1ff248 ldr r1, [r4, r1]
 *   @0x1ff24c ldr r2, [r4, r2]
 *   @0x1ff250 add r0, pc, r0
 *   @0x1ff254 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff258 ldr r1, [pc, #0x708]
 *   @0x1ff25c ldr r2, [pc, #0x708]
 *   @0x1ff260 mov r3, #1
 *   @0x1ff264 ldr r0, [pc, #0x704]
 *   @0x1ff268 ldr r1, [r4, r1]
 *   @0x1ff26c ldr r2, [r4, r2]
 *   @0x1ff270 add r0, pc, r0
 *   @0x1ff274 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff278 ldr r1, [pc, #0x6f4]
 *   @0x1ff27c ldr r2, [pc, #0x6f4]
 *   @0x1ff280 mov r3, #1
 *   @0x1ff284 ldr r0, [pc, #0x6f0]
 *   @0x1ff288 ldr r1, [r4, r1]
 *   @0x1ff28c ldr r2, [r4, r2]
 *   @0x1ff290 add r0, pc, r0
 *   @0x1ff294 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff298 ldr r1, [pc, #0x6e0]
 *   @0x1ff29c ldr r2, [pc, #0x6e0]
 *   @0x1ff2a0 mov r3, #1
 *   @0x1ff2a4 ldr r0, [pc, #0x6dc]
 *   @0x1ff2a8 ldr r1, [r4, r1]
 *   @0x1ff2ac ldr r2, [r4, r2]
 *   @0x1ff2b0 add r0, pc, r0
 *   @0x1ff2b4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff2b8 ldr r1, [pc, #0x6cc]
 *   @0x1ff2bc ldr r2, [pc, #0x6cc]
 *   @0x1ff2c0 mov r3, #1
 *   @0x1ff2c4 ldr r0, [pc, #0x6c8]
 *   @0x1ff2c8 ldr r1, [r4, r1]
 *   @0x1ff2cc ldr r2, [r4, r2]
 *   @0x1ff2d0 add r0, pc, r0
 *   @0x1ff2d4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff2d8 ldr r1, [pc, #0x6b8]
 *   @0x1ff2dc ldr r2, [pc, #0x6b8]
 *   @0x1ff2e0 mov r3, #1
 *   @0x1ff2e4 ldr r0, [pc, #0x6b4]
 *   @0x1ff2e8 ldr r1, [r4, r1]
 *   @0x1ff2ec ldr r2, [r4, r2]
 *   @0x1ff2f0 add r0, pc, r0
 *   @0x1ff2f4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff2f8 ldr r1, [pc, #0x6a4]
 *   @0x1ff2fc ldr r2, [pc, #0x6a4]
 *   @0x1ff300 mov r3, #1
 *   @0x1ff304 ldr r0, [pc, #0x6a0]
 *   @0x1ff308 ldr r1, [r4, r1]
 *   @0x1ff30c ldr r2, [r4, r2]
 *   @0x1ff310 add r0, pc, r0
 *   @0x1ff314 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff318 ldr r1, [pc, #0x690]
 *   @0x1ff31c ldr r2, [pc, #0x690]
 *   @0x1ff320 mov r3, #1
 *   @0x1ff324 ldr r0, [pc, #0x68c]
 *   @0x1ff328 ldr r1, [r4, r1]
 *   @0x1ff32c ldr r2, [r4, r2]
 *   @0x1ff330 add r0, pc, r0
 *   @0x1ff334 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff338 ldr r1, [pc, #0x67c]
 *   @0x1ff33c ldr r2, [pc, #0x67c]
 *   @0x1ff340 mov r3, #1
 *   @0x1ff344 ldr r0, [pc, #0x678]
 *   @0x1ff348 ldr r1, [r4, r1]
 *   @0x1ff34c ldr r2, [r4, r2]
 *   @0x1ff350 add r0, pc, r0
 *   @0x1ff354 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff358 ldr r1, [pc, #0x668]
 *   @0x1ff35c ldr r2, [pc, #0x668]
 *   @0x1ff360 mov r3, #1
 *   @0x1ff364 ldr r0, [pc, #0x664]
 *   @0x1ff368 ldr r1, [r4, r1]
 *   @0x1ff36c ldr r2, [r4, r2]
 *   @0x1ff370 add r0, pc, r0
 *   @0x1ff374 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff378 ldr r1, [pc, #0x654]
 *   @0x1ff37c ldr r2, [pc, #0x654]
 *   @0x1ff380 mov r3, #1
 *   @0x1ff384 ldr r0, [pc, #0x650]
 *   @0x1ff388 ldr r1, [r4, r1]
 *   @0x1ff38c ldr r2, [r4, r2]
 *   @0x1ff390 add r0, pc, r0
 *   @0x1ff394 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff398 ldr r1, [pc, #0x640]
 *   @0x1ff39c ldr r0, [pc, #0x640]
 *   @0x1ff3a0 mov r2, #0
 *   @0x1ff3a4 mov r3, #1
 *   @0x1ff3a8 ldr r1, [r4, r1]
 *   @0x1ff3ac add r0, pc, r0
 *   @0x1ff3b0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff3b4 ldr r1, [pc, #0x62c]
 *   @0x1ff3b8 ldr r0, [pc, #0x62c]
 *   @0x1ff3bc mov r2, #0
 *   @0x1ff3c0 mov r3, #1
 *   @0x1ff3c4 ldr r1, [r4, r1]
 *   @0x1ff3c8 add r0, pc, r0
 *   @0x1ff3cc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff3d0 ldr r1, [pc, #0x618]
 *   @0x1ff3d4 ldr r0, [pc, #0x618]
 *   @0x1ff3d8 mov r2, #0
 *   @0x1ff3dc mov r3, r2
 *   @0x1ff3e0 ldr r1, [r4, r1]
 *   @0x1ff3e4 add r0, pc, r0
 *   @0x1ff3e8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff3ec ldr r1, [pc, #0x604]
 *   @0x1ff3f0 ldr r2, [pc, #0x604]
 *   @0x1ff3f4 mov r3, #1
 *   @0x1ff3f8 ldr r0, [pc, #0x600]
 *   @0x1ff3fc ldr r1, [r4, r1]
 *   @0x1ff400 ldr r2, [r4, r2]
 *   @0x1ff404 add r0, pc, r0
 *   @0x1ff408 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff40c ldr r1, [pc, #0x5f0]
 *   @0x1ff410 ldr r2, [pc, #0x5f0]
 *   @0x1ff414 mov r3, #1
 *   @0x1ff418 ldr r0, [pc, #0x5ec]
 *   @0x1ff41c ldr r1, [r4, r1]
 *   @0x1ff420 ldr r2, [r4, r2]
 *   @0x1ff424 add r0, pc, r0
 *   @0x1ff428 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff42c ldr r1, [pc, #0x5dc]
 *   @0x1ff430 ldr r2, [pc, #0x5dc]
 *   @0x1ff434 mov r3, #1
 *   @0x1ff438 ldr r0, [pc, #0x5d8]
 *   @0x1ff43c ldr r1, [r4, r1]
 *   @0x1ff440 ldr r2, [r4, r2]
 *   @0x1ff444 add r0, pc, r0
 *   @0x1ff448 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff44c ldr r1, [pc, #0x5c8]
 *   @0x1ff450 ldr r2, [pc, #0x5c8]
 *   @0x1ff454 mov r3, #1
 *   @0x1ff458 ldr r0, [pc, #0x5c4]
 *   @0x1ff45c ldr r1, [r4, r1]
 *   @0x1ff460 ldr r2, [r4, r2]
 *   @0x1ff464 add r0, pc, r0
 *   @0x1ff468 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff46c ldr r1, [pc, #0x5b4]
 *   @0x1ff470 ldr r2, [pc, #0x5b4]
 *   @0x1ff474 mov r3, #1
 *   @0x1ff478 ldr r0, [pc, #0x5b0]
 *   @0x1ff47c ldr r1, [r4, r1]
 *   @0x1ff480 ldr r2, [r4, r2]
 *   @0x1ff484 add r0, pc, r0
 *   @0x1ff488 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff48c ldr r1, [pc, #0x5a0]
 *   @0x1ff490 ldr r2, [pc, #0x5a0]
 *   @0x1ff494 mov r3, #1
 *   @0x1ff498 ldr r0, [pc, #0x59c]
 *   @0x1ff49c ldr r1, [r4, r1]
 *   @0x1ff4a0 ldr r2, [r4, r2]
 *   @0x1ff4a4 add r0, pc, r0
 *   @0x1ff4a8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff4ac ldr r1, [pc, #0x58c]
 *   @0x1ff4b0 ldr r2, [pc, #0x58c]
 *   @0x1ff4b4 mov r3, #1
 *   @0x1ff4b8 ldr r0, [pc, #0x588]
 *   @0x1ff4bc ldr r1, [r4, r1]
 *   @0x1ff4c0 ldr r2, [r4, r2]
 *   @0x1ff4c4 add r0, pc, r0
 *   @0x1ff4c8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff4cc ldr r1, [pc, #0x578]
 *   @0x1ff4d0 ldr r2, [pc, #0x578]
 *   @0x1ff4d4 mov r3, #1
 *   @0x1ff4d8 ldr r0, [pc, #0x574]
 *   @0x1ff4dc ldr r1, [r4, r1]
 *   @0x1ff4e0 ldr r2, [r4, r2]
 *   @0x1ff4e4 add r0, pc, r0
 *   @0x1ff4e8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff4ec ldr r1, [pc, #0x564]
 *   @0x1ff4f0 ldr r2, [pc, #0x564]
 *   @0x1ff4f4 mov r3, #1
 *   @0x1ff4f8 ldr r0, [pc, #0x560]
 *   @0x1ff4fc ldr r1, [r4, r1]
 *   @0x1ff500 ldr r2, [r4, r2]
 *   @0x1ff504 add r0, pc, r0
 *   @0x1ff508 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff50c ldr r1, [pc, #0x550]
 *   @0x1ff510 ldr r2, [pc, #0x550]
 *   @0x1ff514 mov r3, #1
 *   @0x1ff518 ldr r0, [pc, #0x54c]
 *   @0x1ff51c ldr r1, [r4, r1]
 *   @0x1ff520 ldr r2, [r4, r2]
 *   @0x1ff524 add r0, pc, r0
 *   @0x1ff528 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff52c ldr r1, [pc, #0x53c]
 *   @0x1ff530 ldr r2, [pc, #0x53c]
 *   @0x1ff534 mov r3, #1
 *   @0x1ff538 ldr r0, [pc, #0x538]
 *   @0x1ff53c ldr r1, [r4, r1]
 *   @0x1ff540 ldr r2, [r4, r2]
 *   @0x1ff544 add r0, pc, r0
 *   @0x1ff548 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff54c ldr r1, [pc, #0x528]
 *   @0x1ff550 ldr r2, [pc, #0x528]
 *   @0x1ff554 mov r3, #1
 *   @0x1ff558 ldr r0, [pc, #0x524]
 *   @0x1ff55c ldr r1, [r4, r1]
 *   @0x1ff560 ldr r2, [r4, r2]
 *   @0x1ff564 add r0, pc, r0
 *   @0x1ff568 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff56c ldr r1, [pc, #0x514]
 *   @0x1ff570 ldr r2, [pc, #0x514]
 *   @0x1ff574 mov r3, #1
 *   @0x1ff578 ldr r0, [pc, #0x510]
 *   @0x1ff57c ldr r1, [r4, r1]
 *   @0x1ff580 ldr r2, [r4, r2]
 *   @0x1ff584 add r0, pc, r0
 *   @0x1ff588 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff58c ldr r1, [pc, #0x500]
 *   @0x1ff590 ldr r0, [pc, #0x500]
 *   @0x1ff594 mov r2, #0
 *   @0x1ff598 mov r3, r2
 *   @0x1ff59c ldr r1, [r4, r1]
 *   @0x1ff5a0 add r0, pc, r0
 *   @0x1ff5a4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff5a8 ldr r1, [pc, #0x4ec]
 *   @0x1ff5ac ldr r0, [pc, #0x4ec]
 *   @0x1ff5b0 mov r2, #0
 *   @0x1ff5b4 mov r3, r2
 *   @0x1ff5b8 ldr r1, [r4, r1]
 *   @0x1ff5bc add r0, pc, r0
 *   @0x1ff5c0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff5c4 ldr r1, [pc, #0x4d8]
 *   @0x1ff5c8 ldr r0, [pc, #0x4d8]
 *   @0x1ff5cc mov r2, #0
 *   @0x1ff5d0 mov r3, r2
 *   @0x1ff5d4 ldr r1, [r4, r1]
 *   @0x1ff5d8 add r0, pc, r0
 *   @0x1ff5dc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff5e0 ldr r1, [pc, #0x4c4]
 *   @0x1ff5e4 ldr r0, [pc, #0x4c4]
 *   @0x1ff5e8 mov r2, #0
 *   @0x1ff5ec mov r3, r2
 *   @0x1ff5f0 ldr r1, [r4, r1]
 *   @0x1ff5f4 add r0, pc, r0
 *   @0x1ff5f8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff5fc ldr r1, [pc, #0x4b0]
 *   @0x1ff600 ldr r0, [pc, #0x4b0]
 *   @0x1ff604 mov r2, #0
 *   @0x1ff608 mov r3, r2
 *   @0x1ff60c ldr r1, [r4, r1]
 *   @0x1ff610 add r0, pc, r0
 *   @0x1ff614 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff618 ldr r1, [pc, #0x49c]
 *   @0x1ff61c ldr r0, [pc, #0x49c]
 *   @0x1ff620 mov r2, #0
 *   @0x1ff624 mov r3, r2
 *   @0x1ff628 ldr r1, [r4, r1]
 *   @0x1ff62c add r0, pc, r0
 *   @0x1ff630 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff634 ldr r1, [pc, #0x488]
 *   @0x1ff638 ldr r0, [pc, #0x488]
 *   @0x1ff63c mov r2, #0
 *   @0x1ff640 mov r3, r2
 *   @0x1ff644 ldr r1, [r4, r1]
 *   @0x1ff648 add r0, pc, r0
 *   @0x1ff64c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff650 ldr r1, [pc, #0x474]
 *   @0x1ff654 ldr r0, [pc, #0x474]
 *   @0x1ff658 mov r2, #0
 *   @0x1ff65c mov r3, r2
 *   @0x1ff660 ldr r1, [r4, r1]
 *   @0x1ff664 add r0, pc, r0
 *   @0x1ff668 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff66c ldr r1, [pc, #0x460]
 *   @0x1ff670 ldr r0, [pc, #0x460]
 *   @0x1ff674 mov r2, #0
 *   @0x1ff678 mov r3, r2
 *   @0x1ff67c ldr r1, [r4, r1]
 *   @0x1ff680 add r0, pc, r0
 *   @0x1ff684 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff688 ldr r1, [pc, #0x44c]
 *   @0x1ff68c ldr r0, [pc, #0x44c]
 *   @0x1ff690 mov r2, #0
 *   @0x1ff694 mov r3, r2
 *   @0x1ff698 ldr r1, [r4, r1]
 *   @0x1ff69c add r0, pc, r0
 *   @0x1ff6a0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff6a4 ldr r1, [pc, #0x438]
 *   @0x1ff6a8 ldr r0, [pc, #0x438]
 *   @0x1ff6ac mov r2, #0
 *   @0x1ff6b0 mov r3, r2
 *   @0x1ff6b4 ldr r1, [r4, r1]
 *   @0x1ff6b8 add r0, pc, r0
 *   @0x1ff6bc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff6c0 ldr r1, [pc, #0x424]
 *   @0x1ff6c4 ldr r0, [pc, #0x424]
 *   @0x1ff6c8 mov r2, #0
 *   @0x1ff6cc mov r3, r2
 *   @0x1ff6d0 ldr r1, [r4, r1]
 *   @0x1ff6d4 add r0, pc, r0
 *   @0x1ff6d8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff6dc ldr r1, [pc, #0x410]
 *   @0x1ff6e0 ldr r0, [pc, #0x410]
 *   @0x1ff6e4 mov r2, #0
 *   @0x1ff6e8 mov r3, r2
 *   @0x1ff6ec ldr r1, [r4, r1]
 *   @0x1ff6f0 add r0, pc, r0
 *   @0x1ff6f4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff6f8 ldr r1, [pc, #0x3fc]
 *   @0x1ff6fc ldr r0, [pc, #0x3fc]
 *   @0x1ff700 mov r2, #0
 *   @0x1ff704 mov r3, r2
 *   @0x1ff708 ldr r1, [r4, r1]
 *   @0x1ff70c add r0, pc, r0
 *   @0x1ff710 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff714 ldr r1, [pc, #0x3e8]
 *   @0x1ff718 ldr r0, [pc, #0x3e8]
 *   @0x1ff71c mov r2, #0
 *   @0x1ff720 mov r3, r2
 *   @0x1ff724 ldr r1, [r4, r1]
 *   @0x1ff728 add r0, pc, r0
 *   @0x1ff72c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff730 ldr r1, [pc, #0x3d4]
 *   @0x1ff734 ldr r0, [pc, #0x3d4]
 *   @0x1ff738 mov r2, #0
 *   @0x1ff73c mov r3, r2
 *   @0x1ff740 ldr r1, [r4, r1]
 *   @0x1ff744 add r0, pc, r0
 *   @0x1ff748 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff74c ldr r1, [pc, #0x3c0]
 *   @0x1ff750 ldr r0, [pc, #0x3c0]
 *   @0x1ff754 mov r2, #0
 *   @0x1ff758 mov r3, r2
 *   @0x1ff75c ldr r1, [r4, r1]
 *   @0x1ff760 add r0, pc, r0
 *   @0x1ff764 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff768 ldr r1, [pc, #0x3ac]
 *   @0x1ff76c ldr r0, [pc, #0x3ac]
 *   @0x1ff770 mov r2, #0
 *   @0x1ff774 mov r3, r2
 *   @0x1ff778 ldr r1, [r4, r1]
 *   @0x1ff77c add r0, pc, r0
 *   @0x1ff780 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff784 ldr r1, [pc, #0x398]
 *   @0x1ff788 ldr r2, [pc, #0x398]
 *   @0x1ff78c mov r3, #1
 *   @0x1ff790 ldr r0, [pc, #0x394]
 *   @0x1ff794 ldr r1, [r4, r1]
 *   @0x1ff798 ldr r2, [r4, r2]
 *   @0x1ff79c add r0, pc, r0
 *   @0x1ff7a0 pop {r4, lr}
 *   @0x1ff7a4 b 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b>
 *   @0x1ff7a8 andseq r2, pc, r0, ror #29
 *   @0x1ff7ac .word 0xfffff4f8
 *   @0x1ff7b0 .word 0xfffff4fc
 *   @0x1ff7b4 ldrsheq r1, [r3], -r4
 *   @0x1ff7b8 .word 0xfffff500
 *   @0x1ff7bc .word 0xfffff504
 *   @0x1ff7c0 ldrsbeq r1, [r3], -r8
 *   @0x1ff7c4 .word 0xfffff508
 *   @0x1ff7c8 .word 0xfffff50c
 *   @0x1ff7cc andseq r4, r5, r0, ror #8
 *   @0x1ff7d0 .word 0xfffff510
 *   @0x1ff7d4 .word 0xfffff514
 *   @0x1ff7d8 andseq r4, r5, r12, asr #8
 *   @0x1ff7dc .word 0xfffff518
 *   @0x1ff7e0 .word 0xfffff51c
 *   @0x1ff7e4 andseq r4, r5, r8, lsr r4
 *   @0x1ff7e8 .word 0xfffff520
 *   @0x1ff7ec .word 0xfffff524
 *   @0x1ff7f0 andseq r4, r5, r0, lsr #8
 *   @0x1ff7f4 .word 0xfffff528
 *   @0x1ff7f8 .word 0xfffff52c
 *   @0x1ff7fc andseq r4, r5, r8, lsl #8
 *   @0x1ff800 .word 0xfffff530
 *   @0x1ff804 .word 0xfffff534
 *   @0x1ff808 ldrsheq r4, [r5], -r0
 *   @0x1ff80c .word 0xfffff538
 *   @0x1ff810 .word 0xfffff53c
 *   @0x1ff814 ldrsbeq r4, [r5], -r8
 *   @0x1ff818 .word 0xfffff540
 *   @0x1ff81c .word 0xfffff544
 *   @0x1ff820 andseq r4, r5, r4, asr #7
 *   @0x1ff824 .word 0xfffff548
 *   @0x1ff828 .word 0xfffff54c
 *   @0x1ff82c andseq r4, r5, r12, lsr #7
 *   @0x1ff830 .word 0xfffff550
 *   @0x1ff834 .word 0xfffff554
 *   @0x1ff838 mulseq r5, r8, r3
 *   @0x1ff83c .word 0xfffff558
 *   @0x1ff840 .word 0xfffff55c
 *   @0x1ff844 andseq r4, r5, r0, lsl #7
 *   @0x1ff848 .word 0xfffff560
 *   @0x1ff84c andseq r4, r5, r8, ror r3
 *   @0x1ff850 .word 0xfffff564
 *   @0x1ff854 andseq r1, r3, r8, lsl #22
 *   @0x1ff858 .word 0xfffff568
 *   @0x1ff85c .word 0xfffff56c
 *   @0x1ff860 andseq r4, r5, r12, asr #6
 *   @0x1ff864 .word 0xfffff570
 *   @0x1ff868 .word 0xfffff574
 *   @0x1ff86c andseq r4, r5, r4, lsr r3
 *   @0x1ff870 .word 0xfffff578
 *   @0x1ff874 .word 0xfffff57c
 *   @0x1ff878 andseq r4, r5, r12, lsl r3
 *   @0x1ff87c .word 0xfffff580
 *   @0x1ff880 .word 0xfffff584
 *   @0x1ff884 andseq r4, r5, r4, lsl #6
 *   @0x1ff888 .word 0xfffff588
 *   @0x1ff88c .word 0xfffff58c
 *   @0x1ff890 ldrsheq r4, [r5], -r0
 *   @0x1ff894 .word 0xfffff590
 *   @0x1ff898 ldrsbeq r4, [r5], -r12
 *   @0x1ff89c .word 0xfffff594
 *   @0x1ff8a0 andseq r4, r5, r12, asr #5
 *   @0x1ff8a4 .word 0xfffff598
 *   @0x1ff8a8 ldrheq r4, [r5], -r12
 *   @0x1ff8ac .word 0xfffff59c
 *   @0x1ff8b0 andseq r4, r5, r12, lsr #5
 *   @0x1ff8b4 .word 0xfffff5a0
 *   @0x1ff8b8 .word 0xfffff5a4
 *   @0x1ff8bc mulseq r5, r8, r2
 *   @0x1ff8c0 .word 0xfffff5a8
 *   @0x1ff8c4 .word 0xfffff5ac
 *   @0x1ff8c8 andseq r4, r5, r8, lsl #5
 *   @0x1ff8cc .word 0xfffff5b0
 *   @0x1ff8d0 .word 0xfffff5b4
 *   @0x1ff8d4 andseq r4, r5, r4, ror r2
 *   @0x1ff8d8 .word 0xfffff5b8
 *   @0x1ff8dc andseq r4, r5, r8, ror #4
 *   @0x1ff8e0 .word 0xfffff5bc
 *   @0x1ff8e4 andseq r4, r5, r12, asr r2
 *   @0x1ff8e8 .word 0xfffff5c0
 *   @0x1ff8ec andseq r4, r5, r0, asr r2
 *   @0x1ff8f0 .word 0xfffff5c4
 *   @0x1ff8f4 andseq r4, r5, r4, asr #4
 *   @0x1ff8f8 .word 0xfffff5c8
 *   @0x1ff8fc andseq r4, r5, r8, lsr r2
 *   @0x1ff900 .word 0xfffff5cc
 *   @0x1ff904 .word 0xfffff5d0
 *   @0x1ff908 andseq r4, r5, r8, lsr #4
 *   @0x1ff90c .word 0xfffff5d4
 *   @0x1ff910 .word 0xfffff5d8
 *   @0x1ff914 andseq r4, r5, r8, lsl r2
 *   @0x1ff918 .word 0xfffff5dc
 *   @0x1ff91c .word 0xfffff5e0
 *   @0x1ff920 andseq r4, r5, r8, lsl #4
 *   @0x1ff924 .word 0xfffff5e4
 *   @0x1ff928 .word 0xfffff5e8
 *   @0x1ff92c ldrsheq r4, [r5], -r4
 *   @0x1ff930 .word 0xfffff5ec
 *   @0x1ff934 .word 0xfffff5f0
 *   @0x1ff938 andseq r4, r5, r0, ror #3
 *   @0x1ff93c .word 0xfffff5f4
 *   @0x1ff940 .word 0xfffff5f8
 *   @0x1ff944 andseq r4, r5, r12, asr #3
 *   @0x1ff948 .word 0xfffff5fc
 *   @0x1ff94c .word 0xfffff600
 *   @0x1ff950 ldrheq r4, [r5], -r8
 *   @0x1ff954 .word 0xfffff604
 *   @0x1ff958 andseq r4, r5, r8, lsr #3
 *   @0x1ff95c .word 0xfffff608
 *   @0x1ff960 .word 0xfffff60c
 *   @0x1ff964 mulseq r5, r4, r1
 *   @0x1ff968 .word 0xfffff610
 *   @0x1ff96c .word 0xfffff614
 *   @0x1ff970 andseq r4, r5, r4, lsl #3
 *   @0x1ff974 .word 0xfffff618
 *   @0x1ff978 .word 0xfffff61c
 *   @0x1ff97c andseq r4, r5, r12, ror r1
 *   @0x1ff980 .word 0xfffff620
 *   @0x1ff984 .word 0xfffff624
 *   @0x1ff988 andseq r4, r5, r8, ror #2
 *   @0x1ff98c .word 0xfffff628
 *   @0x1ff990 .word 0xfffff62c
 *   @0x1ff994 andseq r4, r5, r4, asr r1
 *   @0x1ff998 .word 0xfffff630
 *   @0x1ff99c .word 0xfffff634
 *   @0x1ff9a0 andseq r4, r5, r8, asr #2
 *   @0x1ff9a4 .word 0xfffff638
 *   @0x1ff9a8 .word 0xfffff63c
 *   @0x1ff9ac andseq r4, r5, r8, lsr r1
 *   @0x1ff9b0 .word 0xfffff640
 *   @0x1ff9b4 .word 0xfffff644
 *   @0x1ff9b8 andseq r4, r5, r8, lsr #2
 *   @0x1ff9bc .word 0xfffff648
 *   @0x1ff9c0 .word 0xfffff64c
 *   @0x1ff9c4 andseq r4, r5, r12, lsl r1
 *   @0x1ff9c8 .word 0xfffff650
 *   @0x1ff9cc .word 0xfffff654
 *   @0x1ff9d0 andseq r4, r5, r12, lsl #2
 *   @0x1ff9d4 .word 0xfffff658
 *   @0x1ff9d8 .word 0xfffff65c
 *   @0x1ff9dc andseq r4, r5, r0, lsl #2
 *   @0x1ff9e0 .word 0xfffff660
 *   @0x1ff9e4 ldrsheq r4, [r5], -r4
 *   @0x1ff9e8 .word 0xfffff664
 *   @0x1ff9ec andseq r4, r5, r4, ror #1
 *   @0x1ff9f0 .word 0xfffff668
 *   @0x1ff9f4 ldrsbeq r4, [r5], -r4
 *   @0x1ff9f8 .word 0xfffff66c
 *   @0x1ff9fc .word 0xfffff670
 *   @0x1ffa00 andseq r4, r5, r0, asr #1
 *   @0x1ffa04 .word 0xfffff674
 *   @0x1ffa08 .word 0xfffff678
 *   @0x1ffa0c ldrheq r4, [r5], -r0
 *   @0x1ffa10 .word 0xfffff67c
 *   @0x1ffa14 .word 0xfffff680
 *   @0x1ffa18 andseq r4, r5, r0, lsr #1
 *   @0x1ffa1c .word 0xfffff684
 *   @0x1ffa20 .word 0xfffff688
 *   @0x1ffa24 mulseq r5, r0, r0
 *   @0x1ffa28 .word 0xfffff68c
 *   @0x1ffa2c .word 0xfffff690
 *   @0x1ffa30 andseq r4, r5, r8, lsl #1
 *   @0x1ffa34 .word 0xfffff694
 *   @0x1ffa38 .word 0xfffff698
 *   @0x1ffa3c andseq r4, r5, r0, lsl #1
 *   @0x1ffa40 .word 0xfffff69c
 *   @0x1ffa44 .word 0xfffff6a0
 *   @0x1ffa48 andseq r4, r5, r8, ror r0
 *   @0x1ffa4c .word 0xfffff6a4
 *   @0x1ffa50 .word 0xfffff6a8
 *   @0x1ffa54 andseq r4, r5, r4, rrx
 *   @0x1ffa58 .word 0xfffff6ac
 *   @0x1ffa5c .word 0xfffff6b0
 *   @0x1ffa60 andseq r4, r5, r0, asr r0
 *   @0x1ffa64 .word 0xfffff6b4
 *   @0x1ffa68 .word 0xfffff6b8
 *   @0x1ffa6c andseq r4, r5, r4, asr #32
 *   @0x1ffa70 .word 0xfffff6bc
 *   @0x1ffa74 .word 0xfffff6c0
 *   @0x1ffa78 andseq r4, r5, r8, lsr r0
 *   @0x1ffa7c .word 0xfffff6c4
 *   @0x1ffa80 .word 0xfffff6c8
 *   @0x1ffa84 andseq r4, r5, r4, lsr #32
 *   @0x1ffa88 .word 0xfffff6cc
 *   @0x1ffa8c .word 0xfffff6d0
 *   @0x1ffa90 andseq r4, r5, r8, lsl r0
 *   @0x1ffa94 .word 0xfffff6d4
 *   @0x1ffa98 andseq r4, r5, r8
 *   @0x1ffa9c .word 0xfffff6d8
 *   @0x1ffaa0 ldrsheq r3, [r5], -r8
 *   @0x1ffaa4 .word 0xfffff6dc
 *   @0x1ffaa8 andseq r3, r5, r8, ror #31
 *   @0x1ffaac .word 0xfffff6e0
 *   @0x1ffab0 ldrsbeq r3, [r5], -r8
 *   @0x1ffab4 .word 0xfffff6e4
 *   @0x1ffab8 andseq r3, r5, r8, asr #31
 *   @0x1ffabc .word 0xfffff6e8
 *   @0x1ffac0 ldrheq r3, [r5], -r8
 *   @0x1ffac4 .word 0xfffff6ec
 *   @0x1ffac8 andseq r3, r5, r8, lsr #31
 *   @0x1ffacc .word 0xfffff6f0
 *   @0x1ffad0 mulseq r5, r12, pc
 *   @0x1ffad4 .word 0xfffff6f4
 *   @0x1ffad8 mulseq r5, r0, pc
 *   @0x1ffadc .word 0xfffff6f8
 *   @0x1ffae0 andseq r3, r5, r12, lsl #31
 *   @0x1ffae4 .word 0xfffff6fc
 *   @0x1ffae8 andseq r3, r5, r8, lsl #31
 *   @0x1ffaec .word 0xfffff700
 *   @0x1ffaf0 andseq r3, r5, r4, lsl #31
 *   @0x1ffaf4 .word 0xfffff704
 *   @0x1ffaf8 andseq r3, r5, r8, ror pc
 *   @0x1ffafc .word 0xfffff708
 *   @0x1ffb00 andseq r3, r5, r12, ror #30
 *   @0x1ffb04 .word 0xfffff70c
 *   @0x1ffb08 andseq r3, r5, r4, ror #30
 *   @0x1ffb0c .word 0xfffff710
 *   @0x1ffb10 andseq r3, r5, r12, asr pc
 *   @0x1ffb14 .word 0xfffff714
 *   @0x1ffb18 andseq r3, r5, r12, asr #30
 *   @0x1ffb1c .word 0xfffff718
 *   @0x1ffb20 andseq r3, r5, r12, lsr pc
 *   @0x1ffb24 .word 0xfffff71c
 *   @0x1ffb28 .word 0xfffff720
 *   @0x1ffb2c andseq r3, r5, r12, lsr #30
 *
 * ══ §7/13 anon_302064  0x302064  size 3540  885 条（0x302064..0x302e38）
 * @func 0x302064 0x302e38  size 3540  885 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x542d60 / 0x31c438 / 0x1420274 / 0x2220288 / 0x19ce2f8 / 0x3fd03c / 0x38a1ec / 0xfebaed78
 * 字段偏移 top8: 0x8×2 / 0x1×1 / 0x6×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x302064 andle r2, r5, r12, lsr r9
 *   @0x302068 andle r2, r3, r11, asr r10
 *   @0x30206c andle r2, r1, sp, asr r10
 *   @0x302070 tstle r0, r5, lsr #22
 *   @0x302074 stmdbls r7, {r3, r5, r9, r10, lr}
 *   @0x302078 .word 0xf5b4220d
 *   @0x30207c ldmdblt r0, {r1, r4, r5, r7, r9, r11, sp, lr, pc} ^
 *   @0x302080 ldrsblo pc, [r8, #-132]!
 *   @0x302084 eorvs r3, r5, sp, lsl #10
 *   @0x302088 svclt #0x4407da
 *   @0x30208c movweq pc, #0x2043
 *   @0x302090 cmnlo r8, r4, asr #17
 *   @0x302094 .word 0xf1aae0f8
 *   @0x302098 blhs 0x542d60 <g_DecodeStringBuffer+0x2ec>
 *   @0x30209c bvs 0xbf80c8 <b2_toiTime+0x49ec24>
 *   @0x3020a0 ldrmi r4, [r8, r0, lsr #12]
 *   @0x3020a4 blhs 0x31c438
 *   @0x3020a8 strls sp, [r3, #-0x195]
 *   @0x3020ac stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x3020b0 .word 0xf1bae0ea
 *   @0x3020b4 qaddle r0, r2, r6
 *   @0x3020b8 addsmi r1, pc, #10944
 *   @0x3020bc sbcshi pc, r11, r0, asr #4
 *   @0x3020c0 blhs 0x1420274 <b2_toiTime+0xcc6dd0>
 *   @0x3020c4 .word 0xf1bae008
 *   @0x3020c8 tstle r11, sp, lsr #30
 *   @0x3020cc addsmi r1, pc, #10944
 *   @0x3020d0 sbcshi pc, r1, r0, asr #4
 *   @0x3020d4 blhs 0x2220288 <b2_toiTime+0x1ac6de4>
 *   @0x3020d8 sbchi pc, sp, r0, asr #32
 *   @0x3020dc svceq #0xf1b8
 *   @0x3020e0 sbchi pc, r9, r0
 *   @0x3020e4 strtmi r9, [r0], -r3, lsl #26
 *   @0x3020e8 bge 0x56c510 <g_SWFlineaavertbuff+0x19448>
 *   @0x3020ec .word 0xf8d66025
 *   @0x3020f0 blvs 0x19ce2f8 <b2_toiTime+0x1274e54>
 *   @0x3020f4 svclt #0x183300
 *   @0x3020f8 .word 0xf7fe2301
 *   @0x3020fc ldmiblt r8, {r0, r1, r2, r6, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x302100 sbc r2, r5, r3
 *   @0x302104 svceq #0x2ff1ba
 *   @0x302108 adcshi pc, r5, r0, asr #32
 *   @0x30210c addsmi r1, pc, #43776
 *   @0x302110 adcshi pc, r1, r0, asr #4
 *   @0x302114 strtmi r1, [r0], -r11, ror #24
 *   @0x302118 eorvs r9, r3, r4, lsl #6
 *   @0x30211c ldrmi r6, [r8, r3, lsr #20]
 *   @0x302120 stmdbhs r0, {r0, r5, r6, r7, r11, sp, lr}
 *   @0x302124 svcge #0x57f47f
 *   @0x302128 stmdavs r3!, {r2, r9, r11, r12, pc}
 *   @0x30212c bleq 0x3fd03c <g_RomDisk+0x581c>
 *   @0x302130 rscslo pc, pc, #-1073741822
 *   @0x302134 stmdble r2, {r2, r4, r9, r11, sp}
 *   @0x302138 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30213c adcsmi lr, r11, #164
 *   @0x302140 .word 0xf8ddd2fa
 *   @0x302144 .word 0xf10cc014
 *   @0x302148 .word 0xf8590924
 *   @0x30214c .word 0xf1a98c24
 *   @0x302150 .word 0xf1b80a24
 *   @0x302154 .word 0xf0000f00
 *   @0x302158 stmdavc r9!, {r0, r1, r2, r4, r7, pc} ^
 *   @0x30215c mulhs r0, r8, r8
 *   @0x302160 .word 0xf0404291
 *   @0x302164 strbmi r8, [r0], -r5, lsl #1
 *   @0x302168 stmib r6!, {r2, r4, r5, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x30216c cmnle pc, r3, lsl #11
 *   @0x302170 stmdals r4, {r1, r3, r4, r6, r9, r10, lr}
 *   @0x302174 .word 0xf5b44641
 *   @0x302178 strmi lr, [r2], -r4, ror #26
 *   @0x30217c cmnle r7, r0, lsl #16
 *   @0x302180 ldrsbne pc, [r8, #-132]!
 *   @0x302184 .word 0x3020f8da
 *   @0x302188 svceq #0x1f011
 *   @0x30218c andhs r11, r1, r12, lsl #30
 *   @0x302190 andmi r2, r3, r2
 *   @0x302194 .word 0x078bd0d0
 *   @0x302198 strbmi sp, [r0], -r6, lsl #10
 *   @0x30219c andls r9, r2, #98304
 *   @0x3021a0 stmib r8!, {r2, r4, r5, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x3021a4 bicle r2, r7, r0, lsl #16
 *   @0x3021a8 andseq pc, r4, #14024704
 *   @0x3021ac stmdavs r3, {r3, r5, r8, r12, sp, pc}
 *   @0x3021b0 svclt #0x142b00
 *   @0x3021b4 movwhs r4, #0x603
 *   @0x3021b8 strmi lr, [r3], -r0
 *   @0x3021bc .word 0x1008f8da
 *   @0x3021c0 .word 0xd106290b
 *   @0x3021c4 .word 0xf8da4630
 *   @0x3021c8 strtmi r3, [r1], -r12
 *   @0x3021cc stmvs r0!, {r3, r4, r7, r8, r9, r10, lr} ^
 *   @0x3021d0 .word 0xf8dae046
 *   @0x3021d4 blo 0x38a1ec <bigtens_D2A+0x6bc>
 *   @0x3021d8 stmdale pc!, {r1, r2, r9, r11, sp}
 *   @0x3021dc .word 0xf002e8df
 *   @0x3021e0 ldmdbne r1, {r1, r2, r3, r10}
 *   @0x3021e4 eoreq r2, r10, r2, lsr #12
 *   @0x3021e8 addeq pc, r4, #-2147483647
 *   @0x3021ec ldmdblt r3, {r0, r3, r9, r12, pc}
 *   @0x3021f0 bge 0x54adf8 <gp_ActiveMaskObjects+0x6130>
 *   @0x3021f4 .word 0xf103e028
 *   @0x3021f8 muls r1, r0, r2
 *   @0x3021fc .word 0x03a4f106
 *   @0x302200 .word 0xf106e01e
 *   @0x302204 andls r0, r9, #168, #4
 *   @0x302208 rscsle r2, r1, r0, lsl #22
 *   @0x30220c sbcseq pc, r4, #-1073741824
 *   @0x302210 .word 0xf506e006
 *   @0x302214 andls r7, r9, #232, #4
 *   @0x302218 rscle r2, r9, r0, lsl #22
 *   @0x30221c addvc pc, lr, #12582912
 *   @0x302220 ands r6, r1, r11, lsl r8
 *   @0x302224 .word 0xf842aa0a
 *   @0x302228 and r4, r12, r4, lsl #26
 *   @0x30222c .word 0xf842aa0a
 *   @0x302230 and r6, r8, r4, lsl #26
 *   @0x302234 .word 0xf842aa0a
 *   @0x302238 and r0, r4, r4, lsl #26
 *   @0x30223c orreq pc, r4, #-2147483647
 *   @0x302240 .word 0xf842aa0a
 *   @0x302244 movwhs r3, #0xd04
 *   @0x302248 strhs r6, [r0, #-0x810]
 *   @0x30224c stmdblo r9, {r6, r8, r12, sp, pc}
 *   @0x302250 stmdbhs r1, {r8, r10, r12, pc}
 *   @0x302254 ldrbmi r4, [r1], -r0, lsr #12
 *   @0x302258 stclvs p15, c11, [r5], #-592
 *   @0x30225c strmi r6, [r8, r5, lsr #24]!
 *   @0x302260 orrlt r6, r0, r0, ror #1
 *   @0x302264 blhs 0xfebaed78 <b2_toiTime+0xfffffffffe4558d4>
 *   @0x302268 movwhs sp, #0x112
 *   @0x30226c strb r6, [r3, -r3, ror #1]!
 *   @0x302270 stmdbeq r4!, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x302274 bvs 0xbfc020 <b2_toiTime+0x4a2b7c>
 *   @0x302278 ldrmi r4, [r8, r0, lsr #12]
 *   @0x30227c blhs 0x31c610
 *   @0x302280 svcge #0x5af43f
 *   @0x302284 strmi lr, [r0], r7, lsr #13
 *   @0x302288 strtmi r6, [r0], -r3, ror #19
 *   @0x30228c uhadd8 r4, r1, r8
 *   @0x302290 pop {r0, r1, r3, r12, sp, pc}
 *   @0x302294 svclt #0x8ff0
 *   @0x302298 muleq lr, r8, r2
 *   @0x30229c andeq r12, r8, r0, lsl #26
 *   @0x3022a0 andeq r12, r8, r12, ror #25
 *   @0x3022a4 andeq r12, r8, r0, lsl #25
 *   @0x3022a8 andeq r12, r8, r10, lsr #24
 *   @0x3022ac mvnsmi lr, sp, lsr #18
 *   @0x3022b0 movwhs r10, #0xf01
 *   @0x3022b4 andhi r4, r11, r12, lsl #12
 *   @0x3022b8 andsvs r4, r3, r9, lsr r6
 *   @0x3022bc ldrmi r4, [r5], -r0, lsl #13
 *   @0x3022c0 stc2 p7, c15, [r0], #-912
 *   @0x3022c4 strmi r9, [r6], -r1, lsl #22
 *   @0x3022c8 .word 0xf500b96b
 *   @0x3022cc cmnlo pc, #-67108861
 *   @0x3022d0 blhs 0x36ed44 <_ZTS13C_UTF16String+0x5df0>
 *   @0x3022d4 strbmi sp, [r0], -r6, lsl #16
 *   @0x3022d8 .word 0xf7e44639
 *   @0x3022dc blls 0x381af8 <_ZTS13C_UTF16String+0x18ba4>
 *   @0x3022e0 eorvs r11, r8, r3, lsl #18
 *   @0x3022e4 stmdals r1, {r1, r2, r5, pc}
 *   @0x3022e8 pop {r1, r12, sp, pc}
 *   @0x3022ec push {r4, r5, r6, r7, r8, pc}
 *   @0x3022f0 ldrshlt r4, [r1], r0
 *   @0x3022f4 ldmdaeq r0, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x3022f8 strhs r4, [r0, -lr, lsl #12]
 *   @0x3022fc strmi r2, [r5], -r4, lsl #4
 *   @0x302300 strmi r9, [r8], -r3, lsl #14
 *   @0x302304 strbmi r10, [r1], -r2, lsl #22
 *   @0x302308 .word 0x47a06bf4
 *   @0x30230c adcsmi r9, r10, #8192
 *   @0x302310 .word 0x23a2da01
 *   @0x302314 andle lr, r1, r3
 *   @0x302318 vstrle s4, [r2, #-16]
 *   @0x30231c movwls r2, #0x3303
 *   @0x302320 qasxmi lr, r8, r8
 *   @0x302324 .word 0xf7fe4639
 *   @0x302328 strhls pc, [r3], -r9
 *   @0x30232c teqle r1, r0, lsl #16
 *   @0x302330 .word 0x9064f8d5
 *   @0x302334 beq 0x63e770 <g_SWFaavertbuff+0x6b6a8>
 *   @0x302338 andspl pc, r4, #13959168
 *   @0x30233c strmi r4, [r7], -r4, asr #12
 *   @0x302340 addsmi r9, pc, #2048
 *   @0x302344 stmdavs r3!, {r1, r2, r5, r9, r11, r12, lr, pc}
 *   @0x302348 bhs 0xee03b8 <b2_toiTime+0x786f14>
 *   @0x30234c svclt #0x46862
 *   @0x302350 eorvs r3, r3, r1, lsl #6
 *   @0x302354 bl 0xfef9c3e8 <b2_toiTime+0xfffffffffe842f44>
 *   @0x302358 sbcsle r0, pc, r3, lsl #16
 *   @0x30235c tstlt r1, r9, lsr #17
 *   @0x302360 .word 0xf7e44648
 *   @0x302364 strbmi pc, [r8], -r8, ror #31
 *   @0x302368 mrseq pc, apsr
 *   @0x30236c strlo r4, [r12], #-1618
 *   @0x302370 cdp2 p7, #0xd, c15, c9, c4, #0x7
 *   @0x302374 rsbvs r3, r8, r4, lsl #10
 *   @0x302378 blls 0x3d3d8c <error_g0017+0x2ca30>
 *   @0x30237c .word 0xf854b953
 *   @0x302380 strbmi r1, [r2], -r12, lsl #24
 *   @0x302384 .word 0xf5b49301
 *   @0x302388 blls 0x37c7f8 <_ZTS13C_UTF16String+0x138a4>
 *   @0x30238c .word 0xf80b3701
 *   @0x302390 ldrb r3, [r5, r8]
 *   @0x302394 rscsvs r9, r3, r3, lsl #22
 *   @0x302398 pop {r0, r4, r12, sp, pc}
 *   @0x30239c strdeq r8, r9, [r0], -r0
 *   @0x3023a0 svcmi #0xf0e92d
 *   @0x3023a4 stmdbvs lr, {r0, r1, r2, r3, r7, r12, sp, pc}
 *   @0x3023a8 andls r4, r5, pc, lsl #12
 *   @0x3023ac strls r6, [r3], -r11, asr #20
 *   @0x3023b0 .word 0x61ecf8d0
 *   @0x3023b4 stmdavs r12, {r3, r9, r10, lr}
 *   @0x3023b8 stmvs lr, {r9, r10, r12, pc}
 *   @0x3023bc ldrmi r9, [r8, r4, lsl #12]
 *   @0x3023c0 vmlal.s8 q9, d0, d0
 *   @0x3023c4 cdpls p1, #0x0, c8, c4, c0, #0x1
 *   @0x3023c8 rscne r1, r4, r4, lsr r11
 *   @0x3023cc svclt #0xa842a0
 *   @0x3023d0 andls r4, r6, r0, lsr #12
 *   @0x3023d4 .word 0xf0002800
 *   @0x3023d8 ldmvs r11!, {r0, r2, r4, r5, r6, r7, r8, pc} ^
 *   @0x3023dc .word 0xf0402b00
 *   @0x3023e0 .word 0xf8d781f1
 *   @0x3023e4 .word 0xf1073098
 *   @0x3023e8 .word 0xf10706d0
 *   @0x3023ec .word 0x96020a9c
 *   @0x3023f0 stmvc r2, {r0, r1, r2, r8, r10, r12, sp, lr, pc}
 *   @0x3023f4 mcrge p1, #0x0, r11, c11, c3, #0x2
 *   @0x3023f8 cdpge p6, #0x0, c9, c12, c7, #0x0
 *   @0x3023fc cdpmi p6, #0xf, c9, c3, c8, #0x0
 *   @0x302400 strtmi r2, [r9], r0, lsl #10
 *   @0x302404 ldrbtmi r4, [lr], #-1580
 *   @0x302408 eors r9, r5, r9, lsl #12
 *   @0x30240c stmdals r2, {r1, r2, r9, r10, r11, r12, pc}
 *   @0x302410 mcrls p13, #0x0, r1, c0, c4, #0x5
 *   @0x302414 strtmi r9, [r1], -r3, lsl #20
 *   @0x302418 ldmdavs r11, {r0, r1, r4, r5, r11, sp, lr}
 *   @0x30241c mulls r10, r8, r7
 *   @0x302420 .word 0xf0402800
 *   @0x302424 ldmdavs r3!, {r0, r2, r3, r6, r7, r8, pc}
 *   @0x302428 qsaxmi r4, r1, r0
 *   @0x30242c ldmdavs r11, {r0, r1, r9, r11, r12, pc}
 *   @0x302430 mulls r10, r8, r7
 *   @0x302434 .word 0xf0402800
 *   @0x302438 ldmdavs r3!, {r0, r1, r6, r7, r8, pc}
 *   @0x30243c .word 0x21044640
 *   @0x302440 ldmdavs r11, {r0, r1, r9, r11, r12, pc}
 *   @0x302444 mulls r10, r8, r7
 *   @0x302448 sbcsle r2, r4, r0, lsl #16
 *   @0x30244c .word 0xf10be1b8
 *   @0x302450 addsmi r0, lr, #201326592
 *   @0x302454 bvs 0x11f84c0 <b2_toiTime+0xa9f01c>
 *   @0x302458 .word 0x47984638
 *   @0x30245c .word 0xc000f8d7
 *   @0x302460 ldrmi r9, [r4, #0xe04]!
 *   @0x302464 sbchi pc, pc, r0, lsl #1
 *   @0x302468 blhs 0x31c85c
 *   @0x30246c .word 0x81aaf040
 *   @0x302470 mullo r0, r11, r8
 *   @0x302474 eorsle r2, pc, pc, lsr #22
 *   @0x302478 shsub8mi r6, r8, r11
 *   @0x30247c .word 0xf8d74798
 *   @0x302480 cdpls p0, #0x0, c11, c4, c0, #0x0
 *   @0x302484 .word 0xd3e245b3
 *   @0x302488 .word 0xf89be0bc
 *   @0x30248c .word 0xf1a33003
 *   @0x302490 bhs 0x342cbc
 *   @0x302494 .word 0xf1a3d916
 *   @0x302498 bhs 0x342cd0
 *   @0x30249c .word 0xf013d912
 *   @0x3024a0 ldrdle r0, r1, [pc], -pc
 *   @0x3024a4 andle r2, sp, pc, lsr #22
 *   @0x3024a8 smulwbeq r8, r3, r1
 *   @0x3024ac stmdble r9, {r0, r8, r11, sp}
 *   @0x3024b0 mvnseq pc, r3
 *   @0x3024b4 andle r2, r5, r12, lsr r9
 *   @0x3024b8 andle r2, r3, r11, asr r10
 *   @0x3024bc andle r2, r1, sp, asr r10
 *   @0x3024c0 bicle r2, r8, r5, lsr #22
 *   @0x3024c4 mullo r0, r11, r8
 *   @0x3024c8 .word 0xd10a2b64
 *   @0x3024cc mullo r1, r11, r8
 *   @0x3024d0 bicle r2, r0, r5, ror #22
 *   @0x3024d4 mullo r2, r11, r8
 *   @0x3024d8 .word 0xd1bc2b66
 *   @0x3024dc adcsle r2, r10, r0, lsl #24
 *   @0x3024e0 blhs 0x1c7a738 <b2_toiTime+0x1521294>
 *   @0x3024e4 .word 0xf89bd1b7
 *   @0x3024e8 blhs 0x1e8e4f4 <b2_toiTime+0x1735050>
 *   @0x3024ec .word 0xf89bd1b3
 *   @0x3024f0 blhs 0x1c0e500 <b2_toiTime+0x14b505c>
 *   @0x3024f4 add sp, r5, pc, lsr #3
 *   @0x3024f8 .word 0xf10b9e04
 *   @0x3024fc addsmi r0, lr, #134217728
 *   @0x302500 addhi pc, r1, r0, asr #4
 *   @0x302504 ldrtmi r9, [r8], -r5, lsl #28
 *   @0x302508 bge 0x62c93c <g_SWFaavertbuff+0x59874>
 *   @0x30250c .word 0x3080f8d6
 *   @0x302510 .word 0xf8cd6b5b
 *   @0x302514 movwlo r12, #0x4
 *   @0x302518 movwhs r11, #0x1f18
 *   @0x30251c ldc2 p7, c15, [r6], #-1016
 *   @0x302520 .word 0xc004f8dd
 *   @0x302524 .word 0xf0002800
 *   @0x302528 .word 0xf8d7814d
 *   @0x30252c blhs 0x30e794 <af_shaper_get_elem+0x4002>
 *   @0x302530 .word 0xf10bd1a2
 *   @0x302534 ldrbmi r0, [r0], -r1, lsl #4
 *   @0x302538 .word 0x0c0cebc2
 *   @0x30253c andgt pc, r4, sp, asr #17
 *   @0x302540 movweq pc, #0x110c
 *   @0x302544 .word 0xf8d74621
 *   @0x302548 ldrmi r6, [r0, r8, asr #1]!
 *   @0x30254c .word 0xc004f8dd
 *   @0x302550 stmdahs r0, {r1, r3, r12, pc}
 *   @0x302554 teqhi r4, r0, asr #32
 *   @0x302558 ldrsbtlo pc, [r4], r7
 *   @0x30255c eorlo pc, r4, r3, asr r8
 *   @0x302560 andeq pc, r12, r3, lsl #16
 *   @0x302564 mullo r1, r11, r8
 *   @0x302568 .word 0xd10b2b2e
 *   @0x30256c ldrsbtlo pc, [r4], r7
 *   @0x302570 .word 0xf8539809
 *   @0x302574 .word 0xf5b31024
 *   @0x302578 stmdahs r0, {r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr, pc}
 *   @0x30257c strtmi r11, [r1], r8, lsl #30
 *   @0x302580 strhs r11, [r1, #-0xf08]
 *   @0x302584 .word 0xf8d69e05
 *   @0x302588 blhs 0x30e840 <af_shaper_get_elem+0x40ae>
 *   @0x30258c vmlals.f64 d13, d6, d28
 *   @0x302590 adcmi r1, r2, #3200
 *   @0x302594 stmdbls r11, {r3, r5, r8, r9, r11, r12, lr, pc}
 *   @0x302598 ldmdble r4!, {r0, r3, r4, r7, r9, lr}
 *   @0x30259c bge 0x5a85b0 <g_SWFlineaavertbuff+0x554e8>
 *   @0x3025a0 stc2l p7, c15, [r1, #912]
 *   @0x3025a4 strmi r9, [r3], r10, lsl #22
 *   @0x3025a8 .word 0xf0402b00
 *   @0x3025ac stmdbls r12, {r0, r3, r8, pc}
 *   @0x3025b0 .word 0xf5b49a0b
 *   @0x3025b4 cdpls p8, #0x0, c14, c0, c4, #0x0
 *   @0x3025b8 stmdbls r11, {r3, r4, r6, r9, r10, lr}
 *   @0x3025bc rsceq pc, r10, #268435460
 *   @0x3025c0 .word 0x47986933
 *   @0x3025c4 blls 0x5e9de0 <g_SWFaavertbuff+0x16d18>
 *   @0x3025c8 stmdals r2, {r0, r5, r9, r10, lr}
 *   @0x3025cc .word 0x20acf8d6
 *   @0x3025d0 ldrsbtvs pc, [r12], #135
 *   @0x3025d4 ldrbmi r1, [r10], #-2715
 *   @0x3025d8 ldrmi r9, [r0, r11, lsl #6]!
 *   @0x3025dc andls r4, r10, r9, asr r6
 *   @0x3025e0 .word 0xf7e49803
 *   @0x3025e4 and pc, r7, r8, lsr #29
 *   @0x3025e8 strtmi r9, [r1], -r2, lsl #16
 *   @0x3025ec blls 0x5e8e24 <g_SWFaavertbuff+0x15d5c>
 *   @0x3025f0 ldrsbtvs pc, [r12], #135
 *   @0x3025f4 strhls r4, [r10], -r0
 *   @0x3025f8 blhs 0x329228
 *   @0x3025fc rschi pc, r0, r0, asr #32
 *   @0x302600 ldr r3, [r9, -r1, lsl #8]!
 *   @0x302604 movwhs r11, #0x3914
 *   @0x302608 sbcs r9, r9, r10, lsl #6
 *   @0x30260c addsmi pc, r8, r7, asr #17
 *   @0x302610 ldrsbths pc, [r4], r7
 *   @0x302614 rsbsle r2, pc, r0, lsl #26
 *   @0x302618 stmdami sp!, {r0, r2, r4, r11, sp, lr} ^
 *   @0x30261c ldrbtmi r4, [r8], #-1577
 *   @0x302620 svc #0xa8f5b3
 *   @0x302624 .word 0xf0002800
 *   @0x302628 .word 0xf8d780cd
 *   @0x30262c .word 0x464030b8
 *   @0x302630 ldrsbmi pc, [r0, -r7]!
 *   @0x302634 strtmi r2, [r10], -r0, lsl #2
 *   @0x302638 .word 0x47a0681b
 *   @0x30263c stmdahs r0, {r1, r3, r12, pc}
 *   @0x302640 adcshi pc, lr, r0, asr #32
 *   @0x302644 .word 0x20e8f8d7
 *   @0x302648 .word 0xf8d74640
 *   @0x30264c smlatths r1, r12, r0, r3
 *   @0x302650 ldrsbmi pc, [r0, -r7]!
 *   @0x302654 ldmdavs r11, {r1, r4, r11, sp, lr}
 *   @0x302658 andls r4, r10, r0, lsr #15
 *   @0x30265c .word 0xf0402800
 *   @0x302660 .word 0xf8d780af
 *   @0x302664 .word 0x464020b4
 *   @0x302668 ldrsbtlo pc, [r8], r7
 *   @0x30266c .word 0xf8d72102
 *   @0x302670 .word 0xf8524130
 *   @0x302674 .word 0xf8532029
 *   @0x302678 strmi r3, [r0, r9, lsr #32]!
 *   @0x30267c stmdahs r0, {r1, r3, r12, pc}
 *   @0x302680 addshi pc, lr, r0, asr #32
 *   @0x302684 .word 0x20e8f8d7
 *   @0x302688 .word 0xf8d74640
 *   @0x30268c smlatths r3, r12, r0, r3
 *   @0x302690 ldrsbmi pc, [r0, -r7]!
 *   @0x302694 eorhs pc, r9, r2, asr r8
 *   @0x302698 eorlo pc, r9, r3, asr r8
 *   @0x30269c andls r4, r10, r0, lsr #15
 *   @0x3026a0 .word 0xf0402800
 *   @0x3026a4 .word 0xf8d7808d
 *   @0x3026a8 uadd16mi r2, r0, r12
 *   @0x3026ac .word 0x3120f8d7
 *   @0x3026b0 .word 0xf8d74649
 *   @0x3026b4 ldmdavs r2, {r3, r6, r7, lr}
 *   @0x3026b8 .word 0x47a0681b
 *   @0x3026bc stmdahs r0, {r1, r3, r12, pc}
 *   @0x3026c0 .word 0xf8d7d17e
 *   @0x3026c4 .word 0x4649211c
 *   @0x3026c8 .word 0x3120f8d7
 *   @0x3026cc ldrsbtmi pc, [r12], #135
 *   @0x3026d0 ldmdavs r2, {r1, r11, r12, pc} ^
 *   @0x3026d4 sbfxmi r6, r11, #0x10, #0x1
 *   @0x3026d8 andls r4, r10, r1, lsl #12
 *   @0x3026dc .word 0xd16f2800
 *   @0x3026e0 ldrsbhs pc, [r12, -r7]
 *   @0x3026e4 .word 0xf8d74650
 *   @0x3026e8 .word 0xf8d73120
 *   @0x3026ec ldmvs r2, {r3, r6, r7, lr}
 *   @0x3026f0 .word 0x47a0689b
 *   @0x3026f4 andls r4, r10, r1, lsl #12
 *   @0x3026f8 .word 0xd1612800
 *   @0x3026fc ldrsbhs pc, [r12, -r7]
 *   @0x302700 .word 0x3120f8d7
 *   @0x302704 ldrsbtmi pc, [r12], #135
 *   @0x302708 ldmvs r2, {r1, r11, r12, pc} ^
 *   @0x30270c sbfxmi r6, r11, #0x11, #0x1
 *   @0x302710 stmdahs r0, {r1, r3, r12, pc}
 *   @0x302714 subs sp, r3, r6, asr r0
 *   @0x302718 strtmi r4, [r9], -lr, lsr #22
 *   @0x30271c ldrsbvs pc, [r0, -r7]!
 *   @0x302720 ldmdavs r8, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x302724 andls r7, r12, r11, lsl r9
 *   @0x302728 .word 0xf88d4640
 *   @0x30272c .word 0xf8d73034
 *   @0x302730 ldmdavs r2, {r3, r4, r5, r7, r12, sp}
 *   @0x302734 .word 0x47b0681b
 *   @0x302738 stmdahs r0, {r1, r3, r12, pc}
 *   @0x30273c .word 0xf8d7d140
 *   @0x302740 strbmi r2, [r0], -r8, ror #1
 *   @0x302744 .word 0x30ecf8d7
 *   @0x302748 .word 0xf8d72101
 *   @0x30274c ldmdavs r2, {r4, r5, r8, sp, lr}
 *   @0x302750 .word 0x47b0681b
 *   @0x302754 stmdahs r0, {r1, r3, r12, pc}
 *   @0x302758 bmi 0xaf6c28 <b2_toiTime+0x39d784>
 *   @0x30275c .word 0xf8d74650
 *   @0x302760 strtmi r6, [r9], -r8, asr #1
 *   @0x302764 movwhs r4, #0x847a
 *   @0x302768 strhls r4, [r10], -r0
 *   @0x30276c .word 0xf8d7bb40
 *   @0x302770 qsub8mi r6, r9, r12
 *   @0x302774 bge 0x628784 <g_SWFaavertbuff+0x556bc>
 *   @0x302778 ldrmi r2, [r0, r5, lsl #6]!
 *   @0x30277c ldmiblt r8!, {r1, r3, r12, pc} ^
 *   @0x302780 ldrsbhs pc, [r12, -r7]
 *   @0x302784 .word 0xf8d74650
 *   @0x302788 strtmi r3, [r1], -r0, lsr #2
 *   @0x30278c .word 0x50c8f8d7
 *   @0x302790 ldmdavs r11, {r1, r4, r11, sp, lr}
 *   @0x302794 andls r4, r10, r8, lsr #15
 *   @0x302798 .word 0xf8d7b990
 *   @0x30279c qadd16mi r2, r1, r12
 *   @0x3027a0 .word 0x3120f8d7
 *   @0x3027a4 ldrsbtpl pc, [r12], #135
 *   @0x3027a8 ldmdavs r2, {r1, r11, r12, pc} ^
 *   @0x3027ac sbfxmi r6, r11, #0x10, #0x9
 *   @0x3027b0 stmdblt r8!, {r1, r3, r12, pc}
 *   @0x3027b4 ldrsblo pc, [r8], r7
 *   @0x3027b8 .word 0xf8c73301
 *   @0x3027bc mul r1, r8, r0
 *   @0x3027c0 rscsvs r9, r11, r10, lsl #22
 *   @0x3027c4 pop {r0, r1, r2, r3, r12, sp, pc}
 *   @0x3027c8 svclt #0x8ff0
 *   @0x3027cc strdeq r12, sp, [r8], -r11
 *   @0x3027d0 andeq r12, r8, r3, ror #11
 *   @0x3027d4 ldrdeq sp, lr, [r9], -r0
 *   @0x3027d8 muleq r8, sp, r4
 *   @0x3027dc svcmi #0xf0e92d
 *   @0x3027e0 .word 0xf8d0460f
 *   @0x3027e4 addlt r10, r11, r12, ror #3
 *   @0x3027e8 strmi r6, [r0], r11, asr #19
 *   @0x3027ec stmdbvs r12, {r3, r9, r10, lr}
 *   @0x3027f0 ldmdavs r11!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x3027f4 addsmi r6, r3, #12189696
 *   @0x3027f8 ldmdavc r11, {r4, r9, r12, lr, pc}
 *   @0x3027fc qaddle r2, r11, sp
 *   @0x302800 shasxmi r6, r8, r11
 *   @0x302804 ldmibvs r11!, {r3, r4, r7, r8, r9, r10, lr} ^
 *   @0x302808 .word 0x47984638
 *   @0x30280c ldmvs r10!, {r0, r1, r3, r4, r5, r11, sp, lr}
 *   @0x302810 andle r4, r8, #805306377
 *   @0x302814 blhs 0x1a60888 <b2_toiTime+0x13073e4>
 *   @0x302818 sbcs sp, r7, r5, lsl #2
 *   @0x30281c shsub16mi r6, r8, r11
 *   @0x302820 mcrne p7, #0x0, r4, c5, c8, #0x4
 *   @0x302824 movwhs sp, #0x3a01
 *   @0x302828 ldmvs lr!, {r0, r1, r2, r3, r6, r7, sp, lr, pc}
 *   @0x30282c addsmi r6, lr, #3866624
 *   @0x302830 bne 0xb749c <.text+0x4cc>
 *   @0x302834 adcsmi r1, r5, #246
 *   @0x302838 .word 0xf8d7dd15
 *   @0x30283c stmiblt r11, {r4, r5, r6, r8, r12, sp}
 *   @0x302840 tsths r8, r0, lsr #12
 *   @0x302844 .word 0xf7e4aa07
 *   @0x302848 blls 0x501a08 <SrcVerts+0x5ea4c>
 *   @0x30284c cmneq r0, r7, asr #17
 *   @0x302850 .word 0xf0402b00
 *   @0x302854 .word 0x462180b9
 *   @0x302858 cdp2 p7, #0x2, c15, c12, c5, #0x7
 *   @0x30285c stmdahs r0, {r0, r1, r2, r12, pc}
 *   @0x302860 adcshi pc, r2, r0, asr #32
 *   @0x302864 bvs 0x11d4140 <b2_toiTime+0xa7ac9c>
 *   @0x302868 .word 0x47984638
 *   @0x30286c blhs 0x31cc60
 *   @0x302870 adchi pc, r12, r0, asr #32
 *   @0x302874 shsub8mi r6, r8, r11
 *   @0x302878 ldrvc pc, [lr], r7, lsl #10
 *   @0x30287c ldrmi r9, [r8, r2, lsl #12]
 *   @0x302880 ldrsblo pc, [r8, -r7]!
 *   @0x302884 .word 0x2600b153
 *   @0x302888 cdpmi p6, #0x5, c9, c2, c1, #0x0
 *   @0x30288c .word 0x9603447e
 *   @0x302890 strls r10, [r4], -r8, lsl #28
 *   @0x302894 ldrbtmi r4, [lr], #-3664
 *   @0x302898 sub r9, r2, r5, lsl #12
 *   @0x30289c .word 0x3000f8da
 *   @0x3028a0 stmdals r2, {r0, r3, r5, r9, r10, lr}
 *   @0x3028a4 ldmdavs r11, {r1, r5, r9, r10, lr}
 *   @0x3028a8 mulls r7, r8, r7
 *   @0x3028ac rscle r2, r10, r0, lsl #16
 *   @0x3028b0 stmdbls r3, {r1, r3, r7, sp, lr, pc}
 *   @0x3028b4 .word 0xf5b32203
 *   @0x3028b8 stmdahs r0, {r2, r4, r7, r9, r10, r11, sp, lr, pc}
 *   @0x3028bc bvs 0x11f6ebc <b2_toiTime+0xa9da18>
 *   @0x3028c0 .word 0x47984638
 *   @0x3028c4 shsub16mi r6, r8, r11
 *   @0x3028c8 .word 0xf8d84798
 *   @0x3028cc stmdbge r8, {r7, r12, sp}
 *   @0x3028d0 blvs 0x19ed0fc <b2_toiTime+0x1293c58>
 *   @0x3028d4 svclt #0x183300
 *   @0x3028d8 strmi r2, [r1], r1, lsl #6
 *   @0x3028dc .word 0xf7fe4638
 *   @0x3028e0 stmdahs r0, {r0, r2, r4, r6, r9, r11, r12, sp, lr, pc}
 *   @0x3028e4 bvs 0x11f6ab4 <b2_toiTime+0xa9d610>
 *   @0x3028e8 .word 0x47984638
 *   @0x3028ec blhs 0x31cce0
 *   @0x3028f0 ldmibvs r11!, {r2, r3, r5, r6, r8, r12, lr, pc} ^
 *   @0x3028f4 .word 0x47984638
 *   @0x3028f8 ldmvs r11!, {r3, r4, r5, r11, sp, lr}
 *   @0x3028fc addsmi r1, r3, #2, #26
 *   @0x302900 .word 0xf8d7d815
 *   @0x302904 teqlt r2, r0, ror r1
 *   @0x302908 stmdbls r1, {r3, r6, r9, r10, lr}
 *   @0x30290c .word 0xf7e54623
 *   @0x302910 .word 0xf8ddfe4f
 *   @0x302914 .word 0xf8d79004
 *   @0x302918 .word 0xb1ab3138
 *   @0x30291c strlo r9, [r1], -r1, lsl #28
 *   @0x302920 ldmdavs r8!, {r0, r9, r10, r12, pc}
 *   @0x302924 stcne p8, c6, [r2, #-748]
 *   @0x302928 stmle r2, {r0, r1, r4, r7, r9, lr} ^
 *   @0x30292c stmdbls r5, {r1, r2, r6, sp, lr, pc}
 *   @0x302930 .word 0xf5b32203
 *   @0x302934 stmdahs r0, {r1, r2, r4, r6, r9, r10, r11, sp, lr, pc}
 *   @0x302938 bvs 0x11f70cc <b2_toiTime+0xa9dc28>
 *   @0x30293c .word 0x47984638
 *   @0x302940 shsub8mi r6, r8, r11
 *   @0x302944 bfi r4, r8, #15, #14
 *   @0x302948 .word 0x30acf8d8
 *   @0x30294c blle 0xd4d554 <b2_toiTime+0x5f40b0>
 *   @0x302950 addsmi r9, r9, #8, #18
 *   @0x302954 movwhs sp, #0x3202
 *   @0x302958 eors r9, r5, r7, lsl #6
 *   @0x30295c bge 0x4d41e4 <SrcVerts+0x31228>
 *   @0x302960 blx 0xffb808fa <b2_toiTime+0xffffffffff427456>
 *   @0x302964 strmi r9, [r3], r7, lsl #22
 *   @0x302968 .word 0xd12d2b00
 *   @0x30296c bls 0x528d98 <SrcVerts+0x85ddc>
 *   @0x302970 mcr p5, #0x1, pc, c4, c3, #0x5
 *   @0x302974 ldrsblo pc, [r0], -r10
 *   @0x302978 stmdbls r8, {r3, r4, r6, r9, r10, lr}
 *   @0x30297c rsceq pc, r10, #268435460
 *   @0x302980 .word 0xf8d84798
 *   @0x302984 blls 0x50ac3c <SrcVerts+0x67c80>
 *   @0x302988 stmdals r2, {r0, r3, r6, r9, r10, lr}
 *   @0x30298c .word 0xf8d71a9b
 *   @0x302990 movwls r6, #0x8168
 *   @0x302994 sbfxmi r4, r10, #0x8, #0x11
 *   @0x302998 andls r4, r7, r9, asr r6
 *   @0x30299c .word 0xf7e44620
 *   @0x3029a0 and pc, r7, r10, asr #25
 *   @0x3029a4 strbmi r9, [r9], -r2, lsl #16
 *   @0x3029a8 blls 0x5291d4 <SrcVerts+0x86218>
 *   @0x3029ac .word 0x6168f8d7
 *   @0x3029b0 strhls r4, [r7], -r0
 *   @0x3029b4 blhs 0x3295d8
 *   @0x3029b8 strh sp, [r5], -r0
 *   @0x3029bc ldrsblo pc, [r8, -r7]!
 *   @0x3029c0 .word 0xf8c7b923
 *   @0x3029c4 and r5, r1, r8, lsr r1
 *   @0x3029c8 rscsvs r9, r11, r7, lsl #22
 *   @0x3029cc pop {r0, r1, r3, r12, sp, pc}
 *   @0x3029d0 svclt #0x8ff0
 *   @0x3029d4 andeq r12, r8, r10, ror #7
 *   @0x3029d8 andeq r12, r8, r4, ror #7
 *   @0x3029dc addlt r11, r6, r0, ror r5
 *   @0x3029e0 strmi r6, [r5], -r12, asr #22
 *   @0x3029e4 strmi r4, [r8], -lr, lsl #12
 *   @0x3029e8 .word 0x2106466a
 *   @0x3029ec strmi r2, [r0, r3, lsl #6]!
 *   @0x3029f0 .word 0xdc022805
 *   @0x3029f4 rscsvs r2, r3, r3, lsl #6
 *   @0x3029f8 .word 0x9c03e044
 *   @0x3029fc svclt #0xb82c00
 *   @0x302a00 .word 0x2c004264
 *   @0x302a04 .word 0xf5b4d0f6
 *   @0x302a08 eorle r3, r7, r0, lsl #31
 *   @0x302a0c .word 0xf44f4621
 *   @0x302a10 .word 0xf7e2707a
 *   @0x302a14 qsaxmi pc, r1, r0
 *   @0x302a18 subeq pc, r4, r5, lsr #17
 *   @0x302a1c .word 0xf7e29800
 *   @0x302a20 strtmi pc, [r1], -r10, asr #20
 *   @0x302a24 stmdals r1, {r12, pc}
 *   @0x302a28 blx 0x14809b8 <b2_toiTime+0xd27514>
 *   @0x302a2c andls r4, r1, r1, lsr #12
 *   @0x302a30 .word 0xf7e29802
 *   @0x302a34 strtmi pc, [r1], -r0, asr #20
 *   @0x302a38 stmdals r4, {r1, r12, pc}
 *   @0x302a3c blx 0x12009cc <b2_toiTime+0xaa7528>
 *   @0x302a40 andls r4, r4, r1, lsr #12
 *   @0x302a44 .word 0xf7e29805
 *   @0x302a48 blls 0x401328 <g_RomDisk+0x9b08>
 *   @0x302a4c b 0x79528c <b2_toiTime+0x3bde8>
 *   @0x302a50 svclt #0x380323
 *   @0x302a54 orrlo pc, r0, #1325400064
 *   @0x302a58 andls r9, r5, r3, lsl #6
 *   @0x302a5c .word 0xf8c59b00
 *   @0x302a60 blls 0x34f148
 *   @0x302a64 biclo pc, r0, r5, asr #17
 *   @0x302a68 .word 0xf8c59b02
 *   @0x302a6c blls 0x3cf164 <error_g0017+0x27e08>
 *   @0x302a70 biclo pc, r4, r5, asr #17
 *   @0x302a74 ldrhlo pc, [r2], -sp
 *   @0x302a78 biclo pc, r8, r5, asr #17
 *   @0x302a7c ldrhlo pc, [r6], -sp
 *   @0x302a80 biclo pc, r12, r5, asr #17
 *   @0x302a84 ldcllt p0, c11, [r0, #-24]!
 *   @0x302a88 .word 0xffff0000
 *   @0x302a8c stmvs r2, {r3, r4, r5, r6, r7, r8, r10, r12, sp, pc}
 *   @0x302a90 addsmi r6, r9, #1245184
 *   @0x302a94 stmdavc r4, {r0, r1, r8, r10, r11, r12, lr, pc}
 *   @0x302a98 movwhs r4, #0x1616
 *   @0x302a9c stmdavs r3, {r0, r1, sp, lr, pc} ^
 *   @0x302aa0 ands r6, pc, r8, lsl r8
 *   @0x302aa4 adcmi r3, r3, #67108864
 *   @0x302aa8 .word 0xf856da16
 *   @0x302aac addseq r5, pc, r4, lsl #30
 *   @0x302ab0 ldclle p2, c4, [r7], #676
 *   @0x302ab4 .word 0xf1036840
 *   @0x302ab8 bllo 0x3538c0
 *   @0x302abc eormi pc, r3, r0, asr r8
 *   @0x302ac0 eorlo pc, r3, r2, asr r8
 *   @0x302ac4 bne 0xff5191e4 <b2_toiTime+0xfffffffffedbfd40>
 *   @0x302ac8 .word 0xf7e21ae9
 *   @0x302acc blne 0x10c12a4 <b2_toiTime+0x967e00>
 *   @0x302ad0 bl 0x313898 <af_shaper_get_elem+0x9106>
 *   @0x302ad4 ldcllt p0, c4, [r8, #16]!
 *   @0x302ad8 orrmi pc, r0, #4, #2
 *   @0x302adc bllo 0x35cbec <_ZTS7CFontGM+0x2b4>
 *   @0x302ae0 eoreq pc, r3, r2, asr r8
 *   @0x302ae4 ldcllt p4, c0, [r8, #0]!
 *   @0x302ae8 ldrbtmi r4, [r8], #-2050
 *   @0x302aec addsvs pc, r12, r0, lsl #4
 *   @0x302af0 stclt p7, c15, [pc], #-904
 *   @0x302af4 andeq r6, lr, r2, lsl r7
 *   @0x302af8 svcmi #0xf0e92d
 *   @0x302afc .word 0xf8d04681
 *   @0x302b00 addslt r8, r1, r4, lsl r2
 *   @0x302b04 .word 0xf1b84692
 *   @0x302b08 suble r0, r11, r0, lsl #30
 *   @0x302b0c .word 0x3004f8d8
 *   @0x302b10 strhs r4, [r0], #-1605
 *   @0x302b14 svclt #0x344299
 *   @0x302b18 ldrmi r4, [r11], r11, lsl #13
 *   @0x302b1c .word 0x1004f8d8
 *   @0x302b20 eorsle r4, r10, #140, #4
 *   @0x302b24 stclvs p5, c4, [r9, #368]!
 *   @0x302b28 .word 0xf8956e2e
 *   @0x302b2c andle lr, r2, #88
 *   @0x302b30 eoreq pc, r4, r10, asr r8
 *   @0x302b34 .word 0xf10ee009
 *   @0x302b38 bllo 0x353940
 *   @0x302b3c eoreq pc, r3, r1, asr r8
 *   @0x302b40 bne 0xff3dcb74 <b2_toiTime+0xfffffffffec836d0>
 *   @0x302b44 bicsvc lr, r3, #3072
 *   @0x302b48 .word 0xf04f1058
 *   @0x302b4c movwhs r3, #0x7ff
 *   @0x302b50 eorle r4, r9, #482344960
 *   @0x302b54 eorhs pc, r3, r1, asr r8
 *   @0x302b58 vstmiaeq r3, {s28, s29, s30, s31}
 *   @0x302b5c swple r4, r0, [r2]
 *   @0x302b60 andeq pc, r12, r6, asr r8
 *   @0x302b64 ble 0x3babbc <error_g0017+0x13860>
 *   @0x302b68 .word 0xd1051c7b
 *   @0x302b6c ldrmi lr, [pc], -r2
 *   @0x302b70 strb r3, [sp, r1, lsl #6]!
 *   @0x302b74 and r6, r11, r0, lsr r8
 *   @0x302b78 eorlo pc, r7, r1, asr r8
 *   @0x302b7c and pc, r12, r6, asr r8
 *   @0x302b80 eorne pc, r7, r6, asr r8
 *   @0x302b84 bne 0xff78968c <b2_toiTime+0xffffffffff0301e8>
 *   @0x302b88 smlabteq lr, r1, r11, lr
 *   @0x302b8c .word 0xf8d6f7e2
 *   @0x302b90 eoreq pc, r4, sp, asr #16
 *   @0x302b94 strlo r3, [r1], #-1292
 *   @0x302b98 strbmi lr, [r8], -r0, asr #15
 *   @0x302b9c .word 0xf7fe466a
 *   @0x302ba0 and pc, r10, r6, lsr #17
 *   @0x302ba4 and r2, r8, r6
 *   @0x302ba8 rscle r3, r3, r1, lsl #14
 *   @0x302bac cdpmi p1, #0x8, c15, c0, c14, #0x0
 *   @0x302bb0 cdplo p1, #0xf, c15, c15, c14, #0x0
 *   @0x302bb4 eoreq pc, lr, r6, asr r8
 *   @0x302bb8 andslt lr, r1, r10, ror #15
 *   @0x302bbc svchi #0xf0e8bd
 *   @0x302bc0 mvnsmi lr, sp, lsr #18
 *   @0x302bc4 svclt #0x342904
 *   @0x302bc8 .word 0xf04f4688
 *   @0x302bcc strmi r0, [r6], -r4, lsl #16
 *   @0x302bd0 strhs r4, [r0], #-1559
 *   @0x302bd4 strbtmi r4, [sp], -r4, asr #10
 *   @0x302bd8 .word 0xf857d008
 *   @0x302bdc .word 0xf7e20024
 *   @0x302be0 strne pc, [r0], #-2205
 *   @0x302be4 eoreq pc, r4, r5, asr #16
 *   @0x302be8 ldrb r3, [r3, r1, lsl #8]!
 *   @0x302bec qasxmi r4, r1, r0
 *   @0x302bf0 .word 0xf7ff466a
 *   @0x302bf4 andlt pc, r4, r1, lsl #31
 *   @0x302bf8 ldrhhi lr, [r0, #141]!
 *   @0x302bfc ldrbmi lr, [r0, sp, lsr #18]!
 *   @0x302c00 .word 0xf8d0460e
 *   @0x302c04 .word 0x469171f0
 *   @0x302c08 cmplt pc, #152, #12
 *   @0x302c0c .word 0xf04f2500
 *   @0x302c10 bvs 0x11c5468 <b2_toiTime+0xa6bfc4>
 *   @0x302c14 eorle r4, r2, #-805306359
 *   @0x302c18 .word 0xf305fb0a
 *   @0x302c1c ldmne r4, {r1, r3, r4, r5, r6, r7, r8, r11, sp, lr} ^
 *   @0x302c20 strbmi r5, [r11, #-0x8d3]
 *   @0x302c24 stmdavs r3!, {r0, r3, r4, r8, r12, lr, pc} ^
 *   @0x302c28 ble 0x3d36a8 <error_g0017+0x2c34c>
 *   @0x302c2c .word 0xf8c868a3
 *   @0x302c30 ands r3, r2, r0
 *   @0x302c34 .word 0xc00cf8d4
 *   @0x302c38 strbmi r6, [r6, #-0x922]!
 *   @0x302c3c .word 0xf8c8dd02
 *   @0x302c40 and r2, r10, r0
 *   @0x302c44 bne 0xfff1ced0 <b2_toiTime+0xffffffffff7c3a2c>
 *   @0x302c48 bl 0xff3c9594 <b2_toiTime+0xfffffffffec700f0>
 *   @0x302c4c .word 0xf7e2020c
 *   @0x302c50 stmvs r3!, {r0, r2, r4, r5, r6, r11, r12, sp, lr, pc}
 *   @0x302c54 .word 0xf8c84418
 *   @0x302c58 strlo r0, [r1, #-0x0]
 *   @0x302c5c ldrdhs lr, pc, [r0], -r9
 *   @0x302c60 .word 0x87f0e8bd
 *   @0x302c64 pop {r1, r2, sp}
 *   @0x302c68 push {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x302c6c .word 0x460641f0
 *   @0x302c70 ldrmi r9, [sp], -r6, lsl #30
 *   @0x302c74 strbvc lr, [r7, r7, lsr #20]!
 *   @0x302c78 vmla.i8 d2, d0, d29
 *   @0x302c7c ldm pc, {r0, r1, r2, r4, r5, r8, r9, pc} ^
 *   @0x302c80 eoreq pc, lr, r1, lsl r0
 *   @0x302c84 subseq r0, r5, r9, lsr r0
 *   @0x302c88 rsbseq r0, r12, r1, ror r0
 *   @0x302c8c addeq r0, r10, pc, ror r0
 *   @0x302c90 umlaleq r0, sp, r5, r0
 *   @0x302c94 sbceq r0, sp, r2, asr #1
 *   @0x302c98 rscseq r0, r9, lr, ror #1
 *   @0x302c9c .word 0x012c0121
 *   @0x302ca0 .word 0x01420137
 *   @0x302ca4 cmneq r5, pc, asr r1
 *   @0x302ca8 orrseq r0, r2, r0, lsl #3
 *   @0x302cac .word 0x01af019d
 *   @0x302cb0 ldrheq r0, [r4, #-26]
 *   @0x302cb4 biceq r0, r12, r10, ror #2
 *   @0x302cb8 ldrdeq r0, r1, [r9, #23]!
 *   @0x302cbc andseq r0, r1, #244, #2
 *   @0x302cc0 andseq r0, r12, #1610612736
 *   @0x302cc4 eorseq r0, r7, #44, #4
 *   @0x302cc8 rsbseq r0, r9, #536870916
 *   @0x302ccc rsbseq r0, pc, #124, #4
 *   @0x302cd0 addeq r0, r5, #536870920
 *   @0x302cd4 subseq r0, r8, #-805306364
 *   @0x302cd8 rsbeq r0, lr, #805306374
 *   @0x302cdc stchs p2, c0, [r0, #-592]
 *   @0x302ce0 rsbshi pc, r4, #0
 *   @0x302ce4 .word 0xf0002f00
 *   @0x302ce8 .word 0xf8968273
 *   @0x302cec strhs r3, [r1], #-437
 *   @0x302cf0 rsb r7, r8, #43
 *   @0x302cf4 vpmax.s8 d2, d0, d3
 *   @0x302cf8 stchs p2, c8, [r0, #-996]
 *   @0x302cfc rsbhi pc, r10, #0
 *   @0x302d00 vmax.f32 d18, d0, d3
 *   @0x302d04 bhs 0x3a36b0 <af_blue_strings+0x138c>
 *   @0x302d08 bhs 0x3f6d30 <g_MP3UpdateVolume+0x1a54>
 *   @0x302d0c bhs 0x376d38 <_ZTS13C_UTF16String+0xdde4>
 *   @0x302d10 .word 0xf8d6bf14
 *   @0x302d14 .word 0xf8d631b8
 *   @0x302d18 strh r3, [r4], -r12
 *   @0x302d1c .word 0x31c0f8d6
 *   @0x302d20 .word 0xf8d6e001
 *   @0x302d24 eorvs r3, r11, r4, asr #3
 *   @0x302d28 sub r2, r12, #4, #8
 *   @0x302d2c vpmax.s8 d2, d0, d3
 *   @0x302d30 stchs p2, c8, [r0, #-884]
 *   @0x302d34 subshi pc, r2, #0
 *   @0x302d38 vmax.f32 d18, d0, d3
 *   @0x302d3c bhs 0x3a3688 <af_blue_strings+0x1364>
 *   @0x302d40 bhs 0x3f6d68 <g_MP3UpdateVolume+0x1a8c>
 *   @0x302d44 bhs 0x376d70 <_ZTS13C_UTF16String+0xde1c>
 *   @0x302d48 .word 0xf8d6bf14
 *   @0x302d4c .word 0xf8d631d0
 *   @0x302d50 ldrd r3, r4, [r4], -r4
 *   @0x302d54 ldrsblo pc, [r8, #134]
 *   @0x302d58 .word 0xf8d6e001
 *   @0x302d5c .word 0x602b31dc
 *   @0x302d60 eors r2, r0, #4, #8
 *   @0x302d64 .word 0xf0002d00
 *   @0x302d68 svchs #0x823d
 *   @0x302d6c eorshi pc, r12, #0
 *   @0x302d70 .word 0x31b4f896
 *   @0x302d74 eorvc r2, r11, r1, lsl #8
 *   @0x302d78 .word 0xf8d6e225
 *   @0x302d7c and r6, r7, #108, #2
 *   @0x302d80 .word 0xf0002d00
 *   @0x302d84 svchs #0x38233
 *   @0x302d88 eorshi pc, r2, #64, #4
 *   @0x302d8c .word 0x30a8f8d6
 *   @0x302d90 eorvs r2, r11, r4, lsl #8
 *   @0x302d94 stchs p2, c14, [r0, #-92]
 *   @0x302d98 eorhi pc, r12, #0
 *   @0x302d9c vmax.f32 d18, d0, d3
 *   @0x302da0 .word 0xf8d6822b
 *   @0x302da4 strhs r3, [r4], #-420
 *   @0x302da8 and r6, r12, #43
 *   @0x302dac .word 0x31a4f8d6
 *   @0x302db0 .word 0xf080429a
 *   @0x302db4 .word 0xf8d6829b
 *   @0x302db8 .word 0xf85331a8
 *   @0x302dbc strbmi r8, [r0], -r2, lsr #32
 *   @0x302dc0 bl 0xff1c0494 <b2_toiTime+0xfffffffffea66ff0>
 *   @0x302dc4 mcrrne p6, #0x0, r4, r4, c6
 *   @0x302dc8 .word 0xf0002d00
 *   @0x302dcc adcmi r8, r7, #1073741886
 *   @0x302dd0 mvnshi pc, r0, asr #1
 *   @0x302dd4 strbmi r4, [r1], -r8, lsr #12
 *   @0x302dd8 eors r4, r11, r2, lsr #12
 *   @0x302ddc .word 0x31a4f8d6
 *   @0x302de0 .word 0xf080429a
 *   @0x302de4 .word 0xf8d68283
 *   @0x302de8 ldrheq r3, [r1], r0
 *   @0x302dec eorhi pc, r2, r3, asr r8
 *   @0x302df0 streq pc, [r1], #-264
 *   @0x302df4 .word 0xf0002d00
 *   @0x302df8 adcmi r8, r7, #-1073741768
 *   @0x302dfc mvnhi pc, r0, asr #1
 *   @0x302e00 .word 0x31acf8d6
 *   @0x302e04 stchs p0, c14, [r0, #-340]
 *   @0x302e08 mvnshi pc, r0
 *   @0x302e0c vmax.f32 d18, d0, d3
 *   @0x302e10 .word 0xf8d681f7
 *   @0x302e14 strhs r3, [r4], #-368
 *   @0x302e18 bics r6, r4, r11, lsr #32
 *   @0x302e1c ldrsblo pc, [r0, #-134]!
 *   @0x302e20 .word 0xf0402b01
 *   @0x302e24 .word 0xf8d68263
 *   @0x302e28 addsmi r3, r10, #116, #2
 *   @0x302e2c subshi pc, lr, #128
 *   @0x302e30 .word 0x3184f8d6
 *   @0x302e34 eorhi pc, r2, r3, asr r8
 *
 * ══ §8/13 anon_2b84e8  0x2b84e8  size 1508  94 条（0x2b84e8..0x2b8acc）｜其中 283 条已由别的卡落锚，本节不再重复
 * @func 0x2b84e8 0x2b8acc  size 1508  94 条
 * 部分覆盖: 本节 94/377 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jcopy_sample_rows×2 / anon_2b84e8+0x148 / anon_2b84e8+0x1c8 / anon_2b84e8+0x2d4 / anon_2b84e8+0x46c / anon_2b84e8+0x550 / anon_2b84e8+0x518 / anon_2b84e8+0x540
 * 字段偏移 top8: 0x1×16 / 0x4×15 / 0x114×14 / 0x5c×10 / 0xc×9 / 0x-1×6 / 0x8×6 / 0x2×6
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b84e8 ldr r3, [r0, #0x1a0]
 *   @0x2b84ec ldr r1, [r0, #0x114]
 *   @0x2b84f0 ldr r2, [r0, #0x60]
 *   @0x2b84f4 str r1, [r3, #0x5c]
 *   @0x2b84f8 str r2, [r3, #0x60]
 *   @0x2b84fc bx lr
 *   @0x2b896c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2b8970 mov r6, r0
 *   @0x2b8974 ldr r1, [r1, #0x4]
 *   @0x2b8978 sub sp, sp, #8
 *   @0x2b897c ldr r0, [r0, #0x1a0]
 *   @0x2b8980 ldr r12, [r6, #0x114]
 *   @0x2b8984 add r1, r0, r1
 *   @0x2b8988 ldr r10, [r3]
 *   @0x2b898c cmp r12, #0
 *   @0x2b8990 ldrb r4, [r1, #0x8c]
 *   @0x2b8994 ldrb r7, [r1, #0x96]
 *   @0x2b8998 ble 0x2b8a38 <jinit_d_post_controller+0x62c>
 *   @0x2b899c sub r8, r2, #4
 *   @0x2b89a0 sub r9, r7, #1
 *   @0x2b89a4 mov r5, #0
 *   @0x2b89a8 ldr r3, [r10, r5, lsl #2]
 *   @0x2b89ac ldr r0, [r6, #0x5c]
 *   @0x2b89b0 ldr r1, [r8, #0x4]!
 *   @0x2b89b4 add r0, r3, r0
 *   @0x2b89b8 cmp r3, r0
 *   @0x2b89bc bhs 0x2b8a00 <jinit_d_post_controller+0x5f4>
 *   @0x2b89c0 cmp r4, #0
 *   @0x2b89c4 ldrb r2, [r1], #1
 *   @0x2b89c8 beq 0x2b89f4 <jinit_d_post_controller+0x5e8>
 *   @0x2b89cc add r12, r3, r4
 *   @0x2b89d0 strb r2, [r3], #1
 *   @0x2b89d4 cmp r3, r12
 *   @0x2b89d8 bne 0x2b89d0 <jinit_d_post_controller+0x5c4>
 *   @0x2b89dc cmp r0, r12
 *   @0x2b89e0 bls 0x2b8a00 <jinit_d_post_controller+0x5f4>
 *   @0x2b89e4 cmp r4, #0
 *   @0x2b89e8 mov r3, r12
 *   @0x2b89ec ldrb r2, [r1], #1
 *   @0x2b89f0 bne 0x2b89cc <jinit_d_post_controller+0x5c0>
 *   @0x2b89f4 mov r12, r3
 *   @0x2b89f8 cmp r0, r12
 *   @0x2b89fc bhi 0x2b89e4 <jinit_d_post_controller+0x5d8>
 *   @0x2b8a00 cmp r7, #1
 *   @0x2b8a04 ble 0x2b8a28 <jinit_d_post_controller+0x61c>
 *   @0x2b8a08 ldr r12, [r6, #0x5c]
 *   @0x2b8a0c mov r0, r10
 *   @0x2b8a10 str r9, [sp]
 *   @0x2b8a14 mov r1, r5
 *   @0x2b8a18 mov r2, r10
 *   @0x2b8a1c add r3, r5, #1
 *   @0x2b8a20 str r12, [sp, #0x4]
 *   @0x2b8a24 bl 0x2bc81c <jcopy_sample_rows>
 *   @0x2b8a28 ldr r3, [r6, #0x114]
 *   @0x2b8a2c add r5, r5, r7
 *   @0x2b8a30 cmp r3, r5
 *   @0x2b8a34 bgt 0x2b89a8 <jinit_d_post_controller+0x59c>
 *   @0x2b8a38 add sp, sp, #8
 *   @0x2b8a3c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2b8a40 ldr r1, [r0, #0x114]
 *   @0x2b8a44 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2b8a48 cmp r1, #0
 *   @0x2b8a4c sub sp, sp, #12
 *   @0x2b8a50 mov r7, r0
 *   @0x2b8a54 ldr r6, [r3]
 *   @0x2b8a58 ble 0x2b8ac8 <jinit_d_post_controller+0x6bc>
 *   @0x2b8a5c sub r9, r2, #4
 *   @0x2b8a60 mov r5, #0
 *   @0x2b8a64 mov r8, #1
 *   @0x2b8a68 ldr r3, [r6, r5, lsl #2]
 *   @0x2b8a6c ldr r2, [r7, #0x5c]
 *   @0x2b8a70 ldr lr, [r9, #0x4]!
 *   @0x2b8a74 add r4, r3, r2
 *   @0x2b8a78 cmp r3, r4
 *   @0x2b8a7c bhs 0x2b8a9c <jinit_d_post_controller+0x690>
 *   @0x2b8a80 ldrb r12, [lr], #1
 *   @0x2b8a84 add r3, r3, #2
 *   @0x2b8a88 strb r12, [r3, #-0x2]
 *   @0x2b8a8c strb r12, [r3, #-0x1]
 *   @0x2b8a90 cmp r4, r3
 *   @0x2b8a94 bhi 0x2b8a80 <jinit_d_post_controller+0x674>
 *   @0x2b8a98 ldr r2, [r7, #0x5c]
 *   @0x2b8a9c add r3, r5, #1
 *   @0x2b8aa0 str r2, [sp, #0x4]
 *   @0x2b8aa4 mov r1, r5
 *   @0x2b8aa8 str r8, [sp]
 *   @0x2b8aac mov r0, r6
 *   @0x2b8ab0 mov r2, r6
 *   @0x2b8ab4 bl 0x2bc81c <jcopy_sample_rows>
 *   @0x2b8ab8 ldr r3, [r7, #0x114]
 *   @0x2b8abc add r5, r5, #2
 *   @0x2b8ac0 cmp r3, r5
 *   @0x2b8ac4 bgt 0x2b8a68 <jinit_d_post_controller+0x65c>
 *   @0x2b8ac8 add sp, sp, #12
 *
 * ══ §9/13 anonT_2e8c38  0x2e8c38  size 1180  58 条（0x2e8c38..0x2e90d4）｜其中 237 条已由别的卡落锚，本节不再重复
 * @func 0x2e8c48 0x2e90cc  size 1156  58 条
 * 部分覆盖: 本节 58/531 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Stream_Seek×2 / FT_Stream_Free×2 / FT_Stream_New / 0x1ac8ec4 / 0xb6574 / anonT_2e90fc+0xa8 / 0x374e90 / FT_Stream_Read
 * 字段偏移 top8: 0x1c×4 / 0x14×4 / 0x38×4 / 0x10×4 / 0xc×4 / 0x18×3 / 0x2c×3 / 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8c48 ldrbtmi r1, [r10], #-384
 *   @0x2e8c50 .word 0xf10d083c
 *   @0x2e8c54 strmi r0, [r5], -r0, asr #18
 *   @0x2e8c78 stmdavs r3!, {r0, r2, r3, r4, r9, pc}
 *   @0x2e8c8c and r0, r0, r1, lsl #22
 *   @0x2e8ca4 blx 0x1ac8ec4 <b2_toiTime+0x136fa20>
 *   @0x2e8ca8 andls pc, r6, #-1342177272
 *   @0x2e8cc4 shadd16mi r0, r0, r0
 *   @0x2e8cd4 ldrtmi r0, [r11], -r12, lsl #4
 *   @0x2e8cdc andls pc, lr, r9, ror #30
 *   @0x2e8ce4 and r8, r1, r1, ror #2
 *   @0x2e8d00 bge 0x6eb1f8 <g_SWFvertbuff+0x18130>
 *   @0x2e8d08 movwls r0, #0x9383
 *   @0x2e8d2c .word 0xf0130a38
 *   @0x2e8d30 svclt #0x160310
 *   @0x2e8d3c bge 0x6e8d74 <g_SWFvertbuff+0x15cac>
 *   @0x2e8d48 .word 0x4603ff33
 *   @0x2e8d98 ldrbmi r0, [r9], -r0
 *   @0x2e8da8 blhs 0x374e90 <_ZTS13C_UTF16String+0xbf3c>
 *   @0x2e8dbc bhs 0x17299b0 <b2_toiTime+0xfd050c>
 *   @0x2e8dc8 stmdbls r7, {r1, r3, r5, r6, r7, pc}
 *   @0x2e8dd0 .word 0xf8dd80e1
 *   @0x2e8dd4 .word 0xf1b9903c
 *   @0x2e8dd8 suble r0, r0, r0, lsl #30
 *   @0x2e8e00 bllt 0x1fb5280 <b2_toiTime+0x185bddc>
 *   @0x2e8e0c mrcne p0, #0x2, r3, c10, c5, #0x6
 *   @0x2e8e20 ldmiblt r3!, {r1, r7, r10, r11, r12, sp} ^
 *   @0x2e8e34 ldreq r1, [r2], #-298
 *   @0x2e8e58 strmi pc, [r3], -r1, lsl #21
 *   @0x2e8e78 .word 0x4603fa71
 *   @0x2e8e90 blge 0xbab838 <b2_toiTime+0x452394>
 *   @0x2e8eb0 .word 0xf7fd8044
 *   @0x2e8eb4 bmi 0xfe4e82e8 <b2_toiTime+0xfffffffffdd8ee44>
 *   @0x2e8ee4 bhs 0x2f0f0c <FT_Done_Memory+0x7298>
 *   @0x2e8ef0 stmdblt r3, {r3, r12, sp}
 *   @0x2e8f00 bls 0x4a78bc <SrcVerts+0x4900>
 *   @0x2e8f18 movwls r0, #0xc44
 *   @0x2e8f20 ldrtmi r2, [r11], -r8
 *   @0x2e8f3c blls 0x427984 <g_RomDisk+0x30164>
 *   @0x2e8f50 .word 0xf1080901
 *   @0x2e8f54 .word 0xf1b80804
 *   @0x2e8f58 .word 0xd1b20f24
 *   @0x2e8f6c .word 0xf84af9e4
 *   @0x2e8f70 blls 0x3fcf88 <g_RomDisk+0x5768>
 *   @0x2e8fa4 rsbs pc, sp, r12, asr r10
 *   @0x2e8fb4 .word 0xf8d5f8b8
 *   @0x2e8fb8 strmi r8, [r1], -r0
 *   @0x2e8fcc svchs #0xfca9
 *   @0x2e8fd8 eorvs pc, r8, r11, asr #26
 *   @0x2e9008 ldreq r1, [r1], r10, asr #32
 *   @0x2e9010 .word 0xf8a3104a
 *   @0x2e9014 ldreq r1, [r3, lr, asr #32]
 *   @0x2e9020 .word 0xf8d33180
 *   @0x2e9024 stm r3, {r7, r12, sp}
 *   @0x2e9028 addsvs r0, r10, r6
 *   @0x2e9038 bls 0x431120 <g_RomDisk+0x39900>
 *   @0x2e90a0 mul r5, sp, sp
 *   @0x2e90c8 svclt #0x8ff0
 *
 * ══ §10/13 anonT_2f0444  0x2f0444  size 1154  56 条（0x2f0444..0x2f08c6）｜其中 233 条已由别的卡落锚，本节不再重复
 * @func 0x2f044c 0x2f08c8  size 1148  56 条
 * 部分覆盖: 本节 56/499 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e9c78+0x6464×5 / 0xb65b0×2 / anon_2e9c78+0x674a / anonT_2f0444+0x56 / anonT_2f0444+0x74 / anonT_2f0444+0xa6 / 0xbec52c / 0x7bc8ec
 * 字段偏移 top8: 0x14×7 / 0xc×5 / 0x8×4 / 0x-4×3 / 0x-10×3 / 0x4×3 / 0x-8×2 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2f044c strmi r2, [r4], -r8, asr #1
 *   @0x2f0458 addsmi r2, r3, #204
 *   @0x2f0460 strtmi r1, [r0], -r8, asr #1
 *   @0x2f046c .word 0xf8d4ffaa
 *   @0x2f0470 addsmi r3, lr, #148, #2
 *   @0x2f0478 addsmi r3, pc, #152, #2
 *   @0x2f0488 swphs r7, r8, [r1]
 *   @0x2f04a4 svclt #0xac0fc3
 *   @0x2f04c8 stmdahs r0!, {r0, r3, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f04d4 andle r0, r11, r1, lsl #30
 *   @0x2f04dc .word 0xd10a0f02
 *   @0x2f04ec and r7, r4, lr, asr #11
 *   @0x2f04f8 .word 0xf85565f5
 *   @0x2f04fc strlo r9, [r0, #-0xb04]!
 *   @0x2f0514 ldrtmi r3, [r8], #-2559
 *   @0x2f054c .word 0xf845033f
 *   @0x2f0550 .word 0xf8453c10
 *   @0x2f0554 ldrb r0, [r2, r12, lsl #24]
 *   @0x2f0564 strbmi r7, [r8], lr, asr #7
 *   @0x2f0578 .word 0xf5047568
 *   @0x2f057c .word 0xf8556af5
 *   @0x2f0580 .word 0xf1b99b24
 *   @0x2f0584 eorle r0, r9, r0, lsl #30
 *   @0x2f0598 ldrtmi r0, [r1], -r0, lsr #24
 *   @0x2f05bc ldmdbvs r10!, {r3, r10, r11, sp}
 *   @0x2f05c8 and r2, r3, r12, lsl #24
 *   @0x2f0604 .word 0xf8431303
 *   @0x2f0608 ldrbmi r1, [r0, -r4, lsl #24]!
 *   @0x2f0638 .word 0xf5c5081c
 *   @0x2f063c blmi 0xbec52c <b2_toiTime+0x493088>
 *   @0x2f064c .word 0x21000070
 *   @0x2f0674 .word 0xf8c4008c
 *   @0x2f0678 smlabbhs r0, r8, r0, r5
 *   @0x2f069c mulhs r0, r4, r0
 *   @0x2f06a4 blmi 0x7bc8ec <b2_toiTime+0x63448>
 *   @0x2f06b0 blmi 0x73c918 <g_SWFvertbuff+0x69850>
 *   @0x2f06bc blmi 0x6bc934 <g_SWFlinevertbuff+0x6986c>
 *   @0x2f06c4 pop {r5, r7, r12, sp}
 *   @0x2f06c8 svclt #0x81f0
 *   @0x2f0730 strmi r0, [r8], -r7, lsl #20
 *   @0x2f0744 adcvs pc, r0, r4, lsr #25
 *   @0x2f075c ldrlt r8, [r0, #-0x7f0]!
 *   @0x2f078c blls 0x3ef994
 *   @0x2f07b0 ldmdblt r8, {r1, r2, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2f07d0 mrcne p15, #0x0, r4, c6, c0, #0x7
 *   @0x2f07f0 and r0, r2, r0, lsl #20
 *   @0x2f0848 .word 0xf8c4f20b
 *   @0x2f084c blo 0x61c854 <g_SWFaavertbuff+0x4978c>
 *   @0x2f0854 subsvs r8, lr, r2
 *   @0x2f0864 strbmi r0, [r8], -r7, lsl #24
 *   @0x2f087c adcvs r12, r0, r12
 *   @0x2f0890 strbmi r0, [r9], -r12
 *   @0x2f0898 and pc, r7, r3, lsr pc
 *   @0x2f08a8 movwls r1, #0x5303
 *   @0x2f08b8 stmdblt r8, {r1, r4, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f08c4 ldrblt r8, [r0, #-0xff0]!
 *
 * ══ §11/13 png_read_info  0x2a6ff0  size 1112  83 条（0x2a6ff0..0x2a7448）｜其中 195 条已由别的卡落锚，本节不再重复
 * @func 0x2a7004 0x2a7434  size 1072  83 条
 * 部分覆盖: 本节 83/493 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_handle_as_unknown / 0xb6c40
 * 字段偏移 top8: 0x4×9 / 0x1e×3 / 0x14×2 / 0x50×2 / 0x10×1 / 0xa×1 / 0x20×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a7004 .word 0xf8df8213
 *   @0x2a7008 .word 0xf004842c
 *   @0x2a700c .word 0xf10dfdc3
 *   @0x2a7010 ldrbtmi r0, [r8], #2568
 *   @0x2a7038 .word 0xf8530000
 *   @0x2a703c ldmdbvc r11, {r0, r2, r8, r9, r10, r11}
 *   @0x2a7044 .word 0x46433014
 *   @0x2a7058 ldmdbvc r11, {r0, r1, r2, r3, r8, r9, r10, r11}
 *   @0x2a7060 strbmi r3, [r3], -r4, lsr #32
 *   @0x2a7074 ldmdbvc r11, {r0, r3, r4, r8, r9, r10, r11}
 *   @0x2a707c .word 0x46433034
 *   @0x2a7090 ldmdbvc r11, {r0, r1, r5, r8, r9, r10, r11}
 *   @0x2a7098 strbmi r3, [r3], -r4, asr #32
 *   @0x2a70ac ldmdbvc r11, {r0, r2, r3, r5, r8, r9, r10, r11}
 *   @0x2a70b4 .word 0x46433054
 *   @0x2a70c8 ldmdbvc r11, {r0, r1, r2, r4, r5, r8, r9, r10, r11}
 *   @0x2a70d0 strbmi r3, [r3], -r4, rrx
 *   @0x2a70e4 ldmdbvc r11, {r0, r6, r8, r9, r10, r11}
 *   @0x2a70ec .word 0x46433074
 *   @0x2a7100 ldmdbvc r11, {r0, r1, r3, r6, r8, r9, r10, r11}
 *   @0x2a7108 strbmi r3, [r3], -r4, lsl #1
 *   @0x2a711c ldmdbvc r11, {r0, r2, r4, r6, r8, r9, r10, r11}
 *   @0x2a7124 .word 0x46433094
 *   @0x2a7138 ldmdbvc r11, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11}
 *   @0x2a7140 strbmi r3, [r3], -r4, lsr #1
 *   @0x2a7150 .word 0xf00630ac
 *   @0x2a7154 .word 0x4649fd37
 *   @0x2a7160 ldmdblt r8!, {r4, r5, r6, r8, r10, r11, sp, lr, pc}
 *   @0x2a717c stmdblt r8!, {r1, r5, r6, r8, r10, r11, sp, lr, pc}
 *   @0x2a7188 strb pc, [r7, -r3, ror #28]
 *   @0x2a7194 stmdblt r8!, {r1, r2, r4, r6, r8, r10, r11, sp, lr, pc}
 *   @0x2a71a0 .word 0xe73bff93
 *   @0x2a71b8 stmdblt r8!, {r2, r6, r8, r10, r11, sp, lr, pc}
 *   @0x2a71d0 qasxmi pc, r8, r1
 *   @0x2a71e0 .word 0xf043312c
 *   @0x2a71e4 .word 0xf8c40302
 *   @0x2a71e8 ldr r3, [r7, -r12, lsr #2]
 *   @0x2a71f4 stmdahs r0, {r1, r2, r5, r8, r10, r11, sp, lr, pc}
 *   @0x2a7214 ldreq r8, [r9, r11, lsl #2]
 *   @0x2a7234 stmdblt r8!, {r1, r2, r8, r10, r11, sp, lr, pc}
 *   @0x2a7240 usat pc, #0xb, r1, lsl #29
 *   @0x2a724c ldmiblt r8, {r1, r3, r4, r5, r6, r7, r10, r11, sp, lr, pc} ^
 *   @0x2a7274 .word 0xf8d4f8db
 *   @0x2a7278 .word 0xf8c4312c
 *   @0x2a727c .word 0xf04361d0
 *   @0x2a7280 .word 0xf8c40304
 *   @0x2a7284 sbcs r3, r1, r12, lsr #2
 *   @0x2a7290 stmdblt r8!, {r3, r4, r6, r7, r10, r11, sp, lr, pc}
 *   @0x2a729c ldrt pc, [sp], r1, ror #26
 *   @0x2a72a8 stmdblt r8!, {r2, r3, r6, r7, r10, r11, sp, lr, pc}
 *   @0x2a72b4 .word 0xe6b1f839
 *   @0x2a72c0 stmdblt r8!, {r6, r7, r10, r11, sp, lr, pc}
 *   @0x2a72cc strt pc, [r5], r1, lsr #30
 *   @0x2a72d8 stmdblt r8!, {r2, r4, r5, r7, r10, r11, sp, lr, pc}
 *   @0x2a72e4 .word 0xe699fdd9
 *   @0x2a72f0 stmdblt r8!, {r3, r5, r7, r10, r11, sp, lr, pc}
 *   @0x2a72fc pkhbt pc, sp, r9, lsl #29
 *   @0x2a7308 stmdblt r8!, {r2, r3, r4, r7, r10, r11, sp, lr, pc}
 *   @0x2a7314 str pc, [r1], r9, lsl #30
 *   @0x2a7320 stmdblt r8!, {r4, r7, r10, r11, sp, lr, pc}
 *   @0x2a732c uhadd16 pc, r5, r1
 *   @0x2a7338 stmdblt r8!, {r2, r7, r10, r11, sp, lr, pc}
 *   @0x2a7344 strbt pc, [r9], -r9, lsl #28
 *   @0x2a7350 stmdblt r8!, {r3, r4, r5, r6, r10, r11, sp, lr, pc}
 *   @0x2a735c ldrb pc, [sp], -sp, ror #30
 *   @0x2a7368 stmdblt r8!, {r2, r3, r5, r6, r10, r11, sp, lr, pc}
 *   @0x2a7374 ldrb pc, [r1], -pc, lsl #19
 *   @0x2a7380 stmdblt r8!, {r5, r6, r10, r11, sp, lr, pc}
 *   @0x2a738c strb pc, [r5], -r3, asr #20
 *   @0x2a7398 stmdblt r8!, {r2, r4, r6, r10, r11, sp, lr, pc}
 *   @0x2a73a4 ldrt pc, [r9], -r3, lsr #22
 *   @0x2a73b0 stmdblt r8!, {r3, r6, r10, r11, sp, lr, pc}
 *   @0x2a73bc strt pc, [sp], -r3, ror #17
 *   @0x2a73c8 stmdblt r8!, {r2, r3, r4, r5, r10, r11, sp, lr, pc}
 *   @0x2a73d4 qsub16 pc, r1, sp
 *   @0x2a73e0 stmdblt r8!, {r4, r5, r10, r11, sp, lr, pc}
 *   @0x2a73ec ssub8 pc, r5, pc
 *   @0x2a73f8 stmdblt r8!, {r2, r5, r10, r11, sp, lr, pc}
 *   @0x2a7404 str pc, [r9], -r3, ror #18
 *   @0x2a7410 stmdblt r8!, {r3, r4, r10, r11, sp, lr, pc}
 *   @0x2a741c ldrb pc, [sp, #0xa19]!
 *   @0x2a7428 ldrb pc, [r7, #0xb05]!
 *   @0x2a7430 svclt #0x8ff0
 *
 * ══ §12/13 png_read_png  0x2a7ec0  size 324  24 条（0x2a7ec0..0x2a8004）｜其中 57 条已由别的卡落锚，本节不再重复
 * @func 0x2a7ecc 0x2a7ffc  size 304  24 条
 * 部分覆盖: 本节 24/139 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_read_png+0x24 / png_error / png_set_strip_alpha / 0x4746bc / png_read_png+0x5c / 0x3746c0 / png_set_invert_mono / png_set_shift
 * 字段偏移 top8: 0x8×2 / 0x4×2 / 0x39c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a7ecc .word 0xf7ff8098
 *   @0x2a7ed0 stmdavs r11!, {r0, r1, r2, r3, r7, r11, r12, sp, lr, pc} ^
 *   @0x2a7eec ldreq pc, [r2, r11, asr #18]!
 *   @0x2a7f00 .word 0x06f7fc3e
 *   @0x2a7f08 blhs 0x4746bc <g_RomDisk+0x7ce9c>
 *   @0x2a7f10 blhs 0x3746c0 <_ZTS13C_UTF16String+0xb76c>
 *   @0x2a7f20 .word 0x06b1fc37
 *   @0x2a7f48 ldrbeq pc, [r0, #0xbf7]!
 *   @0x2a7f5c ldrbeq pc, [r2, #-0xbf5]!
 *   @0x2a7f70 strtmi pc, [r0], -r12, asr #24
 *   @0x2a7f78 strtmi pc, [r0], -r7, ror #20
 *   @0x2a7f84 .word 0xf8d5fe1d
 *   @0x2a7f88 ldrshlt r6, [r6, #-8]!
 *   @0x2a7f90 .word 0xf7ff10f8
 *   @0x2a7f94 stmvs r11!, {r0, r2, r4, r6, r10, r11, r12, sp, lr, pc}
 *   @0x2a7fa4 .word 0xf7ff40f8
 *   @0x2a7fa8 stmdavs r9!, {r0, r3, r5, r6, r10, r11, r12, sp, pc} ^
 *   @0x2a7fc4 .word 0xf84220f8
 *   @0x2a7fc8 movwlo r1, #0x1023
 *   @0x2a7fd0 .word 0x260030b8
 *   @0x2a7fe8 .word 0xf7fe70f8
 *   @0x2a7fec strmi pc, [r1], -r3, asr #21
 *   @0x2a7ff4 .word 0xf847fe55
 *   @0x2a7ff8 strlo r0, [r1], -r6, lsr #32
 *
 * ══ §13/13 _spUtil_readFile  0xbd83c  size 4  1 条（0xbd83c..0xbd840）
 * @func 0xbd83c 0xbd840  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbd83c b 0x285cd8 <_readFile>
 */
