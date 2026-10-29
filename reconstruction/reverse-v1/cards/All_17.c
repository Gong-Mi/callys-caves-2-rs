/* cally 逆向卡：All_17 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 7 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/7 anon_b6fd0  0xb6fd0  size 14140  3533 条（0xb6fd0..0xba70c）｜其中 2 条已由别的卡落锚，本节不再重复
 * @func 0xb6fd0 0xba70c  size 14140  3533 条
 * 部分覆盖: 本节 3533/3535 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65f8×36 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×9 / 0xb65b0×9 / operator new(unsigned int)×4 / _RefFactory<char const*>::Create(char const*, int&)×4 / anon_25fe2c×3 / cARRAY_OF_POINTERS::setLength(int)×3 / anon_b6fd0+0x2c8c×3
 * 字段偏移 top8: 0x4×48 / 0x8×30 / 0xc×18 / 0x10×11 / 0x5c×10 / 0x18×10 / 0x1c×9 / 0x24×9
 * VFP 指令 62 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xb6fd0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xb6fd4 sub sp, sp, #8
 *   @0xb6fd8 mov r6, r3
 *   @0xb6fdc mov r3, #0
 *   @0xb6fe0 ldr r4, [sp, #0x28]
 *   @0xb6fe4 mov r5, r2
 *   @0xb6fe8 mov r7, r0
 *   @0xb6fec and r9, r2, #2048
 *   @0xb6ff0 mov r8, r1
 *   @0xb6ff4 ldr r10, [r4]
 *   @0xb6ff8 cmp r10, r3
 *   @0xb6ffc beq 0xb7014 <.text+0x44>
 *   @0xb7000 sub r10, r10, #1
 *   @0xb7004 stm sp, {r3, r10}
 *   @0xb7008 add r3, r6, #4
 *   @0xb700c bl 0x25fe2c <_pcre_ord2utf+0x94>
 *   @0xb7010 mov r10, r0
 *   @0xb7014 add r6, r6, #4
 *   @0xb7018 ldr r3, [r4]
 *   @0xb701c cmn r3, #1
 *   @0xb7020 beq 0xb7084 <.text+0xb4>
 *   @0xb7024 mov lr, r4
 *   @0xb7028 mov r4, lr
 *   @0xb702c add lr, lr, #4
 *   @0xb7030 ldm r4, {r3, r12}
 *   @0xb7034 add r3, r3, #1
 *   @0xb7038 cmp r12, r3
 *   @0xb703c beq 0xb7028 <.text+0x58>
 *   @0xb7040 cmn r12, #1
 *   @0xb7044 subne r12, r12, #1
 *   @0xb7048 bne 0xb705c <.text+0x8c>
 *   @0xb704c add r12, r12, #65536
 *   @0xb7050 cmp r9, #0
 *   @0xb7054 movt r12, #0x10
 *   @0xb7058 mvneq r12, #0
 *   @0xb705c str r3, [sp]
 *   @0xb7060 mov r0, r7
 *   @0xb7064 str r12, [sp, #0x4]
 *   @0xb7068 mov r1, r8
 *   @0xb706c mov r2, r5
 *   @0xb7070 mov r3, r6
 *   @0xb7074 bl 0x25fe2c <_pcre_ord2utf+0x94>
 *   @0xb7078 add r4, r4, #4
 *   @0xb707c add r10, r10, r0
 *   @0xb7080 b 0xb7018 <.text+0x48>
 *   @0xb7084 mov r0, r10
 *   @0xb7088 add sp, sp, #8
 *   @0xb708c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xb7090 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xb7094 sub sp, sp, #8
 *   @0xb7098 mov r7, r2
 *   @0xb709c add r6, r3, #4
 *   @0xb70a0 ldr r2, [sp, #0x28]
 *   @0xb70a4 mov r9, r0
 *   @0xb70a8 mov r8, r1
 *   @0xb70ac mov r10, #0
 *   @0xb70b0 ldr r1, [r2]
 *   @0xb70b4 cmn r1, #1
 *   @0xb70b8 beq 0xb7110 <.text+0x140>
 *   @0xb70bc add r12, r2, #4
 *   @0xb70c0 add r0, r1, #1
 *   @0xb70c4 mov lr, #0
 *   @0xb70c8 ldr r3, [r12]
 *   @0xb70cc add r5, r0, lr
 *   @0xb70d0 mov r4, r12
 *   @0xb70d4 add r12, r12, #4
 *   @0xb70d8 cmp r3, r5
 *   @0xb70dc addeq lr, lr, #1
 *   @0xb70e0 beq 0xb70c8 <.text+0xf8>
 *   @0xb70e4 str r1, [sp]
 *   @0xb70e8 mov r0, r9
 *   @0xb70ec ldr r12, [r2, lr, lsl #2]
 *   @0xb70f0 mov r1, r8
 *   @0xb70f4 mov r2, r7
 *   @0xb70f8 mov r3, r6
 *   @0xb70fc str r12, [sp, #0x4]
 *   @0xb7100 bl 0x25fe2c <_pcre_ord2utf+0x94>
 *   @0xb7104 mov r2, r4
 *   @0xb7108 add r10, r10, r0
 *   @0xb710c b 0xb70b0 <.text+0xe0>
 *   @0xb7110 mov r0, r10
 *   @0xb7114 add sp, sp, #8
 *   @0xb7118 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xb711c ldrh r2, [r0, #4]
 *   @0xb7120 mov r3, #0
 *   @0xb7124 str r3, [r0, #0xa0]
 *   @0xb7128 bic r2, r2, #2
 *   @0xb712c str r3, [r0, #0x50]
 *   @0xb7130 str r3, [r0, #0x54]
 *   @0xb7134 str r3, [r0, #0x58]
 *   @0xb7138 strh r2, [r0, #4]
 *   @0xb713c str r3, [r0, #0x5c]
 *   @0xb7140 str r3, [r0, #0x60]
 *   @0xb7144 str r3, [r0, #0x64]
 *   @0xb7148 bx lr
 *   @0xb714c ldrblt r1, [r7, #0x25b]!
 *   @0xb7150 bicsmi r4, r8, #4, #12
 *   @0xb7154 svclt #0xb84283
 *   @0xb7158 .word 0xf8d44603
 *   @0xb715c stcls p1, c0, [r8, #-304]
 *   @0xb7160 strle r0, [r7, #-0x780]
 *   @0xb7164 movweq pc, #0x83c3
 *   @0xb7168 vstrle d2, [r6, #-1020]
 *   @0xb716c .word 0x73fff5c3
 *   @0xb7170 and r3, r2, r1, lsl #6
 *   @0xb7174 svclt #0xa82bff
 *   @0xb7178 .word 0xf8d423ff
 *   @0xb717c qdsublt r6, r8, r6
 *   @0xb7180 andne pc, r0, sp, lsr #17
 *   @0xb7184 .word 0xf88d4610
 *   @0xb7188 mrshs r3, apsr
 *   @0xb718c andpl pc, r2, sp, lsr #17
 *   @0xb7190 .word 0xf8d4466a
 *   @0xb7194 sbfxmi r3, r12, #0x2, #0x11
 *   @0xb7198 .word 0xf8d4e021
 *   @0xb719c blx 0xb76f6 <.text+0x726>
 *   @0xb71a0 .word 0xf8d41112
 *   @0xb71a4 sbcslt r2, r12, #80, #2
 *   @0xb71a8 stchs p8, c1, [r7, #-320]
 *   @0xb71ac ldm pc, {r0, r1, r4, r11, r12, lr, pc} ^
 *   @0xb71b0 andsne pc, r6, r5
 *   @0xb71b4 stmdaeq r10, {r1, r2, r3, r10, r11}
 *   @0xb71b8 andlo r0, r1, r6, lsl #8
 *   @0xb71bc andvc r5, r4, r4, asr r4
 *   @0xb71c0 andvc r3, r4, r1
 *   @0xb71c4 andvc r3, r4, r1
 *   @0xb71c8 andvc r3, r4, r1
 *   @0xb71cc andvc r3, r4, r1
 *   @0xb71d0 andvc r3, r4, r1
 *   @0xb71d4 ldrmi lr, [r9], -r3
 *   @0xb71d8 .word 0xf7ff462a
 *   @0xb71dc andlt lr, r3, r10, ror #19
 *   @0xb71e0 strdeq r11, r12, [r0], -r0
 *   @0xb71e4 movwhs r11, #0x51f
 *   @0xb71e8 movwls r9, #0x3001
 *   @0xb71ec bl 0xfe3751f0 <b2_toiTime+0xfffffffffdc1bd4c>
 *   @0xb71f0 bls 0x1257d8 <_Z20InitGraphicFunctionsv+0x256c>
 *   @0xb71f4 .word 0xf502490a
 *   @0xb71f8 ldrbtmi r7, [r9], #-158
 *   @0xb71fc .word 0xff3cf22e
 *   @0xb7200 .word 0xf8d29a01
 *   @0xb7204 andls r3, r3, r0, lsr #2
 *   @0xb7208 ldrmi r11, [r0], -r11, lsr #18
 *   @0xb720c stc2l p2, c15, [pc, #-200]
 *   @0xb7210 movths lr, #0x1
 *   @0xb7214 stmdals r3, {r0, r1, r8, r9, r12, pc}
 *   @0xb7218 .word 0xf85db005
 *   @0xb721c svclt #0xfb04
 *   @0xb7220 ldrhteq r1, [r3], -r2
 *   @0xb7224 svcmi #0xf0e92d
 *   @0xb7228 .word 0xf8d04604
 *   @0xb722c .word 0xf5ad9114
 *   @0xb7230 .word 0xf8d04d81
 *   @0xb7234 addlt r5, r5, r0, lsl r1
 *   @0xb7238 andeq lr, r9, r5, asr #23
 *   @0xb723c stcle p8, c2, [r8, #-512]
 *   @0xb7240 cmneq pc, r0, lsl #2
 *   @0xb7244 strmi r1, [r8], #-457
 *   @0xb7248 vadd.i32 d19, d1, d1
 *   @0xb724c strmi lr, [r2], r2, ror #26
 *   @0xb7250 .word 0xf04fe001
 *   @0xb7254 .word 0xf10d0a80
 *   @0xb7258 strbmi r0, [sp, #-0x810]
 *   @0xb725c addhi pc, r7, r0, lsl #5
 *   @0xb7260 movweq lr, #0xab05
 *   @0xb7264 strbmi r10, [r11, #-0x924]
 *   @0xb7268 strbmi r11, [r11], -r8, lsr #31
 *   @0xb726c eoreq lr, r8, r8, lsl #17
 *   @0xb7270 movwls r4, #0x2645
 *   @0xb7274 ldm r5, {r0, r1, r8, r12, pc}
 *   @0xb7278 .word 0xf10d0081
 *   @0xb727c .word 0xf8c40e90
 *   @0xb7280 blne 0xff26f718 <b2_toiTime+0xfffffffffeb16274>
 *   @0xb7284 .word 0x463300b2
 *   @0xb7288 ldmdbeq r2, {r0, r1, r2, r3, r9, r12, sp}
 *   @0xb728c .word 0x1102eb0e
 *   @0xb7290 smlawtne r8, r4, r8, pc
 *   @0xb7294 orrmi pc, r0, r6, lsl #2
 *   @0xb7298 addvs pc, r0, #813694976
 *   @0xb729c .word 0xf8c43901
 *   @0xb72a0 andhs r2, r0, #44, #2
 *   @0xb72a4 teqhs r0, r4, asr #17
 *   @0xb72a8 ldrmi r0, [r6], r9, lsl #1
 *   @0xb72ac .word 0xf8d4b133
 *   @0xb72b0 bllo 0xff748 <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xb72b4 and pc, r1, r2, asr #16
 *   @0xb72b8 ldrb r3, [r7, r4, lsl #18]!
 *   @0xb72bc .word 0xf8c42301
 *   @0xb72c0 .word 0xf8c40114
 *   @0xb72c4 strtmi r3, [r0], -r0, lsr #2
 *   @0xb72c8 tstvc r0, r4, asr #17
 *   @0xb72cc .word 0xff8af7ff
 *   @0xb72d0 mrsle r2, spsr
 *   @0xb72d4 ldrsblt pc, [r0, -r4]
 *   @0xb72d8 ldrsblo pc, [r4, -r4]
 *   @0xb72dc ble 0xec8950 <b2_toiTime+0x76f4ac>
 *   @0xb72e0 ldrsblo pc, [r0, -r4]
 *   @0xb72e4 .word 0xf8d42600
 *   @0xb72e8 bl 0xff17b710 <b2_toiTime+0xfffffffffea2226c>
 *   @0xb72ec .word 0xf8d4020b
 *   @0xb72f0 .word 0xf8533124
 *   @0xb72f4 mvnslt r7, r2, lsr #32
 *   @0xb72f8 ldmdavs r11!, {r1, r2, r3, r6, r8, r12, sp, pc}
 *   @0xb72fc stcle p2, c4, [r6, #-556]
 *   @0xb7300 qsaxmi r1, r0, r11
 *   @0xb7304 ldrbmi r9, [r10], -r0, lsl #6
 *   @0xb7308 .word 0xf7ff4633
 *   @0xb730c ldmdavs r11!, {r0, r1, r2, r3, r4, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0xb7310 strbhs lr, [r3], -r6, lsl #22
 *   @0xb7314 bne 0xffd91608 <b2_toiTime+0xffffffffff638164>
 *   @0xb7318 ldmdavs r9!, {r1, r3, r12, lr, pc}
 *   @0xb731c .word 0x2108f8d4
 *   @0xb7320 blle 0x207d6c <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue+0x50>
 *   @0xb7324 strtmi r2, [r0], -r1, lsl #4
 *   @0xb7328 ldrbmi r9, [r10], -r0, lsl #4
 *   @0xb732c .word 0xff0ef7ff
 *   @0xb7330 ldmvs pc!, {r0, r3, r4, r5, r11, sp, lr} ^
 *   @0xb7334 ldrb r3, [lr, r1, lsl #2]
 *   @0xb7338 .word 0xf8d4b146
 *   @0xb733c strtmi r3, [r0], -r12, lsl #2
 *   @0xb7340 bne 0x1788cb0 <b2_toiTime+0x102f80c>
 *   @0xb7344 ldrtmi r9, [r3], -r0, lsl #6
 *   @0xb7348 .word 0xff00f7ff
 *   @0xb734c bleq 0x133780 <_Z9F_CDTrackR6RValueP9CInstanceS2_iPS_+0x4>
 *   @0xb7350 stclo p7, c14, [r4, #-776]
 *   @0xb7354 stmdahs r0, {r0, r1, r2, sp, lr, pc} ^
 *   @0xb7358 rsbsne sp, r6, r11, lsl #2
 *   @0xb735c adcvs sp, pc, r9
 *   @0xb7360 strlo r4, [r4, #-0x437]
 *   @0xb7364 strbmi r6, [r5, #-0x2f]
 *   @0xb7368 stcls p2, c13, [r2, #-532]
 *   @0xb736c andhs lr, r0, r5, ror r7
 *   @0xb7370 andhs lr, r1, r0
 *   @0xb7374 stcmi p5, c15, [r1, #52]
 *   @0xb7378 pop {r0, r2, r12, sp, pc}
 *   @0xb737c ldrlt r8, [r0, #-0xff0]
 *   @0xb7380 bvs 0xfe1d2994 <b2_toiTime+0xfffffffffda794f0>
 *   @0xb7384 bne 0xfe9515f4 <b2_toiTime+0xfffffffffe1f8150>
 *   @0xb7388 bhs 0xbb5d8 <_Z12GLFuncImportb+0xec8>
 *   @0xb738c .word 0x2363da01
 *   @0xb7390 andsle lr, r12, r2, lsr #32
 *   @0xb7394 .word 0xb141611a
 *   @0xb7398 ldmibhi r10, {r0, r1, r7, r8, r10, r11, sp, lr}
 *   @0xb739c svclt #0x4c0711
 *   @0xb73a0 andseq pc, r0, #66
 *   @0xb73a4 eoreq pc, r0, #66
 *   @0xb73a8 bvs 0xfe197a18 <b2_toiTime+0xfffffffffda3e574>
 *   @0xb73ac .word 0xf1036d81
 *   @0xb73b0 addvs r0, r2, #32, #4
 *   @0xb73b4 andhs r6, r0, #549453824
 *   @0xb73b8 stcvs p1, c6, [r3, #104]
 *   @0xb73bc addsvs r6, r10, r2, lsl #21
 *   @0xb73c0 bicvs r6, r11, r3, lsl #27
 *   @0xb73c4 ldrhlo pc, [r4], #-128
 *   @0xb73c8 .word 0xf8a03301
 *   @0xb73cc bvs 0xfe143524 <b2_toiTime+0xfffffffffd9ea080>
 *   @0xb73d0 addsmi r6, r10, #274432
 *   @0xb73d4 .word 0x2362d303
 *   @0xb73d8 andhs r6, r1, r3, asr #5
 *   @0xb73dc movwhs r11, #0xd10
 *   @0xb73e0 subslo pc, r7, r0, lsl #17
 *   @0xb73e4 ldclt p6, c4, [r0, #-96]
 *   @0xb73e8 blvs 0x1e48b0 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x618>
 *   @0xb73ec vmulne.f32 s13, s6, s4
 *   @0xb73f0 blne 0x537688 <obj_numb_event+0x718>
 *   @0xb73f4 blhs 0xc844c <_Z23F_Vertex_Normal_releaseR6RValueP9CInstanceS2_iPS_+0xc>
 *   @0xb73f8 .word 0xf854db19
 *   @0xb73fc adcmi r5, r9, #4, #26
 *   @0xb7400 bllo 0x12dc0c <_Z17F_PathDeletePointR6RValueP9CInstanceS2_iPS_+0x8>
 *   @0xb7404 stcle p7, c14, [r8, #-988]
 *   @0xb7408 blvs 0x1af434 <_ZN5CRoom9SortTilesEv+0x40>
 *   @0xb740c movwlo r6, #0x1a02
 *   @0xb7410 .word 0xf06f6303
 *   @0xb7414 movtmi r0, #0x3003
 *   @0xb7418 ldrdhs r5, r6, [r0], -r1
 *   @0xb741c bl 0x1668e4 <_ZN9CBitmap32C2Eiijji+0x17c>
 *   @0xb7420 bllo 0xf7e34 <_ZN7CFontGM6AssignEPS_+0x38>
 *   @0xb7424 ldmdavs r1, {r2, r3, r9, r10, lr}
 *   @0xb7428 stmdbmi r4, {r1, r6, r11, r12, sp, lr, pc}
 *   @0xb742c bvs 0x11acc18 <b2_toiTime+0xa53774>
 *   @0xb7430 bllo 0x1d1e40 <_Z22HandleInstanceMovementb+0x154>
 *   @0xb7434 addsmi r6, r3, #805306372
 *   @0xb7438 .word 0x2362d8e7
 *   @0xb743c andhs r6, r1, r3, asr #5
 *   @0xb7440 push {r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0xb7444 .word 0x46044ff0
 *   @0xb7448 ldrsbtls pc, [r4], -r0
 *   @0xb744c stmeq r1, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^
 *   @0xb7450 ldrmi r11, [lr], -r5, lsl #1
 *   @0xb7454 movweq lr, #0x8b09
 *   @0xb7458 .word 0xf8d96aa5
 *   @0xb745c andls r0, r3, #4
 *   @0xb7460 bls 0x447f28 <g_RomDisk+0x50708>
 *   @0xb7464 vmov.i16 q11, #0xb
 *   @0xb7468 addsmi r8, r3, #129
 *   @0xb746c stmdavs r7!, {r1, r2, r3, r4, r5, r6, r10, r11, r12, lr, pc} ^
 *   @0xb7470 .word 0x0c00f1c7
 *   @0xb7474 beq 0xf1cac <_ZN18DIALOG_REQ_CONTEXTD2Ev+0x4>
 *   @0xb7478 svclt #0xb84552
 *   @0xb747c adcsmi r4, r3, #153092096
 *   @0xb7480 ldmibne r8, {r0, r2, r4, r8, r9, r11, r12, lr, pc} ^
 *   @0xb7484 eorsmi r3, r11, r1, lsl #30
 *   @0xb7488 b 0xc5494 <_Z13F_BUFFER_ReadR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0xb748c andslt r0, r11, #12
 *   @0xb7490 .word 0xf894b97b
 *   @0xb7494 tstlt r2, r7, asr r0
 *   @0xb7498 .word 0xf8843d04
 *   @0xb749c .word 0xf8593057
 *   @0xb74a0 strlo r3, [r4, #-0x31]
 *   @0xb74a4 .word 0x3c04f845
 *   @0xb74a8 strmi r6, [r6], #-2150
 *   @0xb74ac ldrtmi lr, [r0], -r2
 *   @0xb74b0 strmi lr, [r6], -r0
 *   @0xb74b4 .word 0x3056f894
 *   @0xb74b8 stcvs p1, c11, [r3, #236]!
 *   @0xb74bc blx 0x10d154c <b2_toiTime+0x9780a8>
 *   @0xb74c0 cmpvs r10, r2, lsl #4
 *   @0xb74c4 .word 0xf8842300
 *   @0xb74c8 ldrmi r3, [r2, #0x56]!
 *   @0xb74cc stmdavs r3!, {r1, r2, r3, r6, r8, r9, r11, r12, lr, pc}
 *   @0xb74d0 andeq lr, r10, #202752
 *   @0xb74d4 bvs 0x1987944 <b2_toiTime+0x122e4a0>
 *   @0xb74d8 bl 0x203ce4 <_ZN7CDS_Map8FindLastEv+0x20>
 *   @0xb74dc addsmi r0, r3, #536870920
 *   @0xb74e0 .word 0x2362d804
 *   @0xb74e4 rscvs r6, r3, #1342177290
 *   @0xb74e8 sub r2, r5, r1
 *   @0xb74ec .word 0xf04f464f
 *   @0xb74f0 .word 0xf04f0b01
 *   @0xb74f4 .word 0xf8840300
 *   @0xb74f8 ldmdavs r9!, {r0, r1, r2, r4, r6, r12, sp} ^
 *   @0xb74fc stcle p2, c4, [r6, #-708]!
 *   @0xb7500 andeq lr, r8, #7168
 *   @0xb7504 .word 0xf8d26923
 *   @0xb7508 bl 0xff46f520 <b2_toiTime+0xfffffffffed1607c>
 *   @0xb750c addsmi r0, r9, #1073741824
 *   @0xb7510 ldrtmi sp, [r8], -r6, lsl #22
 *   @0xb7514 blls 0x19bd20 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1428>
 *   @0xb7518 bls 0x109380 <_Z15F_CollisionLineR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xb751c eor r4, r1, r7, lsl r6
 *   @0xb7520 andlo pc, r8, r7, asr r8
 *   @0xb7524 vmlseq.f64 d14, d22, d14
 *   @0xb7528 stcne p8, c6, [r10, #-224]!
 *   @0xb752c bl 0xff2dbd38 <b2_toiTime+0xfffffffffeb82894>
 *   @0xb7530 bne 0xff0b9154 <b2_toiTime+0xfffffffffe95fcb0>
 *   @0xb7534 blx 0x45c146 <g_RomDisk+0x64926>
 *   @0xb7538 vhadd.s32 d31, d1, d0
 *   @0xb753c blls 0x1724ec <_Z7SetFontv+0x8>
 *   @0xb7540 eorvs r4, r8, r8, lsl r4
 *   @0xb7544 stmdavs r3!, {r0, r9, r11, r12, pc} ^
 *   @0xb7548 ldrmi r4, [lr], #-1557
 *   @0xb754c mrsle lr, apsr
 *   @0xb7550 subslt pc, r7, r4, lsl #17
 *   @0xb7554 ldmdavs r11!, {r2, r8, r10, r12, sp}
 *   @0xb7558 .word 0x3c04f845
 *   @0xb755c ldrmi r6, [lr], #-2147
 *   @0xb7560 streq lr, [r7, -r8, asr #23]
 *   @0xb7564 movwle r4, #0x154f
 *   @0xb7568 stclle p5, c4, [r2, #344]
 *   @0xb756c andhs r6, r0, r3, ror #22
 *   @0xb7570 bl 0xff2d000c <b2_toiTime+0xfffffffffeb76b68>
 *   @0xb7574 .word 0x63630303
 *   @0xb7578 pop {r0, r2, r12, sp, pc}
 *   @0xb757c ldrblt r8, [r3, #-0xff0]!
 *   @0xb7580 blvs 0x11c8d9c <b2_toiTime+0xa6f8f8>
 *   @0xb7584 stmdavs r0!, {r1, r8, r11, sp} ^
 *   @0xb7588 andeq pc, r0, r0, asr #3
 *   @0xb758c stmvs r0!, {r5, r6, sp, lr} ^
 *   @0xb7590 andeq pc, r0, r0, asr #3
 *   @0xb7594 stmdbvs r0!, {r5, r6, r7, sp, lr} ^
 *   @0xb7598 andeq pc, r0, r0, asr #3
 *   @0xb759c stcle p1, c6, [r2, #-384]
 *   @0xb75a0 submi r6, r0, #224, #18
 *   @0xb75a4 subsmi r6, r11, #224, #2
 *   @0xb75a8 blls 0x25c1b0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1088>
 *   @0xb75ac .word 0xf8954628
 *   @0xb75b0 subsmi r6, r11, #86
 *   @0xb75b4 .word 0xff45f7ff
 *   @0xb75b8 .word 0xf895b136
 *   @0xb75bc ldmdblt r11, {r1, r2, r4, r6, r12, sp}
 *   @0xb75c0 ldmdbvs r10, {r0, r1, r3, r5, r7, r8, r10, r11, sp, lr} ^
 *   @0xb75c4 cmpvs r10, r2, asr r2
 *   @0xb75c8 subsmi r6, r11, #6488064
 *   @0xb75cc andlt r6, r2, r3, rrx
 *   @0xb75d0 ldrlt r11, [r0, #-0xd70]
 *   @0xb75d4 stmdavs r3, {r2, r3, r11, sp, lr}
 *   @0xb75d8 ldmdavs r10, {r0, r1, r3, r5, r8, r12, sp, pc}
 *   @0xb75dc blle 0x148034 <_Z20F_GPUGetBlendModeExtR6RValueP9CInstanceS2_iPS_+0x14>
 *   @0xb75e0 ldmdavs r11, {r3, r4, r8, r10, r11, r12} ^
 *   @0xb75e4 strdvs lr, pc, [r11], #-120
 *   @0xb75e8 ldclt p0, c6, [r0, #-4]
 *   @0xb75ec teqlt r11, r3, lsl #16
 *   @0xb75f0 smlabble r2, r11, r2, r4
 *   @0xb75f4 andvs r6, r3, r11, asr r8
 *   @0xb75f8 ldcne p7, c4, [r8, #-448]
 *   @0xb75fc ubfx r6, r11, #0x10, #0x17
 *   @0xb7600 stmdavs r3, {r4, r5, r6, r8, r9, r10, lr}
 *   @0xb7604 orrlt r11, r3, r0, lsr r5
 *   @0xb7608 ldmdavs r1, {r1, r3, r4, r7, r11, sp, lr}
 *   @0xb760c ldmibhi r9, {r0, r3, r4, sp, lr}
 *   @0xb7610 svceq #0x8f011
 *   @0xb7614 .word 0xf06fbf0c
 *   @0xb7618 .word 0x21040103
 *   @0xb761c addsvs r4, r10, r10, lsl #8
 *   @0xb7620 blo 0x111a90 <_Z16F_PointDirectionR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0xb7624 ldmdavs r11, {r1, r3, r4, r8, sp, lr} ^
 *   @0xb7628 stmdavs r3, {r0, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0xb762c ldmdavs r10, {r0, r1, r4, r7, r8, r12, sp, pc} ^
 *   @0xb7630 cmnlt r10, r1, lsl #12
 *   @0xb7634 ldmdavs r4, {r0, r2, r3, r4, r11, sp, lr}
 *   @0xb7638 .word 0xdc0342a5
 *   @0xb763c ldmdavs r11, {r0, r3, r4, r8, r10, r11, r12} ^
 *   @0xb7640 ldclt p9, c11, [r0, #-204]!
 *   @0xb7644 ldmdavs r1, {r1, r3, sp, lr} ^
 *   @0xb7648 .word 0x46016059
 *   @0xb764c stmdavs r3, {r0, r1, r4, r6, sp, lr}
 *   @0xb7650 ubfx r6, r10, #0x10, #0xf
 *   @0xb7654 push {r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0xb7658 .word 0x460447f0
 *   @0xb765c .word 0x9020f8dd
 *   @0xb7660 .word 0xf8dd460d
 *   @0xb7664 bl 0xff1576fc <b2_toiTime+0xfffffffffe9fe258>
 *   @0xb7668 .word 0xf8dd0609
 *   @0xb766c cdphs p0, #0x0, c10, c0, c8, #0x1
 *   @0xb7670 addhi pc, r12, r0, asr #6
 *   @0xb7674 .word 0xf2c045c1
 *   @0xb7678 ldrbmi r8, [r2, #-0x89]
 *   @0xb767c addhi pc, r6, r0, lsl #6
 *   @0xb7680 bl 0xff108b90 <b2_toiTime+0xfffffffffe9af6ec>
 *   @0xb7684 ble 0x379298 <_ZTS13C_UTF16String+0x10344>
 *   @0xb7688 smlabteq r8, r2, r11, lr
 *   @0xb768c shasxmi r4, r2, r8
 *   @0xb7690 blx 0x15f3f4e <b2_toiTime+0xe9aaaa>
 *   @0xb7694 andhs r6, r0, #2293760
 *   @0xb7698 .word 0xf803fa48
 *   @0xb769c and r4, r5, r5, lsl #8
 *   @0xb76a0 blx 0x11516b4 <b2_toiTime+0x9f8210>
 *   @0xb76a4 stmdavs r3, {r0, r1, r11, r12, sp, lr, pc} ^
 *   @0xb76a8 andsmi r3, r10, r1, lsl #22
 *   @0xb76ac stmdavs r3!, {r0, r4, r6, r7, r8, r10, lr}
 *   @0xb76b0 blx 0x136eac8 <b2_toiTime+0xc15624>
 *   @0xb76b4 .word 0xf04ffa03
 *   @0xb76b8 and r0, r5, r0, lsl #18
 *   @0xb76bc blx 0x1b5fe8 <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0xa4>
 *   @0xb76c0 bllo 0x111854 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1b0>
 *   @0xb76c4 stmdbeq r3, {r0, r3, r9, r11, sp, lr, pc}
 *   @0xb76c8 vstrle s4, [r11, #-0]
 *   @0xb76cc ldrsble r4, [sp], #-80
 *   @0xb76d0 ldrtmi r6, [r8], -r1, ror #16
 *   @0xb76d4 stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0xb76d8 ldrtmi r1, [r2], -r9, lsl #21
 *   @0xb76dc blx 0xc73f9a <b2_toiTime+0x51aaf6>
 *   @0xb76e0 and r4, r5, r5, lsl #8
 *   @0xb76e4 .word 0x3057f894
 *   @0xb76e8 bvs 0xfe9a3b3c <b2_toiTime+0xfffffffffe24a698>
 *   @0xb76ec adcvs r3, r3, #4, #22
 *   @0xb76f0 stmdbeq r1, {r0, r3, r4, r6, r7, r8, r12, sp, lr, pc}
 *   @0xb76f4 .word 0x3056f894
 *   @0xb76f8 .word 0xf04fbf38
 *   @0xb76fc .word 0xf8840900
 *   @0xb7700 qsublt r9, r7, r11
 *   @0xb7704 .word 0xf8c36da3
 *   @0xb7708 movwhs r8, #0x14
 *   @0xb770c subslo pc, r6, r4, lsl #17
 *   @0xb7710 stmdaeq r10, {r3, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0xb7714 .word 0xf1086aa3
 *   @0xb7718 bl 0x179724 <_Z15GR_3D_Draw_Wallffffffiff+0x44>
 *   @0xb771c bvs 0x1978144 <b2_toiTime+0x121eca0>
 *   @0xb7720 stmdale r4, {r0, r1, r4, r7, r9, lr}
 *   @0xb7724 andhs r2, r1, r2, ror #6
 *   @0xb7728 pop {r0, r1, r5, r6, r7, r9, sp, lr}
 *   @0xb772c svchs #0x87f0
 *   @0xb7730 ldrtmi sp, [r9], -r12, lsl #26
 *   @0xb7734 stmdavs r0!, {r1, r4, r5, r9, r10, lr} ^
 *   @0xb7738 blx 0x16f3ff6 <b2_toiTime+0xf9ab52>
 *   @0xb773c .word 0x46814631
 *   @0xb7740 cmnmi r8, #96, #16
 *   @0xb7744 bl 0x15740d0 <b2_toiTime+0xe1ac2c>
 *   @0xb7748 and r2, lr, r1
 *   @0xb774c shsub16mi r4, r2, pc
 *   @0xb7750 ldrtmi r6, [r9], -r0, ror #16
 *   @0xb7754 blx 0x1374012 <b2_toiTime+0xc1ab6e>
 *   @0xb7758 .word 0xf1c04631
 *   @0xb775c stmdavs r0!, {r8, r11} ^
 *   @0xb7760 .word 0xf2614378
 *   @0xb7764 .word 0xf04feb44
 *   @0xb7768 bvs 0xfe943b6c <b2_toiTime+0xfffffffffe1ea6c8>
 *   @0xb776c .word 0xf1b84273
 *   @0xb7770 stcle p15, c0, [r10, #-0]
 *   @0xb7774 .word 0xf842185b
 *   @0xb7778 strbmi r5, [sp], #-2820
 *   @0xb777c bl 0xff2674f4 <b2_toiTime+0xfffffffffeb0e050>
 *   @0xb7780 stmdane sp!, {r0, r1, r8, r9}
 *   @0xb7784 ldmlo pc!, {r3, r8, r12, sp, lr, pc} ^
 *   @0xb7788 adcvs lr, r2, #63176704
 *   @0xb778c ldm sp!, {sp}
 *   @0xb7790 ldrlt r8, [r0, #-0x7f0]!
 *   @0xb7794 stmdblt r3!, {r0, r1, r6, r7, r8, r10, r11, sp, lr}
 *   @0xb7798 strvs r6, [r3, #0xa83]
 *   @0xb779c .word 0x332065c3
 *   @0xb77a0 bvs 0xfe1d01b4 <b2_toiTime+0xfffffffffda76d10>
 *   @0xb77a4 addsmi r6, r12, #274432
 *   @0xb77a8 .word 0x2362d301
 *   @0xb77ac stcvs p0, c14, [r4, #164]
 *   @0xb77b0 stmdbhs r1, {r8, r9, sp}
 *   @0xb77b4 stcvs p1, c8, [r4, #652]
 *   @0xb77b8 stcvs p1, c6, [r4, #396]
 *   @0xb77bc stcvs p1, c6, [r4, #140]
 *   @0xb77c0 adcvs r6, r5, r5, lsl #21
 *   @0xb77c4 rsbvs r6, r3, r4, lsl #27
 *   @0xb77c8 mvnvs r6, r4, lsl #27
 *   @0xb77cc .word 0xf8906d83
 *   @0xb77d0 ldrhhi r4, [r12, r0]
 *   @0xb77d4 stmdbhs r2, {r1, r12, lr, pc}
 *   @0xb77d8 ands sp, r1, r11
 *   @0xb77dc ldmibhi r12, {r0, r1, r7, r8, r10, r11, sp, lr}
 *   @0xb77e0 streq pc, [r8], #-68
 *   @0xb77e4 .word 0xb17a819c
 *   @0xb77e8 ldmibhi r10, {r0, r1, r7, r8, r10, r11, sp, lr}
 *   @0xb77ec eoreq pc, r0, #66
 *   @0xb77f0 mrslt lr, spsr
 *   @0xb77f4 ldmibhi r10, {r0, r1, r7, r8, r10, r11, sp, lr}
 *   @0xb77f8 andseq pc, r0, #66
 *   @0xb77fc mul r3, r10, r1
 *   @0xb7800 sbcvs r2, r3, #20, #6
 *   @0xb7804 ldclt p0, c2, [r0, #-4]!
 *   @0xb7808 stmdblt r11, {r0, r1, r9, r10, r11, sp, lr}
 *   @0xb780c strvs r6, [r3], -r3, lsl #27
 *   @0xb7810 .word 0xf8802301
 *   @0xb7814 movwhs r3, #0x56
 *   @0xb7818 .word 0xf8806641
 *   @0xb781c ssaxmi r3, r8, r7
 *   @0xb7820 andeq r11, r0, r0, lsr sp
 *   @0xb7824 svcmi #0xf7e92d
 *   @0xb7828 .word 0xf1004604
 *   @0xb782c movtvs r0, #0x66b4
 *   @0xb7830 .word 0xf8df6c40
 *   @0xb7834 .word 0xf8df80f4
 *   @0xb7838 .word 0xf8c490f4
 *   @0xb783c ldrbtmi r0, [r8], #196
 *   @0xb7840 ldrbtmi r6, [r9], #3232
 *   @0xb7844 adcslo pc, r4, r4, asr #17
 *   @0xb7848 .word 0xf8c49b0c
 *   @0xb784c .word 0xf8c400c8
 *   @0xb7850 .word 0xf8c410bc
 *   @0xb7854 .word 0xf8c420c0
 *   @0xb7858 blvs 0x18c3b40 <b2_toiTime+0x116a69c>
 *   @0xb785c stmdavs r5, {r0, r1, r6, r8, r11, sp, lr} ^
 *   @0xb7860 adcmi r6, r11, #12648448
 *   @0xb7864 svclt #0xd96807
 *   @0xb7868 ldrmi r4, [r12], r10, lsr #12
 *   @0xb786c ssatmi r4, #0xd, r10, lsl #12
 *   @0xb7870 blle 0x108dfc <_Z15F_MpGridGetCellR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0xb7874 stcle p2, c4, [r5, #-580]
 *   @0xb7878 ldc2 p2, c15, [lr, #232]!
 *   @0xb787c tstlo r0, #101376
 *   @0xb7880 sub r6, r8, r3, ror #6
 *   @0xb7884 smlatble r2, r11, r2, r4
 *   @0xb7888 .word 0x63603810
 *   @0xb788c cdpvs p0, #0x6, c14, c1, c3, #0x2
 *   @0xb7890 .word 0xf04fbfb4
 *   @0xb7894 .word 0xf04f0a01
 *   @0xb7898 ldrbmi r0, [r1, #-0xa02]
 *   @0xb789c .word 0xf1bad10b
 *   @0xb78a0 stcvs p15, c0, [r3, #-4]!
 *   @0xb78a4 movwls sp, #0x12e
 *   @0xb78a8 .word 0x21024620
 *   @0xb78ac stclvs p6, c4, [r3], #296
 *   @0xb78b0 stc2l p7, c15, [r7, #1020]
 *   @0xb78b4 .word 0xf1bae02d
 *   @0xb78b8 stmdavs r2!, {r0, r8, r9, r10, r11} ^
 *   @0xb78bc smlatble r8, r0, r8, r6
 *   @0xb78c0 bleq 0x1724d4 <_Z15MakeDefaultFontv+0x6c>
 *   @0xb78c4 .word 0xf10b4252
 *   @0xb78c8 b 0x3868cc <_ZTS13C_UTF16String+0x1d978>
 *   @0xb78cc bne 0xff5780dc <b2_toiTime+0xfffffffffee1ec38>
 *   @0xb78d0 blo 0x12f8dc <_Z13F_SoundDeleteR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xb78d4 addmi r4, r3, #19
 *   @0xb78d8 .word 0xf04fbfb4
 *   @0xb78dc .word 0xf04f0b00
 *   @0xb78e0 ldmdblt r9!, {r0, r8, r9, r11}
 *   @0xb78e4 ldrbmi r4, [r1], -r0, lsr #12
 *   @0xb78e8 .word 0xf7ff465a
 *   @0xb78ec stmdahs r0, {r1, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0xb78f0 ldrd sp, lr, [r5], -r5
 *   @0xb78f4 ldrbmi r4, [r9], -r0, lsr #12
 *   @0xb78f8 stc2l p7, c15, [r1, #-1020]
 *   @0xb78fc rscsle r2, r1, r0, lsl #16
 *   @0xb7900 and r2, lr, r1
 *   @0xb7904 strtmi r9, [r0], -r0, lsl #6
 *   @0xb7908 strbmi r2, [r2], -r2, lsl #2
 *   @0xb790c .word 0xf7ff6ce3
 *   @0xb7910 stmdahs r0, {r1, r2, r4, r5, r9, r10, r11, r12, sp, lr, pc}
 *   @0xb7914 blvs 0x19ac0ec <b2_toiTime+0x1252c48>
 *   @0xb7918 addsle r4, lr, #805306379
 *   @0xb791c strbtvs r2, [r7], #-0
 *   @0xb7920 andlt r6, r3, r5, lsr #9
 *   @0xb7924 svchi #0xf0e8bd
 *   @0xb7928 .word 0x0023abb7
 *   @0xb792c .word 0x0023abb3
 *   @0xb7930 svcmi #0xf7e92d
 *   @0xb7934 .word 0xf1004604
 *   @0xb7938 movtvs r0, #0x66b4
 *   @0xb793c .word 0xf8c46c40
 *   @0xb7940 blls 0x3c3c38 <error_g0017+0x1c8dc>
 *   @0xb7944 .word 0x8104f8df
 *   @0xb7948 .word 0x9104f8df
 *   @0xb794c sbclo pc, r0, r4, asr #17
 *   @0xb7950 blls 0x408d38 <g_RomDisk+0x11518>
 *   @0xb7954 .word 0xf8c444f9
 *   @0xb7958 stcvs p0, c0, [r0], #816
 *   @0xb795c adcslo pc, r4, r4, asr #17
 *   @0xb7960 .word 0xf8c49b0e
 *   @0xb7964 .word 0xf8c400d0
 *   @0xb7968 .word 0xf8c410c4
 *   @0xb796c .word 0xf8c420c8
 *   @0xb7970 blvs 0x18c3c58 <b2_toiTime+0x116a7b4>
 *   @0xb7974 stmdavs r5, {r0, r1, r6, r7, r8, r11, sp, lr} ^
 *   @0xb7978 adcmi r6, r11, #1081344
 *   @0xb797c stmdavs r7, {r0, r6, r7, r11, sp, lr}
 *   @0xb7980 ssatmi r11, #0xd, r9, asr #31
 *   @0xb7984 .word 0x469c469a
 *   @0xb7988 addmi r4, r10, #178257920
 *   @0xb798c strmi sp, [r11], r2, lsl #24
 *   @0xb7990 uadd16mi r4, r10, r1
 *   @0xb7994 blle 0x108ee0 <_Z20F_MpGridAddInstancesR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0xb7998 stcle p5, c4, [r5, #-392]
 *   @0xb799c ldc2l p2, c15, [r3, #-232]
 *   @0xb79a0 tstlo r8, #101376
 *   @0xb79a4 sub r6, r8, r3, ror #6
 *   @0xb79a8 smlatble r2, r11, r2, r4
 *   @0xb79ac .word 0x63603818
 *   @0xb79b0 cdpvs p0, #0x6, c14, c1, c3, #0x2
 *   @0xb79b4 .word 0xf04fbfd4
 *   @0xb79b8 .word 0xf04f0a01
 *   @0xb79bc ldrbmi r0, [r1, #-0xa02]
 *   @0xb79c0 .word 0xf1bad10b
 *   @0xb79c4 stcvs p15, c0, [r3, #-4]!
 *   @0xb79c8 movwls sp, #0x12e
 *   @0xb79cc .word 0x21034620
 *   @0xb79d0 stclvs p6, c4, [r3], #296
 *   @0xb79d4 ldc2 p7, c15, [r5, #-1020]!
 *   @0xb79d8 .word 0xf1bae02d
 *   @0xb79dc stmdavs r2!, {r0, r8, r9, r10, r11} ^
 *   @0xb79e0 smlatble r8, r0, r8, r6
 *   @0xb79e4 bleq 0x1725f8 <_Z15Split_TextBlockPKciP11TStringList+0x98>
 *   @0xb79e8 .word 0xf10b4252
 *   @0xb79ec b 0x3869f0 <_ZTS13C_UTF16String+0x1da9c>
 *   @0xb79f0 bne 0xff578200 <b2_toiTime+0xfffffffffee1ed5c>
 *   @0xb79f4 blo 0x12fa00 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x8>
 *   @0xb79f8 addmi r4, r3, #19
 *   @0xb79fc .word 0xf04fbfb4
 *   @0xb7a00 .word 0xf04f0b00
 *   @0xb7a04 ldmdblt r9!, {r0, r8, r9, r11}
 *   @0xb7a08 ldrbmi r4, [r1], -r0, lsr #12
 *   @0xb7a0c .word 0xf7ff465a
 *   @0xb7a10 stmdahs r0, {r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0xb7a14 ldrd sp, lr, [r5], -r5
 *   @0xb7a18 ldrbmi r4, [r9], -r0, lsr #12
 *   @0xb7a1c stc2 p7, c15, [pc], #1020
 *   @0xb7a20 rscsle r2, r1, r0, lsl #16
 *   @0xb7a24 and r2, lr, r1
 *   @0xb7a28 strtmi r9, [r0], -r0, lsl #6
 *   @0xb7a2c strbmi r2, [r2], -r3, lsl #2
 *   @0xb7a30 .word 0xf7ff6ce3
 *   @0xb7a34 stmdahs r0, {r2, r5, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0xb7a38 blvs 0x19ac210 <b2_toiTime+0x1252d6c>
 *   @0xb7a3c addsle r4, r8, #805306379
 *   @0xb7a40 strbtvs r2, [r7], #-0
 *   @0xb7a44 andlt r6, r3, r5, lsr #9
 *   @0xb7a48 svchi #0xf0e8bd
 *   @0xb7a4c .word 0x0023aaf3
 *   @0xb7a50 eoreq r10, r3, pc, ror #21
 *   @0xb7a54 .word 0x4604b5f0
 *   @0xb7a58 addlt r6, r5, r3, asr #28
 *   @0xb7a5c ldrmi r4, [r5], -lr, lsl #12
 *   @0xb7a60 andsle r2, pc, r1, lsl #22
 *   @0xb7a64 blhs 0x16c674 <_ZN8yyMatrix6InvertEv+0x18>
 *   @0xb7a68 sub sp, pc, r4, lsr r0
 *   @0xb7a6c addsmi r6, r5, #33280
 *   @0xb7a70 stmdavs r3, {r1, r4, r8, r10, r11, r12, lr, pc} ^
 *   @0xb7a74 ldmne r1, {r0, r1, r2, r7, r11, sp, lr} ^
 *   @0xb7a78 stmdblo r1, {r0, r1, r3, r4, r6, r9, lr}
 *   @0xb7a7c bne 0xfe747ab0 <b2_toiTime+0xfffffffffdfee60c>
 *   @0xb7a80 .word 0xf04f42ba
 *   @0xb7a84 svclt #0xb40101
 *   @0xb7a88 andhs r2, r1, #0, #4
 *   @0xb7a8c mcr2 p7, #0x4, pc, c1, c15, #0x7
 *   @0xb7a90 eorsle r2, r11, r0, lsl #16
 *   @0xb7a94 rsb r2, r9, r1
 *   @0xb7a98 stmdavs r3, {r3, r4, r5, r9, r11, r12, lr, pc} ^
 *   @0xb7a9c andsmi r3, r10, r1, lsl #22
 *   @0xb7aa0 ands r6, r4, r3, lsl #17
 *   @0xb7aa4 addsmi r6, r10, #33536
 *   @0xb7aa8 stmdavs r2, {r4, r5, r9, r11, r12, lr, pc} ^
 *   @0xb7aac blo 0x111cb8 <_Z17InitMathFunctionsv+0x5c>
 *   @0xb7ab0 addmi r4, r11, #19
 *   @0xb7ab4 strhhs r11, [r0, -r4]
 *   @0xb7ab8 .word 0xf7ff2101
 *   @0xb7abc stmdahs r0, {r5, r6, r10, r11, r12, sp, lr, pc}
 *   @0xb7ac0 stmdavs r3!, {r3, r5, r6, r7, r8, r12, lr, pc} ^
 *   @0xb7ac4 cdpne p6, #0x5, c4, c10, c0, #0x1
 *   @0xb7ac8 andsmi r6, r10, r3, lsr #25
 *   @0xb7acc smlatbhs r2, r3, r8, r6
 *   @0xb7ad0 bfi r4, r10, #5, #20
 *   @0xb7ad4 addsmi r6, r10, #33536
 *   @0xb7ad8 stmdavs r2, {r3, r4, r8, r10, r11, r12, lr, pc} ^
 *   @0xb7adc subsmi r1, r2, #10027008
 *   @0xb7ae0 andmi r3, r10, r1, lsl #18
 *   @0xb7ae4 bne 0xff591cf0 <b2_toiTime+0xfffffffffee3884c>
 *   @0xb7ae8 svclt #0xb4428b
 *   @0xb7aec mrshs r2, apsr
 *   @0xb7af0 mcrr2 p7, #0xf, pc, r5, c15
 *   @0xb7af4 bicle r2, sp, r0, lsl #16
 *   @0xb7af8 strtmi r6, [r0], -r3, lsr #25
 *   @0xb7afc stmvs r7!, {r1, r5, r6, r11, sp, lr}
 *   @0xb7b00 subsmi r1, r2, #10027008
 *   @0xb7b04 andmi r3, r10, r1, lsl #18
 *   @0xb7b08 sbfx r1, r2, #0x15, #0x1a
 *   @0xb7b0c blhs 0x1134a0 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2c8>
 *   @0xb7b10 blhs 0x16bb20 <_Z20GR_Draw_Vertex_Colorffjf+0x40>
 *   @0xb7b14 eor sp, r6, r12
 *   @0xb7b18 strtmi r6, [r0], -r3, ror #25
 *   @0xb7b1c stclvs p5, c9, [r1], #-0
 *   @0xb7b20 stcvs p3, c9, [r3, #-4]!
 *   @0xb7b24 movwls r6, #0x2ca2
 *   @0xb7b28 .word 0xf7ff4633
 *   @0xb7b2c muls r8, r4, sp
 *   @0xb7b30 movwls r4, #0x26b
 *   @0xb7b34 strtmi r6, [r0], -r3, lsr #26
 *   @0xb7b38 subsmi r6, r11, #41472
 *   @0xb7b3c stclvs p3, c9, [r3], #4
 *   @0xb7b40 .word 0xf8944252
 *   @0xb7b44 subsmi r7, r11, #86
 *   @0xb7b48 movwls r6, #0x2c61
 *   @0xb7b4c .word 0xf7ff4633
 *   @0xb7b50 teqlt r7, r2, lsl #27
 *   @0xb7b54 .word 0x3056f894
 *   @0xb7b58 stcvs p9, c11, [r3, #108]!
 *   @0xb7b5c subsmi r6, r2, #1474560
 *   @0xb7b60 stmdahs r0, {r1, r3, r4, r6, r8, sp, lr}
 *   @0xb7b64 mulhs r0, r6, r1
 *   @0xb7b68 strtvs r6, [r5], #1126
 *   @0xb7b6c ldcllt p0, c11, [r0, #20]!
 *   @0xb7b70 svcmi #0xf0e92d
 *   @0xb7b74 .word 0x4604b091
 *   @0xb7b78 mrsls r2, apsr
 *   @0xb7b7c .word 0x23fcf8d4
 *   @0xb7b80 vmlsl.s8 q9, d0, d0
 *   @0xb7b84 bl 0x1d8304 <_Z17TestForNewRotatesx+0x128>
 *   @0xb7b88 stmdavs r3!, {r1, r7, r9} ^
 *   @0xb7b8c strls r2, [r8, -r0, lsl #14]
 *   @0xb7b90 .word 0x13bef9b2
 *   @0xb7b94 strvs r4, [r1, #-0x359]!
 *   @0xb7b98 .word 0x23bcf9b2
 *   @0xb7b9c strbvs r6, [r5, #0x2e5]!
 *   @0xb7ba0 bvs 0x9488f4 <b2_toiTime+0x1ef450>
 *   @0xb7ba4 subspl pc, r7, r4, lsl #17
 *   @0xb7ba8 subspl pc, r6, r4, lsl #17
 *   @0xb7bac .word 0x63253a20
 *   @0xb7bb0 strbtvs r6, [r3], #610
 *   @0xb7bb4 adcvs r6, r3, #3719168
 *   @0xb7bb8 addsvs r6, r11, r3, lsr #11
 *   @0xb7bbc subspl pc, r4, r4, lsr #17
 *   @0xb7bc0 strhlo pc, [r0], r4
 *   @0xb7bc4 addsmi r9, r8, #8, #16
 *   @0xb7bc8 teqhi r6, r0, lsl #5
 *   @0xb7bcc .word 0x308cf8d4
 *   @0xb7bd0 .word 0xf8d49908
 *   @0xb7bd4 strbtvs r2, [r5], -r4, lsl #1
 *   @0xb7bd8 rfeda r3!
 *   @0xb7bdc adcslt r8, r9, #17
 *   @0xb7be0 .word 0xf8529808
 *   @0xb7be4 stmibvs r7!, {r0, r4, r5, sp, lr}
 *   @0xb7be8 bleq 0xff2f27f8 <b2_toiTime+0xfffffffffeb99354>
 *   @0xb7bec subeq r6, r0, r3, lsr #17
 *   @0xb7bf0 bl 0x15bc24 <_Z17InitYoYoFunctionsv+0x1b54>
 *   @0xb7bf4 adcsmi r0, lr, r1, asr #1
 *   @0xb7bf8 eorshs pc, r8, r2, asr r8
 *   @0xb7bfc beq 0x272b10 <pcre_dfa_exec+0x45a8>
 *   @0xb7c00 .word 0xc004f8db
 *   @0xb7c04 adcsmi r6, r10, r6, asr #16
 *   @0xb7c08 .word 0xfc07fa0c
 *   @0xb7c0c ldrsbtmi r1, [lr], r2
 *   @0xb7c10 bne 0xffe5f83c <b2_toiTime+0xffffffffff706398>
 *   @0xb7c14 movweq lr, #0xcbc3
 *   @0xb7c18 ldrtmi r11, [r7], -pc, lsr #18
 *   @0xb7c1c ssatmi r4, #0x1b, r6, asr #12
 *   @0xb7c20 sadd16mi r4, r3, pc
 *   @0xb7c24 .word 0xf8d4463a
 *   @0xb7c28 bl 0x3e7e50 <error_g0017+0x40af4>
 *   @0xb7c2c .word 0xf81c0701
 *   @0xb7c30 .word 0xf0199001
 *   @0xb7c34 svclt #0x1c0f04
 *   @0xb7c38 ldmdbne r9, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^
 *   @0xb7c3c adcsls pc, r0, r4, lsl #17
 *   @0xb7c40 andne pc, r1, r12, lsl r8
 *   @0xb7c44 mrseq pc, apsr
 *   @0xb7c48 .word 0xf0002902
 *   @0xb7c4c stmiblt r1!, {r1, r4, r5, r6, r7, pc}
 *   @0xb7c50 andne pc, r8, r12, lsl r8
 *   @0xb7c54 mrseq pc, apsr
 *   @0xb7c58 .word 0xd1022901
 *   @0xb7c5c bleq 0x2f4310 <ps_hints_apply+0x2f10>
 *   @0xb7c60 ldrtmi lr, [r3], #-7
 *   @0xb7c64 bl 0x188db4 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0xc8>
 *   @0xb7c68 bl 0x154bbc <_Z19YYIAPEventsDispatchv+0xfd4>
 *   @0xb7c6c ldrsbne r7, [r11], #-34
 *   @0xb7c70 stmdalo r8, {r1, r4, r6, r12}
 *   @0xb7c74 ldrmi r3, [r2], r1, lsl #30
 *   @0xb7c78 strbtvs r4, [r6], #-1566
 *   @0xb7c7c subge pc, r8, r4, asr #17
 *   @0xb7c80 .word 0xf0804558
 *   @0xb7c84 ldmdavc r11!, {r4, r6, r7, pc} ^
 *   @0xb7c88 .word 0x0108f100
 *   @0xb7c8c stmdbeq r1, {r0, r1, r2, r8, r12, sp, lr, pc}
 *   @0xb7c90 .word 0xf0139107
 *   @0xb7c94 andsle r0, r3, r3, lsl #6
 *   @0xb7c98 .word 0xd16c2b01
 *   @0xb7c9c stmvs r0, {r1, r7, r11, sp, lr} ^
 *   @0xb7ca0 stmvs r3!, {r0, r5, r7, r8, r11, sp, lr}
 *   @0xb7ca4 addmi r9, r10, r9, lsl #30
 *   @0xb7ca8 .word 0xf101fa00
 *   @0xb7cac bne 0xff2fe7fc <b2_toiTime+0xfffffffffeba5358>
 *   @0xb7cb0 .word 0x460bb917
 *   @0xb7cb4 sadd16mi r4, r10, r1
 *   @0xb7cb8 .word 0xf7ff4620
 *   @0xb7cbc eors pc, r9, r11, asr #29
 *   @0xb7cc0 stmvs r0, {r1, r7, r11, sp, lr} ^
 *   @0xb7cc4 stmvs r3!, {r0, r5, r7, r8, r11, sp, lr}
 *   @0xb7cc8 blx 0xc7ef8 <_Z25F_Vertex_TexCoord_releaseR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xb7ccc stmdals r9, {r0, r8, r12, sp, lr, pc}
 *   @0xb7cd0 bne 0xff2fe820 <b2_toiTime+0xfffffffffeba537c>
 *   @0xb7cd4 .word 0x460bb910
 *   @0xb7cd8 sadd16mi r4, r10, r1
 *   @0xb7cdc strlo r9, [r2, -r7, lsl #22]
 *   @0xb7ce0 ldrbmi r9, [r11, #-0x706]
 *   @0xb7ce4 .word 0xf8ddd240
 *   @0xb7ce8 .word 0xf1039018
 *   @0xb7cec strls r0, [r10, -r8, lsl #14]
 *   @0xb7cf0 .word 0xf1099707
 *   @0xb7cf4 strls r0, [r6, -r1, lsl #14]
 *   @0xb7cf8 stmibvs r0!, {r0, r1, r2, r3, r4, r7, r11, sp, lr}
 *   @0xb7cfc mulgt r0, r9, r8
 *   @0xb7d00 .word 0xf000fa07
 *   @0xb7d04 .word 0xf00c68a7
 *   @0xb7d08 bl 0xff27ad1c <b2_toiTime+0xfffffffffeb21878>
 *   @0xb7d0c ldmvs r8, {r11} ^
 *   @0xb7d10 blx 0xd23a4 <_Z22Variable_GetName_ScopePKcii+0x17c>
 *   @0xb7d14 stmdals r9, {r0, r1, r8, r9, r12, sp, lr, pc}
 *   @0xb7d18 ldmdblt r0, {r0, r1, r2, r3, r4, r6, r7, r8, r9, r11, r12}
 *   @0xb7d1c .word 0x4647463b
 *   @0xb7d20 .word 0xf1bc4698
 *   @0xb7d24 .word 0xd1080f01
 *   @0xb7d28 andhi pc, r0, sp, asr #17
 *   @0xb7d2c ldrtmi r4, [r11], -r0, lsr #12
 *   @0xb7d30 ldc2l p7, c15, [r8, #-1020]!
 *   @0xb7d34 rsbsle r2, r3, r0, lsl #16
 *   @0xb7d38 .word 0xf1bce0d6
 *   @0xb7d3c cmnle r8, r0, lsl #30
 *   @0xb7d40 bl 0x13e474 <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0xb7d44 bl 0x177d6c <_Z16GR_3D_Draw_Blockffffffiff+0x730>
 *   @0xb7d48 bl 0xd4c9c <_Z12DoPushGlobaljPhPKhP6VMExec+0xc4>
 *   @0xb7d4c ldrsbne r7, [r11], #-0
 *   @0xb7d50 andls r1, r0, r0, asr #32
 *   @0xb7d54 .word 0xf7ff4620
 *   @0xb7d58 stmdahs r0, {r0, r2, r5, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0xb7d5c sbchi pc, r4, r0, asr #32
 *   @0xb7d60 strbmi r9, [r2], -r10, lsl #22
 *   @0xb7d64 .word 0xe7bc4639
 *   @0xb7d68 andge pc, r0, sp, asr #17
 *   @0xb7d6c ldrtmi r4, [r3], -r0, lsr #12
 *   @0xb7d70 ldc2l p7, c15, [r8, #-1020]
 *   @0xb7d74 cps #0x11
 *   @0xb7d78 ldrmi r0, [r11, #0x310]
 *   @0xb7d7c ldmvc r11!, {r0, r3, r4, r6, r8, r9, r12, lr, pc}
 *   @0xb7d80 movweq pc, #0x3003
 *   @0xb7d84 cmple r4, r2, lsl #22
 *   @0xb7d88 cps #0x2
 *   @0xb7d8c stmibvs r3!, {r3, r4, r8}
 *   @0xb7d90 .word 0xe008f8d4
 *   @0xb7d94 swpls r4, r10, [r7]
 *   @0xb7d98 stmdbeq r2, {r1, r2, r3, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0xb7d9c stmvs r1, {r1, r8, r11, sp, lr} ^
 *   @0xb7da0 .word 0xfc03fa02
 *   @0xb7da4 addsmi r6, r9, r2, asr #18
 *   @0xb7da8 .word 0x0c0cebce
 *   @0xb7dac smlabteq r1, lr, r11, lr
 *   @0xb7db0 bl 0xff448020 <b2_toiTime+0xfffffffffeceeb7c>
 *   @0xb7db4 bls 0x2f89c4 <ps_hints_apply+0x75c4>
 *   @0xb7db8 ldrmi r11, [r8], r10, lsr #18
 *   @0xb7dbc strbmi r4, [r4], r3, ror #12
 *   @0xb7dc0 strbmi r4, [r9], -r8, lsl #13
 *   @0xb7dc4 bls 0x2898d0 <spSkeleton_updateCache+0x2d4>
 *   @0xb7dc8 ldmdale sp, {r1, r3, r4, r6, r8, r10, lr}
 *   @0xb7dcc ldrsbhi pc, [r8], -r0
 *   @0xb7dd0 stmibvs r2!, {r6, r7, r8, r11, sp, lr}
 *   @0xb7dd4 .word 0xf802fa08
 *   @0xb7dd8 bls 0x308020 <TT_New_Context+0x7e18>
 *   @0xb7ddc stmdaeq r8, {r1, r2, r3, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0xb7de0 andeq lr, r0, lr, asr #23
 *   @0xb7de4 pkhbtmi r11, r6, r2, lsl #18
 *   @0xb7de8 ldrbtmi r4, [r0], r0, asr #12
 *   @0xb7dec strbmi r9, [r10], -r1
 *   @0xb7df0 andgt pc, r0, sp, asr #17
 *   @0xb7df4 .word 0xf8cd4620
 *   @0xb7df8 .word 0xf7ff8008
 *   @0xb7dfc stmdahs r0, {r0, r3, r4, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0xb7e00 .word 0xf107d172
 *   @0xb7e04 and r0, r11, r3, lsl #18
 *   @0xb7e08 andgt pc, r0, sp, asr #17
 *   @0xb7e0c strls r4, [r1], -r0, lsr #12
 *   @0xb7e10 .word 0xf8cd464a
 *   @0xb7e14 .word 0xf7ffa008
 *   @0xb7e18 stmdahs r0, {r0, r1, r3, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0xb7e1c sub sp, r2, r4, ror #2
 *   @0xb7e20 stmdals r7, {r0, r1, r2, r3, r6, r9, r10, lr}
 *   @0xb7e24 strtmi lr, [r0], -r12, lsr #14
 *   @0xb7e28 uasxmi r4, r2, r1
 *   @0xb7e2c mrc2 p7, #0x0, apsr_nzcv, c2, c15, #0x7
 *   @0xb7e30 tsths r4, #63700992
 *   @0xb7e34 subs r6, r7, r3, ror #5
 *   @0xb7e38 ldrhvc pc, [r4], #-132
 *   @0xb7e3c svchs #0x16de6
 *   @0xb7e40 cdphs p9, #0x0, c13, c0, c15, #0x1
 *   @0xb7e44 svchs #0x1d02d
 *   @0xb7e48 svclt #0x946933
 *   @0xb7e4c ldmvs r2!, {r0, r2, r4, r5, r6, sp, lr}
 *   @0xb7e50 svclt #0x846971
 *   @0xb7e54 addeq lr, r3, #2048
 *   @0xb7e58 ldmibhi r2!, {r1, r4, r5, r6, sp, lr}
 *   @0xb7e5c svceq #0x8f012
 *   @0xb7e60 strmi sp, [r11], #-3
 *   @0xb7e64 ldmlo pc!, {r0, r1, r8, r12, sp, lr, pc} ^
 *   @0xb7e68 strmi lr, [r8], r10
 *   @0xb7e6c .word 0xf1031ac9
 *   @0xb7e70 ldmvs r2!, {r7, r8, r9, lr}
 *   @0xb7e74 .word 0x31013b01
 *   @0xb7e78 bl 0x150444 <InitPhysicsFunctions+0x10>
 *   @0xb7e7c adcsvs r0, r3, r3, lsl #7
 *   @0xb7e80 .word 0xf7ff4620
 *   @0xb7e84 stmdahs r0, {r0, r4, r5, r7, r9, r11, r12, sp, lr, pc}
 *   @0xb7e88 strtmi sp, [r0], -lr, lsr #2
 *   @0xb7e8c mrseq pc, apsr
 *   @0xb7e90 blx 0xfeb75e94 <b2_toiTime+0xfffffffffe41c9f0>
 *   @0xb7e94 svclo #0x1bb40
 *   @0xb7e98 adcslt r6, pc, #7733248
 *   @0xb7e9c bicsle r2, r2, r0, lsl #30
 *   @0xb7ea0 strbvs lr, [r5, #0x73]!
 *   @0xb7ea4 .word 0xf8d4e071
 *   @0xb7ea8 stmdals r11, {r2, r3, r7, r12, sp}
 *   @0xb7eac stcvs p8, c6, [r6, #388]!
 *   @0xb7eb0 .word 0xf1015a1f
 *   @0xb7eb4 stcvs p14, c3, [r3], #1020
 *   @0xb7eb8 b 0x845ac4 <b2_toiTime+0xec620>
 *   @0xb7ebc .word 0xd1020e03
 *   @0xb7ec0 addsmi r6, r3, #57856
 *   @0xb7ec4 ldmvs r2!, {r0, r6, r9, r11, r12, lr, pc}
 *   @0xb7ec8 addsmi r6, r0, #160, #20
 *   @0xb7ecc suble r6, r11, r2, lsr #17
 *   @0xb7ed0 .word 0x070089b0
 *   @0xb7ed4 ldrmi sp, [r6, #0x548]
 *   @0xb7ed8 strhhs r11, [r0, -r4]
 *   @0xb7edc strtmi r2, [r0], -r1, lsl #2
 *   @0xb7ee0 blx 0x1435ee4 <b2_toiTime+0xcdca40>
 *   @0xb7ee4 suble r2, r9, r0, lsl #16
 *   @0xb7ee8 blhs 0x1952a7c <b2_toiTime+0x11f95d8>
 *   @0xb7eec .word 0xf8d4d12b
 *   @0xb7ef0 rscvs r2, r5, #252, #6
 *   @0xb7ef4 bl 0x1c2714 <_ZN13CLayerManager18InitLayerFunctionsEv+0x11d4>
 *   @0xb7ef8 rfeia r3!
 *   @0xb7efc rfeib r3!
 *   @0xb7f00 blx 0xb8df8 <.text+0x1e28>
 *   @0xb7f04 bl 0x134524 <_Z19F_SoundEffectReverbR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0xb7f08 b 0x1494654 <b2_toiTime+0xd3b1b0>
 *   @0xb7f0c addlt r0, pc, #1073741848
 *   @0xb7f10 blx 0x4aef24 <SrcVerts+0xbf68>
 *   @0xb7f14 strmi pc, [r4, #0xc87]
 *   @0xb7f18 movwhs sp, #0xa03
 *   @0xb7f1c .word 0x33fcf8c4
 *   @0xb7f20 andlo lr, r1, #12
 *   @0xb7f24 bl 0x1c6330 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x2c0>
 *   @0xb7f28 .word 0xf8a00082
 *   @0xb7f2c .word 0xf8a073bc
 *   @0xb7f30 .word 0xf8a363be
 *   @0xb7f34 .word 0xf8c413be
 *   @0xb7f38 ssub8 r2, pc, r12
 *   @0xb7f3c rscvs r2, r0, #20
 *   @0xb7f40 andhs lr, r0, r3, ror #2
 *   @0xb7f44 andhs lr, r1, r1, ror #2
 *   @0xb7f48 stcvs p1, c14, [r2, #-380]!
 *   @0xb7f4c ldcle p2, c4, [r10], #588
 *   @0xb7f50 bhs 0xd37e0 <_ZN17TErrStreamConsole6OutputEPKcz+0x58>
 *   @0xb7f54 ldmibhi r0!, {r0, r1, r2, r4, r5, r7, r12, lr, pc}
 *   @0xb7f58 umaalmi r8, r2, r2, r9
 *   @0xb7f5c ldrtle r0, [r2], #1810
 *   @0xb7f60 blo 0x1d29f0 <CheckLicense+0x650>
 *   @0xb7f64 str r6, [lr, r2, lsr #5]!
 *   @0xb7f68 vmlaeq.f64 d14, d1, d3
 *   @0xb7f6c .word 0xf10e4249
 *   @0xb7f70 b 0x447b74 <g_RomDisk+0x50354>
 *   @0xb7f74 bne 0xff2f8380 <b2_toiTime+0xfffffffffeb9eedc>
 *   @0xb7f78 .word 0xe7ad4291
 *   @0xb7f7c .word 0xb1036e23
 *   @0xb7f80 blls 0x2d0754 <_ZN13b2PulleyJoint4DumpEv+0x20>
 *   @0xb7f84 movwls r3, #0x8301
 *   @0xb7f88 bvs 0xfe9717f8 <b2_toiTime+0xfffffffffe218354>
 *   @0xb7f8c addsmi r6, r10, #405504
 *   @0xb7f90 stclvs p2, c13, [r1, #680]!
 *   @0xb7f94 .word 0xf0002900
 *   @0xb7f98 andhs r8, r0, #-2147483636
 *   @0xb7f9c andls r9, lr, #-805306368
 *   @0xb7fa0 andls r10, pc, #13, #30
 *   @0xb7fa4 stmdavs r3!, {r1, r5, r6, r7, r10, r11, sp, lr}
 *   @0xb7fa8 tstmi r10, r6, lsl #14
 *   @0xb7fac eorshs pc, r2, sp, lsr #17
 *   @0xb7fb0 blx 0x1153440 <b2_toiTime+0x9f9f9c>
 *   @0xb7fb4 .word 0xf8adf303
 *   @0xb7fb8 stmdbvs r8, {r4, r5, r12, sp} ^
 *   @0xb7fbc rfeib sp!
 *   @0xb7fc0 strmi r7, [r3], #-48
 *   @0xb7fc4 bllo 0x1249d4 <_Z20InitGraphicFunctionsv+0x1768>
 *   @0xb7fc8 andslt r6, r0, #5111808
 *   @0xb7fcc addmi r11, r7, #-1342177271
 *   @0xb7fd0 ldrhteq pc, [r2], -sp
 *   @0xb7fd4 .word 0xf8adbfc8
 *   @0xb7fd8 andslt r2, r10, #48
 *   @0xb7fdc stmdage sp, {r4, r7, r9, lr}
 *   @0xb7fe0 .word 0xf8adbfb8
 *   @0xb7fe4 andvs r3, sp, r2, lsr r0
 *   @0xb7fe8 blx 0xffdb5fec <b2_toiTime+0xffffffffff65cb48>
 *   @0xb7fec ldrtmi r11, [r1], -lr, lsl #2
 *   @0xb7ff0 blvs 0x9b1f84 <b2_toiTime+0x258ae0>
 *   @0xb7ff4 adcle r2, r1, r0, lsl #22
 *   @0xb7ff8 .word 0x30a0f8d4
 *   @0xb7ffc strtmi r10, [r0], -r12, lsl #18
 *   @0xb8000 eorseq pc, r2, #1073741827
 *   @0xb8004 blls 0x409e6c <g_RomDisk+0x1264c>
 *   @0xb8008 ldrhtne pc, [r0], -sp
 *   @0xb800c ldmdbvs r10, {r0, r1, r5, r8, r12, sp, pc} ^
 *   @0xb8010 orrsvs r1, r10, r2, asr r10
 *   @0xb8014 ubfx r6, r11, #0x10, #0x1a
 *   @0xb8018 rfeia sp!
 *   @0xb801c blhs 0xd00e4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x16c>
 *   @0xb8020 .word 0xf06fdd09
 *   @0xb8024 bvs 0x938438 <b2_toiTime+0x1def94>
 *   @0xb8028 eorslt r4, r0, #1677721601
 *   @0xb802c addmi r5, r1, #5308416
 *   @0xb8030 bllo 0x12c43c <_Z28F_BackgroundCreateFromScreenR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xb8034 .word 0xf10d6323
 *   @0xb8038 .word 0xf10d093c
 *   @0xb803c smladxhs r0, r8, r10, r0
 *   @0xb8040 blvs 0x99dc68 <b2_toiTime+0x2447c4>
 *   @0xb8044 .word 0xf3402b00
 *   @0xb8048 stmdals r8, {r1, r3, r5, r7, pc}
 *   @0xb804c ldrsbtlt pc, [r4], -sp
 *   @0xb8050 .word 0xf1bbb207
 *   @0xb8054 andsle r0, r6, r0, lsl #30
 *   @0xb8058 ldrsblo pc, [r8], -r11
 *   @0xb805c .word 0x8004f8db
 *   @0xb8060 .word 0xf8cb1bdb
 *   @0xb8064 stmdblt r3!, {r3, r4, r12, sp} ^
 *   @0xb8068 ldrbmi r10, [r9], -sp, lsl #16
 *   @0xb806c blx 0xff076070 <b2_toiTime+0xfffffffffe91cbcc>
 *   @0xb8070 strhlo pc, [r12], -r11
 *   @0xb8074 .word 0x071b4659
 *   @0xb8078 ldrbmi r11, [r0], -r12, asr #30
 *   @0xb807c .word 0xf7ff4648
 *   @0xb8080 strbmi pc, [r3], r8, lsr #21
 *   @0xb8084 ldrbmi lr, [r0], -r5, ror #15
 *   @0xb8088 blx 0xfefb608c <b2_toiTime+0xfffffffffe85cbe8>
 *   @0xb808c .word 0xf7ff4648
 *   @0xb8090 blvs 0x9b6b78 <b2_toiTime+0x25d6d4>
 *   @0xb8094 vnmlsne.f32 s13, s18, s5
 *   @0xb8098 .word 0xf06f6321
 *   @0xb809c movtmi r0, #0xb103
 *   @0xb80a0 blne 0xfe74e3f4 <b2_toiTime+0xfffffffffdff4f50>
 *   @0xb80a4 movwls r11, #0x721b
 *   @0xb80a8 andls r11, r8, #536870921
 *   @0xb80ac eorslt r9, r3, #7, #30
 *   @0xb80b0 adcsmi r9, r11, #229376
 *   @0xb80b4 .word 0xf8ddda65
 *   @0xb80b8 .word 0x4688b03c
 *   @0xb80bc .word 0x0c00f04f
 *   @0xb80c0 .word 0xf1b8930a
 *   @0xb80c4 eorsle r0, pc, r0, lsl #30
 *   @0xb80c8 .word 0x3000f8d8
 *   @0xb80cc .word 0x2000f8db
 *   @0xb80d0 .word 0xdc024293
 *   @0xb80d4 sadd16mi r4, r10, r1
 *   @0xb80d8 stmdavs r1!, {r0, r1, r3, r9, r10, lr} ^
 *   @0xb80dc addmi r1, r8, #152, #20
 *   @0xb80e0 submi sp, pc, #8704
 *   @0xb80e4 andeq lr, r7, r2, lsl #20
 *   @0xb80e8 mulsle sp, r0, r2
 *   @0xb80ec vmlaeq.f64 d14, d1, d3
 *   @0xb80f0 cdplo p1, #0xf, c15, c15, c14, #0x0
 *   @0xb80f4 streq lr, [r7, -lr, lsl #20]
 *   @0xb80f8 mulsle r5, pc, r2
 *   @0xb80fc .word 0xdc0242b8
 *   @0xb8100 addmi r4, pc, #16777216
 *   @0xb8104 rfeia r8!
 *   @0xb8108 .word 0xf001100c
 *   @0xb810c stmdbhs r2, {r0, r1, r2, r8}
 *   @0xb8110 .word 0x2101d015
 *   @0xb8114 .word 0xf8c8448c
 *   @0xb8118 blx 0x880120 <b2_toiTime+0x126c7c>
 *   @0xb811c .word 0xf8cbfc8c
 *   @0xb8120 .word 0xf8c83000
 *   @0xb8124 and r1, r10, r8, lsl r0
 *   @0xb8128 andsgt pc, r4, sp, asr #17
 *   @0xb812c stm sp, {r5, r9, r10, lr}
 *   @0xb8130 .word 0xf8d40900
 *   @0xb8134 stmdbls r10, {r2, r5, r7, r12, sp, lr}
 *   @0xb8138 .word 0xf8dd47b8
 *   @0xb813c .word 0xf8d8c014
 *   @0xb8140 .word 0xf8db8004
 *   @0xb8144 ldr r11, [r12, r4]!
 *   @0xb8148 stc2 p10, c15, [r12], {15}
 *   @0xb814c svceq #0xf1bc
 *   @0xb8150 .word 0x3601dc31
 *   @0xb8154 .word 0x30acf8d4
 *   @0xb8158 adcslt r4, r6, #32, #12
 *   @0xb815c svcls #0x74798
 *   @0xb8160 adcsmi r11, r11, #805306371
 *   @0xb8164 ldrbmi sp, [r0], -r2, lsr #21
 *   @0xb8168 blx 0x13b616c <b2_toiTime+0xc5ccc8>
 *   @0xb816c .word 0xf7ff4648
 *   @0xb8170 ldr pc, [r11, r8, asr #20]
 *   @0xb8174 stmdavs pc, {r0, r1, r3, r8, r11, sp, lr} ^
 *   @0xb8178 uadd16mi r11, r0, r3
 *   @0xb817c blx 0xe76180 <b2_toiTime+0x71ccdc>
 *   @0xb8180 stmdbhs r0, {r0, r3, r4, r5, r9, r10, lr}
 *   @0xb8184 stmdbls pc, {r1, r2, r4, r5, r6, r7, r8, r12, lr, pc}
 *   @0xb8188 .word 0xf43f2900
 *   @0xb818c stmdbvs r11, {r1, r3, r4, r6, r8, r9, r10, r11, sp, pc}
 *   @0xb8190 ldmdblt r3, {r0, r1, r2, r3, r6, r11, sp, lr}
 *   @0xb8194 .word 0xf7ff4648
 *   @0xb8198 ldrtmi pc, [r9], -r9, lsr #20
 *   @0xb819c rfeib sp!
 *   @0xb81a0 eorslt r2, r3, #50
 *   @0xb81a4 blle 0xb48c14 <b2_toiTime+0x3ef770>
 *   @0xb81a8 .word 0xf8d43601
 *   @0xb81ac strtmi r3, [r0], -r12, lsr #1
 *   @0xb81b0 adcslt r4, r6, #152, #14
 *   @0xb81b4 .word 0xf8dde7f3
 *   @0xb81b8 blx 0x4a82a0 <SrcVerts+0x52e4>
 *   @0xb81bc .word 0xf8ddf886
 *   @0xb81c0 .word 0xf1bcb03c
 *   @0xb81c4 sbcle r0, r4, r0, lsl #30
 *   @0xb81c8 ldrsblo pc, [r8], -r12
 *   @0xb81cc .word 0xf8ccb193
 *   @0xb81d0 qadd16mi r5, r0, r8
 *   @0xb81d4 andgt pc, r0, sp, asr #17
 *   @0xb81d8 .word 0xf8cd4641
 *   @0xb81dc .word 0xf8d4b004
 *   @0xb81e0 .word 0xf8dc70a8
 *   @0xb81e4 .word 0xf8db2000
 *   @0xb81e8 .word 0xf8cd3000
 *   @0xb81ec .word 0x47b8c014
 *   @0xb81f0 ldrsbgt pc, [r4], -sp
 *   @0xb81f4 .word 0xc004f8dc
 *   @0xb81f8 .word 0xb004f8db
 *   @0xb81fc .word 0xf8d4e7e1
 *   @0xb8200 bllo 0x1051f8 <dsMapAddRValue+0xc8>
 *   @0xb8204 .word 0x33fcf8c4
 *   @0xb8208 ldrhlt lr, [r1], -r8
 *   @0xb820c svchi #0xf0e8bd
 *   @0xb8210 stmdavs sp, {r4, r5, r6, r7, r8, r10, r12, sp, pc}
 *   @0xb8214 stclne p8, c6, [lr, #-784]!
 *   @0xb8218 stmdble r1, {r1, r2, r4, r7, r9, lr}
 *   @0xb821c ldcllt p0, c2, [r0, #24]!
 *   @0xb8220 eorhi r7, r7, pc, lsr #16
 *   @0xb8224 rsbhi r7, r7, pc, ror #16
 *   @0xb8228 mulvc r2, r5, r9
 *   @0xb822c .word 0xf99580a7
 *   @0xb8230 rschi r7, r7, r3
 *   @0xb8234 .word 0x8127792f
 *   @0xb8238 .word 0xf105b15b
 *   @0xb823c addsmi r0, r6, #8, #12
 *   @0xb8240 .word 0xf995d8ec
 *   @0xb8244 .word 0x81633005
 *   @0xb8248 mullo r6, r5, r9
 *   @0xb824c stmibvc r11!, {r0, r1, r5, r7, r8, pc} ^
 *   @0xb8250 .word 0x8163e001
 *   @0xb8254 mvnhi r8, r3, lsr #3
 *   @0xb8258 strvc r2, [r3], #-769
 *   @0xb825c andvs r2, lr, r0
 *   @0xb8260 .word 0xf401bdf0
 *   @0xb8264 push {r7, r8, lr}
 *   @0xb8268 .word 0xf04f47f0
 *   @0xb826c addlt r0, r12, #0, #20
 *   @0xb8270 ldrmi r4, [r0], r7, lsl #12
 *   @0xb8274 vst1.32 {d20, d21, d22}, [pc:64], r9
 *   @0xb8278 ldrbmi r3, [r6], -r0, lsl #1
 *   @0xb827c addsmi r6, lr, #3866624
 *   @0xb8280 .word 0xf858d22c
 *   @0xb8284 .word 0xb32a200a
 *   @0xb8288 .word 0xf85368bb
 *   @0xb828c teqlt r9, #10
 *   @0xb8290 mulsle pc, r1, r2
 *   @0xb8294 b 0x1667ac <_ZN9CBitmap32C2Eiijji+0x44>
 *   @0xb8298 addsmi r7, r9, #-2013265917
 *   @0xb829c b 0x96ef30 <b2_toiTime+0x215a8c>
 *   @0xb82a0 addsmi r7, r9, #-2013265917
 *   @0xb82a4 ands sp, lr, r4, lsl sp
 *   @0xb82a8 andpl pc, r10, r9, asr r8
 *   @0xb82ac blle 0x808d58 <b2_toiTime+0xaf8b4>
 *   @0xb82b0 .word 0xc020f8dd
 *   @0xb82b4 andlo pc, r10, r12, asr r8
 *   @0xb82b8 .word 0xdc174299
 *   @0xb82bc svclt #0xb94291
 *   @0xb82c0 smlabteq r1, r5, r11, lr
 *   @0xb82c4 andeq lr, r2, #201728
 *   @0xb82c8 smlabteq r3, r1, r11, lr
 *   @0xb82cc andeq lr, r3, #198656
 *   @0xb82d0 ldc2 p2, c15, [r4, #-176]!
 *   @0xb82d4 .word 0xf10a3601
 *   @0xb82d8 strb r0, [pc, r4, lsl #20]
 *   @0xb82dc .word 0x87f0e8bd
 *   @0xb82e0 pop {r3, r9, r10, lr}
 *   @0xb82e4 qsub8mi r8, r0, r0
 *   @0xb82e8 .word 0x87f0e8bd
 *   @0xb82ec ldm sp!, {sp}
 *   @0xb82f0 push {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xb82f4 strdlt r4, r5, [r7], r0
 *   @0xb82f8 stmibvs r5, {r8, r9, sp} ^
 *   @0xb82fc .word 0x46076013
 *   @0xb8300 ldrmi r4, [r4], -r8, lsl #13
 *   @0xb8304 vcgt.s32 d9, d14, d5
 *   @0xb8308 sbclt pc, r6, #108544
 *   @0xb830c rsble r2, pc, r0, lsl #28
 *   @0xb8310 strle r0, [r7, #-0x633]
 *   @0xb8314 .word 0xf0064638
 *   @0xb8318 .word 0xf22e067f
 *   @0xb831c eorseq pc, r6, #96, #22
 *   @0xb8320 movwmi r11, #0x62c0
 *   @0xb8324 stmdble r1, {r1, r2, r6, r8, r10, lr}
 *   @0xb8328 rsb r2, r3, r0
 *   @0xb832c blge 0x200b34 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0xa8>
 *   @0xb8330 movwls r4, #0x1628
 *   @0xb8334 .word 0x21029200
 *   @0xb8338 .word 0xf22f1c73
 *   @0xb833c stcls p14, c15, [r5, #-672]
 *   @0xb8340 stchs p6, c4, [r0, #-512]
 *   @0xb8344 .word 0x6026d1f0
 *   @0xb8348 adcsmi r4, r4, #44, #12
 *   @0xb834c ldrtmi sp, [r8], -lr, asr #4
 *   @0xb8350 beq 0x134768 <_Z26F_AudioSetListenerVelocityR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xb8354 blx 0x11b4c16 <b2_toiTime+0xa5b772>
 *   @0xb8358 stmdbeq r4, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^
 *   @0xb835c blx 0xfe0f6ce2 <b2_toiTime+0xfffffffffd99d83e>
 *   @0xb8360 cmneq pc, #43
 *   @0xb8364 rscseq pc, pc, #3
 *   @0xb8368 shsub8mi r11, r8, r11
 *   @0xb836c bleq 0x20b43a0 <b2_toiTime+0x195aefc>
 *   @0xb8370 blx 0x10b4c32 <b2_toiTime+0x95b78e>
 *   @0xb8374 movweq lr, #0x9b08
 *   @0xb8378 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0xb837c addlt r4, r5, #40, #8
 *   @0xb8380 andspl pc, r4, r8, lsr #16
 *   @0xb8384 ldrbmi r4, [r9, #0x654]
 *   @0xb8388 .word 0x4638d2df
 *   @0xb838c vcgt.s32 d9, d14, d3
 *   @0xb8390 blls 0x1b7058 <_ZN13CLayerManager4InitEv+0x158>
 *   @0xb8394 bl 0x1853a0 <_ZN8Graphics5FlushEv+0xb4>
 *   @0xb8398 adcsmi r0, r4, #-1879048188
 *   @0xb839c addlt r4, r5, #40, #8
 *   @0xb83a0 sbcsle r8, r2, #85
 *   @0xb83a4 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0xb83a8 ldrtmi lr, [r8], -sp, ror #15
 *   @0xb83ac vhsub.s32 d9, d14, d3
 *   @0xb83b0 bl 0x2f7010 <ps_hints_apply+0x5c10>
 *   @0xb83b4 blx 0x15f8fe0 <b2_toiTime+0xe9fb3c>
 *   @0xb83b8 addlt pc, r5, #128
 *   @0xb83bc andspl pc, r4, r8, lsr #16
 *   @0xb83c0 ldrbmi r9, [r4], -r3, lsl #20
 *   @0xb83c4 ldrbmi r4, [r9, #0x691]
 *   @0xb83c8 .word 0x4638d2bf
 *   @0xb83cc vcgt.s32 d9, d14, d3
 *   @0xb83d0 blls 0x1b6ff0 <_ZN13CLayerManager4InitEv+0xf0>
 *   @0xb83d4 bl 0x1853e0 <_ZN8Graphics5FlushEv+0xf4>
 *   @0xb83d8 adcsmi r0, r4, #-1879048188
 *   @0xb83dc .word 0xf080fa55
 *   @0xb83e0 subshi r11, r5, r5, lsl #5
 *   @0xb83e4 .word 0xf109d2b1
 *   @0xb83e8 strb r0, [r12, r1, lsl #18]!
 *   @0xb83ec and r4, r1, r0, asr #12
 *   @0xb83f0 rscslo pc, pc, pc, asr #32
 *   @0xb83f4 pop {r0, r1, r2, r12, sp, pc}
 *   @0xb83f8 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xb83fc ssub8mi r4, r5, r0
 *   @0xb8400 addmi r11, sp, #135
 *   @0xb8404 andeq pc, r0, #79
 *   @0xb8408 .word 0xf8d04607
 *   @0xb840c andls r9, r5, #28
 *   @0xb8410 blge 0x22e55c <res0_look+0x384>
 *   @0xb8414 movwls r9, #0x1200
 *   @0xb8418 .word 0x21024648
 *   @0xb841c vmax.s32 d4, d15, d27
 *   @0xb8420 .word 0x9c05fe36
 *   @0xb8424 strmi r4, [r6], -r2, lsr #13
 *   @0xb8428 mrsle r2, spsr
 *   @0xb842c eorsle r4, r12, #172, #4
 *   @0xb8430 vmin.s32 d4, d14, d24
 *   @0xb8434 .word 0x0063fad4
 *   @0xb8438 .word 0xf020b2c0
 *   @0xb843c .word 0xf000027f
 *   @0xb8440 .word 0xf0020b3f
 *   @0xb8444 ldrshlt r0, [r10, #-31]
 *   @0xb8448 movwhs r1, #0x8f2
 *   @0xb844c andsge pc, r3, r2, lsr #16
 *   @0xb8450 ldrbmi r3, [r11, #-0x301]
 *   @0xb8454 streq pc, [r1], #-260
 *   @0xb8458 adcmi sp, r12, #232, #16
 *   @0xb845c .word 0xe026d3f6
 *   @0xb8460 subeq pc, r0, r0
 *   @0xb8464 .word 0xf0004433
 *   @0xb8468 strdlt r0, r1, [r8, pc]
 *   @0xb846c ldrtmi r4, [r8], -r8, lsl #13
 *   @0xb8470 vcgt.s32 d9, d14, d3
 *   @0xb8474 blls 0x1b6f74 <_ZN13CLayerManager4InitEv+0x74>
 *   @0xb8478 .word 0xf8233401
 *   @0xb847c .word 0xf1080018
 *   @0xb8480 ldrbmi r0, [r8, #0x801]
 *   @0xb8484 adcmi sp, r12, #13762560
 *   @0xb8488 ldrsh sp, [r0], -r1
 *   @0xb848c andle r4, lr, #172, #4
 *   @0xb8490 movwls r4, #0x3638
 *   @0xb8494 blx 0xfe9b4d54 <b2_toiTime+0xfffffffffe25b8b0>
 *   @0xb8498 strlo r9, [r1], #-2819
 *   @0xb849c andseq pc, r8, r3, lsr #16
 *   @0xb84a0 stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0xb84a4 ldmible r1!, {r3, r4, r6, r7, r8, r10, lr} ^
 *   @0xb84a8 ldrtmi lr, [r0], -r0, asr #15
 *   @0xb84ac strbmi lr, [r8], -r4
 *   @0xb84b0 vmin.s32 d4, d14, d17
 *   @0xb84b4 andhs pc, r0, r0, asr #30
 *   @0xb84b8 pop {r0, r1, r2, r12, sp, pc}
 *   @0xb84bc push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xb84c0 strdlt r4, r5, [r11], r0
 *   @0xb84c4 ldrmi r6, [r6], -r4, lsl #29
 *   @0xb84c8 adcshi pc, r8, #208, #16
 *   @0xb84cc strtmi r9, [r0], -r5, lsl #2
 *   @0xb84d0 .word 0xf22e69e7
 *   @0xb84d4 andls pc, r9, r8, ror #19
 *   @0xb84d8 .word 0x2100b110
 *   @0xb84dc cmn r11, r4, lsl #2
 *   @0xb84e0 strtmi r10, [r0], -r9, lsl #26
 *   @0xb84e4 vmax.s32 d4, d14, d25
 *   @0xb84e8 blls 0x337124
 *   @0xb84ec mvnsle r2, r0, lsl #22
 *   @0xb84f0 tstle r1, r1, lsl #16
 *   @0xb84f4 strtmi r4, [r9], -r0, lsr #12
 *   @0xb84f8 stc2l p2, c15, [r4], #-184
 *   @0xb84fc strmi r9, [r1], r9, lsl #22
 *   @0xb8500 mvnle r2, r0, lsl #22
 *   @0xb8504 strtmi r4, [r9], -r0, lsr #12
 *   @0xb8508 blx 0xffff4dc8 <b2_toiTime+0xffffffffff89b924>
 *   @0xb850c strmi r9, [r3], -r9, lsl #20
 *   @0xb8510 bhs 0xd05d8 <_Z20Code_Execute_SpecialP9CInstanceS0_P5CCodeP6RValuei+0x4>
 *   @0xb8514 ldmdblt r8, {r0, r5, r6, r7, r8, r12, lr, pc}
 *   @0xb8518 movwls r2, #0x4208
 *   @0xb851c cmp r11, r9, lsl #4
 *   @0xb8520 eoreq lr, r4, sp, lsl #17
 *   @0xb8524 .word 0x21044638
 *   @0xb8528 ldc2 p2, c15, [r1, #188]!
 *   @0xb852c andls r9, r4, r9, lsl #22
 *   @0xb8530 .word 0xf0402b00
 *   @0xb8534 .word 0x469a8151
 *   @0xb8538 qasxmi r6, r0, r3
 *   @0xb853c andle r4, r12, #645922816
 *   @0xb8540 vmax.s32 d4, d14, d25
 *   @0xb8544 bls 0x1f7648 <_ZN9RVariableC2EPKS_+0x244>
 *   @0xb8548 eoreq pc, r10, r2, asr #16
 *   @0xb854c blhs 0xdf178 <_Z5DoAndjPhPKhP6VMExec+0x208>
 *   @0xb8550 .word 0x8142f040
 *   @0xb8554 beq 0x134984 <_Z30F_AudioSetListenerOrientationNR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xb8558 stmdbls r5, {r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0xb855c .word 0xf22e4449
 *   @0xb8560 andls pc, r9, r2, lsr #19
 *   @0xb8564 .word 0xf0402800
 *   @0xb8568 qasxmi r8, r0, r7
 *   @0xb856c vmax.s32 d4, d14, d25
 *   @0xb8570 blls 0x33709c
 *   @0xb8574 blhs 0xd8a3c <_ZN2VM18GetStructureCountsEP15Buffer_Standard+0x130>
 *   @0xb8578 .word 0x812ef040
 *   @0xb857c strtmi r4, [r9], -r0, lsr #12
 *   @0xb8580 blx 0xff0f4e40 <b2_toiTime+0xfffffffffe99b99c>
 *   @0xb8584 strmi r9, [r3], -r9, lsl #20
 *   @0xb8588 bhs 0xd0950 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x304>
 *   @0xb858c .word 0x8124f040
 *   @0xb8590 .word 0x100cf8d8
 *   @0xb8594 stmdavs r9, {r4, r5, r8, r11, pc}
 *   @0xb8598 .word 0xf0404288
 *   @0xb859c stm sp, {r0, r3, r5, r7, pc}
 *   @0xb85a0 ldrtmi r0, [r8], -r4, lsr #32
 *   @0xb85a4 vrhadd.s32 d2, d15, d4
 *   @0xb85a8 blls 0x337b78
 *   @0xb85ac blhs 0xd0a74 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x428>
 *   @0xb85b0 tsthi r2, r0, asr #32
 *   @0xb85b4 ldmvs r3!, {r3, r4, r7, r9, r10, lr} ^
 *   @0xb85b8 subsle r4, r0, #152, #10
 *   @0xb85bc andhs r2, r0, #0, #2
 *   @0xb85c0 eoreq lr, r2, sp, lsl #17
 *   @0xb85c4 ldmdbhi r3!, {r3, r4, r5, r9, r10, lr}
 *   @0xb85c8 .word 0xf8d6210c
 *   @0xb85cc vqadd.s32 d9, d15, d0
 *   @0xb85d0 .word 0xf849fd5e
 *   @0xb85d4 bls 0x2f867c <ps_hints_apply+0x727c>
 *   @0xb85d8 .word 0xf0402a00
 *   @0xb85dc ldmdbvs r3!, {r0, r2, r3, r4, r5, r6, r7, pc}
 *   @0xb85e0 .word 0xf8534691
 *   @0xb85e4 ldmdbhi r2!, {r3, r5, sp, pc}
 *   @0xb85e8 eorsle r4, r5, #608174080
 *   @0xb85ec strtmi r4, [r9], -r0, lsr #12
 *   @0xb85f0 blx 0xfe2f4eb0 <b2_toiTime+0xfffffffffdb9ba0c>
 *   @0xb85f4 blx 0x89ee20 <b2_toiTime+0x14597c>
 *   @0xb85f8 bhs 0xf7400 <_ZN7CFontGMC2EiPKcbi+0x190>
 *   @0xb85fc rschi pc, r12, r0, asr #32
 *   @0xb8600 strtmi r4, [r9], -r0, lsr #12
 *   @0xb8604 blx 0x2074ec4 <b2_toiTime+0x191ba20>
 *   @0xb8608 blx 0x89ee34 <b2_toiTime+0x145990>
 *   @0xb860c bhs 0xf7814 <_ZN7CFontGMC2EP14YYEmbeddedFont+0x188>
 *   @0xb8610 rschi pc, r2, r0, asr #32
 *   @0xb8614 strtmi r4, [r9], -r0, lsr #12
 *   @0xb8618 andgt pc, r12, sp, asr #17
 *   @0xb861c blx 0x1d74edc <b2_toiTime+0x161ba38>
 *   @0xb8620 .word 0xf10a9a09
 *   @0xb8624 .word 0xf8dd0a0c
 *   @0xb8628 addlt r12, r0, #12
 *   @0xb862c .word 0xf0402a00
 *   @0xb8630 blx 0x498984 <g_prim_v+0x8978>
 *   @0xb8634 blx 0x4b7468 <SrcVerts+0x144ac>
 *   @0xb8638 .word 0xf109fc8c
 *   @0xb863c b 0x147aa48 <b2_toiTime+0xd215a4>
 *   @0xb8640 .word 0xf84a028b
 *   @0xb8644 b 0x148367c <b2_toiTime+0xd2a1d8>
 *   @0xb8648 .word 0xf84a028c
 *   @0xb864c andlt r2, r2, #8, #24
 *   @0xb8650 .word 0xf84a0092
 *   @0xb8654 strb r2, [r6, r4, lsl #24]
 *   @0xb8658 stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0xb865c andhs lr, r0, #44826624
 *   @0xb8660 stm sp, {r0, r1, r4, r5, r11, sp, lr}
 *   @0xb8664 ldrtmi r0, [r8], -r4, lsr #32
 *   @0xb8668 vorr d2, d15, d0
 *   @0xb866c blls 0x337ab4
 *   @0xb8670 blhs 0xd0838 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1ec>
 *   @0xb8674 adcshi pc, r0, r0, asr #32
 *   @0xb8678 ldrmi r10, [r11], r9, lsl #20
 *   @0xb867c and r9, r1, r7, lsl #4
 *   @0xb8680 bleq 0x134ab4 <_Z25F_AudioSetEmitterPositionR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0xb8684 ldrmi r6, [r11, #0x833]
 *   @0xb8688 adchi pc, r6, r0, lsl #1
 *   @0xb868c strtmi r9, [r0], -r4, lsl #22
 *   @0xb8690 b 0x149eeac <b2_toiTime+0xd45a08>
 *   @0xb8694 .word 0xf8d6190b
 *   @0xb8698 .word 0xf853a004
 *   @0xb869c bl 0x33c750
 *   @0xb86a0 ldrmi r0, [r1], #-2057
 *   @0xb86a4 .word 0xf8fff22e
 *   @0xb86a8 stmdahs r0, {r0, r3, r12, pc}
 *   @0xb86ac addshi pc, r4, r0, asr #32
 *   @0xb86b0 strtmi r4, [r9], -r0, lsr #12
 *   @0xb86b4 blx 0xa74f74 <b2_toiTime+0x31bad0>
 *   @0xb86b8 andeq pc, r9, r10, asr #16
 *   @0xb86bc blhs 0xdf2e8 <_Z5DoAndjPhPKhP6VMExec+0x378>
 *   @0xb86c0 addhi pc, r10, r0, asr #32
 *   @0xb86c4 strtmi r4, [r9], -r0, lsr #12
 *   @0xb86c8 blx 0x7f4f88 <b2_toiTime+0x9bae4>
 *   @0xb86cc andls r9, r6, r9, lsl #22
 *   @0xb86d0 .word 0xf0402b00
 *   @0xb86d4 strtmi r8, [r0], -r1, lsl #1
 *   @0xb86d8 vmax.s32 d4, d14, d25
 *   @0xb86dc bls 0x336f30
 *   @0xb86e0 .word 0xf8c84603
 *   @0xb86e4 bhs 0xb86fc <.text+0x172c>
 *   @0xb86e8 stmdbls r6, {r1, r2, r4, r5, r6, r8, r12, lr, pc}
 *   @0xb86ec stmdble r2, {r0, r7, r9, lr}
 *   @0xb86f0 movwls r2, #0x9308
 *   @0xb86f4 ldmvs r1!, {r4, r5, r6, sp, lr, pc} ^
 *   @0xb86f8 ldmle r9!, {r3, r7, r9, lr} ^
 *   @0xb86fc eoreq lr, r4, sp, lsl #17
 *   @0xb8700 .word 0x21044638
 *   @0xb8704 stc2l p2, c15, [r3], {47}
 *   @0xb8708 .word 0xf8c89a09
 *   @0xb870c bhs 0xb8734 <.text+0x1764>
 *   @0xb8710 .word 0xf8d8d162
 *   @0xb8714 addsmi r3, r10, #4
 *   @0xb8718 .word 0xf8d8d217
 *   @0xb871c strtmi r3, [r0], -r8
 *   @0xb8720 andls r4, r3, #42991616
 *   @0xb8724 vcgt.s32 d9, d14, d2
 *   @0xb8728 blls 0x176ee4 <_Z18GR_3D_Vertex_Colorfffjf+0x10>
 *   @0xb872c .word 0xf8439a03
 *   @0xb8730 blls 0x2f87c0 <ps_hints_apply+0x73c0>
 *   @0xb8734 .word 0xd14f2b00
 *   @0xb8738 .word 0x3008f8d8
 *   @0xb873c eorne pc, r2, r3, asr r8
 *   @0xb8740 addsmi r6, r9, #15925248
 *   @0xb8744 andlo sp, r1, #212, #4
 *   @0xb8748 .word 0xf85ae7e3
 *   @0xb874c andhs lr, r0, #9
 *   @0xb8750 stm sp, {r3, r4, r5, r9, r10, lr}
 *   @0xb8754 .word 0x21020024
 *   @0xb8758 .word 0xf303fb0e
 *   @0xb875c ldc2 p2, c15, [r7], {47}
 *   @0xb8760 .word 0xf8c89b09
 *   @0xb8764 blhs 0xb879c <.text+0x17cc>
 *   @0xb8768 ldm r8, {r1, r2, r4, r5, r8, r12, lr, pc}
 *   @0xb876c movtmi r0, #0xa006
 *   @0xb8770 addle r4, r5, #805306377
 *   @0xb8774 beq 0xf48b8 <_ZN18CExtensionConstant17LoadFromExeStreamEP7CStream+0x40>
 *   @0xb8778 bl 0x35ef98 <_ZTS12CDS_Priority+0xff0>
 *   @0xb877c ldrmi r0, [r2, #0x903]
 *   @0xb8780 strtmi sp, [r0], -pc, lsl #4
 *   @0xb8784 movwls r10, #0x2909
 *   @0xb8788 rfeib r12!
 *   @0xb878c blls 0x15efb8 <_Z15FacebookUserIdMv+0x3c>
 *   @0xb8790 bllt 0x365198 <_ZTS12CDS_Priority+0x71f0>
 *   @0xb8794 .word 0x200cf8d8
 *   @0xb8798 beq 0x134bc8 <_Z16F_AudioPlaySoundR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0xb879c andseq pc, r9, r2, lsr #16
 *   @0xb87a0 b 0x14b2750 <b2_toiTime+0xd592ac>
 *   @0xb87a4 bl 0xff2f94d0 <b2_toiTime+0xfffffffffeba002c>
 *   @0xb87a8 .word 0xf8d80a0a
 *   @0xb87ac bl 0x3407c4
 *   @0xb87b0 addsmi r0, r1, #1073741826
 *   @0xb87b4 strtmi sp, [r0], -lr, lsl #4
 *   @0xb87b8 movwls r10, #0x2909
 *   @0xb87bc .word 0xf97df22e
 *   @0xb87c0 blls 0x15efec <_Z15FacebookUserIdMv+0x70>
 *   @0xb87c4 .word 0xf8d8b942
 *   @0xb87c8 .word 0xf109200c
 *   @0xb87cc sbcspl r0, r0, #16384
 *   @0xb87d0 strb r3, [r10, r2, lsl #6]!
 *   @0xb87d4 strb r4, [r8, r11, asr #12]
 *   @0xb87d8 stmdbls r4, {r3, r4, r5, r9, r10, lr}
 *   @0xb87dc stc2 p2, c15, [r11, #184]!
 *   @0xb87e0 andlt r9, r11, r9, lsl #16
 *   @0xb87e4 svchi #0xf0e8bd
 *   @0xb87e8 svcmi #0xf0e92d
 *   @0xb87ec ldrmi r11, [r5], -r9, lsl #1
 *   @0xb87f0 .word 0x9c124698
 *   @0xb87f4 cdpls p7, #0x1, c2, c3, c0, #0x0
 *   @0xb87f8 mrsls r9, apsr
 *   @0xb87fc ldrtmi r4, [lr], #-1084
 *   @0xb8800 eorshs pc, r5, r4, asr r8
 *   @0xb8804 eorslo pc, r8, r4, asr r8
 *   @0xb8808 stcle p2, c4, [r2, #-616]
 *   @0xb880c strbmi r4, [r5], -r11, lsr #12
 *   @0xb8810 .word 0xf8544698
 *   @0xb8814 .word 0xf854a035
 *   @0xb8818 .word 0xf856b038
 *   @0xb881c .word 0xf8563035
 *   @0xb8820 ldrbmi r0, [r10, #0x38]
 *   @0xb8824 andeq lr, r3, #206848
 *   @0xb8828 bl 0xff39d040 <b2_toiTime+0xfffffffffec43b9c>
 *   @0xb882c andls r0, r5, #0, #4
 *   @0xb8830 addmi sp, r3, #-1073741823
 *   @0xb8834 strlo sp, [r4, -lr]
 *   @0xb8838 bicsle r2, pc, r8, lsl #30
 *   @0xb883c pop {r0, r3, r12, sp, pc}
 *   @0xb8840 bne 0xff0dc808 <b2_toiTime+0xfffffffffe983364>
 *   @0xb8844 smlabteq r11, r10, r11, lr
 *   @0xb8848 vcgt.s32 d9, d12, d1
 *   @0xb884c blls 0x137524 <_Z18InitSoundFunctionsv+0xdf8>
 *   @0xb8850 and r4, r0, r2, lsl #12
 *   @0xb8854 .word 0xf8dd2200
 *   @0xb8858 stmdbls r7, {r3, r4, r12, pc}
 *   @0xb885c stclle p5, c4, [r10], #548
 *   @0xb8860 eorseq pc, r9, r4, asr r8
 *   @0xb8864 vstmiaeq r9, {s29, s30, s31}
 *   @0xb8868 .word 0xdc014550
 *   @0xb886c and r9, r2, r4, lsl #18
 *   @0xb8870 blle 0x149dd8 <_Z22F_D3DFrustumTestSphereR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0xb8874 strmi r9, [r8], #-2309
 *   @0xb8878 ldrmi lr, [r1], -sp
 *   @0xb887c andeq lr, r0, r10, asr #23
 *   @0xb8880 movwls r9, #0x1203
 *   @0xb8884 andgt pc, r8, sp, asr #17
 *   @0xb8888 blx 0xff0b5190 <b2_toiTime+0xfffffffffe95bcec>
 *   @0xb888c .word 0xf8dd9b01
 *   @0xb8890 bls 0x1a88b8 <_Z19CreateDesktopWindowii+0x64>
 *   @0xb8894 .word 0xf8464418
 *   @0xb8898 .word 0xf109000c
 *   @0xb889c ldrb r0, [r12, r1, lsl #18]
 *   @0xb88a0 andle r2, r12, r0, lsr #16
 *   @0xb88a4 movweq pc, #0x91a0
 *   @0xb88a8 stmdble r8, {r0, r8, r9, r11, sp}
 *   @0xb88ac andle r2, r6, sp, lsl #16
 *   @0xb88b0 andle r2, r4, r12, lsl #16
 *   @0xb88b4 .word 0x0001f1d0
 *   @0xb88b8 andhs r11, r0, r8, lsr pc
 *   @0xb88bc andhs r4, r1, r0, ror r7
 *   @0xb88c0 ldrblt r4, [r8, #0x770]!
 *   @0xb88c4 stmibvs r4, {r0, r1, r2, r3, r4, r9, r10, lr} ^
 *   @0xb88c8 stmibvs r3, {r3, r5, r8, r10, sp}
 *   @0xb88cc blx 0x20a12e <_ZN12CDS_Priority6AssignEPS_+0x6b6>
 *   @0xb88d0 stmdblt r1!, {r0, r1, r8, r10, lr} ^
 *   @0xb88d4 andle r4, r9, #172, #4
 *   @0xb88d8 strheq pc, [r12], -r4
 *   @0xb88dc vmin.s8 d20, d14, d17
 *   @0xb88e0 strtlo pc, [r8], #-3301
 *   @0xb88e4 .word 0xf8444438
 *   @0xb88e8 .word 0xe7f30c18
 *   @0xb88ec adcmi r11, r12, #248, #26
 *   @0xb88f0 rfeib r4!
 *   @0xb88f4 ldrtmi r0, [r1], -lr
 *   @0xb88f8 ldc2l p2, c15, [r8], {78}
 *   @0xb88fc ldrtmi r3, [r8], #-1064
 *   @0xb8900 .word 0x0c14f844
 *   @0xb8904 ldcllt p7, c14, [r8, #972]!
 *   @0xb8908 ldrbmi lr, [r0, sp, lsr #18]!
 *   @0xb890c bvc 0xfeff6c54 <b2_toiTime+0xfffffffffe89d7b0>
 *   @0xb8910 beq 0xfeef6c58 <b2_toiTime+0xfffffffffe79d7b4>
 *   @0xb8914 .word 0xf1400744
 *   @0xb8918 .word 0xf24280c5
 *   @0xb891c blx 0x2060c6 <_ZN8CDS_List3SetEiP6RValueS1_+0x6>
 *   @0xb8920 strlo r7, [r12, #-0x501]!
 *   @0xb8924 smullsvs pc, r4, r5, r8
 *   @0xb8928 .word 0xf0402e00
 *   @0xb892c bhs 0xd8c20 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb>
 *   @0xb8930 subsmi r11, r4, #744
 *   @0xb8934 ldrmi r2, [r4], -r1, lsl #12
 *   @0xb8938 .word 0x0c01f1b1
 *   @0xb893c .word 0x0100f1dc
 *   @0xb8940 qaddeq lr, r1, r12
 *   @0xb8944 .word 0xf010b111
 *   @0xb8948 and r0, r1, r2, lsl #30
 *   @0xb894c svceq #0x1f010
 *   @0xb8950 stmdals r9, {r0, r4, r6, r8, r12, lr, pc}
 *   @0xb8954 strle r0, [r3, #-0x780]
 *   @0xb8958 ldchs p1, c11, [pc], #68
 *   @0xb895c addshi pc, lr, r0, asr #6
 *   @0xb8960 strbeq r9, [r9, r8, lsl #18]
 *   @0xb8964 mcrrhs p5, #0x0, sp, pc, c3
 *   @0xb8968 strbhs r11, [r0], #-4056
 *   @0xb896c ldchs p0, c14, [r8], #-8
 *   @0xb8970 ldrths r11, [r8], #-4024
 *   @0xb8974 stmdbhs r0, {r0, r3, r5, r7, r11, sp, lr}
 *   @0xb8978 addshi pc, r0, r0
 *   @0xb897c bne 0x18d2e28 <b2_toiTime+0x1179984>
 *   @0xb8980 svclt #0xb82800
 *   @0xb8984 stmdahs r7!, {r6, r9, lr}
 *   @0xb8988 ldmdbhs r0!, {r2, r10, r11, r12, lr, pc}
 *   @0xb898c strmi r11, [r12], -r12, lsr #31
 *   @0xb8990 add r2, r3, r0, lsr r4
 *   @0xb8994 .word 0xdc0f2cbf
 *   @0xb8998 teqeq pc, #4
 *   @0xb899c .word 0xdd7d2b09
 *   @0xb89a0 .word 0xf0242b1f
 *   @0xb89a4 .word 0xdc02023f
 *   @0xb89a8 streq pc, [r10], #-258
 *   @0xb89ac blhs 0xe30b8c <b2_toiTime+0x6d76e8>
 *   @0xb89b0 .word 0xf102dc74
 *   @0xb89b4 rsbs r0, r1, r6, lsr r4
 *   @0xb89b8 vstrle s4, [r2, #-0]
 *   @0xb89bc .word 0xdc032b00
 *   @0xb89c0 andsle lr, r5, r5, lsl r0
 *   @0xb89c4 ble 0x5435cc <g_DecodeStringBuffer+0xb58>
 *   @0xb89c8 ldcvs p8, c6, [r2, #488]
 *   @0xb89cc stmdahs r9, {r4, r7, r8, r11, pc}
 *   @0xb89d0 ldmdahs sp, {r3, r8, r11, r12, lr, pc}
 *   @0xb89d4 .word 0xf1c0d80b
 *   @0xb89d8 tsths r4, lr, lsl r0
 *   @0xb89dc vcge.s32 q10, q0, q4
 *   @0xb89e0 .word 0x4603e998
 *   @0xb89e4 rscvc lr, r3, #536576
 *   @0xb89e8 rscvc lr, r3, #165888
 *   @0xb89ec andhs lr, r0, #0
 *   @0xb89f0 strtlo r1, [r0], #-2724
 *   @0xb89f4 .word 0xf105e04c
 *   @0xb89f8 .word 0xf8d5090c
 *   @0xb89fc strtmi r8, [r3], -r8
 *   @0xb8a00 andhs r2, r0, #411041792
 *   @0xb8a04 beq 0x3f4b48 <SV_PixelShader+0xc0>
 *   @0xb8a08 andsle r4, r0, r2, asr #10
 *   @0xb8a0c strls pc, [r2, -r10, lsl #22]
 *   @0xb8a10 .word 0xf8d73201
 *   @0xb8a14 bl 0xff3e8a2c <b2_toiTime+0xfffffffffec8f588>
 *   @0xb8a18 svchs #0x704
 *   @0xb8a1c rsbsmi r11, pc, #184, #30
 *   @0xb8a20 svclt #0xa442af
 *   @0xb8a24 qadd8mi r4, pc, r12
 *   @0xb8a28 ldrtmi r4, [sp], -r3, ror #12
 *   @0xb8a2c addsmi lr, r12, #236, #14
 *   @0xb8a30 eoreq pc, r0, #-1073741824
 *   @0xb8a34 eorseq pc, pc, #34
 *   @0xb8a38 eorlo sp, pc, #4, #22
 *   @0xb8a3c svclt #0xb842a2
 *   @0xb8a40 and r4, r3, r3, lsr #12
 *   @0xb8a44 adcmi r3, r2, #192512
 *   @0xb8a48 strtmi r11, [r3], -r8, asr #31
 *   @0xb8a4c blhs 0x10a4ed8 <b2_toiTime+0x94ba34>
 *   @0xb8a50 .word 0xf103dd21
 *   @0xb8a54 ands r0, r11, r0, lsl r4
 *   @0xb8a58 strle r0, [r2, #-0x702]
 *   @0xb8a5c vldrle d2, [r10, #-252]
 *   @0xb8a60 blhs 0xcb0ab8 <b2_toiTime+0x557614>
 *   @0xb8a64 .word 0xf103dc02
 *   @0xb8a68 and r0, sp, r0, asr #8
 *   @0xb8a6c .word 0xdc0d2b7f
 *   @0xb8a70 .word 0xf0233316
 *   @0xb8a74 blne 0x739778 <g_SWFvertbuff+0x666b0>
 *   @0xb8a78 svclt #0xb82a00
 *   @0xb8a7c bhs 0x4893cc <g_States+0x3a04>
 *   @0xb8a80 stchs p13, c13, [pc], #-44
 *   @0xb8a84 strblo sp, [r0], #-3082
 *   @0xb8a88 and r1, r7, r4, rrx
 *   @0xb8a8c strteq pc, [r0], #-259
 *   @0xb8a90 ldrteq pc, [pc], #-36
 *   @0xb8a94 strbhs lr, [r0], #-2
 *   @0xb8a98 ldrmi lr, [r12], -r0
 *   @0xb8a9c rsbmi r11, r2, #-2147483645
 *   @0xb8aa0 strtmi lr, [r2], -r0
 *   @0xb8aa4 pop {r4, r9, r10, lr}
 *   @0xb8aa8 ldrblt r8, [r3, #-0x7f0]!
 *   @0xb8aac ldmvs r5, {r2, r3, r4, r9, r10, lr}
 *   @0xb8ab0 blvc 0x552c04 <gp_ActiveMaskObjects+0xdf3c>
 *   @0xb8ab4 andls r6, r0, #6684672
 *   @0xb8ab8 andls r7, r1, #34816
 *   @0xb8abc bne 0xffb7f68c <b2_toiTime+0xffffffffff4261e8>
 *   @0xb8ac0 .word 0xff22f7ff
 *   @0xb8ac4 adcvs r4, r0, r8, lsr #8
 *   @0xb8ac8 ldcllt p0, c11, [r0, #-8]!
 *   @0xb8acc svcmi #0xf0e92d
 *   @0xb8ad0 strmi r11, [r10], sp, asr #1
 *   @0xb8ad4 stmdbge r11, {r0, r1, r4, r7, r9, r10, lr}
 *   @0xb8ad8 strmi r2, [r4], -r0, lsl #4
 *   @0xb8adc subspl r4, r0, r0, lsl r6
 *   @0xb8ae0 .word 0xf5b23204
 *   @0xb8ae4 mvnsle r7, r2, lsl #31
 *   @0xb8ae8 stmdbvs r5!, {r1, r2, r4, r6, r8, r11, r12, pc}
 *   @0xb8aec stmibvs r0!, {r0, r3, r6, r7, r9, r11, r12}
 *   @0xb8af0 stmdbvs r7!, {r1, r2, r3, r5, r6, r11, r12} ^
 *   @0xb8af4 stmvs r2!, {r1, r2, r7, r9, lr}
 *   @0xb8af8 bl 0xff1289e0 <b2_toiTime+0xfffffffffe9cf53c>
 *   @0xb8afc stmibvs r0!, {r8, r10} ^
 *   @0xb8b00 addmi r1, r6, #8257536
 *   @0xb8b04 bl 0xff128a2c <b2_toiTime+0xfffffffffe9cf588>
 *   @0xb8b08 bne 0xfebfa710 <b2_toiTime+0xfffffffffe4a126c>
 *   @0xb8b0c bne 0xff0adc78 <b2_toiTime+0xfffffffffe9547d4>
 *   @0xb8b10 mrrcle p2, #0xb, r4, r6, c13
 *   @0xb8b14 mrrcle p15, #0x4, r2, r4, c0
 *   @0xb8b18 stmdaeq r3, {r1, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0xb8b1c blge 0x3a0484 <ft_standard_glyph_names+0x1790>
 *   @0xb8b20 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0xb8b24 orreq lr, r5, #3072
 *   @0xb8b28 blmi 0xa9d73c <b2_toiTime+0x344298>
 *   @0xb8b2c andeq lr, r5, #200, #22
 *   @0xb8b30 ldrbtmi r9, [r11], #-520
 *   @0xb8b34 blls 0x171d760 <b2_toiTime+0xfc42bc>
 *   @0xb8b38 ble 0xaca1a4 <b2_toiTime+0x370d00>
 *   @0xb8b3c strhne pc, [r8], -r6
 *   @0xb8b40 strhhs pc, [r6], -r6
 *   @0xb8b44 strheq pc, [r2], -r6
 *   @0xb8b48 ldrbmi r1, [r1], -r10, lsl #21
 *   @0xb8b4c vhsub.s8 d25, d14, d7
 *   @0xb8b50 .word 0xf8ddfbad
 *   @0xb8b54 .word 0x2100c020
 *   @0xb8b58 strbtmi r4, [r0], #-1112
 *   @0xb8b5c andls r1, r4, #172032
 *   @0xb8b60 .word 0xf0009b09
 *   @0xb8b64 bls 0x17bc68 <_ZN12GraphicsPerf16BuildPerfDisplayEv+0x6c>
 *   @0xb8b68 .word 0xf8533001
 *   @0xb8b6c ldmdapl r2, {r2, r3, r5, r12, sp} ^
 *   @0xb8b70 ldrsbgt pc, [r12], -sp
 *   @0xb8b74 movwhs pc, #0xcb03
 *   @0xb8b78 subspl r9, r3, r3, lsl #20
 *   @0xb8b7c bls 0x1c4f94 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x7b4>
 *   @0xb8b80 adcsmi r4, r10, #33554432
 *   @0xb8b84 .word 0xf109ddec
 *   @0xb8b88 strtlo r0, [r12], -r1, lsl #18
 *   @0xb8b8c blls 0x16b2ae0 <b2_toiTime+0xf5963c>
 *   @0xb8b90 bl 0xff2e2bc4 <b2_toiTime+0xfffffffffeb89720>
 *   @0xb8b94 bl 0xff2ba3a8 <b2_toiTime+0xfffffffffeb60f04>
 *   @0xb8b98 .word 0xf850080b
 *   @0xb8b9c ldmdbne r3!, {r0, r2, r5, sp} ^
 *   @0xb8ba0 addmi r6, r10, #99328
 *   @0xb8ba4 mrsle sp, apsr
 *   @0xb8ba8 addmi r6, r11, #164864
 *   @0xb8bac .word 0x63a3da06
 *   @0xb8bb0 movweq lr, #0x5b08
 *   @0xb8bb4 .word 0xf8c46362
 *   @0xb8bb8 .word 0x6323a02c
 *   @0xb8bbc adcsmi r3, sp, #4194304
 *   @0xb8bc0 sublt sp, sp, r11, ror #27
 *   @0xb8bc4 svchi #0xf0e8bd
 *   @0xb8bc8 eoreq r7, lr, r6, lsr #22
 *   @0xb8bcc push {r0, r9, r11, sp}
 *   @0xb8bd0 .word 0x469b4ff0
 *   @0xb8bd4 .word 0xf8d1bf08
 *   @0xb8bd8 .word 0xf04f800c
 *   @0xb8bdc svclt #0x84300
 *   @0xb8be0 strmi r6, [lr], -sp, lsl #18
 *   @0xb8be4 .word 0xf8d1bf18
 *   @0xb8be8 addlt r8, r11, r4
 *   @0xb8bec stmvs sp, {r3, r4, r8, r9, r10, r11, r12, sp, pc}
 *   @0xb8bf0 movtvs r4, #0x3604
 *   @0xb8bf4 orrvs r2, r3, #0, #6
 *   @0xb8bf8 movtpl pc, #0x4240
 *   @0xb8bfc andne pc, r2, #3072
 *   @0xb8c00 eorhi pc, r12, r0, asr #17
 *   @0xb8c04 blls 0x5d1820 <g_SWFlineaavertbuff+0x7e758>
 *   @0xb8c08 ldmibvs r0!, {r3, r5, r9, r12, sp}
 *   @0xb8c0c ldmdavs r2, {r0, r4, r6, r7, r11, sp, lr} ^
 *   @0xb8c10 andls r9, r7, #8, #2
 *   @0xb8c14 ldmibvs r2!, {r0, r1, r2, r8, r11, r12, pc} ^
 *   @0xb8c18 .word 0xf8cb2900
 *   @0xb8c1c andsvs r8, sp, r0
 *   @0xb8c20 sbcshi pc, lr, r0, asr #6
 *   @0xb8c24 strhvc pc, [r12], -r2
 *   @0xb8c28 .word 0xf04f2301
 *   @0xb8c2c ldrtmi r0, [r10], r8, lsr #24
 *   @0xb8c30 ble 0x389644 <_ZTS13C_UTF16String+0x206f0>
 *   @0xb8c34 .word 0x2103fb0c
 *   @0xb8c38 rfeib r1!
 *   @0xb8c3c addmi r1, pc, #12
 *   @0xb8c40 strmi r11, [pc], -r8, lsr #31
 *   @0xb8c44 svclt #0xb8458a
 *   @0xb8c48 ldrb r4, [r1, r10, lsl #13]!
 *   @0xb8c4c vorr.i32 q2, #0x70000
 *   @0xb8c50 strbmi r8, [r1], -r7, asr #1
 *   @0xb8c54 vmin.s8 d20, d14, d24
 *   @0xb8c58 strbmi pc, [r1], -r9, lsr #22
 *   @0xb8c5c eorvs r4, r0, r8, lsr #8
 *   @0xb8c60 vmin.s8 q10, q7, q0
 *   @0xb8c64 stmdavs r1!, {r0, r1, r5, r8, r9, r11, r12, sp, lr, pc}
 *   @0xb8c68 andseq pc, pc, #33
 *   @0xb8c6c teqeq pc, #33
 *   @0xb8c70 .word 0xf10260a3
 *   @0xb8c74 .word 0xf8c40e20
 *   @0xb8c78 .word 0x6122e014
 *   @0xb8c7c rsbvs r4, r0, r8, lsr #8
 *   @0xb8c80 teqeq pc, #0, #2
 *   @0xb8c84 .word 0xf0234586
 *   @0xb8c88 rscvs r0, r3, pc, lsr r3
 *   @0xb8c8c tsteq pc, #32
 *   @0xb8c90 smulbtvs r0, r8, pc
 *   @0xb8c94 addmi r6, r11, #-1073741784
 *   @0xb8c98 streq pc, [r0, #-0x103]!
 *   @0xb8c9c movweq lr, #0xbc1
 *   @0xb8ca0 strhvs r11, [r1, r8]!
 *   @0xb8ca4 svclt #0xd82b40
 *   @0xb8ca8 bl 0xff151234 <b2_toiTime+0xfffffffffe9f7d90>
 *   @0xb8cac svclt #0xd80205
 *   @0xb8cb0 blhs 0xfe0d1338 <b2_toiTime+0xfffffffffd977e94>
 *   @0xb8cb4 stmdbvs r1!, {r5, r7, r8, r11, sp, lr} ^
 *   @0xb8cb8 bl 0xff111454 <b2_toiTime+0xfffffffffe9b7fb0>
 *   @0xb8cbc eorvs r0, r3, #0, #2
 *   @0xb8cc0 adcvs r6, r2, #268435462
 *   @0xb8cc4 blhs 0x18efce4 <b2_toiTime+0x1196840>
 *   @0xb8cc8 .word 0xf04fbfd4
 *   @0xb8ccc .word 0xf04f0e04
 *   @0xb8cd0 and r0, r1, r8, lsl #28
 *   @0xb8cd4 cdpeq p0, #0x1, c15, c0, c15, #0x2
 *   @0xb8cd8 andeq lr, r3, lr, asr #23
 *   @0xb8cdc bl 0x1896e8 <_Z11loadTextureP7Texture+0xfc>
 *   @0xb8ce0 svclt #0xb8010e
 *   @0xb8ce4 addmi r6, r10, #96, #4
 *   @0xb8ce8 andeq pc, r3, #79
 *   @0xb8cec adcvs r11, r1, #200, #30
 *   @0xb8cf0 svclt #0x48435a
 *   @0xb8cf4 bvs 0x1905508 <b2_toiTime+0x11ac064>
 *   @0xb8cf8 addsmi r1, r1, #146
 *   @0xb8cfc rsbvs r11, r2, #184, #30
 *   @0xb8d00 .word 0xf8d42205
 *   @0xb8d04 cmpmi r3, #36
 *   @0xb8d08 movwlo r11, #0x3f48
 *   @0xb8d0c addsne r6, r11, r2, lsr #21
 *   @0xb8d10 bl 0xff289780 <b2_toiTime+0xfffffffffeb302dc>
 *   @0xb8d14 svclt #0xc8020a
 *   @0xb8d18 andls r6, r9, #805306378
 *   @0xb8d1c ldrmi r6, [r12, #0xaa3]
 *   @0xb8d20 bvs 0x8efe48 <b2_toiTime+0x1969a4>
 *   @0xb8d24 muleq r12, r4, r8
 *   @0xb8d28 bl 0xff3ca340 <b2_toiTime+0xfffffffffec70e9c>
 *   @0xb8d2c ldrmi r0, [r5], #-1280
 *   @0xb8d30 stmdbvs r1!, {r0, r1, r8, r9, r11, r12, lr, pc}
 *   @0xb8d34 ble 0x2c9770 <_ZN7b2World5SolveERK10b2TimeStep+0x134>
 *   @0xb8d38 stmdbvs r1!, {r1, sp, lr, pc} ^
 *   @0xb8d3c stcle p2, c4, [r4, #-564]
 *   @0xb8d40 bl 0x17fa7c <_Z18GR_3D_Light_Enableib+0x15c>
 *   @0xb8d44 strmi r0, [sp], -r5, lsl #18
 *   @0xb8d48 ldrmi lr, [r9], r0
 *   @0xb8d4c bl 0xff0c97a8 <b2_toiTime+0xfffffffffe970304>
 *   @0xb8d50 svclt #0xb4000c
 *   @0xb8d54 andeq lr, r2, #201728
 *   @0xb8d58 andeq lr, r5, #198656
 *   @0xb8d5c stmdbls r9, {r0, r3, r4, r7, r8, r10, lr}
 *   @0xb8d60 bl 0xff328c38 <b2_toiTime+0xfffffffffebcf794>
 *   @0xb8d64 bl 0xff179978 <b2_toiTime+0xfffffffffea204d4>
 *   @0xb8d68 ldrmi r0, [r10], #-777
 *   @0xb8d6c andsgt pc, r0, sp, asr #17
 *   @0xb8d70 vhsub.s32 d9, d12, d5
 *   @0xb8d74 bl 0x2f6ffc <ps_hints_apply+0x5bfc>
 *   @0xb8d78 ldrtmi r0, [r8], -r0, lsl #6
 *   @0xb8d7c ldrmi r9, [r9], -r6, lsl #6
 *   @0xb8d80 blx 0xfe5f56c0 <b2_toiTime+0xfffffffffde9c21c>
 *   @0xb8d84 .word 0x210a9a05
 *   @0xb8d88 .word 0xf8cd9b06
 *   @0xb8d8c movtmi r9, #0xa000
 *   @0xb8d90 mrsls r9, apsr
 *   @0xb8d94 qadd16mi r4, r11, r9
 *   @0xb8d98 bls 0x2dd5a4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x244>
 *   @0xb8d9c bl 0xff0dd5ac <b2_toiTime+0xfffffffffe984108>
 *   @0xb8da0 strtmi r0, [r0], -r5, lsl #28
 *   @0xb8da4 .word 0xf7ff4672
 *   @0xb8da8 .word 0xf8ddfe91
 *   @0xb8dac .word 0xf10cc010
 *   @0xb8db0 ldr r0, [r3, r1, lsl #24]!
 *   @0xb8db4 ldrtmi r6, [r8], -r5, ror #21
 *   @0xb8db8 bl 0xff2d3a50 <b2_toiTime+0xfffffffffeb7a5ac>
 *   @0xb8dbc strbmi r0, [r1], -r5, lsl #16
 *   @0xb8dc0 blx 0x1df5700 <b2_toiTime+0x169c25c>
 *   @0xb8dc4 strtmi r4, [r0], #-1601
 *   @0xb8dc8 beq 0xff0f70e8 <b2_toiTime+0xfffffffffe99dc44>
 *   @0xb8dcc vmin.s8 q10, q7, q0
 *   @0xb8dd0 bls 0x5f778c <g_SWFaavertbuff+0x246c4>
 *   @0xb8dd4 .word 0xf8c64420
 *   @0xb8dd8 .word 0xf8cb0ac4
 *   @0xb8ddc andsvs r5, r4, r0
 *   @0xb8de0 pop {r0, r1, r3, r12, sp, pc}
 *   @0xb8de4 strdeq r8, r9, [r0], -r0
 *   @0xb8de8 subpl pc, r4, #64, #4
 *   @0xb8dec svcmi #0xf0e92d
 *   @0xb8df0 bleq 0xbf4f34 <b2_toiTime+0x49ba90>
 *   @0xb8df4 addlt r6, r5, r5, asr #19
 *   @0xb8df8 strmi r6, [r9], r3, lsl #19
 *   @0xb8dfc andeq pc, r1, r2, lsl #22
 *   @0xb8e00 svclt #0x142900
 *   @0xb8e04 andhs r2, r4, #8, #4
 *   @0xb8e08 .word 0x6c049202
 *   @0xb8e0c blx 0x393c32 <ft_adobe_glyph_list+0x330e>
 *   @0xb8e10 adcsmi r4, r12, #1835008
 *   @0xb8e14 addshi pc, r7, r0, lsl #1
 *   @0xb8e18 blx 0x1416c2 <_Z17YYGML_action_pathP9CInstanceifib+0x26>
 *   @0xb8e1c blmi 0x138d630 <b2_toiTime+0xc3418c>
 *   @0xb8e20 blne 0xf5d634 <b2_toiTime+0x804190>
 *   @0xb8e24 blx 0x17d076 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x27a>
 *   @0xb8e28 strlo pc, [r8, #-0xa02]!
 *   @0xb8e2c .word 0xf1a59a03
 *   @0xb8e30 addsmi r0, r10, #40, #6
 *   @0xb8e34 addhi pc, r7, r0, asr #4
 *   @0xb8e38 stclo p8, c15, [r8], #-212
 *   @0xb8e3c andsmi r9, r3, #8192
 *   @0xb8e40 .word 0x06dbd1f3
 *   @0xb8e44 .word 0xf855d4f1
 *   @0xb8e48 .word 0xf1b91c20
 *   @0xb8e4c .word 0xf8550f01
 *   @0xb8e50 svclt #0x63c24
 *   @0xb8e54 .word 0x6c1af935
 *   @0xb8e58 rfedb r5!
 *   @0xb8e5c rfeib r4!
 *   @0xb8e60 blne 0xfe2fce68 <b2_toiTime+0xfffffffffdba39c4>
 *   @0xb8e64 blle 0x18326c <_ZN8Graphics12UpdateRegionEPviiii+0x2c>
 *   @0xb8e68 bne 0x1792ff4 <b2_toiTime+0x1039b50>
 *   @0xb8e6c and r6, r9, r1, lsr #17
 *   @0xb8e70 stcne p9, c15, [r12], #-220
 *   @0xb8e74 stmdbhs r0, {r0, r4, r5, r6, r9, r11, r12}
 *   @0xb8e78 .word 0xf857db06
 *   @0xb8e7c bne 0x177ff24 <b2_toiTime+0x1026a80>
 *   @0xb8e80 stcne p8, c15, [r4], #-348
 *   @0xb8e84 sub r1, pc, r8, asr r8
 *   @0xb8e88 svceq #0x8f1ba
 *   @0xb8e8c movwhs sp, #0xc11
 *   @0xb8e90 ble 0x1ca3e4 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x94>
 *   @0xb8e94 .word 0xf103fb0b
 *   @0xb8e98 adcsmi r5, r1, #1552
 *   @0xb8e9c blx 0x3afac2 <error_g0017+0x8766>
 *   @0xb8ea0 stmdane r0!, {r0, r1, r8, r12, sp, lr, pc} ^
 *   @0xb8ea4 adcsmi r5, r1, #1552
 *   @0xb8ea8 stmvs r0, {r3, r4, r8, r12, lr, pc}
 *   @0xb8eac movwlo lr, #0x103c
 *   @0xb8eb0 ldrbmi lr, [r1], -lr, ror #15
 *   @0xb8eb4 addmi r2, r11, #0, #6
 *   @0xb8eb8 stmne r8, {r4, r9, r11, r12, lr, pc} ^
 *   @0xb8ebc blx 0x37cfc6 <_ZTS13C_UTF16String+0x14072>
 *   @0xb8ec0 bl 0x1f7ec8 <_Z19GV_BackgroundHTiledP9CInstanceiP6RValue+0x24>
 *   @0xb8ec4 rfedb r4!
 *   @0xb8ec8 strbmi r12, [r6, #-0xc]!
 *   @0xb8ecc strmi sp, [r1], -r1, lsl #20
 *   @0xb8ed0 stcle p7, c14, [r1, #-964]
 *   @0xb8ed4 strb r1, [lr, r3, asr #24]!
 *   @0xb8ed8 mla r5, r0, r8, r6
 *   @0xb8edc .word 0xf303fb0b
 *   @0xb8ee0 stceq p1, c15, [r12], #-652
 *   @0xb8ee4 stmdaeq r12, {r2, r8, r9, r11, sp, lr, pc}
 *   @0xb8ee8 ldrsbne pc, [r0], -r8
 *   @0xb8eec stmne r1!, {r0, r7, r8, r11, r12, sp, pc} ^
 *   @0xb8ef0 .word 0x0008f8d8
 *   @0xb8ef4 cdppl p8, #0xe, c6, c1, c10, #0x4
 *   @0xb8ef8 andlo pc, r12, r4, lsr r9
 *   @0xb8efc .word 0xf8cd1a10
 *   @0xb8f00 bne 0xff328f18 <b2_toiTime+0xfffffffffebcfa74>
 *   @0xb8f04 .word 0xffd7f22b
 *   @0xb8f08 andseq pc, r0, r8, asr #17
 *   @0xb8f0c .word 0xc004f8dd
 *   @0xb8f10 .word 0x3008f8d8
 *   @0xb8f14 andeq pc, r12, r4, lsr r9
 *   @0xb8f18 ldrsbne pc, [r0], -r8
 *   @0xb8f1c movwls r1, #0x1a30
 *   @0xb8f20 .word 0xf9c4f24e
 *   @0xb8f24 ldrmi r9, [r8], #-2817
 *   @0xb8f28 svceq #0xf1b9
 *   @0xb8f2c .word 0xf845d102
 *   @0xb8f30 and r0, r1, r8, lsl r12
 *   @0xb8f34 .word 0x0c14f845
 *   @0xb8f38 stclo p8, c15, [r8], #-212
 *   @0xb8f3c tstmi r3, #8192
 *   @0xb8f40 stclo p8, c15, [r8], #-148
 *   @0xb8f44 andlt lr, r5, r1, ror r7
 *   @0xb8f48 svchi #0xf0e8bd
 *   @0xb8f4c blt 0xc5bde0 <b2_toiTime+0x50293c>
 *   @0xb8f50 ldrbmi lr, [r0, sp, lsr #18]!
 *   @0xb8f54 blo 0xfeff729c <b2_toiTime+0xfffffffffe89ddf8>
 *   @0xb8f58 beq 0xfeef72a0 <b2_toiTime+0xfffffffffe79ddfc>
 *   @0xb8f5c .word 0xf1400745
 *   @0xb8f60 vst4.32 {d24, d25, d26, d27}, [pc], r6
 *   @0xb8f64 bhs 0xce2f0 <_ZN5CCodeD2Ev+0x38>
 *   @0xb8f68 movwlo pc, #0x1b04
 *   @0xb8f6c subsmi r11, r2, #744
 *   @0xb8f70 .word 0x0c01f04f
 *   @0xb8f74 .word 0x0c00f04f
 *   @0xb8f78 .word 0x332c1e4c
 *   @0xb8f7c .word 0x41614261
 *   @0xb8f80 .word 0x8008f8d3
 *   @0xb8f84 .word 0xf010b111
 *   @0xb8f88 and r0, r1, r2, lsl #30
 *   @0xb8f8c svceq #0x1f010
 *   @0xb8f90 .word 0xf1b8d126
 *   @0xb8f94 andle r0, r9, r0, lsl #30
 *   @0xb8f98 bne 0xff51340c <b2_toiTime+0xfffffffffedb9f68>
 *   @0xb8f9c stmdbhs lr, {r0, r1, r2, r5, r8, r12, sp} ^
 *   @0xb8fa0 blhs 0xceefb8 <b2_toiTime+0x595b14>
 *   @0xb8fa4 ldrmi r11, [r10], -r12, lsr #31
 *   @0xb8fa8 subs r2, r12, r0, lsr r2
 *   @0xb8fac .word 0xdc042a35
 *   @0xb8fb0 teqeq r6, #-2147483600
 *   @0xb8fb4 rsbeq lr, r3, #2048
 *   @0xb8fb8 bhs 0xff0b1114 <b2_toiTime+0xfffffffffe957c70>
 *   @0xb8fbc .word 0xf002dc53
 *   @0xb8fc0 blhs 0x2f9cc4 <ps_hints_apply+0x88c4>
 *   @0xb8fc4 blhs 0x630508 <g_SWFaavertbuff+0x5d440>
 *   @0xb8fc8 teqeq pc, r2, lsr #32
 *   @0xb8fcc .word 0xf101dc02
 *   @0xb8fd0 sub r0, r8, r10, lsl #4
 *   @0xb8fd4 blhs 0x387c84 <_ZTS13C_UTF16String+0x1ed30>
 *   @0xb8fd8 .word 0xf101d845
 *   @0xb8fdc sub r0, r2, r6, lsr r2
 *   @0xb8fe0 stmdbeq r12, {r0, r1, r8, r12, sp, lr, pc}
 *   @0xb8fe4 ldrmi r2, [r3], -r2, ror #10
 *   @0xb8fe8 .word 0xf04f2400
 *   @0xb8fec strbmi r0, [r4, #-0xa0c]
 *   @0xb8ff0 blx 0x36d032 <_ZTS13C_UTF16String+0x40de>
 *   @0xb8ff4 strlo r9, [r1], #-1540
 *   @0xb8ff8 blne 0xff6531dc <b2_toiTime+0xfffffffffeef9d38>
 *   @0xb8ffc svclt #0xb82e00
 *   @0xb9000 adcmi r4, lr, #1610612743
 *   @0xb9004 ldrmi r11, [pc], -r4, lsr #31
 *   @0xb9008 ldrtmi r4, [r11], -lr, lsr #12
 *   @0xb900c .word 0xe7ee4635
 *   @0xb9010 .word 0xf103429a
 *   @0xb9014 .word 0xf0240420
 *   @0xb9018 blle 0x1ba11c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x278>
 *   @0xb901c addsmi r3, r4, #788529152
 *   @0xb9020 .word 0x4613bfb8
 *   @0xb9024 stclo p0, c14, [pc], #-12
 *   @0xb9028 svclt #0xc84294
 *   @0xb902c .word 0xb1214613
 *   @0xb9030 vldrle d2, [r7, #-252]
 *   @0xb9034 andseq pc, r0, #-1073741824
 *   @0xb9038 streq lr, [r2, -lr]
 *   @0xb903c blhs 0x10ae44c <b2_toiTime+0x954fa8>
 *   @0xb9040 and sp, r12, r0, lsl sp
 *   @0xb9044 .word 0xdc032b2f
 *   @0xb9048 subeq pc, r0, #-1073741824
 *   @0xb904c and r1, r10, r2, asr r0
 *   @0xb9050 .word 0xdc042b7f
 *   @0xb9054 andseq pc, r6, #-1073741824
 *   @0xb9058 eorseq pc, pc, #34
 *   @0xb905c .word 0xf103e003
 *   @0xb9060 ldrb r0, [r9, r0, lsr #4]!
 *   @0xb9064 .word 0xf1bc2240
 *   @0xb9068 andle r0, r0, r0, lsl #30
 *   @0xb906c ssaxmi r4, r0, r2
 *   @0xb9070 .word 0x87f0e8bd
 *   @0xb9074 svcmi #0xf7e92d
 *   @0xb9078 .word 0xf8d04691
 *   @0xb907c selmi r2, r8, r8
 *   @0xb9080 stmdbls r12, {r2, r3, r4, r9, r10, lr}
 *   @0xb9084 .word 0x0c04f012
 *   @0xb9088 .word 0xf898d111
 *   @0xb908c ldrbeq r3, [r10, r12]
 *   @0xb9090 .word 0xf899d508
 *   @0xb9094 ldrbeq r3, [r11, r12]
 *   @0xb9098 stmdbhs r1, {r2, r8, r10, r12, lr, pc}
 *   @0xb909c ldrhs r11, [r1, #-0xf14]!
 *   @0xb90a0 and r2, r5, r7, lsr r5
 *   @0xb90a4 svclt #0x142901
 *   @0xb90a8 ldrhs r2, [sp, #-0x53b]!
 *   @0xb90ac strbhs lr, [r0, #-0x0]
 *   @0xb90b0 .word 0xa004f8d9
 *   @0xb90b4 .word 0xb004f8d8
 *   @0xb90b8 andgt pc, r4, sp, asr #17
 *   @0xb90bc andeq lr, r10, #207872
 *   @0xb90c0 .word 0xff46f7ff
 *   @0xb90c4 movweq lr, #0xab0b
 *   @0xb90c8 .word 0xc004f8dd
 *   @0xb90cc bicsvc lr, r3, #3072
 *   @0xb90d0 .word 0x0363eb04
 *   @0xb90d4 sbcsvc lr, r0, #0, #22
 *   @0xb90d8 .word 0x0362eba3
 *   @0xb90dc eorseq pc, pc, #19
 *   @0xb90e0 ldmdane lr, {r3, r4, r6, r12, lr, pc}
 *   @0xb90e4 shadd16eq pc, pc, r6
 *   @0xb90e8 adcmi sp, r8, #86
 *   @0xb90ec strbeq pc, [r0], #-450
 *   @0xb90f0 addmi sp, r6, #1280
 *   @0xb90f4 adcsmi sp, r4, #335872
 *   @0xb90f8 rsbsmi sp, r4, #3008
 *   @0xb90fc ldchs p0, c14, [pc, #-316]!
 *   @0xb9100 adcmi sp, r10, #2304
 *   @0xb9104 adcmi sp, r12, #303104
 *   @0xb9108 adcmi sp, lr, #72, #20
 *   @0xb910c .word 0xf1c6da46
 *   @0xb9110 adcmi r0, r10, #64, #4
 *   @0xb9114 .word 0xf000da42
 *   @0xb9118 svchs #0x1f073f
 *   @0xb911c adcsmi sp, r12, #4, #24
 *   @0xb9120 adcsmi sp, lr, #60, #26
 *   @0xb9124 and sp, r1, r10, lsr sp
 *   @0xb9128 strbeq pc, [r0, -r5, asr #3]
 *   @0xb912c blne 0xff93fdd8 <b2_toiTime+0xffffffffff1e6934>
 *   @0xb9130 bl 0xff249b7c <b2_toiTime+0xfffffffffeaf06d8>
 *   @0xb9134 bl 0xff27a150 <b2_toiTime+0xfffffffffeb20cac>
 *   @0xb9138 svclt #0xd80606
 *   @0xb913c adcmi r4, r6, #-1610612732
 *   @0xb9140 rsbsmi r11, r4, #216, #30
 *   @0xb9144 strbvc lr, [r2, #0xa82]!
 *   @0xb9148 strbvc lr, [r2, #0xba5]!
 *   @0xb914c mvnvc lr, r4, lsl #21
 *   @0xb9150 mvnvc lr, r1, lsr #23
 *   @0xb9154 svclt #0xd8428d
 *   @0xb9158 .word 0xf1bc4614
 *   @0xb915c .word 0xd1080f00
 *   @0xb9160 .word 0xdc052c0e
 *   @0xb9164 andeq pc, sp, #111
 *   @0xb9168 svclt #0xb84294
 *   @0xb916c and r4, r0, r4, lsl r6
 *   @0xb9170 strtmi r2, [r3], #-1038
 *   @0xb9174 ldrmi r4, [r8], #-1491
 *   @0xb9178 .word 0xf8c8bfb6
 *   @0xb917c .word 0xf8c83008
 *   @0xb9180 .word 0xf8c90008
 *   @0xb9184 strtmi r0, [r0], -r8
 *   @0xb9188 .word 0xf8c9bfa8
 *   @0xb918c andlt r3, r3, r8
 *   @0xb9190 svchi #0xf0e8bd
 *   @0xb9194 and r4, r2, r4, lsl r6
 *   @0xb9198 and r4, r0, r4, lsr r6
 *   @0xb919c .word 0xf1bc2400
 *   @0xb91a0 sbcsle r0, pc, r0, lsl #30
 *   @0xb91a4 push {r0, r2, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0xb91a8 .word 0x46044ff8
 *   @0xb91ac ldmibvs r0, {r3, r7, r9, r10, lr} ^
 *   @0xb91b0 addmi r6, r8, #3555328
 *   @0xb91b4 ldrmi sp, [r1], -r2, lsl #26
 *   @0xb91b8 .word 0x460b461a
 *   @0xb91bc ldmibvs r8, {r0, r1, r2, r4, r7, r8, r11, sp, lr}
 *   @0xb91c0 ldmibvs lr, {r0, r2, r4, r6, r7, r8, r11, sp, lr} ^
 *   @0xb91c4 bl 0xff209be8 <b2_toiTime+0xfffffffffeab0744>
 *   @0xb91c8 bl 0xff23b5ec <b2_toiTime+0xfffffffffeae2148>
 *   @0xb91cc andle r0, r8, r0, lsl #20
 *   @0xb91d0 ldrhle r4, [r0, -r5]
 *   @0xb91d4 stmibvs r3!, {r0, r2, sp, lr, pc} ^
 *   @0xb91d8 .word 0xdc0542ab
 *   @0xb91dc .word 0x61a3444b
 *   @0xb91e0 strbmi r3, [r4, #-0x428]
 *   @0xb91e4 strd sp, lr, [r4], -r7
 *   @0xb91e8 svclt #0xac42b3
 *   @0xb91ec shsaxmi r4, r11, r3
 *   @0xb91f0 pop {r0, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0xb91f4 blne 0xff0dd1dc <b2_toiTime+0xfffffffffe983d38>
 *   @0xb91f8 .word 0xf22b1b71
 *   @0xb91fc pkhtbmi pc, r3, r12, asr #28
 *   @0xb9200 ldmdale r0, {r2, r6, r8, r10, lr}
 *   @0xb9204 adcmi r6, r8, #224, #18
 *   @0xb9208 strbmi sp, [r8], #-3073
 *   @0xb920c adcsmi lr, r0, #8
 *   @0xb9210 ldrbmi sp, [r0], #-2817
 *   @0xb9214 blne 0x10f122c <b2_toiTime+0x997d88>
 *   @0xb9218 .word 0xf24e4659
 *   @0xb921c ldrtmi pc, [r8], #-2119
 *   @0xb9220 strtlo r6, [r8], #-416
 *   @0xb9224 pop {r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0xb9228 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xb922c .word 0xf04f4ff0
 *   @0xb9230 stmibvs r5, {r3, r5, r8, r11} ^
 *   @0xb9234 stmibvs r3, {r0, r2, r7, r12, sp, pc}
 *   @0xb9238 smlabbls r2, r2, r10, r6
 *   @0xb923c stmdbpl r3, {r0, r3, r8, r9, r11, r12, sp, lr, pc}
 *   @0xb9240 bl 0x153b54 <_Z16InitIAPFunctionsv+0x680>
 *   @0xb9244 movwls r0, #0x3383
 *   @0xb9248 stmdblt r9!, {r0, r1, r3, r5, r9, r10, lr} ^
 *   @0xb924c andle r4, r8, #314572800
 *   @0xb9250 .word 0x33286919
 *   @0xb9254 .word 0x1c10f843
 *   @0xb9258 stcne p8, c15, [r4], #-332
 *   @0xb925c .word 0x1c0cf843
 *   @0xb9260 .word 0xf04fe7f4
 *   @0xb9264 and r0, r12, r4, lsl #20
 *   @0xb9268 andle r4, r8, #314572800
 *   @0xb926c .word 0x33286959
 *   @0xb9270 .word 0x1c10f843
 *   @0xb9274 stcne p8, c15, [r0], #-332
 *   @0xb9278 .word 0x1c0cf843
 *   @0xb927c .word 0xf04fe7f4
 *   @0xb9280 andls r0, r1, #8, #20
 *   @0xb9284 bls 0x19fe90 <_Z11Option_LoadPhjS_+0x95c>
 *   @0xb9288 subsle r4, r8, #805306377
 *   @0xb928c .word 0xf8529a01
 *   @0xb9290 .word 0xf8d66b04
 *   @0xb9294 ldrtmi r8, [r4], -r4, lsr #32
 *   @0xb9298 strbmi r9, [r4, #-0x201]
 *   @0xb929c stmdahi r3!, {r1, r4, r5, r6, r7, r11, r12, lr, pc}
 *   @0xb92a0 svceq #0xaea13
 *   @0xb92a4 strtmi sp, [r3], r1
 *   @0xb92a8 strtlo lr, [r8], #-7
 *   @0xb92ac stchi p7, c14, [r3, #-980]!
 *   @0xb92b0 svceq #0x3ea1a
 *   @0xb92b4 strmi sp, [r7], -r5
 *   @0xb92b8 strbmi r4, [r4, #-0x63c]
 *   @0xb92bc eoreq pc, r8, r4, lsl #2
 *   @0xb92c0 .word 0x4603d3f5
 *   @0xb92c4 strbmi r4, [r7, #-0x607]
 *   @0xb92c8 ldmdahi r10!, {r1, r2, r3, r11, r12, lr, pc}
 *   @0xb92cc svceq #0xaea12
 *   @0xb92d0 strlo sp, [r8, -r1, lsl #2]!
 *   @0xb92d4 .word 0xf1a7e7f7
 *   @0xb92d8 addmi r0, r8, #40, #2
 *   @0xb92dc strtmi sp, [r2], -r12, ror #17
 *   @0xb92e0 .word 0xf7ff463b
 *   @0xb92e4 strb pc, [r7, r0, ror #30]!
 *   @0xb92e8 tstle r3, r12, asr r5
 *   @0xb92ec stmibvs r2!, {r0, r5, r7, r8, r11, sp, lr} ^
 *   @0xb92f0 sbcle r1, r7, r10, lsl #21
 *   @0xb92f4 andle r4, r5, #1610612746
 *   @0xb92f8 qsub8lo r6, r8, r1
 *   @0xb92fc .word 0xf8464411
 *   @0xb9300 .word 0xe7f71c10
 *   @0xb9304 pople {r0, r1, r6, r8, r10, lr}
 *   @0xb9308 .word 0x332869d9
 *   @0xb930c .word 0xf8434411
 *   @0xb9310 .word 0xe7f71c10
 *   @0xb9314 andle r4, r6, #68, #10
 *   @0xb9318 stmdale r4, {r6, r8, r10, lr}
 *   @0xb931c strtmi r4, [r2], -r1, asr #12
 *   @0xb9320 .word 0xf7ff465b
 *   @0xb9324 strmi pc, [r11, #0xf40]!
 *   @0xb9328 .word 0xf1abd9ac
 *   @0xb932c addmi r0, lr, #40, #2
 *   @0xb9330 ldrtmi sp, [r0], -r8, lsr #17
 *   @0xb9334 ldrbmi r4, [r11], -r2, lsr #12
 *   @0xb9338 .word 0xff35f7ff
 *   @0xb933c blls 0x1731cc <_Z24GR_Text_Draw_TransformedffPKciifff+0x164>
 *   @0xb9340 strbmi r11, [sp, #-0x933]
 *   @0xb9344 stmibvs r11!, {r0, r1, r3, r9, r12, lr, pc}
 *   @0xb9348 .word 0xf8453528
 *   @0xb934c .word 0xe7f83c18
 *   @0xb9350 andle r4, r4, #322961408
 *   @0xb9354 strlo r6, [r8, #-0x9ab]!
 *   @0xb9358 .word 0x3c14f845
 *   @0xb935c strdlt lr, pc, [r5], -r8
 *   @0xb9360 svchi #0xf0e8bd
 *   @0xb9364 movwhs r11, #0x57f
 *   @0xb9368 strmi r6, [r4], -r5, lsl #18
 *   @0xb936c movwls r4, #0x360e
 *   @0xb9370 qasxmi r11, r11, sp
 *   @0xb9374 strhle r4, [r8], -r3
 *   @0xb9378 rfeda r1!
 *   @0xb937c movwlo r1, #0x1013
 *   @0xb9380 svclt #0x2842a9
 *   @0xb9384 adclt r4, sp, #13631488
 *   @0xb9388 movwhs lr, #0x7f4
 *   @0xb938c movwls r10, #0x903
 *   @0xb9390 .word 0x91014610
 *   @0xb9394 .word 0x2102461a
 *   @0xb9398 .word 0xf22e1c6b
 *   @0xb939c blls 0x1b8d84 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xcc>
 *   @0xb93a0 ldmdblt r3!, {r5, r6, r7, sp, lr} ^
 *   @0xb93a4 rsbseq r1, r2, r3, ror lr
 *   @0xb93a8 .word 0xf1a22b00
 *   @0xb93ac blle 0x239bbc <_ZN13CPhysicsWorld17ParticleGroupPolyEv+0x24>
 *   @0xb93b0 bpl 0xfe2d363c <b2_toiTime+0xfffffffffdb7a198>
 *   @0xb93b4 .word 0xf82168e1
 *   @0xb93b8 bllo 0x105400 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x14>
 *   @0xb93bc strdvs lr, pc, [r5, -r4]!
 *   @0xb93c0 stmdals r3, {r1, r2, r5, r6, r8, sp, lr}
 *   @0xb93c4 ldcllt p0, c11, [r0, #-16]!
 *   @0xb93c8 ldr r0, [pc, #0x4]
 *   @0xb93cc add r0, pc, r0
 *   @0xb93d0 b 0xb6508 <__cxa_finalize@plt>
 *   @0xb93d4 eorseq r8, r3, r12, lsr #24
 *   @0xb93d8 push {r4, lr}
 *   @0xb93dc ldr r4, [pc, #0x44]
 *   @0xb93e0 ldr r1, [pc, #0x44]
 *   @0xb93e4 add r4, pc, r4
 *   @0xb93e8 ldr r2, [pc, #0x40]
 *   @0xb93ec ldr r3, [pc, #0x40]
 *   @0xb93f0 ldr r0, [r4, r1]
 *   @0xb93f4 ldr r1, [r4, r2]
 *   @0xb93f8 ldr r2, [pc, #0x38]
 *   @0xb93fc add r1, r1, #8
 *   @0xb9400 str r1, [r0]
 *   @0xb9404 add r2, pc, r2
 *   @0xb9408 ldr r1, [r4, r3]
 *   @0xb940c bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9410 mov r0, #0
 *   @0xb9414 bl 0xc4438 <_Z10InitRandomj>
 *   @0xb9418 ldr r3, [pc, #0x1c]
 *   @0xb941c ldr r3, [r4, r3]
 *   @0xb9420 str r0, [r3]
 *   @0xb9424 pop {r4, pc}
 *   @0xb9428 eorseq r8, r3, r12, ror #16
 *   @0xb942c .word 0xffffbd20
 *   @0xb9430 .word 0xffffbd24
 *   @0xb9434 .word 0xffffbd28
 *   @0xb9438 ldrshteq r8, [r3], -r4
 *   @0xb943c .word 0xffffbd18
 *   @0xb9440 push {r3, r4, r5, lr}
 *   @0xb9444 ldr r4, [pc, #0x5c]
 *   @0xb9448 ldr r1, [pc, #0x5c]
 *   @0xb944c add r4, pc, r4
 *   @0xb9450 ldr r2, [pc, #0x58]
 *   @0xb9454 ldr r5, [pc, #0x58]
 *   @0xb9458 ldr r0, [r4, r1]
 *   @0xb945c ldr r3, [pc, #0x54]
 *   @0xb9460 add r5, pc, r5
 *   @0xb9464 ldr r2, [r4, r2]
 *   @0xb9468 add r2, r2, #8
 *   @0xb946c str r2, [r0]
 *   @0xb9470 mov r2, r5
 *   @0xb9474 ldr r1, [r4, r3]
 *   @0xb9478 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb947c ldr r0, [pc, #0x38]
 *   @0xb9480 ldr r1, [pc, #0x38]
 *   @0xb9484 mov r2, r5
 *   @0xb9488 ldr r3, [pc, #0x34]
 *   @0xb948c ldr r0, [r4, r0]
 *   @0xb9490 ldr r1, [r4, r1]
 *   @0xb9494 add r1, r1, #8
 *   @0xb9498 str r1, [r0]
 *   @0xb949c ldr r1, [r4, r3]
 *   @0xb94a0 pop {r3, r4, r5, lr}
 *   @0xb94a4 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb94a8 eorseq r8, r3, r4, lsl #16
 *   @0xb94ac .word 0xffffbd3c
 *   @0xb94b0 .word 0xffffbd40
 *   @0xb94b4 mlaseq r3, r8, r11, r8
 *   @0xb94b8 .word 0xffffbd44
 *   @0xb94bc .word 0xffffbd48
 *   @0xb94c0 .word 0xffffbd4c
 *   @0xb94c4 .word 0xffffbd50
 *   @0xb94c8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xb94cc mov r5, #8
 *   @0xb94d0 ldr r7, [pc, #0xac]
 *   @0xb94d4 mov r1, r5
 *   @0xb94d8 ldr r3, [pc, #0xa8]
 *   @0xb94dc mov r4, #0
 *   @0xb94e0 add r7, pc, r7
 *   @0xb94e4 ldr r9, [pc, #0xa0]
 *   @0xb94e8 ldr r6, [r7, r3]
 *   @0xb94ec add r9, pc, r9
 *   @0xb94f0 mov r0, r6
 *   @0xb94f4 str r4, [r6, #0x4]
 *   @0xb94f8 str r4, [r6]
 *   @0xb94fc str r4, [r6, #0xc]
 *   @0xb9500 str r5, [r6, #0x8]
 *   @0xb9504 bl 0xd1b3c <_ZN18cARRAY_OF_POINTERS9setLengthEi>
 *   @0xb9508 ldr r3, [pc, #0x80]
 *   @0xb950c mov r2, r9
 *   @0xb9510 mov r0, r6
 *   @0xb9514 ldr r8, [r7, r3]
 *   @0xb9518 mov r1, r8
 *   @0xb951c bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9520 ldr r3, [pc, #0x6c]
 *   @0xb9524 mov r1, r5
 *   @0xb9528 ldr r6, [r7, r3]
 *   @0xb952c mov r0, r6
 *   @0xb9530 stmib r6, {r4, r5}
 *   @0xb9534 str r4, [r6]
 *   @0xb9538 str r4, [r6, #0xc]
 *   @0xb953c bl 0xd1b3c <_ZN18cARRAY_OF_POINTERS9setLengthEi>
 *   @0xb9540 mov r2, r9
 *   @0xb9544 mov r1, r8
 *   @0xb9548 mov r0, r6
 *   @0xb954c bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9550 ldr r3, [pc, #0x40]
 *   @0xb9554 mov r1, r5
 *   @0xb9558 ldr r6, [r7, r3]
 *   @0xb955c mov r0, r6
 *   @0xb9560 stmib r6, {r4, r5}
 *   @0xb9564 str r4, [r6]
 *   @0xb9568 str r4, [r6, #0xc]
 *   @0xb956c bl 0xd1b3c <_ZN18cARRAY_OF_POINTERS9setLengthEi>
 *   @0xb9570 mov r0, r6
 *   @0xb9574 mov r1, r8
 *   @0xb9578 mov r2, r9
 *   @0xb957c pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xb9580 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9584 eorseq r8, r3, r0, ror r7
 *   @0xb9588 .word 0xffffbf4c
 *   @0xb958c eorseq r8, r3, r12, lsl #22
 *   @0xb9590 .word 0xffffbf6c
 *   @0xb9594 .word 0xffffbf50
 *   @0xb9598 .word 0xffffbf70
 *   @0xb959c ldr r2, [pc, #0x2c]
 *   @0xb95a0 mov r0, #420
 *   @0xb95a4 ldr r3, [pc, #0x28]
 *   @0xb95a8 ldr r1, [pc, #0x28]
 *   @0xb95ac ldr r2, [pc, r2]
 *   @0xb95b0 add r3, pc, r3
 *   @0xb95b4 ldr r1, [pc, r1]
 *   @0xb95b8 add r1, r1, #8
 *   @0xb95bc str r3, [r3]
 *   @0xb95c0 str r1, [r2]
 *   @0xb95c4 str r3, [r3, #0x4]
 *   @0xb95c8 str r0, [r3, #0x8]
 *   @0xb95cc bx lr
 *   @0xb95d0 eorseq r4, r3, r8, lsl #15
 *   @0xb95d4 eorseq r0, r12, r4, lsl #24
 *   @0xb95d8 ldrhteq r4, [r3], -r8
 *   @0xb95dc push {r3, r4, r5, lr}
 *   @0xb95e0 mov r2, #70
 *   @0xb95e4 ldr r4, [pc, #0xa8]
 *   @0xb95e8 mov r3, #1
 *   @0xb95ec ldr r1, [pc, #0xa4]
 *   @0xb95f0 mov r0, #96
 *   @0xb95f4 add r4, pc, r4
 *   @0xb95f8 mov r5, #0
 *   @0xb95fc add r1, pc, r1
 *   @0xb9600 mov lr, #8
 *   @0xb9604 mov r12, #7
 *   @0xb9608 str lr, [r4]
 *   @0xb960c str r12, [r4, #0x8]
 *   @0xb9610 str r5, [r4, #0x10]
 *   @0xb9614 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xb9618 mov r2, #96
 *   @0xb961c mov r1, r5
 *   @0xb9620 str r0, [r4, #0x10]
 *   @0xb9624 bl 0xb65b0 <memset@plt>
 *   @0xb9628 ldr r2, [r4]
 *   @0xb962c vldr s15, [pc, #92]
 *   @0xb9630 str r5, [r4, #0x4]
 *   @0xb9634 cmp r2, r5
 *   @0xb9638 vmov s13, r2
 *   @0xb963c vcvt.f32.s32 s14, s13
 *   @0xb9640 vmul.f32 s15, s14, s15
 *   @0xb9644 vcvt.s32.f32 s15, s15
 *   @0xb9648 vstr s15, [r4, #12]
 *   @0xb964c ble 0xb9670 <.text+0x26a0>
 *   @0xb9650 ldr r3, [r4, #0x10]
 *   @0xb9654 add r2, r2, r2, lsl #1
 *   @0xb9658 mov r1, r5
 *   @0xb965c add r2, r3, r2, lsl #2
 *   @0xb9660 str r1, [r3, #0x8]
 *   @0xb9664 add r3, r3, #12
 *   @0xb9668 cmp r3, r2
 *   @0xb966c bne 0xb9660 <.text+0x2690>
 *   @0xb9670 ldr r1, [pc, #0x24]
 *   @0xb9674 ldr r0, [pc, #0x24]
 *   @0xb9678 ldr r2, [pc, #0x24]
 *   @0xb967c ldr r1, [pc, r1]
 *   @0xb9680 add r0, pc, r0
 *   @0xb9684 add r2, pc, r2
 *   @0xb9688 pop {r3, r4, r5, lr}
 *   @0xb968c b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9690 svclo #0x19999a
 *   @0xb9694 eorseq r5, r12, r4, lsr #27
 *   @0xb9698 eoreq r7, r7, r4, lsr r10
 *   @0xb969c eorseq r4, r3, r8, lsl #14
 *   @0xb96a0 eorseq r5, r12, r8, lsl sp
 *   @0xb96a4 eorseq r8, r3, r4, ror r9
 *   @0xb96a8 ldr r0, [pc, #0x4]
 *   @0xb96ac ldr r0, [pc, r0]
 *   @0xb96b0 b 0x13aaac <_ZN10yyFindDataC2Ev>
 *   @0xb96b4 ldrsbteq r5, [r3], -r12
 *   @0xb96b8 ldr r1, [pc, #0x2c]
 *   @0xb96bc movw r2, #0x4f80
 *   @0xb96c0 movt r2, #0xc7c3
 *   @0xb96c4 ldr r1, [pc, r1]
 *   @0xb96c8 add r3, r1, #16
 *   @0xb96cc add r1, r1, #112
 *   @0xb96d0 str r2, [r3, #-0x10]
 *   @0xb96d4 add r3, r3, #16
 *   @0xb96d8 str r2, [r3, #-0x1c]
 *   @0xb96dc str r2, [r3, #-0x18]
 *   @0xb96e0 cmp r3, r1
 *   @0xb96e4 bne 0xb96d0 <.text+0x2700>
 *   @0xb96e8 bx lr
 *   @0xb96ec eorseq r5, r3, r0, ror pc
 *   @0xb96f0 ldr r0, [pc, #0x4]
 *   @0xb96f4 ldr r0, [pc, r0]
 *   @0xb96f8 b 0x167e50 <_ZN18RenderStateManagerC2Ev>
 *   @0xb96fc eorseq r4, r3, r4, lsl #12
 *   @0xb9700 push {r4, lr}
 *   @0xb9704 ldr r4, [pc, #0x24]
 *   @0xb9708 ldr r4, [pc, r4]
 *   @0xb970c mov r0, r4
 *   @0xb9710 bl 0x16dce4 <_ZN14CCameraManagerC2Ev>
 *   @0xb9714 ldr r1, [pc, #0x18]
 *   @0xb9718 ldr r2, [pc, #0x18]
 *   @0xb971c mov r0, r4
 *   @0xb9720 ldr r1, [pc, r1]
 *   @0xb9724 add r2, pc, r2
 *   @0xb9728 pop {r4, lr}
 *   @0xb972c b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9730 eorseq r4, r3, r12, ror #10
 *   @0xb9734 eorseq r6, r3, r0, asr #22
 *   @0xb9738 ldrsbteq r8, [r3], -r4
 *   @0xb973c push {r3, r4, r5, lr}
 *   @0xb9740 mov r2, #187
 *   @0xb9744 ldr r4, [pc, #0x50]
 *   @0xb9748 mov r3, #1
 *   @0xb974c ldr r1, [pc, #0x4c]
 *   @0xb9750 mov r0, #1024
 *   @0xb9754 ldr r4, [pc, r4]
 *   @0xb9758 mov r12, #127
 *   @0xb975c add r1, pc, r1
 *   @0xb9760 mov r5, #0
 *   @0xb9764 str r12, [r4, #0x4]
 *   @0xb9768 str r5, [r4, #0x8]
 *   @0xb976c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xb9770 mov r1, r5
 *   @0xb9774 mov r2, #1024
 *   @0xb9778 str r0, [r4]
 *   @0xb977c bl 0xb65b0 <memset@plt>
 *   @0xb9780 ldr r1, [pc, #0x1c]
 *   @0xb9784 mov r0, r4
 *   @0xb9788 ldr r2, [pc, #0x18]
 *   @0xb978c ldr r1, [pc, r1]
 *   @0xb9790 add r2, pc, r2
 *   @0xb9794 pop {r3, r4, r5, lr}
 *   @0xb9798 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb979c ldrhteq r4, [r3], -r12
 *   @0xb97a0 eoreq r1, r9, r8, asr #24
 *   @0xb97a4 eorseq r6, r3, r4, lsl #22
 *   @0xb97a8 eorseq r8, r3, r8, ror #16
 *   @0xb97ac ldr r0, [pc, #0x58]
 *   @0xb97b0 mvn r1, #0
 *   @0xb97b4 ldr r12, [pc, #0x54]
 *   @0xb97b8 add r0, pc, r0
 *   @0xb97bc str r4, [sp, #-0x4]!
 *   @0xb97c0 ldr r12, [pc, r12]
 *   @0xb97c4 mov r4, #0
 *   @0xb97c8 add r3, r0, #32
 *   @0xb97cc add r0, r0, #2832
 *   @0xb97d0 mov r2, r4
 *   @0xb97d4 str r4, [r12]
 *   @0xb97d8 str r4, [r12, #0x4]
 *   @0xb97dc str r2, [r3, #-0x1c]
 *   @0xb97e0 add r3, r3, #28
 *   @0xb97e4 str r2, [r3, #-0x34]
 *   @0xb97e8 str r2, [r3, #-0x30]
 *   @0xb97ec str r2, [r3, #-0x2c]
 *   @0xb97f0 str r2, [r3, #-0x28]
 *   @0xb97f4 str r1, [r3, #-0x24]
 *   @0xb97f8 str r1, [r3, #-0x20]
 *   @0xb97fc cmp r3, r0
 *   @0xb9800 bne 0xb97dc <.text+0x280c>
 *   @0xb9804 ldr r4, [sp], #4
 *   @0xb9808 bx lr
 *   @0xb980c eorseq r8, lr, r4, asr #24
 *   @0xb9810 eorseq r6, r3, r12, lsr #25
 *   @0xb9814 push {r3, r4, r5, r6, r7, lr}
 *   @0xb9818 mov r2, #187
 *   @0xb981c ldr r5, [pc, #0xf0]
 *   @0xb9820 mov r3, #1
 *   @0xb9824 ldr lr, [pc, #0xec]
 *   @0xb9828 mov r0, #4096
 *   @0xb982c add r5, pc, r5
 *   @0xb9830 ldr r1, [pc, #0xe4]
 *   @0xb9834 movw r12, #0x1ff
 *   @0xb9838 mov r4, #0
 *   @0xb983c ldr r6, [r5, lr]
 *   @0xb9840 add r1, pc, r1
 *   @0xb9844 ldr r7, [pc, #0xd4]
 *   @0xb9848 str r12, [r6, #0x4]
 *   @0xb984c add r7, pc, r7
 *   @0xb9850 str r4, [r6, #0x8]
 *   @0xb9854 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xb9858 mov r1, r4
 *   @0xb985c mov r2, #4096
 *   @0xb9860 str r0, [r6]
 *   @0xb9864 bl 0xb65b0 <memset@plt>
 *   @0xb9868 ldr r3, [pc, #0xb4]
 *   @0xb986c mov r2, r7
 *   @0xb9870 mov r0, r6
 *   @0xb9874 ldr r1, [r5, r3]
 *   @0xb9878 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb987c mov r0, #512
 *   @0xb9880 bl 0xcef4c <_Z7YYAlloci>
 *   @0xb9884 ldr r3, [pc, #0x9c]
 *   @0xb9888 mov r1, r4
 *   @0xb988c mov r2, #512
 *   @0xb9890 ldr r6, [r5, r3]
 *   @0xb9894 str r0, [r6]
 *   @0xb9898 bl 0xb65b0 <memset@plt>
 *   @0xb989c ldr r3, [pc, #0x88]
 *   @0xb98a0 mov r1, #128
 *   @0xb98a4 str r4, [r6, #0x8]
 *   @0xb98a8 mov r0, r6
 *   @0xb98ac str r4, [r6, #0xc]
 *   @0xb98b0 mov r2, r7
 *   @0xb98b4 str r1, [r6, #0x4]
 *   @0xb98b8 ldr r1, [r5, r3]
 *   @0xb98bc bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb98c0 ldr r3, [pc, #0x68]
 *   @0xb98c4 ldr r4, [r5, r3]
 *   @0xb98c8 add r6, r4, #352
 *   @0xb98cc mov r0, r4
 *   @0xb98d0 add r4, r4, #88
 *   @0xb98d4 bl 0x190f58 <_ZN13CGCGenerationC2Ev>
 *   @0xb98d8 cmp r4, r6
 *   @0xb98dc bne 0xb98cc <.text+0x28fc>
 *   @0xb98e0 ldr r1, [pc, #0x4c]
 *   @0xb98e4 mov r0, #0
 *   @0xb98e8 ldr r2, [pc, #0x48]
 *   @0xb98ec add r1, pc, r1
 *   @0xb98f0 add r2, pc, r2
 *   @0xb98f4 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb98f8 ldr r3, [pc, #0x3c]
 *   @0xb98fc ldr r2, [pc, #0x3c]
 *   @0xb9900 ldr r3, [r5, r3]
 *   @0xb9904 ldr r2, [r5, r2]
 *   @0xb9908 add r2, r2, #8
 *   @0xb990c str r2, [r3]
 *   @0xb9910 pop {r3, r4, r5, r6, r7, pc}
 *   @0xb9914 eorseq r8, r3, r4, lsr #8
 *   @0xb9918 .word 0xffffbff4
 *   @0xb991c eoreq r3, r9, r12, ror #8
 *   @0xb9920 eorseq r8, r3, r12, lsr #15
 *   @0xb9924 .word 0xffffea40
 *   @0xb9928 .word 0xffffc014
 *   @0xb992c .word 0xffffea44
 *   @0xb9930 .word 0xffffc010
 *   @0xb9934 andeq r7, sp, r0, asr #15
 *   @0xb9938 eorseq r8, r3, r8, lsl #14
 *   @0xb993c .word 0xffffea20
 *   @0xb9940 .word 0xffffea48
 *   @0xb9944 push {r4, r5, r6, lr}
 *   @0xb9948 mov r5, #0
 *   @0xb994c ldr r4, [pc, #0x60]
 *   @0xb9950 ldr r6, [pc, #0x60]
 *   @0xb9954 add r4, pc, r4
 *   @0xb9958 ldr r1, [pc, #0x5c]
 *   @0xb995c add r6, pc, r6
 *   @0xb9960 mov r0, r4
 *   @0xb9964 ldr r1, [pc, r1]
 *   @0xb9968 mov r2, r6
 *   @0xb996c str r5, [r4]
 *   @0xb9970 str r5, [r4, #0x4]
 *   @0xb9974 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9978 ldr r1, [pc, #0x40]
 *   @0xb997c mov r2, r6
 *   @0xb9980 add r0, r4, #8
 *   @0xb9984 str r5, [r4, #0x8]
 *   @0xb9988 ldr r1, [pc, r1]
 *   @0xb998c str r5, [r4, #0xc]
 *   @0xb9990 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9994 ldr r1, [pc, #0x28]
 *   @0xb9998 mov r2, r6
 *   @0xb999c add r0, r4, #16
 *   @0xb99a0 str r5, [r4, #0x10]
 *   @0xb99a4 ldr r1, [pc, r1]
 *   @0xb99a8 str r5, [r4, #0x14]
 *   @0xb99ac pop {r4, r5, r6, lr}
 *   @0xb99b0 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb99b4 subeq r8, r8, r4, ror r12
 *   @0xb99b8 mlaseq r3, r12, r6, r8
 *   @0xb99bc eorseq r6, r3, r4, ror #29
 *   @0xb99c0 eorseq r6, r3, r4, asr #29
 *   @0xb99c4 eorseq r6, r3, r12, lsr #29
 *   @0xb99c8 push {r3, r4, r5, r6, r7, lr}
 *   @0xb99cc mov r4, #0
 *   @0xb99d0 ldr r5, [pc, #0x19c]
 *   @0xb99d4 mov r6, #1
 *   @0xb99d8 ldr r3, [pc, #0x198]
 *   @0xb99dc add r5, pc, r5
 *   @0xb99e0 ldr r7, [pc, #0x194]
 *   @0xb99e4 ldr r1, [pc, #0x194]
 *   @0xb99e8 ldr r3, [r5, r3]
 *   @0xb99ec add r7, pc, r7
 *   @0xb99f0 mov r2, r7
 *   @0xb99f4 str r4, [r3, #0x4]
 *   @0xb99f8 mov r0, r3
 *   @0xb99fc str r4, [r3]
 *   @0xb9a00 str r4, [r3, #0x8]
 *   @0xb9a04 str r6, [r3, #0xc]
 *   @0xb9a08 ldr r1, [r5, r1]
 *   @0xb9a0c bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9a10 ldr r3, [pc, #0x16c]
 *   @0xb9a14 ldr r1, [pc, #0x16c]
 *   @0xb9a18 mov r2, r7
 *   @0xb9a1c ldr r3, [r5, r3]
 *   @0xb9a20 str r4, [r3, #0x4]
 *   @0xb9a24 mov r0, r3
 *   @0xb9a28 str r4, [r3]
 *   @0xb9a2c str r4, [r3, #0x8]
 *   @0xb9a30 str r6, [r3, #0xc]
 *   @0xb9a34 ldr r1, [r5, r1]
 *   @0xb9a38 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9a3c ldr r3, [pc, #0x148]
 *   @0xb9a40 ldr r1, [pc, #0x148]
 *   @0xb9a44 mov r2, r7
 *   @0xb9a48 ldr r3, [r5, r3]
 *   @0xb9a4c str r4, [r3, #0x4]
 *   @0xb9a50 mov r0, r3
 *   @0xb9a54 str r4, [r3]
 *   @0xb9a58 str r4, [r3, #0x8]
 *   @0xb9a5c str r6, [r3, #0xc]
 *   @0xb9a60 ldr r1, [r5, r1]
 *   @0xb9a64 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9a68 ldr r3, [pc, #0x124]
 *   @0xb9a6c ldr r1, [pc, #0x124]
 *   @0xb9a70 mov r2, r7
 *   @0xb9a74 ldr r3, [r5, r3]
 *   @0xb9a78 str r4, [r3, #0x4]
 *   @0xb9a7c mov r0, r3
 *   @0xb9a80 str r4, [r3]
 *   @0xb9a84 str r4, [r3, #0x8]
 *   @0xb9a88 str r6, [r3, #0xc]
 *   @0xb9a8c ldr r1, [r5, r1]
 *   @0xb9a90 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9a94 ldr r3, [pc, #0x100]
 *   @0xb9a98 ldr r1, [pc, #0x100]
 *   @0xb9a9c mov r2, r7
 *   @0xb9aa0 ldr r3, [r5, r3]
 *   @0xb9aa4 str r4, [r3, #0x4]
 *   @0xb9aa8 mov r0, r3
 *   @0xb9aac str r4, [r3]
 *   @0xb9ab0 str r4, [r3, #0x8]
 *   @0xb9ab4 str r6, [r3, #0xc]
 *   @0xb9ab8 ldr r1, [r5, r1]
 *   @0xb9abc bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9ac0 ldr r3, [pc, #0xdc]
 *   @0xb9ac4 ldr r1, [pc, #0xdc]
 *   @0xb9ac8 mov r2, r7
 *   @0xb9acc ldr r3, [r5, r3]
 *   @0xb9ad0 str r4, [r3, #0x4]
 *   @0xb9ad4 mov r0, r3
 *   @0xb9ad8 str r4, [r3]
 *   @0xb9adc str r4, [r3, #0x8]
 *   @0xb9ae0 str r6, [r3, #0xc]
 *   @0xb9ae4 ldr r1, [r5, r1]
 *   @0xb9ae8 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9aec ldr r3, [pc, #0xb8]
 *   @0xb9af0 ldr r1, [pc, #0xb8]
 *   @0xb9af4 mov r2, r7
 *   @0xb9af8 ldr r3, [r5, r3]
 *   @0xb9afc str r4, [r3, #0x4]
 *   @0xb9b00 mov r0, r3
 *   @0xb9b04 str r4, [r3]
 *   @0xb9b08 str r4, [r3, #0x8]
 *   @0xb9b0c str r6, [r3, #0xc]
 *   @0xb9b10 ldr r1, [r5, r1]
 *   @0xb9b14 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9b18 ldr r3, [pc, #0x94]
 *   @0xb9b1c ldr r1, [pc, #0x94]
 *   @0xb9b20 mov r2, r7
 *   @0xb9b24 ldr r3, [r5, r3]
 *   @0xb9b28 str r4, [r3, #0x4]
 *   @0xb9b2c mov r0, r3
 *   @0xb9b30 str r4, [r3]
 *   @0xb9b34 str r4, [r3, #0x8]
 *   @0xb9b38 str r6, [r3, #0xc]
 *   @0xb9b3c ldr r1, [r5, r1]
 *   @0xb9b40 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9b44 ldr r3, [pc, #0x70]
 *   @0xb9b48 ldr r1, [pc, #0x70]
 *   @0xb9b4c mov r2, r7
 *   @0xb9b50 ldr r3, [r5, r3]
 *   @0xb9b54 str r6, [r3, #0xc]
 *   @0xb9b58 mov r0, r3
 *   @0xb9b5c str r4, [r3, #0x4]
 *   @0xb9b60 str r4, [r3]
 *   @0xb9b64 str r4, [r3, #0x8]
 *   @0xb9b68 ldr r1, [r5, r1]
 *   @0xb9b6c pop {r3, r4, r5, r6, r7, lr}
 *   @0xb9b70 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9b74 eorseq r8, r3, r4, ror r2
 *   @0xb9b78 .word 0xffffec0c
 *   @0xb9b7c eorseq r8, r3, r12, lsl #12
 *   @0xb9b80 .word 0xffffee94
 *   @0xb9b84 .word 0xffffec10
 *   @0xb9b88 .word 0xffffee98
 *   @0xb9b8c .word 0xffffec14
 *   @0xb9b90 .word 0xffffee9c
 *   @0xb9b94 .word 0xffffec18
 *   @0xb9b98 .word 0xffffeea0
 *   @0xb9b9c .word 0xffffec1c
 *   @0xb9ba0 .word 0xffffeea4
 *   @0xb9ba4 .word 0xffffec20
 *   @0xb9ba8 .word 0xffffeea8
 *   @0xb9bac .word 0xffffec24
 *   @0xb9bb0 .word 0xffffeeac
 *   @0xb9bb4 .word 0xffffec28
 *   @0xb9bb8 .word 0xffffeeb0
 *   @0xb9bbc .word 0xffffec2c
 *   @0xb9bc0 .word 0xffffeeb4
 *   @0xb9bc4 push {r3, lr}
 *   @0xb9bc8 mov r12, #0
 *   @0xb9bcc ldr r3, [pc, #0x3c]
 *   @0xb9bd0 ldr r1, [pc, #0x3c]
 *   @0xb9bd4 ldr r3, [pc, r3]
 *   @0xb9bd8 ldr r2, [pc, #0x38]
 *   @0xb9bdc ldr r1, [pc, r1]
 *   @0xb9be0 add r2, pc, r2
 *   @0xb9be4 mov r0, r3
 *   @0xb9be8 str r12, [r3]
 *   @0xb9bec str r12, [r3, #0x4]
 *   @0xb9bf0 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9bf4 ldr r0, [pc, #0x20]
 *   @0xb9bf8 mov r3, #0
 *   @0xb9bfc mov r2, #0
 *   @0xb9c00 ldr r0, [pc, r0]
 *   @0xb9c04 strd r2, r3, [r0, #24]
 *   @0xb9c08 pop {r3, lr}
 *   @0xb9c0c b 0x214728 <_ZN13CTimingSource5ResetEv>
 *   @0xb9c10 eorseq r6, r3, r4, asr pc
 *   @0xb9c14 eorseq r6, r3, r12, ror #24
 *   @0xb9c18 eorseq r8, r3, r8, lsl r4
 *   @0xb9c1c eorseq r3, r3, r12, lsr #26
 *   @0xb9c20 ldr r2, [pc, #0x2c]
 *   @0xb9c24 mov r0, #396
 *   @0xb9c28 ldr r3, [pc, #0x28]
 *   @0xb9c2c mov r1, #408
 *   @0xb9c30 ldr r2, [pc, r2]
 *   @0xb9c34 ldr r3, [pc, r3]
 *   @0xb9c38 str r2, [r2]
 *   @0xb9c3c str r2, [r2, #0x4]
 *   @0xb9c40 str r0, [r2, #0x8]
 *   @0xb9c44 str r3, [r3]
 *   @0xb9c48 str r3, [r3, #0x4]
 *   @0xb9c4c str r1, [r3, #0x8]
 *   @0xb9c50 bx lr
 *   @0xb9c54 eorseq r6, r3, r4, lsl #30
 *   @0xb9c58 eorseq r6, r3, r8, lsl #30
 *   @0xb9c64 push {r4, lr}
 *   @0xb9c68 mov r3, #1
 *   @0xb9c6c mov r4, r0
 *   @0xb9c70 add r1, pc, r1
 *   @0xb9c74 mov r0, #128
 *   @0xb9c78 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xb9c7c mov r2, #32
 *   @0xb9c80 mov r3, #0
 *   @0xb9c84 stmib r4, {r2, r3}
 *   @0xb9c88 str r0, [r4]
 *   @0xb9c8c pop {r4, pc}
 *   @0xb9c90 eoreq lr, r7, r8, lsl #21
 *   @0xb9c94 push {r3, r4, r5, r6, r7, lr}
 *   @0xb9c98 ldr r4, [pc, #0x9c]
 *   @0xb9c9c ldr r3, [pc, #0x9c]
 *   @0xb9ca0 add r4, pc, r4
 *   @0xb9ca4 ldr r5, [pc, #0x98]
 *   @0xb9ca8 ldr r6, [r4, r3]
 *   @0xb9cac add r5, pc, r5
 *   @0xb9cb0 mov r0, r6
 *   @0xb9cb4 bl 0xb9c5c <.text+0x2c8c>
 *   @0xb9cb8 ldr r3, [pc, #0x88]
 *   @0xb9cbc mov r0, r6
 *   @0xb9cc0 mov r2, r5
 *   @0xb9cc4 ldr r6, [r4, r3]
 *   @0xb9cc8 mov r1, r6
 *   @0xb9ccc bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9cd0 ldr r3, [pc, #0x74]
 *   @0xb9cd4 ldr r7, [r4, r3]
 *   @0xb9cd8 mov r0, r7
 *   @0xb9cdc bl 0xb9c5c <.text+0x2c8c>
 *   @0xb9ce0 mov r1, r6
 *   @0xb9ce4 mov r2, r5
 *   @0xb9ce8 mov r0, r7
 *   @0xb9cec bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9cf0 ldr r3, [pc, #0x58]
 *   @0xb9cf4 ldr r7, [r4, r3]
 *   @0xb9cf8 mov r0, r7
 *   @0xb9cfc bl 0xb9c5c <.text+0x2c8c>
 *   @0xb9d00 mov r1, r6
 *   @0xb9d04 mov r2, r5
 *   @0xb9d08 mov r0, r7
 *   @0xb9d0c bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9d10 ldr r3, [pc, #0x3c]
 *   @0xb9d14 ldr r12, [pc, #0x3c]
 *   @0xb9d18 mov r1, #0
 *   @0xb9d1c mov r2, r5
 *   @0xb9d20 ldr r3, [r4, r3]
 *   @0xb9d24 str r1, [r3]
 *   @0xb9d28 mov r0, r3
 *   @0xb9d2c str r1, [r3, #0x4]
 *   @0xb9d30 ldr r1, [r4, r12]
 *   @0xb9d34 pop {r3, r4, r5, r6, r7, lr}
 *   @0xb9d38 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9d3c ldrhteq r7, [r3], -r0
 *   @0xb9d40 .word 0xffffbff0
 *   @0xb9d44 eorseq r8, r3, r12, asr #6
 *   @0xb9d48 .word 0xffffef6c
 *   @0xb9d4c .word 0xffffc454
 *   @0xb9d50 .word 0xffffbff8
 *   @0xb9d54 .word 0xffffeef8
 *   @0xb9d58 .word 0xffffef70
 *   @0xb9d5c push {r4, r5, r6, lr}
 *   @0xb9d60 mov r4, #0
 *   @0xb9d64 ldr r5, [pc, #0x84]
 *   @0xb9d68 ldr r3, [pc, #0x84]
 *   @0xb9d6c add r5, pc, r5
 *   @0xb9d70 ldr r6, [pc, #0x80]
 *   @0xb9d74 ldr r1, [pc, #0x80]
 *   @0xb9d78 ldr r3, [r5, r3]
 *   @0xb9d7c add r6, pc, r6
 *   @0xb9d80 mov r2, r6
 *   @0xb9d84 str r4, [r3, #0x4]
 *   @0xb9d88 mov r0, r3
 *   @0xb9d8c str r4, [r3]
 *   @0xb9d90 str r4, [r3, #0x8]
 *   @0xb9d94 ldr r1, [r5, r1]
 *   @0xb9d98 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9d9c ldr r3, [pc, #0x5c]
 *   @0xb9da0 ldr r1, [pc, #0x5c]
 *   @0xb9da4 mov r2, r6
 *   @0xb9da8 ldr r3, [r5, r3]
 *   @0xb9dac str r4, [r3, #0x4]
 *   @0xb9db0 mov r0, r3
 *   @0xb9db4 str r4, [r3]
 *   @0xb9db8 str r4, [r3, #0x8]
 *   @0xb9dbc ldr r1, [r5, r1]
 *   @0xb9dc0 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9dc4 ldr r3, [pc, #0x3c]
 *   @0xb9dc8 ldr r1, [pc, #0x3c]
 *   @0xb9dcc mov r2, r6
 *   @0xb9dd0 ldr r3, [r5, r3]
 *   @0xb9dd4 str r4, [r3, #0x4]
 *   @0xb9dd8 mov r0, r3
 *   @0xb9ddc str r4, [r3]
 *   @0xb9de0 str r4, [r3, #0x8]
 *   @0xb9de4 ldr r1, [r5, r1]
 *   @0xb9de8 pop {r4, r5, r6, lr}
 *   @0xb9dec b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9df0 eorseq r7, r3, r4, ror #29
 *   @0xb9df4 .word 0xffffefc4
 *   @0xb9df8 eorseq r8, r3, r12, ror r2
 *   @0xb9dfc .word 0xfffff030
 *   @0xb9e00 .word 0xffffefb0
 *   @0xb9e04 .word 0xfffff034
 *   @0xb9e08 .word 0xffffefb4
 *   @0xb9e0c .word 0xfffff038
 *   @0xb9e10 push {r4, r5, r6, lr}
 *   @0xb9e14 mov r0, #12
 *   @0xb9e18 bl 0x27c524 <_Znwj>
 *   @0xb9e1c ldr r4, [pc, #0xb4]
 *   @0xb9e20 mov r5, #1
 *   @0xb9e24 add r4, pc, r4
 *   @0xb9e28 mov r6, r0
 *   @0xb9e2c ldr r0, [pc, #0xa8]
 *   @0xb9e30 add r1, r6, #8
 *   @0xb9e34 add r0, pc, r0
 *   @0xb9e38 bl 0x1dbe5c <_ZN11_RefFactoryIPKcE6CreateES1_Ri>
 *   @0xb9e3c ldr r3, [pc, #0x9c]
 *   @0xb9e40 str r5, [r6, #0x4]
 *   @0xb9e44 str r0, [r6]
 *   @0xb9e48 mov r0, #12
 *   @0xb9e4c ldr r3, [r4, r3]
 *   @0xb9e50 str r6, [r3]
 *   @0xb9e54 bl 0x27c524 <_Znwj>
 *   @0xb9e58 mov r6, r0
 *   @0xb9e5c ldr r0, [pc, #0x80]
 *   @0xb9e60 add r1, r6, #8
 *   @0xb9e64 add r0, pc, r0
 *   @0xb9e68 bl 0x1dbe5c <_ZN11_RefFactoryIPKcE6CreateES1_Ri>
 *   @0xb9e6c ldr r3, [pc, #0x74]
 *   @0xb9e70 stm r6, {r0, r5}
 *   @0xb9e74 mov r0, #12
 *   @0xb9e78 ldr r3, [r4, r3]
 *   @0xb9e7c str r6, [r3]
 *   @0xb9e80 bl 0x27c524 <_Znwj>
 *   @0xb9e84 mov r6, r0
 *   @0xb9e88 ldr r0, [pc, #0x5c]
 *   @0xb9e8c add r1, r6, #8
 *   @0xb9e90 add r0, pc, r0
 *   @0xb9e94 bl 0x1dbe5c <_ZN11_RefFactoryIPKcE6CreateES1_Ri>
 *   @0xb9e98 ldr r3, [pc, #0x50]
 *   @0xb9e9c stm r6, {r0, r5}
 *   @0xb9ea0 mov r0, #12
 *   @0xb9ea4 ldr r3, [r4, r3]
 *   @0xb9ea8 str r6, [r3]
 *   @0xb9eac bl 0x27c524 <_Znwj>
 *   @0xb9eb0 mov r6, r0
 *   @0xb9eb4 ldr r0, [pc, #0x38]
 *   @0xb9eb8 add r1, r6, #8
 *   @0xb9ebc add r0, pc, r0
 *   @0xb9ec0 bl 0x1dbe5c <_ZN11_RefFactoryIPKcE6CreateES1_Ri>
 *   @0xb9ec4 ldr r3, [pc, #0x2c]
 *   @0xb9ec8 stm r6, {r0, r5}
 *   @0xb9ecc ldr r3, [r4, r3]
 *   @0xb9ed0 str r6, [r3]
 *   @0xb9ed4 pop {r4, r5, r6, pc}
 *   @0xb9ed8 eorseq r7, r3, r12, lsr #28
 *   @0xb9edc .word 0x002977f4
 *   @0xb9ee0 .word 0xffffce3c
 *   @0xb9ee4 .word 0x002977d4
 *   @0xb9ee8 .word 0xffffcff8
 *   @0xb9eec .word 0x002977b8
 *   @0xb9ef0 .word 0xffffcffc
 *   @0xb9ef4 mlaeq r9, r8, r7, r7
 *   @0xb9ef8 .word 0xffffd000
 *   @0xb9efc push {r3, r4, r5, lr}
 *   @0xb9f00 mov r2, #187
 *   @0xb9f04 ldr r4, [pc, #0x50]
 *   @0xb9f08 mov r3, #1
 *   @0xb9f0c ldr r1, [pc, #0x4c]
 *   @0xb9f10 mov r0, #1024
 *   @0xb9f14 ldr r4, [pc, r4]
 *   @0xb9f18 mov r12, #127
 *   @0xb9f1c add r1, pc, r1
 *   @0xb9f20 mov r5, #0
 *   @0xb9f24 str r12, [r4, #0x4]
 *   @0xb9f28 str r5, [r4, #0x8]
 *   @0xb9f2c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xb9f30 mov r1, r5
 *   @0xb9f34 mov r2, #1024
 *   @0xb9f38 str r0, [r4]
 *   @0xb9f3c bl 0xb65b0 <memset@plt>
 *   @0xb9f40 ldr r1, [pc, #0x1c]
 *   @0xb9f44 mov r0, r4
 *   @0xb9f48 ldr r2, [pc, #0x18]
 *   @0xb9f4c ldr r1, [pc, r1]
 *   @0xb9f50 add r2, pc, r2
 *   @0xb9f54 pop {r3, r4, r5, lr}
 *   @0xb9f58 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xb9f5c eorseq r6, r3, r8, lsl #29
 *   @0xb9f60 eoreq r1, r9, r8, lsl #9
 *   @0xb9f64 eorseq r6, r3, r12, ror lr
 *   @0xb9f68 eorseq r8, r3, r8, lsr #1
 *   @0xb9f6c push {r3, r4, r5, lr}
 *   @0xb9f70 mov r2, #70
 *   @0xb9f74 ldr r4, [pc, #0xa4]
 *   @0xb9f78 mov r3, #1
 *   @0xb9f7c ldr r1, [pc, #0xa0]
 *   @0xb9f80 mov r0, #1536
 *   @0xb9f84 ldr r4, [pc, r4]
 *   @0xb9f88 mov r5, #0
 *   @0xb9f8c add r1, pc, r1
 *   @0xb9f90 mov lr, #128
 *   @0xb9f94 mov r12, #127
 *   @0xb9f98 str lr, [r4]
 *   @0xb9f9c str r12, [r4, #0x8]
 *   @0xb9fa0 str r5, [r4, #0x10]
 *   @0xb9fa4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xb9fa8 mov r2, #1536
 *   @0xb9fac mov r1, r5
 *   @0xb9fb0 str r0, [r4, #0x10]
 *   @0xb9fb4 bl 0xb65b0 <memset@plt>
 *   @0xb9fb8 ldr r2, [r4]
 *   @0xb9fbc vldr s15, [pc, #88]
 *   @0xb9fc0 str r5, [r4, #0x4]
 *   @0xb9fc4 cmp r2, r5
 *   @0xb9fc8 vmov s13, r2
 *   @0xb9fcc vcvt.f32.s32 s14, s13
 *   @0xb9fd0 vmul.f32 s15, s14, s15
 *   @0xb9fd4 vcvt.s32.f32 s15, s15
 *   @0xb9fd8 vstr s15, [r4, #12]
 *   @0xb9fdc ble 0xba000 <.text+0x3030>
 *   @0xb9fe0 add r2, r2, r2, lsl #1
 *   @0xb9fe4 ldr r3, [r4, #0x10]
 *   @0xb9fe8 mov r1, r5
 *   @0xb9fec add r2, r3, r2, lsl #2
 *   @0xb9ff0 str r1, [r3, #0x8]
 *   @0xb9ff4 add r3, r3, #12
 *   @0xb9ff8 cmp r3, r2
 *   @0xb9ffc bne 0xb9ff0 <.text+0x3020>
 *   @0xba000 ldr r1, [pc, #0x20]
 *   @0xba004 mov r0, r4
 *   @0xba008 ldr r2, [pc, #0x1c]
 *   @0xba00c ldr r1, [pc, r1]
 *   @0xba010 add r2, pc, r2
 *   @0xba014 pop {r3, r4, r5, lr}
 *   @0xba018 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba01c svclo #0x19999a
 *   @0xba020 mlaseq r3, r0, lr, r6
 *   @0xba024 eoreq r7, r7, r4, lsr #1
 *   @0xba028 eorseq r6, r3, r4, lsl lr
 *   @0xba02c eorseq r7, r3, r8, ror #31
 *   @0xba030 ldr r3, [pc, #0x24]
 *   @0xba034 mov r12, #0
 *   @0xba038 ldr r1, [pc, #0x20]
 *   @0xba03c ldr r3, [pc, r3]
 *   @0xba040 ldr r2, [pc, #0x1c]
 *   @0xba044 ldr r1, [pc, r1]
 *   @0xba048 add r2, pc, r2
 *   @0xba04c mov r0, r3
 *   @0xba050 str r12, [r3]
 *   @0xba054 str r12, [r3, #0x4]
 *   @0xba058 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba05c eorseq r6, r3, r12, ror #27
 *   @0xba060 eorseq r6, r3, r12, ror #27
 *   @0xba064 ldrhteq r7, [r3], -r0
 *   @0xba068 ldr r3, [pc, #0x24]
 *   @0xba06c mov r12, #0
 *   @0xba070 ldr r1, [pc, #0x20]
 *   @0xba074 ldr r3, [pc, r3]
 *   @0xba078 ldr r2, [pc, #0x1c]
 *   @0xba07c ldr r1, [pc, r1]
 *   @0xba080 add r2, pc, r2
 *   @0xba084 mov r0, r3
 *   @0xba088 str r12, [r3]
 *   @0xba08c str r12, [r3, #0x4]
 *   @0xba090 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba094 eorseq r7, r3, r12, lsr r3
 *   @0xba098 eorseq r7, r3, r12, lsr r3
 *   @0xba09c eorseq r7, r3, r8, ror pc
 *   @0xba0a0 push {r4, r5, r6, r7, r8, lr}
 *   @0xba0a4 mov r5, #0
 *   @0xba0a8 ldr r4, [pc, #0x16c]
 *   @0xba0ac ldr r6, [pc, #0x16c]
 *   @0xba0b0 ldr r7, [pc, #0x16c]
 *   @0xba0b4 add r4, pc, r4
 *   @0xba0b8 ldr r3, [pc, #0x168]
 *   @0xba0bc add r6, pc, r6
 *   @0xba0c0 add r7, pc, r7
 *   @0xba0c4 str r5, [r4, #0x38]
 *   @0xba0c8 str r5, [r4, #0x3c]
 *   @0xba0cc add r0, r4, #56
 *   @0xba0d0 ldr r1, [r6, r3]
 *   @0xba0d4 mov r2, r7
 *   @0xba0d8 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba0dc ldr r3, [pc, #0x148]
 *   @0xba0e0 str r5, [r4, #0x40]
 *   @0xba0e4 mov r2, r7
 *   @0xba0e8 str r5, [r4, #0x44]
 *   @0xba0ec add r0, r4, #64
 *   @0xba0f0 ldr r1, [r6, r3]
 *   @0xba0f4 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba0f8 ldr r3, [pc, #0x130]
 *   @0xba0fc str r5, [r4, #0x20]
 *   @0xba100 mov r2, r7
 *   @0xba104 str r5, [r4, #0x24]
 *   @0xba108 add r0, r4, #32
 *   @0xba10c ldr r8, [r6, r3]
 *   @0xba110 mov r1, r8
 *   @0xba114 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba118 ldr r3, [pc, #0x114]
 *   @0xba11c str r5, [r4, #0x48]
 *   @0xba120 mov r2, r7
 *   @0xba124 str r5, [r4, #0x4c]
 *   @0xba128 add r0, r4, #72
 *   @0xba12c ldr r1, [r6, r3]
 *   @0xba130 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba134 ldr r3, [pc, #0xfc]
 *   @0xba138 str r5, [r4, #0x58]
 *   @0xba13c mov r2, r7
 *   @0xba140 str r5, [r4, #0x5c]
 *   @0xba144 add r0, r4, #88
 *   @0xba148 ldr r1, [r6, r3]
 *   @0xba14c bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba150 ldr r12, [pc, #0xe4]
 *   @0xba154 ldr r3, [pc, #0xe4]
 *   @0xba158 mov r1, r8
 *   @0xba15c mov r2, r7
 *   @0xba160 add r0, r4, #40
 *   @0xba164 ldr r12, [r6, r12]
 *   @0xba168 ldr r3, [r6, r3]
 *   @0xba16c str r5, [r4, #0x28]
 *   @0xba170 ldr r12, [r12]
 *   @0xba174 str r5, [r4, #0x2c]
 *   @0xba178 add r12, r12, #1
 *   @0xba17c str r12, [r3]
 *   @0xba180 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba184 mov r1, r8
 *   @0xba188 mov r2, r7
 *   @0xba18c add r0, r4, #48
 *   @0xba190 str r5, [r4, #0x30]
 *   @0xba194 str r5, [r4, #0x34]
 *   @0xba198 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba19c ldr r3, [pc, #0xa0]
 *   @0xba1a0 mov r1, r8
 *   @0xba1a4 mov r2, r7
 *   @0xba1a8 ldr r3, [r6, r3]
 *   @0xba1ac mov r0, r3
 *   @0xba1b0 str r5, [r3]
 *   @0xba1b4 str r5, [r3, #0x4]
 *   @0xba1b8 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba1bc mov r0, r4
 *   @0xba1c0 bl 0x225cb4 <_ZN9COggAudioC2Ev>
 *   @0xba1c4 ldr r3, [pc, #0x7c]
 *   @0xba1c8 mov r2, r7
 *   @0xba1cc mov r0, r4
 *   @0xba1d0 ldr r1, [r6, r3]
 *   @0xba1d4 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba1d8 ldr r3, [pc, #0x6c]
 *   @0xba1dc str r5, [r4, #0x50]
 *   @0xba1e0 mov r2, r7
 *   @0xba1e4 str r5, [r4, #0x54]
 *   @0xba1e8 add r0, r4, #80
 *   @0xba1ec ldr r1, [r6, r3]
 *   @0xba1f0 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba1f4 ldr r3, [pc, #0x54]
 *   @0xba1f8 ldr r1, [pc, #0x54]
 *   @0xba1fc mov r2, r7
 *   @0xba200 ldr r3, [r6, r3]
 *   @0xba204 str r5, [r3]
 *   @0xba208 mov r0, r3
 *   @0xba20c str r5, [r3, #0x4]
 *   @0xba210 ldr r1, [r6, r1]
 *   @0xba214 pop {r4, r5, r6, r7, r8, lr}
 *   @0xba218 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba21c rsbeq r11, r9, r0, ror #3
 *   @0xba220 mlaseq r3, r4, r11, r7
 *   @0xba224 eorseq r7, r3, r8, lsr pc
 *   @0xba228 .word 0xfffff7ac
 *   @0xba22c .word 0xfffff7b0
 *   @0xba230 .word 0xfffff7b4
 *   @0xba234 .word 0xffffebfc
 *   @0xba238 .word 0xffffec00
 *   @0xba23c .word 0xfffff794
 *   @0xba240 .word 0xfffff7a0
 *   @0xba244 .word 0xfffff788
 *   @0xba248 .word 0xfffff7b8
 *   @0xba24c .word 0xfffff7bc
 *   @0xba250 .word 0xfffff7a8
 *   @0xba254 .word 0xfffff7c0
 *   @0xba258 ldr r0, [pc, #0x4]
 *   @0xba25c ldr r0, [pc, r0]
 *   @0xba260 b 0x21de3c <_ZN14CAudioGroupManC2Ev>
 *   @0xba264 ldrshteq r4, [r3], -r4
 *   @0xba268 ldr r3, [pc, #0x24]
 *   @0xba26c mov r12, #0
 *   @0xba270 ldr r1, [pc, #0x20]
 *   @0xba274 ldr r3, [pc, r3]
 *   @0xba278 ldr r2, [pc, #0x1c]
 *   @0xba27c ldr r1, [pc, r1]
 *   @0xba280 add r2, pc, r2
 *   @0xba284 mov r0, r3
 *   @0xba288 str r12, [r3]
 *   @0xba28c str r12, [r3, #0x4]
 *   @0xba290 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba294 eorseq r7, r3, r4, lsr #3
 *   @0xba298 eorseq r7, r3, r4, lsr #3
 *   @0xba29c eorseq r7, r3, r8, ror sp
 *   @0xba2a0 push {r4, r5, r6, lr}
 *   @0xba2a4 mov r5, #0
 *   @0xba2a8 ldr r4, [pc, #0x44]
 *   @0xba2ac ldr r6, [pc, #0x44]
 *   @0xba2b0 add r4, pc, r4
 *   @0xba2b4 ldr r1, [pc, #0x40]
 *   @0xba2b8 add r6, pc, r6
 *   @0xba2bc mov r0, r4
 *   @0xba2c0 ldr r1, [pc, r1]
 *   @0xba2c4 mov r2, r6
 *   @0xba2c8 str r5, [r4]
 *   @0xba2cc str r5, [r4, #0x4]
 *   @0xba2d0 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba2d4 ldr r1, [pc, #0x24]
 *   @0xba2d8 mov r2, r6
 *   @0xba2dc add r0, r4, #8
 *   @0xba2e0 str r5, [r4, #0x8]
 *   @0xba2e4 str r5, [r4, #0xc]
 *   @0xba2e8 ldr r1, [pc, r1]
 *   @0xba2ec pop {r4, r5, r6, lr}
 *   @0xba2f0 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba2f4 rsbeq r11, r9, r8, lsl #1
 *   @0xba2f8 eorseq r7, r3, r0, asr #26
 *   @0xba2fc eorseq r7, r3, r4, ror #2
 *   @0xba300 eorseq r6, r3, r4, ror #10
 *   @0xba304 push {r3, r4, r5, lr}
 *   @0xba308 mov r2, #187
 *   @0xba30c ldr r4, [pc, #0x50]
 *   @0xba310 mov r3, #1
 *   @0xba314 ldr r1, [pc, #0x4c]
 *   @0xba318 mov r0, #8192
 *   @0xba31c ldr r4, [pc, r4]
 *   @0xba320 movw r12, #0x3ff
 *   @0xba324 add r1, pc, r1
 *   @0xba328 mov r5, #0
 *   @0xba32c str r12, [r4, #0x4]
 *   @0xba330 str r5, [r4, #0x8]
 *   @0xba334 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xba338 mov r1, r5
 *   @0xba33c mov r2, #8192
 *   @0xba340 str r0, [r4]
 *   @0xba344 bl 0xb65b0 <memset@plt>
 *   @0xba348 ldr r1, [pc, #0x1c]
 *   @0xba34c mov r0, r4
 *   @0xba350 ldr r2, [pc, #0x18]
 *   @0xba354 ldr r1, [pc, r1]
 *   @0xba358 add r2, pc, r2
 *   @0xba35c pop {r3, r4, r5, lr}
 *   @0xba360 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba364 eorseq r7, r3, r8, lsl #3
 *   @0xba368 eoreq r2, r9, r8, lsl #19
 *   @0xba36c eorseq r7, r3, r8, ror #2
 *   @0xba370 eorseq r7, r3, r0, lsr #25
 *   @0xba374 push {r3, r4, r5, lr}
 *   @0xba378 mov r2, #187
 *   @0xba37c ldr r4, [pc, #0x50]
 *   @0xba380 mov r3, #1
 *   @0xba384 ldr r1, [pc, #0x4c]
 *   @0xba388 mov r0, #4096
 *   @0xba38c ldr r4, [pc, r4]
 *   @0xba390 movw r12, #0x1ff
 *   @0xba394 add r1, pc, r1
 *   @0xba398 mov r5, #0
 *   @0xba39c str r12, [r4, #0x4]
 *   @0xba3a0 str r5, [r4, #0x8]
 *   @0xba3a4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xba3a8 mov r1, r5
 *   @0xba3ac mov r2, #4096
 *   @0xba3b0 str r0, [r4]
 *   @0xba3b4 bl 0xb65b0 <memset@plt>
 *   @0xba3b8 ldr r1, [pc, #0x1c]
 *   @0xba3bc mov r0, r4
 *   @0xba3c0 ldr r2, [pc, #0x18]
 *   @0xba3c4 ldr r1, [pc, r1]
 *   @0xba3c8 add r2, pc, r2
 *   @0xba3cc pop {r3, r4, r5, lr}
 *   @0xba3d0 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba3d4 eorseq r7, r3, r8, asr r1
 *   @0xba3d8 eoreq r2, r9, r8, lsl r9
 *   @0xba3dc eorseq r7, r3, r4, lsr #2
 *   @0xba3e0 eorseq r7, r3, r0, lsr r12
 *   @0xba3e4 push {r4, r5, r6, lr}
 *   @0xba3e8 mov r2, #70
 *   @0xba3ec ldr r4, [pc, #0x154]
 *   @0xba3f0 mov r3, #1
 *   @0xba3f4 ldr r5, [pc, #0x150]
 *   @0xba3f8 mov r0, #96
 *   @0xba3fc add r4, pc, r4
 *   @0xba400 ldr r1, [pc, #0x148]
 *   @0xba404 mov r6, #0
 *   @0xba408 mov lr, #8
 *   @0xba40c ldr r5, [r4, r5]
 *   @0xba410 add r1, pc, r1
 *   @0xba414 mov r12, #7
 *   @0xba418 str lr, [r5]
 *   @0xba41c str r12, [r5, #0x8]
 *   @0xba420 str r6, [r5, #0x10]
 *   @0xba424 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xba428 mov r2, #96
 *   @0xba42c mov r1, r6
 *   @0xba430 str r0, [r5, #0x10]
 *   @0xba434 bl 0xb65b0 <memset@plt>
 *   @0xba438 ldr r2, [r5]
 *   @0xba43c vldr s15, [pc, #256]
 *   @0xba440 str r6, [r5, #0x4]
 *   @0xba444 cmp r2, r6
 *   @0xba448 vmov s13, r2
 *   @0xba44c vcvt.f32.s32 s14, s13
 *   @0xba450 vmul.f32 s15, s14, s15
 *   @0xba454 vcvt.s32.f32 s15, s15
 *   @0xba458 vstr s15, [r5, #12]
 *   @0xba45c ble 0xba480 <.text+0x34b0>
 *   @0xba460 add r2, r2, r2, lsl #1
 *   @0xba464 ldr r3, [r5, #0x10]
 *   @0xba468 mov r1, r6
 *   @0xba46c add r2, r3, r2, lsl #2
 *   @0xba470 str r1, [r3, #0x8]
 *   @0xba474 add r3, r3, #12
 *   @0xba478 cmp r3, r2
 *   @0xba47c bne 0xba470 <.text+0x34a0>
 *   @0xba480 ldr r3, [pc, #0xcc]
 *   @0xba484 mov r0, r5
 *   @0xba488 ldr r2, [pc, #0xc8]
 *   @0xba48c ldr r1, [r4, r3]
 *   @0xba490 add r2, pc, r2
 *   @0xba494 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba498 ldr r2, [pc, #0xbc]
 *   @0xba49c ldr r3, [pc, #0xbc]
 *   @0xba4a0 ldr r1, [pc, #0xbc]
 *   @0xba4a4 ldr r0, [r4, r2]
 *   @0xba4a8 ldr r12, [r4, r3]
 *   @0xba4ac ldr r3, [pc, #0xb4]
 *   @0xba4b0 add r12, r12, #8
 *   @0xba4b4 ldr r2, [pc, #0xb0]
 *   @0xba4b8 str r12, [r0]
 *   @0xba4bc ldr r0, [r4, r1]
 *   @0xba4c0 ldr r12, [r4, r3]
 *   @0xba4c4 ldr r3, [pc, #0xa4]
 *   @0xba4c8 add r12, r12, #8
 *   @0xba4cc ldr r1, [pc, #0xa0]
 *   @0xba4d0 str r12, [r0]
 *   @0xba4d4 ldr r0, [r4, r2]
 *   @0xba4d8 ldr r12, [r4, r3]
 *   @0xba4dc ldr r3, [pc, #0x94]
 *   @0xba4e0 add r12, r12, #8
 *   @0xba4e4 ldr r2, [pc, #0x90]
 *   @0xba4e8 str r12, [r0]
 *   @0xba4ec ldr r0, [r4, r1]
 *   @0xba4f0 ldr r12, [r4, r3]
 *   @0xba4f4 ldr r3, [pc, #0x84]
 *   @0xba4f8 add r12, r12, #8
 *   @0xba4fc ldr r1, [pc, #0x80]
 *   @0xba500 str r12, [r0]
 *   @0xba504 ldr r0, [r4, r2]
 *   @0xba508 ldr r12, [r4, r3]
 *   @0xba50c ldr r2, [pc, #0x74]
 *   @0xba510 add r12, r12, #8
 *   @0xba514 ldr r3, [pc, #0x70]
 *   @0xba518 str r12, [r0]
 *   @0xba51c ldr r1, [r4, r1]
 *   @0xba520 ldr r0, [r4, r2]
 *   @0xba524 ldr r2, [pc, #0x64]
 *   @0xba528 add r0, r0, #8
 *   @0xba52c str r0, [r1]
 *   @0xba530 ldr r3, [r4, r3]
 *   @0xba534 ldr r2, [r4, r2]
 *   @0xba538 add r2, r2, #8
 *   @0xba53c str r2, [r3]
 *   @0xba540 pop {r4, r5, r6, pc}
 *   @0xba544 svclo #0x19999a
 *   @0xba548 eorseq r7, r3, r4, asr r8
 *   @0xba54c .word 0xfffffbd0
 *   @0xba550 eoreq r6, r7, r0, lsr #24
 *   @0xba554 .word 0xfffffc14
 *   @0xba558 eorseq r7, r3, r8, ror #22
 *   @0xba55c .word 0xfffffbe8
 *   @0xba560 .word 0xfffffc18
 *   @0xba564 .word 0xfffffbec
 *   @0xba568 .word 0xfffffc1c
 *   @0xba56c .word 0xfffffbf0
 *   @0xba570 .word 0xfffffc20
 *   @0xba574 .word 0xfffffbf4
 *   @0xba578 .word 0xfffffc24
 *   @0xba57c .word 0xfffffbf8
 *   @0xba580 .word 0xfffffc28
 *   @0xba584 .word 0xfffffbfc
 *   @0xba588 .word 0xfffffc2c
 *   @0xba58c .word 0xfffffc08
 *   @0xba590 .word 0xfffffc30
 *   @0xba594 ldr r0, [pc, #0x4]
 *   @0xba598 ldr r0, [pc, r0]
 *   @0xba59c b 0x2a00a4 <_ZN9CProfilerC2Ev>
 *   @0xba5a0 ldrsbteq r3, [r3], -r4
 *   @0xba5a4 ldr r3, [pc, #0x10]
 *   @0xba5a8 mov r2, #0
 *   @0xba5ac ldr r3, [pc, r3]
 *   @0xba5b0 str r2, [r3]
 *   @0xba5b4 str r2, [r3, #0x4]
 *   @0xba5b8 bx lr
 *   @0xba5bc eorseq r6, r3, r12, lsr #30
 *   @0xba5c0 push {r3, r4, r5, lr}
 *   @0xba5c4 ldr r4, [pc, #0x5c]
 *   @0xba5c8 ldr r1, [pc, #0x5c]
 *   @0xba5cc add r4, pc, r4
 *   @0xba5d0 ldr r2, [pc, #0x58]
 *   @0xba5d4 ldr r5, [pc, #0x58]
 *   @0xba5d8 ldr r0, [r4, r1]
 *   @0xba5dc ldr r3, [pc, #0x54]
 *   @0xba5e0 add r5, pc, r5
 *   @0xba5e4 ldr r2, [r4, r2]
 *   @0xba5e8 add r2, r2, #8
 *   @0xba5ec str r2, [r0]
 *   @0xba5f0 mov r2, r5
 *   @0xba5f4 ldr r1, [r4, r3]
 *   @0xba5f8 bl 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba5fc ldr r0, [pc, #0x38]
 *   @0xba600 ldr r1, [pc, #0x38]
 *   @0xba604 mov r2, r5
 *   @0xba608 ldr r3, [pc, #0x34]
 *   @0xba60c ldr r0, [r4, r0]
 *   @0xba610 ldr r1, [r4, r1]
 *   @0xba614 add r1, r1, #8
 *   @0xba618 str r1, [r0]
 *   @0xba61c ldr r1, [r4, r3]
 *   @0xba620 pop {r3, r4, r5, lr}
 *   @0xba624 b 0xb65f8 <__aeabi_atexit@plt>
 *   @0xba628 eorseq r7, r3, r4, lsl #13
 *   @0xba62c .word 0xfffffe94
 *   @0xba630 .word 0xfffffe90
 *   @0xba634 eorseq r7, r3, r8, lsl r10
 *   @0xba638 .word 0xfffffea0
 *   @0xba63c .word 0xfffffe98
 *   @0xba640 .word 0xfffff870
 *   @0xba644 .word 0xfffffea4
 *   @0xba648 ldr r3, [pc, #0x18]
 *   @0xba64c mov r2, #0
 *   @0xba650 ldr r3, [pc, r3]
 *   @0xba654 strb r2, [r3]
 *   @0xba658 strb r2, [r3, #0x1]
 *   @0xba65c strb r2, [r3, #0x2]
 *   @0xba660 strb r2, [r3, #0x3]
 *   @0xba664 bx lr
 *   @0xba668 eorseq r6, r3, r12, lsl #29
 *   @0xba66c ldmdbmi r5, {r2, r4, r11, lr}
 *   @0xba670 ldrbtmi r11, [r8], #-1336
 *   @0xba674 .word 0xf7fc4479
 *   @0xba678 strmi lr, [r5], -r8, ror #22
 *   @0xba67c .word 0x4c12b9d8
 *   @0xba680 strmi r2, [r1], -r12, lsl #6
 *   @0xba684 .word 0xf104447c
 *   @0xba688 eorvs r0, r3, r12
 *   @0xba68c cmnvs pc, #12582912
 *   @0xba690 vhadd.s8 d22, d16, d19
 *   @0xba694 rsbvs r1, r3, r5, asr r3
 *   @0xba698 bl 0x478690 <g_RomDisk+0x80e70>
 *   @0xba69c stmdbmi r12, {r0, r1, r3, r11, lr}
 *   @0xba6a0 ldrbtmi r4, [r8], #-2572
 *   @0xba6a4 .word 0x61654479
 *   @0xba6a8 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr}
 *   @0xba6ac pop {r0, r2, r5, r8, sp, lr}
 *   @0xba6b0 vqadd.s32 d20, d1, d24
 *   @0xba6b4 stmdami r8, {r0, r1, r3, r4, r6, r9, r11, r12, sp, pc}
 *   @0xba6b8 .word 0xf25d4478
 *   @0xba6bc svclt #0xfa0f
 *   @0xba6c0 rsbeq lr, r9, lr, asr #28
 *   @0xba6c4 mlaeq r5, r9, sp, r12
 *   @0xba6c8 rsbeq lr, r9, r4, lsr #28
 *   @0xba6cc rsbeq lr, r9, r2, lsl #28
 *   @0xba6d0 mlaeq r5, r5, sp, r12
 *   @0xba6d4 eorseq r7, r3, r0, ror #10
 *   @0xba6d8 mlaeq r10, r4, lr, r1
 *   @0xba6dc cmp r0, #0
 *   @0xba6e0 push {r3, lr}
 *   @0xba6e4 popeq {r3, pc}
 *   @0xba6e8 blx r0
 *   @0xba6ec pop {r3, pc}
 *   @0xba6f0 mov r1, r0
 *   @0xba6f4 ldr r2, [pc, #0xc]
 *   @0xba6f8 ldr r0, [pc, #0xc]
 *   @0xba6fc add r2, pc, r2
 *   @0xba700 add r0, pc, r0
 *   @0xba704 b 0xb64fc <__cxa_atexit@plt>
 *   @0xba708 ldrshteq r7, [r3], -r12
 *
 * ══ §2/7 spSkeletonJson_readSkeletonData  0x28b84c  size 13044  3261 条（0x28b84c..0x28eb40）
 * @func 0x28b84c 0x28eb40  size 13044  3261 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Json_getFloat×59 / Json_getItem×31 / Json_getString×31 / 0xb6574×27 / _malloc×25 / _spSkeletonJson_setError×21 / anon_28b34c+0x334×16 / Json_getInt×14
 * 字段偏移 top8: 0x4×72 / 0xc×69 / 0x1c×67 / 0x18×57 / 0x10×41 / 0x8×39 / 0x2c×39 / 0x20×34
 * VFP 指令 172 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b84c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x28b850 vpush {d8}
 *   @0x28b854 mov r8, r0
 *   @0x28b858 sub sp, sp, #124
 *   @0x28b85c ldr r0, [r0, #0x8]
 *   @0x28b860 mov r5, r1
 *   @0x28b864 bl 0x285c80 <_free>
 *   @0x28b868 mov r3, #0
 *   @0x28b86c mov r0, #1
 *   @0x28b870 mov r1, r3
 *   @0x28b874 str r3, [r8, #0x8]
 *   @0x28b878 str r3, [r8, #0x10]
 *   @0x28b87c bl 0xb679c <setlocale@plt>
 *   @0x28b880 subs r4, r0, #0
 *   @0x28b884 beq 0x28bf58 <spSkeletonJson_readSkeletonData+0x70c>
 *   @0x28b888 bl 0xb6640 <strdup@plt>
 *   @0x28b88c ldr r1, [pc, #0xf50]
 *   @0x28b890 add r1, pc, r1
 *   @0x28b894 mov r4, r0
 *   @0x28b898 mov r0, #1
 *   @0x28b89c bl 0xb679c <setlocale@plt>
 *   @0x28b8a0 mov r0, r5
 *   @0x28b8a4 bl 0x287320 <Json_create>
 *   @0x28b8a8 mov r1, r4
 *   @0x28b8ac str r0, [sp, #0x24]
 *   @0x28b8b0 mov r0, #1
 *   @0x28b8b4 bl 0xb679c <setlocale@plt>
 *   @0x28b8b8 cmp r4, #0
 *   @0x28b8bc beq 0x28b8c8 <spSkeletonJson_readSkeletonData+0x7c>
 *   @0x28b8c0 mov r0, r4
 *   @0x28b8c4 bl 0xb655c <free@plt>
 *   @0x28b8c8 ldr r0, [sp, #0x24]
 *   @0x28b8cc cmp r0, #0
 *   @0x28b8d0 beq 0x28c3b4 <spSkeletonJson_readSkeletonData+0xb68>
 *   @0x28b8d4 bl 0x28addc <spSkeletonData_create>
 *   @0x28b8d8 ldr r1, [pc, #0xf08]
 *   @0x28b8dc add r1, pc, r1
 *   @0x28b8e0 mov r9, r0
 *   @0x28b8e4 ldr r0, [sp, #0x24]
 *   @0x28b8e8 bl 0x2873c4 <Json_getItem>
 *   @0x28b8ec subs r4, r0, #0
 *   @0x28b8f0 beq 0x28b9cc <spSkeletonJson_readSkeletonData+0x180>
 *   @0x28b8f4 ldr r3, [pc, #0xef0]
 *   @0x28b8f8 mov r2, #0
 *   @0x28b8fc ldr r5, [pc, #0xeec]
 *   @0x28b900 add r3, pc, r3
 *   @0x28b904 ldr r6, [pc, #0xee8]
 *   @0x28b908 add r5, pc, r5
 *   @0x28b90c mov r1, r3
 *   @0x28b910 mov r10, r3
 *   @0x28b914 bl 0x287428 <Json_getString>
 *   @0x28b918 add r6, pc, r6
 *   @0x28b91c bl 0xb6538 <strlen@plt>
 *   @0x28b920 mov r1, r5
 *   @0x28b924 movw r2, #0x25f
 *   @0x28b928 add r0, r0, #1
 *   @0x28b92c bl 0x285c10 <_malloc>
 *   @0x28b930 mov r2, #0
 *   @0x28b934 mov r1, r10
 *   @0x28b938 mov r7, r0
 *   @0x28b93c str r0, [r9, #0x4]
 *   @0x28b940 mov r0, r4
 *   @0x28b944 bl 0x287428 <Json_getString>
 *   @0x28b948 mov r1, r0
 *   @0x28b94c mov r0, r7
 *   @0x28b950 bl 0xb65a4 <strcpy@plt>
 *   @0x28b954 mov r1, r6
 *   @0x28b958 mov r2, #0
 *   @0x28b95c mov r0, r4
 *   @0x28b960 bl 0x287428 <Json_getString>
 *   @0x28b964 bl 0xb6538 <strlen@plt>
 *   @0x28b968 mov r1, r5
 *   @0x28b96c mov r2, #608
 *   @0x28b970 add r0, r0, #1
 *   @0x28b974 bl 0x285c10 <_malloc>
 *   @0x28b978 mov r2, #0
 *   @0x28b97c mov r1, r6
 *   @0x28b980 mov r5, r0
 *   @0x28b984 str r0, [r9]
 *   @0x28b988 mov r0, r4
 *   @0x28b98c bl 0x287428 <Json_getString>
 *   @0x28b990 mov r1, r0
 *   @0x28b994 mov r0, r5
 *   @0x28b998 bl 0xb65a4 <strcpy@plt>
 *   @0x28b99c ldr r1, [pc, #0xe54]
 *   @0x28b9a0 mov r2, #0
 *   @0x28b9a4 mov r0, r4
 *   @0x28b9a8 add r1, pc, r1
 *   @0x28b9ac bl 0x287444 <Json_getFloat>
 *   @0x28b9b0 ldr r1, [pc, #0xe44]
 *   @0x28b9b4 mov r2, #0
 *   @0x28b9b8 add r1, pc, r1
 *   @0x28b9bc str r0, [r9, #0x8]
 *   @0x28b9c0 mov r0, r4
 *   @0x28b9c4 bl 0x287444 <Json_getFloat>
 *   @0x28b9c8 str r0, [r9, #0xc]
 *   @0x28b9cc ldr r1, [pc, #0xe2c]
 *   @0x28b9d0 ldr r0, [sp, #0x24]
 *   @0x28b9d4 add r1, pc, r1
 *   @0x28b9d8 bl 0x2873c4 <Json_getItem>
 *   @0x28b9dc ldr r1, [pc, #0xe20]
 *   @0x28b9e0 movw r2, #0x267
 *   @0x28b9e4 add r1, pc, r1
 *   @0x28b9e8 mov r4, r0
 *   @0x28b9ec ldr r0, [r0, #0xc]
 *   @0x28b9f0 lsl r0, r0, #2
 *   @0x28b9f4 bl 0x285c10 <_malloc>
 *   @0x28b9f8 ldr r4, [r4, #0x4]
 *   @0x28b9fc cmp r4, #0
 *   @0x28ba00 str r0, [r9, #0x14]
 *   @0x28ba04 beq 0x28bbcc <spSkeletonJson_readSkeletonData+0x380>
 *   @0x28ba08 ldr r3, [pc, #0xdf8]
 *   @0x28ba0c mov r6, #0
 *   @0x28ba10 ldr r7, [pc, #0xdf4]
 *   @0x28ba14 add r3, pc, r3
 *   @0x28ba18 str r3, [sp, #0x18]
 *   @0x28ba1c ldr r3, [pc, #0xdec]
 *   @0x28ba20 add r7, pc, r7
 *   @0x28ba24 ldr r11, [pc, #0xde8]
 *   @0x28ba28 add r3, pc, r3
 *   @0x28ba2c str r3, [sp, #0x1c]
 *   @0x28ba30 ldr r3, [pc, #0xde0]
 *   @0x28ba34 add r11, pc, r11
 *   @0x28ba38 add r3, pc, r3
 *   @0x28ba3c str r3, [sp, #0x20]
 *   @0x28ba40 b 0x28bba4 <spSkeletonJson_readSkeletonData+0x358>
 *   @0x28ba44 bl 0x28afbc <spSkeletonData_findBone>
 *   @0x28ba48 subs r5, r0, #0
 *   @0x28ba4c beq 0x28bf28 <spSkeletonJson_readSkeletonData+0x6dc>
 *   @0x28ba50 mov r0, r4
 *   @0x28ba54 mov r1, r11
 *   @0x28ba58 mov r2, #0
 *   @0x28ba5c ldr r10, [r9, #0x10]
 *   @0x28ba60 bl 0x287428 <Json_getString>
 *   @0x28ba64 mov r2, r5
 *   @0x28ba68 mov r1, r0
 *   @0x28ba6c mov r0, r10
 *   @0x28ba70 bl 0x285a44 <spBoneData_create>
 *   @0x28ba74 ldr r1, [sp, #0x18]
 *   @0x28ba78 mov r2, #0
 *   @0x28ba7c mov r5, r0
 *   @0x28ba80 mov r0, r4
 *   @0x28ba84 bl 0x287444 <Json_getFloat>
 *   @0x28ba88 vldr s15, [r8]
 *   @0x28ba8c ldr r1, [sp, #0x1c]
 *   @0x28ba90 mov r2, #0
 *   @0x28ba94 vmov s14, r0
 *   @0x28ba98 mov r0, r4
 *   @0x28ba9c vmul.f32 s15, s14, s15
 *   @0x28baa0 vstr s15, [r5, #12]
 *   @0x28baa4 bl 0x287444 <Json_getFloat>
 *   @0x28baa8 vldr s15, [r8]
 *   @0x28baac ldr r1, [sp, #0x20]
 *   @0x28bab0 mov r2, #0
 *   @0x28bab4 vmov s14, r0
 *   @0x28bab8 mov r0, r4
 *   @0x28babc vmul.f32 s15, s14, s15
 *   @0x28bac0 vstr s15, [r5, #16]
 *   @0x28bac4 bl 0x287444 <Json_getFloat>
 *   @0x28bac8 vldr s15, [r8]
 *   @0x28bacc ldr r1, [pc, #0xd48]
 *   @0x28bad0 mov r2, #0
 *   @0x28bad4 add r1, pc, r1
 *   @0x28bad8 vmov s14, r0
 *   @0x28badc mov r0, r4
 *   @0x28bae0 vmul.f32 s15, s14, s15
 *   @0x28bae4 vstr s15, [r5, #20]
 *   @0x28bae8 bl 0x287444 <Json_getFloat>
 *   @0x28baec ldr r1, [pc, #0xd2c]
 *   @0x28baf0 mov r2, #1065353216
 *   @0x28baf4 add r1, pc, r1
 *   @0x28baf8 str r0, [r5, #0x18]
 *   @0x28bafc mov r0, r4
 *   @0x28bb00 bl 0x287444 <Json_getFloat>
 *   @0x28bb04 ldr r1, [pc, #0xd18]
 *   @0x28bb08 mov r2, #1065353216
 *   @0x28bb0c add r1, pc, r1
 *   @0x28bb10 str r0, [r5, #0x1c]
 *   @0x28bb14 mov r0, r4
 *   @0x28bb18 bl 0x287444 <Json_getFloat>
 *   @0x28bb1c ldr r1, [pc, #0xd04]
 *   @0x28bb20 mov r2, #0
 *   @0x28bb24 add r1, pc, r1
 *   @0x28bb28 str r0, [r5, #0x20]
 *   @0x28bb2c mov r0, r4
 *   @0x28bb30 bl 0x287444 <Json_getFloat>
 *   @0x28bb34 ldr r1, [pc, #0xcf0]
 *   @0x28bb38 mov r2, #0
 *   @0x28bb3c add r1, pc, r1
 *   @0x28bb40 str r0, [r5, #0x24]
 *   @0x28bb44 mov r0, r4
 *   @0x28bb48 bl 0x287444 <Json_getFloat>
 *   @0x28bb4c ldr r1, [pc, #0xcdc]
 *   @0x28bb50 mov r2, #1
 *   @0x28bb54 add r1, pc, r1
 *   @0x28bb58 str r0, [r5, #0x28]
 *   @0x28bb5c mov r0, r4
 *   @0x28bb60 bl 0x287460 <Json_getInt>
 *   @0x28bb64 ldr r1, [pc, #0xcc8]
 *   @0x28bb68 mov r2, #1
 *   @0x28bb6c add r1, pc, r1
 *   @0x28bb70 str r0, [r5, #0x2c]
 *   @0x28bb74 mov r0, r4
 *   @0x28bb78 bl 0x287460 <Json_getInt>
 *   @0x28bb7c ldr r1, [r9, #0x14]
 *   @0x28bb80 ldr r2, [r9, #0x10]
 *   @0x28bb84 add r2, r2, #1
 *   @0x28bb88 str r0, [r5, #0x30]
 *   @0x28bb8c str r5, [r1, r6]
 *   @0x28bb90 add r6, r6, #4
 *   @0x28bb94 ldr r4, [r4]
 *   @0x28bb98 str r2, [r9, #0x10]
 *   @0x28bb9c cmp r4, #0
 *   @0x28bba0 beq 0x28bbcc <spSkeletonJson_readSkeletonData+0x380>
 *   @0x28bba4 mov r1, r7
 *   @0x28bba8 mov r0, r4
 *   @0x28bbac mov r2, #0
 *   @0x28bbb0 bl 0x287428 <Json_getString>
 *   @0x28bbb4 subs r10, r0, #0
 *   @0x28bbb8 mov r0, r9
 *   @0x28bbbc mov r1, r10
 *   @0x28bbc0 bne 0x28ba44 <spSkeletonJson_readSkeletonData+0x1f8>
 *   @0x28bbc4 mov r5, r10
 *   @0x28bbc8 b 0x28ba50 <spSkeletonJson_readSkeletonData+0x204>
 *   @0x28bbcc ldr r1, [pc, #0xc64]
 *   @0x28bbd0 ldr r0, [sp, #0x24]
 *   @0x28bbd4 add r1, pc, r1
 *   @0x28bbd8 bl 0x2873c4 <Json_getItem>
 *   @0x28bbdc subs r4, r0, #0
 *   @0x28bbe0 beq 0x28bddc <spSkeletonJson_readSkeletonData+0x590>
 *   @0x28bbe4 ldr r0, [r4, #0xc]
 *   @0x28bbe8 movw r2, #0x28b
 *   @0x28bbec ldr r1, [pc, #0xc48]
 *   @0x28bbf0 str r0, [r9, #0x18]
 *   @0x28bbf4 add r1, pc, r1
 *   @0x28bbf8 lsl r0, r0, #2
 *   @0x28bbfc bl 0x285c10 <_malloc>
 *   @0x28bc00 ldr r4, [r4, #0x4]
 *   @0x28bc04 cmp r4, #0
 *   @0x28bc08 str r0, [r9, #0x1c]
 *   @0x28bc0c beq 0x28bddc <spSkeletonJson_readSkeletonData+0x590>
 *   @0x28bc10 ldr r3, [pc, #0xc28]
 *   @0x28bc14 mov r6, #0
 *   @0x28bc18 ldr r10, [pc, #0xc24]
 *   @0x28bc1c add r3, pc, r3
 *   @0x28bc20 str r3, [sp, #0x18]
 *   @0x28bc24 ldr r3, [pc, #0xc1c]
 *   @0x28bc28 add r10, pc, r10
 *   @0x28bc2c ldr r11, [pc, #0xc18]
 *   @0x28bc30 add r3, pc, r3
 *   @0x28bc34 str r3, [sp, #0x1c]
 *   @0x28bc38 ldr r3, [pc, #0xc10]
 *   @0x28bc3c add r11, pc, r11
 *   @0x28bc40 ldr r0, [pc, #0xc0c]
 *   @0x28bc44 add r3, pc, r3
 *   @0x28bc48 str r8, [sp, #0x28]
 *   @0x28bc4c add r0, pc, r0
 *   @0x28bc50 str r0, [sp, #0x20]
 *   @0x28bc54 mov r8, r3
 *   @0x28bc58 b 0x28bd7c <spSkeletonJson_readSkeletonData+0x530>
 *   @0x28bc5c mov r1, r11
 *   @0x28bc60 mov r2, #0
 *   @0x28bc64 mov r0, r4
 *   @0x28bc68 bl 0x287428 <Json_getString>
 *   @0x28bc6c mov r2, r7
 *   @0x28bc70 mov r1, r0
 *   @0x28bc74 mov r0, r6
 *   @0x28bc78 bl 0x28ef2c <spSlotData_create>
 *   @0x28bc7c ldr r1, [sp, #0x18]
 *   @0x28bc80 mov r2, #0
 *   @0x28bc84 mov r5, r0
 *   @0x28bc88 mov r0, r4
 *   @0x28bc8c bl 0x287428 <Json_getString>
 *   @0x28bc90 subs r7, r0, #0
 *   @0x28bc94 beq 0x28bcd4 <spSkeletonJson_readSkeletonData+0x488>
 *   @0x28bc98 mov r1, #0
 *   @0x28bc9c bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28bca0 mov r0, r7
 *   @0x28bca4 mov r1, #1
 *   @0x28bca8 vstr s0, [r5, #16]
 *   @0x28bcac bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28bcb0 mov r0, r7
 *   @0x28bcb4 mov r1, #2
 *   @0x28bcb8 vstr s0, [r5, #20]
 *   @0x28bcbc bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28bcc0 mov r0, r7
 *   @0x28bcc4 mov r1, #3
 *   @0x28bcc8 vstr s0, [r5, #24]
 *   @0x28bccc bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28bcd0 vstr s0, [r5, #28]
 *   @0x28bcd4 mov r0, r4
 *   @0x28bcd8 ldr r1, [sp, #0x1c]
 *   @0x28bcdc bl 0x2873c4 <Json_getItem>
 *   @0x28bce0 cmp r0, #0
 *   @0x28bce4 beq 0x28bcf4 <spSkeletonJson_readSkeletonData+0x4a8>
 *   @0x28bce8 ldr r1, [r0, #0x10]
 *   @0x28bcec mov r0, r5
 *   @0x28bcf0 bl 0x28efcc <spSlotData_setAttachmentName>
 *   @0x28bcf4 mov r0, r4
 *   @0x28bcf8 mov r1, r8
 *   @0x28bcfc bl 0x2873c4 <Json_getItem>
 *   @0x28bd00 cmp r0, #0
 *   @0x28bd04 beq 0x28bd64 <spSkeletonJson_readSkeletonData+0x518>
 *   @0x28bd08 ldr r7, [r0, #0x10]
 *   @0x28bd0c ldr r1, [sp, #0x20]
 *   @0x28bd10 mov r0, r7
 *   @0x28bd14 bl 0xb6574 <strcmp@plt>
 *   @0x28bd18 cmp r0, #0
 *   @0x28bd1c moveq r3, #1
 *   @0x28bd20 streq r3, [r5, #0x20]
 *   @0x28bd24 beq 0x28bd64 <spSkeletonJson_readSkeletonData+0x518>
 *   @0x28bd28 ldr r1, [pc, #0xb28]
 *   @0x28bd2c mov r0, r7
 *   @0x28bd30 add r1, pc, r1
 *   @0x28bd34 bl 0xb6574 <strcmp@plt>
 *   @0x28bd38 cmp r0, #0
 *   @0x28bd3c moveq r3, #2
 *   @0x28bd40 streq r3, [r5, #0x20]
 *   @0x28bd44 beq 0x28bd64 <spSkeletonJson_readSkeletonData+0x518>
 *   @0x28bd48 ldr r1, [pc, #0xb0c]
 *   @0x28bd4c mov r0, r7
 *   @0x28bd50 add r1, pc, r1
 *   @0x28bd54 bl 0xb6574 <strcmp@plt>
 *   @0x28bd58 cmp r0, #0
 *   @0x28bd5c moveq r3, #3
 *   @0x28bd60 streq r3, [r5, #0x20]
 *   @0x28bd64 ldr r3, [r9, #0x1c]
 *   @0x28bd68 str r5, [r3, r6, lsl #2]
 *   @0x28bd6c add r6, r6, #1
 *   @0x28bd70 ldr r4, [r4]
 *   @0x28bd74 cmp r4, #0
 *   @0x28bd78 beq 0x28bdd8 <spSkeletonJson_readSkeletonData+0x58c>
 *   @0x28bd7c mov r1, r10
 *   @0x28bd80 mov r2, #0
 *   @0x28bd84 mov r0, r4
 *   @0x28bd88 bl 0x287428 <Json_getString>
 *   @0x28bd8c mov r5, r0
 *   @0x28bd90 mov r0, r9
 *   @0x28bd94 mov r1, r5
 *   @0x28bd98 bl 0x28afbc <spSkeletonData_findBone>
 *   @0x28bd9c subs r7, r0, #0
 *   @0x28bda0 bne 0x28bc5c <spSkeletonJson_readSkeletonData+0x410>
 *   @0x28bda4 ldr r8, [sp, #0x28]
 *   @0x28bda8 mov r0, r9
 *   @0x28bdac bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28bdb0 ldr r2, [pc, #0xaa8]
 *   @0x28bdb4 ldr r1, [sp, #0x24]
 *   @0x28bdb8 mov r3, r5
 *   @0x28bdbc mov r0, r8
 *   @0x28bdc0 add r2, pc, r2
 *   @0x28bdc4 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28bdc8 mov r0, r7
 *   @0x28bdcc add sp, sp, #124
 *   @0x28bdd0 vpop {d8}
 *   @0x28bdd4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x28bdd8 ldr r8, [sp, #0x28]
 *   @0x28bddc ldr r1, [pc, #0xa80]
 *   @0x28bde0 ldr r0, [sp, #0x24]
 *   @0x28bde4 add r1, pc, r1
 *   @0x28bde8 bl 0x2873c4 <Json_getItem>
 *   @0x28bdec subs r4, r0, #0
 *   @0x28bdf0 beq 0x28bff8 <spSkeletonJson_readSkeletonData+0x7ac>
 *   @0x28bdf4 ldr r5, [pc, #0xa6c]
 *   @0x28bdf8 movw r2, #0x2b9
 *   @0x28bdfc ldr r0, [r4, #0xc]
 *   @0x28be00 add r5, pc, r5
 *   @0x28be04 str r0, [r9, #0x3c]
 *   @0x28be08 mov r1, r5
 *   @0x28be0c lsl r0, r0, #2
 *   @0x28be10 bl 0x285c10 <_malloc>
 *   @0x28be14 ldr r6, [r4, #0x4]
 *   @0x28be18 cmp r6, #0
 *   @0x28be1c str r0, [r9, #0x40]
 *   @0x28be20 beq 0x28bff8 <spSkeletonJson_readSkeletonData+0x7ac>
 *   @0x28be24 ldr r3, [pc, #0xa40]
 *   @0x28be28 mov r7, #0
 *   @0x28be2c str r5, [sp, #0x20]
 *   @0x28be30 add r3, pc, r3
 *   @0x28be34 str r3, [sp, #0x18]
 *   @0x28be38 ldr r3, [pc, #0xa30]
 *   @0x28be3c add r3, pc, r3
 *   @0x28be40 str r3, [sp, #0x1c]
 *   @0x28be44 ldr r3, [pc, #0xa28]
 *   @0x28be48 add r3, pc, r3
 *   @0x28be4c str r3, [sp, #0x28]
 *   @0x28be50 ldr r3, [pc, #0xa20]
 *   @0x28be54 add r3, pc, r3
 *   @0x28be58 str r3, [sp, #0x2c]
 *   @0x28be5c ldr r3, [pc, #0xa18]
 *   @0x28be60 add r3, pc, r3
 *   @0x28be64 str r3, [sp, #0x30]
 *   @0x28be68 mov r2, #0
 *   @0x28be6c ldr r1, [sp, #0x18]
 *   @0x28be70 mov r0, r6
 *   @0x28be74 bl 0x287428 <Json_getString>
 *   @0x28be78 bl 0x2866f0 <spIkConstraintData_create>
 *   @0x28be7c ldr r1, [sp, #0x1c]
 *   @0x28be80 mov r5, r0
 *   @0x28be84 mov r0, r6
 *   @0x28be88 bl 0x2873c4 <Json_getItem>
 *   @0x28be8c ldr r1, [sp, #0x20]
 *   @0x28be90 movw r2, #0x2c1
 *   @0x28be94 mov r4, r0
 *   @0x28be98 ldr r0, [r0, #0xc]
 *   @0x28be9c str r0, [r5, #0x4]
 *   @0x28bea0 lsl r0, r0, #2
 *   @0x28bea4 bl 0x285c10 <_malloc>
 *   @0x28bea8 ldr r4, [r4, #0x4]
 *   @0x28beac cmp r4, #0
 *   @0x28beb0 movne r10, #0
 *   @0x28beb4 str r0, [r5, #0x8]
 *   @0x28beb8 movne r11, r0
 *   @0x28bebc bne 0x28bed0 <spSkeletonJson_readSkeletonData+0x684>
 *   @0x28bec0 b 0x28bf84 <spSkeletonJson_readSkeletonData+0x738>
 *   @0x28bec4 ldr r4, [r4]
 *   @0x28bec8 cmp r4, #0
 *   @0x28becc beq 0x28bf84 <spSkeletonJson_readSkeletonData+0x738>
 *   @0x28bed0 ldr r1, [r4, #0x10]
 *   @0x28bed4 mov r0, r9
 *   @0x28bed8 bl 0x28afbc <spSkeletonData_findBone>
 *   @0x28bedc str r0, [r11, r10]
 *   @0x28bee0 ldr r11, [r5, #0x8]
 *   @0x28bee4 ldr r1, [r11, r10]
 *   @0x28bee8 add r10, r10, #4
 *   @0x28beec cmp r1, #0
 *   @0x28bef0 bne 0x28bec4 <spSkeletonJson_readSkeletonData+0x678>
 *   @0x28bef4 mov r0, r9
 *   @0x28bef8 mov r10, r1
 *   @0x28befc bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28bf00 ldr r2, [pc, #0x978]
 *   @0x28bf04 mov r0, r8
 *   @0x28bf08 ldr r1, [sp, #0x24]
 *   @0x28bf0c ldr r3, [r4, #0x10]
 *   @0x28bf10 add r2, pc, r2
 *   @0x28bf14 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28bf18 mov r0, r10
 *   @0x28bf1c add sp, sp, #124
 *   @0x28bf20 vpop {d8}
 *   @0x28bf24 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x28bf28 mov r0, r9
 *   @0x28bf2c bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28bf30 ldr r2, [pc, #0x94c]
 *   @0x28bf34 mov r0, r8
 *   @0x28bf38 ldr r1, [sp, #0x24]
 *   @0x28bf3c mov r3, r10
 *   @0x28bf40 add r2, pc, r2
 *   @0x28bf44 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28bf48 mov r0, r5
 *   @0x28bf4c add sp, sp, #124
 *   @0x28bf50 vpop {d8}
 *   @0x28bf54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x28bf58 ldr r1, [pc, #0x928]
 *   @0x28bf5c mov r0, #1
 *   @0x28bf60 add r1, pc, r1
 *   @0x28bf64 bl 0xb679c <setlocale@plt>
 *   @0x28bf68 mov r0, r5
 *   @0x28bf6c bl 0x287320 <Json_create>
 *   @0x28bf70 mov r1, r4
 *   @0x28bf74 str r0, [sp, #0x24]
 *   @0x28bf78 mov r0, #1
 *   @0x28bf7c bl 0xb679c <setlocale@plt>
 *   @0x28bf80 b 0x28b8c8 <spSkeletonJson_readSkeletonData+0x7c>
 *   @0x28bf84 ldr r1, [sp, #0x28]
 *   @0x28bf88 mov r2, #0
 *   @0x28bf8c mov r0, r6
 *   @0x28bf90 bl 0x287428 <Json_getString>
 *   @0x28bf94 mov r1, r0
 *   @0x28bf98 mov r0, r9
 *   @0x28bf9c bl 0x28afbc <spSkeletonData_findBone>
 *   @0x28bfa0 cmp r0, #0
 *   @0x28bfa4 str r0, [r5, #0xc]
 *   @0x28bfa8 beq 0x28cf3c <spSkeletonJson_readSkeletonData+0x16f0>
 *   @0x28bfac mov r0, r6
 *   @0x28bfb0 ldr r1, [sp, #0x2c]
 *   @0x28bfb4 mov r2, #1
 *   @0x28bfb8 bl 0x287460 <Json_getInt>
 *   @0x28bfbc ldr r1, [sp, #0x30]
 *   @0x28bfc0 mov r2, #1065353216
 *   @0x28bfc4 cmp r0, #0
 *   @0x28bfc8 mov r0, r6
 *   @0x28bfcc mvneq r3, #0
 *   @0x28bfd0 movne r3, #1
 *   @0x28bfd4 str r3, [r5, #0x10]
 *   @0x28bfd8 bl 0x287444 <Json_getFloat>
 *   @0x28bfdc ldr r3, [r9, #0x40]
 *   @0x28bfe0 str r0, [r5, #0x14]
 *   @0x28bfe4 str r5, [r3, r7]
 *   @0x28bfe8 add r7, r7, #4
 *   @0x28bfec ldr r6, [r6]
 *   @0x28bff0 cmp r6, #0
 *   @0x28bff4 bne 0x28be68 <spSkeletonJson_readSkeletonData+0x61c>
 *   @0x28bff8 ldr r1, [pc, #0x88c]
 *   @0x28bffc ldr r0, [sp, #0x24]
 *   @0x28c000 add r1, pc, r1
 *   @0x28c004 bl 0x2873c4 <Json_getItem>
 *   @0x28c008 subs r4, r0, #0
 *   @0x28c00c beq 0x28c274 <spSkeletonJson_readSkeletonData+0xa28>
 *   @0x28c010 ldr r5, [pc, #0x878]
 *   @0x28c014 movw r2, #0x2df
 *   @0x28c018 ldr r0, [r4, #0xc]
 *   @0x28c01c add r5, pc, r5
 *   @0x28c020 str r0, [r9, #0x44]
 *   @0x28c024 mov r1, r5
 *   @0x28c028 lsl r0, r0, #2
 *   @0x28c02c bl 0x285c10 <_malloc>
 *   @0x28c030 ldr r6, [r4, #0x4]
 *   @0x28c034 cmp r6, #0
 *   @0x28c038 str r0, [r9, #0x48]
 *   @0x28c03c beq 0x28c274 <spSkeletonJson_readSkeletonData+0xa28>
 *   @0x28c040 ldr r3, [pc, #0x84c]
 *   @0x28c044 mov r7, #0
 *   @0x28c048 str r5, [sp, #0x20]
 *   @0x28c04c add r3, pc, r3
 *   @0x28c050 str r3, [sp, #0x18]
 *   @0x28c054 ldr r3, [pc, #0x83c]
 *   @0x28c058 add r3, pc, r3
 *   @0x28c05c str r3, [sp, #0x1c]
 *   @0x28c060 ldr r3, [pc, #0x834]
 *   @0x28c064 add r3, pc, r3
 *   @0x28c068 str r3, [sp, #0x28]
 *   @0x28c06c ldr r3, [pc, #0x82c]
 *   @0x28c070 add r3, pc, r3
 *   @0x28c074 str r3, [sp, #0x2c]
 *   @0x28c078 mov r2, #0
 *   @0x28c07c ldr r1, [sp, #0x18]
 *   @0x28c080 mov r0, r6
 *   @0x28c084 bl 0x287428 <Json_getString>
 *   @0x28c088 bl 0x28f5b0 <spTransformConstraintData_create>
 *   @0x28c08c ldr r1, [sp, #0x1c]
 *   @0x28c090 mov r5, r0
 *   @0x28c094 mov r0, r6
 *   @0x28c098 bl 0x2873c4 <Json_getItem>
 *   @0x28c09c ldr r1, [sp, #0x20]
 *   @0x28c0a0 movw r2, #0x2e7
 *   @0x28c0a4 mov r4, r0
 *   @0x28c0a8 ldr r0, [r0, #0xc]
 *   @0x28c0ac str r0, [r5, #0x4]
 *   @0x28c0b0 lsl r0, r0, #2
 *   @0x28c0b4 bl 0x285c10 <_malloc>
 *   @0x28c0b8 str r0, [r5, #0x8]
 *   @0x28c0bc ldr r4, [r4, #0x4]
 *   @0x28c0c0 cmp r4, #0
 *   @0x28c0c4 movne r11, r0
 *   @0x28c0c8 movne r10, #0
 *   @0x28c0cc bne 0x28c0e0 <spSkeletonJson_readSkeletonData+0x894>
 *   @0x28c0d0 b 0x28c130 <spSkeletonJson_readSkeletonData+0x8e4>
 *   @0x28c0d4 ldr r4, [r4]
 *   @0x28c0d8 cmp r4, #0
 *   @0x28c0dc beq 0x28c130 <spSkeletonJson_readSkeletonData+0x8e4>
 *   @0x28c0e0 mov r0, r9
 *   @0x28c0e4 ldr r1, [r4, #0x10]
 *   @0x28c0e8 bl 0x28afbc <spSkeletonData_findBone>
 *   @0x28c0ec str r0, [r11, r10]
 *   @0x28c0f0 ldr r11, [r5, #0x8]
 *   @0x28c0f4 ldr r0, [r11, r10]
 *   @0x28c0f8 add r10, r10, #4
 *   @0x28c0fc cmp r0, #0
 *   @0x28c100 bne 0x28c0d4 <spSkeletonJson_readSkeletonData+0x888>
 *   @0x28c104 mov r10, r0
 *   @0x28c108 mov r0, r9
 *   @0x28c10c bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28c110 ldr r2, [pc, #0x78c]
 *   @0x28c114 mov r0, r8
 *   @0x28c118 ldr r1, [sp, #0x24]
 *   @0x28c11c ldr r3, [r4, #0x10]
 *   @0x28c120 add r2, pc, r2
 *   @0x28c124 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28c128 mov r0, r10
 *   @0x28c12c b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580>
 *   @0x28c130 ldr r1, [sp, #0x28]
 *   @0x28c134 mov r2, #0
 *   @0x28c138 mov r0, r6
 *   @0x28c13c bl 0x287428 <Json_getString>
 *   @0x28c140 mov r1, r0
 *   @0x28c144 mov r0, r9
 *   @0x28c148 bl 0x28afbc <spSkeletonData_findBone>
 *   @0x28c14c cmp r0, #0
 *   @0x28c150 str r0, [r5, #0xc]
 *   @0x28c154 beq 0x28d144 <spSkeletonJson_readSkeletonData+0x18f8>
 *   @0x28c158 mov r0, r6
 *   @0x28c15c ldr r1, [sp, #0x2c]
 *   @0x28c160 mov r2, #0
 *   @0x28c164 bl 0x287444 <Json_getFloat>
 *   @0x28c168 ldr r1, [pc, #0x738]
 *   @0x28c16c mov r2, #0
 *   @0x28c170 add r1, pc, r1
 *   @0x28c174 str r0, [r5, #0x20]
 *   @0x28c178 mov r0, r6
 *   @0x28c17c bl 0x287444 <Json_getFloat>
 *   @0x28c180 vldr s15, [r8]
 *   @0x28c184 ldr r1, [pc, #0x720]
 *   @0x28c188 mov r2, #0
 *   @0x28c18c add r1, pc, r1
 *   @0x28c190 vmov s14, r0
 *   @0x28c194 mov r0, r6
 *   @0x28c198 vmul.f32 s15, s14, s15
 *   @0x28c19c vstr s15, [r5, #36]
 *   @0x28c1a0 bl 0x287444 <Json_getFloat>
 *   @0x28c1a4 vldr s15, [r8]
 *   @0x28c1a8 ldr r1, [pc, #0x700]
 *   @0x28c1ac mov r2, #0
 *   @0x28c1b0 add r1, pc, r1
 *   @0x28c1b4 vmov s14, r0
 *   @0x28c1b8 mov r0, r6
 *   @0x28c1bc vmul.f32 s15, s14, s15
 *   @0x28c1c0 vstr s15, [r5, #40]
 *   @0x28c1c4 bl 0x287444 <Json_getFloat>
 *   @0x28c1c8 ldr r1, [pc, #0x6e4]
 *   @0x28c1cc mov r2, #0
 *   @0x28c1d0 add r1, pc, r1
 *   @0x28c1d4 str r0, [r5, #0x2c]
 *   @0x28c1d8 mov r0, r6
 *   @0x28c1dc bl 0x287444 <Json_getFloat>
 *   @0x28c1e0 ldr r1, [pc, #0x6d0]
 *   @0x28c1e4 mov r2, #0
 *   @0x28c1e8 add r1, pc, r1
 *   @0x28c1ec str r0, [r5, #0x30]
 *   @0x28c1f0 mov r0, r6
 *   @0x28c1f4 bl 0x287444 <Json_getFloat>
 *   @0x28c1f8 ldr r1, [pc, #0x6bc]
 *   @0x28c1fc mov r2, #1065353216
 *   @0x28c200 add r1, pc, r1
 *   @0x28c204 str r0, [r5, #0x34]
 *   @0x28c208 mov r0, r6
 *   @0x28c20c bl 0x287444 <Json_getFloat>
 *   @0x28c210 ldr r1, [pc, #0x6a8]
 *   @0x28c214 mov r2, #1065353216
 *   @0x28c218 add r1, pc, r1
 *   @0x28c21c str r0, [r5, #0x10]
 *   @0x28c220 mov r0, r6
 *   @0x28c224 bl 0x287444 <Json_getFloat>
 *   @0x28c228 ldr r1, [pc, #0x694]
 *   @0x28c22c mov r2, #1065353216
 *   @0x28c230 add r1, pc, r1
 *   @0x28c234 str r0, [r5, #0x14]
 *   @0x28c238 mov r0, r6
 *   @0x28c23c bl 0x287444 <Json_getFloat>
 *   @0x28c240 ldr r1, [pc, #0x680]
 *   @0x28c244 mov r2, #1065353216
 *   @0x28c248 add r1, pc, r1
 *   @0x28c24c str r0, [r5, #0x18]
 *   @0x28c250 mov r0, r6
 *   @0x28c254 bl 0x287444 <Json_getFloat>
 *   @0x28c258 ldr r3, [r9, #0x48]
 *   @0x28c25c str r0, [r5, #0x1c]
 *   @0x28c260 str r5, [r3, r7]
 *   @0x28c264 add r7, r7, #4
 *   @0x28c268 ldr r6, [r6]
 *   @0x28c26c cmp r6, #0
 *   @0x28c270 bne 0x28c078 <spSkeletonJson_readSkeletonData+0x82c>
 *   @0x28c274 ldr r1, [pc, #0x650]
 *   @0x28c278 ldr r0, [sp, #0x24]
 *   @0x28c27c add r1, pc, r1
 *   @0x28c280 bl 0x2873c4 <Json_getItem>
 *   @0x28c284 subs r5, r0, #0
 *   @0x28c288 beq 0x28c5ec <spSkeletonJson_readSkeletonData+0xda0>
 *   @0x28c28c ldr r4, [pc, #0x63c]
 *   @0x28c290 movw r2, #0x30e
 *   @0x28c294 ldr r0, [r5, #0xc]
 *   @0x28c298 add r4, pc, r4
 *   @0x28c29c str r0, [r9, #0x4c]
 *   @0x28c2a0 mov r1, r4
 *   @0x28c2a4 lsl r0, r0, #2
 *   @0x28c2a8 bl 0x285c10 <_malloc>
 *   @0x28c2ac ldr r6, [r5, #0x4]
 *   @0x28c2b0 cmp r6, #0
 *   @0x28c2b4 str r0, [r9, #0x50]
 *   @0x28c2b8 beq 0x28c5ec <spSkeletonJson_readSkeletonData+0xda0>
 *   @0x28c2bc ldr r3, [pc, #0x610]
 *   @0x28c2c0 mov r7, #0
 *   @0x28c2c4 str r4, [sp, #0x20]
 *   @0x28c2c8 add r3, pc, r3
 *   @0x28c2cc str r3, [sp, #0x18]
 *   @0x28c2d0 ldr r3, [pc, #0x600]
 *   @0x28c2d4 add r3, pc, r3
 *   @0x28c2d8 str r3, [sp, #0x1c]
 *   @0x28c2dc ldr r3, [pc, #0x5f8]
 *   @0x28c2e0 add r3, pc, r3
 *   @0x28c2e4 str r3, [sp, #0x28]
 *   @0x28c2e8 ldr r3, [pc, #0x5f0]
 *   @0x28c2ec add r3, pc, r3
 *   @0x28c2f0 str r3, [sp, #0x2c]
 *   @0x28c2f4 mov r2, #0
 *   @0x28c2f8 ldr r1, [sp, #0x18]
 *   @0x28c2fc mov r0, r6
 *   @0x28c300 bl 0x287428 <Json_getString>
 *   @0x28c304 bl 0x288edc <spPathConstraintData_create>
 *   @0x28c308 ldr r1, [sp, #0x1c]
 *   @0x28c30c mov r5, r0
 *   @0x28c310 mov r0, r6
 *   @0x28c314 bl 0x2873c4 <Json_getItem>
 *   @0x28c318 ldr r1, [sp, #0x20]
 *   @0x28c31c movw r2, #0x317
 *   @0x28c320 mov r4, r0
 *   @0x28c324 ldr r0, [r0, #0xc]
 *   @0x28c328 str r0, [r5, #0x4]
 *   @0x28c32c lsl r0, r0, #2
 *   @0x28c330 bl 0x285c10 <_malloc>
 *   @0x28c334 str r0, [r5, #0x8]
 *   @0x28c338 ldr r10, [r4, #0x4]
 *   @0x28c33c cmp r10, #0
 *   @0x28c340 movne r11, r0
 *   @0x28c344 movne r4, #0
 *   @0x28c348 bne 0x28c35c <spSkeletonJson_readSkeletonData+0xb10>
 *   @0x28c34c b 0x28c3d8 <spSkeletonJson_readSkeletonData+0xb8c>
 *   @0x28c350 ldr r10, [r10]
 *   @0x28c354 cmp r10, #0
 *   @0x28c358 beq 0x28c3d8 <spSkeletonJson_readSkeletonData+0xb8c>
 *   @0x28c35c mov r0, r9
 *   @0x28c360 ldr r1, [r10, #0x10]
 *   @0x28c364 bl 0x28afbc <spSkeletonData_findBone>
 *   @0x28c368 str r0, [r11, r4]
 *   @0x28c36c ldr r3, [r5, #0x8]
 *   @0x28c370 ldr r12, [r3, r4]
 *   @0x28c374 mov r11, r3
 *   @0x28c378 add r4, r4, #4
 *   @0x28c37c cmp r12, #0
 *   @0x28c380 bne 0x28c350 <spSkeletonJson_readSkeletonData+0xb04>
 *   @0x28c384 mov r0, r9
 *   @0x28c388 str r12, [sp, #0x14]
 *   @0x28c38c bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28c390 ldr r2, [pc, #0x54c]
 *   @0x28c394 mov r0, r8
 *   @0x28c398 ldr r1, [sp, #0x24]
 *   @0x28c39c ldr r3, [r10, #0x10]
 *   @0x28c3a0 add r2, pc, r2
 *   @0x28c3a4 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28c3a8 ldr r12, [sp, #0x14]
 *   @0x28c3ac mov r0, r12
 *   @0x28c3b0 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580>
 *   @0x28c3b4 bl 0x2872b8 <Json_getError>
 *   @0x28c3b8 ldr r2, [pc, #0x528]
 *   @0x28c3bc ldr r1, [sp, #0x24]
 *   @0x28c3c0 add r2, pc, r2
 *   @0x28c3c4 mov r3, r0
 *   @0x28c3c8 mov r0, r8
 *   @0x28c3cc bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28c3d0 ldr r0, [sp, #0x24]
 *   @0x28c3d4 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580>
 *   @0x28c3d8 ldr r1, [sp, #0x28]
 *   @0x28c3dc mov r2, #0
 *   @0x28c3e0 mov r0, r6
 *   @0x28c3e4 bl 0x287428 <Json_getString>
 *   @0x28c3e8 mov r1, r0
 *   @0x28c3ec mov r0, r9
 *   @0x28c3f0 bl 0x28b070 <spSkeletonData_findSlot>
 *   @0x28c3f4 cmp r0, #0
 *   @0x28c3f8 str r0, [r5, #0xc]
 *   @0x28c3fc beq 0x28d170 <spSkeletonJson_readSkeletonData+0x1924>
 *   @0x28c400 ldr r4, [pc, #0x4e4]
 *   @0x28c404 mov r0, r6
 *   @0x28c408 ldr r1, [sp, #0x2c]
 *   @0x28c40c add r4, pc, r4
 *   @0x28c410 mov r2, r4
 *   @0x28c414 bl 0x287428 <Json_getString>
 *   @0x28c418 ldr r1, [pc, #0x4d0]
 *   @0x28c41c add r1, pc, r1
 *   @0x28c420 mov r10, r0
 *   @0x28c424 bl 0xb6574 <strcmp@plt>
 *   @0x28c428 cmp r0, #0
 *   @0x28c42c streq r0, [r5, #0x10]
 *   @0x28c430 beq 0x28c44c <spSkeletonJson_readSkeletonData+0xc00>
 *   @0x28c434 mov r0, r10
 *   @0x28c438 mov r1, r4
 *   @0x28c43c bl 0xb6574 <strcmp@plt>
 *   @0x28c440 cmp r0, #0
 *   @0x28c444 moveq r3, #1
 *   @0x28c448 streq r3, [r5, #0x10]
 *   @0x28c44c ldr r10, [pc, #0x4a0]
 *   @0x28c450 mov r0, r6
 *   @0x28c454 ldr r1, [pc, #0x49c]
 *   @0x28c458 add r10, pc, r10
 *   @0x28c45c add r1, pc, r1
 *   @0x28c460 mov r2, r10
 *   @0x28c464 bl 0x287428 <Json_getString>
 *   @0x28c468 mov r1, r10
 *   @0x28c46c mov r4, r0
 *   @0x28c470 bl 0xb6574 <strcmp@plt>
 *   @0x28c474 cmp r0, #0
 *   @0x28c478 streq r0, [r5, #0x14]
 *   @0x28c47c beq 0x28c4bc <spSkeletonJson_readSkeletonData+0xc70>
 *   @0x28c480 ldr r1, [pc, #0x474]
 *   @0x28c484 mov r0, r4
 *   @0x28c488 add r1, pc, r1
 *   @0x28c48c bl 0xb6574 <strcmp@plt>
 *   @0x28c490 cmp r0, #0
 *   @0x28c494 moveq r3, #1
 *   @0x28c498 streq r3, [r5, #0x14]
 *   @0x28c49c beq 0x28c4bc <spSkeletonJson_readSkeletonData+0xc70>
 *   @0x28c4a0 ldr r1, [pc, #0x458]
 *   @0x28c4a4 mov r0, r4
 *   @0x28c4a8 add r1, pc, r1
 *   @0x28c4ac bl 0xb6574 <strcmp@plt>
 *   @0x28c4b0 cmp r0, #0
 *   @0x28c4b4 moveq r3, #2
 *   @0x28c4b8 streq r3, [r5, #0x14]
 *   @0x28c4bc ldr r10, [pc, #0x440]
 *   @0x28c4c0 mov r0, r6
 *   @0x28c4c4 ldr r1, [pc, #0x43c]
 *   @0x28c4c8 add r10, pc, r10
 *   @0x28c4cc add r1, pc, r1
 *   @0x28c4d0 mov r2, r10
 *   @0x28c4d4 bl 0x287428 <Json_getString>
 *   @0x28c4d8 mov r1, r10
 *   @0x28c4dc mov r4, r0
 *   @0x28c4e0 bl 0xb6574 <strcmp@plt>
 *   @0x28c4e4 cmp r0, #0
 *   @0x28c4e8 streq r0, [r5, #0x18]
 *   @0x28c4ec beq 0x28c52c <spSkeletonJson_readSkeletonData+0xce0>
 *   @0x28c4f0 ldr r1, [pc, #0x414]
 *   @0x28c4f4 mov r0, r4
 *   @0x28c4f8 add r1, pc, r1
 *   @0x28c4fc bl 0xb6574 <strcmp@plt>
 *   @0x28c500 cmp r0, #0
 *   @0x28c504 moveq r3, #1
 *   @0x28c508 streq r3, [r5, #0x18]
 *   @0x28c50c beq 0x28c52c <spSkeletonJson_readSkeletonData+0xce0>
 *   @0x28c510 ldr r1, [pc, #0x3f8]
 *   @0x28c514 mov r0, r4
 *   @0x28c518 add r1, pc, r1
 *   @0x28c51c bl 0xb6574 <strcmp@plt>
 *   @0x28c520 cmp r0, #0
 *   @0x28c524 moveq r3, #2
 *   @0x28c528 streq r3, [r5, #0x18]
 *   @0x28c52c ldr r1, [pc, #0x3e0]
 *   @0x28c530 mov r0, r6
 *   @0x28c534 mov r2, #0
 *   @0x28c538 add r1, pc, r1
 *   @0x28c53c bl 0x287444 <Json_getFloat>
 *   @0x28c540 ldr r1, [pc, #0x3d0]
 *   @0x28c544 mov r2, #0
 *   @0x28c548 add r1, pc, r1
 *   @0x28c54c str r0, [r5, #0x1c]
 *   @0x28c550 mov r0, r6
 *   @0x28c554 bl 0x287444 <Json_getFloat>
 *   @0x28c558 ldr r3, [r5, #0x10]
 *   @0x28c55c ldr r1, [pc, #0x3b8]
 *   @0x28c560 mov r2, #0
 *   @0x28c564 cmp r3, #0
 *   @0x28c568 vldreq s14, [r8]
 *   @0x28c56c add r1, pc, r1
 *   @0x28c570 vmov s15, r0
 *   @0x28c574 str r0, [r5, #0x20]
 *   @0x28c578 mov r0, r6
 *   @0x28c57c vmuleq.f32 s15, s15, s14
 *   @0x28c580 vstreq s15, [r5, #32]
 *   @0x28c584 bl 0x287444 <Json_getFloat>
 *   @0x28c588 ldr r3, [r5, #0x14]
 *   @0x28c58c ldr r1, [pc, #0x38c]
 *   @0x28c590 mov r2, #1065353216
 *   @0x28c594 cmp r3, #1
 *   @0x28c598 vldrls s14, [r8]
 *   @0x28c59c add r1, pc, r1
 *   @0x28c5a0 vmov s15, r0
 *   @0x28c5a4 str r0, [r5, #0x24]
 *   @0x28c5a8 mov r0, r6
 *   @0x28c5ac vmulls.f32 s15, s15, s14
 *   @0x28c5b0 vstrls s15, [r5, #36]
 *   @0x28c5b4 bl 0x287444 <Json_getFloat>
 *   @0x28c5b8 ldr r1, [pc, #0x364]
 *   @0x28c5bc mov r2, #1065353216
 *   @0x28c5c0 add r1, pc, r1
 *   @0x28c5c4 str r0, [r5, #0x28]
 *   @0x28c5c8 mov r0, r6
 *   @0x28c5cc bl 0x287444 <Json_getFloat>
 *   @0x28c5d0 ldr r3, [r9, #0x50]
 *   @0x28c5d4 str r0, [r5, #0x2c]
 *   @0x28c5d8 str r5, [r3, r7]
 *   @0x28c5dc add r7, r7, #4
 *   @0x28c5e0 ldr r6, [r6]
 *   @0x28c5e4 cmp r6, #0
 *   @0x28c5e8 bne 0x28c2f4 <spSkeletonJson_readSkeletonData+0xaa8>
 *   @0x28c5ec ldr r1, [pc, #0x334]
 *   @0x28c5f0 ldr r0, [sp, #0x24]
 *   @0x28c5f4 add r1, pc, r1
 *   @0x28c5f8 bl 0x2873c4 <Json_getItem>
 *   @0x28c5fc subs r4, r0, #0
 *   @0x28c600 beq 0x28ccb8 <spSkeletonJson_readSkeletonData+0x146c>
 *   @0x28c604 ldr r0, [r4, #0xc]
 *   @0x28c608 movw r2, #0x347
 *   @0x28c60c ldr r1, [pc, #0x318]
 *   @0x28c610 lsl r0, r0, #2
 *   @0x28c614 add r1, pc, r1
 *   @0x28c618 bl 0x285c10 <_malloc>
 *   @0x28c61c ldr r4, [r4, #0x4]
 *   @0x28c620 cmp r4, #0
 *   @0x28c624 str r4, [sp, #0x18]
 *   @0x28c628 str r0, [r9, #0x24]
 *   @0x28c62c beq 0x28ccb8 <spSkeletonJson_readSkeletonData+0x146c>
 *   @0x28c630 ldr r0, [pc, #0x2f8]
 *   @0x28c634 mov r11, r9
 *   @0x28c638 ldr r2, [pc, #0x2f4]
 *   @0x28c63c movw r1, #0x5556
 *   @0x28c640 ldr r3, [pc, #0x2f0]
 *   @0x28c644 add r0, pc, r0
 *   @0x28c648 add r2, pc, r2
 *   @0x28c64c movt r1, #0x5555
 *   @0x28c650 add r3, pc, r3
 *   @0x28c654 str r0, [sp, #0x4c]
 *   @0x28c658 str r2, [sp, #0x30]
 *   @0x28c65c str r1, [sp, #0x38]
 *   @0x28c660 str r3, [sp, #0x20]
 *   @0x28c664 ldr r1, [sp, #0x18]
 *   @0x28c668 ldr r0, [r1, #0x1c]
 *   @0x28c66c bl 0x28ec44 <spSkin_create>
 *   @0x28c670 ldr r3, [r11, #0x20]
 *   @0x28c674 ldr r2, [r11, #0x24]
 *   @0x28c678 ldr r1, [sp, #0x4c]
 *   @0x28c67c mov r9, r0
 *   @0x28c680 add r0, r3, #1
 *   @0x28c684 str r0, [r11, #0x20]
 *   @0x28c688 str r9, [r2, r3, lsl #2]
 *   @0x28c68c ldr r2, [sp, #0x18]
 *   @0x28c690 ldr r0, [r2, #0x1c]
 *   @0x28c694 bl 0xb6574 <strcmp@plt>
 *   @0x28c698 ldr r3, [sp, #0x18]
 *   @0x28c69c ldr r3, [r3, #0x4]
 *   @0x28c6a0 str r3, [sp, #0x1c]
 *   @0x28c6a4 cmp r0, #0
 *   @0x28c6a8 streq r9, [r11, #0x28]
 *   @0x28c6ac cmp r3, #0
 *   @0x28c6b0 beq 0x28cca0 <spSkeletonJson_readSkeletonData+0x1454>
 *   @0x28c6b4 ldr r1, [pc, #0x280]
 *   @0x28c6b8 str r11, [sp, #0x34]
 *   @0x28c6bc add r1, pc, r1
 *   @0x28c6c0 str r1, [sp, #0x2c]
 *   @0x28c6c4 ldr r2, [sp, #0x1c]
 *   @0x28c6c8 ldr r0, [sp, #0x34]
 *   @0x28c6cc ldr r1, [r2, #0x1c]
 *   @0x28c6d0 bl 0x28b0cc <spSkeletonData_findSlotIndex>
 *   @0x28c6d4 ldr r3, [sp, #0x1c]
 *   @0x28c6d8 ldr r4, [r3, #0x4]
 *   @0x28c6dc cmp r4, #0
 *   @0x28c6e0 str r0, [sp, #0x28]
 *   @0x28c6e4 beq 0x28cc88 <spSkeletonJson_readSkeletonData+0x143c>
 *   @0x28c6e8 ldr r7, [r4, #0x1c]
 *   @0x28c6ec mov r0, r4
 *   @0x28c6f0 ldr r1, [sp, #0x30]
 *   @0x28c6f4 ldr r10, [pc, #0x244]
 *   @0x28c6f8 mov r2, r7
 *   @0x28c6fc bl 0x287428 <Json_getString>
 *   @0x28c700 ldr r1, [sp, #0x20]
 *   @0x28c704 add r10, pc, r10
 *   @0x28c708 mov r11, r10
 *   @0x28c70c mov r6, r0
 *   @0x28c710 mov r0, r4
 *   @0x28c714 mov r2, r6
 *   @0x28c718 bl 0x287428 <Json_getString>
 *   @0x28c71c mov r2, r10
 *   @0x28c720 ldr r1, [sp, #0x2c]
 *   @0x28c724 mov r5, r0
 *   @0x28c728 mov r0, r4
 *   @0x28c72c bl 0x287428 <Json_getString>
 *   @0x28c730 mov r1, r11
 *   @0x28c734 mov r10, r0
 *   @0x28c738 bl 0xb6574 <strcmp@plt>
 *   @0x28c73c cmp r0, #0
 *   @0x28c740 beq 0x28cf2c <spSkeletonJson_readSkeletonData+0x16e0>
 *   @0x28c744 ldr r1, [pc, #0x1f8]
 *   @0x28c748 mov r0, r10
 *   @0x28c74c add r1, pc, r1
 *   @0x28c750 bl 0xb6574 <strcmp@plt>
 *   @0x28c754 cmp r0, #0
 *   @0x28c758 beq 0x28cf24 <spSkeletonJson_readSkeletonData+0x16d8>
 *   @0x28c75c ldr r1, [pc, #0x1e4]
 *   @0x28c760 mov r0, r10
 *   @0x28c764 add r1, pc, r1
 *   @0x28c768 bl 0xb6574 <strcmp@plt>
 *   @0x28c76c cmp r0, #0
 *   @0x28c770 beq 0x28cf34 <spSkeletonJson_readSkeletonData+0x16e8>
 *   @0x28c774 ldr r1, [pc, #0x1d0]
 *   @0x28c778 mov r0, r10
 *   @0x28c77c add r1, pc, r1
 *   @0x28c780 bl 0xb6574 <strcmp@plt>
 *   @0x28c784 cmp r0, #0
 *   @0x28c788 beq 0x28cfa0 <spSkeletonJson_readSkeletonData+0x1754>
 *   @0x28c78c mov r0, r10
 *   @0x28c790 ldr r1, [sp, #0x20]
 *   @0x28c794 bl 0xb6574 <strcmp@plt>
 *   @0x28c798 cmp r0, #0
 *   @0x28c79c bne 0x28e7f4 <spSkeletonJson_readSkeletonData+0x2fa8>
 *   @0x28c7a0 mov r2, #4
 *   @0x28c7a4 ldr r0, [r8, #0x4]
 *   @0x28c7a8 mov r3, r6
 *   @0x28c7ac str r5, [sp]
 *   @0x28c7b0 mov r1, r9
 *   @0x28c7b4 bl 0x284d58 <spAttachmentLoader_createAttachment>
 *   @0x28c7b8 subs r6, r0, #0
 *   @0x28c7bc beq 0x28cf68 <spSkeletonJson_readSkeletonData+0x171c>
 *   @0x28c7c0 ldr r3, [r6, #0x4]
 *   @0x28c7c4 cmp r3, #4
 *   @0x28c7c8 addls pc, pc, r3, lsl #2
 *   @0x28c7cc b 0x28cc68 <spSkeletonJson_readSkeletonData+0x141c>
 *   @0x28c7d0 b 0x28cdac <spSkeletonJson_readSkeletonData+0x1560>
 *   @0x28c7d4 b 0x28cd6c <spSkeletonJson_readSkeletonData+0x1520>
 *   @0x28c7d8 b 0x28cb20 <spSkeletonJson_readSkeletonData+0x12d4>
 *   @0x28c7dc b 0x28cb20 <spSkeletonJson_readSkeletonData+0x12d4>
 *   @0x28c7e0 b 0x28ca5c <spSkeletonJson_readSkeletonData+0x1210>
 *   @0x28c7e4 andeq sp, r10, r0, lsl r8
 *   @0x28c7e8 andeq r12, r12, r8, ror r2
 *   @0x28c7ec andeq r12, r12, r0, ror #4
 *   @0x28c7f0 strdeq r12, sp, [r12], -r8
 *   @0x28c7f4 andeq r12, r12, r0, asr r2
 *   @0x28c7f8 andeq r12, r12, r8, asr #3
 *   @0x28c7fc andeq r12, r12, r0, asr #3
 *   @0x28c800 andeq r12, r12, r12, lsr #3
 *   @0x28c804 andeq r12, r12, r12, lsl r1
 *   @0x28c808 andeq r4, r10, r8, asr lr
 *   @0x28c80c andeq r4, r10, r4, ror lr
 *   @0x28c810 andeq r4, r10, r12, asr #28
 *   @0x28c814 ldrdeq r4, r5, [r10], -r4
 *   @0x28c818 andeq r4, r10, r0, asr #28
 *   @0x28c81c ldrdeq r12, sp, [r12], -r4
 *   @0x28c820 andeq r12, r12, r0, asr #1
 *   @0x28c824 strheq r12, [r12], -r0
 *   @0x28c828 andeq r12, r12, r0, lsr #1
 *   @0x28c82c muleq r12, r0, r0
 *   @0x28c830 andeq r12, r12, r0, lsl #1
 *   @0x28c834 andeq r12, r12, r8, ror r0
 *   @0x28c838 strheq r11, [r12], -r4
 *   @0x28c83c andeq r11, r12, r12, lsl #30
 *   @0x28c840 strdeq r11, r12, [r12], -r4
 *   @0x28c844 andeq r4, r10, r12, lsl #26
 *   @0x28c848 andeq r4, r10, r12, lsl #26
 *   @0x28c84c andeq r4, r10, r12, asr #23
 *   @0x28c850 ldrdeq r11, r12, [r12], -r4
 *   @0x28c854 ldrdeq r11, r12, [r12], -r4
 *   @0x28c858 strdeq r11, r12, [r12], -r12
 *   @0x28c85c andeq r11, r12, r8, ror #29
 *   @0x28c860 andeq r11, r12, r8, lsr lr
 *   @0x28c864 andeq r11, r12, r0, lsl lr
 *   @0x28c868 andeq r11, r12, r0, lsl #26
 *   @0x28c86c ldrdeq r4, r5, [r10], -r8
 *   @0x28c870 andeq r11, r12, r4, asr #26
 *   @0x28c874 andeq r11, r12, r4, lsl #28
 *   @0x28c878 andeq r11, r12, r12, lsr #28
 *   @0x28c87c andeq r11, r12, r0, lsr lr
 *   @0x28c880 andeq r11, r12, r4, asr #26
 *   @0x28c884 andeq r11, r12, r0, asr r12
 *   @0x28c888 andeq sp, r10, r0, asr #2
 *   @0x28c88c andeq r11, r12, r0, asr #24
 *   @0x28c890 andeq r11, r12, r4, ror #21
 *   @0x28c894 strheq r4, [r10], -r12
 *   @0x28c898 andeq r11, r12, r8, lsr #22
 *   @0x28c89c andeq r11, r12, r8, ror #23
 *   @0x28c8a0 andeq r11, r12, r8, lsr r11
 *   @0x28c8a4 andeq r11, r12, r12, ror r11
 *   @0x28c8a8 andeq r4, r10, r4, lsl #14
 *   @0x28c8ac andeq r4, r10, r12, ror #13
 *   @0x28c8b0 andeq r11, r12, r4, lsl #20
 *   @0x28c8b4 andeq r11, r12, r12, ror #19
 *   @0x28c8b8 andeq r11, r12, r4, ror #19
 *   @0x28c8bc strheq r11, [r12], -r8
 *   @0x28c8c0 andeq r11, r12, r12, lsr #21
 *   @0x28c8c4 andeq r11, r12, r4, lsr #21
 *   @0x28c8c8 muleq r12, r8, r10
 *   @0x28c8cc andeq r11, r12, r8, lsl r10
 *   @0x28c8d0 andeq r11, r12, r8, ror #16
 *   @0x28c8d4 andeq r4, r10, r0, asr #10
 *   @0x28c8d8 andeq r11, r12, r12, lsr #17
 *   @0x28c8dc andeq r11, r12, r12, ror #18
 *   @0x28c8e0 andeq r11, r12, r8, lsr r10
 *   @0x28c8e4 andeq r11, r12, r4, asr r9
 *   @0x28c8e8 andeq r11, r12, r12, ror r7
 *   @0x28c8ec andeq r11, r12, r8, lsr #18
 *   @0x28c8f0 andeq r11, r12, r0, lsr #18
 *   @0x28c8f4 andeq r4, r10, r4, lsl r4
 *   @0x28c8f8 andeq r11, r12, r8, ror #17
 *   @0x28c8fc strheq r11, [r12], -r4
 *   @0x28c900 andeq r11, r12, r12, lsl #17
 *   @0x28c904 muleq r12, r4, r8
 *   @0x28c908 andeq r11, r12, r4, lsl #17
 *   @0x28c90c andeq r11, r12, r12, ror #16
 *   @0x28c910 andeq r11, r12, r4, asr r8
 *   @0x28c914 andeq r11, r12, r0, ror r6
 *   @0x28c918 andeq r11, r12, r0, lsr r8
 *   @0x28c91c andeq r11, r12, r8, lsl r8
 *   @0x28c920 andeq r11, r12, r12, lsl r7
 *   @0x28c924 andeq r11, r12, r4, lsl #14
 *   @0x28c928 strdeq r11, r12, [r12], -r8
 *   @0x28c92c andeq r11, r12, r12, ror #9
 *   @0x28c930 andeq r4, r10, r4, asr pc
 *   @0x28c934 andeq r4, r10, r0, asr #3
 *   @0x28c938 andeq r11, r12, r4, asr #12
 *   @0x28c93c andeq r9, r11, r12, ror #20
 *   @0x28c940 muleq r12, r0, r6
 *   @0x28c944 andeq r11, r12, r0, asr r6
 *   @0x28c948 andeq r11, r12, r0, asr #12
 *   @0x28c94c andeq r11, r12, r4, lsr r6
 *   @0x28c950 muleq r12, r0, r3
 *   @0x28c954 andeq r11, r12, r8, lsl #7
 *   @0x28c958 andeq r11, r12, r12, asr r3
 *   @0x28c95c andeq r11, r12, r8, lsr r0
 *   @0x28c960 andeq r11, r12, r0, lsr r3
 *   @0x28c964 ldrdeq r10, r11, [r12], -r0
 *   @0x28c968 strheq r11, [r12], -r12
 *   @0x28c96c andeq r10, r12, r4, asr #31
 *   @0x28c970 strheq r10, [r12], -r8
 *   @0x28c974 strheq r3, [r10], -r4
 *   @0x28c978 ldrdeq r11, r12, [r12], -r0
 *   @0x28c97c andeq r11, r12, r8, asr #3
 *   @0x28c980 strheq r11, [r12], -r12
 *   @0x28c984 andeq r11, r12, r4, ror r0
 *   @0x28c988 andeq r10, r12, r12, lsr sp
 *   @0x28c98c andeq r3, r10, r12, lsl #21
 *   @0x28c990 andeq r3, r10, r12, ror r10
 *   @0x28c994 muleq r12, r4, sp
 *   @0x28c998 andeq r10, r12, r12, ror sp
 *   @0x28c99c andeq r10, r12, r0, asr sp
 *   @0x28c9a0 andeq r10, r12, r0, lsl #26
 *   @0x28c9a4 andeq r10, r12, r12, ror #25
 *   @0x28c9a8 andeq r10, r12, r0, ror #26
 *   @0x28c9ac andeq r10, r12, r4, lsl sp
 *   @0x28c9b0 andeq r10, r12, r8, lsr r11
 *   @0x28c9b4 strheq r10, [r12], -r0
 *   @0x28c9b8 andeq r10, r12, r4, ror #21
 *   @0x28c9bc andeq r10, r12, r4, ror #26
 *   @0x28c9c0 andeq r10, r12, r12, lsl #21
 *   @0x28c9c4 strdeq r10, r11, [r12], -r4
 *   @0x28c9c8 strdeq r10, r11, [r12], -r0
 *   @0x28c9cc strdeq r10, r11, [r12], -r4
 *   @0x28c9d0 andeq r10, r12, r12, lsl #22
 *   @0x28c9d4 andeq r10, r12, r4, lsl #23
 *   @0x28c9d8 andeq r10, r12, r8, ror #23
 *   @0x28c9dc andeq r10, r12, r12, lsr r9
 *   @0x28c9e0 andeq r10, r12, r0, ror #24
 *   @0x28c9e4 andeq r3, r10, r4, lsr r6
 *   @0x28c9e8 andeq r10, r12, r4, lsl #18
 *   @0x28c9ec andeq r3, r10, r12, lsl r6
 *   @0x28c9f0 andeq r10, r12, r12, lsr #23
 *   @0x28c9f4 andeq r10, r12, r8, asr #16
 *   @0x28c9f8 muleq r12, r12, r8
 *   @0x28c9fc muleq r12, r8, r8
 *   @0x28ca00 strdeq r10, r11, [r12], -r12
 *   @0x28ca04 andeq r10, r12, r0, asr #18
 *   @0x28ca08 strdeq r10, r11, [r12], -r12
 *   @0x28ca0c andeq r10, r12, r0, ror r10
 *   @0x28ca10 ldrdeq r10, r11, [r12], -r12
 *   @0x28ca14 strdeq r10, r11, [r12], -r8
 *   @0x28ca18 andeq r3, r10, r0, lsl r3
 *   @0x28ca1c andeq lr, r11, r12, asr #25
 *   @0x28ca20 andeq r10, r12, r8, lsl #14
 *   @0x28ca24 andeq r3, r10, r0, lsr r4
 *   @0x28ca28 strdeq r10, r11, [r12], -r12
 *   @0x28ca2c andeq r10, r12, r12, asr r8
 *   @0x28ca30 andeq r10, r12, r8, asr r8
 *   @0x28ca34 andeq r10, r12, r8, asr r8
 *   @0x28ca38 andeq r10, r12, r12, asr r8
 *   @0x28ca3c andeq lr, r11, r4, asr #22
 *   @0x28ca40 andeq r3, r10, r8, lsl r1
 *   @0x28ca44 andeq r3, r10, r8, lsl r1
 *   @0x28ca48 andeq lr, r11, r4, ror #18
 *   @0x28ca4c andeq r10, r12, r4, lsr #8
 *   @0x28ca50 andeq r10, r12, r12, lsl #8
 *   @0x28ca54 andeq lr, r11, r4, asr #17
 *   @0x28ca58 andeq r10, r12, r12, asr #8
 *   @0x28ca5c ldr r1, [pc, #-0x114]
 *   @0x28ca60 mov r2, #0
 *   @0x28ca64 mov r0, r4
 *   @0x28ca68 add r1, pc, r1
 *   @0x28ca6c bl 0x287460 <Json_getInt>
 *   @0x28ca70 ldr r1, [pc, #-0x124]
 *   @0x28ca74 mov r2, #1
 *   @0x28ca78 add r1, pc, r1
 *   @0x28ca7c str r0, [r6, #0x2c]
 *   @0x28ca80 mov r0, r4
 *   @0x28ca84 bl 0x287460 <Json_getInt>
 *   @0x28ca88 ldr r1, [pc, #-0x138]
 *   @0x28ca8c mov r2, #0
 *   @0x28ca90 add r1, pc, r1
 *   @0x28ca94 str r0, [r6, #0x30]
 *   @0x28ca98 mov r0, r4
 *   @0x28ca9c bl 0x287460 <Json_getInt>
 *   @0x28caa0 mov r1, r4
 *   @0x28caa4 mov r2, r6
 *   @0x28caa8 mov r5, r0
 *   @0x28caac mov r0, r8
 *   @0x28cab0 lsl r3, r5, #1
 *   @0x28cab4 bl 0x28b3fc <spSkeletonData_findPathConstraint+0x10c>
 *   @0x28cab8 ldr r1, [sp, #0x38]
 *   @0x28cabc movw r2, #0x3d9
 *   @0x28cac0 smull r1, r0, r1, r5
 *   @0x28cac4 ldr r1, [pc, #-0x170]
 *   @0x28cac8 add r1, pc, r1
 *   @0x28cacc sub r0, r0, r5, asr #31
 *   @0x28cad0 str r0, [r6, #0x24]
 *   @0x28cad4 lsl r0, r0, #2
 *   @0x28cad8 bl 0x285c10 <_malloc>
 *   @0x28cadc ldr r1, [pc, #-0x184]
 *   @0x28cae0 add r1, pc, r1
 *   @0x28cae4 str r0, [r6, #0x28]
 *   @0x28cae8 mov r0, r4
 *   @0x28caec bl 0x2873c4 <Json_getItem>
 *   @0x28caf0 ldr r3, [r0, #0x4]
 *   @0x28caf4 cmp r3, #0
 *   @0x28caf8 beq 0x28cc68 <spSkeletonJson_readSkeletonData+0x141c>
 *   @0x28cafc ldr r2, [r6, #0x28]
 *   @0x28cb00 vldr s14, [r3, #24]
 *   @0x28cb04 vldr s15, [r8]
 *   @0x28cb08 vmul.f32 s15, s14, s15
 *   @0x28cb0c ldr r3, [r3]
 *   @0x28cb10 cmp r3, #0
 *   @0x28cb14 vstmia r2!, {s15}
 *   @0x28cb18 bne 0x28cb00 <spSkeletonJson_readSkeletonData+0x12b4>
 *   @0x28cb1c b 0x28cc68 <spSkeletonJson_readSkeletonData+0x141c>
 *   @0x28cb20 mov r0, r5
 *   @0x28cb24 bl 0xb6538 <strlen@plt>
 *   @0x28cb28 ldr r1, [pc, #-0x1cc]
 *   @0x28cb2c movw r2, #0x395
 *   @0x28cb30 add r1, pc, r1
 *   @0x28cb34 add r0, r0, #1
 *   @0x28cb38 bl 0x285c10 <_malloc>
 *   @0x28cb3c mov r1, r5
 *   @0x28cb40 str r0, [r6, #0x54]
 *   @0x28cb44 bl 0xb65a4 <strcpy@plt>
 *   @0x28cb48 ldr r1, [pc, #-0x1e8]
 *   @0x28cb4c mov r0, r4
 *   @0x28cb50 mov r2, #0
 *   @0x28cb54 add r1, pc, r1
 *   @0x28cb58 bl 0x287428 <Json_getString>
 *   @0x28cb5c subs r5, r0, #0
 *   @0x28cb60 beq 0x28cba0 <spSkeletonJson_readSkeletonData+0x1354>
 *   @0x28cb64 mov r1, #0
 *   @0x28cb68 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28cb6c mov r0, r5
 *   @0x28cb70 mov r1, #1
 *   @0x28cb74 vstr s0, [r6, #104]
 *   @0x28cb78 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28cb7c mov r0, r5
 *   @0x28cb80 mov r1, #2
 *   @0x28cb84 vstr s0, [r6, #108]
 *   @0x28cb88 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28cb8c mov r0, r5
 *   @0x28cb90 mov r1, #3
 *   @0x28cb94 vstr s0, [r6, #112]
 *   @0x28cb98 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28cb9c vstr s0, [r6, #116]
 *   @0x28cba0 ldr r1, [pc, #-0x23c]
 *   @0x28cba4 mov r2, #1107296256
 *   @0x28cba8 mov r0, r4
 *   @0x28cbac add r1, pc, r1
 *   @0x28cbb0 bl 0x287444 <Json_getFloat>
 *   @0x28cbb4 vldr s15, [r8]
 *   @0x28cbb8 ldr r1, [pc, #-0x250]
 *   @0x28cbbc mov r2, #1107296256
 *   @0x28cbc0 add r1, pc, r1
 *   @0x28cbc4 vmov s14, r0
 *   @0x28cbc8 mov r0, r4
 *   @0x28cbcc vmul.f32 s15, s14, s15
 *   @0x28cbd0 vstr s15, [r6, #140]
 *   @0x28cbd4 bl 0x287444 <Json_getFloat>
 *   @0x28cbd8 vldr s15, [r8]
 *   @0x28cbdc ldr r1, [pc, #-0x270]
 *   @0x28cbe0 add r1, pc, r1
 *   @0x28cbe4 vmov s14, r0
 *   @0x28cbe8 mov r0, r4
 *   @0x28cbec vmul.f32 s15, s14, s15
 *   @0x28cbf0 vstr s15, [r6, #144]
 *   @0x28cbf4 bl 0x2873c4 <Json_getItem>
 *   @0x28cbf8 subs r5, r0, #0
 *   @0x28cbfc mov r0, r4
 *   @0x28cc00 beq 0x28d008 <spSkeletonJson_readSkeletonData+0x17bc>
 *   @0x28cc04 ldr r1, [pc, #-0x294]
 *   @0x28cc08 mov r2, #1
 *   @0x28cc0c add r1, pc, r1
 *   @0x28cc10 bl 0x287460 <Json_getInt>
 *   @0x28cc14 ldr r1, [pc, #-0x2a0]
 *   @0x28cc18 mov r2, #0
 *   @0x28cc1c add r1, pc, r1
 *   @0x28cc20 str r0, [r6, #0x80]
 *   @0x28cc24 mov r0, r4
 *   @0x28cc28 bl 0x287428 <Json_getString>
 *   @0x28cc2c ldr r2, [r8, #0x10]
 *   @0x28cc30 ldr r1, [r8, #0x14]
 *   @0x28cc34 ldr r10, [r5, #0x10]
 *   @0x28cc38 cmp r2, r1
 *   @0x28cc3c mov r3, r0
 *   @0x28cc40 beq 0x28cfa8 <spSkeletonJson_readSkeletonData+0x175c>
 *   @0x28cc44 ldr r1, [r8, #0x18]
 *   @0x28cc48 add r0, r1, r2, lsl #4
 *   @0x28cc4c add r12, r2, #1
 *   @0x28cc50 str r12, [r8, #0x10]
 *   @0x28cc54 str r3, [r0, #0x4]
 *   @0x28cc58 ldr r3, [sp, #0x28]
 *   @0x28cc5c str r6, [r0, #0xc]
 *   @0x28cc60 str r3, [r0, #0x8]
 *   @0x28cc64 str r10, [r1, r2, lsl #4]
 *   @0x28cc68 mov r2, r7
 *   @0x28cc6c mov r3, r6
 *   @0x28cc70 mov r0, r9
 *   @0x28cc74 ldr r1, [sp, #0x28]
 *   @0x28cc78 bl 0x28ecd8 <spSkin_addAttachment>
 *   @0x28cc7c ldr r4, [r4]
 *   @0x28cc80 cmp r4, #0
 *   @0x28cc84 bne 0x28c6e8 <spSkeletonJson_readSkeletonData+0xe9c>
 *   @0x28cc88 ldr r0, [sp, #0x1c]
 *   @0x28cc8c ldr r0, [r0]
 *   @0x28cc90 cmp r0, #0
 *   @0x28cc94 str r0, [sp, #0x1c]
 *   @0x28cc98 bne 0x28c6c4 <spSkeletonJson_readSkeletonData+0xe78>
 *   @0x28cc9c ldr r11, [sp, #0x34]
 *   @0x28cca0 ldr r0, [sp, #0x18]
 *   @0x28cca4 ldr r0, [r0]
 *   @0x28cca8 cmp r0, #0
 *   @0x28ccac str r0, [sp, #0x18]
 *   @0x28ccb0 bne 0x28c664 <spSkeletonJson_readSkeletonData+0xe18>
 *   @0x28ccb4 mov r9, r11
 *   @0x28ccb8 ldr r3, [r8, #0x10]
 *   @0x28ccbc cmp r3, #0
 *   @0x28ccc0 movgt r6, #0
 *   @0x28ccc4 bgt 0x28cd0c <spSkeletonJson_readSkeletonData+0x14c0>
 *   @0x28ccc8 b 0x28d19c <spSkeletonJson_readSkeletonData+0x1950>
 *   @0x28cccc ldr r1, [r4, #0x8]
 *   @0x28ccd0 ldr r2, [r10, r7]
 *   @0x28ccd4 bl 0x28ed00 <spSkin_getAttachment>
 *   @0x28ccd8 cmp r0, #0
 *   @0x28ccdc mov r1, r0
 *   @0x28cce0 beq 0x28e880 <spSkeletonJson_readSkeletonData+0x3034>
 *   @0x28cce4 ldr r0, [r4, #0xc]
 *   @0x28cce8 bl 0x287654 <spMeshAttachment_setParentMesh>
 *   @0x28ccec ldr r0, [r4, #0xc]
 *   @0x28ccf0 bl 0x287538 <spMeshAttachment_updateUVs>
 *   @0x28ccf4 ldr r1, [r4, #0xc]
 *   @0x28ccf8 ldr r0, [r8, #0x4]
 *   @0x28ccfc bl 0x284db8 <spAttachmentLoader_configureAttachment>
 *   @0x28cd00 ldr r3, [r8, #0x10]
 *   @0x28cd04 cmp r3, r6
 *   @0x28cd08 ble 0x28d19c <spSkeletonJson_readSkeletonData+0x1950>
 *   @0x28cd0c ldr r10, [r8, #0x18]
 *   @0x28cd10 lsl r7, r6, #4
 *   @0x28cd14 mov r0, r9
 *   @0x28cd18 add r4, r10, r7
 *   @0x28cd1c ldr r1, [r4, #0x4]
 *   @0x28cd20 cmp r1, #0
 *   @0x28cd24 ldreq r5, [r9, #0x28]
 *   @0x28cd28 beq 0x28cd34 <spSkeletonJson_readSkeletonData+0x14e8>
 *   @0x28cd2c bl 0x28b124 <spSkeletonData_findSkin>
 *   @0x28cd30 mov r5, r0
 *   @0x28cd34 cmp r5, #0
 *   @0x28cd38 add r6, r6, #1
 *   @0x28cd3c mov r0, r5
 *   @0x28cd40 bne 0x28cccc <spSkeletonJson_readSkeletonData+0x1480>
 *   @0x28cd44 mov r0, r9
 *   @0x28cd48 bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28cd4c ldr r2, [pc, #-0x3d4]
 *   @0x28cd50 mov r0, r8
 *   @0x28cd54 mov r1, r5
 *   @0x28cd58 ldr r3, [r4, #0x4]
 *   @0x28cd5c add r2, pc, r2
 *   @0x28cd60 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28cd64 mov r0, r5
 *   @0x28cd68 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580>
 *   @0x28cd6c ldr r1, [pc, #-0x3f0]
 *   @0x28cd70 mov r2, #0
 *   @0x28cd74 mov r0, r4
 *   @0x28cd78 add r1, pc, r1
 *   @0x28cd7c bl 0x287460 <Json_getInt>
 *   @0x28cd80 mov r1, r4
 *   @0x28cd84 mov r2, r6
 *   @0x28cd88 lsl r5, r0, #1
 *   @0x28cd8c mov r0, r8
 *   @0x28cd90 mov r3, r5
 *   @0x28cd94 bl 0x28b3fc <spSkeletonData_findPathConstraint+0x10c>
 *   @0x28cd98 str r5, [r6, #0x18]
 *   @0x28cd9c ldr r0, [r8, #0x4]
 *   @0x28cda0 mov r1, r6
 *   @0x28cda4 bl 0x284db8 <spAttachmentLoader_configureAttachment>
 *   @0x28cda8 b 0x28cc68 <spSkeletonJson_readSkeletonData+0x141c>
 *   @0x28cdac cmp r5, #0
 *   @0x28cdb0 beq 0x28cddc <spSkeletonJson_readSkeletonData+0x1590>
 *   @0x28cdb4 mov r0, r5
 *   @0x28cdb8 bl 0xb6538 <strlen@plt>
 *   @0x28cdbc ldr r1, [pc, #-0x43c]
 *   @0x28cdc0 movw r2, #0x37b
 *   @0x28cdc4 add r1, pc, r1
 *   @0x28cdc8 add r0, r0, #1
 *   @0x28cdcc bl 0x285c10 <_malloc>
 *   @0x28cdd0 mov r1, r5
 *   @0x28cdd4 str r0, [r6, #0x10]
 *   @0x28cdd8 bl 0xb65a4 <strcpy@plt>
 *   @0x28cddc ldr r1, [pc, #-0x458]
 *   @0x28cde0 mov r2, #0
 *   @0x28cde4 mov r0, r4
 *   @0x28cde8 add r1, pc, r1
 *   @0x28cdec bl 0x287444 <Json_getFloat>
 *   @0x28cdf0 vldr s15, [r8]
 *   @0x28cdf4 ldr r1, [pc, #-0x46c]
 *   @0x28cdf8 mov r2, #0
 *   @0x28cdfc add r1, pc, r1
 *   @0x28ce00 vmov s14, r0
 *   @0x28ce04 mov r0, r4
 *   @0x28ce08 vmul.f32 s15, s14, s15
 *   @0x28ce0c vstr s15, [r6, #20]
 *   @0x28ce10 bl 0x287444 <Json_getFloat>
 *   @0x28ce14 vldr s15, [r8]
 *   @0x28ce18 ldr r1, [pc, #-0x48c]
 *   @0x28ce1c mov r2, #1065353216
 *   @0x28ce20 add r1, pc, r1
 *   @0x28ce24 vmov s14, r0
 *   @0x28ce28 mov r0, r4
 *   @0x28ce2c vmul.f32 s15, s14, s15
 *   @0x28ce30 vstr s15, [r6, #24]
 *   @0x28ce34 bl 0x287444 <Json_getFloat>
 *   @0x28ce38 ldr r1, [pc, #-0x4a8]
 *   @0x28ce3c mov r2, #1065353216
 *   @0x28ce40 add r1, pc, r1
 *   @0x28ce44 str r0, [r6, #0x1c]
 *   @0x28ce48 mov r0, r4
 *   @0x28ce4c bl 0x287444 <Json_getFloat>
 *   @0x28ce50 ldr r1, [pc, #-0x4bc]
 *   @0x28ce54 mov r2, #0
 *   @0x28ce58 add r1, pc, r1
 *   @0x28ce5c str r0, [r6, #0x20]
 *   @0x28ce60 mov r0, r4
 *   @0x28ce64 bl 0x287444 <Json_getFloat>
 *   @0x28ce68 ldr r1, [pc, #-0x4d0]
 *   @0x28ce6c mov r2, #1107296256
 *   @0x28ce70 add r1, pc, r1
 *   @0x28ce74 str r0, [r6, #0x24]
 *   @0x28ce78 mov r0, r4
 *   @0x28ce7c bl 0x287444 <Json_getFloat>
 *   @0x28ce80 vldr s15, [r8]
 *   @0x28ce84 ldr r1, [pc, #-0x4e8]
 *   @0x28ce88 mov r2, #1107296256
 *   @0x28ce8c add r1, pc, r1
 *   @0x28ce90 vmov s14, r0
 *   @0x28ce94 mov r0, r4
 *   @0x28ce98 vmul.f32 s15, s14, s15
 *   @0x28ce9c vstr s15, [r6, #40]
 *   @0x28cea0 bl 0x287444 <Json_getFloat>
 *   @0x28cea4 vldr s15, [r8]
 *   @0x28cea8 ldr r1, [pc, #-0x508]
 *   @0x28ceac mov r2, #0
 *   @0x28ceb0 add r1, pc, r1
 *   @0x28ceb4 vmov s14, r0
 *   @0x28ceb8 mov r0, r4
 *   @0x28cebc vmul.f32 s15, s14, s15
 *   @0x28cec0 vstr s15, [r6, #44]
 *   @0x28cec4 bl 0x287428 <Json_getString>
 *   @0x28cec8 subs r5, r0, #0
 *   @0x28cecc beq 0x28cf0c <spSkeletonJson_readSkeletonData+0x16c0>
 *   @0x28ced0 mov r1, #0
 *   @0x28ced4 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28ced8 mov r0, r5
 *   @0x28cedc mov r1, #1
 *   @0x28cee0 vstr s0, [r6, #48]
 *   @0x28cee4 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28cee8 mov r0, r5
 *   @0x28ceec mov r1, #2
 *   @0x28cef0 vstr s0, [r6, #52]
 *   @0x28cef4 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28cef8 mov r0, r5
 *   @0x28cefc mov r1, #3
 *   @0x28cf00 vstr s0, [r6, #56]
 *   @0x28cf04 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28cf08 vstr s0, [r6, #60]
 *   @0x28cf0c mov r0, r6
 *   @0x28cf10 bl 0x289040 <spRegionAttachment_updateOffset>
 *   @0x28cf14 ldr r0, [r8, #0x4]
 *   @0x28cf18 mov r1, r6
 *   @0x28cf1c bl 0x284db8 <spAttachmentLoader_configureAttachment>
 *   @0x28cf20 b 0x28cc68 <spSkeletonJson_readSkeletonData+0x141c>
 *   @0x28cf24 mov r2, #2
 *   @0x28cf28 b 0x28c7a4 <spSkeletonJson_readSkeletonData+0xf58>
 *   @0x28cf2c mov r2, r0
 *   @0x28cf30 b 0x28c7a4 <spSkeletonJson_readSkeletonData+0xf58>
 *   @0x28cf34 mov r2, #3
 *   @0x28cf38 b 0x28c7a4 <spSkeletonJson_readSkeletonData+0xf58>
 *   @0x28cf3c mov r4, r0
 *   @0x28cf40 mov r0, r9
 *   @0x28cf44 bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28cf48 ldr r2, [pc, #-0x5a4]
 *   @0x28cf4c mov r0, r8
 *   @0x28cf50 ldr r1, [sp, #0x24]
 *   @0x28cf54 add r2, pc, r2
 *   @0x28cf58 ldr r3, [r4, #0x1c]
 *   @0x28cf5c bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28cf60 mov r0, r4
 *   @0x28cf64 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580>
 *   @0x28cf68 ldr r3, [r8, #0x4]
 *   @0x28cf6c ldr r3, [r3]
 *   @0x28cf70 cmp r3, #0
 *   @0x28cf74 beq 0x28cc7c <spSkeletonJson_readSkeletonData+0x1430>
 *   @0x28cf78 ldr r9, [sp, #0x34]
 *   @0x28cf7c mov r0, r9
 *   @0x28cf80 bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28cf84 ldr r3, [r8, #0x4]
 *   @0x28cf88 mov r0, r8
 *   @0x28cf8c ldr r1, [sp, #0x24]
 *   @0x28cf90 ldm r3, {r2, r3}
 *   @0x28cf94 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28cf98 mov r0, r6
 *   @0x28cf9c b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580>
 *   @0x28cfa0 mov r2, #1
 *   @0x28cfa4 b 0x28c7a4 <spSkeletonJson_readSkeletonData+0xf58>
 *   @0x28cfa8 lsl r1, r2, #1
 *   @0x28cfac cmp r1, #7
 *   @0x28cfb0 strgt r1, [r8, #0x14]
 *   @0x28cfb4 ldr r1, [pc, #-0x60c]
 *   @0x28cfb8 lslgt r0, r2, #5
 *   @0x28cfbc movle r2, #8
 *   @0x28cfc0 movle r0, #128
 *   @0x28cfc4 strle r2, [r8, #0x14]
 *   @0x28cfc8 add r1, pc, r1
 *   @0x28cfcc mov r2, #136
 *   @0x28cfd0 str r3, [sp, #0x10]
 *   @0x28cfd4 bl 0x285c10 <_malloc>
 *   @0x28cfd8 ldr r2, [r8, #0x10]
 *   @0x28cfdc ldr r1, [r8, #0x18]
 *   @0x28cfe0 lsl r2, r2, #4
 *   @0x28cfe4 mov r5, r0
 *   @0x28cfe8 bl 0xb65bc <memcpy@plt>
 *   @0x28cfec ldr r0, [r8, #0x18]
 *   @0x28cff0 bl 0x285c80 <_free>
 *   @0x28cff4 ldr r2, [r8, #0x10]
 *   @0x28cff8 mov r1, r5
 *   @0x28cffc str r5, [r8, #0x18]
 *   @0x28d000 ldr r3, [sp, #0x10]
 *   @0x28d004 b 0x28cc48 <spSkeletonJson_readSkeletonData+0x13fc>
 *   @0x28d008 ldr r1, [pc, #-0x65c]
 *   @0x28d00c add r1, pc, r1
 *   @0x28d010 bl 0x2873c4 <Json_getItem>
 *   @0x28d014 ldr r1, [pc, #-0x664]
 *   @0x28d018 movw r2, #0x3a7
 *   @0x28d01c add r1, pc, r1
 *   @0x28d020 mov r5, r0
 *   @0x28d024 ldr r0, [r0, #0xc]
 *   @0x28d028 str r0, [r6, #0x60]
 *   @0x28d02c lsl r0, r0, #1
 *   @0x28d030 bl 0x285c10 <_malloc>
 *   @0x28d034 ldr r3, [r5, #0x4]
 *   @0x28d038 cmp r3, #0
 *   @0x28d03c str r0, [r6, #0x64]
 *   @0x28d040 subne r2, r0, #2
 *   @0x28d044 beq 0x28d05c <spSkeletonJson_readSkeletonData+0x1810>
 *   @0x28d048 ldr r1, [r3, #0x14]
 *   @0x28d04c ldr r3, [r3]
 *   @0x28d050 cmp r3, #0
 *   @0x28d054 strh r1, [r2, #2]!
 *   @0x28d058 bne 0x28d048 <spSkeletonJson_readSkeletonData+0x17fc>
 *   @0x28d05c ldr r1, [pc, #-0x6a8]
 *   @0x28d060 mov r0, r4
 *   @0x28d064 add r1, pc, r1
 *   @0x28d068 bl 0x2873c4 <Json_getItem>
 *   @0x28d06c ldr r1, [pc, #-0x6b4]
 *   @0x28d070 movw r2, #0x3ad
 *   @0x28d074 add r1, pc, r1
 *   @0x28d078 ldr r5, [r0, #0xc]
 *   @0x28d07c mov r10, r0
 *   @0x28d080 lsl r0, r5, #2
 *   @0x28d084 bl 0x285c10 <_malloc>
 *   @0x28d088 ldr r2, [r10, #0x4]
 *   @0x28d08c cmp r2, #0
 *   @0x28d090 str r0, [r6, #0x58]
 *   @0x28d094 movne r3, r0
 *   @0x28d098 beq 0x28d0b0 <spSkeletonJson_readSkeletonData+0x1864>
 *   @0x28d09c ldr r1, [r2, #0x18]
 *   @0x28d0a0 ldr r2, [r2]
 *   @0x28d0a4 cmp r2, #0
 *   @0x28d0a8 str r1, [r3], #4
 *   @0x28d0ac bne 0x28d09c <spSkeletonJson_readSkeletonData+0x1850>
 *   @0x28d0b0 mov r3, r5
 *   @0x28d0b4 mov r1, r4
 *   @0x28d0b8 mov r2, r6
 *   @0x28d0bc mov r0, r8
 *   @0x28d0c0 bl 0x28b3fc <spSkeletonData_findPathConstraint+0x10c>
 *   @0x28d0c4 mov r0, r6
 *   @0x28d0c8 bl 0x287538 <spMeshAttachment_updateUVs>
 *   @0x28d0cc ldr r1, [pc, #-0x710]
 *   @0x28d0d0 mov r2, #0
 *   @0x28d0d4 mov r0, r4
 *   @0x28d0d8 add r1, pc, r1
 *   @0x28d0dc bl 0x287460 <Json_getInt>
 *   @0x28d0e0 ldr r1, [pc, #-0x720]
 *   @0x28d0e4 add r1, pc, r1
 *   @0x28d0e8 str r0, [r6, #0x78]
 *   @0x28d0ec mov r0, r4
 *   @0x28d0f0 bl 0x2873c4 <Json_getItem>
 *   @0x28d0f4 subs r5, r0, #0
 *   @0x28d0f8 beq 0x28cd9c <spSkeletonJson_readSkeletonData+0x1550>
 *   @0x28d0fc ldr r0, [r5, #0xc]
 *   @0x28d100 movw r2, #0x3ba
 *   @0x28d104 ldr r1, [pc, #-0x740]
 *   @0x28d108 str r0, [r6, #0x84]
 *   @0x28d10c add r1, pc, r1
 *   @0x28d110 lsl r0, r0, #2
 *   @0x28d114 bl 0x285c10 <_malloc>
 *   @0x28d118 ldr r3, [r5, #0x4]
 *   @0x28d11c cmp r3, #0
 *   @0x28d120 str r0, [r6, #0x88]
 *   @0x28d124 beq 0x28cd9c <spSkeletonJson_readSkeletonData+0x1550>
 *   @0x28d128 sub r2, r0, #4
 *   @0x28d12c ldr r1, [r3, #0x14]
 *   @0x28d130 ldr r3, [r3]
 *   @0x28d134 cmp r3, #0
 *   @0x28d138 str r1, [r2, #0x4]!
 *   @0x28d13c bne 0x28d12c <spSkeletonJson_readSkeletonData+0x18e0>
 *   @0x28d140 b 0x28cd9c <spSkeletonJson_readSkeletonData+0x1550>
 *   @0x28d144 mov r4, r0
 *   @0x28d148 mov r0, r9
 *   @0x28d14c bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28d150 ldr r2, [pc, #-0x788]
 *   @0x28d154 mov r0, r8
 *   @0x28d158 ldr r1, [sp, #0x24]
 *   @0x28d15c add r2, pc, r2
 *   @0x28d160 ldr r3, [r4, #0x1c]
 *   @0x28d164 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28d168 mov r0, r4
 *   @0x28d16c b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580>
 *   @0x28d170 mov r4, r0
 *   @0x28d174 mov r0, r9
 *   @0x28d178 bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28d17c ldr r2, [pc, #-0x7b0]
 *   @0x28d180 mov r0, r8
 *   @0x28d184 ldr r1, [sp, #0x24]
 *   @0x28d188 add r2, pc, r2
 *   @0x28d18c ldr r3, [r4, #0x1c]
 *   @0x28d190 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28d194 mov r0, r4
 *   @0x28d198 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580>
 *   @0x28d19c ldr r1, [pc, #-0x7cc]
 *   @0x28d1a0 ldr r0, [sp, #0x24]
 *   @0x28d1a4 add r1, pc, r1
 *   @0x28d1a8 bl 0x2873c4 <Json_getItem>
 *   @0x28d1ac subs r4, r0, #0
 *   @0x28d1b0 beq 0x28d290 <spSkeletonJson_readSkeletonData+0x1a44>
 *   @0x28d1b4 ldr r0, [r4, #0xc]
 *   @0x28d1b8 movw r2, #0x404
 *   @0x28d1bc ldr r1, [pc, #-0x7e8]
 *   @0x28d1c0 str r0, [r9, #0x2c]
 *   @0x28d1c4 add r1, pc, r1
 *   @0x28d1c8 lsl r0, r0, #2
 *   @0x28d1cc bl 0x285c10 <_malloc>
 *   @0x28d1d0 ldr r4, [r4, #0x4]
 *   @0x28d1d4 cmp r4, #0
 *   @0x28d1d8 str r0, [r9, #0x30]
 *   @0x28d1dc beq 0x28d290 <spSkeletonJson_readSkeletonData+0x1a44>
 *   @0x28d1e0 ldr r3, [pc, #-0x808]
 *   @0x28d1e4 mov r10, #0
 *   @0x28d1e8 ldr r7, [pc, #-0x80c]
 *   @0x28d1ec ldr r6, [pc, #-0x80c]
 *   @0x28d1f0 add r3, pc, r3
 *   @0x28d1f4 add r7, pc, r7
 *   @0x28d1f8 str r3, [sp, #0x18]
 *   @0x28d1fc add r6, pc, r6
 *   @0x28d200 ldr r3, [pc, #-0x81c]
 *   @0x28d204 add r3, pc, r3
 *   @0x28d208 str r3, [sp, #0x1c]
 *   @0x28d20c ldr r0, [r4, #0x1c]
 *   @0x28d210 bl 0x285b94 <spEventData_create>
 *   @0x28d214 ldr r1, [sp, #0x18]
 *   @0x28d218 mov r2, #0
 *   @0x28d21c mov r5, r0
 *   @0x28d220 mov r0, r4
 *   @0x28d224 bl 0x287460 <Json_getInt>
 *   @0x28d228 ldr r1, [sp, #0x1c]
 *   @0x28d22c mov r2, #0
 *   @0x28d230 str r0, [r5, #0x4]
 *   @0x28d234 mov r0, r4
 *   @0x28d238 bl 0x287444 <Json_getFloat>
 *   @0x28d23c mov r1, r7
 *   @0x28d240 mov r2, #0
 *   @0x28d244 str r0, [r5, #0x8]
 *   @0x28d248 mov r0, r4
 *   @0x28d24c bl 0x287428 <Json_getString>
 *   @0x28d250 subs r11, r0, #0
 *   @0x28d254 beq 0x28d278 <spSkeletonJson_readSkeletonData+0x1a2c>
 *   @0x28d258 bl 0xb6538 <strlen@plt>
 *   @0x28d25c mov r1, r6
 *   @0x28d260 movw r2, #0x40a
 *   @0x28d264 add r0, r0, #1
 *   @0x28d268 bl 0x285c10 <_malloc>
 *   @0x28d26c mov r1, r11
 *   @0x28d270 str r0, [r5, #0xc]
 *   @0x28d274 bl 0xb65a4 <strcpy@plt>
 *   @0x28d278 ldr r3, [r9, #0x30]
 *   @0x28d27c str r5, [r3, r10]
 *   @0x28d280 add r10, r10, #4
 *   @0x28d284 ldr r4, [r4]
 *   @0x28d288 cmp r4, #0
 *   @0x28d28c bne 0x28d20c <spSkeletonJson_readSkeletonData+0x19c0>
 *   @0x28d290 ldr r1, [pc, #-0x8a8]
 *   @0x28d294 ldr r0, [sp, #0x24]
 *   @0x28d298 add r1, pc, r1
 *   @0x28d29c bl 0x2873c4 <Json_getItem>
 *   @0x28d2a0 subs r4, r0, #0
 *   @0x28d2a4 beq 0x28e7a4 <spSkeletonJson_readSkeletonData+0x2f58>
 *   @0x28d2a8 ldr r0, [r4, #0xc]
 *   @0x28d2ac movw r2, #0x413
 *   @0x28d2b0 ldr r1, [pc, #-0x8c4]
 *   @0x28d2b4 lsl r0, r0, #2
 *   @0x28d2b8 add r1, pc, r1
 *   @0x28d2bc bl 0x285c10 <_malloc>
 *   @0x28d2c0 ldr r4, [r4, #0x4]
 *   @0x28d2c4 cmp r4, #0
 *   @0x28d2c8 str r4, [sp, #0x1c]
 *   @0x28d2cc str r0, [r9, #0x38]
 *   @0x28d2d0 beq 0x28e7a4 <spSkeletonJson_readSkeletonData+0x2f58>
 *   @0x28d2d4 ldr r0, [pc, #-0x8e4]
 *   @0x28d2d8 movw r1, #0x5556
 *   @0x28d2dc ldr r2, [pc, #-0x8e8]
 *   @0x28d2e0 movt r1, #0x5555
 *   @0x28d2e4 add r0, pc, r0
 *   @0x28d2e8 ldr r3, [pc, #-0x8f0]
 *   @0x28d2ec str r0, [sp, #0x64]
 *   @0x28d2f0 add r2, pc, r2
 *   @0x28d2f4 ldr r0, [pc, #-0x8f8]
 *   @0x28d2f8 add r3, pc, r3
 *   @0x28d2fc str r2, [sp, #0x68]
 *   @0x28d300 add r0, pc, r0
 *   @0x28d304 str r1, [sp, #0x60]
 *   @0x28d308 str r3, [sp, #0x6c]
 *   @0x28d30c str r0, [sp, #0x70]
 *   @0x28d310 str r9, [sp, #0x18]
 *   @0x28d314 str r8, [sp, #0x20]
 *   @0x28d318 ldr r1, [sp, #0x64]
 *   @0x28d31c ldr r0, [sp, #0x1c]
 *   @0x28d320 bl 0x2873c4 <Json_getItem>
 *   @0x28d324 ldr r1, [sp, #0x68]
 *   @0x28d328 str r0, [sp, #0x30]
 *   @0x28d32c ldr r0, [sp, #0x1c]
 *   @0x28d330 bl 0x2873c4 <Json_getItem>
 *   @0x28d334 ldr r1, [sp, #0x6c]
 *   @0x28d338 mov r4, r0
 *   @0x28d33c ldr r0, [sp, #0x1c]
 *   @0x28d340 bl 0x2873c4 <Json_getItem>
 *   @0x28d344 ldr r1, [sp, #0x70]
 *   @0x28d348 str r0, [sp, #0x34]
 *   @0x28d34c ldr r0, [sp, #0x1c]
 *   @0x28d350 bl 0x2873c4 <Json_getItem>
 *   @0x28d354 ldr r1, [pc, #-0x954]
 *   @0x28d358 add r1, pc, r1
 *   @0x28d35c str r0, [sp, #0x38]
 *   @0x28d360 ldr r0, [sp, #0x1c]
 *   @0x28d364 bl 0x2873c4 <Json_getItem>
 *   @0x28d368 ldr r1, [pc, #-0x964]
 *   @0x28d36c add r1, pc, r1
 *   @0x28d370 str r0, [sp, #0x44]
 *   @0x28d374 ldr r0, [sp, #0x1c]
 *   @0x28d378 bl 0x2873c4 <Json_getItem>
 *   @0x28d37c ldr r1, [pc, #-0x974]
 *   @0x28d380 add r1, pc, r1
 *   @0x28d384 str r0, [sp, #0x50]
 *   @0x28d388 ldr r0, [sp, #0x1c]
 *   @0x28d38c bl 0x2873c4 <Json_getItem>
 *   @0x28d390 ldr r1, [pc, #-0x984]
 *   @0x28d394 add r1, pc, r1
 *   @0x28d398 str r0, [sp, #0x28]
 *   @0x28d39c ldr r0, [sp, #0x1c]
 *   @0x28d3a0 bl 0x2873c4 <Json_getItem>
 *   @0x28d3a4 ldr r1, [sp, #0x28]
 *   @0x28d3a8 cmp r1, #0
 *   @0x28d3ac str r0, [sp, #0x4c]
 *   @0x28d3b0 beq 0x28eb28 <spSkeletonJson_readSkeletonData+0x32dc>
 *   @0x28d3b4 ldr r2, [sp, #0x30]
 *   @0x28d3b8 cmp r2, #0
 *   @0x28d3bc beq 0x28ea80 <spSkeletonJson_readSkeletonData+0x3234>
 *   @0x28d3c0 ldr r2, [r2, #0x4]
 *   @0x28d3c4 cmp r2, #0
 *   @0x28d3c8 beq 0x28ea40 <spSkeletonJson_readSkeletonData+0x31f4>
 *   @0x28d3cc mov r3, #0
 *   @0x28d3d0 ldr r1, [r2, #0xc]
 *   @0x28d3d4 ldr r2, [r2]
 *   @0x28d3d8 add r3, r3, r1
 *   @0x28d3dc cmp r2, #0
 *   @0x28d3e0 bne 0x28d3d0 <spSkeletonJson_readSkeletonData+0x1b84>
 *   @0x28d3e4 cmp r4, #0
 *   @0x28d3e8 beq 0x28d40c <spSkeletonJson_readSkeletonData+0x1bc0>
 *   @0x28d3ec ldr r2, [r4, #0x4]
 *   @0x28d3f0 cmp r2, #0
 *   @0x28d3f4 beq 0x28d40c <spSkeletonJson_readSkeletonData+0x1bc0>
 *   @0x28d3f8 ldr r1, [r2, #0xc]
 *   @0x28d3fc ldr r2, [r2]
 *   @0x28d400 add r3, r3, r1
 *   @0x28d404 cmp r2, #0
 *   @0x28d408 bne 0x28d3f8 <spSkeletonJson_readSkeletonData+0x1bac>
 *   @0x28d40c ldr r0, [sp, #0x34]
 *   @0x28d410 ldr r1, [sp, #0x38]
 *   @0x28d414 cmp r0, #0
 *   @0x28d418 ldrne r2, [r0, #0xc]
 *   @0x28d41c ldreq r2, [sp, #0x34]
 *   @0x28d420 cmp r1, #0
 *   @0x28d424 ldr r0, [sp, #0x44]
 *   @0x28d428 add r3, r3, r2
 *   @0x28d42c ldrne r2, [r1, #0xc]
 *   @0x28d430 ldreq r2, [sp, #0x38]
 *   @0x28d434 cmp r0, #0
 *   @0x28d438 add r1, r3, r2
 *   @0x28d43c beq 0x28d460 <spSkeletonJson_readSkeletonData+0x1c14>
 *   @0x28d440 ldr r3, [r0, #0x4]
 *   @0x28d444 cmp r3, #0
 *   @0x28d448 beq 0x28d460 <spSkeletonJson_readSkeletonData+0x1c14>
 *   @0x28d44c ldr r2, [r3, #0xc]
 *   @0x28d450 ldr r3, [r3]
 *   @0x28d454 add r1, r1, r2
 *   @0x28d458 cmp r3, #0
 *   @0x28d45c bne 0x28d44c <spSkeletonJson_readSkeletonData+0x1c00>
 *   @0x28d460 ldr r2, [sp, #0x50]
 *   @0x28d464 cmp r2, #0
 *   @0x28d468 beq 0x28d4a4 <spSkeletonJson_readSkeletonData+0x1c58>
 *   @0x28d46c ldr r0, [r2, #0x4]
 *   @0x28d470 cmp r0, #0
 *   @0x28d474 beq 0x28d4a4 <spSkeletonJson_readSkeletonData+0x1c58>
 *   @0x28d478 ldr r3, [r0, #0x4]
 *   @0x28d47c cmp r3, #0
 *   @0x28d480 beq 0x28d498 <spSkeletonJson_readSkeletonData+0x1c4c>
 *   @0x28d484 ldr r2, [r3, #0xc]
 *   @0x28d488 ldr r3, [r3]
 *   @0x28d48c add r1, r1, r2
 *   @0x28d490 cmp r3, #0
 *   @0x28d494 bne 0x28d484 <spSkeletonJson_readSkeletonData+0x1c38>
 *   @0x28d498 ldr r0, [r0]
 *   @0x28d49c cmp r0, #0
 *   @0x28d4a0 bne 0x28d478 <spSkeletonJson_readSkeletonData+0x1c2c>
 *   @0x28d4a4 ldr r3, [sp, #0x28]
 *   @0x28d4a8 ldr r0, [sp, #0x4c]
 *   @0x28d4ac ldr r2, [sp, #0x1c]
 *   @0x28d4b0 cmp r3, #0
 *   @0x28d4b4 addne r1, r1, #1
 *   @0x28d4b8 cmp r0, #0
 *   @0x28d4bc addne r1, r1, #1
 *   @0x28d4c0 ldr r0, [r2, #0x1c]
 *   @0x28d4c4 bl 0x2812b4 <spAnimation_create>
 *   @0x28d4c8 cmp r4, #0
 *   @0x28d4cc mov r3, #0
 *   @0x28d4d0 mov r11, r0
 *   @0x28d4d4 str r3, [r0, #0x8]
 *   @0x28d4d8 beq 0x28d640 <spSkeletonJson_readSkeletonData+0x1df4>
 *   @0x28d4dc ldr r4, [r4, #0x4]
 *   @0x28d4e0 cmp r4, #0
 *   @0x28d4e4 str r4, [sp, #0x2c]
 *   @0x28d4e8 beq 0x28d640 <spSkeletonJson_readSkeletonData+0x1df4>
 *   @0x28d4ec ldr r7, [pc, #-0xadc]
 *   @0x28d4f0 ldr r6, [pc, #-0xadc]
 *   @0x28d4f4 ldr r0, [pc, #-0xadc]
 *   @0x28d4f8 add r7, pc, r7
 *   @0x28d4fc ldr r1, [pc, #-0xae0]
 *   @0x28d500 add r6, pc, r6
 *   @0x28d504 ldr r2, [pc, #-0xae4]
 *   @0x28d508 add r0, pc, r0
 *   @0x28d50c add r1, pc, r1
 *   @0x28d510 str r0, [sp, #0x40]
 *   @0x28d514 add r2, pc, r2
 *   @0x28d518 str r1, [sp, #0x48]
 *   @0x28d51c str r2, [sp, #0x54]
 *   @0x28d520 ldr r3, [sp, #0x2c]
 *   @0x28d524 ldr r0, [sp, #0x18]
 *   @0x28d528 ldr r1, [r3, #0x1c]
 *   @0x28d52c bl 0x28b0cc <spSkeletonData_findSlotIndex>
 *   @0x28d530 cmn r0, #1
 *   @0x28d534 str r0, [sp, #0x3c]
 *   @0x28d538 beq 0x28ea10 <spSkeletonJson_readSkeletonData+0x31c4>
 *   @0x28d53c ldr r3, [sp, #0x2c]
 *   @0x28d540 ldr r9, [r3, #0x4]
 *   @0x28d544 cmp r9, #0
 *   @0x28d548 beq 0x28d62c <spSkeletonJson_readSkeletonData+0x1de0>
 *   @0x28d54c ldr r4, [r9, #0x1c]
 *   @0x28d550 ldr r1, [sp, #0x40]
 *   @0x28d554 mov r0, r4
 *   @0x28d558 bl 0xb6574 <strcmp@plt>
 *   @0x28d55c subs r5, r0, #0
 *   @0x28d560 beq 0x28d8dc <spSkeletonJson_readSkeletonData+0x2090>
 *   @0x28d564 mov r0, r4
 *   @0x28d568 ldr r1, [sp, #0x48]
 *   @0x28d56c bl 0xb6574 <strcmp@plt>
 *   @0x28d570 subs r5, r0, #0
 *   @0x28d574 bne 0x28da18 <spSkeletonJson_readSkeletonData+0x21cc>
 *   @0x28d578 ldr r0, [r9, #0xc]
 *   @0x28d57c bl 0x282b94 <spAttachmentTimeline_create>
 *   @0x28d580 ldr r4, [r9, #0x4]
 *   @0x28d584 ldr r2, [sp, #0x3c]
 *   @0x28d588 cmp r4, #0
 *   @0x28d58c mov r8, r0
 *   @0x28d590 str r2, [r0, #0x10]
 *   @0x28d594 beq 0x28d5e8 <spSkeletonJson_readSkeletonData+0x1d9c>
 *   @0x28d598 mov r0, r4
 *   @0x28d59c mov r1, r7
 *   @0x28d5a0 bl 0x2873c4 <Json_getItem>
 *   @0x28d5a4 mov r1, r6
 *   @0x28d5a8 mov r2, #0
 *   @0x28d5ac mov r10, r0
 *   @0x28d5b0 mov r0, r4
 *   @0x28d5b4 bl 0x287444 <Json_getFloat>
 *   @0x28d5b8 ldr r3, [r10, #0x8]
 *   @0x28d5bc mov r1, r5
 *   @0x28d5c0 add r5, r5, #1
 *   @0x28d5c4 cmp r3, #2
 *   @0x28d5c8 ldrne r3, [r10, #0x10]
 *   @0x28d5cc moveq r3, #0
 *   @0x28d5d0 mov r2, r0
 *   @0x28d5d4 mov r0, r8
 *   @0x28d5d8 bl 0x282c1c <spAttachmentTimeline_setFrame>
 *   @0x28d5dc ldr r4, [r4]
 *   @0x28d5e0 cmp r4, #0
 *   @0x28d5e4 bne 0x28d598 <spSkeletonJson_readSkeletonData+0x1d4c>
 *   @0x28d5e8 ldr r3, [r11, #0x8]
 *   @0x28d5ec vldr s14, [r11, #4]
 *   @0x28d5f0 ldr r1, [r11, #0xc]
 *   @0x28d5f4 add r2, r3, #1
 *   @0x28d5f8 str r2, [r11, #0x8]
 *   @0x28d5fc ldr r2, [r9, #0xc]
 *   @0x28d600 str r8, [r1, r3, lsl #2]
 *   @0x28d604 ldr r3, [r8, #0xc]
 *   @0x28d608 add r3, r3, r2, lsl #2
 *   @0x28d60c vldr s15, [r3, #-4]
 *   @0x28d610 vcmpe.f32 s14, s15
 *   @0x28d614 vmrs APSR_nzcv, fpscr
 *   @0x28d618 vmovgt.f32 s15, s14
 *   @0x28d61c vstr s15, [r11, #4]
 *   @0x28d620 ldr r9, [r9]
 *   @0x28d624 cmp r9, #0
 *   @0x28d628 bne 0x28d54c <spSkeletonJson_readSkeletonData+0x1d00>
 *   @0x28d62c ldr r0, [sp, #0x2c]
 *   @0x28d630 ldr r0, [r0]
 *   @0x28d634 cmp r0, #0
 *   @0x28d638 str r0, [sp, #0x2c]
 *   @0x28d63c bne 0x28d520 <spSkeletonJson_readSkeletonData+0x1cd4>
 *   @0x28d640 ldr r3, [sp, #0x30]
 *   @0x28d644 cmp r3, #0
 *   @0x28d648 beq 0x28d840 <spSkeletonJson_readSkeletonData+0x1ff4>
 *   @0x28d64c ldr r0, [sp, #0x30]
 *   @0x28d650 ldr r6, [r0, #0x4]
 *   @0x28d654 cmp r6, #0
 *   @0x28d658 beq 0x28d840 <spSkeletonJson_readSkeletonData+0x1ff4>
 *   @0x28d65c ldr r1, [pc, #-0xc38]
 *   @0x28d660 ldr r2, [pc, #-0xc38]
 *   @0x28d664 add r1, pc, r1
 *   @0x28d668 ldr r3, [pc, #-0xc3c]
 *   @0x28d66c str r1, [sp, #0x3c]
 *   @0x28d670 add r2, pc, r2
 *   @0x28d674 ldr r0, [pc, #-0xc44]
 *   @0x28d678 add r3, pc, r3
 *   @0x28d67c ldr r1, [pc, #-0xc48]
 *   @0x28d680 add r0, pc, r0
 *   @0x28d684 str r2, [sp, #0x40]
 *   @0x28d688 add r1, pc, r1
 *   @0x28d68c str r3, [sp, #0x48]
 *   @0x28d690 str r0, [sp, #0x54]
 *   @0x28d694 str r1, [sp, #0x30]
 *   @0x28d698 ldr r0, [sp, #0x18]
 *   @0x28d69c ldr r1, [r6, #0x1c]
 *   @0x28d6a0 bl 0x28b018 <spSkeletonData_findBoneIndex>
 *   @0x28d6a4 cmn r0, #1
 *   @0x28d6a8 mov r8, r0
 *   @0x28d6ac beq 0x28db5c <spSkeletonJson_readSkeletonData+0x2310>
 *   @0x28d6b0 ldr r7, [r6, #0x4]
 *   @0x28d6b4 cmp r7, #0
 *   @0x28d6b8 strne r6, [sp, #0x58]
 *   @0x28d6bc beq 0x28d834 <spSkeletonJson_readSkeletonData+0x1fe8>
 *   @0x28d6c0 ldr r4, [r7, #0x1c]
 *   @0x28d6c4 ldr r1, [sp, #0x3c]
 *   @0x28d6c8 mov r0, r4
 *   @0x28d6cc bl 0xb6574 <strcmp@plt>
 *   @0x28d6d0 subs r9, r0, #0
 *   @0x28d6d4 beq 0x28da74 <spSkeletonJson_readSkeletonData+0x2228>
 *   @0x28d6d8 mov r0, r4
 *   @0x28d6dc ldr r1, [sp, #0x40]
 *   @0x28d6e0 bl 0xb6574 <strcmp@plt>
 *   @0x28d6e4 ldr r1, [sp, #0x48]
 *   @0x28d6e8 rsbs r5, r0, #1
 *   @0x28d6ec mov r0, r4
 *   @0x28d6f0 movlo r5, #0
 *   @0x28d6f4 bl 0xb6574 <strcmp@plt>
 *   @0x28d6f8 ldr r1, [sp, #0x54]
 *   @0x28d6fc rsbs r9, r0, #1
 *   @0x28d700 mov r0, r4
 *   @0x28d704 movlo r9, #0
 *   @0x28d708 bl 0xb6574 <strcmp@plt>
 *   @0x28d70c orr r4, r9, r5
 *   @0x28d710 rsbs r0, r0, #1
 *   @0x28d714 movlo r0, #0
 *   @0x28d718 orrs r4, r0, r4
 *   @0x28d71c beq 0x28db88 <spSkeletonJson_readSkeletonData+0x233c>
 *   @0x28d720 cmp r9, #0
 *   @0x28d724 bne 0x28da54 <spSkeletonJson_readSkeletonData+0x2208>
 *   @0x28d728 cmp r5, #0
 *   @0x28d72c bne 0x28db48 <spSkeletonJson_readSkeletonData+0x22fc>
 *   @0x28d730 cmp r0, #0
 *   @0x28d734 vmoveq.f32 s16, #1.000000e+00
 *   @0x28d738 moveq r4, r0
 *   @0x28d73c bne 0x28dbb4 <spSkeletonJson_readSkeletonData+0x2368>
 *   @0x28d740 ldr r6, [r7, #0x4]
 *   @0x28d744 str r8, [r4, #0x14]
 *   @0x28d748 cmp r6, #0
 *   @0x28d74c beq 0x28d7e4 <spSkeletonJson_readSkeletonData+0x1f98>
 *   @0x28d750 ldr r10, [pc, #-0xd18]
 *   @0x28d754 mov r5, #0
 *   @0x28d758 ldr r3, [pc, #-0xd1c]
 *   @0x28d75c add r10, pc, r10
 *   @0x28d760 add r3, pc, r3
 *   @0x28d764 str r3, [sp, #0x2c]
 *   @0x28d768 mov r0, r6
 *   @0x28d76c ldr r1, [sp, #0x30]
 *   @0x28d770 mov r2, #0
 *   @0x28d774 bl 0x287444 <Json_getFloat>
 *   @0x28d778 mov r1, r10
 *   @0x28d77c mov r2, #0
 *   @0x28d780 mov r9, r0
 *   @0x28d784 mov r0, r6
 *   @0x28d788 bl 0x287444 <Json_getFloat>
 *   @0x28d78c ldr r1, [sp, #0x2c]
 *   @0x28d790 mov r2, #0
 *   @0x28d794 vmov s14, r0
 *   @0x28d798 mov r0, r6
 *   @0x28d79c vmul.f32 s17, s14, s16
 *   @0x28d7a0 bl 0x287444 <Json_getFloat>
 *   @0x28d7a4 mov r1, r5
 *   @0x28d7a8 mov r2, r9
 *   @0x28d7ac vmov r3, s17
 *   @0x28d7b0 vmov s14, r0
 *   @0x28d7b4 mov r0, r4
 *   @0x28d7b8 vmul.f32 s15, s16, s14
 *   @0x28d7bc vstr s15, [sp]
 *   @0x28d7c0 bl 0x282ad4 <spTranslateTimeline_setFrame>
 *   @0x28d7c4 mov r0, r6
 *   @0x28d7c8 mov r2, r5
 *   @0x28d7cc mov r1, r4
 *   @0x28d7d0 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c>
 *   @0x28d7d4 ldr r6, [r6]
 *   @0x28d7d8 add r5, r5, #1
 *   @0x28d7dc cmp r6, #0
 *   @0x28d7e0 bne 0x28d768 <spSkeletonJson_readSkeletonData+0x1f1c>
 *   @0x28d7e4 ldr r2, [r7, #0xc]
 *   @0x28d7e8 vldr s14, [r11, #4]
 *   @0x28d7ec ldr r3, [r11, #0x8]
 *   @0x28d7f0 ldr r1, [r11, #0xc]
 *   @0x28d7f4 sub r2, r2, #1
 *   @0x28d7f8 add r0, r3, #1
 *   @0x28d7fc str r0, [r11, #0x8]
 *   @0x28d800 add r2, r2, r2, lsl #1
 *   @0x28d804 str r4, [r1, r3, lsl #2]
 *   @0x28d808 ldr r3, [r4, #0x10]
 *   @0x28d80c add r3, r3, r2, lsl #2
 *   @0x28d810 vldr s15, [r3]
 *   @0x28d814 vcmpe.f32 s14, s15
 *   @0x28d818 vmrs APSR_nzcv, fpscr
 *   @0x28d81c vmovgt.f32 s15, s14
 *   @0x28d820 vstr s15, [r11, #4]
 *   @0x28d824 ldr r7, [r7]
 *   @0x28d828 cmp r7, #0
 *   @0x28d82c bne 0x28d6c0 <spSkeletonJson_readSkeletonData+0x1e74>
 *   @0x28d830 ldr r6, [sp, #0x58]
 *   @0x28d834 ldr r6, [r6]
 *   @0x28d838 cmp r6, #0
 *   @0x28d83c bne 0x28d698 <spSkeletonJson_readSkeletonData+0x1e4c>
 *   @0x28d840 ldr r3, [sp, #0x34]
 *   @0x28d844 cmp r3, #0
 *   @0x28d848 beq 0x28dca8 <spSkeletonJson_readSkeletonData+0x245c>
 *   @0x28d84c ldr r1, [sp, #0x34]
 *   @0x28d850 ldr r4, [r1, #0x4]
 *   @0x28d854 cmp r4, #0
 *   @0x28d858 beq 0x28dca8 <spSkeletonJson_readSkeletonData+0x245c>
 *   @0x28d85c ldr r10, [pc, #-0xe1c]
 *   @0x28d860 ldr r2, [pc, #-0xe1c]
 *   @0x28d864 ldr r3, [pc, #-0xe1c]
 *   @0x28d868 add r10, pc, r10
 *   @0x28d86c add r2, pc, r2
 *   @0x28d870 str r2, [sp, #0x2c]
 *   @0x28d874 add r3, pc, r3
 *   @0x28d878 str r3, [sp, #0x30]
 *   @0x28d87c ldr r1, [r4, #0x1c]
 *   @0x28d880 ldr r0, [sp, #0x18]
 *   @0x28d884 bl 0x28b238 <spSkeletonData_findIkConstraint>
 *   @0x28d888 mov r5, r0
 *   @0x28d88c ldr r0, [r4, #0xc]
 *   @0x28d890 bl 0x282f74 <spIkConstraintTimeline_create>
 *   @0x28d894 mov r6, r0
 *   @0x28d898 ldr r0, [sp, #0x18]
 *   @0x28d89c ldr r1, [r0, #0x3c]
 *   @0x28d8a0 cmp r1, #0
 *   @0x28d8a4 ble 0x28dbd0 <spSkeletonJson_readSkeletonData+0x2384>
 *   @0x28d8a8 ldr r2, [r0, #0x40]
 *   @0x28d8ac ldr r3, [r2]
 *   @0x28d8b0 cmp r5, r3
 *   @0x28d8b4 movne r3, #0
 *   @0x28d8b8 bne 0x28d8cc <spSkeletonJson_readSkeletonData+0x2080>
 *   @0x28d8bc b 0x28dbc8 <spSkeletonJson_readSkeletonData+0x237c>
 *   @0x28d8c0 ldr r0, [r2, #0x4]!
 *   @0x28d8c4 cmp r5, r0
 *   @0x28d8c8 beq 0x28dbcc <spSkeletonJson_readSkeletonData+0x2380>
 *   @0x28d8cc add r3, r3, #1
 *   @0x28d8d0 cmp r3, r1
 *   @0x28d8d4 bne 0x28d8c0 <spSkeletonJson_readSkeletonData+0x2074>
 *   @0x28d8d8 b 0x28dbd0 <spSkeletonJson_readSkeletonData+0x2384>
 *   @0x28d8dc ldr r0, [r9, #0xc]
 *   @0x28d8e0 bl 0x282b3c <spColorTimeline_create>
 *   @0x28d8e4 ldr r10, [r9, #0x4]
 *   @0x28d8e8 ldr r1, [sp, #0x3c]
 *   @0x28d8ec cmp r10, #0
 *   @0x28d8f0 mov r8, r0
 *   @0x28d8f4 str r1, [r0, #0x14]
 *   @0x28d8f8 beq 0x28d9d4 <spSkeletonJson_readSkeletonData+0x2188>
 *   @0x28d8fc ldr r12, [pc, #-0xeb0]
 *   @0x28d900 str r7, [sp, #0x74]
 *   @0x28d904 mov r7, r10
 *   @0x28d908 add r12, pc, r12
 *   @0x28d90c mov r10, r6
 *   @0x28d910 ldr r6, [sp, #0x54]
 *   @0x28d914 str r11, [sp, #0x58]
 *   @0x28d918 mov r11, r12
 *   @0x28d91c str r9, [sp, #0x5c]
 *   @0x28d920 mov r0, r7
 *   @0x28d924 mov r1, r6
 *   @0x28d928 mov r2, #0
 *   @0x28d92c bl 0x287428 <Json_getString>
 *   @0x28d930 mov r2, #0
 *   @0x28d934 mov r1, r11
 *   @0x28d938 mov r4, r0
 *   @0x28d93c mov r0, r7
 *   @0x28d940 bl 0x287444 <Json_getFloat>
 *   @0x28d944 mov r1, #0
 *   @0x28d948 mov r9, r0
 *   @0x28d94c mov r0, r4
 *   @0x28d950 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28d954 mov r0, r4
 *   @0x28d958 mov r1, #1
 *   @0x28d95c vstr s0, [sp, #16]
 *   @0x28d960 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28d964 mov r0, r4
 *   @0x28d968 mov r1, #2
 *   @0x28d96c vmov.f32 s17, s0
 *   @0x28d970 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28d974 mov r0, r4
 *   @0x28d978 mov r1, #3
 *   @0x28d97c vmov.f32 s16, s0
 *   @0x28d980 bl 0x28b680 <spSkeletonData_findPathConstraint+0x390>
 *   @0x28d984 mov r1, r5
 *   @0x28d988 mov r2, r9
 *   @0x28d98c mov r0, r8
 *   @0x28d990 ldr r3, [sp, #0x10]
 *   @0x28d994 vstr s17, [sp]
 *   @0x28d998 vstr s16, [sp, #4]
 *   @0x28d99c vstr s0, [sp, #8]
 *   @0x28d9a0 bl 0x282b54 <spColorTimeline_setFrame>
 *   @0x28d9a4 mov r0, r7
 *   @0x28d9a8 mov r2, r5
 *   @0x28d9ac mov r1, r8
 *   @0x28d9b0 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c>
 *   @0x28d9b4 ldr r7, [r7]
 *   @0x28d9b8 add r5, r5, #1
 *   @0x28d9bc cmp r7, #0
 *   @0x28d9c0 bne 0x28d920 <spSkeletonJson_readSkeletonData+0x20d4>
 *   @0x28d9c4 ldr r11, [sp, #0x58]
 *   @0x28d9c8 mov r6, r10
 *   @0x28d9cc ldr r9, [sp, #0x5c]
 *   @0x28d9d0 ldr r7, [sp, #0x74]
 *   @0x28d9d4 ldr r2, [r9, #0xc]
 *   @0x28d9d8 vldr s14, [r11, #4]
 *   @0x28d9dc ldr r3, [r11, #0x8]
 *   @0x28d9e0 ldr r1, [r11, #0xc]
 *   @0x28d9e4 sub r2, r2, #1
 *   @0x28d9e8 add r0, r3, #1
 *   @0x28d9ec str r0, [r11, #0x8]
 *   @0x28d9f0 add r2, r2, r2, lsl #2
 *   @0x28d9f4 str r8, [r1, r3, lsl #2]
 *   @0x28d9f8 ldr r3, [r8, #0x10]
 *   @0x28d9fc add r3, r3, r2, lsl #2
 *   @0x28da00 vldr s15, [r3]
 *   @0x28da04 vcmpe.f32 s14, s15
 *   @0x28da08 vmrs APSR_nzcv, fpscr
 *   @0x28da0c vmovgt.f32 s15, s14
 *   @0x28da10 vstr s15, [r11, #4]
 *   @0x28da14 b 0x28d620 <spSkeletonJson_readSkeletonData+0x1dd4>
 *   @0x28da18 ldr r8, [sp, #0x20]
 *   @0x28da1c mov r0, r11
 *   @0x28da20 mov r4, r9
 *   @0x28da24 ldr r9, [sp, #0x18]
 *   @0x28da28 bl 0x28147c <spAnimation_dispose>
 *   @0x28da2c ldr r2, [pc, #-0xfdc]
 *   @0x28da30 mov r0, r8
 *   @0x28da34 ldr r3, [r4, #0x1c]
 *   @0x28da38 mov r1, #0
 *   @0x28da3c add r2, pc, r2
 *   @0x28da40 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28da44 mov r0, r9
 *   @0x28da48 bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28da4c mov r0, #0
 *   @0x28da50 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580>
 *   @0x28da54 cmp r5, #0
 *   @0x28da58 ldr r2, [sp, #0x20]
 *   @0x28da5c vldr s16, [r2]
 *   @0x28da60 bne 0x28db4c <spSkeletonJson_readSkeletonData+0x2300>
 *   @0x28da64 ldr r0, [r7, #0xc]
 *   @0x28da68 bl 0x282abc <spTranslateTimeline_create>
 *   @0x28da6c mov r4, r0
 *   @0x28da70 b 0x28d740 <spSkeletonJson_readSkeletonData+0x1ef4>
 *   @0x28da74 ldr r0, [r7, #0xc]
 *   @0x28da78 bl 0x282a90 <spRotateTimeline_create>
 *   @0x28da7c ldr r4, [r7, #0x4]
 *   @0x28da80 cmp r4, #0
 *   @0x28da84 mov r5, r0
 *   @0x28da88 str r8, [r0, #0x14]
 *   @0x28da8c beq 0x28db0c <spSkeletonJson_readSkeletonData+0x22c0>
 *   @0x28da90 ldr r6, [pc, #0xff0]
 *   @0x28da94 mov r12, r7
 *   @0x28da98 ldr r10, [pc, #0xfec]
 *   @0x28da9c add r6, pc, r6
 *   @0x28daa0 add r10, pc, r10
 *   @0x28daa4 mov r7, r6
 *   @0x28daa8 mov r0, r4
 *   @0x28daac mov r1, r7
 *   @0x28dab0 mov r2, #0
 *   @0x28dab4 str r12, [sp, #0x14]
 *   @0x28dab8 bl 0x287444 <Json_getFloat>
 *   @0x28dabc mov r1, r10
 *   @0x28dac0 mov r2, #0
 *   @0x28dac4 mov r6, r0
 *   @0x28dac8 mov r0, r4
 *   @0x28dacc bl 0x287444 <Json_getFloat>
 *   @0x28dad0 mov r1, r9
 *   @0x28dad4 mov r2, r6
 *   @0x28dad8 mov r3, r0
 *   @0x28dadc mov r0, r5
 *   @0x28dae0 bl 0x282aa8 <spRotateTimeline_setFrame>
 *   @0x28dae4 mov r0, r4
 *   @0x28dae8 mov r2, r9
 *   @0x28daec mov r1, r5
 *   @0x28daf0 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c>
 *   @0x28daf4 ldr r4, [r4]
 *   @0x28daf8 add r9, r9, #1
 *   @0x28dafc ldr r12, [sp, #0x14]
 *   @0x28db00 cmp r4, #0
 *   @0x28db04 bne 0x28daa8 <spSkeletonJson_readSkeletonData+0x225c>
 *   @0x28db08 mov r7, r12
 *   @0x28db0c ldr r3, [r11, #0x8]
 *   @0x28db10 vldr s14, [r11, #4]
 *   @0x28db14 ldr r1, [r11, #0xc]
 *   @0x28db18 add r2, r3, #1
 *   @0x28db1c str r2, [r11, #0x8]
 *   @0x28db20 ldr r2, [r7, #0xc]
 *   @0x28db24 str r5, [r1, r3, lsl #2]
 *   @0x28db28 ldr r3, [r5, #0x10]
 *   @0x28db2c add r3, r3, r2, lsl #3
 *   @0x28db30 vldr s15, [r3, #-8]
 *   @0x28db34 vcmpe.f32 s14, s15
 *   @0x28db38 vmrs APSR_nzcv, fpscr
 *   @0x28db3c vmovgt.f32 s15, s14
 *   @0x28db40 vstr s15, [r11, #4]
 *   @0x28db44 b 0x28d824 <spSkeletonJson_readSkeletonData+0x1fd8>
 *   @0x28db48 vmov.f32 s16, #1.000000e+00
 *   @0x28db4c ldr r0, [r7, #0xc]
 *   @0x28db50 bl 0x282b04 <spScaleTimeline_create>
 *   @0x28db54 mov r4, r0
 *   @0x28db58 b 0x28d740 <spSkeletonJson_readSkeletonData+0x1ef4>
 *   @0x28db5c ldr r8, [sp, #0x20]
 *   @0x28db60 mov r0, r11
 *   @0x28db64 ldr r9, [sp, #0x18]
 *   @0x28db68 bl 0x28147c <spAnimation_dispose>
 *   @0x28db6c ldr r2, [pc, #0xf1c]
 *   @0x28db70 mov r0, r8
 *   @0x28db74 ldr r1, [sp, #0x1c]
 *   @0x28db78 ldr r3, [r6, #0x1c]
 *   @0x28db7c add r2, pc, r2
 *   @0x28db80 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28db84 b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8>
 *   @0x28db88 ldr r8, [sp, #0x20]
 *   @0x28db8c mov r0, r11
 *   @0x28db90 ldr r9, [sp, #0x18]
 *   @0x28db94 bl 0x28147c <spAnimation_dispose>
 *   @0x28db98 ldr r2, [pc, #0xef4]
 *   @0x28db9c mov r1, r4
 *   @0x28dba0 mov r0, r8
 *   @0x28dba4 ldr r3, [r7, #0x1c]
 *   @0x28dba8 add r2, pc, r2
 *   @0x28dbac bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28dbb0 b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8>
 *   @0x28dbb4 ldr r0, [r7, #0xc]
 *   @0x28dbb8 vmov.f32 s16, #1.000000e+00
 *   @0x28dbbc bl 0x282b20 <spShearTimeline_create>
 *   @0x28dbc0 mov r4, r0
 *   @0x28dbc4 b 0x28d740 <spSkeletonJson_readSkeletonData+0x1ef4>
 *   @0x28dbc8 mov r3, #0
 *   @0x28dbcc str r3, [r6, #0x14]
 *   @0x28dbd0 ldr r5, [r4, #0x4]
 *   @0x28dbd4 cmp r5, #0
 *   @0x28dbd8 movne r7, #0
 *   @0x28dbdc beq 0x28dc5c <spSkeletonJson_readSkeletonData+0x2410>
 *   @0x28dbe0 mov r0, r5
 *   @0x28dbe4 mov r1, r10
 *   @0x28dbe8 mov r2, #0
 *   @0x28dbec bl 0x287444 <Json_getFloat>
 *   @0x28dbf0 ldr r1, [sp, #0x2c]
 *   @0x28dbf4 mov r2, #1065353216
 *   @0x28dbf8 mov r9, r0
 *   @0x28dbfc mov r0, r5
 *   @0x28dc00 bl 0x287444 <Json_getFloat>
 *   @0x28dc04 ldr r1, [sp, #0x30]
 *   @0x28dc08 mov r2, #1
 *   @0x28dc0c mov r8, r0
 *   @0x28dc10 mov r0, r5
 *   @0x28dc14 bl 0x287460 <Json_getInt>
 *   @0x28dc18 mov r1, r7
 *   @0x28dc1c mov r2, r9
 *   @0x28dc20 mov r3, r8
 *   @0x28dc24 cmp r0, #0
 *   @0x28dc28 mov r0, r6
 *   @0x28dc2c mvneq r12, #0
 *   @0x28dc30 movne r12, #1
 *   @0x28dc34 str r12, [sp]
 *   @0x28dc38 bl 0x282f8c <spIkConstraintTimeline_setFrame>
 *   @0x28dc3c mov r0, r5
 *   @0x28dc40 mov r2, r7
 *   @0x28dc44 mov r1, r6
 *   @0x28dc48 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c>
 *   @0x28dc4c ldr r5, [r5]
 *   @0x28dc50 add r7, r7, #1
 *   @0x28dc54 cmp r5, #0
 *   @0x28dc58 bne 0x28dbe0 <spSkeletonJson_readSkeletonData+0x2394>
 *   @0x28dc5c ldr r2, [r4, #0xc]
 *   @0x28dc60 vldr s14, [r11, #4]
 *   @0x28dc64 ldr r3, [r11, #0x8]
 *   @0x28dc68 ldr r1, [r11, #0xc]
 *   @0x28dc6c sub r2, r2, #1
 *   @0x28dc70 add r0, r3, #1
 *   @0x28dc74 str r0, [r11, #0x8]
 *   @0x28dc78 add r2, r2, r2, lsl #1
 *   @0x28dc7c str r6, [r1, r3, lsl #2]
 *   @0x28dc80 ldr r3, [r6, #0x10]
 *   @0x28dc84 ldr r4, [r4]
 *   @0x28dc88 add r3, r3, r2, lsl #2
 *   @0x28dc8c vldr s15, [r3]
 *   @0x28dc90 vcmpe.f32 s14, s15
 *   @0x28dc94 vmrs APSR_nzcv, fpscr
 *   @0x28dc98 vmovgt.f32 s15, s14
 *   @0x28dc9c cmp r4, #0
 *   @0x28dca0 vstr s15, [r11, #4]
 *   @0x28dca4 bne 0x28d87c <spSkeletonJson_readSkeletonData+0x2030>
 *   @0x28dca8 ldr r0, [sp, #0x38]
 *   @0x28dcac cmp r0, #0
 *   @0x28dcb0 beq 0x28de74 <spSkeletonJson_readSkeletonData+0x2628>
 *   @0x28dcb4 ldr r2, [sp, #0x38]
 *   @0x28dcb8 ldr r5, [r2, #0x4]
 *   @0x28dcbc cmp r5, #0
 *   @0x28dcc0 beq 0x28de74 <spSkeletonJson_readSkeletonData+0x2628>
 *   @0x28dcc4 ldr r3, [pc, #0xdcc]
 *   @0x28dcc8 ldr r0, [pc, #0xdcc]
 *   @0x28dccc add r3, pc, r3
 *   @0x28dcd0 ldr r1, [pc, #0xdc8]
 *   @0x28dcd4 str r3, [sp, #0x2c]
 *   @0x28dcd8 add r0, pc, r0
 *   @0x28dcdc ldr r2, [pc, #0xdc0]
 *   @0x28dce0 add r1, pc, r1
 *   @0x28dce4 ldr r3, [pc, #0xdbc]
 *   @0x28dce8 add r2, pc, r2
 *   @0x28dcec str r0, [sp, #0x30]
 *   @0x28dcf0 add r3, pc, r3
 *   @0x28dcf4 str r1, [sp, #0x34]
 *   @0x28dcf8 str r2, [sp, #0x38]
 *   @0x28dcfc str r3, [sp, #0x3c]
 *   @0x28dd00 ldr r1, [r5, #0x1c]
 *   @0x28dd04 ldr r0, [sp, #0x18]
 *   @0x28dd08 bl 0x28b294 <spSkeletonData_findTransformConstraint>
 *   @0x28dd0c mov r4, r0
 *   @0x28dd10 ldr r0, [r5, #0xc]
 *   @0x28dd14 bl 0x282fb8 <spTransformConstraintTimeline_create>
 *   @0x28dd18 mov r6, r0
 *   @0x28dd1c ldr r0, [sp, #0x18]
 *   @0x28dd20 ldr r1, [r0, #0x44]
 *   @0x28dd24 cmp r1, #0
 *   @0x28dd28 ble 0x28dd68 <spSkeletonJson_readSkeletonData+0x251c>
 *   @0x28dd2c ldr r2, [r0, #0x48]
 *   @0x28dd30 ldr r3, [r2]
 *   @0x28dd34 cmp r4, r3
 *   @0x28dd38 movne r3, #0
 *   @0x28dd3c bne 0x28dd50 <spSkeletonJson_readSkeletonData+0x2504>
 *   @0x28dd40 b 0x28dd60 <spSkeletonJson_readSkeletonData+0x2514>
 *   @0x28dd44 ldr r0, [r2, #0x4]!
 *   @0x28dd48 cmp r4, r0
 *   @0x28dd4c beq 0x28dd64 <spSkeletonJson_readSkeletonData+0x2518>
 *   @0x28dd50 add r3, r3, #1
 *   @0x28dd54 cmp r3, r1
 *   @0x28dd58 bne 0x28dd44 <spSkeletonJson_readSkeletonData+0x24f8>
 *   @0x28dd5c b 0x28dd68 <spSkeletonJson_readSkeletonData+0x251c>
 *   @0x28dd60 mov r3, #0
 *   @0x28dd64 str r3, [r6, #0x14]
 *   @0x28dd68 ldr r4, [r5, #0x4]
 *   @0x28dd6c cmp r4, #0
 *   @0x28dd70 movne r7, #0
 *   @0x28dd74 movne r12, r5
 *   @0x28dd78 beq 0x28de28 <spSkeletonJson_readSkeletonData+0x25dc>
 *   @0x28dd7c mov r0, r4
 *   @0x28dd80 ldr r1, [sp, #0x2c]
 *   @0x28dd84 mov r2, #0
 *   @0x28dd88 str r12, [sp, #0x14]
 *   @0x28dd8c bl 0x287444 <Json_getFloat>
 *   @0x28dd90 ldr r1, [sp, #0x30]
 *   @0x28dd94 mov r2, #1065353216
 *   @0x28dd98 mov r9, r0
 *   @0x28dd9c mov r0, r4
 *   @0x28dda0 bl 0x287444 <Json_getFloat>
 *   @0x28dda4 ldr r1, [sp, #0x34]
 *   @0x28dda8 mov r2, #1065353216
 *   @0x28ddac mov r8, r0
 *   @0x28ddb0 mov r0, r4
 *   @0x28ddb4 bl 0x287444 <Json_getFloat>
 *   @0x28ddb8 ldr r1, [sp, #0x38]
 *   @0x28ddbc mov r2, #1065353216
 *   @0x28ddc0 mov r5, r0
 *   @0x28ddc4 mov r0, r4
 *   @0x28ddc8 bl 0x287444 <Json_getFloat>
 *   @0x28ddcc ldr r1, [sp, #0x3c]
 *   @0x28ddd0 mov r2, #1065353216
 *   @0x28ddd4 mov r10, r0
 *   @0x28ddd8 mov r0, r4
 *   @0x28dddc bl 0x287444 <Json_getFloat>
 *   @0x28dde0 mov r1, r7
 *   @0x28dde4 mov r2, r9
 *   @0x28dde8 mov r3, r8
 *   @0x28ddec str r5, [sp]
 *   @0x28ddf0 str r10, [sp, #0x4]
 *   @0x28ddf4 str r0, [sp, #0x8]
 *   @0x28ddf8 mov r0, r6
 *   @0x28ddfc bl 0x282fd0 <spTransformConstraintTimeline_setFrame>
 *   @0x28de00 mov r0, r4
 *   @0x28de04 mov r2, r7
 *   @0x28de08 mov r1, r6
 *   @0x28de0c bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c>
 *   @0x28de10 ldr r4, [r4]
 *   @0x28de14 add r7, r7, #1
 *   @0x28de18 ldr r12, [sp, #0x14]
 *   @0x28de1c cmp r4, #0
 *   @0x28de20 bne 0x28dd7c <spSkeletonJson_readSkeletonData+0x2530>
 *   @0x28de24 mov r5, r12
 *   @0x28de28 ldr r2, [r5, #0xc]
 *   @0x28de2c vldr s14, [r11, #4]
 *   @0x28de30 ldr r3, [r11, #0x8]
 *   @0x28de34 ldr r1, [r11, #0xc]
 *   @0x28de38 sub r2, r2, #1
 *   @0x28de3c add r0, r3, #1
 *   @0x28de40 str r0, [r11, #0x8]
 *   @0x28de44 add r2, r2, r2, lsl #2
 *   @0x28de48 str r6, [r1, r3, lsl #2]
 *   @0x28de4c ldr r3, [r6, #0x10]
 *   @0x28de50 ldr r5, [r5]
 *   @0x28de54 add r3, r3, r2, lsl #2
 *   @0x28de58 vldr s15, [r3]
 *   @0x28de5c vcmpe.f32 s14, s15
 *   @0x28de60 vmrs APSR_nzcv, fpscr
 *   @0x28de64 vmovgt.f32 s15, s14
 *   @0x28de68 cmp r5, #0
 *   @0x28de6c vstr s15, [r11, #4]
 *   @0x28de70 bne 0x28dd00 <spSkeletonJson_readSkeletonData+0x24b4>
 *   @0x28de74 ldr r1, [sp, #0x44]
 *   @0x28de78 cmp r1, #0
 *   @0x28de7c beq 0x28e060 <spSkeletonJson_readSkeletonData+0x2814>
 *   @0x28de80 ldr r2, [sp, #0x44]
 *   @0x28de84 ldr r10, [r2, #0x4]
 *   @0x28de88 cmp r10, #0
 *   @0x28de8c beq 0x28e060 <spSkeletonJson_readSkeletonData+0x2814>
 *   @0x28de90 ldr r3, [pc, #0xc14]
 *   @0x28de94 mov r0, #0
 *   @0x28de98 ldr r1, [pc, #0xc10]
 *   @0x28de9c add r3, pc, r3
 *   @0x28dea0 str r0, [sp, #0x2c]
 *   @0x28dea4 str r3, [sp, #0x38]
 *   @0x28dea8 add r1, pc, r1
 *   @0x28deac ldr r2, [pc, #0xc00]
 *   @0x28deb0 ldr r3, [pc, #0xc00]
 *   @0x28deb4 ldr r0, [pc, #0xc00]
 *   @0x28deb8 add r2, pc, r2
 *   @0x28debc add r3, pc, r3
 *   @0x28dec0 str r1, [sp, #0x3c]
 *   @0x28dec4 add r0, pc, r0
 *   @0x28dec8 str r2, [sp, #0x40]
 *   @0x28decc str r3, [sp, #0x44]
 *   @0x28ded0 str r0, [sp, #0x48]
 *   @0x28ded4 ldr r0, [sp, #0x18]
 *   @0x28ded8 ldr r1, [r10, #0x1c]
 *   @0x28dedc bl 0x28b2f0 <spSkeletonData_findPathConstraint>
 *   @0x28dee0 subs r9, r0, #0
 *   @0x28dee4 beq 0x28ea48 <spSkeletonJson_readSkeletonData+0x31fc>
 *   @0x28dee8 ldr r2, [sp, #0x18]
 *   @0x28deec ldr r1, [r2, #0x4c]
 *   @0x28def0 cmp r1, #0
 *   @0x28def4 ble 0x28df30 <spSkeletonJson_readSkeletonData+0x26e4>
 *   @0x28def8 ldr r2, [r2, #0x50]
 *   @0x28defc ldr r3, [r2]
 *   @0x28df00 cmp r9, r3
 *   @0x28df04 mov r3, #0
 *   @0x28df08 bne 0x28df1c <spSkeletonJson_readSkeletonData+0x26d0>
 *   @0x28df0c b 0x28df2c <spSkeletonJson_readSkeletonData+0x26e0>
 *   @0x28df10 ldr r0, [r2, #0x4]!
 *   @0x28df14 cmp r9, r0
 *   @0x28df18 beq 0x28df2c <spSkeletonJson_readSkeletonData+0x26e0>
 *   @0x28df1c add r3, r3, #1
 *   @0x28df20 cmp r3, r1
 *   @0x28df24 bne 0x28df10 <spSkeletonJson_readSkeletonData+0x26c4>
 *   @0x28df28 b 0x28df30 <spSkeletonJson_readSkeletonData+0x26e4>
 *   @0x28df2c str r3, [sp, #0x2c]
 *   @0x28df30 ldr r4, [r10, #0x4]
 *   @0x28df34 cmp r4, #0
 *   @0x28df38 beq 0x28e054 <spSkeletonJson_readSkeletonData+0x2808>
 *   @0x28df3c ldr r6, [r4, #0x1c]
 *   @0x28df40 ldr r1, [sp, #0x38]
 *   @0x28df44 mov r0, r6
 *   @0x28df48 bl 0xb6574 <strcmp@plt>
 *   @0x28df4c cmp r0, #0
 *   @0x28df50 mov r0, r6
 *   @0x28df54 bne 0x28e52c <spSkeletonJson_readSkeletonData+0x2ce0>
 *   @0x28df58 ldr r1, [sp, #0x40]
 *   @0x28df5c bl 0xb6574 <strcmp@plt>
 *   @0x28df60 cmp r0, #0
 *   @0x28df64 beq 0x28e53c <spSkeletonJson_readSkeletonData+0x2cf0>
 *   @0x28df68 ldr r0, [r4, #0xc]
 *   @0x28df6c bl 0x283010 <spPathConstraintPositionTimeline_create>
 *   @0x28df70 ldr r3, [r9, #0x10]
 *   @0x28df74 cmp r3, #0
 *   @0x28df78 mov r8, r0
 *   @0x28df7c bne 0x28e554 <spSkeletonJson_readSkeletonData+0x2d08>
 *   @0x28df80 ldr r1, [sp, #0x20]
 *   @0x28df84 vldr s16, [r1]
 *   @0x28df88 ldr r5, [r4, #0x4]
 *   @0x28df8c ldr r2, [sp, #0x2c]
 *   @0x28df90 cmp r5, #0
 *   @0x28df94 str r2, [r8, #0x14]
 *   @0x28df98 movne r7, #0
 *   @0x28df9c movne r12, r4
 *   @0x28dfa0 beq 0x28e010 <spSkeletonJson_readSkeletonData+0x27c4>
 *   @0x28dfa4 mov r0, r5
 *   @0x28dfa8 ldr r1, [sp, #0x3c]
 *   @0x28dfac mov r2, #0
 *   @0x28dfb0 str r12, [sp, #0x14]
 *   @0x28dfb4 bl 0x287444 <Json_getFloat>
 *   @0x28dfb8 mov r1, r6
 *   @0x28dfbc mov r2, #0
 *   @0x28dfc0 mov r4, r0
 *   @0x28dfc4 mov r0, r5
 *   @0x28dfc8 bl 0x287444 <Json_getFloat>
 *   @0x28dfcc mov r1, r7
 *   @0x28dfd0 mov r2, r4
 *   @0x28dfd4 vmov s14, r0
 *   @0x28dfd8 mov r0, r8
 *   @0x28dfdc vmul.f32 s15, s14, s16
 *   @0x28dfe0 vmov r3, s15
 *   @0x28dfe4 bl 0x283028 <spPathConstraintPositionTimeline_setFrame>
 *   @0x28dfe8 mov r0, r5
 *   @0x28dfec mov r2, r7
 *   @0x28dff0 mov r1, r8
 *   @0x28dff4 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c>
 *   @0x28dff8 ldr r5, [r5]
 *   @0x28dffc add r7, r7, #1
 *   @0x28e000 ldr r12, [sp, #0x14]
 *   @0x28e004 cmp r5, #0
 *   @0x28e008 bne 0x28dfa4 <spSkeletonJson_readSkeletonData+0x2758>
 *   @0x28e00c mov r4, r12
 *   @0x28e010 ldr r3, [r11, #0x8]
 *   @0x28e014 vldr s14, [r11, #4]
 *   @0x28e018 ldr r1, [r11, #0xc]
 *   @0x28e01c add r2, r3, #1
 *   @0x28e020 str r2, [r11, #0x8]
 *   @0x28e024 ldr r2, [r4, #0xc]
 *   @0x28e028 str r8, [r1, r3, lsl #2]
 *   @0x28e02c ldr r3, [r8, #0x10]
 *   @0x28e030 add r3, r3, r2, lsl #3
 *   @0x28e034 vldr s15, [r3, #-8]
 *   @0x28e038 vcmpe.f32 s14, s15
 *   @0x28e03c vmrs APSR_nzcv, fpscr
 *   @0x28e040 vmovgt.f32 s15, s14
 *   @0x28e044 vstr s15, [r11, #4]
 *   @0x28e048 ldr r4, [r4]
 *   @0x28e04c cmp r4, #0
 *   @0x28e050 bne 0x28df3c <spSkeletonJson_readSkeletonData+0x26f0>
 *   @0x28e054 ldr r10, [r10]
 *   @0x28e058 cmp r10, #0
 *   @0x28e05c bne 0x28ded4 <spSkeletonJson_readSkeletonData+0x2688>
 *   @0x28e060 ldr r1, [sp, #0x50]
 *   @0x28e064 cmp r1, #0
 *   @0x28e068 beq 0x28e338 <spSkeletonJson_readSkeletonData+0x2aec>
 *   @0x28e06c ldr r0, [sp, #0x50]
 *   @0x28e070 ldr r0, [r0, #0x4]
 *   @0x28e074 cmp r0, #0
 *   @0x28e078 str r0, [sp, #0x2c]
 *   @0x28e07c beq 0x28e338 <spSkeletonJson_readSkeletonData+0x2aec>
 *   @0x28e080 ldr r1, [pc, #0xa38]
 *   @0x28e084 mov r10, r11
 *   @0x28e088 ldr r2, [pc, #0xa34]
 *   @0x28e08c ldr r3, [pc, #0xa34]
 *   @0x28e090 add r1, pc, r1
 *   @0x28e094 ldr r0, [pc, #0xa30]
 *   @0x28e098 add r2, pc, r2
 *   @0x28e09c add r3, pc, r3
 *   @0x28e0a0 str r1, [sp, #0x50]
 *   @0x28e0a4 add r0, pc, r0
 *   @0x28e0a8 str r2, [sp, #0x48]
 *   @0x28e0ac str r3, [sp, #0x54]
 *   @0x28e0b0 str r0, [sp, #0x58]
 *   @0x28e0b4 ldr r2, [sp, #0x2c]
 *   @0x28e0b8 ldr r0, [sp, #0x18]
 *   @0x28e0bc ldr r1, [r2, #0x1c]
 *   @0x28e0c0 bl 0x28b124 <spSkeletonData_findSkin>
 *   @0x28e0c4 ldr r3, [sp, #0x2c]
 *   @0x28e0c8 ldr r8, [r3, #0x4]
 *   @0x28e0cc cmp r8, #0
 *   @0x28e0d0 movne r11, r8
 *   @0x28e0d4 str r0, [sp, #0x40]
 *   @0x28e0d8 beq 0x28e320 <spSkeletonJson_readSkeletonData+0x2ad4>
 *   @0x28e0dc ldr r0, [sp, #0x18]
 *   @0x28e0e0 ldr r1, [r11, #0x1c]
 *   @0x28e0e4 bl 0x28b0cc <spSkeletonData_findSlotIndex>
 *   @0x28e0e8 ldr r9, [r11, #0x4]
 *   @0x28e0ec cmp r9, #0
 *   @0x28e0f0 strne r11, [sp, #0x5c]
 *   @0x28e0f4 str r0, [sp, #0x3c]
 *   @0x28e0f8 beq 0x28e314 <spSkeletonJson_readSkeletonData+0x2ac8>
 *   @0x28e0fc ldr r0, [sp, #0x40]
 *   @0x28e100 ldr r1, [sp, #0x3c]
 *   @0x28e104 ldr r2, [r9, #0x1c]
 *   @0x28e108 bl 0x28ed00 <spSkin_getAttachment>
 *   @0x28e10c subs r8, r0, #0
 *   @0x28e110 beq 0x28e55c <spSkeletonJson_readSkeletonData+0x2d10>
 *   @0x28e114 ldr r3, [r8, #0x14]
 *   @0x28e118 adds r3, r3, #0
 *   @0x28e11c movne r3, #1
 *   @0x28e120 cmp r3, #0
 *   @0x28e124 str r3, [sp, #0x34]
 *   @0x28e128 ldrne r1, [sp, #0x60]
 *   @0x28e12c ldrne r3, [r8, #0x18]
 *   @0x28e130 ldreq r11, [r8, #0x18]
 *   @0x28e134 smullne r1, r2, r1, r3
 *   @0x28e138 ldr r1, [sp, #0x50]
 *   @0x28e13c subne r3, r2, r3, asr #31
 *   @0x28e140 lslne r11, r3, #1
 *   @0x28e144 lsl r2, r11, #2
 *   @0x28e148 str r2, [sp, #0x38]
 *   @0x28e14c ldr r0, [sp, #0x38]
 *   @0x28e150 mov r2, #388
 *   @0x28e154 bl 0x285c10 <_malloc>
 *   @0x28e158 mov r1, r11
 *   @0x28e15c mov r4, r0
 *   @0x28e160 ldr r0, [r9, #0xc]
 *   @0x28e164 bl 0x282e58 <spDeformTimeline_create>
 *   @0x28e168 ldr r5, [r9, #0x4]
 *   @0x28e16c ldr r3, [sp, #0x3c]
 *   @0x28e170 cmp r5, #0
 *   @0x28e174 mov r7, r0
 *   @0x28e178 str r3, [r0, #0x1c]
 *   @0x28e17c str r8, [r0, #0x20]
 *   @0x28e180 beq 0x28e2c4 <spSkeletonJson_readSkeletonData+0x2a78>
 *   @0x28e184 vmov.f32 s16, #1.000000e+00
 *   @0x28e188 ldr r0, [sp, #0x38]
 *   @0x28e18c mov r1, #0
 *   @0x28e190 str r1, [sp, #0x30]
 *   @0x28e194 add r0, r0, r4
 *   @0x28e198 str r0, [sp, #0x44]
 *   @0x28e19c mov r0, r5
 *   @0x28e1a0 ldr r1, [sp, #0x48]
 *   @0x28e1a4 bl 0x2873c4 <Json_getItem>
 *   @0x28e1a8 subs r12, r0, #0
 *   @0x28e1ac beq 0x28e820 <spSkeletonJson_readSkeletonData+0x2fd4>
 *   @0x28e1b0 ldr r1, [sp, #0x54]
 *   @0x28e1b4 mov r2, #0
 *   @0x28e1b8 mov r0, r5
 *   @0x28e1bc str r12, [sp, #0x14]
 *   @0x28e1c0 bl 0x287460 <Json_getInt>
 *   @0x28e1c4 mov r1, #0
 *   @0x28e1c8 lsl r3, r0, #2
 *   @0x28e1cc mov r6, r0
 *   @0x28e1d0 mov r0, r4
 *   @0x28e1d4 str r3, [sp, #0x10]
 *   @0x28e1d8 mov r2, r3
 *   @0x28e1dc bl 0xb65b0 <memset@plt>
 *   @0x28e1e0 ldr r0, [sp, #0x20]
 *   @0x28e1e4 vldr s15, [r0]
 *   @0x28e1e8 vcmp.f32 s15, s16
 *   @0x28e1ec ldr r12, [sp, #0x14]
 *   @0x28e1f0 ldr r3, [sp, #0x10]
 *   @0x28e1f4 vmrs APSR_nzcv, fpscr
 *   @0x28e1f8 ldr r2, [r12, #0x4]
 *   @0x28e1fc bne 0x28e848 <spSkeletonJson_readSkeletonData+0x2ffc>
 *   @0x28e200 cmp r2, #0
 *   @0x28e204 beq 0x28e228 <spSkeletonJson_readSkeletonData+0x29dc>
 *   @0x28e208 add r3, r4, r3
 *   @0x28e20c ldr r1, [r2, #0x18]
 *   @0x28e210 add r6, r6, #1
 *   @0x28e214 ldr r2, [r2]
 *   @0x28e218 cmp r2, #0
 *   @0x28e21c str r1, [r3], #4
 *   @0x28e220 bne 0x28e20c <spSkeletonJson_readSkeletonData+0x29c0>
 *   @0x28e224 lsl r3, r6, #2
 *   @0x28e228 rsb r2, r6, r11
 *   @0x28e22c add r0, r4, r3
 *   @0x28e230 mov r1, #0
 *   @0x28e234 lsl r2, r2, #2
 *   @0x28e238 bl 0xb65b0 <memset@plt>
 *   @0x28e23c ldr r2, [sp, #0x34]
 *   @0x28e240 cmp r2, #0
 *   @0x28e244 bne 0x28e274 <spSkeletonJson_readSkeletonData+0x2a28>
 *   @0x28e248 cmp r11, #0
 *   @0x28e24c ldr r2, [r8, #0x1c]
 *   @0x28e250 ble 0x28e274 <spSkeletonJson_readSkeletonData+0x2a28>
 *   @0x28e254 mov r3, r4
 *   @0x28e258 vldr s14, [r3]
 *   @0x28e25c vldmia r2!, {s15}
 *   @0x28e260 vadd.f32 s15, s14, s15
 *   @0x28e264 ldr r0, [sp, #0x44]
 *   @0x28e268 vstmia r3!, {s15}
 *   @0x28e26c cmp r3, r0
 *   @0x28e270 bne 0x28e258 <spSkeletonJson_readSkeletonData+0x2a0c>
 *   @0x28e274 mov r6, r4
 *   @0x28e278 mov r0, r5
 *   @0x28e27c ldr r1, [sp, #0x58]
 *   @0x28e280 mov r2, #0
 *   @0x28e284 bl 0x287444 <Json_getFloat>
 *   @0x28e288 ldr r1, [sp, #0x30]
 *   @0x28e28c mov r3, r6
 *   @0x28e290 mov r2, r0
 *   @0x28e294 mov r0, r7
 *   @0x28e298 bl 0x282ef8 <spDeformTimeline_setFrame>
 *   @0x28e29c mov r0, r5
 *   @0x28e2a0 mov r1, r7
 *   @0x28e2a4 ldr r2, [sp, #0x30]
 *   @0x28e2a8 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c>
 *   @0x28e2ac ldr r5, [r5]
 *   @0x28e2b0 ldr r1, [sp, #0x30]
 *   @0x28e2b4 cmp r5, #0
 *   @0x28e2b8 add r1, r1, #1
 *   @0x28e2bc str r1, [sp, #0x30]
 *   @0x28e2c0 bne 0x28e19c <spSkeletonJson_readSkeletonData+0x2950>
 *   @0x28e2c4 mov r0, r4
 *   @0x28e2c8 bl 0x285c80 <_free>
 *   @0x28e2cc ldr r3, [r10, #0x8]
 *   @0x28e2d0 ldr r1, [r10, #0xc]
 *   @0x28e2d4 vldr s14, [r10, #4]
 *   @0x28e2d8 add r2, r3, #1
 *   @0x28e2dc str r2, [r10, #0x8]
 *   @0x28e2e0 ldr r2, [r9, #0xc]
 *   @0x28e2e4 str r7, [r1, r3, lsl #2]
 *   @0x28e2e8 ldr r3, [r7, #0x10]
 *   @0x28e2ec ldr r9, [r9]
 *   @0x28e2f0 add r3, r3, r2, lsl #2
 *   @0x28e2f4 vldr s15, [r3, #-4]
 *   @0x28e2f8 vcmpe.f32 s14, s15
 *   @0x28e2fc vmrs APSR_nzcv, fpscr
 *   @0x28e300 vmovgt.f32 s15, s14
 *   @0x28e304 cmp r9, #0
 *   @0x28e308 vstr s15, [r10, #4]
 *   @0x28e30c bne 0x28e0fc <spSkeletonJson_readSkeletonData+0x28b0>
 *   @0x28e310 ldr r11, [sp, #0x5c]
 *   @0x28e314 ldr r11, [r11]
 *   @0x28e318 cmp r11, #0
 *   @0x28e31c bne 0x28e0dc <spSkeletonJson_readSkeletonData+0x2890>
 *   @0x28e320 ldr r0, [sp, #0x2c]
 *   @0x28e324 ldr r0, [r0]
 *   @0x28e328 cmp r0, #0
 *   @0x28e32c str r0, [sp, #0x2c]
 *   @0x28e330 bne 0x28e0b4 <spSkeletonJson_readSkeletonData+0x2868>
 *   @0x28e334 mov r11, r10
 *   @0x28e338 ldr r3, [sp, #0x28]
 *   @0x28e33c cmp r3, #0
 *   @0x28e340 beq 0x28e614 <spSkeletonJson_readSkeletonData+0x2dc8>
 *   @0x28e344 ldr r2, [sp, #0x28]
 *   @0x28e348 ldr r3, [sp, #0x18]
 *   @0x28e34c ldr r0, [r2, #0xc]
 *   @0x28e350 ldr r1, [r3, #0x18]
 *   @0x28e354 bl 0x282d4c <spDrawOrderTimeline_create>
 *   @0x28e358 str r0, [sp, #0x2c]
 *   @0x28e35c ldr r0, [sp, #0x28]
 *   @0x28e360 ldr r9, [r0, #0x4]
 *   @0x28e364 cmp r9, #0
 *   @0x28e368 beq 0x28e5d4 <spSkeletonJson_readSkeletonData+0x2d88>
 *   @0x28e36c ldr r1, [pc, #0x75c]
 *   @0x28e370 mov r10, #0
 *   @0x28e374 ldr r8, [sp, #0x18]
 *   @0x28e378 add r1, pc, r1
 *   @0x28e37c ldr r2, [pc, #0x750]
 *   @0x28e380 str r1, [sp, #0x3c]
 *   @0x28e384 ldr r3, [pc, #0x74c]
 *   @0x28e388 add r2, pc, r2
 *   @0x28e38c ldr r0, [pc, #0x748]
 *   @0x28e390 ldr r1, [pc, #0x748]
 *   @0x28e394 add r3, pc, r3
 *   @0x28e398 add r0, pc, r0
 *   @0x28e39c str r2, [sp, #0x30]
 *   @0x28e3a0 add r1, pc, r1
 *   @0x28e3a4 str r3, [sp, #0x34]
 *   @0x28e3a8 str r0, [sp, #0x40]
 *   @0x28e3ac str r1, [sp, #0x44]
 *   @0x28e3b0 str r11, [sp, #0x38]
 *   @0x28e3b4 mov r0, r9
 *   @0x28e3b8 ldr r1, [sp, #0x3c]
 *   @0x28e3bc bl 0x2873c4 <Json_getItem>
 *   @0x28e3c0 subs r4, r0, #0
 *   @0x28e3c4 beq 0x28e590 <spSkeletonJson_readSkeletonData+0x2d44>
 *   @0x28e3c8 ldr r3, [r4, #0xc]
 *   @0x28e3cc movw r2, #0x1ba
 *   @0x28e3d0 ldr r0, [r8, #0x18]
 *   @0x28e3d4 ldr r1, [sp, #0x30]
 *   @0x28e3d8 rsb r0, r3, r0
 *   @0x28e3dc lsl r0, r0, #2
 *   @0x28e3e0 bl 0x285c10 <_malloc>
 *   @0x28e3e4 ldr r1, [sp, #0x30]
 *   @0x28e3e8 movw r2, #0x1bd
 *   @0x28e3ec mov r11, r0
 *   @0x28e3f0 ldr r0, [r8, #0x18]
 *   @0x28e3f4 lsl r0, r0, #2
 *   @0x28e3f8 bl 0x285c10 <_malloc>
 *   @0x28e3fc ldr r2, [r8, #0x18]
 *   @0x28e400 subs r1, r2, #1
 *   @0x28e404 mov r6, r0
 *   @0x28e408 addpl r2, r0, r2, lsl #2
 *   @0x28e40c mvnpl r0, #0
 *   @0x28e410 bmi 0x28e424 <spSkeletonJson_readSkeletonData+0x2bd8>
 *   @0x28e414 sub r1, r1, #1
 *   @0x28e418 str r0, [r2, #-0x4]!
 *   @0x28e41c cmn r1, #1
 *   @0x28e420 bne 0x28e414 <spSkeletonJson_readSkeletonData+0x2bc8>
 *   @0x28e424 ldr r7, [r4, #0x4]
 *   @0x28e428 cmp r7, #0
 *   @0x28e42c moveq r5, r7
 *   @0x28e430 moveq r4, r5
 *   @0x28e434 beq 0x28e4c4 <spSkeletonJson_readSkeletonData+0x2c78>
 *   @0x28e438 mov r5, #0
 *   @0x28e43c mov r4, r5
 *   @0x28e440 ldr r1, [sp, #0x34]
 *   @0x28e444 mov r2, #0
 *   @0x28e448 mov r0, r7
 *   @0x28e44c bl 0x287428 <Json_getString>
 *   @0x28e450 mov r1, r0
 *   @0x28e454 mov r0, r8
 *   @0x28e458 bl 0x28b0cc <spSkeletonData_findSlotIndex>
 *   @0x28e45c cmn r0, #1
 *   @0x28e460 mov r3, r0
 *   @0x28e464 beq 0x28e8ac <spSkeletonJson_readSkeletonData+0x3060>
 *   @0x28e468 cmp r0, r4
 *   @0x28e46c subne r1, r5, #-1073741823
 *   @0x28e470 movne r2, r4
 *   @0x28e474 addne r1, r11, r1, lsl #2
 *   @0x28e478 beq 0x28e49c <spSkeletonJson_readSkeletonData+0x2c50>
 *   @0x28e47c add r0, r2, #1
 *   @0x28e480 str r2, [r1, #0x4]!
 *   @0x28e484 cmp r0, r3
 *   @0x28e488 mov r2, r0
 *   @0x28e48c bne 0x28e47c <spSkeletonJson_readSkeletonData+0x2c30>
 *   @0x28e490 add r5, r3, r5
 *   @0x28e494 rsb r5, r4, r5
 *   @0x28e498 mov r4, r3
 *   @0x28e49c mov r0, r7
 *   @0x28e4a0 ldr r1, [sp, #0x40]
 *   @0x28e4a4 mov r2, #0
 *   @0x28e4a8 bl 0x287460 <Json_getInt>
 *   @0x28e4ac ldr r7, [r7]
 *   @0x28e4b0 cmp r7, #0
 *   @0x28e4b4 add r0, r4, r0
 *   @0x28e4b8 str r4, [r6, r0, lsl #2]
 *   @0x28e4bc add r4, r4, #1
 *   @0x28e4c0 bne 0x28e440 <spSkeletonJson_readSkeletonData+0x2bf4>
 *   @0x28e4c4 ldr r2, [r8, #0x18]
 *   @0x28e4c8 cmp r4, r2
 *   @0x28e4cc bge 0x28e4f4 <spSkeletonJson_readSkeletonData+0x2ca8>
 *   @0x28e4d0 sub r1, r5, #-1073741823
 *   @0x28e4d4 add r1, r11, r1, lsl #2
 *   @0x28e4d8 str r4, [r1, #0x4]!
 *   @0x28e4dc add r3, r4, #1
 *   @0x28e4e0 ldr r2, [r8, #0x18]
 *   @0x28e4e4 add r5, r5, #1
 *   @0x28e4e8 mov r4, r3
 *   @0x28e4ec cmp r3, r2
 *   @0x28e4f0 blt 0x28e4d8 <spSkeletonJson_readSkeletonData+0x2c8c>
 *   @0x28e4f4 subs r1, r2, #1
 *   @0x28e4f8 addpl r2, r6, r2, lsl #2
 *   @0x28e4fc bmi 0x28e520 <spSkeletonJson_readSkeletonData+0x2cd4>
 *   @0x28e500 ldr r3, [r2, #-0x4]!
 *   @0x28e504 sub r1, r1, #1
 *   @0x28e508 cmn r3, #1
 *   @0x28e50c subeq r5, r5, #1
 *   @0x28e510 ldreq r3, [r11, r5, lsl #2]
 *   @0x28e514 streq r3, [r2]
 *   @0x28e518 cmn r1, #1
 *   @0x28e51c bne 0x28e500 <spSkeletonJson_readSkeletonData+0x2cb4>
 *   @0x28e520 mov r0, r11
 *   @0x28e524 bl 0x285c80 <_free>
 *   @0x28e528 b 0x28e594 <spSkeletonJson_readSkeletonData+0x2d48>
 *   @0x28e52c ldr r1, [sp, #0x44]
 *   @0x28e530 bl 0xb6574 <strcmp@plt>
 *   @0x28e534 cmp r0, #0
 *   @0x28e538 bne 0x28e8ec <spSkeletonJson_readSkeletonData+0x30a0>
 *   @0x28e53c ldr r0, [r4, #0xc]
 *   @0x28e540 bl 0x28303c <spPathConstraintSpacingTimeline_create>
 *   @0x28e544 ldr r3, [r9, #0x14]
 *   @0x28e548 cmp r3, #1
 *   @0x28e54c mov r8, r0
 *   @0x28e550 bls 0x28ea74 <spSkeletonJson_readSkeletonData+0x3228>
 *   @0x28e554 vmov.f32 s16, #1.000000e+00
 *   @0x28e558 b 0x28df88 <spSkeletonJson_readSkeletonData+0x273c>
 *   @0x28e55c mov r5, r8
 *   @0x28e560 mov r0, r10
 *   @0x28e564 ldr r8, [sp, #0x20]
 *   @0x28e568 mov r7, r9
 *   @0x28e56c ldr r9, [sp, #0x18]
 *   @0x28e570 bl 0x28147c <spAnimation_dispose>
 *   @0x28e574 ldr r2, [pc, #0x568]
 *   @0x28e578 mov r1, r5
 *   @0x28e57c mov r0, r8
 *   @0x28e580 ldr r3, [r7, #0x1c]
 *   @0x28e584 add r2, pc, r2
 *   @0x28e588 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28e58c b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8>
 *   @0x28e590 mov r6, r4
 *   @0x28e594 mov r0, r9
 *   @0x28e598 ldr r1, [sp, #0x44]
 *   @0x28e59c mov r2, #0
 *   @0x28e5a0 bl 0x287444 <Json_getFloat>
 *   @0x28e5a4 mov r1, r10
 *   @0x28e5a8 mov r3, r6
 *   @0x28e5ac add r10, r10, #1
 *   @0x28e5b0 mov r2, r0
 *   @0x28e5b4 ldr r0, [sp, #0x2c]
 *   @0x28e5b8 bl 0x282ddc <spDrawOrderTimeline_setFrame>
 *   @0x28e5bc mov r0, r6
 *   @0x28e5c0 bl 0x285c80 <_free>
 *   @0x28e5c4 ldr r9, [r9]
 *   @0x28e5c8 cmp r9, #0
 *   @0x28e5cc bne 0x28e3b4 <spSkeletonJson_readSkeletonData+0x2b68>
 *   @0x28e5d0 ldr r11, [sp, #0x38]
 *   @0x28e5d4 ldr r0, [sp, #0x28]
 *   @0x28e5d8 vldr s14, [r11, #4]
 *   @0x28e5dc ldr r3, [r11, #0x8]
 *   @0x28e5e0 ldr r1, [r11, #0xc]
 *   @0x28e5e4 ldr r2, [r0, #0xc]
 *   @0x28e5e8 add r0, r3, #1
 *   @0x28e5ec str r0, [r11, #0x8]
 *   @0x28e5f0 ldr r0, [sp, #0x2c]
 *   @0x28e5f4 str r0, [r1, r3, lsl #2]
 *   @0x28e5f8 ldr r3, [r0, #0xc]
 *   @0x28e5fc add r3, r3, r2, lsl #2
 *   @0x28e600 vldr s15, [r3, #-4]
 *   @0x28e604 vcmpe.f32 s14, s15
 *   @0x28e608 vmrs APSR_nzcv, fpscr
 *   @0x28e60c vmovgt.f32 s15, s14
 *   @0x28e610 vstr s15, [r11, #4]
 *   @0x28e614 ldr r2, [sp, #0x4c]
 *   @0x28e618 cmp r2, #0
 *   @0x28e61c beq 0x28e774 <spSkeletonJson_readSkeletonData+0x2f28>
 *   @0x28e620 ldr r0, [r2, #0xc]
 *   @0x28e624 bl 0x282c8c <spEventTimeline_create>
 *   @0x28e628 ldr r3, [sp, #0x4c]
 *   @0x28e62c ldr r10, [r3, #0x4]
 *   @0x28e630 cmp r10, #0
 *   @0x28e634 mov r6, r0
 *   @0x28e638 beq 0x28e738 <spSkeletonJson_readSkeletonData+0x2eec>
 *   @0x28e63c ldr r3, [pc, #0x4a4]
 *   @0x28e640 mov r5, #0
 *   @0x28e644 ldr r7, [pc, #0x4a0]
 *   @0x28e648 add r3, pc, r3
 *   @0x28e64c ldr r9, [pc, #0x49c]
 *   @0x28e650 str r3, [sp, #0x28]
 *   @0x28e654 add r7, pc, r7
 *   @0x28e658 ldr r3, [pc, #0x494]
 *   @0x28e65c add r9, pc, r9
 *   @0x28e660 add r3, pc, r3
 *   @0x28e664 str r3, [sp, #0x2c]
 *   @0x28e668 ldr r3, [pc, #0x488]
 *   @0x28e66c add r3, pc, r3
 *   @0x28e670 str r3, [sp, #0x30]
 *   @0x28e674 mov r2, #0
 *   @0x28e678 mov r1, r7
 *   @0x28e67c mov r0, r10
 *   @0x28e680 bl 0x287428 <Json_getString>
 *   @0x28e684 mov r1, r0
 *   @0x28e688 ldr r0, [sp, #0x18]
 *   @0x28e68c bl 0x28b180 <spSkeletonData_findEvent>
 *   @0x28e690 mov r2, #0
 *   @0x28e694 ldr r1, [sp, #0x28]
 *   @0x28e698 subs r8, r0, #0
 *   @0x28e69c mov r0, r10
 *   @0x28e6a0 beq 0x28e7b4 <spSkeletonJson_readSkeletonData+0x2f68>
 *   @0x28e6a4 bl 0x287444 <Json_getFloat>
 *   @0x28e6a8 mov r1, r8
 *   @0x28e6ac bl 0x285b44 <spEvent_create>
 *   @0x28e6b0 ldr r2, [r8, #0x4]
 *   @0x28e6b4 mov r1, r9
 *   @0x28e6b8 mov r4, r0
 *   @0x28e6bc mov r0, r10
 *   @0x28e6c0 bl 0x287460 <Json_getInt>
 *   @0x28e6c4 ldr r2, [r8, #0x8]
 *   @0x28e6c8 ldr r1, [sp, #0x2c]
 *   @0x28e6cc str r0, [r4, #0x8]
 *   @0x28e6d0 mov r0, r10
 *   @0x28e6d4 bl 0x287444 <Json_getFloat>
 *   @0x28e6d8 ldr r2, [r8, #0xc]
 *   @0x28e6dc ldr r1, [sp, #0x30]
 *   @0x28e6e0 str r0, [r4, #0xc]
 *   @0x28e6e4 mov r0, r10
 *   @0x28e6e8 bl 0x287428 <Json_getString>
 *   @0x28e6ec subs r8, r0, #0
 *   @0x28e6f0 beq 0x28e718 <spSkeletonJson_readSkeletonData+0x2ecc>
 *   @0x28e6f4 bl 0xb6538 <strlen@plt>
 *   @0x28e6f8 ldr r1, [pc, #0x3fc]
 *   @0x28e6fc movw r2, #0x1ee
 *   @0x28e700 add r1, pc, r1
 *   @0x28e704 add r0, r0, #1
 *   @0x28e708 bl 0x285c10 <_malloc>
 *   @0x28e70c mov r1, r8
 *   @0x28e710 str r0, [r4, #0x10]
 *   @0x28e714 bl 0xb65a4 <strcpy@plt>
 *   @0x28e718 mov r1, r5
 *   @0x28e71c mov r2, r4
 *   @0x28e720 mov r0, r6
 *   @0x28e724 add r5, r5, #1
 *   @0x28e728 bl 0x282d14 <spEventTimeline_setFrame>
 *   @0x28e72c ldr r10, [r10]
 *   @0x28e730 cmp r10, #0
 *   @0x28e734 bne 0x28e674 <spSkeletonJson_readSkeletonData+0x2e28>
 *   @0x28e738 ldr r0, [sp, #0x4c]
 *   @0x28e73c vldr s14, [r11, #4]
 *   @0x28e740 ldr r3, [r11, #0x8]
 *   @0x28e744 ldr r1, [r11, #0xc]
 *   @0x28e748 ldr r2, [r0, #0xc]
 *   @0x28e74c add r0, r3, #1
 *   @0x28e750 str r0, [r11, #0x8]
 *   @0x28e754 str r6, [r1, r3, lsl #2]
 *   @0x28e758 ldr r3, [r6, #0xc]
 *   @0x28e75c add r3, r3, r2, lsl #2
 *   @0x28e760 vldr s15, [r3, #-4]
 *   @0x28e764 vcmpe.f32 s14, s15
 *   @0x28e768 vmrs APSR_nzcv, fpscr
 *   @0x28e76c vmovgt.f32 s15, s14
 *   @0x28e770 vstr s15, [r11, #4]
 *   @0x28e774 ldr r0, [sp, #0x18]
 *   @0x28e778 ldr r3, [r0, #0x34]
 *   @0x28e77c ldr r2, [r0, #0x38]
 *   @0x28e780 add r1, r3, #1
 *   @0x28e784 str r1, [r0, #0x34]
 *   @0x28e788 ldr r1, [sp, #0x1c]
 *   @0x28e78c str r11, [r2, r3, lsl #2]
 *   @0x28e790 ldr r1, [r1]
 *   @0x28e794 cmp r1, #0
 *   @0x28e798 str r1, [sp, #0x1c]
 *   @0x28e79c bne 0x28d318 <spSkeletonJson_readSkeletonData+0x1acc>
 *   @0x28e7a0 mov r9, r0
 *   @0x28e7a4 ldr r0, [sp, #0x24]
 *   @0x28e7a8 bl 0x2872c8 <Json_dispose>
 *   @0x28e7ac mov r0, r9
 *   @0x28e7b0 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580>
 *   @0x28e7b4 mov r4, r8
 *   @0x28e7b8 mov r0, r11
 *   @0x28e7bc ldr r8, [sp, #0x20]
 *   @0x28e7c0 ldr r9, [sp, #0x18]
 *   @0x28e7c4 bl 0x28147c <spAnimation_dispose>
 *   @0x28e7c8 mov r1, r7
 *   @0x28e7cc mov r2, r4
 *   @0x28e7d0 mov r0, r10
 *   @0x28e7d4 bl 0x287428 <Json_getString>
 *   @0x28e7d8 ldr r2, [pc, #0x320]
 *   @0x28e7dc mov r1, r4
 *   @0x28e7e0 add r2, pc, r2
 *   @0x28e7e4 mov r3, r0
 *   @0x28e7e8 mov r0, r8
 *   @0x28e7ec bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28e7f0 b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8>
 *   @0x28e7f4 ldr r9, [sp, #0x34]
 *   @0x28e7f8 mov r0, r9
 *   @0x28e7fc bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28e800 ldr r2, [pc, #0x2fc]
 *   @0x28e804 mov r0, r8
 *   @0x28e808 ldr r1, [sp, #0x24]
 *   @0x28e80c mov r3, r10
 *   @0x28e810 add r2, pc, r2
 *   @0x28e814 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28e818 mov r0, #0
 *   @0x28e81c b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580>
 *   @0x28e820 ldr r2, [sp, #0x34]
 *   @0x28e824 cmp r2, #0
 *   @0x28e828 ldreq r6, [r8, #0x1c]
 *   @0x28e82c beq 0x28e278 <spSkeletonJson_readSkeletonData+0x2a2c>
 *   @0x28e830 mov r1, r12
 *   @0x28e834 mov r0, r4
 *   @0x28e838 ldr r2, [sp, #0x38]
 *   @0x28e83c mov r6, r4
 *   @0x28e840 bl 0xb65b0 <memset@plt>
 *   @0x28e844 b 0x28e278 <spSkeletonJson_readSkeletonData+0x2a2c>
 *   @0x28e848 cmp r2, #0
 *   @0x28e84c beq 0x28e228 <spSkeletonJson_readSkeletonData+0x29dc>
 *   @0x28e850 add r3, r4, r3
 *   @0x28e854 b 0x28e860 <spSkeletonJson_readSkeletonData+0x3014>
 *   @0x28e858 ldr r1, [sp, #0x20]
 *   @0x28e85c vldr s15, [r1]
 *   @0x28e860 vldr s14, [r2, #24]
 *   @0x28e864 vmul.f32 s15, s15, s14
 *   @0x28e868 ldr r2, [r2]
 *   @0x28e86c add r6, r6, #1
 *   @0x28e870 cmp r2, #0
 *   @0x28e874 vstmia r3!, {s15}
 *   @0x28e878 bne 0x28e858 <spSkeletonJson_readSkeletonData+0x300c>
 *   @0x28e87c b 0x28e224 <spSkeletonJson_readSkeletonData+0x29d8>
 *   @0x28e880 mov r5, r0
 *   @0x28e884 mov r0, r9
 *   @0x28e888 bl 0x28adf8 <spSkeletonData_dispose>
 *   @0x28e88c ldr r2, [pc, #0x274]
 *   @0x28e890 mov r0, r8
 *   @0x28e894 mov r1, r5
 *   @0x28e898 ldr r3, [r4]
 *   @0x28e89c add r2, pc, r2
 *   @0x28e8a0 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28e8a4 mov r0, r5
 *   @0x28e8a8 b 0x28bdcc <spSkeletonJson_readSkeletonData+0x580>
 *   @0x28e8ac ldr r11, [sp, #0x38]
 *   @0x28e8b0 mov r9, r8
 *   @0x28e8b4 ldr r8, [sp, #0x20]
 *   @0x28e8b8 mov r0, r11
 *   @0x28e8bc bl 0x28147c <spAnimation_dispose>
 *   @0x28e8c0 ldr r1, [sp, #0x34]
 *   @0x28e8c4 mov r0, r7
 *   @0x28e8c8 mov r2, #0
 *   @0x28e8cc bl 0x287428 <Json_getString>
 *   @0x28e8d0 ldr r2, [pc, #0x234]
 *   @0x28e8d4 mov r1, #0
 *   @0x28e8d8 add r2, pc, r2
 *   @0x28e8dc mov r3, r0
 *   @0x28e8e0 mov r0, r8
 *   @0x28e8e4 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28e8e8 b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8>
 *   @0x28e8ec mov r0, r6
 *   @0x28e8f0 ldr r1, [sp, #0x48]
 *   @0x28e8f4 bl 0xb6574 <strcmp@plt>
 *   @0x28e8f8 cmp r0, #0
 *   @0x28e8fc beq 0x28e048 <spSkeletonJson_readSkeletonData+0x27fc>
 *   @0x28e900 ldr r0, [r4, #0xc]
 *   @0x28e904 bl 0x283068 <spPathConstraintMixTimeline_create>
 *   @0x28e908 ldr r5, [r4, #0x4]
 *   @0x28e90c cmp r5, #0
 *   @0x28e910 mov r6, r0
 *   @0x28e914 ldr r0, [sp, #0x2c]
 *   @0x28e918 str r0, [r6, #0x14]
 *   @0x28e91c beq 0x28e9cc <spSkeletonJson_readSkeletonData+0x3180>
 *   @0x28e920 ldr r8, [pc, #0x1e8]
 *   @0x28e924 mov r7, #0
 *   @0x28e928 ldr r1, [pc, #0x1e4]
 *   @0x28e92c mov r12, r4
 *   @0x28e930 ldr r2, [pc, #0x1e0]
 *   @0x28e934 add r8, pc, r8
 *   @0x28e938 add r1, pc, r1
 *   @0x28e93c str r1, [sp, #0x30]
 *   @0x28e940 add r2, pc, r2
 *   @0x28e944 str r2, [sp, #0x34]
 *   @0x28e948 mov r0, r5
 *   @0x28e94c mov r1, r8
 *   @0x28e950 mov r2, #0
 *   @0x28e954 str r12, [sp, #0x14]
 *   @0x28e958 bl 0x287444 <Json_getFloat>
 *   @0x28e95c ldr r1, [sp, #0x30]
 *   @0x28e960 mov r2, #1065353216
 *   @0x28e964 mov r3, r0
 *   @0x28e968 mov r0, r5
 *   @0x28e96c str r3, [sp, #0x10]
 *   @0x28e970 bl 0x287444 <Json_getFloat>
 *   @0x28e974 ldr r1, [sp, #0x34]
 *   @0x28e978 mov r2, #1065353216
 *   @0x28e97c mov r4, r0
 *   @0x28e980 mov r0, r5
 *   @0x28e984 bl 0x287444 <Json_getFloat>
 *   @0x28e988 ldr r3, [sp, #0x10]
 *   @0x28e98c mov r1, r7
 *   @0x28e990 mov r2, r3
 *   @0x28e994 mov r3, r4
 *   @0x28e998 str r0, [sp]
 *   @0x28e99c mov r0, r6
 *   @0x28e9a0 bl 0x283080 <spPathConstraintMixTimeline_setFrame>
 *   @0x28e9a4 mov r0, r5
 *   @0x28e9a8 mov r2, r7
 *   @0x28e9ac mov r1, r6
 *   @0x28e9b0 bl 0x28b34c <spSkeletonData_findPathConstraint+0x5c>
 *   @0x28e9b4 ldr r5, [r5]
 *   @0x28e9b8 add r7, r7, #1
 *   @0x28e9bc ldr r12, [sp, #0x14]
 *   @0x28e9c0 cmp r5, #0
 *   @0x28e9c4 bne 0x28e948 <spSkeletonJson_readSkeletonData+0x30fc>
 *   @0x28e9c8 mov r4, r12
 *   @0x28e9cc ldr r2, [r4, #0xc]
 *   @0x28e9d0 vldr s14, [r11, #4]
 *   @0x28e9d4 ldr r3, [r11, #0x8]
 *   @0x28e9d8 ldr r1, [r11, #0xc]
 *   @0x28e9dc sub r2, r2, #1
 *   @0x28e9e0 add r0, r3, #1
 *   @0x28e9e4 str r0, [r11, #0x8]
 *   @0x28e9e8 add r2, r2, r2, lsl #1
 *   @0x28e9ec str r6, [r1, r3, lsl #2]
 *   @0x28e9f0 ldr r3, [r6, #0x10]
 *   @0x28e9f4 add r3, r3, r2, lsl #2
 *   @0x28e9f8 vldr s15, [r3]
 *   @0x28e9fc vcmpe.f32 s14, s15
 *   @0x28ea00 vmrs APSR_nzcv, fpscr
 *   @0x28ea04 vmovgt.f32 s15, s14
 *   @0x28ea08 vstr s15, [r11, #4]
 *   @0x28ea0c b 0x28e048 <spSkeletonJson_readSkeletonData+0x27fc>
 *   @0x28ea10 mov r0, r11
 *   @0x28ea14 ldr r8, [sp, #0x20]
 *   @0x28ea18 ldr r9, [sp, #0x18]
 *   @0x28ea1c bl 0x28147c <spAnimation_dispose>
 *   @0x28ea20 ldr r2, [sp, #0x2c]
 *   @0x28ea24 mov r0, r8
 *   @0x28ea28 ldr r1, [sp, #0x1c]
 *   @0x28ea2c ldr r3, [r2, #0x1c]
 *   @0x28ea30 ldr r2, [pc, #0xe4]
 *   @0x28ea34 add r2, pc, r2
 *   @0x28ea38 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28ea3c b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8>
 *   @0x28ea40 mov r3, r2
 *   @0x28ea44 b 0x28d3e4 <spSkeletonJson_readSkeletonData+0x1b98>
 *   @0x28ea48 ldr r8, [sp, #0x20]
 *   @0x28ea4c mov r0, r11
 *   @0x28ea50 ldr r9, [sp, #0x18]
 *   @0x28ea54 bl 0x28147c <spAnimation_dispose>
 *   @0x28ea58 ldr r2, [pc, #0xc0]
 *   @0x28ea5c mov r0, r8
 *   @0x28ea60 ldr r1, [sp, #0x1c]
 *   @0x28ea64 ldr r3, [r10, #0x1c]
 *   @0x28ea68 add r2, pc, r2
 *   @0x28ea6c bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28ea70 b 0x28da44 <spSkeletonJson_readSkeletonData+0x21f8>
 *   @0x28ea74 ldr r0, [sp, #0x20]
 *   @0x28ea78 vldr s16, [r0]
 *   @0x28ea7c b 0x28df88 <spSkeletonJson_readSkeletonData+0x273c>
 *   @0x28ea80 ldr r3, [sp, #0x30]
 *   @0x28ea84 b 0x28d3e4 <spSkeletonJson_readSkeletonData+0x1b98>
 *   @0x28ea88 andeq lr, r11, r0, lsr r7
 *   @0x28ea8c ldrdeq r2, r3, [r10], -r12
 *   @0x28ea90 andeq r10, r12, r0, lsr r3
 *   @0x28ea94 andeq r10, r12, r12, lsr r3
 *   @0x28ea98 andeq lr, r11, r0, lsl #10
 *   @0x28ea9c andeq r9, r12, r0, ror #31
 *   @0x28eaa0 andeq r9, r12, r4, ror #31
 *   @0x28eaa4 andeq r9, r12, r12, ror #31
 *   @0x28eaa8 strdeq r9, r10, [r12], -r0
 *   @0x28eaac ldrdeq r9, r10, [r12], -r12
 *   @0x28eab0 andeq lr, r11, r4, lsr #6
 *   @0x28eab4 andeq r9, r12, r12, asr #29
 *   @0x28eab8 andeq r9, r12, r8, asr #29
 *   @0x28eabc andeq r9, r12, r12, asr #27
 *   @0x28eac0 andeq r9, r12, r0, ror r10
 *   @0x28eac4 andeq r9, r12, r12, asr r10
 *   @0x28eac8 andeq r9, r12, r0, lsr #29
 *   @0x28eacc andeq lr, r11, r8, lsr #2
 *   @0x28ead0 andeq r9, r12, r12, asr #23
 *   @0x28ead4 andeq r9, r12, r8, ror r7
 *   @0x28ead8 strheq r9, [r12], -r8
 *   @0x28eadc andeq r9, r12, r4, lsr #23
 *   @0x28eae0 andeq sp, r11, r12, lsr #28
 *   @0x28eae4 andeq r9, r12, r0, lsr #19
 *   @0x28eae8 andeq sp, r11, r4, lsl #23
 *   @0x28eaec strheq r2, [r10], -r4
 *   @0x28eaf0 strdeq r9, r10, [r12], -r4
 *   @0x28eaf4 andeq r2, r10, r0, asr #3
 *   @0x28eaf8 strheq r2, [r10], -r12
 *   @0x28eafc andeq r9, r12, r0, lsl #8
 *   @0x28eb00 andeq r9, r12, r4, ror r7
 *   @0x28eb04 strheq r8, [r12], -r12
 *   @0x28eb08 muleq r12, r0, r5
 *   @0x28eb0c muleq r12, r12, r5
 *   @0x28eb10 muleq r11, r8, r8
 *   @0x28eb14 andeq r9, r12, r0, lsl #7
 *   @0x28eb18 andeq r9, r12, r4, lsl #7
 *   @0x28eb1c andeq r9, r12, r0, asr #8
 *   @0x28eb20 andeq r9, r12, r0, lsr #9
 *   @0x28eb24 andeq r9, r12, r8, lsr r3
 *   @0x28eb28 ldr r1, [pc, #-0xc]
 *   @0x28eb2c ldr r0, [sp, #0x1c]
 *   @0x28eb30 add r1, pc, r1
 *   @0x28eb34 bl 0x2873c4 <Json_getItem>
 *   @0x28eb38 str r0, [sp, #0x28]
 *   @0x28eb3c b 0x28d3b4 <spSkeletonJson_readSkeletonData+0x1b68>
 *
 * ══ §3/7 anonT_2fec70  0x2fec70  size 5012  286 条（0x2fec70..0x300004）｜其中 967 条已由别的卡落锚，本节不再重复
 * @func 0x2fec7c 0x2ffff0  size 4980  286 条
 * 部分覆盖: 本节 286/2106 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anonT_2f8e0a×11 / FT_Stream_GetUShort×7 / ft_mem_free×6 / 0xb65bc×4 / ft_mem_realloc×3 / anon_b6fd0+0x142a×2 / anon_2fa330+0x1f2×2 / anonT_2fec70+0x41c×2
 * 字段偏移 top8: 0x4×18 / 0x10×18 / 0x14×17 / 0x18×17 / 0x5c×14 / 0x4c×12 / 0x3c×10 / 0x20×9
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2fec7c stmvs r3, {r5, r6, pc}
 *   @0x2fec98 .word 0xf8d4ec92
 *   @0x2fec9c subhs r0, r4, #156
 *   @0x2feca4 .word 0x31b47090
 *   @0x2fecb4 .word 0xf8c33280
 *   @0x2fecb8 .word 0xf8d420e0
 *   @0x2fecbc .word 0xf8c3309c
 *   @0x2fecc0 rfeia r4!
 *   @0x2fecc4 .word 0xf8d42080
 *   @0x2fecc8 .word 0xf8d4008c
 *   @0x2feccc sbcseq r1, r2, r8, lsl #1
 *   @0x2fece4 bvs 0xff78af5c <b2_toiTime+0xffffffffff031ab8>
 *   @0x2fecec rfeia r4!
 *   @0x2fecf0 stchs p0, c3, [r0, #-512]
 *   @0x2fed48 .word 0xf0220220
 *   @0x2fed4c subsvs r0, r10, pc, lsr r2
 *   @0x2fed68 .word 0xf0220220
 *   @0x2fed6c subsvs r0, r10, pc, lsr r2
 *   @0x2fedac .word 0xf105509c
 *   @0x2fedb0 .word 0xf1050690
 *   @0x2fedb4 .word 0xf8d50724
 *   @0x2fedb8 .word 0xf10531d0
 *   @0x2fedbc .word 0xf8c50e90
 *   @0x2fedc0 .word 0xf8c5c16c
 *   @0x2fedc4 .word 0xf8d53168
 *   @0x2fedc8 .word 0xf8c531d4
 *   @0x2fedcc movwhs r3, #0x3170
 *   @0x2fedec .word 0xf105000f
 *   @0x2fedf0 .word 0xc70f0e90
 *   @0x2fee04 strgt r0, [pc, -pc]
 *   @0x2fee38 .word 0xf8c5112e
 *   @0x2fee3c .word 0xf8c51126
 *   @0x2fee40 .word 0xf8c5c010
 *   @0x2fee44 .word 0xf8d3c1b0
 *   @0x2fee48 .word 0x4798329c
 *   @0x2fee54 bllt 0xfef87730 <b2_toiTime+0xfffffffffe82e28c>
 *   @0x2fee80 .word 0xf1043080
 *   @0x2fee84 .word 0xf8d40244
 *   @0x2fee88 .word 0xf1031088
 *   @0x2fee8c bllo 0x413a94 <g_RomDisk+0x1c274>
 *   @0x2feea8 .word 0xf1030003
 *   @0x2feeac .word 0xf1040110
 *   @0x2feeb0 tstlo r8, #180, #4
 *   @0x2feec8 ldrlt r8, [r0, #-0x3f8]
 *   @0x2feeec bleq 0xfe6ffaf8 <b2_toiTime+0xfffffffffdfa6654>
 *   @0x2feef8 ldrhlt r3, [r3, -r5]
 *   @0x2fef00 ldrmi r11, [r8], -r7, ror #29
 *   @0x2fef08 push {r4, r8, r9, r10, r11}
 *   @0x2fef0c .word 0x460447ff
 *   @0x2fef24 .word 0xf10d0a0c
 *   @0x2fef28 and r0, r4, lr, lsl #18
 *   @0x2fef40 strtmi r9, [r0], -r0
 *   @0x2fef48 rfeia sp!
 *   @0x2fef4c .word 0xf848300e
 *   @0x2fef50 strlo r3, [r1, #-0x25]
 *   @0x2fef70 uadd16mi r2, r3, r12
 *   @0x2fefa8 ldrtmi r4, [r2], -r12, lsr #2
 *   @0x2fefbc strhvs r0, [r0, -r0]!
 *   @0x2fefe8 movwhs r3, #0x2170
 *   @0x2feff4 .word 0xf8c42168
 *   @0x2feff8 .word 0xf8d73164
 *   @0x2feffc .word 0x4798329c
 *   @0x2ff004 smladxhs r0, r4, r1, r5
 *   @0x2ff058 .word 0xf8c6319c
 *   @0x2ff05c .word 0xf8d43088
 *   @0x2ff060 .word 0xf8c631a8
 *   @0x2ff064 .word 0xf8d43094
 *   @0x2ff068 .word 0xf8c631ac
 *   @0x2ff06c stmibne r2!, {r3, r4, r7, r12, sp} ^
 *   @0x2ff074 strlo r7, [r8, -r0, ror #5]
 *   @0x2ff0ac .word 0xf8cd52b8
 *   @0x2ff0b0 bhs 0x32b268
 *   @0x2ff0bc stclvs p2, c8, [r10], #-828
 *   @0x2ff0c4 stcvs p2, c8, [r10], #820
 *   @0x2ff0dc .word 0xf8cd82c1
 *   @0x2ff0e0 cdpge p0, #0x1, c11, c9, c0, #0x0
 *   @0x2ff0ec .word 0xf8ddffd0
 *   @0x2ff0f0 andls r10, r6, r4, rrx
 *   @0x2ff100 strls r10, [r1], -r0
 *   @0x2ff10c bls 0x97f014 <b2_toiTime+0x225b70>
 *   @0x2ff124 blls 0x97effc <b2_toiTime+0x225b58>
 *   @0x2ff154 strmi pc, [r2], r6, ror #28
 *   @0x2ff174 blls 0x97efac <b2_toiTime+0x225b08>
 *   @0x2ff180 stm sp, {r0, r4, r5, r6, r9, pc}
 *   @0x2ff184 .word 0x21040044
 *   @0x2ff198 stm sp, {r0, r3, r5, r6, r9, pc}
 *   @0x2ff19c .word 0x21040044
 *   @0x2ff1b0 qsaxmi r8, r0, pc
 *   @0x2ff1e0 .word 0xf02040ff
 *   @0x2ff1e4 smlsdxls r9, pc, r0, r0
 *   @0x2ff200 stmdavs r3!, {r3, r4, r5, r6, r11, r12, sp, lr, pc}
 *   @0x2ff24c .word 0x462081dd
 *   @0x2ff278 strlo r0, [r1, -r7, lsr #32]
 *   @0x2ff280 blvs 0xffd7feb4 <b2_toiTime+0xffffffffff626a10>
 *   @0x2ff2d8 strlo r0, [r1, -r7, lsr #32]
 *   @0x2ff2f4 strlo r0, [r1, -r7, lsr #32]
 *   @0x2ff304 andsls r0, r5, #536870912
 *   @0x2ff350 .word 0xd10a0f00
 *   @0x2ff364 strls pc, [r10, -r8, ror #31]
 *   @0x2ff378 strdle r3, r4, [r2], -pc
 *   @0x2ff388 blls 0x44df8c <g_RomDisk+0x5676c>
 *   @0x2ff3a8 bls 0x8be870 <b2_toiTime+0x1653cc>
 *   @0x2ff3bc ands r3, r12, r6, lsr r0
 *   @0x2ff3e8 and r2, sp, r6, lsr r0
 *   @0x2ff3f4 ldrbeq r3, [r11], r0, asr #5
 *   @0x2ff3fc bl 0x3cb414 <error_g0017+0x240b8>
 *   @0x2ff400 ldmdavs r10, {r1, r2, r6, r7, r8, r9} ^
 *   @0x2ff418 strbpl r0, [r6], #513
 *   @0x2ff45c blls 0x3fe7bc <g_RomDisk+0x6f9c>
 *   @0x2ff468 rfedb r1!
 *   @0x2ff46c shadd16mi r0, r9, r6
 *   @0x2ff49c eorslt r3, r10, #12
 *   @0x2ff4dc ldrtmi pc, [r7], -r5, lsl #19
 *   @0x2ff4f8 .word 0xf85b0e03
 *   @0x2ff4fc ldrmi r1, [r8], #-55
 *   @0x2ff518 ldrmi r0, [r9, #0x3c9]!
 *   @0x2ff524 .word 0xf1090c08
 *   @0x2ff528 strmi r0, [r8], #-2305
 *   @0x2ff538 strb r0, [lr, r4, lsl #24]!
 *   @0x2ff564 ldrbmi r0, [r3], -r8, lsl #16
 *   @0x2ff574 strmi r3, [r9, #0x1ff]
 *   @0x2ff588 svcls #0x8f92f
 *   @0x2ff59c sxtahmi r10, r1, r6, ror #24
 *   @0x2ff5a8 stmdbls r6, {r0, r2, r4, r6, r7, r9, r10, r11, sp, pc}
 *   @0x2ff5c0 .word 0xf85b0e00
 *   @0x2ff5c4 ldmpl r9!, {r0, r1} ^
 *   @0x2ff614 stmdals r4, {r4, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2ff61c stmdals r4, {r2, r3, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2ff624 stmdals r4, {r3, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2ff62c strtmi pc, [r0], -r4, lsl #29
 *   @0x2ff638 and r11, r1, r12, lsl r0
 *   @0x2ff684 ldrmi r11, [r8], r0
 *   @0x2ff6b8 strls r3, [r6, #-0x580]
 *   @0x2ff6c0 blvs 0x1a4b8c8 <b2_toiTime+0x12f2424>
 *   @0x2ff6ec .word 0xf5b6a01c
 *   @0x2ff6f0 strbmi lr, [r8], -r0, ror #30
 *   @0x2ff700 ssatmi r9, #0xd, r8
 *   @0x2ff720 ldmdblt r10!, {r4, r5, r7, r9, sp}
 *   @0x2ff784 movwhs r8, #0xa1
 *   @0x2ff7ac strtmi pc, [r0], -r6, asr #23
 *   @0x2ff7b4 stmdavs r2!, {r0, r1, r3, r5, r6, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2ff7fc .word 0x932630b4
 *   @0x2ff808 .word 0x932830bc
 *   @0x2ff83c blls 0xc83b44 <b2_toiTime+0x52a6a0>
 *   @0x2ff850 .word 0xf8d120bc
 *   @0x2ff854 streq r5, [sp, r0, asr #5]!
 *   @0x2ff85c .word 0x63e60600
 *   @0x2ff87c ldrtmi pc, [r9], -r6, asr #21
 *   @0x2ff898 .word 0xf8d400b4
 *   @0x2ff89c .word 0xf7f900b8
 *   @0x2ff8a0 .word 0x4639fab4
 *   @0x2ff8b4 .word 0xf8d400bc
 *   @0x2ff8b8 .word 0xf7f900c0
 *   @0x2ff8bc .word 0xf8c4faa6
 *   @0x2ff8c0 movwhs r0, #0xc0
 *   @0x2ff8cc qasxmi pc, r0, r6
 *   @0x2ff8d4 rfeib r4!
 *   @0x2ff8d8 blhs 0x30b960 <af_shaper_get_elem+0x11ce>
 *   @0x2ff8f0 .word 0xf8db8477
 *   @0x2ff8f4 strtmi r3, [r0], -r12, lsl #4
 *   @0x2ff904 svchi #0x6e0a4c
 *   @0x2ff910 strbmi r0, [r11], #-2503
 *   @0x2ff91c blvs 0xffd8e930 <b2_toiTime+0xffffffffff63548c>
 *   @0x2ff928 andshs r0, r0, #3
 *   @0x2ff93c andshs r0, r8, #3
 *   @0x2ff958 stcvs p0, c8, [r11], #-28
 *   @0x2ff960 stcvs p0, c8, [r11], #-4
 *   @0x2ff968 stcvs p0, c8, [r11], #-8
 *   @0x2ff970 ldcne p0, c8, [r11, #-12]!
 *   @0x2ff978 ldrhlt r2, [r10, #44]!
 *   @0x2ff980 .word 0xd1450702
 *   @0x2ff988 andlo r2, r4, #128
 *   @0x2ff998 blvs 0xffd4bbb0 <b2_toiTime+0xffffffffff5f270c>
 *   @0x2ff9a4 stcvs p0, c0, [r11], #-560
 *   @0x2ff9b0 .word 0xf8c47098
 *   @0x2ff9b4 .word 0xf5b63094
 *   @0x2ff9b8 eor lr, r9, r2, lsl #28
 *   @0x2ff9c4 .word 0xf7ffc00c
 *   @0x2ff9c8 stmdavs r3!, {r0, r5, r6, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2ffa08 stmdahs r0, {r4, r5, r7, r12, sp}
 *   @0x2ffa28 bl 0x38d234 <_ZTS7CBucketILj16384ELj262144ELb1EE+0x1290>
 *   @0x2ffa2c ldrmi r0, [r0, #0x806]
 *   @0x2ffa44 .word 0xf8560c08
 *   @0x2ffa48 .word 0xf7f90c04
 *   @0x2ffa4c .word 0x4632f9de
 *   @0x2ffa6c .word 0xf1040003
 *   @0x2ffa70 stm r10, {r2, r4, r5, r7, r8, r9}
 *   @0x2ffa74 blvs 0xffd7fa88 <b2_toiTime+0xffffffffff6265e4>
 *   @0x2ffa9c .word 0xd1080102
 *   @0x2ffac0 orrs pc, r3, #6912
 *   @0x2ffac8 .word 0xf8db8389
 *   @0x2ffacc .word 0xf104a064
 *   @0x2ffad0 .word 0xf8d408cc
 *   @0x2ffad4 blls 0x523e0c <SrcVerts+0x80e50>
 *   @0x2ffae4 ldrb r9, [r7, r4]!
 *   @0x2ffaec ldrshlt r3, [r3, -pc]
 *   @0x2ffafc .word 0xb108ff08
 *   @0x2ffb0c and r6, sp, r8
 *   @0x2ffb18 blls 0x8fe738 <b2_toiTime+0x1a5294>
 *   @0x2ffb50 strls r3, [lr, #-0x20c]
 *   @0x2ffb58 bhs 0x308650 <TT_New_Context+0x8448>
 *   @0x2ffb64 usaxmi r0, r0, r12
 *   @0x2ffb70 addslt r9, sp, #4
 *   @0x2ffb7c .word 0xf8ad308a
 *   @0x2ffb80 andslt r3, r11, #136
 *   @0x2ffb8c bls 0x8fe594 <b2_toiTime+0x1a50f0>
 *   @0x2ffba0 smlabbhs r1, r10, r0, r3
 *   @0x2ffbb0 stm sp, {r1, r4, r6, r7, pc}
 *   @0x2ffbb4 ldrbmi r0, [r0], -r4, lsl #4
 *   @0x2ffbc0 bls 0x8fe560 <b2_toiTime+0x1a50bc>
 *   @0x2ffbc8 stmdbls r5, {r1, r2, r6, r7, pc}
 *   @0x2ffbdc andlt r0, r11, #8, #28
 *   @0x2ffc0c blx 0xac3720 <b2_toiTime+0x36a27c>
 *   @0x2ffc10 .word 0xf845f981
 *   @0x2ffc14 stcvs p0, c2, [r2], #204
 *   @0x2ffc20 .word 0xf8080e02
 *   @0x2ffc24 .word 0xf8202003
 *   @0x2ffc28 blx 0xac3c7c <b2_toiTime+0x36a7d8>
 *   @0x2ffc2c stclvs p14, c15, [r1], #568
 *   @0x2ffc40 .word 0xf8081004
 *   @0x2ffc44 .word 0xf8202003
 *   @0x2ffc48 .word 0xf109e013
 *   @0x2ffc4c .word 0xf8d40e02
 *   @0x2ffc50 blx 0xac3f28 <b2_toiTime+0x36aa84>
 *   @0x2ffc54 blx 0x6ff694 <g_SWFvertbuff+0x2c5cc>
 *   @0x2ffc58 .word 0xf845f38e
 *   @0x2ffc5c bl 0x443d30 <g_RomDisk+0x4c510>
 *   @0x2ffc60 .word 0xf8d40cc3
 *   @0x2ffc64 .word 0xf8cc10b8
 *   @0x2ffc68 .word 0xf1091004
 *   @0x2ffc6c .word 0xf8080103
 *   @0x2ffc70 blx 0xac7c84 <b2_toiTime+0x36e7e0>
 *   @0x2ffc74 .word 0xf820fc81
 *   @0x2ffc78 .word 0xf8d4e013
 *   @0x2ffc7c blx 0x6c3f74 <g_SWFlinevertbuff+0x70eac>
 *   @0x2ffc80 .word 0xf845f38c
 *   @0x2ffc84 bl 0x443d58 <g_RomDisk+0x4c538>
 *   @0x2ffc88 .word 0xf8d40ec3
 *   @0x2ffc8c .word 0xf8ce10c0
 *   @0x2ffc90 ldrtmi r1, [r1], -r4
 *   @0x2ffc9c eorls r12, r5, r3, lsl r0
 *   @0x2ffca4 strls r3, [r3, #-0x8a]!
 *   @0x2ffcec bl 0x46fdb8 <g_RomDisk+0x78598>
 *   @0x2ffcf0 .word 0xf8c403c1
 *   @0x2ffcf4 ldmdavs r11, {r2, r6, lr, pc} ^
 *   @0x2ffd18 .word 0xf8de10b4
 *   @0x2ffd1c .word 0xf04f0004
 *   @0x2ffd20 blx 0x78358a <b2_toiTime+0x2a0e6>
 *   @0x2ffd24 .word 0xf8c4e203
 *   @0x2ffd28 stmne r11!, {r3, r4, r5, r7}
 *   @0x2ffd30 ldmdavs r11, {r2, r3, r4, r5, r7, sp} ^
 *   @0x2ffd48 ldrbeq r3, [sp], r0, asr #5
 *   @0x2ffd50 .word 0xf8c40102
 *   @0x2ffd54 .word 0x465010b0
 *   @0x2ffd5c ldrbmi pc, [r0], -r12, ror #21
 *   @0x2ffd68 ldrbmi pc, [r0], -r6, ror #21
 *   @0x2ffd7c stmdbvs r3!, {r0, r1, r2, r4, r5, r9, pc}
 *   @0x2ffd94 shasxmi pc, r9, r10
 *   @0x2ffd9c .word 0xf7f900b4
 *   @0x2ffda0 stmdbls r6, {r2, r4, r5, r11, r12, sp, lr, pc}
 *   @0x2ffdb4 .word 0xf8d400b8
 *   @0x2ffdb8 .word 0xf7f900bc
 *   @0x2ffdbc stmdbls r6, {r1, r2, r5, r11, r12, sp, lr, pc}
 *   @0x2ffdd4 andle r6, r6, r0, lsl #11
 *   @0x2ffddc stmvs r3!, {r0, r2, r3, r7, r9, r11, r12, sp, lr, pc}
 *   @0x2ffe20 ldcls p0, c8, [r0, #-900]
 *   @0x2ffe48 strls r0, [r7, #-0x544]
 *   @0x2ffe54 stcge p0, c0, [r4, #-12]!
 *   @0x2ffe60 stcge p0, c0, [r6, #-12]!
 *   @0x2ffe6c ldm r12, {r0, r1}
 *   @0x2ffe70 blvs 0xffc3fe84 <b2_toiTime+0xffffffffff4e69e0>
 *   @0x2ffe88 qadd16mi r5, r0, r6
 *   @0x2ffeb8 ldm r2, {r0, r1}
 *   @0x2ffebc blls 0x53fed0 <obj_has_event+0x5360>
 *   @0x2ffedc bls 0x4441a4 <g_RomDisk+0x4c984>
 *   @0x2ffef0 andsls r0, lr, #1342177292
 *   @0x2fff00 andle r0, r6, r8, asr #7
 *   @0x2fff08 movwls r0, #0x3110
 *   @0x2fff44 ldmdavs r7, {r3, r4, r5} ^
 *   @0x2fff54 .word 0xd1020f00
 *   @0x2fff74 strtmi pc, [r9], -r2, lsl #17
 *   @0x2fff88 strmi pc, [r7], -r0, asr #30
 *   @0x2fff9c .word 0xf7f88008
 *   @0x2fffa0 .word 0x4641ff34
 *   @0x2fffcc andhs pc, r0, #176128
 *   @0x2fffec ldcls p2, c0, [r2, #-8]
 *
 * ══ §4/7 anonT_2fb894  0x2fb894  size 3156  201 条（0x2fb894..0x2fc4e8）｜其中 588 条已由别的卡落锚，本节不再重复
 * @func 0x2fb8b4 0x2fc4e8  size 3124  201 条
 * 部分覆盖: 本节 201/1397 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_realloc×3 / FT_Stream_GetUShort×3 / FT_DivFix×2 / FT_Stream_Pos×2 / ft_mem_alloc×2 / FT_Stream_EnterFrame×2 / 0x5bbe6c×2 / anonT_2fb894+0x78
 * 字段偏移 top8: 0xc×15 / 0x8×14 / 0x10×11 / 0x4×9 / 0x24×9 / 0x28×7 / 0x18×6 / 0x-8×5
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2fb8b4 .word 0xf8520033
 *   @0x2fb8b8 adcsmi r6, r0, #49
 *   @0x2fb8e0 strmi r10, [r8, #0x33]
 *   @0x2fb918 stmible r12!, {r3, r8, r9, r10} ^
 *   @0x2fb958 blne 0xfe2fb990 <b2_toiTime+0xfffffffffdba24ec>
 *   @0x2fb970 ldmible r11, {r3, r8, r9, r10} ^
 *   @0x2fb978 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2fb97c strhs r4, [r0], #-4087
 *   @0x2fb9a4 .word 0xf8550b84
 *   @0x2fb9a8 .word 0xf8531c0c
 *   @0x2fb9ac addmi r0, r8, #36
 *   @0x2fb9b4 addsmi r3, r8, #20, #24
 *   @0x2fb9c4 addsmi r3, r10, #16, #24
 *   @0x2fb9cc bne 0xff302a24 <b2_toiTime+0xfffffffffeba9580>
 *   @0x2fb9d4 submi pc, r0, #112, #20
 *   @0x2fb9ec strlo r9, [r1], #-11
 *   @0x2fb9f8 addsmi r3, pc, #0
 *   @0x2fba00 strlo r2, [r1, -r7, lsr #32]
 *   @0x2fba08 orrslt r4, r4, #28
 *   @0x2fba24 ldmdavs r0!, {r2, r10, r11, r12}
 *   @0x2fba94 svcge #0x88254
 *   @0x2fbabc and r8, r10, r3, lsr #5
 *   @0x2fbae4 strmi r7, [r1], r0, lsl #3
 *   @0x2fbaec .word 0x9009f9f3
 *   @0x2fbaf4 rfeia sp!
 *   @0x2fbaf8 .word 0xf10d3038
 *   @0x2fbafc stmdals r4, {r2, r5, r11}
 *   @0x2fbb08 movwls r3, #0x7032
 *   @0x2fbb14 blhs 0x2fc5fc <ps_hints_apply+0xb1fc>
 *   @0x2fbb2c adcseq pc, r9, r7, lsl #22
 *   @0x2fbb54 .word 0xf8d48257
 *   @0x2fbb58 .word 0xf10022b8
 *   @0x2fbb5c sbcsvs r0, r0, r4, lsl r1
 *   @0x2fbb6c strdvs r3, r4, [r2], #-47
 *   @0x2fbb74 blx 0x303c46 <TT_New_Context+0x3a3e>
 *   @0x2fbb78 .word 0x612a1202
 *   @0x2fbb84 stmdbvs r9!, {r0, r1, r12, sp, lr, pc}
 *   @0x2fbbbc shasxmi r1, r0, r0
 *   @0x2fbbc4 andls pc, r9, r0, ror lr
 *   @0x2fbbcc .word 0xf8df821b
 *   @0x2fbbd0 .word 0xf10da1ac
 *   @0x2fbbd4 stmvs r11!, {r2, r3, r4, r5, r8, r9, r11} ^
 *   @0x2fbbe0 rfeia sp!
 *   @0x2fbbe4 ldrbmi lr, [r1, #0x32]!
 *   @0x2fbbf4 blls 0x3ba1b8 <error_g0017+0x12e5c>
 *   @0x2fbc04 cdpeq p12, #0x1, c2, c2, c8, #0x0
 *   @0x2fbc0c ldmdbls r1, {r2, r4, r10, r11, r12}
 *   @0x2fbc18 rfeia sp!
 *   @0x2fbc1c .word 0xf843104e
 *   @0x2fbc20 .word 0xf8531c04
 *   @0x2fbc24 andvc r1, r10, r8, lsl r12
 *   @0x2fbc34 .word 0xf8532c18
 *   @0x2fbc38 beq 0x542c60 <g_DecodeStringBuffer+0x1ec>
 *   @0x2fbc40 .word 0xf8532c18
 *   @0x2fbc44 sbcsvc r1, r1, r8, lsl #24
 *   @0x2fbc50 .word 0xf8532c10
 *   @0x2fbc54 addsmi r1, r1, #20, #24
 *   @0x2fbc5c addmi r1, r10, #12, #24
 *   @0x2fbc64 .word 0xf8432c14
 *   @0x2fbc68 .word 0xf1092c0c
 *   @0x2fbc6c tstlo r8, #16384
 *   @0x2fbc74 andhs r9, r0, #184, #4
 *   @0x2fbc8c blhs 0x2fbce4 <ps_hints_apply+0xa8e4>
 *   @0x2fbc9c mrcvc p2, #0x0, r3, c11, c8, #0x5
 *   @0x2fbcac b 0x16be0b4 <b2_toiTime+0xf64c10>
 *   @0x2fbcb0 blls 0x47eac4 <targetStr+0x3884>
 *   @0x2fbcd0 rfeia sp!
 *   @0x2fbcd4 ldrmi r3, [r9, #0x36]
 *   @0x2fbcdc .word 0xf1bb1032
 *   @0x2fbce0 svclt #0xc0f00
 *   @0x2fbcec .word 0xf7ec0181
 *   @0x2fbcf0 .word 0x4603f898
 *   @0x2fbd0c .word 0xf858fe72
 *   @0x2fbd10 blls 0x386d48 <_ZTS13C_UTF16String+0x1ddf4>
 *   @0x2fbd24 blls 0x3bb794 <error_g0017+0x14438>
 *   @0x2fbd2c movwlo r0, #0x1023
 *   @0x2fbd34 andle r0, r4, r0, lsl #30
 *   @0x2fbd3c .word 0xf848fe5a
 *   @0x2fbd40 .word 0xf8580c04
 *   @0x2fbd44 ldrbmi r2, [r3], -r12, lsl #24
 *   @0x2fbd64 .word 0xf7ec0a83
 *   @0x2fbd68 ldr pc, [r2, r7, lsr #17]!
 *   @0x2fbd88 .word 0xf10d921c
 *   @0x2fbd8c strtmi r0, [r0], -r8, lsr #16
 *   @0x2fbd98 .word 0x47b06078
 *   @0x2fbda0 .word 0xf8d98135
 *   @0x2fbda4 qsub16mi r6, r0, r8
 *   @0x2fbdb4 cdpvs p1, #0xa, c8, c5, c13, #0x1
 *   @0x2fbdbc ldrtmi r6, [r11], -r4, lsl #4
 *   @0x2fbdd4 .word 0x462880b4
 *   @0x2fbddc .word 0x4631fdb1
 *   @0x2fbdf0 strtmi r8, [r8], -r6, lsr #1
 *   @0x2fbdf8 mulls r10, r11, sp
 *   @0x2fbe00 svchs #0x1809e
 *   @0x2fbe10 .word 0xf8c8f98a
 *   @0x2fbe14 blls 0x57befc <g_SWFlineaavertbuff+0x28e34>
 *   @0x2fbe1c qadd8mi r8, r8, r0
 *   @0x2fbe24 andls pc, r10, r5, lsl #27
 *   @0x2fbe2c strtmi r8, [r8], -r8, lsl #1
 *   @0x2fbe34 .word 0xf7ea7038
 *   @0x2fbe38 eorshi pc, r8, r5, ror #28
 *   @0x2fbe48 blls 0x5bb7c4 <g_SWFlineaavertbuff+0x686fc>
 *   @0x2fbe68 strmi pc, [r2], -r10, lsr #22
 *   @0x2fbe74 .word 0x4648a038
 *   @0x2fbe7c stm sp, {r12, sp}
 *   @0x2fbe80 .word 0xf7ec0044
 *   @0x2fbe84 .word 0xf8caf904
 *   @0x2fbe88 blls 0x57bef0 <g_SWFlineaavertbuff+0x28e28>
 *   @0x2fbea0 qasxmi r3, r8, r8
 *   @0x2fbeb4 .word 0xf04f7038
 *   @0x2fbeb8 ldmibvs lr!, {r2, r3, r8, r11}
 *   @0x2fbec0 strlo r6, [r12], -r3, lsl #18
 *   @0x2fbed0 .word 0xf846fdc4
 *   @0x2fbed4 strtmi r0, [r8], -r12, lsl #24
 *   @0x2fbee4 rfeda r6!
 *   @0x2fbee8 .word 0xf8262c08
 *   @0x2fbeec ldmdavs r11!, {r1, r2, r10, r11} ^
 *   @0x2fbf08 blls 0x5bbe6c <g_SWFlineaavertbuff+0x68da4>
 *   @0x2fbf10 .word 0x260c3038
 *   @0x2fbf34 vst1.64 {d19, d20, d21, d22}, [r3], r0
 *   @0x2fbf38 .word 0xf8c47380
 *   @0x2fbf3c blls 0x448a44 <g_RomDisk+0x51224>
 *   @0x2fbf50 cdpls p8, #0x0, c15, c9, c10, #0x7
 *   @0x2fbf5c ldmvs r9, {r3, r4, r5, r7, r9, r12, sp} ^
 *   @0x2fbf64 stmdavs r10!, {r2, r3, r5, r8, r9, r11, sp, lr, pc}
 *   @0x2fbf7c ldrtmi r1, [r3], -r3, lsl #2
 *   @0x2fbf88 stmdbvs r8!, {r0, r1, r10, r12, sp, lr, pc}
 *   @0x2fbf94 ldrb r0, [r3, r0, lsl #3]!
 *   @0x2fbfac ldrbtmi r10, [r8], #196
 *   @0x2fbfd8 and r11, lr, r8, lsl r12
 *   @0x2fbfec and r9, r4, r8, lsl r12
 *   @0x2fbff8 andlo r8, r1, #24, #24
 *   @0x2fc014 qsub16mi r12, r0, r8
 *   @0x2fc024 rfeia sp!
 *   @0x2fc028 andhs r3, r12, #54
 *   @0x2fc040 addmi r1, r11, #50
 *   @0x2fc084 .word 0x460512b8
 *   @0x2fc094 strhlt r3, [r1, #-37]!
 *   @0x2fc0b4 andls pc, r10, r1, ror #25
 *   @0x2fc0d0 .word 0xf5022023
 *   @0x2fc0d4 .word 0xf5b13180
 *   @0x2fc0d8 ldmible r0!, {r8, r9, r10, r11, r12, sp} ^
 *   @0x2fc0e4 strhlt r3, [r3, -r4]!
 *   @0x2fc118 stmibmi r0!, {r0, r1, r4, r10, r11, r12, sp, lr, pc}
 *   @0x2fc134 blls 0x65c400 <g_SWFlinevertbuff+0x9338>
 *   @0x2fc148 stmdahi r9, {r3, r4, r5, r12, sp}
 *   @0x2fc160 rfeia sp!
 *   @0x2fc164 .word 0xf0163040
 *   @0x2fc168 svclt #0xc0f01
 *   @0x2fc1cc blls 0x3fb2ec <g_RomDisk+0x3acc>
 *   @0x2fc1e0 andls pc, r11, r0, lsr #28
 *   @0x2fc210 blvs 0xffbfbb64 <b2_toiTime+0xffffffffff4a26c0>
 *   @0x2fc224 blx 0x3bc33e <error_g0017+0x14fe2>
 *   @0x2fc228 .word 0xf7ebf30e
 *   @0x2fc22c blls 0x5fbef4 <g_SWFaavertbuff+0x28e2c>
 *   @0x2fc240 andls pc, r11, r2, lsr r11
 *   @0x2fc24c subeq r3, r9, r8, lsr r0
 *   @0x2fc254 andls pc, r11, r6, ror #27
 *   @0x2fc27c bls 0x43b16c <g_RomDisk+0x4394c>
 *   @0x2fc288 strb r0, [r11, r3, lsr #32]!
 *   @0x2fc2a0 .word 0xe123af23
 *   @0x2fc2b0 .word 0xf7eb3000
 *   @0x2fc2b4 blls 0x5bbe6c <g_SWFlineaavertbuff+0x68da4>
 *   @0x2fc2e0 strhs r8, [r1], -r5, lsl #2
 *   @0x2fc2e8 .word 0xf85a0023
 *   @0x2fc2ec addmi r1, r8, #35
 *   @0x2fc300 addmi r0, r3, #0
 *   @0x2fc308 stmdblt r9, {r0, r1, r5, r12}
 *   @0x2fc314 ldrbmi r3, [r1], -r0
 *   @0x2fc31c eorvs r0, r3, r8, lsl #5
 *   @0x2fc330 stmdbhs r0, {r0, r2, r4, r5, r7, r9, r12, sp}
 *   @0x2fc33c .word 0xf89532b8
 *   @0x2fc340 stmvs r0!, {r0, r2, r4, r5, r7, r9, sp}
 *   @0x2fc348 ldrmi r9, [r8, #0x4]!
 *   @0x2fc358 andhs r0, r0, #2160
 *   @0x2fc364 andlo r1, r4, #2
 *   @0x2fc370 andlo r1, r1, #34
 *   @0x2fc380 andlo r1, r1, #34
 *   @0x2fc394 subs r0, r5, r8, lsl r8
 *   @0x2fc3e8 movwls r0, #0x310e
 *   @0x2fc3f0 .word 0xf7e8020c
 *   @0x2fc3f4 .word 0xf858fca3
 *   @0x2fc3f8 .word 0xf8522c04
 *   @0x2fc3fc ldrmi r2, [r0], #-58
 *   @0x2fc420 stmdahs r0, {r2, r8, r9, r11}
 *   @0x2fc428 .word 0xf858bc10
 *   @0x2fc42c bl 0xff343484 <b2_toiTime+0xfffffffffebe9fe0>
 *   @0x2fc430 .word 0xf7fc010b
 *   @0x2fc434 ldrbmi pc, [r8], #-3306
 *   @0x2fc45c .word 0xf8493c10
 *   @0x2fc460 strb r3, [r11, r4, lsl #24]!
 *   @0x2fc470 movwhs pc, #0xf62
 *   @0x2fc478 mcrvs p2, #0x5, r3, c9, c8, #0x4
 *   @0x2fc488 andls pc, r10, r7, lsr #21
 *   @0x2fc490 movwhs r12, #0x8
 *   @0x2fc4a0 blx 0x3bfec2 <error_g0017+0x18b66>
 *   @0x2fc4a4 andhs r2, r0, #14, #28
 *   @0x2fc4cc rsbvs r4, r10, r3, lsl #4
 *   @0x2fc4dc .word 0xf88512a8
 *   @0x2fc4e0 .word 0xf7ea72bc
 *   @0x2fc4e4 movwhs pc, #0xf28
 *
 * ══ §5/7 anonT_309b08  0x309b08  size 2996  179 条（0x309b08..0x30a6bc）｜其中 570 条已由别的卡落锚，本节不再重复
 * @func 0x309b20 0x30a6a4  size 2948  179 条
 * 部分覆盖: 本节 179/1299 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574×4 / FT_DivFix×3 / af_shaper_get_coverage×2 / 0xb65b0×2 / anonT_309b08×2 / anon_300274+0x7038×2 / anonT_309b08+0x8cc×2 / 0x448730
 * 字段偏移 top8: 0x4×20 / 0x2c×10 / 0x34×9 / 0xc×8 / 0x8×7 / 0x28×7 / 0x10×6 / 0x14×6
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x309b20 blls 0x448730 <g_RomDisk+0x50f10>
 *   @0x309b30 stmdbvs r9!, {r1, r2, r3, r4, r5, r7, r10, r12, sp, lr}
 *   @0x309b38 subvs r6, r1, r8, ror r1
 *   @0x309b64 movwlo r0, #0x1243
 *   @0x309b74 bllt 0x2149678 <b2_toiTime+0x19f01d4>
 *   @0x309b80 and r0, r9, r4, lsl r8
 *   @0x309ba0 ldrmi r1, [r9], r6, lsr #32
 *   @0x309bac stmdbhs r0, {r2, r8, r9, r10, r11, r12}
 *   @0x309bb8 strtmi r1, [r2], -r11, lsr #32
 *   @0x309bc0 ldrths pc, [r0], -r1, lsr #31
 *   @0x309bd0 .word 0x36018094
 *   @0x309be8 umulls r8, r7, r5, r0
 *   @0x309bf4 .word 0xf1031178
 *   @0x309bf8 .word 0xf6430908
 *   @0x309bfc stmdbvs r9, {r0, r1, r2, r3, r4, r5, r6, r7, r9, r11, r12, sp, lr}
 *   @0x309c08 .word 0xb36a2c08
 *   @0x309c14 bls 0x3496b0
 *   @0x309c24 vmov.i32 d17, #0x90
 *   @0x309c28 ldrbmi r0, [r1, #-0x10d]
 *   @0x309c30 sadd16mi r6, r1, r0
 *   @0x309c44 addmi r0, r2, #4, #24
 *   @0x309c64 strb r0, [lr, r8, lsl #18]
 *   @0x309c80 andls pc, r5, pc, ror #28
 *   @0x309ca8 blls 0x489658 <g_States+0x3c90>
 *   @0x309cc0 vmov.i32 d18, #0xa3
 *   @0x309cc4 adcsmi r0, r1, #1073741827
 *   @0x309ccc .word 0xf8244280
 *   @0x309cd0 .word 0xe7e52013
 *   @0x309cec shsaxmi r10, r8, lr
 *   @0x309d00 rfeda r4!
 *   @0x309d04 b 0x1ed5d4c <b2_toiTime+0x177c8a8>
 *   @0x309d08 b 0x1edaa1c <b2_toiTime+0x1781578>
 *   @0x309d0c .word 0xf8244353
 *   @0x309d10 smmla lr, r0, r0, r3
 *   @0x309d74 .word 0xf10d764c
 *   @0x309d78 vldmdbge r2!, {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16, d17, d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28, d29, d30, d31}
 *   @0x309d88 .word 0xf10d22c8
 *   @0x309d8c ldrbmi r0, [r8], -r8, lsl #19
 *   @0x309d98 .word 0x2100ec0c
 *   @0x309da0 .word 0xf1a96c08
 *   @0x309da4 strtmi r0, [r8], -r4, lsl #10
 *   @0x309db0 .word 0x2100b008
 *   @0x309dc8 strls r8, [r10, -r8, lsr #32]
 *   @0x309dd0 strls r12, [pc, -r8]
 *   @0x309de4 stmdavs r9, {r3, lr, pc}
 *   @0x309df0 .word 0xf00a3004
 *   @0x309df4 addsmi r0, r3, #-268435456
 *   @0x309dfc .word 0xf00a0c0c
 *   @0x309e00 .word 0xf8c8030f
 *   @0x309e04 .word 0xf1083004
 *   @0x309e08 ldm r12!, {r3, r9, r10, r11}
 *   @0x309e0c stm lr!, {r0, r1, r2, r3}
 *   @0x309e10 ldm r12, {r0, r1, r2, r3}
 *   @0x309e14 stm lr, {r0, r1, r2}
 *   @0x309e18 .word 0xf8d80007
 *   @0x309e1c svcls #0x1300c
 *   @0x309e60 ldrbtmi r3, [r11], #-1380
 *   @0x309e68 .word 0xf1a48004
 *   @0x309e6c movwhs r0, #0x710
 *   @0x309e74 svcls #0xb3c10
 *   @0x309ed8 svcls #0x4a017
 *   @0x309eec .word 0xf8dfc02a
 *   @0x309ef0 .word 0xf8dc34d8
 *   @0x309ef4 ldmpl r11!, {r2, sp} ^
 *   @0x309f04 .word 0xf1baa010
 *   @0x309f08 .word 0xd1bd0f00
 *   @0x309f18 ldrmi r12, [r8], -r8
 *   @0x309f20 blls 0x8c8330 <b2_toiTime+0x16ee8c>
 *   @0x309f50 .word 0xe799f9f2
 *   @0x309f58 .word 0x46ca9010
 *   @0x309f78 stmdals r1, {r1, r2, r4, r6, r7, r8, r12, lr}
 *   @0x309f88 .word 0xf0425220
 *   @0x309f8c .word 0xf7dd0201
 *   @0x309f90 andls pc, r4, r9, ror #21
 *   @0x309f98 stmdbvs r3!, {r0, r9, pc} ^
 *   @0x309fa4 svcls #0x180ba
 *   @0x309fc0 svcls #0x180ac
 *   @0x309fdc movwhs r9, #0x28
 *   @0x30a004 blmi 0xfffc9d6c <b2_toiTime+0xffffffffff8708c8>
 *   @0x30a01c rfeia r7!
 *   @0x30a020 blhs 0x316138 <FT_Bitmap_Embolden+0x12f2>
 *   @0x30a028 svcls #0x113000
 *   @0x30a030 ldmdbvs r11, {r0, r1, r5, r12, sp} ^
 *   @0x30a040 ldmdbge r4, {r0, r8, r9, r10}
 *   @0x30a054 blhs 0x3190bc <__aeabi_dadd+0x2a4>
 *   @0x30a078 stmdbls r8, {r0, r3, r4, r8, r11, r12, sp, lr, pc}
 *   @0x30a098 svchs #0x16c
 *   @0x30a0a0 stmdbls r1, {r3, r4, r10, r11, sp}
 *   @0x30a0a8 .word 0xf8d9fe53
 *   @0x30a0ac streq r1, [r7], #-16
 *   @0x30a0b4 stmdbls r8, {r0, r1, r3, r4, r5, r6, r7, r11, r12, sp, lr, pc}
 *   @0x30a0d4 .word 0xf1c70170
 *   @0x30a0d8 svcls #0x6407f
 *   @0x30a0f0 addsmi r2, r3, #104, #2
 *   @0x30a108 .word 0xf8d8fab3
 *   @0x30a10c shsub16mi r3, r8, r4
 *   @0x30a114 .word 0xf7dc3c04
 *   @0x30a118 svcls #0xafa33
 *   @0x30a124 .word 0xf10d030c
 *   @0x30a128 .word 0xf10d0e98
 *   @0x30a12c blgt 0x6cc3d4 <g_SWFlinevertbuff+0x7930c>
 *   @0x30a13c stm r8, {r0, r1}
 *   @0x30a140 ldm lr, {r0, r1}
 *   @0x30a144 stm r7, {r0, r1, r2, r3}
 *   @0x30a148 ldmdage r6, {r0, r1, r2, r3}
 *   @0x30a158 ldcvs p9, c15, [r2], #988
 *   @0x30a164 .word 0xf0400714
 *   @0x30a168 stcvc p0, c8, [r11], #-588
 *   @0x30a170 bvs 0x1d4a328 <b2_toiTime+0x15f0e84>
 *   @0x30a178 .word 0xf8dbf955
 *   @0x30a17c ldmdbls r1!, {r3, r12, sp}
 *   @0x30a184 .word 0x632b3010
 *   @0x30a18c .word 0xf8dbf88f
 *   @0x30a190 ldrmi r3, [r8], #-8
 *   @0x30a1a8 .word 0xf1bcc01c
 *   @0x30a1ac andle r0, r4, r0, lsl #30
 *   @0x30a1e8 .word 0xf1ae0f17
 *   @0x30a1ec .word 0xf8de0e2c
 *   @0x30a1f0 .word 0xf8de2004
 *   @0x30a1f4 bl 0xff39621c <b2_toiTime+0xfffffffffec3cd78>
 *   @0x30a1f8 bl 0xff60a200 <b2_toiTime+0xfffffffffeeb0d5c>
 *   @0x30a1fc svclt #0xd80208
 *   @0x30a20c svclt #0xd8093f
 *   @0x30a22c .word 0xf8c50940
 *   @0x30a230 .word 0xf8de902c
 *   @0x30a234 ldrbmi lr, [r1, #-0x8]!
 *   @0x30a248 blvs 0x1d92490 <b2_toiTime+0x1638fec>
 *   @0x30a254 .word 0xf0200020
 *   @0x30a258 .word 0xf103003f
 *   @0x30a25c rscvs r0, r8, #32, #4
 *   @0x30a26c ldrmi r0, [r10], #-2944
 *   @0x30a278 rscvs r0, r8, #63
 *   @0x30a28c mul r1, r4, r0
 *   @0x30a29c blvs 0xf8d304 <b2_toiTime+0x833e60>
 *   @0x30a2c4 .word 0xb14b0c14
 *   @0x30a2e8 shadd8mi pc, r8, sp
 *   @0x30a2f0 .word 0xf854f86d
 *   @0x30a2f4 .word 0xf8540c08
 *   @0x30a2f8 .word 0xf8543c04
 *   @0x30a2fc eorslo r2, pc, r0, lsl r12
 *   @0x30a308 .word 0xf023023f
 *   @0x30a30c .word 0xf021033f
 *   @0x30a310 .word 0xf020013f
 *   @0x30a314 .word 0xf844003f
 *   @0x30a318 .word 0xf8442c10
 *   @0x30a31c bne 0x1951354 <b2_toiTime+0x11f7eb0>
 *   @0x30a328 eorsvs r3, r2, #4, #24
 *   @0x30a334 strmi r1, [r10], #-3096
 *   @0x30a340 ldrmi r2, [r3], #-3092
 *   @0x30a35c .word 0xf7fc1008
 *   @0x30a360 movwhs pc, #0xfa5
 *   @0x30a380 .word 0xf7fc100c
 *   @0x30a384 bvs 0xff00a1d8 <b2_toiTime+0xfffffffffe8b0d34>
 *   @0x30a398 cmnvs r0, #63
 *   @0x30a3ac strbmi pc, [r0], -r9, lsl #20
 *   @0x30a3b8 svclt #0x8ff0
 *   @0x30a408 .word 0x43f7e92d
 *   @0x30a424 stmdblt r8, {r3, r5, r7, r11, sp, lr, pc} ^
 *   @0x30a430 stmdahs r0, {r0, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30a444 ldmdblt r8!, {r3, r4, r7, r11, sp, lr, pc}
 *   @0x30a450 ldmvs r11, {r0, r3, r5, r12, sp}
 *   @0x30a460 ldmdblt r0, {r1, r3, r7, r11, sp, lr, pc}
 *   @0x30a494 stmdblt r8, {r4, r5, r6, r11, sp, lr, pc}
 *   @0x30a4a4 stmiblt r0, {r3, r5, r6, r11, sp, lr, pc}
 *   @0x30a52c blhs 0x3165cc <FT_Bitmap_Embolden+0x1786>
 *   @0x30a554 stmdblt r8!, {r4, r11, sp, lr, pc}
 *   @0x30a55c stmdavs r3!, {r1, r2, r3, r4, r7, pc}
 *   @0x30a56c ldmdblt r0!, {r2, r11, sp, lr, pc} ^
 *   @0x30a574 stmdavs r0!, {r1, r4, r7, pc}
 *   @0x30a584 stmdavs r2!, {r0, r1, r3, r7, pc} ^
 *   @0x30a5c8 stmdahs r0, {r1, r2, r4, r6, r7, r8, r9, r10, r11, sp, lr, pc}
 *   @0x30a5e0 blls 0x384708 <_ZTS13C_UTF16String+0x1b7b4>
 *   @0x30a600 blls 0x3846e8 <_ZTS13C_UTF16String+0x1b794>
 *   @0x30a648 stmdale r6!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr}
 *   @0x30a654 stmdale r0!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr}
 *   @0x30a65c eorvs r12, r10, #28
 *   @0x30a674 strmi lr, [r7], -r0, lsl #31
 *   @0x30a684 stmdblt r8, {r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr, pc}
 *   @0x30a6a0 svclt #0x81f0
 *
 * ══ §6/7 anonT_2fa06c  0x2fa06c  size 708  37 条（0x2fa06c..0x2fa330）｜其中 140 条已由别的卡落锚，本节不再重复
 * @func 0x2fa088 0x2fa320  size 664  37 条
 * 部分覆盖: 本节 37/290 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_free×16 / anonT_2fa06c+0x132 / 0x1bf8394 / 0xfebfa03c / 0xfebf8360
 * 字段偏移 top8: 0x4×8 / 0x18×5 / 0xc×5 / 0x1c×5 / 0x34×5 / 0x14×4 / 0x10×4 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2fa088 strhvs r1, [r5, r8]!
 *   @0x2fa090 shsaxmi pc, r0, r2
 *   @0x2fa0d0 shasxmi pc, r0, r2
 *   @0x2fa0e4 ldrtmi pc, [r0], -r8, lsr #18
 *   @0x2fa0f8 .word 0x6165f91e
 *   @0x2fa110 cdpvs p1, #0x5, c0, c14, c12, #0x1
 *   @0x2fa118 movwhs pc, #0xfa9
 *   @0x2fa124 strhs r1, [r0, #-0xfc]
 *   @0x2fa134 .word 0xf8c450fc
 *   @0x2fa138 .word 0xf7ed50f8
 *   @0x2fa13c .word 0xf504f8fc
 *   @0x2fa140 .word 0xf8c47084
 *   @0x2fa144 .word 0xf8a45104
 *   @0x2fa148 .word 0xf7ff5100
 *   @0x2fa14c .word 0x4630ffb9
 *   @0x2fa160 .word 0xf7ed1090
 *   @0x2fa164 .word 0xf04ff8e8
 *   @0x2fa168 .word 0xf8c433ff
 *   @0x2fa16c .word 0x67e55090
 *   @0x2fa194 movwhs pc, #0xfb9
 *   @0x2fa1a0 .word 0x460c41f0
 *   @0x2fa1cc stmdavs r3!, {r3, pc} ^
 *   @0x2fa1e8 movwhs pc, #0x8a6
 *   @0x2fa20c strlo r7, [r1, #-0x25]
 *   @0x2fa218 movwhs pc, #0x88e
 *   @0x2fa220 push {r4, r5, r6, r7, r8, pc}
 *   @0x2fa224 .word 0x460647f0
 *   @0x2fa24c qsub16mi pc, r8, r4
 *   @0x2fa260 stmibvs r3!, {r1, r3, r5, r6, r11, r12, sp, lr, pc} ^
 *   @0x2fa290 movwhs pc, #0x852
 *   @0x2fa2a0 bvs 0xfebfa0a0 <b2_toiTime+0xfffffffffe4a0bfc>
 *   @0x2fa2b8 bvs 0xfebf83b8 <b2_toiTime+0xfffffffffe49ef14>
 *   @0x2fa2c4 adcvs pc, r7, #56, #16
 *   @0x2fa2dc blvs 0x1bf8394 <b2_toiTime+0x149eef0>
 *   @0x2fa304 blvs 0xfebfa03c <b2_toiTime+0xfffffffffe4a0b98>
 *   @0x2fa310 blvs 0xfebf8360 <b2_toiTime+0xfffffffffe49eebc>
 *   @0x2fa31c .word 0x63a6f80c
 *
 * ══ §7/7 png_read_update_info  0x2a7448  size 48  3 条（0x2a7448..0x2a7478）｜其中 9 条已由别的卡落锚，本节不再重复
 * @func 0x2a7464 0x2a7474  size 16  3 条
 * 部分覆盖: 本节 3/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_read_start_row
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a7464 strtmi pc, [r0], -r7, lsl #16
 *   @0x2a746c .word 0xf0014038
 *   @0x2a7470 vldmdblt r8!, {s22, s23, s24, s25, s26, s27, s28, s29, s30, s31}
 */
