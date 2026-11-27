/* cally 逆向卡：Reach_03 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 19 个函数｜锚点 7496 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/19 RTree<CInstance*, int, float, 6, 2>::SplitNode  0x1ccd60  size 1788  447 条（0x1ccd60..0x1cd45c）
 * @func 0x1ccd60 0x1cd45c  size 1788  447 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_1cbc10+0xe4×4 / RTree<CInstance*, int, float, 6, 2>::SplitNode(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Branch const*, RTree<CInstance*, int, float, 6, 2>::Node**)+0x5a8×2 / RTree<CInstance*, int, float, 6, 2>::SplitNode(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Branch const*, RTree<CInstance*, int, float, 6, 2>::Node**)+0x21c / RTree<CInstance*, int, float, 6, 2>::SplitNode(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Branch const*, RTree<CInstance*, int, float, 6, 2>::Node**)+0x250 / RTree<CInstance*, int, float, 6, 2>::SplitNode(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Branch const*, RTree<CInstance*, int, float, 6, 2>::Node**)+0x510 / RTree<CInstance*, int, float, 6, 2>::SplitNode(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Branch const*, RTree<CInstance*, int, float, 6, 2>::Node**)+0x370 / RTree<CInstance*, int, float, 6, 2>::SplitNode(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Branch const*, RTree<CInstance*, int, float, 6, 2>::Node**)+0x57c / RTree<CInstance*, int, float, 6, 2>::SplitNode(RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Branch const*, RTree<CInstance*, int, float, 6, 2>::Node**)+0x644
 * 字段偏移 top8: 0x4×12 / 0xc×11 / 0x18×7 / 0x78×6 / 0x14×6 / 0x8×6 / 0x1c×5 / 0x10×4
 * VFP 指令 83 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ccd60 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ccd64 sub sp, sp, #372
 *   @0x1ccd68 add r11, sp, #92
 *   @0x1ccd6c add r7, sp, #236
 *   @0x1ccd70 mov r6, r2
 *   @0x1ccd74 mov r5, r1
 *   @0x1ccd78 mov r4, r11
 *   @0x1ccd7c str r1, [sp, #0x24]
 *   @0x1ccd80 str r0, [sp, #0x2c]
 *   @0x1ccd84 str r3, [sp, #0x30]
 *   @0x1ccd88 add lr, r5, #8
 *   @0x1ccd8c add r12, r4, #84
 *   @0x1ccd90 add r4, r4, #24
 *   @0x1ccd94 add r5, r5, #24
 *   @0x1ccd98 ldm lr!, {r0, r1, r2, r3}
 *   @0x1ccd9c cmp r4, r7
 *   @0x1ccda0 stm r12!, {r0, r1, r2, r3}
 *   @0x1ccda4 ldm lr, {r0, r1}
 *   @0x1ccda8 stm r12, {r0, r1}
 *   @0x1ccdac bne 0x1ccd88 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x28>
 *   @0x1ccdb0 ldm r6!, {r0, r1, r2, r3}
 *   @0x1ccdb4 add r5, sp, #320
 *   @0x1ccdb8 add r4, sp, #176
 *   @0x1ccdbc str r4, [sp, #0x20]
 *   @0x1ccdc0 add lr, sp, #200
 *   @0x1ccdc4 add r4, r11, #252
 *   @0x1ccdc8 mov r12, #7
 *   @0x1ccdcc str r12, [sp, #0x158]
 *   @0x1ccdd0 stm r5!, {r0, r1, r2, r3}
 *   @0x1ccdd4 mov r12, lr
 *   @0x1ccdd8 ldm r6, {r0, r1}
 *   @0x1ccddc stm r5, {r0, r1}
 *   @0x1ccde0 ldr r5, [sp, #0x20]
 *   @0x1ccde4 ldm r5, {r0, r1, r2, r3}
 *   @0x1ccde8 add r5, sp, #348
 *   @0x1ccdec stm r5, {r0, r1, r2, r3}
 *   @0x1ccdf0 mov r8, r0
 *   @0x1ccdf4 ldr r7, [sp, #0x164]
 *   @0x1ccdf8 ldr r6, [sp, #0x160]
 *   @0x1ccdfc ldr r5, [sp, #0x168]
 *   @0x1cce00 ldr r1, [r12]
 *   @0x1cce04 add r12, r12, #24
 *   @0x1cce08 ldr r0, [r12, #-0x10]
 *   @0x1cce0c ldr r3, [r12, #-0x14]
 *   @0x1cce10 cmp r1, r8
 *   @0x1cce14 movge r1, r8
 *   @0x1cce18 ldr r2, [r12, #-0xc]
 *   @0x1cce1c cmp r0, r7
 *   @0x1cce20 movlt r0, r7
 *   @0x1cce24 cmp r3, r6
 *   @0x1cce28 movge r3, r6
 *   @0x1cce2c mov r8, r1
 *   @0x1cce30 cmp r2, r5
 *   @0x1cce34 movlt r2, r5
 *   @0x1cce38 cmp r12, r4
 *   @0x1cce3c mov r6, r3
 *   @0x1cce40 mov r7, r0
 *   @0x1cce44 mov r5, r2
 *   @0x1cce48 str r1, [sp, #0x15c]
 *   @0x1cce4c str r3, [sp, #0x160]
 *   @0x1cce50 str r0, [sp, #0x164]
 *   @0x1cce54 str r2, [sp, #0x168]
 *   @0x1cce58 bne 0x1cce00 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0xa0>
 *   @0x1cce5c vmov s4, r0
 *   @0x1cce60 add r4, sp, #88
 *   @0x1cce64 vmov s8, r2
 *   @0x1cce68 str r4, [sp, #0x28]
 *   @0x1cce6c vcvt.f32.s32 s12, s4
 *   @0x1cce70 add r4, r11, #24
 *   @0x1cce74 vmov s4, r1
 *   @0x1cce78 add r0, sp, #88
 *   @0x1cce7c vmov s10, r3
 *   @0x1cce80 mvn r12, #0
 *   @0x1cce84 mov r5, #0
 *   @0x1cce88 mov r1, #2
 *   @0x1cce8c str r5, [sp, #0x84]
 *   @0x1cce90 str r5, [sp, #0x80]
 *   @0x1cce94 mov r5, #0
 *   @0x1cce98 str r1, [sp, #0x7c]
 *   @0x1cce9c vcvt.f32.s32 s14, s4
 *   @0x1ccea0 str r5, [sp, #0xac]
 *   @0x1ccea4 str r5, [sp, #0xa8]
 *   @0x1ccea8 mov r5, #7
 *   @0x1cceac str r5, [sp, #0x78]
 *   @0x1cceb0 vcvt.f32.s32 s13, s8
 *   @0x1cceb4 vcvt.f32.s32 s15, s10
 *   @0x1cceb8 vsub.f32 s14, s12, s14
 *   @0x1ccebc vsub.f32 s15, s13, s15
 *   @0x1ccec0 vmul.f32 s14, s14, s15
 *   @0x1ccec4 vstr s14, [sp, #364]
 *   @0x1ccec8 str r12, [r0, #0x4]!
 *   @0x1ccecc cmp r0, r4
 *   @0x1cced0 bne 0x1ccec8 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x168>
 *   @0x1cced4 add r2, sp, #64
 *   @0x1cced8 add r1, r11, #168
 *   @0x1ccedc mov r3, r11
 *   @0x1ccee0 vldr s15, [r3, #92]
 *   @0x1ccee4 vldr s13, [r3, #84]
 *   @0x1ccee8 vldr s11, [r3, #96]
 *   @0x1cceec vldr s12, [r3, #88]
 *   @0x1ccef0 vcvt.f32.s32 s10, s15
 *   @0x1ccef4 add r3, r3, #24
 *   @0x1ccef8 cmp r3, r1
 *   @0x1ccefc vcvt.f32.s32 s13, s13
 *   @0x1ccf00 vcvt.f32.s32 s11, s11
 *   @0x1ccf04 vcvt.f32.s32 s12, s12
 *   @0x1ccf08 vsub.f32 s13, s10, s13
 *   @0x1ccf0c vsub.f32 s15, s11, s12
 *   @0x1ccf10 vmul.f32 s15, s13, s15
 *   @0x1ccf14 vstmia r2!, {s15}
 *   @0x1ccf18 bne 0x1ccee0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x180>
 *   @0x1ccf1c vmov.f32 s15, #-1.000000e+00
 *   @0x1ccf20 mvn r5, #0
 *   @0x1ccf24 add r4, sp, #176
 *   @0x1ccf28 add r0, sp, #68
 *   @0x1ccf2c mov r12, #1
 *   @0x1ccf30 str r0, [sp, #0x14]
 *   @0x1ccf34 mov r6, #0
 *   @0x1ccf38 mov r0, r5
 *   @0x1ccf3c str lr, [sp, #0x18]
 *   @0x1ccf40 str r11, [sp, #0x34]
 *   @0x1ccf44 vsub.f32 s14, s15, s14
 *   @0x1ccf48 ldr r2, [sp, #0x18]
 *   @0x1ccf4c add r1, r6, #1
 *   @0x1ccf50 str r1, [sp, #0x1c]
 *   @0x1ccf54 ldr r10, [r4, #0x8]
 *   @0x1ccf58 ldr r11, [r2, #-0x18]
 *   @0x1ccf5c ldr r1, [sp, #0x14]
 *   @0x1ccf60 vldr s9, [r1, #-4]
 *   @0x1ccf64 ldr r9, [r4, #0x4]
 *   @0x1ccf68 ldr r2, [sp, #0x1c]
 *   @0x1ccf6c ldr r8, [r4, #0xc]
 *   @0x1ccf70 ldr r3, [sp, #0x18]
 *   @0x1ccf74 str r4, [sp, #0xc]
 *   @0x1ccf78 b 0x1ccfb0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x250>
 *   @0x1ccf7c vcmp.f32 s15, s14
 *   @0x1ccf80 add r3, r3, #24
 *   @0x1ccf84 vmrs APSR_nzcv, fpscr
 *   @0x1ccf88 movne lr, #0
 *   @0x1ccf8c andeq lr, r12, #1
 *   @0x1ccf90 cmp lr, #0
 *   @0x1ccf94 movne r5, r2
 *   @0x1ccf98 add r2, r2, #1
 *   @0x1ccf9c vmovne.f32 s14, s15
 *   @0x1ccfa0 movne r0, r6
 *   @0x1ccfa4 movne r12, #0
 *   @0x1ccfa8 cmp r2, #6
 *   @0x1ccfac bgt 0x1cd048 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x2e8>
 *   @0x1ccfb0 ldr r4, [r3, #0x8]
 *   @0x1ccfb4 vmov.f32 s8, s9
 *   @0x1ccfb8 ldr lr, [r3]
 *   @0x1ccfbc vldmia r1!, {s15}
 *   @0x1ccfc0 cmp r4, r10
 *   @0x1ccfc4 movge r7, r4
 *   @0x1ccfc8 movlt r7, r10
 *   @0x1ccfcc ldr r4, [r3, #0xc]
 *   @0x1ccfd0 cmp lr, r11
 *   @0x1ccfd4 movge lr, r11
 *   @0x1ccfd8 cmp r4, r8
 *   @0x1ccfdc movlt r4, r8
 *   @0x1ccfe0 vmov s4, r7
 *   @0x1ccfe4 vmov s11, r4
 *   @0x1ccfe8 ldr r4, [r3, #0x4]
 *   @0x1ccfec vcvt.f32.s32 s10, s4
 *   @0x1ccff0 cmp r4, r9
 *   @0x1ccff4 movge r4, r9
 *   @0x1ccff8 vmov s4, lr
 *   @0x1ccffc vmov s13, r4
 *   @0x1cd000 vcvt.f32.s32 s12, s4
 *   @0x1cd004 vcvt.f32.s32 s11, s11
 *   @0x1cd008 vcvt.f32.s32 s13, s13
 *   @0x1cd00c vsub.f32 s12, s10, s12
 *   @0x1cd010 vsub.f32 s13, s11, s13
 *   @0x1cd014 vnmls.f32 s8, s12, s13
 *   @0x1cd018 vsub.f32 s15, s8, s15
 *   @0x1cd01c vcmpe.f32 s15, s14
 *   @0x1cd020 vmrs APSR_nzcv, fpscr
 *   @0x1cd024 ble 0x1ccf7c <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x21c>
 *   @0x1cd028 mov r5, r2
 *   @0x1cd02c add r2, r2, #1
 *   @0x1cd030 cmp r2, #6
 *   @0x1cd034 vmov.f32 s14, s15
 *   @0x1cd038 mov r0, r6
 *   @0x1cd03c mov r12, #0
 *   @0x1cd040 add r3, r3, #24
 *   @0x1cd044 ble 0x1ccfb0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x250>
 *   @0x1cd048 ldr r1, [sp, #0x1c]
 *   @0x1cd04c ldr r2, [sp, #0x18]
 *   @0x1cd050 ldr r3, [sp, #0x14]
 *   @0x1cd054 cmp r1, #6
 *   @0x1cd058 ldr r4, [sp, #0xc]
 *   @0x1cd05c add r2, r2, #24
 *   @0x1cd060 add r3, r3, #4
 *   @0x1cd064 str r2, [sp, #0x18]
 *   @0x1cd068 add r4, r4, #24
 *   @0x1cd06c str r3, [sp, #0x14]
 *   @0x1cd070 movne r6, r1
 *   @0x1cd074 bne 0x1ccf48 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x1e8>
 *   @0x1cd078 ldr r11, [sp, #0x34]
 *   @0x1cd07c mov r1, #0
 *   @0x1cd080 mov r2, r11
 *   @0x1cd084 bl 0x1cbcf4 <_Z19FINALIZE_Run_Globalv+0x288>
 *   @0x1cd088 mov r1, #1
 *   @0x1cd08c mov r2, r11
 *   @0x1cd090 mov r0, r5
 *   @0x1cd094 bl 0x1cbcf4 <_Z19FINALIZE_Run_Globalv+0x288>
 *   @0x1cd098 ldr r3, [sp, #0x80]
 *   @0x1cd09c ldr r1, [sp, #0x84]
 *   @0x1cd0a0 ldr r7, [sp, #0x78]
 *   @0x1cd0a4 add r2, r3, r1
 *   @0x1cd0a8 cmp r2, r7
 *   @0x1cd0ac bge 0x1cd308 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x5a8>
 *   @0x1cd0b0 ldr r2, [sp, #0x7c]
 *   @0x1cd0b4 rsb r2, r2, r7
 *   @0x1cd0b8 cmp r3, r2
 *   @0x1cd0bc bge 0x1cd2b0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x550>
 *   @0x1cd0c0 cmp r1, r2
 *   @0x1cd0c4 bge 0x1cd2b0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x550>
 *   @0x1cd0c8 ldr r8, [sp, #0x38]
 *   @0x1cd0cc ldr r6, [sp, #0x3c]
 *   @0x1cd0d0 cmp r7, #0
 *   @0x1cd0d4 ble 0x1cd270 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x510>
 *   @0x1cd0d8 ldr r1, [sp, #0x98]
 *   @0x1cd0dc add r0, sp, #176
 *   @0x1cd0e0 ldr r5, [sp, #0x90]
 *   @0x1cd0e4 vmov.f32 s14, #-1.000000e+00
 *   @0x1cd0e8 ldr r12, [sp, #0x8c]
 *   @0x1cd0ec mov r3, #0
 *   @0x1cd0f0 ldr lr, [sp, #0x94]
 *   @0x1cd0f4 vldr s5, [sp, #168]
 *   @0x1cd0f8 ldr r2, [sp, #0x9c]
 *   @0x1cd0fc vldr s6, [sp, #172]
 *   @0x1cd100 str r1, [sp, #0x18]
 *   @0x1cd104 ldr r10, [sp, #0x88]
 *   @0x1cd108 str r5, [sp, #0xc]
 *   @0x1cd10c str r12, [sp, #0x10]
 *   @0x1cd110 str lr, [sp, #0x14]
 *   @0x1cd114 ldr r9, [sp, #0xa0]
 *   @0x1cd118 str r2, [sp, #0x1c]
 *   @0x1cd11c ldr r1, [sp, #0xa4]
 *   @0x1cd120 b 0x1cd134 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x3d4>
 *   @0x1cd124 add r3, r3, #1
 *   @0x1cd128 add r0, r0, #24
 *   @0x1cd12c cmp r3, r7
 *   @0x1cd130 beq 0x1cd270 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x510>
 *   @0x1cd134 ldr r2, [r11, r3, lsl #2]
 *   @0x1cd138 cmn r2, #1
 *   @0x1cd13c bne 0x1cd124 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x3c4>
 *   @0x1cd140 ldmib r0, {r12, lr}
 *   @0x1cd144 mov r5, #0
 *   @0x1cd148 ldr r4, [r0]
 *   @0x1cd14c ldr r2, [sp, #0x18]
 *   @0x1cd150 cmp r2, r4
 *   @0x1cd154 movge r2, r4
 *   @0x1cd158 cmp r4, r10
 *   @0x1cd15c movge r4, r10
 *   @0x1cd160 str r4, [sp, #0x34]
 *   @0x1cd164 cmp lr, r9
 *   @0x1cd168 movge r4, lr
 *   @0x1cd16c movlt r4, r9
 *   @0x1cd170 vmov s7, r2
 *   @0x1cd174 ldr r2, [r0, #0xc]
 *   @0x1cd178 vmov s11, r4
 *   @0x1cd17c ldr r4, [sp, #0xc]
 *   @0x1cd180 vldr s10, [sp, #52]
 *   @0x1cd184 vcvt.f32.s32 s7, s7
 *   @0x1cd188 cmp lr, r4
 *   @0x1cd18c movlt lr, r4
 *   @0x1cd190 ldr r4, [sp, #0x1c]
 *   @0x1cd194 cmp r4, r12
 *   @0x1cd198 movge r4, r12
 *   @0x1cd19c vmov s4, lr
 *   @0x1cd1a0 vmov s8, r4
 *   @0x1cd1a4 ldr r4, [sp, #0x10]
 *   @0x1cd1a8 cmp r12, r4
 *   @0x1cd1ac movge r12, r4
 *   @0x1cd1b0 cmp r2, r1
 *   @0x1cd1b4 movge r4, r2
 *   @0x1cd1b8 movlt r4, r1
 *   @0x1cd1bc vcvt.f32.s32 s9, s4
 *   @0x1cd1c0 vmov s13, r4
 *   @0x1cd1c4 ldr r4, [sp, #0x14]
 *   @0x1cd1c8 vmov s4, r12
 *   @0x1cd1cc cmp r2, r4
 *   @0x1cd1d0 movlt r2, r4
 *   @0x1cd1d4 vmov s15, r2
 *   @0x1cd1d8 vcvt.f32.s32 s8, s8
 *   @0x1cd1dc vcvt.f32.s32 s12, s10
 *   @0x1cd1e0 vcvt.f32.s32 s11, s11
 *   @0x1cd1e4 vcvt.f32.s32 s10, s15
 *   @0x1cd1e8 vcvt.f32.s32 s13, s13
 *   @0x1cd1ec vcvt.f32.s32 s15, s4
 *   @0x1cd1f0 vsub.f32 s13, s13, s8
 *   @0x1cd1f4 vsub.f32 s15, s10, s15
 *   @0x1cd1f8 vsub.f32 s11, s11, s7
 *   @0x1cd1fc vsub.f32 s12, s9, s12
 *   @0x1cd200 vmov.f32 s8, s6
 *   @0x1cd204 vmov.f32 s10, s5
 *   @0x1cd208 vnmls.f32 s8, s11, s13
 *   @0x1cd20c vnmls.f32 s10, s12, s15
 *   @0x1cd210 vsub.f32 s15, s8, s10
 *   @0x1cd214 vcmpe.f32 s15, #0
 *   @0x1cd218 vmrs APSR_nzcv, fpscr
 *   @0x1cd21c vneglt.f32 s15, s15
 *   @0x1cd220 movlt r5, #1
 *   @0x1cd224 vcmpe.f32 s15, s14
 *   @0x1cd228 vmrs APSR_nzcv, fpscr
 *   @0x1cd22c bgt 0x1cd3ac <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x64c>
 *   @0x1cd230 vcmp.f32 s15, s14
 *   @0x1cd234 add r2, r5, #8
 *   @0x1cd238 add r4, sp, #368
 *   @0x1cd23c add r12, r4, r6, lsl #2
 *   @0x1cd240 add r2, r4, r2, lsl #2
 *   @0x1cd244 vmrs APSR_nzcv, fpscr
 *   @0x1cd248 bne 0x1cd124 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x3c4>
 *   @0x1cd24c ldr r2, [r2, #-0x110]
 *   @0x1cd250 add r0, r0, #24
 *   @0x1cd254 ldr r12, [r12, #-0xf0]
 *   @0x1cd258 cmp r2, r12
 *   @0x1cd25c movlt r8, r3
 *   @0x1cd260 add r3, r3, #1
 *   @0x1cd264 movlt r6, r5
 *   @0x1cd268 cmp r3, r7
 *   @0x1cd26c bne 0x1cd134 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x3d4>
 *   @0x1cd270 mov r1, r6
 *   @0x1cd274 mov r2, r11
 *   @0x1cd278 mov r0, r8
 *   @0x1cd27c bl 0x1cbcf4 <_Z19FINALIZE_Run_Globalv+0x288>
 *   @0x1cd280 ldr r3, [sp, #0x80]
 *   @0x1cd284 ldr r1, [sp, #0x84]
 *   @0x1cd288 ldr r7, [sp, #0x78]
 *   @0x1cd28c add r2, r3, r1
 *   @0x1cd290 cmp r7, r2
 *   @0x1cd294 ble 0x1cd308 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x5a8>
 *   @0x1cd298 ldr r2, [sp, #0x7c]
 *   @0x1cd29c rsb r2, r2, r7
 *   @0x1cd2a0 cmp r3, r2
 *   @0x1cd2a4 bge 0x1cd2b0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x550>
 *   @0x1cd2a8 cmp r1, r2
 *   @0x1cd2ac blt 0x1cd0d0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x370>
 *   @0x1cd2b0 cmp r3, r2
 *   @0x1cd2b4 movlt r6, #0
 *   @0x1cd2b8 movge r6, #1
 *   @0x1cd2bc cmp r7, #0
 *   @0x1cd2c0 ble 0x1cd308 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x5a8>
 *   @0x1cd2c4 add r5, sp, #88
 *   @0x1cd2c8 mov r4, #0
 *   @0x1cd2cc b 0x1cd2dc <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x57c>
 *   @0x1cd2d0 add r4, r4, #1
 *   @0x1cd2d4 cmp r4, r7
 *   @0x1cd2d8 bge 0x1cd308 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x5a8>
 *   @0x1cd2dc ldr r3, [r5, #0x4]!
 *   @0x1cd2e0 cmn r3, #1
 *   @0x1cd2e4 bne 0x1cd2d0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x570>
 *   @0x1cd2e8 mov r0, r4
 *   @0x1cd2ec mov r1, r6
 *   @0x1cd2f0 mov r2, r11
 *   @0x1cd2f4 add r4, r4, #1
 *   @0x1cd2f8 bl 0x1cbcf4 <_Z19FINALIZE_Run_Globalv+0x288>
 *   @0x1cd2fc ldr r7, [sp, #0x78]
 *   @0x1cd300 cmp r4, r7
 *   @0x1cd304 blt 0x1cd2dc <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x57c>
 *   @0x1cd308 ldr r5, [sp, #0x2c]
 *   @0x1cd30c ldr r4, [r5, #0x4]
 *   @0x1cd310 ldr r7, [r4, #0x10]
 *   @0x1cd314 cmp r7, #0
 *   @0x1cd318 beq 0x1cd3bc <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x65c>
 *   @0x1cd31c ldr r3, [r7]
 *   @0x1cd320 str r3, [r4, #0x10]
 *   @0x1cd324 ldr r5, [sp, #0x24]
 *   @0x1cd328 mov r4, #0
 *   @0x1cd32c mvn r3, #0
 *   @0x1cd330 str r4, [r7]
 *   @0x1cd334 str r3, [r7, #0x4]
 *   @0x1cd338 ldr r2, [sp, #0x78]
 *   @0x1cd33c ldr r3, [r5, #0x4]
 *   @0x1cd340 ldr r12, [sp, #0x30]
 *   @0x1cd344 cmp r2, r4
 *   @0x1cd348 str r7, [r12]
 *   @0x1cd34c str r3, [r7, #0x4]
 *   @0x1cd350 str r4, [r5]
 *   @0x1cd354 ble 0x1cd3a4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x644>
 *   @0x1cd358 ldr r8, [sp, #0x2c]
 *   @0x1cd35c add r5, sp, #176
 *   @0x1cd360 ldr r9, [sp, #0x24]
 *   @0x1cd364 add r6, sp, #88
 *   @0x1cd368 ldr r2, [r6, #0x4]!
 *   @0x1cd36c add lr, sp, #368
 *   @0x1cd370 str r9, [sp, #0x40]
 *   @0x1cd374 mov r1, r5
 *   @0x1cd378 str r7, [sp, #0x44]
 *   @0x1cd37c mov r3, #0
 *   @0x1cd380 add r2, lr, r2, lsl #2
 *   @0x1cd384 mov r0, r8
 *   @0x1cd388 add r4, r4, #1
 *   @0x1cd38c add r5, r5, #24
 *   @0x1cd390 ldr r2, [r2, #-0x130]
 *   @0x1cd394 bl 0x1cd45c <_ZN5RTreeIP9CInstanceifLi6ELi2EE9AddBranchEPKNS2_6BranchEPNS2_4NodeEPS7_>
 *   @0x1cd398 ldr r3, [sp, #0x78]
 *   @0x1cd39c cmp r4, r3
 *   @0x1cd3a0 blt 0x1cd368 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x608>
 *   @0x1cd3a4 add sp, sp, #372
 *   @0x1cd3a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1cd3ac vmov.f32 s14, s15
 *   @0x1cd3b0 mov r6, r5
 *   @0x1cd3b4 mov r8, r3
 *   @0x1cd3b8 b 0x1cd124 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x3c4>
 *   @0x1cd3bc ldr r3, [r4, #0xc]
 *   @0x1cd3c0 ldr r2, [r4]
 *   @0x1cd3c4 cmp r3, r2
 *   @0x1cd3c8 bge 0x1cd3f0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x690>
 *   @0x1cd3cc ldr r0, [r4, #0x8]
 *   @0x1cd3d0 mov r7, #152
 *   @0x1cd3d4 ldr r2, [r4, #0x4]
 *   @0x1cd3d8 add r1, r3, #1
 *   @0x1cd3dc sub r0, r0, #-1073741823
 *   @0x1cd3e0 ldr r2, [r2, r0, lsl #2]
 *   @0x1cd3e4 str r1, [r4, #0xc]
 *   @0x1cd3e8 mla r7, r7, r3, r2
 *   @0x1cd3ec b 0x1cd324 <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x5c4>
 *   @0x1cd3f0 ldr r1, [r4, #0x8]
 *   @0x1cd3f4 mov r3, #74
 *   @0x1cd3f8 ldr r6, [pc, #0x58]
 *   @0x1cd3fc add r1, r1, #1
 *   @0x1cd400 ldr r0, [r4, #0x4]
 *   @0x1cd404 add r6, pc, r6
 *   @0x1cd408 str r1, [r4, #0x8]
 *   @0x1cd40c str r7, [r4, #0xc]
 *   @0x1cd410 lsl r1, r1, #2
 *   @0x1cd414 mov r2, r6
 *   @0x1cd418 str r7, [sp]
 *   @0x1cd41c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1cd420 ldr r3, [r4]
 *   @0x1cd424 ldr r12, [r4, #0x8]
 *   @0x1cd428 mov r1, r6
 *   @0x1cd42c mov r2, #70
 *   @0x1cd430 sub r6, r12, #-1073741823
 *   @0x1cd434 mov r5, r0
 *   @0x1cd438 mov r0, #152
 *   @0x1cd43c mul r0, r0, r3
 *   @0x1cd440 str r5, [r4, #0x4]
 *   @0x1cd444 mov r3, #1
 *   @0x1cd448 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1cd44c ldr r3, [r4, #0xc]
 *   @0x1cd450 str r0, [r5, r6, lsl #2]
 *   @0x1cd454 b 0x1cd3cc <_ZN5RTreeIP9CInstanceifLi6ELi2EE9SplitNodeEPNS2_4NodeEPKNS2_6BranchEPS4_+0x66c>
 *   @0x1cd458 andseq r3, r6, r12, lsr #24
 *
 * ══ §2/19 _SetupRenderTargetFBO  0x1814a0  size 1720  430 条（0x1814a0..0x181b58）
 * @func 0x1814a0 0x181b58  size 1720  430 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1814cc→0x479bbc, 0x1814e0→0x479bc0, 0x181548→0x3f26dc, 0x18155c→0x479c08, 0x181574→0x4a2f4c, 0x181598→0x479b44, 0x1815a0→0x479c00, 0x1815d4→0x479b74
 * 调用序列: DBG_BIND_FRAMEBUFFER(int)
 * 字段偏移 top8: 0x1c×6 / 0xc×4 / 0x380×3 / 0x20×3 / 0x14×2 / 0x608×1 / 0x5e8×1 / 0x5d8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1814a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1814a4 subs r5, r0, #0
 *   @0x1814a8 ldr r4, [pc, #0x608]
 *   @0x1814ac sub sp, sp, #20
 *   @0x1814b0 mov r8, r1
 *   @0x1814b4 mov r7, r2
 *   @0x1814b8 add r4, pc, r4
 *   @0x1814bc beq 0x181868 <_Z21_SetupRenderTargetFBOP7Textureii+0x3c8>
 *   @0x1814c0 ldr r1, [r5, #0x14]
 *   @0x1814c4 cmn r1, #1
 *   @0x1814c8 beq 0x181868 <_Z21_SetupRenderTargetFBOP7Textureii+0x3c8>
 *   @0x1814cc ldr r3, [pc, #0x5e8]
 *   @0x1814d0 movw r0, #0xde1
 *   @0x1814d4 ldr r3, [r4, r3]
 *   @0x1814d8 ldr r3, [r3]
 *   @0x1814dc blx r3
 *   @0x1814e0 ldr r3, [pc, #0x5d8]
 *   @0x1814e4 movw r0, #0xde1
 *   @0x1814e8 movw r1, #0x2801
 *   @0x1814ec mov r2, #1024
 *   @0x1814f0 movt r2, #0x4618
 *   @0x1814f4 ldr r6, [r4, r3]
 *   @0x1814f8 ldr r3, [r6]
 *   @0x1814fc blx r3
 *   @0x181500 ldr r3, [r6]
 *   @0x181504 movw r0, #0xde1
 *   @0x181508 mov r1, #10240
 *   @0x18150c mov r2, #1024
 *   @0x181510 movt r2, #0x4618
 *   @0x181514 blx r3
 *   @0x181518 ldr r3, [r6]
 *   @0x18151c movw r0, #0xde1
 *   @0x181520 movw r1, #0x2802
 *   @0x181524 mov r2, #12032
 *   @0x181528 movt r2, #0x4701
 *   @0x18152c blx r3
 *   @0x181530 ldr r3, [r6]
 *   @0x181534 movw r0, #0xde1
 *   @0x181538 movw r1, #0x2803
 *   @0x18153c mov r2, #12032
 *   @0x181540 movt r2, #0x4701
 *   @0x181544 blx r3
 *   @0x181548 ldr r3, [pc, #0x574]
 *   @0x18154c ldr r6, [r4, r3]
 *   @0x181550 ldr r0, [r6]
 *   @0x181554 cmp r0, #1
 *   @0x181558 beq 0x1819ec <_Z21_SetupRenderTargetFBOP7Textureii+0x54c>
 *   @0x18155c ldr r3, [pc, #0x564]
 *   @0x181560 mov r0, #1
 *   @0x181564 add r1, r5, #24
 *   @0x181568 ldr r3, [r4, r3]
 *   @0x18156c ldr r3, [r3]
 *   @0x181570 blx r3
 *   @0x181574 ldr r1, [pc, #0x550]
 *   @0x181578 movw r3, #0x443
 *   @0x18157c ldr r2, [pc, #0x54c]
 *   @0x181580 ldr r0, [r5, #0x18]
 *   @0x181584 ldr r9, [r4, r1]
 *   @0x181588 add r2, pc, r2
 *   @0x18158c stm r9, {r2, r3}
 *   @0x181590 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi>
 *   @0x181594 ldr r3, [r6]
 *   @0x181598 ldr r12, [pc, #0x534]
 *   @0x18159c cmp r3, #1
 *   @0x1815a0 ldrne r12, [pc, #0x530]
 *   @0x1815a4 ldr r12, [r4, r12]
 *   @0x1815a8 mov lr, #0
 *   @0x1815ac ldr r3, [r5, #0x14]
 *   @0x1815b0 movw r0, #0x8d40
 *   @0x1815b4 str lr, [sp]
 *   @0x1815b8 movw r1, #0x8ce0
 *   @0x1815bc movw r2, #0xde1
 *   @0x1815c0 ldr r12, [r12]
 *   @0x1815c4 blx r12
 *   @0x1815c8 ldr r0, [r6]
 *   @0x1815cc cmp r0, #1
 *   @0x1815d0 beq 0x181a38 <_Z21_SetupRenderTargetFBOP7Textureii+0x598>
 *   @0x1815d4 ldr r3, [pc, #0x500]
 *   @0x1815d8 mov r0, #1
 *   @0x1815dc add r1, r5, #28
 *   @0x1815e0 ldr r3, [r4, r3]
 *   @0x1815e4 ldr r3, [r3]
 *   @0x1815e8 blx r3
 *   @0x1815ec ldr r3, [r6]
 *   @0x1815f0 cmp r3, #1
 *   @0x1815f4 beq 0x181a30 <_Z21_SetupRenderTargetFBOP7Textureii+0x590>
 *   @0x1815f8 ldr r3, [pc, #0x4e0]
 *   @0x1815fc ldr r3, [r4, r3]
 *   @0x181600 movw r0, #0x8d41
 *   @0x181604 ldr r1, [r5, #0x1c]
 *   @0x181608 ldr r3, [r3]
 *   @0x18160c blx r3
 *   @0x181610 ldr r3, [pc, #0x4cc]
 *   @0x181614 ldr r3, [r4, r3]
 *   @0x181618 ldrb r3, [r3]
 *   @0x18161c cmp r3, #0
 *   @0x181620 ldr r3, [r6]
 *   @0x181624 beq 0x181870 <_Z21_SetupRenderTargetFBOP7Textureii+0x3d0>
 *   @0x181628 cmp r3, #1
 *   @0x18162c ldr r12, [pc, #0x4b4]
 *   @0x181630 ldrne r12, [pc, #0x4b4]
 *   @0x181634 ldr r12, [r4, r12]
 *   @0x181638 mov r3, r7
 *   @0x18163c movw r0, #0x8d41
 *   @0x181640 movw r1, #0x88f0
 *   @0x181644 mov r2, r8
 *   @0x181648 ldr r12, [r12]
 *   @0x18164c blx r12
 *   @0x181650 ldr r3, [r6]
 *   @0x181654 cmp r3, #1
 *   @0x181658 beq 0x181a68 <_Z21_SetupRenderTargetFBOP7Textureii+0x5c8>
 *   @0x18165c ldr r3, [pc, #0x47c]
 *   @0x181660 ldr r3, [r4, r3]
 *   @0x181664 movw r0, #0x8d41
 *   @0x181668 mov r1, #0
 *   @0x18166c ldr r3, [r3]
 *   @0x181670 blx r3
 *   @0x181674 ldr r3, [pc, #0x474]
 *   @0x181678 ldr r3, [r4, r3]
 *   @0x18167c ldrb r3, [r3]
 *   @0x181680 cmp r3, #0
 *   @0x181684 ldr r3, [r6]
 *   @0x181688 bne 0x181a04 <_Z21_SetupRenderTargetFBOP7Textureii+0x564>
 *   @0x18168c cmp r3, #1
 *   @0x181690 ldr r12, [pc, #0x45c]
 *   @0x181694 ldrne r12, [pc, #0x45c]
 *   @0x181698 ldr r12, [r4, r12]
 *   @0x18169c movw r0, #0x8d40
 *   @0x1816a0 ldr r3, [r5, #0x1c]
 *   @0x1816a4 mov r1, #36096
 *   @0x1816a8 movw r2, #0x8d41
 *   @0x1816ac ldr r12, [r12]
 *   @0x1816b0 blx r12
 *   @0x1816b4 ldr r3, [r6]
 *   @0x1816b8 cmp r3, #1
 *   @0x1816bc beq 0x181a80 <_Z21_SetupRenderTargetFBOP7Textureii+0x5e0>
 *   @0x1816c0 ldr r12, [pc, #0x430]
 *   @0x1816c4 movw r0, #0x8d40
 *   @0x1816c8 ldr r3, [r5, #0x1c]
 *   @0x1816cc ldr r12, [r4, r12]
 *   @0x1816d0 movw r1, #0x8d20
 *   @0x1816d4 movw r2, #0x8d41
 *   @0x1816d8 ldr r12, [r12]
 *   @0x1816dc blx r12
 *   @0x1816e0 ldr r12, [pc, #0x414]
 *   @0x1816e4 mov r0, #0
 *   @0x1816e8 mov r1, r0
 *   @0x1816ec mov r2, r8
 *   @0x1816f0 mov r3, r7
 *   @0x1816f4 ldr r10, [r4, r12]
 *   @0x1816f8 ldr r12, [r10]
 *   @0x1816fc blx r12
 *   @0x181700 ldr r12, [pc, #0x3f8]
 *   @0x181704 mov r3, r7
 *   @0x181708 mov r0, #0
 *   @0x18170c mov r2, r8
 *   @0x181710 mov r1, r0
 *   @0x181714 ldr r7, [r4, r12]
 *   @0x181718 ldr r5, [r7]
 *   @0x18171c blx r5
 *   @0x181720 ldr r3, [pc, #0x3dc]
 *   @0x181724 mov r0, #0
 *   @0x181728 mov r1, r0
 *   @0x18172c mov r2, r0
 *   @0x181730 ldr lr, [r4, r3]
 *   @0x181734 mov r3, r0
 *   @0x181738 ldr r5, [lr]
 *   @0x18173c blx r5
 *   @0x181740 ldr r3, [pc, #0x3c0]
 *   @0x181744 mov r0, #1065353216
 *   @0x181748 ldr r3, [r4, r3]
 *   @0x18174c ldr r3, [r3]
 *   @0x181750 blx r3
 *   @0x181754 ldr r3, [pc, #0x3b0]
 *   @0x181758 movw r0, #0xc11
 *   @0x18175c ldr r3, [r4, r3]
 *   @0x181760 ldr r3, [r3]
 *   @0x181764 blx r3
 *   @0x181768 ldr r3, [pc, #0x3a0]
 *   @0x18176c mov r0, #17664
 *   @0x181770 ldr r3, [r4, r3]
 *   @0x181774 ldr r3, [r3]
 *   @0x181778 blx r3
 *   @0x18177c ldr r3, [pc, #0x390]
 *   @0x181780 movw r0, #0xc11
 *   @0x181784 ldr r3, [r4, r3]
 *   @0x181788 ldr r3, [r3]
 *   @0x18178c blx r3
 *   @0x181790 ldr r2, [pc, #0x380]
 *   @0x181794 ldr r0, [pc, #0x380]
 *   @0x181798 ldr r1, [pc, #0x380]
 *   @0x18179c ldr r2, [r4, r2]
 *   @0x1817a0 ldr r3, [pc, #0x37c]
 *   @0x1817a4 ldr r11, [r4, r0]
 *   @0x1817a8 ldr r8, [r4, r1]
 *   @0x1817ac str r2, [sp, #0xc]
 *   @0x1817b0 ldr r5, [r4, r3]
 *   @0x1817b4 ldr r0, [r11]
 *   @0x1817b8 ldr r1, [r8]
 *   @0x1817bc ldr r2, [r2]
 *   @0x1817c0 ldr r3, [r5]
 *   @0x1817c4 ldr r10, [r10]
 *   @0x1817c8 blx r10
 *   @0x1817cc ldr r3, [sp, #0xc]
 *   @0x1817d0 ldr r12, [r7]
 *   @0x1817d4 ldr r0, [r11]
 *   @0x1817d8 ldr r2, [r3]
 *   @0x1817dc ldr r1, [r8]
 *   @0x1817e0 ldr r3, [r5]
 *   @0x1817e4 blx r12
 *   @0x1817e8 ldr r3, [r6]
 *   @0x1817ec cmp r3, #1
 *   @0x1817f0 beq 0x181a50 <_Z21_SetupRenderTargetFBOP7Textureii+0x5b0>
 *   @0x1817f4 ldr r3, [pc, #0x32c]
 *   @0x1817f8 movw r0, #0x8d40
 *   @0x1817fc ldr r3, [r4, r3]
 *   @0x181800 ldr r3, [r3]
 *   @0x181804 blx r3
 *   @0x181808 movw r3, #0x8cd5
 *   @0x18180c cmp r0, r3
 *   @0x181810 beq 0x18183c <_Z21_SetupRenderTargetFBOP7Textureii+0x39c>
 *   @0x181814 ldr r12, [pc, #0x310]
 *   @0x181818 mov r2, r0
 *   @0x18181c mov r3, r0
 *   @0x181820 ldr r1, [pc, #0x308]
 *   @0x181824 ldr r0, [r4, r12]
 *   @0x181828 add r1, pc, r1
 *   @0x18182c ldr r0, [r0]
 *   @0x181830 ldr r12, [r0]
 *   @0x181834 ldr r12, [r12, #0xc]
 *   @0x181838 blx r12
 *   @0x18183c ldr r3, [pc, #0x2f0]
 *   @0x181840 movw r1, #0x48b
 *   @0x181844 ldr r2, [pc, #0x2ec]
 *   @0x181848 str r1, [r9, #0x4]
 *   @0x18184c add r2, pc, r2
 *   @0x181850 str r2, [r9]
 *   @0x181854 ldr r3, [r4, r3]
 *   @0x181858 ldr r0, [r3]
 *   @0x18185c add sp, sp, #20
 *   @0x181860 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x181864 b 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi>
 *   @0x181868 add sp, sp, #20
 *   @0x18186c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x181870 cmp r3, #1
 *   @0x181874 movw r1, #0x81a5
 *   @0x181878 ldr r3, [pc, #0x2bc]
 *   @0x18187c beq 0x181a78 <_Z21_SetupRenderTargetFBOP7Textureii+0x5d8>
 *   @0x181880 ldr r12, [pc, #0x264]
 *   @0x181884 ldr r10, [r4, r3]
 *   @0x181888 movw lr, #0x81a6
 *   @0x18188c ldr r12, [r4, r12]
 *   @0x181890 mov r3, r7
 *   @0x181894 movw r0, #0x8d41
 *   @0x181898 mov r2, r8
 *   @0x18189c ldrb r10, [r10]
 *   @0x1818a0 ldr r12, [r12]
 *   @0x1818a4 cmp r10, #0
 *   @0x1818a8 movne r1, lr
 *   @0x1818ac blx r12
 *   @0x1818b0 ldr r3, [r6]
 *   @0x1818b4 cmp r3, #1
 *   @0x1818b8 beq 0x181a70 <_Z21_SetupRenderTargetFBOP7Textureii+0x5d0>
 *   @0x1818bc ldr r3, [pc, #0x21c]
 *   @0x1818c0 ldr r3, [r4, r3]
 *   @0x1818c4 movw r0, #0x8d41
 *   @0x1818c8 mov r1, #0
 *   @0x1818cc ldr r3, [r3]
 *   @0x1818d0 blx r3
 *   @0x1818d4 ldr r3, [r6]
 *   @0x1818d8 ldr r12, [pc, #0x214]
 *   @0x1818dc cmp r3, #1
 *   @0x1818e0 ldrne r12, [pc, #0x210]
 *   @0x1818e4 ldr r12, [r4, r12]
 *   @0x1818e8 movw r0, #0x8d40
 *   @0x1818ec ldr r3, [r5, #0x1c]
 *   @0x1818f0 mov r1, #36096
 *   @0x1818f4 movw r2, #0x8d41
 *   @0x1818f8 ldr r12, [r12]
 *   @0x1818fc blx r12
 *   @0x181900 ldr r3, [pc, #0x238]
 *   @0x181904 ldr r3, [r4, r3]
 *   @0x181908 ldrb r3, [r3]
 *   @0x18190c cmp r3, #0
 *   @0x181910 beq 0x1816e0 <_Z21_SetupRenderTargetFBOP7Textureii+0x240>
 *   @0x181914 ldr r0, [r6]
 *   @0x181918 cmp r0, #1
 *   @0x18191c beq 0x181aa0 <_Z21_SetupRenderTargetFBOP7Textureii+0x600>
 *   @0x181920 ldr r3, [pc, #0x1b4]
 *   @0x181924 mov r0, #1
 *   @0x181928 add r1, r5, #32
 *   @0x18192c ldr r3, [r4, r3]
 *   @0x181930 ldr r3, [r3]
 *   @0x181934 blx r3
 *   @0x181938 ldr r3, [pc, #0x1ec]
 *   @0x18193c ldr r1, [pc, #0x200]
 *   @0x181940 ldr r2, [r5, #0x20]
 *   @0x181944 ldr r3, [r4, r3]
 *   @0x181948 add r1, pc, r1
 *   @0x18194c ldr r0, [r3]
 *   @0x181950 ldr r3, [r0]
 *   @0x181954 ldr r3, [r3, #0xc]
 *   @0x181958 blx r3
 *   @0x18195c ldr r3, [r6]
 *   @0x181960 cmp r3, #1
 *   @0x181964 beq 0x181a98 <_Z21_SetupRenderTargetFBOP7Textureii+0x5f8>
 *   @0x181968 ldr r3, [pc, #0x170]
 *   @0x18196c ldr r3, [r4, r3]
 *   @0x181970 movw r0, #0x8d41
 *   @0x181974 ldr r1, [r5, #0x20]
 *   @0x181978 ldr r3, [r3]
 *   @0x18197c blx r3
 *   @0x181980 ldr r3, [r6]
 *   @0x181984 ldr r12, [pc, #0x15c]
 *   @0x181988 cmp r3, #1
 *   @0x18198c ldrne r12, [pc, #0x158]
 *   @0x181990 ldr r12, [r4, r12]
 *   @0x181994 mov r3, r7
 *   @0x181998 movw r0, #0x8d41
 *   @0x18199c movw r1, #0x8d48
 *   @0x1819a0 mov r2, r8
 *   @0x1819a4 ldr r12, [r12]
 *   @0x1819a8 blx r12
 *   @0x1819ac ldr r3, [r6]
 *   @0x1819b0 cmp r3, #1
 *   @0x1819b4 beq 0x181a90 <_Z21_SetupRenderTargetFBOP7Textureii+0x5f0>
 *   @0x1819b8 ldr r3, [pc, #0x120]
 *   @0x1819bc ldr r3, [r4, r3]
 *   @0x1819c0 movw r0, #0x8d41
 *   @0x1819c4 mov r1, #0
 *   @0x1819c8 ldr r3, [r3]
 *   @0x1819cc blx r3
 *   @0x1819d0 ldr r3, [r6]
 *   @0x1819d4 ldr r12, [pc, #0x118]
 *   @0x1819d8 cmp r3, #1
 *   @0x1819dc ldrne r12, [pc, #0x114]
 *   @0x1819e0 movw r0, #0x8d40
 *   @0x1819e4 ldr r3, [r5, #0x20]
 *   @0x1819e8 b 0x1816cc <_Z21_SetupRenderTargetFBOP7Textureii+0x22c>
 *   @0x1819ec ldr r3, [pc, #0x154]
 *   @0x1819f0 add r1, r5, #24
 *   @0x1819f4 ldr r3, [r4, r3]
 *   @0x1819f8 ldr r3, [r3]
 *   @0x1819fc blx r3
 *   @0x181a00 b 0x181574 <_Z21_SetupRenderTargetFBOP7Textureii+0xd4>
 *   @0x181a04 cmp r3, #1
 *   @0x181a08 ldr r12, [pc, #0xe4]
 *   @0x181a0c ldrne r12, [pc, #0xe4]
 *   @0x181a10 ldr r12, [r4, r12]
 *   @0x181a14 movw r0, #0x8d40
 *   @0x181a18 ldr r3, [r5, #0x1c]
 *   @0x181a1c movw r1, #0x821a
 *   @0x181a20 movw r2, #0x8d41
 *   @0x181a24 ldr r12, [r12]
 *   @0x181a28 blx r12
 *   @0x181a2c b 0x1816e0 <_Z21_SetupRenderTargetFBOP7Textureii+0x240>
 *   @0x181a30 ldr r3, [pc, #0x114]
 *   @0x181a34 b 0x1815fc <_Z21_SetupRenderTargetFBOP7Textureii+0x15c>
 *   @0x181a38 ldr r3, [pc, #0x110]
 *   @0x181a3c add r1, r5, #28
 *   @0x181a40 ldr r3, [r4, r3]
 *   @0x181a44 ldr r3, [r3]
 *   @0x181a48 blx r3
 *   @0x181a4c b 0x1815ec <_Z21_SetupRenderTargetFBOP7Textureii+0x14c>
 *   @0x181a50 ldr r3, [pc, #0xfc]
 *   @0x181a54 movw r0, #0x8d40
 *   @0x181a58 ldr r3, [r4, r3]
 *   @0x181a5c ldr r3, [r3]
 *   @0x181a60 blx r3
 *   @0x181a64 b 0x181808 <_Z21_SetupRenderTargetFBOP7Textureii+0x368>
 *   @0x181a68 ldr r3, [pc, #0xdc]
 *   @0x181a6c b 0x181660 <_Z21_SetupRenderTargetFBOP7Textureii+0x1c0>
 *   @0x181a70 ldr r3, [pc, #0xd4]
 *   @0x181a74 b 0x1818c0 <_Z21_SetupRenderTargetFBOP7Textureii+0x420>
 *   @0x181a78 ldr r12, [pc, #0x68]
 *   @0x181a7c b 0x181884 <_Z21_SetupRenderTargetFBOP7Textureii+0x3e4>
 *   @0x181a80 ldr r12, [pc, #0x6c]
 *   @0x181a84 movw r0, #0x8d40
 *   @0x181a88 ldr r3, [r5, #0x1c]
 *   @0x181a8c b 0x1816cc <_Z21_SetupRenderTargetFBOP7Textureii+0x22c>
 *   @0x181a90 ldr r3, [pc, #0xb4]
 *   @0x181a94 b 0x1819bc <_Z21_SetupRenderTargetFBOP7Textureii+0x51c>
 *   @0x181a98 ldr r3, [pc, #0xac]
 *   @0x181a9c b 0x18196c <_Z21_SetupRenderTargetFBOP7Textureii+0x4cc>
 *   @0x181aa0 ldr r3, [pc, #0xa8]
 *   @0x181aa4 add r1, r5, #32
 *   @0x181aa8 ldr r3, [r4, r3]
 *   @0x181aac ldr r3, [r3]
 *   @0x181ab0 blx r3
 *   @0x181ab4 b 0x181938 <_Z21_SetupRenderTargetFBOP7Textureii+0x498>
 *   @0x181ab8 mlaeq r7, r8, r7, r0
 *   @0x181abc .word 0xffffbb20
 *   @0x181ac0 .word 0xffffbb1c
 *   @0x181ac4 .word 0xffffe7b8
 *   @0x181ac8 .word 0xffffbc74
 *   @0x181acc .word 0xffffe81c
 *   @0x181ad0 andseq r10, r12, r4, lsr r4
 *   @0x181ad4 .word 0xffffbb6c
 *   @0x181ad8 .word 0xffffbc7c
 *   @0x181adc .word 0xffffbcb0
 *   @0x181ae0 .word 0xffffbcb4
 *   @0x181ae4 .word 0xffffe7d8
 *   @0x181ae8 .word 0xffffbc08
 *   @0x181aec .word 0xffffbcb8
 *   @0x181af0 .word 0xffffe900
 *   @0x181af4 .word 0xffffbc10
 *   @0x181af8 .word 0xffffbcc0
 *   @0x181afc .word 0xffffbae4
 *   @0x181b00 .word 0xffffbaf0
 *   @0x181b04 .word 0xffffbb00
 *   @0x181b08 .word 0xffffbb04
 *   @0x181b0c .word 0xffffbad0
 *   @0x181b10 .word 0xffffbacc
 *   @0x181b14 .word 0xffffbad8
 *   @0x181b18 .word 0xffffe814
 *   @0x181b1c .word 0xffffe80c
 *   @0x181b20 .word 0xffffe810
 *   @0x181b24 .word 0xffffe818
 *   @0x181b28 .word 0xffffbc84
 *   @0x181b2c .word 0xffffbac4
 *   @0x181b30 andseq r10, r12, r8, lsl r2
 *   @0x181b34 .word 0xffffe820
 *   @0x181b38 andseq r10, r12, r0, ror r1
 *   @0x181b3c .word 0xffffe7dc
 *   @0x181b40 .word 0xffffe7c4
 *   @0x181b44 andseq r10, r12, r8, ror #1
 *   @0x181b48 .word 0xffffbb68
 *   @0x181b4c .word 0xffffbc04
 *   @0x181b50 .word 0xffffbc00
 *   @0x181b54 .word 0xffffbbf4
 *
 * ══ §3/19 vorbis_synthesis_headerin  0x22af64  size 1716  429 条（0x22af64..0x22b618）
 * @func 0x22af64 0x22b618  size 1716  429 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_read×31 / vorbis_synthesis_headerin+0x1ac×5 / 0xb6c34×5 / oggpack_bytes×3 / vorbis_synthesis_headerin+0x3c4×2 / oggpack_readinit / 0xb6c40 / vorbis_info_clear
 * 字段偏移 top8: 0x4×15 / 0x8×13 / 0xc×9 / 0x1c×9 / 0x2×5 / 0x1×3 / 0x10×3 / 0x14×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22af64 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22af68 subs r7, r2, #0
 *   @0x22af6c sub sp, sp, #44
 *   @0x22af70 mov r11, r0
 *   @0x22af74 mov r9, r1
 *   @0x22af78 beq 0x22b004 <vorbis_synthesis_headerin+0xa0>
 *   @0x22af7c add r5, sp, #20
 *   @0x22af80 ldm r7, {r1, r2}
 *   @0x22af84 add r8, sp, #12
 *   @0x22af88 add r4, sp, #11
 *   @0x22af8c mov r0, r5
 *   @0x22af90 add r6, sp, #17
 *   @0x22af94 bl 0x23385c <oggpack_readinit>
 *   @0x22af98 mov r0, r5
 *   @0x22af9c mov r1, #8
 *   @0x22afa0 bl 0x233b28 <oggpack_read>
 *   @0x22afa4 mov r3, #0
 *   @0x22afa8 strh r3, [r8, #4]
 *   @0x22afac str r3, [sp, #0xc]
 *   @0x22afb0 mov r10, r0
 *   @0x22afb4 mov r0, r5
 *   @0x22afb8 mov r1, #8
 *   @0x22afbc bl 0x233b28 <oggpack_read>
 *   @0x22afc0 strb r0, [r4, #0x1]!
 *   @0x22afc4 cmp r4, r6
 *   @0x22afc8 bne 0x22afb4 <vorbis_synthesis_headerin+0x50>
 *   @0x22afcc ldr r1, [pc, #0x634]
 *   @0x22afd0 mov r0, r8
 *   @0x22afd4 mov r2, #6
 *   @0x22afd8 add r1, pc, r1
 *   @0x22afdc bl 0xb6c40 <memcmp@plt>
 *   @0x22afe0 subs r8, r0, #0
 *   @0x22afe4 mvnne r8, #131
 *   @0x22afe8 bne 0x22b008 <vorbis_synthesis_headerin+0xa4>
 *   @0x22afec cmp r10, #3
 *   @0x22aff0 beq 0x22b198 <vorbis_synthesis_headerin+0x234>
 *   @0x22aff4 cmp r10, #5
 *   @0x22aff8 beq 0x22b120 <vorbis_synthesis_headerin+0x1bc>
 *   @0x22affc cmp r10, #1
 *   @0x22b000 beq 0x22b014 <vorbis_synthesis_headerin+0xb0>
 *   @0x22b004 mvn r8, #132
 *   @0x22b008 mov r0, r8
 *   @0x22b00c add sp, sp, #44
 *   @0x22b010 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22b014 ldr r3, [r7, #0x8]
 *   @0x22b018 cmp r3, #0
 *   @0x22b01c beq 0x22b004 <vorbis_synthesis_headerin+0xa0>
 *   @0x22b020 ldr r3, [r11, #0x8]
 *   @0x22b024 cmp r3, #0
 *   @0x22b028 bne 0x22b004 <vorbis_synthesis_headerin+0xa0>
 *   @0x22b02c ldr r4, [r11, #0x1c]
 *   @0x22b030 cmp r4, #0
 *   @0x22b034 beq 0x22b524 <vorbis_synthesis_headerin+0x5c0>
 *   @0x22b038 mov r0, r5
 *   @0x22b03c mov r1, #32
 *   @0x22b040 bl 0x233b28 <oggpack_read>
 *   @0x22b044 cmp r0, #0
 *   @0x22b048 str r0, [r11]
 *   @0x22b04c bne 0x22b49c <vorbis_synthesis_headerin+0x538>
 *   @0x22b050 mov r1, #8
 *   @0x22b054 mov r0, r5
 *   @0x22b058 bl 0x233b28 <oggpack_read>
 *   @0x22b05c mov r1, #32
 *   @0x22b060 str r0, [r11, #0x4]
 *   @0x22b064 mov r0, r5
 *   @0x22b068 bl 0x233b28 <oggpack_read>
 *   @0x22b06c mov r1, #32
 *   @0x22b070 str r0, [r11, #0x8]
 *   @0x22b074 mov r0, r5
 *   @0x22b078 bl 0x233b28 <oggpack_read>
 *   @0x22b07c mov r1, #32
 *   @0x22b080 str r0, [r11, #0xc]
 *   @0x22b084 mov r0, r5
 *   @0x22b088 bl 0x233b28 <oggpack_read>
 *   @0x22b08c mov r1, #32
 *   @0x22b090 str r0, [r11, #0x10]
 *   @0x22b094 mov r0, r5
 *   @0x22b098 bl 0x233b28 <oggpack_read>
 *   @0x22b09c mov r1, #4
 *   @0x22b0a0 str r0, [r11, #0x14]
 *   @0x22b0a4 mov r0, r5
 *   @0x22b0a8 bl 0x233b28 <oggpack_read>
 *   @0x22b0ac mov r1, #4
 *   @0x22b0b0 lsl r3, r10, r0
 *   @0x22b0b4 mov r0, r5
 *   @0x22b0b8 str r3, [r4]
 *   @0x22b0bc bl 0x233b28 <oggpack_read>
 *   @0x22b0c0 ldr r3, [r11, #0x8]
 *   @0x22b0c4 cmp r3, #0
 *   @0x22b0c8 lsl r0, r10, r0
 *   @0x22b0cc str r0, [r4, #0x4]
 *   @0x22b0d0 ble 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b0d4 ldr r3, [r11, #0x4]
 *   @0x22b0d8 cmp r3, #0
 *   @0x22b0dc ble 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b0e0 ldr r3, [r4]
 *   @0x22b0e4 cmp r3, #63
 *   @0x22b0e8 ble 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b0ec cmp r0, r3
 *   @0x22b0f0 blt 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b0f4 cmp r0, #8192
 *   @0x22b0f8 bgt 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b0fc mov r0, r5
 *   @0x22b100 mov r1, #1
 *   @0x22b104 bl 0x233b28 <oggpack_read>
 *   @0x22b108 cmp r0, #1
 *   @0x22b10c beq 0x22b008 <vorbis_synthesis_headerin+0xa4>
 *   @0x22b110 mov r0, r11
 *   @0x22b114 mvn r8, #132
 *   @0x22b118 bl 0x22ad10 <vorbis_info_clear>
 *   @0x22b11c b 0x22b008 <vorbis_synthesis_headerin+0xa4>
 *   @0x22b120 ldr r3, [r11, #0x8]
 *   @0x22b124 cmp r3, #0
 *   @0x22b128 beq 0x22b004 <vorbis_synthesis_headerin+0xa0>
 *   @0x22b12c ldr r3, [r9, #0xc]
 *   @0x22b130 cmp r3, #0
 *   @0x22b134 beq 0x22b004 <vorbis_synthesis_headerin+0xa0>
 *   @0x22b138 ldr r6, [r11, #0x1c]
 *   @0x22b13c cmp r6, #0
 *   @0x22b140 beq 0x22b524 <vorbis_synthesis_headerin+0x5c0>
 *   @0x22b144 mov r0, r5
 *   @0x22b148 mov r1, #8
 *   @0x22b14c bl 0x233b28 <oggpack_read>
 *   @0x22b150 add r0, r0, #1
 *   @0x22b154 str r0, [r6, #0x1c]
 *   @0x22b158 cmp r0, #0
 *   @0x22b15c addgt r7, r6, #2064
 *   @0x22b160 movgt r4, r8
 *   @0x22b164 addgt r7, r7, #12
 *   @0x22b168 bgt 0x22b17c <vorbis_synthesis_headerin+0x218>
 *   @0x22b16c b 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b170 ldr r3, [r6, #0x1c]
 *   @0x22b174 cmp r4, r3
 *   @0x22b178 bge 0x22b338 <vorbis_synthesis_headerin+0x3d4>
 *   @0x22b17c mov r0, r5
 *   @0x22b180 add r4, r4, #1
 *   @0x22b184 bl 0x227d30 <vorbis_staticbook_unpack>
 *   @0x22b188 cmp r0, #0
 *   @0x22b18c str r0, [r7, #0x4]!
 *   @0x22b190 bne 0x22b170 <vorbis_synthesis_headerin+0x20c>
 *   @0x22b194 b 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b198 ldr r3, [r11, #0x8]
 *   @0x22b19c cmp r3, #0
 *   @0x22b1a0 beq 0x22b004 <vorbis_synthesis_headerin+0xa0>
 *   @0x22b1a4 mov r0, r5
 *   @0x22b1a8 mov r1, #32
 *   @0x22b1ac bl 0x233b28 <oggpack_read>
 *   @0x22b1b0 subs r4, r0, #0
 *   @0x22b1b4 blt 0x22b328 <vorbis_synthesis_headerin+0x3c4>
 *   @0x22b1b8 mov r0, r5
 *   @0x22b1bc ldr r6, [sp, #0x24]
 *   @0x22b1c0 bl 0x233e28 <oggpack_bytes>
 *   @0x22b1c4 rsb r0, r0, r6
 *   @0x22b1c8 cmp r4, r0
 *   @0x22b1cc bgt 0x22b328 <vorbis_synthesis_headerin+0x3c4>
 *   @0x22b1d0 add r0, r4, #1
 *   @0x22b1d4 mov r1, #1
 *   @0x22b1d8 bl 0xb6c34 <calloc@plt>
 *   @0x22b1dc cmp r0, #0
 *   @0x22b1e0 mov r6, r0
 *   @0x22b1e4 str r0, [r9, #0xc]
 *   @0x22b1e8 beq 0x22b328 <vorbis_synthesis_headerin+0x3c4>
 *   @0x22b1ec cmp r4, #0
 *   @0x22b1f0 beq 0x22b20c <vorbis_synthesis_headerin+0x2a8>
 *   @0x22b1f4 mov r0, r5
 *   @0x22b1f8 mov r1, #8
 *   @0x22b1fc bl 0x233b28 <oggpack_read>
 *   @0x22b200 subs r4, r4, #1
 *   @0x22b204 strb r0, [r6], #1
 *   @0x22b208 bne 0x22b1f4 <vorbis_synthesis_headerin+0x290>
 *   @0x22b20c mov r0, r5
 *   @0x22b210 mov r1, #32
 *   @0x22b214 bl 0x233b28 <oggpack_read>
 *   @0x22b218 cmn r0, #-2147483647
 *   @0x22b21c mov r4, r0
 *   @0x22b220 movne r3, #0
 *   @0x22b224 moveq r3, #1
 *   @0x22b228 orrs r7, r3, r0, lsr #31
 *   @0x22b22c bne 0x22b328 <vorbis_synthesis_headerin+0x3c4>
 *   @0x22b230 mov r0, r5
 *   @0x22b234 ldr r6, [sp, #0x24]
 *   @0x22b238 bl 0x233e28 <oggpack_bytes>
 *   @0x22b23c rsb r0, r0, r6
 *   @0x22b240 cmp r4, r0, asr #2
 *   @0x22b244 bgt 0x22b328 <vorbis_synthesis_headerin+0x3c4>
 *   @0x22b248 add r10, r4, #1
 *   @0x22b24c mov r1, #4
 *   @0x22b250 mov r0, r10
 *   @0x22b254 bl 0xb6c34 <calloc@plt>
 *   @0x22b258 mov r1, #4
 *   @0x22b25c mov r6, r0
 *   @0x22b260 str r0, [r9]
 *   @0x22b264 mov r0, r10
 *   @0x22b268 bl 0xb6c34 <calloc@plt>
 *   @0x22b26c cmp r6, #0
 *   @0x22b270 str r0, [r9, #0x4]
 *   @0x22b274 beq 0x22b328 <vorbis_synthesis_headerin+0x3c4>
 *   @0x22b278 cmp r0, #0
 *   @0x22b27c beq 0x22b328 <vorbis_synthesis_headerin+0x3c4>
 *   @0x22b280 cmp r4, #0
 *   @0x22b284 str r4, [r9, #0x8]
 *   @0x22b288 ble 0x22b314 <vorbis_synthesis_headerin+0x3b0>
 *   @0x22b28c mov r0, r5
 *   @0x22b290 mov r1, #32
 *   @0x22b294 bl 0x233b28 <oggpack_read>
 *   @0x22b298 subs r4, r0, #0
 *   @0x22b29c blt 0x22b328 <vorbis_synthesis_headerin+0x3c4>
 *   @0x22b2a0 mov r0, r5
 *   @0x22b2a4 ldr r6, [sp, #0x24]
 *   @0x22b2a8 bl 0x233e28 <oggpack_bytes>
 *   @0x22b2ac rsb r0, r0, r6
 *   @0x22b2b0 cmp r4, r0
 *   @0x22b2b4 bgt 0x22b328 <vorbis_synthesis_headerin+0x3c4>
 *   @0x22b2b8 ldr r3, [r9, #0x4]
 *   @0x22b2bc add r0, r4, #1
 *   @0x22b2c0 ldr r6, [r9]
 *   @0x22b2c4 mov r1, #1
 *   @0x22b2c8 str r4, [r3, r7, lsl #2]
 *   @0x22b2cc bl 0xb6c34 <calloc@plt>
 *   @0x22b2d0 str r0, [r6, r7, lsl #2]
 *   @0x22b2d4 ldr r3, [r9]
 *   @0x22b2d8 ldr r6, [r3, r7, lsl #2]
 *   @0x22b2dc cmp r6, #0
 *   @0x22b2e0 beq 0x22b410 <vorbis_synthesis_headerin+0x4ac>
 *   @0x22b2e4 cmp r4, #0
 *   @0x22b2e8 beq 0x22b304 <vorbis_synthesis_headerin+0x3a0>
 *   @0x22b2ec mov r0, r5
 *   @0x22b2f0 mov r1, #8
 *   @0x22b2f4 bl 0x233b28 <oggpack_read>
 *   @0x22b2f8 subs r4, r4, #1
 *   @0x22b2fc strb r0, [r6], #1
 *   @0x22b300 bne 0x22b2ec <vorbis_synthesis_headerin+0x388>
 *   @0x22b304 ldr r3, [r9, #0x8]
 *   @0x22b308 add r7, r7, #1
 *   @0x22b30c cmp r7, r3
 *   @0x22b310 blt 0x22b28c <vorbis_synthesis_headerin+0x328>
 *   @0x22b314 mov r0, r5
 *   @0x22b318 mov r1, #1
 *   @0x22b31c bl 0x233b28 <oggpack_read>
 *   @0x22b320 cmp r0, #1
 *   @0x22b324 beq 0x22b008 <vorbis_synthesis_headerin+0xa4>
 *   @0x22b328 mov r0, r9
 *   @0x22b32c mvn r8, #132
 *   @0x22b330 bl 0x22ac4c <vorbis_comment_clear>
 *   @0x22b334 b 0x22b008 <vorbis_synthesis_headerin+0xa4>
 *   @0x22b338 mov r0, r5
 *   @0x22b33c mov r1, #6
 *   @0x22b340 bl 0x233b28 <oggpack_read>
 *   @0x22b344 add r0, r0, #1
 *   @0x22b348 str r0, [r6, #0x10]
 *   @0x22b34c cmp r0, #0
 *   @0x22b350 addgt r9, r6, #796
 *   @0x22b354 movgt r7, #0
 *   @0x22b358 bgt 0x22b36c <vorbis_synthesis_headerin+0x408>
 *   @0x22b35c b 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b360 ldr r3, [r6, #0x10]
 *   @0x22b364 cmp r7, r3
 *   @0x22b368 bge 0x22b390 <vorbis_synthesis_headerin+0x42c>
 *   @0x22b36c mov r0, r5
 *   @0x22b370 mov r1, #16
 *   @0x22b374 bl 0x233b28 <oggpack_read>
 *   @0x22b378 add r7, r7, #1
 *   @0x22b37c cmp r0, #0
 *   @0x22b380 mov r4, r0
 *   @0x22b384 str r0, [r9, #0x4]!
 *   @0x22b388 beq 0x22b360 <vorbis_synthesis_headerin+0x3fc>
 *   @0x22b38c b 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b390 mov r0, r5
 *   @0x22b394 mov r1, #6
 *   @0x22b398 bl 0x233b28 <oggpack_read>
 *   @0x22b39c add r0, r0, #1
 *   @0x22b3a0 str r0, [r6, #0x14]
 *   @0x22b3a4 cmp r0, #0
 *   @0x22b3a8 addgt r7, r6, #1040
 *   @0x22b3ac addgt r7, r7, #12
 *   @0x22b3b0 bgt 0x22b3e0 <vorbis_synthesis_headerin+0x47c>
 *   @0x22b3b4 b 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b3b8 ldr r2, [pc, r2]
 *   @0x22b3bc ldr r3, [r2, r3, lsl #2]
 *   @0x22b3c0 ldr r3, [r3]
 *   @0x22b3c4 blx r3
 *   @0x22b3c8 cmp r0, #0
 *   @0x22b3cc str r0, [r7, #0x100]
 *   @0x22b3d0 beq 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b3d4 ldr r3, [r6, #0x14]
 *   @0x22b3d8 cmp r4, r3
 *   @0x22b3dc bge 0x22b418 <vorbis_synthesis_headerin+0x4b4>
 *   @0x22b3e0 mov r1, #16
 *   @0x22b3e4 mov r0, r5
 *   @0x22b3e8 bl 0x233b28 <oggpack_read>
 *   @0x22b3ec add r4, r4, #1
 *   @0x22b3f0 ldr r2, [pc, #0x214]
 *   @0x22b3f4 mov r1, r5
 *   @0x22b3f8 mov r3, r0
 *   @0x22b3fc cmp r3, #1
 *   @0x22b400 mov r0, r11
 *   @0x22b404 str r3, [r7, #0x4]!
 *   @0x22b408 bls 0x22b3b8 <vorbis_synthesis_headerin+0x454>
 *   @0x22b40c b 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b410 str r7, [r9, #0x8]
 *   @0x22b414 b 0x22b328 <vorbis_synthesis_headerin+0x3c4>
 *   @0x22b418 mov r0, r5
 *   @0x22b41c mov r1, #6
 *   @0x22b420 bl 0x233b28 <oggpack_read>
 *   @0x22b424 add r0, r0, #1
 *   @0x22b428 str r0, [r6, #0x18]
 *   @0x22b42c cmp r0, #0
 *   @0x22b430 addgt r4, r6, #1552
 *   @0x22b434 movgt r7, #0
 *   @0x22b438 addgt r4, r4, #12
 *   @0x22b43c bgt 0x22b46c <vorbis_synthesis_headerin+0x508>
 *   @0x22b440 b 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b444 ldr r3, [pc, r3]
 *   @0x22b448 ldr r3, [r3, r2, lsl #2]
 *   @0x22b44c ldr r3, [r3]
 *   @0x22b450 blx r3
 *   @0x22b454 cmp r0, #0
 *   @0x22b458 str r0, [r4, #0x100]
 *   @0x22b45c beq 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b460 ldr r3, [r6, #0x18]
 *   @0x22b464 cmp r7, r3
 *   @0x22b468 bge 0x22b4a4 <vorbis_synthesis_headerin+0x540>
 *   @0x22b46c mov r1, #16
 *   @0x22b470 mov r0, r5
 *   @0x22b474 bl 0x233b28 <oggpack_read>
 *   @0x22b478 add r7, r7, #1
 *   @0x22b47c ldr r3, [pc, #0x18c]
 *   @0x22b480 mov r1, r5
 *   @0x22b484 mov r2, r0
 *   @0x22b488 cmp r2, #2
 *   @0x22b48c mov r0, r11
 *   @0x22b490 str r2, [r4, #0x4]!
 *   @0x22b494 bls 0x22b444 <vorbis_synthesis_headerin+0x4e0>
 *   @0x22b498 b 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b49c mvn r8, #133
 *   @0x22b4a0 b 0x22b008 <vorbis_synthesis_headerin+0xa4>
 *   @0x22b4a4 mov r0, r5
 *   @0x22b4a8 mov r1, #6
 *   @0x22b4ac bl 0x233b28 <oggpack_read>
 *   @0x22b4b0 add r0, r0, #1
 *   @0x22b4b4 str r0, [r6, #0xc]
 *   @0x22b4b8 cmp r0, #0
 *   @0x22b4bc addgt r9, r6, #284
 *   @0x22b4c0 movgt r7, #0
 *   @0x22b4c4 bgt 0x22b4f4 <vorbis_synthesis_headerin+0x590>
 *   @0x22b4c8 b 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b4cc ldr r3, [pc, r3]
 *   @0x22b4d0 ldr r3, [r3]
 *   @0x22b4d4 ldr r3, [r3]
 *   @0x22b4d8 blx r3
 *   @0x22b4dc cmp r0, #0
 *   @0x22b4e0 str r0, [r9, #0x100]
 *   @0x22b4e4 beq 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b4e8 ldr r3, [r6, #0xc]
 *   @0x22b4ec cmp r7, r3
 *   @0x22b4f0 bge 0x22b52c <vorbis_synthesis_headerin+0x5c8>
 *   @0x22b4f4 mov r1, #16
 *   @0x22b4f8 mov r0, r5
 *   @0x22b4fc bl 0x233b28 <oggpack_read>
 *   @0x22b500 add r7, r7, #1
 *   @0x22b504 ldr r3, [pc, #0x108]
 *   @0x22b508 mov r1, r5
 *   @0x22b50c mov r4, r0
 *   @0x22b510 cmp r4, #0
 *   @0x22b514 mov r0, r11
 *   @0x22b518 str r4, [r9, #0x4]!
 *   @0x22b51c beq 0x22b4cc <vorbis_synthesis_headerin+0x568>
 *   @0x22b520 b 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b524 mvn r8, #128
 *   @0x22b528 b 0x22b008 <vorbis_synthesis_headerin+0xa4>
 *   @0x22b52c mov r0, r5
 *   @0x22b530 mov r1, #6
 *   @0x22b534 bl 0x233b28 <oggpack_read>
 *   @0x22b538 add r0, r0, #1
 *   @0x22b53c str r0, [r6, #0x8]
 *   @0x22b540 cmp r0, #0
 *   @0x22b544 movgt r7, r4
 *   @0x22b548 movgt r4, r6
 *   @0x22b54c bgt 0x22b584 <vorbis_synthesis_headerin+0x620>
 *   @0x22b550 b 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b554 ldr r2, [r3, #0x8]
 *   @0x22b558 cmp r2, #0
 *   @0x22b55c bgt 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b560 ldr r3, [r3, #0xc]
 *   @0x22b564 ldr r2, [r6, #0xc]
 *   @0x22b568 cmp r3, r2
 *   @0x22b56c bge 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b570 cmp r3, #0
 *   @0x22b574 blt 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b578 ldr r3, [r6, #0x8]
 *   @0x22b57c cmp r7, r3
 *   @0x22b580 bge 0x22b0fc <vorbis_synthesis_headerin+0x198>
 *   @0x22b584 mov r1, #16
 *   @0x22b588 mov r0, #1
 *   @0x22b58c bl 0xb6c34 <calloc@plt>
 *   @0x22b590 mov r1, #1
 *   @0x22b594 add r7, r7, r1
 *   @0x22b598 add r4, r4, #4
 *   @0x22b59c mov r9, r0
 *   @0x22b5a0 str r0, [r4, #0x1c]
 *   @0x22b5a4 mov r0, r5
 *   @0x22b5a8 bl 0x233b28 <oggpack_read>
 *   @0x22b5ac ldr r3, [r4, #0x1c]
 *   @0x22b5b0 mov r1, #16
 *   @0x22b5b4 str r0, [r9]
 *   @0x22b5b8 mov r0, r5
 *   @0x22b5bc str r3, [sp, #0x4]
 *   @0x22b5c0 bl 0x233b28 <oggpack_read>
 *   @0x22b5c4 ldr r3, [sp, #0x4]
 *   @0x22b5c8 mov r1, #16
 *   @0x22b5cc ldr r10, [r4, #0x1c]
 *   @0x22b5d0 str r0, [r3, #0x4]
 *   @0x22b5d4 mov r0, r5
 *   @0x22b5d8 bl 0x233b28 <oggpack_read>
 *   @0x22b5dc ldr r9, [r4, #0x1c]
 *   @0x22b5e0 mov r1, #8
 *   @0x22b5e4 str r0, [r10, #0x8]
 *   @0x22b5e8 mov r0, r5
 *   @0x22b5ec bl 0x233b28 <oggpack_read>
 *   @0x22b5f0 ldr r3, [r4, #0x1c]
 *   @0x22b5f4 ldr r2, [r3, #0x4]
 *   @0x22b5f8 cmp r2, #0
 *   @0x22b5fc str r0, [r9, #0xc]
 *   @0x22b600 ble 0x22b554 <vorbis_synthesis_headerin+0x5f0>
 *   @0x22b604 b 0x22b110 <vorbis_synthesis_headerin+0x1ac>
 *   @0x22b608 ldrsheq r10, [r2], -r12
 *   @0x22b60c andseq r6, r12, r12, asr #1
 *   @0x22b610 andseq r6, r12, r4, asr #32
 *   @0x22b614 ldrheq r5, [r12], -r4
 *
 * ══ §4/19 HandleCollision  0x1cc500  size 1684  421 条（0x1cc500..0x1ccb94）
 * @func 0x1cc500 0x1ccb94  size 1684  421 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1cc50c→0x757e7c, 0x1cc530→0x542379, 0x1cc534→0x536f68, 0x1cc550→0x536f64, 0x1cc590→0x536f20, 0x1cc7cc→0x757e80, 0x1cc7ec→0x5429a8, 0x1cc824→0x5429b8
 * 调用序列: CInstance::SetPosition(float, float)×6 / CInstance::SetPathPosition(float)×4 / HandleCollision()+0x2bc×2 / CInstance::Collision_Instance(CInstance*, bool)×2 / Perform_Event(CInstance*, CInstance*, int, int)×2 / CInstance::Adapt_Path()×2 / HandleCollision()+0x290 / HandleCollision()+0xec
 * 字段偏移 top8: 0x8×16 / 0xc×9 / 0x190×8 / 0x4×7 / 0x194×7 / 0xc4×6 / 0x18c×6 / 0x10×5
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cc500 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1cc504 sub sp, sp, #60
 *   @0x1cc508 ldr r6, [pc, #0x640]
 *   @0x1cc50c ldr r3, [pc, #0x640]
 *   @0x1cc510 add r6, pc, r6
 *   @0x1cc514 str r6, [sp, #0x8]
 *   @0x1cc518 ldr r3, [r6, r3]
 *   @0x1cc51c str r3, [sp, #0x14]
 *   @0x1cc520 ldrb r3, [r3]
 *   @0x1cc524 cmp r3, #0
 *   @0x1cc528 bne 0x1ccac4 <_Z15HandleCollisionv+0x5c4>
 *   @0x1cc52c ldr r12, [sp, #0x8]
 *   @0x1cc530 ldr r2, [pc, #0x620]
 *   @0x1cc534 ldr r3, [pc, #0x620]
 *   @0x1cc538 ldr r2, [r12, r2]
 *   @0x1cc53c ldr r3, [r12, r3]
 *   @0x1cc540 ldrb r10, [r2]
 *   @0x1cc544 ldr r9, [r3, #0x4]
 *   @0x1cc548 cmp r10, #0
 *   @0x1cc54c bne 0x1cc7e4 <_Z15HandleCollisionv+0x2e4>
 *   @0x1cc550 ldr r3, [pc, #0x608]
 *   @0x1cc554 ldr r3, [r12, r3]
 *   @0x1cc558 str r3, [sp, #0xc]
 *   @0x1cc55c ldr r3, [r3]
 *   @0x1cc560 cmp r3, #0
 *   @0x1cc564 ble 0x1cc7bc <_Z15HandleCollisionv+0x2bc>
 *   @0x1cc568 ldrb r3, [r9, #0x10]
 *   @0x1cc56c cmp r3, #0
 *   @0x1cc570 beq 0x1cc7a4 <_Z15HandleCollisionv+0x2a4>
 *   @0x1cc574 ldr r3, [r9, #0x8]
 *   @0x1cc578 ldr r11, [r3, #0xc4]
 *   @0x1cc57c cmp r11, #0
 *   @0x1cc580 beq 0x1cc7a4 <_Z15HandleCollisionv+0x2a4>
 *   @0x1cc584 ldr r3, [r11, #0x8]
 *   @0x1cc588 cmp r3, #0
 *   @0x1cc58c beq 0x1cc7a4 <_Z15HandleCollisionv+0x2a4>
 *   @0x1cc590 ldr r3, [pc, #0x5cc]
 *   @0x1cc594 ldr r12, [r9, #0xc]
 *   @0x1cc598 ldr r6, [sp, #0x8]
 *   @0x1cc59c str r12, [sp, #0x10]
 *   @0x1cc5a0 ldr r1, [r6, r3]
 *   @0x1cc5a4 ldrd r4, r5, [r1]
 *   @0x1cc5a8 adds r2, r4, #1
 *   @0x1cc5ac adc r3, r5, #0
 *   @0x1cc5b0 strd r2, r3, [r1]
 *   @0x1cc5b4 ldr r8, [r11, #0x8]
 *   @0x1cc5b8 ldr r11, [r11]
 *   @0x1cc5bc ldrb r3, [r8, #0x68]
 *   @0x1cc5c0 cmp r3, #0
 *   @0x1cc5c4 bne 0x1cc790 <_Z15HandleCollisionv+0x290>
 *   @0x1cc5c8 ldrb r3, [r8, #0x69]
 *   @0x1cc5cc cmp r3, #0
 *   @0x1cc5d0 bne 0x1cc790 <_Z15HandleCollisionv+0x290>
 *   @0x1cc5d4 ldrd r2, r3, [r8, #112]
 *   @0x1cc5d8 cmp r4, r2
 *   @0x1cc5dc sbcs r12, r5, r3
 *   @0x1cc5e0 blt 0x1cc790 <_Z15HandleCollisionv+0x290>
 *   @0x1cc5e4 ldr r12, [sp, #0x10]
 *   @0x1cc5e8 ldr r6, [r12, #0xc4]
 *   @0x1cc5ec cmp r6, #0
 *   @0x1cc5f0 beq 0x1cc790 <_Z15HandleCollisionv+0x290>
 *   @0x1cc5f4 ldr r3, [r6, #0x8]
 *   @0x1cc5f8 cmp r3, #0
 *   @0x1cc5fc beq 0x1cc790 <_Z15HandleCollisionv+0x290>
 *   @0x1cc600 ldr r7, [r6, #0x8]
 *   @0x1cc604 ldr r6, [r6]
 *   @0x1cc608 ldrb r3, [r7, #0x68]
 *   @0x1cc60c cmp r3, #0
 *   @0x1cc610 bne 0x1cc5ec <_Z15HandleCollisionv+0xec>
 *   @0x1cc614 ldrb r3, [r7, #0x69]
 *   @0x1cc618 cmp r3, #0
 *   @0x1cc61c bne 0x1cc5ec <_Z15HandleCollisionv+0xec>
 *   @0x1cc620 ldrd r2, r3, [r7, #112]
 *   @0x1cc624 cmp r4, r2
 *   @0x1cc628 sbcs r1, r5, r3
 *   @0x1cc62c blt 0x1cc5ec <_Z15HandleCollisionv+0xec>
 *   @0x1cc630 mov r0, r8
 *   @0x1cc634 mov r1, r7
 *   @0x1cc638 mov r2, #1
 *   @0x1cc63c bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b>
 *   @0x1cc640 cmp r0, #0
 *   @0x1cc644 beq 0x1cc5ec <_Z15HandleCollisionv+0xec>
 *   @0x1cc648 ldrb r3, [r8, #0x66]
 *   @0x1cc64c cmp r3, #0
 *   @0x1cc650 bne 0x1cc660 <_Z15HandleCollisionv+0x160>
 *   @0x1cc654 ldrb r3, [r7, #0x66]
 *   @0x1cc658 cmp r3, #0
 *   @0x1cc65c beq 0x1cc698 <_Z15HandleCollisionv+0x198>
 *   @0x1cc660 ldr r2, [r8, #0xc8]
 *   @0x1cc664 mov r0, r8
 *   @0x1cc668 ldr r1, [r8, #0xc4]
 *   @0x1cc66c bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1cc670 mov r0, r8
 *   @0x1cc674 ldr r1, [r8, #0x130]
 *   @0x1cc678 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf>
 *   @0x1cc67c mov r0, r7
 *   @0x1cc680 ldr r1, [r7, #0xc4]
 *   @0x1cc684 ldr r2, [r7, #0xc8]
 *   @0x1cc688 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1cc68c mov r0, r7
 *   @0x1cc690 ldr r1, [r7, #0x130]
 *   @0x1cc694 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf>
 *   @0x1cc698 mov r0, r8
 *   @0x1cc69c mov r1, r7
 *   @0x1cc6a0 mov r2, #4
 *   @0x1cc6a4 ldr r3, [r7, #0x7c]
 *   @0x1cc6a8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1cc6ac ldr r3, [r8, #0x7c]
 *   @0x1cc6b0 mov r0, r7
 *   @0x1cc6b4 mov r1, r8
 *   @0x1cc6b8 mov r2, #4
 *   @0x1cc6bc bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1cc6c0 ldrb r3, [r8, #0x66]
 *   @0x1cc6c4 cmp r3, #0
 *   @0x1cc6c8 bne 0x1cc6d8 <_Z15HandleCollisionv+0x1d8>
 *   @0x1cc6cc ldrb r3, [r7, #0x66]
 *   @0x1cc6d0 cmp r3, #0
 *   @0x1cc6d4 beq 0x1cc5ec <_Z15HandleCollisionv+0xec>
 *   @0x1cc6d8 mov r0, r8
 *   @0x1cc6dc bl 0x19411c <_ZN9CInstance10Adapt_PathEv>
 *   @0x1cc6e0 mov r0, r7
 *   @0x1cc6e4 bl 0x19411c <_ZN9CInstance10Adapt_PathEv>
 *   @0x1cc6e8 vldr s13, [r8, #180]
 *   @0x1cc6ec vldr s15, [r8, #224]
 *   @0x1cc6f0 vadd.f32 s15, s13, s15
 *   @0x1cc6f4 vldr s14, [r8, #184]
 *   @0x1cc6f8 mov r0, r8
 *   @0x1cc6fc vmov r1, s15
 *   @0x1cc700 vldr s15, [r8, #228]
 *   @0x1cc704 vadd.f32 s15, s14, s15
 *   @0x1cc708 vmov r2, s15
 *   @0x1cc70c bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1cc710 vldr s12, [r7, #180]
 *   @0x1cc714 vldr s14, [r7, #184]
 *   @0x1cc718 vldr s13, [r7, #224]
 *   @0x1cc71c vldr s15, [r7, #228]
 *   @0x1cc720 vadd.f32 s13, s12, s13
 *   @0x1cc724 mov r0, r7
 *   @0x1cc728 vadd.f32 s15, s14, s15
 *   @0x1cc72c vmov r1, s13
 *   @0x1cc730 vmov r2, s15
 *   @0x1cc734 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1cc738 mov r0, r8
 *   @0x1cc73c mov r1, r7
 *   @0x1cc740 mov r2, #1
 *   @0x1cc744 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b>
 *   @0x1cc748 cmp r0, #0
 *   @0x1cc74c beq 0x1cc5ec <_Z15HandleCollisionv+0xec>
 *   @0x1cc750 ldr r2, [r8, #0xc8]
 *   @0x1cc754 mov r0, r8
 *   @0x1cc758 ldr r1, [r8, #0xc4]
 *   @0x1cc75c bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1cc760 mov r0, r8
 *   @0x1cc764 ldr r1, [r8, #0x130]
 *   @0x1cc768 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf>
 *   @0x1cc76c mov r0, r7
 *   @0x1cc770 ldr r1, [r7, #0xc4]
 *   @0x1cc774 ldr r2, [r7, #0xc8]
 *   @0x1cc778 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1cc77c mov r0, r7
 *   @0x1cc780 ldr r1, [r7, #0x130]
 *   @0x1cc784 bl 0x1935c4 <_ZN9CInstance15SetPathPositionEf>
 *   @0x1cc788 cmp r6, #0
 *   @0x1cc78c bne 0x1cc5f4 <_Z15HandleCollisionv+0xf4>
 *   @0x1cc790 cmp r11, #0
 *   @0x1cc794 beq 0x1cc7a4 <_Z15HandleCollisionv+0x2a4>
 *   @0x1cc798 ldr r3, [r11, #0x8]
 *   @0x1cc79c cmp r3, #0
 *   @0x1cc7a0 bne 0x1cc5b4 <_Z15HandleCollisionv+0xb4>
 *   @0x1cc7a4 ldr r6, [sp, #0xc]
 *   @0x1cc7a8 add r10, r10, #1
 *   @0x1cc7ac add r9, r9, #20
 *   @0x1cc7b0 ldr r3, [r6]
 *   @0x1cc7b4 cmp r3, r10
 *   @0x1cc7b8 bgt 0x1cc568 <_Z15HandleCollisionv+0x68>
 *   @0x1cc7bc ldr r12, [sp, #0x14]
 *   @0x1cc7c0 ldrb r3, [r12]
 *   @0x1cc7c4 cmp r3, #0
 *   @0x1cc7c8 beq 0x1cc7dc <_Z15HandleCollisionv+0x2dc>
 *   @0x1cc7cc ldr r3, [pc, #0x394]
 *   @0x1cc7d0 ldr r6, [sp, #0x8]
 *   @0x1cc7d4 ldr r0, [r6, r3]
 *   @0x1cc7d8 bl 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x1cc7dc add sp, sp, #60
 *   @0x1cc7e0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1cc7e4 ldr r9, [pc, #0x380]
 *   @0x1cc7e8 mov r8, #0
 *   @0x1cc7ec ldr r3, [pc, #0x37c]
 *   @0x1cc7f0 add r7, sp, #28
 *   @0x1cc7f4 ldr r6, [sp, #0x8]
 *   @0x1cc7f8 add r9, pc, r9
 *   @0x1cc7fc mov r2, #396
 *   @0x1cc800 str r7, [sp, #0x1c]
 *   @0x1cc804 str r2, [sp, #0x24]
 *   @0x1cc808 str r8, [r9]
 *   @0x1cc80c str r7, [sp, #0x20]
 *   @0x1cc810 ldr r11, [r6, r3]
 *   @0x1cc814 ldr r4, [r11]
 *   @0x1cc818 cmp r4, r8
 *   @0x1cc81c beq 0x1ccb0c <_Z15HandleCollisionv+0x60c>
 *   @0x1cc820 bl 0x1cc24c <_Z10UpdateTreev>
 *   @0x1cc824 ldr r3, [pc, #0x348]
 *   @0x1cc828 ldr r12, [sp, #0x8]
 *   @0x1cc82c ldr r5, [r12, r3]
 *   @0x1cc830 ldr r6, [r5]
 *   @0x1cc834 cmp r6, r5
 *   @0x1cc838 beq 0x1ccb20 <_Z15HandleCollisionv+0x620>
 *   @0x1cc83c ldr r9, [pc, #0x334]
 *   @0x1cc840 add r12, sp, #40
 *   @0x1cc844 str r12, [sp, #0xc]
 *   @0x1cc848 add r12, sp, #24
 *   @0x1cc84c add r9, pc, r9
 *   @0x1cc850 str r12, [sp, #0x10]
 *   @0x1cc854 b 0x1cc950 <_Z15HandleCollisionv+0x450>
 *   @0x1cc858 ldrb r1, [r4, #0x69]
 *   @0x1cc85c cmp r1, #0
 *   @0x1cc860 bne 0x1cc968 <_Z15HandleCollisionv+0x468>
 *   @0x1cc864 ldr r0, [r4, #0xe8]
 *   @0x1cc868 add r3, sp, #24
 *   @0x1cc86c ldr lr, [r4, #0xf0]
 *   @0x1cc870 add r2, sp, #40
 *   @0x1cc874 ldr r12, [r4, #0xec]
 *   @0x1cc878 str r1, [sp, #0x18]
 *   @0x1cc87c cmp lr, r0
 *   @0x1cc880 strle lr, [sp, #0x28]
 *   @0x1cc884 strgt r0, [sp, #0x28]
 *   @0x1cc888 ldr r1, [r4, #0xf4]
 *   @0x1cc88c cmp lr, r0
 *   @0x1cc890 strge lr, [sp, #0x30]
 *   @0x1cc894 strlt r0, [sp, #0x30]
 *   @0x1cc898 ldr r10, [pc, #0x2dc]
 *   @0x1cc89c ldr lr, [sp, #0x8]
 *   @0x1cc8a0 ldr r0, [r11]
 *   @0x1cc8a4 cmp r1, r12
 *   @0x1cc8a8 strle r1, [sp, #0x2c]
 *   @0x1cc8ac strgt r12, [sp, #0x2c]
 *   @0x1cc8b0 cmp r1, r12
 *   @0x1cc8b4 strge r1, [sp, #0x34]
 *   @0x1cc8b8 strlt r12, [sp, #0x34]
 *   @0x1cc8bc ldr r12, [lr, r10]
 *   @0x1cc8c0 add r10, r4, #396
 *   @0x1cc8c4 ldr r1, [r0, #0x10]
 *   @0x1cc8c8 str r4, [sp, #0x4]
 *   @0x1cc8cc str r12, [sp]
 *   @0x1cc8d0 bl 0x10d558 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPNS2_4NodeEPNS2_4RectERiPFbS1_PvES8_>
 *   @0x1cc8d4 ldr r3, [r4, #0x194]
 *   @0x1cc8d8 ldr r6, [r6]
 *   @0x1cc8dc cmp r3, r5
 *   @0x1cc8e0 beq 0x1ccadc <_Z15HandleCollisionv+0x5dc>
 *   @0x1cc8e4 ldrb r3, [r4, #0xb0]
 *   @0x1cc8e8 str r10, [r4, #0x18c]
 *   @0x1cc8ec cmp r3, #0
 *   @0x1cc8f0 str r10, [r4, #0x190]
 *   @0x1cc8f4 str r8, [r4, #0x194]
 *   @0x1cc8f8 beq 0x1cc940 <_Z15HandleCollisionv+0x440>
 *   @0x1cc8fc ldr r0, [r4, #0xac]
 *   @0x1cc900 cmp r0, #0
 *   @0x1cc904 ldrlt r0, [r4, #0x8c]
 *   @0x1cc908 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1cc90c cmp r0, #0
 *   @0x1cc910 beq 0x1cc940 <_Z15HandleCollisionv+0x440>
 *   @0x1cc914 ldr r3, [r0, #0x18]
 *   @0x1cc918 cmp r3, #1
 *   @0x1cc91c ble 0x1cc940 <_Z15HandleCollisionv+0x440>
 *   @0x1cc920 ldr r3, [sp, #0x1c]
 *   @0x1cc924 cmp r10, r3
 *   @0x1cc928 beq 0x1cc940 <_Z15HandleCollisionv+0x440>
 *   @0x1cc92c str r3, [r4, #0x18c]
 *   @0x1cc930 str r7, [r4, #0x190]
 *   @0x1cc934 str r10, [sp, #0x1c]
 *   @0x1cc938 str r10, [r3, #0x4]
 *   @0x1cc93c str r7, [r4, #0x194]
 *   @0x1cc940 ldr r3, [r9, #0xc]
 *   @0x1cc944 cmp r6, r5
 *   @0x1cc948 str r3, [r4, #0x188]
 *   @0x1cc94c beq 0x1cc990 <_Z15HandleCollisionv+0x490>
 *   @0x1cc950 ldr r4, [r5, #0x8]
 *   @0x1cc954 subs r4, r6, r4
 *   @0x1cc958 beq 0x1cc968 <_Z15HandleCollisionv+0x468>
 *   @0x1cc95c ldrb r3, [r4, #0x68]
 *   @0x1cc960 cmp r3, #0
 *   @0x1cc964 beq 0x1cc858 <_Z15HandleCollisionv+0x358>
 *   @0x1cc968 ldr r3, [r4, #0x194]
 *   @0x1cc96c ldr r6, [r6]
 *   @0x1cc970 cmp r3, r5
 *   @0x1cc974 beq 0x1ccaf4 <_Z15HandleCollisionv+0x5f4>
 *   @0x1cc978 cmp r6, r5
 *   @0x1cc97c add r3, r4, #396
 *   @0x1cc980 str r8, [r4, #0x194]
 *   @0x1cc984 str r3, [r4, #0x18c]
 *   @0x1cc988 str r3, [r4, #0x190]
 *   @0x1cc98c bne 0x1cc950 <_Z15HandleCollisionv+0x450>
 *   @0x1cc990 ldr r2, [pc, #0x1e8]
 *   @0x1cc994 ldr r1, [sp, #0x1c]
 *   @0x1cc998 add r2, pc, r2
 *   @0x1cc99c ldr r3, [r5]
 *   @0x1cc9a0 ldr r4, [r2]
 *   @0x1cc9a4 ldr r0, [pc, #0x1d8]
 *   @0x1cc9a8 mov r2, #0
 *   @0x1cc9ac ldr r6, [pc, #0x1d4]
 *   @0x1cc9b0 cmp r3, r2
 *   @0x1cc9b4 add r0, pc, r0
 *   @0x1cc9b8 ldr r12, [pc, #0x1cc]
 *   @0x1cc9bc ldr r8, [r0, #0xc]
 *   @0x1cc9c0 add r8, r8, #1
 *   @0x1cc9c4 str r8, [r0, #0xc]
 *   @0x1cc9c8 mov r0, r6
 *   @0x1cc9cc ldr r6, [sp, #0x8]
 *   @0x1cc9d0 ldr r0, [r6, r0]
 *   @0x1cc9d4 str r2, [r0]
 *   @0x1cc9d8 ldr r0, [r6, r12]
 *   @0x1cc9dc str r2, [r0]
 *   @0x1cc9e0 beq 0x1cc9f4 <_Z15HandleCollisionv+0x4f4>
 *   @0x1cc9e4 cmp r3, r5
 *   @0x1cc9e8 strne r3, [r3]
 *   @0x1cc9ec strne r3, [r3, #0x4]
 *   @0x1cc9f0 strne r2, [r3, #0x8]
 *   @0x1cc9f4 ldr r3, [r5, #0x4]
 *   @0x1cc9f8 cmp r3, #0
 *   @0x1cc9fc beq 0x1cca14 <_Z15HandleCollisionv+0x514>
 *   @0x1cca00 cmp r3, r5
 *   @0x1cca04 strne r3, [r3]
 *   @0x1cca08 strne r3, [r3, #0x4]
 *   @0x1cca0c movne r2, #0
 *   @0x1cca10 strne r2, [r3, #0x8]
 *   @0x1cca14 cmp r1, r7
 *   @0x1cca18 str r5, [r5]
 *   @0x1cca1c str r5, [r5, #0x4]
 *   @0x1cca20 beq 0x1cca94 <_Z15HandleCollisionv+0x594>
 *   @0x1cca24 ldr r6, [sp, #0x24]
 *   @0x1cca28 mov r12, r5
 *   @0x1cca2c mov r0, r5
 *   @0x1cca30 mov r8, #0
 *   @0x1cca34 rsb r6, r6, #0
 *   @0x1cca38 add r3, r1, r6
 *   @0x1cca3c ldr r1, [r1]
 *   @0x1cca40 add r2, r3, #396
 *   @0x1cca44 ldr r9, [r3, #0x194]
 *   @0x1cca48 cmp r9, r7
 *   @0x1cca4c ldreq r10, [r3, #0x190]
 *   @0x1cca50 ldreq r9, [r3, #0x18c]
 *   @0x1cca54 streq r10, [r9, #0x4]
 *   @0x1cca58 ldreq r10, [r3, #0x190]
 *   @0x1cca5c streq r9, [r10]
 *   @0x1cca60 cmp r0, r2
 *   @0x1cca64 str r2, [r3, #0x18c]
 *   @0x1cca68 str r2, [r3, #0x190]
 *   @0x1cca6c movne r12, r2
 *   @0x1cca70 strne r0, [r3, #0x18c]
 *   @0x1cca74 str r8, [r3, #0x194]
 *   @0x1cca78 strne r5, [r3, #0x190]
 *   @0x1cca7c strne r2, [r0, #0x4]
 *   @0x1cca80 mov r0, r12
 *   @0x1cca84 strne r5, [r3, #0x194]
 *   @0x1cca88 cmp r1, r7
 *   @0x1cca8c bne 0x1cca38 <_Z15HandleCollisionv+0x538>
 *   @0x1cca90 str r12, [r5]
 *   @0x1cca94 ldr r6, [pc, #0xf4]
 *   @0x1cca98 cmp r4, #0
 *   @0x1cca9c mov r5, #0
 *   @0x1ccaa0 add r6, pc, r6
 *   @0x1ccaa4 ble 0x1cc7bc <_Z15HandleCollisionv+0x2bc>
 *   @0x1ccaa8 ldr r0, [r6, #0x8]
 *   @0x1ccaac add r0, r0, r5, lsl #3
 *   @0x1ccab0 add r5, r5, #1
 *   @0x1ccab4 bl 0x1cc034 <_Z16processCollisionP10SCollision>
 *   @0x1ccab8 cmp r5, r4
 *   @0x1ccabc bne 0x1ccaa8 <_Z15HandleCollisionv+0x5a8>
 *   @0x1ccac0 b 0x1cc7bc <_Z15HandleCollisionv+0x2bc>
 *   @0x1ccac4 ldr r3, [pc, #0x9c]
 *   @0x1ccac8 mov r1, #6
 *   @0x1ccacc mov r2, #0
 *   @0x1ccad0 ldr r0, [r6, r3]
 *   @0x1ccad4 bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x1ccad8 b 0x1cc52c <_Z15HandleCollisionv+0x2c>
 *   @0x1ccadc ldr r2, [r4, #0x190]
 *   @0x1ccae0 ldr r3, [r4, #0x18c]
 *   @0x1ccae4 str r2, [r3, #0x4]
 *   @0x1ccae8 ldr r2, [r4, #0x190]
 *   @0x1ccaec str r3, [r2]
 *   @0x1ccaf0 b 0x1cc8e4 <_Z15HandleCollisionv+0x3e4>
 *   @0x1ccaf4 ldr r2, [r4, #0x190]
 *   @0x1ccaf8 ldr r3, [r4, #0x18c]
 *   @0x1ccafc str r2, [r3, #0x4]
 *   @0x1ccb00 ldr r2, [r4, #0x190]
 *   @0x1ccb04 str r3, [r2]
 *   @0x1ccb08 b 0x1cc978 <_Z15HandleCollisionv+0x478>
 *   @0x1ccb0c ldr r3, [pc, #0x60]
 *   @0x1ccb10 mov r1, r7
 *   @0x1ccb14 ldr r5, [r6, r3]
 *   @0x1ccb18 ldr r3, [r5]
 *   @0x1ccb1c b 0x1cc9a4 <_Z15HandleCollisionv+0x4a4>
 *   @0x1ccb20 ldr r2, [pc, #0x60]
 *   @0x1ccb24 ldr r1, [r9, #0xc]
 *   @0x1ccb28 ldr r3, [pc, #0x5c]
 *   @0x1ccb2c add r1, r1, #1
 *   @0x1ccb30 str r1, [r9, #0xc]
 *   @0x1ccb34 ldr r2, [r12, r2]
 *   @0x1ccb38 ldr r1, [sp, #0x1c]
 *   @0x1ccb3c ldr r4, [r9]
 *   @0x1ccb40 str r8, [r2]
 *   @0x1ccb44 ldr r3, [r12, r3]
 *   @0x1ccb48 str r8, [r3]
 *   @0x1ccb4c b 0x1cc9f4 <_Z15HandleCollisionv+0x4f4>
 *   @0x1ccb50 eoreq r5, r2, r0, asr #14
 *   @0x1ccb54 .word 0xffffbf18
 *   @0x1ccb58 .word 0xffffea30
 *   @0x1ccb5c .word 0xffffea90
 *   @0x1ccb60 .word 0xffffea8c
 *   @0x1ccb64 .word 0xffffdeb4
 *   @0x1ccb68 .word 0xffffbf1c
 *   @0x1ccb6c mlaseq r7, r8, r1, r6
 *   @0x1ccb70 .word 0xffffc5f4
 *   @0x1ccb74 .word 0xffffeee4
 *   @0x1ccb78 eorseq r6, r7, r4, asr #2
 *   @0x1ccb7c .word 0xffffeef0
 *   @0x1ccb80 ldrshteq r5, [r7], -r8
 *   @0x1ccb84 ldrsbteq r5, [r7], -r12
 *   @0x1ccb88 .word 0xffffeee0
 *   @0x1ccb8c .word 0xffffeee8
 *   @0x1ccb90 ldrshteq r5, [r7], -r0
 *
 * ══ §5/19 Extension_Prepare  0xf5834  size 1668  417 条（0xf5834..0xf5eb8）
 * @func 0xf5834 0xf5eb8  size 1668  417 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xf587c→0x483670, 0xf5960→0x483658, 0xf5a6c→0x48366c, 0xf5a98→0x483668, 0xf5a9c→0x48365c, 0xf5b04→0x483664, 0xf5e50→0x483658
 * 调用序列: 0xb65b0×6 / CExtensionFunction::GetId()×6 / CExtensionPackage::GetIncludesFile(int)×5 / CExtensionPackage::GetFolder()×3 / 0xb6574×3 / CExtensionPackage::GetIncludesCount()×3 / CExtensionFile::GetFunctionsCount()×3 / CExtensionFile::GetFunctionsData(int)×3
 * 字段偏移 top8: 0x14×8 / 0x2×8 / 0x1c×7 / 0x3c×5 / 0x4×4 / 0x20×4 / 0x38×4 / 0x18×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5834 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf5838 sub sp, sp, #2192
 *   @0xf583c ldr r9, [pc, #0x62c]
 *   @0xf5840 sub sp, sp, #12
 *   @0xf5844 ldr r3, [pc, #0x628]
 *   @0xf5848 add r2, sp, #148
 *   @0xf584c add r9, pc, r9
 *   @0xf5850 str r2, [sp, #0x24]
 *   @0xf5854 mov r8, #0
 *   @0xf5858 mov r2, #1024
 *   @0xf585c ldr r3, [r9, r3]
 *   @0xf5860 add r0, sp, #148
 *   @0xf5864 mov r1, r8
 *   @0xf5868 str r8, [sp, #0x50]
 *   @0xf586c str r3, [sp, #0x40]
 *   @0xf5870 ldr r3, [r3]
 *   @0xf5874 str r3, [sp, #0x894]
 *   @0xf5878 bl 0xb65b0 <memset@plt>
 *   @0xf587c ldr r3, [pc, #0x5f4]
 *   @0xf5880 ldr r3, [r9, r3]
 *   @0xf5884 str r3, [sp, #0x3c]
 *   @0xf5888 ldr r3, [r3]
 *   @0xf588c cmp r3, r8
 *   @0xf5890 ble 0xf5e50 <_Z17Extension_Preparev+0x61c>
 *   @0xf5894 ldr r10, [pc, #0x5e0]
 *   @0xf5898 ldr r2, [pc, #0x5e0]
 *   @0xf589c add r10, pc, r10
 *   @0xf58a0 add r2, pc, r2
 *   @0xf58a4 str r2, [sp, #0x14]
 *   @0xf58a8 b 0xf58c8 <_Z17Extension_Preparev+0x94>
 *   @0xf58ac ldr r3, [r10, #0x4]
 *   @0xf58b0 str r0, [r3, r8, lsl #2]
 *   @0xf58b4 ldr r12, [sp, #0x3c]
 *   @0xf58b8 add r8, r8, #1
 *   @0xf58bc ldr r3, [r12]
 *   @0xf58c0 cmp r3, r8
 *   @0xf58c4 ble 0xf5960 <_Z17Extension_Preparev+0x12c>
 *   @0xf58c8 ldr r3, [r10, #0x4]
 *   @0xf58cc ldr r7, [r3, r8, lsl #2]
 *   @0xf58d0 mov r0, r7
 *   @0xf58d4 bl 0xf55fc <_ZN17CExtensionPackage9GetFolderEv>
 *   @0xf58d8 ldr r1, [sp, #0x14]
 *   @0xf58dc bl 0xb6574 <strcmp@plt>
 *   @0xf58e0 cmp r0, #0
 *   @0xf58e4 movne r6, #0
 *   @0xf58e8 beq 0xf58ac <_Z17Extension_Preparev+0x78>
 *   @0xf58ec mov r0, r7
 *   @0xf58f0 bl 0xf5630 <_ZN17CExtensionPackage16GetIncludesCountEv>
 *   @0xf58f4 cmp r6, r0
 *   @0xf58f8 bge 0xf58b4 <_Z17Extension_Preparev+0x80>
 *   @0xf58fc mov r0, r7
 *   @0xf5900 mov r1, r6
 *   @0xf5904 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi>
 *   @0xf5908 mov r4, #0
 *   @0xf590c mov r5, r0
 *   @0xf5910 b 0xf5948 <_Z17Extension_Preparev+0x114>
 *   @0xf5914 mov r1, r4
 *   @0xf5918 mov r0, r5
 *   @0xf591c bl 0xf5390 <_ZN14CExtensionFile16GetConstantsDataEi>
 *   @0xf5920 bl 0xf490c <_ZN18CExtensionConstant7GetNameEv>
 *   @0xf5924 mov r1, r4
 *   @0xf5928 add r4, r4, #1
 *   @0xf592c mov r11, r0
 *   @0xf5930 mov r0, r5
 *   @0xf5934 bl 0xf5390 <_ZN14CExtensionFile16GetConstantsDataEi>
 *   @0xf5938 bl 0xf4940 <_ZN18CExtensionConstant8GetValueEv>
 *   @0xf593c mov r1, r0
 *   @0xf5940 mov r0, r11
 *   @0xf5944 bl 0xf1a10 <_Z17Code_Constant_AddPKcS0_>
 *   @0xf5948 mov r0, r5
 *   @0xf594c bl 0xf5058 <_ZN14CExtensionFile17GetConstantsCountEv>
 *   @0xf5950 cmp r4, r0
 *   @0xf5954 blt 0xf5914 <_Z17Extension_Preparev+0xe0>
 *   @0xf5958 add r6, r6, #1
 *   @0xf595c b 0xf58ec <_Z17Extension_Preparev+0xb8>
 *   @0xf5960 ldr r2, [pc, #0x51c]
 *   @0xf5964 cmp r3, #0
 *   @0xf5968 mov r10, #0
 *   @0xf596c ldr r6, [r9, r2]
 *   @0xf5970 str r10, [r6]
 *   @0xf5974 ble 0xf5e68 <_Z17Extension_Preparev+0x634>
 *   @0xf5978 ldr r11, [pc, #0x508]
 *   @0xf597c ldr r2, [pc, #0x508]
 *   @0xf5980 add r11, pc, r11
 *   @0xf5984 add r2, pc, r2
 *   @0xf5988 str r2, [sp, #0x14]
 *   @0xf598c b 0xf59a4 <_Z17Extension_Preparev+0x170>
 *   @0xf5990 ldr r12, [sp, #0x3c]
 *   @0xf5994 add r10, r10, #1
 *   @0xf5998 ldr r3, [r12]
 *   @0xf599c cmp r3, r10
 *   @0xf59a0 ble 0xf5a48 <_Z17Extension_Preparev+0x214>
 *   @0xf59a4 ldr r3, [r11, #0x4]
 *   @0xf59a8 ldr r8, [r3, r10, lsl #2]
 *   @0xf59ac cmp r8, #0
 *   @0xf59b0 beq 0xf5990 <_Z17Extension_Preparev+0x15c>
 *   @0xf59b4 mov r0, r8
 *   @0xf59b8 bl 0xf55fc <_ZN17CExtensionPackage9GetFolderEv>
 *   @0xf59bc ldr r1, [sp, #0x14]
 *   @0xf59c0 bl 0xb6574 <strcmp@plt>
 *   @0xf59c4 cmp r0, #0
 *   @0xf59c8 movne r7, #0
 *   @0xf59cc beq 0xf5990 <_Z17Extension_Preparev+0x15c>
 *   @0xf59d0 mov r0, r8
 *   @0xf59d4 bl 0xf5630 <_ZN17CExtensionPackage16GetIncludesCountEv>
 *   @0xf59d8 cmp r7, r0
 *   @0xf59dc bge 0xf5990 <_Z17Extension_Preparev+0x15c>
 *   @0xf59e0 mov r0, r8
 *   @0xf59e4 mov r1, r7
 *   @0xf59e8 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi>
 *   @0xf59ec mov r4, #0
 *   @0xf59f0 mov r5, r0
 *   @0xf59f4 b 0xf59fc <_Z17Extension_Preparev+0x1c8>
 *   @0xf59f8 add r4, r4, #1
 *   @0xf59fc mov r0, r5
 *   @0xf5a00 bl 0xf5044 <_ZN14CExtensionFile17GetFunctionsCountEv>
 *   @0xf5a04 cmp r4, r0
 *   @0xf5a08 bge 0xf5a40 <_Z17Extension_Preparev+0x20c>
 *   @0xf5a0c mov r1, r4
 *   @0xf5a10 mov r0, r5
 *   @0xf5a14 bl 0xf5050 <_ZN14CExtensionFile16GetFunctionsDataEi>
 *   @0xf5a18 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv>
 *   @0xf5a1c ldr r3, [r6]
 *   @0xf5a20 cmp r0, r3
 *   @0xf5a24 ble 0xf59f8 <_Z17Extension_Preparev+0x1c4>
 *   @0xf5a28 mov r1, r4
 *   @0xf5a2c mov r0, r5
 *   @0xf5a30 bl 0xf5050 <_ZN14CExtensionFile16GetFunctionsDataEi>
 *   @0xf5a34 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv>
 *   @0xf5a38 str r0, [r6]
 *   @0xf5a3c b 0xf59f8 <_Z17Extension_Preparev+0x1c4>
 *   @0xf5a40 add r7, r7, #1
 *   @0xf5a44 b 0xf59d0 <_Z17Extension_Preparev+0x19c>
 *   @0xf5a48 ldr r0, [r6]
 *   @0xf5a4c add r0, r0, #1
 *   @0xf5a50 lsl r0, r0, #2
 *   @0xf5a54 ldr r4, [pc, #0x434]
 *   @0xf5a58 mov r2, #148
 *   @0xf5a5c mov r3, #1
 *   @0xf5a60 add r4, pc, r4
 *   @0xf5a64 mov r1, r4
 *   @0xf5a68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf5a6c ldr lr, [pc, #0x420]
 *   @0xf5a70 ldr r12, [r6]
 *   @0xf5a74 mov r3, #1
 *   @0xf5a78 mov r1, r4
 *   @0xf5a7c mov r2, #149
 *   @0xf5a80 ldr lr, [r9, lr]
 *   @0xf5a84 add r12, r12, r3
 *   @0xf5a88 str lr, [sp, #0x20]
 *   @0xf5a8c str r0, [lr]
 *   @0xf5a90 lsl r0, r12, #2
 *   @0xf5a94 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf5a98 ldr lr, [pc, #0x3f8]
 *   @0xf5a9c ldr r12, [pc, #0x3f8]
 *   @0xf5aa0 mov r3, #150
 *   @0xf5aa4 ldr r1, [r6]
 *   @0xf5aa8 mov r2, r4
 *   @0xf5aac ldr lr, [r9, lr]
 *   @0xf5ab0 add r1, r1, #1
 *   @0xf5ab4 str lr, [sp, #0x28]
 *   @0xf5ab8 lsl r1, r1, #2
 *   @0xf5abc str r0, [lr]
 *   @0xf5ac0 ldr r0, [r9, r12]
 *   @0xf5ac4 add r0, r0, #4
 *   @0xf5ac8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xf5acc ldr r2, [r6]
 *   @0xf5ad0 ldr r12, [sp, #0x28]
 *   @0xf5ad4 mvn r1, #0
 *   @0xf5ad8 add r2, r2, #1
 *   @0xf5adc ldr r0, [r12]
 *   @0xf5ae0 lsl r2, r2, #2
 *   @0xf5ae4 bl 0xb65b0 <memset@plt>
 *   @0xf5ae8 ldr r0, [r6]
 *   @0xf5aec mov r1, r4
 *   @0xf5af0 mov r2, #153
 *   @0xf5af4 add r0, r0, #1
 *   @0xf5af8 mov r3, #1
 *   @0xf5afc lsl r0, r0, #2
 *   @0xf5b00 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf5b04 ldr r3, [pc, #0x394]
 *   @0xf5b08 ldr r2, [r6]
 *   @0xf5b0c mvn r1, #0
 *   @0xf5b10 ldr r3, [r9, r3]
 *   @0xf5b14 add r2, r2, #1
 *   @0xf5b18 lsl r2, r2, #2
 *   @0xf5b1c str r3, [sp, #0x2c]
 *   @0xf5b20 str r0, [r3]
 *   @0xf5b24 bl 0xb65b0 <memset@plt>
 *   @0xf5b28 ldr r2, [r6]
 *   @0xf5b2c mvn r1, #0
 *   @0xf5b30 ldr r12, [sp, #0x20]
 *   @0xf5b34 add r2, r2, #1
 *   @0xf5b38 ldr r0, [r12]
 *   @0xf5b3c lsl r2, r2, #2
 *   @0xf5b40 bl 0xb65b0 <memset@plt>
 *   @0xf5b44 ldr r12, [sp, #0x3c]
 *   @0xf5b48 ldr r3, [r12]
 *   @0xf5b4c cmp r3, #0
 *   @0xf5b50 ble 0xf5e2c <_Z17Extension_Preparev+0x5f8>
 *   @0xf5b54 ldr r12, [pc, #0x348]
 *   @0xf5b58 add r8, sp, #80
 *   @0xf5b5c add r12, pc, r12
 *   @0xf5b60 str r12, [sp, #0x44]
 *   @0xf5b64 ldr r12, [pc, #0x33c]
 *   @0xf5b68 add r12, pc, r12
 *   @0xf5b6c str r12, [sp, #0x48]
 *   @0xf5b70 mov r12, #0
 *   @0xf5b74 str r12, [sp, #0x38]
 *   @0xf5b78 ldr r12, [pc, #0x32c]
 *   @0xf5b7c add r12, pc, r12
 *   @0xf5b80 str r12, [sp, #0x4c]
 *   @0xf5b84 ldr r12, [pc, #0x324]
 *   @0xf5b88 add r12, pc, r12
 *   @0xf5b8c str r12, [sp, #0x30]
 *   @0xf5b90 ldr r12, [pc, #0x31c]
 *   @0xf5b94 add r12, pc, r12
 *   @0xf5b98 str r12, [sp, #0x34]
 *   @0xf5b9c b 0xf5bbc <_Z17Extension_Preparev+0x388>
 *   @0xf5ba0 ldr r12, [sp, #0x3c]
 *   @0xf5ba4 ldr r3, [r12]
 *   @0xf5ba8 ldr r12, [sp, #0x38]
 *   @0xf5bac add r12, r12, #1
 *   @0xf5bb0 str r12, [sp, #0x38]
 *   @0xf5bb4 cmp r3, r12
 *   @0xf5bb8 ble 0xf5e2c <_Z17Extension_Preparev+0x5f8>
 *   @0xf5bbc ldr r12, [sp, #0x44]
 *   @0xf5bc0 ldr r3, [r12, #0x4]
 *   @0xf5bc4 ldr r12, [sp, #0x38]
 *   @0xf5bc8 ldr r7, [r3, r12, lsl #2]
 *   @0xf5bcc cmp r7, #0
 *   @0xf5bd0 beq 0xf5ba0 <_Z17Extension_Preparev+0x36c>
 *   @0xf5bd4 bl 0x28fd5c <_Z14GetFilePrePendv>
 *   @0xf5bd8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf5bdc mov r4, r0
 *   @0xf5be0 mov r0, r7
 *   @0xf5be4 bl 0xf55fc <_ZN17CExtensionPackage9GetFolderEv>
 *   @0xf5be8 ldr r1, [sp, #0x48]
 *   @0xf5bec bl 0xb6574 <strcmp@plt>
 *   @0xf5bf0 cmp r0, #0
 *   @0xf5bf4 beq 0xf5ba0 <_Z17Extension_Preparev+0x36c>
 *   @0xf5bf8 mov r3, r4
 *   @0xf5bfc mov r1, #1024
 *   @0xf5c00 ldr r2, [sp, #0x4c]
 *   @0xf5c04 add r0, sp, #148
 *   @0xf5c08 bl 0xb65c8 <snprintf@plt>
 *   @0xf5c0c mov r0, r4
 *   @0xf5c10 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf5c14 mov r12, #0
 *   @0xf5c18 add r3, sp, #1168
 *   @0xf5c1c mov r5, r12
 *   @0xf5c20 add r3, r3, #8
 *   @0xf5c24 str r12, [sp, #0x1c]
 *   @0xf5c28 sub r3, r3, #4
 *   @0xf5c2c str r3, [sp, #0x18]
 *   @0xf5c30 mov r0, r7
 *   @0xf5c34 bl 0xf5630 <_ZN17CExtensionPackage16GetIncludesCountEv>
 *   @0xf5c38 ldr r12, [sp, #0x1c]
 *   @0xf5c3c cmp r12, r0
 *   @0xf5c40 bge 0xf5ba0 <_Z17Extension_Preparev+0x36c>
 *   @0xf5c44 ldr r1, [sp, #0x1c]
 *   @0xf5c48 mov r0, r7
 *   @0xf5c4c bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi>
 *   @0xf5c50 mov r6, #0
 *   @0xf5c54 str r0, [sp, #0x14]
 *   @0xf5c58 ldr r0, [sp, #0x14]
 *   @0xf5c5c bl 0xf5044 <_ZN14CExtensionFile17GetFunctionsCountEv>
 *   @0xf5c60 cmp r6, r0
 *   @0xf5c64 bge 0xf5d98 <_Z17Extension_Preparev+0x564>
 *   @0xf5c68 mov r1, r6
 *   @0xf5c6c ldr r0, [sp, #0x14]
 *   @0xf5c70 bl 0xf5050 <_ZN14CExtensionFile16GetFunctionsDataEi>
 *   @0xf5c74 ldr r12, [sp, #0x2c]
 *   @0xf5c78 mov r10, #0
 *   @0xf5c7c mov r9, r10
 *   @0xf5c80 ldr r11, [r12]
 *   @0xf5c84 str r7, [r0, #0x60]
 *   @0xf5c88 mov r4, r0
 *   @0xf5c8c bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv>
 *   @0xf5c90 str r4, [r11, r0, lsl #2]
 *   @0xf5c94 mov r1, r9
 *   @0xf5c98 mov r0, r4
 *   @0xf5c9c bl 0xf4974 <_ZN18CExtensionFunction10GetArgTypeEi>
 *   @0xf5ca0 add r9, r9, #1
 *   @0xf5ca4 cmp r0, #1
 *   @0xf5ca8 movne r0, r5
 *   @0xf5cac cmp r9, #17
 *   @0xf5cb0 str r0, [r8, r10]
 *   @0xf5cb4 add r10, r10, #4
 *   @0xf5cb8 bne 0xf5c94 <_Z17Extension_Preparev+0x460>
 *   @0xf5cbc mov r0, r4
 *   @0xf5cc0 bl 0xf4c48 <_ZN18CExtensionFunction13GetReturnTypeEv>
 *   @0xf5cc4 subs r3, r0, #1
 *   @0xf5cc8 mov r0, r4
 *   @0xf5ccc rsbs r10, r3, #0
 *   @0xf5cd0 adcs r10, r10, r3
 *   @0xf5cd4 bl 0xf4c18 <_ZN18CExtensionFunction7GetKindEv>
 *   @0xf5cd8 mov r1, #0
 *   @0xf5cdc mov r2, #1024
 *   @0xf5ce0 cmp r0, #12
 *   @0xf5ce4 ldr r0, [sp, #0x18]
 *   @0xf5ce8 beq 0xf5da8 <_Z17Extension_Preparev+0x574>
 *   @0xf5cec bl 0xb65b0 <memset@plt>
 *   @0xf5cf0 ldr r1, [sp, #0x1c]
 *   @0xf5cf4 mov r0, r7
 *   @0xf5cf8 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi>
 *   @0xf5cfc bl 0xf4fac <_ZN14CExtensionFile11GetFileNameEv>
 *   @0xf5d00 ldr r2, [sp, #0x30]
 *   @0xf5d04 add r3, sp, #148
 *   @0xf5d08 mov r1, #1024
 *   @0xf5d0c mov r9, r0
 *   @0xf5d10 str r0, [sp]
 *   @0xf5d14 ldr r0, [sp, #0x18]
 *   @0xf5d18 bl 0xb65c8 <snprintf@plt>
 *   @0xf5d1c ldr r12, [sp, #0x20]
 *   @0xf5d20 mov r0, r4
 *   @0xf5d24 ldr r11, [r12]
 *   @0xf5d28 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv>
 *   @0xf5d2c mov r12, r0
 *   @0xf5d30 mov r0, r4
 *   @0xf5d34 str r12, [sp, #0xc]
 *   @0xf5d38 bl 0xf4be4 <_ZN18CExtensionFunction15GetExternalNameEv>
 *   @0xf5d3c mov r1, r0
 *   @0xf5d40 mov r0, r4
 *   @0xf5d44 str r1, [sp, #0x10]
 *   @0xf5d48 bl 0xf4c38 <_ZN18CExtensionFunction11GetArgCountEv>
 *   @0xf5d4c ldr r1, [sp, #0x10]
 *   @0xf5d50 mov r2, #1
 *   @0xf5d54 stm sp, {r8, r10}
 *   @0xf5d58 mov r3, r0
 *   @0xf5d5c mov r0, r9
 *   @0xf5d60 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii>
 *   @0xf5d64 ldr r12, [sp, #0xc]
 *   @0xf5d68 str r0, [r11, r12, lsl #2]
 *   @0xf5d6c ldr r12, [sp, #0x28]
 *   @0xf5d70 mov r0, r4
 *   @0xf5d74 add r6, r6, #1
 *   @0xf5d78 ldr r4, [r12]
 *   @0xf5d7c bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv>
 *   @0xf5d80 mov r3, #2
 *   @0xf5d84 str r3, [r4, r0, lsl #2]
 *   @0xf5d88 ldr r0, [sp, #0x14]
 *   @0xf5d8c bl 0xf5044 <_ZN14CExtensionFile17GetFunctionsCountEv>
 *   @0xf5d90 cmp r6, r0
 *   @0xf5d94 blt 0xf5c68 <_Z17Extension_Preparev+0x434>
 *   @0xf5d98 ldr r12, [sp, #0x1c]
 *   @0xf5d9c add r12, r12, #1
 *   @0xf5da0 str r12, [sp, #0x1c]
 *   @0xf5da4 b 0xf5c30 <_Z17Extension_Preparev+0x3fc>
 *   @0xf5da8 bl 0xb65b0 <memset@plt>
 *   @0xf5dac ldr r1, [sp, #0x1c]
 *   @0xf5db0 mov r0, r7
 *   @0xf5db4 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi>
 *   @0xf5db8 bl 0xf4fac <_ZN14CExtensionFile11GetFileNameEv>
 *   @0xf5dbc ldr r2, [sp, #0x34]
 *   @0xf5dc0 add r3, sp, #148
 *   @0xf5dc4 mov r1, #1024
 *   @0xf5dc8 mov r9, r0
 *   @0xf5dcc str r0, [sp]
 *   @0xf5dd0 ldr r0, [sp, #0x18]
 *   @0xf5dd4 bl 0xb65c8 <snprintf@plt>
 *   @0xf5dd8 ldr r12, [sp, #0x20]
 *   @0xf5ddc mov r0, r4
 *   @0xf5de0 ldr r11, [r12]
 *   @0xf5de4 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv>
 *   @0xf5de8 mov r12, r0
 *   @0xf5dec mov r0, r4
 *   @0xf5df0 str r12, [sp, #0xc]
 *   @0xf5df4 bl 0xf4be4 <_ZN18CExtensionFunction15GetExternalNameEv>
 *   @0xf5df8 mov r1, r0
 *   @0xf5dfc mov r0, r4
 *   @0xf5e00 str r1, [sp, #0x10]
 *   @0xf5e04 bl 0xf4c38 <_ZN18CExtensionFunction11GetArgCountEv>
 *   @0xf5e08 ldr r1, [sp, #0x10]
 *   @0xf5e0c mov r2, #0
 *   @0xf5e10 stm sp, {r8, r10}
 *   @0xf5e14 mov r3, r0
 *   @0xf5e18 mov r0, r9
 *   @0xf5e1c bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii>
 *   @0xf5e20 ldr r12, [sp, #0xc]
 *   @0xf5e24 str r0, [r11, r12, lsl #2]
 *   @0xf5e28 b 0xf5d6c <_Z17Extension_Preparev+0x538>
 *   @0xf5e2c ldr r12, [sp, #0x40]
 *   @0xf5e30 mov r0, #1
 *   @0xf5e34 ldr r2, [sp, #0x894]
 *   @0xf5e38 ldr r3, [r12]
 *   @0xf5e3c cmp r2, r3
 *   @0xf5e40 bne 0xf5e64 <_Z17Extension_Preparev+0x630>
 *   @0xf5e44 add sp, sp, #2192
 *   @0xf5e48 add sp, sp, #12
 *   @0xf5e4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf5e50 ldr r3, [pc, #0x2c]
 *   @0xf5e54 mov r0, #4
 *   @0xf5e58 ldr r6, [r9, r3]
 *   @0xf5e5c str r8, [r6]
 *   @0xf5e60 b 0xf5a54 <_Z17Extension_Preparev+0x220>
 *   @0xf5e64 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xf5e68 mov r0, #4
 *   @0xf5e6c b 0xf5a54 <_Z17Extension_Preparev+0x220>
 *   @0xf5e70 eoreq r12, pc, r4, lsl #8
 *   @0xf5e74 .word 0xffffbd00
 *   @0xf5e78 .word 0xffffc1e4
 *   @0xf5e7c eorseq sp, r8, r12, lsr #27
 *   @0xf5e80 strhteq r2, [r4], -r12
 *   @0xf5e84 .word 0xffffc1e8
 *   @0xf5e88 eorseq sp, r8, r8, asr #25
 *   @0xf5e8c .word 0x00241fd8
 *   @0xf5e90 eoreq r1, r4, r8, lsl #30
 *   @0xf5e94 .word 0xffffc10c
 *   @0xf5e98 .word 0xffffc108
 *   @0xf5e9c .word 0xffffc1ec
 *   @0xf5ea0 .word 0xffffc1f0
 *   @0xf5ea4 eorseq sp, r8, r12, ror #21
 *   @0xf5ea8 .word 0x00241df4
 *   @0xf5eac eoreq lr, r3, r12, lsl #31
 *   @0xf5eb0 eoreq pc, r3, r12, asr #32
 *   @0xf5eb4 eoreq pc, r3, r0, asr #32
 *
 * ══ §6/19 b2Island::Solve  0x2e15e8  size 1664  416 条（0x2e15e8..0x2e1c68）
 * @func 0x2e15e8 0x2e1c68  size 1664  416 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Timer::Reset()×3 / b2Timer::GetMilliseconds() const×3 / b2Island::Solve(b2Profile*, b2TimeStep const&, b2Vec2 const&, bool)+0x3a0×2 / b2Island::Solve(b2Profile*, b2TimeStep const&, b2Vec2 const&, bool)+0x5d8×2 / b2Timer::b2Timer() / b2Island::Solve(b2Profile*, b2TimeStep const&, b2Vec2 const&, bool)+0x14c / b2ContactSolver::b2ContactSolver(b2ContactSolverDef*) / b2ContactSolver::InitializeVelocityConstraints()
 * 字段偏移 top8: 0x4×12 / 0xc×9 / 0x20×7 / 0x8×6 / 0x14×6 / 0x10×6 / 0x18×5 / 0x1c×4
 * VFP 指令 134 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e15e8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e15ec vpush {d8, d9, d10, d11, d12, d13}
 *   @0x2e15f0 sub sp, sp, #156
 *   @0x2e15f4 add r12, sp, #16
 *   @0x2e15f8 mov r4, r0
 *   @0x2e15fc str r12, [sp]
 *   @0x2e1600 mov r6, r2
 *   @0x2e1604 mov r0, r12
 *   @0x2e1608 ldrb r12, [sp, #0xf0]
 *   @0x2e160c mov r10, r3
 *   @0x2e1610 str r1, [sp, #0x4]
 *   @0x2e1614 str r12, [sp, #0x8]
 *   @0x2e1618 bl 0x2e10b8 <_ZN7b2TimerC2Ev>
 *   @0x2e161c ldr r3, [r4, #0x1c]
 *   @0x2e1620 vldr s16, [r6]
 *   @0x2e1624 cmp r3, #0
 *   @0x2e1628 ble 0x2e1734 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x14c>
 *   @0x2e162c ldr r5, [r4, #0x8]
 *   @0x2e1630 vmov.f32 s10, #1.000000e+00
 *   @0x2e1634 ldr lr, [r4, #0x14]
 *   @0x2e1638 ldr r12, [r4, #0x18]
 *   @0x2e163c add r3, r5, r3, lsl #2
 *   @0x2e1640 b 0x2e166c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x84>
 *   @0x2e1644 cmp r5, r3
 *   @0x2e1648 vstr s12, [lr]
 *   @0x2e164c str r11, [lr, #0x4]
 *   @0x2e1650 add r12, r12, #12
 *   @0x2e1654 str r8, [lr, #0x8]
 *   @0x2e1658 vstr s13, [r12, #-12]
 *   @0x2e165c vstr s14, [r12, #-8]
 *   @0x2e1660 vstr s15, [r12, #-4]
 *   @0x2e1664 add lr, lr, #12
 *   @0x2e1668 beq 0x2e1734 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x14c>
 *   @0x2e166c ldr r2, [r5], #4
 *   @0x2e1670 vldr s12, [r2, #60]
 *   @0x2e1674 vldr s13, [r2, #80]
 *   @0x2e1678 vldr s14, [r2, #84]
 *   @0x2e167c add r1, r2, #60
 *   @0x2e1680 add r7, r2, #52
 *   @0x2e1684 ldr r9, [r2]
 *   @0x2e1688 vldr s15, [r2, #88]
 *   @0x2e168c ldr r8, [r2, #0x48]
 *   @0x2e1690 ldm r1, {r0, r1}
 *   @0x2e1694 cmp r9, #2
 *   @0x2e1698 ldr r11, [r2, #0x40]
 *   @0x2e169c stm r7, {r0, r1}
 *   @0x2e16a0 str r8, [r2, #0x44]
 *   @0x2e16a4 bne 0x2e1644 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5c>
 *   @0x2e16a8 vldr s9, [r2, #136]
 *   @0x2e16ac vldr s8, [r2, #92]
 *   @0x2e16b0 vldr s1, [r2, #96]
 *   @0x2e16b4 vmul.f32 s8, s9, s8
 *   @0x2e16b8 vldr s6, [r2, #148]
 *   @0x2e16bc vldr s7, [r2, #156]
 *   @0x2e16c0 vldr s2, [r10]
 *   @0x2e16c4 vldr s3, [r10, #4]
 *   @0x2e16c8 vldr s4, [r2, #144]
 *   @0x2e16cc vldr s5, [r2, #100]
 *   @0x2e16d0 vmul.f32 s9, s9, s1
 *   @0x2e16d4 vmov.f32 s11, s10
 *   @0x2e16d8 vmls.f32 s11, s16, s6
 *   @0x2e16dc vmla.f32 s9, s7, s3
 *   @0x2e16e0 vmla.f32 s8, s7, s2
 *   @0x2e16e4 vmul.f32 s7, s16, s4
 *   @0x2e16e8 vcmpe.f32 s11, s10
 *   @0x2e16ec vmla.f32 s14, s16, s9
 *   @0x2e16f0 vmrs APSR_nzcv, fpscr
 *   @0x2e16f4 vmla.f32 s13, s16, s8
 *   @0x2e16f8 vmla.f32 s15, s7, s5
 *   @0x2e16fc vmovpl.f32 s9, #1.000000e+00
 *   @0x2e1700 bmi 0x2e1bfc <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x614>
 *   @0x2e1704 vldr s8, [r2, #152]
 *   @0x2e1708 vmov.f32 s11, s10
 *   @0x2e170c vmls.f32 s11, s16, s8
 *   @0x2e1710 vcmpe.f32 s11, s10
 *   @0x2e1714 vmov.f32 s8, s11
 *   @0x2e1718 vmrs APSR_nzcv, fpscr
 *   @0x2e171c vmul.f32 s13, s13, s9
 *   @0x2e1720 vmul.f32 s14, s14, s9
 *   @0x2e1724 vmovpl.f32 s8, #1.000000e+00
 *   @0x2e1728 bmi 0x2e1bec <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x604>
 *   @0x2e172c vmul.f32 s15, s15, s8
 *   @0x2e1730 b 0x2e1644 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5c>
 *   @0x2e1734 add r0, sp, #16
 *   @0x2e1738 add r5, sp, #24
 *   @0x2e173c bl 0x2e1090 <_ZN7b2Timer5ResetEv>
 *   @0x2e1740 mov r12, r6
 *   @0x2e1744 ldm r12!, {r0, r1, r2, r3}
 *   @0x2e1748 mov r8, r5
 *   @0x2e174c mov r10, r6
 *   @0x2e1750 add lr, sp, #56
 *   @0x2e1754 ldr r11, [r4, #0x14]
 *   @0x2e1758 add r7, sp, #100
 *   @0x2e175c stm r8!, {r0, r1, r2, r3}
 *   @0x2e1760 ldm r12, {r0, r1}
 *   @0x2e1764 str r11, [sp, #0x30]
 *   @0x2e1768 str r11, [sp, #0x58]
 *   @0x2e176c stm r8, {r0, r1}
 *   @0x2e1770 ldm r10!, {r0, r1, r2, r3}
 *   @0x2e1774 ldr r8, [r4, #0x18]
 *   @0x2e1778 ldr r10, [r4, #0xc]
 *   @0x2e177c stm lr!, {r0, r1, r2, r3}
 *   @0x2e1780 ldm r12, {r0, r1}
 *   @0x2e1784 ldr r3, [r4, #0x24]
 *   @0x2e1788 str r8, [sp, #0x34]
 *   @0x2e178c stm lr, {r0, r1}
 *   @0x2e1790 add r1, sp, #56
 *   @0x2e1794 str r3, [sp, #0x54]
 *   @0x2e1798 mov r0, r7
 *   @0x2e179c str r10, [sp, #0x50]
 *   @0x2e17a0 str r8, [sp, #0x5c]
 *   @0x2e17a4 ldr r3, [r4]
 *   @0x2e17a8 str r3, [sp, #0x60]
 *   @0x2e17ac bl 0x2e2090 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef>
 *   @0x2e17b0 mov r0, r7
 *   @0x2e17b4 bl 0x2e2398 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv>
 *   @0x2e17b8 ldrb r3, [r6, #0x14]
 *   @0x2e17bc cmp r3, #0
 *   @0x2e17c0 bne 0x2e1c2c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x644>
 *   @0x2e17c4 ldr r3, [r4, #0x20]
 *   @0x2e17c8 cmp r3, #0
 *   @0x2e17cc movgt r8, #0
 *   @0x2e17d0 ble 0x2e17fc <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x214>
 *   @0x2e17d4 ldr r3, [r4, #0x10]
 *   @0x2e17d8 mov r1, r5
 *   @0x2e17dc ldr r0, [r3, r8, lsl #2]
 *   @0x2e17e0 add r8, r8, #1
 *   @0x2e17e4 ldr r3, [r0]
 *   @0x2e17e8 ldr r3, [r3, #0x20]
 *   @0x2e17ec blx r3
 *   @0x2e17f0 ldr r3, [r4, #0x20]
 *   @0x2e17f4 cmp r3, r8
 *   @0x2e17f8 bgt 0x2e17d4 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x1ec>
 *   @0x2e17fc add r0, sp, #16
 *   @0x2e1800 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv>
 *   @0x2e1804 ldr r12, [sp, #0x4]
 *   @0x2e1808 str r0, [r12, #0xc]
 *   @0x2e180c add r0, sp, #16
 *   @0x2e1810 bl 0x2e1090 <_ZN7b2Timer5ResetEv>
 *   @0x2e1814 ldr r3, [r6, #0xc]
 *   @0x2e1818 cmp r3, #0
 *   @0x2e181c movgt r8, #0
 *   @0x2e1820 ble 0x2e1874 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x28c>
 *   @0x2e1824 ldr r3, [r4, #0x20]
 *   @0x2e1828 cmp r3, #0
 *   @0x2e182c ble 0x2e185c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x274>
 *   @0x2e1830 mov r9, #0
 *   @0x2e1834 ldr r3, [r4, #0x10]
 *   @0x2e1838 mov r1, r5
 *   @0x2e183c ldr r0, [r3, r9, lsl #2]
 *   @0x2e1840 add r9, r9, #1
 *   @0x2e1844 ldr r3, [r0]
 *   @0x2e1848 ldr r3, [r3, #0x24]
 *   @0x2e184c blx r3
 *   @0x2e1850 ldr r3, [r4, #0x20]
 *   @0x2e1854 cmp r3, r9
 *   @0x2e1858 bgt 0x2e1834 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x24c>
 *   @0x2e185c mov r0, r7
 *   @0x2e1860 add r8, r8, #1
 *   @0x2e1864 bl 0x2e28f4 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv>
 *   @0x2e1868 ldr r3, [r6, #0xc]
 *   @0x2e186c cmp r3, r8
 *   @0x2e1870 bgt 0x2e1824 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x23c>
 *   @0x2e1874 mov r0, r7
 *   @0x2e1878 bl 0x2e2ee8 <_ZN15b2ContactSolver13StoreImpulsesEv>
 *   @0x2e187c add r0, sp, #16
 *   @0x2e1880 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv>
 *   @0x2e1884 ldr r12, [r4, #0x1c]
 *   @0x2e1888 ldr r3, [sp, #0x4]
 *   @0x2e188c cmp r12, #0
 *   @0x2e1890 str r0, [r3, #0x10]
 *   @0x2e1894 ble 0x2e1988 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x3a0>
 *   @0x2e1898 mov r8, #0
 *   @0x2e189c vmov.f32 s24, #4.000000e+00
 *   @0x2e18a0 ldr r0, [r4, #0x14]
 *   @0x2e18a4 mov r10, r8
 *   @0x2e18a8 ldr r1, [r4, #0x18]
 *   @0x2e18ac vldr s23, [pc, #924]
 *   @0x2e18b0 vldr s25, [pc, #924]
 *   @0x2e18b4 vmov.f32 s26, #2.000000e+00
 *   @0x2e18b8 b 0x2e191c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x334>
 *   @0x2e18bc vmul.f32 s15, s16, s17
 *   @0x2e18c0 vmul.f32 s14, s15, s15
 *   @0x2e18c4 vcmpe.f32 s14, s23
 *   @0x2e18c8 vmrs APSR_nzcv, fpscr
 *   @0x2e18cc ble 0x2e18e8 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x300>
 *   @0x2e18d0 vcmpe.f32 s15, #0
 *   @0x2e18d4 vmrs APSR_nzcv, fpscr
 *   @0x2e18d8 vnegle.f32 s15, s15
 *   @0x2e18dc vdiv.f32 s15, s25, s15
 *   @0x2e18e0 vmul.f32 s17, s17, s15
 *   @0x2e18e4 vmul.f32 s15, s16, s17
 *   @0x2e18e8 add r10, r10, #1
 *   @0x2e18ec add r8, r8, #12
 *   @0x2e18f0 cmp r12, r10
 *   @0x2e18f4 vadd.f32 s12, s22, s12
 *   @0x2e18f8 vadd.f32 s13, s21, s13
 *   @0x2e18fc vstr s12, [r2]
 *   @0x2e1900 vadd.f32 s20, s20, s15
 *   @0x2e1904 vstr s13, [r2, #4]
 *   @0x2e1908 vstr s20, [r2, #8]
 *   @0x2e190c vstr s19, [r3]
 *   @0x2e1910 vstr s18, [r3, #4]
 *   @0x2e1914 vstr s17, [r3, #8]
 *   @0x2e1918 ble 0x2e1988 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x3a0>
 *   @0x2e191c add r3, r1, r8
 *   @0x2e1920 vldr s18, [r3, #4]
 *   @0x2e1924 vmul.f32 s13, s16, s18
 *   @0x2e1928 vldr s19, [r3]
 *   @0x2e192c add r2, r0, r8
 *   @0x2e1930 vldr s17, [r3, #8]
 *   @0x2e1934 vldr s22, [r2]
 *   @0x2e1938 vldr s21, [r2, #4]
 *   @0x2e193c vldr s20, [r2, #8]
 *   @0x2e1940 vmul.f32 s12, s16, s19
 *   @0x2e1944 vmul.f32 s14, s13, s13
 *   @0x2e1948 vmla.f32 s14, s12, s12
 *   @0x2e194c vcmpe.f32 s14, s24
 *   @0x2e1950 vmrs APSR_nzcv, fpscr
 *   @0x2e1954 ble 0x2e18bc <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x2d4>
 *   @0x2e1958 vsqrt.f32 s15, s14
 *   @0x2e195c vcmp.f32 s15, s15
 *   @0x2e1960 vmrs APSR_nzcv, fpscr
 *   @0x2e1964 bne 0x2e1c38 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x650>
 *   @0x2e1968 vdiv.f32 s15, s26, s15
 *   @0x2e196c add r2, r0, r8
 *   @0x2e1970 add r3, r1, r8
 *   @0x2e1974 vmul.f32 s19, s19, s15
 *   @0x2e1978 vmul.f32 s18, s18, s15
 *   @0x2e197c vmul.f32 s12, s16, s19
 *   @0x2e1980 vmul.f32 s13, s16, s18
 *   @0x2e1984 b 0x2e18bc <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x2d4>
 *   @0x2e1988 add r0, sp, #16
 *   @0x2e198c bl 0x2e1090 <_ZN7b2Timer5ResetEv>
 *   @0x2e1990 ldr r3, [r6, #0x10]
 *   @0x2e1994 cmp r3, #0
 *   @0x2e1998 movgt r8, #0
 *   @0x2e199c ble 0x2e1a04 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x41c>
 *   @0x2e19a0 mov r0, r7
 *   @0x2e19a4 bl 0x2e2f4c <_ZN15b2ContactSolver24SolvePositionConstraintsEv>
 *   @0x2e19a8 ldr r3, [r4, #0x20]
 *   @0x2e19ac cmp r3, #0
 *   @0x2e19b0 mov r11, r0
 *   @0x2e19b4 ble 0x2e1bd4 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5ec>
 *   @0x2e19b8 mov r9, #0
 *   @0x2e19bc mov r10, #1
 *   @0x2e19c0 ldr r3, [r4, #0x10]
 *   @0x2e19c4 mov r1, r5
 *   @0x2e19c8 ldr r0, [r3, r9, lsl #2]
 *   @0x2e19cc add r9, r9, #1
 *   @0x2e19d0 ldr r3, [r0]
 *   @0x2e19d4 ldr r3, [r3, #0x28]
 *   @0x2e19d8 blx r3
 *   @0x2e19dc ldr r3, [r4, #0x20]
 *   @0x2e19e0 cmp r3, r9
 *   @0x2e19e4 and r10, r10, r0
 *   @0x2e19e8 bgt 0x2e19c0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x3d8>
 *   @0x2e19ec tst r10, r11
 *   @0x2e19f0 bne 0x2e1be0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5f8>
 *   @0x2e19f4 ldr r3, [r6, #0x10]
 *   @0x2e19f8 add r8, r8, #1
 *   @0x2e19fc cmp r3, r8
 *   @0x2e1a00 bgt 0x2e19a0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x3b8>
 *   @0x2e1a04 mov r12, #0
 *   @0x2e1a08 str r12, [sp, #0xc]
 *   @0x2e1a0c ldr r10, [r4, #0x1c]
 *   @0x2e1a10 cmp r10, #0
 *   @0x2e1a14 ble 0x2e1ab4 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x4cc>
 *   @0x2e1a18 ldr r9, [r4, #0x8]
 *   @0x2e1a1c ldr r8, [r4, #0x14]
 *   @0x2e1a20 ldr r6, [r4, #0x18]
 *   @0x2e1a24 add r10, r9, r10, lsl #2
 *   @0x2e1a28 add r8, r8, #8
 *   @0x2e1a2c add r6, r6, #8
 *   @0x2e1a30 ldr r5, [r9], #4
 *   @0x2e1a34 ldmdb r8, {r0, r1}
 *   @0x2e1a38 add r2, r5, #60
 *   @0x2e1a3c ldr r11, [r8], #12
 *   @0x2e1a40 add r3, r5, #80
 *   @0x2e1a44 stm r2, {r0, r1}
 *   @0x2e1a48 ldmdb r6, {r0, r1}
 *   @0x2e1a4c ldr r2, [r6], #12
 *   @0x2e1a50 str r11, [r5, #0x48]
 *   @0x2e1a54 stm r3, {r0, r1}
 *   @0x2e1a58 mov r0, r11
 *   @0x2e1a5c str r2, [r5, #0x58]
 *   @0x2e1a60 bl 0xb6580 <sinf@plt>
 *   @0x2e1a64 vmov s17, r0
 *   @0x2e1a68 mov r0, r11
 *   @0x2e1a6c vstr s17, [r5, #20]
 *   @0x2e1a70 bl 0xb658c <cosf@plt>
 *   @0x2e1a74 vldr s15, [r5, #48]
 *   @0x2e1a78 vmul.f32 s14, s15, s17
 *   @0x2e1a7c vldr s12, [r5, #44]
 *   @0x2e1a80 vldr s10, [r5, #60]
 *   @0x2e1a84 vldr s11, [r5, #64]
 *   @0x2e1a88 cmp r9, r10
 *   @0x2e1a8c vmov s13, r0
 *   @0x2e1a90 str r0, [r5, #0x18]
 *   @0x2e1a94 vmul.f32 s15, s15, s13
 *   @0x2e1a98 vnmls.f32 s14, s12, s13
 *   @0x2e1a9c vmla.f32 s15, s12, s17
 *   @0x2e1aa0 vsub.f32 s14, s10, s14
 *   @0x2e1aa4 vsub.f32 s15, s11, s15
 *   @0x2e1aa8 vstr s14, [r5, #12]
 *   @0x2e1aac vstr s15, [r5, #16]
 *   @0x2e1ab0 bne 0x2e1a30 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x448>
 *   @0x2e1ab4 add r0, sp, #16
 *   @0x2e1ab8 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv>
 *   @0x2e1abc ldr r12, [sp, #0x4]
 *   @0x2e1ac0 ldr r1, [sp, #0x8c]
 *   @0x2e1ac4 str r0, [r12, #0x14]
 *   @0x2e1ac8 mov r0, r4
 *   @0x2e1acc bl 0x2e1224 <_ZN8b2Island6ReportEPK27b2ContactVelocityConstraint>
 *   @0x2e1ad0 ldr r12, [sp, #0x8]
 *   @0x2e1ad4 cmp r12, #0
 *   @0x2e1ad8 beq 0x2e1bc0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5d8>
 *   @0x2e1adc ldr r3, [r4, #0x1c]
 *   @0x2e1ae0 cmp r3, #0
 *   @0x2e1ae4 ble 0x2e1bc0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5d8>
 *   @0x2e1ae8 ldr r4, [r4, #0x8]
 *   @0x2e1aec lsl r5, r3, #2
 *   @0x2e1af0 mov lr, #0
 *   @0x2e1af4 vldr s15, [pc, #348]
 *   @0x2e1af8 add r0, r4, r5
 *   @0x2e1afc vldr s12, [pc, #344]
 *   @0x2e1b00 mov r2, r4
 *   @0x2e1b04 vldr s11, [pc, #340]
 *   @0x2e1b08 ldr r3, [r2], #4
 *   @0x2e1b0c ldr r1, [r3]
 *   @0x2e1b10 cmp r1, #0
 *   @0x2e1b14 beq 0x2e1b5c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x574>
 *   @0x2e1b18 ldrh r1, [r3, #4]
 *   @0x2e1b1c tst r1, #4
 *   @0x2e1b20 beq 0x2e1b54 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x56c>
 *   @0x2e1b24 vldr s14, [r3, #88]
 *   @0x2e1b28 vmul.f32 s14, s14, s14
 *   @0x2e1b2c vcmpe.f32 s14, s12
 *   @0x2e1b30 vmrs APSR_nzcv, fpscr
 *   @0x2e1b34 bgt 0x2e1b54 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x56c>
 *   @0x2e1b38 vldr s14, [r3, #84]
 *   @0x2e1b3c vmul.f32 s14, s14, s14
 *   @0x2e1b40 vldr s13, [r3, #80]
 *   @0x2e1b44 vmla.f32 s14, s13, s13
 *   @0x2e1b48 vcmpe.f32 s14, s11
 *   @0x2e1b4c vmrs APSR_nzcv, fpscr
 *   @0x2e1b50 ble 0x2e1c10 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x628>
 *   @0x2e1b54 str lr, [r3, #0xa0]
 *   @0x2e1b58 vldr s15, [pc, #260]
 *   @0x2e1b5c cmp r2, r0
 *   @0x2e1b60 bne 0x2e1b08 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x520>
 *   @0x2e1b64 vmov.f32 s14, #5.000000e-01
 *   @0x2e1b68 vcmpe.f32 s15, s14
 *   @0x2e1b6c vmrs APSR_nzcv, fpscr
 *   @0x2e1b70 blt 0x2e1bc0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5d8>
 *   @0x2e1b74 ldr r3, [sp, #0xc]
 *   @0x2e1b78 cmp r3, #0
 *   @0x2e1b7c beq 0x2e1bc0 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5d8>
 *   @0x2e1b80 add r12, r4, r5
 *   @0x2e1b84 mov r1, r4
 *   @0x2e1b88 mov r2, #0
 *   @0x2e1b8c ldr r3, [r1], #4
 *   @0x2e1b90 cmp r1, r12
 *   @0x2e1b94 ldrh r0, [r3, #4]
 *   @0x2e1b98 str r2, [r3, #0xa0]
 *   @0x2e1b9c bic r0, r0, #2
 *   @0x2e1ba0 str r2, [r3, #0x50]
 *   @0x2e1ba4 str r2, [r3, #0x54]
 *   @0x2e1ba8 str r2, [r3, #0x58]
 *   @0x2e1bac str r2, [r3, #0x5c]
 *   @0x2e1bb0 str r2, [r3, #0x60]
 *   @0x2e1bb4 str r2, [r3, #0x64]
 *   @0x2e1bb8 strh r0, [r3, #4]
 *   @0x2e1bbc bne 0x2e1b8c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x5a4>
 *   @0x2e1bc0 mov r0, r7
 *   @0x2e1bc4 bl 0x2e2370 <_ZN15b2ContactSolverD2Ev>
 *   @0x2e1bc8 add sp, sp, #156
 *   @0x2e1bcc vpop {d8, d9, d10, d11, d12, d13}
 *   @0x2e1bd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e1bd4 mov r10, #1
 *   @0x2e1bd8 tst r10, r11
 *   @0x2e1bdc beq 0x2e19f4 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x40c>
 *   @0x2e1be0 mov r3, #1
 *   @0x2e1be4 str r3, [sp, #0xc]
 *   @0x2e1be8 b 0x2e1a0c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x424>
 *   @0x2e1bec vcmpe.f32 s8, #0
 *   @0x2e1bf0 vmrs APSR_nzcv, fpscr
 *   @0x2e1bf4 vldrmi s8, [pc, #104]
 *   @0x2e1bf8 b 0x2e172c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x144>
 *   @0x2e1bfc vcmpe.f32 s11, #0
 *   @0x2e1c00 vmrs APSR_nzcv, fpscr
 *   @0x2e1c04 vmovpl.f32 s9, s11
 *   @0x2e1c08 vldrmi s9, [pc, #84]
 *   @0x2e1c0c b 0x2e1704 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x11c>
 *   @0x2e1c10 vldr s14, [r3, #160]
 *   @0x2e1c14 vadd.f32 s14, s16, s14
 *   @0x2e1c18 vcmpe.f32 s14, s15
 *   @0x2e1c1c vstr s14, [r3, #160]
 *   @0x2e1c20 vmrs APSR_nzcv, fpscr
 *   @0x2e1c24 vmovle.f32 s15, s14
 *   @0x2e1c28 b 0x2e1b5c <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x574>
 *   @0x2e1c2c mov r0, r7
 *   @0x2e1c30 bl 0x2e27d0 <_ZN15b2ContactSolver9WarmStartEv>
 *   @0x2e1c34 b 0x2e17c4 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x1dc>
 *   @0x2e1c38 vmov r0, s14
 *   @0x2e1c3c bl 0xb6700 <sqrtf@plt>
 *   @0x2e1c40 vmov s15, r0
 *   @0x2e1c44 add r0, r4, #20
 *   @0x2e1c48 ldm r0, {r0, r1, r12}
 *   @0x2e1c4c b 0x2e1968 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b+0x380>
 *   @0x2e1c50 andsmi lr, sp, r7, ror #19
 *   @0x2e1c54 svclo #0xc90fdb
 *   @0x2e1c58 svcvc #0x7fffff
 *   @0x2e1c5c blo 0xfeacf0a8 <b2_toiTime+0xfffffffffe375c04>
 *   @0x2e1c60 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x2e1c64 andeq r0, r0, r0
 *
 * ══ §7/19 b2ParticleSystem::UpdateContacts  0x2da664  size 1644  411 条（0x2da664..0x2dacd0）
 * @func 0x2da664 0x2dacd0  size 1644  411 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: void std::sort<b2ParticleSystem::Proxy*>(b2ParticleSystem::Proxy*, b2ParticleSystem::Proxy*)×2 / b2ParticleSystem::UpdateContacts(bool)+0x270×2 / b2BlockAllocator::Allocate(int)×2 / 0xb65bc×2 / b2BlockAllocator::Free(void*, int)×2 / b2ParticleSystem::UpdateContacts(bool)+0x2a8×2 / b2ParticleSystem::UpdateContacts(bool)+0x268 / b2ParticleSystem::UpdateContacts(bool)+0xf8
 * 字段偏移 top8: 0x4×16 / 0x8×12 / 0x74×10 / 0x7c×7 / 0x-8×5 / 0xc×5 / 0x38×4 / 0x-4×4
 * VFP 指令 76 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2da664 ldr r3, [r0, #0x68]
 *   @0x2da668 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2da66c vpush {d8, d9, d10}
 *   @0x2da670 sub sp, sp, #28
 *   @0x2da674 ldr r6, [r0, #0x70]
 *   @0x2da678 mov r4, r0
 *   @0x2da67c str r1, [sp, #0x14]
 *   @0x2da680 add r11, r6, r3, lsl #3
 *   @0x2da684 cmp r6, r11
 *   @0x2da688 bhs 0x2daacc <_ZN16b2ParticleSystem14UpdateContactsEb+0x468>
 *   @0x2da68c add r9, r6, #8
 *   @0x2da690 add r12, r6, #16
 *   @0x2da694 rsb r1, r9, #7
 *   @0x2da698 ldr r0, [r0, #0x38]
 *   @0x2da69c add r1, r11, r1
 *   @0x2da6a0 mov r3, r9
 *   @0x2da6a4 bic r1, r1, #7
 *   @0x2da6a8 vldr s15, [r4, #28]
 *   @0x2da6ac add r1, r12, r1
 *   @0x2da6b0 vldr s10, [pc, #656]
 *   @0x2da6b4 vldr s11, [pc, #656]
 *   @0x2da6b8 vldr s12, [pc, #656]
 *   @0x2da6bc ldr r2, [r3, #-0x8]
 *   @0x2da6c0 vmov.f32 s9, s11
 *   @0x2da6c4 add r3, r3, #8
 *   @0x2da6c8 add r2, r0, r2, lsl #3
 *   @0x2da6cc vldr s13, [r2]
 *   @0x2da6d0 vmul.f32 s13, s15, s13
 *   @0x2da6d4 vldr s14, [r2, #4]
 *   @0x2da6d8 vmla.f32 s9, s13, s10
 *   @0x2da6dc vmov.f32 s13, s9
 *   @0x2da6e0 vmov.f32 s9, s12
 *   @0x2da6e4 vmla.f32 s9, s15, s14
 *   @0x2da6e8 vcvt.u32.f32 s13, s13
 *   @0x2da6ec vcvt.u32.f32 s14, s9
 *   @0x2da6f0 vmov lr, s13
 *   @0x2da6f4 vmov r2, s14
 *   @0x2da6f8 add r2, lr, r2, lsl #20
 *   @0x2da6fc str r2, [r3, #-0xc]
 *   @0x2da700 cmp r3, r1
 *   @0x2da704 bne 0x2da6bc <_ZN16b2ParticleSystem14UpdateContactsEb+0x58>
 *   @0x2da708 vmov.f32 s21, #5.000000e-01
 *   @0x2da70c mov r0, r6
 *   @0x2da710 mov r1, r11
 *   @0x2da714 mov r10, r9
 *   @0x2da718 str r12, [sp, #0xc]
 *   @0x2da71c bl 0x2da584 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_>
 *   @0x2da720 mov r3, #0
 *   @0x2da724 str r3, [r4, #0x74]
 *   @0x2da728 vmov.f32 s20, #1.500000e+00
 *   @0x2da72c vmov.f32 s19, #1.000000e+00
 *   @0x2da730 ldr r3, [sp, #0xc]
 *   @0x2da734 cmp r11, r10
 *   @0x2da738 ldr r1, [r3, #-0xc]
 *   @0x2da73c add r9, r1, #256
 *   @0x2da740 bls 0x2da8d4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x270>
 *   @0x2da744 ldr r3, [r3, #-0x4]
 *   @0x2da748 cmp r9, r3
 *   @0x2da74c blo 0x2da8d4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x270>
 *   @0x2da750 ldr r5, [sp, #0xc]
 *   @0x2da754 str r6, [sp, #0x10]
 *   @0x2da758 b 0x2da7f8 <_ZN16b2ParticleSystem14UpdateContactsEb+0x194>
 *   @0x2da75c ldr r2, [r4, #0x7c]
 *   @0x2da760 vmov r0, s16
 *   @0x2da764 vldr s14, [r4, #28]
 *   @0x2da768 vmul.f32 s15, s16, s21
 *   @0x2da76c vmov.f32 s12, s20
 *   @0x2da770 vmov.f32 s13, s19
 *   @0x2da774 asr r3, r0, #1
 *   @0x2da778 add r0, r1, r1, lsl #1
 *   @0x2da77c rsb r3, r3, #1593835520
 *   @0x2da780 add r1, r1, #1
 *   @0x2da784 add r3, r3, #3620864
 *   @0x2da788 str r6, [r2, r0, lsl #3]
 *   @0x2da78c add r3, r3, #6592
 *   @0x2da790 add r2, r2, r0, lsl #3
 *   @0x2da794 add r3, r3, #31
 *   @0x2da798 ldr r0, [r4, #0x30]
 *   @0x2da79c str r7, [r2, #0x4]
 *   @0x2da7a0 vmov s9, r3
 *   @0x2da7a4 ldr r12, [r0, r7, lsl #2]
 *   @0x2da7a8 vmul.f32 s15, s15, s9
 *   @0x2da7ac ldr r0, [r0, r6, lsl #2]
 *   @0x2da7b0 orr r0, r12, r0
 *   @0x2da7b4 str r0, [r2, #0x8]
 *   @0x2da7b8 vmls.f32 s12, s9, s15
 *   @0x2da7bc vmul.f32 s15, s9, s12
 *   @0x2da7c0 vmul.f32 s16, s16, s15
 *   @0x2da7c4 vmls.f32 s13, s16, s14
 *   @0x2da7c8 vmul.f32 s18, s18, s15
 *   @0x2da7cc vstr s13, [r2, #12]
 *   @0x2da7d0 vmul.f32 s17, s17, s15
 *   @0x2da7d4 vstr s18, [r2, #16]
 *   @0x2da7d8 vstr s17, [r2, #20]
 *   @0x2da7dc str r1, [r4, #0x74]
 *   @0x2da7e0 cmp r11, r5
 *   @0x2da7e4 add r5, r5, #8
 *   @0x2da7e8 bls 0x2da8cc <_ZN16b2ParticleSystem14UpdateContactsEb+0x268>
 *   @0x2da7ec ldr r3, [r5, #-0x4]
 *   @0x2da7f0 cmp r3, r9
 *   @0x2da7f4 bhi 0x2da8cc <_ZN16b2ParticleSystem14UpdateContactsEb+0x268>
 *   @0x2da7f8 ldr r6, [r10, #-0x8]
 *   @0x2da7fc vldr s15, [r4, #32]
 *   @0x2da800 ldr r7, [r5, #-0x8]
 *   @0x2da804 ldr r2, [r4, #0x38]
 *   @0x2da808 add r3, r2, r6, lsl #3
 *   @0x2da80c add r2, r2, r7, lsl #3
 *   @0x2da810 vldr s14, [r3, #4]
 *   @0x2da814 vldr s17, [r2, #4]
 *   @0x2da818 vsub.f32 s17, s17, s14
 *   @0x2da81c vldr s18, [r2]
 *   @0x2da820 vldr s14, [r3]
 *   @0x2da824 vmul.f32 s16, s17, s17
 *   @0x2da828 vsub.f32 s18, s18, s14
 *   @0x2da82c vmla.f32 s16, s18, s18
 *   @0x2da830 vcmpe.f32 s16, s15
 *   @0x2da834 vmrs APSR_nzcv, fpscr
 *   @0x2da838 bpl 0x2da7e0 <_ZN16b2ParticleSystem14UpdateContactsEb+0x17c>
 *   @0x2da83c ldr r3, [r4, #0x74]
 *   @0x2da840 ldr r12, [r4, #0x78]
 *   @0x2da844 cmp r3, r12
 *   @0x2da848 mov r1, r3
 *   @0x2da84c blt 0x2da75c <_ZN16b2ParticleSystem14UpdateContactsEb+0xf8>
 *   @0x2da850 lsl r8, r3, #1
 *   @0x2da854 cmp r3, #0
 *   @0x2da858 add r3, r8, r3, lsl #2
 *   @0x2da85c mov r1, #6144
 *   @0x2da860 ldr r0, [r4, #0xd4]
 *   @0x2da864 moveq r8, #256
 *   @0x2da868 lslne r1, r3, #3
 *   @0x2da86c ldr r3, [r4, #0x7c]
 *   @0x2da870 str r12, [sp, #0x4]
 *   @0x2da874 str r3, [sp, #0x8]
 *   @0x2da878 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2da87c ldr r12, [sp, #0x4]
 *   @0x2da880 ldr r1, [sp, #0x8]
 *   @0x2da884 add r12, r12, r12, lsl #1
 *   @0x2da888 lsl r12, r12, #3
 *   @0x2da88c str r12, [sp, #0x4]
 *   @0x2da890 mov r2, r12
 *   @0x2da894 bl 0xb65bc <memcpy@plt>
 *   @0x2da898 ldr r12, [sp, #0x4]
 *   @0x2da89c ldr r1, [sp, #0x8]
 *   @0x2da8a0 mov r2, r12
 *   @0x2da8a4 mov r3, r0
 *   @0x2da8a8 ldr r0, [r4, #0xd4]
 *   @0x2da8ac str r3, [sp, #0x4]
 *   @0x2da8b0 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2da8b4 ldr r3, [sp, #0x4]
 *   @0x2da8b8 ldr r1, [r4, #0x74]
 *   @0x2da8bc str r8, [r4, #0x78]
 *   @0x2da8c0 mov r2, r3
 *   @0x2da8c4 str r3, [r4, #0x7c]
 *   @0x2da8c8 b 0x2da760 <_ZN16b2ParticleSystem14UpdateContactsEb+0xfc>
 *   @0x2da8cc ldr r6, [sp, #0x10]
 *   @0x2da8d0 ldr r1, [r10, #-0x4]
 *   @0x2da8d4 cmp r11, r6
 *   @0x2da8d8 add r2, r1, #1044480
 *   @0x2da8dc add r2, r2, #3840
 *   @0x2da8e0 bls 0x2da90c <_ZN16b2ParticleSystem14UpdateContactsEb+0x2a8>
 *   @0x2da8e4 ldr r3, [r6, #0x4]
 *   @0x2da8e8 cmp r2, r3
 *   @0x2da8ec bhi 0x2da900 <_ZN16b2ParticleSystem14UpdateContactsEb+0x29c>
 *   @0x2da8f0 b 0x2da928 <_ZN16b2ParticleSystem14UpdateContactsEb+0x2c4>
 *   @0x2da8f4 ldr r3, [r6, #0x4]
 *   @0x2da8f8 cmp r3, r2
 *   @0x2da8fc bhs 0x2da928 <_ZN16b2ParticleSystem14UpdateContactsEb+0x2c4>
 *   @0x2da900 add r6, r6, #8
 *   @0x2da904 cmp r11, r6
 *   @0x2da908 bhi 0x2da8f4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x290>
 *   @0x2da90c ldr r3, [sp, #0xc]
 *   @0x2da910 cmp r11, r10
 *   @0x2da914 add r3, r3, #8
 *   @0x2da918 str r3, [sp, #0xc]
 *   @0x2da91c bls 0x2daae0 <_ZN16b2ParticleSystem14UpdateContactsEb+0x47c>
 *   @0x2da920 add r10, r10, #8
 *   @0x2da924 b 0x2da730 <_ZN16b2ParticleSystem14UpdateContactsEb+0xcc>
 *   @0x2da928 add r1, r1, #1048576
 *   @0x2da92c add r1, r1, #256
 *   @0x2da930 str r1, [sp, #0x8]
 *   @0x2da934 cmp r1, r3
 *   @0x2da938 blo 0x2da90c <_ZN16b2ParticleSystem14UpdateContactsEb+0x2a8>
 *   @0x2da93c add r5, r6, #8
 *   @0x2da940 str r6, [sp, #0x10]
 *   @0x2da944 b 0x2da9f4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x390>
 *   @0x2da948 orrmi r0, r0, #0
 *   @0x2da94c .word 0x49000000
 *   @0x2da950 strmi r0, [r0, #-0x0]
 *   @0x2da954 ldr r2, [r4, #0x7c]
 *   @0x2da958 vmov r0, s16
 *   @0x2da95c vldr s14, [r4, #28]
 *   @0x2da960 vmul.f32 s15, s16, s21
 *   @0x2da964 vmov.f32 s12, s20
 *   @0x2da968 vmov.f32 s13, s19
 *   @0x2da96c asr r3, r0, #1
 *   @0x2da970 add r0, r1, r1, lsl #1
 *   @0x2da974 rsb r3, r3, #1593835520
 *   @0x2da978 add r1, r1, #1
 *   @0x2da97c add r3, r3, #3620864
 *   @0x2da980 str r6, [r2, r0, lsl #3]
 *   @0x2da984 add r3, r3, #6592
 *   @0x2da988 add r2, r2, r0, lsl #3
 *   @0x2da98c add r3, r3, #31
 *   @0x2da990 ldr r0, [r4, #0x30]
 *   @0x2da994 str r7, [r2, #0x4]
 *   @0x2da998 vmov s9, r3
 *   @0x2da99c ldr r12, [r0, r7, lsl #2]
 *   @0x2da9a0 vmul.f32 s15, s15, s9
 *   @0x2da9a4 ldr r0, [r0, r6, lsl #2]
 *   @0x2da9a8 orr r0, r12, r0
 *   @0x2da9ac str r0, [r2, #0x8]
 *   @0x2da9b0 vmls.f32 s12, s9, s15
 *   @0x2da9b4 vmul.f32 s15, s9, s12
 *   @0x2da9b8 vmul.f32 s16, s16, s15
 *   @0x2da9bc vmls.f32 s13, s16, s14
 *   @0x2da9c0 vmul.f32 s18, s18, s15
 *   @0x2da9c4 vstr s13, [r2, #12]
 *   @0x2da9c8 vmul.f32 s17, s17, s15
 *   @0x2da9cc vstr s18, [r2, #16]
 *   @0x2da9d0 vstr s17, [r2, #20]
 *   @0x2da9d4 str r1, [r4, #0x74]
 *   @0x2da9d8 cmp r11, r5
 *   @0x2da9dc add r5, r5, #8
 *   @0x2da9e0 bls 0x2daac4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x460>
 *   @0x2da9e4 ldr r3, [r5, #-0x4]
 *   @0x2da9e8 ldr r0, [sp, #0x8]
 *   @0x2da9ec cmp r3, r0
 *   @0x2da9f0 bhi 0x2daac4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x460>
 *   @0x2da9f4 ldr r6, [r10, #-0x8]
 *   @0x2da9f8 vldr s15, [r4, #32]
 *   @0x2da9fc ldr r7, [r5, #-0x8]
 *   @0x2daa00 ldr r2, [r4, #0x38]
 *   @0x2daa04 add r3, r2, r6, lsl #3
 *   @0x2daa08 add r2, r2, r7, lsl #3
 *   @0x2daa0c vldr s14, [r3, #4]
 *   @0x2daa10 vldr s17, [r2, #4]
 *   @0x2daa14 vsub.f32 s17, s17, s14
 *   @0x2daa18 vldr s18, [r2]
 *   @0x2daa1c vldr s14, [r3]
 *   @0x2daa20 vmul.f32 s16, s17, s17
 *   @0x2daa24 vsub.f32 s18, s18, s14
 *   @0x2daa28 vmla.f32 s16, s18, s18
 *   @0x2daa2c vcmpe.f32 s16, s15
 *   @0x2daa30 vmrs APSR_nzcv, fpscr
 *   @0x2daa34 bpl 0x2da9d8 <_ZN16b2ParticleSystem14UpdateContactsEb+0x374>
 *   @0x2daa38 ldr r3, [r4, #0x74]
 *   @0x2daa3c ldr r12, [r4, #0x78]
 *   @0x2daa40 cmp r3, r12
 *   @0x2daa44 mov r1, r3
 *   @0x2daa48 blt 0x2da954 <_ZN16b2ParticleSystem14UpdateContactsEb+0x2f0>
 *   @0x2daa4c lsl r8, r3, #1
 *   @0x2daa50 cmp r3, #0
 *   @0x2daa54 add r3, r8, r3, lsl #2
 *   @0x2daa58 mov r1, #6144
 *   @0x2daa5c ldr r0, [r4, #0xd4]
 *   @0x2daa60 moveq r8, #256
 *   @0x2daa64 lslne r1, r3, #3
 *   @0x2daa68 ldr r9, [r4, #0x7c]
 *   @0x2daa6c str r12, [sp, #0x4]
 *   @0x2daa70 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2daa74 ldr r12, [sp, #0x4]
 *   @0x2daa78 mov r1, r9
 *   @0x2daa7c add r12, r12, r12, lsl #1
 *   @0x2daa80 lsl r12, r12, #3
 *   @0x2daa84 str r12, [sp, #0x4]
 *   @0x2daa88 mov r2, r12
 *   @0x2daa8c bl 0xb65bc <memcpy@plt>
 *   @0x2daa90 ldr r12, [sp, #0x4]
 *   @0x2daa94 mov r1, r9
 *   @0x2daa98 mov r2, r12
 *   @0x2daa9c mov r3, r0
 *   @0x2daaa0 ldr r0, [r4, #0xd4]
 *   @0x2daaa4 str r3, [sp, #0x4]
 *   @0x2daaa8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2daaac ldr r3, [sp, #0x4]
 *   @0x2daab0 ldr r1, [r4, #0x74]
 *   @0x2daab4 str r8, [r4, #0x78]
 *   @0x2daab8 mov r2, r3
 *   @0x2daabc str r3, [r4, #0x7c]
 *   @0x2daac0 b 0x2da958 <_ZN16b2ParticleSystem14UpdateContactsEb+0x2f4>
 *   @0x2daac4 ldr r6, [sp, #0x10]
 *   @0x2daac8 b 0x2da90c <_ZN16b2ParticleSystem14UpdateContactsEb+0x2a8>
 *   @0x2daacc mov r0, r6
 *   @0x2daad0 mov r1, r11
 *   @0x2daad4 bl 0x2da584 <_ZSt4sortIPN16b2ParticleSystem5ProxyEEvT_S3_>
 *   @0x2daad8 mov r3, #0
 *   @0x2daadc str r3, [r4, #0x74]
 *   @0x2daae0 ldr r3, [sp, #0x14]
 *   @0x2daae4 cmp r3, #0
 *   @0x2daae8 bne 0x2daaf8 <_ZN16b2ParticleSystem14UpdateContactsEb+0x494>
 *   @0x2daaec add sp, sp, #28
 *   @0x2daaf0 vpop {d8, d9, d10}
 *   @0x2daaf4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2daaf8 ldr r9, [r4, #0x74]
 *   @0x2daafc ldr r8, [r4, #0x7c]
 *   @0x2dab00 add r9, r9, r9, lsl #1
 *   @0x2dab04 sbfx r3, r9, #0x0, #0x1d
 *   @0x2dab08 add r9, r8, r9, lsl #3
 *   @0x2dab0c add r11, r3, r3, lsl #2
 *   @0x2dab10 add r11, r11, r11, lsl #4
 *   @0x2dab14 add r11, r11, r11, lsl #8
 *   @0x2dab18 add r11, r11, r11, lsl #16
 *   @0x2dab1c add r11, r3, r11, lsl #1
 *   @0x2dab20 asr r2, r11, #2
 *   @0x2dab24 cmp r2, #0
 *   @0x2dab28 ble 0x2dacb4 <_ZN16b2ParticleSystem14UpdateContactsEb+0x650>
 *   @0x2dab2c ldr r3, [r8, #0x8]
 *   @0x2dab30 tst r3, #2
 *   @0x2dab34 bne 0x2dacc0 <_ZN16b2ParticleSystem14UpdateContactsEb+0x65c>
 *   @0x2dab38 ldr r3, [r8, #0x20]
 *   @0x2dab3c tst r3, #2
 *   @0x2dab40 addne r12, r8, #24
 *   @0x2dab44 bne 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0>
 *   @0x2dab48 ldr r3, [r8, #0x38]
 *   @0x2dab4c tst r3, #2
 *   @0x2dab50 addne r12, r8, #48
 *   @0x2dab54 bne 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0>
 *   @0x2dab58 ldr r3, [r8, #0x50]
 *   @0x2dab5c tst r3, #2
 *   @0x2dab60 bne 0x2dacc8 <_ZN16b2ParticleSystem14UpdateContactsEb+0x664>
 *   @0x2dab64 add r1, r8, #176
 *   @0x2dab68 mov r0, r8
 *   @0x2dab6c add r10, r8, #168
 *   @0x2dab70 b 0x2daba8 <_ZN16b2ParticleSystem14UpdateContactsEb+0x544>
 *   @0x2dab74 ldr r5, [r3, r5]
 *   @0x2dab78 tst r5, #2
 *   @0x2dab7c bne 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0>
 *   @0x2dab80 ldr r5, [r3, r7]
 *   @0x2dab84 tst r5, #2
 *   @0x2dab88 bne 0x2dac88 <_ZN16b2ParticleSystem14UpdateContactsEb+0x624>
 *   @0x2dab8c ldr r3, [r3, r6]
 *   @0x2dab90 tst r3, #2
 *   @0x2dab94 bne 0x2dac80 <_ZN16b2ParticleSystem14UpdateContactsEb+0x61c>
 *   @0x2dab98 ldr r3, [r1], #96
 *   @0x2dab9c tst r3, #2
 *   @0x2daba0 bne 0x2dac78 <_ZN16b2ParticleSystem14UpdateContactsEb+0x614>
 *   @0x2daba4 mov r0, r12
 *   @0x2daba8 subs r2, r2, #1
 *   @0x2dabac rsb r3, r10, r1
 *   @0x2dabb0 add r5, r8, #96
 *   @0x2dabb4 add r7, r8, #120
 *   @0x2dabb8 add r6, r8, #144
 *   @0x2dabbc add r12, r0, #96
 *   @0x2dabc0 bne 0x2dab74 <_ZN16b2ParticleSystem14UpdateContactsEb+0x510>
 *   @0x2dabc4 rsb r2, r12, r9
 *   @0x2dabc8 asr r2, r2, #3
 *   @0x2dabcc add r3, r2, r2, lsl #2
 *   @0x2dabd0 add r3, r3, r3, lsl #4
 *   @0x2dabd4 add r3, r3, r3, lsl #8
 *   @0x2dabd8 add r3, r3, r3, lsl #16
 *   @0x2dabdc add r3, r2, r3, lsl #1
 *   @0x2dabe0 cmp r3, #2
 *   @0x2dabe4 beq 0x2daca0 <_ZN16b2ParticleSystem14UpdateContactsEb+0x63c>
 *   @0x2dabe8 cmp r3, #3
 *   @0x2dabec beq 0x2dac90 <_ZN16b2ParticleSystem14UpdateContactsEb+0x62c>
 *   @0x2dabf0 cmp r3, #1
 *   @0x2dabf4 bne 0x2dac68 <_ZN16b2ParticleSystem14UpdateContactsEb+0x604>
 *   @0x2dabf8 ldr r3, [r12, #0x8]
 *   @0x2dabfc tst r3, #2
 *   @0x2dac00 beq 0x2dac68 <_ZN16b2ParticleSystem14UpdateContactsEb+0x604>
 *   @0x2dac04 cmp r9, r12
 *   @0x2dac08 beq 0x2dac68 <_ZN16b2ParticleSystem14UpdateContactsEb+0x604>
 *   @0x2dac0c add r5, r12, #24
 *   @0x2dac10 cmp r9, r5
 *   @0x2dac14 beq 0x2dac4c <_ZN16b2ParticleSystem14UpdateContactsEb+0x5e8>
 *   @0x2dac18 ldr r3, [r5, #0x8]
 *   @0x2dac1c mov r7, r5
 *   @0x2dac20 mov r6, r12
 *   @0x2dac24 add r5, r5, #24
 *   @0x2dac28 tst r3, #2
 *   @0x2dac2c bne 0x2dac10 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5ac>
 *   @0x2dac30 ldm r7!, {r0, r1, r2, r3}
 *   @0x2dac34 cmp r9, r5
 *   @0x2dac38 add r12, r12, #24
 *   @0x2dac3c stm r6!, {r0, r1, r2, r3}
 *   @0x2dac40 ldm r7, {r0, r1}
 *   @0x2dac44 stm r6, {r0, r1}
 *   @0x2dac48 bne 0x2dac18 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5b4>
 *   @0x2dac4c rsb r3, r8, r12
 *   @0x2dac50 asr r3, r3, #3
 *   @0x2dac54 add r11, r3, r3, lsl #2
 *   @0x2dac58 add r11, r11, r11, lsl #4
 *   @0x2dac5c add r11, r11, r11, lsl #8
 *   @0x2dac60 add r11, r11, r11, lsl #16
 *   @0x2dac64 add r11, r3, r11, lsl #1
 *   @0x2dac68 str r11, [r4, #0x74]
 *   @0x2dac6c add sp, sp, #28
 *   @0x2dac70 vpop {d8, d9, d10}
 *   @0x2dac74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2dac78 add r12, r0, #168
 *   @0x2dac7c b 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0>
 *   @0x2dac80 add r12, r0, #144
 *   @0x2dac84 b 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0>
 *   @0x2dac88 add r12, r0, #120
 *   @0x2dac8c b 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0>
 *   @0x2dac90 ldr r3, [r12, #0x8]
 *   @0x2dac94 tst r3, #2
 *   @0x2dac98 bne 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0>
 *   @0x2dac9c add r12, r12, #24
 *   @0x2daca0 ldr r3, [r12, #0x8]
 *   @0x2daca4 tst r3, #2
 *   @0x2daca8 bne 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0>
 *   @0x2dacac add r12, r12, #24
 *   @0x2dacb0 b 0x2dabf8 <_ZN16b2ParticleSystem14UpdateContactsEb+0x594>
 *   @0x2dacb4 mov r3, r11
 *   @0x2dacb8 mov r12, r8
 *   @0x2dacbc b 0x2dabe0 <_ZN16b2ParticleSystem14UpdateContactsEb+0x57c>
 *   @0x2dacc0 mov r12, r8
 *   @0x2dacc4 b 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0>
 *   @0x2dacc8 add r12, r8, #72
 *   @0x2daccc b 0x2dac04 <_ZN16b2ParticleSystem14UpdateContactsEb+0x5a0>
 *
 * ══ §8/19 CHashMap<char const*, int, 7>::Insert  0xd261c  size 1640  410 条（0xd261c..0xd2c84）
 * @func 0xd261c 0xd2c84  size 1640  410 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: unsigned int CHashMapCalculateHash<char const*>(char const*)×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / 0xb65b0×3 / MemoryManager::Free(void const*)×3 / CHashMap<char const*, int, 7>::Insert(char const*, int)+0x70 / CHashMap<char const*, int, 7>::Insert(char const*, int)+0x1d0 / CHashMap<char const*, int, 7>::Insert(char const*, int)+0x340 / CHashMap<char const*, int, 7>::Insert(char const*, int)+0x318
 * 字段偏移 top8: 0x4×33 / 0x8×30 / 0x10×18 / 0xc×7 / 0x1c×6 / 0x24×5 / 0x18×5 / 0x20×4
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd261c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd2620 vpush {d8}
 *   @0xd2624 sub sp, sp, #60
 *   @0xd2628 ldr r3, [r0, #0x4]
 *   @0xd262c mov r11, r0
 *   @0xd2630 str r2, [sp, #0x24]
 *   @0xd2634 ldr r2, [r0, #0xc]
 *   @0xd2638 str r1, [sp, #0x1c]
 *   @0xd263c cmp r3, r2
 *   @0xd2640 bgt 0xd2750 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x134>
 *   @0xd2644 add r3, r3, #1
 *   @0xd2648 ldr r0, [sp, #0x1c]
 *   @0xd264c str r3, [r11, #0x4]
 *   @0xd2650 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0xd2654 ldr r4, [r11, #0x8]
 *   @0xd2658 ldr r6, [r11, #0x10]
 *   @0xd265c bic r0, r0, #-2147483648
 *   @0xd2660 and r3, r0, r4
 *   @0xd2664 add r2, r3, r3, lsl #1
 *   @0xd2668 add r2, r6, r2, lsl #2
 *   @0xd266c ldr r12, [r2, #0x8]
 *   @0xd2670 cmp r12, #0
 *   @0xd2674 beq 0xd2730 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x114>
 *   @0xd2678 ldr r7, [r11]
 *   @0xd267c mov r1, #0
 *   @0xd2680 ldr r8, [sp, #0x1c]
 *   @0xd2684 ldr r9, [sp, #0x24]
 *   @0xd2688 b 0xd26d0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0xb4>
 *   @0xd268c ldr r10, [r2]
 *   @0xd2690 mov r1, r5
 *   @0xd2694 ldr r5, [r2, #0x4]
 *   @0xd2698 str r0, [r2, #0x8]
 *   @0xd269c mov r0, r12
 *   @0xd26a0 str r8, [r2]
 *   @0xd26a4 mov r8, r10
 *   @0xd26a8 str r9, [r2, #0x4]
 *   @0xd26ac mov r9, r5
 *   @0xd26b0 add r3, r3, #1
 *   @0xd26b4 add r1, r1, #1
 *   @0xd26b8 and r3, r3, r4
 *   @0xd26bc add r2, r3, r3, lsl #1
 *   @0xd26c0 add r2, r6, r2, lsl #2
 *   @0xd26c4 ldr r12, [r2, #0x8]
 *   @0xd26c8 cmp r12, #0
 *   @0xd26cc beq 0xd2728 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x10c>
 *   @0xd26d0 add r5, r7, r3
 *   @0xd26d4 and r10, r12, r4
 *   @0xd26d8 rsb r5, r10, r5
 *   @0xd26dc and r5, r5, r4
 *   @0xd26e0 cmp r5, r1
 *   @0xd26e4 blt 0xd268c <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x70>
 *   @0xd26e8 cmp r1, r5
 *   @0xd26ec bne 0xd26b0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x94>
 *   @0xd26f0 cmp r0, r12
 *   @0xd26f4 bne 0xd26b0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x94>
 *   @0xd26f8 ldr r12, [r2]
 *   @0xd26fc cmp r8, r12
 *   @0xd2700 bne 0xd26b0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x94>
 *   @0xd2704 ldr r3, [r11, #0x4]
 *   @0xd2708 str r8, [sp, #0x1c]
 *   @0xd270c str r8, [r2]
 *   @0xd2710 sub r3, r3, #1
 *   @0xd2714 str r9, [r2, #0x4]
 *   @0xd2718 str r0, [r2, #0x8]
 *   @0xd271c str r9, [sp, #0x24]
 *   @0xd2720 str r3, [r11, #0x4]
 *   @0xd2724 b 0xd2744 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x128>
 *   @0xd2728 str r8, [sp, #0x1c]
 *   @0xd272c str r9, [sp, #0x24]
 *   @0xd2730 ldr r12, [sp, #0x1c]
 *   @0xd2734 str r0, [r2, #0x8]
 *   @0xd2738 str r12, [r2]
 *   @0xd273c ldr r12, [sp, #0x24]
 *   @0xd2740 str r12, [r2, #0x4]
 *   @0xd2744 add sp, sp, #60
 *   @0xd2748 vpop {d8}
 *   @0xd274c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd2750 ldr r12, [r0]
 *   @0xd2754 mov r3, #1
 *   @0xd2758 ldr r1, [pc, #0x430]
 *   @0xd275c mov r2, #70
 *   @0xd2760 str r12, [sp, #0x20]
 *   @0xd2764 add r1, pc, r1
 *   @0xd2768 ldr r12, [r0, #0x10]
 *   @0xd276c str r12, [sp, #0x30]
 *   @0xd2770 ldr r12, [sp, #0x20]
 *   @0xd2774 lsl r0, r12, r3
 *   @0xd2778 str r0, [r11]
 *   @0xd277c add r4, r0, r12, lsl #2
 *   @0xd2780 sub r0, r0, #1
 *   @0xd2784 str r0, [r11, #0x8]
 *   @0xd2788 lsl r4, r4, #2
 *   @0xd278c mov r0, r4
 *   @0xd2790 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd2794 mov r2, r4
 *   @0xd2798 mov r1, #0
 *   @0xd279c str r0, [r11, #0x10]
 *   @0xd27a0 bl 0xb65b0 <memset@plt>
 *   @0xd27a4 ldr r2, [r11]
 *   @0xd27a8 vldr s15, [pc, #988]
 *   @0xd27ac mov r1, #0
 *   @0xd27b0 cmp r2, r1
 *   @0xd27b4 str r1, [r11, #0x4]
 *   @0xd27b8 vmov s13, r2
 *   @0xd27bc vcvt.f32.s32 s14, s13
 *   @0xd27c0 vmul.f32 s15, s14, s15
 *   @0xd27c4 vcvt.s32.f32 s15, s15
 *   @0xd27c8 vstr s15, [r11, #12]
 *   @0xd27cc ble 0xd27ec <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x1d0>
 *   @0xd27d0 add r2, r2, r2, lsl #1
 *   @0xd27d4 ldr r3, [r11, #0x10]
 *   @0xd27d8 add r2, r3, r2, lsl #2
 *   @0xd27dc str r1, [r3, #0x8]
 *   @0xd27e0 add r3, r3, #12
 *   @0xd27e4 cmp r3, r2
 *   @0xd27e8 bne 0xd27dc <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x1c0>
 *   @0xd27ec ldr r12, [sp, #0x20]
 *   @0xd27f0 cmp r12, #0
 *   @0xd27f4 ble 0xd295c <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x340>
 *   @0xd27f8 ldr r12, [pc, #0x394]
 *   @0xd27fc vldr s16, [pc, #904]
 *   @0xd2800 add r12, pc, r12
 *   @0xd2804 str r12, [sp, #0x34]
 *   @0xd2808 mov r12, #0
 *   @0xd280c str r12, [sp, #0xc]
 *   @0xd2810 ldr r12, [pc, #0x380]
 *   @0xd2814 add r12, pc, r12
 *   @0xd2818 str r12, [sp, #0x2c]
 *   @0xd281c ldr r12, [sp, #0x30]
 *   @0xd2820 str r12, [sp, #0x8]
 *   @0xd2824 ldr r12, [sp, #0x8]
 *   @0xd2828 ldr r3, [r12, #0x8]
 *   @0xd282c cmp r3, #0
 *   @0xd2830 ble 0xd2934 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x318>
 *   @0xd2834 ldr r12, [r12]
 *   @0xd2838 ldr r3, [r11, #0x4]
 *   @0xd283c ldr r2, [r11, #0xc]
 *   @0xd2840 str r12, [sp, #0x10]
 *   @0xd2844 ldr r12, [sp, #0x8]
 *   @0xd2848 cmp r3, r2
 *   @0xd284c ldr r12, [r12, #0x4]
 *   @0xd2850 str r12, [sp, #0x18]
 *   @0xd2854 bgt 0xd29a4 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x388>
 *   @0xd2858 add r3, r3, #1
 *   @0xd285c ldr r0, [sp, #0x10]
 *   @0xd2860 str r3, [r11, #0x4]
 *   @0xd2864 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0xd2868 ldr lr, [r11, #0x8]
 *   @0xd286c ldr r6, [r11, #0x10]
 *   @0xd2870 bic r0, r0, #-2147483648
 *   @0xd2874 and r3, r0, lr
 *   @0xd2878 add r2, r3, r3, lsl #1
 *   @0xd287c add r2, r6, r2, lsl #2
 *   @0xd2880 ldr r1, [r2, #0x8]
 *   @0xd2884 cmp r1, #0
 *   @0xd2888 beq 0xd298c <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x370>
 *   @0xd288c ldr r7, [r11]
 *   @0xd2890 mov r4, #0
 *   @0xd2894 ldr r8, [sp, #0x10]
 *   @0xd2898 ldr r9, [sp, #0x18]
 *   @0xd289c b 0xd28e0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x2c4>
 *   @0xd28a0 ldr r5, [r2]
 *   @0xd28a4 ldr r4, [r2, #0x4]
 *   @0xd28a8 str r0, [r2, #0x8]
 *   @0xd28ac mov r0, r1
 *   @0xd28b0 str r8, [r2]
 *   @0xd28b4 mov r8, r5
 *   @0xd28b8 str r9, [r2, #0x4]
 *   @0xd28bc mov r9, r4
 *   @0xd28c0 add r3, r3, #1
 *   @0xd28c4 add r4, r12, #1
 *   @0xd28c8 and r3, r3, lr
 *   @0xd28cc add r2, r3, r3, lsl #1
 *   @0xd28d0 add r2, r6, r2, lsl #2
 *   @0xd28d4 ldr r1, [r2, #0x8]
 *   @0xd28d8 cmp r1, #0
 *   @0xd28dc beq 0xd2984 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x368>
 *   @0xd28e0 add r12, r7, r3
 *   @0xd28e4 and r5, r1, lr
 *   @0xd28e8 rsb r12, r5, r12
 *   @0xd28ec and r12, r12, lr
 *   @0xd28f0 cmp r12, r4
 *   @0xd28f4 blt 0xd28a0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x284>
 *   @0xd28f8 movne r12, r4
 *   @0xd28fc bne 0xd28c0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x2a4>
 *   @0xd2900 cmp r1, r0
 *   @0xd2904 bne 0xd28c0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x2a4>
 *   @0xd2908 ldr r4, [r2]
 *   @0xd290c cmp r8, r4
 *   @0xd2910 bne 0xd28c0 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x2a4>
 *   @0xd2914 ldr r3, [r11, #0x4]
 *   @0xd2918 str r8, [sp, #0x10]
 *   @0xd291c str r8, [r2]
 *   @0xd2920 sub r3, r3, #1
 *   @0xd2924 str r9, [r2, #0x4]
 *   @0xd2928 str r1, [r2, #0x8]
 *   @0xd292c str r9, [sp, #0x18]
 *   @0xd2930 str r3, [r11, #0x4]
 *   @0xd2934 ldr r12, [sp, #0xc]
 *   @0xd2938 ldr r0, [sp, #0x20]
 *   @0xd293c add r12, r12, #1
 *   @0xd2940 str r12, [sp, #0xc]
 *   @0xd2944 ldr r12, [sp, #0x8]
 *   @0xd2948 add r12, r12, #12
 *   @0xd294c str r12, [sp, #0x8]
 *   @0xd2950 ldr r12, [sp, #0xc]
 *   @0xd2954 cmp r12, r0
 *   @0xd2958 bne 0xd2824 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x208>
 *   @0xd295c ldr r0, [sp, #0x30]
 *   @0xd2960 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd2964 vldr s13, [r11]
 *   @0xd2968 vcvt.f32.s32 s14, s13
 *   @0xd296c vldr s15, [pc, #536]
 *   @0xd2970 ldr r3, [r11, #0x4]
 *   @0xd2974 vmul.f32 s15, s14, s15
 *   @0xd2978 vcvt.s32.f32 s15, s15
 *   @0xd297c vstr s15, [r11, #12]
 *   @0xd2980 b 0xd2644 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x28>
 *   @0xd2984 str r8, [sp, #0x10]
 *   @0xd2988 str r9, [sp, #0x18]
 *   @0xd298c ldr r12, [sp, #0x10]
 *   @0xd2990 str r0, [r2, #0x8]
 *   @0xd2994 str r12, [r2]
 *   @0xd2998 ldr r12, [sp, #0x18]
 *   @0xd299c str r12, [r2, #0x4]
 *   @0xd29a0 b 0xd2934 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x318>
 *   @0xd29a4 ldr r12, [r11]
 *   @0xd29a8 mov r3, #1
 *   @0xd29ac ldr r1, [sp, #0x34]
 *   @0xd29b0 mov r2, #70
 *   @0xd29b4 str r12, [sp, #0x14]
 *   @0xd29b8 ldr r12, [r11, #0x10]
 *   @0xd29bc str r12, [sp, #0x28]
 *   @0xd29c0 ldr r12, [sp, #0x14]
 *   @0xd29c4 lsl r0, r12, r3
 *   @0xd29c8 str r0, [r11]
 *   @0xd29cc add r4, r0, r12, lsl #2
 *   @0xd29d0 sub r0, r0, #1
 *   @0xd29d4 str r0, [r11, #0x8]
 *   @0xd29d8 lsl r4, r4, #2
 *   @0xd29dc mov r0, r4
 *   @0xd29e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd29e4 mov r2, r4
 *   @0xd29e8 mov r1, #0
 *   @0xd29ec str r0, [r11, #0x10]
 *   @0xd29f0 bl 0xb65b0 <memset@plt>
 *   @0xd29f4 ldr r2, [r11]
 *   @0xd29f8 mov r0, #0
 *   @0xd29fc str r0, [r11, #0x4]
 *   @0xd2a00 cmp r2, r0
 *   @0xd2a04 vmov s13, r2
 *   @0xd2a08 vcvt.f32.s32 s15, s13
 *   @0xd2a0c vmul.f32 s15, s15, s16
 *   @0xd2a10 vcvt.s32.f32 s15, s15
 *   @0xd2a14 vstr s15, [r11, #12]
 *   @0xd2a18 ble 0xd2a3c <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x420>
 *   @0xd2a1c add r2, r2, r2, lsl #1
 *   @0xd2a20 ldr r3, [r11, #0x10]
 *   @0xd2a24 add r2, r3, r2, lsl #2
 *   @0xd2a28 mov r0, #0
 *   @0xd2a2c add r3, r3, #12
 *   @0xd2a30 str r0, [r3, #-0x4]
 *   @0xd2a34 cmp r3, r2
 *   @0xd2a38 bne 0xd2a28 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x40c>
 *   @0xd2a3c ldr r12, [sp, #0x14]
 *   @0xd2a40 cmp r12, #0
 *   @0xd2a44 ble 0xd2b5c <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x540>
 *   @0xd2a48 ldr r6, [sp, #0x28]
 *   @0xd2a4c mov r12, #0
 *   @0xd2a50 str r12, [sp, #0x4]
 *   @0xd2a54 ldr r3, [r6, #0x8]
 *   @0xd2a58 cmp r3, #0
 *   @0xd2a5c ble 0xd2b40 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x524>
 *   @0xd2a60 ldr r3, [r11, #0x4]
 *   @0xd2a64 ldr r2, [r11, #0xc]
 *   @0xd2a68 ldr r4, [r6]
 *   @0xd2a6c cmp r3, r2
 *   @0xd2a70 ldr r5, [r6, #0x4]
 *   @0xd2a74 bgt 0xd2b9c <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x580>
 *   @0xd2a78 add r3, r3, #1
 *   @0xd2a7c mov r0, r4
 *   @0xd2a80 str r3, [r11, #0x4]
 *   @0xd2a84 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0xd2a88 ldr lr, [r11, #0x8]
 *   @0xd2a8c ldr r9, [r11, #0x10]
 *   @0xd2a90 bic r0, r0, #-2147483648
 *   @0xd2a94 and r3, r0, lr
 *   @0xd2a98 add r2, r3, r3, lsl #1
 *   @0xd2a9c add r2, r9, r2, lsl #2
 *   @0xd2aa0 ldr r1, [r2, #0x8]
 *   @0xd2aa4 cmp r1, #0
 *   @0xd2aa8 ldrne r10, [r11]
 *   @0xd2aac movne r7, #0
 *   @0xd2ab0 bne 0xd2af8 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x4dc>
 *   @0xd2ab4 b 0xd2b80 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x564>
 *   @0xd2ab8 ldr r8, [r2]
 *   @0xd2abc ldr r7, [r2, #0x4]
 *   @0xd2ac0 str r0, [r2, #0x8]
 *   @0xd2ac4 mov r0, r1
 *   @0xd2ac8 str r4, [r2]
 *   @0xd2acc mov r4, r8
 *   @0xd2ad0 str r5, [r2, #0x4]
 *   @0xd2ad4 mov r5, r7
 *   @0xd2ad8 add r3, r3, #1
 *   @0xd2adc add r7, r12, #1
 *   @0xd2ae0 and r3, r3, lr
 *   @0xd2ae4 add r2, r3, r3, lsl #1
 *   @0xd2ae8 add r2, r9, r2, lsl #2
 *   @0xd2aec ldr r1, [r2, #0x8]
 *   @0xd2af0 cmp r1, #0
 *   @0xd2af4 beq 0xd2b80 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x564>
 *   @0xd2af8 add r12, r3, r10
 *   @0xd2afc and r8, r1, lr
 *   @0xd2b00 rsb r12, r8, r12
 *   @0xd2b04 and r12, r12, lr
 *   @0xd2b08 cmp r12, r7
 *   @0xd2b0c blt 0xd2ab8 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x49c>
 *   @0xd2b10 movne r12, r7
 *   @0xd2b14 bne 0xd2ad8 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x4bc>
 *   @0xd2b18 cmp r1, r0
 *   @0xd2b1c bne 0xd2ad8 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x4bc>
 *   @0xd2b20 ldr r7, [r2]
 *   @0xd2b24 cmp r4, r7
 *   @0xd2b28 bne 0xd2ad8 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x4bc>
 *   @0xd2b2c ldr r3, [r11, #0x4]
 *   @0xd2b30 stm r2, {r4, r5}
 *   @0xd2b34 sub r3, r3, #1
 *   @0xd2b38 str r1, [r2, #0x8]
 *   @0xd2b3c str r3, [r11, #0x4]
 *   @0xd2b40 ldr r12, [sp, #0x4]
 *   @0xd2b44 add r6, r6, #12
 *   @0xd2b48 ldr r0, [sp, #0x14]
 *   @0xd2b4c add r12, r12, #1
 *   @0xd2b50 str r12, [sp, #0x4]
 *   @0xd2b54 cmp r12, r0
 *   @0xd2b58 bne 0xd2a54 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x438>
 *   @0xd2b5c ldr r0, [sp, #0x28]
 *   @0xd2b60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd2b64 vldr s13, [r11]
 *   @0xd2b68 vcvt.f32.s32 s15, s13
 *   @0xd2b6c ldr r3, [r11, #0x4]
 *   @0xd2b70 vmul.f32 s15, s15, s16
 *   @0xd2b74 vcvt.s32.f32 s15, s15
 *   @0xd2b78 vstr s15, [r11, #12]
 *   @0xd2b7c b 0xd2858 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x23c>
 *   @0xd2b80 stm r2, {r4, r5}
 *   @0xd2b84 str r0, [r2, #0x8]
 *   @0xd2b88 b 0xd2b40 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x524>
 *   @0xd2b8c svclo #0x19999a
 *   @0xd2b90 eoreq lr, r5, r12, asr #17
 *   @0xd2b94 eoreq lr, r5, r0, lsr r8
 *   @0xd2b98 eoreq lr, r5, r12, lsl r8
 *   @0xd2b9c ldr r8, [r11]
 *   @0xd2ba0 mov r3, #1
 *   @0xd2ba4 ldr r1, [sp, #0x2c]
 *   @0xd2ba8 mov r2, #70
 *   @0xd2bac ldr r7, [r11, #0x10]
 *   @0xd2bb0 lsl r0, r8, r3
 *   @0xd2bb4 str r0, [r11]
 *   @0xd2bb8 add r9, r0, r8, lsl #2
 *   @0xd2bbc sub r0, r0, #1
 *   @0xd2bc0 str r0, [r11, #0x8]
 *   @0xd2bc4 lsl r9, r9, #2
 *   @0xd2bc8 mov r0, r9
 *   @0xd2bcc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd2bd0 mov r2, r9
 *   @0xd2bd4 mov r1, #0
 *   @0xd2bd8 str r0, [r11, #0x10]
 *   @0xd2bdc bl 0xb65b0 <memset@plt>
 *   @0xd2be0 ldr r2, [r11]
 *   @0xd2be4 mov r0, #0
 *   @0xd2be8 str r0, [r11, #0x4]
 *   @0xd2bec cmp r2, r0
 *   @0xd2bf0 vmov s13, r2
 *   @0xd2bf4 vcvt.f32.s32 s15, s13
 *   @0xd2bf8 vmul.f32 s15, s15, s16
 *   @0xd2bfc vcvt.s32.f32 s15, s15
 *   @0xd2c00 vstr s15, [r11, #12]
 *   @0xd2c04 ble 0xd2c28 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x60c>
 *   @0xd2c08 add r2, r2, r2, lsl #1
 *   @0xd2c0c ldr r3, [r11, #0x10]
 *   @0xd2c10 add r2, r3, r2, lsl #2
 *   @0xd2c14 mov r0, #0
 *   @0xd2c18 add r3, r3, #12
 *   @0xd2c1c str r0, [r3, #-0x4]
 *   @0xd2c20 cmp r3, r2
 *   @0xd2c24 bne 0xd2c14 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x5f8>
 *   @0xd2c28 cmp r8, #0
 *   @0xd2c2c movgt r9, r7
 *   @0xd2c30 movgt r10, #0
 *   @0xd2c34 ble 0xd2c60 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x644>
 *   @0xd2c38 ldr r3, [r9, #0x8]
 *   @0xd2c3c mov r0, r11
 *   @0xd2c40 add r10, r10, #1
 *   @0xd2c44 cmp r3, #0
 *   @0xd2c48 ble 0xd2c54 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x638>
 *   @0xd2c4c ldm r9, {r1, r2}
 *   @0xd2c50 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i>
 *   @0xd2c54 cmp r10, r8
 *   @0xd2c58 add r9, r9, #12
 *   @0xd2c5c bne 0xd2c38 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x61c>
 *   @0xd2c60 mov r0, r7
 *   @0xd2c64 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd2c68 vldr s13, [r11]
 *   @0xd2c6c vcvt.f32.s32 s15, s13
 *   @0xd2c70 ldr r3, [r11, #0x4]
 *   @0xd2c74 vmul.f32 s15, s15, s16
 *   @0xd2c78 vcvt.s32.f32 s15, s15
 *   @0xd2c7c vstr s15, [r11, #12]
 *   @0xd2c80 b 0xd2a78 <_ZN8CHashMapIPKciLi7EE6InsertES1_i+0x45c>
 *
 * ══ §9/19 CHashMap<YYObjectBase*, YYObjectBase*, 4>::Insert  0x195ba8  size 1640  410 条（0x195ba8..0x196210）
 * @func 0x195ba8 0x196210  size 1640  410 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: unsigned int CHashMapCalculateHash<YYObjectBase*>(YYObjectBase*)×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / 0xb65b0×3 / MemoryManager::Free(void const*)×3 / CHashMap<YYObjectBase*, YYObjectBase*, 4>::Insert(YYObjectBase*, YYObjectBase*)+0x70 / CHashMap<YYObjectBase*, YYObjectBase*, 4>::Insert(YYObjectBase*, YYObjectBase*)+0x1d0 / CHashMap<YYObjectBase*, YYObjectBase*, 4>::Insert(YYObjectBase*, YYObjectBase*)+0x340 / CHashMap<YYObjectBase*, YYObjectBase*, 4>::Insert(YYObjectBase*, YYObjectBase*)+0x318
 * 字段偏移 top8: 0x4×33 / 0x8×30 / 0x10×18 / 0xc×7 / 0x1c×6 / 0x24×5 / 0x18×5 / 0x20×4
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x195ba8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x195bac vpush {d8}
 *   @0x195bb0 sub sp, sp, #60
 *   @0x195bb4 ldr r3, [r0, #0x4]
 *   @0x195bb8 mov r11, r0
 *   @0x195bbc str r2, [sp, #0x24]
 *   @0x195bc0 ldr r2, [r0, #0xc]
 *   @0x195bc4 str r1, [sp, #0x1c]
 *   @0x195bc8 cmp r3, r2
 *   @0x195bcc bgt 0x195cdc <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x134>
 *   @0x195bd0 add r3, r3, #1
 *   @0x195bd4 ldr r0, [sp, #0x1c]
 *   @0x195bd8 str r3, [r11, #0x4]
 *   @0x195bdc bl 0x190f34 <_Z21CHashMapCalculateHashIP12YYObjectBaseEjT_>
 *   @0x195be0 ldr r4, [r11, #0x8]
 *   @0x195be4 ldr r6, [r11, #0x10]
 *   @0x195be8 bic r0, r0, #-2147483648
 *   @0x195bec and r3, r0, r4
 *   @0x195bf0 add r2, r3, r3, lsl #1
 *   @0x195bf4 add r2, r6, r2, lsl #2
 *   @0x195bf8 ldr r12, [r2, #0x8]
 *   @0x195bfc cmp r12, #0
 *   @0x195c00 beq 0x195cbc <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x114>
 *   @0x195c04 ldr r7, [r11]
 *   @0x195c08 mov r1, #0
 *   @0x195c0c ldr r8, [sp, #0x1c]
 *   @0x195c10 ldr r9, [sp, #0x24]
 *   @0x195c14 b 0x195c5c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0xb4>
 *   @0x195c18 ldr r10, [r2]
 *   @0x195c1c mov r1, r5
 *   @0x195c20 ldr r5, [r2, #0x4]
 *   @0x195c24 str r0, [r2, #0x8]
 *   @0x195c28 mov r0, r12
 *   @0x195c2c str r8, [r2]
 *   @0x195c30 mov r8, r10
 *   @0x195c34 str r9, [r2, #0x4]
 *   @0x195c38 mov r9, r5
 *   @0x195c3c add r3, r3, #1
 *   @0x195c40 add r1, r1, #1
 *   @0x195c44 and r3, r3, r4
 *   @0x195c48 add r2, r3, r3, lsl #1
 *   @0x195c4c add r2, r6, r2, lsl #2
 *   @0x195c50 ldr r12, [r2, #0x8]
 *   @0x195c54 cmp r12, #0
 *   @0x195c58 beq 0x195cb4 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x10c>
 *   @0x195c5c add r5, r7, r3
 *   @0x195c60 and r10, r12, r4
 *   @0x195c64 rsb r5, r10, r5
 *   @0x195c68 and r5, r5, r4
 *   @0x195c6c cmp r5, r1
 *   @0x195c70 blt 0x195c18 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x70>
 *   @0x195c74 cmp r1, r5
 *   @0x195c78 bne 0x195c3c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x94>
 *   @0x195c7c cmp r0, r12
 *   @0x195c80 bne 0x195c3c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x94>
 *   @0x195c84 ldr r12, [r2]
 *   @0x195c88 cmp r8, r12
 *   @0x195c8c bne 0x195c3c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x94>
 *   @0x195c90 ldr r3, [r11, #0x4]
 *   @0x195c94 str r8, [sp, #0x1c]
 *   @0x195c98 str r8, [r2]
 *   @0x195c9c sub r3, r3, #1
 *   @0x195ca0 str r9, [r2, #0x4]
 *   @0x195ca4 str r0, [r2, #0x8]
 *   @0x195ca8 str r9, [sp, #0x24]
 *   @0x195cac str r3, [r11, #0x4]
 *   @0x195cb0 b 0x195cd0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x128>
 *   @0x195cb4 str r8, [sp, #0x1c]
 *   @0x195cb8 str r9, [sp, #0x24]
 *   @0x195cbc ldr r12, [sp, #0x1c]
 *   @0x195cc0 str r0, [r2, #0x8]
 *   @0x195cc4 str r12, [r2]
 *   @0x195cc8 ldr r12, [sp, #0x24]
 *   @0x195ccc str r12, [r2, #0x4]
 *   @0x195cd0 add sp, sp, #60
 *   @0x195cd4 vpop {d8}
 *   @0x195cd8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x195cdc ldr r12, [r0]
 *   @0x195ce0 mov r3, #1
 *   @0x195ce4 ldr r1, [pc, #0x430]
 *   @0x195ce8 mov r2, #70
 *   @0x195cec str r12, [sp, #0x20]
 *   @0x195cf0 add r1, pc, r1
 *   @0x195cf4 ldr r12, [r0, #0x10]
 *   @0x195cf8 str r12, [sp, #0x30]
 *   @0x195cfc ldr r12, [sp, #0x20]
 *   @0x195d00 lsl r0, r12, r3
 *   @0x195d04 str r0, [r11]
 *   @0x195d08 add r4, r0, r12, lsl #2
 *   @0x195d0c sub r0, r0, #1
 *   @0x195d10 str r0, [r11, #0x8]
 *   @0x195d14 lsl r4, r4, #2
 *   @0x195d18 mov r0, r4
 *   @0x195d1c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x195d20 mov r2, r4
 *   @0x195d24 mov r1, #0
 *   @0x195d28 str r0, [r11, #0x10]
 *   @0x195d2c bl 0xb65b0 <memset@plt>
 *   @0x195d30 ldr r2, [r11]
 *   @0x195d34 vldr s15, [pc, #988]
 *   @0x195d38 mov r1, #0
 *   @0x195d3c cmp r2, r1
 *   @0x195d40 str r1, [r11, #0x4]
 *   @0x195d44 vmov s13, r2
 *   @0x195d48 vcvt.f32.s32 s14, s13
 *   @0x195d4c vmul.f32 s15, s14, s15
 *   @0x195d50 vcvt.s32.f32 s15, s15
 *   @0x195d54 vstr s15, [r11, #12]
 *   @0x195d58 ble 0x195d78 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x1d0>
 *   @0x195d5c add r2, r2, r2, lsl #1
 *   @0x195d60 ldr r3, [r11, #0x10]
 *   @0x195d64 add r2, r3, r2, lsl #2
 *   @0x195d68 str r1, [r3, #0x8]
 *   @0x195d6c add r3, r3, #12
 *   @0x195d70 cmp r3, r2
 *   @0x195d74 bne 0x195d68 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x1c0>
 *   @0x195d78 ldr r12, [sp, #0x20]
 *   @0x195d7c cmp r12, #0
 *   @0x195d80 ble 0x195ee8 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x340>
 *   @0x195d84 ldr r12, [pc, #0x394]
 *   @0x195d88 vldr s16, [pc, #904]
 *   @0x195d8c add r12, pc, r12
 *   @0x195d90 str r12, [sp, #0x34]
 *   @0x195d94 mov r12, #0
 *   @0x195d98 str r12, [sp, #0xc]
 *   @0x195d9c ldr r12, [pc, #0x380]
 *   @0x195da0 add r12, pc, r12
 *   @0x195da4 str r12, [sp, #0x2c]
 *   @0x195da8 ldr r12, [sp, #0x30]
 *   @0x195dac str r12, [sp, #0x8]
 *   @0x195db0 ldr r12, [sp, #0x8]
 *   @0x195db4 ldr r3, [r12, #0x8]
 *   @0x195db8 cmp r3, #0
 *   @0x195dbc ble 0x195ec0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x318>
 *   @0x195dc0 ldr r12, [r12]
 *   @0x195dc4 ldr r3, [r11, #0x4]
 *   @0x195dc8 ldr r2, [r11, #0xc]
 *   @0x195dcc str r12, [sp, #0x10]
 *   @0x195dd0 ldr r12, [sp, #0x8]
 *   @0x195dd4 cmp r3, r2
 *   @0x195dd8 ldr r12, [r12, #0x4]
 *   @0x195ddc str r12, [sp, #0x18]
 *   @0x195de0 bgt 0x195f30 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x388>
 *   @0x195de4 add r3, r3, #1
 *   @0x195de8 ldr r0, [sp, #0x10]
 *   @0x195dec str r3, [r11, #0x4]
 *   @0x195df0 bl 0x190f34 <_Z21CHashMapCalculateHashIP12YYObjectBaseEjT_>
 *   @0x195df4 ldr lr, [r11, #0x8]
 *   @0x195df8 ldr r6, [r11, #0x10]
 *   @0x195dfc bic r0, r0, #-2147483648
 *   @0x195e00 and r3, r0, lr
 *   @0x195e04 add r2, r3, r3, lsl #1
 *   @0x195e08 add r2, r6, r2, lsl #2
 *   @0x195e0c ldr r1, [r2, #0x8]
 *   @0x195e10 cmp r1, #0
 *   @0x195e14 beq 0x195f18 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x370>
 *   @0x195e18 ldr r7, [r11]
 *   @0x195e1c mov r4, #0
 *   @0x195e20 ldr r8, [sp, #0x10]
 *   @0x195e24 ldr r9, [sp, #0x18]
 *   @0x195e28 b 0x195e6c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x2c4>
 *   @0x195e2c ldr r5, [r2]
 *   @0x195e30 ldr r4, [r2, #0x4]
 *   @0x195e34 str r0, [r2, #0x8]
 *   @0x195e38 mov r0, r1
 *   @0x195e3c str r8, [r2]
 *   @0x195e40 mov r8, r5
 *   @0x195e44 str r9, [r2, #0x4]
 *   @0x195e48 mov r9, r4
 *   @0x195e4c add r3, r3, #1
 *   @0x195e50 add r4, r12, #1
 *   @0x195e54 and r3, r3, lr
 *   @0x195e58 add r2, r3, r3, lsl #1
 *   @0x195e5c add r2, r6, r2, lsl #2
 *   @0x195e60 ldr r1, [r2, #0x8]
 *   @0x195e64 cmp r1, #0
 *   @0x195e68 beq 0x195f10 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x368>
 *   @0x195e6c add r12, r7, r3
 *   @0x195e70 and r5, r1, lr
 *   @0x195e74 rsb r12, r5, r12
 *   @0x195e78 and r12, r12, lr
 *   @0x195e7c cmp r12, r4
 *   @0x195e80 blt 0x195e2c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x284>
 *   @0x195e84 movne r12, r4
 *   @0x195e88 bne 0x195e4c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x2a4>
 *   @0x195e8c cmp r1, r0
 *   @0x195e90 bne 0x195e4c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x2a4>
 *   @0x195e94 ldr r4, [r2]
 *   @0x195e98 cmp r8, r4
 *   @0x195e9c bne 0x195e4c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x2a4>
 *   @0x195ea0 ldr r3, [r11, #0x4]
 *   @0x195ea4 str r8, [sp, #0x10]
 *   @0x195ea8 str r8, [r2]
 *   @0x195eac sub r3, r3, #1
 *   @0x195eb0 str r9, [r2, #0x4]
 *   @0x195eb4 str r1, [r2, #0x8]
 *   @0x195eb8 str r9, [sp, #0x18]
 *   @0x195ebc str r3, [r11, #0x4]
 *   @0x195ec0 ldr r12, [sp, #0xc]
 *   @0x195ec4 ldr r0, [sp, #0x20]
 *   @0x195ec8 add r12, r12, #1
 *   @0x195ecc str r12, [sp, #0xc]
 *   @0x195ed0 ldr r12, [sp, #0x8]
 *   @0x195ed4 add r12, r12, #12
 *   @0x195ed8 str r12, [sp, #0x8]
 *   @0x195edc ldr r12, [sp, #0xc]
 *   @0x195ee0 cmp r12, r0
 *   @0x195ee4 bne 0x195db0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x208>
 *   @0x195ee8 ldr r0, [sp, #0x30]
 *   @0x195eec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x195ef0 vldr s13, [r11]
 *   @0x195ef4 vcvt.f32.s32 s14, s13
 *   @0x195ef8 vldr s15, [pc, #536]
 *   @0x195efc ldr r3, [r11, #0x4]
 *   @0x195f00 vmul.f32 s15, s14, s15
 *   @0x195f04 vcvt.s32.f32 s15, s15
 *   @0x195f08 vstr s15, [r11, #12]
 *   @0x195f0c b 0x195bd0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x28>
 *   @0x195f10 str r8, [sp, #0x10]
 *   @0x195f14 str r9, [sp, #0x18]
 *   @0x195f18 ldr r12, [sp, #0x10]
 *   @0x195f1c str r0, [r2, #0x8]
 *   @0x195f20 str r12, [r2]
 *   @0x195f24 ldr r12, [sp, #0x18]
 *   @0x195f28 str r12, [r2, #0x4]
 *   @0x195f2c b 0x195ec0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x318>
 *   @0x195f30 ldr r12, [r11]
 *   @0x195f34 mov r3, #1
 *   @0x195f38 ldr r1, [sp, #0x34]
 *   @0x195f3c mov r2, #70
 *   @0x195f40 str r12, [sp, #0x14]
 *   @0x195f44 ldr r12, [r11, #0x10]
 *   @0x195f48 str r12, [sp, #0x28]
 *   @0x195f4c ldr r12, [sp, #0x14]
 *   @0x195f50 lsl r0, r12, r3
 *   @0x195f54 str r0, [r11]
 *   @0x195f58 add r4, r0, r12, lsl #2
 *   @0x195f5c sub r0, r0, #1
 *   @0x195f60 str r0, [r11, #0x8]
 *   @0x195f64 lsl r4, r4, #2
 *   @0x195f68 mov r0, r4
 *   @0x195f6c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x195f70 mov r2, r4
 *   @0x195f74 mov r1, #0
 *   @0x195f78 str r0, [r11, #0x10]
 *   @0x195f7c bl 0xb65b0 <memset@plt>
 *   @0x195f80 ldr r2, [r11]
 *   @0x195f84 mov r0, #0
 *   @0x195f88 str r0, [r11, #0x4]
 *   @0x195f8c cmp r2, r0
 *   @0x195f90 vmov s13, r2
 *   @0x195f94 vcvt.f32.s32 s15, s13
 *   @0x195f98 vmul.f32 s15, s15, s16
 *   @0x195f9c vcvt.s32.f32 s15, s15
 *   @0x195fa0 vstr s15, [r11, #12]
 *   @0x195fa4 ble 0x195fc8 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x420>
 *   @0x195fa8 add r2, r2, r2, lsl #1
 *   @0x195fac ldr r3, [r11, #0x10]
 *   @0x195fb0 add r2, r3, r2, lsl #2
 *   @0x195fb4 mov r0, #0
 *   @0x195fb8 add r3, r3, #12
 *   @0x195fbc str r0, [r3, #-0x4]
 *   @0x195fc0 cmp r3, r2
 *   @0x195fc4 bne 0x195fb4 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x40c>
 *   @0x195fc8 ldr r12, [sp, #0x14]
 *   @0x195fcc cmp r12, #0
 *   @0x195fd0 ble 0x1960e8 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x540>
 *   @0x195fd4 ldr r6, [sp, #0x28]
 *   @0x195fd8 mov r12, #0
 *   @0x195fdc str r12, [sp, #0x4]
 *   @0x195fe0 ldr r3, [r6, #0x8]
 *   @0x195fe4 cmp r3, #0
 *   @0x195fe8 ble 0x1960cc <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x524>
 *   @0x195fec ldr r3, [r11, #0x4]
 *   @0x195ff0 ldr r2, [r11, #0xc]
 *   @0x195ff4 ldr r4, [r6]
 *   @0x195ff8 cmp r3, r2
 *   @0x195ffc ldr r5, [r6, #0x4]
 *   @0x196000 bgt 0x196128 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x580>
 *   @0x196004 add r3, r3, #1
 *   @0x196008 mov r0, r4
 *   @0x19600c str r3, [r11, #0x4]
 *   @0x196010 bl 0x190f34 <_Z21CHashMapCalculateHashIP12YYObjectBaseEjT_>
 *   @0x196014 ldr lr, [r11, #0x8]
 *   @0x196018 ldr r9, [r11, #0x10]
 *   @0x19601c bic r0, r0, #-2147483648
 *   @0x196020 and r3, r0, lr
 *   @0x196024 add r2, r3, r3, lsl #1
 *   @0x196028 add r2, r9, r2, lsl #2
 *   @0x19602c ldr r1, [r2, #0x8]
 *   @0x196030 cmp r1, #0
 *   @0x196034 ldrne r10, [r11]
 *   @0x196038 movne r7, #0
 *   @0x19603c bne 0x196084 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x4dc>
 *   @0x196040 b 0x19610c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x564>
 *   @0x196044 ldr r8, [r2]
 *   @0x196048 ldr r7, [r2, #0x4]
 *   @0x19604c str r0, [r2, #0x8]
 *   @0x196050 mov r0, r1
 *   @0x196054 str r4, [r2]
 *   @0x196058 mov r4, r8
 *   @0x19605c str r5, [r2, #0x4]
 *   @0x196060 mov r5, r7
 *   @0x196064 add r3, r3, #1
 *   @0x196068 add r7, r12, #1
 *   @0x19606c and r3, r3, lr
 *   @0x196070 add r2, r3, r3, lsl #1
 *   @0x196074 add r2, r9, r2, lsl #2
 *   @0x196078 ldr r1, [r2, #0x8]
 *   @0x19607c cmp r1, #0
 *   @0x196080 beq 0x19610c <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x564>
 *   @0x196084 add r12, r3, r10
 *   @0x196088 and r8, r1, lr
 *   @0x19608c rsb r12, r8, r12
 *   @0x196090 and r12, r12, lr
 *   @0x196094 cmp r12, r7
 *   @0x196098 blt 0x196044 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x49c>
 *   @0x19609c movne r12, r7
 *   @0x1960a0 bne 0x196064 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x4bc>
 *   @0x1960a4 cmp r1, r0
 *   @0x1960a8 bne 0x196064 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x4bc>
 *   @0x1960ac ldr r7, [r2]
 *   @0x1960b0 cmp r4, r7
 *   @0x1960b4 bne 0x196064 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x4bc>
 *   @0x1960b8 ldr r3, [r11, #0x4]
 *   @0x1960bc stm r2, {r4, r5}
 *   @0x1960c0 sub r3, r3, #1
 *   @0x1960c4 str r1, [r2, #0x8]
 *   @0x1960c8 str r3, [r11, #0x4]
 *   @0x1960cc ldr r12, [sp, #0x4]
 *   @0x1960d0 add r6, r6, #12
 *   @0x1960d4 ldr r0, [sp, #0x14]
 *   @0x1960d8 add r12, r12, #1
 *   @0x1960dc str r12, [sp, #0x4]
 *   @0x1960e0 cmp r12, r0
 *   @0x1960e4 bne 0x195fe0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x438>
 *   @0x1960e8 ldr r0, [sp, #0x28]
 *   @0x1960ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1960f0 vldr s13, [r11]
 *   @0x1960f4 vcvt.f32.s32 s15, s13
 *   @0x1960f8 ldr r3, [r11, #0x4]
 *   @0x1960fc vmul.f32 s15, s15, s16
 *   @0x196100 vcvt.s32.f32 s15, s15
 *   @0x196104 vstr s15, [r11, #12]
 *   @0x196108 b 0x195de4 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x23c>
 *   @0x19610c stm r2, {r4, r5}
 *   @0x196110 str r0, [r2, #0x8]
 *   @0x196114 b 0x1960cc <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x524>
 *   @0x196118 svclo #0x19999a
 *   @0x19611c andseq r11, r9, r0, asr #6
 *   @0x196120 andseq r11, r9, r4, lsr #5
 *   @0x196124 mulseq r9, r0, r2
 *   @0x196128 ldr r8, [r11]
 *   @0x19612c mov r3, #1
 *   @0x196130 ldr r1, [sp, #0x2c]
 *   @0x196134 mov r2, #70
 *   @0x196138 ldr r7, [r11, #0x10]
 *   @0x19613c lsl r0, r8, r3
 *   @0x196140 str r0, [r11]
 *   @0x196144 add r9, r0, r8, lsl #2
 *   @0x196148 sub r0, r0, #1
 *   @0x19614c str r0, [r11, #0x8]
 *   @0x196150 lsl r9, r9, #2
 *   @0x196154 mov r0, r9
 *   @0x196158 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x19615c mov r2, r9
 *   @0x196160 mov r1, #0
 *   @0x196164 str r0, [r11, #0x10]
 *   @0x196168 bl 0xb65b0 <memset@plt>
 *   @0x19616c ldr r2, [r11]
 *   @0x196170 mov r0, #0
 *   @0x196174 str r0, [r11, #0x4]
 *   @0x196178 cmp r2, r0
 *   @0x19617c vmov s13, r2
 *   @0x196180 vcvt.f32.s32 s15, s13
 *   @0x196184 vmul.f32 s15, s15, s16
 *   @0x196188 vcvt.s32.f32 s15, s15
 *   @0x19618c vstr s15, [r11, #12]
 *   @0x196190 ble 0x1961b4 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x60c>
 *   @0x196194 add r2, r2, r2, lsl #1
 *   @0x196198 ldr r3, [r11, #0x10]
 *   @0x19619c add r2, r3, r2, lsl #2
 *   @0x1961a0 mov r0, #0
 *   @0x1961a4 add r3, r3, #12
 *   @0x1961a8 str r0, [r3, #-0x4]
 *   @0x1961ac cmp r3, r2
 *   @0x1961b0 bne 0x1961a0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x5f8>
 *   @0x1961b4 cmp r8, #0
 *   @0x1961b8 movgt r9, r7
 *   @0x1961bc movgt r10, #0
 *   @0x1961c0 ble 0x1961ec <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x644>
 *   @0x1961c4 ldr r3, [r9, #0x8]
 *   @0x1961c8 mov r0, r11
 *   @0x1961cc add r10, r10, #1
 *   @0x1961d0 cmp r3, #0
 *   @0x1961d4 ble 0x1961e0 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x638>
 *   @0x1961d8 ldm r9, {r1, r2}
 *   @0x1961dc bl 0x195ba8 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_>
 *   @0x1961e0 cmp r10, r8
 *   @0x1961e4 add r9, r9, #12
 *   @0x1961e8 bne 0x1961c4 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x61c>
 *   @0x1961ec mov r0, r7
 *   @0x1961f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1961f4 vldr s13, [r11]
 *   @0x1961f8 vcvt.f32.s32 s15, s13
 *   @0x1961fc ldr r3, [r11, #0x4]
 *   @0x196200 vmul.f32 s15, s15, s16
 *   @0x196204 vcvt.s32.f32 s15, s15
 *   @0x196208 vstr s15, [r11, #12]
 *   @0x19620c b 0x196004 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_+0x45c>
 *
 * ══ §10/19 CHashMap<int, RValue*, 3>::Insert  0x196408  size 1640  410 条（0x196408..0x196a70）
 * @func 0x196408 0x196a70  size 1640  410 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CHashMapCalculateHash(int)×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / 0xb65b0×3 / MemoryManager::Free(void const*)×3 / CHashMap<int, RValue*, 3>::Insert(int, RValue*)+0x70 / CHashMap<int, RValue*, 3>::Insert(int, RValue*)+0x1d0 / CHashMap<int, RValue*, 3>::Insert(int, RValue*)+0x340 / CHashMap<int, RValue*, 3>::Insert(int, RValue*)+0x318
 * 字段偏移 top8: 0x4×33 / 0x8×30 / 0x10×18 / 0xc×7 / 0x1c×6 / 0x24×5 / 0x18×5 / 0x20×4
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x196408 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x19640c vpush {d8}
 *   @0x196410 sub sp, sp, #60
 *   @0x196414 ldr r3, [r0, #0x4]
 *   @0x196418 mov r11, r0
 *   @0x19641c str r2, [sp, #0x24]
 *   @0x196420 ldr r2, [r0, #0xc]
 *   @0x196424 str r1, [sp, #0x1c]
 *   @0x196428 cmp r3, r2
 *   @0x19642c bgt 0x19653c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x134>
 *   @0x196430 add r3, r3, #1
 *   @0x196434 ldr r0, [sp, #0x1c]
 *   @0x196438 str r3, [r11, #0x4]
 *   @0x19643c bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x196440 ldr r4, [r11, #0x8]
 *   @0x196444 ldr r6, [r11, #0x10]
 *   @0x196448 bic r0, r0, #-2147483648
 *   @0x19644c and r3, r0, r4
 *   @0x196450 add r2, r3, r3, lsl #1
 *   @0x196454 add r2, r6, r2, lsl #2
 *   @0x196458 ldr r12, [r2, #0x8]
 *   @0x19645c cmp r12, #0
 *   @0x196460 beq 0x19651c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x114>
 *   @0x196464 ldr r7, [r11]
 *   @0x196468 mov r1, #0
 *   @0x19646c ldr r8, [sp, #0x1c]
 *   @0x196470 ldr r9, [sp, #0x24]
 *   @0x196474 b 0x1964bc <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0xb4>
 *   @0x196478 ldr r10, [r2]
 *   @0x19647c mov r1, r5
 *   @0x196480 ldr r5, [r2, #0x4]
 *   @0x196484 str r0, [r2, #0x8]
 *   @0x196488 mov r0, r12
 *   @0x19648c str r8, [r2]
 *   @0x196490 mov r8, r10
 *   @0x196494 str r9, [r2, #0x4]
 *   @0x196498 mov r9, r5
 *   @0x19649c add r3, r3, #1
 *   @0x1964a0 add r1, r1, #1
 *   @0x1964a4 and r3, r3, r4
 *   @0x1964a8 add r2, r3, r3, lsl #1
 *   @0x1964ac add r2, r6, r2, lsl #2
 *   @0x1964b0 ldr r12, [r2, #0x8]
 *   @0x1964b4 cmp r12, #0
 *   @0x1964b8 beq 0x196514 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x10c>
 *   @0x1964bc add r5, r7, r3
 *   @0x1964c0 and r10, r12, r4
 *   @0x1964c4 rsb r5, r10, r5
 *   @0x1964c8 and r5, r5, r4
 *   @0x1964cc cmp r5, r1
 *   @0x1964d0 blt 0x196478 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x70>
 *   @0x1964d4 cmp r1, r5
 *   @0x1964d8 bne 0x19649c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x94>
 *   @0x1964dc cmp r0, r12
 *   @0x1964e0 bne 0x19649c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x94>
 *   @0x1964e4 ldr r12, [r2]
 *   @0x1964e8 cmp r8, r12
 *   @0x1964ec bne 0x19649c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x94>
 *   @0x1964f0 ldr r3, [r11, #0x4]
 *   @0x1964f4 str r8, [sp, #0x1c]
 *   @0x1964f8 str r8, [r2]
 *   @0x1964fc sub r3, r3, #1
 *   @0x196500 str r9, [r2, #0x4]
 *   @0x196504 str r0, [r2, #0x8]
 *   @0x196508 str r9, [sp, #0x24]
 *   @0x19650c str r3, [r11, #0x4]
 *   @0x196510 b 0x196530 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x128>
 *   @0x196514 str r8, [sp, #0x1c]
 *   @0x196518 str r9, [sp, #0x24]
 *   @0x19651c ldr r12, [sp, #0x1c]
 *   @0x196520 str r0, [r2, #0x8]
 *   @0x196524 str r12, [r2]
 *   @0x196528 ldr r12, [sp, #0x24]
 *   @0x19652c str r12, [r2, #0x4]
 *   @0x196530 add sp, sp, #60
 *   @0x196534 vpop {d8}
 *   @0x196538 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19653c ldr r12, [r0]
 *   @0x196540 mov r3, #1
 *   @0x196544 ldr r1, [pc, #0x430]
 *   @0x196548 mov r2, #70
 *   @0x19654c str r12, [sp, #0x20]
 *   @0x196550 add r1, pc, r1
 *   @0x196554 ldr r12, [r0, #0x10]
 *   @0x196558 str r12, [sp, #0x30]
 *   @0x19655c ldr r12, [sp, #0x20]
 *   @0x196560 lsl r0, r12, r3
 *   @0x196564 str r0, [r11]
 *   @0x196568 add r4, r0, r12, lsl #2
 *   @0x19656c sub r0, r0, #1
 *   @0x196570 str r0, [r11, #0x8]
 *   @0x196574 lsl r4, r4, #2
 *   @0x196578 mov r0, r4
 *   @0x19657c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x196580 mov r2, r4
 *   @0x196584 mov r1, #0
 *   @0x196588 str r0, [r11, #0x10]
 *   @0x19658c bl 0xb65b0 <memset@plt>
 *   @0x196590 ldr r2, [r11]
 *   @0x196594 vldr s15, [pc, #988]
 *   @0x196598 mov r1, #0
 *   @0x19659c cmp r2, r1
 *   @0x1965a0 str r1, [r11, #0x4]
 *   @0x1965a4 vmov s13, r2
 *   @0x1965a8 vcvt.f32.s32 s14, s13
 *   @0x1965ac vmul.f32 s15, s14, s15
 *   @0x1965b0 vcvt.s32.f32 s15, s15
 *   @0x1965b4 vstr s15, [r11, #12]
 *   @0x1965b8 ble 0x1965d8 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x1d0>
 *   @0x1965bc add r2, r2, r2, lsl #1
 *   @0x1965c0 ldr r3, [r11, #0x10]
 *   @0x1965c4 add r2, r3, r2, lsl #2
 *   @0x1965c8 str r1, [r3, #0x8]
 *   @0x1965cc add r3, r3, #12
 *   @0x1965d0 cmp r3, r2
 *   @0x1965d4 bne 0x1965c8 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x1c0>
 *   @0x1965d8 ldr r12, [sp, #0x20]
 *   @0x1965dc cmp r12, #0
 *   @0x1965e0 ble 0x196748 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x340>
 *   @0x1965e4 ldr r12, [pc, #0x394]
 *   @0x1965e8 vldr s16, [pc, #904]
 *   @0x1965ec add r12, pc, r12
 *   @0x1965f0 str r12, [sp, #0x34]
 *   @0x1965f4 mov r12, #0
 *   @0x1965f8 str r12, [sp, #0xc]
 *   @0x1965fc ldr r12, [pc, #0x380]
 *   @0x196600 add r12, pc, r12
 *   @0x196604 str r12, [sp, #0x2c]
 *   @0x196608 ldr r12, [sp, #0x30]
 *   @0x19660c str r12, [sp, #0x8]
 *   @0x196610 ldr r12, [sp, #0x8]
 *   @0x196614 ldr r3, [r12, #0x8]
 *   @0x196618 cmp r3, #0
 *   @0x19661c ble 0x196720 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x318>
 *   @0x196620 ldr r12, [r12]
 *   @0x196624 ldr r3, [r11, #0x4]
 *   @0x196628 ldr r2, [r11, #0xc]
 *   @0x19662c str r12, [sp, #0x10]
 *   @0x196630 ldr r12, [sp, #0x8]
 *   @0x196634 cmp r3, r2
 *   @0x196638 ldr r12, [r12, #0x4]
 *   @0x19663c str r12, [sp, #0x18]
 *   @0x196640 bgt 0x196790 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x388>
 *   @0x196644 add r3, r3, #1
 *   @0x196648 ldr r0, [sp, #0x10]
 *   @0x19664c str r3, [r11, #0x4]
 *   @0x196650 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x196654 ldr lr, [r11, #0x8]
 *   @0x196658 ldr r6, [r11, #0x10]
 *   @0x19665c bic r0, r0, #-2147483648
 *   @0x196660 and r3, r0, lr
 *   @0x196664 add r2, r3, r3, lsl #1
 *   @0x196668 add r2, r6, r2, lsl #2
 *   @0x19666c ldr r1, [r2, #0x8]
 *   @0x196670 cmp r1, #0
 *   @0x196674 beq 0x196778 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x370>
 *   @0x196678 ldr r7, [r11]
 *   @0x19667c mov r4, #0
 *   @0x196680 ldr r8, [sp, #0x10]
 *   @0x196684 ldr r9, [sp, #0x18]
 *   @0x196688 b 0x1966cc <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x2c4>
 *   @0x19668c ldr r5, [r2]
 *   @0x196690 ldr r4, [r2, #0x4]
 *   @0x196694 str r0, [r2, #0x8]
 *   @0x196698 mov r0, r1
 *   @0x19669c str r8, [r2]
 *   @0x1966a0 mov r8, r5
 *   @0x1966a4 str r9, [r2, #0x4]
 *   @0x1966a8 mov r9, r4
 *   @0x1966ac add r3, r3, #1
 *   @0x1966b0 add r4, r12, #1
 *   @0x1966b4 and r3, r3, lr
 *   @0x1966b8 add r2, r3, r3, lsl #1
 *   @0x1966bc add r2, r6, r2, lsl #2
 *   @0x1966c0 ldr r1, [r2, #0x8]
 *   @0x1966c4 cmp r1, #0
 *   @0x1966c8 beq 0x196770 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x368>
 *   @0x1966cc add r12, r7, r3
 *   @0x1966d0 and r5, r1, lr
 *   @0x1966d4 rsb r12, r5, r12
 *   @0x1966d8 and r12, r12, lr
 *   @0x1966dc cmp r12, r4
 *   @0x1966e0 blt 0x19668c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x284>
 *   @0x1966e4 movne r12, r4
 *   @0x1966e8 bne 0x1966ac <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x2a4>
 *   @0x1966ec cmp r1, r0
 *   @0x1966f0 bne 0x1966ac <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x2a4>
 *   @0x1966f4 ldr r4, [r2]
 *   @0x1966f8 cmp r8, r4
 *   @0x1966fc bne 0x1966ac <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x2a4>
 *   @0x196700 ldr r3, [r11, #0x4]
 *   @0x196704 str r8, [sp, #0x10]
 *   @0x196708 str r8, [r2]
 *   @0x19670c sub r3, r3, #1
 *   @0x196710 str r9, [r2, #0x4]
 *   @0x196714 str r1, [r2, #0x8]
 *   @0x196718 str r9, [sp, #0x18]
 *   @0x19671c str r3, [r11, #0x4]
 *   @0x196720 ldr r12, [sp, #0xc]
 *   @0x196724 ldr r0, [sp, #0x20]
 *   @0x196728 add r12, r12, #1
 *   @0x19672c str r12, [sp, #0xc]
 *   @0x196730 ldr r12, [sp, #0x8]
 *   @0x196734 add r12, r12, #12
 *   @0x196738 str r12, [sp, #0x8]
 *   @0x19673c ldr r12, [sp, #0xc]
 *   @0x196740 cmp r12, r0
 *   @0x196744 bne 0x196610 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x208>
 *   @0x196748 ldr r0, [sp, #0x30]
 *   @0x19674c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x196750 vldr s13, [r11]
 *   @0x196754 vcvt.f32.s32 s14, s13
 *   @0x196758 vldr s15, [pc, #536]
 *   @0x19675c ldr r3, [r11, #0x4]
 *   @0x196760 vmul.f32 s15, s14, s15
 *   @0x196764 vcvt.s32.f32 s15, s15
 *   @0x196768 vstr s15, [r11, #12]
 *   @0x19676c b 0x196430 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x28>
 *   @0x196770 str r8, [sp, #0x10]
 *   @0x196774 str r9, [sp, #0x18]
 *   @0x196778 ldr r12, [sp, #0x10]
 *   @0x19677c str r0, [r2, #0x8]
 *   @0x196780 str r12, [r2]
 *   @0x196784 ldr r12, [sp, #0x18]
 *   @0x196788 str r12, [r2, #0x4]
 *   @0x19678c b 0x196720 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x318>
 *   @0x196790 ldr r12, [r11]
 *   @0x196794 mov r3, #1
 *   @0x196798 ldr r1, [sp, #0x34]
 *   @0x19679c mov r2, #70
 *   @0x1967a0 str r12, [sp, #0x14]
 *   @0x1967a4 ldr r12, [r11, #0x10]
 *   @0x1967a8 str r12, [sp, #0x28]
 *   @0x1967ac ldr r12, [sp, #0x14]
 *   @0x1967b0 lsl r0, r12, r3
 *   @0x1967b4 str r0, [r11]
 *   @0x1967b8 add r4, r0, r12, lsl #2
 *   @0x1967bc sub r0, r0, #1
 *   @0x1967c0 str r0, [r11, #0x8]
 *   @0x1967c4 lsl r4, r4, #2
 *   @0x1967c8 mov r0, r4
 *   @0x1967cc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1967d0 mov r2, r4
 *   @0x1967d4 mov r1, #0
 *   @0x1967d8 str r0, [r11, #0x10]
 *   @0x1967dc bl 0xb65b0 <memset@plt>
 *   @0x1967e0 ldr r2, [r11]
 *   @0x1967e4 mov r0, #0
 *   @0x1967e8 str r0, [r11, #0x4]
 *   @0x1967ec cmp r2, r0
 *   @0x1967f0 vmov s13, r2
 *   @0x1967f4 vcvt.f32.s32 s15, s13
 *   @0x1967f8 vmul.f32 s15, s15, s16
 *   @0x1967fc vcvt.s32.f32 s15, s15
 *   @0x196800 vstr s15, [r11, #12]
 *   @0x196804 ble 0x196828 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x420>
 *   @0x196808 add r2, r2, r2, lsl #1
 *   @0x19680c ldr r3, [r11, #0x10]
 *   @0x196810 add r2, r3, r2, lsl #2
 *   @0x196814 mov r0, #0
 *   @0x196818 add r3, r3, #12
 *   @0x19681c str r0, [r3, #-0x4]
 *   @0x196820 cmp r3, r2
 *   @0x196824 bne 0x196814 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x40c>
 *   @0x196828 ldr r12, [sp, #0x14]
 *   @0x19682c cmp r12, #0
 *   @0x196830 ble 0x196948 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x540>
 *   @0x196834 ldr r6, [sp, #0x28]
 *   @0x196838 mov r12, #0
 *   @0x19683c str r12, [sp, #0x4]
 *   @0x196840 ldr r3, [r6, #0x8]
 *   @0x196844 cmp r3, #0
 *   @0x196848 ble 0x19692c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x524>
 *   @0x19684c ldr r3, [r11, #0x4]
 *   @0x196850 ldr r2, [r11, #0xc]
 *   @0x196854 ldr r4, [r6]
 *   @0x196858 cmp r3, r2
 *   @0x19685c ldr r5, [r6, #0x4]
 *   @0x196860 bgt 0x196988 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x580>
 *   @0x196864 add r3, r3, #1
 *   @0x196868 mov r0, r4
 *   @0x19686c str r3, [r11, #0x4]
 *   @0x196870 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x196874 ldr lr, [r11, #0x8]
 *   @0x196878 ldr r9, [r11, #0x10]
 *   @0x19687c bic r0, r0, #-2147483648
 *   @0x196880 and r3, r0, lr
 *   @0x196884 add r2, r3, r3, lsl #1
 *   @0x196888 add r2, r9, r2, lsl #2
 *   @0x19688c ldr r1, [r2, #0x8]
 *   @0x196890 cmp r1, #0
 *   @0x196894 ldrne r10, [r11]
 *   @0x196898 movne r7, #0
 *   @0x19689c bne 0x1968e4 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x4dc>
 *   @0x1968a0 b 0x19696c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x564>
 *   @0x1968a4 ldr r8, [r2]
 *   @0x1968a8 ldr r7, [r2, #0x4]
 *   @0x1968ac str r0, [r2, #0x8]
 *   @0x1968b0 mov r0, r1
 *   @0x1968b4 str r4, [r2]
 *   @0x1968b8 mov r4, r8
 *   @0x1968bc str r5, [r2, #0x4]
 *   @0x1968c0 mov r5, r7
 *   @0x1968c4 add r3, r3, #1
 *   @0x1968c8 add r7, r12, #1
 *   @0x1968cc and r3, r3, lr
 *   @0x1968d0 add r2, r3, r3, lsl #1
 *   @0x1968d4 add r2, r9, r2, lsl #2
 *   @0x1968d8 ldr r1, [r2, #0x8]
 *   @0x1968dc cmp r1, #0
 *   @0x1968e0 beq 0x19696c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x564>
 *   @0x1968e4 add r12, r3, r10
 *   @0x1968e8 and r8, r1, lr
 *   @0x1968ec rsb r12, r8, r12
 *   @0x1968f0 and r12, r12, lr
 *   @0x1968f4 cmp r12, r7
 *   @0x1968f8 blt 0x1968a4 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x49c>
 *   @0x1968fc movne r12, r7
 *   @0x196900 bne 0x1968c4 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x4bc>
 *   @0x196904 cmp r1, r0
 *   @0x196908 bne 0x1968c4 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x4bc>
 *   @0x19690c ldr r7, [r2]
 *   @0x196910 cmp r4, r7
 *   @0x196914 bne 0x1968c4 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x4bc>
 *   @0x196918 ldr r3, [r11, #0x4]
 *   @0x19691c stm r2, {r4, r5}
 *   @0x196920 sub r3, r3, #1
 *   @0x196924 str r1, [r2, #0x8]
 *   @0x196928 str r3, [r11, #0x4]
 *   @0x19692c ldr r12, [sp, #0x4]
 *   @0x196930 add r6, r6, #12
 *   @0x196934 ldr r0, [sp, #0x14]
 *   @0x196938 add r12, r12, #1
 *   @0x19693c str r12, [sp, #0x4]
 *   @0x196940 cmp r12, r0
 *   @0x196944 bne 0x196840 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x438>
 *   @0x196948 ldr r0, [sp, #0x28]
 *   @0x19694c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x196950 vldr s13, [r11]
 *   @0x196954 vcvt.f32.s32 s15, s13
 *   @0x196958 ldr r3, [r11, #0x4]
 *   @0x19695c vmul.f32 s15, s15, s16
 *   @0x196960 vcvt.s32.f32 s15, s15
 *   @0x196964 vstr s15, [r11, #12]
 *   @0x196968 b 0x196644 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x23c>
 *   @0x19696c stm r2, {r4, r5}
 *   @0x196970 str r0, [r2, #0x8]
 *   @0x196974 b 0x19692c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x524>
 *   @0x196978 svclo #0x19999a
 *   @0x19697c andseq r10, r9, r0, ror #21
 *   @0x196980 andseq r10, r9, r4, asr #20
 *   @0x196984 andseq r10, r9, r0, lsr r10
 *   @0x196988 ldr r8, [r11]
 *   @0x19698c mov r3, #1
 *   @0x196990 ldr r1, [sp, #0x2c]
 *   @0x196994 mov r2, #70
 *   @0x196998 ldr r7, [r11, #0x10]
 *   @0x19699c lsl r0, r8, r3
 *   @0x1969a0 str r0, [r11]
 *   @0x1969a4 add r9, r0, r8, lsl #2
 *   @0x1969a8 sub r0, r0, #1
 *   @0x1969ac str r0, [r11, #0x8]
 *   @0x1969b0 lsl r9, r9, #2
 *   @0x1969b4 mov r0, r9
 *   @0x1969b8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1969bc mov r2, r9
 *   @0x1969c0 mov r1, #0
 *   @0x1969c4 str r0, [r11, #0x10]
 *   @0x1969c8 bl 0xb65b0 <memset@plt>
 *   @0x1969cc ldr r2, [r11]
 *   @0x1969d0 mov r0, #0
 *   @0x1969d4 str r0, [r11, #0x4]
 *   @0x1969d8 cmp r2, r0
 *   @0x1969dc vmov s13, r2
 *   @0x1969e0 vcvt.f32.s32 s15, s13
 *   @0x1969e4 vmul.f32 s15, s15, s16
 *   @0x1969e8 vcvt.s32.f32 s15, s15
 *   @0x1969ec vstr s15, [r11, #12]
 *   @0x1969f0 ble 0x196a14 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x60c>
 *   @0x1969f4 add r2, r2, r2, lsl #1
 *   @0x1969f8 ldr r3, [r11, #0x10]
 *   @0x1969fc add r2, r3, r2, lsl #2
 *   @0x196a00 mov r0, #0
 *   @0x196a04 add r3, r3, #12
 *   @0x196a08 str r0, [r3, #-0x4]
 *   @0x196a0c cmp r3, r2
 *   @0x196a10 bne 0x196a00 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x5f8>
 *   @0x196a14 cmp r8, #0
 *   @0x196a18 movgt r9, r7
 *   @0x196a1c movgt r10, #0
 *   @0x196a20 ble 0x196a4c <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x644>
 *   @0x196a24 ldr r3, [r9, #0x8]
 *   @0x196a28 mov r0, r11
 *   @0x196a2c add r10, r10, #1
 *   @0x196a30 cmp r3, #0
 *   @0x196a34 ble 0x196a40 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x638>
 *   @0x196a38 ldm r9, {r1, r2}
 *   @0x196a3c bl 0x196408 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_>
 *   @0x196a40 cmp r10, r8
 *   @0x196a44 add r9, r9, #12
 *   @0x196a48 bne 0x196a24 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x61c>
 *   @0x196a4c mov r0, r7
 *   @0x196a50 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x196a54 vldr s13, [r11]
 *   @0x196a58 vcvt.f32.s32 s15, s13
 *   @0x196a5c ldr r3, [r11, #0x4]
 *   @0x196a60 vmul.f32 s15, s15, s16
 *   @0x196a64 vcvt.s32.f32 s15, s15
 *   @0x196a68 vstr s15, [r11, #12]
 *   @0x196a6c b 0x196864 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_+0x45c>
 *
 * ══ §11/19 CHashMap<int, CLayer*, 7>::Insert  0x1c2a90  size 1640  410 条（0x1c2a90..0x1c30f8）
 * @func 0x1c2a90 0x1c30f8  size 1640  410 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CHashMapCalculateHash(int)×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / 0xb65b0×3 / MemoryManager::Free(void const*)×3 / CHashMap<int, CLayer*, 7>::Insert(int, CLayer*)+0x70 / CHashMap<int, CLayer*, 7>::Insert(int, CLayer*)+0x1d0 / CHashMap<int, CLayer*, 7>::Insert(int, CLayer*)+0x340 / CHashMap<int, CLayer*, 7>::Insert(int, CLayer*)+0x318
 * 字段偏移 top8: 0x4×33 / 0x8×30 / 0x10×18 / 0xc×7 / 0x1c×6 / 0x24×5 / 0x18×5 / 0x20×4
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c2a90 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1c2a94 vpush {d8}
 *   @0x1c2a98 sub sp, sp, #60
 *   @0x1c2a9c ldr r3, [r0, #0x4]
 *   @0x1c2aa0 mov r11, r0
 *   @0x1c2aa4 str r2, [sp, #0x24]
 *   @0x1c2aa8 ldr r2, [r0, #0xc]
 *   @0x1c2aac str r1, [sp, #0x1c]
 *   @0x1c2ab0 cmp r3, r2
 *   @0x1c2ab4 bgt 0x1c2bc4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x134>
 *   @0x1c2ab8 add r3, r3, #1
 *   @0x1c2abc ldr r0, [sp, #0x1c]
 *   @0x1c2ac0 str r3, [r11, #0x4]
 *   @0x1c2ac4 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1c2ac8 ldr r4, [r11, #0x8]
 *   @0x1c2acc ldr r6, [r11, #0x10]
 *   @0x1c2ad0 bic r0, r0, #-2147483648
 *   @0x1c2ad4 and r3, r0, r4
 *   @0x1c2ad8 add r2, r3, r3, lsl #1
 *   @0x1c2adc add r2, r6, r2, lsl #2
 *   @0x1c2ae0 ldr r12, [r2, #0x8]
 *   @0x1c2ae4 cmp r12, #0
 *   @0x1c2ae8 beq 0x1c2ba4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x114>
 *   @0x1c2aec ldr r7, [r11]
 *   @0x1c2af0 mov r1, #0
 *   @0x1c2af4 ldr r8, [sp, #0x1c]
 *   @0x1c2af8 ldr r9, [sp, #0x24]
 *   @0x1c2afc b 0x1c2b44 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0xb4>
 *   @0x1c2b00 ldr r10, [r2]
 *   @0x1c2b04 mov r1, r5
 *   @0x1c2b08 ldr r5, [r2, #0x4]
 *   @0x1c2b0c str r0, [r2, #0x8]
 *   @0x1c2b10 mov r0, r12
 *   @0x1c2b14 str r8, [r2]
 *   @0x1c2b18 mov r8, r10
 *   @0x1c2b1c str r9, [r2, #0x4]
 *   @0x1c2b20 mov r9, r5
 *   @0x1c2b24 add r3, r3, #1
 *   @0x1c2b28 add r1, r1, #1
 *   @0x1c2b2c and r3, r3, r4
 *   @0x1c2b30 add r2, r3, r3, lsl #1
 *   @0x1c2b34 add r2, r6, r2, lsl #2
 *   @0x1c2b38 ldr r12, [r2, #0x8]
 *   @0x1c2b3c cmp r12, #0
 *   @0x1c2b40 beq 0x1c2b9c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x10c>
 *   @0x1c2b44 add r5, r7, r3
 *   @0x1c2b48 and r10, r12, r4
 *   @0x1c2b4c rsb r5, r10, r5
 *   @0x1c2b50 and r5, r5, r4
 *   @0x1c2b54 cmp r5, r1
 *   @0x1c2b58 blt 0x1c2b00 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x70>
 *   @0x1c2b5c cmp r1, r5
 *   @0x1c2b60 bne 0x1c2b24 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x94>
 *   @0x1c2b64 cmp r0, r12
 *   @0x1c2b68 bne 0x1c2b24 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x94>
 *   @0x1c2b6c ldr r12, [r2]
 *   @0x1c2b70 cmp r8, r12
 *   @0x1c2b74 bne 0x1c2b24 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x94>
 *   @0x1c2b78 ldr r3, [r11, #0x4]
 *   @0x1c2b7c str r8, [sp, #0x1c]
 *   @0x1c2b80 str r8, [r2]
 *   @0x1c2b84 sub r3, r3, #1
 *   @0x1c2b88 str r9, [r2, #0x4]
 *   @0x1c2b8c str r0, [r2, #0x8]
 *   @0x1c2b90 str r9, [sp, #0x24]
 *   @0x1c2b94 str r3, [r11, #0x4]
 *   @0x1c2b98 b 0x1c2bb8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x128>
 *   @0x1c2b9c str r8, [sp, #0x1c]
 *   @0x1c2ba0 str r9, [sp, #0x24]
 *   @0x1c2ba4 ldr r12, [sp, #0x1c]
 *   @0x1c2ba8 str r0, [r2, #0x8]
 *   @0x1c2bac str r12, [r2]
 *   @0x1c2bb0 ldr r12, [sp, #0x24]
 *   @0x1c2bb4 str r12, [r2, #0x4]
 *   @0x1c2bb8 add sp, sp, #60
 *   @0x1c2bbc vpop {d8}
 *   @0x1c2bc0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1c2bc4 ldr r12, [r0]
 *   @0x1c2bc8 mov r3, #1
 *   @0x1c2bcc ldr r1, [pc, #0x430]
 *   @0x1c2bd0 mov r2, #70
 *   @0x1c2bd4 str r12, [sp, #0x20]
 *   @0x1c2bd8 add r1, pc, r1
 *   @0x1c2bdc ldr r12, [r0, #0x10]
 *   @0x1c2be0 str r12, [sp, #0x30]
 *   @0x1c2be4 ldr r12, [sp, #0x20]
 *   @0x1c2be8 lsl r0, r12, r3
 *   @0x1c2bec str r0, [r11]
 *   @0x1c2bf0 add r4, r0, r12, lsl #2
 *   @0x1c2bf4 sub r0, r0, #1
 *   @0x1c2bf8 str r0, [r11, #0x8]
 *   @0x1c2bfc lsl r4, r4, #2
 *   @0x1c2c00 mov r0, r4
 *   @0x1c2c04 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c2c08 mov r2, r4
 *   @0x1c2c0c mov r1, #0
 *   @0x1c2c10 str r0, [r11, #0x10]
 *   @0x1c2c14 bl 0xb65b0 <memset@plt>
 *   @0x1c2c18 ldr r2, [r11]
 *   @0x1c2c1c vldr s15, [pc, #988]
 *   @0x1c2c20 mov r1, #0
 *   @0x1c2c24 cmp r2, r1
 *   @0x1c2c28 str r1, [r11, #0x4]
 *   @0x1c2c2c vmov s13, r2
 *   @0x1c2c30 vcvt.f32.s32 s14, s13
 *   @0x1c2c34 vmul.f32 s15, s14, s15
 *   @0x1c2c38 vcvt.s32.f32 s15, s15
 *   @0x1c2c3c vstr s15, [r11, #12]
 *   @0x1c2c40 ble 0x1c2c60 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x1d0>
 *   @0x1c2c44 add r2, r2, r2, lsl #1
 *   @0x1c2c48 ldr r3, [r11, #0x10]
 *   @0x1c2c4c add r2, r3, r2, lsl #2
 *   @0x1c2c50 str r1, [r3, #0x8]
 *   @0x1c2c54 add r3, r3, #12
 *   @0x1c2c58 cmp r3, r2
 *   @0x1c2c5c bne 0x1c2c50 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x1c0>
 *   @0x1c2c60 ldr r12, [sp, #0x20]
 *   @0x1c2c64 cmp r12, #0
 *   @0x1c2c68 ble 0x1c2dd0 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x340>
 *   @0x1c2c6c ldr r12, [pc, #0x394]
 *   @0x1c2c70 vldr s16, [pc, #904]
 *   @0x1c2c74 add r12, pc, r12
 *   @0x1c2c78 str r12, [sp, #0x34]
 *   @0x1c2c7c mov r12, #0
 *   @0x1c2c80 str r12, [sp, #0xc]
 *   @0x1c2c84 ldr r12, [pc, #0x380]
 *   @0x1c2c88 add r12, pc, r12
 *   @0x1c2c8c str r12, [sp, #0x2c]
 *   @0x1c2c90 ldr r12, [sp, #0x30]
 *   @0x1c2c94 str r12, [sp, #0x8]
 *   @0x1c2c98 ldr r12, [sp, #0x8]
 *   @0x1c2c9c ldr r3, [r12, #0x8]
 *   @0x1c2ca0 cmp r3, #0
 *   @0x1c2ca4 ble 0x1c2da8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x318>
 *   @0x1c2ca8 ldr r12, [r12]
 *   @0x1c2cac ldr r3, [r11, #0x4]
 *   @0x1c2cb0 ldr r2, [r11, #0xc]
 *   @0x1c2cb4 str r12, [sp, #0x10]
 *   @0x1c2cb8 ldr r12, [sp, #0x8]
 *   @0x1c2cbc cmp r3, r2
 *   @0x1c2cc0 ldr r12, [r12, #0x4]
 *   @0x1c2cc4 str r12, [sp, #0x18]
 *   @0x1c2cc8 bgt 0x1c2e18 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x388>
 *   @0x1c2ccc add r3, r3, #1
 *   @0x1c2cd0 ldr r0, [sp, #0x10]
 *   @0x1c2cd4 str r3, [r11, #0x4]
 *   @0x1c2cd8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1c2cdc ldr lr, [r11, #0x8]
 *   @0x1c2ce0 ldr r6, [r11, #0x10]
 *   @0x1c2ce4 bic r0, r0, #-2147483648
 *   @0x1c2ce8 and r3, r0, lr
 *   @0x1c2cec add r2, r3, r3, lsl #1
 *   @0x1c2cf0 add r2, r6, r2, lsl #2
 *   @0x1c2cf4 ldr r1, [r2, #0x8]
 *   @0x1c2cf8 cmp r1, #0
 *   @0x1c2cfc beq 0x1c2e00 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x370>
 *   @0x1c2d00 ldr r7, [r11]
 *   @0x1c2d04 mov r4, #0
 *   @0x1c2d08 ldr r8, [sp, #0x10]
 *   @0x1c2d0c ldr r9, [sp, #0x18]
 *   @0x1c2d10 b 0x1c2d54 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x2c4>
 *   @0x1c2d14 ldr r5, [r2]
 *   @0x1c2d18 ldr r4, [r2, #0x4]
 *   @0x1c2d1c str r0, [r2, #0x8]
 *   @0x1c2d20 mov r0, r1
 *   @0x1c2d24 str r8, [r2]
 *   @0x1c2d28 mov r8, r5
 *   @0x1c2d2c str r9, [r2, #0x4]
 *   @0x1c2d30 mov r9, r4
 *   @0x1c2d34 add r3, r3, #1
 *   @0x1c2d38 add r4, r12, #1
 *   @0x1c2d3c and r3, r3, lr
 *   @0x1c2d40 add r2, r3, r3, lsl #1
 *   @0x1c2d44 add r2, r6, r2, lsl #2
 *   @0x1c2d48 ldr r1, [r2, #0x8]
 *   @0x1c2d4c cmp r1, #0
 *   @0x1c2d50 beq 0x1c2df8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x368>
 *   @0x1c2d54 add r12, r7, r3
 *   @0x1c2d58 and r5, r1, lr
 *   @0x1c2d5c rsb r12, r5, r12
 *   @0x1c2d60 and r12, r12, lr
 *   @0x1c2d64 cmp r12, r4
 *   @0x1c2d68 blt 0x1c2d14 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x284>
 *   @0x1c2d6c movne r12, r4
 *   @0x1c2d70 bne 0x1c2d34 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x2a4>
 *   @0x1c2d74 cmp r1, r0
 *   @0x1c2d78 bne 0x1c2d34 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x2a4>
 *   @0x1c2d7c ldr r4, [r2]
 *   @0x1c2d80 cmp r8, r4
 *   @0x1c2d84 bne 0x1c2d34 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x2a4>
 *   @0x1c2d88 ldr r3, [r11, #0x4]
 *   @0x1c2d8c str r8, [sp, #0x10]
 *   @0x1c2d90 str r8, [r2]
 *   @0x1c2d94 sub r3, r3, #1
 *   @0x1c2d98 str r9, [r2, #0x4]
 *   @0x1c2d9c str r1, [r2, #0x8]
 *   @0x1c2da0 str r9, [sp, #0x18]
 *   @0x1c2da4 str r3, [r11, #0x4]
 *   @0x1c2da8 ldr r12, [sp, #0xc]
 *   @0x1c2dac ldr r0, [sp, #0x20]
 *   @0x1c2db0 add r12, r12, #1
 *   @0x1c2db4 str r12, [sp, #0xc]
 *   @0x1c2db8 ldr r12, [sp, #0x8]
 *   @0x1c2dbc add r12, r12, #12
 *   @0x1c2dc0 str r12, [sp, #0x8]
 *   @0x1c2dc4 ldr r12, [sp, #0xc]
 *   @0x1c2dc8 cmp r12, r0
 *   @0x1c2dcc bne 0x1c2c98 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x208>
 *   @0x1c2dd0 ldr r0, [sp, #0x30]
 *   @0x1c2dd4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1c2dd8 vldr s13, [r11]
 *   @0x1c2ddc vcvt.f32.s32 s14, s13
 *   @0x1c2de0 vldr s15, [pc, #536]
 *   @0x1c2de4 ldr r3, [r11, #0x4]
 *   @0x1c2de8 vmul.f32 s15, s14, s15
 *   @0x1c2dec vcvt.s32.f32 s15, s15
 *   @0x1c2df0 vstr s15, [r11, #12]
 *   @0x1c2df4 b 0x1c2ab8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x28>
 *   @0x1c2df8 str r8, [sp, #0x10]
 *   @0x1c2dfc str r9, [sp, #0x18]
 *   @0x1c2e00 ldr r12, [sp, #0x10]
 *   @0x1c2e04 str r0, [r2, #0x8]
 *   @0x1c2e08 str r12, [r2]
 *   @0x1c2e0c ldr r12, [sp, #0x18]
 *   @0x1c2e10 str r12, [r2, #0x4]
 *   @0x1c2e14 b 0x1c2da8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x318>
 *   @0x1c2e18 ldr r12, [r11]
 *   @0x1c2e1c mov r3, #1
 *   @0x1c2e20 ldr r1, [sp, #0x34]
 *   @0x1c2e24 mov r2, #70
 *   @0x1c2e28 str r12, [sp, #0x14]
 *   @0x1c2e2c ldr r12, [r11, #0x10]
 *   @0x1c2e30 str r12, [sp, #0x28]
 *   @0x1c2e34 ldr r12, [sp, #0x14]
 *   @0x1c2e38 lsl r0, r12, r3
 *   @0x1c2e3c str r0, [r11]
 *   @0x1c2e40 add r4, r0, r12, lsl #2
 *   @0x1c2e44 sub r0, r0, #1
 *   @0x1c2e48 str r0, [r11, #0x8]
 *   @0x1c2e4c lsl r4, r4, #2
 *   @0x1c2e50 mov r0, r4
 *   @0x1c2e54 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c2e58 mov r2, r4
 *   @0x1c2e5c mov r1, #0
 *   @0x1c2e60 str r0, [r11, #0x10]
 *   @0x1c2e64 bl 0xb65b0 <memset@plt>
 *   @0x1c2e68 ldr r2, [r11]
 *   @0x1c2e6c mov r0, #0
 *   @0x1c2e70 str r0, [r11, #0x4]
 *   @0x1c2e74 cmp r2, r0
 *   @0x1c2e78 vmov s13, r2
 *   @0x1c2e7c vcvt.f32.s32 s15, s13
 *   @0x1c2e80 vmul.f32 s15, s15, s16
 *   @0x1c2e84 vcvt.s32.f32 s15, s15
 *   @0x1c2e88 vstr s15, [r11, #12]
 *   @0x1c2e8c ble 0x1c2eb0 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x420>
 *   @0x1c2e90 add r2, r2, r2, lsl #1
 *   @0x1c2e94 ldr r3, [r11, #0x10]
 *   @0x1c2e98 add r2, r3, r2, lsl #2
 *   @0x1c2e9c mov r0, #0
 *   @0x1c2ea0 add r3, r3, #12
 *   @0x1c2ea4 str r0, [r3, #-0x4]
 *   @0x1c2ea8 cmp r3, r2
 *   @0x1c2eac bne 0x1c2e9c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x40c>
 *   @0x1c2eb0 ldr r12, [sp, #0x14]
 *   @0x1c2eb4 cmp r12, #0
 *   @0x1c2eb8 ble 0x1c2fd0 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x540>
 *   @0x1c2ebc ldr r6, [sp, #0x28]
 *   @0x1c2ec0 mov r12, #0
 *   @0x1c2ec4 str r12, [sp, #0x4]
 *   @0x1c2ec8 ldr r3, [r6, #0x8]
 *   @0x1c2ecc cmp r3, #0
 *   @0x1c2ed0 ble 0x1c2fb4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x524>
 *   @0x1c2ed4 ldr r3, [r11, #0x4]
 *   @0x1c2ed8 ldr r2, [r11, #0xc]
 *   @0x1c2edc ldr r4, [r6]
 *   @0x1c2ee0 cmp r3, r2
 *   @0x1c2ee4 ldr r5, [r6, #0x4]
 *   @0x1c2ee8 bgt 0x1c3010 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x580>
 *   @0x1c2eec add r3, r3, #1
 *   @0x1c2ef0 mov r0, r4
 *   @0x1c2ef4 str r3, [r11, #0x4]
 *   @0x1c2ef8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1c2efc ldr lr, [r11, #0x8]
 *   @0x1c2f00 ldr r9, [r11, #0x10]
 *   @0x1c2f04 bic r0, r0, #-2147483648
 *   @0x1c2f08 and r3, r0, lr
 *   @0x1c2f0c add r2, r3, r3, lsl #1
 *   @0x1c2f10 add r2, r9, r2, lsl #2
 *   @0x1c2f14 ldr r1, [r2, #0x8]
 *   @0x1c2f18 cmp r1, #0
 *   @0x1c2f1c ldrne r10, [r11]
 *   @0x1c2f20 movne r7, #0
 *   @0x1c2f24 bne 0x1c2f6c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x4dc>
 *   @0x1c2f28 b 0x1c2ff4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x564>
 *   @0x1c2f2c ldr r8, [r2]
 *   @0x1c2f30 ldr r7, [r2, #0x4]
 *   @0x1c2f34 str r0, [r2, #0x8]
 *   @0x1c2f38 mov r0, r1
 *   @0x1c2f3c str r4, [r2]
 *   @0x1c2f40 mov r4, r8
 *   @0x1c2f44 str r5, [r2, #0x4]
 *   @0x1c2f48 mov r5, r7
 *   @0x1c2f4c add r3, r3, #1
 *   @0x1c2f50 add r7, r12, #1
 *   @0x1c2f54 and r3, r3, lr
 *   @0x1c2f58 add r2, r3, r3, lsl #1
 *   @0x1c2f5c add r2, r9, r2, lsl #2
 *   @0x1c2f60 ldr r1, [r2, #0x8]
 *   @0x1c2f64 cmp r1, #0
 *   @0x1c2f68 beq 0x1c2ff4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x564>
 *   @0x1c2f6c add r12, r3, r10
 *   @0x1c2f70 and r8, r1, lr
 *   @0x1c2f74 rsb r12, r8, r12
 *   @0x1c2f78 and r12, r12, lr
 *   @0x1c2f7c cmp r12, r7
 *   @0x1c2f80 blt 0x1c2f2c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x49c>
 *   @0x1c2f84 movne r12, r7
 *   @0x1c2f88 bne 0x1c2f4c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x4bc>
 *   @0x1c2f8c cmp r1, r0
 *   @0x1c2f90 bne 0x1c2f4c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x4bc>
 *   @0x1c2f94 ldr r7, [r2]
 *   @0x1c2f98 cmp r4, r7
 *   @0x1c2f9c bne 0x1c2f4c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x4bc>
 *   @0x1c2fa0 ldr r3, [r11, #0x4]
 *   @0x1c2fa4 stm r2, {r4, r5}
 *   @0x1c2fa8 sub r3, r3, #1
 *   @0x1c2fac str r1, [r2, #0x8]
 *   @0x1c2fb0 str r3, [r11, #0x4]
 *   @0x1c2fb4 ldr r12, [sp, #0x4]
 *   @0x1c2fb8 add r6, r6, #12
 *   @0x1c2fbc ldr r0, [sp, #0x14]
 *   @0x1c2fc0 add r12, r12, #1
 *   @0x1c2fc4 str r12, [sp, #0x4]
 *   @0x1c2fc8 cmp r12, r0
 *   @0x1c2fcc bne 0x1c2ec8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x438>
 *   @0x1c2fd0 ldr r0, [sp, #0x28]
 *   @0x1c2fd4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1c2fd8 vldr s13, [r11]
 *   @0x1c2fdc vcvt.f32.s32 s15, s13
 *   @0x1c2fe0 ldr r3, [r11, #0x4]
 *   @0x1c2fe4 vmul.f32 s15, s15, s16
 *   @0x1c2fe8 vcvt.s32.f32 s15, s15
 *   @0x1c2fec vstr s15, [r11, #12]
 *   @0x1c2ff0 b 0x1c2ccc <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x23c>
 *   @0x1c2ff4 stm r2, {r4, r5}
 *   @0x1c2ff8 str r0, [r2, #0x8]
 *   @0x1c2ffc b 0x1c2fb4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x524>
 *   @0x1c3000 svclo #0x19999a
 *   @0x1c3004 andseq lr, r6, r8, asr r4
 *   @0x1c3008 ldrheq lr, [r6], -r12
 *   @0x1c300c andseq lr, r6, r8, lsr #7
 *   @0x1c3010 ldr r8, [r11]
 *   @0x1c3014 mov r3, #1
 *   @0x1c3018 ldr r1, [sp, #0x2c]
 *   @0x1c301c mov r2, #70
 *   @0x1c3020 ldr r7, [r11, #0x10]
 *   @0x1c3024 lsl r0, r8, r3
 *   @0x1c3028 str r0, [r11]
 *   @0x1c302c add r9, r0, r8, lsl #2
 *   @0x1c3030 sub r0, r0, #1
 *   @0x1c3034 str r0, [r11, #0x8]
 *   @0x1c3038 lsl r9, r9, #2
 *   @0x1c303c mov r0, r9
 *   @0x1c3040 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c3044 mov r2, r9
 *   @0x1c3048 mov r1, #0
 *   @0x1c304c str r0, [r11, #0x10]
 *   @0x1c3050 bl 0xb65b0 <memset@plt>
 *   @0x1c3054 ldr r2, [r11]
 *   @0x1c3058 mov r0, #0
 *   @0x1c305c str r0, [r11, #0x4]
 *   @0x1c3060 cmp r2, r0
 *   @0x1c3064 vmov s13, r2
 *   @0x1c3068 vcvt.f32.s32 s15, s13
 *   @0x1c306c vmul.f32 s15, s15, s16
 *   @0x1c3070 vcvt.s32.f32 s15, s15
 *   @0x1c3074 vstr s15, [r11, #12]
 *   @0x1c3078 ble 0x1c309c <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x60c>
 *   @0x1c307c add r2, r2, r2, lsl #1
 *   @0x1c3080 ldr r3, [r11, #0x10]
 *   @0x1c3084 add r2, r3, r2, lsl #2
 *   @0x1c3088 mov r0, #0
 *   @0x1c308c add r3, r3, #12
 *   @0x1c3090 str r0, [r3, #-0x4]
 *   @0x1c3094 cmp r3, r2
 *   @0x1c3098 bne 0x1c3088 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x5f8>
 *   @0x1c309c cmp r8, #0
 *   @0x1c30a0 movgt r9, r7
 *   @0x1c30a4 movgt r10, #0
 *   @0x1c30a8 ble 0x1c30d4 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x644>
 *   @0x1c30ac ldr r3, [r9, #0x8]
 *   @0x1c30b0 mov r0, r11
 *   @0x1c30b4 add r10, r10, #1
 *   @0x1c30b8 cmp r3, #0
 *   @0x1c30bc ble 0x1c30c8 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x638>
 *   @0x1c30c0 ldm r9, {r1, r2}
 *   @0x1c30c4 bl 0x1c2a90 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_>
 *   @0x1c30c8 cmp r10, r8
 *   @0x1c30cc add r9, r9, #12
 *   @0x1c30d0 bne 0x1c30ac <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x61c>
 *   @0x1c30d4 mov r0, r7
 *   @0x1c30d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1c30dc vldr s13, [r11]
 *   @0x1c30e0 vcvt.f32.s32 s15, s13
 *   @0x1c30e4 ldr r3, [r11, #0x4]
 *   @0x1c30e8 vmul.f32 s15, s15, s16
 *   @0x1c30ec vcvt.s32.f32 s15, s15
 *   @0x1c30f0 vstr s15, [r11, #12]
 *   @0x1c30f4 b 0x1c2eec <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x45c>
 *
 * ══ §12/19 CHashMap<int, CLayerElementBase*, 7>::Insert  0x1c384c  size 1640  410 条（0x1c384c..0x1c3eb4）
 * @func 0x1c384c 0x1c3eb4  size 1640  410 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CHashMapCalculateHash(int)×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / 0xb65b0×3 / MemoryManager::Free(void const*)×3 / CHashMap<int, CLayerElementBase*, 7>::Insert(int, CLayerElementBase*)+0x70 / CHashMap<int, CLayerElementBase*, 7>::Insert(int, CLayerElementBase*)+0x1d0 / CHashMap<int, CLayerElementBase*, 7>::Insert(int, CLayerElementBase*)+0x340 / CHashMap<int, CLayerElementBase*, 7>::Insert(int, CLayerElementBase*)+0x318
 * 字段偏移 top8: 0x4×33 / 0x8×30 / 0x10×18 / 0xc×7 / 0x1c×6 / 0x24×5 / 0x18×5 / 0x20×4
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c384c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1c3850 vpush {d8}
 *   @0x1c3854 sub sp, sp, #60
 *   @0x1c3858 ldr r3, [r0, #0x4]
 *   @0x1c385c mov r11, r0
 *   @0x1c3860 str r2, [sp, #0x24]
 *   @0x1c3864 ldr r2, [r0, #0xc]
 *   @0x1c3868 str r1, [sp, #0x1c]
 *   @0x1c386c cmp r3, r2
 *   @0x1c3870 bgt 0x1c3980 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x134>
 *   @0x1c3874 add r3, r3, #1
 *   @0x1c3878 ldr r0, [sp, #0x1c]
 *   @0x1c387c str r3, [r11, #0x4]
 *   @0x1c3880 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1c3884 ldr r4, [r11, #0x8]
 *   @0x1c3888 ldr r6, [r11, #0x10]
 *   @0x1c388c bic r0, r0, #-2147483648
 *   @0x1c3890 and r3, r0, r4
 *   @0x1c3894 add r2, r3, r3, lsl #1
 *   @0x1c3898 add r2, r6, r2, lsl #2
 *   @0x1c389c ldr r12, [r2, #0x8]
 *   @0x1c38a0 cmp r12, #0
 *   @0x1c38a4 beq 0x1c3960 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x114>
 *   @0x1c38a8 ldr r7, [r11]
 *   @0x1c38ac mov r1, #0
 *   @0x1c38b0 ldr r8, [sp, #0x1c]
 *   @0x1c38b4 ldr r9, [sp, #0x24]
 *   @0x1c38b8 b 0x1c3900 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0xb4>
 *   @0x1c38bc ldr r10, [r2]
 *   @0x1c38c0 mov r1, r5
 *   @0x1c38c4 ldr r5, [r2, #0x4]
 *   @0x1c38c8 str r0, [r2, #0x8]
 *   @0x1c38cc mov r0, r12
 *   @0x1c38d0 str r8, [r2]
 *   @0x1c38d4 mov r8, r10
 *   @0x1c38d8 str r9, [r2, #0x4]
 *   @0x1c38dc mov r9, r5
 *   @0x1c38e0 add r3, r3, #1
 *   @0x1c38e4 add r1, r1, #1
 *   @0x1c38e8 and r3, r3, r4
 *   @0x1c38ec add r2, r3, r3, lsl #1
 *   @0x1c38f0 add r2, r6, r2, lsl #2
 *   @0x1c38f4 ldr r12, [r2, #0x8]
 *   @0x1c38f8 cmp r12, #0
 *   @0x1c38fc beq 0x1c3958 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x10c>
 *   @0x1c3900 add r5, r7, r3
 *   @0x1c3904 and r10, r12, r4
 *   @0x1c3908 rsb r5, r10, r5
 *   @0x1c390c and r5, r5, r4
 *   @0x1c3910 cmp r5, r1
 *   @0x1c3914 blt 0x1c38bc <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x70>
 *   @0x1c3918 cmp r1, r5
 *   @0x1c391c bne 0x1c38e0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x94>
 *   @0x1c3920 cmp r0, r12
 *   @0x1c3924 bne 0x1c38e0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x94>
 *   @0x1c3928 ldr r12, [r2]
 *   @0x1c392c cmp r8, r12
 *   @0x1c3930 bne 0x1c38e0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x94>
 *   @0x1c3934 ldr r3, [r11, #0x4]
 *   @0x1c3938 str r8, [sp, #0x1c]
 *   @0x1c393c str r8, [r2]
 *   @0x1c3940 sub r3, r3, #1
 *   @0x1c3944 str r9, [r2, #0x4]
 *   @0x1c3948 str r0, [r2, #0x8]
 *   @0x1c394c str r9, [sp, #0x24]
 *   @0x1c3950 str r3, [r11, #0x4]
 *   @0x1c3954 b 0x1c3974 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x128>
 *   @0x1c3958 str r8, [sp, #0x1c]
 *   @0x1c395c str r9, [sp, #0x24]
 *   @0x1c3960 ldr r12, [sp, #0x1c]
 *   @0x1c3964 str r0, [r2, #0x8]
 *   @0x1c3968 str r12, [r2]
 *   @0x1c396c ldr r12, [sp, #0x24]
 *   @0x1c3970 str r12, [r2, #0x4]
 *   @0x1c3974 add sp, sp, #60
 *   @0x1c3978 vpop {d8}
 *   @0x1c397c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1c3980 ldr r12, [r0]
 *   @0x1c3984 mov r3, #1
 *   @0x1c3988 ldr r1, [pc, #0x430]
 *   @0x1c398c mov r2, #70
 *   @0x1c3990 str r12, [sp, #0x20]
 *   @0x1c3994 add r1, pc, r1
 *   @0x1c3998 ldr r12, [r0, #0x10]
 *   @0x1c399c str r12, [sp, #0x30]
 *   @0x1c39a0 ldr r12, [sp, #0x20]
 *   @0x1c39a4 lsl r0, r12, r3
 *   @0x1c39a8 str r0, [r11]
 *   @0x1c39ac add r4, r0, r12, lsl #2
 *   @0x1c39b0 sub r0, r0, #1
 *   @0x1c39b4 str r0, [r11, #0x8]
 *   @0x1c39b8 lsl r4, r4, #2
 *   @0x1c39bc mov r0, r4
 *   @0x1c39c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c39c4 mov r2, r4
 *   @0x1c39c8 mov r1, #0
 *   @0x1c39cc str r0, [r11, #0x10]
 *   @0x1c39d0 bl 0xb65b0 <memset@plt>
 *   @0x1c39d4 ldr r2, [r11]
 *   @0x1c39d8 vldr s15, [pc, #988]
 *   @0x1c39dc mov r1, #0
 *   @0x1c39e0 cmp r2, r1
 *   @0x1c39e4 str r1, [r11, #0x4]
 *   @0x1c39e8 vmov s13, r2
 *   @0x1c39ec vcvt.f32.s32 s14, s13
 *   @0x1c39f0 vmul.f32 s15, s14, s15
 *   @0x1c39f4 vcvt.s32.f32 s15, s15
 *   @0x1c39f8 vstr s15, [r11, #12]
 *   @0x1c39fc ble 0x1c3a1c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x1d0>
 *   @0x1c3a00 add r2, r2, r2, lsl #1
 *   @0x1c3a04 ldr r3, [r11, #0x10]
 *   @0x1c3a08 add r2, r3, r2, lsl #2
 *   @0x1c3a0c str r1, [r3, #0x8]
 *   @0x1c3a10 add r3, r3, #12
 *   @0x1c3a14 cmp r3, r2
 *   @0x1c3a18 bne 0x1c3a0c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x1c0>
 *   @0x1c3a1c ldr r12, [sp, #0x20]
 *   @0x1c3a20 cmp r12, #0
 *   @0x1c3a24 ble 0x1c3b8c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x340>
 *   @0x1c3a28 ldr r12, [pc, #0x394]
 *   @0x1c3a2c vldr s16, [pc, #904]
 *   @0x1c3a30 add r12, pc, r12
 *   @0x1c3a34 str r12, [sp, #0x34]
 *   @0x1c3a38 mov r12, #0
 *   @0x1c3a3c str r12, [sp, #0xc]
 *   @0x1c3a40 ldr r12, [pc, #0x380]
 *   @0x1c3a44 add r12, pc, r12
 *   @0x1c3a48 str r12, [sp, #0x2c]
 *   @0x1c3a4c ldr r12, [sp, #0x30]
 *   @0x1c3a50 str r12, [sp, #0x8]
 *   @0x1c3a54 ldr r12, [sp, #0x8]
 *   @0x1c3a58 ldr r3, [r12, #0x8]
 *   @0x1c3a5c cmp r3, #0
 *   @0x1c3a60 ble 0x1c3b64 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x318>
 *   @0x1c3a64 ldr r12, [r12]
 *   @0x1c3a68 ldr r3, [r11, #0x4]
 *   @0x1c3a6c ldr r2, [r11, #0xc]
 *   @0x1c3a70 str r12, [sp, #0x10]
 *   @0x1c3a74 ldr r12, [sp, #0x8]
 *   @0x1c3a78 cmp r3, r2
 *   @0x1c3a7c ldr r12, [r12, #0x4]
 *   @0x1c3a80 str r12, [sp, #0x18]
 *   @0x1c3a84 bgt 0x1c3bd4 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x388>
 *   @0x1c3a88 add r3, r3, #1
 *   @0x1c3a8c ldr r0, [sp, #0x10]
 *   @0x1c3a90 str r3, [r11, #0x4]
 *   @0x1c3a94 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1c3a98 ldr lr, [r11, #0x8]
 *   @0x1c3a9c ldr r6, [r11, #0x10]
 *   @0x1c3aa0 bic r0, r0, #-2147483648
 *   @0x1c3aa4 and r3, r0, lr
 *   @0x1c3aa8 add r2, r3, r3, lsl #1
 *   @0x1c3aac add r2, r6, r2, lsl #2
 *   @0x1c3ab0 ldr r1, [r2, #0x8]
 *   @0x1c3ab4 cmp r1, #0
 *   @0x1c3ab8 beq 0x1c3bbc <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x370>
 *   @0x1c3abc ldr r7, [r11]
 *   @0x1c3ac0 mov r4, #0
 *   @0x1c3ac4 ldr r8, [sp, #0x10]
 *   @0x1c3ac8 ldr r9, [sp, #0x18]
 *   @0x1c3acc b 0x1c3b10 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x2c4>
 *   @0x1c3ad0 ldr r5, [r2]
 *   @0x1c3ad4 ldr r4, [r2, #0x4]
 *   @0x1c3ad8 str r0, [r2, #0x8]
 *   @0x1c3adc mov r0, r1
 *   @0x1c3ae0 str r8, [r2]
 *   @0x1c3ae4 mov r8, r5
 *   @0x1c3ae8 str r9, [r2, #0x4]
 *   @0x1c3aec mov r9, r4
 *   @0x1c3af0 add r3, r3, #1
 *   @0x1c3af4 add r4, r12, #1
 *   @0x1c3af8 and r3, r3, lr
 *   @0x1c3afc add r2, r3, r3, lsl #1
 *   @0x1c3b00 add r2, r6, r2, lsl #2
 *   @0x1c3b04 ldr r1, [r2, #0x8]
 *   @0x1c3b08 cmp r1, #0
 *   @0x1c3b0c beq 0x1c3bb4 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x368>
 *   @0x1c3b10 add r12, r7, r3
 *   @0x1c3b14 and r5, r1, lr
 *   @0x1c3b18 rsb r12, r5, r12
 *   @0x1c3b1c and r12, r12, lr
 *   @0x1c3b20 cmp r12, r4
 *   @0x1c3b24 blt 0x1c3ad0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x284>
 *   @0x1c3b28 movne r12, r4
 *   @0x1c3b2c bne 0x1c3af0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x2a4>
 *   @0x1c3b30 cmp r1, r0
 *   @0x1c3b34 bne 0x1c3af0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x2a4>
 *   @0x1c3b38 ldr r4, [r2]
 *   @0x1c3b3c cmp r8, r4
 *   @0x1c3b40 bne 0x1c3af0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x2a4>
 *   @0x1c3b44 ldr r3, [r11, #0x4]
 *   @0x1c3b48 str r8, [sp, #0x10]
 *   @0x1c3b4c str r8, [r2]
 *   @0x1c3b50 sub r3, r3, #1
 *   @0x1c3b54 str r9, [r2, #0x4]
 *   @0x1c3b58 str r1, [r2, #0x8]
 *   @0x1c3b5c str r9, [sp, #0x18]
 *   @0x1c3b60 str r3, [r11, #0x4]
 *   @0x1c3b64 ldr r12, [sp, #0xc]
 *   @0x1c3b68 ldr r0, [sp, #0x20]
 *   @0x1c3b6c add r12, r12, #1
 *   @0x1c3b70 str r12, [sp, #0xc]
 *   @0x1c3b74 ldr r12, [sp, #0x8]
 *   @0x1c3b78 add r12, r12, #12
 *   @0x1c3b7c str r12, [sp, #0x8]
 *   @0x1c3b80 ldr r12, [sp, #0xc]
 *   @0x1c3b84 cmp r12, r0
 *   @0x1c3b88 bne 0x1c3a54 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x208>
 *   @0x1c3b8c ldr r0, [sp, #0x30]
 *   @0x1c3b90 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1c3b94 vldr s13, [r11]
 *   @0x1c3b98 vcvt.f32.s32 s14, s13
 *   @0x1c3b9c vldr s15, [pc, #536]
 *   @0x1c3ba0 ldr r3, [r11, #0x4]
 *   @0x1c3ba4 vmul.f32 s15, s14, s15
 *   @0x1c3ba8 vcvt.s32.f32 s15, s15
 *   @0x1c3bac vstr s15, [r11, #12]
 *   @0x1c3bb0 b 0x1c3874 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x28>
 *   @0x1c3bb4 str r8, [sp, #0x10]
 *   @0x1c3bb8 str r9, [sp, #0x18]
 *   @0x1c3bbc ldr r12, [sp, #0x10]
 *   @0x1c3bc0 str r0, [r2, #0x8]
 *   @0x1c3bc4 str r12, [r2]
 *   @0x1c3bc8 ldr r12, [sp, #0x18]
 *   @0x1c3bcc str r12, [r2, #0x4]
 *   @0x1c3bd0 b 0x1c3b64 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x318>
 *   @0x1c3bd4 ldr r12, [r11]
 *   @0x1c3bd8 mov r3, #1
 *   @0x1c3bdc ldr r1, [sp, #0x34]
 *   @0x1c3be0 mov r2, #70
 *   @0x1c3be4 str r12, [sp, #0x14]
 *   @0x1c3be8 ldr r12, [r11, #0x10]
 *   @0x1c3bec str r12, [sp, #0x28]
 *   @0x1c3bf0 ldr r12, [sp, #0x14]
 *   @0x1c3bf4 lsl r0, r12, r3
 *   @0x1c3bf8 str r0, [r11]
 *   @0x1c3bfc add r4, r0, r12, lsl #2
 *   @0x1c3c00 sub r0, r0, #1
 *   @0x1c3c04 str r0, [r11, #0x8]
 *   @0x1c3c08 lsl r4, r4, #2
 *   @0x1c3c0c mov r0, r4
 *   @0x1c3c10 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c3c14 mov r2, r4
 *   @0x1c3c18 mov r1, #0
 *   @0x1c3c1c str r0, [r11, #0x10]
 *   @0x1c3c20 bl 0xb65b0 <memset@plt>
 *   @0x1c3c24 ldr r2, [r11]
 *   @0x1c3c28 mov r0, #0
 *   @0x1c3c2c str r0, [r11, #0x4]
 *   @0x1c3c30 cmp r2, r0
 *   @0x1c3c34 vmov s13, r2
 *   @0x1c3c38 vcvt.f32.s32 s15, s13
 *   @0x1c3c3c vmul.f32 s15, s15, s16
 *   @0x1c3c40 vcvt.s32.f32 s15, s15
 *   @0x1c3c44 vstr s15, [r11, #12]
 *   @0x1c3c48 ble 0x1c3c6c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x420>
 *   @0x1c3c4c add r2, r2, r2, lsl #1
 *   @0x1c3c50 ldr r3, [r11, #0x10]
 *   @0x1c3c54 add r2, r3, r2, lsl #2
 *   @0x1c3c58 mov r0, #0
 *   @0x1c3c5c add r3, r3, #12
 *   @0x1c3c60 str r0, [r3, #-0x4]
 *   @0x1c3c64 cmp r3, r2
 *   @0x1c3c68 bne 0x1c3c58 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x40c>
 *   @0x1c3c6c ldr r12, [sp, #0x14]
 *   @0x1c3c70 cmp r12, #0
 *   @0x1c3c74 ble 0x1c3d8c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x540>
 *   @0x1c3c78 ldr r6, [sp, #0x28]
 *   @0x1c3c7c mov r12, #0
 *   @0x1c3c80 str r12, [sp, #0x4]
 *   @0x1c3c84 ldr r3, [r6, #0x8]
 *   @0x1c3c88 cmp r3, #0
 *   @0x1c3c8c ble 0x1c3d70 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x524>
 *   @0x1c3c90 ldr r3, [r11, #0x4]
 *   @0x1c3c94 ldr r2, [r11, #0xc]
 *   @0x1c3c98 ldr r4, [r6]
 *   @0x1c3c9c cmp r3, r2
 *   @0x1c3ca0 ldr r5, [r6, #0x4]
 *   @0x1c3ca4 bgt 0x1c3dcc <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x580>
 *   @0x1c3ca8 add r3, r3, #1
 *   @0x1c3cac mov r0, r4
 *   @0x1c3cb0 str r3, [r11, #0x4]
 *   @0x1c3cb4 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1c3cb8 ldr lr, [r11, #0x8]
 *   @0x1c3cbc ldr r9, [r11, #0x10]
 *   @0x1c3cc0 bic r0, r0, #-2147483648
 *   @0x1c3cc4 and r3, r0, lr
 *   @0x1c3cc8 add r2, r3, r3, lsl #1
 *   @0x1c3ccc add r2, r9, r2, lsl #2
 *   @0x1c3cd0 ldr r1, [r2, #0x8]
 *   @0x1c3cd4 cmp r1, #0
 *   @0x1c3cd8 ldrne r10, [r11]
 *   @0x1c3cdc movne r7, #0
 *   @0x1c3ce0 bne 0x1c3d28 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x4dc>
 *   @0x1c3ce4 b 0x1c3db0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x564>
 *   @0x1c3ce8 ldr r8, [r2]
 *   @0x1c3cec ldr r7, [r2, #0x4]
 *   @0x1c3cf0 str r0, [r2, #0x8]
 *   @0x1c3cf4 mov r0, r1
 *   @0x1c3cf8 str r4, [r2]
 *   @0x1c3cfc mov r4, r8
 *   @0x1c3d00 str r5, [r2, #0x4]
 *   @0x1c3d04 mov r5, r7
 *   @0x1c3d08 add r3, r3, #1
 *   @0x1c3d0c add r7, r12, #1
 *   @0x1c3d10 and r3, r3, lr
 *   @0x1c3d14 add r2, r3, r3, lsl #1
 *   @0x1c3d18 add r2, r9, r2, lsl #2
 *   @0x1c3d1c ldr r1, [r2, #0x8]
 *   @0x1c3d20 cmp r1, #0
 *   @0x1c3d24 beq 0x1c3db0 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x564>
 *   @0x1c3d28 add r12, r3, r10
 *   @0x1c3d2c and r8, r1, lr
 *   @0x1c3d30 rsb r12, r8, r12
 *   @0x1c3d34 and r12, r12, lr
 *   @0x1c3d38 cmp r12, r7
 *   @0x1c3d3c blt 0x1c3ce8 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x49c>
 *   @0x1c3d40 movne r12, r7
 *   @0x1c3d44 bne 0x1c3d08 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x4bc>
 *   @0x1c3d48 cmp r1, r0
 *   @0x1c3d4c bne 0x1c3d08 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x4bc>
 *   @0x1c3d50 ldr r7, [r2]
 *   @0x1c3d54 cmp r4, r7
 *   @0x1c3d58 bne 0x1c3d08 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x4bc>
 *   @0x1c3d5c ldr r3, [r11, #0x4]
 *   @0x1c3d60 stm r2, {r4, r5}
 *   @0x1c3d64 sub r3, r3, #1
 *   @0x1c3d68 str r1, [r2, #0x8]
 *   @0x1c3d6c str r3, [r11, #0x4]
 *   @0x1c3d70 ldr r12, [sp, #0x4]
 *   @0x1c3d74 add r6, r6, #12
 *   @0x1c3d78 ldr r0, [sp, #0x14]
 *   @0x1c3d7c add r12, r12, #1
 *   @0x1c3d80 str r12, [sp, #0x4]
 *   @0x1c3d84 cmp r12, r0
 *   @0x1c3d88 bne 0x1c3c84 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x438>
 *   @0x1c3d8c ldr r0, [sp, #0x28]
 *   @0x1c3d90 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1c3d94 vldr s13, [r11]
 *   @0x1c3d98 vcvt.f32.s32 s15, s13
 *   @0x1c3d9c ldr r3, [r11, #0x4]
 *   @0x1c3da0 vmul.f32 s15, s15, s16
 *   @0x1c3da4 vcvt.s32.f32 s15, s15
 *   @0x1c3da8 vstr s15, [r11, #12]
 *   @0x1c3dac b 0x1c3a88 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x23c>
 *   @0x1c3db0 stm r2, {r4, r5}
 *   @0x1c3db4 str r0, [r2, #0x8]
 *   @0x1c3db8 b 0x1c3d70 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x524>
 *   @0x1c3dbc svclo #0x19999a
 *   @0x1c3dc0 mulseq r6, r12, r6
 *   @0x1c3dc4 andseq sp, r6, r0, lsl #12
 *   @0x1c3dc8 andseq sp, r6, r12, ror #11
 *   @0x1c3dcc ldr r8, [r11]
 *   @0x1c3dd0 mov r3, #1
 *   @0x1c3dd4 ldr r1, [sp, #0x2c]
 *   @0x1c3dd8 mov r2, #70
 *   @0x1c3ddc ldr r7, [r11, #0x10]
 *   @0x1c3de0 lsl r0, r8, r3
 *   @0x1c3de4 str r0, [r11]
 *   @0x1c3de8 add r9, r0, r8, lsl #2
 *   @0x1c3dec sub r0, r0, #1
 *   @0x1c3df0 str r0, [r11, #0x8]
 *   @0x1c3df4 lsl r9, r9, #2
 *   @0x1c3df8 mov r0, r9
 *   @0x1c3dfc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1c3e00 mov r2, r9
 *   @0x1c3e04 mov r1, #0
 *   @0x1c3e08 str r0, [r11, #0x10]
 *   @0x1c3e0c bl 0xb65b0 <memset@plt>
 *   @0x1c3e10 ldr r2, [r11]
 *   @0x1c3e14 mov r0, #0
 *   @0x1c3e18 str r0, [r11, #0x4]
 *   @0x1c3e1c cmp r2, r0
 *   @0x1c3e20 vmov s13, r2
 *   @0x1c3e24 vcvt.f32.s32 s15, s13
 *   @0x1c3e28 vmul.f32 s15, s15, s16
 *   @0x1c3e2c vcvt.s32.f32 s15, s15
 *   @0x1c3e30 vstr s15, [r11, #12]
 *   @0x1c3e34 ble 0x1c3e58 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x60c>
 *   @0x1c3e38 add r2, r2, r2, lsl #1
 *   @0x1c3e3c ldr r3, [r11, #0x10]
 *   @0x1c3e40 add r2, r3, r2, lsl #2
 *   @0x1c3e44 mov r0, #0
 *   @0x1c3e48 add r3, r3, #12
 *   @0x1c3e4c str r0, [r3, #-0x4]
 *   @0x1c3e50 cmp r3, r2
 *   @0x1c3e54 bne 0x1c3e44 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x5f8>
 *   @0x1c3e58 cmp r8, #0
 *   @0x1c3e5c movgt r9, r7
 *   @0x1c3e60 movgt r10, #0
 *   @0x1c3e64 ble 0x1c3e90 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x644>
 *   @0x1c3e68 ldr r3, [r9, #0x8]
 *   @0x1c3e6c mov r0, r11
 *   @0x1c3e70 add r10, r10, #1
 *   @0x1c3e74 cmp r3, #0
 *   @0x1c3e78 ble 0x1c3e84 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x638>
 *   @0x1c3e7c ldm r9, {r1, r2}
 *   @0x1c3e80 bl 0x1c384c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_>
 *   @0x1c3e84 cmp r10, r8
 *   @0x1c3e88 add r9, r9, #12
 *   @0x1c3e8c bne 0x1c3e68 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x61c>
 *   @0x1c3e90 mov r0, r7
 *   @0x1c3e94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1c3e98 vldr s13, [r11]
 *   @0x1c3e9c vcvt.f32.s32 s15, s13
 *   @0x1c3ea0 ldr r3, [r11, #0x4]
 *   @0x1c3ea4 vmul.f32 s15, s15, s16
 *   @0x1c3ea8 vcvt.s32.f32 s15, s15
 *   @0x1c3eac vstr s15, [r11, #12]
 *   @0x1c3eb0 b 0x1c3ca8 <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_+0x45c>
 *
 * ══ §13/19 vorbis_synthesis_blockin  0x227638  size 1608  402 条（0x227638..0x227c80）
 * @func 0x227638 0x227c80  size 1608  402 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: vorbis_synthesis_blockin+0x240×3 / vorbis_synthesis_blockin+0x3c / vorbis_synthesis_blockin+0x28c / vorbis_synthesis_blockin+0x270 / vorbis_synthesis_blockin+0x4ac
 * 字段偏移 top8: 0x18×13 / 0x38×13 / 0x14×12 / 0x2c×10 / 0x8×9 / 0x48×7 / 0xc×7 / 0x24×7
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x227638 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x22763c sub sp, sp, #112
 *   @0x227640 ldr r7, [r0, #0x4]
 *   @0x227644 mov r4, r0
 *   @0x227648 ldr r12, [r0, #0x18]
 *   @0x22764c ldr r3, [r0, #0x14]
 *   @0x227650 str r1, [sp, #0x38]
 *   @0x227654 ldr r0, [r0, #0x48]
 *   @0x227658 cmp r3, r12
 *   @0x22765c ldr r1, [r7, #0x1c]
 *   @0x227660 str r0, [sp, #0x48]
 *   @0x227664 str r1, [sp, #0x2c]
 *   @0x227668 ble 0x227674 <vorbis_synthesis_blockin+0x3c>
 *   @0x22766c cmn r12, #1
 *   @0x227670 bne 0x227c5c <vorbis_synthesis_blockin+0x624>
 *   @0x227674 ldr r5, [r4, #0x28]
 *   @0x227678 mvn r0, #0
 *   @0x22767c ldr r6, [sp, #0x38]
 *   @0x227680 mvn r1, #0
 *   @0x227684 ldrd r2, r3, [r4, #64]
 *   @0x227688 str r5, [sp, #0xc]
 *   @0x22768c mvn r5, #0
 *   @0x227690 ldr r6, [r6, #0x1c]
 *   @0x227694 cmp r3, r1
 *   @0x227698 cmpeq r2, r0
 *   @0x22769c ldr r8, [sp, #0xc]
 *   @0x2276a0 str r5, [r4, #0x2c]
 *   @0x2276a4 str r6, [sp, #0x8]
 *   @0x2276a8 str r8, [r4, #0x24]
 *   @0x2276ac str r6, [r4, #0x28]
 *   @0x2276b0 beq 0x227bbc <vorbis_synthesis_blockin+0x584>
 *   @0x2276b4 ldr r5, [sp, #0x38]
 *   @0x2276b8 adds r2, r2, #1
 *   @0x2276bc adc r3, r3, #0
 *   @0x2276c0 ldrd r0, r1, [r5, #56]
 *   @0x2276c4 cmp r3, r1
 *   @0x2276c8 cmpeq r2, r0
 *   @0x2276cc movne r2, r0
 *   @0x2276d0 movne r0, r1
 *   @0x2276d4 beq 0x227c40 <vorbis_synthesis_blockin+0x608>
 *   @0x2276d8 mvn r1, #0
 *   @0x2276dc str r1, [sp, #0x30]
 *   @0x2276e0 str r1, [sp, #0x34]
 *   @0x2276e4 ldrd r8, r9, [sp, #48]
 *   @0x2276e8 str r1, [r4, #0x38]
 *   @0x2276ec str r1, [r4, #0x3c]
 *   @0x2276f0 strd r8, r9, [sp, #88]
 *   @0x2276f4 ldr r9, [sp, #0x48]
 *   @0x2276f8 str r1, [r9, #0x10]
 *   @0x2276fc str r1, [r9, #0x14]
 *   @0x227700 ldr r1, [sp, #0x38]
 *   @0x227704 ldr r1, [r1]
 *   @0x227708 str r2, [r4, #0x40]
 *   @0x22770c cmp r1, #0
 *   @0x227710 str r0, [r4, #0x44]
 *   @0x227714 str r1, [sp, #0x10]
 *   @0x227718 beq 0x227920 <vorbis_synthesis_blockin+0x2e8>
 *   @0x22771c ldr r3, [sp, #0x2c]
 *   @0x227720 ldr r6, [sp, #0x8]
 *   @0x227724 ldr r5, [r4, #0x30]
 *   @0x227728 ldr r2, [r3, #0x4]
 *   @0x22772c ldr r6, [r3, r6, lsl #2]
 *   @0x227730 cmp r5, #0
 *   @0x227734 ldr r3, [r3]
 *   @0x227738 add r2, r2, r2, lsr #31
 *   @0x22773c ldr r1, [r7, #0x4]
 *   @0x227740 str r5, [sp, #0x64]
 *   @0x227744 asr r2, r2, #1
 *   @0x227748 str r2, [sp, #0x24]
 *   @0x22774c ldr r8, [sp, #0x24]
 *   @0x227750 add r2, r6, r6, lsr #31
 *   @0x227754 ldr r9, [sp, #0x24]
 *   @0x227758 add r3, r3, r3, lsr #31
 *   @0x22775c asr r2, r2, #1
 *   @0x227760 str r6, [sp, #0x44]
 *   @0x227764 movne r8, #0
 *   @0x227768 asr r3, r3, #1
 *   @0x22776c moveq r9, #0
 *   @0x227770 cmp r1, #0
 *   @0x227774 str r8, [sp, #0x50]
 *   @0x227778 str r9, [sp, #0x68]
 *   @0x22777c str r2, [sp, #0x14]
 *   @0x227780 str r3, [sp, #0x18]
 *   @0x227784 ble 0x2278c4 <vorbis_synthesis_blockin+0x28c>
 *   @0x227788 ldr r12, [sp, #0x24]
 *   @0x22778c mov r0, r3
 *   @0x227790 add r3, r3, r3, lsr #31
 *   @0x227794 ldr r9, [sp, #0x50]
 *   @0x227798 bic r1, r0, r0, asr #31
 *   @0x22779c ldr r5, [r4, #0x8]
 *   @0x2277a0 add r2, r12, r12, lsr #31
 *   @0x2277a4 ldr r0, [sp, #0x14]
 *   @0x2277a8 ldr r12, [sp, #0x68]
 *   @0x2277ac lsl r8, r1, #2
 *   @0x2277b0 asr r2, r2, #1
 *   @0x2277b4 str r1, [sp, #0x40]
 *   @0x2277b8 add r6, r2, r3, asr #1
 *   @0x2277bc str r6, [sp, #0x4c]
 *   @0x2277c0 sub r3, r2, r3, asr #1
 *   @0x2277c4 rsb r10, r1, r6
 *   @0x2277c8 add r2, r9, r3
 *   @0x2277cc ldr r6, [sp, #0x18]
 *   @0x2277d0 lsl r3, r3, #2
 *   @0x2277d4 str r3, [sp, #0x60]
 *   @0x2277d8 ldr r3, [sp, #0x24]
 *   @0x2277dc lsl r1, r9, #2
 *   @0x2277e0 lsl r2, r2, #2
 *   @0x2277e4 str r5, [sp, #0x20]
 *   @0x2277e8 str r2, [sp, #0x54]
 *   @0x2277ec mov r5, #0
 *   @0x2277f0 lsl r10, r10, #2
 *   @0x2277f4 lsl r2, r0, #2
 *   @0x2277f8 lsl r9, r3, #2
 *   @0x2277fc str r1, [sp, #0x28]
 *   @0x227800 str r4, [sp, #0x6c]
 *   @0x227804 lsl r1, r6, #2
 *   @0x227808 mov r4, r7
 *   @0x22780c mov r6, r5
 *   @0x227810 lsl r12, r12, #2
 *   @0x227814 str r8, [sp, #0x3c]
 *   @0x227818 str r12, [sp, #0x1c]
 *   @0x22781c ldr r8, [sp, #0xc]
 *   @0x227820 cmp r8, #0
 *   @0x227824 beq 0x227a84 <vorbis_synthesis_blockin+0x44c>
 *   @0x227828 ldr r12, [sp, #0x8]
 *   @0x22782c cmp r12, #0
 *   @0x227830 beq 0x227b64 <vorbis_synthesis_blockin+0x52c>
 *   @0x227834 ldr r3, [sp, #0x20]
 *   @0x227838 ldr r0, [sp, #0x24]
 *   @0x22783c ldr r12, [sp, #0x10]
 *   @0x227840 ldr r8, [r3, r5]
 *   @0x227844 cmp r0, #0
 *   @0x227848 ldr r3, [sp, #0x28]
 *   @0x22784c ldr r11, [r12, r5]
 *   @0x227850 add r0, r8, r3
 *   @0x227854 ble 0x227878 <vorbis_synthesis_blockin+0x240>
 *   @0x227858 mov r3, #0
 *   @0x22785c ldr r7, [r0, r3]
 *   @0x227860 ldr r12, [r11, r3]
 *   @0x227864 add r12, r7, r12
 *   @0x227868 str r12, [r0, r3]
 *   @0x22786c add r3, r3, #4
 *   @0x227870 cmp r3, r9
 *   @0x227874 bne 0x22785c <vorbis_synthesis_blockin+0x224>
 *   @0x227878 ldr r12, [sp, #0x14]
 *   @0x22787c add r11, r11, r2
 *   @0x227880 ldr r0, [sp, #0x1c]
 *   @0x227884 cmp r12, #0
 *   @0x227888 add r8, r8, r0
 *   @0x22788c movgt r3, #0
 *   @0x227890 ble 0x2278a8 <vorbis_synthesis_blockin+0x270>
 *   @0x227894 ldr r0, [r11, r3]
 *   @0x227898 str r0, [r8, r3]
 *   @0x22789c add r3, r3, #4
 *   @0x2278a0 cmp r3, r2
 *   @0x2278a4 bne 0x227894 <vorbis_synthesis_blockin+0x25c>
 *   @0x2278a8 ldr r3, [r4, #0x4]
 *   @0x2278ac add r6, r6, #1
 *   @0x2278b0 add r5, r5, #4
 *   @0x2278b4 cmp r3, r6
 *   @0x2278b8 bgt 0x22781c <vorbis_synthesis_blockin+0x1e4>
 *   @0x2278bc ldr r4, [sp, #0x6c]
 *   @0x2278c0 ldr r12, [r4, #0x18]
 *   @0x2278c4 ldr r1, [sp, #0x64]
 *   @0x2278c8 cmp r1, #0
 *   @0x2278cc ldreq r2, [sp, #0x24]
 *   @0x2278d0 movne r3, #0
 *   @0x2278d4 strne r3, [r4, #0x30]
 *   @0x2278d8 streq r2, [r4, #0x30]
 *   @0x2278dc cmn r12, #1
 *   @0x2278e0 beq 0x227be0 <vorbis_synthesis_blockin+0x5a8>
 *   @0x2278e4 ldr r5, [sp, #0xc]
 *   @0x2278e8 ldr r6, [sp, #0x2c]
 *   @0x2278ec ldr r8, [sp, #0x44]
 *   @0x2278f0 ldr r9, [sp, #0x50]
 *   @0x2278f4 ldr r3, [r6, r5, lsl #2]
 *   @0x2278f8 cmp r8, #0
 *   @0x2278fc add r2, r8, #3
 *   @0x227900 add r1, r3, #3
 *   @0x227904 movge r2, r8
 *   @0x227908 cmp r3, #0
 *   @0x22790c str r9, [r4, #0x18]
 *   @0x227910 movlt r3, r1
 *   @0x227914 add r3, r9, r3, asr #2
 *   @0x227918 add r2, r3, r2, asr #2
 *   @0x22791c str r2, [r4, #0x14]
 *   @0x227920 ldrd r0, r1, [sp, #88]
 *   @0x227924 mvn r2, #0
 *   @0x227928 mvn r3, #0
 *   @0x22792c cmp r1, r3
 *   @0x227930 cmpeq r0, r2
 *   @0x227934 beq 0x227bcc <vorbis_synthesis_blockin+0x594>
 *   @0x227938 ldr r3, [sp, #0x8]
 *   @0x22793c ldr r5, [sp, #0x2c]
 *   @0x227940 ldr r6, [sp, #0xc]
 *   @0x227944 ldr r8, [sp, #0x48]
 *   @0x227948 ldr r2, [r5, r3, lsl #2]
 *   @0x22794c ldr r3, [r5, r6, lsl #2]
 *   @0x227950 add r1, r2, #3
 *   @0x227954 cmp r2, #0
 *   @0x227958 movlt r2, r1
 *   @0x22795c add r1, r3, #3
 *   @0x227960 cmp r3, #0
 *   @0x227964 asr r2, r2, #2
 *   @0x227968 movlt r3, r1
 *   @0x22796c add r1, r2, r3, asr #2
 *   @0x227970 ldrd r2, r3, [sp, #88]
 *   @0x227974 adds r2, r2, r1
 *   @0x227978 adc r3, r3, r1, asr #31
 *   @0x22797c strd r2, r3, [r8, #16]
 *   @0x227980 ldrd r0, r1, [sp, #48]
 *   @0x227984 mvn r2, #0
 *   @0x227988 mvn r3, #0
 *   @0x22798c cmp r1, r3
 *   @0x227990 cmpeq r0, r2
 *   @0x227994 beq 0x227a44 <vorbis_synthesis_blockin+0x40c>
 *   @0x227998 ldr r6, [sp, #0x2c]
 *   @0x22799c ldr r5, [sp, #0x8]
 *   @0x2279a0 ldr r8, [sp, #0xc]
 *   @0x2279a4 ldr r9, [sp, #0x38]
 *   @0x2279a8 ldr r0, [r6, r5, lsl #2]
 *   @0x2279ac ldr r1, [r6, r8, lsl #2]
 *   @0x2279b0 add r12, r0, #3
 *   @0x2279b4 cmp r0, #0
 *   @0x2279b8 ldrd r6, r7, [r9, #48]
 *   @0x2279bc movlt r0, r12
 *   @0x2279c0 add r12, r1, #3
 *   @0x2279c4 cmp r1, #0
 *   @0x2279c8 asr r0, r0, #2
 *   @0x2279cc movlt r1, r12
 *   @0x2279d0 add r12, r0, r1, asr #2
 *   @0x2279d4 ldrd r0, r1, [sp, #48]
 *   @0x2279d8 adds r0, r0, r12
 *   @0x2279dc adc r1, r1, r12, asr #31
 *   @0x2279e0 cmp r7, r3
 *   @0x2279e4 cmpeq r6, r2
 *   @0x2279e8 strd r0, r1, [r4, #56]
 *   @0x2279ec beq 0x227a5c <vorbis_synthesis_blockin+0x424>
 *   @0x2279f0 cmp r1, r7
 *   @0x2279f4 cmpeq r0, r6
 *   @0x2279f8 beq 0x227a5c <vorbis_synthesis_blockin+0x424>
 *   @0x2279fc cmp r6, r0
 *   @0x227a00 sbcs r12, r7, r1
 *   @0x227a04 bge 0x227bac <vorbis_synthesis_blockin+0x574>
 *   @0x227a08 subs r2, r0, r6
 *   @0x227a0c beq 0x227bac <vorbis_synthesis_blockin+0x574>
 *   @0x227a10 ldr r3, [sp, #0x38]
 *   @0x227a14 ldr r0, [r3, #0x2c]
 *   @0x227a18 cmp r0, #0
 *   @0x227a1c beq 0x227bb4 <vorbis_synthesis_blockin+0x57c>
 *   @0x227a20 ldr r3, [r4, #0x14]
 *   @0x227a24 ldr r1, [r4, #0x18]
 *   @0x227a28 rsb r1, r1, r3
 *   @0x227a2c cmp r2, r1
 *   @0x227a30 movge r2, r1
 *   @0x227a34 bic r2, r2, r2, asr #31
 *   @0x227a38 rsb r3, r2, r3
 *   @0x227a3c str r3, [r4, #0x14]
 *   @0x227a40 b 0x227bb4 <vorbis_synthesis_blockin+0x57c>
 *   @0x227a44 ldr r1, [sp, #0x38]
 *   @0x227a48 ldrd r8, r9, [sp, #48]
 *   @0x227a4c ldrd r2, r3, [r1, #48]
 *   @0x227a50 cmp r3, r9
 *   @0x227a54 cmpeq r2, r8
 *   @0x227a58 bne 0x227bf0 <vorbis_synthesis_blockin+0x5b8>
 *   @0x227a5c ldr r9, [sp, #0x38]
 *   @0x227a60 ldr r0, [r9, #0x2c]
 *   @0x227a64 cmp r0, #0
 *   @0x227a68 beq 0x227a78 <vorbis_synthesis_blockin+0x440>
 *   @0x227a6c mov r0, #0
 *   @0x227a70 mov r3, #1
 *   @0x227a74 str r3, [r4, #0x20]
 *   @0x227a78 add sp, sp, #112
 *   @0x227a7c pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x227a80 bx lr
 *   @0x227a84 ldr r8, [sp, #0x8]
 *   @0x227a88 cmp r8, #0
 *   @0x227a8c beq 0x227b1c <vorbis_synthesis_blockin+0x4e4>
 *   @0x227a90 ldr r0, [sp, #0x20]
 *   @0x227a94 ldr r3, [sp, #0x10]
 *   @0x227a98 ldr r12, [sp, #0x18]
 *   @0x227a9c ldr r8, [r0, r5]
 *   @0x227aa0 ldr r11, [r3, r5]
 *   @0x227aa4 cmp r12, #0
 *   @0x227aa8 ldr r3, [sp, #0x60]
 *   @0x227aac ldr r12, [sp, #0x28]
 *   @0x227ab0 add r7, r11, r3
 *   @0x227ab4 add r0, r8, r12
 *   @0x227ab8 ble 0x227ae4 <vorbis_synthesis_blockin+0x4ac>
 *   @0x227abc ldr r3, [sp, #0xc]
 *   @0x227ac0 str r2, [sp, #0x4]
 *   @0x227ac4 ldr r12, [r0, r3]
 *   @0x227ac8 ldr r2, [r7, r3]
 *   @0x227acc add r12, r12, r2
 *   @0x227ad0 str r12, [r0, r3]
 *   @0x227ad4 add r3, r3, #4
 *   @0x227ad8 cmp r1, r3
 *   @0x227adc bne 0x227ac4 <vorbis_synthesis_blockin+0x48c>
 *   @0x227ae0 ldr r2, [sp, #0x4]
 *   @0x227ae4 ldr r3, [sp, #0x40]
 *   @0x227ae8 ldr r12, [sp, #0x4c]
 *   @0x227aec cmp r3, r12
 *   @0x227af0 bge 0x227878 <vorbis_synthesis_blockin+0x240>
 *   @0x227af4 ldr r3, [sp, #0x3c]
 *   @0x227af8 add r7, r7, r3
 *   @0x227afc add r0, r0, r3
 *   @0x227b00 mov r3, #0
 *   @0x227b04 ldr r12, [r7, r3]
 *   @0x227b08 str r12, [r0, r3]
 *   @0x227b0c add r3, r3, #4
 *   @0x227b10 cmp r3, r10
 *   @0x227b14 bne 0x227b04 <vorbis_synthesis_blockin+0x4cc>
 *   @0x227b18 b 0x227878 <vorbis_synthesis_blockin+0x240>
 *   @0x227b1c ldr r12, [sp, #0x20]
 *   @0x227b20 ldr r8, [sp, #0x18]
 *   @0x227b24 ldr r0, [sp, #0x10]
 *   @0x227b28 cmp r8, #0
 *   @0x227b2c ldr r3, [sp, #0x28]
 *   @0x227b30 ldr r8, [r12, r5]
 *   @0x227b34 ldr r11, [r0, r5]
 *   @0x227b38 add r0, r8, r3
 *   @0x227b3c ble 0x227878 <vorbis_synthesis_blockin+0x240>
 *   @0x227b40 ldr r3, [sp, #0x8]
 *   @0x227b44 ldr r7, [r0, r3]
 *   @0x227b48 ldr r12, [r11, r3]
 *   @0x227b4c add r12, r7, r12
 *   @0x227b50 str r12, [r0, r3]
 *   @0x227b54 add r3, r3, #4
 *   @0x227b58 cmp r1, r3
 *   @0x227b5c bne 0x227b44 <vorbis_synthesis_blockin+0x50c>
 *   @0x227b60 b 0x227878 <vorbis_synthesis_blockin+0x240>
 *   @0x227b64 ldr r12, [sp, #0x20]
 *   @0x227b68 ldr r8, [sp, #0x18]
 *   @0x227b6c ldr r0, [sp, #0x10]
 *   @0x227b70 cmp r8, #0
 *   @0x227b74 ldr r3, [sp, #0x54]
 *   @0x227b78 ldr r8, [r12, r5]
 *   @0x227b7c ldr r11, [r0, r5]
 *   @0x227b80 add r0, r8, r3
 *   @0x227b84 ble 0x227878 <vorbis_synthesis_blockin+0x240>
 *   @0x227b88 ldr r3, [sp, #0x8]
 *   @0x227b8c ldr r7, [r0, r3]
 *   @0x227b90 ldr r12, [r11, r3]
 *   @0x227b94 add r12, r7, r12
 *   @0x227b98 str r12, [r0, r3]
 *   @0x227b9c add r3, r3, #4
 *   @0x227ba0 cmp r3, r1
 *   @0x227ba4 bne 0x227b8c <vorbis_synthesis_blockin+0x554>
 *   @0x227ba8 b 0x227878 <vorbis_synthesis_blockin+0x240>
 *   @0x227bac ldr r1, [sp, #0x38]
 *   @0x227bb0 ldr r0, [r1, #0x2c]
 *   @0x227bb4 strd r6, r7, [r4, #56]
 *   @0x227bb8 b 0x227a64 <vorbis_synthesis_blockin+0x42c>
 *   @0x227bbc ldr r9, [sp, #0x38]
 *   @0x227bc0 ldr r2, [r9, #0x38]
 *   @0x227bc4 ldr r0, [r9, #0x3c]
 *   @0x227bc8 b 0x2276d8 <vorbis_synthesis_blockin+0xa0>
 *   @0x227bcc ldr r1, [sp, #0x48]
 *   @0x227bd0 mov r2, #0
 *   @0x227bd4 mov r3, #0
 *   @0x227bd8 strd r2, r3, [r1, #16]
 *   @0x227bdc b 0x227980 <vorbis_synthesis_blockin+0x348>
 *   @0x227be0 ldr r3, [sp, #0x68]
 *   @0x227be4 str r3, [r4, #0x18]
 *   @0x227be8 str r3, [r4, #0x14]
 *   @0x227bec b 0x227920 <vorbis_synthesis_blockin+0x2e8>
 *   @0x227bf0 ldr r12, [sp, #0x48]
 *   @0x227bf4 ldrd r6, r7, [r12, #16]
 *   @0x227bf8 strd r2, r3, [r4, #56]
 *   @0x227bfc cmp r2, r6
 *   @0x227c00 sbcs r0, r3, r7
 *   @0x227c04 bge 0x227a5c <vorbis_synthesis_blockin+0x424>
 *   @0x227c08 ldr r1, [sp, #0x38]
 *   @0x227c0c rsb r2, r2, r6
 *   @0x227c10 bic r2, r2, r2, asr #31
 *   @0x227c14 ldr r0, [r1, #0x2c]
 *   @0x227c18 cmp r0, #0
 *   @0x227c1c beq 0x227c64 <vorbis_synthesis_blockin+0x62c>
 *   @0x227c20 ldr r3, [r4, #0x14]
 *   @0x227c24 ldr r1, [r4, #0x18]
 *   @0x227c28 rsb r1, r1, r3
 *   @0x227c2c cmp r2, r1
 *   @0x227c30 movge r2, r1
 *   @0x227c34 rsb r3, r2, r3
 *   @0x227c38 str r3, [r4, #0x14]
 *   @0x227c3c b 0x227a6c <vorbis_synthesis_blockin+0x434>
 *   @0x227c40 ldr r9, [sp, #0x48]
 *   @0x227c44 ldrd r0, r1, [r4, #56]
 *   @0x227c48 ldrd r8, r9, [r9, #16]
 *   @0x227c4c strd r0, r1, [sp, #48]
 *   @0x227c50 mov r0, r3
 *   @0x227c54 strd r8, r9, [sp, #88]
 *   @0x227c58 b 0x227700 <vorbis_synthesis_blockin+0xc8>
 *   @0x227c5c mvn r0, #130
 *   @0x227c60 b 0x227a78 <vorbis_synthesis_blockin+0x440>
 *   @0x227c64 ldr r1, [r4, #0x18]
 *   @0x227c68 ldr r3, [r4, #0x14]
 *   @0x227c6c add r2, r2, r1
 *   @0x227c70 str r2, [r4, #0x18]
 *   @0x227c74 cmp r2, r3
 *   @0x227c78 strgt r3, [r4, #0x18]
 *   @0x227c7c b 0x227a78 <vorbis_synthesis_blockin+0x440>
 *
 * ══ §14/19 b2ContactSolver::SolveVelocityConstraints  0x2e28f4  size 1524  381 条（0x2e28f4..0x2e2ee8）
 * @func 0x2e28f4 0x2e2ee8  size 1524  381 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ContactSolver::SolveVelocityConstraints()+0x3e4×2 / b2ContactSolver::SolveVelocityConstraints()+0x4f8×2 / b2ContactSolver::SolveVelocityConstraints()+0x580×2 / b2ContactSolver::SolveVelocityConstraints()+0x374×2 / b2ContactSolver::SolveVelocityConstraints()+0x3d4 / b2ContactSolver::SolveVelocityConstraints()+0x1d8
 * 字段偏移 top8: 0x10×4 / 0x8×4 / 0x4×4 / 0x28×3 / 0x1c×3 / 0x20×3 / 0x24×3 / 0x14×2
 * VFP 指令 261 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e28f4 ldr r3, [r0, #0x30]
 *   @0x2e28f8 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2e28fc vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e2900 cmp r3, #0
 *   @0x2e2904 sub sp, sp, #48
 *   @0x2e2908 ble 0x2e2cc8 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x3d4>
 *   @0x2e290c mov r2, #156
 *   @0x2e2910 ldr r7, [r0, #0x28]
 *   @0x2e2914 mul r2, r2, r3
 *   @0x2e2918 ldr r0, [r0, #0x1c]
 *   @0x2e291c add r1, r7, #8
 *   @0x2e2920 add r3, r7, #80
 *   @0x2e2924 str r1, [sp, #0x10]
 *   @0x2e2928 add r1, r7, #60
 *   @0x2e292c str r3, [sp, #0x20]
 *   @0x2e2930 add r3, r7, #36
 *   @0x2e2934 str r1, [sp, #0x8]
 *   @0x2e2938 add r1, r7, #12
 *   @0x2e293c str r2, [sp, #0x14]
 *   @0x2e2940 add r2, r7, #96
 *   @0x2e2944 str r2, [sp, #0x24]
 *   @0x2e2948 add r8, r7, #16
 *   @0x2e294c str r3, [sp, #0x2c]
 *   @0x2e2950 add r9, r7, #52
 *   @0x2e2954 str r1, [sp, #0x18]
 *   @0x2e2958 add r11, r7, #68
 *   @0x2e295c ldr r3, [sp, #0x24]
 *   @0x2e2960 mov r4, #0
 *   @0x2e2964 ldr r1, [sp, #0x20]
 *   @0x2e2968 add r2, r7, #44
 *   @0x2e296c ldr r10, [sp, #0x10]
 *   @0x2e2970 str r0, [sp, #0xc]
 *   @0x2e2974 mov r0, r7
 *   @0x2e2978 str r2, [sp, #0x28]
 *   @0x2e297c add r2, r7, #28
 *   @0x2e2980 str r3, [sp, #0x4]
 *   @0x2e2984 str r2, [sp, #0x1c]
 *   @0x2e2988 str r1, [sp]
 *   @0x2e298c ldr r6, [r0, #0x70]
 *   @0x2e2990 add r3, r7, r4
 *   @0x2e2994 ldr r5, [r0, #0x74]
 *   @0x2e2998 vldr s4, [r3, #72]
 *   @0x2e299c ldr r12, [r0, #0x94]
 *   @0x2e29a0 vneg.f32 s21, s4
 *   @0x2e29a4 ldr r2, [sp, #0xc]
 *   @0x2e29a8 add r6, r6, r6, lsl #1
 *   @0x2e29ac add r5, r5, r5, lsl #1
 *   @0x2e29b0 cmp r12, #0
 *   @0x2e29b4 add r6, r2, r6, lsl #2
 *   @0x2e29b8 vldr s9, [r3, #76]
 *   @0x2e29bc add r5, r2, r5, lsl #2
 *   @0x2e29c0 vldr s7, [r0, #120]
 *   @0x2e29c4 vldr s10, [r6]
 *   @0x2e29c8 vldr s11, [r6, #4]
 *   @0x2e29cc vldr s14, [r6, #8]
 *   @0x2e29d0 vldr s5, [r0, #128]
 *   @0x2e29d4 vldr s12, [r5]
 *   @0x2e29d8 vldr s13, [r5, #4]
 *   @0x2e29dc vldr s15, [r5, #8]
 *   @0x2e29e0 vldr s8, [r0, #124]
 *   @0x2e29e4 vldr s6, [r0, #132]
 *   @0x2e29e8 vldr s22, [r0, #136]
 *   @0x2e29ec ble 0x2e2acc <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x1d8>
 *   @0x2e29f0 ldr r1, [sp, #0x1c]
 *   @0x2e29f4 vldr s23, [r0, #144]
 *   @0x2e29f8 add r3, r1, r4
 *   @0x2e29fc ldr r1, [sp, #0x18]
 *   @0x2e2a00 add r2, r1, r4
 *   @0x2e2a04 mov r1, #0
 *   @0x2e2a08 vmov.f32 s16, s13
 *   @0x2e2a0c vldr s19, [r2, #-4]
 *   @0x2e2a10 vldr s0, [r2]
 *   @0x2e2a14 vldr s18, [r3, #-28]
 *   @0x2e2a18 vldr s1, [r3, #-24]
 *   @0x2e2a1c vldr s20, [r3, #-8]
 *   @0x2e2a20 vldr s3, [r3]
 *   @0x2e2a24 vldr s2, [r3, #-12]
 *   @0x2e2a28 vmla.f32 s16, s15, s19
 *   @0x2e2a2c add r1, r1, #1
 *   @0x2e2a30 add r2, r2, #36
 *   @0x2e2a34 add r3, r3, #36
 *   @0x2e2a38 vmov.f32 s17, s12
 *   @0x2e2a3c vmls.f32 s17, s15, s0
 *   @0x2e2a40 vsub.f32 s16, s16, s11
 *   @0x2e2a44 vmls.f32 s16, s14, s18
 *   @0x2e2a48 vsub.f32 s17, s17, s10
 *   @0x2e2a4c vmla.f32 s17, s14, s1
 *   @0x2e2a50 vmul.f32 s16, s21, s16
 *   @0x2e2a54 vmla.f32 s16, s17, s9
 *   @0x2e2a58 vsub.f32 s16, s16, s23
 *   @0x2e2a5c vmov.f32 s17, s20
 *   @0x2e2a60 vmls.f32 s17, s16, s3
 *   @0x2e2a64 vmul.f32 s2, s22, s2
 *   @0x2e2a68 vcmpe.f32 s2, s17
 *   @0x2e2a6c vneg.f32 s3, s2
 *   @0x2e2a70 vmrs APSR_nzcv, fpscr
 *   @0x2e2a74 vmovgt.f32 s2, s17
 *   @0x2e2a78 vcmpe.f32 s3, s2
 *   @0x2e2a7c vmrs APSR_nzcv, fpscr
 *   @0x2e2a80 vmovle.f32 s3, s2
 *   @0x2e2a84 vstr s3, [r3, #-44]
 *   @0x2e2a88 cmp r1, r12
 *   @0x2e2a8c vsub.f32 s3, s3, s20
 *   @0x2e2a90 vmul.f32 s2, s3, s9
 *   @0x2e2a94 vmul.f32 s3, s3, s21
 *   @0x2e2a98 vmul.f32 s0, s0, s2
 *   @0x2e2a9c vmul.f32 s1, s1, s2
 *   @0x2e2aa0 vnmls.f32 s0, s19, s3
 *   @0x2e2aa4 vnmls.f32 s1, s18, s3
 *   @0x2e2aa8 vmla.f32 s15, s6, s0
 *   @0x2e2aac vmls.f32 s14, s5, s1
 *   @0x2e2ab0 vmls.f32 s10, s7, s2
 *   @0x2e2ab4 vmls.f32 s11, s7, s3
 *   @0x2e2ab8 vmla.f32 s12, s8, s2
 *   @0x2e2abc vmla.f32 s13, s8, s3
 *   @0x2e2ac0 bne 0x2e2a08 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x114>
 *   @0x2e2ac4 cmp r1, #1
 *   @0x2e2ac8 beq 0x2e2d3c <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x448>
 *   @0x2e2acc vmov.f32 s0, s13
 *   @0x2e2ad0 ldr r1, [sp, #0x28]
 *   @0x2e2ad4 vldr s21, [r0]
 *   @0x2e2ad8 vldr s25, [r0, #4]
 *   @0x2e2adc add r3, r1, r4
 *   @0x2e2ae0 vldr s18, [r3]
 *   @0x2e2ae4 ldr r1, [sp, #0x2c]
 *   @0x2e2ae8 vldr s22, [r3, #4]
 *   @0x2e2aec vmla.f32 s0, s15, s18
 *   @0x2e2af0 rsb r3, r7, r10
 *   @0x2e2af4 add r2, r1, r4
 *   @0x2e2af8 ldr r1, [sp, #0x10]
 *   @0x2e2afc vldr s19, [r2]
 *   @0x2e2b00 vldr s23, [r2, #4]
 *   @0x2e2b04 add r3, r3, r1
 *   @0x2e2b08 vldr s20, [r3, #-8]
 *   @0x2e2b0c vldr s24, [r3, #-4]
 *   @0x2e2b10 ldr r2, [sp, #0x4]
 *   @0x2e2b14 ldr r1, [sp, #0x24]
 *   @0x2e2b18 vldr s16, [r9]
 *   @0x2e2b1c rsb r3, r7, r2
 *   @0x2e2b20 vldr s17, [r8]
 *   @0x2e2b24 add r3, r3, r1
 *   @0x2e2b28 vldr s1, [r3, #-84]
 *   @0x2e2b2c vldr s26, [r3, #-92]
 *   @0x2e2b30 vldr s27, [r3, #-88]
 *   @0x2e2b34 vldr s29, [r3, #-96]
 *   @0x2e2b38 ldr r2, [sp]
 *   @0x2e2b3c ldr r1, [sp, #0x20]
 *   @0x2e2b40 rsb r3, r7, r2
 *   @0x2e2b44 add r3, r3, r1
 *   @0x2e2b48 vmov.f32 s2, s13
 *   @0x2e2b4c vneg.f32 s3, s15
 *   @0x2e2b50 vmov.f32 s28, s12
 *   @0x2e2b54 vmla.f32 s2, s15, s20
 *   @0x2e2b58 vmla.f32 s28, s3, s22
 *   @0x2e2b5c vmov.f32 s30, s12
 *   @0x2e2b60 vsub.f32 s0, s0, s11
 *   @0x2e2b64 vmla.f32 s30, s3, s24
 *   @0x2e2b68 vmls.f32 s0, s14, s19
 *   @0x2e2b6c vsub.f32 s2, s2, s11
 *   @0x2e2b70 vsub.f32 s28, s28, s10
 *   @0x2e2b74 vneg.f32 s31, s14
 *   @0x2e2b78 vmls.f32 s2, s14, s21
 *   @0x2e2b7c vmls.f32 s28, s31, s23
 *   @0x2e2b80 vsub.f32 s3, s30, s10
 *   @0x2e2b84 vldr s30, [r11]
 *   @0x2e2b88 vmul.f32 s0, s0, s9
 *   @0x2e2b8c vmls.f32 s3, s31, s25
 *   @0x2e2b90 vldr s31, [r3, #-80]
 *   @0x2e2b94 vmul.f32 s1, s16, s1
 *   @0x2e2b98 vmul.f32 s2, s2, s9
 *   @0x2e2b9c vmla.f32 s0, s28, s4
 *   @0x2e2ba0 vldr s28, [r3, #-72]
 *   @0x2e2ba4 vmla.f32 s1, s17, s26
 *   @0x2e2ba8 vmla.f32 s2, s3, s4
 *   @0x2e2bac vmul.f32 s3, s16, s27
 *   @0x2e2bb0 vsub.f32 s0, s0, s30
 *   @0x2e2bb4 vldr s30, [r0, #32]
 *   @0x2e2bb8 vmla.f32 s3, s17, s29
 *   @0x2e2bbc vldr s29, [r3, #-76]
 *   @0x2e2bc0 vsub.f32 s0, s0, s1
 *   @0x2e2bc4 vldr s1, [r3, #-68]
 *   @0x2e2bc8 vsub.f32 s2, s2, s30
 *   @0x2e2bcc vmul.f32 s28, s0, s28
 *   @0x2e2bd0 vsub.f32 s2, s2, s3
 *   @0x2e2bd4 vmla.f32 s28, s2, s31
 *   @0x2e2bd8 vneg.f32 s28, s28
 *   @0x2e2bdc vcmpe.f32 s28, #0
 *   @0x2e2be0 vmrs APSR_nzcv, fpscr
 *   @0x2e2be4 blt 0x2e2cd8 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x3e4>
 *   @0x2e2be8 vmul.f32 s1, s0, s1
 *   @0x2e2bec vmla.f32 s1, s2, s29
 *   @0x2e2bf0 vneg.f32 s1, s1
 *   @0x2e2bf4 vcmpe.f32 s1, #0
 *   @0x2e2bf8 vmrs APSR_nzcv, fpscr
 *   @0x2e2bfc blt 0x2e2cd8 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x3e4>
 *   @0x2e2c00 vsub.f32 s17, s28, s17
 *   @0x2e2c04 vstr s28, [r8]
 *   @0x2e2c08 vstr s1, [r9]
 *   @0x2e2c0c vsub.f32 s1, s1, s16
 *   @0x2e2c10 vmul.f32 s3, s17, s4
 *   @0x2e2c14 vmul.f32 s4, s1, s4
 *   @0x2e2c18 vmul.f32 s17, s17, s9
 *   @0x2e2c1c vmul.f32 s25, s25, s3
 *   @0x2e2c20 vmul.f32 s24, s24, s3
 *   @0x2e2c24 vmul.f32 s23, s23, s4
 *   @0x2e2c28 vmul.f32 s22, s22, s4
 *   @0x2e2c2c vmul.f32 s9, s1, s9
 *   @0x2e2c30 vnmls.f32 s23, s19, s9
 *   @0x2e2c34 vnmls.f32 s22, s18, s9
 *   @0x2e2c38 vnmls.f32 s25, s21, s17
 *   @0x2e2c3c vnmls.f32 s24, s20, s17
 *   @0x2e2c40 vadd.f32 s23, s25, s23
 *   @0x2e2c44 vadd.f32 s22, s24, s22
 *   @0x2e2c48 vadd.f32 s4, s3, s4
 *   @0x2e2c4c vadd.f32 s9, s17, s9
 *   @0x2e2c50 vmls.f32 s14, s23, s5
 *   @0x2e2c54 vmla.f32 s15, s22, s6
 *   @0x2e2c58 vmls.f32 s10, s7, s4
 *   @0x2e2c5c vmla.f32 s12, s8, s4
 *   @0x2e2c60 vmls.f32 s11, s7, s9
 *   @0x2e2c64 vmla.f32 s13, s8, s9
 *   @0x2e2c68 ldr r1, [sp, #0x14]
 *   @0x2e2c6c add r4, r4, #156
 *   @0x2e2c70 ldr r2, [sp, #0x8]
 *   @0x2e2c74 vstr s10, [r6]
 *   @0x2e2c78 ldr r3, [sp, #0x4]
 *   @0x2e2c7c cmp r4, r1
 *   @0x2e2c80 ldr r1, [sp]
 *   @0x2e2c84 vstr s11, [r6, #4]
 *   @0x2e2c88 vstr s14, [r6, #8]
 *   @0x2e2c8c add r2, r2, #156
 *   @0x2e2c90 add r3, r3, #156
 *   @0x2e2c94 add r1, r1, #156
 *   @0x2e2c98 add r0, r0, #156
 *   @0x2e2c9c vstr s12, [r5]
 *   @0x2e2ca0 vstr s13, [r5, #4]
 *   @0x2e2ca4 vstr s15, [r5, #8]
 *   @0x2e2ca8 add r8, r8, #156
 *   @0x2e2cac add r9, r9, #156
 *   @0x2e2cb0 str r2, [sp, #0x8]
 *   @0x2e2cb4 add r10, r10, #156
 *   @0x2e2cb8 add r11, r11, #156
 *   @0x2e2cbc str r3, [sp, #0x4]
 *   @0x2e2cc0 str r1, [sp]
 *   @0x2e2cc4 bne 0x2e298c <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x98>
 *   @0x2e2cc8 add sp, sp, #48
 *   @0x2e2ccc vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e2cd0 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2e2cd4 bx lr
 *   @0x2e2cd8 vldr s3, [r0, #24]
 *   @0x2e2cdc vnmul.f32 s3, s3, s2
 *   @0x2e2ce0 vcmpe.f32 s3, #0
 *   @0x2e2ce4 vmrs APSR_nzcv, fpscr
 *   @0x2e2ce8 blt 0x2e2dec <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x4f8>
 *   @0x2e2cec vmov.f32 s1, s0
 *   @0x2e2cf0 vmla.f32 s1, s3, s26
 *   @0x2e2cf4 vcmpe.f32 s1, #0
 *   @0x2e2cf8 vmrs APSR_nzcv, fpscr
 *   @0x2e2cfc blt 0x2e2dec <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x4f8>
 *   @0x2e2d00 mov r1, #0
 *   @0x2e2d04 vsub.f32 s17, s3, s17
 *   @0x2e2d08 vmov s0, r1
 *   @0x2e2d0c vstr s3, [r8]
 *   @0x2e2d10 str r1, [r9]
 *   @0x2e2d14 vsub.f32 s16, s0, s16
 *   @0x2e2d18 vmul.f32 s3, s17, s4
 *   @0x2e2d1c vmul.f32 s4, s16, s4
 *   @0x2e2d20 vmul.f32 s17, s17, s9
 *   @0x2e2d24 vmul.f32 s25, s25, s3
 *   @0x2e2d28 vmul.f32 s24, s24, s3
 *   @0x2e2d2c vmul.f32 s23, s23, s4
 *   @0x2e2d30 vmul.f32 s22, s22, s4
 *   @0x2e2d34 vmul.f32 s9, s16, s9
 *   @0x2e2d38 b 0x2e2c30 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x33c>
 *   @0x2e2d3c vmov.f32 s1, s13
 *   @0x2e2d40 ldr r1, [sp, #0x10]
 *   @0x2e2d44 rsb r3, r7, r10
 *   @0x2e2d48 vldr s16, [r0]
 *   @0x2e2d4c add r3, r3, r1
 *   @0x2e2d50 vldr s17, [r3, #-8]
 *   @0x2e2d54 vldr s2, [r3, #-4]
 *   @0x2e2d58 vldr s3, [r0, #4]
 *   @0x2e2d5c vmla.f32 s1, s15, s17
 *   @0x2e2d60 vldr s20, [r0, #32]
 *   @0x2e2d64 vldr s18, [r8]
 *   @0x2e2d68 vldr s19, [r0, #24]
 *   @0x2e2d6c mov r1, #0
 *   @0x2e2d70 vmov.f32 s0, s12
 *   @0x2e2d74 vmls.f32 s0, s15, s2
 *   @0x2e2d78 vsub.f32 s1, s1, s11
 *   @0x2e2d7c vmls.f32 s1, s14, s16
 *   @0x2e2d80 vsub.f32 s0, s0, s10
 *   @0x2e2d84 vmla.f32 s0, s14, s3
 *   @0x2e2d88 vmul.f32 s1, s1, s9
 *   @0x2e2d8c vmla.f32 s1, s0, s4
 *   @0x2e2d90 vsub.f32 s1, s1, s20
 *   @0x2e2d94 vmov.f32 s0, s18
 *   @0x2e2d98 vmls.f32 s0, s19, s1
 *   @0x2e2d9c vmov.f32 s1, s0
 *   @0x2e2da0 vcmpe.f32 s0, #0
 *   @0x2e2da4 vmov s0, r1
 *   @0x2e2da8 vmrs APSR_nzcv, fpscr
 *   @0x2e2dac vmovle.f32 s1, s0
 *   @0x2e2db0 vstr s1, [r8]
 *   @0x2e2db4 vsub.f32 s1, s1, s18
 *   @0x2e2db8 vmul.f32 s4, s1, s4
 *   @0x2e2dbc vmul.f32 s9, s1, s9
 *   @0x2e2dc0 vmul.f32 s2, s2, s4
 *   @0x2e2dc4 vmul.f32 s3, s3, s4
 *   @0x2e2dc8 vnmls.f32 s2, s17, s9
 *   @0x2e2dcc vnmls.f32 s3, s16, s9
 *   @0x2e2dd0 vmla.f32 s15, s6, s2
 *   @0x2e2dd4 vmls.f32 s14, s5, s3
 *   @0x2e2dd8 vmls.f32 s10, s7, s4
 *   @0x2e2ddc vmls.f32 s11, s7, s9
 *   @0x2e2de0 vmla.f32 s12, s8, s4
 *   @0x2e2de4 vmla.f32 s13, s8, s9
 *   @0x2e2de8 b 0x2e2c68 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x374>
 *   @0x2e2dec ldr r2, [sp, #0x8]
 *   @0x2e2df0 vldr s3, [r2]
 *   @0x2e2df4 vnmul.f32 s3, s3, s0
 *   @0x2e2df8 vcmpe.f32 s3, #0
 *   @0x2e2dfc vmrs APSR_nzcv, fpscr
 *   @0x2e2e00 blt 0x2e2e74 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x580>
 *   @0x2e2e04 vmov.f32 s1, s2
 *   @0x2e2e08 vmla.f32 s1, s3, s27
 *   @0x2e2e0c vcmpe.f32 s1, #0
 *   @0x2e2e10 vmrs APSR_nzcv, fpscr
 *   @0x2e2e14 blt 0x2e2e74 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x580>
 *   @0x2e2e18 mov r3, #0
 *   @0x2e2e1c str r3, [r8]
 *   @0x2e2e20 vmov s0, r3
 *   @0x2e2e24 vstr s3, [r9]
 *   @0x2e2e28 vsub.f32 s3, s3, s16
 *   @0x2e2e2c vsub.f32 s2, s0, s17
 *   @0x2e2e30 vmul.f32 s1, s2, s4
 *   @0x2e2e34 vmul.f32 s4, s3, s4
 *   @0x2e2e38 vmul.f32 s2, s2, s9
 *   @0x2e2e3c vmul.f32 s23, s23, s4
 *   @0x2e2e40 vmul.f32 s9, s3, s9
 *   @0x2e2e44 vmul.f32 s22, s22, s4
 *   @0x2e2e48 vmul.f32 s25, s25, s1
 *   @0x2e2e4c vmul.f32 s24, s24, s1
 *   @0x2e2e50 vnmls.f32 s23, s19, s9
 *   @0x2e2e54 vnmls.f32 s22, s18, s9
 *   @0x2e2e58 vnmls.f32 s25, s21, s2
 *   @0x2e2e5c vnmls.f32 s24, s20, s2
 *   @0x2e2e60 vadd.f32 s23, s25, s23
 *   @0x2e2e64 vadd.f32 s22, s24, s22
 *   @0x2e2e68 vadd.f32 s4, s1, s4
 *   @0x2e2e6c vadd.f32 s9, s2, s9
 *   @0x2e2e70 b 0x2e2c50 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x35c>
 *   @0x2e2e74 vcmpe.f32 s2, #0
 *   @0x2e2e78 vmrs APSR_nzcv, fpscr
 *   @0x2e2e7c blt 0x2e2c68 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x374>
 *   @0x2e2e80 vcmpe.f32 s0, #0
 *   @0x2e2e84 vmrs APSR_nzcv, fpscr
 *   @0x2e2e88 blt 0x2e2c68 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x374>
 *   @0x2e2e8c mov r2, #0
 *   @0x2e2e90 str r2, [r8]
 *   @0x2e2e94 vmov s0, r2
 *   @0x2e2e98 str r2, [r9]
 *   @0x2e2e9c vsub.f32 s3, s0, s17
 *   @0x2e2ea0 vsub.f32 s16, s0, s16
 *   @0x2e2ea4 vmul.f32 s2, s3, s4
 *   @0x2e2ea8 vmul.f32 s4, s16, s4
 *   @0x2e2eac vmul.f32 s3, s3, s9
 *   @0x2e2eb0 vmul.f32 s23, s23, s4
 *   @0x2e2eb4 vmul.f32 s9, s16, s9
 *   @0x2e2eb8 vmul.f32 s22, s22, s4
 *   @0x2e2ebc vmul.f32 s25, s25, s2
 *   @0x2e2ec0 vmul.f32 s24, s24, s2
 *   @0x2e2ec4 vnmls.f32 s23, s19, s9
 *   @0x2e2ec8 vnmls.f32 s22, s18, s9
 *   @0x2e2ecc vnmls.f32 s25, s21, s3
 *   @0x2e2ed0 vnmls.f32 s24, s20, s3
 *   @0x2e2ed4 vadd.f32 s23, s25, s23
 *   @0x2e2ed8 vadd.f32 s22, s24, s22
 *   @0x2e2edc vadd.f32 s4, s2, s4
 *   @0x2e2ee0 vadd.f32 s9, s3, s9
 *   @0x2e2ee4 b 0x2e2c50 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x35c>
 *
 * ══ §15/19 b2TimeOfImpact  0x2e0930  size 1492  373 条（0x2e0930..0x2e0f04）
 * @func 0x2e0930 0x2e0f04  size 1492  373 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6910×2 / 0xb6580×2 / 0xb658c×2 / b2SeparationFunction::Evaluate(int, int, float) const×2 / b2Timer::b2Timer() / b2Distance(b2DistanceOutput*, b2SimplexCache*, b2DistanceInput const*) / b2TimeOfImpact(b2TOIOutput*, b2TOIInput const*)+0x5c0 / b2SeparationFunction::Initialize(b2SimplexCache const*, b2DistanceProxy const*, b2Sweep const&, b2DistanceProxy const*, b2Sweep const&, float)
 * 字段偏移 top8: 0x30×10 / 0x24×7 / 0x1c×6 / 0x28×4 / 0x4×4 / 0x3c×3 / 0x10×3 / 0x-158×2
 * VFP 指令 154 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e0930 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e0934 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2e0938 sub sp, sp, #396
 *   @0x2e093c vldr s16, [pc, #920]
 *   @0x2e0940 add r4, sp, #84
 *   @0x2e0944 add r6, sp, #128
 *   @0x2e0948 str r0, [sp, #0x30]
 *   @0x2e094c mov r7, #0
 *   @0x2e0950 mov r0, r4
 *   @0x2e0954 str r4, [sp, #0x44]
 *   @0x2e0958 str r1, [sp, #0x24]
 *   @0x2e095c add r4, sp, #128
 *   @0x2e0960 str r6, [sp, #0x34]
 *   @0x2e0964 bl 0x2e10b8 <_ZN7b2TimerC2Ev>
 *   @0x2e0968 ldr r6, [sp, #0x24]
 *   @0x2e096c vmov.f32 s26, #1.000000e+00
 *   @0x2e0970 ldr r12, [sp, #0x24]
 *   @0x2e0974 vldr s21, [pc, #868]
 *   @0x2e0978 ldr r11, [pc, #0x370]
 *   @0x2e097c vldr s24, [pc, #864]
 *   @0x2e0980 ldr r6, [r6, #0x80]
 *   @0x2e0984 add r5, r12, #56
 *   @0x2e0988 ldr r12, [pc, #0x364]
 *   @0x2e098c add r11, pc, r11
 *   @0x2e0990 ldm r5!, {r0, r1, r2, r3}
 *   @0x2e0994 vldr s22, [pc, #844]
 *   @0x2e0998 str r6, [sp, #0x28]
 *   @0x2e099c ldr r6, [sp, #0x24]
 *   @0x2e09a0 ldr r8, [r11, r12]
 *   @0x2e09a4 add r12, sp, #164
 *   @0x2e09a8 add lr, r6, #92
 *   @0x2e09ac str r12, [sp, #0x38]
 *   @0x2e09b0 ldr r6, [sp, #0x28]
 *   @0x2e09b4 ldr r12, [sp, #0x30]
 *   @0x2e09b8 stm r4!, {r0, r1, r2, r3}
 *   @0x2e09bc str r6, [r12, #0x4]
 *   @0x2e09c0 add r6, sp, #200
 *   @0x2e09c4 str r6, [sp, #0x2c]
 *   @0x2e09c8 add r12, sp, #164
 *   @0x2e09cc ldr r6, [r8]
 *   @0x2e09d0 ldm r5!, {r0, r1, r2, r3}
 *   @0x2e09d4 add r6, r6, #1
 *   @0x2e09d8 str r6, [r8]
 *   @0x2e09dc ldr r6, [sp, #0x24]
 *   @0x2e09e0 add r6, r6, #28
 *   @0x2e09e4 str r6, [sp, #0x3c]
 *   @0x2e09e8 ldr r6, [sp, #0x30]
 *   @0x2e09ec stm r4!, {r0, r1, r2, r3}
 *   @0x2e09f0 ldr r5, [r5]
 *   @0x2e09f4 ldm lr!, {r0, r1, r2, r3}
 *   @0x2e09f8 str r7, [r6]
 *   @0x2e09fc vldr s19, [sp, #152]
 *   @0x2e0a00 vdiv.f32 s11, s19, s16
 *   @0x2e0a04 str r5, [r4]
 *   @0x2e0a08 add r6, sp, #104
 *   @0x2e0a0c add r4, sp, #92
 *   @0x2e0a10 stm r12!, {r0, r1, r2, r3}
 *   @0x2e0a14 add r5, sp, #200
 *   @0x2e0a18 ldm lr!, {r0, r1, r2, r3}
 *   @0x2e0a1c str r6, [sp, #0x40]
 *   @0x2e0a20 add r6, sp, #76
 *   @0x2e0a24 str r4, [sp, #0x20]
 *   @0x2e0a28 add r4, sp, #292
 *   @0x2e0a2c stm r12!, {r0, r1, r2, r3}
 *   @0x2e0a30 ldr r3, [lr]
 *   @0x2e0a34 str r3, [r12]
 *   @0x2e0a38 vmov r0, s11
 *   @0x2e0a3c bl 0xb6910 <floorf@plt>
 *   @0x2e0a40 vldr s17, [sp, #188]
 *   @0x2e0a44 vdiv.f32 s14, s17, s16
 *   @0x2e0a48 vldr s18, [sp, #156]
 *   @0x2e0a4c str r6, [sp, #0x18]
 *   @0x2e0a50 str r7, [sp, #0x1c]
 *   @0x2e0a54 vmov s11, r0
 *   @0x2e0a58 vmul.f32 s15, s11, s16
 *   @0x2e0a5c vmov r0, s14
 *   @0x2e0a60 vsub.f32 s19, s19, s15
 *   @0x2e0a64 vsub.f32 s18, s18, s15
 *   @0x2e0a68 vstr s19, [sp, #152]
 *   @0x2e0a6c vstr s18, [sp, #156]
 *   @0x2e0a70 bl 0xb6910 <floorf@plt>
 *   @0x2e0a74 ldr r6, [sp, #0x24]
 *   @0x2e0a78 vldr s11, [r6, #24]
 *   @0x2e0a7c vldr s13, [r6, #52]
 *   @0x2e0a80 vadd.f32 s13, s11, s13
 *   @0x2e0a84 add lr, sp, #392
 *   @0x2e0a88 movw r3, #0xfed8
 *   @0x2e0a8c movt r3, #0xffff
 *   @0x2e0a90 mov r12, r6
 *   @0x2e0a94 vldr s15, [pc, #592]
 *   @0x2e0a98 vldr s14, [sp, #192]
 *   @0x2e0a9c strh r7, [lr, r3]
 *   @0x2e0aa0 ldr lr, [sp, #0x3c]
 *   @0x2e0aa4 vsub.f32 s15, s13, s15
 *   @0x2e0aa8 vcmpe.f32 s15, s21
 *   @0x2e0aac vmov.f32 s12, s19
 *   @0x2e0ab0 vmrs APSR_nzcv, fpscr
 *   @0x2e0ab4 vmovpl.f32 s21, s15
 *   @0x2e0ab8 vmov s11, r0
 *   @0x2e0abc ldm r12!, {r0, r1, r2, r3}
 *   @0x2e0ac0 vmul.f32 s16, s11, s16
 *   @0x2e0ac4 stm r5!, {r0, r1, r2, r3}
 *   @0x2e0ac8 ldm r12, {r0, r1, r2}
 *   @0x2e0acc add r12, sp, #228
 *   @0x2e0ad0 stm r5, {r0, r1, r2}
 *   @0x2e0ad4 vsub.f32 s13, s17, s16
 *   @0x2e0ad8 ldm lr!, {r0, r1, r2, r3}
 *   @0x2e0adc vsub.f32 s14, s14, s16
 *   @0x2e0ae0 vstr s13, [sp, #188]
 *   @0x2e0ae4 stm r12!, {r0, r1, r2, r3}
 *   @0x2e0ae8 ldm lr, {r0, r1, r2}
 *   @0x2e0aec strb r7, [sp, #0x120]
 *   @0x2e0af0 stm r12, {r0, r1, r2}
 *   @0x2e0af4 vmov.f32 s17, s14
 *   @0x2e0af8 vstr s14, [sp, #192]
 *   @0x2e0afc vldr s23, [sp, #144]
 *   @0x2e0b00 vldr s20, [sp, #148]
 *   @0x2e0b04 vldr s14, [sp, #136]
 *   @0x2e0b08 vldr s15, [sp, #140]
 *   @0x2e0b0c vmul.f32 s18, s24, s18
 *   @0x2e0b10 vsub.f32 s16, s26, s24
 *   @0x2e0b14 vmla.f32 s18, s16, s12
 *   @0x2e0b18 vmul.f32 s17, s24, s17
 *   @0x2e0b1c vmov r0, s18
 *   @0x2e0b20 vmul.f32 s23, s24, s23
 *   @0x2e0b24 vmul.f32 s20, s24, s20
 *   @0x2e0b28 vmla.f32 s17, s16, s13
 *   @0x2e0b2c vmla.f32 s23, s16, s14
 *   @0x2e0b30 vmla.f32 s20, s16, s15
 *   @0x2e0b34 bl 0xb6580 <sinf@plt>
 *   @0x2e0b38 vmov s25, r0
 *   @0x2e0b3c vmov r0, s18
 *   @0x2e0b40 bl 0xb658c <cosf@plt>
 *   @0x2e0b44 vldr s19, [sp, #180]
 *   @0x2e0b48 vldr s18, [sp, #184]
 *   @0x2e0b4c vmul.f32 s19, s24, s19
 *   @0x2e0b50 vldr s14, [sp, #172]
 *   @0x2e0b54 vldr s15, [sp, #176]
 *   @0x2e0b58 vldr s29, [sp, #132]
 *   @0x2e0b5c vldr s28, [sp, #128]
 *   @0x2e0b60 vmul.f32 s18, s24, s18
 *   @0x2e0b64 vmla.f32 s19, s16, s14
 *   @0x2e0b68 vmov s27, r0
 *   @0x2e0b6c vmov r0, s17
 *   @0x2e0b70 vmla.f32 s18, s16, s15
 *   @0x2e0b74 bl 0xb6580 <sinf@plt>
 *   @0x2e0b78 vmov s16, r0
 *   @0x2e0b7c vmov r0, s17
 *   @0x2e0b80 bl 0xb658c <cosf@plt>
 *   @0x2e0b84 vldr s15, [sp, #168]
 *   @0x2e0b88 vmul.f32 s12, s29, s25
 *   @0x2e0b8c vldr s10, [sp, #164]
 *   @0x2e0b90 add r1, sp, #92
 *   @0x2e0b94 add r2, sp, #200
 *   @0x2e0b98 vstr s25, [sp, #264]
 *   @0x2e0b9c vstr s27, [sp, #268]
 *   @0x2e0ba0 vstr s16, [sp, #280]
 *   @0x2e0ba4 vmul.f32 s14, s15, s16
 *   @0x2e0ba8 vmul.f32 s13, s29, s27
 *   @0x2e0bac vmov s11, r0
 *   @0x2e0bb0 add r0, sp, #104
 *   @0x2e0bb4 vstr s11, [sp, #284]
 *   @0x2e0bb8 vmul.f32 s15, s15, s11
 *   @0x2e0bbc vnmls.f32 s14, s10, s11
 *   @0x2e0bc0 vmla.f32 s15, s10, s16
 *   @0x2e0bc4 vnmls.f32 s12, s28, s27
 *   @0x2e0bc8 vmla.f32 s13, s28, s25
 *   @0x2e0bcc vsub.f32 s15, s18, s15
 *   @0x2e0bd0 vsub.f32 s12, s23, s12
 *   @0x2e0bd4 vstr s15, [sp, #276]
 *   @0x2e0bd8 vsub.f32 s13, s20, s13
 *   @0x2e0bdc vstr s12, [sp, #256]
 *   @0x2e0be0 vsub.f32 s14, s19, s14
 *   @0x2e0be4 vstr s13, [sp, #260]
 *   @0x2e0be8 vstr s14, [sp, #272]
 *   @0x2e0bec bl 0x2c3fa0 <_Z10b2DistanceP16b2DistanceOutputP14b2SimplexCachePK15b2DistanceInput>
 *   @0x2e0bf0 vldr s15, [sp, #120]
 *   @0x2e0bf4 vcmpe.f32 s15, #0
 *   @0x2e0bf8 mov r3, #0
 *   @0x2e0bfc vmrs APSR_nzcv, fpscr
 *   @0x2e0c00 bls 0x2e0ef0 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x5c0>
 *   @0x2e0c04 vadd.f32 s25, s21, s22
 *   @0x2e0c08 vcmpe.f32 s15, s25
 *   @0x2e0c0c vmrs APSR_nzcv, fpscr
 *   @0x2e0c10 bmi 0x2e0edc <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x5ac>
 *   @0x2e0c14 vmov.f32 s23, #5.000000e-01
 *   @0x2e0c18 ldr r12, [sp, #0x3c]
 *   @0x2e0c1c add lr, sp, #164
 *   @0x2e0c20 vstr s24, [sp, #8]
 *   @0x2e0c24 str lr, [sp, #0x4]
 *   @0x2e0c28 mov r0, r4
 *   @0x2e0c2c str r12, [sp]
 *   @0x2e0c30 add r1, sp, #92
 *   @0x2e0c34 ldr r2, [sp, #0x24]
 *   @0x2e0c38 add r3, sp, #128
 *   @0x2e0c3c bl 0x2dfcf4 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f>
 *   @0x2e0c40 ldr r10, [sp, #0x28]
 *   @0x2e0c44 add r6, sp, #80
 *   @0x2e0c48 mov r12, #8
 *   @0x2e0c4c str r6, [sp, #0x14]
 *   @0x2e0c50 str r12, [sp, #0x10]
 *   @0x2e0c54 mov r0, r4
 *   @0x2e0c58 add r1, sp, #76
 *   @0x2e0c5c add r2, sp, #80
 *   @0x2e0c60 mov r3, r10
 *   @0x2e0c64 bl 0x2e01c8 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f>
 *   @0x2e0c68 vmov s20, r0
 *   @0x2e0c6c vcmpe.f32 s25, s20
 *   @0x2e0c70 vmrs APSR_nzcv, fpscr
 *   @0x2e0c74 bmi 0x2e0e00 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x4d0>
 *   @0x2e0c78 vsub.f32 s16, s21, s22
 *   @0x2e0c7c vcmpe.f32 s20, s16
 *   @0x2e0c80 vmrs APSR_nzcv, fpscr
 *   @0x2e0c84 bgt 0x2e0e98 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x568>
 *   @0x2e0c88 ldr r5, [sp, #0x4c]
 *   @0x2e0c8c mov r0, r4
 *   @0x2e0c90 ldr r6, [sp, #0x50]
 *   @0x2e0c94 vmov r3, s24
 *   @0x2e0c98 mov r1, r5
 *   @0x2e0c9c mov r2, r6
 *   @0x2e0ca0 bl 0x2e0694 <_ZNK20b2SeparationFunction8EvaluateEiif>
 *   @0x2e0ca4 vmov s18, r0
 *   @0x2e0ca8 vcmpe.f32 s16, s18
 *   @0x2e0cac vmrs APSR_nzcv, fpscr
 *   @0x2e0cb0 bgt 0x2e0eb4 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x584>
 *   @0x2e0cb4 vcmpe.f32 s25, s18
 *   @0x2e0cb8 vmrs APSR_nzcv, fpscr
 *   @0x2e0cbc bge 0x2e0ea0 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x570>
 *   @0x2e0cc0 ldr r3, [pc, #0x30]
 *   @0x2e0cc4 vmov s19, r10
 *   @0x2e0cc8 vmov.f32 s17, s24
 *   @0x2e0ccc mov r9, #0
 *   @0x2e0cd0 ldr r7, [r11, r3]
 *   @0x2e0cd4 ldr r8, [r7]
 *   @0x2e0cd8 b 0x2e0d30 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x400>
 *   @0x2e0cdc ldrdmi r0, r1, [r9], #251
 *   @0x2e0ce0 bllo 0xfebd6910 <b2_toiTime+0xfffffffffe47d46c>
 *   @0x2e0ce4 andeq r0, r0, r0
 *   @0x2e0ce8 blo 0xfebd6918 <b2_toiTime+0xfffffffffe47d474>
 *   @0x2e0cec ldcllo p2, c12, [r5], #-572
 *   @0x2e0cf0 andseq r1, r1, r4, asr #5
 *   @0x2e0cf4 .word 0xffffff34
 *   @0x2e0cf8 .word 0xffffff38
 *   @0x2e0cfc .word 0xffffff3c
 *   @0x2e0d00 .word 0xffffff40
 *   @0x2e0d04 .word 0xffffff44
 *   @0x2e0d08 .word 0xffffff48
 *   @0x2e0d0c .word 0xffffff4c
 *   @0x2e0d10 vcmpe.f32 s15, s21
 *   @0x2e0d14 vmrs APSR_nzcv, fpscr
 *   @0x2e0d18 vmovle.f32 s20, s15
 *   @0x2e0d1c vmovgt.f32 s18, s15
 *   @0x2e0d20 vmovle.f32 s19, s16
 *   @0x2e0d24 vmovgt.f32 s17, s16
 *   @0x2e0d28 cmp r9, #50
 *   @0x2e0d2c beq 0x2e0d9c <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x46c>
 *   @0x2e0d30 tst r9, #1
 *   @0x2e0d34 add r9, r9, #1
 *   @0x2e0d38 add r3, r9, r8
 *   @0x2e0d3c mov r0, r4
 *   @0x2e0d40 vsubne.f32 s16, s21, s18
 *   @0x2e0d44 str r3, [r7]
 *   @0x2e0d48 mov r1, r5
 *   @0x2e0d4c mov r2, r6
 *   @0x2e0d50 vsubne.f32 s15, s19, s17
 *   @0x2e0d54 vmulne.f32 s16, s16, s15
 *   @0x2e0d58 vsubne.f32 s15, s20, s18
 *   @0x2e0d5c vdivne.f32 s16, s16, s15
 *   @0x2e0d60 vaddeq.f32 s16, s17, s19
 *   @0x2e0d64 vmuleq.f32 s16, s16, s23
 *   @0x2e0d68 vaddne.f32 s16, s16, s17
 *   @0x2e0d6c vmov r3, s16
 *   @0x2e0d70 bl 0x2e0694 <_ZNK20b2SeparationFunction8EvaluateEiif>
 *   @0x2e0d74 vmov s15, r0
 *   @0x2e0d78 vsub.f32 s14, s15, s21
 *   @0x2e0d7c vcmpe.f32 s14, #0
 *   @0x2e0d80 vmov.f32 s13, s14
 *   @0x2e0d84 vmrs APSR_nzcv, fpscr
 *   @0x2e0d88 vnegle.f32 s13, s14
 *   @0x2e0d8c vcmpe.f32 s13, s22
 *   @0x2e0d90 vmrs APSR_nzcv, fpscr
 *   @0x2e0d94 bpl 0x2e0d10 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x3e0>
 *   @0x2e0d98 vmov r10, s16
 *   @0x2e0d9c ldr r3, [pc, #-0xa8]
 *   @0x2e0da0 ldr r6, [sp, #0x10]
 *   @0x2e0da4 ldr r3, [r11, r3]
 *   @0x2e0da8 ldr r2, [r3]
 *   @0x2e0dac cmp r9, r2
 *   @0x2e0db0 strge r9, [r3]
 *   @0x2e0db4 strlt r2, [r3]
 *   @0x2e0db8 subs r6, r6, #1
 *   @0x2e0dbc str r6, [sp, #0x10]
 *   @0x2e0dc0 bne 0x2e0c54 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x324>
 *   @0x2e0dc4 ldr r12, [sp, #0x1c]
 *   @0x2e0dc8 ldr r3, [pc, #-0xd0]
 *   @0x2e0dcc add r12, r12, #1
 *   @0x2e0dd0 str r12, [sp, #0x1c]
 *   @0x2e0dd4 cmp r12, #20
 *   @0x2e0dd8 ldr r3, [r11, r3]
 *   @0x2e0ddc ldr r2, [r3]
 *   @0x2e0de0 add r2, r2, #1
 *   @0x2e0de4 str r2, [r3]
 *   @0x2e0de8 beq 0x2e0ec8 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x598>
 *   @0x2e0dec vldr s12, [sp, #152]
 *   @0x2e0df0 vldr s18, [sp, #156]
 *   @0x2e0df4 vldr s13, [sp, #188]
 *   @0x2e0df8 vldr s17, [sp, #192]
 *   @0x2e0dfc b 0x2e0afc <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x1cc>
 *   @0x2e0e00 ldr r6, [sp, #0x30]
 *   @0x2e0e04 mov r3, #4
 *   @0x2e0e08 ldr r4, [sp, #0x28]
 *   @0x2e0e0c str r3, [r6]
 *   @0x2e0e10 str r4, [r6, #0x4]
 *   @0x2e0e14 ldr r6, [sp, #0x1c]
 *   @0x2e0e18 ldr r3, [pc, #-0x120]
 *   @0x2e0e1c add r6, r6, #1
 *   @0x2e0e20 str r6, [sp, #0x1c]
 *   @0x2e0e24 ldr r3, [r11, r3]
 *   @0x2e0e28 ldr r2, [r3]
 *   @0x2e0e2c add r2, r2, #1
 *   @0x2e0e30 str r2, [r3]
 *   @0x2e0e34 ldr r3, [pc, #-0x138]
 *   @0x2e0e38 add r0, sp, #84
 *   @0x2e0e3c ldr r4, [sp, #0x1c]
 *   @0x2e0e40 ldr r3, [r11, r3]
 *   @0x2e0e44 ldr r2, [r3]
 *   @0x2e0e48 cmp r4, r2
 *   @0x2e0e4c strge r4, [r3]
 *   @0x2e0e50 strlt r2, [r3]
 *   @0x2e0e54 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv>
 *   @0x2e0e58 ldr r3, [pc, #-0x158]
 *   @0x2e0e5c ldr r2, [pc, #-0x158]
 *   @0x2e0e60 ldr r3, [r11, r3]
 *   @0x2e0e64 vldr s14, [r3]
 *   @0x2e0e68 vmov s15, r0
 *   @0x2e0e6c vcmpe.f32 s15, s14
 *   @0x2e0e70 vmrs APSR_nzcv, fpscr
 *   @0x2e0e74 vmovpl.f32 s14, s15
 *   @0x2e0e78 vstr s14, [r3]
 *   @0x2e0e7c ldr r3, [r11, r2]
 *   @0x2e0e80 vldr s14, [r3]
 *   @0x2e0e84 vadd.f32 s15, s14, s15
 *   @0x2e0e88 vstr s15, [r3]
 *   @0x2e0e8c add sp, sp, #396
 *   @0x2e0e90 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2e0e94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e0e98 vmov s24, r10
 *   @0x2e0e9c b 0x2e0dc4 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x494>
 *   @0x2e0ea0 ldr r4, [sp, #0x30]
 *   @0x2e0ea4 mov r3, #3
 *   @0x2e0ea8 vstr s24, [r4, #4]
 *   @0x2e0eac str r3, [r4]
 *   @0x2e0eb0 b 0x2e0e14 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x4e4>
 *   @0x2e0eb4 ldr r12, [sp, #0x30]
 *   @0x2e0eb8 mov r3, #1
 *   @0x2e0ebc vstr s24, [r12, #4]
 *   @0x2e0ec0 str r3, [r12]
 *   @0x2e0ec4 b 0x2e0e14 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x4e4>
 *   @0x2e0ec8 ldr r12, [sp, #0x30]
 *   @0x2e0ecc mov r3, #1
 *   @0x2e0ed0 vstr s24, [r12, #4]
 *   @0x2e0ed4 str r3, [r12]
 *   @0x2e0ed8 b 0x2e0e34 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x504>
 *   @0x2e0edc ldr r6, [sp, #0x30]
 *   @0x2e0ee0 mov r3, #3
 *   @0x2e0ee4 vstr s24, [r6, #4]
 *   @0x2e0ee8 str r3, [r6]
 *   @0x2e0eec b 0x2e0e34 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x504>
 *   @0x2e0ef0 ldr r4, [sp, #0x30]
 *   @0x2e0ef4 str r3, [r4, #0x4]
 *   @0x2e0ef8 mov r3, #2
 *   @0x2e0efc str r3, [r4]
 *   @0x2e0f00 b 0x2e0e34 <_Z14b2TimeOfImpactP11b2TOIOutputPK10b2TOIInput+0x504>
 *
 * ══ §16/19 Check_LoadGameState  0x1d0ed4  size 1428  357 条（0x1d0ed4..0x1d1468）
 * @func 0x1d0ed4 0x1d1468  size 1428  357 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d0f50→0x48f78c, 0x1d0f68→0x54298c, 0x1d0f8c→0x536f28, 0x1d1060→0x54255c, 0x1d1090→0x542558, 0x1d1094→0x542990, 0x1d116c→0x542958, 0x1d11c0→0x5428e8
 * 调用序列: YYGetInt32(RValue const*, int)×3 / MemoryManager::Free(void const*)×2 / CRoom::~CRoom()×2 / operator delete(void*)×2 / Check_LoadGameState()+0x344×2 / GlobalState_DeSerialise(IBuffer*) / FreeIBuffer(int) / Variable_Global_DeSerialise(IBuffer*)
 * 字段偏移 top8: 0x4×17 / 0xc×16 / 0x8×13 / 0x14×5 / 0x10×4 / 0x3b8×2 / 0x1c×2 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d0ed4 ldr r3, [pc, #0x558]
 *   @0x1d0ed8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d0edc add r3, pc, r3
 *   @0x1d0ee0 ldr r10, [pc, #0x550]
 *   @0x1d0ee4 sub sp, sp, #36
 *   @0x1d0ee8 ldr r5, [r3]
 *   @0x1d0eec add r10, pc, r10
 *   @0x1d0ef0 subs r0, r5, #0
 *   @0x1d0ef4 beq 0x1d0f38 <_Z19Check_LoadGameStatev+0x64>
 *   @0x1d0ef8 mov r9, #0
 *   @0x1d0efc str r9, [r3]
 *   @0x1d0f00 bl 0x1d039c <_Z23GlobalState_DeSerialiseP7IBuffer>
 *   @0x1d0f04 cmp r0, r9
 *   @0x1d0f08 bne 0x1d0f40 <_Z19Check_LoadGameStatev+0x6c>
 *   @0x1d0f0c mov r5, #0
 *   @0x1d0f10 ldr r4, [pc, #0x524]
 *   @0x1d0f14 add r4, pc, r4
 *   @0x1d0f18 ldr r0, [r4, #0x4]
 *   @0x1d0f1c cmn r0, #1
 *   @0x1d0f20 moveq r0, r5
 *   @0x1d0f24 beq 0x1d0f38 <_Z19Check_LoadGameStatev+0x64>
 *   @0x1d0f28 bl 0xc6a88 <_Z11FreeIBufferi>
 *   @0x1d0f2c mov r0, r5
 *   @0x1d0f30 mvn r3, #0
 *   @0x1d0f34 str r3, [r4, #0x4]
 *   @0x1d0f38 add sp, sp, #36
 *   @0x1d0f3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d0f40 mov r0, r5
 *   @0x1d0f44 bl 0x1f4b64 <_Z27Variable_Global_DeSerialiseP7IBuffer>
 *   @0x1d0f48 cmp r0, #0
 *   @0x1d0f4c beq 0x1d0f0c <_Z19Check_LoadGameStatev+0x38>
 *   @0x1d0f50 ldr r3, [pc, #0x4e8]
 *   @0x1d0f54 mov r1, r5
 *   @0x1d0f58 ldr r0, [r10, r3]
 *   @0x1d0f5c bl 0x16f34c <_ZN14CCameraManager11DeSerializeEP7IBuffer>
 *   @0x1d0f60 cmp r0, #0
 *   @0x1d0f64 beq 0x1d0f0c <_Z19Check_LoadGameStatev+0x38>
 *   @0x1d0f68 ldr r3, [pc, #0x4d4]
 *   @0x1d0f6c ldr r3, [r10, r3]
 *   @0x1d0f70 ldr r0, [r3]
 *   @0x1d0f74 str r3, [sp, #0x14]
 *   @0x1d0f78 bl 0x1ab798 <_ZN5CRoom14ClearInstancesEv>
 *   @0x1d0f7c ldr r3, [sp, #0x14]
 *   @0x1d0f80 ldr r0, [r3]
 *   @0x1d0f84 bl 0x1ab9c8 <_ZN5CRoom22ClearDeactiveInstancesEv>
 *   @0x1d0f88 bl 0x19f21c <_Z27Object_ClearAllInstanceInfov>
 *   @0x1d0f8c ldr r3, [pc, #0x4b4]
 *   @0x1d0f90 ldr r4, [r10, r3]
 *   @0x1d0f94 ldr r8, [r4, #0x4]
 *   @0x1d0f98 cmp r8, #0
 *   @0x1d0f9c blt 0x1d1010 <_Z19Check_LoadGameStatev+0x13c>
 *   @0x1d0fa0 lsl r7, r8, #3
 *   @0x1d0fa4 ldr r3, [r4]
 *   @0x1d0fa8 add r2, r3, r7
 *   @0x1d0fac ldr r6, [r3, r7]
 *   @0x1d0fb0 str r9, [r3, r7]
 *   @0x1d0fb4 cmp r6, #0
 *   @0x1d0fb8 str r9, [r2, #0x4]
 *   @0x1d0fbc beq 0x1d1000 <_Z19Check_LoadGameStatev+0x12c>
 *   @0x1d0fc0 ldr r3, [r6, #0xc]
 *   @0x1d0fc4 ldr r11, [r6, #0x4]
 *   @0x1d0fc8 cmp r3, #0
 *   @0x1d0fcc mov r0, r3
 *   @0x1d0fd0 beq 0x1d0fe0 <_Z19Check_LoadGameStatev+0x10c>
 *   @0x1d0fd4 ldr r3, [r3]
 *   @0x1d0fd8 ldr r3, [r3, #0x4]
 *   @0x1d0fdc blx r3
 *   @0x1d0fe0 mov r0, r6
 *   @0x1d0fe4 mov r6, r11
 *   @0x1d0fe8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d0fec ldr r3, [r4, #0x8]
 *   @0x1d0ff0 cmp r11, #0
 *   @0x1d0ff4 sub r3, r3, #1
 *   @0x1d0ff8 str r3, [r4, #0x8]
 *   @0x1d0ffc bne 0x1d0fc0 <_Z19Check_LoadGameStatev+0xec>
 *   @0x1d1000 sub r8, r8, #1
 *   @0x1d1004 sub r7, r7, #8
 *   @0x1d1008 cmn r8, #1
 *   @0x1d100c bne 0x1d0fa4 <_Z19Check_LoadGameStatev+0xd0>
 *   @0x1d1010 ldr r3, [r5]
 *   @0x1d1014 add r8, r5, #44
 *   @0x1d1018 mov r1, #6
 *   @0x1d101c mov r0, r5
 *   @0x1d1020 mov r2, r8
 *   @0x1d1024 ldr r3, [r3, #0xc]
 *   @0x1d1028 blx r3
 *   @0x1d102c mov r1, #0
 *   @0x1d1030 mov r0, r8
 *   @0x1d1034 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1d1038 ldr r3, [r5]
 *   @0x1d103c mov r2, r8
 *   @0x1d1040 mov r1, #6
 *   @0x1d1044 ldr r3, [r3, #0xc]
 *   @0x1d1048 str r0, [sp, #0xc]
 *   @0x1d104c mov r0, r5
 *   @0x1d1050 blx r3
 *   @0x1d1054 mov r1, #0
 *   @0x1d1058 mov r0, r8
 *   @0x1d105c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1d1060 ldr r12, [pc, #0x3e4]
 *   @0x1d1064 ldr r3, [r5]
 *   @0x1d1068 mov r2, r8
 *   @0x1d106c mov r1, #6
 *   @0x1d1070 ldr r12, [r10, r12]
 *   @0x1d1074 ldr r3, [r3, #0xc]
 *   @0x1d1078 str r0, [r12]
 *   @0x1d107c mov r0, r5
 *   @0x1d1080 blx r3
 *   @0x1d1084 mov r0, r8
 *   @0x1d1088 mov r1, #0
 *   @0x1d108c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1d1090 ldr r2, [pc, #0x3b8]
 *   @0x1d1094 ldr r3, [pc, #0x3b8]
 *   @0x1d1098 ldr r2, [r10, r2]
 *   @0x1d109c str r0, [r2]
 *   @0x1d10a0 ldr r11, [r10, r3]
 *   @0x1d10a4 ldr r3, [sp, #0xc]
 *   @0x1d10a8 ldr r2, [r11]
 *   @0x1d10ac cmp r2, r3
 *   @0x1d10b0 str r2, [sp, #0x1c]
 *   @0x1d10b4 beq 0x1d1168 <_Z19Check_LoadGameStatev+0x294>
 *   @0x1d10b8 cmp r3, #0
 *   @0x1d10bc bne 0x1d13e0 <_Z19Check_LoadGameStatev+0x50c>
 *   @0x1d10c0 ldr r3, [r11, #0x4]
 *   @0x1d10c4 cmp r3, #0
 *   @0x1d10c8 beq 0x1d1150 <_Z19Check_LoadGameStatev+0x27c>
 *   @0x1d10cc cmp r2, #0
 *   @0x1d10d0 ble 0x1d1150 <_Z19Check_LoadGameStatev+0x27c>
 *   @0x1d10d4 ldr r6, [sp, #0xc]
 *   @0x1d10d8 mov r1, r6
 *   @0x1d10dc ldr r0, [r3]
 *   @0x1d10e0 movw r2, #0xfeee
 *   @0x1d10e4 movt r2, #0xfeee
 *   @0x1d10e8 movw r12, #0xfeee
 *   @0x1d10ec cmp r0, r2
 *   @0x1d10f0 movt r12, #0xfeee
 *   @0x1d10f4 lsl r9, r6, #2
 *   @0x1d10f8 beq 0x1d1140 <_Z19Check_LoadGameStatev+0x26c>
 *   @0x1d10fc ldr r7, [r3, r6, lsl #2]
 *   @0x1d1100 add r2, r3, r9
 *   @0x1d1104 cmp r7, #0
 *   @0x1d1108 mov r0, r7
 *   @0x1d110c beq 0x1d1140 <_Z19Check_LoadGameStatev+0x26c>
 *   @0x1d1110 ldr r3, [r7]
 *   @0x1d1114 cmp r3, r12
 *   @0x1d1118 beq 0x1d1138 <_Z19Check_LoadGameStatev+0x264>
 *   @0x1d111c str r1, [sp, #0x8]
 *   @0x1d1120 bl 0x1afa00 <_ZN5CRoomD2Ev>
 *   @0x1d1124 mov r0, r7
 *   @0x1d1128 bl 0x27d1d0 <_ZdlPv>
 *   @0x1d112c ldr r2, [r11, #0x4]
 *   @0x1d1130 ldr r1, [sp, #0x8]
 *   @0x1d1134 add r2, r2, r9
 *   @0x1d1138 str r1, [r2]
 *   @0x1d113c ldr r3, [r11, #0x4]
 *   @0x1d1140 ldr r2, [r11]
 *   @0x1d1144 add r6, r6, #1
 *   @0x1d1148 cmp r6, r2
 *   @0x1d114c blt 0x1d10dc <_Z19Check_LoadGameStatev+0x208>
 *   @0x1d1150 mov r0, r3
 *   @0x1d1154 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d1158 mov r3, #0
 *   @0x1d115c str r3, [r11, #0x4]
 *   @0x1d1160 ldr r3, [sp, #0xc]
 *   @0x1d1164 str r3, [r11]
 *   @0x1d1168 ldr r2, [sp, #0xc]
 *   @0x1d116c ldr r3, [pc, #0x2e4]
 *   @0x1d1170 cmp r2, #0
 *   @0x1d1174 ble 0x1d1428 <_Z19Check_LoadGameStatev+0x554>
 *   @0x1d1178 ldr r3, [r10, r3]
 *   @0x1d117c mov r7, #0
 *   @0x1d1180 ldr r6, [sp, #0xc]
 *   @0x1d1184 mvn r9, #0
 *   @0x1d1188 str r4, [sp, #0xc]
 *   @0x1d118c ldr r4, [sp, #0x1c]
 *   @0x1d1190 str r10, [sp, #0x18]
 *   @0x1d1194 mov r10, r7
 *   @0x1d1198 str r3, [sp, #0x10]
 *   @0x1d119c cmp r4, #0
 *   @0x1d11a0 ble 0x1d1218 <_Z19Check_LoadGameStatev+0x344>
 *   @0x1d11a4 ldr r3, [r11]
 *   @0x1d11a8 cmp r3, r10
 *   @0x1d11ac ble 0x1d1218 <_Z19Check_LoadGameStatev+0x344>
 *   @0x1d11b0 ldr r3, [r11, #0x4]
 *   @0x1d11b4 ldr r1, [r3, r7]
 *   @0x1d11b8 cmp r1, #0
 *   @0x1d11bc beq 0x1d1218 <_Z19Check_LoadGameStatev+0x344>
 *   @0x1d11c0 ldr r3, [pc, #0x294]
 *   @0x1d11c4 ldr r2, [sp, #0x18]
 *   @0x1d11c8 ldr r3, [r2, r3]
 *   @0x1d11cc ldrb r3, [r3]
 *   @0x1d11d0 cmp r3, #0
 *   @0x1d11d4 beq 0x1d11f4 <_Z19Check_LoadGameStatev+0x320>
 *   @0x1d11d8 mov r2, r1
 *   @0x1d11dc mov r3, #8
 *   @0x1d11e0 ldr r0, [r2, #0x48]
 *   @0x1d11e4 subs r3, r3, #1
 *   @0x1d11e8 add r2, r2, #4
 *   @0x1d11ec str r9, [r0, #0x40]
 *   @0x1d11f0 bne 0x1d11e0 <_Z19Check_LoadGameStatev+0x30c>
 *   @0x1d11f4 mov r0, r1
 *   @0x1d11f8 str r1, [sp, #0x8]
 *   @0x1d11fc bl 0x1afa00 <_ZN5CRoomD2Ev>
 *   @0x1d1200 ldr r1, [sp, #0x8]
 *   @0x1d1204 mov r0, r1
 *   @0x1d1208 bl 0x27d1d0 <_ZdlPv>
 *   @0x1d120c ldr r3, [r11, #0x4]
 *   @0x1d1210 mov r2, #0
 *   @0x1d1214 str r2, [r3, r7]
 *   @0x1d1218 ldr r3, [r5]
 *   @0x1d121c mov r1, #6
 *   @0x1d1220 mov r2, r8
 *   @0x1d1224 mov r0, r5
 *   @0x1d1228 ldr r3, [r3, #0xc]
 *   @0x1d122c blx r3
 *   @0x1d1230 mov r0, r8
 *   @0x1d1234 mov r1, #0
 *   @0x1d1238 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1d123c cmp r0, #0
 *   @0x1d1240 bne 0x1d1394 <_Z19Check_LoadGameStatev+0x4c0>
 *   @0x1d1244 add r10, r10, #1
 *   @0x1d1248 add r7, r7, #4
 *   @0x1d124c cmp r10, r6
 *   @0x1d1250 bne 0x1d119c <_Z19Check_LoadGameStatev+0x2c8>
 *   @0x1d1254 ldr r4, [sp, #0xc]
 *   @0x1d1258 ldr r2, [sp, #0x10]
 *   @0x1d125c ldr r3, [r2]
 *   @0x1d1260 ldr r2, [r11]
 *   @0x1d1264 cmp r3, r2
 *   @0x1d1268 movge r3, #0
 *   @0x1d126c ldrlt r2, [r11, #0x4]
 *   @0x1d1270 ldrlt r3, [r2, r3, lsl #2]
 *   @0x1d1274 ldr r2, [sp, #0x14]
 *   @0x1d1278 str r3, [r2]
 *   @0x1d127c bl 0x1b29bc <_Z17Draw_Room_SetSizev>
 *   @0x1d1280 ldr r2, [sp, #0x14]
 *   @0x1d1284 ldr r3, [r2]
 *   @0x1d1288 ldr r7, [r3, #0x80]
 *   @0x1d128c cmp r7, #0
 *   @0x1d1290 beq 0x1d1380 <_Z19Check_LoadGameStatev+0x4ac>
 *   @0x1d1294 ldr r8, [pc, #0x1c4]
 *   @0x1d1298 mov r9, #0
 *   @0x1d129c add r8, pc, r8
 *   @0x1d12a0 ldr r6, [r7, #0x78]
 *   @0x1d12a4 ldr r10, [r7, #0x178]
 *   @0x1d12a8 cmp r6, #0
 *   @0x1d12ac blt 0x1d1410 <_Z19Check_LoadGameStatev+0x53c>
 *   @0x1d12b0 ldr r1, [r4, #0x4]
 *   @0x1d12b4 ldr r2, [r4]
 *   @0x1d12b8 and r1, r6, r1
 *   @0x1d12bc ldr r3, [r2, r1, lsl #3]
 *   @0x1d12c0 add r1, r2, r1, lsl #3
 *   @0x1d12c4 cmp r3, #0
 *   @0x1d12c8 beq 0x1d12f4 <_Z19Check_LoadGameStatev+0x420>
 *   @0x1d12cc ldr r0, [r3, #0x8]
 *   @0x1d12d0 cmp r6, r0
 *   @0x1d12d4 bne 0x1d12e8 <_Z19Check_LoadGameStatev+0x414>
 *   @0x1d12d8 b 0x1d136c <_Z19Check_LoadGameStatev+0x498>
 *   @0x1d12dc ldr r2, [r3, #0x8]
 *   @0x1d12e0 cmp r6, r2
 *   @0x1d12e4 beq 0x1d136c <_Z19Check_LoadGameStatev+0x498>
 *   @0x1d12e8 ldr r3, [r3, #0x4]
 *   @0x1d12ec cmp r3, #0
 *   @0x1d12f0 bne 0x1d12dc <_Z19Check_LoadGameStatev+0x408>
 *   @0x1d12f4 mov r11, r1
 *   @0x1d12f8 mov r1, r8
 *   @0x1d12fc movw r2, #0x132
 *   @0x1d1300 mov r3, #1
 *   @0x1d1304 mov r0, #16
 *   @0x1d1308 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d130c ldr r3, [r11]
 *   @0x1d1310 ldr r2, [sp, #0x14]
 *   @0x1d1314 mov r1, r7
 *   @0x1d1318 cmp r3, #0
 *   @0x1d131c ldrne r3, [r11, #0x4]
 *   @0x1d1320 str r6, [r0, #0x8]
 *   @0x1d1324 strne r3, [r0]
 *   @0x1d1328 str r7, [r0, #0xc]
 *   @0x1d132c strne r0, [r3, #0x4]
 *   @0x1d1330 streq r0, [r11, #0x4]
 *   @0x1d1334 streq r0, [r11]
 *   @0x1d1338 streq r3, [r0, #0x4]
 *   @0x1d133c streq r3, [r0]
 *   @0x1d1340 ldr r3, [r4, #0x8]
 *   @0x1d1344 strne r0, [r11, #0x4]
 *   @0x1d1348 strne r9, [r0, #0x4]
 *   @0x1d134c add r3, r3, #1
 *   @0x1d1350 ldr r0, [r2]
 *   @0x1d1354 str r3, [r4, #0x8]
 *   @0x1d1358 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance>
 *   @0x1d135c cmp r10, #0
 *   @0x1d1360 beq 0x1d1380 <_Z19Check_LoadGameStatev+0x4ac>
 *   @0x1d1364 mov r7, r10
 *   @0x1d1368 b 0x1d12a0 <_Z19Check_LoadGameStatev+0x3cc>
 *   @0x1d136c ldr r3, [r3, #0xc]
 *   @0x1d1370 cmp r3, #0
 *   @0x1d1374 beq 0x1d12f4 <_Z19Check_LoadGameStatev+0x420>
 *   @0x1d1378 cmp r10, #0
 *   @0x1d137c bne 0x1d1364 <_Z19Check_LoadGameStatev+0x490>
 *   @0x1d1380 mov r0, r5
 *   @0x1d1384 bl 0x18ca38 <_Z23VirtualKeys_DeSerialiseP7IBuffer>
 *   @0x1d1388 adds r5, r0, #0
 *   @0x1d138c movne r5, #1
 *   @0x1d1390 b 0x1d0f10 <_Z19Check_LoadGameStatev+0x3c>
 *   @0x1d1394 mov r0, #292
 *   @0x1d1398 bl 0x27c524 <_Znwj>
 *   @0x1d139c str r0, [sp, #0x8]
 *   @0x1d13a0 bl 0x1ad2cc <_ZN5CRoomC2Ev>
 *   @0x1d13a4 ldm r11, {r1, r2}
 *   @0x1d13a8 ldr r3, [sp, #0x8]
 *   @0x1d13ac cmp r1, r10
 *   @0x1d13b0 mov r1, r5
 *   @0x1d13b4 str r3, [r2, r7]
 *   @0x1d13b8 movle r0, #0
 *   @0x1d13bc ldrgt r3, [r11, #0x4]
 *   @0x1d13c0 ldrgt r0, [r3, r7]
 *   @0x1d13c4 ldr r3, [sp, #0x10]
 *   @0x1d13c8 ldr r2, [r3]
 *   @0x1d13cc subs r3, r10, r2
 *   @0x1d13d0 rsbs r2, r3, #0
 *   @0x1d13d4 adcs r2, r2, r3
 *   @0x1d13d8 bl 0x1ac33c <_ZN5CRoom11DeSerialiseEP7IBufferb>
 *   @0x1d13dc b 0x1d1244 <_Z19Check_LoadGameStatev+0x370>
 *   @0x1d13e0 ldr r2, [sp, #0xc]
 *   @0x1d13e4 lsls r1, r2, #2
 *   @0x1d13e8 beq 0x1d1420 <_Z19Check_LoadGameStatev+0x54c>
 *   @0x1d13ec ldr r2, [pc, #0x70]
 *   @0x1d13f0 mov r3, #0
 *   @0x1d13f4 ldr r0, [r11, #0x4]
 *   @0x1d13f8 add r2, pc, r2
 *   @0x1d13fc str r3, [sp]
 *   @0x1d1400 mov r3, #135
 *   @0x1d1404 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1d1408 str r0, [r11, #0x4]
 *   @0x1d140c b 0x1d1160 <_Z19Check_LoadGameStatev+0x28c>
 *   @0x1d1410 ldm r4, {r3, r11}
 *   @0x1d1414 and r11, r6, r11
 *   @0x1d1418 add r11, r3, r11, lsl #3
 *   @0x1d141c b 0x1d12f8 <_Z19Check_LoadGameStatev+0x424>
 *   @0x1d1420 ldr r3, [r11, #0x4]
 *   @0x1d1424 b 0x1d1150 <_Z19Check_LoadGameStatev+0x27c>
 *   @0x1d1428 ldr r3, [r10, r3]
 *   @0x1d142c str r3, [sp, #0x10]
 *   @0x1d1430 b 0x1d1258 <_Z19Check_LoadGameStatev+0x384>
 *   @0x1d1434 eorseq r1, r7, r8, ror #21
 *   @0x1d1438 eoreq r0, r2, r4, ror #26
 *   @0x1d143c .word 0x002241fc
 *   @0x1d1440 .word 0xffffc024
 *   @0x1d1444 .word 0xffffbcd8
 *   @0x1d1448 .word 0xffffbff4
 *   @0x1d144c .word 0xffffebbc
 *   @0x1d1450 .word 0xffffebc0
 *   @0x1d1454 .word 0xffffeed8
 *   @0x1d1458 .word 0xffffd784
 *   @0x1d145c .word 0xffffbcd4
 *   @0x1d1460 andseq r11, r7, r0, lsl r10
 *   @0x1d1464 ldrsheq r11, [r7], -r8
 *
 * ══ §17/19 StartShaderBlock  0x18426c  size 1420  355 条（0x18426c..0x1847f8）
 * @func 0x18426c 0x1847f8  size 1420  355 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1842f0→0x3f2934, 0x184310→0x4a23f4, 0x184318→0x4a23a8, 0x184408→0x479b28, 0x1844b8→0x479b28, 0x18451c→0x4a23a8, 0x184520→0x4a23f4, 0x18459c→0x479b28
 * 调用序列: Shader_Get(int)×5 / GetVertexFormat(int) / StartShaderBlock(int)+0x290 / StartShaderBlock(int)+0x1fc / StartShaderBlock(int)+0x1d4 / SetFogUniforms(GLSLShader*) / SetAlphaTestUniforms(GLSLShader*) / SetLightingUniforms(GLSLShader*, int)
 * 字段偏移 top8: 0x4×15 / 0x8×7 / 0x2×7 / 0xc×4 / 0x2c×4 / 0x10×4 / 0x20×4 / 0x24×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18426c ldr r2, [pc, #0x530]
 *   @0x184270 mov r3, r0
 *   @0x184274 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x184278 add r2, pc, r2
 *   @0x18427c ldr r9, [pc, #0x524]
 *   @0x184280 ands r5, r0, #16777216
 *   @0x184284 mov r4, #0
 *   @0x184288 sub sp, sp, #28
 *   @0x18428c add r9, pc, r9
 *   @0x184290 str r4, [r2]
 *   @0x184294 beq 0x1842d8 <_Z16StartShaderBlocki+0x6c>
 *   @0x184298 bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0x18429c ldr r1, [r0, #0x4]
 *   @0x1842a0 str r0, [sp, #0x4]
 *   @0x1842a4 cmp r1, #0
 *   @0x1842a8 ble 0x1844fc <_Z16StartShaderBlocki+0x290>
 *   @0x1842ac ldr r3, [r0, #0x8]
 *   @0x1842b0 add r1, r3, r1, lsl #4
 *   @0x1842b4 ldr r2, [r3, #0x8]
 *   @0x1842b8 sub r2, r2, #1
 *   @0x1842bc cmp r2, #3
 *   @0x1842c0 addls pc, pc, r2, lsl #2
 *   @0x1842c4 b 0x1844f0 <_Z16StartShaderBlocki+0x284>
 *   @0x1842c8 b 0x184514 <_Z16StartShaderBlocki+0x2a8>
 *   @0x1842cc b 0x18450c <_Z16StartShaderBlocki+0x2a0>
 *   @0x1842d0 b 0x184504 <_Z16StartShaderBlocki+0x298>
 *   @0x1842d4 b 0x1844ec <_Z16StartShaderBlocki+0x280>
 *   @0x1842d8 cmp r0, #16
 *   @0x1842dc beq 0x184590 <_Z16StartShaderBlocki+0x324>
 *   @0x1842e0 cmp r3, #24
 *   @0x1842e4 str r5, [sp, #0x4]
 *   @0x1842e8 moveq r4, #7
 *   @0x1842ec movne r4, #15
 *   @0x1842f0 ldr r3, [pc, #0x4b4]
 *   @0x1842f4 ldr r3, [r9, r3]
 *   @0x1842f8 ldr r0, [r3]
 *   @0x1842fc cmn r0, #1
 *   @0x184300 beq 0x18451c <_Z16StartShaderBlocki+0x2b0>
 *   @0x184304 bl 0x187e70 <_Z10Shader_Geti>
 *   @0x184308 subs r7, r0, #0
 *   @0x18430c beq 0x18451c <_Z16StartShaderBlocki+0x2b0>
 *   @0x184310 ldr r2, [pc, #0x498]
 *   @0x184314 mov r10, #0
 *   @0x184318 ldr r3, [pc, #0x494]
 *   @0x18431c mov r11, r10
 *   @0x184320 ldr r8, [r9, r2]
 *   @0x184324 ldr r6, [r9, r3]
 *   @0x184328 ldrb r3, [r8]
 *   @0x18432c cmp r3, #0
 *   @0x184330 bne 0x18455c <_Z16StartShaderBlocki+0x2f0>
 *   @0x184334 ldrb r3, [r6]
 *   @0x184338 cmp r3, #0
 *   @0x18433c bne 0x184570 <_Z16StartShaderBlocki+0x304>
 *   @0x184340 cmp r11, #0
 *   @0x184344 bne 0x184580 <_Z16StartShaderBlocki+0x314>
 *   @0x184348 cmp r5, #0
 *   @0x18434c beq 0x184468 <_Z16StartShaderBlocki+0x1fc>
 *   @0x184350 ldr r11, [r7, #0x30]
 *   @0x184354 cmp r11, #0
 *   @0x184358 ble 0x184468 <_Z16StartShaderBlocki+0x1fc>
 *   @0x18435c ldr r4, [r7, #0x34]
 *   @0x184360 ldr r2, [sp, #0x4]
 *   @0x184364 cmp r4, #0
 *   @0x184368 beq 0x18465c <_Z16StartShaderBlocki+0x3f0>
 *   @0x18436c ldr r3, [sp, #0x4]
 *   @0x184370 mov r6, #0
 *   @0x184374 ldr r2, [r2, #0xc]
 *   @0x184378 ldr r10, [r7, #0x2c]
 *   @0x18437c ldr r3, [r3, #0x8]
 *   @0x184380 str r2, [sp, #0x8]
 *   @0x184384 ldr r2, [pc, #0x42c]
 *   @0x184388 str r3, [sp, #0xc]
 *   @0x18438c add r2, pc, r2
 *   @0x184390 str r9, [sp, #0x14]
 *   @0x184394 str r2, [sp, #0x10]
 *   @0x184398 ldr r0, [r10, r6, lsl #2]
 *   @0x18439c lsl r9, r6, #2
 *   @0x1843a0 cmn r0, #1
 *   @0x1843a4 beq 0x184440 <_Z16StartShaderBlocki+0x1d4>
 *   @0x1843a8 ldr r3, [sp, #0x4]
 *   @0x1843ac ldr r2, [r7, #0x38]
 *   @0x1843b0 ldr r4, [r3, #0x4]
 *   @0x1843b4 ldr r3, [r7, #0x34]
 *   @0x1843b8 cmp r4, #0
 *   @0x1843bc ldr r8, [r2, r6, lsl #2]
 *   @0x1843c0 ldr r5, [r3, r6, lsl #2]
 *   @0x1843c4 ble 0x184440 <_Z16StartShaderBlocki+0x1d4>
 *   @0x1843c8 ldr r3, [sp, #0xc]
 *   @0x1843cc mov r2, #0
 *   @0x1843d0 ldr r1, [sp, #0x8]
 *   @0x1843d4 b 0x1843e4 <_Z16StartShaderBlocki+0x178>
 *   @0x1843d8 cmp r2, r4
 *   @0x1843dc add r1, r1, #16
 *   @0x1843e0 beq 0x184440 <_Z16StartShaderBlocki+0x1d4>
 *   @0x1843e4 ldr r12, [r3, #0x8]
 *   @0x1843e8 add r2, r2, #1
 *   @0x1843ec add r3, r3, #16
 *   @0x1843f0 cmp r12, r5
 *   @0x1843f4 bne 0x1843d8 <_Z16StartShaderBlocki+0x16c>
 *   @0x1843f8 ldr r12, [r1, #0xc]
 *   @0x1843fc cmp r12, r8
 *   @0x184400 bne 0x1843d8 <_Z16StartShaderBlocki+0x16c>
 *   @0x184404 ldr r2, [sp, #0x14]
 *   @0x184408 ldr r3, [pc, #0x3ac]
 *   @0x18440c ldr r3, [r2, r3]
 *   @0x184410 ldr r3, [r3]
 *   @0x184414 blx r3
 *   @0x184418 ldr r2, [sp, #0x10]
 *   @0x18441c ldr r10, [r7, #0x2c]
 *   @0x184420 ldr r0, [sp, #0x10]
 *   @0x184424 ldr r3, [r2]
 *   @0x184428 ldr r11, [r7, #0x30]
 *   @0x18442c ldr r2, [r10, r9]
 *   @0x184430 add r1, r3, #1
 *   @0x184434 add r3, r0, r3, lsl #2
 *   @0x184438 str r1, [r0]
 *   @0x18443c str r2, [r3, #0x4]
 *   @0x184440 add r6, r6, #1
 *   @0x184444 cmp r11, r6
 *   @0x184448 bgt 0x184398 <_Z16StartShaderBlocki+0x12c>
 *   @0x18444c ldr r3, [pc, #0x36c]
 *   @0x184450 mov r0, r7
 *   @0x184454 mov r2, #1
 *   @0x184458 add r3, pc, r3
 *   @0x18445c strb r2, [r3, #0x44]
 *   @0x184460 add sp, sp, #28
 *   @0x184464 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x184468 ldr r0, [r7, #0x1c]
 *   @0x18446c cmn r0, #1
 *   @0x184470 beq 0x18447c <_Z16StartShaderBlocki+0x210>
 *   @0x184474 tst r4, #1
 *   @0x184478 bne 0x18461c <_Z16StartShaderBlocki+0x3b0>
 *   @0x18447c ldr r0, [r7, #0x20]
 *   @0x184480 cmn r0, #1
 *   @0x184484 beq 0x184490 <_Z16StartShaderBlocki+0x224>
 *   @0x184488 tst r4, #8
 *   @0x18448c bne 0x18459c <_Z16StartShaderBlocki+0x330>
 *   @0x184490 ldr r0, [r7, #0x28]
 *   @0x184494 cmn r0, #1
 *   @0x184498 beq 0x1844a4 <_Z16StartShaderBlocki+0x238>
 *   @0x18449c tst r4, #2
 *   @0x1844a0 bne 0x1845dc <_Z16StartShaderBlocki+0x370>
 *   @0x1844a4 ldr r0, [r7, #0x24]
 *   @0x1844a8 cmn r0, #1
 *   @0x1844ac beq 0x18444c <_Z16StartShaderBlocki+0x1e0>
 *   @0x1844b0 tst r4, #4
 *   @0x1844b4 beq 0x18444c <_Z16StartShaderBlocki+0x1e0>
 *   @0x1844b8 ldr r3, [pc, #0x2fc]
 *   @0x1844bc ldr r3, [r9, r3]
 *   @0x1844c0 ldr r3, [r3]
 *   @0x1844c4 blx r3
 *   @0x1844c8 ldr r3, [pc, #0x2f4]
 *   @0x1844cc ldr r1, [r7, #0x24]
 *   @0x1844d0 add r3, pc, r3
 *   @0x1844d4 ldr r2, [r3]
 *   @0x1844d8 add r0, r2, #1
 *   @0x1844dc str r0, [r3]
 *   @0x1844e0 add r3, r3, r2, lsl #2
 *   @0x1844e4 str r1, [r3, #0x4]
 *   @0x1844e8 b 0x18444c <_Z16StartShaderBlocki+0x1e0>
 *   @0x1844ec orr r4, r4, #4
 *   @0x1844f0 add r3, r3, #16
 *   @0x1844f4 cmp r3, r1
 *   @0x1844f8 bne 0x1842b4 <_Z16StartShaderBlocki+0x48>
 *   @0x1844fc mov r5, #1
 *   @0x184500 b 0x1842f0 <_Z16StartShaderBlocki+0x84>
 *   @0x184504 orr r4, r4, #8
 *   @0x184508 b 0x1844f0 <_Z16StartShaderBlocki+0x284>
 *   @0x18450c orr r4, r4, #2
 *   @0x184510 b 0x1844f0 <_Z16StartShaderBlocki+0x284>
 *   @0x184514 orr r4, r4, #1
 *   @0x184518 b 0x1844f0 <_Z16StartShaderBlocki+0x284>
 *   @0x18451c ldr r2, [pc, #0x290]
 *   @0x184520 ldr r3, [pc, #0x288]
 *   @0x184524 ldr r6, [r9, r2]
 *   @0x184528 ldr r8, [r9, r3]
 *   @0x18452c ldrb r3, [r6]
 *   @0x184530 ldrb r2, [r8]
 *   @0x184534 cmp r3, #0
 *   @0x184538 orrne r2, r2, #2
 *   @0x18453c cmp r4, #3
 *   @0x184540 beq 0x184760 <_Z16StartShaderBlocki+0x4f4>
 *   @0x184544 cmp r4, #7
 *   @0x184548 beq 0x1846c4 <_Z16StartShaderBlocki+0x458>
 *   @0x18454c cmp r4, #15
 *   @0x184550 beq 0x184708 <_Z16StartShaderBlocki+0x49c>
 *   @0x184554 mov r0, #0
 *   @0x184558 b 0x184460 <_Z16StartShaderBlocki+0x1f4>
 *   @0x18455c mov r0, r7
 *   @0x184560 bl 0x184064 <_Z14SetFogUniformsP10GLSLShader>
 *   @0x184564 ldrb r3, [r6]
 *   @0x184568 cmp r3, #0
 *   @0x18456c beq 0x184340 <_Z16StartShaderBlocki+0xd4>
 *   @0x184570 mov r0, r7
 *   @0x184574 bl 0x184190 <_Z20SetAlphaTestUniformsP10GLSLShader>
 *   @0x184578 cmp r11, #0
 *   @0x18457c beq 0x184348 <_Z16StartShaderBlocki+0xdc>
 *   @0x184580 mov r1, r10
 *   @0x184584 mov r0, r7
 *   @0x184588 bl 0x183d88 <_Z19SetLightingUniformsP10GLSLShaderi>
 *   @0x18458c b 0x184348 <_Z16StartShaderBlocki+0xdc>
 *   @0x184590 mov r4, #3
 *   @0x184594 str r5, [sp, #0x4]
 *   @0x184598 b 0x1842f0 <_Z16StartShaderBlocki+0x84>
 *   @0x18459c ldr r3, [pc, #0x218]
 *   @0x1845a0 ldr r3, [r9, r3]
 *   @0x1845a4 ldr r3, [r3]
 *   @0x1845a8 blx r3
 *   @0x1845ac ldr r3, [pc, #0x214]
 *   @0x1845b0 ldr r1, [r7, #0x20]
 *   @0x1845b4 add r3, pc, r3
 *   @0x1845b8 ldr r2, [r3]
 *   @0x1845bc add r0, r2, #1
 *   @0x1845c0 str r0, [r3]
 *   @0x1845c4 ldr r0, [r7, #0x28]
 *   @0x1845c8 add r3, r3, r2, lsl #2
 *   @0x1845cc cmn r0, #1
 *   @0x1845d0 str r1, [r3, #0x4]
 *   @0x1845d4 bne 0x18449c <_Z16StartShaderBlocki+0x230>
 *   @0x1845d8 b 0x1844a4 <_Z16StartShaderBlocki+0x238>
 *   @0x1845dc ldr r3, [pc, #0x1d8]
 *   @0x1845e0 ldr r3, [r9, r3]
 *   @0x1845e4 ldr r3, [r3]
 *   @0x1845e8 blx r3
 *   @0x1845ec ldr r3, [pc, #0x1d8]
 *   @0x1845f0 ldr r1, [r7, #0x28]
 *   @0x1845f4 add r3, pc, r3
 *   @0x1845f8 ldr r2, [r3]
 *   @0x1845fc add r0, r2, #1
 *   @0x184600 str r0, [r3]
 *   @0x184604 ldr r0, [r7, #0x24]
 *   @0x184608 add r3, r3, r2, lsl #2
 *   @0x18460c cmn r0, #1
 *   @0x184610 str r1, [r3, #0x4]
 *   @0x184614 bne 0x1844b0 <_Z16StartShaderBlocki+0x244>
 *   @0x184618 b 0x18444c <_Z16StartShaderBlocki+0x1e0>
 *   @0x18461c ldr r3, [pc, #0x198]
 *   @0x184620 ldr r3, [r9, r3]
 *   @0x184624 ldr r3, [r3]
 *   @0x184628 blx r3
 *   @0x18462c ldr r3, [pc, #0x19c]
 *   @0x184630 ldr r1, [r7, #0x1c]
 *   @0x184634 add r3, pc, r3
 *   @0x184638 ldr r2, [r3]
 *   @0x18463c add r0, r2, #1
 *   @0x184640 str r0, [r3]
 *   @0x184644 ldr r0, [r7, #0x20]
 *   @0x184648 add r3, r3, r2, lsl #2
 *   @0x18464c cmn r0, #1
 *   @0x184650 str r1, [r3, #0x4]
 *   @0x184654 bne 0x184488 <_Z16StartShaderBlocki+0x21c>
 *   @0x184658 b 0x184490 <_Z16StartShaderBlocki+0x224>
 *   @0x18465c ldr r6, [r2, #0x4]
 *   @0x184660 cmp r6, r11
 *   @0x184664 movge r6, r11
 *   @0x184668 cmp r6, #0
 *   @0x18466c ble 0x18444c <_Z16StartShaderBlocki+0x1e0>
 *   @0x184670 ldr r5, [pc, #0x15c]
 *   @0x184674 ldr r10, [r7, #0x2c]
 *   @0x184678 add r5, pc, r5
 *   @0x18467c ldr r0, [r10, r4, lsl #2]
 *   @0x184680 ldr r3, [pc, #0x134]
 *   @0x184684 cmn r0, #1
 *   @0x184688 beq 0x1846b4 <_Z16StartShaderBlocki+0x448>
 *   @0x18468c ldr r3, [r9, r3]
 *   @0x184690 ldr r3, [r3]
 *   @0x184694 blx r3
 *   @0x184698 ldr r10, [r7, #0x2c]
 *   @0x18469c ldr r3, [r5]
 *   @0x1846a0 ldr r2, [r10, r4, lsl #2]
 *   @0x1846a4 add r1, r3, #1
 *   @0x1846a8 add r3, r5, r3, lsl #2
 *   @0x1846ac str r1, [r5]
 *   @0x1846b0 str r2, [r3, #0x4]
 *   @0x1846b4 add r4, r4, #1
 *   @0x1846b8 cmp r4, r6
 *   @0x1846bc bne 0x18467c <_Z16StartShaderBlocki+0x410>
 *   @0x1846c0 b 0x18444c <_Z16StartShaderBlocki+0x1e0>
 *   @0x1846c4 ldr r3, [pc, #0x10c]
 *   @0x1846c8 mov r10, #0
 *   @0x1846cc mov r11, r10
 *   @0x1846d0 add r3, pc, r3
 *   @0x1846d4 ldr r0, [r3, r2, lsl #2]
 *   @0x1846d8 bl 0x187e70 <_Z10Shader_Geti>
 *   @0x1846dc mov r7, r0
 *   @0x1846e0 cmp r7, #0
 *   @0x1846e4 beq 0x184554 <_Z16StartShaderBlocki+0x2e8>
 *   @0x1846e8 ldr r3, [pc, #0xec]
 *   @0x1846ec ldr r0, [r7, #0x8]
 *   @0x1846f0 ldr r3, [r9, r3]
 *   @0x1846f4 ldr r3, [r3]
 *   @0x1846f8 blx r3
 *   @0x1846fc mov r0, r7
 *   @0x184700 bl 0x184230 <_Z20SetTransformUniformsP10GLSLShader>
 *   @0x184704 b 0x184328 <_Z16StartShaderBlocki+0xbc>
 *   @0x184708 ldr r3, [pc, #0xd0]
 *   @0x18470c ldr r3, [r9, r3]
 *   @0x184710 ldrb r10, [r3]
 *   @0x184714 cmp r10, #0
 *   @0x184718 beq 0x184784 <_Z16StartShaderBlocki+0x518>
 *   @0x18471c ldr r1, [pc, #0xc0]
 *   @0x184720 mov r11, #1
 *   @0x184724 ldr r3, [pc, #0xbc]
 *   @0x184728 ldr r0, [pc, #0xbc]
 *   @0x18472c ldr r1, [r9, r1]
 *   @0x184730 add r3, pc, r3
 *   @0x184734 add r0, pc, r0
 *   @0x184738 ldr r1, [r1]
 *   @0x18473c add r12, r3, r1, lsl #2
 *   @0x184740 ldr r10, [r3, r1, lsl #2]
 *   @0x184744 ldr r3, [r12, #0x24]
 *   @0x184748 orr r2, r2, r3, lsl #2
 *   @0x18474c add r3, r0, r2, lsl #2
 *   @0x184750 ldr r0, [r3, #0x20]
 *   @0x184754 bl 0x187e70 <_Z10Shader_Geti>
 *   @0x184758 mov r7, r0
 *   @0x18475c b 0x1846e0 <_Z16StartShaderBlocki+0x474>
 *   @0x184760 ldr r3, [pc, #0x88]
 *   @0x184764 mov r10, #0
 *   @0x184768 mov r11, r10
 *   @0x18476c add r3, pc, r3
 *   @0x184770 add r2, r3, r2, lsl #2
 *   @0x184774 ldr r0, [r2, #0x60]
 *   @0x184778 bl 0x187e70 <_Z10Shader_Geti>
 *   @0x18477c mov r7, r0
 *   @0x184780 b 0x1846e0 <_Z16StartShaderBlocki+0x474>
 *   @0x184784 ldr r3, [pc, #0x68]
 *   @0x184788 mov r11, r10
 *   @0x18478c add r3, pc, r3
 *   @0x184790 add r2, r3, r2, lsl #2
 *   @0x184794 ldr r0, [r2, #0x10]
 *   @0x184798 bl 0x187e70 <_Z10Shader_Geti>
 *   @0x18479c mov r7, r0
 *   @0x1847a0 b 0x1846e0 <_Z16StartShaderBlocki+0x474>
 *   @0x1847a4 ldrsbteq lr, [r1], -r8
 *   @0x1847a8 eoreq sp, r6, r4, asr #19
 *   @0x1847ac .word 0xffffe940
 *   @0x1847b0 .word 0xffffe884
 *   @0x1847b4 .word 0xffffe89c
 *   @0x1847b8 eorseq lr, r1, r4, asr #23
 *   @0x1847bc .word 0xffffbb88
 *   @0x1847c0 ldrshteq lr, [r1], -r8
 *   @0x1847c4 eorseq lr, r1, r0, lsl #21
 *   @0x1847c8 mlaseq r1, r12, r9, lr
 *   @0x1847cc eorseq lr, r1, r12, asr r9
 *   @0x1847d0 eorseq lr, r1, r12, lsl r9
 *   @0x1847d4 ldrsbteq lr, [r1], -r8
 *   @0x1847d8 .word 0x0026e1d8
 *   @0x1847dc .word 0xffffbb80
 *   @0x1847e0 .word 0xffffe880
 *   @0x1847e4 .word 0xffffe86c
 *   @0x1847e8 andseq r9, sp, r12, lsr #9
 *   @0x1847ec eoreq lr, r6, r4, ror r1
 *   @0x1847f0 eoreq lr, r6, r12, lsr r1
 *   @0x1847f4 eoreq lr, r6, r12, lsl r1
 *
 * ══ §18/19 HandleEnter  0x1d5fe8  size 1384  346 条（0x1d5fe8..0x1d6550）
 * @func 0x1d5fe8 0x1d6550  size 1384  346 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d5ff8→0x536f20, 0x1d6004→0x536f70, 0x1d6040→0x542374, 0x1d6044→0x53ab70, 0x1d61a4→0x542374, 0x1d61a8→0x53ab70, 0x1d6320→0x542374, 0x1d6324→0x53ab70
 * 调用序列: CInstance::Collision_Point(float, float, bool)×2 / Perform_Event(CInstance*, CInstance*, int, int)×2 / HandleEnter()+0x1a4 / HandleEnter()+0x308 / HandleEnter()+0x424 / HandleEnter()+0x39c / HandleEnter()+0x544 / HandleEnter()+0x4c0
 * 字段偏移 top8: 0x8×14 / 0x4×8 / 0xc×8 / 0x18×7 / 0x1c×6 / 0x16c×6 / 0x2×4 / 0x3×4
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5fe8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d5fec sub sp, sp, #36
 *   @0x1d5ff0 ldr r4, [pc, #0x53c]
 *   @0x1d5ff4 movw r12, #0x1828
 *   @0x1d5ff8 ldr r3, [pc, #0x538]
 *   @0x1d5ffc add r4, pc, r4
 *   @0x1d6000 str r4, [sp, #0x18]
 *   @0x1d6004 ldr r1, [pc, #0x530]
 *   @0x1d6008 ldr r3, [r4, r3]
 *   @0x1d600c str r3, [sp, #0x1c]
 *   @0x1d6010 ldrd r6, r7, [r3]
 *   @0x1d6014 ldr r8, [sp, #0x1c]
 *   @0x1d6018 adds r2, r6, #1
 *   @0x1d601c adc r3, r7, #0
 *   @0x1d6020 strd r6, r7, [sp, #16]
 *   @0x1d6024 strd r2, r3, [r8]
 *   @0x1d6028 ldr r8, [r4, r1]
 *   @0x1d602c ldr r3, [r8, r12]
 *   @0x1d6030 cmp r3, #0
 *   @0x1d6034 ble 0x1d618c <_Z11HandleEnterv+0x1a4>
 *   @0x1d6038 ldr r9, [sp, #0x18]
 *   @0x1d603c mov r10, #0
 *   @0x1d6040 ldr r2, [pc, #0x4f8]
 *   @0x1d6044 ldr r3, [pc, #0x4f8]
 *   @0x1d6048 ldr r11, [pc, #0x4f8]
 *   @0x1d604c ldr r7, [r9, r2]
 *   @0x1d6050 ldr r5, [r9, r3]
 *   @0x1d6054 add r11, pc, r11
 *   @0x1d6058 mov r9, r5
 *   @0x1d605c mov r5, r7
 *   @0x1d6060 movw r0, #0x3054
 *   @0x1d6064 ldr r3, [r5]
 *   @0x1d6068 ldr r1, [r9, r0]
 *   @0x1d606c ldr r2, [r3, #0x4]
 *   @0x1d6070 ldr r1, [r1, r10, lsl #2]
 *   @0x1d6074 ldr r3, [r3]
 *   @0x1d6078 and r2, r1, r2
 *   @0x1d607c ldr r3, [r3, r2, lsl #3]
 *   @0x1d6080 cmp r3, #0
 *   @0x1d6084 bne 0x1d6098 <_Z11HandleEnterv+0xb0>
 *   @0x1d6088 b 0x1d617c <_Z11HandleEnterv+0x194>
 *   @0x1d608c ldr r3, [r3, #0x4]
 *   @0x1d6090 cmp r3, #0
 *   @0x1d6094 beq 0x1d617c <_Z11HandleEnterv+0x194>
 *   @0x1d6098 ldr r2, [r3, #0x8]
 *   @0x1d609c cmp r1, r2
 *   @0x1d60a0 bne 0x1d608c <_Z11HandleEnterv+0xa4>
 *   @0x1d60a4 ldr r3, [r3, #0xc]
 *   @0x1d60a8 cmp r3, #0
 *   @0x1d60ac beq 0x1d617c <_Z11HandleEnterv+0x194>
 *   @0x1d60b0 ldr r6, [r3, #0xc4]
 *   @0x1d60b4 cmp r6, #0
 *   @0x1d60b8 beq 0x1d617c <_Z11HandleEnterv+0x194>
 *   @0x1d60bc ldr r3, [r6, #0x8]
 *   @0x1d60c0 cmp r3, #0
 *   @0x1d60c4 beq 0x1d617c <_Z11HandleEnterv+0x194>
 *   @0x1d60c8 stm sp, {r8, r9, r10}
 *   @0x1d60cc mov r10, r5
 *   @0x1d60d0 b 0x1d60e0 <_Z11HandleEnterv+0xf8>
 *   @0x1d60d4 ldr r3, [r6, #0x8]
 *   @0x1d60d8 cmp r3, #0
 *   @0x1d60dc beq 0x1d6170 <_Z11HandleEnterv+0x188>
 *   @0x1d60e0 ldr r7, [r6, #0x8]
 *   @0x1d60e4 ldr r6, [r6]
 *   @0x1d60e8 ldrb r3, [r7, #0x68]
 *   @0x1d60ec cmp r3, #0
 *   @0x1d60f0 bne 0x1d6168 <_Z11HandleEnterv+0x180>
 *   @0x1d60f4 ldrb r3, [r7, #0x69]
 *   @0x1d60f8 cmp r3, #0
 *   @0x1d60fc bne 0x1d6168 <_Z11HandleEnterv+0x180>
 *   @0x1d6100 ldrd r4, r5, [r7, #112]
 *   @0x1d6104 mov r0, r7
 *   @0x1d6108 ldrd r8, r9, [sp, #16]
 *   @0x1d610c mov r3, #1
 *   @0x1d6110 cmp r4, r8
 *   @0x1d6114 sbcs r9, r5, r9
 *   @0x1d6118 bge 0x1d6168 <_Z11HandleEnterv+0x180>
 *   @0x1d611c vldr s15, [r11]
 *   @0x1d6120 vcvt.f32.s32 s15, s15
 *   @0x1d6124 ldrd r8, r9, [sp, #16]
 *   @0x1d6128 ldr r4, [r7, #0x16c]
 *   @0x1d612c strd r8, r9, [r7, #112]
 *   @0x1d6130 and r4, r4, #3
 *   @0x1d6134 vmov r1, s15
 *   @0x1d6138 vldr s15, [r11, #4]
 *   @0x1d613c vcvt.f32.s32 s15, s15
 *   @0x1d6140 str r12, [sp, #0xc]
 *   @0x1d6144 vmov r2, s15
 *   @0x1d6148 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb>
 *   @0x1d614c ldr r12, [sp, #0xc]
 *   @0x1d6150 cmp r0, #0
 *   @0x1d6154 moveq r0, #2
 *   @0x1d6158 movne r0, #1
 *   @0x1d615c eor r4, r0, r4
 *   @0x1d6160 orr r0, r0, r4, lsl #2
 *   @0x1d6164 str r0, [r7, #0x16c]
 *   @0x1d6168 cmp r6, #0
 *   @0x1d616c bne 0x1d60d4 <_Z11HandleEnterv+0xec>
 *   @0x1d6170 mov r3, r10
 *   @0x1d6174 ldm sp, {r8, r9, r10}
 *   @0x1d6178 mov r5, r3
 *   @0x1d617c ldr r3, [r8, r12]
 *   @0x1d6180 add r10, r10, #1
 *   @0x1d6184 cmp r3, r10
 *   @0x1d6188 bgt 0x1d6060 <_Z11HandleEnterv+0x78>
 *   @0x1d618c movw r12, #0x182c
 *   @0x1d6190 ldr r3, [r8, r12]
 *   @0x1d6194 cmp r3, #0
 *   @0x1d6198 ble 0x1d62f0 <_Z11HandleEnterv+0x308>
 *   @0x1d619c ldr r9, [sp, #0x18]
 *   @0x1d61a0 mov r10, #0
 *   @0x1d61a4 ldr r2, [pc, #0x394]
 *   @0x1d61a8 ldr r3, [pc, #0x394]
 *   @0x1d61ac ldr r11, [pc, #0x398]
 *   @0x1d61b0 ldr r7, [r9, r2]
 *   @0x1d61b4 ldr r5, [r9, r3]
 *   @0x1d61b8 add r11, pc, r11
 *   @0x1d61bc mov r9, r5
 *   @0x1d61c0 mov r5, r7
 *   @0x1d61c4 movw r0, #0x305c
 *   @0x1d61c8 ldr r3, [r5]
 *   @0x1d61cc ldr r1, [r9, r0]
 *   @0x1d61d0 ldr r2, [r3, #0x4]
 *   @0x1d61d4 ldr r1, [r1, r10, lsl #2]
 *   @0x1d61d8 ldr r3, [r3]
 *   @0x1d61dc and r2, r1, r2
 *   @0x1d61e0 ldr r3, [r3, r2, lsl #3]
 *   @0x1d61e4 cmp r3, #0
 *   @0x1d61e8 bne 0x1d61fc <_Z11HandleEnterv+0x214>
 *   @0x1d61ec b 0x1d62e0 <_Z11HandleEnterv+0x2f8>
 *   @0x1d61f0 ldr r3, [r3, #0x4]
 *   @0x1d61f4 cmp r3, #0
 *   @0x1d61f8 beq 0x1d62e0 <_Z11HandleEnterv+0x2f8>
 *   @0x1d61fc ldr r2, [r3, #0x8]
 *   @0x1d6200 cmp r1, r2
 *   @0x1d6204 bne 0x1d61f0 <_Z11HandleEnterv+0x208>
 *   @0x1d6208 ldr r3, [r3, #0xc]
 *   @0x1d620c cmp r3, #0
 *   @0x1d6210 beq 0x1d62e0 <_Z11HandleEnterv+0x2f8>
 *   @0x1d6214 ldr r6, [r3, #0xc4]
 *   @0x1d6218 cmp r6, #0
 *   @0x1d621c beq 0x1d62e0 <_Z11HandleEnterv+0x2f8>
 *   @0x1d6220 ldr r3, [r6, #0x8]
 *   @0x1d6224 cmp r3, #0
 *   @0x1d6228 beq 0x1d62e0 <_Z11HandleEnterv+0x2f8>
 *   @0x1d622c stm sp, {r8, r9, r10}
 *   @0x1d6230 mov r10, r5
 *   @0x1d6234 b 0x1d6244 <_Z11HandleEnterv+0x25c>
 *   @0x1d6238 ldr r3, [r6, #0x8]
 *   @0x1d623c cmp r3, #0
 *   @0x1d6240 beq 0x1d62d4 <_Z11HandleEnterv+0x2ec>
 *   @0x1d6244 ldr r7, [r6, #0x8]
 *   @0x1d6248 ldr r6, [r6]
 *   @0x1d624c ldrb r3, [r7, #0x68]
 *   @0x1d6250 cmp r3, #0
 *   @0x1d6254 bne 0x1d62cc <_Z11HandleEnterv+0x2e4>
 *   @0x1d6258 ldrb r3, [r7, #0x69]
 *   @0x1d625c cmp r3, #0
 *   @0x1d6260 bne 0x1d62cc <_Z11HandleEnterv+0x2e4>
 *   @0x1d6264 ldrd r4, r5, [r7, #112]
 *   @0x1d6268 mov r0, r7
 *   @0x1d626c ldrd r8, r9, [sp, #16]
 *   @0x1d6270 mov r3, #1
 *   @0x1d6274 cmp r4, r8
 *   @0x1d6278 sbcs r9, r5, r9
 *   @0x1d627c bge 0x1d62cc <_Z11HandleEnterv+0x2e4>
 *   @0x1d6280 vldr s15, [r11]
 *   @0x1d6284 vcvt.f32.s32 s15, s15
 *   @0x1d6288 ldrd r8, r9, [sp, #16]
 *   @0x1d628c ldr r4, [r7, #0x16c]
 *   @0x1d6290 strd r8, r9, [r7, #112]
 *   @0x1d6294 and r4, r4, #3
 *   @0x1d6298 vmov r1, s15
 *   @0x1d629c vldr s15, [r11, #4]
 *   @0x1d62a0 vcvt.f32.s32 s15, s15
 *   @0x1d62a4 str r12, [sp, #0xc]
 *   @0x1d62a8 vmov r2, s15
 *   @0x1d62ac bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb>
 *   @0x1d62b0 ldr r12, [sp, #0xc]
 *   @0x1d62b4 cmp r0, #0
 *   @0x1d62b8 moveq r0, #2
 *   @0x1d62bc movne r0, #1
 *   @0x1d62c0 eor r4, r0, r4
 *   @0x1d62c4 orr r0, r0, r4, lsl #2
 *   @0x1d62c8 str r0, [r7, #0x16c]
 *   @0x1d62cc cmp r6, #0
 *   @0x1d62d0 bne 0x1d6238 <_Z11HandleEnterv+0x250>
 *   @0x1d62d4 mov r3, r10
 *   @0x1d62d8 ldm sp, {r8, r9, r10}
 *   @0x1d62dc mov r5, r3
 *   @0x1d62e0 ldr r3, [r8, r12]
 *   @0x1d62e4 add r10, r10, #1
 *   @0x1d62e8 cmp r3, r10
 *   @0x1d62ec bgt 0x1d61c4 <_Z11HandleEnterv+0x1dc>
 *   @0x1d62f0 ldr r4, [sp, #0x1c]
 *   @0x1d62f4 movw r6, #0x1828
 *   @0x1d62f8 ldr r3, [r8, r6]
 *   @0x1d62fc ldr r7, [sp, #0x1c]
 *   @0x1d6300 ldrd r10, r11, [r4]
 *   @0x1d6304 adds r4, r10, #1
 *   @0x1d6308 adc r5, r11, #0
 *   @0x1d630c cmp r3, #0
 *   @0x1d6310 strd r4, r5, [r7]
 *   @0x1d6314 ble 0x1d640c <_Z11HandleEnterv+0x424>
 *   @0x1d6318 ldr r4, [sp, #0x18]
 *   @0x1d631c mov r9, #0
 *   @0x1d6320 ldr r2, [pc, #0x218]
 *   @0x1d6324 ldr r3, [pc, #0x218]
 *   @0x1d6328 ldr r7, [r4, r2]
 *   @0x1d632c ldr r5, [r4, r3]
 *   @0x1d6330 movw r0, #0x3054
 *   @0x1d6334 ldr r3, [r7]
 *   @0x1d6338 ldr r1, [r5, r0]
 *   @0x1d633c ldr r2, [r3, #0x4]
 *   @0x1d6340 ldr r1, [r1, r9, lsl #2]
 *   @0x1d6344 ldr r3, [r3]
 *   @0x1d6348 and r2, r1, r2
 *   @0x1d634c ldr r3, [r3, r2, lsl #3]
 *   @0x1d6350 cmp r3, #0
 *   @0x1d6354 bne 0x1d6368 <_Z11HandleEnterv+0x380>
 *   @0x1d6358 b 0x1d63f4 <_Z11HandleEnterv+0x40c>
 *   @0x1d635c ldr r3, [r3, #0x4]
 *   @0x1d6360 cmp r3, #0
 *   @0x1d6364 beq 0x1d63f4 <_Z11HandleEnterv+0x40c>
 *   @0x1d6368 ldr r2, [r3, #0x8]
 *   @0x1d636c cmp r1, r2
 *   @0x1d6370 bne 0x1d635c <_Z11HandleEnterv+0x374>
 *   @0x1d6374 ldr r3, [r3, #0xc]
 *   @0x1d6378 cmp r3, #0
 *   @0x1d637c ldrne r4, [r3, #0xc4]
 *   @0x1d6380 beq 0x1d63f4 <_Z11HandleEnterv+0x40c>
 *   @0x1d6384 cmp r4, #0
 *   @0x1d6388 beq 0x1d63f4 <_Z11HandleEnterv+0x40c>
 *   @0x1d638c ldr r3, [r4, #0x8]
 *   @0x1d6390 cmp r3, #0
 *   @0x1d6394 beq 0x1d63f4 <_Z11HandleEnterv+0x40c>
 *   @0x1d6398 ldr r0, [r4, #0x8]
 *   @0x1d639c ldr r4, [r4]
 *   @0x1d63a0 ldrb r3, [r0, #0x68]
 *   @0x1d63a4 cmp r3, #0
 *   @0x1d63a8 bne 0x1d6384 <_Z11HandleEnterv+0x39c>
 *   @0x1d63ac ldrb r3, [r0, #0x69]
 *   @0x1d63b0 cmp r3, #0
 *   @0x1d63b4 bne 0x1d6384 <_Z11HandleEnterv+0x39c>
 *   @0x1d63b8 ldrd r2, r3, [r0, #112]
 *   @0x1d63bc cmp r10, r2
 *   @0x1d63c0 sbcs r1, r11, r3
 *   @0x1d63c4 blt 0x1d6384 <_Z11HandleEnterv+0x39c>
 *   @0x1d63c8 ldr r3, [r0, #0x16c]
 *   @0x1d63cc tst r3, #4
 *   @0x1d63d0 beq 0x1d6384 <_Z11HandleEnterv+0x39c>
 *   @0x1d63d4 tst r3, #1
 *   @0x1d63d8 beq 0x1d6384 <_Z11HandleEnterv+0x39c>
 *   @0x1d63dc mov r2, #6
 *   @0x1d63e0 mov r3, #10
 *   @0x1d63e4 mov r1, r0
 *   @0x1d63e8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1d63ec cmp r4, #0
 *   @0x1d63f0 bne 0x1d638c <_Z11HandleEnterv+0x3a4>
 *   @0x1d63f4 ldr r3, [r8, r6]
 *   @0x1d63f8 add r9, r9, #1
 *   @0x1d63fc cmp r3, r9
 *   @0x1d6400 bgt 0x1d6330 <_Z11HandleEnterv+0x348>
 *   @0x1d6404 ldr r5, [sp, #0x1c]
 *   @0x1d6408 ldrd r4, r5, [r5]
 *   @0x1d640c strd r4, r5, [sp, #16]
 *   @0x1d6410 movw r10, #0x182c
 *   @0x1d6414 ldrd r2, r3, [sp, #16]
 *   @0x1d6418 ldr r1, [r8, r10]
 *   @0x1d641c adds r2, r2, #1
 *   @0x1d6420 ldr r6, [sp, #0x1c]
 *   @0x1d6424 adc r3, r3, #0
 *   @0x1d6428 cmp r1, #0
 *   @0x1d642c strd r2, r3, [r6]
 *   @0x1d6430 ble 0x1d652c <_Z11HandleEnterv+0x544>
 *   @0x1d6434 ldr r4, [sp, #0x18]
 *   @0x1d6438 mov r9, #0
 *   @0x1d643c ldr r2, [pc, #0xfc]
 *   @0x1d6440 movw r11, #0x305c
 *   @0x1d6444 ldr r3, [pc, #0xf8]
 *   @0x1d6448 ldr r7, [r4, r2]
 *   @0x1d644c ldr r5, [r4, r3]
 *   @0x1d6450 str r7, [sp, #0x18]
 *   @0x1d6454 ldr r6, [sp, #0x18]
 *   @0x1d6458 ldr r1, [r5, r11]
 *   @0x1d645c ldr r3, [r6]
 *   @0x1d6460 ldr r1, [r1, r9, lsl #2]
 *   @0x1d6464 ldr r2, [r3, #0x4]
 *   @0x1d6468 ldr r3, [r3]
 *   @0x1d646c and r2, r1, r2
 *   @0x1d6470 ldr r3, [r3, r2, lsl #3]
 *   @0x1d6474 cmp r3, #0
 *   @0x1d6478 bne 0x1d648c <_Z11HandleEnterv+0x4a4>
 *   @0x1d647c b 0x1d651c <_Z11HandleEnterv+0x534>
 *   @0x1d6480 ldr r3, [r3, #0x4]
 *   @0x1d6484 cmp r3, #0
 *   @0x1d6488 beq 0x1d651c <_Z11HandleEnterv+0x534>
 *   @0x1d648c ldr r2, [r3, #0x8]
 *   @0x1d6490 cmp r1, r2
 *   @0x1d6494 bne 0x1d6480 <_Z11HandleEnterv+0x498>
 *   @0x1d6498 ldr r3, [r3, #0xc]
 *   @0x1d649c cmp r3, #0
 *   @0x1d64a0 ldrne r4, [r3, #0xc4]
 *   @0x1d64a4 beq 0x1d651c <_Z11HandleEnterv+0x534>
 *   @0x1d64a8 cmp r4, #0
 *   @0x1d64ac beq 0x1d651c <_Z11HandleEnterv+0x534>
 *   @0x1d64b0 ldr r3, [r4, #0x8]
 *   @0x1d64b4 cmp r3, #0
 *   @0x1d64b8 beq 0x1d651c <_Z11HandleEnterv+0x534>
 *   @0x1d64bc ldr r0, [r4, #0x8]
 *   @0x1d64c0 ldr r4, [r4]
 *   @0x1d64c4 ldrb r3, [r0, #0x68]
 *   @0x1d64c8 cmp r3, #0
 *   @0x1d64cc bne 0x1d64a8 <_Z11HandleEnterv+0x4c0>
 *   @0x1d64d0 ldrb r3, [r0, #0x69]
 *   @0x1d64d4 cmp r3, #0
 *   @0x1d64d8 bne 0x1d64a8 <_Z11HandleEnterv+0x4c0>
 *   @0x1d64dc ldrd r6, r7, [sp, #16]
 *   @0x1d64e0 ldrd r2, r3, [r0, #112]
 *   @0x1d64e4 cmp r6, r2
 *   @0x1d64e8 sbcs r3, r7, r3
 *   @0x1d64ec blt 0x1d64a8 <_Z11HandleEnterv+0x4c0>
 *   @0x1d64f0 ldr r3, [r0, #0x16c]
 *   @0x1d64f4 tst r3, #8
 *   @0x1d64f8 beq 0x1d64a8 <_Z11HandleEnterv+0x4c0>
 *   @0x1d64fc tst r3, #2
 *   @0x1d6500 beq 0x1d64a8 <_Z11HandleEnterv+0x4c0>
 *   @0x1d6504 mov r2, #6
 *   @0x1d6508 mov r3, #11
 *   @0x1d650c mov r1, r0
 *   @0x1d6510 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1d6514 cmp r4, #0
 *   @0x1d6518 bne 0x1d64b0 <_Z11HandleEnterv+0x4c8>
 *   @0x1d651c ldr r3, [r8, r10]
 *   @0x1d6520 add r9, r9, #1
 *   @0x1d6524 cmp r3, r9
 *   @0x1d6528 bgt 0x1d6454 <_Z11HandleEnterv+0x46c>
 *   @0x1d652c add sp, sp, #36
 *   @0x1d6530 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d6534 eoreq r11, r1, r4, asr r12
 *   @0x1d6538 .word 0xffffdeb4
 *   @0x1d653c .word 0xffffdeb8
 *   @0x1d6540 .word 0xffffbfec
 *   @0x1d6544 .word 0xffffdebc
 *   @0x1d6548 eorseq lr, r6, r12, lsl r10
 *   @0x1d654c ldrhteq lr, [r6], -r8
 *
 * ══ §19/19 GR_Texture_Draw_Tiled  0x175e90  size 1052  261 条（0x175e90..0x1762ac）
 * @func 0x175e90 0x1762ac  size 1052  261 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8×3 / __aeabi_idivmod×2 / Graphics::AllocVerts(ePrimType, void*, int, int)×2 / GR_Texture_Exists(int) / GR_Texture_Draw_Tiled(int, float, float, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)+0x2b0 / GR_Texture_Draw_Tiled(int, float, float, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)+0x2c0
 * 字段偏移 top8: 0xc×5 / 0x10×2 / 0x14×2 / 0x4×2 / 0x2×2 / 0x8×2 / 0x20×2 / 0x24×2
 * VFP 指令 136 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x175e90 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x175e94 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x175e98 sub sp, sp, #28
 *   @0x175e9c vldr s17, [sp, #116]
 *   @0x175ea0 vmov s21, r2
 *   @0x175ea4 mov r5, r0
 *   @0x175ea8 ldrb r2, [sp, #0x7c]
 *   @0x175eac vmov s18, r3
 *   @0x175eb0 ldrb r3, [sp, #0x80]
 *   @0x175eb4 vmov s25, r1
 *   @0x175eb8 vldr s16, [sp, #120]
 *   @0x175ebc vldr s27, [sp, #132]
 *   @0x175ec0 str r2, [sp, #0xc]
 *   @0x175ec4 vldr s24, [sp, #136]
 *   @0x175ec8 str r3, [sp, #0x10]
 *   @0x175ecc ldr r4, [sp, #0x94]
 *   @0x175ed0 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x175ed4 ldr r8, [pc, #0x3c4]
 *   @0x175ed8 add r8, pc, r8
 *   @0x175edc cmp r0, #0
 *   @0x175ee0 str r0, [sp, #0x14]
 *   @0x175ee4 beq 0x176140 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2b0>
 *   @0x175ee8 ldr r3, [pc, #0x3b4]
 *   @0x175eec ldr r7, [r8, r3]
 *   @0x175ef0 ldr r3, [r7, #0x4]
 *   @0x175ef4 ldr r3, [r3, r5, lsl #2]
 *   @0x175ef8 ldrsh r2, [r3, #4]
 *   @0x175efc ldrsh r3, [r3, #6]
 *   @0x175f00 vmov s14, r2
 *   @0x175f04 vmov s15, r3
 *   @0x175f08 vcvt.f32.s32 s14, s14
 *   @0x175f0c vcvt.f32.s32 s15, s15
 *   @0x175f10 vmul.f32 s14, s14, s17
 *   @0x175f14 vmul.f32 s15, s15, s16
 *   @0x175f18 vcvt.s32.f32 s14, s14
 *   @0x175f1c vcvt.s32.f32 s15, s15
 *   @0x175f20 vmov r9, s14
 *   @0x175f24 vmov r6, s15
 *   @0x175f28 cmp r6, #0
 *   @0x175f2c cmpgt r9, #0
 *   @0x175f30 movle r2, #0
 *   @0x175f34 strle r2, [sp, #0x14]
 *   @0x175f38 ble 0x176140 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2b0>
 *   @0x175f3c vldr s15, [pc, #852]
 *   @0x175f40 vldr s12, [sp, #152]
 *   @0x175f44 vmul.f32 s14, s12, s15
 *   @0x175f48 vcmpe.f32 s14, #0
 *   @0x175f4c vmrs APSR_nzcv, fpscr
 *   @0x175f50 bmi 0x17627c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x3ec>
 *   @0x175f54 vcmpe.f32 s14, s15
 *   @0x175f58 vmrs APSR_nzcv, fpscr
 *   @0x175f5c ble 0x176150 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2c0>
 *   @0x175f60 vldr d7, [pc, #800]
 *   @0x175f64 vmov r0, r1, d7
 *   @0x175f68 bl 0xb66e8 <lrint@plt>
 *   @0x175f6c ldr r12, [r7, #0x4]
 *   @0x175f70 vnmul.f32 s25, s17, s25
 *   @0x175f74 uxtb r1, r4
 *   @0x175f78 ubfx r2, r4, #0x10, #0x8
 *   @0x175f7c and r3, r4, #65280
 *   @0x175f80 ldr r4, [r12, r5, lsl #2]
 *   @0x175f84 orr r5, r2, r1, lsl #16
 *   @0x175f88 orr r5, r5, r3
 *   @0x175f8c ldrsh r2, [r4, #4]
 *   @0x175f90 ldrsh r3, [r4, #6]
 *   @0x175f94 vmov s14, r2
 *   @0x175f98 vmov s15, r3
 *   @0x175f9c vnmul.f32 s21, s16, s21
 *   @0x175fa0 vcvt.f64.f32 d6, s18
 *   @0x175fa4 vcvt.f32.s32 s14, s14
 *   @0x175fa8 orr r5, r5, r0, lsl #24
 *   @0x175fac vmov r0, r1, d6
 *   @0x175fb0 vcvt.f32.s32 s15, s15
 *   @0x175fb4 vmov.f32 s26, s25
 *   @0x175fb8 vmov.f32 s22, s21
 *   @0x175fbc vmla.f32 s26, s14, s17
 *   @0x175fc0 vmla.f32 s22, s15, s16
 *   @0x175fc4 bl 0xb66e8 <lrint@plt>
 *   @0x175fc8 ldr r2, [sp, #0xc]
 *   @0x175fcc cmp r2, #0
 *   @0x175fd0 mov r7, r0
 *   @0x175fd4 beq 0x176008 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x178>
 *   @0x175fd8 mov r1, r9
 *   @0x175fdc bl 0x318dec <__aeabi_idivmod>
 *   @0x175fe0 subs r7, r1, #0
 *   @0x175fe4 rsbgt r7, r9, r7
 *   @0x175fe8 b 0x175ff0 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x160>
 *   @0x175fec mov r7, r3
 *   @0x175ff0 add r3, r7, r9
 *   @0x175ff4 vmov s14, r3
 *   @0x175ff8 vcvt.f32.s32 s15, s14
 *   @0x175ffc vcmpe.f32 s15, s27
 *   @0x176000 vmrs APSR_nzcv, fpscr
 *   @0x176004 bmi 0x175fec <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x15c>
 *   @0x176008 vldr s12, [sp, #140]
 *   @0x17600c vadd.f32 s27, s27, s12
 *   @0x176010 vmov s13, r7
 *   @0x176014 vcvt.f32.s32 s19, s13
 *   @0x176018 vcmpe.f32 s19, s27
 *   @0x17601c vmrs APSR_nzcv, fpscr
 *   @0x176020 bpl 0x176140 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2b0>
 *   @0x176024 vldr s15, [sp, #144]
 *   @0x176028 vadd.f32 s23, s24, s15
 *   @0x17602c vldr s13, [sp, #112]
 *   @0x176030 vldr s17, [pc, #612]
 *   @0x176034 vcvt.f64.f32 d6, s13
 *   @0x176038 vstr d6, [sp]
 *   @0x17603c ldrd r0, r1, [sp]
 *   @0x176040 bl 0xb66e8 <lrint@plt>
 *   @0x176044 ldr r2, [sp, #0x10]
 *   @0x176048 cmp r2, #0
 *   @0x17604c bne 0x176164 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2d4>
 *   @0x176050 vmov s12, r0
 *   @0x176054 vcvt.f32.s32 s16, s12
 *   @0x176058 vcmpe.f32 s16, s23
 *   @0x17605c vmrs APSR_nzcv, fpscr
 *   @0x176060 bpl 0x17611c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x28c>
 *   @0x176064 mov r2, #24
 *   @0x176068 mov r3, #4
 *   @0x17606c mov r0, #6
 *   @0x176070 ldr r1, [r4]
 *   @0x176074 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x176078 ldr r3, [pc, #0x228]
 *   @0x17607c vadd.f32 s14, s25, s19
 *   @0x176080 ldr r11, [r8, r3]
 *   @0x176084 ldr r3, [r11]
 *   @0x176088 vadd.f32 s19, s26, s19
 *   @0x17608c vstr s17, [r0, #16]
 *   @0x176090 vstr s17, [r0, #20]
 *   @0x176094 ldrsh r2, [r4, #4]
 *   @0x176098 vldr s15, [r4, #8]
 *   @0x17609c vstr s17, [r0, #44]
 *   @0x1760a0 str r5, [r0, #0xc]
 *   @0x1760a4 str r3, [r0, #0x8]
 *   @0x1760a8 vmov s13, r2
 *   @0x1760ac str r3, [r0, #0x20]
 *   @0x1760b0 str r5, [r0, #0x24]
 *   @0x1760b4 vcvt.f32.s32 s13, s13
 *   @0x1760b8 str r3, [r0, #0x38]
 *   @0x1760bc str r5, [r0, #0x3c]
 *   @0x1760c0 vmul.f32 s13, s13, s15
 *   @0x1760c4 vstr s13, [r0, #40]
 *   @0x1760c8 vstr s13, [r0, #64]
 *   @0x1760cc ldrsh r2, [r4, #6]
 *   @0x1760d0 vldr s15, [r4, #12]
 *   @0x1760d4 vstr s14, [r0]
 *   @0x1760d8 vstr s14, [r0, #72]
 *   @0x1760dc vadd.f32 s14, s21, s16
 *   @0x1760e0 str r3, [r0, #0x50]
 *   @0x1760e4 vmov s13, r2
 *   @0x1760e8 str r5, [r0, #0x54]
 *   @0x1760ec vstr s17, [r0, #88]
 *   @0x1760f0 vstr s19, [r0, #24]
 *   @0x1760f4 vstr s19, [r0, #48]
 *   @0x1760f8 vcvt.f32.s32 s13, s13
 *   @0x1760fc vstr s14, [r0, #4]
 *   @0x176100 vstr s14, [r0, #28]
 *   @0x176104 vmul.f32 s13, s13, s15
 *   @0x176108 vadd.f32 s15, s22, s16
 *   @0x17610c vstr s13, [r0, #68]
 *   @0x176110 vstr s13, [r0, #92]
 *   @0x176114 vstr s15, [r0, #52]
 *   @0x176118 vstr s15, [r0, #76]
 *   @0x17611c ldr r3, [sp, #0xc]
 *   @0x176120 cmp r3, #0
 *   @0x176124 beq 0x176140 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2b0>
 *   @0x176128 add r7, r7, r9
 *   @0x17612c vmov s13, r7
 *   @0x176130 vcvt.f32.s32 s19, s13
 *   @0x176134 vcmpe.f32 s19, s27
 *   @0x176138 vmrs APSR_nzcv, fpscr
 *   @0x17613c bmi 0x17603c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x1ac>
 *   @0x176140 ldr r0, [sp, #0x14]
 *   @0x176144 add sp, sp, #28
 *   @0x176148 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x17614c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x176150 vcmpe.f32 s14, #0
 *   @0x176154 vmrs APSR_nzcv, fpscr
 *   @0x176158 bmi 0x17627c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x3ec>
 *   @0x17615c vcvt.f64.f32 d7, s14
 *   @0x176160 b 0x175f64 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0xd4>
 *   @0x176164 mov r1, r6
 *   @0x176168 bl 0x318dec <__aeabi_idivmod>
 *   @0x17616c cmp r1, #0
 *   @0x176170 rsbgt r1, r6, r1
 *   @0x176174 b 0x17617c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2ec>
 *   @0x176178 mov r1, r10
 *   @0x17617c add r10, r1, r6
 *   @0x176180 vmov s12, r10
 *   @0x176184 vcvt.f32.s32 s15, s12
 *   @0x176188 vcmpe.f32 s15, s24
 *   @0x17618c vmrs APSR_nzcv, fpscr
 *   @0x176190 bmi 0x176178 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x2e8>
 *   @0x176194 vmov s13, r1
 *   @0x176198 vcvt.f32.s32 s18, s13
 *   @0x17619c vcmpe.f32 s18, s23
 *   @0x1761a0 vmrs APSR_nzcv, fpscr
 *   @0x1761a4 bpl 0x17611c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x28c>
 *   @0x1761a8 vadd.f32 s20, s25, s19
 *   @0x1761ac ldr r3, [pc, #0xf4]
 *   @0x1761b0 ldr r11, [r8, r3]
 *   @0x1761b4 vadd.f32 s19, s26, s19
 *   @0x1761b8 mov r2, #24
 *   @0x1761bc mov r3, #4
 *   @0x1761c0 mov r0, #6
 *   @0x1761c4 ldr r1, [r4]
 *   @0x1761c8 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1761cc vmov s12, r10
 *   @0x1761d0 add r10, r10, r6
 *   @0x1761d4 vadd.f32 s14, s21, s18
 *   @0x1761d8 vadd.f32 s18, s22, s18
 *   @0x1761dc vstr s17, [r0, #16]
 *   @0x1761e0 vstr s17, [r0, #20]
 *   @0x1761e4 ldrsh r3, [r4, #4]
 *   @0x1761e8 vldr s13, [r4, #8]
 *   @0x1761ec vstr s17, [r0, #44]
 *   @0x1761f0 str r5, [r0, #0xc]
 *   @0x1761f4 str r5, [r0, #0x24]
 *   @0x1761f8 vmov s15, r3
 *   @0x1761fc ldr r3, [r11]
 *   @0x176200 str r5, [r0, #0x3c]
 *   @0x176204 vcvt.f32.s32 s15, s15
 *   @0x176208 str r3, [r0, #0x8]
 *   @0x17620c str r3, [r0, #0x20]
 *   @0x176210 str r3, [r0, #0x38]
 *   @0x176214 vmul.f32 s15, s15, s13
 *   @0x176218 vstr s15, [r0, #40]
 *   @0x17621c vstr s15, [r0, #64]
 *   @0x176220 ldrsh r2, [r4, #6]
 *   @0x176224 vldr s13, [r4, #12]
 *   @0x176228 vstr s18, [r0, #52]
 *   @0x17622c vstr s18, [r0, #76]
 *   @0x176230 vcvt.f32.s32 s18, s12
 *   @0x176234 str r5, [r0, #0x54]
 *   @0x176238 vmov s15, r2
 *   @0x17623c vstr s17, [r0, #88]
 *   @0x176240 vstr s19, [r0, #24]
 *   @0x176244 vstr s19, [r0, #48]
 *   @0x176248 vstr s20, [r0, #72]
 *   @0x17624c vstr s14, [r0, #4]
 *   @0x176250 vstr s14, [r0, #28]
 *   @0x176254 str r3, [r0, #0x50]
 *   @0x176258 vstr s20, [r0]
 *   @0x17625c vcvt.f32.s32 s15, s15
 *   @0x176260 vmul.f32 s15, s15, s13
 *   @0x176264 vcmpe.f32 s18, s23
 *   @0x176268 vstr s15, [r0, #68]
 *   @0x17626c vstr s15, [r0, #92]
 *   @0x176270 vmrs APSR_nzcv, fpscr
 *   @0x176274 bmi 0x1761b8 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x328>
 *   @0x176278 b 0x17611c <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0x28c>
 *   @0x17627c vldr d7, [pc, #12]
 *   @0x176280 b 0x175f64 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf+0xd4>
 *   @0x176284 nop
 *   @0x176288 andeq r0, r0, r0
 *   @0x17628c rsbmi lr, pc, r0
 *   @0x176298 cmnmi pc, #0
 *   @0x17629c andeq r0, r0, r0
 *   @0x1762a0 eoreq r11, r7, r8, ror sp
 *   @0x1762a4 .word 0xffffbccc
 *   @0x1762a8 .word 0xffffbcd0
 */
