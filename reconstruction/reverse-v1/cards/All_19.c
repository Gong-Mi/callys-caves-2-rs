/* cally 逆向卡：All_19 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 8 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/8 TT_RunIns  0x2fcdf4  size 7804  1951 条（0x2fcdf4..0x2fec70）
 * @func 0x2fcdf4 0x2fec70  size 7804  1951 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_MulDiv×8 / anonT_2f8e0a×4 / anon_2f929c×4 / anon_2f929c+0x1c4×3 / TT_RunIns+0x4b4×3 / anon_2fa330+0x11bc×3 / anon_2fa330+0xf54×2 / anon_2fa330+0xf24×2
 * 字段偏移 top8: 0x4×43 / 0xc×21 / 0x1c×14 / 0x8×9 / 0x34×9 / 0x10×7 / 0x40×6 / 0x2c×6
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2fcdf4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2fcdf8 mov r4, r0
 *   @0x2fcdfc sub sp, #0x74
 *   @0x2fce00 ldr r3, [r3, #0x40]
 *   @0x2fce04 bne 0x2fce1a <TT_RunIns+0x26>
 *   @0x2fce08 lsls r6, r3, #0x12
 *   @0x2fce0c ldrb.w r3, [r0, #0x154]
 *   @0x2fce10 eor r3, r3, #0x4
 *   @0x2fce14 ubfx r3, r3, #0x2, #0x1
 *   @0x2fce18 b 0x2fce1c <TT_RunIns+0x28>
 *   @0x2fce1c ldrh.w r6, [r4, #0x98]
 *   @0x2fce20 movs r2, #0x0
 *   @0x2fce24 .word 0xf8840180
 *   @0x2fce28 ldmdane r3!, {r0, r1, r2, r5, r6, r9, r12, sp}
 *   @0x2fce2c ldrh.w r1, [r4, #0xbc]
 *   @0x2fce30 strb.w r2, [r4, #0x268]
 *   @0x2fce34 lsls r3, r3, #0x1
 *   @0x2fce38 blhs 0xa857e4 <b2_toiTime+0x32c340>
 *   @0x2fce3c it lo
 *   @0x2fce40 str.w r2, [r4, #0x26c]
 *   @0x2fce44 cmp r1, r3
 *   @0x2fce48 svclt #0x882274
 *   @0x2fce4c strhhi.w r3, [r4, #0xbc]
 *   @0x2fce50 movs r1, #0xa
 *   @0x2fce54 muls r6, r1, r6
 *   @0x2fce58 it lt
 *   @0x2fce5c cmp.w r0, #0x1f4
 *   @0x2fce60 blo 0x2fce68 <TT_RunIns+0x74>
 *   @0x2fce64 strd lr, pc, [r0], -r2
 *   @0x2fce68 movs r0, #0x32
 *   @0x2fce6c str.w r6, [r4, #0x270]
 *   @0x2fce70 b 0x2fce7e <TT_RunIns+0x8a>
 *   @0x2fce74 cmp r1, #0x64
 *   @0x2fce78 movlo r1, #0x64
 *   @0x2fce7c stmdbvs r11!, {r4, r5, r6, r9, r12}
 *   @0x2fce80 movs r2, #0x64
 *   @0x2fce84 ldr.w r2, [r4, #0x270]
 *   @0x2fce88 cmp r2, r3
 *   @0x2fce8c svclt #0x8820dc
 *   @0x2fce90 strhi.w r3, [r4, #0x270]
 *   @0x2fce94 ldr.w r3, [r4, #0x270]
 *   @0x2fce98 str.w r3, [r4, #0x278]
 *   @0x2fce9c movs r3, #0x0
 *   @0x2fcea0 rfeia r4!
 *   @0x2fcea4 addsmi r3, r10, #222
 *   @0x2fcea8 beq 0x2fced0 <TT_RunIns+0xdc>
 *   @0x2fceac ldrbtmi r3, [r11], #-3012
 *   @0x2fceb0 str.w r3, [r4, #0x254]
 *   @0x2fceb4 ldr.w r3, [pc, #0xbbc]
 *   @0x2fceb8 add r3, pc
 *   @0x2fcebc .word 0xf8df3258
 *   @0x2fcec0 ldrbtmi r3, [r11], #-3000
 *   @0x2fcec4 str.w r3, [r4, #0x25c]
 *   @0x2fcec8 ldr.w r3, [pc, #0xbb0]
 *   @0x2fcecc add r3, pc
 *   @0x2fced0 ldr.w r3, [pc, #0xbac]
 *   @0x2fced4 add r3, pc
 *   @0x2fced8 .word 0xf8df3254
 *   @0x2fcedc ldrbtmi r3, [r11], #-2984
 *   @0x2fcee0 str.w r3, [r4, #0x258]
 *   @0x2fcee4 ldr.w r3, [pc, #0xba0]
 *   @0x2fcee8 add r3, pc
 *   @0x2fceec .word 0xf8df325c
 *   @0x2fcef0 ldrbtmi r3, [r11], #-2972
 *   @0x2fcef4 str.w r3, [r4, #0x260]
 *   @0x2fcef8 mov r0, r4
 *   @0x2fcefc .word 0xf894fab1
 *   @0x2fcf00 blhs 0x4c93f8 <SrcVerts+0x2643c>
 *   @0x2fcf04 bhi 0x2fcf54 <TT_RunIns+0x160>
 *   @0x2fcf08 ldmdaeq r4, {r0, r1, r12, sp, lr, pc}
 *   @0x2fcf0c asrs r0, r3, #0x20
 *   @0x2fcf10 movs r0, #0x1c
 *   @0x2fcf14 ldrbtmi r3, [r11], #-2940
 *   @0x2fcf18 b 0x2fcf50 <TT_RunIns+0x15c>
 *   @0x2fcf1c ldrbtmi r3, [r11], #-2936
 *   @0x2fcf20 b 0x2fcf50 <TT_RunIns+0x15c>
 *   @0x2fcf24 ldrbtmi r3, [r11], #-2932
 *   @0x2fcf28 b 0x2fcf50 <TT_RunIns+0x15c>
 *   @0x2fcf2c ldrbtmi r3, [r11], #-2928
 *   @0x2fcf30 b 0x2fcf50 <TT_RunIns+0x15c>
 *   @0x2fcf34 ldrbtmi r3, [r11], #-2924
 *   @0x2fcf38 b 0x2fcf50 <TT_RunIns+0x15c>
 *   @0x2fcf3c ldrbtmi r3, [r11], #-2920
 *   @0x2fcf40 b 0x2fcf50 <TT_RunIns+0x15c>
 *   @0x2fcf44 ldrbtmi r3, [r11], #-2916
 *   @0x2fcf48 b 0x2fcf50 <TT_RunIns+0x15c>
 *   @0x2fcf4c ldrbtmi r3, [r11], #-2912
 *   @0x2fcf50 str.w r3, [r4, #0x23c]
 *   @0x2fcf54 ldr.w r6, [pc, #0xb58]
 *   @0x2fcf58 movs r5, #0x0
 *   @0x2fcf5c ldrbtmi r7, [lr], #-2904
 *   @0x2fcf60 str r5, [sp, #0x18]
 *   @0x2fcf64 str r6, [sp, #0x38]
 *   @0x2fcf68 ldr.w r5, [r4, #0x168]
 *   @0x2fcf6c ldr.w r3, [r4, #0x16c]
 *   @0x2fcf70 ldr.w r8, [sp, #0x38]
 *   @0x2fcf74 ldr.w r0, [r4, #0x170]
 *   @0x2fcf78 ldrb r2, [r5, r3]
 *   @0x2fcf7c .word 0xf8841002
 *   @0x2fcf80 stmdbhs r0, {r2, r4, r5, r6, r8, sp}
 *   @0x2fcf84 str.w r1, [r4, #0x178]
 *   @0x2fcf88 bge 0x2fcfa2 <TT_RunIns+0x1ae>
 *   @0x2fcf8c cmp r6, r0
 *   @0x2fcf90 ldrmi r8, [sp], #-1634
 *   @0x2fcf94 ldrb r5, [r5, #0x1]
 *   @0x2fcf98 .word 0xf1c1f105
 *   @0x2fcf9c .word 0xf8c40102
 *   @0x2fcfa0 .word 0xf8d41178
 *   @0x2fcfa4 strmi r1, [r11], #-376
 *   @0x2fcfa8 cmp r3, r0
 *   @0x2fcfac .word 0xf8df8654
 *   @0x2fcfb0 ldrbtmi r3, [r11], #-2824
 *   @0x2fcfb4 add r2, r3
 *   @0x2fcfb8 ldrb.w r2, [r2, #0x498]
 *   @0x2fcfbc sub.w r3, r3, r2, lsr #4
 *   @0x2fcfc0 str r3, [r4, #0x1c]
 *   @0x2fcfc4 bge 0x2fcffa <TT_RunIns+0x206>
 *   @0x2fcfc8 stmdblt r11, {r0, r2, r4, r5, r9, r12, sp}
 *   @0x2fcfcc mov r1, r3
 *   @0x2fcfd0 movs r3, #0x81
 *   @0x2fcfd4 .word 0xf894be41
 *   @0x2fcfd8 .word 0xf8dd2174
 *   @0x2fcfdc strbtmi r12, [r2], #-60
 *   @0x2fcfe0 ldrb.w r2, [r2, #0x498]
 *   @0x2fcfe4 cmp.w r3, r2, lsr #4
 *   @0x2fcfe8 bhs 0x2fcff6 <TT_RunIns+0x202>
 *   @0x2fcfec str.w r1, [r2, r3, lsl #2]
 *   @0x2fcff0 adds r3, #0x1
 *   @0x2fcff4 b 0x2fcfd6 <TT_RunIns+0x1e2>
 *   @0x2fcff8 str r3, [r4, #0x1c]
 *   @0x2fcffc blhs 0xfe7495d4 <b2_toiTime+0xfffffffffdff0130>
 *   @0x2fd000 bne 0x2fd014 <TT_RunIns+0x220>
 *   @0x2fd004 ldr.w r2, [r2, #0x2b8]
 *   @0x2fd008 cbz r2, 0x2fd02a <TT_RunIns+0x236>
 *   @0x2fd00c ldr r1, [r4, #0x1c]
 *   @0x2fd010 str r1, [r4, #0x20]
 *   @0x2fd014 ldr.w r2, [pc, #0xaa4]
 *   @0x2fd018 add r2, pc
 *   @0x2fd01c ldrb.w r1, [r2, #0x498]
 *   @0x2fd020 ldr r2, [r4, #0x1c]
 *   @0x2fd024 strmi r0, [r10], #-271
 *   @0x2fd028 str r2, [r4, #0x20]
 *   @0x2fd02c ldr r1, [r4, #0x20]
 *   @0x2fd030 ble 0x2fd038 <TT_RunIns+0x244>
 *   @0x2fd034 b.w 0x2fec58 <TT_RunIns+0x1e64>
 *   @0x2fd038 ldr r6, [r4, #0x1c]
 *   @0x2fd03c ldr r5, [r4, #0x18]
 *   @0x2fd040 strb.w r0, [r4, #0x17c]
 *   @0x2fd044 str r1, [r4, #0xc]
 *   @0x2fd048 blhs 0xfe77ee68 <b2_toiTime+0xfffffffffe0259c4>
 *   @0x2fd04c bhi.w 0x2fe7b8 <TT_RunIns+0x19c4>
 *   @0x2fd050 tbh [pc, r3, lsl #1]
 *   @0x2fd054 lsls r3, r2, #0x2
 *   @0x2fd058 lsls r3, r2, #0x2
 *   @0x2fd05c lsls r3, r2, #0x2
 *   @0x2fd060 lsls r1, r6, #0x2
 *   @0x2fd064 lsls r6, r0, #0x3
 *   @0x2fd068 lsls r2, r2, #0x3
 *   @0x2fd06c lsls r1, r6, #0x3
 *   @0x2fd070 lsls r3, r0, #0x4
 *   @0x2fd074 lsls r3, r7, #0x7
 *   @0x2fd078 lsls r7, r0, #0x8
 *   @0x2fd07c lsls r3, r5, #0x8
 *   @0x2fd080 lsls r7, r4, #0x9
 *   @0x2fd084 lsls r3, r6, #0xa
 *   @0x2fd088 lsls r5, r0, #0xb
 *   @0x2fd08c lsls r7, r3, #0xb
 *   @0x2fd090 lsls r3, r5, #0xb
 *   @0x2fd094 lsls r3, r7, #0xb
 *   @0x2fd098 lsls r0, r0, #0xc
 *   @0x2fd09c lsls r3, r1, #0xc
 *   @0x2fd0a0 lsls r7, r4, #0xc
 *   @0x2fd0a4 lsls r7, r6, #0xd
 *   @0x2fd0a8 lsls r3, r2, #0xe
 *   @0x2fd0ac lsls r7, r4, #0xf
 *   @0x2fd0b0 lsls r7, r2, #0x10
 *   @0x2fd0b4 lsls r0, r0, #0x11
 *   @0x2fd0b8 lsls r4, r6, #0x13
 *   @0x2fd0bc lsls r1, r7, #0x13
 *   @0x2fd0c0 lsls r6, r7, #0x15
 *   @0x2fd0c4 lsls r5, r0, #0x17
 *   @0x2fd0c8 lsls r0, r1, #0x1b
 *   @0x2fd0cc lsls r7, r3, #0x1c
 *   @0x2fd0d0 lsls r4, r7, #0x1d
 *   @0x2fd0d4 lsls r7, r3, #0x1f
 *   @0x2fd0d8 lsrs r4, r4, #0x20
 *   @0x2fd0dc lsrs r1, r1, #0x1
 *   @0x2fd0e0 lsrs r6, r5, #0x1
 *   @0x2fd0e4 lsrs r2, r2, #0x2
 *   @0x2fd0e8 lsrs r0, r3, #0x2
 *   @0x2fd0ec lsrs r6, r4, #0x2
 *   @0x2fd0f0 lsrs r5, r7, #0x2
 *   @0x2fd0f4 lsrs r5, r0, #0x3
 *   @0x2fd0f8 lsrs r3, r3, #0x3
 *   @0x2fd0fc lsrs r1, r6, #0x3
 *   @0x2fd100 lsrs r0, r1, #0x4
 *   @0x2fd104 lsrs r3, r5, #0x4
 *   @0x2fd108 lsrs r0, r2, #0x5
 *   @0x2fd10c lsrs r0, r5, #0x5
 *   @0x2fd110 lsrs r0, r7, #0x5
 *   @0x2fd114 lsrs r0, r1, #0x6
 *   @0x2fd118 lsrs r0, r3, #0x6
 *   @0x2fd11c lsrs r0, r6, #0x6
 *   @0x2fd120 lsrs r6, r7, #0x6
 *   @0x2fd124 lsrs r5, r1, #0x7
 *   @0x2fd128 lsrs r5, r1, #0x7
 *   @0x2fd12c lsrs r2, r3, #0x7
 *   @0x2fd130 lsrs r2, r3, #0x7
 *   @0x2fd134 lsrs r6, r4, #0x7
 *   @0x2fd138 lsrs r7, r6, #0x7
 *   @0x2fd13c lsrs r4, r7, #0x7
 *   @0x2fd140 lsrs r3, r1, #0x9
 *   @0x2fd144 lsrs r3, r5, #0x9
 *   @0x2fd148 lsrs r5, r7, #0x9
 *   @0x2fd14c lsrs r2, r1, #0xa
 *   @0x2fd150 lsrs r2, r5, #0x16
 *   @0x2fd154 lsrs r4, r3, #0xa
 *   @0x2fd158 lsrs r2, r1, #0xb
 *   @0x2fd15c lsrs r4, r6, #0xb
 *   @0x2fd160 lsrs r5, r7, #0xb
 *   @0x2fd164 lsrs r2, r0, #0xc
 *   @0x2fd168 lsrs r4, r1, #0xd
 *   @0x2fd16c lsrs r6, r3, #0xd
 *   @0x2fd170 lsrs r0, r6, #0xd
 *   @0x2fd174 lsrs r5, r2, #0xe
 *   @0x2fd178 lsrs r1, r0, #0xf
 *   @0x2fd17c orrseq r0, r2, #268435456
 *   @0x2fd180 uxth r2, r2
 *   @0x2fd184 ite eq
 *   @0x2fd188 smlabbhs r0, r0, r1, r4
 *   @0x2fd18c cmp r3, #0x3
 *   @0x2fd190 strh.w r2, [r4, #0x12a]
 *   @0x2fd194 strh.w r1, [r4, #0x12c]
 *   @0x2fd198 strh.w r2, [r4, #0x126]
 *   @0x2fd19c strh.w r1, [r4, #0x128]
 *   @0x2fd1a0 lsls r0, r3, #0x1e
 *   @0x2fd1a4 strhpl.w r2, [r4, #0x12e]
 *   @0x2fd1a8 strhpl.w r1, [r4, #0x130]
 *   @0x2fd1ac mov r0, r4
 *   @0x2fd1b0 .word 0xf001f957
 *   @0x2fd1b4 .word 0xf504bcf9
 *   @0x2fd1b8 qadd8mi r7, r0, r5
 *   @0x2fd1bc ldrh r1, [r7, #0x4]
 *   @0x2fd1c0 strbmi r2, [r3], -r6, lsr #32
 *   @0x2fd1c4 bl 0x2fb284 <ps_hints_apply+0x9e84>
 *   @0x2fd1c8 cmp r0, #0x0
 *   @0x2fd1cc .word 0xf8d484ed
 *   @0x2fd1d0 strtmi r3, [r0], -r10, lsr #2
 *   @0x2fd1d4 str.w r3, [r4, #0x126]
 *   @0x2fd1d8 bl 0x2f9460 <ps_hints_apply+0x8060>
 *   @0x2fd1dc b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd1e0 mov r0, r4
 *   @0x2fd1e4 ldrh.w r2, [r5, r6, lsl #2]
 *   @0x2fd1e8 add.w r3, r4, #0x12e
 *   @0x2fd1ec bl 0x2fb284 <ps_hints_apply+0x9e84>
 *   @0x2fd1f0 cmp r0, #0x0
 *   @0x2fd1f4 .word 0xe7d984d9
 *   @0x2fd1f8 add.w r3, r4, #0x12a
 *   @0x2fd1fc ldrsh.w r0, [r5, r6, lsl #2]
 *   @0x2fd200 ldrsh.w r1, [r7, #0x4]
 *   @0x2fd204 mov r5, r3
 *   @0x2fd208 bl 0x2fb254 <ps_hints_apply+0x9e54>
 *   @0x2fd20c ldr r3, [r5]
 *   @0x2fd210 str.w r3, [r4, #0x126]
 *   @0x2fd214 bl 0x2f9460 <ps_hints_apply+0x8060>
 *   @0x2fd218 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd21c ldrsh.w r0, [r5, r6, lsl #2]
 *   @0x2fd220 add.w r2, r4, #0x12e
 *   @0x2fd224 ldrsh.w r1, [r7, #0x4]
 *   @0x2fd228 bl 0x2fb254 <ps_hints_apply+0x9e54>
 *   @0x2fd22c mov r0, r4
 *   @0x2fd230 .word 0xf001f917
 *   @0x2fd234 rfeib r4!
 *   @0x2fd238 .word 0xf845312a
 *   @0x2fd23c rfeib r4!
 *   @0x2fd240 rsbsvs r3, r11, r12, lsr #2
 *   @0x2fd244 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd248 ldrsh.w r3, [r4, #0x12e]
 *   @0x2fd24c str.w r3, [r5, r6, lsl #2]
 *   @0x2fd250 ldrsh.w r3, [r4, #0x130]
 *   @0x2fd254 str r3, [r7, #0x4]
 *   @0x2fd258 .word 0xf8d4bca7
 *   @0x2fd25c strtmi r3, [r0], -r10, lsr #2
 *   @0x2fd260 str.w r3, [r4, #0x12e]
 *   @0x2fd264 bl 0x2f9460 <ps_hints_apply+0x8060>
 *   @0x2fd268 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd26c ldr.w r6, [r5, r6, lsl #2]
 *   @0x2fd270 ldr r2, [r7, #0x10]
 *   @0x2fd274 str r6, [sp, #0x1c]
 *   @0x2fd278 ldr r6, [r7, #0x8]
 *   @0x2fd27c cmp r7, r3
 *   @0x2fd280 bhs 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd284 ldrmi pc, [r11, #0xb82]
 *   @0x2fd288 bhs 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd28c adclt r3, sp, #80
 *   @0x2fd290 cmp r5, r3
 *   @0x2fd294 uxth r6, r6
 *   @0x2fd298 bhs 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd29c ldrh.w r3, [r4, #0x74]
 *   @0x2fd2a0 uxth.w r10, r7
 *   @0x2fd2a4 cmp r3, r10
 *   @0x2fd2a8 ldrb.w r3, [r4, #0x235]
 *   @0x2fd2ac cmp r3, #0x0
 *   @0x2fd2b0 orrhs r8, r6, #2063597568
 *   @0x2fd2b4 str r3, [r4, #0xc]
 *   @0x2fd2b8 b 0x16ec49c <b2_toiTime+0xf92ff8>
 *   @0x2fd2bc .word 0xf8dd08cb
 *   @0x2fd2c0 blvs 0x1bed2f8 <b2_toiTime+0x1493e54>
 *   @0x2fd2c4 str.w r8, [sp, #0x20]
 *   @0x2fd2c8 mov r2, r8
 *   @0x2fd2cc b 0x16dd304 <b2_toiTime+0xf83e60>
 *   @0x2fd2d0 ldrmi r0, [r10], #-3276
 *   @0x2fd2d4 str.w r12, [sp, #0x24]
 *   @0x2fd2d8 mov r1, r12
 *   @0x2fd2dc .word 0xf853c058
 *   @0x2fd2e0 b 0x16d93c8 <b2_toiTime+0xf7ff24>
 *   @0x2fd2e4 ldrmi r0, [r9], #-2246
 *   @0x2fd2e8 ldr.w r3, [r3, r11, lsl #3]
 *   @0x2fd2ec str.w r8, [sp, #0x28]
 *   @0x2fd2f0 mov lr, r8
 *   @0x2fd2f4 stmdavs r9, {r0, r2, r6, r7, r11} ^
 *   @0x2fd2f8 subs r3, r3, r7
 *   @0x2fd2fc ldr r3, [r2, #0x4]
 *   @0x2fd300 ldr.w r0, [r12, r5, lsl #3]
 *   @0x2fd304 mov r2, r8
 *   @0x2fd308 strbtmi r9, [r2], #-54
 *   @0x2fd30c subs r3, r3, r1
 *   @0x2fd310 .word 0xf1c38014
 *   @0x2fd314 .word 0xf8de0c00
 *   @0x2fd318 ldmdavs r2, {r2, pc} ^
 *   @0x2fd31c rsb r9, r0, r9
 *   @0x2fd320 subs r0, r7, r0
 *   @0x2fd324 rsb r8, r2, r8
 *   @0x2fd328 mov r0, r9
 *   @0x2fd32c mov r1, r12
 *   @0x2fd330 movs r2, #0x40
 *   @0x2fd334 movwls r12, #0x202c
 *   @0x2fd338 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2fd33c ldr r1, [sp, #0x10]
 *   @0x2fd340 mov r7, r0
 *   @0x2fd344 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2fd348 ldr r1, [sp, #0x10]
 *   @0x2fd34c add r7, r0
 *   @0x2fd350 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2fd354 ldr r3, [sp, #0x8]
 *   @0x2fd358 mov r1, r3
 *   @0x2fd35c mov r0, r8
 *   @0x2fd360 .word 0xf7e7c008
 *   @0x2fd364 b 0xfe4fc718 <b2_toiTime+0xfffffffffdda3274>
 *   @0x2fd368 bl 0xfebda30c <b2_toiTime+0xfffffffffe480e68>
 *   @0x2fd36c andshs r7, r3, #-1677721597
 *   @0x2fd370 ldr.w r12, [sp, #0x8]
 *   @0x2fd374 muls r3, r2, r3
 *   @0x2fd378 eor.w r12, r0, r0, asr #31
 *   @0x2fd37c sub.w r12, r12, r0, asr #31
 *   @0x2fd380 cmp r3, r12
 *   @0x2fd384 stcle p3, c0, [r8, #-808]!
 *   @0x2fd388 ldr r1, [sp, #0x2c]
 *   @0x2fd38c ldr r0, [sp, #0x30]
 *   @0x2fd390 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2fd394 ldr r1, [sp, #0x10]
 *   @0x2fd398 mov r6, r0
 *   @0x2fd39c bl 0x2e4d3c <FT_MulDiv>
 *   @0x2fd3a0 mov r1, r9
 *   @0x2fd3a4 add r6, r0
 *   @0x2fd3a8 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2fd3ac mov r1, r8
 *   @0x2fd3b0 mov r9, r0
 *   @0x2fd3b4 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2fd3b8 ldr r1, [r4, #0x58]
 *   @0x2fd3bc ldr.w r1, [r1, r5, lsl #3]
 *   @0x2fd3c0 ldr r5, [sp, #0x14]
 *   @0x2fd3c4 str.w r1, [r2, r10, lsl #3]
 *   @0x2fd3c8 ldr r3, [sp, #0x8]
 *   @0x2fd3cc add r3, r2
 *   @0x2fd3d0 add r2, r5
 *   @0x2fd3d4 add r0, r2
 *   @0x2fd3d8 b 0x2fd432 <TT_RunIns+0x63e>
 *   @0x2fd3dc ldr r2, [r4, #0x34]
 *   @0x2fd3e0 ldr.w r5, [r1, r5, lsl #3]
 *   @0x2fd3e4 ldr.w r1, [r1, r6, lsl #3]
 *   @0x2fd3e8 ldr r6, [sp, #0xc]
 *   @0x2fd3ec ldr r7, [sp, #0x28]
 *   @0x2fd3f0 .word 0xf8528020
 *   @0x2fd3f4 strmi r1, [sp], #-54
 *   @0x2fd3f8 ldr.w r1, [r2, r11, lsl #3]
 *   @0x2fd3fc adds r1, r5, r1
 *   @0x2fd400 addmi r1, #0x3
 *   @0x2fd404 str.w r1, [r0, r10, lsl #3]
 *   @0x2fd408 ldr r0, [r4, #0x7c]
 *   @0x2fd40c add r3, r0
 *   @0x2fd410 ldr r1, [r4, #0x34]
 *   @0x2fd414 add r2, r7
 *   @0x2fd418 ldr r2, [r2, #0x4]
 *   @0x2fd41c ldr r0, [sp, #0x24]
 *   @0x2fd420 add r1, r8
 *   @0x2fd424 ldr r1, [r1, #0x4]
 *   @0x2fd428 adds r2, r2, r1
 *   @0x2fd42c addmi r2, #0x3
 *   @0x2fd430 str r2, [r3, #0x4]
 *   @0x2fd434 .word 0xf8d4c01c
 *   @0x2fd438 blx 0xac5650 <b2_toiTime+0x36c1ac>
 *   @0x2fd43c ldclpl p3, c15, [r1], {140}
 *   @0x2fd440 orr r1, r1, #0x18
 *   @0x2fd444 strb r1, [r2, r3]
 *   @0x2fd448 .word 0xf855bbaf
 *   @0x2fd44c .word 0xf8a43026
 *   @0x2fd450 .word 0xf0013120
 *   @0x2fd454 .word 0xf855bba9
 *   @0x2fd458 .word 0xf8a43026
 *   @0x2fd45c .word 0xf0013122
 *   @0x2fd460 .word 0xf855bba3
 *   @0x2fd464 .word 0xf8a43026
 *   @0x2fd468 .word 0xf0013124
 *   @0x2fd46c .word 0xf855bb9d
 *   @0x2fd470 teqlt r11, r6, lsr #32
 *   @0x2fd474 cmp r3, #0x1
 *   @0x2fd478 .word 0xf104af17
 *   @0x2fd47c .word 0xf1040724
 *   @0x2fd480 mul r3, r0, r12
 *   @0x2fd484 add.w r7, r4, #0x24
 *   @0x2fd488 add.w r12, r4, #0xb4
 *   @0x2fd48c ldm.w r12!, {r0, r1, r2, r3}
 *   @0x2fd490 stm r7!, {r0, r1, r2, r3}
 *   @0x2fd494 strgt r0, [pc, -pc]
 *   @0x2fd498 ldr.w r3, [r12]
 *   @0x2fd49c str r3, [r7]
 *   @0x2fd4a0 .word 0xf8a43026
 *   @0x2fd4a4 .word 0xf001315c
 *   @0x2fd4a8 .word 0xf855bb7f
 *   @0x2fd4ac teqlt r11, r6, lsr #32
 *   @0x2fd4b0 cmp r3, #0x1
 *   @0x2fd4b4 .word 0xf104aef9
 *   @0x2fd4b8 .word 0xf1040748
 *   @0x2fd4bc mul r3, r0, r12
 *   @0x2fd4c0 add.w r7, r4, #0x48
 *   @0x2fd4c4 add.w r12, r4, #0xb4
 *   @0x2fd4c8 ldm.w r12!, {r0, r1, r2, r3}
 *   @0x2fd4cc stm r7!, {r0, r1, r2, r3}
 *   @0x2fd4d0 strgt r0, [pc, -pc]
 *   @0x2fd4d4 ldr.w r3, [r12]
 *   @0x2fd4d8 str r3, [r7]
 *   @0x2fd4dc .word 0xf8a43026
 *   @0x2fd4e0 .word 0xf001315e
 *   @0x2fd4e4 .word 0xf855bb61
 *   @0x2fd4e8 teqlt r11, r6, lsr #32
 *   @0x2fd4ec cmp r3, #0x1
 *   @0x2fd4f0 .word 0xf104aedb
 *   @0x2fd4f4 .word 0xf104076c
 *   @0x2fd4f8 mul r3, r0, r12
 *   @0x2fd4fc add.w r7, r4, #0x6c
 *   @0x2fd500 add.w r12, r4, #0xb4
 *   @0x2fd504 ldm.w r12!, {r0, r1, r2, r3}
 *   @0x2fd508 stm r7!, {r0, r1, r2, r3}
 *   @0x2fd50c strgt r0, [pc, -pc]
 *   @0x2fd510 ldr.w r3, [r12]
 *   @0x2fd514 str r3, [r7]
 *   @0x2fd518 .word 0xf8a43026
 *   @0x2fd51c .word 0xf0013160
 *   @0x2fd520 .word 0xf855bb43
 *   @0x2fd524 teqlt r11, r6, lsr #32
 *   @0x2fd528 cmp r3, #0x1
 *   @0x2fd52c .word 0xf104aebd
 *   @0x2fd530 .word 0xf1040724
 *   @0x2fd534 mul r3, r0, r12
 *   @0x2fd538 add.w r7, r4, #0x24
 *   @0x2fd53c add.w r12, r4, #0xb4
 *   @0x2fd540 ldm.w r12!, {r0, r1, r2, r3}
 *   @0x2fd544 add.w r8, r4, #0x24
 *   @0x2fd548 stm r7!, {r0, r1, r2, r3}
 *   @0x2fd54c strgt r0, [pc, -pc]
 *   @0x2fd550 ldr.w r3, [r12]
 *   @0x2fd554 add.w r12, r4, #0x48
 *   @0x2fd558 str r3, [r7]
 *   @0x2fd55c svcgt #0xf0724
 *   @0x2fd560 stm.w r12!, {r0, r1, r2, r3}
 *   @0x2fd564 ldm r7!, {r0, r1, r2, r3}
 *   @0x2fd568 ldmdavs r11!, {r0, r1, r2, r3}
 *   @0x2fd56c str.w r3, [r12]
 *   @0x2fd570 add.w r12, r4, #0x6c
 *   @0x2fd574 ldm.w r8!, {r0, r1, r2, r3}
 *   @0x2fd578 stm.w r12!, {r0, r1, r2, r3}
 *   @0x2fd57c ldm.w r8!, {r0, r1, r2, r3}
 *   @0x2fd580 stm.w r12!, {r0, r1, r2, r3}
 *   @0x2fd584 ldr r3, [r7]
 *   @0x2fd588 .word 0xf8553000
 *   @0x2fd58c .word 0xf8a43026
 *   @0x2fd590 .word 0xf855315c
 *   @0x2fd594 .word 0xf8a43026
 *   @0x2fd598 .word 0xf855315e
 *   @0x2fd59c .word 0xf8a43026
 *   @0x2fd5a0 .word 0xf0013160
 *   @0x2fd5a4 .word 0xf855bb01
 *   @0x2fd5a8 blhs 0x309648 <TT_New_Context+0x9440>
 *   @0x2fd5ac itee ge
 *   @0x2fd5b0 orrhs r3, r4, #52, #2
 *   @0x2fd5b4 strlt r3, [r4, #0xc]
 *   @0x2fd5b8 .word 0xf8dfbaf7
 *   @0x2fd5bc .word 0xf8c43504
 *   @0x2fd5c0 ldrbtmi r0, [r11], #-316
 *   @0x2fd5c4 str.w r3, [r4, #0x23c]
 *   @0x2fd5c8 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd5cc ldr.w r3, [pc, #0x4f4]
 *   @0x2fd5d0 str.w r1, [r4, #0x13c]
 *   @0x2fd5d4 add r3, pc
 *   @0x2fd5d8 .word 0xf001323c
 *   @0x2fd5dc .word 0xf855bae5
 *   @0x2fd5e0 .word 0xf8c43026
 *   @0x2fd5e4 .word 0xf0013138
 *   @0x2fd5e8 strhs r11, [r1, #-0xadf]
 *   @0x2fd5ec mov r0, r4
 *   @0x2fd5f0 stmdahs r1, {r0, r1, r2, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2fd5f4 beq.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd5f8 ldrb.w r3, [r4, #0x174]
 *   @0x2fd5fc cmp r3, #0x58
 *   @0x2fd600 cmp r3, #0x59
 *   @0x2fd604 subs r5, #0x1
 *   @0x2fd608 adds r5, #0x1
 *   @0x2fd60c bne 0x2fd5ec <TT_RunIns+0x7f8>
 *   @0x2fd610 strtmi r11, [r0], -r11, asr #21
 *   @0x2fd614 mov r1, r7
 *   @0x2fd618 .word 0xf001f839
 *   @0x2fd61c .word 0xf855bac5
 *   @0x2fd620 .word 0xf8c43026
 *   @0x2fd624 .word 0xf0013144
 *   @0x2fd628 .word 0xf855babf
 *   @0x2fd62c .word 0xf8c43026
 *   @0x2fd630 .word 0xf0013148
 *   @0x2fd634 .word 0xf855bab9
 *   @0x2fd638 .word 0xf8d40026
 *   @0x2fd63c .word 0xf7fb1108
 *   @0x2fd640 .word 0xf8c4fbe4
 *   @0x2fd644 .word 0xf001014c
 *   @0x2fd648 .word 0xf855baaf
 *   @0x2fd64c rsbsvs r3, r11, r6, lsr #32
 *   @0x2fd650 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd654 str r1, [r4, #0x20]
 *   @0x2fd658 .word 0xf855baa7
 *   @0x2fd65c ldmdavs r11!, {r1, r2, r5, sp} ^
 *   @0x2fd660 str.w r3, [r5, r6, lsl #2]
 *   @0x2fd664 str r2, [r7, #0x4]
 *   @0x2fd668 stmdbvs r3!, {r0, r1, r2, r3, r4, r7, r9, r11, r12, sp, pc}
 *   @0x2fd66c str.w r3, [r5, r6, lsl #2]
 *   @0x2fd670 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd674 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fd678 cmp r3, #0x0
 *   @0x2fd67c cmp r3, r6
 *   @0x2fd680 ldrb.w r3, [r4, #0x235]
 *   @0x2fd684 cbz r3, 0x2fd68a <TT_RunIns+0x896>
 *   @0x2fd688 str r3, [r4, #0xc]
 *   @0x2fd68c str.w r3, [r5, r6, lsl #2]
 *   @0x2fd690 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd694 subs r3, r6, r3
 *   @0x2fd698 .word 0xf8453023
 *   @0x2fd69c .word 0xf0013026
 *   @0x2fd6a0 .word 0xf855ba83
 *   @0x2fd6a4 bhs 0x305744 <TT_New_Context+0x553c>
 *   @0x2fd6a8 ble.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd6ac cmp r2, r6
 *   @0x2fd6b0 bne 0xff0a8ea4 <b2_toiTime+0xfffffffffe94fa00>
 *   @0x2fd6b4 subs r2, #0x1
 *   @0x2fd6b8 lsls r2, r2, #0x2
 *   @0x2fd6bc add r0, r5
 *   @0x2fd6c0 ldr.w r6, [r5, r6, lsl #2]
 *   @0x2fd6c4 blx 0xb6694 <memmove@plt>
 *   @0x2fd6c8 ldr r3, [r4, #0x1c]
 *   @0x2fd6cc add.w r3, r3, #0x40000000
 *   @0x2fd6d0 subs r3, #0x1
 *   @0x2fd6d4 .word 0xf0016023
 *   @0x2fd6d8 rfeda r5!
 *   @0x2fd6dc rfeia r4!
 *   @0x2fd6e0 ldmdavs lr!, {r4, r6, r12, sp} ^
 *   @0x2fd6e4 cmp r3, r8
 *   @0x2fd6e8 stchi p13, c10, [r3, #892]!
 *   @0x2fd6ec uxth r6, r6
 *   @0x2fd6f0 bls.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd6f4 ldr r2, [r4, #0x34]
 *   @0x2fd6f8 add.w r5, r2, r6, lsl #3
 *   @0x2fd6fc add.w r0, r3, r8, lsl #3
 *   @0x2fd700 ldr.w r7, [r2, r6, lsl #3]
 *   @0x2fd704 ldr.w r1, [r3, r8, lsl #3]
 *   @0x2fd708 ldr r5, [r5, #0x4]
 *   @0x2fd70c subs r1, r7, r1
 *   @0x2fd710 strtmi r3, [r0], -r0, asr #4
 *   @0x2fd714 subs r2, r5, r2
 *   @0x2fd718 ldr.w r5, [r4, #0x24c]
 *   @0x2fd71c add.w r1, r4, #0x48
 *   @0x2fd720 mov r2, r8
 *   @0x2fd724 ldrdne r7, r8, [r7], #-0
 *   @0x2fd728 mov r0, r4
 *   @0x2fd72c blx r5
 *   @0x2fd730 strtmi r5, [r0], -r12, asr #4
 *   @0x2fd734 add.w r1, r4, #0x24
 *   @0x2fd738 mov r2, r6
 *   @0x2fd73c blx r5
 *   @0x2fd740 qasxmi r11, r0, r3
 *   @0x2fd744 bl 0x2fb4ec <ps_hints_apply+0xa0ec>
 *   @0x2fd748 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd74c ldrh r2, [r4, #0x2c]
 *   @0x2fd750 addsmi r3, r10, #38
 *   @0x2fd754 bls.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fd758 ldrsh.w r2, [r4, #0x12e]
 *   @0x2fd75c ldrsh.w r1, [r4, #0x130]
 *   @0x2fd760 cmp r2, #0x0
 *   @0x2fd764 movne r2, #0xf7
 *   @0x2fd768 cbz r1, 0x2fd76e <TT_RunIns+0x97a>
 *   @0x2fd76c blvs 0xffb3e330 <b2_toiTime+0xffffffffff3e4e8c>
 *   @0x2fd770 ldrb r0, [r1, r3]
 *   @0x2fd774 strb r2, [r1, r3]
 *   @0x2fd778 qadd16mi r11, r0, r7
 *   @0x2fd77c mov r1, r7
 *   @0x2fd780 .word 0xf001fe5b
 *   @0x2fd784 .word 0xf8d4ba11
 *   @0x2fd788 .word 0xf85531a8
 *   @0x2fd78c movwlo r2, #0x1026
 *   @0x2fd790 cmp r2, r3
 *   @0x2fd794 ldr.w r0, [r4, #0x190]
 *   @0x2fd798 ldr.w r1, [r4, #0x198]
 *   @0x2fd79c cmp r3, r0
 *   @0x2fd7a0 movs r3, #0x18
 *   @0x2fd7a4 ldmvs sp, {r1, r8, r9, r12} ^
 *   @0x2fd7a8 cmp r5, r2
 *   @0x2fd7ac movs r3, #0x18
 *   @0x2fd7b0 strmi r1, [r11], -r0
 *   @0x2fd7b4 cmp r3, r0
 *   @0x2fd7b8 cmp r3, r0
 *   @0x2fd7bc b 0x2fd81a <TT_RunIns+0xa26>
 *   @0x2fd7c0 cmp r1, r2
 *   @0x2fd7c4 adds r3, #0x18
 *   @0x2fd7c8 ldrb r2, [r3, #0x10]
 *   @0x2fd7cc ldr.w r2, [r4, #0x1b0]
 *   @0x2fd7d0 ldr.w r1, [r4, #0x1b4]
 *   @0x2fd7d4 cmp r2, r1
 *   @0x2fd7d8 movs r3, #0x82
 *   @0x2fd7dc b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd7e0 ldr.w r5, [r4, #0x1b8]
 *   @0x2fd7e4 lsls r1, r2, #0x4
 *   @0x2fd7e8 stmdane r10!, {r2, r5, r6, r8} ^
 *   @0x2fd7ec str r0, [r5, r1]
 *   @0x2fd7f0 ldr.w r1, [r4, #0x16c]
 *   @0x2fd7f4 str r3, [r2, #0xc]
 *   @0x2fd7f8 str r1, [r2, #0x4]
 *   @0x2fd7fc str r1, [r2, #0x8]
 *   @0x2fd800 strmi r2, [r10], #-432
 *   @0x2fd804 str.w r2, [r4, #0x1b0]
 *   @0x2fd808 ldm.w r3, {r1, r2}
 *   @0x2fd80c bl 0x2fb3f6 <ps_hints_apply+0x9ff6>
 *   @0x2fd810 movs r3, #0x0
 *   @0x2fd814 .word 0xf001317c
 *   @0x2fd818 orrhs r11, r6, #3260416
 *   @0x2fd81c str r3, [r4, #0xc]
 *   @0x2fd820 strtmi r11, [r0], -r3, asr #19
 *   @0x2fd824 mov r1, r7
 *   @0x2fd828 .word 0xf001fedb
 *   @0x2fd82c .word 0xf8d4b9bd
 *   @0x2fd830 bhs 0x305ef8 <TT_New_Context+0x5cf0>
 *   @0x2fd834 bgt 0x2fd83e <TT_RunIns+0xa4a>
 *   @0x2fd838 str r3, [r4, #0xc]
 *   @0x2fd83c blo 0x36bf18 <_ZTS13C_UTF16String+0x2fc4>
 *   @0x2fd840 ldr.w r1, [r4, #0x1b8]
 *   @0x2fd844 str.w r2, [r4, #0x1b0]
 *   @0x2fd848 lsls r2, r2, #0x4
 *   @0x2fd84c ldr r0, [r3, #0x8]
 *   @0x2fd850 str r0, [r3, #0x8]
 *   @0x2fd854 strb.w r0, [r4, #0x17c]
 *   @0x2fd858 ldr r0, [r3, #0x8]
 *   @0x2fd85c ble 0x2fd874 <TT_RunIns+0xa80>
 *   @0x2fd860 andlo r2, r1, #176, #2
 *   @0x2fd864 str.w r2, [r4, #0x1b0]
 *   @0x2fd868 ldr r3, [r3, #0xc]
 *   @0x2fd86c str.w r3, [r4, #0x16c]
 *   @0x2fd870 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd874 ldr r1, [r1, r2]
 *   @0x2fd878 ldr r2, [r3, #0x4]
 *   @0x2fd87c .word 0xf001fdbc
 *   @0x2fd880 rfeda r5!
 *   @0x2fd884 stchi p0, c6, [r2, #152]!
 *   @0x2fd888 cmp r2, r6
 *   @0x2fd88c .word 0xf013ad0d
 *   @0x2fd890 andsle r0, r2, r1, lsl #6
 *   @0x2fd894 ldr r2, [r4, #0x34]
 *   @0x2fd898 ldr.w r3, [r4, #0x240]
 *   @0x2fd89c add.w r5, r2, r6, lsl #3
 *   @0x2fd8a0 ldr.w r1, [r2, r6, lsl #3]
 *   @0x2fd8a4 ldr r2, [r5, #0x4]
 *   @0x2fd8a8 ldr.w r5, [r4, #0x23c]
 *   @0x2fd8ac ldr.w r2, [r4, #0x10c]
 *   @0x2fd8b0 mov r7, r0
 *   @0x2fd8b4 mov r1, r7
 *   @0x2fd8b8 subs r3, r0, r7
 *   @0x2fd8bc strtmi r5, [r0], -r12, asr #4
 *   @0x2fd8c0 add.w r1, r4, #0x24
 *   @0x2fd8c4 mov r2, r6
 *   @0x2fd8c8 strh.w r6, [r4, #0x120]
 *   @0x2fd8cc strh.w r6, [r4, #0x122]
 *   @0x2fd8d0 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd8d4 ldr r2, [r4]
 *   @0x2fd8d8 ldr r2, [r2, #0x40]
 *   @0x2fd8dc bne 0x2fd906 <TT_RunIns+0xb12>
 *   @0x2fd8e0 orrlt r2, r2, r7, ror #4
 *   @0x2fd8e4 ldrb.w r2, [r4, #0x268]
 *   @0x2fd8e8 cbz r2, 0x2fd8f4 <TT_RunIns+0xb00>
 *   @0x2fd8ec bhs 0x306298 <TT_New_Context+0x6090>
 *   @0x2fd8f0 bne.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd8f4 tst.w r3, #0x1
 *   @0x2fd8f8 mov.w r2, #0x1
 *   @0x2fd8fc ite ne
 *   @0x2fd900 .word 0xf8842268
 *   @0x2fd904 rfeib r4!
 *   @0x2fd908 bhs 0x305b78 <TT_New_Context+0x5970>
 *   @0x2fd90c beq.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fd910 tst.w r3, #0x1
 *   @0x2fd914 add.w r1, r4, #0x9c
 *   @0x2fd918 ldm r1, {r1, r2, r3}
 *   @0x2fd91c movs r5, #0x8
 *   @0x2fd920 str r2, [sp, #0x50]
 *   @0x2fd924 str r5, [sp, #0xc]
 *   @0x2fd928 adds r1, #0x4
 *   @0x2fd92c adds r3, #0x4
 *   @0x2fd930 str r1, [sp, #0x4c]
 *   @0x2fd934 str r3, [sp, #0x54]
 *   @0x2fd938 ldrh.w r3, [r4, #0x98]
 *   @0x2fd93c mov.w r10, #0x0
 *   @0x2fd940 add.w r11, sp, #0x4c
 *   @0x2fd944 mov r7, r10
 *   @0x2fd948 ldr.w r3, [r4, #0xac]
 *   @0x2fd94c sxth.w r2, r10
 *   @0x2fd950 mov r5, r7
 *   @0x2fd954 rfeia r4!
 *   @0x2fd958 bl 0xff3c9c20 <b2_toiTime+0xfffffffffec7077c>
 *   @0x2fd95c rfeia r4!
 *   @0x2fd960 ldrmi r3, [r9, #0x98]
 *   @0x2fd964 it hs
 *   @0x2fd968 strbmi r3, [sp, #-0x9ff]
 *   @0x2fd96c bhi 0x2fda22 <TT_RunIns+0xc2e>
 *   @0x2fd970 .word 0xf8dd30a8
 *   @0x2fd974 ldclpl p0, c8, [r11, #-48]
 *   @0x2fd978 tst.w r8, r3
 *   @0x2fd97c add.w r3, r5, #0x1
 *   @0x2fd980 bne 0x2fd986 <TT_RunIns+0xb92>
 *   @0x2fd984 b 0x2fd96a <TT_RunIns+0xb76>
 *   @0x2fd988 mov r6, r5
 *   @0x2fd98c cmp r5, r9
 *   @0x2fd990 ldr.w r3, [r4, #0xa8]
 *   @0x2fd994 ldr.w r12, [sp, #0xc]
 *   @0x2fd998 ldrb r3, [r3, r5]
 *   @0x2fd99c andle r0, r7, r3, lsl #30
 *   @0x2fd9a0 adds r1, r6, #0x1
 *   @0x2fd9a4 str r5, [sp]
 *   @0x2fd9a8 subs r2, r5, #0x1
 *   @0x2fd9ac bl 0x2fb894 <ps_hints_apply+0xa494>
 *   @0x2fd9b0 adds r5, #0x1
 *   @0x2fd9b4 cmp r6, r8
 *   @0x2fd9b8 ldr r3, [sp, #0x50]
 *   @0x2fd9bc .word 0xf85308c6
 *   @0x2fd9c0 blls 0x7c5aa0 <b2_toiTime+0x6c5fc>
 *   @0x2fd9c4 ldr.w r3, [r3, r6, lsl #3]
 *   @0x2fd9c8 subs r2, r2, r3
 *   @0x2fd9cc lsls r3, r7, #0x3
 *   @0x2fd9d0 bhs 0x2fd9e0 <TT_RunIns+0xbec>
 *   @0x2fd9d4 adds r7, #0x1
 *   @0x2fd9d8 add r0, r2
 *   @0x2fd9dc adds r3, #0x8
 *   @0x2fd9e0 adds r6, #0x1
 *   @0x2fd9e4 strbmi r0, [lr, #-0x808]
 *   @0x2fd9e8 bhi 0x2fda22 <TT_RunIns+0xc2e>
 *   @0x2fd9ec ldr.w r3, [r1, r8]
 *   @0x2fd9f0 add r3, r2
 *   @0x2fd9f4 ldrb r3, [r3, r8]!
 *   @0x2fd9f8 adds r1, r6, #0x1
 *   @0x2fd9fc ldrbmi r8, [r8], -r0
 *   @0x2fda00 mov r2, r9
 *   @0x2fda04 mov r3, r6
 *   @0x2fda08 .word 0xf1b8ff45
 *   @0x2fda0c andle r0, r8, r0, lsl #30
 *   @0x2fda10 str.w r8, [sp]
 *   @0x2fda14 mov r0, r11
 *   @0x2fda18 add.w r2, r8, #0xffffffff
 *   @0x2fda1c mov r3, r6
 *   @0x2fda20 .word 0xf10aff39
 *   @0x2fda24 rfeib r4!
 *   @0x2fda28 blx 0xac5c98 <b2_toiTime+0x36c7f4>
 *   @0x2fda2c blx 0x6fc464 <g_SWFvertbuff+0x2939c>
 *   @0x2fda30 addsmi pc, r10, #671088642
 *   @0x2fda34 ble.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fda38 mov r7, r5
 *   @0x2fda3c mov r0, r4
 *   @0x2fda40 .word 0xf001fad6
 *   @0x2fda44 rfeia r4!
 *   @0x2fda48 .word 0xf8553160
 *   @0x2fda4c tstlt r3, r6, lsr #32
 *   @0x2fda50 ldrh.w r3, [r4, #0x76]
 *   @0x2fda54 b 0x2fda58 <TT_RunIns+0xc64>
 *   @0x2fda58 uxth r6, r6
 *   @0x2fda5c blo 0x2fdac8 <TT_RunIns+0xcd4>
 *   @0x2fda60 blhs 0x30a33c <af_shaper_get_coverage+0x838>
 *   @0x2fda64 beq.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fda68 movs r3, #0x86
 *   @0x2fda6c b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fda70 bvc 0x2fda26 <TT_RunIns+0xc32>
 *   @0x2fda74 .word 0xffffd7b5
 *   @0x2fda78 .word 0xffffd78f
 *   @0x2fda7c .word 0xffffd763
 *   @0x2fda80 .word 0xffffc3e1
 *   @0x2fda84 .word 0xffffc3dd
 *   @0x2fda88 .word 0xffffc3dd
 *   @0x2fda8c .word 0xffffc3dd
 *   @0x2fda90 .word 0xffffc46b
 *   @0x2fda94 .word 0xffffe63d
 *   @0x2fda98 .word 0xffffe69d
 *   @0x2fda9c .word 0xffffe677
 *   @0x2fdaa0 .word 0xffffe647
 *   @0x2fdaa4 .word 0xffffe6a7
 *   @0x2fdaa8 .word 0xffffe6c1
 *   @0x2fdaac .word 0xffffe6f5
 *   @0x2fdab0 andeq r2, r10, r6, lsr #31
 *   @0x2fdab4 cmp r7, #0xa2
 *   @0x2fdab8 cmp r7, #0x52
 *   @0x2fdabc cmp r6, #0xec
 *   @0x2fdac0 svc #0x99
 *   @0x2fdac4 .word 0xffffdfa9
 *   @0x2fdac8 movteq pc, #0x210d
 *   @0x2fdacc mov r0, r4
 *   @0x2fdad0 add r1, sp, #0x44
 *   @0x2fdad4 add r3, sp, #0x4c
 *   @0x2fdad8 stmdahs r0, {r1, r3, r4, r9, r11, r12, sp, lr, pc}
 *   @0x2fdadc bne.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fdae0 cbz r6, 0x2fdb00 <TT_RunIns+0xd0c>
 *   @0x2fdae4 ldr.w r2, [r4, #0x88]
 *   @0x2fdae8 add.w r3, r3, #0x80000000
 *   @0x2fdaec ldrh.w r5, [r4, #0x8c]
 *   @0x2fdaf0 subs r3, #0x1
 *   @0x2fdaf4 rfeda r2!
 *   @0x2fdaf8 ldrmi r3, [sp], #-19
 *   @0x2fdafc uxth r5, r5
 *   @0x2fdb00 mov r5, r6
 *   @0x2fdb04 ldmdblt r3, {r5, r6, r8, r12, sp}
 *   @0x2fdb08 ldrh.w r6, [r4, #0x74]
 *   @0x2fdb0c b 0x2fdb24 <TT_RunIns+0xd30>
 *   @0x2fdb10 eorslt r3, r6, #136
 *   @0x2fdb14 ldrh.w r2, [r4, #0x8c]
 *   @0x2fdb18 ldrh.w r3, [r3, r6, lsl #1]
 *   @0x2fdb1c rsb.w r2, r2, #0x1
 *   @0x2fdb20 adds r6, r2, r3
 *   @0x2fdb24 movs r7, #0x1
 *   @0x2fdb28 bhs.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fdb2c ldr r3, [r4, #0x7c]
 *   @0x2fdb30 cmp r2, r3
 *   @0x2fdb34 ldrh.w r3, [sp, #0x42]
 *   @0x2fdb38 cmp r3, r5
 *   @0x2fdb3c str r7, [sp]
 *   @0x2fdb40 mov r1, r5
 *   @0x2fdb44 ldr r3, [sp, #0x48]
 *   @0x2fdb48 strlo pc, [r1, #-0xf0a]
 *   @0x2fdb4c uxth r5, r5
 *   @0x2fdb50 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fdb54 cmp r3, #0x1
 *   @0x2fdb58 ldrb.w r3, [r4, #0x235]
 *   @0x2fdb5c cmp r3, #0x0
 *   @0x2fdb60 orrhs r8, r6, #35
 *   @0x2fdb64 str r3, [r4, #0xc]
 *   @0x2fdb68 .word 0xf10db81f
 *   @0x2fdb6c strtmi r0, [r0], -r2, asr #6
 *   @0x2fdb70 str r3, [sp]
 *   @0x2fdb74 add r2, sp, #0x48
 *   @0x2fdb78 bl 0x2f9f0e <ps_hints_apply+0x8b0e>
 *   @0x2fdb7c cmp r0, #0x0
 *   @0x2fdb80 rfeia r4!
 *   @0x2fdb84 ldmdblt r3, {r5, r6, r8, r12, sp}
 *   @0x2fdb88 ldrh.w r6, [r4, #0x74]
 *   @0x2fdb8c b 0x2fdbb0 <TT_RunIns+0xdbc>
 *   @0x2fdb90 bne 0x2fdbae <TT_RunIns+0xdba>
 *   @0x2fdb94 blhs 0x309d74 <af_shaper_get_coverage+0x270>
 *   @0x2fdb98 ble 0x2fdbae <TT_RunIns+0xdba>
 *   @0x2fdb9c .word 0xf8d44300
 *   @0x2fdba0 bllo 0x345dc8
 *   @0x2fdba4 ldrh.w r6, [r2, r3, lsl #1]
 *   @0x2fdba8 adds r6, #0x1
 *   @0x2fdbac b 0x2fdbb0 <TT_RunIns+0xdbc>
 *   @0x2fdbb0 movs r5, #0x0
 *   @0x2fdbb4 cmp r5, r6
 *   @0x2fdbb8 svcvs #0xe387f7
 *   @0x2fdbbc ldr r2, [sp, #0x5c]
 *   @0x2fdbc0 bne 0x2fdbca <TT_RunIns+0xdd6>
 *   @0x2fdbc4 adcmi r3, r11, #66
 *   @0x2fdbc8 beq 0x2fdbd8 <TT_RunIns+0xde4>
 *   @0x2fdbcc mov r0, r4
 *   @0x2fdbd0 ldr r2, [sp, #0x44]
 *   @0x2fdbd4 bl 0x2f995e <ps_hints_apply+0x855e>
 *   @0x2fdbd8 adds r5, #0x1
 *   @0x2fdbdc b 0x2fdbb4 <TT_RunIns+0xdc0>
 *   @0x2fdbe0 mov r1, r7
 *   @0x2fdbe4 .word 0xf000fef6
 *   @0x2fdbe8 stmdbvs r2!, {r0, r1, r2, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, pc}
 *   @0x2fdbec ldr.w r3, [r4, #0x134]
 *   @0x2fdbf0 cmp r2, r3
 *   @0x2fdbf4 ldrb.w r3, [r4, #0x235]
 *   @0x2fdbf8 cmp r3, #0x0
 *   @0x2fdbfc orrhs r8, r6, #236
 *   @0x2fdc00 str r3, [r4, #0xc]
 *   @0x2fdc04 ldrh.w r3, [r4, #0x15c]
 *   @0x2fdc08 cbz r3, 0x2fdc20 <TT_RunIns+0xe2c>
 *   @0x2fdc0c teqlt r11, lr, asr r1
 *   @0x2fdc10 ldrh.w r8, [r4, #0x160]
 *   @0x2fdc14 rsbs.w r8, r8, #0x1
 *   @0x2fdc18 it lo
 *   @0x2fdc1c and r0, r1, r0, lsl #16
 *   @0x2fdc20 mov.w r8, #0x1
 *   @0x2fdc24 ldrh.w r6, [r4, #0x122]
 *   @0x2fdc28 ldrh r3, [r4, #0x2c]
 *   @0x2fdc2c bls 0x2fdbf4 <TT_RunIns+0xe00>
 *   @0x2fdc30 .word 0xf1b80ac6
 *   @0x2fdc34 andle r0, r1, r0, lsl #30
 *   @0x2fdc38 ldr r5, [r4, #0x30]
 *   @0x2fdc3c ldr r5, [r4, #0x38]
 *   @0x2fdc40 ldrbmi r3, [r5], #-292
 *   @0x2fdc44 ldrh.w r2, [r4, #0x50]
 *   @0x2fdc48 ldr r7, [r4, #0x34]
 *   @0x2fdc4c add r10, r7
 *   @0x2fdc50 ldr.w lr, [r5]
 *   @0x2fdc54 cmp.w r8, #0x0
 *   @0x2fdc58 beq 0x2fdc5e <TT_RunIns+0xe6a>
 *   @0x2fdc5c b 0x2fdc6c <TT_RunIns+0xe78>
 *   @0x2fdc60 .word 0xf8d420e4
 *   @0x2fdc64 addsmi r1, r1, #224
 *   @0x2fdc68 ldr r2, [r4, #0x5c]
 *   @0x2fdc6c add.w r0, r2, r3, lsl #3
 *   @0x2fdc70 ldr.w r1, [r2, r3, lsl #3]
 *   @0x2fdc74 ldr r2, [r5, #0x4]
 *   @0x2fdc78 rsb r1, lr, r1
 *   @0x2fdc7c mov r0, r4
 *   @0x2fdc80 ldr.w r3, [r4, #0x244]
 *   @0x2fdc84 b 0x2fdcb6 <TT_RunIns+0xec2>
 *   @0x2fdc88 bl 0xff67dd5c <b2_toiTime+0xfffffffffef248b8>
 *   @0x2fdc8c .word 0xf7fb0000
 *   @0x2fdc90 rfeia r4!
 *   @0x2fdc94 stclvs p1, c2, [r3, #144]!
 *   @0x2fdc98 ldr.w r1, [r4, #0xe4]
 *   @0x2fdc9c add.w r3, r3, r2, lsl #3
 *   @0x2fdca0 mov r9, r0
 *   @0x2fdca4 ldr r3, [r5, #0x4]
 *   @0x2fdca8 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fdcac ldr.w r3, [r4, #0x244]
 *   @0x2fdcb0 mov r1, r9
 *   @0x2fdcb4 mov r0, r4
 *   @0x2fdcb8 ldrh.w r2, [r4, #0x124]
 *   @0x2fdcbc ldr r3, [r4, #0x58]
 *   @0x2fdcc0 .word 0xf8537036
 *   @0x2fdcc4 blne 0xff541d94 <b2_toiTime+0xfffffffffede88f0>
 *   @0x2fdcc8 mov r9, r0
 *   @0x2fdccc .word 0xf8da00c2
 *   @0x2fdcd0 stmdavs r6, {r2, sp} ^
 *   @0x2fdcd4 mov r0, r4
 *   @0x2fdcd8 bne 0xfef8a5e0 <b2_toiTime+0xfffffffffe83113c>
 *   @0x2fdcdc blx r3
 *   @0x2fdce0 b 0x2fdce8 <TT_RunIns+0xef4>
 *   @0x2fdce4 str r6, [sp, #0xc]
 *   @0x2fdce8 add.w r7, r4, #0x6c
 *   @0x2fdcec str r7, [sp, #0x14]
 *   @0x2fdcf0 blhs 0x30a1c8 <af_shaper_get_coverage+0x6c4>
 *   @0x2fdcf4 ble 0x2fddd6 <TT_RunIns+0xfe2>
 *   @0x2fdcf8 ldr r2, [r4, #0x18]
 *   @0x2fdcfc str r3, [r4, #0x1c]
 *   @0x2fdd00 rfeia r4!
 *   @0x2fdd04 addsmi r3, lr, #116
 *   @0x2fdd08 blo 0x2fdd1a <TT_RunIns+0xf26>
 *   @0x2fdd0c blhs 0x30a5e8 <af_shaper_get_coverage+0xae4>
 *   @0x2fdd10 beq 0x2fddca <TT_RunIns+0xfd6>
 *   @0x2fdd14 str r3, [r4, #0xc]
 *   @0x2fdd18 .word 0xf8d5bf47
 *   @0x2fdd1c rscseq lr, r7, r0
 *   @0x2fdd20 cmp.w r8, #0x0
 *   @0x2fdd24 beq 0x2fdd2a <TT_RunIns+0xf36>
 *   @0x2fdd28 b 0x2fdd3a <TT_RunIns+0xf46>
 *   @0x2fdd2c .word 0xf8d430e4
 *   @0x2fdd30 addsmi r1, r9, #224
 *   @0x2fdd34 ldr.w r3, [r4, #0x80]
 *   @0x2fdd38 bne 0x2fdd52 <TT_RunIns+0xf5e>
 *   @0x2fdd3c ldr.w r1, [r3, r6, lsl #3]
 *   @0x2fdd40 mov r0, r4
 *   @0x2fdd44 rsb r1, lr, r1
 *   @0x2fdd48 ldr r2, [r5, #0x4]
 *   @0x2fdd4c ldr.w r3, [r4, #0x244]
 *   @0x2fdd50 b 0x2fdd7e <TT_RunIns+0xf8a>
 *   @0x2fdd54 bl 0xff67de34 <b2_toiTime+0xfffffffffef24990>
 *   @0x2fdd58 .word 0xf7fb0000
 *   @0x2fdd5c .word 0xf8d4f856
 *   @0x2fdd60 .word 0xf8d43080
 *   @0x2fdd64 ldrtmi r1, [r11], #-228
 *   @0x2fdd68 mov r11, r0
 *   @0x2fdd6c ldr r3, [r5, #0x4]
 *   @0x2fdd70 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fdd74 ldr.w r3, [r4, #0x244]
 *   @0x2fdd78 mov r1, r11
 *   @0x2fdd7c mov r0, r4
 *   @0x2fdd80 ldr r3, [r4, #0x7c]
 *   @0x2fdd84 ldr.w r1, [r3, r6, lsl #3]
 *   @0x2fdd88 ldr r2, [r7, #0x4]
 *   @0x2fdd8c .word 0xf8da3004
 *   @0x2fdd90 bne 0xff799d98 <b2_toiTime+0xffffffffff0408f4>
 *   @0x2fdd94 ldr.w r3, [r4, #0x240]
 *   @0x2fdd98 subs r1, r1, r7
 *   @0x2fdd9c mov r0, r4
 *   @0x2fdda0 mov r7, r0
 *   @0x2fdda4 andle r0, r8, r0, lsl #30
 *   @0x2fdda8 cmp.w r9, #0x0
 *   @0x2fddac beq 0x2fddba <TT_RunIns+0xfc6>
 *   @0x2fddb0 ldr r1, [sp, #0xc]
 *   @0x2fddb4 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2fddb8 mov r11, r0
 *   @0x2fddbc mov r0, r4
 *   @0x2fddc0 rsb r3, r7, r11
 *   @0x2fddc4 ldr.w r6, [r4, #0x24c]
 *   @0x2fddc8 blx r6
 *   @0x2fddcc bllo 0x34a2a4
 *   @0x2fddd0 str.w r3, [r4, #0x134]
 *   @0x2fddd4 b 0x2fdcee <TT_RunIns+0xefa>
 *   @0x2fddd8 str.w r3, [r4, #0x134]
 *   @0x2fdddc ldr r3, [r4, #0x1c]
 *   @0x2fdde0 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fdde4 ldrh.w r8, [r5, r6, lsl #2]
 *   @0x2fdde8 ldrh.w r3, [r4, #0x50]
 *   @0x2fddec cmp r3, r8
 *   @0x2fddf0 rfeia r4!
 *   @0x2fddf4 stchi p1, c2, [r3, #128]!
 *   @0x2fddf8 cmp r3, r2
 *   @0x2fddfc rfeia r4!
 *   @0x2fde00 .word 0xf104315e
 *   @0x2fde04 stmiblt r11, {r3, r6, r9, r10} ^
 *   @0x2fde08 ldr r1, [r4, #0x30]
 *   @0x2fde0c stclvs p9, c0, [r3, #-800]!
 *   @0x2fde10 add.w r2, r1, r2, lsl #3
 *   @0x2fde14 add r3, r9
 *   @0x2fde18 strbmi r0, [r2], -r3
 *   @0x2fde1c stm.w r3, {r0, r1}
 *   @0x2fde20 mov r0, r4
 *   @0x2fde24 ldr r3, [r7, #0x4]
 *   @0x2fde28 sbfxmi r5, r0, #0x4, #0x9
 *   @0x2fde2c ldr r3, [r4, #0x58]
 *   @0x2fde30 add r3, r9
 *   @0x2fde34 ldm.w r9, {r0, r1}
 *   @0x2fde38 stm.w r3, {r0, r1}
 *   @0x2fde3c ldrh.w r2, [r4, #0x120]
 *   @0x2fde40 ldr r1, [r4, #0x58]
 *   @0x2fde44 add.w r5, r1, r8, lsl #3
 *   @0x2fde48 add.w r0, r3, r2, lsl #3
 *   @0x2fde4c ldr.w r1, [r1, r8, lsl #3]
 *   @0x2fde50 ldr.w r3, [r3, r2, lsl #3]
 *   @0x2fde54 ldr r5, [r5, #0x4]
 *   @0x2fde58 subs r1, r1, r3
 *   @0x2fde5c ldr.w r3, [r4, #0x240]
 *   @0x2fde60 subs r2, r5, r2
 *   @0x2fde64 ldr r3, [r7, #0x4]
 *   @0x2fde68 ldr.w r5, [r4, #0x24c]
 *   @0x2fde6c mov r1, r6
 *   @0x2fde70 mov r0, r4
 *   @0x2fde74 ldrh.w r3, [r4, #0x120]
 *   @0x2fde78 strh.w r8, [r4, #0x124]
 *   @0x2fde7c strh.w r3, [r4, #0x122]
 *   @0x2fde80 ldrb.w r3, [r4, #0x174]
 *   @0x2fde84 lsls r2, r3, #0x1f
 *   @0x2fde88 .word 0xf8a4868f
 *   @0x2fde8c .word 0xf0008120
 *   @0x2fde90 stmdbvs r2!, {r0, r1, r3, r7, r9, r10, r11, r12, sp, pc}
 *   @0x2fde94 ldr.w r3, [r4, #0x134]
 *   @0x2fde98 cmp r2, r3
 *   @0x2fde9c ldrh.w r2, [r4, #0x120]
 *   @0x2fdea0 ldrh r3, [r4, #0x2c]
 *   @0x2fdea4 bhs 0x2fdeac <TT_RunIns+0x10b8>
 *   @0x2fdea8 eors r0, r1, r8, asr #14
 *   @0x2fdeac ldrb.w r3, [r4, #0x235]
 *   @0x2fdeb0 cmp r3, #0x0
 *   @0x2fdeb4 movs r3, #0x86
 *   @0x2fdeb8 b 0x2fdf2a <TT_RunIns+0x1136>
 *   @0x2fdebc ldr r2, [r4, #0x18]
 *   @0x2fdec0 str r3, [r4, #0x1c]
 *   @0x2fdec4 rfeia r4!
 *   @0x2fdec8 adcsmi r3, r3, #80
 *   @0x2fdecc bls 0x2fdf1a <TT_RunIns+0x1126>
 *   @0x2fded0 stcvs p1, c2, [r1, #128]!
 *   @0x2fded4 ldr r3, [r4, #0x34]
 *   @0x2fded8 bl 0x3bf5f8 <error_g0017+0x1829c>
 *   @0x2fdedc .word 0xf85100c2
 *   @0x2fdee0 stmdavs sp!, {r1, r2, r4, r5, sp, lr, pc} ^
 *   @0x2fdee4 ldr.w r1, [r3, r2, lsl #3]
 *   @0x2fdee8 ldr r2, [r0, #0x4]
 *   @0x2fdeec ldr.w r3, [r4, #0x240]
 *   @0x2fdef0 rsb r1, r1, lr
 *   @0x2fdef4 subs r2, r5, r2
 *   @0x2fdef8 ldr.w r5, [r4, #0x24c]
 *   @0x2fdefc mov r1, r7
 *   @0x2fdf00 rsbs r3, r0, #0
 *   @0x2fdf04 blx r5
 *   @0x2fdf08 bllo 0x34a3e0
 *   @0x2fdf0c str.w r3, [r4, #0x134]
 *   @0x2fdf10 ldr.w r3, [r4, #0x134]
 *   @0x2fdf14 cmp r3, #0x0
 *   @0x2fdf18 b 0x2fdf2a <TT_RunIns+0x1136>
 *   @0x2fdf1c blhs 0x30a7f8 <af_shaper_get_elem+0x66>
 *   @0x2fdf20 beq 0x2fdf06 <TT_RunIns+0x1112>
 *   @0x2fdf24 str r3, [r4, #0xc]
 *   @0x2fdf28 movwhs r11, #0x1e3f
 *   @0x2fdf2c str.w r3, [r4, #0x134]
 *   @0x2fdf30 ldr r3, [r4, #0x1c]
 *   @0x2fdf34 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fdf38 movs r3, #0x2
 *   @0x2fdf3c .word 0xf8df313c
 *   @0x2fdf40 ldrbtmi r3, [r11], #-3104
 *   @0x2fdf44 str.w r3, [r4, #0x23c]
 *   @0x2fdf48 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fdf4c ldrh.w r6, [r5, r6, lsl #2]
 *   @0x2fdf50 ldrh r3, [r4, #0x2c]
 *   @0x2fdf54 adcsmi r8, r3, #68, #2
 *   @0x2fdf58 ldr r1, [r7, #0x4]
 *   @0x2fdf5c ldr.w r3, [r4, #0x180]
 *   @0x2fdf60 cmp r1, r3
 *   @0x2fdf64 ldrb.w r3, [r4, #0x235]
 *   @0x2fdf68 cmp r3, #0x0
 *   @0x2fdf6c movs r3, #0x86
 *   @0x2fdf70 b 0x2fe006 <TT_RunIns+0x1212>
 *   @0x2fdf74 qsaxmi r3, r0, r8
 *   @0x2fdf78 blx r3
 *   @0x2fdf7c .word 0x4607315c
 *   @0x2fdf80 cbnz r3, 0x2fdfb8 <TT_RunIns+0x11c4>
 *   @0x2fdf84 b 0x16c2444 <b2_toiTime+0xf68fa0>
 *   @0x2fdf88 blvs 0xc406a8 <b2_toiTime+0x4e7204>
 *   @0x2fdf8c bl 0x2f929c <ps_hints_apply+0x7e9c>
 *   @0x2fdf90 str.w r0, [r5, r6, lsl #3]
 *   @0x2fdf94 mov r0, r7
 *   @0x2fdf98 mov r5, r9
 *   @0x2fdf9c ldrmi r1, [r9], #304
 *   @0x2fdfa0 bl 0x2f929c <ps_hints_apply+0x7e9c>
 *   @0x2fdfa4 str.w r0, [r9, #0x4]
 *   @0x2fdfa8 ldr r3, [r4, #0x34]
 *   @0x2fdfac add r3, r5
 *   @0x2fdfb0 ldm.w r5, {r0, r1}
 *   @0x2fdfb4 stm.w r3, {r0, r1}
 *   @0x2fdfb8 ldr r3, [r4, #0x34]
 *   @0x2fdfbc ldr.w r5, [r4, #0x240]
 *   @0x2fdfc0 add.w r2, r3, r6, lsl #3
 *   @0x2fdfc4 ldr.w r1, [r3, r6, lsl #3]
 *   @0x2fdfc8 ldr r2, [r2, #0x4]
 *   @0x2fdfcc ldrb.w r3, [r4, #0x174]
 *   @0x2fdfd0 lsls r3, r3, #0x1f
 *   @0x2fdfd4 bpl 0x2fdff4 <TT_RunIns+0x1200>
 *   @0x2fdfd8 ldr.w r5, [r4, #0x23c]
 *   @0x2fdfdc cmp r1, #0x0
 *   @0x2fdfe0 rsblt r1, r1, #0
 *   @0x2fdfe4 cmp r1, r8
 *   @0x2fdfe8 movle r1, r7
 *   @0x2fdfec ldr.w r2, [r4, #0x10c]
 *   @0x2fdff0 blx r5
 *   @0x2fdff4 ldr.w r5, [r4, #0x24c]
 *   @0x2fdff8 mov r0, r4
 *   @0x2fdffc ldrtmi r0, [r2], -r4, lsr #2
 *   @0x2fe000 rsb r3, r9, r7
 *   @0x2fe004 blx r5
 *   @0x2fe008 .word 0xf8a46120
 *   @0x2fe00c .word 0xf0006122
 *   @0x2fe010 .word 0xf8d4bdcb
 *   @0x2fe014 andlo r1, r1, #104, #2
 *   @0x2fe018 ldr.w r3, [r4, #0x16c]
 *   @0x2fe01c add r3, r1
 *   @0x2fe020 ldr r3, [r4, #0x10]
 *   @0x2fe024 cmp r1, r3
 *   @0x2fe028 movwhs r10, #0x1bd7
 *   @0x2fe02c cmp r3, r1
 *   @0x2fe030 ldr.w r0, [r4, #0x168]
 *   @0x2fe034 add.w r5, r3, #0x40000000
 *   @0x2fe038 ldr.w r2, [r4, #0x16c]
 *   @0x2fe03c subs r5, #0x1
 *   @0x2fe040 adds r3, #0x1
 *   @0x2fe044 uxth r3, r3
 *   @0x2fe048 str.w r2, [r7, r5, lsl #2]
 *   @0x2fe04c b 0x2fe02c <TT_RunIns+0x1238>
 *   @0x2fe050 add r1, r3
 *   @0x2fe054 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe058 ldr.w r3, [r4, #0x16c]
 *   @0x2fe05c adds r2, #0x1
 *   @0x2fe060 ldrmi r1, [r9], #-360
 *   @0x2fe064 ldrb r6, [r1, #0x1]
 *   @0x2fe068 subs r1, r2, r1
 *   @0x2fe06c bhs.w 0x2fd7d8 <TT_RunIns+0x9e4>
 *   @0x2fe070 movs r5, #0x0
 *   @0x2fe074 str.w r3, [r4, #0x16c]
 *   @0x2fe078 uxth r3, r5
 *   @0x2fe07c bhs 0x2fe08c <TT_RunIns+0x1298>
 *   @0x2fe080 bl 0x2f92e2 <ps_hints_apply+0x7ee2>
 *   @0x2fe084 str.w r0, [r7, r5, lsl #2]
 *   @0x2fe088 adds r5, #0x1
 *   @0x2fe08c movs r3, #0x0
 *   @0x2fe090 bvs 0xbca688 <b2_toiTime+0x4711e4>
 *   @0x2fe094 add r6, r3
 *   @0x2fe098 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe09c ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe0a0 ldrh.w r2, [r4, #0x1d8]
 *   @0x2fe0a4 cmp r3, r2
 *   @0x2fe0a8 ldmdavs r9!, {r0, r1, r2, r3, r4, r5, r6, r7, r11, sp, pc} ^
 *   @0x2fe0ac ldr.w r2, [r4, #0x1dc]
 *   @0x2fe0b0 str.w r1, [r2, r3, lsl #2]
 *   @0x2fe0b4 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe0b8 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe0bc ldrh.w r2, [r4, #0x1d8]
 *   @0x2fe0c0 cmp r3, r2
 *   @0x2fe0c4 ldrb.w r3, [r4, #0x235]
 *   @0x2fe0c8 cmp r3, #0x0
 *   @0x2fe0cc .word 0xf845a8f2
 *   @0x2fe0d0 .word 0xf0003026
 *   @0x2fe0d4 .word 0xf8d4bd69
 *   @0x2fe0d8 .word 0xf85221dc
 *   @0x2fe0dc .word 0xf8453023
 *   @0x2fe0e0 .word 0xf0003026
 *   @0x2fe0e4 .word 0xf855bd61
 *   @0x2fe0e8 .word 0xf8d41026
 *   @0x2fe0ec addsmi r3, r9, #128, #2
 *   @0x2fe0f0 bhs.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fe0f4 ldr.w r3, [r4, #0x25c]
 *   @0x2fe0f8 mov r0, r4
 *   @0x2fe0fc blx r3
 *   @0x2fe100 .word 0xf855bd53
 *   @0x2fe104 .word 0xf8d41026
 *   @0x2fe108 addsmi r3, r9, #128, #2
 *   @0x2fe10c blo 0x2fe120 <TT_RunIns+0x132c>
 *   @0x2fe110 blhs 0x30a9ec <af_shaper_get_elem+0x25a>
 *   @0x2fe114 bne.w 0x2fd2b2 <TT_RunIns+0x4be>
 *   @0x2fe118 str.w r3, [r5, r6, lsl #2]
 *   @0x2fe11c b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe120 ldr.w r3, [r4, #0x258]
 *   @0x2fe124 mov r0, r4
 *   @0x2fe128 str.w r0, [r5, r6, lsl #2]
 *   @0x2fe12c b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe130 ldr.w r2, [r5, r6, lsl #2]
 *   @0x2fe134 ldrh.w r1, [r4, #0x74]
 *   @0x2fe138 cmp r2, r1
 *   @0x2fe13c ldrb.w r0, [r4, #0x235]
 *   @0x2fe140 cbz r0, 0x2fe170 <TT_RunIns+0x137c>
 *   @0x2fe144 movs r0, #0x0
 *   @0x2fe148 b 0x2fe170 <TT_RunIns+0x137c>
 *   @0x2fe14c b 0x16c1d58 <b2_toiTime+0xf688b4>
 *   @0x2fe150 andle r0, r4, r2, asr #7
 *   @0x2fe154 ldr r1, [r4, #0x78]
 *   @0x2fe158 ldr.w r3, [r4, #0x244]
 *   @0x2fe15c b 0x2fe166 <TT_RunIns+0x1372>
 *   @0x2fe160 adds r7, r1, r3
 *   @0x2fe164 .word 0xf8513240
 *   @0x2fe168 qasxmi r1, r0, r2
 *   @0x2fe16c ldr r2, [r7, #0x4]
 *   @0x2fe170 str.w r0, [r5, r6, lsl #2]
 *   @0x2fe174 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe178 mov r0, r4
 *   @0x2fe17c bl 0x2f9712 <ps_hints_apply+0x8312>
 *   @0x2fe180 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe184 mov r0, r4
 *   @0x2fe188 bl 0x2f976a <ps_hints_apply+0x836a>
 *   @0x2fe18c b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe190 ldr.w r3, [r4, #0x254]
 *   @0x2fe194 mov r0, r4
 *   @0x2fe198 str.w r0, [r5, r6, lsl #2]
 *   @0x2fe19c b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe1a0 ldr r3, [r4]
 *   @0x2fe1a4 ldr r3, [r3, #0x40]
 *   @0x2fe1a8 bne 0x2fe1ba <TT_RunIns+0x13c6>
 *   @0x2fe1ac qsaxmi r3, r0, r4
 *   @0x2fe1b0 blx r3
 *   @0x2fe1b4 .word 0xf0000026
 *   @0x2fe1b8 .word 0xf8d4bcf7
 *   @0x2fe1bc .word 0xf84530d8
 *   @0x2fe1c0 .word 0xf0003026
 *   @0x2fe1c4 .word 0xf884bcf1
 *   @0x2fe1c8 .word 0xf0000140
 *   @0x2fe1cc .word 0xf884bced
 *   @0x2fe1d0 .word 0xf0001140
 *   @0x2fe1d4 orrhs r11, r7, #59648
 *   @0x2fe1d8 str r3, [r4, #0xc]
 *   @0x2fe1dc .word 0xf855bce5
 *   @0x2fe1e0 ldmdavs r10!, {r1, r2, r5, r12, sp} ^
 *   @0x2fe1e4 cmp r3, r2
 *   @0x2fe1e8 movge r3, #0x0
 *   @0x2fe1ec str.w r3, [r5, r6, lsl #2]
 *   @0x2fe1f0 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe1f4 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe1f8 ldr r2, [r7, #0x4]
 *   @0x2fe1fc ite gt
 *   @0x2fe200 movle r3, #0x1
 *   @0x2fe204 .word 0xf0003026
 *   @0x2fe208 .word 0xf855bccf
 *   @0x2fe20c ldmdavs r10!, {r1, r2, r5, r12, sp} ^
 *   @0x2fe210 cmp r3, r2
 *   @0x2fe214 movle r3, #0x0
 *   @0x2fe218 str.w r3, [r5, r6, lsl #2]
 *   @0x2fe21c b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe220 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe224 ldr r2, [r7, #0x4]
 *   @0x2fe228 ite lt
 *   @0x2fe22c movge r3, #0x1
 *   @0x2fe230 .word 0xf0003026
 *   @0x2fe234 .word 0xf855bcb9
 *   @0x2fe238 ldmdavs r10!, {r1, r2, r5, r12, sp} ^
 *   @0x2fe23c subs.w r9, r3, r2
 *   @0x2fe240 rsbs.w r3, r9, #0x0
 *   @0x2fe244 adcs.w r3, r3, r9
 *   @0x2fe248 str.w r3, [r5, r6, lsl #2]
 *   @0x2fe24c b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe250 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe254 ldr r2, [r7, #0x4]
 *   @0x2fe258 it ne
 *   @0x2fe25c str.w r3, [r5, r6, lsl #2]
 *   @0x2fe260 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe264 ldr.w r3, [r4, #0x23c]
 *   @0x2fe268 mov r0, r4
 *   @0x2fe26c andhs r1, r0, #38
 *   @0x2fe270 blx r3
 *   @0x2fe274 .word 0xf1b0007f
 *   @0x2fe278 .word 0xf1d80840
 *   @0x2fe27c bl 0x16fe284 <b2_toiTime+0xfa4de0>
 *   @0x2fe280 .word 0xf8450008
 *   @0x2fe284 .word 0xf0000026
 *   @0x2fe288 .word 0xf8d4bc8f
 *   @0x2fe28c qasxmi r3, r0, r12
 *   @0x2fe290 ldr.w r1, [r5, r6, lsl #2]
 *   @0x2fe294 movs r2, #0x0
 *   @0x2fe298 tst.w r0, #0x7f
 *   @0x2fe29c ite ne
 *   @0x2fe2a0 moveq r3, #0x1
 *   @0x2fe2a4 .word 0xf0003026
 *   @0x2fe2a8 .word 0xf855bc7f
 *   @0x2fe2ac blhs 0x30a34c <af_shaper_get_coverage+0x848>
 *   @0x2fe2b0 bne.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe2b4 movs r5, #0x1
 *   @0x2fe2b8 bl 0x2f9580 <ps_hints_apply+0x8180>
 *   @0x2fe2bc cmp r0, #0x1
 *   @0x2fe2c0 .word 0xf8948473
 *   @0x2fe2c4 blhs 0x190a89c <b2_toiTime+0x11b13f8>
 *   @0x2fe2c8 beq 0x2fe2e0 <TT_RunIns+0x14ec>
 *   @0x2fe2cc beq 0x2fe2e4 <TT_RunIns+0x14f0>
 *   @0x2fe2d0 bne 0x2fe2b6 <TT_RunIns+0x14c2>
 *   @0x2fe2d4 .word 0xf1dc0c01
 *   @0x2fe2d8 bl 0x17beee0 <b2_toiTime+0x1065a3c>
 *   @0x2fe2dc and r0, r5, r12, lsl #6
 *   @0x2fe2e0 adds r5, #0x1
 *   @0x2fe2e4 subs r5, #0x1
 *   @0x2fe2e8 movne r3, #0x0
 *   @0x2fe2ec cmp r3, #0x0
 *   @0x2fe2f0 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe2f4 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe2f8 cbz r3, 0x2fe302 <TT_RunIns+0x150e>
 *   @0x2fe2fc adds r3, #0x0
 *   @0x2fe300 movne r3, #0x1
 *   @0x2fe304 .word 0xf0003026
 *   @0x2fe308 .word 0xf855bc4f
 *   @0x2fe30c stmdblt r3!, {r1, r2, r5, r12, sp}
 *   @0x2fe310 ldr r3, [r7, #0x4]
 *   @0x2fe314 it ne
 *   @0x2fe318 b 0x2fe31c <TT_RunIns+0x1528>
 *   @0x2fe31c str.w r3, [r5, r6, lsl #2]
 *   @0x2fe320 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe324 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe328 rsbs.w r3, r3, #0x1
 *   @0x2fe32c it lo
 *   @0x2fe330 str.w r3, [r5, r6, lsl #2]
 *   @0x2fe334 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe338 mov r0, r4
 *   @0x2fe33c bl 0x2f9ab6 <ps_hints_apply+0x86b6>
 *   @0x2fe340 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe344 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe348 strh.w r3, [r4, #0x150]
 *   @0x2fe34c b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe350 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe354 cmp r3, #0x6
 *   @0x2fe358 strhls.w r3, [r4, #0x152]
 *   @0x2fe35c movhi r3, #0x84
 *   @0x2fe360 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe364 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe368 ldr r2, [r7, #0x4]
 *   @0x2fe36c str.w r3, [r5, r6, lsl #2]
 *   @0x2fe370 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe374 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe378 ldr r2, [r7, #0x4]
 *   @0x2fe37c str.w r3, [r5, r6, lsl #2]
 *   @0x2fe380 b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe384 ldr r2, [r7, #0x4]
 *   @0x2fe388 movs r3, #0x85
 *   @0x2fe38c b.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe390 ldr.w r0, [r5, r6, lsl #2]
 *   @0x2fe394 movs r1, #0x40
 *   @0x2fe398 .word 0xf845fd29
 *   @0x2fe39c .word 0xf0000026
 *   @0x2fe3a0 .word 0xf855bc03
 *   @0x2fe3a4 subhs r0, r0, #38
 *   @0x2fe3a8 ldr r1, [r7, #0x4]
 *   @0x2fe3ac .word 0xf845fcc7
 *   @0x2fe3b0 .word 0xe3f90026
 *   @0x2fe3b4 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe3b8 cmp r3, #0x0
 *   @0x2fe3bc rsblt r3, r3, #0
 *   @0x2fe3c0 .word 0xe3f13026
 *   @0x2fe3c4 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe3c8 rsbs r3, r3, #0
 *   @0x2fe3cc .word 0xe3eb3026
 *   @0x2fe3d0 ldr.w r3, [r5, r6, lsl #2]
 *   @0x2fe3d4 bic r3, r3, #0x3f
 *   @0x2fe3d8 str.w r3, [r5, r6, lsl #2]
 *   @0x2fe3dc b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe3e0 teqlo pc, #38
 *   @0x2fe3e4 bic r3, r3, #0x3f
 *   @0x2fe3e8 str.w r3, [r5, r6, lsl #2]
 *   @0x2fe3ec b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe3f0 .word 0xf8d40383
 *   @0x2fe3f4 qasxmi r7, r0, r12
 *   @0x2fe3f8 ldr.w r1, [r5, r6, lsl #2]
 *   @0x2fe3fc ldr r2, [r3, #-148]
 *   @0x2fe400 blx r7
 *   @0x2fe404 bic r0, pc, #38
 *   @0x2fe408 add.w r3, r4, r3, lsl #2
 *   @0x2fe40c ldr.w r1, [r5, r6, lsl #2]
 *   @0x2fe410 mov r0, r4
 *   @0x2fe414 .word 0xf7fa2ca4
 *   @0x2fe418 .word 0xf845ffb5
 *   @0x2fe41c bic r0, r3, #38
 *   @0x2fe420 ldr.w r5, [r5, r6, lsl #2]
 *   @0x2fe424 ldr.w r3, [r4, #0x180]
 *   @0x2fe428 cmp r5, r3
 *   @0x2fe42c ldmdavs r8!, {r0, r2, r3, r4, r5, r8, r9, r10, r11, sp, pc} ^
 *   @0x2fe430 ldr.w r1, [r4, #0x108]
 *   @0x2fe434 ldr.w r6, [r4, #0x184]
 *   @0x2fe438 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fe43c str.w r0, [r6, r5, lsl #2]
 *   @0x2fe440 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe444 mov r1, r7
 *   @0x2fe448 .word 0xe3adfb36
 *   @0x2fe44c ldr.w r3, [r4, #0x254]
 *   @0x2fe450 mov r0, r4
 *   @0x2fe454 ldr.w r6, [r5, r6, lsl #2]
 *   @0x2fe458 movs r5, #0x1
 *   @0x2fe45c cmp r5, r6
 *   @0x2fe460 ldr r3, [r4, #0x1c]
 *   @0x2fe464 bgt 0x2fe476 <TT_RunIns+0x1682>
 *   @0x2fe468 .word 0xb10b3235
 *   @0x2fe46c movs r3, #0x81
 *   @0x2fe470 movs r3, #0x0
 *   @0x2fe474 b 0x2fe4e4 <TT_RunIns+0x16f0>
 *   @0x2fe478 str r2, [r4, #0x1c]
 *   @0x2fe47c subs r3, #0x1
 *   @0x2fe480 bl 0x382514 <_ZTS13C_UTF16String+0x195c0>
 *   @0x2fe484 .word 0xf8530383
 *   @0x2fe488 .word 0xf8d42c04
 *   @0x2fe48c addsmi r3, r9, #128, #2
 *   @0x2fe490 blo 0x2fe49e <TT_RunIns+0x16aa>
 *   @0x2fe494 tstlt r11, #1342177283
 *   @0x2fe498 movs r3, #0x86
 *   @0x2fe49c b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe4a0 vbic.i32 q8, #0xa4
 *   @0x2fe4a4 ldmdahs r4!, {r0, r1, r8, r9, r12} ^
 *   @0x2fe4a8 beq 0x2fe4b2 <TT_RunIns+0x16be>
 *   @0x2fe4ac bne 0x2fe4b4 <TT_RunIns+0x16c0>
 *   @0x2fe4b0 b 0x2fe4b4 <TT_RunIns+0x16c0>
 *   @0x2fe4b4 ldrh.w r0, [r4, #0x150]
 *   @0x2fe4b8 add r3, r0
 *   @0x2fe4bc bne 0x2fe4e0 <TT_RunIns+0x16ec>
 *   @0x2fe4c0 rfeia r4!
 *   @0x2fe4c4 .word 0xf1be2152
 *   @0x2fe4c8 .word 0xf8d40e08
 *   @0x2fe4cc svclt #0x583260
 *   @0x2fe4d0 addpl.w lr, lr, #0x1
 *   @0x2fe4d4 rsb.w r2, r2, #0x6
 *   @0x2fe4d8 mov r0, r4
 *   @0x2fe4dc ldrmi pc, [r8, r2, lsl #4]
 *   @0x2fe4e0 adds r5, #0x1
 *   @0x2fe4e4 ldr r3, [r4, #0x1c]
 *   @0x2fe4e8 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe4ec mov.w r1, #0x4000
 *   @0x2fe4f0 ldr.w r2, [r5, r6, lsl #2]
 *   @0x2fe4f4 bl 0x2f9398 <ps_hints_apply+0x7f98>
 *   @0x2fe4f8 movs r3, #0x6
 *   @0x2fe4fc .word 0xf8df313c
 *   @0x2fe500 ldrbtmi r3, [r11], #-1636
 *   @0x2fe504 str.w r3, [r4, #0x23c]
 *   @0x2fe508 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe50c movw r1, #0x2d41
 *   @0x2fe510 ldr.w r2, [r5, r6, lsl #2]
 *   @0x2fe514 bl 0x2f9398 <ps_hints_apply+0x7f98>
 *   @0x2fe518 movs r3, #0x7
 *   @0x2fe51c .word 0xf8df313c
 *   @0x2fe520 ldrbtmi r3, [r11], #-1608
 *   @0x2fe524 str.w r3, [r4, #0x23c]
 *   @0x2fe528 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe52c cmp r3, #0x0
 *   @0x2fe530 qasxmi r8, r0, r11
 *   @0x2fe534 mov r1, r7
 *   @0x2fe538 teq r5, #11075584
 *   @0x2fe53c ldr r3, [r7, #0x4]
 *   @0x2fe540 bne.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe544 mov r0, r4
 *   @0x2fe548 bl 0x2fb68c <ps_hints_apply+0xa28c>
 *   @0x2fe54c b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe550 str.w r3, [r4, #0x13c]
 *   @0x2fe554 ldr.w r3, [pc, #0x614]
 *   @0x2fe558 add r3, pc
 *   @0x2fe55c .word 0xe323323c
 *   @0x2fe560 mov r0, r4
 *   @0x2fe564 tst pc, #780
 *   @0x2fe568 movs r3, #0x4
 *   @0x2fe56c .word 0xf8df313c
 *   @0x2fe570 ldrbtmi r3, [r11], #-1536
 *   @0x2fe574 str.w r3, [r4, #0x23c]
 *   @0x2fe578 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe57c str.w r3, [r4, #0x13c]
 *   @0x2fe580 ldr.w r3, [pc, #0x5f0]
 *   @0x2fe584 add r3, pc
 *   @0x2fe588 movw r3, #0xd23c
 *   @0x2fe58c mov r0, r4
 *   @0x2fe590 movw pc, #0x99a6
 *   @0x2fe594 ldr r3, [r4]
 *   @0x2fe598 ldr r3, [r3, #0x40]
 *   @0x2fe59c bne 0x2fe5b4 <TT_RunIns+0x17c0>
 *   @0x2fe5a0 teqlt r11, r7, ror #4
 *   @0x2fe5a4 ldrb.w r3, [r4, #0x268]
 *   @0x2fe5a8 cbz r3, 0x2fe5b4 <TT_RunIns+0x17c0>
 *   @0x2fe5ac blhs 0x30af58 <af_shaper_get_elem+0x7c6>
 *   @0x2fe5b0 bne.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe5b4 ldrh r1, [r7, #0x4]
 *   @0x2fe5b8 .word 0xf8553098
 *   @0x2fe5bc addsmi r0, r9, #38
 *   @0x2fe5c0 bhs.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fe5c4 uxth r0, r0
 *   @0x2fe5c8 bhs.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fe5cc movs r2, #0x0
 *   @0x2fe5d0 uxth r3, r3
 *   @0x2fe5d4 bhi.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe5d8 ldr.w r5, [r4, #0xa8]
 *   @0x2fe5dc adds r2, #0x1
 *   @0x2fe5e0 orr r6, r6, #0x1
 *   @0x2fe5e4 strb r6, [r5, r3]
 *   @0x2fe5e8 ldr r3, [r4]
 *   @0x2fe5ec ldr r3, [r3, #0x40]
 *   @0x2fe5f0 bne 0x2fe608 <TT_RunIns+0x1814>
 *   @0x2fe5f4 teqlt r11, r7, ror #4
 *   @0x2fe5f8 ldrb.w r3, [r4, #0x268]
 *   @0x2fe5fc cbz r3, 0x2fe608 <TT_RunIns+0x1814>
 *   @0x2fe600 blhs 0x30afac <af_shaper_get_elem+0x81a>
 *   @0x2fe604 bne.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe608 ldrh r1, [r7, #0x4]
 *   @0x2fe60c .word 0xf8553098
 *   @0x2fe610 addsmi r0, r9, #38
 *   @0x2fe614 bhs.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fe618 uxth r0, r0
 *   @0x2fe61c bhs.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fe620 movs r2, #0x0
 *   @0x2fe624 uxth r3, r3
 *   @0x2fe628 bhi.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe62c ldr.w r5, [r4, #0xa8]
 *   @0x2fe630 adds r2, #0x1
 *   @0x2fe634 bic r6, r6, #0x1
 *   @0x2fe638 strb r6, [r5, r3]
 *   @0x2fe63c mov r0, r4
 *   @0x2fe640 adcs pc, r1, #340
 *   @0x2fe644 mov r0, r4
 *   @0x2fe648 bl 0x2f985e <ps_hints_apply+0x845e>
 *   @0x2fe64c b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe650 mov r1, r7
 *   @0x2fe654 adc pc, r7, #1200
 *   @0x2fe658 ldr r0, [r4]
 *   @0x2fe65c cdpvs p0, #0x0, c2, c3, c6, #0x1
 *   @0x2fe660 tst.w r2, #0x1
 *   @0x2fe664 ldr r1, [r3, #0x40]
 *   @0x2fe668 movne r3, r1
 *   @0x2fe66c lsls r7, r2, #0x1e
 *   @0x2fe670 ldrb.w r7, [r4, #0x11d]
 *   @0x2fe674 cbz r7, 0x2fe67a <TT_RunIns+0x1886>
 *   @0x2fe678 ldrbeq r7, [r7, -r0, lsl #7]
 *   @0x2fe67c bpl 0x2fe688 <TT_RunIns+0x1894>
 *   @0x2fe680 .word 0xb10f711e
 *   @0x2fe684 orr r3, r3, #0x200
 *   @0x2fe688 lsls r7, r2, #0x1c
 *   @0x2fe68c ldr.w r0, [r0, #0x2b8]
 *   @0x2fe690 cbz r0, 0x2fe696 <TT_RunIns+0x18a2>
 *   @0x2fe694 ldreq r6, [r0], r0, lsl #7
 *   @0x2fe698 bpl 0x2fe6a4 <TT_RunIns+0x18b0>
 *   @0x2fe69c .word 0xb1080264
 *   @0x2fe6a0 orr r3, r3, #0x1000
 *   @0x2fe6a4 cmp r1, #0x28
 *   @0x2fe6a8 lsls r1, r2, #0x19
 *   @0x2fe6ac orrmi r3, r3, #0x2000
 *   @0x2fe6b0 lsls r7, r2, #0x17
 *   @0x2fe6b4 ldrb.w r1, [r4, #0x266]
 *   @0x2fe6b8 cbz r1, 0x2fe6be <TT_RunIns+0x18ca>
 *   @0x2fe6bc ldrbeq r4, [r0, #-0x300]
 *   @0x2fe6c0 it mi
 *   @0x2fe6c4 ldreq r3, [r1, #-0x300]
 *   @0x2fe6c8 it mi
 *   @0x2fe6cc ldrbeq r2, [r7], #896
 *   @0x2fe6d0 bpl 0x2fe6dc <TT_RunIns+0x18e8>
 *   @0x2fe6d4 .word 0xb10a226a
 *   @0x2fe6d8 orr r3, r3, #0x80000
 *   @0x2fe6dc str.w r3, [r5, r6, lsl #2]
 *   @0x2fe6e0 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe6e4 mov r1, r7
 *   @0x2fe6e8 subs pc, sp, #796
 *   @0x2fe6ec ldr r1, [r7, #0x8]
 *   @0x2fe6f0 ldmdavs r10!, {r1, r2, r5, r12, sp} ^
 *   @0x2fe6f4 str r1, [r7, #0x4]
 *   @0x2fe6f8 str.w r2, [r5, r6, lsl #2]
 *   @0x2fe6fc b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe700 ldr.w r2, [r5, r6, lsl #2]
 *   @0x2fe704 cmp r3, r2
 *   @0x2fe708 .word 0xf845824f
 *   @0x2fe70c sub r3, r11, #38
 *   @0x2fe710 ldr r3, [r7, #0x4]
 *   @0x2fe714 addsmi r2, r3, #38
 *   @0x2fe718 bge.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe71c str.w r3, [r5, r6, lsl #2]
 *   @0x2fe720 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe724 blhs 0x30a7c4 <af_shaper_get_elem+0x32>
 *   @0x2fe728 blt.w 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe72c uxth r3, r3
 *   @0x2fe730 eors r3, r9, #88, #2
 *   @0x2fe734 ldr r2, [r7, #0x4]
 *   @0x2fe738 cdpne p0, #0x5, c3, c1, c6, #0x1
 *   @0x2fe73c cmp r1, #0x2
 *   @0x2fe740 strhhs r10, [r1], -r3
 *   @0x2fe744 lsl.w r1, r0, r1
 *   @0x2fe748 cbz r3, 0x2fe750 <TT_RunIns+0x195c>
 *   @0x2fe74c bne.w 0x2fd2a8 <TT_RunIns+0x4b4>
 *   @0x2fe750 ldrb.w r0, [r4, #0x154]
 *   @0x2fe754 cmp r2, #0x3
 *   @0x2fe758 b 0x133eb64 <b2_toiTime+0xbe56c0>
 *   @0x2fe75c .word 0xf8840103
 *   @0x2fe760 .word 0xf0401154
 *   @0x2fe764 stmdavs r2!, {r0, r5, r9, pc}
 *   @0x2fe768 ldr r2, [r2, #0x60]
 *   @0x2fe76c cmp r2, #0x28
 *   @0x2fe770 bllo 0x41efe4 <g_RomDisk+0x277c4>
 *   @0x2fe774 it ne
 *   @0x2fe778 strb.w r3, [r4, #0x267]
 *   @0x2fe77c b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe780 bl 0x2fb4ec <ps_hints_apply+0xa0ec>
 *   @0x2fe784 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe788 ldr.w r3, [r3, #0x2b8]
 *   @0x2fe78c cbz r3, 0x2fe7ce <TT_RunIns+0x19da>
 *   @0x2fe790 adds r2, #0x1
 *   @0x2fe794 ldr r3, [r4, #0x10]
 *   @0x2fe798 cmp r1, r3
 *   @0x2fe79c lsls r1, r1, #0x2
 *   @0x2fe7a0 b 0x2fe7a8 <TT_RunIns+0x19b4>
 *   @0x2fe7a4 str r3, [r4, #0xc]
 *   @0x2fe7a8 cmp r3, r1
 *   @0x2fe7ac stmpl r2, {r0, r2, r3, r4, r5, r6, r7, r8, pc} ^
 *   @0x2fe7b0 asrs r2, r2, #0x2
 *   @0x2fe7b4 adds r3, #0x4
 *   @0x2fe7b8 cmp r3, #0xdf
 *   @0x2fe7bc cmp r3, #0xbf
 *   @0x2fe7c0 blhs 0xff0deb8c <b2_toiTime+0xfffffffffe9856e8>
 *   @0x2fe7c4 bhi.w 0x2feb28 <TT_RunIns+0x1d34>
 *   @0x2fe7c8 cmp r3, #0xaf
 *   @0x2fe7cc .word 0x462081d5
 *   @0x2fe7d0 bl 0x2fb4ec <ps_hints_apply+0xa0ec>
 *   @0x2fe7d4 b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2fe7d8 ldr.w r3, [r3, #0x2b8]
 *   @0x2fe7dc cmp r3, #0x0
 *   @0x2fe7e0 movs r3, #0x11
 *   @0x2fe7e4 bics r3, pc, r6, lsr #32
 *   @0x2fe7e8 ldrh.w r6, [r5, r6, lsl #2]
 *   @0x2fe7ec ldrh.w r3, [r4, #0x50]
 *   @0x2fe7f0 ldr.w r8, [r4, #0x138]
 *   @0x2fe7f4 cmp r3, r6
 *   @0x2fe7f8 ldmdavs r9!, {r2, r6, r8, r12, pc} ^
 *   @0x2fe7fc bls 0x2fe814 <TT_RunIns+0x1a20>
 *   @0x2fe800 mcrrne p1, #0x8, r3, r8, c0
 *   @0x2fe804 adds r3, #0x1
 *   @0x2fe808 bhs 0x2fe814 <TT_RunIns+0x1a20>
 *   @0x2fe80c stchi p1, c2, [r3, #128]!
 *   @0x2fe810 cmp r2, r3
 *   @0x2fe814 ldrb.w r3, [r4, #0x235]
 *   @0x2fe818 cmp r3, #0x0
 *   @0x2fe81c orrhs r8, r6, #182
 *   @0x2fe820 str r3, [r4, #0xc]
 *   @0x2fe824 cbz r0, 0x2fe82e <TT_RunIns+0x1a3a>
 *   @0x2fe828 qsaxmi r3, r0, r8
 *   @0x2fe82c blx r3
 *   @0x2fe830 .word 0xf8d4514c
 *   @0x2fe834 blne 0x138ad5c <b2_toiTime+0xc318b8>
 *   @0x2fe838 cmp r2, #0x0
 *   @0x2fe83c rsblt r2, r2, #0
 *   @0x2fe840 bge 0x2fe84a <TT_RunIns+0x1a56>
 *   @0x2fe844 bge 0x2fe84c <TT_RunIns+0x1a58>
 *   @0x2fe848 b 0x2fe84c <TT_RunIns+0x1a58>
 *   @0x2fe84c ldrh.w r3, [r4, #0x15e]
 *   @0x2fe850 cbnz r3, 0x2fe8a2 <TT_RunIns+0x1aae>
 *   @0x2fe854 strtmi r2, [r8], -r0, lsr #2
 *   @0x2fe858 ldr r3, [r4, #0x30]
 *   @0x2fe85c rfeib r4!
 *   @0x2fe860 stclvs p1, c1, [r7, #-184]!
 *   @0x2fe864 ldr.w r10, [r3, r2, lsl #3]
 *   @0x2fe868 bl 0x2f929c <ps_hints_apply+0x7e9c>
 *   @0x2fe86c add r0, r10
 *   @0x2fe870 rfeia r4!
 *   @0x2fe874 strtmi r2, [r8], -r0, lsr #2
 *   @0x2fe878 ldr r3, [r4, #0x30]
 *   @0x2fe87c bl 0x3c2d44 <error_g0017+0x1b9e8>
 *   @0x2fe880 stclvs p3, c0, [r7, #-776]!
 *   @0x2fe884 ldr.w r10, [r3, #0x4]
 *   @0x2fe888 bl 0x2f929c <ps_hints_apply+0x7e9c>
 *   @0x2fe88c add r7, r11
 *   @0x2fe890 str r0, [r7, #0x4]
 *   @0x2fe894 ldr r2, [r4, #0x54]
 *   @0x2fe898 add r11, r2
 *   @0x2fe89c stm r3, {r0, r1}
 *   @0x2fe8a0 rfeia r4!
 *   @0x2fe8a4 b 0x16c2d2c <b2_toiTime+0xf69888>
 *   @0x2fe8a8 vstmdbvs r7!, {s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26, s27, s28, s29, s30, s31}
 *   @0x2fe8ac ldr r3, [r4, #0x30]
 *   @0x2fe8b0 bl 0x3be8e0 <error_g0017+0x17584>
 *   @0x2fe8b4 .word 0xf85702c1
 *   @0x2fe8b8 .word 0xf853e036
 *   @0x2fe8bc stmdavs r7, {r0, r4, r5, r12} ^
 *   @0x2fe8c0 mov r0, r4
 *   @0x2fe8c4 rsb r1, r1, lr
 *   @0x2fe8c8 ldr.w r3, [r4, #0x244]
 *   @0x2fe8cc subs r2, r7, r2
 *   @0x2fe8d0 ldrh.w r2, [r4, #0x120]
 *   @0x2fe8d4 ldr r3, [r4, #0x34]
 *   @0x2fe8d8 add r10, r1
 *   @0x2fe8dc .word 0xf851c032
 *   @0x2fe8e0 bl 0xff6029c0 <b2_toiTime+0xfffffffffeea951c>
 *   @0x2fe8e4 strmi r0, [r7], -r1, lsl #2
 *   @0x2fe8e8 add.w r0, r3, r2, lsl #3
 *   @0x2fe8ec ldr.w r3, [r10, #0x4]
 *   @0x2fe8f0 ldr r2, [r0, #0x4]
 *   @0x2fe8f4 subs r2, r3, r2
 *   @0x2fe8f8 ldrmi r3, [r8, r0, asr #4]
 *   @0x2fe8fc ldrb.w r3, [r4, #0x140]
 *   @0x2fe900 mov r10, r0
 *   @0x2fe904 teq.w r7, r5
 *   @0x2fe908 it mi
 *   @0x2fe90c ldrb.w r3, [r4, #0x174]
 *   @0x2fe910 tst.w r3, #0x4
 *   @0x2fe914 and r3, r3, #0x3
 *   @0x2fe918 beq 0x2fe948 <TT_RunIns+0x1b54>
 *   @0x2fe91c rfeia r4!
 *   @0x2fe920 addsmi r2, r1, #-2147483625
 *   @0x2fe924 bne 0x2fe934 <TT_RunIns+0x1b40>
 *   @0x2fe928 cmp r2, #0x0
 *   @0x2fe92c rsblt r2, r2, #0
 *   @0x2fe930 it gt
 *   @0x2fe934 add.w r3, r4, r3, lsl #2
 *   @0x2fe938 mov r1, r5
 *   @0x2fe93c ldr.w r5, [r4, #0x23c]
 *   @0x2fe940 ldr.w r2, [r3, #0x10c]
 *   @0x2fe944 blx r5
 *   @0x2fe948 add.w r3, r4, r3, lsl #2
 *   @0x2fe94c mov r0, r4
 *   @0x2fe950 ldr.w r2, [r3, #0x10c]
 *   @0x2fe954 bl 0x2f9384 <ps_hints_apply+0x7f84>
 *   @0x2fe958 ldrb.w r2, [r4, #0x174]
 *   @0x2fe95c mov r3, r0
 *   @0x2fe960 bpl 0x2fe978 <TT_RunIns+0x1b84>
 *   @0x2fe964 blt 0x2fe96e <TT_RunIns+0x1b7a>
 *   @0x2fe968 it lt
 *   @0x2fe96c b 0x2fe978 <TT_RunIns+0x1b84>
 *   @0x2fe970 strbmi r0, [r3, #-0x800]
 *   @0x2fe974 it ge
 *   @0x2fe978 ldr.w r5, [r4, #0x24c]
 *   @0x2fe97c mov r0, r4
 *   @0x2fe980 ldrtmi r0, [r2], -r8, asr #2
 *   @0x2fe984 rsb r3, r10, r3
 *   @0x2fe988 blx r5
 *   @0x2fe98c .word 0xf8a43120
 *   @0x2fe990 .word 0xf8a46124
 *   @0x2fe994 .word 0xf8943122
 *   @0x2fe998 .word 0x06d93174
 *   @0x2fe99c it mi
 *   @0x2fe9a0 .word 0xe1016120
 *   @0x2fe9a4 ldrh.w r6, [r5, r6, lsl #2]
 *   @0x2fe9a8 ldrh.w r3, [r4, #0x50]
 *   @0x2fe9ac ldr.w r7, [r4, #0x138]
 *   @0x2fe9b0 cmp r3, r6
 *   @0x2fe9b4 ldrh.w r3, [r4, #0x120]
 *   @0x2fe9b8 ldrh r2, [r4, #0x2c]
 *   @0x2fe9bc bhi 0x2fe9ce <TT_RunIns+0x1bda>
 *   @0x2fe9c0 blhs 0x30b29c <af_shaper_get_elem+0xb0a>
 *   @0x2fe9c4 beq.w 0x2feb0e <TT_RunIns+0x1d1a>
 *   @0x2fe9c8 movs r3, #0x86
 *   @0x2fe9cc b 0x2feb0e <TT_RunIns+0x1d1a>
 *   @0x2fe9d0 sbcseq r2, sp, r12, asr r1
 *   @0x2fe9d4 cbz r2, 0x2fe9dc <TT_RunIns+0x1be8>
 *   @0x2fe9d8 ldmiblt r2, {r1, r2, r3, r4, r6, r8, sp}
 *   @0x2fe9dc ldr r1, [r4, #0x54]
 *   @0x2fe9e0 add.w r12, r1, r6, lsl #3
 *   @0x2fe9e4 adds r0, r2, r5
 *   @0x2fe9e8 .word 0xf8dce036
 *   @0x2fe9ec .word 0xf8525004
 *   @0x2fe9f0 stmdavs r2, {r0, r1, r4, r5, r12} ^
 *   @0x2fe9f4 mov r0, r4
 *   @0x2fe9f8 bl 0xff34b310 <b2_toiTime+0xfffffffffebf1e6c>
 *   @0x2fe9fc bne 0xfed7ee3c <b2_toiTime+0xfffffffffe625998>
 *   @0x2fea00 b 0x2fea64 <TT_RunIns+0x1c70>
 *   @0x2fea04 .word 0xf8d420e4
 *   @0x2fea08 .word 0xf8d410e0
 *   @0x2fea0c blvs 0xfeb36b84 <b2_toiTime+0xfffffffffe3dd6e0>
 *   @0x2fea10 cmp r1, r2
 *   @0x2fea14 strmi r0, [r5], #-2246
 *   @0x2fea18 ldr.w lr, [lr, r6, lsl #3]
 *   @0x2fea1c ldr.w r2, [r0, r3, lsl #3]
 *   @0x2fea20 bne 0x2fea40 <TT_RunIns+0x1c4c>
 *   @0x2fea24 bl 0xff38aa3c <b2_toiTime+0xfffffffffec31598>
 *   @0x2fea28 stmdavs sp!, {r1, r2, r3, r8} ^
 *   @0x2fea2c mov r0, r4
 *   @0x2fea30 ldr.w r3, [r4, #0x244]
 *   @0x2fea34 blx r3
 *   @0x2fea38 .word 0xf7fa10e0
 *   @0x2fea3c ands pc, r2, r6, ror #19
 *   @0x2fea40 rsb r0, r2, lr
 *   @0x2fea44 bl 0x2f8e0a <ps_hints_apply+0x7a0a>
 *   @0x2fea48 ldr r3, [r5, #0x4]
 *   @0x2fea4c strmi r1, [r1], r4, ror #1
 *   @0x2fea50 ldr.w r0, [r8, #0x4]
 *   @0x2fea54 subs r0, r0, r3
 *   @0x2fea58 .word 0xf8d4f9d8
 *   @0x2fea5c strbmi r3, [r9], -r4, asr #4
 *   @0x2fea60 mov r2, r0
 *   @0x2fea64 blx r3
 *   @0x2fea68 .word 0xf8d4514c
 *   @0x2fea6c blne 0x138af94 <b2_toiTime+0xc31af0>
 *   @0x2fea70 cmp r2, #0x0
 *   @0x2fea74 rsblt r2, r2, #0
 *   @0x2fea78 bge 0x2fea82 <TT_RunIns+0x1c8e>
 *   @0x2fea7c bge 0x2fea84 <TT_RunIns+0x1c90>
 *   @0x2fea80 b 0x2fea84 <TT_RunIns+0x1c90>
 *   @0x2fea84 ldrb.w r3, [r4, #0x174]
 *   @0x2fea88 tst.w r3, #0x4
 *   @0x2fea8c and r3, r3, #0x3
 *   @0x2fea90 beq 0x2feaa6 <TT_RunIns+0x1cb2>
 *   @0x2fea94 strtmi r0, [r0], -r3, lsl #5
 *   @0x2fea98 ldr.w r3, [r4, #0x23c]
 *   @0x2fea9c mov r1, r5
 *   @0x2feaa0 ldrmi r2, [r8, r12, lsl #2]
 *   @0x2feaa4 b 0x2feab6 <TT_RunIns+0x1cc2>
 *   @0x2feaa8 strtmi r0, [r0], -r3, lsl #7
 *   @0x2feaac mov r1, r5
 *   @0x2feab0 .word 0xf7fa210c
 *   @0x2feab4 .word 0xf894fc67
 *   @0x2feab8 sxtab16mi r3, r0, r4
 *   @0x2feabc lsls r2, r3, #0x1c
 *   @0x2feac0 cmp r5, #0x0
 *   @0x2feac4 cmp r8, r7
 *   @0x2feac8 movlt r8, r7
 *   @0x2feacc rsbs r7, r7, #0
 *   @0x2fead0 it ge
 *   @0x2fead4 ldrh.w r2, [r4, #0x120]
 *   @0x2fead8 ldr r1, [r4, #0x58]
 *   @0x2feadc add.w r5, r1, r6, lsl #3
 *   @0x2feae0 add.w r0, r3, r2, lsl #3
 *   @0x2feae4 ldr.w r7, [r1, r6, lsl #3]
 *   @0x2feae8 ldr.w r1, [r3, r2, lsl #3]
 *   @0x2feaec ldr r3, [r0, #0x4]
 *   @0x2feaf0 ldr r2, [r5, #0x4]
 *   @0x2feaf4 ldr.w r5, [r4, #0x240]
 *   @0x2feaf8 subs r2, r2, r3
 *   @0x2feafc ldr.w r5, [r4, #0x24c]
 *   @0x2feb00 add.w r1, r4, #0x48
 *   @0x2feb04 mov r2, r6
 *   @0x2feb08 strtmi r0, [r0], -r8, lsl #6
 *   @0x2feb0c blx r5
 *   @0x2feb10 .word 0xf8a43120
 *   @0x2feb14 .word 0xf8a46124
 *   @0x2feb18 .word 0xf8943122
 *   @0x2feb1c .word 0x06db3174
 *   @0x2feb20 bpl 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2feb24 eors r6, pc, r0, lsr #2
 *   @0x2feb28 subs r3, #0xb7
 *   @0x2feb2c uxth r6, r3
 *   @0x2feb30 subs r3, r2, r3
 *   @0x2feb34 bhs.w 0x2fe7a2 <TT_RunIns+0x19ae>
 *   @0x2feb38 ldr.w r3, [r4, #0x16c]
 *   @0x2feb3c movs r5, #0x0
 *   @0x2feb40 str.w r3, [r4, #0x16c]
 *   @0x2feb44 mov r0, r4
 *   @0x2feb48 .word 0xf847fbcc
 *   @0x2feb4c strlo r0, [r1, #-0x25]
 *   @0x2feb50 uxth r3, r5
 *   @0x2feb54 blo 0x2feb44 <TT_RunIns+0x1d50>
 *   @0x2feb58 strb.w r3, [r4, #0x17c]
 *   @0x2feb5c b 0x2feba8 <TT_RunIns+0x1db4>
 *   @0x2feb60 bvs 0x2feaaa <TT_RunIns+0x1cb6>
 *   @0x2feb64 .word 0xffffd105
 *   @0x2feb68 .word 0xffffd121
 *   @0x2feb6c .word 0xffffae29
 *   @0x2feb70 .word 0xffffd051
 *   @0x2feb74 .word 0xffffd021
 *   @0x2feb78 stmdbvs r1!, {r0, r1, r2, r3, r5, r7, r8, r9, r11, r12, sp}
 *   @0x2feb7c adds r2, #0x1
 *   @0x2feb80 subs r1, r2, r1
 *   @0x2feb84 bhs.w 0x2fe7a2 <TT_RunIns+0x19ae>
 *   @0x2feb88 movs r2, #0x1
 *   @0x2feb8c .word 0xf1025168
 *   @0x2feb90 .word 0xf8d44180
 *   @0x2feb94 stmdblo r1, {r2, r3, r5, r6, r8}
 *   @0x2feb98 add r0, r5
 *   @0x2feb9c adds r2, #0x1
 *   @0x2feba0 cmp r2, r3
 *   @0x2feba4 ldmible r0!, {r0, r5} ^
 *   @0x2feba8 ldr r3, [r4, #0xc]
 *   @0x2febac cmp r3, #0x80
 *   @0x2febb0 ldr.w r3, [r4, #0x1a4]
 *   @0x2febb4 movs r1, #0x18
 *   @0x2febb8 blx 0x347232
 *   @0x2febbc addsmi r3, r3, #536870912
 *   @0x2febc0 bhs 0x2fec5a <TT_RunIns+0x1e66>
 *   @0x2febc4 cbz r1, 0x2fec0c <TT_RunIns+0x1e18>
 *   @0x2febc8 blvc 0x93f1a0 <b2_toiTime+0x1e5cfc>
 *   @0x2febcc cmp r0, r1
 *   @0x2febd0 ldr.w r2, [r4, #0x1b0]
 *   @0x2febd4 ldr.w r1, [r4, #0x1b4]
 *   @0x2febd8 cmp r2, r1
 *   @0x2febdc movs r3, #0x86
 *   @0x2febe0 ldr.w r5, [r4, #0x1b8]
 *   @0x2febe4 lsls r1, r2, #0x4
 *   @0x2febe8 stmdane r10!, {r2, r5, r6, r8} ^
 *   @0x2febec str r0, [r5, r1]
 *   @0x2febf0 ldr.w r1, [r4, #0x16c]
 *   @0x2febf4 str r3, [r2, #0xc]
 *   @0x2febf8 str r1, [r2, #0x4]
 *   @0x2febfc str r1, [r2, #0x8]
 *   @0x2fec00 .word 0xf7fc0006
 *   @0x2fec04 stmdahs r1, {r3, r4, r5, r6, r7, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2fec08 bne 0x2fec34 <TT_RunIns+0x1e40>
 *   @0x2fec0c adds r3, #0x18
 *   @0x2fec10 ldr r3, [r4, #0x20]
 *   @0x2fec14 ldrb.w r3, [r4, #0x17c]
 *   @0x2fec18 cbz r3, 0x2fec28 <TT_RunIns+0x1e34>
 *   @0x2fec1c .word 0xf8d4216c
 *   @0x2fec20 ldrmi r3, [r3], #-376
 *   @0x2fec24 str.w r3, [r4, #0x16c]
 *   @0x2fec28 ldr r5, [sp, #0x18]
 *   @0x2fec2c adds r5, #0x1
 *   @0x2fec30 cmp r5, r3
 *   @0x2fec34 ldr.w r2, [r4, #0x16c]
 *   @0x2fec38 ldr.w r3, [r4, #0x170]
 *   @0x2fec3c cmp r2, r3
 *   @0x2fec40 ldr.w r3, [r4, #0x1b0]
 *   @0x2fec44 cmp r3, #0x0
 *   @0x2fec48 b 0x2fec62 <TT_RunIns+0x1e6e>
 *   @0x2fec4c blhs 0x30b404 <af_shaper_get_elem+0xc72>
 *   @0x2fec50 beq.w 0x2fcf68 <TT_RunIns+0x174>
 *   @0x2fec54 b 0x2fec62 <TT_RunIns+0x1e6e>
 *   @0x2fec58 str r3, [r4, #0xc]
 *   @0x2fec5c b 0x2fec64 <TT_RunIns+0x1e70>
 *   @0x2fec60 b 0x2fec64 <TT_RunIns+0x1e70>
 *   @0x2fec64 add sp, #0x74
 *   @0x2fec68 svclt #0x8ff0
 *   @0x2fec6c rsbs r0, r0, #0
 *
 * ══ §2/8 anon_31518e  0x31518e  size 6448  1612 条（0x31518e..0x316abe）
 * @func 0x31518e 0x316abe  size 6448  1612 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x45331e / 0x37fec2 / 0xac99a6 / 0x38363a / 0x37af1e / 0x52651e / 0x53c6ae / 0x4e2ebe
 * 字段偏移 top8: 0x16×2 / 0x8×2 / 0x1×2 / 0x14×2 / 0x10×1 / 0xc×1 / 0x20×1 / 0x17×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31518e ldrshtlt r4, [pc], r0
 *   @0x315192 stclls p6, c4, [r10, #-24]
 *   @0x315196 strmi r9, [r10], -r9, lsl #4
 *   @0x31519a movwhs r9, #0x30c
 *   @0x31519e tstls pc, #2013265920
 *   @0x3151a2 .word 0x93219320
 *   @0x3151a6 .word 0x93239322
 *   @0x3151aa .word 0x93259324
 *   @0x3151ae .word 0x93279326
 *   @0x3151b2 .word 0x93299328
 *   @0x3151b6 .word 0x932b932a
 *   @0x3151ba .word 0x932d932c
 *   @0x3151be blmi 0x45331e <g_RomDisk+0x5bafe>
 *   @0x3151c2 blo 0x37fec2 <_ZTS13C_UTF16String+0x16f6e>
 *   @0x3151c6 streq lr, [r4], #2819
 *   @0x3151ca stclo p8, c15, [r0], {84}
 *   @0x3151ce movweq pc, #0x1103
 *   @0x3151d2 stclo p8, c15, [r0], {68}
 *   @0x3151d6 blls 0xac99a6 <b2_toiTime+0x370502>
 *   @0x3151da smlabble r4, r11, r2, r4
 *   @0x3151de ldrmi r9, [r0], -r9, asr #24
 *   @0x3151e2 eorvs r6, r10, r2, lsr #32
 *   @0x3151e6 stmdavs r10!, {r0, r5, r6, r8, sp, lr, pc}
 *   @0x3151ea strhs r10, [r1], #-3614
 *   @0x3151ee eorlo pc, r4, r6, asr r8
 *   @0x3151f2 strlo r11, [r1], #-2323
 *   @0x3151f6 mvnsle r2, r0, lsl r12
 *   @0x3151fa movwhs r4, #0xf6a2
 *   @0x3151fe svclt #0x3842a2
 *   @0x315202 andls r4, r2, #35651584
 *   @0x315206 eorhs pc, r3, r6, asr r8
 *   @0x31520a bllo 0x38363a <_ZTS13C_UTF16String+0x1a6e6>
 *   @0x31520e svcls #0x2d1fa
 *   @0x315212 svclt #0x28429f
 *   @0x315216 eorvs r4, pc, pc, lsl r6
 *   @0x31521a strls r2, [r2, -r1, lsl #10]
 *   @0x31521e strtmi r4, [r7], -r5, lsr #1
 *   @0x315222 andle r4, r9, #-268435447
 *   @0x315226 eorhs pc, r7, r6, asr r8
 *   @0x31522a strle r1, [r2, #-0xaad]
 *   @0x31522e andeq pc, r2, pc, rrx
 *   @0x315232 smladxlo r1, r11, r1, lr
 *   @0x315236 ldrb r0, [r3, sp, rrx]!
 *   @0x31523a ldmeq r8!, {r0, r2, r3, r8, r12, sp, lr, pc} ^
 *   @0x31523e streq lr, [r3, r8, lsl #22]
 *   @0x315242 stchs p8, c15, [r0], {87}
 *   @0x315246 andls r1, r6, #696320
 *   @0x31524a .word 0xf847d4f0
 *   @0x31524e .word 0xf10d5c80
 *   @0x315252 .word 0x270008b8
 *   @0x315256 ssatmi r4, #0x1d, r10, lsl #12
 *   @0x31525a blo 0x37af1e <_ZTS13C_UTF16String+0x11fca>
 *   @0x31525e streq pc, [r4, -r7, lsl #2]
 *   @0x315262 ldmibpl r5!, {r1, r2, r12, lr, pc} ^
 *   @0x315266 bl 0x52651e <SrcVerts+0x83562>
 *   @0x31526a .word 0xf8c50507
 *   @0x31526e ldrb r12, [r4, r4]!
 *   @0x315272 .word 0xf8504615
 *   @0x315276 .word 0xb1677025
 *   @0x31527a ldmibeq r8!, {r0, r2, r3, r8, r12, sp, lr, pc} ^
 *   @0x31527e fstmiaxeq r7, {d14, d15, d16, d17}
 *   @0x315282 .word 0xf85c9f4d
 *   @0x315286 .word 0xf1099c40
 *   @0x31528a .word 0xf84c0801
 *   @0x31528e .word 0xf8478c40
 *   @0x315292 strlo r5, [r1, #-0x29]
 *   @0x315296 .word 0xd3ec428d
 *   @0x31529a ldmeq r8!, {r0, r2, r3, r8, r12, sp, lr, pc} ^
 *   @0x31529e bl 0x53c6ae <obj_has_event+0x1b3e>
 *   @0x3152a2 svcls #0x4d0183
 *   @0x3152a6 andhs r4, r0, sp, ror #4
 *   @0x3152aa mcrrne p8, #0x5, pc, r0, c1
 *   @0x3152ae streq lr, [r4], r6, lsl #22
 *   @0x3152b2 strls r4, [r4], -r3, lsl #13
 *   @0x3152b6 .word 0xf04f4680
 *   @0x3152ba bl 0x4e2ebe <SrcVerts+0x3ff02>
 *   @0x3152be smlabbls r10, r1, r1, r0
 *   @0x3152c2 eorls r4, lr, r9, lsr #12
 *   @0x3152c6 andls r9, pc, r7, lsl #10
 *   @0x3152ca vqrshl.u8 d4, d10, d16
 *   @0x3152ce .word 0x9c0480e5
 *   @0x3152d2 bl 0xff59e6de <b2_toiTime+0xfffffffffee4523a>
 *   @0x3152d6 strls r0, [sp, -r3, lsl #14]
 *   @0x3152da strls r6, [r1], #-2084
 *   @0x3152de ldrbtlo pc, [pc], #266
 *   @0x3152e2 vst1.8 {d15, d16}, [r4], r5
 *   @0x3152e6 stcls p4, c9, [r1, #-44]
 *   @0x3152ea stclo p15, c9, [r1, #-4]
 *   @0x3152ee svchs #0x9508
 *   @0x3152f2 sbchi pc, r12, r0
 *   @0x3152f6 strmi r9, [r12], #-3074
 *   @0x3152fa streq lr, [r10], #-3012
 *   @0x3152fe .word 0x9008f8dd
 *   @0x315302 .word 0xf8cd4489
 *   @0x315306 strbmi r9, [r10, #0x14]
 *   @0x31530a .word 0xf04fdd65
 *   @0x31530e stcls p8, c0, [r1, #-4]
 *   @0x315312 blx 0x453b3c <g_RomDisk+0x5c31c>
 *   @0x315316 .word 0x0c01f106
 *   @0x31531a ldmdble pc, {r0, r1, r3, r5, r7, r8, r10, lr}
 *   @0x31531e ldrsbthi pc, [r4], -sp
 *   @0x315322 strtmi r9, [r0], #3842
 *   @0x315326 svclt #0x2845b8
 *   @0x31532a strbmi r4, [r4, #-0x6b8]
 *   @0x31532e .word 0xf8ddd216
 *   @0x315332 stcls p0, c9, [r4, #-128]
 *   @0x315336 bleq 0x610262 <g_SWFaavertbuff+0x3d19a>
 *   @0x31533a bllo 0x31176e <af_shaper_get_elem+0x6fdc>
 *   @0x31533e strtmi r9, [r5], -r3, lsl #10
 *   @0x315342 strbmi r3, [r5, #-0x501]
 *   @0x315346 svcls #0x3d20b
 *   @0x31534a bleq 0x160fc8e <b2_toiTime+0xeb67ea>
 *   @0x31534e svcls #0x4f857
 *   @0x315352 strls r4, [r3, -r11, asr #11]
 *   @0x315356 bl 0xff58b76a <b2_toiTime+0xfffffffffee322c6>
 *   @0x31535a ldrb r0, [r1, r11, lsl #22]!
 *   @0x31535e svcls #0x4c4625
 *   @0x315362 stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x315366 blx 0x493b90 <g_prim_v+0x3b84>
 *   @0x31536a .word 0x8000f8d7
 *   @0x31536e stmdbeq r8, {r0, r1, r3, r8, r9, r11, sp, lr, pc}
 *   @0x315372 svcvs #0xb4f5b9
 *   @0x315376 svcge #0x5af63f
 *   @0x31537a bl 0x4fd0ae <SrcVerts+0x5a0f2>
 *   @0x31537e svcge #0x3e08c8
 *   @0x315382 streq lr, [r12, r7, lsl #22]
 *   @0x315386 .word 0xf8479703
 *   @0x31538a svcls #0x4c8cbc
 *   @0x31538e andls pc, r0, r7, asr #17
 *   @0x315392 svceq #0xf1bc
 *   @0x315396 svcge #0x3ed017
 *   @0x31539a bl 0x4fb3ae <SrcVerts+0x583f2>
 *   @0x31539e blx 0xb96dbe <b2_toiTime+0x43d91a>
 *   @0x3153a2 .word 0xf856f101
 *   @0x3153a6 .word 0xf8406cbc
 *   @0x3153aa bl 0xff4a04b2 <b2_toiTime+0xfffffffffed4700e>
 *   @0x3153ae bl 0x4953d6 <g_prim_v+0x53ca>
 *   @0x3153b2 .word 0xf80609c1
 *   @0x3153b6 bl 0xff369482 <b2_toiTime+0xfffffffffec0ffde>
 *   @0x3153ba stmdbls r2, {r5, r6, r7}
 *   @0x3153be andeq pc, r4, r9, asr #17
 *   @0x3153c2 andne pc, r1, r9, lsl #17
 *   @0x3153c6 stclls p0, c14, [r9, #-8]
 *   @0x3153ca andhi pc, r0, r5, asr #17
 *   @0x3153ce strbtmi r9, [r6], -r7, lsl #30
 *   @0x3153d2 ldrtmi r9, [r12], #-2309
 *   @0x3153d6 mcrrls p7, #0x9, lr, sp, c2
 *   @0x3153da stmdbeq r10, {r0, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x3153de blx 0x1afc80e <b2_toiTime+0x13a336a>
 *   @0x3153e2 .word 0xf8cdf989
 *   @0x3153e6 adcmi r9, r12, #12
 *   @0x3153ea stmdavs r0!, {r0, r2, r3, r4, r9, r12, lr, pc}
 *   @0x3153ee adcsmi r9, r8, #9, #30
 *   @0x3153f2 strlo sp, [r4], #-520
 *   @0x3153f6 svclt #0x8c28ff
 *   @0x3153fa stmdbeq r0!, {r0, r1, r2, r3, r6, r12, sp, lr, pc} ^
 *   @0x3153fe stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x315402 ands r9, r2, sp, asr #8
 *   @0x315406 .word 0x9024f8dd
 *   @0x31540a bl 0xff57c532 <b2_toiTime+0xfffffffffee2308e>
 *   @0x31540e stclls p0, c0, [sp, #-0]
 *   @0x315412 eorvc pc, r0, r4, asr r8
 *   @0x315416 strbls r3, [sp, #-0x504]
 *   @0x31541a blx 0x1ae3162 <b2_toiTime+0x1389cbe>
 *   @0x31541e svcls #0xcf987
 *   @0x315422 eoreq pc, r0, r7, asr r8
 *   @0x315426 .word 0xf04fe001
 *   @0x31542a blx 0xb97b32 <b2_toiTime+0x43e68e>
 *   @0x31542e strhs pc, [r1], #-1281
 *   @0x315432 .word 0x0c0aebc1
 *   @0x315436 .word 0xfc0cfa04
 *   @0x31543a strbeq lr, [r5], #2824
 *   @0x31543e strbeq lr, [r12, pc, asr #20]
 *   @0x315442 ldrbmi r9, [sp, #-0x705]
 *   @0x315446 svcls #0x3d208
 *   @0x31544a .word 0xf8844465
 *   @0x31544e rsbvs r9, r0, r0
 *   @0x315452 svcls #0x57067
 *   @0x315456 .word 0xe7f4443c
 *   @0x31545a andsmi r9, r5, #704
 *   @0x31545e streq lr, [r5], #-2690
 *   @0x315462 andle r4, r1, r2, lsr #12
 *   @0x315466 ldrb r0, [r8, sp, ror #16]!
 *   @0x31546a stmdbeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x31546e blx 0x58092e <g_SWFlineaavertbuff+0x2d866>
 *   @0x315472 svclo #0x1f701
 *   @0x315476 eorpl pc, r6, r5, asr r8
 *   @0x31547a adcmi r4, pc, #39
 *   @0x31547e stcls p0, c13, [r2, #-12]
 *   @0x315482 blne 0x1564c8e <b2_toiTime+0xe0b7ea>
 *   @0x315486 .word 0x9c08e7f0
 *   @0x31548a str r9, [r12, -r1, lsl #8]!
 *   @0x31548e .word 0xf10a9c04
 *   @0x315492 strlo r0, [r4], #-2561
 *   @0x315496 ldr r9, [r7, -r4, lsl #8]
 *   @0x31549a .word 0xb12d9d06
 *   @0x31549e svclt #0x142b01
 *   @0x3154a2 andeq pc, r4, pc, rrx
 *   @0x3154a6 and r2, r0, r0
 *   @0x3154aa eorslt r9, pc, r6, lsl #16
 *   @0x3154ae svchi #0xf0e8bd
 *   @0x3154b2 mvnsmi lr, sp, lsr #18
 *   @0x3154b6 addlt r4, r5, #24117248
 *   @0x3154ba strmi r0, [r12], -r6, lsl #24
 *   @0x3154be rsble r2, r5, r0, lsl #18
 *   @0x3154c2 ldmpl r0!, {r0, r6, r9, r12, sp, lr, pc}
 *   @0x3154c6 subsle r2, sp, r0, lsl #30
 *   @0x3154ca svclt #0x344547
 *   @0x3154ce .word 0x4643463b
 *   @0x3154d2 blhs 0x6dc0d6 <g_SWFvertbuff+0x900e>
 *   @0x3154d6 stmdavc r2!, {r0, r6, r8, r10, r11, r12, lr, pc}
 *   @0x3154da ldrlo r3, [r0], #-2832
 *   @0x3154de .word 0xf8144415
 *   @0x3154e2 strtmi r2, [lr], #-3087
 *   @0x3154e6 .word 0xf8144415
 *   @0x3154ea strtmi r2, [lr], #-3086
 *   @0x3154ee .word 0xf8144415
 *   @0x3154f2 strtmi r2, [lr], #-3085
 *   @0x3154f6 .word 0xf8144415
 *   @0x3154fa strtmi r2, [lr], #-3084
 *   @0x3154fe .word 0xf8144415
 *   @0x315502 strtmi r2, [lr], #-3083
 *   @0x315506 .word 0xf8144415
 *   @0x31550a strtmi r2, [lr], #-3082
 *   @0x31550e .word 0xf8144415
 *   @0x315512 strtmi r2, [lr], #-3081
 *   @0x315516 .word 0xf8144415
 *   @0x31551a strtmi r2, [lr], #-3080
 *   @0x31551e .word 0xf8144415
 *   @0x315522 strtmi r2, [lr], #-3079
 *   @0x315526 .word 0xf8144415
 *   @0x31552a strtmi r2, [lr], #-3078
 *   @0x31552e .word 0xf8144415
 *   @0x315532 strtmi r2, [lr], #-3077
 *   @0x315536 .word 0xf8144415
 *   @0x31553a strtmi r2, [lr], #-3076
 *   @0x31553e .word 0xf8144415
 *   @0x315542 strtmi r2, [lr], #-3075
 *   @0x315546 .word 0xf8144415
 *   @0x31554a strtmi r2, [lr], #-3074
 *   @0x31554e .word 0xf8144415
 *   @0x315552 strtmi r2, [lr], #-3073
 *   @0x315556 strtmi r4, [lr], #-1045
 *   @0x31555a ldrhlt lr, [r3, -r11]!
 *   @0x31555e .word 0xf8144423
 *   @0x315562 addsmi r2, r12, #1024
 *   @0x315566 strtmi r4, [lr], #-1045
 *   @0x31556a qsub8mi sp, r8, r9
 *   @0x31556e mvnsvc pc, pc, asr #12
 *   @0x315572 bl 0xff2d1586 <b2_toiTime+0xfffffffffeb780e2>
 *   @0x315576 .word 0x460d4630
 *   @0x31557a mvnsvc pc, pc, asr #12
 *   @0x31557e bl 0xff151592 <b2_toiTime+0xfffffffffe9f80ee>
 *   @0x315582 ldr r4, [pc, lr, lsl #12]
 *   @0x315586 andmi lr, r6, r5, asr #20
 *   @0x31558a ldrhhi lr, [r0, #141]!
 *   @0x31558e pop {r0, sp}
 *   @0x315592 .word 0xf7d181f0
 *   @0x315596 .word 0xf7d1becf
 *   @0x31559a strlt r11, [r7, #-0xecd]
 *   @0x31559e bge 0x3662ea <_ZTS12CDS_Priority+0x8342>
 *   @0x3155a2 stc2l p7, c15, [r0, #836]
 *   @0x3155a6 .word 0xf85db003
 *   @0x3155aa .word 0xf7fffb04
 *   @0x3155ae ldrlt r11, [r7, #-0xff6]!
 *   @0x3155b2 strmi r2, [r4], -r0, lsl #2
 *   @0x3155b6 .word 0xf976f7d1
 *   @0x3155ba stmdahs r0, {r12, pc}
 *   @0x3155be qsaxmi sp, r0, r4
 *   @0x3155c2 andhs r10, r4, #16384
 *   @0x3155c6 .word 0xf9e2f7d1
 *   @0x3155ca stmdahs r0, {r12, pc}
 *   @0x3155ce .word 0xf89dd14c
 *   @0x3155d2 blhs 0xae15ea <b2_toiTime+0x388146>
 *   @0x3155d6 .word 0xf89dd10c
 *   @0x3155da blhs 0xfe5e15f6 <b2_toiTime+0xfffffffffde88152>
 *   @0x3155de .word 0xf89dd108
 *   @0x3155e2 blhs 0x521602 <SrcVerts+0x7e646>
 *   @0x3155e6 .word 0xf89dd104
 *   @0x3155ea .word 0xf0133007
 *   @0x3155ee andle r0, r2, r0, ror #31
 *   @0x3155f2 movwls r2, #0x303
 *   @0x3155f6 qasxmi lr, r0, r8
 *   @0x3155fa .word 0xf7d12106
 *   @0x3155fe .word 0xf89df998
 *   @0x315602 andls r3, r0, r7
 *   @0x315606 strle r0, [r4], #-1880
 *   @0x31560a mullo r7, sp, r8
 *   @0x31560e strle r0, [lr], #-1817
 *   @0x315612 uqadd16mi lr, r9, r5
 *   @0x315616 .word 0xf7d14620
 *   @0x31561a blls 0x354432
 *   @0x31561e bllt 0x9e6e2a <b2_toiTime+0x28d986>
 *   @0x315622 .word 0xf7d14620
 *   @0x315626 andls pc, r0, r4, lsl #19
 *   @0x31562a rscle r2, sp, r0, lsl #16
 *   @0x31562e qadd16mi lr, r0, r12
 *   @0x315632 .word 0xf7d14669
 *   @0x315636 blls 0x353f42
 *   @0x31563a stmdahs r0, {r0, r1, r4, r5, r7, r8, r11, r12, sp, pc}
 *   @0x31563e .word 0xf89dd1f7
 *   @0x315642 ldrbeq r3, [r10], r7
 *   @0x315646 strtmi sp, [r0], -r7, lsl #10
 *   @0x31564a .word 0xf7d14669
 *   @0x31564e blls 0x353f2a
 *   @0x315652 stmdahs r0, {r0, r1, r4, r6, r8, r11, r12, sp, pc}
 *   @0x315656 .word 0xf89dd1f7
 *   @0x31565a ldreq r3, [r11, r7]
 *   @0x31565e strtmi sp, [r0], -r4, lsl #10
 *   @0x315662 .word 0xf7d12102
 *   @0x315666 andls pc, r0, r4, ror #18
 *   @0x31566a andlt r9, r3, r0, lsl #16
 *   @0x31566e push {r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x315672 .word 0x460443f8
 *   @0x315676 strmi r6, [sp], -r7, asr #22
 *   @0x31567a ldrsbthi pc, [r0], -r0
 *   @0x31567e stmdbvs r11, {r1, r2, r4, r9, r10, lr}
 *   @0x315682 .word 0xf8d145b8
 *   @0x315686 svclt #0x88900c
 *   @0x31568a bl 0xff5301ae <b2_toiTime+0xfffffffffedd6d0a>
 *   @0x31568e addsmi r0, pc, #1835008
 *   @0x315692 ldrmi r11, [pc], -r8, lsr #30
 *   @0x315696 .word 0xf112b11f
 *   @0x31569a svclt #0x80f05
 *   @0x31569e blne 0xff9deea6 <b2_toiTime+0xffffffffff285a02>
 *   @0x3156a2 stmdbvs r11!, {r0, r1, r3, r5, r8, sp, lr} ^
 *   @0x3156a6 .word 0x616b443b
 *   @0x3156aa smulwblt r11, r3, r11
 *   @0x3156ae strbmi r6, [r1], -r0, ror #23
 *   @0x3156b2 .word 0x4798463a
 *   @0x3156b6 .word 0x632863e0
 *   @0x3156ba ldrtmi r4, [r10], -r8, asr #12
 *   @0x3156be ldrtmi r4, [r9], #1601
 *   @0x3156c2 svc #0x7cf5a0
 *   @0x3156c6 strbmi r6, [r7], #-2787
 *   @0x3156ca .word 0xd126429f
 *   @0x3156ce .word 0x8028f8d4
 *   @0x3156d2 adcsmi r6, r11, #101376
 *   @0x3156d6 .word 0xf8c4bf08
 *   @0x3156da blvs 0x1cf57b2 <b2_toiTime+0x159c30e>
 *   @0x3156de bl 0xff52fb92 <b2_toiTime+0xfffffffffedd66ee>
 *   @0x3156e2 addsmi r0, pc, #1835008
 *   @0x3156e6 ldrmi r11, [pc], -r8, lsr #30
 *   @0x3156ea .word 0xf116b11f
 *   @0x3156ee svclt #0x80f05
 *   @0x3156f2 blne 0xff9deefa <b2_toiTime+0xffffffffff285a56>
 *   @0x3156f6 stmdbvs r11!, {r0, r1, r3, r5, r8, sp, lr} ^
 *   @0x3156fa .word 0x616b443b
 *   @0x3156fe smulwblt r11, r3, r11
 *   @0x315702 strbmi r6, [r1], -r0, ror #23
 *   @0x315706 .word 0x4798463a
 *   @0x31570a .word 0x632863e0
 *   @0x31570e ldrtmi r4, [r10], -r8, asr #12
 *   @0x315712 ldrtmi r4, [r9], #1601
 *   @0x315716 svc #0x52f5a0
 *   @0x31571a .word 0xf8c54447
 *   @0x31571e ldrtmi r9, [r0], -r12
 *   @0x315722 pop {r0, r1, r2, r5, r8, r9, sp, lr}
 *   @0x315726 ldrlt r8, [r8, #-0x3f8]!
 *   @0x31572a strmi r4, [sp], -r4, lsl #12
 *   @0x31572e blvs 0xff401b5e <b2_toiTime+0xfffffffffeca86ba>
 *   @0x315732 stmdavs r3!, {r0, r1, r4, sp, lr}
 *   @0x315736 blhs 0x36434e <_ZTS12CDS_Priority+0x63a6>
 *   @0x31573a bvs 0x1e0b74e <b2_toiTime+0x16b22aa>
 *   @0x31573e stmvs r1!, {r3, r5, r7, r9, r11, sp, lr} ^
 *   @0x315742 stmdavs r3!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x315746 .word 0xd1032b06
 *   @0x31574a bvs 0xfed300fe <b2_toiTime+0xfffffffffe5d6c5a>
 *   @0x31574e ldrmi r6, [r8, r1, ror #16]
 *   @0x315752 andhs r6, r0, r3, lsr #21
 *   @0x315756 mvnvs r6, r0, lsr #32
 *   @0x31575a .word 0x63236363
 *   @0x31575e eorvs r6, r0, #166912
 *   @0x315762 strmi r11, [r1], -r3, lsr #2
 *   @0x315766 ldrmi r4, [r8, r2, lsl #12]
 *   @0x31576a .word 0x632863e0
 *   @0x31576e ldrlt r11, [r8, #-0xd38]!
 *   @0x315772 mvnlt r4, r4, lsl #12
 *   @0x315776 bicslt r6, r11, r3, asr #19
 *   @0x31577a biclt r6, r10, r2, asr #20
 *   @0x31577e orrlt r6, r5, sp, asr r9
 *   @0x315782 strtmi r2, [r8], -r0, lsl #4
 *   @0x315786 .word 0xf7ff4621
 *   @0x31578a bvs 0x1c156ca <b2_toiTime+0x14bc226>
 *   @0x31578e bvs 0xfed70216 <b2_toiTime+0xfffffffffe616d72>
 *   @0x315792 bvs 0x1be75fa <b2_toiTime+0x148e156>
 *   @0x315796 bvs 0x1d7021e <b2_toiTime+0x1616d7a>
 *   @0x31579a bvs 0x1be7602 <b2_toiTime+0x148e15e>
 *   @0x31579e strtmi r6, [r9], -r0, lsr #21
 *   @0x3157a2 bvs 0xfeb2760a <b2_toiTime+0xfffffffffe3ce166>
 *   @0x3157a6 stmibvs r1!, {r0, r1, r5, r6, r9, r11, sp, lr} ^
 *   @0x3157aa mulhs r0, r8, r7
 *   @0x3157ae ldclt p1, c6, [r8, #-896]!
 *   @0x3157b2 andeq pc, r1, pc, rrx
 *   @0x3157b6 ldrblt r11, [r8, #0xd38]!
 *   @0x3157ba stmvs r4, {r1, r2, r9, r10, lr} ^
 *   @0x3157be orrslt r6, r12, r7, asr #19
 *   @0x3157c2 andeq pc, r12, r4, lsl #2
 *   @0x3157c6 .word 0xf7ff2500
 *   @0x3157ca rscvs pc, r5, #840
 *   @0x3157ce ldrtmi r6, [r8], -r5, lsr #6
 *   @0x3157d2 strtmi r6, [r1], -r5, ror #6
 *   @0x3157d6 .word 0x61a560e5
 *   @0x3157da mvnvs r6, r5, lsr #2
 *   @0x3157de eorvs r6, r5, r5, lsr #1
 *   @0x3157e2 .word 0xf7d16065
 *   @0x3157e6 rscsvs pc, r5, r7, lsr #27
 *   @0x3157ea stmdblt r4!, {r2, r4, r5, r6, r8, r11, sp, lr}
 *   @0x3157ee ldmdavs r1!, {r3, r4, r5, r9, r10, lr}
 *   @0x3157f2 stc2 p7, c15, [r0, #836]!
 *   @0x3157f6 ldcllt p0, c6, [r8, #208]!
 *   @0x3157fa .word 0x4601b510
 *   @0x3157fe stmibvs r3, {r4, r7, r8, r12, sp, pc} ^
 *   @0x315802 strhs r11, [r0], #-387
 *   @0x315806 addvs r6, r4, r4, asr #2
 *   @0x31580a ldmvs r10, {r2, r7, r8, sp, lr} ^
 *   @0x31580e svclt #0x1442a2
 *   @0x315812 strtmi r2, [r2], -r7, lsl #4
 *   @0x315816 stmibvs r3, {r1, r3, r4, sp, lr} ^
 *   @0x31581a ldmdbvs r8, {r1, r5, r9, r10, lr} ^
 *   @0x31581e .word 0xff83f7ff
 *   @0x315822 ldclt p6, c4, [r0, #-128]
 *   @0x315826 andeq pc, r1, pc, rrx
 *   @0x31582a push {r4, r8, r10, r11, r12, sp, pc}
 *   @0x31582e .word 0x460d47f0
 *   @0x315832 stmdahs r0, {r2, r9, r10, lr}
 *   @0x315836 movwhs sp, #0x72
 *   @0x31583a bvs 0x3ede4e
 *   @0x31583e bmi 0x1203cb2 <b2_toiTime+0xaaa80e>
 *   @0x315842 ldrbtmi r6, [r10], #-643
 *   @0x315846 bvs 0x1bee056 <b2_toiTime+0x1494bb2>
 *   @0x31584a blmi 0x1183c9e <b2_toiTime+0xa2a7fa>
 *   @0x31584e rsbvs r4, r3, #2063597568
 *   @0x315852 .word 0x21016a23
 *   @0x315856 andshs r6, r8, #160, #20
 *   @0x31585a .word 0x61e04798
 *   @0x31585e rsble r2, r1, r0, lsl #16
 *   @0x315862 .word 0x61432300
 *   @0x315866 addsmi r6, sp, #3702784
 *   @0x31586a ble 0x3edbbe
 *   @0x31586e rsbmi r6, sp, #3719168
 *   @0x315872 sbcsvs r2, r10, r1, lsl #4
 *   @0x315876 movweq pc, #0x81a5
 *   @0x31587a stmdble r3, {r0, r1, r2, r8, r9, r11, sp}
 *   @0x31587e .word 0xf7ff4620
 *   @0x315882 sub pc, r11, r6, ror pc
 *   @0x315886 tstvs sp, r3, ror #19
 *   @0x31588a ldmvs r11!, {r0, r1, r2, r5, r6, r7, r8, r11, sp, lr} ^
 *   @0x31588e .word 0xf8dfb91b
 *   @0x315892 ldrbtmi r8, [r8], #164
 *   @0x315896 .word 0xf04fe001
 *   @0x31589a strhs r0, [r1], -r0, lsl #16
 *   @0x31589e bvs 0xfeb30132 <b2_toiTime+0xfffffffffe3d6c8e>
 *   @0x3158a2 subhs r4, r0, #51380224
 *   @0x3158a6 .word 0xf905fa06
 *   @0x3158aa .word 0x46054798
 *   @0x3158ae eorle r2, r10, r0, lsl #16
 *   @0x3158b2 .word 0x21086a23
 *   @0x3158b6 vst1.32 {d22, d23}, [pc:128], r0
 *   @0x3158ba .word 0x479862b4
 *   @0x3158be rsbvs r4, r8, #136314880
 *   @0x3158c2 strtmi r11, [r9], -r8, lsr #18
 *   @0x3158c6 bvs 0xfeb3025a <b2_toiTime+0xfffffffffe3d6db6>
 *   @0x3158ca .word 0x47984655
 *   @0x3158ce shadd16mi lr, r1, r11
 *   @0x3158d2 bvs 0xfeb30166 <b2_toiTime+0xfffffffffe3d6cc2>
 *   @0x3158d6 ldrmi r4, [r8, r10, asr #12]
 *   @0x3158da adcvs r4, r8, #6291456
 *   @0x3158de bvs 0x1d83e06 <b2_toiTime+0x162a962>
 *   @0x3158e2 bvs 0xfeb30276 <b2_toiTime+0xfffffffffe3d6dd2>
 *   @0x3158e6 qadd8mi r4, r9, r8
 *   @0x3158ea ldrtmi r6, [r5], -r3, ror #20
 *   @0x3158ee ldrmi r6, [r8, r0, lsr #21]
 *   @0x3158f2 strbmi lr, [lr], #-9
 *   @0x3158f6 rscvs r2, lr, #0, #4
 *   @0x3158fa .word 0xf8c54628
 *   @0x3158fe qasxmi r8, r1, r8
 *   @0x315902 .word 0xf7ff602a
 *   @0x315906 cmnvs sp, r0, lsl pc
 *   @0x31590a ldmdblt r5, {r5, r9, r10, lr}
 *   @0x31590e .word 0xff2ff7ff
 *   @0x315912 .word 0xf7ffe008
 *   @0x315916 andhs pc, r0, r1, ror pc
 *   @0x31591a .word 0x87f0e8bd
 *   @0x31591e andeq pc, r1, pc, rrx
 *   @0x315922 .word 0x87f0e8bd
 *   @0x315926 andeq pc, r3, pc, rrx
 *   @0x31592a .word 0x87f0e8bd
 *   @0x31592e stc2l p15, c11, [r5, #-0]!
 *   @0x315932 stc2l p15, c15, [r7, #-1020]
 *   @0x315936 .word 0xfc1bffff
 *   @0x31593a push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x31593e .word 0x46044ff0
 *   @0x315942 stmdahs r0, {r0, r1, r3, r4, r7, r12, sp, pc}
 *   @0x315946 strbhi pc, [r10, r0]!
 *   @0x31594a blhs 0x33005e
 *   @0x31594e strbhi pc, [r6, r0]!
 *   @0x315952 blhs 0x32f966
 *   @0x315956 strbhi pc, [r2, r0]!
 *   @0x31595a bhs 0xff153cde <b2_toiTime+0xfffffffffe9fa83a>
 *   @0x31595e .word 0xf8df2904
 *   @0x315962 .word 0xf06f1ab4
 *   @0x315966 ldrbtmi r0, [r10], #-1796
 *   @0x31596a andhs r11, r0, r4, lsl pc
 *   @0x31596e andeq pc, r4, pc, rrx
 *   @0x315972 orrseq pc, r8, #-2147483648
 *   @0x315976 .word 0xf8df9312
 *   @0x31597a ldrbtmi r3, [r9], #-2720
 *   @0x31597e ldrbtmi r9, [r11], #-9
 *   @0x315982 bllo 0x139dce <_Z13F_FileWriteLnR6RValueP9CInstanceS2_iPS_+0x3a>
 *   @0x315986 tstls r3, #-536870912
 *   @0x31598a ldmdavs r10, {r0, r1, r5, r6, r7, r8, r11, sp, lr}
 *   @0x31598e vpmax.s8 d2, d0, d13
 *   @0x315992 ldm pc, {r0, r2, r6, r7, r8, r9, r10, pc} ^
 *   @0x315996 andseq pc, r2, r2, lsl r0
 *   @0x31599a rsbeq r0, r1, r11, lsr r0
 *   @0x31599e addeq r0, r11, r5, ror r0
 *   @0x3159a2 adcseq r0, r10, r1, lsr #1
 *   @0x3159a6 strbeq r0, [r5, -r5, asr #1]!
 *   @0x3159aa .word 0x078d0778
 *   @0x3159ae strbeq r0, [r6, r2, lsr #15]
 *   @0x3159b2 .word 0xf06f000e
 *   @0x3159b6 .word 0xf0000002
 *   @0x3159ba stmdavs r2!, {r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, sp, pc} ^
 *   @0x3159be .word 0xf0002a00
 *   @0x3159c2 blo 0x37789a <_ZTS13C_UTF16String+0xe946>
 *   @0x3159c6 stmvs r2!, {r1, r5, r6, sp, lr}
 *   @0x3159ca adcvs r3, r2, r1, lsl #4
 *   @0x3159ce mrrcne p8, #0x2, r6, r1, c2
 *   @0x3159d2 ldmdavc r2, {r0, r5, sp, lr}
 *   @0x3159d6 .word 0xf002605a
 *   @0x3159da bhs 0x51621e <SrcVerts+0x73262>
 *   @0x3159de andle r6, r5, r3, ror #19
 *   @0x3159e2 andsvs r2, r10, sp, lsl #4
 *   @0x3159e6 blo 0x1153d6a <b2_toiTime+0x9fa8c6>
 *   @0x3159ea eor r4, r9, r11, ror r4
 *   @0x3159ee ldmdbeq r2, {r1, r3, r4, r6, r11, sp, lr}
 *   @0x3159f2 .word 0x0108f102
 *   @0x3159f6 addsmi r6, r1, #425984
 *   @0x3159fa andhs sp, sp, #81920
 *   @0x3159fe .word 0xf8df601a
 *   @0x315a02 ldrbtmi r3, [r11], #-2592
 *   @0x315a06 svcls #0x9e01c
 *   @0x315a0a andsvs r2, r10, r1, lsl #4
 *   @0x315a0e blhs 0x32fba2
 *   @0x315a12 strhi pc, [r11, r0]
 *   @0x315a16 rsbvs r3, r3, r1, lsl #22
 *   @0x315a1a tsths pc, r3, lsr #17
 *   @0x315a1e movwlo r6, #0x19e5
 *   @0x315a22 stmdavs r3!, {r0, r1, r5, r7, sp, lr}
 *   @0x315a26 eorvs r1, r2, r10, asr r12
 *   @0x315a2a ldmdavc lr, {r3, r5, r6, r11, sp, lr}
 *   @0x315a2e andhs lr, r0, r6, lsl #22
 *   @0x315a32 ldmdb lr, {r0, r1, r12, sp, lr, pc} ^
 *   @0x315a36 movwhs r11, #0xd139
 *   @0x315a3a .word 0xf8df602b
 *   @0x315a3e ldrbtmi r3, [r11], #-2536
 *   @0x315a42 .word 0xf00061a3
 *   @0x315a46 ldrteq r11, [r2], r2, ror #30
 *   @0x315a4a movwhs sp, #0x7403
 *   @0x315a4e .word 0xf000602b
 *   @0x315a52 svcls #0x9bf5f
 *   @0x315a56 eorvs r2, r11, r2, lsl #6
 *   @0x315a5a blhs 0x32fbee
 *   @0x315a5e strbhi pc, [r5, -r0]!
 *   @0x315a62 rsbvs r3, r3, r1, lsl #22
 *   @0x315a66 stmibvs r2!, {r0, r1, r5, r7, r11, sp, lr} ^
 *   @0x315a6a adcvs r3, r3, r1, lsl #6
 *   @0x315a6e svcls #0x96823
 *   @0x315a72 eorvs r1, r1, r9, asr r12
 *   @0x315a76 sadd16eq r7, r11, r11
 *   @0x315a7a stmibvs r3!, {r0, r1, r4, r7, sp, lr} ^
 *   @0x315a7e andsvs r2, r10, r3, lsl #4
 *   @0x315a82 blhs 0x32fc16
 *   @0x315a86 ldrbhi pc, [r1, -r0]
 *   @0x315a8a rsbvs r3, r3, r1, lsl #22
 *   @0x315a8e stmdavs r2!, {r0, r1, r5, r7, r11, sp, lr}
 *   @0x315a92 adcvs r3, r3, r1, lsl #6
 *   @0x315a96 mrrcne p9, #0xe, r6, r0, c3
 *   @0x315a9a ldmvs r9, {r0, r3, r8, r9, r10, r11, r12, pc}
 *   @0x315a9e ldmdavc r2, {r5, sp, lr}
 *   @0x315aa2 andmi lr, r2, #1024
 *   @0x315aa6 stmibvs r3!, {r1, r3, r4, r7, sp, lr} ^
 *   @0x315aaa andsvs r2, r10, r4, lsl #4
 *   @0x315aae blhs 0x32fc42
 *   @0x315ab2 ldrhi pc, [r11, -r0]!
 *   @0x315ab6 rsbvs r3, r3, r1, lsl #22
 *   @0x315aba stmdavs r2!, {r0, r1, r5, r7, r11, sp, lr}
 *   @0x315abe adcvs r3, r3, r1, lsl #6
 *   @0x315ac2 mrrcne p9, #0xe, r6, r0, c3
 *   @0x315ac6 ldmvs r9, {r0, r3, r8, r9, r10, r11, r12, pc}
 *   @0x315aca ldmdavc r2, {r5, sp, lr}
 *   @0x315ace andhs lr, r2, #1024
 *   @0x315ad2 stmibvs r3!, {r1, r3, r4, r7, sp, lr} ^
 *   @0x315ad6 andsvs r2, r10, r5, lsl #4
 *   @0x315ada blhs 0x32fc6e
 *   @0x315ade strhi pc, [r5, -r0]!
 *   @0x315ae2 rsbvs r3, r3, r1, lsl #22
 *   @0x315ae6 stmdavs r2!, {r0, r1, r5, r7, r11, sp, lr}
 *   @0x315aea adcvs r3, r3, r1, lsl #6
 *   @0x315aee mrrcne p9, #0xe, r6, r0, c3
 *   @0x315af2 mlavs r0, r9, r8, r6
 *   @0x315af6 ldmdavc r2, {r1, sp}
 *   @0x315afa addsvs r4, r10, r10, lsl #8
 *   @0x315afe ldmvs r10, {r0, r1, r5, r6, r7, r8, r11, sp, lr}
 *   @0x315b02 andhs r6, r6, #-2013265920
 *   @0x315b06 .word 0xf000601a
 *   @0x315b0a andhs r11, sp, #38, #30
 *   @0x315b0e .word 0xf8df601a
 *   @0x315b12 andhs r3, r0, #24, #18
 *   @0x315b16 .word 0x61a3447b
 *   @0x315b1a subsvs r6, r10, r3, ror #19
 *   @0x315b1e cdplt p0, #0xf, c15, c14, c0, #0x0
 *   @0x315b22 stmdavs r2!, {r0, r2, r3, r4, r6, r8, r11, sp, lr} ^
 *   @0x315b26 .word 0xa000f8d4
 *   @0x315b2a blvs 0xdf08ea <b2_toiTime+0x697446>
 *   @0x315b2e addsmi r9, lr, #8, #4
 *   @0x315b32 .word 0xb020f8d5
 *   @0x315b36 ldrsbls pc, [r12], -r5
 *   @0x315b3a bl 0xff4ca376 <b2_toiTime+0xfffffffffed70ed2>
 *   @0x315b3e .word 0xf1080803
 *   @0x315b42 .word 0xf8df38ff
 *   @0x315b46 .word 0xf8df38e8
 *   @0x315b4a ldrbtmi lr, [r11], #-2280
 *   @0x315b4e ldrbtmi r9, [lr], #783
 *   @0x315b52 sub pc, r0, sp, asr #17
 *   @0x315b56 bvs 0xffe0dbe6 <b2_toiTime+0xffffffffff6b4742>
 *   @0x315b5a stmdaeq r3, {r1, r2, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x315b5e .word 0xf1b8e7f1
 *   @0x315b62 .word 0xf0000f00
 *   @0x315b66 stmdbls r8, {r0, r6, r7, pc}
 *   @0x315b6a stmdavs pc!, {r4, r5, r9, r10, lr} ^
 *   @0x315b6e svclt #0x3842b9
 *   @0x315b72 ldrbmi r4, [r1], -pc, lsl #12
 *   @0x315b76 svclt #0x284547
 *   @0x315b7a ldrtmi r4, [r10], #1607
 *   @0x315b7e shasxmi r4, r10, lr
 *   @0x315b82 stmdaeq r8, {r0, r1, r2, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x315b86 ldc p5, c15, [r10, #-640]
 *   @0x315b8a stmdavs r11!, {r3, r9, r11, r12, pc} ^
 *   @0x315b8e andls r1, r8, #215040
 *   @0x315b92 .word 0x606f1bdf
 *   @0x315b96 .word 0xf0002f00
 *   @0x315b9a .word 0x270080f0
 *   @0x315b9e blhs 0x56fc52 <g_SWFlineaavertbuff+0x1cb8a>
 *   @0x315ba2 strthi pc, [r11], -r0, lsl #4
 *   @0x315ba6 .word 0xf013e8df
 *   @0x315baa rsbseq r0, r1, r9, lsl r0
 *   @0x315bae smlalseq r0, sp, r7, r0
 *   @0x315bb2 biceq r0, r5, r12, lsr #2
 *   @0x315bb6 strbeq r0, [r3, #0x358]!
 *   @0x315bba ldreq r0, [r5], -r2, lsl #12
 *   @0x315bbe bhs 0x33c3e6
 *   @0x315bc2 bichi pc, r7, r0
 *   @0x315bc6 bllo 0x393c36 <ft_adobe_glyph_list+0x3312>
 *   @0x315bca blo 0x35f7d2 <_ZTS12CDS_Priority+0x182a>
 *   @0x315bce blx 0x3fa3f6 <g_RomDisk+0x2bd6>
 *   @0x315bd2 .word 0xf109f309
 *   @0x315bd6 b 0x15d7ffe <b2_toiTime+0xe7eb5a>
 *   @0x315bda .word 0xf1b90b03
 *   @0x315bde stmible sp!, {r1, r8, r9, r10, r11} ^
 *   @0x315be2 smlalbteq pc, r1, r11, r3
 *   @0x315be6 movweq pc, #0x100b
 *   @0x315bea .word 0x61ab2902
 *   @0x315bee stmdbhs r3, {r1, r3, r5, r12, lr, pc}
 *   @0x315bf2 stmdbhs r1, {r1, r2, r3, r5, r12, lr, pc}
 *   @0x315bf6 .word 0xf1a9d00b
 *   @0x315bfa b 0x16d640e <b2_toiTime+0xf7cf6a>
 *   @0x315bfe .word 0xf00201db
 *   @0x315c02 blx 0xb56826 <b2_toiTime+0x3fd382>
 *   @0x315c06 bl 0xff41481a <b2_toiTime+0xfffffffffecbb376>
 *   @0x315c0a movwhs r0, #0x1902
 *   @0x315c0e bvs 0xc0defe <b2_toiTime+0x4b4a5a>
 *   @0x315c12 bvs 0xfeb1e48a <b2_toiTime+0xfffffffffe3c4fe6>
 *   @0x315c16 .word 0xb1584798
 *   @0x315c1a movwhs r9, #0x913
 *   @0x315c1e movwhs r6, #0x9003
 *   @0x315c22 movwhs r7, #0x5403
 *   @0x315c26 .word 0xf8df7443
 *   @0x315c2a orrvs r3, r1, r12, lsl #16
 *   @0x315c2e .word 0x6143447b
 *   @0x315c32 stmdahs r0, {r3, r5, r6, sp, lr}
 *   @0x315c36 ldrbthi pc, [r11], -r0
 *   @0x315c3a bleq 0xffa1057e <b2_toiTime+0xffffffffff2b70da>
 *   @0x315c3e stmdbeq r3, {r0, r3, r5, r7, r8, r12, sp, lr, pc}
 *   @0x315c42 adds r2, pc, r6, lsl #6
 *   @0x315c46 bleq 0xffa1058a <b2_toiTime+0xffffffffff2b70e6>
 *   @0x315c4a stmdbeq r3, {r0, r3, r5, r7, r8, r12, sp, lr, pc}
 *   @0x315c4e adds r2, r9, r3, lsl #6
 *   @0x315c52 eorvs r2, r11, r9, lsl #6
 *   @0x315c56 ubfxlo pc, pc, #0x11, #0x5
 *   @0x315c5a .word 0x61a3447b
 *   @0x315c5e bicseq lr, r11, #323584
 *   @0x315c62 .word 0xf1a9622b
 *   @0x315c66 mvnvs r0, r3, lsl #6
 *   @0x315c6a ldclt p0, c15, [r7, #0]!
 *   @0x315c6e stmdahs r0, {r3, r11, r12, pc}
 *   @0x315c72 msrhi SPSR_f, r0
 *   @0x315c76 bllo 0x393ce6 <ft_adobe_glyph_list+0x33c2>
 *   @0x315c7a stmdalo r1, {r8, r9, r10, sp}
 *   @0x315c7e blx 0x3f9ca6 <g_RomDisk+0x2486>
 *   @0x315c82 .word 0xf109f309
 *   @0x315c86 b 0x15d80ae <b2_toiTime+0xe7ec0a>
 *   @0x315c8a .word 0xf1b90b03
 *   @0x315c8e stmible sp!, {r0, r1, r2, r3, r4, r8, r9, r10, r11} ^
 *   @0x315c92 movweq lr, #0xba6f
 *   @0x315c96 .word 0xf28bfa1f
 *   @0x315c9a addsmi r0, r3, #6912
 *   @0x315c9e bls 0x549cda <gp_ActiveMaskObjects+0x5012>
 *   @0x315ca2 eorvs r2, r11, r9, lsl #6
 *   @0x315ca6 .word 0x3798f8df
 *   @0x315caa .word 0x61a3447b
 *   @0x315cae eorlt pc, r0, r5, asr #17
 *   @0x315cb2 andsls pc, r12, r5, asr #17
 *   @0x315cb6 .word 0xf0006062
 *   @0x315cba mlsvs r11, r2, sp, r11
 *   @0x315cbe stmibvs r11!, {r0, r1, r3, r5, r8, r11, r12, sp, pc}
 *   @0x315cc2 svclt #0x142b00
 *   @0x315cc6 movwhs r2, #0x307
 *   @0x315cca movwhs lr, #0x2000
 *   @0x315cce stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x315cd2 strbmi r6, [r11], r11, lsr #32
 *   @0x315cd6 blls 0x54fa66 <gp_ActiveMaskObjects+0xad9e>
 *   @0x315cda .word 0xf47f2b00
 *   @0x315cde .word 0xf8c5af40
 *   @0x315ce2 .word 0xf8c5b020
 *   @0x315ce6 teq r9, r12, lsl r0
 *   @0x315cea addsmi r6, lr, #962560
 *   @0x315cee blvs 0xdca136 <b2_toiTime+0x670c92>
 *   @0x315cf2 addsmi r6, r10, #700416
 *   @0x315cf6 addsmi sp, r3, #12
 *   @0x315cfa bl 0xff4059da <b2_toiTime+0xfffffffffecac536>
 *   @0x315cfe bl 0xff3d7d0e <b2_toiTime+0xfffffffffec7e86a>
 *   @0x315d02 .word 0xf1080806
 *   @0x315d06 ssub8mi r3, lr, pc
 *   @0x315d0a svceq #0xf1b8
 *   @0x315d0e svcge #0x2bf47f
 *   @0x315d12 strtmi r6, [r1], -lr, ror #6
 *   @0x315d16 qasxmi r4, r8, r10
 *   @0x315d1a stc2 p7, c15, [r9], #1020
 *   @0x315d1e blvs 0xd70ade <b2_toiTime+0x61763a>
 *   @0x315d22 addmi r6, lr, #962560
 *   @0x315d26 bl 0xff4c5a06 <b2_toiTime+0xfffffffffed6c562>
 *   @0x315d2a bl 0xff497d36 <b2_toiTime+0xfffffffffed3e892>
 *   @0x315d2e .word 0xf1080803
 *   @0x315d32 addsmi r3, lr, #16711680
 *   @0x315d36 .word 0xd10b4602
 *   @0x315d3a addsmi r6, r9, #700416
 *   @0x315d3e addmi sp, r11, #8
 *   @0x315d42 bl 0xff405a22 <b2_toiTime+0xfffffffffecac57e>
 *   @0x315d46 bl 0xff3d7d52 <b2_toiTime+0xfffffffffec7e8ae>
 *   @0x315d4a .word 0xf1080806
 *   @0x315d4e ssub8mi r3, lr, pc
 *   @0x315d52 svceq #0xf1b8
 *   @0x315d56 svcge #0x7f47f
 *   @0x315d5a eorlt pc, r0, r5, asr #17
 *   @0x315d5e andsls pc, r12, r5, asr #17
 *   @0x315d62 stmdals r8, {r0, r1, r5, r11, sp, lr}
 *   @0x315d66 smlabteq r10, r3, r11, lr
 *   @0x315d6a .word 0xf8c468a3
 *   @0x315d6e rsbvs r10, r0, r0
 *   @0x315d72 adcvs r4, r3, r11, lsl #8
 *   @0x315d76 .word 0xf000636e
 *   @0x315d7a stmibvs r11!, {r2, r4, r8, r10, r11, r12, sp, pc}
 *   @0x315d7e svclt #0x142b00
 *   @0x315d82 movwhs r2, #0x307
 *   @0x315d86 str r6, [r9, -r11, lsr #32]
 *   @0x315d8a cmnlt r3, r8, lsl #22
 *   @0x315d8e movwls r3, #0x8b01
 *   @0x315d92 bllo 0x393e02 <ft_adobe_glyph_list+0x34de>
 *   @0x315d96 blx 0x3df99e <error_g0017+0x38642>
 *   @0x315d9a .word 0xf109f309
 *   @0x315d9e b 0x15d81c6 <b2_toiTime+0xe7ed22>
 *   @0x315da2 .word 0xf1b90b03
 *   @0x315da6 stmible pc!, {r0, r2, r3, r8, r9, r10, r11} ^
 *   @0x315daa stmdals r8, {r1, r2, sp, lr, pc}
 *   @0x315dae eorlt pc, r0, r5, asr #17
 *   @0x315db2 andsls pc, r12, r5, asr #17
 *   @0x315db6 sbcs r6, r2, r0, rrx
 *   @0x315dba tsteq pc, r11
 *   @0x315dbe andeq pc, sp, #738197507
 *   @0x315dc2 rsbvs r2, r10, sp, lsl r9
 *   @0x315dc6 movwhs sp, #0x9905
 *   @0x315dca .word 0xf8df602b
 *   @0x315dce ldrbtmi r3, [r11], #-1652
 *   @0x315dd2 .word 0xf3c2e0ff
 *   @0x315dd6 bhs 0xa5a6ee <b2_toiTime+0x30124a>
 *   @0x315dda .word 0xf501d8f5
 *   @0x315dde bvs 0xbf23ea <b2_toiTime+0x498f46>
 *   @0x315de2 bvs 0xfeb26e2e <b2_toiTime+0xfffffffffe3cd98a>
 *   @0x315de6 ldrmi r2, [r8, r4, lsl #4]
 *   @0x315dea stmdahs r0, {r3, r5, r6, r7, sp, lr}
 *   @0x315dee ldrhi pc, [pc]
 *   @0x315df2 bllo 0xfea10736 <b2_toiTime+0xfffffffffe2b7292>
 *   @0x315df6 stmdbeq lr, {r0, r3, r5, r7, r8, r12, sp, lr, pc}
 *   @0x315dfa adcvs r2, r11, r0, lsl #6
 *   @0x315dfe eorvs r2, r11, r4, lsl #6
 *   @0x315e02 .word 0x1644f8df
 *   @0x315e06 stmdavs r10!, {r0, r3, r4, r5, r6, r10, lr} ^
 *   @0x315e0a beq 0xfe7b00be <b2_toiTime+0xfffffffffe056c1a>
 *   @0x315e0e addsmi r3, r3, #4, #4
 *   @0x315e12 .word 0xf1b9d221
 *   @0x315e16 stmdale pc, {r1, r8, r9, r10, r11}
 *   @0x315e1a stmdahs r0, {r3, r11, r12, pc}
 *   @0x315e1e addshi pc, r2, r0
 *   @0x315e22 blhs 0x393e92 <ft_adobe_glyph_list+0x356e>
 *   @0x315e26 strhs r3, [r0, -r1, lsl #16]
 *   @0x315e2a blx 0x3b9e52 <error_g0017+0x12af6>
 *   @0x315e2e .word 0xf109f209
 *   @0x315e32 b 0x15d825a <b2_toiTime+0xe7edb6>
 *   @0x315e36 strb r0, [r12, r2, lsl #22]!
 *   @0x315e3a bl 0x35cfa2 <_ZTS7CFontGM+0x66a>
 *   @0x315e3e stmvs r10!, {r0, r1, r7, r8, r9} ^
 *   @0x315e42 stmdbeq r3, {r0, r3, r5, r7, r8, r12, sp, lr, pc}
 *   @0x315e46 umlalvs r6, r8, r11, r8
 *   @0x315e4a andeq pc, r7, r11
 *   @0x315e4e bleq 0xffa10792 <b2_toiTime+0xffffffffff2b72ee>
 *   @0x315e52 eoreq pc, r3, r2, asr #16
 *   @0x315e56 .word 0xf8dfe7d7
 *   @0x315e5a strdhs r2, r3, [r0, -r0]
 *   @0x315e5e stmvs r11!, {r1, r3, r4, r5, r6, r10, lr}
 *   @0x315e62 blhs 0x7b020a <b2_toiTime+0x56d66>
 *   @0x315e66 stmdale r8, {r1, r3, r12, pc}
 *   @0x315e6a bl 0x39cfd2 <ft_adobe_glyph_list+0xc6ae>
 *   @0x315e6e adcvs r0, r8, r3, lsl #7
 *   @0x315e72 stmdals r10, {r0, r1, r3, r4, r7, r11, sp, lr}
 *   @0x315e76 eorne pc, r3, r0, asr #16
 *   @0x315e7a qsub8mi lr, r11, r1
 *   @0x315e7e .word 0xf8432207
 *   @0x315e82 .word 0xf04f2f10
 *   @0x315e86 movwls r0, #0xcc00
 *   @0x315e8a tsteq r4, #1073741825
 *   @0x315e8e tsths r3, sp, lsl #6
 *   @0x315e92 andhs r6, r4, #438272
 *   @0x315e96 rsbgt pc, r4, sp, asr #17
 *   @0x315e9a movwls r6, #0xbaa0
 *   @0x315e9e andsgt pc, r8, sp, asr #17
 *   @0x315ea2 ldrmi r6, [r8, r3, lsr #20]
 *   @0x315ea6 ldrsbgt pc, [r8], -sp
 *   @0x315eaa stmdahs r0, {r7, r9, r10, lr}
 *   @0x315eae blls 0x689f62 <g_SWFlinevertbuff+0x36e9a>
 *   @0x315eb2 andls r2, r5, r3, lsl r1
 *   @0x315eb6 .word 0xf8cd460a
 *   @0x315eba movwls r12, #0x1000
 *   @0x315ebe stmdals r10, {r2, r3, r8, r9, r11, r12, pc}
 *   @0x315ec2 blls 0x5faad2 <g_SWFaavertbuff+0x27a0a>
 *   @0x315ec6 blge 0x97aada <b2_toiTime+0x221636>
 *   @0x315eca strbtmi r9, [r3], -r4, lsl #6
 *   @0x315ece .word 0xf95df7ff
 *   @0x315ed2 strmi r1, [r2], -r3, asr #25
 *   @0x315ed6 .word 0xf8dfd104
 *   @0x315eda ldrbtmi r3, [r11], #-1396
 *   @0x315ede and r6, r9, r3, lsr #3
 *   @0x315ee2 andle r3, r1, r5
 *   @0x315ee6 stmdblt r11!, {r0, r1, r3, r5, r8, r11, sp, lr}
 *   @0x315eea strblo pc, [r8, #-0x8df]!
 *   @0x315eee andeq pc, r2, #111
 *   @0x315ef2 .word 0x61a3447b
 *   @0x315ef6 strbmi r6, [r1], -r3, ror #20
 *   @0x315efa andls r6, r7, #160, #20
 *   @0x315efe bls 0x4e7d66 <SrcVerts+0x44daa>
 *   @0x315f02 .word 0xb19a4690
 *   @0x315f06 .word 0xf06fe002
 *   @0x315f0a and r0, r8, r3, lsl #16
 *   @0x315f0e svceq #0x3f112
 *   @0x315f12 bvs 0x1c0a32e <b2_toiTime+0x14b0e8a>
 *   @0x315f16 stmvs r9!, {r5, r7, r9, r11, sp, lr} ^
 *   @0x315f1a movwhs r4, #0x9798
 *   @0x315f1e stmdals r8, {r0, r1, r3, r5, sp, lr}
 *   @0x315f22 eorlt pc, r0, r5, asr #17
 *   @0x315f26 andsls pc, r12, r5, asr #17
 *   @0x315f2a .word 0xe1676060
 *   @0x315f2e adcvs r2, r10, r5, lsl #6
 *   @0x315f32 .word 0xf8df602b
 *   @0x315f36 .word 0xf8df1520
 *   @0x315f3a ldrbtmi r2, [r9], #-1312
 *   @0x315f3e ldrbtmi r9, [r10], #-267
 *   @0x315f42 rsbs r9, r6, r12, lsl #4
 *   @0x315f46 .word 0xf8c59908
 *   @0x315f4a .word 0xf8c5b020
 *   @0x315f4e rsbvs r9, r1, r12, lsl r0
 *   @0x315f52 blls 0x54df6e <gp_ActiveMaskObjects+0x92a6>
 *   @0x315f56 eorlt pc, r0, r5, asr #17
 *   @0x315f5a andsls pc, r12, r5, asr #17
 *   @0x315f5e stmdavs r3!, {r0, r1, r5, r6, sp, lr}
 *   @0x315f62 .word 0xf8c44628
 *   @0x315f66 strtmi r10, [r1], -r0
 *   @0x315f6a andeq lr, r10, #199680
 *   @0x315f6e ldrmi r6, [r3], #-2211
 *   @0x315f72 adcvs r4, r3, r10, lsr r6
 *   @0x315f76 .word 0xf000636e
 *   @0x315f7a stmdbls sp, {r0, r1, r4, r6, r10, r11, r12, sp, pc}
 *   @0x315f7e svclt #0x142912
 *   @0x315f82 mrshs r3, apsr
 *   @0x315f86 vmlaeq.f64 d14, d0, d1
 *   @0x315f8a .word 0xf04fbf14
 *   @0x315f8e .word 0xf04f0803
 *   @0x315f92 ldrbmi r0, [r1, #0x80b]!
 *   @0x315f96 bls 0x64ad1a <g_SWFaavertbuff+0x77c52>
 *   @0x315f9a .word 0xfc00fa2b
 *   @0x315f9e andeq lr, r9, r0, asr #23
 *   @0x315fa2 vdiveq.f64 d14, d1, d2
 *   @0x315fa6 stmdbeq r0, {r0, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x315faa blx 0xe3bfda <b2_toiTime+0x6e2b36>
 *   @0x315fae .word 0xf8defb01
 *   @0x315fb2 b 0x64e10a <g_SWFaavertbuff+0x7b042>
 *   @0x315fb6 strbmi r0, [r6], #3598
 *   @0x315fba .word 0x0103eb0e
 *   @0x315fbe ldmdble r10, {r0, r7, r9, lr} ^
 *   @0x315fc2 bvs 0xfeb30956 <b2_toiTime+0xfffffffffe3d74b2>
 *   @0x315fc6 ldrmi r6, [r8, r9, ror #17]
 *   @0x315fca eorvs r2, r11, r9, lsl #6
 *   @0x315fce ldrlo pc, [r0], #2271
 *   @0x315fd2 stmdbls r8, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x315fd6 .word 0xf8c561a3
 *   @0x315fda .word 0xf8c5b020
 *   @0x315fde rsbvs r9, r1, r12, lsl r0
 *   @0x315fe2 stmdals r8, {r0, r2, r3, r4, r5, r6, r7, r8, r9, sp, lr, pc}
 *   @0x315fe6 adcle r2, sp, r0, lsl #16
 *   @0x315fea blne 0x39405a <ft_adobe_glyph_list+0x3736>
 *   @0x315fee stmdalo r1, {r8, r9, r10, sp}
 *   @0x315ff2 blx 0x37a01a <_ZTS13C_UTF16String+0x110c6>
 *   @0x315ff6 .word 0xf109f109
 *   @0x315ffa b 0x15d8422 <b2_toiTime+0xe7ef7e>
 *   @0x315ffe ldrmi r0, [r1, #0xb01]
 *   @0x316002 .word 0xf8ddd3ef
 *   @0x316006 bl 0x6ce0be <g_SWFlinevertbuff+0x7aff6>
 *   @0x31600a ldclvs p2, c0, [r1, #-520]
 *   @0x31600e b 0x5f05be <g_SWFaavertbuff+0x1d4f6>
 *   @0x316012 bl 0x39641e <ft_adobe_glyph_list+0x5afa>
 *   @0x316016 ldmdavc r0, {r0, r6, r7, r9} ^
 *   @0x31601a bhs 0x6f016a <g_SWFvertbuff+0x1d0a2>
 *   @0x31601e stmle r12!, {r0, r2, r3, r9, r12, pc}
 *   @0x316022 blx 0xdf03ce <b2_toiTime+0x696f2a>
 *   @0x316026 bl 0xff354c2e <b2_toiTime+0xfffffffffebfb78a>
 *   @0x31602a mrrcne p9, #0x0, r0, r8, c9
 *   @0x31602e .word 0xf84160a8
 *   @0x316032 stmdavs r9!, {r0, r1, r5, sp} ^
 *   @0x316036 .word 0xf00168ab
 *   @0x31603a vmov.i32 d16, #0x9f00
 *   @0x31603e .word 0x910d1144
 *   @0x316042 orrvc pc, r1, r2, lsl #10
 *   @0x316046 ldrsbt pc, [r4], -sp
 *   @0x31604a .word 0xf8cd448e
 *   @0x31604e ldrbmi lr, [r3, #-0x28]!
 *   @0x316052 stmdbvs r10!, {r3, r5, r9, r12, lr, pc}
 *   @0x316056 bls 0x54ffaa <gp_ActiveMaskObjects+0xb2e2>
 *   @0x31605a .word 0xf43f2a00
 *   @0x31605e .word 0xf81aaf7a
 *   @0x316062 blo 0x374c6e <_ZTS13C_UTF16String+0xbd1a>
 *   @0x316066 blx 0x4fa88e <SrcVerts+0x578d2>
 *   @0x31606a .word 0xf109f709
 *   @0x31606e b 0x15d8496 <b2_toiTime+0xe7eff2>
 *   @0x316072 strhs r0, [r0, -r7, lsl #22]
 *   @0x316076 bls 0x68feb2 <g_SWFlinevertbuff+0x3cdea>
 *   @0x31607a .word 0xd1082a10
 *   @0x31607e addsle r2, pc, r0, lsl #22
 *   @0x316082 addmi pc, r0, r3, lsl #2
 *   @0x316086 stmdalo r1, {r1, r3, r5, r6, r7, r11, sp, lr}
 *   @0x31608a eoreq pc, r0, r2, asr r8
 *   @0x31608e andhs lr, r0, r0
 *   @0x316092 stmvs r10!, {r0, r1, r3, r4, r7} ^
 *   @0x316096 mcreq p1, #0x0, pc, c1, c14, #0x5
 *   @0x31609a .word 0xf10350d0
 *   @0x31609e mvnsle r0, r4, lsl #6
 *   @0x3160a2 strb r6, [r6, r9, lsr #1]
 *   @0x3160a6 smlatths r9, r8, r8, r6
 *   @0x3160aa .word 0x21069115
 *   @0x3160ae movwhs r9, #0x116
 *   @0x3160b2 .word 0xf2026a69
 *   @0x3160b6 .word 0x616b1201
 *   @0x3160ba andhs r9, r4, #-1610612736
 *   @0x3160be .word 0x910c900b
 *   @0x3160c2 orrsvc pc, r0, pc, asr #8
 *   @0x3160c6 bvs 0xfeb3ad32 <b2_toiTime+0xfffffffffe3e188e>
 *   @0x3160ca ldrmi r6, [r8, r3, lsr #20]
 *   @0x3160ce stmdahs r0, {r7, r9, r10, lr}
 *   @0x3160d2 bls 0x6ca2d6 <g_SWFlinevertbuff+0x7720e>
 *   @0x3160d6 stcleq p1, c15, [r4], #-52
 *   @0x3160da .word 0xf5029005
 *   @0x3160de movwls r7, #0x38a
 *   @0x3160e2 movwls r10, #0x1b17
 *   @0x3160e6 movwls r10, #0x2b15
 *   @0x3160ea .word 0xf2409b0c
 *   @0x3160ee .word 0xf8cd1201
 *   @0x3160f2 stmdals r11, {r4, lr, pc}
 *   @0x3160f6 stmdbls r10, {r0, r1, r8, r9, r12, pc}
 *   @0x3160fa .word 0xf8cd9b12
 *   @0x3160fe .word 0xf7ffc018
 *   @0x316102 .word 0xf8ddf844
 *   @0x316106 .word 0x4602c018
 *   @0x31610a blls 0x884552 <b2_toiTime+0x12b0ae>
 *   @0x31610e ands r11, r4, r3, asr #2
 *   @0x316112 smlabtle r3, r1, r12, r1
 *   @0x316116 ldrbtmi r4, [r11], #-3027
 *   @0x31611a and r6, r6, r3, lsr #3
 *   @0x31611e andle r1, r4, r3, lsl #26
 *   @0x316122 .word 0xf06f4bd1
 *   @0x316126 ldrbtmi r0, [r11], #-514
 *   @0x31612a bvs 0x1bee7be <b2_toiTime+0x149531a>
 *   @0x31612e bvs 0xfeb27a3a <b2_toiTime+0xfffffffffe3ce596>
 *   @0x316132 ldrmi r9, [r8, r7, lsl #4]
 *   @0x316136 ldrmi r9, [r0], r7, lsl #20
 *   @0x31613a .word 0xf8dde04e
 *   @0x31613e stmdals r12, {r3, r4, r5, sp, lr, pc}
 *   @0x316142 movwvc pc, #0x250e
 *   @0x316146 blge 0x93ad4e <b2_toiTime+0x1e18aa>
 *   @0x31614a blge 0x8bad56 <b2_toiTime+0x1618b2>
 *   @0x31614e blls 0x5bad5e <g_SWFlineaavertbuff+0x67c96>
 *   @0x316152 .word 0xf8dd990b
 *   @0x316156 andls lr, r3, r4, lsr r0
 *   @0x31615a addeq lr, r3, r1, lsl #22
 *   @0x31615e mrseq pc, apsr
 *   @0x316162 ldrsbt pc, [r8], -sp
 *   @0x316166 andsgt pc, r0, sp, asr #17
 *   @0x31616a bicvc pc, r8, #58720256
 *   @0x31616e andshi pc, r4, sp, asr #17
 *   @0x316172 .word 0xf80bf7ff
 *   @0x316176 strmi r6, [r4], r3, ror #20
 *   @0x31617a bls 0x8c4662 <b2_toiTime+0x16b1be>
 *   @0x31617e stmdals r10, {r1, r3, r4, r8, r9, r11, r12, sp, pc}
 *   @0x316182 .word 0x1101f240
 *   @0x316186 tstle r0, r8, lsl #5
 *   @0x31618a .word 0xf110e01d
 *   @0x31618e .word 0xd1030f03
 *   @0x316192 ldrbtmi r4, [r10], #-2742
 *   @0x316196 and r6, sp, r2, lsr #3
 *   @0x31619a svceq #0x5f110
 *   @0x31619e bmi 0xff00a5ae <b2_toiTime+0xfffffffffe8b110a>
 *   @0x3161a2 and r4, r4, r10, ror r4
 *   @0x3161a6 svceq #0x4f110
 *   @0x3161aa bmi 0xfef8a1c2 <b2_toiTime+0xfffffffffe830d1e>
 *   @0x3161ae .word 0xf06f447a
 *   @0x3161b2 .word 0x61a20c02
 *   @0x3161b6 strbmi r6, [r1], -r0, lsr #21
 *   @0x3161ba andsgt pc, r8, sp, asr #17
 *   @0x3161be .word 0xf8dd4798
 *   @0x3161c2 usatmi r12, #0x0, r8
 *   @0x3161c6 strbmi lr, [r1], -r8
 *   @0x3161ca ldrmi r6, [r8, r0, lsr #21]
 *   @0x3161ce stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x3161d2 .word 0xf06fe021
 *   @0x3161d6 and r0, r11, r3, lsl #16
 *   @0x3161da svceq #0xf1b8
 *   @0x3161de .word 0xf118d01b
 *   @0x3161e2 .word 0xd1050f03
 *   @0x3161e6 bvs 0xfeb30b7a <b2_toiTime+0xfffffffffe3d76d6>
 *   @0x3161ea ldrmi r6, [r8, r9, ror #17]
 *   @0x3161ee eorvs r2, r11, r9, lsl #6
 *   @0x3161f2 .word 0xf8c59a08
 *   @0x3161f6 .word 0xf8c5b020
 *   @0x3161fa rsbvs r9, r2, r12, lsl r0
 *   @0x3161fe strtmi r6, [r8], -r3, lsr #16
 *   @0x316202 andge pc, r0, r4, asr #17
 *   @0x316206 bl 0xff3e7a92 <b2_toiTime+0xfffffffffec8e5ee>
 *   @0x31620a stmvs r3!, {r1, r3, r9}
 *   @0x31620e .word 0x46424413
 *   @0x316212 .word 0x636e60a3
 *   @0x316216 blls 0x88ee2e <b2_toiTime+0x13598a>
 *   @0x31621a bvs 0xfeb1e626 <b2_toiTime+0xfffffffffe3c5182>
 *   @0x31621e movwls r2, #0xa21c
 *   @0x316222 movwls r9, #0xdb16
 *   @0x316226 movwls r9, #0xbb17
 *   @0x31622a movwls r9, #0xcb18
 *   @0x31622e ldrmi r6, [r8, r3, lsr #20]
 *   @0x316232 .word 0xf0002800
 *   @0x316236 blls 0x5b702e <g_SWFlineaavertbuff+0x63f66>
 *   @0x31623a andhi pc, r0, r0, asr #17
 *   @0x31623e blls 0x673252 <g_SWFlinevertbuff+0x2018a>
 *   @0x316242 blls 0x5f3356 <g_SWFaavertbuff+0x2028e>
 *   @0x316246 blls 0x62e75a <g_SWFaavertbuff+0x5b692>
 *   @0x31624a rsbvs r6, r8, r3, lsl #3
 *   @0x31624e bvs 0x1bf05fa <b2_toiTime+0x1497156>
 *   @0x316252 ldrmi r6, [r8, r0, lsr #21]
 *   @0x316256 eorvs r2, r11, r6, lsl #6
 *   @0x31625a eorlt pc, r0, r5, asr #17
 *   @0x31625e andsls pc, r12, r5, asr #17
 *   @0x316262 stmdals r8, {r0, r1, r5, r11, sp, lr}
 *   @0x316266 andeq lr, r10, #199680
 *   @0x31626a .word 0xf8c468a3
 *   @0x31626e rsbvs r10, r0, r0
 *   @0x316272 adcvs r4, r3, r3, lsl r4
 *   @0x316276 .word 0x636e6b29
 *   @0x31627a stmdavs r11!, {r1, r2, r3, r7, r9, lr} ^
 *   @0x31627e andne lr, r0, #148, #16
 *   @0x316282 .word 0xa020f8d5
 *   @0x316286 ldrsbhi pc, [r12], -r5
 *   @0x31628a blne 0xfe58aaa6 <b2_toiTime+0xfffffffffde31602>
 *   @0x31628e bmi 0x216469a <b2_toiTime+0x1a0b1f6>
 *   @0x316292 andls r4, r8, #2046820352
 *   @0x316296 bvs 0xffd8e2c6 <b2_toiTime+0xffffffffff634e22>
 *   @0x31629a ldrb r1, [r8, r9, lsl #23]!
 *   @0x31629e svceq #0x40f010
 *   @0x3162a2 sbcsvs sp, r8, lr, asr #2
 *   @0x3162a6 bl 0x3b03ee <error_g0017+0x9092>
 *   @0x3162aa addsvs r0, r10, r0, asr #5
 *   @0x3162ae bhs 0x57031e <g_SWFlineaavertbuff+0x1d256>
 *   @0x3162b2 eorhi pc, r4, #0, #4
 *   @0x3162b6 .word 0xf012e8df
 *   @0x3162ba andseq r0, r0, r10
 *   @0x3162be rsbseq r0, r4, sp, asr #32
 *   @0x3162c2 tsteq r10, r11, lsr #1
 *   @0x3162c6 biceq r0, sp, r9, ror r1
 *   @0x3162ca andeq r0, lr, #-1073741762
 *   @0x3162ce sbcsvs r7, r10, r10, lsl r12
 *   @0x3162d2 addsvs r6, r10, r10, asr r9
 *   @0x3162d6 andsvs r2, r10, r1, lsl #4
 *   @0x3162da ldrmi r6, [r0, #0x8da]
 *   @0x3162de .word 0xf1bcd20f
 *   @0x3162e2 .word 0xf0000f00
 *   @0x3162e6 .word 0xf81980d0
 *   @0x3162ea .word 0xf10c0b01
 *   @0x3162ee .word 0x27003cff
 *   @0x3162f2 .word 0xf008fa00
 *   @0x3162f6 stmdaeq r8, {r3, r8, r12, sp, lr, pc}
 *   @0x3162fa beq 0x350c2a
 *   @0x3162fe ldmdami lr, {r0, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x316302 bl 0x3274ea
 *   @0x316306 ldmvs r8, {r1, r7, r9}
 *   @0x31630a b 0x5b185a <g_SWFlineaavertbuff+0x5e792>
 *   @0x31630e bl 0x319b1e <__gnu_Unwind_ForcedUnwind+0xe>
 *   @0x316312 .word 0xf81002ce
 *   @0x316316 .word 0xf892003e
 *   @0x31631a blx 0xdc2326 <b2_toiTime+0x668e82>
 *   @0x31631e bl 0xff614b52 <b2_toiTime+0xfffffffffeebb6ae>
 *   @0x316322 ldmdblt r8, {r3, r11}
 *   @0x316326 addsvs r6, r10, r2, asr r8
 *   @0x31632a teq r12, r6, lsl #4
 *   @0x31632e svceq #0x10f010
 *   @0x316332 .word 0xf000d0b4
 *   @0x316336 addsvs r0, r8, pc
 *   @0x31633a subsvs r6, r10, r2, asr r8
 *   @0x31633e teq r2, r2, lsl #4
 *   @0x316342 strle r0, [r1, #-0x682]
 *   @0x316346 .word 0xe12e2207
 *   @0x31634a andsvs r2, r10, r9, lsl #4
 *   @0x31634e ldrbtmi r4, [r11], #-2892
 *   @0x316352 ldmvs r10, {r0, r1, r3, r4, r6, sp, lr, pc}
 *   @0x316356 andle r4, pc, #144, #10
 *   @0x31635a svceq #0xf1bc
 *   @0x31635e addshi pc, r3, r0
 *   @0x316362 bleq 0x3943ce <ft_adobe_glyph_list+0x3aaa>
 *   @0x316366 ldcllo p1, c15, [pc], #48
 *   @0x31636a blx 0x31ff72
 *   @0x31636e .word 0xf108f008
 *   @0x316372 b 0x159839a <b2_toiTime+0xe3eef6>
 *   @0x316376 strb r0, [sp, r0, lsl #20]!
 *   @0x31637a .word 0xe020f8dd
 *   @0x31637e stmdaeq r8, {r1, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x316382 addeq lr, r2, lr, lsl #22
 *   @0x316386 b 0x5b188e <g_SWFlineaavertbuff+0x5e7c6>
 *   @0x31638a blx 0xd99b92 <b2_toiTime+0x6406ee>
 *   @0x31638e .word 0x7c5afa02
 *   @0x316392 sbcsvs r6, r10, r8, asr r8
 *   @0x316396 ldmibvs r10, {r4, r5, r6, r10, lr}
 *   @0x31639a addsvs r6, r10, r8, asr r0
 *   @0x31639e andsvs r2, r10, r3, lsl #4
 *   @0x3163a2 ldrmi r6, [r0, #0x8da]
 *   @0x3163a6 .word 0xf1bcd20e
 *   @0x3163aa rsble r0, r12, r0, lsl #30
 *   @0x3163ae bleq 0x39441a <ft_adobe_glyph_list+0x3af6>
 *   @0x3163b2 ldcllo p1, c15, [pc], #48
 *   @0x3163b6 blx 0x31ffbe
 *   @0x3163ba .word 0xf108f008
 *   @0x3163be b 0x15983e6 <b2_toiTime+0xe3ef42>
 *   @0x3163c2 strb r0, [lr, r0, lsl #20]!
 *   @0x3163c6 bl 0x33c40e
 *   @0x3163ca ldmvs r8, {r1, r7, r9}
 *   @0x3163ce b 0x5b191e <g_SWFlineaavertbuff+0x5e856>
 *   @0x3163d2 bl 0x319be2 <_Unwind_DeleteException+0x1e>
 *   @0x3163d6 .word 0xf81002ce
 *   @0x3163da .word 0xf892003e
 *   @0x3163de .word 0xf010b001
 *   @0x3163e2 blx 0xd9a02a <b2_toiTime+0x640b86>
 *   @0x3163e6 bl 0xff614c1a <b2_toiTime+0xfffffffffeebb776>
 *   @0x3163ea andle r0, r6, r8, lsl #16
 *   @0x3163ee andeq pc, pc, r0
 *   @0x3163f2 ldmdavs r2, {r3, r4, r7, sp, lr} ^
 *   @0x3163f6 andhs r6, r4, #218
 *   @0x3163fa .word 0xf010e0d5
 *   @0x3163fe .word 0xf43f0f40
 *   @0x316402 andhs r10, r9, #80, #30
 *   @0x316406 blmi 0xaae476 <b2_toiTime+0x354fd2>
 *   @0x31640a .word 0x61a3447b
 *   @0x31640e ldmvs r10, {r1, r5, r6, r8, sp, lr, pc}
 *   @0x316412 .word 0xf7d8e05a
 *   @0x316416 cdpls p0, #0xc, c0, c5, c8, #0x0
 *   @0x31641a .word 0xf7c00007
 *   @0x31641e ldclls p0, c0, [r12], #-32
 *   @0x316422 ldclls p0, c0, [sp], #-28
 *   @0x316426 mrrcls p0, #0x0, r0, r5, c7
 *   @0x31642a blls 0xfe89644e <b2_toiTime+0xfffffffffe13cfaa>
 *   @0x31642e .word 0xf5f40007
 *   @0x316432 .word 0xf5f00008
 *   @0x316436 ldr r0, [r10], #-8
 *   @0x31643a bls 0x1b96462 <b2_toiTime+0x143cfbe>
 *   @0x31643e bls 0xc56462 <b2_toiTime+0x4fcfbe>
 *   @0x316442 ldmdbls r12, {r0, r1, r2}
 *   @0x316446 .word 0xf33a0007
 *   @0x31644a vaddl.s32 q8, d2, d8
 *   @0x31644e ldmdals r4!, {r3}
 *   @0x316452 stmdals r6, {r0, r1, r2} ^
 *   @0x316456 vhadd.s8 d0, d4, d7
 *   @0x31645a vhadd.s8 d0, d0, d8
 *   @0x31645e strls r0, [r10, r8]
 *   @0x316462 ldrbls r0, [lr], -r7
 *   @0x316466 ldrbtls r0, [r1], -r7
 *   @0x31646a strtls r0, [r4], -r7
 *   @0x31646e ldrtls r0, [r3], -r7
 *   @0x316472 strbls r0, [r0], -r7
 *   @0x316476 cdp p0, #0xa, c0, c14, c7, #0x0
 *   @0x31647a cdp p0, #0x3, c0, c14, c8, #0x0
 *   @0x31647e ldrtls r0, [pc], #8
 *   @0x316482 strtls r0, [r1], #-7
 *   @0x316486 .word 0xf8c50007
 *   @0x31648a strtmi r10, [r8], -r0, lsr #32
 *   @0x31648e andshi pc, r12, r5, asr #17
 *   @0x316492 stmdavs r3!, {r0, r5, r9, r10, lr}
 *   @0x316496 andgt pc, r4, r4, asr #17
 *   @0x31649a andeq lr, r9, #199680
 *   @0x31649e .word 0xf8c468a3
 *   @0x3164a2 ldrmi r9, [r3], #-0
 *   @0x3164a6 adcvs r4, r3, r10, lsr r6
 *   @0x3164aa teq r10, lr, ror #6
 *   @0x3164ae svceq #0xf1bc
 *   @0x3164b2 .word 0xf819d0e9
 *   @0x3164b6 .word 0xf10c0b01
 *   @0x3164ba .word 0x27003cff
 *   @0x3164be .word 0xf008fa00
 *   @0x3164c2 stmdaeq r8, {r3, r8, r12, sp, lr, pc}
 *   @0x3164c6 beq 0x350df6
 *   @0x3164ca .word 0xd3ef4590
 *   @0x3164ce ldrsbt pc, [r12], -sp
 *   @0x3164d2 stmdaeq r8, {r1, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x3164d6 addeq lr, r2, lr, lsl #22
 *   @0x3164da b 0x5b19e2 <g_SWFlineaavertbuff+0x5e91a>
 *   @0x3164de ldmvs r8, {r9, r10, r11} ^
 *   @0x3164e2 blx 0x3d4d92 <error_g0017+0x2da36>
 *   @0x3164e6 ldrbtmi r2, [r0], #-517
 *   @0x3164ea sbcsvs r6, r8, r10, lsl r0
 *   @0x3164ee bl 0xff3b085e <b2_toiTime+0xfffffffffec573ba>
 *   @0x3164f2 bvs 0xfed99112 <b2_toiTime+0xfffffffffe63fc6e>
 *   @0x3164f6 andsle r4, r6, #616562688
 *   @0x3164fa bne 0xfe3310a2 <b2_toiTime+0xfffffffffdbd7bfe>
 *   @0x3164fe ldrb r4, [r9, r3, lsl #9]!
 *   @0x316502 .word 0xf89bb1a9
 *   @0x316506 .word 0xf10b0000
 *   @0x31650a .word 0xf1060201
 *   @0x31650e stmdblo r1, {r0, r9, r10, r11}
 *   @0x316512 eorsvc r2, r0, r0, lsl #14
 *   @0x316516 bvs 0xffd27ef6 <b2_toiTime+0xffffffffff5cea52>
 *   @0x31651a ldmdavs r8, {r1, r7, r9, lr} ^
 *   @0x31651e bvs 0xfedc6146 <b2_toiTime+0xfffffffffe66cca2>
 *   @0x316522 subsvs r3, r8, r1, lsl #16
 *   @0x316526 ldmdavs r10, {r0, r1, r4, r7, r9, r10, lr} ^
 *   @0x31652a mvnle r2, r0, lsl #20
 *   @0x31652e bvs 0xffdce622 <b2_toiTime+0xffffffffff67517e>
 *   @0x316532 swple r4, r6, [lr]
 *   @0x316536 bvs 0xfedb11e2 <b2_toiTime+0xfffffffffe657d3e>
 *   @0x31653a mulle r10, r1, r2
 *   @0x31653e svclt #0x36428a
 *   @0x316542 smlabteq r1, r2, r11, lr
 *   @0x316546 smlabteq r6, r2, r11, lr
 *   @0x31654a mvnslo pc, r1, lsl #2
 *   @0x31654e stmdbhs r0, {r1, r2, r4, r9, r10, lr}
 *   @0x316552 .word 0x636ed1d7
 *   @0x316556 ldrtmi r4, [r10], -r1, lsr #12
 *   @0x31655a movwls r4, #0x7628
 *   @0x31655e andsgt pc, r8, sp, asr #17
 *   @0x316562 .word 0xf885f7ff
 *   @0x316566 blvs 0xef1326 <b2_toiTime+0x797e82>
 *   @0x31656a adcsmi r9, lr, #7168
 *   @0x31656e ldrsbgt pc, [r8], -sp
 *   @0x316572 bl 0xff4c625a <b2_toiTime+0xfffffffffed6cdb6>
 *   @0x316576 strmi r0, [r2], -r7, lsl #2
 *   @0x31657a svclt #0x346ae8
 *   @0x31657e mvnslo pc, r1, lsl #2
 *   @0x316582 smlabteq r0, r6, r11, lr
 *   @0x316586 smlabble r11, r6, r2, r4
 *   @0x31658a addmi r6, r7, #168, #20
 *   @0x31658e adcsmi sp, r8, #8
 *   @0x316592 bl 0xff346272 <b2_toiTime+0xfffffffffebecdce>
 *   @0x316596 bl 0xff3169ba <b2_toiTime+0xfffffffffebbd516>
 *   @0x31659a .word 0xf1010106
 *   @0x31659e .word 0x460631ff
 *   @0x3165a2 .word 0xd1ae2900
 *   @0x3165a6 andsvs lr, r10, sp, lsr r0
 *   @0x3165aa stmdbhs r0, {r7, r9, r10, sp, lr, pc}
 *   @0x3165ae bvs 0xffdcaada <b2_toiTime+0xffffffffff671636>
 *   @0x3165b2 swple r4, r6, [lr]
 *   @0x3165b6 bvs 0xfedb1262 <b2_toiTime+0xfffffffffe657dbe>
 *   @0x3165ba mulle r10, r1, r2
 *   @0x3165be svclt #0x36428a
 *   @0x3165c2 smlabteq r1, r2, r11, lr
 *   @0x3165c6 smlabteq r6, r2, r11, lr
 *   @0x3165ca mvnslo pc, r1, lsl #2
 *   @0x3165ce stmdbhs r0, {r1, r2, r4, r9, r10, lr}
 *   @0x3165d2 .word 0x636ed137
 *   @0x3165d6 ldrtmi r4, [r10], -r1, lsr #12
 *   @0x3165da movwls r4, #0x7628
 *   @0x3165de andsgt pc, r8, sp, asr #17
 *   @0x3165e2 .word 0xf845f7ff
 *   @0x3165e6 blvs 0xef13a6 <b2_toiTime+0x797f02>
 *   @0x3165ea adcsmi r9, lr, #7168
 *   @0x3165ee ldrsbgt pc, [r8], -sp
 *   @0x3165f2 bl 0xff4c62da <b2_toiTime+0xfffffffffed6ce36>
 *   @0x3165f6 strmi r0, [r2], -r7, lsl #2
 *   @0x3165fa svclt #0x346ae8
 *   @0x3165fe mvnslo pc, r1, lsl #2
 *   @0x316602 smlabteq r0, r6, r11, lr
 *   @0x316606 smlabble r11, r6, r2, r4
 *   @0x31660a addmi r6, r7, #168, #20
 *   @0x31660e adcsmi sp, r8, #8
 *   @0x316612 bl 0xff3462f2 <b2_toiTime+0xfffffffffebece4e>
 *   @0x316616 bl 0xff316a3a <b2_toiTime+0xfffffffffebbd596>
 *   @0x31661a .word 0xf1010106
 *   @0x31661e .word 0x460631ff
 *   @0x316622 .word 0xf8c5b979
 *   @0x316626 .word 0xf8c5a020
 *   @0x31662a stmdavs r3!, {r2, r3, r4, pc}
 *   @0x31662e andgt pc, r4, r4, asr #17
 *   @0x316632 smlabteq r9, r3, r11, lr
 *   @0x316636 .word 0xf8c468a3
 *   @0x31663a strmi r9, [r11], #-0
 *   @0x31663e .word 0x636e60a3
 *   @0x316642 ldmvs r10, {r4, r5, sp, lr, pc}
 *   @0x316646 stmdblo r1, {r8, r9, r10, sp}
 *   @0x31664a .word 0xf8063601
 *   @0x31664e andsvs r2, pc, r1, lsl #24
 *   @0x316652 .word 0xf1b8e62c
 *   @0x316656 stmdble r5, {r0, r1, r2, r8, r9, r10, r11}
 *   @0x31665a stmdaeq r8, {r3, r5, r7, r8, r12, sp, lr, pc}
 *   @0x31665e .word 0x0c01f10c
 *   @0x316662 ldmiblo pc!, {r0, r3, r8, r12, sp, lr, pc} ^
 *   @0x316666 strtmi r6, [r1], -lr, ror #6
 *   @0x31666a qasxmi r4, r8, r10
 *   @0x31666e .word 0xf8cd9307
 *   @0x316672 .word 0xf7fec018
 *   @0x316676 blvs 0x1d9666e <b2_toiTime+0x163d1ca>
 *   @0x31667a blls 0x4f133a <SrcVerts+0x4e37e>
 *   @0x31667e .word 0xf8dd428e
 *   @0x316682 .word 0x4602c018
 *   @0x316686 .word 0xf8c5d011
 *   @0x31668a .word 0xf8c5a020
 *   @0x31668e stmdavs r3!, {r2, r3, r4, pc}
 *   @0x316692 andgt pc, r4, r4, asr #17
 *   @0x316696 andeq lr, r9, r3, asr #23
 *   @0x31669a .word 0xf8c468a3
 *   @0x31669e strmi r9, [r3], #-0
 *   @0x3166a2 .word 0x636960a3
 *   @0x3166a6 strtmi r4, [r1], -r8, lsr #12
 *   @0x3166aa andhs lr, r8, #59
 *   @0x3166ae .word 0xf8c5601a
 *   @0x3166b2 strtmi r10, [r8], -r0, lsr #32
 *   @0x3166b6 andshi pc, r12, r5, asr #17
 *   @0x3166ba stmdavs r3!, {r0, r5, r9, r10, lr}
 *   @0x3166be andgt pc, r4, r4, asr #17
 *   @0x3166c2 andeq lr, r9, #199680
 *   @0x3166c6 .word 0xf8c468a3
 *   @0x3166ca ldrmi r9, [r3], #-0
 *   @0x3166ce adcvs r2, r3, r1, lsl #4
 *   @0x3166d2 eor r6, r6, lr, ror #6
 *   @0x3166d6 eorge pc, r0, r5, asr #17
 *   @0x3166da .word 0xf8c54628
 *   @0x3166de qadd16mi r8, r1, r12
 *   @0x3166e2 .word 0xf8c46823
 *   @0x3166e6 bl 0xff4066fe <b2_toiTime+0xfffffffffecad25a>
 *   @0x3166ea stmvs r3!, {r0, r3, r9}
 *   @0x3166ee andls pc, r0, r4, asr #17
 *   @0x3166f2 .word 0xf06f4413
 *   @0x3166f6 adcvs r0, r3, r2, lsl #4
 *   @0x3166fa ands r6, r2, lr, ror #6
 *   @0x3166fe eorge pc, r0, r5, asr #17
 *   @0x316702 .word 0xf8c54628
 *   @0x316706 qadd16mi r8, r1, r12
 *   @0x31670a .word 0xf8c46823
 *   @0x31670e bl 0xff406726 <b2_toiTime+0xfffffffffecad282>
 *   @0x316712 stmvs r3!, {r0, r3, r9}
 *   @0x316716 andls pc, r0, r4, asr #17
 *   @0x31671a .word 0xf06f4413
 *   @0x31671e adcvs r0, r3, r1, lsl #4
 *   @0x316722 .word 0xf7fe636e
 *   @0x316726 stmdahs r1, {r2, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x31672a teqle r10, r2, lsl #12
 *   @0x31672e bvs 0xfeb310c2 <b2_toiTime+0xfffffffffe3d7c1e>
 *   @0x316732 ldrmi r6, [r8, r9, ror #16]
 *   @0x316736 blvs 0x1eb13ea <b2_toiTime+0x1757f46>
 *   @0x31673a addsmi r6, lr, #96, #16
 *   @0x31673e svclt #0x3869af
 *   @0x316742 stmdaeq r3, {r1, r2, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x316746 .word 0xa000f8d4
 *   @0x31674a bvs 0xffe06402 <b2_toiTime+0xffffffffff6acf5e>
 *   @0x31674e ldmlo pc!, {r3, r8, r12, sp, lr, pc} ^
 *   @0x316752 .word 0xf8d59008
 *   @0x316756 svclt #0x28b020
 *   @0x31675a stmdaeq r3, {r1, r2, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x31675e ldrsbls pc, [r12], -r5
 *   @0x316762 eorvs r11, pc, r7, lsl r9
 *   @0x316766 blt 0x9d476a <b2_toiTime+0x27b2c6>
 *   @0x31676a movwhs r2, #0x7700
 *   @0x31676e .word 0x636e602b
 *   @0x316772 qasxmi r4, r8, r10
 *   @0x316776 .word 0xf7fe4621
 *   @0x31677a blvs 0x1e1656a <b2_toiTime+0x16bd0c6>
 *   @0x31677e addsmi r6, lr, #47104
 *   @0x316782 andsle r4, r1, r2, lsl #12
 *   @0x316786 .word 0xf8c59908
 *   @0x31678a .word 0xf8c5b020
 *   @0x31678e rsbvs r9, r1, r12, lsl r0
 *   @0x316792 .word 0xf8c46821
 *   @0x316796 bl 0xff37e79e <b2_toiTime+0xfffffffffec252fa>
 *   @0x31679a stmvs r1!, {r1, r3}
 *   @0x31679e adcvs r4, r1, r1, lsl #8
 *   @0x3167a2 strtmi r6, [r8], -r11, ror #6
 *   @0x3167a6 eors r4, r11, r1, lsr #12
 *   @0x3167aa eorvs r2, r11, r8, lsl #6
 *   @0x3167ae strtmi r9, [r8], -r8, lsl #20
 *   @0x3167b2 eorlt pc, r0, r5, asr #17
 *   @0x3167b6 .word 0xf8c54621
 *   @0x3167ba stmdavs r3!, {r2, r3, r4, r12, pc}
 *   @0x3167be bl 0xff3ee94e <b2_toiTime+0xfffffffffec954aa>
 *   @0x3167c2 stmvs r3!, {r1, r3, r9}
 *   @0x3167c6 andge pc, r0, r4, asr #17
 *   @0x3167ca andhs r4, r1, #318767104
 *   @0x3167ce .word 0x636e60a3
 *   @0x3167d2 .word 0xf8c5e026
 *   @0x3167d6 .word 0xf8c5b020
 *   @0x3167da blls 0x53a852 <obj_numb_event+0x38e2>
 *   @0x3167de stmdavs r3!, {r0, r1, r5, r6, sp, lr}
 *   @0x3167e2 .word 0xf8c44628
 *   @0x3167e6 strtmi r10, [r1], -r0
 *   @0x3167ea andeq lr, r10, #199680
 *   @0x3167ee ldrmi r6, [r3], #-2211
 *   @0x3167f2 andeq pc, r2, #111
 *   @0x3167f6 .word 0x636e60a3
 *   @0x3167fa .word 0xf8c5e012
 *   @0x3167fe strtmi r11, [r1], -r0, lsr #32
 *   @0x316802 andsls pc, r12, r5, asr #17
 *   @0x316806 stmdals r8, {r0, r1, r5, r11, sp, lr}
 *   @0x31680a andeq lr, r10, #199680
 *   @0x31680e .word 0xf8c468a3
 *   @0x316812 rsbvs r10, r0, r0
 *   @0x316816 qadd16mi r4, r8, r3
 *   @0x31681a andeq pc, r1, #111
 *   @0x31681e .word 0x636e60a3
 *   @0x316822 .word 0xff25f7fe
 *   @0x316826 strmi r1, [r7], -r3, asr #25
 *   @0x31682a stmibvs r3!, {r0, r1, r2, r8, r12, lr, pc} ^
 *   @0x31682e andsvs r2, r10, sp, lsl #4
 *   @0x316832 stmibvs r3!, {r9, sp} ^
 *   @0x316836 .word 0xf7ff605a
 *   @0x31683a stmdahs r0, {r0, r1, r2, r5, r7, r11, r12, sp, pc}
 *   @0x31683e stmdahs r1, {r0, r1, r4, r5, r6, r12, lr, pc}
 *   @0x316842 stmibvs r2!, {r0, r1, r4, r5, r6, r8, r12, lr, pc} ^
 *   @0x316846 andlo r4, r4, #34603008
 *   @0x31684a .word 0xf7fe6910
 *   @0x31684e stmibvs r3!, {r2, r3, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x316852 ldrsblt r6, [r2, -r10]
 *   @0x316856 andsvs r2, r10, r12, lsl #4
 *   @0x31685a svcls #0x9e05a
 *   @0x31685e andsvs r2, r10, r8, lsl #4
 *   @0x316862 blhs 0x3309f6
 *   @0x316866 bllo 0x38a9f2 <bigtens_D2A+0xec2>
 *   @0x31686a stmvs r3!, {r0, r1, r5, r6, sp, lr}
 *   @0x31686e movwlo r6, #0x19e2
 *   @0x316872 stmdavs r3!, {r0, r1, r5, r7, sp, lr}
 *   @0x316876 mrrcne p15, #0x0, r9, r9, c9
 *   @0x31687a ldmdavc r11, {r0, r5, sp, lr}
 *   @0x31687e addsvs r0, r3, r11, lsl r6
 *   @0x316882 andhs r6, r9, #3719168
 *   @0x316886 stmdavs r3!, {r1, r3, r4, sp, lr} ^
 *   @0x31688a suble r2, lr, r0, lsl #22
 *   @0x31688e rsbvs r3, r3, r1, lsl #22
 *   @0x316892 stmdavs r2!, {r0, r1, r5, r7, r11, sp, lr}
 *   @0x316896 adcvs r3, r3, r1, lsl #6
 *   @0x31689a mrrcne p9, #0xe, r6, r0, c3
 *   @0x31689e ldmvs r9, {r0, r3, r8, r9, r10, r11, r12, pc}
 *   @0x3168a2 ldmdavc r2, {r5, sp, lr}
 *   @0x3168a6 andmi lr, r2, #1024
 *   @0x3168aa stmibvs r3!, {r1, r3, r4, r7, sp, lr} ^
 *   @0x3168ae andsvs r2, r10, r10, lsl #4
 *   @0x3168b2 blhs 0x330a46
 *   @0x3168b6 bllo 0x38a9a2 <bigtens_D2A+0xe72>
 *   @0x3168ba stmvs r3!, {r0, r1, r5, r6, sp, lr}
 *   @0x3168be movwlo r6, #0x1822
 *   @0x3168c2 stmibvs r3!, {r0, r1, r5, r7, sp, lr} ^
 *   @0x3168c6 svcls #0x91c50
 *   @0x3168ca mlavs r0, r9, r8, r6
 *   @0x3168ce bl 0x37491e <_ZTS13C_UTF16String+0xb9ca>
 *   @0x3168d2 addsvs r2, r10, r2, lsl #4
 *   @0x3168d6 andhs r6, r11, #3719168
 *   @0x3168da stmdavs r3!, {r1, r3, r4, sp, lr} ^
 *   @0x3168de bllo 0x383592 <_ZTS13C_UTF16String+0x1a63e>
 *   @0x3168e2 stmvs r3!, {r0, r1, r5, r6, sp, lr}
 *   @0x3168e6 movwlo r6, #0x1822
 *   @0x3168ea stmibvs r3!, {r0, r1, r5, r7, sp, lr} ^
 *   @0x3168ee ldmvs r9, {r4, r6, r10, r11, r12}
 *   @0x3168f2 ldmdavc r2, {r5, sp, lr}
 *   @0x3168f6 addsvs r4, r10, r10, lsl #8
 *   @0x3168fa ldmdavs r9, {r0, r1, r5, r6, r7, r8, r11, sp, lr} ^
 *   @0x3168fe addsmi r6, r1, #10092544
 *   @0x316902 ldmdbls r1, {r0, r3, r12, lr, pc}
 *   @0x316906 andsvs r2, r10, sp, lsl #4
 *   @0x31690a stmibvs r3!, {r0, r5, r7, r8, sp, lr} ^
 *   @0x31690e subsvs r2, r10, r5, lsl #4
 *   @0x316912 .word 0xf7ff9f09
 *   @0x316916 andhs r11, r12, #3735552
 *   @0x31691a and r6, r2, r10, lsl r0
 *   @0x31691e andeq pc, r1, pc, rrx
 *   @0x316922 andhs lr, r1, r9, lsl r0
 *   @0x316926 stmdals r9, {r0, r1, r2, r4, sp, lr, pc}
 *   @0x31692a shadd16mi lr, r8, r5
 *   @0x31692e bls 0x54e982 <gp_ActiveMaskObjects+0x9cba>
 *   @0x316932 .word 0xf8c54628
 *   @0x316936 strtmi r11, [r1], -r0, lsr #32
 *   @0x31693a andsls pc, r12, r5, asr #17
 *   @0x31693e rsbvs r6, r2, r3, lsr #16
 *   @0x316942 andeq lr, r10, #199680
 *   @0x316946 .word 0xf8c468a3
 *   @0x31694a ldrmi r10, [r3], #-0
 *   @0x31694e andeq pc, r3, #111
 *   @0x316952 .word 0x636e60a3
 *   @0x316956 andslt lr, r11, r4, ror #14
 *   @0x31695a svchi #0xf0e8bd
 *   @0x31695e push {r8, r9, r10, r11, r12, sp, pc}
 *   @0x316962 .word 0xf50043f8
 *   @0x316966 .word 0xf1005501
 *   @0x31696a .word 0xf100090c
 *   @0x31696e .word 0xf5000848
 *   @0x316972 strmi r5, [r4], -r2, lsl #7
 *   @0x316976 rscvs r3, r11, r8, lsl #6
 *   @0x31697a vst4.32 {d22, d24, d26, d28}, [pc], r3
 *   @0x31697e bicvs r5, r3, r0, lsl #7
 *   @0x316982 blhs 0x331116
 *   @0x316986 stmdbvs r3!, {r1, r2, r3, r5, r12, lr, pc}
 *   @0x31698a stmdavs r6!, {r0, r1, r3, r8, r9, r11, r12, sp, pc}
 *   @0x31698e .word 0xb1476977
 *   @0x316992 ldmvs r1!, {r4, r5, r9, r10, lr}
 *   @0x316996 vst1.16 {d20, d21, d22}, [pc], r2
 *   @0x31699a ldrmi r5, [r8, r0, lsl #7]!
 *   @0x31699e teqlt r0, #7340032
 *   @0x3169a2 ldmvs r3!, {r0, r1, r2, r3, sp, lr, pc}
 *   @0x3169a6 bne 0x2f0b8a <FT_Done_Memory+0x6f16>
 *   @0x3169aa svcpl #0x80f5b7
 *   @0x3169ae mvnslt sp, r1, lsl #16
 *   @0x3169b2 vst4.8 {d30, d31, d0, d1}, [pc], r1
 *   @0x3169b6 ldmdavs r1!, {r7, r8, r9, r10, r12, lr}
 *   @0x3169ba ldrtmi r4, [r10], -r0, asr #12
 *   @0x3169be .word 0xf59f4419
 *   @0x3169c2 ldmvs r3!, {r2, r3, r4, r5, r6, r7, r8, r10, r11, sp, lr, pc}
 *   @0x3169c6 adcsvs r4, r3, r11, lsr r4
 *   @0x3169ca andhi pc, r12, r4, asr #17
 *   @0x3169ce strbmi r6, [r8], -r7, lsr #2
 *   @0x3169d2 .word 0xf7fe2100
 *   @0x3169d6 stmdahs r1, {r1, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3169da stmibvs r3!, {r0, r1, r2, r8, r12, lr, pc}
 *   @0x3169de addsmi r6, r3, #15335424
 *   @0x3169e2 andle r6, r6, r11, lsr #2
 *   @0x3169e6 ldm sp!, {sp}
 *   @0x3169ea stmdahs r0, {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x3169ee stmvs r11!, {r3, r6, r7, r12, lr, pc} ^
 *   @0x3169f2 subshs r6, r5, r11, lsr #2
 *   @0x3169f6 .word 0x83f8e8bd
 *   @0x3169fa ldrbmi lr, [r0, sp, lsr #18]!
 *   @0x3169fe strpl pc, [r1], #-1280
 *   @0x316a02 .word 0x46054698
 *   @0x316a06 strmi r6, [r9], r3, lsr #17
 *   @0x316a0a .word 0xf1044692
 *   @0x316a0e addsmi r0, r9, #8, #14
 *   @0x316a12 stmdavs r0, {r3, r4, r9, r12, lr, pc}
 *   @0x316a16 .word 0xf7cf6c69
 *   @0x316a1a strmi pc, [r6], -r5, asr #30
 *   @0x316a1e .word 0xf04fb110
 *   @0x316a22 sub r0, r6, r0, lsl #18
 *   @0x316a26 andeq pc, r12, r5, lsl #2
 *   @0x316a2a mcr2 p7, #0x7, pc, c6, c14, #0x7
 *   @0x316a2e movteq pc, #0x8105
 *   @0x316a32 .word 0xf50560eb
 *   @0x316a36 smlawbvs lr, r2, r3, r5
 *   @0x316a3a mvnvs r3, r8, lsl #6
 *   @0x316a3e smulwbvs r7, r11, r1
 *   @0x316a42 adcvs r6, r6, r7, ror #1
 *   @0x316a46 ldrmi r6, [r1, #0x8a6]!
 *   @0x316a4a bl 0xff4ccea2 <b2_toiTime+0xfffffffffed739fe>
 *   @0x316a4e stmvs r2!, {r0, r3, r9, r10} ^
 *   @0x316a52 bne 0xfe9f0ee6 <b2_toiTime+0xfffffffffe297a42>
 *   @0x316a56 svclt #0x38429e
 *   @0x316a5a ldrmi r4, [r10], #-1587
 *   @0x316a5e ldmdavs r10!, {r1, r5, r6, r7, sp, lr}
 *   @0x316a62 ldrmi r1, [r10], #-2806
 *   @0x316a66 andle r6, r5, r10, lsr r0
 *   @0x316a6a .word 0xf7ff4628
 *   @0x316a6e stmdahs r0, {r3, r4, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x316a72 ldrb sp, [r4, sp, ror #1]
 *   @0x316a76 svceq #0xf1b8
 *   @0x316a7a .word 0xf04fd0d1
 *   @0x316a7e stmvs r1!, {r8, r11} ^
 *   @0x316a82 stmdbvs r6!, {r4, r6, r9, r10, lr}
 *   @0x316a86 ldrmi r1, [r0, #0xa76]!
 *   @0x316a8a .word 0x4646bf38
 *   @0x316a8e ldrtmi r4, [r1], #1202
 *   @0x316a92 .word 0xf59f4632
 *   @0x316a96 stmvs r3!, {r1, r4, r7, r8, r10, r11, sp, lr, pc} ^
 *   @0x316a9a stmdaeq r6, {r3, r4, r5, r7, r8, r9, r11, sp, lr, pc}
 *   @0x316a9e rscvs r4, r3, r3, lsr r4
 *   @0x316aa2 ldrtmi r6, [r3], #-2107
 *   @0x316aa6 andle r6, r4, r11, lsr r0
 *   @0x316aaa .word 0xf7ff4628
 *   @0x316aae stmdahs r0, {r3, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x316ab2 strbmi sp, [r8], -r5, ror #1
 *   @0x316ab6 .word 0x87f0e8bd
 *   @0x316aba .word 0xf7ff68c0
 *
 * ══ §3/8 anon_300814  0x300814  size 6224  1556 条（0x300814..0x302064）
 * @func 0x300814 0x302064  size 6224  1556 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xd0c958 / 0x391484 / 0xfe6fe8d0 / 0xfe860d94 / 0xff4d90 / 0x122f12c / 0x44cf18 / 0x4c4600
 * 字段偏移 top8: 0x8×2 / 0x14×2 / 0x-e×1 / 0xa×1 / 0x6×1 / 0x2×1 / 0xc×1 / 0x10×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x300814 bichi pc, r12, r0, asr #32
 *   @0x300818 rscsle r2, r6, r0, lsl #22
 *   @0x30081c bic r4, r8, r8, lsl r6
 *   @0x300820 .word 0x3040f8d8
 *   @0x300824 .word 0xd10d2b28
 *   @0x300828 svchs #0xe0f416
 *   @0x30082c movweq pc, #0x4f
 *   @0x300830 .word 0xf04fbf14
 *   @0x300834 .word 0xf04f0a00
 *   @0x300838 .word 0xf8870a01
 *   @0x30083c .word 0xf04f3266
 *   @0x300840 and r0, r4, r1, lsl #22
 *   @0x300844 beq 0x33c988
 *   @0x300848 rsbge pc, r6, #8847360
 *   @0x30084c .word 0xf8d846d3
 *   @0x300850 blhs 0xd0c958 <b2_toiTime+0x5b34b4>
 *   @0x300854 .word 0xf1bbd10b
 *   @0x300858 .word 0xd1050f00
 *   @0x30085c movwmi pc, #0x33c6
 *   @0x300860 svclt #0x183b02
 *   @0x300864 and r2, r0, r1, lsl #6
 *   @0x300868 sbcslt r2, r11, #0, #6
 *   @0x30086c vaddl.u8 q15, d6, d4
 *   @0x300870 bllo 0x391484 <ft_adobe_glyph_list+0xb60>
 *   @0x300874 movwhs r11, #0x1f18
 *   @0x300878 .word 0x46494638
 *   @0x30087c movwls r4, #0x562a
 *   @0x300880 ldc2l p7, c15, [r12, #-996]!
 *   @0x300884 stmdahs r0, {r0, r2, r8, r9, r11, r12, pc}
 *   @0x300888 orrshi pc, r3, r0, asr #32
 *   @0x30088c .word 0x2040f8d8
 *   @0x300890 .word 0xd10d2a28
 *   @0x300894 rsbhs pc, r5, #9895936
 *   @0x300898 .word 0xf897455a
 *   @0x30089c svclt #0x1c226a
 *   @0x3008a0 rsblt pc, r5, #8847360
 *   @0x3008a4 ldrbmi r2, [r2, #-0x1]
 *   @0x3008a8 .word 0xf887bf1c
 *   @0x3008ac andhs r10, r1, r10, ror #4
 *   @0x3008b0 rsbhs pc, r4, #9895936
 *   @0x3008b4 mulle r2, r10, r2
 *   @0x3008b8 rsblo pc, r4, #8847360
 *   @0x3008bc ldmdblt r0!, {r0, r1, r2, sp, lr, pc}
 *   @0x3008c0 .word 0x3154f897
 *   @0x3008c4 ldrle r0, [sp, #-0x7d8]
 *   @0x3008c8 streq pc, [r2], -r6, asr #32
 *   @0x3008cc .word 0xf04fe01a
 *   @0x3008d0 .word 0xf8d50a00
 *   @0x3008d4 ldrmi r3, [r10, #0xf8]
 *   @0x3008d8 .word 0xf8d9d20d
 *   @0x3008dc stclvs p2, c3, [r9, #608]!
 *   @0x3008e0 ldrsbthi pc, [r12], #133
 *   @0x3008e4 andseq pc, r10, r3, lsr r9
 *   @0x3008e8 blx 0xfe6fe8d0 <b2_toiTime+0xfffffffffdfa542c>
 *   @0x3008ec eoreq pc, r10, r8, asr #16
 *   @0x3008f0 beq 0x37cd20 <_ZTS13C_UTF16String+0x13dcc>
 *   @0x3008f4 strtmi lr, [r8], -sp, ror #15
 *   @0x3008f8 .word 0xf7fe9909
 *   @0x3008fc stmdahs r0, {r0, r1, r2, r3, r6, r8, r9, r11, r12, sp, lr, pc}
 *   @0x300900 ldrsb sp, [r6, #-14]
 *   @0x300904 strle r0, [r7, #-0x799]
 *   @0x300908 .word 0xf50749af
 *   @0x30090c subhs r7, r4, #144
 *   @0x300910 stmdavs r9, {r0, r3, r4, r5, r6, r10, lr}
 *   @0x300914 mrc p5, #0x2, apsr_nzcv, c2, c5, #0x5
 *   @0x300918 cmneq pc, #38
 *   @0x30091c eorslo pc, r5, #8847360
 *   @0x300920 .word 0xf8d7973c
 *   @0x300924 teqls sp, #140, #2
 *   @0x300928 ldrsblo pc, [r12], r4
 *   @0x30092c shadd16mi r6, r8, pc
 *   @0x300930 stc2l p7, c15, [r4], {228}
 *   @0x300934 andhs r9, r0, #11264
 *   @0x300938 .word 0xf8c4a815
 *   @0x30093c tstls r11, #128
 *   @0x300940 .word 0x67e24b9d
 *   @0x300944 strtvs r9, [r3], #2310
 *   @0x300948 .word 0x97184613
 *   @0x30094c .word 0xf8cd9619
 *   @0x300950 ldrls r9, [r6, #-0x54]
 *   @0x300954 subls r9, r8, #385875968
 *   @0x300958 .word 0xf7fe9249
 *   @0x30095c strmi pc, [r0], pc, lsl #29
 *   @0x300960 .word 0xf0402800
 *   @0x300964 blmi 0xfe860d94 <b2_toiTime+0xfffffffffe1078f0>
 *   @0x300968 cdpls p12, #0x1, c6, c8, c2, #0x5
 *   @0x30096c .word 0x469b429a
 *   @0x300970 blvs 0xff4d90 <b2_toiTime+0x89b8ec>
 *   @0x300974 addlo pc, r0, r4, asr #17
 *   @0x300978 .word 0xf8c46b73
 *   @0x30097c ands r3, r0, r4, lsl #1
 *   @0x300980 .word 0xf1043614
 *   @0x300984 cdpgt p7, #0x0, c0, c15, c12, #0x3
 *   @0x300988 .word 0xf104c70f
 *   @0x30098c ldmdavs r3!, {r2, r3, r5, r6}
 *   @0x300990 vld2.8 {d9, d11}, [r3:128], r6
 *   @0x300994 strbvs r7, [r3, r0, lsl #6]!
 *   @0x300998 submi r11, r9, #1073741830
 *   @0x30099c .word 0xf7e54642
 *   @0x3009a0 stmdals r7, {r0, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0x3009a4 blls 0x122f12c <b2_toiTime+0xad5c88>
 *   @0x3009a8 .word 0x2155f893
 *   @0x3009ac .word 0xf8d3b1a2
 *   @0x3009b0 blhs 0x44cf18 <g_RomDisk+0x556f8>
 *   @0x3009b4 ldm pc, {r4, r11, r12, lr, pc} ^
 *   @0x3009b8 movwne pc, #0x3003
 *   @0x3009bc bleq 0x4c4600 <SrcVerts+0x21644>
 *   @0x3009c0 .word 0xf0436fe3
 *   @0x3009c4 and r0, r10, r0, lsr #6
 *   @0x3009c8 .word 0xf0436fe3
 *   @0x3009cc and r0, r6, r0, lsr r3
 *   @0x3009d0 .word 0xf0436fe3
 *   @0x3009d4 and r0, r2, r0, lsl r3
 *   @0x3009d8 .word 0xf0436fe3
 *   @0x3009dc strbvs r0, [r3, r8, lsl #6]!
 *   @0x3009e0 .word 0xf10d9f15
 *   @0x3009e4 .word 0xf8dd0e34
 *   @0x3009e8 mrcls p0, #0x0, r10, c7, c8, #0x2
 *   @0x3009ec movwls r6, #0x7e3b
 *   @0x3009f0 bfieq r9, r9, #22, #5
 *   @0x3009f4 .word 0xf8dabf56
 *   @0x3009f8 vst4.8 {d19, d20, d21, d22}, [pc:128], r12
 *   @0x3009fc .word 0xf8d33980
 *   @0x300a00 ldcvs p0, c9, [r3], #32
 *   @0x300a04 andle r4, r5, r11, asr r5
 *   @0x300a08 rsbeq pc, r12, r6, lsl #2
 *   @0x300a0c .word 0xf7e54671
 *   @0x300a10 .word 0xe003fcdd
 *   @0x300a14 blgt 0x6eb694 <g_SWFvertbuff+0x185cc>
 *   @0x300a18 andeq lr, pc, lr, lsl #17
 *   @0x300a1c stmdbls sp, {r2, r5, r8, r9, r11, r12, pc}
 *   @0x300a20 .word 0x63b39a10
 *   @0x300a24 rsbsvs r6, r2, #268435459
 *   @0x300a28 blls 0xca6ad0 <b2_toiTime+0x54d62c>
 *   @0x300a2c stmdals r7, {r0, r1, r6, r7, r9, r11, r12}
 *   @0x300a30 .word 0x6c0362b3
 *   @0x300a34 .word 0xd1042b28
 *   @0x300a38 tstlt r3, r12, lsr r11
 *   @0x300a3c rsblo pc, r7, #9633792
 *   @0x300a40 .word 0xf8d7bb5b
 *   @0x300a44 bllt 0x13cd1ec <b2_toiTime+0xc73d48>
 *   @0x300a48 ldmdals r9, {r0, r2, r3, r4, r6, r8, r9, r11, lr}
 *   @0x300a4c bllt 0xbd0a60 <b2_toiTime+0x4775bc>
 *   @0x300a50 .word 0x002cf8da
 *   @0x300a54 rsc pc, r8, #14090240
 *   @0x300a58 sbcslt pc, r12, #14090240
 *   @0x300a5c strhge pc, [r0], -r0
 *   @0x300a60 rscgt pc, r4, #14090240
 *   @0x300a64 andsle r4, r8, r3, ror #10
 *   @0x300a68 rsceq pc, r12, #14090240
 *   @0x300a6c ldrbmi r5, [r0, #-0xcc0]
 *   @0x300a70 .word 0xf8ddd111
 *   @0x300a74 .word 0xf10cc018
 *   @0x300a78 ldrbmi r0, [r0, #-0x2]!
 *   @0x300a7c blx 0x6b52ba <g_SWFlinevertbuff+0x621f2>
 *   @0x300a80 .word 0xf10b0303
 *   @0x300a84 bl 0x5c36ac <g_SWFlineaavertbuff+0x705e4>
 *   @0x300a88 teqlt r0, r3
 *   @0x300a8c andlo pc, r3, r11, lsl r8
 *   @0x300a90 adcsvs r0, r3, #-1073741786
 *   @0x300a94 movwlo lr, #0x1001
 *   @0x300a98 blls 0x6faa30 <g_SWFvertbuff+0x27968>
 *   @0x300a9c bne 0x1966adc <b2_toiTime+0x120d638>
 *   @0x300aa0 bne 0x71916c <g_SWFvertbuff+0x460a4>
 *   @0x300aa4 .word 0xf89761f0
 *   @0x300aa8 .word 0xb1a33124
 *   @0x300aac strhlo pc, [r10, #-135]
 *   @0x300ab0 stmdals r3, {r0, r1, r3, r7, r8, r12, sp, pc} ^
 *   @0x300ab4 bne 0xfe3123e0 <b2_toiTime+0xfffffffffdbb8f3c>
 *   @0x300ab8 .word 0xf9fdf7e4
 *   @0x300abc blx 0x6e77d8 <g_SWFvertbuff+0x14710>
 *   @0x300ac0 stmdals r3, {r7, r8, r9, r11, r12, sp, lr, pc} ^
 *   @0x300ac4 stcle p2, c4, [r1, #-608]!
 *   @0x300ac8 strbmi r1, [r9], -r0, asr #21
 *   @0x300acc .word 0xf9f3f7e4
 *   @0x300ad0 blx 0xfe33f354 <b2_toiTime+0xfffffffffdbe5eb0>
 *   @0x300ad4 .word 0x4649e01c
 *   @0x300ad8 .word 0xf9edf7e4
 *   @0x300adc ldrhhs pc, [r4, #-135]!
 *   @0x300ae0 .word 0x73fff64f
 *   @0x300ae4 svclt #0x19429a
 *   @0x300ae8 ldrhge pc, [r10, r7]!
 *   @0x300aec ldrhlo pc, [r12, r7]!
 *   @0x300af0 ldrhge pc, [r12], #151
 *   @0x300af4 ldrhlo pc, [lr], #151
 *   @0x300af8 beq 0x5bba0c <g_SWFlineaavertbuff+0x68944>
 *   @0x300afc bl 0xff32d304 <b2_toiTime+0xfffffffffebd3e60>
 *   @0x300b00 bl 0x5c3730 <g_SWFlineaavertbuff+0x70668>
 *   @0x300b04 b 0x16dfa78 <b2_toiTime+0xf865d4>
 *   @0x300b08 and r0, r1, r11, ror #22
 *   @0x300b0c beq 0x33cc50
 *   @0x300b10 .word 0x3080f8d7
 *   @0x300b14 .word 0xb1b36b5b
 *   @0x300b18 ldmvs r2, {r1, r3, r4, r11, sp, lr}
 *   @0x300b1c .word 0xf8cdb19a
 *   @0x300b20 andhs r10, r0, #76
 *   @0x300b24 sublt pc, r8, sp, asr #17
 *   @0x300b28 ldmdavs r10, {r0, r4, r9, r12, pc}
 *   @0x300b2c blge 0x75ac94 <b2_toiTime+0x17f0>
 *   @0x300b30 ldmvs r7, {r1, r2, r8, r11, r12, pc}
 *   @0x300b34 ldrmi r2, [r8, r1, lsl #4]!
 *   @0x300b38 strmi r11, [r0], r8, lsl #2
 *   @0x300b3c .word 0xf8dde01d
 *   @0x300b40 .word 0xf8ddb048
 *   @0x300b44 .word 0xf8c6a04c
 *   @0x300b48 blls 0x968c40 <b2_toiTime+0x20f79c>
 *   @0x300b4c strle r0, [r9], #-2011
 *   @0x300b50 .word 0x46494658
 *   @0x300b54 .word 0xf959f7f8
 *   @0x300b58 strmi r4, [r3], r9, asr #12
 *   @0x300b5c .word 0xf7f84650
 *   @0x300b60 pkhtbmi pc, r2, r4, asr #18
 *   @0x300b64 bvs 0xf9b638 <b2_toiTime+0x842194>
 *   @0x300b68 eorslt pc, r0, r6, asr #17
 *   @0x300b6c bicsvc lr, r3, #3072
 *   @0x300b70 eorsge pc, r4, r6, asr #17
 *   @0x300b74 rsbeq lr, r3, #165888
 *   @0x300b78 blls 0x859748 <b2_toiTime+0x1002a4>
 *   @0x300b7c stmdage r8, {r8, sp} ^
 *   @0x300b80 .word 0x460b6e5a
 *   @0x300b84 .word 0xffcef7e7
 *   @0x300b88 ldmdblt r10!, {r1, r3, r9, r11, r12, pc}
 *   @0x300b8c ldmdahi r11, {r0, r1, r3, r5, r6, r7, r9, r11, sp, lr} ^
 *   @0x300b90 stmdale r3, {r0, r1, r2, r4, r8, r9, r11, sp}
 *   @0x300b94 .word 0xf4436fe3
 *   @0x300b98 strbvs r7, [r3, r0, lsl #7]!
 *   @0x300b9c and r4, r8, r0, asr #12
 *   @0x300ba0 and r2, r6, r4, lsr #32
 *   @0x300ba4 and r2, r4, r3, lsr #32
 *   @0x300ba8 and r2, r2, r6
 *   @0x300bac mul r0, r9, r0
 *   @0x300bb0 sublt r4, r11, r0, lsl r6
 *   @0x300bb4 svchi #0xf0e8bd
 *   @0x300bb8 svcvs #0x75746c
 *   @0x300bbc .word 0x636f6d70
 *   @0x300bc0 eoreq r0, r0, r2
 *   @0x300bc4 rsbvs r7, r9, #1929379840
 *   @0x300bc8 andeq r1, pc, r12, asr #5
 *   @0x300bcc muleq r12, r0, r8
 *   @0x300bd0 andmi lr, r2, #274432
 *   @0x300bd4 muleq r9, r1, r8
 *   @0x300bd8 movwmi lr, #0xa43
 *   @0x300bdc stmdale r4, {r1, r3, r4, r7, r9, lr}
 *   @0x300be0 andhs r11, r0, r12, lsr #30
 *   @0x300be4 andeq pc, r0, pc, rrx
 *   @0x300be8 andhs r4, r1, r0, ror r7
 *   @0x300bec .word 0xf8d04770
 *   @0x300bf0 ldrbmi r0, [r0, -r12, ror #2]!
 *   @0x300bf4 .word 0xf100b530
 *   @0x300bf8 strmi r0, [r12], -r4, lsl #11
 *   @0x300bfc strgt r12, [pc], #-3343
 *   @0x300c00 muleq pc, r5, r8
 *   @0x300c04 andeq lr, pc, r4, lsl #17
 *   @0x300c08 ldclt p0, c2, [r0, #-0]!
 *   @0x300c0c .word 0x30a4f8b0
 *   @0x300c10 andhi r2, r11, r0
 *   @0x300c14 andhs r4, r1, r0, ror r7
 *   @0x300c18 strlt r4, [r8, #-0x770]
 *   @0x300c1c .word 0x03a8f100
 *   @0x300c20 strmi r2, [r8], -r4, asr #5
 *   @0x300c24 .word 0xf5b54619
 *   @0x300c28 andhs lr, r0, r10, asr #25
 *   @0x300c2c ldrblt r11, [r0, #-0xd08]!
 *   @0x300c30 andsvs r2, r12, r0, lsl #8
 *   @0x300c34 .word 0xf8d0605c
 *   @0x300c38 tstlt r4, #240, #2
 *   @0x300c3c b 0x139b6d8 <b2_toiTime+0xc42234>
 *   @0x300c40 bvs 0x1b1104c <b2_toiTime+0x13b7ba8>
 *   @0x300c44 strpl pc, [r0, #0x105]
 *   @0x300c48 bl 0x310054 <af_shaper_get_elem+0x58c2>
 *   @0x300c4c adcmi r1, r8, #20971520
 *   @0x300c50 bne 0xeb6cb4 <b2_toiTime+0x75d810>
 *   @0x300c54 bl 0x485134 <mstack+0x448>
 *   @0x300c58 ldrsbtne r7, [r6], #-102
 *   @0x300c5c stmibne r4, {r1, r2, r4, r5, r8}
 *   @0x300c60 stmdavs r6!, {r1, r7, r8, r11, r12, lr} ^
 *   @0x300c64 strmi lr, [r2], -r6, asr #20
 *   @0x300c68 smlabble r4, lr, r2, r4
 *   @0x300c6c andsvs r6, r10, r2, lsr #17
 *   @0x300c70 subsvs r6, r10, r2, ror #17
 *   @0x300c74 svclt #0x34e005
 *   @0x300c78 andseq pc, r0, r4, lsl #2
 *   @0x300c7c ldreq pc, [r0, #-0x1a4]
 *   @0x300c80 andhs lr, r0, r5, ror #15
 *   @0x300c84 blx 0xfe37024e <b2_toiTime+0xfffffffffdc16daa>
 *   @0x300c88 b 0x16cd490 <b2_toiTime+0xf73fec>
 *   @0x300c8c .word 0xf50070e2
 *   @0x300c90 ldmdane r11, {lr}
 *   @0x300c94 andeq pc, r0, #-2147483632
 *   @0x300c98 andsmi lr, r3, pc, asr #20
 *   @0x300c9c andmi lr, r2, r0, asr #20
 *   @0x300ca0 ldrlt r4, [r0, #-0x770]!
 *   @0x300ca4 andslo pc, r4, #208, #16
 *   @0x300ca8 ldmdavs r10, {r0, r1, r3, r4, r5, r6, r7, r8, r12, sp, pc} ^
 *   @0x300cac andvs r2, r10, r0
 *   @0x300cb0 subvs r6, r10, r10, lsl r8
 *   @0x300cb4 ldmdavs r12, {r1, r3, r4, r9, r10, lr} ^
 *   @0x300cb8 andlo r3, r12, #12, #2
 *   @0x300cbc andsle r4, r2, #160, #4
 *   @0x300cc0 streq lr, [r0], #2819
 *   @0x300cc4 stmvs r4!, {r0, r12, sp}
 *   @0x300cc8 .word 0x4c04f841
 *   @0x300ccc stmdavs r4!, {r2, r4, r8, r10, r11, sp, lr}
 *   @0x300cd0 .word 0xf892600c
 *   @0x300cd4 ldcvs p0, c4, [r5, #-304]
 *   @0x300cd8 strmi pc, [r0], #260
 *   @0x300cdc .word 0xf8553c01
 *   @0x300ce0 subvs r4, r12, r4, lsr #32
 *   @0x300ce4 andhs lr, r0, r7, ror #15
 *   @0x300ce8 andhs r11, r6, r0, lsr sp
 *   @0x300cec push {r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x300cf0 ssub8mi r4, r7, r8
 *   @0x300cf4 andsvs pc, r4, #208, #16
 *   @0x300cf8 ldmdavs r3!, {r1, r2, r7, r8, r9, r12, sp, pc} ^
 *   @0x300cfc .word 0xf04f2500
 *   @0x300d00 addsmi r0, r9, #16384
 *   @0x300d04 .word 0x4688bf34
 *   @0x300d08 ldmdavs r3!, {r3, r4, r7, r9, r10, lr}
 *   @0x300d0c eorle r4, r8, #-805306359
 *   @0x300d10 addlo pc, r0, pc, asr #8
 *   @0x300d14 ldmdavs r3!, {r10, sp} ^
 *   @0x300d18 andsle r4, r9, #156, #4
 *   @0x300d1c andle r4, r9, #68, #10
 *   @0x300d20 eorne pc, r4, r7, asr r8
 *   @0x300d24 blle 0x50b12c <SrcVerts+0x68170>
 *   @0x300d28 svclo #0x80f5b1
 *   @0x300d2c .word 0xf44fbfa8
 *   @0x300d30 and r3, r3, r0, lsl #3
 *   @0x300d34 .word 0x4100f44f
 *   @0x300d38 .word 0x2100e000
 *   @0x300d3c vpmax.u8 d15, d4, d9
 *   @0x300d40 eormi r3, r11, #16777216
 *   @0x300d44 .word 0xf5c1bf08
 *   @0x300d48 .word 0xf7ff3180
 *   @0x300d4c .word 0xe7e2ff9c
 *   @0x300d50 .word 0x3088f8d6
 *   @0x300d54 eoreq pc, r5, r3, asr #16
 *   @0x300d58 ldrb r3, [r6, r1, lsl #10]
 *   @0x300d5c pop {r1, r2, sp}
 *   @0x300d60 strdhs r8, r9, [r0], -r8
 *   @0x300d64 .word 0x83f8e8bd
 *   @0x300d68 .word 0x4604b538
 *   @0x300d6c strmi r6, [r8], -sp, asr #22
 *   @0x300d70 strmi r2, [r10], -r0, lsl #2
 *   @0x300d74 strmi r4, [r8, r11, lsl #12]!
 *   @0x300d78 eoreq pc, r0, #196, #16
 *   @0x300d7c .word 0xf8d1bd38
 *   @0x300d80 .word 0xf0433178
 *   @0x300d84 .word 0xf8c10301
 *   @0x300d88 .word 0x47703178
 *   @0x300d8c .word 0x43f8e92d
 *   @0x300d90 ldrmi r4, [lr], -r4, lsl #12
 *   @0x300d94 stmvs r7, {r0, r1, r6, r7, r8, r11, sp, lr}
 *   @0x300d98 ldrmi r4, [r1], r8, lsl #13
 *   @0x300d9c stmdavs r3!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x300da0 eorle r4, r1, #-1342177269
 *   @0x300da4 bllo 0xf1ee18 <b2_toiTime+0x7c5974>
 *   @0x300da8 ldmdale sp, {r0, r3, r8, r9, r11, sp}
 *   @0x300dac strtmi r6, [r0], -r3, ror #20
 *   @0x300db0 bvs 0xbd2c18 <b2_toiTime+0x479774>
 *   @0x300db4 strtmi r4, [r0], -r5, lsl #12
 *   @0x300db8 stmdavs r3!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x300dbc .word 0xf1032d00
 *   @0x300dc0 .word 0xf8c90301
 *   @0x300dc4 blle 0x6ccdcc <g_SWFlinevertbuff+0x79d04>
 *   @0x300dc8 adcsmi r1, sp, #1044480
 *   @0x300dcc stmdavs r3!, {r2, r3, r9, r11, r12, lr, pc}
 *   @0x300dd0 ldrmi r1, [r3], #-3178
 *   @0x300dd4 .word 0xf8c86023
 *   @0x300dd8 stmvs r0!, {r12, lr} ^
 *   @0x300ddc .word 0x0001f1d0
 *   @0x300de0 andhs r11, r0, r8, lsr pc
 *   @0x300de4 .word 0x83f8e8bd
 *   @0x300de8 movwhs r11, #0x3926
 *   @0x300dec rscvs r4, r3, r0, lsr r6
 *   @0x300df0 .word 0x83f8e8bd
 *   @0x300df4 ldm sp!, {sp}
 *   @0x300df8 .word 0xf8d083f8
 *   @0x300dfc andhs r3, r0, #156
 *   @0x300e00 .word 0x4770625a
 *   @0x300e04 ldrbmi r2, [r0, -r0]!
 *   @0x300e08 andeq r4, r0, r0, ror r7
 *   @0x300e0c .word 0x4604b538
 *   @0x300e10 .word 0xf8d36843
 *   @0x300e14 cmplt sp, r8, lsr #4
 *   @0x300e18 stmdbmi r6, {r0, r1, r3, r4, r9, r10, r11, sp, lr}
 *   @0x300e1c ldrbtmi r6, [r9], #-2136
 *   @0x300e20 .word 0xf866f7e5
 *   @0x300e24 stmdavs r11!, {r5, r8, r12, sp, pc} ^
 *   @0x300e28 .word 0xf8d44798
 *   @0x300e2c subsvs r3, r8, #156
 *   @0x300e30 ldclt p0, c2, [r8, #-0]!
 *   @0x300e34 andeq sp, r8, r8, ror sp
 *   @0x300e38 mvnsmi lr, sp, lsr #18
 *   @0x300e3c stmdavs r6, {r2, r9, r10, lr} ^
 *   @0x300e40 cdppl p2, #0x6, c15, c4, c0, #0x0
 *   @0x300e44 ldrmi r4, [r7], -r8, lsl #13
 *   @0x300e48 .word 0x3080f8d6
 *   @0x300e4c .word 0xf5066b5d
 *   @0x300e50 blgt 0x6dddc8 <g_SWFvertbuff+0xad00>
 *   @0x300e54 andeq lr, pc, lr, lsl #17
 *   @0x300e58 rscvc pc, r4, #25165824
 *   @0x300e5c cmnpl r4, #4, #4
 *   @0x300e60 muleq r3, r2, r8
 *   @0x300e64 andeq lr, r3, r3, lsl #17
 *   @0x300e68 stmdavs r11!, {r0, r2, r3, r6, r8, r12, sp, pc}
 *   @0x300e6c stmdavs r8!, {r0, r6, r9, r10, lr} ^
 *   @0x300e70 ldmdavs r11, {r1, r3, r4, r5, r9, r10, lr}
 *   @0x300e74 .word 0x46064798
 *   @0x300e78 teqle r7, r0, lsl #16
 *   @0x300e7c .word 0xf8d6e009
 *   @0x300e80 .word 0xf85331ac
 *   @0x300e84 eorsvs r3, r11, r8, lsr #32
 *   @0x300e88 ldrsblo pc, [r0, r6]!
 *   @0x300e8c eorlo pc, r8, r3, asr r8
 *   @0x300e90 .word 0xf8d4607b
 *   @0x300e94 .word 0x462035d0
 *   @0x300e98 muleq r6, r7, r8
 *   @0x300e9c .word 0x46064798
 *   @0x300ea0 tstlt sp, #32, #22
 *   @0x300ea4 ldmvs r11, {r0, r1, r3, r5, r11, sp, lr}
 *   @0x300ea8 bvs 0xb2dabc <b2_toiTime+0x3d4618>
 *   @0x300eac .word 0xff36f7e3
 *   @0x300eb0 stm sp, {r10, r12}
 *   @0x300eb4 bvs 0xfeb00fc0 <b2_toiTime+0xfffffffffe3a7b1c>
 *   @0x300eb8 .word 0xff30f7e3
 *   @0x300ebc andls r1, r2, r0, lsl #8
 *   @0x300ec0 .word 0xf7e36ae0
 *   @0x300ec4 ldrtmi pc, [r2], -r11, lsr #30
 *   @0x300ec8 strne r4, [r0], #-1601
 *   @0x300ecc stmdavs r11!, {r0, r1, r12, pc}
 *   @0x300ed0 ldmvs pc, {r3, r5, r6, r11, sp, lr}
 *   @0x300ed4 ldrmi r4, [r8, r11, ror #12]!
 *   @0x300ed8 ldreq r9, [r11], #-2816
 *   @0x300edc blls 0x399770 <ft_adobe_glyph_list+0x8e4c>
 *   @0x300ee0 adcvs r0, r3, #452984832
 *   @0x300ee4 ldreq r9, [r11], #-2819
 *   @0x300ee8 strmi r6, [r6], -r3, ror #5
 *   @0x300eec andlt r4, r4, r0, lsr r6
 *   @0x300ef0 ldrhhi lr, [r0, #141]!
 *   @0x300ef4 uqsub16mi r11, r10, r3
 *   @0x300ef8 .word 0xf7ff4606
 *   @0x300efc .word 0x4605ff9d
 *   @0x300f00 ldmdavs r3!, {r3, r6, r8, r11, r12, sp, pc} ^
 *   @0x300f04 .word 0x3080f8d3
 *   @0x300f08 qsublt r6, r11, r3
 *   @0x300f0c uqadd16mi r6, r9, r10
 *   @0x300f10 ldmdavs r2, {r3, r4, r6, r11, sp, lr} ^
 *   @0x300f14 qadd8mi r4, r8, r0
 *   @0x300f18 ldcllt p0, c11, [r0, #-8]!
 *   @0x300f1c mvnsmi lr, sp, lsr #18
 *   @0x300f20 .word 0xf8d02200
 *   @0x300f24 .word 0xf5ad81ec
 *   @0x300f28 strhvs r6, [r10], -pc
 *   @0x300f2c .word 0xf8d0460f
 *   @0x300f30 stcge p1, c3, [r6, #-672]
 *   @0x300f34 .word 0x100cf8d8
 *   @0x300f38 movwls r4, #0x604
 *   @0x300f3c andslo pc, r4, #208, #16
 *   @0x300f40 andls r4, r2, #40, #12
 *   @0x300f44 movwls r9, #0x1203
 *   @0x300f48 ldrbtmi r4, [r11], #-2849
 *   @0x300f4c ldrmi r9, [r3], -r4, lsl #6
 *   @0x300f50 strtmi r6, [r1], -lr, lsl #16
 *   @0x300f54 stmdahs r0, {r4, r5, r7, r8, r9, r10, lr}
 *   @0x300f58 movwhs sp, #0x1135
 *   @0x300f5c sublo pc, r6, r5, lsl #17
 *   @0x300f60 ldrsblo pc, [r4, r4]
 *   @0x300f64 .word 0xf8854606
 *   @0x300f68 .word 0xf8c50044
 *   @0x300f6c .word 0xf8d43554
 *   @0x300f70 .word 0xf8cd3198
 *   @0x300f74 .word 0xf8d43570
 *   @0x300f78 .word 0xf8c5319c
 *   @0x300f7c .word 0xf8d4355c
 *   @0x300f80 .word 0xf8cd31a0
 *   @0x300f84 .word 0xf8d43578
 *   @0x300f88 .word 0xf8c53224
 *   @0x300f8c .word 0xf8d435d4
 *   @0x300f90 eorsvs r3, r8, r0, lsr #4
 *   @0x300f94 ldrblo pc, [r0, #0x8cd]!
 *   @0x300f98 .word 0x31a4f8d4
 *   @0x300f9c ble 0x611a1c <g_SWFaavertbuff+0x3e954>
 *   @0x300fa0 ldrtmi r4, [r1], -r8, lsr #12
 *   @0x300fa4 .word 0xffa6f7ff
 *   @0x300fa8 bvs 0xfedad428 <b2_toiTime+0xfffffffffe653f84>
 *   @0x300fac addsmi r6, r10, #3866624
 *   @0x300fb0 bvs 0xfedf83bc <b2_toiTime+0xfffffffffe69ef18>
 *   @0x300fb4 .word 0x3601603b
 *   @0x300fb8 .word 0xf8d8e7ee
 *   @0x300fbc strtmi r3, [r8], -r12
 *   @0x300fc0 .word 0x4798685b
 *   @0x300fc4 .word 0xf50d2000
 *   @0x300fc8 pop {r0, r1, r2, r3, r4, r5, r7, r8, r10, r11, sp, lr}
 *   @0x300fcc svclt #0x81f0
 *   @0x300fd0 .word 0xffffffa7
 *   @0x300fd4 mvnsmi lr, #737280
 *   @0x300fd8 tsteq r0, #19
 *   @0x300fdc ldclpl p2, c15, [r12, #692]!
 *   @0x300fe0 .word 0x46044617
 *   @0x300fe4 .word 0xf8dd4688
 *   @0x300fe8 .word 0xf8d06618
 *   @0x300fec andle r2, r7, r12, ror #3
 *   @0x300ff0 ldrmi r2, [r10], -r0, lsl #6
 *   @0x300ff4 ldrhtle r4, [r8], -r11
 *   @0x300ff8 eorhs pc, r3, r6, asr #16
 *   @0x300ffc ldrb r3, [r9, r1, lsl #6]!
 *   @0x301000 stcge p8, c6, [r6, #-836]
 *   @0x301004 .word 0x21a8f8d0
 *   @0x301008 .word 0xf8d09200
 *   @0x30100c qadd16mi r2, r8, r4
 *   @0x301010 movwls r9, #0x3302
 *   @0x301014 bmi 0xb25820 <b2_toiTime+0x3cc37c>
 *   @0x301018 andls r4, r4, #2046820352
 *   @0x30101c .word 0xf8d1461a
 *   @0x301020 strtmi r12, [r1], -r0
 *   @0x301024 bllt 0xfe912fac <b2_toiTime+0xfffffffffe1b9b08>
 *   @0x301028 .word 0xf8852301
 *   @0x30102c .word 0xf8d43046
 *   @0x301030 pkhbtmi r3, r1, r4, lsl #3
 *   @0x301034 subeq pc, r4, r5, lsl #17
 *   @0x301038 ldrblo pc, [r4, #-0x8c5]
 *   @0x30103c ldrsblo pc, [r8, r4]
 *   @0x301040 ldrblo pc, [r0, #-0x8cd]!
 *   @0x301044 ldrsblo pc, [r12, r4]
 *   @0x301048 ldrblo pc, [r12, #-0x8c5]
 *   @0x30104c .word 0x31a0f8d4
 *   @0x301050 ldrblo pc, [r8, #-0x8cd]!
 *   @0x301054 eorlo pc, r4, #212, #16
 *   @0x301058 ldrblo pc, [r4, #0x8c5]
 *   @0x30105c eorlo pc, r0, #212, #16
 *   @0x301060 .word 0xf8cd4604
 *   @0x301064 adcsmi r3, r12, #240, #10
 *   @0x301068 andhs sp, r0, r1, lsl #2
 *   @0x30106c qadd16mi lr, r8, r0
 *   @0x301070 .word 0x0108eb04
 *   @0x301074 .word 0xff3ef7ff
 *   @0x301078 bvs 0xfed2f540 <b2_toiTime+0xfffffffffe5d609c>
 *   @0x30107c cdp2 p7, #0x4, c15, c14, c3, #0x7
 *   @0x301080 .word 0xf8461400
 *   @0x301084 and r0, r1, r4, lsr #32
 *   @0x301088 eorls pc, r4, r6, asr #16
 *   @0x30108c strb r3, [r10, r1, lsl #8]!
 *   @0x301090 ldclpl p2, c15, [r12, #52]!
 *   @0x301094 mvnshi lr, #12386304
 *   @0x301098 .word 0xfffffed9
 *   @0x30109c mvnsmi lr, #737280
 *   @0x3010a0 .word 0xf8d0b085
 *   @0x3010a4 movwhs r4, #0x214
 *   @0x3010a8 strmi r4, [sp], -r7, lsl #12
 *   @0x3010ac mcrvs p6, #0x2, r4, c6, c1, #0x4
 *   @0x3010b0 ldmdblt r4!, {r0, r1, r8, r9, r12, pc} ^
 *   @0x3010b4 .word 0xf44f4630
 *   @0x3010b8 bge 0x3dd808 <error_g0017+0x364ac>
 *   @0x3010bc rfeda r3!
 *   @0x3010c0 strmi r9, [r4], -r3, lsl #22
 *   @0x3010c4 .word 0xf0402b00
 *   @0x3010c8 .word 0xf8c08091
 *   @0x3010cc .word 0xf8c731a0
 *   @0x3010d0 stchs p2, c0, [r0, #-80]
 *   @0x3010d4 stmdavs r2!, {r5, r6, r12, lr, pc}
 *   @0x3010d8 cmple r11, r0, lsl #20
 *   @0x3010dc .word 0xf10d9200
 *   @0x3010e0 ldrtmi r0, [r0], -r12, lsl #16
 *   @0x3010e4 andhi pc, r4, sp, asr #17
 *   @0x3010e8 strtmi r2, [r11], -r0, lsr #2
 *   @0x3010ec .word 0xffcff7e6
 *   @0x3010f0 .word 0xf8c49a03
 *   @0x3010f4 bhs 0x30134c <TT_New_Context+0x1144>
 *   @0x3010f8 stm sp, {r3, r4, r5, r6, r8, r12, lr, pc}
 *   @0x3010fc ldrtmi r0, [r0], -r4, lsl #2
 *   @0x301100 strtmi r2, [r11], -r4, asr #3
 *   @0x301104 .word 0xffc3f7e6
 *   @0x301108 .word 0xf8c49a03
 *   @0x30110c bhs 0x301474 <TT_New_Context+0x126c>
 *   @0x301110 stm sp, {r2, r3, r5, r6, r8, r12, lr, pc}
 *   @0x301114 ldrtmi r0, [r0], -r4, lsl #2
 *   @0x301118 qadd16mi r2, r11, r0
 *   @0x30111c .word 0xffb7f7e6
 *   @0x301120 .word 0xf8c49a03
 *   @0x301124 bhs 0x3015ac <TT_New_Context+0x13a4>
 *   @0x301128 rsbeq sp, r11, r0, ror #2
 *   @0x30112c smlabbeq r4, sp, r8, lr
 *   @0x301130 .word 0x21044630
 *   @0x301134 .word 0xffabf7e6
 *   @0x301138 .word 0xf8c49b03
 *   @0x30113c blhs 0x301364 <TT_New_Context+0x115c>
 *   @0x301140 .word 0xf107d154
 *   @0x301144 andhs r0, r2, #132, #6
 *   @0x301148 addslo pc, r0, r4, asr #17
 *   @0x30114c .word 0x03a8f107
 *   @0x301150 sbcslo pc, r4, r4, asr #17
 *   @0x301154 bl 0x3129e8 <af_shaper_get_elem+0x8256>
 *   @0x301158 .word 0xf5070085
 *   @0x30115c .word 0xf8c477e8
 *   @0x301160 .word 0xf8c4008c
 *   @0x301164 adcmi r7, r10, #28, #2
 *   @0x301168 movweq pc, #0x4103
 *   @0x30116c .word 0xf8d3d810
 *   @0x301170 andlo r1, r1, #144
 *   @0x301174 .word 0xf8c33120
 *   @0x301178 .word 0xf8d31094
 *   @0x30117c ldrdlo r1, r2, [r4, #4]
 *   @0x301180 sbcsne pc, r8, r3, asr #17
 *   @0x301184 ldrsbne pc, [r12, -r3]
 *   @0x301188 .word 0xf8c33110
 *   @0x30118c strb r1, [r10, r0, lsr #2]!
 *   @0x301190 and r6, r1, r5, lsr #32
 *   @0x301194 smulwble r7, r10, r2
 *   @0x301198 svceq #0xf1b9
 *   @0x30119c stmdavs r3!, {r0, r2, r12, lr, pc} ^
 *   @0x3011a0 strbmi r11, [r11, #-0x10b]
 *   @0x3011a4 .word 0xf8c4d120
 *   @0x3011a8 ldm r4, {r2, r12, pc}
 *   @0x3011ac mvnlt r0, r0, lsr #1
 *   @0x3011b0 stmibvs r2!, {r0, r1, r2, r5, r6, r7, r8, r12, sp, pc}
 *   @0x3011b4 blge 0x3ef904
 *   @0x3011b8 movwls r9, #0x1200
 *   @0x3011bc blx 0x452a86 <g_RomDisk+0x5b266>
 *   @0x3011c0 .word 0x2104f307
 *   @0x3011c4 .word 0xff63f7e6
 *   @0x3011c8 lslvs r9, r3, #22
 *   @0x3011cc adcseq r11, pc, r3, ror r9
 *   @0x3011d0 streq lr, [r5, #0xb04]
 *   @0x3011d4 ldrtmi r4, [r10], -r3, lsr #12
 *   @0x3011d8 adcmi r3, r11, #4, #6
 *   @0x3011dc stmibvs r1!, {r1, r2, r12, lr, pc}
 *   @0x3011e0 ldrtmi r4, [r10], #-1041
 *   @0x3011e4 .word 0xe7f76199
 *   @0x3011e8 movwls r2, #0x3303
 *   @0x3011ec andlt r9, r5, r3, lsl #16
 *   @0x3011f0 mvnshi lr, #12386304
 *   @0x3011f4 svcmi #0xf0e92d
 *   @0x3011f8 .word 0xf10db0b3
 *   @0x3011fc strmi r0, [r12], -r8, lsl #20
 *   @0x301200 andspl pc, r4, #208, #16
 *   @0x301204 andshs r4, r0, #6291456
 *   @0x301208 blge 0x352a30
 *   @0x30120c blvs 0xffcd2b58 <b2_toiTime+0xffffffffff5796b4>
 *   @0x301210 stmdbls r1, {r3, r4, r5, r7, r8, r9, r10, lr}
 *   @0x301214 blle 0xfcb61c <b2_toiTime+0x872178>
 *   @0x301218 ldmdbhs r0, {r2, r4, r5, r12, lr, pc}
 *   @0x30121c .word 0xb10ddc32
 *   @0x301220 ldmdblt r11!, {r0, r1, r3, r5, r11, sp, lr}
 *   @0x301224 andhs r4, r0, #48, #12
 *   @0x301228 .word 0xff38f7ff
 *   @0x30122c .word 0xf8d6bb58
 *   @0x301230 and r5, r1, r4, lsl r2
 *   @0x301234 smlawble r5, r11, r2, r4
 *   @0x301238 .word 0x9000f8d4
 *   @0x30123c .word 0xf8d44657
 *   @0x301240 strhs r8, [r0], -r8
 *   @0x301244 strlo r9, [r12, -r1, lsl #22]
 *   @0x301248 ble 0x7d1cc8 <b2_toiTime+0x78824>
 *   @0x30124c .word 0x3c0cf857
 *   @0x301250 .word 0x21004620
 *   @0x301254 .word 0xf8576023
 *   @0x301258 adcvs r3, r3, r8, lsl #24
 *   @0x30125c .word 0xf8d56aa3
 *   @0x301260 .word 0xf8d5a08c
 *   @0x301264 ldrmi r11, [r8, r8, lsl #1]
 *   @0x301268 eoreq pc, r6, r11, asr #16
 *   @0x30126c eoreq pc, r6, r10, asr #16
 *   @0x301270 strb r3, [r7, r1, lsl #12]!
 *   @0x301274 andls pc, r0, r4, asr #17
 *   @0x301278 .word 0xf8c42000
 *   @0x30127c and r8, r2, r8
 *   @0x301280 and r2, r0, r2, lsr #1
 *   @0x301284 rscvs r2, r0, r3
 *   @0x301288 pop {r0, r1, r4, r5, r12, sp, pc}
 *   @0x30128c push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x301290 strdlt r4, r5, [r3], #240
 *   @0x301294 stmdaeq r8, {r0, r2, r3, r8, r12, sp, lr, pc} ^
 *   @0x301298 andshs r6, r0, #209920
 *   @0x30129c bl 0x652ca8 <g_SWFaavertbuff+0x7fbe0>
 *   @0x3012a0 strmi r0, [r8], -r2, lsl #6
 *   @0x3012a4 strbmi r4, [r1], -r12, lsl #12
 *   @0x3012a8 blls 0x413150 <g_RomDisk+0x1b930>
 *   @0x3012ac blle 0x174beb4 <b2_toiTime+0xff2a10>
 *   @0x3012b0 blhs 0x735400 <g_SWFvertbuff+0x62338>
 *   @0x3012b4 stmdavs r3!, {r4, r6, r10, r11, r12, lr, pc}
 *   @0x3012b8 .word 0xf8d92500
 *   @0x3012bc .word 0xf10da214
 *   @0x3012c0 qadd16mi r0, lr, r8
 *   @0x3012c4 stmvs r3!, {r0, r8, r9, r12, pc}
 *   @0x3012c8 blls 0x425ed8 <g_RomDisk+0x2e6b8>
 *   @0x3012cc ble 0x11d1d48 <b2_toiTime+0xa788a4>
 *   @0x3012d0 .word 0x3000f8d8
 *   @0x3012d4 blvs 0xffcd2b5c <b2_toiTime+0xffffffffff5796b8>
 *   @0x3012d8 andhs r4, r4, #93323264
 *   @0x3012dc .word 0xf8d86023
 *   @0x3012e0 adcvs r3, r3, r4
 *   @0x3012e4 ldrmi r10, [r8, r5, lsl #22]!
 *   @0x3012e8 stmdblt r5!, {r0, r2, r8, r9, r11, r12, pc} ^
 *   @0x3012ec bllo 0x352b6c
 *   @0x3012f0 ldmdale r1!, {r0, r1, r8, r9, r11, sp}
 *   @0x3012f4 stmdbls r4, {r3, r6, r9, r10, lr}
 *   @0x3012f8 .word 0xf7ff4632
 *   @0x3012fc bllt 0x1b40e40 <b2_toiTime+0x13e799c>
 *   @0x301300 andsge pc, r4, #14221312
 *   @0x301304 adcsmi lr, r3, #1
 *   @0x301308 ldrbmi sp, [r10], -r6, lsr #2
 *   @0x30130c blls 0x44af14 <g_RomDisk+0x536f4>
 *   @0x301310 addsmi r3, pc, #12, #4
 *   @0x301314 .word 0xf852da14
 *   @0x301318 strtmi r3, [r0], -r12, lsl #24
 *   @0x30131c eorvs r2, r3, r0, lsl #2
 *   @0x301320 .word 0x3c08f852
 *   @0x301324 stcne p0, c6, [r11, #652]!
 *   @0x301328 eorlo pc, r3, r10, asr r8
 *   @0x30132c movwls r9, #0x3200
 *   @0x301330 ldrmi r6, [r8, r3, lsr #21]
 *   @0x301334 .word 0xf8439b03
 *   @0x301338 strlo r0, [r1, -r7, lsr #32]
 *   @0x30133c strb r9, [r6, r0, lsl #20]!
 *   @0x301340 .word 0xf1083501
 *   @0x301344 strb r0, [r0, r12, lsl #16]
 *   @0x301348 andhs r9, r0, r1, lsl #22
 *   @0x30134c blls 0x3993e0 <ft_adobe_glyph_list+0x8abc>
 *   @0x301350 and r6, r2, r3, lsr #1
 *   @0x301354 and r2, r0, r2, lsr #1
 *   @0x301358 rscvs r2, r0, r3
 *   @0x30135c pop {r0, r1, r6, r12, sp, pc}
 *   @0x301360 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x301364 ldrshlt r4, [r5], #240
 *   @0x301368 .word 0xf10d6e47
 *   @0x30136c vstrge s0, [r9, #-160]
 *   @0x301370 .word 0xf04f460c
 *   @0x301374 andhs r0, r4, #0, #16
 *   @0x301378 strmi r9, [r6], -r6, lsl #14
 *   @0x30137c andhi pc, r0, r5, asr #17
 *   @0x301380 ldrbmi r4, [r3], -r8, lsl #12
 *   @0x301384 blvs 0xffceb7bc <b2_toiTime+0xffffffffff592318>
 *   @0x301388 .word 0xf8da47b8
 *   @0x30138c strbmi r2, [r2, #-0x0]
 *   @0x301390 .word 0x23a2da01
 *   @0x301394 eorle lr, pc, r1, lsr r0
 *   @0x301398 .word 0xdc2d2a04
 *   @0x30139c ldrtmi r6, [r0], -r7, lsr #16
 *   @0x3013a0 strls r4, [r5, -r1, asr #12]
 *   @0x3013a4 strls r6, [r7, -r7, lsr #17]
 *   @0x3013a8 mrc2 p7, #0x3, apsr_nzcv, c8, c15, #0x7
 *   @0x3013ac stmdahs r0, {r3, r5, sp, lr}
 *   @0x3013b0 .word 0xf8d6d164
 *   @0x3013b4 pkhbtmi r6, r0, r4, lsl #4
 *   @0x3013b8 stmdbeq r0!, {r0, r2, r3, r8, r12, sp, lr, pc} ^
 *   @0x3013bc .word 0xf108e002
 *   @0x3013c0 strlo r0, [r12], -r1, lsl #16
 *   @0x3013c4 .word 0x3000f8da
 *   @0x3013c8 ble 0x17d2a30 <b2_toiTime+0x107958c>
 *   @0x3013cc .word 0xf10d220c
 *   @0x3013d0 blx 0x38408a <_ZTS13C_UTF16String+0x1b136>
 *   @0x3013d4 bge 0x63dffc <g_SWFaavertbuff+0x6af34>
 *   @0x3013d8 strtmi r6, [r0], -r7, ror #23
 *   @0x3013dc ldrmi r5, [r3], #-2201
 *   @0x3013e0 ldmdavs r11, {r2, r4, r9, sp} ^
 *   @0x3013e4 strbmi r6, [r9], -r1, lsr #32
 *   @0x3013e8 ldrbmi r6, [r11], -r3, lsr #1
 *   @0x3013ec .word 0xf8db47b8
 *   @0x3013f0 cdpne p0, #0x5, c3, c10, c0, #0x0
 *   @0x3013f4 stmdble r2, {r0, r1, r4, r9, r11, sp}
 *   @0x3013f8 eorvs r2, r11, r3, lsl #6
 *   @0x3013fc ldclvs p0, c14, [r2, #248]!
 *   @0x301400 mvnsle r2, r0, lsl #20
 *   @0x301404 eoreq lr, r4, sp, lsl #17
 *   @0x301408 stmdals r6, {r2, r8, sp}
 *   @0x30140c .word 0xf7e6005b
 *   @0x301410 ldrbvs pc, [r0, #0xe3e]!
 *   @0x301414 svchs #0x682f
 *   @0x301418 .word 0xf8dbd130
 *   @0x30141c strbmi r3, [r10], -r0
 *   @0x301420 bl 0x312f98 <af_shaper_get_elem+0x8806>
 *   @0x301424 .word 0xf8860083
 *   @0x301428 shsaxvs r3, r0, r8
 *   @0x30142c .word 0x3000f8dc
 *   @0x301430 addsmi r3, pc, #12, #4
 *   @0x301434 .word 0xf852dac3
 *   @0x301438 strtmi r3, [r0], -r12, lsl #24
 *   @0x30143c eorvs r3, r3, r1, lsl #6
 *   @0x301440 .word 0x3c08f852
 *   @0x301444 adcvs r3, r3, r1, lsl #22
 *   @0x301448 .word 0xf8d66a63
 *   @0x30144c andls r11, r4, #92
 *   @0x301450 andgt pc, r12, sp, asr #17
 *   @0x301454 swphs r4, r8, [r0]
 *   @0x301458 eoreq pc, r7, r11, asr #16
 *   @0x30145c bvs 0xfebd2ce4 <b2_toiTime+0xfffffffffe479840>
 *   @0x301460 .word 0xb060f8d6
 *   @0x301464 .word 0xf84b4798
 *   @0x301468 strlo r0, [r1, -r7, lsr #32]
 *   @0x30146c .word 0xc00cf8dd
 *   @0x301470 ldrb r9, [r11, r4, lsl #20]
 *   @0x301474 eorvs r9, r7, r5, lsl #30
 *   @0x301478 adcvs r9, r7, r7, lsl #30
 *   @0x30147c rscvs r6, r3, r11, lsr #16
 *   @0x301480 pop {r0, r2, r4, r6, r12, sp, pc}
 *   @0x301484 ldrblt r8, [r0, #-0xff0]!
 *   @0x301488 strmi r4, [r6], -r12, lsl #12
 *   @0x30148c .word 0xf7e56a49
 *   @0x301490 strhs pc, [r0, #-0xf52]
 *   @0x301494 stmibvs r1!, {r4, r5, r9, r10, lr} ^
 *   @0x301498 adcvs r6, r5, #1342177286
 *   @0x30149c .word 0xff4bf7e5
 *   @0x3014a0 eorvs r6, r5, #1073741881
 *   @0x3014a4 qasxmi r4, r1, r0
 *   @0x3014a8 ldrhtmi lr, [r0], #-141
 *   @0x3014ac svclt #0x43f7e5
 *   @0x3014b0 svcmi #0xf0e92d
 *   @0x3014b4 addlt r4, pc, lr, lsl #12
 *   @0x3014b8 ldrsbls pc, [r12], -r1
 *   @0x3014bc ldrsbne pc, [r0, #128]!
 *   @0x3014c0 strmi r2, [r4], -r2, lsl #6
 *   @0x3014c4 .word 0xb1299307
 *   @0x3014c8 .word 0xf7ff4648
 *   @0x3014cc movwhs pc, #0xfdc
 *   @0x3014d0 mvnslo pc, r4, asr #17
 *   @0x3014d4 .word 0x212c4648
 *   @0x3014d8 .word 0xf7e5aa07
 *   @0x3014dc blls 0x500d74 <SrcVerts+0x5ddb8>
 *   @0x3014e0 blhs 0x312cfc <af_shaper_get_elem+0x856a>
 *   @0x3014e4 .word 0x812cf040
 *   @0x3014e8 ldmdavs r1!, {r4, r5, r9, r10, lr} ^
 *   @0x3014ec ldc2 p7, c15, [r9], {230}
 *   @0x3014f0 stmdahs r0, {r0, r1, r2, r12, pc}
 *   @0x3014f4 .word 0x8124f040
 *   @0x3014f8 strbvc pc, [r8, r4, lsl #10]!
 *   @0x3014fc stmdaeq r4, {r0, r2, r8, r12, sp, lr, pc}
 *   @0x301500 ldm r7, {r0, r1, r8, r9, r10, r12, pc}
 *   @0x301504 stm r8, {r0, r1, r2, r3}
 *   @0x301508 .word 0xf8d4000f
 *   @0x30150c ldrdvs r3, r4, [r11, #-28]!
 *   @0x301510 ldrsblo pc, [r4, #132]
 *   @0x301514 .word 0xf8d461ab
 *   @0x301518 ldmibvs r11!, {r2, r3, r5, r6, r7, r8, r12, sp, lr}
 *   @0x30151c .word 0xf10db1d3
 *   @0x301520 .word 0xf1060a24
 *   @0x301524 .word 0xf8d3011c
 *   @0x301528 ldrbmi r12, [r0], -r0
 *   @0x30152c strbmi r12, [r0, lr, lsl #18]!
 *   @0x301530 ldmdblt r8!, {r0, r1, r2, r12, pc} ^
 *   @0x301534 ldrbmi r4, [r0], -r7, lsl #23
 *   @0x301538 ldrbtmi r9, [r11], #-1291
 *   @0x30153c .word 0xf104930c
 *   @0x301540 movwls r0, #0xd384
 *   @0x301544 ldmvs r11, {r0, r1, r3, r4, r5, r7, r8, r11, sp, lr}
 *   @0x301548 ldmibvs r11!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x30154c andls r6, r7, r11, asr r8
 *   @0x301550 .word 0x47984650
 *   @0x301554 mulslo r12, sp, r8
 *   @0x301558 .word 0xf0402b02
 *   @0x30155c ldmdavs r3!, {r0, r2, r3, r4, r5, r7, pc} ^
 *   @0x301560 blhs 0x49be30 <TimingData+0x1e18>
 *   @0x301564 adcshi pc, r8, r0, asr #4
 *   @0x301568 stmdbhs r3, {r0, r4, r6, r11, r12, sp, lr}
 *   @0x30156c adcshi pc, r4, r0, lsl #4
 *   @0x301570 ldmdbvc r0, {r0, r4, r8, r11, r12, sp, lr} ^
 *   @0x301574 b 0x13425a0 <b2_toiTime+0xbe90fc>
 *   @0x301578 ldmvc r0, {r8, sp, lr}
 *   @0x30157c ldmvc r0, {r0, r8, r9, lr} ^
 *   @0x301580 .word 0x2100ea41
 *   @0x301584 .word 0xf0404299
 *   @0x301588 bvs 0x1f6182c <b2_toiTime+0x1808388>
 *   @0x30158c movwls r2, #0x8300
 *   @0x301590 msreq SPSR_sc, #2147483648
 *   @0x301594 .word 0xf8d64299
 *   @0x301598 teqle r4, #28
 *   @0x30159c mlseq r4, r2, r8, pc
 *   @0x3015a0 cdpeq p1, #0x6, c15, c3, c2, #0x0
 *   @0x3015a4 mlslo r3, r2, r8, pc
 *   @0x3015a8 andhs lr, r0, r3, asr #20
 *   @0x3015ac bl 0x68d5fc <g_SWFlinevertbuff+0x3a534>
 *   @0x3015b0 .word 0xf1030300
 *   @0x3015b4 strbmi r0, [r1, #-0xc12]!
 *   @0x3015b8 addhi pc, r3, r0, asr #1
 *   @0x3015bc mulgt r1, r3, r8
 *   @0x3015c0 andeq pc, r0, lr, lsl r8
 *   @0x3015c4 andhs lr, r12, r0, asr #20
 *   @0x3015c8 ldmdble r10!, {r0, r4, r11, sp} ^
 *   @0x3015cc .word 0xf8937c18
 *   @0x3015d0 streq lr, [r0], #-17
 *   @0x3015d4 andvs lr, lr, r0, asr #20
 *   @0x3015d8 mul lr, r3, r8
 *   @0x3015dc b 0x1320550 <b2_toiTime+0xbc70ac>
 *   @0x3015e0 b 0x1301620 <b2_toiTime+0xba817c>
 *   @0x3015e4 ldmdane r3, {r0, r1, sp}
 *   @0x3015e8 mlsle r10, r3, r2, r4
 *   @0x3015ec addmi r1, pc, #40704
 *   @0x3015f0 .word 0xf893d809
 *   @0x3015f4 .word 0x5c13e001
 *   @0x3015f8 movwhs lr, #0xea43
 *   @0x3015fc bl 0x4da0b0 <SrcVerts+0x370f4>
 *   @0x301600 addsmi r0, r1, #805306376
 *   @0x301604 movwhs sp, #0x2202
 *   @0x301608 subs r9, r10, r8, lsl #6
 *   @0x30160c subsle r2, r8, r0, lsl #22
 *   @0x301610 stmdbge r8, {r9, sp}
 *   @0x301614 ldrbmi r9, [r0], -r0, lsl #4
 *   @0x301618 tsths r0, r1, lsl #2
 *   @0x30161c ldc2 p7, c15, [r7, #-920]!
 *   @0x301620 strmi r9, [r3], r8, lsl #20
 *   @0x301624 bhs 0x319fcc <__gnu_Unwind_Backtrace+0x2dc>
 *   @0x301628 bvs 0xfed75b5c <b2_toiTime+0xfffffffffe61c6b8>
 *   @0x30162c bvs 0x1b1cdc0 <b2_toiTime+0x13c391c>
 *   @0x301630 orreq lr, r1, r7, lsl #22
 *   @0x301634 movwls r9, #0x4105
 *   @0x301638 ble 0x652048 <g_SWFaavertbuff+0x7ef80>
 *   @0x30163c .word 0xf8516aa1
 *   @0x301640 rfeia r1!
 *   @0x301644 .word 0xf1bee008
 *   @0x301648 .word 0xd1070f07
 *   @0x30164c .word 0xf7e44620
 *   @0x301650 andls pc, r8, r5, asr r11
 *   @0x301654 teqle r4, r0, lsl #16
 *   @0x301658 and r2, r1, r0, lsl #4
 *   @0x30165c strb r3, [r11, r1, lsl #4]!
 *   @0x301660 .word 0xf10b9b05
 *   @0x301664 addsmi r0, pc, #16, #22
 *   @0x301668 ldmdavc r9!, {r0, r1, r3, r4, r9, r12, lr, pc}
 *   @0x30166c andls r4, r2, #32, #12
 *   @0x301670 .word 0xf976f7e4
 *   @0x301674 .word 0xf84b3704
 *   @0x301678 qadd16mi r0, r0, r0
 *   @0x30167c .word 0x1c03f817
 *   @0x301680 .word 0xf96ef7e4
 *   @0x301684 .word 0x0c0cf84b
 *   @0x301688 .word 0x0c01f817
 *   @0x30168c .word 0x1c02f817
 *   @0x301690 .word 0x2100ea41
 *   @0x301694 .word 0xf84bb209
 *   @0x301698 bls 0x3886c0 <_ZTS13C_UTF16String+0x1f76c>
 *   @0x30169c .word 0x2c04f84b
 *   @0x3016a0 svcls #0x4e7de
 *   @0x3016a4 strtmi r11, [r0], -r7, lsr #2
 *   @0x3016a8 .word 0xf7e44639
 *   @0x3016ac andls pc, r8, r7, lsr #22
 *   @0x3016b0 ldmdblt r3!, {r3, r8, r9, r11, r12, pc}
 *   @0x3016b4 andshs r4, r0, #40, #22
 *   @0x3016b8 bvs 0xfed5c060 <b2_toiTime+0xfffffffffe602bbc>
 *   @0x3016bc .word 0xf5b5447b
 *   @0x3016c0 blls 0x53b700 <obj_has_event+0xb90>
 *   @0x3016c4 uasxmi r11, r0, r3
 *   @0x3016c8 .word 0xf7e56a69
 *   @0x3016cc movwhs pc, #0xe34
 *   @0x3016d0 adcvs r6, r11, #-1342177274
 *   @0x3016d4 movwls r9, #0x7b08
 *   @0x3016d8 ldrsb pc, [r12], -sp
 *   @0x3016dc svceq #0xf1be
 *   @0x3016e0 ldm r8, {r0, r1, r3, r5, r8, r12, lr, pc}
 *   @0x3016e4 svcls #0x3000f
 *   @0x3016e8 andeq lr, pc, r7, lsl #17
 *   @0x3016ec strhlo pc, [r6], -r5
 *   @0x3016f0 rfeib r5!
 *   @0x3016f4 .word 0x63a3300a
 *   @0x3016f8 .word 0xf50368eb
 *   @0x3016fc .word 0x33ff437f
 *   @0x301700 .word 0x63e3141b
 *   @0x301704 .word 0xf503692b
 *   @0x301708 .word 0x33ff437f
 *   @0x30170c strtvs r1, [r3], #-1051
 *   @0x301710 .word 0xf503696b
 *   @0x301714 ldrne r4, [r11], #-768
 *   @0x301718 sublo pc, r6, r4, lsr #17
 *   @0x30171c .word 0xf50369ab
 *   @0x301720 ldrne r4, [r11], #-768
 *   @0x301724 sublo pc, r8, r4, lsr #17
 *   @0x301728 teqlt r3, r11, lsr #21
 *   @0x30172c .word 0xf8c468a3
 *   @0x301730 uhsub8mi r5, r5, r0
 *   @0x301734 movteq pc, #0x43
 *   @0x301738 ldrtmi r6, [r0], -r3, lsr #1
 *   @0x30173c blx 0xff23f6de <b2_toiTime+0xfffffffffeae623a>
 *   @0x301740 .word 0x4648b11d
 *   @0x301744 .word 0xf7ff4629
 *   @0x301748 stmdals r7, {r1, r2, r3, r4, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30174c pop {r0, r1, r2, r3, r12, sp, pc}
 *   @0x301750 svclt #0x8ff0
 *   @0x301754 andeq r2, r0, r5, asr r1
 *   @0x301758 .word 0xfffff50d
 *   @0x30175c ldrbmi lr, [r0, sp, lsr #18]!
 *   @0x301760 .word 0xf8d04606
 *   @0x301764 mcrvs p2, #0x2, r4, c5, c4, #0x0
 *   @0x301768 rsble r2, r8, r0, lsl #24
 *   @0x30176c stmibvs r1!, {r3, r5, r9, r10, lr}
 *   @0x301770 .word 0x9000f8d4
 *   @0x301774 .word 0x8004f8d4
 *   @0x301778 ldc2l p7, c15, [sp, #916]
 *   @0x30177c andhs r2, r0, #67108864
 *   @0x301780 strbmi r6, [r11, #-0x1a2]
 *   @0x301784 streq pc, [r0, -pc, asr #32]
 *   @0x301788 bl 0x435fa0 <g_RomDisk+0x3e780>
 *   @0x30178c movwlo r0, #0x1183
 *   @0x301790 ldrb r6, [r6, r10, lsl #3]!
 *   @0x301794 .word 0xf8d44628
 *   @0x301798 .word 0xf7e510d8
 *   @0x30179c strtmi pc, [r8], -r12, asr #27
 *   @0x3017a0 ldrsbne pc, [r4], r4
 *   @0x3017a4 sbcsvc pc, r8, r4, asr #17
 *   @0x3017a8 stc2l p7, c15, [r5, #916]
 *   @0x3017ac .word 0x1120f8d4
 *   @0x3017b0 addsvc pc, r4, r4, asr #17
 *   @0x3017b4 .word 0xf7e54628
 *   @0x3017b8 .word 0x4623fdbe
 *   @0x3017bc shasxmi r4, r9, r10
 *   @0x3017c0 smlawtvc r0, r4, r8, pc
 *   @0x3017c4 .word 0xf103454a
 *   @0x3017c8 .word 0xf04f0304
 *   @0x3017cc andle r0, r7, r0, lsl #14
 *   @0x3017d0 sbcsne pc, r0, r3, asr #17
 *   @0x3017d4 .word 0xf8c33201
 *   @0x3017d8 .word 0xf8c3108c
 *   @0x3017dc .word 0xe7f11118
 *   @0x3017e0 .word 0xf8d44628
 *   @0x3017e4 strtmi r1, [r1], r8, lsl #1
 *   @0x3017e8 .word 0xf7e546ba
 *   @0x3017ec .word 0xf8c4fda4
 *   @0x3017f0 .word 0xf8c47088
 *   @0x3017f4 strbmi r7, [r7, #-0x8c]
 *   @0x3017f8 stmdbeq r4, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x3017fc strtmi sp, [r8], -r8
 *   @0x301800 .word 0x1004f8d9
 *   @0x301804 ldc2 p7, c15, [r7, #916]
 *   @0x301808 .word 0xf8c93701
 *   @0x30180c ldrb r10, [r2, r4]!
 *   @0x301810 ldrtmi r2, [r9], r0, lsl #14
 *   @0x301814 .word 0xf1044547
 *   @0x301818 strtmi r0, [r8], -r12, lsl #8
 *   @0x30181c stcvs p0, c13, [r1, #-32]!
 *   @0x301820 .word 0xf7e53701
 *   @0x301824 .word 0xf8c4fd88
 *   @0x301828 .word 0xf8849050
 *   @0x30182c ldrb r9, [r1, r12, asr #32]!
 *   @0x301830 andsne pc, r4, #14024704
 *   @0x301834 ldc2l p7, c15, [pc, #-916]!
 *   @0x301838 .word 0xf8c62300
 *   @0x30183c pop {r2, r4, r9, r12, sp}
 *   @0x301840 strdeq r8, r9, [r0], -r0
 *   @0x301844 svcmi #0xf0e92d
 *   @0x301848 .word 0xf8d0460c
 *   @0x30184c addlt r11, r9, r12, ror #3
 *   @0x301850 stmibvs r11, {r0, r1, r2, r9, r10, lr} ^
 *   @0x301854 .word 0xf8d14608
 *   @0x301858 ldrmi r8, [r8, r8]
 *   @0x30185c strbmi r6, [r6, #-0x826]
 *   @0x301860 ldmdavc r3!, {r3, r4, r9, r12, lr, pc}
 *   @0x301864 eorseq pc, r0, #-1073741784
 *   @0x301868 stmdble r2, {r0, r3, r9, r11, sp}
 *   @0x30186c .word 0xf0402b5b
 *   @0x301870 blhs 0x19e1c5c <b2_toiTime+0x12887b8>
 *   @0x301874 .word 0xd1066925
 *   @0x301878 .word 0xf44f1c73
 *   @0x30187c eorvs r7, r3, r0, lsl #19
 *   @0x301880 movwls r2, #0x5301
 *   @0x301884 bvs 0x1bf98b4 <b2_toiTime+0x14a0410>
 *   @0x301888 ldrmi r4, [r8, r0, lsr #12]
 *   @0x30188c svcvc #0x80f5b0
 *   @0x301890 stcle p6, c4, [r1, #-516]
 *   @0x301894 .word 0xe10f2303
 *   @0x301898 movwls r2, #0x5300
 *   @0x30189c strtmi r6, [r0], -r3, ror #19
 *   @0x3018a0 stmdavs r3!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x3018a4 .word 0xf0804543
 *   @0x3018a8 .word 0xf8d78108
 *   @0x3018ac .word 0xf1041180
 *   @0x3018b0 movwls r0, #0x4364
 *   @0x3018b4 qadd8mi r11, r8, r1
 *   @0x3018b8 beq 0x33d9fc
 *   @0x3018bc ldc2 p7, c15, [r11, #-916]!
 *   @0x3018c0 orrge pc, r0, r7, asr #17
 *   @0x3018c4 .word 0xf8d74628
 *   @0x3018c8 .word 0xf7e51184
 *   @0x3018cc .word 0xf8c7fd34
 *   @0x3018d0 .word 0xf8d4a184
 *   @0x3018d4 swplt r3, r4, [r11]
 *   @0x3018d8 ldrmi r9, [r8, r4, lsl #16]
 *   @0x3018dc cmnls r4, r7, asr #17
 *   @0x3018e0 .word 0xf8c42200
 *   @0x3018e4 .word 0xf10d9060
 *   @0x3018e8 andls r0, r0, #28, #20
 *   @0x3018ec .word 0xf8cd4628
 *   @0x3018f0 .word 0x2102a004
 *   @0x3018f4 .word 0xf7e6464b
 *   @0x3018f8 bls 0x500828 <SrcVerts+0x5d86c>
 *   @0x3018fc orreq pc, r0, r7, asr #17
 *   @0x301900 blls 0x4edd30 <SrcVerts+0x4ad74>
 *   @0x301904 .word 0x464be0d8
 *   @0x301908 streq lr, [r4], #-2189
 *   @0x30190c .word 0x21044628
 *   @0x301910 blx 0xff27f8b2 <b2_toiTime+0xfffffffffeb2640e>
 *   @0x301914 .word 0xf8c79b07
 *   @0x301918 blhs 0x301f30 <TT_New_Context+0x1d28>
 *   @0x30191c .word 0xf8dbd1f1
 *   @0x301920 strbmi r3, [r9], -r0
 *   @0x301924 strtmi r9, [r10], -r4, lsl #16
 *   @0x301928 .word 0x4798681b
 *   @0x30192c stmdahs r0, {r0, r1, r2, r12, pc}
 *   @0x301930 .word 0xf8dfd1e7
 *   @0x301934 strmi r11, [r2], r12, lsl #3
 *   @0x301938 strbmi r4, [r10, #0x4fb]
 *   @0x30193c ldrbmi sp, [r1], -r9, lsl #20
 *   @0x301940 ldrsbpl pc, [r0], r4
 *   @0x301944 ldrbmi r9, [r10], -r4, lsl #16
 *   @0x301948 .word 0xf10a2308
 *   @0x30194c strmi r0, [r8, r1, lsl #20]!
 *   @0x301950 stmibvs r3!, {r0, r1, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x301954 ldrmi r4, [r8, r0, lsr #12]
 *   @0x301958 beq 0x33da9c
 *   @0x30195c strbmi r6, [r5, #-0x825]
 *   @0x301960 stmdavc r10!, {r0, r1, r3, r4, r5, r6, r9, r12, lr, pc}
 *   @0x301964 .word 0xd1252a64
 *   @0x301968 strbmi r1, [r6, #-0xcee]
 *   @0x30196c stmdavc r11!, {r1, r2, r5, r9, r12, lr, pc} ^
 *   @0x301970 .word 0xd1232b65
 *   @0x301974 blhs 0x1c9fc28 <b2_toiTime+0x1546784>
 *   @0x301978 stmvc r11!, {r5, r8, r12, lr, pc} ^
 *   @0x30197c smlatbeq r9, r3, r1, pc
 *   @0x301980 stmdble r10!, {r0, r8, r11, sp} ^
 *   @0x301984 smlatbeq r12, r3, r1, pc
 *   @0x301988 stmdble r6!, {r0, r8, r11, sp} ^
 *   @0x30198c bicseq pc, pc, r3, lsl r0
 *   @0x301990 blhs 0xef5b24 <b2_toiTime+0x79c680>
 *   @0x301994 .word 0xf1a3d061
 *   @0x301998 stmdahs r1, {r3, r5}
 *   @0x30199c .word 0xf003d95d
 *   @0x3019a0 ldmdahs r12!, {r0, r2, r3, r4, r5, r6, r7}
 *   @0x3019a4 ldmdbhs r11, {r0, r3, r4, r6, r12, lr, pc} ^
 *   @0x3019a8 ldmdbhs sp, {r0, r1, r2, r4, r6, r12, lr, pc} ^
 *   @0x3019ac blhs 0xc75b08 <b2_toiTime+0x51c664>
 *   @0x3019b0 subs sp, r2, r4, lsl #2
 *   @0x3019b4 qaddle r2, sp, r1
 *   @0x3019b8 sub r1, lr, lr, ror #24
 *   @0x3019bc .word 0x9e053a30
 *   @0x3019c0 stmdble r1, {r0, r3, r9, r11, sp}
 *   @0x3019c4 eors r11, sp, r6, ror #18
 *   @0x3019c8 bvs 0x1beff28 <b2_toiTime+0x1496a84>
 *   @0x3019cc ldrmi r4, [r8, r0, lsr #12]
 *   @0x3019d0 strmi r6, [r3], r3, ror #19
 *   @0x3019d4 ldrmi r4, [r8, r0, lsr #12]
 *   @0x3019d8 addsmi r6, sp, #2293760
 *   @0x3019dc eor sp, pc, r1, lsl #2
 *   @0x3019e0 stmdavs r5!, {r0, r1, r4, r6, r7, r9, r10, lr}
 *   @0x3019e4 ldrmi r1, [r8, #0xcab]
 *   @0x3019e8 stmdavc r11!, {r3, r5, r8, r11, r12, lr, pc}
 *   @0x3019ec .word 0xd1252b2f
 *   @0x3019f0 ble 0xbd3120 <b2_toiTime+0x479c7c>
 *   @0x3019f4 strlo r6, [r1, #-0xa23]
 *   @0x3019f8 eorvs r4, r5, r0, lsr #12
 *   @0x3019fc stmdavs r3!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x301a00 subsle r4, r10, #281018368
 *   @0x301a04 bhs 0x31bd94
 *   @0x301a08 bl 0xff475f6c <b2_toiTime+0xfffffffffed1cac8>
 *   @0x301a0c stmdals r4, {r0, r1, r10, r11}
 *   @0x301a10 movweq pc, #0x110c
 *   @0x301a14 andgt pc, r12, sp, asr #17
 *   @0x301a18 qsaxmi r4, r10, r9
 *   @0x301a1c ldrsbvs pc, [r0], r4
 *   @0x301a20 .word 0xf8dd47b0
 *   @0x301a24 rscvs r12, r0, r12
 *   @0x301a28 mrsle r2, spsr
 *   @0x301a2c .word 0xf10a6fe3
 *   @0x301a30 .word 0xf8530a01
 *   @0x301a34 .word 0xf803302b
 *   @0x301a38 and r0, r9, r12
 *   @0x301a3c teqlt lr, r5, lsl #28
 *   @0x301a40 eors r2, r9, r2, lsl #6
 *   @0x301a44 strtmi r6, [r0], -r3, lsr #20
 *   @0x301a48 stmvs r3!, {r3, r4, r7, r8, r9, r10, lr} ^
 *   @0x301a4c teqle r4, r0, lsl #22
 *   @0x301a50 strtmi r6, [r0], -r3, ror #19
 *   @0x301a54 qadd8mi r4, lr, r8
 *   @0x301a58 movwhs lr, #0x1780
 *   @0x301a5c cmnlo r0, r7, asr #17
 *   @0x301a60 eor r6, r10, r6, lsr #32
 *   @0x301a64 tsteq r1, #-2147483647
 *   @0x301a68 stmdble r8, {r3, r4, r7, r8, r10, lr}
 *   @0x301a6c shadd16mi r4, r0, r5
 *   @0x301a70 ldrbtmi r2, [r9], #-528
 *   @0x301a74 ldc p5, c15, [r4, #720]!
 *   @0x301a78 movwhs r11, #0x2908
 *   @0x301a7c .word 0xf106e018
 *   @0x301a80 ldrmi r0, [r8, #0x30f]
 *   @0x301a84 ldmdbmi r0, {r3, r8, r11, r12, lr, pc}
 *   @0x301a88 andhs r4, lr, #48, #12
 *   @0x301a8c .word 0xf5b44479
 *   @0x301a90 stmdblt r8, {r3, r5, r7, r8, r10, r11, sp, lr, pc}
 *   @0x301a94 and r2, r11, r4, lsl #6
 *   @0x301a98 tsteq r2, #-2147483647
 *   @0x301a9c stmdble r10, {r3, r4, r7, r8, r10, lr}
 *   @0x301aa0 ldrtmi r4, [r0], -r10, lsl #18
 *   @0x301aa4 ldrbtmi r2, [r9], #-529
 *   @0x301aa8 ldc p5, c15, [r10, #720]
 *   @0x301aac movwhs r11, #0x3918
 *   @0x301ab0 cmnlo r0, r7, asr #17
 *   @0x301ab4 .word 0x23a2e001
 *   @0x301ab8 andlt r6, r9, r3, ror #1
 *   @0x301abc svchi #0xf0e8bd
 *   @0x301ac0 andeq sp, r8, r9, asr #5
 *   @0x301ac4 andeq sp, r8, r8, lsr #3
 *   @0x301ac8 muleq r8, pc, r1
 *   @0x301acc muleq r8, r4, r1
 *   @0x301ad0 svcmi #0xf0e92d
 *   @0x301ad4 stmdavs r6, {r0, r1, r3, r4, r7, r9, r10, lr} ^
 *   @0x301ad8 ldcvs p2, c15, [r4, #-692]!
 *   @0x301adc strmi r4, [r8], r4, lsl #12
 *   @0x301ae0 .word 0xf8d64691
 *   @0x301ae4 .word 0xf8d331ec
 *   @0x301ae8 ldmdbvs r3!, {r2, r3, lr, pc}
 *   @0x301aec movwle r4, #0x529a
 *   @0x301af0 .word 0x3080f8d6
 *   @0x301af4 blhs 0x31c868
 *   @0x301af8 msrhi SPSR_sc, r0
 *   @0x301afc svcvs #0x80f41b
 *   @0x301b00 .word 0xf04bbf18
 *   @0x301b04 .word 0xf1b80b03
 *   @0x301b08 andle r0, r6, r0, lsl #30
 *   @0x301b0c ldrsblo pc, [r0], -r8
 *   @0x301b10 adclo pc, r12, r4, asr #17
 *   @0x301b14 ldrsblo pc, [r4], -r8
 *   @0x301b18 vst4.8 {d30, d31, d0, d1}, [pc], r3
 *   @0x301b1c .word 0xf8c43380
 *   @0x301b20 .word 0xf8df30ac
 *   @0x301b24 ldcge p2, c10, [r4, #-704]
 *   @0x301b28 adcslo pc, r0, r4, asr #17
 *   @0x301b2c .word 0xf8a42300
 *   @0x301b30 .word 0xf01b306e
 *   @0x301b34 .word 0xf8a40f03
 *   @0x301b38 svclt #0x14306c
 *   @0x301b3c mrshs r2, apsr
 *   @0x301b40 subge pc, r8, r4, asr #17
 *   @0x301b44 .word 0xf8d64628
 *   @0x301b48 strbmi r3, [r2], -r8, lsr #3
 *   @0x301b4c movwls r9, #0x109
 *   @0x301b50 andslo pc, r4, #14024704
 *   @0x301b54 ldrtmi r9, [r1], -r2, lsl #2
 *   @0x301b58 .word 0xf3cb9301
 *   @0x301b5c movwls r4, #0x3303
 *   @0x301b60 ldrbtmi r4, [r11], #-2973
 *   @0x301b64 strtmi r9, [r3], -r4, lsl #6
 *   @0x301b68 .word 0x7000f8dc
 *   @0x301b6c andsgt pc, r8, sp, asr #17
 *   @0x301b70 .word 0xf8dd47b8
 *   @0x301b74 .word 0x4607c018
 *   @0x301b78 .word 0xf0402800
 *   @0x301b7c .word 0xf8d68125
 *   @0x301b80 vsra.u64 d19, d4, #0x35
 *   @0x301b84 strtmi r2, [r8], -r0, lsl #5
 *   @0x301b88 subhs pc, r5, r5, lsl #17
 *   @0x301b8c strbmi r9, [r9], -r8, lsl #4
 *   @0x301b90 ldrblo pc, [r4, #-0x8c5]
 *   @0x301b94 .word 0xf8d6aa0a
 *   @0x301b98 .word 0xf8cd3198
 *   @0x301b9c .word 0xf8d635a8
 *   @0x301ba0 .word 0xf8c5319c
 *   @0x301ba4 .word 0xf8d6355c
 *   @0x301ba8 .word 0xf8cd31a0
 *   @0x301bac .word 0xf8d635b0
 *   @0x301bb0 .word 0xf8c53224
 *   @0x301bb4 .word 0xf8d635d4
 *   @0x301bb8 .word 0xf8cd3220
 *   @0x301bbc .word 0xf8cdc018
 *   @0x301bc0 .word 0xf7ff3628
 *   @0x301bc4 .word 0xf8ddf939
 *   @0x301bc8 .word 0x4607c018
 *   @0x301bcc .word 0xf0402800
 *   @0x301bd0 .word 0xf20d80f5
 *   @0x301bd4 .word 0xf10d53b4
 *   @0x301bd8 .word 0xf8d50930
 *   @0x301bdc blgt 0x6eb1b4 <g_SWFvertbuff+0x180ec>
 *   @0x301be0 andeq lr, pc, r9, lsl #17
 *   @0x301be4 .word 0xf8d54628
 *   @0x301be8 movwls r3, #0x7578
 *   @0x301bec .word 0x3004f8dc
 *   @0x301bf0 svcvs #0xe34798
 *   @0x301bf4 .word 0xf0039908
 *   @0x301bf8 .word 0xf0430301
 *   @0x301bfc strbvs r0, [r3, r4, lsl #6]!
 *   @0x301c00 bvs 0xd2e34c <b2_toiTime+0x5d4ea8>
 *   @0x301c04 ldrsbhi pc, [r12], r4
 *   @0x301c08 .word 0xf888f7e3
 *   @0x301c0c eorvs r1, r0, #0, #8
 *   @0x301c10 .word 0xf1086aa8
 *   @0x301c14 .word 0xf7e3050c
 *   @0x301c18 strne pc, [r0], #-2177
 *   @0x301c1c ldm r9, {r5, r7, r9, sp, lr}
 *   @0x301c20 stm r5, {r0, r1, r2, r3}
 *   @0x301c24 movwhs r0, #0x100f
 *   @0x301c28 .word 0xf8c89a07
 *   @0x301c2c .word 0xf888a01c
 *   @0x301c30 .word 0xf8c83008
 *   @0x301c34 adc r2, r12, r0, lsr #32
 *   @0x301c38 .word 0xf7e36aa8
 *   @0x301c3c strne pc, [r0], #-2159
 *   @0x301c40 bvs 0xfed1a6c8 <b2_toiTime+0xfffffffffe5c1224>
 *   @0x301c44 .word 0xf86af7e3
 *   @0x301c48 ldrsblo pc, [r12], r4
 *   @0x301c4c movvs r1, #0, #8
 *   @0x301c50 .word 0xf01b721f
 *   @0x301c54 movwls r0, #0x8310
 *   @0x301c58 .word 0xf8d6d008
 *   @0x301c5c .word 0xf8d621dc
 *   @0x301c60 bne 0xff7ce3b8 <b2_toiTime+0xffffffffff074f14>
 *   @0x301c64 .word 0x6363141b
 *   @0x301c68 and r6, r9, r3, ror #7
 *   @0x301c6c .word 0xf7e36ae8
 *   @0x301c70 strne pc, [r0], #-2133
 *   @0x301c74 bvs 0xffd1a9fc <b2_toiTime+0xffffffffff5c1558>
 *   @0x301c78 .word 0xf850f7e3
 *   @0x301c7c mvnvs r1, #0, #8
 *   @0x301c80 strtvs r4, [r1], #2388
 *   @0x301c84 svceq #0xf1b8
 *   @0x301c88 rfeia r8!
 *   @0x301c8c blhs 0x8cdccc <b2_toiTime+0x174828>
 *   @0x301c90 svcvs #0xe3d803
 *   @0x301c94 orrvc pc, r0, #1124073472
 *   @0x301c98 .word 0xf8d967e3
 *   @0x301c9c .word 0xf5b33000
 *   @0x301ca0 smlabble r10, r0, pc, r3
 *   @0x301ca4 .word 0x300cf8d9
 *   @0x301ca8 svclo #0x80f5b3
 *   @0x301cac .word 0xf8d9d105
 *   @0x301cb0 ldmdblt r3, {r2, r12, sp}
 *   @0x301cb4 .word 0x3008f8d9
 *   @0x301cb8 .word 0xf104b183
 *   @0x301cbc strbmi r0, [r9], -r12, rrx
 *   @0x301cc0 mrrc2 p7, #0xe, pc, lr, c4
 *   @0x301cc4 .word 0x1000f8d9
 *   @0x301cc8 .word 0xf7fe6aa0
 *   @0x301ccc .word 0xf8d9ffdc
 *   @0x301cd0 adcvs r1, r0, #12
 *   @0x301cd4 .word 0xf7fe6b60
 *   @0x301cd8 msrvs SPSR, #856
 *   @0x301cdc svceq #0xf1ba
 *   @0x301ce0 bls 0x4f60ec <SrcVerts+0x53130>
 *   @0x301ce4 ldrbmi r11, [r1], -r2, ror #2
 *   @0x301ce8 rsbeq pc, r12, r4, lsl #2
 *   @0x301cec .word 0xf7e49a07
 *   @0x301cf0 bvs 0xfec00b5c <b2_toiTime+0xfffffffffe4a76b8>
 *   @0x301cf4 ldrbmi r9, [r3], #-2311
 *   @0x301cf8 blvs 0x1bda78c <b2_toiTime+0x14812e8>
 *   @0x301cfc .word 0x6363440b
 *   @0x301d00 svceq #0x1f01b
 *   @0x301d04 blls 0x9361c4 <b2_toiTime+0x1dcd20>
 *   @0x301d08 .word 0xf8d49909
 *   @0x301d0c ldmdavs sp, {r2, r3, r5, r7, sp, pc} ^
 *   @0x301d10 ldrsbtls pc, [r0], r4
 *   @0x301d14 bls 0xcae2a0 <b2_toiTime+0x554dfc>
 *   @0x301d18 usaxmi r11, r1, r2
 *   @0x301d1c .word 0xf7fe6aa0
 *   @0x301d20 .word 0x4649ffb2
 *   @0x301d24 blvs 0x1b1a7ac <b2_toiTime+0x13c1308>
 *   @0x301d28 .word 0xffadf7fe
 *   @0x301d2c ands r6, r9, r0, ror #6
 *   @0x301d30 strhlt pc, [r2], -r3
 *   @0x301d34 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x301d38 andeq lr, r11, #200, #22
 *   @0x301d3c bhs 0x30f164 <af_shaper_get_elem+0x49d2>
 *   @0x301d40 ldrbmi sp, [r1], -r11, ror #27
 *   @0x301d44 .word 0x0c08f855
 *   @0x301d48 .word 0xff9df7fe
 *   @0x301d4c .word 0xf1084649
 *   @0x301d50 .word 0xf8450801
 *   @0x301d54 .word 0xf8550c08
 *   @0x301d58 .word 0xf7fe0c04
 *   @0x301d5c .word 0xf845ff94
 *   @0x301d60 strb r0, [r9, r4, lsl #24]!
 *   @0x301d64 .word 0xf104ad10
 *   @0x301d68 strtmi r0, [r9], -r12, rrx
 *   @0x301d6c blx 0xebfd06 <b2_toiTime+0x766862>
 *   @0x301d70 stmvs r11!, {r1, r3, r5, r11, sp, lr}
 *   @0x301d74 bne 0xfe9dbf20 <b2_toiTime+0xfffffffffe282a7c>
 *   @0x301d78 stmvs r11!, {r0, r1, r5, r7, r8, sp, lr} ^
 *   @0x301d7c bne 0x195a60c <b2_toiTime+0x1201168>
 *   @0x301d80 rsbvs r6, r3, #1073741880
 *   @0x301d84 .word 0xb1239b08
 *   @0x301d88 andseq pc, r8, r4, lsl #2
 *   @0x301d8c .word 0xf7e36b61
 *   @0x301d90 stmdbge r10, {r0, r1, r2, r5, r7, r8, r9, r11, r12, sp, lr, pc}
 *   @0x301d94 .word 0xf8c4680b
 *   @0x301d98 stmdavs r11, {r3, r7, r12, sp} ^
 *   @0x301d9c addlo pc, r12, r4, asr #17
 *   @0x301da0 .word 0x3080f8d6
 *   @0x301da4 cmnlt r11, r11, asr r11
 *   @0x301da8 ldmdavs r8, {r1, r3, r4, r11, sp, lr} ^
 *   @0x301dac .word 0x47906852
 *   @0x301db0 .word 0xf8c42300
 *   @0x301db4 .word 0xf8c43088
 *   @0x301db8 and r3, r5, r12, lsl #1
 *   @0x301dbc .word 0x3004f8dc
 *   @0x301dc0 ldrmi r4, [r8, r8, lsr #12]
 *   @0x301dc4 strhs lr, [r6, -r0]
 *   @0x301dc8 vmin.s8 d4, d13, d24
 *   @0x301dcc pop {r2, r4, r5, r8, r10, r11, sp, lr}
 *   @0x301dd0 svclt #0x8ff0
 *   @0x301dd4 svcvs #0x75746c
 *   @0x301dd8 .word 0xfffff38f
 *   @0x301ddc .word 0x4604b570
 *   @0x301de0 .word 0xf0002800
 *   @0x301de4 .word 0xf8d08096
 *   @0x301de8 cdpvs p2, #0x4, c1, c5, c4, #0x1
 *   @0x301dec qasxmi r11, r8, r9
 *   @0x301df0 blx 0xfeb7fd8c <b2_toiTime+0xfffffffffe4268e8>
 *   @0x301df4 .word 0xf8c42300
 *   @0x301df8 .word 0xf8c43224
 *   @0x301dfc strtmi r3, [r0], -r0, lsr #4
 *   @0x301e00 .word 0xf7ff2600
 *   @0x301e04 strtmi pc, [r8], -r11, lsr #25
 *   @0x301e08 .word 0x1084f8d4
 *   @0x301e0c andsvs pc, r4, #196, #16
 *   @0x301e10 blx 0xfe77fdac <b2_toiTime+0xfffffffffe026908>
 *   @0x301e14 .word 0xf8d44628
 *   @0x301e18 .word 0xf8c41088
 *   @0x301e1c .word 0xf7e56084
 *   @0x301e20 strtmi pc, [r8], -r10, lsl #21
 *   @0x301e24 .word 0x108cf8d4
 *   @0x301e28 addvs pc, r8, r4, asr #17
 *   @0x301e2c blx 0xfe3ffdc8 <b2_toiTime+0xfffffffffdca6924>
 *   @0x301e30 .word 0xf8d44628
 *   @0x301e34 .word 0xf8c41090
 *   @0x301e38 .word 0xf7e5608c
 *   @0x301e3c qsub16mi pc, r8, r12
 *   @0x301e40 ldrsbne pc, [r4], r4
 *   @0x301e44 addsvs pc, r0, r4, asr #17
 *   @0x301e48 blx 0x207fde4 <b2_toiTime+0x1926940>
 *   @0x301e4c .word 0xf8d44628
 *   @0x301e50 .word 0xf8c411b0
 *   @0x301e54 .word 0xf7e56094
 *   @0x301e58 strtmi pc, [r8], -lr, ror #20
 *   @0x301e5c .word 0x11acf8d4
 *   @0x301e60 asrsvs pc, r4, #17
 *   @0x301e64 blx 0x1cffe00 <b2_toiTime+0x15a695c>
 *   @0x301e68 .word 0xf8d44628
 *   @0x301e6c .word 0xf8c411a8
 *   @0x301e70 .word 0xf7e561ac
 *   @0x301e74 strtmi pc, [r8], -r0, ror #20
 *   @0x301e78 ldrsbne pc, [r8, r4]
 *   @0x301e7c .word 0x61a8f8c4
 *   @0x301e80 blx 0x197fe1c <b2_toiTime+0x1226978>
 *   @0x301e84 .word 0xf8d44628
 *   @0x301e88 .word 0xf8c4119c
 *   @0x301e8c .word 0xf7e56198
 *   @0x301e90 .word 0xf8d4fa52
 *   @0x301e94 strtmi r0, [r9], -r0, lsr #3
 *   @0x301e98 orrsvs pc, r12, r4, asr #17
 *   @0x301e9c blx 0xfe3ffe38 <b2_toiTime+0xfffffffffdca6994>
 *   @0x301ea0 .word 0xf8d44628
 *   @0x301ea4 .word 0xf7e511a0
 *   @0x301ea8 strtmi pc, [r8], -r6, asr #20
 *   @0x301eac .word 0x1188f8d4
 *   @0x301eb0 asrvs pc, r4, #17
 *   @0x301eb4 blx 0x12ffe50 <b2_toiTime+0xba69ac>
 *   @0x301eb8 .word 0xf8d44628
 *   @0x301ebc .word 0xf8c4118c
 *   @0x301ec0 .word 0xf7e56188
 *   @0x301ec4 qasxmi pc, r8, r8
 *   @0x301ec8 ldrsbne pc, [r0, r4]
 *   @0x301ecc orrvs pc, r12, r4, asr #17
 *   @0x301ed0 blx 0xf7fe6c <b2_toiTime+0x8269c8>
 *   @0x301ed4 .word 0xf8d44628
 *   @0x301ed8 .word 0xf8c41180
 *   @0x301edc .word 0xf7e56190
 *   @0x301ee0 strtmi pc, [r8], -r10, lsr #20
 *   @0x301ee4 .word 0x1184f8d4
 *   @0x301ee8 orrvs pc, r0, r4, asr #17
 *   @0x301eec blx 0xbffe88 <b2_toiTime+0x4a69e4>
 *   @0x301ef0 .word 0x116cf8d4
 *   @0x301ef4 orrvs pc, r4, r4, asr #17
 *   @0x301ef8 .word 0xf7e54628
 *   @0x301efc .word 0xf8d4fa1c
 *   @0x301f00 .word 0xf8c411f0
 *   @0x301f04 tstlt r1, r12, ror #2
 *   @0x301f08 .word 0xf7ff4628
 *   @0x301f0c strhvs pc, [r6, #-172]!
 *   @0x301f10 ldcllt p1, c6, [r0, #-664]!
 *   @0x301f14 .word 0x4605b5f8
 *   @0x301f18 .word 0x61a4f8d0
 *   @0x301f1c strhs r4, [r0], #-1551
 *   @0x301f20 ble 0x5529f8 <gp_ActiveMaskObjects+0xdd30>
 *   @0x301f24 .word 0x31a8f8d5
 *   @0x301f28 .word 0xf8534638
 *   @0x301f2c .word 0xf5b41024
 *   @0x301f30 tstlt r8, r2, lsr #22
 *   @0x301f34 ldrb r3, [r3, r1, lsl #8]!
 *   @0x301f38 ldcllt p0, c2, [r8, #0]!
 *   @0x301f3c ldcllt p6, c4, [r8, #128]!
 *   @0x301f40 svcmi #0xf0e92d
 *   @0x301f44 strhs r11, [r0, #-0x8b]
 *   @0x301f48 ldrdvs r1, r2, [sp], #135
 *   @0x301f4c andvs r4, r10, r6, lsl #12
 *   @0x301f50 addvs r4, pc, r8, lsl #12
 *   @0x301f54 stmibvs r11, {r2, r3, r9, r10, lr} ^
 *   @0x301f58 ldrmi r4, [r8, r8, lsr #13]
 *   @0x301f5c stclmi p5, c9, [lr, #12]
 *   @0x301f60 teqgt r8, #14614528
 *   @0x301f64 strls r4, [r5, #-0x47d]
 *   @0x301f68 ldrbtmi r4, [r12], #3533
 *   @0x301f6c andsgt pc, r8, sp, asr #17
 *   @0x301f70 strls r4, [r7, #-0x47d]
 *   @0x301f74 adcsmi r6, sp, #2424832
 *   @0x301f78 .word 0xf895d22d
 *   @0x301f7c .word 0xf1baa000
 *   @0x301f80 .word 0xd12a0f65
 *   @0x301f84 adcsmi r1, r11, #10944
 *   @0x301f88 .word 0xf080d01d
 *   @0x301f8c stmdbvc r11!, {r2, r7, pc} ^
 *   @0x301f90 andeq pc, r9, #-1073741784
 *   @0x301f94 ldmdble r6, {r0, r9, r11, sp}
 *   @0x301f98 andeq pc, r12, #-1073741784
 *   @0x301f9c ldmdble r2, {r0, r9, r11, sp}
 *   @0x301fa0 sbcseq pc, pc, #19
 *   @0x301fa4 blhs 0xef5fe8 <b2_toiTime+0x79cb44>
 *   @0x301fa8 .word 0xf1a3d00d
 *   @0x301fac stmdbhs r1, {r3, r5, r8}
 *   @0x301fb0 .word 0xf003d909
 *   @0x301fb4 ldmdbhs r12!, {r0, r2, r3, r4, r5, r6, r7, r8}
 *   @0x301fb8 bhs 0x19f5fd4 <b2_toiTime+0x129cb30>
 *   @0x301fbc bhs 0x1a75fd0 <b2_toiTime+0x131cb2c>
 *   @0x301fc0 blhs 0xc75fcc <b2_toiTime+0x51cb28>
 *   @0x301fc4 ldmibmi r7!, {r0, r1, r2, r5, r6, r8, r12, lr, pc}
 *   @0x301fc8 andhs r4, r5, #40, #12
 *   @0x301fcc .word 0xf5b44479
 *   @0x301fd0 stmdahs r0, {r3, r8, r9, r11, sp, lr, pc}
 *   @0x301fd4 stmvs r0!, {r0, r1, r2, r3, r4, r6, r8, r12, lr, pc} ^
 *   @0x301fd8 .word 0xf1bae15a
 *   @0x301fdc .word 0xd1250f63
 *   @0x301fe0 movweq pc, #0xa105
 *   @0x301fe4 ldrhle r4, [r12], -r11
 *   @0x301fe8 bvc 0x1df6944 <b2_toiTime+0x169d4a0>
 *   @0x301fec andeq pc, r9, #-1073741784
 *   @0x301ff0 ldmdble r6, {r0, r9, r11, sp}
 *   @0x301ff4 andeq pc, r12, #-1073741784
 *   @0x301ff8 ldmdble r2, {r0, r9, r11, sp}
 *   @0x301ffc sbcseq pc, pc, #19
 *   @0x302000 blhs 0xef6044 <b2_toiTime+0x79cba0>
 *   @0x302004 .word 0xf1a3d00d
 *   @0x302008 stmdbhs r1, {r3, r5, r8}
 *   @0x30200c .word 0xf003d909
 *   @0x302010 ldmdbhs r12!, {r0, r2, r3, r4, r5, r6, r7, r8}
 *   @0x302014 bhs 0x19f6030 <b2_toiTime+0x129cb8c>
 *   @0x302018 bhs 0x1a7602c <b2_toiTime+0x131cb88>
 *   @0x30201c blhs 0xc76028 <b2_toiTime+0x51cb84>
 *   @0x302020 stmibmi r1!, {r0, r3, r4, r5, r8, r12, lr, pc}
 *   @0x302024 andhs r4, r9, #40, #12
 *   @0x302028 .word 0xe7d04479
 *   @0x30202c svceq #0x46f1ba
 *   @0x302030 .word 0xf105d131
 *   @0x302034 adcsmi r0, r11, #939524096
 *   @0x302038 eorle sp, r12, #28
 *   @0x30203c .word 0xf1a37b6b
 *   @0x302040 bhs 0x34286c
 *   @0x302044 .word 0xf1a3d916
 *   @0x302048 bhs 0x342880
 *   @0x30204c .word 0xf013d912
 *   @0x302050 ldrdle r0, r1, [pc], -pc
 *   @0x302054 andle r2, sp, pc, lsr #22
 *   @0x302058 smulwbeq r8, r3, r1
 *   @0x30205c stmdble r9, {r0, r8, r11, sp}
 *   @0x302060 mvnseq pc, r3
 *
 * ══ §4/8 pcre_compile2  0x2679c0  size 5576  1394 条（0x2679c0..0x268f88）
 * @func 0x2679c0 0x268f88  size 5576  1394 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2682d0→0x3f76e0, 0x268514→0x3f76dc, 0x268adc→0x3f76dc, 0x268b1c→0x3f76dc
 * 调用序列: 0xb65e0×14 / _pcre_find_bracket×3 / anon_25fe2c+0x128×2 / pcre_compile2+0xb6c×2 / pcre_compile2+0xdb4×2 / anon_25b524+0x2614×2 / anon_2670bc×2 / pcre_compile2+0x2e8
 * 字段偏移 top8: 0x38×16 / 0x3c×14 / 0xc×14 / 0x4c×11 / 0x30×11 / 0x34×11 / 0x48×10 / 0x60×10
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2679c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2679c4 sub sp, sp, #4672
 *   @0x2679c8 sub sp, sp, #28
 *   @0x2679cc ldr r5, [pc, #0xfd8]
 *   @0x2679d0 ldr r4, [pc, #0xfd8]
 *   @0x2679d4 cmp r3, #0
 *   @0x2679d8 add r5, pc, r5
 *   @0x2679dc str r5, [sp, #0x44]
 *   @0x2679e0 ldr r6, [sp, #0x44]
 *   @0x2679e4 add r10, sp, #4672
 *   @0x2679e8 str r3, [sp, #0x54]
 *   @0x2679ec add r10, r10, #24
 *   @0x2679f0 movw r3, #0xee54
 *   @0x2679f4 movt r3, #0xffff
 *   @0x2679f8 ldr r4, [r6, r4]
 *   @0x2679fc movw r5, #0xee38
 *   @0x267a00 str r0, [r10, r3]
 *   @0x267a04 movt r5, #0xffff
 *   @0x267a08 mov r6, r1
 *   @0x267a0c mov r1, #1
 *   @0x267a10 str r4, [sp, #0x50]
 *   @0x267a14 mov r4, r0
 *   @0x267a18 add r0, sp, #4672
 *   @0x267a1c ldr r10, [sp, #0x50]
 *   @0x267a20 add r0, r0, #24
 *   @0x267a24 str r2, [sp, #0x40]
 *   @0x267a28 movw r12, #0xee4c
 *   @0x267a2c movt r12, #0xffff
 *   @0x267a30 str r1, [r0, r5]
 *   @0x267a34 add r1, sp, #8192
 *   @0x267a38 ldr r2, [r10]
 *   @0x267a3c mov r3, #0
 *   @0x267a40 ldr r5, [r1, #-0xd80]
 *   @0x267a44 ldr r10, [r1, #-0xd7c]
 *   @0x267a48 str r3, [r0, r12]
 *   @0x267a4c str r2, [r1, #-0xdac]
 *   @0x267a50 str r5, [sp, #0x48]
 *   @0x267a54 str r10, [sp, #0x3c]
 *   @0x267a58 beq 0x267e64 <pcre_compile2+0x4a4>
 *   @0x267a5c ldr r10, [sp, #0x40]
 *   @0x267a60 ldr r12, [sp, #0x54]
 *   @0x267a64 ldr r5, [sp, #0x48]
 *   @0x267a68 cmp r10, #0
 *   @0x267a6c str r3, [r12]
 *   @0x267a70 strne r3, [r10]
 *   @0x267a74 cmp r5, #0
 *   @0x267a78 beq 0x267e84 <pcre_compile2+0x4c4>
 *   @0x267a7c ldr r10, [sp, #0x3c]
 *   @0x267a80 mov r3, #0
 *   @0x267a84 ldr r12, [sp, #0x48]
 *   @0x267a88 cmp r10, #0
 *   @0x267a8c str r3, [r12]
 *   @0x267a90 beq 0x267ea4 <pcre_compile2+0x4e4>
 *   @0x267a94 movw r3, #0x8580
 *   @0x267a98 movt r3, #0xd800
 *   @0x267a9c ldr r12, [sp, #0x3c]
 *   @0x267aa0 and r3, r6, r3
 *   @0x267aa4 add r0, sp, #4672
 *   @0x267aa8 add r8, sp, #212
 *   @0x267aac movw r2, #0xee7c
 *   @0x267ab0 add r0, r0, #24
 *   @0x267ab4 movt r2, #0xffff
 *   @0x267ab8 cmp r3, #0
 *   @0x267abc add r10, sp, #216
 *   @0x267ac0 str r10, [sp, #0x58]
 *   @0x267ac4 str r12, [r0, r2]
 *   @0x267ac8 add r2, r12, #512
 *   @0x267acc str r2, [r8, #0x8]
 *   @0x267ad0 add r2, r12, #832
 *   @0x267ad4 str r2, [r8, #0xc]
 *   @0x267ad8 add r2, r12, #256
 *   @0x267adc str r2, [sp, #0xd8]
 *   @0x267ae0 bne 0x267d34 <pcre_compile2+0x374>
 *   @0x267ae4 str r3, [r8, #0x64]
 *   @0x267ae8 mov r11, r3
 *   @0x267aec ldr r3, [pc, #0xec0]
 *   @0x267af0 mvn r5, #0
 *   @0x267af4 ubfx r12, r6, #0x10, #0x1
 *   @0x267af8 str r5, [sp, #0x60]
 *   @0x267afc add r3, pc, r3
 *   @0x267b00 str r5, [sp, #0x74]
 *   @0x267b04 str r12, [sp, #0x68]
 *   @0x267b08 movw r10, #0x9998
 *   @0x267b0c str r3, [sp, #0x38]
 *   @0x267b10 movt r10, #0x1999
 *   @0x267b14 ldr r5, [pc, #0xe9c]
 *   @0x267b18 ldr r12, [pc, #0xe9c]
 *   @0x267b1c ldr r3, [pc, #0xe9c]
 *   @0x267b20 add r5, pc, r5
 *   @0x267b24 add r12, pc, r12
 *   @0x267b28 str r10, [sp, #0x64]
 *   @0x267b2c add r3, pc, r3
 *   @0x267b30 ldr r10, [pc, #0xe8c]
 *   @0x267b34 str r5, [sp, #0x4c]
 *   @0x267b38 str r12, [sp, #0x5c]
 *   @0x267b3c add r10, pc, r10
 *   @0x267b40 str r3, [sp, #0x6c]
 *   @0x267b44 ldr r5, [pc, #0xe7c]
 *   @0x267b48 ldr r12, [pc, #0xe7c]
 *   @0x267b4c ldr r3, [pc, #0xe7c]
 *   @0x267b50 add r5, pc, r5
 *   @0x267b54 add r12, pc, r12
 *   @0x267b58 str r5, [sp, #0x78]
 *   @0x267b5c add r3, pc, r3
 *   @0x267b60 str r12, [sp, #0x7c]
 *   @0x267b64 str r3, [sp, #0x80]
 *   @0x267b68 ldr r5, [pc, #0xe64]
 *   @0x267b6c ldr r12, [pc, #0xe64]
 *   @0x267b70 ldr r3, [pc, #0xe64]
 *   @0x267b74 add r5, pc, r5
 *   @0x267b78 add r12, pc, r12
 *   @0x267b7c str r5, [sp, #0x84]
 *   @0x267b80 add r3, pc, r3
 *   @0x267b84 str r12, [sp, #0x70]
 *   @0x267b88 str r3, [sp, #0x88]
 *   @0x267b8c ldrb r3, [r4, r11]
 *   @0x267b90 mov r9, r11
 *   @0x267b94 add r7, r4, r11
 *   @0x267b98 cmp r3, #40
 *   @0x267b9c bne 0x267ce0 <pcre_compile2+0x320>
 *   @0x267ba0 ldrb r3, [r7, #0x1]
 *   @0x267ba4 cmp r3, #42
 *   @0x267ba8 bne 0x267ce0 <pcre_compile2+0x320>
 *   @0x267bac add r5, r11, #2
 *   @0x267bb0 mov r1, r10
 *   @0x267bb4 add r5, r4, r5
 *   @0x267bb8 mov r2, #5
 *   @0x267bbc mov r0, r5
 *   @0x267bc0 bl 0xb65e0 <strncmp@plt>
 *   @0x267bc4 cmp r0, #0
 *   @0x267bc8 addeq r11, r11, #7
 *   @0x267bcc orreq r6, r6, #2048
 *   @0x267bd0 beq 0x267b8c <pcre_compile2+0x1cc>
 *   @0x267bd4 mov r0, r5
 *   @0x267bd8 ldr r1, [sp, #0x38]
 *   @0x267bdc mov r2, #4
 *   @0x267be0 bl 0xb65e0 <strncmp@plt>
 *   @0x267be4 cmp r0, #0
 *   @0x267be8 addeq r11, r11, #6
 *   @0x267bec orreq r6, r6, #2048
 *   @0x267bf0 beq 0x267b8c <pcre_compile2+0x1cc>
 *   @0x267bf4 mov r0, r5
 *   @0x267bf8 ldr r1, [sp, #0x4c]
 *   @0x267bfc mov r2, #4
 *   @0x267c00 bl 0xb65e0 <strncmp@plt>
 *   @0x267c04 cmp r0, #0
 *   @0x267c08 addeq r11, r11, #6
 *   @0x267c0c orreq r6, r6, #536870912
 *   @0x267c10 beq 0x267b8c <pcre_compile2+0x1cc>
 *   @0x267c14 mov r0, r5
 *   @0x267c18 ldr r1, [sp, #0x5c]
 *   @0x267c1c mov r2, #16
 *   @0x267c20 bl 0xb65e0 <strncmp@plt>
 *   @0x267c24 cmp r0, #0
 *   @0x267c28 addeq r11, r11, #18
 *   @0x267c2c orreq r6, r6, #131072
 *   @0x267c30 beq 0x267b8c <pcre_compile2+0x1cc>
 *   @0x267c34 mov r0, r5
 *   @0x267c38 ldr r1, [sp, #0x6c]
 *   @0x267c3c mov r2, #13
 *   @0x267c40 bl 0xb65e0 <strncmp@plt>
 *   @0x267c44 cmp r0, #0
 *   @0x267c48 addeq r11, r11, #15
 *   @0x267c4c orreq r6, r6, #67108864
 *   @0x267c50 beq 0x267b8c <pcre_compile2+0x1cc>
 *   @0x267c54 mov r0, r5
 *   @0x267c58 ldr r1, [sp, #0x78]
 *   @0x267c5c mov r2, #12
 *   @0x267c60 bl 0xb65e0 <strncmp@plt>
 *   @0x267c64 cmp r0, #0
 *   @0x267c68 beq 0x267df4 <pcre_compile2+0x434>
 *   @0x267c6c mov r0, r5
 *   @0x267c70 ldr r1, [sp, #0x7c]
 *   @0x267c74 mov r2, #16
 *   @0x267c78 bl 0xb65e0 <strncmp@plt>
 *   @0x267c7c cmp r0, #0
 *   @0x267c80 bne 0x267f0c <pcre_compile2+0x54c>
 *   @0x267c84 add r11, r9, #18
 *   @0x267c88 ldrb r1, [r4, r11]
 *   @0x267c8c sub r3, r1, #48
 *   @0x267c90 cmp r3, #9
 *   @0x267c94 mov r2, r1
 *   @0x267c98 mov r3, #0
 *   @0x267c9c bhi 0x267cd4 <pcre_compile2+0x314>
 *   @0x267ca0 ldr r0, [sp, #0x64]
 *   @0x267ca4 b 0x267cb0 <pcre_compile2+0x2f0>
 *   @0x267ca8 cmp r3, r0
 *   @0x267cac bhi 0x267cd4 <pcre_compile2+0x314>
 *   @0x267cb0 add r3, r3, r3, lsl #2
 *   @0x267cb4 add r11, r11, #1
 *   @0x267cb8 add r3, r2, r3, lsl #1
 *   @0x267cbc ldrb r2, [r4, r11]
 *   @0x267cc0 sub r3, r3, #48
 *   @0x267cc4 sub r1, r2, #48
 *   @0x267cc8 cmp r1, #9
 *   @0x267ccc mov r1, r2
 *   @0x267cd0 bls 0x267ca8 <pcre_compile2+0x2e8>
 *   @0x267cd4 cmp r1, #41
 *   @0x267cd8 add r11, r11, #1
 *   @0x267cdc beq 0x268004 <pcre_compile2+0x644>
 *   @0x267ce0 ldr r10, [sp, #0x68]
 *   @0x267ce4 ubfx r5, r6, #0xb, #0x1
 *   @0x267ce8 str r5, [sp, #0x4c]
 *   @0x267cec tst r5, r10
 *   @0x267cf0 bne 0x267dd4 <pcre_compile2+0x414>
 *   @0x267cf4 ldr r10, [sp, #0x4c]
 *   @0x267cf8 cmp r10, #0
 *   @0x267cfc beq 0x267d08 <pcre_compile2+0x348>
 *   @0x267d00 tst r6, #8192
 *   @0x267d04 beq 0x2681d8 <pcre_compile2+0x818>
 *   @0x267d08 mov r2, r4
 *   @0x267d0c ands r1, r6, #536870912
 *   @0x267d10 beq 0x267eb8 <pcre_compile2+0x4f8>
 *   @0x267d14 rsb r4, r4, r2
 *   @0x267d18 add r2, sp, #4672
 *   @0x267d1c movw r1, #0xee4c
 *   @0x267d20 add r2, r2, #24
 *   @0x267d24 movt r1, #0xffff
 *   @0x267d28 mov r3, #67
 *   @0x267d2c str r3, [r2, r1]
 *   @0x267d30 b 0x267d48 <pcre_compile2+0x388>
 *   @0x267d34 movw r2, #0xee4c
 *   @0x267d38 movt r2, #0xffff
 *   @0x267d3c mov r4, #0
 *   @0x267d40 mov r3, #17
 *   @0x267d44 str r3, [r0, r2]
 *   @0x267d48 ldr r5, [sp, #0x48]
 *   @0x267d4c str r4, [r5]
 *   @0x267d50 ldr r2, [pc, #0xc88]
 *   @0x267d54 mov r12, r3
 *   @0x267d58 mov r1, #110
 *   @0x267d5c add r2, pc, r2
 *   @0x267d60 add r2, r2, #1344
 *   @0x267d64 cmp r1, #0
 *   @0x267d68 mov r0, r2
 *   @0x267d6c ldrb r1, [r0, #0x1]
 *   @0x267d70 add r2, r2, #1
 *   @0x267d74 bne 0x267d64 <pcre_compile2+0x3a4>
 *   @0x267d78 cmp r1, #0
 *   @0x267d7c beq 0x267dc8 <pcre_compile2+0x408>
 *   @0x267d80 sub r12, r12, #1
 *   @0x267d84 cmp r12, #0
 *   @0x267d88 bgt 0x267d64 <pcre_compile2+0x3a4>
 *   @0x267d8c ldr r12, [sp, #0x40]
 *   @0x267d90 ldr r5, [sp, #0x54]
 *   @0x267d94 cmp r12, #0
 *   @0x267d98 str r2, [r5]
 *   @0x267d9c strne r3, [r12]
 *   @0x267da0 mov r0, #0
 *   @0x267da4 ldr r5, [sp, #0x50]
 *   @0x267da8 add r3, sp, #8192
 *   @0x267dac ldr r2, [r3, #-0xdac]
 *   @0x267db0 ldr r3, [r5]
 *   @0x267db4 cmp r2, r3
 *   @0x267db8 bne 0x268f70 <pcre_compile2+0x15b0>
 *   @0x267dbc add sp, sp, #4672
 *   @0x267dc0 add sp, sp, #28
 *   @0x267dc4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x267dc8 ldr r2, [pc, #0xc14]
 *   @0x267dcc add r2, pc, r2
 *   @0x267dd0 b 0x267d8c <pcre_compile2+0x3cc>
 *   @0x267dd4 add r6, sp, #4672
 *   @0x267dd8 movw r2, #0xee4c
 *   @0x267ddc add r6, r6, #24
 *   @0x267de0 movt r2, #0xffff
 *   @0x267de4 mov r1, #78
 *   @0x267de8 mov r3, r1
 *   @0x267dec str r1, [r6, r2]
 *   @0x267df0 b 0x267d50 <pcre_compile2+0x390>
 *   @0x267df4 add r11, r9, #14
 *   @0x267df8 mov r3, r0
 *   @0x267dfc ldrb r2, [r4, r11]
 *   @0x267e00 sub r1, r2, #48
 *   @0x267e04 cmp r1, #9
 *   @0x267e08 bhi 0x267e3c <pcre_compile2+0x47c>
 *   @0x267e0c ldr r0, [sp, #0x64]
 *   @0x267e10 b 0x267e1c <pcre_compile2+0x45c>
 *   @0x267e14 cmp r3, r0
 *   @0x267e18 bhi 0x267e3c <pcre_compile2+0x47c>
 *   @0x267e1c add r3, r3, r3, lsl #2
 *   @0x267e20 add r11, r11, #1
 *   @0x267e24 add r3, r2, r3, lsl #1
 *   @0x267e28 ldrb r2, [r4, r11]
 *   @0x267e2c sub r3, r3, #48
 *   @0x267e30 sub r1, r2, #48
 *   @0x267e34 cmp r1, #9
 *   @0x267e38 bls 0x267e14 <pcre_compile2+0x454>
 *   @0x267e3c cmp r2, #41
 *   @0x267e40 add r11, r11, #1
 *   @0x267e44 bne 0x267ce0 <pcre_compile2+0x320>
 *   @0x267e48 ldr r12, [sp, #0x74]
 *   @0x267e4c cmp r12, r3
 *   @0x267e50 ldrhi r2, [r8, #0x64]
 *   @0x267e54 strhi r3, [sp, #0x74]
 *   @0x267e58 orrhi r3, r2, #8192
 *   @0x267e5c strhi r3, [r8, #0x64]
 *   @0x267e60 b 0x267b8c <pcre_compile2+0x1cc>
 *   @0x267e64 ldr r12, [sp, #0x40]
 *   @0x267e68 cmp r12, r3
 *   @0x267e6c beq 0x267da0 <pcre_compile2+0x3e0>
 *   @0x267e70 ldr r5, [sp, #0x40]
 *   @0x267e74 mov r3, #99
 *   @0x267e78 ldr r0, [sp, #0x54]
 *   @0x267e7c str r3, [r5]
 *   @0x267e80 b 0x267da4 <pcre_compile2+0x3e4>
 *   @0x267e84 add r6, sp, #4672
 *   @0x267e88 movw r2, #0xee4c
 *   @0x267e8c add r6, r6, #24
 *   @0x267e90 movt r2, #0xffff
 *   @0x267e94 mov r1, #16
 *   @0x267e98 mov r3, r1
 *   @0x267e9c str r1, [r6, r2]
 *   @0x267ea0 b 0x267d50 <pcre_compile2+0x390>
 *   @0x267ea4 ldr r3, [pc, #0xb3c]
 *   @0x267ea8 ldr r5, [sp, #0x44]
 *   @0x267eac ldr r3, [r5, r3]
 *   @0x267eb0 str r3, [sp, #0x3c]
 *   @0x267eb4 b 0x267a94 <pcre_compile2+0xd4>
 *   @0x267eb8 and r3, r6, #25165824
 *   @0x267ebc cmp r3, #25165824
 *   @0x267ec0 beq 0x268268 <pcre_compile2+0x8a8>
 *   @0x267ec4 and r3, r6, #7340032
 *   @0x267ec8 cmp r3, #2097152
 *   @0x267ecc beq 0x268298 <pcre_compile2+0x8d8>
 *   @0x267ed0 ble 0x268240 <pcre_compile2+0x880>
 *   @0x267ed4 cmp r3, #4194304
 *   @0x267ed8 beq 0x268020 <pcre_compile2+0x660>
 *   @0x267edc cmp r3, #5242880
 *   @0x267ee0 beq 0x2688ac <pcre_compile2+0xeec>
 *   @0x267ee4 cmp r3, #3145728
 *   @0x267ee8 beq 0x2688a4 <pcre_compile2+0xee4>
 *   @0x267eec add r6, sp, #4672
 *   @0x267ef0 movw r1, #0xee4c
 *   @0x267ef4 add r6, r6, #24
 *   @0x267ef8 movt r1, #0xffff
 *   @0x267efc mov r3, #56
 *   @0x267f00 rsb r4, r4, r2
 *   @0x267f04 str r3, [r6, r1]
 *   @0x267f08 b 0x267d48 <pcre_compile2+0x388>
 *   @0x267f0c mov r0, r5
 *   @0x267f10 ldr r1, [sp, #0x80]
 *   @0x267f14 mov r2, #3
 *   @0x267f18 bl 0xb65e0 <strncmp@plt>
 *   @0x267f1c cmp r0, #0
 *   @0x267f20 addeq r11, r11, #5
 *   @0x267f24 moveq r3, #1048576
 *   @0x267f28 beq 0x268f74 <pcre_compile2+0x15b4>
 *   @0x267f2c mov r0, r5
 *   @0x267f30 ldr r1, [sp, #0x84]
 *   @0x267f34 mov r2, #3
 *   @0x267f38 bl 0xb65e0 <strncmp@plt>
 *   @0x267f3c cmp r0, #0
 *   @0x267f40 addeq r11, r11, #5
 *   @0x267f44 moveq r3, #2097152
 *   @0x267f48 beq 0x268f74 <pcre_compile2+0x15b4>
 *   @0x267f4c mov r0, r5
 *   @0x267f50 ldr r1, [sp, #0x70]
 *   @0x267f54 mov r2, #5
 *   @0x267f58 bl 0xb65e0 <strncmp@plt>
 *   @0x267f5c cmp r0, #0
 *   @0x267f60 addeq r11, r11, #7
 *   @0x267f64 moveq r3, #3145728
 *   @0x267f68 beq 0x268f74 <pcre_compile2+0x15b4>
 *   @0x267f6c mov r0, r5
 *   @0x267f70 ldr r1, [sp, #0x88]
 *   @0x267f74 mov r2, #4
 *   @0x267f78 bl 0xb65e0 <strncmp@plt>
 *   @0x267f7c cmp r0, #0
 *   @0x267f80 addeq r11, r11, #6
 *   @0x267f84 moveq r3, #4194304
 *   @0x267f88 beq 0x268f74 <pcre_compile2+0x15b4>
 *   @0x267f8c ldr r1, [pc, #0xa58]
 *   @0x267f90 mov r0, r5
 *   @0x267f94 mov r2, #8
 *   @0x267f98 add r1, pc, r1
 *   @0x267f9c bl 0xb65e0 <strncmp@plt>
 *   @0x267fa0 cmp r0, #0
 *   @0x267fa4 addeq r11, r11, #10
 *   @0x267fa8 moveq r3, #5242880
 *   @0x267fac beq 0x268f74 <pcre_compile2+0x15b4>
 *   @0x267fb0 ldr r1, [pc, #0xa38]
 *   @0x267fb4 mov r0, r5
 *   @0x267fb8 mov r2, #12
 *   @0x267fbc add r1, pc, r1
 *   @0x267fc0 bl 0xb65e0 <strncmp@plt>
 *   @0x267fc4 cmp r0, #0
 *   @0x267fc8 addeq r11, r11, #14
 *   @0x267fcc moveq r3, #8388608
 *   @0x267fd0 beq 0x267ff8 <pcre_compile2+0x638>
 *   @0x267fd4 ldr r1, [pc, #0xa18]
 *   @0x267fd8 mov r0, r5
 *   @0x267fdc mov r2, #12
 *   @0x267fe0 add r1, pc, r1
 *   @0x267fe4 bl 0xb65e0 <strncmp@plt>
 *   @0x267fe8 cmp r0, #0
 *   @0x267fec bne 0x267ce0 <pcre_compile2+0x320>
 *   @0x267ff0 add r11, r11, #14
 *   @0x267ff4 mov r3, #16777216
 *   @0x267ff8 bic r6, r6, #25165824
 *   @0x267ffc orr r6, r3, r6
 *   @0x268000 b 0x267b8c <pcre_compile2+0x1cc>
 *   @0x268004 ldr r5, [sp, #0x60]
 *   @0x268008 cmp r5, r3
 *   @0x26800c ldrhi r2, [r8, #0x64]
 *   @0x268010 strhi r3, [sp, #0x60]
 *   @0x268014 orrhi r3, r2, #16384
 *   @0x268018 strhi r3, [r8, #0x64]
 *   @0x26801c b 0x267b8c <pcre_compile2+0x1cc>
 *   @0x268020 mov r1, #1
 *   @0x268024 str r1, [sp, #0x158]
 *   @0x268028 mov r0, r4
 *   @0x26802c mov r5, #0
 *   @0x268030 add r12, sp, #596
 *   @0x268034 str r5, [r8, #0x4c]
 *   @0x268038 str r12, [r8, #0x14]
 *   @0x26803c mov lr, #20
 *   @0x268040 str r12, [r8, #0x20]
 *   @0x268044 add r10, sp, #280
 *   @0x268048 str r12, [r8, #0x10]
 *   @0x26804c add r3, sp, #596
 *   @0x268050 str r5, [r8, #0x50]
 *   @0x268054 add r12, sp, #172
 *   @0x268058 str r5, [r8, #0x40]
 *   @0x26805c movw r11, #0xee4c
 *   @0x268060 str r5, [r8, #0x30]
 *   @0x268064 movt r11, #0xffff
 *   @0x268068 str r5, [r8, #0x34]
 *   @0x26806c str r5, [r8, #0x2c]
 *   @0x268070 str r5, [r8, #0x78]
 *   @0x268074 str r5, [r8, #0x7c]
 *   @0x268078 str r5, [r8, #0x54]
 *   @0x26807c str r5, [r8, #0x80]
 *   @0x268080 str lr, [r8, #0x38]
 *   @0x268084 str r10, [sp, #0x70]
 *   @0x268088 add r10, sp, #168
 *   @0x26808c str r4, [r8, #0x18]
 *   @0x268090 str r3, [sp, #0x38]
 *   @0x268094 add r3, sp, #356
 *   @0x268098 str r5, [sp, #0x118]
 *   @0x26809c str r3, [r8, #0x28]
 *   @0x2680a0 mov r3, #4096
 *   @0x2680a4 str r10, [sp, #0x80]
 *   @0x2680a8 add r10, sp, #164
 *   @0x2680ac str r3, [r8, #0x3c]
 *   @0x2680b0 str r12, [sp, #0x84]
 *   @0x2680b4 add r12, sp, #152
 *   @0x2680b8 str r10, [sp, #0x7c]
 *   @0x2680bc movw r10, #0xee54
 *   @0x2680c0 str r12, [sp, #0x64]
 *   @0x2680c4 add r12, sp, #148
 *   @0x2680c8 str r2, [sp, #0x34]
 *   @0x2680cc movt r10, #0xffff
 *   @0x2680d0 str r12, [sp, #0x68]
 *   @0x2680d4 bl 0xb6538 <strlen@plt>
 *   @0x2680d8 ldr r2, [sp, #0x34]
 *   @0x2680dc add r1, sp, #152
 *   @0x2680e0 str r5, [sp]
 *   @0x2680e4 add lr, sp, #148
 *   @0x2680e8 str r5, [sp, #0x4]
 *   @0x2680ec add r9, r2, r9
 *   @0x2680f0 str r5, [sp, #0x8]
 *   @0x2680f4 add r2, sp, #144
 *   @0x2680f8 str r5, [sp, #0xc]
 *   @0x2680fc movw r3, #0xee50
 *   @0x268100 str r5, [sp, #0x20]
 *   @0x268104 movt r3, #0xffff
 *   @0x268108 str r1, [sp, #0x1c]
 *   @0x26810c movw r12, #0xeffc
 *   @0x268110 str lr, [sp, #0x14]
 *   @0x268114 add lr, sp, #596
 *   @0x268118 str r2, [sp, #0x28]
 *   @0x26811c movt r12, #0xffff
 *   @0x268120 str r8, [sp, #0x24]
 *   @0x268124 add r1, sp, #168
 *   @0x268128 str r5, [r8, #0x68]
 *   @0x26812c add r2, sp, #172
 *   @0x268130 str r5, [r8, #0x58]
 *   @0x268134 str r5, [r8, #0x5c]
 *   @0x268138 str r5, [r8, #0x48]
 *   @0x26813c str r5, [r8, #0x24]
 *   @0x268140 add r5, sp, #4672
 *   @0x268144 add r5, r5, #24
 *   @0x268148 str r6, [r8, #0x60]
 *   @0x26814c str lr, [r5, r3]
 *   @0x268150 add r3, sp, #164
 *   @0x268154 str r9, [r5, r10]
 *   @0x268158 add r5, sp, #156
 *   @0x26815c str r5, [sp, #0x10]
 *   @0x268160 mvn lr, #124
 *   @0x268164 str r5, [sp, #0x6c]
 *   @0x268168 add r5, sp, #160
 *   @0x26816c str r5, [sp, #0x18]
 *   @0x268170 mov r9, #56
 *   @0x268174 str r5, [sp, #0x78]
 *   @0x268178 add r5, sp, #4672
 *   @0x26817c add r5, r5, #24
 *   @0x268180 strb lr, [r5, r12]
 *   @0x268184 add r0, r4, r0
 *   @0x268188 str r0, [r8, #0x1c]
 *   @0x26818c mov r0, r6
 *   @0x268190 bl 0x25ff54 <_pcre_ord2utf+0x1bc>
 *   @0x268194 add r12, sp, #4672
 *   @0x268198 add r12, r12, #24
 *   @0x26819c ldr r3, [r12, r11]
 *   @0x2681a0 cmp r3, #0
 *   @0x2681a4 bne 0x268218 <pcre_compile2+0x858>
 *   @0x2681a8 add r0, sp, #4672
 *   @0x2681ac movw r2, #0xee38
 *   @0x2681b0 add r0, r0, #24
 *   @0x2681b4 movt r2, #0xffff
 *   @0x2681b8 ldr r2, [r0, r2]
 *   @0x2681bc cmp r2, #65536
 *   @0x2681c0 ble 0x2682c4 <pcre_compile2+0x904>
 *   @0x2681c4 ldr r2, [r0, r10]
 *   @0x2681c8 mov r3, #20
 *   @0x2681cc str r3, [r0, r11]
 *   @0x2681d0 rsb r4, r4, r2
 *   @0x2681d4 b 0x267d48 <pcre_compile2+0x388>
 *   @0x2681d8 ldr r2, [sp, #0x48]
 *   @0x2681dc mov r0, r4
 *   @0x2681e0 mvn r1, #0
 *   @0x2681e4 bl 0x2668f4 <_pcre_valid_utf>
 *   @0x2681e8 add r12, sp, #4672
 *   @0x2681ec movw r2, #0xee4c
 *   @0x2681f0 add r12, r12, #24
 *   @0x2681f4 movt r2, #0xffff
 *   @0x2681f8 cmp r0, #0
 *   @0x2681fc str r0, [r12, r2]
 *   @0x268200 beq 0x268288 <pcre_compile2+0x8c8>
 *   @0x268204 add r0, sp, #4672
 *   @0x268208 mov r3, #44
 *   @0x26820c add r0, r0, #24
 *   @0x268210 str r3, [r0, r2]
 *   @0x268214 b 0x267d50 <pcre_compile2+0x390>
 *   @0x268218 ldr r2, [r12, r10]
 *   @0x26821c rsb r4, r4, r2
 *   @0x268220 ldr r10, [sp, #0x48]
 *   @0x268224 cmp r3, #0
 *   @0x268228 str r4, [r10]
 *   @0x26822c bgt 0x267d50 <pcre_compile2+0x390>
 *   @0x268230 ldr r2, [pc, #0x7c0]
 *   @0x268234 add r2, pc, r2
 *   @0x268238 add r2, r2, #1344
 *   @0x26823c b 0x267d8c <pcre_compile2+0x3cc>
 *   @0x268240 cmp r3, #0
 *   @0x268244 beq 0x268298 <pcre_compile2+0x8d8>
 *   @0x268248 cmp r3, #1048576
 *   @0x26824c streq r1, [sp, #0x158]
 *   @0x268250 moveq r3, #13
 *   @0x268254 bne 0x267eec <pcre_compile2+0x52c>
 *   @0x268258 strb r3, [r8, #0x8c]
 *   @0x26825c mov r3, #1
 *   @0x268260 str r3, [r8, #0x88]
 *   @0x268264 b 0x268028 <pcre_compile2+0x668>
 *   @0x268268 add r5, sp, #4672
 *   @0x26826c movw r1, #0xee4c
 *   @0x268270 add r5, r5, #24
 *   @0x268274 movt r1, #0xffff
 *   @0x268278 mov r3, #56
 *   @0x26827c rsb r4, r4, r2
 *   @0x268280 str r3, [r5, r1]
 *   @0x268284 b 0x267d48 <pcre_compile2+0x388>
 *   @0x268288 movw r3, #0xee54
 *   @0x26828c movt r3, #0xffff
 *   @0x268290 ldr r2, [r12, r3]
 *   @0x268294 b 0x267d0c <pcre_compile2+0x34c>
 *   @0x268298 mov r3, #10
 *   @0x26829c cmp r3, #255
 *   @0x2682a0 mov r0, #0
 *   @0x2682a4 str r0, [sp, #0x158]
 *   @0x2682a8 ble 0x268258 <pcre_compile2+0x898>
 *   @0x2682ac strb r3, [r8, #0x8d]
 *   @0x2682b0 asr r3, r3, #8
 *   @0x2682b4 strb r3, [r8, #0x8c]
 *   @0x2682b8 mov r3, #2
 *   @0x2682bc str r3, [r8, #0x88]
 *   @0x2682c0 b 0x268028 <pcre_compile2+0x668>
 *   @0x2682c4 ldr r0, [r8, #0x30]
 *   @0x2682c8 ldr r12, [r8, #0x34]
 *   @0x2682cc ldr r5, [sp, #0x44]
 *   @0x2682d0 ldr r1, [pc, #0x724]
 *   @0x2682d4 mla r2, r12, r0, r2
 *   @0x2682d8 ldr r1, [r5, r1]
 *   @0x2682dc add r2, r2, #56
 *   @0x2682e0 ldr r1, [r1]
 *   @0x2682e4 mov r0, r2
 *   @0x2682e8 str r2, [sp, #0x34]
 *   @0x2682ec str r3, [sp, #0x30]
 *   @0x2682f0 blx r1
 *   @0x2682f4 ldr r2, [sp, #0x34]
 *   @0x2682f8 ldr r3, [sp, #0x30]
 *   @0x2682fc subs r5, r0, #0
 *   @0x268300 beq 0x268f20 <pcre_compile2+0x1560>
 *   @0x268304 ldr r1, [r8, #0x34]
 *   @0x268308 add r12, r5, #56
 *   @0x26830c ldr r10, [r8, #0x30]
 *   @0x268310 movw r0, #0x5245
 *   @0x268314 str r2, [r5, #0x4]
 *   @0x268318 movt r0, #0x5043
 *   @0x26831c uxth r2, r1
 *   @0x268320 str r0, [r5]
 *   @0x268324 uxth r0, r10
 *   @0x268328 str r10, [sp, #0x5c]
 *   @0x26832c ldr r10, [sp, #0x74]
 *   @0x268330 mla r0, r0, r2, r12
 *   @0x268334 ldr lr, [r8, #0x60]
 *   @0x268338 ldr r2, [pc, #0x6a8]
 *   @0x26833c ldr r11, [sp, #0x3c]
 *   @0x268340 str lr, [r5, #0x8]
 *   @0x268344 str r0, [sp, #0x38]
 *   @0x268348 ldr r0, [r8, #0x64]
 *   @0x26834c str r10, [r5, #0x10]
 *   @0x268350 ldr r10, [sp, #0x60]
 *   @0x268354 strh r1, [r5, #36]
 *   @0x268358 str r0, [r5, #0xc]
 *   @0x26835c str r10, [r5, #0x14]
 *   @0x268360 ldr r10, [sp, #0x5c]
 *   @0x268364 strh r3, [r5, #24]
 *   @0x268368 strh r3, [r5, #26]
 *   @0x26836c strh r10, [r5, #38]
 *   @0x268370 ldr r10, [sp, #0x44]
 *   @0x268374 strh r9, [r5, #34]
 *   @0x268378 strh r3, [r5, #40]
 *   @0x26837c ldr r0, [r10, r2]
 *   @0x268380 ldr r10, [sp, #0x5c]
 *   @0x268384 cmp r11, r0
 *   @0x268388 ldr r1, [r8, #0x40]
 *   @0x26838c ldr r2, [r8, #0x10]
 *   @0x268390 moveq r11, #0
 *   @0x268394 cmp r10, #0
 *   @0x268398 ldr r10, [sp, #0x38]
 *   @0x26839c str r11, [r5, #0x30]
 *   @0x2683a0 str r3, [r5, #0x34]
 *   @0x2683a4 strh r3, [r5, #46]
 *   @0x2683a8 strh r3, [r5, #44]
 *   @0x2683ac strh r3, [r5, #42]
 *   @0x2683b0 str r10, [r8, #0x14]
 *   @0x2683b4 str r3, [r8, #0x58]
 *   @0x2683b8 str r3, [r8, #0x5c]
 *   @0x2683bc str r3, [r8, #0x48]
 *   @0x2683c0 str r3, [r8, #0x80]
 *   @0x2683c4 str r12, [r8, #0x2c]
 *   @0x2683c8 str r1, [sp, #0x118]
 *   @0x2683cc str r3, [r8, #0x40]
 *   @0x2683d0 str r2, [r8, #0x20]
 *   @0x2683d4 str r3, [r8, #0x68]
 *   @0x2683d8 str r3, [r8, #0x6c]
 *   @0x2683dc str r3, [r8, #0x70]
 *   @0x2683e0 str r3, [r8, #0x74]
 *   @0x2683e4 str r3, [r8, #0x24]
 *   @0x2683e8 ble 0x26852c <pcre_compile2+0xb6c>
 *   @0x2683ec ldr r2, [r8, #0x28]
 *   @0x2683f0 str r3, [r8, #0x30]
 *   @0x2683f4 str r7, [sp, #0x74]
 *   @0x2683f8 mov r7, r12
 *   @0x2683fc ldr r3, [r2]
 *   @0x268400 str r2, [sp, #0x3c]
 *   @0x268404 ldr r11, [r2, #0x4]
 *   @0x268408 ldr r2, [r2, #0x8]
 *   @0x26840c str r4, [sp, #0x88]
 *   @0x268410 mov r4, r3
 *   @0x268414 str r5, [sp, #0x70]
 *   @0x268418 str r2, [sp, #0x60]
 *   @0x26841c str r6, [sp, #0x8c]
 *   @0x268420 b 0x268450 <pcre_compile2+0xa90>
 *   @0x268424 ldrb r3, [r9, r11]
 *   @0x268428 cmp r3, #0
 *   @0x26842c beq 0x2684e0 <pcre_compile2+0xb20>
 *   @0x268430 rsb r2, r10, r6
 *   @0x268434 add r0, r7, r5
 *   @0x268438 mov r1, r7
 *   @0x26843c mul r2, r5, r2
 *   @0x268440 bl 0xb6694 <memmove@plt>
 *   @0x268444 ldr r5, [sp, #0x3c]
 *   @0x268448 add r5, r5, #12
 *   @0x26844c str r5, [sp, #0x3c]
 *   @0x268450 ldr r6, [sp, #0x60]
 *   @0x268454 add r0, r7, #2
 *   @0x268458 mov r1, r4
 *   @0x26845c mov r2, r11
 *   @0x268460 strb r6, [r7, #0x1]
 *   @0x268464 lsr r3, r6, #8
 *   @0x268468 strb r3, [r7]
 *   @0x26846c add r7, r7, r11
 *   @0x268470 bl 0xb65bc <memcpy@plt>
 *   @0x268474 ldr r10, [sp, #0x5c]
 *   @0x268478 mov r12, #0
 *   @0x26847c strb r12, [r7, #0x2]
 *   @0x268480 subs r10, r10, #1
 *   @0x268484 ldr r12, [r8, #0x30]
 *   @0x268488 str r10, [sp, #0x5c]
 *   @0x26848c add r6, r12, #1
 *   @0x268490 str r6, [r8, #0x30]
 *   @0x268494 beq 0x2684f8 <pcre_compile2+0xb38>
 *   @0x268498 ldr r12, [sp, #0x3c]
 *   @0x26849c cmp r6, #0
 *   @0x2684a0 ldr r7, [r8, #0x2c]
 *   @0x2684a4 ldr r3, [r12, #0x14]
 *   @0x2684a8 ldr r4, [r12, #0xc]
 *   @0x2684ac ldr r11, [r12, #0x10]
 *   @0x2684b0 str r3, [sp, #0x60]
 *   @0x2684b4 ble 0x268444 <pcre_compile2+0xa84>
 *   @0x2684b8 ldr r5, [r8, #0x34]
 *   @0x2684bc add r9, r7, #2
 *   @0x2684c0 mov r10, #0
 *   @0x2684c4 mov r0, r4
 *   @0x2684c8 mov r1, r9
 *   @0x2684cc mov r2, r11
 *   @0x2684d0 bl 0xb6c40 <memcmp@plt>
 *   @0x2684d4 cmp r0, #0
 *   @0x2684d8 beq 0x268424 <pcre_compile2+0xa64>
 *   @0x2684dc blt 0x268430 <pcre_compile2+0xa70>
 *   @0x2684e0 add r10, r10, #1
 *   @0x2684e4 add r7, r7, r5
 *   @0x2684e8 cmp r10, r6
 *   @0x2684ec add r9, r9, r5
 *   @0x2684f0 bne 0x2684c4 <pcre_compile2+0xb04>
 *   @0x2684f4 b 0x268444 <pcre_compile2+0xa84>
 *   @0x2684f8 ldr r3, [r8, #0x38]
 *   @0x2684fc ldr r7, [sp, #0x74]
 *   @0x268500 cmp r3, #20
 *   @0x268504 ldr r5, [sp, #0x70]
 *   @0x268508 ldr r4, [sp, #0x88]
 *   @0x26850c ldr r6, [sp, #0x8c]
 *   @0x268510 ble 0x26852c <pcre_compile2+0xb6c>
 *   @0x268514 ldr r3, [pc, #0x4e4]
 *   @0x268518 ldr r10, [sp, #0x44]
 *   @0x26851c ldr r0, [r8, #0x28]
 *   @0x268520 ldr r3, [r10, r3]
 *   @0x268524 ldr r3, [r3]
 *   @0x268528 blx r3
 *   @0x26852c ldr r10, [sp, #0x38]
 *   @0x268530 add r12, sp, #4672
 *   @0x268534 add r12, r12, #24
 *   @0x268538 movw r2, #0xee54
 *   @0x26853c movw r3, #0xee50
 *   @0x268540 movt r2, #0xffff
 *   @0x268544 movt r3, #0xffff
 *   @0x268548 add r1, sp, #168
 *   @0x26854c str r7, [r12, r2]
 *   @0x268550 mvn r2, #124
 *   @0x268554 str r10, [r12, r3]
 *   @0x268558 mov r7, #0
 *   @0x26855c strb r2, [r10]
 *   @0x268560 add r3, sp, #164
 *   @0x268564 ldr r0, [r5, #0x8]
 *   @0x268568 add r2, sp, #172
 *   @0x26856c str r8, [sp, #0x24]
 *   @0x268570 add r8, sp, #212
 *   @0x268574 add r12, sp, #156
 *   @0x268578 add lr, sp, #148
 *   @0x26857c str r12, [sp, #0x10]
 *   @0x268580 add r10, sp, #160
 *   @0x268584 add r12, sp, #152
 *   @0x268588 str lr, [sp, #0x14]
 *   @0x26858c str r10, [sp, #0x18]
 *   @0x268590 str r12, [sp, #0x1c]
 *   @0x268594 str r7, [sp]
 *   @0x268598 str r7, [sp, #0x4]
 *   @0x26859c str r7, [sp, #0x8]
 *   @0x2685a0 str r7, [sp, #0xc]
 *   @0x2685a4 str r7, [sp, #0x20]
 *   @0x2685a8 str r7, [sp, #0x28]
 *   @0x2685ac bl 0x25ff54 <_pcre_ord2utf+0x1bc>
 *   @0x2685b0 ldr r3, [r8, #0x6c]
 *   @0x2685b4 ldr r0, [r8, #0x40]
 *   @0x2685b8 ldr r1, [r8, #0x4c]
 *   @0x2685bc cmp r3, r7
 *   @0x2685c0 ldr r3, [r8, #0x48]
 *   @0x2685c4 ldr r2, [r8, #0x64]
 *   @0x2685c8 strh r0, [r5, #30]
 *   @0x2685cc orr r2, r2, #1
 *   @0x2685d0 strh r1, [r5, #32]
 *   @0x2685d4 str r2, [r5, #0xc]
 *   @0x2685d8 strh r3, [r5, #28]
 *   @0x2685dc beq 0x268604 <pcre_compile2+0xc44>
 *   @0x2685e0 add lr, sp, #4672
 *   @0x2685e4 movw r2, #0xee48
 *   @0x2685e8 add lr, lr, #24
 *   @0x2685ec movt r2, #0xffff
 *   @0x2685f0 movw r3, #0xee40
 *   @0x2685f4 movt r3, #0xffff
 *   @0x2685f8 str r7, [lr, r2]
 *   @0x2685fc mvn r2, #0
 *   @0x268600 str r2, [lr, r3]
 *   @0x268604 add r0, sp, #4672
 *   @0x268608 movw r3, #0xee4c
 *   @0x26860c add r0, r0, #24
 *   @0x268610 movt r3, #0xffff
 *   @0x268614 ldr r2, [r0, r3]
 *   @0x268618 cmp r2, #0
 *   @0x26861c bne 0x26863c <pcre_compile2+0xc7c>
 *   @0x268620 movw r2, #0xee54
 *   @0x268624 movt r2, #0xffff
 *   @0x268628 ldr r2, [r0, r2]
 *   @0x26862c ldrb r2, [r2]
 *   @0x268630 cmp r2, #0
 *   @0x268634 movne r2, #22
 *   @0x268638 strne r2, [r0, r3]
 *   @0x26863c add r2, sp, #4672
 *   @0x268640 movw r3, #0xee50
 *   @0x268644 add r2, r2, #24
 *   @0x268648 movt r3, #0xffff
 *   @0x26864c add r10, sp, #4672
 *   @0x268650 mov r0, #0
 *   @0x268654 ldr r1, [r2, r3]
 *   @0x268658 add r10, r10, #24
 *   @0x26865c movw r2, #0xee38
 *   @0x268660 movt r2, #0xffff
 *   @0x268664 add r12, r1, #1
 *   @0x268668 str r12, [r10, r3]
 *   @0x26866c strb r0, [r1]
 *   @0x268670 ldr r12, [sp, #0x38]
 *   @0x268674 ldr r1, [r10, r3]
 *   @0x268678 ldr r3, [r10, r2]
 *   @0x26867c rsb r2, r12, r1
 *   @0x268680 cmp r2, r3
 *   @0x268684 movwgt r3, #0xee4c
 *   @0x268688 movtgt r3, #0xffff
 *   @0x26868c movgt r2, #23
 *   @0x268690 strgt r2, [r10, r3]
 *   @0x268694 ldr r2, [r8, #0x20]
 *   @0x268698 ldr r3, [r8, #0x10]
 *   @0x26869c cmp r2, r3
 *   @0x2686a0 bls 0x268774 <pcre_compile2+0xdb4>
 *   @0x2686a4 add lr, sp, #4672
 *   @0x2686a8 movw r11, #0xee4c
 *   @0x2686ac add lr, lr, #24
 *   @0x2686b0 movt r11, #0xffff
 *   @0x2686b4 mov r0, #0
 *   @0x2686b8 mvn r1, #0
 *   @0x2686bc ldr r2, [lr, r11]
 *   @0x2686c0 mov r3, #53
 *   @0x2686c4 ldr r7, [sp, #0x38]
 *   @0x2686c8 cmp r2, #0
 *   @0x2686cc bne 0x268774 <pcre_compile2+0xdb4>
 *   @0x2686d0 ldr r2, [r8, #0x20]
 *   @0x2686d4 ldr r12, [r8, #0x10]
 *   @0x2686d8 cmp r2, r12
 *   @0x2686dc bls 0x268774 <pcre_compile2+0xdb4>
 *   @0x2686e0 sub r12, r2, #2
 *   @0x2686e4 str r12, [r8, #0x20]
 *   @0x2686e8 ldrb r12, [r2, #-0x2]
 *   @0x2686ec ldrb r2, [r2, #-0x1]
 *   @0x2686f0 orrs r2, r2, r12, lsl #8
 *   @0x2686f4 beq 0x268f40 <pcre_compile2+0x1580>
 *   @0x2686f8 add r10, r7, r2
 *   @0x2686fc ldrb r12, [r10, #-0x1]
 *   @0x268700 cmp r12, #117
 *   @0x268704 bne 0x268f40 <pcre_compile2+0x1580>
 *   @0x268708 add lr, r2, #1
 *   @0x26870c ldrb r9, [r7, r2]
 *   @0x268710 add r12, r7, lr
 *   @0x268714 ldrb r2, [r7, lr]
 *   @0x268718 orr r9, r2, r9, lsl #8
 *   @0x26871c cmp r9, r1
 *   @0x268720 beq 0x268744 <pcre_compile2+0xd84>
 *   @0x268724 mov r0, r7
 *   @0x268728 ldr r1, [sp, #0x4c]
 *   @0x26872c mov r2, r9
 *   @0x268730 str r3, [sp, #0x30]
 *   @0x268734 str r12, [sp, #0x34]
 *   @0x268738 bl 0x25e0fc <_pcre_find_bracket>
 *   @0x26873c ldr r12, [sp, #0x34]
 *   @0x268740 ldr r3, [sp, #0x30]
 *   @0x268744 cmp r0, #0
 *   @0x268748 beq 0x268f5c <pcre_compile2+0x159c>
 *   @0x26874c rsb r2, r7, r0
 *   @0x268750 asr r1, r2, #8
 *   @0x268754 strb r1, [r10]
 *   @0x268758 add r10, sp, #4672
 *   @0x26875c strb r2, [r12]
 *   @0x268760 add r10, r10, #24
 *   @0x268764 ldr r2, [r10, r11]
 *   @0x268768 cmp r2, #0
 *   @0x26876c mov r1, r9
 *   @0x268770 beq 0x2686d0 <pcre_compile2+0xd10>
 *   @0x268774 ldr r3, [r8, #0x3c]
 *   @0x268778 cmp r3, #4096
 *   @0x26877c bgt 0x268b18 <pcre_compile2+0x1158>
 *   @0x268780 add lr, sp, #4672
 *   @0x268784 movw r3, #0xee4c
 *   @0x268788 add lr, lr, #24
 *   @0x26878c movt r3, #0xffff
 *   @0x268790 mov r2, #0
 *   @0x268794 str r2, [r8, #0x10]
 *   @0x268798 ldr r2, [lr, r3]
 *   @0x26879c cmp r2, #0
 *   @0x2687a0 bne 0x268ad8 <pcre_compile2+0x1118>
 *   @0x2687a4 ldrh r2, [r5, #30]
 *   @0x2687a8 ldrh r1, [r5, #32]
 *   @0x2687ac cmp r1, r2
 *   @0x2687b0 movhi r2, #15
 *   @0x2687b4 strhi r2, [lr, r3]
 *   @0x2687b8 bhi 0x268ad8 <pcre_compile2+0x1118>
 *   @0x2687bc tst r6, #131072
 *   @0x2687c0 beq 0x268b4c <pcre_compile2+0x118c>
 *   @0x2687c4 ldr r3, [r8, #0x74]
 *   @0x2687c8 cmp r3, #0
 *   @0x2687cc bne 0x268990 <pcre_compile2+0xfd0>
 *   @0x2687d0 ldr r4, [r5, #0x8]
 *   @0x2687d4 ands r1, r4, #16
 *   @0x2687d8 beq 0x2688b8 <pcre_compile2+0xef8>
 *   @0x2687dc add lr, sp, #4672
 *   @0x2687e0 movw r3, #0xee40
 *   @0x2687e4 add lr, lr, #24
 *   @0x2687e8 movt r3, #0xffff
 *   @0x2687ec ldr r3, [lr, r3]
 *   @0x2687f0 cmp r3, #0
 *   @0x2687f4 blt 0x268838 <pcre_compile2+0xe78>
 *   @0x2687f8 ldr r2, [r5, #0x8]
 *   @0x2687fc tst r2, #16
 *   @0x268800 beq 0x26880c <pcre_compile2+0xe4c>
 *   @0x268804 tst r3, #2
 *   @0x268808 beq 0x268838 <pcre_compile2+0xe78>
 *   @0x26880c add r0, sp, #4672
 *   @0x268810 movw r2, #0xee48
 *   @0x268814 add r0, r0, #24
 *   @0x268818 movt r2, #0xffff
 *   @0x26881c tst r3, #1
 *   @0x268820 ldrb r3, [r0, r2]
 *   @0x268824 strh r3, [r5, #26]
 *   @0x268828 bne 0x268928 <pcre_compile2+0xf68>
 *   @0x26882c ldr r3, [r5, #0xc]
 *   @0x268830 orr r3, r3, #64
 *   @0x268834 str r3, [r5, #0xc]
 *   @0x268838 add r1, sp, #4672
 *   @0x26883c movw r3, #0xee50
 *   @0x268840 add r1, r1, #24
 *   @0x268844 movt r3, #0xffff
 *   @0x268848 mov r6, #0
 *   @0x26884c ldr r7, [sp, #0x38]
 *   @0x268850 ldr r4, [r1, r3]
 *   @0x268854 b 0x268870 <pcre_compile2+0xeb0>
 *   @0x268858 ldrb r0, [r7, #0x1]
 *   @0x26885c ldrb r2, [r7, #0x2]
 *   @0x268860 orr r2, r2, r0, lsl #8
 *   @0x268864 ldrb r2, [r7, r2]!
 *   @0x268868 cmp r2, #119
 *   @0x26886c bne 0x268f80 <pcre_compile2+0x15c0>
 *   @0x268870 str r6, [sp]
 *   @0x268874 mov r0, r7
 *   @0x268878 mov r1, r4
 *   @0x26887c ldr r2, [sp, #0x4c]
 *   @0x268880 mov r3, r8
 *   @0x268884 bl 0x25bbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa88>
 *   @0x268888 cmp r0, #0
 *   @0x26888c beq 0x268858 <pcre_compile2+0xe98>
 *   @0x268890 ldr r3, [r5, #0xc]
 *   @0x268894 mov r0, r5
 *   @0x268898 orr r3, r3, #32768
 *   @0x26889c str r3, [r5, #0xc]
 *   @0x2688a0 b 0x267da4 <pcre_compile2+0x3e4>
 *   @0x2688a4 movw r3, #0xd0a
 *   @0x2688a8 b 0x26829c <pcre_compile2+0x8dc>
 *   @0x2688ac mov r1, #2
 *   @0x2688b0 str r1, [sp, #0x158]
 *   @0x2688b4 b 0x268028 <pcre_compile2+0x668>
 *   @0x2688b8 ldr r0, [sp, #0x38]
 *   @0x2688bc mov r3, r1
 *   @0x2688c0 mov r2, r8
 *   @0x2688c4 bl 0x25c5dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14b4>
 *   @0x2688c8 subs r6, r0, #0
 *   @0x2688cc orrne r4, r4, #16
 *   @0x2688d0 strne r4, [r5, #0x8]
 *   @0x2688d4 bne 0x2687dc <pcre_compile2+0xe1c>
 *   @0x2688d8 add r10, sp, #4672
 *   @0x2688dc movw r4, #0xee3c
 *   @0x2688e0 add r10, r10, #24
 *   @0x2688e4 movt r4, #0xffff
 *   @0x2688e8 ldr r3, [r10, r4]
 *   @0x2688ec cmp r3, #0
 *   @0x2688f0 blt 0x268958 <pcre_compile2+0xf98>
 *   @0x2688f4 add lr, sp, #4672
 *   @0x2688f8 movw r2, #0xee44
 *   @0x2688fc add lr, lr, #24
 *   @0x268900 movt r2, #0xffff
 *   @0x268904 ldr r2, [lr, r2]
 *   @0x268908 tst r3, #1
 *   @0x26890c uxtb r3, r2
 *   @0x268910 strh r3, [r5, #24]
 *   @0x268914 bne 0x268940 <pcre_compile2+0xf80>
 *   @0x268918 ldr r3, [r5, #0xc]
 *   @0x26891c orr r3, r3, #16
 *   @0x268920 str r3, [r5, #0xc]
 *   @0x268924 b 0x2687dc <pcre_compile2+0xe1c>
 *   @0x268928 ldr r2, [sp, #0xd8]
 *   @0x26892c ldrb r2, [r2, r3]
 *   @0x268930 cmp r2, r3
 *   @0x268934 ldr r3, [r5, #0xc]
 *   @0x268938 orrne r3, r3, #128
 *   @0x26893c b 0x268830 <pcre_compile2+0xe70>
 *   @0x268940 ldr r2, [sp, #0xd8]
 *   @0x268944 ldrb r2, [r2, r3]
 *   @0x268948 cmp r2, r3
 *   @0x26894c ldr r3, [r5, #0xc]
 *   @0x268950 orrne r3, r3, #32
 *   @0x268954 b 0x26891c <pcre_compile2+0xf5c>
 *   @0x268958 mov r2, r6
 *   @0x26895c add r1, sp, #148
 *   @0x268960 ldr r0, [sp, #0x38]
 *   @0x268964 bl 0x25c988 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1860>
 *   @0x268968 add r12, sp, #4672
 *   @0x26896c add r12, r12, #24
 *   @0x268970 movw r2, #0xee44
 *   @0x268974 movt r2, #0xffff
 *   @0x268978 ldr r3, [r12, r4]
 *   @0x26897c cmp r3, #0
 *   @0x268980 str r0, [r12, r2]
 *   @0x268984 blt 0x268e50 <pcre_compile2+0x1490>
 *   @0x268988 mov r2, r0
 *   @0x26898c b 0x268908 <pcre_compile2+0xf48>
 *   @0x268990 ldr r0, [sp, #0x38]
 *   @0x268994 mvn r2, #0
 *   @0x268998 ldr r1, [sp, #0x4c]
 *   @0x26899c bl 0x25e0fc <_pcre_find_bracket>
 *   @0x2689a0 subs r6, r0, #0
 *   @0x2689a4 bne 0x268a3c <pcre_compile2+0x107c>
 *   @0x2689a8 b 0x268abc <pcre_compile2+0x10fc>
 *   @0x2689ac andseq r10, r8, r8, ror r2
 *   @0x2689b0 .word 0xffffbd00
 *   @0x2689b4 .word 0x000ef5d4
 *   @0x2689b8 strheq pc, [lr], -r8
 *   @0x2689bc strheq pc, [lr], -r12
 *   @0x2689c0 andeq pc, lr, r8, asr #11
 *   @0x2689c4 andeq pc, lr, r12, lsl #11
 *   @0x2689c8 strheq pc, [lr], -r4
 *   @0x2689cc andeq pc, lr, r0, asr #11
 *   @0x2689d0 andeq pc, lr, r12, asr #11
 *   @0x2689d4 strheq pc, [lr], -r8
 *   @0x2689d8 strheq pc, [lr], -r8
 *   @0x2689dc strheq pc, [lr], -r8
 *   @0x2689e0 ldrsheq r1, [r2], -r4
 *   @0x2689e4 .word 0x000ef2d4
 *   @0x2689e8 .word 0xfffffb98
 *   @0x2689ec andeq pc, lr, r8, lsr #3
 *   @0x2689f0 muleq lr, r0, r1
 *   @0x2689f4 andeq pc, lr, r12, ror r1
 *   @0x2689f8 andseq r1, r2, r12, lsl r9
 *   @0x2689fc .word 0xfffffb94
 *   @0x268a00 .word 0xffffea38
 *   @0x268a04 .word 0xfffffb8c
 *   @0x268a08 .word 0xfffffb90
 *   @0x268a0c ldr r3, [r8, #0x48]
 *   @0x268a10 cmp r0, r3
 *   @0x268a14 strgt r0, [r8, #0x48]
 *   @0x268a18 strb r0, [r6, #0x2]
 *   @0x268a1c asr r0, r0, #8
 *   @0x268a20 strb r0, [r6, #0x1]
 *   @0x268a24 add r0, r6, #3
 *   @0x268a28 ldr r1, [sp, #0x4c]
 *   @0x268a2c mvn r2, #0
 *   @0x268a30 bl 0x25e0fc <_pcre_find_bracket>
 *   @0x268a34 subs r6, r0, #0
 *   @0x268a38 beq 0x268b34 <pcre_compile2+0x1174>
 *   @0x268a3c ldrb r12, [r6, #0x1]
 *   @0x268a40 ldrb r3, [r6, #0x2]
 *   @0x268a44 orrs r12, r3, r12, lsl #8
 *   @0x268a48 bne 0x268a24 <pcre_compile2+0x1064>
 *   @0x268a4c ldrb r7, [r6, #-0x2]
 *   @0x268a50 mov r0, r6
 *   @0x268a54 ldrb r1, [r6, #-0x1]
 *   @0x268a58 mov r2, #1
 *   @0x268a5c mov r3, r8
 *   @0x268a60 orr r7, r1, r7, lsl #8
 *   @0x268a64 sub r7, r7, #3
 *   @0x268a68 ldrb r9, [r6, r7]
 *   @0x268a6c strb r12, [r6, r7]
 *   @0x268a70 ldr r1, [r5, #0x8]
 *   @0x268a74 str r12, [sp]
 *   @0x268a78 ubfx r1, r1, #0xb, #0x1
 *   @0x268a7c bl 0x25b5c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x49c>
 *   @0x268a80 strb r9, [r6, r7]
 *   @0x268a84 cmp r0, #0
 *   @0x268a88 bge 0x268a0c <pcre_compile2+0x104c>
 *   @0x268a8c cmn r0, #2
 *   @0x268a90 moveq r0, #36
 *   @0x268a94 beq 0x268aa4 <pcre_compile2+0x10e4>
 *   @0x268a98 cmn r0, #4
 *   @0x268a9c movne r0, #25
 *   @0x268aa0 moveq r0, #70
 *   @0x268aa4 add r12, sp, #4672
 *   @0x268aa8 movw r3, #0xee4c
 *   @0x268aac add r12, r12, #24
 *   @0x268ab0 movt r3, #0xffff
 *   @0x268ab4 str r0, [r12, r3]
 *   @0x268ab8 b 0x268ad8 <pcre_compile2+0x1118>
 *   @0x268abc add r10, sp, #4672
 *   @0x268ac0 movw r3, #0xee4c
 *   @0x268ac4 add r10, r10, #24
 *   @0x268ac8 movt r3, #0xffff
 *   @0x268acc ldr r3, [r10, r3]
 *   @0x268ad0 cmp r3, #0
 *   @0x268ad4 beq 0x2687d0 <pcre_compile2+0xe10>
 *   @0x268ad8 mov r0, r5
 *   @0x268adc ldr r3, [pc, #-0xe4]
 *   @0x268ae0 ldr r5, [sp, #0x44]
 *   @0x268ae4 add r6, sp, #4672
 *   @0x268ae8 add r6, r6, #24
 *   @0x268aec ldr r3, [r5, r3]
 *   @0x268af0 ldr r3, [r3]
 *   @0x268af4 blx r3
 *   @0x268af8 movw r2, #0xee54
 *   @0x268afc movt r2, #0xffff
 *   @0x268b00 movw r3, #0xee4c
 *   @0x268b04 movt r3, #0xffff
 *   @0x268b08 ldr r2, [r6, r2]
 *   @0x268b0c ldr r3, [r6, r3]
 *   @0x268b10 rsb r4, r4, r2
 *   @0x268b14 b 0x268220 <pcre_compile2+0x860>
 *   @0x268b18 ldr r12, [sp, #0x44]
 *   @0x268b1c ldr r3, [pc, #-0x124]
 *   @0x268b20 ldr r0, [r8, #0x10]
 *   @0x268b24 ldr r3, [r12, r3]
 *   @0x268b28 ldr r3, [r3]
 *   @0x268b2c blx r3
 *   @0x268b30 b 0x268780 <pcre_compile2+0xdc0>
 *   @0x268b34 add lr, sp, #4672
 *   @0x268b38 movw r3, #0xee4c
 *   @0x268b3c add lr, lr, #24
 *   @0x268b40 movt r3, #0xffff
 *   @0x268b44 ldr r3, [lr, r3]
 *   @0x268b48 b 0x268ad0 <pcre_compile2+0x1110>
 *   @0x268b4c ldr r6, [sp, #0x38]
 *   @0x268b50 movw r10, #0xee58
 *   @0x268b54 ldr r9, [sp, #0x4c]
 *   @0x268b58 movt r10, #0xffff
 *   @0x268b5c add r11, sp, #180
 *   @0x268b60 add r12, sp, #176
 *   @0x268b64 str r11, [sp, #0x5c]
 *   @0x268b68 str r12, [sp, #0x3c]
 *   @0x268b6c str r5, [sp, #0x64]
 *   @0x268b70 str r4, [sp, #0x60]
 *   @0x268b74 ldrb r3, [r6]
 *   @0x268b78 cmp r3, #161
 *   @0x268b7c bhi 0x268ce4 <pcre_compile2+0x1324>
 *   @0x268b80 sub r2, r3, #33
 *   @0x268b84 cmp r2, #64
 *   @0x268b88 bhi 0x268c88 <pcre_compile2+0x12c8>
 *   @0x268b8c cmp r3, #84
 *   @0x268b90 movhi r2, #85
 *   @0x268b94 bhi 0x268bbc <pcre_compile2+0x11fc>
 *   @0x268b98 cmp r3, #71
 *   @0x268b9c movhi r2, #72
 *   @0x268ba0 bhi 0x268bbc <pcre_compile2+0x11fc>
 *   @0x268ba4 cmp r3, #58
 *   @0x268ba8 movhi r2, #59
 *   @0x268bac bhi 0x268bbc <pcre_compile2+0x11fc>
 *   @0x268bb0 cmp r3, #45
 *   @0x268bb4 movls r2, #33
 *   @0x268bb8 movhi r2, #46
 *   @0x268bbc rsb r3, r2, r3
 *   @0x268bc0 uxtb r4, r3
 *   @0x268bc4 add r7, r4, #33
 *   @0x268bc8 uxtb r7, r7
 *   @0x268bcc cmp r7, #40
 *   @0x268bd0 addhi r3, sp, #180
 *   @0x268bd4 movhi r0, #0
 *   @0x268bd8 bhi 0x268bf4 <pcre_compile2+0x1234>
 *   @0x268bdc mov r3, r11
 *   @0x268be0 mov r0, r6
 *   @0x268be4 mov r1, r9
 *   @0x268be8 ldr r2, [sp, #0xd8]
 *   @0x268bec bl 0x25db38 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a10>
 *   @0x268bf0 mov r3, r11
 *   @0x268bf4 ands r2, r4, #253
 *   @0x268bf8 moveq r2, #1
 *   @0x268bfc beq 0x268c0c <pcre_compile2+0x124c>
 *   @0x268c00 subs r1, r2, #4
 *   @0x268c04 rsbs r2, r1, #0
 *   @0x268c08 adcs r2, r2, r1
 *   @0x268c0c add r1, sp, #4672
 *   @0x268c10 cmp r0, #0
 *   @0x268c14 add r1, r1, #24
 *   @0x268c18 str r2, [r3, #0x4]
 *   @0x268c1c mov r2, #1000
 *   @0x268c20 str r2, [r1, r10]
 *   @0x268c24 beq 0x268eb4 <pcre_compile2+0x14f4>
 *   @0x268c28 ldr r5, [sp, #0x3c]
 *   @0x268c2c add r12, sp, #4672
 *   @0x268c30 add r12, r12, #24
 *   @0x268c34 str r0, [sp]
 *   @0x268c38 movw lr, #0x3e7
 *   @0x268c3c mov r1, r9
 *   @0x268c40 str r5, [sp, #0x4]
 *   @0x268c44 mov r2, r8
 *   @0x268c48 str lr, [r12, r10]
 *   @0x268c4c bl 0x2670bc <_pcre_xclass+0x410>
 *   @0x268c50 cmp r0, #0
 *   @0x268c54 beq 0x268eb4 <pcre_compile2+0x14f4>
 *   @0x268c58 sub r7, r7, #33
 *   @0x268c5c cmp r7, #7
 *   @0x268c60 addls pc, pc, r7, lsl #2
 *   @0x268c64 b 0x268eb4 <pcre_compile2+0x14f4>
 *   @0x268c68 b 0x268ebc <pcre_compile2+0x14fc>
 *   @0x268c6c b 0x268ef8 <pcre_compile2+0x1538>
 *   @0x268c70 b 0x268ef8 <pcre_compile2+0x1538>
 *   @0x268c74 b 0x268ed0 <pcre_compile2+0x1510>
 *   @0x268c78 b 0x268ed0 <pcre_compile2+0x1510>
 *   @0x268c7c b 0x268ee4 <pcre_compile2+0x1524>
 *   @0x268c80 b 0x268ee4 <pcre_compile2+0x1524>
 *   @0x268c84 b 0x268f0c <pcre_compile2+0x154c>
 *   @0x268c88 sub r2, r3, #110
 *   @0x268c8c cmp r2, #2
 *   @0x268c90 bhi 0x268cbc <pcre_compile2+0x12fc>
 *   @0x268c94 cmp r3, #112
 *   @0x268c98 addne r7, r6, #33
 *   @0x268c9c ldrbeq r7, [r6, #0x1]
 *   @0x268ca0 ldrbeq r2, [r6, #0x2]
 *   @0x268ca4 orreq r7, r2, r7, lsl #8
 *   @0x268ca8 addeq r7, r6, r7
 *   @0x268cac ldrb r4, [r7]
 *   @0x268cb0 sub r2, r4, #98
 *   @0x268cb4 cmp r2, #7
 *   @0x268cb8 bls 0x268dd4 <pcre_compile2+0x1414>
 *   @0x268cbc cmp r3, #96
 *   @0x268cc0 bhi 0x268da4 <pcre_compile2+0x13e4>
 *   @0x268cc4 cmp r3, #94
 *   @0x268cc8 bhs 0x268d90 <pcre_compile2+0x13d0>
 *   @0x268ccc cmp r3, #90
 *   @0x268cd0 bhi 0x268d78 <pcre_compile2+0x13b8>
 *   @0x268cd4 cmp r3, #85
 *   @0x268cd8 bhs 0x268d90 <pcre_compile2+0x13d0>
 *   @0x268cdc cmp r3, #0
 *   @0x268ce0 bne 0x268d2c <pcre_compile2+0x136c>
 *   @0x268ce4 add r6, sp, #4672
 *   @0x268ce8 movw r3, #0xee4c
 *   @0x268cec add r6, r6, #24
 *   @0x268cf0 movt r3, #0xffff
 *   @0x268cf4 ldr r5, [sp, #0x64]
 *   @0x268cf8 ldr r3, [r6, r3]
 *   @0x268cfc ldr r4, [sp, #0x60]
 *   @0x268d00 cmp r3, #0
 *   @0x268d04 beq 0x2687c4 <pcre_compile2+0xe04>
 *   @0x268d08 b 0x268ad8 <pcre_compile2+0x1118>
 *   @0x268d0c cmp r3, #153
 *   @0x268d10 beq 0x268d24 <pcre_compile2+0x1364>
 *   @0x268d14 cmp r3, #155
 *   @0x268d18 beq 0x268d24 <pcre_compile2+0x1364>
 *   @0x268d1c cmp r3, #151
 *   @0x268d20 bne 0x268d2c <pcre_compile2+0x136c>
 *   @0x268d24 ldrb r2, [r6, #0x1]
 *   @0x268d28 add r6, r6, r2
 *   @0x268d2c ldr r2, [pc, #-0x330]
 *   @0x268d30 cmp r9, #0
 *   @0x268d34 ldr r5, [sp, #0x44]
 *   @0x268d38 ldr r2, [r5, r2]
 *   @0x268d3c ldrb r2, [r2, r3]
 *   @0x268d40 add r6, r6, r2
 *   @0x268d44 beq 0x268b74 <pcre_compile2+0x11b4>
 *   @0x268d48 sub r3, r3, #29
 *   @0x268d4c cmp r3, #55
 *   @0x268d50 bhi 0x268b74 <pcre_compile2+0x11b4>
 *   @0x268d54 ldrb r3, [r6, #-0x1]
 *   @0x268d58 cmp r3, #191
 *   @0x268d5c bls 0x268b74 <pcre_compile2+0x11b4>
 *   @0x268d60 ldr r2, [pc, #-0x360]
 *   @0x268d64 and r3, r3, #63
 *   @0x268d68 ldr r2, [r5, r2]
 *   @0x268d6c ldrb r3, [r2, r3]
 *   @0x268d70 add r6, r6, r3
 *   @0x268d74 b 0x268b74 <pcre_compile2+0x11b4>
 *   @0x268d78 ldrb r2, [r6, #0x3]
 *   @0x268d7c sub r2, r2, #15
 *   @0x268d80 cmp r2, #1
 *   @0x268d84 bhi 0x268d2c <pcre_compile2+0x136c>
 *   @0x268d88 add r6, r6, #2
 *   @0x268d8c b 0x268d2c <pcre_compile2+0x136c>
 *   @0x268d90 ldrb r2, [r6, #0x1]
 *   @0x268d94 sub r2, r2, #15
 *   @0x268d98 cmp r2, #1
 *   @0x268d9c bhi 0x268d2c <pcre_compile2+0x136c>
 *   @0x268da0 b 0x268d88 <pcre_compile2+0x13c8>
 *   @0x268da4 cmp r3, #149
 *   @0x268da8 beq 0x268d24 <pcre_compile2+0x1364>
 *   @0x268dac bhi 0x268d0c <pcre_compile2+0x134c>
 *   @0x268db0 cmp r3, #97
 *   @0x268db4 beq 0x268d78 <pcre_compile2+0x13b8>
 *   @0x268db8 cmp r3, #112
 *   @0x268dbc bne 0x268d2c <pcre_compile2+0x136c>
 *   @0x268dc0 ldrb r2, [r6, #0x1]
 *   @0x268dc4 ldrb r3, [r6, #0x2]
 *   @0x268dc8 orr r3, r3, r2, lsl #8
 *   @0x268dcc add r6, r6, r3
 *   @0x268dd0 b 0x268b74 <pcre_compile2+0x11b4>
 *   @0x268dd4 mov r1, r9
 *   @0x268dd8 ldr r2, [sp, #0xd8]
 *   @0x268ddc mov r3, r11
 *   @0x268de0 mov r0, r6
 *   @0x268de4 bl 0x25db38 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a10>
 *   @0x268de8 ldr r5, [sp, #0x3c]
 *   @0x268dec add r12, sp, #4672
 *   @0x268df0 and lr, r4, #1
 *   @0x268df4 add r12, r12, #24
 *   @0x268df8 mov r1, r9
 *   @0x268dfc str r5, [sp, #0x4]
 *   @0x268e00 mov r2, r8
 *   @0x268e04 mov r3, r11
 *   @0x268e08 movw r5, #0x3e7
 *   @0x268e0c str r5, [r12, r10]
 *   @0x268e10 eor lr, lr, #1
 *   @0x268e14 str lr, [sp, #0xb8]
 *   @0x268e18 str r0, [sp]
 *   @0x268e1c bl 0x2670bc <_pcre_xclass+0x410>
 *   @0x268e20 cmp r0, #0
 *   @0x268e24 beq 0x268eb4 <pcre_compile2+0x14f4>
 *   @0x268e28 sub r12, r4, #100
 *   @0x268e2c cmp r12, #5
 *   @0x268e30 addls pc, pc, r12, lsl #2
 *   @0x268e34 b 0x268e9c <pcre_compile2+0x14dc>
 *   @0x268e38 b 0x268e8c <pcre_compile2+0x14cc>
 *   @0x268e3c b 0x268e8c <pcre_compile2+0x14cc>
 *   @0x268e40 b 0x268e7c <pcre_compile2+0x14bc>
 *   @0x268e44 b 0x268e7c <pcre_compile2+0x14bc>
 *   @0x268e48 b 0x268eac <pcre_compile2+0x14ec>
 *   @0x268e4c b 0x268eac <pcre_compile2+0x14ec>
 *   @0x268e50 mov r3, r6
 *   @0x268e54 mov r1, r6
 *   @0x268e58 str r6, [sp]
 *   @0x268e5c mov r2, r8
 *   @0x268e60 ldr r0, [sp, #0x38]
 *   @0x268e64 bl 0x25c788 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1660>
 *   @0x268e68 cmp r0, #0
 *   @0x268e6c ldrne r3, [r5, #0xc]
 *   @0x268e70 orrne r3, r3, #256
 *   @0x268e74 strne r3, [r5, #0xc]
 *   @0x268e78 b 0x2687dc <pcre_compile2+0xe1c>
 *   @0x268e7c mov r3, #108
 *   @0x268e80 strb r3, [r7]
 *   @0x268e84 ldrb r3, [r6]
 *   @0x268e88 b 0x268cbc <pcre_compile2+0x12fc>
 *   @0x268e8c mov r3, #107
 *   @0x268e90 strb r3, [r7]
 *   @0x268e94 ldrb r3, [r6]
 *   @0x268e98 b 0x268cbc <pcre_compile2+0x12fc>
 *   @0x268e9c mov r3, #106
 *   @0x268ea0 strb r3, [r7]
 *   @0x268ea4 ldrb r3, [r6]
 *   @0x268ea8 b 0x268cbc <pcre_compile2+0x12fc>
 *   @0x268eac mov r12, #109
 *   @0x268eb0 strb r12, [r7]
 *   @0x268eb4 ldrb r3, [r6]
 *   @0x268eb8 b 0x268cbc <pcre_compile2+0x12fc>
 *   @0x268ebc ldrb r3, [r6]
 *   @0x268ec0 add r3, r3, #9
 *   @0x268ec4 uxtb r3, r3
 *   @0x268ec8 strb r3, [r6]
 *   @0x268ecc b 0x268cbc <pcre_compile2+0x12fc>
 *   @0x268ed0 ldrb r3, [r6]
 *   @0x268ed4 add r3, r3, #7
 *   @0x268ed8 uxtb r3, r3
 *   @0x268edc strb r3, [r6]
 *   @0x268ee0 b 0x268cbc <pcre_compile2+0x12fc>
 *   @0x268ee4 ldrb r3, [r6]
 *   @0x268ee8 add r3, r3, #6
 *   @0x268eec uxtb r3, r3
 *   @0x268ef0 strb r3, [r6]
 *   @0x268ef4 b 0x268cbc <pcre_compile2+0x12fc>
 *   @0x268ef8 ldrb r3, [r6]
 *   @0x268efc add r3, r3, #8
 *   @0x268f00 uxtb r3, r3
 *   @0x268f04 strb r3, [r6]
 *   @0x268f08 b 0x268cbc <pcre_compile2+0x12fc>
 *   @0x268f0c ldrb r3, [r6]
 *   @0x268f10 add r3, r3, #5
 *   @0x268f14 uxtb r3, r3
 *   @0x268f18 strb r3, [r6]
 *   @0x268f1c b 0x268cbc <pcre_compile2+0x12fc>
 *   @0x268f20 add r6, sp, #4672
 *   @0x268f24 mov r2, #21
 *   @0x268f28 add r6, r6, #24
 *   @0x268f2c mov r3, r2
 *   @0x268f30 ldr r1, [r6, r10]
 *   @0x268f34 str r2, [r6, r11]
 *   @0x268f38 rsb r4, r4, r1
 *   @0x268f3c b 0x267d48 <pcre_compile2+0x388>
 *   @0x268f40 add r0, sp, #4672
 *   @0x268f44 movw r3, #0xee4c
 *   @0x268f48 add r0, r0, #24
 *   @0x268f4c movt r3, #0xffff
 *   @0x268f50 mov r2, #10
 *   @0x268f54 str r2, [r0, r3]
 *   @0x268f58 b 0x268774 <pcre_compile2+0xdb4>
 *   @0x268f5c add r1, sp, #4672
 *   @0x268f60 mov r2, #53
 *   @0x268f64 add r1, r1, #24
 *   @0x268f68 str r3, [r1, r11]
 *   @0x268f6c b 0x268768 <pcre_compile2+0xda8>
 *   @0x268f70 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x268f74 bic r6, r6, #7340032
 *   @0x268f78 orr r6, r3, r6
 *   @0x268f7c b 0x267b8c <pcre_compile2+0x1cc>
 *   @0x268f80 mov r0, r5
 *   @0x268f84 b 0x267da4 <pcre_compile2+0x3e4>
 *
 * ══ §5/8 anon_2bb0f8  0x2bb0f8  size 5464  738 条（0x2bb0f8..0x2bc650）｜其中 628 条已由别的卡落锚，本节不再重复
 * @func 0x2bb0f8 0x2bc650  size 5464  738 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2bb0f8+0x2cc×3 / __divsi3×3 / jzero_far×2 / anon_2bb0f8+0x7bc×2 / anon_2bb0f8+0x7c / anon_2bb0f8+0x278 / anon_2bb0f8+0x84 / anon_2bb0f8+0x430
 * 字段偏移 top8: 0x4×56 / 0x8×37 / 0x14×32 / 0xc×29 / 0x18×23 / 0x10×22 / 0x2×19 / 0x28×19
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bb0f8 ldr r2, [r0, #0x1a8]
 *   @0x2bb0fc cmp r3, #0
 *   @0x2bb100 push {r4, r5, r6, r7, r8}
 *   @0x2bb104 ldr r6, [r0, #0x5c]
 *   @0x2bb108 ldr r5, [r2, #0x18]
 *   @0x2bb10c ble 0x2bb174 <jinit_1pass_quantizer+0x444>
 *   @0x2bb110 add r8, r6, r6, lsl #1
 *   @0x2bb114 add r7, r1, r3, lsl #2
 *   @0x2bb118 cmp r6, #0
 *   @0x2bb11c ldr r3, [r1], #4
 *   @0x2bb120 addne r4, r3, r8
 *   @0x2bb124 beq 0x2bb16c <jinit_1pass_quantizer+0x43c>
 *   @0x2bb128 ldrb r12, [r3]
 *   @0x2bb12c add r3, r3, #3
 *   @0x2bb130 ldrb r0, [r3, #-0x2]
 *   @0x2bb134 ldrb r2, [r3, #-0x1]
 *   @0x2bb138 lsr r12, r12, #3
 *   @0x2bb13c lsr r0, r0, #2
 *   @0x2bb140 ldr r12, [r5, r12, lsl #2]
 *   @0x2bb144 lsr r2, r2, #3
 *   @0x2bb148 add r0, r12, r0, lsl #6
 *   @0x2bb14c lsl r2, r2, #1
 *   @0x2bb150 ldrh r12, [r0, r2]
 *   @0x2bb154 add r12, r12, #1
 *   @0x2bb158 uxth r12, r12
 *   @0x2bb15c cmp r12, #0
 *   @0x2bb160 strhne r12, [r0, r2]
 *   @0x2bb164 cmp r3, r4
 *   @0x2bb168 bne 0x2bb128 <jinit_1pass_quantizer+0x3f8>
 *   @0x2bb16c cmp r1, r7
 *   @0x2bb170 bne 0x2bb118 <jinit_1pass_quantizer+0x3e8>
 *   @0x2bb174 pop {r4, r5, r6, r7, r8}
 *   @0x2bb178 bx lr
 *   @0x2bb17c ldr r12, [r0, #0x4]
 *   @0x2bb180 mov r1, #1
 *   @0x2bb184 push {r3, r4, r5, lr}
 *   @0x2bb188 movw r2, #0x7fc
 *   @0x2bb18c ldr r3, [r12]
 *   @0x2bb190 ldr r4, [r0, #0x1a8]
 *   @0x2bb194 blx r3
 *   @0x2bb198 mov r3, #0
 *   @0x2bb19c add r1, r0, #1016
 *   @0x2bb1a0 add r2, r0, #1024
 *   @0x2bb1a4 add r12, r0, #1020
 *   @0x2bb1a8 str r12, [r4, #0x28]
 *   @0x2bb1ac str r3, [r1, #0x4]!
 *   @0x2bb1b0 rsb r12, r3, #0
 *   @0x2bb1b4 add r3, r3, #1
 *   @0x2bb1b8 str r12, [r2, #-0x4]!
 *   @0x2bb1bc cmp r3, #16
 *   @0x2bb1c0 bne 0x2bb1ac <jinit_1pass_quantizer+0x47c>
 *   @0x2bb1c4 add r1, r0, #1072
 *   @0x2bb1c8 add r12, r0, #960
 *   @0x2bb1cc add r1, r1, #8
 *   @0x2bb1d0 mov r2, r3
 *   @0x2bb1d4 add r3, r3, #1
 *   @0x2bb1d8 str r2, [r1, #0x4]!
 *   @0x2bb1dc and r5, r3, #1
 *   @0x2bb1e0 cmp r3, #48
 *   @0x2bb1e4 eor r5, r5, #1
 *   @0x2bb1e8 rsb r4, r2, #0
 *   @0x2bb1ec add r2, r2, r5
 *   @0x2bb1f0 str r4, [r12, #-0x4]!
 *   @0x2bb1f4 bne 0x2bb1d4 <jinit_1pass_quantizer+0x4a4>
 *   @0x2bb1f8 add r3, r0, #1200
 *   @0x2bb1fc add r12, r0, #2032
 *   @0x2bb200 add r1, r0, #832
 *   @0x2bb204 add r3, r3, #8
 *   @0x2bb208 add r12, r12, #8
 *   @0x2bb20c rsb r0, r2, #0
 *   @0x2bb210 str r2, [r3, #0x4]!
 *   @0x2bb214 cmp r3, r12
 *   @0x2bb218 str r0, [r1, #-0x4]!
 *   @0x2bb21c bne 0x2bb210 <jinit_1pass_quantizer+0x4e0>
 *   @0x2bb220 pop {r3, r4, r5, pc}
 *   @0x2bb224 bx lr
 *   @0x2bb228 ldr r3, [r0, #0x1a8]
 *   @0x2bb22c mov r2, #1
 *   @0x2bb230 strb r2, [r3, #0x1c]
 *   @0x2bb234 bx lr
 *   @0x2bb238 push {r3, r4, r5, r6, r7, lr}
 *   @0x2bb23c mov r4, r0
 *   @0x2bb240 ldr r3, [r0, #0x4c]
 *   @0x2bb244 ldr r6, [r0, #0x1a8]
 *   @0x2bb248 cmp r3, #0
 *   @0x2bb24c ldr r5, [r6, #0x18]
 *   @0x2bb250 movne r3, #2
 *   @0x2bb254 strne r3, [r0, #0x4c]
 *   @0x2bb258 cmp r1, #0
 *   @0x2bb25c beq 0x2bb2a4 <jinit_1pass_quantizer+0x574>
 *   @0x2bb260 ldr r2, [pc, #0x148]
 *   @0x2bb264 mov r1, #1
 *   @0x2bb268 ldr r3, [pc, #0x144]
 *   @0x2bb26c add r2, pc, r2
 *   @0x2bb270 strb r1, [r6, #0x1c]
 *   @0x2bb274 add r3, pc, r3
 *   @0x2bb278 stmib r6, {r2, r3}
 *   @0x2bb27c mov r4, #0
 *   @0x2bb280 ldr r0, [r5, r4]
 *   @0x2bb284 mov r1, #4096
 *   @0x2bb288 add r4, r4, #4
 *   @0x2bb28c bl 0x2bc868 <jzero_far>
 *   @0x2bb290 cmp r4, #128
 *   @0x2bb294 bne 0x2bb280 <jinit_1pass_quantizer+0x550>
 *   @0x2bb298 mov r3, #0
 *   @0x2bb29c strb r3, [r6, #0x1c]
 *   @0x2bb2a0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2bb2a4 ldr r2, [r0, #0x4c]
 *   @0x2bb2a8 cmp r2, #2
 *   @0x2bb2ac beq 0x2bb2f4 <jinit_1pass_quantizer+0x5c4>
 *   @0x2bb2b0 ldr r3, [pc, #0x100]
 *   @0x2bb2b4 add r3, pc, r3
 *   @0x2bb2b8 str r3, [r6, #0x4]
 *   @0x2bb2bc ldr r3, [r4, #0x70]
 *   @0x2bb2c0 ldr r1, [pc, #0xf4]
 *   @0x2bb2c4 cmp r3, #0
 *   @0x2bb2c8 add r1, pc, r1
 *   @0x2bb2cc str r1, [r6, #0x8]
 *   @0x2bb2d0 ble 0x2bb370 <jinit_1pass_quantizer+0x640>
 *   @0x2bb2d4 cmp r3, #256
 *   @0x2bb2d8 bgt 0x2bb304 <jinit_1pass_quantizer+0x5d4>
 *   @0x2bb2dc cmp r2, #2
 *   @0x2bb2e0 beq 0x2bb334 <jinit_1pass_quantizer+0x604>
 *   @0x2bb2e4 ldrb r3, [r6, #0x1c]
 *   @0x2bb2e8 cmp r3, #0
 *   @0x2bb2ec popeq {r3, r4, r5, r6, r7, pc}
 *   @0x2bb2f0 b 0x2bb27c <jinit_1pass_quantizer+0x54c>
 *   @0x2bb2f4 ldr r3, [pc, #0xc4]
 *   @0x2bb2f8 add r3, pc, r3
 *   @0x2bb2fc str r3, [r6, #0x4]
 *   @0x2bb300 b 0x2bb2bc <jinit_1pass_quantizer+0x58c>
 *   @0x2bb304 ldr r3, [r4]
 *   @0x2bb308 mov r2, #256
 *   @0x2bb30c mov r1, #57
 *   @0x2bb310 str r2, [r3, #0x18]
 *   @0x2bb314 mov r0, r4
 *   @0x2bb318 ldr r2, [r4]
 *   @0x2bb31c str r1, [r3, #0x14]
 *   @0x2bb320 ldr r3, [r2]
 *   @0x2bb324 blx r3
 *   @0x2bb328 ldr r2, [r4, #0x4c]
 *   @0x2bb32c cmp r2, #2
 *   @0x2bb330 bne 0x2bb2e4 <jinit_1pass_quantizer+0x5b4>
 *   @0x2bb334 ldr r3, [r4, #0x5c]
 *   @0x2bb338 ldr r0, [r6, #0x20]
 *   @0x2bb33c add r3, r3, r3, lsl #1
 *   @0x2bb340 cmp r0, #0
 *   @0x2bb344 lsl r7, r3, #1
 *   @0x2bb348 add r7, r7, #12
 *   @0x2bb34c beq 0x2bb380 <jinit_1pass_quantizer+0x650>
 *   @0x2bb350 mov r1, r7
 *   @0x2bb354 bl 0x2bc868 <jzero_far>
 *   @0x2bb358 ldr r3, [r6, #0x28]
 *   @0x2bb35c cmp r3, #0
 *   @0x2bb360 beq 0x2bb3a4 <jinit_1pass_quantizer+0x674>
 *   @0x2bb364 mov r3, #0
 *   @0x2bb368 strb r3, [r6, #0x24]
 *   @0x2bb36c b 0x2bb2e4 <jinit_1pass_quantizer+0x5b4>
 *   @0x2bb370 ldr r3, [r4]
 *   @0x2bb374 mov r2, #1
 *   @0x2bb378 mov r1, #56
 *   @0x2bb37c b 0x2bb310 <jinit_1pass_quantizer+0x5e0>
 *   @0x2bb380 ldr r3, [r4, #0x4]
 *   @0x2bb384 mov r0, r4
 *   @0x2bb388 mov r1, #1
 *   @0x2bb38c mov r2, r7
 *   @0x2bb390 ldr r3, [r3, #0x4]
 *   @0x2bb394 blx r3
 *   @0x2bb398 mov r3, r0
 *   @0x2bb39c str r3, [r6, #0x20]
 *   @0x2bb3a0 b 0x2bb350 <jinit_1pass_quantizer+0x620>
 *   @0x2bb3a4 mov r0, r4
 *   @0x2bb3a8 bl 0x2bb17c <jinit_1pass_quantizer+0x44c>
 *   @0x2bb3ac b 0x2bb364 <jinit_1pass_quantizer+0x634>
 *   @0x2bb3b0 .word 0xfffffe84
 *   @0x2bb3b4 andeq r0, r0, r4, ror pc
 *   @0x2bb3b8 ldrdeq r0, r1, [r0], -r8
 *   @0x2bb3bc .word 0xffffff54
 *   @0x2bb3c0 andeq r0, r0, r12, ror #22
 *   @0x2bbd94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bbd98 sub sp, sp, #28
 *   @0x2bbd9c cmp r3, #0
 *   @0x2bbda0 str r2, [sp, #0x10]
 *   @0x2bbda4 str r3, [sp, #0x14]
 *   @0x2bbda8 ldr r2, [r0, #0x5c]
 *   @0x2bbdac ldr r3, [r0, #0x1a8]
 *   @0x2bbdb0 str r1, [sp, #0xc]
 *   @0x2bbdb4 str r2, [sp, #0x8]
 *   @0x2bbdb8 ldr r11, [r3, #0x18]
 *   @0x2bbdbc ble 0x2bbe64 <jinit_1pass_quantizer+0x1134>
 *   @0x2bbdc0 mov r10, r11
 *   @0x2bbdc4 mov r11, r0
 *   @0x2bbdc8 mov r9, #0
 *   @0x2bbdcc str r9, [sp, #0x4]
 *   @0x2bbdd0 ldr r3, [sp, #0x8]
 *   @0x2bbdd4 ldr r2, [sp, #0xc]
 *   @0x2bbdd8 cmp r3, #0
 *   @0x2bbddc ldr r3, [sp, #0x10]
 *   @0x2bbde0 ldr r4, [r2, r9]
 *   @0x2bbde4 ldr r8, [r3, r9]
 *   @0x2bbde8 ldrne r5, [sp, #0x8]
 *   @0x2bbdec bne 0x2bbe08 <jinit_1pass_quantizer+0x10d8>
 *   @0x2bbdf0 b 0x2bbe48 <jinit_1pass_quantizer+0x1118>
 *   @0x2bbdf4 subs r5, r5, #1
 *   @0x2bbdf8 sub r12, r12, #1
 *   @0x2bbdfc add r4, r4, #3
 *   @0x2bbe00 strb r12, [r8], #1
 *   @0x2bbe04 beq 0x2bbe48 <jinit_1pass_quantizer+0x1118>
 *   @0x2bbe08 ldrb r1, [r4]
 *   @0x2bbe0c ldrb r2, [r4, #0x1]
 *   @0x2bbe10 ldrb r3, [r4, #0x2]
 *   @0x2bbe14 lsr r1, r1, #3
 *   @0x2bbe18 lsr r2, r2, #2
 *   @0x2bbe1c ldr r7, [r10, r1, lsl #2]
 *   @0x2bbe20 lsr r3, r3, #3
 *   @0x2bbe24 add r7, r7, r2, lsl #6
 *   @0x2bbe28 lsl r6, r3, #1
 *   @0x2bbe2c ldrh r12, [r7, r6]
 *   @0x2bbe30 cmp r12, #0
 *   @0x2bbe34 bne 0x2bbdf4 <jinit_1pass_quantizer+0x10c4>
 *   @0x2bbe38 mov r0, r11
 *   @0x2bbe3c bl 0x2bb8b4 <jinit_1pass_quantizer+0xb84>
 *   @0x2bbe40 ldrh r12, [r7, r6]
 *   @0x2bbe44 b 0x2bbdf4 <jinit_1pass_quantizer+0x10c4>
 *   @0x2bbe48 ldr r2, [sp, #0x4]
 *   @0x2bbe4c add r9, r9, #4
 *   @0x2bbe50 ldr r3, [sp, #0x14]
 *   @0x2bbe54 add r2, r2, #1
 *   @0x2bbe58 str r2, [sp, #0x4]
 *   @0x2bbe5c cmp r2, r3
 *   @0x2bbe60 bne 0x2bbdd0 <jinit_1pass_quantizer+0x10a0>
 *   @0x2bbe64 add sp, sp, #28
 *   @0x2bbe68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bbe6c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bbe70 sub sp, sp, #124
 *   @0x2bbe74 ldr r4, [r0, #0x1a8]
 *   @0x2bbe78 cmp r3, #0
 *   @0x2bbe7c ldr r8, [r0, #0x5c]
 *   @0x2bbe80 str r3, [sp, #0x60]
 *   @0x2bbe84 ldr r9, [r4, #0x18]
 *   @0x2bbe88 ldr r3, [r0, #0x74]
 *   @0x2bbe8c ldr r12, [r4, #0x28]
 *   @0x2bbe90 str r4, [sp, #0x50]
 *   @0x2bbe94 str r8, [sp, #0x48]
 *   @0x2bbe98 ldr r4, [r3]
 *   @0x2bbe9c ldr r8, [r3, #0x4]
 *   @0x2bbea0 str r9, [sp, #0x34]
 *   @0x2bbea4 ldr r3, [r3, #0x8]
 *   @0x2bbea8 ldr r9, [r0, #0x120]
 *   @0x2bbeac str r0, [sp, #0x4c]
 *   @0x2bbeb0 str r12, [sp, #0x68]
 *   @0x2bbeb4 str r4, [sp, #0x38]
 *   @0x2bbeb8 str r8, [sp, #0x3c]
 *   @0x2bbebc str r3, [sp, #0x40]
 *   @0x2bbec0 str r9, [sp, #0xc]
 *   @0x2bbec4 ble 0x2bc1a4 <jinit_1pass_quantizer+0x1474>
 *   @0x2bbec8 ldr r11, [sp, #0x48]
 *   @0x2bbecc sub r2, r2, #4
 *   @0x2bbed0 sub r1, r1, #4
 *   @0x2bbed4 str r2, [sp, #0x5c]
 *   @0x2bbed8 add r3, r11, #1
 *   @0x2bbedc mov r12, #0
 *   @0x2bbee0 add r0, r11, r11, lsl #1
 *   @0x2bbee4 sub r4, r11, #1
 *   @0x2bbee8 add r3, r3, r3, lsl #1
 *   @0x2bbeec sub r2, r0, #3
 *   @0x2bbef0 str r1, [sp, #0x58]
 *   @0x2bbef4 lsl r3, r3, #1
 *   @0x2bbef8 str r2, [sp, #0x6c]
 *   @0x2bbefc str r12, [sp, #0x54]
 *   @0x2bbf00 str r4, [sp, #0x74]
 *   @0x2bbf04 str r3, [sp, #0x70]
 *   @0x2bbf08 ldr r8, [sp, #0x50]
 *   @0x2bbf0c ldr r9, [sp, #0x58]
 *   @0x2bbf10 ldr r12, [sp, #0x5c]
 *   @0x2bbf14 ldrb r3, [r8, #0x24]
 *   @0x2bbf18 ldr r5, [r9, #0x4]!
 *   @0x2bbf1c ldr r11, [r12, #0x4]!
 *   @0x2bbf20 cmp r3, #0
 *   @0x2bbf24 str r9, [sp, #0x58]
 *   @0x2bbf28 str r12, [sp, #0x5c]
 *   @0x2bbf2c str r11, [sp, #0x10]
 *   @0x2bbf30 beq 0x2bc1ac <jinit_1pass_quantizer+0x147c>
 *   @0x2bbf34 ldr r3, [r8, #0x20]
 *   @0x2bbf38 mov r9, #0
 *   @0x2bbf3c ldr r8, [sp, #0x74]
 *   @0x2bbf40 ldr r4, [sp, #0x6c]
 *   @0x2bbf44 add r11, r11, r8
 *   @0x2bbf48 mvn r8, #0
 *   @0x2bbf4c str r8, [sp, #0x64]
 *   @0x2bbf50 add r5, r5, r4
 *   @0x2bbf54 ldr r8, [sp, #0x48]
 *   @0x2bbf58 mvn r4, #2
 *   @0x2bbf5c str r11, [sp, #0x10]
 *   @0x2bbf60 ldr r11, [sp, #0x50]
 *   @0x2bbf64 cmp r8, #0
 *   @0x2bbf68 ldr r12, [sp, #0x70]
 *   @0x2bbf6c str r4, [sp, #0x30]
 *   @0x2bbf70 add r3, r3, r12
 *   @0x2bbf74 strb r9, [r11, #0x24]
 *   @0x2bbf78 str r3, [sp, #0x44]
 *   @0x2bbf7c beq 0x2bc1e0 <jinit_1pass_quantizer+0x14b0>
 *   @0x2bbf80 ldr r9, [sp, #0x30]
 *   @0x2bbf84 mov r7, #0
 *   @0x2bbf88 mov r2, r7
 *   @0x2bbf8c str r7, [sp, #0x18]
 *   @0x2bbf90 str r7, [sp, #0x14]
 *   @0x2bbf94 mov r12, r7
 *   @0x2bbf98 lsl r9, r9, #1
 *   @0x2bbf9c str r7, [sp, #0x2c]
 *   @0x2bbfa0 str r9, [sp, #0x1c]
 *   @0x2bbfa4 mov r9, r7
 *   @0x2bbfa8 str r7, [sp, #0x28]
 *   @0x2bbfac str r7, [sp, #0x24]
 *   @0x2bbfb0 str r7, [sp, #0x20]
 *   @0x2bbfb4 str r8, [sp, #0x8]
 *   @0x2bbfb8 ldr r4, [sp, #0x44]
 *   @0x2bbfbc ldr r7, [sp, #0x68]
 *   @0x2bbfc0 b 0x2bc0a4 <jinit_1pass_quantizer+0x1374>
 *   @0x2bbfc4 ldr r11, [sp, #0x10]
 *   @0x2bbfc8 sub r3, r0, #1
 *   @0x2bbfcc ldr r12, [sp, #0x64]
 *   @0x2bbfd0 strb r3, [r11], r12
 *   @0x2bbfd4 ldr r12, [sp, #0x8]
 *   @0x2bbfd8 str r11, [sp, #0x10]
 *   @0x2bbfdc subs r12, r12, #1
 *   @0x2bbfe0 str r12, [sp, #0x8]
 *   @0x2bbfe4 ldr r12, [sp, #0x38]
 *   @0x2bbfe8 ldr r11, [sp, #0x30]
 *   @0x2bbfec ldrb r2, [r12, r3]
 *   @0x2bbff0 add r5, r5, r11
 *   @0x2bbff4 ldr r11, [sp, #0x3c]
 *   @0x2bbff8 ldr r12, [sp, #0x40]
 *   @0x2bbffc rsb r8, r2, r8
 *   @0x2bc000 ldrb r0, [r11, r3]
 *   @0x2bc004 ldrb r3, [r12, r3]
 *   @0x2bc008 lsl r12, r8, #1
 *   @0x2bc00c ldr r11, [sp, #0x14]
 *   @0x2bc010 rsb r0, r0, r10
 *   @0x2bc014 add r10, r8, r12
 *   @0x2bc018 rsb r3, r3, r9
 *   @0x2bc01c add r11, r10, r11
 *   @0x2bc020 str r11, [sp]
 *   @0x2bc024 ldr r11, [sp, #0x24]
 *   @0x2bc028 add r10, r10, r12
 *   @0x2bc02c lsl r1, r0, #1
 *   @0x2bc030 str r8, [sp, #0x24]
 *   @0x2bc034 add r11, r11, r10
 *   @0x2bc038 ldr r8, [sp]
 *   @0x2bc03c str r11, [sp, #0x14]
 *   @0x2bc040 add r9, r0, r1
 *   @0x2bc044 ldr r11, [sp, #0x18]
 *   @0x2bc048 lsl r2, r3, #1
 *   @0x2bc04c add r12, r10, r12
 *   @0x2bc050 strh r8, [r4]
 *   @0x2bc054 add r10, r9, r11
 *   @0x2bc058 ldr r11, [sp, #0x28]
 *   @0x2bc05c str r0, [sp, #0x28]
 *   @0x2bc060 add r8, r3, r2
 *   @0x2bc064 ldr r0, [sp, #0x20]
 *   @0x2bc068 add r9, r9, r1
 *   @0x2bc06c strh r10, [r4, #2]
 *   @0x2bc070 add r10, r8, r2
 *   @0x2bc074 add r8, r8, r0
 *   @0x2bc078 strh r8, [r4, #4]
 *   @0x2bc07c ldr r8, [sp, #0x2c]
 *   @0x2bc080 add r11, r11, r9
 *   @0x2bc084 add r2, r10, r2
 *   @0x2bc088 str r11, [sp, #0x18]
 *   @0x2bc08c add r10, r8, r10
 *   @0x2bc090 add r9, r9, r1
 *   @0x2bc094 mov r4, r6
 *   @0x2bc098 str r10, [sp, #0x20]
 *   @0x2bc09c str r3, [sp, #0x2c]
 *   @0x2bc0a0 beq 0x2bc150 <jinit_1pass_quantizer+0x1420>
 *   @0x2bc0a4 ldr r11, [sp, #0x1c]
 *   @0x2bc0a8 ldrb r8, [r5]
 *   @0x2bc0ac add r6, r4, r11
 *   @0x2bc0b0 ldrb r0, [r5, #0x2]
 *   @0x2bc0b4 ldrsh r10, [r4, r11]
 *   @0x2bc0b8 ldrsh r3, [r6, #4]
 *   @0x2bc0bc ldrsh r1, [r6, #2]
 *   @0x2bc0c0 add r12, r10, r12
 *   @0x2bc0c4 add r2, r3, r2
 *   @0x2bc0c8 add r12, r12, #8
 *   @0x2bc0cc add r9, r1, r9
 *   @0x2bc0d0 add r2, r2, #8
 *   @0x2bc0d4 add r9, r9, #8
 *   @0x2bc0d8 asr r12, r12, #4
 *   @0x2bc0dc asr r2, r2, #4
 *   @0x2bc0e0 ldrb r3, [r5, #0x1]
 *   @0x2bc0e4 asr r9, r9, #4
 *   @0x2bc0e8 ldr r12, [r7, r12, lsl #2]
 *   @0x2bc0ec ldr r1, [r7, r2, lsl #2]
 *   @0x2bc0f0 ldr r2, [r7, r9, lsl #2]
 *   @0x2bc0f4 ldr r9, [sp, #0xc]
 *   @0x2bc0f8 ldr r11, [sp, #0x34]
 *   @0x2bc0fc add r12, r9, r12
 *   @0x2bc100 add r2, r9, r2
 *   @0x2bc104 add r1, r9, r1
 *   @0x2bc108 ldrb r8, [r12, r8]
 *   @0x2bc10c ldrb r9, [r1, r0]
 *   @0x2bc110 ldrb r10, [r2, r3]
 *   @0x2bc114 asr r1, r8, #3
 *   @0x2bc118 asr r3, r9, #3
 *   @0x2bc11c ldr r12, [r11, r1, lsl #2]
 *   @0x2bc120 asr r2, r10, #2
 *   @0x2bc124 lsl r11, r3, #1
 *   @0x2bc128 add r12, r12, r2, lsl #6
 *   @0x2bc12c ldrh r0, [r12, r11]
 *   @0x2bc130 cmp r0, #0
 *   @0x2bc134 bne 0x2bbfc4 <jinit_1pass_quantizer+0x1294>
 *   @0x2bc138 ldr r0, [sp, #0x4c]
 *   @0x2bc13c str r12, [sp, #0x4]
 *   @0x2bc140 bl 0x2bb8b4 <jinit_1pass_quantizer+0xb84>
 *   @0x2bc144 ldr r12, [sp, #0x4]
 *   @0x2bc148 ldrh r0, [r12, r11]
 *   @0x2bc14c b 0x2bbfc4 <jinit_1pass_quantizer+0x1294>
 *   @0x2bc150 ldr r12, [sp, #0x44]
 *   @0x2bc154 mov r7, r10
 *   @0x2bc158 ldr r9, [sp, #0x1c]
 *   @0x2bc15c uxth r7, r7
 *   @0x2bc160 ldr r11, [sp, #0x48]
 *   @0x2bc164 ldr r4, [sp, #0x14]
 *   @0x2bc168 ldr r8, [sp, #0x18]
 *   @0x2bc16c mla r12, r11, r9, r12
 *   @0x2bc170 uxth r3, r4
 *   @0x2bc174 uxth r10, r8
 *   @0x2bc178 str r12, [sp, #0x44]
 *   @0x2bc17c ldr r9, [sp, #0x54]
 *   @0x2bc180 ldr r12, [sp, #0x60]
 *   @0x2bc184 ldr r11, [sp, #0x44]
 *   @0x2bc188 add r9, r9, #1
 *   @0x2bc18c cmp r9, r12
 *   @0x2bc190 str r9, [sp, #0x54]
 *   @0x2bc194 strh r3, [r11]
 *   @0x2bc198 strh r10, [r11, #2]
 *   @0x2bc19c strh r7, [r11, #4]
 *   @0x2bc1a0 bne 0x2bbf08 <jinit_1pass_quantizer+0x11d8>
 *   @0x2bc1a4 add sp, sp, #124
 *   @0x2bc1a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bc1ac ldr r9, [sp, #0x50]
 *   @0x2bc1b0 mov r11, #3
 *   @0x2bc1b4 ldr r8, [sp, #0x48]
 *   @0x2bc1b8 mov r12, #1
 *   @0x2bc1bc ldr r4, [sp, #0x50]
 *   @0x2bc1c0 mov r0, #1
 *   @0x2bc1c4 ldr r9, [r9, #0x20]
 *   @0x2bc1c8 cmp r8, #0
 *   @0x2bc1cc str r11, [sp, #0x30]
 *   @0x2bc1d0 str r12, [sp, #0x64]
 *   @0x2bc1d4 str r9, [sp, #0x44]
 *   @0x2bc1d8 strb r0, [r4, #0x24]
 *   @0x2bc1dc bne 0x2bbf80 <jinit_1pass_quantizer+0x1250>
 *   @0x2bc1e0 ldr r7, [sp, #0x48]
 *   @0x2bc1e4 mov r10, r7
 *   @0x2bc1e8 mov r3, r7
 *   @0x2bc1ec b 0x2bc17c <jinit_1pass_quantizer+0x144c>
 *   @0x2bc1f0 ldr r3, [r0, #0x1a8]
 *   @0x2bc1f4 mov r1, #1
 *   @0x2bc1f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bc1fc sub sp, sp, #60
 *   @0x2bc200 str r3, [sp, #0x34]
 *   @0x2bc204 ldr r12, [sp, #0x34]
 *   @0x2bc208 ldr r3, [r0, #0x4]
 *   @0x2bc20c str r0, [sp, #0x14]
 *   @0x2bc210 ldr r5, [r12, #0x14]
 *   @0x2bc214 ldr r2, [r12, #0x10]
 *   @0x2bc218 ldr r3, [r3]
 *   @0x2bc21c str r2, [r0, #0x74]
 *   @0x2bc220 lsl r2, r5, #5
 *   @0x2bc224 blx r3
 *   @0x2bc228 mov r3, #0
 *   @0x2bc22c mov r2, #63
 *   @0x2bc230 str r3, [r0]
 *   @0x2bc234 mov r1, r0
 *   @0x2bc238 str r3, [r0, #0x8]
 *   @0x2bc23c mov r4, r0
 *   @0x2bc240 str r3, [r0, #0x10]
 *   @0x2bc244 ldr r3, [sp, #0x14]
 *   @0x2bc248 str r2, [r0, #0xc]
 *   @0x2bc24c mov r2, #31
 *   @0x2bc250 str r2, [r0, #0x4]
 *   @0x2bc254 str r2, [r0, #0x14]
 *   @0x2bc258 ldr r0, [r3, #0x1a8]
 *   @0x2bc25c bl 0x2bb3c4 <jinit_1pass_quantizer+0x694>
 *   @0x2bc260 cmp r5, #1
 *   @0x2bc264 movle r12, #1
 *   @0x2bc268 strle r12, [sp, #0x2c]
 *   @0x2bc26c ble 0x2bc3d4 <jinit_1pass_quantizer+0x16a4>
 *   @0x2bc270 mov r3, #1
 *   @0x2bc274 mov r2, r4
 *   @0x2bc278 mov r6, r3
 *   @0x2bc27c str r3, [sp, #0x2c]
 *   @0x2bc280 cmp r5, r6, lsl #1
 *   @0x2bc284 mov r1, #0
 *   @0x2bc288 mov r3, r4
 *   @0x2bc28c blt 0x2bc39c <jinit_1pass_quantizer+0x166c>
 *   @0x2bc290 mov r0, r1
 *   @0x2bc294 mov lr, r1
 *   @0x2bc298 ldr r12, [r3, #0x1c]
 *   @0x2bc29c add r0, r0, #1
 *   @0x2bc2a0 cmp r12, lr
 *   @0x2bc2a4 ble 0x2bc2b8 <jinit_1pass_quantizer+0x1588>
 *   @0x2bc2a8 ldr r7, [r3, #0x18]
 *   @0x2bc2ac cmp r7, #0
 *   @0x2bc2b0 movgt r1, r3
 *   @0x2bc2b4 movgt lr, r12
 *   @0x2bc2b8 cmp r0, r6
 *   @0x2bc2bc add r3, r3, #32
 *   @0x2bc2c0 blt 0x2bc298 <jinit_1pass_quantizer+0x1568>
 *   @0x2bc2c4 cmp r1, #0
 *   @0x2bc2c8 beq 0x2bc3d0 <jinit_1pass_quantizer+0x16a0>
 *   @0x2bc2cc ldr r3, [r1, #0x4]
 *   @0x2bc2d0 add r7, r2, #32
 *   @0x2bc2d4 str r3, [r2, #0x24]
 *   @0x2bc2d8 ldr r3, [r1, #0xc]
 *   @0x2bc2dc str r3, [r2, #0x2c]
 *   @0x2bc2e0 ldr r3, [r1, #0x14]
 *   @0x2bc2e4 str r3, [r2, #0x34]
 *   @0x2bc2e8 ldr r3, [r1]
 *   @0x2bc2ec str r3, [r2, #0x20]
 *   @0x2bc2f0 ldr r3, [r1, #0x8]
 *   @0x2bc2f4 str r3, [r2, #0x28]
 *   @0x2bc2f8 ldr r3, [r1, #0x10]
 *   @0x2bc2fc str r3, [r2, #0x30]
 *   @0x2bc300 ldr r12, [r1, #0xc]
 *   @0x2bc304 ldr r3, [r1, #0x8]
 *   @0x2bc308 ldr r9, [r1, #0x4]
 *   @0x2bc30c ldr r10, [r1]
 *   @0x2bc310 rsb r0, r3, r12
 *   @0x2bc314 str r12, [sp]
 *   @0x2bc318 rsb r11, r10, r9
 *   @0x2bc31c lsl r12, r0, #3
 *   @0x2bc320 ldr lr, [r1, #0x14]
 *   @0x2bc324 add r12, r12, r0, lsl #2
 *   @0x2bc328 ldr r8, [r1, #0x10]
 *   @0x2bc32c lsl r11, r11, #4
 *   @0x2bc330 cmp r11, r12
 *   @0x2bc334 rsb r0, r8, lr
 *   @0x2bc338 lsl r0, r0, #3
 *   @0x2bc33c ble 0x2bc62c <jinit_1pass_quantizer+0x18fc>
 *   @0x2bc340 cmp r11, r0
 *   @0x2bc344 bge 0x2bc5fc <jinit_1pass_quantizer+0x18cc>
 *   @0x2bc348 add lr, lr, r8
 *   @0x2bc34c add lr, lr, lr, lsr #31
 *   @0x2bc350 asr r3, lr, #1
 *   @0x2bc354 str r3, [r1, #0x14]
 *   @0x2bc358 add r3, r3, #1
 *   @0x2bc35c str r3, [r2, #0x30]
 *   @0x2bc360 ldr r3, [sp, #0x14]
 *   @0x2bc364 add r6, r6, #1
 *   @0x2bc368 ldr r0, [r3, #0x1a8]
 *   @0x2bc36c bl 0x2bb3c4 <jinit_1pass_quantizer+0x694>
 *   @0x2bc370 ldr r12, [sp, #0x14]
 *   @0x2bc374 mov r1, r7
 *   @0x2bc378 ldr r0, [r12, #0x1a8]
 *   @0x2bc37c bl 0x2bb3c4 <jinit_1pass_quantizer+0x694>
 *   @0x2bc380 cmp r6, r5
 *   @0x2bc384 beq 0x2bc3d0 <jinit_1pass_quantizer+0x16a0>
 *   @0x2bc388 cmp r5, r6, lsl #1
 *   @0x2bc38c mov r2, r7
 *   @0x2bc390 mov r1, #0
 *   @0x2bc394 mov r3, r4
 *   @0x2bc398 bge 0x2bc290 <jinit_1pass_quantizer+0x1560>
 *   @0x2bc39c mov r12, r1
 *   @0x2bc3a0 mov r0, r1
 *   @0x2bc3a4 ldr lr, [r3, #0x18]
 *   @0x2bc3a8 add r12, r12, #1
 *   @0x2bc3ac cmp lr, r0
 *   @0x2bc3b0 movle lr, r0
 *   @0x2bc3b4 movgt r1, r3
 *   @0x2bc3b8 cmp r12, r6
 *   @0x2bc3bc add r3, r3, #32
 *   @0x2bc3c0 mov r0, lr
 *   @0x2bc3c4 blt 0x2bc3a4 <jinit_1pass_quantizer+0x1674>
 *   @0x2bc3c8 cmp r1, #0
 *   @0x2bc3cc bne 0x2bc2cc <jinit_1pass_quantizer+0x159c>
 *   @0x2bc3d0 str r6, [sp, #0x2c]
 *   @0x2bc3d4 mov r2, #0
 *   @0x2bc3d8 str r4, [sp, #0x28]
 *   @0x2bc3dc str r2, [sp, #0x30]
 *   @0x2bc3e0 ldr r2, [sp, #0x28]
 *   @0x2bc3e4 ldr r12, [sp, #0x14]
 *   @0x2bc3e8 ldr lr, [sp, #0x28]
 *   @0x2bc3ec ldr r3, [r2, #0x4]
 *   @0x2bc3f0 ldr r2, [r12, #0x1a8]
 *   @0x2bc3f4 ldr lr, [lr]
 *   @0x2bc3f8 ldr r0, [sp, #0x28]
 *   @0x2bc3fc cmp lr, r3
 *   @0x2bc400 ldr r1, [r2, #0x18]
 *   @0x2bc404 str lr, [sp, #0x8]
 *   @0x2bc408 ldr r2, [sp, #0x28]
 *   @0x2bc40c ldr lr, [sp, #0x28]
 *   @0x2bc410 ldr r0, [r0, #0xc]
 *   @0x2bc414 ldr r12, [r2, #0x14]
 *   @0x2bc418 ldr lr, [lr, #0x8]
 *   @0x2bc41c str r0, [sp, #0x18]
 *   @0x2bc420 ldr r11, [r2, #0x10]
 *   @0x2bc424 str lr, [sp, #0x10]
 *   @0x2bc428 str r12, [sp]
 *   @0x2bc42c bgt 0x2bc618 <jinit_1pass_quantizer+0x18e8>
 *   @0x2bc430 add r2, r11, lr, lsl #5
 *   @0x2bc434 ldr r0, [sp, #0x8]
 *   @0x2bc438 mov lr, #0
 *   @0x2bc43c add r3, r3, #1
 *   @0x2bc440 add r6, r12, #1
 *   @0x2bc444 str r3, [sp, #0x24]
 *   @0x2bc448 lsl r3, r2, #1
 *   @0x2bc44c ldr r2, [sp, #0x18]
 *   @0x2bc450 add r1, r1, r0, lsl #2
 *   @0x2bc454 mov r5, lr
 *   @0x2bc458 str r1, [sp, #0x20]
 *   @0x2bc45c mov r4, lr
 *   @0x2bc460 mov r1, lr
 *   @0x2bc464 add r2, r2, #1
 *   @0x2bc468 str lr, [sp, #0xc]
 *   @0x2bc46c str r3, [sp, #0x1c]
 *   @0x2bc470 str r2, [sp, #0x4]
 *   @0x2bc474 ldr r12, [sp, #0x10]
 *   @0x2bc478 ldr r0, [sp, #0x18]
 *   @0x2bc47c cmp r12, r0
 *   @0x2bc480 bgt 0x2bc504 <jinit_1pass_quantizer+0x17d4>
 *   @0x2bc484 ldr r3, [sp, #0x20]
 *   @0x2bc488 ldr r2, [sp, #0xc]
 *   @0x2bc48c ldr r12, [sp, #0x8]
 *   @0x2bc490 ldr r0, [sp, #0x1c]
 *   @0x2bc494 ldr r10, [r3, r2]
 *   @0x2bc498 lsl r8, r12, #3
 *   @0x2bc49c ldr r9, [sp, #0x10]
 *   @0x2bc4a0 add r8, r8, #4
 *   @0x2bc4a4 add r10, r10, r0
 *   @0x2bc4a8 ldr r3, [sp]
 *   @0x2bc4ac mov r0, r10
 *   @0x2bc4b0 cmp r11, r3
 *   @0x2bc4b4 bgt 0x2bc4f0 <jinit_1pass_quantizer+0x17c0>
 *   @0x2bc4b8 lsl r7, r9, #2
 *   @0x2bc4bc mov r3, r11
 *   @0x2bc4c0 add r7, r7, #2
 *   @0x2bc4c4 ldrh r2, [r0], #2
 *   @0x2bc4c8 lsl r12, r3, #3
 *   @0x2bc4cc add r12, r12, #4
 *   @0x2bc4d0 add r3, r3, #1
 *   @0x2bc4d4 cmp r2, #0
 *   @0x2bc4d8 addne r4, r4, r2
 *   @0x2bc4dc mlane r5, r8, r2, r5
 *   @0x2bc4e0 mlane lr, r7, r2, lr
 *   @0x2bc4e4 mlane r1, r12, r2, r1
 *   @0x2bc4e8 cmp r3, r6
 *   @0x2bc4ec bne 0x2bc4c4 <jinit_1pass_quantizer+0x1794>
 *   @0x2bc4f0 ldr r12, [sp, #0x4]
 *   @0x2bc4f4 add r9, r9, #1
 *   @0x2bc4f8 add r10, r10, #64
 *   @0x2bc4fc cmp r9, r12
 *   @0x2bc500 bne 0x2bc4a8 <jinit_1pass_quantizer+0x1778>
 *   @0x2bc504 ldr r0, [sp, #0x8]
 *   @0x2bc508 ldr r3, [sp, #0x24]
 *   @0x2bc50c add r0, r0, #1
 *   @0x2bc510 ldr r2, [sp, #0xc]
 *   @0x2bc514 cmp r0, r3
 *   @0x2bc518 str r0, [sp, #0x8]
 *   @0x2bc51c add r2, r2, #4
 *   @0x2bc520 str r2, [sp, #0xc]
 *   @0x2bc524 bne 0x2bc474 <jinit_1pass_quantizer+0x1744>
 *   @0x2bc528 asr r6, r4, #1
 *   @0x2bc52c add r0, r5, r6
 *   @0x2bc530 add r7, lr, r6
 *   @0x2bc534 add r6, r1, r6
 *   @0x2bc538 ldr r12, [sp, #0x14]
 *   @0x2bc53c mov r1, r4
 *   @0x2bc540 ldr r2, [sp, #0x28]
 *   @0x2bc544 ldr r3, [r12, #0x74]
 *   @0x2bc548 add r2, r2, #32
 *   @0x2bc54c str r2, [sp, #0x28]
 *   @0x2bc550 ldr r5, [r3]
 *   @0x2bc554 bl 0x318d10 <__divsi3>
 *   @0x2bc558 ldr r3, [sp, #0x30]
 *   @0x2bc55c mov r1, r4
 *   @0x2bc560 ldr r12, [sp, #0x14]
 *   @0x2bc564 strb r0, [r5, r3]
 *   @0x2bc568 mov r0, r7
 *   @0x2bc56c ldr r3, [r12, #0x74]
 *   @0x2bc570 ldr r5, [r3, #0x4]
 *   @0x2bc574 bl 0x318d10 <__divsi3>
 *   @0x2bc578 ldr r2, [sp, #0x30]
 *   @0x2bc57c mov r1, r4
 *   @0x2bc580 ldr r12, [sp, #0x14]
 *   @0x2bc584 strb r0, [r5, r2]
 *   @0x2bc588 mov r0, r6
 *   @0x2bc58c ldr r3, [r12, #0x74]
 *   @0x2bc590 ldr r4, [r3, #0x8]
 *   @0x2bc594 bl 0x318d10 <__divsi3>
 *   @0x2bc598 ldr r2, [sp, #0x30]
 *   @0x2bc59c ldr r3, [sp, #0x2c]
 *   @0x2bc5a0 strb r0, [r4, r2]
 *   @0x2bc5a4 add r2, r2, #1
 *   @0x2bc5a8 cmp r2, r3
 *   @0x2bc5ac str r2, [sp, #0x30]
 *   @0x2bc5b0 blt 0x2bc3e0 <jinit_1pass_quantizer+0x16b0>
 *   @0x2bc5b4 ldr r12, [sp, #0x14]
 *   @0x2bc5b8 mov r1, #1
 *   @0x2bc5bc ldr r2, [sp, #0x2c]
 *   @0x2bc5c0 ldr lr, [sp, #0x14]
 *   @0x2bc5c4 ldr r3, [r12]
 *   @0x2bc5c8 mov r12, #96
 *   @0x2bc5cc str r2, [lr, #0x70]
 *   @0x2bc5d0 mov r0, lr
 *   @0x2bc5d4 str r2, [r3, #0x18]
 *   @0x2bc5d8 ldr r2, [lr]
 *   @0x2bc5dc str r12, [r3, #0x14]
 *   @0x2bc5e0 ldr r3, [r2, #0x4]
 *   @0x2bc5e4 blx r3
 *   @0x2bc5e8 ldr r12, [sp, #0x34]
 *   @0x2bc5ec mov r3, #1
 *   @0x2bc5f0 strb r3, [r12, #0x1c]
 *   @0x2bc5f4 add sp, sp, #60
 *   @0x2bc5f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bc5fc add r9, r9, r10
 *   @0x2bc600 add r9, r9, r9, lsr #31
 *   @0x2bc604 asr r3, r9, #1
 *   @0x2bc608 str r3, [r1, #0x4]
 *   @0x2bc60c add r3, r3, #1
 *   @0x2bc610 str r3, [r2, #0x20]
 *   @0x2bc614 b 0x2bc360 <jinit_1pass_quantizer+0x1630>
 *   @0x2bc618 mov r6, #0
 *   @0x2bc61c mov r7, r6
 *   @0x2bc620 mov r0, r6
 *   @0x2bc624 mov r4, r6
 *   @0x2bc628 b 0x2bc538 <jinit_1pass_quantizer+0x1808>
 *   @0x2bc62c cmp r12, r0
 *   @0x2bc630 blt 0x2bc348 <jinit_1pass_quantizer+0x1618>
 *   @0x2bc634 ldr lr, [sp]
 *   @0x2bc638 add r3, lr, r3
 *   @0x2bc63c add r3, r3, r3, lsr #31
 *   @0x2bc640 asr r3, r3, #1
 *   @0x2bc644 str r3, [r1, #0xc]
 *   @0x2bc648 add r3, r3, #1
 *   @0x2bc64c str r3, [r2, #0x28]
 *
 * ══ §6/8 anon_2b389c  0x2b389c  size 1600  196 条（0x2b389c..0x2b3edc）｜其中 204 条已由别的卡落锚，本节不再重复
 * @func 0x2b389c 0x2b3edc  size 1600  196 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jdiv_round_up×7 / __aeabi_uidivmod×3 / anon_2b389c+0x1cc×2 / anon_2b389c+0x180 / anon_2b389c+0xe0 / anon_2b389c+0x1ac / 0xb65bc / anon_2b389c+0x6c
 * 字段偏移 top8: 0x14×13 / 0x1c×8 / 0x24×8 / 0x114×7 / 0x20×7 / 0x190×6 / 0x10×6 / 0x4×6
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b389c ldr r3, [r0, #0x190]
 *   @0x2b38a0 ldr r2, [pc, #0x8]
 *   @0x2b38a4 add r2, pc, r2
 *   @0x2b38a8 str r2, [r3]
 *   @0x2b38ac bx lr
 *   @0x2b38b0 andeq r0, r0, r0, lsl #6
 *   @0x2b38b4 push {r3, r4, r5, lr}
 *   @0x2b38b8 mov r2, #1
 *   @0x2b38bc ldr r3, [r0, #0x190]
 *   @0x2b38c0 mov r5, #0
 *   @0x2b38c4 ldr r1, [pc, #0x38]
 *   @0x2b38c8 mov r4, r0
 *   @0x2b38cc strb r2, [r3, #0x14]
 *   @0x2b38d0 add r1, pc, r1
 *   @0x2b38d4 strb r5, [r3, #0x10]
 *   @0x2b38d8 strb r5, [r3, #0x11]
 *   @0x2b38dc ldr r2, [r0]
 *   @0x2b38e0 str r1, [r3]
 *   @0x2b38e4 ldr r3, [r2, #0x10]
 *   @0x2b38e8 blx r3
 *   @0x2b38ec ldr r3, [r4, #0x194]
 *   @0x2b38f0 mov r0, r4
 *   @0x2b38f4 ldr r3, [r3]
 *   @0x2b38f8 blx r3
 *   @0x2b38fc str r5, [r4, #0x8c]
 *   @0x2b3900 pop {r3, r4, r5, pc}
 *   @0x2b3904 ldrdeq r0, r1, [r0], -r4
 *   @0x2b3908 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b390c mov r5, r0
 *   @0x2b3910 ldr r6, [r0, #0x124]
 *   @0x2b3914 sub sp, sp, #12
 *   @0x2b3918 cmp r6, #1
 *   @0x2b391c beq 0x2b3b28 <jpeg_finish_output+0x338>
 *   @0x2b3920 sub r3, r6, #1
 *   @0x2b3924 cmp r3, #3
 *   @0x2b3928 bhi 0x2b3b80 <jpeg_finish_output+0x390>
 *   @0x2b392c ldr r1, [r5, #0x110]
 *   @0x2b3930 ldr r0, [r5, #0x1c]
 *   @0x2b3934 lsl r1, r1, #3
 *   @0x2b3938 bl 0x2bc7ec <jdiv_round_up>
 *   @0x2b393c ldr r1, [r5, #0x114]
 *   @0x2b3940 lsl r1, r1, #3
 *   @0x2b3944 str r0, [r5, #0x138]
 *   @0x2b3948 ldr r0, [r5, #0x20]
 *   @0x2b394c bl 0x2bc7ec <jdiv_round_up>
 *   @0x2b3950 ldr r2, [r5, #0x124]
 *   @0x2b3954 mov r3, #0
 *   @0x2b3958 str r3, [r5, #0x140]
 *   @0x2b395c cmp r2, r3
 *   @0x2b3960 str r0, [r5, #0x13c]
 *   @0x2b3964 ble 0x2b3a68 <jpeg_finish_output+0x278>
 *   @0x2b3968 mov r8, r3
 *   @0x2b396c mov r4, r3
 *   @0x2b3970 mov r9, r5
 *   @0x2b3974 add r2, r5, #320
 *   @0x2b3978 str r2, [sp, #0x4]
 *   @0x2b397c ldr r6, [r9, #0x128]
 *   @0x2b3980 ldr r7, [r6, #0x8]
 *   @0x2b3984 ldr r10, [r6, #0xc]
 *   @0x2b3988 ldr r2, [r6, #0x24]
 *   @0x2b398c str r7, [r6, #0x34]
 *   @0x2b3990 mov r1, r7
 *   @0x2b3994 mul r11, r10, r7
 *   @0x2b3998 str r10, [r6, #0x38]
 *   @0x2b399c mul r2, r2, r7
 *   @0x2b39a0 ldr r0, [r6, #0x1c]
 *   @0x2b39a4 str r11, [r6, #0x3c]
 *   @0x2b39a8 str r2, [r6, #0x40]
 *   @0x2b39ac bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x2b39b0 ldr r0, [r6, #0x20]
 *   @0x2b39b4 cmp r1, #0
 *   @0x2b39b8 movne r7, r1
 *   @0x2b39bc mov r1, r10
 *   @0x2b39c0 str r7, [r6, #0x44]
 *   @0x2b39c4 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x2b39c8 add r3, r11, r8
 *   @0x2b39cc cmp r1, #0
 *   @0x2b39d0 movne r10, r1
 *   @0x2b39d4 cmp r3, #10
 *   @0x2b39d8 str r10, [r6, #0x48]
 *   @0x2b39dc bgt 0x2b3aa0 <jpeg_finish_output+0x2b0>
 *   @0x2b39e0 cmp r11, #0
 *   @0x2b39e4 sub r0, r11, #1
 *   @0x2b39e8 ble 0x2b3a1c <jpeg_finish_output+0x22c>
 *   @0x2b39ec ldr r1, [r5, #0x140]
 *   @0x2b39f0 ldr r12, [sp, #0x4]
 *   @0x2b39f4 add r2, r11, r1
 *   @0x2b39f8 add r3, r5, r1, lsl #2
 *   @0x2b39fc add r2, r12, r2, lsl #2
 *   @0x2b3a00 add r3, r3, #320
 *   @0x2b3a04 str r4, [r3, #0x4]!
 *   @0x2b3a08 cmp r3, r2
 *   @0x2b3a0c bne 0x2b3a04 <jpeg_finish_output+0x214>
 *   @0x2b3a10 add r1, r1, #1
 *   @0x2b3a14 add r0, r0, r1
 *   @0x2b3a18 str r0, [r5, #0x140]
 *   @0x2b3a1c ldr r6, [r5, #0x124]
 *   @0x2b3a20 add r4, r4, #1
 *   @0x2b3a24 add r9, r9, #4
 *   @0x2b3a28 cmp r4, r6
 *   @0x2b3a2c ldrlt r8, [r5, #0x140]
 *   @0x2b3a30 blt 0x2b397c <jpeg_finish_output+0x18c>
 *   @0x2b3a34 cmp r6, #0
 *   @0x2b3a38 ble 0x2b3a68 <jpeg_finish_output+0x278>
 *   @0x2b3a3c mov r7, r5
 *   @0x2b3a40 mov r4, #0
 *   @0x2b3a44 mov r9, #52
 *   @0x2b3a48 ldr r8, [r7, #0x128]
 *   @0x2b3a4c ldr r3, [r8, #0x4c]
 *   @0x2b3a50 cmp r3, #0
 *   @0x2b3a54 beq 0x2b3abc <jpeg_finish_output+0x2cc>
 *   @0x2b3a58 add r4, r4, #1
 *   @0x2b3a5c add r7, r7, #4
 *   @0x2b3a60 cmp r4, r6
 *   @0x2b3a64 blt 0x2b3a48 <jpeg_finish_output+0x258>
 *   @0x2b3a68 ldr r3, [r5, #0x198]
 *   @0x2b3a6c mov r0, r5
 *   @0x2b3a70 ldr r3, [r3]
 *   @0x2b3a74 blx r3
 *   @0x2b3a78 ldr r3, [r5, #0x188]
 *   @0x2b3a7c mov r0, r5
 *   @0x2b3a80 ldr r3, [r3]
 *   @0x2b3a84 blx r3
 *   @0x2b3a88 ldr r2, [r5, #0x188]
 *   @0x2b3a8c ldr r3, [r5, #0x190]
 *   @0x2b3a90 ldr r2, [r2, #0x4]
 *   @0x2b3a94 str r2, [r3]
 *   @0x2b3a98 add sp, sp, #12
 *   @0x2b3a9c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b3aa0 ldr r3, [r5]
 *   @0x2b3aa4 mov r12, #13
 *   @0x2b3aa8 mov r0, r5
 *   @0x2b3aac str r12, [r3, #0x14]
 *   @0x2b3ab0 ldr r3, [r3]
 *   @0x2b3ab4 blx r3
 *   @0x2b3ab8 b 0x2b39e0 <jpeg_finish_output+0x1f0>
 *   @0x2b3abc ldr r3, [r8, #0x10]
 *   @0x2b3ac0 cmp r3, #3
 *   @0x2b3ac4 add r6, r3, #36
 *   @0x2b3ac8 bhi 0x2b3b08 <jpeg_finish_output+0x318>
 *   @0x2b3acc ldr r2, [r5, r6, lsl #2]
 *   @0x2b3ad0 cmp r2, #0
 *   @0x2b3ad4 beq 0x2b3b08 <jpeg_finish_output+0x318>
 *   @0x2b3ad8 ldr r3, [r5, #0x4]
 *   @0x2b3adc mov r1, #1
 *   @0x2b3ae0 mov r2, #130
 *   @0x2b3ae4 mov r0, r5
 *   @0x2b3ae8 ldr r3, [r3]
 *   @0x2b3aec blx r3
 *   @0x2b3af0 ldr r1, [r5, r6, lsl #2]
 *   @0x2b3af4 mov r2, #130
 *   @0x2b3af8 bl 0xb65bc <memcpy@plt>
 *   @0x2b3afc ldr r6, [r5, #0x124]
 *   @0x2b3b00 str r0, [r8, #0x4c]
 *   @0x2b3b04 b 0x2b3a58 <jpeg_finish_output+0x268>
 *   @0x2b3b08 ldr r2, [r5]
 *   @0x2b3b0c mov r0, r5
 *   @0x2b3b10 str r3, [r2, #0x18]
 *   @0x2b3b14 ldr r3, [r5]
 *   @0x2b3b18 str r9, [r2, #0x14]
 *   @0x2b3b1c ldr r3, [r3]
 *   @0x2b3b20 blx r3
 *   @0x2b3b24 b 0x2b3ad8 <jpeg_finish_output+0x2e8>
 *   @0x2b3b28 ldr r4, [r0, #0x128]
 *   @0x2b3b2c ldr r3, [r4, #0x20]
 *   @0x2b3b30 ldr r7, [r4, #0xc]
 *   @0x2b3b34 ldr r2, [r4, #0x24]
 *   @0x2b3b38 ldr r1, [r4, #0x1c]
 *   @0x2b3b3c str r1, [r0, #0x138]
 *   @0x2b3b40 mov r0, r3
 *   @0x2b3b44 str r3, [r5, #0x13c]
 *   @0x2b3b48 mov r1, r7
 *   @0x2b3b4c str r6, [r4, #0x34]
 *   @0x2b3b50 str r6, [r4, #0x38]
 *   @0x2b3b54 str r6, [r4, #0x3c]
 *   @0x2b3b58 str r6, [r4, #0x44]
 *   @0x2b3b5c str r2, [r4, #0x40]
 *   @0x2b3b60 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x2b3b64 mov r3, #0
 *   @0x2b3b68 cmp r1, r3
 *   @0x2b3b6c movne r7, r1
 *   @0x2b3b70 str r7, [r4, #0x48]
 *   @0x2b3b74 str r6, [r5, #0x140]
 *   @0x2b3b78 str r3, [r5, #0x144]
 *   @0x2b3b7c b 0x2b3a3c <jpeg_finish_output+0x24c>
 *   @0x2b3b80 ldr r3, [r0]
 *   @0x2b3b84 mov r12, #26
 *   @0x2b3b88 mov r1, #4
 *   @0x2b3b8c str r6, [r3, #0x18]
 *   @0x2b3b90 ldr r2, [r0]
 *   @0x2b3b94 str r12, [r3, #0x14]
 *   @0x2b3b98 str r1, [r2, #0x1c]
 *   @0x2b3b9c ldr r3, [r0]
 *   @0x2b3ba0 ldr r3, [r3]
 *   @0x2b3ba4 blx r3
 *   @0x2b3ba8 b 0x2b392c <jpeg_finish_output+0x13c>
 *
 * ══ §7/8 anonT_317ba8  0x317ba8  size 692  31 条（0x317ba8..0x317e5c）｜其中 142 条已由别的卡落锚，本节不再重复
 * @func 0x317ba8 0x317e5c  size 692  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_3187cc+0x68×3 / anon_3187cc+0x4×3 / anon_3187cc+0x28×2 / _Unwind_VRS_Get / 0x6539ec / anon_317a44+0xf4 / anon_317a44+0x10c / anon_3187cc+0x144
 * 字段偏移 top8: 0x10×6 / 0x30×4 / 0x18×4 / 0x14×3 / 0x38×3 / 0x2c×3 / 0x20×2 / 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x317bbc .word 0xf0114500
 *   @0x317bc0 adcsvs r0, r0, r1, lsl #10
 *   @0x317be4 mulls r12, r2, pc
 *   @0x317bec movwhs r8, #0xde
 *   @0x317c08 .word 0xf0020a01
 *   @0x317c0c blls 0x6539ec <g_SWFlinevertbuff+0x924>
 *   @0x317c20 strtmi r0, [r0], -r10, lsl #20
 *   @0x317c34 andls r5, r7, #1024
 *   @0x317c40 .word 0x462080bd
 *   @0x317c50 strtmi r5, [r0], -r1, lsl #22
 *   @0x317c60 ldmdane pc, {r2, r4, r8, r10, r11, r12, sp}
 *   @0x317c78 .word 0x4629fddd
 *   @0x317c90 strbmi r8, [r0], -pc, lsl #1
 *   @0x317cac stcls p0, c8, [r5, #-552]
 *   @0x317cc0 .word 0xf8dd0405
 *   @0x317cc4 strls r11, [r4, #-0x28]
 *   @0x317ccc .word 0x960a7d10
 *   @0x317cec .word 0xf1089c34
 *   @0x317cf0 movwls r0, #0xf358
 *   @0x317d04 blhs 0x318910 <__cxa_call_unexpected+0x248>
 *   @0x317d20 movwls r3, #0xf058
 *   @0x317d38 stcls p0, c8, [r5, #-520]
 *   @0x317d6c teqle r10, r5, lsl #2
 *   @0x317d90 stcls p15, c8, [r5, #-960]
 *   @0x317da0 movwhs r10, #0x2f1f
 *   @0x317dd4 movwhs r2, #0x6300
 *   @0x317e04 blhs 0x318a10 <__cxa_call_unexpected+0x348>
 *   @0x317e14 .word 0xf8cd0240
 *   @0x317e18 .word 0xf7ff8008
 *   @0x317e1c stmdahs r0, {r0, r1, r2, r5, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x317e44 .word 0x9c0b4500
 *
 * ══ §8/8 Buffer_Fast::Write(eBuffer_Type, RValue*)  0xc4c24  size 88  22 条（0xc4c24..0xc4c7c）
 * @func 0xc4c24 0xc4c7c  size 88  22 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x1c×2 / 0x10×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4c24 cmp r1, #1
 *   @0xc4c28 push {r3, r4, r5, lr}
 *   @0xc4c2c mov r3, r0
 *   @0xc4c30 bne 0xc4c6c <_ZN11Buffer_Fast5WriteE12eBuffer_TypeP6RValue+0x48>
 *   @0xc4c34 ldr r4, [r0, #0x1c]
 *   @0xc4c38 ldr r1, [r0, #0x10]
 *   @0xc4c3c cmp r4, r1
 *   @0xc4c40 bge 0xc4c74 <_ZN11Buffer_Fast5WriteE12eBuffer_TypeP6RValue+0x50>
 *   @0xc4c44 mov r0, r2
 *   @0xc4c48 mov r1, #0
 *   @0xc4c4c add r2, r4, #1
 *   @0xc4c50 str r2, [r3, #0x1c]
 *   @0xc4c54 ldr r5, [r3, #0xc]
 *   @0xc4c58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc4c5c mov r3, #0
 *   @0xc4c60 strb r0, [r5, r4]
 *   @0xc4c64 mov r0, r3
 *   @0xc4c68 pop {r3, r4, r5, pc}
 *   @0xc4c6c mvn r3, #3
 *   @0xc4c70 b 0xc4c64 <_ZN11Buffer_Fast5WriteE12eBuffer_TypeP6RValue+0x40>
 *   @0xc4c74 mvn r3, #1
 *   @0xc4c78 b 0xc4c64 <_ZN11Buffer_Fast5WriteE12eBuffer_TypeP6RValue+0x40>
 */
