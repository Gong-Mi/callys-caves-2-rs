/* cally 逆向卡：All_21 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 4 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/4 anon_300274  0x300274  size 39052  6141 条（0x300274..0x309b00）｜其中 3622 条已由别的卡落锚，本节不再重复
 * @func 0x300274 0x309b00  size 39052  6141 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_300274+0x544 / 0xae6fd0 / 0x47fd28 / 0x47fd10 / 0x47fcf8 / 0x47fce0 / 0x90cfc4 / 0x43857c
 * 字段偏移 top8: 0x8×81 / 0x6×14 / 0xa×7 / 0xc×7 / 0x14×4 / 0x4×4 / 0x18×4 / 0x20×3
 * VFP 指令 70 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x300274 svcmi #0xf0e92d
 *   @0x300278 .word 0xf8d04604
 *   @0x30027c addlt r0, r7, r0, lsr r1
 *   @0x300280 pkhtbmi r4, r8, pc, asr #31
 *   @0x300284 ldrbtmi r2, [pc], #-2048
 *   @0x300288 smulbbhi sp, r0, r2
 *   @0x30028c .word 0xf04f6826
 *   @0x300290 .word 0xf8d40900
 *   @0x300294 cdpvs p0, #0x7, c1, c5, c4, #0x4
 *   @0x300298 .word 0xf7e74628
 *   @0x30029c strtmi pc, [r8], -r12, asr #16
 *   @0x3002a0 ldrsbne pc, [r0], r4
 *   @0x3002a4 addls pc, r4, r4, asr #17
 *   @0x3002a8 .word 0xf845f7e7
 *   @0x3002ac .word 0xf8d44628
 *   @0x3002b0 .word 0xf8c410fc
 *   @0x3002b4 .word 0xf7e79090
 *   @0x3002b8 qasxmi pc, r8, lr
 *   @0x3002bc rscsls pc, r12, r4, asr #17
 *   @0x3002c0 .word 0x1104f8d4
 *   @0x3002c4 rfeda r7!
 *   @0x3002c8 .word 0x012cf8d4
 *   @0x3002cc smlabtls r4, r4, r8, pc
 *   @0x3002d0 .word 0xf7f9b108
 *   @0x3002d4 .word 0xf504fecb
 *   @0x3002d8 .word 0xf10d7a84
 *   @0x3002dc uadd16mi r0, r0, r0
 *   @0x3002e0 mcr2 p7, #0x7, pc, c14, c9, #0x7
 *   @0x3002e4 .word 0x33fff04f
 *   @0x3002e8 teqlo r0, r4, asr #17
 *   @0x3002ec teqlo r4, r4, asr #17
 *   @0x3002f0 .word 0xf7ff6e30
 *   @0x3002f4 .word 0xf8c4ff89
 *   @0x3002f8 strtmi r0, [r8], -r12, lsr #2
 *   @0x3002fc ldrhlo pc, [r8, -r6]
 *   @0x300300 addlo pc, r0, r4, asr #17
 *   @0x300304 ldrhhs pc, [r10, -r6]
 *   @0x300308 addhs pc, r12, r4, asr #17
 *   @0x30030c strbvs r2, [r2, r0, lsl #4]!
 *   @0x300310 addhs pc, r8, r4, asr #17
 *   @0x300314 addshs pc, r4, r4, asr #17
 *   @0x300318 addshs pc, r8, r4, asr #17
 *   @0x30031c addsne pc, r4, #14024704
 *   @0x300320 rscsne pc, r8, r4, asr #17
 *   @0x300324 ldrhne pc, [r6, -r6]
 *   @0x300328 rsbshs pc, r1, r4, lsl #17
 *   @0x30032c rsbshs pc, r2, r4, lsl #17
 *   @0x300330 smlatbne r0, r4, r8, pc
 *   @0x300334 qadd16vs r2, r2, r8
 *   @0x300338 strtvs r6, [r2], r2, ror #12
 *   @0x30033c andls r6, r0, #236978176
 *   @0x300340 andls pc, r4, sp, asr #17
 *   @0x300344 cdp2 p7, #0xa, c15, c3, c7, #0x7
 *   @0x300348 .word 0xf8c49a04
 *   @0x30034c bhs 0x300564 <TT_New_Context+0x35c>
 *   @0x300350 .word 0x8103f040
 *   @0x300354 andeq lr, r4, #9240576
 *   @0x300358 tsths r8, r8, lsr #12
 *   @0x30035c .word 0x308cf8d4
 *   @0x300360 cdp2 p7, #0x9, c15, c5, c7, #0x7
 *   @0x300364 .word 0xf8c49a04
 *   @0x300368 bhs 0x3005b0 <TT_New_Context+0x3a8>
 *   @0x30036c rscshi pc, r5, r0, asr #32
 *   @0x300370 andeq lr, r4, #9240576
 *   @0x300374 .word 0x21044628
 *   @0x300378 ldrsbtlo pc, [r8], #132
 *   @0x30037c cdp2 p7, #0x8, c15, c7, c7, #0x7
 *   @0x300380 .word 0xf8c49a04
 *   @0x300384 bhs 0x30077c <TT_New_Context+0x574>
 *   @0x300388 rschi pc, r7, r0, asr #32
 *   @0x30038c strhlo pc, [r0, -r4]
 *   @0x300390 stm sp, {r3, r5, r9, r10, lr}
 *   @0x300394 .word 0x21040204
 *   @0x300398 cdp2 p7, #0x7, c15, c9, c7, #0x7
 *   @0x30039c .word 0xf8c49b04
 *   @0x3003a0 blhs 0x3007b8 <TT_New_Context+0x5b0>
 *   @0x3003a4 sbcshi pc, r9, r0, asr #32
 *   @0x3003a8 ldrhls pc, [r4, -r6]
 *   @0x3003ac eorhs r4, r4, #26214400
 *   @0x3003b0 .word 0xf1094650
 *   @0x3003b4 movwls r0, #0x3904
 *   @0x3003b8 ldm r10!, {r1, r2, r4, r5, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x3003bc blx 0xae6fd0 <b2_toiTime+0x38db2c>
 *   @0x3003c0 .word 0xf8c4f989
 *   @0x3003c4 .word 0xf10d5108
 *   @0x3003c8 qadd16mi r0, r8, r4
 *   @0x3003cc movwls r4, #0x61a
 *   @0x3003d0 andlt pc, r4, sp, asr #17
 *   @0x3003d4 strbmi r2, [r11], -r8, lsl #2
 *   @0x3003d8 cdp2 p7, #0x5, c15, c9, c7, #0x7
 *   @0x3003dc .word 0xf8c49a05
 *   @0x3003e0 tstlt r10, r4, lsl r1
 *   @0x3003e4 .word 0xf7f94650
 *   @0x3003e8 eors pc, r3, r11, ror #28
 *   @0x3003ec stmdaeq r4, {r0, r2, r3, r7, r11, sp, lr, pc}
 *   @0x3003f0 .word 0x21084628
 *   @0x3003f4 .word 0xf7e7464b
 *   @0x3003f8 bls 0x47fd28 <_ZN10InputQuery13ms_InputText2E+0x938>
 *   @0x3003fc tsteq r8, r4, asr #17
 *   @0x300400 mvnle r2, r0, lsl #20
 *   @0x300404 stmdaeq r4, {r0, r2, r3, r7, r11, sp, lr, pc}
 *   @0x300408 .word 0x21084628
 *   @0x30040c .word 0xf7e7464b
 *   @0x300410 bls 0x47fd10 <_ZN10InputQuery13ms_InputText2E+0x920>
 *   @0x300414 tsteq r12, r4, asr #17
 *   @0x300418 mvnle r2, r0, lsl #20
 *   @0x30041c stmdaeq r4, {r0, r2, r3, r7, r11, sp, lr, pc}
 *   @0x300420 .word 0x21014628
 *   @0x300424 .word 0xf7e7464b
 *   @0x300428 bls 0x47fcf8 <_ZN10InputQuery13ms_InputText2E+0x908>
 *   @0x30042c smlawteq r0, r4, r8, pc
 *   @0x300430 bicsle r2, r7, r0, lsl #20
 *   @0x300434 stm sp, {r0, r1, r4, r9, r10, lr}
 *   @0x300438 strtmi r0, [r8], -r4, lsl #16
 *   @0x30043c .word 0xf7e72102
 *   @0x300440 blls 0x47fce0 <_ZN10InputQuery13ms_InputText2E+0x8f0>
 *   @0x300444 smlawteq r4, r4, r8, pc
 *   @0x300448 bicle r2, r11, r0, lsl #22
 *   @0x30044c smlatbls r12, r4, r8, pc
 *   @0x300450 smlatblo lr, r4, r8, pc
 *   @0x300454 movwls r9, #0x4b05
 *   @0x300458 cmnle lr, r0, lsl #22
 *   @0x30045c .word 0xf1044b69
 *   @0x300460 .word 0xf8a400b4
 *   @0x300464 subhs r9, r4, #16, #2
 *   @0x300468 .word 0xf5b658f9
 *   @0x30046c cdpvs p8, #0x3, c14, c3, c8, #0x5
 *   @0x300470 .word 0xf8d3685b
 *   @0x300474 .word 0xf8c630ac
 *   @0x300478 ldmdblt r11, {r2, r3, r4, r7, r9, r12, sp}
 *   @0x30047c ldmpl r11!, {r1, r5, r6, r8, r9, r11, lr} ^
 *   @0x300480 addslo pc, r12, #12976128
 *   @0x300484 strtmi r6, [r2], -r6, lsr #16
 *   @0x300488 .word 0x512cf8d4
 *   @0x30048c qasxmi r4, r8, r1
 *   @0x300490 .word 0xff74f7f9
 *   @0x300494 .word 0xd1662800
 *   @0x300498 asrseq pc, r5, #17
 *   @0x30049c .word 0x61282340
 *   @0x3004a0 mvnlo pc, r5, asr #17
 *   @0x3004a4 orrmi pc, r0, #1325400064
 *   @0x3004a8 mvneq pc, r5, asr #17
 *   @0x3004ac eorslo pc, r8, #12910592
 *   @0x3004b0 orrlo pc, r0, #1325400064
 *   @0x3004b4 mvneq pc, r5, asr #17
 *   @0x3004b8 mvneq pc, r5, lsl #17
 *   @0x3004bc eorshi pc, r5, #8716288
 *   @0x3004c0 sbcseq pc, r12, r5, lsr #17
 *   @0x3004c4 sbcseq pc, lr, r5, lsr #17
 *   @0x3004c8 rsceq pc, r0, r5, asr #17
 *   @0x3004cc rsceq pc, r4, r5, asr #17
 *   @0x3004d0 smlatbeq r0, r5, r8, pc
 *   @0x3004d4 smlabteq r8, r5, r8, pc
 *   @0x3004d8 smlabtlo r4, r5, r8, pc
 *   @0x3004dc addne pc, r8, #14024704
 *   @0x3004e0 addlo pc, r4, #14024704
 *   @0x3004e4 biceq pc, r8, r5, asr #17
 *   @0x3004e8 bicne pc, r0, r5, asr #17
 *   @0x3004ec biclo pc, r4, r5, asr #17
 *   @0x3004f0 biceq pc, r12, r5, asr #17
 *   @0x3004f4 bicseq pc, r0, r5, asr #17
 *   @0x3004f8 bicseq pc, r4, r5, asr #17
 *   @0x3004fc addhs pc, r4, #14024704
 *   @0x300500 .word 0xf8c5b162
 *   @0x300504 movwhs r3, #0x1170
 *   @0x300508 smulbteq r12, r5, r8
 *   @0x30050c .word 0xf8c54628
 *   @0x300510 .word 0xf8c51168
 *   @0x300514 .word 0xf8d63164
 *   @0x300518 .word 0x4798329c
 *   @0x30051c teqeq r0, r4, asr #17
 *   @0x300520 .word 0xf8d5bb08
 *   @0x300524 .word 0x67e33190
 *   @0x300528 ldrsblo pc, [r12, r5]
 *   @0x30052c addlo pc, r8, r4, asr #17
 *   @0x300530 .word 0x31a8f8d5
 *   @0x300534 addslo pc, r4, r4, asr #17
 *   @0x300538 .word 0x31acf8d5
 *   @0x30053c addslo pc, r8, r4, asr #17
 *   @0x300540 stmne r9!, {r0, r1, r9, r10, lr} ^
 *   @0x300544 .word 0xf50118e2
 *   @0x300548 movwlo r7, #0x81e0
 *   @0x30054c blhs 0x90cfc4 <b2_toiTime+0x1b3b20>
 *   @0x300550 stm r2, {r0, r1, r8, r11, lr, pc}
 *   @0x300554 mvnsle r0, r3
 *   @0x300558 blls 0x43857c <g_RomDisk+0x40d5c>
 *   @0x30055c qadd16mi r11, r0, r3
 *   @0x300560 ldc2l p7, c15, [r2, #996]
 *   @0x300564 stmdahs r0, {r2, r11, r12, pc}
 *   @0x300568 .word 0xf8d4d147
 *   @0x30056c stmdahs r0, {r2, r4, r5, r8}
 *   @0x300570 .word 0xf8d4da43
 *   @0x300574 strhs r9, [r0, #-0x0]
 *   @0x300578 ldrsbtlo pc, [r8], #132
 *   @0x30057c andle r4, r12, #-805306359
 *   @0x300580 addslo pc, r8, #14221312
 *   @0x300584 .word 0xf8d46de1
 *   @0x300588 rfedb r3!
 *   @0x30058c .word 0xf7f80015
 *   @0x300590 .word 0xf846fc3c
 *   @0x300594 strlo r0, [r1, #-0x25]
 *   @0x300598 movwhs lr, #0x7ee
 *   @0x30059c rfeia r4!
 *   @0x3005a0 addmi r1, r11, #16, #2
 *   @0x3005a4 .word 0xf8d4d212
 *   @0x3005a8 sbcseq r0, r9, r4, lsl r1
 *   @0x3005ac eorshs pc, r3, r0, asr #16
 *   @0x3005b0 ldrsbeq pc, [r4, -r4]
 *   @0x3005b4 subvs r4, r2, r8, lsl #8
 *   @0x3005b8 ldrsbeq pc, [r8, -r4]
 *   @0x3005bc eorshs pc, r3, r0, asr #16
 *   @0x3005c0 .word 0xf8d43301
 *   @0x3005c4 strmi r0, [r1], #-280
 *   @0x3005c8 strb r6, [r8, r10, asr #32]!
 *   @0x3005cc ldrmi r2, [r9], -r0, lsl #6
 *   @0x3005d0 strhhs pc, [r0, -r4]
 *   @0x3005d4 andle r4, r5, #805306377
 *   @0x3005d8 .word 0x2104f8d4
 *   @0x3005dc eorne pc, r3, r2, asr #16
 *   @0x3005e0 ldrb r3, [r5, r1, lsl #6]!
 *   @0x3005e4 .word 0xf1044b07
 *   @0x3005e8 subhs r0, r4, #180
 *   @0x3005ec .word 0xf5b558f9
 *   @0x3005f0 strtmi lr, [r0], -r6, ror #31
 *   @0x3005f4 .word 0xf7fe4641
 *   @0x3005f8 .word 0xb007fcd1
 *   @0x3005fc svchi #0xf0e8bd
 *   @0x300600 andeq r1, pc, lr, asr #19
 *   @0x300604 .word 0xffffff88
 *   @0x300608 .word 0xffffff8c
 *   @0x30060c svcmi #0xf0e92d
 *   @0x300610 ldrmi r11, [lr], -r11, asr #1
 *   @0x300614 andls r4, r6, #4, #12
 *   @0x300618 stmdavs r3, {r0, r2, r3, r9, r10, lr} ^
 *   @0x30061c .word 0xf0002900
 *   @0x300620 blhs 0x321124
 *   @0x300624 adcshi pc, lr, #0
 *   @0x300628 .word 0xf8dd691a
 *   @0x30062c ldrmi r12, [r4, #0x18]
 *   @0x300630 .word 0xf8d3d305
 *   @0x300634 blvs 0x178883c <b2_toiTime+0x102f398>
 *   @0x300638 .word 0xf0002a00
 *   @0x30063c .word 0x07b282b5
 *   @0x300640 ldmvs r10, {r3, r8, r10, r12, lr, pc}
 *   @0x300644 svclt #0x480497
 *   @0x300648 streq pc, [r2], -r6, lsr #32
 *   @0x30064c svclt #0x480430
 *   @0x300650 streq pc, [r2], -r6, asr #32
 *   @0x300654 andmi pc, r1, #64, #4
 *   @0x300658 teqlt r2, r2, lsr r0
 *   @0x30065c ldreq r6, [r9], #2203
 *   @0x300660 .word 0xf046bf4c
 *   @0x300664 .word 0xf0460609
 *   @0x300668 svcvs #0x69060b
 *   @0x30066c andeq pc, r2, r6, lsl r0
 *   @0x300670 .word 0xf105bf14
 *   @0x300674 .word 0xf105030c
 *   @0x300678 mcrrne p3, #0x3, r0, r10, c0
 *   @0x30067c rscvs r9, r11, #7
 *   @0x300680 addshi pc, r0, r0
 *   @0x300684 .word 0xf1000733
 *   @0x300688 stmdavs r0!, {r0, r2, r3, r7, pc} ^
 *   @0x30068c adcslo pc, r12, #144, #16
 *   @0x300690 .word 0xf0002b00
 *   @0x300694 .word 0xf8d08087
 *   @0x300698 svcge #0x15221c
 *   @0x30069c strls r6, [r2, -r3, lsl #29]
 *   @0x3006a0 .word 0xf1049300
 *   @0x3006a4 movwls r0, #0x134c
 *   @0x3006a8 .word 0xf8d24633
 *   @0x3006ac bls 0x4b07d4 <SrcVerts+0xd818>
 *   @0x3006b0 stmdahs r0, {r5, r6, r7, r8, r9, r10, lr}
 *   @0x3006b4 rfeia sp!
 *   @0x3006b8 .word 0xf0163056
 *   @0x3006bc rfeib sp!
 *   @0x3006c0 .word 0xf8a42058
 *   @0x3006c4 b 0x16c0884 <b2_toiTime+0xf673e0>
 *   @0x3006c8 .word 0x61a31383
 *   @0x3006cc ldrhlo pc, [r4], #-141
 *   @0x3006d0 rsbeq pc, r12, r4, lsr #17
 *   @0x3006d4 ldrheq pc, [lr], #-157
 *   @0x3006d8 orrne lr, r3, #323584
 *   @0x3006dc b 0x16d8e70 <b2_toiTime+0xf7f9cc>
 *   @0x3006e0 eorvs r1, r3, #134217730
 *   @0x3006e4 ldrhlo pc, [r10], #-157
 *   @0x3006e8 .word 0x8004f8d4
 *   @0x3006ec uqadd16vs r11, r0, r8
 *   @0x3006f0 orrne lr, r3, pc, asr #20
 *   @0x3006f4 rfeia sp!
 *   @0x3006f8 svclt #0x4105c
 *   @0x3006fc strtvs r6, [r3], r2, ror #12
 *   @0x300700 orrne lr, r1, pc, asr #20
 *   @0x300704 b 0x16d9190 <b2_toiTime+0xf7fcec>
 *   @0x300708 rscvs r1, r1, #128, #2
 *   @0x30070c strhtne pc, [r0], #-157
 *   @0x300710 vstmiane r1, {s28, s29, s30, s31}
 *   @0x300714 eorsgt pc, r0, r4, asr #17
 *   @0x300718 strhtgt pc, [r2], #-141
 *   @0x30071c ssatvs r11, #0x2, r8, lsl #30
 *   @0x300720 vstmiane r12, {s28, s29, s30, s31}
 *   @0x300724 eorsgt pc, r4, r4, asr #17
 *   @0x300728 ldrgt pc, [r8], #2271
 *   @0x30072c subgt pc, r8, r4, asr #17
 *   @0x300730 .word 0x3008f8d8
 *   @0x300734 strle r0, [r1], #-2011
 *   @0x300738 eors r2, r10, #0
 *   @0x30073c .word 0x9068f8d8
 *   @0x300740 sbcshs r2, r4, #0, #2
 *   @0x300744 .word 0xf5b54638
 *   @0x300748 stmdbls r6, {r2, r4, r5, r8, r9, r10, r11, sp, lr, pc}
 *   @0x30074c movwhs r2, #0x1200
 *   @0x300750 sasxls r4, r9, r8
 *   @0x300754 subshi pc, r4, sp, asr #17
 *   @0x300758 ldrls r9, [r7], #-1302
 *   @0x30075c rsbls pc, r12, sp, asr #17
 *   @0x300760 .word 0xff8cf7fe
 *   @0x300764 .word 0x21009b15
 *   @0x300768 sbceq pc, r12, r7, lsl #2
 *   @0x30076c .word 0x460b6e5a
 *   @0x300770 .word 0xf9d8f7e8
 *   @0x300774 stmdals r4!, {r0, r6, r8, r9, r11, r12, pc}
 *   @0x300778 bvs 0xfebd970c <b2_toiTime+0xfffffffffe480268>
 *   @0x30077c stmdblt r11!, {r5, r7, r8, r9, sp, lr}
 *   @0x300780 bvs 0xffdecc08 <b2_toiTime+0xffffffffff693764>
 *   @0x300784 .word 0xf7f86859
 *   @0x300788 adcvs pc, r0, #64, #22
 *   @0x30078c vmlshs.f64 d6, d0, d22
 *   @0x300790 blvs 0xffb34ee0 <b2_toiTime+0xffffffffff3dba3c>
 *   @0x300794 sbcle r2, pc, r0, lsl #16
 *   @0x300798 ldmvs r9, {r0, r1, r3, r5, r6, r7, r9, r11, sp, lr}
 *   @0x30079c blx 0x107e786 <b2_toiTime+0x9252e2>
 *   @0x3007a0 strb r6, [r9, r0, ror #6]
 *   @0x3007a4 .word 0x0101f016
 *   @0x3007a8 .word 0xd104910a
 *   @0x3007ac .word 0x3070f895
 *   @0x3007b0 .word 0xf0002b00
 *   @0x3007b4 .word 0xf41681f5
 *   @0x3007b8 .word 0xf0404180
 *   @0x3007bc .word 0xf8d481f5
 *   @0x3007c0 .word 0xf10d9004
 *   @0x3007c4 sbcshs r0, r4, #84, #24
 *   @0x3007c8 eorgt pc, r0, sp, asr #17
 *   @0x3007cc .word 0xf8d94660
 *   @0x3007d0 .word 0xf8d93068
 *   @0x3007d4 movwls r8, #0xb060
 *   @0x3007d8 mcr p5, #0x7, pc, c10, c5, #0x5
 *   @0x3007dc stmdahs r0, {r0, r1, r2, r11, r12, pc}
 *   @0x3007e0 adchi pc, r2, r0, asr #32
 *   @0x3007e4 ldrsbhs pc, [r0, -r5]!
 *   @0x3007e8 cmneq pc, #38
 *   @0x3007ec sbcslt r2, r11, #0, #20
 *   @0x3007f0 blle 0x3e541c <error_g0017+0x3e0c0>
 *   @0x3007f4 ldrsblo pc, [r4, -r5]!
 *   @0x3007f8 ble 0x58b400 <g_SWFlineaavertbuff+0x38338>
 *   @0x3007fc stmdbls r9, {r3, r5, r9, r10, lr}
 *   @0x300800 ldc2 p7, c15, [r8, #-1020]!
 *   @0x300804 .word 0xf0402800
 *   @0x300808 .word 0xf8d581d4
 *   @0x30080c ldmdblt pc!, {r2, r3, r5, r8, r12, sp, lr}
 *   @0x300810 bhs 0x338f48
 *   @0x302e38 .word 0xf5b34640
 *   @0x302e3c .word 0x4606eb7e
 *   @0x302e40 stchs p12, c1, [r0, #-272]
 *   @0x302e44 .word 0x81bcf000
 *   @0x302e48 .word 0xf0c042a7
 *   @0x302e4c .word 0x462881bc
 *   @0x302e50 ldrtmi r4, [r2], -r1, asr #12
 *   @0x302e54 bl 0xfefc0528 <b2_toiTime+0xfffffffffe867084>
 *   @0x302e58 strpl r2, [r11, #0x300]!
 *   @0x302e5c stchs p1, c14, [r0, #-704]
 *   @0x302e60 bicshi pc, r0, r0
 *   @0x302e64 vmax.f32 d18, d0, d3
 *   @0x302e68 .word 0xf8d681cf
 *   @0x302e6c strhs r3, [r4], #-404
 *   @0x302e70 .word 0xe1a8602b
 *   @0x302e74 .word 0x11a0f8d6
 *   @0x302e78 sasxmi r11, r0, r9
 *   @0x302e7c blx 0x1bc0e0c <b2_toiTime+0x1467968>
 *   @0x302e80 .word 0xf0002800
 *   @0x302e84 stmdavs r2, {r0, r1, r4, r5, r9, pc}
 *   @0x302e88 .word 0xf8d6e004
 *   @0x302e8c addsmi r3, r10, #148, #2
 *   @0x302e90 eorhi pc, r12, #128
 *   @0x302e94 ldrsblo pc, [r12, r6]
 *   @0x302e98 .word 0xf8530091
 *   @0x302e9c .word 0xf1088022
 *   @0x302ea0 stchs p4, c0, [r0, #-4]
 *   @0x302ea4 orrhi pc, r12, r0
 *   @0x302ea8 .word 0xf0c042a7
 *   @0x302eac .word 0xf8d6818c
 *   @0x302eb0 ldmdapl r9, {r3, r4, r7, r8, r12, sp} ^
 *   @0x302eb4 strbmi r4, [r2], -r8, lsr #12
 *   @0x302eb8 bl 0xfe34058c <b2_toiTime+0xfffffffffdbe70e8>
 *   @0x302ebc .word 0xf8052300
 *   @0x302ec0 cmn sp, r8
 *   @0x302ec4 .word 0xf0002d00
 *   @0x302ec8 svchs #0x181a1
 *   @0x302ecc asrhi pc, r0, #4
 *   @0x302ed0 strhlo pc, [r0, -r6]!
 *   @0x302ed4 eorhi r2, r11, r2, lsl #8
 *   @0x302ed8 stchs p1, c14, [r0, #-468]
 *   @0x302edc orrshi pc, r10, r0
 *   @0x302ee0 vmax.f32 d18, d0, d1
 *   @0x302ee4 rfeia r6!
 *   @0x302ee8 strhs r3, [r2], #-290
 *   @0x302eec .word 0xe16a802b
 *   @0x302ef0 .word 0xf0002d00
 *   @0x302ef4 svchs #0x8193
 *   @0x302ef8 orrshi pc, r2, r0
 *   @0x302efc umlalslo pc, r0, r6, r8
 *   @0x302f00 eorvc r2, r11, r1, lsl #8
 *   @0x302f04 .word 0xf896e15f
 *   @0x302f08 addsmi r3, r10, #176
 *   @0x302f0c mvnhi pc, r0, lsl #1
 *   @0x302f10 .word 0xf0002d00
 *   @0x302f14 svchs #0x18187
 *   @0x302f18 orrhi pc, r6, r0, asr #4
 *   @0x302f1c strbeq lr, [r2], -r6, lsl #22
 *   @0x302f20 rfeia r6!
 *   @0x302f24 strhthi r3, [r11], -r4
 *   @0x302f28 stchs p1, c14, [r0, #-308]
 *   @0x302f2c cmnhi lr, r0
 *   @0x302f30 vmax.f32 d18, d0, d3
 *   @0x302f34 .word 0xf8d6817d
 *   @0x302f38 strhs r3, [r4], #-276
 *   @0x302f3c .word 0xe142602b
 *   @0x302f40 .word 0xf0002d00
 *   @0x302f44 svchs #0x38177
 *   @0x302f48 cmnhi r6, r0, asr #4
 *   @0x302f4c ldrsblo pc, [r12, -r6]
 *   @0x302f50 eorvs r2, r11, r4, lsl #8
 *   @0x302f54 stchs p1, c14, [r0, #-220]
 *   @0x302f58 cmnhi r0, r0
 *   @0x302f5c vmax.f32 d18, d0, d3
 *   @0x302f60 .word 0xf8d6816f
 *   @0x302f64 strhs r3, [r4], #-280
 *   @0x302f68 .word 0xe12c602b
 *   @0x302f6c .word 0xf0002d00
 *   @0x302f70 svchs #0x8169
 *   @0x302f74 msrhi SPSR_f, r0
 *   @0x302f78 umlalslo pc, r1, r6, r8
 *   @0x302f7c eorvc r2, r11, r1, lsl #8
 *   @0x302f80 .word 0xf896e121
 *   @0x302f84 addsmi r3, r10, #177
 *   @0x302f88 lslshi pc, r0, #1
 *   @0x302f8c .word 0xf0002d00
 *   @0x302f90 svchs #0x1815d
 *   @0x302f94 cmphi r12, r0, asr #4
 *   @0x302f98 strbeq lr, [r2], -r6, lsl #22
 *   @0x302f9c rfeia r6!
 *   @0x302fa0 .word 0x802b30d0
 *   @0x302fa4 stchs p1, c14, [r0, #-60]
 *   @0x302fa8 cmphi r4, r0
 *   @0x302fac .word 0xf0002f00
 *   @0x302fb0 .word 0xf8968153
 *   @0x302fb4 strhs r3, [r1], #-178
 *   @0x302fb8 .word 0xe104702b
 *   @0x302fbc umlalslo pc, r2, r6, r8
 *   @0x302fc0 .word 0xf080429a
 *   @0x302fc4 stchs p1, c8, [r0, #-588]
 *   @0x302fc8 mrshi pc, spsr
 *   @0x302fcc vmax.f32 d18, d0, d1
 *   @0x302fd0 bl 0x4a34f4 <SrcVerts+0x538>
 *   @0x302fd4 strhs r0, [r2], #-1602
 *   @0x302fd8 strhtlo pc, [r4], #134
 *   @0x302fdc rscs r8, r2, r11, lsr #32
 *   @0x302fe0 .word 0xf0002d00
 *   @0x302fe4 svchs #0x813f
 *   @0x302fe8 teqhi lr, r0
 *   @0x302fec umlalslo pc, r3, r6, r8
 *   @0x302ff0 eorvc r2, r11, r1, lsl #8
 *   @0x302ff4 .word 0xf896e0e7
 *   @0x302ff8 addsmi r3, r10, #179
 *   @0x302ffc cmnhi r6, r0, lsl #1
 *   @0x303000 .word 0xf0002d00
 *   @0x303004 svchs #0x18133
 *   @0x303008 teqhi r2, r0, asr #4
 *   @0x30300c strbeq lr, [r2], -r6, lsl #22
 *   @0x303010 rfeia r6!
 *   @0x303014 eorhi r3, r11, r0, lsl #2
 *   @0x303018 stchs p0, c14, [r0, #-852]
 *   @0x30301c msrhi CPSR_fx, r0
 *   @0x303020 .word 0xf0002f00
 *   @0x303024 .word 0xf8968129
 *   @0x303028 strhs r3, [r1], #-292
 *   @0x30302c sbc r7, r10, r11, lsr #32
 *   @0x303030 .word 0x3124f896
 *   @0x303034 .word 0xf080429a
 *   @0x303038 stchs p1, c8, [r0, #-356]
 *   @0x30303c tsthi lr, r0
 *   @0x303040 vmax.f32 d18, d0, d1
 *   @0x303044 bl 0x4a34c0 <SrcVerts+0x504>
 *   @0x303048 strhs r0, [r2], #-1602
 *   @0x30304c strhlo pc, [r8, -r6]!
 *   @0x303050 adcs r8, r8, r11, lsr #32
 *   @0x303054 .word 0xf0002d00
 *   @0x303058 svchs #0x8115
 *   @0x30305c tsthi r4, r0
 *   @0x303060 .word 0x3125f896
 *   @0x303064 eorvc r2, r11, r1, lsl #8
 *   @0x303068 .word 0xf896e0ad
 *   @0x30306c addsmi r3, r10, #1073741833
 *   @0x303070 teqhi r12, r0, lsl #1
 *   @0x303074 .word 0xf0002d00
 *   @0x303078 svchs #0x18109
 *   @0x30307c .word 0x8108f240
 *   @0x303080 strbeq lr, [r2], -r6, lsl #22
 *   @0x303084 rfeia r6!
 *   @0x303088 eorhi r3, r11, r2, asr #2
 *   @0x30308c stchs p0, c14, [r0, #-620]
 *   @0x303090 .word 0x8100f000
 *   @0x303094 .word 0xf0002f00
 *   @0x303098 .word 0xf89680ff
 *   @0x30309c strhs r3, [r1], #-295
 *   @0x3030a0 adds r7, r0, r11, lsr #32
 *   @0x3030a4 .word 0xf0002d00
 *   @0x3030a8 svchs #0x80f9
 *   @0x3030ac rscshi pc, r8, r0
 *   @0x3030b0 .word 0x3126f896
 *   @0x3030b4 eorvc r2, r11, r1, lsl #8
 *   @0x3030b8 bhs 0x37b2d4 <_ZTS13C_UTF16String+0x12380>
 *   @0x3030bc tsthi r6, r0, lsl #4
 *   @0x3030c0 .word 0xf0002d00
 *   @0x3030c4 svchs #0x180ef
 *   @0x3030c8 rschi pc, lr, r0, asr #4
 *   @0x3030cc strbeq lr, [r2], -r6, lsl #22
 *   @0x3030d0 rfeia r6!
 *   @0x3030d4 eorhi r3, r11, r8, ror #2
 *   @0x3030d8 stchs p0, c14, [r0, #-468]
 *   @0x3030dc rschi pc, r6, r0
 *   @0x3030e0 vmax.f32 d18, d0, d3
 *   @0x3030e4 .word 0xf8d680e5
 *   @0x3030e8 strhs r3, [r4], #-172
 *   @0x3030ec rsb r6, r10, r11, lsr #32
 *   @0x3030f0 .word 0xf0002d00
 *   @0x3030f4 svchs #0x380df
 *   @0x3030f8 sbcshi pc, lr, r0, asr #4
 *   @0x3030fc .word 0x3164f8d6
 *   @0x303100 eorvs r2, r11, r4, lsl #8
 *   @0x303104 stchs p0, c14, [r0, #-380]
 *   @0x303108 sbcshi pc, r8, r0
 *   @0x30310c vmax.f32 d18, d0, d3
 *   @0x303110 .word 0xf8d680d7
 *   @0x303114 strhs r3, [r4], #-352
 *   @0x303118 subs r6, r4, r11, lsr #32
 *   @0x30311c .word 0xf0002d00
 *   @0x303120 svchs #0x80d1
 *   @0x303124 sbcshi pc, r0, r0
 *   @0x303128 umullslo pc, r12, r6, r8
 *   @0x30312c eorvc r2, r11, r1, lsl #8
 *   @0x303130 stchs p0, c14, [r0, #-292]
 *   @0x303134 sbchi pc, r10, r0
 *   @0x303138 vmax.f32 d18, d0, d1
 *   @0x30313c rfeia r6!
 *   @0x303140 strhs r3, [r2], #-158
 *   @0x303144 eors r8, lr, r11, lsr #32
 *   @0x303148 .word 0xf0002d00
 *   @0x30314c svchs #0x180c3
 *   @0x303150 sbchi pc, r2, r0, asr #4
 *   @0x303154 .word 0x30a0f8b6
 *   @0x303158 eorhi r2, r11, r2, lsl #8
 *   @0x30315c stchs p0, c14, [r0, #-204]
 *   @0x303160 adcshi pc, r12, r0
 *   @0x303164 vmax.f32 d18, d0, d1
 *   @0x303168 rfeia r6!
 *   @0x30316c strhs r3, [r2], #-164
 *   @0x303170 eor r8, r8, r11, lsr #32
 *   @0x303174 .word 0x6084f8d6
 *   @0x303178 .word 0xf8d6e00a
 *   @0x30317c and r6, r7, r8, lsl #1
 *   @0x303180 .word 0x608cf8d6
 *   @0x303184 .word 0xf8d6e004
 *   @0x303188 mul r1, r0, r0
 *   @0x30318c ldrsbvs pc, [r4], r6
 *   @0x303190 .word 0xf5b34630
 *   @0x303194 mcrrne p9, #0xd, lr, r4, c2
 *   @0x303198 adcmi r11, r7, #1073741861
 *   @0x30319c qadd16mi sp, r8, r3
 *   @0x3031a0 qasxmi r4, r2, r1
 *   @0x3031a4 b 0x5c0878 <g_SWFlineaavertbuff+0x6d7b0>
 *   @0x3031a8 stchs p0, c14, [r0, #-40]
 *   @0x3031ac addshi pc, r10, r0
 *   @0x3031b0 vmax.f32 d18, d0, d3
 *   @0x3031b4 .word 0xf8d68099
 *   @0x3031b8 strhs r3, [r4], #-152
 *   @0x3031bc and r6, r2, r11, lsr #32
 *   @0x3031c0 .word 0xf0002c00
 *   @0x3031c4 qadd8mi r8, r0, r3
 *   @0x3031c8 ldrhhi lr, [r0, #141]!
 *   @0x3031cc ldrb r2, [r10, r1, lsl #8]!
 *   @0x3031d0 ldrb r2, [r8, r1, lsl #8]!
 *   @0x3031d4 ldrb r2, [r6, r4, lsl #8]!
 *   @0x3031d8 ldrb r2, [r4, r4, lsl #8]!
 *   @0x3031dc ldrb r2, [r2, r4, lsl #8]!
 *   @0x3031e0 ldrb r2, [r0, r4, lsl #8]!
 *   @0x3031e4 strb r2, [lr, r1, lsl #8]!
 *   @0x3031e8 strb r2, [r12, r1, lsl #8]!
 *   @0x3031ec strb r2, [r10, r4, lsl #8]!
 *   @0x3031f0 strb r2, [r8, r4, lsl #8]!
 *   @0x3031f4 strb r2, [r6, r4, lsl #8]!
 *   @0x3031f8 strb r2, [r4, r4, lsl #8]!
 *   @0x3031fc strb r2, [r2, r4, lsl #8]!
 *   @0x303200 strb r2, [r0, r4, lsl #8]!
 *   @0x303204 ldrb r2, [lr, r4, lsl #8]
 *   @0x303208 ldrb r2, [r12, r4, lsl #8]
 *   @0x30320c ldrb r2, [r10, r2, lsl #8]
 *   @0x303210 ldrb r2, [r8, r2, lsl #8]
 *   @0x303214 ldrb r2, [r6, r2, lsl #8]
 *   @0x303218 ldrb r2, [r4, r2, lsl #8]
 *   @0x30321c ldrb r2, [r2, r1, lsl #8]
 *   @0x303220 ldrb r2, [r0, r1, lsl #8]
 *   @0x303224 strb r2, [lr, r2, lsl #8]
 *   @0x303228 strb r2, [r12, r2, lsl #8]
 *   @0x30322c strb r2, [r10, r4, lsl #8]
 *   @0x303230 strb r2, [r8, r4, lsl #8]
 *   @0x303234 strb r2, [r6, r4, lsl #8]
 *   @0x303238 strb r2, [r4, r4, lsl #8]
 *   @0x30323c strb r2, [r2, r4, lsl #8]
 *   @0x303240 strb r2, [r0, r4, lsl #8]
 *   @0x303244 ldr r2, [lr, r1, lsl #8]!
 *   @0x303248 ldr r2, [r12, r1, lsl #8]!
 *   @0x30324c ldr r2, [r10, r2, lsl #8]!
 *   @0x303250 ldr r2, [r8, r2, lsl #8]!
 *   @0x303254 ldr r2, [r6, r1, lsl #8]!
 *   @0x303258 ldr r2, [r4, r1, lsl #8]!
 *   @0x30325c ldr r2, [r2, r2, lsl #8]!
 *   @0x303260 ldr r2, [r0, r2, lsl #8]!
 *   @0x303264 str r2, [lr, r1, lsl #8]!
 *   @0x303268 str r2, [r12, r1, lsl #8]!
 *   @0x30326c str r2, [r10, r2, lsl #8]!
 *   @0x303270 str r2, [r8, r2, lsl #8]!
 *   @0x303274 str r2, [r6, r1, lsl #8]!
 *   @0x303278 str r2, [r4, r1, lsl #8]!
 *   @0x30327c str r2, [r2, r2, lsl #8]!
 *   @0x303280 str r2, [r0, r2, lsl #8]!
 *   @0x303284 ldr r2, [lr, r1, lsl #8]
 *   @0x303288 ldr r2, [r12, r1, lsl #8]
 *   @0x30328c ldr r2, [r10, r2, lsl #8]
 *   @0x303290 ldr r2, [r8, r2, lsl #8]
 *   @0x303294 ldr r2, [r6, r1, lsl #8]
 *   @0x303298 ldr r2, [r4, r1, lsl #8]
 *   @0x30329c ldr r2, [r2, r1, lsl #8]
 *   @0x3032a0 ldr r2, [r0, r1, lsl #8]
 *   @0x3032a4 str r2, [lr, r2, lsl #8]
 *   @0x3032a8 str r2, [r12, r2, lsl #8]
 *   @0x3032ac str r2, [r10, r4, lsl #8]
 *   @0x3032b0 str r2, [r8, r4, lsl #8]
 *   @0x3032b4 str r2, [r6, r4, lsl #8]
 *   @0x3032b8 str r2, [r4, r4, lsl #8]
 *   @0x3032bc str r2, [r2, r4, lsl #8]
 *   @0x3032c0 str r2, [r0, r4, lsl #8]
 *   @0x3032c4 ldrb r2, [lr, -r1, lsl #8]!
 *   @0x3032c8 ldrb r2, [r12, -r1, lsl #8]!
 *   @0x3032cc ldrb r2, [r10, -r2, lsl #8]!
 *   @0x3032d0 ldrb r2, [r8, -r2, lsl #8]!
 *   @0x3032d4 ldrb r2, [r6, -r2, lsl #8]!
 *   @0x3032d8 ldrb r2, [r4, -r2, lsl #8]!
 *   @0x3032dc ldrb r2, [r2, -r2, lsl #8]!
 *   @0x3032e0 ldrb r2, [r0, -r2, lsl #8]!
 *   @0x3032e4 strb r2, [lr, -r4, lsl #8]!
 *   @0x3032e8 strb r2, [r12, -r4, lsl #8]!
 *   @0x3032ec rscslo pc, pc, pc, asr #32
 *   @0x3032f0 ldrhhi lr, [r0, #141]!
 *   @0x3032f4 .word 0xf8d0b510
 *   @0x3032f8 ldrmi r4, [r0], -r8, lsr #3
 *   @0x3032fc .word 0xf854461a
 *   @0x303300 .word 0xf7e51021
 *   @0x303304 .word 0x2000faf0
 *   @0x303308 bhs 0x372750 <_ZTS13C_UTF16String+0x97fc>
 *   @0x30330c stmdavs r3, {r4, r5, r6, r7, r8, r10, r12, sp, pc} ^
 *   @0x303310 andvs sp, r11, r1, lsl #2
 *   @0x303314 bhs 0x3b2adc <error_g0017+0xb780>
 *   @0x303318 smlabtle r6, r4, r8, r6
 *   @0x30331c andvs r4, r11, r3, lsr #8
 *   @0x303320 stmvs r3, {r1, r6, r7, r11, sp, lr}
 *   @0x303324 subvs r4, r11, r3, lsl r4
 *   @0x303328 bhs 0x3f2af0 <SVS_VertexShader+0x1b8>
 *   @0x30332c stmdbvs r2, {r0, r2, r6, r7, r8, r11, sp, lr} ^
 *   @0x303330 strtmi sp, [r10], #-276
 *   @0x303334 strtmi r4, [r3], #-1044
 *   @0x303338 stmibvs r3, {r0, r1, r3, sp, lr}
 *   @0x30333c ldrmi r6, [r10], #-2498
 *   @0x303340 ldrmi r6, [r10], #-2243
 *   @0x303344 ldrmi r6, [r3], #-2179
 *   @0x303348 stmibvs r3, {r0, r1, r3, r6, sp, lr}
 *   @0x30334c ldrmi r6, [r10], #-2498
 *   @0x303350 stmdbvs r0, {r0, r1, r6, r8, r11, sp, lr}
 *   @0x303354 strmi r4, [r3], #-1043
 *   @0x303358 ldcllt p0, c6, [r0, #556]!
 *   @0x30335c blvs 0xff4de07c <b2_toiTime+0xfffffffffed84bd8>
 *   @0x303360 bvs 0xff494444 <b2_toiTime+0xfffffffffed3afa0>
 *   @0x303364 bvs 0x1494448 <b2_toiTime+0xd3afa4>
 *   @0x303368 ldrtmi r4, [r5], #-1086
 *   @0x30336c ldrmi r4, [r4], #-1066
 *   @0x303370 andvs r4, r11, r3, lsr #8
 *   @0x303374 blvs 0xff39e188 <b2_toiTime+0xfffffffffec44ce4>
 *   @0x303378 bvs 0xff3d43e8 <b2_toiTime+0xfffffffffec7af44>
 *   @0x30337c bvs 0xfe3d43ec <b2_toiTime+0xfffffffffdc7af48>
 *   @0x303380 stmibvs r3, {r1, r3, r4, r10, lr} ^
 *   @0x303384 stmibvs r3, {r1, r3, r4, r10, lr}
 *   @0x303388 stmvs r3, {r1, r3, r4, r10, lr} ^
 *   @0x30338c stmvs r3, {r1, r3, r4, r10, lr}
 *   @0x303390 subvs r4, r11, r3, lsl r4
 *   @0x303394 blvs 0xff39e1a8 <b2_toiTime+0xfffffffffec44d04>
 *   @0x303398 blvs 0x13d4408 <b2_toiTime+0xc7af64>
 *   @0x30339c blvs 0x3d440c <error_g0017+0x2d0b0>
 *   @0x3033a0 stmibvs r3, {r1, r3, r4, r10, lr} ^
 *   @0x3033a4 stmibvs r3, {r1, r3, r4, r10, lr}
 *   @0x3033a8 stmdbvs r3, {r1, r3, r4, r10, lr} ^
 *   @0x3033ac stmdbvs r3, {r1, r3, r4, r10, lr}
 *   @0x3033b0 addvs r4, r11, r3, lsl r4
 *   @0x3033b4 blvs 0xff39e1c8 <b2_toiTime+0xfffffffffec44d24>
 *   @0x3033b8 blvs 0x13d4428 <b2_toiTime+0xc7af84>
 *   @0x3033bc blvs 0x3d442c <error_g0017+0x2d0d0>
 *   @0x3033c0 bvs 0xff3d4430 <b2_toiTime+0xfffffffffec7af8c>
 *   @0x3033c4 bvs 0xfe3d4434 <b2_toiTime+0xfffffffffdc7af90>
 *   @0x3033c8 bvs 0x13d4438 <b2_toiTime+0xc7af94>
 *   @0x3033cc bvs 0x394420 <ft_adobe_glyph_list+0x3afc>
 *   @0x3033d0 sbcvs r4, r11, r3, lsl r4
 *   @0x3033d4 ldrblt r11, [r0, #0xdf0]!
 *   @0x3033d8 .word 0xf8d0460d
 *   @0x3033dc addlt r4, r5, r4, lsl r2
 *   @0x3033e0 mvnlt r4, r6, lsl r6
 *   @0x3033e4 .word 0x0088f8d4
 *   @0x3033e8 stmdavs r2!, {r0, r3, r5, r6, r9, r10, lr} ^
 *   @0x3033ec .word 0xf7ff466f
 *   @0x3033f0 stmdavs r3!, {r2, r3, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x3033f4 addsmi r2, sp, #0
 *   @0x3033f8 qasxmi r11, r11, r8
 *   @0x3033fc addmi r0, r8, #153
 *   @0x303400 ldmdapl r10!, {r0, r1, r12, lr, pc}
 *   @0x303404 andlo r5, r4, r2, lsr r0
 *   @0x303408 .word 0xf44fe7f9
 *   @0x30340c adcmi r4, r11, #0, #4
 *   @0x303410 .word 0xf846d203
 *   @0x303414 movwlo r2, #0x1023
 *   @0x303418 strdhs lr, pc, [r0], -r9
 *   @0x30341c andhs lr, r6, r0
 *   @0x303420 ldcllt p0, c11, [r0, #20]!
 *   @0x303424 mvnsmi lr, #737280
 *   @0x303428 .word 0xf8d0460f
 *   @0x30342c addlt r4, r5, r4, lsl r2
 *   @0x303430 tstlt r4, #144, #12
 *   @0x303434 .word 0x0088f8d4
 *   @0x303438 stmdavs r2!, {r0, r3, r5, r6, r9, r10, lr} ^
 *   @0x30343c .word 0xf7ff3458
 *   @0x303440 .word 0xf854ff64
 *   @0x303444 usatmi r5, #0x9, r4, asr #24
 *   @0x303448 adcmi r2, pc, #0, #12
 *   @0x30344c shasxmi r11, sp, r8
 *   @0x303450 andle r4, r9, lr, lsr #5
 *   @0x303454 .word 0xf8594620
 *   @0x303458 .word 0xf7ff1026
 *   @0x30345c strlo pc, [r12], #-2839
 *   @0x303460 eoreq pc, r6, r8, asr #16
 *   @0x303464 ldrb r3, [r3, r1, lsl #12]!
 *   @0x303468 adcsmi r2, sp, #0, #6
 *   @0x30346c .word 0xf848d203
 *   @0x303470 strlo r3, [r1, #-0x25]
 *   @0x303474 strdhs lr, pc, [r0], -r9
 *   @0x303478 andhs lr, r6, r0
 *   @0x30347c pop {r0, r2, r12, sp, pc}
 *   @0x303480 strdeq r8, r9, [r0], -r0
 *   @0x303484 svcmi #0xf0e92d
 *   @0x303488 mcrge p0, #0x0, r11, c10, c9, #0x4
 *   @0x30348c .word 0x91006e45
 *   @0x303490 .word 0xf8d04631
 *   @0x303494 .word 0xf7fd4214
 *   @0x303498 andls pc, r5, r4, lsl #24
 *   @0x30349c .word 0xf0402800
 *   @0x3034a0 stmdbls r10, {r1, r2, r4, r7, pc}
 *   @0x3034a4 qadd16mi r2, r8, r8
 *   @0x3034a8 cmnmi r9, #20480
 *   @0x3034ac .word 0xf7e33114
 *   @0x3034b0 stcls p14, c15, [r5, #-232]
 *   @0x3034b4 stchs p6, c4, [r0, #-520]
 *   @0x3034b8 addhi pc, r9, r0, asr #32
 *   @0x3034bc ldrtmi r9, [r11], r10, lsl #20
 *   @0x3034c0 ldrtmi r4, [r1], r8, asr #22
 *   @0x3034c4 ldrblo pc, [pc, pc, asr #32]!
 *   @0x3034c8 ldrbtmi r6, [r11], #-133
 *   @0x3034cc movwls r6, #0x1002
 *   @0x3034d0 bls 0x5d61ec <g_SWFaavertbuff+0x3124>
 *   @0x3034d4 movwls r4, #0x247b
 *   @0x3034d8 subvs r4, r2, r4, asr #22
 *   @0x3034dc andseq pc, r4, #0, #2
 *   @0x3034e0 sbcvs r4, r2, r11, ror r4
 *   @0x3034e4 movwls r6, #0x3105
 *   @0x3034e8 addmi r9, sp, #163840
 *   @0x3034ec blx 0x5f7e22 <g_SWFaavertbuff+0x24d5a>
 *   @0x3034f0 .word 0xf8d9fc05
 *   @0x3034f4 .word 0xf8da0008
 *   @0x3034f8 .word 0xf841100c
 *   @0x3034fc .word 0xf8da000c
 *   @0x303500 bl 0x347538
 *   @0x303504 .word 0xf8d9000c
 *   @0x303508 streq r1, [r9], #-12
 *   @0x30350c .word 0xf8da6041
 *   @0x303510 bl 0x347548
 *   @0x303514 .word 0xf8d9000c
 *   @0x303518 streq r1, [r9], #-16
 *   @0x30351c .word 0xf8da60c1
 *   @0x303520 strbtmi r6, [r6], #-12
 *   @0x303524 ldmvs r1!, {r4, r5, r6, r11, sp, lr} ^
 *   @0x303528 bl 0x354534
 *   @0x30352c ldrdne r7, r8, [r9], #-17
 *   @0x303530 .word 0xf8da60b1
 *   @0x303534 strbtmi r1, [r1], #-12
 *   @0x303538 .word 0xf8da614f
 *   @0x30353c strbtmi r1, [r1], #-12
 *   @0x303540 .word 0xf8da610f
 *   @0x303544 bl 0x34757c
 *   @0x303548 .word 0xf851060c
 *   @0x30354c .word 0xf1b8800c
 *   @0x303550 andsle r0, r4, r0, lsl #30
 *   @0x303554 stmdbls r1, {r6, r9, r10, lr}
 *   @0x303558 stmda r12, {r0, r1, r4, r5, r7, r8, r10, r12, sp, lr, pc}
 *   @0x30355c blmi 0xab1984 <b2_toiTime+0x3584e0>
 *   @0x303560 strbmi lr, [r0], -r12
 *   @0x303564 .word 0xf5b39902
 *   @0x303568 stmdblt r8, {r1, r2, r11, sp, lr, pc}
 *   @0x30356c and r4, r5, r11, lsl r11
 *   @0x303570 stmdbls r3, {r6, r9, r10, lr}
 *   @0x303574 svc #0xfef5b2
 *   @0x303578 blmi 0x9719a0 <b2_toiTime+0x2184fc>
 *   @0x30357c strlo r6, [r1, #-0x133]
 *   @0x303580 stmdbeq r12, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x303584 stmdavs r2!, {r4, r5, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x303588 stmdavs r1!, {r0, sp}
 *   @0x30358c addmi r4, r1, #144
 *   @0x303590 blls 0x3375a4
 *   @0x303594 andge pc, r0, r3, asr #17
 *   @0x303598 mcrge p0, #0x0, lr, c6, c9, #0x0
 *   @0x30359c .word 0x008cf8d4
 *   @0x3035a0 strhs r3, [r0, #-0x458]
 *   @0x3035a4 .word 0xf04f4631
 *   @0x3035a8 .word 0xf7ff0918
 *   @0x3035ac bls 0x5c306c <g_SWFlineaavertbuff+0x6ffa4>
 *   @0x3035b0 rscle r4, lr, #1342177289
 *   @0x3035b4 .word 0x200cf8da
 *   @0x3035b8 .word 0xf8564620
 *   @0x3035bc strlo r1, [r12], #-37
 *   @0x3035c0 strhs pc, [r5, -r9, lsl #22]
 *   @0x3035c4 blx 0x1bc15c8 <b2_toiTime+0x1468124>
 *   @0x3035c8 adcsvs r3, r8, r1, lsl #10
 *   @0x3035cc stmdals r5, {r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x3035d0 pop {r0, r3, r4, r12, sp, pc}
 *   @0x3035d4 svclt #0x8ff0
 *   @0x3035d8 .word 0x77676874
 *   @0x3035dc strbvc r7, [r4, -r8, ror #8]!
 *   @0x3035e0 svcvs #0x70737a
 *   @0x3035e4 strheq r11, [r8], -r0
 *   @0x3035e8 andeq r11, r8, r5, lsl r7
 *   @0x3035ec andeq r11, r8, pc, lsl #14
 *   @0x3035f0 mcrvs p5, #0x0, r11, c3, c0, #0x0
 *   @0x3035f4 .word 0xf8d04908
 *   @0x3035f8 ldrbtmi r4, [r9], #-552
 *   @0x3035fc .word 0xf7e26858
 *   @0x303600 .word 0x4603fc77
 *   @0x303604 tstlt r12, r0, lsr r1
 *   @0x303608 tstlt r11, r3, lsr #16
 *   @0x30360c ldclt p7, c4, [r0, #-608]
 *   @0x303610 ldclt p6, c4, [r0, #-128]
 *   @0x303614 ldclt p6, c4, [r0, #-96]
 *   @0x303618 muleq r8, r12, r5
 *   @0x30361c .word 0x4604b573
 *   @0x303620 strmi r6, [lr], -r0, lsl #16
 *   @0x303624 .word 0xffe4f7ff
 *   @0x303628 .word 0x46054631
 *   @0x30362c .word 0xf7e16820
 *   @0x303630 teqlt sp, r11, lsr #31
 *   @0x303634 movwhs r6, #0xaa2
 *   @0x303638 movwls r6, #0x921
 *   @0x30363c stmdavs sp!, {r4, r11, sp, lr} ^
 *   @0x303640 strmi r6, [r8, r2, ror #18]!
 *   @0x303644 andlt r2, r2, r0
 *   @0x303648 ldrlt r11, [r0, #-0xd70]
 *   @0x30364c bvs 0xfe3d4e64 <b2_toiTime+0xfffffffffdc7b9c0>
 *   @0x303650 cmplt r3, r11, lsl r8
 *   @0x303654 .word 0xf7ff6800
 *   @0x303658 tstlt r8, r11, asr #31
 *   @0x30365c stmvs r2, {r0, r1, r5, r7, r9, r11, sp, lr}
 *   @0x303660 .word 0x47906818
 *   @0x303664 andhs r6, r0, #667648
 *   @0x303668 ldclt p0, c6, [r0, #-104]
 *   @0x30366c .word 0x4604b513
 *   @0x303670 .word 0xf7ff6800
 *   @0x303674 ldrhlt pc, [r0, #-253]
 *   @0x303678 bge 0x35d704 <_ZTS7CFontGM+0xdcc>
 *   @0x30367c .word 0x31a86803
 *   @0x303680 mcrreq p8, #0x5, pc, r4, c1
 *   @0x303684 ldmdblt r0, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x303688 blls 0x35e118 <_ZTS12CDS_Priority+0x170>
 *   @0x30368c andlt r6, r2, r3, lsl r0
 *   @0x303690 .word 0xf5b1bd10
 *   @0x303694 push {r7, r8, r9, r10, r11, r12, sp}
 *   @0x303698 .word 0x460743f8
 *   @0x30369c ldrmi r4, [r0], lr, lsl #12
 *   @0x3036a0 .word 0xf8d2d21d
 *   @0x3036a4 strhs r9, [r0], #-288
 *   @0x3036a8 ble 0x914be0 <b2_toiTime+0x1bb73c>
 *   @0x3036ac .word 0x3124f8d8
 *   @0x3036b0 eorpl pc, r4, r3, asr r8
 *   @0x3036b4 stmdavc r10!, {r0, r2, r4, r5, r6, r8, r12, sp, pc}
 *   @0x3036b8 addsmi r7, r10, #3866624
 *   @0x3036bc strtmi sp, [r8], -r10, lsl #2
 *   @0x3036c0 svc #0x3af5b2
 *   @0x3036c4 strhle r4, [r5, -r0]
 *   @0x3036c8 ldrtmi r4, [r9], -r8, lsr #12
 *   @0x3036cc .word 0xf5b24632
 *   @0x3036d0 smlabblt r8, r8, pc, lr
 *   @0x3036d4 strb r3, [r7, r1, lsl #8]!
 *   @0x3036d8 pop {r5, r9, r10, lr}
 *   @0x3036dc strdhs r8, r9, [r0], -r8
 *   @0x3036e0 .word 0x83f8e8bd
 *   @0x3036e4 .word 0x460fb5f7
 *   @0x3036e8 strmi r2, [r5], -r0, lsl #2
 *   @0x3036ec .word 0xf7e34616
 *   @0x3036f0 .word 0x4604f8da
 *   @0x3036f4 qasxmi r11, r8, r8
 *   @0x3036f8 .word 0x0102f10d
 *   @0x3036fc .word 0xf7feaa01
 *   @0x303700 .word 0x4604fdd5
 *   @0x303704 rfeia sp!
 *   @0x303708 vhadd.s8 d18, d8, d2
 *   @0x30370c addsmi r0, r10, #67108864
 *   @0x303710 qadd16mi sp, r8, r2
 *   @0x303714 .word 0xf7e44631
 *   @0x303718 strmi pc, [r4], -r4, lsl #23
 *   @0x30371c bvs 0xd31d84 <b2_toiTime+0x5d88e0>
 *   @0x303720 shasxmi r4, r2, r9
 *   @0x303724 b 0xfe640df8 <b2_toiTime+0xfffffffffdee7954>
 *   @0x303728 svclt #0x142800
 *   @0x30372c strhs r2, [r0], #-1026
 *   @0x303730 .word 0xf7e44628
 *   @0x303734 and pc, r6, r1, asr #23
 *   @0x303738 strtmi r4, [r8], -r1, lsr #12
 *   @0x30373c rfeia r3!
 *   @0x303740 stmdahs r0, {r2, r9, r10, lr}
 *   @0x303744 strtmi sp, [r0], -r5, ror #1
 *   @0x303748 ldcllt p0, c11, [r0, #12]!
 *   @0x30374c svcmi #0xf0e92d
 *   @0x303750 .word 0xf8d0b0ed
 *   @0x303754 .word 0xf10d21ec
 *   @0x303758 .word 0x46040934
 *   @0x30375c strbmi r2, [r8], -r0, lsl #2
 *   @0x303760 andls r2, r6, #0, #10
 *   @0x303764 adcsvc pc, lr, #1325400064
 *   @0x303768 svc #0x22f5b2
 *   @0x30376c .word 0x33fff04f
 *   @0x303770 strtmi r9, [r9], -r6, lsl #20
 *   @0x303774 andslo pc, r8, #196, #16
 *   @0x303778 .word 0xf8c44648
 *   @0x30377c movwhs r3, #0x721c
 *   @0x303780 tstlo r8, r4, asr #17
 *   @0x303784 .word 0xf8c42301
 *   @0x303788 movwhs r3, #0x411c
 *   @0x30378c adclo pc, r12, r4, asr #17
 *   @0x303790 cmpvc r12, #64, #12
 *   @0x303794 cmplo r12, r4, asr #17
 *   @0x303798 .word 0xf8c44ba9
 *   @0x30379c .word 0xf8d45220
 *   @0x3037a0 .word 0xf8c48064
 *   @0x3037a4 ldmdavs r3, {r2, r4, r8, r12, sp} ^
 *   @0x3037a8 cdpvs p6, #0xa, c4, c6, c10, #0x1
 *   @0x3037ac .word 0x4643681f
 *   @0x3037b0 stmibmi r4!, {r3, r4, r5, r7, r8, r9, r10, lr}
 *   @0x3037b4 andhs r4, lr, #48, #12
 *   @0x3037b8 .word 0xf8c94479
 *   @0x3037bc .word 0xf8c95050
 *   @0x3037c0 .word 0xf8c9504c
 *   @0x3037c4 .word 0xf8c95058
 *   @0x3037c8 .word 0xf8895054
 *   @0x3037cc .word 0xf889505c
 *   @0x3037d0 .word 0xf889505d
 *   @0x3037d4 stcge p0, c5, [r11, #-376]
 *   @0x3037d8 subvs pc, r8, r9, asr #17
 *   @0x3037dc .word 0xff82f7ff
 *   @0x3037e0 ldmdblt r8!, {r3, r5, sp, lr}
 *   @0x3037e4 .word 0x21004630
 *   @0x3037e8 .word 0xf85df7e3
 *   @0x3037ec stmdahs r0, {r3, r5, sp, lr}
 *   @0x3037f0 and sp, r12, r12, asr r1
 *   @0x3037f4 stmdahs r2, {r6, r7, r9, r12, sp, pc}
 *   @0x3037f8 ldmibmi r3, {r3, r4, r6, r8, r12, lr, pc}
 *   @0x3037fc andhs r4, r10, #48, #12
 *   @0x303800 .word 0xf7ff4479
 *   @0x303804 eorvs pc, r8, pc, ror #30
 *   @0x303808 mrsle r2, spsr
 *   @0x30380c .word 0xf10de7ea
 *   @0x303810 svcge #0xc0a28
 *   @0x303814 uasxmi r4, r1, r0
 *   @0x303818 .word 0xf7fe463a
 *   @0x30381c strmi pc, [r1], -r7, asr #26
 *   @0x303820 stmdahs r0, {r3, r5, sp, lr}
 *   @0x303824 rfeia r10!
 *   @0x303828 vhadd.s8 d18, d8, d0
 *   @0x30382c addsmi r0, r10, #67108864
 *   @0x303830 ldrtmi sp, [r0], -r8
 *   @0x303834 rfeda r7!
 *   @0x303838 stmdahs r0, {r3, r5, sp, lr}
 *   @0x30383c ldmdavs r3!, {r1, r2, r4, r5, r8, r12, lr, pc} ^
 *   @0x303840 and r6, r2, r11, lsr r0
 *   @0x303844 .word 0xf8892301
 *   @0x303848 ldmdbvs r3!, {r2, r3, r4, r6, r12, sp} ^
 *   @0x30384c ldmdavs r9!, {r0, r1, r7, r8, r11, r12, sp, pc}
 *   @0x303850 ldmdavs r2!, {r4, r5, r9, r10, lr}
 *   @0x303854 .word 0xf8c968b3
 *   @0x303858 ldrmi r1, [r3], #-80
 *   @0x30385c sublo pc, r12, r9, asr #17
 *   @0x303860 .word 0xf8892301
 *   @0x303864 .word 0xf7e3305d
 *   @0x303868 eorvs pc, r8, r3, ror #16
 *   @0x30386c ldrsh r11, [r2], -r0
 *   @0x303870 .word 0x46406839
 *   @0x303874 .word 0xf7e3462a
 *   @0x303878 stmdavs r11!, {r1, r2, r4, r6, r10, r11, r12, sp, lr, pc}
 *   @0x30387c .word 0xf8c94601
 *   @0x303880 ldmiblt r11, {r2, r3, r6}
 *   @0x303884 ldmdavs r10!, {r4, r5, r9, r10, lr}
 *   @0x303888 .word 0xf881f7e3
 *   @0x30388c stmdblt r8!, {r3, r5, sp, lr} ^
 *   @0x303890 .word 0xf8c9683b
 *   @0x303894 .word 0xf8d93050
 *   @0x303898 .word 0xf8d9304c
 *   @0x30389c .word 0xf8c92050
 *   @0x3038a0 .word 0xf8c93004
 *   @0x3038a4 ldrmi r3, [r3], #-0
 *   @0x3038a8 andlo pc, r8, r9, asr #17
 *   @0x3038ac .word 0xb14b682b
 *   @0x3038b0 .word 0x605df899
 *   @0x3038b4 .word 0x4640b936
 *   @0x3038b8 .word 0x104cf8d9
 *   @0x3038bc ldc2 p7, c15, [r11, #-908]!
 *   @0x3038c0 subvs pc, r12, r9, asr #17
 *   @0x3038c4 .word 0xf10d682b
 *   @0x3038c8 .word 0xf8ca0a24
 *   @0x3038cc blhs 0x30f8d4 <af_shaper_get_elem+0x5142>
 *   @0x3038d0 subshi pc, r8, #64
 *   @0x3038d4 strbmi r4, [r9], -r0, lsr #12
 *   @0x3038d8 .word 0x204cf8d9
 *   @0x3038dc ldrsblo pc, [r0], #-137
 *   @0x3038e0 blx 0xec18e2 <b2_toiTime+0x76843e>
 *   @0x3038e4 .word 0xf8ca4680
 *   @0x3038e8 .word 0x28000000
 *   @0x3038ec subhi pc, r10, #64
 *   @0x3038f0 ldrsblo pc, [r0], -r9
 *   @0x3038f4 .word 0xf8d9ae0a
 *   @0x3038f8 eorsvs r7, r0, r8, asr #32
 *   @0x3038fc .word 0xf8999305
 *   @0x303900 blhs 0x30fa78 <af_shaper_get_elem+0x52e6>
 *   @0x303904 shsaxmi sp, r8, pc
 *   @0x303908 .word 0xf81af7e3
 *   @0x30390c subshi pc, r8, r9, asr #17
 *   @0x303910 ldmdaeq r0!, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x303914 ldrtmi r9, [r8], -r7
 *   @0x303918 strtmi r4, [r10], -r1, asr #12
 *   @0x30391c stc2l p7, c15, [r6], {254}
 *   @0x303920 stmdahs r0, {r4, r5, sp, lr}
 *   @0x303924 .word 0x8146f040
 *   @0x303928 strhlo pc, [r0], -r8
 *   @0x30392c andeq pc, r2, #72, #4
 *   @0x303930 addsmi r4, r3, #154140672
 *   @0x303934 .word 0xf8d9d10c
 *   @0x303938 shsaxmi r3, r8, r8
 *   @0x30393c strmi r6, [r11], #-2089
 *   @0x303940 subslo pc, r8, r9, asr #17
 *   @0x303944 .word 0xfff4f7e2
 *   @0x303948 stmdahs r0, {r4, r5, sp, lr}
 *   @0x30394c teq r1, r3, ror #1
 *   @0x303950 ldrsblo pc, [r8], #-137
 *   @0x303954 .word 0xf0002b00
 *   @0x303958 shsaxmi r8, r8, r5
 *   @0x30395c .word 0xf7e29907
 *   @0x303960 eorsvs pc, r0, r2, lsr #31
 *   @0x303964 .word 0xf0402800
 *   @0x303968 stmdals r5, {r0, r2, r5, r8, pc}
 *   @0x30396c .word 0xf8d94632
 *   @0x303970 .word 0xf7e31058
 *   @0x303974 ldmdavs r3!, {r3, r4, r6, r7, r8, r9, r11, r12, sp, lr, pc}
 *   @0x303978 subseq pc, r4, r9, asr #17
 *   @0x30397c .word 0xf0402b00
 *   @0x303980 shadd16mi r8, r8, r9
 *   @0x303984 strtmi r4, [r10], -r1, asr #12
 *   @0x303988 subslo pc, r8, r9, asr #17
 *   @0x30398c stc2 p7, c15, [lr], {254}
 *   @0x303990 ldmdblt r8, {r4, r5, sp, lr}
 *   @0x303994 strhlo pc, [r0], -r8
 *   @0x303998 andle r4, r2, r11, asr r5
 *   @0x30399c eorsvs r2, r3, r0, lsl #6
 *   @0x3039a0 .word 0xf8d9e0e2
 *   @0x3039a4 shsaxmi r1, r8, r4
 *   @0x3039a8 ldrsblo pc, [r8], #-137
 *   @0x3039ac ldrmi r6, [r9], #-2090
 *   @0x3039b0 .word 0xffedf7e2
 *   @0x3039b4 stmdahs r0, {r4, r5, sp, lr}
 *   @0x3039b8 rscshi pc, r12, r0, asr #32
 *   @0x3039bc .word 0xf8d9682a
 *   @0x3039c0 ldrmi r3, [r3], #-88
 *   @0x3039c4 .word 0xf8d9e7dd
 *   @0x3039c8 .word 0xf8d9704c
 *   @0x3039cc ldrtmi r3, [r11], #-80
 *   @0x3039d0 bhs 0x1c61ac0 <b2_toiTime+0x150861c>
 *   @0x3039d4 .word 0xf107d10f
 *   @0x3039d8 addsmi r0, r3, #-1879048192
 *   @0x3039dc ldmdavc r10!, {r0, r1, r3, r8, r11, r12, lr, pc} ^
 *   @0x3039e0 .word 0xd1082a65
 *   @0x3039e4 bhs 0x2121cd4 <b2_toiTime+0x19c8830>
 *   @0x3039e8 ldmvc r10!, {r0, r2, r8, r12, lr, pc} ^
 *   @0x3039ec .word 0xd1022a65
 *   @0x3039f0 bhs 0x1be1ee0 <b2_toiTime+0x1488a3c>
 *   @0x3039f4 strlo sp, [r1, -r1]
 *   @0x3039f8 .word 0xf8d9e01f
 *   @0x3039fc strlo r3, [r10, -r12, asr #32]
 *   @0x303a00 andvc pc, r8, r9, asr #17
 *   @0x303a04 andlo pc, r0, r9, asr #17
 *   @0x303a08 .word 0xf8d9e005
 *   @0x303a0c .word 0x4648301c
 *   @0x303a10 .word 0xf8d94798
 *   @0x303a14 adcsmi r3, r11, #0
 *   @0x303a18 ldmdavc r10, {r1, r3, r9, r12, lr, pc}
 *   @0x303a1c andsle r2, r5, r5, ror #20
 *   @0x303a20 .word 0x3020f8d9
 *   @0x303a24 ldrmi r4, [r8, r8, asr #12]
 *   @0x303a28 .word 0x300cf8d9
 *   @0x303a2c rscle r2, r12, r0, lsl #22
 *   @0x303a30 .word 0x204cf8d9
 *   @0x303a34 ldrsblo pc, [r0], #-137
 *   @0x303a38 addsmi r4, pc, #318767104
 *   @0x303a3c mvn sp, r8, asr #7
 *   @0x303a40 eoreq r10, r7, r0
 *   @0x303a44 andeq r11, r8, r6, asr #9
 *   @0x303a48 andeq r11, r8, sp, lsl #9
 *   @0x303a4c addsmi r1, r7, #5760
 *   @0x303a50 ldmdavc r10, {r1, r2, r5, r6, r7, r8, r11, r12, lr, pc} ^
 *   @0x303a54 mvnle r2, r5, ror #20
 *   @0x303a58 bhs 0x2121cc8 <b2_toiTime+0x19c8824>
 *   @0x303a5c ldmvc r10, {r5, r6, r7, r8, r12, lr, pc} ^
 *   @0x303a60 bicsle r2, sp, r5, ror #20
 *   @0x303a64 blhs 0x1be1ed8 <b2_toiTime+0x1488a34>
 *   @0x303a68 .word 0xf8d9d1da
 *   @0x303a6c strbmi r2, [r8], -r12, asr #32
 *   @0x303a70 ldrsblo pc, [r0], #-137
 *   @0x303a74 .word 0xf8c94413
 *   @0x303a78 .word 0xf8d93008
 *   @0x303a7c ldrmi r3, [r8, r0, lsr #32]
 *   @0x303a80 .word 0x7000f8d9
 *   @0x303a84 .word 0x8008f8d9
 *   @0x303a88 bl 0xff4cbeb8 <b2_toiTime+0xfffffffffed72a14>
 *   @0x303a8c ldrtmi r0, [r8], -r8, lsl #6
 *   @0x303a90 ldrmi r9, [r10], -r2, lsl #6
 *   @0x303a94 mcr p5, #0x0, pc, c4, c2, #0x5
 *   @0x303a98 strmi r9, [r3], r2, lsl #22
 *   @0x303a9c ldrtmi r11, [r8], -r8, asr #2
 *   @0x303aa0 ldrmi r2, [r10], -sp, lsl #2
 *   @0x303aa4 ldcl p5, c15, [r12, #712]!
 *   @0x303aa8 svclt #0x944583
 *   @0x303aac andhs r2, r1, r0
 *   @0x303ab0 andhs lr, r1, r0
 *   @0x303ab4 ldrtmi r11, [r10], -r1, asr #5
 *   @0x303ab8 ldrmi r4, [r7], -r2, asr #10
 *   @0x303abc .word 0x81a2f080
 *   @0x303ac0 bllo 0x381b10 <_ZTS13C_UTF16String+0x18bbc>
 *   @0x303ac4 rscsle r2, r7, r0, lsr #22
 *   @0x303ac8 rscsle r2, r5, r9, lsl #22
 *   @0x303acc blhs 0x66fef8 <g_SWFlinevertbuff+0x1ce30>
 *   @0x303ad0 blhs 0x5b7ea0 <g_SWFlineaavertbuff+0x64dd8>
 *   @0x303ad4 .word 0xf8d9d0f0
 *   @0x303ad8 .word 0xf8d9204c
 *   @0x303adc blne 0xff74fc24 <b2_toiTime+0xfffffffffeff6780>
 *   @0x303ae0 .word 0xf8994419
 *   @0x303ae4 eorvs r3, r9, sp, asr r0
 *   @0x303ae8 .word 0xf0002b00
 *   @0x303aec stmdals r5, {r1, r2, r3, r7, r8, pc}
 *   @0x303af0 ldrtmi r3, [r2], -r1, lsl #2
 *   @0x303af4 blx 0x901a8a <b2_toiTime+0x1a85e6>
 *   @0x303af8 .word 0xf8c96833
 *   @0x303afc blhs 0x303c54 <TT_New_Context+0x3a4c>
 *   @0x303b00 stmdavs r11!, {r3, r4, r6, r8, r12, lr, pc}
 *   @0x303b04 subslo pc, r8, r9, asr #17
 *   @0x303b08 ldrmi r1, [r8, #0xcfb]
 *   @0x303b0c .word 0x81a1f240
 *   @0x303b10 .word 0xf1a3783b
 *   @0x303b14 bhs 0x5443dc <g_DecodeStringBuffer+0x1968>
 *   @0x303b18 orrhi pc, r3, r0, lsl #4
 *   @0x303b1c .word 0xf1a3787b
 *   @0x303b20 bhs 0x5443e8 <g_DecodeStringBuffer+0x1974>
 *   @0x303b24 orrhi pc, r3, r0, lsl #4
 *   @0x303b28 .word 0xf1a378bb
 *   @0x303b2c bhs 0x5443f4 <g_DecodeStringBuffer+0x1980>
 *   @0x303b30 orrhi pc, r3, r0, lsl #4
 *   @0x303b34 .word 0xf1a378fb
 *   @0x303b38 bhs 0x544400 <g_DecodeStringBuffer+0x198c>
 *   @0x303b3c orrhi pc, r3, r0, lsl #4
 *   @0x303b40 vstrge s18, [sp, #-24]
 *   @0x303b44 ldmdaeq r0!, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x303b48 strtmi r9, [r8], -sp, lsl #14
 *   @0x303b4c ldmdavs r3, {r8, r9, r10, sp} ^
 *   @0x303b50 strls r9, [r0, -r2, lsr #18]
 *   @0x303b54 .word 0xf8d39a23
 *   @0x303b58 .word 0x4643c018
 *   @0x303b5c .word 0xf8d847e0
 *   @0x303b60 stclvs p0, c3, [r10, #-0]!
 *   @0x303b64 ldrbpl r6, [r7], #1451
 *   @0x303b68 .word 0xf8d99a06
 *   @0x303b6c .word 0xf8d90054
 *   @0x303b70 ldmdbvs r3, {r3, r4, r6, r12}
 *   @0x303b74 rsbsne pc, r1, #80740352
 *   @0x303b78 .word 0xf8d94798
 *   @0x303b7c blhs 0x3cfce4 <error_g0017+0x28988>
 *   @0x303b80 .word 0x8140f240
 *   @0x303b84 ldrsbhs pc, [r4], #-137
 *   @0x303b88 andsvc r2, r3, r0, lsr #6
 *   @0x303b8c ldrsbhs pc, [r4], #-137
 *   @0x303b90 .word 0xf8d97053
 *   @0x303b94 addsvc r2, r3, r4, asr r0
 *   @0x303b98 ldrsbhs pc, [r4], #-137
 *   @0x303b9c .word 0xf8d970d3
 *   @0x303ba0 .word 0xf8d93054
 *   @0x303ba4 .word 0xf8c92058
 *   @0x303ba8 .word 0xf8c93004
 *   @0x303bac ldrmi r3, [r3], #-0
 *   @0x303bb0 andlo pc, r8, r9, asr #17
 *   @0x303bb4 .word 0xf8ca6833
 *   @0x303bb8 blhs 0x30fbc0 <af_shaper_get_elem+0x542e>
 *   @0x303bbc rschi pc, r2, r0, asr #32
 *   @0x303bc0 strbmi r4, [r9], -r0, lsr #12
 *   @0x303bc4 ldrsbhs pc, [r4], #-137
 *   @0x303bc8 ldrsblo pc, [r8], #-137
 *   @0x303bcc rfeib r8!
 *   @0x303bd0 andeq pc, r0, r10, asr #17
 *   @0x303bd4 .word 0xf0402800
 *   @0x303bd8 .word 0xf89480d5
 *   @0x303bdc .word 0xf02330b0
 *   @0x303be0 .word 0xf8840301
 *   @0x303be4 .word 0xf8d430b0
 *   @0x303be8 teqlt r11, r4, lsl r2
 *   @0x303bec .word 0x21a0f8d3
 *   @0x303bf0 ldmdavs r9, {r1, r5, r8, r12, sp, pc} ^
 *   @0x303bf4 svclt #0x18428a
 *   @0x303bf8 asreq pc, r3, #17
 *   @0x303bfc andslo pc, r4, #212, #16
 *   @0x303c00 ldmdavs r10, {r0, r1, r4, r5, r8, r12, sp, pc}
 *   @0x303c04 ldmdavs r11, {r1, r3, r8, r12, sp, pc} ^
 *   @0x303c08 qadd16mi r11, r0, r3
 *   @0x303c0c stc2 p7, c15, [r6, #1012]!
 *   @0x303c10 andshs pc, r4, #212, #16
 *   @0x303c14 ldmdavs r1, {r1, r3, r4, r5, r6, r8, r12, sp, pc} ^
 *   @0x303c18 andhs r2, r12, r0, lsl #6
 *   @0x303c1c andle r4, r10, r11, lsl #5
 *   @0x303c20 strhs pc, [r3, #-0xb00]
 *   @0x303c24 .word 0x5058f895
 *   @0x303c28 qadd16mi r11, r0, sp
 *   @0x303c2c ldc2 p7, c15, [r6, #1012]
 *   @0x303c30 movwlo lr, #0x1001
 *   @0x303c34 .word 0xf8d4e7f2
 *   @0x303c38 orrslt r3, r3, r4, lsl r2
 *   @0x303c3c eorlo pc, r0, #212, #16
 *   @0x303c40 strhs r11, [r0, #-0x18b]
 *   @0x303c44 stm sp, {r2, r8, sp}
 *   @0x303c48 strtmi r0, [r10], -r0, lsr #8
 *   @0x303c4c .word 0xf7e46e60
 *   @0x303c50 .word 0xf8dafa1e
 *   @0x303c54 .word 0xf8c43000
 *   @0x303c58 .word 0xb1230224
 *   @0x303c5c eorpl pc, r0, #196, #16
 *   @0x303c60 .word 0xf8c4e090
 *   @0x303c64 blls 0xfd04ec <b2_toiTime+0x877048>
 *   @0x303c68 .word 0x31a4f8c4
 *   @0x303c6c orrlt r9, r11, pc, asr r11
 *   @0x303c70 .word 0xf8c49b5b
 *   @0x303c74 blls 0x1a102cc <b2_toiTime+0x12b6e28>
 *   @0x303c78 orrlo pc, r8, r4, asr #17
 *   @0x303c7c .word 0xf8c49b62
 *   @0x303c80 blls 0x1bd02e8 <b2_toiTime+0x1476e44>
 *   @0x303c84 orrslo pc, r12, r4, asr #17
 *   @0x303c88 .word 0xf8c49b69
 *   @0x303c8c movwhs r3, #0x1a0
 *   @0x303c90 .word 0x9369935f
 *   @0x303c94 .word 0x3080f8d4
 *   @0x303c98 stmdblt r3!, {r0, r1, r3, r4, r6, r8, r9, r11, sp, lr}
 *   @0x303c9c ldmdblt r3, {r2, r6, r8, r9, r11, r12, pc}
 *   @0x303ca0 .word 0xf8ca2303
 *   @0x303ca4 blls 0x134fcac <b2_toiTime+0xbf6808>
 *   @0x303ca8 strbls r2, [r4], -r0, lsl #12
 *   @0x303cac orrlo pc, r12, r4, asr #17
 *   @0x303cb0 .word 0xf8c49b47
 *   @0x303cb4 blls 0x151036c <b2_toiTime+0xdb6ec8>
 *   @0x303cb8 asrslo pc, r4, #17
 *   @0x303cbc shasxls r9, r4, r4
 *   @0x303cc0 orrslo pc, r0, r4, asr #17
 *   @0x303cc4 shasxls r9, r10, r10
 *   @0x303cc8 .word 0x31a8f8c4
 *   @0x303ccc ldrsblo pc, [r0, #-132]!
 *   @0x303cd0 cmple r7, r1, lsl #22
 *   @0x303cd4 ldrtmi r4, [r0], r2, ror #22
 *   @0x303cd8 ldrtmi r4, [r5], -r2, ror #20
 *   @0x303cdc movwls r4, #0x547b
 *   @0x303ce0 andls r4, r7, #2046820352
 *   @0x303ce4 ldrsbtlo pc, [r4], #-137
 *   @0x303ce8 ble 0x13d4764 <b2_toiTime+0xc7b2c0>
 *   @0x303cec .word 0x2180f8d4
 *   @0x303cf0 movweq pc, #0x4f
 *   @0x303cf4 .word 0x0c45ea4f
 *   @0x303cf8 bleq 0xfe47e63c <b2_toiTime+0xfffffffffdd25198>
 *   @0x303cfc andslo pc, r5, r2, lsr #16
 *   @0x303d00 .word 0xf8d49b05
 *   @0x303d04 .word 0xf8422184
 *   @0x303d08 .word 0xf8d93025
 *   @0x303d0c .word 0xf852207c
 *   @0x303d10 .word 0xb36b3025
 *   @0x303d14 .word 0x21a4f8d4
 *   @0x303d18 andls r2, r6, #0, #14
 *   @0x303d1c addsmi r9, r7, #24576
 *   @0x303d20 .word 0xf8d4da26
 *   @0x303d24 ldrmi r1, [r8], -r8, lsr #3
 *   @0x303d28 eorhs pc, r7, r1, asr r8
 *   @0x303d2c .word 0xf8cd9302
 *   @0x303d30 ldrmi r12, [r1], -r12
 *   @0x303d34 .word 0xf5b29204
 *   @0x303d38 bls 0x43edb8 <g_RomDisk+0x47598>
 *   @0x303d3c .word 0xf8dd9b02
 *   @0x303d40 ldmiblt r8, {r2, r3, lr, pc}
 *   @0x303d44 .word 0x3180f8d4
 *   @0x303d48 stmdals r7, {r0, r4, r9, r10, lr}
 *   @0x303d4c andvc pc, r12, r3, lsr #16
 *   @0x303d50 .word 0x3184f8d4
 *   @0x303d54 andhs pc, r11, r3, asr #16
 *   @0x303d58 .word 0xec0cf5b2
 *   @0x303d5c strmi r11, [r8, #0x140]!
 *   @0x303d60 strtmi r11, [r8], r8, lsr #31
 *   @0x303d64 blle 0x3d4840 <error_g0017+0x2d4e4>
 *   @0x303d68 and r1, r1, lr, ror #24
 *   @0x303d6c ldrb r3, [r5, r1, lsl #14]
 *   @0x303d70 ldr r3, [r7, r1, lsl #10]!
 *   @0x303d74 .word 0x3060f8d9
 *   @0x303d78 cmnhi r8, r4, asr #17
 *   @0x303d7c cmnvs r12, r4, asr #17
 *   @0x303d80 cmnlo r4, r4, asr #17
 *   @0x303d84 .word 0xf8d99b32
 *   @0x303d88 .word 0xb10b4010
 *   @0x303d8c ldrmi r10, [r8, r6, lsr #16]
 *   @0x303d90 tstlt r3, sp, asr #22
 *   @0x303d94 sbcseq pc, r0, r9, lsl #2
 *   @0x303d98 blls 0x1315c00 <b2_toiTime+0xbbc75c>
 *   @0x303d9c .word 0xf109b113
 *   @0x303da0 .word 0x4798009c
 *   @0x303da4 tstlt r3, r10, asr r11
 *   @0x303da8 addvc pc, r2, r9, lsl #10
 *   @0x303dac blls 0x1d15c14 <b2_toiTime+0x15bc770>
 *   @0x303db0 .word 0xf509b113
 *   @0x303db4 .word 0x4798709e
 *   @0x303db8 stmdals r9!, {r0, r5, r9, r10, lr} ^
 *   @0x303dbc blx 0x1d50
 *   @0x303dc0 stmdbls r9!, {r5, r9, r10, lr} ^
 *   @0x303dc4 .word 0xf7e32400
 *   @0x303dc8 .word 0xf8d9fab6
 *   @0x303dcc .word 0xf8d95010
 *   @0x303dd0 strbtls r1, [r9], #-84
 *   @0x303dd4 .word 0xf7e34628
 *   @0x303dd8 .word 0xf8c9faae
 *   @0x303ddc .word 0xf8994054
 *   @0x303de0 ldmdblt r4!, {r0, r2, r3, r4, r6, lr}
 *   @0x303de4 .word 0xf8d94628
 *   @0x303de8 .word 0xf7e3104c
 *   @0x303dec .word 0xf8c9faa4
 *   @0x303df0 strbmi r4, [r8], -r12, asr #32
 *   @0x303df4 ldrsblo pc, [r8], -r9
 *   @0x303df8 .word 0xf8da4798
 *   @0x303dfc rsblt r0, sp, r0
 *   @0x303e00 svchi #0xf0e8bd
 *   @0x303e04 eorsvs r2, r3, r3, lsl #6
 *   @0x303e08 ldrdhs lr, pc, [r1], -r4
 *   @0x303e0c subshs pc, r4, r9, asr #17
 *   @0x303e10 subseq pc, lr, r9, lsl #17
 *   @0x303e14 subsne pc, r8, r9, asr #17
 *   @0x303e18 sublo pc, r12, r9, asr #17
 *   @0x303e1c subslo pc, r0, r9, asr #17
 *   @0x303e20 .word 0xf023e672
 *   @0x303e24 bllo 0x1344aac <b2_toiTime+0xbeb608>
 *   @0x303e28 ldmdale r2, {r0, r2, r8, r9, r11, sp}
 *   @0x303e2c .word 0xf023e676
 *   @0x303e30 bllo 0x1344ab8 <b2_toiTime+0xbeb614>
 *   @0x303e34 stmdale r12, {r0, r2, r8, r9, r11, sp}
 *   @0x303e38 .word 0xf023e676
 *   @0x303e3c bllo 0x1344ac4 <b2_toiTime+0xbeb620>
 *   @0x303e40 stmdale r6, {r0, r2, r8, r9, r11, sp}
 *   @0x303e44 .word 0xf023e676
 *   @0x303e48 bllo 0x1344ad0 <b2_toiTime+0xbeb62c>
 *   @0x303e4c .word 0xf67f2b05
 *   @0x303e50 .word 0xf8d9ae77
 *   @0x303e54 shsaxmi r0, r9, r4
 *   @0x303e58 .word 0xf5b2682a
 *   @0x303e5c pkhbt lr, r3, r12, lsl #24
 *   @0x303e60 andeq r10, r8, r5, lsr #30
 *   @0x303e64 andeq r10, r8, r1, lsr #30
 *   @0x303e68 svcmi #0xf0e92d
 *   @0x303e6c cdpvs p6, #0x0, c4, c8, c12, #0x0
 *   @0x303e70 andhs r4, r1, #23068672
 *   @0x303e74 stmibmi r1!, {r1, r3, sp, lr}
 *   @0x303e78 ldrbtmi r11, [r9], #-135
 *   @0x303e7c .word 0xf85bf7e2
 *   @0x303e80 ldmibmi pc, {r0, r1, r5, r9, r10, r11, sp, lr}
 *   @0x303e84 .word 0xf8c44479
 *   @0x303e88 strmi r0, [r0], r8, ror #3
 *   @0x303e8c .word 0xf7e26858
 *   @0x303e90 strmi pc, [r7], -r11, asr #16
 *   @0x303e94 mvneq pc, r4, asr #17
 *   @0x303e98 .word 0xf0002800
 *   @0x303e9c mcrvs p1, #0x1, r8, c3, c9, #0x0
 *   @0x303ea0 ldmdavs r8, {r3, r4, r7, r8, r11, lr} ^
 *   @0x303ea4 .word 0xf7e24479
 *   @0x303ea8 .word 0xf8c4f83f
 *   @0x303eac strtmi r0, [r0], -r8, lsr #4
 *   @0x303eb0 mcrr2 p7, #0xf, pc, r12, c15
 *   @0x303eb4 stmdahs r0, {r0, r2, r9, r10, lr}
 *   @0x303eb8 tsthi r2, r0, asr #32
 *   @0x303ebc vmull.p8 q9, d0, d0
 *   @0x303ec0 adcslt r8, r6, #-1073741821
 *   @0x303ec4 .word 0xf0402e00
 *   @0x303ec8 .word 0xf8d48105
 *   @0x303ecc rsbvs r3, r0, r4, lsr #3
 *   @0x303ed0 stmvs r3!, {r0, r1, r5, r8, sp, lr}
 *   @0x303ed4 msrvs CPSR_c, #1124073472
 *   @0x303ed8 andeq pc, r1, #67
 *   @0x303edc .word 0xf89460a2
 *   @0x303ee0 .word 0xb112209c
 *   @0x303ee4 movweq pc, #0x5043
 *   @0x303ee8 .word 0xf8d460a3
 *   @0x303eec tstlt r11, r4, lsl r2
 *   @0x303ef0 vst2.32 {d22, d23}, [r3:128], r3
 *   @0x303ef4 adcvs r7, r3, r0, lsl #7
 *   @0x303ef8 ldrsbhs pc, [r0], r4
 *   @0x303efc .word 0x61a32300
 *   @0x303f00 biclt r6, r10, r2, ror #2
 *   @0x303f04 .word 0x308cf8d4
 *   @0x303f08 ldmdavc r9, {r0, r1, r4, r6, r7, r8, r12, sp, pc}
 *   @0x303f0c .word 0xf0002900
 *   @0x303f10 ldmdavc r0, {r0, r1, r5, r6, r7, pc}
 *   @0x303f14 smlabble r1, r1, r2, r4
 *   @0x303f18 and r3, r3, r1, lsl #4
 *   @0x303f1c andle r2, r1, r0, lsr #18
 *   @0x303f20 .word 0xd101292d
 *   @0x303f24 ldrb r3, [r0, r1, lsl #6]!
 *   @0x303f28 andle r2, r1, r0, lsr #16
 *   @0x303f2c .word 0xd101282d
 *   @0x303f30 strb r3, [r10, r1, lsl #4]!
 *   @0x303f34 sbcs r11, r1, r0, lsr #18
 *   @0x303f38 .word 0x316cf8d4
 *   @0x303f3c .word 0x6163b103
 *   @0x303f40 .word 0xf8d469a3
 *   @0x303f44 stmdblt r11!, {r2, r4, r7, sp, lr}
 *   @0x303f48 .word 0x61a6b10e
 *   @0x303f4c blmi 0x1ebbf5c <b2_toiTime+0x1762ab8>
 *   @0x303f50 .word 0x61a3447b
 *   @0x303f54 rscvs r2, r3, r0, lsl #6
 *   @0x303f58 ldrsblo pc, [r8], r4
 *   @0x303f5c movwhs r11, #0x110b
 *   @0x303f60 cmnlt lr, r3, ror #1
 *   @0x303f64 ldrtmi r4, [r0], -r9, ror #18
 *   @0x303f68 .word 0xf5b24479
 *   @0x303f6c .word 0xb128eb04
 *   @0x303f70 ldrtmi r4, [r0], -r7, ror #18
 *   @0x303f74 .word 0xf5b24479
 *   @0x303f78 ldmdblt r8, {r1, r2, r3, r4, r5, r6, r7, r9, r11, sp, lr, pc}
 *   @0x303f7c .word 0xf04368e3
 *   @0x303f80 rscvs r0, r3, r2, lsl #6
 *   @0x303f84 mvnvs r2, r0, lsl #6
 *   @0x303f88 rfeib r4!
 *   @0x303f8c rfeib r4!
 *   @0x303f90 .word 0x636361d6
 *   @0x303f94 ldrsblo pc, [r8, #132]
 *   @0x303f98 .word 0xf50363a6
 *   @0x303f9c .word 0xf8d44a7f
 *   @0x303fa0 .word 0xf10a31dc
 *   @0x303fa4 .word 0xf5030aff
 *   @0x303fa8 rfeia r4!
 *   @0x303fac .word 0xf1093044
 *   @0x303fb0 b 0x16c67b4 <b2_toiTime+0xf6d310>
 *   @0x303fb4 .word 0xf8c44a2a
 *   @0x303fb8 b 0x16ec0b0 <b2_toiTime+0xf92c0c>
 *   @0x303fbc .word 0xf8c44929
 *   @0x303fc0 ldmdblt r11, {r6, r12, pc}
 *   @0x303fc4 cmnvc r10, #1325400064
 *   @0x303fc8 sublo pc, r4, r4, lsr #17
 *   @0x303fcc strhhs pc, [r4], #-132
 *   @0x303fd0 blx 0xacc008 <b2_toiTime+0x372b64>
 *   @0x303fd4 blx 0xb00e00 <b2_toiTime+0x3a795c>
 *   @0x303fd8 .word 0xf8a4fb86
 *   @0x303fdc .word 0x210a3046
 *   @0x303fe0 sublt pc, r8, r4, lsr #17
 *   @0x303fe4 blx 0xfe60282a <b2_toiTime+0xfffffffffdea9386>
 *   @0x303fe8 movwls r4, #0x1350
 *   @0x303fec mrc p0, #0x4, apsr_nzcv, c0, c4, #0x0
 *   @0x303ff0 .word 0xf8a49b01
 *   @0x303ff4 andslt r10, r11, #76
 *   @0x303ff8 movweq lr, #0x3bcb
 *   @0x303ffc andlt r11, r2, #128, #4
 *   @0x304000 svclt #0xac429a
 *   @0x304004 subeq pc, r10, r4, lsr #17
 *   @0x304008 streq lr, [r9], -r6, asr #23
 *   @0x30400c stmdbeq r12, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x304010 .word 0xf8a4bfb8
 *   @0x304014 strtmi r6, [r0], -r10, asr #32
 *   @0x304018 .word 0xf7fc4649
 *   @0x30401c stmdblt r8!, {r0, r1, r2, r3, r4, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x304020 .word 0xf7e09803
 *   @0x304024 strne pc, [r0], #-3707
 *   @0x304028 subeq pc, r12, r4, lsr #17
 *   @0x30402c strhlo pc, [r10], #-132
 *   @0x304030 sublo pc, lr, r4, lsr #17
 *   @0x304034 ldrhlo pc, [lr], r4
 *   @0x304038 subslo pc, r0, r4, lsr #17
 *   @0x30403c .word 0x30a0f8b4
 *   @0x304040 subslo pc, r2, r4, lsr #17
 *   @0x304044 svceq #0xf1b8
 *   @0x304048 ldmdbvs lr!, {r1, r3, r6, r12, lr, pc} ^
 *   @0x30404c .word 0xf8ad2303
 *   @0x304050 movwhs r3, #0x1014
 *   @0x304054 andslo pc, r6, sp, lsr #17
 *   @0x304058 blmi 0xbcc460 <b2_toiTime+0x472fbc>
 *   @0x30405c strls r4, [r3], #-1610
 *   @0x304060 strmi r9, [r11], -r4, lsl #6
 *   @0x304064 .word 0xf7e468f0
 *   @0x304068 tstlt r0, r6, lsl #19
 *   @0x30406c blhs 0xfebf0b80 <b2_toiTime+0xfffffffffe4976dc>
 *   @0x304070 movwhs sp, #0x712c
 *   @0x304074 andslo pc, r4, sp, lsr #17
 *   @0x304078 ldrsblo pc, [r0, #-132]!
 *   @0x30407c blhs 0x3d2c88 <error_g0017+0x2b92c>
 *   @0x304080 ldm pc, {r1, r2, r3, r5, r11, r12, lr, pc} ^
 *   @0x304084 andseq pc, r0, #3
 *   @0x304088 blmi 0x9064ec <b2_toiTime+0x1ad048>
 *   @0x30408c movwhs r9, #0x304
 *   @0x304090 andslo pc, r6, sp, lsr #17
 *   @0x304094 ands r6, r3, r0, lsr r8
 *   @0x304098 movwls r4, #0x4b15
 *   @0x30409c .word 0xf8ad2301
 *   @0x3040a0 ldmdavs r0!, {r1, r2, r4, r12, sp} ^
 *   @0x3040a4 blmi 0x7fc0dc <b2_toiTime+0xa2c38>
 *   @0x3040a8 movwhs r9, #0x2304
 *   @0x3040ac andslo pc, r6, sp, lsr #17
 *   @0x3040b0 strh r6, [r5], -r0
 *   @0x3040b4 movwls r4, #0x4b10
 *   @0x3040b8 .word 0xf8ad2303
 *   @0x3040bc ldmvs r0!, {r1, r2, r4, r12, sp} ^
 *   @0x3040c0 .word 0x2100b170
 *   @0x3040c4 strmi r4, [r11], -r10, asr #12
 *   @0x3040c8 .word 0xf955f7e4
 *   @0x3040cc and r4, r7, r5, lsl #12
 *   @0x3040d0 and r2, r5, r11, lsl #10
 *   @0x3040d4 and r2, r3, r6, lsl #10
 *   @0x3040d8 ldrbtmi r4, [r11], #-2830
 *   @0x3040dc str r6, [pc, -r3, lsr #3]!
 *   @0x3040e0 andlt r4, r7, r8, lsr #12
 *   @0x3040e4 svchi #0xf0e8bd
 *   @0x3040e8 strbvc r6, [lr, #-0x963]!
 *   @0x3040ec .word 0x41444f42
 *   @0x3040f0 .word 0x41444245
 *   @0x3040f4 .word 0x41444243
 *   @0x3040f8 stclvs p4, c7, [r1], #-196
 *   @0x3040fc andeq r10, r8, pc, lsr r10
 *   @0x304100 andeq r10, r8, r12, asr r10
 *   @0x304104 strdeq r10, r11, [r8], -r2
 *   @0x304108 strheq r10, [r8], -r12
 *   @0x30410c andeq r10, r8, r2, lsl #17
 *   @0x304110 andeq r10, r8, r4, lsr #26
 *   @0x304114 andeq r10, r8, r2, lsr r7
 *   @0x304118 andlo pc, r0, #132096
 *   @0x30411c rscvc lr, r2, pc, asr #20
 *   @0x304120 andmi pc, r0, r0, lsl #10
 *   @0x304124 .word 0xf142181b
 *   @0x304128 b 0x16c4930 <b2_toiTime+0xf6b48c>
 *   @0x30412c b 0x1314180 <b2_toiTime+0xbbacdc>
 *   @0x304130 ldrbmi r4, [r0, -r2]!
 *   @0x304134 .word 0x460ab570
 *   @0x304138 movwhs r6, #0x804
 *   @0x30413c teqlt r2, r5, lsr #12
 *   @0x304140 blvs 0x38219c <_ZTS13C_UTF16String+0x19248>
 *   @0x304144 b 0x1492950 <b2_toiTime+0xd394ac>
 *   @0x304148 sbcslt r2, r2, #201326592
 *   @0x30414c strtmi lr, [r1], #-2039
 *   @0x304150 ldrmi r6, [r8], -r1
 *   @0x304154 ldrlt r11, [r0, #-0xd70]
 *   @0x304158 blhs 0x31f98c
 *   @0x30415c .word 0xf8d0db10
 *   @0x304160 addsmi r2, r3, #44, #2
 *   @0x304164 .word 0xf8d0da0c
 *   @0x304168 ldrbths r2, [r12], #304
 *   @0x30416c blx 0x415996 <g_RomDisk+0x1e176>
 *   @0x304170 bvs 0xfe5cd184 <b2_toiTime+0xfffffffffde73ce0>
 *   @0x304174 ldrmi r2, [r8, r0, lsl #2]
 *   @0x304178 sbcseq pc, r0, r4, asr #17
 *   @0x30417c adcseq pc, r4, r4, asr #17
 *   @0x304180 ldclt p0, c2, [r0, #-0]
 *   @0x304184 ldrsblo pc, [r12], r0
 *   @0x304188 subsvs r2, r10, #0, #4
 *   @0x30418c andhs r4, r0, r0, ror r7
 *   @0x304190 .word 0x47704770
 *   @0x304194 .word 0x008cf8d0
 *   @0x304198 stmdavc r3, {r3, r4, r8, r12, sp, pc}
 *   @0x30419c svclt #0x82b2f
 *   @0x3041a0 ldrbmi r3, [r0, -r1]!
 *   @0x3041a4 .word 0xf100b530
 *   @0x3041a8 strmi r0, [r12], -r4, lsr #11
 *   @0x3041ac strgt r12, [pc], #-3343
 *   @0x3041b0 muleq pc, r5, r8
 *   @0x3041b4 andeq lr, pc, r4, lsl #17
 *   @0x3041b8 ldclt p0, c2, [r0, #-0]!
 *   @0x3041bc ldrhlo pc, [r8, -r0]!
 *   @0x3041c0 andhi r2, r11, r0
 *   @0x3041c4 ldrlt r4, [r0, #-0x770]
 *   @0x3041c8 .word 0xf8d0b111
 *   @0x3041cc mulvs r12, r8, r0
 *   @0x3041d0 .word 0xf8d0b112
 *   @0x3041d4 mulsvs r1, r12, r0
 *   @0x3041d8 .word 0xf8d0b113
 *   @0x3041dc andsvs r2, r10, r0, lsr #1
 *   @0x3041e0 ldclt p0, c2, [r0, #-0]
 *   @0x3041e4 movwhs r11, #0x1109
 *   @0x3041e8 andhs r7, r0, r11
 *   @0x3041ec .word 0xb1024770
 *   @0x3041f0 andhs r6, r0, r1, lsl r0
 *   @0x3041f4 andeq r4, r0, r0, ror r7
 *   @0x3041f8 .word 0x4604b538
 *   @0x3041fc .word 0xf8d36843
 *   @0x304200 cmplt sp, r0, asr #2
 *   @0x304204 stmdbmi r6, {r0, r1, r3, r4, r9, r10, r11, sp, lr}
 *   @0x304208 ldrbtmi r6, [r9], #-2136
 *   @0x30420c cdp2 p7, #0x7, c15, c0, c1, #0x7
 *   @0x304210 stmdavs r11!, {r5, r8, r12, sp, pc} ^
 *   @0x304214 .word 0xf8d44798
 *   @0x304218 subsvs r3, r8, #156
 *   @0x30421c ldclt p0, c2, [r8, #-0]!
 *   @0x304220 andeq r10, r8, r12, lsl #19
 *   @0x304224 svcmi #0xf0e92d
 *   @0x304228 .word 0xf8d0b08b
 *   @0x30422c strhs r11, [r0], -r4
 *   @0x304230 .word 0x91024604
 *   @0x304234 .word 0xf8db9605
 *   @0x304238 .word 0xf8db3088
 *   @0x30423c .word 0xf8db2064
 *   @0x304240 movwls r8, #0x3148
 *   @0x304244 .word 0x3080f8db
 *   @0x304248 blvs 0x1ae8a54 <b2_toiTime+0x138f5b0>
 *   @0x30424c eorsle r2, r2, r0, lsl #30
 *   @0x304250 .word 0xf10d683b
 *   @0x304254 ldmdavs r8!, {r3, r4, r11} ^
 *   @0x304258 ldmdavs r11, {r1, r6, r9, r10, lr}
 *   @0x30425c mulls r5, r8, r7
 *   @0x304260 .word 0xf0402800
 *   @0x304264 blls 0x4a4620 <SrcVerts+0x1664>
 *   @0x304268 .word 0xf89ba80a
 *   @0x30426c .word 0xf8401120
 *   @0x304270 .word 0xf7ff3d18
 *   @0x304274 stcls p15, c15, [r7, #-380]
 *   @0x304278 orrslt r4, r5, r1, lsl #13
 *   @0x30427c .word 0x3120f8db
 *   @0x304280 stmdals r1, {r0, r2, r9, r11, sp, pc}
 *   @0x304284 strtmi r1, [r9], -sp, ror #21
 *   @0x304288 .word 0xff4df7e2
 *   @0x30428c strmi r9, [r6], -r5, lsl #22
 *   @0x304290 .word 0xf8dbb943
 *   @0x304294 strtmi r3, [r10], -r0, lsr #2
 *   @0x304298 ldrmi r9, [r9], #-2310
 *   @0x30429c stmib lr, {r1, r4, r5, r7, r8, r10, r12, sp, lr, pc}
 *   @0x3042a0 strtmi lr, [lr], -r0
 *   @0x3042a4 .word 0x4641683b
 *   @0x3042a8 ldmdavs r11, {r3, r4, r5, r6, r11, sp, lr} ^
 *   @0x3042ac blls 0x456114 <g_RomDisk+0x5e8f4>
 *   @0x3042b0 subsle r2, r12, r0, lsl #22
 *   @0x3042b4 .word 0xf8dbe0c4
 *   @0x3042b8 strbmi r3, [r0], -r4, lsr #2
 *   @0x3042bc .word 0x5120f8db
 *   @0x3042c0 ldrsbne pc, [r12, -r11]
 *   @0x3042c4 .word 0xf8db441d
 *   @0x3042c8 bls 0x3907a0 <_ZTS11b2GearJoint+0x200>
 *   @0x3042cc blx 0x39533a <ft_adobe_glyph_list+0x4a16>
 *   @0x3042d0 .word 0xf7e21105
 *   @0x3042d4 andls pc, r5, r8, ror #21
 *   @0x3042d8 strbmi r11, [r0], -r0, lsl #23
 *   @0x3042dc .word 0xf7e30069
 *   @0x3042e0 andls pc, r5, r0, lsr #27
 *   @0x3042e4 .word 0xf8d8bb50
 *   @0x3042e8 stcge p0, c3, [r10, #-128]
 *   @0x3042ec .word 0x1120f89b
 *   @0x3042f0 ldclo p8, c15, [r8, #-276]
 *   @0x3042f4 .word 0xf7ff4628
 *   @0x3042f8 .word 0xf89bff1d
 *   @0x3042fc strmi r1, [r1], r4, lsr #2
 *   @0x304300 .word 0xf7ff4628
 *   @0x304304 stmdbls r4, {r0, r1, r2, r4, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x304308 .word 0x2120f8db
 *   @0x30430c .word 0xf89b440a
 *   @0x304310 andls r1, r4, #36, #2
 *   @0x304314 strtmi r4, [r8], -r2, lsl #13
 *   @0x304318 .word 0xff0cf7ff
 *   @0x30431c strbmi r4, [r0], -r5, lsl #12
 *   @0x304320 stc2l p7, c15, [r10, #908]
 *   @0x304324 .word 0x212cf8db
 *   @0x304328 andle r4, r5, #608174080
 *   @0x30432c .word 0x2004f8d8
 *   @0x304330 stmdale r1, {r0, r2, r4, r7, r9, lr}
 *   @0x304334 stmdble r3, {r1, r3, r5, r7, r8, r10, lr}
 *   @0x304338 movwls r2, #0x5309
 *   @0x30433c rsbs r2, pc, r0, lsl #12
 *   @0x304340 streq lr, [r10, #-0xbb5]
 *   @0x304344 bge 0x478734 <g_RomDisk+0x80f14>
 *   @0x304348 strtmi r9, [r9], -r1, lsl #16
 *   @0x30434c cdp2 p7, #0xe, c15, c11, c2, #0x7
 *   @0x304350 strmi r9, [r6], -r5, lsl #20
 *   @0x304354 cmnle r3, r0, lsl #20
 *   @0x304358 ldrsbne pc, [r4, -r11]!
 *   @0x30435c ldrtmi r4, [r2], -r0, asr #12
 *   @0x304360 ldrbmi r4, [r1], #-1579
 *   @0x304364 blx 0xffec22f4 <b2_toiTime+0xffffffffff768e50>
 *   @0x304368 stmdahs r0, {r0, r2, r12, pc}
 *   @0x30436c .word 0xf8dbd168
 *   @0x304370 vand d3, d4, d28
 *   @0x304374 bl 0x3dbd0c <error_g0017+0x349b0>
 *   @0x304378 .word 0xf85302c9
 *   @0x30437c .word 0xf8c43039
 *   @0x304380 ldmdavs r3, {r2, r4, r6, r8, r10, r12, sp} ^
 *   @0x304384 .word 0xf8c422fc
 *   @0x304388 movwhs r3, #0x558
 *   @0x30438c ldrblo pc, [r12, #-0x8c4]
 *   @0x304390 strblo pc, [r0, #-0x8c4]!
 *   @0x304394 ldrsblo pc, [r0, -r11]!
 *   @0x304398 stmdblo r9, {r1, r8, r9, r11, r12, sp, lr, pc}
 *   @0x30439c bicseq pc, r8, #1073741826
 *   @0x3043a0 stm lr, {r0, r1, r2, r3, r8, r9, r11, lr, pc}
 *   @0x3043a4 .word 0xf109000f
 *   @0x3043a8 vhsub.s8 q0, q10, q12
 *   @0x3043ac ldm r2, {r2, r4, r5, r6, r8, r9, r12, lr}
 *   @0x3043b0 stm r3, {r0, r1}
 *   @0x3043b4 .word 0xf8d90003
 *   @0x3043b8 b 0xbd03d0 <b2_toiTime+0x476f2c>
 *   @0x3043bc strmi r7, [r8, #0x8e3]!
 *   @0x3043c0 ldrblo pc, [r0, #-0x8c4]
 *   @0x3043c4 movwhs sp, #0x9902
 *   @0x3043c8 eors r9, r9, r5, lsl #6
 *   @0x3043cc blle 0x48efd4 <prim_v+0x5620>
 *   @0x3043d0 ldrtmi r9, [r0], -r3, lsl #20
 *   @0x3043d4 ldmdbvs r3, {r0, r3, r5, r9, r10, lr}
 *   @0x3043d8 rsceq pc, r10, #268435460
 *   @0x3043dc bl 0xff516244 <b2_toiTime+0xfffffffffedbcda0>
 *   @0x3043e0 .word 0xf8d40205
 *   @0x3043e4 .word 0x462035d0
 *   @0x3043e8 .word 0x0108eb06
 *   @0x3043ec .word 0x46054798
 *   @0x3043f0 bllt 0xd2840c <b2_toiTime+0x5cef68>
 *   @0x3043f4 ldmdavs r11!, {r0, r1, r2, r5, r8, r9, r12, sp, pc}
 *   @0x3043f8 movwlt r6, #0xb89b
 *   @0x3043fc .word 0xf7e06a20
 *   @0x304400 strls pc, [r7, #-0xc8d]
 *   @0x304404 andls r1, r6, r0, lsl #8
 *   @0x304408 .word 0xf7e06aa0
 *   @0x30440c strne pc, [r0], #-3207
 *   @0x304410 bvs 0xffb28438 <b2_toiTime+0xffffffffff3cef94>
 *   @0x304414 stc2 p7, c15, [r2], {224}
 *   @0x304418 strtmi r9, [r10], -r2, lsl #18
 *   @0x30441c andls r1, r9, r0, lsl #8
 *   @0x304420 ldmdavs r8!, {r0, r1, r3, r4, r5, r11, sp, lr} ^
 *   @0x304424 .word 0xc008f8d3
 *   @0x304428 strbmi r10, [r0, r6, lsl #22]!
 *   @0x30442c ldreq r9, [r11], #-2822
 *   @0x304430 blls 0x51ccc4 <SrcVerts+0x79d08>
 *   @0x304434 adcvs r0, r3, #452984832
 *   @0x304438 ldreq r9, [r11], #-2825
 *   @0x30443c andls r6, r5, r3, ror #5
 *   @0x304440 ldrtmi r9, [r1], -r1, lsl #16
 *   @0x304444 .word 0xff77f7e2
 *   @0x304448 andlt r9, r11, r5, lsl #16
 *   @0x30444c svchi #0xf0e8bd
 *   @0x304450 svcmi #0xf0e92d
 *   @0x304454 .word 0xf8d0461e
 *   @0x304458 strmi r8, [r11], r4
 *   @0x30445c stcvs p2, c15, [r12, #-692]!
 *   @0x304460 ldrmi r4, [r1], r4, lsl #12
 *   @0x304464 ldrsblo pc, [r0], -r8
 *   @0x304468 .word 0x1088f8d8
 *   @0x30446c swpls r4, r10, [r7]
 *   @0x304470 smlabbhi r10, r0, r0, pc
 *   @0x304474 ldrsblo pc, [r0], -r11
 *   @0x304478 stmibmi r6, {r0, r4, r5, r6, r8, r10}
 *   @0x30447c .word 0xf046bf48
 *   @0x304480 .word 0xf0160603
 *   @0x304484 ldcge p15, c0, [r2, #-12]
 *   @0x304488 adclo pc, r4, r0, asr #17
 *   @0x30448c andhs r11, r0, #20, #30
 *   @0x304490 .word 0xf8db2201
 *   @0x304494 strvs r3, [r1], #20
 *   @0x304498 andls r9, r8, #114688
 *   @0x30449c adclo pc, r8, r0, asr #17
 *   @0x3044a0 .word 0xf8a02300
 *   @0x3044a4 .word 0xf8a0306e
 *   @0x3044a8 strtmi r3, [r8], -r12, rrx
 *   @0x3044ac strbmi r6, [r1], -r10, asr #17
 *   @0x3044b0 movwls r9, #0x1300
 *   @0x3044b4 movwls r9, #0x2b08
 *   @0x3044b8 movwmi pc, #0x33c6
 *   @0x3044bc blmi 0x20a90d0 <b2_toiTime+0x194fc2c>
 *   @0x3044c0 movwls r4, #0x447b
 *   @0x3044c4 ldmdavs r7, {r0, r1, r5, r9, r10, lr}
 *   @0x3044c8 sbfxmi r4, r10, #0xc, #0x19
 *   @0x3044cc stmdahs r0, {r0, r1, r2, r9, r10, lr}
 *   @0x3044d0 sbcshi pc, r11, r0, asr #32
 *   @0x3044d4 orrhs pc, r0, r6, asr #7
 *   @0x3044d8 .word 0x91094628
 *   @0x3044dc subne pc, r5, r5, lsl #17
 *   @0x3044e0 .word 0xf7ff4649
 *   @0x3044e4 .word 0x4607fe9f
 *   @0x3044e8 .word 0xf0402800
 *   @0x3044ec .word 0xf20d80ce
 *   @0x3044f0 .word 0xf10d53ac
 *   @0x3044f4 .word 0xf8d50928
 *   @0x3044f8 blgt 0x6edad0 <g_SWFvertbuff+0x1aa08>
 *   @0x3044fc andeq lr, pc, r9, lsl #17
 *   @0x304500 stmdbls r7, {r3, r5, r9, r10, lr}
 *   @0x304504 ldrbhs pc, [r8, #-0x8d5]!
 *   @0x304508 andls r6, r6, #13303808
 *   @0x30450c .word 0x4798685b
 *   @0x304510 bls 0x5604a4 <g_SWFlineaavertbuff+0xd3dc>
 *   @0x304514 movweq pc, #0x1003
 *   @0x304518 movweq pc, #0x4043
 *   @0x30451c biclt r6, r2, r3, ror #15
 *   @0x304520 .word 0xf8d46a28
 *   @0x304524 .word 0xf7e0609c
 *   @0x304528 strne pc, [r0], #-3065
 *   @0x30452c bvs 0xfed1cdb4 <b2_toiTime+0xfffffffffe5c3910>
 *   @0x304530 blx 0x424ba
 *   @0x304534 adcvs r1, r0, #0, #8
 *   @0x304538 muleq pc, r9, r8
 *   @0x30453c streq pc, [r12], #-262
 *   @0x304540 andeq lr, pc, r4, lsl #17
 *   @0x304544 .word 0xf8c69b06
 *   @0x304548 eorsvs r10, r3, #28
 *   @0x30454c eorsvc r2, r3, #67108864
 *   @0x304550 bvs 0xfed3c7c4 <b2_toiTime+0xfffffffffe5e3320>
 *   @0x304554 blx 0xffbc24de <b2_toiTime+0xffffffffff46903a>
 *   @0x304558 adcvs r1, r0, #0, #8
 *   @0x30455c .word 0xf7e06aa8
 *   @0x304560 .word 0xf8d4fbdd
 *   @0x304564 stmdbmi r11, {r2, r3, r4, r7, r12, sp} ^
 *   @0x304568 movvs r1, #0, #8
 *   @0x30456c .word 0xf8d8721f
 *   @0x304570 .word 0xf8d820d0
 *   @0x304574 strtvs r3, [r1], #200
 *   @0x304578 ldrne r1, [r11], #-2771
 *   @0x30457c .word 0x63e36363
 *   @0x304580 strhlo pc, [lr], -r11
 *   @0x304584 stmdale r3, {r0, r1, r2, r4, r8, r9, r11, sp}
 *   @0x304588 .word 0xf4436fe3
 *   @0x30458c strbvs r7, [r3, r0, lsl #7]!
 *   @0x304590 .word 0x3000f8d9
 *   @0x304594 svclo #0x80f5b3
 *   @0x304598 .word 0xf8d9d10a
 *   @0x30459c .word 0xf5b3300c
 *   @0x3045a0 smlabble r5, r0, pc, r3
 *   @0x3045a4 .word 0x3004f8d9
 *   @0x3045a8 .word 0xf8d9b913
 *   @0x3045ac orrlt r3, r3, r8
 *   @0x3045b0 rsbeq pc, r12, r4, lsl #2
 *   @0x3045b4 .word 0xf7e14649
 *   @0x3045b8 .word 0xf8d9ffe3
 *   @0x3045bc bvs 0xfeb085c4 <b2_toiTime+0xfffffffffe3af120>
 *   @0x3045c0 stc2 p7, c15, [r10, #1020]!
 *   @0x3045c4 .word 0x100cf8d9
 *   @0x3045c8 blvs 0x1b1d050 <b2_toiTime+0x13c3bac>
 *   @0x3045cc stc2 p7, c15, [r4, #1020]!
 *   @0x3045d0 .word 0xf1ba6360
 *   @0x3045d4 .word 0xd1010f00
 *   @0x3045d8 .word 0xb1629a06
 *   @0x3045dc .word 0xf1044651
 *   @0x3045e0 bls 0x484798 <g_matstack+0xc3c>
 *   @0x3045e4 .word 0xff1ef7e1
 *   @0x3045e8 stmdbls r6, {r0, r1, r5, r7, r9, r11, sp, lr}
 *   @0x3045ec adcvs r4, r3, #1392508928
 *   @0x3045f0 strmi r6, [r11], #-2915
 *   @0x3045f4 ldrbeq r6, [r2, r3, ror #6]!
 *   @0x3045f8 blls 0x8b96b8 <b2_toiTime+0x160214>
 *   @0x3045fc .word 0xf8d49908
 *   @0x304600 ldmdavs sp, {r2, r5, r7, sp, pc} ^
 *   @0x304604 .word 0x90a8f8d4
 *   @0x304608 bls 0xc30b94 <b2_toiTime+0x4d76f0>
 *   @0x30460c usaxmi r11, r1, r2
 *   @0x304610 .word 0xf7ff6aa0
 *   @0x304614 strbmi pc, [r9], -r1, lsl #27
 *   @0x304618 blvs 0x1b1d0a0 <b2_toiTime+0x13c3bfc>
 *   @0x30461c ldc2l p7, c15, [r12, #-1020]!
 *   @0x304620 ands r6, r9, r0, ror #6
 *   @0x304624 strhlt pc, [r2], -r3
 *   @0x304628 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30462c movweq lr, #0xbbc8
 *   @0x304630 blhs 0x311a58 <af_shaper_get_elem+0x72c6>
 *   @0x304634 ldrbmi sp, [r1], -r11, ror #27
 *   @0x304638 .word 0x0c08f855
 *   @0x30463c stc2l p7, c15, [r12, #-1020]!
 *   @0x304640 .word 0xf1084649
 *   @0x304644 .word 0xf8450801
 *   @0x304648 .word 0xf8550c08
 *   @0x30464c .word 0xf7ff0c04
 *   @0x304650 .word 0xf845fd63
 *   @0x304654 strb r0, [r9, r4, lsl #24]!
 *   @0x304658 .word 0xf104ad0e
 *   @0x30465c strtmi r0, [r9], -r12, rrx
 *   @0x304660 cdp2 p7, #0xb, c15, c4, c1, #0x7
 *   @0x304664 stmvs r11!, {r1, r3, r5, r11, sp, lr}
 *   @0x304668 bne 0xfe9de814 <b2_toiTime+0xfffffffffe285370>
 *   @0x30466c stmvs r11!, {r0, r1, r5, r7, r8, sp, lr} ^
 *   @0x304670 bne 0x195cf00 <b2_toiTime+0x1203a5c>
 *   @0x304674 rsbvs r6, r3, #1073741880
 *   @0x304678 strle r0, [r6, #-0x6f3]
 *   @0x30467c andseq pc, r8, r4, lsl #2
 *   @0x304680 .word 0xf7e06b61
 *   @0x304684 and pc, r0, sp, lsr #30
 *   @0x304688 ldrtmi r2, [r8], -r6, lsl #14
 *   @0x30468c stcvs p2, c15, [r12, #-52]!
 *   @0x304690 svchi #0xf0e8bd
 *   @0x304694 svcvs #0x75746c
 *   @0x304698 .word 0xfffffd61
 *   @0x30469c mvnsmi lr, sp, lsr #18
 *   @0x3046a0 stmdahs r0, {r2, r9, r10, lr}
 *   @0x3046a4 .word 0xf8d0d078
 *   @0x3046a8 mcrvs p1, #0x2, r3, c6, c12, #0x1
 *   @0x3046ac strhs r11, [r0, #-0x313]
 *   @0x3046b0 .word 0xf8d446a8
 *   @0x3046b4 addsmi r3, sp, #44, #2
 *   @0x3046b8 .word 0xf8d4da14
 *   @0x3046bc bl 0x4e0bb4 <SrcVerts+0x3dbf8>
 *   @0x3046c0 ldmdavs r11!, {r0, r2, r6, r7, r8, r9, r10} ^
 *   @0x3046c4 ldmdavs r9, {r0, r1, r5, r6, r8, r12, sp, pc}
 *   @0x3046c8 .word 0xf7e24630
 *   @0x3046cc ldmdavs r11!, {r2, r4, r5, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x3046d0 .word 0xf8c34630
 *   @0x3046d4 ldmdavs r9!, {pc} ^
 *   @0x3046d8 cdp2 p7, #0x2, c15, c13, c2, #0x7
 *   @0x3046dc andhi pc, r4, r7, asr #17
 *   @0x3046e0 strb r3, [r6, r1, lsl #10]!
 *   @0x3046e4 .word 0xf8d44630
 *   @0x3046e8 .word 0xf7e2113c
 *   @0x3046ec movwhs pc, #0xe24
 *   @0x3046f0 teqlo r12, r4, asr #17
 *   @0x3046f4 .word 0xf8d44630
 *   @0x3046f8 strhs r1, [r0, #-0xa4]
 *   @0x3046fc cdp2 p7, #0x1, c15, c11, c2, #0x7
 *   @0x304700 .word 0xf8d44630
 *   @0x304704 .word 0xf8c410a8
 *   @0x304708 .word 0xf7e250a4
 *   @0x30470c shadd16mi pc, r0, r4
 *   @0x304710 .word 0x10acf8d4
 *   @0x304714 adcpl pc, r8, r4, asr #17
 *   @0x304718 cdp2 p7, #0x0, c15, c13, c2, #0x7
 *   @0x30471c .word 0xf8d44630
 *   @0x304720 .word 0xf8c410b0
 *   @0x304724 .word 0xf7e250ac
 *   @0x304728 ldrtmi pc, [r0], -r6, lsl #28
 *   @0x30472c ldrsbtne pc, [r4], r4
 *   @0x304730 adcspl pc, r0, r4, asr #17
 *   @0x304734 ldc2l p7, c15, [pc, #904]!
 *   @0x304738 .word 0xf8d44630
 *   @0x30473c .word 0xf8c41130
 *   @0x304740 .word 0xf7e250b4
 *   @0x304744 shsub8mi pc, r0, r8
 *   @0x304748 .word 0x108cf8d4
 *   @0x30474c teqpl r0, r4, asr #17
 *   @0x304750 smlawtpl r12, r4, r8, pc
 *   @0x304754 stc2l p7, c15, [pc, #904]!
 *   @0x304758 .word 0xf8d44630
 *   @0x30475c .word 0xf8c41098
 *   @0x304760 .word 0xf7e2508c
 *   @0x304764 ldrtmi pc, [r0], -r8, ror #27
 *   @0x304768 ldrsbne pc, [r12], r4
 *   @0x30476c addspl pc, r8, r4, asr #17
 *   @0x304770 stc2l p7, c15, [r1, #904]!
 *   @0x304774 .word 0xf8d44630
 *   @0x304778 .word 0xf8c41144
 *   @0x30477c .word 0x6165509c
 *   @0x304780 .word 0xf7e261a5
 *   @0x304784 .word 0xf8c4fdd8
 *   @0x304788 ldrtmi r5, [r0], -r4, asr #2
 *   @0x30478c .word 0x1148f8d4
 *   @0x304790 ldc2l p7, c15, [r1, #904]
 *   @0x304794 smlalbtpl pc, r8, r4, r8
 *   @0x304798 ldrhhi lr, [r0, #141]!
 *   @0x30479c .word 0x4606b5f0
 *   @0x3047a0 addlt r6, r7, sp, lsl #28
 *   @0x3047a4 blle 0x184fbac <b2_toiTime+0x10f6708>
 *   @0x3047a8 .word 0x312cf8d0
 *   @0x3047ac ble 0x1755228 <b2_toiTime+0xffbd84>
 *   @0x3047b0 ldrsbvc pc, [r0, -r0]!
 *   @0x3047b4 blvs 0x1616164 <b2_toiTime+0xebccc0>
 *   @0x3047b8 movwhs r4, #0x3608
 *   @0x3047bc strmi r2, [r0, r6, lsl #2]!
 *   @0x3047c0 stclle p8, c2, [r9, #-20]
 *   @0x3047c4 .word 0x2c009c03
 *   @0x3047c8 rsbmi r11, r4, #184, #30
 *   @0x3047cc suble r2, r3, r0, lsl #24
 *   @0x3047d0 svclo #0x80f5b4
 *   @0x3047d4 strtmi sp, [r1], -r7, lsr #32
 *   @0x3047d8 rsbsvc pc, r10, pc, asr #8
 *   @0x3047dc blx 0x1e02766 <b2_toiTime+0x16a92c2>
 *   @0x3047e0 .word 0xf8a64621
 *   @0x3047e4 stmdals r0, {r2, r6}
 *   @0x3047e8 blx 0x1c82772 <b2_toiTime+0x15292ce>
 *   @0x3047ec andls r4, r0, r1, lsr #12
 *   @0x3047f0 .word 0xf7e09801
 *   @0x3047f4 strtmi pc, [r1], -r0, ror #22
 *   @0x3047f8 stmdals r2, {r0, r12, pc}
 *   @0x3047fc blx 0x1a02786 <b2_toiTime+0x12a92e2>
 *   @0x304800 andls r4, r2, r1, lsr #12
 *   @0x304804 .word 0xf7e09804
 *   @0x304808 qsaxmi pc, r1, r6
 *   @0x30480c stmdals r5, {r2, r12, pc}
 *   @0x304810 blx 0x178279a <b2_toiTime+0x10292f6>
 *   @0x304814 bmi 0x7ab428 <b2_toiTime+0x51f84>
 *   @0x304818 .word 0x0323ea12
 *   @0x30481c .word 0xf44fbf38
 *   @0x304820 movwls r3, #0x3380
 *   @0x304824 .word 0x23fc9005
 *   @0x304828 blx 0x3eb032 <bdf_driver_class+0x4aa>
 *   @0x30482c .word 0xf8c37305
 *   @0x304830 bls 0x34cb98
 *   @0x304834 rschs pc, r0, r3, asr #17
 *   @0x304838 .word 0xf8c39a02
 *   @0x30483c bls 0x3ccbb4 <error_g0017+0x25858>
 *   @0x304840 rschs pc, r4, r3, asr #17
 *   @0x304844 ldrhhs pc, [r2], -sp
 *   @0x304848 rschs pc, r8, r3, asr #17
 *   @0x30484c ldrhhs pc, [r6], -sp
 *   @0x304850 rschs pc, r12, r3, asr #17
 *   @0x304854 and r2, r0, r0
 *   @0x304858 andlt r2, r7, r3
 *   @0x30485c svclt #0xbdf0
 *   @0x304860 .word 0xffff0000
 *   @0x304864 strdlt r11, r12, [r5], r0
 *   @0x304868 movwhs r6, #0xe46
 *   @0x30486c movwls r4, #0x3604
 *   @0x304870 bvs 0x15d6098 <b2_toiTime+0xe7cbf4>
 *   @0x304874 ldrmi r6, [r8, pc, lsl #25]
 *   @0x304878 ble 0x38c094 <_ZTS7CBucketILj16384ELj262144ELb1EE+0xf0>
 *   @0x30487c movwls r2, #0x3303
 *   @0x304880 ldmdavs r8!, {r2, r5, sp, lr, pc} ^
 *   @0x304884 .word 0xf0142164
 *   @0x304888 .word 0xf8d4e9e0
 *   @0x30488c addmi r2, r5, #48, #2
 *   @0x304890 strmi r11, [r5], -r8, lsr #30
 *   @0x304894 blge 0x3f2fe4 <SVN_VertexShader+0x1b0>
 *   @0x304898 movwls r9, #0x1200
 *   @0x30489c qasxmi r4, r11, r0
 *   @0x3048a0 .word 0xf7e321fc
 *   @0x3048a4 blls 0x40387c <g_RomDisk+0xc05c>
 *   @0x3048a8 teqeq r0, r4, asr #17
 *   @0x3048ac mvnshs r11, r3, ror r9
 *   @0x3048b0 .word 0xf8c42004
 *   @0x3048b4 .word 0xf8d4512c
 *   @0x3048b8 addsmi r2, r3, #44, #2
 *   @0x3048bc .word 0xf8d4da06
 *   @0x3048c0 blx 0x34cd8a
 *   @0x3048c4 movwlo r2, #0x1203
 *   @0x3048c8 ubfx r6, r0, #0x0, #0x15
 *   @0x3048cc andlt r9, r5, r3, lsl #16
 *   @0x3048d0 strdeq r11, r12, [r0], -r0
 *   @0x3048d4 ldrbtmi r4, [r8], #-2049
 *   @0x3048d8 ldclt p7, c15, [r11, #-896]!
 *   @0x3048dc andeq r5, lr, r2, lsr #1
 *   @0x3048e0 mcrvs p5, #0x0, r11, c3, c0, #0x0
 *   @0x3048e4 .word 0xf8d04908
 *   @0x3048e8 ldrbtmi r4, [r9], #-320
 *   @0x3048ec .word 0xf7e16858
 *   @0x3048f0 .word 0x4603faff
 *   @0x3048f4 tstlt r12, r0, lsr r1
 *   @0x3048f8 tstlt r11, r3, lsr #16
 *   @0x3048fc ldclt p7, c4, [r0, #-608]
 *   @0x304900 ldclt p6, c4, [r0, #-128]
 *   @0x304904 ldclt p6, c4, [r0, #-96]
 *   @0x304908 andeq r10, r8, r12, lsr #5
 *   @0x30490c .word 0x4604b537
 *   @0x304910 .word 0xf7e06800
 *   @0x304914 stmdavs r0!, {r0, r3, r4, r5, r9, r10, r11, r12, sp, lr, pc}
 *   @0x304918 .word 0xffe2f7ff
 *   @0x30491c bvs 0xfebb0e04 <b2_toiTime+0xfffffffffe457960>
 *   @0x304920 stmdbvs r1!, {r8, r9, sp}
 *   @0x304924 stmdavs r5, {r8, r9, r12, pc} ^
 *   @0x304928 stmdbvs r2!, {r4, r11, sp, lr} ^
 *   @0x30492c andhs r4, r0, r8, lsr #15
 *   @0x304930 ldclt p0, c11, [r0, #-12]!
 *   @0x304934 .word 0x4604b510
 *   @0x304938 ldmdavs r11, {r0, r1, r7, r9, r11, sp, lr}
 *   @0x30493c stmdavs r0, {r0, r1, r4, r6, r8, r12, sp, pc}
 *   @0x304940 .word 0xffcef7ff
 *   @0x304944 bvs 0xfebf0dac <b2_toiTime+0xfffffffffe497908>
 *   @0x304948 ldmdavs r8, {r1, r7, r11, sp, lr}
 *   @0x30494c bvs 0xfebd6794 <b2_toiTime+0xfffffffffe47d2f0>
 *   @0x304950 andsvs r2, r10, r0, lsl #4
 *   @0x304954 ldrlt r11, [r7, #-0xd10]!
 *   @0x304958 stmdavs r0, {r2, r9, r10, lr}
 *   @0x30495c .word 0xffc0f7ff
 *   @0x304960 stmdavs r3!, {r4, r5, r6, r8, r12, sp, pc}
 *   @0x304964 .word 0xf8d36805
 *   @0x304968 ldmdavs r9, {r4, r5, r8, sp} ^
 *   @0x30496c .word 0x23fc6e58
 *   @0x304970 .word 0x2101fb03
 *   @0x304974 strmi r10, [r8, r1, lsl #20]!
 *   @0x304978 bvs 0xfebb2dc0 <b2_toiTime+0xfffffffffe45991c>
 *   @0x30497c andsvs r9, r3, r1, lsl #22
 *   @0x304980 ldclt p0, c11, [r0, #-12]!
 *   @0x304984 svcmi #0xf0e92d
 *   @0x304988 .word 0xf8dfb0f1
 *   @0x30498c ldcge p8, c7, [r2, #-608]
 *   @0x304990 strmi r6, [r1], r6, asr #28
 *   @0x304994 ldmdavs pc!, {r0, r1, r2, r3, r4, r5, r6, r10, lr}
 *   @0x304998 rsbhs r9, r8, #8, #2
 *   @0x30499c ldmdavs r11!, {r8, sp}
 *   @0x3049a0 strls r4, [r7], -r8, lsr #12
 *   @0x3049a4 .word 0xf5b1936f
 *   @0x3049a8 .word 0xf8d9ee04
 *   @0x3049ac smlabbhs r0, r8, r0, r6
 *   @0x3049b0 strtmi r2, [r8], -r4, ror #4
 *   @0x3049b4 .word 0x4068f8d9
 *   @0x3049b8 ldcl p5, c15, [r10, #708]!
 *   @0x3049bc .word 0x21006873
 *   @0x3049c0 strtmi r4, [r8], -r10, lsl #12
 *   @0x3049c4 blls 0x4dea44 <SrcVerts+0x3ba88>
 *   @0x3049c8 strtvs r4, [r12], #1968
 *   @0x3049cc .word 0xf7e14620
 *   @0x3049d0 ldrhhs pc, [pc, -r7]
 *   @0x3049d4 strtmi r9, [r0], -r6
 *   @0x3049d8 blx 0xc0296c <b2_toiTime+0x4a94c8>
 *   @0x3049dc strmi r9, [r6], -r12, lsl #14
 *   @0x3049e0 .word 0xf0402800
 *   @0x3049e4 .word 0xf8df8106
 *   @0x3049e8 andshs r1, pc, #64, #16
 *   @0x3049ec ldrbtmi r6, [r9], #-2592
 *   @0x3049f0 ldcl p5, c15, [r6, #708]!
 *   @0x3049f4 svclt #0x142800
 *   @0x3049f8 strhs r2, [r0], -r2, lsl #12
 *   @0x3049fc .word 0xf7e34620
 *   @0x304a00 .word 0x2e00fa5b
 *   @0x304a04 rscshi pc, r5, r0, asr #32
 *   @0x304a08 stmdalo r0!, {r0, r1, r2, r3, r4, r6, r7, r11, r12, sp, lr, pc}
 *   @0x304a0c movwls r4, #0xd47b
 *   @0x304a10 .word 0xf8df4620
 *   @0x304a14 .word 0xf7e1a81c
 *   @0x304a18 .word 0xf10dff93
 *   @0x304a1c ldrbtmi r0, [r10], #2992
 *   @0x304a20 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x304a24 strne pc, [r9], -r0, asr #4
 *   @0x304a28 strtmi r4, [r0], -r5, lsl #12
 *   @0x304a2c .word 0xf7e16867
 *   @0x304a30 ldrbmi pc, [r9], -r7, lsl #31
 *   @0x304a34 adcsmi r1, r0, #56, #20
 *   @0x304a38 .word 0x4607bf34
 *   @0x304a3c qasxmi r4, r0, r7
 *   @0x304a40 .word 0xf7e1463a
 *   @0x304a44 strmi pc, [r6], -r4, lsr #31
 *   @0x304a48 .word 0xf0402800
 *   @0x304a4c svcne #0xbe80d2
 *   @0x304a50 andeq pc, r7, r11, lsl #16
 *   @0x304a54 .word 0xf10d445e
 *   @0x304a58 .word 0x96050bb0
 *   @0x304a5c ldrbmi r9, [lr], -r5, lsl #22
 *   @0x304a60 eorle r4, r4, #650117120
 *   @0x304a64 .word 0xf10b7832
 *   @0x304a68 bhs 0x17c7674 <b2_toiTime+0x106e1d0>
 *   @0x304a6c ldrtmi sp, [r0], -r7, lsl #2
 *   @0x304a70 andhs r4, r9, #84934656
 *   @0x304a74 ldc p5, c15, [r4, #708]!
 *   @0x304a78 strlo r11, [r10, #-0x908]
 *   @0x304a7c .word 0xf89be00b
 *   @0x304a80 bhs 0x1fcca88 <b2_toiTime+0x18735e4>
 *   @0x304a84 ldrtmi sp, [r0], -r10, ror #3
 *   @0x304a88 andhs r9, r6, #212992
 *   @0x304a8c stc p5, c15, [r8, #708]!
 *   @0x304a90 mvnle r2, r0, lsl #16
 *   @0x304a94 bge 0xe11eb8 <b2_toiTime+0x6b8a14>
 *   @0x304a98 bne 0xfefd6320 <b2_toiTime+0xfffffffffe87ce7c>
 *   @0x304a9c ldrmi r9, [sp], #-3590
 *   @0x304aa0 ldrtmi r1, [r1], -pc, lsr #23
 *   @0x304aa4 cdp2 p7, #0xf, c15, c15, c1, #0x7
 *   @0x304aa8 .word 0xb1a84606
 *   @0x304aac strbmi lr, [r7], #-161
 *   @0x304ab0 vmax.f32 d18, d0, d8
 *   @0x304ab4 .word 0xf10d809b
 *   @0x304ab8 .word 0xf1a70bb0
 *   @0x304abc ldrbmi r0, [r9], #-265
 *   @0x304ac0 ldrbmi r2, [r8], -r9, lsl #4
 *   @0x304ac4 stmdaeq r9, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x304ac8 stcl p5, c15, [r4, #708]!
 *   @0x304acc strvc pc, [r0, #0x505]
 *   @0x304ad0 strvc pc, [r0], pc, asr #8
 *   @0x304ad4 str r4, [r8, r3, asr #9]!
 *   @0x304ad8 ldrtmi r4, [r9], -r0, lsr #12
 *   @0x304adc .word 0xf10daa25
 *   @0x304ae0 .word 0xf7e30a48
 *   @0x304ae4 .word 0x4606f9de
 *   @0x304ae8 .word 0xf0402800
 *   @0x304aec .word 0xf8da8082
 *   @0x304af0 .word 0xf04f804c
 *   @0x304af4 .word 0xf8ca32ff
 *   @0x304af8 usaxmi r7, r0, r0
 *   @0x304afc .word 0xf8ca4447
 *   @0x304b00 .word 0xf8ca2060
 *   @0x304b04 .word 0xf8da7008
 *   @0x304b08 .word 0xf8ca2020
 *   @0x304b0c .word 0xf8ca5054
 *   @0x304b10 .word 0xf8ca8004
 *   @0x304b14 ldrmi r8, [r0, r0]
 *   @0x304b18 ldrsbhs pc, [r12], -r10
 *   @0x304b1c .word 0x47904650
 *   @0x304b20 .word 0x2020f8da
 *   @0x304b24 .word 0xf8da4650
 *   @0x304b28 ldrmi r7, [r0, r0]
 *   @0x304b2c ldrsbhs pc, [r12], -r10
 *   @0x304b30 .word 0x47904650
 *   @0x304b34 .word 0x3008f8da
 *   @0x304b38 .word 0xb000f8da
 *   @0x304b3c .word 0x96091f9e
 *   @0x304b40 .word 0xf8df9305
 *   @0x304b44 .word 0xf8df66f0
 *   @0x304b48 ldrbtmi r3, [lr], #-1776
 *   @0x304b4c ldrbtmi r9, [r11], #-1547
 *   @0x304b50 cdpls p3, #0x0, c9, c9, c10, #0x0
 *   @0x304b54 ldmdale r12!, {r0, r1, r4, r5, r7, r8, r10, lr}
 *   @0x304b58 .word 0xf10d9e15
 *   @0x304b5c vmlshs.f32 s0, s0, s16
 *   @0x304b60 .word 0xf89bd147
 *   @0x304b64 bhs 0x17ccb6c <b2_toiTime+0x10736c8>
 *   @0x304b68 blls 0x478fe4 <g_RomDisk+0x817c4>
 *   @0x304b6c andeq pc, r9, #-1073741784
 *   @0x304b70 ldmdale r8, {r0, r1, r4, r7, r8, r10, lr}
 *   @0x304b74 stmdbls r10, {r3, r4, r6, r9, r10, lr}
 *   @0x304b78 .word 0xf5b12209
 *   @0x304b7c ldmiblt r0, {r1, r4, r5, r8, r10, r11, sp, lr, pc}
 *   @0x304b80 ssatne pc, #0x19, pc, asr #17
 *   @0x304b84 andhs r4, r5, #64, #12
 *   @0x304b88 .word 0xf5b14479
 *   @0x304b8c stmdahs r0, {r1, r3, r5, r8, r10, r11, sp, lr, pc}
 *   @0x304b90 ldrtmi sp, [r8], -pc, lsr #2
 *   @0x304b94 andhs r4, r10, #51380224
 *   @0x304b98 stcl p5, c15, [r10, #-708]!
 *   @0x304b9c blle 0xc4eba4 <b2_toiTime+0x4f5700>
 *   @0x304ba0 subseq pc, r8, r10, asr #17
 *   @0x304ba4 .word 0xf89be025
 *   @0x304ba8 blhs 0x1fd0bb4 <b2_toiTime+0x1877710>
 *   @0x304bac ldrbmi sp, [r8], -r5, lsl #2
 *   @0x304bb0 andhs r9, r6, #180224
 *   @0x304bb4 ldc p5, c15, [r4, #-708]
 *   @0x304bb8 mrcge p1, #0x0, r11, c2, c0, #0x6
 *   @0x304bbc ssatmi r9, #0x19, r10, lsl #22
 *   @0x304bc0 shsaxmi r4, r0, pc
 *   @0x304bc4 ldmibvs r3!, {r3, r4, r7, r8, r9, r10, lr} ^
 *   @0x304bc8 .word 0x47984630
 *   @0x304bcc .word 0xb000f8d6
 *   @0x304bd0 .word 0x4620e7bf
 *   @0x304bd4 .word 0xf7e3a925
 *   @0x304bd8 qadd16mi pc, r0, r8
 *   @0x304bdc .word 0xf7e14629
 *   @0x304be0 strmi pc, [r6], -r2, ror #28
 *   @0x304be4 .word 0xf43f2800
 *   @0x304be8 and r10, r2, r3, lsl pc
 *   @0x304bec and r2, r0, r3, lsl #12
 *   @0x304bf0 stcge p6, c2, [pc, #-8]
 *   @0x304bf4 cdphs p0, #0x0, c6, c0, c14, #0x1
 *   @0x304bf8 sbchi pc, r12, #64
 *   @0x304bfc .word 0xf8dfac12
 *   @0x304c00 .word 0xf8d4a640
 *   @0x304c04 stcvs p0, c8, [r7, #-304]!
 *   @0x304c08 .word 0x60e644fa
 *   @0x304c0c .word 0x6634f8df
 *   @0x304c10 adcvs r4, r7, r7, asr #8
 *   @0x304c14 .word 0x9605447e
 *   @0x304c18 andhi pc, r0, r4, asr #17
 *   @0x304c1c stmibvs r3!, {r5, r9, r10, lr} ^
 *   @0x304c20 stmdavs r6!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x304c24 movwle r4, #0x32be
 *   @0x304c28 bleq 0x7c12cc <b2_toiTime+0x67e28>
 *   @0x304c2c and r10, r7, r2, lsl r11
 *   @0x304c30 bleq 0x7812d0 <b2_toiTime+0x27e2c>
 *   @0x304c34 stmdavc r2, {r1, r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x304c38 stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x304c3c andle r2, r3, r5, lsr #20
 *   @0x304c40 .word 0x464045d8
 *   @0x304c44 strd sp, lr, [pc], -r7
 *   @0x304c48 andshs r4, r1, #84934656
 *   @0x304c4c .word 0xf5b19302
 *   @0x304c50 blls 0x3bff78 <error_g0017+0x18c1c>
 *   @0x304c54 mvnsle r2, r0, lsl #16
 *   @0x304c58 .word 0x212cf8d9
 *   @0x304c5c .word 0xddef2a00
 *   @0x304c60 andlo r6, r1, #416
 *   @0x304c64 .word 0xe7eb661a
 *   @0x304c68 suble r4, r9, #-536870901
 *   @0x304c6c strtmi r6, [r0], -r3, lsr #20
 *   @0x304c70 stmdavs r3!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x304c74 suble r4, r3, #-1342177269
 *   @0x304c78 bhs 0x31f008
 *   @0x304c7c ldmdavc r2!, {r6, r8, r12, lr, pc}
 *   @0x304c80 teqle r10, pc, lsr #20
 *   @0x304c84 addsmi r1, r7, #45568
 *   @0x304c88 ldclne p9, c13, [r1], #-220
 *   @0x304c8c .word 0x1e4b1a59
 *   @0x304c90 ldmdale r2!, {r2, r4, r8, r9, r11, sp}
 *   @0x304c94 .word 0xf1009805
 *   @0x304c98 .word 0xf858084c
 *   @0x304c9c .word 0xf1a82c24
 *   @0x304ca0 cmplt r2, #36, #22
 *   @0x304ca4 ldmdavc r3, {r4, r5, r6, r11, r12, sp, lr}
 *   @0x304ca8 .word 0xd1134298
 *   @0x304cac .word 0x91034610
 *   @0x304cb0 .word 0xf5b19202
 *   @0x304cb4 stmdbls r3, {r1, r6, r10, r11, sp, lr, pc}
 *   @0x304cb8 addmi r9, r1, #8192
 *   @0x304cbc movwhs sp, #0x110a
 *   @0x304cc0 andle r4, r10, r11, lsl #5
 *   @0x304cc4 .word 0xf89018f0
 *   @0x304cc8 ldclpl p0, c14, [r0], {1}
 *   @0x304ccc smlabble r1, r6, r5, r4
 *   @0x304cd0 ldrb r3, [r5, r1, lsl #6]!
 *   @0x304cd4 stmdaeq r4!, {r3, r8, r12, sp, lr, pc}
 *   @0x304cd8 .word 0xf8dbe7df
 *   @0x304cdc .word 0xf10d1008
 *   @0x304ce0 stmdbhs r11, {r3, r6, r11}
 *   @0x304ce4 rsbhi pc, r8, #64
 *   @0x304ce8 .word 0xf8db4648
 *   @0x304cec strtmi r3, [r1], -r12
 *   @0x304cf0 stmvs r0!, {r3, r4, r7, r8, r9, r10, lr} ^
 *   @0x304cf4 andeq pc, r12, r8, asr #17
 *   @0x304cf8 .word 0xf8ddb940
 *   @0x304cfc str r8, [r11, r8, asr #32]
 *   @0x304d00 .word 0x312cf8d9
 *   @0x304d04 ldmdals r5, {r0, r1, r3, r8, r12, sp, pc}
 *   @0x304d08 andhs lr, r3, r0
 *   @0x304d0c stmdahs r0, {r3, r5, sp, lr}
 *   @0x304d10 subhi pc, r0, #64
 *   @0x304d14 cdphs p14, #0x0, c9, c0, c8, #0x0
 *   @0x304d18 eorshi pc, r12, #192, #4
 *   @0x304d1c .word 0x21289807
 *   @0x304d20 .word 0xf7e2462a
 *   @0x304d24 stmdavs r11!, {r9, r11, r12, sp, lr, pc}
 *   @0x304d28 smlalbteq pc, r8, r9, r8
 *   @0x304d2c .word 0xf0402b00
 *   @0x304d30 svcge #0x128231
 *   @0x304d34 .word 0xf8d96dba
 *   @0x304d38 bhs 0x31cee0
 *   @0x304d3c addshi pc, r6, r0
 *   @0x304d40 ldclvs p8, c6, [r11, #-452]!
 *   @0x304d44 bne 0xff5ead68 <b2_toiTime+0xfffffffffee918c4>
 *   @0x304d48 qadd8mi r4, r10, r10
 *   @0x304d4c ldrvs r11, [r11, #0xf88]!
 *   @0x304d50 .word 0xf7e26da1
 *   @0x304d54 stmdavs r10!, {r3, r5, r6, r7, r8, r11, r12, sp, lr, pc}
 *   @0x304d58 .word 0xf8c94683
 *   @0x304d5c bhs 0x305274 <TT_New_Context+0x506c>
 *   @0x304d60 andshi pc, r8, #64
 *   @0x304d64 .word 0x7068f8d9
 *   @0x304d68 .word 0xf8d46d61
 *   @0x304d6c shsaxmi r8, r8, r8
 *   @0x304d70 ldc2 p7, c15, [r9, #900]
 *   @0x304d74 stmdahs r0, {r1, r2, r9, r10, lr}
 *   @0x304d78 .word 0xf10dd16a
 *   @0x304d7c ldrbmi r0, [r8], #2736
 *   @0x304d80 andshi pc, r8, sp, asr #17
 *   @0x304d84 stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x304d88 .word 0xf8cd4651
 *   @0x304d8c blls 0x4ace04 <SrcVerts+0x9e48>
 *   @0x304d90 subsle r4, sp, #650117120
 *   @0x304d94 tstle r12, #339738624
 *   @0x304d98 .word 0xf7e14638
 *   @0x304d9c ldmdavs r10!, {r0, r4, r6, r7, r8, r10, r11, r12, sp, lr, pc} ^
 *   @0x304da0 pkhbtmi r1, r2, r2, lsl #20
 *   @0x304da4 strths sp, [r0], r1, lsl #2
 *   @0x304da8 shsaxmi lr, r8, r2
 *   @0x304dac .word 0xf5b2a92c
 *   @0x304db0 svclt #0x287f80
 *   @0x304db4 addvc pc, r0, #1325400064
 *   @0x304db8 stc2l p7, c15, [r9, #900]!
 *   @0x304dbc mrsle r2, spsr
 *   @0x304dc0 .word 0xf7e14638
 *   @0x304dc4 stmdbge r12!, {r0, r2, r3, r4, r5, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x304dc8 andeq lr, r0, r10, asr #23
 *   @0x304dcc beq 0xfef41208 <b2_toiTime+0xfffffffffe7e7d64>
 *   @0x304dd0 stmdavc r10, {r1, r7, r10, lr}
 *   @0x304dd4 cdpeq p1, #0x3, c15, c0, c2, #0x5
 *   @0x304dd8 svceq #0x9f1be
 *   @0x304ddc blx 0x1afadec <b2_toiTime+0x13a1948>
 *   @0x304de0 ands pc, pc, lr, lsl #29
 *   @0x304de4 cdpeq p1, #0x6, c15, c1, c2, #0x5
 *   @0x304de8 .word 0xfe8efa5f
 *   @0x304dec svceq #0x5f1be
 *   @0x304df0 .word 0xf1a2d918
 *   @0x304df4 stmdahs r5, {r0, r6}
 *   @0x304df8 blo 0x10fae0c <b2_toiTime+0x9a1968>
 *   @0x304dfc .word 0xfe82fa5f
 *   @0x304e00 .word 0xf1a2e010
 *   @0x304e04 stmdahs r1, {r0, r3}
 *   @0x304e08 .word 0xf1a2d91f
 *   @0x304e0c stmdahs r1, {r2, r3}
 *   @0x304e10 .word 0xf012d91b
 *   @0x304e14 ldrsble r0, [r8], -pc
 *   @0x304e18 bicle r2, r4, lr, lsr r10
 *   @0x304e1c .word 0xf04f2001
 *   @0x304e20 and r0, r0, r0, lsl #28
 *   @0x304e24 .word 0xf1b82000
 *   @0x304e28 andle r0, r4, r0, lsl #30
 *   @0x304e2c vmlsne.f32 s28, s28, s30
 *   @0x304e30 and pc, r0, r11, lsl #17
 *   @0x304e34 .word 0xf89be004
 *   @0x304e38 ldrmi r2, [r6], #0
 *   @0x304e3c bl 0x382e70 <_ZTS13C_UTF16String+0x19f1c>
 *   @0x304e40 stmdaeq r1, {r3, r6, r7, r8, r12, sp, lr, pc}
 *   @0x304e44 .word 0xf888fa5f
 *   @0x304e48 .word 0x3101b910
 *   @0x304e4c .word 0x4606e79f
 *   @0x304e50 cdphs p0, #0x0, c6, c0, c14, #0x1
 *   @0x304e54 orrshi pc, lr, r0, asr #32
 *   @0x304e58 .word 0x0148f8d9
 *   @0x304e5c .word 0x1144f8d9
 *   @0x304e60 .word 0xf7e16da2
 *   @0x304e64 .word 0xf8c9fd12
 *   @0x304e68 and r6, r11, r4, lsr r1
 *   @0x304e6c cdpgt p6, #0x0, c4, c15, c4, #0x0
 *   @0x304e70 cdpgt p4, #0x0, c12, c15, c15, #0x0
 *   @0x304e74 ldm r6, {r0, r1, r2, r3, r10, lr, pc}
 *   @0x304e78 stm r4, {r0, r1}
 *   @0x304e7c ldclvs p0, c0, [r11, #-12]!
 *   @0x304e80 teqlo r4, r9, asr #17
 *   @0x304e84 .word 0xc120f8d9
 *   @0x304e88 svceq #0xf1bc
 *   @0x304e8c .word 0xf8d9db05
 *   @0x304e90 .word 0xf10bb124
 *   @0x304e94 blhs 0x3d1e98 <error_g0017+0x2ab3c>
 *   @0x304e98 movwhs sp, #0x3902
 *   @0x304e9c cmn r9, r11, lsr #32
 *   @0x304ea0 svceq #0x4f1bc
 *   @0x304ea4 .word 0xf8d9dcf9
 *   @0x304ea8 strhs r7, [r0], -r8, asr #2
 *   @0x304eac ldrsblo pc, [r4, -r9]!
 *   @0x304eb0 .word 0x812cf8d9
 *   @0x304eb4 bne 0xffc1f0ac <b2_toiTime+0xffffffffff4c5c08>
 *   @0x304eb8 strbmi r2, [r6, #-0x3fc]
 *   @0x304ebc .word 0xf8d9da25
 *   @0x304ec0 blx 0x3cd38a <error_g0017+0x2602e>
 *   @0x304ec4 .word 0xf8d22206
 *   @0x304ec8 stmdbhs r0, {r3, r4, r5, r6, r7, r12}
 *   @0x304ecc .word 0xf8d2dbe5
 *   @0x304ed0 .word 0xf1baa0f0
 *   @0x304ed4 andle r0, r1, r0, lsl #30
 *   @0x304ed8 sbcsle r2, lr, r0, lsl #18
 *   @0x304edc ldclle p9, c2, [r12], {4}
 *   @0x304ee0 ldrsbteq pc, [r4], #130
 *   @0x304ee4 ldmle r8, {r5, r7, r9, lr} ^
 *   @0x304ee8 svceq #0xf1ba
 *   @0x304eec ldrsblt sp, [r1, #-181]
 *   @0x304ef0 movwls r1, #0x2a20
 *   @0x304ef4 andgt pc, r12, sp, asr #17
 *   @0x304ef8 mcr p0, #0x5, pc, c6, c3, #0x0
 *   @0x304efc .word 0xf8dd9b02
 *   @0x304f00 strmi r12, [r2, #0xc]
 *   @0x304f04 strlo sp, [r1], -r9, asr #17
 *   @0x304f08 .word 0xf8d9e7d7
 *   @0x304f0c adcmi r0, r0, #28, #2
 *   @0x304f10 bne 0xb3b224 <b2_toiTime+0x3e1d80>
 *   @0x304f14 .word 0x010beb0c
 *   @0x304f18 mrc p0, #0x4, apsr_nzcv, c6, c3, #0x0
 *   @0x304f1c .word 0x3128f8d9
 *   @0x304f20 ldmle r10!, {r0, r1, r7, r9, lr}
 *   @0x304f24 .word 0x0088f8d9
 *   @0x304f28 .word 0xf8d92400
 *   @0x304f2c ldcge p0, c6, [r0, #-400]
 *   @0x304f30 strls r4, [r0], #-1603
 *   @0x304f34 .word 0x21089009
 *   @0x304f38 ldrtmi r9, [r0], -r1, lsl #10
 *   @0x304f3c .word 0xf7e34622
 *   @0x304f40 stmdavs r11!, {r1, r2, r5, r7, r11, r12, sp, lr, pc}
 *   @0x304f44 teqeq r12, r9, asr #17
 *   @0x304f48 .word 0xf0402b00
 *   @0x304f4c .word 0xf100811d
 *   @0x304f50 ldrmi r0, [r12], -r8, lsl #16
 *   @0x304f54 movwls r10, #0x6911
 *   @0x304f58 .word 0x91089307
 *   @0x304f5c .word 0x312cf8d9
 *   @0x304f60 addsmi r9, r9, #114688
 *   @0x304f64 tsthi r0, r0, lsl #5
 *   @0x304f68 ldrsbhs pc, [r0, -r9]!
 *   @0x304f6c stmdals r7, {r2, r3, r4, r5, r6, r7, r8, r9, sp}
 *   @0x304f70 blhs 0x343b84
 *   @0x304f74 .word 0x1004f8db
 *   @0x304f78 ldrsbtpl pc, [r0], #139
 *   @0x304f7c stchs p1, c9, [r0, #-40]
 *   @0x304f80 sbcshi pc, r3, r0
 *   @0x304f84 .word 0x1c6a9b06
 *   @0x304f88 addsmi r9, r10, #1342177280
 *   @0x304f8c .word 0xf105d91f
 *   @0x304f90 .word 0xf10d0a04
 *   @0x304f94 .word 0xf02a0c40
 *   @0x304f98 ldrmi r0, [r10, #0xa03]
 *   @0x304f9c movhs sp, #196608
 *   @0x304fa0 andlo pc, r0, r12, asr #17
 *   @0x304fa4 stm sp, {r0, r1, r3, r4, r5, r7, sp, lr, pc}
 *   @0x304fa8 uadd16mi r1, r3, r0
 *   @0x304fac .word 0x21044630
 *   @0x304fb0 .word 0xf8cd9a06
 *   @0x304fb4 .word 0xf7e3c00c
 *   @0x304fb8 .word 0xf8ddf86a
 *   @0x304fbc .word 0xf8dcc00c
 *   @0x304fc0 strmi r3, [r4], -r0
 *   @0x304fc4 .word 0xf0402b00
 *   @0x304fc8 .word 0xf8cd80aa
 *   @0x304fcc .word 0xf8dba018
 *   @0x304fd0 shsub8mi r1, r8, r4
 *   @0x304fd4 ldrsblo pc, [r4, -r9]!
 *   @0x304fd8 beq 0x1341414 <b2_toiTime+0xbe7f70>
 *   @0x304fdc .word 0xf7e14419
 *   @0x304fe0 andsls pc, r0, r2, ror #24
 *   @0x304fe4 .word 0xf0402800
 *   @0x304fe8 .word 0xf8db809a
 *   @0x304fec shsub8mi r1, r8, r8
 *   @0x304ff0 cmpmi r1, #20480
 *   @0x304ff4 .word 0xff15f7e2
 *   @0x304ff8 andeq pc, r0, r10, asr #17
 *   @0x304ffc .word 0xf0402800
 *   @0x305000 bvs 0x11e5240 <b2_toiTime+0xa8bd9c>
 *   @0x305004 tstls r1, #136314880
 *   @0x305008 .word 0xf89ba811
 *   @0x30500c .word 0xf7ff10f8
 *   @0x305010 .word 0xf844f891
 *   @0x305014 .word 0xf10a002a
 *   @0x305018 strmi r0, [r10, #0xa01]!
 *   @0x30501c shsub8mi sp, r8, r4
 *   @0x305020 .word 0xff4af7e2
 *   @0x305024 movwhs r1, #0x1f22
 *   @0x305028 svceq #0x4f852
 *   @0x30502c addmi r6, r8, #5308416
 *   @0x305030 movwlo sp, #0x180c
 *   @0x305034 ldmible r7!, {r0, r1, r3, r5, r7, r9, lr} ^
 *   @0x305038 adceq r6, r11, r9, ror r8
 *   @0x30503c ldrsbhs pc, [r4, -r9]!
 *   @0x305040 .word 0xf854930b
 *   @0x305044 bne 0xfe5910e0 <b2_toiTime+0xfffffffffde37c3c>
 *   @0x305048 stmdble r2, {r0, r1, r4, r7, r9, lr}
 *   @0x30504c andsls r2, r0, #805306368
 *   @0x305050 stmdavs r2!, {r0, r2, r5, r6, sp, lr, pc}
 *   @0x305054 bleq 0x1341490 <b2_toiTime+0xbe7fec>
 *   @0x305058 .word 0xf8cd4630
 *   @0x30505c bl 0xff3b1074 <b2_toiTime+0xfffffffffec57bd0>
 *   @0x305060 .word 0x21040a03
 *   @0x305064 blls 0x44d86c <g_RomDisk+0x5604c>
 *   @0x305068 .word 0xf7e39200
 *   @0x30506c .word 0xf848f810
 *   @0x305070 strmi r0, [r3], -r4, lsl #24
 *   @0x305074 .word 0x2000f8db
 *   @0x305078 cmple r0, r0, lsl #20
 *   @0x30507c uasxmi r4, r1, r0
 *   @0x305080 movwls r4, #0x265a
 *   @0x305084 .word 0xf84ff7e2
 *   @0x305088 andsvs r9, r8, r2, lsl #22
 *   @0x30508c .word 0x3000f8db
 *   @0x305090 .word 0xd1442b00
 *   @0x305094 ldrtmi r6, [r8], -r1, lsr #16
 *   @0x305098 ldrsblo pc, [r4, -r9]!
 *   @0x30509c .word 0xf7e14419
 *   @0x3050a0 .word 0xf8cbfc02
 *   @0x3050a4 .word 0x28000000
 *   @0x3050a8 .word 0xf858d139
 *   @0x3050ac ldrtmi r3, [r8], -r4, lsl #24
 *   @0x3050b0 ldmdavs r9, {r1, r4, r6, r9, r10, lr}
 *   @0x3050b4 stc2l p7, c15, [r11], #-900
 *   @0x3050b8 andeq pc, r0, r11, asr #17
 *   @0x3050bc qsub16mi r11, r2, r8
 *   @0x3050c0 .word 0x1c04f858
 *   @0x3050c4 .word 0xf8d21d03
 *   @0x3050c8 .word 0xf852c004
 *   @0x3050cc stmdapl r8, {r2, r8, r9, r11, sp, lr, pc}
 *   @0x3050d0 vmlseq.f64 d14, d28, d14
 *   @0x3050d4 sbcpl r4, r8, r0, ror r4
 *   @0x3050d8 addmi r9, r3, #720896
 *   @0x3050dc ldrmi sp, [r8], -r1
 *   @0x3050e0 stmdbls r10, {r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x3050e4 ble 0x38f4ec <_ZTS7CBucketILj16384ELj262144ELb1EE+0x3548>
 *   @0x3050e8 .word 0x5c08f848
 *   @0x3050ec ssatmi lr, #0x3, sp
 *   @0x3050f0 bleq 0x341234
 *   @0x3050f4 .word 0xf8589809
 *   @0x3050f8 .word 0xf8da2c04
 *   @0x3050fc stmdbvs r0, {r2, r12, sp}
 *   @0x305100 blne 0x443270 <g_RomDisk+0x4ba50>
 *   @0x305104 bne 0x196911c <b2_toiTime+0x120fc78>
 *   @0x305108 eoreq pc, r11, r2, asr r8
 *   @0x30510c rsceq pc, r10, #268435460
 *   @0x305110 .word 0xf10b9b04
 *   @0x305114 ldrmi r0, [r8, r1, lsl #22]
 *   @0x305118 mvnle r4, r11, lsr #11
 *   @0x30511c .word 0xf8d9e7e4
 *   @0x305120 orrlt r3, r11, #60, #2
 *   @0x305124 strtmi r2, [r8], r0, lsl #10
 *   @0x305128 stmdals r7, {r1, r5, sp, lr, pc}
 *   @0x30512c stmdaeq r8, {r3, r8, r12, sp, lr, pc}
 *   @0x305130 andls r3, r7, r1
 *   @0x305134 .word 0xf8d9e712
 *   @0x305138 rsceq r3, pc, r12, lsr r1
 *   @0x30513c ldmdavs r11, {r0, r1, r3, r4, r5, r10, lr} ^
 *   @0x305140 ldmdavs r9, {r0, r1, r3, r6, r8, r12, sp, pc}
 *   @0x305144 .word 0xf7e24630
 *   @0x305148 .word 0xf8d9f8f6
 *   @0x30514c ldrtmi r3, [r11], #-316
 *   @0x305150 .word 0xf8c3685b
 *   @0x305154 .word 0xf8d98000
 *   @0x305158 shasxmi r3, r0, r12
 *   @0x30515c ldrtmi r3, [r11], #-1281
 *   @0x305160 .word 0xf7e26859
 *   @0x305164 .word 0xf8d9f8e8
 *   @0x305168 ldrmi r3, [pc], #-316
 *   @0x30516c andhi pc, r4, r7, asr #17
 *   @0x305170 .word 0x312cf8d9
 *   @0x305174 blle 0xffa95bf0 <b2_toiTime+0xffffffffff33c74c>
 *   @0x305178 .word 0xf8d94630
 *   @0x30517c .word 0xf7e2113c
 *   @0x305180 movwhs pc, #0x8da
 *   @0x305184 teqlo r12, r9, asr #17
 *   @0x305188 qasxmi r4, r1, r0
 *   @0x30518c .word 0xf8d3f7e2
 *   @0x305190 andls r9, pc, #16, #20
 *   @0x305194 stclvs p12, c10, [r3], #72
 *   @0x305198 stcvs p1, c11, [r0], #108
 *   @0x30519c .word 0xf7e2a925
 *   @0x3051a0 stmibvs r3!, {r2, r4, r5, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3051a4 ldrmi r4, [r8, r0, lsr #12]
 *   @0x3051a8 bls 0x1eec9e0 <b2_toiTime+0x179353c>
 *   @0x3051ac ldmdavs r3!, {r0, r1, r2, r3, r11, r12, pc}
 *   @0x3051b0 mlasle r3, r10, r2, r4
 *   @0x3051b4 b 0x6c2880 <g_SWFlinevertbuff+0x6f7b8>
 *   @0x3051b8 .word 0x3004f8db
 *   @0x3051bc ldmdale r0, {r0, r2, r8, r9, r11, sp}
 *   @0x3051c0 .word 0xf003e8df
 *   @0x3051c4 streq r0, [r9], -r3, lsl #30
 *   @0x3051c8 .word 0xf1090c0f
 *   @0x3051cc ands r0, r5, r12, lsl #7
 *   @0x3051d0 .word 0x03a4f109
 *   @0x3051d4 .word 0xf509e012
 *   @0x3051d8 mul pc, r12, r3
 *   @0x3051dc biceq pc, r4, #1073741826
 *   @0x3051e0 .word 0xf8d8e00c
 *   @0x3051e4 bhs 0x30d36c <af_shaper_get_elem+0x2bda>
 *   @0x3051e8 .word 0xf8d9db16
 *   @0x3051ec addsmi r3, r10, #44, #2
 *   @0x3051f0 .word 0xf8d9da12
 *   @0x3051f4 rscshs r3, r12, r0, lsr r1
 *   @0x3051f8 movwlo pc, #0x2b00
 *   @0x3051fc bge 0x753628 <builtin_variables+0x51c>
 *   @0x305200 andsvs r2, r3, r1, lsl #18
 *   @0x305204 .word 0xf04f4620
 *   @0x305208 ldrbmi r0, [r9], -r0, lsl #6
 *   @0x30520c svclt #0x949300
 *   @0x305210 stcvs p12, c6, [r6], #-408
 *   @0x305214 strb r4, [sp, #-0x7b0]!
 *   @0x305218 strb r2, [r11, #-0xa0]!
 *   @0x30521c pop {r0, r4, r5, r6, r12, sp, pc}
 *   @0x305220 svclt #0x8ff0
 *   @0x305224 andeq r8, lr, r0, asr #31
 *   @0x305228 strdeq r10, r11, [r8], -r7
 *   @0x30522c andeq r10, r8, r3, lsl #8
 *   @0x305230 andeq r10, r8, r7, ror #7
 *   @0x305234 andeq r10, r8, r5, asr #5
 *   @0x305238 strheq r10, [r8], -r7
 *   @0x30523c andeq r10, r8, lr, lsl #5
 *   @0x305240 andeq r10, r8, r4, lsl r2
 *   @0x305244 andeq r4, lr, r4, ror #26
 *   @0x305248 .word 0x43f8e92d
 *   @0x30524c andvs r2, r11, r1, lsl #6
 *   @0x305250 .word 0xf8d14605
 *   @0x305254 strmi r3, [r12], -r8, lsl #1
 *   @0x305258 ldmdblt r3, {r1, r2, r4, r9, r10, lr} ^
 *   @0x30525c stmdbmi r3!, {r0, r1, r3, r9, r10, r11, sp, lr} ^
 *   @0x305260 ldrbtmi r6, [r9], #-2136
 *   @0x305264 cdp2 p7, #0x6, c15, c0, c0, #0x7
 *   @0x305268 .word 0xf0002800
 *   @0x30526c .word 0xf8c480b9
 *   @0x305270 .word 0xf8d40088
 *   @0x305274 ldmdblt r11!, {r6, r8, r12, sp}
 *   @0x305278 ldmdbmi sp, {r0, r1, r5, r9, r10, r11, sp, lr} ^
 *   @0x30527c ldrbtmi r6, [r9], #-2136
 *   @0x305280 cdp2 p7, #0x5, c15, c2, c0, #0x7
 *   @0x305284 smlalbteq pc, r0, r4, r8
 *   @0x305288 .word 0x21004628
 *   @0x30528c blx 0x60321a <g_SWFaavertbuff+0x30152>
 *   @0x305290 stmdahs r0, {r0, r2, r9, r10, lr}
 *   @0x305294 adchi pc, r7, r0, asr #32
 *   @0x305298 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x30529c blx 0x1fc32a2 <b2_toiTime+0x1869dfe>
 *   @0x3052a0 stmdahs r0, {r0, r2, r9, r10, lr}
 *   @0x3052a4 addshi pc, pc, r0, asr #32
 *   @0x3052a8 vmull.p8 q9, d0, d0
 *   @0x3052ac adcslt r8, r6, #156
 *   @0x3052b0 .word 0xf0402e00
 *   @0x3052b4 .word 0xf8d48097
 *   @0x3052b8 rsbvs r3, r0, #40, #2
 *   @0x3052bc .word 0x61236060
 *   @0x3052c0 vst2.32 {d22, d23}, [r3:128], r3
 *   @0x3052c4 .word 0xf0436301
 *   @0x3052c8 adcvs r0, r2, r1, lsl #4
 *   @0x3052cc umlalshs pc, r12, r4, r8
 *   @0x3052d0 .word 0xf043b112
 *   @0x3052d4 adcvs r0, r3, r5, lsl #6
 *   @0x3052d8 ldrsbths pc, [r0], r4
 *   @0x3052dc .word 0x61624b45
 *   @0x3052e0 .word 0x61a3447b
 *   @0x3052e4 .word 0xf8d4b1c2
 *   @0x3052e8 biclt r3, r11, r12, lsr #1
 *   @0x3052ec .word 0xb1b97819
 *   @0x3052f0 addmi r7, r1, #16, #16
 *   @0x3052f4 andlo sp, r1, #1073741824
 *   @0x3052f8 stmdbhs r0!, {r0, r1, sp, lr, pc}
 *   @0x3052fc pushhs {r0, r12, lr, pc}
 *   @0x305300 movwlo sp, #0x1101
 *   @0x305304 stmdahs r0!, {r1, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x305308 stmdahs sp!, {r0, r12, lr, pc}
 *   @0x30530c andlo sp, r1, #1073741824
 *   @0x305310 stmdblt r8!, {r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x305314 and r6, r3, r3, lsr #3
 *   @0x305318 .word 0x308cf8d4
 *   @0x30531c .word 0x6163b103
 *   @0x305320 rscvs r2, r3, r0, lsl #6
 *   @0x305324 ldrsbtlo pc, [r8], r4
 *   @0x305328 movwhs r11, #0x110b
 *   @0x30532c .word 0xf8d460e3
 *   @0x305330 ldrhlt r6, [lr, #-4]!
 *   @0x305334 shasxmi r4, r0, r0
 *   @0x305338 .word 0xf5b14479
 *   @0x30533c .word 0xb128e91c
 *   @0x305340 ldrtmi r4, [r0], -lr, lsr #18
 *   @0x305344 .word 0xf5b14479
 *   @0x305348 ldmdblt r8, {r1, r2, r4, r8, r11, sp, lr, pc}
 *   @0x30534c .word 0xf04368e3
 *   @0x305350 rscvs r0, r3, r2, lsl #6
 *   @0x305354 mvnvs r2, r0, lsl #6
 *   @0x305358 rfeib r4!
 *   @0x30535c .word 0xf8d430c6
 *   @0x305360 rfeib r4!
 *   @0x305364 .word 0x636360ca
 *   @0x305368 ldrbmi pc, [pc, -r7, lsl #10]!
 *   @0x30536c .word 0x30ccf8d4
 *   @0x305370 .word 0x63a637ff
 *   @0x305374 cmnmi pc, #12582912
 *   @0x305378 .word 0x33ff143f
 *   @0x30537c ldrne r6, [r11], #-1063
 *   @0x305380 rfeia r4!
 *   @0x305384 ldmdblt r11, {r2, r6, r12, sp}
 *   @0x305388 cmnvc r10, #1325400064
 *   @0x30538c sublo pc, r4, r4, lsr #17
 *   @0x305390 strhlo pc, [r4], #-132
 *   @0x305394 blx 0xacd3cc <b2_toiTime+0x373f28>
 *   @0x305398 blx 0xb035b8 <b2_toiTime+0x3aa114>
 *   @0x30539c .word 0xf8a4f987
 *   @0x3053a0 .word 0x210a8048
 *   @0x3053a4 subls pc, r6, r4, lsr #17
 *   @0x3053a8 .word 0xf888fa0f
 *   @0x3053ac .word 0xf0134358
 *   @0x3053b0 blx 0x700678 <g_SWFvertbuff+0x2d5b0>
 *   @0x3053b4 bl 0xff5439e0 <b2_toiTime+0xfffffffffedea53c>
 *   @0x3053b8 addlt r0, r0, #589824
 *   @0x3053bc strbmi r11, [r3, #-0x203]
 *   @0x3053c0 ldrhtlo pc, [lr], r4
 *   @0x3053c4 bl 0xff4b52a4 <b2_toiTime+0xfffffffffed5be00>
 *   @0x3053c8 .word 0xf8a40607
 *   @0x3053cc .word 0xf8a4004a
 *   @0x3053d0 .word 0xf8a4604a
 *   @0x3053d4 rfeia r4!
 *   @0x3053d8 .word 0xf8a430c0
 *   @0x3053dc and r3, r2, r2, asr r0
 *   @0x3053e0 and r2, r0, r11, lsl #10
 *   @0x3053e4 strtmi r2, [r8], -r6, lsl #10
 *   @0x3053e8 .word 0x83f8e8bd
 *   @0x3053ec andeq r9, r8, lr, ror r6
 *   @0x3053f0 andeq r9, r8, r8, lsl r9
 *   @0x3053f4 andeq r9, r8, r12, lsr #10
 *   @0x3053f8 strheq r9, [r8], -r2
 *   @0x3053fc andeq r9, r8, r4, asr r9
 *   @0x305400 .word 0x016cf8d0
 *   @0x305404 ldrlt r4, [r0, #-0x770]!
 *   @0x305408 streq pc, [r4, #0x100]
 *   @0x30540c stcgt p6, c4, [pc, #-48]
 *   @0x305410 ldm r5, {r0, r1, r2, r3, r10, lr, pc}
 *   @0x305414 stm r4, {r0, r1, r2, r3}
 *   @0x305418 andhs r0, r0, pc
 *   @0x30541c rfeia r0!
 *   @0x305420 andhs r3, r0, r4, lsr #1
 *   @0x305424 ldrbmi r8, [r0, -r11]!
 *   @0x305428 ldrbmi r2, [r0, -r1]!
 *   @0x30542c .word 0xf100b508
 *   @0x305430 sbchs r0, r4, #168, #6
 *   @0x305434 ldrmi r4, [r9], -r8, lsl #12
 *   @0x305438 stm r0, {r0, r4, r5, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x30543c stclt p0, c2, [r8, #-0]
 *   @0x305440 ldrblt r4, [r0, #-0x770]!
 *   @0x305444 stmdavs r5, {r1, r2, r3, r9, r10, lr}
 *   @0x305448 bvs 0xff316c60 <b2_toiTime+0xfffffffffebbd7bc>
 *   @0x30544c stc2l p7, c15, [r7], #896
 *   @0x305450 .word 0xf8d54631
 *   @0x305454 .word 0xf7e001f8
 *   @0x305458 .word 0x4606f950
 *   @0x30545c .word 0xf8d5b950
 *   @0x305460 strlo r3, [r12], #-504
 *   @0x305464 strlo r6, [r12, #-0xd9d]
 *   @0x305468 strgt r12, [pc], #-3343
 *   @0x30546c muleq r7, r5, r8
 *   @0x305470 andeq lr, r7, r4, lsl #17
 *   @0x305474 ldcllt p6, c4, [r0, #-192]!
 *   @0x305478 .word 0x460eb570
 *   @0x30547c strmi r6, [r4], -r5, lsl #16
 *   @0x305480 .word 0xf7e06ac0
 *   @0x305484 ldrtmi pc, [r1], -r12, asr #25
 *   @0x305488 ldrsbeq pc, [r8, #133]!
 *   @0x30548c .word 0xf94ef7e0
 *   @0x305490 ldmdblt r0, {r1, r2, r9, r10, lr} ^
 *   @0x305494 ldrsblo pc, [r8, #133]!
 *   @0x305498 ldcvs p4, c3, [sp, #48]
 *   @0x30549c stcgt p5, c3, [pc, #-48]
 *   @0x3054a0 ldm r5, {r0, r1, r2, r3, r10, lr, pc}
 *   @0x3054a4 stm r4, {r0, r1, r2}
 *   @0x3054a8 ldrtmi r0, [r0], -r7
 *   @0x3054ac push {r4, r5, r6, r8, r10, r11, r12, sp, pc}
 *   @0x3054b0 .word 0x460f47f0
 *   @0x3054b4 ldrmi r6, [r9], r1, asr #16
 *   @0x3054b8 strhs r4, [r0], -r4, lsl #12
 *   @0x3054bc ldmdavs r9!, {r0, r1, r3, r9, r10, r11, sp, lr}
 *   @0x3054c0 ldrsbhi pc, [r12], -r3
 *   @0x3054c4 .word 0x31acf8d1
 *   @0x3054c8 .word 0xf8532100
 *   @0x3054cc andhs r0, r10, #34
 *   @0x3054d0 stm lr, {r0, r4, r5, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x3054d4 .word 0x50a0f8d4
 *   @0x3054d8 strtmi r4, [r8], -r2, lsl #13
 *   @0x3054dc .word 0xf821f7e2
 *   @0x3054e0 andseq pc, r8, r5, lsl #2
 *   @0x3054e4 eorhs r2, r0, #0, #2
 *   @0x3054e8 stmda r2!, {r0, r4, r5, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x3054ec rsbeq pc, r12, r5, lsl #2
 *   @0x3054f0 andshs r2, r4, #0, #2
 *   @0x3054f4 ldmda r12, {r0, r4, r5, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x3054f8 subeq pc, r12, r5, lsl #2
 *   @0x3054fc andshs r2, r8, #0, #2
 *   @0x305500 ldmda r6, {r0, r4, r5, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x305504 strtvs r6, [lr], lr, ror #12
 *   @0x305508 .word 0xf8c54652
 *   @0x30550c .word 0xf0496080
 *   @0x305510 .word 0xf8c50308
 *   @0x305514 .word 0xf8c56084
 *   @0x305518 .word 0xf8c56088
 *   @0x30551c .word 0xf8c5608c
 *   @0x305520 strtvs r6, [lr], #152
 *   @0x305524 .word 0x63ee63ae
 *   @0x305528 .word 0xf8d86af9
 *   @0x30552c .word 0xf8d45048
 *   @0x305530 strmi r0, [r8, r0, lsr #1]!
 *   @0x305534 stmdahs r0, {r2, r7, r9, r10, lr}
 *   @0x305538 .word 0xf8d4d137
 *   @0x30553c .word 0xf10450a0
 *   @0x305540 .word 0xf1050618
 *   @0x305544 svcgt #0xf0718
 *   @0x305548 ldm r7, {r0, r1, r2, r3, r9, r10, lr, pc}
 *   @0x30554c .word 0xf105000f
 *   @0x305550 stm r6, {r2, r3, r5, r6, r8, r9, r10}
 *   @0x305554 .word 0xf104000f
 *   @0x305558 blvs 0xfedc6f10 <b2_toiTime+0xfffffffffe66da6c>
 *   @0x30555c blvs 0xffdde3f0 <b2_toiTime+0xffffffffff684f4c>
 *   @0x305560 stcvs p3, c6, [r11], #908
 *   @0x305564 svcgt #0xf64a3
 *   @0x305568 ldmdavs r11!, {r0, r1, r2, r3, r9, r10, lr, pc}
 *   @0x30556c strbeq pc, [r12, -r5, lsl #2]
 *   @0x305570 .word 0xf1046033
 *   @0x305574 svcgt #0xf064c
 *   @0x305578 ldm r7, {r0, r1, r2, r3, r9, r10, lr, pc}
 *   @0x30557c stm r6, {r0, r1}
 *   @0x305580 cdpvs p0, #0x6, c0, c11, c3, #0x0
 *   @0x305584 cdpvs p6, #0xa, c6, c11, c3, #0x3
 *   @0x305588 .word 0xf8d566a3
 *   @0x30558c .word 0xf8c43080
 *   @0x305590 .word 0xf8d53080
 *   @0x305594 .word 0xf8c43084
 *   @0x305598 .word 0xf8d53084
 *   @0x30559c .word 0xf8c43088
 *   @0x3055a0 .word 0xf8d53088
 *   @0x3055a4 .word 0xf8c4308c
 *   @0x3055a8 strbtmi r3, [r0], -r12, lsl #1
 *   @0x3055ac .word 0x87f0e8bd
 *   @0x3055b0 .word 0x00a0f8d0
 *   @0x3055b4 blt 0xfef83544 <b2_toiTime+0xfffffffffe82a0a0>
 *   @0x3055b8 .word 0x4604b513
 *   @0x3055bc ldclvs p8, c6, [r8, #-268]
 *   @0x3055c0 .word 0xf8d3b918
 *   @0x3055c4 ldclvs p1, c3, [r11, #-992]
 *   @0x3055c8 .word 0xf8d3e005
 *   @0x3055cc stmdbge r1, {r3, r4, r5, r6, r7, r8}
 *   @0x3055d0 blx 0x16c3560 <b2_toiTime+0xf6a0bc>
 *   @0x3055d4 .word 0xf8c49b01
 *   @0x3055d8 andlt r3, r2, r0, lsr #1
 *   @0x3055dc ldrlt r11, [r0, #-0xd10]
 *   @0x3055e0 stmdavs r3, {r2, r9, r10, lr}
 *   @0x3055e4 .word 0xf8d36ae1
 *   @0x3055e8 .word 0x306c01f8
 *   @0x3055ec .word 0xf98ff7e3
 *   @0x3055f0 bvs 0xffb31a78 <b2_toiTime+0xffffffffff3d85d4>
 *   @0x3055f4 blx 0x5c3588 <g_SWFlineaavertbuff+0x704c0>
 *   @0x3055f8 rscvs r2, r3, #0, #6
 *   @0x3055fc ldrlt r11, [r7, #-0xd10]!
 *   @0x305600 stmdavs r3, {r2, r9, r10, lr}
 *   @0x305604 .word 0xf8d3a901
 *   @0x305608 .word 0xf7e301f8
 *   @0x30560c .word 0x4605f995
 *   @0x305610 rscvs r9, r0, #65536
 *   @0x305614 .word 0xfc03f7e0
 *   @0x305618 andlt r4, r3, r8, lsr #12
 *   @0x30561c ldrblt r11, [r0, #-0xd30]!
 *   @0x305620 stmdahs r0, {r2, r9, r10, lr}
 *   @0x305624 mcrvs p0, #0x2, sp, c6, c3, #0x3
 *   @0x305628 ldrsbeq pc, [r8, #128]!
 *   @0x30562c .word 0xf7e3b108
 *   @0x305630 .word 0x4630fad5
 *   @0x305634 .word 0x1084f8d4
 *   @0x305638 .word 0xf7e12500
 *   @0x30563c shsub16mi pc, r0, r12
 *   @0x305640 .word 0x1088f8d4
 *   @0x305644 addpl pc, r4, r4, asr #17
 *   @0x305648 cdp2 p7, #0x7, c15, c5, c1, #0x7
 *   @0x30564c .word 0xf8d44630
 *   @0x305650 .word 0xf8c4108c
 *   @0x305654 .word 0xf7e15088
 *   @0x305658 ldrtmi pc, [r0], -lr, ror #28
 *   @0x30565c ldrsbne pc, [r0], r4
 *   @0x305660 addpl pc, r12, r4, asr #17
 *   @0x305664 cdp2 p7, #0x6, c15, c7, c1, #0x7
 *   @0x305668 .word 0xf8d44630
 *   @0x30566c .word 0xf8c41094
 *   @0x305670 .word 0xf7e15090
 *   @0x305674 ldrtmi pc, [r0], -r0, ror #28
 *   @0x305678 ldrsbne pc, [r0, r4]!
 *   @0x30567c addspl pc, r4, r4, asr #17
 *   @0x305680 cdp2 p7, #0x5, c15, c9, c1, #0x7
 *   @0x305684 .word 0xf8d44630
 *   @0x305688 .word 0xf8c411ac
 *   @0x30568c .word 0xf7e151b0
 *   @0x305690 shsaxmi pc, r0, r2
 *   @0x305694 .word 0x11a8f8d4
 *   @0x305698 .word 0x51acf8c4
 *   @0x30569c cdp2 p7, #0x4, c15, c11, c1, #0x7
 *   @0x3056a0 .word 0xf8d44630
 *   @0x3056a4 .word 0xf8c4118c
 *   @0x3056a8 .word 0xf7e151a8
 *   @0x3056ac ldrtmi pc, [r0], -r4, asr #28
 *   @0x3056b0 ldrsbne pc, [r0, r4]
 *   @0x3056b4 orrpl pc, r12, r4, asr #17
 *   @0x3056b8 cdp2 p7, #0x3, c15, c13, c1, #0x7
 *   @0x3056bc .word 0xf8d44630
 *   @0x3056c0 .word 0xf8c41180
 *   @0x3056c4 .word 0xf7e15190
 *   @0x3056c8 shasxmi pc, r0, r6
 *   @0x3056cc .word 0x1184f8d4
 *   @0x3056d0 orrpl pc, r0, r4, asr #17
 *   @0x3056d4 cdp2 p7, #0x2, c15, c15, c1, #0x7
 *   @0x3056d8 .word 0xf8d44630
 *   @0x3056dc .word 0xf8c4116c
 *   @0x3056e0 .word 0xf7e15184
 *   @0x3056e4 ldrtmi pc, [r0], -r8, lsr #28
 *   @0x3056e8 ldrsbne pc, [r0, #132]!
 *   @0x3056ec smulbtpl r12, r4, r8
 *   @0x3056f0 cdp2 p7, #0x2, c15, c1, c1, #0x7
 *   @0x3056f4 mvnspl pc, r4, asr #17
 *   @0x3056f8 .word 0xf8d44630
 *   @0x3056fc .word 0xf7e11230
 *   @0x305700 .word 0xf8c4fe1a
 *   @0x305704 .word 0xf8c45230
 *   @0x305708 .word 0x6165522c
 *   @0x30570c ldcllt p1, c6, [r0, #-660]!
 *   @0x305710 ldrlt r4, [r0, #-0x906]
 *   @0x305714 .word 0x46044479
 *   @0x305718 .word 0xf7e06840
 *   @0x30571c tstlt r8, r9, ror #23
 *   @0x305720 andhs r6, r0, r3, lsl #16
 *   @0x305724 ldclt p1, c6, [r0, #-908]
 *   @0x305728 ldclt p0, c2, [r0, #-44]
 *   @0x30572c andeq r9, r8, r12
 *   @0x305730 mvnsmi lr, sp, lsr #18
 *   @0x305734 .word 0xf8d04605
 *   @0x305738 strmi r7, [lr], -r4, lsr #3
 *   @0x30573c adcsmi r2, r12, #0, #8
 *   @0x305740 .word 0xf8d5da19
 *   @0x305744 b 0x16d1dec <b2_toiTime+0xf78948>
 *   @0x305748 ldmdavc r2!, {r2, r7, r11}
 *   @0x30574c eorne pc, r4, r3, asr r8
 *   @0x305750 addsmi r7, r10, #720896
 *   @0x305754 ldrtmi sp, [r0], -sp, lsl #2
 *   @0x305758 svc #0xcf5b0
 *   @0x30575c stmdblt r0, {r0, r9, r10, lr} ^
 *   @0x305760 .word 0x31acf8d5
 *   @0x305764 .word 0xf853220a
 *   @0x305768 ldm sp!, {r3}
 *   @0x30576c .word 0xf01641f0
 *   @0x305770 strlo r11, [r1], #-2541
 *   @0x305774 andhs lr, r0, r3, ror #15
 *   @0x305778 ldrhhi lr, [r0, #141]!
 *   @0x30577c svcmi #0xf0e92d
 *   @0x305780 stmvs r2!, {r2, r3, r9, r10, lr}
 *   @0x305784 stmdbvs r9, {r0, r2, r3, r7, r12, sp, pc}
 *   @0x305788 stmibvs r3!, {r0, r2, r9, r10, lr} ^
 *   @0x30578c andls r4, r6, #32, #12
 *   @0x305790 ldrmi r9, [r8, r5, lsl #2]
 *   @0x305794 stmdbls r6, {r0, r1, r5, r11, sp, lr}
 *   @0x305798 movwle r4, #0x528b
 *   @0x30579c beq 0x3418e0
 *   @0x3057a0 ldrbmi r2, [r0], r3, lsl #6
 *   @0x3057a4 .word 0xe120930a
 *   @0x3057a8 eorvs r1, r2, r10, asr r12
 *   @0x3057ac blhs 0x19e3820 <b2_toiTime+0x128a37c>
 *   @0x3057b0 .word 0xf04fd1f4
 *   @0x3057b4 stmibvs r3!, {r8, r11} ^
 *   @0x3057b8 strbmi r4, [r10], r0, lsr #12
 *   @0x3057bc strbmi r4, [pc], -r8, asr #13
 *   @0x3057c0 ldrmi r4, [r8, lr, asr #12]
 *   @0x3057c4 blge 0x5efff4 <g_SWFaavertbuff+0x1cf2c>
 *   @0x3057c8 eorls pc, r0, sp, asr #17
 *   @0x3057cc andsls pc, r0, sp, asr #17
 *   @0x3057d0 movwls r9, #0x9207
 *   @0x3057d4 .word 0xc000f8d4
 *   @0x3057d8 ldrmi r9, [r4, #0xa06]
 *   @0x3057dc smlabbhi r3, r0, r0, pc
 *   @0x3057e0 mullo r0, r12, r8
 *   @0x3057e4 qaddle r2, sp, r3
 *   @0x3057e8 movweq pc, #0x110c
 *   @0x3057ec rscs r6, lr, r3, lsr #32
 *   @0x3057f0 teqle r8, r12, lsr r11
 *   @0x3057f4 strtmi r6, [r0], -r3, lsr #20
 *   @0x3057f8 andgt pc, r12, sp, asr #17
 *   @0x3057fc stmvs r3!, {r3, r4, r7, r8, r9, r10, lr} ^
 *   @0x305800 .word 0xc00cf8dd
 *   @0x305804 .word 0xf0402b00
 *   @0x305808 stmdavs r3!, {r1, r4, r5, r6, r7, pc}
 *   @0x30580c bleq 0x400744 <g_RomDisk+0x8f24>
 *   @0x305810 bllo 0x301c44 <TT_New_Context+0x1a3c>
 *   @0x305814 blvc 0xffa00448 <b2_toiTime+0xffffffffff2a6fa4>
 *   @0x305818 bleq 0x1e0019c <b2_toiTime+0x16a6cf8>
 *   @0x30581c rschi pc, r3, r0
 *   @0x305820 andhi pc, r0, sp, asr #17
 *   @0x305824 ldrbmi r10, [r11], -r10, lsl #18
 *   @0x305828 stmdals r5, {r0, r8, r12, pc}
 *   @0x30582c bls 0x50dc38 <SrcVerts+0x6ac7c>
 *   @0x305830 andgt pc, r12, sp, asr #17
 *   @0x305834 stc2 p7, c15, [r11], #-904
 *   @0x305838 .word 0xf8dd9b0a
 *   @0x30583c strmi r12, [r0], r12
 *   @0x305840 .word 0xf0402b00
 *   @0x305844 bvs 0xffce5b94 <b2_toiTime+0xffffffffff58c6f0>
 *   @0x305848 beq 0x38198c <_ZTS13C_UTF16String+0x18a38>
 *   @0x30584c andgt pc, r0, r4, asr #17
 *   @0x305850 .word 0xf8cd4620
 *   @0x305854 strbmi r10, [r1], -r0
 *   @0x305858 blge 0x5d71c8 <g_SWFaavertbuff+0x4100>
 *   @0x30585c svcls #0xb47b8
 *   @0x305860 eorlt pc, r0, sp, asr #17
 *   @0x305864 bllo 0xf3d8f8 <b2_toiTime+0x7e4454>
 *   @0x305868 stmdale r0!, {r0, r3, r8, r9, r11, sp}
 *   @0x30586c svceq #0xf1ba
 *   @0x305870 movwhs sp, #0x3004
 *   @0x305874 beq 0x3819b8 <_ZTS13C_UTF16String+0x18a64>
 *   @0x305878 adcs r9, r6, r10, lsl #6
 *   @0x30587c strtmi r6, [r0], -r3, ror #20
 *   @0x305880 stmdahs r0, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x305884 adchi pc, pc, r0, asr #5
 *   @0x305888 strmi r6, [r7], -r3, lsr #20
 *   @0x30588c ldrmi r4, [r8, r0, lsr #12]
 *   @0x305890 blhs 0x31fc24
 *   @0x305894 adcshi pc, r2, r0, asr #32
 *   @0x305898 stmdbls r6, {r0, r1, r5, r11, sp, lr}
 *   @0x30589c stmdaeq r1, {r0, r1, r8, r12, sp, lr, pc}
 *   @0x3058a0 adcsmi r1, r10, #827392
 *   @0x3058a4 addshi pc, pc, r0, asr #4
 *   @0x3058a8 ldrmi r1, [r3], #-3194
 *   @0x3058ac .word 0xf1b86023
 *   @0x3058b0 .word 0xf0000f00
 *   @0x3058b4 .word 0x07fb8098
 *   @0x3058b8 cdpne p5, #0x7, c13, c11, c4, #0x0
 *   @0x3058bc andhs pc, r3, r8, lsl r8
 *   @0x3058c0 sadd16mi r11, pc, r10
 *   @0x3058c4 .word 0xf0002f00
 *   @0x3058c8 stmdavs r3!, {r1, r2, r3, r7, pc}
 *   @0x3058cc bleq 0x341a10
 *   @0x3058d0 bl 0xff3ec0f0 <b2_toiTime+0xfffffffffec92c4c>
 *   @0x3058d4 .word 0xf1b90c02
 *   @0x3058d8 eorle r0, r9, r1, lsl #30
 *   @0x3058dc .word 0xf1b9d303
 *   @0x3058e0 rsble r0, r11, r2, lsl #30
 *   @0x3058e4 mcrhs p0, #0x0, lr, c11, c6, #0x3
 *   @0x3058e8 ldrsbhs pc, [r0, #133]!
 *   @0x3058ec .word 0xf818dc04
 *   @0x3058f0 ldrpl r3, [r3, #0xb]
 *   @0x3058f4 rsb r3, sp, r1, lsl #12
 *   @0x3058f8 ldmdbvc r3, {r0, r4, r8, r11, r12, sp, lr} ^
 *   @0x3058fc movwne lr, #0x1b03
 *   @0x305900 tsteq r11, r4, lsl #6
 *   @0x305904 .word 0xf8c5330c
 *   @0x305908 ldrmi r3, [r12, #0x1f4]
 *   @0x30590c andls sp, r0, #109568
 *   @0x305910 stmdals r5, {r1, r3, r8, r11, sp, pc}
 *   @0x305914 .word 0x9101220c
 *   @0x305918 .word 0xf8cd2101
 *   @0x30591c .word 0xf7e2c00c
 *   @0x305920 blls 0x5c4800 <g_SWFlineaavertbuff+0x71738>
 *   @0x305924 .word 0xc00cf8dd
 *   @0x305928 mvnseq pc, r5, asr #17
 *   @0x30592c cmple r12, r0, lsl #22
 *   @0x305930 ldrsblo pc, [r4, #133]!
 *   @0x305934 blle 0x3563b4
 *   @0x305938 eor r2, r6, r0, lsl #6
 *   @0x30593c andhs pc, r11, r8, lsl r8
 *   @0x305940 stmdbeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x305944 ldrsblo pc, [r0, #133]!
 *   @0x305948 .word 0x3601559a
 *   @0x30594c .word 0xf8d5e042
 *   @0x305950 ldrsheq r0, [r10, -r0]
 *   @0x305954 stmne r1, {r3, r4, r9, r12, sp}
 *   @0x305958 stmdavc r10, {r7, r10, r11, r12, lr} ^
 *   @0x30595c b 0x13869ac <b2_toiTime+0xc2d508>
 *   @0x305960 stmvc r8, {r9, sp, lr} ^
 *   @0x305964 movwmi r7, #0x2889
 *   @0x305968 andhs lr, r1, #270336
 *   @0x30596c ldmdale r10!, {r1, r5, r6, r8, r10, lr}
 *   @0x305970 ldrsbne pc, [r4, #133]!
 *   @0x305974 andeq lr, r12, r2, asr #23
 *   @0x305978 ldcle p2, c4, [r4], #-516
 *   @0x30597c movwlo r3, #0x1203
 *   @0x305980 andeq pc, r3, #34
 *   @0x305984 .word 0xf8c54411
 *   @0x305988 bls 0x40a160 <g_RomDisk+0x12940>
 *   @0x30598c blle 0xffa963e0 <b2_toiTime+0xffffffffff33cf3c>
 *   @0x305990 ldrsbne pc, [r0, #133]!
 *   @0x305994 .word 0xf8d50112
 *   @0x305998 andlo r3, r12, #244, #2
 *   @0x30599c .word 0x91009805
 *   @0x3059a0 mrsls r10, apsr
 *   @0x3059a4 strmi r2, [r11], #-257
 *   @0x3059a8 andgt pc, r12, sp, asr #17
 *   @0x3059ac blx 0x1f0393e <b2_toiTime+0x17aa49a>
 *   @0x3059b0 .word 0xf8dd9b0a
 *   @0x3059b4 .word 0xf8c5c00c
 *   @0x3059b8 ldmiblt r3!, {r4, r5, r6, r7, r8}
 *   @0x3059bc ldrsblo pc, [r4, #133]!
 *   @0x3059c0 ble 0x716440 <g_SWFvertbuff+0x43378>
 *   @0x3059c4 andhs pc, r11, r8, lsl r8
 *   @0x3059c8 stmdbeq r2, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x3059cc ldrsblo pc, [r0, #133]!
 *   @0x3059d0 .word 0x3601559a
 *   @0x3059d4 bleq 0x381e08 <_ZTS13C_UTF16String+0x18eb4>
 *   @0x3059d8 .word 0xf4ff45bb
 *   @0x3059dc stmibvs r3!, {r2, r3, r4, r5, r6, r8, r9, r10, r11, sp, pc} ^
 *   @0x3059e0 ldrmi r4, [r8, r0, lsr #12]
 *   @0x3059e4 movwhs lr, #0x36f6
 *   @0x3059e8 blls 0x5aa618 <g_SWFlineaavertbuff+0x57550>
 *   @0x3059ec .word 0xf1ba60e3
 *   @0x3059f0 andle r0, r3, r0, lsl #30
 *   @0x3059f4 strbmi r9, [r1], -r5, lsl #16
 *   @0x3059f8 ldc2 p7, c15, [sp], {225}
 *   @0x3059fc pop {r0, r2, r3, r12, sp, pc}
 *   @0x305a00 strdeq r8, r9, [r0], -r0
 *   @0x305a04 addlt r11, r6, r0, ror r5
 *   @0x305a08 strmi r6, [r5], -r12, asr #22
 *   @0x305a0c strmi r4, [r8], -lr, lsl #12
 *   @0x305a10 .word 0x2106466a
 *   @0x305a14 strmi r2, [r0, r0, lsl #6]!
 *   @0x305a18 .word 0xdc022805
 *   @0x305a1c rscsvs r2, r3, r3, lsl #6
 *   @0x305a20 .word 0x9c03e03d
 *   @0x305a24 svclt #0xb82c00
 *   @0x305a28 .word 0x2c004264
 *   @0x305a2c .word 0xf5b4d0f6
 *   @0x305a30 eorle r3, r0, r0, lsl #31
 *   @0x305a34 stmdals r0, {r0, r5, r9, r10, lr}
 *   @0x305a38 blx 0x12839bc <b2_toiTime+0xb2a518>
 *   @0x305a3c andls r4, r0, r1, lsr #12
 *   @0x305a40 .word 0xf7df9801
 *   @0x305a44 qasxmi pc, r1, r8
 *   @0x305a48 stmdals r2, {r0, r12, pc}
 *   @0x305a4c blx 0x10039d0 <b2_toiTime+0x8aa52c>
 *   @0x305a50 andls r4, r2, r1, lsr #12
 *   @0x305a54 .word 0xf7df9804
 *   @0x305a58 strtmi pc, [r1], -lr, lsr #20
 *   @0x305a5c stmdals r5, {r2, r12, pc}
 *   @0x305a60 blx 0xd839e4 <b2_toiTime+0x62a540>
 *   @0x305a64 bmi 0x6ec678 <g_SWFvertbuff+0x195b0>
 *   @0x305a68 .word 0x0323ea12
 *   @0x305a6c .word 0xf44fbf38
 *   @0x305a70 movwls r3, #0x3380
 *   @0x305a74 blls 0x329a90
 *   @0x305a78 .word 0x31b8f8c5
 *   @0x305a7c .word 0xf8c59b01
 *   @0x305a80 blls 0x392188 <ft_adobe_glyph_list+0x1864>
 *   @0x305a84 .word 0x31bcf8c5
 *   @0x305a88 .word 0xf8c59b03
 *   @0x305a8c rfeib sp!
 *   @0x305a90 .word 0xf8c53012
 *   @0x305a94 rfeib sp!
 *   @0x305a98 .word 0xf8c53016
 *   @0x305a9c andlt r3, r6, r12, asr #3
 *   @0x305aa0 svclt #0xbd70
 *   @0x305aa4 .word 0xffff0000
 *   @0x305aa8 ldrbtmi r4, [r8], #-2049
 *   @0x305aac mrrclt p7, #0xd, pc, r1, c15
 *   @0x305ab0 andeq r4, lr, r6, lsr #13
 *   @0x305ab4 .word 0xf8d0b510
 *   @0x305ab8 ldrmi r4, [r0], -r8, lsr #3
 *   @0x305abc .word 0xf854461a
 *   @0x305ac0 .word 0xf7e21021
 *   @0x305ac4 andhs pc, r0, r0, lsl pc
 *   @0x305ac8 andeq r11, r0, r0, lsl sp
 *   @0x305acc svcmi #0xf0e92d
 *   @0x305ad0 .word 0xf8d0460c
 *   @0x305ad4 addlt r7, r7, r12, ror #3
 *   @0x305ad8 strmi r6, [r8], -r11, asr #19
 *   @0x305adc stmdbvs sp, {r1, r2, r3, r7, r11, sp, lr}
 *   @0x305ae0 stmdavs r3!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x305ae4 movwle r4, #0x12b3
 *   @0x305ae8 orrs r2, r0, r3, lsl #2
 *   @0x305aec .word 0xf1a3781b
 *   @0x305af0 bhs 0x5463b8 <gp_ActiveMaskObjects+0x16f0>
 *   @0x305af4 bvs 0x1bfbb44 <b2_toiTime+0x14a26a0>
 *   @0x305af8 ldrmi r4, [r8, r0, lsr #12]
 *   @0x305afc .word 0xf8c468e3
 *   @0x305b00 blhs 0x305d48 <TT_New_Context+0x5b40>
 *   @0x305b04 orrhi pc, r4, r0, asr #32
 *   @0x305b08 blle 0xffe4fb10 <b2_toiTime+0xffffffffff6f666c>
 *   @0x305b0c bne 0xfffdfba0 <b2_toiTime+0xffffffffff8866fc>
 *   @0x305b10 addsmi r1, r8, #155
 *   @0x305b14 .word 0xf8c4dd2d
 *   @0x305b18 mla r10, r0, r0, r3
 *   @0x305b1c mvnle r2, r12, lsr r11
 *   @0x305b20 strtmi r6, [r0], -r3, lsr #20
 *   @0x305b24 .word 0xf8d44798
 *   @0x305b28 .word 0xf1b8800c
 *   @0x305b2c .word 0xf0400f00
 *   @0x305b30 stmibvs r3!, {r0, r1, r2, r3, r5, r6, r8, pc} ^
 *   @0x305b34 ldrmi r4, [r8, r0, lsr #12]
 *   @0x305b38 .word 0x9000f8d4
 *   @0x305b3c adcsmi r6, r3, #2293760
 *   @0x305b40 ldmdavc r11, {r0, r1, r2, r4, r9, r12, lr, pc}
 *   @0x305b44 .word 0xd1022b2f
 *   @0x305b48 stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x305b4c blhs 0x12bdb6c <b2_toiTime+0xb646c8>
 *   @0x305b50 .word 0xf8c4d104
 *   @0x305b54 .word 0xf8c48090
 *   @0x305b58 and r9, r10, r0
 *   @0x305b5c strtmi r6, [r0], -r3, lsr #20
 *   @0x305b60 stmvs r3!, {r3, r4, r7, r8, r9, r10, lr} ^
 *   @0x305b64 .word 0xf0402b00
 *   @0x305b68 stmibvs r3!, {r0, r1, r4, r6, r8, pc} ^
 *   @0x305b6c ldrmi r4, [r8, r0, lsr #12]
 *   @0x305b70 stmdavs r3!, {r2, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x305b74 adcsle r4, r7, #805306379
 *   @0x305b78 .word 0x3108f8d4
 *   @0x305b7c .word 0xd1b32b00
 *   @0x305b80 .word 0xf104683b
 *   @0x305b84 .word 0xf8d402c8
 *   @0x305b88 andls r1, r2, #144
 *   @0x305b8c ldmdavs r11, {r4, r9, r10, lr}
 *   @0x305b90 ldrmi r4, [r8, r10, lsr #12]
 *   @0x305b94 stmdahs r0, {r0, r9, r10, lr}
 *   @0x305b98 teqhi r9, r0, asr #32
 *   @0x305b9c orrseq pc, r4, #4, #2
 *   @0x305ba0 ldmdavs r11!, {r0, r1, r8, r9, r12, pc}
 *   @0x305ba4 .word 0xf8d4462a
 *   @0x305ba8 stmdals r3, {r4, r7, r12}
 *   @0x305bac .word 0x4798681b
 *   @0x305bb0 stmdahs r0, {r0, r9, r10, lr}
 *   @0x305bb4 .word 0x812bf040
 *   @0x305bb8 .word 0xf104683b
 *   @0x305bbc strdhs r0, r1, [r4, -r12]
 *   @0x305bc0 strbmi r4, [r8], -r10, lsr #12
 *   @0x305bc4 .word 0x4798681b
 *   @0x305bc8 stmdahs r0, {r0, r9, r10, lr}
 *   @0x305bcc tsthi pc, r0, asr #32
 *   @0x305bd0 pkhbtmi r4, r0, r1, lsl #31
 *   @0x305bd4 andls r4, r0, r5, lsl #12
 *   @0x305bd8 smlsdxls r5, pc, r4, r4
 *   @0x305bdc strtmi r6, [r0], -r3, ror #19
 *   @0x305be0 .word 0xf8d44798
 *   @0x305be4 ldrmi r11, [r3, #0x0]!
 *   @0x305be8 addshi pc, r5, r0, lsl #1
 *   @0x305bec mullo r0, r11, r8
 *   @0x305bf0 tstle r1, r5, ror #22
 *   @0x305bf4 movweq pc, #0x310b
 *   @0x305bf8 stmdble pc, {r1, r2, r3, r4, r7, r9, lr}
 *   @0x305bfc mullo r1, r11, r8
 *   @0x305c00 .word 0xd10b2b6e
 *   @0x305c04 mullo r2, r11, r8
 *   @0x305c08 .word 0xd1072b64
 *   @0x305c0c muleq r3, r11, r8
 *   @0x305c10 mcr2 p5, #0x2, pc, c6, c2, #0x5
 *   @0x305c14 rsbs r11, lr, r0, lsl r1
 *   @0x305c18 rsbsle r2, r12, lr, lsr r11
 *   @0x305c1c strtmi r6, [r0], -r3, lsr #20
 *   @0x305c20 stmdavs r1!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x305c24 .word 0xf4bf42b1
 *   @0x305c28 stmvs r3!, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11, sp, pc} ^
 *   @0x305c2c .word 0xf0402b00
 *   @0x305c30 .word 0xf89b80ef
 *   @0x305c34 blhs 0xed1c3c <b2_toiTime+0x778798>
 *   @0x305c38 blhs 0xd39c44 <b2_toiTime+0x5e07a0>
 *   @0x305c3c bllo 0xd3a37c <b2_toiTime+0x5e0ed8>
 *   @0x305c40 beq 0x342394
 *   @0x305c44 beq 0x4009b4 <g_RomDisk+0x9194>
 *   @0x305c48 svceq #0xf1ba
 *   @0x305c4c movwhs r11, #0x2f0c
 *   @0x305c50 ldrbmi r2, [r11], #-771
 *   @0x305c54 .word 0xf67f429e
 *   @0x305c58 .word 0xf10baf47
 *   @0x305c5c bl 0xff386468 <b2_toiTime+0xfffffffffec2cfc4>
 *   @0x305c60 .word 0xf1ba0c01
 *   @0x305c64 andle r0, r1, r0, lsl #30
 *   @0x305c68 ldcllo p1, c15, [pc], #48
 *   @0x305c6c .word 0xf10c4629
 *   @0x305c70 .word 0xf8cd0301
 *   @0x305c74 stmdals r3, {r2, lr, pc}
 *   @0x305c78 .word 0x70c0f8d4
 *   @0x305c7c .word 0xf8dd47b8
 *   @0x305c80 strmi r12, [r1], -r4
 *   @0x305c84 .word 0xf0402800
 *   @0x305c88 .word 0xf8d480c2
 *   @0x305c8c adceq r3, pc, r12, lsr #1
 *   @0x305c90 .word 0xf8539704
 *   @0x305c94 .word 0xf8033025
 *   @0x305c98 .word 0xf89b000c
 *   @0x305c9c blhs 0xe91ca8 <b2_toiTime+0x738804>
 *   @0x305ca0 .word 0xf8d4d10d
 *   @0x305ca4 stmdals r5, {r2, r3, r5, r7, r12, sp}
 *   @0x305ca8 eorne pc, r5, r3, asr r8
 *   @0x305cac stcl p5, c15, [r2], #-704
 *   @0x305cb0 stmdahs r0, {r8, r9, r10, r11, r12, pc}
 *   @0x305cb4 strtmi r11, [r8], r8, lsl #30
 *   @0x305cb8 strhs r11, [r1, -r8, lsl #30]
 *   @0x305cbc stmibvs r3!, {r8, r9, r10, r12, pc} ^
 *   @0x305cc0 ldrmi r4, [r8, r0, lsr #12]
 *   @0x305cc4 svceq #0xf1ba
 *   @0x305cc8 bvs 0xbf9cd8 <b2_toiTime+0x4a0834>
 *   @0x305ccc ldrmi r4, [r8, r0, lsr #12]
 *   @0x305cd0 strtmi r6, [r0], -r2, lsr #16
 *   @0x305cd4 andls r6, r1, #405504
 *   @0x305cd8 stmdavs r3!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x305cdc adcsmi r9, r3, #4096
 *   @0x305ce0 svcge #0x2f4bf
 *   @0x305ce4 bleq 0x400bf4 <g_RomDisk+0x93d4>
 *   @0x305ce8 stmdals r2, {r0, r3, r5, r9, r10, lr}
 *   @0x305cec movweq pc, #0x110b
 *   @0x305cf0 ldrsbtvc pc, [r4], #132
 *   @0x305cf4 .word 0x460147b8
 *   @0x305cf8 .word 0xf0402800
 *   @0x305cfc .word 0xf8d48088
 *   @0x305d00 strlo r3, [r1, #-0xe0]
 *   @0x305d04 ldmibpl r11, {r2, r8, r9, r10, r11, r12, pc} ^
 *   @0x305d08 andeq pc, r11, r3, lsl #16
 *   @0x305d0c ldrsblo pc, [r0], r4
 *   @0x305d10 .word 0xf6ff429d
 *   @0x305d14 svcls #0xaf63
 *   @0x305d18 addspl pc, r0, r4, asr #17
 *   @0x305d1c .word 0xf43f2f00
 *   @0x305d20 .word 0xf8d4aee3
 *   @0x305d24 ldmdami sp!, {r2, r3, r5, r7, r12, sp}
 *   @0x305d28 ldrbtmi r6, [r8], #-2078
 *   @0x305d2c .word 0xf5b04631
 *   @0x305d30 stmdahs r0, {r1, r5, r10, r11, sp, lr, pc}
 *   @0x305d34 .word 0xf8d4d06c
 *   @0x305d38 strhhs r3, [r0, -r0]
 *   @0x305d3c .word 0x5128f8d4
 *   @0x305d40 ldrtmi r4, [r2], -r8, asr #12
 *   @0x305d44 .word 0x47a8681b
 *   @0x305d48 stmdahs r0, {r0, r9, r10, lr}
 *   @0x305d4c .word 0xf8d4d15f
 *   @0x305d50 smlatths r1, r0, r0, r2
 *   @0x305d54 .word 0x30e4f8d4
 *   @0x305d58 .word 0xf8d44648
 *   @0x305d5c ldmdavs r2, {r3, r5, r8, r12, lr}
 *   @0x305d60 .word 0x47a8681b
 *   @0x305d64 stmdahs r0, {r0, r9, r10, lr}
 *   @0x305d68 .word 0xf8d4d151
 *   @0x305d6c smlatbhs r2, r12, r0, r2
 *   @0x305d70 ldrsbtlo pc, [r0], r4
 *   @0x305d74 .word 0xf8d44648
 *   @0x305d78 .word 0xf8525128
 *   @0x305d7c .word 0xf8532028
 *   @0x305d80 strmi r3, [r8, r8, lsr #32]!
 *   @0x305d84 stmdahs r0, {r0, r9, r10, lr}
 *   @0x305d88 .word 0xf8d4d141
 *   @0x305d8c smlatths r3, r0, r0, r2
 *   @0x305d90 .word 0x30e4f8d4
 *   @0x305d94 .word 0xf8d44648
 *   @0x305d98 .word 0xf8525128
 *   @0x305d9c .word 0xf8532028
 *   @0x305da0 strmi r3, [r8, r8, lsr #32]!
 *   @0x305da4 stmdahs r0, {r0, r9, r10, lr}
 *   @0x305da8 .word 0xf8d4d131
 *   @0x305dac .word 0x46412114
 *   @0x305db0 ldrsblo pc, [r8, -r4]
 *   @0x305db4 .word 0x50c0f8d4
 *   @0x305db8 ldmdavs r2, {r0, r1, r11, r12, pc}
 *   @0x305dbc .word 0x47a8681b
 *   @0x305dc0 bllt 0xb175cc <b2_toiTime+0x3be128>
 *   @0x305dc4 ldrsbhs pc, [r4, -r4]
 *   @0x305dc8 .word 0xf8d44641
 *   @0x305dcc .word 0xf8d43118
 *   @0x305dd0 stmdals r2, {r2, r4, r5, r6, r7, r12, lr}
 *   @0x305dd4 ldmdavs r11, {r1, r4, r6, r11, sp, lr} ^
 *   @0x305dd8 strmi r4, [r1], -r8, lsr #15
 *   @0x305ddc .word 0xf8d4b9b8
 *   @0x305de0 .word 0xf8d42114
 *   @0x305de4 .word 0xf8d43118
 *   @0x305de8 stmdals r3, {r6, r7, r12, lr}
 *   @0x305dec ldmvs r11, {r1, r4, r7, r11, sp, lr}
 *   @0x305df0 strmi r4, [r1], -r8, lsr #15
 *   @0x305df4 .word 0xf8d4b958
 *   @0x305df8 .word 0xf8d42114
 *   @0x305dfc .word 0xf8d43118
 *   @0x305e00 stmdals r2, {r2, r4, r5, r6, r7, r12, lr}
 *   @0x305e04 ldmvs r11, {r1, r4, r6, r7, r11, sp, lr} ^
 *   @0x305e08 strmi r4, [r1], -r8, lsr #15
 *   @0x305e0c rscvs r11, r1, r0, lsl #2
 *   @0x305e10 pop {r0, r1, r2, r12, sp, pc}
 *   @0x305e14 svclt #0x8ff0
 *   @0x305e18 andeq r9, r8, r9, lsr #32
 *   @0x305e1c ldrdeq r8, r9, [r8], -r7
 *   @0x305e20 svcmi #0xf0e92d
 *   @0x305e24 .word 0xf8d0460c
 *   @0x305e28 addlt r11, r9, r12, ror #3
 *   @0x305e2c stmibvs r11, {r0, r1, r2, r9, r10, lr} ^
 *   @0x305e30 .word 0xf8d14608
 *   @0x305e34 ldrmi r8, [r8, r8]
 *   @0x305e38 strbmi r6, [r6, #-0x826]
 *   @0x305e3c ldmdavc r3!, {r3, r4, r9, r12, lr, pc}
 *   @0x305e40 eorseq pc, r0, #-1073741784
 *   @0x305e44 stmdble r2, {r0, r3, r9, r11, sp}
 *   @0x305e48 .word 0xf0402b5b
 *   @0x305e4c blhs 0x19e61ec <b2_toiTime+0x128cd48>
 *   @0x305e50 .word 0xd1066925
 *   @0x305e54 .word 0xf44f1c73
 *   @0x305e58 eorvs r7, r3, r0, lsl #19
 *   @0x305e5c movwls r2, #0x5301
 *   @0x305e60 bvs 0x1bfde90 <b2_toiTime+0x14a49ec>
 *   @0x305e64 ldrmi r4, [r8, r0, lsr #12]
 *   @0x305e68 svcvc #0x80f5b0
 *   @0x305e6c stcle p6, c4, [r1, #-516]
 *   @0x305e70 rscs r2, r12, r3, lsl #6
 *   @0x305e74 movwls r2, #0x5300
 *   @0x305e78 strtmi r6, [r0], -r3, ror #19
 *   @0x305e7c stmdavs r3!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x305e80 .word 0xf0804543
 *   @0x305e84 .word 0xf8d780f5
 *   @0x305e88 .word 0xf1041180
 *   @0x305e8c movwls r0, #0x435c
 *   @0x305e90 qadd8mi r11, r8, r1
 *   @0x305e94 beq 0x341fd8
 *   @0x305e98 blx 0x1683e24 <b2_toiTime+0xf2a980>
 *   @0x305e9c orrge pc, r0, r7, asr #17
 *   @0x305ea0 .word 0xf8d74628
 *   @0x305ea4 .word 0xf7e11184
 *   @0x305ea8 .word 0xf8c7fa46
 *   @0x305eac .word 0xf8d4a184
 *   @0x305eb0 smlabblt r11, r12, r0, r3
 *   @0x305eb4 ldrmi r9, [r8, r4, lsl #16]
 *   @0x305eb8 cmnls r4, r7, asr #17
 *   @0x305ebc .word 0xf8c42200
 *   @0x305ec0 .word 0xf10d9058
 *   @0x305ec4 andls r0, r0, #28, #20
 *   @0x305ec8 .word 0xf8cd4628
 *   @0x305ecc .word 0x2102a004
 *   @0x305ed0 .word 0xf7e2464b
 *   @0x305ed4 bls 0x50424c <SrcVerts+0x61290>
 *   @0x305ed8 orreq pc, r0, r7, asr #17
 *   @0x305edc blls 0x4f230c <SrcVerts+0x4f350>
 *   @0x305ee0 strbmi lr, [r11], -r5, asr #1
 *   @0x305ee4 streq lr, [r4], #-2189
 *   @0x305ee8 .word 0x21044628
 *   @0x305eec .word 0xf8cff7e2
 *   @0x305ef0 .word 0xf8c79b07
 *   @0x305ef4 blhs 0x30650c <TT_New_Context+0x6304>
 *   @0x305ef8 .word 0xf8dbd1f1
 *   @0x305efc strbmi r3, [r9], -r0
 *   @0x305f00 strtmi r9, [r10], -r4, lsl #16
 *   @0x305f04 .word 0x4798681b
 *   @0x305f08 stmdahs r0, {r0, r1, r2, r12, pc}
 *   @0x305f0c .word 0xf8dfd1e7
 *   @0x305f10 strmi r11, [r2], r8, ror #2
 *   @0x305f14 strbmi r4, [r10, #0x4fb]
 *   @0x305f18 ldrbmi sp, [r1], -r9, lsl #20
 *   @0x305f1c .word 0x5088f8d4
 *   @0x305f20 ldrbmi r9, [r10], -r4, lsl #16
 *   @0x305f24 .word 0xf10a2308
 *   @0x305f28 strmi r0, [r8, r1, lsl #20]!
 *   @0x305f2c stmibvs r3!, {r0, r1, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x305f30 ldrmi r4, [r8, r0, lsr #12]
 *   @0x305f34 beq 0x342078
 *   @0x305f38 strbmi r6, [r5, #-0x825]
 *   @0x305f3c .word 0xf895d268
 *   @0x305f40 .word 0xf1bbb000
 *   @0x305f44 .word 0xd10d0f64
 *   @0x305f48 strbmi r1, [r6, #-0xcee]
 *   @0x305f4c stmdavc r11!, {r0, r1, r2, r3, r9, r12, lr, pc} ^
 *   @0x305f50 .word 0xd10c2b65
 *   @0x305f54 blhs 0x1ca4208 <b2_toiTime+0x154ad64>
 *   @0x305f58 stmvc r8!, {r0, r3, r8, r12, lr, pc} ^
 *   @0x305f5c stc2 p5, c15, [r0], #712
 *   @0x305f60 subs r11, r5, r8, lsr #2
 *   @0x305f64 svceq #0x5df1bb
 *   @0x305f68 stclne p1, c13, [lr], #-4
 *   @0x305f6c .word 0xf1abe050
 *   @0x305f70 vmovls.16 d5[0], r0
 *   @0x305f74 svceq #0x9f1bb
 *   @0x305f78 stmdblt r6!, {r0, r8, r11, r12, lr, pc} ^
 *   @0x305f7c ldmdblt r6, {r0, r2, r3, r4, r5, sp, lr, pc} ^
 *   @0x305f80 strtmi r6, [r0], -r3, ror #20
 *   @0x305f84 stmibvs r3!, {r3, r4, r7, r8, r9, r10, lr} ^
 *   @0x305f88 strtmi r4, [r0], -r3, lsl #13
 *   @0x305f8c stmdavs r3!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x305f90 swple r4, sp, [r1]
 *   @0x305f94 ldrbmi lr, [r3], pc, lsr #32
 *   @0x305f98 stcne p8, c6, [r11], #148
 *   @0x305f9c stmdble r8!, {r3, r4, r7, r8, r10, lr}
 *   @0x305fa0 blhs 0xee4054 <b2_toiTime+0x78abb0>
 *   @0x305fa4 strbmi sp, [r10, #0x125]
 *   @0x305fa8 bvs 0xbfc83c <b2_toiTime+0x4a3398>
 *   @0x305fac strtmi r3, [r0], -r1, lsl #10
 *   @0x305fb0 ldrmi r6, [r8, r5, lsr #32]
 *   @0x305fb4 strbmi r6, [r3, #-0x823]
 *   @0x305fb8 stmvs r2!, {r1, r3, r4, r6, r9, r12, lr, pc} ^
 *   @0x305fbc cmple r7, r0, lsl #20
 *   @0x305fc0 .word 0x0c03ebc5
 *   @0x305fc4 .word 0xf10c9804
 *   @0x305fc8 .word 0xf8cd0301
 *   @0x305fcc ldrbmi r12, [r9], -r12
 *   @0x305fd0 .word 0xf8d4462a
 *   @0x305fd4 ldrmi r6, [r0, r8, lsl #1]!
 *   @0x305fd8 .word 0xc00cf8dd
 *   @0x305fdc stmdahs r0, {r5, r6, r7, sp, lr}
 *   @0x305fe0 svcvs #0x63d146
 *   @0x305fe4 beq 0x382414 <_ZTS13C_UTF16String+0x194c0>
 *   @0x305fe8 eorlo pc, r11, r3, asr r8
 *   @0x305fec andeq pc, r12, r3, lsl #16
 *   @0x305ff0 cdpls p0, #0x0, c14, c5, c9, #0x0
 *   @0x305ff4 movwhs r11, #0x213e
 *   @0x305ff8 bvs 0xbfe0e4 <b2_toiTime+0x4a4c40>
 *   @0x305ffc ldrmi r4, [r8, r0, lsr #12]
 *   @0x306000 blhs 0x320394
 *   @0x306004 stmibvs r3!, {r2, r4, r5, r8, r12, lr, pc} ^
 *   @0x306008 ldrmi r4, [r8, r0, lsr #12]
 *   @0x30600c ldr r4, [r3, lr, lsr #12]
 *   @0x306010 .word 0xf8c72301
 *   @0x306014 eorvs r3, r6, r0, ror r1
 *   @0x306018 .word 0xf106e02a
 *   @0x30601c ldrmi r0, [r8, #0x311]
 *   @0x306020 ldmdbmi r6, {r3, r8, r11, r12, lr, pc}
 *   @0x306024 andshs r4, r0, #48, #12
 *   @0x306028 .word 0xf5b04479
 *   @0x30602c stmdblt r8, {r1, r3, r4, r6, r7, r9, r11, sp, lr, pc}
 *   @0x306030 ands r2, r8, r2, lsl #6
 *   @0x306034 movweq pc, #0xf106
 *   @0x306038 stmdble r8, {r3, r4, r7, r8, r10, lr}
 *   @0x30603c shadd16mi r4, r0, r0
 *   @0x306040 ldrbtmi r2, [r9], #-526
 *   @0x306044 b 0xff64370c <b2_toiTime+0xfffffffffeeea268>
 *   @0x306048 movwhs r11, #0x4908
 *   @0x30604c .word 0xf106e00b
 *   @0x306050 ldrmi r0, [r8, #0x312]
 *   @0x306054 stmdbmi r11, {r1, r3, r8, r11, r12, lr, pc}
 *   @0x306058 andshs r4, r1, #48, #12
 *   @0x30605c .word 0xf5b04479
 *   @0x306060 ldmdblt r8, {r6, r7, r9, r11, sp, lr, pc}
 *   @0x306064 .word 0xf8c72303
 *   @0x306068 and r3, r1, r0, ror r1
 *   @0x30606c rscvs r2, r3, r2, lsr #7
 *   @0x306070 pop {r0, r3, r12, sp, pc}
 *   @0x306074 svclt #0x8ff0
 *   @0x306078 andeq r8, r8, sp, ror #25
 *   @0x30607c strdeq r8, r9, [r8], -r2
 *   @0x306080 andeq r8, r8, r9, ror #23
 *   @0x306084 ldrdeq r8, r9, [r8], -lr
 *   @0x306088 svcmi #0xf0e92d
 *   @0x30608c .word 0x460cb0dd
 *   @0x306090 andls r6, r10, #8, #28
 *   @0x306094 andhs r2, r1, #0, #10
 *   @0x306098 mvnspl pc, r1, asr #17
 *   @0x30609c .word 0xf8df600a
 *   @0x3060a0 movwls r1, #0xb620
 *   @0x3060a4 .word 0xf7df4479
 *   @0x3060a8 cdpvs p15, #0x2, c15, c3, c6, #0x2
 *   @0x3060ac .word 0x1614f8df
 *   @0x3060b0 andls r4, r9, r9, ror r4
 *   @0x3060b4 mvneq pc, r4, asr #17
 *   @0x3060b8 .word 0xf7df6858
 *   @0x3060bc .word 0x4680ff35
 *   @0x3060c0 mvneq pc, r4, asr #17
 *   @0x3060c4 .word 0xf0002800
 *   @0x3060c8 .word 0xf8d482e7
 *   @0x3060cc cdpge p0, #0x1, c10, c0, c4, #0x3
 *   @0x3060d0 stcge p6, c4, [r12, #-164]
 *   @0x3060d4 addsvc pc, r8, #1325400064
 *   @0x3060d8 .word 0xf5b04630
 *   @0x3060dc ldrbmi lr, [r0], -r10, ror #20
 *   @0x3060e0 strtmi r2, [r10], -r12, lsl #2
 *   @0x3060e4 .word 0xf81ff7e1
 *   @0x3060e8 .word 0x9000f8d5
 *   @0x3060ec mvnseq pc, r4, asr #17
 *   @0x3060f0 svceq #0xf1b9
 *   @0x3060f4 .word 0x81bef040
 *   @0x3060f8 .word 0xf8c4230c
 *   @0x3060fc .word 0xf8d831f4
 *   @0x306100 svcge #0xd3004
 *   @0x306104 ldrtmi r6, [r0], -r5, lsr #29
 *   @0x306108 andls pc, r0, r7, asr #17
 *   @0x30610c .word 0xf8d34649
 *   @0x306110 strbmi r12, [r10], -r0
 *   @0x306114 ubfxmi r4, r3, #0xc, #0x1
 *   @0x306118 strbmi r4, [r9], -r8, lsr #12
 *   @0x30611c .word 0xf8cd9522
 *   @0x306120 .word 0xf8cd9090
 *   @0x306124 .word 0xf88d908c
 *   @0x306128 .word 0xf7e09094
 *   @0x30612c ldrhtvs pc, [r8], -r12
 *   @0x306130 mrsle r2, spsr
 *   @0x306134 tsths r1, r8, lsr #12
 *   @0x306138 cdp2 p7, #0x7, c15, c3, c1, #0x7
 *   @0x30613c stmdahs r0, {r3, r4, r5, sp, lr}
 *   @0x306140 .word 0xf8dfd13f
 *   @0x306144 andshs r1, r1, #132, #10
 *   @0x306148 ldrbtmi r6, [r9], #-2600
 *   @0x30614c ldcl p5, c15, [r8, #-704]!
 *   @0x306150 movwhs r11, #0x2108
 *   @0x306154 qasxmi r6, r8, r11
 *   @0x306158 cdp2 p7, #0xa, c15, c14, c1, #0x7
 *   @0x30615c stmdbhs r0, {r0, r3, r4, r5, r11, sp, lr}
 *   @0x306160 strtmi sp, [r8], -pc, lsr #2
 *   @0x306164 blx 0xfeb040ee <b2_toiTime+0xfffffffffe3aac4a>
 *   @0x306168 bllt 0x171e250 <b2_toiTime+0xfc4dac>
 *   @0x30616c .word 0xf8d5696b
 *   @0x306170 ldmdblt r11!, {r2, r12, pc} ^
 *   @0x306174 strtmi r6, [r8], -r10, lsr #16
 *   @0x306178 strbmi r6, [r9], -r11, lsr #17
 *   @0x30617c addsls pc, r0, sp, asr #17
 *   @0x306180 .word 0x93234413
 *   @0x306184 .word 0xf88d2301
 *   @0x306188 .word 0xf7e03094
 *   @0x30618c ldrsbtvs pc, [r8], -r1
 *   @0x306190 ldrh r11, [r0], -r8
 *   @0x306194 ldrbmi r4, [r0], -r9, asr #12
 *   @0x306198 .word 0xf7e0463a
 *   @0x30619c ldmdavs r11!, {r2, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3061a0 eorls r4, r3, r1, lsl #12
 *   @0x3061a4 strtmi r11, [r8], -r11, ror #18
 *   @0x3061a8 .word 0xf7e0464a
 *   @0x3061ac ldrshtvs pc, [r8], -r0
 *   @0x3061b0 .word 0xf8c6b938
 *   @0x3061b4 blls 0xbea2fc <b2_toiTime+0x490e58>
 *   @0x3061b8 eorsvs r6, r3, r3, ror r0
 *   @0x3061bc ldrmi r9, [r3], #-2596
 *   @0x3061c0 stcge p0, c6, [sp, #-716]
 *   @0x3061c4 teqlt r11, r11, lsr #16
 *   @0x3061c8 umullsvc pc, r4, sp, r8
 *   @0x3061cc ldrbmi r11, [r0], -r7, lsr #18
 *   @0x3061d0 .word 0xf7e19923
 *   @0x3061d4 .word 0x9723f8b0
 *   @0x3061d8 movwls r6, #0xc82b
 *   @0x3061dc .word 0xf0402b00
 *   @0x3061e0 bls 0xbe670c <b2_toiTime+0x48d268>
 *   @0x3061e4 .word 0xf8df4630
 *   @0x3061e8 eorsvs r9, r2, r4, ror #9
 *   @0x3061ec stcls p4, c4, [r4, #-996]!
 *   @0x3061f0 ldrvc pc, [lr, -r9, lsl #10]!
 *   @0x3061f4 ldrmi r6, [r5], #-243
 *   @0x3061f8 ldrshtvs r6, [r5], r3
 *   @0x3061fc .word 0x97074798
 *   @0x306200 strbvc pc, [r12], #2271
 *   @0x306204 smlsdxls r8, pc, r4, r4
 *   @0x306208 .word 0xf8d7af10
 *   @0x30620c strmi r11, [r11, #0x0]!
 *   @0x306210 .word 0xf89bd22d
 *   @0x306214 bhs 0x148e21c <b2_toiTime+0xd34d78>
 *   @0x306218 .word 0xf10bd118
 *   @0x30621c addsmi r0, r5, #-1879048191
 *   @0x306220 addshi pc, sp, r0, asr #4
 *   @0x306224 stmdbls r8, {r3, r4, r6, r9, r10, lr}
 *   @0x306228 .word 0xf5b0220d
 *   @0x30622c stmdahs r0, {r1, r3, r4, r6, r7, r8, r11, sp, lr, pc}
 *   @0x306230 addshi pc, r5, r0, asr #32
 *   @0x306234 shasxmi r6, r8, r10
 *   @0x306238 shadd8mi r4, r8, r0
 *   @0x30623c .word 0x479069fa
 *   @0x306240 .word 0xf8df683e
 *   @0x306244 shadd8mi r11, r0, r0
 *   @0x306248 ldrsh r4, [pc], -r11
 *   @0x30624c .word 0xf0402a2f
 *   @0x306250 .word 0xf10b8086
 *   @0x306254 addsmi r0, r5, #536870912
 *   @0x306258 addhi pc, r1, r0, asr #4
 *   @0x30625c .word 0xf10b6a3a
 *   @0x306260 ldrtmi r0, [r8], -r1, lsl #12
 *   @0x306264 .word 0x4790603e
 *   @0x306268 bhs 0x320658
 *   @0x30626c ldmvs r8!, {r1, r3, r5, r12, lr, pc} ^
 *   @0x306270 stmdavc r2, {r0, r1, r2, r3, r4, r5, r6, sp, lr, pc}
 *   @0x306274 andle r2, r12, r11, ror #20
 *   @0x306278 shasxmi r6, r8, r10
 *   @0x30627c ldmvs r10!, {r4, r7, r8, r9, r10, lr} ^
 *   @0x306280 mvnsle r2, r0, lsl #20
 *   @0x306284 ldmibvs r10!, {r3, r4, r5, r9, r10, lr} ^
 *   @0x306288 ldmdavs r8!, {r4, r7, r8, r9, r10, lr}
 *   @0x30628c mvnsle r4, #168, #4
 *   @0x306290 stclne p0, c14, [r2, #-88]
 *   @0x306294 stmible pc!, {r0, r2, r4, r7, r9, lr} ^
 *   @0x306298 andhs r4, r5, #93323264
 *   @0x30629c stmib r0!, {r4, r5, r7, r8, r10, r12, sp, lr, pc}
 *   @0x3062a0 mvnle r2, r0, lsl #16
 *   @0x3062a4 bleq 0x10426e0 <b2_toiTime+0x8e923c>
 *   @0x3062a8 shasxmi r6, r8, r10
 *   @0x3062ac blvs 0xff1980f4 <b2_toiTime+0xfffffffffea3ec50>
 *   @0x3062b0 uasxmi r4, r9, r8
 *   @0x3062b4 .word 0xf8db4790
 *   @0x3062b8 bhs 0x3ce2e0 <error_g0017+0x26f84>
 *   @0x3062bc ldmdavs lr!, {r8, r12, lr, pc}
 *   @0x3062c0 subs r6, r2, lr, lsr r0
 *   @0x3062c4 bl 0xff4a03b8 <b2_toiTime+0xfffffffffed46f14>
 *   @0x3062c8 .word 0xf10a0a03
 *   @0x3062cc bhs 0x812ed0 <b2_toiTime+0xb9a2c>
 *   @0x3062d0 adcmi sp, r11, #4915200
 *   @0x3062d4 .word 0xf109d249
 *   @0x3062d8 ldmdavs r9!, {r3, r5, r8, r9, r10}
 *   @0x3062dc eorsle r2, r9, r0, lsl #18
 *   @0x3062e0 muleq r1, r11, r8
 *   @0x3062e4 addsmi r7, r0, #655360
 *   @0x3062e8 .word 0x4608d134
 *   @0x3062ec .word 0xf5b09105
 *   @0x3062f0 stmdbls r5, {r2, r5, r8, r11, sp, lr, pc}
 *   @0x3062f4 smlawble sp, r2, r5, r4
 *   @0x3062f8 uasxmi r4, r2, r0
 *   @0x3062fc stc p5, c15, [r0], #704
 *   @0x306300 ldmvs r8!, {r6, r8, r9, r11, r12, sp, pc}
 *   @0x306304 stmdahs r11, {r4, r9, r10, r11, sp, pc}
 *   @0x306308 strtmi sp, [r0], -r5, lsl #2
 *   @0x30630c shsub8mi r6, r1, r11
 *   @0x306310 ldmvs r0!, {r3, r4, r7, r8, r9, r10, lr} ^
 *   @0x306314 ldmdavs r9!, {r0, r1, r3, r4, sp, lr, pc} ^
 *   @0x306318 stmdbhs r3, {r0, r2, r3, r9, r11, sp, pc}
 *   @0x30631c stmdbhs r5, {r0, r3, r12, lr, pc}
 *   @0x306320 stmdbhs r2, {r2, r12, lr, pc}
 *   @0x306324 .word 0xf104d105
 *   @0x306328 and r0, r4, r4, lsr #3
 *   @0x30632c mvnvc pc, r4, lsl #10
 *   @0x306330 .word 0xf104e001
 *   @0x306334 stmdalo r9, {r2, r7, r8}
 *   @0x306338 stmdahs r1, {r0, r4, sp, lr}
 *   @0x30633c .word 0xf04f4639
 *   @0x306340 ldrtmi r0, [r0], -r0, lsl #6
 *   @0x306344 svclt #0x949300
 *   @0x306348 ldcvs p12, c6, [r7], #-476
 *   @0x30634c ldrhtvs r4, [r0], #120
 *   @0x306350 and r11, lr, r8, asr r1
 *   @0x306354 strlo r9, [r4, -r7, lsl #18]!
 *   @0x306358 .word 0xd1be428f
 *   @0x30635c bvs 0x11be378 <b2_toiTime+0xa64ed4>
 *   @0x306360 .word 0x47904638
 *   @0x306364 bhs 0x320754
 *   @0x306368 ldmdage r0, {r0, r7, r8, r12, lr, pc}
 *   @0x30636c ldrmi r6, [r8, r3, asr #19]
 *   @0x306370 blge 0x6400a0 <g_SWFaavertbuff+0x6cfd8>
 *   @0x306374 stmdahs r0, {r3, r4, sp, lr}
 *   @0x306378 .word 0xf894d17c
 *   @0x30637c bhs 0xd8ea58 <b2_toiTime+0x6355b4>
 *   @0x306380 andhs sp, r2, #2
 *   @0x306384 rsbs r6, r5, r10, lsl r0
 *   @0x306388 .word 0xf8c49a34
 *   @0x30638c bls 0x144ea24 <b2_toiTime+0xcf5580>
 *   @0x306390 andhs r11, r3, #163840
 *   @0x306394 blls 0x139e404 <b2_toiTime+0xc44f60>
 *   @0x306398 strbls r2, [r5], -r0, lsl #12
 *   @0x30639c orrlo pc, r12, r4, asr #17
 *   @0x3063a0 .word 0xf8c49b48
 *   @0x3063a4 blls 0x1552a5c <b2_toiTime+0xdf95b8>
 *   @0x3063a8 asrslo pc, r4, #17
 *   @0x3063ac shasxls r9, r5, r5
 *   @0x3063b0 orrslo pc, r0, r4, asr #17
 *   @0x3063b4 shasxls r9, r11, r11
 *   @0x3063b8 .word 0x31a8f8c4
 *   @0x3063bc ldrsblo pc, [r0, #-132]!
 *   @0x3063c0 cmple r7, r1, lsl #22
 *   @0x3063c4 .word 0xf10d4ac4
 *   @0x3063c8 blmi 0xff408cd0 <b2_toiTime+0xfffffffffecaf82c>
 *   @0x3063cc .word 0x463546b1
 *   @0x3063d0 ldrbtmi r4, [r11], #-1146
 *   @0x3063d4 movwls r9, #0x8207
 *   @0x3063d8 .word 0x306cf8da
 *   @0x3063dc ble 0x1356e58 <b2_toiTime+0xbfd9b4>
 *   @0x3063e0 .word 0x3180f8d4
 *   @0x3063e4 streq pc, [r0, -pc, asr #32]
 *   @0x3063e8 b 0x16c6698 <b2_toiTime+0xf6d1f4>
 *   @0x3063ec andls r0, r6, #17664
 *   @0x3063f0 andsvc pc, r5, r3, lsr #16
 *   @0x3063f4 .word 0xf8d49f07
 *   @0x3063f8 .word 0xf8433184
 *   @0x3063fc .word 0xf8da7025
 *   @0x306400 .word 0xf8533074
 *   @0x306404 cmplt r11, #37
 *   @0x306408 .word 0x21a4f8d4
 *   @0x30640c addsmi r2, r7, #0, #14
 *   @0x306410 .word 0xf8d4da26
 *   @0x306414 ldrmi r1, [r8], -r8, lsr #3
 *   @0x306418 eorlt pc, r7, r1, asr r8
 *   @0x30641c movwls r9, #0x4203
 *   @0x306420 .word 0xf8cd4659
 *   @0x306424 .word 0xf5b0c014
 *   @0x306428 bge 0x4006c8 <g_RomDisk+0x8ea8>
 *   @0x30642c mulne r12, r2, r8
 *   @0x306430 .word 0xf8d4b9a0
 *   @0x306434 ldrbmi r3, [r9], -r0, lsl #3
 *   @0x306438 stmdals r8, {r1, r2, r9, r11, r12, pc}
 *   @0x30643c andvc pc, r12, r3, lsr #16
 *   @0x306440 .word 0x3184f8d4
 *   @0x306444 andlt pc, r2, r3, asr #16
 *   @0x306448 ldm r4, {r4, r5, r7, r8, r10, r12, sp, lr, pc}
 *   @0x30644c strmi r11, [r9, #0x140]!
 *   @0x306450 strtmi r11, [r9], r8, lsr #31
 *   @0x306454 blle 0x3d6f30 <error_g0017+0x2fbd4>
 *   @0x306458 and r1, r1, lr, ror #24
 *   @0x30645c ldrb r3, [r6, r1, lsl #14]
 *   @0x306460 ldr r3, [r9, r1, lsl #10]!
 *   @0x306464 ldrsblo pc, [r8], #-138
 *   @0x306468 cmnls r8, r4, asr #17
 *   @0x30646c cmnvs r12, r4, asr #17
 *   @0x306470 cmnlo r4, r4, asr #17
 *   @0x306474 vldrge d9, [r0, #-204]
 *   @0x306478 .word 0xf105b113
 *   @0x30647c .word 0x4798005c
 *   @0x306480 tstlt r3, lr, asr #22
 *   @0x306484 sbceq pc, r8, r5, lsl #2
 *   @0x306488 blls 0x13582f0 <b2_toiTime+0xbfee4c>
 *   @0x30648c .word 0xf105b113
 *   @0x306490 .word 0x47980094
 *   @0x306494 tstlt r3, r11, asr r11
 *   @0x306498 rscseq pc, r12, r5, lsl #2
 *   @0x30649c .word 0xf89d4798
 *   @0x3064a0 stmdbvs r8!, {r2, r4, r7, sp, lr}
 *   @0x3064a4 stmdbls r3!, {r1, r2, r3, r4, r8, r11, r12, sp, pc}
 *   @0x3064a8 .word 0xff45f7e0
 *   @0x3064ac stmibvs r11!, {r0, r1, r5, r9, r10, r12, pc}
 *   @0x3064b0 ldrmi r4, [r8, r8, lsr #12]
 *   @0x3064b4 cdphs p14, #0x0, c9, c0, c12, #0x0
 *   @0x3064b8 rscshi pc, r3, r0, asr #32
 *   @0x3064bc svchs #0x9f0a
 *   @0x3064c0 rschi pc, pc, r0, asr #5
 *   @0x3064c4 blhs 0x332fb8
 *   @0x3064c8 rschi pc, r8, r0, asr #32
 *   @0x3064cc .word 0x31a4f8d4
 *   @0x3064d0 rsbvs r6, r6, r6, ror #4
 *   @0x3064d4 stmvs r3!, {r0, r1, r5, r8, sp, lr}
 *   @0x3064d8 andvc pc, r4, #1124073472
 *   @0x3064dc andeq pc, r1, #66
 *   @0x3064e0 .word 0xf89460a2
 *   @0x3064e4 .word 0xb122209c
 *   @0x3064e8 movwvc pc, #0x5443
 *   @0x3064ec movweq pc, #0x1043
 *   @0x3064f0 stmvs r3!, {r0, r1, r5, r7, sp, lr}
 *   @0x3064f4 ldrsbhs pc, [r0], r4
 *   @0x3064f8 movwvs pc, #0x443
 *   @0x3064fc blmi 0x211e790 <b2_toiTime+0x19c52ec>
 *   @0x306500 ldrbtmi r6, [r11], #-354
 *   @0x306504 biclt r6, r2, r3, lsr #3
 *   @0x306508 .word 0x308cf8d4
 *   @0x30650c ldmdavc r9, {r0, r1, r3, r6, r7, r8, r12, sp, pc}
 *   @0x306510 ldmdavc r0, {r0, r3, r4, r5, r7, r8, r12, sp, pc}
 *   @0x306514 smlabble r1, r1, r2, r4
 *   @0x306518 and r3, r3, r1, lsl #4
 *   @0x30651c andle r2, r1, r0, lsr #18
 *   @0x306520 .word 0xd101292d
 *   @0x306524 ldrb r3, [r2, r1, lsl #6]!
 *   @0x306528 andle r2, r1, r0, lsr #16
 *   @0x30652c .word 0xd101282d
 *   @0x306530 strb r3, [r12, r1, lsl #4]!
 *   @0x306534 .word 0x61a3b928
 *   @0x306538 .word 0xf8d4e003
 *   @0x30653c .word 0xb103316c
 *   @0x306540 movwhs r6, #0x163
 *   @0x306544 eorvs r6, r3, #-1073741768
 *   @0x306548 eorvs r2, r11, r9, lsl #6
 *   @0x30654c stmdbmi r5!, {r0, r1, r5, r9, r10, r11, sp, lr} ^
 *   @0x306550 ldrbtmi r6, [r9], #-2136
 *   @0x306554 stc2l p7, c15, [r12], {223}
 *   @0x306558 ldrsblo pc, [r0, #132]!
 *   @0x30655c rsbvs r9, r11, r11, lsl #30
 *   @0x306560 ldrsblo pc, [r4, #132]!
 *   @0x306564 smultbvs r8, r11, r0
 *   @0x306568 stmdavs r11!, {r0, r1, r2, r4, r5, r8, r12, sp, pc}
 *   @0x30656c .word 0xf04361af
 *   @0x306570 eorvs r0, r11, r0, lsl r3
 *   @0x306574 mvnvs r9, r6, ror #22
 *   @0x306578 strtmi r6, [r9], -r3, lsr #28
 *   @0x30657c ldmdavs r8, {r9, sp} ^
 *   @0x306580 .word 0x73fcf504
 *   @0x306584 .word 0xf8c7f7e3
 *   @0x306588 stmdahs r0, {r0, r7, r9, r10, lr}
 *   @0x30658c addhi pc, r8, r0, asr #32
 *   @0x306590 ldrsblo pc, [r8, #132]!
 *   @0x306594 .word 0xf7e26d98
 *   @0x306598 .word 0xf8d4fa39
 *   @0x30659c .word 0xf10471f8
 *   @0x3065a0 .word 0xf1070c34
 *   @0x3065a4 blgt 0x6c727c <g_SWFlinevertbuff+0x741b4>
 *   @0x3065a8 andeq lr, pc, r12, lsl #17
 *   @0x3065ac strhlo pc, [r4], #-135
 *   @0x3065b0 sublo pc, r4, r4, lsr #17
 *   @0x3065b4 strhlo pc, [r6], #-135
 *   @0x3065b8 sublo pc, r6, r4, lsr #17
 *   @0x3065bc strhlo pc, [r8], #-135
 *   @0x3065c0 sublo pc, r8, r4, lsr #17
 *   @0x3065c4 strhlo pc, [r10], #-135
 *   @0x3065c8 sublo pc, r10, r4, lsr #17
 *   @0x3065cc strhlo pc, [r12], #-135
 *   @0x3065d0 sublo pc, r12, r4, lsr #17
 *   @0x3065d4 strhlo pc, [lr], #-135
 *   @0x3065d8 andls pc, r12, r4, asr #17
 *   @0x3065dc sublo pc, lr, r4, lsr #17
 *   @0x3065e0 ldrhlo pc, [lr], r4
 *   @0x3065e4 subslo pc, r0, r4, lsr #17
 *   @0x3065e8 .word 0x30a0f8b4
 *   @0x3065ec subslo pc, r2, r4, lsr #17
 *   @0x3065f0 ldrsblo pc, [r8], r4
 *   @0x3065f4 movwhs r11, #0x110b
 *   @0x3065f8 ldmvs r11!, {r0, r1, r5, r6, r7, sp, lr} ^
 *   @0x3065fc strle r0, [r3, #-0x79a]
 *   @0x306600 .word 0xf04368e3
 *   @0x306604 rscvs r0, r3, r2, lsl #6
 *   @0x306608 .word 0x069b68bb
 *   @0x30660c stmvs r3!, {r0, r1, r8, r10, r12, lr, pc}
 *   @0x306610 hinteq #0x43
 *   @0x306614 svcls #0x960a3
 *   @0x306618 suble r2, r2, r0, lsl #30
 *   @0x30661c ldrsbvc pc, [r4], -r8
 *   @0x306620 .word 0x812b2303
 *   @0x306624 .word 0x816b2301
 *   @0x306628 blmi 0xb0ea30 <b2_toiTime+0x3b558c>
 *   @0x30662c eorvs r4, r12, r10, lsr #12
 *   @0x306630 strmi r6, [r11], -r11, rrx
 *   @0x306634 .word 0xf7e168f8
 *   @0x306638 .word 0x4606fe9e
 *   @0x30663c sbclt r11, r3, #16, #2
 *   @0x306640 smulwble lr, r3, r11
 *   @0x306644 .word 0x812b2307
 *   @0x306648 ldrsblo pc, [r0, #-132]!
 *   @0x30664c blhs 0x3d5258 <error_g0017+0x2defc>
 *   @0x306650 ldm pc, {r1, r2, r5, r11, r12, lr, pc} ^
 *   @0x306654 andeq pc, lr, #3
 *   @0x306658 blmi 0x8486b0 <b2_toiTime+0xef20c>
 *   @0x30665c movwhs r6, #0x6b
 *   @0x306660 ldmdavs r8!, {r0, r1, r3, r5, r6, r8, pc}
 *   @0x306664 blmi 0x7fe6ac <b2_toiTime+0xa5208>
 *   @0x306668 movwhs r6, #0x106b
 *   @0x30666c ldmdavs r8!, {r0, r1, r3, r5, r6, r8, pc} ^
 *   @0x306670 blmi 0x77e6a0 <b2_toiTime+0x251fc>
 *   @0x306674 movwhs r6, #0x206b
 *   @0x306678 ldmvs r8!, {r0, r1, r3, r5, r6, r8, pc}
 *   @0x30667c blmi 0x6fe694 <g_SWFvertbuff+0x2b5cc>
 *   @0x306680 movwhs r6, #0x306b
 *   @0x306684 ldmvs r8!, {r0, r1, r3, r5, r6, r8, pc} ^
 *   @0x306688 qaddhs r11, r0, r0
 *   @0x30668c strmi r4, [r11], -r10, lsr #12
 *   @0x306690 cdp2 p7, #0x7, c15, c1, c1, #0x7
 *   @0x306694 and r4, r3, r1, lsl #13
 *   @0x306698 and r2, r2, r11, lsl #12
 *   @0x30669c and r2, r0, r6, lsl #12
 *   @0x3066a0 ldrtmi r4, [r0], -lr, asr #12
 *   @0x3066a4 pop {r0, r2, r3, r4, r6, r12, sp, pc}
 *   @0x3066a8 svclt #0x8ff0
 *   @0x3066ac strbvc r6, [lr, #-0x963]!
 *   @0x3066b0 .word 0x41444f42
 *   @0x3066b4 .word 0x41444245
 *   @0x3066b8 .word 0x41444243
 *   @0x3066bc stclvs p4, c7, [r1], #-196
 *   @0x3066c0 andeq r8, r8, r5, lsl r8
 *   @0x3066c4 andeq r8, r8, r0, lsr r8
 *   @0x3066c8 strheq r8, [r8], -r8
 *   @0x3066cc andeq r3, lr, r4, ror #30
 *   @0x3066d0 andeq r8, r8, r8, asr r10
 *   @0x3066d4 andeq r8, r8, r12, asr #25
 *   @0x3066d8 andeq r8, r8, r1, lsr r8
 *   @0x3066dc andeq r8, r8, pc, lsr #16
 *   @0x3066e0 andeq r8, r8, r10, lsl #6
 *   @0x3066e4 andeq r8, r8, lr, asr #3
 *   @0x3066e8 .word 0xf8d36803
 *   @0x3066ec .word 0xf8922084
 *   @0x3066f0 .word 0x61033068
 *   @0x3066f4 mlshs r9, r2, r8, pc
 *   @0x3066f8 bne 0xff7d2f04 <b2_toiTime+0xffffffffff079a60>
 *   @0x3066fc andhs r6, r0, r3, asr #2
 *   @0x306700 stmdbvs r3, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x306704 stmdbvs r3, {r0, r3, r6, r7, r9, r11, r12} ^
 *   @0x306708 svclt #0x344299
 *   @0x30670c andhs r1, r0, r8, asr #24
 *   @0x306710 stmdavs r10, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x306714 andlo r6, r1, #49152
 *   @0x306718 stmdble r6, {r1, r3, r4, r7, r9, lr}
 *   @0x30671c bne 0xff7e0c24 <b2_toiTime+0xffffffffff087780>
 *   @0x306720 andle r4, r4, #805306376
 *   @0x306724 ssaxmi r1, r3, r8
 *   @0x306728 andhs lr, r1, r3
 *   @0x30672c movwhs lr, #0x1
 *   @0x306730 andvs r4, r11, r8, lsl r6
 *   @0x306734 strlt r4, [r8, #-0x770]
 *   @0x306738 .word 0xf8d0229c
 *   @0x30673c strmi r3, [r8], -r4, lsl #1
 *   @0x306740 .word 0xf5af1d19
 *   @0x306744 andhs lr, r0, r12, lsr pc
 *   @0x306748 ldrlt r11, [r8, #-0xd08]!
 *   @0x30674c stmdavs r0, {r2, r9, r10, lr}
 *   @0x306750 .word 0xf8d02100
 *   @0x306754 .word 0xf7de5084
 *   @0x306758 andhs pc, r0, r5, ror #29
 *   @0x30675c ldrhlo pc, [r0], #-133
 *   @0x306760 .word 0x61a3019b
 *   @0x306764 ldrhhs pc, [r0], #-133
 *   @0x306768 strhtlo pc, [r0], #-133
 *   @0x30676c ldrsbeq r1, [r11, r3]
 *   @0x306770 rfeia r5!
 *   @0x306774 orrseq r3, r11, r6, rrx
 *   @0x306778 ldclt p2, c6, [r8, #-396]!
 *   @0x30677c .word 0x4605b5f8
 *   @0x306780 strmi r6, [r12], -r3, lsl #16
 *   @0x306784 .word 0xf8d36888
 *   @0x306788 bvs 0xade9a0 <b2_toiTime+0x3854fc>
 *   @0x30678c .word 0xb123690b
 *   @0x306790 qdaddhs r4, r8, r8
 *   @0x306794 .word 0xf0123024
 *   @0x306798 .word 0x3020eabc
 *   @0x30679c orrne r6, r0, r3, lsr #16
 *   @0x3067a0 blhs 0x372bf4 <_ZTS13C_UTF16String+0x9ca0>
 *   @0x3067a4 ands sp, r1, r6
 *   @0x3067a8 .word 0x332068fb
 *   @0x3067ac svcne #0xa3ebb0
 *   @0x3067b0 and sp, r5, r4, lsl #2
 *   @0x3067b4 strhtlo pc, [r0], #-134
 *   @0x3067b8 mulle r1, r8, r2
 *   @0x3067bc ldcllt p0, c2, [r8, #92]!
 *   @0x3067c0 .word 0x21004628
 *   @0x3067c4 ldrhtmi lr, [r8], #141
 *   @0x3067c8 svclt #0xbff7ff
 *   @0x3067cc ldcllt p0, c2, [r8, #28]!
 *   @0x3067d0 mvnsmi lr, sp, lsr #18
 *   @0x3067d4 stmdavs r9, {r1, r2, r3, r4, r9, r10, lr}
 *   @0x3067d8 strmi r2, [r4], -r0, lsl #6
 *   @0x3067dc .word 0x23239303
 *   @0x3067e0 .word 0xf8d1b131
 *   @0x3067e4 tstlt r5, r4, lsl #1
 *   @0x3067e8 addsmi r6, r10, #180224
 *   @0x3067ec movwhs sp, #0x6302
 *   @0x3067f0 rsbs r9, sp, r3, lsl #6
 *   @0x3067f4 cdpne p1, #0x5, c11, c3, c10, #0x0
 *   @0x3067f8 .word 0xf895e001
 *   @0x3067fc stmhi r8!, {r1, r3, r5, r6, r12, sp}
 *   @0x306800 subvc pc, r0, #176, #10
 *   @0x306804 cmpmi r0, r0, asr r2
 *   @0x306808 svclt #0x142800
 *   @0x30680c .word 0x21042106
 *   @0x306810 addshs r11, r4, #20, #30
 *   @0x306814 blx 0x3cf1f6 <error_g0017+0x27e9a>
 *   @0x306818 stmvs r11!, {r0, r9, sp}
 *   @0x30681c .word 0x2102bf0c
 *   @0x306820 bllo 0x38ec38 <_ZTS7CBucketILj16384ELj262144ELb1EE+0x2c94>
 *   @0x306824 addsmi r1, r10, #372736
 *   @0x306828 .word 0xf8d5d243
 *   @0x30682c ldmne r9!, {r5, r7, r12, sp, lr}
 *   @0x306830 .word 0xf8915cbb
 *   @0x306834 b 0x13f6840 <b2_toiTime+0xc9d39c>
 *   @0x306838 strvs r2, [r3, #-0x30c]!
 *   @0x30683c stmvc pc, {r1, r3, r7, r11, r12, sp, lr} ^
 *   @0x306840 stmdbvc r8, {r3, r5, r8, r12, sp, pc} ^
 *   @0x306844 streq r7, [r9], #-2313
 *   @0x306848 .word 0x6100ea41
 *   @0x30684c b 0x139747c <b2_toiTime+0xc3dfd8>
 *   @0x306850 stmvs r10!, {r0, r1, r2, r8, r9, r10, sp}
 *   @0x306854 eorle r4, r12, #1879048201
 *   @0x306858 strhtne pc, [r0], #-133
 *   @0x30685c andhs r2, r1, #0
 *   @0x306860 .word 0xf8846660
 *   @0x306864 orrseq r2, r11, lr, asr r0
 *   @0x306868 orreq r6, r9, r1, ror #9
 *   @0x30686c ldrhhs pc, [r0], #-133
 *   @0x306870 .word 0xe084f8df
 *   @0x306874 .word 0xf1046220
 *   @0x306878 ssatvs r0, #0x3, r8
 *   @0x30687c .word 0xf8c40192
 *   @0x306880 rsbvs lr, r2, #72
 *   @0x306884 mvnvs r6, r3, lsr #3
 *   @0x306888 .word 0xf7de62a3
 *   @0x30688c .word 0xf416fe29
 *   @0x306890 smlawble sp, r0, r2, r0
 *   @0x306894 stmdavs r3!, {r1, r2, r5, r8, r10, r11, sp, lr} ^
 *   @0x306898 .word 0xf8d53607
 *   @0x30689c ldmeq r6!, {r5, r7, pc} ^
 *   @0x3068a0 strbvs r6, [r6, #-0xe58]!
 *   @0x3068a4 stclvs p1, c11, [r1], #184
 *   @0x3068a8 blx 0x360b5e <_ZTS12CDS_Priority+0x2bb6>
 *   @0x3068ac ldrmi r7, [r12, #0xc06]
 *   @0x3068b0 movwhs sp, #0x3901
 *   @0x3068b4 blge 0x40072c <g_RomDisk+0x8f0c>
 *   @0x3068b8 movwls r9, #0x1200
 *   @0x3068bc .word 0xf7e14633
 *   @0x3068c0 blls 0x405860 <g_RomDisk+0xe040>
 *   @0x3068c4 ldmiblt r11, {r5, r7, r8, r10, sp, lr}
 *   @0x3068c8 strmi r4, [r6], #-1095
 *   @0x3068cc ldmne r9!, {r0, r1, r5, r6, r7, r10, r11, sp, lr} ^
 *   @0x3068d0 addmi r4, pc, #3145728
 *   @0x3068d4 .word 0xf817d205
 *   @0x3068d8 andsvc r2, r10, r1, lsl #22
 *   @0x3068dc ldrmi r6, [r3], #-3426
 *   @0x3068e0 strdlo lr, pc, [r1], -r7
 *   @0x3068e4 ldrhle r4, [r1, #32]!
 *   @0x3068e8 ldrsblo pc, [r12], r4
 *   @0x3068ec subsvs r2, r10, r1, lsl #4
 *   @0x3068f0 andlt r9, r4, r3, lsl #16
 *   @0x3068f4 ldrhhi lr, [r0, #141]!
 *   @0x3068f8 rsbvs r7, r9, #1929379840
 *   @0x3068fc .word 0x4605b5f8
 *   @0x306900 .word 0x4084f8d5
 *   @0x306904 cdpvs p14, #0x8, c6, c0, c6, #0x2
 *   @0x306908 .word 0xf8d4b1a4
 *   @0x30690c tstlt r11, r0, lsr #1
 *   @0x306910 lsleq pc, r4, #2
 *   @0x306914 blx 0x21848a0 <b2_toiTime+0x1a2b3fc>
 *   @0x306918 .word 0xf8d44630
 *   @0x30691c .word 0xf7e010a8
 *   @0x306920 strhs pc, [r0, -r10, lsl #26]
 *   @0x306924 .word 0xf8c44630
 *   @0x306928 strtmi r7, [r1], -r8, lsr #1
 *   @0x30692c stc2 p7, c15, [r3, #-896]
 *   @0x306930 addvc pc, r4, r5, asr #17
 *   @0x306934 ldrlt r11, [r8, #-0xdf8]!
 *   @0x306938 .word 0xb1484604
 *   @0x30693c .word 0xf7ff6e45
 *   @0x306940 bvs 0xb868bc <b2_toiTime+0x42d418>
 *   @0x306944 .word 0xf7e04628
 *   @0x306948 movwhs pc, #0xcf6
 *   @0x30694c mvnvs r6, r3, lsr #4
 *   @0x306950 andeq r11, r0, r8, lsr sp
 *   @0x306954 ldrbtmi r4, [r8], #-2049
 *   @0x306958 ldcllt p7, c15, [r11], #888
 *   @0x30695c andeq r3, lr, r2, ror r11
 *   @0x306960 .word 0x4604b538
 *   @0x306964 strmi r4, [r8], -sp, lsl #12
 *   @0x306968 .word 0xf7df6821
 *   @0x30696c bllt 0xfeb467e4 <b2_toiTime+0xfffffffffe3ed340>
 *   @0x306970 qadd16mi r4, r8, r10
 *   @0x306974 ldrbtmi r1, [r9], #-3362
 *   @0x306978 blx 0xfee44904 <b2_toiTime+0xfffffffffe6eb460>
 *   @0x30697c stmhi r3!, {r3, r5, r6, r8, r9, r11, r12, sp, pc}
 *   @0x306980 svcvc #0xf5b3
 *   @0x306984 .word 0xf5b3d004
 *   @0x306988 andle r7, r3, r0, asr #30
 *   @0x30698c ldclt p0, c2, [r8, #-8]!
 *   @0x306990 and r2, r0, r6, ror r2
 *   @0x306994 stmvs r1!, {r2, r4, r7, r9, sp}
 *   @0x306998 .word 0xd3f74291
 *   @0x30699c svcvc #0xf5b3
 *   @0x3069a0 movwhs sp, #0x10a
 *   @0x3069a4 addlo pc, r4, r4, asr #17
 *   @0x3069a8 addlo pc, r8, r4, lsr #17
 *   @0x3069ac addlo pc, r10, r4, lsr #17
 *   @0x3069b0 addlo pc, r12, r4, lsr #17
 *   @0x3069b4 addlo pc, lr, r4, lsr #17
 *   @0x3069b8 strhlo pc, [r8], #-132
 *   @0x3069bc strbtle r0, [r5], #2011
 *   @0x3069c0 stmdavs r1!, {r3, r5, r9, r10, lr}
 *   @0x3069c4 .word 0xff6ff7df
 *   @0x3069c8 qasxmi r11, r8, r8
 *   @0x3069cc .word 0xf10468a1
 *   @0x3069d0 pop {r5, r7, r9}
 *   @0x3069d4 .word 0xf7e14038
 *   @0x3069d8 vldmdblt r8!, {s22, s23, s24, s25, s26, s27, s28, s29, s30, s31}
 *   @0x3069dc andeq r9, r9, r0, lsl #23
 *   @0x3069e0 svcmi #0xf0e92d
 *   @0x3069e4 .word 0xf8dfb0b7
 *   @0x3069e8 strmi r9, [r12], -r12, lsl #9
 *   @0x3069ec b 0xfe3a2428 <b2_toiTime+0xfffffffffdc48f84>
 *   @0x3069f0 bl 0xfece4980 <b2_toiTime+0xfffffffffe58b4dc>
 *   @0x3069f4 ldrbtmi r7, [r9], #2018
 *   @0x3069f8 .word 0x9000f8d9
 *   @0x3069fc andls r6, r6, lr, asr #28
 *   @0x306a00 .word 0xf8d92100
 *   @0x306a04 strtmi r3, [r8], -r0
 *   @0x306a08 addne pc, r4, r4, asr #17
 *   @0x306a0c adcslt r4, pc, #144, #12
 *   @0x306a10 .word 0xf7df9335
 *   @0x306a14 .word 0xf8cdff48
 *   @0x306a18 andsls r9, r1, r8, lsr #32
 *   @0x306a1c .word 0xf0402800
 *   @0x306a20 .word 0xf8df823a
 *   @0x306a24 qsaxmi r9, r8, r4
 *   @0x306a28 ldrbtmi r10, [r9], #2578
 *   @0x306a2c orrseq pc, r8, r9, lsl #2
 *   @0x306a30 blx 0x17449bc <b2_toiTime+0xfeb518>
 *   @0x306a34 rfeia sp!
 *   @0x306a38 .word 0xf6452048
 *   @0x306a3c .word 0xf04f234d
 *   @0x306a40 .word 0xf8cd0a02
 *   @0x306a44 addsmi r10, r10, #68
 *   @0x306a48 eorhi pc, r0, #64
 *   @0x306a4c rfeia sp!
 *   @0x306a50 .word 0xf7df104a
 *   @0x306a54 andsls pc, r1, r8, lsr #30
 *   @0x306a58 .word 0xf0402800
 *   @0x306a5c qadd16mi r8, r8, r12
 *   @0x306a60 .word 0x01acf109
 *   @0x306a64 .word 0xf7e1aa13
 *   @0x306a68 .word 0xb108fa35
 *   @0x306a6c ands r9, r2, #17
 *   @0x306a70 subge pc, r4, sp, asr #17
 *   @0x306a74 movtpl pc, #0xe244
 *   @0x306a78 strhge pc, [r12], #-141
 *   @0x306a7c .word 0xf040459a
 *   @0x306a80 rfeia sp!
 *   @0x306a84 strtmi r1, [r8], -r10, asr #32
 *   @0x306a88 strhlo pc, [lr], #-141
 *   @0x306a8c .word 0xf7df4419
 *   @0x306a90 andsls pc, r1, r10, lsl #30
 *   @0x306a94 .word 0xf0402800
 *   @0x306a98 rfeia sp!
 *   @0x306a9c qsaxmi r1, r8, r0
 *   @0x306aa0 strhlo pc, [lr], #-141
 *   @0x306aa4 .word 0xf7e11ac9
 *   @0x306aa8 ldrhls pc, [r1], -r12
 *   @0x306aac .word 0xf0402800
 *   @0x306ab0 qsub8mi r8, r8, r2
 *   @0x306ab4 .word 0xffadf7df
 *   @0x306ab8 pkhbtmi r2, r1, r0, lsl #16
 *   @0x306abc bicshi pc, r1, r0, lsl #4
 *   @0x306ac0 beq 0x642c04 <g_SWFaavertbuff+0x6fb3c>
 *   @0x306ac4 .word 0xf7df4628
 *   @0x306ac8 strmi pc, [r2], -r4, lsr #31
 *   @0x306acc .word 0x4628b1d8
 *   @0x306ad0 .word 0xf7df9202
 *   @0x306ad4 bls 0x3c6954 <error_g0017+0x1f5f8>
 *   @0x306ad8 .word 0x0108f248
 *   @0x306adc strmi r4, [r3], r10, lsl #5
 *   @0x306ae0 strtmi sp, [r8], -r10, lsl #2
 *   @0x306ae4 .word 0xff2cf7df
 *   @0x306ae8 bvs 0x1da1394 <b2_toiTime+0x1647ef0>
 *   @0x306aec beq 0x3819fc <_ZTS13C_UTF16String+0x18aa8>
 *   @0x306af0 beq 0x442f20 <g_RomDisk+0x4b700>
 *   @0x306af4 and r4, r8, r2, lsl #9
 *   @0x306af8 .word 0xf300fb0a
 *   @0x306afc movwlo r6, #0x4a2a
 *   @0x306b00 eorvs r4, r10, #436207616
 *   @0x306b04 pkhtbmi lr, r2, lr, asr #15
 *   @0x306b08 strtmi r4, [r8], -r3, lsl #13
 *   @0x306b0c .word 0xf9d4f7e1
 *   @0x306b10 svceq #0xf1bb
 *   @0x306b14 .word 0x81a5f000
 *   @0x306b18 svceq #0xf1ba
 *   @0x306b1c .word 0x81a1f000
 *   @0x306b20 stmdavs r10!, {r1, r2, r4, r5, r6, r8, sp} ^
 *   @0x306b24 .word 0xf10bfb01
 *   @0x306b28 vqsub.s8 d4, d16, d1
 *   @0x306b2c .word 0xf1b8819a
 *   @0x306b30 .word 0xf8c40f00
 *   @0x306b34 .word 0xf2c0b000
 *   @0x306b38 ldrbmi r8, [pc, #-0x1ae]
 *   @0x306b3c orrshi pc, r5, r0, lsl #5
 *   @0x306b40 .word 0x21ac4630
 *   @0x306b44 .word 0xf7e0aa11
 *   @0x306b48 blls 0x785708 <b2_toiTime+0x2c264>
 *   @0x306b4c addeq pc, r4, r4, asr #17
 *   @0x306b50 .word 0xf0402b00
 *   @0x306b54 .word 0xf04f81a0
 *   @0x306b58 strtmi r0, [r8], -r12, lsl #22
 *   @0x306b5c .word 0xa107fb0b
 *   @0x306b60 mcr2 p7, #0x5, pc, c1, c15, #0x6
 *   @0x306b64 stmdahs r0, {r0, r4, r12, pc}
 *   @0x306b68 orrshi pc, r0, r0, asr #32
 *   @0x306b6c ldrbmi r4, [r9], -r8, lsr #12
 *   @0x306b70 .word 0xf957f7e1
 *   @0x306b74 stmdahs r0, {r0, r4, r12, pc}
 *   @0x306b78 orrhi pc, r8, r0, asr #32
 *   @0x306b7c .word 0xf8d44628
 *   @0x306b80 .word 0xf7dfa084
 *   @0x306b84 blx 0x3468a4
 *   @0x306b88 .word 0xf8caf009
 *   @0x306b8c strtmi r0, [r8], -r0
 *   @0x306b90 .word 0xa084f8d4
 *   @0x306b94 .word 0xff3df7df
 *   @0x306b98 .word 0xf009fa00
 *   @0x306b9c adceq pc, r4, r10, asr #17
 *   @0x306ba0 strtmi r6, [r8], -r11, lsr #20
 *   @0x306ba4 eorvs r3, r11, #8, #6
 *   @0x306ba8 .word 0xf986f7e1
 *   @0x306bac .word 0x0084f8d4
 *   @0x306bb0 .word 0xf7ff4629
 *   @0x306bb4 ldrsbls pc, [r1], -r5
 *   @0x306bb8 .word 0xf244e151
 *   @0x306bbc ldrmi r5, [r10, #0x350]
 *   @0x306bc0 .word 0x814df040
 *   @0x306bc4 rfeia sp!
 *   @0x306bc8 .word 0xf7df104a
 *   @0x306bcc andsls pc, r1, r12, ror #28
 *   @0x306bd0 .word 0xf0402800
 *   @0x306bd4 strtmi r8, [r8], -r0, ror #2
 *   @0x306bd8 biceq pc, r4, r9, lsl #2
 *   @0x306bdc .word 0xf7e1aa2b
 *   @0x306be0 andsls pc, r1, r9, ror r9
 *   @0x306be4 .word 0xf0402800
 *   @0x306be8 blls 0xde7148 <b2_toiTime+0x68dca4>
 *   @0x306bec .word 0xf0404553
 *   @0x306bf0 rfeia sp!
 *   @0x306bf4 .word 0xf5b330b0
 *   @0x306bf8 .word 0xf0407fa6
 *   @0x306bfc blls 0xe670cc <b2_toiTime+0x70dc28>
 *   @0x306c00 addsmi r4, r3, #634880
 *   @0x306c04 .word 0x812df040
 *   @0x306c08 rsbsge pc, r0, #14614528
 *   @0x306c0c ldrmi r2, [r9], r0, lsl #6
 *   @0x306c10 ldrbtmi r6, [r10], #35
 *   @0x306c14 .word 0xf10aab30
 *   @0x306c18 rfeia sp!
 *   @0x306c1c strbmi r2, [r10, #-0xb2]
 *   @0x306c20 tsthi pc, r0, asr #4
 *   @0x306c24 qadd16mi r4, r8, r10
 *   @0x306c28 movwls r4, #0x2659
 *   @0x306c2c .word 0xf952f7e1
 *   @0x306c30 andsls r9, r1, r2, lsl #22
 *   @0x306c34 .word 0xf0402800
 *   @0x306c38 bls 0xfa70f8 <b2_toiTime+0x84dc54>
 *   @0x306c3c addsmi r9, r1, #753664
 *   @0x306c40 .word 0xf109d004
 *   @0x306c44 blx 0xac9050 <b2_toiTime+0x36fbac>
 *   @0x306c48 strb pc, [r6, r9, lsl #19]!
 *   @0x306c4c ldmdbls r4!, {r3, r5, r9, r10, lr}
 *   @0x306c50 mcr2 p7, #0x1, pc, c9, c15, #0x6
 *   @0x306c54 stmdahs r0, {r0, r4, r12, pc}
 *   @0x306c58 tsthi sp, r0, asr #32
 *   @0x306c5c .word 0xf50a4628
 *   @0x306c60 bge 0x9e3298 <b2_toiTime+0x289df4>
 *   @0x306c64 rfedb r6!
 *   @0x306c68 stmdahs r0, {r0, r4, r12, pc}
 *   @0x306c6c tsthi r3, r0, asr #32
 *   @0x306c70 .word 0x46839b34
 *   @0x306c74 blmi 0xfe3ab888 <b2_toiTime+0xfffffffffdc523e4>
 *   @0x306c78 movwls r4, #0x747b
 *   @0x306c7c orrsvc pc, r12, #12582912
 *   @0x306c80 blmi 0xfe32b8c0 <b2_toiTime+0xfffffffffdbd241c>
 *   @0x306c84 movwls r4, #0x847b
 *   @0x306c88 ldrbtmi r4, [r11], #-2943
 *   @0x306c8c .word 0xf5039309
 *   @0x306c90 movwls r7, #0xf39c
 *   @0x306c94 ldrhths pc, [r8], #-141
 *   @0x306c98 ldrhtlo pc, [r10], #-141
 *   @0x306c9c ldrmi r4, [r11, #0x413]
 *   @0x306ca0 sbcshi pc, sp, r0, lsl #5
 *   @0x306ca4 strtmi r9, [r8], -r3, lsl #22
 *   @0x306ca8 tsteq r0, r3, lsl #2
 *   @0x306cac biceq lr, r11, r1, lsl #22
 *   @0x306cb0 ldc2l p7, c15, [r9, #892]!
 *   @0x306cb4 stmdahs r0, {r0, r4, r12, pc}
 *   @0x306cb8 rschi pc, sp, r0, asr #32
 *   @0x306cbc stmdbls lr, {r3, r5, r9, r10, lr}
 *   @0x306cc0 .word 0xf7e1aa15
 *   @0x306cc4 andsls pc, r1, r7, lsl #18
 *   @0x306cc8 .word 0xf0402800
 *   @0x306ccc blls 0x8a7064 <b2_toiTime+0x14dbc0>
 *   @0x306cd0 .word 0xf2802b00
 *   @0x306cd4 bls 0x1026ff4 <b2_toiTime+0x8cdb50>
 *   @0x306cd8 movwmi pc, #0x23
 *   @0x306cdc tstls r6, #40, #12
 *   @0x306ce0 andls r1, r4, #10092544
 *   @0x306ce4 .word 0xf7df4611
 *   @0x306ce8 ldrsbls pc, [r1], -lr
 *   @0x306cec .word 0xf0402800
 *   @0x306cf0 blls 0x4e7040 <SrcVerts+0x44084>
 *   @0x306cf4 bge 0xad859c <b2_toiTime+0x37f0f8>
 *   @0x306cf8 orrvc pc, r12, r3, lsl #10
 *   @0x306cfc .word 0xf8eaf7e1
 *   @0x306d00 stmdahs r0, {r0, r4, r12, pc}
 *   @0x306d04 sbchi pc, r7, r0, asr #32
 *   @0x306d08 strmi r9, [r1], r8, lsl #22
 *   @0x306d0c orrsvc pc, r12, #12582912
 *   @0x306d10 blge 0x8eb948 <b2_toiTime+0x1924a4>
 *   @0x306d14 rfeia sp!
 *   @0x306d18 rfeia sp!
 *   @0x306d1c ldrmi r3, [r3], #-138
 *   @0x306d20 vshl.i64 d4, d9, #0x0
 *   @0x306d24 blls 0x426f88 <g_RomDisk+0x2f768>
 *   @0x306d28 .word 0xf1034628
 *   @0x306d2c bl 0x347174
 *   @0x306d30 .word 0xf7df01c9
 *   @0x306d34 ldrhls pc, [r1], -r8
 *   @0x306d38 .word 0xf0402800
 *   @0x306d3c strtmi r8, [r8], -r12, lsr #1
 *   @0x306d40 bge 0x8ed178 <b2_toiTime+0x193cd4>
 *   @0x306d44 .word 0xf8c6f7e1
 *   @0x306d48 stmdahs r0, {r0, r4, r12, pc}
 *   @0x306d4c adchi pc, r3, r0, asr #32
 *   @0x306d50 blhs 0x32d9b8
 *   @0x306d54 addhi pc, r5, r0, lsl #5
 *   @0x306d58 .word 0xf0239a34
 *   @0x306d5c strtmi r4, [r8], -r0, lsl #6
 *   @0x306d60 ldmne r10, {r3, r4, r8, r9, r12, pc}
 *   @0x306d64 ldrmi r9, [r1], -r5, lsl #4
 *   @0x306d68 ldc2 p7, c15, [sp, #892]
 *   @0x306d6c stmdahs r0, {r0, r4, r12, pc}
 *   @0x306d70 addshi pc, r1, r0, asr #32
 *   @0x306d74 strtmi r9, [r8], -r8, lsl #22
 *   @0x306d78 .word 0xf503aa23
 *   @0x306d7c .word 0xf7e1718c
 *   @0x306d80 andsls pc, r1, r9, lsr #17
 *   @0x306d84 .word 0xf0402800
 *   @0x306d88 strmi r8, [r2], r6, lsl #1
 *   @0x306d8c movwls r10, #0xbb19
 *   @0x306d90 ldrhhs pc, [r8], sp
 *   @0x306d94 ldrhlo pc, [r10], sp
 *   @0x306d98 ldrmi r4, [r10, #0x413]
 *   @0x306d9c blls 0x47d6f8 <targetStr+0x24b8>
 *   @0x306da0 .word 0xf1034628
 *   @0x306da4 bl 0x3471ec
 *   @0x306da8 .word 0xf7df01ca
 *   @0x306dac andsls pc, r1, r12, ror sp
 *   @0x306db0 cmnle r0, r0, lsl #16
 *   @0x306db4 stmdbls pc, {r3, r5, r9, r10, lr}
 *   @0x306db8 .word 0xf7e1aa19
 *   @0x306dbc andsls pc, r1, r11, lsl #17
 *   @0x306dc0 .word 0xd1682800
 *   @0x306dc4 blhs 0x32da2c
 *   @0x306dc8 blls 0x87dafc <b2_toiTime+0x124658>
 *   @0x306dcc teqle r7, r8, lsl #22
 *   @0x306dd0 qadd16mi r9, r8, r10
 *   @0x306dd4 ldrmi r9, [r9], #-2819
 *   @0x306dd8 stc2l p7, c15, [r5, #-892]!
 *   @0x306ddc stmdahs r0, {r0, r4, r12, pc}
 *   @0x306de0 blls 0x57b34c <g_SWFlineaavertbuff+0x28284>
 *   @0x306de4 bge 0xcd868c <b2_toiTime+0x57f1e8>
 *   @0x306de8 .word 0x71a4f503
 *   @0x306dec .word 0xf872f7e1
 *   @0x306df0 stmdahs r0, {r0, r4, r12, pc}
 *   @0x306df4 stmdavs r3!, {r0, r1, r2, r3, r6, r8, r12, lr, pc}
 *   @0x306df8 mulle r3, pc, r2
 *   @0x306dfc movwlo r6, #0x1823
 *   @0x306e00 ands r6, sp, r3, lsr #32
 *   @0x306e04 .word 0x21ac4630
 *   @0x306e08 .word 0xf7e0aa11
 *   @0x306e0c blls 0x785444 <b2_toiTime+0x2bfa0>
 *   @0x306e10 addeq pc, r4, r4, asr #17
 *   @0x306e14 teqle lr, r0, lsl #22
 *   @0x306e18 qasxmi r9, r9, r4
 *   @0x306e1c ldrmi r9, [r10], #-2599
 *   @0x306e20 bne 0xff7edaf0 <b2_toiTime+0xffffffffff09464c>
 *   @0x306e24 bls 0xd1ee38 <b2_toiTime+0x5c5994>
 *   @0x306e28 .word 0x3084f8d4
 *   @0x306e2c adchs pc, r4, r3, asr #17
 *   @0x306e30 .word 0x0084f8d4
 *   @0x306e34 ldc2 p7, c15, [r4, #1020]
 *   @0x306e38 stmdahs r0, {r0, r4, r12, pc}
 *   @0x306e3c .word 0xe025d0de
 *   @0x306e40 beq 0x383270 <_ZTS13C_UTF16String+0x1a31c>
 *   @0x306e44 blx 0xfe5c56c8 <b2_toiTime+0xfffffffffde6c224>
 *   @0x306e48 .word 0xf109e7a2
 *   @0x306e4c blx 0xac9258 <b2_toiTime+0x36fdb4>
 *   @0x306e50 strb pc, [r0, -r9, lsl #19]!
 *   @0x306e54 movweq pc, #0x110b
 *   @0x306e58 blx 0xfe4056de <b2_toiTime+0xfffffffffdcac23a>
 *   @0x306e5c stmdavs r3!, {r1, r3, r4, r8, r9, r10, sp, lr, pc}
 *   @0x306e60 movwhs r11, #0x390b
 *   @0x306e64 addsmi lr, pc, #2
 *   @0x306e68 movwhs sp, #0x6b10
 *   @0x306e6c ands r9, r2, r1, lsl r3
 *   @0x306e70 smlatteq r11, r0, r0, r0
 *   @0x306e74 andeq r6, lr, lr, asr pc
 *   @0x306e78 andeq r9, r9, r12, asr #21
 *   @0x306e7c andeq r9, r9, r4, ror #17
 *   @0x306e80 andeq r9, r9, lr, ror r8
 *   @0x306e84 andeq r9, r9, r2, ror r8
 *   @0x306e88 andeq r9, r9, r12, ror #16
 *   @0x306e8c tstlt r3, r1, lsl r11
 *   @0x306e90 .word 0xf7ff4620
 *   @0x306e94 blls 0x786368 <b2_toiTime+0x2cec4>
 *   @0x306e98 ldmdblt r11, {r0, r1, r2, r5, r8, r9, r12, pc}
 *   @0x306e9c svceq #0xf1b8
 *   @0x306ea0 smlabthi r5, r0, r2, pc
 *   @0x306ea4 blhs 0x3b3a18 <error_g0017+0xc6bc>
 *   @0x306ea8 bge 0xcfb320 <b2_toiTime+0x5a1e7c>
 *   @0x306eac .word 0x21ac4630
 *   @0x306eb0 rfedb r9!
 *   @0x306eb4 .word 0xf8c49a27
 *   @0x306eb8 bhs 0x3070d0 <TT_New_Context+0x6ec8>
 *   @0x306ebc rscshi pc, r7, r0, asr #32
 *   @0x306ec0 eorvs r2, r1, r1, lsl #2
 *   @0x306ec4 andvs r9, r2, r6, lsl #18
 *   @0x306ec8 .word 0xf8c0684a
 *   @0x306ecc .word 0xf7ff20a4
 *   @0x306ed0 eorls pc, r7, r7, asr #26
 *   @0x306ed4 .word 0xf1b8b930
 *   @0x306ed8 .word 0xf2c00f00
 *   @0x306edc smlattlt pc, r8, r0, r8
 *   @0x306ee0 .word 0x93272306
 *   @0x306ee4 blhs 0x32db88
 *   @0x306ee8 sbcshi pc, lr, r0, asr #32
 *   @0x306eec .word 0x5084f8d4
 *   @0x306ef0 strhtlo pc, [r0], #-133
 *   @0x306ef4 .word 0xf0002b00
 *   @0x306ef8 stmvs r3!, {r0, r2, r4, r7, pc}
 *   @0x306efc .word 0xf0436067
 *   @0x306f00 adcvs r0, r2, r2, lsl r2
 *   @0x306f04 strhtne pc, [r4], #-133
 *   @0x306f08 strhths pc, [r6], #-133
 *   @0x306f0c svclt #0x44291
 *   @0x306f10 tsteq r6, #67
 *   @0x306f14 .word 0xf89560a3
 *   @0x306f18 tstlt r11, r6, asr r0
 *   @0x306f1c .word 0xf04368e3
 *   @0x306f20 rscvs r0, r3, r1, lsl #6
 *   @0x306f24 ldrhlo pc, [r10], #-133
 *   @0x306f28 svcvc #0x48f5b3
 *   @0x306f2c stmvs r3!, {r0, r1, r8, r9, r12, lr, pc} ^
 *   @0x306f30 movweq pc, #0x2043
 *   @0x306f34 andhs r6, r0, #227
 *   @0x306f38 andls r2, r0, #67108864
 *   @0x306f3c ldmibeq r12, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x306f40 .word 0xf8cd4630
 *   @0x306f44 tsths r0, r4
 *   @0x306f48 .word 0xf8a1f7e1
 *   @0x306f4c strmi r9, [r7], -r7, lsr #22
 *   @0x306f50 blhs 0x31f7d8
 *   @0x306f54 adchi pc, r8, r0, asr #32
 *   @0x306f58 mvnvs r2, r1, lsl #6
 *   @0x306f5c strhtlo pc, [r4], #-133
 *   @0x306f60 rfeia r5!
 *   @0x306f64 rfeia r5!
 *   @0x306f68 ldrmi r3, [r3], #-96
 *   @0x306f6c rfeia r5!
 *   @0x306f70 subhs r0, r8, #74
 *   @0x306f74 rsbsvs r0, r8, r0, lsl #3
 *   @0x306f78 strhhi pc, [r12], #-133
 *   @0x306f7c strhge pc, [lr], #-133
 *   @0x306f80 svceq #0xf1b8
 *   @0x306f84 .word 0xf04fbf08
 *   @0x306f88 .word 0xf1ba0848
 *   @0x306f8c svclt #0x80f00
 *   @0x306f90 beq 0x15430d4 <b2_toiTime+0xde9c30>
 *   @0x306f94 .word 0xf7dd4641
 *   @0x306f98 .word 0x3020fed1
 *   @0x306f9c teqeq pc, #32
 *   @0x306fa0 rfeia r5!
 *   @0x306fa4 orreq r0, r0, r0, rrx
 *   @0x306fa8 stcle p2, c4, [r5, #-524]
 *   @0x306fac strdhs r6, r7, [r8, #-8]
 *   @0x306fb0 .word 0xf7dd4642
 *   @0x306fb4 rsbsvs pc, r8, r3, asr #29
 *   @0x306fb8 usub16mi r6, r1, r8
 *   @0x306fbc .word 0xf7dd2248
 *   @0x306fc0 movwhs pc, #0xebd
 *   @0x306fc4 .word 0xf0203020
 *   @0x306fc8 adcsvs r0, r8, pc, lsr r0
 *   @0x306fcc .word 0xf8ad932c
 *   @0x306fd0 .word 0xf8ad30b4
 *   @0x306fd4 strtls r3, [r11], #-182
 *   @0x306fd8 .word 0x305cf895
 *   @0x306fdc .word 0xd1042b4d
 *   @0x306fe0 .word 0x932c4b38
 *   @0x306fe4 .word 0xf8ad2301
 *   @0x306fe8 ldmdami r7!, {r2, r4, r5, r7, r12, sp}
 *   @0x306fec bge 0xdcf3f4 <b2_toiTime+0x675f50>
 *   @0x306ff0 ldrbtmi r4, [r8], #-1547
 *   @0x306ff4 .word 0xf7e13018
 *   @0x306ff8 .word 0x9027f9be
 *   @0x306ffc cmple r3, r0, lsl #16
 *   @0x307000 tstlt r3, r3, ror #20
 *   @0x307004 ldmdavs r11, {r0, r1, r5, r7, r9, r11, sp, lr}
 *   @0x307008 .word 0xf89565e3
 *   @0x30700c .word 0xf8952069
 *   @0x307010 addsmi r3, r10, #104
 *   @0x307014 bne 0xff7fbc34 <b2_toiTime+0xffffffffff0a2790>
 *   @0x307018 .word 0x61233302
 *   @0x30701c stmvs pc!, {r0, r1, r3, r5, r6, r8, r9, r10, r11, sp, lr}
 *   @0x307020 movwle r4, #0x22bb
 *   @0x307024 .word 0x93272303
 *   @0x307028 bne 0x2ff128 <TT_RunIns+0x2334>
 *   @0x30702c ldclne p6, c4, [r9], #-192
 *   @0x307030 .word 0xf7e0464a
 *   @0x307034 .word 0xf8c5f878
 *   @0x307038 .word 0xf8dd00a8
 *   @0x30703c .word 0xf1b8809c
 *   @0x307040 teqle r1, r0, lsl #30
 *   @0x307044 ldrtmi r6, [r10], -r11, ror #30
 *   @0x307048 .word 0x10a0f8d5
 *   @0x30704c .word 0xf5af4419
 *   @0x307050 .word 0xf8d5eab6
 *   @0x307054 .word 0xf80330a8
 *   @0x307058 .word 0xf8d58007
 *   @0x30705c strbmi r8, [r0], -r8, lsr #1
 *   @0x307060 b 0x1dc4724 <b2_toiTime+0x166b280>
 *   @0x307064 movweq lr, #0x88d
 *   @0x307068 ldrtmi r2, [r10], -r1, lsl #2
 *   @0x30706c ldrtmi r1, [r0], -r3, asr #24
 *   @0x307070 .word 0xf80df7e1
 *   @0x307074 adceq pc, r8, r5, asr #17
 *   @0x307078 stmiblt r11!, {r0, r1, r2, r5, r8, r9, r11, r12, pc}
 *   @0x30707c .word 0x61604b13
 *   @0x307080 .word 0x61a3447b
 *   @0x307084 .word 0xf01368e3
 *   @0x307088 .word 0xf0030f02
 *   @0x30708c andle r0, r6, r1, lsl #6
 *   @0x307090 blmi 0x6f34e4 <g_SWFvertbuff+0x2041c>
 *   @0x307094 and r4, r5, r11, ror r4
 *   @0x307098 ldrbtmi r4, [r11], #-2830
 *   @0x30709c teqlt r3, r2
 *   @0x3070a0 ldrbtmi r4, [r11], #-2829
 *   @0x3070a4 and r6, r2, r3, lsr #3
 *   @0x3070a8 .word 0xf7ff4620
 *   @0x3070ac stmdbls r10, {r2, r6, r10, r11, r12, sp, lr, pc}
 *   @0x3070b0 stmdals r7!, {r0, r2, r4, r5, r9, r11, r12, pc}
 *   @0x3070b4 addsmi r6, r10, #720896
 *   @0x3070b8 .word 0xf5afd001
 *   @0x3070bc eorslt lr, r7, r12, lsl #21
 *   @0x3070c0 svchi #0xf0e8bd
 *   @0x3070c4 cmnvs r2, lr, ror #26
 *   @0x3070c8 ldrdeq r3, r4, [lr], -r6
 *   @0x3070cc andeq r7, r8, r12, lsl #15
 *   @0x3070d0 muleq r8, r4, lr
 *   @0x3070d4 andeq r7, r8, r0, asr r7
 *   @0x3070d8 andeq r7, r8, pc, lsr #14
 *   @0x3070dc ldrblt r2, [r0, #-0x301]!
 *   @0x3070e0 andle r4, lr, #805306376
 *   @0x3070e4 addeq lr, r3, #1024
 *   @0x3070e8 .word 0xb144461c
 *   @0x3070ec .word 0xf8526815
 *   @0x3070f0 adcsmi r6, r5, #4, #26
 *   @0x3070f4 stm r2, {r0, r1, r9, r11, r12, lr, pc}
 *   @0x3070f8 .word 0x3c010060
 *   @0x3070fc movwlo lr, #0x17f5
 *   @0x307100 ldcllt p7, c14, [r0, #-952]!
 *   @0x307104 svcmi #0xf0e92d
 *   @0x307108 stmdavs r3, {r1, r2, r9, r10, lr}
 *   @0x30710c strmi r11, [sp], -r7, lsl #1
 *   @0x307110 blhs 0x358b5c
 *   @0x307114 sxtab16mi sp, r11, r7
 *   @0x307118 stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30711c ldrmi r6, [r8, #0x833]
 *   @0x307120 ldrbmi sp, [r12], r3, lsr #4
 *   @0x307124 .word 0xf1ba46c2
 *   @0x307128 andsle r0, r9, r0, lsl #30
 *   @0x30712c .word 0x200cf8dc
 *   @0x307130 stmdblo r12, {r2, r3, r4, r6, r11, r12, sp, lr, pc}
 *   @0x307134 ble 0x7d7ba4 <b2_toiTime+0x7e700>
 *   @0x307138 ldreq pc, [r8, -r12, lsl #2]
 *   @0x30713c .word 0xf10cac03
 *   @0x307140 .word 0xf10a030c
 *   @0x307144 ldm r7, {r0, r1, r2, r3, r4, r5, r6, r7, r9, r11, r12, sp}
 *   @0x307148 stm r4, {r0, r1, r2}
 *   @0x30714c ldm r3, {r0, r1, r2}
 *   @0x307150 stm r7, {r0, r1, r2}
 *   @0x307154 ldm r4, {r0, r1, r2}
 *   @0x307158 stm r3, {r0, r1, r2}
 *   @0x30715c strb r0, [r2, r7]!
 *   @0x307160 stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x307164 bleq 0x643598 <g_SWFaavertbuff+0x704d0>
 *   @0x307168 .word 0xf8d5e7d8
 *   @0x30716c strhs r10, [r0, -r0]
 *   @0x307170 .word 0xf04f2401
 *   @0x307174 ldrtmi r0, [r11], -r12, lsl #16
 *   @0x307178 addsmi r6, r4, #3276800
 *   @0x30717c blx 0x53ba3e <obj_has_event+0xece>
 *   @0x307180 stmdapl r9!, {r2, r8, r12, sp, lr, pc} ^
 *   @0x307184 smlabteq r1, r10, r11, lr
 *   @0x307188 .word 0xdc034549
 *   @0x30718c addmi r1, r12, #1296
 *   @0x307190 ldrmi sp, [r4], -r2, lsr #2
 *   @0x307194 blx 0x505dbe <SrcVerts+0x62e02>
 *   @0x307198 .word 0xf04f4639
 *   @0x30719c bl 0x44a9a4 <g_RomDisk+0x53184>
 *   @0x3071a0 adcmi r0, r1, #11
 *   @0x3071a4 andeq pc, r12, r0, lsl #2
 *   @0x3071a8 .word 0xf850d206
 *   @0x3071ac mrslo r2, apsr
 *   @0x3071b0 .word 0x3c0cf840
 *   @0x3071b4 .word 0xe7f44496
 *   @0x3071b8 movwls r4, #0x1670
 *   @0x3071bc stc p0, c15, [r8, #68]!
 *   @0x3071c0 .word 0xf8459b01
 *   @0x3071c4 ldmdavs r2!, {r0, r1, r3}
 *   @0x3071c8 addsmi r3, r4, #4096
 *   @0x3071cc stclne p2, c13, [r7], #-16
 *   @0x3071d0 .word 0xf207fb08
 *   @0x3071d4 andge pc, r2, r5, asr r8
 *   @0x3071d8 strb r3, [sp, r1, lsl #8]
 *   @0x3071dc strtmi r2, [r11], -r1, lsl #8
 *   @0x3071e0 .word 0xf04f4627
 *   @0x3071e4 ldmdavs r2!, {r2, r3, r11}
 *   @0x3071e8 andle r4, r11, #1879048201
 *   @0x3071ec svchs #0xcf853
 *   @0x3071f0 blx 0x5336c2 <g_pPNGFile+0x6f6>
 *   @0x3071f4 strlo r5, [r1], #-3076
 *   @0x3071f8 muleq r7, r3, r8
 *   @0x3071fc andeq lr, r7, r12, lsl #17
 *   @0x307200 ldrb r3, [r0, r1, lsl #14]!
 *   @0x307204 andlt r6, r7, r4, lsr r0
 *   @0x307208 svchi #0xf0e8bd
 *   @0x30720c .word 0xf500b119
 *   @0x307210 ldmibvs r11, {r3, r5, r6, r7, r8, r9, r12, lr} ^
 *   @0x307214 tstlt r2, r11
 *   @0x307218 ldrsbtlo pc, [r12], #128
 *   @0x30721c .word 0x47706013
 *   @0x307220 .word 0xf8c0b530
 *   @0x307224 stmibvs r12, {r2, r3, r4, r5, r7, r9, r11, r12} ^
 *   @0x307228 bmi 0xff045530 <b2_toiTime+0xfffffffffe8ec08c>
 *   @0x30722c subvs r6, r3, r11, asr #21
 *   @0x307230 addvs r6, r3, r11, lsl #22
 *   @0x307234 .word 0x53e2f501
 *   @0x307238 ldrdvs r6, r7, [r2], #138
 *   @0x30723c .word 0x6103691b
 *   @0x307240 cdpne p9, #0x9, c6, c3, c10, #0x4
 *   @0x307244 stmdale r2, {r0, r8, r9, r11, sp}
 *   @0x307248 bhs 0x38fe54 <_zip_nerr_str+0x594>
 *   @0x30724c bhs 0x43f25c <g_RomDisk+0x47a3c>
 *   @0x307250 movweq pc, #0x4f
 *   @0x307254 streq pc, [r2, #-0x22]
 *   @0x307258 .word 0xf043bf08
 *   @0x30725c stchs p3, c0, [r1, #-8]
 *   @0x307260 bhs 0x3bb27c <error_g0017+0x13f20>
 *   @0x307264 .word 0xf043bf14
 *   @0x307268 .word 0xf0430304
 *   @0x30726c bvs 0x1587ea4 <b2_toiTime+0xe2ea00>
 *   @0x307270 ldrsbhs pc, [r8, #-130]!
 *   @0x307274 tstlt r2, r2, lsl sp
 *   @0x307278 streq pc, [r4], #-68
 *   @0x30727c .word 0xf044e001
 *   @0x307280 .word 0xf8c0040c
 *   @0x307284 .word 0xf8c04ab4
 *   @0x307288 strhhs r3, [r0], -r8
 *   @0x30728c .word 0xf8c0bd30
 *   @0x307290 stmibvs r11, {r2, r3, r4, r5, r7, r9, r11, r12} ^
 *   @0x307294 blo 0xff04559c <b2_toiTime+0xfffffffffe8ec0f8>
 *   @0x307298 subvs r6, r3, r11, lsl #17
 *   @0x30729c sbcvs r6, r3, r11, asr #17
 *   @0x3072a0 addvs r6, r3, r11, lsl #18
 *   @0x3072a4 .word 0x6103694b
 *   @0x3072a8 ldrbmi r2, [r0, -r0]!
 *   @0x3072ac andlo pc, r0, #132096
 *   @0x3072b0 rscvc lr, r2, pc, asr #20
 *   @0x3072b4 andmi pc, r0, r0, lsl #10
 *   @0x3072b8 .word 0xf142181b
 *   @0x3072bc b 0x16c7ac4 <b2_toiTime+0xf6e620>
 *   @0x3072c0 b 0x1317314 <b2_toiTime+0xbbde70>
 *   @0x3072c4 ldrbmi r4, [r0, -r2]!
 *   @0x3072c8 strths r11, [r8], #-1520
 *   @0x3072cc strhs r6, [r1, #-0x982]
 *   @0x3072d0 strhs r6, [r2], -r3, asr #19
 *   @0x3072d4 strhs r6, [r0, -r8, asr #16]
 *   @0x3072d8 strlo pc, [r2], #-2820
 *   @0x3072dc andlo r6, r8, r10, lsl #17
 *   @0x3072e0 adcmi r3, r3, #268435456
 *   @0x3072e4 ldmdbvs r9, {r1, r2, r4, r9, r12, lr, pc}
 *   @0x3072e8 .word 0x1c08f840
 *   @0x3072ec .word 0xf8406959
 *   @0x3072f0 ldmdahi r9, {r2, r10, r11, r12}
 *   @0x3072f4 svceq #0x1f011
 *   @0x3072f8 .word 0xf802d002
 *   @0x3072fc and r7, r5, r1, lsl #24
 *   @0x307300 svclt #0x4c0789
 *   @0x307304 .word 0x6c01f802
 *   @0x307308 .word 0x5c01f802
 *   @0x30730c andlo r3, r8, r8, lsr #6
 *   @0x307310 strb r3, [r6, r1, lsl #4]!
 *   @0x307314 .word 0xf7ffbdf0
 *   @0x307318 tstlt r9, r3, lsl #31
 *   @0x30731c .word 0x53e8f500
 *   @0x307320 ldrdvs r6, r7, [r11], -r11
 *   @0x307324 .word 0xf8d0b112
 *   @0x307328 ldrshvs r3, [r3], -r12
 *   @0x30732c tstlt r9, r0, ror r7
 *   @0x307330 tstpl r3, #0, #10
 *   @0x307334 andvs r6, r11, r11, asr r10
 *   @0x307338 .word 0xf8d0b112
 *   @0x30733c ldrshvs r3, [r3], -r12
 *   @0x307340 push {r4, r5, r6, r8, r9, r10, lr}
 *   @0x307344 vrecps.f32 q10, q8, q8
 *   @0x307348 blx 0x41c462 <g_RomDisk+0x24c42>
 *   @0x30734c strhs r0, [r12, -r3, lsl #6]!
 *   @0x307350 .word 0xf103b087
 *   @0x307354 .word 0x33280a2c
 *   @0x307358 .word 0x6008f8da
 *   @0x30735c blx 0x4e14d2 <SrcVerts+0x3e516>
 *   @0x307360 teqlt r1, r3, lsl #14
 *   @0x307364 stmdbeq r12, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x307368 .word 0x2101fb09
 *   @0x30736c .word 0x9c0cf851
 *   @0x307370 strmi lr, [r9], r0
 *   @0x307374 blo 0xff2456bc <b2_toiTime+0xfffffffffeaec218>
 *   @0x307378 rsbsvc pc, r0, #268435460
 *   @0x30737c blhs 0x321df0
 *   @0x307380 svclt #0xb84698
 *   @0x307384 ldmeq pc!, {r0, r1, r8, r12, sp, lr, pc} ^
 *   @0x307388 stmdahs r8!, {r0, r1, r2, r3, r4, r6, r9, r11, sp, lr, pc}
 *   @0x30738c .word 0xf04fbf08
 *   @0x307390 cmpmi r3, #65536
 *   @0x307394 .word 0xf203bf48
 *   @0x307398 sbcsne r7, r11, #-67108861
 *   @0x30739c .word 0xf1069304
 *   @0x3073a0 movwls r0, #0x232c
 *   @0x3073a4 .word 0xf1a4461c
 *   @0x3073a8 movwls r0, #0x132c
 *   @0x3073ac rsble r4, r5, #-1342177269
 *   @0x3073b0 stchs p9, c15, [r11], #-80
 *   @0x3073b4 ldrsblo pc, [r8], -r10
 *   @0x3073b8 .word 0xd15d429a
 *   @0x3073bc .word 0xf1a59d02
 *   @0x3073c0 movwls r0, #0x332c
 *   @0x3073c4 subsle r4, r7, #-1342177269
 *   @0x3073c8 stcne p9, c15, [r11], #-80
 *   @0x3073cc stchs p9, c15, [r11], #-84
 *   @0x3073d0 stclo p8, c15, [r10], #-208
 *   @0x3073d4 rfeda r5!
 *   @0x3073d8 andls r0, r5, #10752
 *   @0x3073dc andslt sp, r11, #-2147483630
 *   @0x3073e0 addsmi r11, r8, #0, #4
 *   @0x3073e4 rfedb r4!
 *   @0x3073e8 rfedb r5!
 *   @0x3073ec rfedb r4!
 *   @0x3073f0 rfedb r5!
 *   @0x3073f4 strbmi r1, [r3, #0xc24]!
 *   @0x3073f8 .word 0x46e3bfb8
 *   @0x3073fc svclt #0xd44291
 *   @0x307400 bleq 0x382334 <_ZTS13C_UTF16String+0x193e0>
 *   @0x307404 bleq 0x3c2338 <error_g0017+0x1afdc>
 *   @0x307408 blle 0xfd8b1c <b2_toiTime+0x87f678>
 *   @0x30740c .word 0xf1b91ac3
 *   @0x307410 andsle r0, r6, r0, lsl #30
 *   @0x307414 .word 0x46490298
 *   @0x307418 ldcl p0, c15, [r10], #-68
 *   @0x30741c tstvc r0, #536870916
 *   @0x307420 addvs pc, r0, r0, lsr #11
 *   @0x307424 .word 0xdc084298
 *   @0x307428 stcle p8, c2, [r9, #-0]
 *   @0x30742c .word 0xf6404340
 *   @0x307430 .word 0xf01131b8
 *   @0x307434 strmi lr, [r3], -lr, ror #24
 *   @0x307438 vst4.8 {d30, d31, d0, d1}, [pc], r3
 *   @0x30743c strd r4, r5, [r0], -r10
 *   @0x307440 stmdals r4, {r0, r2, r8, r9, r11, r12, pc}
 *   @0x307444 movwls r4, #0x659
 *   @0x307448 stcl p0, c15, [r2], #-68
 *   @0x30744c .word 0xf8549b00
 *   @0x307450 ldrmi r2, [r8], #-3088
 *   @0x307454 ble 0x417e9c <g_RomDisk+0x2067c>
 *   @0x307458 .word 0xf8449b03
 *   @0x30745c .word 0xf8440c10
 *   @0x307460 .word 0xf8553c18
 *   @0x307464 addsmi r2, r0, #16, #24
 *   @0x307468 blls 0x37dc80 <_ZTS13C_UTF16String+0x14d2c>
 *   @0x30746c .word 0x0c10f845
 *   @0x307470 .word 0x3c18f845
 *   @0x307474 str r3, [r2, r12, lsr #10]!
 *   @0x307478 ldr r3, [r4, r12, lsr #8]
 *   @0x30747c adcsmi r2, lr, #0, #2
 *   @0x307480 ldmdbvs r3!, {r0, r3, r9, r12, lr, pc} ^
 *   @0x307484 ldmdbvs r10, {r0, r1, r3, r5, r8, r12, sp, pc} ^
 *   @0x307488 strhle r4, [r2], -r2
 *   @0x30748c ldmdbvs r11, {r0, r4, r5, r6, r8, sp, lr} ^
 *   @0x307490 .word 0x362c61b3
 *   @0x307494 strdlt lr, pc, [r7], -r3
 *   @0x307498 svchi #0xf0e8bd
 *   @0x30749c stmdavs sp, {r4, r5, r8, r10, r12, sp, pc} ^
 *   @0x3074a0 bne 0xff2457a8 <b2_toiTime+0xfffffffffeaec304>
 *   @0x3074a4 .word 0xf8c069ca
 *   @0x3074a8 bvs 0xff5d1f80 <b2_toiTime+0xfffffffffee78adc>
 *   @0x3074ac blvs 0x5df5c0 <g_SWFaavertbuff+0xc4f8>
 *   @0x3074b0 .word 0xf5016083
 *   @0x3074b4 ldmdbvs r12, {r4, r8, r9, r12, lr} ^
 *   @0x3074b8 ldmibvs r11, {r2, r6, r7, sp, lr}
 *   @0x3074bc stmibvs r12, {r0, r1, r8, sp, lr}
 *   @0x3074c0 blhs 0x34ef54
 *   @0x3074c4 movwhs sp, #0x1802
 *   @0x3074c8 and r2, r2, r2, lsl #24
 *   @0x3074cc .word 0xf04f2c04
 *   @0x3074d0 svclt #0x80300
 *   @0x3074d4 movweq pc, #0x2043
 *   @0x3074d8 andle r2, r10, r1, lsl #24
 *   @0x3074dc andle r2, r8, r3, lsl #24
 *   @0x3074e0 stmvs r12!, {r1, r10, r11, sp} ^
 *   @0x3074e4 .word 0xf043bf14
 *   @0x3074e8 .word 0xf0430304
 *   @0x3074ec strbeq r0, [r4, r12, lsl #6]!
 *   @0x3074f0 .word 0xf042d501
 *   @0x3074f4 bvs 0x1547d00 <b2_toiTime+0xdee85c>
 *   @0x3074f8 ldrsbne pc, [r8, #-129]!
 *   @0x3074fc stmdblt r9, {r0, r3, r8, r10, r11, r12, sp, lr}
 *   @0x307500 andeq pc, r8, #66
 *   @0x307504 bhs 0xff04580c <b2_toiTime+0xfffffffffe8ec368>
 *   @0x307508 blo 0xff145810 <b2_toiTime+0xfffffffffe9ec36c>
 *   @0x30750c ldclt p0, c2, [r0, #-0]!
 *   @0x307510 subshs r4, r3, #3145728
 *   @0x307514 orrvs pc, r3, r0, asr #4
 *   @0x307518 andshs r6, lr, #194
 *   @0x30751c andhs r6, r0, r2, lsl #2
 *   @0x307520 ldrvc r2, [r8, #-0x201]
 *   @0x307524 vst3.16 {d23, d25, d27}, [pc:64], r10
 *   @0x307528 addsvs r7, r9, #-1610612721
 *   @0x30752c vst4.32 {d22, d24, d26, d28}, [pc:64], r10
 *   @0x307530 cmpvs r8, #200, #4
 *   @0x307534 .word 0xf44f61da
 *   @0x307538 andsvs r7, r10, #-1610612729
 *   @0x30753c andsne pc, r3, #64, #4
 *   @0x307540 sbcsvs r6, r10, #-1610612731
 *   @0x307544 andsne pc, sp, #64, #12
 *   @0x307548 .word 0x4770631a
 *   @0x3087c0 mvnsmi lr, sp, lsr #18
 *   @0x3087c4 stmdahs r0, {r2, r9, r10, lr}
 *   @0x3087c8 stmdavs r7, {r1, r6, r12, lr, pc}
 *   @0x3087cc eorsle r2, pc, r0, lsl #30
 *   @0x3087d0 strbeq pc, [r8, #-0x100]
 *   @0x3087d4 stmdaeq r2, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x3087d8 .word 0xf8552600
 *   @0x3087dc .word 0xf8451c14
 *   @0x3087e0 adcmi r6, r9, #28, #24
 *   @0x3087e4 .word 0x6c18f845
 *   @0x3087e8 ldrtmi sp, [r8], -r4
 *   @0x3087ec stc2 p7, c15, [r3, #888]!
 *   @0x3087f0 .word 0x6c14f845
 *   @0x3087f4 .word 0x1c08f855
 *   @0x3087f8 movtvc pc, #0x6505
 *   @0x3087fc .word 0x6c10f845
 *   @0x308800 .word 0xf8454299
 *   @0x308804 andle r6, r4, r12, lsl #24
 *   @0x308808 .word 0xf7de4638
 *   @0x30880c .word 0xf845fd94
 *   @0x308810 .word 0xf1b86c08
 *   @0x308814 vadd.i8 d0, d5, d1
 *   @0x308818 bicsle r5, lr, r4, asr #10
 *   @0x30881c .word 0xf6046aa1
 *   @0x308820 addsmi r2, r9, #200, #6
 *   @0x308824 ldrtmi sp, [r8], -r4
 *   @0x308828 stc2 p7, c15, [r5, #888]
 *   @0x30882c eorhi pc, r8, r4, asr #17
 *   @0x308830 .word 0xf60469e1
 *   @0x308834 strhs r2, [r0, #-0x3e8]
 *   @0x308838 addsmi r6, r9, #1342177282
 *   @0x30883c andle r6, r3, r5, ror #4
 *   @0x308840 .word 0xf7de4638
 *   @0x308844 mvnvs pc, r8, ror sp
 *   @0x308848 .word 0x61632300
 *   @0x30884c eorvs r6, r3, r3, lsr #3
 *   @0x308850 ldrhhi lr, [r0, #141]!
 *   @0x308854 mvnsmi lr, sp, lsr #18
 *   @0x308858 .word 0xb3204606
 *   @0x30885c strhs r6, [r0], #-2051
 *   @0x308860 strtmi r4, [r0], r5, lsl #12
 *   @0x308864 stmdbvs r8!, {r0, r1, r2, r3, r4, r6, r9, r10, r11, sp, lr}
 *   @0x308868 bmi 0x734eb0 <g_SWFvertbuff+0x61de8>
 *   @0x30886c ldrbtmi r4, [r10], #-2832
 *   @0x308870 ldrbtmi r6, [r11], #-2066
 *   @0x308874 stmpl r2!, {r0, r1, r3, r4, r11, sp, lr}
 *   @0x308878 .word 0xf8536852
 *   @0x30887c ldmdbvs r11, {r1, r5, r12, sp}
 *   @0x308880 ldrmi r11, [r8, r3, lsl #2]
 *   @0x308884 stmdbvs r9!, {r3, r4, r5, r9, r10, lr}
 *   @0x308888 ldc2l p7, c15, [r5, #-888]
 *   @0x30888c andshi pc, r0, r5, asr #17
 *   @0x308890 strlo r3, [r4, #-0x404]
 *   @0x308894 svcvc #0xa8f5b4
 *   @0x308898 ldrtmi sp, [r8], -r5, ror #3
 *   @0x30889c pop {r0, r4, r5, r9, r10, lr}
 *   @0x3088a0 .word 0xf7de41f0
 *   @0x3088a4 pop {r3, r6, r8, r10, r11, r12, sp, pc}
 *   @0x3088a8 svclt #0x81f0
 *   @0x3088ac andeq r9, lr, r10, ror r3
 *   @0x3088b0 andeq r9, lr, r10, ror r3
 *   @0x3088b4 ldrbtmi r4, [r8], #-2049
 *   @0x3088b8 stcllt p7, c15, [r11, #-880]
 *   @0x3088bc strheq r1, [lr], -r6
 *   @0x3088c0 movtpl pc, #0x4240
 *   @0x3088c4 movweq pc, #0x1b03
 *   @0x3088c8 svcmi #0xf0e92d
 *   @0x3088cc .word 0x3328b08f
 *   @0x3088d0 ldcne p6, c4, [lr, #-20]
 *   @0x3088d4 strls r9, [r4], -r5, lsl #2
 *   @0x3088d8 ldmvs r12, {r1, r2, r8, r9, r12, pc} ^
 *   @0x3088dc .word 0xf7ff685e
 *   @0x3088e0 andls pc, r9, r11, lsr #17
 *   @0x3088e4 .word 0xf0402800
 *   @0x3088e8 .word 0x232c822f
 *   @0x3088ec strmi pc, [r6], -r3, lsl #22
 *   @0x3088f0 .word 0xf1a318e3
 *   @0x3088f4 addsmi r0, r6, #44, #4
 *   @0x3088f8 .word 0xf853d920
 *   @0x3088fc .word 0xf8532c08
 *   @0x308900 .word 0xf8131c04
 *   @0x308904 ldmdahi r0, {r2, r3, r5, r10, r11, lr}
 *   @0x308908 streq pc, [r1], #-36
 *   @0x30890c stcmi p8, c15, [r12], #-12
 *   @0x308910 andeq pc, r3, r0
 *   @0x308914 andle r4, pc, r10, lsl #5
 *   @0x308918 ldmdahi r4, {r1, r4, r9, r11, sp, lr}
 *   @0x30891c streq pc, [r3], #-4
 *   @0x308920 mrslt r11, spsr
 *   @0x308924 smlabble r5, r10, r2, r4
 *   @0x308928 stceq p8, c15, [r12], #-76
 *   @0x30892c andeq pc, r1, r0, asr #32
 *   @0x308930 stceq p8, c15, [r12], #-12
 *   @0x308934 strb r4, [sp, r0, lsr #12]!
 *   @0x308938 ldrb r3, [r10, r12, lsr #6]
 *   @0x30893c svcls #0x69e04
 *   @0x308940 ldmdavs r10!, {r0, r1, r4, r5, r7, r8, r11, sp, lr} ^
 *   @0x308944 movwls r9, #0xaf05
 *   @0x308948 blo 0xff246ca4 <b2_toiTime+0xfffffffffeaed800>
 *   @0x30894c bvs 0xfeaa2c24 <b2_toiTime+0xfffffffffe349780>
 *   @0x308950 stmdavs r9!, {r0, r1, r2, r3, r8, r11, r12, sp, pc} ^
 *   @0x308954 stmvs r9!, {sp, lr, pc} ^
 *   @0x308958 bleq 0xe44a9c <b2_toiTime+0x6eb5f8>
 *   @0x30895c blx 0x5d0c66 <g_SWFlineaavertbuff+0x7db9e>
 *   @0x308960 .word 0xf7dc4b02
 *   @0x308964 vaddne.f32 s30, s7, s17
 *   @0x308968 streq pc, [r12, -r4, lsl #2]!
 *   @0x30896c .word 0x33ffbfb8
 *   @0x308970 beq 0x584ab4 <g_SWFlineaavertbuff+0x319ec>
 *   @0x308974 stmdaeq r7, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x308978 movwls r1, #0xb21b
 *   @0x30897c smladxls r8, r11, r6, r4
 *   @0x308980 .word 0xf1a39007
 *   @0x308984 ldrbmi r0, [lr, #0xe2c]
 *   @0x308988 .word 0xf913d257
 *   @0x30898c cdpls p12, #0x0, c2, c10, c11, #0x1
 *   @0x308990 ldrhle r4, [r0, #-34]
 *   @0x308994 strtmi r9, [r2], -r8, lsl #18
 *   @0x308998 suble r4, r12, #377487360
 *   @0x30899c suble r4, r7, r2, ror r5
 *   @0x3089a0 stceq p9, c15, [r11], #-76
 *   @0x3089a4 stcvs p9, c15, [r11], #-68
 *   @0x3089a8 strdle r4, r5, [r1, #-32]
 *   @0x3089ac stcgt p9, c15, [r10], #-196
 *   @0x3089b0 stceq p9, c15, [r10], #-204
 *   @0x3089b4 .word 0x0c00ebbc
 *   @0x3089b8 rfedb r3!
 *   @0x3089bc rfedb r1!
 *   @0x3089c0 rfeib r2!
 *   @0x3089c4 rfedb r3!
 *   @0x3089c8 ldrmi r0, [r1, #0xc24]!
 *   @0x3089cc strbmi r11, [lr], -r8, lsr #31
 *   @0x3089d0 svclt #0xd44287
 *   @0x3089d4 streq lr, [r7], -r6, asr #23
 *   @0x3089d8 streq lr, [r0], -r6, asr #23
 *   @0x3089dc adcsmi r9, lr, #11, #30
 *   @0x3089e0 .word 0xf853db26
 *   @0x3089e4 b 0x16cba2c <b2_toiTime+0xf72588>
 *   @0x3089e8 blx 0x58a922 <g_SWFlineaavertbuff+0x3785a>
 *   @0x3089ec strbmi pc, [pc, #-0x900]
 *   @0x3089f0 blx 0x53f22e <obj_has_event+0x46be>
 *   @0x3089f4 addmi pc, r7, #0
 *   @0x3089f8 .word 0xf853db03
 *   @0x3089fc adcsmi r0, r0, #12, #24
 *   @0x308a00 .word 0xf843da05
 *   @0x308a04 .word 0xf843cc10
 *   @0x308a08 .word 0xf8436c0c
 *   @0x308a0c ldmibvs r0, {r3, r4, r10, r11, sp} ^
 *   @0x308a10 .word 0xf900fb0a
 *   @0x308a14 ble 0x5d9f58 <g_SWFaavertbuff+0x6e90>
 *   @0x308a18 .word 0xf000fb08
 *   @0x308a1c blle 0x399440 <ft_adobe_glyph_list+0x8b1c>
 *   @0x308a20 adcsmi r6, r0, #16, #20
 *   @0x308a24 .word 0xf8c2da04
 *   @0x308a28 andsvs r12, r6, #28
 *   @0x308a2c ands pc, r4, r2, asr #17
 *   @0x308a30 .word 0x312c322c
 *   @0x308a34 .word 0x332ce7b0
 *   @0x308a38 strtmi lr, [r3], -r3, lsr #15
 *   @0x308a3c ldrbmi r2, [r11, #-0x700]
 *   @0x308a40 ldmdbvs r8, {r0, r1, r2, r4, r6, r9, r12, lr, pc} ^
 *   @0x308a44 subsle r2, r2, r0, lsl #16
 *   @0x308a48 addsmi r6, r9, #1064960
 *   @0x308a4c rfeib r0!
 *   @0x308a50 rfeib r3!
 *   @0x308a54 addsmi r2, r6, #2
 *   @0x308a58 ldmibvs r10, {r0, r3, r6, r8, r10, r11, r12, lr, pc} ^
 *   @0x308a5c ldrsbls pc, [r12], -sp
 *   @0x308a60 ble 0x1419f90 <b2_toiTime+0xcc0aec>
 *   @0x308a64 ldrbmi r4, [r10, #-0x622]
 *   @0x308a68 rfeib r2!
 *   @0x308a6c rfeib r1!
 *   @0x308a70 ldrbmi r10, [r1, #0x2]
 *   @0x308a74 addsmi sp, r1, #14592
 *   @0x308a78 .word 0xf8d2d037
 *   @0x308a7c .word 0xf1bee014
 *   @0x308a80 eorsle r0, r2, r0, lsl #30
 *   @0x308a84 ldrsbgt pc, [r4], -lr
 *   @0x308a88 .word 0xd12e4594
 *   @0x308a8c strhvs pc, [r2], -lr
 *   @0x308a90 strhhi pc, [r2], -r0
 *   @0x308a94 blle 0xd19fb4 <b2_toiTime+0x5c0b10>
 *   @0x308a98 smlabtle r1, r10, r5, r4
 *   @0x308a9c .word 0xd02445b0
 *   @0x308aa0 ldrsbvs pc, [r12], -r12
 *   @0x308aa4 ldrsbhi pc, [r12], -r1
 *   @0x308aa8 ldcle p5, c4, [lr, #-280]
 *   @0x308aac svceq #0x88ebb6
 *   @0x308ab0 .word 0xf8dcda1b
 *   @0x308ab4 .word 0xf04f6020
 *   @0x308ab8 blx 0x54aece <gp_ActiveMaskObjects+0x6206>
 *   @0x308abc bvs 0x6c6adc <g_SWFlinevertbuff+0x73a14>
 *   @0x308ac0 blle 0x6d9fe0 <g_SWFvertbuff+0x6f18>
 *   @0x308ac4 ldrbmi r4, [lr, #-0x626]
 *   @0x308ac8 .word 0xf8d6d20f
 *   @0x308acc strbmi r8, [r0, #0x14]!
 *   @0x308ad0 cmnvs r7, r2, lsl #2
 *   @0x308ad4 strh r6, [r3], -r0
 *   @0x308ad8 svclt #0x445f0
 *   @0x308adc .word 0x61b16177
 *   @0x308ae0 ldrb r3, [r0, r12, lsr #12]!
 *   @0x308ae4 .word 0x614f6147
 *   @0x308ae8 eorlo lr, r12, #1
 *   @0x308aec .word 0x332ce7bb
 *   @0x308af0 andhs lr, r0, r5, lsr #15
 *   @0x308af4 andsle r4, r1, #92, #10
 *   @0x308af8 .word 0xb16a6962
 *   @0x308afc adcmi r6, r3, #1359872
 *   @0x308b00 .word 0x6160d00a
 *   @0x308b04 ldmibvs r1, {r0, r1, r2, r8, r9, r11, r12, pc} ^
 *   @0x308b08 blle 0x3d9574 <error_g0017+0x32218>
 *   @0x308b0c bl 0xfefe32a0 <b2_toiTime+0xfffffffffe889dfc>
 *   @0x308b10 ble 0x34c91c
 *   @0x308b14 .word 0x61a36953
 *   @0x308b18 strb r3, [r11, r12, lsr #8]!
 *   @0x308b1c .word 0xf8d5682e
 *   @0x308b20 svcls #0x53abc
 *   @0x308b24 vst1.8 {d25, d26, d27}, [pc], r7
 *   @0x308b28 bls 0x49e6b4 <TimingData+0x469c>
 *   @0x308b2c strlo pc, [r7], -r6, lsl #22
 *   @0x308b30 ldmdavs r3, {r2, r8, r9, r10, r11, r12, pc} ^
 *   @0x308b34 ldmvs r12!, {r2, r3, r5, r9, sp}
 *   @0x308b38 blx 0x3963f2 <ft_adobe_glyph_list+0x5ace>
 *   @0x308b3c movwhs r4, #0x203
 *   @0x308b40 blls 0x460f34 <g_RomDisk+0x69714>
 *   @0x308b44 stmdblt r11, {r3, r9, r12, pc}
 *   @0x308b48 and r6, r0, sp, ror #16
 *   @0x308b4c strls r6, [r3, #-0x8ed]
 *   @0x308b50 .word 0x00ccf8d6
 *   @0x308b54 .word 0xf7dc9903
 *   @0x308b58 ldmdahs r0, {r0, r3, r4, r5, r6, r8, r11, r12, sp, lr, pc}
 *   @0x308b5c andshs sp, r0, r5, lsl #26
 *   @0x308b60 .word 0xf7dc9903
 *   @0x308b64 strmi pc, [r0], r8, lsr #19
 *   @0x308b68 .word 0xf8d6e03c
 *   @0x308b6c eors r8, r9, r12, asr #1
 *   @0x308b70 .word 0xf914272c
 *   @0x308b74 blx 0x4fbc2a <SrcVerts+0x58c6e>
 *   @0x308b78 svcls #0x4f003
 *   @0x308b7c stmdane r10, {r0, r3, r4, r5, r6, r8, r11, sp, lr}
 *   @0x308b80 mulls sp, r2, r9
 *   @0x308b84 eorsle r4, r12, r1, ror #11
 *   @0x308b88 stmdals r6, {r0, r8, r9, r12, sp}
 *   @0x308b8c blle 0xffed95a0 <b2_toiTime+0xffffffffff7800fc>
 *   @0x308b90 .word 0xd16c2d00
 *   @0x308b94 blge 0x6707b8 <g_SWFlinevertbuff+0x1d6f0>
 *   @0x308b98 stcne p9, c15, [r10], #-208
 *   @0x308b9c stchs p9, c15, [r11], #-80
 *   @0x308ba0 movwls r9, #0x1804
 *   @0x308ba4 strls r4, [r0, -r11, lsr #12]
 *   @0x308ba8 .word 0xf9e4f7ff
 *   @0x308bac cmple r12, r0, lsl #16
 *   @0x308bb0 eorhs r4, r12, #42991616
 *   @0x308bb4 .word 0xf5ad980d
 *   @0x308bb8 blls 0x683fb0 <g_SWFlinevertbuff+0x30ee8>
 *   @0x308bbc subsvs r9, lr, #49152
 *   @0x308bc0 .word 0xf814629e
 *   @0x308bc4 cmpvc r10, #11008
 *   @0x308bc8 stchs p8, c15, [r10], #-208
 *   @0x308bcc rfedb r4!
 *   @0x308bd0 stcls p12, c0, [sp, #-168]
 *   @0x308bd4 rfedb r10!
 *   @0x308bd8 rsbvs r9, r8, sp, lsl #22
 *   @0x308bdc addsvs r6, r10, r10, asr r8
 *   @0x308be0 .word 0x6c1cf844
 *   @0x308be4 strtlo r9, [r12], #-2052
 *   @0x308be8 .word 0x9020f8dd
 *   @0x308bec strteq pc, [r12], -r4, lsr #3
 *   @0x308bf0 strbmi r6, [lr, #-0x8c0]
 *   @0x308bf4 suble r9, r1, #6
 *   @0x308bf8 .word 0xf64f2300
 *   @0x308bfc ssub8mi r7, sp, pc
 *   @0x308c00 rfedb r4!
 *   @0x308c04 cdppl p12, #0x0, c12, c9, c10, #0x1
 *   @0x308c08 smlabteq r12, r1, r11, lr
 *   @0x308c0c svclt #0xb82900
 *   @0x308c10 strbmi r4, [r1, #-0x249]
 *   @0x308c14 ldrbmi sp, [r1, #-0xab8]
 *   @0x308c18 .word 0xf854dab6
 *   @0x308c1c andls r0, r5, r8, lsl r12
 *   @0x308c20 bvs 0x18f5828 <b2_toiTime+0x119c384>
 *   @0x308c24 ldrtmi r2, [r12], r0
 *   @0x308c28 .word 0xf8dc970b
 *   @0x308c2c .word 0xf1bbb014
 *   @0x308c30 andle r0, r12, r0, lsl #30
 *   @0x308c34 rfeib r11!
 *   @0x308c38 rfeib r0!
 *   @0x308c3c ldrbmi r7, [pc, #-0x2]
 *   @0x308c40 bl 0xff5f8b78 <b2_toiTime+0xfffffffffee9f6d4>
 *   @0x308c44 bl 0xff4c8c68 <b2_toiTime+0xfffffffffed6f7c4>
 *   @0x308c48 strbmi r0, [r0, #-0xb]
 *   @0x308c4c .word 0xf8dcda9c
 *   @0x308c50 svcls #0xbc010
 *   @0x308c54 strhle r4, [r8, #92]!
 *   @0x308c58 svclt #0xb84540
 *   @0x308c5c svclt #0xb8468a
 *   @0x308c60 .word 0xe7914615
 *   @0x308c64 ldrmi r4, [r5], -r10, lsl #13
 *   @0x308c68 andls lr, r9, lr, lsl #15
 *   @0x308c6c bvs 0x1e00e24 <b2_toiTime+0x16a7980>
 *   @0x308c70 .word 0x3c1cf844
 *   @0x308c74 tstvs lr, r11, lsr #21
 *   @0x308c78 ldr r6, [r3, lr, lsr #5]!
 *   @0x308c7c .word 0xf04f9e04
 *   @0x308c80 svcls #0x6082c
 *   @0x308c84 blx 0x52325a <SrcVerts+0x8029e>
 *   @0x308c88 ldrmi r3, [r10], -r7, lsl #16
 *   @0x308c8c andle r4, r8, #276824064
 *   @0x308c90 qsublt r6, r1, r1
 *   @0x308c94 stmdbvs r9, {r1, r3, r6, r7, sp, lr}
 *   @0x308c98 addmi r6, r1, #80, #20
 *   @0x308c9c eorlo sp, r12, #-2147483586
 *   @0x308ca0 .word 0xf04fe7f4
 *   @0x308ca4 .word 0xf04f0900
 *   @0x308ca8 strbmi r0, [r3, #-0xa01]
 *   @0x308cac bvs 0x197d5e4 <b2_toiTime+0x1224140>
 *   @0x308cb0 strtmi r2, [r5], -r0, lsl #8
 *   @0x308cb4 stmibvs pc, {r1, r3, r11, r12, sp, lr}
 *   @0x308cb8 svclt #0x4c07d2
 *   @0x308cbc strlo r3, [r1], #-1281
 *   @0x308cc0 ldmvs lr!, {r0, r1, r2, r5, r8, r12, sp, pc} ^
 *   @0x308cc4 svclt #0x181af6
 *   @0x308cc8 and r2, r0, r1, lsl #12
 *   @0x308ccc stmdbvs r8, {r1, r2, r3, r4, r5, r9, r10, lr} ^
 *   @0x308cd0 stmdblt r0, {r1, r2, r4, r5, r6, r7, r9, r12, sp, pc}
 *   @0x308cd4 ldmibvs r10, {r1, r2, r5, r8, r9, r12, sp, pc}
 *   @0x308cd8 ldmibvs r10, {r1, r2, r3, r8, r12, sp, pc} ^
 *   @0x308cdc .word 0xb1b24638
 *   @0x308ce0 strhvc pc, [r0], -r2
 *   @0x308ce4 strhlt pc, [r0], -r3
 *   @0x308ce8 strhgt pc, [r2], -r0
 *   @0x308cec bleq 0x603c10 <g_SWFaavertbuff+0x30b48>
 *   @0x308cf0 strhvc pc, [r2], -r1
 *   @0x308cf4 svceq #0xf1bb
 *   @0x308cf8 .word 0xf1cbbfb8
 *   @0x308cfc strbmi r0, [r7, #-0xb00]!
 *   @0x308d00 bl 0xff638c38 <b2_toiTime+0xfffffffffeedf794>
 *   @0x308d04 bl 0xff4ca928 <b2_toiTime+0xfffffffffed71484>
 *   @0x308d08 ldrbmi r0, [pc, #-0x70c]
 *   @0x308d0c stmvs r2, {r9, r11, r12, lr, pc} ^
 *   @0x308d10 bicsvs r11, r10, lr, lsr #2
 *   @0x308d14 .word 0xf0407b10
 *   @0x308d18 tstvc r0, #2
 *   @0x308d1c orrsvs lr, r10, r0
 *   @0x308d20 bvs 0x19a314c <b2_toiTime+0x1249ca8>
 *   @0x308d24 .word 0xd1c54291
 *   @0x308d28 .word 0xf883b915
 *   @0x308d2c and r9, r3, r12
 *   @0x308d30 blle 0x1997cc <_ZN9CInstanceC2Effiib+0x2f0>
 *   @0x308d34 andge pc, r12, r3, lsl #17
 *   @0x308d38 ldrsblt r6, [r10, -r10]
 *   @0x308d3c swplt r6, r10, [r10]
 *   @0x308d40 andsls pc, r12, r3, asr #17
 *   @0x308d44 ldr r3, [r0, r12, lsr #6]!
 *   @0x308d48 andlt r9, pc, r9, lsl #16
 *   @0x308d4c svchi #0xf0e8bd
 *   @0x308d50 svcmi #0xf0e92d
 *   @0x308d54 stcvs p0, c11, [r11, #532]
 *   @0x308d58 strhne pc, [r4], #-129
 *   @0x308d5c ldrsbpl pc, [r8, #-128]!
 *   @0x308d60 rsbsvc pc, r10, pc, asr #32
 *   @0x308d64 streq r8, [r9], #-2460
 *   @0x308d68 .word 0xf7dc9200
 *   @0x308d6c vadd.i8 d31, d16, d20
 *   @0x308d70 bls 0x311bb0 <af_shaper_get_elem+0x741e>
 *   @0x308d74 .word 0x46074298
 *   @0x308d78 addshi pc, r3, r0, asr #6
 *   @0x308d7c bhs 0x323630
 *   @0x308d80 ldrsblt pc, [r8], -r5
 *   @0x308d84 ldrsbge pc, [r12], -r5
 *   @0x308d88 .word 0xf8d59301
 *   @0x308d8c blvs 0xdece24 <b2_toiTime+0x693980>
 *   @0x308d90 .word 0xf8d56aae
 *   @0x308d94 blvs 0x1e68e4c <b2_toiTime+0x170f9a8>
 *   @0x308d98 strls r9, [r3, #-0x302]
 *   @0x308d9c ldreq sp, [r0], #-3333
 *   @0x308da0 .word 0xf7fe4639
 *   @0x308da4 strmi pc, [r5], -r3, lsl #21
 *   @0x308da8 vst4.8 {d30, d31, d0, d1}, [pc], r1
 *   @0x308dac strteq r0, [r4], #-1430
 *   @0x308db0 .word 0xf385fab5
 *   @0x308db4 svchs #0x80f5b4
 *   @0x308db8 .word 0xf44fbfb8
 *   @0x308dbc blx 0xff011fc4 <b2_toiTime+0xfffffffffe8b8b20>
 *   @0x308dc0 .word 0xf1c2f284
 *   @0x308dc4 bne 0xff7c96c4 <b2_toiTime+0xffffffffff070220>
 *   @0x308dc8 vstrle d2, [r2, #-180]
 *   @0x308dcc ldreq r9, [r3], #-2562
 *   @0x308dd0 strtmi lr, [r8], -r4
 *   @0x308dd4 .word 0xf7fe4621
 *   @0x308dd8 strmi pc, [r3], -r9, ror #20
 *   @0x308ddc andmi lr, r11, pc, asr #20
 *   @0x308de0 ble 0x3997f4 <ft_adobe_glyph_list+0x8ed0>
 *   @0x308de4 andmi lr, r10, pc, asr #20
 *   @0x308de8 bls 0x380f34 <_ZTS13C_UTF16String+0x17fe0>
 *   @0x308dec .word 0x4c02ea4f
 *   @0x308df0 ble 0xb1a384 <b2_toiTime+0x3c0ee0>
 *   @0x308df4 bleq 0x3c3d28 <error_g0017+0x1c9cc>
 *   @0x308df8 .word 0xf8cd4621
 *   @0x308dfc .word 0xf7dcc000
 *   @0x308e00 .word 0xf8ddf85a
 *   @0x308e04 .word 0xf1bbc000
 *   @0x308e08 .word 0xd10a0f00
 *   @0x308e0c strbtmi r9, [r0], -r1, lsl #22
 *   @0x308e10 bl 0xff3da69c <b2_toiTime+0xfffffffffec811f8>
 *   @0x308e14 .word 0xf7dc0a06
 *   @0x308e18 .word 0xf1baf84e
 *   @0x308e1c andsle r0, r1, r0, lsl #30
 *   @0x308e20 bne 0xd40ebc <b2_toiTime+0x5e7a18>
 *   @0x308e24 smlabteq r9, r10, r11, lr
 *   @0x308e28 .word 0xf7db465a
 *   @0x308e2c strmi pc, [r5], -r7, lsl #31
 *   @0x308e30 andmi lr, r10, pc, asr #20
 *   @0x308e34 bl 0xff000ecc <b2_toiTime+0xfffffffffe8a7a28>
 *   @0x308e38 blle 0xffcdca58 <b2_toiTime+0xffffffffff5835b4>
 *   @0x308e3c bl 0xfefef64c <b2_toiTime+0xfffffffffe8961a8>
 *   @0x308e40 ble 0xb9ca50 <b2_toiTime+0x4435ac>
 *   @0x308e44 ldrteq r9, [r0], #-2562
 *   @0x308e48 bl 0xff49a6d4 <b2_toiTime+0xfffffffffed41230>
 *   @0x308e4c .word 0xf7dc0902
 *   @0x308e50 .word 0xf1b9f832
 *   @0x308e54 andsle r0, r8, r0, lsl #30
 *   @0x308e58 bne 0xd2fa6c <b2_toiTime+0x5d65c8>
 *   @0x308e5c bl 0xff51a78c <b2_toiTime+0xfffffffffedc12e8>
 *   @0x308e60 .word 0xf7db0103
 *   @0x308e64 strmi pc, [r5], -r11, ror #30
 *   @0x308e68 andmi lr, r8, pc, asr #20
 *   @0x308e6c bne 0xd40e94 <b2_toiTime+0x5e79f0>
 *   @0x308e70 smlabteq r8, r9, r11, lr
 *   @0x308e74 .word 0xf7db4652
 *   @0x308e78 strmi pc, [r5], -r1, ror #30
 *   @0x308e7c andmi lr, r9, pc, asr #20
 *   @0x308e80 .word 0xf7dc4621
 *   @0x308e84 strtmi pc, [r8], #-2072
 *   @0x308e88 bls 0x400ea0 <g_RomDisk+0x9680>
 *   @0x308e8c qadd16mi r0, r1, r0
 *   @0x308e90 .word 0xf811f7dc
 *   @0x308e94 .word 0xf7dc4639
 *   @0x308e98 .word 0xf500f80e
 *   @0x308e9c strne r4, [r0], #-0
 *   @0x308ea0 andhs lr, r0, r0
 *   @0x308ea4 pop {r0, r2, r12, sp, pc}
 *   @0x308ea8 strdeq r8, r9, [r0], -r0
 *   @0x308eac svcmi #0xf0e92d
 *   @0x308eb0 strmi r11, [r7], -r1, lsr #1
 *   @0x308eb4 strmi r4, [r8], -sp, lsl #12
 *   @0x308eb8 andls r4, sp, #17825792
 *   @0x308ebc .word 0xf7fe9306
 *   @0x308ec0 andls pc, r9, r7, asr #22
 *   @0x308ec4 .word 0xf0402800
 *   @0x308ec8 .word 0x9c0683d9
 *   @0x308ecc blhs 0x363560 <_ZTS12CDS_Priority+0x55b8>
 *   @0x308ed0 blo 0xff04722c <b2_toiTime+0xfffffffffe8edd88>
 *   @0x308ed4 ldreq sp, [lr, -r1, lsl #2]
 *   @0x308ed8 ldrbeq sp, [r12, r6, lsl #10]
 *   @0x308edc .word 0xf8d5d504
 *   @0x308ee0 .word 0x07983ab4
 *   @0x308ee4 ands sp, r12, r9, lsl r4
 *   @0x308ee8 strtmi r9, [r8], -r6, lsl #24
 *   @0x308eec blvs 0x1c912f4 <b2_toiTime+0x1537e50>
 *   @0x308ef0 stc2 p7, c15, [r2, #1016]!
 *   @0x308ef4 stmdahs r0, {r2, r9, r10, lr}
 *   @0x308ef8 .word 0x83b9f040
 *   @0x308efc strtmi r9, [r8], -r6, lsl #22
 *   @0x308f00 .word 0xf1034631
 *   @0x308f04 qasxmi r0, r3, r8
 *   @0x308f08 blx 0xa06f08 <b2_toiTime+0x2ada64>
 *   @0x308f0c strtmi r4, [r1], -r8, lsr #12
 *   @0x308f10 rfeia r8!
 *   @0x308f14 rscle r2, r2, r0, lsl #16
 *   @0x308f18 strls lr, [r7, #-0x3ab]
 *   @0x308f1c bleq 0x345060
 *   @0x308f20 .word 0x9c06e0ad
 *   @0x308f24 .word 0x21014628
 *   @0x308f28 ldrpl pc, [r0], -r4, lsl #10
 *   @0x308f2c ldreq pc, [r4], #-262
 *   @0x308f30 stmvs r4!, {r0, r2, r10, r12, pc}
 *   @0x308f34 stc2 p7, c15, [r0, #1016]
 *   @0x308f38 .word 0xf0402800
 *   @0x308f3c qadd8mi r8, r8, r10
 *   @0x308f40 .word 0xf1064621
 *   @0x308f44 movwhs r0, #0x1220
 *   @0x308f48 .word 0xf9fbf7fe
 *   @0x308f4c .word 0x21014628
 *   @0x308f50 .word 0xf898f7ff
 *   @0x308f54 .word 0xf0402800
 *   @0x308f58 .word 0x9c06838c
 *   @0x308f5c ldmvs r11, {r0, r1, r5, r6, r9, r11, sp, lr}
 *   @0x308f60 andslo pc, r7, r3, lsr r8
 *   @0x308f64 ldrble r0, [r8], #1113
 *   @0x308f68 strmi pc, [r4, #0x8d5]
 *   @0x308f6c .word 0xf8d5222c
 *   @0x308f70 .word 0xf8d6357c
 *   @0x308f74 stmdals r6, {r2, r4, sp, pc}
 *   @0x308f78 andmi pc, r3, #2048
 *   @0x308f7c .word 0xf500342c
 *   @0x308f80 andls r5, r8, r3, lsl r0
 *   @0x308f84 bls 0x4ed7a8 <SrcVerts+0x4a7ec>
 *   @0x308f88 msreq APSR_nzcvqg, #164, #2
 *   @0x308f8c stmible r4, {r1, r3, r4, r7, r9, lr} ^
 *   @0x308f90 strhs r9, [r0, -r6, lsl #18]
 *   @0x308f94 .word 0x46bb46b8
 *   @0x308f98 smlawbhs r8, r8, r10, r6
 *   @0x308f9c cdp p0, #0x5, c15, c4, c15, #0x0
 *   @0x308fa0 .word 0xf7fe4651
 *   @0x308fa4 bls 0x5475b8 <gp_ActiveMaskObjects+0x28f0>
 *   @0x308fa8 ldrteq pc, [r12], -r2, lsl #2
 *   @0x308fac svclt #0xb42820
 *   @0x308fb0 .word 0xf04f4681
 *   @0x308fb4 stmdals r5, {r5, r8, r11}
 *   @0x308fb8 ldrsblo pc, [r8], #128
 *   @0x308fbc subsle r4, r0, #650117120
 *   @0x308fc0 .word 0x07da6973
 *   @0x308fc4 .word 0xf8d5d549
 *   @0x308fc8 .word 0xf0131588
 *   @0x308fcc .word 0xf9140f06
 *   @0x308fd0 svclt #0xc0c1f
 *   @0x308fd4 .word 0x0c00f04f
 *   @0x308fd8 .word 0x0c01f04f
 *   @0x308fdc biceq pc, r0, #201326595
 *   @0x308fe0 submi r1, r1, #64, #20
 *   @0x308fe4 strbmi r4, [r1, #-0x141]!
 *   @0x308fe8 blhs 0x33d3f4
 *   @0x308fec .word 0xf856d035
 *   @0x308ff0 rfedb r4!
 *   @0x308ff4 movwls r0, #0x3c2c
 *   @0x308ff8 ldrbmi r1, [r1], -r0, asr #20
 *   @0x308ffc svclt #0xb82800
 *   @0x309000 .word 0xf8cd4240
 *   @0x309004 .word 0xf7fec010
 *   @0x309008 blls 0x407554 <g_RomDisk+0xfd34>
 *   @0x30900c ldrsbgt pc, [r0], -sp
 *   @0x309010 ble 0x3da538 <error_g0017+0x331dc>
 *   @0x309014 stmdaeq r12, {r1, r2, r5, r7, r8, r12, sp, lr, pc}
 *   @0x309018 ldrmi r4, [pc], -r1, lsl #13
 *   @0x30901c stcne p8, c15, [r0], #-80
 *   @0x309020 ldrle r0, [r10, #-0x7ca]
 *   @0x309024 stmiblt r3, {r3, r6, r7, r8, r12, sp, pc} ^
 *   @0x309028 .word 0x0c0cf856
 *   @0x30902c stcne p9, c15, [r12], #-208
 *   @0x309030 svclt #0xac4281
 *   @0x309034 andhs r2, r1, r0
 *   @0x309038 andle r4, lr, r0, ror #10
 *   @0x30903c movwls r6, #0x3830
 *   @0x309040 ldrbmi r1, [r1], -r8, lsl #20
 *   @0x309044 svclt #0xb82800
 *   @0x309048 .word 0xf7fe4240
 *   @0x30904c blls 0x407510 <g_RomDisk+0xfcf0>
 *   @0x309050 ble 0x39a578 <ft_adobe_glyph_list+0x9c54>
 *   @0x309054 ldrmi r4, [pc], -r1, lsl #13
 *   @0x309058 .word 0xf10b46b0
 *   @0x30905c strtlo r0, [r4], -r1, lsl #22
 *   @0x309060 .word 0xf1b8e7a9
 *   @0x309064 andle r0, r8, r0, lsl #30
 *   @0x309068 .word 0x8c18f844
 *   @0x30906c .word 0xf814b12f
 *   @0x309070 .word 0xf0433c20
 *   @0x309074 .word 0xf8040308
 *   @0x309078 strtlo r3, [r12], #-3104
 *   @0x30907c .word 0xf8d5e783
 *   @0x309080 .word 0xf1bb3ab4
 *   @0x309084 tstle r7, r0, lsl #30
 *   @0x309088 stmibvs r2!, {r1, r2, r10, r11, r12, pc}
 *   @0x30908c tstle r0, r1, lsl #20
 *   @0x309090 strle r0, [lr], #-1817
 *   @0x309094 ldmdage r1, {r4, r8, r9, r11, sp, pc}
 *   @0x309098 strtmi r9, [r9], -r0, lsl #6
 *   @0x30909c blge 0x6daa0c <g_SWFvertbuff+0x7944>
 *   @0x3090a0 ldc2 p5, c15, [r4, #700]
 *   @0x3090a4 ldrbmi r4, [r9], -r8, lsr #12
 *   @0x3090a8 blls 0x72f8ec <g_SWFvertbuff+0x5c824>
 *   @0x3090ac .word 0xfc09f5af
 *   @0x3090b0 .word 0xf013e2ce
 *   @0x3090b4 and r0, r1, r1, lsl #30
 *   @0x3090b8 svceq #0x2f013
 *   @0x3090bc sbchi pc, r8, #64
 *   @0x3090c0 eorhs r9, r12, #1792
 *   @0x3090c4 svceq #0x1f1bb
 *   @0x3090c8 .word 0x6c266ba3
 *   @0x3090cc andvs pc, r3, #2048
 *   @0x3090d0 ldrblo pc, [r8, #-0x8df]!
 *   @0x3090d4 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x3090d8 .word 0xf8d59205
 *   @0x3090dc ldmdavs r2, {r2, r3, r4, r5, r7, r9, r11, sp}
 *   @0x3090e0 .word 0xf8536892
 *   @0x3090e4 .word 0xd14b3022
 *   @0x3090e8 ssatmi r7, #0x11, r11, lsl #22
 *   @0x3090ec movwls r2, #0x8700
 *   @0x3090f0 strmi r9, [r0, #0xc05]!
 *   @0x3090f4 .word 0xf898d247
 *   @0x3090f8 .word 0xf003300c
 *   @0x3090fc .word 0xf0020204
 *   @0x309100 bhs 0x309504 <TT_New_Context+0x92fc>
 *   @0x309104 .word 0xf8d8d139
 *   @0x309108 .word 0xf8d82014
 *   @0x30910c .word 0xb1aa4018
 *   @0x309110 stmdbvs r2!, {r2, r5, r7, r8, r12, sp, pc} ^
 *   @0x309114 blvc 0xbb5764 <b2_toiTime+0x45c2c0>
 *   @0x309118 .word 0x0108f002
 *   @0x30911c cdpeq p0, #0xf, c15, c15, c1, #0x0
 *   @0x309120 .word 0xf022b121
 *   @0x309124 .word 0x61600208
 *   @0x309128 and r7, r7, r2, lsr #6
 *   @0x30912c strle r0, [r5, #-0x71a]
 *   @0x309130 movweq pc, #0x8023
 *   @0x309134 ands pc, r4, r8, asr #17
 *   @0x309138 andlo pc, r12, r8, lsl #17
 *   @0x30913c ldrsblo pc, [r4], -r8
 *   @0x309140 bicslt r11, r4, r11, lsr #18
 *   @0x309144 blhs 0x3236d8
 *   @0x309148 addshi pc, r5, #64
 *   @0x30914c .word 0x4642e015
 *   @0x309150 umullsvs r6, r3, r11, r8
 *   @0x309154 .word 0xf0437b13
 *   @0x309158 tstvc r3, #4, #6
 *   @0x30915c stmdbvs r3!, {r2, r4, r6, r8, r12, sp, pc} ^
 *   @0x309160 strtmi r11, [r3], -r3, asr #18
 *   @0x309164 .word 0x21014628
 *   @0x309168 ldc2 p5, c15, [pc], {175}
 *   @0x30916c .word 0xf0437b23
 *   @0x309170 .word 0x73230304
 *   @0x309174 svclt #0x82f00
 *   @0x309178 .word 0xf1084647
 *   @0x30917c ldr r0, [r7, r12, lsr #16]!
 *   @0x309180 strls r2, [r8], #-1024
 *   @0x309184 ldrtmi r4, [r4], -r7, lsr #12
 *   @0x309188 .word 0xf1a62000
 *   @0x30918c andls r0, r11, r12, lsr #2
 *   @0x309190 bls 0x46d5c0 <g_RomDisk+0x75da0>
 *   @0x309194 .word 0xf0804294
 *   @0x309198 blvc 0xba95bc <b2_toiTime+0x450118>
 *   @0x30919c cps #0x13
 *   @0x3091a0 .word 0xf8d48101
 *   @0x3091a4 .word 0xf1b88018
 *   @0x3091a8 .word 0xd1030f00
 *   @0x3091ac andlo r9, r1, #45056
 *   @0x3091b0 rscs r9, r7, r11, lsl #4
 *   @0x3091b4 ldrsblo pc, [r4], -r8
 *   @0x3091b8 qsaxmi r11, r3, r3
 *   @0x3091bc ldrbmi r4, [r9], -r8, lsr #12
 *   @0x3091c0 .word 0xf5af4642
 *   @0x3091c4 blvc 0xc08394 <b2_toiTime+0x4aeef0>
 *   @0x3091c8 movweq pc, #0x4043
 *   @0x3091cc rsc r7, r9, r3, lsr #6
 *   @0x3091d0 .word 0xa004f8d4
 *   @0x3091d4 .word 0xd1472f00
 *   @0x3091d8 .word 0x3004f8d8
 *   @0x3091dc andls r4, r0, #40, #12
 *   @0x3091e0 bl 0xff59ab4c <b2_toiTime+0xfffffffffee416a8>
 *   @0x3091e4 .word 0xf8980903
 *   @0x3091e8 strbmi r3, [r10], -r12
 *   @0x3091ec ldrtmi r9, [r11], -r1, lsl #6
 *   @0x3091f0 blx 0xfe5c68b6 <b2_toiTime+0xfffffffffde6d412>
 *   @0x3091f4 stcle p8, c2, [r4, #-256]
 *   @0x3091f8 stcle p8, c2, [r4], #-380
 *   @0x3091fc .word 0x2326211a
 *   @0x309200 .word 0x2120e001
 *   @0x309204 bl 0x59aa38 <g_SWFlineaavertbuff+0x47970>
 *   @0x309208 .word 0xf10a0a69
 *   @0x30920c .word 0xf0220220
 *   @0x309210 ldrmi r0, [r1], #-575
 *   @0x309214 ldrbmi r1, [r7], #-2719
 *   @0x309218 beq 0x5c4124 <g_SWFlineaavertbuff+0x7105c>
 *   @0x30921c svclt #0xb82f00
 *   @0x309220 .word 0xf1ba427f
 *   @0x309224 svclt #0xb80f00
 *   @0x309228 beq 0x345958
 *   @0x30922c svclt #0xb84557
 *   @0x309230 smlabteq r2, r3, r11, lr
 *   @0x309234 bicsvc lr, r0, #0, #22
 *   @0x309238 smultbeq r3, r1, r11
 *   @0x30923c strmi r6, [r1], #-161
 *   @0x309240 andne pc, r8, r8, asr #17
 *   @0x309244 .word 0xf10ae004
 *   @0x309248 .word 0xf02a0a20
 *   @0x30924c adcvs r0, r3, pc, lsr r3
 *   @0x309250 strtmi r7, [r8], -r3, lsr #22
 *   @0x309254 qsaxmi r4, r2, r9
 *   @0x309258 movweq pc, #0x4043
 *   @0x30925c strbmi r7, [r3], -r3, lsr #6
 *   @0x309260 .word 0xf5af4627
 *   @0x309264 adds pc, sp, r2, lsr #24
 *   @0x309268 ldmvs r8!, {r0, r3, r4, r5, r6, r11, sp, lr}
 *   @0x30926c smlabteq r10, r1, r11, lr
 *   @0x309270 .word 0x0c00eb01
 *   @0x309274 .word 0x1004f8d8
 *   @0x309278 muleq r12, r8, r8
 *   @0x30927c beq 0x3841ac <_ZTS13C_UTF16String+0x1b258>
 *   @0x309280 ldrbmi r9, [r9], -r0, lsl #4
 *   @0x309284 andsgt pc, r0, sp, asr #17
 *   @0x309288 ldrbmi r9, [r2], -r12
 *   @0x30928c strtmi r9, [r8], -r1
 *   @0x309290 stmdbeq r10!, {r2, r3, r8, r9, r11, sp, lr, pc} ^
 *   @0x309294 blx 0x114695a <b2_toiTime+0x9ed4b6>
 *   @0x309298 .word 0xf8dd990c
 *   @0x30929c .word 0xf011c010
 *   @0x3092a0 andle r0, r4, r4, lsl #30
 *   @0x3092a4 .word 0x3008f8d8
 *   @0x3092a8 adcvs r1, r0, r8, lsl r10
 *   @0x3092ac ldmdahs pc, {r2, r3, r6, sp, lr, pc} ^
 *   @0x3092b0 stmdahs r0, {r0, r2, r5, r10, r11, r12, lr, pc} ^
 *   @0x3092b4 .word 0x0120f109
 *   @0x3092b8 teqeq pc, r1, lsr #32
 *   @0x3092bc sbcsvc lr, r0, r0, lsl #22
 *   @0x3092c0 .word 0x2320bfd5
 *   @0x3092c4 ldrmi r2, [r10], -r6, lsr #4
 *   @0x3092c8 bl 0xff351f38 <b2_toiTime+0xfffffffffebf8a94>
 *   @0x3092cc strmi r0, [r11], #-3586
 *   @0x3092d0 bl 0xff3da610 <b2_toiTime+0xfffffffffec8116c>
 *   @0x3092d4 .word 0xf1be0909
 *   @0x3092d8 svclt #0xb80f00
 *   @0x3092dc cdpeq p1, #0x0, c15, c0, c14, #0x6
 *   @0x3092e0 svceq #0xf1b9
 *   @0x3092e4 .word 0xf1c9bfb8
 *   @0x3092e8 strbmi r0, [lr, #0x900]
 *   @0x3092ec bl 0xff3b91d4 <b2_toiTime+0xfffffffffec5fd30>
 *   @0x3092f0 bl 0xfebc9efc <b2_toiTime+0xfffffffffe470a58>
 *   @0x3092f4 bl 0x3c9c7c <error_g0017+0x22920>
 *   @0x3092f8 adcvs r0, r2, r0, rrx
 *   @0x3092fc strbtmi lr, [r2], #34
 *   @0x309300 eoreq pc, r0, #12, #2
 *   @0x309304 beq 0xb45734 <b2_toiTime+0x3ec290>
 *   @0x309308 .word 0xf02a1041
 *   @0x30930c .word 0xf0220a3f
 *   @0x309310 bl 0xff309c14 <b2_toiTime+0xfffffffffebb0770>
 *   @0x309314 bl 0x38bb44 <_pcre_default_tables+0x9c>
 *   @0x309318 ldrbmi r0, [r1], #-3585
 *   @0x30931c vmlseq.f64 d14, d30, d9
 *   @0x309320 stmdbeq r1, {r0, r3, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x309324 svceq #0xf1be
 *   @0x309328 .word 0xf1cebfb8
 *   @0x30932c .word 0xf1b90e00
 *   @0x309330 svclt #0xb80f00
 *   @0x309334 stmdbeq r0, {r0, r3, r6, r7, r8, r12, sp, lr, pc}
 *   @0x309338 svclt #0xac45ce
 *   @0x30933c ssaxmi r4, r3, r3
 *   @0x309340 ldrmi r6, [r8], #-163
 *   @0x309344 andeq pc, r8, r8, asr #17
 *   @0x309348 adcsmi r7, r4, #35840
 *   @0x30934c movweq pc, #0x4043
 *   @0x309350 .word 0xf8987323
 *   @0x309354 .word 0xf043300c
 *   @0x309358 .word 0xf8880304
 *   @0x30935c stmdble r1!, {r2, r3, r12, sp}
 *   @0x309360 blne 0xfebaf388 <b2_toiTime+0xfffffffffe455ee4>
 *   @0x309364 teqlt r8, r3, lsr #17
 *   @0x309368 strmi r9, [r10], #-2314
 *   @0x30936c addsmi r6, r3, #9568256
 *   @0x309370 movwhs r11, #0xfd4
 *   @0x309374 and r2, r6, r1, lsl #6
 *   @0x309378 strmi r9, [r2], #-2058
 *   @0x30937c addsmi r6, r3, #9568256
 *   @0x309380 movwhs r11, #0xfac
 *   @0x309384 .word 0xb16b2301
 *   @0x309388 cmplt r10, r2, lsr #19
 *   @0x30938c blne 0xfebef7bc <b2_toiTime+0xfffffffffe496318>
 *   @0x309390 strmi r6, [r11], #-2194
 *   @0x309394 bne 0xff7a3608 <b2_toiTime+0xffffffffff04a164>
 *   @0x309398 svclt #0xb82a00
 *   @0x30939c bhs 0x719cec <g_SWFvertbuff+0x46c24>
 *   @0x3093a0 adcvs r11, r3, r8, asr #31
 *   @0x3093a4 ldrbt r3, [r4], r12, lsr #8
 *   @0x3093a8 svceq #0xf1bb
 *   @0x3093ac blne 0xfe7bd8cc <b2_toiTime+0xfffffffffe064428>
 *   @0x3093b0 addsne r4, r2, r5, lsr #23
 *   @0x3093b4 bhs 0x49a124 <TimingData+0x10c>
 *   @0x3093b8 bhs 0x63d3e0 <g_SWFaavertbuff+0x6a318>
 *   @0x3093bc .word 0xf106d13e
 *   @0x3093c0 .word 0xf106012c
 *   @0x3093c4 .word 0xf5060edc
 *   @0x3093c8 and r7, r4, r6, asr #7
 *   @0x3093cc cdpeq p1, #0x5, c15, c8, c6, #0x0
 *   @0x3093d0 movseq pc, #2147483649
 *   @0x3093d4 .word 0xf8de4631
 *   @0x3093d8 stmdavs r12, {r2, lr, pc} ^
 *   @0x3093dc stmdaeq r12, {r2, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x3093e0 bl 0xff623558 <b2_toiTime+0xfffffffffeeca0b4>
 *   @0x3093e4 bl 0xff3093fc <b2_toiTime+0xfffffffffebaff58>
 *   @0x3093e8 stmdahs r0, {r3}
 *   @0x3093ec submi r11, r0, #184, #30
 *   @0x3093f0 stcle p8, c2, [r3], #-28
 *   @0x3093f4 .word 0xf8de6889
 *   @0x3093f8 ldmibvs r12, {r3}
 *   @0x3093fc subeq lr, r0, r1, lsr #23
 *   @0x309400 strmi r6, [r1], #-2201
 *   @0x309404 addsvs r4, r8, r0, asr #4
 *   @0x309408 stmvs r0!, {r2, r4, r8, r12, sp, pc}
 *   @0x30940c adcvs r1, r0, r0, asr #20
 *   @0x309410 .word 0xd1092a0c
 *   @0x309414 .word 0x2168f8d6
 *   @0x309418 .word 0xf8c61a52
 *   @0x30941c .word 0xf8d62168
 *   @0x309420 bne 0x1751bd8 <b2_toiTime+0xff8734>
 *   @0x309424 mvnne pc, r6, asr #17
 *   @0x309428 .word 0xf0427b1a
 *   @0x30942c tstvc r10, #4, #4
 *   @0x309430 .word 0xb11b699b
 *   @0x309434 .word 0xf0427b1a
 *   @0x309438 tstvc r10, #4, #4
 *   @0x30943c ldmdblt r12, {r0, r1, r3, r10, r11, r12, pc} ^
 *   @0x309440 .word 0x9c07b157
 *   @0x309444 blvs 0x1bd18fc <b2_toiTime+0x1478458>
 *   @0x309448 blx 0x363fda <_ZTS12CDS_Priority+0x6032>
 *   @0x30944c .word 0xf1bb3102
 *   @0x309450 .word 0xf0000f00
 *   @0x309454 sbcs r8, r12, r12, asr #1
 *   @0x309458 strteq pc, [r12], #-262
 *   @0x30945c ldmdaeq r8!, {r1, r2, r8, r12, sp, lr, pc}
 *   @0x309460 stceq p1, c15, [r12], #-664
 *   @0x309464 bls 0x45aef4 <g_RomDisk+0x636d4>
 *   @0x309468 stmdbeq r12!, {r2, r5, r7, r8, r12, sp, lr, pc}
 *   @0x30946c rscle r4, r8, #608174080
 *   @0x309470 stclo p8, c15, [r0], #-80
 *   @0x309474 cps #0x18
 *   @0x309478 .word 0xf85480b5
 *   @0x30947c cmnlt r3, r0, lsl r12
 *   @0x309480 .word 0xf854685a
 *   @0x309484 bne 0x171052c <b2_toiTime+0xfb7088>
 *   @0x309488 svclt #0xb82800
 *   @0x30948c stmdahs pc, {r6, r9, lr} ^
 *   @0x309490 bne 0xfe5c04ac <b2_toiTime+0xfffffffffde67008>
 *   @0x309494 strmi r6, [r10], #-2201
 *   @0x309498 stchs p8, c15, [r4], #-272
 *   @0x30949c stmdblt r7, {r3, r6, sp, lr, pc} ^
 *   @0x3094a0 stclo p8, c15, [r8], #-336
 *   @0x3094a4 .word 0x3320464f
 *   @0x3094a8 teqeq pc, #35
 *   @0x3094ac stclo p8, c15, [r4], #-272
 *   @0x3094b0 .word 0xf1a4e03e
 *   @0x3094b4 adcsmi r0, r3, #88, #6
 *   @0x3094b8 blvc 0x9be0c8 <b2_toiTime+0x264c24>
 *   @0x3094bc strle r0, [r1, #-0x751]
 *   @0x3094c0 and r4, r5, r1, lsr #12
 *   @0x3094c4 ldrb r3, [r6, r12, lsr #22]!
 *   @0x3094c8 ldrbeq r7, [r2, -r10, lsl #22]
 *   @0x3094cc .word 0x312cd403
 *   @0x3094d0 addmi r9, r1, #327680
 *   @0x3094d4 adcsmi sp, r3, #248, #6
 *   @0x3094d8 strbmi sp, [r11, #-0x31f]
 *   @0x3094dc bls 0x47dd58 <targetStr+0x2b18>
 *   @0x3094e0 andsle r4, r10, #268435465
 *   @0x3094e4 ldmdble r8, {r0, r3, r6, r8, r10, lr}
 *   @0x3094e8 .word 0xf8d1685a
 *   @0x3094ec ldmvs r11, {r2, sp, lr, pc}
 *   @0x3094f0 mulsle r11, r6, r5
 *   @0x3094f4 stceq p8, c15, [r8], #-336
 *   @0x3094f8 bne 0xfe323724 <b2_toiTime+0xfffffffffdbca280>
 *   @0x3094fc andeq lr, lr, #198656
 *   @0x309500 movwls r1, #0x3ac9
 *   @0x309504 andsgt pc, r0, sp, asr #17
 *   @0x309508 .word 0xfc18f7db
 *   @0x30950c ldrmi r9, [r8], #-2819
 *   @0x309510 stceq p8, c15, [r4], #-272
 *   @0x309514 ldrsbgt pc, [r0], -sp
 *   @0x309518 ldmdavs r11!, {r1, r3, sp, lr, pc} ^
 *   @0x30951c stchs p8, c15, [r8], #-336
 *   @0x309520 ldmvs r11!, {r1, r4, r6, r7, r9, r11, r12}
 *   @0x309524 .word 0xf0223210
 *   @0x309528 ldrmi r0, [r3], #-543
 *   @0x30952c stclo p8, c15, [r4], #-272
 *   @0x309530 stclo p8, c15, [r0], #-80
 *   @0x309534 .word 0xf04345b1
 *   @0x309538 .word 0xf8040304
 *   @0x30953c stmdble r7!, {r5, r10, r11, r12, sp}
 *   @0x309540 bl 0xff5b0168 <b2_toiTime+0xfffffffffee56cc4>
 *   @0x309544 strbtmi r0, [r2], #-520
 *   @0x309548 .word 0xf854b143
 *   @0x30954c .word 0xf8523c24
 *   @0x309550 addsmi r2, r3, #4, #24
 *   @0x309554 movwhs r11, #0xfd4
 *   @0x309558 and r2, r7, r1, lsl #6
 *   @0x30955c stclo p8, c15, [r4], #-336
 *   @0x309560 .word 0x2c04f852
 *   @0x309564 svclt #0xac4293
 *   @0x309568 movwhs r2, #0x1300
 *   @0x30956c .word 0xf854b183
 *   @0x309570 .word 0xb16a2c14
 *   @0x309574 movweq lr, #0x8bca
 *   @0x309578 strbtmi r6, [r3], #-2194
 *   @0x30957c .word 0x3c04f853
 *   @0x309580 bhs 0x3100d0 <af_shaper_get_elem+0x593e>
 *   @0x309584 subsmi r11, r2, #184, #30
 *   @0x309588 svclt #0xc82a10
 *   @0x30958c stclo p8, c15, [r4], #-272
 *   @0x309590 addmi r9, r4, #327680
 *   @0x309594 .word 0xf898d226
 *   @0x309598 ldrbeq r3, [r11, -r0]
 *   @0x30959c stmdbls r8, {r1, r5, r8, r10, r12, lr, pc}
 *   @0x3095a0 stchs p8, c15, [r4], #-336
 *   @0x3095a4 .word 0x3c04f858
 *   @0x3095a8 addsmi r11, r10, #1073741832
 *   @0x3095ac movwhs r11, #0xfac
 *   @0x3095b0 and r2, r3, r1, lsl #6
 *   @0x3095b4 svclt #0xd4429a
 *   @0x3095b8 movwhs r2, #0x1300
 *   @0x3095bc .word 0xf854b193
 *   @0x3095c0 cmnlt r11, r4, lsl r12
 *   @0x3095c4 smlabteq r8, r10, r11, lr
 *   @0x3095c8 strbtmi r6, [r1], #-2202
 *   @0x3095cc .word 0x3c04f851
 *   @0x3095d0 blhs 0x310124 <af_shaper_get_elem+0x5992>
 *   @0x3095d4 subsmi r11, r11, #184, #30
 *   @0x3095d8 svclt #0xc42b10
 *   @0x3095dc .word 0x3c04f858
 *   @0x3095e0 stclo p8, c15, [r4], #-272
 *   @0x3095e4 .word 0xf108342c
 *   @0x3095e8 ldr r0, [r12, -r12, lsr #16]!
 *   @0x3095ec addmi r3, r11, #44, #6
 *   @0x3095f0 ldmvs r12, {r0, r4, r9, r12, lr, pc} ^
 *   @0x3095f4 rscsle r2, r9, r0, lsl #24
 *   @0x3095f8 bvs 0xfeaa3f68 <b2_toiTime+0xfffffffffe34aac4>
 *   @0x3095fc adcsmi r6, r2, #160, #16
 *   @0x309600 ldmdahi r0, {r4, r8, sp, lr}
 *   @0x309604 andeq pc, r4, r0, asr #32
 *   @0x309608 rscle r8, pc, r0, lsl r0
 *   @0x30960c .word 0xe7f56a12
 *   @0x309610 addmi r3, r11, #44, #6
 *   @0x309614 strtmi sp, [r8], -r8, lsl #6
 *   @0x309618 .word 0xf5af4659
 *   @0x30961c strtmi pc, [r8], -r5, ror #23
 *   @0x309620 .word 0xf5af4659
 *   @0x309624 ands pc, r3, r2, lsl #28
 *   @0x309628 .word 0x2c0068dc
 *   @0x30962c bvs 0x19bd9f4 <b2_toiTime+0x1264550>
 *   @0x309630 stmvs r0!, {r1, r2, r3, r4, r7, r9, r11, sp, lr}
 *   @0x309634 ldrhvs r4, [r0, #-34]
 *   @0x309638 .word 0xf0408810
 *   @0x30963c andshi r0, r0, r8
 *   @0x309640 bvs 0x7bd9e0 <b2_toiTime+0x6453c>
 *   @0x309644 svclt #0xe7f5
 *   @0x309648 blt 0xeac4dc <b2_toiTime+0x753038>
 *   @0x30964c andeq r8, lr, r0, lsl r11
 *   @0x309650 bleq 0x385a84 <_ZTS13C_UTF16String+0x1cb30>
 *   @0x309654 .word 0xf1bb9c07
 *   @0x309658 vmax.f32 d0, d4, d2
 *   @0x30965c strls r5, [r7], #-1092
 *   @0x309660 stcge p4, c15, [sp, #-508]
 *   @0x309664 stmdbls sp, {r3, r5, r9, r10, lr}
 *   @0x309668 mcr2 p7, #0x1, pc, c14, c13, #0x7
 *   @0x30966c andls lr, r9, r6
 *   @0x309670 andls lr, r9, r4
 *   @0x309674 strtmi lr, [r2], -r2
 *   @0x309678 strb r4, [r9, #-0x644]!
 *   @0x30967c eorlt r9, r1, r9, lsl #16
 *   @0x309680 svchi #0xf0e8bd
 *   @0x309684 svcmi #0xf0e92d
 *   @0x309688 .word 0x4608b09f
 *   @0x30968c ldrmi r4, [r1], -r12, lsl #12
 *   @0x309690 movwls r9, #0x920b
 *   @0x309694 .word 0xff5cf7fd
 *   @0x309698 stmdahs r0, {r3, r12, pc}
 *   @0x30969c eorhi pc, r9, #64
 *   @0x3096a0 ldmibvs r3!, {r0, r3, r9, r10, r11, r12, pc}
 *   @0x3096a4 .word 0xf8d42b01
 *   @0x3096a8 strhle r3, [r1, -r4]
 *   @0x3096ac strle r0, [r1, #-0x71a]
 *   @0x3096b0 strle r0, [r11], #-2011
 *   @0x3096b4 .word 0x21004620
 *   @0x3096b8 .word 0xf902f7ff
 *   @0x3096bc stmdahs r0, {r1, r9, r10, lr}
 *   @0x3096c0 mvnshi pc, r0, asr #32
 *   @0x3096c4 stmdbls r9, {r5, r9, r10, lr}
 *   @0x3096c8 mrc2 p7, #0x1, apsr_nzcv, c6, c14, #0x7
 *   @0x3096cc blo 0xff047a24 <b2_toiTime+0xfffffffffe8ee580>
 *   @0x3096d0 strle r0, [r11], #-1951
 *   @0x3096d4 .word 0x21014620
 *   @0x3096d8 .word 0xf8f2f7ff
 *   @0x3096dc .word 0xf0402800
 *   @0x3096e0 strtmi r8, [r0], -r4, ror #3
 *   @0x3096e4 andhs r9, r1, #147456
 *   @0x3096e8 mcr2 p7, #0x1, pc, c6, c14, #0x7
 *   @0x3096ec strhs r4, [r0, -r1, lsr #13]
 *   @0x3096f0 blo 0xff047a48 <b2_toiTime+0xfffffffffe8ee5a4>
 *   @0x3096f4 bfieq r11, r7, #18, #13
 *   @0x3096f8 bic sp, r9, r3, lsl #10
 *   @0x3096fc ldrle r0, [r5, #-0x79d]
 *   @0x309700 cdpls p1, #0x0, c14, c9, c6, #0x6
 *   @0x309704 bhs 0x363dd4 <_ZTS12CDS_Priority+0x5e2c>
 *   @0x309708 .word 0x0718d110
 *   @0x30970c blge 0x6be74c <g_SWFlinevertbuff+0x6b684>
 *   @0x309710 movwls r10, #0x80f
 *   @0x309714 ldrtmi r4, [r10], -r1, lsr #12
 *   @0x309718 .word 0xf5afab0d
 *   @0x30971c qsaxmi pc, r0, r7
 *   @0x309720 bls 0x65b00c <g_SWFlinevertbuff+0x7f44>
 *   @0x309724 .word 0xf5af9b0e
 *   @0x309728 .word 0xe1b1f8cc
 *   @0x30972c .word 0x5040f8d9
 *   @0x309730 .word 0xf8d9222c
 *   @0x309734 .word 0xf04f3038
 *   @0x309738 strtmi r0, [lr], -r0, lsl #24
 *   @0x30973c andpl pc, r3, #2048
 *   @0x309740 stmdals r7, {r0, r1, r2, r9, r12, pc}
 *   @0x309744 eorsle r4, r6, #1610612744
 *   @0x309748 smmlareq r9, r3, r11, r7
 *   @0x30974c ldmdbvs r3!, {r0, r4, r5, r10, r12, lr, pc} ^
 *   @0x309750 stmdblt r11!, {r1, r4, r5, r7, r8, r11, sp, lr}
 *   @0x309754 ldmdbvs r3, {r1, r3, r5, r6, r8, r9, r12, sp, pc} ^
 *   @0x309758 .word 0xf0402b00
 *   @0x30975c eor r8, r8, r8, lsr #3
 *   @0x309760 shadd8mi r4, r2, r0
 *   @0x309764 .word 0xa008f8d3
 *   @0x309768 .word 0xf8c27b13
 *   @0x30976c .word 0xf043a008
 *   @0x309770 tstvc r3, #4, #6
 *   @0x309774 svceq #0xf1b8
 *   @0x309778 .word 0xf8d8d017
 *   @0x30977c stmiblt r3!, {r2, r4, r12, sp}
 *   @0x309780 .word 0x3004f8d8
 *   @0x309784 ldmdavs r2, {r5, r9, r10, lr} ^
 *   @0x309788 .word 0xf8cd4639
 *   @0x30978c bne 0xfe9b97e4 <b2_toiTime+0xfffffffffe260340>
 *   @0x309790 blx 0xffac6e56 <b2_toiTime+0xffffffffff36d9b2>
 *   @0x309794 mullo r12, r8, r8
 *   @0x309798 movweq pc, #0x4043
 *   @0x30979c andlo pc, r12, r8, lsl #17
 *   @0x3097a0 .word 0xf8c84450
 *   @0x3097a4 .word 0xf8dd0008
 *   @0x3097a8 .word 0xf1bcc014
 *   @0x3097ac svclt #0x80f00
 *   @0x3097b0 .word 0x362c46b4
 *   @0x3097b4 movwhs lr, #0x7c5
 *   @0x3097b8 ldrmi r4, [r11], lr, lsr #12
 *   @0x3097bc movwls r9, #0x6303
 *   @0x3097c0 stmdals r7, {r1, r3, r8, r9, r12, pc}
 *   @0x3097c4 rsbsle r4, r0, #1610612744
 *   @0x3097c8 mulge r12, r6, r8
 *   @0x3097cc svceq #0x4f01a
 *   @0x3097d0 .word 0xf8d6d169
 *   @0x3097d4 .word 0xf1b88018
 *   @0x3097d8 andle r0, r11, r0, lsl #30
 *   @0x3097dc .word 0xb1639b06
 *   @0x3097e0 ldmvs r1!, {r0, r1, r8, r9, r11, r12, pc}
 *   @0x3097e4 eorseq pc, pc, #-1073741824
 *   @0x3097e8 ble 0x3da218 <error_g0017+0x32ebc>
 *   @0x3097ec .word 0x1008f8d8
 *   @0x3097f0 blle 0x39a220 <ft_adobe_glyph_list+0x98fc>
 *   @0x3097f4 bleq 0x385c28 <_ZTS13C_UTF16String+0x1ccd4>
 *   @0x3097f8 .word 0xf8d8e055
 *   @0x3097fc orrslt r2, r2, r4, lsl r0
 *   @0x309800 .word 0x2004f8d8
 *   @0x309804 ldmdavs r3!, {r5, r9, r10, lr} ^
 *   @0x309808 .word 0xf8cd4639
 *   @0x30980c .word 0xf04ac014
 *   @0x309810 bne 0xfe98c028 <b2_toiTime+0xfffffffffe232b84>
 *   @0x309814 blx 0xfea46eda <b2_toiTime+0xfffffffffe2eda36>
 *   @0x309818 .word 0x2008f8d8
 *   @0x30981c andge pc, r12, r6, lsl #17
 *   @0x309820 adcsvs r4, r0, r0, lsl r4
 *   @0x309824 ldrmi lr, [r0, #0x16]!
 *   @0x309828 .word 0xf8d8d217
 *   @0x30982c strtmi r2, [r0], -r4
 *   @0x309830 shsub16mi r6, r9, r3
 *   @0x309834 andsgt pc, r4, sp, asr #17
 *   @0x309838 beq 0x445968 <g_RomDisk+0x4e148>
 *   @0x30983c .word 0xf5af1a9a
 *   @0x309840 .word 0xf8d8fb87
 *   @0x309844 .word 0xf8863008
 *   @0x309848 strmi r10, [r3], #-12
 *   @0x30984c adcsvs r9, r3, r3, lsl #6
 *   @0x309850 movwls r2, #0x6301
 *   @0x309854 ldrsbgt pc, [r4], -sp
 *   @0x309858 svchs #0x1e025
 *   @0x30985c .word 0xf1bcd00c
 *   @0x309860 .word 0xd1090f00
 *   @0x309864 andgt pc, r0, sp, asr #17
 *   @0x309868 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x30986c strbtmi r4, [r3], -r2, asr #12
 *   @0x309870 .word 0xfc00f5af
 *   @0x309874 and r9, r6, r10
 *   @0x309878 strtmi r9, [r0], -r0, lsl #14
 *   @0x30987c .word 0x46424631
 *   @0x309880 .word 0xf5af9b0a
 *   @0x309884 blvc 0x1008868 <b2_toiTime+0x8af3c4>
 *   @0x309888 .word 0xf04346b4
 *   @0x30988c teqvc r3, #4, #6
 *   @0x309890 mullo r12, r8, r8
 *   @0x309894 movweq pc, #0x4043
 *   @0x309898 andlo pc, r12, r8, lsl #17
 *   @0x30989c .word 0x3008f8d8
 *   @0x3098a0 movwhs r9, #0x1303
 *   @0x3098a4 strtlo r9, [r12], -r6, lsl #6
 *   @0x3098a8 svchs #0xe78b
 *   @0x3098ac bl 0xff47de18 <b2_toiTime+0xfffffffffed24974>
 *   @0x3098b0 ldmibmi r2, {r9, r10, r11}
 *   @0x3098b4 .word 0x0eaeea4f
 *   @0x3098b8 .word 0xfe0efb01
 *   @0x3098bc svceq #0x6f1be
 *   @0x3098c0 .word 0xf1bed009
 *   @0x3098c4 .word 0xd14c0f0c
 *   @0x3098c8 eoreq pc, r12, #1073741825
 *   @0x3098cc bicseq pc, r12, r5, lsl #2
 *   @0x3098d0 bicvc pc, r6, #20971520
 *   @0x3098d4 .word 0xf105e004
 *   @0x3098d8 .word 0xf1050158
 *   @0x3098dc .word 0x462a03b0
 *   @0x3098e0 .word 0xc004f8d1
 *   @0x3098e4 bl 0xff4a3a44 <b2_toiTime+0xfffffffffed4a5a0>
 *   @0x3098e8 ldmdavs lr, {r2, r3, r11} ^
 *   @0x3098ec andeq lr, r6, r12, asr #23
 *   @0x3098f0 streq lr, [r8], -r0, asr #23
 *   @0x3098f4 cps #0x10
 *   @0x3098f8 cdphs p8, #0x0, c0, c0, c12, #0x1
 *   @0x3098fc rsbsmi r11, r6, #184, #30
 *   @0x309900 .word 0xd12e4540
 *   @0x309904 .word 0xf1016988
 *   @0x309908 strbmi r0, [r0, #-0x82c]
 *   @0x30990c ldmibvs r8, {r0, r3, r5, r8, r12, lr, pc}
 *   @0x309910 stmdaeq r12!, {r0, r1, r8, r12, sp, lr, pc}
 *   @0x309914 .word 0xd1244540
 *   @0x309918 stcle p14, c2, [r2], #-28
 *   @0x30991c ldmvs r2, {r0, r3, r7, r11, sp, lr}
 *   @0x309920 subeq lr, r1, #165888
 *   @0x309924 ldrmi r6, [r1], #-2201
 *   @0x309928 addsvs r4, r10, r2, asr r2
 *   @0x30992c stmvs r2, {r4, r8, r12, sp, pc}
 *   @0x309930 addvs r1, r2, r2, asr r10
 *   @0x309934 svceq #0xcf1be
 *   @0x309938 .word 0xf8d5d109
 *   @0x30993c bne 0x1791ee4 <b2_toiTime+0x1038a40>
 *   @0x309940 smulbths r8, r5, r8
 *   @0x309944 .word 0x21ecf8d5
 *   @0x309948 .word 0xf8c51a51
 *   @0x30994c blvc 0x98e104 <b2_toiTime+0x234c60>
 *   @0x309950 andeq pc, r4, #66
 *   @0x309954 ldmibvs r11, {r1, r3, r4, r8, r9, r12, sp, lr}
 *   @0x309958 blvc 0x9b5dcc <b2_toiTime+0x25c928>
 *   @0x30995c andeq pc, r4, #66
 *   @0x309960 .word 0xf1bb731a
 *   @0x309964 andsle r0, r2, r0, lsl #30
 *   @0x309968 and r4, r3, r11, lsr #12
 *   @0x30996c .word 0x07727b1e
 *   @0x309970 .word 0x332cd51b
 *   @0x309974 adcsmi r9, r3, #7, #28
 *   @0x309978 .word 0xf1bbd3f8
 *   @0x30997c andle r0, r6, r0, lsl #30
 *   @0x309980 strteq pc, [r12], -r5, lsl #2
 *   @0x309984 .word 0xf1a69b07
 *   @0x309988 addsmi r0, r9, #44, #2
 *   @0x30998c .word 0xf8d9d31c
 *   @0x309990 strhs r3, [r12, #-0x40]!
 *   @0x309994 ldrsbths pc, [r8], -r9
 *   @0x309998 bvs 0xff147cf0 <b2_toiTime+0xfffffffffe9ee84c>
 *   @0x30999c vmlalo.f64 d15, d2, d5
 *   @0x3099a0 teqle r1, r0, lsl #30
 *   @0x3099a4 streq pc, [r1], -r6
 *   @0x3099a8 ldmibvs r10, {r4, r5, sp, lr, pc} ^
 *   @0x3099ac rscle r2, r0, r0, lsl #20
 *   @0x3099b0 .word 0xf0466851
 *   @0x3099b4 ldmdavs r8, {r2, r9, r10} ^
 *   @0x3099b8 bllo 0x305dec <TT_New_Context+0x5be4>
 *   @0x3099bc ldmvs r0, {r0, r6, r9, r11, r12}
 *   @0x3099c0 strmi r7, [r1], #-798
 *   @0x3099c4 bfi r6, r9, #1, #20
 *   @0x3099c8 stclo p8, c15, [r0], #-88
 *   @0x3099cc ldrle r0, [r9], #-1880
 *   @0x3099d0 stmdalo r12!, {r3, r9, r10, lr}
 *   @0x3099d4 movwle r4, #0x62a8
 *   @0x3099d8 ldrbeq r7, [r10, -r3, lsl #22]
 *   @0x3099dc ldrb sp, [r8, r3, lsl #8]!
 *   @0x3099e0 ldrbeq r7, [r11, -r11, lsl #22]
 *   @0x3099e4 bls 0x4fe9fc <SrcVerts+0x5ba40>
 *   @0x3099e8 addsmi r3, r1, #44, #2
 *   @0x3099ec .word 0xe060d3f8
 *   @0x3099f0 rsble r4, r6, #168, #4
 *   @0x3099f4 stchs p8, c15, [r8], #-344
 *   @0x3099f8 bne 0xff7e3b2c <b2_toiTime+0xffffffffff08a688>
 *   @0x3099fc ldrmi r6, [r3], #-2186
 *   @0x309a00 stclo p8, c15, [r4], #-280
 *   @0x309a04 ldr r3, [sp, r12, lsr #12]!
 *   @0x309a08 strbeq pc, [r0], -r6, asr #7
 *   @0x309a0c ldrbmi r11, [r3, #-0x2f6]!
 *   @0x309a10 bvs 0x19be2f0 <b2_toiTime+0x1264e4c>
 *   @0x309a14 bvs 0x17360d4 <b2_toiTime+0xfdcc30>
 *   @0x309a18 stmdahi r1, {r0, r2, r3, r4, r7, r11, sp, lr}
 *   @0x309a1c .word 0x6105b91f
 *   @0x309a20 .word 0x0104f041
 *   @0x309a24 .word 0xf041e002
 *   @0x309a28 mrsvs r0, spsr
 *   @0x309a2c bvs 0xfe769a38 <b2_toiTime+0xfffffffffe010594>
 *   @0x309a30 andle r4, r1, r8, lsl #5
 *   @0x309a34 strb r6, [pc, r0, lsl #20]!
 *   @0x309a38 bvs 0x1963e88 <b2_toiTime+0x120a9e4>
 *   @0x309a3c mvnle r4, r10, lsl #5
 *   @0x309a40 ldmvs r8, {r2, r3, r4, sp, lr, pc}
 *   @0x309a44 bne 0x1323bb0 <b2_toiTime+0xbca70c>
 *   @0x309a48 rfeia r5!
 *   @0x309a4c stmdblt pc!, {lr, pc}
 *   @0x309a50 .word 0xf04c6929
 *   @0x309a54 strmi r0, [r1], #-3076
 *   @0x309a58 and r6, r4, r9, lsr #2
 *   @0x309a5c .word 0xf04c6969
 *   @0x309a60 strmi r0, [r1], #-3080
 *   @0x309a64 .word 0xf8a56169
 *   @0x309a68 bvs 0xfe779a70 <b2_toiTime+0xfffffffffe0205cc>
 *   @0x309a6c andle r4, r1, sp, lsl #5
 *   @0x309a70 strb r6, [r10, sp, lsr #20]!
 *   @0x309a74 bvs 0x1963ec4 <b2_toiTime+0x120aa20>
 *   @0x309a78 mvnle r4, r10, lsl #5
 *   @0x309a7c strb r3, [r6, r12, lsr #6]
 *   @0x309a80 ldrtmi r4, [r9], -r0, lsr #12
 *   @0x309a84 rfeib r0!
 *   @0x309a88 ldrtmi r4, [r9], -r0, lsr #12
 *   @0x309a8c blx 0xff687152 <b2_toiTime+0xfffffffffef2dcae>
 *   @0x309a90 vabd.s8 d3, d9, d1
 *   @0x309a94 svchs #0x25944
 *   @0x309a98 mcrge p4, #0x1, pc, c10, c15, #0x3
 *   @0x309a9c stmdbls r11, {r5, r9, r10, lr}
 *   @0x309aa0 .word 0xfc12f7fd
 *   @0x309aa4 andls lr, r8, r5, lsr #32
 *   @0x309aa8 andls lr, r8, r3, lsr #32
 *   @0x309aac ldrtmi lr, [r0], r1, lsr #32
 *   @0x309ab0 adcmi lr, r8, #88, #12
 *   @0x309ab4 .word 0xf856d3a6
 *   @0x309ab8 stmdavs r3, {r3, r5, r10, r11, sp} ^
 *   @0x309abc stmvs r2, {r0, r1, r4, r6, r7, r9, r11, r12}
 *   @0x309ac0 rfeib r1!
 *   @0x309ac4 rfeib r0!
 *   @0x309ac8 .word 0xf8d03000
 *   @0x309acc addsmi r8, r10, #8
 *   @0x309ad0 .word 0xf846d102
 *   @0x309ad4 ldr r8, [r5, r4, lsr #24]
 *   @0x309ad8 stceq p9, c15, [r12], #-216
 *   @0x309adc stmvs r9, {r1, r4, r6, r7, r9, r11, r12}
 *   @0x309ae0 bl 0xff5105e8 <b2_toiTime+0xfffffffffedb7144>
 *   @0x309ae4 .word 0xf7db0101
 *   @0x309ae8 strbmi pc, [r0], #-2345
 *   @0x309aec stceq p8, c15, [r4], #-280
 *   @0x309af0 stmdals r8, {r3, r7, r8, r9, r10, sp, lr, pc}
 *   @0x309af4 pop {r0, r1, r2, r3, r4, r12, sp, pc}
 *   @0x309af8 svclt #0x8ff0
 *   @0x309afc blt 0xeac990 <b2_toiTime+0x7534ec>
 *
 * ══ §2/4 anon_308d50  0x308d50  size 3504  876 条（0x308d50..0x309b00）
 * @func 0x308d50 0x309b00  size 3504  876 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_30a7b2+0x73fe / 0xdece24 / 0x1e68e4c / 0xff011fc4 / 0x3997f4 / 0x380f34 / 0xb1a384 / 0x3c3d28
 * 字段偏移 top8: 0x10×2 / 0x14×2 / 0x16×1 / 0x-644×1 / 0x8×1 / 0xc×1 / 0x6×1 / 0x18×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x308d50 svcmi #0xf0e92d
 *   @0x308d54 stcvs p0, c11, [r11, #532]
 *   @0x308d58 strhne pc, [r4], #-129
 *   @0x308d5c ldrsbpl pc, [r8, #-128]!
 *   @0x308d60 rsbsvc pc, r10, pc, asr #32
 *   @0x308d64 streq r8, [r9], #-2460
 *   @0x308d68 .word 0xf7dc9200
 *   @0x308d6c vadd.i8 d31, d16, d20
 *   @0x308d70 bls 0x311bb0 <af_shaper_get_elem+0x741e>
 *   @0x308d74 .word 0x46074298
 *   @0x308d78 addshi pc, r3, r0, asr #6
 *   @0x308d7c bhs 0x323630
 *   @0x308d80 ldrsblt pc, [r8], -r5
 *   @0x308d84 ldrsbge pc, [r12], -r5
 *   @0x308d88 .word 0xf8d59301
 *   @0x308d8c blvs 0xdece24 <b2_toiTime+0x693980>
 *   @0x308d90 .word 0xf8d56aae
 *   @0x308d94 blvs 0x1e68e4c <b2_toiTime+0x170f9a8>
 *   @0x308d98 strls r9, [r3, #-0x302]
 *   @0x308d9c ldreq sp, [r0], #-3333
 *   @0x308da0 .word 0xf7fe4639
 *   @0x308da4 strmi pc, [r5], -r3, lsl #21
 *   @0x308da8 vst4.8 {d30, d31, d0, d1}, [pc], r1
 *   @0x308dac strteq r0, [r4], #-1430
 *   @0x308db0 .word 0xf385fab5
 *   @0x308db4 svchs #0x80f5b4
 *   @0x308db8 .word 0xf44fbfb8
 *   @0x308dbc blx 0xff011fc4 <b2_toiTime+0xfffffffffe8b8b20>
 *   @0x308dc0 .word 0xf1c2f284
 *   @0x308dc4 bne 0xff7c96c4 <b2_toiTime+0xffffffffff070220>
 *   @0x308dc8 vstrle d2, [r2, #-180]
 *   @0x308dcc ldreq r9, [r3], #-2562
 *   @0x308dd0 strtmi lr, [r8], -r4
 *   @0x308dd4 .word 0xf7fe4621
 *   @0x308dd8 strmi pc, [r3], -r9, ror #20
 *   @0x308ddc andmi lr, r11, pc, asr #20
 *   @0x308de0 ble 0x3997f4 <ft_adobe_glyph_list+0x8ed0>
 *   @0x308de4 andmi lr, r10, pc, asr #20
 *   @0x308de8 bls 0x380f34 <_ZTS13C_UTF16String+0x17fe0>
 *   @0x308dec .word 0x4c02ea4f
 *   @0x308df0 ble 0xb1a384 <b2_toiTime+0x3c0ee0>
 *   @0x308df4 bleq 0x3c3d28 <error_g0017+0x1c9cc>
 *   @0x308df8 .word 0xf8cd4621
 *   @0x308dfc .word 0xf7dcc000
 *   @0x308e00 .word 0xf8ddf85a
 *   @0x308e04 .word 0xf1bbc000
 *   @0x308e08 .word 0xd10a0f00
 *   @0x308e0c strbtmi r9, [r0], -r1, lsl #22
 *   @0x308e10 bl 0xff3da69c <b2_toiTime+0xfffffffffec811f8>
 *   @0x308e14 .word 0xf7dc0a06
 *   @0x308e18 .word 0xf1baf84e
 *   @0x308e1c andsle r0, r1, r0, lsl #30
 *   @0x308e20 bne 0xd40ebc <b2_toiTime+0x5e7a18>
 *   @0x308e24 smlabteq r9, r10, r11, lr
 *   @0x308e28 .word 0xf7db465a
 *   @0x308e2c strmi pc, [r5], -r7, lsl #31
 *   @0x308e30 andmi lr, r10, pc, asr #20
 *   @0x308e34 bl 0xff000ecc <b2_toiTime+0xfffffffffe8a7a28>
 *   @0x308e38 blle 0xffcdca58 <b2_toiTime+0xffffffffff5835b4>
 *   @0x308e3c bl 0xfefef64c <b2_toiTime+0xfffffffffe8961a8>
 *   @0x308e40 ble 0xb9ca50 <b2_toiTime+0x4435ac>
 *   @0x308e44 ldrteq r9, [r0], #-2562
 *   @0x308e48 bl 0xff49a6d4 <b2_toiTime+0xfffffffffed41230>
 *   @0x308e4c .word 0xf7dc0902
 *   @0x308e50 .word 0xf1b9f832
 *   @0x308e54 andsle r0, r8, r0, lsl #30
 *   @0x308e58 bne 0xd2fa6c <b2_toiTime+0x5d65c8>
 *   @0x308e5c bl 0xff51a78c <b2_toiTime+0xfffffffffedc12e8>
 *   @0x308e60 .word 0xf7db0103
 *   @0x308e64 strmi pc, [r5], -r11, ror #30
 *   @0x308e68 andmi lr, r8, pc, asr #20
 *   @0x308e6c bne 0xd40e94 <b2_toiTime+0x5e79f0>
 *   @0x308e70 smlabteq r8, r9, r11, lr
 *   @0x308e74 .word 0xf7db4652
 *   @0x308e78 strmi pc, [r5], -r1, ror #30
 *   @0x308e7c andmi lr, r9, pc, asr #20
 *   @0x308e80 .word 0xf7dc4621
 *   @0x308e84 strtmi pc, [r8], #-2072
 *   @0x308e88 bls 0x400ea0 <g_RomDisk+0x9680>
 *   @0x308e8c qadd16mi r0, r1, r0
 *   @0x308e90 .word 0xf811f7dc
 *   @0x308e94 .word 0xf7dc4639
 *   @0x308e98 .word 0xf500f80e
 *   @0x308e9c strne r4, [r0], #-0
 *   @0x308ea0 andhs lr, r0, r0
 *   @0x308ea4 pop {r0, r2, r12, sp, pc}
 *   @0x308ea8 strdeq r8, r9, [r0], -r0
 *   @0x308eac svcmi #0xf0e92d
 *   @0x308eb0 strmi r11, [r7], -r1, lsr #1
 *   @0x308eb4 strmi r4, [r8], -sp, lsl #12
 *   @0x308eb8 andls r4, sp, #17825792
 *   @0x308ebc .word 0xf7fe9306
 *   @0x308ec0 andls pc, r9, r7, asr #22
 *   @0x308ec4 .word 0xf0402800
 *   @0x308ec8 .word 0x9c0683d9
 *   @0x308ecc blhs 0x363560 <_ZTS12CDS_Priority+0x55b8>
 *   @0x308ed0 blo 0xff04722c <b2_toiTime+0xfffffffffe8edd88>
 *   @0x308ed4 ldreq sp, [lr, -r1, lsl #2]
 *   @0x308ed8 ldrbeq sp, [r12, r6, lsl #10]
 *   @0x308edc .word 0xf8d5d504
 *   @0x308ee0 .word 0x07983ab4
 *   @0x308ee4 ands sp, r12, r9, lsl r4
 *   @0x308ee8 strtmi r9, [r8], -r6, lsl #24
 *   @0x308eec blvs 0x1c912f4 <b2_toiTime+0x1537e50>
 *   @0x308ef0 stc2 p7, c15, [r2, #1016]!
 *   @0x308ef4 stmdahs r0, {r2, r9, r10, lr}
 *   @0x308ef8 .word 0x83b9f040
 *   @0x308efc strtmi r9, [r8], -r6, lsl #22
 *   @0x308f00 .word 0xf1034631
 *   @0x308f04 qasxmi r0, r3, r8
 *   @0x308f08 blx 0xa06f08 <b2_toiTime+0x2ada64>
 *   @0x308f0c strtmi r4, [r1], -r8, lsr #12
 *   @0x308f10 rfeia r8!
 *   @0x308f14 rscle r2, r2, r0, lsl #16
 *   @0x308f18 strls lr, [r7, #-0x3ab]
 *   @0x308f1c bleq 0x345060
 *   @0x308f20 .word 0x9c06e0ad
 *   @0x308f24 .word 0x21014628
 *   @0x308f28 ldrpl pc, [r0], -r4, lsl #10
 *   @0x308f2c ldreq pc, [r4], #-262
 *   @0x308f30 stmvs r4!, {r0, r2, r10, r12, pc}
 *   @0x308f34 stc2 p7, c15, [r0, #1016]
 *   @0x308f38 .word 0xf0402800
 *   @0x308f3c qadd8mi r8, r8, r10
 *   @0x308f40 .word 0xf1064621
 *   @0x308f44 movwhs r0, #0x1220
 *   @0x308f48 .word 0xf9fbf7fe
 *   @0x308f4c .word 0x21014628
 *   @0x308f50 .word 0xf898f7ff
 *   @0x308f54 .word 0xf0402800
 *   @0x308f58 .word 0x9c06838c
 *   @0x308f5c ldmvs r11, {r0, r1, r5, r6, r9, r11, sp, lr}
 *   @0x308f60 andslo pc, r7, r3, lsr r8
 *   @0x308f64 ldrble r0, [r8], #1113
 *   @0x308f68 strmi pc, [r4, #0x8d5]
 *   @0x308f6c .word 0xf8d5222c
 *   @0x308f70 .word 0xf8d6357c
 *   @0x308f74 stmdals r6, {r2, r4, sp, pc}
 *   @0x308f78 andmi pc, r3, #2048
 *   @0x308f7c .word 0xf500342c
 *   @0x308f80 andls r5, r8, r3, lsl r0
 *   @0x308f84 bls 0x4ed7a8 <SrcVerts+0x4a7ec>
 *   @0x308f88 msreq APSR_nzcvqg, #164, #2
 *   @0x308f8c stmible r4, {r1, r3, r4, r7, r9, lr} ^
 *   @0x308f90 strhs r9, [r0, -r6, lsl #18]
 *   @0x308f94 .word 0x46bb46b8
 *   @0x308f98 smlawbhs r8, r8, r10, r6
 *   @0x308f9c cdp p0, #0x5, c15, c4, c15, #0x0
 *   @0x308fa0 .word 0xf7fe4651
 *   @0x308fa4 bls 0x5475b8 <gp_ActiveMaskObjects+0x28f0>
 *   @0x308fa8 ldrteq pc, [r12], -r2, lsl #2
 *   @0x308fac svclt #0xb42820
 *   @0x308fb0 .word 0xf04f4681
 *   @0x308fb4 stmdals r5, {r5, r8, r11}
 *   @0x308fb8 ldrsblo pc, [r8], #128
 *   @0x308fbc subsle r4, r0, #650117120
 *   @0x308fc0 .word 0x07da6973
 *   @0x308fc4 .word 0xf8d5d549
 *   @0x308fc8 .word 0xf0131588
 *   @0x308fcc .word 0xf9140f06
 *   @0x308fd0 svclt #0xc0c1f
 *   @0x308fd4 .word 0x0c00f04f
 *   @0x308fd8 .word 0x0c01f04f
 *   @0x308fdc biceq pc, r0, #201326595
 *   @0x308fe0 submi r1, r1, #64, #20
 *   @0x308fe4 strbmi r4, [r1, #-0x141]!
 *   @0x308fe8 blhs 0x33d3f4
 *   @0x308fec .word 0xf856d035
 *   @0x308ff0 rfedb r4!
 *   @0x308ff4 movwls r0, #0x3c2c
 *   @0x308ff8 ldrbmi r1, [r1], -r0, asr #20
 *   @0x308ffc svclt #0xb82800
 *   @0x309000 .word 0xf8cd4240
 *   @0x309004 .word 0xf7fec010
 *   @0x309008 blls 0x407554 <g_RomDisk+0xfd34>
 *   @0x30900c ldrsbgt pc, [r0], -sp
 *   @0x309010 ble 0x3da538 <error_g0017+0x331dc>
 *   @0x309014 stmdaeq r12, {r1, r2, r5, r7, r8, r12, sp, lr, pc}
 *   @0x309018 ldrmi r4, [pc], -r1, lsl #13
 *   @0x30901c stcne p8, c15, [r0], #-80
 *   @0x309020 ldrle r0, [r10, #-0x7ca]
 *   @0x309024 stmiblt r3, {r3, r6, r7, r8, r12, sp, pc} ^
 *   @0x309028 .word 0x0c0cf856
 *   @0x30902c stcne p9, c15, [r12], #-208
 *   @0x309030 svclt #0xac4281
 *   @0x309034 andhs r2, r1, r0
 *   @0x309038 andle r4, lr, r0, ror #10
 *   @0x30903c movwls r6, #0x3830
 *   @0x309040 ldrbmi r1, [r1], -r8, lsl #20
 *   @0x309044 svclt #0xb82800
 *   @0x309048 .word 0xf7fe4240
 *   @0x30904c blls 0x407510 <g_RomDisk+0xfcf0>
 *   @0x309050 ble 0x39a578 <ft_adobe_glyph_list+0x9c54>
 *   @0x309054 ldrmi r4, [pc], -r1, lsl #13
 *   @0x309058 .word 0xf10b46b0
 *   @0x30905c strtlo r0, [r4], -r1, lsl #22
 *   @0x309060 .word 0xf1b8e7a9
 *   @0x309064 andle r0, r8, r0, lsl #30
 *   @0x309068 .word 0x8c18f844
 *   @0x30906c .word 0xf814b12f
 *   @0x309070 .word 0xf0433c20
 *   @0x309074 .word 0xf8040308
 *   @0x309078 strtlo r3, [r12], #-3104
 *   @0x30907c .word 0xf8d5e783
 *   @0x309080 .word 0xf1bb3ab4
 *   @0x309084 tstle r7, r0, lsl #30
 *   @0x309088 stmibvs r2!, {r1, r2, r10, r11, r12, pc}
 *   @0x30908c tstle r0, r1, lsl #20
 *   @0x309090 strle r0, [lr], #-1817
 *   @0x309094 ldmdage r1, {r4, r8, r9, r11, sp, pc}
 *   @0x309098 strtmi r9, [r9], -r0, lsl #6
 *   @0x30909c blge 0x6daa0c <g_SWFvertbuff+0x7944>
 *   @0x3090a0 ldc2 p5, c15, [r4, #700]
 *   @0x3090a4 ldrbmi r4, [r9], -r8, lsr #12
 *   @0x3090a8 blls 0x72f8ec <g_SWFvertbuff+0x5c824>
 *   @0x3090ac .word 0xfc09f5af
 *   @0x3090b0 .word 0xf013e2ce
 *   @0x3090b4 and r0, r1, r1, lsl #30
 *   @0x3090b8 svceq #0x2f013
 *   @0x3090bc sbchi pc, r8, #64
 *   @0x3090c0 eorhs r9, r12, #1792
 *   @0x3090c4 svceq #0x1f1bb
 *   @0x3090c8 .word 0x6c266ba3
 *   @0x3090cc andvs pc, r3, #2048
 *   @0x3090d0 ldrblo pc, [r8, #-0x8df]!
 *   @0x3090d4 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x3090d8 .word 0xf8d59205
 *   @0x3090dc ldmdavs r2, {r2, r3, r4, r5, r7, r9, r11, sp}
 *   @0x3090e0 .word 0xf8536892
 *   @0x3090e4 .word 0xd14b3022
 *   @0x3090e8 ssatmi r7, #0x11, r11, lsl #22
 *   @0x3090ec movwls r2, #0x8700
 *   @0x3090f0 strmi r9, [r0, #0xc05]!
 *   @0x3090f4 .word 0xf898d247
 *   @0x3090f8 .word 0xf003300c
 *   @0x3090fc .word 0xf0020204
 *   @0x309100 bhs 0x309504 <TT_New_Context+0x92fc>
 *   @0x309104 .word 0xf8d8d139
 *   @0x309108 .word 0xf8d82014
 *   @0x30910c .word 0xb1aa4018
 *   @0x309110 stmdbvs r2!, {r2, r5, r7, r8, r12, sp, pc} ^
 *   @0x309114 blvc 0xbb5764 <b2_toiTime+0x45c2c0>
 *   @0x309118 .word 0x0108f002
 *   @0x30911c cdpeq p0, #0xf, c15, c15, c1, #0x0
 *   @0x309120 .word 0xf022b121
 *   @0x309124 .word 0x61600208
 *   @0x309128 and r7, r7, r2, lsr #6
 *   @0x30912c strle r0, [r5, #-0x71a]
 *   @0x309130 movweq pc, #0x8023
 *   @0x309134 ands pc, r4, r8, asr #17
 *   @0x309138 andlo pc, r12, r8, lsl #17
 *   @0x30913c ldrsblo pc, [r4], -r8
 *   @0x309140 bicslt r11, r4, r11, lsr #18
 *   @0x309144 blhs 0x3236d8
 *   @0x309148 addshi pc, r5, #64
 *   @0x30914c .word 0x4642e015
 *   @0x309150 umullsvs r6, r3, r11, r8
 *   @0x309154 .word 0xf0437b13
 *   @0x309158 tstvc r3, #4, #6
 *   @0x30915c stmdbvs r3!, {r2, r4, r6, r8, r12, sp, pc} ^
 *   @0x309160 strtmi r11, [r3], -r3, asr #18
 *   @0x309164 .word 0x21014628
 *   @0x309168 ldc2 p5, c15, [pc], {175}
 *   @0x30916c .word 0xf0437b23
 *   @0x309170 .word 0x73230304
 *   @0x309174 svclt #0x82f00
 *   @0x309178 .word 0xf1084647
 *   @0x30917c ldr r0, [r7, r12, lsr #16]!
 *   @0x309180 strls r2, [r8], #-1024
 *   @0x309184 ldrtmi r4, [r4], -r7, lsr #12
 *   @0x309188 .word 0xf1a62000
 *   @0x30918c andls r0, r11, r12, lsr #2
 *   @0x309190 bls 0x46d5c0 <g_RomDisk+0x75da0>
 *   @0x309194 .word 0xf0804294
 *   @0x309198 blvc 0xba95bc <b2_toiTime+0x450118>
 *   @0x30919c cps #0x13
 *   @0x3091a0 .word 0xf8d48101
 *   @0x3091a4 .word 0xf1b88018
 *   @0x3091a8 .word 0xd1030f00
 *   @0x3091ac andlo r9, r1, #45056
 *   @0x3091b0 rscs r9, r7, r11, lsl #4
 *   @0x3091b4 ldrsblo pc, [r4], -r8
 *   @0x3091b8 qsaxmi r11, r3, r3
 *   @0x3091bc ldrbmi r4, [r9], -r8, lsr #12
 *   @0x3091c0 .word 0xf5af4642
 *   @0x3091c4 blvc 0xc08394 <b2_toiTime+0x4aeef0>
 *   @0x3091c8 movweq pc, #0x4043
 *   @0x3091cc rsc r7, r9, r3, lsr #6
 *   @0x3091d0 .word 0xa004f8d4
 *   @0x3091d4 .word 0xd1472f00
 *   @0x3091d8 .word 0x3004f8d8
 *   @0x3091dc andls r4, r0, #40, #12
 *   @0x3091e0 bl 0xff59ab4c <b2_toiTime+0xfffffffffee416a8>
 *   @0x3091e4 .word 0xf8980903
 *   @0x3091e8 strbmi r3, [r10], -r12
 *   @0x3091ec ldrtmi r9, [r11], -r1, lsl #6
 *   @0x3091f0 blx 0xfe5c68b6 <b2_toiTime+0xfffffffffde6d412>
 *   @0x3091f4 stcle p8, c2, [r4, #-256]
 *   @0x3091f8 stcle p8, c2, [r4], #-380
 *   @0x3091fc .word 0x2326211a
 *   @0x309200 .word 0x2120e001
 *   @0x309204 bl 0x59aa38 <g_SWFlineaavertbuff+0x47970>
 *   @0x309208 .word 0xf10a0a69
 *   @0x30920c .word 0xf0220220
 *   @0x309210 ldrmi r0, [r1], #-575
 *   @0x309214 ldrbmi r1, [r7], #-2719
 *   @0x309218 beq 0x5c4124 <g_SWFlineaavertbuff+0x7105c>
 *   @0x30921c svclt #0xb82f00
 *   @0x309220 .word 0xf1ba427f
 *   @0x309224 svclt #0xb80f00
 *   @0x309228 beq 0x345958
 *   @0x30922c svclt #0xb84557
 *   @0x309230 smlabteq r2, r3, r11, lr
 *   @0x309234 bicsvc lr, r0, #0, #22
 *   @0x309238 smultbeq r3, r1, r11
 *   @0x30923c strmi r6, [r1], #-161
 *   @0x309240 andne pc, r8, r8, asr #17
 *   @0x309244 .word 0xf10ae004
 *   @0x309248 .word 0xf02a0a20
 *   @0x30924c adcvs r0, r3, pc, lsr r3
 *   @0x309250 strtmi r7, [r8], -r3, lsr #22
 *   @0x309254 qsaxmi r4, r2, r9
 *   @0x309258 movweq pc, #0x4043
 *   @0x30925c strbmi r7, [r3], -r3, lsr #6
 *   @0x309260 .word 0xf5af4627
 *   @0x309264 adds pc, sp, r2, lsr #24
 *   @0x309268 ldmvs r8!, {r0, r3, r4, r5, r6, r11, sp, lr}
 *   @0x30926c smlabteq r10, r1, r11, lr
 *   @0x309270 .word 0x0c00eb01
 *   @0x309274 .word 0x1004f8d8
 *   @0x309278 muleq r12, r8, r8
 *   @0x30927c beq 0x3841ac <_ZTS13C_UTF16String+0x1b258>
 *   @0x309280 ldrbmi r9, [r9], -r0, lsl #4
 *   @0x309284 andsgt pc, r0, sp, asr #17
 *   @0x309288 ldrbmi r9, [r2], -r12
 *   @0x30928c strtmi r9, [r8], -r1
 *   @0x309290 stmdbeq r10!, {r2, r3, r8, r9, r11, sp, lr, pc} ^
 *   @0x309294 blx 0x114695a <b2_toiTime+0x9ed4b6>
 *   @0x309298 .word 0xf8dd990c
 *   @0x30929c .word 0xf011c010
 *   @0x3092a0 andle r0, r4, r4, lsl #30
 *   @0x3092a4 .word 0x3008f8d8
 *   @0x3092a8 adcvs r1, r0, r8, lsl r10
 *   @0x3092ac ldmdahs pc, {r2, r3, r6, sp, lr, pc} ^
 *   @0x3092b0 stmdahs r0, {r0, r2, r5, r10, r11, r12, lr, pc} ^
 *   @0x3092b4 .word 0x0120f109
 *   @0x3092b8 teqeq pc, r1, lsr #32
 *   @0x3092bc sbcsvc lr, r0, r0, lsl #22
 *   @0x3092c0 .word 0x2320bfd5
 *   @0x3092c4 ldrmi r2, [r10], -r6, lsr #4
 *   @0x3092c8 bl 0xff351f38 <b2_toiTime+0xfffffffffebf8a94>
 *   @0x3092cc strmi r0, [r11], #-3586
 *   @0x3092d0 bl 0xff3da610 <b2_toiTime+0xfffffffffec8116c>
 *   @0x3092d4 .word 0xf1be0909
 *   @0x3092d8 svclt #0xb80f00
 *   @0x3092dc cdpeq p1, #0x0, c15, c0, c14, #0x6
 *   @0x3092e0 svceq #0xf1b9
 *   @0x3092e4 .word 0xf1c9bfb8
 *   @0x3092e8 strbmi r0, [lr, #0x900]
 *   @0x3092ec bl 0xff3b91d4 <b2_toiTime+0xfffffffffec5fd30>
 *   @0x3092f0 bl 0xfebc9efc <b2_toiTime+0xfffffffffe470a58>
 *   @0x3092f4 bl 0x3c9c7c <error_g0017+0x22920>
 *   @0x3092f8 adcvs r0, r2, r0, rrx
 *   @0x3092fc strbtmi lr, [r2], #34
 *   @0x309300 eoreq pc, r0, #12, #2
 *   @0x309304 beq 0xb45734 <b2_toiTime+0x3ec290>
 *   @0x309308 .word 0xf02a1041
 *   @0x30930c .word 0xf0220a3f
 *   @0x309310 bl 0xff309c14 <b2_toiTime+0xfffffffffebb0770>
 *   @0x309314 bl 0x38bb44 <_pcre_default_tables+0x9c>
 *   @0x309318 ldrbmi r0, [r1], #-3585
 *   @0x30931c vmlseq.f64 d14, d30, d9
 *   @0x309320 stmdbeq r1, {r0, r3, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x309324 svceq #0xf1be
 *   @0x309328 .word 0xf1cebfb8
 *   @0x30932c .word 0xf1b90e00
 *   @0x309330 svclt #0xb80f00
 *   @0x309334 stmdbeq r0, {r0, r3, r6, r7, r8, r12, sp, lr, pc}
 *   @0x309338 svclt #0xac45ce
 *   @0x30933c ssaxmi r4, r3, r3
 *   @0x309340 ldrmi r6, [r8], #-163
 *   @0x309344 andeq pc, r8, r8, asr #17
 *   @0x309348 adcsmi r7, r4, #35840
 *   @0x30934c movweq pc, #0x4043
 *   @0x309350 .word 0xf8987323
 *   @0x309354 .word 0xf043300c
 *   @0x309358 .word 0xf8880304
 *   @0x30935c stmdble r1!, {r2, r3, r12, sp}
 *   @0x309360 blne 0xfebaf388 <b2_toiTime+0xfffffffffe455ee4>
 *   @0x309364 teqlt r8, r3, lsr #17
 *   @0x309368 strmi r9, [r10], #-2314
 *   @0x30936c addsmi r6, r3, #9568256
 *   @0x309370 movwhs r11, #0xfd4
 *   @0x309374 and r2, r6, r1, lsl #6
 *   @0x309378 strmi r9, [r2], #-2058
 *   @0x30937c addsmi r6, r3, #9568256
 *   @0x309380 movwhs r11, #0xfac
 *   @0x309384 .word 0xb16b2301
 *   @0x309388 cmplt r10, r2, lsr #19
 *   @0x30938c blne 0xfebef7bc <b2_toiTime+0xfffffffffe496318>
 *   @0x309390 strmi r6, [r11], #-2194
 *   @0x309394 bne 0xff7a3608 <b2_toiTime+0xffffffffff04a164>
 *   @0x309398 svclt #0xb82a00
 *   @0x30939c bhs 0x719cec <g_SWFvertbuff+0x46c24>
 *   @0x3093a0 adcvs r11, r3, r8, asr #31
 *   @0x3093a4 ldrbt r3, [r4], r12, lsr #8
 *   @0x3093a8 svceq #0xf1bb
 *   @0x3093ac blne 0xfe7bd8cc <b2_toiTime+0xfffffffffe064428>
 *   @0x3093b0 addsne r4, r2, r5, lsr #23
 *   @0x3093b4 bhs 0x49a124 <TimingData+0x10c>
 *   @0x3093b8 bhs 0x63d3e0 <g_SWFaavertbuff+0x6a318>
 *   @0x3093bc .word 0xf106d13e
 *   @0x3093c0 .word 0xf106012c
 *   @0x3093c4 .word 0xf5060edc
 *   @0x3093c8 and r7, r4, r6, asr #7
 *   @0x3093cc cdpeq p1, #0x5, c15, c8, c6, #0x0
 *   @0x3093d0 movseq pc, #2147483649
 *   @0x3093d4 .word 0xf8de4631
 *   @0x3093d8 stmdavs r12, {r2, lr, pc} ^
 *   @0x3093dc stmdaeq r12, {r2, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x3093e0 bl 0xff623558 <b2_toiTime+0xfffffffffeeca0b4>
 *   @0x3093e4 bl 0xff3093fc <b2_toiTime+0xfffffffffebaff58>
 *   @0x3093e8 stmdahs r0, {r3}
 *   @0x3093ec submi r11, r0, #184, #30
 *   @0x3093f0 stcle p8, c2, [r3], #-28
 *   @0x3093f4 .word 0xf8de6889
 *   @0x3093f8 ldmibvs r12, {r3}
 *   @0x3093fc subeq lr, r0, r1, lsr #23
 *   @0x309400 strmi r6, [r1], #-2201
 *   @0x309404 addsvs r4, r8, r0, asr #4
 *   @0x309408 stmvs r0!, {r2, r4, r8, r12, sp, pc}
 *   @0x30940c adcvs r1, r0, r0, asr #20
 *   @0x309410 .word 0xd1092a0c
 *   @0x309414 .word 0x2168f8d6
 *   @0x309418 .word 0xf8c61a52
 *   @0x30941c .word 0xf8d62168
 *   @0x309420 bne 0x1751bd8 <b2_toiTime+0xff8734>
 *   @0x309424 mvnne pc, r6, asr #17
 *   @0x309428 .word 0xf0427b1a
 *   @0x30942c tstvc r10, #4, #4
 *   @0x309430 .word 0xb11b699b
 *   @0x309434 .word 0xf0427b1a
 *   @0x309438 tstvc r10, #4, #4
 *   @0x30943c ldmdblt r12, {r0, r1, r3, r10, r11, r12, pc} ^
 *   @0x309440 .word 0x9c07b157
 *   @0x309444 blvs 0x1bd18fc <b2_toiTime+0x1478458>
 *   @0x309448 blx 0x363fda <_ZTS12CDS_Priority+0x6032>
 *   @0x30944c .word 0xf1bb3102
 *   @0x309450 .word 0xf0000f00
 *   @0x309454 sbcs r8, r12, r12, asr #1
 *   @0x309458 strteq pc, [r12], #-262
 *   @0x30945c ldmdaeq r8!, {r1, r2, r8, r12, sp, lr, pc}
 *   @0x309460 stceq p1, c15, [r12], #-664
 *   @0x309464 bls 0x45aef4 <g_RomDisk+0x636d4>
 *   @0x309468 stmdbeq r12!, {r2, r5, r7, r8, r12, sp, lr, pc}
 *   @0x30946c rscle r4, r8, #608174080
 *   @0x309470 stclo p8, c15, [r0], #-80
 *   @0x309474 cps #0x18
 *   @0x309478 .word 0xf85480b5
 *   @0x30947c cmnlt r3, r0, lsl r12
 *   @0x309480 .word 0xf854685a
 *   @0x309484 bne 0x171052c <b2_toiTime+0xfb7088>
 *   @0x309488 svclt #0xb82800
 *   @0x30948c stmdahs pc, {r6, r9, lr} ^
 *   @0x309490 bne 0xfe5c04ac <b2_toiTime+0xfffffffffde67008>
 *   @0x309494 strmi r6, [r10], #-2201
 *   @0x309498 stchs p8, c15, [r4], #-272
 *   @0x30949c stmdblt r7, {r3, r6, sp, lr, pc} ^
 *   @0x3094a0 stclo p8, c15, [r8], #-336
 *   @0x3094a4 .word 0x3320464f
 *   @0x3094a8 teqeq pc, #35
 *   @0x3094ac stclo p8, c15, [r4], #-272
 *   @0x3094b0 .word 0xf1a4e03e
 *   @0x3094b4 adcsmi r0, r3, #88, #6
 *   @0x3094b8 blvc 0x9be0c8 <b2_toiTime+0x264c24>
 *   @0x3094bc strle r0, [r1, #-0x751]
 *   @0x3094c0 and r4, r5, r1, lsr #12
 *   @0x3094c4 ldrb r3, [r6, r12, lsr #22]!
 *   @0x3094c8 ldrbeq r7, [r2, -r10, lsl #22]
 *   @0x3094cc .word 0x312cd403
 *   @0x3094d0 addmi r9, r1, #327680
 *   @0x3094d4 adcsmi sp, r3, #248, #6
 *   @0x3094d8 strbmi sp, [r11, #-0x31f]
 *   @0x3094dc bls 0x47dd58 <targetStr+0x2b18>
 *   @0x3094e0 andsle r4, r10, #268435465
 *   @0x3094e4 ldmdble r8, {r0, r3, r6, r8, r10, lr}
 *   @0x3094e8 .word 0xf8d1685a
 *   @0x3094ec ldmvs r11, {r2, sp, lr, pc}
 *   @0x3094f0 mulsle r11, r6, r5
 *   @0x3094f4 stceq p8, c15, [r8], #-336
 *   @0x3094f8 bne 0xfe323724 <b2_toiTime+0xfffffffffdbca280>
 *   @0x3094fc andeq lr, lr, #198656
 *   @0x309500 movwls r1, #0x3ac9
 *   @0x309504 andsgt pc, r0, sp, asr #17
 *   @0x309508 .word 0xfc18f7db
 *   @0x30950c ldrmi r9, [r8], #-2819
 *   @0x309510 stceq p8, c15, [r4], #-272
 *   @0x309514 ldrsbgt pc, [r0], -sp
 *   @0x309518 ldmdavs r11!, {r1, r3, sp, lr, pc} ^
 *   @0x30951c stchs p8, c15, [r8], #-336
 *   @0x309520 ldmvs r11!, {r1, r4, r6, r7, r9, r11, r12}
 *   @0x309524 .word 0xf0223210
 *   @0x309528 ldrmi r0, [r3], #-543
 *   @0x30952c stclo p8, c15, [r4], #-272
 *   @0x309530 stclo p8, c15, [r0], #-80
 *   @0x309534 .word 0xf04345b1
 *   @0x309538 .word 0xf8040304
 *   @0x30953c stmdble r7!, {r5, r10, r11, r12, sp}
 *   @0x309540 bl 0xff5b0168 <b2_toiTime+0xfffffffffee56cc4>
 *   @0x309544 strbtmi r0, [r2], #-520
 *   @0x309548 .word 0xf854b143
 *   @0x30954c .word 0xf8523c24
 *   @0x309550 addsmi r2, r3, #4, #24
 *   @0x309554 movwhs r11, #0xfd4
 *   @0x309558 and r2, r7, r1, lsl #6
 *   @0x30955c stclo p8, c15, [r4], #-336
 *   @0x309560 .word 0x2c04f852
 *   @0x309564 svclt #0xac4293
 *   @0x309568 movwhs r2, #0x1300
 *   @0x30956c .word 0xf854b183
 *   @0x309570 .word 0xb16a2c14
 *   @0x309574 movweq lr, #0x8bca
 *   @0x309578 strbtmi r6, [r3], #-2194
 *   @0x30957c .word 0x3c04f853
 *   @0x309580 bhs 0x3100d0 <af_shaper_get_elem+0x593e>
 *   @0x309584 subsmi r11, r2, #184, #30
 *   @0x309588 svclt #0xc82a10
 *   @0x30958c stclo p8, c15, [r4], #-272
 *   @0x309590 addmi r9, r4, #327680
 *   @0x309594 .word 0xf898d226
 *   @0x309598 ldrbeq r3, [r11, -r0]
 *   @0x30959c stmdbls r8, {r1, r5, r8, r10, r12, lr, pc}
 *   @0x3095a0 stchs p8, c15, [r4], #-336
 *   @0x3095a4 .word 0x3c04f858
 *   @0x3095a8 addsmi r11, r10, #1073741832
 *   @0x3095ac movwhs r11, #0xfac
 *   @0x3095b0 and r2, r3, r1, lsl #6
 *   @0x3095b4 svclt #0xd4429a
 *   @0x3095b8 movwhs r2, #0x1300
 *   @0x3095bc .word 0xf854b193
 *   @0x3095c0 cmnlt r11, r4, lsl r12
 *   @0x3095c4 smlabteq r8, r10, r11, lr
 *   @0x3095c8 strbtmi r6, [r1], #-2202
 *   @0x3095cc .word 0x3c04f851
 *   @0x3095d0 blhs 0x310124 <af_shaper_get_elem+0x5992>
 *   @0x3095d4 subsmi r11, r11, #184, #30
 *   @0x3095d8 svclt #0xc42b10
 *   @0x3095dc .word 0x3c04f858
 *   @0x3095e0 stclo p8, c15, [r4], #-272
 *   @0x3095e4 .word 0xf108342c
 *   @0x3095e8 ldr r0, [r12, -r12, lsr #16]!
 *   @0x3095ec addmi r3, r11, #44, #6
 *   @0x3095f0 ldmvs r12, {r0, r4, r9, r12, lr, pc} ^
 *   @0x3095f4 rscsle r2, r9, r0, lsl #24
 *   @0x3095f8 bvs 0xfeaa3f68 <b2_toiTime+0xfffffffffe34aac4>
 *   @0x3095fc adcsmi r6, r2, #160, #16
 *   @0x309600 ldmdahi r0, {r4, r8, sp, lr}
 *   @0x309604 andeq pc, r4, r0, asr #32
 *   @0x309608 rscle r8, pc, r0, lsl r0
 *   @0x30960c .word 0xe7f56a12
 *   @0x309610 addmi r3, r11, #44, #6
 *   @0x309614 strtmi sp, [r8], -r8, lsl #6
 *   @0x309618 .word 0xf5af4659
 *   @0x30961c strtmi pc, [r8], -r5, ror #23
 *   @0x309620 .word 0xf5af4659
 *   @0x309624 ands pc, r3, r2, lsl #28
 *   @0x309628 .word 0x2c0068dc
 *   @0x30962c bvs 0x19bd9f4 <b2_toiTime+0x1264550>
 *   @0x309630 stmvs r0!, {r1, r2, r3, r4, r7, r9, r11, sp, lr}
 *   @0x309634 ldrhvs r4, [r0, #-34]
 *   @0x309638 .word 0xf0408810
 *   @0x30963c andshi r0, r0, r8
 *   @0x309640 bvs 0x7bd9e0 <b2_toiTime+0x6453c>
 *   @0x309644 svclt #0xe7f5
 *   @0x309648 blt 0xeac4dc <b2_toiTime+0x753038>
 *   @0x30964c andeq r8, lr, r0, lsl r11
 *   @0x309650 bleq 0x385a84 <_ZTS13C_UTF16String+0x1cb30>
 *   @0x309654 .word 0xf1bb9c07
 *   @0x309658 vmax.f32 d0, d4, d2
 *   @0x30965c strls r5, [r7], #-1092
 *   @0x309660 stcge p4, c15, [sp, #-508]
 *   @0x309664 stmdbls sp, {r3, r5, r9, r10, lr}
 *   @0x309668 mcr2 p7, #0x1, pc, c14, c13, #0x7
 *   @0x30966c andls lr, r9, r6
 *   @0x309670 andls lr, r9, r4
 *   @0x309674 strtmi lr, [r2], -r2
 *   @0x309678 strb r4, [r9, #-0x644]!
 *   @0x30967c eorlt r9, r1, r9, lsl #16
 *   @0x309680 svchi #0xf0e8bd
 *   @0x309684 svcmi #0xf0e92d
 *   @0x309688 .word 0x4608b09f
 *   @0x30968c ldrmi r4, [r1], -r12, lsl #12
 *   @0x309690 movwls r9, #0x920b
 *   @0x309694 .word 0xff5cf7fd
 *   @0x309698 stmdahs r0, {r3, r12, pc}
 *   @0x30969c eorhi pc, r9, #64
 *   @0x3096a0 ldmibvs r3!, {r0, r3, r9, r10, r11, r12, pc}
 *   @0x3096a4 .word 0xf8d42b01
 *   @0x3096a8 strhle r3, [r1, -r4]
 *   @0x3096ac strle r0, [r1, #-0x71a]
 *   @0x3096b0 strle r0, [r11], #-2011
 *   @0x3096b4 .word 0x21004620
 *   @0x3096b8 .word 0xf902f7ff
 *   @0x3096bc stmdahs r0, {r1, r9, r10, lr}
 *   @0x3096c0 mvnshi pc, r0, asr #32
 *   @0x3096c4 stmdbls r9, {r5, r9, r10, lr}
 *   @0x3096c8 mrc2 p7, #0x1, apsr_nzcv, c6, c14, #0x7
 *   @0x3096cc blo 0xff047a24 <b2_toiTime+0xfffffffffe8ee580>
 *   @0x3096d0 strle r0, [r11], #-1951
 *   @0x3096d4 .word 0x21014620
 *   @0x3096d8 .word 0xf8f2f7ff
 *   @0x3096dc .word 0xf0402800
 *   @0x3096e0 strtmi r8, [r0], -r4, ror #3
 *   @0x3096e4 andhs r9, r1, #147456
 *   @0x3096e8 mcr2 p7, #0x1, pc, c6, c14, #0x7
 *   @0x3096ec strhs r4, [r0, -r1, lsr #13]
 *   @0x3096f0 blo 0xff047a48 <b2_toiTime+0xfffffffffe8ee5a4>
 *   @0x3096f4 bfieq r11, r7, #18, #13
 *   @0x3096f8 bic sp, r9, r3, lsl #10
 *   @0x3096fc ldrle r0, [r5, #-0x79d]
 *   @0x309700 cdpls p1, #0x0, c14, c9, c6, #0x6
 *   @0x309704 bhs 0x363dd4 <_ZTS12CDS_Priority+0x5e2c>
 *   @0x309708 .word 0x0718d110
 *   @0x30970c blge 0x6be74c <g_SWFlinevertbuff+0x6b684>
 *   @0x309710 movwls r10, #0x80f
 *   @0x309714 ldrtmi r4, [r10], -r1, lsr #12
 *   @0x309718 .word 0xf5afab0d
 *   @0x30971c qsaxmi pc, r0, r7
 *   @0x309720 bls 0x65b00c <g_SWFlinevertbuff+0x7f44>
 *   @0x309724 .word 0xf5af9b0e
 *   @0x309728 .word 0xe1b1f8cc
 *   @0x30972c .word 0x5040f8d9
 *   @0x309730 .word 0xf8d9222c
 *   @0x309734 .word 0xf04f3038
 *   @0x309738 strtmi r0, [lr], -r0, lsl #24
 *   @0x30973c andpl pc, r3, #2048
 *   @0x309740 stmdals r7, {r0, r1, r2, r9, r12, pc}
 *   @0x309744 eorsle r4, r6, #1610612744
 *   @0x309748 smmlareq r9, r3, r11, r7
 *   @0x30974c ldmdbvs r3!, {r0, r4, r5, r10, r12, lr, pc} ^
 *   @0x309750 stmdblt r11!, {r1, r4, r5, r7, r8, r11, sp, lr}
 *   @0x309754 ldmdbvs r3, {r1, r3, r5, r6, r8, r9, r12, sp, pc} ^
 *   @0x309758 .word 0xf0402b00
 *   @0x30975c eor r8, r8, r8, lsr #3
 *   @0x309760 shadd8mi r4, r2, r0
 *   @0x309764 .word 0xa008f8d3
 *   @0x309768 .word 0xf8c27b13
 *   @0x30976c .word 0xf043a008
 *   @0x309770 tstvc r3, #4, #6
 *   @0x309774 svceq #0xf1b8
 *   @0x309778 .word 0xf8d8d017
 *   @0x30977c stmiblt r3!, {r2, r4, r12, sp}
 *   @0x309780 .word 0x3004f8d8
 *   @0x309784 ldmdavs r2, {r5, r9, r10, lr} ^
 *   @0x309788 .word 0xf8cd4639
 *   @0x30978c bne 0xfe9b97e4 <b2_toiTime+0xfffffffffe260340>
 *   @0x309790 blx 0xffac6e56 <b2_toiTime+0xffffffffff36d9b2>
 *   @0x309794 mullo r12, r8, r8
 *   @0x309798 movweq pc, #0x4043
 *   @0x30979c andlo pc, r12, r8, lsl #17
 *   @0x3097a0 .word 0xf8c84450
 *   @0x3097a4 .word 0xf8dd0008
 *   @0x3097a8 .word 0xf1bcc014
 *   @0x3097ac svclt #0x80f00
 *   @0x3097b0 .word 0x362c46b4
 *   @0x3097b4 movwhs lr, #0x7c5
 *   @0x3097b8 ldrmi r4, [r11], lr, lsr #12
 *   @0x3097bc movwls r9, #0x6303
 *   @0x3097c0 stmdals r7, {r1, r3, r8, r9, r12, pc}
 *   @0x3097c4 rsbsle r4, r0, #1610612744
 *   @0x3097c8 mulge r12, r6, r8
 *   @0x3097cc svceq #0x4f01a
 *   @0x3097d0 .word 0xf8d6d169
 *   @0x3097d4 .word 0xf1b88018
 *   @0x3097d8 andle r0, r11, r0, lsl #30
 *   @0x3097dc .word 0xb1639b06
 *   @0x3097e0 ldmvs r1!, {r0, r1, r8, r9, r11, r12, pc}
 *   @0x3097e4 eorseq pc, pc, #-1073741824
 *   @0x3097e8 ble 0x3da218 <error_g0017+0x32ebc>
 *   @0x3097ec .word 0x1008f8d8
 *   @0x3097f0 blle 0x39a220 <ft_adobe_glyph_list+0x98fc>
 *   @0x3097f4 bleq 0x385c28 <_ZTS13C_UTF16String+0x1ccd4>
 *   @0x3097f8 .word 0xf8d8e055
 *   @0x3097fc orrslt r2, r2, r4, lsl r0
 *   @0x309800 .word 0x2004f8d8
 *   @0x309804 ldmdavs r3!, {r5, r9, r10, lr} ^
 *   @0x309808 .word 0xf8cd4639
 *   @0x30980c .word 0xf04ac014
 *   @0x309810 bne 0xfe98c028 <b2_toiTime+0xfffffffffe232b84>
 *   @0x309814 blx 0xfea46eda <b2_toiTime+0xfffffffffe2eda36>
 *   @0x309818 .word 0x2008f8d8
 *   @0x30981c andge pc, r12, r6, lsl #17
 *   @0x309820 adcsvs r4, r0, r0, lsl r4
 *   @0x309824 ldrmi lr, [r0, #0x16]!
 *   @0x309828 .word 0xf8d8d217
 *   @0x30982c strtmi r2, [r0], -r4
 *   @0x309830 shsub16mi r6, r9, r3
 *   @0x309834 andsgt pc, r4, sp, asr #17
 *   @0x309838 beq 0x445968 <g_RomDisk+0x4e148>
 *   @0x30983c .word 0xf5af1a9a
 *   @0x309840 .word 0xf8d8fb87
 *   @0x309844 .word 0xf8863008
 *   @0x309848 strmi r10, [r3], #-12
 *   @0x30984c adcsvs r9, r3, r3, lsl #6
 *   @0x309850 movwls r2, #0x6301
 *   @0x309854 ldrsbgt pc, [r4], -sp
 *   @0x309858 svchs #0x1e025
 *   @0x30985c .word 0xf1bcd00c
 *   @0x309860 .word 0xd1090f00
 *   @0x309864 andgt pc, r0, sp, asr #17
 *   @0x309868 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x30986c strbtmi r4, [r3], -r2, asr #12
 *   @0x309870 .word 0xfc00f5af
 *   @0x309874 and r9, r6, r10
 *   @0x309878 strtmi r9, [r0], -r0, lsl #14
 *   @0x30987c .word 0x46424631
 *   @0x309880 .word 0xf5af9b0a
 *   @0x309884 blvc 0x1008868 <b2_toiTime+0x8af3c4>
 *   @0x309888 .word 0xf04346b4
 *   @0x30988c teqvc r3, #4, #6
 *   @0x309890 mullo r12, r8, r8
 *   @0x309894 movweq pc, #0x4043
 *   @0x309898 andlo pc, r12, r8, lsl #17
 *   @0x30989c .word 0x3008f8d8
 *   @0x3098a0 movwhs r9, #0x1303
 *   @0x3098a4 strtlo r9, [r12], -r6, lsl #6
 *   @0x3098a8 svchs #0xe78b
 *   @0x3098ac bl 0xff47de18 <b2_toiTime+0xfffffffffed24974>
 *   @0x3098b0 ldmibmi r2, {r9, r10, r11}
 *   @0x3098b4 .word 0x0eaeea4f
 *   @0x3098b8 .word 0xfe0efb01
 *   @0x3098bc svceq #0x6f1be
 *   @0x3098c0 .word 0xf1bed009
 *   @0x3098c4 .word 0xd14c0f0c
 *   @0x3098c8 eoreq pc, r12, #1073741825
 *   @0x3098cc bicseq pc, r12, r5, lsl #2
 *   @0x3098d0 bicvc pc, r6, #20971520
 *   @0x3098d4 .word 0xf105e004
 *   @0x3098d8 .word 0xf1050158
 *   @0x3098dc .word 0x462a03b0
 *   @0x3098e0 .word 0xc004f8d1
 *   @0x3098e4 bl 0xff4a3a44 <b2_toiTime+0xfffffffffed4a5a0>
 *   @0x3098e8 ldmdavs lr, {r2, r3, r11} ^
 *   @0x3098ec andeq lr, r6, r12, asr #23
 *   @0x3098f0 streq lr, [r8], -r0, asr #23
 *   @0x3098f4 cps #0x10
 *   @0x3098f8 cdphs p8, #0x0, c0, c0, c12, #0x1
 *   @0x3098fc rsbsmi r11, r6, #184, #30
 *   @0x309900 .word 0xd12e4540
 *   @0x309904 .word 0xf1016988
 *   @0x309908 strbmi r0, [r0, #-0x82c]
 *   @0x30990c ldmibvs r8, {r0, r3, r5, r8, r12, lr, pc}
 *   @0x309910 stmdaeq r12!, {r0, r1, r8, r12, sp, lr, pc}
 *   @0x309914 .word 0xd1244540
 *   @0x309918 stcle p14, c2, [r2], #-28
 *   @0x30991c ldmvs r2, {r0, r3, r7, r11, sp, lr}
 *   @0x309920 subeq lr, r1, #165888
 *   @0x309924 ldrmi r6, [r1], #-2201
 *   @0x309928 addsvs r4, r10, r2, asr r2
 *   @0x30992c stmvs r2, {r4, r8, r12, sp, pc}
 *   @0x309930 addvs r1, r2, r2, asr r10
 *   @0x309934 svceq #0xcf1be
 *   @0x309938 .word 0xf8d5d109
 *   @0x30993c bne 0x1791ee4 <b2_toiTime+0x1038a40>
 *   @0x309940 smulbths r8, r5, r8
 *   @0x309944 .word 0x21ecf8d5
 *   @0x309948 .word 0xf8c51a51
 *   @0x30994c blvc 0x98e104 <b2_toiTime+0x234c60>
 *   @0x309950 andeq pc, r4, #66
 *   @0x309954 ldmibvs r11, {r1, r3, r4, r8, r9, r12, sp, lr}
 *   @0x309958 blvc 0x9b5dcc <b2_toiTime+0x25c928>
 *   @0x30995c andeq pc, r4, #66
 *   @0x309960 .word 0xf1bb731a
 *   @0x309964 andsle r0, r2, r0, lsl #30
 *   @0x309968 and r4, r3, r11, lsr #12
 *   @0x30996c .word 0x07727b1e
 *   @0x309970 .word 0x332cd51b
 *   @0x309974 adcsmi r9, r3, #7, #28
 *   @0x309978 .word 0xf1bbd3f8
 *   @0x30997c andle r0, r6, r0, lsl #30
 *   @0x309980 strteq pc, [r12], -r5, lsl #2
 *   @0x309984 .word 0xf1a69b07
 *   @0x309988 addsmi r0, r9, #44, #2
 *   @0x30998c .word 0xf8d9d31c
 *   @0x309990 strhs r3, [r12, #-0x40]!
 *   @0x309994 ldrsbths pc, [r8], -r9
 *   @0x309998 bvs 0xff147cf0 <b2_toiTime+0xfffffffffe9ee84c>
 *   @0x30999c vmlalo.f64 d15, d2, d5
 *   @0x3099a0 teqle r1, r0, lsl #30
 *   @0x3099a4 streq pc, [r1], -r6
 *   @0x3099a8 ldmibvs r10, {r4, r5, sp, lr, pc} ^
 *   @0x3099ac rscle r2, r0, r0, lsl #20
 *   @0x3099b0 .word 0xf0466851
 *   @0x3099b4 ldmdavs r8, {r2, r9, r10} ^
 *   @0x3099b8 bllo 0x305dec <TT_New_Context+0x5be4>
 *   @0x3099bc ldmvs r0, {r0, r6, r9, r11, r12}
 *   @0x3099c0 strmi r7, [r1], #-798
 *   @0x3099c4 bfi r6, r9, #1, #20
 *   @0x3099c8 stclo p8, c15, [r0], #-88
 *   @0x3099cc ldrle r0, [r9], #-1880
 *   @0x3099d0 stmdalo r12!, {r3, r9, r10, lr}
 *   @0x3099d4 movwle r4, #0x62a8
 *   @0x3099d8 ldrbeq r7, [r10, -r3, lsl #22]
 *   @0x3099dc ldrb sp, [r8, r3, lsl #8]!
 *   @0x3099e0 ldrbeq r7, [r11, -r11, lsl #22]
 *   @0x3099e4 bls 0x4fe9fc <SrcVerts+0x5ba40>
 *   @0x3099e8 addsmi r3, r1, #44, #2
 *   @0x3099ec .word 0xe060d3f8
 *   @0x3099f0 rsble r4, r6, #168, #4
 *   @0x3099f4 stchs p8, c15, [r8], #-344
 *   @0x3099f8 bne 0xff7e3b2c <b2_toiTime+0xffffffffff08a688>
 *   @0x3099fc ldrmi r6, [r3], #-2186
 *   @0x309a00 stclo p8, c15, [r4], #-280
 *   @0x309a04 ldr r3, [sp, r12, lsr #12]!
 *   @0x309a08 strbeq pc, [r0], -r6, asr #7
 *   @0x309a0c ldrbmi r11, [r3, #-0x2f6]!
 *   @0x309a10 bvs 0x19be2f0 <b2_toiTime+0x1264e4c>
 *   @0x309a14 bvs 0x17360d4 <b2_toiTime+0xfdcc30>
 *   @0x309a18 stmdahi r1, {r0, r2, r3, r4, r7, r11, sp, lr}
 *   @0x309a1c .word 0x6105b91f
 *   @0x309a20 .word 0x0104f041
 *   @0x309a24 .word 0xf041e002
 *   @0x309a28 mrsvs r0, spsr
 *   @0x309a2c bvs 0xfe769a38 <b2_toiTime+0xfffffffffe010594>
 *   @0x309a30 andle r4, r1, r8, lsl #5
 *   @0x309a34 strb r6, [pc, r0, lsl #20]!
 *   @0x309a38 bvs 0x1963e88 <b2_toiTime+0x120a9e4>
 *   @0x309a3c mvnle r4, r10, lsl #5
 *   @0x309a40 ldmvs r8, {r2, r3, r4, sp, lr, pc}
 *   @0x309a44 bne 0x1323bb0 <b2_toiTime+0xbca70c>
 *   @0x309a48 rfeia r5!
 *   @0x309a4c stmdblt pc!, {lr, pc}
 *   @0x309a50 .word 0xf04c6929
 *   @0x309a54 strmi r0, [r1], #-3076
 *   @0x309a58 and r6, r4, r9, lsr #2
 *   @0x309a5c .word 0xf04c6969
 *   @0x309a60 strmi r0, [r1], #-3080
 *   @0x309a64 .word 0xf8a56169
 *   @0x309a68 bvs 0xfe779a70 <b2_toiTime+0xfffffffffe0205cc>
 *   @0x309a6c andle r4, r1, sp, lsl #5
 *   @0x309a70 strb r6, [r10, sp, lsr #20]!
 *   @0x309a74 bvs 0x1963ec4 <b2_toiTime+0x120aa20>
 *   @0x309a78 mvnle r4, r10, lsl #5
 *   @0x309a7c strb r3, [r6, r12, lsr #6]
 *   @0x309a80 ldrtmi r4, [r9], -r0, lsr #12
 *   @0x309a84 rfeib r0!
 *   @0x309a88 ldrtmi r4, [r9], -r0, lsr #12
 *   @0x309a8c blx 0xff687152 <b2_toiTime+0xfffffffffef2dcae>
 *   @0x309a90 vabd.s8 d3, d9, d1
 *   @0x309a94 svchs #0x25944
 *   @0x309a98 mcrge p4, #0x1, pc, c10, c15, #0x3
 *   @0x309a9c stmdbls r11, {r5, r9, r10, lr}
 *   @0x309aa0 .word 0xfc12f7fd
 *   @0x309aa4 andls lr, r8, r5, lsr #32
 *   @0x309aa8 andls lr, r8, r3, lsr #32
 *   @0x309aac ldrtmi lr, [r0], r1, lsr #32
 *   @0x309ab0 adcmi lr, r8, #88, #12
 *   @0x309ab4 .word 0xf856d3a6
 *   @0x309ab8 stmdavs r3, {r3, r5, r10, r11, sp} ^
 *   @0x309abc stmvs r2, {r0, r1, r4, r6, r7, r9, r11, r12}
 *   @0x309ac0 rfeib r1!
 *   @0x309ac4 rfeib r0!
 *   @0x309ac8 .word 0xf8d03000
 *   @0x309acc addsmi r8, r10, #8
 *   @0x309ad0 .word 0xf846d102
 *   @0x309ad4 ldr r8, [r5, r4, lsr #24]
 *   @0x309ad8 stceq p9, c15, [r12], #-216
 *   @0x309adc stmvs r9, {r1, r4, r6, r7, r9, r11, r12}
 *   @0x309ae0 bl 0xff5105e8 <b2_toiTime+0xfffffffffedb7144>
 *   @0x309ae4 .word 0xf7db0101
 *   @0x309ae8 strbmi pc, [r0], #-2345
 *   @0x309aec stceq p8, c15, [r4], #-280
 *   @0x309af0 stmdals r8, {r3, r7, r8, r9, r10, sp, lr, pc}
 *   @0x309af4 pop {r0, r1, r2, r3, r4, r12, sp, pc}
 *   @0x309af8 svclt #0x8ff0
 *   @0x309afc blt 0xeac990 <b2_toiTime+0x7534ec>
 *
 * ══ §3/4 anon_2254b0  0x2254b0  size 1900  475 条（0x2254b0..0x225c1c）
 * @func 0x2254b0 0x225c1c  size 1900  475 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock()×4 / COggSyncThread::Unlock()×4 / 0xb6a9c×4 / 0xb6b08×3 / 0xb6afc×3 / __divsi3×3 / 0xb6a84×3 / 0xb65b0×3
 * 字段偏移 top8: 0x86c×16 / 0x40×14 / 0x804×9 / 0x870×7 / 0x30×6 / 0x24×5 / 0x808×5 / 0x10×5
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2254b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2254b4 vpush {d8, d9}
 *   @0x2254b8 sub sp, sp, #76
 *   @0x2254bc vldr d8, [pc, #476]
 *   @0x2254c0 ldr r5, [pc, #0x1e8]
 *   @0x2254c4 mvn r4, #0
 *   @0x2254c8 ldr r12, [pc, #0x1e4]
 *   @0x2254cc vldr s18, [pc, #468]
 *   @0x2254d0 ldr r8, [r0, #0xc]
 *   @0x2254d4 ldr r5, [pc, r5]
 *   @0x2254d8 add r12, pc, r12
 *   @0x2254dc str r4, [sp, #0x14]
 *   @0x2254e0 str r12, [sp, #0x28]
 *   @0x2254e4 mov r4, #0
 *   @0x2254e8 ldr r12, [pc, #0x1c8]
 *   @0x2254ec mov r10, r4
 *   @0x2254f0 vldr s19, [pc, #436]
 *   @0x2254f4 add r12, pc, r12
 *   @0x2254f8 str r12, [sp, #0x2c]
 *   @0x2254fc add r12, sp, #64
 *   @0x225500 str r12, [sp, #0x20]
 *   @0x225504 mvn r12, #0
 *   @0x225508 str r12, [sp, #0x24]
 *   @0x22550c bl 0x215148 <Timing_Time>
 *   @0x225510 ldrb r3, [r5]
 *   @0x225514 uxtb r3, r3
 *   @0x225518 strb r3, [r8, #0x84d]
 *   @0x22551c ldrb r11, [r8, #0x84d]
 *   @0x225520 ands r11, r11, #255
 *   @0x225524 strd r0, r1, [sp, #8]
 *   @0x225528 bne 0x225988 <_ZN14COggSyncThread7MixDataEPviiiff+0x800>
 *   @0x22552c mov r0, r8
 *   @0x225530 bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x225534 ldrb r12, [r8, #0x84f]
 *   @0x225538 ldr r3, [r8, #0x808]
 *   @0x22553c ldrb r7, [r8, #0x850]
 *   @0x225540 str r12, [sp, #0x10]
 *   @0x225544 cmp r3, #0
 *   @0x225548 ldrb r12, [r8, #0x851]
 *   @0x22554c movgt r1, r11
 *   @0x225550 strb r11, [r8, #0x850]
 *   @0x225554 strb r11, [r8, #0x84f]
 *   @0x225558 str r12, [sp, #0x18]
 *   @0x22555c ldrb r12, [r8, #0x852]
 *   @0x225560 strb r11, [r8, #0x851]
 *   @0x225564 ldrb r6, [r8, #0x802]
 *   @0x225568 str r12, [sp, #0x1c]
 *   @0x22556c strb r11, [r8, #0x852]
 *   @0x225570 ldrb r9, [r8, #0x801]
 *   @0x225574 movgt r2, r1
 *   @0x225578 ble 0x2255c0 <_ZN14COggSyncThread7MixDataEPviiiff+0x438>
 *   @0x22557c ldr r3, [r8, #0x804]
 *   @0x225580 ldr r0, [r8, #0x82c]
 *   @0x225584 add r3, r3, r1
 *   @0x225588 add r1, r1, #768
 *   @0x22558c ldrb r12, [r3, #0x2d6]
 *   @0x225590 strb r12, [r0, r2, lsl #3]
 *   @0x225594 vldr s15, [r3, #744]
 *   @0x225598 vmul.f32 s15, s15, s18
 *   @0x22559c strb r10, [r3, #0x2d6]
 *   @0x2255a0 ldr r12, [r8, #0x808]
 *   @0x2255a4 add r2, r2, #1
 *   @0x2255a8 ldr r0, [r3, #0x2d8]
 *   @0x2255ac cmp r12, r2
 *   @0x2255b0 str r0, [r3, #0x2bc]
 *   @0x2255b4 vcvt.s32.f32 s15, s15
 *   @0x2255b8 vstr s15, [r3, #740]
 *   @0x2255bc bgt 0x22557c <_ZN14COggSyncThread7MixDataEPviiiff+0x3f4>
 *   @0x2255c0 mov r0, r8
 *   @0x2255c4 bl 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x2255c8 cmp r9, #0
 *   @0x2255cc beq 0x2259c4 <_ZN14COggSyncThread7MixDataEPviiiff+0x83c>
 *   @0x2255d0 ldr r0, [r8, #0x86c]
 *   @0x2255d4 bl 0xb6b14 <alSourceStop@plt>
 *   @0x2255d8 add r2, sp, #64
 *   @0x2255dc ldr r0, [r8, #0x86c]
 *   @0x2255e0 movw r1, #0x1015
 *   @0x2255e4 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x2255e8 ldr r3, [sp, #0x40]
 *   @0x2255ec cmp r3, #0
 *   @0x2255f0 sub r3, r3, #1
 *   @0x2255f4 addne r4, sp, #68
 *   @0x2255f8 str r3, [sp, #0x40]
 *   @0x2255fc beq 0x225624 <_ZN14COggSyncThread7MixDataEPviiiff+0x49c>
 *   @0x225600 ldr r0, [r8, #0x86c]
 *   @0x225604 mov r1, #1
 *   @0x225608 mov r2, r4
 *   @0x22560c bl 0xb6b08 <alSourceUnqueueBuffers@plt>
 *   @0x225610 ldr r3, [sp, #0x40]
 *   @0x225614 cmp r3, #0
 *   @0x225618 sub r3, r3, #1
 *   @0x22561c str r3, [sp, #0x40]
 *   @0x225620 bne 0x225600 <_ZN14COggSyncThread7MixDataEPviiiff+0x478>
 *   @0x225624 mov r0, r8
 *   @0x225628 bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x22562c ldr r2, [r8, #0x808]
 *   @0x225630 cmp r2, #0
 *   @0x225634 movgt r5, #0
 *   @0x225638 movgt r6, r5
 *   @0x22563c movgt r7, r5
 *   @0x225640 ble 0x225680 <_ZN14COggSyncThread7MixDataEPviiiff+0x4f8>
 *   @0x225644 ldr r4, [r8, #0x804]
 *   @0x225648 add r6, r6, #1
 *   @0x22564c add r4, r4, r5
 *   @0x225650 add r5, r5, #768
 *   @0x225654 ldr r3, [r4, #0x2c4]
 *   @0x225658 mov r0, r4
 *   @0x22565c cmp r3, #0
 *   @0x225660 beq 0x225678 <_ZN14COggSyncThread7MixDataEPviiiff+0x4f0>
 *   @0x225664 bl 0x230ec4 <ov_clear>
 *   @0x225668 ldr r2, [r8, #0x808]
 *   @0x22566c str r7, [r4, #0x2c4]
 *   @0x225670 str r7, [r4, #0x2e0]
 *   @0x225674 strb r7, [r4, #0x2d5]
 *   @0x225678 cmp r6, r2
 *   @0x22567c blt 0x225644 <_ZN14COggSyncThread7MixDataEPviiiff+0x4bc>
 *   @0x225680 mov r0, r8
 *   @0x225684 bl 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x225688 mov r0, #0
 *   @0x22568c strb r0, [r8, #0x84c]
 *   @0x225690 add sp, sp, #76
 *   @0x225694 vpop {d8, d9}
 *   @0x225698 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22569c nop
 *   @0x2256a0 rscsle r10, r1, #252, #18
 *   @0x2256a4 svclo #0x50624d
 *   @0x2256a8 ldrbtmi r0, [r10], #-0
 *   @0x2256ac stclo p7, c13, [r3], #-40
 *   @0x2256b0 andseq r11, r12, r4, lsr #31
 *   @0x2256b4 ldrsheq pc, [r2], -r4
 *   @0x2256b8 mulseq r2, r12, r9
 *   @0x2256bc ldr r5, [sp, #0x30]
 *   @0x2256c0 ldrb r3, [r8, #0x853]
 *   @0x2256c4 cmp r3, #0
 *   @0x2256c8 beq 0x2256d8 <_ZN14COggSyncThread7MixDataEPviiiff+0x550>
 *   @0x2256cc ldr r0, [r8, #0x804]
 *   @0x2256d0 mvn r1, #0
 *   @0x2256d4 bl 0x23138c <ov_pcm_total>
 *   @0x2256d8 ldr r1, [r8, #0x804]
 *   @0x2256dc movw r12, #0x1101
 *   @0x2256e0 movw lr, #0x1103
 *   @0x2256e4 ldr r2, [r8, #0x85c]
 *   @0x2256e8 ldr r0, [r8, #0x864]
 *   @0x2256ec mov r3, #16384
 *   @0x2256f0 ldr r1, [r1, #0x298]
 *   @0x2256f4 mov r11, #2080
 *   @0x2256f8 ldr r6, [r1, #0x4]
 *   @0x2256fc ldr r1, [r1, #0x8]
 *   @0x225700 cmp r6, #1
 *   @0x225704 moveq lr, r12
 *   @0x225708 str r1, [sp, #0x14]
 *   @0x22570c str r1, [sp]
 *   @0x225710 mov r1, lr
 *   @0x225714 str lr, [sp, #0x24]
 *   @0x225718 bl 0xb6afc <alBufferData@plt>
 *   @0x22571c ldr r9, [r8, #0x804]
 *   @0x225720 mov r0, #16384
 *   @0x225724 ldr r3, [r9, #0x298]
 *   @0x225728 ldr r1, [r3, #0x4]
 *   @0x22572c lsl r1, r1, #1
 *   @0x225730 bl 0x318d10 <__divsi3>
 *   @0x225734 ldrd r6, r7, [r8, r11]
 *   @0x225738 movw r12, #0x818
 *   @0x22573c mov r3, #1
 *   @0x225740 mov r1, r4
 *   @0x225744 str r3, [r8, #0x870]
 *   @0x225748 mov r2, r8
 *   @0x22574c ldrb r3, [r8, #0x853]
 *   @0x225750 adds r6, r6, r0
 *   @0x225754 adc r7, r7, r0, asr #31
 *   @0x225758 mov r0, r9
 *   @0x22575c strd r6, r7, [r8, r11]
 *   @0x225760 strd r6, r7, [r8, r12]
 *   @0x225764 bl 0x225384 <_ZN14COggSyncThread7MixDataEPviiiff+0x1fc>
 *   @0x225768 ldr r12, [sp, #0x14]
 *   @0x22576c ldr r2, [r8, #0x860]
 *   @0x225770 mov r3, #16384
 *   @0x225774 ldr r0, [r8, #0x868]
 *   @0x225778 ldr r1, [sp, #0x24]
 *   @0x22577c str r12, [sp]
 *   @0x225780 bl 0xb6afc <alBufferData@plt>
 *   @0x225784 ldr r3, [r8, #0x804]
 *   @0x225788 mov r0, #16384
 *   @0x22578c ldr r3, [r3, #0x298]
 *   @0x225790 ldr r1, [r3, #0x4]
 *   @0x225794 lsl r1, r1, #1
 *   @0x225798 bl 0x318d10 <__divsi3>
 *   @0x22579c ldrd r6, r7, [r8, r11]
 *   @0x2257a0 add r2, r8, #2144
 *   @0x2257a4 mov r1, #2
 *   @0x2257a8 add r2, r2, #4
 *   @0x2257ac adds r6, r6, r0
 *   @0x2257b0 adc r7, r7, r0, asr #31
 *   @0x2257b4 ldr r0, [r8, #0x86c]
 *   @0x2257b8 strd r6, r7, [r8, r11]
 *   @0x2257bc bl 0xb6b8c <alSourceQueueBuffers@plt>
 *   @0x2257c0 ldrd r2, r3, [r8, r11]
 *   @0x2257c4 movw r1, #0x818
 *   @0x2257c8 ldr r0, [r8, #0x86c]
 *   @0x2257cc strd r2, r3, [r8, r1]
 *   @0x2257d0 bl 0xb6a84 <alSourcePlay@plt>
 *   @0x2257d4 ldr r0, [r8, #0x86c]
 *   @0x2257d8 movw r1, #0x100a
 *   @0x2257dc mov r2, #1065353216
 *   @0x2257e0 bl 0xb6a78 <alSourcef@plt>
 *   @0x2257e4 str r10, [r8, #0x870]
 *   @0x2257e8 ldr r12, [sp, #0x10]
 *   @0x2257ec cmp r12, #0
 *   @0x2257f0 bne 0x225b3c <_ZN14COggSyncThread7MixDataEPviiiff+0x9b4>
 *   @0x2257f4 cmp r4, #0
 *   @0x2257f8 ldr r3, [sp, #0x3c]
 *   @0x2257fc beq 0x225810 <_ZN14COggSyncThread7MixDataEPviiiff+0x688>
 *   @0x225800 movw r2, #0x1014
 *   @0x225804 cmp r3, r2
 *   @0x225808 moveq r11, #1
 *   @0x22580c beq 0x225820 <_ZN14COggSyncThread7MixDataEPviiiff+0x698>
 *   @0x225810 movw r2, #0x1012
 *   @0x225814 cmp r3, r2
 *   @0x225818 bne 0x225948 <_ZN14COggSyncThread7MixDataEPviiiff+0x7c0>
 *   @0x22581c mov r11, #0
 *   @0x225820 str r10, [sp, #0x40]
 *   @0x225824 movw r1, #0x1016
 *   @0x225828 ldr r0, [r8, #0x86c]
 *   @0x22582c add r2, sp, #64
 *   @0x225830 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x225834 ldr r3, [sp, #0x40]
 *   @0x225838 cmp r3, #0
 *   @0x22583c sub r3, r3, #1
 *   @0x225840 str r3, [sp, #0x40]
 *   @0x225844 ble 0x22592c <_ZN14COggSyncThread7MixDataEPviiiff+0x7a4>
 *   @0x225848 str r11, [sp, #0x30]
 *   @0x22584c add r6, sp, #68
 *   @0x225850 ldr r11, [sp, #0x14]
 *   @0x225854 movw r9, #0x818
 *   @0x225858 mov r7, #2080
 *   @0x22585c str r4, [sp, #0x10]
 *   @0x225860 str r5, [sp, #0x34]
 *   @0x225864 mov r2, r6
 *   @0x225868 ldr r0, [r8, #0x86c]
 *   @0x22586c mov r1, #1
 *   @0x225870 bl 0xb6b08 <alSourceUnqueueBuffers@plt>
 *   @0x225874 ldr r3, [r8, #0x804]
 *   @0x225878 mov r0, #16384
 *   @0x22587c ldr r3, [r3, #0x298]
 *   @0x225880 ldr r1, [r3, #0x4]
 *   @0x225884 lsl r1, r1, #1
 *   @0x225888 bl 0x318d10 <__divsi3>
 *   @0x22588c ldr r12, [r8, #0x870]
 *   @0x225890 ldrd r4, r5, [r8, r7]
 *   @0x225894 mov r1, #0
 *   @0x225898 mov r2, #16384
 *   @0x22589c add r3, r8, r12, lsl #2
 *   @0x2258a0 adds r4, r4, r0
 *   @0x2258a4 adc r5, r5, r0, asr #31
 *   @0x2258a8 ldr r0, [r3, #0x85c]
 *   @0x2258ac strd r4, r5, [r8, r9]
 *   @0x2258b0 bl 0xb65b0 <memset@plt>
 *   @0x2258b4 ldr r0, [r8, #0x804]
 *   @0x2258b8 ldr r1, [sp, #0x10]
 *   @0x2258bc mov r2, r8
 *   @0x2258c0 ldrb r3, [r8, #0x853]
 *   @0x2258c4 bl 0x225384 <_ZN14COggSyncThread7MixDataEPviiiff+0x1fc>
 *   @0x2258c8 ldr r2, [r8, #0x870]
 *   @0x2258cc ldr r0, [sp, #0x44]
 *   @0x2258d0 mov r3, #16384
 *   @0x2258d4 ldr r1, [sp, #0x24]
 *   @0x2258d8 add r2, r8, r2, lsl #2
 *   @0x2258dc ldr r2, [r2, #0x85c]
 *   @0x2258e0 str r11, [sp]
 *   @0x2258e4 bl 0xb6afc <alBufferData@plt>
 *   @0x2258e8 ldrd r2, r3, [r8, r9]
 *   @0x2258ec ldr r12, [r8, #0x870]
 *   @0x2258f0 mov r1, #1
 *   @0x2258f4 ldr r0, [r8, #0x86c]
 *   @0x2258f8 eor r12, r12, r1
 *   @0x2258fc strd r2, r3, [r8, r7]
 *   @0x225900 str r12, [r8, #0x870]
 *   @0x225904 mov r2, r6
 *   @0x225908 bl 0xb6b8c <alSourceQueueBuffers@plt>
 *   @0x22590c ldr r3, [sp, #0x40]
 *   @0x225910 cmp r3, #0
 *   @0x225914 sub r3, r3, #1
 *   @0x225918 str r3, [sp, #0x40]
 *   @0x22591c bgt 0x225864 <_ZN14COggSyncThread7MixDataEPviiiff+0x6dc>
 *   @0x225920 ldr r4, [sp, #0x10]
 *   @0x225924 ldr r11, [sp, #0x30]
 *   @0x225928 ldr r5, [sp, #0x34]
 *   @0x22592c cmp r11, #0
 *   @0x225930 beq 0x225948 <_ZN14COggSyncThread7MixDataEPviiiff+0x7c0>
 *   @0x225934 ldr r0, [r8, #0x86c]
 *   @0x225938 bl 0xb6a84 <alSourcePlay@plt>
 *   @0x22593c ldr r3, [r8, #0x828]
 *   @0x225940 add r3, r3, #1
 *   @0x225944 str r3, [r8, #0x828]
 *   @0x225948 ldr r12, [sp, #0x18]
 *   @0x22594c cmp r12, #0
 *   @0x225950 beq 0x225964 <_ZN14COggSyncThread7MixDataEPviiiff+0x7dc>
 *   @0x225954 ldr r2, [sp, #0x3c]
 *   @0x225958 movw r3, #0x1012
 *   @0x22595c cmp r2, r3
 *   @0x225960 beq 0x225c10 <_ZN14COggSyncThread7MixDataEPviiiff+0xa88>
 *   @0x225964 ldr r12, [sp, #0x1c]
 *   @0x225968 cmp r12, #0
 *   @0x22596c beq 0x225988 <_ZN14COggSyncThread7MixDataEPviiiff+0x800>
 *   @0x225970 ldr r2, [sp, #0x3c]
 *   @0x225974 movw r3, #0x1013
 *   @0x225978 cmp r2, r3
 *   @0x22597c bne 0x225988 <_ZN14COggSyncThread7MixDataEPviiiff+0x800>
 *   @0x225980 ldr r0, [r8, #0x86c]
 *   @0x225984 bl 0xb6a84 <alSourcePlay@plt>
 *   @0x225988 bl 0x215148 <Timing_Time>
 *   @0x22598c ldrd r2, r3, [sp, #8]
 *   @0x225990 subs r0, r0, r2
 *   @0x225994 sbc r1, r1, r3
 *   @0x225998 bl 0x319164 <__floatdidf>
 *   @0x22599c vmov d6, r0, r1
 *   @0x2259a0 vmul.f64 d7, d6, d8
 *   @0x2259a4 vcvt.s32.f64 s13, d7
 *   @0x2259a8 vmov r0, s13
 *   @0x2259ac rsb r0, r0, #16
 *   @0x2259b0 bic r0, r0, r0, asr #31
 *   @0x2259b4 cmp r0, #0
 *   @0x2259b8 beq 0x22550c <_ZN14COggSyncThread7MixDataEPviiiff+0x384>
 *   @0x2259bc bl 0x27e114 <_ZN7CThread5SleepEi>
 *   @0x2259c0 b 0x22550c <_ZN14COggSyncThread7MixDataEPviiiff+0x384>
 *   @0x2259c4 cmp r6, #0
 *   @0x2259c8 bne 0x2255d0 <_ZN14COggSyncThread7MixDataEPviiiff+0x448>
 *   @0x2259cc ldr r0, [r8, #0x86c]
 *   @0x2259d0 movw r1, #0x1010
 *   @0x2259d4 add r2, sp, #60
 *   @0x2259d8 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x2259dc cmp r7, #0
 *   @0x2259e0 beq 0x2257e8 <_ZN14COggSyncThread7MixDataEPviiiff+0x660>
 *   @0x2259e4 ldr r2, [sp, #0x3c]
 *   @0x2259e8 movw r3, #0x1012
 *   @0x2259ec cmp r2, r3
 *   @0x2259f0 beq 0x225c00 <_ZN14COggSyncThread7MixDataEPviiiff+0xa78>
 *   @0x2259f4 mov r1, r6
 *   @0x2259f8 mov r2, #16384
 *   @0x2259fc ldr r0, [r8, #0x85c]
 *   @0x225a00 bl 0xb65b0 <memset@plt>
 *   @0x225a04 mov r1, r6
 *   @0x225a08 mov r2, #16384
 *   @0x225a0c ldr r0, [r8, #0x860]
 *   @0x225a10 bl 0xb65b0 <memset@plt>
 *   @0x225a14 ldr r12, [r8, #0x808]
 *   @0x225a18 ldr r6, [r8, #0x804]
 *   @0x225a1c mov r1, #2080
 *   @0x225a20 cmp r12, #0
 *   @0x225a24 mov r2, #0
 *   @0x225a28 mov r3, #0
 *   @0x225a2c strd r2, r3, [r8, r1]
 *   @0x225a30 movgt r3, #1
 *   @0x225a34 movgt r2, r6
 *   @0x225a38 ble 0x225a5c <_ZN14COggSyncThread7MixDataEPviiiff+0x8d4>
 *   @0x225a3c ldr r1, [r2, #0x2d8]
 *   @0x225a40 add r2, r2, #768
 *   @0x225a44 cmp r1, #0
 *   @0x225a48 strne r1, [r2, #-0x44]
 *   @0x225a4c movne r4, r3
 *   @0x225a50 cmp r12, r3
 *   @0x225a54 add r3, r3, #1
 *   @0x225a58 bgt 0x225a3c <_ZN14COggSyncThread7MixDataEPviiiff+0x8b4>
 *   @0x225a5c cmp r4, #0
 *   @0x225a60 str r10, [r8, #0x870]
 *   @0x225a64 beq 0x2256c0 <_ZN14COggSyncThread7MixDataEPviiiff+0x538>
 *   @0x225a68 add r7, r6, #748
 *   @0x225a6c mov r9, #0
 *   @0x225a70 str r5, [sp, #0x30]
 *   @0x225a74 b 0x225af8 <_ZN14COggSyncThread7MixDataEPviiiff+0x970>
 *   @0x225a78 mov r0, r6
 *   @0x225a7c bl 0x223cb4 <_ZN10COggThread8LogErrorEPKcz+0x9c>
 *   @0x225a80 cmp r0, #0
 *   @0x225a84 beq 0x225bd4 <_ZN14COggSyncThread7MixDataEPviiiff+0xa4c>
 *   @0x225a88 mov r1, #2
 *   @0x225a8c mov r0, r6
 *   @0x225a90 str r1, [r6, #0x2c4]
 *   @0x225a94 mvn r1, #0
 *   @0x225a98 bl 0x232e28 <ov_info>
 *   @0x225a9c str r10, [r6, #0x2e0]
 *   @0x225aa0 mvn r1, #0
 *   @0x225aa4 str r0, [r6, #0x298]
 *   @0x225aa8 mov r0, r6
 *   @0x225aac bl 0x23138c <ov_pcm_total>
 *   @0x225ab0 strd r0, r1, [r7, #4]
 *   @0x225ab4 vldr s15, [r11, #4]
 *   @0x225ab8 vcmpe.f32 s15, s19
 *   @0x225abc vmrs APSR_nzcv, fpscr
 *   @0x225ac0 strmi r10, [r6, #0x2a8]
 *   @0x225ac4 bmi 0x225ae4 <_ZN14COggSyncThread7MixDataEPviiiff+0x95c>
 *   @0x225ac8 str r10, [r6, #0x2a8]
 *   @0x225acc mov r0, r6
 *   @0x225ad0 mov r1, r8
 *   @0x225ad4 mov r2, #1
 *   @0x225ad8 bl 0x225230 <_ZN14COggSyncThread7MixDataEPviiiff+0xa8>
 *   @0x225adc cmp r0, #0
 *   @0x225ae0 ble 0x225ba0 <_ZN14COggSyncThread7MixDataEPviiiff+0xa18>
 *   @0x225ae4 add r9, r9, #1
 *   @0x225ae8 add r6, r6, #768
 *   @0x225aec cmp r9, r4
 *   @0x225af0 add r7, r7, #768
 *   @0x225af4 beq 0x2256bc <_ZN14COggSyncThread7MixDataEPviiiff+0x534>
 *   @0x225af8 ldr r11, [r6, #0x2bc]
 *   @0x225afc ldr r3, [r11, #0x4]
 *   @0x225b00 str r3, [r7]
 *   @0x225b04 ldrb r1, [r11, #0x24]
 *   @0x225b08 cmp r1, #0
 *   @0x225b0c beq 0x225a78 <_ZN14COggSyncThread7MixDataEPviiiff+0x8f0>
 *   @0x225b10 ldr r5, [r11, #0x30]
 *   @0x225b14 mov r2, #0
 *   @0x225b18 mov r1, r6
 *   @0x225b1c mov r0, r5
 *   @0x225b20 bl 0x223d28 <_ZN10COggThread8LogErrorEPKcz+0x110>
 *   @0x225b24 subs r2, r0, #0
 *   @0x225b28 bne 0x225a88 <_ZN14COggSyncThread7MixDataEPviiiff+0x900>
 *   @0x225b2c mov r0, r5
 *   @0x225b30 mov r1, r6
 *   @0x225b34 bl 0x223e10 <_ZN10COggThread8LogErrorEPKcz+0x1f8>
 *   @0x225b38 b 0x225a80 <_ZN14COggSyncThread7MixDataEPviiiff+0x8f8>
 *   @0x225b3c ldr r0, [r8, #0x86c]
 *   @0x225b40 bl 0xb6b14 <alSourceStop@plt>
 *   @0x225b44 str r10, [sp, #0x40]
 *   @0x225b48 movw r1, #0x1015
 *   @0x225b4c ldr r0, [r8, #0x86c]
 *   @0x225b50 add r2, sp, #64
 *   @0x225b54 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x225b58 ldr r3, [sp, #0x40]
 *   @0x225b5c cmp r3, #0
 *   @0x225b60 sub r3, r3, #1
 *   @0x225b64 addne r6, sp, #68
 *   @0x225b68 str r3, [sp, #0x40]
 *   @0x225b6c beq 0x225b94 <_ZN14COggSyncThread7MixDataEPviiiff+0xa0c>
 *   @0x225b70 ldr r0, [r8, #0x86c]
 *   @0x225b74 mov r1, #1
 *   @0x225b78 mov r2, r6
 *   @0x225b7c bl 0xb6b08 <alSourceUnqueueBuffers@plt>
 *   @0x225b80 ldr r3, [sp, #0x40]
 *   @0x225b84 cmp r3, #0
 *   @0x225b88 sub r3, r3, #1
 *   @0x225b8c str r3, [sp, #0x40]
 *   @0x225b90 bne 0x225b70 <_ZN14COggSyncThread7MixDataEPviiiff+0x9e8>
 *   @0x225b94 ldr r3, [sp, #0x3c]
 *   @0x225b98 mov r4, #0
 *   @0x225b9c b 0x225810 <_ZN14COggSyncThread7MixDataEPviiiff+0x688>
 *   @0x225ba0 ldr r3, [r6, #0x2c4]
 *   @0x225ba4 cmp r3, #0
 *   @0x225ba8 beq 0x225bbc <_ZN14COggSyncThread7MixDataEPviiiff+0xa34>
 *   @0x225bac mov r0, r6
 *   @0x225bb0 bl 0x230ec4 <ov_clear>
 *   @0x225bb4 str r10, [r6, #0x2c4]
 *   @0x225bb8 str r10, [r6, #0x2e0]
 *   @0x225bbc mov r0, r8
 *   @0x225bc0 bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x225bc4 strb r10, [r6, #0x2d5]
 *   @0x225bc8 mov r0, r8
 *   @0x225bcc bl 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x225bd0 b 0x225ae4 <_ZN14COggSyncThread7MixDataEPviiiff+0x95c>
 *   @0x225bd4 mov r0, r8
 *   @0x225bd8 ldr r1, [sp, #0x28]
 *   @0x225bdc ldr r5, [sp, #0x30]
 *   @0x225be0 bl 0x224fdc <_ZN14COggSyncThread8LogErrorEPKcz>
 *   @0x225be4 mov r0, r8
 *   @0x225be8 bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x225bec mov r3, #1
 *   @0x225bf0 mov r0, r8
 *   @0x225bf4 strb r3, [r8, #0x801]
 *   @0x225bf8 bl 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x225bfc b 0x22550c <_ZN14COggSyncThread7MixDataEPviiiff+0x384>
 *   @0x225c00 mov r0, r8
 *   @0x225c04 ldr r1, [sp, #0x2c]
 *   @0x225c08 bl 0x224fdc <_ZN14COggSyncThread8LogErrorEPKcz>
 *   @0x225c0c b 0x22550c <_ZN14COggSyncThread7MixDataEPviiiff+0x384>
 *   @0x225c10 ldr r0, [r8, #0x86c]
 *   @0x225c14 bl 0xb6ab4 <alSourcePause@plt>
 *   @0x225c18 b 0x225964 <_ZN14COggSyncThread7MixDataEPviiiff+0x7dc>
 *
 * ══ §4/4 Code_Main_SET_Argument_Relative(int)  0xcefa8  size 32  8 条（0xcefa8..0xcefc8）
 * @func 0xcefa8 0xcefc8  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcefa8 ldr r3, [pc, #0x14]
 *   @0xcefac subs r2, r0, #1
 *   @0xcefb0 rsbs r0, r2, #0
 *   @0xcefb4 ldr r3, [pc, r3]
 *   @0xcefb8 adcs r0, r0, r2
 *   @0xcefbc strb r0, [r3]
 *   @0xcefc0 bx lr
 *   @0xcefc4 eorseq lr, r1, r8, lsl #23
 */
